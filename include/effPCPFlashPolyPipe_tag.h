#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolyPipeParam_t effPCPFlashPolyPipeParam_t;
typedef struct effPCPFlashPolyPipePart_tag effPCPFlashPolyPipePart_tag;
typedef struct effPCPFlashPolyPipe_tag effPCPFlashPolyPipe_tag;

struct effPCPFlashPolyPipe_tag {
    effPCPFlashPolyPipeParam_t *param;
    effPCPFlashPolyPipePart_tag pPart[UNKNOWN_ARRAY_SIZE];
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
