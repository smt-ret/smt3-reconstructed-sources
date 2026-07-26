#include "types.h"

typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct rstData_t rstData_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static rstData_t *GBWK;
static s8 gProcessStat;
static void *oResult2_UI;

void CampDispOff(dds3DefaultMain *this, bool titlemode);
void CampDispOn(dds3DefaultMain *this, bool titlemode);
void ClearResult2UI(void);
u8 Get(s32 id);
char *GetPlatformStr(void);
void LoadLocalizeText(char *key, char *filename);
void Remove(char *key);
void WindowDispOff(bool sw);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void evtStartEvent(s32 no);
void fclClearSignal(s8 Idx);
s8 fclDestroyMessage(void);
void fclFreeStage(void);
s8 fclInitMessage(void *pData);
sdfTexHandle_t *fclLoadTexture(char *pFileName);
void fclSetSelMessagePos(s8 SelPos);
s8 fclSetVal(s8 Idx, s32 Val);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
void rstCreateTargetList(rstData_t **pData);
void *rstDestroyResult2(dds3ProcessID_t *PID);
rstData_t *rstInit(cmpSeqInfo_t *pParentSeqInfo);
void *sdfDevLoadFileUnity(char *aFilename, void **aTopPtr, s32 aSizePtr, char *akey);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
void sdfTexFree(sdfTexHandle_t *aHandle);

// 0x1569220
void ClearResult2UI(void) {
  UnityEngine_Object_o *oResult2_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oResult2_UI, 0, 0))
  {
    v6 = oResult2_UI;
    Destroy_27360000(v6);
    oResult2_UI = 0;
  }
}

// 0x15693f0
void *GetResult2UI(void) {
  return oResult2_UI;
}

// 0x1560f50
void SetPointAnime(s32 point) {
  if (point < 10)
  {
    if (point < 1)
    {
      SetInteger(_statusUIScr->pointAnim, StringLiteral_21942, 1);
    }
    else
    {
      SetInteger(_statusUIScr->pointAnim, StringLiteral_21942, 0);
    }
  }
  else
  {
    SetInteger(_statusUIScr->pointAnim, StringLiteral_21942, 5);
  }
}

// 0x1568120
u32 rstCalcExpFromLevel(u8 Index, s32 Level) {
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *pStock;

  pStock = 0;
  unitwork = DDS3_GBWK->unitwork;
  pStock = unitwork->m_Items[Index];
  return cmbCalcLevelUpExp(&pStock, Level);
}

// 0x1568030
u8 rstCalcLevelFromExp(u8 Index, u32 Exp) {
  struct datUnitWork_t_array *unitwork;
  s32 v8;
  u16 level;
  datUnitWork_t_o *pStock;

  pStock = 0;
  unitwork = DDS3_GBWK->unitwork;
  pStock = unitwork->m_Items[Index];
  v8 = Exp - pStock->exp;
  level = pStock->level;
  return cmbGetLevelUpCount(&pStock, v8) + level;
}

// 0x1567af0
s8 rstChkEvoAct(void) {
  if (dds3SearchProcessName(StringLiteral_21934))
    return 1;
  evtBitOff(3717);
  return 0;
}

// 0x1567e20
s32 rstChkLevelUpTarget(datUnitWork_t **pStock) {
  if (((*pStock)->flag & 1) == 0 || ((*pStock)->badstatus & 0x800) != 0)
    return 0;
  return cmbGetLevelUpCount(pStock, 0) > 0;
}

// 0x1569320
s8 rstChkResult2Process(void) {
  struct rstinit_StaticFields *static_fields;
  s32 gProcessStat;

  static_fields = rstinit->static_fields;
  gProcessStat = static_fields->gProcessStat;
  if (gProcessStat == 1)
    return 1;
  if (gProcessStat != 2)
    return 0;
  static_fields->gProcessStat = 0;
  return 0;
}

// 0x1567ec0
s8 rstChkResultEntry(void) {
  u64 v3;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v7;
  datUnitWork_t_o *pStock;

  pStock = 0;
  v3 = 0;
  while (1)
  {
    unitwork = DDS3_GBWK->unitwork;
    v7 = unitwork->m_Items[v3];
    pStock = v7;
    if ((byte_3F59DE7 & 1) == 0)
    if ((v7->flag & 1) != 0 && (v7->badstatus & 0x800) == 0)
    {
      if (cmbGetLevelUpCount(&pStock, 0) > 0)
        return 1;
    }
    if (v3++ >= 0xF)
      return 0;
  }
}

// 0x1568200
void rstCreateTargetList(rstData_t **pData) {
}

// 0x1568ba0
void *rstDestroyResult2(dds3ProcessID_t *PID) {
  struct sdfTexHandle_t_array *TexHandle;
  sdfTexHandle_t_o *v7;
  s64 *v14;
  System_String_o *PlatformStr;
  System_String_o *v17;

  if (GBWK)
  {
    cmpDynamicTexReset();
    TexHandle = GBWK->TexHandle;
    v7 = TexHandle->m_Items[0];
    sdfTexFree(v7);
    fclDestroyMessage();
    cmpModelFreeResource();
    cmpModelEnd();
    cmpTerminatePanelEff();
    cmpSetModelMoveMode(0);
    WindowDispOff(0);
    GBWK = 0;
    gProcessStat = 2;
    p2sdFadeOut(2818048);
    if (evtBitCheck(3712))
    {
      v14 = &StringLiteral_21939;
    }
    else
    {
      v14 = &StringLiteral_21940;
    }
    Remove(*v14, 0);
    Remove(StringLiteral_5047, 0);
    Remove(StringLiteral_21941, 0);
    Remove(StringLiteral_16177, 0);
    Remove(StringLiteral_12292, 0);
    PlatformStr = GetPlatformStr();
    v17 = Concat_5224608(StringLiteral_12292, PlatformStr);
    Remove(v17, 0);
  }
  CampDispOff(kernelObject, 0);
  cmpRemoveObjUI(1);
  return 0;
}

// 0x1568620
rstData_t *rstInit(cmpSeqInfo_t *pParentSeqInfo) {
  u64 *v3;
  u64 *v4;
  cmpSeqInfo_t_o *v7;
  cmpCursorInfo_t_o *v8;
  Il2CppObject *v13;
  u64 v16;
  s64 *Texture;
  s64 *v19;
  u64 v20;
  sdfTexHandle_t_o *v21;
  System_String_o *v29;
  s64 *v30;
  System_String_o *PlatformStr;
  System_String_o *v33;
  System_String_o *v34;
  System_String_o *v35;
  rstData_t_o *pData;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(rstData_t);
  rstData_t___ctor(v4);
  pData = v4;
  v4[3] = v3;
  v7 = v4[2];
  cmpInitSeqInfo(v7, pParentSeqInfo);
  *(v4[2] + 17) = 0;
  *(v4[2] + 19) = 0;
  *(v4[2] + 20) = 1;
  v8 = v4[14];
  *(v4 + 74) = 1;
  *(v4 + 19) = 0;
  *(v4 + 72) = -128;
  cmpInitCursorSize(v8, 0, 0, 0, 0, 0);
  cmpInitCursorInfo(v4[14], 5u, 5u, 0);
  cmpInitCursorInfo(v4[17], 8u, 8u, 0);
  cmpModelInit();
  Clear(v4[16], 0, *(v4[16] + 24), 0);
  cmpStatResetRaceEffect();
  sdfDevLoadFileUnity(StringLiteral_21936, v4 + 22, 0, StringLiteral_5039);
  sdfDevLoadFileUnity_25061072(StringLiteral_21937, v4 + 24, 0, StringLiteral_5039);
  v13 = v4[24];
  fclInitMessage(v13);
  fclSetSelMessagePos(0);
  cmpStartProcessPanelEff(0);
  cmpSetModelMoveMode(1);
  v16 = v4[26];
  Texture = fclLoadTexture(StringLiteral_21938);
  v19 = Texture;
  *(v16 + 32) = v19;
  v20 = v4[26];
  v21 = *(v20 + 32);
  cmpDynamicTexSet(v21);
  rstCreateTargetList(&pData);
  *(v4 + 54) = 691;
  dds3FadeIn(0, 0, 0, 0xFu);
  p2sdPlayBGM(2818048);
  CampDispOn(kernelObject, 0);
  cmpSetupObjUI(-1, 0);
  if (evtBitCheck(3712))
  {
    v29 = StringLiteral_4611;
    v30 = &StringLiteral_21939;
  }
  else
  {
    v29 = StringLiteral_4611;
    v30 = &StringLiteral_21940;
  }
  LoadLocalizeText(v29, *v30);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5047);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_21941);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_16177);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_12292);
  PlatformStr = GetPlatformStr();
  v33 = Concat_5224608(StringLiteral_4611, PlatformStr);
  v34 = GetPlatformStr();
  v35 = Concat_5224608(StringLiteral_12292, v34);
  LoadLocalizeText(v33, v35);
  return v4;
}

// 0x1566230
void rstInitEvoAct(void) {
  u16 id;
  System_Single_array *v7;
  f32 v9;
  s32 v10;
  System_Single_array *pPos;

  pPos = NewSpecific(f32, 3u);
  fclClearSignal(0);
  fclClearSignal(1);
  fclSetVal(2, 1);
  fclSetVal(3, 1);
  fclSetVal(4, GBWK->pCurrentStock->id);
  fclSetVal(5, GBWK->EvoDevil->id);
  id = GBWK->EvoDevil->id;
  cmpModelTblGetPos(id, &pPos);
  v7 = pPos;
  v9 = pPos->m_Items[1];
  v10 = GBWK->EvoDevil->id;
  v7->m_Items[1] = v9 * Get(v10, 0)->formscale;
  fclSetVal(6, pPos->m_Items[1]);
  evtStartEvent(809);
  GBWK->EvoActStatFlag = 0;
  evtBitOn(3717);
}

// 0x1561cd0
void rstInitParamOfs(rstData_t **pData) {
  Clear((*pData)->ParamOfs, 0, (*pData)->ParamOfs->max_length, 0);
}

// 0x1567b90
void rstKillEvoAct(void) {
  fclFreeStage();
  Write(StringLiteral_21935, 0);
}

// 0x1569140
void rstResult2ProcessEnd(void) {
    dds3KillProcessName(0, 0);
    rstDestroyResult2(0);
    ClearResult2UI();
}

// 0x1568f00
void rstResult2ProcessStart(void) {
  u64 *v3;
  Il2CppObject *data;
  u64 *v6;
  u64 *v7;
  u64 *v8;

  else if (GBWK)
  {
    return;
  }
  GBWK = rstInit(0);
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_rstcalc_rstCalc__);
  data = GBWK;
  dds3StartProcess(StringLiteral_21943, 0x405u, 1, 1, v3, 0, 0, 0, data, 0);
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_rstdraw_rstDraw__);
  dds3StartProcess(
    StringLiteral_21944,
    0x2B15u,
    1,
    1,
    v6,
    0,
    0,
    0,
    GBWK,
    0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_rstupdate_rstUpdate__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_rstinit_rstDestroyResult2__);
  dds3StartProcess(
    StringLiteral_21945,
    0x5211u,
    1,
    1,
    v7,
    0,
    v8,
    0,
    GBWK,
    0);
  gProcessStat = 1;
}

// 0x1567c30
void rstSetTestParam(void) {
  datUnitWork_t_array *unitwork;
  s32 v5;
  struct datUnitWork_t_array *v7;
  struct datUnitWork_t_array *v10;
  struct datUnitWork_t_array *v12;

  unitwork = DDS3_GBWK->unitwork;
  v5 = cmbAddDefaultDevilToStock(0x3Du, unitwork, 0xCu, 4);
  if (v5 >= 1)
  {
    v7 = DDS3_GBWK->unitwork;
    v7->m_Items[v5]->flag = 1;
  }
  v10 = DDS3_GBWK->unitwork;
  v10->m_Items[0]->exp += 9999;
  v12 = DDS3_GBWK->unitwork;
  v12->m_Items[4]->exp += 100 * v12->m_Items[4]->level;
}

// 0x1562730
void rstTerminateResult2(void) {
  struct rstData_t_o *GBWK;

  if (GBWK)
  {
    GBWK->SeqInfo->Flag |= 0x10u;
  }
}
