#pragma once
#include "types.h"

typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct effPCPFLEACHBlurParam_t effPCPFLEACHBlurParam_t;
typedef struct effPCPFLEACHBlur_tag effPCPFLEACHBlur_tag;

struct effPCPFLEACHBlur_tag {
    effPCPFLEACHBlurParam_t *param;
    dds3Effect_PartialMultiBlur_t *hMultiBlur;
    s32 frame;
    u32 abgr;
};
