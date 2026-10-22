#pragma once
#include "types.h"

typedef struct effPCPWwSpherePolyPart_tag effPCPWwSpherePolyPart_tag;

struct effPCPWwSpherePolyPart_tag {
    f32 *rot;
    s32 frame;
    f32 radian;
    f32 radian_s;
    f32 radian_add;
    f32 radius;
    f32 radius_s;
    f32 width;
};
