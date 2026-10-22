#pragma once
#include "types.h"

typedef struct dbgFieldMenuCtl_tag dbgFieldMenuCtl_tag;

struct dbgFieldMenuCtl_tag {
    s8 flag;
    s32 min;
    s32 max;
    char *str;
};
