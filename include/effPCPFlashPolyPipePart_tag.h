#pragma once
#include "types.h"

typedef struct effPCPFlashPolyPipePart_tag effPCPFlashPolyPipePart_tag;

struct effPCPFlashPolyPipePart_tag {
    u32 abgr;
    s32 frame;
    f32 length;
    f32 width_in;
    f32 width_out;
    f32 up;
    f32 rotate;
};
