#include "mock_cmdlist.h"
#include "graphics_allocation.h"

namespace xe {
namespace ult {

WhiteBox<::xe::CommandList>::WhiteBox(Device *device) : CommandListImp(device) {
}

WhiteBox<::xe::CommandList>::~WhiteBox() {
}

Mock<CommandList>::Mock(Device *device) : WhiteBox<::xe::CommandList>(device) {
    size_t batchBufferSize = 65536u;
    batchBuffer = new uint8_t[batchBufferSize];
    mockAllocation = new GraphicsAllocation(batchBuffer, batchBufferSize);
    allocation = mockAllocation;
}

Mock<CommandList>::~Mock() {
    allocation = nullptr;
    delete mockAllocation;
    delete[] batchBuffer;
}

} // namespace ult
} // namespace xe
