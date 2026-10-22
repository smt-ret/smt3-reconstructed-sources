#pragma once
#include "types.h"

typedef struct sdfCorePacketPointBuff_tag sdfCorePacketPointBuff_tag;

struct sdfCorePacketPointBuff_tag {
    sdfVector4_t vert;
    sdfVector4_t norm;
    sdfVector4_t color;
    sdfVector4_t uv;
    sdfCorePacketPointBuff_tag *next;
    sdfCorePacketPointBuff_tag *base0;
    sdfCorePacketPointBuff_tag *base1;
    f32 divRate;
    u8 faceDivFlag;
    u8 clipFlag;
    u16 pad1;
    u32 pad2[3];
};
