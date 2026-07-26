#pragma once
#include "types.h"

typedef struct effBTL_t effBTL_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effPCP_BED_Param_t effPCP_BED_Param_t;
typedef struct effPCP_BED_tag effPCP_BED_tag;

struct effPCP_BED_tag {
    sdfMatrix4_t matrix;
    sdfVector4_t pos;
    effPCP_BED_Param_t *param;
    u32 abgr;
    s32 frame;
    effBTL_t *hBED;
    effEveBEDCutHandle_t *hBEDCut;
};
