#pragma once
#include "types.h"

typedef struct effDistortionBlurHandle_t effDistortionBlurHandle_t;
typedef struct effPCPDistortionBlurExp_tag effPCPDistortionBlurExp_tag;

struct effPCPDistortionBlurExp_tag {
    sdfVector4_t pos;
    u8 type;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    u32 abgr;
    u32 abgr_base;
    s32 area_s;
    s32 area_e;
    s32 frame;
    effDistortionBlurHandle_t *hDistBlur;
};
