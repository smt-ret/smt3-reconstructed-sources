#pragma once
#include "types.h"

typedef struct debug_tag debug_tag;
typedef struct mesflow_tag mesflow_tag;

struct debug_tag {
    s32 cursor;
    s32 mode;
    mesflow_tag *pmesflow;
};
