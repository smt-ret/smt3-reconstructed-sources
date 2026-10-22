#pragma once
#include "types.h"

typedef enum {
    PARAM_POWER = 0,
    PARAM_INTELI = 1,
    PARAM_MAGIC = 2,
    PARAM_STAMINA = 3,
    PARAM_QUICK = 4,
    PARAM_LUCK = 5,
    PARAM_MAX = 6,
} PARAM_STS;

typedef enum {
    ATTR_NON = -1,
    ATTR_BUTURI = 0,
    ATTR_KAEN = 1,
    ATTR_HYOKETU = 2,
    ATTR_DENGEKI = 3,
    ATTR_SHOGEKI = 4,
    ATTR_BANNO = 5,
    ATTR_HAMA = 6,
    ATTR_JYUSATU = 7,
    ATTR_MARYOKU = 8,
    ATTR_SINKEI = 9,
    ATTR_SEISIN = 10,
    ATTR_JIBAKU = 11,
    ATTR_NEGO = 12,
    ATTR_RECOVERY = 13,
    ATTR_HOJO = 14,
    ATTR_SPECIAL = 15,
    ATTR_MAX = 16,
} ATTR_ATK;

typedef enum {
    FORM_MAGIC = 1,
    FORM_BREATH = 2,
    FORM_WING = 4,
    FORM_EYE = 8,
    FORM_DASH = 16,
    FORM_BITE = 32,
    FORM_CLAW = 64,
    FORM_NEEDLE = 128,
    FORM_WEAPON = 256,
    FORM_PRIVATE = 512,
    FORM_OTOME = 1024,
    FORM_NEGO = 2048,
} FROM_M;

typedef enum {
    QUES_NORMAL = 0,
    QUES_YOSUGA = 1,
    QUES_MUSUBI = 2,
    QUES_SIJIMA = 3,
    QUES_MAX = 4,
} QUES_TYPE;

typedef enum {
    DV_BOY = 0,
    DV_GIRL = 1,
    DV_LADY = 2,
    DV_WITCH = 3,
    DV_HEEHAW = 4,
    DV_BEAST = 5,
    DV_GENTLE = 6,
    DV_PUNK = 7,
    DV_OLDMAN = 8,
    DV_OLDWOMAN = 9,
    DV_LORD = 10,
    DV_MANEKATA = 11,
    DV_HEROINE = 12,
    DV_SAMURAI = 13,
    DV_THING = 14,
    DV_YOJU = 15,
    DV_KUCYO_DANTE = 16,
    DV_KUCYO_MATADO = 17,
    DV_KUCYO_HELLSA = 18,
    DV_KUCYO_DAISOU = 19,
    DV_KUCYO_WRIDER = 20,
    DV_KUCYO_RRIDER = 21,
    DV_KUCYO_BRIDER = 22,
    DV_KUCYO_PRIDER = 23,
    DV_KUCYO_MOTHER = 24,
    DV_KUCYO_TORANP = 25,
    DV_KUCYO_BERUZE = 26,
    DV_KUCYO_METATO = 27,
    DV_KUCYO_HUTOMI = 28,
    DV_KUCYO_SAKAHA = 29,
    DV_DEVIL = 30,
    DV_KUCYO_MAX = 31,
} DV_TALK_TYPE;

typedef enum {
    DV_TOKUBOU_NON = 0,
    DV_TOKUBOU_100 = 1,
    DV_TOKUBOU_0 = 2,
    DV_TOKUBOU_SET0 = 3,
} DV_TOKUBOU;

typedef enum {
    DV_HONBOU_OFF = 0,
    DV_HONBOU_ON = 1,
} DV_HONBOU;

typedef enum {
    DV_PRIVATE_SELECT_OFF = 0,
    DV_PRIVATE_SELECT_ON = 1,
} DV_PRIVATE_SELECT;

typedef enum {
    DV_MUKAN_OFF = 0,
    DV_MUKAN_ON = 1,
} DV_MUKAN;

typedef enum {
    DV_SENSEI_OFF = 0,
    DV_SENSEI_ON = 1,
} DV_SENSEI;

typedef enum {
    DV_INOTI_OFF = 0,
    DV_INOTI_ON = 1,
} DV_INOTI;

typedef enum {
    DV_BINJO_OFF = 0,
    DV_BINJO_ON = 1,
} DV_BINJO;

typedef enum {
    ATTACK = 0,
    SKILL = 1,
    ESCAPE = 2,
    WAIT = 3,
    NEGO = 4,
    ITEM = 5,
    SUMMON = 6,
    RETURN = 7,
    BADWAIT = 8,
    SKIP = 9,
    DAMAGE = 10,
} SU_COMM;

typedef enum {
    NON = 0,
    ROT = 1,
    DASH = 2,
    NEGODASH = 3,
    DASH_SINGLE = 4,
    DASH_GROUP = 5,
} UV_MV;

typedef enum {
    OFF = 0,
    ON = 1,
} UV_AUTOWAIT;

typedef enum {
    S = 0,
    M = 1,
    L = 2,
    LL = 3,
} UV_MODEL;

typedef enum {
    NON = 0,
    S = 1,
    M = 2,
    L = 3,
    LL = 4,
} UV_SHADOW;

typedef enum {
    NORM = 0,
    PAUSE = 1,
    OUT = 2,
    STOP = 3,
    MAX = 4,
} UV_END;

typedef enum {
    FROM_WAIT = 0,
    FROM_DMG = 1,
    FROM_BAD = 2,
    TO_WAIT = 3,
    TO_DMG = 4,
    TO_BAD = 5,
    MAX = 6,
} UV_HOKAN_FROM;

typedef enum {
    DV_AI_LV0 = 0,
    DV_AI_LV1 = 1,
    DV_AI_LV2 = 2,
} DV_AI_LV;

typedef enum {
    DV_HOJO_BATK_UP = 0,
    DV_HOJO_BATK_DOWN = 1,
    DV_HOJO_MATK_UP = 2,
    DV_HOJO_MATK_DOWN = 3,
    DV_HOJO_ESC_UP = 4,
    DV_HOJO_ESC_DOWN = 5,
    DV_HOJO_DEF_UP = 6,
    DV_HOJO_DEF_DOWN = 7,
    DV_HOJO_HIT_UP = 8,
    DV_HOJO_HIT_DOWN = 9,
    DV_HOJO_DEKAJA = 10,
    DV_HOJO_HYOKETU_OFF = 11,
    DV_HOJO_KAEN_OFF = 12,
    DV_HOJO_JYUSATU_OFF = 13,
    DV_HOJO_HAMA_OFF = 14,
    DV_HOJO_MAGIC_REF = 15,
    DV_HOJO_BUTURI_REF = 16,
    DV_HOJO_ATKx2 = 17,
} DV_HOJO;

typedef enum {
    DV_AI_CHK_MYHP = 1,
    DV_AI_CHK_FRHP = 2,
    DV_AI_CHK_DMGCNT = 3,
    DV_AI_CHK_CHKCNT = 4,
    DV_AI_CHK_FRCNT = 5,
    DV_AI_CHK_ENCNT = 6,
    DV_AI_CHK_MYBAD = 7,
    DV_AI_CHK_FRBAD = 8,
    DV_AI_CHK_ENBAD = 9,
    DV_AI_CHK_ENALLBAD = 10,
    DV_AI_CHK_ENID = 11,
    DV_AI_CHK_FRID = 12,
    DV_AI_CHK_ENHOJO = 13,
    DV_AI_CHK_FRHOJO = 14,
    DV_AI_CHK_BA = 15,
    DV_AI_CHK_ENLIGHT = 16,
    DV_AI_CHK_ENDARK = 17,
    DV_AI_CHK_POW = 18,
    DV_AI_CHK_PLV = 19,
    DV_AI_CHK_PPARTYLV = 20,
    DV_AI_CHK_CHKCNT_B = 21,
    DV_AI_CHK_TURN = 22,
    DV_AI_CHK_SENSEI = 23,
    DV_AI_CHK_MYMP = 24,
    DV_AI_CHK_ENHOJOMAX = 25,
    DV_AI_CHK_FRHOJOMAX = 26,
    DV_AI_CHK_ENHAMAMHK = 27,
    DV_AI_CHK_SKILLNOMP = 28,
    DV_AI_CHK_CNT = 29,
} DV_AI_CHK;

typedef enum {
    TAR_CODE_AI = 0,
    TAR_CODE_LIFEMIN = 1,
    TAR_CODE_BAD = 2,
    TAR_CODE_ID = 3,
    TAR_CODE_LIGHT = 4,
    TAR_CODE_DARK = 5,
    TAR_CODE_PLAYER = 6,
    TAR_CODE_JOKEN = 7,
    TAR_CODE_RND = 8,
    TAR_CODE_BAARLV = 9,
    TAR_CODE_LVMIN = 10,
} TAR_CODE;

typedef enum {
    BTL_SND_TYPE_NORMAL1 = 1,
    BTL_SND_TYPE_NORMAL2 = 2,
    BTL_SND_TYPE_NORMAL3 = 3,
    BTL_SND_TYPE_NORMAL4 = 4,
    BTL_SND_TYPE_BOSS1 = 5,
    BTL_SND_TYPE_BOSS2 = 6,
    BTL_SND_TYPE_BOSS3 = 7,
    BTL_SND_TYPE_BOSS4 = 8,
    BTL_SND_TYPE_BOSS5 = 9,
    BTL_SND_TYPE_BOSS6 = 10,
    BTL_SND_TYPE_BOSS7 = 11,
    BTL_SND_TYPE_BOSS8 = 12,
    BTL_SND_TYPE_BOSS9 = 13,
    BTL_SND_TYPE_BOSS10 = 14,
    BTL_SND_TYPE_NORMAL5 = 15,
} BTL_SND_TYPE;

typedef enum {
    ENC_BA_OFF = -1,
    ENC_BA_ON = 0,
    ENC_BA_100 = 1,
} ENC_BA;

typedef enum {
    ENC_ESC_ON = 0,
    ENC_ESC_OFF = 1,
} ENC_ESC;

typedef enum {
    ENC_FORMATION_NORMAL = 0,
    ENC_FORMATION_ARSIEL = 1,
    ENC_FORMATION_GIRIME = 2,
    ENC_FORMATION_MARA = 3,
    ENC_FORMATION_3SISTER = 4,
    ENC_FORMATION_ALBION = 5,
    ENC_FORMATION_TENSI = 6,
    ENC_FORMATION_BAAL = 7,
    ENC_FORMATION_NET = 8,
    ENC_FORMATION_ARI = 9,
    ENC_FORMATION_KAGU = 10,
    ENC_FORMATION_META = 11,
    ENC_FORMATION_BERU = 12,
    ENC_FORMATION_LUSI = 13,
} ENC_FORMATION;

typedef enum {
    SK_TYPE_NON = -1,
    SK_TYPE_NORMAL = 0,
    SK_TYPE_SPECIAL = 1,
    SK_TYPE_TALK = 2,
} SK_TYPE;

typedef enum {
    NSK_FLAG_BOSSMUKOU = 1,
    NSK_FLAG_IKKIUSELESS = 2,
    NSK_FLAG_COSTMUSI = 4,
    NSK_FLAG_DEAD = 8,
} NSK_FLAG;

typedef enum {
    NSK_USE_FIELD = 1,
    NSK_USE_BATTLE = 2,
} NSK_USE;

typedef enum {
    NSK_BUTURI = 0,
    NSK_MAGIC = 1,
} NSK;

typedef enum {
    NSK_COST_NON = 0,
    NSK_COST_HP = 1,
    NSK_COST_MP = 2,
} NSK_COST;

typedef enum {
    NSK_TARGET_TYPE_SINGLE = 0,
    NSK_TARGET_TYPE_GROUP = 1,
    NSK_TARGET_TYPE_ALL = 2,
    NSK_TARGET_TYPE_NON = 3,
} NSK_TARGET_TYPE;

typedef enum {
    NSK_TARGET_AREA_FRIEND = 1,
    NSK_TARGET_AREA_ENEMY = 2,
    NSK_TARGET_AREA_PARTY = 4,
    NSK_TARGET_AREA_BPARTY = 8,
} NSK_TARGET_AREA;

typedef enum {
    NSK_TARGET_RULE_I = 1,
    NSK_TARGET_RULE_OTHER = 2,
    NSK_TARGET_RULE_EMPTY = 4,
    NSK_TARGET_RULE_EMPTYONLY = 8,
} NSK_TARGET_RULE;

typedef enum {
    NSK_TARGET_RAND_OFF = 0,
    NSK_TARGET_RAND_ON = 1,
} NSK_TARGET_RAND;

typedef enum {
    NSK_HIT_TYPE_ALL = 1,
    NSK_HIT_TYPE_DARK = 2,
    NSK_HIT_TYPE_NEUTRAL = 4,
    NSK_HIT_TYPE_LIGHT = 8,
} NSK_HIT_TYPE;

typedef enum {
    NSK_HIT_VERYHARD = 10,
    NSK_HIT_HARD = 50,
    NSK_HIT_NORMAL = 100,
    NSK_HIT_EASY = 150,
    NSK_HIT_VERYEASY = 200,
    NSK_HIT_100 = 255,
} NSK_HIT;

typedef enum {
    NSK_BAD_VERYHARD3 = 5,
    NSK_BAD_VERYHARD2 = 15,
    NSK_BAD_VERYHARD = 30,
    NSK_BAD_HARD = 40,
    NSK_BAD_NORMAL = 50,
    NSK_BAD_EASY = 60,
    NSK_BAD_VERYEASY = 70,
    NSK_BAD_VERY70 = 80,
    NSK_BAD_VERY80 = 90,
    NSK_BAD_100 = 255,
} NSK_BAD;

typedef enum {
    NSK_HANEI_TYPE_NON = 0,
    NSK_HANEI_TYPE_DMG = 1,
    NSK_HANEI_TYPE_REC = 2,
    NSK_HANEI_TYPE_SET = 3,
    NSK_HANEI_TYPE_DOWN = 4,
    NSK_HANEI_TYPE_UP = 5,
    NSK_HANEI_TYPE_MAXHPDMG = 6,
    NSK_HANEI_TYPE_MAXHPREC = 7,
    NSK_HANEI_TYPE_PERDMG = 8,
    NSK_HANEI_TYPE_PERREC = 9,
    NSK_HANEI_TYPE_MAXPERDMG = 10,
    NSK_HANEI_TYPE_MAXPERREC = 11,
    NSK_HANEI_TYPE_DRAIN = 12,
    NSK_HANEI_TYPE_DRAIN2 = 13,
    NSK_HANEI_TYPE_DMGDIV = 14,
    NSK_HANEI_TYPE_RNDUP = 15,
} NSK_HANEI_TYPE;

typedef enum {
    NSK_BAD_TYPE_NON = 0,
    NSK_BAD_TYPE_ON = 1,
    NSK_BAD_TYPE_OFF = 2,
    NSK_BAD_TYPE_RNDON = 3,
} NSK_BAD_TYPE;

typedef enum {
    NSK_HOJO_BATK_UP = 1,
    NSK_HOJO_BATK_DOWN = 2,
    NSK_HOJO_MATK_UP = 4,
    NSK_HOJO_MATK_DOWN = 8,
    NSK_HOJO_ESC_UP = 16,
    NSK_HOJO_ESC_DOWN = 32,
    NSK_HOJO_DEF_UP = 64,
    NSK_HOJO_DEF_DOWN = 128,
    NSK_HOJO_HIT_UP = 256,
    NSK_HOJO_HIT_DOWN = 512,
    NSK_HOJO_DEKAJA = 1024,
    NSK_HOJO_HYOKETU_OFF = 4096,
    NSK_HOJO_KAEN_OFF = 8192,
    NSK_HOJO_JYUSATU_OFF = 16384,
    NSK_HOJO_HAMA_OFF = 32768,
    NSK_HOJO_MAGIC_REF = 65536,
    NSK_HOJO_BUTURI_REF = 131072,
    NSK_HOJO_DEKUNDA = 262144,
    NSK_HOJO_ATKx2 = 16777216,
} NSK_HOJO;

typedef enum {
    NSK_PROG_NON = 0,
    NSK_PROG_ANALYZE = 1,
    NSK_PROG_SUMMON = 2,
    NSK_PROG_ENEMYSUMMON = 3,
    NSK_PROG_ESCAPE = 4,
    NSK_PROG_MAKA = 5,
    NSK_PROG_SLEEPONLY = 6,
    NSK_PROG_ENEMYESCAPE = 7,
    NSK_PROG_ESUTOMA = 8,
    NSK_PROG_RIBERAMA = 9,
    NSK_PROG_RIFUTOMA = 10,
    NSK_PROG_RAITOMA = 11,
    NSK_PROG_AURORA = 12,
    NSK_PROG_PRESS = 13,
    NSK_PROG_FLARECHARGE = 14,
    NSK_PROG_POISONONLY = 15,
} NSK_PROG;

typedef enum {
    NSK_DEAD_NORMAL = 0,
    NSK_DEAD_STONE = 1,
    NSK_DEAD_EVENT = 2,
} NSK_DEAD;

typedef enum {
    NSK_ANIME_NORMAL = 0,
    NSK_ANIME_DELAY5 = 1,
    NSK_ANIME_DELAY8 = 2,
    NSK_ANIME_DELAY10 = 3,
    NSK_ANIME_LEFT1 = 4,
    NSK_ANIME_LEFT5 = 5,
    NSK_ANIME_LEFT8 = 6,
    NSK_ANIME_LEFT10 = 7,
    NSK_ANIME_RIGHT1 = 8,
    NSK_ANIME_RIGHT5 = 9,
    NSK_ANIME_RIGHT8 = 10,
    NSK_ANIME_RIGHT10 = 11,
    NSK_ANIME_RAND1 = 12,
    NSK_ANIME_RAND5 = 13,
    NSK_ANIME_RAND8 = 14,
    NSK_ANIME_RAND10 = 15,
} NSK_ANIME;

typedef enum {
    NSK_HATUDO_NON = 0,
    NSK_HATUDO_NORMAL = 1,
    NSK_HATUDO_HANYOU01 = 2,
    NSK_HATUDO_AGI01 = 3,
    NSK_HATUDO_BUFU01 = 4,
    NSK_HATUDO_JIO01 = 5,
    NSK_HATUDO_ZAN01 = 6,
    NSK_HATUDO_MEGIDO01 = 7,
    NSK_HATUDO_HAMA01 = 8,
    NSK_HATUDO_MUDO01 = 9,
    NSK_HATUDO_BREATH01 = 10,
    NSK_HATUDO_SUMMON = 11,
    NSK_HATUDO_RETURN = 12,
    NSK_HATUDO_BSARI1 = 13,
    NSK_HATUDO_BSARI2 = 14,
    NSK_HATUDO_BSNET1 = 15,
    NSK_HATUDO_BSNET2 = 16,
    NSK_HATUDO_BSKAGU1 = 17,
    NSK_HATUDO_BSKAGU2 = 18,
    NSK_HATUDO_KEN = 19,
    NSK_HATUDO_BSNET1_A = 20,
    NSK_HATUDO_BSNET2_A = 21,
    NSK_HATUDO_BSMETA = 22,
    NSK_HATUDO_BSBERU = 23,
    NSK_HATUDO_BSLUSI = 24,
    NSK_HATUDO_MAX = 25,
} NSK_HATUDO;

typedef enum {
    TSK_TYPE_NAKAMA = 0,
    TSK_TYPE_KINPIN = 1,
    TSK_TYPE_STONE = 2,
    TSK_TYPE_BUTUBUTU = 3,
    TSK_TYPE_MAKKA = 4,
    TSK_TYPE_KAKE = 5,
    TSK_TYPE_INFO = 6,
    TSK_TYPE_HOJO = 7,
} TSK_TYPE;

typedef enum {
    NEGO_REQ_ITEM_RITU = 0,
    NEGO_REQ_MAKKA_RITU = 1,
    NEGO_REQ_QUES_RITU = 2,
    NEGO_REQ_DRAIN_RITU = 3,
    NEGO_REQ_FIGHT_RITU = 4,
    NEGO_REQ_MAX = 5,
} NEGO_REQ;

typedef enum {
    NEGO_QUES_NORMAL = 0,
    NEGO_QUES_YOSUGA = 1,
    NEGO_QUES_MUSUBI = 2,
    NEGO_QUES_SIJIMA = 3,
    NEGO_QUES_MAX = 4,
} NEGO_QUES;

typedef enum {
    INNEN_RESULT_ITEM = 0,
    INNEN_RESULT_FIGHT = 1,
} INNEN_RESULT;

typedef enum {
    DAT_GETKOUKA_HP = 0,
    DAT_GETKOUKA_MP = 1,
} DAT_GETKOUKA;

typedef struct InnenMotionInfo_s InnenMotionInfo_s;
typedef struct datBossPress_t datBossPress_t;
typedef struct datDevilAIChk_s datDevilAIChk_s;
typedef struct datDevilAITbl_s datDevilAITbl_s;
typedef struct datDevilAI_s datDevilAI_s;
typedef struct datDevilFormat_s datDevilFormat_s;
typedef struct datDevilHistory_s datDevilHistory_s;
typedef struct datDevilNegoFormat_s datDevilNegoFormat_s;
typedef struct datEncountFld_t datEncountFld_t;
typedef struct datEncountPack_s datEncountPack_s;
typedef struct datEncountRitu_s datEncountRitu_s;
typedef struct datEncountTbl_s datEncountTbl_s;
typedef struct datEncount_s datEncount_s;
typedef struct datInfoSelectTable_s datInfoSelectTable_s;
typedef struct datInnenNegoTable_s datInnenNegoTable_s;
typedef struct datItem_s datItem_s;
typedef struct datNegoAisyo_s datNegoAisyo_s;
typedef struct datNegoNormalQuesInfo_s datNegoNormalQuesInfo_s;
typedef struct datNegoPresent_s datNegoPresent_s;
typedef struct datNegoSkill_s datNegoSkill_s;
typedef struct datNormalSkillVisual_s datNormalSkillVisual_s;
typedef struct datNormalSkill_s datNormalSkill_s;
typedef struct datSkill_s datSkill_s;
typedef struct datSpecialSkill_s datSpecialSkill_s;
typedef struct datTakaraSagasiI_s datTakaraSagasiI_s;
typedef struct datTakaraSagasiT_s datTakaraSagasiT_s;
typedef struct datTakaraSagasi_s datTakaraSagasi_s;
typedef struct datUnitMotion_s datUnitMotion_s;
typedef struct datUnitVisual_s datUnitVisual_s;
typedef struct datUnitWork_s datUnitWork_s;

struct datUnitWork_s {
    u32 flag;
    u16 id;
    u16 hp;
    u16 maxhp;
    u16 mp;
    u16 maxmp;
    u16 badstatus;
    u32 exp;
    u16 level;
    s8 param[6];
    s8 skillparam[6];
    u16 uniqueid;
    u16 reserve1;
    u16 reserve2;
    u16 namecode[8];
    s32 skillcnt;
    s32 skill[24];
    s16 nowcommand;
    u16 nowindex;
    s16 nowtarea;
    s16 nowtform;
    s16 prevcommand;
    u16 previndex;
    s16 prevtarea;
    s16 prevtform;
    s8 mitamaparam[6];
    s8 levelupparam[6];
    u16 keisyoskill[24];
    u8 keiattr[24];
    u16 hensinmae;
    u16 getdevilhearts[4];
    u32 hensinmaeexp;
    u16 fullnamecode[8];
};

struct datDevilFormat_s {
    u32 flag;
    u8 race;
    u8 level;
    u16 hp;
    u16 maxhp;
    u16 mp;
    u16 maxmp;
    s16 aisyoid;
    s8 param[6];
    u16 skill[8];
    s16 keisyotype;
    u16 keisyoform;
    u16 dropmakka;
    u16 dropexp;
    u8 dropitem[2];
    u8 droppoint[2];
    u16 specialbit;
    u8 specialitem;
    u8 specialpoint;
    u8 hougyokupoint;
    u8 masekipoint;
    s8 attackattr;
    u8 attackcnt;
    u8 attackinterval;
    u8 reserve1;
};

struct datDevilAI_s {
    u16 scriptid;
    u16 ailevel;
    datDevilAIChk_s *aichk;
    datDevilAITbl_s **aitable;
    u16 deadscriptid;
    u16 deadeventno;
};

struct datDevilNegoFormat_s {
    u32 kucyo;
    u32 tokucyo;
    u8 tokuboutype;
    u8 honboutype;
    u8 fighttype;
    u8 reqtype;
    u8 tuikareqtype;
    u8 privatesel;
    u8 privateselindex;
    u8 senseitype;
    u8 inotitype;
    u8 binjotype;
    u16 mukantype;
    u16 mukanindex;
    datNegoPresent_s *itema;
    datNegoPresent_s *itemb;
    datNegoPresent_s *stone;
};

struct datEncount_s {
    s8 backattack;
    s8 esc;
    u8 item;
    u8 itemcnt;
    u8 formationtype;
    u16 *devil;
    u16 stageid;
    u16 areaid;
    u16 flag;
    u8 maxparty;
    u8 maxcall;
    u16 btlsound;
};

struct datEncountPack_s {
    u16 stageid;
    u16 areaid;
    u16 btlsound;
    u16 moonchk;
    u16 table2;
    u16 eventbit1;
    u16 eventbit2;
    u8 *table1;
    datEncountTbl_s *enctable;
};

struct datDevilAIChk_s {
    u32 check[2];
    u32 table;
};

struct datDevilAITbl_s {
    u16 ritu;
    u16 skill;
    u32 target;
};

struct datNegoPresent_s {
    u8 ritu;
    u8 item;
};

struct datEncountTbl_s {
    s32 normalritu;
    datEncountRitu_s *ritu;
};

struct datEncountRitu_s {
    u16 encountid;
    u16 ritu;
    u8 sensei;
    u8 renzokuritu;
    u16 renzokuindex;
};

struct datBossPress_t {
    s32 flag;
    s32 flag2;
    s32 encid;
    s32 dbest;
};

struct datUnitVisual_s {
    sdfVector4_t center;
    f32 formsize;
    f32 formheight;
    f32 formscale;
    f32 oneshotr;
    f32 allshotr;
    u16 modelsize;
    u16 shadowsize;
    u16 badframe;
    u16 autowait;
    datUnitMotion_s *motion;
    u32 reserve1;
    u32 reserve2;
    u32 reserve3;
};

struct datUnitMotion_s {
    u32 motion_no;
    s16 movetype;
    u16 actframe;
    s32 se_no;
    s32 se_endtype;
    s32 se_endframe;
    f32 motionsp;
    f32 atarisize;
    f32 movey;
    f32 movez;
    s16 bframe;
    s16 hframe;
};

struct datEncountFld_t {
    s32 flag;
    s16 *Encount1;
    s16 *Encount2;
};

struct datTakaraSagasi_s {
    u32 flag;
    datTakaraSagasiT_s *tbl[4];
};

struct datItem_s {
    u8 use;
    u8 flag;
    u16 skillid;
    u32 price;
};

struct datTakaraSagasiT_s {
    u32 flag;
    datTakaraSagasiI_s *itemtbl[8];
};

struct datTakaraSagasiI_s {
    u16 item;
    u16 par;
};

struct datNegoSkill_s {
    u32 type;
    u8 *rate;
    datNegoAisyo_s *killeraisyo;
    datNegoAisyo_s *ngaisyo;
};

struct datNegoAisyo_s {
    u32 from;
    u32 to;
    s32 mes;
};

struct datInnenNegoTable_s {
    s16 check;
    u16 id1;
    u16 id2;
    u16 result;
    u16 **item;
    u16 mainmes;
    u16 mescnt;
    u16 winmes;
    u16 losemes;
    u16 fullmes;
    InnenMotionInfo_s *innen_motion[3];
};

struct datInfoSelectTable_s {
    s16 *flagcheck;
    s16 *fieldno;
};

struct datNegoNormalQuesInfo_s {
    u16 type;
    u8 ritu1;
    u8 ritu2;
};

struct InnenMotionInfo_s {
    s16 pageno;
    s16 player_motion;
    s16 doui;
};

struct datNormalSkill_s {
    u8 flag;
    u8 use;
    u8 koukatype;
    u8 costtype;
    u16 cost;
    u16 costbase;
    u8 targettype;
    u8 targetarea;
    u8 targetrule;
    u8 targetrandom;
    u16 untargetbadstat;
    u16 targetprog;
    u8 hittype;
    u8 hitlevel;
    u16 hitprog;
    u8 targetcntmin;
    u8 targetcntmax;
    u16 hptype;
    s16 hpn;
    u16 mptype;
    s16 mpn;
    s16 hpbase;
    s16 mpbase;
    u16 minus;
    u8 badtype;
    u8 badlevel;
    u16 basstatus;
    u32 hojotype;
    s8 hojopoint;
    u8 deadtype;
    u32 program;
    s16 criticalpoint;
    s16 failpoint;
    s16 magicbase;
    s16 magiclimit;
};

struct datNormalSkillVisual_s {
    u8 motion;
    u8 animetype;
    u8 hatudo;
    u8 bedno;
};

struct datSkill_s {
    s8 skillattr;
    s8 type;
    s16 index;
    u16 keisyoform;
    s8 capacity;
    u8 flag;
};

struct datSpecialSkill_s {
    s16 n;
    s16 m;
    s16 a;
    s16 b;
};

struct datDevilHistory_s {
    u8 flag;
    u8 killcnt;
};

typedef struct datDevilAI_s datDevilAI_t;
typedef struct datDevilFormat_s datDevilFormat_t;
typedef struct datDevilNegoFormat_s datDevilNegoFormat_t;
typedef struct datEncountPack_s datEncountPack_t;
typedef struct datEncount_s datEncount_t;
typedef struct datInfoSelectTable_s datInfoSelectTable_t;
typedef struct datInnenNegoTable_s datInnenNegoTable_t;
typedef struct datItem_s datItem_t;
typedef struct datNegoNormalQuesInfo_s datNegoNormalQuesInfo_t;
typedef struct datNegoSkill_s datNegoSkill_t;
typedef struct datNormalSkillVisual_s datNormalSkillVisual_t;
typedef struct datNormalSkill_s datNormalSkill_t;
typedef struct datSkill_s datSkill_t;
typedef struct datSpecialSkill_s datSpecialSkill_t;
typedef struct datTakaraSagasi_s datTakaraSagasi_t;
typedef struct datUnitVisual_s datUnitVisual_t;
typedef struct datUnitWork_s datUnitWork_t;
