#pragma once
#include "types.h"

typedef enum {
    NB_ACT_SEQ_NON = 0,
    NB_ACT_SEQ_COMM = 1,
    NB_ACT_SEQ_AI = 2,
    NB_ACT_SEQ_AISCR = 3,
    NB_ACT_SEQ_BAD = 4,
    NB_ACT_SEQ_TARSEL = 5,
    NB_ACT_SEQ_STKSEL = 6,
    NB_ACT_SEQ_READY = 7,
    NB_ACT_SEQ_SKILL = 8,
    NB_ACT_SEQ_NEGO = 9,
    NB_ACT_SEQ_NEGORESULT = 10,
    NB_ACT_SEQ_BADWAIT = 11,
    NB_ACT_SEQ_WAIT = 12,
    NB_ACT_SEQ_ESCAPE = 13,
    NB_ACT_SEQ_RETURN = 14,
    NB_ACT_SEQ_INVISIBLE = 15,
    NB_ACT_SEQ_RESERVE1 = 16,
    NB_ACT_SEQ_RESERVE2 = 17,
    NB_ACT_SEQ_CHECK1 = 18,
    NB_ACT_SEQ_DEADSCRIPT = 19,
    NB_ACT_SEQ_CHECK3 = 20,
    NB_ACT_SEQ_ATO = 21,
    NB_ACT_SEQ_END = 22,
    NB_ACT_SEQ_MAX = 23,
} NB_ACT_SEQ;

typedef enum {
    NB_ACT_TYPE_NORMAL = 0,
    NB_ACT_TYPE_INOTI = 1,
    NB_ACT_TYPE_BINJO = 2,
    NB_ACT_TYPE_KOKETA = 3,
    NB_ACT_TYPE_COUNTER = 4,
    NB_ACT_TYPE_DEADSCRIPT = 5,
    NB_ACT_TYPE_MAX = 6,
} NB_ACT_TYPE;

typedef enum {
    NB_ACT_ERR_NON = 0,
    NB_ACT_ERR_COST = 1,
    NB_ACT_ERR_MUDA = 2,
    NB_ACT_ERR_SUMMON = 3,
} NB_ACT_ERR;

typedef enum {
    NB_BADAI_WAIT = 0,
    NB_BADAI_ATTACK = 1,
    NB_BADAI_KAIFUKU = 2,
    NB_BADAI_KAJA = 3,
    NB_BADAI_MAKA = 4,
    NB_BADAI_NEGO = 5,
    NB_BADAI_RETURN = 6,
    NB_BADAI_DAMAGE = 7,
    NB_BADAI_SUMMON = 8,
    NB_BADAI_BADWAIT = 9,
    NB_BADAI_MAX = 10,
} NB_BADAI;

typedef enum {
    NB_KOUKA_HIT = 0,
    NB_KOUKA_HANSYA = 1,
    NB_KOUKA_KYUSYU = 2,
    NB_KOUKA_MUKOU = 3,
    NB_KOUKA_SAKE = 4,
    NB_KOUKA_MISS = 5,
    NB_KOUKA_SUMMON = 6,
    NB_KOUKA_ANALYZE = 7,
    NB_KOUKA_ESCAPE = 8,
    NB_KOUKA_MAKA = 9,
    NB_KOUKA_ENEESC = 10,
    NB_KOUKA_ONGSHADOW = 11,
    NB_KOUKA_AURORA = 12,
    NB_KOUKA_PRESS = 13,
    NB_KOUKA_FLARECHARGE = 14,
} NB_KOUKA;

typedef enum {
    NB_DAMAGE_TYPE_HP = 0,
    NB_DAMAGE_TYPE_MP = 1,
} NB_DAMAGE_TYPE;

typedef enum {
    NB_DAMAGE_NORMAL = 0,
    NB_DAMAGE_CRITICAL = 1,
    NB_DAMAGE_WEAK = 2,
    NB_DAMAGE_EASY = 3,
} NB_DAMAGE;

typedef enum {
    NB_KAIFUKU_NORMAL = 0,
    NB_KAIFUKU_KYUSYU = 1,
    NB_KAIFUKU_DRAIN = 2,
    NB_KAIFUKU_DRAINCOL = 3,
} NB_KAIFUKU;

typedef enum {
    NB_BADKAIFUKU_PRESS = 0,
    NB_BADKAIFUKU_ACTION = 1,
    NB_BADKAIFUKU_DAMAGE = 2,
    NB_BADKAIFUKU_END = 3,
} NB_BADKAIFUKU;

typedef enum {
    NB_3ZOKUSEI_DARK = 0,
    NB_3ZOKUSEI_NEUTRAL = 1,
    NB_3ZOKUSEI_LIGHT = 2,
} NB_3ZOKUSEI;

typedef enum {
    NON = 0,
    IN = 1,
    SELECT = 2,
    ENTER = 3,
    OUT = 4,
} NB_COMMSEL_STAT;

typedef enum {
    COMM = 0,
    TALK = 1,
    ITEM = 2,
    SUMMON = 3,
    RETURN = 4,
    ESCAPE = 5,
    MAX = 6,
} NB_COMMSEL_TYPE;

typedef enum {
    NON = 0,
    BOSS = 1,
    IKKIUTI = 2,
    COST = 3,
    DEAD = 4,
    CLOSE = 5,
    FULL = 6,
} NB_COMMSEL_ERR;

typedef enum {
    DVLCNG = 0,
    HP = 1,
    MP = 2,
    BAD = 3,
    MOT = 4,
    AISYO = 5,
    MAX = 6,
} NB_DEBUG_MENU;

typedef enum {
    SELECT = 1,
    CHANGE1 = 2,
    DVLCHANGE = 3,
    MENU = 4,
    HP = 5,
    MP = 6,
    BAD = 7,
    MOT = 8,
    MOTDATA = 9,
    AISYO = 10,
} NB_DEBUG_SEQ;

typedef enum {
    TXTCONV = 0,
    MSGCONV = 1,
    PLAYER = 2,
} NB_HELP_TYPE;

typedef enum {
    NEGO = 0,
    JYOKYO = 1,
    DVNAME = 2,
    ERR = 3,
} NB_HELP_MSG;

typedef enum {
    DAMAGE = 0,
    HANSYA = 1,
    KYUSYU = 2,
    MUKOU = 3,
    ENCOUNT = 4,
    RETURN = 5,
    STONEDEAD = 6,
    CRITICAL = 7,
    NEGO_KAIHUKU = 8,
    NEGO_KYUSYU = 9,
    NEGO_STONE = 10,
} NB_HITEFF;

typedef enum {
    HPDAMAGE = 0,
    MPDAMAGE = 1,
    HPKAIFUKU = 2,
    MPKAIFUKU = 3,
    HPMPDAMAGE = 4,
    HPMPKAIFUKU = 5,
} NB_NUMEFF;

typedef enum {
    BIKU = 0,
    WEAK = 1,
    CRITICAL = 2,
    MISS = 3,
    BLOCK = 4,
} NB_MOJIEFF;

typedef enum {
    SKILLEFF = 0,
    TARMOVE = 1,
    HOMEMOVE = 2,
    ROT = 3,
    HOMEROT = 4,
    UNITCOL = 5,
    UNITHOMECOL = 6,
    UNITA = 7,
    UNITHOMEA = 8,
    DMGMOT = 9,
    BADDMGMOT = 10,
    RETURN = 11,
    SUMMON = 12,
    SAKE = 13,
    SKILLCOLOFF = 14,
    HITEFF = 15,
    NUMEFF = 16,
    HPMP = 17,
    PRESS = 18,
    BADSTAT = 19,
    BADMOTKAIFUKU = 20,
    SKILLEFF2 = 21,
    MOJIEFF = 22,
    BADEFF = 23,
    BADEFFKAIFUKU = 24,
    SE = 25,
    SKILLEFF1 = 26,
    MOTION = 27,
    SE2 = 28,
    SELOCK = 29,
    HITSTOP = 30,
    NEWPRESS = 31,
    MOTIONSTOP = 32,
    MOTIONSTOPCLS = 33,
    ANALYZE = 34,
    JYOKYOHELP = 35,
    DEADPCM = 36,
    BADMOT = 37,
    FORMONOFF = 38,
    BOSSONGBUN = 39,
    BOSSONGBUN2 = 40,
    BOSSONGOUT = 41,
    BOSSONGOUT2 = 42,
    SKILLEFF3 = 43,
    FORMFLAGONOFF = 44,
    FLY = 45,
    DEADEVENT = 46,
    FADEOUT = 47,
    FADEIN = 48,
    SKILLNAME = 49,
    HOJO = 50,
    FLARECHARGE = 51,
    PADSHOCK = 52,
    EASYDMGMOT = 53,
    SKILLCOLON = 54,
    SKILLMOTION = 55,
    STKPNL_FOUT = 56,
    STKPNL_END = 57,
    HATUDOEFF_END = 58,
} NB_KOUKA_TYPE;

typedef enum {
    MODEL_ID = 255,
} NB_FLY;

typedef enum {
    NB_NEWPRESS_NORMAL = 0,
    NB_NEWPRESS_WAIT = 1,
    NB_NEWPRESS_WEEK = 2,
    NB_NEWPRESS_CRITICAL = 3,
    NB_NEWPRESS_MISS = 4,
    NB_NEWPRESS_MUKOU = 5,
    NB_NEWPRESS_HANSYA = 6,
    NB_NEWPRESS_KYUSYU = 7,
    NB_NEWPRESS_ESC = 8,
    NB_NEWPRESS_RETURN = 9,
    NB_NEWPRESS_SUMMON = 10,
    NB_NEWPRESS_NEGO_OK = 11,
    NB_NEWPRESS_NEGO_NG1 = 12,
    NB_NEWPRESS_NEGO_NG2 = 13,
    NB_NEWPRESS_TURN = 14,
    NB_NEWPRESS_ADD2 = 15,
    NB_NEWPRESS_ADD4 = 16,
    NB_NEWPRESS_ADD3 = 17,
} NB_NEWPRESS;

typedef enum {
    NB_SIDE_PLAYER = 0,
    NB_SIDE_ENEMY = 1,
    NB_SIDE_NPC = 2,
} NB_SIDE;

typedef enum {
    NORMAL = 0,
    DAMAGE = 1,
    SAKE = 2,
    BADSTAT = 3,
    LOAD = 4,
} NB_FORM_TYPE;

typedef enum {
    NB_PARTY_STAT_EXIST = 1,
    NB_PARTY_STAT_ENEMY = 2,
    NB_PARTY_STAT_NPC = 4,
    NB_PARTY_STAT_INVISIBLE = 8,
    NB_PARTY_STAT_NOSEL = 16,
    NB_PARTY_STAT_LOST = 32,
    NB_PARTY_STAT_BINJO = 64,
    NB_PARTY_STAT_USED_HOJO = 128,
    NB_PARTY_STAT_CRITICAL = 256,
    NB_PARTY_STAT_KUIUSE = 512,
    NB_PARTY_STAT_KUISTOP = 1024,
    NB_PARTY_STAT_MAKABARA = 2048,
} NB_PARTY;

typedef enum {
    NB_CNT_DMG = 0,
    NB_CNT_AI0 = 1,
    NB_CNT_AI1 = 2,
    NB_CNT_AI2 = 3,
    NB_CNT_BATK = 4,
    NB_CNT_MATK = 5,
    NB_CNT_ESC = 6,
    NB_CNT_DEF = 7,
    NB_CNT_HIT = 8,
    NB_CNT_HYOKETU_OFF = 9,
    NB_CNT_KAEN_OFF = 10,
    NB_CNT_JYUSATU_OFF = 11,
    NB_CNT_HAMA_OFF = 12,
    NB_CNT_MAGIC_REF = 13,
    NB_CNT_BUTURI_REF = 14,
    NB_CNT_ATKx2 = 15,
    NB_CNT_TARGET = 16,
    NB_CNT_KOUDOCNT = 17,
    NB_CNT_PRESSKOUDO = 18,
    NB_CNT_AISYO = 19,
    NB_CNT_MAX = 20,
} NB_CNT;

typedef enum {
    NB_SND_END = 0,
    NB_SND_START = 1,
    NB_SND_LOAD = 2,
} NB_SND;

typedef enum {
    NON = 0,
    MAE = 1,
    ENCOUNT = 2,
    EVENT = 3,
    PRESSMAE = 4,
    PRESSNIIDA = 5,
    ACTIONMAE = 6,
    ACTION = 7,
    NPC = 8,
    CHKEND = 9,
    CHKTURN = 10,
    ATO = 11,
    RESULT = 12,
    END = 13,
    DEBUG = 14,
    RENZOKU = 15,
} NB_PHASE;

typedef enum {
    NON = 0,
    ENE0 = 1,
    GAMEOVER = 2,
    ESCAPE = 3,
    TAIKYO = 4,
    RENZOKU = 5,
    STONE = 6,
    EVENT = 7,
    ENDING = 8,
    NEGOENE0 = 9,
} NB_END;

typedef enum {
    NB_TARSEL_TYPE_NORMAL = 0,
    NB_TARSEL_TYPE_SUMMON = 1,
} NB_TARSEL_TYPE;

typedef enum {
    NB_MAKA_TYPE_NORMAL = 0,
} NB_MAKA_TYPE;

typedef enum {
    NB_MAKA_STAT_NON = 0,
    NB_MAKA_STAT_IN = 1,
    NB_MAKA_STAT_OUT = 2,
} NB_MAKA_STAT;

typedef enum {
    NEGO_FLOW_ONE = 1,
    NEGO_FLOW_FULLMOON = 2,
    NEGO_FLOW_STOCK = 3,
    NEGO_FLOW_DOUCHARA = 4,
    NEGO_FLOW_INNEN = 5,
    NEGO_FLOW_TWO = 6,
    NEGO_FLOW_QUESTION = 7,
    NEGO_FLOW_FIGHT = 8,
    NEGO_FLOW_OK = 9,
    NEGO_FLOW_NG = 10,
    NEGO_FLOW_DRAIN = 11,
    NEGO_FLOW_MUKAN = 12,
    NEGO_FLOW_SENSEI = 13,
    NEGO_FLOW_BINJO = 14,
    NEGO_FLOW_INOCHI = 15,
    NEGO_FLOW_KOKETA = 16,
    NEGO_FLOW_MAX = 17,
} NEGO_FLOW;

typedef enum {
    NEGO_TYPE_NORMAL = 0,
    NEGO_TYPE_MUKAN = 1,
    NEGO_TYPE_SENSEI = 2,
    NEGO_TYPE_BINJO = 3,
    NEGO_TYPE_INOTI = 4,
    NEGO_TYPE_KOKETA = 5,
    NEGO_TYPE_PANIC = 6,
} NEGO_TYPE;

typedef enum {
    OFF = 0,
    ON = 1,
    NORMAL = 1,
    TAIKYO = 2,
    NAKAMA = 3,
    ENEMY = 4,
    ALLID = 5,
    ALL = 6,
    PG0 = 7,
    GAMEOVER = 8,
    NAKAMATAIKYO = 9,
} NEGO_END;

typedef enum {
    NEGO_MY_REQ_NAKAMA = 0,
    NEGO_MY_REQ_MAKKA = 1,
    NEGO_MY_REQ_MAKKAITEM = 2,
    NEGO_MY_REQ_STONE = 3,
    NEGO_MY_REQ_BUTUBUTU = 4,
    NEGO_MY_REQ_KAKE = 5,
    NEGO_MY_REQ_INFO = 6,
    NEGO_MY_REQ_MAX = 7,
} NEGO_MY_REQ;

typedef enum {
    NEGO_ENE_REQ_ITEM = 0,
    NEGO_ENE_REQ_MAKKA = 1,
    NEGO_ENE_REQ_QUES = 2,
    NEGO_ENE_REQ_HPMP = 3,
    NEGO_ENE_REQ_FIGHT = 4,
    NEGO_ENE_REQ_KAKE = 5,
    NEGO_ENE_REQ_MAX = 6,
} NEGO_ENE_REQ;

typedef enum {
    NEGO_QUES_NORMAL = 0,
    NEGO_QUES_YOSUGA = 1,
    NEGO_QUES_MUSUBI = 2,
    NEGO_QUES_SIJIMA = 3,
    NEGO_QUES_MAX = 4,
} NEGO_QUES;

typedef enum {
    NEGO_INFO_DEVIL = 0,
    NEGO_INFO_FIELD = 1,
    NEGO_INFO_WORLD = 2,
    NEGO_INFO_MAX = 3,
} NEGO_INFO;

typedef enum {
    NEGO_AISYO_NORMAL = 0,
    NEGO_AISYO_KILLER = 1,
    NEGO_AISYO_NG = 2,
} NEGO_AISYO;

typedef enum {
    NEGO_OKCHK_OK = 0,
    NEGO_OKCHK_CYUCYO = 1,
    NEGO_OKCHK_FUSOKU = 2,
    NEGO_OKCHK_MOTINIGE = 3,
    NEGO_OKCHK_MAX = 4,
} NEGO_OKCHK;

typedef enum {
    NEGO_HOJO_TYPE_MAKADOWN = 0,
    NEGO_HOJO_TYPE_IKARI = 1,
    NEGO_HOJO_TYPE_STOP = 2,
    NEGO_HOJO_TYPE_RITUUP = 3,
} NEGO_HOJO_TYPE;

typedef enum {
    NB_SKILLERR_ERR = 1,
    NB_SKILLERR_LIVE = 2,
    NB_SKILLERR_MUDA = 3,
    NB_SKILLERR_ZUMI = 4,
} NB_SKILLERR;

typedef enum {
    NB_STAGE_STAT_NON = 0,
    NB_STAGE_STAT_LOAD = 1,
    NB_STAGE_STAT_SET = 2,
    NB_STAGE_STAT_WAIT = 3,
    NB_STAGE_STAT_FREE = 4,
} NB_STAGE_STAT;

typedef enum {
    NB_STAGE_RUN_INVALID = 0,
    NB_STAGE_RUN_WAIT = 1,
    NB_STAGE_RUN_LOAD = 2,
    NB_STAGE_RUN_FREE = 3,
} NB_STAGE_RUN;

typedef enum {
    NB_TARSEL_STAT_WAIT = 0,
    NB_TARSEL_STAT_SELECT = 1,
    NB_TARSEL_STAT_CANCEL = 2,
} NB_TARSEL_STAT;

typedef enum {
    SINGLE = 0,
    GROUP = 1,
    ALL = 2,
} NB_TARSEL_CTYPE;

typedef enum {
    PB = 0,
    MSE = 1,
    NSE = 2,
} BP_TYPE;

typedef enum {
    NB_UANIME_ACTIVE = 0,
} NB_UANIME;

typedef enum {
    jyokyohelp_000_1 = 0,
    jyokyohelp_000_2 = 1,
    jyokyohelp_001_1 = 2,
    jyokyohelp_001_2 = 3,
    jyokyohelp_002_1 = 4,
    jyokyohelp_002_2 = 5,
    jyokyohelp_003_1 = 6,
    jyokyohelp_003_2 = 7,
    jyokyohelp_004_1 = 8,
    jyokyohelp_004_2 = 9,
    jyokyohelp_005_1 = 10,
    jyokyohelp_005_2 = 11,
    jyokyohelp_006_1 = 12,
    jyokyohelp_006_2 = 13,
    jyokyohelp_007_1 = 14,
    jyokyohelp_007_2 = 15,
    jyokyohelp_008_1 = 16,
    jyokyohelp_008_2 = 17,
    jyokyohelp_009_1 = 18,
    jyokyohelp_009_2 = 19,
    jyokyohelp_010_1 = 20,
    jyokyohelp_010_2 = 21,
    jyokyohelp_011_1 = 22,
    jyokyohelp_011_2 = 23,
    jyokyohelp_012_1 = 24,
    jyokyohelp_012_2 = 25,
    jyokyohelp_013_1 = 26,
    jyokyohelp_013_2 = 27,
    jyokyohelp_014_1 = 28,
    jyokyohelp_014_2 = 29,
    jyokyohelp_015_1 = 30,
    jyokyohelp_015_2 = 31,
    jyokyohelp_016_1 = 32,
    jyokyohelp_016_2 = 33,
    jyokyohelp_017_1 = 34,
    jyokyohelp_017_2 = 35,
    jyokyohelp_018_1 = 36,
    jyokyohelp_018_2 = 37,
    jyokyohelp_019_1 = 38,
    jyokyohelp_019_2 = 39,
    jyokyohelp_020_1 = 40,
    jyokyohelp_020_2 = 41,
    jyokyohelp_021_1 = 42,
    jyokyohelp_021_2 = 43,
    jyokyohelp_022_1 = 44,
    jyokyohelp_022_2 = 45,
    jyokyohelp_023_1 = 46,
    jyokyohelp_023_2 = 47,
    jyokyohelp_024_1 = 48,
    jyokyohelp_024_2 = 49,
    jyokyohelp_025_1 = 50,
    jyokyohelp_025_2 = 51,
    jyokyohelp_026_1 = 52,
    jyokyohelp_026_2 = 53,
    jyokyohelp_027_1 = 54,
    jyokyohelp_027_2 = 55,
    jyokyohelp_028_1 = 56,
    jyokyohelp_028_2 = 57,
    jyokyohelp_029_1 = 58,
    jyokyohelp_029_2 = 59,
    jyokyohelp_030_1 = 60,
    jyokyohelp_030_2 = 61,
    jyokyohelp_031_1 = 62,
    jyokyohelp_031_2 = 63,
    jyokyohelp_032_1 = 64,
    jyokyohelp_032_2 = 65,
    jyokyohelp_033_1 = 66,
    jyokyohelp_033_2 = 67,
    jyokyohelp_034_1 = 68,
    jyokyohelp_034_2 = 69,
    jyokyohelp_035_1 = 70,
    jyokyohelp_035_2 = 71,
    jyokyohelp_036_1 = 72,
    jyokyohelp_036_2 = 73,
    jyokyohelp_037_1 = 74,
    jyokyohelp_037_2 = 75,
    jyokyohelp_038_1 = 76,
    jyokyohelp_038_2 = 77,
    jyokyohelp_039_1 = 78,
    jyokyohelp_039_2 = 79,
    jyokyohelp_040_1 = 80,
    jyokyohelp_040_2 = 81,
    jyokyohelp_041_1 = 82,
    jyokyohelp_041_2 = 83,
    jyokyohelp_042_1 = 84,
    jyokyohelp_042_2 = 85,
    jyokyohelp_043_1 = 86,
    jyokyohelp_043_2 = 87,
    jyokyohelp_044_1 = 88,
    jyokyohelp_044_2 = 89,
    jyokyohelp_045_1 = 90,
    jyokyohelp_045_2 = 91,
    jyokyohelp_046_1 = 92,
    jyokyohelp_046_2 = 93,
    jyokyohelp_047_1 = 94,
    jyokyohelp_047_2 = 95,
    jyokyohelp_048_1 = 96,
    jyokyohelp_048_2 = 97,
    jyokyohelp_049_1 = 98,
    jyokyohelp_049_2 = 99,
    jyokyohelp_050_1 = 100,
    jyokyohelp_050_2 = 101,
} JYOKYOHELP;

typedef enum {
    MENU = 0,
    PARTY = 1,
    TURN = 2,
    BANNOUNCE = 3,
    TURNCHG = 4,
    ANALYZE = 5,
    STKSEL = 6,
    MAKA = 7,
} bUI;

typedef struct NB_FILEHANDLE_T NB_FILEHANDLE_T;
typedef struct SOBED_PB_LIST SOBED_PB_LIST;
typedef struct bDrawText bDrawText;
typedef struct bpHeader_t bpHeader_t;
typedef struct bpTypeTable_t bpTypeTable_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTLSysHandle_t effBTLSysHandle_t;
typedef struct effBTL_t effBTL_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fileHandle_t fileHandle_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbActionStack_t nbActionStack_t;
typedef struct nbCommSelProcessData_t nbCommSelProcessData_t;
typedef struct nbDebugProcessData_t nbDebugProcessData_t;
typedef struct nbE nbE;
typedef struct nbEventFuncList_t nbEventFuncList_t;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbEventProcessData_t_usershutdownDelegate nbEventProcessData_t_usershutdownDelegate;
typedef struct nbFormData_t nbFormData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbHelpProcessData_t nbHelpProcessData_t;
typedef struct nbKoukaData_t nbKoukaData_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbKoukaProcessData_t nbKoukaProcessData_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbMakaProcessData_t nbMakaProcessData_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;
typedef struct nbNewBattleSeqData_t nbNewBattleSeqData_t;
typedef struct nbPanelFlashData_t nbPanelFlashData_t;
typedef struct nbParty_t nbParty_t;
typedef struct nbSound_t nbSound_t;
typedef struct nbStageProcessData_t nbStageProcessData_t;
typedef struct nbTarSelProcessData_t nbTarSelProcessData_t;
typedef struct nbTimeList_t nbTimeList_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct nbFormation_t {
    sdfVector4_t orgpos;
    sdfVector4_t orgrot;
    sdfVector4_t pos;
    sdfVector4_t rot;
    sdfVector4_t center;
    f32 r;
    f32 h;
    f32 cr;
    f32 scl;
    f32 oneshotr;
    f32 allshotr;
    f32 movey;
    f32 movez;
    s32 type;
    u32 time;
    u32 stat;
    u32 flag;
    u32 anime;
    dds3Basic_t *basic;
    s32 serial;
    evtUnitHandle_t *hunit;
    s16 partyindex;
    s16 formindex;
    u32 autotime;
    effBTLSysHandle_t *badeff;
    u32 modelcol;
    f32 motspeed;
    s16 motendtype;
    s16 motenddata;
    s16 nexthokan;
    s16 nexthokanb;
    s16 waitmot;
    s16 motcate;
    s32 reserve4;
    NB_FILEHANDLE_T *packh;
    char *akey;
    s32 read_minor;
    void *modelobj;
    sdfVector3_t modelrot;
    void *modelanm;
    s32 asyncPhase;
    void *aReq;
    void *readObject;
    u32 tartime;
    f32 range;
    f32 addmovet;
    f32 movet;
    nbFormData_t *data1;
    nbFormData_t *data2;
    sdfVector4_t tarpos;
    sdfVector4_t startpos;
};

struct nbFormData_t {
    s8 c[4];
    s16 s[2];
    s32 i;
    f32 mf;
    void *p;
};

struct nbPanelFlashData_t {
    s32 PT_1_Frame;
    u32 PT_1_Process;
    s32 PT_2_Frame;
    u32 PT_2_Process;
    f32 PT_2_Rate;
    s32 PT_3_Frame;
    u32 PT_3_Process;
    f32 PT_3_Rate;
    u32 abgr;
    u32 abgr_c;
    f32 scale_x;
    f32 scale_y;
    s32 addX;
    s32 addY;
    void *obj;
};

struct SOBED_PB_LIST {
    void *gobj;
    s32 reversePB;
};

struct nbNewBattleSeqData_t {
    s32 encountpack;
    s32 encounttbl;
};

struct bDrawText {
    char *DrawTxt;
    s32 color;
};

struct nbKoukaPacket_t {
    s16 startframe;
    s16 framelength;
    s8 type;
    u8 flag;
    u16 time;
    s32 uniqueid;
    nbKoukaPacket_t *next;
    nbKoukaPacket_t *prev;
    nbFormation_t *form;
    datUnitWork_t *unit;
    nbParty_t *party;
    s32 partyno;
    effBTLCutHandle_t *cuteff;
    nbKoukaData_t *data1;
    nbKoukaData_t *data2;
    sdfVector4_t v;
    f32 startframeF;
    f32 framelengthF;
    f32 timeF;
};

struct nbParty_t {
    s16 flag;
    s16 formindex;
    s16 statindex;
    u16 partyindex;
    s16 count[20];
    u32 aisyo[16];
    u16 hojoskill[8];
};

struct nbKoukaData_t {
    s8 c[4];
    s16 s[2];
    s32 i;
    f32 f;
    void *p;
};

struct nbEventFuncList_t {
    s32 resource;
    s32 pb;
    void *func;
    s32 encno;
    char *seid;
    u16 fadetime;
    u16 fadeout;
    u16 fadestop;
    u16 fadein;
};

struct nbE {
    s32 event_no;
    s32 index;
    char *path;
    char *prefab;
    s32 target;
    s32 eye;
    f32 rotY;
};

struct nbStageProcessData_t {
    u8 stat;
    u8 now;
    u8 req;
    u8 reserve1;
    s16 major;
    u16 minor;
    u32 bluralp;
};

struct nbTimeList_t {
    u16 lockframe;
    u16 endframe;
    u16 hp;
    u16 reserve1;
};

struct nbActionProcessData_t {
    nbMainProcessData_t *data;
    u32 stat;
    s32 uniqueid;
    s8 seq;
    s8 nextseq;
    u16 seqtime;
    s32 seqcnt;
    s32 skilltime;
    f32 press;
    s32 newpresstype;
    s16 newpress_p;
    s16 newpress_ten;
    s32 newaddpresstype;
    nbParty_t *party;
    nbFormation_t *form;
    datUnitWork_t *work;
    s32 partyindex;
    s32 type;
    s32 target;
    u32 select;
    u32 timer;
    s32 runerr;
    s32 jyokyomes;
    s32 jyo_varid;
    s32 jyo_varind;
    s32 adata;
    s32 autoskill;
    s32 allhpdamage;
    s32 allmpdamage;
    s32 massuruid;
    u32 negotype;
    s32 motion;
    s32 motse;
    s32 motionO;
    effBTL_t *hEffBTL;
    u8 hBed[UNKNOWN_ARRAY_SIZE];
    fileHandle_t *hSkillSe;
    sdfMemHandle_t *hSkillMem;
    u32 skillmidi;
    char *se0_name;
    char *se1_name;
    void pTexture[UNKNOWN_ARRAY_SIZE];
    nbTimeList_t *timelist[32];
    u32 packettime;
    s32 hitstopframe;
    u32 aiselect;
    s32 aijokentbl;
    s8 aichktbl[5];
    u32 aisummonid;
};

struct nbMainProcessData_t {
    nbFormation_t form[UNKNOWN_ARRAY_SIZE];
    datUnitWork_t enemyunit[UNKNOWN_ARRAY_SIZE];
    nbParty_t party[UNKNOWN_ARRAY_SIZE];
    s16 playerpcnt;
    s16 enemypcnt;
    s16 activeunit;
    nbSound_t sound[UNKNOWN_ARRAY_SIZE];
    sdfMemHandle_t *sound_mem;
    s32 encpackno;
    s32 packno;
    s32 packindex;
    s32 encno;
    s32 formationtype;
    nbActionStack_t actionstack[UNKNOWN_ARRAY_SIZE];
    s32 actionstackp;
    u32 endtype;
    s8 order[12];
    s8 orderindex;
    s16 previndex;
    u16 prevcommand;
    u16 prevcommind;
    u16 prevflag;
    u16 debug;
    u32 stat;
    u32 flag;
    u8 turn;
    s8 phase;
    s8 nextphase;
    u8 esccnt;
    u16 phasetime;
    u32 battletime;
    f32 press3;
    s16 press4_p;
    s16 press4_ten;
    s16 press4_hansya;
    s16 press4_miss;
    s16 StageMajor;
    s16 StageMinor;
    s32 TarSelType;
    s32 nakamayobi;
    s32 eventno;
    s32 eventrid;
    s16 negopformindex;
    s16 negoeformindex;
    s32 negoresult;
    u8 item[4];
    u8 itemcnt[4];
    u32 maka;
    u32 exp;
    dds3Basic_t *baselight;
    dds3Basic_t *niidalight;
    dds3Basic_t *gamecamera;
    dds3Basic_t *niidacamera;
    dds3Basic_t *eventcamera;
    dds3ProcessID_t *MainProcessID;
    dds3ProcessID_t *MaeProcessID;
    dds3ProcessID_t *AtoProcessID;
    dds3ProcessID_t *ResultProcessID;
    dds3ProcessID_t *StageProcessID;
    dds3ProcessID_t *UnitProcessID;
    dds3ProcessID_t *ActionProcessID[4];
    s32 NowActionProcess;
    dds3ProcessID_t *CommSelProcessID;
    dds3ProcessID_t *TarSelProcessID;
    dds3ProcessID_t *EffectProcessID;
    dds3ProcessID_t *KoukaProcessID;
    dds3ProcessID_t *NegoProcessID;
    dds3ProcessID_t *CameraProcessID;
    dds3ProcessID_t *DebugProcessID;
    dds3ProcessID_t *AiScriptProcessID;
    dds3ProcessID_t *PanelProcessID;
    dds3ProcessID_t *HelpProcessID;
    dds3ProcessID_t *AutoCommProcessID;
    dds3ProcessID_t *EncProcessID;
    dds3ProcessID_t *EventProcessID;
    effBTL_t *HatudoEff;
    sdfTexHandle_t *hPnlTex1;
    sdfTexHandle_t *hPnlTex2;
    sdfTexHandle_t *hPnlTex3;
    sdfTexHandle_t *hPnlTex4;
    s32 jyokyomsgid;
    s32 miscmsgid;
    NB_FILEHANDLE_T *flyh;
    char *flyh_akey;
    sdfMemHandle_t *flymem;
    u32 d31_press_total;
    u32 d31_rebehansya;
    u32 d31_andahansya;
    u32 d31_kantuu;
};

struct nbSound_t {
    s16 exist;
    u16 id;
    s32 linkcnt;
    s32 motse_h;
    s32 negose_h;
};

struct nbActionStack_t {
    s32 type;
    s32 from;
    s32 to;
    s32 data;
};

struct nbCommSelProcessData_t {
    sdfMemHandle_t *mem;
    nbMainProcessData_t *data;
    nbActionProcessData_t *act;
    s8 nowstat;
    u8 nowtype;
    s32 drawtype;
    s32 drawcursor;
    s32 drawlisty;
    s32 nowcursor[6];
    s32 nowlisty[6];
    nbParty_t *my;
    nbParty_t *partytarget;
    u16 *commlist[6];
    s32 commcnt[6];
    s8 *commdisable[6];
    s32 cnt;
    f32 smritu;
    u32 animeflag;
    s32 ox;
    s32 oy;
    s32 oz;
    s32 alpha;
    s32 helpa;
    f32 ritu;
    s32 openwait;
};

struct nbDebugProcessData_t {
    nbMainProcessData_t *data;
    s32 seq;
    s32 nextseq;
    s32 side;
    s32 stockno;
    s32 formindex;
    nbFormation_t *form;
    s32 partyindex;
    nbParty_t *party;
    s32 hp;
    s32 mp;
    u32 bad;
};

struct nbEventProcessData_t {
    nbMainProcessData_t *data;
    s32 eventrid;
    s32 time;
    s32 seq;
    s32 seqtime;
    void *userdata;
    nbEventProcessData_t_usershutdownDelegate *usershutdown;
    fileHandle_t *file;
    NB_FILEHANDLE_T *pfile;
    sdfMemHandle_t *mem;
    s32 uniqueid;
};

struct nbHelpProcessData_t {
    s32 type;
    char *text1;
    char *text2;
    char *text3;
    s32 textframe;
    s32 textmax;
    void *texthandle;
    s32 textwidth;
    s32 nextwidth;
    u32 textcol;
    s32 wait_time;
    char *wait_text1;
    char *wait_text2;
    s32 msgid;
    s32 msgno;
    s32 reqmsgid;
    s32 reqmsgno;
    s32 alpha;
};

struct nbKoukaProcessData_t {
    nbMainProcessData_t *data;
    s32 packetcnt;
    nbKoukaPacket_t *first;
    nbKoukaPacket_t *last;
};

struct nbMakaProcessData_t {
    s32 stat;
    u32 oldmaka;
    s32 disp;
    s32 targetx;
    s32 targety;
    s32 basex;
    s32 basey;
    s32 type;
    f32 ritu;
    s32 offtime;
    s32 alpha;
};

struct nbNegoProcessData_t {
    nbMainProcessData_t *data;
    nbActionProcessData_t *actdata;
    u32 stat;
    s32 negotype;
    s32 waitframe;
    u32 nownegoid;
    s32 nownegophase;
    u32 nextnegoid;
    s32 nextkouhocnt;
    u32 nextkouho[8];
    s32 nowmsgid;
    s32 nowmsgno;
    s32 nowmes;
    s32 msgwndid;
    u32 msgwndcnt;
    s32 nowselect;
    u32 workid[8];
    s32 requesttype;
    s32 requestdata;
    s32 requesthpmp;
    s32 prevreqtype;
    s32 cnt6_36;
    s32 cnt6_37;
    s32 cnt6_58;
    s32 cnt6_66;
    s32 mes6_2;
    s32 mes6_25;
    s32 mes6_67;
    s32 flag1_6;
    s32 flag1_39;
    s32 historyindex;
    u32 history[14];
    s32 historymes[14];
    s32 endid;
    s32 endtype;
    s32 negoreqtype;
    u32 negoskillid;
    s32 aisyo;
    s32 aisyomes;
    s32 hojopartyindex;
    s32 hojoskillid;
    s32 hojoseikou;
    s32 hojoaisyo;
    s32 hojoaisyomes;
    s32 qtype;
    s32 qindex;
    datUnitWork_t *pwork;
    datUnitWork_t *ework;
    s32 pformindex;
    s32 eformindex;
    nbFormation_t *pform;
    nbFormation_t *eform;
    s32 ppartyindex;
    s32 epartyindex;
    nbParty_t *pparty;
    nbParty_t *eparty;
    s32 pkucyo;
    s32 ekucyo;
    s32 innen_id;
    s32 temp_param[4];
    s32 boupartyindex;
    s32 getmakka;
    s32 getitem;
    s32 getinfotype;
    s32 getinfomsg;
    s32 flowmsg[31];
    s32 questionmsg;
    s32 aisyomsg[31];
    s32 infomsg[31];
    s32 helpmsg;
    s32 helpmsg2;
    s32 innenmsg;
    s32 bossmsg;
    s32 selectcur;
};

struct nbTarSelProcessData_t {
    nbMainProcessData_t *data;
    nbActionProcessData_t *act;
    u8 stat;
    s8 ctype;
    u8 crule;
    u8 carea;
    u8 nowcarea;
    s8 nowno;
    s8 nowform;
    s16 partyindex;
    s8 friendcnt;
    s8 enemycnt;
    s8 friendno[12];
    s8 enemyno[12];
    s32 jyokyotime;
    s32 time;
    s32 alpha_a;
    s32 alpha_b;
    f32 scale_a;
    f32 scale_b;
};

struct bpHeader_t {
    u16 FileType;
    u16 FileFormat;
    s16 UserID;
    s32 FileSize;
    char *MagicCode;
    s32 ExpandSize;
    s32 TypeTableCount;
    s32 Version;
    s32 Reserve2;
    s32 Reserve3;
};

struct bpTypeTable_t {
    s32 Type;
    s32 ItemSize;
    s32 ItemCount;
    s32 ItemAddress;
};
