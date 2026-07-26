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
    ApplyChangeListIndex(0, 0, 0);
    fclRbnSwitchActiveSort(0, 0);
    CreateFontListRead(0, 0, 0);
    return 0;
}

// 0x119d4c0
s32 AcceptKeyListWindow(lstListWindow_t *plistwin, s32 flag) {
    DDS3_PADCHECK_PRESS(0);
    lstMoveCursor(0, 0);
    lstPageUp(0);
    lstPageDown(0);
    p2sdPlaySE(0);
    return 0;
}

// 0x11a07d0
void AcceptKeyRegistConfirm(fclEncyc_instance_tag *pinst) {
    CirculateDevilObject(0, 0);
    fclRbnSwitchActive(0, 0);
    fclClearSignal(0);
    fclSetVal(0, 0);
    fclScriptStart(0, 0, 0);
    SetButtonGuide(0, 0);
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
    CursorPos->Shift = v14 - v23;
    CursorPos->DrawShift = v14 - v23;
    CursorSize->Y = CursorSize->DefY + CursorInfo->StepY * (v14 - v23);
  }
  CursorPos->Index = v17;
  {
    v25 = plistwin->CursorInfo;
    v26 = v25->CursorSize;
    v27 = v25->CursorPos;
    v28 = v27->Shift;
    if (!v27->Shift)
    {
      Index = v27->Index;
      v34 = __OFSUB__(Index, 1);
      v35 = Index - 1;
      if (v35 < 0 != v34)
        return;
      v27->Index = v35;
      *&v27->Shift = 257;
      v32 = v26->DefY + v25->StepY;
    }
  }
  v25 = plistwin->CursorInfo;
  v26 = v25->CursorSize;
  v27 = v25->CursorPos;
  v28 = v27->Shift;
  if (!v27->Shift)
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
    fclRbnCalc(0);
    CalcMoveReadMainHelp(0);
    ReleaseFontExplain(0, 0);
    CirculateDevilObject(0, 0);
    CreateFontExplain(0);
    ResetReadMainRibbon(0);
    InitCameraForViewMode(0);
    SetBoundControl(0);
    fclRbnSwitchActive(0, 0);
    draw_status_off(0);
    StatusTitleOff();
    SetButtonGuide(0, 0);
}

// 0x11a5c10
void CalcPhaseReadStatus(fclEncyc_instance_tag *pinst) {
    FadeInRibbon(0);
    CheckStatusUI();
    StatusTitleOff();
    SetButtonGuide(0, 0);
    fclRbnCalc(0);
    CalcMoveReadMainHelp(0);
    MoveScreenOffset(0);
    CirculateDevilObject(0, 0);
    ResetReadMainRibbon(0);
    fclRbnSwitchActive(0, 0);
    CreateFontExplain(0);
    CMP_YM(0);
    draw_status_off(0);
    InitCameraForViewMode(0);
    SetBoundControl(0);
    PrepSummon(0);
    DrawSummonMoneyReset(0);
}

// 0x11aa4f0
void CalcPhaseReadSummon(fclEncyc_instance_tag *pinst) {
    FadeOutRibbon(0);
    fclRbnCalc(0);
    DrawSummonMoneyStart(0);
    CalcMoveReadMainHelp(0);
    MoveScreenOffset(0);
    fclChkMessageDraw(0);
    fclChkSignal(0);
    ExecSummon(0);
    p2sdPlaySE_20173184(0);
    FadeOutWindow();
    SetButtonGuide(0, 0);
    DrawSummonMoney(0, 0);
    DrawSummonMoneyReset(0);
}

// 0x11a2dd0
void CalcPhaseReadTop(fclEncyc_instance_tag *pinst) {
    fclRbnCalc(0);
    AcceptKeyChangeSort(0);
    AcceptKeyListWindow(0, 0);
    CreateFontListRead(0, 0, 0);
    CalcListElemColor(0, 0, 0, 0);
}

// 0x11abeb0
void CalcPhaseReadView(fclEncyc_instance_tag *pinst) {
    fclRbnCalc(0);
    CalcMoveReadMainHelp(0);
    CalcMoveViewModeRibbon(0);
    MoveScreenOffset(0);
    GetViewModeKey(0);
    ControlModel(0, 0, 0);
    ResetReadMainRibbon(0);
    reset_viewmode(0);
    fclRbnSwitchActive(0, 0);
    CreateFontExplain(0);
    draw_status_off(0);
    SetButtonGuide(0, 0);
}

// 0x11a15a0
void CalcPhaseRegistAll(fclEncyc_instance_tag *pinst) {
    CalcListElemColor(0, 0, 0, 0);
    fclChkMessageDraw(0);
    fclChkSignal(0);
    SetButtonGuide(0, 0);
    RegistAll(0);
    fclClearSignal(0);
    fclScriptStart(0, 0, 0);
    FadeOutWindow();
}

// 0x11a01f0
void CalcPhaseRegistConfirm(fclEncyc_instance_tag *pinst) {
    fclRbnCalc(0);
    CalcMoveRegistKeyHelp(0);
    fclChkMessageDraw(0);
    FadeOutWindow();
    fclChkSignal(0);
    fclEncycRegist(0, 0, 0);
    AcceptKeyRegistConfirm(0);
}

// 0x119d0b0
void CalcPhaseRegistTop(fclEncyc_instance_tag *pinst) {
    AcceptKeyListWindow(0, 0);
    SetButtonGuide(0, 0);
    dds3KillProcess(0, 0);
    fclClearSignal(0);
    fclScriptStart(0, 0, 0);
    CalcListElemColor(0, 0, 0, 0);
    fclChkSignal(0);
    FadeOutWindow();
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
    RequestModelLoad(0, 0);
    SetRecordToUnitCore(0, 0);
}

// 0x119f770
void ChangeDevilObjectRegistConfirm(s32 unitindex, fclEncyc_instance_tag *pinst) {
    RequestModelLoad(0, 0);
    datUnitWork_t__Copy(0, 0);
    SetRecordToUnit(0, 0);
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
    if (no != cmpModelTblGetMotNo(id))
    {
      v12 = no;
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
      mdlSmoothLoopMotionForUnity(v12, model, stat);
    }
  }
  mdlSetMotionSpeed(speed);
}

// 0x11a7c80
void CirculateDevilObject(fclEncyc_instance_tag *pinst, s32 dsn) {
    fclEncycGetNumForDLC();
    Log(0, 0);
    ChangeDevilObjectRegistConfirm(0, 0);
    ChangeDevilObjectReadMain(0, 0);
}

// 0x11afb30
void ClearMessage(void *obj) {
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
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(0);
    InitCameraForViewMode(0);
    InitModelPosRot(0, 0);
}

// 0x11a7030
void CreateFontExplain(fclEncyc_instance_tag *pinst) {
    itfMesMngInitialize(0, 0, 0);
    itfMesMngSetMesPosition(0, 0, 0);
    itfMesMngMarkBitStat(0, 0);
    itfMesMngSetDefaultSpeed(0, 0);
    itfMesMngRequestMessage(0, 0, 0, 0);
    itfMesMngGetFRQ(0, 0);
    frSetDrawSpeed(0, 0);
    frEnableMode(0);
    Get(0);
    GetEncyc(0);
    GetEncyc(0);
    frDisableMode(0);
    ClearMessage();
}

// 0x11a2650
void CreateFontListRead(fclEncyc_readtopwork_tag *pwork, s32 sort, s16 **pindex) {
    ReleaseFontList(0, 0);
    CMP_YM(0);
    fclEncycGetNumForDLC();
    Get(0);
    CMP_XM(0);
    GetEncyc(0);
    frwGetSmallFontFRQ2_20603280(0, 0, 0, 0, 0, 0);
    GetEncyc(0);
    frwGetSmallNumFontFRQ_20603536(0, 0, 0, 0, 0, 0);
    GetDevilParam(0, 0);
    fclEncycGetRatio2();
}

// 0x11aefd0
void CreateSortIndexByLevel(s16 ***pout) {
  u64 *v3;
  s32 num;

  num = 0;
  v3 = Allocate(fclEncyc_cmbLevelSortCallback);
  _ctor(v3, 0);
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
  num = DDS3_GBWK->encyc_record->num;
  FillIndex(pout, &num);
  Sort_3899856(*pout, 0, num, v3);
}

// 0x11b4620
s32 DebugProcDispBound(fclEncyc_instance_tag *pinst, fclEncyc_debug_t *pdebug, sdfDrawTag_t *pdrawtag) {
    DDS3_PAD2CHECK_TRIG(0);
    DDS3_PAD2CHECK_REP(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    Get(0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x11b3180
s32 DebugProcMenu(fclEncyc_instance_tag *pinst, fclEncyc_debug_t *pdebug, sdfDrawTag_t *pdrawtag) {
    DDS3_PAD2CHECK_REP(0);
    DDS3_PAD2CHECK_TRIG(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
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
    DDS3_PAD2CHECK_TRIG(0);
    DDS3_PAD2CHECK_REP(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
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
}

// 0x11a9be0
void DestPhaseReadStatus(fclEncyc_instance_tag *pinst) {
    ReleaseFontExplain(0, 0);
    itfMesMngRelease(0);
    frDestroyFontRequestNow(0);
    fclRbnRelease(0);
}

// 0x11a4950
void DestPhaseReadTop(fclEncyc_instance_tag *pinst) {
    ReleaseFontList(0, 0);
}

// 0x11a1480
void DestPhaseRegistConfirm(fclEncyc_instance_tag *pinst) {
    fclRbnRelease(0);
}

// 0x119e6f0
void DestPhaseRegistTop(fclEncyc_instance_tag *pinst) {
    ReleaseFontList(0, 0);
    dds3KillProcess(0, 0);
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
  v7 = Find(v6, StringLiteral_12359, 0);
  gameObject = get_gameObject(v7);
  v9 = get_transform(transform, 0);
  v10 = Find(v9, StringLiteral_16235, 0);
  v11 = get_gameObject(v10);
  if (get_activeSelf(v11))
    SetActive(v11, 0, 0);
  if (!get_activeSelf(gameObject))
    SetActive(gameObject, 1, 0);
  v12 = get_transform(gameObject, 0);
  v13 = Find(v12, StringLiteral_16143, 0);
  v14 = get_gameObject(v13);
  if (!get_activeSelf(v14))
    SetActive(v14, 1, 0);
  v15 = get_transform(gameObject, 0);
  v16 = Find(v15, StringLiteral_16222, 0);
  v17 = get_gameObject(v16);
  if (get_activeSelf(v17))
    SetActive(v17, 0, 0);
  v18 = get_transform(gameObject, 0);
  v19 = Find(v18, StringLiteral_16236, 0);
  v20 = get_gameObject(v19);
  if ((((alpha == 128) ^ get_activeSelf(v20)) & 1) != 0)
    SetActive(v20, alpha == 128, 0);
  v21 = get_transform(gameObject, 0);
  v22 = Find(v21, StringLiteral_16223, 0);
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
    draw_race_devil(0);
    itfMesMngGetFRQ(0, 0);
    return 0;
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
  v12 = Find(transform, StringLiteral_12359, 0);
  gameObject = get_gameObject(v12);
  v14 = get_transform(gameObject, 0);
  v15 = Find(v14, StringLiteral_16143, 0);
  v16 = get_gameObject(v15);
  v17 = get_transform(v16, 0);
  v18 = Find(v17, StringLiteral_16144, 0);
  v19 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v19);
  v20 = get_gameObject(v18);
  if (get_activeSelf(v20))
  {
    if (get_activeSelf(gameObject))
    SetActive(gameObject, 1, 0);
    if (bar)
  }
  v23 = get_gameObject(v18);
  SetActive(v23, 1, 0);
  if (!get_activeSelf(gameObject))
  if (bar)
  if (get_activeSelf(v16))
  {
    if (alpha != 16)
    {
      if (alpha)
      v21 = v16;
      v22 = 0;
    }
    v24 = get_transform(v16, 0);
    v25 = Find(v24, StringLiteral_16144, 0);
    v26 = get_gameObject(v25);
    if (!get_activeSelf(v26))
      SetActive(v26, 1, 0);
    v27 = get_transform(v16, 0);
    v28 = Find(v27, StringLiteral_16145, 0);
    v29 = get_gameObject(v28);
    if (!get_activeSelf(v29))
      SetActive(v29, 1, 0);
    v30 = get_transform(v16, 0);
    v31 = Find(v30, StringLiteral_16146, 0);
    v16 = get_gameObject(v31);
    if (!get_activeSelf(v16))
    {
      v21 = v16;
      v22 = 1;
      SetActive(v21, v22, 0);
    }
  }
  else  _Clear(v19);
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
        GetInteger(Component_object, StringLiteral_16147);
        if (mode == v35)
        {
          SetInteger(Component_object, StringLiteral_16147, 1);
          v43 = _get_Item(
                  v19,
                  mode);
          DrawModePanelText(v43, list, mode, 1);
        }
        else
        {
          SetInteger(Component_object, StringLiteral_16147, 0);
          v46 = _get_Item(
                  v19,
                  v35);
          DrawModePanelText(v46, list, v35, 0);
          v47 = _get_Item(
                  v19,
                  v35);
          v48 = get_transform(v47, 0);
          v50 = Find(v48, StringLiteral_16148, 0);
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
    DrawMessage(0);
    DrawExplainBack(0, 0);
    DrawModePanel(0, 0, 0, 0, 0);
    DrawReadMainHelp(0);
}

// 0x11a83d0
void DrawPhaseReadStatus(fclEncyc_instance_tag *pinst) {
    DrawExplainBack(0, 0);
    DrawModePanel(0, 0, 0, 0, 0);
    DrawReadMainHelp(0);
}

// 0x11aabd0
void DrawPhaseReadSummon(fclEncyc_instance_tag *pinst) {
    DrawBackBlackBoard(0, 0);
    DrawModePanel(0, 0, 0, 0, 0);
    DrawReadStatusMoney(0);
    DrawReadMainHelp(0);
    DrawSummonMoney(0, 0);
    UpdateDrawFlag(0);
}

// 0x11a3460
void DrawPhaseReadTop(fclEncyc_instance_tag *pinst) {
    DrawCaption2(0, 0, 0);
    GetGameObject(0);
    DrawListWindowBack(0, 0);
    DrawReadListwinElem(0, 0, 0);
    UpdateItemCursor(0, 0, 0, 0);
    DrawReadListSortBar(0);
    Set2(0, 0, (sdfColor_t){0}, 0);
    fclEncycGetRatio2();
    Set(0, 0);
}

// 0x11ae160
void DrawPhaseReadView(fclEncyc_instance_tag *pinst) {
    DrawBackBlackBoard(0, 0);
    InitModelPosRot(0, 0);
    mdlLink(0, 0);
    StatusTitleOff();
    DrawModePanel(0, 0, 0, 0, 0);
    DrawReadMainHelp(0);
}

// 0x119fda0
void DrawPhaseRegistConfirm(fclEncyc_instance_tag *pinst) {
    DrawModePanel(0, 0, 0, 0, 0);
}

// 0x119da40
void DrawPhaseRegistTop(fclEncyc_instance_tag *pinst) {
    DrawCaption2(0, 0, 0);
    GetGameObject(0);
    DrawListWindowBack(0, 0);
    DrawRegistListwinElem(0, 0);
    UpdateItemCursor(0, 0, 0, 0);
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
    }
    else
    {
      v23 = phase;
      if (*(v2 + 6) > phase)
      {
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
  Item = object___get_Item(ListObjs, StringLiteral_16097);
  v6 = object___get_Item(ListObjs, StringLiteral_16099);
  Component_object = GetComponent_object_(Item);
  SetInteger(Component_object, StringLiteral_16260, 1 - sort);
  v8 = GetComponent_object_(v6);
  SetInteger(v8, StringLiteral_16260, sort);
}

// 0x11b0d80
void DrawReadListwinCaption(fclEncyc_instance_tag *pinst) {
    sdfIVector4_t__Create(0, 0, 0, 0);
    sdfIVector2_t__Create(0, 0);
    sdfDrawTagInit(0);
    itfMiscDrawSpritePlanePrim(0, 0, 0, 0, 0);
    itfMiscDrawSpritePrim(0, 0, 0, 0, 0, 0, 0);
    itfMiscDrawSpritePrim2(0, 0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x11a3830
void DrawReadListwinElem(void *obj, void *rule, fclEncyc_instance_tag *pinst) {
    DrawBackPanel(0);
    DrawScrollBar(0, 0, 0);
    fclEncycGetNumForDLC();
    Get(0);
    GetEncyc(0);
    RepColTag(0, 0);
    GetEncyc(0);
    Set2(0, 0, (sdfColor_t){0}, 0);
    GetDevilParam(0, 0);
    fclEncycGetRatio2();
    Set(0, 0);
}

// 0x11a88c0
void DrawReadMainHelp(fclEncyc_instance_tag *pinst) {
    sdfDrawTagInit(0);
    itfMiscDrawSpritePrim(0, 0, 0, 0, 0, 0, 0);
    itfMiscDrawSpritePrim2(0, 0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
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

  Item = object___get_Item(ListObjs, StringLiteral_16219);
  v5 = object___get_Item(CCtrObjs, StringLiteral_16087);
  maka = DDS3_GBWK->maka;
  white = get_white();
  Set(v5, maka, white, 0, 0);
  if (!get_activeSelf(Item))
    SetActive(Item, 1, 0);
  statusUIScr = _statusUIScr;
  if (!op_Equality(statusUIScr, 0, 0))
  {
    transform = get_transform(_statusUIScr, 0);
    v14 = Find(transform, StringLiteral_12359, 0);
    gameObject = get_gameObject(v14);
    v16 = get_transform(gameObject, 0);
    v17 = Find(v16, StringLiteral_16143, 0);
    v18 = get_gameObject(v17);
    v19 = get_transform(v18, 0);
    v20 = Find(v19, StringLiteral_16144, 0);
    v21 = get_gameObject(v20);
    if (get_activeSelf(v21))
      SetActive(v21, 0, 0);
    v22 = get_transform(v18, 0);
    v23 = Find(v22, StringLiteral_16145, 0);
    v24 = get_gameObject(v23);
    if (get_activeSelf(v24))
      SetActive(v24, 0, 0);
    v25 = get_transform(v18, 0);
    v26 = Find(v25, StringLiteral_16146, 0);
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
    sdfDrawTagInit(0);
    itfMiscDrawSpritePrim(0, 0, 0, 0, 0, 0, 0);
    itfMiscDrawSpritePrim2(0, 0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x119de20
void DrawRegistListwinElem(void *obj, fclEncyc_instance_tag *pinst) {
    DrawBackPanel(0);
    DrawScrollBar(0, 0, 0);
    IsDLC();
    Get(0);
    GetEncyc(0);
    RepColTag(0, 0);
    GetEncyc(0);
    Set2(0, 0, (sdfColor_t){0}, 0);
    datGetLevelForDraw(0);
}

// 0x119fb90
void DrawStatus1Shot(fclEncyc_instance_tag *pinst) {
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
  GameObject = GetGameObject(StringLiteral_16086);
  if (((get_activeSelf(GameObject) ^ v3) & 1) != 0)
    SetActive(GameObject, v3, 0);
  Item = object___get_Item(ListObjs, StringLiteral_16087);
  if (((get_activeSelf(Item) ^ v3) & 1) != 0)
    SetActive(Item, v3, 0);
  v10 = !v3;
  v11 = object___get_Item(ListObjs, StringLiteral_16096);
  if (((get_activeSelf(v11) ^ v3) & 1) == 0)
    SetActive(v11, v10, 0);
  v14 = object___get_Item(ListObjs, StringLiteral_16109);
  if (((get_activeSelf(v14) ^ v3) & 1) == 0)
    SetActive(v14, v10, 0);
  v17 = object___get_Item(ListObjs, StringLiteral_16107);
  if (((get_activeSelf(v17) ^ v3) & 1) == 0)
    SetActive(v17, v10, 0);
  v20 = object___get_Item(ListObjs, StringLiteral_16108);
  if (((get_activeSelf(v20) ^ v3) & 1) == 0)
    SetActive(v20, v10, 0);
  v23 = object___get_Item(ListObjs, StringLiteral_16094);
  if (((get_activeSelf(v23) ^ v3) & 1) == 0)
    SetActive(v23, v10, 0);
  v26 = object___get_Item(ListObjs, StringLiteral_16095);
  if (((get_activeSelf(v26) ^ v3) & 1) == 0)
    SetActive(v26, v10, 0);
  v29 = object___get_Item(ListObjs, StringLiteral_16090);
  if (((get_activeSelf(v29) ^ v3) & 1) == 0)
    SetActive(v29, v10, 0);
  v32 = object___get_Item(ListObjs, StringLiteral_16094);
  if (((get_activeSelf(v32) ^ v3) & 1) == 0)
    SetActive(v32, v10, 0);
  v35 = object___get_Item(ListObjs, StringLiteral_16084);
  if (((get_activeSelf(v35) ^ v3) & 1) == 0)
    SetActive(v35, v10, 0);
  v38 = object___get_Item(ListObjs, StringLiteral_16112);
  if (((get_activeSelf(v38) ^ v3) & 1) == 0)
    SetActive(v38, v10, 0);
  v41 = object___get_Item(ListObjs, StringLiteral_16110);
  if (((get_activeSelf(v41) ^ v3) & 1) == 0)
    SetActive(v41, v10, 0);
}

// 0x11a2ce0
void DrawSummonMoneyReset(fclEncyc_instance_tag *pinst) {
  fclEncyc_instance_tag_o *v3;
  Il2CppObject *Item;
  Il2CppObject *Component_object;

  DrawSummonMoney(v3, 0);
  Item = object___get_Item(ListObjs, StringLiteral_16087);
  if (!get_activeSelf(Item))
    SetActive(Item, 1, 0);
  Component_object = GetComponent_object_(Item);
  DisplayOn(Component_object);
}

// 0x11aa450
void DrawSummonMoneyStart(fclEncyc_instance_tag *pinst) {
  Il2CppObject *Item;
  Il2CppObject *Component_object;

  Item = object___get_Item(ListObjs, StringLiteral_16087);
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
      if (++v5 >= *num)
    }
    v11 = *pout + 2 * v6++;
    *(v11 + 16) = v5;
  }
  v6 = 0;
  *num = v6;
}

// 0x11b05e0
s32 GetAnalogPad(void) {
    return 0;
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
          }
          else
          {
            IsDLC = 0;
            if (v8 >= LODWORD(unitwork->max_length))
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
    GetAnalogPad();
    DDS3_PADCHECK_TRIG(0);
    DDS3_PADCHECK_PRESS2(0);
    return 0;
}

// 0x11a7480
void InitCameraForViewMode(fclEncyc_instance_tag *pinst) {
    ResetCameraPos(0);
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
}

// 0x11a4aa0
void InitPhaseReadStatus(fclEncyc_instance_tag *pinst) {
    StatusFrontProcess(0, 0);
    CMP_YM(0);
    CMP_XM(0);
    dds3GetActiveScene();
    dds3VisibleSceneBasic(0, 0);
    ChangeDevilObjectReadMain(0, 0);
    ResetReadMainRibbon(0);
    fclRbnInit(0, 0, 0, 0);
    fclRbnSetPara(0, 0, 0, 0, 0, 0, 0, 0);
    RegistModePanel(0, 0);
    SetButtonGuide(0, 0);
}

// 0x11a1a10
void InitPhaseReadTop(fclEncyc_instance_tag *pinst) {
    WindowDispOff(0);
    StatusBackProcess(0);
    fclRbnInitSort(0);
    fclRbnSetPara(0, 0, 0, 0, 0, 0, 0, 0);
    sdfIVector4_t__Create(0, 0, 0, 0);
    fclEncycGetNumForDLC();
    InitListWindow(0, 0, 0, 0, 0, 0, 0, 0);
    PopListwinCursor(0, 0, 0);
    CreateFontListRead(0, 0, 0);
    draw_status_off(0);
    SetButtonGuide(0, 0);
    RemakeFldSky();
    DrawSummonMoneyReset(0);
}

// 0x119e960
void InitPhaseRegistConfirm(fclEncyc_instance_tag *pinst) {
    StatusFrontProcess(0, 0);
    CMP_XM(0);
    CMP_YM(0);
    dds3GetActiveScene();
    dds3VisibleSceneBasic(0, 0);
    ChangeDevilObjectRegistConfirm(0, 0);
    fclRbnInit(0, 0, 0, 0);
    fclRbnSetPara(0, 0, 0, 0, 0, 0, 0, 0);
    RegistModePanel(0, 0);
    DrawStatus1Shot(0);
    DrawPhaseRegistConfirm(0);
    DispRegistConfirm(0);
    SetButtonGuide(0, 0);
}

// 0x119be10
void InitPhaseRegistTop(fclEncyc_instance_tag *pinst) {
    WindowDispOff(0);
    StatusBackProcess(0);
    GetValidUnitIndex(0);
    sdfIVector4_t__Create(0, 0, 0, 0);
    InitListWindow(0, 0, 0, 0, 0, 0, 0, 0);
    PopListwinCursor(0, 0, 0);
    fclClearSignal(0);
    fclScriptStart(0, 0, 0);
    draw_status_off(0);
    SetButtonGuide(0, 0);
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
  }
  if (pinst->phase == 7)
  {
    statusUIScr = _statusUIScr;
    if (op_Inequality(statusUIScr, 0, 0))
    {
      transform = get_transform(_statusUIScr, 0);
      v11 = Find(transform, StringLiteral_16220, 0);
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
    GetDevilParam(0, 0);
    fclEncycGetRatio2();
    fclSetVal(0, 0);
    datSearchDevilStock(0);
    datCheckStockFull();
    CheckLevelLimit(0, 0);
    fclClearSignal(0);
    fclScriptStart(0, 0, 0);
    dds3GetProcessData(0);
    itfMesMngSetVar(0, 0, 0, 0);
    return 0;
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
  v6 = Find(transform, StringLiteral_16237, 0);
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
  fclEncyc_c *v2;
  struct fclEncyc_StaticFields *static_fields;

  static_fields = v2->static_fields;
  if (static_fields->g_pdebug)
  {
    static_fields->g_pdebug = 0;
  }
}

// 0x11a9dd0
void ReleaseFontExplain(fclEncyc_instance_tag *pinst, s32 release_mesmng) {
    itfMesMngRequestMessageRelease(0, 0);
    itfMesMngRelease(0);
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

  else if (cmpGetModelMinorNo() == id)
  {
    return;
  }
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
    SetCameraLightParam(0);
}

// 0x11a7720
void SetBoundControl(fclEncyc_instance_tag *pinst) {
    Get(0);
}

// 0x11affd0
void SetCameraLightParam(fclEncyc_instance_tag *pinst) {
    dds3GetFrameID();
    dds3SetSoftenBias(0, 0, 0);
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    dds3SetFogColor(0, (sdfVector4_t){0});
    dds3SetFogPara(0, 0, 0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdf3DMakeScreenParam(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__STOREMATRIX(0);
    sdf3DMakeViewportPacket(0, 0, 0);
    sdf3DSetCamera(0, 0);
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
  v6 = &StringLiteral_16118;
  if (mode)
    v6 = &StringLiteral_16086;
  v7 = *v6;
  GameObject = GetGameObject(v7);
  if (get_activeSelf(GameObject))
    SetActive(GameObject, 0, 0);
  v10 = GetGameObject(StringLiteral_16142);
  if (get_activeSelf(v10))
    SetActive(v10, 0, 0);
  v12 = GetGameObject(StringLiteral_16127);
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
      }
      else
      {
        v23 = 0;
        phase = g_pinst->phase;
        next_phase = g_pinst->next_phase;
        if (phase == next_phase)
        {
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
    }
  }
  return 0;
}

// 0x11b57c0
s32 draw_race_devil(fclEncyc_instance_tag *pinst) {
    return 0;
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
    v9 = Find(transform, StringLiteral_16261, 0);
    v11 = get_gameObject(v9);
    if (op_Inequality(v11, 0, 0) && get_activeSelf(v11))
      SetActive(v11, 0, 0);
    v12 = get_transform(gameObject, 0);
    v13 = Find(v12, StringLiteral_16262, 0);
    v15 = get_gameObject(v13);
    if (op_Inequality(v15, 0, 0)
      && ((get_activeSelf(v15) ^ v2) & 1) == 0)
    {
      SetActive(v15, !v2, 0);
    }
    v16 = get_transform(gameObject, 0);
    v17 = Find(v16, StringLiteral_16263, 0);
    v19 = get_gameObject(v17);
    if (op_Inequality(v19, 0, 0)
      && ((get_activeSelf(v19) ^ v2) & 1) == 0)
    {
      SetActive(v19, !v2, 0);
    }
    v20 = get_transform(gameObject, 0);
    v21 = Find(v20, StringLiteral_16264, 0);
    v23 = get_gameObject(v21);
    if (op_Inequality(v23, 0, 0)
      && ((get_activeSelf(v23) ^ v2) & 1) == 0)
    {
      SetActive(v23, !v2, 0);
    }
    v24 = get_transform(gameObject, 0);
    v25 = Find(v24, StringLiteral_12358, 0);
    v27 = get_gameObject(v25);
    if (op_Inequality(v27, 0, 0)
      && ((get_activeSelf(v27) ^ v2) & 1) == 0)
    {
      SetActive(v27, !v2, 0);
    }
    v28 = get_transform(gameObject, 0);
    v29 = Find(v28, StringLiteral_12281, 0);
    v31 = get_gameObject(v29);
    if (op_Inequality(v31, 0, 0)
      && ((get_activeSelf(v31) ^ v2) & 1) == 0)
    {
      SetActive(v31, !v2, 0);
    }
    v32 = get_transform(gameObject, 0);
    v33 = Find(v32, StringLiteral_12359, 0);
    v34 = get_gameObject(v33);
    v35 = get_transform(v34, 0);
    v36 = Find(v35, StringLiteral_16222, 0);
    v37 = get_gameObject(v36);
    if (get_activeSelf(v37))
      SetActive(v37, 0, 0);
    v38 = get_transform(v34, 0);
    v39 = Find(v38, StringLiteral_16223, 0);
    v41 = get_gameObject(v39);
    ClearMessage(v41);
    SetInteger(statusUIScr->infoAnim, StringLiteral_12357, v2);
  }
}

// 0x1197000
s32 fclEncycCheckRegistable(void) {
  return GetValidUnitIndex(0);
}

// 0x11b5280
dds3ProcessFunc_t *fclEncycDebugProc(dds3ProcessID_t *proc_id) {
    sdfDrawTagInit(0);
    sdfDrawTagLinkOt(0, 0);
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
    while (1)
    {
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
    }
  }
}

// 0x11b56e0
dds3ProcessFunc_t *fclEncycDebugShutdown(dds3ProcessID_t *proc_id) {
  fclEncyc_c *v2;
  struct fclEncyc_StaticFields *static_fields;

  static_fields = v2->static_fields;
  if (static_fields->g_pdebug)
  {
    static_fields->g_pdebug = 0;
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
    while (1)
    {
      pelem = DDS3_GBWK->encyc_record->pelem;
      if (pelem->m_Items[v4]->id == 191)
      {
        v5 &= GetOrUsed(2);
      }
      if (num - 1 == v4)
        break;
      ++v4;
    }
  }
  return num - ((v5 & 1) == 0);
}

// 0x11b4f90
s32 fclEncycGetRatio(void) {
  s32 num;
  s32 result;

  num = DDS3_GBWK->encyc_record->num;
  result = 100 * num / (LODWORD(ZensyoDevilID->max_length) - 1);
  if (num >= 1 && result <= 1)
    return 1;
  return result;
}

// 0x11a4570
s32 fclEncycGetRatio2(void) {
    return 0;
}

// 0x11b4c80
void fclEncycInitRecord(s32 mode) {
  if (!mode)
    DDS3_GBWK->encyc_record->num = 0;
  g_pinst = 0;
  g_pdebug = 0;
}

// 0x119bb10
s32 fclEncycKillProcess(void) {
    UnloadCollectionBook();
    StatusBackProcess(0);
    dds3KillProcess(0, 0);
    SetButtonGuide(0, 0);
    RemakeFldSky();
    return 0;
}

// 0x11a0c90
s32 fclEncycRegist(datUnitWork_t *punit, s32 overwrite, bool update) {
    IsDLC();
    fclEncycSearch(0);
    dds3Printf(0, 0);
    SetElem(0, 0);
    fclEncycGetRatio2();
    evtBitOff(0);
    evtBitOn(0);
    return 0;
}

// 0x11b4d40
s32 fclEncycRegist2(fclencyceelem_t *pelemsrc, s32 overwrite) {
    fclEncycSearch(0);
    dds3Printf(0, 0);
    fclencyceelem_t__Clear(0);
    fclencyceelem_t__Copy(0, 0);
    fclEncycGetRatio2();
    evtBitOn(0);
    evtBitOff(0);
    return 0;
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
    InitializeInstance(0);
    LoadCollectionBook();
    fclEncycGetRatio2();
    CreateSortIndexByRace(0);
    CreateSortIndexByLevel(0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
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
      SetInteger(Animator, StringLiteral_4572, motion);
  }
}

// 0x11ada90
void reset_viewmode(fclEncyc_instance_tag *pinst) {
    InitCameraForViewMode(0);
    InitModelPosRot(0, 0);
}
