#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolyRingParam_t effPCPFlashPolyRingParam_t;
typedef struct effPCPFlashPolyRingPart_tag effPCPFlashPolyRingPart_tag;
typedef struct effPCPFlashPolyRing_tag effPCPFlashPolyRing_tag;

struct effPCPFlashPolyRing_tag {
    effPCPFlashPolyRingParam_t *param;
    effPCPFlashPolyRingPart_tag *pPart;
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
