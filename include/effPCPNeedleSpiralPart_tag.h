#pragma once
#include "types.h"

typedef struct effPCPNeedleSpiralPart_tag effPCPNeedleSpiralPart_tag;

struct effPCPNeedleSpiralPart_tag {
    sdfVector4_t pos;
    sdfVector4_t old_pos;
    s32 frame;
    f32 radius;
    f32 radian;
};
