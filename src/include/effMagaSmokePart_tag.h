#pragma once
#include "types.h"

typedef struct effMagaSmokePart_tag effMagaSmokePart_tag;

struct effMagaSmokePart_tag {
    sdfVector4_t pos;
    sdfVector4_t dirUp;
    s32 frame;
    f32 amplitude;
    f32 angle;
    f32 up_s;
};
