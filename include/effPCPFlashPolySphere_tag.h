#pragma once
#include "types.h"

typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct effPCPFlashPolySphereParam_t effPCPFlashPolySphereParam_t;
typedef struct effPCPFlashPolySpherePart_tag effPCPFlashPolySpherePart_tag;
typedef struct effPCPFlashPolySphere_tag effPCPFlashPolySphere_tag;

struct effPCPFlashPolySphere_tag {
    effPCPFlashPolySphereParam_t *param;
    effPCPFlashPolySpherePart_tag *pPart;
    u32 frame;
    u32 abgr;
    f32 scale;
    dds3FlashPolyList_t *hPoly;
};
