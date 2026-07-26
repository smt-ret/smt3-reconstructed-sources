#pragma once
#include "types.h"

typedef enum {
    ADDPOINT = 0,
    SKPOWERUP = 1,
    POISON = 2,
    PALYZE = 3,
    CURSE = 4,
    RECOVER = 5,
    RECOVER_PLAYER = 6,
    NONE = 7,
    MAX = 8,
} FCL_HEARTS_EVT;

typedef enum {
    RST_EVOACT_BUSY = 0,
    RST_EVOACT_END = 1,
} RST_EVOACT;

typedef enum {
    LEVUP = 0,
    GIFT = 1,
    SKILLPUP = 2,
    SKILLPUP_NO = 3,
    GIFT_NO = 4,
    TAKEAWAY = 5,
    TAKEAWAY_NO = 6,
    MAX = 7,
} RST_TYPE_MOTION;

typedef enum {
    SINGLE = 0,
    LOOP = 1,
    CANCEL = 2,
} RST_MODE_MOTION;

typedef enum {
    PLAYER_LEVELUP = 0,
    PLAYER_DH = 1,
    PLAYER_DH_EVENT_INIT = 2,
    PLAYER_DH_EVENT = 3,
    PLAYER_DH_MASTER_INIT = 4,
    PLAYER_DH_MASTER = 5,
    DEVIL_LEVELUP = 6,
    DEVIL_DEFSKILL_INIT = 7,
    DEVIL_DEFSKILL = 8,
    DEVIL_POWERUP_INIT = 9,
    DEVIL_POWERUP = 10,
    DEVIL_GIFT_INIT = 11,
    DEVIL_GIFT_INIT2 = 12,
    DEVIL_GIFT = 13,
    DEVIL_TAKEAWAY_INIT = 14,
    DEVIL_TAKEAWAY = 15,
    DEVIL_EVO_INIT = 16,
    DEVIL_EVO = 17,
    DEVIL_EVO_AT = 18,
    EXIT = 19,
    DEVIL_EVO_ACT = 20,
    DESTROY_SKILL = 21,
    DESTROY_CFM = 22,
    NAME_ENT = 23,
    CFM = 24,
    DEVIL_EVO_WAIT = 25,
} RST_SEQ;

typedef enum {
    ST_EVT_NO = 0,
    ST_EVT_SK = 1,
    ST_EVT_RM = 2,
    ST_EVT_DH = 3,
    ST_EVT_NN = 4,
    ST_EVT_CH = 5,
    ST_EVT_CHSK = 6,
    ST_EVT_AT = 7,
    ST_EVT_MAX = 8,
} ST_EVT;

typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct fclEvoDevilParam_t fclEvoDevilParam_t;
typedef struct fclEvoNeedFlag_t fclEvoNeedFlag_t;
typedef struct fclEvoNeedSkill_t fclEvoNeedSkill_t;
typedef struct fclGiftHearts_t fclGiftHearts_t;
typedef struct fclGiftItem_t fclGiftItem_t;
typedef struct fclHeartsSkill_t fclHeartsSkill_t;
typedef struct fclHeartsSplt_t fclHeartsSplt_t;
typedef struct fclHearts_t fclHearts_t;
typedef struct fclKeisyoSkillLevel_t fclKeisyoSkillLevel_t;
typedef struct fclSkillParam_t fclSkillParam_t;
typedef struct fclSkill_t fclSkill_t;
typedef struct fclTensiChange_t fclTensiChange_t;
typedef struct rstData_t rstData_t;
typedef struct rstMotionTbl_t rstMotionTbl_t;
typedef struct rstSkillInfo_t rstSkillInfo_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct rstData_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    s16 AsignParamMax;
    s16 AsignParam;
    s16 StartLevel;
    s16 LevelUpCnt;
    fclSkillParam_t pEvent[UNKNOWN_ARRAY_SIZE];
    s8 EventNums;
    s8 EventOfs;
    u16 EventParam;
    u16 GetHeartsSkill;
    s8 RecoverFlag;
    s8 HeartsSkFlag;
    s8 HeartsSkillResult;
    s8 HeartsEventMode;
    u16 HeartsEventData;
    s8 DefSkillResult;
    datUnitWork_t *pTargetList[16];
    s8 TargetCnt;
    s8 TargetPos;
    s8 TargetIndex;
    s8 PUpSkillResult;
    s8 PUpSkillIndex;
    u16 PUpSkillID;
    s32 EvoActFrame;
    s8 EvoActFlag;
    s8 EvoActStatFlag;
    s8 EvoFlag;
    datUnitWork_t *EvoDevil;
    datUnitWork_t *pCurrentStock;
    datUnitWork_t *WorkStock;
    cmpCursorInfo_t *ParamCursor;
    s8 GiftType;
    u16 GiftItemID;
    u8 GiftMesType;
    s8 GiftStep;
    s8 Flag;
    s8 ParamOfs[6];
    cmpCursorInfo_t *SkillCursor;
    u8 StatAlpha;
    s8 MotionReq;
    s8 MotionReqMode;
    f32 MotionReqBeforeFrame;
    f32 MotionReqAfterFrame;
    u16 SelectSkillID;
    s32 PanelEffID;
    sdfMemHandle_t *ScriptMH;
    void *pScriptData;
    sdfMemHandle_t *MessageMH;
    u8 pMessage[UNKNOWN_ARRAY_SIZE];
    s32 MessageWait;
    sdfTexHandle_t *TexHandle[1];
    u32 BgTimer;
    u32 EvoBgFade;
};

struct fclSkillParam_t {
    u8 TargetLevel;
    u8 Type;
    u16 Param;
};

struct fclEvoDevilParam_t {
    u16 DevilID;
    u16 MaxHP;
    u16 MaxMP;
    s8 Param[UNKNOWN_ARRAY_SIZE];
};

struct fclEvoNeedFlag_t {
    u16 DevilID;
    u16 EventFlag;
};

struct fclEvoNeedSkill_t {
    u16 DevilID;
    u16 SkillID;
};

struct fclGiftHearts_t {
    u16 DevilID;
    u8 HeartsID;
};

struct fclGiftItem_t {
    u16 ID;
    u16 Rate;
    s8 LevelLimit;
    s8 NumsLimit;
};

struct fclHearts_t {
    u8 Flag;
    s16 AisyoID;
    s16 MasterAisyoID;
    s8 GrowParamTbl[UNKNOWN_ARRAY_SIZE];
    s8 MasterGrowParamTbl[UNKNOWN_ARRAY_SIZE];
    s8 AutoAsignParamTbl[UNKNOWN_ARRAY_SIZE];
    fclHeartsSplt_t *Split;
    fclHeartsSkill_t Skill[UNKNOWN_ARRAY_SIZE];
    u8 Event[UNKNOWN_ARRAY_SIZE];
};

struct fclHeartsSplt_t {
    u8 TargetLevel;
    u8 HeartsID;
};

struct fclHeartsSkill_t {
    u8 TargetLevel;
    u16 ID;
};

struct fclKeisyoSkillLevel_t {
    u16 SkillID;
    u8 Level;
};

struct rstMotionTbl_t {
    u8 MotionNo;
    u8 BeforeFrame;
    u8 AfterFrame;
};

struct fclSkill_t {
    s8 GrowParamTbl[UNKNOWN_ARRAY_SIZE];
    fclSkillParam_t Event[UNKNOWN_ARRAY_SIZE];
};

struct fclTensiChange_t {
    u16 FirstID;
    u16 LastID;
    u16 ChangeID;
};

struct rstSkillInfo_t {
    s8 SkillCnt;
    u8 TargetLevel[24];
    u16 SkillID[24];
};
