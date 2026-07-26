#pragma once
#include "types.h"

typedef struct sdfChipRecord_t sdfChipRecord_t;

struct sdfChipRecord_t {
    sdfChipRecord_t *next;
    void *ptr;
    char *file;
    s32 line;
};
