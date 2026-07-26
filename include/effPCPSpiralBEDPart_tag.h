#pragma once
#include "types.h"

typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effPCPSpiralBEDPart_tag effPCPSpiralBEDPart_tag;

struct effPCPSpiralBEDPart_tag {
    effEveBEDCutHandle_t *hBEDCut;
    s32 frame;
    f32 up;
    f32 up_s;
    f32 rotate;
    f32 rotate_s;
    f32 radius;
    f32 radius_s;
};
