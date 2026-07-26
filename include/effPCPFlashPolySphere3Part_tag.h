#pragma once
#include "types.h"

typedef struct effPCPFlashPolySphere3Part_tag effPCPFlashPolySphere3Part_tag;

struct effPCPFlashPolySphere3Part_tag {
    u32 abgr;
    s32 frame;
    f32 rotate;
    f32 radius;
    f32 move;
    f32 move_s;
    f32 look_r;
    f32 width;
};
