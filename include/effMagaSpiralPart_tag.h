#pragma once
#include "types.h"

typedef struct effMagaSpiralPart_tag effMagaSpiralPart_tag;

struct effMagaSpiralPart_tag {
    s32 frame;
    f32 up;
    f32 up_s;
    f32 rotate;
    f32 rotate_s;
    f32 radius;
    f32 radius_s;
};
