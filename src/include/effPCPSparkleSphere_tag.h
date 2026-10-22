#pragma once
#include "types.h"

typedef struct billHandle_t billHandle_t;
typedef struct effPCPSparkleSphereParam_t effPCPSparkleSphereParam_t;
typedef struct effPCPSparkleSphere_tag effPCPSparkleSphere_tag;

struct effPCPSparkleSphere_tag {
    sdfVector4_t pos;
    effPCPSparkleSphereParam_t *param;
    u32 abgr;
    f32 area;
    billHandle_t *hBill;
};
