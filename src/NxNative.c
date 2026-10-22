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
  u64 *v3;
  Il2CppObject *v5;
  s32 v6;

  v6 = mode;
  v3 = sub_8D3950(NxNative_CpuBoostMode, &v6);
  v5 = Concat("SetCpuBoostMode : ", v3);
  Log(v5, 0);
  sub_29C0850();
}

// 0x188c2d0
void nn_oe_SetCpuBoostMode(s32 mode) {
  sub_29C0850();
}
