#pragma once
#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfMemRecord_t sdfMemRecord_t;

struct sdfMemRecord_t {
    sdfMemRecord_t *next;
    sdfMemHandle_t *handle;
    char *file;
    s32 line;
};
