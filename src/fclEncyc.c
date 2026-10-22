#include "types.h"

typedef struct CounterCtr CounterCtr;
typedef struct _FRQ _FRQ;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fclEncyc_DEBUG_PHASE fclEncyc_DEBUG_PHASE;
typedef struct fclEncyc_FLAG_READMAIN fclEncyc_FLAG_READMAIN;
typedef struct fclEncyc_PHASE fclEncyc_PHASE;
typedef struct fclEncyc_STAT fclEncyc_STAT;
typedef struct fclEncyc_VIEWKEY fclEncyc_VIEWKEY;
typedef struct fclEncyc_debug_t fclEncyc_debug_t;
typedef struct fclEncyc_instance_tag fclEncyc_instance_tag;
typedef struct fclEncyc_readmainwork_tag fclEncyc_readmainwork_tag;
typedef struct fclEncyc_readtopwork_tag fclEncyc_readtopwork_tag;
typedef struct fclEncyc_registconfirmwork_tag fclEncyc_registconfirmwork_tag;
typedef struct fclEncyc_registtopwork_tag fclEncyc_registtopwork_tag;
typedef struct fclPanel_t fclPanel_t;
typedef struct fclRibbon_t fclRibbon_t;
typedef struct fclencyceelem_t fclencyceelem_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct sdf3DScreenParam_t sdf3DScreenParam_t;
typedef struct sdf3DViewportPacket_t sdf3DViewportPacket_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct smnUI smnUI;
typedef struct statusUI statusUI;
typedef struct talkUI talkUI;

struct fclEncyc_instance_tag {
    sdfVector4_t pos_camera;
    sdfVector4_t pos_camera_target;
    f32 screen_ofsx;
    f32 screen_ofsy;
    sdfMemHandle_t *memhandle;
    dds3ProcessID_t *procid[3];
    sdfTexHandle_t *texhandle[7];
    u32 stat;
    s16 phase;
    s16 next_phase;
    s32 stack[2];
    s16 lw_cur[4];
    s8 sort;
    s8 viewkeytype;
    s16 req_model;
    s32 num_nakama;
    u8 pnakamaindex[12];
    s16 praceindex[185];
    s16 plevelindex[185];
    void *pbmd;
    s32 ctr;
    sdfMemHandle_t *mhwork;
    void *pwork;
    s32 RepeatSw;
    s32 XAngle;
    bool StatusBack;
};

struct fclEncyc_debug_t {
    sdfMemHandle_t *memhandle;
    s16 phase;
    s16 menu_cursor;
    s16 top;
    s16 offset;
};

struct fclEncyc_registtopwork_tag {
    u8 ismsgend;
    u8 reserved0;
    u16 reserved1;
    lstListWindow_t *listwin;
    fclPanel_t *panel;
    s32 pp_id[12];
    _FRQ *ppfont[12];
    dds3ProcessID_t *scr_proc;
};

struct fclEncyc_registconfirmwork_tag {
    u8 flag;
    u8 period;
    s16 unitindex;
    s32 status_alpha;
    s32 x_now;
    s32 inc_now;
    s32 x_rec;
    s32 inc_rec;
    sdfIVector2_t *regist_pos;
    s32 regist_inc;
    s16 regist_alpha;
    u8 dispregist;
    u8 reserved;
    datUnitWork_t *unit_rec;
    datUnitWork_t *unit_now;
    fclRibbon_t *pribbon;
    dds3ProcessID_t *scr_proc;
    s32 b_MsgEnd;
};

struct fclEncyc_readtopwork_tag {
    lstListWindow_t *listwin;
    fclPanel_t *panel;
    fclRibbon_t *pribbon;
    _FRQ *pfont_head;
    _FRQ *pfont_num;
    _FRQ *pfont_reg;
    _FRQ *ppfont[9];
    u8 linemark[9];
};

struct fclEncyc_readmainwork_tag {
    s16 recindex;
    u16 flags;
    s32 mak;
    s32 msgid;
    sdfIVector4_t *ribbon_pos;
    s16 ribbon_alpha;
    s16 status_alpha;
    s32 ribbon_accel[2];
    f32 radius;
    f32 rot_x;
    sdfVector2_t bound_rot_x;
    sdfVector2_t bound_radius;
    sdfIVector2_t *vir_pos;
    sdfIVector4_t *bound_pos;
    s32 back_y;
    s16 back_alpha;
    s16 explain_alpha;
    sdfIVector2_t *viewhelp_pos;
    s32 viewhelp_inc;
    s16 viewhelp_alpha;
    s16 viewhelp_ctr;
    sdfIVector2_t *summon_pos;
    s32 summon_inc;
    s16 summon_alpha;
    s16 reserved;
    fclRibbon_t *pribbon;
    _FRQ *pfont_maka;
    dds3ProcessID_t *scr_proc;
    datUnitWork_t *unit;
    s32 msgno;
    char *dvlrace;
    char *dvlname;
    s32 display_money;
};

struct fclEncyc_FLAG_READMAIN {
    u16 value__;
};

struct fclEncyc_VIEWKEY {
    u32 value__;
};

struct fclEncyc_DEBUG_PHASE {
    s32 value__;
};

struct fclEncyc_STAT {
    s32 value__;
};

struct fclEncyc_PHASE {
    s32 value__;
};

static u32 ANALOG_L_LEFT;
static u32 ANALOG_L_RIGHT;
static u32 ANALOG_L_UP;
static u32 ANALOG_L_DOWN;
static u32 ANALOG_R_LEFT;
static u32 ANALOG_R_RIGHT;
static u32 ANALOG_R_UP;
static u32 ANALOG_R_DOWN;
static s32 CONFIRN_N_BLEND;
static char *menuReadPhase[3];
static char *menuRegistPhase[2];
static bool Registed;
static s32 RegNum;
static dds3DefaultMain *pKernel;
static fclEncyc_instance_tag *g_pinst;
static fclEncyc_debug_t *g_pdebug;
static sdfIVector4_t *g_uv_underline;
static sdfIVector4_t *g_uv_hp;
static sdfIVector4_t *g_uv_mp;
static sdfIVector4_t *g_uv_tri0;
static sdfIVector4_t *g_uv_tri1;
static sdfIVector4_t *g_uv_mak0;
static sdfIVector4_t *g_uv_mak1;
static sdfIVector4_t *g_uv_limk;
static sdfIVector4_t *g_uv_summon_back;
static sdfIVector4_t *g_uv_summon;
static sdfIVector4_t *g_uv_regist;
static sdfIVector4_t *g_uv_money;
static sdfIVector4_t *g_uv_maka;
static sdfIVector4_t *g_color_std;
static char *g_pstr[2];
static u16 ZensyoDevilID[186];

s32 AcceptKeyChangeSort(fclEncyc_instance_tag *pinst);
s32 AcceptKeyListWindow(lstListWindow_t *plistwin, s32 flag);
void AcceptKeyRegistConfirm(fclEncyc_instance_tag *pinst);
void ApplyChangeListIndex(lstListWindow_t *plistwin, s16 **ptable, s32 val);
s32 CMP_XM(s32 a);
s32 CMP_YM(s32 b);
void CalcListElemColor(lstListWindow_t *plistwin, _FRQ **ppfont, s32 disprow, u32 basecol);
void CalcMoveReadMainHelp(fclEncyc_readmainwork_tag *pwork);
void CalcMoveRegistKeyHelp(fclEncyc_registconfirmwork_tag *pwork);
void CalcMoveViewModeRibbon(fclEncyc_readmainwork_tag *pwork);
void ChangeDevilObjectReadMain(s32 recindex, fclEncyc_instance_tag *pinst);
void ChangeDevilObjectRegistConfirm(s32 unitindex, fclEncyc_instance_tag *pinst);
void ChangeModelMotion(s32 id, dds3ModelHandle_t *model, u32 stat);
bool CheckLevelLimit(s32 lv1, s32 lv2);
bool CheckStatusUI(void);
void CirculateDevilObject(fclEncyc_instance_tag *pinst, s32 dsn);
void ClearMessage(void);
s32 CompareUnitToRecord(datUnitWork_t *punit, fclencyceelem_t *pelem);
void ControlModel(fclEncyc_instance_tag *pinst, dds3ModelHandle_t *model, u32 pad);
void CreateFontExplain(fclEncyc_instance_tag *pinst);
void CreateFontListRead(fclEncyc_readtopwork_tag *pwork, s32 sort, s16 **pindex);
void CreateSortIndexByLevel(s16 ***pout);
void CreateSortIndexByRace(s16 ***pout);
bool DDS3_PAD2CHECK_PRESS(s32 id);
bool DDS3_PAD2CHECK_REP(s32 id);
bool DDS3_PAD2CHECK_TRIG(s32 id);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_PRESS2(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void DebugRemoveRecord(s32 id);
void DebugUpdateListwin(fclEncyc_instance_tag *pinst);
void DevilStatusMode(bool flag, bool stat);
void DispRegistConfirm(bool sw);
void Display(talkUI *this, bool sw);
void DisplayOn(smnUI *this);
void DrawBackBlackBoard(s32 y, s32 alpha);
void DrawBackPanel(char *name);
void DrawCaption2(char *name, char *caption, void *txt);
void DrawExplainBack(statusUI *ui, s32 alpha);
void DrawListWindowBack(void *obj, lstListWindow_t *plistwin);
s32 DrawMessage(_FRQ *pfont);
void DrawModePanel(statusUI *ui, s32 mode, s32 alpha, char **list, bool bar);
void DrawModePanelText(void *obj, char **list, s32 csr, bool sw);
void DrawPhaseRegistConfirm(fclEncyc_instance_tag *pinst);
void DrawReadListSortBar(fclEncyc_instance_tag *pinst);
void DrawReadListwinElem(void *obj, void *rule, fclEncyc_instance_tag *pinst);
void DrawReadMainHelp(fclEncyc_instance_tag *pinst);
void DrawReadStatusMoney(fclEncyc_instance_tag *pinst);
void DrawRegistListwinElem(void *obj, fclEncyc_instance_tag *pinst);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
void DrawStatus1Shot(fclEncyc_instance_tag *pinst);
void DrawSummonMoney(fclEncyc_instance_tag *pinst, bool sw);
void DrawSummonMoneyReset(fclEncyc_instance_tag *pinst);
void DrawSummonMoneyStart(fclEncyc_instance_tag *pinst);
void ExecSummon(s32 recindex);
void FadeInRibbon(fclEncyc_readmainwork_tag *pwork);
void FadeOutRibbon(fclEncyc_readmainwork_tag *pwork);
void FadeOutWindow(void);
void FillIndex(s32 ***idx);
u8 Get(s32 id);
s32 GetAnalogPad(void);
void *GetAnimator(void *obj);
s32 GetDevilParam(fclencyceelem_t *pelem, s32 type);
char *GetEncyc(s32 id);
void *GetGameObject(char *name);
bool GetOrUsed(s32 idx);
s32 GetValidUnitIndex(u8 **pindex);
u32 GetViewModeKey(fclEncyc_instance_tag *pinst);
void InitCameraForViewMode(fclEncyc_instance_tag *pinst);
void InitListWindow(lstListWindow_t *plistwin, fclPanel_t *ppanel, sdfIVector4_t *pos, sdfIVector4_t *cur, sdfIVector4_t *pnl, s32 row, s32 disprow, s32 curstep);
void InitModelPosRot(dds3ModelHandle_t *model, s32 id);
void InitializeInstance(fclEncyc_instance_tag *pinst);
bool IsDLC(void);
void LoadCollectionBook(void);
void Log(char *fmt, void **parray);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void MoveScreenOffset(fclEncyc_instance_tag *pinst);
void PopListwinCursor(fclEncyc_instance_tag *pinst, lstListWindow_t *plistwin, s32 Stack);
s32 PrepSummon(fclEncyc_readmainwork_tag *pwork);
s32 RegistAll(fclEncyc_instance_tag *pinst);
void RegistModePanel(statusUI *ui, char **list);
void ReleaseFontExplain(fclEncyc_instance_tag *pinst, s32 release_mesmng);
void ReleaseFontList(_FRQ **ppfont, s32 num);
void RemakeFldSky(void);
char *RepColTag(char *txt, void **LegacyParamArray);
void RequestModelLoad(fclEncyc_instance_tag *pinst, s32 id);
void ResetCameraPos(fclEncyc_instance_tag *pinst);
void ResetReadMainRibbon(fclEncyc_readmainwork_tag *pwork);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void Set2(CounterCtr *this, s32 val, sdfColor_t col, s32 colidx);
void Set3DParam(fclEncyc_instance_tag *pinst);
void SetBoundControl(fclEncyc_instance_tag *pinst);
void SetButtonGuide(s32 mode, bool sw);
void SetCameraLightParam(fclEncyc_instance_tag *pinst);
void SetElem(fclencyceelem_t *pelem, datUnitWork_t *punit);
void SetRecordToUnit(datUnitWork_t *punit, s32 id);
void SetRecordToUnitCore(datUnitWork_t *punit, fclencyceelem_t *pelem);
void StatusBackProcess(fclEncyc_instance_tag *pinst);
void StatusFrontProcess(fclEncyc_instance_tag *pinst, s32 mode);
void StatusTitleOff(void);
void UnloadCollectionBook(void);
void UpdateDrawFlag(char *name);
void UpdateItemCursor(void *csrobj, cmpCursorPos_t *csr, f32 y, f32 ofsy);
void WindowDispOff(bool sw);
s32 datAddDevil(s32 id, s32 sw);
s32 datCheckStockFull(void);
s32 datGetLevelForDraw(datUnitWork_t *work);
s32 datSearchDevilStock(s32 id);
void datUnitWork_t__Clear(datUnitWork_t *this);
void datUnitWork_t__Copy(datUnitWork_t *this, datUnitWork_t *dat);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
dds3Basic_t *dds3GetActiveScene(void);
s32 dds3GetFrameID(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3Printf(char *str, void **LegacyParamArray);
void dds3SetAmbientColor(u32 frame, sdfVector4_t col);
void dds3SetFogColor(u32 frame, sdfVector4_t col);
void dds3SetFogPara(u32 frame, f32 max, f32 min, f32 near, f32 far);
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col);
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir);
void dds3SetSoftenBias(u32 frame, f32 soften, f32 bias);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible);
s32 draw_race_devil(fclEncyc_instance_tag *pinst);
void draw_status_off(bool sw);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
s8 fclChkMessageDraw(dds3ProcessID_t *PID);
s8 fclChkSignal(s8 Idx);
void fclClearSignal(s8 Idx);
s32 fclEncycGetNumForDLC(void);
s32 fclEncycGetRatio2(void);
s32 fclEncycKillProcess(void);
s32 fclEncycRegist(datUnitWork_t *punit, s32 overwrite, bool update);
s32 fclEncycSearch(s32 id);
void fclInitPanel(fclPanel_t *pPanel, s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Type, s8 Spd);
void fclRbnCalc(fclRibbon_t *phandle);
fclRibbon_t *fclRbnInit(s32 num, s32 act, sdfTexHandle_t *tex0, sdfTexHandle_t *tex1);
fclRibbon_t *fclRbnInitSort(s32 act);
void fclRbnRelease(fclRibbon_t *phandle);
void fclRbnSetPara(fclRibbon_t *phandle, s32 index, sdfIVector4_t *ppos_act, sdfIVector4_t *ppos_deact, sdfIVector4_t *puv_act, sdfIVector4_t *puv_deact, sdfTexHandle_t *tex_act, sdfTexHandle_t *tex_deact);
void fclRbnSwitchActive(fclRibbon_t *phandle, s32 index);
void fclRbnSwitchActiveSort(fclRibbon_t *phandle, s32 index);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
void fclSetPanelFlag(fclPanel_t *panel, u32 flag);
s8 fclSetVal(s8 Idx, s32 Val);
void fclencyceelem_t__Clear(fclencyceelem_t *this);
void fclencyceelem_t__Copy(fclencyceelem_t *this, fclencyceelem_t *data);
_FRQ *frDestroyFontRequestNow(_FRQ *pFRQ);
u8 frDisableMode(s8 Flag);
u8 frEnableMode(s8 Flag);
void frSetDrawSpeed(_FRQ *pFRQ, u8 Speed);
void frSetFontColor(_FRQ *pFRQ, u32 Color);
_FRQ *frwGetSmallFontFRQ2_20603280(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ);
_FRQ *frwGetSmallNumFontFRQ_20603536(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ);
_FRQ *itfMesMngGetFRQ(s32 id, s32 message);
s32 itfMesMngInitialize(void *presource, char **master_text, char *key);
void itfMesMngMarkBitStat(s32 id, u32 flag);
void itfMesMngRelease(s32 id);
s32 itfMesMngRequestMessage(s32 id, s32 message, s32 page, s32 callmode);
void itfMesMngRequestMessageRelease(s32 id, s32 cls_speaker);
void itfMesMngSetDefaultSpeed(s32 id, s32 speed);
void itfMesMngSetMesPosition(s32 id, s32 x, s32 y);
void itfMesMngSetVar(s32 id, s32 index, s32 num, s32 type);
void itfMiscDrawSpritePlanePrim(sdfIVector4_t *pos, sdfIVector4_t *color, u32 z, s32 context, sdfDrawTag_t *pdrawtag);
void itfMiscDrawSpritePrim(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, sdfTexHandle_t *texhandle, s32 context, sdfDrawTag_t *pdrawtag);
void itfMiscDrawSpritePrim2(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, s32 context, sdfDrawTag_t *pdrawtag);
void lstInitListWindow(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Style, lstListWindow_t *pListWindow);
void lstMoveCursor(lstListWindow_t *pListWindow, s8 Dir);
s32 lstPageDown(lstListWindow_t *plistwin);
s32 lstPageUp(lstListWindow_t *plistwin);
void mdlLink(dds3ModelHandle_t **aHandle, sdfModelOt_t **aModelOt);
void mdlSetMotionSpeed(dds3ModelHandle_t **aHandle, f32 speed);
void mdlSmoothLoopMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);
s32 p2sdPlaySE(s32 a);
void p2sdPlaySE_20173184(char *define_name);
void reset_viewmode(fclEncyc_instance_tag *pinst);
void sdf3DMakeScreenParam(sdf3DScreenParam_t **aParam);
void sdf3DMakeViewportPacket(sdf3DViewportPacket_t *aPacket, sdf3DScreenParam_t *aParam, sdfMatrix4_t *aCamera);
void sdf3DSetCamera(sdf3DScreenParam_t *aParam, sdfMatrix4_t *aCamera);
f32 sdfCos(f32 aRadius);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
sdfIVector2_t *sdfIVector2_t__Create(s32 x, s32 y);
sdfIVector4_t *sdfIVector4_t__Create(s32 x, s32 y, s32 z, s32 w);
f32 sdfSin(f32 aRadius);

// 0x11a3130
s32 AcceptKeyChangeSort(fclEncyc_instance_tag *pinst) {
  fclEncyc_readtopwork_tag_o *pwork;
  fclEncyc_readtopwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  lstListWindow_t_o *listwin;
  u32 v10;
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  System_Int16_array *plevelindex;
  struct System_Int16_array *praceindex;
  s64 v18;
  s32 v20;
  s32 sort;
  s64 v25;
  System_Int16_array *v26;
  cmpCursorInfo_t_o *v28;
  u64 v30[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readtopwork_tag, v30);
      if ((v30[0] & 1) != 0)
        v6 = v30[2];
      else
        v6 = v30 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  listwin = pwork->listwin;
  v10 = cmpChkCommonInput(0x30000u);
LABEL_17:
  if (cmpChkStatusModelLoadStat() == 1 || v10 != 0x20000 && v10 != 0x10000)
    return 0;
  pinst->sort ^= 1u;
  CursorInfo = listwin->CursorInfo;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  if (pinst->sort)
  {
    praceindex = pinst->praceindex;
    plevelindex = pinst->plevelindex;
    v18 = CursorIndex;
    if (CursorIndex >= LODWORD(praceindex->max_length))
      goto LABEL_28;
  }
  else
  {
    plevelindex = pinst->praceindex;
    praceindex = pinst->plevelindex;
    v18 = CursorIndex;
    if (CursorIndex >= LODWORD(praceindex->max_length))
    {
LABEL_28:
    }
  }
  v20 = praceindex->m_Items[v18];
  ApplyChangeListIndex(listwin, plevelindex, v20);
  fclRbnSwitchActiveSort(pwork->pribbon, pinst->sort);
  cmpPlaySE(v10);
  sort = pinst->sort;
  v25 = 128;
  if (!pinst->sort)
    v25 = 120;
  v26 = *(&pinst->klass + v25);
  CreateFontListRead(pwork, sort, v26);
  v28 = pwork->listwin->CursorInfo;
  cmpInitCursorEff(v28);
  return 1;
}

// 0x119d4c0
s32 AcceptKeyListWindow(lstListWindow_t *plistwin, s32 flag) {
  struct cmpCursorInfo_t_o *CursorInfo;
  s32 v8;
  u32 v9;
  u32 v11;
  s32 v12;
  s32 v13;
  lstListWindow_t_o *v14;
  s8 v15;
  s32 v16;
  cmpCursorInfo_t_o *v17;
  u32 v18;
  bool v20;
  u32 v21;

  CursorInfo = plistwin->CursorInfo;
  if (flag)
  {
    else if (!DDS3_PADCHECK_PRESS(6))
    {
      goto LABEL_7;
    }
    v8 = 192;
    goto LABEL_38;
  }
  if (!DDS3_PADCHECK_PRESS(6))
  {
    if (!DDS3_PADCHECK_PRESS(7))
      lstMoveCursor(plistwin, 0);
  }
  v8 = 8;
LABEL_38:
  v9 = CMP_PE_NORMAL | v8;
  v11 = cmpChkCommonInput(v9);
  if (v11 > 8)
  {
    if (v11 <= 0x20)
    {
      if (v11 == 16)
      {
        v13 = 2 * (CursorInfo->StopFlag == 0);
        v14 = plistwin;
        v15 = -1;
        goto LABEL_60;
      }
      if (v11 == 32)
      {
        v13 = 2 * (CursorInfo->StopFlag == 0);
        v14 = plistwin;
        v15 = 1;
LABEL_60:
        lstMoveCursor(v14, v15);
        v12 = 0;
        goto LABEL_63;
      }
LABEL_56:
      v12 = 0;
      v13 = 0;
      goto LABEL_63;
    }
    if (v11 == 64)
    {
      v16 = lstPageUp(plistwin);
    }
    else
    {
      if (v11 != 128)
        goto LABEL_56;
      v16 = lstPageDown(plistwin);
    }
    v12 = v16;
    v13 = 2;
    goto LABEL_63;
  }
  if (v11 == 1)
  {
    v12 = 0;
    v13 = 1;
    goto LABEL_63;
  }
  if (v11 == 2)
  {
    v12 = 0;
    v13 = -1;
    goto LABEL_63;
  }
  if (v11 != 8)
    goto LABEL_56;
  p2sdPlaySE(8);
  v12 = 0;
  v13 = 3;
LABEL_63:
  v17 = plistwin->CursorInfo;
  v18 = cmpDisablePadBitStop(v17, v11, 0x30u);
  if (v12)
    v20 = 1;
  else
    v20 = flag == 0;
  if (v20)
    v21 = v18;
  else
    v21 = v18 & 0xFFFFFF3F;
  cmpPlaySE(v21);
  return v13;
}

// 0x11a07d0
void AcceptKeyRegistConfirm(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u32 v9;
  u32 v11;
  char v15;
  bool v19;
  s32 v21;
  u64 v26[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registconfirmwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registconfirmwork_tag, v26);
      if ((v26[0] & 1) != 0)
        v6 = v26[2];
      else
        v6 = v26 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v9 = cmpChkCommonInput(0x30033u);
  v11 = cmpChkCommonInputPress(0x30033u);
LABEL_20:
  if (cmpChkStatusModelLoadStat() != 1)
  {
    if (v9 > 0x10)
    {
      if (v9 == 32)
      {
        CirculateDevilObject(pinst, 1);
          goto LABEL_72;
      }
      else
      {
        if (v9 != 0x10000 && v9 != 0x20000)
        {
LABEL_44:
          if (!v11)
            pinst->RepeatSw = 0;
          return;
        }
        v15 = LOBYTE(pwork[1].klass) ^ 1;
        LOBYTE(pwork[1].klass) = v15;
        CMB_GBWK->bReadPhase = v15 == 1;
        fclRbnSwitchActive(pwork[4].monitor, LOBYTE(pwork[1].klass) ^ 1, 0);
          goto LABEL_72;
      }
    }
    else
    {
      switch (v9)
      {
        case 1u:
          fclRbnSwitchActive(pwork[4].monitor, 1);
          LOBYTE(pwork[1].klass) = 0;
          else
          {
            v19 = 0;
          }
          CMB_GBWK->bReadPhase = v19;
          fclClearSignal(0);
          v21 = pinst->num_nakama < 2;
          fclSetVal(8, v21);
          pwork[5].klass = 0;
          pwork[5].klass = fclScriptStart(CMB_GBWK->pScriptData, 16, &pwork[5]);
          LODWORD(pwork[5].monitor) = 0;
          SetButtonGuide(-1, 0);
          BYTE6(pwork[3].klass) = 0;
          BYTE1(pwork[1].klass) = 1;
          cmpSetActiveStatusUIParts(0, 0, 0);
            goto LABEL_72;
          break;
        case 2u:
          pinst->stat |= 2u;
          pinst->next_phase = 0;
          {
LABEL_72:
            cmpPlaySE(v9);
            return;
          }
          break;
        case 0x10u:
          CirculateDevilObject(pinst, 0);
            goto LABEL_72;
          break;
        default:
          goto LABEL_44;
      }
    }
    goto LABEL_72;
  }
}

// 0x11a0f50
void AdjustStackCursor(s32 numlist, s16 *pindex, s16 *pshift) {
  s16 v4;
  s32 v5;

  v4 = numlist - 1;
  if (numlist >= 1)
  {
    v5 = *pindex;
    if (v5 + 12 >= numlist)
    {
      if (*pshift + v5 < numlist)
        v4 = *pshift;
      if (v5 >= 1)
      {
        v4 = *pshift;
        LOWORD(v5) = v5 - 1;
      }
      *pindex = v5;
      *pshift = v4;
    }
  }
}

// 0x11ae9e0
void ApplyChangeListIndex(lstListWindow_t *plistwin, s16 **ptable, s32 val) {
  struct cmpCursorInfo_t_o *CursorInfo;
  struct cmpCursorSize_t_o *CursorSize;
  struct cmpCursorPos_t_o *CursorPos;
  signed s64 num;
  u64 v14;
  s32 Shift;
  s32 v17;
  u32 ListNums;
  u32 ShiftMax;
  s16 v20;
  bool v21;
  u32 v22;
  s16 v23;
  struct cmpCursorInfo_t_o *v25;
  struct cmpCursorSize_t_o *v26;
  struct cmpCursorPos_t_o *v27;
  s32 v28;
  s32 v29;
  s32 v30;
  u8 v31;
  s32 v32;
  s32 Index;
  bool v34;
  s32 v35;

  CursorInfo = plistwin->CursorInfo;
  CursorSize = CursorInfo->CursorSize;
  CursorPos = CursorInfo->CursorPos;
LABEL_12:
  num = DDS3_GBWK->encyc_record->num;
  if (num < 1)
    return;
  v14 = 0;
  while (1)
  {
    if (ptable->m_Items[v14] == val)
      break;
    if (++v14 >= num)
      return;
  }
  Shift = CursorPos->Shift;
  v17 = v14 - Shift;
  if (v14 - Shift < 0)
  {
    LOBYTE(v23) = 0;
    CursorPos->Index = 0;
    goto LABEL_34;
  }
  ListNums = CursorPos->ListNums;
  ShiftMax = CursorPos->ShiftMax;
  v20 = ListNums - ShiftMax;
  if (v17 > (ListNums - ShiftMax))
  {
    v21 = ListNums >= ShiftMax;
    if (ListNums <= ShiftMax)
      ListNums = CursorPos->ShiftMax;
    v22 = ListNums + Shift - ShiftMax;
    if (v21)
      v23 = v20;
    else
      v23 = 0;
    CursorPos->Index = v23;
    if (v22 == v14)
    {
LABEL_35:
        goto LABEL_40;
      goto LABEL_36;
    }
LABEL_34:
    CursorPos->Shift = v14 - v23;
    CursorPos->DrawShift = v14 - v23;
    CursorSize->Y = CursorSize->DefY + CursorInfo->StepY * (v14 - v23);
    goto LABEL_35;
  }
  CursorPos->Index = v17;
  {
LABEL_40:
    v25 = plistwin->CursorInfo;
    v26 = v25->CursorSize;
    v27 = v25->CursorPos;
    v28 = v27->Shift;
    if (!v27->Shift)
    {
LABEL_44:
      Index = v27->Index;
      v34 = __OFSUB__(Index, 1);
      v35 = Index - 1;
      if (v35 < 0 != v34)
        return;
      v27->Index = v35;
      *&v27->Shift = 257;
      v32 = v26->DefY + v25->StepY;
      goto LABEL_46;
    }
    goto LABEL_41;
  }
LABEL_36:
    goto LABEL_40;
  v25 = plistwin->CursorInfo;
  v26 = v25->CursorSize;
  v27 = v25->CursorPos;
  v28 = v27->Shift;
  if (!v27->Shift)
    goto LABEL_44;
LABEL_41:
  v29 = v27->ShiftMax;
  if (v29 - 1 == v28)
  {
    v30 = v27->Index;
    if (v30 + v29 < v27->ListNums)
    {
      v31 = v28 - 1;
      v27->Shift = v31;
      v27->DrawShift = v31;
      v27->Index = v30 + 1;
      v32 = v26->DefY + v25->StepY * v31;
LABEL_46:
      v26->Y = v32;
    }
  }
}

// 0x11aeca0
void ApplyEdgeListCursor(lstListWindow_t *plistwin) {
  struct cmpCursorInfo_t_o *CursorInfo;
  struct cmpCursorSize_t_o *CursorSize;
  struct cmpCursorPos_t_o *CursorPos;
  s32 Shift;
  s32 ShiftMax;
  s32 v7;
  u8 v8;
  s32 v9;
  s32 Index;
  bool v11;
  s32 v12;

  CursorInfo = plistwin->CursorInfo;
  CursorSize = CursorInfo->CursorSize;
  CursorPos = CursorInfo->CursorPos;
  Shift = CursorPos->Shift;
  if (!CursorPos->Shift)
  {
    Index = CursorPos->Index;
    v11 = __OFSUB__(Index, 1);
    v12 = Index - 1;
    if (v12 < 0 != v11)
      return;
    CursorPos->Index = v12;
    *&CursorPos->Shift = 257;
    v9 = CursorSize->DefY + CursorInfo->StepY;
    goto LABEL_7;
  }
  ShiftMax = CursorPos->ShiftMax;
  if (ShiftMax - 1 == Shift)
  {
    v7 = CursorPos->Index;
    if (v7 + ShiftMax < CursorPos->ListNums)
    {
      v8 = Shift - 1;
      CursorPos->Shift = v8;
      CursorPos->DrawShift = v8;
      CursorPos->Index = v7 + 1;
      v9 = CursorSize->DefY + CursorInfo->StepY * v8;
LABEL_7:
      CursorSize->Y = v9;
    }
  }
}

// 0x11a05a0
void CalcConfirmStatus(fclEncyc_registconfirmwork_tag *pwork) {
  s32 status_alpha;
  s32 v3;
  s32 inc_now;
  s32 v5;
  s32 v6;
  s32 v7;
  s32 inc_rec;
  s32 v9;

  status_alpha = pwork->status_alpha;
  if (pwork->flag)
  {
    v3 = status_alpha - 16;
    pwork->status_alpha = v3;
    if (v3 < 0)
    {
      pwork->status_alpha = 0;
    }
    else
    {
      inc_now = pwork->inc_now;
      pwork->x_now += inc_now;
      pwork->inc_now = inc_now - 4;
      v5 = pwork->inc_rec - 4;
      pwork->x_rec -= v5;
      pwork->inc_rec = v5;
    }
  }
  else
  {
    v6 = status_alpha + 16;
    pwork->status_alpha = v6;
    if (v6 < 161)
    {
      v7 = pwork->inc_now + 4;
      inc_rec = pwork->inc_rec;
      v9 = inc_rec + pwork->x_rec;
      pwork->x_now -= v7;
      pwork->inc_now = v7;
      pwork->x_rec = v9;
      pwork->inc_rec = inc_rec + 4;
    }
    else
    {
      pwork->status_alpha = 160;
    }
  }
}

// 0x11a64c0
s32 CalcFadeAlpha(s16 *pval, s32 mode, s32 max_alpha, s32 speed) {
  s16 v5;
  s16 v6;
  _BOOL4 v7;
  s32 v8;

  v5 = speed + *pval;
  if (((*pval - speed) & 0x8000) != 0)
    v6 = 0;
  else
    v6 = *pval - speed;
  v7 = v5 <= max_alpha;
  if (v5 > max_alpha)
    v5 = max_alpha;
  if (mode)
  {
    v6 = v5;
    v8 = v7;
  }
  else
  {
    v8 = ((*pval - speed) & 0x8000) == 0;
  }
  *pval = v6;
  return v8;
}

// 0x119d8e0
void CalcListElemColor(lstListWindow_t *plistwin, _FRQ **ppfont, s32 disprow, u32 basecol) {
  cmpCursorInfo_t_o *CursorInfo;
  _FRQ_o **m_Items;
  u64 v11;
  signed s64 v12;
  _FRQ_o *v16;
  s32 v17;
  s32 col2;

  CursorInfo = plistwin->CursorInfo;
  col2 = 2;
  if (disprow >= 1)
  {
    m_Items = ppfont->m_Items;
    v11 = 0;
    v12 = disprow;
    do
    {
      if (!m_Items[v11])
        break;
      cmpGetCursorBlurFontCol(CursorInfo, v11, v11, basecol, 256, &col2, 0);
      v16 = m_Items[v11];
      v17 = col2;
      frSetFontColor(v16, v17);
      ++v11;
    }
    while (v11 < v12);
  }
}

// 0x11a6510
void CalcMoveReadMainHelp(fclEncyc_readmainwork_tag *pwork) {
  s32 summon_alpha;
  s16 v3;
  struct sdfIVector2_t_o *summon_pos;
  s32 v5;
  struct System_Int32_array *v6;
  struct System_Int32_array *v7;
  s32 viewhelp_alpha;
  struct System_Int32_array *v9;
  struct System_Int32_array *v11;
  s16 v14;
  struct sdfIVector2_t_o *viewhelp_pos;
  s32 v16;
  struct System_Int32_array *v17;
  struct System_Int32_array *pm;
  struct System_Int32_array *v20;
  struct System_Int32_array *v24;

  summon_alpha = pwork->summon_alpha;
  if ((pwork->flags & 0x10) != 0)
  {
    if (summon_alpha + 16 > 128)
    {
      pwork->summon_alpha = 128;
      viewhelp_alpha = pwork->viewhelp_alpha;
      if ((pwork->flags & 8) == 0)
      {
LABEL_18:
        v14 = viewhelp_alpha - 16;
        if (viewhelp_alpha - 16 < 0)
        {
          pm = pwork->viewhelp_pos->pm;
          pm->m_Items[0] = 0;
          v20 = pwork->viewhelp_pos->pm;
          v20->m_Items[1] = 3304;
          v14 = 0;
          pwork->viewhelp_inc = 32;
        }
        else
        {
          viewhelp_pos = pwork->viewhelp_pos;
          v16 = pwork->viewhelp_inc + 4;
          pwork->viewhelp_inc = v16;
          v17 = viewhelp_pos->pm;
          v17->m_Items[1] += v16;
        }
        goto LABEL_34;
      }
    }
    else
    {
      v7 = pwork->summon_pos->pm;
      v7->m_Items[1] -= pwork->summon_inc;
      pwork->summon_inc -= 4;
      pwork->summon_alpha = summon_alpha + 16;
      viewhelp_alpha = pwork->viewhelp_alpha;
      if ((pwork->flags & 8) == 0)
        goto LABEL_18;
    }
  }
  else
  {
    v3 = summon_alpha - 16;
    if (summon_alpha - 16 < 0)
    {
      v9 = pwork->summon_pos->pm;
      v9->m_Items[0] = 4976;
      v11 = pwork->summon_pos->pm;
      v11->m_Items[1] = 3360;
      pwork->summon_inc = 32;
      pwork->summon_alpha = 0;
      viewhelp_alpha = pwork->viewhelp_alpha;
      if ((pwork->flags & 8) == 0)
        goto LABEL_18;
    }
    else
    {
      summon_pos = pwork->summon_pos;
      v5 = pwork->summon_inc + 4;
      pwork->summon_inc = v5;
      v6 = summon_pos->pm;
      v6->m_Items[1] += v5;
      pwork->summon_alpha = v3;
      viewhelp_alpha = pwork->viewhelp_alpha;
      if ((pwork->flags & 8) == 0)
        goto LABEL_18;
    }
  }
  v14 = viewhelp_alpha + 16;
  if (viewhelp_alpha + 16 > 128)
  {
    v14 = 128;
  }
  else
  {
    v24 = pwork->viewhelp_pos->pm;
    v24->m_Items[1] -= pwork->viewhelp_inc;
    pwork->viewhelp_inc -= 4;
  }
LABEL_34:
  pwork->viewhelp_alpha = v14;
}

// 0x11a0630
void CalcMoveRegistKeyHelp(fclEncyc_registconfirmwork_tag *pwork) {
  s32 regist_alpha;
  s16 v3;
  struct System_Int32_array *pm;
  struct sdfIVector2_t_o *regist_pos;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v9;
  struct System_Int32_array *v11;

  regist_alpha = pwork->regist_alpha;
  if (pwork->dispregist)
  {
    v3 = regist_alpha + 16;
    if (regist_alpha + 16 > 128)
    {
      v3 = 128;
    }
    else
    {
      pm = pwork->regist_pos->pm;
      pm->m_Items[1] -= pwork->regist_inc;
      pwork->regist_inc -= 4;
    }
  }
  else
  {
    v3 = regist_alpha - 16;
    if (regist_alpha - 16 < 0)
    {
      v9 = pwork->regist_pos->pm;
      v9->m_Items[0] = 4976;
      v11 = pwork->regist_pos->pm;
      v11->m_Items[1] = 3360;
      v3 = 0;
      pwork->regist_inc = 32;
    }
    else
    {
      regist_pos = pwork->regist_pos;
      v6 = pwork->regist_inc + 4;
      pwork->regist_inc = v6;
      v7 = regist_pos->pm;
      v7->m_Items[1] += v6;
    }
  }
  pwork->regist_alpha = v3;
}

// 0x11ac4a0
void CalcMoveViewModeRibbon(fclEncyc_readmainwork_tag *pwork) {
  s32 ribbon_alpha;
  struct System_Int32_array *v3;
  struct System_Int32_array *v4;
  u32 max_length;
  struct System_Int32_array *v7;
  struct System_Int32_array *v10;
  struct System_Int32_array *ribbon_accel;
  struct System_Int32_array *pm;
  struct System_Int32_array *v16;

  ribbon_alpha = pwork->ribbon_alpha;
  if ((pwork->flags & 0x20) != 0)
  {
    LOWORD(v3) = ribbon_alpha - 16;
    if (ribbon_alpha - 16 < 0)
    {
      LOWORD(v3) = 0;
    }
    else
    {
      ribbon_accel = pwork->ribbon_accel;
      ribbon_accel->m_Items[0] += 4;
      pm = pwork->ribbon_pos->pm;
      v16 = pwork->ribbon_accel;
      pm->m_Items[1] -= v16->m_Items[0];
    }
  }
  else
  {
    LODWORD(v3) = ribbon_alpha + 16;
    v4 = pwork->ribbon_pos->pm;
    max_length = v4->max_length;
    if (v3 >= 129)
    {
      v4->m_Items[1] = 88;
      v3 = pwork->ribbon_accel;
      v3->m_Items[0] = 0;
      LOWORD(v3) = 128;
    }
    else
    {
      v7 = pwork->ribbon_accel;
      v4->m_Items[1] += v7->m_Items[0];
      v10 = pwork->ribbon_accel;
      v10->m_Items[0] -= 4;
    }
  }
  pwork->ribbon_alpha = v3;
}

// 0x11ab350
void CalcPhaseReadExplain(fclEncyc_instance_tag *pinst) {
  fclEncyc_readmainwork_tag_o *pwork;
  fclEncyc_readmainwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s16 v9;
  s32 v10;
  s32 v11;
  u32 v14;
  u32 v16;
  fclEncyc_instance_tag_o *v20;
  s32 v21;
  struct System_Int32_array *pm;
  struct System_Int32_array *v33;
  u64 v38[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v38);
      if ((v38[0] & 1) != 0)
        v6 = v38[2];
      else
        v6 = v38 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  fclRbnCalc(pwork->pribbon);
  v9 = pwork->status_alpha - 128;
  if (v9 < 0)
    v9 = 0;
  pwork->status_alpha = v9;
  v10 = pwork->back_alpha + 64;
  if (v10 << 16 > 0x800000)
    LOWORD(v10) = 128;
  pwork->back_alpha = v10;
  v11 = pwork->explain_alpha + 64;
  if (v11 << 16 > 0x800000)
    LOWORD(v11) = 128;
  pwork->explain_alpha = v11;
  CalcMoveReadMainHelp(pwork);
  v14 = cmpChkCommonInput(0x30032u);
  v16 = cmpChkCommonInputPress(0x30032u);
  if (cmpChkStatusModelLoadStat() != 1)
  {
    if (v14 > 0x10)
    {
      switch (v14)
      {
        case 0x20u:
          ReleaseFontExplain(pinst, 0);
          v20 = pinst;
          v21 = 1;
LABEL_57:
          CirculateDevilObject(v20, v21);
          CreateFontExplain(pinst);
          {
LABEL_58:
          }
LABEL_74:
          cmpPlaySE(v14);
          return;
        case 0x10000u:
          ResetReadMainRibbon(pwork);
          ReleaseFontExplain(pinst, 0);
          InitCameraForViewMode(pinst);
          SetBoundControl(pinst);
          pm = pwork->vir_pos->pm;
          pm->m_Items[0] = 0;
          v33 = pwork->vir_pos->pm;
          v33->m_Items[1] = 0;
          fclRbnSwitchActive(pwork->pribbon, 2);
          pinst->stat |= 8u;
          dds3KernelDebugSign = 0;
          pwork->back_y = 3072;
          pwork->flags |= 8u;
          pinst->stat |= 0xC0u;
          pwork->flags &= ~0x10u;
          draw_status_off(1);
          pinst->RepeatSw = 0;
          StatusTitleOff();
          pinst->next_phase = 7;
          SetButtonGuide(17, 1);
            goto LABEL_74;
          goto LABEL_58;
        case 0x20000u:
          fclRbnSwitchActive(pwork->pribbon, 1);
          ReleaseFontExplain(pinst, 0);
          pwork->flags |= 0x10u;
          SetButtonGuide(16, 1);
          draw_status_off(0);
          pinst->next_phase = 4;
            goto LABEL_74;
          goto LABEL_58;
      }
    }
    else
    {
      if (v14 == 2)
      {
        pinst->stat |= 2u;
        pinst->next_phase = 3;
          goto LABEL_58;
        goto LABEL_74;
      }
      if (v14 == 16)
      {
        ReleaseFontExplain(pinst, 0);
        v20 = pinst;
        v21 = 0;
        goto LABEL_57;
      }
    }
    if (!v16)
      pinst->RepeatSw = 0;
  }
}

// 0x11a5c10
void CalcPhaseReadStatus(fclEncyc_instance_tag *pinst) {
  fclEncyc_readmainwork_tag_o *pwork;
  fclEncyc_readmainwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v10;
  s16 v11;
  s16 v12;
  u32 v16;
  u32 v18;
  struct System_Int32_array *pm;
  struct System_Int32_array *v27;
  s32 v31;
  u16 v33;
  s32 v35;
  u16 flags;
  s32 v42;
  u16 v44;
  u64 v46[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v46);
      if ((v46[0] & 1) != 0)
        v6 = v46[2];
      else
        v6 = v46 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (pwork->ribbon_alpha <= 127)
  {
    FadeInRibbon(pwork);
  }
  else if (!CheckStatusUI())
  {
    return;
  }
  if ((pwork->flags & 0x40) == 0)
  {
    StatusTitleOff();
    SetButtonGuide(16, 1);
    pwork->flags |= 0x40u;
  }
  fclRbnCalc(pwork->pribbon);
  v10 = pwork->status_alpha + 128;
  if (v10 << 16 > 0x800000)
    LOWORD(v10) = 128;
  pwork->status_alpha = v10;
  v11 = pwork->back_alpha - 64;
  if (v11 < 0)
    v11 = 0;
  pwork->back_alpha = v11;
  v12 = pwork->explain_alpha - 64;
  if (v12 < 0)
    v12 = 0;
  pwork->explain_alpha = v12;
  CalcMoveReadMainHelp(pwork);
  MoveScreenOffset(pinst);
  v16 = cmpChkCommonInput(0x30033u);
  v18 = cmpChkCommonInputPress(0x30032u);
  if (cmpChkStatusModelLoadStat() != 1)
  {
    if (v16 > 0x10)
    {
      switch (v16)
      {
        case 0x20u:
          CirculateDevilObject(pinst, 1);
            goto LABEL_116;
          break;
        case 0x10000u:
          ResetReadMainRibbon(pwork);
          fclRbnSwitchActive(pwork->pribbon, 0);
          CreateFontExplain(pinst);
          v42 = CMP_YM(430);
          v44 = pwork->flags & 0xFFEF;
          pwork->back_y = v42;
          pwork->flags = v44;
          SetButtonGuide(18, 1);
          draw_status_off(1);
          pinst->RepeatSw = 0;
          pinst->next_phase = 6;
            goto LABEL_116;
          break;
        case 0x20000u:
          ResetReadMainRibbon(pwork);
          InitCameraForViewMode(pinst);
          SetBoundControl(pinst);
          pm = pwork->vir_pos->pm;
          pm->m_Items[0] = 0;
          v27 = pwork->vir_pos->pm;
          v27->m_Items[1] = 0;
          fclRbnSwitchActive(pwork->pribbon, 2);
          pinst->stat |= 8u;
          dds3KernelDebugSign = 0;
          v31 = CMP_YM(384);
          v33 = pwork->flags | 8;
          pwork->back_y = v31;
          pwork->flags = v33;
          pinst->stat |= 0xC0u;
          pwork->flags &= ~0x10u;
          SetButtonGuide(-1, 0);
          draw_status_off(1);
          pinst->RepeatSw = 0;
          StatusTitleOff();
          pinst->next_phase = 7;
          SetButtonGuide(17, 1);
            goto LABEL_116;
          break;
        default:
LABEL_76:
          if (!v18)
            pinst->RepeatSw = 0;
          return;
      }
    }
    else
    {
      switch (v16)
      {
        case 1u:
          v35 = PrepSummon(pwork);
          flags = pwork->flags;
          if (v35)
          {
            flags |= 1u;
            pwork->flags = flags;
          }
          pwork->flags = flags & 0xFFEF;
          SetButtonGuide(-1, 0);
          pinst->next_phase = 5;
          cmpSetActiveStatusUIParts(0, 0, 0);
          pwork->display_money = 0;
            goto LABEL_116;
          break;
        case 2u:
          pwork->flags &= ~0x10u;
          SetButtonGuide(-1, 0);
          pinst->stat |= 2u;
          pinst->next_phase = 3;
          DrawSummonMoneyReset(pinst);
            goto LABEL_116;
          break;
        case 0x10u:
          CirculateDevilObject(pinst, 0);
            goto LABEL_116;
          break;
        default:
          goto LABEL_76;
      }
    }
LABEL_116:
    cmpPlaySE(v16);
  }
}

// 0x11aa4f0
void CalcPhaseReadSummon(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  fclEncyc_instance_tag_o *v8;
  s32 v9;
  s16 v10;
  s16 v11;
  dds3ProcessID_t_o *monitor;
  s32 klass_low;
  s16 v22;
  fclEncyc_instance_tag_o *v25;
  u64 v26[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v26);
      if ((v26[0] & 1) != 0)
        v6 = v26[2];
      else
        v6 = v26 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (SLOWORD(pwork[2].monitor) >= 1)
  {
    if ((BYTE2(pwork[1].klass) & 4) == 0)
    {
      FadeOutRibbon(pwork);
    }
    fclRbnCalc(pwork[8].monitor);
  }
  if ((BYTE2(pwork[1].klass) & 4) == 0 && !LODWORD(pwork[12].klass))
  {
    DrawSummonMoneyStart(v8);
    LODWORD(pwork[12].klass) = 1;
  }
  v9 = SWORD1(pwork[2].monitor) + 128;
  if (v9 << 16 > 0x800000)
    LOWORD(v9) = 128;
  WORD1(pwork[2].monitor) = v9;
  v10 = WORD2(pwork[6].klass) - 64;
  if (v10 < 0)
    v10 = 0;
  WORD2(pwork[6].klass) = v10;
  v11 = HIWORD(pwork[6].klass) - 64;
  if (v11 < 0)
    v11 = 0;
  HIWORD(pwork[6].klass) = v11;
  CalcMoveReadMainHelp(pwork);
  MoveScreenOffset(pinst);
  monitor = pwork[9].monitor;
  if (fclChkMessageDraw(monitor))
  {
    if ((WORD1(pwork[1].klass) & 3) == 1)
    {
      if (fclChkSignal(0))
      {
        DDS3_GBWK->maka -= HIDWORD(pwork[1].klass);
        WORD1(pwork[1].klass) |= 2u;
        klass_low = SLOWORD(pwork[1].klass);
        ExecSummon(klass_low);
        p2sdPlaySE_20173184("COMSE_SE11");
      }
    }
  }
  else
  {
    FadeOutWindow();
    cmpSetActiveStatusUIParts(1, 0, 0);
    v22 = WORD1(pwork[1].klass);
    if ((~v22 & 3) != 0)
    {
      WORD1(pwork[1].klass) = v22 | 0x10;
      SetButtonGuide(16, 1);
      DrawSummonMoney(v25, 0);
      pinst->next_phase = 4;
    }
    else
    {
      pinst->stat |= 2u;
      pinst->next_phase = 3;
    }
    DrawSummonMoneyReset(pinst);
  }
}

// 0x11a2dd0
void CalcPhaseReadTop(fclEncyc_instance_tag *pinst) {
  fclEncyc_readtopwork_tag_o *pwork;
  fclEncyc_readtopwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  lstListWindow_t_o *listwin;
  s32 v12;
  _FRQ_array *ppfont;
  s32 sort;
  s64 v20;
  System_Int16_array *v21;
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  struct System_Int16_array *lw_cur;
  struct cmpCursorPos_t_o *CursorPos;
  struct System_Int16_array *v27;
  s16 Shift;
  s64 v30;
  s64 v31;
  struct System_Int32_array *stack;
  s32 v34;
  u64 v36[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readtopwork_tag, v36);
      if ((v36[0] & 1) != 0)
        v6 = v36[2];
      else
        v6 = v36 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  listwin = pwork->listwin;
  fclRbnCalc(pwork->pribbon);
  else if (AcceptKeyChangeSort(pinst))
  {
    return;
  }
  v12 = AcceptKeyListWindow(listwin, 1);
  if (v12 == 2)
  {
    sort = pinst->sort;
    v20 = 128;
    if (!pinst->sort)
      v20 = 120;
    v21 = *(&pinst->klass + v20);
    CreateFontListRead(pwork, sort, v21);
    ppfont = pwork->ppfont;
      goto LABEL_49;
  }
  else if (v12 == 1)
  {
    CursorInfo = listwin->CursorInfo;
    CursorIndex = cmpGetCursorIndex(CursorInfo);
    lw_cur = pinst->lw_cur;
    CursorPos = listwin->CursorInfo->CursorPos;
    lw_cur->m_Items[2] = CursorPos->Index;
    v27 = pinst->lw_cur;
    Shift = CursorPos->Shift;
    v27->m_Items[3] = Shift;
    v30 = 128;
    if (!pinst->sort)
      v30 = 120;
    v31 = *(&pinst->klass + v30);
    stack = pinst->stack;
    v34 = *(v31 + 2LL * CursorIndex + 32);
    stack->m_Items[0] = v34;
    pinst->StatusBack = 1;
    pinst->stat |= 2u;
    pinst->next_phase = 4;
    ppfont = pwork->ppfont;
      goto LABEL_49;
  }
  else
  {
    if (v12 == -1)
    {
      pinst->stat |= 2u;
      pinst->next_phase = 8;
    }
    ppfont = pwork->ppfont;
      goto LABEL_49;
  }
LABEL_49:
  CalcListElemColor(listwin, ppfont, 9, 0);
}

// 0x11abeb0
void CalcPhaseReadView(fclEncyc_instance_tag *pinst) {
  fclEncyc_readmainwork_tag_o *pwork;
  fclEncyc_readmainwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s16 v9;
  s16 v10;
  s32 v11;
  s16 v12;
  u32 ViewModeKey;
  dds3ModelHandle_t_o *StatusModelHandle;
  s16 v21;
  s32 viewhelp_ctr;
  u32 v24;
  fclRibbon_t_o *pribbon;
  s32 v33;
  fclRibbon_t_o *v34;
  u64 v39[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v39);
      if ((v39[0] & 1) != 0)
        v6 = v39[2];
      else
        v6 = v39 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  fclRbnCalc(pwork->pribbon);
  v9 = pwork->status_alpha - 128;
  if (v9 < 0)
    v10 = 0;
  else
    v10 = pwork->status_alpha - 128;
  pwork->status_alpha = v10;
  if (v9 < 0)
    pinst->stat |= 0x10u;
  v11 = pwork->back_alpha + 64;
  if (v11 << 16 > 0x800000)
    LOWORD(v11) = 128;
  pwork->back_alpha = v11;
  v12 = pwork->explain_alpha - 64;
  if (v12 < 0)
    v12 = 0;
  pwork->explain_alpha = v12;
  CalcMoveReadMainHelp(pwork);
  CalcMoveViewModeRibbon(pwork);
  MoveScreenOffset(pinst);
  if ((pinst->stat & 0x10) != 0)
  {
    ViewModeKey = GetViewModeKey(pinst);
    StatusModelHandle = cmpGetStatusModelHandle();
    ControlModel(pinst, StatusModelHandle, ViewModeKey);
    PPSV2_StatusMode = 1;
    PPSV2_StatusDevilId = pwork->unit->id;
    if (ViewModeKey)
    {
      pwork->flags = pwork->flags & 0xFFD7 | 0x20;
      v21 = 20;
    }
    else
    {
      viewhelp_ctr = pwork->viewhelp_ctr;
      if (viewhelp_ctr < 0)
      {
        pwork->flags = pwork->flags & 0xFFD7 | 8;
        goto LABEL_40;
      }
      v21 = viewhelp_ctr - 1;
    }
    pwork->viewhelp_ctr = v21;
  }
LABEL_40:
  v24 = cmpChkCommonInput(0x30002u);
LABEL_47:
  if (cmpChkStatusModelLoadStat() != 1)
  {
    switch (v24)
    {
      case 0x20000u:
        ResetReadMainRibbon(pwork);
        pwork->flags &= ~0x20u;
        *&pinst->screen_ofsx = 0x450000004508C000LL;
        pinst->stat &= 0xFFE7u;
        dds3KernelDebugSign = 1;
        pinst->stat = pinst->stat & 0xFFFFFF3F | 0x40;
        reset_viewmode(pinst);
        pribbon = pwork->pribbon;
        pwork->flags &= ~8u;
        fclRbnSwitchActive(pribbon, 0);
        CreateFontExplain(pinst);
        pwork->back_y = 3440;
        pwork->flags &= ~0x10u;
        draw_status_off(1);
        pinst->RepeatSw = 0;
        pinst->next_phase = 6;
        v33 = 18;
        break;
      case 0x10000u:
        ResetReadMainRibbon(pwork);
        v34 = pwork->pribbon;
        pwork->flags &= ~0x20u;
        fclRbnSwitchActive(v34, 1);
        *&pinst->screen_ofsx = 0x450000004508C000LL;
        pinst->stat &= 0xFFE7u;
        dds3KernelDebugSign = 1;
        pinst->stat = pinst->stat & 0xFFFFFF3F | 0x40;
        reset_viewmode(pinst);
        pwork->flags = pwork->flags & 0xFFE7 | 0x10;
        draw_status_off(0);
        pinst->next_phase = 4;
        v33 = 16;
        break;
      case 2u:
        pinst->stat |= 0x100u;
        dds3KernelDebugSign = 1;
        pinst->stat = pinst->stat & 0xFFFFFF3D | 0x42;
        pinst->next_phase = 3;
LABEL_84:
        pinst->XAngle = 0;
LABEL_85:
        cmpPlaySE(v24);
        return;
      default:
        goto LABEL_85;
    }
    SetButtonGuide(v33, 1);
    goto LABEL_84;
  }
}

// 0x11a15a0
void CalcPhaseRegistAll(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  lstListWindow_t_o *monitor;
  _FRQ_array *v10;
  u64 *p_monitor;
  dds3ProcessID_t_o *v13;
  s16 v19;
  u64 v23[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registtopwork_tag, v23);
      if ((v23[0] & 1) != 0)
        v7 = v23[2];
      else
        v7 = v23 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  monitor = pwork[1].monitor;
  v10 = pwork[3].klass;
  CalcListElemColor(monitor, v10, 12, 2u);
  p_monitor = &pwork[3].monitor;
  v13 = pwork[3].monitor;
  if (!fclChkMessageDraw(v13))
  {
    if (LOBYTE(pwork[1].klass))
    {
      *p_monitor = 0;
      {
LABEL_28:
        if (fclChkSignal(0))
        {
          SetButtonGuide(-1, 0);
          RegistAll(pinst);
          pinst->stat |= 2u;
          v19 = 8;
        }
        else
        {
          LOBYTE(pwork[1].klass) = 0;
          fclClearSignal(0);
          *p_monitor = 0;
          *p_monitor = fclScriptStart(CMB_GBWK->pScriptData, 15, &pwork[3].monitor);
          SetButtonGuide(-1, 0);
          v19 = 0;
        }
        pinst->next_phase = v19;
        return;
      }
    }
    else
    {
      FadeOutWindow();
      SetButtonGuide(12, 1);
      LOBYTE(pwork[1].klass) = 1;
      *p_monitor = 0;
        goto LABEL_28;
    }
    goto LABEL_28;
  }
}

// 0x11a01f0
void CalcPhaseRegistConfirm(fclEncyc_instance_tag *pinst) {
  fclEncyc_registconfirmwork_tag_o *pwork;
  fclEncyc_registconfirmwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 status_alpha;
  s32 inc_now;
  s32 v12;
  s32 v13;
  s32 inc_rec;
  s32 v15;
  dds3ProcessID_t_o *scr_proc;
  struct datUnitWork_t_array *unitwork;
  s64 unitindex;
  datUnitWork_t_o *v27;
  struct System_Int16_array *lw_cur;
  s32 num_nakama;
  u32 max_length;
  s16 v31;
  s32 v34;
  s32 v35;
  s16 v36;
  u64 v37[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registconfirmwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registconfirmwork_tag, v37);
      if ((v37[0] & 1) != 0)
        v6 = v37[2];
      else
        v6 = v37 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  else
  {
    status_alpha = pwork->status_alpha;
    if (pwork->flag)
      goto LABEL_13;
  }
  v12 = status_alpha + 16;
  pwork->status_alpha = v12;
  if (v12 < 161)
  {
    v13 = pwork->inc_now + 4;
    inc_rec = pwork->inc_rec;
    v15 = inc_rec + pwork->x_rec;
    pwork->x_now -= v13;
    pwork->inc_now = v13;
    pwork->x_rec = v15;
    pwork->inc_rec = inc_rec + 4;
  }
  else
  {
    pwork->status_alpha = 160;
  }
LABEL_20:
  fclRbnCalc(pwork->pribbon);
  CalcMoveRegistKeyHelp(pwork);
  if (pwork->period)
  {
    scr_proc = pwork->scr_proc;
    if (!fclChkMessageDraw(scr_proc))
    {
      FadeOutWindow();
      if (fclChkSignal(0))
      {
        unitwork = DDS3_GBWK->unitwork;
        unitindex = pwork->unitindex;
        v27 = unitwork->m_Items[unitindex];
        fclEncycRegist(v27, 1, 0);
        lw_cur = pinst->lw_cur;
        num_nakama = pinst->num_nakama;
        max_length = lw_cur->max_length;
        if (num_nakama >= 2)
        {
          v34 = lw_cur->m_Items[0];
          if (v34 + 12 >= num_nakama - 1)
          {
            v35 = lw_cur->m_Items[1];
            v36 = v34 - 1;
            if (v34 < 1)
            {
              v36 = lw_cur->m_Items[0];
              if (v35 + v34 >= num_nakama - 1)
                LOWORD(v35) = num_nakama - 2;
            }
            lw_cur->m_Items[0] = v36;
            lw_cur->m_Items[1] = v35;
          }
        }
        v31 = 8 * (pinst->num_nakama < 2);
      }
      else
      {
        v31 = 0;
      }
      pinst->next_phase = v31;
      pinst->stat |= 2u;
    }
  }
  else
  {
    AcceptKeyRegistConfirm(pinst);
  }
}

// 0x119d0b0
void CalcPhaseRegistTop(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  lstListWindow_t_o *monitor;
  s32 v12;
  s16 v15;
  dds3ProcessID_t_o *v20;
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  struct cmpCursorPos_t_o *CursorPos;
  struct System_Int16_array *lw_cur;
  struct System_Int16_array *v26;
  s16 Shift;
  struct System_Byte_array *pnakamaindex;
  struct System_Int32_array *stack;
  s32 v32;
  u32 stat;
  _FRQ_array *v35;
  u64 v36[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registtopwork_tag, v36);
      if ((v36[0] & 1) != 0)
        v7 = v36[2];
      else
        v7 = v36 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  monitor = pwork[1].monitor;
  if (LOBYTE(pwork[1].klass))
  {
LABEL_22:
    v12 = AcceptKeyListWindow(monitor, 0);
    switch (v12)
    {
      case 3:
        SetButtonGuide(-1, 0);
        dds3KillProcess(&pwork[3].monitor, 0);
        fclClearSignal(0);
        pwork[3].monitor = 0;
        v20 = fclScriptStart(CMB_GBWK->pScriptData, 19, &pwork[3].monitor);
        v15 = 2;
        pwork[3].monitor = v20;
        LOBYTE(pwork[1].klass) = 0;
        break;
      case 1:
        CursorInfo = monitor->CursorInfo;
        CursorIndex = cmpGetCursorIndex(CursorInfo);
        CursorPos = monitor->CursorInfo->CursorPos;
        lw_cur = pinst->lw_cur;
        lw_cur->m_Items[0] = CursorPos->Index;
        v26 = pinst->lw_cur;
        Shift = CursorPos->Shift;
        v26->m_Items[1] = Shift;
        pnakamaindex = pinst->pnakamaindex;
        stack = pinst->stack;
        v32 = pnakamaindex->m_Items[CursorIndex];
        stack->m_Items[0] = v32;
        stat = pinst->stat;
        v15 = 1;
        pinst->StatusBack = 1;
        pinst->stat = stat | 2;
        break;
      case -1:
        pinst->stat |= 2u;
        v15 = 8;
        break;
      default:
        goto LABEL_58;
    }
    pinst->next_phase = v15;
LABEL_58:
    v35 = pwork[3].klass;
    CalcListElemColor(monitor, v35, 12, 0);
    return;
  }
  if (fclChkSignal(0))
  {
    LOBYTE(pwork[1].klass) = 1;
    FadeOutWindow();
    SetButtonGuide(11, 1);
    goto LABEL_22;
  }
}

// 0x119a490
void *CalcProc(dds3ProcessID_t *proc_id) {
  u64 *v2;
  u64 *v3;
  u64 *v5;
  u64 *v7;
  u64 *v9;
  u64 *v11;
  u64 *v12;
  u64 *v14;
  u64 *v16;
  u64 *v18;
  u64 *v20;
  u64 *v22;
  u64 *v24;
  u64 *v26;
  fclEncyc_instance_tag_o *g_pinst;
  s8 Stat;
  u32 v35;
  u16 req_model;
  s8 v37;
  u32 v38;
  s32 v40;
  dds3ModelHandle_t_o *v41;
  u32 v43;

  v2 = NewSpecific(fclEncyc_func_initDelegate, 9u);
  v3 = Allocate(fclEncyc_func_initDelegate);
  _ctor(v3, 0, Method_fclEncyc_InitPhaseRegistTop__, 0);
  v2[4] = v3;
  v5 = Allocate(fclEncyc_func_initDelegate);
  _ctor(v5, 0, Method_fclEncyc_InitPhaseRegistConfirm__, 0);
  v2[5] = v5;
  v7 = Allocate(fclEncyc_func_initDelegate);
  _ctor(v7, 0, Method_fclEncyc_InitPhaseReadTop__, 0);
  v2[7] = v7;
  v9 = Allocate(fclEncyc_func_initDelegate);
  _ctor(v9, 0, Method_fclEncyc_InitPhaseReadStatus__, 0);
  v2[8] = v9;
  v11 = NewSpecific(fclEncyc_func_calcDelegate, 9u);
  v12 = Allocate(fclEncyc_func_calcDelegate);
  _ctor(v12, 0, Method_fclEncyc_CalcPhaseRegistTop__, 0);
  v11[4] = v12;
  v14 = Allocate(fclEncyc_func_calcDelegate);
  _ctor(v14, 0, Method_fclEncyc_CalcPhaseRegistConfirm__, 0);
  v11[5] = v14;
  v16 = Allocate(fclEncyc_func_calcDelegate);
  _ctor(v16, 0, Method_fclEncyc_CalcPhaseRegistAll__, 0);
  v11[6] = v16;
  v18 = Allocate(fclEncyc_func_calcDelegate);
  _ctor(v18, 0, Method_fclEncyc_CalcPhaseReadTop__, 0);
  v11[7] = v18;
  v20 = Allocate(fclEncyc_func_calcDelegate);
  _ctor(v20, 0, Method_fclEncyc_CalcPhaseReadStatus__, 0);
  v11[8] = v20;
  v22 = Allocate(fclEncyc_func_calcDelegate);
  _ctor(v22, 0, Method_fclEncyc_CalcPhaseReadSummon__, 0);
  v11[9] = v22;
  v24 = Allocate(fclEncyc_func_calcDelegate);
  _ctor(v24, 0, Method_fclEncyc_CalcPhaseReadExplain__, 0);
  v11[10] = v24;
  v26 = Allocate(fclEncyc_func_calcDelegate);
  _ctor(v26, 0, Method_fclEncyc_CalcPhaseReadView__, 0);
  v11[11] = v26;
  if (g_pinst)
  {
    if ((g_pinst->stat & 1) == 0)
    {
      if (v2[g_pinst->phase + 4])
      {
        Invoke(v2[g_pinst->phase + 4], g_pinst, 0);
      }
      g_pinst->stat |= 1u;
    }
    Stat = cmpChkStatusModelLoadStat();
    v35 = g_pinst->stat;
    if (Stat != 1 && (v35 & 4) != 0 && !g_pinst->RepeatSw)
    {
      req_model = g_pinst->req_model;
      v37 = cmpModelSetup(req_model, 0);
      v38 = g_pinst->stat;
      if (v37 == 1)
      {
        v38 &= ~0x400u;
        g_pinst->stat = v38;
      }
      v35 = v38 & 0xFFFFFFFB;
      g_pinst->stat = v35;
    }
    if ((v35 & 0x40) != 0)
    {
      if (cmpGetStatusModelHandle())
      {
        v40 = g_pinst->req_model;
        cmpGetStatusModelHandle();
        v43 = g_pinst->stat;
        ChangeModelMotion(v40, v41, v43);
        g_pinst->stat &= ~0x40u;
      }
    }
    if (v11[g_pinst->phase + 4])
    {
      Invoke(v11[g_pinst->phase + 4], g_pinst, 0);
    }
    g_pinst->stat |= 0x20u;
  }
  return 0;
}

// 0x11a6a00
bool CanControl(fclEncyc_instance_tag *pinst) {
  return cmpChkStatusModelLoadStat() != 1;
}

// 0x11a58e0
void ChangeDevilObjectReadMain(s32 recindex, fclEncyc_instance_tag *pinst) {
  fclEncyc_instance_tag_o *v3;
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct fclencyceelem_t_array *pelem;
  fclencyceelem_t_o *v13;
  s32 id;
  u64 v16[3];

  v3 = pinst;
  pwork = v3->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v16);
      if ((v16[0] & 1) != 0)
        v8 = v16[2];
      else
        v8 = v16 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  LOWORD(pwork[1].klass) = recindex;
  pelem = DDS3_GBWK->encyc_record->pelem;
  v13 = pelem->m_Items[recindex];
  id = v13->id;
  RequestModelLoad(v3, id);
  SetRecordToUnitCore(pwork[10].klass, v13);
}

// 0x119f770
void ChangeDevilObjectRegistConfirm(s32 unitindex, fclEncyc_instance_tag *pinst) {
  fclEncyc_instance_tag_o *v3;
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v13;
  s32 id;
  struct datUnitWork_t_array *v16;
  u64 v18[3];

  v3 = pinst;
  pwork = v3->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registconfirmwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registconfirmwork_tag, v18);
      if ((v18[0] & 1) != 0)
        v8 = v18[2];
      else
        v8 = v18 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  WORD1(pwork[1].klass) = unitindex;
  unitwork = DDS3_GBWK->unitwork;
  v13 = unitwork->m_Items[unitindex];
  id = v13->id;
  RequestModelLoad(v3, id);
  datUnitWork_t__Copy(pwork[4].klass, v13);
  v16 = DDS3_GBWK->unitwork;
  SetRecordToUnit(pwork[3].monitor, v16->m_Items[unitindex]->id);
}

// 0x119ad10
void ChangeModelMotion(s32 id, dds3ModelHandle_t *model, u32 stat) {
  s16 v4;
  u8 MotNo;
  f32 MotSpd;
  f32 speed;
  struct motiontable_tag_array *v10;
  s32 v12;
  struct motiontable_tag_array *tbl;
  s32 no;

  v4 = stat;
  if ((v4 & 0x80) != 0)
  {
    no = tbl->m_Items[id]->no;
    speed = tbl->m_Items[id]->speed;
    if ((v4 & 0x400) == 0)
      goto LABEL_38;
    if (no != cmpModelTblGetMotNo(id))
    {
LABEL_38:
      v12 = no;
      goto LABEL_31;
    }
  }
  else
  {
    MotNo = cmpModelTblGetMotNo(id);
    MotSpd = cmpModelTblGetMotSpd(id);
    speed = MotSpd;
    v10 = tbl;
    if (v10->m_Items[id]->no != MotNo)
    {
      v12 = MotNo;
LABEL_31:
      mdlSmoothLoopMotionForUnity(v12, model, stat);
    }
  }
  mdlSetMotionSpeed(speed);
}

// 0x11a7c80
void CirculateDevilObject(fclEncyc_instance_tag *pinst, s32 dsn) {
  cmpCursorInfo_t_o *v5;
  struct System_Int16_array *lw_cur;
  s64 v8;
  struct cmpCursorPos_t_o *CursorPos;
  struct System_Int16_array *v11;
  s64 v12;
  u8 v14;
  s32 num_nakama;
  s32 NumForDLC;
  s32 CursorIndex;
  s8 v20;
  s32 v21;
  System_Object_array *v23;
  s64 *v25;
  s64 *v26;
  s64 *v29;
  s64 *v30;
  s64 *v33;
  s64 *v34;
  s64 *v37;
  s64 *v38;
  System_String_o *v40;
  System_Object_array *v42;
  struct System_Int16_array *v45;
  struct System_Int16_array *v47;
  struct System_Byte_array *pnakamaindex;
  s32 v50;
  s32 v52;
  s64 v53;
  s64 v54;
  s32 v56;
  System_Object_array *v58;
  s32 v66;
  s32 RepeatSw;
  s32 v68;
  s32 v69;
  s8 v70[4];

  v5 = Allocate(cmpCursorInfo_t);
  cmpCursorInfo_t___ctor(v5);
  lw_cur = pinst->lw_cur;
  v8 = 2 * (pinst->phase != 1);
  CursorPos = v5->CursorPos;
  CursorPos->Index = lw_cur->m_Items[v8];
  v11 = pinst->lw_cur;
  v12 = v8 | 1;
  v14 = v11->m_Items[v12];
  CursorPos->Shift = v14;
  CursorPos->DrawShift = v14;
  if (pinst->phase == 1)
  {
    CursorPos->ListNums = pinst->num_nakama;
    num_nakama = pinst->num_nakama;
    if (num_nakama >= 12)
      LOBYTE(num_nakama) = 12;
  }
  else
  {
    NumForDLC = fclEncycGetNumForDLC();
    if (NumForDLC >= 9)
      LOBYTE(num_nakama) = 9;
    else
      LOBYTE(num_nakama) = NumForDLC;
    CursorPos->ListNums = NumForDLC;
  }
  CursorPos->ShiftMax = num_nakama;
  CursorIndex = cmpGetCursorIndex(v5);
  if (dsn)
    v20 = 1;
  else
    v20 = -1;
  cmpMoveCursorEx(v5, v20, 1);
  v21 = cmpGetCursorIndex(v5);
  v23 = NewSpecific(object, 7u);
  v66 = dsn;
  v70[0] = gLoadStat;
  v25 = sub_8D3950(sbyte, v70);
  v26 = v25;
  v23->m_Items[0] = v26;
  v23->m_Items[1] = ",[ ";
  v69 = v21;
  v29 = sub_8D3950(s32, &v69);
  v30 = v29;
  v23->m_Items[2] = v30;
  v23->m_Items[3] = " / ";
  v68 = CursorIndex;
  v33 = sub_8D3950(s32, &v68);
  v34 = v33;
  v23->m_Items[4] = v34;
  v23->m_Items[5] = "] ";
  RepeatSw = pinst->RepeatSw;
  v37 = sub_8D3950(s32, &RepeatSw);
  v38 = v37;
  v23->m_Items[6] = v38;
  v40 = Concat_5270224(v23);
  v42 = Empty_string_();
  Log(v40, v42, 0);
  if (v21 != CursorIndex && gLoadStat != 1)
  {
    cmpStatusMdlDestroy();
  }
  v45 = pinst->lw_cur;
  v45->m_Items[v8] = CursorPos->Index;
  v47 = pinst->lw_cur;
  v47->m_Items[v12] = CursorPos->Shift;
  if (pinst->phase == 1)
  {
    pnakamaindex = pinst->pnakamaindex;
    v50 = v66;
    v52 = pnakamaindex->m_Items[v21];
    ChangeDevilObjectRegistConfirm(v52, pinst);
  }
  else
  {
    v50 = v66;
    v53 = 128;
    if (!pinst->sort)
      v53 = 120;
    if (v21 != CursorIndex)
    {
      v54 = *(&pinst->klass + v53);
      v56 = *(v54 + 2LL * v21 + 32);
      ChangeDevilObjectReadMain(v56, pinst);
    }
  }
  cmpSetModelReloadFlag();
  pinst->RepeatSw = v50 + 1;
  v58 = Empty_string_();
  Log("Repeat = UD", v58, 0);
}

// 0x11afb30
void ClearMessage(void *obj) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v4;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_Component_o *v6;
  UnityEngine_GUILayer_o *v7;
  u64 *v8;
  System_String_o *v9;
  UnityEngine_Component_o *v10;
  UnityEngine_GUILayer_o *v11;
  u64 *v12;
  System_String_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GUILayer_o *v15;
  u64 *v16;
  System_String_o *v17;
  UnityEngine_Component_o *v18;
  UnityEngine_GUILayer_o *v19;
  u64 *v20;
  System_String_o *v21;
  UnityEngine_Component_o *v22;
  UnityEngine_GUILayer_o *v23;
  u64 *v24;
  System_String_o *v25;
  UnityEngine_Component_o *v26;
  UnityEngine_GUILayer_o *v27;
  u64 *v28;
  System_String_o *v29;
  UnityEngine_Component_o *v30;
  UnityEngine_GUILayer_o *v31;
  u64 *v32;
  System_String_o *v33;
  UnityEngine_Component_o *v34;
  UnityEngine_GUILayer_o *v35;
  u64 *v36;
  System_String_o *v37;
  UnityEngine_Component_o *v38;
  UnityEngine_GUILayer_o *v39;
  u64 *v40;
  System_String_o *v41;
  UnityEngine_Component_o *v42;
  UnityEngine_GUILayer_o *v43;
  u64 *v44;
  System_String_o *v45;
  UnityEngine_Component_o *v46;
  UnityEngine_GUILayer_o *v47;
  s32 v48;

  transform = get_transform(obj, 0);
  v4 = Find(transform, "Text_raceTM", 0);
  Component_GUILayer = GetComponent_GUILayer_(v4);
  set_text(Component_GUILayer, "");
  v6 = Find(transform, "Text_nameTM", 0);
  v7 = GetComponent_GUILayer_(v6);
  set_text(v7, "");
  v48 = 1;
  v8 = sub_8D3950(s32, &v48);
  v9 = Format("Text_name{0:D2}TM", v8, 0);
  v10 = Find(transform, v9, 0);
  v11 = GetComponent_GUILayer_(v10);
  set_text(v11, "");
  v48 = 2;
  v12 = sub_8D3950(s32, &v48);
  v13 = Format("Text_name{0:D2}TM", v12, 0);
  v14 = Find(transform, v13, 0);
  v15 = GetComponent_GUILayer_(v14);
  set_text(v15, "");
  v48 = 3;
  v16 = sub_8D3950(s32, &v48);
  v17 = Format("Text_name{0:D2}TM", v16, 0);
  v18 = Find(transform, v17, 0);
  v19 = GetComponent_GUILayer_(v18);
  set_text(v19, "");
  v48 = 4;
  v20 = sub_8D3950(s32, &v48);
  v21 = Format("Text_name{0:D2}TM", v20, 0);
  v22 = Find(transform, v21, 0);
  v23 = GetComponent_GUILayer_(v22);
  set_text(v23, "");
  v48 = 5;
  v24 = sub_8D3950(s32, &v48);
  v25 = Format("Text_name{0:D2}TM", v24, 0);
  v26 = Find(transform, v25, 0);
  v27 = GetComponent_GUILayer_(v26);
  set_text(v27, "");
  v48 = 6;
  v28 = sub_8D3950(s32, &v48);
  v29 = Format("Text_name{0:D2}TM", v28, 0);
  v30 = Find(transform, v29, 0);
  v31 = GetComponent_GUILayer_(v30);
  set_text(v31, "");
  v48 = 7;
  v32 = sub_8D3950(s32, &v48);
  v33 = Format("Text_name{0:D2}TM", v32, 0);
  v34 = Find(transform, v33, 0);
  v35 = GetComponent_GUILayer_(v34);
  set_text(v35, "");
  v48 = 8;
  v36 = sub_8D3950(s32, &v48);
  v37 = Format("Text_name{0:D2}TM", v36, 0);
  v38 = Find(transform, v37, 0);
  v39 = GetComponent_GUILayer_(v38);
  set_text(v39, "");
  v48 = 9;
  v40 = sub_8D3950(s32, &v48);
  v41 = Format("Text_name{0:D2}TM", v40, 0);
  v42 = Find(transform, v41, 0);
  v43 = GetComponent_GUILayer_(v42);
  set_text(v43, "");
  v48 = 10;
  v44 = sub_8D3950(s32, &v48);
  v45 = Format("Text_name{0:D2}TM", v44, 0);
  v46 = Find(transform, v45, 0);
  v47 = GetComponent_GUILayer_(v46);
  set_text(v47, "");
}

// 0x11ae620
s32 CompareUnitToRecord(datUnitWork_t *punit, fclencyceelem_t *pelem) {
  System_Array_o *v5;
  u64 v6;
  s32 v7;
  struct System_SByte_array *param;
  s64 v10;
  struct System_SByte_array *v12;
  s32 v13;
  struct System_SByte_array *skillparam;
  struct System_SByte_array *v17;
  s32 v18;
  struct System_SByte_array *mitamaparam;
  struct System_SByte_array *v22;
  s32 v23;
  struct System_SByte_array *levelupparam;
  struct System_SByte_array *v27;
  s32 v28;
  u64 skillcnt;
  u64 v32;
  struct System_UInt16_array *skill;
  s32 v35;
  u64 v36;
  struct System_Int32_array *v37;

  v5 = NewSpecific(char, 5u);
  InitializeArray_1543888(v5, Field__PrivateImplementationDetails__0EA39157D53DE452277153A35DF4805D344F11ED);
  if (pelem->flag != (punit->flag & 0x240))
    return 1;
  if (pelem->maxhp != punit->maxhp)
    return 2;
  if (pelem->maxmp != punit->maxmp)
    return 3;
  if (pelem->exp != punit->exp)
    return 4;
  if (pelem->level != punit->level)
    return 5;
  v6 = 0;
  v7 = 9;
  do
  {
    param = pelem->param;
    v10 = *(&v5[2].klass + v6);
    v12 = punit->param;
    v13 = param->m_Items[v10];
    if (v13 != v12->m_Items[v10])
      return 6;
    skillparam = pelem->skillparam;
    v17 = punit->skillparam;
    v18 = skillparam->m_Items[v10];
    if (v18 != v17->m_Items[v10])
      return 7;
    mitamaparam = pelem->mitamaparam;
    v22 = punit->mitamaparam;
    v23 = mitamaparam->m_Items[v10];
    if (v23 != v22->m_Items[v10])
      return 8;
    levelupparam = pelem->levelupparam;
    v27 = punit->levelupparam;
    v28 = levelupparam->m_Items[v10];
    if (v28 != v27->m_Items[v10])
      return v7;
  }
  while (v6++ < 4);
  skillcnt = punit->skillcnt;
  if (skillcnt != pelem->skillcnt)
    return 10;
  if (pelem->skillcnt)
  {
    v32 = 0;
    v7 = 11;
    do
    {
      skill = pelem->skill;
      v35 = skill->m_Items[v32];
      v36 = 0;
      while (1)
      {
        v37 = punit->skill;
        if (v37->m_Items[v36] == v35)
          break;
        if (++v36 >= skillcnt)
          return v7;
      }
      ++v32;
    }
    while (v32 < skillcnt);
  }
  if (pelem->hensinmae != punit->hensinmae)
    return 12;
  if (pelem->hensinmaeexp == punit->hensinmaeexp)
    return 0;
  else
    return 13;
}

// 0x11aced0
void ControlModel(fclEncyc_instance_tag *pinst, dds3ModelHandle_t *model, u32 pad) {
  s16 v4;
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  UnityEngine_GameObject_o *cmpMdlObj;
  struct fclencyceelem_t_array *pelem;
  s32 id;
  bool activeSelf;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  UnityEngine_Transform_o *v31;
  f32 x;
  f32 y;
  f32 z;
  f32 v37;
  dds3ModelHandle_t_o *v38;
  const char *v40;
  const char *v42;
  f32 v45;
  f32 *v46;
  s32 v47;
  f32 v48;
  f32 v49;
  f32 *p_monitor;
  s32 v51;
  f32 v52;
  f32 v53;
  fclEncyc_instance_tag_Fields *p_fields;
  struct UnityEngine_Vector4_o *p_pos_camera_target;
  const char *name;
  s64 v59;
  s32 v60;
  const char *v62;
  s32 v64;
  const char *v65;
  s64 v67;
  s32 v68;
  const char *v71;
  s64 v73;
  s32 v74;
  const char *v76;
  u32 *v77;
  s32 v78;
  s32 v79;
  const char *v80;
  s64 v82;
  s32 v83;
  const char *v85;
  s32 v86;
  UnityEngine_Vector4_o v91;
  UnityEngine_Matrix4x4_o v92;
  UnityEngine_Vector4_o p;
  u64 v94[2];
  UnityEngine_Vector4_o v95;
  UnityEngine_Vector4_o v96;
  UnityEngine_Vector3_o v97;
  UnityEngine_Vector3_o up;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o localScale;
  UnityEngine_Vector3_o v101;
  UnityEngine_Vector3_o v102;
  UnityEngine_Vector3_o v103;
  UnityEngine_Quaternion_o v104;
  UnityEngine_Quaternion_o v105;
  UnityEngine_Quaternion_o v106;
  UnityEngine_Vector3_o v107;
  UnityEngine_Vector3_o v108;
  UnityEngine_Quaternion_o v109;
  UnityEngine_Quaternion_o localRotation;

  v4 = pad;
  *&v96.x = 0;
  *&v96.z = 0;
  *&v95.x = 0;
  *&v95.z = 0;
  v94[0] = 0;
  v94[1] = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&v96.x, 0.03, 0.0, 0.0, 0.0);
  sub_854690(&v95.x, 0.0, 0.03, 0.0, 0.0);
  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, &v92);
      if ((LOBYTE(v92.m00) & 1) != 0)
        v11 = *&v92.m01;
      else
        v11 = &v92.m00 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  get_zero();
  pelem = DDS3_GBWK->encyc_record->pelem;
  id = pelem->m_Items[SLOWORD(pwork[1].klass)]->id;
  if (!op_Equality(cmpMdlObj, 0, 0))
  {
    activeSelf = get_activeSelf(cmpMdlObj);
    if (model)
    {
      if (activeSelf)
      {
        model->modelRoot->modelobj = cmpMdlObj;
        transform = get_transform(cmpMdlObj, 0);
        Child = GetChild(transform, 0);
        gameObject = get_gameObject(Child);
        if ((v4 & 1) == 0)
        {
          v25 = gameObject;
          sub_1A1BDD0(v94, 0.017453, 0.0, 0.0, 1.0);
          sub_1A1CAE0(v94, 0);
          v27 = v26;
          sub_1A1CAE0(v94, 0);
          v28 = sub_851730(&pwork[4], 0);
          sub_1A1BDD0(v94, v28, 0.0, 0.0, 1.0);
          sub_1A1CAE0(v94, 0);
          v29 = sub_851730(&pwork[4], 1);
          sub_1A1BDD0(v94, v29, 0.0, 0.0, 1.0);
          sub_1A1CAE0(v94, 0);
          v31 = get_transform(v25, 0);
          {
          }
          get_identity(0);
          get_localPosition(v31);
          if ((v4 & 2) != 0)
          {
            {
            }
            up = get_up();
            x = up.x;
            y = up.y;
            z = up.z;
            {
            }
            v37 = v27;
          }
          else
          {
            if ((v4 & 4) == 0)
              goto LABEL_56;
            {
            }
            v97 = get_up();
            x = v97.x;
            y = v97.y;
            z = v97.z;
            {
            }
            v37 = -v27;
          }
          v108.x = x;
          v108.y = y;
          v108.z = z;
          v104 = AngleAxis(v37, v108);
          localRotation = get_localRotation(v31);
          v109 = op_Multiply(v104, localRotation, 0);
          set_localRotation(v31, v109);
LABEL_56:
          if ((v4 & 8) != 0)
          {
            v48 = *(&pwork[3].monitor + 1) + 0.034907;
            *(&pwork[3].monitor + 1) = v48;
            if (v48 <= sub_851730(&pwork[4], 1))
              goto LABEL_63;
            v46 = &pwork[4];
            v47 = 1;
          }
          else
          {
            if ((v4 & 0x10) == 0
              || (v45 = *(&pwork[3].monitor + 1) + -0.034907,
                  *(&pwork[3].monitor + 1) = v45,
                  v45 >= sub_851730(&pwork[4], 0)))
            {
LABEL_63:
              if ((v4 & 0x400) != 0)
              {
                v52 = *&pwork[3].monitor + -5.0;
                *&pwork[3].monitor = v52;
                if (v52 < sub_851730(&pwork[4].monitor, 0))
                {
                  p_monitor = &pwork[4].monitor;
                  v51 = 0;
                  goto LABEL_69;
                }
              }
              else if ((v4 & 0x200) != 0)
              {
                v49 = *&pwork[3].monitor + 5.0;
                *&pwork[3].monitor = v49;
                if (v49 > sub_851730(&pwork[4].monitor, 1))
                {
                  p_monitor = &pwork[4].monitor;
                  v51 = 1;
LABEL_69:
                  *&pwork[3].monitor = sub_851730(p_monitor, v51);
                }
              }
              v53 = *(&pwork[3].monitor + 1);
              p_fields = &pinst->fields;
              sdfSin(v53);
              p_pos_camera_target = &pinst->pos_camera_target;
              sub_854710(p_pos_camera_target, 1u);
              sub_854930(p_fields, 1u);
              sdfCos(*(&pwork[3].monitor + 1), 0);
              sub_854710(p_pos_camera_target, 2u);
              sub_854930(p_fields, 2u);
              localPosition = get_localPosition(v31);
              v105 = get_localRotation(v31);
              localScale = get_localScale(v31);
              {
              }
              TRS(&v92, localPosition, v105, localScale);
              *&v91.x = 0;
              *&v91.z = 0;
              sub_854690(&v91.x, v92.m30, v92.m31, v92.m32, v92.m33);
              SDF_VU0__LOADVECTOR(v91);
              if ((v4 & 0x20) == 0)
                goto LABEL_91;
              name = pwork[5].klass->_1.name;
              v59 = *(pwork[5].monitor + 2);
              v60 = *(name + 8);
              if (v60 > *(v59 + 32))
              {
                SDF_VU0__LOADVECTOR_B(v96);
                SDF_VU0__SUBVECTOR();
                v62 = pwork[5].klass->_1.name;
                v64 = *(v62 + 8) - 1;
              }
              else
              {
LABEL_91:
                if ((v4 & 0x40) == 0)
                  goto LABEL_95;
                v65 = pwork[5].klass->_1.name;
                v67 = *(pwork[5].monitor + 2);
                v68 = *(v65 + 8);
                if (v68 >= *(v67 + 40))
                {
LABEL_95:
                  if ((v4 & 0x80) == 0)
                    goto LABEL_108;
                  v71 = pwork[5].klass->_1.name;
                  v73 = *(pwork[5].monitor + 2);
                  v74 = *(v71 + 9);
                  if (v74 > *(v73 + 36))
                  {
                    SDF_VU0__LOADVECTOR_B(v95);
                    SDF_VU0__SUBVECTOR();
                    v76 = pwork[5].klass->_1.name;
                    v78 = *(v76 + 9);
                    v77 = v76 + 36;
                    v79 = v78 - 1;
                  }
                  else
                  {
LABEL_108:
                    if ((v4 & 0x100) == 0)
                      goto LABEL_114;
                    v80 = pwork[5].klass->_1.name;
                    v82 = *(pwork[5].monitor + 2);
                    v83 = *(v80 + 9);
                    if (v83 >= *(v82 + 44))
                      goto LABEL_114;
                    SDF_VU0__LOADVECTOR_B(v95);
                    SDF_VU0__ADDVECTOR();
                    v85 = pwork[5].klass->_1.name;
                    v86 = *(v85 + 9);
                    v77 = v85 + 36;
                    v79 = v86 + 1;
                  }
                  *v77 = v79;
LABEL_114:
                  SDF_VU0__VECTOR_W_SET_ONE();
                  v101 = get_localPosition(v31);
                  v106 = get_localRotation(v31);
                  v102 = get_localScale(v31);
                  {
                  }
                  TRS(&v92, v101, v106, v102);
                  sub_854690(&p.x, v92.m30, v92.m31, v92.m32, v92.m33);
                  SDF_VU0__STOREVECTOR(&p);
                  v103 = get_localPosition(v31);
                  v91.z = 0.0;
                  *&v91.x = 0;
                  sub_8524C0(&v91.x, p.x, -p.y, p.z);
                  {
                  }
                  v107 = op_Addition(v103, *&v91.x);
                  set_localPosition(v31, v107);
                  return;
                }
                SDF_VU0__LOADVECTOR_B(v96);
                SDF_VU0__ADDVECTOR();
                v62 = pwork[5].klass->_1.name;
                v64 = *(v62 + 8) + 1;
              }
              *(v62 + 8) = v64;
              goto LABEL_95;
            }
            v46 = &pwork[4];
            v47 = 0;
          }
          *(&pwork[3].monitor + 1) = sub_851730(v46, v47);
          goto LABEL_63;
        }
        InitCameraForViewMode(pinst);
        InitModelPosRot(v38, id);
        pinst->XAngle = 0;
        v40 = pwork[5].klass->_1.name;
        *(v40 + 8) = 0;
        v42 = pwork[5].klass->_1.name;
        *(v42 + 9) = 0;
      }
    }
  }
}

// 0x11a7030
void CreateFontExplain(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct fclencyceelem_t_array *pelem;
  s32 monitor;
  s32 id;
  Il2CppObject *pbmd;
  s32 v14;
  s32 v15;
  _FRQ_o *FRQ;
  u8 draw_spd;
  s32 race;
  UnityEngine_Component_o *statusUIScr;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v27;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v29;
  UnityEngine_Component_o *v30;
  UnityEngine_GameObject_o *v31;
  UnityEngine_Transform_o *v32;
  UnityEngine_Component_o *v33;
  UnityEngine_GameObject_o *v35;
  u64 v36[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v36);
      if ((v36[0] & 1) != 0)
        v6 = v36[2];
      else
        v6 = v36 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pelem = DDS3_GBWK->encyc_record->pelem;
  monitor = pwork[1].monitor;
  id = pelem->m_Items[SLOWORD(pwork[1].klass)]->id;
  if (monitor < 0)
  {
    pbmd = pinst->pbmd;
    v14 = itfMesMngInitialize(pbmd, 0, 0);
    LODWORD(pwork[1].monitor) = v14;
    itfMesMngSetMesPosition(v14, 5088, 2160);
    monitor = pwork[1].monitor;
  }
  itfMesMngMarkBitStat(monitor, 0x400000u);
  itfMesMngSetDefaultSpeed(pwork[1].monitor, 26);
  v15 = pwork[1].monitor;
  LODWORD(pwork[10].monitor) = id;
  itfMesMngRequestMessage(v15, id, 0, 2);
  FRQ = itfMesMngGetFRQ(pwork[1].monitor, id);
  draw_spd = FRQ->draw_spd;
  frSetDrawSpeed(FRQ, draw_spd);
  frEnableMode(1);
  if (id == 191)
  {
    race = 38;
  }
  else
  {
    race = Get(id, 1, 0)->race;
  }
  pwork[11].klass = GetEncyc(race);
  pwork[11].monitor = GetEncyc(id);
  frDisableMode(1);
  statusUIScr = _statusUIScr;
  if (!op_Equality(statusUIScr, 0, 0))
  {
    transform = get_transform(statusUIScr, 0);
    v27 = Find(transform, "comstatus_parts", 0);
    gameObject = get_gameObject(v27);
    v29 = get_transform(gameObject, 0);
    v30 = Find(v29, "commoney", 0);
    v31 = get_gameObject(v30);
    if (get_activeSelf(v31))
      SetActive(v31, 0, 0);
    v32 = get_transform(gameObject, 0);
    v33 = Find(v32, "comnote", 0);
    v35 = get_gameObject(v33);
    ClearMessage(v35);
  }
}

// 0x11a2650
void CreateFontListRead(fclEncyc_readtopwork_tag *pwork, s32 sort, s16 **pindex) {
  u64 *v4;
  struct cmpCursorPos_t_o *CursorPos;
  s32 v10;
  s32 NumForDLC;
  s64 Index;
  u64 v14;
  struct fclencyceelem_t_array *pelem;
  fclencyceelem_t_o *v20;
  s32 id;
  s32 race;
  u32 level;
  struct System_Byte_array *linemark;
  struct System_Byte_array *v26;
  s32 v29;
  System_String_o *Encyc;
  _FRQ_o *SmallFontFRQ2_20603280;
  s32 v32;
  s32 v34;
  System_String_o *v35;
  _FRQ_o *v36;
  u32 v37;
  _FRQ_o *v38;
  u64 *v39;
  System_String_o *v41;
  s32 v42;
  s32 v43;
  _FRQ_o *SmallNumFontFRQ_20603536;
  s32 DevilParam;
  s32 v49;
  s32 v51;
  s32 v53;
  s32 v56;
  s32 Ratio2;
  System_String_o *v59;
  u64 *v60;
  s32 v61;
  s32 v62;
  s64 *v63;
  s64 *v64;
  s32 v66;
  s16 *m_Items;
  s64 v69;
  s32 v72;
  struct _FRQ_array *ppfont;
  u32 v74;
  u32 v75;

  ppfont = pwork->ppfont;
  v4 = Allocate(_FRQ);
  _FRQ___ctor(v4);
  CursorPos = pwork->listwin->CursorInfo->CursorPos;
  ReleaseFontList(ppfont, 9);
  Clear(pwork->linemark, 0, pwork->linemark->max_length, 0);
  v9 = CMP_YM(148);
  v10 = v9;
  NumForDLC = fclEncycGetNumForDLC();
  if (NumForDLC > CursorPos->Index)
  {
    Index = CursorPos->Index;
    v69 = NumForDLC;
    m_Items = pindex->m_Items;
    v14 = 0;
    v72 = -1;
    do
    {
      pelem = DDS3_GBWK->encyc_record->pelem;
      v20 = pelem->m_Items[m_Items[Index]];
      id = v20->id;
      race = 38;
      if (id != 191)
      {
        race = Get(id, 1, 0)->race;
      }
      if (sort)
      {
        level = v20->level;
        if (v72 / 10 != level / 0xA)
        {
          linemark = pwork->linemark;
          linemark->m_Items[v14] = 1;
          v72 = level;
        }
      }
      else if (v72 != race)
      {
        v26 = pwork->linemark;
        v26->m_Items[v14] = 1;
        v72 = race;
      }
      v29 = CMP_XM(103);
      Encyc = GetEncyc(race);
      SmallFontFRQ2_20603280 = frwGetSmallFontFRQ2_20603280(v29, v10, 16777200, 0xA09DC380, Encyc, 0);
      v32 = CMP_XM(162);
      v34 = CMP_YM(2);
      v35 = GetEncyc(id);
      v36 = frwGetSmallFontFRQ2_20603280(v32, v34 + v10, 16777200, 0xA09DC380, v35, SmallFontFRQ2_20603280);
      v37 = v20->level;
      if (v37 >= 0x63)
        v37 = 99;
      v75 = v37;
      v38 = v36;
      v39 = sub_8D3950(s32, &v75);
      v41 = Format("{0,3:D}", v39, 0);
      v42 = CMP_XM(286);
      v43 = CMP_YM(4);
      SmallNumFontFRQ_20603536 = frwGetSmallNumFontFRQ_20603536(v42, v43 + v10, 16777200, 0xA09DC380, v41, v38);
      DevilParam = GetDevilParam(v20, 0);
      v49 = GetDevilParam(v20, 2);
      v51 = GetDevilParam(v20, 3);
      v53 = GetDevilParam(v20, 4);
      v55 = GetDevilParam(v20, 5);
      v56 = v55;
      Ratio2 = fclEncycGetRatio2();
      if (v20->id - 191 > 1)
      {
        v74 = (100 * ((v49 + DevilParam + v51 + v53 + v56) * (v49 + DevilParam + v51 + v53 + v56) / 0x14u)) >> (Ratio2 > 99);
        v60 = sub_8D3950(s32, &v74);
        v59 = Format("{0,6:D}", v60, 0);
      }
      else
      {
        v59 = " ";
      }
      v61 = CMP_XM(360);
      v62 = CMP_YM(4);
      v63 = frwGetSmallNumFontFRQ_20603536(v61, v62 + v10, 16777200, 0xA09DC380, v59, SmallNumFontFRQ_20603536);
      v64 = v63;
      ppfont->m_Items[v14] = v64;
      ++Index;
      v66 = CMP_YM(28);
      if (Index >= v69)
        break;
      ++v14;
      v10 += v66;
    }
    while (v14 < 9);
  }
}

// 0x11aefd0
void CreateSortIndexByLevel(s16 ***pout) {
  u64 *v3;
  s32 num;

  num = 0;
  v3 = Allocate(fclEncyc_cmbLevelSortCallback);
  _ctor(v3, 0);
LABEL_7:
  num = DDS3_GBWK->encyc_record->num;
  FillIndex(pout, &num);
  Sort_3899856(*pout, 0, num, v3);
}

// 0x11aed30
void CreateSortIndexByRace(s16 ***pout) {
  u64 *v3;
  s32 num;

  num = 0;
  v3 = Allocate(fclEncyc_cmbRaceSortCallback);
  _ctor(v3, 0);
LABEL_7:
  num = DDS3_GBWK->encyc_record->num;
  FillIndex(pout, &num);
  Sort_3899856(*pout, 0, num, v3);
}

// 0x11b4620
s32 DebugProcDispBound(fclEncyc_instance_tag *pinst, fclEncyc_debug_t *pdebug, sdfDrawTag_t *pdrawtag) {
  bool v7;
  bool v8;
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  struct fclencyceelem_t_array *pelem;
  f32 v18;
  s32 id;
  f32 v21;
  f32 v22;
  f32 formsize;
  System_Object_array *v24;
  s64 *v25;
  s64 *v27;
  f32 v28;
  f32 v30;
  f32 v31;
  Il2CppObject *v33;
  System_Object_array *v34;
  s64 *v35;
  s64 *v36;
  Il2CppObject *v38;
  System_Object_array *v39;
  s64 *v40;
  s64 *v41;
  Il2CppObject *v43;
  System_Object_array *v44;
  const char *name;
  System_Object_array *v46;
  s64 *v48;
  s64 *v49;
  Il2CppObject *v51;
  System_Object_array *v52;
  const char *v53;
  System_Object_array *v54;
  s64 *v56;
  s64 *v57;
  Il2CppObject *v59;
  s32 v66;
  s32 v67;
  s32 monitor_high;
  f32 v69;
  u64 v70[3];

  v7 = DDS3_PAD2CHECK_TRIG(3);
  v8 = DDS3_PAD2CHECK_REP(1);
  if (v7 || v8)
    pdebug->phase = 0;
  dds3ConsPanelTagLink(pdrawtag, 16, 16, 22, 7);
  if (pinst->phase == 7)
  {
    pwork = pinst->pwork;
    if (pwork)
    {
      klass = pwork->klass;
      if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
      {
        sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v70);
        if ((v70[0] & 1) != 0)
          v13 = v70[2];
        else
          v13 = v70 + 1;
        v14 = sub_8C4940(v13);
      }
    }
    pelem = DDS3_GBWK->encyc_record->pelem;
    v18 = *&pwork[3].monitor;
    id = pelem->m_Items[SLOWORD(pwork[1].klass)]->id;
    sub_854710(&pinst->pos_camera_target, 3u);
    v22 = v21;
    formsize = Get(id, 0)->formsize;
    LODWORD(v70[0]) = id;
    v24 = NewSpecific(object, 1u);
    v25 = sub_8D3950(s32, v70);
    v27 = v25;
    v28 = v18 - v22;
    v24->m_Items[0] = v27;
    v30 = v28 - formsize;
    v31 = v30 + -80.0;
    v33 = sdfDevPrintf(29056, 31232, 0xFFFFF0u, 0, "ID\t : 0x%03X", v24);
    sdfDrawTagLink(pdrawtag, v33);
    v69 = v31;
    v34 = NewSpecific(object, 1u);
    v35 = sub_8D3950(f32, &v69);
    v36 = v35;
    v34->m_Items[0] = v36;
    v38 = sdfDevPrintf(29056, 31328, 0xFFFFF0u, 0, "RADIUS : %f", v34);
    sdfDrawTagLink(pdrawtag, v38);
    v39 = NewSpecific(object, 1u);
    monitor_high = HIDWORD(pwork[3].monitor);
    v40 = sub_8D3950(f32, &monitor_high);
    v41 = v40;
    v39->m_Items[0] = v41;
    v43 = sdfDevPrintf(29056, 31424, 0xFFFFF0u, 0, "DEGREE : %f", v39);
    sdfDrawTagLink(pdrawtag, v43);
    v44 = NewSpecific(object, 1u);
    name = pwork[5].klass->_1.name;
    v46 = v44;
    v67 = *(name + 8);
    v48 = sub_8D3950(s32, &v67);
    v49 = v48;
    v46->m_Items[0] = v49;
    v51 = sdfDevPrintf(29056, 31520, 0xFFFFF0u, 0, "OFFSET : X=%3d", v46);
    sdfDrawTagLink(pdrawtag, v51);
    v52 = NewSpecific(object, 1u);
    v53 = pwork[5].klass->_1.name;
    v54 = v52;
    v66 = *(v53 + 9);
    v56 = sub_8D3950(s32, &v66);
    v57 = v56;
    v54->m_Items[0] = v57;
    v59 = sdfDevPrintf(29056, 31616, 0xFFFFF0u, 0, "\t   : Y=%3d", v54);
    sdfDrawTagLink(pdrawtag, v59);
  }
  return 0;
}

// 0x11b3180
s32 DebugProcMenu(fclEncyc_instance_tag *pinst, fclEncyc_debug_t *pdebug, sdfDrawTag_t *pdrawtag) {
  u64 *v7;
  s16 *p_menu_cursor;
  s16 v13;
  s16 menu_cursor;
  s32 v20;
  s16 v21;
  System_String_o *v23;
  System_Object_array *v25;
  Il2CppObject *v27;
  System_String_o *v29;
  System_Object_array *v31;
  Il2CppObject *v33;
  System_String_o *v35;
  System_Object_array *v37;
  Il2CppObject *v39;
  s32 v40;
  System_Object_array *v42;
  Il2CppObject *v44;

  v7 = NewSpecific(string, 3u);
  v7[4] = "DEVIL REGISTER";
  v7[5] = "VIEWMODE KEY";
  v7[6] = "DISP VIEW PARAM";
  else if (DDS3_PAD2CHECK_REP(6))
  {
    goto LABEL_18;
  }
  if (DDS3_PAD2CHECK_REP(7))
  {
    p_menu_cursor = &pdebug->menu_cursor;
    menu_cursor = pdebug->menu_cursor;
    if ((menu_cursor + 1) < 3)
      v13 = menu_cursor + 1;
    else
      v13 = 0;
LABEL_31:
    *p_menu_cursor = v13;
  }
  else if (DDS3_PAD2CHECK_TRIG(3))
  {
    return 1;
  }
  if (DDS3_PAD2CHECK_TRIG(1))
  {
    v20 = pdebug->menu_cursor;
    if (v20 == 2)
    {
      v21 = 3;
      goto LABEL_47;
    }
    if (v20 == 1)
    {
      v21 = 2;
      goto LABEL_47;
    }
    if (!pdebug->menu_cursor)
    {
      v21 = 1;
LABEL_47:
      pdebug->phase = v21;
    }
  }
  dds3ConsPanelTagLink(pdrawtag, 16, 16, 22, 5);
  v23 = v7[4];
  v25 = Empty_string_();
  v27 = sdfDevPrintf(29568, 31232, 0xFFFFF0u, 0, v23, v25);
  sdfDrawTagLink(pdrawtag, v27);
  v29 = v7[5];
  v31 = Empty_string_();
  v33 = sdfDevPrintf(29568, 31328, 0xFFFFF0u, 0, v29, v31);
  sdfDrawTagLink(pdrawtag, v33);
  v35 = v7[6];
  v37 = Empty_string_();
  v39 = sdfDevPrintf(29568, 31424, 0xFFFFF0u, 0, v35, v37);
  sdfDrawTagLink(pdrawtag, v39);
  v40 = pdebug->menu_cursor;
  v42 = Empty_string_();
  v44 = sdfDevPrintf(29056, 96 * v40 + 31232, 0xFFFFF0u, 0, ">", v42);
  sdfDrawTagLink(pdrawtag, v44);
  return 0;
}

// 0x11b36d0
s32 DebugProcRegister(fclEncyc_instance_tag *pinst, fclEncyc_debug_t *pdebug, sdfDrawTag_t *pdrawtag) {
    DDS3_PAD2CHECK_TRIG(0);
    DDS3_PAD2CHECK_REP(0);
    DDS3_PAD2CHECK_PRESS(0);
    fclEncycSearch(0);
    DebugRemoveRecord(0);
    CreateSortIndexByRace(0);
    CreateSortIndexByLevel(0);
    DebugUpdateListwin(0);
    fclEncycRegist(0, 0, 0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x11b43a0
s32 DebugProcViewkey(fclEncyc_instance_tag *pinst, fclEncyc_debug_t *pdebug, sdfDrawTag_t *pdrawtag) {
  bool v7;
  bool v8;
  s8 viewkeytype;
  s8 v13;
  s8 v14;
  System_Object_array *v15;
  System_Object_array *v16;
  s64 *v17;
  s64 *v19;
  Il2CppObject *v22;
  s32 v25;

  v7 = DDS3_PAD2CHECK_TRIG(3);
  v8 = DDS3_PAD2CHECK_REP(1);
  if (v7 || v8)
  {
    pdebug->phase = 0;
    {
LABEL_13:
      if (!DDS3_PAD2CHECK_REP(7))
        goto LABEL_18;
      goto LABEL_14;
    }
  }
  else
  {
      goto LABEL_13;
  }
    goto LABEL_13;
  if (!DDS3_PAD2CHECK_REP(7))
    goto LABEL_18;
LABEL_14:
  viewkeytype = pinst->viewkeytype;
  if ((viewkeytype + 1) <= 2)
    v13 = viewkeytype + 1;
  else
    v13 = 0;
  pinst->viewkeytype = v13;
LABEL_18:
  else if (!DDS3_PAD2CHECK_REP(6))
  {
    goto LABEL_24;
  }
  v14 = pinst->viewkeytype - 1;
  if (v14 < 0)
    v14 = 2;
  pinst->viewkeytype = v14;
LABEL_24:
  dds3ConsPanelTagLink(pdrawtag, 16, 16, 22, 3);
  v15 = NewSpecific(object, 1u);
  v25 = pinst->viewkeytype;
  v16 = v15;
  v17 = sub_8D3950(s32, &v25);
  v19 = v17;
  v16->m_Items[0] = v19;
  v22 = sdfDevPrintf(29056, 31232, 0xFFFFF0u, 0, "VIEWMODE KEY TYPE %d", v16);
  sdfDrawTagLink(pdrawtag, v22);
  return 0;
}

// 0x11b3f20
void DebugRemoveRecord(s32 id) {
  s32 v3;
  s32 v5;
  s32 v7;
  s64 v8;
  s64 v9;
  struct fclencyceelem_t_array *pelem;
  u32 max_length;
  fclencyceelem_t_o *v13;
  struct fclEncycRecord_t_o *encyc_record;

  else
  {
    v3 = fclEncycSearch(id);
    if (v3 < 0)
      return;
  }
  v5 = v3;
  v7 = DDS3_GBWK->encyc_record->num + ~v5;
  if (v7 >= 1)
  {
    v8 = v7;
    v9 = v5;
    do
    {
      pelem = DDS3_GBWK->encyc_record->pelem;
      max_length = pelem->max_length;
      v13 = pelem->m_Items[v9];
      fclencyceelem_t__Copy(v13, DDS3_GBWK->encyc_record->pelem->m_Items[v9 + 1]);
      ++v9;
      --v8;
    }
    while (v8);
  }
  encyc_record = DDS3_GBWK->encyc_record;
  --encyc_record->num;
  LOBYTE(v16[2].klass->_1.this_arg.bits) = 0;
  if (fclEncycGetRatio2() >= 100)
    evtBitOn(2323);
  else
    evtBitOff(2323);
}

// 0x11b41c0
void DebugUpdateListwin(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  cmpCursorInfo_t_o *data;
  struct cmpCursorSize_t_o *CursorSize;
  struct cmpCursorPos_t_o *CursorPos;
  s32 num;
  char v13;
  u64 v14[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readtopwork_tag, v14);
      if ((v14[0] & 1) != 0)
        v6 = v14[2];
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
LABEL_14:
  data = pwork[1].klass->_1.this_arg.data;
  CursorSize = data->CursorSize;
  CursorPos = data->CursorPos;
  if (DDS3_GBWK->encyc_record->num <= 1)
    num = 1;
  else
    num = DDS3_GBWK->encyc_record->num;
  cmpChangeCursorListNums(num, data);
  if (num >= 9)
    v13 = 9;
  else
    v13 = num;
  CursorPos->ShiftMax = v13;
  CursorSize->Y = CursorSize->DefY + data->StepY * CursorPos->Shift;
}

// 0x11a9be0
void DestPhaseReadStatus(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 monitor;
  _FRQ_o *v13;
  u64 v15[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v15);
      if ((v15[0] & 1) != 0)
        v7 = v15[2];
      else
        v7 = v15 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  CMB_GBWK->bReadPhase = 0;
  ReleaseFontExplain(pinst, 1);
  monitor = pwork[1].monitor;
  itfMesMngRelease(monitor);
  v13 = pwork[9].klass;
  if (v13)
  {
    frDestroyFontRequestNow(v13);
    pwork[9].klass = 0;
  }
  fclRbnRelease(pwork[8].monitor);
  pinst->StatusBack = 1;
  if (pinst->pwork)
    pinst->pwork = 0;
}

// 0x11a4950
void DestPhaseReadTop(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  _FRQ_array *v7;
  char *v10;
  s64 *v11;
  u64 v12[3];

  pwork = pinst->pwork;
  klass = pwork->klass;
  if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readtopwork_tag)
  {
    sub_8FC2C0(klass->_1.element_class, fclEncyc_readtopwork_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v7 = pwork[4].klass;
  ReleaseFontList(v7, 9);
  if (pinst->pwork)
    pinst->pwork = 0;
  CMB_GBWK->bReadPhase = 0;
}

// 0x11a1480
void DestPhaseRegistConfirm(fclEncyc_instance_tag *pinst) {
  fclRibbon_t_o **pwork;
  fclRibbon_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  pwork = pinst->pwork;
  v4 = *pwork;
  if (LOBYTE((*pwork)[5].monitor) < typeHierarchyDepth
    || *(*&v4[3].ctr_act + 8 * typeHierarchyDepth - 8) != fclEncyc_registconfirmwork_tag)
  {
    sub_8FC2C0(v4[1].monitor, fclEncyc_registconfirmwork_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  fclRbnRelease(pwork[9]);
  pinst->StatusBack = 1;
  if (pinst->pwork)
    pinst->pwork = 0;
}

// 0x119e6f0
void DestPhaseRegistTop(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  _FRQ_array *v7;
  dds3ProcessID_t_o **p_monitor;
  void *monitor;
  char *v11;
  s64 *v12;
  u64 v13[3];

  pwork = pinst->pwork;
  klass = pwork->klass;
  if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registtopwork_tag)
  {
    sub_8FC2C0(klass->_1.element_class, fclEncyc_registtopwork_tag, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v7 = pwork[3].klass;
  ReleaseFontList(v7, 12);
  monitor = pwork[3].monitor;
  p_monitor = &pwork[3].monitor;
  if (monitor)
  {
    dds3KillProcess(p_monitor, 0);
  }
  if (pinst->pwork)
    pinst->pwork = 0;
}

// 0x11a0120
void DispRegistConfirm(bool sw) {
  _BOOL4 v2;
  UnityEngine_GameObject_o *campObjBG;

  v2 = sw;
  campObjBG = pKernel->campObjBG;
  if (op_Inequality(campObjBG, 0, 0)
    && ((get_activeInHierarchy(campObjBG) ^ v2) & 1) != 0)
  {
    SetActive(campObjBG, v2, 0);
  }
}

// 0x11aae90
void DrawBackBlackBoard(s32 y, s32 alpha) {
  sdfIVector4_t_o *v5;
  sdfIVector4_t_o *v6;
  sdfIVector4_t_o *v7;
  u64 *v8;
  struct System_Int32_array *pm;
  struct System_Int32_array *v13;
  s32 v14;
  struct sdfGrOt_t_array *dds3Ot;

  v5 = sdfIVector4_t__Create(0, 472, 0x2000, 0);
  v6 = sdfIVector4_t__Create(0, 0, 0, 0);
  if (alpha >= 1)
  {
    v7 = v6;
    v8 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v8);
    sdfDrawTagInit(v8);
    pm = v5->pm;
    pm->m_Items[3] = y;
    v13 = v7->pm;
    v14 = (51 * alpha) >> 7;
    v13->m_Items[3] = v14;
    itfMiscDrawSpritePlanePrim(v5, v7, 1u, 0, v8);
    sdfDrawTagLinkOt(dds3Ot->m_Items[8], v8);
  }
}

// 0x11a8680
void DrawExplainBack(statusUI *ui, s32 alpha) {
  UnityEngine_Component_o *transform;
  UnityEngine_Transform_o *v6;
  UnityEngine_Component_o *v7;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v9;
  UnityEngine_Component_o *v10;
  UnityEngine_GameObject_o *v11;
  UnityEngine_Transform_o *v12;
  UnityEngine_Component_o *v13;
  UnityEngine_GameObject_o *v14;
  UnityEngine_Transform_o *v15;
  UnityEngine_Component_o *v16;
  UnityEngine_GameObject_o *v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Component_o *v19;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Transform_o *v21;
  UnityEngine_Component_o *v22;
  UnityEngine_GameObject_o *v23;

  transform = get_transform(ui, 0);
  v6 = get_transform(transform, 0);
  v7 = Find(v6, "comstatus_parts", 0);
  gameObject = get_gameObject(v7);
  v9 = get_transform(transform, 0);
  v10 = Find(v9, "magstatus_parts", 0);
  v11 = get_gameObject(v10);
  if (get_activeSelf(v11))
    SetActive(v11, 0, 0);
  if (!get_activeSelf(gameObject))
    SetActive(gameObject, 1, 0);
  v12 = get_transform(gameObject, 0);
  v13 = Find(v12, "commode", 0);
  v14 = get_gameObject(v13);
  if (!get_activeSelf(v14))
    SetActive(v14, 1, 0);
  v15 = get_transform(gameObject, 0);
  v16 = Find(v15, "commoney", 0);
  v17 = get_gameObject(v16);
  if (get_activeSelf(v17))
    SetActive(v17, 0, 0);
  v18 = get_transform(gameObject, 0);
  v19 = Find(v18, "comveiw", 0);
  v20 = get_gameObject(v19);
  if ((((alpha == 128) ^ get_activeSelf(v20)) & 1) != 0)
    SetActive(v20, alpha == 128, 0);
  v21 = get_transform(gameObject, 0);
  v22 = Find(v21, "comnote", 0);
  v23 = get_gameObject(v22);
  if ((((alpha == 128) ^ get_activeSelf(v23)) & 1) != 0)
    SetActive(v23, alpha == 128, 0);
}

// 0x119dd80
void DrawListWindowBack(void *obj, lstListWindow_t *plistwin) {
  System_String_o *name;

  if (!get_activeSelf(obj))
    SetActive(obj, 1, 0);
  name = get_name(obj);
  UpdateDrawFlag(name);
}

// 0x11aba60
s32 DrawMessage(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 monitor;
  s32 v10;
  _FRQ_o *FRQ;
  struct _FRQ_o *head;
  UnityEngine_Object_o *statusUIScr;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v18;
  UnityEngine_GameObject_o *v19;
  UnityEngine_Transform_o *v20;
  UnityEngine_Component_o *v21;
  UnityEngine_GameObject_o *v22;
  UnityEngine_Transform_o *v23;
  UnityEngine_Component_o *v24;
  UnityEngine_GameObject_o *v25;
  s32 v26;
  s32 v27;
  System_String_o *v28;
  u32 v29;
  struct _TEXT_o *str;
  s32 y;
  s32 color;
  s32 v33;
  u32 v34;
  System_String_o *v35;
  System_String_o *v36;
  UnityEngine_Transform_o *v37;
  UnityEngine_Transform_o *v38;
  u64 *v39;
  System_String_o *v40;
  UnityEngine_Component_o *v41;
  UnityEngine_GUILayer_o *Component_GUILayer;
  bool IsNullOrEmpty;
  UnityEngine_Transform_o *v44;
  UnityEngine_Transform_o *v45;
  u64 *v46;
  System_String_o *v47;
  UnityEngine_Component_o *v48;
  UnityEngine_GUILayer_o *v49;
  u64 v51[3];

  draw_race_devil(pinst);
  pwork = pinst->pwork;
  if (!pwork)
    return 0;
LABEL_6:
  klass = pwork->klass;
  if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
  {
    sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v51);
    if ((v51[0] & 1) != 0)
      v6 = v51[2];
    else
      v6 = v51 + 1;
    v7 = sub_8C4940(v6);
  }
  monitor = pwork[1].monitor;
  v10 = pwork[10].monitor;
  FRQ = itfMesMngGetFRQ(monitor, v10);
  if (!FRQ)
    return 0;
  head = FRQ->head;
  statusUIScr = _statusUIScr;
  if (op_Equality(statusUIScr, 0, 0))
    return 0;
  gameObject = get_gameObject(statusUIScr);
  transform = get_transform(gameObject, 0);
  v18 = Find(transform, "comstatus_parts", 0);
  v19 = get_gameObject(v18);
  v20 = get_transform(v19, 0);
  v21 = Find(v20, "comveiw", 0);
  v22 = get_gameObject(v21);
  if (!get_activeSelf(v22))
    return 0;
  v23 = get_transform(v19, 0);
  v24 = Find(v23, "comnote", 0);
  v25 = get_gameObject(v24);
  if (!get_activeSelf(v25))
    return 0;
  v26 = 1;
  v27 = 232;
  v28 = "";
  v29 = 0;
LABEL_28:
  if (head)
  {
    while (1)
    {
      str = head->str;
      do
      {
        y = head->y;
        color = str->color;
        if (v26 == 1)
        {
          v33 = v27 + color;
          v34 = color & 0xFFFFFF00;
          v27 = v33 - 128;
          if (v33 >= 128)
            v33 = 128;
          color = v33 | v34;
          v26 = v33 > 127;
          str->color = color;
        }
        if (color == 128)
          v35 = sub_3C3A80(&str->chcode, 0);
        else
          v35 = "　";
        v36 = Concat_5224608(v28, v35);
        str = str->next;
        v28 = v36;
      }
      while (str);
      head = head->next;
      if (!head)
        break;
      if (y != head->y)
      {
        v37 = get_transform(v25, 0);
        LODWORD(v51[0]) = ++v29;
        v38 = v37;
        v39 = sub_8D3950(s32, v51);
        v40 = Format("Text_name{0:D2}TM", v39, 0);
        v41 = Find(v38, v40, 0);
        Component_GUILayer = GetComponent_GUILayer_(v41);
        set_text(Component_GUILayer, v28);
        v28 = "";
        if (v29 != 10)
          goto LABEL_28;
        break;
      }
    }
  }
  IsNullOrEmpty = IsNullOrEmpty(v28);
  if (v29 <= 9 && !IsNullOrEmpty)
  {
    v44 = get_transform(v25, 0);
    LODWORD(v51[0]) = v29 + 1;
    v45 = v44;
    v46 = sub_8D3950(s32, v51);
    v47 = Format("Text_name{0:D2}TM", v46, 0);
    v48 = Find(v45, v47, 0);
    v49 = GetComponent_GUILayer_(v48);
    set_text(v49, v28);
  }
  return v26;
}

// 0x11a0f90
void DrawModePanel(statusUI *ui, s32 mode, s32 alpha, char **list, bool bar) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v12;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v14;
  UnityEngine_Component_o *v15;
  UnityEngine_GameObject_o *v16;
  UnityEngine_Transform_o *v17;
  UnityEngine_Component_o *v18;
  u64 *v19;
  UnityEngine_GameObject_o *v20;
  UnityEngine_GameObject_o *v21;
  bool v22;
  UnityEngine_GameObject_o *v23;
  UnityEngine_Transform_o *v24;
  UnityEngine_Component_o *v25;
  UnityEngine_GameObject_o *v26;
  UnityEngine_Transform_o *v27;
  UnityEngine_Component_o *v28;
  UnityEngine_GameObject_o *v29;
  UnityEngine_Transform_o *v30;
  UnityEngine_Component_o *v31;
  s32 v32;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v34;
  s32 v35;
  s32 max_length;
  System_WeakReference_o *Item;
  bool activeSelf;
  System_WeakReference_o *v39;
  System_WeakReference_o *v40;
  Il2CppObject *Component_object;
  System_WeakReference_o *v43;
  System_WeakReference_o *v44;
  System_WeakReference_o *v46;
  System_WeakReference_o *v47;
  UnityEngine_Transform_o *v48;
  UnityEngine_Object_o *v50;

  transform = get_transform(ui, 0);
  v12 = Find(transform, "comstatus_parts", 0);
  gameObject = get_gameObject(v12);
  v14 = get_transform(gameObject, 0);
  v15 = Find(v14, "commode", 0);
  v16 = get_gameObject(v15);
  v17 = get_transform(v16, 0);
  v18 = Find(v17, "commode_menu", 0);
  v19 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v19);
  v20 = get_gameObject(v18);
  if (get_activeSelf(v20))
  {
    if (get_activeSelf(gameObject))
      goto LABEL_5;
LABEL_11:
    SetActive(gameObject, 1, 0);
    if (bar)
      goto LABEL_22;
    goto LABEL_6;
  }
  v23 = get_gameObject(v18);
  SetActive(v23, 1, 0);
  if (!get_activeSelf(gameObject))
    goto LABEL_11;
LABEL_5:
  if (bar)
    goto LABEL_22;
LABEL_6:
  if (get_activeSelf(v16))
  {
    if (alpha != 16)
    {
      if (alpha)
        goto LABEL_22;
      v21 = v16;
      v22 = 0;
      goto LABEL_21;
    }
    v24 = get_transform(v16, 0);
    v25 = Find(v24, "commode_menu", 0);
    v26 = get_gameObject(v25);
    if (!get_activeSelf(v26))
      SetActive(v26, 1, 0);
    v27 = get_transform(v16, 0);
    v28 = Find(v27, "comlr_iconl", 0);
    v29 = get_gameObject(v28);
    if (!get_activeSelf(v29))
      SetActive(v29, 1, 0);
    v30 = get_transform(v16, 0);
    v31 = Find(v30, "comlr_iconr", 0);
    v16 = get_gameObject(v31);
    if (!get_activeSelf(v16))
    {
LABEL_20:
      v21 = v16;
      v22 = 1;
LABEL_21:
      SetActive(v21, v22, 0);
    }
  }
  else if (alpha == 128)
  {
    goto LABEL_20;
  }
LABEL_22:
  _Clear(v19);
  if (get_childCount(v18) >= 1)
  {
    v32 = 0;
    do
    {
      Child = GetChild(v18, v32);
      v34 = get_gameObject(Child);
      _Add(v19, v34);
      ++v32;
    }
    while (v32 < get_childCount(v18));
  }
  if (_get_Count(v19) >= 1)
  {
    v35 = 0;
    do
    {
      max_length = list->max_length;
      Item = _get_Item(
               v19,
               v35);
      activeSelf = get_activeSelf(Item);
      if (v35 >= max_length)
      {
        if (activeSelf)
        {
          v44 = _get_Item(
                  v19,
                  v35);
          SetActive(v44, 0, 0);
        }
      }
      else
      {
        if (!activeSelf)
        {
          v39 = _get_Item(
                  v19,
                  v35);
          SetActive(v39, 1, 0);
        }
        v40 = _get_Item(
                v19,
                v35);
        Component_object = GetComponent_object_(v40);
        GetInteger(Component_object, "commode01");
        if (mode == v35)
        {
          SetInteger(Component_object, "commode01", 1);
          v43 = _get_Item(
                  v19,
                  mode);
          DrawModePanelText(v43, list, mode, 1);
        }
        else
        {
          SetInteger(Component_object, "commode01", 0);
          v46 = _get_Item(
                  v19,
                  v35);
          DrawModePanelText(v46, list, v35, 0);
          v47 = _get_Item(
                  v19,
                  v35);
          v48 = get_transform(v47, 0);
          v50 = Find(v48, "stretch_off/TextTM", 0);
          op_Equality(v50, 0, 0);
        }
      }
      ++v35;
    }
    while (v35 < _get_Count(v19));
  }
}

// 0x11ab850
void DrawPhaseReadExplain(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  datUnitWork_t_o *v9;
  s16 v10;
  u64 v17[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v17);
      if ((v17[0] & 1) != 0)
        v6 = v17[2];
      else
        v6 = v17 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (cmpGetStatusModelHandle())
    pinst->stat |= 0x400u;
  v9 = pwork[10].klass;
  v10 = WORD1(pwork[2].monitor);
  cmpDrawStatusComEx(v9, v10, 255, 0, 0, 0, 0xA09DC380, 1, 0, 0);
  DrawMessage(pinst);
  DrawExplainBack(_statusUIScr, SHIWORD(pwork[6].klass));
  DrawModePanel(
    _statusUIScr,
    0,
    SLOWORD(pwork[2].monitor),
    menuReadPhase,
    0);
  DrawReadMainHelp(pinst);
}

// 0x11a83d0
void DrawPhaseReadStatus(fclEncyc_instance_tag *pinst) {
  UnityEngine_GameObject_o *campObjBG;
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  datUnitWork_t_o *v12;
  s16 v13;
  statusUI_o *statusUIScr;
  s32 klass_high;
  u64 v21[3];

  else if (!cmpGetStatusModelHandle())
  {
    return;
  }
  campObjBG = pKernel->campObjBG;
  if (op_Inequality(campObjBG, 0, 0)
    && !get_activeInHierarchy(campObjBG))
  {
    SetActive(campObjBG, 1, 0);
  }
  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v21);
      if ((v21[0] & 1) != 0)
        v10 = v21[2];
      else
        v10 = v21 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  pinst->stat |= 0x400u;
  v12 = pwork[10].klass;
  v13 = WORD1(pwork[2].monitor);
  cmpDrawStatusComEx(v12, v13, 255, 0, 0, 0, 0xA09DC380, 1, 0, 0);
  statusUIScr = _statusUIScr;
  klass_high = SHIWORD(pwork[6].klass);
  DrawExplainBack(statusUIScr, klass_high);
  DrawModePanel(
    _statusUIScr,
    1,
    SLOWORD(pwork[2].monitor),
    menuReadPhase,
    0);
  DrawReadMainHelp(pinst);
}

// 0x11aabd0
void DrawPhaseReadSummon(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v9;
  s32 v10;
  datUnitWork_t_o *v13;
  s16 v14;
  statusUI_o *statusUIScr;
  s32 monitor_low;
  fclEncyc_instance_tag_o *v23;
  u64 v26[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v26);
      if ((v26[0] & 1) != 0)
        v7 = v26[2];
      else
        v7 = v26 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = pwork[6].klass;
  v10 = SWORD2(pwork[6].klass);
  DrawBackBlackBoard(v9, v10);
  if (cmpGetStatusModelHandle())
    pinst->stat |= 0x400u;
  v13 = pwork[10].klass;
  v14 = WORD1(pwork[2].monitor);
  cmpDrawStatusComEx(v13, v14, 255, 0, 0, 0, 0xA09DC380, 1, 0, 0);
  statusUIScr = _statusUIScr;
  monitor_low = SLOWORD(pwork[2].monitor);
  DrawModePanel(statusUIScr, 1, monitor_low, menuReadPhase, 1);
  if (SLOWORD(pwork[2].monitor) <= 127)
  {
    DrawReadStatusMoney(pinst);
  }
  DrawReadMainHelp(pinst);
  DrawSummonMoney(v23, (WORD1(pwork[1].klass) & 4) == 0);
  UpdateDrawFlag("dlistsum");
}

// 0x11a3460
void DrawPhaseReadTop(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct System_String_array *g_pstr;
  System_String_o *v12;
  Il2CppObject *Item;
  UnityEngine_GameObject_o *GameObject;
  lstListWindow_t_o *v16;
  Il2CppObject *v18;
  UnityEngine_GameObject_o *v19;
  Il2CppObject *v21;
  Il2CppObject *v23;
  Il2CppObject *v25;
  s32 maka;
  s32 Ratio2;
  Il2CppObject *v33;
  u64 v34[3];
  UnityEngine_Color_o white;
  UnityEngine_Color_o yellow;

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readtopwork_tag, v34);
      if ((v34[0] & 1) != 0)
        v6 = v34[2];
      else
        v6 = v34 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v12 = g_pstr->m_Items[1];
  Item = object___get_Item(TextObjs, "comtitle");
  DrawCaption2("comtitle", v12, Item);
  GameObject = GetGameObject("dlistsum");
  DrawListWindowBack(GameObject, v16);
  v18 = object___get_Item(ListObjs, "dlistsum_row");
  object___get_Item(ListObjs, "dlistsum_rule");
  DrawReadListwinElem(v18, v19, pinst);
  v21 = object___get_Item(ListObjs, "dlistsum_cursor");
  UpdateItemCursor(v21, *(pwork[1].klass->_1.this_arg.data + 4), -334.0, -62.0, 0);
  DrawReadListSortBar(pinst);
  v23 = object___get_Item(ListObjs, "dlistmoney_base_money");
  v25 = object___get_Item(CCtrObjs, "dlistmoney_base");
  maka = DDS3_GBWK->maka;
  white = get_white();
  Set2(v25, maka, white, 0);
  if (!get_activeSelf(v23))
    SetActive(v23, 1, 0);
  Ratio2 = fclEncycGetRatio2();
  v33 = object___get_Item(CCtrObjs, "dlistsum_ratio");
  if (Ratio2 >= 100)
    yellow = get_yellow();
  else
    yellow = get_white();
  Set(v33, Ratio2, yellow, 0, 0);
}

// 0x11ae160
void DrawPhaseReadView(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v9;
  s32 v10;
  datUnitWork_t_o *v13;
  s16 v14;
  u64 *v16;
  struct fclencyceelem_t_array *pelem;
  dds3ModelHandle_t_o *v22;
  s32 id;
  struct sdfModelOt_t_array *dds3ModelOt;
  statusUI_o *statusUIScr;
  s32 monitor_low;
  dds3ModelHandle_t_o *v35[3];
  dds3ModelHandle_t_o *aHandle;

  aHandle = 0;
  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v35);
      if ((v35[0] & 1) != 0)
        v7 = v35[2];
      else
        v7 = v35 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = pwork[6].klass;
  v10 = SWORD2(pwork[6].klass);
  DrawBackBlackBoard(v9, v10);
  if ((pinst->stat & 0x10) != 0)
  {
    v16 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v16);
    aHandle = v16;
    aHandle = cmpGetStatusModelHandle();
    if (aHandle)
    {
      if ((pinst->stat & 0x400) == 0)
      {
        pelem = DDS3_GBWK->encyc_record->pelem;
        id = pelem->m_Items[SLOWORD(pwork[1].klass)]->id;
        InitModelPosRot(v22, id);
        pinst->stat |= 0x400u;
      }
      mdlLink(&aHandle, dds3ModelOt->m_Items);
    }
  }
  else
  {
    if (cmpGetStatusModelHandle())
      pinst->stat |= 0x400u;
    v13 = pwork[10].klass;
    v14 = WORD1(pwork[2].monitor);
    cmpDrawStatusComEx(v13, v14, 255, 0, 0, 0, 0xA09DC380, 1, 0, 0);
  }
  StatusTitleOff();
  statusUIScr = _statusUIScr;
  monitor_low = SLOWORD(pwork[2].monitor);
  DrawModePanel(statusUIScr, 2, monitor_low, menuReadPhase, 0);
  DrawReadMainHelp(pinst);
}

// 0x119fda0
void DrawPhaseRegistConfirm(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 klass_low;
  s32 klass_high;
  statusUI_o *statusUIScr;
  datUnitWork_t_o *monitor;
  s32 v16;
  statusUI_o *v18;
  datUnitWork_t_o *v21;
  s32 v22;
  struct sdfModelOt_t_array *dds3ModelOt;
  sdfModelOt_t_o *v25;
  u64 v27[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registconfirmwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registconfirmwork_tag, v27);
      if ((v27[0] & 1) != 0)
        v7 = v27[2];
      else
        v7 = v27 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  klass_low = LOBYTE(pwork[1].klass);
  klass_high = HIDWORD(pwork[1].klass);
  if (klass_low == 1)
  {
    statusUIScr = _statusUIScr;
    DrawModePanel(statusUIScr, 0, 128, menuRegistPhase, 0);
    monitor = pwork[3].monitor;
    v16 = pwork[2].klass;
    cmpDrawStatusComEx2(monitor, v16, 0, 0x80 - klass_high, 255, 0, 0, 0, 0xA09DC380, 1, 0, 0, 0);
    klass_low = LOBYTE(pwork[1].klass);
  }
  if (!klass_low)
  {
    v18 = _statusUIScr;
    DrawModePanel(v18, 1, 128, menuRegistPhase, 0);
    v21 = pwork[4].klass;
    v22 = pwork[1].monitor;
    cmpDrawStatusComEx2(v21, v22, 0, klass_high - 32, 255, 0, 0, 0, 0xA09DC380, 1, 0, 0, 0);
  }
  else
  {
    if (!LODWORD(dds3ModelOt->max_length))
      goto LABEL_35;
  }
  v25 = dds3ModelOt->m_Items[0];
  cmpDrawStatusModel(v25);
  PPSV2_StatusMode = 1;
  PPSV2_StatusDevilId = WORD2(pwork[4].klass->_1.name);
}

// 0x119da40
void DrawPhaseRegistTop(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct System_String_array *g_pstr;
  System_String_o *v11;
  Il2CppObject *Item;
  UnityEngine_GameObject_o *GameObject;
  lstListWindow_t_o *v15;
  Il2CppObject *v17;
  Il2CppObject *v22;
  cmpCursorPos_t_o *v23;
  Il2CppObject *v24;
  UnityEngine_GameObject_o *v25;
  bool v26;
  Il2CppObject *v27;
  u64 v28[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registtopwork_tag, v28);
      if ((v28[0] & 1) != 0)
        v6 = v28[2];
      else
        v6 = v28 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  else
  {
    if (!LODWORD(g_pstr->max_length))
      goto LABEL_13;
  }
  v11 = g_pstr->m_Items[0];
  Item = object___get_Item(TextObjs, "comtitle");
  DrawCaption2("comtitle", v11, Item);
  GameObject = GetGameObject("dlistrec");
  DrawListWindowBack(GameObject, v15);
  v17 = object___get_Item(ListObjs, "dlistrec_row");
  DrawRegistListwinElem(v17, pinst);
  if (!pinst->phase)
  {
    if (LOBYTE(pwork[1].klass))
    {
      v22 = object___get_Item(ListObjs, "dlistrec_cursor");
      v23 = *(*(pwork[1].monitor + 6) + 32LL);
      UpdateItemCursor(v22, v23, -214.0, -62.0);
      v24 = object___get_Item(ListObjs, "dlistrec_cursor");
      if (!get_activeSelf(v24))
      {
        v25 = v24;
        v26 = 1;
LABEL_37:
        SetActive(v25, v26, 0);
      }
    }
    else
    {
      v27 = object___get_Item(ListObjs, "dlistrec_cursor");
      if (get_activeSelf(v27))
      {
        v25 = v27;
        v26 = 0;
        goto LABEL_37;
      }
    }
  }
}

// 0x119af60
dds3ProcessFunc_t *DrawProc(dds3ProcessID_t *proc_id) {
  u64 *v2;
  u64 *v3;
  u64 *v5;
  u64 *v7;
  u64 *v9;
  u64 *v11;
  u64 *v13;
  u64 *v15;
  u64 *v17;
  struct fclEncyc_instance_tag_o *g_pinst;
  u32 phase;
  s64 v23;

  v2 = NewSpecific(fclEncyc_funcDelegate, 9u);
  v3 = Allocate(fclEncyc_funcDelegate);
  _ctor(v3, 0, Method_fclEncyc_DrawPhaseRegistTop__, 0);
  v2[4] = v3;
  v5 = Allocate(fclEncyc_funcDelegate);
  _ctor(v5, 0, Method_fclEncyc_DrawPhaseRegistConfirm__, 0);
  v2[5] = v5;
  v7 = Allocate(fclEncyc_funcDelegate);
  _ctor(v7, 0, Method_fclEncyc_DrawPhaseRegistTop__, 0);
  v2[6] = v7;
  v9 = Allocate(fclEncyc_funcDelegate);
  _ctor(v9, 0, Method_fclEncyc_DrawPhaseReadTop__, 0);
  v2[7] = v9;
  v11 = Allocate(fclEncyc_funcDelegate);
  _ctor(v11, 0, Method_fclEncyc_DrawPhaseReadStatus__, 0);
  v2[8] = v11;
  v13 = Allocate(fclEncyc_funcDelegate);
  _ctor(v13, 0, Method_fclEncyc_DrawPhaseReadSummon__, 0);
  v2[9] = v13;
  v15 = Allocate(fclEncyc_funcDelegate);
  _ctor(v15, 0, Method_fclEncyc_DrawPhaseReadExplain__, 0);
  v2[10] = v15;
  v17 = Allocate(fclEncyc_funcDelegate);
  _ctor(v17, 0, Method_fclEncyc_DrawPhaseReadView__, 0);
  v2[11] = v17;
  if (g_pinst && (g_pinst->stat & 0x20) != 0)
  {
    phase = g_pinst->phase;
    if (phase > 3 || phase == 1)
    {
      Set3DParam(g_pinst);
      v23 = g_pinst->phase;
      if (*(v2 + 6) > v23)
        goto LABEL_43;
    }
    else
    {
      v23 = phase;
      if (*(v2 + 6) > phase)
      {
LABEL_43:
        if (v2[v23 + 4])
        {
          Invoke(v2[g_pinst->phase + 4], g_pinst, 0);
        }
        return 0;
      }
    }
  }
  return 0;
}

// 0x11a4460
void DrawReadListSortBar(fclEncyc_instance_tag *pinst) {
  s32 sort;
  Il2CppObject *Item;
  Il2CppObject *v6;
  Il2CppObject *Component_object;
  Il2CppObject *v8;

  sort = pinst->sort;
  Item = object___get_Item(ListObjs, "dlistsum_race");
  v6 = object___get_Item(ListObjs, "dlistsum_level");
  Component_object = GetComponent_object_(Item);
  SetInteger(Component_object, "dlistsort", 1 - sort);
  v8 = GetComponent_object_(v6);
  SetInteger(v8, "dlistsort", sort);
}

// 0x11b0d80
void DrawReadListwinCaption(fclEncyc_instance_tag *pinst) {
  sdfIVector4_t_o *v2;
  sdfIVector4_t_o *v3;
  sdfIVector4_t_o *v4;
  u64 *v5;
  s64 *v6;
  s64 *v7;
  s64 *v9;
  s64 *v10;
  s64 *v12;
  s64 *v13;
  s64 *v15;
  s64 *v16;
  struct System_Int32_array *pm;
  sdfIVector4_t_Fields *p_fields;
  u64 *v24;
  struct System_Int32_array *v25;
  u64 i;
  s64 v30;
  s32 v31;
  struct System_Int32_array *v32;
  s64 v34;
  s32 v36;
  sdfIVector4_t_o *v38;
  struct System_Int32_array *v43;
  sdfIVector4_t_Fields *v44;
  sdfIVector4_t_o *g_uv_summon_back;
  struct sdfTexHandle_t_array *texhandle;
  sdfTexHandle_t_o *v52;
  struct System_Int32_array *v54;
  struct System_Int32_array *v59;
  struct System_Int32_array *v66;
  struct sdfTexHandle_t_array *v75;
  struct System_Int32_array *v77;
  struct System_Int32_array *v86;
  struct System_Int32_array *v91;
  struct System_Int32_array *v97;
  sdfIVector4_t_o *v107;
  struct sdfTexHandle_t_array *cmpTex;
  struct System_Int32_array *v110;
  struct System_Int32_array *v114;
  struct sdfTexHandle_t_array *v123;
  struct System_Int32_array *v125;
  struct System_Int32_array *v134;
  struct System_Int32_array *v143;
  struct System_Int32_array *v150;
  struct sdfTexHandle_t_array *v159;
  struct System_Int32_array *v161;
  struct System_Int32_array *v166;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v179;
  sdfIVector4_t_o *uv;
  sdfDrawTag_t_o *aTag;

  v2 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v2);
  uv = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(uv);
  v3 = sdfIVector4_t__Create(0, 0, 0, 64);
  v4 = sdfIVector4_t__Create(47, 31, 31, 128);
  v5 = NewSpecific(sdfIVector2_t, 4u);
  v6 = sdfIVector2_t__Create(1616, 2480);
  v7 = v6;
  v5[4] = v7;
  v9 = sdfIVector2_t__Create(2576, 4224);
  v10 = v9;
  v5[5] = v10;
  v12 = sdfIVector2_t__Create(4656, 5136);
  v13 = v12;
  v5[6] = v13;
  v15 = sdfIVector2_t__Create(5696, 6992);
  v16 = v15;
  v5[7] = v16;
  aTag = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(aTag);
  sdfDrawTagInit(aTag);
  p_fields = &v2->fields;
  pm = v2->pm;
  pm->m_Items[1] = 944;
  p_fields->pm->m_Items[3] = 1016;
  v24 = v5 + 4;
  v25 = p_fields->pm;
  for (i = 0; i != 4; ++i)
  {
    v30 = *(v24[i] + 16LL);
    v31 = *(v30 + 32);
    v25->m_Items[0] = v31;
    v32 = p_fields->pm;
    v34 = *(v24[i] + 16LL);
    v36 = *(v34 + 36);
    v32->m_Items[2] = v36;
    if (i == 3)
      v38 = v4;
    else
      v38 = v3;
    itfMiscDrawSpritePlanePrim(v2, v38, 0xFFFFF0u, 0, aTag);
    v25 = v2->pm;
  }
  v25->m_Items[0] = 1696;
  p_fields->pm->m_Items[1] = 920;
  p_fields->pm->m_Items[2] = 2432;
  p_fields->pm->m_Items[3] = 1040;
  v44 = &uv->fields;
  v43 = uv->pm;
  v43->m_Items[0] = 16;
  v44->pm->m_Items[1] = 352;
  v44->pm->m_Items[2] = 752;
  v44->pm->m_Items[3] = 592;
  texhandle = pinst->texhandle;
  v52 = texhandle->m_Items[0];
  itfMiscDrawSpritePrim(v2, uv, g_uv_summon_back, 0xFFFFF0u, v52, 0, aTag);
  v54 = v2->pm;
  v54->m_Items[0] = 3024;
  p_fields->pm->m_Items[2] = 3792;
  v44->pm->m_Items[0] = 768;
  v44->pm->m_Items[2] = 1536;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v59 = v2->pm;
  v59->m_Items[0] = 4672;
  p_fields->pm->m_Items[2] = 5104;
  v44->pm->m_Items[0] = 1552;
  v44->pm->m_Items[1] = 352;
  v44->pm->m_Items[2] = 1984;
  v44->pm->m_Items[3] = 592;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v66 = v2->pm;
  v66->m_Items[0] = 6256;
  p_fields->pm->m_Items[1] = 912;
  p_fields->pm->m_Items[2] = 6432;
  p_fields->pm->m_Items[3] = 1040;
  v44->pm->m_Items[0] = 2992;
  v44->pm->m_Items[1] = 592;
  v44->pm->m_Items[2] = 3168;
  v44->pm->m_Items[3] = 848;
  v75 = pinst->texhandle;
  itfMiscDrawSpritePrim(v2, uv, g_uv_summon_back, 0xFFFFF0u, v75->m_Items[1], 0, aTag);
  v77 = v2->pm;
  v77->m_Items[0] = 4944;
  p_fields->pm->m_Items[1] = 2992;
  p_fields->pm->m_Items[2] = 5360;
  p_fields->pm->m_Items[3] = 3224;
  v44->pm->m_Items[0] = 2896;
  v44->pm->m_Items[1] = 928;
  v44->pm->m_Items[2] = 3312;
  v44->pm->m_Items[3] = 1392;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v86 = v2->pm;
  v86->m_Items[0] = 7440;
  p_fields->pm->m_Items[2] = 7856;
  v44->pm->m_Items[0] = 3328;
  v44->pm->m_Items[2] = 3744;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v91 = v2->pm;
  v91->m_Items[0] = 5360;
  p_fields->pm->m_Items[2] = 7440;
  v44->pm->m_Items[0] = 3296;
  v44->pm->m_Items[2] = 3312;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v97 = v2->pm;
  v97->m_Items[0] = 2896;
  p_fields->pm->m_Items[1] = 3312;
  p_fields->pm->m_Items[2] = 3840;
  p_fields->pm->m_Items[3] = 3480;
  v44->pm->m_Items[0] = 16;
  v44->pm->m_Items[1] = 1200;
  v44->pm->m_Items[2] = 960;
  v44->pm->m_Items[3] = 1536;
  v107 = g_uv_summon_back;
  itfMiscDrawSpritePrim(v2, uv, v107, 0xFFFFF0u, cmpTex->m_Items[1], 0, aTag);
  v110 = v2->pm;
  v110->m_Items[0] = 3840;
  p_fields->pm->m_Items[2] = 0x2000;
  v44->pm->m_Items[0] = 944;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v114 = v2->pm;
  v114->m_Items[0] = 5280;
  p_fields->pm->m_Items[1] = 3024;
  p_fields->pm->m_Items[2] = 6624;
  p_fields->pm->m_Items[3] = 3184;
  v44->pm->m_Items[0] = 1648;
  v44->pm->m_Items[1] = 16;
  v44->pm->m_Items[2] = 2992;
  v44->pm->m_Items[3] = 336;
  v123 = pinst->texhandle;
  itfMiscDrawSpritePrim(v2, uv, g_uv_summon_back, 0xFFFFF0u, v123->m_Items[2], 0, aTag);
  v125 = v2->pm;
  v125->m_Items[0] = 7360;
  p_fields->pm->m_Items[1] = 3056;
  p_fields->pm->m_Items[2] = 7600;
  p_fields->pm->m_Items[3] = 3184;
  v44->pm->m_Items[0] = 3008;
  v44->pm->m_Items[1] = 16;
  v44->pm->m_Items[2] = 3248;
  v44->pm->m_Items[3] = 272;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v134 = v2->pm;
  v134->m_Items[0] = 3264;
  p_fields->pm->m_Items[1] = 3312;
  p_fields->pm->m_Items[2] = 5568;
  p_fields->pm->m_Items[3] = 3472;
  v44->pm->m_Items[0] = 16;
  v44->pm->m_Items[1] = 480;
  v44->pm->m_Items[2] = 2320;
  v44->pm->m_Items[3] = 800;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v143 = v2->pm;
  v143->m_Items[0] = 5776;
  p_fields->pm->m_Items[2] = 7968;
  v44->pm->m_Items[0] = 16;
  v44->pm->m_Items[1] = 816;
  v44->pm->m_Items[2] = 2208;
  v44->pm->m_Items[3] = 1136;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v150 = v2->pm;
  v150->m_Items[0] = 4304;
  p_fields->pm->m_Items[1] = 240;
  p_fields->pm->m_Items[2] = 7264;
  p_fields->pm->m_Items[3] = 480;
  v44->pm->m_Items[0] = 32;
  v44->pm->m_Items[1] = 752;
  v44->pm->m_Items[2] = 2992;
  v44->pm->m_Items[3] = 1232;
  v159 = cmpTex;
  itfMiscDrawSpritePrim(v2, uv, g_uv_summon_back, 0xFFFFF0u, v159->m_Items[3], 0, aTag);
  v161 = v2->pm;
  v161->m_Items[0] = 7264;
  p_fields->pm->m_Items[2] = 0x2000;
  v44->pm->m_Items[0] = 2976;
  v44->pm->m_Items[2] = 2992;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v166 = v2->pm;
  v166->m_Items[0] = 7760;
  p_fields->pm->m_Items[1] = 304;
  p_fields->pm->m_Items[2] = 7968;
  p_fields->pm->m_Items[3] = 472;
  v44->pm->m_Items[0] = 3200;
  v44->pm->m_Items[1] = 16;
  v44->pm->m_Items[2] = 3408;
  v44->pm->m_Items[3] = 352;
  itfMiscDrawSpritePrim2(v2, uv, g_uv_summon_back, 0xFFFFF0u, 0, aTag);
  v179 = dds3Ot->m_Items[71];
  sdfDrawTagLinkOt(v179, aTag);
}

// 0x11a3830
void DrawReadListwinElem(void *obj, void *rule, fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  s64 v11;
  s64 v12;
  Il2CppObject *Item;
  cmpCursorPos_t_o *CursorPos;
  s32 NumForDLC;
  s32 Index;
  u64 v22;
  u64 v23;
  u64 *v26;
  Il2CppObject *v28;
  Il2CppObject *v31;
  struct fclencyceelem_t_array *pelem;
  s64 v36;
  Il2CppClass **v38;
  s32 race;
  fclencyceelem_t_o *v40;
  s32 id;
  u32 level;
  u8 *monitor;
  u8 *v45;
  System_Collections_Generic_Dictionary_object__object__o *TextObjs;
  Il2CppObject *v50;
  Il2CppObject *v52;
  System_String_o *Encyc;
  System_Object_array *v54;
  System_Object_array *v55;
  s64 *v56;
  s64 *v58;
  System_String_o *v60;
  System_Collections_Generic_Dictionary_object__object__o *v61;
  Il2CppObject *v62;
  Il2CppObject *v64;
  System_String_o *v65;
  System_Object_array *v66;
  System_Object_array *v67;
  s64 *v68;
  s64 *v69;
  System_String_o *v71;
  s32 v74;
  System_Collections_Generic_Dictionary_object__object__o *CCtrObjs;
  Il2CppObject *v76;
  Il2CppObject *v77;
  s32 DevilParam;
  s32 v82;
  s32 v84;
  s32 v86;
  u32 v89;
  bool v90;
  char v93;
  s32 v94;
  s32 v95;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v97;
  Il2CppObject *v98;
  bool activeSelf;
  System_Collections_Generic_Dictionary_object__object__o *v102;
  Il2CppObject *v103;
  Il2CppObject *v104;
  u32 v105;
  u64 *v106;
  Il2CppObject *v108;
  Il2CppObject *v110;
  s64 i;
  u64 *v112;
  Il2CppObject *v114;
  Il2CppObject *v117;
  u8 *v119;
  s32 v121;
  _BOOL4 v122;
  Il2CppObject *v125;
  Il2CppObject *v126;
  s32 v127;
  s64 v128;
  s32 sort;
  cmpCursorInfo_t_o *pCursorInfo;
  s32 v131;
  s32 v132;
  s32 col2;
  u64 v134[3];
  UnityEngine_Color_o white;
  UnityEngine_Color_o v136;

  col2 = 0;
  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readtopwork_tag, v134);
      if ((v134[0] & 1) != 0)
        v9 = v134[2];
      else
        v9 = v134 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  sort = pinst->sort;
  pCursorInfo = pwork[1].klass->_1.this_arg.data;
  col2 = 2;
  v11 = 120;
  if (sort)
    v11 = 128;
  v12 = *(&pinst->klass + v11);
  DrawBackPanel("combgcolor");
  if (!get_activeSelf(obj))
    SetActive(obj, 1, 0);
  get_transform(obj, 0);
  Item = object___get_Item(ListObjs, "dlistsum_scroll");
  CursorPos = pCursorInfo->CursorPos;
  DrawScrollBar(Item, "cfgscroll", CursorPos);
  NumForDLC = fclEncycGetNumForDLC();
  Index = pCursorInfo->CursorPos->Index;
  Clear(pwork[4].monitor, 0, *(pwork[4].monitor + 6), 0);
  LODWORD(v22) = 0;
  if (NumForDLC <= Index)
    goto LABEL_115;
  v23 = 0;
  v131 = -1;
  v126 = pwork;
  v127 = NumForDLC;
  v128 = v12;
  do
  {
    v22 = v23 + 1;
    LODWORD(v134[0]) = v23 + 1;
    v26 = sub_8D3950(s32, v134);
    v28 = Format("dlistsum_row{0:D2}", v26, 0);
    v31 = object___get_Item(ListObjs, v28);
    if (!op_Equality(v31, 0, 0))
    {
      if (!get_activeSelf(v31))
        SetActive(v31, 1, 0);
      pelem = DDS3_GBWK->encyc_record->pelem;
      v36 = *(v12 + 2LL * Index + 32);
      v38 = &pelem->obj.klass + v36;
      race = 38;
      v40 = v38[4];
      id = v40->id;
      if (id != 191)
      {
        race = Get(id, 1, 0)->race;
      }
      if (sort)
      {
        level = v40->level;
        if (v131 / 10 != level / 0xA)
        {
          monitor = pwork[4].monitor;
          monitor[v23 + 32] = 1;
          v131 = level;
        }
      }
      else if (v131 != race)
      {
        v45 = pwork[4].monitor;
        v45[v23 + 32] = 1;
        v131 = race;
      }
      cmpGetCursorBlurFontCol(pCursorInfo, v23, v23, 0, 256, &col2, 0);
      v50 = Concat_5224608(v28, "_name");
      v52 = object___get_Item(TextObjs, v50);
      Encyc = GetEncyc(id);
      v54 = NewSpecific(object, 1u);
      LODWORD(v134[0]) = col2;
      v55 = v54;
      v56 = sub_8D3950(s32, v134);
      v58 = v56;
      v55->m_Items[0] = v58;
      v60 = RepColTag(Encyc, v55);
      set_text(v52, v60);
      v61 = TextObjs;
      v62 = Concat_5224608(v28, "_race");
      v64 = object___get_Item(v61, v62);
      pwork = v126;
      v65 = GetEncyc(race);
      v66 = NewSpecific(object, 1u);
      v132 = col2;
      v67 = v66;
      v68 = sub_8D3950(s32, &v132);
      v69 = v68;
      v67->m_Items[0] = v69;
      v71 = RepColTag(v65, v67);
      set_text(v64, v71);
      if (v40->level >= 0x63u)
        v74 = 99;
      else
        v74 = v40->level;
      v76 = Concat_5224608(v28, "_lv");
      v77 = object___get_Item(CCtrObjs, v76);
      white = get_white();
      Set2(v77, v74, white, 0);
      DevilParam = GetDevilParam(v40, 0);
      v82 = GetDevilParam(v40, 2);
      v84 = GetDevilParam(v40, 3);
      v86 = GetDevilParam(v40, 4);
      v88 = GetDevilParam(v40, 5);
      v89 = 100 * ((v82 + DevilParam + v84 + v86 + v88) * (v82 + DevilParam + v84 + v86 + v88) / 0x14u);
      v90 = fclEncycGetRatio2() <= 99;
      v93 = !v90;
      v94 = v89 >> v93;
      if (v40->id - 191 >= 2)
        v95 = v94;
      else
        v95 = 0;
      {
        v12 = v128;
        NumForDLC = v127;
      }
      else
      {
        v12 = v128;
        NumForDLC = v127;
      }
      v97 = Concat_5224608(v28, "_money");
      v98 = object___get_Item(ListObjs, v97);
      activeSelf = get_activeSelf(v98);
      if (v95)
      {
        if (!activeSelf)
          SetActive(v98, 1, 0);
        v102 = CCtrObjs;
        v103 = Concat_5224608(v28, "_money");
        v104 = object___get_Item(v102, v103);
        v136 = get_white();
        Set(v104, v95, v136, 0, 0);
      }
      else if (activeSelf)
      {
        SetActive(v98, 0, 0);
      }
      ++Index;
    }
    if (v22 > 8)
      break;
    v23 = v22;
  }
  while (Index < NumForDLC);
  if (v22 <= 8)
  {
LABEL_115:
    v105 = v22 - 1;
    do
    {
      LODWORD(v134[0]) = v105 + 2;
      v106 = sub_8D3950(s32, v134);
      v108 = Format("dlistsum_row{0:D2}", v106, 0);
      v110 = object___get_Item(ListObjs, v108);
      if (get_activeSelf(v110))
        SetActive(v110, 0, 0);
      ++v105;
    }
    while (v105 < 8);
  }
  for (i = 33; i != 41; ++i)
  {
    LODWORD(v134[0]) = i - 32;
    v112 = sub_8D3950(s32, v134);
    v114 = Format("dlistsum_rule{0:D2}", v112, 0);
    v117 = object___get_Item(ListObjs, v114);
    if (!op_Equality(v117, 0, 0))
    {
      v119 = pwork[4].monitor;
      v121 = v119[i];
      v122 = v119[i] != 0;
      if (((get_activeSelf(v117) ^ v122) & 1) != 0)
        SetActive(v117, v121 != 0, 0);
    }
  }
  v125 = object___get_Item(ListObjs, "dlistsum_rule09");
  if (op_Inequality(v125, 0, 0) && get_activeSelf(v125))
    SetActive(v125, 0, 0);
}

// 0x11a88c0
void DrawReadMainHelp(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  sdfIVector4_t_o *v7;
  sdfIVector4_t_o *v8;
  sdfIVector4_t_o *v9;
  u64 *v10;
  s64 v13;
  u32 v14;
  s32 v15;
  s32 v16;
  struct System_Int32_array *pm;
  struct System_Int32_array *v18;
  struct System_Int32_array *v20;
  struct System_Int32_array *v22;
  struct System_Int32_array *v24;
  struct System_Int32_array *v26;
  struct System_Int32_array *v28;
  struct System_Int32_array *v30;
  sdfIVector4_t_o *g_uv_summon_back;
  struct sdfTexHandle_t_array *texhandle;
  sdfTexHandle_t_o *v36;
  struct System_Int32_array *v37;
  struct System_Int32_array *v39;
  struct System_Int32_array *v41;
  struct System_Int32_array *v43;
  struct sdfGrOt_t_array *dds3Ot;
  u64 *v49;
  s64 v52;
  u32 v53;
  s32 v54;
  s32 v55;
  struct System_Int32_array *v56;
  struct System_Int32_array *v57;
  struct System_Int32_array *v59;
  struct System_Int32_array *v61;
  struct System_Int32_array *v63;
  sdfIVector4_t_Fields *p_fields;
  struct System_Int32_array *v69;
  sdfIVector4_t_Fields *v70;
  s32 v73;
  s32 v75;
  struct sdfTexHandle_t_array *v77;
  sdfTexHandle_t_o *v79;
  struct System_Int32_array *v80;
  s32 v82;
  struct System_Int32_array *v84;
  struct System_Int32_array *v88;
  struct System_Int32_array *v97;
  sdfIVector4_t_o *v102;
  sdfIVector4_t_o *v103;
  sdfDrawTag_t_o *v104;
  sdfIVector4_t_o *v105;
  struct System_Int32_array *v106;
  s32 v114;
  struct System_Int32_array *v116;
  s32 v123;
  struct sdfTexHandle_t_array *v126;
  struct System_Int32_array *v128;
  struct sdfTexHandle_t_array *v135;
  struct System_Int32_array *v137;
  struct System_Int32_array *v146;
  struct System_Int32_array *v153;
  struct sdfGrOt_t_array *v162;
  s32 v170;
  s32 v171;
  u64 v173[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v173);
      if ((v173[0] & 1) != 0)
        v5 = v173[2];
      else
        v5 = v173 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  v7 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v7);
  v8 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v8);
  v9 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v9);
  if (SWORD2(pwork[8].klass) >= 1)
  {
    v10 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v10);
    sdfDrawTagInit(v10);
    v13 = *(pwork[7].monitor + 2);
    v14 = *(v13 + 24);
    v15 = *(v13 + 32);
    v16 = *(*(pwork[7].monitor + 2) + 36LL);
    pm = v9->pm;
    pm->m_Items[0] = 128;
    v18 = v9->pm;
    v18->m_Items[1] = 128;
    v20 = v9->pm;
    v20->m_Items[2] = 128;
    v22 = v9->pm;
    v22->m_Items[3] = SWORD2(pwork[8].klass);
    v24 = v7->pm;
    v24->m_Items[0] = v15;
    v26 = v7->pm;
    v26->m_Items[1] = v16;
    v28 = v7->pm;
    v28->m_Items[2] = v15 + 3216;
    v30 = v7->pm;
    v30->m_Items[3] = v16 + 240;
    texhandle = pinst->texhandle;
    v36 = texhandle->m_Items[3];
    itfMiscDrawSpritePrim(v7, g_uv_summon_back, v9, 0xFFFFF0u, v36, 0, v10);
    v37 = v7->pm;
    v37->m_Items[0] = v15 + 1824;
    v39 = v7->pm;
    v39->m_Items[1] = v16 + 40;
    v41 = v7->pm;
    v41->m_Items[2] = v15 + 2768;
    v43 = v7->pm;
    v43->m_Items[3] = v16 + 200;
    itfMiscDrawSpritePrim2(v7, g_uv_summon, v9, 0xFFFFF0u, 0, v10);
    sdfDrawTagLinkOt(dds3Ot->m_Items[71], v10);
  }
  if (SWORD2(pwork[7].klass) >= 1)
  {
    v49 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v49);
    sdfDrawTagInit(v49);
    v52 = *(pwork[6].monitor + 2);
    v53 = *(v52 + 24);
    v54 = *(v52 + 32);
    v55 = *(*(pwork[6].monitor + 2) + 36LL);
    v56 = v9->pm;
    v56->m_Items[0] = 128;
    v57 = v9->pm;
    v57->m_Items[1] = 128;
    v59 = v9->pm;
    v59->m_Items[2] = 128;
    v61 = v9->pm;
    v61->m_Items[3] = SWORD2(pwork[7].klass);
    p_fields = &v8->fields;
    v63 = v8->pm;
    v63->m_Items[0] = 2352;
    p_fields->pm->m_Items[1] = 480;
    p_fields->pm->m_Items[2] = 4048;
    p_fields->pm->m_Items[3] = 1072;
    v70 = &v7->fields;
    v69 = v7->pm;
    v69->m_Items[0] = v54;
    v70->pm->m_Items[1] = v55;
    v73 = v54 + 1696;
    v70->pm->m_Items[2] = v73;
    v170 = v55;
    v75 = v55 + 296;
    v70->pm->m_Items[3] = v75;
    v77 = pinst->texhandle;
    v79 = v77->m_Items[2];
    itfMiscDrawSpritePrim(v7, v8, v9, 0xFFFFF0u, v79, 0, v49);
    v80 = v7->pm;
    v80->m_Items[0] = v54 + 0x2000;
    v82 = v54 + 6496;
    v70->pm->m_Items[2] = v82;
    itfMiscDrawSpritePrim2(v7, v8, v9, 0xFFFFF0u, 0, v49);
    v84 = v8->pm;
    v84->m_Items[0] = 4032;
    v70->pm->m_Items[0] = v73;
    v70->pm->m_Items[2] = v82;
    itfMiscDrawSpritePrim2(v7, v8, v9, 0xFFFFF0u, 0, v49);
    v88 = v8->pm;
    v88->m_Items[0] = 1728;
    p_fields->pm->m_Items[1] = 1632;
    p_fields->pm->m_Items[2] = 2176;
    p_fields->pm->m_Items[3] = 2032;
    v70->pm->m_Items[0] = v54 + 2176;
    v171 = v170 + 56;
    v70->pm->m_Items[1] = v171;
    v70->pm->m_Items[2] = v54 + 2624;
    v70->pm->m_Items[3] = v170 + 256;
    itfMiscDrawSpritePrim2(v7, v8, v9, 0xFFFFF0u, 0, v49);
    v97 = v8->pm;
    v97->m_Items[0] = 1232;
    p_fields->pm->m_Items[2] = 1712;
    v70->pm->m_Items[0] = v54 + 3504;
    v102 = v8;
    v70->pm->m_Items[2] = v54 + 3984;
    v103 = v8;
    v104 = v49;
    itfMiscDrawSpritePrim2(v7, v102, v9, 0xFFFFF0u, 0, v49);
    v105 = v103;
    v106 = v103->pm;
    v106->m_Items[0] = 3424;
    p_fields->pm->m_Items[1] = 1424;
    p_fields->pm->m_Items[2] = 3776;
    p_fields->pm->m_Items[3] = 1824;
    v70->pm->m_Items[0] = v54 + 5552;
    v70->pm->m_Items[1] = v170 + 48;
    v70->pm->m_Items[2] = v54 + 5904;
    v114 = v170 + 248;
    v70->pm->m_Items[3] = v114;
    itfMiscDrawSpritePrim2(v7, v105, v9, 0xFFFFF0u, 0, v104);
    v116 = v105->pm;
    v116->m_Items[0] = 2624;
    p_fields->pm->m_Items[1] = 496;
    p_fields->pm->m_Items[2] = 2976;
    p_fields->pm->m_Items[3] = 864;
    v70->pm->m_Items[0] = v54 + 912;
    v70->pm->m_Items[1] = v171;
    v123 = v54 + 1264;
    v70->pm->m_Items[2] = v123;
    v70->pm->m_Items[3] = v170 + 240;
    v126 = pinst->texhandle;
    itfMiscDrawSpritePrim(v7, v105, v9, 0xFFFFF0u, v126->m_Items[1], 0, v104);
    v128 = v105->pm;
    v128->m_Items[0] = 576;
    p_fields->pm->m_Items[1] = 1376;
    p_fields->pm->m_Items[2] = 1152;
    p_fields->pm->m_Items[3] = 1744;
    v70->pm->m_Items[0] = v123;
    v70->pm->m_Items[2] = v54 + 1840;
    v135 = pinst->texhandle;
    itfMiscDrawSpritePrim(v7, v105, v9, 0xFFFFF0u, v135->m_Items[4], 0, v104);
    v137 = v105->pm;
    v137->m_Items[0] = 16;
    p_fields->pm->m_Items[1] = 1376;
    p_fields->pm->m_Items[2] = 560;
    p_fields->pm->m_Items[3] = 1776;
    v70->pm->m_Items[0] = v54 + 2624;
    v70->pm->m_Items[1] = v171;
    v70->pm->m_Items[2] = v54 + 3168;
    v70->pm->m_Items[3] = v170 + 256;
    itfMiscDrawSpritePrim2(v7, v105, v9, 0xFFFFF0u, 0, v104);
    v146 = v105->pm;
    v146->m_Items[0] = 1168;
    p_fields->pm->m_Items[1] = 1376;
    p_fields->pm->m_Items[2] = 2400;
    p_fields->pm->m_Items[3] = 1776;
    v70->pm->m_Items[0] = v54 + 3984;
    v70->pm->m_Items[2] = v54 + 5216;
    itfMiscDrawSpritePrim2(v7, v105, v9, 0xFFFFF0u, 0, v104);
    v153 = v105->pm;
    v153->m_Items[0] = 2416;
    p_fields->pm->m_Items[2] = 3792;
    v70->pm->m_Items[0] = v54 + 5904;
    v70->pm->m_Items[1] = v170 + 48;
    v70->pm->m_Items[2] = v54 + 7280;
    v70->pm->m_Items[3] = v114;
    itfMiscDrawSpritePrim2(v7, v105, v9, 0xFFFFF0u, 0, v104);
    v162 = dds3Ot;
    sdfDrawTagLinkOt(v162->m_Items[71], v104);
  }
}

// 0x11ab070
void DrawReadStatusMoney(fclEncyc_instance_tag *pinst) {
  Il2CppObject *Item;
  Il2CppObject *v5;
  s32 maka;
  UnityEngine_Object_o *statusUIScr;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v14;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *v18;
  UnityEngine_Transform_o *v19;
  UnityEngine_Component_o *v20;
  UnityEngine_GameObject_o *v21;
  UnityEngine_Transform_o *v22;
  UnityEngine_Component_o *v23;
  UnityEngine_GameObject_o *v24;
  UnityEngine_Transform_o *v25;
  UnityEngine_Component_o *v26;
  UnityEngine_GameObject_o *v27;
  UnityEngine_Color_o white;

  Item = object___get_Item(ListObjs, "dlistmoney_base_money");
  v5 = object___get_Item(CCtrObjs, "dlistmoney_base");
  maka = DDS3_GBWK->maka;
  white = get_white();
  Set(v5, maka, white, 0, 0);
  if (!get_activeSelf(Item))
    SetActive(Item, 1, 0);
  statusUIScr = _statusUIScr;
  if (!op_Equality(statusUIScr, 0, 0))
  {
    transform = get_transform(_statusUIScr, 0);
    v14 = Find(transform, "comstatus_parts", 0);
    gameObject = get_gameObject(v14);
    v16 = get_transform(gameObject, 0);
    v17 = Find(v16, "commode", 0);
    v18 = get_gameObject(v17);
    v19 = get_transform(v18, 0);
    v20 = Find(v19, "commode_menu", 0);
    v21 = get_gameObject(v20);
    if (get_activeSelf(v21))
      SetActive(v21, 0, 0);
    v22 = get_transform(v18, 0);
    v23 = Find(v22, "comlr_iconl", 0);
    v24 = get_gameObject(v23);
    if (get_activeSelf(v24))
      SetActive(v24, 0, 0);
    v25 = get_transform(v18, 0);
    v26 = Find(v25, "comlr_iconr", 0);
    v27 = get_gameObject(v26);
    if (get_activeSelf(v27))
      SetActive(v27, 0, 0);
  }
}

// 0x11b25b0
void DrawRegistAllHelp(fclEncyc_instance_tag *pinst) {
  sdfIVector4_t_o *v3;
  sdfIVector4_t_o *v4;
  u64 *v5;
  struct System_Int32_array *pm;
  struct System_Int32_array *v10;
  struct System_Int32_array *v12;
  struct System_Int32_array *v14;
  struct sdfTexHandle_t_array *texhandle;
  sdfIVector4_t_o *g_uv_summon_back;
  sdfTexHandle_t_o *v20;
  struct System_Int32_array *v21;
  struct System_Int32_array *v23;
  struct System_Int32_array *v25;
  struct System_Int32_array *v27;
  struct System_Int32_array *v29;
  struct System_Int32_array *v31;
  struct System_Int32_array *v33;
  struct System_Int32_array *v35;
  struct System_Int32_array *v37;
  struct System_Int32_array *v39;
  struct System_Int32_array *v41;
  struct System_Int32_array *v43;
  struct System_Int32_array *v45;
  struct System_Int32_array *v47;
  struct System_Int32_array *v49;
  struct System_Int32_array *v51;
  struct System_Int32_array *v53;
  struct System_Int32_array *v55;
  struct System_Int32_array *v57;
  struct System_Int32_array *v59;
  struct sdfGrOt_t_array *dds3Ot;

  v3 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v3);
  v4 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v4);
  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  sdfDrawTagInit(v5);
  pm = v3->pm;
  pm->m_Items[0] = 4976;
  v10 = v3->pm;
  v10->m_Items[1] = 160;
  v12 = v3->pm;
  v12->m_Items[2] = 0x2000;
  v14 = v3->pm;
  v14->m_Items[3] = 400;
  texhandle = pinst->texhandle;
  v20 = texhandle->m_Items[3];
  itfMiscDrawSpritePrim(v3, g_uv_summon_back, g_uv_summon_back, 0xFFFFF0u, v20, 0, v5);
  v21 = v4->pm;
  v21->m_Items[0] = 96;
  v23 = v4->pm;
  v23->m_Items[1] = 1200;
  v25 = v4->pm;
  v25->m_Items[2] = 400;
  v27 = v4->pm;
  v27->m_Items[3] = 1520;
  v29 = v3->pm;
  v29->m_Items[0] = 6352;
  v31 = v3->pm;
  v31->m_Items[1] = 200;
  v33 = v3->pm;
  v33->m_Items[2] = 6656;
  v35 = v3->pm;
  v35->m_Items[3] = 360;
  itfMiscDrawSpritePrim2(v3, v4, g_uv_summon_back, 0xFFFFF0u, 0, v5);
  v37 = v4->pm;
  v37->m_Items[0] = 3296;
  v39 = v4->pm;
  v39->m_Items[1] = 1552;
  v41 = v4->pm;
  v41->m_Items[2] = 3936;
  v43 = v4->pm;
  v43->m_Items[3] = 1872;
  v45 = v3->pm;
  v45->m_Items[0] = 6688;
  v47 = v3->pm;
  v47->m_Items[2] = 7328;
  itfMiscDrawSpritePrim2(v3, v4, g_uv_summon_back, 0xFFFFF0u, 0, v5);
  v49 = v4->pm;
  v49->m_Items[0] = 720;
  v51 = v4->pm;
  v51->m_Items[1] = 1200;
  v53 = v4->pm;
  v53->m_Items[2] = 1360;
  v55 = v4->pm;
  v55->m_Items[3] = 1520;
  v57 = v3->pm;
  v57->m_Items[0] = 7216;
  v59 = v3->pm;
  v59->m_Items[2] = 7856;
  itfMiscDrawSpritePrim2(v3, v4, g_uv_summon_back, 0xFFFFF0u, 0, v5);
  sdfDrawTagLinkOt(dds3Ot->m_Items[71], v5);
}

// 0x11b2b80
void DrawRegistKeyHelp(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  sdfIVector4_t_o *v8;
  sdfIVector4_t_o *v9;
  u64 *v10;
  s64 v13;
  u32 v14;
  s32 v15;
  struct System_Int32_array *pm;
  s32 v17;
  struct System_Int32_array *v18;
  struct System_Int32_array *v20;
  struct System_Int32_array *v22;
  s32 v23;
  struct System_Int32_array *v25;
  struct System_Int32_array *v27;
  struct System_Int32_array *v29;
  struct System_Int32_array *v31;
  struct sdfTexHandle_t_array *texhandle;
  sdfIVector4_t_o *g_uv_summon_back;
  sdfTexHandle_t_o *v37;
  struct System_Int32_array *v38;
  struct System_Int32_array *v40;
  struct System_Int32_array *v42;
  struct System_Int32_array *v44;
  struct sdfGrOt_t_array *dds3Ot;
  u64 v53[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registconfirmwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registconfirmwork_tag, v53);
      if ((v53[0] & 1) != 0)
        v6 = v53[2];
      else
        v6 = v53 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v8);
  v9 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v9);
  if (SWORD2(pwork[3].klass) >= 1)
  {
    v10 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v10);
    sdfDrawTagInit(v10);
    v13 = *(pwork[2].monitor + 2);
    v14 = *(v13 + 24);
    v15 = *(v13 + 32);
    pm = v9->pm;
    v17 = *(*(pwork[2].monitor + 2) + 36LL);
    pm->m_Items[0] = 128;
    v18 = v9->pm;
    v18->m_Items[1] = 128;
    v20 = v9->pm;
    v20->m_Items[2] = 128;
    v22 = v9->pm;
    v23 = SWORD2(pwork[3].klass);
    v22->m_Items[3] = v23;
    v25 = v8->pm;
    v25->m_Items[0] = v15;
    v27 = v8->pm;
    v27->m_Items[1] = v17;
    v29 = v8->pm;
    v29->m_Items[2] = v15 + 3216;
    v31 = v8->pm;
    v31->m_Items[3] = v17 + 240;
    texhandle = pinst->texhandle;
    v37 = texhandle->m_Items[3];
    itfMiscDrawSpritePrim(v8, g_uv_summon_back, v9, 0xFFFFF0u, v37, 0, v10);
    v38 = v8->pm;
    v38->m_Items[0] = v15 + 1824;
    v40 = v8->pm;
    v40->m_Items[1] = v17 + 40;
    v42 = v8->pm;
    v42->m_Items[2] = v15 + 2768;
    v44 = v8->pm;
    v44->m_Items[3] = v17 + 200;
    itfMiscDrawSpritePrim2(v8, g_uv_regist, v9, 0xFFFFF0u, 0, v10);
    sdfDrawTagLinkOt(dds3Ot->m_Items[71], v10);
  }
}

// 0x119de20
void DrawRegistListwinElem(void *obj, fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *Item;
  cmpCursorPos_t_o *CursorPos;
  s64 v14;
  u32 v15;
  u64 *v18;
  Il2CppObject *v20;
  Il2CppObject *v22;
  struct datUnitWork_t_array *unitwork;
  struct System_Byte_array *pnakamaindex;
  s64 v28;
  datUnitWork_t_o *v30;
  System_String_o *name;
  s32 id;
  System_String_o *v34;
  bool IsDLC;
  s32 race;
  System_Collections_Generic_Dictionary_object__object__o *TextObjs;
  Il2CppObject *v41;
  Il2CppObject *v43;
  System_String_o *Encyc;
  System_Object_array *v45;
  System_Object_array *v46;
  s64 *v47;
  s64 *v49;
  System_String_o *v51;
  System_Collections_Generic_Dictionary_object__object__o *v52;
  Il2CppObject *v53;
  Il2CppObject *v55;
  System_String_o *v56;
  System_Object_array *v57;
  System_Object_array *v58;
  s64 *v59;
  s64 *v60;
  System_String_o *v62;
  System_Collections_Generic_Dictionary_object__object__o *CCtrObjs;
  Il2CppObject *v64;
  Il2CppObject *v65;
  s32 maxhp;
  CounterCtr_o *v67;
  System_Collections_Generic_Dictionary_object__object__o *v68;
  Il2CppObject *v69;
  Il2CppObject *v70;
  s32 maxmp;
  CounterCtr_o *v72;
  System_Collections_Generic_Dictionary_object__object__o *v73;
  Il2CppObject *v74;
  Il2CppObject *v76;
  s32 LevelForDraw;
  s64 v78;
  u32 v79;
  u32 v80;
  u64 *v81;
  Il2CppObject *v83;
  Il2CppObject *v85;
  Il2CppObject *v86;
  s64 num_nakama;
  cmpCursorInfo_t_o *pCursorInfo;
  fclEncyc_instance_tag_o *v89;
  u32 v90;
  s32 v91;
  s32 col2;
  u64 v93[3];
  UnityEngine_Color_o white;
  UnityEngine_Color_o v95;
  UnityEngine_Color_o v96;

  v89 = pinst;
  col2 = 0;
  pwork = v89->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registtopwork_tag, v93);
      if ((v93[0] & 1) != 0)
        v7 = v93[2];
      else
        v7 = v93 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pCursorInfo = *(pwork[1].monitor + 6);
  col2 = 2;
  DrawBackPanel("combgcolor");
  if (!get_activeSelf(obj))
    SetActive(obj, 1, 0);
  get_transform(obj, 0);
  Item = object___get_Item(ListObjs, "dlistrec_scroll");
  CursorPos = pCursorInfo->CursorPos;
  DrawScrollBar(Item, "scroll", CursorPos);
  num_nakama = v89->num_nakama;
  if (v89->num_nakama <= pCursorInfo->CursorPos->Index)
  {
    v79 = 0;
LABEL_83:
    v80 = v79 - 1;
    do
    {
      LODWORD(v93[0]) = v80 + 2;
      v81 = sub_8D3950(s32, v93);
      v83 = Format("dlistrec_row{0:D2}", v81, 0);
      v85 = object___get_Item(ListObjs, v83);
      if (get_activeSelf(v85))
        SetActive(v85, 0, 0);
      ++v80;
    }
    while (v80 < 0xB);
    return;
  }
  v14 = pCursorInfo->CursorPos->Index + 32LL;
  v15 = -1;
  v86 = pwork;
  do
  {
    LODWORD(v93[0]) = v15 + 2;
    v18 = sub_8D3950(s32, v93);
    v20 = Format("dlistrec_row{0:D2}", v18, 0);
    v90 = v15 + 2;
    v22 = object___get_Item(ListObjs, v20);
    if (!get_activeSelf(v22))
      SetActive(v22, 1, 0);
    unitwork = DDS3_GBWK->unitwork;
    pnakamaindex = v89->pnakamaindex;
    v28 = *(&pnakamaindex->obj.klass + v14);
    v30 = unitwork->m_Items[v28];
    name = get_name(v22);
    id = v30->id;
    v34 = name;
    IsDLC = IsDLC();
    if (id == 192 && IsDLC)
    {
      id = 191;
      race = 38;
    }
    else if (id == 191)
    {
      race = 38;
    }
    else
    {
      race = Get(id, 1, 0)->race;
    }
    cmpGetCursorBlurFontCol(pCursorInfo, v15 + 1, v15 + 1, 0, 256, &col2, 0);
    if (!LOBYTE(pwork[1].klass) && col2 == 1)
      col2 = 0;
    v41 = Concat_5224608(v34, "_name");
    v43 = object___get_Item(TextObjs, v41);
    Encyc = GetEncyc(id);
    v45 = NewSpecific(object, 1u);
    LODWORD(v93[0]) = col2;
    v46 = v45;
    v47 = sub_8D3950(s32, v93);
    v49 = v47;
    v46->m_Items[0] = v49;
    v51 = RepColTag(Encyc, v46);
    set_text(v43, v51);
    v52 = TextObjs;
    v53 = Concat_5224608(v34, "_race");
    v55 = object___get_Item(v52, v53);
    v56 = GetEncyc(race);
    v57 = NewSpecific(object, 1u);
    v91 = col2;
    v58 = v57;
    v59 = sub_8D3950(s32, &v91);
    v60 = v59;
    v58->m_Items[0] = v60;
    v62 = RepColTag(v56, v58);
    set_text(v55, v62);
    v64 = Concat_5224608(v34, "_hp");
    v65 = object___get_Item(CCtrObjs, v64);
    maxhp = v30->maxhp;
    v67 = v65;
    white = get_white();
    Set2(v67, maxhp, white, 0);
    v68 = CCtrObjs;
    v69 = Concat_5224608(v34, "_mp");
    v70 = object___get_Item(v68, v69);
    maxmp = v30->maxmp;
    v72 = v70;
    v95 = get_white();
    Set2(v72, maxmp, v95, 0);
    v73 = CCtrObjs;
    v74 = Concat_5224608(v34, "_lv");
    v76 = object___get_Item(v73, v74);
    LevelForDraw = datGetLevelForDraw(v30);
    v96 = get_white();
    Set2(v76, LevelForDraw, v96, 0);
    pwork = v86;
    ++v15;
    if (v90 > 0xB)
      break;
    v78 = v14 - 31;
    ++v14;
  }
  while (v78 < num_nakama);
  if (v15 <= 0xA)
  {
    v79 = v15 + 1;
    goto LABEL_83;
  }
}

// 0x119fb90
void DrawStatus1Shot(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  datUnitWork_t_o *monitor;
  s32 v9;
  datUnitWork_t_o *v10;
  s32 v11;
  char *v12;
  s64 *v13;
  u64 v14[3];

  pwork = pinst->pwork;
  klass = pwork->klass;
  if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registconfirmwork_tag)
  {
    sub_8FC2C0(klass->_1.element_class, fclEncyc_registconfirmwork_tag, v14);
    if ((v14[0] & 1) != 0)
      v12 = v14[2];
    else
      v12 = v14 + 1;
    v13 = sub_8C4940(v12);
  }
  if (LOBYTE(pwork[1].klass) == 1)
  {
    CMB_GBWK->bReadPhase = 1;
    monitor = pwork[3].monitor;
    v9 = pwork[2].klass;
    cmpDrawStatusComEx2(monitor, v9, 0, 0x80u, 255, 0, 0, 0, 0xA09DC380, 1, 0, 0, 0);
  }
  else
  {
    CMB_GBWK->bReadPhase = 0;
    v10 = pwork[4].klass;
    v11 = pwork[1].monitor;
    cmpDrawStatusComEx2(v10, v11, 0, 0x60u, 255, 0, 0, 0, 0xA09DC380, 1, 0, 0, 0);
  }
}

// 0x11a9f30
void DrawSummonMoney(fclEncyc_instance_tag *pinst, bool sw) {
  _BOOL4 v3;
  UnityEngine_GameObject_o *GameObject;
  Il2CppObject *Item;
  bool v10;
  Il2CppObject *v11;
  Il2CppObject *v14;
  Il2CppObject *v17;
  Il2CppObject *v20;
  Il2CppObject *v23;
  Il2CppObject *v26;
  Il2CppObject *v29;
  Il2CppObject *v32;
  Il2CppObject *v35;
  Il2CppObject *v38;
  Il2CppObject *v41;

  v3 = sw;
  GameObject = GetGameObject("dlistsum");
  if (((get_activeSelf(GameObject) ^ v3) & 1) != 0)
    SetActive(GameObject, v3, 0);
  Item = object___get_Item(ListObjs, "dlistmoney_base");
  if (((get_activeSelf(Item) ^ v3) & 1) != 0)
    SetActive(Item, v3, 0);
  v10 = !v3;
  v11 = object___get_Item(ListObjs, "dlistsumlr_base");
  if (((get_activeSelf(v11) ^ v3) & 1) == 0)
    SetActive(v11, v10, 0);
  v14 = object___get_Item(ListObjs, "dlistsum_combase");
  if (((get_activeSelf(v14) ^ v3) & 1) == 0)
    SetActive(v14, v10, 0);
  v17 = object___get_Item(ListObjs, "dlistsumindex_base");
  if (((get_activeSelf(v17) ^ v3) & 1) == 0)
    SetActive(v17, v10, 0);
  v20 = object___get_Item(ListObjs, "dlistsum_base");
  if (((get_activeSelf(v20) ^ v3) & 1) == 0)
    SetActive(v20, v10, 0);
  v23 = object___get_Item(ListObjs, "dlistsum_scroll");
  if (((get_activeSelf(v23) ^ v3) & 1) == 0)
    SetActive(v23, v10, 0);
  v26 = object___get_Item(ListObjs, "dlistsum_cursor");
  if (((get_activeSelf(v26) ^ v3) & 1) == 0)
    SetActive(v26, v10, 0);
  v29 = object___get_Item(ListObjs, "dlistsum_ratio");
  if (((get_activeSelf(v29) ^ v3) & 1) == 0)
    SetActive(v29, v10, 0);
  v32 = object___get_Item(ListObjs, "dlistsum_scroll");
  if (((get_activeSelf(v32) ^ v3) & 1) == 0)
    SetActive(v32, v10, 0);
  v35 = object___get_Item(ListObjs, "combmenu_cursor");
  if (((get_activeSelf(v35) ^ v3) & 1) == 0)
    SetActive(v35, v10, 0);
  v38 = object___get_Item(ListObjs, "dlistsum_row");
  if (((get_activeSelf(v38) ^ v3) & 1) == 0)
    SetActive(v38, v10, 0);
  v41 = object___get_Item(ListObjs, "dlistsum_rule");
  if (((get_activeSelf(v41) ^ v3) & 1) == 0)
    SetActive(v41, v10, 0);
}

// 0x11a2ce0
void DrawSummonMoneyReset(fclEncyc_instance_tag *pinst) {
  fclEncyc_instance_tag_o *v3;
  Il2CppObject *Item;
  Il2CppObject *Component_object;

  DrawSummonMoney(v3, 0);
  Item = object___get_Item(ListObjs, "dlistmoney_base");
  if (!get_activeSelf(Item))
    SetActive(Item, 1, 0);
  Component_object = GetComponent_object_(Item);
  DisplayOn(Component_object);
}

// 0x11aa450
void DrawSummonMoneyStart(fclEncyc_instance_tag *pinst) {
  Il2CppObject *Item;
  Il2CppObject *Component_object;

  Item = object___get_Item(ListObjs, "dlistmoney_base");
  Component_object = GetComponent_object_(Item);
  Display(Component_object, 1);
}

// 0x11aaa90
void ExecSummon(s32 recindex) {
  struct fclencyceelem_t_array *pelem;
  fclencyceelem_t_o *v6;
  s32 id;
  s32 v8;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v13;

  pelem = DDS3_GBWK->encyc_record->pelem;
  v6 = pelem->m_Items[recindex];
  id = v6->id;
  v8 = datAddDevil(id, 0);
  unitwork = DDS3_GBWK->unitwork;
  v13 = unitwork->m_Items[v8];
  SetRecordToUnitCore(v13, v6);
}

// 0x11a6320
void FadeInRibbon(fclEncyc_readmainwork_tag *pwork) {
  s16 v2;
  struct System_Int32_array *pm;
  struct System_Int32_array *ribbon_accel;
  struct System_Int32_array *v5;
  struct System_Int32_array *v6;
  struct System_Int32_array *v8;
  struct System_Int32_array *v10;
  s32 v12;

  v2 = pwork->ribbon_alpha + 16;
  if (v2 >= 128)
    v2 = 128;
  pwork->ribbon_alpha = v2;
  pm = pwork->ribbon_pos->pm;
  ribbon_accel = pwork->ribbon_accel;
  pm->m_Items[0] += ribbon_accel->m_Items[0];
  v5 = pwork->ribbon_accel;
  v5->m_Items[0] -= 32;
  v6 = pwork->ribbon_accel;
  v6->m_Items[1] += 32;
  v8 = pwork->ribbon_pos->pm;
  v10 = pwork->ribbon_accel;
  v12 = v10->m_Items[1] + v8->m_Items[2];
  v8->m_Items[2] = v12;
}

// 0x11aa900
void FadeOutRibbon(fclEncyc_readmainwork_tag *pwork) {
  struct System_Int32_array *ribbon_accel;
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  struct System_Int32_array *v6;
  struct System_Int32_array *v8;
  struct System_Int32_array *v11;

  ribbon_accel = pwork->ribbon_accel;
  pwork->ribbon_alpha = (pwork->ribbon_alpha - 16) & ~((pwork->ribbon_alpha - 16) >> 15);
  ribbon_accel->m_Items[0] += 32;
  pm = pwork->ribbon_pos->pm;
  v5 = pwork->ribbon_accel;
  pm->m_Items[0] -= v5->m_Items[0];
  v6 = pwork->ribbon_pos->pm;
  v8 = pwork->ribbon_accel;
  v6->m_Items[2] -= v8->m_Items[1];
  v11 = pwork->ribbon_accel;
  v11->m_Items[1] -= 32;
}

// 0x11aee50
void FillIndex(s16 ***pout, s32 *num) {
  u64 v5;
  u32 v6;
  struct fclencyceelem_t_array *pelem;
  char *v11;

  if (*num >= 1)
  {
    v5 = 0;
    v6 = 0;
    while (1)
    {
      pelem = DDS3_GBWK->encyc_record->pelem;
      if (pelem->m_Items[v5]->id != 191)
        break;
      else if (GetOrUsed(2))
      {
        break;
      }
LABEL_19:
      if (++v5 >= *num)
        goto LABEL_22;
    }
    v11 = *pout + 2 * v6++;
    *(v11 + 16) = v5;
    goto LABEL_19;
  }
  v6 = 0;
LABEL_22:
  *num = v6;
}

// 0x11b05e0
s32 GetAnalogPad(void) {
  struct System_Byte_array_array_array *dds3PadAnalog;
  System_Byte_array_array *v3;
  System_Byte_array *v4;
  struct System_Byte_array_array_array *v5;
  u32 v6;
  System_Byte_array_array *v7;
  System_Byte_array *v8;
  u32 v9;
  s32 ANALOG_L_LEFT;
  u32 ANALOG_L_UP;
  struct System_Byte_array_array_array *v18;
  System_Byte_array_array *v19;
  System_Byte_array *v20;
  struct System_Byte_array_array_array *v21;
  u32 v22;
  System_Byte_array_array *v23;
  System_Byte_array *v24;
  u32 v25;
  u32 ANALOG_R_LEFT;
  u32 ANALOG_R_UP;

  if (!LODWORD(dds3PadAnalog->max_length))
    goto LABEL_70;
LABEL_6:
  v3 = dds3PadAnalog->m_Items[0];
  v4 = v3->m_Items[0];
  v5 = dds3PadAnalog;
  v6 = v4->m_Items[0];
  v7 = v5->m_Items[0];
  v8 = v7->m_Items[0];
  v9 = v8->m_Items[1];
  if (v6 <= 0x4C)
  {
    else
    {
      if (v9 <= 0x4C)
        goto LABEL_30;
    }
  }
  else if (v6 >= 0xB4)
  {
    ANALOG_L_LEFT = ANALOG_L_RIGHT;
    if (v9 <= 0x4C)
      goto LABEL_30;
  }
  else
  {
    ANALOG_L_LEFT = 0;
    if (v9 <= 0x4C)
      goto LABEL_30;
  }
  if (v9 >= 0xB4)
  {
    ANALOG_L_UP = ANALOG_L_DOWN;
    goto LABEL_34;
  }
LABEL_35:
  v18 = dds3PadAnalog;
  if (!LODWORD(v18->max_length))
    goto LABEL_74;
LABEL_38:
  v19 = v18->m_Items[0];
  v20 = v19->m_Items[1];
  v21 = dds3PadAnalog;
  v22 = v20->m_Items[0];
  v23 = v21->m_Items[0];
  v24 = v23->m_Items[1];
  v25 = v24->m_Items[1];

  {
    if (v22 < 0xB4)
      goto LABEL_57;
    ANALOG_R_LEFT = ANALOG_R_RIGHT;
  }
  ANALOG_L_LEFT |= ANALOG_R_LEFT;
LABEL_57:
  if (v25 <= 0x4C)
  {
    return ANALOG_R_UP | ANALOG_L_LEFT;
  }
  if (v25 >= 0xB4)
  {
    ANALOG_R_UP = ANALOG_R_DOWN;
    return ANALOG_R_UP | ANALOG_L_LEFT;
  }
  return ANALOG_L_LEFT;
}

// 0x11afa30
s32 GetDevilParam(fclencyceelem_t *pelem, s32 type) {
  struct System_SByte_array *param;
  struct System_SByte_array *skillparam;
  s32 v6;
  struct System_SByte_array *mitamaparam;
  s32 v9;
  s32 v11;

  param = pelem->param;
  skillparam = pelem->skillparam;
  v6 = param->m_Items[type];
  mitamaparam = pelem->mitamaparam;
  v9 = skillparam->m_Items[type];
  v11 = v9 + v6 + mitamaparam->m_Items[type];
  if (v11 < 1)
    return 1;
  if (v11 >= 40)
    return 40;
  return v9 + v6 + mitamaparam->m_Items[type];
}

// 0x11b4150
s32 GetNakamaMax(void) {
  return LODWORD(ZensyoDevilID->max_length) - 1;
}

// 0x11afb00
s32 GetPriceForSummon(s32 id, s32 exp, s32 level, s32 str, s32 mgc, s32 pow, s32 spd, s32 luk) {
  return 100 * ((mgc + str + pow + spd + luk) * (mgc + str + pow + spd + luk) / 0x14u);
}

// 0x119c460
s32 GetValidUnitIndex(u8 **pindex) {
  struct datUnitWork_t_array *unitwork;
  u32 v5;
  s32 v6;
  s64 v7;
  u64 v8;
  s64 v10;
  s32 v11;
  _BOOL4 IsDLC;
  s32 v17;
  s32 v20;
  datUnitWork_t_o *v22;
  struct fclencyceelem_t_array *pelem;
  s64 v26;

  unitwork = DDS3_GBWK->unitwork;
  v5 = 0;
  v6 = 0;
  v7 = 8;
  do
  {
    v8 = v7 - 4;
    v10 = *(&unitwork->obj.klass + v7);
    v11 = *(v10 + 16);
    if ((v11 & 1) != 0)
    {
      if ((v11 & 0x10) == 0)
      {
        if ((*(v10 + 31) & 8) == 0)
        {
          if (*(v10 + 20) == 192)
          {
            IsDLC = IsDLC();
            if (v8 >= LODWORD(unitwork->max_length))
            {
LABEL_25:
            }
          }
          else
          {
            IsDLC = 0;
            if (v8 >= LODWORD(unitwork->max_length))
              goto LABEL_25;
          }
          v17 = *(*(&unitwork->obj.klass + v7) + 20LL);
          v20 = fclEncycSearch(v17 - IsDLC);
          v22 = *(&unitwork->obj.klass + v7);
          pelem = DDS3_GBWK->encyc_record->pelem;
          if (CompareUnitToRecord(v22, pelem->m_Items[v20]))
          {
            ++v6;
            if (!pindex)
              return v6;
            v26 = v5;
            ++v5;
            pindex->m_Items[v26] = v8;
          }
        }
      }
    }
    ++v7;
  }
  while ((v7 - 5) < 0xF);
  return v6;
}

// 0x11ac670
u32 GetViewModeKey(fclEncyc_instance_tag *pinst) {
  s32 AnalogPad;
  struct System_Byte_array_array_array *dds3PadAnalog;
  System_Byte_array_array *v7;
  System_Byte_array *v8;
  struct System_Byte_array_array_array *v9;
  s32 v10;
  System_Byte_array_array *v11;
  System_Byte_array *v12;
  s32 viewkeytype;
  s32 v14;
  u32 v16;
  s16 v18;
  s32 v19;
  u32 v23;
  s32 v28;
  s16 v30;
  s32 v31;
  u32 v36;
  s32 v46;
  bool v48;
  s16 v51;
  s32 v52;

  AnalogPad = GetAnalogPad();
  if (!LODWORD(dds3PadAnalog->max_length))
    goto LABEL_41;
LABEL_9:
  v7 = dds3PadAnalog->m_Items[0];
  v8 = v7->m_Items[0];
  v9 = dds3PadAnalog;
  v10 = v8->m_Items[0];
  v11 = v9->m_Items[0];
  v12 = v11->m_Items[0];
  viewkeytype = pinst->viewkeytype;
  if (viewkeytype == 2)
  {
    v23 = 1;
    if (!DDS3_PADCHECK_TRIG(1))
    {
      if ((ANALOG_L_LEFT & AnalogPad) != 0)
      {
        return 32;
      }
      else
      {
        if ((ANALOG_L_RIGHT & AnalogPad) != 0)
        {
          return 64;
        }
        else
        {
          if ((ANALOG_L_UP & AnalogPad) != 0)
          {
            return 128;
          }
          else
          {
            if ((ANALOG_L_DOWN & AnalogPad) != 0)
            {
              return 256;
            }
            else
            {
              if ((ANALOG_R_LEFT & AnalogPad) != 0)
              {
                return 2;
              }
              else
              {
                if ((ANALOG_R_RIGHT & AnalogPad) != 0)
                {
                  return 4;
                }
                else
                {
                  if ((ANALOG_R_UP & AnalogPad) != 0)
                  {
                    return 8;
                  }
                  else
                  {
                    if ((ANALOG_R_DOWN & AnalogPad) != 0)
                    {
                      return 16;
                    }
                    else
                    {
                      {
                      }
                      if (DDS3_PADCHECK_PRESS2(6))
                      {
                        return 512;
                      }
                      else
                      {
                        {
                        }
                        if (DDS3_PADCHECK_PRESS2(7))
                          return 1024;
                        else
                          return 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return v23;
  }
  v14 = v12->m_Items[1];
  if (viewkeytype == 1)
  {
    v28 = DDS3_PADCHECK_TRIG(1);
    if ((v30 & 0x200) != 0)
    {
      v31 = v30 & 0x200;
    }
    else
    {
      v31 = 0;
    }
    if ((ANALOG_L_LEFT & AnalogPad) != 0)
      v28 |= 2u;
    if ((ANALOG_L_RIGHT & AnalogPad) != 0)
      v28 |= 4u;
    if ((ANALOG_L_UP & AnalogPad) != 0)
      v28 |= 8u;
    if ((ANALOG_L_DOWN & AnalogPad) != 0)
      v28 |= 0x10u;
    if (((v10 == 128) & DDS3_PADCHECK_PRESS2(4)) != 0)
      v28 |= 0x20u;
    if (((v10 == 128) & DDS3_PADCHECK_PRESS2(5)) != 0)
      v46 = v28 | 0x40;
    else
      v46 = v28;
    if (((v14 == 128) & DDS3_PADCHECK_PRESS2(6)) != 0)
      v46 |= 0x80u;
    v48 = ((v14 == 128) & DDS3_PADCHECK_PRESS2(7)) == 0;
    if (v48)
      v23 = v46;
    else
      v23 = v46 | 0x100;
    if ((v51 & 0x200) != 0)
    {
      v52 = v51 & 0x200;
    }
    else
    {
      v52 = 0;
    }
    if ((ANALOG_R_UP & AnalogPad) != 0)
      v23 |= 0x200u;
    if ((ANALOG_R_DOWN & AnalogPad) != 0)
      v23 |= 0x400u;
    return v23;
  }
  if (viewkeytype)
    return 0;
  v16 = DDS3_PADCHECK_TRIG(1);
  if ((v18 & 0x200) != 0)
  {
    v19 = v18 & 0x200;
  }
  else
  {
    v19 = 0;
  }
  if ((ANALOG_L_LEFT & AnalogPad) != 0)
    v16 |= 2u;
  if ((ANALOG_L_RIGHT & AnalogPad) != 0)
    v16 |= 4u;
  if ((ANALOG_L_UP & AnalogPad) != 0)
    v16 |= 8u;
  if ((ANALOG_L_DOWN & AnalogPad) != 0)
    v36 = v16 | 0x10;
  else
    v36 = v16;
  if (((v10 == 128) & DDS3_PADCHECK_PRESS2(4)) != 0)
    v36 |= 0x20u;
  if (((v10 == 128) & DDS3_PADCHECK_PRESS2(5)) != 0)
    v36 |= 0x40u;
  if (((v14 == 128) & DDS3_PADCHECK_PRESS2(6)) != 0)
    v36 |= 0x80u;
  if (((v14 == 128) & DDS3_PADCHECK_PRESS2(7)) != 0)
    v36 |= 0x100u;
  if (DDS3_PADCHECK_PRESS2(9))
    v36 |= 0x200u;
  if (DDS3_PADCHECK_PRESS2(11))
    return v36 | 0x400;
  else
    return v36;
}

// 0x11a7480
void InitCameraForViewMode(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct fclencyceelem_t_array *pelem;
  u16 id;
  f32 v15;
  f32 v16;
  struct UnityEngine_Vector4_o *p_pos_camera_target;
  System_Single_array *v19[3];
  System_Single_array *pPos;

  pPos = 0;
  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v19);
      if ((v19[0] & 1) != 0)
        v6 = v19[2];
      else
        v6 = v19 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pPos = NewSpecific(f32, 3u);
  pelem = DDS3_GBWK->encyc_record->pelem;
  id = pelem->m_Items[SLOWORD(pwork[1].klass)]->id;
  cmpModelTblGetPos(id, &pPos);
  ResetCameraPos(pinst);
  v15 = pPos->m_Items[2];
  sub_854710(&pinst->fields, 2u);
  *&pwork[3].monitor = v15 - v16;
  p_pos_camera_target = &pinst->pos_camera_target;
  sub_854710(&cmpCameraTargetPos, 0);
  sub_854930(p_pos_camera_target, 0);
  sub_854710(&cmpCameraTargetPos, 1u);
  sub_854930(p_pos_camera_target, 1u);
  sub_854930(p_pos_camera_target, 2u);
  HIDWORD(pwork[3].monitor) = 0;
}

// 0x119c730
void InitListWindow(lstListWindow_t *plistwin, fclPanel_t *ppanel, sdfIVector4_t *pos, sdfIVector4_t *cur, sdfIVector4_t *pnl, s32 row, s32 disprow, s32 curstep) {
  u8 v10;
  struct System_Int32_array *pm;
  s32 v17;
  s32 v18;
  struct System_Int32_array *v19;
  s32 v20;
  s32 v22;
  struct System_Int32_array *v23;
  u32 max_length;
  struct System_Int32_array *v28;
  cmpCursorInfo_t_o *CursorInfo;
  u32 v30;
  s32 v31;
  s32 v32;
  s32 v33;
  s32 v35;
  struct System_Int32_array *v36;
  s32 v38;
  struct System_Int32_array *v39;
  s32 v40;
  s32 v42;
  struct System_Int32_array *v43;
  u32 v44;
  u8 ShiftMax;

  v10 = row;
  ShiftMax = disprow;
  pm = pos->pm;
  v17 = pm->m_Items[0];
  v18 = CMP_XM(v17);
  v19 = pos->pm;
  v20 = v18;
  v22 = CMP_YM(v19->m_Items[1]);
  v23 = pos->pm;
  max_length = v23->max_length;
  lstInitListWindow(v20, v22, 0xFFFFF0u, v23->m_Items[2], pos->pm->m_Items[3], 0x80808080, 0, plistwin);
  v28 = cur->pm;
  CursorInfo = plistwin->CursorInfo;
  v30 = v28->max_length;
  v31 = v28->m_Items[0];
  v32 = v28->m_Items[1];
  v33 = v28->m_Items[2];
  v35 = v28->m_Items[3];
  cmpInitCursorSize(CursorInfo, v31, v32, v33, v35, curstep);
  cmpInitCursorInfo(plistwin->CursorInfo, v10, ShiftMax, 0);
  v36 = pnl->pm;
  v38 = CMP_XM(v36->m_Items[0]);
  v39 = pnl->pm;
  v40 = v38;
  v42 = CMP_YM(v39->m_Items[1]);
  v43 = pnl->pm;
  v44 = v43->max_length;
  fclInitPanel(ppanel, v40, v42, 0xFFFFFu, v43->m_Items[2], pnl->pm->m_Items[3], 0x80808080, 0, 16);
  fclSetPanelFlag(plistwin->Panel, 0x10000u);
}

// 0x11add80
void InitModelPosRot(dds3ModelHandle_t *model, s32 id) {
  u16 v3;
  UnityEngine_Object_o *cmpMdlObj;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v12;
  u32 max_length;
  UnityEngine_Transform_o *v14;
  f32 v15;
  f32 v16;
  f32 v18;
  UnityEngine_Object_o *v20;
  UnityEngine_Transform_o *v23;
  UnityEngine_Component_o *v24;
  UnityEngine_GameObject_o *v25;
  u32 v27;
  f32 x;
  UnityEngine_GameObject_o *v29;
  f32 v30;
  f32 y;
  f32 v33;
  f32 v35;
  f32 v36;
  f32 v37;
  UnityEngine_Transform_o *v39;
  UnityEngine_Vector3_o v43;
  System_Single_array *pPos;
  UnityEngine_Quaternion_o v45;

  v3 = id;
  pPos = NewSpecific(f32, 3u);
  cmpModelTblGetPos(v3, &pPos);
  if (op_Inequality(cmpMdlObj, 0, 0))
  {
    transform = get_transform(cmpMdlObj, 0);
    Child = GetChild(transform, 0);
    gameObject = get_gameObject(Child);
    v12 = get_transform(gameObject, 0);
    max_length = pPos->max_length;
    v14 = v12;
    v15 = pPos->m_Items[0];
    v16 = pPos->m_Items[1];
    v18 = pPos->m_Items[2];
    v43.z = 0.0;
    *&v43.x = 0;
    sub_8524C0(&v43.x, v15 / 100.0, v16 / -100.0, v18 / 100.0);
    set_localPosition(v14, v43);
  }
  cmpModelTblGetRot(v3, &pPos);
  v20 = cmpMdlObj;
  if (op_Inequality(v20, 0, 0))
  {
    v23 = get_transform(cmpMdlObj, 0);
    v24 = GetChild(v23, 0);
    v25 = get_gameObject(v24);
    v27 = pPos->max_length;
    x = cmpDevilRot.x;
    v29 = v25;
    v30 = pPos->m_Items[0];
    y = cmpDevilRot.y;
    v33 = fmodf(pPos->m_Items[1] + 180.0, 360.0);
    v35 = x + v30;
    v36 = y + v33;
    v37 = cmpDevilRot.z + pPos->m_Items[2];
    v39 = get_transform(v29, 0);
    v45 = Euler(v35, v36, v37);
    set_localRotation(v39, v45);
  }
}

// 0x11a4aa0
void InitPhaseReadStatus(fclEncyc_instance_tag *pinst) {
  sdfIVector4_t_o *v3;
  sdfIVector4_t_o *v4;
  sdfIVector4_t_o *v5;
  sdfIVector4_t_o *v6;
  u64 *v9;
  _BOOL4 StatusBack;
  u64 v13;
  s64 typeHierarchyDepth;
  u64 *v15;
  char *v16;
  s64 *v17;
  u64 v18;
  s64 v19;
  char *v20;
  s64 *v21;
  s32 v22;
  u64 v23;
  s64 v24;
  s32 v25;
  s64 v27;
  s32 v28;
  s64 v30;
  s32 v31;
  s64 v33;
  s32 v35;
  struct System_Int32_array *stack;
  s32 v41;
  struct sdfTexHandle_t_array *texhandle;
  u32 max_length;
  sdfTexHandle_t_o *v46;
  struct System_Int32_array *pm;
  struct System_Int32_array *v50;
  struct System_Int32_array *v52;
  struct System_Int32_array *v54;
  struct System_Int32_array *v56;
  struct System_Int32_array *v58;
  struct System_Int32_array *v60;
  struct System_Int32_array *v62;
  struct System_Int32_array *v64;
  struct System_Int32_array *v66;
  struct System_Int32_array *v68;
  struct System_Int32_array *v70;
  struct System_Int32_array *v72;
  struct System_Int32_array *v74;
  struct System_Int32_array *v76;
  struct System_Int32_array *v78;
  struct sdfTexHandle_t_array *v80;
  struct System_Int32_array *v82;
  struct System_Int32_array *v84;
  struct System_Int32_array *v86;
  struct System_Int32_array *v88;
  struct System_Int32_array *v90;
  struct System_Int32_array *v92;
  struct System_Int32_array *v94;
  struct System_Int32_array *v96;
  struct System_Int32_array *v98;
  struct System_Int32_array *v100;
  struct System_Int32_array *v102;
  struct System_Int32_array *v104;
  struct System_Int32_array *v106;
  struct System_Int32_array *v108;
  struct System_Int32_array *v110;
  struct System_Int32_array *v112;
  struct sdfTexHandle_t_array *v114;
  struct System_Int32_array *v116;
  struct System_Int32_array *v118;
  struct System_Int32_array *v120;
  struct System_Int32_array *v122;
  struct System_Int32_array *v124;
  struct System_Int32_array *v126;
  struct System_Int32_array *v128;
  struct System_Int32_array *v130;
  struct System_Int32_array *v132;
  struct System_Int32_array *v134;
  struct System_Int32_array *v136;
  struct System_Int32_array *v138;
  struct System_Int32_array *v140;
  struct System_Int32_array *v142;
  struct System_Int32_array *v144;
  struct System_Int32_array *v146;
  struct sdfTexHandle_t_array *v148;
  dds3Basic_t_o *basic;
  u64 v155[2];
  char *v156;

  basic = 0;
  v3 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v3);
  v4 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v4);
  v5 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v5);
  v6 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v6);
  CMB_GBWK->bReadPhase = 1;
  v9 = Allocate(fclEncyc_readmainwork_tag);
  _ctor(v9, 0);
  StatusBack = pinst->StatusBack;
  pinst->pwork = v9;
  if (v9)
  {
    v13 = *v9;
    if (*(*v9 + 288) < typeHierarchyDepth
      || (v15 = v9, *(*(v13 + 200) + 8 * typeHierarchyDepth - 8) != fclEncyc_readmainwork_tag))
    {
      sub_8FC2C0(*(v13 + 64), fclEncyc_readmainwork_tag, v155);
      if ((v155[0] & 1) != 0)
        v16 = v156;
      else
        v16 = v155 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  else
  {
    v15 = 0;
  }
  if (StatusBack)
  {
    StatusFrontProcess(pinst, 1);
  }
  else if (v9)
  {
    v18 = *v9;
    if (*(*v9 + 288) < v19 || (v15 = v9, *(*(v18 + 200) + 8 * v19 - 8) != fclEncyc_readmainwork_tag))
    {
      sub_8FC2C0(*(v18 + 64), fclEncyc_readmainwork_tag, v155);
      if ((v155[0] & 1) != 0)
        v20 = v156;
      else
        v20 = v155 + 1;
      v21 = sub_8C4940(v20);
    }
  }
  else
  {
    v15 = 0;
  }
  *(v15 + 9) = 0;
  *(v15 + 21) = 128;
  *(v15 + 50) = 0;
  v22 = CMP_YM(384);
  v23 = v15[13];
  *(v15 + 24) = v22;
  *(v15 + 51) = 0;
  v24 = *(v23 + 16);
  v25 = CMP_XM(0);
  *(v24 + 32) = v25;
  v27 = *(v15[13] + 16);
  v28 = CMP_YM(413);
  *(v27 + 36) = v28;
  v15[14] = 0x14000000000020LL;
  v30 = *(v15[15] + 16);
  v31 = CMP_XM(311);
  *(v30 + 32) = v31;
  v33 = *(v15[15] + 16);
  v35 = CMP_YM(420);
  *(v33 + 36) = v35;
  *(v15 + 66) = 0;
  *(v15 + 32) = 32;
  *(v15 + 6) = -1;
  v15[22] = 0;
  v15[23] = 0;
  basic = dds3GetActiveScene();
  if (basic)
  {
    dds3VisibleSceneBasic(&basic, 0);
  }
  stack = pinst->stack;
  v41 = stack->m_Items[0];
  ChangeDevilObjectReadMain(v41, pinst);
  ResetReadMainRibbon(v15);
  texhandle = pinst->texhandle;
  max_length = texhandle->max_length;
  v46 = texhandle->m_Items[2];
  v15[17] = fclRbnInit(3, 1, v46, pinst->texhandle->m_Items[3]);
  pm = v3->pm;
  pm->m_Items[0] = 2064;
  v50 = v3->pm;
  v50->m_Items[1] = 16;
  v52 = v3->pm;
  v52->m_Items[2] = 2896;
  v54 = v3->pm;
  v54->m_Items[3] = 264;
  v56 = v4->pm;
  v56->m_Items[0] = 2128;
  v58 = v4->pm;
  v58->m_Items[1] = 64;
  v60 = v4->pm;
  v60->m_Items[2] = 2832;
  v62 = v4->pm;
  v62->m_Items[3] = 224;
  v64 = v5->pm;
  v64->m_Items[0] = 3248;
  v66 = v5->pm;
  v66->m_Items[1] = 352;
  v68 = v5->pm;
  v68->m_Items[2] = 4080;
  v70 = v5->pm;
  v70->m_Items[3] = 848;
  v72 = v6->pm;
  v72->m_Items[0] = 3056;
  v74 = v6->pm;
  v74->m_Items[1] = 16;
  v76 = v6->pm;
  v76->m_Items[2] = 3760;
  v78 = v6->pm;
  v78->m_Items[3] = 336;
  v80 = pinst->texhandle;
  fclRbnSetPara(v15[17], 0, v3, v4, v5, v6, v80->m_Items[3], v80->m_Items[3]);
  v82 = v3->pm;
  v82->m_Items[0] = 3504;
  v84 = v3->pm;
  v84->m_Items[1] = 16;
  v86 = v3->pm;
  v86->m_Items[2] = 4720;
  v88 = v3->pm;
  v88->m_Items[3] = 264;
  v90 = v4->pm;
  v90->m_Items[0] = 3584;
  v92 = v4->pm;
  v92->m_Items[1] = 64;
  v94 = v4->pm;
  v94->m_Items[2] = 4640;
  v96 = v4->pm;
  v96->m_Items[3] = 224;
  v98 = v5->pm;
  v98->m_Items[0] = 1376;
  v100 = v5->pm;
  v100->m_Items[1] = 864;
  v102 = v5->pm;
  v102->m_Items[2] = 2592;
  v104 = v5->pm;
  v104->m_Items[3] = 1360;
  v106 = v6->pm;
  v106->m_Items[0] = 2176;
  v108 = v6->pm;
  v108->m_Items[1] = 352;
  v110 = v6->pm;
  v110->m_Items[2] = 3232;
  v112 = v6->pm;
  v112->m_Items[3] = 672;
  v114 = pinst->texhandle;
  fclRbnSetPara(v15[17], 1, v3, v4, v5, v6, v114->m_Items[3], v114->m_Items[3]);
  v116 = v3->pm;
  v116->m_Items[0] = 4992;
  v118 = v3->pm;
  v118->m_Items[1] = 16;
  v120 = v3->pm;
  v120->m_Items[2] = 6464;
  v122 = v3->pm;
  v122->m_Items[3] = 264;
  v124 = v4->pm;
  v124->m_Items[0] = 5056;
  v126 = v4->pm;
  v126->m_Items[1] = 64;
  v128 = v4->pm;
  v128->m_Items[2] = 6400;
  v130 = v4->pm;
  v130->m_Items[3] = 224;
  v132 = v5->pm;
  v132->m_Items[0] = 2608;
  v134 = v5->pm;
  v134->m_Items[1] = 864;
  v136 = v5->pm;
  v136->m_Items[2] = 4080;
  v138 = v5->pm;
  v138->m_Items[3] = 1360;
  v140 = v6->pm;
  v140->m_Items[0] = 16;
  v142 = v6->pm;
  v142->m_Items[1] = 864;
  v144 = v6->pm;
  v144->m_Items[2] = 1360;
  v146 = v6->pm;
  v146->m_Items[3] = 1184;
  v148 = pinst->texhandle;
  fclRbnSetPara(v15[17], 2, v3, v4, v5, v6, v148->m_Items[3], v148->m_Items[3]);
  *&pinst->screen_ofsx = 0x450000004508C000LL;
  pinst->stat &= ~8u;
  RegistModePanel(_statusUIScr, menuReadPhase);
  *(v15 + 9) = *(v15 + 9) & 0xFFAF | 0x10;
  SetButtonGuide(-1, 0);
}

// 0x11a1a10
void InitPhaseReadTop(fclEncyc_instance_tag *pinst) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  sdfIVector4_t_o *v6;
  sdfIVector4_t_o *v7;
  sdfIVector4_t_o *v8;
  sdfIVector4_t_o *v9;
  fclEncyc_readtopwork_tag_o *v13;
  fclEncyc_readtopwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  struct System_Int32_array *pm;
  struct System_Int32_array *v20;
  struct System_Int32_array *v22;
  struct System_Int32_array *v24;
  struct System_Int32_array *v26;
  struct System_Int32_array *v28;
  struct System_Int32_array *v30;
  struct System_Int32_array *v32;
  struct System_Int32_array *v34;
  struct System_Int32_array *v36;
  struct System_Int32_array *v38;
  struct System_Int32_array *v40;
  struct System_Int32_array *v42;
  struct System_Int32_array *v44;
  struct System_Int32_array *v46;
  struct System_Int32_array *v48;
  struct sdfTexHandle_t_array *texhandle;
  struct System_Int32_array *v52;
  struct System_Int32_array *v54;
  struct System_Int32_array *v56;
  struct System_Int32_array *v58;
  struct System_Int32_array *v60;
  struct System_Int32_array *v62;
  struct System_Int32_array *v64;
  struct System_Int32_array *v66;
  struct System_Int32_array *v68;
  struct System_Int32_array *v70;
  struct System_Int32_array *v72;
  struct System_Int32_array *v74;
  struct System_Int32_array *v76;
  struct System_Int32_array *v78;
  struct System_Int32_array *v80;
  struct System_Int32_array *v82;
  struct sdfTexHandle_t_array *v84;
  struct _FRQ_array *ppfont;
  struct _FRQ_array *v88;
  struct _FRQ_array *v90;
  struct _FRQ_array *v92;
  struct _FRQ_array *v94;
  struct _FRQ_array *v96;
  struct _FRQ_array *v98;
  struct _FRQ_array *v100;
  struct _FRQ_array *v102;
  sdfIVector4_t_o *v104;
  sdfIVector4_t_o *v105;
  sdfIVector4_t_o *v107;
  fclPanel_t_o *panel;
  lstListWindow_t_o *listwin;
  s32 NumForDLC;
  s32 sort;
  s64 v116;
  System_Int16_array *v117;
  MethodInfo *methoda;
  u64 v124[3];

  v3 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v3);
  v4 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v4);
  v5 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v5);
  v6 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v6);
  v7 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v7);
  v8 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v8);
  v9 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v9);
  CMB_GBWK->bReadPhase = 1;
  WindowDispOff(0);
  if (pinst->StatusBack)
  {
    StatusBackProcess(pinst);
  }
  v13 = Allocate(fclEncyc_readtopwork_tag);
  _ctor(v13, 0);
  pinst->pwork = v13;
  if (v13)
  {
    klass = v13->klass;
    if (v13->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readtopwork_tag, v124);
      if ((v124[0] & 1) != 0)
        v16 = v124[2];
      else
        v16 = v124 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  v13->pribbon = fclRbnInitSort(pinst->sort);
  pm = v6->pm;
  pm->m_Items[0] = 2432;
  v20 = v6->pm;
  v20->m_Items[1] = 24;
  v22 = v6->pm;
  v22->m_Items[2] = 3376;
  v24 = v6->pm;
  v24->m_Items[3] = 272;
  v26 = v7->pm;
  v26->m_Items[0] = 2528;
  v28 = v7->pm;
  v28->m_Items[1] = 72;
  v30 = v7->pm;
  v30->m_Items[2] = 3264;
  v32 = v7->pm;
  v32->m_Items[3] = 232;
  v34 = v8->pm;
  v34->m_Items[0] = 16;
  v36 = v8->pm;
  v36->m_Items[1] = 352;
  v38 = v8->pm;
  v38->m_Items[2] = 960;
  v40 = v8->pm;
  v40->m_Items[3] = 848;
  v42 = v9->pm;
  v42->m_Items[0] = 16;
  v44 = v9->pm;
  v44->m_Items[1] = 16;
  v46 = v9->pm;
  v46->m_Items[2] = 752;
  v48 = v9->pm;
  v48->m_Items[3] = 336;
  texhandle = pinst->texhandle;
  fclRbnSetPara(v13->pribbon, 0, v6, v7, v8, v9, texhandle->m_Items[3], texhandle->m_Items[3]);
  v52 = v6->pm;
  v52->m_Items[0] = 4704;
  v54 = v6->pm;
  v54->m_Items[1] = 24;
  v56 = v6->pm;
  v56->m_Items[2] = 5888;
  v58 = v6->pm;
  v58->m_Items[3] = 272;
  v60 = v7->pm;
  v60->m_Items[0] = 4832;
  v62 = v7->pm;
  v62->m_Items[1] = 72;
  v64 = v7->pm;
  v64->m_Items[2] = 5776;
  v66 = v7->pm;
  v66->m_Items[3] = 232;
  v68 = v8->pm;
  v68->m_Items[0] = 976;
  v70 = v8->pm;
  v70->m_Items[1] = 352;
  v72 = v8->pm;
  v72->m_Items[2] = 2160;
  v74 = v8->pm;
  v74->m_Items[3] = 848;
  v76 = v9->pm;
  v76->m_Items[0] = 768;
  v78 = v9->pm;
  v78->m_Items[1] = 16;
  v80 = v9->pm;
  v80->m_Items[2] = 1712;
  v82 = v9->pm;
  v82->m_Items[3] = 336;
  v84 = pinst->texhandle;
  fclRbnSetPara(v13->pribbon, 1, v6, v7, v8, v9, v84->m_Items[3], v84->m_Items[3]);
  ppfont = v13->ppfont;
  ppfont->m_Items[0] = 0;
  v88 = v13->ppfont;
  v88->m_Items[1] = 0;
  v90 = v13->ppfont;
  v90->m_Items[2] = 0;
  v92 = v13->ppfont;
  v92->m_Items[3] = 0;
  v94 = v13->ppfont;
  v94->m_Items[4] = 0;
  v96 = v13->ppfont;
  v96->m_Items[5] = 0;
  v98 = v13->ppfont;
  v98->m_Items[6] = 0;
  v100 = v13->ppfont;
  v100->m_Items[7] = 0;
  v102 = v13->ppfont;
  v102->m_Items[8] = 0;
  v104 = sdfIVector4_t__Create(24, 136, 464, 237);
  v105 = sdfIVector4_t__Create(70, 11, 349, 21);
  v107 = sdfIVector4_t__Create(0, 104, 512, 307);
  listwin = v13->listwin;
  panel = v13->panel;
  NumForDLC = fclEncycGetNumForDLC();
  InitListWindow(listwin, panel, v104, v105, v107, NumForDLC, 9, 28, methoda);
  PopListwinCursor(pinst, v13->listwin, 1);
  sort = pinst->sort;
  v116 = 128;
  if (!pinst->sort)
    v116 = 120;
  v117 = *(&pinst->klass + v116);
  CreateFontListRead(v13, sort, v117);
  *&pinst->screen_ofsx = 0x4500000045000000LL;
  draw_status_off(0);
  SetButtonGuide(15, 1);
  RemakeFldSky();
  DrawSummonMoneyReset(pinst);
  CMB_GBWK->bUnlock = 1;
}

// 0x119e960
void InitPhaseRegistConfirm(fclEncyc_instance_tag *pinst) {
  sdfIVector4_t_o *v3;
  sdfIVector4_t_o *v4;
  sdfIVector4_t_o *v5;
  sdfIVector4_t_o *v6;
  u64 *v7;
  _BOOL4 StatusBack;
  u64 v11;
  s64 typeHierarchyDepth;
  u64 *v13;
  char *v14;
  s64 *v15;
  u64 v16;
  s64 v17;
  char *v18;
  s64 *v19;
  s64 v21;
  s32 v22;
  s64 v24;
  s32 v26;
  struct System_Int32_array *stack;
  s32 v32;
  struct sdfTexHandle_t_array *texhandle;
  u32 max_length;
  sdfTexHandle_t_o *v36;
  struct System_Int32_array *pm;
  s32 v40;
  struct System_Int32_array *v42;
  s32 v43;
  struct System_Int32_array *v45;
  s32 v46;
  struct System_Int32_array *v48;
  s32 v49;
  struct System_Int32_array *v51;
  s32 v52;
  struct System_Int32_array *v54;
  s32 v55;
  struct System_Int32_array *v57;
  s32 v58;
  struct System_Int32_array *v60;
  s32 v61;
  struct System_Int32_array *v63;
  s32 v64;
  struct System_Int32_array *v66;
  s32 v67;
  struct System_Int32_array *v69;
  s32 v70;
  struct System_Int32_array *v72;
  s32 v73;
  struct System_Int32_array *v75;
  s32 v76;
  struct System_Int32_array *v78;
  s32 v79;
  struct System_Int32_array *v81;
  s32 v82;
  struct System_Int32_array *v84;
  s32 v85;
  struct sdfTexHandle_t_array *v87;
  struct System_Int32_array *v89;
  s32 v90;
  struct System_Int32_array *v92;
  s32 v93;
  struct System_Int32_array *v95;
  s32 v96;
  struct System_Int32_array *v98;
  s32 v99;
  struct System_Int32_array *v101;
  s32 v102;
  struct System_Int32_array *v104;
  s32 v105;
  struct System_Int32_array *v107;
  s32 v108;
  struct System_Int32_array *v110;
  s32 v111;
  struct System_Int32_array *v113;
  s32 v114;
  struct System_Int32_array *v116;
  s32 v117;
  struct System_Int32_array *v119;
  s32 v120;
  struct System_Int32_array *v122;
  s32 v123;
  struct System_Int32_array *v125;
  s32 v126;
  struct System_Int32_array *v128;
  s32 v129;
  struct System_Int32_array *v131;
  s32 v132;
  struct System_Int32_array *v134;
  s32 v135;
  struct sdfTexHandle_t_array *v137;
  dds3Basic_t_o *basic;
  u64 v147[2];
  char *v148;

  basic = 0;
  v3 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v3);
  v4 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v4);
  v5 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v5);
  v6 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v6);
  v7 = Allocate(fclEncyc_registconfirmwork_tag);
  _ctor(v7, 0);
  StatusBack = pinst->StatusBack;
  pinst->pwork = v7;
  if (v7)
  {
    v11 = *v7;
    if (*(*v7 + 288) < typeHierarchyDepth
      || (v13 = v7, *(*(v11 + 200) + 8 * typeHierarchyDepth - 8) != fclEncyc_registconfirmwork_tag))
    {
      sub_8FC2C0(*(v11 + 64), fclEncyc_registconfirmwork_tag, v147);
      if ((v147[0] & 1) != 0)
        v14 = v148;
      else
        v14 = v147 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  else
  {
    v13 = 0;
  }
  if (StatusBack)
  {
    StatusFrontProcess(pinst, 0);
  }
  else if (v7)
  {
    v16 = *v7;
    if (*(*v7 + 288) < v17 || (v13 = v7, *(*(v16 + 200) + 8 * v17 - 8) != fclEncyc_registconfirmwork_tag))
    {
      sub_8FC2C0(*(v16 + 64), fclEncyc_registconfirmwork_tag, v147);
      if ((v147[0] & 1) != 0)
        v18 = v148;
      else
        v18 = v147 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  else
  {
    v13 = 0;
  }
  *(v13 + 16) = 0;
  CMB_GBWK->bReadPhase = 0;
  *(v13 + 20) = 192;
  *(v13 + 28) = 0xB400000000LL;
  *(v13 + 17) = 0;
  *(v13 + 9) = 40;
  v21 = *(v13[5] + 16);
  v22 = CMP_XM(311);
  *(v21 + 32) = v22;
  v24 = *(v13[5] + 16);
  v26 = CMP_YM(420);
  *(v24 + 36) = v26;
  *(v13 + 26) = 0;
  *(v13 + 12) = 32;
  *(v13 + 54) = 1;
  v13[10] = 0;
  basic = dds3GetActiveScene();
  if (basic)
  {
    dds3VisibleSceneBasic(&basic, 0);
  }
  stack = pinst->stack;
  v32 = stack->m_Items[0];
  ChangeDevilObjectRegistConfirm(v32, pinst);
  texhandle = pinst->texhandle;
  max_length = texhandle->max_length;
  v36 = texhandle->m_Items[2];
  v13[9] = fclRbnInit(2, 1, v36, pinst->texhandle->m_Items[3]);
  pm = v3->pm;
  v40 = CMP_XM(121);
  pm->m_Items[0] = v40;
  v42 = v3->pm;
  v43 = CMP_YM(3);
  v42->m_Items[1] = v43;
  v45 = v3->pm;
  v46 = CMP_XM(242);
  v45->m_Items[2] = v46;
  v48 = v3->pm;
  v49 = CMP_YM(32);
  v48->m_Items[3] = v49;
  v51 = v4->pm;
  v52 = CMP_XM(125);
  v51->m_Items[0] = v52;
  v54 = v4->pm;
  v55 = CMP_YM(8);
  v54->m_Items[1] = v55;
  v57 = v4->pm;
  v58 = CMP_XM(238);
  v57->m_Items[2] = v58;
  v60 = v4->pm;
  v61 = CMP_YM(28);
  v60->m_Items[3] = v61;
  v63 = v5->pm;
  v64 = CMP_XM(1);
  v63->m_Items[0] = v64;
  v66 = v5->pm;
  v67 = CMP_XM(33);
  v66->m_Items[1] = v67;
  v69 = v5->pm;
  v70 = CMP_XM(122);
  v69->m_Items[2] = v70;
  v72 = v5->pm;
  v73 = CMP_XM(62);
  v72->m_Items[3] = v73;
  v75 = v6->pm;
  v76 = CMP_XM(1);
  v75->m_Items[0] = v76;
  v78 = v6->pm;
  v79 = CMP_XM(63);
  v78->m_Items[1] = v79;
  v81 = v6->pm;
  v82 = CMP_XM(114);
  v81->m_Items[2] = v82;
  v84 = v6->pm;
  v85 = CMP_XM(83);
  v84->m_Items[3] = v85;
  v87 = pinst->texhandle;
  fclRbnSetPara(v13[9], 0, v3, v4, v5, v6, v87->m_Items[4], v87->m_Items[4]);
  v89 = v3->pm;
  v90 = CMP_XM(268);
  v89->m_Items[0] = v90;
  v92 = v3->pm;
  v93 = CMP_YM(3);
  v92->m_Items[1] = v93;
  v95 = v3->pm;
  v96 = CMP_XM(395);
  v95->m_Items[2] = v96;
  v98 = v3->pm;
  v99 = CMP_YM(32);
  v98->m_Items[3] = v99;
  v101 = v4->pm;
  v102 = CMP_XM(271);
  v101->m_Items[0] = v102;
  v104 = v4->pm;
  v105 = CMP_YM(8);
  v104->m_Items[1] = v105;
  v107 = v4->pm;
  v108 = CMP_XM(392);
  v107->m_Items[2] = v108;
  v110 = v4->pm;
  v111 = CMP_YM(28);
  v110->m_Items[3] = v111;
  v113 = v5->pm;
  v114 = CMP_XM(123);
  v113->m_Items[0] = v114;
  v116 = v5->pm;
  v117 = CMP_XM(33);
  v116->m_Items[1] = v117;
  v119 = v5->pm;
  v120 = CMP_XM(250);
  v119->m_Items[2] = v120;
  v122 = v5->pm;
  v123 = CMP_XM(62);
  v122->m_Items[3] = v123;
  v125 = v6->pm;
  v126 = CMP_XM(115);
  v125->m_Items[0] = v126;
  v128 = v6->pm;
  v129 = CMP_XM(63);
  v128->m_Items[1] = v129;
  v131 = v6->pm;
  v132 = CMP_XM(236);
  v131->m_Items[2] = v132;
  v134 = v6->pm;
  v135 = CMP_XM(83);
  v134->m_Items[3] = v135;
  v137 = pinst->texhandle;
  fclRbnSetPara(v13[9], 1, v3, v4, v5, v6, v137->m_Items[4], v137->m_Items[4]);
  RegistModePanel(_statusUIScr, menuRegistPhase);
  DrawStatus1Shot(pinst);
  DrawPhaseRegistConfirm(pinst);
  *&pinst->screen_ofsx = 0x450000004508C000LL;
  DispRegistConfirm(1);
  *(v13 + 22) = 0;
  SetButtonGuide(13, 1);
}

// 0x119be10
void InitPhaseRegistTop(fclEncyc_instance_tag *pinst) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  System_Byte_array *pnakamaindex;
  fclEncyc_registtopwork_tag_o *v10;
  fclEncyc_registtopwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  sdfIVector4_t_o *v15;
  sdfIVector4_t_o *v16;
  sdfIVector4_t_o *v17;
  struct _FRQ_array *ppfont;
  struct _FRQ_array *v22;
  struct _FRQ_array *v24;
  struct _FRQ_array *v26;
  struct _FRQ_array *v28;
  struct _FRQ_array *v30;
  struct _FRQ_array *v32;
  struct _FRQ_array *v34;
  struct _FRQ_array *v36;
  struct _FRQ_array *v38;
  struct _FRQ_array *v40;
  struct _FRQ_array *v42;
  dds3ProcessID_t_o **p_scr_proc;
  u64 v50[3];

  v3 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v3);
  v4 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v4);
  v5 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v5);
  CMB_GBWK->bReadPhase = 0;
  WindowDispOff(0);
  if (pinst->StatusBack)
  {
    StatusBackProcess(pinst);
  }
  pnakamaindex = pinst->pnakamaindex;
  pinst->num_nakama = GetValidUnitIndex(pnakamaindex);
  v10 = Allocate(fclEncyc_registtopwork_tag);
  _ctor(v10, 0);
  pinst->pwork = v10;
  if (v10)
  {
    klass = v10->klass;
    if (v10->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_registtopwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_registtopwork_tag, v50);
      if ((v50[0] & 1) != 0)
        v13 = v50[2];
      else
        v13 = v50 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  v15 = sdfIVector4_t__Create(24, 84, 464, 209);
  v16 = sdfIVector4_t__Create(70, 11, 349, 21);
  v17 = sdfIVector4_t__Create(0, 49, 512, 260);
  InitListWindow(v10->listwin, v10->panel, v15, v16, v17, pinst->num_nakama, 12, 28);
  PopListwinCursor(pinst, v10->listwin, 0);
  ppfont = v10->ppfont;
  ppfont->m_Items[0] = 0;
  v22 = v10->ppfont;
  v22->m_Items[1] = 0;
  v24 = v10->ppfont;
  v24->m_Items[2] = 0;
  v26 = v10->ppfont;
  v26->m_Items[3] = 0;
  v28 = v10->ppfont;
  v28->m_Items[4] = 0;
  v30 = v10->ppfont;
  v30->m_Items[5] = 0;
  v32 = v10->ppfont;
  v32->m_Items[6] = 0;
  v34 = v10->ppfont;
  v34->m_Items[7] = 0;
  v36 = v10->ppfont;
  v36->m_Items[8] = 0;
  v38 = v10->ppfont;
  v38->m_Items[9] = 0;
  v40 = v10->ppfont;
  v40->m_Items[10] = 0;
  v42 = v10->ppfont;
  v42->m_Items[11] = 0;
  v10->ismsgend = 0;
  fclClearSignal(0);
  v10->scr_proc = 0;
  p_scr_proc = &v10->scr_proc;
  *p_scr_proc = fclScriptStart(CMB_GBWK->pScriptData, 15, p_scr_proc);
  *&pinst->screen_ofsx = 0x4500000045000000LL;
  draw_status_off(0);
  SetButtonGuide(-1, 0);
  RemakeFldSky();
}

// 0x11b3060
void InitializeDebug(void) {
  u64 *v1;

  v1 = Allocate(fclEncyc_debug_t);
  _ctor(v1, 0);
  v1[3] = 0;
  g_pdebug = v1;
}

// 0x119a340
void InitializeInstance(fclEncyc_instance_tag *pinst) {
  struct System_Int16_array *lw_cur;
  struct System_Int16_array *v5;
  struct System_Int16_array *v7;
  struct System_Int16_array *v9;

  lw_cur = pinst->lw_cur;
  *&pinst->stat = 0;
  lw_cur->m_Items[0] = 0;
  v5 = pinst->lw_cur;
  v5->m_Items[1] = 0;
  v7 = pinst->lw_cur;
  v7->m_Items[2] = 0;
  v9 = pinst->lw_cur;
  v9->m_Items[3] = 0;
  *&pinst->sort = 4294902016LL;
  pinst->pbmd = 0;
  pinst->ctr = 0;
  pinst->pwork = 0;
  *&pinst->screen_ofsx = 0x4500000045000000LL;
}

// 0x11a6850
void MoveScreenOffset(fclEncyc_instance_tag *pinst) {
  f32 v3;
  f32 v4;
  UnityEngine_Object_o *statusUIScr;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v11;
  f32 v12;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v14;

  if ((pinst->stat & 8) == 0)
  {
    v3 = pinst->screen_ofsx + 16.0;
    pinst->screen_ofsx = v3;
    if (v3 <= 2188.0)
      return;
    v4 = 2188.0;
    goto LABEL_24;
  }
  if (pinst->phase == 7)
  {
    statusUIScr = _statusUIScr;
    if (op_Inequality(statusUIScr, 0, 0))
    {
      transform = get_transform(_statusUIScr, 0);
      v11 = Find(transform, "statusChara", 0);
      if (op_Inequality(v11, 0, 0))
      {
        localPosition = get_localPosition(v11);
        v14.y = localPosition.y;
        v14.z = localPosition.z;
        v14.x = fmaxf(localPosition.x + -50.0, 960.0);
        set_localPosition(v11, v14);
      }
    }
  }
  v12 = pinst->screen_ofsx + -16.0;
  pinst->screen_ofsx = v12;
  if (v12 < 2048.0)
  {
    v4 = 2048.0;
LABEL_24:
    pinst->screen_ofsx = v4;
  }
}

// 0x119cab0
void PopListwinCursor(fclEncyc_instance_tag *pinst, lstListWindow_t *plistwin, s32 Stack) {
  struct System_Int16_array *lw_cur;
  u32 max_length;
  s32 v9;
  s64 v10;
  s64 v12;
  s16 v13;
  s32 v15;
  struct cmpCursorInfo_t_o *CursorInfo;
  struct cmpCursorSize_t_o *CursorSize;
  struct cmpCursorPos_t_o *CursorPos;

  lw_cur = pinst->lw_cur;
  max_length = lw_cur->max_length;
  v9 = 2 * Stack;
  v10 = 2 * Stack;
  v12 = v10 | 1;
  v13 = lw_cur->m_Items[v9];
  v15 = lw_cur->m_Items[v12];
  CursorInfo = plistwin->CursorInfo;
  CursorSize = CursorInfo->CursorSize;
  CursorPos = CursorInfo->CursorPos;
  CursorPos->Index = v13;
  CursorPos->Shift = v15;
  CursorPos->DrawShift = v15;
  CursorSize->Y = CursorSize->DefY + CursorInfo->StepY * v15;
}

// 0x11a6a70
s32 PrepSummon(fclEncyc_readmainwork_tag *pwork) {
  u64 *v3;
  struct fclencyceelem_t_array *pelem;
  fclencyceelem_t_o *v9;
  s32 DevilParam;
  s32 v12;
  s32 v14;
  s32 v16;
  u32 v20;
  s32 v21;
  u16 flags;
  s32 id;
  s32 v24;
  s32 v27;
  s32 v28;
  dds3ProcessID_t_o **p_scr_proc;
  Il2CppObject *ProcessData;
  Il2CppObject *v35;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v38;
  s64 *v39;
  s32 monitor_high;
  s32 v42;
  s32 level;
  struct datUnitWork_t_array *unitwork;
  s32 v48;
  u64 v50[3];

  v3 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v3);
  pelem = DDS3_GBWK->encyc_record->pelem;
  v9 = pelem->m_Items[pwork->recindex];
  DevilParam = GetDevilParam(v9, 0);
  v12 = GetDevilParam(v9, 2);
  v14 = GetDevilParam(v9, 3);
  v16 = GetDevilParam(v9, 4);
  v18 = GetDevilParam(v9, 5);
  v20 = (100 * ((v12 + DevilParam + v14 + v16 + v18) * (v12 + DevilParam + v14 + v16 + v18) / 0x14u)) >> (fclEncycGetRatio2() > 99);
  if (v9->id - 191 >= 2)
    v21 = v20;
  else
    v21 = 0;
  flags = pwork->flags;
  pwork->mak = v21;
  pwork->flags = flags & 0xFFFB;
  id = v9->id;
  if ((id - 191) <= 1)
  {
    v24 = 4;
LABEL_26:
    fclSetVal(8, v24);
    v27 = 0;
    pwork->flags |= 4u;
    goto LABEL_27;
  }
  else if ((datSearchDevilStock(id) & 0x80000000) == 0)
  {
    goto LABEL_22;
  }
  v42 = v9->id;
  if (v42 == 194)
  {
    if ((datSearchDevilStock(207) & 0x80000000) == 0)
      goto LABEL_22;
    v42 = v9->id;
  }
  if (v42 == 207)
  {
    if ((datSearchDevilStock(194) & 0x80000000) == 0)
    {
LABEL_22:
      v24 = 1;
      goto LABEL_26;
    }
  }
  if (datCheckStockFull())
  {
    v24 = 2;
    goto LABEL_26;
  }
  level = v9->level;
  unitwork = DDS3_GBWK->unitwork;
  v48 = unitwork->m_Items[0]->level;
  if (CheckLevelLimit(level, v48))
  {
    v24 = 3;
    goto LABEL_26;
  }
  if (v21 <= DDS3_GBWK->maka)
  {
    v28 = 17;
    v27 = 1;
    goto LABEL_28;
  }
  fclSetVal(8, 0);
  v27 = 0;
LABEL_27:
  v28 = 18;
LABEL_28:
  fclClearSignal(0);
  pwork->scr_proc = 0;
  p_scr_proc = &pwork->scr_proc;
  *p_scr_proc = fclScriptStart(CMB_GBWK->pScriptData, v28, p_scr_proc);
  ProcessData = dds3GetProcessData(p_scr_proc);
  v35 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != scrProcessWork_s)
    {
      sub_8FC2C0(klass->_1.element_class, scrProcessWork_s, v50);
      if ((v50[0] & 1) != 0)
        v38 = v50[2];
      else
        v38 = v50 + 1;
      v39 = sub_8C4940(v38);
    }
  }
  monitor_high = HIDWORD(ProcessData[8].monitor);
  itfMesMngSetVar(monitor_high, 0, v21, 0);
  itfMesMngSetVar(HIDWORD(v35[8].monitor), 1, v9->id, 1, 0);
  return v27;
}

// 0x119d840
void PushListwinCursor(fclEncyc_instance_tag *pinst, lstListWindow_t *plistwin, s32 Stack) {
  struct System_Int16_array *lw_cur;
  struct cmpCursorPos_t_o *CursorPos;
  s64 v6;
  struct System_Int16_array *v8;
  s16 Shift;

  lw_cur = pinst->lw_cur;
  CursorPos = plistwin->CursorInfo->CursorPos;
  v6 = 2 * Stack;
  lw_cur->m_Items[2 * Stack] = CursorPos->Index;
  v8 = pinst->lw_cur;
  Shift = CursorPos->Shift;
  v8->m_Items[v6 | 1] = Shift;
}

// 0x11a18d0
s32 RegistAll(fclEncyc_instance_tag *pinst) {
  s64 num_nakama;
  u64 v5;
  s32 v6;
  struct System_Byte_array *pnakamaindex;
  struct datUnitWork_t_array *unitwork;
  s64 v11;
  datUnitWork_t_o *v13;

  num_nakama = pinst->num_nakama;
  if (num_nakama < 1)
    return 0;
  v5 = 0;
  v6 = 0;
  do
  {
    pnakamaindex = pinst->pnakamaindex;
    unitwork = DDS3_GBWK->unitwork;
    v11 = pnakamaindex->m_Items[v5];
    v13 = unitwork->m_Items[v11];
    ++v5;
    if (fclEncycRegist(v13, 1, 0) == 1)
      ++v6;
  }
  while (num_nakama != v5);
  return v6;
}

// 0x119f960
void RegistModePanel(statusUI *ui, char **list) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v6;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v8;
  u64 *v9;
  s32 v10;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v12;
  s32 v13;
  s32 max_length;
  System_WeakReference_o *Item;
  bool activeSelf;
  System_WeakReference_o *v17;
  System_WeakReference_o *v19;
  System_WeakReference_o *v20;

  transform = get_transform(ui, 0);
  v6 = Find(transform, "comstatus_parts/commode/commode_menu", 0);
  gameObject = get_gameObject(v6);
  v8 = get_transform(gameObject, 0);
  v9 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v9);
  _Clear(v9);
  if (get_childCount(v8) >= 1)
  {
    v10 = 0;
    do
    {
      Child = GetChild(v8, v10);
      v12 = get_gameObject(Child);
      _Add(v9, v12);
      ++v10;
    }
    while (v10 < get_childCount(v8));
  }
  if (_get_Count(v9) >= 1)
  {
    v13 = 0;
    while (1)
    {
      max_length = list->max_length;
      Item = _get_Item(
               v9,
               v13);
      activeSelf = get_activeSelf(Item);
      if (v13 >= max_length)
        break;
      if (!activeSelf)
      {
        v17 = _get_Item(
                v9,
                v13);
        SetActive(v17, 1, 0);
      }
      v19 = _get_Item(
              v9,
              v13);
      DrawModePanelText(v19, list, v13++, 0);
      if (v13 >= _get_Count(v9))
        return;
    }
    if (activeSelf)
    {
      v20 = _get_Item(
              v9,
              v13);
      SetActive(v20, 0, 0);
    }
  }
}

// 0x11b30f0
void ReleaseDebug(void) {
  if (g_pdebug)
  {
    g_pdebug = 0;
  }
}

// 0x11a9dd0
void ReleaseFontExplain(fclEncyc_instance_tag *pinst, s32 release_mesmng) {
  s32 v3;
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 monitor;
  s32 v12;
  u64 v13[3];

  v3 = release_mesmng;
  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v13);
      if ((v13[0] & 1) != 0)
        v8 = v13[2];
      else
        v8 = v13 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  monitor = pwork[1].monitor;
  itfMesMngRequestMessageRelease(monitor, 0);
  pwork[11].klass = 0;
  pwork[11].monitor = 0;
  if (v3)
  {
    v12 = pwork[1].monitor;
    itfMesMngRelease(v12);
  }
}

// 0x119e870
void ReleaseFontList(_FRQ **ppfont, s32 num) {
  u64 v5;
  s64 v6;
  _FRQ_o **m_Items;
  _FRQ_o *v9;

  if (num >= 1)
  {
    v5 = 0;
    v6 = num;
    m_Items = ppfont->m_Items;
    do
    {
      v9 = m_Items[v5];
      if (v9)
      {
        frDestroyFontRequestNow(v9);
        m_Items[v5] = 0;
      }
      ++v5;
    }
    while (v6 != v5);
  }
}

// 0x119a480
void ReleaseWork(fclEncyc_instance_tag *pinst) {
  if (pinst->pwork)
    pinst->pwork = 0;
}

// 0x11a7c60
void RequestChangeMotion(fclEncyc_instance_tag *pinst, s32 flag) {
  u32 stat;
  u32 v4;
  u32 v5;
  s32 v6;

  stat = pinst->stat;
  v4 = stat & 0xFFFFFF3F;
  v5 = stat | 0xC0;
  v6 = v4 | 0x40;
  if (!flag)
    v5 = v6;
  pinst->stat = v5;
}

// 0x11afee0
void RequestModelLoad(fclEncyc_instance_tag *pinst, s32 id) {
  s32 RepeatSw;

  else if (!cmpGetStatusModelHandle())
  {
    goto LABEL_9;
  }
  else if (cmpGetModelMinorNo() == id)
  {
    return;
  }
LABEL_9:
  RepeatSw = pinst->RepeatSw;
  pinst->req_model = id;
  if (!RepeatSw)
    pinst->stat |= 4u;
}

// 0x11b0a90
void ResetCameraPos(fclEncyc_instance_tag *pinst) {
  SDF_VU0__COPYVECTOR(&pinst->pos_camera, cmpCameraEyePos);
  SDF_VU0__COPYVECTOR(&pinst->pos_camera_target, cmpCameraTargetPos);
}

// 0x11a5a80
void ResetReadMainRibbon(fclEncyc_readmainwork_tag *pwork) {
  struct System_Int32_array *pm;
  s32 v4;
  struct System_Int32_array *v6;
  s32 v7;
  struct System_Int32_array *v9;
  struct System_Int32_array *v11;
  s32 v12;
  struct System_Int32_array *ribbon_accel;
  struct System_Int32_array *v16;

  pm = pwork->ribbon_pos->pm;
  v4 = CMP_XM(0);
  pm->m_Items[0] = v4;
  v6 = pwork->ribbon_pos->pm;
  v7 = CMP_YM(11);
  v6->m_Items[1] = v7;
  v9 = pwork->ribbon_pos->pm;
  v9->m_Items[2] = 1152;
  v11 = pwork->ribbon_pos->pm;
  v12 = CMP_YM(21);
  v11->m_Items[3] = v12;
  ribbon_accel = pwork->ribbon_accel;
  pwork->ribbon_alpha = 128;
  ribbon_accel->m_Items[0] = 0;
  v16 = pwork->ribbon_accel;
  v16->m_Items[1] = 256;
}

// 0x119b490
void Set3DParam(fclEncyc_instance_tag *pinst) {
  fclEncyc_instance_tag_o *v4;

  dds3ScreenParam->ox = pinst->screen_ofsx;
  dds3ScreenParam->oy = pinst->screen_ofsy;
  if ((pinst->stat & 0x10) != 0)
  {
    else
    {
      v4 = pinst;
    }
    SetCameraLightParam(v4);
  }
  {
    cmpModelInitCore2();
  }
  else
  {
    cmpModelInitCore2();
  }
}

// 0x11a7720
void SetBoundControl(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct fclencyceelem_t_array *pelem;
  s64 id;
  struct viewtable_tag_array *tbl;
  struct viewtable_tag_array *v15;
  struct UnityEngine_Vector4_o *p_pos_camera_target;
  f32 v19;
  f32 v20;
  datUnitVisual_t_o *v21;
  struct viewtable_tag_array *v22;
  struct viewtable_tag_array *v24;
  f32 v27;
  f32 v28;
  f32 formsize;
  struct viewtable_tag_array *v32;
  f32 v34;
  s64 v37;
  struct viewtable_tag_array *v38;
  s32 v40;
  s64 v42;
  struct viewtable_tag_array *v43;
  s32 v45;
  s64 v47;
  struct viewtable_tag_array *v48;
  s32 ofs_x;
  s64 v52;
  struct viewtable_tag_array *v53;
  s32 ofs_y;
  u64 v57[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v57);
      if ((v57[0] & 1) != 0)
        v6 = v57[2];
      else
        v6 = v57 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pelem = DDS3_GBWK->encyc_record->pelem;
  id = pelem->m_Items[SLOWORD(pwork[1].klass)]->id;
  sub_8518D0(&pwork[4], 0, -tbl->m_Items[id]->rot_x);
  v15 = tbl;
  sub_8518D0(&pwork[4], 1, v15->m_Items[id]->rot_x);
  p_pos_camera_target = &pinst->pos_camera_target;
  sub_854710(p_pos_camera_target, 3u);
  v20 = v19;
  v21 = Get(id, 0);
  v22 = tbl;
  sub_8518D0(&pwork[4].monitor, 0, ((v20 + v21->formsize) + 80.0) + v22->m_Items[id]->radius);
  v24 = tbl;
  if (v24->m_Items[id]->rad_far <= 0.0)
  {
    v34 = *&pwork[3].monitor + *&pwork[3].monitor;
  }
  else
  {
    sub_854710(p_pos_camera_target, 3u);
    v28 = v27;
    formsize = Get(id, 0)->formsize;
    v32 = tbl;
    v34 = ((v28 + formsize) + 80.0) + v32->m_Items[id]->rad_far;
  }
  sub_8518D0(&pwork[4].monitor, 1, v34);
  v37 = *(pwork[5].monitor + 2);
  v38 = tbl;
  v40 = -v38->m_Items[id]->ofs_x;
  *(v37 + 32) = v40;
  v42 = *(pwork[5].monitor + 2);
  v43 = tbl;
  v45 = -v43->m_Items[id]->ofs_y;
  *(v42 + 36) = v45;
  v47 = *(pwork[5].monitor + 2);
  v48 = tbl;
  ofs_x = v48->m_Items[id]->ofs_x;
  *(v47 + 40) = ofs_x;
  v52 = *(pwork[5].monitor + 2);
  v53 = tbl;
  ofs_y = v53->m_Items[id]->ofs_y;
  *(v52 + 44) = ofs_y;
}

// 0x11affd0
void SetCameraLightParam(fclEncyc_instance_tag *pinst) {
  s32 FrameID;
  struct sdf3DScreenParam_t_o *dds3ScreenParam;
  f32 x;
  f32 z;
  f32 v15;
  f32 v17;
  struct dds3DrawEnv_t_array *dds3DrawEnv;
  sdf3DScreenParam_t_o *v21;
  s64 v22;
  s64 v23;
  s64 v24;
  sdf3DViewportPacket_t_o *ViewportPacket;
  s64 v26;
  s64 v27;
  s64 v28;
  s64 v29;
  s64 v31;
  sdf3DScreenParam_t_o *v32;
  s64 v33;
  s64 v34;
  s64 v35;
  s64 v36;
  s64 v37;
  s64 v38;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v42;
  f32 w;
  f32 y;
  UnityEngine_Matrix4x4_o v47;
  UnityEngine_Matrix4x4_o v48;
  UnityEngine_Vector3_o v49;
  UnityEngine_Vector3_o v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;
  UnityEngine_Vector4_o v59;

  *&v56.x = 0;
  *&v56.z = 0;
  *&v55.x = 0;
  *&v55.z = 0;
  *&v54.x = 0;
  *&v54.z = 0;
  v50.z = 0.0;
  *&v50.x = 0;
  v49.z = 0.0;
  *&v49.x = 0;
  *&v53.x = 0;
  *&v53.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v51.x = 0;
  *&v51.z = 0;
  sub_854690(&v56.x, 1.0, 1.0, 1.0, 0.0);
  sub_854690(&v55.x, 0.96, 0.36, 0.44, 1.0);
  sub_854690(&v54.x, 0.48, 0.45, 0.54, 0.0);
  sub_854690(&v53.x, 0.1, 0.1, 0.1, 1.0);
  *&p.x = 0;
  *&p.z = 0;
  FrameID = dds3GetFrameID();
  *&v51.x = 0;
  *&v51.z = 0;
  dds3SetSoftenBias(0, 5.0, 0.0);
  dds3SetLightColor(0, 0, v56);
  dds3SetLightDir(0, 0, v55);
  dds3SetAmbientColor(0, v54);
  dds3SetFogColor(0, v53);
  dds3SetFogPara(0, 255.0, 255.0, 2000.0, 30000.0);
  dds3ScreenParam->fovy = CMP_DEFAULT_FOVY;
  SDF_VU0__COPYVECTOR(&dds3CameraEyePos, pinst->pos_camera);
  SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, pinst->pos_camera_target);
  SDF_VU0__COPYVECTOR(&dds3CameraUpVector, cmpCameraUpVector);
  sdf3DMakeScreenParam(&dds3ScreenParam);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__SCALEVECTOR(600.0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__LOADVECTOR_B(dds3CameraOffset);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(dds3CameraEyePos);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v51);
  x = p.x;
  v58.y = p.y;
  z = p.z;
  v58.w = p.w;
  v15 = v51.x;
  v59.y = v51.y;
  v17 = v51.z;
  v59.w = v51.w;
  v58.x = x;
  v58.z = z;
  v59.x = v15;
  v59.z = v17;
  *&v57.x = 0;
  LookAtMatrix(v58, v59, v57);
  SDF_VU0__STOREMATRIX(&dds3CameraTM);
  v21 = dds3ScreenParam;
  v22 = *&dds3CameraTM.m00;
  v23 = *&dds3CameraTM.m20;
  v24 = *&dds3CameraTM.m21;
  ViewportPacket = dds3DrawEnv->m_Items[FrameID]->ViewportPacket;
  *&v48.m01 = *&dds3CameraTM.m01;
  *&v48.m21 = v24;
  *&v48.m00 = v22;
  *&v48.m20 = v23;
  v26 = *&dds3CameraTM.m02;
  v27 = *&dds3CameraTM.m22;
  v29 = *&dds3CameraTM.m03;
  v28 = *&dds3CameraTM.m23;
  *&v48.m03 = v29;
  *&v48.m23 = v28;
  *&v48.m02 = v26;
  *&v48.m22 = v27;
  sdf3DMakeViewportPacket(ViewportPacket, v21, &v48);
  v31 = *&dds3CameraTM.m21;
  v32 = dds3ScreenParam;
  v33 = *&dds3CameraTM.m00;
  v34 = *&dds3CameraTM.m20;
  *&v47.m01 = *&dds3CameraTM.m01;
  *&v47.m21 = v31;
  *&v47.m00 = v33;
  *&v47.m20 = v34;
  v35 = *&dds3CameraTM.m02;
  v36 = *&dds3CameraTM.m22;
  v38 = *&dds3CameraTM.m03;
  v37 = *&dds3CameraTM.m23;
  *&v47.m03 = v38;
  *&v47.m23 = v37;
  *&v47.m02 = v35;
  *&v47.m22 = v36;
  sdf3DSetCamera(v32, &v47);
  v50.z = 0.0;
  *&v50.x = 0;
  v49.z = 0.0;
  *&v49.x = 0;
  sub_8529B0(&v50, 0, dds3CameraEyePos.x / 100.0);
  sub_8529B0(&v50, 1, dds3CameraEyePos.y / -100.0);
  sub_8529B0(&v50, 2, dds3CameraEyePos.z / 100.0);
  transform = get_transform(campCameraObj, 0);
  set_localPosition(transform, v50);
  sub_8529B0(&v49, 0, dds3CameraTargetPos.x / 100.0);
  sub_8529B0(&v49, 1, dds3CameraTargetPos.y / -100.0);
  sub_8529B0(&v49, 2, dds3CameraTargetPos.z / 100.0);
  v42 = get_transform(campCameraObj, 0);
  LookAt_27488768(v42, v49);
}

// 0x11af0f0
void SetElem(fclencyceelem_t *pelem, datUnitWork_t *punit) {
  struct System_SByte_array *param;
  il2cpp_array_size_t max_length;
  s64 v7;
  struct System_SByte_array *v8;
  char v10;
  s64 v12;
  struct System_Int32_array *skill;
  char *v14;
  u64 v15;
  struct System_UInt16_array *v16;
  s32 v18;
  struct System_SByte_array *skillparam;
  il2cpp_array_size_t v21;
  s64 v22;
  struct System_SByte_array *v23;
  char v25;
  s64 v27;
  struct System_SByte_array *mitamaparam;
  il2cpp_array_size_t v29;
  s64 v30;
  struct System_SByte_array *v31;
  char v33;
  s64 v35;
  struct System_SByte_array *levelupparam;
  il2cpp_array_size_t v37;
  s64 v38;
  struct System_SByte_array *v39;
  char v41;
  s64 v43;
  struct System_UInt16_array *keisyoskill;
  il2cpp_array_size_t v45;
  s64 v46;
  struct System_UInt16_array *v47;
  s16 v49;
  s64 v51;
  struct System_Byte_array *keiattr;
  il2cpp_array_size_t v53;
  s64 v54;
  struct System_Byte_array *v55;
  char v57;
  s64 v59;

  fclencyceelem_t__Clear(pelem);
  pelem->id = punit->id;
  pelem->maxhp = punit->maxhp;
  pelem->maxmp = punit->maxmp;
  pelem->exp = punit->exp;
  pelem->level = punit->level;
  param = punit->param;
  max_length = param->max_length;
  if (max_length >= 1)
  {
    v7 = 32;
    do
    {
      v8 = pelem->param;
      v10 = *(&param->obj.klass + v7);
      *(&v8->obj.klass + v7) = v10;
      param = punit->param;
      LODWORD(max_length) = param->max_length;
      v12 = v7 - 31;
      ++v7;
    }
    while (v12 < max_length);
  }
  skill = punit->skill;
  v14 = skill->max_length;
  if (v14 >= 1)
  {
    v15 = 0;
    do
    {
      v16 = pelem->skill;
      v18 = skill->m_Items[v15];
      v14 = v16 + 2 * v15++;
      *(v14 + 16) = v18;
      skill = punit->skill;
      LODWORD(v14) = skill->max_length;
    }
    while (v15 < v14);
  }
  skillparam = punit->skillparam;
  v21 = skillparam->max_length;
  if (v21 >= 1)
  {
    v22 = 32;
    do
    {
      v23 = pelem->skillparam;
      v25 = *(&skillparam->obj.klass + v22);
      *(&v23->obj.klass + v22) = v25;
      skillparam = punit->skillparam;
      LODWORD(v21) = skillparam->max_length;
      v27 = v22 - 31;
      ++v22;
    }
    while (v27 < v21);
  }
  pelem->skillcnt = punit->skillcnt;
  mitamaparam = punit->mitamaparam;
  v29 = mitamaparam->max_length;
  if (v29 >= 1)
  {
    v30 = 32;
    do
    {
      v31 = pelem->mitamaparam;
      v33 = *(&mitamaparam->obj.klass + v30);
      *(&v31->obj.klass + v30) = v33;
      mitamaparam = punit->mitamaparam;
      LODWORD(v29) = mitamaparam->max_length;
      v35 = v30 - 31;
      ++v30;
    }
    while (v35 < v29);
  }
  levelupparam = punit->levelupparam;
  v37 = levelupparam->max_length;
  if (v37 >= 1)
  {
    v38 = 32;
    do
    {
      v39 = pelem->levelupparam;
      v41 = *(&levelupparam->obj.klass + v38);
      *(&v39->obj.klass + v38) = v41;
      levelupparam = punit->levelupparam;
      LODWORD(v37) = levelupparam->max_length;
      v43 = v38 - 31;
      ++v38;
    }
    while (v43 < v37);
  }
  keisyoskill = punit->keisyoskill;
  v45 = keisyoskill->max_length;
  if (v45 >= 1)
  {
    v46 = 16;
    do
    {
      v47 = pelem->keisyoskill;
      v49 = *(&keisyoskill->obj.klass + v46);
      *(&v47->obj.klass + v46) = v49;
      keisyoskill = punit->keisyoskill;
      LODWORD(v45) = keisyoskill->max_length;
      v51 = v46 - 15;
      ++v46;
    }
    while (v51 < v45);
  }
  keiattr = punit->keiattr;
  v53 = keiattr->max_length;
  if (v53 >= 1)
  {
    v54 = 32;
    do
    {
      v55 = pelem->keiattr;
      v57 = *(&keiattr->obj.klass + v54);
      *(&v55->obj.klass + v54) = v57;
      keiattr = punit->keiattr;
      LODWORD(v53) = keiattr->max_length;
      v59 = v54 - 31;
      ++v54;
    }
    while (v59 < v53);
  }
  pelem->hensinmae = punit->hensinmae;
  pelem->flag = punit->flag & 0x240;
  pelem->hensinmaeexp = punit->hensinmaeexp;
}

// 0x11af4b0
void SetElem2(fclencyceelem_t *pelem, fclencyceelem_t *pelemsrc) {
  fclencyceelem_t__Clear(pelem);
  fclencyceelem_t__Copy(pelem, pelemsrc);
}

// 0x11ae9b0
void SetForceListwinCursor(lstListWindow_t *plistwin, s32 index, s32 shift) {
  struct cmpCursorInfo_t_o *CursorInfo;
  struct cmpCursorSize_t_o *CursorSize;
  struct cmpCursorPos_t_o *CursorPos;

  CursorInfo = plistwin->CursorInfo;
  CursorSize = CursorInfo->CursorSize;
  CursorPos = CursorInfo->CursorPos;
  CursorPos->Index = index;
  CursorPos->Shift = shift;
  CursorPos->DrawShift = shift;
  CursorSize->Y = CursorSize->DefY + CursorInfo->StepY * shift;
}

// 0x11af4f0
void SetRecordToUnit(datUnitWork_t *punit, s32 id) {
  s32 v3;
  struct fclEncycRecord_t_o *encyc_record;
  s32 v7;
  struct fclencyceelem_t_array *pelem;

  v3 = id;
  encyc_record = DDS3_GBWK->encyc_record;
  if (v3 == 192)
  {
    if (IsDLC())
      v3 = 191;
    else
      v3 = 192;
  }
  v7 = fclEncycSearch(v3, *&id);
  pelem = encyc_record->pelem;
  SetRecordToUnitCore(punit, pelem->m_Items[v7]);
}

// 0x11af600
void SetRecordToUnitCore(datUnitWork_t *punit, fclencyceelem_t *pelem) {
  u16 id;
  struct System_SByte_array *param;
  il2cpp_array_size_t max_length;
  s64 v9;
  struct System_SByte_array *v10;
  char v12;
  s64 v14;
  struct System_UInt16_array *skill;
  char *v16;
  u64 v17;
  struct System_Int32_array *v18;
  s32 v20;
  struct System_SByte_array *skillparam;
  il2cpp_array_size_t v23;
  s64 v24;
  struct System_SByte_array *v25;
  char v27;
  s64 v29;
  struct System_SByte_array *mitamaparam;
  il2cpp_array_size_t v31;
  s64 v32;
  struct System_SByte_array *v33;
  char v35;
  s64 v37;
  struct System_SByte_array *levelupparam;
  il2cpp_array_size_t v39;
  s64 v40;
  struct System_SByte_array *v41;
  char v43;
  s64 v45;
  struct System_UInt16_array *keisyoskill;
  il2cpp_array_size_t v47;
  s64 v48;
  struct System_UInt16_array *v49;
  s16 v51;
  s64 v53;
  struct System_Byte_array *keiattr;
  il2cpp_array_size_t v55;
  s64 v56;
  struct System_Byte_array *v57;
  char v59;
  s64 v61;
  u32 v62;

  datUnitWork_t__Clear(punit);
  id = pelem->id;
  cmbCopyDefaultDevilToStock(id, punit);
  punit->hp = pelem->maxhp;
  punit->maxhp = pelem->maxhp;
  punit->mp = pelem->maxmp;
  punit->maxmp = pelem->maxmp;
  punit->exp = pelem->exp;
  punit->level = pelem->level;
  param = pelem->param;
  max_length = param->max_length;
  if (max_length >= 1)
  {
    v9 = 32;
    do
    {
      v10 = punit->param;
      v12 = *(&param->obj.klass + v9);
      *(&v10->obj.klass + v9) = v12;
      param = pelem->param;
      LODWORD(max_length) = param->max_length;
      v14 = v9 - 31;
      ++v9;
    }
    while (v14 < max_length);
  }
  skill = pelem->skill;
  v16 = skill->max_length;
  if (v16 >= 1)
  {
    v17 = 0;
    do
    {
      v18 = punit->skill;
      v20 = skill->m_Items[v17];
      v16 = v18 + 4 * v17++;
      *(v16 + 8) = v20;
      skill = pelem->skill;
      LODWORD(v16) = skill->max_length;
    }
    while (v17 < v16);
  }
  skillparam = pelem->skillparam;
  v23 = skillparam->max_length;
  if (v23 >= 1)
  {
    v24 = 32;
    do
    {
      v25 = punit->skillparam;
      v27 = *(&skillparam->obj.klass + v24);
      *(&v25->obj.klass + v24) = v27;
      skillparam = pelem->skillparam;
      LODWORD(v23) = skillparam->max_length;
      v29 = v24 - 31;
      ++v24;
    }
    while (v29 < v23);
  }
  punit->skillcnt = pelem->skillcnt;
  mitamaparam = pelem->mitamaparam;
  v31 = mitamaparam->max_length;
  if (v31 >= 1)
  {
    v32 = 32;
    do
    {
      v33 = punit->mitamaparam;
      v35 = *(&mitamaparam->obj.klass + v32);
      *(&v33->obj.klass + v32) = v35;
      mitamaparam = pelem->mitamaparam;
      LODWORD(v31) = mitamaparam->max_length;
      v37 = v32 - 31;
      ++v32;
    }
    while (v37 < v31);
  }
  levelupparam = pelem->levelupparam;
  v39 = levelupparam->max_length;
  if (v39 >= 1)
  {
    v40 = 32;
    do
    {
      v41 = punit->levelupparam;
      v43 = *(&levelupparam->obj.klass + v40);
      *(&v41->obj.klass + v40) = v43;
      levelupparam = pelem->levelupparam;
      LODWORD(v39) = levelupparam->max_length;
      v45 = v40 - 31;
      ++v40;
    }
    while (v45 < v39);
  }
  keisyoskill = pelem->keisyoskill;
  v47 = keisyoskill->max_length;
  if (v47 >= 1)
  {
    v48 = 16;
    do
    {
      v49 = punit->keisyoskill;
      v51 = *(&keisyoskill->obj.klass + v48);
      *(&v49->obj.klass + v48) = v51;
      keisyoskill = pelem->keisyoskill;
      LODWORD(v47) = keisyoskill->max_length;
      v53 = v48 - 15;
      ++v48;
    }
    while (v53 < v47);
  }
  keiattr = pelem->keiattr;
  v55 = keiattr->max_length;
  if (v55 >= 1)
  {
    v56 = 32;
    do
    {
      v57 = punit->keiattr;
      v59 = *(&keiattr->obj.klass + v56);
      *(&v57->obj.klass + v56) = v59;
      keiattr = pelem->keiattr;
      LODWORD(v55) = keiattr->max_length;
      v61 = v56 - 31;
      ++v56;
    }
    while (v61 < v55);
  }
  punit->hensinmae = pelem->hensinmae;
  v62 = punit->flag & 0xFFFFFDBF;
  punit->flag = v62;
  punit->flag = pelem->flag | v62;
  punit->hensinmaeexp = pelem->hensinmaeexp;
}

// 0x119a450
void SetScreenOffset(fclEncyc_instance_tag *pinst, s32 flag) {
  f32 v3;

  v3 = flt_32C3158[flag == 0];
  pinst->screen_ofsy = 2048.0;
  pinst->screen_ofsx = v3;
}

// 0x119c320
void StatusBackProcess(fclEncyc_instance_tag *pinst) {
  dds3Basic_t_o *basic;

  basic = 0;
  cmpModelEnd();
  cmpModelInitFacility();
  basic = dds3GetActiveScene();
  if (basic)
  {
    dds3VisibleSceneBasic(&basic, 1);
  }
  DispRegistConfirm(0);
  DevilStatusMode(0, 1);
  pinst->StatusBack = 0;
}

// 0x119f5f0
void StatusFrontProcess(fclEncyc_instance_tag *pinst, s32 mode) {
  s64 *v6;
  System_String_o *v7;
  UnityEngine_GameObject_o *GameObject;
  UnityEngine_GameObject_o *v10;
  UnityEngine_GameObject_o *v12;

  DevilStatusMode(1, 0);
  v6 = &"dlistrec";
  if (mode)
    v6 = &"dlistsum";
  v7 = *v6;
  GameObject = GetGameObject(v7);
  if (get_activeSelf(GameObject))
    SetActive(GameObject, 0, 0);
  v10 = GetGameObject("combgcolor");
  if (get_activeSelf(v10))
    SetActive(v10, 0, 0);
  v12 = GetGameObject("comtitle");
  if (get_activeSelf(v12))
    SetActive(v12, 0, 0);
  pinst->StatusBack = 0;
}

// 0x119b590
void *UpdateProc(dds3ProcessID_t *proc_id) {
  u64 *v2;
  u64 *v3;
  u64 *v5;
  u64 *v7;
  u64 *v9;
  u64 *v11;
  u64 *v13;
  u64 *v15;
  u64 *v17;
  struct fclEncyc_instance_tag_o *g_pinst;
  u32 stat;
  s32 v23;
  s32 phase;
  s32 next_phase;

  v2 = NewSpecific(fclEncyc_funcDelegate, 8u);
  v3 = Allocate(fclEncyc_funcDelegate);
  _ctor(v3, 0, Method_fclEncyc_DestPhaseRegistTop__, 0);
  v2[4] = v3;
  v5 = Allocate(fclEncyc_funcDelegate);
  _ctor(v5, 0, Method_fclEncyc_DestPhaseRegistConfirm__, 0);
  v2[5] = v5;
  v7 = Allocate(fclEncyc_funcDelegate);
  _ctor(v7, 0, Method_fclEncyc_DestPhaseRegistTop__, 0);
  v2[6] = v7;
  v9 = Allocate(fclEncyc_funcDelegate);
  _ctor(v9, 0, Method_fclEncyc_DestPhaseReadTop__, 0);
  v2[7] = v9;
  v11 = Allocate(fclEncyc_funcDelegate);
  _ctor(v11, 0, Method_fclEncyc_DestPhaseReadStatus__, 0);
  v2[8] = v11;
  v13 = Allocate(fclEncyc_funcDelegate);
  _ctor(v13, 0, Method_fclEncyc_DestPhaseReadStatus__, 0);
  v2[9] = v13;
  v15 = Allocate(fclEncyc_funcDelegate);
  _ctor(v15, 0, Method_fclEncyc_DestPhaseReadStatus__, 0);
  v2[10] = v15;
  v17 = Allocate(fclEncyc_funcDelegate);
  _ctor(v17, 0, Method_fclEncyc_DestPhaseReadStatus__, 0);
  v2[11] = v17;
  if (g_pinst)
  {
    stat = g_pinst->stat;
    if ((stat & 0x20) != 0)
    {
      if ((stat & 0x100) != 0)
      {
        *&g_pinst->screen_ofsx = 0x4500000045000000LL;
        stat &= 0xFFFFFEE7;
        g_pinst->stat = stat;
      }
      if ((stat & 2) != 0)
      {
        if (v2[g_pinst->phase + 4])
        {
          Invoke(v2[g_pinst->phase + 4], g_pinst, 0);
        }
        stat = g_pinst->stat & 0xFFFFFFFD;
        v23 = 1;
        g_pinst->stat = stat;
        phase = g_pinst->phase;
        next_phase = g_pinst->next_phase;
        if (phase == next_phase)
          goto LABEL_65;
      }
      else
      {
        v23 = 0;
        phase = g_pinst->phase;
        next_phase = g_pinst->next_phase;
        if (phase == next_phase)
        {
LABEL_65:
          ++g_pinst->ctr;
          if (phase == 8)
          {
            fclEncycKillProcess();
          }
          return 0;
        }
      }
      g_pinst->phase = next_phase;
      if (v23)
        g_pinst->stat = stat & 0xFFFFFFFE;
      phase = next_phase;
      goto LABEL_65;
    }
  }
  return 0;
}

// 0x11b57c0
s32 draw_race_devil(fclEncyc_instance_tag *pinst) {
  System_String_o **pwork;
  System_String_o *v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v11;
  UnityEngine_GameObject_o *v12;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GameObject_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *v18;
  UnityEngine_Transform_o *v19;
  UnityEngine_Component_o *v20;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_Transform_o *v22;
  UnityEngine_Component_o *v23;
  UnityEngine_GUILayer_o *v24;
  u64 v26[3];

  pwork = pinst->pwork;
  if (pwork)
  {
    v4 = *pwork;
    if (LOBYTE((*pwork)[12].klass) < typeHierarchyDepth
      || *(v4[8].monitor + typeHierarchyDepth - 1) != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(*&v4[2].fields, fclEncyc_readmainwork_tag, v26);
      if ((v26[0] & 1) != 0)
        v6 = v26[2];
      else
        v6 = v26 + 1;
      v7 = sub_8C4940(v6);
    }
    gameObject = get_gameObject(_statusUIScr);
    transform = get_transform(gameObject, 0);
    v11 = Find(transform, "comstatus_parts", 0);
    v12 = get_gameObject(v11);
    v13 = get_transform(v12, 0);
    v14 = Find(v13, "comveiw", 0);
    v15 = get_gameObject(v14);
    if (!get_activeSelf(v15))
      SetActive(v15, 1, 0);
    v16 = get_transform(v12, 0);
    v17 = Find(v16, "comnote", 0);
    v18 = get_gameObject(v17);
    if (!get_activeSelf(v18))
      SetActive(v18, 1, 0);
    v19 = get_transform(v18, 0);
    v20 = Find(v19, "Text_raceTM", 0);
    Component_GUILayer = GetComponent_GUILayer_(v20);
    set_text(Component_GUILayer, pwork[22]);
    v22 = get_transform(v18, 0);
    v23 = Find(v22, "Text_nameTM", 0);
    v24 = GetComponent_GUILayer_(v23);
    set_text(v24, pwork[23]);
  }
  return 1;
}

// 0x119cbb0
void draw_status_off(bool sw) {
  _BOOL4 v2;
  struct statusUI_o *statusUIScr;
  UnityEngine_GameObject_o *titleObj;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v9;
  UnityEngine_GameObject_o *v11;
  UnityEngine_Transform_o *v12;
  UnityEngine_Component_o *v13;
  UnityEngine_GameObject_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *v19;
  UnityEngine_Transform_o *v20;
  UnityEngine_Component_o *v21;
  UnityEngine_GameObject_o *v23;
  UnityEngine_Transform_o *v24;
  UnityEngine_Component_o *v25;
  UnityEngine_GameObject_o *v27;
  UnityEngine_Transform_o *v28;
  UnityEngine_Component_o *v29;
  UnityEngine_GameObject_o *v31;
  UnityEngine_Transform_o *v32;
  UnityEngine_Component_o *v33;
  UnityEngine_GameObject_o *v34;
  UnityEngine_Transform_o *v35;
  UnityEngine_Component_o *v36;
  UnityEngine_GameObject_o *v37;
  UnityEngine_Transform_o *v38;
  UnityEngine_Component_o *v39;
  UnityEngine_GameObject_o *v41;

  v2 = sw;
  statusUIScr = _statusUIScr;
  if (!op_Equality(statusUIScr, 0, 0))
  {
    titleObj = statusUIScr->titleObj;
    if (op_Inequality(titleObj, 0, 0) && get_activeSelf(titleObj))
      SetActive(titleObj, 0, 0);
    gameObject = get_gameObject(statusUIScr);
    transform = get_transform(gameObject, 0);
    v9 = Find(transform, "title_window", 0);
    v11 = get_gameObject(v9);
    if (op_Inequality(v11, 0, 0) && get_activeSelf(v11))
      SetActive(v11, 0, 0);
    v12 = get_transform(gameObject, 0);
    v13 = Find(v12, "sinfo_basic", 0);
    v15 = get_gameObject(v13);
    if (op_Inequality(v15, 0, 0)
      && ((get_activeSelf(v15) ^ v2) & 1) == 0)
    {
      SetActive(v15, !v2, 0);
    }
    v16 = get_transform(gameObject, 0);
    v17 = Find(v16, "sstatus", 0);
    v19 = get_gameObject(v17);
    if (op_Inequality(v19, 0, 0)
      && ((get_activeSelf(v19) ^ v2) & 1) == 0)
    {
      SetActive(v19, !v2, 0);
    }
    v20 = get_transform(gameObject, 0);
    v21 = Find(v20, "sfeature", 0);
    v23 = get_gameObject(v21);
    if (op_Inequality(v23, 0, 0)
      && ((get_activeSelf(v23) ^ v2) & 1) == 0)
    {
      SetActive(v23, !v2, 0);
    }
    v24 = get_transform(gameObject, 0);
    v25 = Find(v24, "sskill", 0);
    v27 = get_gameObject(v25);
    if (op_Inequality(v27, 0, 0)
      && ((get_activeSelf(v27) ^ v2) & 1) == 0)
    {
      SetActive(v27, !v2, 0);
    }
    v28 = get_transform(gameObject, 0);
    v29 = Find(v28, "sstatusbad", 0);
    v31 = get_gameObject(v29);
    if (op_Inequality(v31, 0, 0)
      && ((get_activeSelf(v31) ^ v2) & 1) == 0)
    {
      SetActive(v31, !v2, 0);
    }
    v32 = get_transform(gameObject, 0);
    v33 = Find(v32, "comstatus_parts", 0);
    v34 = get_gameObject(v33);
    v35 = get_transform(v34, 0);
    v36 = Find(v35, "commoney", 0);
    v37 = get_gameObject(v36);
    if (get_activeSelf(v37))
      SetActive(v37, 0, 0);
    v38 = get_transform(v34, 0);
    v39 = Find(v38, "comnote", 0);
    v41 = get_gameObject(v39);
    ClearMessage(v41);
    SetInteger(statusUIScr->infoAnim, "sinfo", v2);
  }
}

// 0x1197000
s32 fclEncycCheckRegistable(void) {
  return GetValidUnitIndex(0);
}

// 0x11b5280
dds3ProcessFunc_t *fclEncycDebugProc(dds3ProcessID_t *proc_id) {
  u64 *v3;
  u64 *v4;
  u64 *v6;
  u64 *v8;
  u64 *v10;
  u64 *v22;
  fclEncyc_debug_t_o *g_pdebug;
  s32 v30;
  struct sdfGrOt_t_array *dds3Ot;
  s32 v34;

  v3 = NewSpecific(fclEncyc_funcDelegate_a, 4u);
  v4 = Allocate(fclEncyc_funcDelegate_a);
  _ctor(v4, 0, Method_fclEncyc_DebugProcMenu__, 0);
  v3[4] = v4;
  v6 = Allocate(fclEncyc_funcDelegate_a);
  _ctor(v6, 0, Method_fclEncyc_DebugProcRegister__, 0);
  v3[5] = v6;
  v8 = Allocate(fclEncyc_funcDelegate_a);
  _ctor(v8, 0, Method_fclEncyc_DebugProcViewkey__, 0);
  v3[6] = v8;
  v10 = Allocate(fclEncyc_funcDelegate_a);
  _ctor(v10, 0, Method_fclEncyc_DebugProcDispBound__, 0);
  v3[7] = v10;
  if (g_pinst)
  {
    else if (!g_pdebug)
    {
      goto LABEL_26;
    }
    v22 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v22);
    sdfDrawTagInit(v22);
    v30 = Invoke(v3[g_pdebug->phase + 4], g_pinst, g_pdebug, v22, 0);
    sdfDrawTagLinkOt(dds3Ot->m_Items[81], v22);
    if (v30)
      v34 = -1;
    else
      v34 = 0;
    proc_id->func_ans = v34;
  }
  return 0;
}

// 0x11b50d0
void fclEncycDebugRegist(void) {
  dds3GlobalWork_c *v2;
  s64 stockcnt;
  s64 v4;
  u64 v5;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Int32_array *stocklist;
  struct datUnitWork_t_array *unitwork;
  s64 v10;
  datUnitWork_t_o *v11;
  u64 *v13;

  stockcnt = DDS3_GBWK->stockcnt;
  if (stockcnt >= 1)
  {
    v4 = stockcnt - 1;
    v5 = 0;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_12;
LABEL_10:
    while (1)
    {
LABEL_12:
      stocklist = DDS3_GBWK->stocklist;
      unitwork = DDS3_GBWK->unitwork;
      v10 = stocklist->m_Items[v5];
      v11 = unitwork->m_Items[v10];
      if ((v11->flag & 4) != 0)
      {
        if (v4 == v5)
          return;
      }
      else
      {
        v13 = Allocate(datUnitWork_t);
        datUnitWork_t___ctor(v13);
        datUnitWork_t__Copy(v13, v11);
        fclEncycRegist(v13, 0, 0);
        if (v4 == v5)
          return;
      }
      ++v5;
        goto LABEL_10;
    }
  }
}

// 0x11b56e0
dds3ProcessFunc_t *fclEncycDebugShutdown(dds3ProcessID_t *proc_id) {
LABEL_7:
  if (g_pdebug)
  {
    g_pdebug = 0;
  }
  return 0;
}

// 0x1197070
s32 fclEncycGetNum(void) {
  return DDS3_GBWK->encyc_record->num;
}

// 0x11a24f0
s32 fclEncycGetNumForDLC(void) {
  dds3GlobalWork_c *v2;
  s64 num;
  u64 v4;
  s32 v5;
  struct fclencyceelem_t_array *pelem;

  num = DDS3_GBWK->encyc_record->num;
  if (num < 1)
  {
    LOBYTE(v5) = 1;
  }
  else
  {
    v4 = 0;
    v5 = 1;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_12;
LABEL_10:
    while (1)
    {
LABEL_12:
      pelem = DDS3_GBWK->encyc_record->pelem;
      if (pelem->m_Items[v4]->id == 191)
      {
        v5 &= GetOrUsed(2);
      }
      if (num - 1 == v4)
        break;
      ++v4;
        goto LABEL_10;
    }
  }
  return num - ((v5 & 1) == 0);
}

// 0x11b4f90
s32 fclEncycGetRatio(void) {
  s32 num;
  s32 result;

LABEL_7:
  num = DDS3_GBWK->encyc_record->num;
  result = 100 * num / (LODWORD(ZensyoDevilID->max_length) - 1);
  if (num >= 1 && result <= 1)
    return 1;
  return result;
}

// 0x11a4570
s32 fclEncycGetRatio2(void) {
  s32 v4;
  s32 RegNum;
  struct fclencyceelem_t_array *pelem;
  u64 *v8;
  s64 num;
  s64 v12;
  u64 v14;
  struct System_UInt16_array *ZensyoDevilID;
  u64 max_length_low;
  struct System_UInt16_array *v19;
  u64 v21;
  fclencyceelem_t_o **m_Items;
  s32 v28;

  v4 = LODWORD(ZensyoDevilID->max_length) - 2;

  {
    v28 = LODWORD(ZensyoDevilID->max_length) - 2;
    pelem = DDS3_GBWK->encyc_record->pelem;
    v8 = Allocate(System_Collections_Generic_Dictionary_int__int_);
    int____ctor(
      v8);
    num = DDS3_GBWK->encyc_record->num;
    v12 = 16;
    v14 = 0;
    {
LABEL_25:
    }
    while (1)
    {
      max_length_low = LODWORD(ZensyoDevilID->max_length);
      if (v14 >= max_length_low)
        break;
      else if (v14 >= max_length_low)
      {
        goto LABEL_31;
      }
      if (!int___ContainsKey(
              v8,
              *(&ZensyoDevilID->obj.klass + v12)))
      {
        v19 = ZensyoDevilID;
        int___Add(
          v8,
          *(&v19->obj.klass + v12),
          *(&ZensyoDevilID->obj.klass + v12));
      }
      ++v12;
      v14 = v12 - 16;
        goto LABEL_25;
    }
    if (num >= 1)
    {
      v21 = 0;
      m_Items = pelem->m_Items;
      do
      {
        if (int___ContainsKey(v8, m_Items[v21]->id))
        {
          int___Remove(v8, m_Items[v21]->id);
        }
        ++v21;
      }
      while (num != v21);
    }
    if (int___ContainsKey(v8, 191))
    {
      int___Remove(v8, 191);
    }
    v4 = v28;
    RegNum = v28
           - int___get_Count(v8);
    Registed = 1;
  }
  return 100 * RegNum / v4;
}

// 0x11b4c80
void fclEncycInitRecord(s32 mode) {
  if (!mode)
LABEL_6:
    DDS3_GBWK->encyc_record->num = 0;
LABEL_7:
  g_pinst = 0;
  g_pdebug = 0;
}

// 0x119bb10
s32 fclEncycKillProcess(void) {
  fclEncyc_instance_tag_o *g_pinst;
  u64 *v4;
  struct dds3ProcessID_t_array *procid;
  struct dds3ProcessID_t_array *v12;
  struct dds3ProcessID_t_array *v14;

  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  UnloadCollectionBook();
  cmpModelEnd();
  cmpModelInitFacility();
  if (g_pinst->StatusBack)
  {
    StatusBackProcess(g_pinst);
  }
  else if (cmpChkStatusModelLoadStat())
  {
LABEL_20:
    Write("ENCYC:  wait to kill process\n", 0);
    return -1;
  }
  procid = g_pinst->procid;
  else if (!LODWORD(procid->max_length))
  {
    goto LABEL_28;
  }
  dds3KillProcess(procid->m_Items, 0);
  v12 = g_pinst->procid;
  dds3KillProcess(&v12->m_Items[1], 0);
  v14 = g_pinst->procid;
  dds3KillProcess(&v14->m_Items[2], 0);
  cmpModelFreeResource();
  if (g_pinst->pwork)
    g_pinst->pwork = 0;
  g_pinst = 0;
  Write("ENCYC:  all process halted.\n", 0);
  SetButtonGuide(2, 0);
  RemakeFldSky();
  return 0;
}

// 0x11a0c90
s32 fclEncycRegist(datUnitWork_t *punit, s32 overwrite, bool update) {
  struct fclEncycRecord_t_o *encyc_record;
  struct fclencyceelem_t_array *pelem;
  s32 id;
  _BOOL4 IsDLC;
  bool v12;
  u16 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v19;
  s32 v21;

  encyc_record = DDS3_GBWK->encyc_record;
  pelem = encyc_record->pelem;
  id = punit->id;
  IsDLC = IsDLC();
  v12 = id == 192;
  v13 = punit->id;
  v14 = v12;
  v15 = v14 & IsDLC;
  if ((v14 & IsDLC) == 1)
    punit->id = --v13;
  v16 = fclEncycSearch(v13);
  if (v16 < 0)
    goto LABEL_24;
LABEL_17:
  if (!overwrite)
  {
    if (v15)
      ++punit->id;
    return -1;
  }
  v19 = v16;
  v21 = 1;
    goto LABEL_34;
LABEL_19:
LABEL_34:
  Registed = 0;
  SetElem(pelem->m_Items[v19], punit);
  if (fclEncycGetRatio2() < 100)
  {
    evtBitOff(2323);
    if (!v15)
      return v21;
    goto LABEL_40;
  }
  evtBitOn(2323);
  if (v15)
LABEL_40:
    ++punit->id;
  return v21;
}

// 0x11b4d40
s32 fclEncycRegist2(fclencyceelem_t *pelemsrc, s32 overwrite) {
  struct fclEncycRecord_t_o *encyc_record;
  struct fclencyceelem_t_array *pelem;
  s32 id;
  s32 v9;
  s32 v11;
  s64 v12;
  fclencyceelem_t_o *v14;

  encyc_record = DDS3_GBWK->encyc_record;
  pelem = encyc_record->pelem;
  id = pelemsrc->id;
  v9 = fclEncycSearch(id);
  if (v9 < 0)
    goto LABEL_19;
LABEL_9:
  if (!overwrite)
    return -1;
  v11 = 1;
  v12 = v9;
  if (v9 >= LODWORD(pelem->max_length))
    goto LABEL_11;
LABEL_12:
  v14 = pelem->m_Items[v12];
  fclencyceelem_t__Clear(v14);
  fclencyceelem_t__Copy(v14, pelemsrc);
  if (fclEncycGetRatio2() >= 100)
    evtBitOn(2323);
  else
    evtBitOff(2323);
  return v11;
}

// 0x11ae530
s32 fclEncycSearch(s32 id) {
  struct fclEncycRecord_t_o *encyc_record;
  signed s64 num;
  struct fclencyceelem_t_array *pelem;
  u64 v7;
  s32 v8;

  encyc_record = DDS3_GBWK->encyc_record;
  num = encyc_record->num;
  if (num < 1)
    return -1;
  pelem = encyc_record->pelem;
  v7 = 0;
  v8 = -1;
  while (1)
  {
    if (pelem->m_Items[v7]->id == id)
      break;
    if (++v7 >= num)
      return v8;
  }
  return v7;
}

// 0x11967d0
void fclEncycSetExplainData(void *pbmd) {
  g_pinst->pbmd = pbmd;
}

// 0x11963d0
void fclEncycSetTexHandle(sdfTexHandle_t **texhandle) {
  struct fclEncyc_instance_tag_o *g_pinst;
  struct sdfTexHandle_t_array *v5;
  sdfTexHandle_t_o *v6;
  struct sdfTexHandle_t_array *v9;
  sdfTexHandle_t_o *v10;
  struct sdfTexHandle_t_array *v13;
  sdfTexHandle_t_o *v15;
  struct sdfTexHandle_t_array *v17;
  sdfTexHandle_t_o *v18;
  struct sdfTexHandle_t_array *v21;
  sdfTexHandle_t_o *v23;
  struct sdfTexHandle_t_array *v25;
  sdfTexHandle_t_o *v27;
  struct sdfTexHandle_t_array *v29;
  s64 *v31;

  v5 = g_pinst->texhandle;
  v6 = texhandle->m_Items[0];
  v5->m_Items[0] = v6;
  v9 = g_pinst->texhandle;
  v10 = texhandle->m_Items[1];
  v9->m_Items[1] = v10;
  v13 = g_pinst->texhandle;
  v15 = texhandle->m_Items[2];
  v13->m_Items[2] = v15;
  v17 = g_pinst->texhandle;
  v18 = texhandle->m_Items[3];
  v17->m_Items[3] = v18;
  v21 = g_pinst->texhandle;
  v23 = texhandle->m_Items[4];
  v21->m_Items[4] = v23;
  v25 = g_pinst->texhandle;
  v27 = texhandle->m_Items[5];
  v25->m_Items[5] = v27;
  v29 = g_pinst->texhandle;
  v31 = texhandle->m_Items[6];
  v29->m_Items[6] = v31;
}

// 0x1195e60
void fclEncycStartProcess(s32 mode) {
  u64 *v3;
  fclEncyc_instance_tag_o *v4;
  u32 stat;
  s16 v9;
  struct dds3ProcessID_t_array *procid;
  u64 *v20;
  s64 *started;
  s64 *v23;
  struct dds3ProcessID_t_array *v25;
  u64 *v26;
  s64 *v27;
  s64 *v28;
  struct dds3ProcessID_t_array *v30;
  u64 *v31;
  s64 *v32;
  s64 *v34;
  System_String_o *v36;
  Il2CppObject **v37;
  Il2CppObject *v38;
  UnityEngine_GameObject_o *v41;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(fclEncyc_instance_tag);
  _ctor(v4, 0);
  v4->memhandle = v3;
  InitializeInstance(v4);
  LoadCollectionBook();
  stat = v4->stat;
  if (mode)
  {
    stat |= 0x200u;
    v4->stat = stat;
  }
  v9 = ((stat << 22) >> 31) & 3;
  v4->phase = v9;
  v4->next_phase = v9;
  if ((stat & 0x200) != 0)
  {
    else if ((byte_3F58E03 & 1) != 0)
    {
      goto LABEL_16;
    }
    goto LABEL_16;
  }
LABEL_28:
  procid = v4->procid;
  v20 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v20,
    0,
    Method_fclEncyc_CalcProc__);
  started = dds3StartProcess("CALC_ENCYC", 0x407u, 0, 0, v20, 0, 0, 0, 0, 0);
  v23 = started;
  procid->m_Items[0] = v23;
  v25 = v4->procid;
  v26 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v26,
    0,
    Method_fclEncyc_DrawProc__);
  v27 = dds3StartProcess("DRAW_ENCYC", 0x2B17u, 0, 0, v26, 0, 0, 0, 0, 0);
  v28 = v27;
  v25->m_Items[1] = v28;
  v30 = v4->procid;
  v31 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v31,
    0,
    Method_fclEncyc_UpdateProc__);
  v32 = dds3StartProcess("UPDT_ENCYC", 0x5213u, 0, 0, v31, 0, 0, 0, 0, 0);
  v34 = v32;
  v30->m_Items[2] = v34;
  v36 = "ENCYC:process start ({0})\n";
  v37 = &"READING";
  if (!mode)
    v37 = &"REGISTRATION";
  v38 = *v37;
  Write_2930400(v36, v38);
  g_pinst = v4;
  v41 = Find("kernel", 0);
  pKernel = GetComponent_object_(v41);
}

// 0x1196f90
s32 fclEncycWork(void) {
  return g_pinst != 0;
}

// 0x11b0c60
void mdlSetMotionSpeed(f32 speed) {
  UnityEngine_GameObject_o *cmpMdlObj;
  UnityEngine_Animator_o *Animator;

  if (!op_Equality(cmpMdlObj, 0, 0))
  {
    Animator = GetAnimator(cmpMdlObj);
    if (!op_Equality(Animator, 0, 0))
      set_speed(Animator, speed);
  }
}

// 0x11b0b30
void mdlSmoothLoopMotionForUnity(s32 motion, s32 a, s32 b) {
  UnityEngine_GameObject_o *cmpMdlObj;
  UnityEngine_Animator_o *Animator;

  if (!op_Equality(cmpMdlObj, 0, 0))
  {
    Animator = GetAnimator(cmpMdlObj);
    if (!op_Equality(Animator, 0, 0))
      SetInteger(Animator, "anim", motion);
  }
}

// 0x11ada90
void reset_viewmode(fclEncyc_instance_tag *pinst) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3GlobalWork_c *v11;
  struct fclencyceelem_t_array *pelem;
  const char *name;
  const char *v16;
  UnityEngine_Object_o *statusUIScr;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v24;
  u64 v25[3];
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v27;

  pwork = pinst->pwork;
  if (pwork)
  {
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclEncyc_readmainwork_tag)
    {
      sub_8FC2C0(klass->_1.element_class, fclEncyc_readmainwork_tag, v25);
      if ((v25[0] & 1) != 0)
        v6 = v25[2];
      else
        v6 = v25 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (cmpGetStatusModelHandle())
  {
    InitCameraForViewMode(pinst);
    pelem = DDS3_GBWK->encyc_record->pelem;
    InitModelPosRot(v11, pelem->m_Items[SLOWORD(pwork[1].klass)]->id);
    name = pwork[5].klass->_1.name;
    *(name + 8) = 0;
    v16 = pwork[5].klass->_1.name;
    *(v16 + 9) = 0;
  }
  statusUIScr = _statusUIScr;
  if (op_Inequality(statusUIScr, 0, 0))
  {
    transform = get_transform(_statusUIScr, 0);
    v24 = Find(transform, "statusChara", 0);
    if (op_Inequality(v24, 0, 0))
    {
      localPosition = get_localPosition(v24);
      v27.y = localPosition.y;
      v27.z = localPosition.z;
      v27.x = 1460.0;
      set_localPosition(v24, v27);
    }
  }
}
