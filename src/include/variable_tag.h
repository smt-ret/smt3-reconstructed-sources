#pragma once
#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct variable_tag variable_tag;

struct variable_tag {
    char *pptr[32];
    sdfMemHandle_t *pmh[32];
};
