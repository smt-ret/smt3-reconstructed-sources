#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolySphere3Param_t effPCPFlashPolySphere3Param_t;
typedef struct effPCPFlashPolySphere3Part_tag effPCPFlashPolySphere3Part_tag;
typedef struct effPCPFlashPolySphere3_tag effPCPFlashPolySphere3_tag;

struct effPCPFlashPolySphere3_tag {
    effPCPFlashPolySphere3Param_t *param;
    effPCPFlashPolySphere3Part_tag *pPart;
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
