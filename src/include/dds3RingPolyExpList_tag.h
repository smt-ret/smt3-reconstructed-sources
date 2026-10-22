#pragma once
#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3RingPolyExpList_tag dds3RingPolyExpList_tag;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct dds3RingPolyExpList_tag {
    sdfMatrix4_t dir;
    sdfMatrix4_t rot;
    sdfVector4_t pos;
    f32 scale;
    u32 blend;
    u32 abgr;
    s32 point;
    sdfVector4_t *pVertex;
    u32 *pVC;
    sdfMat_t *pMat;
    sdfMemHandle_t *hMem;
    u32 number;
    void *pTexture;
    XRD773Unity_CommonMesh *pMesh;
};
