#include "types.h"

typedef struct datDevilFormat_s datDevilFormat_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbPanelFlashData_t nbPanelFlashData_t;
typedef struct nbPanelProcess_NBPANEL_ANALIZE nbPanelProcess_NBPANEL_ANALIZE;
typedef struct nbPanelProcess_NBPANEL_PGE nbPanelProcess_NBPANEL_PGE;
typedef struct nbPanelProcess_NBPANEL_PTAP nbPanelProcess_NBPANEL_PTAP;
typedef struct nbPanelProcess_NBPANEL_PTF_1 nbPanelProcess_NBPANEL_PTF_1;
typedef struct nbPanelProcess_NBPANEL_PTF_2 nbPanelProcess_NBPANEL_PTF_2;
typedef struct nbPanelProcess_NBPANEL_PTF_3 nbPanelProcess_NBPANEL_PTF_3;
typedef struct nbPanelProcess_NBPANEL_PTP_0 nbPanelProcess_NBPANEL_PTP_0;
typedef struct nbPanelProcess_NBPANEL_PTP_1 nbPanelProcess_NBPANEL_PTP_1;
typedef struct nbPanelProcess_NBPNL_TMX nbPanelProcess_NBPNL_TMX;
typedef struct nbPanelProcess_nbPanelTMXuv_t nbPanelProcess_nbPanelTMXuv_t;
typedef struct nbPanelProcess_nbPanelXYZ_t nbPanelProcess_nbPanelXYZ_t;
typedef struct nbPanelProcess_typeNbPnlWork nbPanelProcess_typeNbPnlWork;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct nbPanelProcess_typeNbPnlWork {
    s32 ActiveMode;
    s32 OfsX;
    s32 OldHp;
    s32 OldMp;
    s32 HpAnmCnt;
    s32 MpAnmCnt;
};

struct nbPanelProcess_nbPanelXYZ_t {
    s32 xyz[3];
    s32 wh[2];
};

struct nbPanelProcess_nbPanelTMXuv_t {
    s32 uv[2];
    s32 wh[2];
};

struct nbPanelProcess_NBPNL_TMX {
    s32 value__;
};

struct nbPanelProcess_NBPANEL_PGE {
    s32 value__;
};

struct nbPanelProcess_NBPANEL_PTF_1 {
    s32 value__;
};

struct nbPanelProcess_NBPANEL_PTF_2 {
    s32 value__;
};

struct nbPanelProcess_NBPANEL_PTF_3 {
    s32 value__;
};

struct nbPanelProcess_NBPANEL_PTP_0 {
    s32 value__;
};

struct nbPanelProcess_NBPANEL_PTP_1 {
    s32 value__;
};

struct nbPanelProcess_NBPANEL_PTAP {
    s32 value__;
};

struct nbPanelProcess_NBPANEL_ANALIZE {
    s32 value__;
};

static u32 NBPNL_Z_MAX;
static f32 NBPANEL_PRESS_RATE_S;
static f32 NBPANEL_PRESS_RATE;
static u32 NBPANEL_PRESS_1_ALPHA;
static f32 NBPANEL_PRESS_1_RATE_S;
static f32 NBPANEL_PRESS_1_RATE;
static f32 NBPANEL_PRESS_2_ALPHA;
static f32 NBPANEL_PRESS_2_RATE_S;
static f32 NBPANEL_PRESS_2_RATE;
static u32 NBPANEL_PRESS_3_ALPHA;
static f32 NBPANEL_PRESS_3_RATE_S;
static f32 NBPANEL_PRESS_3_RATE;
static nbPanelProcess_typeNbPnlWork *gnbPnlWork[4];
static sdfMemHandle_t *hnbPnlFile1;
static void *pnbPnlFile1;
static sdfMemHandle_t *hnbPnlFile2;
static void *pnbPnlFile2;
static sdfMemHandle_t *hnbPnlFile3;
static void *pnbPnlFile3;
static sdfMemHandle_t *hnbPnlFile4;
static void *pnbPnlFile4;
static s32 gnbPnlOtOfs;
static s32 nbPnlDrawFlag;
static f32 nbPnlCnt;
static s32 bpturnCnt;
static s32 bpturnDrawFlag;
static nbPanelProcess_nbPanelXYZ_t *nbPanelPTPartList[11];
static u32 nbPanelBaseABGR;
static u32 nbPanelBaseRGBA;
static u32 NBPNL_PP_CUT_HP;
static u32 NBPNL_PP_CUT_MP;
static u32 NBPNL_PP_CUT_BOTTOM;
static u32 NBPNL_PP_CUT_ORDER_P;
static u32 NBPNL_PP_CUT_BAD;
static u32 NBPNL_PP_SELECT;
static u32 NBPNL_PP_SELECT_R;
static f32 NBPANEL_PRESS_SCALE_HEAD;
static f32 NBPANEL_PRESS_SCALE_BODY;
static u32 NBPANEL_PRESS_B_FRAME;
static u32 NBPANEL_PRESS_B_FRAME_M;
static f32 NBPANEL_PRESS_B_SCALE;
static u32 NBPANEL_PRESS_B_BLUR_A;
static u32 NBPANEL_PRESS_E_BLUR_A;
static f32 NBPANEL_PRESS_E_SCALE;
static u32 nbPanelPGPress;
static u32 nbPanelPGNumber;
static u32 nbPanelPGTurn;
static u32 nbPanelPGTurnOld;
static s32 nbPanelPGFrame;
static s32 nbPanelPGBirthWait;
static u8 nbPanelPGStart;
static s32 nbPanelPGShow;
static s32 nbPanelPGEncount;
static u32 nbPanelPGBaseColor;
static s32 nbPanelPressGauge_GaugeNumber;
static s32 nbPanelPressGauge_GaugeNormal;
static s32 nbPanelPressGauge_GaugeBlink;
static s32 nbPanelPressGauge_GaugeFlash;
static bool nbPanelPressGauge_PlusSkillOn;
static s32 nbPanelPTOmit;
static u32 nbPanelPT_1_Process;
static s32 nbPanelPT_1_Frame;
static u32 nbPanelPT_2_Process;
static s32 nbPanelPT_2_Frame;
static f32 nbPanelPT_2_Rate;
static u32 nbPanelPT_3_Process;
static s32 nbPanelPT_3_Frame;
static f32 nbPanelPT_3_Rate;
static u32 NBPANEL_PRESS_PTP_0_RGBA;
static s32 nbPanelPTP_0_Frame;
static u32 nbPanelPTP_0_Process;
static u32 nbPanelPTP_0_ABGR;
static void *nbPanelPTP_0_Obj;
static u32 NBPANEL_PRESS_PTP_1_RGBA;
static f32 NBPANEL_PRESS_PTP_1_Z_S_U;
static f32 NBPANEL_PRESS_PTP_1_Z_S_D;
static u32 NBPANEL_PRESS_PTP_1_ZC;
static f32 NBPANEL_PRESS_PTP_1_ZC_S_U;
static f32 NBPANEL_PRESS_PTP_1_ZC_S_D;
static u32 NBPANEL_PRESS_PTP_1_R;
static f32 NBPANEL_PRESS_PTP_1_R_R;
static f32 NBPANEL_PRESS_PTP_1_R_S_U;
static f32 NBPANEL_PRESS_PTP_1_R_S_D;
static f32 NBPANEL_PRESS_PTP_1_SHIFT_U_R;
static u32 NBPANEL_PRESS_PTP_1_SHIFT_U_A;
static s32 nbPanelPTP_1_Frame;
static u32 nbPanelPTP_1_Process;
static f32 nbPanelPTP_1_Rate;
static f32 NBPANEL_PRESS_TPA_1_S_R;
static f32 NBPANEL_PRESS_TPA_1_E_R;
static u32 nbPanelPTAProcess;
static s32 nbPanelPTAFrame;
static f32 nbPanelPTARate_S;
static f32 nbPanelPTARate_E;
static u8 nbPanelPTAOnly;
static s32 nbPanelStockRun;
static s32 nbPanelStockPad;
static u32 nbPanelStockABGR;
static s32 nbPanelStockFadeFlag;
static s32 nbPanelStockFrame;
static s32 nbPanelStockShiftX;
static u32 StockIDList[16];
static s32 StockIDListCount;
static s32 StockIDListCursor;
static s32 StockIDListTop;
static f32 NBPANEL_ANALIZE_ANIM_ACCELE;
static f32 NBPANEL_ANALIZE_ANIM_SHIFT_E_F;
static f32 NBPANEL_ANALIZE_ANIM_BTM_E_F;
static u32 nbPanelAnalyzeProcess;
static s32 nbPanelAnalyzeFrame;
static f32 nbPanelAnalyzeRate;
static datUnitWork_t *pNbPanelAnalyzeUnitWork;
static u32 PanelAutoABGR;
static u32 PanelAutoBaseColor;
static s32 PanelAutoShow;
static s32 PanelPartyShow;
static bool Wait_Skill_Doutyo;
static u32 NBPANEL_FLASH_1_ALPHA;
static u32 NBPANEL_FLASH_2_ALPHA;
static u32 NBPANEL_FLASH_3_ALPHA;

datDevilFormat_t *Analyze(s32 id);
void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
u8 Get(s32 id);
void *GetBattleUI(s32 index);
char *GetLocalizeText(char *ID);
void PnlAnim(void *mAnimator, char *name, s32 num);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__MULVECTOR(void);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void StkSelDisp(bool show);
s32 datCheckDying(datUnitWork_t *work);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool effBTLSkillCheckRun2(u32 skillid);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
u32 effColorMultiply(u32 abgr0, u32 abgr1);
char *frGetCNameString(s8 TargetNo);
s32 nbGetActionSeq(dds3ProcessID_t *id);
nbMainProcessData_t *nbGetMainProcessData(void);
void nbPanelAllHide(void);
void nbPanelAnalyzeRun(void);
void nbPanelAutoHide(void);
void nbPanelAutoShow(void);
void nbPanelDrawPP(s32 x, s32 y, s32 select, u32 statindex, u32 flag, s32 winnum);
void nbPanelDrawPP0(s32 x, s32 y, nbMainProcessData_t *p, s32 index);
void nbPanelDrawPP1(s32 x, s32 y, s32 i, s32 j, s32 jun, s32 act, nbMainProcessData_t *p, bool pc_num_hide);
void nbPanelDrawPPnon(s32 index);
void nbPanelPartyDraw(void);
void nbPanelPartyHide(void);
void nbPanelPartySelect(nbMainProcessData_t *pMainData);
void nbPanelPartyShow(void);
void nbPanelPolygonFlashDrawUnity(void *obj, s32 x, s32 y, s32 ctx, s32 cty, f32 scale_x, f32 scale_y, u32 abgr_in, u32 abgr_out);
void nbPanelPressGauge(nbMainProcessData_t *pMainData);
void nbPanelPressGaugeShow(void);
void nbPanelPressTurn(nbMainProcessData_t *pMainData);
s32 nbPanelPressTurnRun(void);
u32 nbPanelStockSelectCtrl(nbMainProcessData_t *pMainData);
void nbPlaySe(s32 no);

// 0x121c260
u32 DDS3EFFECT_RGBA(s32 r, s32 g, s32 b, s32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x121f270
f32 HPMPBarAdjustment(f32 bar, f32 maxbar, f32 limit) {
  f32 v4;
  f32 result;
  bool v6;
  bool v7;

  v4 = bar / maxbar;
  result = 1.0 - limit;
  if (v4 < 1.0)
  {
    v6 = v4 == result;
    v7 = v4 < result;
  }
  else
  {
    v6 = 1;
    v7 = 0;
  }
  if (v7 || v6)
  {
    if (v4 <= 0.0)
    {
      return v4;
    }
    else if (v4 >= limit)
    {
      return v4;
    }
    else
    {
      return limit;
    }
  }
  return result;
}

// 0x121c290
s32 NBPANEL_FONT_RATIO(f32 v, f32 r) {
  return ((v * r) * 0.01);
}

// 0x121c270
u32 NBPANEL_FONT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return (g << 16) | (r << 24) | (b << 8) | a;
}

// 0x121c390
u32 NBPANEL_PRESS_RGBA_E(void) {
  return 3215519;
}

// 0x121c400
u32 NBPANEL_PRESS_RGBA_E_C(void) {
  return 7426975;
}

// 0x121c2b0
u32 NBPANEL_PRESS_RGBA_P(void) {
  return 10363410;
}

// 0x121c320
u32 NBPANEL_PRESS_RGBA_P_C(void) {
  return 10449235;
}

// 0x1221ea0
s32 NBPANEL_PTP_CX(nbPanelProcess_nbPanelXYZ_t *part) {
  struct System_Int32_array *xyz;
  struct System_Int32_array *wh;
  s32 v4;

  xyz = part->xyz;
  wh = part->wh;
  v4 = xyz->m_Items[0];
  return v4 + (wh->m_Items[0] >> 1);
}

// 0x1221f20
s32 NBPANEL_PTP_CY(nbPanelProcess_nbPanelXYZ_t *part) {
  struct System_Int32_array *xyz;
  struct System_Int32_array *wh;
  s32 v5;

  xyz = part->xyz;
  wh = part->wh;
  v5 = xyz->m_Items[1];
  return v5 + (wh->m_Items[1] >> 1);
}

// 0x1221fe0
s32 NBPANEL_PTP_H(nbPanelProcess_nbPanelXYZ_t *part) {
  struct System_Int32_array *wh;

  wh = part->wh;
  return wh->m_Items[1];
}

// 0x12220f0
s32 NBPANEL_PTP_HR(nbPanelProcess_nbPanelXYZ_t *part0, nbPanelProcess_nbPanelXYZ_t *part1, f32 rate) {
  struct System_Int32_array *wh;
  struct System_Int32_array *v6;
  s32 v7;
  struct System_Int32_array *v9;
  s32 v10;

  wh = part0->wh;
  v6 = part1->wh;
  v7 = wh->m_Items[1];
  v9 = part0->wh;
  v10 = v6->m_Items[1];
  return v7 + ((v10 - v9->m_Items[1]) * rate);
}

// 0x1221f90
s32 NBPANEL_PTP_W(nbPanelProcess_nbPanelXYZ_t *part) {
  struct System_Int32_array *wh;

  wh = part->wh;
  return wh->m_Items[0];
}

// 0x1222020
s32 NBPANEL_PTP_WR(nbPanelProcess_nbPanelXYZ_t *part0, nbPanelProcess_nbPanelXYZ_t *part1, f32 rate) {
  struct System_Int32_array *wh;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  s32 v8;

  wh = part0->wh;
  v5 = part1->wh;
  v6 = wh->m_Items[0];
  v7 = part0->wh;
  v8 = v5->m_Items[0];
  return v6 + ((v8 - v7->m_Items[0]) * rate);
}

// 0x121e1e0
void PnlAnim(void *mAnimator, char *name, s32 num) {
  UnityEngine_Animator_o *v7;
  bool v8;

  if (GetInteger(mAnimator, name) != num)
  {
    SetInteger(mAnimator, name, num);
    if (Equals_5234480(name, StringLiteral_21520))
    {
      if (GetInteger(mAnimator, name) == 1
        || GetInteger(mAnimator, name) == 2)
      {
        v7 = mAnimator;
        v8 = 1;
      }
      else
      {
        v7 = mAnimator;
        v8 = 0;
      }
      set_keepAnimatorControllerStateOnDisable(v7, v8);
    }
  }
}

// 0x1224020
void PnlColorSet(s32 col) {
  UnityEngine_GameObject_o *BattleUI;
  Il2CppObject *Component_object;

  BattleUI = GetBattleUI(6);
  Component_object = GetComponent_object_(BattleUI);
  SetInteger(Component_object, StringLiteral_16609, col);
}

// 0x12239d0
void StkSelDisp(bool show) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_GameObject_o *v7;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v9;
  Il2CppObject *v10;

  BattleUI = GetBattleUI(6);
  if (op_Inequality(BattleUI, 0, 0))
  {
    if (show)
    {
      if (!get_activeSelf(BattleUI))
        SetActive(BattleUI, 1, 0);
      v7 = GetBattleUI(6);
      Component_object = GetComponent_object_(v7);
      SetInteger(Component_object, StringLiteral_16609, 1);
    }
    else
    {
      v9 = GetBattleUI(6);
      v10 = GetComponent_object_(v9);
      SetInteger(v10, StringLiteral_16609, 0);
      if (get_activeSelf(BattleUI))
        SetActive(BattleUI, 0, 0);
    }
  }
}

// 0x1227b00
void nbInitPanelProcess(nbMainProcessData_t *data) {
  u64 *v3;
  u64 *v4;
  u64 *v6;
  struct nbPanelProcess_typeNbPnlWork_array *v10;
  nbPanelProcess_c *v11;
  u64 v12;
  s32 v13;
  u32 *gnbPnlWork;
  u64 *v16;
  struct nbPanelProcess_typeNbPnlWork_array *v18;
  struct nbPanelProcess_typeNbPnlWork_array *v20;
  struct nbPanelProcess_typeNbPnlWork_array *v22;
  struct nbPanelProcess_typeNbPnlWork_array *v24;
  struct nbPanelProcess_typeNbPnlWork_array *v26;
  struct nbPanelProcess_typeNbPnlWork_array *v28;
  Il2CppClass **v30;
  u32 v31;
  u64 v32;
  dds3ProcessID_t_o *started;
  dds3ProcessID_t_o *target;

  started = 0;
  target = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_nbPanelProcess_nbPanelRunProcess__);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbPanelProcess_nbPanelShutdown__);
  target = dds3StartProcess(StringLiteral_21567, 0x3F9u, 1, 1, v3, 0, v4, 0, 0, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->PanelProcessID = target;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbPanelProcess_nbPanelDrawProcess__);
  started = dds3StartProcess(StringLiteral_21568, 0x2B0Eu, 1, 1, v6, 0, 0, 0, 0, 0);
  dds3LinkProcess(&target, &started);
  *&nbPnlDrawFlag = 1;
  v10 = NewSpecific(nbPanelProcess_typeNbPnlWork, 4u);
  gnbPnlWork = v10;
  v12 = 0;
  v13 = (v11->_2.bitflags2 >> 1) & 1;
  do
  {
    v16 = Allocate(nbPanelProcess_typeNbPnlWork);
    _ctor(v16, 0);
    *&gnbPnlWork[2 * v12 + 8] = v16;
    v18 = gnbPnlWork;
    v18->m_Items[v12]->ActiveMode = 0;
    v20 = gnbPnlWork;
    v20->m_Items[v12]->OfsX = 0;
    v22 = gnbPnlWork;
    v22->m_Items[v12]->OldHp = -1;
    v24 = gnbPnlWork;
    v24->m_Items[v12]->OldMp = -1;
    v26 = gnbPnlWork;
    v26->m_Items[v12]->HpAnmCnt = 0;
    v28 = gnbPnlWork;
    v30 = &v28->obj.klass + v12++;
    HIDWORD(v30[4]->_1.byval_arg.data) = 0;
    v31 = *&v11->_2.bitflags1;
    v13 = (v31 >> 9) & 1;
  }
  while (v12 != 4);
  *(*(v32 + 184) + 284LL) = 0;
  *(*(v32 + 184) + 292LL) = 0;
  *(*(v32 + 184) + 304LL) = 0;
  *(*(v32 + 184) + 412LL) = 0;
  *(*(v32 + 184) + 396LL) = 0;
  *(*(v32 + 184) + 428LL) = 0;
  *(*(v32 + 184) + 280LL) = 0;
  *(*(v32 + 184) + 224LL) = 0;
  *(*(v32 + 184) + 236LL) = 0;
  *(*(v32 + 184) + 240LL) = 0;
  *(*(v32 + 184) + 244LL) = 0;
  *(*(v32 + 184) + 248LL) = 1;
  *(*(v32 + 184) + 252LL) = 0;
  *(*(v32 + 184) + 228LL) = -1;
  *(*(v32 + 184) + 232LL) = -1;
  *(*(v32 + 184) + 256LL) = -2139062144;
  *(*(v32 + 184) + 432LL) = 0;
  *(*(v32 + 184) + 436LL) = 0;
  *(*(v32 + 184) + 440LL) = 2155905152LL;
  *(*(v32 + 184) + 448LL) = 0;
  *(*(v32 + 184) + 452LL) = 300;
  *(*(v32 + 184) + 488LL) = 0;
  *(*(v32 + 184) + 492LL) = 0;
  *(*(v32 + 184) + 504LL) = 0;
  *(*(v32 + 184) + 512LL) = 1082163328;
  *(*(v32 + 184) + 516LL) = -2139062144;
  *(*(v32 + 184) + 520LL) = 1;
  if ((*(v32 + 295) & 2) != 0 && !*(v32 + 216))
  nbPanelPressGaugeShow(v32);
  nbPanelPartyShow();
  nbPanelAutoShow();
  nbPanelBaseABGR = -2139062144;
  nbPanelBaseRGBA = -2139062144;
}

// 0x121ca00
void nbPanelAllHide(void) {
  nbPanelAutoHide();
  nbPanelPartyHide();
  nbPanelPGShow = 0;
}

// 0x121c5d0
void nbPanelAllShow(void) {
  nbPanelPressGaugeShow();
  nbPanelPartyShow();
  nbPanelAutoShow();
}

// 0x1224ee0
void nbPanelAnalyzeDraw(datUnitWork_t *pUnitWork) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v7;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;

  pNbPanelAnalyzeUnitWork = pUnitWork;
  if (nbPanelAnalyzeProcess != 4)
  {
    BattleUI = GetBattleUI(5);
    if (!get_activeSelf(BattleUI))
    {
      SetActive(BattleUI, 1, 0);
      transform = get_transform(BattleUI, 0);
      v7 = Find(transform, StringLiteral_21545, 0);
      gameObject = get_gameObject(v7);
      Component_object = GetComponent_object_(gameObject);
      PnlAnim(Component_object, StringLiteral_21545, 1);
      ButtonGuideDispSet(StringLiteral_21546, 0, 0, 90);
    }
    nbPanelAnalyzeRun();
  }
}

// 0x1224df0
void nbPanelAnalyzeEnd(void) {
    GetBattleUI(0);
    ButtonGuideDispOff();
}

// 0x1224cf0
void nbPanelAnalyzeInit(void) {
  nbPanelAnalyzeProcess = 0;
  nbPanelAnalyzeFrame = 0;
  pNbPanelAnalyzeUnitWork = 0;
}

// 0x1225090
void nbPanelAnalyzeRun(void) {
    nbGetMainProcessData();
    Get(0);
    GetBattleUI(0);
    Set(0, 0);
    Analyze(0);
    Get(0);
    Get(0);
    Get(0);
    GetLocalizeText(0);
    Get(0);
}

// 0x1224d70
void nbPanelAnalyzeStart(void) {
  nbPanelAnalyzeProcess = 1;
  nbPanelAnalyzeFrame = 0;
}

// 0x1225fd0
void nbPanelAuto(nbMainProcessData_t *pMainData) {
  ;
}

// 0x1225ed0
s32 nbPanelAutoCheckShow(void) {
  return PanelAutoShow;
}

// 0x121cab0
void nbPanelAutoHide(void) {
  UnityEngine_GameObject_o *BattleUI;

  PanelAutoShow = 0;
  BattleUI = GetBattleUI(2);
  if (op_Inequality(BattleUI, 0, 0) && get_activeSelf(BattleUI))
    SetActive(BattleUI, 0, 0);
}

// 0x1225f40
void nbPanelAutoInit(void) {
  PanelAutoABGR = 1082163328;
  PanelAutoBaseColor = -2139062144;
  PanelAutoShow = 1;
}

// 0x121c8f0
void nbPanelAutoShow(void) {
  UnityEngine_GameObject_o *BattleUI;

  PanelAutoBaseColor = -2139062144;
  PanelAutoShow = 1;
  BattleUI = GetBattleUI(2);
  if (op_Inequality(BattleUI, 0, 0) && !get_activeSelf(BattleUI))
    SetActive(BattleUI, 1, 0);
}

// 0x121c550
void nbPanelBaseColorSet(u32 abgr) {
  nbPanelBaseABGR = abgr;
  nbPanelBaseRGBA = bswap32(abgr);
}

// 0x121dfb0
void nbPanelCursorDraw(s32 x, s32 y) {
  ;
}

// 0x1225fe0
void nbPanelDraw(s32 flag) {
  if (flag)
  {
    nbPanelPressGaugeShow();
    nbPanelPartyShow();
    nbPanelAutoShow();
    {
    }
  }
  else
  {
    nbPanelAllHide();
  }
  nbPnlDrawFlag = 1;
}

// 0x121f2b0
void nbPanelDrawPP(s32 x, s32 y, s32 select, u32 statindex, u32 flag, s32 winnum) {
    GetBattleUI(0);
    nbGetMainProcessData();
    PnlAnim(0, 0, 0);
    datCheckDying(0);
    Set(0, 0);
    Get(0);
}

// 0x121dff0
void nbPanelDrawPP0(s32 x, s32 y, nbMainProcessData_t *p, s32 index) {
    GetBattleUI(0);
    PnlAnim(0, 0, 0);
}

// 0x121e2d0
void nbPanelDrawPP1(s32 x, s32 y, s32 i, s32 j, s32 jun, s32 act, nbMainProcessData_t *p, bool pc_num_hide) {
    GetBattleUI(0);
    PnlAnim(0, 0, 0);
    datCheckDying(0);
    Set(0, 0);
    frGetCNameString(0);
    Get(0);
}

// 0x1224b40
void nbPanelDrawPPnon(s32 index) {
    GetBattleUI(0);
    PnlAnim(0, 0, 0);
}

// 0x1227680
void *nbPanelDrawProcess(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v4;
  nbMainProcessData_t_o *v8;
  struct dds3ProcessID_t_array *ActionProcessID;
  s64 NowActionProcess;
  nbMainProcessData_t_o *v12;
  struct dds3ProcessID_t_array *v14;
  s64 v15;
  dds3ProcessID_t_o *v17;
  s32 ActionSeq;
  u32 orderindex;
  struct System_SByte_array *order;
  u32 max_length;
  struct System_SByte_array *v23;
  u32 v25;
  struct System_SByte_array *v26;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v31;
  struct nbFormation_t_array *v33;
  struct nbFormation_t_array *v35;
  u64 v37;

  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    v4 = MainProcessData;
    nbPanelPressTurn(v4);
    nbPanelAnalyzeRun();
    if (nbPnlDrawFlag)
    {
      nbPanelPressGauge(v4);
      v8 = nbGetMainProcessData();
      ActionProcessID = v8->ActionProcessID;
      NowActionProcess = v8->NowActionProcess;
      v12 = v8;
      if (!ActionProcessID->m_Items[NowActionProcess] || v8->orderindex == 255)
      v14 = v8->ActionProcessID;
      v15 = v8->NowActionProcess;
      v17 = v14->m_Items[v15];
      ActionSeq = nbGetActionSeq(v17);
      orderindex = v12->orderindex;
      if ((orderindex & 0x80000000) == 0)
      {
        order = v12->order;
        max_length = order->max_length;
        if (orderindex < max_length)
        {
          if ((order->m_Items[v12->orderindex] & 0x80000000) == 0)
          {
            v23 = v12->order;
            v25 = v12->party->max_length;
            if (v23->m_Items[v12->orderindex] < v25)
            {
              v26 = v12->order;
              if (ActionSeq == 5)
              {
                form = v12->form;
                if ((~form->m_Items[0]->stat & 0x109) == 0)
                v31 = v12->form;
                if ((~v31->m_Items[1]->stat & 0x109) == 0)
                v33 = v12->form;
                if ((~v33->m_Items[2]->stat & 0x109) == 0)
                v35 = v12->form;
                if ((~v35->m_Items[3]->stat & 0x109) == 0)
                {
                  nbPanelPartySelect(v12);
                  return 0;
                }
              }
              if (!*(*(v37 + 184) + 432LL))
              {
                if ((*(v37 + 295) & 2) != 0 && !*(v37 + 216))
                nbPanelPartyDraw(v37);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

// 0x1228260
void nbPanelFlashDraw(nbPanelFlashData_t **pFlash, u32 abgrBase) {
  nbPanelFlashData_t_o *v5;
  s32 addX;
  u32 abgr;
  f32 scale_y;
  f32 scale_x;
  s32 v10;
  f32 v11;
  u32 v12;
  u32 v13;
  s32 v14;
  s32 v15;
  u32 v16;
  struct nbPanelProcess_nbPanelXYZ_t_array *nbPanelPTPartList;
  nbPanelProcess_nbPanelXYZ_t_o *v19;
  struct nbPanelProcess_nbPanelXYZ_t_array *v20;
  nbPanelProcess_nbPanelXYZ_t_o *v22;
  nbPanelFlashData_t_o *v25;
  s32 v26;
  s32 v27;
  s32 v28;
  u32 v29;
  struct nbPanelProcess_nbPanelXYZ_t_array *v31;
  nbPanelProcess_nbPanelXYZ_t_o *v32;
  struct nbPanelProcess_nbPanelXYZ_t_array *v33;
  nbPanelProcess_nbPanelXYZ_t_o *v35;
  f32 v38;
  u32 v39;
  u32 v40;
  s32 v41;
  s32 v42;
  u32 v43;
  struct nbPanelProcess_nbPanelXYZ_t_array *v45;
  nbPanelProcess_nbPanelXYZ_t_o *v46;
  struct nbPanelProcess_nbPanelXYZ_t_array *v47;
  nbPanelProcess_nbPanelXYZ_t_o *v49;

  v5 = *pFlash;
  addX = (*pFlash)->addX;
  abgr = (*pFlash)->abgr;
  scale_x = (*pFlash)->scale_x;
  scale_y = (*pFlash)->scale_y;
  v10 = (*pFlash)->addY + 87;
  switch ((*pFlash)->PT_1_Process)
  {
    case 1u:
      v11 = v5->PT_1_Frame / 7.0;
      v12 = vcvts_n_s32_f32(v11, 5u);
      v13 = vcvts_n_u32_f32(v11, 5u);
      if ((v11 * 32.0) >= 0.0)
        v12 = v13;
      SDF_VU0__dds3ColorItoF(abgr | (v12 << 24), 0);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__dds3ColorItoF(abgrBase);
      SDF_VU0__MULVECTOR();
      SDF_VU0__dds3ColorFtoI(128.0);
      v19 = nbPanelPTPartList->m_Items[2];
      v20 = nbPanelPTPartList;
      v22 = v20->m_Items[2];
      nbPanelPolygonFlashDrawUnity(
        (*pFlash)->obj,
        addX,
        v10,
        v14,
        v15,
        scale_x,
        scale_y,
        v16,
        abgr);
      ++(*pFlash)->PT_1_Frame;
      v25 = *pFlash;
      if ((*pFlash)->PT_1_Frame >= 7)
      {
        v26 = 2;
      }
      break;
    case 2u:
      SDF_VU0__dds3ColorItoF(abgr | 0x20000000);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__dds3ColorItoF(abgrBase);
      SDF_VU0__MULVECTOR();
      SDF_VU0__dds3ColorFtoI(128.0);
      v31 = nbPanelPTPartList;
      v32 = v31->m_Items[2];
      v33 = nbPanelPTPartList;
      v35 = v33->m_Items[2];
      nbPanelPolygonFlashDrawUnity(
        (*pFlash)->obj,
        addX,
        v10,
        v27,
        v28,
        scale_x,
        scale_y,
        v29,
        abgr);
      ++(*pFlash)->PT_1_Frame;
      v25 = *pFlash;
      if ((*pFlash)->PT_1_Frame >= 10)
      {
        v26 = 3;
      }
      break;
    case 3u:
      v38 = (v5->PT_1_Frame / -15.0) + 1.0;
      v39 = vcvts_n_s32_f32(v38, 5u);
      v40 = vcvts_n_u32_f32(v38, 5u);
      if ((v38 * 32.0) >= 0.0)
        v39 = v40;
      SDF_VU0__dds3ColorItoF(abgr | (v39 << 24), 0);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__dds3ColorItoF(abgrBase);
      SDF_VU0__MULVECTOR();
      SDF_VU0__dds3ColorFtoI(128.0);
      v45 = nbPanelPTPartList;
      v46 = v45->m_Items[2];
      v47 = nbPanelPTPartList;
      v49 = v47->m_Items[2];
      nbPanelPolygonFlashDrawUnity(
        (*pFlash)->obj,
        addX,
        v10,
        v41,
        v42,
        scale_x,
        scale_y,
        v43,
        abgr);
      ++(*pFlash)->PT_1_Frame;
      v25 = *pFlash;
      if ((*pFlash)->PT_1_Frame >= 15)
      {
        v26 = 4;
        v25->PT_1_Process = v26;
        (*pFlash)->PT_1_Frame = 0;
      }
      break;
    case 4u:
      v5->PT_1_Process = 0;
      break;
    default:
      return;
  }
}

// 0x1228190
void nbPanelFlashInit(nbPanelFlashData_t **pFlash, f32 scale_x, f32 scale_y, u32 abgr, u32 abgr_c, s32 addX, s32 addY) {
  (*pFlash)->PT_1_Process = 1;
  (*pFlash)->PT_1_Frame = 0;
  (*pFlash)->PT_2_Process = 1;
  (*pFlash)->PT_2_Frame = 0;
  (*pFlash)->PT_2_Rate = 0.1;
  (*pFlash)->PT_3_Process = 1;
  (*pFlash)->PT_3_Frame = 0;
  (*pFlash)->PT_3_Rate = 0.1;
  (*pFlash)->scale_x = scale_x;
  (*pFlash)->scale_y = scale_y;
  (*pFlash)->abgr = abgr;
  (*pFlash)->abgr_c = abgr_c;
  (*pFlash)->addX = addX;
  (*pFlash)->addY = addY;
}

// 0x1228210
u32 nbPanelFlashRGBAMulti(u32 abgr0, u32 abgr1) {
  SDF_VU0__dds3ColorItoF(abgr0);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(abgr1);
  SDF_VU0__MULVECTOR();
  return SDF_VU0__dds3ColorFtoI(128.0);
}

// 0x121dec0
s32 nbPanelHPColor(datUnitWork_t *pUnitWork) {
  signed s32 v3;

  else if (datCheckDying(pUnitWork))
  {
    return 2;
  }
  v3 = 100 * pUnitWork->hp / pUnitWork->maxhp;
  if (v3 >= 25)
    return v3 < 50;
  return 2;
}

// 0x121df80
s32 nbPanelMPColor(datUnitWork_t *pUnitWork) {
  signed s32 v2;

  v2 = 100 * pUnitWork->mp / pUnitWork->maxmp;
  if (v2 < 25)
    return 2;
  else
    return v2 < 50;
}

// 0x1226160
void nbPanelPartyDraw(void) {
    effBTLSkillCheckRun2(0);
    nbGetMainProcessData();
    dds3GetRandIntA(0, 0);
    nbPanelDrawPP0(0, 0, 0, 0);
    nbPanelDrawPP1(0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x121cbb0
void nbPanelPartyHide(void) {
  UnityEngine_GameObject_o *BattleUI;

  PanelPartyShow = 0;
  BattleUI = GetBattleUI(1);
  if (op_Inequality(BattleUI, 0, 0) && get_activeSelf(BattleUI))
    SetActive(BattleUI, 0, 0);
}

// 0x12234a0
void nbPanelPartySelect(nbMainProcessData_t *pMainData) {
    GetBattleUI(0);
    nbPanelDrawPP(0, 0, 0, 0, 0, 0);
    PnlAnim(0, 0, 0);
}

// 0x121c7d0
void nbPanelPartyShow(void) {
  UnityEngine_GameObject_o *BattleUI;

  PanelPartyShow = 1;
  BattleUI = GetBattleUI(1);
  if (op_Inequality(BattleUI, 0, 0) && !get_activeSelf(BattleUI))
  {
    SetActive(BattleUI, 1, 0);
    nbPanelPartyDraw();
  }
}

// 0x121dfc0
void nbPanelPolygonDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, u32 abgr0, u32 abgr1, u32 abgr2, u32 abgr3) {
  ;
}

// 0x121dfe0
void nbPanelPolygonFlashDraw(s32 x, s32 y, s32 ctx, s32 cty, s32 width, s32 height, u32 abgr_in, u32 abgr_out) {
  ;
}

// 0x1228840
void nbPanelPolygonFlashDrawUnity(void *obj, s32 x, s32 y, s32 ctx, s32 cty, f32 scale_x, f32 scale_y, u32 abgr_in, u32 abgr_out) {
    SDF_VU0__Retdds3ColorItoF(0, 0);
}

// 0x121dfd0
void nbPanelPolygonScaleDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, f32 scale_w, f32 scale_h, u32 abgr0, u32 abgr1, u32 abgr2, u32 abgr3) {
  ;
}

// 0x12203c0
void nbPanelPressGauge(nbMainProcessData_t *pMainData) {
    GetBattleUI(0);
    PnlAnim(0, 0, 0);
    effBTLSkillCheckRun2(0);
}

// 0x1220340
void nbPanelPressGaugeEncountHide(void) {
  nbPanelPGEncount = 1;
  nbPanelPGShow = 0;
}

// 0x121ccb0
void nbPanelPressGaugeHide(void) {
  nbPanelPGShow = 0;
}

// 0x121ff70
void nbPanelPressGaugeInit(void) {
  nbPanelPGNumber = 0;
  nbPanelPGFrame = 0;
  nbPanelPGBirthWait = 0;
  nbPanelPGStart = 0;
  nbPanelPGShow = 1;
  nbPanelPGEncount = 0;
  nbPanelPGTurn = -1;
  nbPanelPGTurnOld = -1;
  nbPanelPGBaseColor = -2139062144;
}

// 0x12200d0
void nbPanelPressGaugeReset(void) {
  Write(StringLiteral_21527, 0);
  nbPanelPGNumber = 0;
  nbPanelPGFrame = 0;
  nbPanelPGBirthWait = 0;
  nbPanelPGStart = 1;
  nbPanelPGTurn = -1;
  nbPanelPGTurnOld = -1;
  nbPanelPT_1_Process = 0;
  nbPanelPT_2_Process = 0;
  nbPanelPT_3_Process = 0;
  nbPanelPTAFrame = 4;
  nbPanelPTAProcess = 3;
  nbPanelPTARate_S = 0.1;
  nbPanelPTARate_E = 0.1;
  nbPanelPTAOnly = 1;
  nbPanelPTOmit = 1;
}

// 0x121c640
void nbPanelPressGaugeShow(void) {
  nbMainProcessData_t_o *MainProcessData;
  nbPanelProcess_c *v4;
  struct nbPanelProcess_StaticFields *static_fields;
  u32 stat;

  MainProcessData = nbGetMainProcessData();
  else
  {
    static_fields = nbPanelProcess->static_fields;
    if (static_fields->nbPanelPGShow)
  }
  if (static_fields->nbPanelPGEncount)
  {
    if ((v4->_2.bitflags2 & 2) == 0)
  }
  Write(StringLiteral_21528, 0);
  stat = MainProcessData->stat;
  nbPanelPGPress = stat & 8;
  nbPanelPGNumber = MainProcessData->press4_ten;
  nbPanelPGFrame = 0;
  nbPanelPGEncount = 0;
  nbPanelPGShow = 1;
  nbPanelPGBaseColor = -2139062144;
}

// 0x1220030
void nbPanelPressGaugeStart(void) {
  nbPanelPGNumber = 0;
  nbPanelPGFrame = 0;
  nbPanelPGBirthWait = 0;
  nbPanelPGStart = 1;
  nbPanelPGTurn = -1;
  nbPanelPGTurnOld = -1;
}

// 0x12221b0
void nbPanelPressTurn(nbMainProcessData_t *pMainData) {
    nbPanelPressTurnRun();
    GetBattleUI(0);
    effColorBlend(0, 0, 0);
}

// 0x121fe10
void nbPanelPressTurnGaugeAnimStart(void) {
  nbPanelPT_1_Process = 0;
  nbPanelPT_2_Process = 0;
  nbPanelPT_3_Process = 0;
  nbPanelPTAProcess = 1;
  nbPanelPTAFrame = 0;
  nbPanelPTAOnly = 1;
}

// 0x121feb0
void nbPanelPressTurnGaugeAnimStart2(void) {
  nbPanelPT_1_Process = 0;
  nbPanelPT_2_Process = 0;
  nbPanelPT_3_Process = 0;
  nbPanelPTAFrame = 4;
  nbPanelPTAProcess = 3;
  nbPanelPTARate_S = 0.1;
  nbPanelPTARate_E = 0.1;
  nbPanelPTAOnly = 1;
}

// 0x1221a60
s32 nbPanelPressTurnGaugeRun(void) {
  return nbPanelPTAProcess != 0;
}

// 0x1221ad0
void nbPanelPressTurnInit(void) {
  nbPanelPT_1_Process = 0;
  nbPanelPT_2_Process = 0;
  nbPanelPT_3_Process = 0;
  nbPanelPTAProcess = 0;
  nbPanelPTP_1_Process = 0;
  nbPanelPTAOnly = 0;
  nbPanelPTOmit = 0;
}

// 0x12202d0
void nbPanelPressTurnOmit(void) {
  nbPanelPTOmit = 1;
}

// 0x1221b70
s32 nbPanelPressTurnRun(void) {
  struct nbPanelProcess_StaticFields *static_fields;

  else
  {
    static_fields = nbPanelProcess->static_fields;
    if (static_fields->nbPanelPT_1_Process)
      return 1;
  }
  else if (static_fields->nbPanelPT_2_Process)
  {
    return 1;
  }
  if (!static_fields->nbPanelPT_3_Process)
  {
    if (!static_fields->nbPanelPTAProcess)
    {
      if (!static_fields->nbPanelPTP_1_Process)
        return 0;
    }
  }
  return 1;
}

// 0x1221ca0
void nbPanelPressTurnStart(void) {
  nbPanelProcess_c *v4;
  s16 v5;
  s32 v6;
  struct nbPanelProcess_StaticFields **p_static_fields;
  struct nbPanelProcess_StaticFields *static_fields;
  struct nbPanelProcess_StaticFields *v9;

  Write(StringLiteral_21539, 0);
  nbGetMainProcessData();
  if ((v5 & 0x200) != 0)
  {
    v6 = v5 & 0x200;
    p_static_fields = &v4->static_fields;
    static_fields = v4->static_fields;
    if (static_fields->nbPanelPTOmit)
  }
  else
  {
    v6 = 0;
    p_static_fields = &nbPanelProcess->static_fields;
    static_fields = nbPanelProcess->static_fields;
    if (static_fields->nbPanelPTOmit)
    {
      static_fields->nbPanelPTOmit = 0;
      return;
    }
  }
  static_fields->nbPanelPT_1_Process = 1;
  nbPanelPT_1_Frame = 0;
  nbPanelPT_2_Process = 1;
  nbPanelPT_2_Frame = 0;
  nbPanelPT_2_Rate = 0.1;
  nbPanelPT_3_Process = 1;
  nbPanelPT_3_Frame = 0;
  nbPanelPT_3_Rate = 0.1;
  nbPanelPTP_0_Frame = 0;
  nbPanelPTP_0_Process = 0;
  nbPanelPTP_1_Frame = 0;
  nbPanelPTP_1_Process = 0;
  v9 = v4->static_fields;
  if (v9->nbPanelPGTurn != v9->nbPanelPGTurnOld)
  {
    v9->nbPanelPTAProcess = 1;
    (*p_static_fields)->nbPanelPTAFrame = 0;
    (*p_static_fields)->nbPanelPTAOnly = 0;
  }
  nbPanelPGTurnOld = nbPanelPGTurn;
}

// 0x12260e0
void *nbPanelRunProcess(dds3ProcessID_t *id) {
  nbPnlCnt = nbPnlCnt + 0.2;
  return 0;
}

// 0x1227a70
void *nbPanelShutdown(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;

  MainProcessData = nbGetMainProcessData();
  MainProcessData->PanelProcessID = 0;
  return 0;
}

// 0x121deb0
void nbPanelSmallNameStringDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, u32 abgr, u32 statindex) {
  ;
}

// 0x121dea0
void nbPanelSmallStringDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, u32 abgr, char **pString) {
  ;
}

// 0x121d9d0
void nbPanelSpriteBlendDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ_0, nbPanelProcess_nbPanelXYZ_t *pXYZ_1, f32 rate, nbPanelProcess_nbPanelTMXuv_t *pUV, u32 abgr, sdfTexHandle_t *hTex) {
  nbPanelProcess_nbPanelXYZ_t_o *v14;
  struct System_Int32_array *xyz;
  struct System_Int32_array *v17;
  struct System_Int32_array *v18;
  s32 v19;
  struct System_Int32_array *v20;
  s32 v21;
  s32 v22;
  struct System_Int32_array *v24;
  struct System_Int32_array *v25;
  struct System_Int32_array *v27;
  s32 v28;
  struct System_Int32_array *v30;
  s32 v31;
  s32 v33;
  struct System_Int32_array *wh;
  struct System_Int32_array *v36;
  struct System_Int32_array *v37;
  s32 v38;
  struct System_Int32_array *v39;
  s32 v40;
  s32 v41;
  struct System_Int32_array *v43;
  struct System_Int32_array *v44;
  struct System_Int32_array *v46;
  s32 v47;
  struct System_Int32_array *v49;
  s32 v50;
  s32 v52;
  u32 max_length;
  u32 v54;
  u32 v55;
  u32 v56;

  v14 = Allocate(nbPanelProcess_nbPanelXYZ_t);
  _ctor(v14, 0);
  xyz = pXYZ_0->xyz;
  v17 = v14->xyz;
  v18 = pXYZ_1->xyz;
  v19 = xyz->m_Items[0];
  v20 = pXYZ_0->xyz;
  v21 = v18->m_Items[0];
  v22 = ((v21 + v19 - v20->m_Items[0]) * rate);
  v17->m_Items[0] = v22;
  v24 = pXYZ_0->xyz;
  v25 = v14->xyz;
  v27 = pXYZ_1->xyz;
  v28 = v24->m_Items[1];
  v30 = pXYZ_0->xyz;
  v31 = v27->m_Items[1];
  v33 = ((v31 + v28 - v30->m_Items[1]) * rate);
  v25->m_Items[1] = v33;
  wh = pXYZ_0->wh;
  v36 = v14->wh;
  v37 = pXYZ_1->wh;
  v38 = wh->m_Items[0];
  v39 = pXYZ_0->wh;
  v40 = v37->m_Items[0];
  v41 = ((v40 + v38 - v39->m_Items[0]) * rate);
  v36->m_Items[0] = v41;
  v43 = pXYZ_0->wh;
  v44 = v14->wh;
  v46 = pXYZ_1->wh;
  v47 = v43->m_Items[1];
  v49 = pXYZ_0->wh;
  v50 = v46->m_Items[1];
  v52 = ((v50 + v47 - v49->m_Items[1]) * rate);
  v44->m_Items[1] = v52;
  max_length = v14->xyz->max_length;
  v54 = v14->wh->max_length;
  v55 = pUV->uv->max_length;
  v56 = pUV->wh->max_length;
  effColorMultiply(abgr, nbPanelBaseABGR);
}

// 0x121cef0
void nbPanelSpriteCenteringDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, nbPanelProcess_nbPanelXYZ_t *pArea, nbPanelProcess_nbPanelTMXuv_t *pUV, u32 abgr, sdfTexHandle_t *hTex) {
  u32 max_length;
  u32 v13;
  u32 v14;
  u32 v15;

  if ((byte_3F59073 & 1) != 0)
  {
    if (LODWORD(pXYZ->wh->max_length))
  }
  if (!LODWORD(pXYZ->wh->max_length))
  max_length = pXYZ->xyz->max_length;
  v13 = pXYZ->wh->max_length;
  v14 = pUV->uv->max_length;
  v15 = pUV->wh->max_length;
  effColorMultiply(abgr, nbPanelBaseABGR);
}

// 0x121cd20
void nbPanelSpriteDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, nbPanelProcess_nbPanelTMXuv_t *pUV, u32 abgr, sdfTexHandle_t *hTex) {
  u32 max_length;
  u32 v11;
  u32 v12;
  u32 v13;

  if ((byte_3F59072 & 1) != 0)
  {
    max_length = pXYZ->xyz->max_length;
    if (max_length)
  }
  max_length = pXYZ->xyz->max_length;
  if (!max_length)
  v11 = pXYZ->wh->max_length;
  v12 = pUV->uv->max_length;
  v13 = pUV->wh->max_length;
  effColorMultiply(abgr, nbPanelBaseABGR);
}

// 0x121d120
void nbPanelSpriteDrawPer(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, nbPanelProcess_nbPanelTMXuv_t *pUV, u32 abgr, f32 per, sdfTexHandle_t *hTex) {
  u32 max_length;
  u32 v12;
  u32 v13;
  u32 v14;

  if ((byte_3F59074 & 1) != 0)
  {
    max_length = pXYZ->xyz->max_length;
    if (max_length)
  }
  max_length = pXYZ->xyz->max_length;
  if (!max_length)
  v12 = pXYZ->wh->max_length;
  v13 = pUV->uv->max_length;
  v14 = pUV->wh->max_length;
  effColorMultiply(abgr, nbPanelBaseABGR);
}

// 0x121d750
void nbPanelSpriteScaleCenterDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, nbPanelProcess_nbPanelTMXuv_t *pUV, u32 abgr, sdfIVector2_t *pCenter, f32 scale, sdfTexHandle_t *hTex) {
  u32 max_length;
  il2cpp_array_size_t v14;
  u32 v15;
  u32 v16;

  if ((byte_3F59077 & 1) != 0)
  {
    max_length = pCenter->pm->max_length;
    if (max_length)
  }
  max_length = pCenter->pm->max_length;
  if (!max_length)
  v14 = pXYZ->xyz->max_length;
  v15 = pUV->uv->max_length;
  v16 = pUV->wh->max_length;
  effColorMultiply(abgr, nbPanelBaseABGR);
}

// 0x121d2f0
void nbPanelSpriteScaleDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, nbPanelProcess_nbPanelTMXuv_t *pUV, u32 abgr, f32 scale, sdfTexHandle_t *hTex) {
  u32 max_length;
  u32 v12;
  u32 v13;

  if ((byte_3F59075 & 1) != 0)
  {
    max_length = pXYZ->wh->max_length;
    if (max_length)
  }
  max_length = pXYZ->wh->max_length;
  if (!max_length)
  v12 = pUV->uv->max_length;
  v13 = pUV->wh->max_length;
  effColorMultiply(abgr, nbPanelBaseABGR);
}

// 0x121d520
void nbPanelSpriteScaleWHDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, nbPanelProcess_nbPanelTMXuv_t *pUV, u32 abgr, f32 scaleW, f32 scaleH, sdfTexHandle_t *hTex) {
  u32 max_length;
  u32 v13;
  u32 v14;

  if ((byte_3F59076 & 1) != 0)
  {
    max_length = pXYZ->wh->max_length;
    if (max_length)
  }
  max_length = pXYZ->wh->max_length;
  if (!max_length)
  v13 = pUV->uv->max_length;
  v14 = pUV->wh->max_length;
  effColorMultiply(abgr, nbPanelBaseABGR);
}

// 0x1223880
s32 nbPanelStockCheckRun(void) {
  return nbPanelStockRun;
}

// 0x12238f0
void nbPanelStockEnd(void) {
  nbPanelStockRun = 0;
  nbPanelStockPad = 0;
}

// 0x1223c00
void nbPanelStockFadeOUT(void) {
  nbPanelStockFadeFlag = 1;
}

// 0x1223960
void nbPanelStockHide(void) {
  StkSelDisp(0);
}

// 0x12237e0
void nbPanelStockInit(void) {
  nbPanelStockRun = 0;
  nbPanelStockPad = 0;
  nbPanelStockFadeFlag = 0;
  nbPanelStockABGR = -2139062144;
  nbPanelStockFrame = 0;
  nbPanelStockShiftX = 300;
}

// 0x12247c0
u32 nbPanelStockSelect(nbMainProcessData_t *pMainData, u32 pad) {
  u64 v4;
  u32 v5;
  s64 StockIDListTop;
  s64 v11;
  nbPanelProcess_c *v13;
  s64 v14;
  s64 v15;
  s16 v16;
  s32 v17;
  struct nbPanelProcess_StaticFields *static_fields;
  struct System_UInt32_array *v19;
  u32 v21;
  s32 v22;
  u32 v23;
  struct System_UInt32_array *StockIDList;
  dds3GlobalWork_c *v26;
  struct dds3GlobalWork_StaticFields *v27;
  struct datUnitWork_t_array *unitwork;
  struct System_UInt32_array *v30;

  if (!pad)
  if (!nbPanelStockPad)
  if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
  v5 = nbPanelStockSelectCtrl(v4, *&pad);
  nbPanelDrawPPnon(0, *&pad);
  nbPanelDrawPPnon(1);
  nbPanelDrawPPnon(2);
  nbPanelDrawPPnon(3);
  if (StockIDListCount >= 1)
  {
    v14 = 0;
    v15 = 4 * StockIDListTop + 32;
    while (1)
    {
      v16 = *&v13->_2.bitflags1;
      if ((v16 & 0x200) != 0)
      {
        v17 = v16 & 0x200;
        static_fields = v13->static_fields;
        if (v14 == static_fields->StockIDListCursor)
        {
          StockIDList = static_fields->StockIDList;
          v21 = *(&StockIDList->obj.klass + 4 * v14 + v15);
          v22 = 1;
          v23 = 2097176;
        }
      }
      else
      {
        v17 = 0;
        static_fields = v13->static_fields;
        if (v14 == static_fields->StockIDListCursor)
      }
      v19 = static_fields->StockIDList;
      v21 = *(&v19->obj.klass + 4 * v14 + v15);
      v22 = 0;
      v23 = 24;
      nbPanelDrawPP(0, v11, v22, v21, v23, v14);
      v27 = v26->static_fields;
      unitwork = v27->DDS3_GBWK->unitwork;
      v30 = StockIDList;
      if (StockIDListTop + 1 + v14 < StockIDListCount && v14++ < 3)
        continue;
      break;
    }
  }
  else  if ((v13->_2.bitflags2 & 2) == 0)
  ++nbPanelStockFrame;
  return v5;
}

// 0x12240b0
u32 nbPanelStockSelectCtrl(nbMainProcessData_t *pMainData) {
    DDS3_PADCHECK_REP(0);
    nbPlaySe(0);
    DDS3_PADCHECK_TRIG(0);
    nbPanelPartyShow();
    StkSelDisp(0);
    return 0;
}

// 0x1223c70
void nbPanelStockSelectInit(void) {
    nbGetMainProcessData();
    nbPanelPartyHide();
    StkSelDisp(0);
}

// 0x121c470
void nbPnlLoad(void) {
  ;
}

// 0x121c540
void nbPnlSprite(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba, sdfTexHandle_t *th) {
  ;
}

// 0x121c490
void nbPnlTexDel(nbMainProcessData_t *p) {
  ;
}

// 0x121c480
void nbPnlTexSet(nbMainProcessData_t *p) {
  ;
}

// 0x121c530
void nbPnl_rsetAlpha(s32 mode) {
  ;
}

// 0x121c520
void nbPnl_rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  ;
}

// 0x121c510
void nbPnl_rsetTex1(s32 mmag, s32 mmin) {
  ;
}

// 0x121c4a0
void nbPnl_setOt(s32 otofs) {
  gnbPnlOtOfs = otofs;
}

// 0x1228cc0
void nbResetTurnSetAnimKeepState(void) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *v8;
  UnityEngine_Component_o *v9;
  UnityEngine_GameObject_o *v10;
  Il2CppObject *v11;
  UnityEngine_Transform_o *v12;
  UnityEngine_Component_o *v13;
  UnityEngine_GameObject_o *v14;
  UnityEngine_Transform_o *v15;
  s32 v16;
  UnityEngine_Transform_o *v17;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v19;
  Il2CppObject *v20;
  UnityEngine_Transform_o *v21;
  UnityEngine_Transform_o *v22;
  UnityEngine_Component_o *v23;
  UnityEngine_GameObject_o *v24;
  UnityEngine_Transform_o *v25;
  s32 v26;
  UnityEngine_Transform_o *v27;
  UnityEngine_Component_o *v28;
  UnityEngine_GameObject_o *v29;
  Il2CppObject *v30;
  UnityEngine_Transform_o *v31;

  BattleUI = GetBattleUI(2);
  if (op_Inequality(BattleUI, 0, 0))
  {
    transform = get_transform(BattleUI, 0);
    v5 = Find(transform, StringLiteral_21569, 0);
    gameObject = get_gameObject(v5);
    Component_object = GetComponent_object_(gameObject);
    set_keepAnimatorControllerStateOnDisable(Component_object, 0);
    v8 = get_transform(BattleUI, 0);
    v9 = Find(v8, StringLiteral_21570, 0);
    v10 = get_gameObject(v9);
    v11 = GetComponent_object_(v10);
    set_keepAnimatorControllerStateOnDisable(v11, 0);
    v12 = get_transform(BattleUI, 0);
    v13 = Find(v12, StringLiteral_21533, 0);
    v14 = get_gameObject(v13);
    v15 = get_transform(v14, 0);
    if (get_childCount(v15) >= 1)
    {
      v16 = 0;
      do
      {
        v17 = get_transform(v14, 0);
        Child = GetChild(v17, v16);
        v19 = get_gameObject(Child);
        v20 = GetComponent_object_(v19);
        set_keepAnimatorControllerStateOnDisable(v20, 0);
        ++v16;
        v21 = get_transform(v14, 0);
      }
      while (v16 < get_childCount(v21));
    }
    v22 = get_transform(BattleUI, 0);
    v23 = Find(v22, StringLiteral_21534, 0);
    v24 = get_gameObject(v23);
    v25 = get_transform(v24, 0);
    if (get_childCount(v25) >= 1)
    {
      v26 = 0;
      do
      {
        v27 = get_transform(v24, 0);
        v28 = GetChild(v27, v26);
        v29 = get_gameObject(v28);
        v30 = GetComponent_object_(v29);
        set_keepAnimatorControllerStateOnDisable(v30, 0);
        ++v26;
        v31 = get_transform(v24, 0);
      }
      while (v26 < get_childCount(v31));
    }
  }
}

// 0x1228af0
void nbTurnPBInitSetting(void) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v7;
  UnityEngine_Component_o *v8;
  UnityEngine_GameObject_o *v9;
  UnityEngine_Transform_o *v10;
  UnityEngine_Component_o *v11;
  UnityEngine_GameObject_o *v12;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GameObject_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *v18;

  BattleUI = GetBattleUI(2);
  if (op_Inequality(BattleUI, 0, 0) && !get_activeSelf(BattleUI))
  {
    SetActive(BattleUI, 1, 0);
    transform = get_transform(BattleUI, 0);
    v5 = Find(transform, StringLiteral_21436, 0);
    gameObject = get_gameObject(v5);
    SetActive(gameObject, 1, 0);
    v7 = get_transform(BattleUI, 0);
    v8 = Find(v7, StringLiteral_21529, 0);
    v9 = get_gameObject(v8);
    SetActive(v9, 0, 0);
    v10 = get_transform(BattleUI, 0);
    v11 = Find(v10, StringLiteral_21530, 0);
    v12 = get_gameObject(v11);
    SetActive(v12, 0, 0);
    v13 = get_transform(BattleUI, 0);
    v14 = Find(v13, StringLiteral_21533, 0);
    v15 = get_gameObject(v14);
    SetActive(v15, 0, 0);
    v16 = get_transform(BattleUI, 0);
    v17 = Find(v16, StringLiteral_21534, 0);
    v18 = get_gameObject(v17);
    SetActive(v18, 0, 0);
  }
}
