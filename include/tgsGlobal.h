#pragma once
#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct tgsGlobal tgsGlobal;

struct tgsGlobal {
    sdfMemHandle_t *mh;
    sdfTexHandle_t *KotowariSpriteHandle;
    s32 step;
    s32 cnt;
    s32 ModePos;
    s32 YnPos;
    sdfMemHandle_t *htitMem[5];
    sdfTexHandle_t *htittex[5];
    sdfMemHandle_t *hmoaMem[4];
    sdfTexHandle_t *hmoatex[4];
    sdfMemHandle_t *hmodMem[4];
    sdfTexHandle_t *hmodtex[4];
    u32 bg_cnt[2];
    u32 bg_alpha[2];
    u32 titcur_cnt;
    u32 titcur_alpha;
    f32 titcur_w;
    u32 mode_cnt;
    u32 mode_alpha;
    u32 modecur_cnt;
    u32 modecur_alpha;
    u32 mode_rgba[4];
    u32 bg_fadecnt;
    u32 bg_maskrgba;
    u32 bg_rgba[5];
};
