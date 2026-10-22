#pragma once
#include "types.h"

typedef struct itfmisclinkstack_t itfmisclinkstack_t;
typedef struct manager_tag manager_tag;
typedef struct mesflow_tag mesflow_tag;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct manager_tag {
    u32 numuse;
    sdfTexHandle_t *tex;
    s32 ctr;
    u16 stat;
    s16 reserved;
    itfmisclinkstack_t *linkstack;
    mesflow_tag *pmesflow[128];
};
