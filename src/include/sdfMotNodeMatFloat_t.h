#pragma once
#include "types.h"

typedef struct sdfMotNodeMatBase_t sdfMotNodeMatBase_t;
typedef struct sdfMotNodeMatFloat_t sdfMotNodeMatFloat_t;

struct sdfMotNodeMatFloat_t {
    sdfMotNodeMatBase_t *base;
    f32 blendSrc;
};
