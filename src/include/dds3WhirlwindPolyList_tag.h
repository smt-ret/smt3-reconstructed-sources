#pragma once
#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3ScatterPolyListTexResource_tag dds3ScatterPolyListTexResource_tag;
typedef struct dds3WhirlwindPolyList_tag dds3WhirlwindPolyList_tag;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct dds3WhirlwindPolyList_tag {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    u32 blend;
    u32 abgr;
    u32 number;
    s32 point;
    f32 scale;
    sdfVector4_t *pVertex;
    sdfVector2_t *pUV;
    u32 *pVC;
    u32 *pABGR;
    sdfMat_t *pMat;
    sdfMemHandle_t *hMem;
    dds3ScatterPolyListTexResource_tag *hTexRes;
    void *pTexture;
    XRD773Unity_CommonMesh *pMesh;
};
