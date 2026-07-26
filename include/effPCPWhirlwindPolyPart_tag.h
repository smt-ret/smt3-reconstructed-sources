#pragma once
#include "types.h"

typedef struct effPCPWhirlwindPolyPart_tag effPCPWhirlwindPolyPart_tag;

struct effPCPWhirlwindPolyPart_tag {
    f32 rot_x;
    f32 rot_y;
    s32 frame;
    f32 up_s;
    f32 radian;
    f32 radian_s;
    f32 radian_add;
    f32 radius;
    f32 radius_s;
    f32 width;
};
