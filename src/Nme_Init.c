#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nmeData_t nmeData_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 name_count;
static s32 char_sel;
static char *nmeCharTexFile;
static nmeData_t *GBWK;
static s8 gProcessStat;
static char *tblDefName;
static s8 *nmeTblList;
static char **nmeTblList22;
static char **nmeTblList24;
static s32 dds3KernelDebugSignOrg;
static u8 *gFadeCol;
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
  struct nmeData_t_o *GBWK;
  s32 dds3KernelDebugSignOrg;

  if (GBWK)
  {
    nmeSetFontImageToGW(GBWK->TargetNo, &GBWK);
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
LABEL_7:
  nmeSetDefaultNameCore(0, 0, &pData);
  nmeSetDefaultNameCore(0, 1, &pData);
  nmeSetDefaultNameCore(0, 2, &pData);
  nmeSetFontImageToGW(0, &pData);
LABEL_14:
  nmeSetDefaultNameCore(1, 0, &pData);
  nmeSetDefaultNameCore(1, 1, &pData);
  nmeSetDefaultNameCore(1, 2, &pData);
  nmeSetFontImageToGW(1, &pData);
LABEL_21:
  nmeSetDefaultNameCore(2, 0, &pData);
  nmeSetDefaultNameCore(2, 1, &pData);
  nmeSetDefaultNameCore(2, 2, &pData);
  nmeSetFontImageToGW(2, &pData);
LABEL_28:
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
      goto LABEL_23;
  }
  if (v14)
  {
    LOBYTE(v18) = 6;
    v13 = 16;
    v19 = (*pData)->CharCursor;
    if (!LODWORD(v19->max_length))
      goto LABEL_25;
    goto LABEL_26;
  }
  if (v12 == 3)
  {
LABEL_23:
    v15 = v12 == 3;
    if (v12 >= 3)
      goto LABEL_36;
LABEL_24:
    LOBYTE(v18) = 6;
    v19 = (*pData)->CharCursor;
    if (!LODWORD(v19->max_length))
      goto LABEL_25;
    goto LABEL_26;
  }
  v13 = 0;
  v15 = v12 == 3;
  if (v12 < 3)
    goto LABEL_24;
LABEL_36:
  if (v15)
  {
    v18 = SLODWORD(nmeTblList24->m_Items[3]->max_length) / 16;
    (*pData)->ListCapFlag = 0;
    v19 = (*pData)->CharCursor;
    if (!LODWORD(v19->max_length))
    {
LABEL_25:
    }
  }
  else
  {
    LOBYTE(v18) = 0;
    v19 = (*pData)->CharCursor;
    if (!LODWORD(v19->max_length))
      goto LABEL_25;
  }
LABEL_26:
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
  s32 gProcessStat;
  s8 IntPara;
  s8 v7;
  s8 v9;
  s32 v10;
  s32 v11;

  else
  {
    if (gProcessStat != 2)
    {
LABEL_6:
      if (!gProcessStat)
      {
        IntPara = scrGetIntPara(0);
        v9 = scrGetIntPara(1);
        nmeNameProcessStart(IntPara, v9, v7);
      }
      v10 = 0;
      v11 = 1;
      goto LABEL_20;
    }
  }
  v11 = 0;
  v10 = 1;
  gProcessStat = 0;
LABEL_20:
  scrSetIntReturnValue(v11);
  return v10;
}

// 0x18a73e0
void nmeNameProcessEnd(void) {
  dds3KillProcessName("name", 1);
  dds3KillProcessName("name_draw", 1);
  dds3KillProcessName("name_update", 1);
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
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", "dds3data/UI", "nameUI");
  v10 = Find("Canvas_UI", 0);
  transform = get_transform(v10, 0);
  v14 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  oName_UI = v14;
  AddComponent_object_(oName_UI);
  if ((byte_3F5AA06 & 1) != 0)
  {
LABEL_17:
    if ((v17->_2.bitflags2 & 2) == 0)
      goto LABEL_20;
    goto LABEL_18;
  }
    goto LABEL_20;
LABEL_18:
LABEL_20:
  v19 = oName_UI;
  v20 = get_transform(oName_UI, 0);
  v21 = Find(v20, "namelist", 0);
  gameObject = get_gameObject(v21);
  v23 = get_transform(v19, 0);
  v24 = Find(v23, "nameinput/nameconfirm", 0);
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
    if (name_count != 1)
      goto LABEL_50;
  }
  if (get_activeSelf(oName_UI))
  {
    yesnoflag = 0;
    SetActive(gameObject, 1, 0);
    name_count = 2;
  }
  NameInit();
  NameInit2();
LABEL_50:
  char_sel = TargetNo;
  else
  {
    DefNameDraw();
    if (TargetNo < 4)
      goto LABEL_64;
  }
  {
LABEL_66:
    if (GBWK)
      return;
    goto LABEL_69;
  }
LABEL_65:
    goto LABEL_66;
  if (GBWK)
    return;
LABEL_69:
  GBWK = nmeInit(TargetNo, EntryMode, 0);
  ButtonGuideDispSet("NAME01", 0, 0, 90);
  v43 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v43,
    0,
    Method_Nme_Calc_nmeCalc__);
  data = GBWK;
  dds3StartProcess("name", 0x406u, 1, 1, v43, 0, 0, 0, data, 0);
  v46 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v46,
    0,
    Method_Nme_Draw_nmeDraw__);
  dds3StartProcess(
    "name_draw",
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
    "name_update",
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
      goto LABEL_102;
  }
  else
  {
    v60 = gFadeCol;
    v60->m_Items[0] = -1;
    v62 = gFadeCol;
    v62->m_Items[1] = -1;
    v64 = gFadeCol;
    v64->m_Items[2] = -1;
      goto LABEL_102;
  }
LABEL_102:
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
LABEL_9:
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
      goto LABEL_9;
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
  s64 v5;
  char v6;
  u32 v7;
  struct System_Byte_array_array *name_nums;
  System_Byte_array *v11;
  struct System_SByte_array *InputNums;
  s8 v14;
  u64 v16;
  struct System_SByte_array *v17;
  struct System_Byte_array *InputCode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v22;
  u8 v23;
  struct System_Byte_array *v24;
  Il2CppArrayBounds *v25;
  il2cpp_array_size_t v26;
  il2cpp_array_size_t v27;
  u64 *v30;
  struct System_Byte_array_array *name_code;
  System_Byte_array *v34;
  struct System_Byte_array *v35;
  Il2CppArrayBounds *v36;
  il2cpp_array_size_t v37;
  il2cpp_array_size_t v38;
  char *v39;
  s64 v40;
  struct System_Byte_array_array *v42;
  System_Byte_array *v44;
  struct System_Byte_array *v45;
  Il2CppArrayBounds *v46;
  il2cpp_array_size_t v47;
  il2cpp_array_size_t v48;
  u8 v50;
  s64 v51;
  struct System_SByte_array *v63;
  u64 v65;
  u64 i;
  char *v67;
  struct System_SByte_array *v68;
  struct System_Byte_array_array *cname_code;
  struct System_Byte_array *v73;
  Il2CppArrayBounds *v74;
  System_Byte_array *v75;
  il2cpp_array_size_t v76;
  il2cpp_array_size_t v77;
  u8 v78;
  struct System_Byte_array_array *v80;
  struct System_Byte_array *v82;
  Il2CppArrayBounds *v83;
  System_Byte_array *v84;
  il2cpp_array_size_t v85;
  il2cpp_array_size_t v86;
  u8 v88;
  struct System_Byte_array *cname_nums;
  struct System_SByte_array *v96;
  s8 v98;
  s64 v100;
  s32 v101;

  v5 = 0;
  v6 = 0;
  v7 = TargetNo;
  v100 = TargetNo;
  do
  {
    name_nums = DDS3_GBWK->name_nums;
    v11 = name_nums->m_Items[v100];
    InputNums = (*pData)->InputNums;
    v14 = InputNums->m_Items[v5];
    v16 = 0;
    v11->m_Items[v5] = v14;
    while (1)
    {
      v17 = (*pData)->InputNums;
      if (v16 >= v17->m_Items[v5])
        break;
      InputCode = (*pData)->InputCode;
      bounds = InputCode->bounds;
      length = bounds[1].length;
      v22 = bounds[2].length;
      v23 = InputCode->m_Items[v22 * (v16 + v5 * length)];
      v24 = (*pData)->InputCode;
      v25 = v24->bounds;
      v26 = v25[1].length;
      v27 = v25[2].length;
      v101 = v24->m_Items[v27 * (v16 + v5 * v26) + 1] | (v23 << 8);
      v30 = sub_8D3950(s32, &v101);
      Write_2930400("{0:x4} ", v30);
      name_code = DDS3_GBWK->name_code;
      v34 = name_code->m_Items[v100];
      v35 = (*pData)->InputCode;
      v36 = v35->bounds;
      v37 = v36[1].length;
      v38 = v36[2].length;
      v39 = v35 + v38 * (v16 + v5 * v37);
      v40 = 2LL * v6;
      v34->m_Items[v40] = v39[32];
      v42 = DDS3_GBWK->name_code;
      v44 = v42->m_Items[v100];
      v45 = (*pData)->InputCode;
      v46 = v45->bounds;
      v47 = v46[1].length;
      v48 = v46[2].length;
      v50 = v45->m_Items[v48 * (v16 + v5 * v47) + 1];
      v51 = v40 | 1LL;
      ++v6;
      ++v16;
      v44->m_Items[v51] = v50;
    }
    Write("\n", 0);
    ++v5;
  }
  while (v5 != 2);
  v63 = (*pData)->InputNums;
  if (v63->m_Items[2] >= 1)
  {
    v65 = 0;
    for (i = 0; ; ++i)
    {
      v68 = (*pData)->InputNums;
      if (i >= v68->m_Items[2])
        break;
      cname_code = DDS3_GBWK->cname_code;
      v73 = (*pData)->InputCode;
      v74 = v73->bounds;
      v75 = cname_code->m_Items[0];
      v76 = v74[1].length;
      v77 = v74[2].length;
      v78 = v73->m_Items[v77 * (i + 2 * v76)];
      v75->m_Items[v65] = v78;
      v80 = DDS3_GBWK->cname_code;
      v82 = (*pData)->InputCode;
      v83 = v82->bounds;
      v84 = v80->m_Items[0];
      v85 = v83[1].length;
      v86 = v83[2].length;
      v88 = v82->m_Items[v86 * (i + 2 * v85) + 1];
      v67 = v84 + v65;
      v65 += 2LL;
      v67[33] = v88;
    }
    cname_nums = DDS3_GBWK->cname_nums;
    v96 = (*pData)->InputNums;
    v98 = v96->m_Items[2];
    cname_nums->m_Items[0] = v98;
  }
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
  Texture = fclLoadTexture("/name/tmx/name_01.tmx");
  v7 = Texture;
  Tex->m_Items[0] = v7;
  v9 = (*pData)->Tex;
  v10 = fclLoadTexture("/name/tmx/name_02.tmx");
  v11 = v10;
  v9->m_Items[1] = v11;
  v13 = (*pData)->Tex;
  v14 = fclLoadTexture("/name/tmx/name_03.tmx");
  v15 = v14;
  v13->m_Items[2] = v15;
  v18 = evtBitCheck(2224);
  v20 = (*pData)->Tex;
  if (TargetNo || !v18)
  {
    v23 = nmeCharTexFile->m_Items[TargetNo];
      goto LABEL_26;
  }
  else
  {
    v21 = nmeCharTexFile;
    v23 = v21->m_Items[4];
    {
LABEL_26:
    }
  }
  v27 = fclLoadTexture(v23);
  v28 = v27;
  v20->m_Items[3] = v28;
}
