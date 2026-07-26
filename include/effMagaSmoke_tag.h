#pragma once
#include "types.h"

typedef struct effMagaSmokeParam_t effMagaSmokeParam_t;
typedef struct effMagaSmokePart_tag effMagaSmokePart_tag;
typedef struct effMagaSmoke_tag effMagaSmoke_tag;
typedef struct effMagatuhi_tag effMagatuhi_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effMagaSmoke_tag {
    sdfMatrix4_t matrix;
    effMagaSmokeParam_t *param;
    effMagaSmokePart_tag pPart[UNKNOWN_ARRAY_SIZE];
    u32 abgr;
    effMagatuhi_tag *pMagatuhi;
    sdfMemHandle_t *hMem;
};
