#pragma once
#include "types.h"

typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct effPCPBlinkMultiBlurBase_tag effPCPBlinkMultiBlurBase_tag;

struct effPCPBlinkMultiBlurBase_tag {
    sdfVector4_t pos;
    u32 abgr;
    u32 abgr_base;
    u32 frame;
    f32 area;
    u32 blink;
    u32 blink_base;
    u32 *blink_abgr;
    f32 ratio;
    s32 area_min;
    dds3Effect_PartialMultiBlur_t *hBlur;
};
