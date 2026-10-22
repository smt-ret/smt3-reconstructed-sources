#pragma once
#include "types.h"

typedef struct effMagaSmokeConvPart_tag effMagaSmokeConvPart_tag;

struct effMagaSmokeConvPart_tag {
    sdfVector4_t pos;
    sdfVector4_t dirUp;
    s32 frame;
    f32 amplitude;
    f32 angle;
    f32 up_s;
};
