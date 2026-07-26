#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolyRingExpParam_t effPCPFlashPolyRingExpParam_t;
typedef struct effPCPFlashPolyRingExpPart_tag effPCPFlashPolyRingExpPart_tag;
typedef struct effPCPFlashPolyRingExp_tag effPCPFlashPolyRingExp_tag;

struct effPCPFlashPolyRingExp_tag {
    effPCPFlashPolyRingExpParam_t *param;
    effPCPFlashPolyRingExpPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    u32 frame;
    u32 abgr;
    f32 scale;
    f32 radius;
    f32 length;
    f32 width_in;
    f32 width_out;
    dds3FlashPolyList_t *hPoly;
};
