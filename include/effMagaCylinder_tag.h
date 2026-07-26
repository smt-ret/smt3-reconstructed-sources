#pragma once
#include "types.h"

typedef struct effMagaCylinderParam_t effMagaCylinderParam_t;
typedef struct effMagaCylinderPart_tag effMagaCylinderPart_tag;
typedef struct effMagaCylinder_tag effMagaCylinder_tag;
typedef struct effMagatuhi_tag effMagatuhi_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effMagaCylinder_tag {
    sdfMatrix4_t matrix;
    effMagaCylinderParam_t *param;
    effMagaCylinderPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    effMagatuhi_tag *pMagatuhi;
    u32 abgr;
    sdfMemHandle_t *hMem;
};
