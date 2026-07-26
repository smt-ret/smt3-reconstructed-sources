#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolySphereExpParam_t effPCPFlashPolySphereExpParam_t;
typedef struct effPCPFlashPolySphereExpPart_tag effPCPFlashPolySphereExpPart_tag;
typedef struct effPCPFlashPolySphereExp_tag effPCPFlashPolySphereExp_tag;

struct effPCPFlashPolySphereExp_tag {
    effPCPFlashPolySphereExpParam_t *param;
    effPCPFlashPolySphereExpPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
