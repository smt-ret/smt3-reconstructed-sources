#pragma once
#include "types.h"

typedef struct sdfIpuHeader_t sdfIpuHeader_t;

struct sdfIpuHeader_t {
    u32 magicCode;
    u32 size;
    u16 width;
    u16 height;
    s32 frameCount;
};
