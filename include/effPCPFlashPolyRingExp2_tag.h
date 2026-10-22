#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolyRingExp2Param_t effPCPFlashPolyRingExp2Param_t;
typedef struct effPCPFlashPolyRingExp2Part_tag effPCPFlashPolyRingExp2Part_tag;
typedef struct effPCPFlashPolyRingExp2_tag effPCPFlashPolyRingExp2_tag;

struct effPCPFlashPolyRingExp2_tag {
    effPCPFlashPolyRingExp2Param_t *param;
    effPCPFlashPolyRingExp2Part_tag *pPart;
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
