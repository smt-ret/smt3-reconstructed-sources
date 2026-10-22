#pragma once
#include "types.h"

typedef struct effPCPBlurExpParam_t effPCPBlurExpParam_t;
typedef struct effPCPBlurExp_tag effPCPBlurExp_tag;

struct effPCPBlurExp_tag {
    effPCPBlurExpParam_t *param;
    u32 abgr;
    u32 abgr_base;
    s32 frame;
};
