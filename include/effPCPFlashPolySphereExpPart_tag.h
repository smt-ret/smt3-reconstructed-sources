#pragma once
#include "types.h"

typedef struct effPCPFlashPolySphereExpPart_tag effPCPFlashPolySphereExpPart_tag;

struct effPCPFlashPolySphereExpPart_tag {
    u32 abgr;
    s32 frame;
    f32 rotate;
    f32 radius;
    f32 look_r;
    f32 width_in;
    f32 width_out;
    f32 radius_max;
};
