#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolySphere2ExpParam_t effPCPFlashPolySphere2ExpParam_t;
typedef struct effPCPFlashPolySphere2ExpPart_tag effPCPFlashPolySphere2ExpPart_tag;
typedef struct effPCPFlashPolySphere2Exp_tag effPCPFlashPolySphere2Exp_tag;

struct effPCPFlashPolySphere2Exp_tag {
    effPCPFlashPolySphere2ExpParam_t *param;
    effPCPFlashPolySphere2ExpPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
