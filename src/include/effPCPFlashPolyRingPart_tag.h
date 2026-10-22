#pragma once
#include "types.h"

typedef struct effPCPFlashPolyRingPart_tag effPCPFlashPolyRingPart_tag;

struct effPCPFlashPolyRingPart_tag {
    u32 abgr;
    s32 frame;
    f32 length;
    f32 length_max;
    f32 rotate;
};
