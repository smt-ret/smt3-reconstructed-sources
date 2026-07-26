#pragma once
#include "types.h"

typedef struct billHandle_t billHandle_t;
typedef struct effPCPMuzzleFlashParam_t effPCPMuzzleFlashParam_t;
typedef struct effPCPMuzzleFlash_tag effPCPMuzzleFlash_tag;

struct effPCPMuzzleFlash_tag {
    sdfMatrix4_t matrix;
    sdfVector4_t pos;
    effPCPMuzzleFlashParam_t *param;
    billHandle_t *hBillboard;
    s32 frame;
    f32 scale;
};
