#pragma once
#include "types.h"

typedef struct effPCPHamaCardScatterPart_tag effPCPHamaCardScatterPart_tag;

struct effPCPHamaCardScatterPart_tag {
    s32 frame;
    f32 height;
    f32 height_s;
    f32 radian;
    f32 radian_w;
    f32 radian_s;
    f32 radius;
    f32 roll;
    sdfVector2_t axis;
};
