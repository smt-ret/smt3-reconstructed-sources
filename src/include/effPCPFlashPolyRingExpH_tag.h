#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolyRingExpHPart_tag effPCPFlashPolyRingExpHPart_tag;
typedef struct effPCPFlashPolyRingExpH_tag effPCPFlashPolyRingExpH_tag;
typedef struct effPCPFlashPolyRingExpParam_t effPCPFlashPolyRingExpParam_t;

struct effPCPFlashPolyRingExpH_tag {
    effPCPFlashPolyRingExpParam_t *param;
    effPCPFlashPolyRingExpHPart_tag *pPart;
    u32 frame;
    u32 abgr;
    f32 scale;
    f32 radius;
    f32 length;
    f32 width_in;
    f32 width_out;
    dds3FlashPolyList_t *hPoly;
};
