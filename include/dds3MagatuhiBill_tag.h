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
    sdfVector4_t *pVertex;
    u32 *pVC;
    f32 *pScale;
    u32 *pRGBA;
    u16 *pCurrent;
    u16 *pCount;
    dds3MagatuhiBillTail_tag *pTail;
    sdfTexHandle_t *hTex;
    sdfMemHandle_t *hMem;
    XRD773Unity_CommonMesh *pMesh;
};
