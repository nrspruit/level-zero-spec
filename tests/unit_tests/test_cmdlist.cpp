#include "mock_cmdlist.h"
#include "mock_device.h"
#include "mock_memory_manager.h"
#include "event.h"
#include "graphics_allocation.h"
#include "igfxfmid.h"
#include "runtime/command_stream/linear_stream.h"
#include "runtime/indirect_heap/indirect_heap.h"
#include "test.h"
#include "unit_tests/gen_common/gen_cmd_parse.h"

namespace L0 {
namespace ult {

TEST(xeCommandListDestroy, redirectsToObject) {
    Mock<CommandList> cmdList;
    EXPECT_CALL(cmdList, destroy()).Times(1);

    auto result = xeCommandListDestroy(cmdList.toHandle());
    EXPECT_EQ(XE_RESULT_SUCCESS, result);
}

using ::testing::_;
using ::testing::AnyNumber;
using ::testing::Return;
using CommandListCreate = ::testing::TestWithParam<uint32_t>;

TEST_P(CommandListCreate, returnsCommandListOnSuccess) {
    Mock<Device> device;
    EXPECT_CALL(device, getMemoryManager).Times(AnyNumber());

    auto commandList = whitebox_cast(CommandList::create(GetParam(), &device));
    ASSERT_NE(nullptr, commandList);

    EXPECT_EQ(&device, commandList->device);
    ASSERT_NE(commandList->allocation, nullptr);
    auto numAllocations = 0u;

    auto allocation = whitebox_cast(commandList->allocation);
    ++numAllocations;

    ASSERT_NE(nullptr, commandList->commandStream);
    for (auto indirectHeap : commandList->indirectHeaps) {
        ASSERT_NE(indirectHeap, nullptr);
    }

    for (auto allocationIndirectHeap : commandList->allocationIndirectHeaps) {
        ++numAllocations;
        ASSERT_NE(allocationIndirectHeap, nullptr);
    }

    EXPECT_LT(0u, commandList->commandStream->getAvailableSpace());
    ASSERT_EQ(commandList->residencyContainer.size(), numAllocations);
    EXPECT_EQ(commandList->residencyContainer.front(), allocation->allocationRT);
    commandList->destroy();
}

static uint32_t supportedProductFamilyTable[] = {
    IGFX_BROADWELL,
    IGFX_KABYLAKE,
    IGFX_SKYLAKE,
};

INSTANTIATE_TEST_CASE_P(,
                        CommandListCreate,
                        ::testing::ValuesIn(supportedProductFamilyTable));

using CommandListCreateFail = ::testing::TestWithParam<uint32_t>;

TEST_P(CommandListCreateFail, returnsNullPointerOnFailure) {
    Mock<Device> device;
    auto commandList = CommandList::create(GetParam(), &device);
    EXPECT_EQ(nullptr, commandList);
}

static uint32_t unsupportedProductFamilyTable[] = {
    IGFX_HASWELL,
    IGFX_CANNONLAKE,
    IGFX_MAX_PRODUCT,
};

INSTANTIATE_TEST_CASE_P(,
                        CommandListCreateFail,
                        ::testing::ValuesIn(unsupportedProductFamilyTable));

GEN9TEST_F(CommandListCreate, addsPipelineSelectBeforeVfeStateToBatchBuffer) {
    Mock<Device> device;
    EXPECT_CALL(device, getMemoryManager).Times(AnyNumber());

    auto commandList = whitebox_cast(CommandList::create(productFamily, &device));
    ASSERT_NE(nullptr, commandList->commandStream);
    auto usedSpaceBefore = commandList->commandStream->getUsed();

    auto result = commandList->close();
    ASSERT_EQ(XE_RESULT_SUCCESS, result);

    auto usedSpaceAfter = commandList->commandStream->getUsed();
    ASSERT_GT(usedSpaceAfter, usedSpaceBefore);

    GenCmdList cmdList;
    ASSERT_TRUE(FamilyType::PARSE::parseCommandBuffer(cmdList,
                                                      ptrOffset(commandList->commandStream->getCpuBase(), 0),
                                                      usedSpaceAfter));
    using MEDIA_VFE_STATE = typename FamilyType::MEDIA_VFE_STATE;
    auto itorVFE = find<MEDIA_VFE_STATE *>(cmdList.begin(), cmdList.end());
    ASSERT_NE(itorVFE, cmdList.end());

    // Should have a PS before a VFE
    using PIPELINE_SELECT = typename FamilyType::PIPELINE_SELECT;
    auto itorPS = find<PIPELINE_SELECT *>(cmdList.begin(), itorVFE);
    ASSERT_NE(itorPS, itorVFE);

    {
        auto cmd = genCmdCast<PIPELINE_SELECT *>(*itorPS);
        EXPECT_EQ(cmd->getMaskBits() & 3u, 3u);
        EXPECT_EQ(cmd->getPipelineSelection(), PIPELINE_SELECT::PIPELINE_SELECTION_GPGPU);
    }
}

HWTEST_F(CommandListCreate, addsStateBaseAddressToBatchBuffer) {
    Mock<Device> device;
    EXPECT_CALL(device, getMemoryManager).Times(AnyNumber());

    auto commandList = whitebox_cast(CommandList::create(productFamily, &device));
    ASSERT_NE(nullptr, commandList->commandStream);
    auto usedSpaceBefore = commandList->commandStream->getUsed();

    auto result = commandList->close();
    ASSERT_EQ(XE_RESULT_SUCCESS, result);

    auto usedSpaceAfter = commandList->commandStream->getUsed();
    ASSERT_GT(usedSpaceAfter, usedSpaceBefore);

    GenCmdList cmdList;
    ASSERT_TRUE(FamilyType::PARSE::parseCommandBuffer(cmdList,
                                                      ptrOffset(commandList->commandStream->getCpuBase(), 0),
                                                      usedSpaceAfter));
    using STATE_BASE_ADDRESS = typename FamilyType::STATE_BASE_ADDRESS;
    auto itor = find<STATE_BASE_ADDRESS *>(cmdList.begin(), cmdList.end());
    ASSERT_NE(cmdList.end(), itor);

    {
        auto cmd = genCmdCast<STATE_BASE_ADDRESS *>(*itor);

        auto heap = commandList->indirectHeaps[CommandList::DYNAMIC_STATE];
        EXPECT_TRUE(cmd->getDynamicStateBaseAddressModifyEnable());
        EXPECT_EQ(cmd->getDynamicStateBaseAddress(), heap->getHeapGpuBase());
        EXPECT_TRUE(cmd->getDynamicStateBufferSizeModifyEnable());
        EXPECT_EQ(cmd->getDynamicStateBufferSize(), heap->getMaxAvailableSpace());

        heap = commandList->indirectHeaps[CommandList::INSTRUCTION];
        EXPECT_TRUE(cmd->getInstructionBaseAddressModifyEnable());
        EXPECT_EQ(cmd->getInstructionBaseAddress(), heap->getHeapGpuBase());
        EXPECT_TRUE(cmd->getInstructionBufferSizeModifyEnable());
        EXPECT_EQ(cmd->getInstructionBufferSize(), heap->getMaxAvailableSpace());

        heap = commandList->indirectHeaps[CommandList::GENERAL_STATE];
        EXPECT_TRUE(cmd->getGeneralStateBaseAddressModifyEnable());
        EXPECT_EQ(cmd->getGeneralStateBaseAddress(), heap->getHeapGpuBase());
        EXPECT_TRUE(cmd->getGeneralStateBufferSizeModifyEnable());
        EXPECT_EQ(cmd->getGeneralStateBufferSize(), heap->getMaxAvailableSpace());

        heap = commandList->indirectHeaps[CommandList::INDIRECT_OBJECT];
        EXPECT_TRUE(cmd->getIndirectObjectBaseAddressModifyEnable());
        EXPECT_EQ(cmd->getIndirectObjectBaseAddress(), heap->getHeapGpuBase());
        EXPECT_TRUE(cmd->getIndirectObjectBufferSizeModifyEnable());
        EXPECT_EQ(cmd->getIndirectObjectBufferSize(), heap->getMaxAvailableSpace());

        heap = commandList->indirectHeaps[CommandList::SURFACE_STATE];
        EXPECT_TRUE(cmd->getSurfaceStateBaseAddressModifyEnable());
        EXPECT_EQ(cmd->getSurfaceStateBaseAddress(), heap->getHeapGpuBase());
    }
}

GEN9TEST_F(CommandListCreate, addsVfeStateToBatchBuffer) {
    Mock<Device> device;
    EXPECT_CALL(device, getMemoryManager).Times(AnyNumber());

    auto commandList = whitebox_cast(CommandList::create(productFamily, &device));
    ASSERT_NE(nullptr, commandList->commandStream);
    auto usedSpaceBefore = commandList->commandStream->getUsed();

    auto result = commandList->close();
    ASSERT_EQ(XE_RESULT_SUCCESS, result);

    auto usedSpaceAfter = commandList->commandStream->getUsed();
    ASSERT_GT(usedSpaceAfter, usedSpaceBefore);

    GenCmdList cmdList;
    ASSERT_TRUE(FamilyType::PARSE::parseCommandBuffer(cmdList,
                                                      ptrOffset(commandList->commandStream->getCpuBase(), 0),
                                                      usedSpaceAfter));
    using MEDIA_VFE_STATE = typename FamilyType::MEDIA_VFE_STATE;
    auto itor = find<MEDIA_VFE_STATE *>(cmdList.begin(), cmdList.end());
    ASSERT_NE(cmdList.end(), itor);

    {
        auto cmd = genCmdCast<MEDIA_VFE_STATE *>(*itor);
        EXPECT_EQ(cmd->getNumberOfUrbEntries(), 1u);
        EXPECT_GT(cmd->getUrbEntryAllocationSize(), 0u);
        EXPECT_GT(cmd->getMaximumNumberOfThreads(), 0u);

        EXPECT_EQ(cmd->getPerThreadScratchSpace(), 0u);
        EXPECT_EQ(cmd->getStackSize(), 0u);
        uint64_t scratchAddress = cmd->getScratchSpaceBasePointerHigh();
        scratchAddress <<= 32u;
        scratchAddress |= cmd->getScratchSpaceBasePointer();
        EXPECT_EQ(scratchAddress, 0u);
    }
}

ATSTEST_F(CommandListCreate, addsCfeStateToBatchBuffer) {
    Mock<Device> device;
    EXPECT_CALL(device, getMemoryManager).Times(AnyNumber());

    auto commandList = whitebox_cast(CommandList::create(productFamily, &device));
    ASSERT_NE(nullptr, commandList->commandStream);
    auto usedSpaceBefore = commandList->commandStream->getUsed();

    auto result = commandList->close();
    ASSERT_EQ(XE_RESULT_SUCCESS, result);

    auto usedSpaceAfter = commandList->commandStream->getUsed();
    ASSERT_GT(usedSpaceAfter, usedSpaceBefore);

    GenCmdList cmdList;
    ASSERT_TRUE(FamilyType::PARSE::parseCommandBuffer(cmdList,
                                                      ptrOffset(commandList->commandStream->getCpuBase(), 0),
                                                      usedSpaceAfter));
    using CFE_STATE = typename FamilyType::CFE_STATE;
    auto itor = find<CFE_STATE *>(cmdList.begin(), cmdList.end());
    ASSERT_NE(cmdList.end(), itor);

    {
        auto cmd = genCmdCast<CFE_STATE *>(*itor);
    }
}

} // namespace ult
} // namespace L0
