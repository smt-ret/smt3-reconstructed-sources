#pragma once
#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3NeedleModelPart_tag dds3NeedleModelPart_tag;
typedef struct dds3NeedleModel_tag dds3NeedleModel_tag;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct dds3NeedleModel_tag {
    sdfMatrix4_t matrix;
    dds3NeedleModelPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    u32 number;
    u32 blend;
    f32 scale[UNKNOWN_ARRAY_SIZE];
    u32 point;
    sdfVector4_t pVertex[UNKNOWN_ARRAY_SIZE];
    sdfVector4_t pNormal[UNKNOWN_ARRAY_SIZE];
    u32 pVC[UNKNOWN_ARRAY_SIZE];
    sdfMemHandle_t *hVNMem;
    sdfMat_t *pMat;
    sdfMemHandle_t *hMem;
    XRD773Unity_CommonMesh pMesh[UNKNOWN_ARRAY_SIZE];
};
