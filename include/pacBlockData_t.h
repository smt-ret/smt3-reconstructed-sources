#pragma once
#include "types.h"

typedef struct pacBlockData_t pacBlockData_t;
typedef struct pacFileCb_t pacFileCb_t;

struct pacBlockData_t {
    s32 size;
    pacFileCb_t *handle;
};
