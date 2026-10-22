#pragma once
#include "types.h"

typedef struct putevebox_s putevebox_s;

struct putevebox_s {
    sdfVector4_t vtx[8];
    sdfVector4_t boxnml;
    sdfVector4_t facenml[6];
    f32 facenum[6];
    s32 put_serialID;
    f32 sizex;
    f32 sizey;
    f32 sizez;
    s32 anim_a;
    f32 anim_cntf;
    s16 type;
    s16 TakaraIdx;
    s16 npcHoji;
    s16 npcHit;
    s16 npcIdx;
    s16 mode2D;
    s32 facehit;
};
