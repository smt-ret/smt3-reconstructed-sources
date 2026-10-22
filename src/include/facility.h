#pragma once
#include "types.h"

typedef enum {
    CMB_ACTBGM_END = 0,
    CMB_ACTBGM_START = 1,
} CMB_ACTBGM;

typedef enum {
    CMB_ACTSE_END = 0,
    CMB_ACTSE_START = 1,
} CMB_ACTSE;

typedef enum {
    CMB_ACTSE_TYPE_NORMAL = 0,
    CMB_ACTSE_TYPE_ACCIDENT = 1,
} CMB_ACTSE_TYPE;

typedef enum {
    PARAM_TYPE_NONE = 0,
    PARAM_TYPE_PWR = 1,
    PARAM_TYPE_INT = 2,
    PARAM_TYPE_MGC = 3,
    PARAM_TYPE_DEF = 4,
    PARAM_TYPE_SPD = 5,
    PARAM_TYPE_LUK = 6,
    PARAM_TYPE_HP = 7,
    PARAM_TYPE_MP = 8,
} PARAM_TYPE;

typedef enum {
    CMB_RANK_NONE = 0,
    CMB_RANK_UP = 1,
    CMB_RANK_DOWN = 2,
} CMB_RANK;

typedef enum {
    CMB_RESULT_FAIL = 0,
    CMB_RESULT_NORMAL = 1,
    CMB_RESULT_POWUP = 2,
    CMB_RESULT_MITAMA = 3,
    CMB_RESULT_SEIREI = 4,
    CMB_RESULT_RANKUP = 5,
    CMB_RESULT_RANKDOWN = 6,
    CMB_RESULT_TOKUSYU = 7,
    CMB_RESULT_IKENIE = 8,
    CMB_RESULT_TOKUSYUIKENIE = 9,
    CMB_RESULT_ACCIDENT = 10,
    CMB_RESULT_ACCIDENT_EH = 11,
    CMB_RESULT_MANIN = 12,
} CMB_RESULT;

typedef enum {
    CMB_STAT_MOONFULL = 0,
    CMB_STAT_CURSE = 1,
    CMB_STAT_OTHER = 2,
} CMB_STAT;

typedef enum {
    CMB_SEQ_RO = 0,
    CMB_SEQ_CM = 1,
    CMB_SEQ_ZE = 2,
    CMB_SEQ_TL = 3,
    CMB_SEQ_EX = 4,
    CMB_SEQ_1ST = 5,
    CMB_SEQ_2ND = 6,
    CMB_SEQ_SAC_CFM = 7,
    CMB_SEQ_SAC = 8,
    CMB_SEQ_STA = 9,
    CMB_SEQ_STA2 = 10,
    CMB_SEQ_BID = 11,
    CMB_SEQ_DCI = 12,
    CMB_SEQ_ACC = 13,
    CMB_SEQ_ACT_WAIT = 14,
    CMB_SEQ_ACT = 15,
    CMB_SEQ_INT = 16,
    CMB_SEQ_ERR = 17,
    CMB_SEQ_MSG = 18,
    CMB_SEQ_END = 19,
    CMB_SEQ_MAX = 20,
} CMB_SEQ;

typedef enum {
    CMB_ERR_NONE = 0,
    CMB_ERR_DEVLEV = 1,
    CMB_ERR_DEVDBL = 2,
} CMB_ERR;

typedef enum {
    CMB_INFO_SEL1ST = 0,
    CMB_INFO_SEL2ND = 1,
    CMB_INFO_SELSAC = 2,
} CMB_INFO;

typedef enum {
    CMB_SEL1ST = 0,
    CMB_SEL2ND = 1,
    CMB_SELSAC = 2,
    CMB_SELBIR = 3,
    CMB_SELMAX = 4,
} CMB_SEL;

typedef enum {
    FCL_DBGMODE_COMBINE = 0,
    FCL_DBGMODE_TERMINAL = 1,
    FCL_DBGMODE_RAG = 2,
    FCL_DBGMODE_SHOP = 3,
} FCL_DBGMODE;

typedef enum {
    FCL_MSGSTAT_NONE = 0,
    FCL_MSGSTAT_DRAW = 1,
    FCL_MSGSTAT_LAST = 2,
    FCL_MSGSTAT_END = 3,
} FCL_MSGSTAT;

typedef enum {
    FCL_PROC_STOP = 0,
    FCL_PROC_BUSY = 1,
    FCL_PROC_TERM = 2,
} FCL_PROC;

typedef enum {
    FCL_STR_YES = 0,
    FCL_STR_NO = 1,
    FCL_STR_SYOJIKIN = 2,
    FCL_STR_SOUGAKU = 3,
    FCL_STR_MAKA = 4,
    FCL_STR_BATS = 5,
    FCL_STR_SYOJISU = 6,
    FCL_STR_KO = 7,
    FCL_STR_HOUSEKISU = 8,
    FCL_STR_CHIRYOUHI = 9,
} FCL_STR;

typedef enum {
    FCL_PANELTYPE_BACK = 0,
    FCL_PANELTYPE_LIST = 1,
    FCL_PANELTYPE_HELP = 2,
    FCL_PANELTYPE_LIST2 = 3,
    FCL_PANELTYPE_DEF = 4,
} FCL_PANELTYPE;

typedef enum {
    FCL_PANELGRAD_DOUBLE = 0,
    FCL_PANELGRAD_DOUBLE2 = 1,
} FCL_PANELGRAD;

typedef enum {
    FCL_PANELMOVER_MODE_NONE = 0,
    FCL_PANELMOVER_MODE_NEXT = 1,
    FCL_PANELMOVER_MODE_PREV = 2,
} FCL_PANELMOVER;

typedef enum {
    RAG_SEQ_RO = 0,
    RAG_SEQ_IT = 1,
    RAG_SEQ_SE = 2,
    RAG_SEQ_MI = 3,
    RAG_SEQ_TL = 4,
    RAG_SEQ_EX = 5,
    RAG_SEQ_ERR = 6,
    RAG_SEQ_ST = 7,
    RAG_SEQ_CFM = 8,
} RAG_SEQ;

typedef enum {
    RAG_ERR_NONE = 0,
} RAG_ERR;

typedef enum {
    RCV_SEQ_RO = 0,
    RCV_SEQ_AR = 1,
    RCV_SEQ_RC = 2,
    RCV_SEQ_ST = 3,
    RCV_SEQ_RV = 4,
    RCV_SEQ_DP = 5,
    RCV_SEQ_TL = 6,
    RCV_SEQ_EX = 7,
    RCV_SEQ_CFM = 8,
} RCV_SEQ;

typedef enum {
    RCV_ERR_NONE = 0,
} RCV_ERR;

typedef enum {
    RCV_ATTR_NONE = 0,
    RCV_ATTR_RC = 1,
    RCV_ATTR_ST = 2,
    RCV_ATTR_RV = 4,
    RCV_ATTR_ALL = 7,
} RCV_ATTR;

typedef enum {
    FCL_RBN_FLAG_FIXFRAME = 1,
    FCL_RBN_FLAG_MASKLR = 2,
    FCL_RBN_FLAG_FIXHEX = 4,
} FCL_RBN_FLAG;

typedef enum {
    FCL_SPRALPHA_SEMI = 0,
    FCL_SPRALPHA_ADD = 1,
    FCL_SPRALPHA_SUB = 2,
} FCL_SPRALPHA;

typedef enum {
    FCL_SPRFILTER_NONE = 0,
    FCL_SPRFILTER_LINEAR = 1,
} FCL_SPRFILTER;

typedef enum {
    CURSOR_TYPE_LEFT = 0,
    CURSOR_TYPE_RIGHT = 1,
    CURSOR_TYPE_DOWN = 2,
} CURSOR_TYPE;

typedef enum {
    SHP_SEQ_RO = 0,
    SHP_SEQ_BU = 1,
    SHP_SEQ_SE = 2,
    SHP_SEQ_TL = 3,
    SHP_SEQ_EX = 4,
    SHP_SEQ_BN = 5,
    SHP_SEQ_SN = 6,
    SHP_SEQ_ERR = 7,
    SHP_SEQ_CFM = 8,
    SHP_SEQ_PAY = 9,
    SHP_SEQ_SRV = 10,
    SHP_SEQ_SRV_IT = 11,
} SHP_SEQ;

typedef enum {
    SHP_ERR_NONE = 0,
} SHP_ERR;

typedef enum {
    TRM_SEQ_RO = 0,
    TRM_SEQ_TR = 1,
    TRM_SEQ_SA = 2,
    TRM_SEQ_TL = 3,
    TRM_SEQ_EX = 4,
    TRM_SEQ_CFM = 5,
    TRM_SEQ_ACT = 6,
    TRM_SEQ_SA_IN = 7,
    TRM_SEQ_SA_OUT = 8,
} TRM_SEQ;

typedef enum {
    TRM_EVT_NONE = 0,
    TRM_EVT_WAIT = 1,
    TRM_EVT_START = 2,
    TRM_EVT_BUSY = 3,
    TRM_EVT_TALK_START = 4,
    TRM_EVT_TALK = 5,
    TRM_EVT_TERM = 6,
} TRM_EVT;

typedef enum {
    TRM_ERR_NONE = 0,
} TRM_ERR;

typedef struct cmbGlobalWork_t cmbGlobalWork_t;
typedef struct cmbKeisyoSort_t cmbKeisyoSort_t;
typedef struct cmbModelPack_t cmbModelPack_t;
typedef struct cmbRaceLevelSorted_t cmbRaceLevelSorted_t;
typedef struct cmbResultTable_t cmbResultTable_t;
typedef struct cmbSelDev_t cmbSelDev_t;
typedef struct cmpCmdSelInfo_t cmpCmdSelInfo_t;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpLocalSkill_t cmpLocalSkill_t;
typedef struct cmpLocalStock_t cmpLocalStock_t;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct cmpYesNoInfo_t cmpYesNoInfo_t;
typedef struct datDevilFormat_s datDevilFormat_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effEVECombParSmokeParam_t effEVECombParSmokeParam_t;
typedef struct effEVECombParSmoke_t effEVECombParSmoke_t;
typedef struct effHandle_t effHandle_t;
typedef struct fclCombCom_t fclCombCom_t;
typedef struct fclCombSpirit_t fclCombSpirit_t;
typedef struct fclDataRag_t fclDataRag_t;
typedef struct fclDataRecover_t fclDataRecover_t;
typedef struct fclDataShop_t fclDataShop_t;
typedef struct fclDataTerminal_t fclDataTerminal_t;
typedef struct fclDrawPanelFunc_t fclDrawPanelFunc_t;
typedef struct fclDrawSprTbl_t fclDrawSprTbl_t;
typedef struct fclEncycRecord_t fclEncycRecord_t;
typedef struct fclEventDevil_t fclEventDevil_t;
typedef struct fclIkenieExtPatternDev2_t fclIkenieExtPatternDev2_t;
typedef struct fclIkenieExtPatternDevRace_t fclIkenieExtPatternDevRace_t;
typedef struct fclIkenieExtPatternDev_t fclIkenieExtPatternDev_t;
typedef struct fclIkenieExtPattern_t fclIkenieExtPattern_t;
typedef struct fclItemList_t fclItemList_t;
typedef struct fclKeisyoList_t fclKeisyoList_t;
typedef struct fclPanelMoverFunc_t fclPanelMoverFunc_t;
typedef struct fclPanelMover_t fclPanelMover_t;
typedef struct fclPanelPos_t fclPanelPos_t;
typedef struct fclPanel_t fclPanel_t;
typedef struct fclRagDevilParam_t fclRagDevilParam_t;
typedef struct fclRagDevil_t fclRagDevil_t;
typedef struct fclRagExchangeRate_t fclRagExchangeRate_t;
typedef struct fclRagItem_t fclRagItem_t;
typedef struct fclRagMitamaPack_t fclRagMitamaPack_t;
typedef struct fclRagSeireiPack_t fclRagSeireiPack_t;
typedef struct fclRag_t fclRag_t;
typedef struct fclRankBase_t fclRankBase_t;
typedef struct fclRankTbl_t fclRankTbl_t;
typedef struct fclRibbon_t fclRibbon_t;
typedef struct fclShopItemBase_t fclShopItemBase_t;
typedef struct fclShopItemBox_t fclShopItemBox_t;
typedef struct fclShopItemPack_t fclShopItemPack_t;
typedef struct fclShopTbl_t fclShopTbl_t;
typedef struct fclSprTblArry_t fclSprTblArry_t;
typedef struct fclSprTbl_t fclSprTbl_t;
typedef struct fclSpriteBase_t fclSpriteBase_t;
typedef struct fclSprite_t fclSprite_t;
typedef struct fclUpdatePanelFunc_t fclUpdatePanelFunc_t;
typedef struct fclZensyo_t fclZensyo_t;
typedef struct fclencyceelem_t fclencyceelem_t;
typedef struct fclribbon_elem_t fclribbon_elem_t;
typedef struct lstDrawBoxPkt_t lstDrawBoxPkt_t;
typedef struct lstDrawCrsPkt_t lstDrawCrsPkt_t;
typedef struct lstEnvPkt_t lstEnvPkt_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct lstQWdata lstQWdata;
typedef struct lstVertex_t lstVertex_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct fclSprTbl_t {
    s8 TexID;
    fclSpriteBase_t *Base;
};

struct fclDrawSprTbl_t {
    s16 X;
    s16 Y;
    u8 Flag;
    u16 SprTblNo;
};

struct fclSprTblArry_t {
    fclSprTbl_t *Tbl;
    fclDrawSprTbl_t *Draw;
};

struct fclSpriteBase_t {
    u16 W;
    u16 H;
    u16 UV[4];
};

struct fclPanelPos_t {
    s32 X;
    s32 Y;
    u32 Z;
    u16 W;
    u16 H;
    s32 Work;
};

struct fclPanelMover_t {
    u8 Mode;
    s32 OfsX;
    s32 OfsY;
    s32 MaxOfsX;
    s32 MaxOfsY;
    s32 Rate;
    s32 Spd;
    s32 Work;
    fclPanelMoverFunc_t *MoverFunc;
};

struct fclEncycRecord_t {
    s32 num;
    u32 reserved0;
    u32 reserved1;
    u32 reserved2;
    fclencyceelem_t *pelem[185];
};

struct fclencyceelem_t {
    u16 id;
    u16 reserved0;
    u16 maxhp;
    u16 maxmp;
    u32 exp;
    u16 level;
    s8 param[6];
    s8 skillparam[6];
    u16 skillcnt;
    u16 skill[24];
    s8 mitamaparam[6];
    s8 levelupparam[6];
    u16 keisyoskill[24];
    u8 keiattr[24];
    u16 hensinmae;
    u16 reserved1;
    u32 flag;
    u32 reserved2;
    u32 hensinmaeexp;
};

struct fclCombCom_t {
    u16 Devil1ID;
    u16 Devil2ID;
    u16 BirthID;
};

struct fclEventDevil_t {
    u16 DevilID;
    u32 EventFlag;
};

struct fclIkenieExtPattern_t {
    u8 Race1ID;
    u8 Race2ID;
    u8 Race3ID;
    u8 BirthRace;
};

struct fclIkenieExtPatternDev_t {
    u16 Devil1ID;
    u16 Devil2ID;
    u16 Devil3ID;
    u16 BirthDevil;
};

struct fclIkenieExtPatternDev2_t {
    u16 Devil1ID;
    u16 Devil2ID;
    u16 BirthDevil;
};

struct fclIkenieExtPatternDevRace_t {
    u16 DevilID;
    u8 Race1ID;
    u8 Race2ID;
    u16 BirthDevil;
};

struct fclRankTbl_t {
    u16 DevilID;
    fclRankBase_t *Base[32];
};

struct fclCombSpirit_t {
    u16 DevilID;
    u16 ParamType[2];
    u8 UpRate;
};

struct fclRankBase_t {
    u8 RaceID;
    u8 Flag;
};

struct fclShopTbl_t {
    s8 Place;
    s16 EventBitPos[1];
    u8 ItemPackID[2];
};

struct fclShopItemPack_t {
    u16 BaseRate;
    fclShopItemBase_t *ItemList[32];
};

struct fclShopItemBox_t {
    u8 Rate;
    u16 ItemID;
};

struct fclShopItemBase_t {
    u16 ID;
    u16 Rate;
};

struct fclRag_t {
    s8 Place;
    s16 EventBitPos[1];
    u8 ItemPackID[2];
    u8 SeireiPackID[2];
    u8 MitamaPackID[2];
};

struct fclRagItem_t {
    u16 ItemID;
    fclRagExchangeRate_t *Rate[3];
};

struct fclRagDevil_t {
    u16 DevilID;
    s8 ParamFlag;
    fclRagDevilParam_t *Param;
    fclRagExchangeRate_t *Rate[3];
};

struct fclRagMitamaPack_t {
    u8 Per[7];
    u8 *Index[4];
};

struct fclRagSeireiPack_t {
    u8 Per[7];
    u8 *Index[4];
};

struct fclRagDevilParam_t {
    u8 Level;
    u16 MaxHP;
    u16 MaxMP;
    s8 Param[6];
    u16 Skill[8];
};

struct fclRagExchangeRate_t {
    u16 ItemID;
    s8 Nums;
};

struct fclKeisyoList_t {
    u16 SkillID[8];
    s8 SkillCnt;
};

struct cmbGlobalWork_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    cmpCmdSelInfo_t *CmdSelInfo;
    cmpCursorInfo_t *WorkCI[3];
    u8 Jyakyo1st;
    s8 TokusyuBGM;
    u8 DevilNums;
    cmbSelDev_t *SelDev[3];
    datUnitWork_t *BirthDevil;
    datUnitWork_t *BirthDevilOrg;
    datUnitWork_t *AccidentDevil;
    s8 BirthDevilFlag;
    s8 AccidentFlag;
    cmbResultTable_t *Result;
    s8 HelpFlag;
    s8 StatFlag;
    s8 StatTarget;
    s8 ErrorFlag;
    sdfMemHandle_t *ScriptMH;
    u8 *pScriptData;
    dds3ProcessID_t *ScriptPID;
    sdfMemHandle_t *CollectMH;
    u8 *pCollectData;
    dds3ProcessID_t *PMPID;
    cmbModelPack_t *ModelPack[5];
    sdfVector4_t ModelPos[4];
    effEVECombParSmoke_t *EffHandle[3];
    s32 ActTimeTablePos;
    s8 ActFlag;
    s32 ActCnt;
    f32 ActMaskRate;
    s8 IntroFlag;
    s8 IdxNums;
    s8 StockIdx[12];
    cmpCmdSelInfo_t *ZensyoSelInfo;
    cmpCmdSelInfo_t *TalkSelInfo;
    lstListWindow_t *ListWindow;
    datUnitWork_t *ZensyoList[16];
    s32 ZensyoListNums;
    sdfTexHandle_t *TexHandle[7];
    fclSprite_t *SpriteBG;
    effEVECombParSmokeParam_t *pEffParam;
    fclPanel_t *pBackPanel;
    fclRibbon_t *pRibbon;
    fclPanelMover_t *PanelMover[2];
    s32 NoDraw;
    bool Initialized;
    s32 EventEnd;
    s32 LevelLimit;
    s32 MovieSkip;
    s32 RepeatSw;
    s32 bDrawStat;
    bool bDrawDisabled;
    s32 EffCsr;
    bool bReadPhase;
    bool bMaxParam;
    bool bLoadModel;
    bool bUnlock;
};

struct cmbResultTable_t {
    s8 flag;
    s8 **table[2];
    u16 **b_id[2];
    datUnitWork_t **devil[2];
    fclKeisyoList_t **keisyo[2];
};

struct lstListWindow_t {
    fclPanel_t *Panel;
    fclPanelPos_t *Pos;
    u32 Col;
    s8 Style;
    u8 ItemAttr[256];
    cmpCursorInfo_t *CursorInfo;
};

struct fclSprite_t {
    sdfTexHandle_t *TexHandle;
    fclSpriteBase_t *Base;
    s32 X;
    s32 Y;
    s32 Z;
    u8 Col[4];
    u8 Flag;
};

struct fclPanel_t {
    s32 X;
    s32 Y;
    u32 Z;
    u16 W;
    u16 H;
    u32 Col;
    u8 Spd;
    s32 Timer;
    s32 Timer2;
    u32 Flag;
    u32 TexUV[4];
    sdfTexHandle_t *TexHandle;
    fclDrawPanelFunc_t *DrawFunc;
    fclUpdatePanelFunc_t *UpdateFunc;
};

struct fclRibbon_t {
    sdfTexHandle_t *tex[2];
    u32 stat;
    s16 act;
    s16 deact;
    s32 ctr_act;
    s32 ctr_deact;
    s32 ctr;
    s32 num;
    fclribbon_elem_t *pelem;
};

struct cmbSelDev_t {
    s8 Index;
    s8 CursorIndex;
    u16 ID;
};

struct cmbModelPack_t {
    sdfMemHandle_t *MH;
    u8 *pData;
    s32 DataSize;
    u16 DevilID;
    dds3ModelHandle_t *Model;
    void *DevilObj;
    bool cmbAct_MdlEffectSkip;
    bool bEnabled;
};

struct fclribbon_elem_t {
    sdfIVector4_t *pos_act;
    sdfIVector4_t *pos_deact;
    sdfIVector4_t *uv_act;
    sdfIVector4_t *uv_deact;
    sdfTexHandle_t *tex[2];
};

struct fclDataRag_t {
    cmpSeqInfo_t *SeqInfo;
    s8 InitFlag;
    s8 Place;
    s8 ItemList[32];
    s8 ItemListCnt;
    s8 SeireiList[8];
    s8 SeireiListCnt;
    s8 MitamaList[8];
    s8 MitamaListCnt;
    s8 HeartsFlag;
    datUnitWork_t *Devil;
    cmpCmdSelInfo_t *CmdSelInfo;
    lstListWindow_t *ItemWindow;
    lstListWindow_t *SeireiWindow;
    lstListWindow_t *MitamaWindow;
    u8 *pScriptData;
    dds3ProcessID_t *ScriptPID;
    sdfTexHandle_t *TexHandleBG;
    sdfTexHandle_t *TexHandle[2];
    fclSprite_t *SpriteBG;
    fclPanel_t *HelpPanel;
    fclPanel_t *SyojiPanel;
    fclPanel_t *BackPanel;
    fclPanelMover_t *PanelMover[2];
    bool Initialized;
    s32 EventEnd;
    s32 ismsgend;
};

struct fclDataRecover_t {
    cmpSeqInfo_t *SeqInfo;
    s8 Place;
    cmpCmdSelInfo_t *CmdSelInfo;
    s32 Price[24];
    u8 AttrFlag;
    cmpLocalStock_t *LocalStock;
    cmpLocalSkill_t *LocalSkill;
    cmpYesNoInfo_t *YesNoInfo;
    lstListWindow_t *StockWindow;
    lstListWindow_t *SkillWindow;
    u8 *pScriptData;
    dds3ProcessID_t *ScriptPID;
    bool EffFlag;
    effHandle_t *EffHandle;
    u8 *EffD3P;
    dds3Basic_t *bas;
    sdfTexHandle_t *TexHandle[3];
    fclPanel_t *BackPanel;
    fclPanelMover_t *PanelMover[2];
    bool Initialized;
    s32 EventEnd;
    s32 ismsgend;
};

struct fclDataShop_t {
    cmpSeqInfo_t *SeqInfo;
    s8 InitFlag;
    s8 Place;
    s32 PayMoney;
    s32 PayTotal;
    s8 ChoiceNums;
    cmpCmdSelInfo_t *CmdSelInfo;
    lstListWindow_t *ListWindow;
    u16 BuyItemList[32];
    s8 BuyItemCnt;
    s8 HeartsFlag;
    fclItemList_t *SellItemList;
    s32 IncVal;
    u8 *pScriptData;
    dds3ProcessID_t *ScriptPID;
    sdfTexHandle_t *TexHandle[2];
    fclPanel_t *HelpPanel;
    fclPanel_t *BackPanel;
    fclPanelMover_t *PanelMover[2];
    bool Initialized;
    s32 EventEnd;
    s32 ismsgend;
};

struct fclItemList_t {
    u8 ItemCnt;
    u16 ItemIdx[160];
};

struct fclDataTerminal_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    cmpCmdSelInfo_t *CmdSelInfo;
    lstListWindow_t *TransWindow;
    s8 MenuEraseFlag;
    s8 TerminalType;
    u16 TerminalNo;
    s8 TerminalList[34];
    s8 LastTerminalType;
    s8 TerminalCnt;
    s8 ActFlag;
    s8 ActStartFlag;
    sdfMemHandle_t *ScriptMH;
    u8 *pScriptData;
    dds3ProcessID_t *ScriptPID;
    sdfMemHandle_t *EvtScrMH;
    void *pEvtScrData;
    dds3ProcessID_t *EvtScrPID;
    dds3ProcessID_t *PMPID;
    dds3ProcessID_t *PMPID2;
    sdfTexHandle_t *TexHandle[1];
    bool Initialized;
    s32 EventEnd;
};

struct cmbKeisyoSort_t {
    u16 KeisyoSkill;
    u8 KeiAttr;
};

struct cmbRaceLevelSorted_t {
    u16 ID;
    datDevilFormat_t *pData;
};

struct fclZensyo_t {
    u32 exp;
    u16 level;
    s8 param[6];
    s8 skillparam[6];
    u16 skillcnt;
    u16 skill[24];
    s8 mitamaparam[6];
    s8 levelupparam[6];
    u16 keisyoskill[24];
    u16 hensinmae;
    u32 hensinmaeexp;
};

struct lstQWdata {
    u64 ul128[2];
    u64 ul64[2];
    u32 ui32[4];
    sdfVector4_t fvect;
};

struct lstVertex_t {
    lstQWdata *col;
    lstQWdata *xyz;
};

struct lstEnvPkt_t {
    lstQWdata *giftag;
    lstQWdata *alpha1;
    lstQWdata *pabe;
    lstQWdata *fba1;
    lstQWdata *test1;
};

struct lstDrawCrsPkt_t {
    lstQWdata *dmatag;
    lstEnvPkt_t *envpkt;
    lstQWdata *giftag;
    lstVertex_t *vertex1[3];
};

struct lstDrawBoxPkt_t {
    lstQWdata *dmatag;
    lstEnvPkt_t *envpkt;
    lstQWdata *giftag;
    lstVertex_t *vertex1[4];
};

extern u32 FCL_RECOVER_ULINECOL_MAIN;
extern u32 FCL_RAG_ULINECOL_EXCHG;
extern u32 FCL_RAG_WINCOL_HELP;
extern u32 FCL_RAG_ULINECOL_MAIN;
extern u32 FCL_PANELHELP_GRAD_COL;
extern u32 FCL_PANELDEF_GRAD_COL;
extern u32 FCL_RAG_WINCOL_SYOJI;
extern u32 FCL_RAG_CAPCOL_HELP;
extern u32 FCL_RAG_CAPCOL_EXCHG;
extern u32 FCL_SHOP_CAPCOL_HELP;
extern u32 FCL_SHOP_ULINECOL_ITEM;
extern u32 FCL_SHOP_WINCOL_HELP;
