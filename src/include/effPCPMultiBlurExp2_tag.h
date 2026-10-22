#pragma once
#include "types.h"

typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct effPCPMultiBlurExp2_tag effPCPMultiBlurExp2_tag;

struct effPCPMultiBlurExp2_tag {
    sdfVector4_t pos;
    u8 type;
    u32 abgr;
    u32 abgr_base;
    s32 frame;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    s32 area_s;
    s32 area_e;
    f32 area;
    dds3Effect_PartialMultiBlur_t *hBlur;
};
