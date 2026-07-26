#pragma once
#include "types.h"

typedef struct pbMapBase_t pbMapBase_t;
typedef struct sdfMat_t sdfMat_t;

struct pbMapBase_t {
    u32 flag;
    u32 mode;
    sdfMat_t *mat;
};
