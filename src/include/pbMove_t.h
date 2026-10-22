#pragma once
#include "types.h"

typedef struct pbGroupData_t pbGroupData_t;
typedef struct pbMove_t pbMove_t;

struct pbMove_t {
    s16 dir;
    u32 cnt;
    f32 scl;
    pbGroupData_t *grp;
};
