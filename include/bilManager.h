#pragma once
#include "types.h"

typedef enum {
    BILL_DRAW_MODE0 = 0,
    BILL_DRAW_MODE1 = 1,
    BILL_DRAW_MAX = 2,
} BILL_DRAW;

typedef struct bilInstance_s bilInstance_s;
typedef struct bilProcessData_t bilProcessData_t;
typedef struct bilResource_t bilResource_t;
typedef struct bilSetup_t bilSetup_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct bilInstance_s {
    sdfVector4_t Pos;
    sdfVector4_t Scl;
    s32 Id;
    u32 Color;
    sdfTexHandle_t *TexHandle;
    bilInstance_s *Prev;
    bilInstance_s *Next;
    bilInstance_s *Draw;
};

struct bilSetup_t {
    s8 File;
    s16 Type;
    s16 Trans;
    f32 Offset[2];
};

struct bilResource_t {
    sdfTexHandle_t *TexHandle;
    s32 TexHandleCount;
    u16 *UvTable[2];
    f32 *XyOffset[2];
};

struct bilProcessData_t {
    s32 Count;
    bilInstance_s *First;
    bilInstance_s *Last;
    bilInstance_s *DrawFirst[18];
    bilInstance_s *DrawLast[18];
};
