#pragma once
#include "types.h"

typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effPCPRadiateBEDPart_tag effPCPRadiateBEDPart_tag;

struct effPCPRadiateBEDPart_tag {
    effEveBEDCutHandle_t *hBEDCut;
    s32 frame;
    f32 radius;
    f32 radius_s;
    f32 radian;
    f32 radian_s;
};
