#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolyCircleParam_t effPCPFlashPolyCircleParam_t;
typedef struct effPCPFlashPolyCirclePart_tag effPCPFlashPolyCirclePart_tag;
typedef struct effPCPFlashPolyCircle_tag effPCPFlashPolyCircle_tag;

struct effPCPFlashPolyCircle_tag {
    effPCPFlashPolyCircleParam_t *param;
    effPCPFlashPolyCirclePart_tag pPart[UNKNOWN_ARRAY_SIZE];
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
