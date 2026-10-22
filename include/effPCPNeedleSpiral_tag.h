#pragma once
#include "types.h"

typedef struct dds3NeedleModel_tag dds3NeedleModel_tag;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct effPCPNeedleSpiralParam_t effPCPNeedleSpiralParam_t;
typedef struct effPCPNeedleSpiralPart_tag effPCPNeedleSpiralPart_tag;
typedef struct effPCPNeedleSpiral_tag effPCPNeedleSpiral_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPNeedleSpiral_tag {
    effPCPNeedleSpiralParam_t *param;
    effPCPNeedleSpiralPart_tag *pPart;
    u32 abgr;
    u32 number;
    dds3TrackPoly_t *hTrackPoly;
    dds3NeedleModel_tag *hNModel;
    sdfMemHandle_t *hMem;
};
