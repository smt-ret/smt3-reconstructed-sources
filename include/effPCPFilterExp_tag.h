#pragma once
#include "types.h"

typedef struct effPCPFilterExpParam_t effPCPFilterExpParam_t;
typedef struct effPCPFilterExp_tag effPCPFilterExp_tag;

struct effPCPFilterExp_tag {
    effPCPFilterExpParam_t *param;
    u32 abgr;
    u32 abgr_base;
    s32 frame;
};
