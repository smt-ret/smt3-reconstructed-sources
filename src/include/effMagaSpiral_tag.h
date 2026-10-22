#pragma once
#include "types.h"

typedef struct effMagaSpiralParam_t effMagaSpiralParam_t;
typedef struct effMagaSpiralPart_tag effMagaSpiralPart_tag;
typedef struct effMagaSpiral_tag effMagaSpiral_tag;
typedef struct effMagatuhi_tag effMagatuhi_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effMagaSpiral_tag {
    sdfMatrix4_t matrix;
    effMagaSpiralParam_t *param;
    effMagaSpiralPart_tag *pPart;
    effMagatuhi_tag *pMagatuhi;
    u32 abgr;
    sdfMemHandle_t *hMem;
};
