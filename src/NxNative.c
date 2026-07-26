#include "types.h"

typedef struct NxNative_CpuBoostMode NxNative_CpuBoostMode;
typedef struct NxNative_MemoryInfo NxNative_MemoryInfo;

struct NxNative_MemoryInfo {
    u64 totalAvailableMemorySize;
    u32 totalUsedMemorySize;
    u32 totalMemoryHeapSize;
    u32 allocatedMemoryHeapSize;
    u32 programSize;
    u32 totalThreadStackSize;
    s32 threadCount;
};

struct NxNative_CpuBoostMode {
    s32 value__;
};

// 0x188c2e0
void SetCpuBoostMode(s32 mode) {
}

// 0x188c2d0
void nn_oe_SetCpuBoostMode(s32 mode) {
}
