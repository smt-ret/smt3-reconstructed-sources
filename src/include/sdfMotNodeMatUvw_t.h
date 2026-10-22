#pragma once
#include "types.h"

typedef struct sdfMotNodeMatBase_t sdfMotNodeMatBase_t;
typedef struct sdfMotNodeMatUvw_t sdfMotNodeMatUvw_t;

struct sdfMotNodeMatUvw_t {
    sdfMotNodeMatBase_t *base;
    f32 blendSrc[5];
};
