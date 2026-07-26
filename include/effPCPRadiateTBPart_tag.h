#pragma once
#include "types.h"

typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effPCPRadiateTBPart_tag effPCPRadiateTBPart_tag;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;

struct effPCPRadiateTBPart_tag {
    effPCP_ThunderPoly_t *pThunderPoly;
    effEveBEDCutHandle_t hBEDCut[UNKNOWN_ARRAY_SIZE];
    f32 radian;
    f32 radius;
    f32 rotate;
    f32 rotate_s;
    s32 frame;
};
