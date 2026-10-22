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
    if (Equals_5234480(name, "bpressturn"))
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
  SetInteger(Component_object, "color", col);
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
      SetInteger(Component_object, "color", 1);
    }
    else
    {
      v9 = GetBattleUI(6);
      v10 = GetComponent_object_(v9);
      SetInteger(v10, "color", 0);
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
  target = dds3StartProcess("nb_panel", 0x3F9u, 1, 1, v3, 0, v4, 0, 0, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->PanelProcessID = target;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbPanelProcess_nbPanelDrawProcess__);
  started = dds3StartProcess("nb_panel_draw", 0x2B0Eu, 1, 1, v6, 0, 0, 0, 0, 0);
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
LABEL_35:
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
      v7 = Find(transform, "banalyze_window", 0);
      gameObject = get_gameObject(v7);
      Component_object = GetComponent_object_(gameObject);
      PnlAnim(Component_object, "banalyze_window", 1);
      ButtonGuideDispSet("BTL04", 0, 0, 90);
    }
    nbPanelAnalyzeRun();
  }
}

// 0x1224df0
void nbPanelAnalyzeEnd(void) {
  UnityEngine_GameObject_o *BattleUI;

  nbPanelAnalyzeProcess = 4;
  nbPanelAnalyzeFrame = 0;
  BattleUI = GetBattleUI(5);
  SetActive(BattleUI, 0, 0);
  pNbPanelAnalyzeUnitWork = 0;
  else
  {
    ButtonGuideDispOff();
  }
}

// 0x1224cf0
void nbPanelAnalyzeInit(void) {
  nbPanelAnalyzeProcess = 0;
  nbPanelAnalyzeFrame = 0;
  pNbPanelAnalyzeUnitWork = 0;
}

// 0x1225090
void nbPanelAnalyzeRun(void) {
  s32 id;
  u8 v7;
  u32 v8;
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v12;
  UnityEngine_GameObject_o *gameObject;
  s32 v14;
  UnityEngine_Transform_o *v15;
  UnityEngine_Component_o *v16;
  UnityEngine_GameObject_o *v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Component_o *v19;
  UnityEngine_GameObject_o *v20;
  Il2CppObject *Component_object;
  s32 level;
  UnityEngine_Transform_o *v25;
  UnityEngine_Component_o *v26;
  UnityEngine_GameObject_o *v27;
  UnityEngine_Transform_o *v28;
  UnityEngine_Component_o *v29;
  UnityEngine_GameObject_o *v30;
  Il2CppObject *v32;
  s32 v34;
  s32 race;
  System_String_o *v37;
  UnityEngine_Transform_o *v38;
  UnityEngine_Component_o *v39;
  UnityEngine_GameObject_o *v40;
  Il2CppObject *v42;
  s32 v44;
  System_String_o *v45;
  UnityEngine_Transform_o *v46;
  UnityEngine_Component_o *v47;
  UnityEngine_GameObject_o *v48;
  UnityEngine_Transform_o *v49;
  UnityEngine_Component_o *v50;
  UnityEngine_GameObject_o *v51;
  UnityEngine_Transform_o *v52;
  UnityEngine_Component_o *v53;
  UnityEngine_GameObject_o *v54;
  Il2CppObject *v56;
  s32 hp;
  UnityEngine_Transform_o *v59;
  UnityEngine_Component_o *v60;
  UnityEngine_GameObject_o *v61;
  Il2CppObject *v62;
  s32 maxhp;
  CounterCtr_o *v64;
  UnityEngine_Transform_o *v65;
  UnityEngine_Component_o *v66;
  UnityEngine_GameObject_o *v67;
  Il2CppObject *v68;
  struct datUnitWork_t_o *pNbPanelAnalyzeUnitWork;
  u32 v70;
  u32 v71;
  f32 v72;
  UnityEngine_Transform_o *v73;
  UnityEngine_Component_o *v74;
  UnityEngine_GameObject_o *v75;
  UnityEngine_Transform_o *v76;
  UnityEngine_Component_o *v77;
  UnityEngine_GameObject_o *v78;
  UnityEngine_Transform_o *v79;
  UnityEngine_Component_o *v80;
  UnityEngine_GameObject_o *v81;
  UnityEngine_Transform_o *v82;
  UnityEngine_Component_o *v83;
  UnityEngine_GameObject_o *v84;
  Il2CppObject *v86;
  s32 mp;
  UnityEngine_Transform_o *v89;
  UnityEngine_Component_o *v90;
  UnityEngine_GameObject_o *v91;
  Il2CppObject *v92;
  s32 maxmp;
  CounterCtr_o *v94;
  UnityEngine_Transform_o *v95;
  UnityEngine_Component_o *v96;
  UnityEngine_GameObject_o *v97;
  Il2CppObject *v98;
  struct datUnitWork_t_o *v99;
  u32 v100;
  u32 v101;
  f32 v102;
  UnityEngine_Transform_o *v103;
  UnityEngine_Component_o *v104;
  UnityEngine_GameObject_o *v105;
  f32 v106;
  UnityEngine_Transform_o *v107;
  u64 *v108;
  System_String_o *v109;
  UnityEngine_Component_o *v110;
  UnityEngine_GameObject_o *v111;
  Il2CppObject *v112;
  System_String_o *v113;
  s64 i;
  UnityEngine_Transform_o *v115;
  u64 *v116;
  System_String_o *v117;
  UnityEngine_Component_o *v118;
  UnityEngine_GameObject_o *v119;
  Il2CppObject *v121;
  u64 v123;
  s32 v124;
  struct System_UInt16_array *skill;
  s32 v129;
  struct System_UInt16_array *v131;
  s32 v133;
  System_String_o *v134;
  UnityEngine_Transform_o *v135;
  UnityEngine_Component_o *v136;
  UnityEngine_GameObject_o *v137;
  Il2CppObject *v138;
  UnityEngine_Transform_o *v139;
  UnityEngine_Component_o *v140;
  UnityEngine_GameObject_o *v141;
  Il2CppObject *v143;
  s32 v145;
  s32 aisyoid;
  System_String_o *LocalizeText;
  UnityEngine_Color_o v149;
  UnityEngine_Color_o v150;
  s32 v151;

  if (pNbPanelAnalyzeUnitWork)
  {
    nbGetMainProcessData();
    id = pNbPanelAnalyzeUnitWork->id;
    v7 = Get(id, 0);
    v8 = pNbPanelAnalyzeUnitWork->id;
    if (v8 >= 0x170)
    {
      if (v8 <= 0x18F)
        v7 = 121;
    }
    BattleUI = GetBattleUI(5);
    if (!op_Equality(BattleUI, 0, 0))
    {
      transform = get_transform(BattleUI, 0);
      v12 = Find(transform, "banalyze_name", 0);
      gameObject = get_gameObject(v12);
      v14 = v7;
      v15 = get_transform(gameObject, 0);
      v16 = Find(v15, "banalyze_lv_known", 0);
      v17 = get_gameObject(v16);
      if ((v7 & 1) != 0)
      {
        SetActive(v17, 0, 0);
        v25 = get_transform(gameObject, 0);
        v26 = Find(v25, "banalyze_lv_unknown", 0);
        v27 = get_gameObject(v26);
        SetActive(v27, 1, 0);
      }
      else
      {
        SetActive(v17, 1, 0);
        v18 = get_transform(gameObject, 0);
        v19 = Find(v18, "banalyze_lv_unknown", 0);
        v20 = get_gameObject(v19);
        SetActive(v20, 0, 0);
        Component_object = GetComponent_object_(gameObject);
        level = pNbPanelAnalyzeUnitWork->level;
        *&v150.r = 0;
        *&v150.b = 0;
        sub_19EC630(&v150.r, 1.0, 1.0, 1.0, 1.0);
        Set(Component_object, level, v150, 0, 0);
      }
      v28 = get_transform(BattleUI, 0);
      v29 = Find(v28, "banalyze_name/banalyze_race_textTM", 0);
      v30 = get_gameObject(v29);
      v32 = GetComponent_object_(v30);
      if ((v14 & 2) != 0)
      {
        v37 = "？";
      }
      else
      {
        v34 = pNbPanelAnalyzeUnitWork->id;
        race = Analyze(v34)->race;
        v37 = Get(race, 0, 0);
      }
      set_text(v32, v37);
      v38 = get_transform(BattleUI, 0);
      v39 = Find(v38, "banalyze_name/banalyze_name_textTM", 0);
      v40 = get_gameObject(v39);
      v42 = GetComponent_object_(v40);
      if ((v14 & 4) != 0)
      {
        v45 = "？";
      }
      else
      {
        v44 = pNbPanelAnalyzeUnitWork->id;
        v45 = Get(v44, 0);
      }
      set_text(v42, v45);
      v46 = get_transform(BattleUI, 0);
      v47 = Find(v46, "banalyze_hp/banalyze_hp_known", 0);
      v48 = get_gameObject(v47);
      if ((v14 & 8) != 0)
      {
        SetActive(v48, 0, 0);
        v73 = get_transform(BattleUI, 0);
        v74 = Find(v73, "banalyze_hp/banalyze_hp_unknown", 0);
        v75 = get_gameObject(v74);
        SetActive(v75, 1, 0);
      }
      else
      {
        SetActive(v48, 1, 0);
        v49 = get_transform(BattleUI, 0);
        v50 = Find(v49, "banalyze_hp/banalyze_hp_unknown", 0);
        v51 = get_gameObject(v50);
        SetActive(v51, 0, 0);
        v52 = get_transform(BattleUI, 0);
        v53 = Find(v52, "banalyze_hp/banalyze_hp_known/num_hp01", 0);
        v54 = get_gameObject(v53);
        v56 = GetComponent_object_(v54);
        hp = pNbPanelAnalyzeUnitWork->hp;
        *&v150.r = 0;
        *&v150.b = 0;
        sub_19EC630(&v150.r, 1.0, 1.0, 1.0, 1.0);
        Set(v56, hp, v150, 0, 0);
        v59 = get_transform(BattleUI, 0);
        v60 = Find(v59, "banalyze_hp/banalyze_hp_known/num_hpfull01", 0);
        v61 = get_gameObject(v60);
        v62 = GetComponent_object_(v61);
        maxhp = pNbPanelAnalyzeUnitWork->maxhp;
        v64 = v62;
        *&v149.r = 0;
        *&v149.b = 0;
        sub_19EC630(&v149.r, 1.0, 1.0, 1.0, 1.0);
        Set(v64, maxhp, v149, 0, 0);
        v65 = get_transform(BattleUI, 0);
        v66 = Find(v65, "banalyze_hp/banalyze_hp_known/banalyze_hpbase/banalyze_hpbar", 0);
        v67 = get_gameObject(v66);
        v68 = GetComponent_object_(v67);
        LOWORD(v70) = pNbPanelAnalyzeUnitWork->hp;
        LOWORD(v71) = pNbPanelAnalyzeUnitWork->maxhp;
        v72 = v70 / v71;
        if (v72 >= 1.0 || v72 <= 0.95)
        {
          if (v72 > 0.0)
            v72 = fmaxf(v72, 0.05);
        }
        else
        {
          v72 = 0.95;
        }
        set_fillAmount(v68, v72);
      }
      v76 = get_transform(BattleUI, 0);
      v77 = Find(v76, "banalyze_mp/banalyze_mp_known", 0);
      v78 = get_gameObject(v77);
      if ((v14 & 0x10) != 0)
      {
        SetActive(v78, 0, 0);
        v103 = get_transform(BattleUI, 0);
        v104 = Find(v103, "banalyze_mp/banalyze_mp_unknown", 0);
        v105 = get_gameObject(v104);
        SetActive(v105, 1, 0);
        v151 = v14;
        if ((v14 & 0x40) == 0)
          goto LABEL_85;
      }
      else
      {
        SetActive(v78, 1, 0);
        v79 = get_transform(BattleUI, 0);
        v80 = Find(v79, "banalyze_mp/banalyze_mp_unknown", 0);
        v81 = get_gameObject(v80);
        SetActive(v81, 0, 0);
        v82 = get_transform(BattleUI, 0);
        v83 = Find(v82, "banalyze_mp/banalyze_mp_known/num_mp01", 0);
        v84 = get_gameObject(v83);
        v86 = GetComponent_object_(v84);
        mp = pNbPanelAnalyzeUnitWork->mp;
        *&v150.r = 0;
        *&v150.b = 0;
        sub_19EC630(&v150.r, 1.0, 1.0, 1.0, 1.0);
        Set(v86, mp, v150, 0, 0);
        v89 = get_transform(BattleUI, 0);
        v90 = Find(v89, "banalyze_mp/banalyze_mp_known/num_mpfull01", 0);
        v91 = get_gameObject(v90);
        v92 = GetComponent_object_(v91);
        maxmp = pNbPanelAnalyzeUnitWork->maxmp;
        v94 = v92;
        *&v149.r = 0;
        *&v149.b = 0;
        sub_19EC630(&v149.r, 1.0, 1.0, 1.0, 1.0);
        Set(v94, maxmp, v149, 0, 0);
        v95 = get_transform(BattleUI, 0);
        v96 = Find(v95, "banalyze_mp/banalyze_mp_known/banalyze_mpbase/banalyze_mpbar", 0);
        v97 = get_gameObject(v96);
        v98 = GetComponent_object_(v97);
        v99 = pNbPanelAnalyzeUnitWork;
        LOWORD(v100) = v99->mp;
        LOWORD(v101) = v99->maxmp;
        v102 = v100 / v101;
        if (v102 >= 1.0 || v102 <= 0.95)
        {
          if (v102 > 0.0)
            v102 = fmaxf(v102, 0.05);
          set_fillAmount(v98, v102);
          v151 = v14;
          if ((v14 & 0x40) == 0)
            goto LABEL_85;
        }
        else
        {
          set_fillAmount(v98, 0.95);
          v151 = v14;
          if ((v14 & 0x40) == 0)
          {
LABEL_85:
            for (i = 16; i != 24; ++i)
            {
              v115 = get_transform(BattleUI, 0);
              LODWORD(v150.r) = i - 15;
              v116 = sub_8D3950(uint, &v150);
              v117 = Concat_5269984("banalyze_skill/banalyze_skill0", v116, "/banalyze_textTM");
              v118 = Find(v115, v117, 0);
              v119 = get_gameObject(v118);
              v121 = GetComponent_object_(v119);
              v123 = i - 16;
              v124 = pNbPanelAnalyzeUnitWork->id;
              skill = Analyze(v124)->skill;
              if (*(&skill->obj.klass + i))
              {
                v129 = pNbPanelAnalyzeUnitWork->id;
                v131 = Analyze(v129)->skill;
                v133 = *(&v131->obj.klass + i);
                v134 = Get(v133, 0, 0);
              }
              else
              {
                v134 = "";
              }
              set_text(v121, v134);
            }
            goto LABEL_109;
          }
        }
      }
      LODWORD(v106) = 1;
      do
      {
        v107 = get_transform(BattleUI, 0);
        v150.r = v106;
        v108 = sub_8D3950(uint, &v150);
        v109 = Concat_5269984("banalyze_skill/banalyze_skill0", v108, "/banalyze_textTM");
        v110 = Find(v107, v109, 0);
        v111 = get_gameObject(v110);
        v112 = GetComponent_object_(v111);
        if (LODWORD(v106) == 1)
          v113 = "？";
        else
          v113 = "";
        set_text(v112, v113);
        ++LODWORD(v106);
      }
      while (LODWORD(v106) != 9);
LABEL_109:
      v135 = get_transform(BattleUI, 0);
      v136 = Find(v135, "banalyze_skill/banalyze_skill09/banalyze_textTM", 0);
      v137 = get_gameObject(v136);
      v138 = GetComponent_object_(v137);
      set_text(v138, "");
      v139 = get_transform(BattleUI, 0);
      v140 = Find(v139, "banalyze_attribute/banalyze_attribute_textTM", 0);
      v141 = get_gameObject(v140);
      v143 = GetComponent_object_(v141);
      if ((v151 & 0x20) != 0)
      {
        LocalizeText = GetLocalizeText("AISYO_L0448");
      }
      else
      {
        v145 = pNbPanelAnalyzeUnitWork->id;
        aisyoid = Analyze(v145)->aisyoid;
        LocalizeText = Get(aisyoid, 0);
      }
      set_text(v143, LocalizeText);
    }
  }
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
LABEL_13:
    }
  }
  else
  {
    nbPanelAllHide();
      goto LABEL_13;
  }
  nbPnlDrawFlag = 1;
}

// 0x121f2b0
void nbPanelDrawPP(s32 x, s32 y, s32 select, u32 statindex, u32 flag, s32 winnum) {
  f32 v7;
  char v9;
  UnityEngine_Object_o *BattleUI;
  UnityEngine_Transform_o *transform;
  u64 *v15;
  System_String_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  s16 v24;
  s32 v25;
  System_String_o *v26;
  UnityEngine_Animator_o *v27;
  s32 v28;
  UnityEngine_Transform_o *v29;
  UnityEngine_Component_o *v30;
  UnityEngine_GameObject_o *v31;
  UnityEngine_Transform_o *v32;
  UnityEngine_Component_o *v33;
  UnityEngine_GameObject_o *v34;
  UnityEngine_Transform_o *v35;
  UnityEngine_Component_o *v36;
  UnityEngine_GameObject_o *v37;
  UnityEngine_Transform_o *v38;
  UnityEngine_Component_o *v39;
  UnityEngine_GameObject_o *v40;
  UnityEngine_Transform_o *v42;
  UnityEngine_Component_o *v43;
  UnityEngine_GameObject_o *v44;
  Il2CppObject *v46;
  u32 v47;
  struct datUnitWork_t_array *unitwork;
  u32 max_length;
  UnityEngine_Transform_o *v51;
  UnityEngine_Component_o *v52;
  UnityEngine_GameObject_o *v53;
  Il2CppObject *v55;
  u32 v56;
  struct datUnitWork_t_array *v58;
  u32 v59;
  f32 v62;
  f32 v63;
  UnityEngine_Transform_o *v64;
  UnityEngine_Component_o *v65;
  UnityEngine_GameObject_o *v66;
  struct datUnitWork_t_array *v68;
  UnityEngine_GameObject_o *v69;
  datUnitWork_t_o *v71;
  signed s32 v72;
  s32 v73;
  Il2CppObject *v74;
  struct datUnitWork_t_array *v75;
  CounterCtrBattle_o *v76;
  s32 hp;
  UnityEngine_Transform_o *v79;
  UnityEngine_Component_o *v80;
  UnityEngine_GameObject_o *v81;
  Il2CppObject *v83;
  struct datUnitWork_t_array *v85;
  s32 id;
  System_String_o *v88;
  f32 v91;
  f32 v92;
  f32 v93;
  f32 v94;
  UnityEngine_Transform_o *v95;
  UnityEngine_Component_o *v96;
  UnityEngine_GameObject_o *v97;
  Il2CppObject *v98;
  struct datUnitWork_t_array *v100;
  struct datUnitWork_t_array *v103;
  UnityEngine_GameObject_o *v105;
  bool v106;
  UnityEngine_Transform_o *v107;
  UnityEngine_Component_o *v108;
  UnityEngine_GameObject_o *v110;
  struct datUnitWork_t_array *v112;
  datUnitWork_t_o *v114;
  signed s32 v115;
  s32 v116;
  Il2CppObject *v117;
  struct datUnitWork_t_array *v118;
  CounterCtrBattle_o *v119;
  s32 mp;
  struct datUnitWork_t_array *v123;
  u16 badstatus;
  s32 v126;
  UnityEngine_Transform_o *v127;
  UnityEngine_Component_o *v128;
  UnityEngine_GameObject_o *v129;
  Il2CppObject *v130;
  s32 v131;
  UnityEngine_Color_o v132;

  v9 = flag;
  BattleUI = GetBattleUI(6);
  if (op_Equality(BattleUI, 0, 0) || !get_activeSelf(BattleUI))
    return;
  LODWORD(v132.r) = winnum + 1;
  transform = get_transform(BattleUI, 0);
  v15 = sub_8D3950(s32, &v132);
  v16 = Concat("bparty_window0", v15);
  v17 = Find(transform, v16, 0);
  gameObject = get_gameObject(v17);
  Component_object = GetComponent_object_(gameObject);
  nbGetMainProcessData();
  if ((v24 & 0x200) != 0)
  {
    v25 = v24 & 0x200;
    if (select)
      goto LABEL_16;
  }
  else
  {
    v25 = 0;
    if (select)
    {
LABEL_16:
      v26 = "bparty_window";
      v27 = Component_object;
      v28 = 1;
      goto LABEL_27;
    }
  }
  v26 = "bparty_window";
  v27 = Component_object;
  v28 = 0;
LABEL_27:
  PnlAnim(v27, v26, v28);
  v29 = get_transform(gameObject, 0);
  v30 = Find(v29, "bparty_pc_num/bparty_pc_num1", 0);
  v31 = get_gameObject(v30);
  SetActive(v31, 0, 0);
  v32 = get_transform(gameObject, 0);
  v33 = Find(v32, "bparty_pc_num/bparty_pc_num2", 0);
  v34 = get_gameObject(v33);
  SetActive(v34, 0, 0);
  v35 = get_transform(gameObject, 0);
  v36 = Find(v35, "bparty_pc_num/bparty_pc_num3", 0);
  v37 = get_gameObject(v36);
  SetActive(v37, 0, 0);
  v38 = get_transform(gameObject, 0);
  v39 = Find(v38, "bparty_pc_num/bparty_pc_num4", 0);
  v40 = get_gameObject(v39);
  SetActive(v40, 0, 0);
  if ((v9 & 2) != 0)
  {
    if ((v9 & 4) != 0)
      goto LABEL_64;
  }
  else
  {
    v42 = get_transform(gameObject, 0);
    v43 = Find(v42, "barhp/barhp_color", 0);
    v44 = get_gameObject(v43);
    v46 = GetComponent_object_(v44);
    unitwork = DDS3_GBWK->unitwork;
    max_length = unitwork->max_length;
    LOWORD(v7) = unitwork->m_Items[statindex]->hp;
    v7 = LODWORD(v7);
    LOWORD(v47) = unitwork->m_Items[statindex]->maxhp;
    v62 = v47;
    v63 = v7 / v62;
    if ((v7 / v62) >= 1.0 || v63 <= 0.925)
    {
      if (v63 > 0.0)
        v63 = fmaxf(v63, 0.075);
    }
    else
    {
      v63 = 0.925;
    }
    set_fillAmount(v46, v63);
    v64 = get_transform(gameObject, 0);
    v65 = Find(v64, "barhp", 0);
    v66 = get_gameObject(v65);
    v68 = DDS3_GBWK->unitwork;
    v69 = v66;
    v71 = v68->m_Items[statindex];
    if (datCheckDying(v71) || (v72 = 100 * v71->hp / v71->maxhp, v72 < 25))
      v73 = 2;
    else
      v73 = v72 < 50;
    v74 = GetComponent_object_(v69);
    v75 = DDS3_GBWK->unitwork;
    v76 = v74;
    hp = v75->m_Items[statindex]->hp;
    *&v132.r = 0;
    *&v132.b = 0;
    sub_19EC630(&v132.r, 1.0, 1.0, 1.0, 1.0);
    Set(v76, hp, v132, v73, 0);
    if ((v9 & 4) != 0)
    {
LABEL_64:
      if ((v9 & 1) == 0)
        goto LABEL_65;
LABEL_114:
      if ((v9 & 0x20) != 0)
        return;
      goto LABEL_115;
    }
  }
  v51 = get_transform(gameObject, 0);
  v52 = Find(v51, "barmp/barmp_color", 0);
  v53 = get_gameObject(v52);
  v55 = GetComponent_object_(v53);
  v58 = DDS3_GBWK->unitwork;
  v59 = v58->max_length;
  LOWORD(v7) = v58->m_Items[statindex]->mp;
  v91 = LODWORD(v7);
  LOWORD(v56) = v58->m_Items[statindex]->maxmp;
  v92 = v56;
  v93 = v91 / v92;
  if (v93 >= 1.0 || v93 <= 0.925)
  {
    v94 = v93;
    if (v93 > 0.0)
      v94 = fmaxf(v93, 0.075);
  }
  else
  {
    v94 = 0.925;
  }
  set_fillAmount(v55, v94);
  v95 = get_transform(gameObject, 0);
  v96 = Find(v95, "barmp/barmp_graycolor", 0);
  v97 = get_gameObject(v96);
  v98 = GetComponent_object_(v97);
  set_fillAmount(v98, v93);
  v100 = DDS3_GBWK->unitwork;
  if (!v100->m_Items[statindex]->hp)
    goto LABEL_95;
  v103 = DDS3_GBWK->unitwork;
  if (v103->m_Items[statindex]->badstatus != 2048)
  {
    if (get_activeSelf(v97))
    {
      v105 = v97;
      v106 = 0;
      goto LABEL_99;
    }
  }
  else
  {
LABEL_95:
    if (!get_activeSelf(v97))
    {
      v105 = v97;
      v106 = 1;
LABEL_99:
      SetActive(v105, v106, 0);
    }
  }
  v107 = get_transform(gameObject, 0);
  v108 = Find(v107, "barmp", 0);
  v110 = get_gameObject(v108);
  v112 = DDS3_GBWK->unitwork;
  v114 = v112->m_Items[statindex];
  v115 = 100 * v114->mp / v114->maxmp;
  if (v115 <= 24)
    v116 = 2;
  else
    v116 = v115 < 50;
  v117 = GetComponent_object_(v110);
  v118 = DDS3_GBWK->unitwork;
  v119 = v117;
  mp = v118->m_Items[statindex]->mp;
  *&v132.r = 0;
  *&v132.b = 0;
  sub_19EC630(&v132.r, 1.0, 1.0, 1.0, 1.0);
  Set(v119, mp, v132, v116, 0);
  if ((v9 & 1) != 0)
    goto LABEL_114;
LABEL_65:
  v79 = get_transform(gameObject, 0);
  v80 = Find(v79, "bparty_text01TM", 0);
  v81 = get_gameObject(v80);
  v83 = GetComponent_object_(v81);
  v85 = DDS3_GBWK->unitwork;
  id = v85->m_Items[statindex]->id;
  v88 = Get(id, 0);
  set_text(v83, v88);
  if ((v9 & 0x20) == 0)
  {
LABEL_115:
    v123 = DDS3_GBWK->unitwork;
    badstatus = v123->m_Items[statindex]->badstatus;
    if ((badstatus & 0x800) != 0)
    {
      v126 = 5;
    }
    else if ((v123->m_Items[statindex]->badstatus & 0x400) != 0)
    {
      v126 = 13;
    }
    else if ((v123->m_Items[statindex]->badstatus & 0x200) != 0)
    {
      v126 = 7;
    }
    else if ((v123->m_Items[statindex]->badstatus & 0x100) != 0)
    {
      v126 = 8;
    }
    else if ((badstatus & 0x80) != 0)
    {
      v126 = 2;
    }
    else if ((badstatus & 0x40) != 0)
    {
      v126 = 10;
    }
    else if ((badstatus & 0x10) != 0)
    {
      v126 = 1;
    }
    else if ((badstatus & 4) != 0)
    {
      v126 = 12;
    }
    else if ((badstatus & 2) != 0)
    {
      v126 = 6;
    }
    else if ((badstatus & 1) != 0)
    {
      v126 = 11;
    }
    else if ((badstatus & 0x20) != 0)
    {
      v126 = 3;
    }
    else if ((badstatus & 8) != 0)
    {
      v126 = 9;
    }
    else
    {
      v126 = -1;
    }
    v127 = get_transform(gameObject, 0);
    v128 = Find(v127, "steff", 0);
    v129 = get_gameObject(v128);
    v130 = GetComponent_object_(v129);
    if (v126 == -1)
      v131 = 0;
    else
      v131 = v126;
    SetInteger(v130, "steff", v131);
  }
}

// 0x121dff0
void nbPanelDrawPP0(s32 x, s32 y, nbMainProcessData_t *p, s32 index) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  u64 *v9;
  System_String_o *v10;
  UnityEngine_Component_o *v11;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GameObject_o *v15;
  Il2CppObject *Component_object;
  Il2CppObject *v19;
  UnityEngine_Transform_o *v20;
  UnityEngine_Component_o *v21;
  UnityEngine_GameObject_o *v22;
  Il2CppObject *v23;
  s32 v24;

  BattleUI = GetBattleUI(1);
  if (!op_Equality(BattleUI, 0, 0))
  {
    v24 = index + 1;
    transform = get_transform(BattleUI, 0);
    v9 = sub_8D3950(s32, &v24);
    v10 = Concat("bparty_window0", v9);
    v11 = Find(transform, v10, 0);
    gameObject = get_gameObject(v11);
    v13 = get_transform(gameObject, 0);
    v14 = Find(v13, "bparty_text01TM", 0);
    v15 = get_gameObject(v14);
    Component_object = GetComponent_object_(v15);
    set_text(Component_object, "");
    v19 = GetComponent_object_(gameObject);
    PnlAnim(v19, "bparty_window", 4);
    v20 = get_transform(gameObject, 0);
    v21 = Find(v20, "steff", 0);
    v22 = get_gameObject(v21);
    v23 = GetComponent_object_(v22);
    SetInteger(v23, "steff", 0);
  }
}

// 0x121e2d0
void nbPanelDrawPP1(s32 x, s32 y, s32 i, s32 j, s32 jun, s32 act, nbMainProcessData_t *p, bool pc_num_hide) {
  u32 v9;
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  u64 *v18;
  System_String_o *v19;
  UnityEngine_Component_o *v20;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  System_String_o *v27;
  UnityEngine_Animator_o *v28;
  s32 v29;
  UnityEngine_Transform_o *v30;
  UnityEngine_Component_o *v31;
  UnityEngine_GameObject_o *v32;
  UnityEngine_Transform_o *v33;
  UnityEngine_Component_o *v34;
  UnityEngine_GameObject_o *v35;
  UnityEngine_Transform_o *v36;
  UnityEngine_Component_o *v37;
  UnityEngine_GameObject_o *v38;
  UnityEngine_Transform_o *v39;
  UnityEngine_Component_o *v40;
  UnityEngine_GameObject_o *v41;
  UnityEngine_Transform_o *v42;
  f32 v43;
  u64 *v44;
  System_String_o *v45;
  UnityEngine_Component_o *v46;
  UnityEngine_GameObject_o *v47;
  UnityEngine_Transform_o *v48;
  u64 *v49;
  System_String_o *v50;
  UnityEngine_Component_o *v51;
  UnityEngine_GameObject_o *v52;
  UnityEngine_Transform_o *v53;
  UnityEngine_Component_o *v54;
  UnityEngine_GameObject_o *v55;
  Il2CppObject *v57;
  u32 v58;
  struct datUnitWork_t_array *unitwork;
  f32 v62;
  f32 v63;
  f32 v64;
  struct datUnitWork_t_array *v67;
  datUnitWork_t_o *v69;
  signed s32 v70;
  s32 v71;
  UnityEngine_Transform_o *v72;
  UnityEngine_Component_o *v73;
  UnityEngine_GameObject_o *v74;
  Il2CppObject *v75;
  struct datUnitWork_t_array *v76;
  CounterCtrBattle_o *v77;
  s32 hp;
  UnityEngine_Transform_o *v80;
  UnityEngine_Component_o *v81;
  UnityEngine_GameObject_o *v82;
  Il2CppObject *v83;
  u32 v84;
  struct datUnitWork_t_array *v85;
  f32 v87;
  f32 v88;
  f32 v89;
  UnityEngine_Transform_o *v92;
  UnityEngine_Component_o *v93;
  UnityEngine_GameObject_o *v94;
  Il2CppObject *v95;
  struct datUnitWork_t_array *v98;
  datUnitWork_t_o *v100;
  signed s32 v101;
  s32 v102;
  UnityEngine_Transform_o *v103;
  UnityEngine_Component_o *v104;
  UnityEngine_GameObject_o *v105;
  Il2CppObject *v106;
  struct datUnitWork_t_array *v107;
  CounterCtrBattle_o *v108;
  s32 mp;
  UnityEngine_Transform_o *v111;
  UnityEngine_Component_o *v112;
  UnityEngine_GameObject_o *v113;
  Il2CppObject *v114;
  struct datUnitWork_t_array *v116;
  TMPro_TMP_Text_o *v117;
  struct datUnitWork_t_array *v120;
  s32 id;
  System_String_o *CNameString;
  struct datUnitWork_t_array *v126;
  s32 v128;
  struct datUnitWork_t_array *v129;
  struct datUnitWork_t_array *v131;
  struct datUnitWork_t_array *v133;
  struct datUnitWork_t_array *v135;
  struct datUnitWork_t_array *v137;
  struct datUnitWork_t_array *v139;
  struct datUnitWork_t_array *v141;
  struct datUnitWork_t_array *v143;
  struct datUnitWork_t_array *v145;
  struct datUnitWork_t_array *v147;
  struct datUnitWork_t_array *v149;
  s32 v151;
  UnityEngine_Transform_o *v152;
  UnityEngine_Component_o *v153;
  UnityEngine_GameObject_o *v154;
  Il2CppObject *v155;
  s32 v156;
  UnityEngine_Color_o v157;

  BattleUI = GetBattleUI(1);
  if (!op_Equality(BattleUI, 0, 0))
  {
    LODWORD(v157.r) = i + 1;
    transform = get_transform(BattleUI, 0);
    v18 = sub_8D3950(s32, &v157);
    v19 = Concat("bparty_window0", v18);
    v20 = Find(transform, v19, 0);
    gameObject = get_gameObject(v20);
    Component_object = GetComponent_object_(gameObject);
    if (act)
    {
      v27 = "bparty_window";
      v28 = Component_object;
      v29 = 2;
    }
    else
    {
      v27 = "bparty_window";
      v28 = Component_object;
      v29 = 0;
    }
    PnlAnim(v28, v27, v29);
    v30 = get_transform(gameObject, 0);
    v31 = Find(v30, "bparty_pc_num/bparty_pc_num1", 0);
    v32 = get_gameObject(v31);
    SetActive(v32, 0, 0);
    v33 = get_transform(gameObject, 0);
    v34 = Find(v33, "bparty_pc_num/bparty_pc_num2", 0);
    v35 = get_gameObject(v34);
    SetActive(v35, 0, 0);
    v36 = get_transform(gameObject, 0);
    v37 = Find(v36, "bparty_pc_num/bparty_pc_num3", 0);
    v38 = get_gameObject(v37);
    SetActive(v38, 0, 0);
    v39 = get_transform(gameObject, 0);
    v40 = Find(v39, "bparty_pc_num/bparty_pc_num4", 0);
    v41 = get_gameObject(v40);
    SetActive(v41, 0, 0);
    if (jun <= 3)
    {
      v42 = get_transform(gameObject, 0);
      LODWORD(v43) = jun + 1;
      v157.r = v43;
      v44 = sub_8D3950(s32, &v157);
      v45 = Concat("bparty_pc_num/bparty_pc_num", v44);
      v46 = Find(v42, v45, 0);
      v47 = get_gameObject(v46);
      SetActive(v47, 1, 0);
      if (pc_num_hide)
      {
        v48 = get_transform(gameObject, 0);
        v157.r = v43;
        v49 = sub_8D3950(s32, &v157);
        v50 = Concat("bparty_pc_num/bparty_pc_num", v49);
        v51 = Find(v48, v50, 0);
        v52 = get_gameObject(v51);
        SetActive(v52, 0, 0);
      }
    }
    v53 = get_transform(gameObject, 0);
    v54 = Find(v53, "barhp/barhp_color", 0);
    v55 = get_gameObject(v54);
    v57 = GetComponent_object_(v55);
    unitwork = DDS3_GBWK->unitwork;
    LOWORD(v9) = unitwork->m_Items[j]->hp;
    v62 = v9;
    LOWORD(v58) = unitwork->m_Items[j]->maxhp;
    v63 = v58;
    v64 = v62 / v63;
    if ((v62 / v63) >= 1.0 || v64 <= 0.925)
    {
      if (v64 > 0.0)
        v64 = fmaxf(v64, 0.075);
    }
    else
    {
      v64 = 0.925;
    }
    set_fillAmount(v57, v64);
    v67 = DDS3_GBWK->unitwork;
    v69 = v67->m_Items[j];
    else if (datCheckDying(v69))
    {
      goto LABEL_52;
    }
    v70 = 100 * v69->hp / v69->maxhp;
    if (v70 >= 25)
    {
      v71 = v70 < 50;
LABEL_53:
      v72 = get_transform(gameObject, 0);
      v73 = Find(v72, "barhp", 0);
      v74 = get_gameObject(v73);
      v75 = GetComponent_object_(v74);
      v76 = DDS3_GBWK->unitwork;
      v77 = v75;
      hp = v76->m_Items[j]->hp;
      *&v157.r = 0;
      *&v157.b = 0;
      sub_19EC630(&v157.r, 1.0, 1.0, 1.0, 1.0);
      Set(v77, hp, v157, v71, 0);
      v80 = get_transform(gameObject, 0);
      v81 = Find(v80, "barmp/barmp_color", 0);
      v82 = get_gameObject(v81);
      v83 = GetComponent_object_(v82);
      v85 = DDS3_GBWK->unitwork;
      LOWORD(v84) = v85->m_Items[j]->mp;
      v87 = v84;
      LOWORD(v84) = v85->m_Items[j]->maxmp;
      v88 = v87 / v84;
      if (v88 >= 1.0 || v88 <= 0.925)
      {
        v89 = v88;
        if (v88 > 0.0)
          v89 = fmaxf(v88, 0.075);
      }
      else
      {
        v89 = 0.925;
      }
      set_fillAmount(v83, v89);
      v92 = get_transform(gameObject, 0);
      v93 = Find(v92, "barmp/barmp_graycolor", 0);
      v94 = get_gameObject(v93);
      v95 = GetComponent_object_(v94);
      set_fillAmount(v95, v88);
      if (get_activeSelf(v94))
        SetActive(v94, 0, 0);
      v98 = DDS3_GBWK->unitwork;
      v100 = v98->m_Items[j];
      v101 = 100 * v100->mp / v100->maxmp;
      if (v101 <= 24)
        v102 = 2;
      else
        v102 = v101 < 50;
      v103 = get_transform(gameObject, 0);
      v104 = Find(v103, "barmp", 0);
      v105 = get_gameObject(v104);
      v106 = GetComponent_object_(v105);
      v107 = DDS3_GBWK->unitwork;
      v108 = v106;
      mp = v107->m_Items[j]->mp;
      *&v157.r = 0;
      *&v157.b = 0;
      sub_19EC630(&v157.r, 1.0, 1.0, 1.0, 1.0);
      Set(v108, mp, v157, v102, 0);
      v111 = get_transform(gameObject, 0);
      v112 = Find(v111, "bparty_text01TM", 0);
      v113 = get_gameObject(v112);
      v114 = GetComponent_object_(v113);
      v116 = DDS3_GBWK->unitwork;
      v117 = v114;
      if ((v116->m_Items[j]->flag & 4) != 0)
      {
        CNameString = frGetCNameString(0);
      }
      else
      {
        v120 = DDS3_GBWK->unitwork;
        id = v120->m_Items[j]->id;
        CNameString = Get(id, 0);
      }
      set_text(v117, CNameString);
      v126 = DDS3_GBWK->unitwork;
      if ((v126->m_Items[j]->badstatus & 0x800) != 0)
        v128 = 5;
      else
        v128 = -1;
      v129 = DDS3_GBWK->unitwork;
      if ((v129->m_Items[j]->badstatus & 0x400) != 0)
        v128 = 13;
      v131 = DDS3_GBWK->unitwork;
      if ((v131->m_Items[j]->badstatus & 0x200) != 0)
        v128 = 7;
      v133 = DDS3_GBWK->unitwork;
      if ((v133->m_Items[j]->badstatus & 0x100) != 0)
        v128 = 8;
      v135 = DDS3_GBWK->unitwork;
      if ((v135->m_Items[j]->badstatus & 0x80) != 0)
        v128 = 2;
      v137 = DDS3_GBWK->unitwork;
      if ((v137->m_Items[j]->badstatus & 0x40) != 0)
        v128 = 10;
      v139 = DDS3_GBWK->unitwork;
      if ((v139->m_Items[j]->badstatus & 0x20) != 0)
        v128 = 3;
      v141 = DDS3_GBWK->unitwork;
      if ((v141->m_Items[j]->badstatus & 0x10) != 0)
        v128 = 1;
      v143 = DDS3_GBWK->unitwork;
      if ((v143->m_Items[j]->badstatus & 8) != 0)
        v128 = 9;
      v145 = DDS3_GBWK->unitwork;
      if ((v145->m_Items[j]->badstatus & 4) != 0)
        v128 = 12;
      v147 = DDS3_GBWK->unitwork;
      if ((v147->m_Items[j]->badstatus & 2) != 0)
        v128 = 6;
      v149 = DDS3_GBWK->unitwork;
      if ((v149->m_Items[j]->badstatus & 1) != 0)
        v151 = 11;
      else
        v151 = v128;
      v152 = get_transform(gameObject, 0);
      v153 = Find(v152, "steff", 0);
      v154 = get_gameObject(v153);
      v155 = GetComponent_object_(v154);
      if (v151 == -1)
        v156 = 0;
      else
        v156 = v151;
      SetInteger(v155, "steff", v156);
      return;
    }
LABEL_52:
    v71 = 2;
    goto LABEL_53;
  }
}

// 0x1224b40
void nbPanelDrawPPnon(s32 index) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  u64 *v6;
  System_String_o *v7;
  UnityEngine_Component_o *v8;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v10;
  UnityEngine_Component_o *v11;
  UnityEngine_GameObject_o *v12;
  Il2CppObject *Component_object;
  Il2CppObject *v16;
  s32 v17;

  BattleUI = GetBattleUI(6);
  if (!op_Equality(BattleUI, 0, 0))
  {
    v17 = index + 1;
    transform = get_transform(BattleUI, 0);
    v6 = sub_8D3950(s32, &v17);
    v7 = Concat("bparty_window0", v6);
    v8 = Find(transform, v7, 0);
    gameObject = get_gameObject(v8);
    v10 = get_transform(gameObject, 0);
    v11 = Find(v10, "bparty_text01TM", 0);
    v12 = get_gameObject(v11);
    Component_object = GetComponent_object_(v12);
    set_text(Component_object, "");
    v16 = GetComponent_object_(gameObject);
    PnlAnim(v16, "bparty_window", 4);
  }
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
        goto LABEL_56;
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
                  goto LABEL_72;
                v31 = v12->form;
                if ((~v31->m_Items[1]->stat & 0x109) == 0)
                  goto LABEL_72;
                v33 = v12->form;
                if ((~v33->m_Items[2]->stat & 0x109) == 0)
                  goto LABEL_72;
                v35 = v12->form;
                if ((~v35->m_Items[3]->stat & 0x109) == 0)
                {
LABEL_72:
                  nbPanelPartySelect(v12);
                  return 0;
                }
              }
LABEL_56:
              if (!*(*(v37 + 184) + 432LL))
              {
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
        goto LABEL_50;
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
        goto LABEL_50;
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
LABEL_50:
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
  u32 *v1;
  u64 *v2;
  u64 *v3;
  u32 *v5;
  s64 v12;
  nbMainProcessData_t_o *v13;
  nbMainProcessData_t_o *v15;
  u64 v16;
  u64 *v17;
  u64 *v18;
  u32 *v19;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v26;
  struct nbFormation_t_array *v28;
  u32 partyindex;
  struct nbParty_t_array *party;
  s32 statindex;
  struct nbFormation_t_array *v36;
  u32 *v39;
  u32 orderindex;
  u32 v41;
  s32 v42;
  struct System_SByte_array *order;
  struct System_SByte_array *v45;
  s32 v46;
  struct System_SByte_array *v50;
  s32 v52;
  struct System_SByte_array *v55;
  s32 v57;
  struct System_SByte_array *v60;
  s32 v62;
  u64 v65;
  u32 *v66;
  u32 v69;
  u32 phase;
  s32 v71;
  bool v72;
  struct System_SByte_array *v76;
  s32 v78;
  nbPanelProcess_c *v81;
  struct nbPanelProcess_typeNbPnlWork_array *v82;
  struct nbPanelProcess_typeNbPnlWork_array *v84;
  s32 v86;
  s32 v87;
  nbPanelProcess_c *v88;
  struct nbPanelProcess_typeNbPnlWork_array *v89;
  struct nbPanelProcess_typeNbPnlWork_array *v91;
  s32 OfsX;
  s32 v94;
  struct nbPanelProcess_typeNbPnlWork_array *v95;
  struct nbPanelProcess_typeNbPnlWork_array *v97;
  struct nbPanelProcess_typeNbPnlWork_array *v100;
  s32 v102;
  struct nbPanelProcess_typeNbPnlWork_array *gnbPnlWork;
  struct nbPanelProcess_typeNbPnlWork_array *v106;
  struct nbPanelProcess_typeNbPnlWork_array *v108;
  struct nbPanelProcess_typeNbPnlWork_array *v110;
  struct nbPanelProcess_typeNbPnlWork_array *v112;
  struct nbPanelProcess_typeNbPnlWork_array *v114;
  struct nbPanelProcess_typeNbPnlWork_array *v116;
  struct nbPanelProcess_typeNbPnlWork_array *v118;
  struct nbPanelProcess_typeNbPnlWork_array *v121;
  s64 v125;
  struct nbPanelProcess_typeNbPnlWork_array *v126;
  struct nbPanelProcess_typeNbPnlWork_array *v130;
  struct nbPanelProcess_typeNbPnlWork_array *v134;
  nbPanelProcess_typeNbPnlWork_o *v136;
  struct datUnitWork_t_array *unitwork;
  struct nbPanelProcess_typeNbPnlWork_array *v140;
  struct nbPanelProcess_typeNbPnlWork_array *v142;
  struct nbPanelProcess_typeNbPnlWork_array *v144;
  nbPanelProcess_typeNbPnlWork_o *v146;
  struct datUnitWork_t_array *v148;
  struct nbPanelProcess_typeNbPnlWork_array *v150;
  struct nbPanelProcess_typeNbPnlWork_array *v154;
  nbPanelProcess_typeNbPnlWork_o *v156;
  struct datUnitWork_t_array *v158;
  struct nbPanelProcess_typeNbPnlWork_array *v160;
  struct nbPanelProcess_typeNbPnlWork_array *v162;
  struct nbPanelProcess_typeNbPnlWork_array *v164;
  struct nbPanelProcess_typeNbPnlWork_array *v167;
  nbPanelProcess_typeNbPnlWork_o *v169;
  struct datUnitWork_t_array *v171;
  struct nbPanelProcess_typeNbPnlWork_array *v173;
  s32 OldMp;
  struct datUnitWork_t_array *v177;
  struct nbPanelProcess_typeNbPnlWork_array *v180;
  s32 v183;
  s32 v186;
  struct nbPanelProcess_typeNbPnlWork_array *v187;
  u64 *v190;
  u32 *v191;
  u64 *v192;
  u32 x;
  u64 *v194;
  u64 *v195;
  u32 *v196;
  nbMainProcessData_t_o *MainProcessData;

  v1 = NewSpecific(s32, 4u);
  v2 = NewSpecific(s32, 4u);
  v3 = NewSpecific(s32, 4u);
  v5 = NewSpecific(s32, 4u);
  if (PanelPartyShow)
  {
    if (Wait_Skill_Doutyo)
    {
      if (!effBTLSkillCheckRun2(0xE8u))
      {
        Wait_Skill_Doutyo = 0;
      }
      return;
    }
    if (effBTLSkillCheckRun2(0xE8u))
    {
      Wait_Skill_Doutyo = 1;
    }
    MainProcessData = nbGetMainProcessData();
    if (MainProcessData)
    {
      v16 = 0;
      v17 = v3 + 4;
      v18 = v2 + 4;
      v19 = v1 + 8;
      v190 = v3;
      v194 = v5 + 8;
      v196 = v5;
      do
      {
        v19[v16] = -1;
        *(v18 + v16) = -1;
        *(v194 + v16) = -1;
        *(v17 + v16) = -1;
        form = MainProcessData->form;
        if ((form->m_Items[v16]->stat & 1) != 0)
        {
          v26 = MainProcessData->form;
          if ((v26->m_Items[v16]->stat & 0x40) != 0)
          {
            v28 = MainProcessData->form;
            partyindex = v28->m_Items[v16]->partyindex;
            party = MainProcessData->party;
            statindex = party->m_Items[partyindex]->statindex;
            v19[v16] = partyindex;
            *(v18 + v16) = statindex;
            v36 = MainProcessData->form;
            v3 = v190;
            if (v36->m_Items[v16]->type == 1)
            {
              *(v17 + v16) = 1;
            }
          }
        }
        ++v16;
      }
      while (v16 != 4);
      v39 = v196;
      if ((MainProcessData->stat & 8) == 0)
      {
        orderindex = MainProcessData->orderindex;
        if (orderindex != -1)
        {
          v41 = 0;
          v42 = 12;
          do
          {
            order = MainProcessData->order;
            if (order->m_Items[orderindex] != 255)
            {
              v45 = MainProcessData->order;
              v46 = v45->m_Items[orderindex];
              if (v1[8] == v46)
              {
                v196[8] = v41++;
              }
              v50 = MainProcessData->order;
              v52 = v50->m_Items[orderindex];
              if (v1[9] == v52)
              {
                v196[9] = v41++;
              }
              v55 = MainProcessData->order;
              v57 = v55->m_Items[orderindex];
              if (v1[10] == v57)
              {
                v196[10] = v41++;
              }
              v60 = MainProcessData->order;
              v62 = v60->m_Items[orderindex];
              if (v1[11] == v62)
              {
                v196[11] = v41++;
              }
            }
            if ((orderindex + 1) < 12)
              ++orderindex;
            else
              orderindex = 0;
            --v42;
          }
          while (v42);
        }
      }
      v192 = v2 + 4;
      v65 = 0;
      v66 = v1 + 8;
      v191 = v196 + 8;
      v195 = v3 + 4;
      while (1)
      {
        if (*(v195 + v65) == -1)
        {
          x = 230;
          if (v65 >= v1[6])
            goto LABEL_111;
        }
        else
        {
          x = dds3GetRandIntA(6u, "") + 227;
          dds3GetRandIntA(6u, "");
          if (v65 >= v1[6])
          {
LABEL_111:
          }
        }
        v69 = v66[v65];
        if (v69 != -1 && MainProcessData->orderindex != 255)
          break;
        if (v69 != -1 && MainProcessData->phase == 2)
          goto LABEL_129;
        if (v69 != -1 && MainProcessData->phase == 9)
          goto LABEL_129;
        if (v69 == -1 || MainProcessData->phase != 15)
        {
          nbPanelDrawPP0(v102, v12, v13, v65);
          gnbPnlWork->m_Items[v65]->ActiveMode = 0;
          v106 = gnbPnlWork;
          v106->m_Items[v65]->OfsX = 0;
          v108 = gnbPnlWork;
          v108->m_Items[v65]->OldHp = -1;
          v110 = gnbPnlWork;
          v110->m_Items[v65]->OldMp = -1;
          v112 = gnbPnlWork;
          v112->m_Items[v65]->HpAnmCnt = 0;
          v114 = gnbPnlWork;
          v114->m_Items[v65++]->MpAnmCnt = 0;
          if (v65 == 4)
            return;
        }
        else
        {
LABEL_129:
          v71 = MainProcessData->orderindex;
LABEL_130:
          v72 = v71 == 255;
          if (v71 == 255)
            LOBYTE(v71) = 0;
LABEL_132:
          v76 = MainProcessData->order;
          v78 = v76->m_Items[v71];
          v3 = v190;
          if (v66[v65] == v78)
          {
            if (v191[v65] != -1)
            {
              v82 = gnbPnlWork;
              v82->m_Items[v65]->ActiveMode = 1;
              v84 = gnbPnlWork;
              v86 = 16 - v84->m_Items[v65]->OfsX;
              if (v86 < 3)
              {
                v87 = 1;
                if ((v81->_2.bitflags2 & 2) != 0)
                  goto LABEL_149;
              }
              else
              {
                v87 = v86 / 3;
                if ((v81->_2.bitflags2 & 2) != 0)
                {
LABEL_149:
                }
              }
              v116 = gnbPnlWork;
              v116->m_Items[v65]->OfsX += v87;
              v118 = gnbPnlWork;
              if (v118->m_Items[v65]->OfsX >= 17)
              {
                v121 = gnbPnlWork;
                v121->m_Items[v65]->OfsX = 16;
              }
LABEL_206:
              if (v65 >= *(v2 + 6))
                goto LABEL_207;
              goto LABEL_208;
            }
          }
          v89 = gnbPnlWork;
          v89->m_Items[v65]->ActiveMode = 0;
          v91 = gnbPnlWork;
          OfsX = v91->m_Items[v65]->OfsX;
          if (OfsX < 3)
          {
            v94 = 1;
            if ((v88->_2.bitflags2 & 2) == 0)
              goto LABEL_165;
          }
          else
          {
            v94 = OfsX / 3;
            if ((v88->_2.bitflags2 & 2) == 0)
              goto LABEL_165;
          }
LABEL_165:
          v95 = gnbPnlWork;
          v95->m_Items[v65]->OfsX -= v94;
          v97 = gnbPnlWork;
          if ((v97->m_Items[v65]->OfsX & 0x80000000) == 0)
            goto LABEL_206;
          v100 = gnbPnlWork;
          v100->m_Items[v65]->OfsX = 0;
          if (v65 >= *(v2 + 6))
          {
LABEL_207:
          }
LABEL_208:
          v125 = *(v192 + v65);
          v126 = gnbPnlWork;
          if (v126->m_Items[v65]->OldHp == -1)
          {
            v134 = gnbPnlWork;
            v136 = v134->m_Items[v65];
            unitwork = DDS3_GBWK->unitwork;
            v136->OldHp = unitwork->m_Items[v125]->hp;
            if (v65 >= *(v190 + 6))
            {
LABEL_215:
            }
          }
          else if (v65 >= *(v190 + 6))
          {
            goto LABEL_215;
          }
          if (*(v195 + v65) == -1)
          {
            v140 = gnbPnlWork;
            if (v140->m_Items[v65]->HpAnmCnt < 1)
            {
              v144 = gnbPnlWork;
              v146 = v144->m_Items[v65];
              v148 = DDS3_GBWK->unitwork;
              v146->OldHp = v148->m_Items[v125]->hp;
              {
LABEL_248:
              }
            }
            else
            {
              v142 = gnbPnlWork;
              --v142->m_Items[v65]->HpAnmCnt;
                goto LABEL_248;
            }
          }
          else
          {
            v130 = gnbPnlWork;
            v130->m_Items[v65]->HpAnmCnt = 8;
              goto LABEL_248;
          }
          v150 = gnbPnlWork;
          if (v150->m_Items[v65]->OldMp != -1)
          {
              goto LABEL_278;
LABEL_265:
            goto LABEL_278;
          }
          v154 = gnbPnlWork;
          v156 = v154->m_Items[v65];
          v158 = DDS3_GBWK->unitwork;
          v156->OldMp = v158->m_Items[v125]->mp;
            goto LABEL_265;
LABEL_278:
          v160 = gnbPnlWork;
          if (v160->m_Items[v65]->MpAnmCnt < 1)
          {
            v173 = gnbPnlWork;
            OldMp = v173->m_Items[v65]->OldMp;
            v177 = DDS3_GBWK->unitwork;
            if (OldMp > v177->m_Items[v125]->mp)
            {
              v180 = gnbPnlWork;
              v180->m_Items[v65]->MpAnmCnt = 8;
            }
          }
          else
          {
            v162 = gnbPnlWork;
            --v162->m_Items[v65]->MpAnmCnt;
            v164 = gnbPnlWork;
            if (v164->m_Items[v65]->MpAnmCnt <= 0)
            {
              v167 = gnbPnlWork;
              v169 = v167->m_Items[v65];
              v171 = DDS3_GBWK->unitwork;
              v169->OldMp = v171->m_Items[v125]->mp;
              if (v65 >= *(v2 + 6))
              {
LABEL_319:
              }
              goto LABEL_320;
            }
          }
          if (v65 >= *(v2 + 6))
            goto LABEL_319;
LABEL_320:
          v183 = *(v192 + v65);
          v186 = v191[v65];
          v187 = gnbPnlWork;
          nbPanelDrawPP1(x, v12, v65, v183, v186, v187->m_Items[v65]->ActiveMode, v15, v72);
          v39 = v196;
          if (++v65 == 4)
            return;
        }
      }
      phase = MainProcessData->phase;
      v71 = MainProcessData->orderindex;
      v72 = 0;
      if (phase > 0xF || ((1 << phase) & 0x8204) == 0)
        goto LABEL_132;
      goto LABEL_130;
    }
  }
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
  UnityEngine_GameObject_o *BattleUI;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v8;
  Il2CppClass **v10;
  System_Int32_c **v11;
  nbMainProcessData_t_o *v12;
  u64 v13;
  s32 v14;
  UnityEngine_Transform_o *transform;
  s64 v16;
  u64 v17;
  u64 *v18;
  System_String_o *v19;
  UnityEngine_Component_o *v20;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  s64 v23;
  struct nbFormation_t_array *form;
  Il2CppObject *v27;
  nbFormation_t_o *v29;
  u32 stat;
  System_Int32_c **v31;
  s32 statindex;
  u32 v34;
  s32 v35;
  System_String_o *v36;
  UnityEngine_Animator_o *v37;
  s32 v38;
  s32 v40;

  BattleUI = GetBattleUI(1);
  if (!op_Equality(BattleUI, 0, 0))
  {
    order = pMainData->order;
    party = pMainData->party;
    v8 = order->m_Items[pMainData->orderindex];
    v10 = &party->obj.klass + v8;
    v11 = &s32;
    v12 = pMainData;
    v13 = 0;
    v14 = WORD2(v10[4]->_1.name);
    do
    {
      transform = get_transform(BattleUI, 0);
      v16 = *v11;
      v17 = v13 + 1;
      v40 = v13 + 1;
      v18 = sub_8D3950(v16, &v40);
      v19 = Concat("bparty_window0", v18);
      v20 = Find(transform, v19, 0);
      gameObject = get_gameObject(v20);
      Component_object = GetComponent_object_(gameObject);
      form = v12->form;
      v27 = Component_object;
      v29 = form->m_Items[v13];
      stat = v29->stat;
      if ((~stat & 0x101) == 0)
      {
        v31 = v11;
        statindex = party->m_Items[v29->partyindex]->statindex;
        v34 = statindex;
        v35 = v14 == statindex;
        if ((stat & 8) != 0)
        {
          nbPanelDrawPP(230, v23, v35, v34, 0x200000u, v13);
          v11 = v31;
          if (v14 == v34)
          {
            v36 = "bparty_window";
            v37 = v27;
            v38 = 3;
          }
          else
          {
            v36 = "bparty_window";
            v37 = v27;
            v38 = 1;
          }
        }
        else
        {
          v11 = v31;
          if (v14 == statindex)
          {
            v36 = "bparty_window";
            v37 = v27;
            v38 = 6;
          }
          else
          {
            v36 = "bparty_window";
            v37 = v27;
            v38 = 5;
          }
        }
        PnlAnim(v37, v36, v38);
        v12 = pMainData;
      }
      ++v13;
    }
    while (v17 != 4);
  }
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
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v17;
  f32 v18;
  f32 v19;
  s32 width;
  s32 v21;
  f32 v22;
  s32 height;
  s32 v24;
  f32 v25;
  UnityEngine_Transform_o *v26;
  UnityEngine_Transform_o *v27;
  UnityEngine_Transform_o *v28;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  s64 v34;
  s64 v35;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector3_o v37;
  UnityEngine_Vector3_o v38;

  if (op_Inequality(obj, 0, 0))
  {
    if (!get_activeSelf(obj))
      SetActive(obj, 1, 0);
    transform = get_transform(obj, 0);
    get_position(transform);
    v17 = get_transform(obj, 0);
    get_localScale(v17);
    v18 = get_width(0) * 0.0019531;
    v19 = ((y + 95) + -224.0) * (get_height(0) / -448.0);
    width = get_width(0);
    if (width >= 0)
      v21 = width;
    else
      v21 = width + 1;
    v22 = (((x + 256) + -256.0) * v18) + (v21 >> 1);
    height = get_height(0);
    if (height >= 0)
      v24 = height;
    else
      v24 = height + 1;
    v25 = (v24 >> 1) + v19;
    v26 = get_transform(obj, 0);
    v37.z = 0.0;
    v37.x = v22;
    v37.y = v25;
    set_position(v26, v37);
    v27 = get_transform(obj, 0);
    v38.z = 1.0;
    v38.x = scale_x;
    v38.y = scale_y;
    set_localScale(v27, v38);
    v28 = get_transform(obj, 0);
    Child = GetChild(v28, 0);
    gameObject = get_gameObject(Child);
    if (op_Inequality(gameObject, 0, 0))
    {
      Component_object = GetComponent_object_(gameObject);
      if (op_Inequality(Component_object, 0, 0))
      {
        v36 = SDF_VU0__Retdds3ColorItoF(abgr_out, 128.0);
        v34 = 0;
        v35 = 0;
        sub_19EC630(&v34, v36.x, v36.y, v36.z, v36.w);
        (Component_object->klass->vtable[23].methodPtr)(
          Component_object,
          Component_object->klass->vtable[23].*&v34,
          *(&v34 + 1),
          *&v35,
          *(&v35 + 1));
      }
    }
  }
}

// 0x121dfd0
void nbPanelPolygonScaleDraw(s32 x, s32 y, nbPanelProcess_nbPanelXYZ_t *pXYZ, f32 scale_w, f32 scale_h, u32 abgr0, u32 abgr1, u32 abgr2, u32 abgr3) {
  ;
}

// 0x12203c0
void nbPanelPressGauge(nbMainProcessData_t *pMainData) {
  UnityEngine_Object_o *BattleUI;
  nbPanelProcess_c *v6;
  s32 press4_p;
  u32 v10;
  s32 v11;
  u32 nbPanelPGBaseColor;
  s32 v14;
  u32 phase;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v19;
  UnityEngine_Component_o *v20;
  UnityEngine_GameObject_o *v22;
  struct nbPanelProcess_StaticFields **p_static_fields;
  u32 stat;
  UnityEngine_Transform_o *v26;
  UnityEngine_Component_o *v27;
  UnityEngine_GameObject_o *v28;
  Il2CppObject *v31;
  UnityEngine_GameObject_o *v32;
  UnityEngine_Transform_o *v33;
  UnityEngine_Component_o *v34;
  UnityEngine_GameObject_o *v35;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *v39;
  UnityEngine_Component_o *v40;
  UnityEngine_GameObject_o *v41;
  UnityEngine_Transform_o *v42;
  UnityEngine_Component_o *v43;
  UnityEngine_GameObject_o *v45;
  Il2CppObject *v49;
  UnityEngine_Transform_o *v52;
  u64 *v54;
  System_String_o *v55;
  UnityEngine_Component_o *v56;
  UnityEngine_GameObject_o *v58;
  s32 i;
  UnityEngine_Transform_o *v61;
  u64 *v62;
  System_String_o *v63;
  UnityEngine_Component_o *v64;
  UnityEngine_Transform_o *v70;
  u64 *v72;
  System_String_o *v73;
  UnityEngine_Component_o *v74;
  UnityEngine_GameObject_o *v75;
  nbPanelProcess_c *v76;
  s32 nbPanelPGNumber;
  s32 v79;
  UnityEngine_Transform_o *v80;
  u64 *v81;
  System_String_o *v82;
  UnityEngine_Component_o *v83;
  UnityEngine_GameObject_o *v84;
  Il2CppObject *v85;
  struct nbPanelProcess_StaticFields **v88;
  s16 v89;
  s32 v90;
  s32 nbPanelPGBirthWait;
  s32 v92;
  UnityEngine_Transform_o *v93;
  u64 *v94;
  System_String_o *v95;
  UnityEngine_Component_o *v96;
  UnityEngine_GameObject_o *v97;
  Il2CppObject *v100;
  s32 v102;
  struct nbPanelProcess_StaticFields *v103;
  u32 v104;
  s32 v105;
  s32 v106;
  UnityEngine_Transform_o *v107;
  UnityEngine_Component_o *v108;
  UnityEngine_GameObject_o *v109;
  Il2CppObject *v112;
  UnityEngine_Transform_o *v113;
  UnityEngine_Component_o *v114;
  UnityEngine_GameObject_o *v115;
  Il2CppObject *v118;
  s32 v119;
  UnityEngine_Transform_o *v121;
  u64 *v122;
  System_String_o *v123;
  UnityEngine_Component_o *v124;
  UnityEngine_GameObject_o *v125;
  Il2CppObject *v128;
  nbPanelProcess_c *v129;
  s32 nbPanelPressGauge_GaugeBlink;
  bool v133;
  s32 nbPanelPressGauge_GaugeNormal;
  UnityEngine_Transform_o *v136;
  u64 *v137;
  System_String_o *v138;
  UnityEngine_Component_o *v139;
  UnityEngine_GameObject_o *v140;
  Il2CppObject *v141;
  s32 v143;
  bool v144;
  s32 v145;
  UnityEngine_Transform_o *v146;
  u64 *v147;
  System_String_o *v148;
  UnityEngine_Component_o *v149;
  UnityEngine_GameObject_o *v150;
  Il2CppObject *v153;
  s16 v155;
  s32 v156;
  System_String_o *v157;
  UnityEngine_Animator_o *v158;
  s32 v159;
  nbMainProcessData_t_o *v160;
  UnityEngine_AnimatorStateInfo_o v161;
  UnityEngine_AnimatorStateInfo_o v162;
  UnityEngine_AnimatorStateInfo_o v163;
  s32 v164;

  memset(&v163, 0, sizeof(v163));
  memset(&v162, 0, sizeof(v162));
  BattleUI = GetBattleUI(2);
  if (op_Equality(BattleUI, 0, 0))
    return;
  else if (!nbPanelPGStart)
  {
    goto LABEL_23;
  }
  if (!pMainData->press4_ten)
    return;
  nbPanelPT_1_Process = 0;
  nbPanelPT_2_Process = 0;
  nbPanelPT_3_Process = 0;
  nbPanelPTAProcess = 1;
  nbPanelPTAFrame = 0;
  nbPanelPTAOnly = 1;
LABEL_23:
  else
  {
    if (nbPanelPGFrame)
      goto LABEL_26;
  }
  press4_p = pMainData->press4_p;
  nbPanelPressGauge_GaugeNormal = press4_p;
  nbPanelPressGauge_GaugeBlink = pMainData->press4_ten;
  nbPanelPressGauge_GaugeNumber = nbPanelPressGauge_GaugeBlink;
  if ((v6->_2.bitflags2 & 2) != 0)
  {
LABEL_27:
  }
LABEL_36:
  v10 = pMainData->stat & 8;
  if (nbPanelPGTurn != v10)
  {
    nbPanelPGTurn = v10;
    nbPanelPGBirthWait = 12;
  }
  if ((*&v6->_2.bitflags1 & 0x200) != 0)
  {
    else
    {
      if (nbPanelPGShow)
        goto LABEL_43;
    }
LABEL_53:
    if (!HIBYTE(nbPanelPGBaseColor))
      return;
    v14 = -268435456;
    goto LABEL_61;
  }
  v11 = 0;
  if (!nbPanelPGShow)
    goto LABEL_53;
LABEL_43:
  if (HIBYTE(nbPanelPGBaseColor) != 128)
  {
    v14 = 0x10000000;
LABEL_61:
    nbPanelPGBaseColor = nbPanelPGBaseColor + v14;
  }
  phase = pMainData->phase;
  if (phase <= 0xF && ((1 << phase) & 0x8204) != 0)
    return;
  transform = get_transform(BattleUI, 0);
  v17 = Find(transform, "bturn_player", 0);
  gameObject = get_gameObject(v17);
  v19 = get_transform(BattleUI, 0);
  v20 = Find(v19, "bturn_enemy", 0);
  v22 = get_gameObject(v20);
  if (nbPanelPGStart)
  {
    stat = pMainData->stat;
    nbPanelPGPress = stat & 8;
    if ((*p_static_fields)->nbPanelPGPress)
    {
      if (!get_activeSelf(v22))
        SetActive(v22, 1, 0);
      if (get_activeSelf(gameObject))
        SetActive(gameObject, 0, 0);
      gameObject = v22;
    }
    else
    {
      if (!get_activeSelf(gameObject))
        SetActive(gameObject, 1, 0);
      if (get_activeSelf(v22))
        SetActive(v22, 0, 0);
    }
    v33 = get_transform(gameObject, 0);
    v34 = Find(v33, "bturn", 0);
    v35 = get_gameObject(v34);
    Component_object = GetComponent_object_(v35);
    PnlAnim(Component_object, "bturn", 1);
    nbPanelPGStart = 0;
    goto LABEL_107;
  }
  if (nbPanelPGPress)
  {
    if (get_activeSelf(gameObject))
    {
      v26 = get_transform(gameObject, 0);
      v27 = Find(v26, "bturn", 0);
      v28 = get_gameObject(v27);
      v31 = GetComponent_object_(v28);
      PnlAnim(v31, "bturn", 2);
      GetCurrentAnimatorStateInfo(&v161, v31, 0);
      v163 = v161;
      if (sub_85F980(&v163, "bturn_out"))
      {
        GetCurrentAnimatorStateInfo(&v161, v31, 0);
        v163 = v161;
        if (sub_85FB40(&v163) >= 1.0)
        {
          set_keepAnimatorControllerStateOnDisable(v31, 0);
          SetActive(gameObject, 0, 0);
        }
      }
    }
    if (!get_activeSelf(v22) && get_activeSelf(gameObject))
    {
      SetActive(v22, 1, 0);
      v32 = v22;
      goto LABEL_240;
    }
  }
  else
  {
    if (get_activeSelf(v22))
    {
      v107 = get_transform(v22, 0);
      v108 = Find(v107, "bturn", 0);
      v109 = get_gameObject(v108);
      v112 = GetComponent_object_(v109);
      PnlAnim(v112, "bturn", 2);
      GetCurrentAnimatorStateInfo(&v161, v112, 0);
      v163 = v161;
      if (sub_85F980(&v163, "bturn_out"))
      {
        GetCurrentAnimatorStateInfo(&v161, v112, 0);
        v163 = v161;
        if (sub_85FB40(&v163) >= 1.0)
        {
          set_keepAnimatorControllerStateOnDisable(v112, 0);
          SetActive(v22, 0, 0);
        }
      }
    }
    if (!get_activeSelf(gameObject) && get_activeSelf(v22))
    {
      SetActive(gameObject, 1, 0);
      v32 = gameObject;
LABEL_240:
      v113 = get_transform(v32, 0);
      v114 = Find(v113, "bturn", 0);
      v115 = get_gameObject(v114);
      v118 = GetComponent_object_(v115);
      PnlAnim(v118, "bturn", 1);
      set_keepAnimatorControllerStateOnDisable(v118, 1);
    }
  }
LABEL_107:
  v39 = get_transform(BattleUI, 0);
  v40 = Find(v39, "bpturn_pl", 0);
  v41 = get_gameObject(v40);
  v42 = get_transform(BattleUI, 0);
  v43 = Find(v42, "bpturn_en", 0);
  v45 = get_gameObject(v43);
  if (nbPanelPGPress)
  {
    if (!get_activeSelf(v45))
      SetActive(v45, 1, 0);
    if (get_activeSelf(v41))
      SetActive(v41, 0, 0);
    v49 = "bpturn_en0";
      goto LABEL_124;
LABEL_122:
    goto LABEL_124;
  }
  if (!get_activeSelf(v41))
    SetActive(v41, 1, 0);
  if (get_activeSelf(v45))
    SetActive(v45, 0, 0);
  v45 = v41;
  v49 = "bpturn_pl0";
    goto LABEL_122;
LABEL_124:
  if (op_Inequality(v41, 0, 0))
  {
    v52 = get_transform(v45, 0);
    v161.m_Name = bpturnCnt + 1;
    v54 = sub_8D3950(s32, &v161);
    v55 = Concat(v49, v54);
    v56 = Find(v52, v55, 0);
    v58 = get_gameObject(v56);
    if (!nbPanelPGNumber)
    {
      for (i = 1; i != 9; ++i)
      {
        v61 = get_transform(v45, 0);
        v161.m_Name = i;
        v62 = sub_8D3950(s32, &v161);
        v63 = Concat(v49, v62);
        v64 = Find(v61, v63, 0);
        v58 = get_gameObject(v64);
        if (nbPanelPGNumber < nbPanelPressGauge_GaugeNumber
          && get_activeSelf(v58))
        {
          SetActive(v58, 0, 0);
        }
      }
    }
    if (!bpturnCnt && !get_activeSelf(v58))
    {
      if (!nbPanelPGNumber)
      {
        bpturnDrawFlag = 0;
      }
    }
    v70 = get_transform(v45, 0);
    v161.m_Name = bpturnCnt + 1;
    v72 = sub_8D3950(s32, &v161);
    v73 = Concat(v49, v72);
    v74 = Find(v70, v73, 0);
    v75 = get_gameObject(v74);
    if (bpturnDrawFlag == 1)
    {
      if (bpturnCnt < nbPanelPGNumber && !get_activeSelf(v75))
        SetActive(v75, 1, 0);
      if (nbPanelPGNumber <= 7)
      {
        v79 = nbPanelPGNumber - 1;
        do
        {
          v80 = get_transform(v45, 0);
          v161.m_Name = v79 + 2;
          v81 = sub_8D3950(s32, &v161);
          v82 = Concat(v49, v81);
          v83 = Find(v80, v82, 0);
          v84 = get_gameObject(v83);
          if (get_activeSelf(v84))
          {
            v85 = GetComponent_object_(v84);
            if ((GetInteger(v85, "bpressturn") - 3) > 1
              || (GetCurrentAnimatorStateInfo(&v161, v85, 0),
                  v162 = v161,
                  sub_85FB40(&v162) > 1.0))
            {
              SetActive(v84, 0, 0);
            }
          }
          ++v79;
        }
        while (v79 < 7);
      }
    }
    ++bpturnCnt;
    if (bpturnCnt >= 8)
    {
      bpturnCnt = 0;
      bpturnDrawFlag = 1;
      if ((v76->_2.bitflags2 & 2) == 0)
        goto LABEL_185;
      goto LABEL_183;
    }
  }
  else
  {
  }
  if ((v76->_2.bitflags2 & 2) != 0)
  {
LABEL_183:
  }
LABEL_185:
  if (nbPanelPGNumber < nbPanelPressGauge_GaugeNumber)
  {
    v89 = *&v76->_2.bitflags1;
    if ((v89 & 0x200) != 0)
    {
      v90 = v89 & 0x200;
      if (!nbPanelPGBirthWait)
        goto LABEL_222;
    }
    else
    {
      v90 = 0;
      if (!nbPanelPGBirthWait)
      {
LABEL_222:
        v105 = 2 * (nbPanelPressGauge_GaugeNumber - nbPanelPGNumber) + 13;
        v106 = nbPanelPGFrame + 1;
        nbPanelPGFrame = v106;
        if (v106 >= v105)
        {
          nbPanelPGNumber = nbPanelPressGauge_GaugeNumber;
          nbPanelPGFrame = 0;
        }
        goto LABEL_293;
      }
    }
    nbPanelPGBirthWait = nbPanelPGBirthWait - 1;
    v103 = *v88;
    if (!(*v88)->nbPanelPGBirthWait)
    {
      v104 = pMainData->stat;
      v103->nbPanelPGPress = v104 & 8;
    }
    goto LABEL_293;
  }
  v160 = pMainData;
  v92 = 0;
  if ((v76->_2.bitflags2 & 2) == 0)
    goto LABEL_194;
LABEL_192:
LABEL_194:
  while (v92 < nbPanelPressGauge_GaugeNormal)
  {
    v93 = get_transform(v45, 0);
    v161.m_Name = ++v92;
    v94 = sub_8D3950(s32, &v161);
    v95 = Concat(v49, v94);
    v96 = Find(v93, v95, 0);
    v97 = get_gameObject(v96);
    v100 = GetComponent_object_(v97);
    PnlAnim(v100, "bpressturn", 1);
      goto LABEL_192;
  }
  if (effBTLSkillCheckRun2(0xDBu))
    goto LABEL_206;
  if (effBTLSkillCheckRun2(0xDCu))
  {
LABEL_206:
    nbPanelPressGauge_PlusSkillOn = 1;
  }
  v102 = 0;
LABEL_275:
  v164 = v102;
  while (1)
  {
    v119 = v92;
    if (v92 >= nbPanelPressGauge_GaugeBlink)
      break;
    v121 = get_transform(v45, 0);
    ++v92;
    v161.m_Name = v119 + 1;
    v122 = sub_8D3950(s32, &v161);
    v123 = Concat(v49, v122);
    v124 = Find(v121, v123, 0);
    v125 = get_gameObject(v124);
    v128 = GetComponent_object_(v125);
    PnlAnim(v128, "bpressturn", 2);
    if (nbPanelPressGauge_GaugeFlash == nbPanelPressGauge_GaugeBlink - nbPanelPressGauge_GaugeNormal)
      goto LABEL_267;
    else if (nbPanelPressGauge_PlusSkillOn)
    {
      goto LABEL_267;
    }
    Play_8777152(v128, "bpressturn_charge", 0, 0.0);
    if (v119 != nbPanelPressGauge_GaugeBlink - 1)
    {
LABEL_267:
      if ((v129->_2.bitflags2 & 2) != 0)
        goto LABEL_268;
LABEL_269:
      if (nbPanelPressGauge_PlusSkillOn)
        goto LABEL_270;
    }
    else
    {
      nbPanelPressGauge_GaugeFlash = nbPanelPressGauge_GaugeBlink - nbPanelPressGauge_GaugeNormal;
      if ((v129->_2.bitflags2 & 2) == 0)
        goto LABEL_269;
LABEL_268:
        goto LABEL_269;
      if (nbPanelPressGauge_PlusSkillOn)
      {
LABEL_270:
        GetCurrentAnimatorStateInfo(&v161, v128, 0);
        v163 = v161;
        if (!sub_85F980(&v163, "bpressturn_charge"))
        {
          GetCurrentAnimatorStateInfo(&v161, v128, 0);
          v163 = v161;
          v133 = sub_85F980(&v163, "bpressturn_out");
          v92 = v119 + 1;
          v102 = 1;
          if (v133)
          {
            PnlAnim(v128, "bpressturn", 0);
            v102 = 1;
          }
          goto LABEL_275;
        }
      }
    }
  }
  if ((v76->_2.bitflags2 & 2) != 0)
  {
    pMainData = v160;
  }
  else
  {
    pMainData = v160;
  }
  if (!(v164 & 1 | !nbPanelPressGauge_PlusSkillOn))
  {
    if ((v76->_2.bitflags2 & 2) != 0)
    {
LABEL_287:
    }
    while (nbPanelPressGauge_GaugeNormal < nbPanelPressGauge_GaugeBlink
                                          - nbPanelPressGauge_GaugeNormal)
    {
      v136 = get_transform(v45, 0);
      v161.m_Name = ++nbPanelPressGauge_GaugeNormal;
      v137 = sub_8D3950(s32, &v161);
      v138 = Concat(v49, v137);
      v139 = Find(v136, v138, 0);
      v140 = get_gameObject(v139);
      v141 = GetComponent_object_(v140);
      Play_8777152(v141, "bpressturn_charge", 0, 0.0);
      nbPanelPressGauge_PlusSkillOn = 0;
      if ((v76->_2.bitflags2 & 2) != 0)
        goto LABEL_287;
    }
  }
LABEL_293:
  if (nbPanelPGNumber > nbPanelPressGauge_GaugeNumber)
  {
    v143 = nbPanelPGFrame + 1;
    v144 = nbPanelPGFrame - 9 < 0;
    nbPanelPGFrame = v143;
    if (v144 == __OFSUB__(v143, 10))
    {
      nbPanelPGNumber = nbPanelPressGauge_GaugeNumber;
      nbPanelPGFrame = 0;
    }
    v145 = nbPanelPGNumber;
    if ((v76->_2.bitflags2 & 2) != 0)
    {
LABEL_311:
    }
    while (2)
    {
      if (v145 <= nbPanelPressGauge_GaugeNumber)
        return;
      v146 = get_transform(v45, 0);
      v161.m_Name = v145;
      v147 = sub_8D3950(s32, &v161);
      v148 = Concat(v49, v147);
      v149 = Find(v146, v148, 0);
      v150 = get_gameObject(v149);
      v153 = GetComponent_object_(v150);
      if (pMainData->press4_hansya || pMainData->press4_miss)
      {
        if ((v155 & 0x200) != 0)
        {
          v156 = v155 & 0x200;
          if (nbPanelPGNumber == 1)
            goto LABEL_325;
LABEL_318:
          v157 = "bpressturn";
          v158 = v153;
          v159 = 4;
        }
        else
        {
          v156 = 0;
          if (nbPanelPGNumber != 1)
            goto LABEL_318;
LABEL_325:
          if (v156)
          {
LABEL_326:
          }
LABEL_329:
          v157 = "bpressturn";
          v158 = v153;
          v159 = 3;
        }
        PnlAnim(v158, v157, v159);
        --v145;
          goto LABEL_311;
        continue;
      }
      break;
    }
      goto LABEL_326;
    goto LABEL_329;
  }
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
  Write("nbPanelPressGaugeReset\n", 0);
LABEL_10:
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
  u32 stat;

  MainProcessData = nbGetMainProcessData();
  else
  {
    if (nbPanelPGShow)
      goto LABEL_22;
  }
  if (nbPanelPGEncount)
  {
LABEL_22:
    if ((v4->_2.bitflags2 & 2) == 0)
      goto LABEL_25;
    goto LABEL_23;
  }
  Write("nbPanelPressGaugeShow : Reset\n", 0);
  stat = MainProcessData->stat;
  nbPanelPGPress = stat & 8;
  nbPanelPGNumber = MainProcessData->press4_ten;
  nbPanelPGFrame = 0;
  if ((v4->_2.bitflags2 & 2) != 0)
  {
LABEL_23:
  }
LABEL_25:
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
  nbPanelProcess_c *v5;
  struct nbPanelProcess_StaticFields *static_fields;
  s32 v7;
  s16 v8;
  s32 v9;
  bool v10;
  s32 nbPanelPTAFrame;
  s32 v13;
  s32 v15;
  s32 v16;
  u32 stat;
  struct nbPanelProcess_StaticFields **p_static_fields;
  struct nbPanelProcess_StaticFields *v20;
  s32 v21;
  struct nbPanelProcess_StaticFields **v22;
  s32 v25;
  struct nbPanelProcess_StaticFields **v30;
  u32 nbPanelPT_3_Process;
  struct nbPanelProcess_StaticFields **v36;
  s32 v37;
  UnityEngine_GameObject_o *BattleUI;
  u32 v40;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v42;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v44;
  UnityEngine_Component_o *v45;
  UnityEngine_GameObject_o *v46;
  UnityEngine_Transform_o *v47;
  UnityEngine_Component_o *v48;
  UnityEngine_GameObject_o *v50;
  s64 *v52;
  u32 v53;
  s32 v56;
  UnityEngine_Object_o *nbPanelPTP_0_Obj;
  UnityEngine_Transform_o *v59;
  UnityEngine_Component_o *v60;
  UnityEngine_GameObject_o *v61;
  UnityEngine_Transform_o *v62;
  UnityEngine_Component_o *v63;
  UnityEngine_Transform_o *v65;
  UnityEngine_Component_o *v66;
  UnityEngine_GameObject_o *v68;
  Il2CppObject *Component_object;
  s32 nbPanelPTP_1_Frame;
  struct nbPanelProcess_StaticFields *v72;
  s32 v73;
  s64 v74;
  s64 v76;
  s32 v78;
  s32 v80;
  s32 v81;
  struct nbPanelProcess_StaticFields **v83;
  struct nbPanelProcess_StaticFields *v84;

  if (nbPanelPressTurnRun())
  {
    switch (nbPanelPTAProcess)
    {
      case 1u:
        v7 = nbPanelPTAFrame + 1;
        nbPanelPTAFrame = v7;
        if (v7 < 0)
          goto LABEL_67;
        nbPanelPTAFrame = 0;
        nbPanelPTAProcess = 2;
        v8 = *&v5->_2.bitflags1;
        if ((v8 & 0x200) == 0)
          goto LABEL_68;
        goto LABEL_73;
      case 2u:
        v9 = nbPanelPTAFrame + 1;
        v10 = nbPanelPTAFrame - 5 < 0;
        nbPanelPTAFrame = v9;
        if (v10 != __OFSUB__(v9, 6))
          goto LABEL_67;
        nbPanelPTAFrame = 0;
        nbPanelPTAProcess = 3;
        nbPanelPTARate_S = 0.1;
        nbPanelPTARate_E = 0.1;
        v8 = *&v5->_2.bitflags1;
        if ((v8 & 0x200) != 0)
          goto LABEL_73;
        goto LABEL_68;
      case 3u:
        if (nbPanelPTAFrame >= 4)
        {
          if (nbPanelPTAFrame <= 7)
          {
            nbPanelPTARate_E = nbPanelPTARate_E * 1.85;
          }
        }
        v13 = nbPanelPTAFrame;
        v15 = nbPanelPTAFrame + 1;
        v10 = nbPanelPTAFrame - 11 < 0;
        nbPanelPTAFrame = v15;
        if (v10 == __OFSUB__(v15, 12))
        {
          nbPanelPTAFrame = 0;
          nbPanelPTAProcess = 4;
        }
        goto LABEL_67;
      case 4u:
        stat = pMainData->stat;
        nbPanelPGPress = stat & 8;
        nbPanelPTAProcess = 0;
        v8 = *&v5->_2.bitflags1;
        if ((v8 & 0x200) != 0)
          goto LABEL_73;
        goto LABEL_68;
      default:
LABEL_67:
        v8 = *&v5->_2.bitflags1;
        if ((v8 & 0x200) != 0)
        {
LABEL_73:
          v16 = v8 & 0x200;
        }
        else
        {
LABEL_68:
          v16 = 0;
        }
        if (nbPanelPTAOnly)
        {
          if (v16)
          {
LABEL_78:
          }
LABEL_356:
          if ((byte_3F590A2 & 1) != 0)
          {
LABEL_358:
            nbPanelBaseABGR = -2139062144;
            nbPanelBaseRGBA = -2139062144;
            return;
          }
LABEL_357:
          goto LABEL_358;
        }
        switch (nbPanelPT_1_Process)
        {
          case 1u:
            ++nbPanelPT_1_Frame;
            v20 = *p_static_fields;
            if ((*p_static_fields)->nbPanelPT_1_Frame < 14)
              goto LABEL_110;
            v21 = 2;
            break;
          case 2u:
            ++nbPanelPT_1_Frame;
            v20 = *p_static_fields;
            if ((*p_static_fields)->nbPanelPT_1_Frame < 20)
              goto LABEL_110;
            v21 = 3;
            break;
          case 3u:
            ++nbPanelPT_1_Frame;
            v20 = *p_static_fields;
            if ((*p_static_fields)->nbPanelPT_1_Frame < 20)
              goto LABEL_110;
            v21 = 4;
            break;
          case 4u:
            nbPanelPT_1_Process = 0;
            if ((v5->_2.bitflags2 & 2) == 0)
              goto LABEL_117;
            goto LABEL_111;
          default:
            goto LABEL_110;
        }
        v20->nbPanelPT_1_Process = v21;
        (*p_static_fields)->nbPanelPT_1_Frame = 0;
LABEL_110:
        if ((v5->_2.bitflags2 & 2) != 0)
        {
LABEL_111:
        }
        break;
    }
LABEL_117:
    switch (nbPanelPT_2_Process)
    {
      case 1u:
        ++nbPanelPT_2_Frame;
        if (nbPanelPT_2_Frame < 6)
          goto LABEL_166;
        v25 = 2;
        goto LABEL_160;
      case 2u:
        ++nbPanelPT_2_Frame;
        if (nbPanelPT_2_Frame < 6)
          goto LABEL_166;
        nbPanelPT_2_Process = 3;
        (*v22)->nbPanelPT_2_Frame = 0;
        (*v22)->nbPanelPT_2_Rate = 0.1;
        if ((v5->_2.bitflags2 & 2) == 0)
          goto LABEL_169;
        goto LABEL_167;
      case 3u:
        nbPanelPT_2_Rate = nbPanelPT_2_Rate * 1.35;
        if (nbPanelPT_2_Rate > 1.0)
        {
          nbPanelPT_2_Rate = 1.0;
        }
        ++nbPanelPT_2_Frame;
        if (nbPanelPT_2_Frame < 10)
          goto LABEL_166;
        nbPanelPT_2_Process = 4;
        nbPanelPT_2_Frame = 0;
        if ((v5->_2.bitflags2 & 2) == 0)
          goto LABEL_169;
        goto LABEL_167;
      case 4u:
        ++nbPanelPT_2_Frame;
        if (nbPanelPT_2_Frame < 33)
          goto LABEL_166;
        v25 = 5;
LABEL_160:
        nbPanelPT_2_Process = v25;
        (*v22)->nbPanelPT_2_Frame = 0;
        if ((v5->_2.bitflags2 & 2) == 0)
          goto LABEL_169;
        goto LABEL_167;
      case 5u:
        nbPanelPT_2_Process = 0;
        goto LABEL_166;
      default:
LABEL_166:
        if ((v5->_2.bitflags2 & 2) != 0)
        {
LABEL_167:
        }
LABEL_169:
        if (nbPanelPT_3_Process != 3)
        {
          if (nbPanelPT_3_Process == 2)
          {
            ++nbPanelPT_3_Frame;
            if (nbPanelPT_3_Frame >= 20)
            {
              nbPanelPT_3_Process = 3;
              (*v30)->nbPanelPT_3_Frame = 0;
            }
          }
          else if (nbPanelPT_3_Process == 1)
          {
            nbPanelPT_3_Rate = nbPanelPT_3_Rate * 1.35;
            if (nbPanelPT_3_Rate > 1.0)
            {
              nbPanelPT_3_Rate = 1.0;
            }
            ++nbPanelPT_3_Frame;
            if (nbPanelPT_3_Frame >= 20)
            {
              nbPanelPT_3_Process = 2;
              nbPanelPT_3_Frame = 0;
              if ((v5->_2.bitflags2 & 2) == 0)
                goto LABEL_204;
              goto LABEL_193;
            }
          }
          if ((v5->_2.bitflags2 & 2) == 0)
            goto LABEL_204;
          goto LABEL_193;
        }
        nbPanelPT_3_Process = 0;
        if ((v5->_2.bitflags2 & 2) == 0)
        {
LABEL_204:
          switch (nbPanelPTP_0_Process)
          {
            case 0u:
              v37 = nbPanelPTP_0_Frame + 1;
              v10 = nbPanelPTP_0_Frame - 5 < 0;
              nbPanelPTP_0_Frame = v37;
              if (v10 == __OFSUB__(v37, 6))
              {
                nbPanelPTP_0_Frame = 0;
                nbPanelPTP_0_Process = 1;
                nbPanelPTP_0_Obj = 0;
                BattleUI = GetBattleUI(4);
                {
                }
                if (op_Inequality(BattleUI, 0, 0))
                {
                  SetActive(BattleUI, 1, 0);
                  v40 = pMainData->stat;
                  transform = get_transform(BattleUI, 0);
                  v42 = Find(transform, "bturnchg_player", 0);
                  gameObject = get_gameObject(v42);
                  if ((v40 & 8) != 0)
                  {
                    SetActive(gameObject, 0, 0);
                    v59 = get_transform(BattleUI, 0);
                    v60 = Find(v59, "bturnchg_enemy", 0);
                    v61 = get_gameObject(v60);
                    SetActive(v61, 1, 0);
                    v62 = get_transform(BattleUI, 0);
                    v63 = Find(v62, "bturnchg_enemy", 0);
                    v50 = get_gameObject(v63);
                    v52 = &"bturnchg_enemy/bturnchg";
                  }
                  else
                  {
                    SetActive(gameObject, 1, 0);
                    v44 = get_transform(BattleUI, 0);
                    v45 = Find(v44, "bturnchg_enemy", 0);
                    v46 = get_gameObject(v45);
                    SetActive(v46, 0, 0);
                    v47 = get_transform(BattleUI, 0);
                    v48 = Find(v47, "bturnchg_player", 0);
                    v50 = get_gameObject(v48);
                    v52 = &"bturnchg_player/bturnchg";
                  }
                  nbPanelPTP_0_Obj = v50;
                  v65 = get_transform(BattleUI, 0);
                  v66 = Find(v65, *v52, 0);
                  v68 = get_gameObject(v66);
                  {
                  }
                  if (op_Inequality(v68, 0, 0))
                  {
                    Component_object = GetComponent_object_(v68);
                    Play_8766576(Component_object, "bturn_change");
                  }
                }
              }
              goto LABEL_267;
            case 1u:
              if (nbPanelPTP_1_Process != 3)
                goto LABEL_267;
              nbPanelPTP_0_Frame = 0;
              (*v36)->nbPanelPTP_0_ABGR = -2139062144;
              (*v36)->nbPanelPTP_0_Process = 2;
                goto LABEL_270;
              goto LABEL_268;
            case 2u:
              v53 = effColorBlend(0x80808080, 0x80A0A0A0, nbPanelPTP_0_Frame / 18.0);
              nbPanelPTP_0_ABGR = v53;
              v56 = nbPanelPTP_0_Frame + 1;
              v10 = nbPanelPTP_0_Frame - 17 < 0;
              nbPanelPTP_0_Frame = v56;
              if (v10 != __OFSUB__(v56, 18))
                goto LABEL_267;
              nbPanelPTP_0_Frame = 0;
              nbPanelPTP_0_ABGR = -2136956768;
              nbPanelPTP_0_Process = 3;
                goto LABEL_270;
              goto LABEL_268;
            case 3u:
              if (nbPanelPTP_1_Process != 5)
                goto LABEL_267;
              nbPanelPTP_0_Frame = 0;
              (*v36)->nbPanelPTP_0_Process = 4;
              nbPanelPTP_0_Obj = (*v36)->nbPanelPTP_0_Obj;
              {
              }
              if (!op_Inequality(nbPanelPTP_0_Obj, 0, 0))
                goto LABEL_267;
              SetActive(nbPanelPTP_0_Obj, 0, 0);
                goto LABEL_270;
              goto LABEL_268;
            default:
LABEL_267:
              {
LABEL_268:
              }
LABEL_270:
              switch (nbPanelPTP_1_Process)
              {
                case 0u:
                  nbPanelPTP_1_Frame = nbPanelPTP_1_Frame + 1;
                  if (nbPanelPTP_1_Frame >= 4)
                  {
                    nbPanelPTP_1_Frame = 0;
                    v73 = 1;
                    goto LABEL_354;
                  }
                  break;
                case 1u:
                  v74 = -1;
                  do
                  {
                    v76 = nbPanelPTP_1_Frame;
                    ++v74;
                  }
                  while (v74 < v76);
                  nbPanelPTP_1_Frame = v76 + 1;
                  if (v76 >= 4)
                  {
                    nbPanelPTP_1_Frame = 0;
                    v73 = 2;
                    goto LABEL_354;
                  }
                  break;
                case 2u:
                  if ((v5->_2.bitflags2 & 2) != 0)
                  {
                          v5 = nbPanelProcess,
                    {
                    }
                  }
                  v78 = nbPanelPTP_1_Frame;
                  nbPanelPTP_1_Frame = v78 + 1;
                  if (v78 >= 8)
                  {
                    nbPanelPTP_1_Frame = 1;
                    nbPanelPTP_1_Rate = 1.0;
                    v73 = 3;
                    goto LABEL_354;
                  }
                  break;
                case 3u:
                  nbPanelPTP_1_Rate = nbPanelPTP_1_Rate * 0.75;
                  v80 = nbPanelPTP_1_Frame;
                  nbPanelPTP_1_Frame = v80 + 1;
                  if (v80 >= 18)
                  {
                    nbPanelPTP_1_Frame = 0;
                    v73 = 4;
                    goto LABEL_354;
                  }
                  break;
                case 4u:
                  v81 = nbPanelPTP_1_Frame;
                  nbPanelPTP_1_Frame = v81 + 1;
                  if (v81 >= 8)
                  {
                    nbPanelPTP_1_Frame = 0;
                    nbPanelPTP_1_Rate = 1.0;
                    v73 = 5;
                    goto LABEL_354;
                  }
                  break;
                case 5u:
                  if (nbPanelPTP_1_Frame >= 8)
                  {
                    nbPanelPTP_1_Rate = nbPanelPTP_1_Rate * 1.25;
                  }
                  if (nbPanelPTP_1_Frame <= 9
                    && (v5->_2.bitflags2 & 2) != 0
                  {
                  }
                  ++nbPanelPTP_1_Frame;
                  if (nbPanelPTP_1_Frame >= 14)
                  {
                    if ((v5->_2.bitflags2 & 2) == 0
                          v5 = nbPanelProcess,
                          v83 = &nbPanelProcess->static_fields,
                          v84 = nbPanelProcess->static_fields,
                          nbPanelPTP_1_Frame >= 10))
                    {
                      nbPanelPTP_1_Frame = 0;
                      v72 = *v83;
                      v73 = 6;
LABEL_354:
                      nbPanelPTP_1_Process = v73;
                    }
                  }
                  break;
                default:
                  break;
              }
              if ((v5->_2.bitflags2 & 2) == 0)
                goto LABEL_356;
              goto LABEL_78;
          }
        }
LABEL_193:
        goto LABEL_204;
    }
  }
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
  else
  {
    if (nbPanelPT_1_Process)
      return 1;
  }
  else if (nbPanelPT_2_Process)
  {
    return 1;
  }
  if (!nbPanelPT_3_Process)
  {
    if (!nbPanelPTAProcess)
    {
      if (!nbPanelPTP_1_Process)
        return 0;
    }
  }
  return 1;
}

// 0x1221ca0
void nbPanelPressTurnStart(void) {
  s16 v5;
  s32 v6;
  struct nbPanelProcess_StaticFields **p_static_fields;

  Write("nbPanelPressTurnStart\n", 0);
  nbGetMainProcessData();
  if ((v5 & 0x200) != 0)
  {
    v6 = v5 & 0x200;
    if (nbPanelPTOmit)
      goto LABEL_11;
  }
  else
  {
    v6 = 0;
    if (nbPanelPTOmit)
    {
LABEL_11:
      nbPanelPTOmit = 0;
      return;
    }
  }
  nbPanelPT_1_Process = 1;
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
  if (nbPanelPGTurn != nbPanelPGTurnOld)
  {
    nbPanelPTAProcess = 1;
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
      goto LABEL_3;
LABEL_18:
  }
  if (!LODWORD(pXYZ->wh->max_length))
    goto LABEL_18;
LABEL_3:
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
      goto LABEL_3;
LABEL_16:
  }
  max_length = pXYZ->xyz->max_length;
  if (!max_length)
    goto LABEL_16;
LABEL_3:
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
      goto LABEL_3;
LABEL_16:
  }
  max_length = pXYZ->xyz->max_length;
  if (!max_length)
    goto LABEL_16;
LABEL_3:
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
      goto LABEL_3;
LABEL_19:
  }
  max_length = pCenter->pm->max_length;
  if (!max_length)
    goto LABEL_19;
LABEL_3:
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
      goto LABEL_3;
LABEL_18:
  }
  max_length = pXYZ->wh->max_length;
  if (!max_length)
    goto LABEL_18;
LABEL_3:
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
      goto LABEL_3;
LABEL_18:
  }
  max_length = pXYZ->wh->max_length;
  if (!max_length)
    goto LABEL_18;
LABEL_3:
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
  struct System_UInt32_array *v19;
  u32 v21;
  s32 v22;
  u32 v23;
  struct System_UInt32_array *StockIDList;
  struct datUnitWork_t_array *unitwork;
  struct System_UInt32_array *v30;

  if (!pad)
    goto LABEL_12;
  if (!nbPanelStockPad)
    goto LABEL_12;
LABEL_7:
  v5 = nbPanelStockSelectCtrl(v4, *&pad);
LABEL_13:
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
        if (v14 == StockIDListCursor)
        {
LABEL_29:
          v21 = *(&StockIDList->obj.klass + 4 * v14 + v15);
          v22 = 1;
          v23 = 2097176;
          goto LABEL_35;
        }
      }
      else
      {
        v17 = 0;
        if (v14 == StockIDListCursor)
          goto LABEL_29;
      }
      v19 = StockIDList;
      v21 = *(&v19->obj.klass + 4 * v14 + v15);
      v22 = 0;
      v23 = 24;
LABEL_35:
      nbPanelDrawPP(0, v11, v22, v21, v23, v14);
      unitwork = DDS3_GBWK->unitwork;
      v30 = StockIDList;
      if (StockIDListTop + 1 + v14 < StockIDListCount && v14++ < 3)
        continue;
      break;
    }
  }
  else if (nbPanelStockFrame > 4)
  {
    goto LABEL_56;
  }
LABEL_56:
  if ((v13->_2.bitflags2 & 2) == 0)
    goto LABEL_57;
LABEL_53:
LABEL_57:
  ++nbPanelStockFrame;
  return v5;
}

// 0x12240b0
u32 nbPanelStockSelectCtrl(nbMainProcessData_t *pMainData) {
  s16 v5;
  s32 v6;
  struct nbPanelProcess_StaticFields *static_fields;
  s32 v10;
  s32 v11;
  s32 StockIDListCount;
  s32 StockIDListCursor;
  nbPanelProcess_c *v34;
  struct nbPanelProcess_StaticFields **p_static_fields;
  s16 v37;
  s32 v38;
  s32 v39;

  else if (nbPanelStockFrame < 8)
  {
    return -1;
  }
  if (!DDS3_PADCHECK_REP(6))
    goto LABEL_35;
LABEL_11:
  if ((v5 & 0x200) != 0)
  {
    v6 = v5 & 0x200;
    if (StockIDListTop < 1)
      goto LABEL_13;
LABEL_27:
    else
    {
      v11 = StockIDListCursor;
      if (v11 == 1)
        goto LABEL_30;
    }
    v10 = v11 - 1;
    goto LABEL_121;
  }
  v6 = 0;
  if (StockIDListTop >= 1)
    goto LABEL_27;
LABEL_13:
  if (StockIDListCursor >= 1)
  {
    nbPlaySe(4);
    v10 = StockIDListCursor - 1;
LABEL_121:
    StockIDListCursor = v10;
    return -1;
  }
  if (DDS3_PADCHECK_TRIG(6))
  {
    if (StockIDListCursor)
      return -1;
    v37 = *&v34->_2.bitflags1;
    if ((v37 & 0x200) != 0)
    {
      v38 = v37 & 0x200;
      v39 = StockIDListCount;
      if (v39 < 4)
        goto LABEL_135;
    }
    else
    {
      v38 = 0;
      v39 = StockIDListCount;
      if (v39 < 4)
      {
LABEL_135:
        if (v39 >= 2)
        {
          nbPlaySe(4);
        }
        StockIDListTop = 0;
        v10 = StockIDListCount - 1;
        goto LABEL_121;
      }
    }
    StockIDListTop = v39 - 4;
    static_fields = *p_static_fields;
    v10 = 3;
    goto LABEL_121;
  }
  return -1;
}

// 0x1223c70
void nbPanelStockSelectInit(void) {
  u64 v4;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Int32_array *stocklist;
  struct datUnitWork_t_array *unitwork;
  s64 v10;
  struct datUnitWork_t_array *v13;
  struct datUnitWork_t_array *v16;
  struct datUnitWork_t_array *v19;
  struct datUnitWork_t_array *v22;
  struct System_UInt32_array *StockIDList;
  s64 StockIDListCount;

  nbGetMainProcessData();
  StockIDListCursor = 0;
  StockIDListTop = 0;
  nbPanelStockFrame = 0;
  nbPanelStockShiftX = 300;
  StockIDListCount = 0;
  v4 = 0;
  {
LABEL_12:
  }
  while (1)
  {
    if (v4 >= DDS3_GBWK->stockcnt)
      break;
    else
    {
      stocklist = DDS3_GBWK->stocklist;
      if (v4 >= LODWORD(stocklist->max_length))
        goto LABEL_18;
    }
    unitwork = DDS3_GBWK->unitwork;
    v10 = stocklist->m_Items[v4];
    if ((unitwork->m_Items[v10]->flag & 1) != 0)
    {
      v13 = DDS3_GBWK->unitwork;
      if ((v13->m_Items[v10]->flag & 4) == 0)
      {
        v16 = DDS3_GBWK->unitwork;
        if ((v16->m_Items[v10]->flag & 2) == 0)
        {
          v19 = DDS3_GBWK->unitwork;
          if (!v19->m_Items[v10]->hp)
            goto LABEL_46;
          v22 = DDS3_GBWK->unitwork;
          if (v22->m_Items[v10]->badstatus == 2048)
          {
LABEL_46:
            StockIDList->m_Items[StockIDListCount] = v10;
            ++StockIDListCount;
          }
        }
      }
    }
    ++v4;
      goto LABEL_12;
  }
  LODWORD(v29[2].klass->vtable[9].methodPtr) = -2139062144;
  HIDWORD(v29[2].klass->vtable[9].methodPtr) = 0;
  LODWORD(v29[2].klass->vtable[8].method) = 1;
  HIDWORD(v29[2].klass->vtable[8].method) = 1;
  nbPanelPartyHide();
  StkSelDisp(1);
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
    v5 = Find(transform, "bturn_player/bturn", 0);
    gameObject = get_gameObject(v5);
    Component_object = GetComponent_object_(gameObject);
    set_keepAnimatorControllerStateOnDisable(Component_object, 0);
    v8 = get_transform(BattleUI, 0);
    v9 = Find(v8, "bturn_enemy/bturn", 0);
    v10 = get_gameObject(v9);
    v11 = GetComponent_object_(v10);
    set_keepAnimatorControllerStateOnDisable(v11, 0);
    v12 = get_transform(BattleUI, 0);
    v13 = Find(v12, "bpturn_pl", 0);
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
    v23 = Find(v22, "bpturn_en", 0);
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
    v5 = Find(transform, "bauto", 0);
    gameObject = get_gameObject(v5);
    SetActive(gameObject, 1, 0);
    v7 = get_transform(BattleUI, 0);
    v8 = Find(v7, "bturn_player", 0);
    v9 = get_gameObject(v8);
    SetActive(v9, 0, 0);
    v10 = get_transform(BattleUI, 0);
    v11 = Find(v10, "bturn_enemy", 0);
    v12 = get_gameObject(v11);
    SetActive(v12, 0, 0);
    v13 = get_transform(BattleUI, 0);
    v14 = Find(v13, "bpturn_pl", 0);
    v15 = get_gameObject(v14);
    SetActive(v15, 0, 0);
    v16 = get_transform(BattleUI, 0);
    v17 = Find(v16, "bpturn_en", 0);
    v18 = get_gameObject(v17);
    SetActive(v18, 0, 0);
  }
}
