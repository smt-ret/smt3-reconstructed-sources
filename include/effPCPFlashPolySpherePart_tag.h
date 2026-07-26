#pragma once
#include "types.h"

typedef struct effPCPFlashPolySpherePart_tag effPCPFlashPolySpherePart_tag;

struct effPCPFlashPolySpherePart_tag {
    u32 abgr;
    s32 frame;
    f32 rotate;
    f32 radius;
    sdfVector4_t dir;
    f32 width_in;
    f32 width_out;
    f32 radius_max;
};
