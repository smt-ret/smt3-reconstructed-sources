#pragma once
#include "types.h"

typedef struct dds3BezierTrackPoly_tag dds3BezierTrackPoly_tag;
typedef struct effBezier7PPart_t effBezier7PPart_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effPCPBezierBillPart_tag effPCPBezierBillPart_tag;

struct effPCPBezierBillPart_tag {
    sdfVector4_t pos;
    s32 frame;
    f32 alpha;
    dds3BezierTrackPoly_tag *hBztp;
    effBezier7PPart_t *Bezier7P;
    effEveBEDCutHandle_t *hBEDCut;
};
