#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolySphere2Param_t effPCPFlashPolySphere2Param_t;
typedef struct effPCPFlashPolySphere2Part_tag effPCPFlashPolySphere2Part_tag;
typedef struct effPCPFlashPolySphere2_tag effPCPFlashPolySphere2_tag;

struct effPCPFlashPolySphere2_tag {
    effPCPFlashPolySphere2Param_t *param;
    effPCPFlashPolySphere2Part_tag *pPart;
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
