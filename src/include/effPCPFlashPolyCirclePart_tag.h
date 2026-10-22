#pragma once
#include "types.h"

typedef struct effPCPFlashPolyCirclePart_tag effPCPFlashPolyCirclePart_tag;

struct effPCPFlashPolyCirclePart_tag {
    u32 abgr;
    s32 frame;
    f32 radius;
    f32 radius_s;
};
