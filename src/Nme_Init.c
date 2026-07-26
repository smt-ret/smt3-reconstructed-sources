#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nmeData_t nmeData_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 name_count;
static s32 char_sel;
static char nmeCharTexFile[UNKNOWN_ARRAY_SIZE];
static nmeData_t *GBWK;
static s8 gProcessStat;
static char tblDefName[UNKNOWN_ARRAY_SIZE];
static s8 nmeTblList[UNKNOWN_ARRAY_SIZE];
static char *nmeTblList22[UNKNOWN_ARRAY_SIZE];
static char *nmeTblList24[UNKNOWN_ARRAY_SIZE];
static s32 dds3KernelDebugSignOrg;
static u8 gFadeCol[UNKNOWN_ARRAY_SIZE];
static void *cursor_UI;
static void *oName_UI;

void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void DefNameDraw(void);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void NameInit(void);
void NameInit2(void);
void dds3FadeClear(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
sdfTexHandle_t *fclLoadTexture(char *pFileName);
void frDelFontStyle(u8 StyleNo);
nmeData_t *nmeInit(s8 TargetNo, s8 EntryMode, cmpSeqInfo_t *pParentSeqInfo);
void nmeInitEntryType(s8 EntryType, nmeData_t **pData);
void nmeInitFuncCursor(s8 CursorPos, nmeData_t **pData);
void nmeInitInputMode(s8 InputMode, nmeData_t **pData);
void nmeNameProcessStart(s8 TargetNo, s8 EntryMode, s8 DebugMode);
void nmeSetDefaultNameCore(s8 TargetNo, s8 Type, nmeData_t **pData);
void nmeSetFontImageToGW(s8 TargetNo, nmeData_t **pData);
void nmeTexFree(nmeData_t **pData);
void nmeTexLoad(s8 TargetNo, nmeData_t **pData);
s32 scrGetIntPara(s32 n);
void scrSetIntReturnValue(s32 i);
void sdfTexFree(sdfTexHandle_t *aHandle);

// 0x18a76f0
void ClearNameUI(void) {
  UnityEngine_Object_o *oName_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oName_UI, 0, 0))
  {
    v6 = oName_UI;
    Destroy_27360000(v6);
    oName_UI = 0;
  }
}

// 0x18a7370
void *GetoNameUI(void) {
  return oName_UI;
}

// 0x18a4900
s32 SDF_ABORT1(char *a) {
  return 0;
}

// 0x18a60b0
s8 nmeChkEntryType(nmeData_t **pData) {
  if ((*pData)->EntryType > 1u)
    return 2;
  else
    return ((*pData)->InputPos + 3) > 6u;
}

// 0x18a7480
s8 nmeChkNameProcess(void) {
  return gProcessStat == 1;
}

// 0x18a5180
dds3ProcessFunc_t *nmeDestroyName(dds3ProcessID_t *PID) {
  Nme_Init_c *v3;
  struct Nme_Init_StaticFields *static_fields;
  struct nmeData_t_o *GBWK;
  s32 dds3KernelDebugSignOrg;

  static_fields = v3->static_fields;
  GBWK = static_fields->GBWK;
  if (GBWK)
  {
    nmeSetFontImageToGW(GBWK->TargetNo, &static_fields->GBWK);
    nmeTexFree(&GBWK);
    frDelFontStyle(4u);
    GBWK = 0;
    gProcessStat = 2;
    dds3KernelDebugSign = dds3KernelDebugSignOrg;
    dds3FadeClear();
  }
  return 0;
}

// 0x18a5f70
void nmeFadeOut(void) {
  struct System_Byte_array *gFadeCol;
  u32 max_length;
  struct System_Byte_array *v5;
  u32 v6;
  u32 v7;
  u32 v9;

  max_length = gFadeCol->max_length;
  v5 = gFadeCol;
  v6 = gFadeCol->m_Items[0];
  v7 = v5->m_Items[1];
  v9 = v5->m_Items[2];
  dds3FadeOut(v6, v7, v9, 0x1Eu);
}

// 0x18a6100
s8 nmeGetInputCharMax(nmeData_t **pData) {
  s32 v3;

  if ((*pData)->EntryType >= 2u)
    v3 = 8;
  else
    v3 = 4;
  return ToSByte_2956832(v3);
}

// 0x18a60e0
s32 nmeGetInputCharMaxCore(s32 Type) {
  if (!Type)
    return 4;
  if (Type == 1)
    return 4;
  return 8;
}

// 0x18a6630
s8 nmeGetInputModeColumnMax(s8 InputMode) {
  s32 v2;

  if (InputMode > 3u)
    LOBYTE(v2) = 0;
  else
    return 0xF100F0Fu >> (8 * InputMode);
  return v2;
}

// 0x18a4910
nmeData_t *nmeInit(s8 TargetNo, s8 EntryMode, cmpSeqInfo_t *pParentSeqInfo) {
  u64 *v7;
  u64 *v8;
  nmeData_t_o *v9;
  cmpSeqInfo_t_o *SeqInfo;
  struct System_SByte_array *InputNums;
  struct System_SByte_array *v16;
  struct System_SByte_array *v18;
  s8 v20;
  nmeData_t_o *pData;

  v7 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v7);
  v8 = Allocate(nmeData_t);
  nmeData_t___ctor(v8);
  v9 = Allocate(nmeData_t);
  nmeData_t___ctor(v9);
  pData = v9;
  v9->MH = v7;
  SeqInfo = v9->SeqInfo;
  cmpInitSeqInfo(SeqInfo, pParentSeqInfo);
  v9->SeqInfo->Current = 0;
  v9->SeqInfo->Last = 0;
  v9->SeqInfo->Change = 1;
  v9->EntryMode = EntryMode;
  InputNums = v9->InputNums;
  v9->TargetNo = TargetNo;
  InputNums->m_Items[0] = 0;
  v16 = v9->InputNums;
  v16->m_Items[1] = 0;
  v18 = v9->InputNums;
  v18->m_Items[2] = 0;
  nmeInitEntryType(0, &pData);
  nmeInitFuncCursor(v20, &pData);
  nmeSetDefaultNameCore(TargetNo, 0, &pData);
  nmeSetDefaultNameCore(TargetNo, 1, &pData);
  nmeSetDefaultNameCore(TargetNo, 2, &pData);
  nmeTexLoad(TargetNo, &pData);
  return v9;
}

// 0x18a5c80
void nmeInitDefaultName(void) {
  u64 *v1;
  u64 *v2;
  u64 *v3;
  nmeData_t_o *pData;

  v1 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v1);
  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
  v3 = Allocate(nmeData_t);
  nmeData_t___ctor(v3);
  pData = v3;
  nmeSetDefaultNameCore(0, 0, &pData);
  nmeSetDefaultNameCore(0, 1, &pData);
  nmeSetDefaultNameCore(0, 2, &pData);
  nmeSetFontImageToGW(0, &pData);
  nmeSetDefaultNameCore(1, 0, &pData);
  nmeSetDefaultNameCore(1, 1, &pData);
  nmeSetDefaultNameCore(1, 2, &pData);
  nmeSetFontImageToGW(1, &pData);
  nmeSetDefaultNameCore(2, 0, &pData);
  nmeSetDefaultNameCore(2, 1, &pData);
  nmeSetDefaultNameCore(2, 2, &pData);
  nmeSetFontImageToGW(2, &pData);
  nmeSetDefaultNameCore(3, 0, &pData);
  nmeSetDefaultNameCore(3, 1, &pData);
  nmeSetDefaultNameCore(3, 2, &pData);
  nmeSetFontImageToGW(3, &pData);
}

// 0x18a4b30
void nmeInitEntryType(s8 EntryType, nmeData_t **pData) {
  struct cmpCursorInfo_t_o *v6;
  cmpCursorInfo_t_o *v7;
  u8 v8;
  u8 v9;
  struct cmpCursorInfo_t_o *ModeCursor;

  (*pData)->EntryType = EntryType;
  (*pData)->InputPos = 0;
  (*pData)->FuncFlag = 0;
  (*pData)->ListCapFlag = 0;
  (*pData)->CfmFlag = 0;
  nmeInitInputMode(0, pData);
  if (EntryType < 2u)
  {
    ModeCursor = (*pData)->ModeCursor;
    v7 = ModeCursor;
    v8 = 4;
    v9 = 4;
  }
  else
  {
    if (EntryType != 2)
      return;
    v6 = (*pData)->ModeCursor;
    v7 = v6;
    v8 = 3;
    v9 = 3;
  }
  cmpInitCursorInfo(v7, v8, v9, 0);
  cmpInitCursorSize((*pData)->ModeCursor, 0, 0, 0, 0, 0, 0);
}

// 0x18a4c90
void nmeInitFuncCursor(s8 CursorPos, nmeData_t **pData) {
  cmpCursorInfo_t_o *FuncCursor;
  struct cmpCursorInfo_t_array *CharCursor;
  cmpCursorInfo_t_o *v8;
  s32 Shift;
  s32 v10;

  FuncCursor = (*pData)->FuncCursor;
  cmpInitCursorInfo(FuncCursor, 4u, 4u, 0);
  cmpInitCursorSize((*pData)->FuncCursor, 0, 0, 0, 0, 0, 0);
  CharCursor = (*pData)->CharCursor;
  v8 = (*pData)->FuncCursor;
  Shift = CharCursor->m_Items[0]->CursorPos->Shift;
  if ((Shift - 3) > 2)
  {
    v10 = 0;
  }
  else
  {
    v10 = Shift - 2;
  }
  cmpSetCursorPos(v10, v8);
}

// 0x18a6660
void nmeInitInputMode(s8 InputMode, nmeData_t **pData) {
  struct cmpCursorInfo_t_array *CharCursor;
  u64 *v6;
  struct cmpCursorInfo_t_array *v8;
  u64 *v9;
  u32 v12;
  u8 v13;
  bool v14;
  bool v15;
  s32 v18;
  struct cmpCursorInfo_t_array *v19;
  cmpCursorInfo_t_o *v21;
  struct cmpCursorInfo_t_array *v22;
  struct cmpCursorInfo_t_array *v24;
  struct cmpCursorInfo_t_array *v26;
  struct System_String_array_array *nmeTblList24;

  CharCursor = (*pData)->CharCursor;
  v6 = Allocate(cmpCursorInfo_t);
  cmpCursorInfo_t___ctor(v6);
  CharCursor->m_Items[0] = v6;
  v8 = (*pData)->CharCursor;
  v9 = Allocate(cmpCursorInfo_t);
  cmpCursorInfo_t___ctor(v9);
  v8->m_Items[1] = v9;
  else
  {
    v12 = InputMode;
    v13 = 15;
    v14 = v12 == 2;
    if (v12 < 2)
  }
  if (v14)
  {
    LOBYTE(v18) = 6;
    v13 = 16;
    v19 = (*pData)->CharCursor;
    if (!LODWORD(v19->max_length))
  }
  if (v12 == 3)
  {
    v15 = v12 == 3;
    if (v12 >= 3)
    LOBYTE(v18) = 6;
    v19 = (*pData)->CharCursor;
    if (!LODWORD(v19->max_length))
  }
  v13 = 0;
  v15 = v12 == 3;
  if (v12 < 3)
  if (v15)
  {
    v18 = SLODWORD(nmeTblList24->m_Items[3]->max_length) / 16;
    (*pData)->ListCapFlag = 0;
    v19 = (*pData)->CharCursor;
  }
  else
  {
    LOBYTE(v18) = 0;
    v19 = (*pData)->CharCursor;
    if (!LODWORD(v19->max_length))
  }
  v21 = v19->m_Items[0];
  cmpInitCursorInfo(v21, v18, 6u, 0);
  v22 = (*pData)->CharCursor;
  cmpInitCursorSize(v22->m_Items[0], 0, 0, 0, 0, 0);
  v24 = (*pData)->CharCursor;
  cmpInitCursorInfo(v24->m_Items[1], v13, v13, 0);
  v26 = (*pData)->CharCursor;
  cmpInitCursorSize(v26->m_Items[1], 0, 0, 0, 0, 0);
}

// 0x18a7590
s32 nmeNameEntry(void) {
  struct Nme_Init_StaticFields *static_fields;
  s32 gProcessStat;
  s8 IntPara;
  s8 v7;
  s8 v9;
  s32 v10;
  s32 v11;

  else
  {
    static_fields = Nme_Init->static_fields;
    gProcessStat = static_fields->gProcessStat;
    if (gProcessStat != 2)
    {
      if (!gProcessStat)
      {
        IntPara = scrGetIntPara(0);
        v9 = scrGetIntPara(1);
        nmeNameProcessStart(IntPara, v9, v7);
      }
      v10 = 0;
      v11 = 1;
    }
  }
  v11 = 0;
  v10 = 1;
  static_fields->gProcessStat = 0;
  scrSetIntReturnValue(v11);
  return v10;
}

// 0x18a73e0
void nmeNameProcessEnd(void) {
  dds3KillProcessName(StringLiteral_6, 1);
  dds3KillProcessName(StringLiteral_5626, 1);
  dds3KillProcessName(StringLiteral_5627, 1);
}

// 0x18a69d0
void nmeNameProcessStart(s8 TargetNo, s8 EntryMode, s8 DebugMode) {
  nmeData_t_o *v6;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v10;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v14;
  Nme_Init_c *v17;
  UnityEngine_GameObject_o *oName_UI;
  UnityEngine_GameObject_o *v19;
  UnityEngine_Transform_o *v20;
  UnityEngine_Component_o *v21;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v23;
  UnityEngine_Component_o *v24;
  struct cmpCursorInfo_t_array *CharCursor;
  u64 *v26;
  struct cmpCursorInfo_t_array *v28;
  u64 *v29;
  struct Nme_Init_StaticFields *static_fields;
  u64 *v43;
  Il2CppObject *data;
  u64 *v46;
  u64 *v47;
  u64 *v48;
  bool v51;
  struct System_Byte_array *gFadeCol;
  struct System_Byte_array *v55;
  struct System_Byte_array *v57;
  struct System_Byte_array *v60;
  struct System_Byte_array *v62;
  struct System_Byte_array *v64;
  struct System_Byte_array *v66;
  u32 max_length;
  u32 v68;
  u32 v69;
  u32 v71;

  NewSpecific(sbyte, 4u);
  v6 = Allocate(nmeData_t);
  nmeData_t___ctor(v6);
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_4611, StringLiteral_5156, StringLiteral_5623);
  v10 = Find(StringLiteral_4905, 0);
  transform = get_transform(v10, 0);
  v14 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  oName_UI = v14;
  AddComponent_object_(oName_UI);
  if ((byte_3F5AA06 & 1) != 0)
  {
    if ((v17->_2.bitflags2 & 2) == 0)
  }
  v19 = oName_UI;
  v20 = get_transform(oName_UI, 0);
  v21 = Find(v20, StringLiteral_5553, 0);
  gameObject = get_gameObject(v21);
  v23 = get_transform(v19, 0);
  v24 = Find(v23, StringLiteral_5624, 0);
  get_gameObject(v24);
  CharCursor = v6->CharCursor;
  v26 = Allocate(cmpCursorInfo_t);
  cmpCursorInfo_t___ctor(v26);
  CharCursor->m_Items[0] = v26;
  v28 = v6->CharCursor;
  v29 = Allocate(cmpCursorInfo_t);
  cmpCursorInfo_t___ctor(v29);
  v28->m_Items[1] = v29;
  else
  {
    static_fields = Nme_Init->static_fields;
    if (static_fields->name_count != 1)
  }
  if (get_activeSelf(static_fields->oName_UI))
  {
    yesnoflag = 0;
    SetActive(gameObject, 1, 0);
    name_count = 2;
  }
  NameInit();
  NameInit2();
  char_sel = TargetNo;
  else
  {
    DefNameDraw();
    if (TargetNo < 4)
  }
  {
    if (GBWK)
      return;
  }
  if (GBWK)
    return;
  GBWK = nmeInit(TargetNo, EntryMode, 0);
  ButtonGuideDispSet(StringLiteral_5592, 0, 0, 90);
  v43 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v43,
    0,
    Method_Nme_Calc_nmeCalc__);
  data = GBWK;
  dds3StartProcess(StringLiteral_6, 0x406u, 1, 1, v43, 0, 0, 0, data, 0);
  v46 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v46,
    0,
    Method_Nme_Draw_nmeDraw__);
  dds3StartProcess(
    StringLiteral_5626,
    0x2B16u,
    1,
    1,
    v46,
    0,
    0,
    0,
    GBWK,
    0);
  v47 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v47,
    0,
    Method_Nme_Update_nmeUpdate__);
  v48 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v48,
    0,
    Method_Nme_Init_nmeDestroyName__);
  dds3StartProcess(
    StringLiteral_5627,
    0x5212u,
    1,
    1,
    v47,
    0,
    v48,
    0,
    GBWK,
    0);
  gProcessStat = 1;
  dds3KernelDebugSignOrg = 1;
  v51 = evtBitCheck(18);
  if (v51)
  {
    gFadeCol->m_Items[0] = 0;
    v55 = gFadeCol;
    v55->m_Items[1] = 0;
    v57 = gFadeCol;
    v57->m_Items[2] = 0;
  }
  else
  {
    v60 = gFadeCol;
    v60->m_Items[0] = -1;
    v62 = gFadeCol;
    v62->m_Items[1] = -1;
    v64 = gFadeCol;
    v64->m_Items[2] = -1;
  }
  v66 = gFadeCol;
  max_length = v66->max_length;
  v68 = v66->m_Items[0];
  v69 = gFadeCol->m_Items[1];
  v71 = gFadeCol->m_Items[2];
  dds3FadeIn(v68, v69, v71, 0x1Eu);
}

// 0x18a4dc0
void nmeSetDefaultName(s8 TargetNo, nmeData_t **pData) {
  nmeSetDefaultNameCore(TargetNo, 0, pData);
  nmeSetDefaultNameCore(TargetNo, 1, pData);
  nmeSetDefaultNameCore(TargetNo, 2, pData);
}

// 0x18a61a0
void nmeSetDefaultNameCore(s8 TargetNo, s8 Type, nmeData_t **pData) {
  s32 v6;
  char v7;
  struct System_Byte_array *InputCode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v12;
  s64 v13;
  char *v14;
  struct System_Byte_array *v15;
  Il2CppArrayBounds *v16;
  il2cpp_array_size_t v17;
  il2cpp_array_size_t v18;
  System_Text_Encoding_o *Unicode;
  struct System_String_array *tblDefName;
  s32 v29;
  s64 v31;
  s32 v32;
  struct System_SByte_array *InputNums;
  s32 v35;
  struct System_Byte_array *v41;
  s64 v42;
  Il2CppArrayBounds *v44;
  il2cpp_array_size_t v45;
  il2cpp_array_size_t v46;
  char *v47;
  struct System_Byte_array *v48;
  s64 v49;
  u8 v51;
  Il2CppArrayBounds *v52;
  il2cpp_array_size_t v53;
  il2cpp_array_size_t v54;
  s32 v57;
  nmeData_t_o **v58;

  if (Type >= 2u)
    v6 = 8;
  else
    v6 = 4;
  v7 = 0;
  v58 = pData;
  {
  }
  while (v6 > v7)
  {
    InputCode = (*pData)->InputCode;
    bounds = InputCode->bounds;
    length = bounds[1].length;
    v12 = bounds[2].length;
    v13 = v7;
    v14 = InputCode + v12 * (v7 + length * Type);
    pData = v58;
    v14[32] = -1;
    v15 = (*v58)->InputCode;
    v16 = v15->bounds;
    v17 = v16[1].length;
    v18 = v16[2].length;
    ++v7;
    v15->m_Items[v18 * (v13 + v17 * Type) + 1] = -1;
  }
  Unicode = get_Unicode();
  v29 = Type + (3 * TargetNo);
  v31 = (Unicode->klass->vtable._28_GetBytes.methodPtr)(
          Unicode,
          tblDefName->m_Items[v29],
          Unicode->klass->vtable._28_GetBytes.method);
  v32 = *(v31 + 24) / 2;
  InputNums = (*pData)->InputNums;
  InputNums->m_Items[Type] = v32;
  if (v32 << 24 >= 1)
  {
    v35 = 0;
    v57 = v32;
    do
    {
      v41 = (*pData)->InputCode;
      v42 = 2LL * v35;
      v44 = v41->bounds;
      v45 = v44[1].length;
      v46 = v44[2].length;
      v47 = v41 + v46 * (v35 + v45 * Type);
      pData = v58;
      v47[32] = *(v31 + v42 + 32);
      v48 = (*v58)->InputCode;
      v49 = v42 | 1LL;
      v51 = *(v31 + v49 + 32);
      v52 = v48->bounds;
      v53 = v52[1].length;
      v54 = v52[2].length;
      v48->m_Items[v54 * (v35 + v53 * Type) + 1] = v51;
      v35 = (v35 + 1);
    }
    while (v57 > v35);
  }
}

// 0x18a52d0
void nmeSetFontImageToGW(s8 TargetNo, nmeData_t **pData) {
}

// 0x18a74f0
void nmeTerminateName(void) {
  struct nmeData_t_o *GBWK;

  if (GBWK)
  {
    GBWK->SeqInfo->Flag |= 0x10u;
  }
}

// 0x18a5ae0
void nmeTexFree(nmeData_t **pData) {
  struct sdfTexHandle_t_array *Tex;
  sdfTexHandle_t_o *v5;
  struct sdfTexHandle_t_array *v7;
  sdfTexHandle_t_o *v8;
  struct sdfTexHandle_t_array *v11;
  sdfTexHandle_t_o *v13;
  struct sdfTexHandle_t_array *v15;
  sdfTexHandle_t_o *v16;

  Tex = (*pData)->Tex;
  v5 = Tex->m_Items[0];
  sdfTexFree(v5);
  v7 = (*pData)->Tex;
  v8 = v7->m_Items[1];
  sdfTexFree(v8);
  v11 = (*pData)->Tex;
  v13 = v11->m_Items[2];
  sdfTexFree(v13);
  v15 = (*pData)->Tex;
  v16 = v15->m_Items[3];
  sdfTexFree(v16);
}

// 0x18a4e60
void nmeTexLoad(s8 TargetNo, nmeData_t **pData) {
  struct sdfTexHandle_t_array *Tex;
  s64 *Texture;
  s64 *v7;
  struct sdfTexHandle_t_array *v9;
  s64 *v10;
  s64 *v11;
  struct sdfTexHandle_t_array *v13;
  s64 *v14;
  s64 *v15;
  bool v18;
  struct sdfTexHandle_t_array *v20;
  struct System_String_array *v21;
  System_String_o *v23;
  struct System_String_array *nmeCharTexFile;
  s64 *v27;
  s64 *v28;

  Tex = (*pData)->Tex;
  Texture = fclLoadTexture(StringLiteral_5619);
  v7 = Texture;
  Tex->m_Items[0] = v7;
  v9 = (*pData)->Tex;
  v10 = fclLoadTexture(StringLiteral_5620);
  v11 = v10;
  v9->m_Items[1] = v11;
  v13 = (*pData)->Tex;
  v14 = fclLoadTexture(StringLiteral_5621);
  v15 = v14;
  v13->m_Items[2] = v15;
  v18 = evtBitCheck(2224);
  v20 = (*pData)->Tex;
  if (TargetNo || !v18)
  {
    v23 = nmeCharTexFile->m_Items[TargetNo];
  }
  else
  {
    v21 = nmeCharTexFile;
    v23 = v21->m_Items[4];
    {
    }
  }
  v27 = fclLoadTexture(v23);
  v28 = v27;
  v20->m_Items[3] = v28;
}
