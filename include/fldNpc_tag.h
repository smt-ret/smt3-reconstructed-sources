#pragma once
#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct effHandle_t effHandle_t;
typedef struct fldNpc_tag fldNpc_tag;

struct fldNpc_tag {
    s32 Type;
    f32 x;
    f32 y;
    f32 z;
    sdfVector4_t rot;
    dds3Basic_t *Basic;
    f32 csize;
    s32 dmy2;
    s32 dmy3;
    effHandle_t *d3p;
    f32 cntf;
    s32 cnti;
    f32 cntAnmf;
    s32 cntAnmi;
    s32 npcmodel;
    s32 hojiID;
    s32 ItemBoxIdx;
    s32 tType;
    s32 tCamera;
    s32 tId1;
    s32 tId2;
    char *name;
    void *fldObj;
};
