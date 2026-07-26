#pragma once
#include "types.h"

typedef struct GameFileInfo_t GameFileInfo_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3GlobalWork_t dds3GlobalWork_t;
typedef struct evtMoon_t evtMoon_t;
typedef struct fclEncycRecord_t fclEncycRecord_t;
typedef struct fldAutoMapBuff31_t fldAutoMapBuff31_t;
typedef struct fldAutoMapBuffEX_t fldAutoMapBuffEX_t;
typedef struct fldAutoMapBuff_t fldAutoMapBuff_t;
typedef struct fldSave_t fldSave_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct dds3GlobalWork_t {
    GameFileInfo_t *GameFileInfo;
    sdfMemHandle_t *mh;
    s32 runtime;
    s32 playtime;
    s32 IntVariable[256];
    f32 FloatVariable[256];
    s32 EventBit[128];
    evtMoon_t *Moon;
    s32 maka;
    u32 stat;
    s32 maxstock;
    datUnitWork_t *unitwork[16];
    s32 stocklist[16];
    s32 stockcnt;
    u8 item[160];
    s32 *boss_press[40];
    u8 syakkincnt[64];
    u8 negoques[4];
    u8 kotowari[4];
    u16 wakimi_id;
    u16 bouga_cnt;
    f32 encountkyori;
    u16 encountcnt;
    u8 heartsequip;
    u8 hearts[64];
    u8 heartsskcnt[64];
    u8 heartscnt;
    u8 **name_img[UNKNOWN_ARRAY_SIZE];
    u8 *name_nums[4];
    u8 *name_code[4];
    u8 *cname_code[4];
    u8 cname_nums[4];
    fldSave_t *fldSave;
    s32 config_data[14];
    s32 dmy;
    u16 *hearts_sk[32];
    s8 *hearts_up_param[32];
    fclEncycRecord_t *encyc_record;
    fldAutoMapBuff31_t *amap31;
    fldAutoMapBuffEX_t *amapEX;
    fldAutoMapBuff_t *amap_Ver7;
    fldAutoMapBuff31_t *amap31_Ver7;
    fldAutoMapBuffEX_t *amapEX_Ver7;
};
