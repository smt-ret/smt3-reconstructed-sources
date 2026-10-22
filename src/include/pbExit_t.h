#pragma once
#include "types.h"

typedef struct pbExit_t pbExit_t;
typedef struct sdfMat_t sdfMat_t;

struct pbExit_t {
    u32 flg;
    s16 x;
    s16 y;
    sdfMat_t *mat;
};
