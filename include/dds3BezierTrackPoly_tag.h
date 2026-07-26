#pragma once
#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3BezierTrackPoly_tag dds3BezierTrackPoly_tag;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct dds3BezierTrackPoly_tag {
    u32 abgr;
    u32 blend;
    s32 point;
    s32 count;
    s32 current;
    s32 split;
    sdfVector4_t pVertex[UNKNOWN_ARRAY_SIZE];
    u32 pVC[UNKNOWN_ARRAY_SIZE];
    sdfMat_t *pMat;
    sdfMemHandle_t *hMem;
    sdfVector4_t pHeadVertex[UNKNOWN_ARRAY_SIZE];
    u32 pHeadVC[UNKNOWN_ARRAY_SIZE];
    XRD773Unity_CommonMesh pMesh[UNKNOWN_ARRAY_SIZE];
};
