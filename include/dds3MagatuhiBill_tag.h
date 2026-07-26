#pragma once
#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3MagatuhiBillTail_tag dds3MagatuhiBillTail_tag;
typedef struct dds3MagatuhiBill_tag dds3MagatuhiBill_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct dds3MagatuhiBill_tag {
    u32 number;
    u16 point;
    f32 scale;
    f32 t;
    u32 blend;
    sdfVector4_t pVertex[UNKNOWN_ARRAY_SIZE];
    u32 pVC[UNKNOWN_ARRAY_SIZE];
    f32 pScale[UNKNOWN_ARRAY_SIZE];
    u32 pRGBA[UNKNOWN_ARRAY_SIZE];
    u16 pCurrent[UNKNOWN_ARRAY_SIZE];
    u16 pCount[UNKNOWN_ARRAY_SIZE];
    dds3MagatuhiBillTail_tag pTail[UNKNOWN_ARRAY_SIZE];
    sdfTexHandle_t *hTex;
    sdfMemHandle_t *hMem;
    XRD773Unity_CommonMesh pMesh[UNKNOWN_ARRAY_SIZE];
};
