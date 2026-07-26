#pragma once
#include "types.h"

typedef struct effBTL_t effBTL_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effPCPAnalyzeBED_tag effPCPAnalyzeBED_tag;

struct effPCPAnalyzeBED_tag {
    effBTL_t *hBED;
    effEveBEDCutHandle_t *hBEDCut;
    f32 scale;
    u32 abgr;
};
