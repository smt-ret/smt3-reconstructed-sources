#pragma once
#include "types.h"

typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct pbMyChar_t pbMyChar_t;

struct pbMyChar_t {
    u32 flg;
    s16 x;
    s16 y;
    s32 dir;
    s32 dmy;
    sdfVector4_t pos;
    dds3ModelHandle_t *modelhdl;
    void *modelobj;
};
