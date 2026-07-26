#pragma once
#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldWave_tag fldWave_tag;

struct fldWave_tag {
    s32 use;
    s32 cnt;
    s32 dmy1;
    s32 dmy2;
    dds3Basic_t *pBasic;
};
