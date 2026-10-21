#pragma once
#include "types.h"

typedef enum {
    NORMAL = 0,
    P2A = 1,
    MULTI = 2,
    GENERAL = 3,
} DDS3BILLBOARD;

typedef enum {
    STATE_END = 0,
    STATE_RUN = 1,
} DDS3BILLANIM;

typedef enum {
    OPAQUE = 0,
    SEMITRANS = 1,
    ADDTRANS = 2,
    SUBTRANS = 3,
    COUNT = 4,
} BILL_MODE;

typedef enum {
    EFFBTL_CUT_1 = 0,
    EFFBTL_CUT_2 = 1,
    EFFBTL_CUT_3 = 2,
    EFFBTL_CUT_ENCOUNT = 3,
    EFFBTL_CUT_RETURN = 3,
    EFFBTL_CUT_NEGO = 3,
    EFFBTL_CUT_MAX = 4,
} EFFBTL_CUT;

typedef enum {
    STOP = 0,
    FADE_IN_BASE = 1,
    FADE_IN = 2,
    WAIT = 3,
    FADE_OUT = 4,
    FADE_OUT_WAIT = 5,
} EFFBTL_FIELDCOLOR_P;

typedef enum {
    D3P = 0,
    P2A = 1,
    TMX = 2,
    MODEL = 3,
    PCP = 4,
    P2APOLY = 5,
    PCF = 6,
    MAX = 7,
    BED = 65533,
    EMPTY = 65534,
    COPY = 65535,
} DDS3EFFPART_TYPE;

typedef enum {
    FRONT = 0,
    R45 = 1,
    R90 = 2,
    R135 = 3,
    BACK = 4,
    L135 = 5,
    L90 = 6,
    L45 = 7,
    MAX = 8,
} EFFBTL_CIRPTR_Y;

typedef enum {
    FRONT = 0,
    U45 = 1,
    U90 = 2,
    U135 = 3,
    BACK = 4,
    D135 = 5,
    D90 = 6,
    D45 = 7,
    MAX = 8,
} EFFBTL_CIRPTR_X;

typedef enum {
    MODEL = 0,
    PARTY_I = 1,
    PARTY_T = 2,
    WORLD = 3,
    MARK = 4,
    MARK2 = 5,
    MAX = 6,
} EFFBTL_POSPTR_T;

typedef enum {
    BOTTOM = 0,
    MIDDLE = 1,
    PEAK = 2,
    TOP = 3,
    CAMERA = 4,
    GROUND = 5,
    MAX = 6,
} EFFBTL_POSPTR_H;

typedef enum {
    FRONT = 0,
    R45 = 1,
    R90 = 2,
    R135 = 3,
    BACK = 4,
    L135 = 5,
    L90 = 6,
    L45 = 7,
    CENTER = 8,
    CAMERA = 9,
    CENTER2 = 10,
    MAX = 11,
} EFFBTL_POSPTR_D;

typedef enum {
    NON = 0,
    SHOCK = 1,
    FREEZE = 2,
    SLEEP = 3,
    PANIC = 4,
    BIND = 5,
    CLOSE = 6,
    POISON = 7,
    CHARM = 8,
    PARALYZE = 9,
    FLY = 10,
    STONE = 11,
    CURSE = 12,
    CURSE_CAMP = 13,
    STONE_DEAD = 14,
    MUDO_DEAD = 15,
    HAMA_DEAD = 16,
    HANSYA = 17,
    KYUSYUU = 18,
    TOUSOU = 19,
    RETURN = 20,
    DEAD = 21,
    REVIVAL = 22,
    NAKAMA = 23,
    ATTACK = 24,
    ATTACK_C = 25,
    ENCOUNT = 26,
    NEGO_KAIHUKU = 27,
    NEGO_KYUSYU = 28,
    NEGO_STONE = 29,
    MAX = 30,
} EFFBTL_SYSTEM;

typedef enum {
    EFFVIEWER_ITEM_S8 = 0,
    EFFVIEWER_ITEM_U8 = 1,
    EFFVIEWER_ITEM_S16 = 2,
    EFFVIEWER_ITEM_U16 = 3,
    EFFVIEWER_ITEM_S32 = 4,
    EFFVIEWER_ITEM_U32 = 5,
    EFFVIEWER_ITEM_U32H = 6,
    EFFVIEWER_ITEM_FLOAT = 7,
    EFFVIEWER_ITEM_ONOFF = 8,
    EFFVIEWER_ITEM_R = 9,
    EFFVIEWER_ITEM_G = 10,
    EFFVIEWER_ITEM_B = 11,
    EFFVIEWER_ITEM_A = 12,
    EFFVIEWER_ITEM_BLEND = 13,
    EFFVIEWER_ITEM_BLEND2 = 14,
    EFFVIEWER_ITEM_BLEND3 = 15,
    EFFVIEWER_ITEM_XY = 16,
    EFFVIEWER_ITEM_CAMERA = 17,
    EFFVIEWER_ITEM_SEPA = 18,
    EFFVIEWER_ITEM_TITLE = 19,
    EFFVIEWER_ITEM_AREA = 20,
    EFFVIEWER_ITEM_PARMINIT = 21,
    EFFVIEWER_ITEM_SUBMENU = 22,
    EFFVIEWER_ITEM_FUNC = 23,
} EFFVIEWER_ITEM;

typedef enum {
    EFFFLWIN_STAT_RUN = 0,
    EFFFLWIN_STAT_SELECT = 1,
    EFFFLWIN_STAT_CANCEL = 2,
} EFFFLWIN_STAT;

typedef enum {
    EFFEVEBED_CUT_1 = 0,
    EFFEVEBED_CUT_2 = 1,
    EFFEVEBED_CUT_3 = 2,
    EFFEVEBED_CUT_MAX = 3,
} EFFEVEBED_CUT;

typedef enum {
    OPAQUE = 0,
    SEMITRANS = 1,
    ADDTRANS = 2,
    SUBTRANS = 3,
    MAX = 4,
} DDS3MAGATUHI_BLEND;

typedef enum {
    DDS3MAGAPAR_SMOKECONV = 0,
    DDS3MAGAPAR_POINT4 = 1,
    DDS3MAGAPAR_CYLINDER = 2,
    DDS3MAGAPAR_SPIRAL = 3,
    DDS3MAGAPAR_SMOKE = 4,
} DDS3MAGAPAR;

typedef enum {
    DDS3EFFECT_PARTICLE = 0,
    DDS3EFFECT_PARTICLE_EXP = 1,
    DDS3EFFECT_POLYGON = 2,
    DDS3EFFECT_MAGATUHI = 3,
    DDS3EFFECT_PCF = 4,
    DDS3EFFECT_DANTE = 5,
    DDS3EFFECT_FUNC = 6,
    DDS3EFFECT_BILLBOARD = 7,
    DDS3EFFECT_COUNT = 8,
} DDS3EFFECT;

typedef enum {
    DDS3EFFECT_STATE_END = 0,
    DDS3EFFECT_STATE_RUN = 1,
} DDS3EFFECT_STATE;

typedef enum {
    EXP = -1,
    NOM = 0,
} DDS3PARTICLE_BILL;

typedef enum {
    EFFMTP_BLEND_OPAQUE = 0,
    EFFMTP_BLEND_SEMITRANS = 1,
    EFFMTP_BLEND_ADDTRANS = 2,
    EFFMTP_BLEND_SUBTRANS = 3,
    EFFMTP_BLEND_NEG = 4,
    EFFMTP_BLEND_MAX = 5,
} EFFMTP_BLEND;

typedef enum {
    OPAQUE = 0,
    SEMITRANS = 1,
    ADDTRANS = 2,
    SUBTRANS = 3,
    MAX = 4,
} DDS3FPL_BLEND;

typedef enum {
    DDS3SPL_BLEND_OPAQUE = 0,
    DDS3SPL_BLEND_SEMITRANS = 1,
    DDS3SPL_BLEND_ADDTRANS = 2,
    DDS3SPL_BLEND_SUBTRANS = 3,
    DDS3SPL_BLEND_NEG = 4,
    DDS3SPL_BLEND_MAX = 5,
} DDS3SPL_BLEND;

typedef enum {
    DDS3NM_BLEND_OPAQUE = 0,
    DDS3NM_BLEND_SEMITRANS = 1,
    DDS3NM_BLEND_ADDTRANS = 2,
    DDS3NM_BLEND_SUBTRANS = 3,
    DDS3NM_BLEND_MAX = 4,
} DDS3NM_BLEND;

typedef enum {
    DDS3RPE_BLEND_OPAQUE = 0,
    DDS3RPE_BLEND_SEMITRANS = 1,
    DDS3RPE_BLEND_ADDTRANS = 2,
    DDS3RPE_BLEND_SUBTRANS = 3,
    DDS3RPE_BLEND_MAX = 4,
} DDS3RPE_BLEND;

typedef enum {
    DDS3WPL_BLEND_OPAQUE = 0,
    DDS3WPL_BLEND_SEMITRANS = 1,
    DDS3WPL_BLEND_ADDTRANS = 2,
    DDS3WPL_BLEND_SUBTRANS = 3,
    DDS3WPL_BLEND_MAX = 4,
} DDS3WPL_BLEND;

typedef enum {
    EFFPCP_BOSS_BUNSIN_CUT1 = 0,
    EFFPCP_BOSS_BUNSIN_CUT2 = 1,
} EFFPCP_BOSS_BUNSIN;

typedef enum {
    DDS3EFFECT_TYPE_BILLBOARD = 0,
    DDS3EFFECT_TYPE_ANIMBILL = 1,
    DDS3EFFECT_TYPE_PARTICLE = 2,
    DDS3EFFECT_TYPE_MODEL = 3,
    DDS3EFFECT_TYPE_FUNCTION = 4,
} DDS3EFFECT_TYPE;

typedef enum {
    NBCAMERA_STAT_WAIT = 0,
    NBCAMERA_STAT_START = 1,
    NBCAMERA_STAT_COMM_ROOT = 2,
    NBCAMERA_STAT_COMM_BAD = 3,
    NBCAMERA_STAT_COMM_TARGETSEL = 4,
    NBCAMERA_STAT_SKILL_ATTACK = 5,
    NBCAMERA_STAT_SKILL_START = 6,
    NBCAMERA_STAT_SKILL_CUT1 = 7,
    NBCAMERA_STAT_SKILL_CUT2 = 8,
    NBCAMERA_STAT_SKILL_CUT3 = 9,
    NBCAMERA_STAT_SKILL_END = 10,
    NBCAMERA_STAT_PRESSTURN = 11,
    NBCAMERA_STAT_SUMMON = 12,
    NBCAMERA_STAT_NEGO_BOUGAI = 13,
    NBCAMERA_STAT_NEGO_TAIZI = 14,
    NBCAMERA_STAT_NEGO_TARGET = 15,
    NBCAMERA_STAT_NEGO_HOJO = 16,
    NBCAMERA_STAT_NEGO_END = 17,
    NBCAMERA_STAT_GAMEOVER = 18,
    NBCAMERA_STAT_RESULT = 19,
    NBCAMERA_STAT_PLAYERSIDE = 20,
    NBCAMERA_STAT_ENEMYSIDE = 21,
    NBCAMERA_STAT_END = 22,
    NBCAMERA_STAT_EVENT = 23,
    NBCAMERA_STAT_EVENT_TARGET = 24,
    NBCAMERA_STAT_ENEMY_BAD = 25,
    NBCAMERA_STAT_SCRIPT_1SHOT = 26,
    NBCAMERA_STAT_SCRIPT_BOUGAI = 27,
    NBCAMERA_STAT_SCRIPT_FIX = 28,
    NBCAMERA_STAT_DEBUG_SHOT_ALL = 29,
    NBCAMERA_STAT_MAX = 30,
} NBCAMERA_STAT;

typedef enum {
    NORMAL = 0,
    N_MAX = 1,
    ATTACK = 2,
    IT_R = 3,
    ITP_R = 4,
    EX01 = 5,
    EX02 = 6,
    EX03 = 7,
    SUMMON = 8,
    ANALYZ = 9,
    IT_N_R = 10,
    NON = 11,
    MAX = 12,
} CS_ST1;

typedef enum {
    ALL = 0,
    IT = 1,
    T = 2,
    CS_ST23_N_MAX = 3,
    ATTACK = 4,
    ITPT = 5,
    ITPT2 = 6,
    IT_R = 7,
    EX00 = 8,
    EX01 = 9,
    EX02 = 10,
    EX03 = 11,
    EX04 = 12,
    SUMMON = 13,
    ANALYZ = 14,
    IT_N = 15,
    IT_N_R = 16,
    TORAFL = 17,
    ALLPARTY = 18,
    I = 19,
    IP = 20,
    MAX = 21,
} CS_ST23;

typedef enum {
    ALL = 0,
    B25 = 1,
    B15 = 2,
    B10 = 3,
    MIDDLE = 4,
    T25 = 5,
    T15 = 6,
    T10 = 7,
    N_MAX = 8,
    B = 9,
    T = 10,
    BT15 = 11,
    BT10 = 12,
    B25T10 = 13,
    B25T25 = 14,
    B15_25 = 15,
    B_T15 = 16,
    B10_15 = 17,
    MAX = 18,
} CS_HA;

typedef enum {
    ALL = 0,
    R45 = 1,
    R30 = 2,
    R15 = 3,
    MIDDLE = 4,
    L45 = 5,
    L30 = 6,
    L15 = 7,
    N_MAX = 8,
    R = 9,
    L = 10,
    R30L30 = 11,
    R15L15 = 12,
    R30L30NF = 13,
    MAX = 14,
} CS_WA;

typedef enum {
    HFIT = 0,
    H4 = 1,
    H6 = 2,
    H8 = 3,
    HMAX = 4,
} CS_H;

typedef enum {
    WFIT = 0,
    W6 = 1,
    W7 = 2,
    W8 = 3,
    W10 = 4,
    W11 = 5,
    W12 = 6,
    WMAX = 7,
} CS_W;

typedef enum {
    SPIRAL = 0,
    SMOKE = 1,
    SPARK = 2,
    RADIATE = 3,
    SPHERESPIRAL = 4,
    SPHERESMOKE = 5,
    SPHERERING = 6,
    SPARK2 = 7,
    SPHEREATOM = 8,
    NOP = 9,
    SPARKOFFSET = 10,
    SMOKEOFFSET = 11,
    SPHERESPIRAL2 = 12,
} DDS3PARTICLE;

typedef enum {
    NO = 0,
    BLUR = 1,
    TRACK = 2,
    TRACK2 = 3,
    TRACK3 = 4,
    COUNT = 5,
} DDS3PAR_EFFECT;

typedef enum {
    OPAQUE = 0,
    SEMITRANS = 1,
    ADDTRANS = 2,
    SUBTRANS = 3,
    NEG = 4,
    MAX = 5,
} POLY_MODE;

typedef enum {
    POLY_TYPE_NORMAL = 0,
    POLY_TYPE_DELETE = 1,
    POLY_TYPE_MAX = 2,
} POLY_TYPE;

typedef enum {
    TYPE_1 = 0,
    TYPE_2 = 1,
    TYPE_3 = 2,
    TYPE_4 = 3,
    TYPE_5 = 4,
    TYPE_MAX = 5,
} DDS3TRACKPOLY;

typedef enum {
    NORMAL = 0,
    ACUTE = 1,
    ACUTE_W = 2,
    MAX = 3,
} DDS3TRACKPOLY_VC;

typedef enum {
    RING_OLD = 0,
    RING = 1,
    SPHERERING = 2,
    ROLLRING = 3,
} DDS3SPPOLY;

typedef enum {
    effPCPFlashPolySphere2Param_no = 0,
    effPCPFlashPolySphereParam_no = 1,
    effPCPFlashPolyRingParam_no = 2,
    effPCPFlashPolyPipeParam_no = 3,
    effPCPFlashPolyRingExpParam_no = 4,
    effPCPFlashPolySphereExpParam_no = 5,
    effPCPFlashPolySphere2ExpParam_no = 6,
    effPCPFlashPolySphere3Param_no = 7,
    effPCPFlashPolyRingExp2Param_no = 8,
    effPCPFlashPolyCircleParam_no = 9,
    effPCPMultiFilterExpParam_no = 10,
    effPCPMultiBlurExp2Param_no = 11,
    effPCPFilterExpParam_no = 12,
    effPCPBlurExpParam_no = 13,
    effPCPDistortionBlurExpParam_no = 14,
    effPCPRippleBlurExpParam_no = 15,
    effPCPBreathParam_no = 16,
    effPCPAgiFireballParam_no = 17,
    effPCPAgiFireball2Param_no = 18,
    effPCPThunderSphereExpParam_no = 19,
    effPCPRingPolyExpParam_no = 20,
    effPCPRingPolyExp2Param_no = 21,
    effPCPRadiateThunderParam_no = 22,
    effPCPRadiateBEDParam_no = 23,
    effPCPRadiateTBParam_no = 24,
    effPCPSpiralBEDParam_no = 25,
    effPCPHelperBEDParam_no = 26,
    effPCPFLEACHBlurParam_no = 27,
    effPCPAgiraoFireParam_no = 28,
    effPCPHamaCardSpiralParam_no = 29,
    effPCPHamaCardSphereParam_no = 30,
    effPCPHamaCardScatterParam_no = 31,
    effPCPWhirlwindPolyParam_no = 32,
    effPCPWhirlwind2PolyParam_no = 33,
    effPCPWhirlwind3PolyParam_no = 34,
    effPCPWwSpherePolyParam_no = 35,
    effPCPThunderSpherePolyParam_no = 36,
    effPCPCrackParam_no = 37,
    effPCPBossBaelParam_no = 38,
    effPCPBossDengekiParam_no = 39,
    effPCPBossThunderboltParam_no = 40,
    effPCPBossKAGUInvokeParam_no = 41,
    effPCPBossKAGUAttackParam_no = 42,
    effPCPBossKAGUThunderboltParam_no = 43,
    effPCPBossKAGU2AttackParam_no = 44,
    effPCPBossKAGU2MUHENKParam_no = 45,
    effPCPCrack2Param_no = 46,
    effPCPBossMETATOBeamParam_no = 47,
    effPCPScreenCrackModelParam_no = 48,
    effPCPMuzzleFlashParam_no = 49,
    effPCPDANTE_Thunder_Param_no = 50,
    effPCPDANTE_Damage_Param_no = 51,
    effPCP_PBCamera_Param_no = 52,
    effPCPDANTE_ShowTime_Param_no = 53,
    effPCP_BED_Param_no = 54,
    effPCP_HBED2_Param_no = 55,
    effPCPBezierBillParam_no = 56,
    effPCPNeedleSpiralParam_no = 57,
    effPCP_object_Param_no = 58,
} CTNO;

typedef enum {
    NORMAL = 0,
    PLURAL = 1,
    MULTI = 2,
    ALPHAMULTI = 3,
} DDS3P2APOLY_TYPE;

typedef struct BillTable_t BillTable_t;
typedef struct EffBTL_BillFireball_Part_t EffBTL_BillFireball_Part_t;
typedef struct EffBTL_BillFireball_t EffBTL_BillFireball_t;
typedef struct EffBTL_BillTrack_Part_t EffBTL_BillTrack_Part_t;
typedef struct EffBTL_BillTrack_t EffBTL_BillTrack_t;
typedef struct EffTable_t EffTable_t;
typedef struct Eff_FlashPolyParam_t Eff_FlashPolyParam_t;
typedef struct Eff_FlashPolyPart_t Eff_FlashPolyPart_t;
typedef struct Eff_FlashPoly_t Eff_FlashPoly_t;
typedef struct Eff_ModelTrackPolyABGR_t Eff_ModelTrackPolyABGR_t;
typedef struct Eff_ModelTrackPolyParam_t Eff_ModelTrackPolyParam_t;
typedef struct Eff_ModelTrackPoly_tag Eff_ModelTrackPoly_tag;
typedef struct Eff_RippleSprite_t Eff_RippleSprite_t;
typedef struct Eff_Ripple_t Eff_Ripple_t;
typedef struct Eff_SparkleSphereBillParam_t Eff_SparkleSphereBillParam_t;
typedef struct Eff_SparkleSphereBill_t Eff_SparkleSphereBill_t;
typedef struct Eff_ThunderPolyParam_t Eff_ThunderPolyParam_t;
typedef struct Eff_ThunderPolyPart_t Eff_ThunderPolyPart_t;
typedef struct Eff_ThunderPoly_t Eff_ThunderPoly_t;
typedef struct Eff_ThunderRadiatePolyParam_t Eff_ThunderRadiatePolyParam_t;
typedef struct Eff_ThunderRadiatePolyPart_t Eff_ThunderRadiatePolyPart_t;
typedef struct Eff_ThunderRadiatePoly_t Eff_ThunderRadiatePoly_t;
typedef struct Eff_ThunderSpherePolyParam_t Eff_ThunderSpherePolyParam_t;
typedef struct Eff_ThunderSpherePolyPart_t Eff_ThunderSpherePolyPart_t;
typedef struct Eff_ThunderSpherePoly_t Eff_ThunderSpherePoly_t;
typedef struct P2A_ANIMATION_tag P2A_ANIMATION_tag;
typedef struct P2A_HEAD_t P2A_HEAD_t;
typedef struct P2A_TEXANIM_tag P2A_TEXANIM_tag;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct billHandle_t billHandle_t;
typedef struct dds3BillAnimResource_tag dds3BillAnimResource_tag;
typedef struct dds3BillAnim_tag dds3BillAnim_tag;
typedef struct dds3BillResource_tag dds3BillResource_tag;
typedef struct dds3Billboard_Normal_tag3 dds3Billboard_Normal_tag3;
typedef struct dds3Billboard_P2A_tag3 dds3Billboard_P2A_tag3;
typedef struct dds3Billboard_Tex_t dds3Billboard_Tex_t;
typedef struct dds3EffectPCPData_Part_t dds3EffectPCPData_Part_t;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3EffectPCP_t dds3EffectPCP_t;
typedef struct dds3EffectTable_Reset_t dds3EffectTable_Reset_t;
typedef struct dds3EffectTable_Reset_t_ResetDelegate dds3EffectTable_Reset_t_ResetDelegate;
typedef struct dds3EffectTable_Scale_t dds3EffectTable_Scale_t;
typedef struct dds3EffectTable_Scale_t_ScaleDelegate dds3EffectTable_Scale_t_ScaleDelegate;
typedef struct dds3EffectTable_t dds3EffectTable_t;
typedef struct dds3EffectTable_t_CreateDelegate dds3EffectTable_t_CreateDelegate;
typedef struct dds3EffectTable_t_DeleteDelegate dds3EffectTable_t_DeleteDelegate;
typedef struct dds3EffectTable_t_DrawDelegate dds3EffectTable_t_DrawDelegate;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistBlurPart_tag dds3Effect_DistBlurPart_tag;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_DistortionBlur_t dds3Effect_DistortionBlur_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialBlur_t dds3Effect_PartialBlur_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_PartialMultiFilter_t dds3Effect_PartialMultiFilter_t;
typedef struct dds3Effect_RipBlurPart_tag dds3Effect_RipBlurPart_tag;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct dds3Effect_RippleBlur_t dds3Effect_RippleBlur_t;
typedef struct dds3Effect_t dds3Effect_t;
typedef struct dds3FlashPolyList_t dds3FlashPolyList_t;
typedef struct dds3HermitianTrackPoly_tag dds3HermitianTrackPoly_tag;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3MultiBillResource_tag dds3MultiBillResource_tag;
typedef struct dds3P2APolygonResource_tag dds3P2APolygonResource_tag;
typedef struct dds3P2APolygon_tag dds3P2APolygon_tag;
typedef struct dds3ParOffsetBuffParts_t dds3ParOffsetBuffParts_t;
typedef struct dds3ParOffsetBuff_t dds3ParOffsetBuff_t;
typedef struct dds3ParticleColorAnim_t dds3ParticleColorAnim_t;
typedef struct dds3Particle_Basic_t dds3Particle_Basic_t;
typedef struct dds3Particle_BlurBuffList_t dds3Particle_BlurBuffList_t;
typedef struct dds3Particle_BlurBuff_t dds3Particle_BlurBuff_t;
typedef struct dds3Particle_Blur_t dds3Particle_Blur_t;
typedef struct dds3Particle_EffItem_t dds3Particle_EffItem_t;
typedef struct dds3Particle_Effect_t dds3Particle_Effect_t;
typedef struct dds3Particle_Exp_t dds3Particle_Exp_t;
typedef struct dds3Particle_Expansion_t dds3Particle_Expansion_t;
typedef struct dds3Particle_Nop_t3 dds3Particle_Nop_t3;
typedef struct dds3Particle_Physics_t dds3Particle_Physics_t;
typedef struct dds3Particle_Radiate_t3 dds3Particle_Radiate_t3;
typedef struct dds3Particle_SmokeOffset_t3 dds3Particle_SmokeOffset_t3;
typedef struct dds3Particle_Smoke_t3 dds3Particle_Smoke_t3;
typedef struct dds3Particle_Spark2_t3 dds3Particle_Spark2_t3;
typedef struct dds3Particle_SparkOffset_t3 dds3Particle_SparkOffset_t3;
typedef struct dds3Particle_Spark_t3 dds3Particle_Spark_t3;
typedef struct dds3Particle_SphereAtom_t3 dds3Particle_SphereAtom_t3;
typedef struct dds3Particle_SphereRing_t3 dds3Particle_SphereRing_t3;
typedef struct dds3Particle_SphereSmoke_t3 dds3Particle_SphereSmoke_t3;
typedef struct dds3Particle_SphereSpiral2_t3 dds3Particle_SphereSpiral2_t3;
typedef struct dds3Particle_SphereSpiral_t3 dds3Particle_SphereSpiral_t3;
typedef struct dds3Particle_Spiral_t3 dds3Particle_Spiral_t3;
typedef struct dds3Particle_Track2_t dds3Particle_Track2_t;
typedef struct dds3Particle_Track3_t dds3Particle_Track3_t;
typedef struct dds3Particle_Track_t dds3Particle_Track_t;
typedef struct dds3Polygon_t dds3Polygon_t;
typedef struct dds3SpPoly_Basic_t dds3SpPoly_Basic_t;
typedef struct dds3SpPoly_RingPhysics_t dds3SpPoly_RingPhysics_t;
typedef struct dds3SpPoly_Ring_Old_Physics_t dds3SpPoly_Ring_Old_Physics_t;
typedef struct dds3SpPoly_Ring_Old_t3 dds3SpPoly_Ring_Old_t3;
typedef struct dds3SpPoly_Ring_t3 dds3SpPoly_Ring_t3;
typedef struct dds3SpPoly_RollRingPhysics_t dds3SpPoly_RollRingPhysics_t;
typedef struct dds3SpPoly_RollRing_t3 dds3SpPoly_RollRing_t3;
typedef struct dds3SpPoly_SphereRingPhysics_t dds3SpPoly_SphereRingPhysics_t;
typedef struct dds3SpPoly_SphereRing_t3 dds3SpPoly_SphereRing_t3;
typedef struct dds3TrackPolyList_t dds3TrackPolyList_t;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct dds3TrianglePoly_t dds3TrianglePoly_t;
typedef struct effAPPoint4Param_t effAPPoint4Param_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTLCutHandle_t_CutEndCallbackDelegate effBTLCutHandle_t_CutEndCallbackDelegate;
typedef struct effBTLCutHandle_t_MotionChangeCallbackDelegate effBTLCutHandle_t_MotionChangeCallbackDelegate;
typedef struct effBTLSysHandle_t effBTLSysHandle_t;
typedef struct effBTL_FieldBaseColorTable_t effBTL_FieldBaseColorTable_t;
typedef struct effBTL_FieldColorTable_t effBTL_FieldColorTable_t;
typedef struct effBTL_SkillCameraShake_t effBTL_SkillCameraShake_t;
typedef struct effBTL_SkillCamera_t effBTL_SkillCamera_t;
typedef struct effBTL_SkillColorAnim_t effBTL_SkillColorAnim_t;
typedef struct effBTL_SkillCutTable_t effBTL_SkillCutTable_t;
typedef struct effBTL_SkillData_t effBTL_SkillData_t;
typedef struct effBTL_SkillField_t effBTL_SkillField_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct effBTL_SkillPBFileHeader_t effBTL_SkillPBFileHeader_t;
typedef struct effBTL_SkillPartsList_t effBTL_SkillPartsList_t;
typedef struct effBTL_SkillParts_t effBTL_SkillParts_t;
typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBTL_SkillSE_t effBTL_SkillSE_t;
typedef struct effBTL_t effBTL_t;
typedef struct effBezier4PPart_t effBezier4PPart_t;
typedef struct effBezier4P_t effBezier4P_t;
typedef struct effBezier7PPart_t effBezier7PPart_t;
typedef struct effBezier7P_t effBezier7P_t;
typedef struct effBezier_t effBezier_t;
typedef struct effCAMPBadParams_t effCAMPBadParams_t;
typedef struct effDistortionBlurHandle_t effDistortionBlurHandle_t;
typedef struct effEVECombParSmokeParam_t effEVECombParSmokeParam_t;
typedef struct effEVECombParSmokePart_t effEVECombParSmokePart_t;
typedef struct effEVECombParSmoke_t effEVECombParSmoke_t;
typedef struct effEveAPP4Point_t effEveAPP4Point_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effEveBEDParams_t effEveBEDParams_t;
typedef struct effFLWin_tag effFLWin_tag;
typedef struct effFileItem_tag effFileItem_tag;
typedef struct effFileList_tag effFileList_tag;
typedef struct effMTPolyListHandle_t effMTPolyListHandle_t;
typedef struct effMagaCylinderParam_t effMagaCylinderParam_t;
typedef struct effMagaP4Point_t effMagaP4Point_t;
typedef struct effMagaPoint4Param_t effMagaPoint4Param_t;
typedef struct effMagaSCArea_t effMagaSCArea_t;
typedef struct effMagaSmokeConvParam_t effMagaSmokeConvParam_t;
typedef struct effMagaSmokeParam_t effMagaSmokeParam_t;
typedef struct effMagaSpiralParam_t effMagaSpiralParam_t;
typedef struct effMagatuhiParams_t effMagatuhiParams_t;
typedef struct effPCPAgiFireball2Param_t effPCPAgiFireball2Param_t;
typedef struct effPCPAgiFireball2PartList_t effPCPAgiFireball2PartList_t;
typedef struct effPCPAgiFireballParam_t effPCPAgiFireballParam_t;
typedef struct effPCPAgiFireballPartList_t effPCPAgiFireballPartList_t;
typedef struct effPCPAgiraoFireParam_t effPCPAgiraoFireParam_t;
typedef struct effPCPAgiraoFirePartList_t effPCPAgiraoFirePartList_t;
typedef struct effPCPBezierBillParam_t effPCPBezierBillParam_t;
typedef struct effPCPBlinkMultiBlurParam_t effPCPBlinkMultiBlurParam_t;
typedef struct effPCPBlurExpParam_t effPCPBlurExpParam_t;
typedef struct effPCPBossBUNSIN2Param_t effPCPBossBUNSIN2Param_t;
typedef struct effPCPBossBUNSIN2_t effPCPBossBUNSIN2_t;
typedef struct effPCPBossBUNSINParam_t effPCPBossBUNSINParam_t;
typedef struct effPCPBossBUNSIN_t effPCPBossBUNSIN_t;
typedef struct effPCPBossBaelParam_t effPCPBossBaelParam_t;
typedef struct effPCPBossBael_t effPCPBossBael_t;
typedef struct effPCPBossDengekiParam_t effPCPBossDengekiParam_t;
typedef struct effPCPBossDengeki_t effPCPBossDengeki_t;
typedef struct effPCPBossKAGU2AttackParam_t effPCPBossKAGU2AttackParam_t;
typedef struct effPCPBossKAGU2Attack_t effPCPBossKAGU2Attack_t;
typedef struct effPCPBossKAGU2MUHENKParam_t effPCPBossKAGU2MUHENKParam_t;
typedef struct effPCPBossKAGU2MUHENK_t effPCPBossKAGU2MUHENK_t;
typedef struct effPCPBossKAGUAttackParam_t effPCPBossKAGUAttackParam_t;
typedef struct effPCPBossKAGUAttack_t effPCPBossKAGUAttack_t;
typedef struct effPCPBossKAGUInvokeParam_t effPCPBossKAGUInvokeParam_t;
typedef struct effPCPBossKAGUInvoke_t effPCPBossKAGUInvoke_t;
typedef struct effPCPBossKAGUThunderboltParam_t effPCPBossKAGUThunderboltParam_t;
typedef struct effPCPBossKAGUThunderbolt_t effPCPBossKAGUThunderbolt_t;
typedef struct effPCPBossMETATOBeamParam_t effPCPBossMETATOBeamParam_t;
typedef struct effPCPBossMETATOBeam_t effPCPBossMETATOBeam_t;
typedef struct effPCPBossONGY2Param_t effPCPBossONGY2Param_t;
typedef struct effPCPBossONGY2_t effPCPBossONGY2_t;
typedef struct effPCPBossONGYParam_t effPCPBossONGYParam_t;
typedef struct effPCPBossONGY_t effPCPBossONGY_t;
typedef struct effPCPBossThunderboltParam_t effPCPBossThunderboltParam_t;
typedef struct effPCPBossThunderbolt_t effPCPBossThunderbolt_t;
typedef struct effPCPBreathParam_t effPCPBreathParam_t;
typedef struct effPCPCrack2Param_t effPCPCrack2Param_t;
typedef struct effPCPCrackParam_t effPCPCrackParam_t;
typedef struct effPCPCrackPartFlash_t effPCPCrackPartFlash_t;
typedef struct effPCPCrackPart_t effPCPCrackPart_t;
typedef struct effPCPCrack_t effPCPCrack_t;
typedef struct effPCPDANTE_Damage_Param_t effPCPDANTE_Damage_Param_t;
typedef struct effPCPDANTE_ShowTime_Param_t effPCPDANTE_ShowTime_Param_t;
typedef struct effPCPDANTE_Thunder_Param_t effPCPDANTE_Thunder_Param_t;
typedef struct effPCPDistortionBlurExpParam_t effPCPDistortionBlurExpParam_t;
typedef struct effPCPFLEACHBlurParam_t effPCPFLEACHBlurParam_t;
typedef struct effPCPFilterExpParam_t effPCPFilterExpParam_t;
typedef struct effPCPFlashPolyCircleParam_t effPCPFlashPolyCircleParam_t;
typedef struct effPCPFlashPolyPipeParam_t effPCPFlashPolyPipeParam_t;
typedef struct effPCPFlashPolyRingExp2Param_t effPCPFlashPolyRingExp2Param_t;
typedef struct effPCPFlashPolyRingExpParam_t effPCPFlashPolyRingExpParam_t;
typedef struct effPCPFlashPolyRingParam_t effPCPFlashPolyRingParam_t;
typedef struct effPCPFlashPolySphere2ExpParam_t effPCPFlashPolySphere2ExpParam_t;
typedef struct effPCPFlashPolySphere2Param_t effPCPFlashPolySphere2Param_t;
typedef struct effPCPFlashPolySphere3Param_t effPCPFlashPolySphere3Param_t;
typedef struct effPCPFlashPolySphereExpParam_t effPCPFlashPolySphereExpParam_t;
typedef struct effPCPFlashPolySphereParam_t effPCPFlashPolySphereParam_t;
typedef struct effPCPHamaCardScatterParam_t effPCPHamaCardScatterParam_t;
typedef struct effPCPHamaCardSphereParam_t effPCPHamaCardSphereParam_t;
typedef struct effPCPHamaCardSpiralParam_t effPCPHamaCardSpiralParam_t;
typedef struct effPCPHelperBEDParam_t effPCPHelperBEDParam_t;
typedef struct effPCPMultiBlurExp2Param_t effPCPMultiBlurExp2Param_t;
typedef struct effPCPMultiBlurExpParam_t effPCPMultiBlurExpParam_t;
typedef struct effPCPMultiFilterExpParam_t effPCPMultiFilterExpParam_t;
typedef struct effPCPMuzzleFlashParam_t effPCPMuzzleFlashParam_t;
typedef struct effPCPNeedleSpiralParam_t effPCPNeedleSpiralParam_t;
typedef struct effPCPRadiateBEDParam_t effPCPRadiateBEDParam_t;
typedef struct effPCPRadiateTBParam_t effPCPRadiateTBParam_t;
typedef struct effPCPRadiateThunderAttach_t effPCPRadiateThunderAttach_t;
typedef struct effPCPRadiateThunderParam_t effPCPRadiateThunderParam_t;
typedef struct effPCPRingPolyExp2Param_t effPCPRingPolyExp2Param_t;
typedef struct effPCPRingPolyExpParam_t effPCPRingPolyExpParam_t;
typedef struct effPCPRippleBlurExpParam_t effPCPRippleBlurExpParam_t;
typedef struct effPCPScreenCrackModelParam_t effPCPScreenCrackModelParam_t;
typedef struct effPCPScreenCrackModel_t effPCPScreenCrackModel_t;
typedef struct effPCPSparkleSphereParam_t effPCPSparkleSphereParam_t;
typedef struct effPCPSpiralBEDParam_t effPCPSpiralBEDParam_t;
typedef struct effPCPThunderSphereExpParam_t effPCPThunderSphereExpParam_t;
typedef struct effPCPThunderSpherePolyLow_t effPCPThunderSpherePolyLow_t;
typedef struct effPCPThunderSpherePolyParam_t effPCPThunderSpherePolyParam_t;
typedef struct effPCPThunderSpherePolyPart_t effPCPThunderSpherePolyPart_t;
typedef struct effPCPThunderSpherePoly_t effPCPThunderSpherePoly_t;
typedef struct effPCPWhirlwind2PolyParam_t effPCPWhirlwind2PolyParam_t;
typedef struct effPCPWhirlwind3PolyParam_t effPCPWhirlwind3PolyParam_t;
typedef struct effPCPWhirlwindPolyParam_t effPCPWhirlwindPolyParam_t;
typedef struct effPCPWwSpherePolyParam_t effPCPWwSpherePolyParam_t;
typedef struct effPCP_BED_Param_t effPCP_BED_Param_t;
typedef struct effPCP_HBED2_Param_t effPCP_HBED2_Param_t;
typedef struct effPCP_PBCamera_Param_t effPCP_PBCamera_Param_t;
typedef struct effPCP_ThunderColumnPolyLowParam_t effPCP_ThunderColumnPolyLowParam_t;
typedef struct effPCP_ThunderColumnPolyLowPart_t effPCP_ThunderColumnPolyLowPart_t;
typedef struct effPCP_ThunderColumnPolyLow_t effPCP_ThunderColumnPolyLow_t;
typedef struct effPCP_ThunderPolyListParam_t effPCP_ThunderPolyListParam_t;
typedef struct effPCP_ThunderPolyList_t effPCP_ThunderPolyList_t;
typedef struct effPCP_ThunderPolyLow_t effPCP_ThunderPolyLow_t;
typedef struct effPCP_ThunderPolyParam_t effPCP_ThunderPolyParam_t;
typedef struct effPCP_ThunderPolyPart_t effPCP_ThunderPolyPart_t;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;
typedef struct effPCP_ThunderRadiatePolyParam_t effPCP_ThunderRadiatePolyParam_t;
typedef struct effPCP_ThunderRadiatePolyPart_t effPCP_ThunderRadiatePolyPart_t;
typedef struct effPCP_ThunderRadiatePoly_t effPCP_ThunderRadiatePoly_t;
typedef struct effPCP_object_Param_t effPCP_object_Param_t;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct effPkt2DF4Parm_t effPkt2DF4Parm_t;
typedef struct effPkt2DTriStripParm_t effPkt2DTriStripParm_t;
typedef struct effRippleBlurHandle_t effRippleBlurHandle_t;
typedef struct effSimpleBED_t effSimpleBED_t;
typedef struct effSpline_t effSpline_t;
typedef struct effSwordTrackParams_t effSwordTrackParams_t;
typedef struct effViewer_Menu_Item_t effViewer_Menu_Item_t;
typedef struct effViewer_Menu_t effViewer_Menu_t;
typedef struct effViewer_Menu_t_DrawDelegate effViewer_Menu_t_DrawDelegate;
typedef struct effViewer_Menu_t_EndDelegate effViewer_Menu_t_EndDelegate;
typedef struct effViewer_Menu_t_InitDelegate effViewer_Menu_t_InitDelegate;
typedef struct effViewer_Menu_t_RefreshDelegate effViewer_Menu_t_RefreshDelegate;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbCameraAnim_t nbCameraAnim_t;
typedef struct nbCameraSkillInfo_t nbCameraSkillInfo_t;
typedef struct nbCameraSkillPtr_t nbCameraSkillPtr_t;
typedef struct nbCameraState_Start_t nbCameraState_Start_t;
typedef struct nbCamera_AllTable_t nbCamera_AllTable_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct parPhysics_t parPhysics_t;
typedef struct parToolColorTable_t parToolColorTable_t;
typedef struct parToolColorWin_tag parToolColorWin_tag;
typedef struct parToolItem_t parToolItem_t;
typedef struct parToolMenu_t parToolMenu_t;
typedef struct parToolMenu_tag parToolMenu_tag;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDmaTag_t sdfDmaTag_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGifTag_t sdfGifTag_t;
typedef struct sdfGrTagRGBA_t sdfGrTagRGBA_t;
typedef struct sdfGrTagSTQ_t sdfGrTagSTQ_t;
typedef struct sdfGrTagXYZ2_t sdfGrTagXYZ2_t;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct effCAMPBadParams_t {
    sdfVector4_t pos;
    sdfVector4_t rot;
    sdfVector4_t center;
    f32 r;
    f32 h;
    f32 scl;
    dds3ModelHandle_t *hModel;
};

struct effBTLSysHandle_t {
    u32 id;
    void *pHandle;
    nbFormation_t *pFormation;
};

struct effSpline_t {
    u32 numpoint;
    u16 islinear;
    u16 reserved;
    sdfVector3_t *mhcoef;
    sdfVector3_t *ppoint;
    s32 pcoef0;
    s32 pcoef1;
    s32 pcoef2;
    u32 segment;
    f32 weight;
    f32 step;
};

struct effPCPThunderSpherePolyParam_t {
    sdfVector4_t pos;
    u32 blend;
    u32 number;
    u8 loop;
    f32 width;
    f32 height;
    f32 refraction;
    s32 interval;
    s32 refresh;
    u16 split;
    f32 width_center;
    u32 color_center;
    f32 width_border;
    u32 color_border;
    f32 width_edge;
    u32 color_edge;
};

struct effPCP_ThunderPolyParam_t {
    sdfVector4_t *pos;
    u32 blend;
    u32 number;
    u32 life;
    f32 refraction;
    s32 interval;
    s32 refresh;
    u16 split;
    f32 width_center;
    u32 color_center;
    f32 width_border;
    u32 color_border;
    f32 width_edge;
    u32 color_edge;
};

struct effPCP_ThunderRadiatePolyParam_t {
    sdfVector4_t pos;
    u32 blend;
    f32 radius;
    u32 number;
    u8 loop;
    f32 refraction;
    s32 interval;
    s32 refresh;
    u16 split;
    f32 width_center;
    u32 color_center;
    f32 width_border;
    u32 color_border;
    f32 width_edge;
    u32 color_edge;
};

struct effPCPMultiBlurExpParam_t {
    u32 blink;
    u32 blink_abgr[2];
    f32 ratio;
    s32 area_min;
    dds3Effect_PartialMultiBlurParam_t *MultiBlur;
};

struct effPCPSparkleSphereParam_t {
    u32 abgr;
};

struct effPCPFlashPolySphereParam_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    s32 scale_f;
    u32 interval;
    u32 abgr_in;
    u32 abgr_out;
    f32 width_in;
    f32 width_out;
    f32 radius;
    f32 rotate;
    u32 blend;
    u32 numberO;
};

struct effPCPMultiFilterExpParam_t {
    u8 type;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    s32 area_s;
    s32 area_e;
    dds3Effect_PartialMultiFilterParam_t *MultiFilter;
};

struct effPCPBlinkMultiBlurParam_t {
    u32 blink;
    u32 *blink_abgr;
    f32 ratio;
    s32 area_min;
    dds3Effect_PartialMultiBlurParam_t *MultiBlur;
};

struct dds3Effect_PartialMultiBlurParam_t {
    s32 area;
    dds3Effect_Blur_t *Blur;
};

struct dds3Effect_PartialMultiFilterParam_t {
    s32 area;
    sdfIVector2_t *center;
    dds3Effect_Filter_t *Filter;
};

struct dds3Effect_Blur_t {
    u32 abgr;
    s32 blend;
    f32 rotate;
    f32 scale;
    sdfIVector2_t *center;
    sdfIVector2_t *xy[2];
};

struct dds3Effect_Filter_t {
    u32 abgr;
    s32 blend;
    sdfIVector2_t *xy[2];
};

struct nbCameraSkillPtr_t {
    u32 ptr_shot_1;
    u32 ptr_shot_23;
    u32 ptr_angleH;
    u32 ptr_angleW;
    u32 ptr_H;
    u32 ptr_W;
    u32 anim;
};

struct dds3BillResource_tag {
    sdfTexHandle_t *hTex;
    u16 type;
    u32 count;
    sdfVector2_t uv[4];
    f32 cx;
    f32 cy;
    f32 width;
    f32 height;
    sdfDrawTag_t *pBillTag;
    u16 current_mode;
    sdfMemHandle_t *hMem;
    dds3BillResource_tag *next;
    s32 number;
};

struct BillTable_t {
    char *pPath;
    char *pTexFile;
    s16 type;
    s16 mode;
};

struct dds3EffectTable_t {
    dds3EffectTable_t_CreateDelegate *Create;
    dds3EffectTable_t_DrawDelegate *Draw;
    dds3EffectTable_t_DeleteDelegate *Delete;
};

struct billHandle_t {
    sdfVector4_t pos;
    sdfVector4_t scale;
    f32 rot;
    u32 abgr;
    dds3EffectTable_t *tbl;
    u16 type;
    u16 mode;
    dds3Billboard_Normal_tag3 *pNormal;
    dds3Billboard_P2A_tag3 *pP2A;
    void *texture;
    f32 alf_raito;
    f32 bri_raito;
    XRD773Unity_CommonMesh *pMesh;
    s32 use_tmx_idx;
    char *callname;
};

struct dds3Billboard_Normal_tag3 {
    billHandle_t *basic;
    dds3BillResource_tag *hResource;
};

struct dds3Billboard_P2A_tag3 {
    billHandle_t *basic;
    dds3BillAnimResource_tag *hResource;
    dds3MultiBillResource_tag *MultiBillRes;
    u16 state;
    u32 mode;
    u32 number;
    u32 Anim_n;
    dds3BillAnim_tag *pAnim;
    u32 abgr;
    f32 rot;
};

struct dds3BillAnimResource_tag {
    sdfMemHandle_t *hMem;
    P2A_HEAD_t *pHeader;
    P2A_ANIMATION_tag *pAnimTable;
    u32 AnimNum;
    s32 TexNum;
    s32 count;
    dds3BillResource_tag *pResList;
    P2A_TEXANIM_tag **pTexAnimTable;
    u32 **pABGRTable;
};

struct dds3MultiBillResource_tag {
    dds3BillResource_tag *hBillRes;
    u16 type;
    u16 mode;
    u32 *abgr;
    sdfDrawTag_t *pBillTag;
    dds3MultiBillResource_tag *next;
};

struct P2A_HEAD_t {
    s32 tmxofs;
    s32 AnimNum;
};

struct dds3BillAnim_tag {
    dds3BillAnimResource_tag *hResource;
    s32 key;
    s32 wait;
    P2A_ANIMATION_tag *pAnim;
    P2A_TEXANIM_tag *pTexAnim;
};

struct P2A_ANIMATION_tag {
    u32 spranm;
    u32 alpha;
    u32 attr;
    u32 times;
    u32 mode;
};

struct P2A_TEXANIM_tag {
    s16 sx;
    s16 sy;
    s16 cx;
    s16 cy;
    s16 u1;
    s16 v1;
    s16 u2;
    s16 v2;
    s16 texid;
    s16 attr;
    f32 angle;
};

struct effBTL_FieldColorTable_t {
    f32 disp;
    sdfVector4_t light;
    u32 filter;
};

struct effBTL_FieldBaseColorTable_t {
    f32 disp;
    sdfVector4_t *light;
};

struct effBTL_SkillLight_t {
    effBTL_SkillPositionPtr_t *pos_ptr;
    u32 diffuse;
    u32 ambient;
    effBTL_SkillColorAnim_t *color_anim;
};

struct effBTL_SkillModel_t {
    u32 color;
    effBTL_SkillColorAnim_t *color_anim;
    u32 motion_timing;
};

struct effBTL_SkillPositionPtr_t {
    u8 target;
    u8 height;
    u8 direction;
    u8 dmy;
    u32 radius;
};

struct effBTL_SkillColorAnim_t {
    u32 fade_in_frame;
    u32 fade_in_pattern;
    u32 fade_out_frame;
    u32 fade_out_pattern;
    u32 anim_pattern;
};

struct effBTL_t {
    effBTL_SkillData_t *Skill;
    sdfMemHandle_t *hMem;
    u32 CutCount;
    effBTLCutHandle_t *hCutListTop;
};

struct effBTL_SkillData_t {
    char *version;
    effBTL_SkillCutTable_t *cut[2];
};

struct effBTLCutHandle_t {
    nbFormation_t *pFormation;
    effBTL_t *hBTLEffect;
    u32 frame;
    u32 cut_frame;
    u32 draw_frame;
    u16 cut;
    u32 stat;
    effBTL_SkillCutTable_t *pSkillCut;
    effPartHandle_t *hPart[60];
    effBTLCutHandle_t_MotionChangeCallbackDelegate *MotionChangeCallback;
    effBTLCutHandle_t_CutEndCallbackDelegate *CutEndCallback;
    void *pUserData;
    effBTLCutHandle_t *hCutListNext;
    f32 frameF;
};

struct effPartHandle_t {
    u16 type;
    void *pHandle;
};

struct effBTL_SkillCutTable_t {
    u32 frame;
    effBTL_SkillCamera_t *camera;
    effBTL_SkillLight_t *light;
    effBTL_SkillModel_t *model;
    effBTL_SkillField_t *field;
    effBTL_SkillSE_t *se;
    effBTL_SkillParts_t *parts;
};

struct effBTL_SkillCamera_t {
    u16 restriction;
    effBTL_SkillCameraShake_t *shake;
};

struct effBTL_SkillField_t {
    u32 color;
    effBTL_SkillColorAnim_t *color_anim;
};

struct effBTL_SkillSE_t {
    u16 reserve;
    u16 dmy;
    u32 timing;
};

struct effBTL_SkillParts_t {
    u16 number;
    u16 dmy0;
    u32 life;
    u8 scaling;
    u8 dmy1;
    u8 dmy2;
    u8 dmy3;
    effBTL_SkillPartsList_t *list[60];
};

struct effBTL_SkillCameraShake_t {
    u16 number;
    u16 timing;
    u16 life;
};

struct effBTL_SkillPartsList_t {
    u16 type;
    void *pHandle;
    u32 offset;
    effBTL_SkillPositionPtr_t *pos_ptr;
    u32 timing;
    u8 reverberations;
};

struct dds3EffectPCPData_Part_t {
    u32 size;
    u32 offset;
    u32 type;
    u32 reserve;
};

struct effPCPThunderSpherePolyLow_t {
    effPCPThunderSpherePolyParam_t *param;
    effPCPThunderSpherePolyPart_t *pPart;
    u32 abgr;
    f32 width_base;
    f32 height_base;
    dds3TrackPoly_t *hPoly;
    sdfMemHandle_t *hMem;
};

struct dds3TrackPoly_t {
    u16 type;
    u16 mode;
    s32 number;
    s32 point;
    s32 rec;
    sdfMemHandle_t *hMem;
    dds3TrackPolyList_t *trackList;
    sdfVector4_t *pVertex;
    u32 *pVC;
    sdfMat_t *pMat;
    dds3TrackPoly_t *next;
    dds3TrackPoly_t *d_next;
    XRD773Unity_CommonMesh *pMesh;
    f32 alf_raito;
};

struct effPCPThunderSpherePolyPart_t {
    u32 wait;
    u32 refresh;
    sdfVector3_t dir;
    sdfVector3_t axis;
    f32 rotate;
    f32 radius;
    u32 abgr;
};

struct dds3TrackPolyList_t {
    sdfVector4_t *pVertex;
    u32 *pVC;
    s32 count;
    s32 rec;
    u32 color;
};

struct effAPPoint4Param_t {
    sdfVector4_t *point;
    u8 loop;
    u32 number;
    s32 life;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 *radius;
    u32 *reserve;
};

struct effBezier4P_t {
    effBezier4PPart_t *pPart;
    u32 number;
    sdfMemHandle_t *hMem;
};

struct effBezier4PPart_t {
    sdfVector3_t point[4];
    f32 weight;
    f32 step;
};

struct effDistortionBlurHandle_t {
    dds3Effect_DistortionBlurParam_t *param;
    void *hAlphaTex;
    sdfMemHandle_t *hMem;
    dds3Effect_DistBlurPart_tag *pwork;
};

struct dds3Effect_DistortionBlurParam_t {
    u32 number;
    u32 interval;
    f32 speed;
    u32 abgr;
    s32 blend;
    f32 rotate;
    f32 distortion;
    sdfIVector2_t *center;
    s32 area;
    s32 width;
};

struct dds3Effect_PartialMultiBlur_t {
    dds3Effect_PartialMultiBlurParam_t *param;
    sdfTexHandle_t *hAlphaTex;
    XRD773Unity_CommonMesh *pMesh;
    void *rImage;
    s32 cntRT;
};

struct dds3Effect_PartialMultiFilter_t {
    dds3Effect_PartialMultiFilterParam_t *param;
    sdfTexHandle_t *hAlphaTex;
};

struct dds3Effect_RippleBlur_t {
    dds3Effect_RippleBlurParam_t *param;
    sdfTexHandle_t *hAlphaTex;
    sdfMemHandle_t *hMem;
    dds3Effect_RipBlurPart_tag *pwork;
};

struct dds3Effect_RippleBlurParam_t {
    u32 number;
    f32 speed;
    f32 interval;
    u32 abgr;
    s32 blend;
    f32 rotate;
    f32 power;
    f32 frequency;
    sdfIVector2_t *center;
    s32 area;
    f32 unitycalc_center_x;
    f32 unitycalc_center_y;
    f32 unitycalc_area;
};

struct effViewer_Menu_t {
    char *pName;
    sdfIVector2_t *pos;
    s32 cursor;
    effViewer_Menu_Item_t *pItem;
    s32 ItemNum;
    void *pParent;
    void *pParm;
    void *pParm_Def;
    s32 ParmSize;
    s32 run;
    effViewer_Menu_t_InitDelegate *Init;
    effViewer_Menu_t_DrawDelegate *Draw;
    effViewer_Menu_t_EndDelegate *End;
    void *ppArgument;
    effViewer_Menu_t_RefreshDelegate *Refresh;
};

struct effEVECombParSmokeParam_t {
    sdfVector4_t pos;
    u32 number;
    u32 life;
    s32 timing;
    s32 wait;
    f32 radius;
    u32 abgr;
    s32 blend;
    s32 fade_in;
    s32 fade_out;
    u8 loop;
    f32 scale;
    f32 scale_r;
    f32 scl_w;
    f32 scl_h;
    f32 scl_s;
    f32 roll_s;
    f32 up_s;
    f32 up_s_r;
    f32 shift_s;
    f32 shift_s_r;
    f32 accele;
    f32 angle_s;
    f32 amplitude;
    f32 amplitude_s;
    f32 amplitude_r;
    s32 color_t;
    s32 color_f;
};

struct effViewer_Menu_Item_t {
    char *pName;
    u8 type;
    void *p;
    s32 min;
    s32 max;
    s32 interval;
};

struct effMagatuhiParams_t {
    u32 number;
    u32 tail;
    f32 scale;
    u32 abgr_s;
    u32 abgr_e;
    u32 blend;
    f32 t;
};

struct effMagaSmokeConvParam_t {
    sdfVector4_t s_pos;
    sdfVector4_t c_pos;
    u8 loop;
    s32 life;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 s_radius;
    f32 s_up_s;
    f32 s_up_s_r;
    f32 s_angle_s;
    f32 s_ampli;
    f32 s_ampli_s;
    f32 s_ampli_r;
    f32 c_radius;
    f32 c_ampli;
    f32 c_step;
    f32 c_step_a;
    effMagatuhiParams_t *MagaParam;
    u32 reserve[64];
};

struct effMagaPoint4Param_t {
    sdfVector4_t point[4];
    u8 loop;
    s32 life;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radius[4];
    effMagatuhiParams_t *MagaParam;
    u32 reserve[64];
};

struct effMagaCylinderParam_t {
    sdfVector4_t pos;
    u8 loop;
    s32 life;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 rotate_s;
    f32 rotate_r;
    f32 height;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    effMagatuhiParams_t *MagaParam;
    u32 reserve[32];
};

struct effMagaSpiralParam_t {
    sdfVector4_t pos;
    u8 loop;
    s32 life;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 rotate_s;
    f32 rotate_r;
    f32 up_s;
    f32 up_r;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    effMagatuhiParams_t *MagaParam;
    u32 reserve[32];
};

struct effMagaSmokeParam_t {
    sdfVector4_t pos;
    u8 loop;
    s32 life;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radius;
    f32 up_s;
    f32 up_s_r;
    f32 angle_s;
    f32 ampli;
    f32 ampli_s;
    f32 ampli_r;
    effMagatuhiParams_t *MagaParam;
    u32 reserve[32];
};

struct effBezier7PPart_t {
    sdfVector3_t point[7];
    u32 segment;
    f32 weight;
    f32 step;
};

struct effEveBEDCutHandle_t {
    effEveBEDParams_t *pParams;
    evtUnitHandle_t *hUnit;
    effBTLCutHandle_t *hBTLCutEffect;
};

struct effEveBEDParams_t {
    sdfVector4_t center;
    sdfVector4_t rot;
    f32 r;
    f32 h;
    f32 scale;
    u32 abgr;
};

struct effPCPBezierBillParam_t {
    sdfVector4_t pos;
    u32 type;
    f32 radius;
    f32 depth;
    f32 height;
    u32 number;
    s32 life;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 width;
    u32 length;
    s32 split;
    u32 abgr_s_c;
    u32 abgr_s_e;
    u32 abgr_e_c;
    u32 abgr_e_e;
};

struct effPCPMuzzleFlashParam_t {
    f32 scale_h;
    f32 scale_w;
};

struct effPCPDANTE_Thunder_Param_t {
    effPCP_ThunderPolyParam_t *tp_param;
    u32 helper;
    s32 life;
    s32 fade_in;
    s32 fade_out;
};

struct effPCP_ThunderPoly_t {
    effPCP_ThunderPolyParam_t *param;
    effPCP_ThunderPolyPart_t *pPart;
    u32 abgr;
    u32 frame;
    dds3TrackPoly_t *hPoly;
    sdfMemHandle_t *hMem;
};

struct effPCP_ThunderPolyPart_t {
    u32 wait;
    u32 refresh;
    u32 abgr;
};

struct effPCPDANTE_Damage_Param_t {
    s32 life;
    s32 fade_in;
    s32 fade_out;
    u32 wait;
};

struct effPCP_PBCamera_Param_t {
    s32 life;
};

struct effPCPDANTE_ShowTime_Param_t {
    s32 reserve;
};

struct effPCP_BED_Param_t {
    s32 life;
    s32 fade_in;
    s32 fade_out;
};

struct effPCP_HBED2_Param_t {
    effPCPHelperBEDParam_t *hbed;
};

struct effPCPHelperBEDParam_t {
    sdfVector4_t pos;
    s32 fade_in;
    s32 fade_out;
    f32 speed;
};

struct effPCPFlashPolySphere2Param_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    s32 scale_f;
    u32 abgr_in;
    u32 abgr_out;
    f32 radius;
    u32 blend;
    u32 numberO;
};

struct dds3FlashPolyList_t {
    sdfMatrix4_t matrix;
    sdfVector4_t pos;
    u32 blend;
    u32 abgr;
    s32 point;
    f32 scale;
    sdfVector4_t *pVertex;
    u32 *pVC;
    sdfMat_t *pMat;
    sdfMemHandle_t *hMem;
    XRD773Unity_CommonMesh *pMesh;
    f32 alf_raito;
};

struct effPCPFlashPolyRingParam_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    s32 scale_f;
    u32 interval;
    u32 abgr_in;
    u32 abgr_out;
    f32 width_in;
    f32 width_out;
    f32 radius;
    f32 length;
    f32 spread;
    f32 rotate;
    u32 blend;
    u32 numberO;
};

struct effPCPFlashPolyPipeParam_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    u32 interval;
    s32 abgr_s;
    s32 abgr_e;
    u32 abgr_in;
    u32 abgr_out;
    f32 width_in;
    f32 width_out;
    f32 radius;
    f32 length;
    f32 spread;
    f32 rotate;
    f32 up_s;
    u32 blend;
    u32 numberO;
};

struct effPCPFlashPolyRingExpParam_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    u32 interval;
    s32 abgr_s;
    s32 abgr_e;
    u32 abgr_in;
    u32 abgr_out;
    f32 width_in;
    f32 width_out;
    f32 radius_s;
    f32 radius_e;
    f32 length_s;
    f32 length_e;
    f32 spread_s;
    f32 spread_e;
    f32 rotate;
    u32 blend;
    u32 numberO;
};

struct effPCPFlashPolySphereExpParam_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    s32 scale_f;
    u32 interval;
    u8 fix;
    s32 abgr_s;
    s32 abgr_e;
    u32 abgr_in;
    u32 abgr_out;
    f32 width_in;
    f32 width_out;
    f32 radius;
    f32 rotate;
    u32 blend;
    u32 numberO;
};

struct effPCPFlashPolySphere2ExpParam_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    s32 abgr_s;
    s32 abgr_e;
    u32 abgr_in;
    u32 abgr_out;
    f32 radius;
    f32 radius_s;
    f32 radius_a;
    u32 blend;
    u32 numberO;
};

struct effPCPFlashPolySphere3Param_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    u32 interval;
    s32 abgr_s;
    s32 abgr_e;
    u32 abgr_in;
    u32 abgr_out;
    f32 width;
    f32 width_r;
    f32 radius;
    f32 rotate;
    f32 move;
    f32 move_s;
    f32 move_a;
    u32 blend;
    u32 numberO;
    u32 reserve[32];
};

struct effPCPFlashPolyRingExp2Param_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    s32 scale_f;
    u32 interval;
    s32 abgr_s;
    s32 abgr_e;
    u32 abgr_in;
    u32 abgr_out;
    f32 width_in;
    f32 width_out;
    f32 radius;
    f32 length;
    f32 spread;
    f32 rotate;
    u32 blend;
    u32 numberO;
};

struct effPCPFlashPolyCircleParam_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    s32 life;
    s32 abgr_s;
    s32 abgr_e;
    u32 abgr_in;
    u32 abgr_out;
    f32 radius;
    f32 radius_s;
    f32 radius_a;
    f32 z;
    u32 blend;
    u32 numberO;
};

struct effPCPThunderSpherePoly_t {
    effPCPThunderSpherePolyParam_t *param;
    effPCPThunderSpherePolyPart_t *pPart;
    u32 abgr;
    f32 width_base;
    f32 height_base;
    dds3TrackPoly_t *hPoly;
    sdfMemHandle_t *hMem;
};

struct effPCPFilterExpParam_t {
    s32 life;
    s32 fade_in;
    s32 fade_out;
    dds3Effect_Filter_t *Filter;
};

struct effPCPBlurExpParam_t {
    s32 life;
    s32 fade_in;
    s32 fade_out;
    dds3Effect_Blur_t *Blur;
};

struct effPCPBreathParam_t {
    sdfVector4_t pos;
    s32 start;
    s32 life;
    s32 fade_out;
    f32 angle;
    f32 move;
};

struct effPCPAgiraoFireParam_t {
    sdfVector4_t pos;
    sdfVector2_t *offset;
    s32 *timing;
    s32 *part_timing;
};

struct dds3Effect_t {
    u32 major;
    u32 minor;
    void *pwork;
    f32 version;
};

struct effPCPAgiFireballParam_t {
    sdfVector4_t pos;
    s32 fade_in;
    s32 fade_out;
    f32 scale;
    s32 TrackCount[3];
    f32 TrackScale[3];
    f32 TrackScale_r[3];
    f32 TrackArea[3];
    s32 OkSmokeFrame;
};

struct effPCPAgiFireball2Param_t {
    s32 timing[3];
    effPCPAgiFireballParam_t *param[3];
};

struct effPCPRingPolyExpParam_t {
    sdfVector4_t pos;
    s32 fade_in;
    s32 fade_out;
    s32 wait;
    s32 life_a;
    u32 type_a;
    s32 life_r;
    f32 radius_s;
    f32 radius_e;
    u32 split;
    u32 blend;
    f32 width_e_in;
    u32 color_e_in;
    f32 width_c;
    u32 color_c;
    f32 width_e_out;
    u32 color_e_out;
};

struct effPCPRingPolyExp2Param_t {
    sdfVector4_t pos;
    f32 incline;
    f32 rotate;
    f32 rotate_s;
    f32 rotate_a;
    u8 type;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    f32 radius;
    f32 radius_s;
    f32 radius_a;
    u32 split;
    u32 blend;
    f32 width_e_in;
    u32 color_e_in;
    f32 width_c;
    u32 color_c;
    f32 width_e_out;
    u32 color_e_out;
};

struct effPCPRadiateThunderParam_t {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    u8 loop;
    s32 life;
    u32 number;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    f32 radian_s;
    f32 radian_a;
    f32 radian_r;
    f32 spread_s;
    f32 spread_e;
    effPCPRadiateThunderAttach_t *attach;
    effPCP_ThunderPolyParam_t *ThunderParam;
    u32 reserve[32];
};

struct effPCPRadiateThunderAttach_t {
    u8 use[4];
};

struct effPCPRadiateBEDParam_t {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    u8 loop;
    s32 life;
    u32 number;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    f32 radian_s;
    f32 radian_a;
    f32 radian_r;
    u32 reserve[32];
};

struct effPCPRadiateTBParam_t {
    sdfVector4_t pos;
    u8 loop;
    s32 life;
    u32 number;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radius;
    f32 radius_r;
    f32 rotate_s;
    f32 rotate_r;
    effPCP_ThunderPolyParam_t *ThunderParam;
};

struct effPCPSpiralBEDParam_t {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    u8 loop;
    s32 life;
    u32 number;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 rotate_s;
    f32 rotate_r;
    f32 rotate_a;
    f32 up_s;
    f32 up_r;
    f32 up_a;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    f32 height;
};

struct effPCPFLEACHBlurParam_t {
    dds3Effect_PartialMultiBlurParam_t *start;
    dds3Effect_PartialMultiBlurParam_t *end;
    s32 life;
    s32 fade_in;
    s32 fade_out;
};

struct effPCPNeedleSpiralParam_t {
    sdfVector4_t pos;
    u32 number;
    s32 life;
    u32 blend;
    s32 fade_in;
    s32 fade_out;
    u32 timing;
    f32 speed;
    f32 accele;
    f32 radius;
    f32 radius_r;
    f32 roll_s;
    u32 n_split;
    f32 n_radius;
    f32 n_length;
    u32 n_vc[2];
    f32 t_width;
    u32 t_length;
    u32 t_abgr;
};

struct effPCPHamaCardSpiralParam_t {
    sdfVector4_t pos;
    f32 tex_w;
    f32 tex_h;
    s32 blend;
    u8 loop;
    u32 number;
    u32 simu_num;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    s32 life;
    s32 wait;
    f32 up_s;
    f32 up_a;
    f32 roll_s;
    f32 roll_a;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    f32 up_r;
    u8 vibrate;
    f32 vib_power;
    u8 attach;
    s32 attach_f;
    u32 attach_i;
};

struct effPCPHamaCardSphereParam_t {
    sdfVector4_t pos;
    f32 tex_w;
    f32 tex_h;
    s32 blend;
    u8 loop;
    u32 number;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    s32 life;
    s32 wait;
    f32 roll_s;
    f32 roll_a;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    u8 vibrate;
    f32 vib_power;
    u8 attach;
    s32 attach_f;
    u32 attach_i;
};

struct effPCPHamaCardScatterParam_t {
    sdfVector4_t pos;
    f32 tex_w;
    f32 tex_h;
    s32 blend;
    u8 loop;
    u32 number;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    s32 life;
    s32 wait;
    f32 drop_s;
    f32 drop_a;
    u8 attach;
    s32 attach_f;
    u32 attach_i;
};

struct effPCPWhirlwindPolyParam_t {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    u32 blend;
    u8 loop;
    s32 life;
    u32 number;
    u32 split;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radian_w;
    f32 radian_w_r;
    f32 radian_w_u;
    f32 incline;
    f32 width;
    f32 width_r;
    f32 up_s;
    f32 up_a;
    f32 up_r;
    f32 roll_s;
    f32 roll_a;
    f32 radius_s;
    f32 radius_s_r;
    f32 radius_e;
    f32 radius_e_r;
    u32 abgr;
    u32 repeat_u;
    u32 repeat_v;
    u32 *reserve;
};

struct effPCPWhirlwind2PolyParam_t {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    u32 blend;
    u8 loop;
    s32 life;
    u32 number;
    u32 split;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radian_w;
    f32 radian_w_r;
    f32 radian_w_u;
    f32 incline;
    f32 width;
    f32 width_r;
    f32 up_s;
    f32 up_a;
    f32 up_r;
    f32 roll_s;
    f32 roll_a;
    f32 radius;
    f32 radius_r;
    f32 radius_s;
    f32 radius_s_r;
    f32 radius_a;
    u32 abgr;
    u32 repeat_u;
    u32 repeat_v;
    u32 *reserve;
};

struct effPCPWhirlwind3PolyParam_t {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    u32 blend;
    u8 loop;
    s32 life;
    u32 number;
    u32 split;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radian_w;
    f32 radian_w_r;
    f32 incline;
    f32 height;
    f32 slant;
    f32 width;
    f32 width_r;
    f32 up_s;
    f32 up_a;
    f32 up_r;
    f32 roll_s;
    f32 roll_a;
    f32 radius;
    f32 radius_r;
    f32 radius_s;
    f32 radius_s_r;
    f32 radius_a;
    u32 abgr_s;
    u32 abgr_e;
    u32 repeat_u;
    u32 repeat_v;
    u32 *reserve;
};

struct effPCPWwSpherePolyParam_t {
    sdfVector4_t pos;
    u32 blend;
    u8 loop;
    s32 life;
    u32 number;
    u32 split;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radian_w;
    f32 radian_w_r;
    f32 width;
    f32 width_r;
    f32 roll_s;
    f32 roll_a;
    f32 radius;
    f32 radius_r;
    f32 radius_s;
    f32 radius_a;
    s32 radius_aw;
    u32 abgr;
    u32 repeat_u;
    u32 repeat_v;
    u32 *reserve;
};

struct nbCamera_AllTable_t {
    f32 distance;
    f32 up;
    f32 radius;
};

struct nbCamera_t {
    sdfVector4_t target;
    sdfVector4_t direction;
    f32 distance;
    f32 fovy;
    u32 state_change;
    u32 state;
    u32 state_old;
    u32 state_old2;
    u32 phase;
    s32 frame;
    u32 type;
    f32 angle;
    nbCameraAnim_t *anim;
};

struct nbCameraAnim_t {
    s32 rotate_f;
    f32 rotate_s;
    s32 distance_f;
    f32 distance_s;
};

struct nbCameraSkillInfo_t {
    u32 shot_1;
    u32 shot_23;
    f32 angleH;
    f32 angleW;
    f32 HeightMin;
    f32 WidthMin;
    u32 ptr_1;
    u32 ptr_23;
    u32 anim;
};

struct nbCameraState_Start_t {
    effBezier4PPart_t *B4P_Target;
    effBezier4PPart_t *B4P_Eye;
};

struct dds3EffectTable_Reset_t {
    dds3EffectTable_Reset_t_ResetDelegate *Reset;
};

struct dds3EffectTable_Scale_t {
    dds3EffectTable_Scale_t_ScaleDelegate *Scale;
};

struct dds3Polygon_t {
    s16 type;
    s32 point;
    s32 strip_count;
    s32 count;
    sdfMemHandle_t *hMem;
    sdf3DPrimPolyParm_t *parm;
    sdfMat_t *pMat;
    sdfVector4_t *pVertex;
    sdfVector2_t *pUV;
    sdfVector4_t *pNormal;
    u32 *pVertexColor;
    dds3Polygon_t *next;
    dds3Polygon_t *d_next;
};

struct effEVECombParSmoke_t {
    effEVECombParSmokeParam_t *param;
    effEVECombParSmokePart_t *pPart;
    u8 Ztest;
    sdfMemHandle_t *hMem;
    XRD773Unity_CommonMesh *pMesh;
};

struct effEVECombParSmokePart_t {
    sdfVector4_t pos;
    sdfVector4_t dirUp;
    s32 frame;
    s32 wait;
    f32 scale;
    f32 s_w_r;
    f32 s_w_s;
    f32 s_w;
    f32 s_h_r;
    f32 s_h_s;
    f32 s_h;
    f32 roll;
    f32 roll_s;
    f32 amplitude;
    f32 angle;
    f32 up_s;
    f32 shift_s;
    u32 reserve;
};

struct dds3Billboard_Tex_t {
    sdfTexHandle_t *hTex;
    u16 *uv[2];
};

struct effBTL_SkillPBFileHeader_t {
    u32 size;
    u32 reserve[3];
    u8 *pbData;
    void *oData;
};

struct effBezier_t {
    sdfMemHandle_t *mh;
    u32 numpoint;
    sdfVector3_t *ppoint;
    u32 segment;
    f32 weight;
    f32 step;
};

struct dds3Effect_PartialBlur_t {
    s32 area;
    dds3Effect_Blur_t *Blur;
};

struct dds3Effect_DistortionBlur_t {
    dds3Effect_DistortionBlurParam_t *param;
    sdfTexHandle_t *hAlphaTex;
    sdfMemHandle_t *hMem;
    void *pwork;
};

struct effSimpleBED_t {
    effBTL_t *hBED;
    effEveBEDCutHandle_t *hCut;
    effEveBEDParams_t *pParams;
    u8 original;
};

struct effEveAPP4Point_t {
    sdfVector4_t *point;
    f32 *radius;
};

struct effMagaSCArea_t {
    sdfVector4_t s_center;
    sdfVector4_t c_center;
    f32 s_radius;
    f32 c_radius;
};

struct effMagaP4Point_t {
    sdfVector4_t point[4];
    f32 radius[4];
};

struct effBezier7P_t {
    effBezier7PPart_t *pPart;
    u32 number;
    sdfMemHandle_t *hMem;
};

struct Eff_ModelTrackPolyABGR_t {
    u32 s0;
    u32 s1;
    u32 e0;
    u32 e1;
};

struct Eff_ModelTrackPolyParam_t {
    dds3ModelHandle_t *hModel;
    u32 mark[2];
    f32 frame_s;
    f32 frame_e;
    u32 record;
    u32 face;
    u32 split;
    u32 blend;
    Eff_ModelTrackPolyABGR_t *abgr;
};

struct effSwordTrackParams_t {
    dds3ModelHandle_t *hModel;
    u32 *mark;
    u32 frame_s;
    u32 frame_e;
    u32 point;
    f32 step;
    u32 blend;
    u32 abgr;
    f32 slide;
    u32 sub_alpha_in;
    u32 sub_alpha_out;
};

struct dds3HermitianTrackPoly_tag {
    u32 blend;
    u32 abgr;
    s32 point;
    s32 count;
    s32 current;
    s32 split;
    sdfVector4_t *pVertex;
    u32 *pVC;
    sdfMat_t *pMat;
    sdfMemHandle_t *hMem;
    XRD773Unity_CommonMesh *pMesh;
};

struct Eff_ModelTrackPoly_tag {
    Eff_ModelTrackPolyParam_t *param;
    effSwordTrackParams_t *param_dante;
    u32 frame;
    f32 slide_par;
    dds3HermitianTrackPoly_tag *hPoly;
};

struct effMTPolyListHandle_t {
    Eff_ModelTrackPoly_tag *hPolyList;
    u32 number;
    sdfMemHandle_t *hMem;
};

struct effPkt2DTriStripParm_t {
    sdfGrTagRGBA_t *rgba;
    sdfGrTagSTQ_t *stq0;
    sdfGrTagXYZ2_t *xyz0;
    sdfGrTagSTQ_t *stq1;
    sdfGrTagXYZ2_t *xyz1;
    sdfGrTagSTQ_t *stq2;
    sdfGrTagXYZ2_t *xyz2;
    sdfGrTagSTQ_t *stq3;
    sdfGrTagXYZ2_t *xyz3;
};

struct effPkt2DF4Parm_t {
    sdfDmaTag_t *dmatag;
    sdfGifTag_t *giftag;
    u64 prim;
    u64 rgba0;
    u64 xyz0;
    u64 rgba1;
    u64 xyz1;
    u64 rgba2;
    u64 xyz2;
    u64 rgba3;
    u64 xyz3;
    u64 nop0;
    u64 nop1;
    u64 pad;
};

struct dds3EffectPCP_t {
    u32 kateg;
    u32 param;
    void *pHandle;
};

struct dds3EffectPCPData_t {
    u32 kateg;
    u32 param;
    u32 part;
    u32 reserve;
    dds3EffectPCPData_Part_t *pcpData;
};

struct EffBTL_BillFireball_Part_t {
    u32 wait;
    u32 frame;
    sdfVector4_t pos_add;
    f32 scale[2];
    u32 abgr;
    u32 alpha;
    u32 p2a_frame;
};

struct EffBTL_BillFireball_t {
    sdfVector4_t pos;
    sdfVector4_t vec;
    f32 scale;
    EffBTL_BillFireball_Part_t *Part[10];
    sdfMemHandle_t *hMem;
};

struct EffBTL_BillTrack_Part_t {
    sdfVector4_t pos;
    sdfVector4_t vec;
    f32 scale;
    f32 scale_s;
    f32 rot;
    f32 rot_s;
    f32 speed;
    u32 abgr;
    u32 use;
    u32 align;
};

struct EffBTL_BillTrack_t {
    sdfVector4_t pos;
    sdfVector4_t vec;
    u32 number;
    u32 simul;
    f32 scale;
    u32 point;
    EffBTL_BillTrack_Part_t *pPart;
    sdfMemHandle_t *hMem;
};

struct Eff_ThunderSpherePolyPart_t {
    u32 wait;
    u32 refresh;
    sdfVector3_t dir;
    sdfVector3_t axis;
    f32 rotate;
    f32 radius;
    u32 abgr;
};

struct Eff_ThunderSpherePolyParam_t {
    sdfVector4_t pos;
    u32 number;
    u8 loop;
    f32 width;
    f32 height;
    f32 refraction;
    s32 interval;
    s32 refresh;
    u16 split;
    f32 width_center;
    u32 color_center;
    f32 width_border;
    u32 color_border;
    f32 width_edge;
    u32 color_edge;
};

struct Eff_ThunderSpherePoly_t {
    Eff_ThunderSpherePolyParam_t *param;
    Eff_ThunderSpherePolyPart_t *pPart;
    u32 abgr;
    dds3TrackPoly_t *hPoly;
    sdfMemHandle_t *hMem;
};

struct Eff_ThunderPolyPart_t {
    u32 wait;
    u32 refresh;
    u32 abgr;
};

struct Eff_ThunderPolyParam_t {
    sdfVector4_t pos[2];
    u32 number;
    u8 loop;
    f32 refraction;
    s32 interval;
    s32 refresh;
    u16 split;
    f32 width_center;
    u32 color_center;
    f32 width_border;
    u32 color_border;
    f32 width_edge;
    u32 color_edge;
};

struct Eff_ThunderPoly_t {
    Eff_ThunderPolyParam_t *param;
    Eff_ThunderPolyPart_t *pPart;
    u32 abgr;
    dds3TrackPoly_t *hPoly;
    dds3TrackPoly_t *hPoly_c;
    sdfMemHandle_t *hMem;
};

struct Eff_ThunderRadiatePolyPart_t {
    sdfVector3_t dir;
    u32 wait;
    u32 refresh;
};

struct Eff_ThunderRadiatePolyParam_t {
    sdfVector4_t pos;
    f32 radius;
    u32 number;
    u8 loop;
    f32 refraction;
    s32 interval;
    s32 refresh;
    u16 split;
    f32 width_center;
    u32 color_center;
    f32 width_border;
    u32 color_border;
    f32 width_edge;
    u32 color_edge;
};

struct Eff_ThunderRadiatePoly_t {
    Eff_ThunderRadiatePolyParam_t *param;
    Eff_ThunderRadiatePolyPart_t *pPart;
    dds3TrackPoly_t *hPoly;
    sdfMemHandle_t *hMem;
};

struct Eff_RippleSprite_t {
    f32 rot;
    f32 rot_add;
    f32 size;
    u32 abgr;
    sdfIVector2_t *center;
};

struct Eff_Ripple_t {
    sdfIVector2_t *center;
    s32 area;
    u32 abgr;
    Eff_RippleSprite_t *sprite;
    effRippleBlurHandle_t *hRippleBlur;
    effDistortionBlurHandle_t *hDistortionBlur;
};

struct Eff_FlashPolyPart_t {
    u8 alpha;
    s32 wait;
    f32 rotate;
};

struct Eff_FlashPolyParam_t {
    sdfVector4_t pos;
    u32 number;
    u32 frame;
    u32 interval;
    u32 abgr;
    u32 alpha_s;
    f32 width;
    f32 radius;
    f32 rotate;
};

struct Eff_FlashPoly_t {
    Eff_FlashPolyParam_t *param;
    u32 frame;
    Eff_FlashPolyPart_t *pPart;
    dds3TrackPoly_t *hPoly;
    sdfMemHandle_t *hMem;
};

struct Eff_SparkleSphereBillParam_t {
    sdfVector4_t pos;
    u32 number;
    f32 radius;
    u32 abgr;
};

struct Eff_SparkleSphereBill_t {
    Eff_SparkleSphereBillParam_t *param;
    billHandle_t *hBillboard;
};

struct effPCP_ThunderColumnPolyLowParam_t {
    sdfVector4_t pos;
    effPCP_ThunderPolyParam_t *TP;
    f32 length;
    u32 number;
    u8 loop;
    s32 life;
    s32 timing;
    s32 fade_in;
    s32 fade_out;
    f32 radius;
    f32 radius_r;
    f32 height;
    f32 roll_s;
    f32 roll_r;
    f32 roll_a;
    f32 up_s;
    f32 up_r;
    f32 up_a;
};

struct effPCP_ThunderPolyListParam_t {
    sdfVector4_t pos[10];
    s32 point;
    effPCP_ThunderPolyParam_t *TPParam;
};

struct effPCPMultiBlurExp2Param_t {
    u8 type;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    s32 area_s;
    s32 area_e;
    dds3Effect_PartialMultiBlurParam_t *MultiBlur;
};

struct effPCPDistortionBlurExpParam_t {
    u8 type;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    s32 area_s;
    s32 area_e;
    dds3Effect_DistortionBlurParam_t *DistBlur;
};

struct effPCPRippleBlurExpParam_t {
    u8 type;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    s32 area_s;
    s32 area_e;
    dds3Effect_RippleBlurParam_t *RippleBlur;
};

struct effPCPAgiraoFirePartList_t {
    void *pD3PData[7];
};

struct effPCPAgiFireballPartList_t {
    void *pHelper;
    void *pAttach[5];
    void *pTrack[3];
    void *pStart[5];
    void *pOkSmoke;
};

struct effPCPAgiFireball2PartList_t {
    void *pHelper[3];
    effPCPAgiFireballPartList_t *PartList;
};

struct effPCPThunderSphereExpParam_t {
    s32 life;
    s32 fade_in;
    s32 fade_out;
    s32 radius_s;
    s32 radius_e;
    effPCPThunderSpherePolyParam_t *ThunderSpherePoly;
};

struct effPCPBossONGYParam_t {
    nbFormation_t *pFormation;
};

struct effPCPBossONGY2Param_t {
    nbFormation_t *pFormation;
};

struct effPCPBossBUNSINParam_t {
    nbFormation_t *pStartForm;
    nbFormation_t *pEndForm;
};

struct effPCPBossBUNSIN2Param_t {
    nbFormation_t *pStartForm;
    nbFormation_t *pForm1;
    nbFormation_t *pForm2L;
    nbFormation_t *pForm2R;
};

struct effPCPCrackParam_t {
    sdfVector4_t pos;
    u8 show;
    f32 speed;
    f32 scale;
    f32 width;
    s32 abgr_wait;
    s32 abgr_f;
    u32 abgr_s_in;
    u32 abgr_s_out;
    u32 abgr_e_in;
    u32 abgr_e_out;
    u32 blend;
    u8 f_show;
    u8 f_type;
    s32 f_wait;
    s32 f_timing;
    s32 f_life;
    s32 f_fade_in;
    s32 f_fade_out;
    s32 f_scale;
    f32 f_length;
    f32 f_length_r;
    f32 f_width_in;
    f32 f_width_out;
    f32 f_width_r;
    s32 f_abgr_wait;
    s32 f_abgr_f;
    u32 f_abgr_s_in;
    u32 f_abgr_s_out;
    u32 f_abgr_e_in;
    u32 f_abgr_e_out;
    u32 f_blend;
    u8 f_dir;
};

struct effPCPBossBaelParam_t {
    sdfVector4_t pos;
};

struct effPCPBossDengekiParam_t {
    effPCP_ThunderPolyParam_t *TPParam;
    f32 scale;
};

struct effPCPBossThunderboltParam_t {
    sdfVector4_t pos;
    effPCP_ThunderPolyParam_t *TPParam;
};

struct effPCPBossKAGUInvokeParam_t {
    sdfVector4_t **point;
    effPCP_ThunderPolyParam_t *TPParam;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    u32 number;
};

struct effPCPBossKAGUAttackParam_t {
    effPCP_ThunderPolyParam_t *TPParam;
    f32 scale;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    u32 number;
    f32 rand;
};

struct effPCPBossKAGUThunderboltParam_t {
    sdfVector4_t pos;
    effPCP_ThunderPolyParam_t *TPParam;
    effPCPCrackParam_t *CrackParam;
    f32 scale;
    s32 life;
    s32 fade_in;
    s32 fade_out;
};

struct effPCPBossKAGU2AttackParam_t {
    effPCP_ThunderPolyParam_t *TPParam;
    f32 scale;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    u32 number;
    f32 rand;
};

struct effPCPBossKAGU2MUHENKParam_t {
    s32 dmy;
};

struct effPCPCrack2Param_t {
    effPCPCrackParam_t *crack;
    s32 rotate_w;
    f32 rotate_s;
};

struct effPCPBossMETATOBeamParam_t {
    sdfVector4_t pos;
    effPCP_ThunderPolyParam_t *TPParam;
    s32 life;
    s32 fade_in;
    s32 fade_out;
};

struct effPCPScreenCrackModelParam_t {
    f32 speed;
};

struct effPCP_object_Param_t {
    u8 *hData;
    s32 offset;
};

struct effPCPBossONGY_t {
    effPCPBossONGYParam_t *param;
    sdfMat_t *pMat;
    f32 radian;
    s32 frame;
};

struct effPCPBossONGY2_t {
    effPCPBossONGY2Param_t *param;
    sdfMat_t *pMat;
    f32 radian;
    s32 frame;
};

struct effPCPBossBUNSIN_t {
    sdfVector4_t pos_s;
    sdfVector4_t pos_e;
    effPCPBossBUNSINParam_t *param;
    sdfVector4_t pMat[4];
    f32 radian;
    s32 frame;
    XRD773Unity_CommonMesh *pMesh;
};

struct effPCPBossBUNSIN2_t {
    effPCPBossBUNSIN2Param_t *param;
    s32 frame;
    u32 process;
    effPCPBossBUNSIN_t *pCut1;
    effPCPBossBUNSIN_t *pCut2_1;
    effPCPBossBUNSIN_t *pCut2_2;
};

struct effPCPCrackPartFlash_t {
    f32 length;
    f32 width_in;
    f32 width_out;
    s32 frame;
    u8 type;
};

struct effPCPCrackPart_t {
    dds3FlashPolyList_t *hFlash;
    sdfVector4_t dir;
    f32 rotate;
    s32 rotate_w;
    f32 rotate_add;
    effPCPCrackPartFlash_t *pSize;
};

struct effPCPCrack_t {
    effPCPCrackParam_t *param;
    effPCPCrackPart_t *pPart;
    sdfMemHandle_t *hPartMem;
    s32 MarkCount;
    u16 MarkLength;
    s32 frame;
    u32 abgr;
    dds3TrackPoly_t *hPoly;
    effPartHandle_t *hHelper;
};

struct effPCPBossBael_t {
    sdfVector4_t target;
    effPCPBossBaelParam_t *param;
    s32 frame;
    u32 abgr;
    effPartHandle_t *hPB;
    effPartHandle_t *hPCF;
};

struct effPCPBossDengeki_t {
    effPCPBossDengekiParam_t *param;
    effPCP_ThunderPolyList_t *pTPList;
    effBTL_t *hBED;
    effEveBEDCutHandle_t *hBEDCut;
    s32 frame;
    u32 abgr;
};

struct effPCP_ThunderPolyList_t {
    effPCP_ThunderPolyListParam_t *param;
    effPCP_ThunderPoly_t *pTP;
    u32 abgr;
};

struct effPCPBossThunderbolt_t {
    effPCPBossThunderboltParam_t *param;
    effPCP_ThunderPolyList_t *pTPolyList;
    s32 frame;
    u32 abgr;
};

struct effPCPBossKAGUInvoke_t {
    effPCPBossKAGUInvokeParam_t *param;
    effPCP_ThunderPolyList_t *pTPList[24];
    u32 point[2];
    s32 frame;
    u32 abgr;
    sdfMemHandle_t *hMem;
};

struct effPCPBossKAGUAttack_t {
    effPCPBossKAGUAttackParam_t *param;
    effPCP_ThunderPolyList_t *pTPList[32];
    effBTL_t *hBED;
    effEveBEDCutHandle_t *hBEDCut;
    s32 frame;
    u32 abgr;
};

struct effPCPBossKAGUThunderbolt_t {
    effPCPBossKAGUThunderboltParam_t *param;
    effPCP_ThunderPolyList_t *pTPolyList;
    effPCPCrack_t *pCrack;
    effBTL_t *hBED;
    effEveBEDCutHandle_t *hBEDCut;
    s32 frame;
    u32 abgr;
};

struct effPCPBossKAGU2Attack_t {
    effPCPBossKAGU2AttackParam_t *param;
    effPCP_ThunderPolyList_t *pTPList[16];
    effBTL_t *hBED;
    effEveBEDCutHandle_t *hBEDCut;
    s32 frame;
    u32 abgr;
};

struct effPCPBossKAGU2MUHENK_t {
    effPCPBossKAGU2MUHENKParam_t *param;
    s32 frame;
    u32 abgr;
};

struct effPCPBossMETATOBeam_t {
    effPCPBossMETATOBeamParam_t *param;
    effPCP_ThunderPolyList_t *pTPolyList[2];
    s32 frame;
    u32 abgr;
};

struct effPCPScreenCrackModel_t {
    effPCPScreenCrackModelParam_t *param;
    effPartHandle_t *hModel;
    s32 frame;
    u32 abgr;
};

struct EffTable_t {
    s16 number;
    s16 type;
};

struct dds3Particle_BlurBuffList_t {
    sdfVector4_t *pPos;
    u16 count;
    u32 abgr;
    f32 scale;
};

struct dds3Particle_BlurBuff_t {
    u16 number;
    u16 point;
    dds3Particle_BlurBuffList_t *blurList;
    billHandle_t *pBill_Handle;
    sdfMemHandle_t *hMem;
};

struct dds3Particle_Blur_t {
    u16 length;
    dds3Particle_BlurBuff_t *hBlur;
};

struct dds3Particle_Track_t {
    u16 length;
    f32 width;
    u32 color;
    dds3TrackPoly_t *hTrackPoly;
};

struct dds3Particle_Track2_t {
    u16 length;
    f32 width;
    u32 color_in;
    u32 color_out;
    dds3TrackPoly_t *hTrackPoly;
};

struct dds3Particle_Track3_t {
    u16 length;
    f32 width;
    u32 color_s;
    u32 color_e;
    effMTPolyListHandle_t *hTrackPoly;
};

struct dds3Particle_EffItem_t {
    dds3Particle_Track3_t *track3;
    dds3Particle_Track2_t *track2;
    dds3Particle_Track_t *track;
    dds3Particle_Blur_t *blur;
};

struct dds3Particle_Effect_t {
    u16 type;
    dds3Particle_EffItem_t *param;
};

struct dds3ParticleColorAnim_t {
    u32 type;
    u32 color[3];
    u32 alpha;
    s32 alpha_s;
    s32 alpha_e;
    s32 frame_end;
    s32 frame_h;
    f32 r_add[2];
    f32 g_add[2];
    f32 b_add[2];
    u32 alpha_s_add;
    u32 alpha_e_sub;
};

struct dds3Particle_Expansion_t {
    f32 scl;
    f32 rot_s;
    f32 scl_r;
    f32 rot_r;
    u8 rot_type;
};

struct dds3Particle_Basic_t {
    sdfVector4_t pos;
    sdfVector4_t scale;
    u32 number;
    u32 numberO;
    s32 frame;
    u32 billno;
    u16 billmode;
    dds3Particle_Effect_t *effect;
    dds3ParticleColorAnim_t *color;
    dds3Particle_Expansion_t *exp;
    u32 struct_size;
    u32 d_frame;
    sdfMatrix4_t rot;
    u32 abgr;
    billHandle_t *hBillboard;
    dds3Particle_Physics_t *hPhysics;
    u32 empty_loop;
    sdfMatrix4_t rot_b;
    u16 type;
    u16 state;
    f32 par_scl_raito;
    f32 eff_scl_raito;
    dds3Particle_Spiral_t3 *pSpiral;
    dds3Particle_Smoke_t3 *pSmoke;
    dds3Particle_Spark_t3 *pSpark;
    dds3Particle_Radiate_t3 *pRadiate;
    dds3Particle_SphereSpiral_t3 *pSphereSpiral;
    dds3Particle_SphereSmoke_t3 *pSphereSmoke;
    dds3Particle_SphereRing_t3 *pSphereRing;
    dds3Particle_Spark2_t3 *pSpark2;
    dds3Particle_SphereAtom_t3 *pSphereAtom;
    dds3Particle_Nop_t3 *pNop;
    dds3Particle_SparkOffset_t3 *pSparkOffset;
    dds3Particle_SmokeOffset_t3 *pSmokeOffset;
    dds3Particle_SphereSpiral2_t3 *pSphereSpiral2;
    s32 uniqueid;
};

struct dds3Particle_Physics_t {
    sdfMemHandle_t *hMem;
    parPhysics_t *pPhysics;
};

struct dds3Particle_Spiral_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 timing;
    f32 radius;
    u32 simu_num;
    f32 up_s;
    f32 roll_s;
    f32 radius_e;
    f32 accele;
    f32 radius_s_r;
    f32 radius_e_r;
};

struct dds3Particle_Smoke_t3 {
    dds3Particle_Basic_t *basic;
    u8 loop;
    s32 timing;
    f32 radius;
    f32 up_s;
    f32 angle_s;
    f32 amplitude;
    f32 amplitude_s;
    f32 accele;
    f32 up_s_r;
    f32 ampli_r;
};

struct dds3Particle_Spark_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 timing;
    u8 random;
    f32 radius;
    f32 spread;
    f32 gravity;
    f32 speed;
    f32 accele;
    f32 speed_r;
};

struct dds3Particle_Radiate_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 interval;
    u8 random;
    u32 split;
    f32 angle;
    f32 speed;
};

struct dds3Particle_SphereSpiral_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 timing;
    f32 radius;
    f32 roll_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
};

struct dds3Particle_SphereSmoke_t3 {
    dds3Particle_Basic_t *basic;
    u8 loop;
    s32 timing;
    f32 radius;
    f32 up_s;
    f32 angle_s;
    f32 amplitude;
    f32 amplitude_s;
    f32 accele;
    f32 up_s_r;
    f32 ampli_r;
    f32 radius_s_r;
};

struct dds3Particle_SphereRing_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 timing;
    f32 radius;
    f32 radius_r;
    u32 simu_num;
    f32 roll_s;
};

struct dds3Particle_Spark2_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 timing;
    u8 random;
    f32 radius;
    f32 spread;
    f32 gravity;
    f32 speed;
    f32 accele;
    f32 speed_r;
    f32 angle;
    f32 reserve1;
    f32 reserve2;
};

struct dds3Particle_SphereAtom_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 timing;
    f32 radius;
    f32 radius_e;
    f32 speed;
    f32 accele;
};

struct dds3Particle_Nop_t3 {
    dds3Particle_Basic_t *basic;
};

struct dds3Particle_SparkOffset_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 timing;
    u8 random;
    f32 radius;
    f32 spread;
    f32 gravity;
    f32 speed;
    f32 accele;
    f32 speed_r;
    u32 reserve[4];
};

struct dds3Particle_SmokeOffset_t3 {
    dds3Particle_Basic_t *basic;
    u8 loop;
    s32 timing;
    f32 radius;
    f32 up_s;
    f32 angle_s;
    f32 amplitude;
    f32 amplitude_s;
    f32 accele;
    f32 up_s_r;
    f32 ampli_r;
    sdfVector4_t *pOffset;
    sdfMemHandle_t *hOffsetMem;
    u32 reserve[32];
};

struct dds3Particle_SphereSpiral2_t3 {
    dds3Particle_Basic_t *basic;
    u8 type;
    u8 loop;
    s32 timing;
    f32 radius;
    f32 roll_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    dds3ParOffsetBuff_t *OffBuff;
    sdfVector4_t old_pos;
};

struct dds3ParOffsetBuff_t {
    dds3ParOffsetBuffParts_t *pParts;
    u32 length;
    sdfMemHandle_t *hMem;
};

struct parPhysics_t {
    sdfVector4_t pos;
    sdfVector4_t dir;
    s32 frame;
    u32 color;
    f32 scale;
    f32 rot;
    sdfVector4_t val_f;
};

struct dds3ParOffsetBuffParts_t {
    u32 point;
    u32 count;
    sdfVector3_t *pPosBuff;
};

struct dds3Particle_Exp_t {
    u32 type;
    u32 size;
    u32 reserve1;
    u32 reserve2;
};

struct dds3TrianglePoly_t {
    s32 number;
    u32 abgr;
    sdfVector4_t *pVertex;
    u32 *pVC;
    sdfMat_t *pMat;
    sdfMemHandle_t *hMem;
};

struct dds3SpPoly_Basic_t {
    sdfVector4_t pos;
    u32 number;
    s32 frame;
    u32 struct_size;
    u32 d_frame;
    sdfMatrix4_t rot;
    u32 abgr;
    u8 loop;
    u16 mode;
    u32 alpha_s;
    u32 alpha_e;
    sdfMatrix4_t rot_b;
    u16 type;
    u16 state;
    dds3SpPoly_Ring_Old_t3 *pRing_Old;
    dds3SpPoly_Ring_t3 *pRing;
    dds3SpPoly_SphereRing_t3 *pSphereRing;
    dds3SpPoly_RollRing_t3 *pRollRing;
};

struct dds3SpPoly_Ring_Old_t3 {
    dds3SpPoly_Basic_t *basic;
    u8 loop;
    u8 type;
    s32 interval;
    u16 split;
    f32 width;
    f32 speed;
    u32 color_in;
    u32 color_out;
    dds3TrackPoly_t *hTrackPoly;
    dds3SpPoly_Ring_Old_Physics_t *pPhysics;
};

struct dds3SpPoly_Ring_t3 {
    dds3SpPoly_Basic_t *basic;
    s32 timing;
    u32 vertex;
    f32 width;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    f32 up_s;
    f32 up_a;
    u32 color_edge_in;
    u32 color;
    u32 color_edge_out;
    dds3TrackPoly_t *hTrackPoly;
    dds3SpPoly_RingPhysics_t *pPhysics;
    sdfMemHandle_t *hMem;
};

struct dds3SpPoly_SphereRing_t3 {
    dds3SpPoly_Basic_t *basic;
    s32 timing;
    u32 vertex;
    f32 width;
    f32 radius;
    f32 radius_r;
    u32 color_edge_in;
    u32 color;
    u32 color_edge_out;
    dds3TrackPoly_t *hTrackPoly;
    dds3SpPoly_SphereRingPhysics_t *pPhysics;
    sdfMemHandle_t *hMem;
};

struct dds3SpPoly_RollRing_t3 {
    dds3SpPoly_Basic_t *basic;
    s32 timing;
    u32 vertex;
    f32 width;
    f32 radius_s;
    f32 radius_e;
    f32 radius_s_r;
    f32 radius_e_r;
    u32 simu_num;
    f32 incline;
    f32 roll_s;
    u32 color_edge_in;
    u32 color;
    u32 color_edge_out;
    dds3TrackPoly_t *hTrackPoly;
    dds3SpPoly_RollRingPhysics_t *pPhysics;
    sdfMemHandle_t *hMem;
};

struct dds3SpPoly_Ring_Old_Physics_t {
    s32 frame;
};

struct dds3SpPoly_RingPhysics_t {
    s32 frame;
    f32 spread_s;
};

struct dds3SpPoly_SphereRingPhysics_t {
    s32 frame;
    u32 radius;
};

struct dds3SpPoly_RollRingPhysics_t {
    s32 frame;
    f32 radius;
    f32 spread_s;
    f32 rot_x;
    f32 rot_y;
};

struct parToolItem_t {
    char *pName;
    u8 type;
    intptr_t p;
    s32 min;
    s32 max;
};

struct parToolMenu_t {
    s32 x;
    s32 y;
    s32 width;
    s32 line;
    s32 cursor;
    parToolItem_t *pItem;
    s32 ItemNum;
    s32 ParentShow;
    parToolMenu_t *pParent;
};

struct effFileItem_tag {
    s32 type;
    char *filename;
    effFileItem_tag *prev;
    effFileItem_tag *next;
};

struct effFileList_tag {
    s32 number;
    char *pDir;
    effFileItem_tag *pItem;
};

struct parToolMenu_tag {
    s32 x;
    s32 y;
    s32 width;
    s32 line;
    s32 cursor;
    parToolItem_t *pItem;
    s32 ItemNum;
    s32 ParentShow;
    parToolMenu_tag *pParent;
};

struct parToolColorTable_t {
    u32 *color;
    s32 type;
};

struct parToolColorWin_tag {
    s32 stat;
    s32 type;
    s32 mode;
    s32 x;
    s32 y;
    s32 cursor;
    parToolColorTable_t color;
};

struct effFLWin_tag {
    s32 x;
    s32 y;
    s32 stat;
    s32 line;
    s32 top;
    s32 pos;
    s32 cursor;
    s32 view;
    s32 padwait;
    s32 ot;
    u32 frame_color;
    u32 bg_color;
    effFileItem_tag *pTopItem;
    effFileItem_tag *pSelectItem;
    effFileItem_tag *pViewItem;
    sdfTexHandle_t *hTMXViewTex;
    effFileList_tag *hEffFileList;
};

struct effPCP_ThunderColumnPolyLowPart_t {
    s32 frame;
    f32 up;
    f32 up_s;
    f32 rotate;
    f32 rotate_s;
    f32 radius;
    f32 height;
    dds3TrackPoly_t *hPoly;
};

struct effPCP_ThunderColumnPolyLow_t {
    effPCP_ThunderColumnPolyLowParam_t *param;
    effPCP_ThunderColumnPolyLowPart_t *pPart;
    u32 abgr;
    sdfMemHandle_t *hMem;
};

struct effPCP_ThunderPolyLow_t {
    effPCP_ThunderPolyParam_t *param;
    effPCP_ThunderPolyPart_t *pPart;
    u32 abgr;
    dds3TrackPoly_t *hPoly;
    dds3TrackPoly_t *hPoly_c;
    sdfMemHandle_t *hMem;
};

struct effPCP_ThunderRadiatePolyPart_t {
    sdfVector3_t dir;
    u32 wait;
    u32 refresh;
};

struct effPCP_ThunderRadiatePoly_t {
    effPCP_ThunderRadiatePolyParam_t *param;
    effPCP_ThunderRadiatePolyPart_t *pPart;
    u32 abgr;
    dds3TrackPoly_t *hPoly;
    sdfMemHandle_t *hMem;
};

struct dds3P2APolygonResource_tag {
    u32 type;
    dds3BillResource_tag *hResource;
};

struct dds3P2APolygon_tag {
    sdfMatrix4_t dir;
    sdfMatrix4_t rot;
    billHandle_t *hBillboard;
    sdfMat_t *pMat;
};

typedef struct effBezier_t effBezier;
