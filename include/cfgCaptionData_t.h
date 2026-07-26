#pragma once
#include "types.h"

typedef struct cfgCaptionData_t cfgCaptionData_t;

struct cfgCaptionData_t {
    char *pStr;
    char *hStr;
    s32 type;
    s32 option;
    s32 Lines;
};
