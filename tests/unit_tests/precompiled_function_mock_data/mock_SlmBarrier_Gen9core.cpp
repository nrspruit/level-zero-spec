// This is a generated file
// Check L0::ult::ModuleCreate_onlineCompilationModuleTest_Test::TestBody for details

#include "tests/unit_tests/mock_module_precompiled.h"

namespace L0 {
namespace ult {

static const uint32_t SlmBarrier_SimdSize_Gen9core = 32;

static const uint32_t SlmBarrier_ISA_Gen9core[] = 
{
    0x00600001, 0x2060020c, 0x00200000, 0x00000000, 0x00008006, 0x30000004, 0x16001000, 0x04c004c0, 
    0x00600009, 0x27801328, 0x1e8d0020, 0x00020002, 0x00601009, 0x27c01328, 0x1e8d0030, 0x00020002, 
    0x00602009, 0x28001328, 0x1e8d0040, 0x00020002, 0x00603009, 0x28401328, 0x1e8d0050, 0x00020002, 
    0x20558041, 0x03090400, 0x00800009, 0x25001228, 0x1eb10020, 0x00020002, 0x00600040, 0x22004b28, 
    0x4a000100, 0x00690780, 0x00600040, 0x23804b28, 0x4a000108, 0x00690780, 0x00601040, 0x22404b28, 
    0x4a000100, 0x006907c0, 0x00601040, 0x23c04b28, 0x4a000108, 0x006907c0, 0x00602040, 0x22804b28, 
    0x4a000100, 0x00690800, 0x00602040, 0x24004b28, 0x4a000108, 0x00690800, 0x00603040, 0x22c04b28, 
    0x4a000100, 0x00690840, 0x00603040, 0x24404b28, 0x4a000108, 0x00690840, 0x00802009, 0x25401228, 
    0x1eb10040, 0x00020002, 0x0c800031, 0x23004268, 0x06000200, 0x082411ff, 0x00800040, 0x20a01228, 
    0x0ab10020, 0x00000080, 0x0c800031, 0x24804268, 0x06000380, 0x082411ff, 0x0c802031, 0x23404268, 
    0x06000280, 0x082411ff, 0x00802040, 0x21401228, 0x0ab10040, 0x00000080, 0x0c802031, 0x24c04268, 
    0x06000400, 0x082411ff, 0x00600005, 0x2580020c, 0x06000068, 0x8f000000, 0x20019640, 0x07050c07, 
    0x00802040, 0x21c00a28, 0x0a8d0140, 0x000000e0, 0x20025640, 0x241818e7, 0x00802040, 0x23403ae8, 
    0x3a8d0340, 0x008d04c0, 0x0c800033, 0x00018070, 0x00000502, 0x04025efe, 0x0c802033, 0x0001a070, 
    0x00000542, 0x04025efe, 0x00008001, 0x32000604, 0x00000000, 0x00000000, 0x03000031, 0x20000204, 
    0x06000580, 0x02000004, 0x00000030, 0x32000004, 0x00001200, 0x00000000, 0x01800010, 0x20000a26, 
    0x1e000120, 0x00000000, 0x01802010, 0x20000a26, 0x1e000120, 0x00000000, 0x00110020, 0x34000006, 
    0x0e001400, 0x00000020, 0x00000001, 0x20843eec, 0x00000000, 0x00000000, 0x00000020, 0x34000004, 
    0x0e001400, 0x000000f0, 0x00000001, 0x2088032c, 0x00000120, 0x00000000, 0x00200001, 0x20981e2c, 
    0x00000000, 0x00000000, 0x00000001, 0x20843eec, 0x00000000, 0x00000000, 0x00000009, 0x25a00a2c, 
    0x1e000098, 0x00020002, 0x00000040, 0x20980a2c, 0x1e00009c, 0x00010001, 0x0a000031, 0x25c0020c, 
    0x060005a0, 0x021108fe, 0x00000001, 0x20900b2c, 0x00000098, 0x00000000, 0x05600010, 0x20004304, 
    0x42000090, 0x00000088, 0x05601010, 0x20004304, 0x42000090, 0x00000088, 0x05602010, 0x20004304, 
    0x42000090, 0x00000088, 0x05603010, 0x20004304, 0x42000090, 0x00000088, 0x00000040, 0x20843aec, 
    0x3a000084, 0x000005c0, 0x00b10028, 0x20000e00, 0x00000020, 0x00000020, 0x00000001, 0x209c0a2c, 
    0x00000098, 0x00000000, 0x00a00027, 0x20000000, 0x0e000000, 0xffffff50, 0x00600005, 0x25e0020c, 
    0x06000068, 0x8f000000, 0x00008001, 0x32000604, 0x00000000, 0x00000000, 0x03000031, 0x20000204, 
    0x060005e0, 0x02000004, 0x00000030, 0x32000004, 0x00001200, 0x00000000, 0x00600009, 0x28800b28, 
    0x1e8d0180, 0x00020002, 0x00601009, 0x28c00b28, 0x1e8d01a0, 0x00020002, 0x00602009, 0x29000b28, 
    0x1e8d01c0, 0x00020002, 0x00603009, 0x29400b28, 0x1e8d01e0, 0x00020002, 0x20151601, 0x00043800, 
    0x00802001, 0x27403ae8, 0x00000084, 0x00000000, 0x00600040, 0x26004b28, 0x4a000110, 0x00690880, 
    0x00601040, 0x26404b28, 0x4a000110, 0x006908c0, 0x00602040, 0x26804b28, 0x4a000110, 0x00690900, 
    0x00603040, 0x26c04b28, 0x4a000110, 0x00690940, 0x20004d01, 0x00037f07, 0x0c800033, 0x00038070, 
    0x00000602, 0x080691ff, 0x0c802033, 0x0003a070, 0x00000682, 0x080691ff, 0x07600031, 0x20000204, 
    0x06000fe0, 0x82000010, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const uint32_t SlmBarrier_CrossThreadDataBase_Gen9core[] = 
{
    0x00000000, 0x00000000, 0x00000000, 0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 
    0x7cef7000, 0x0000029a, 0x7d014000, 0x0000029a, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000020, 0x00000001, 0x00000001, 0x00000020, 0x00000001, 0x00000001, 0x00000000, 0x00000000
};


static const uint32_t SlmBarrier_PerThreadDataBase_Gen9core[] = 
{
    0x00010000, 0x00030002, 0x00050004, 0x00070006, 0x00090008, 0x000b000a, 0x000d000c, 0x000f000e, 
    0x00110010, 0x00130012, 0x00150014, 0x00170016, 0x00190018, 0x001b001a, 0x001d001c, 0x001f001e, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};


static const bool SlmBarrier_HasBarriers_Gen9core = 1;

static const std::pair<int, int> SlmBarrier_BufferArgIndicesAndOffsets_Gen9core[] = { {0x0, 0x20}, {0x1, 0x28},  };

static const uint32_t SlmBarrier_GroupSizeInPerThreadData_Gen9core[] = { 0x20, 0x1, 0x1 };

static const PrecompiledFunctionMockData SlmBarrier_Gen9core {
SlmBarrier_SimdSize_Gen9core,
SlmBarrier_ISA_Gen9core, sizeof(SlmBarrier_ISA_Gen9core),
SlmBarrier_CrossThreadDataBase_Gen9core, sizeof(SlmBarrier_CrossThreadDataBase_Gen9core),
SlmBarrier_PerThreadDataBase_Gen9core, sizeof(SlmBarrier_PerThreadDataBase_Gen9core),
SlmBarrier_GroupSizeInPerThreadData_Gen9core,
SlmBarrier_BufferArgIndicesAndOffsets_Gen9core, sizeof(SlmBarrier_BufferArgIndicesAndOffsets_Gen9core) / sizeof(SlmBarrier_BufferArgIndicesAndOffsets_Gen9core[0]),
SlmBarrier_HasBarriers_Gen9core
};

RegisterPrecompiledFunctionMocksData Register_SlmBarrier_Gen9core{ & SlmBarrier_Gen9core, "SlmBarrier", "Gen9core" }; 

} // namespace L0
} // namespace ult
