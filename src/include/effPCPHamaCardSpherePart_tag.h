#pragma once
#include "types.h"

typedef struct effPCPHamaCardSpherePart_tag effPCPHamaCardSpherePart_tag;

struct effPCPHamaCardSpherePart_tag {
    s32 frame;
    f32 radius_s;
    f32 roll_s;
    f32 radius;
    f32 radian;
    sdfVector3_t axis;
};
