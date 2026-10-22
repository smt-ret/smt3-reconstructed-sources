#pragma once
#include "types.h"

typedef struct dds3MovieTable_t dds3MovieTable_t;
typedef struct sdfMovieInitParm_t sdfMovieInitParm_t;

struct dds3MovieTable_t {
    char *filename;
    s32 id;
    s32 layer;
    sdfMovieInitParm_t *initParm;
    bool fldmap;
    bool character;
};
