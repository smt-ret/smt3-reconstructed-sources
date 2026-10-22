#include "types.h"

typedef struct TextManager TextManager;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nmeData_t nmeData_t;

static s32 namecursur_flag;
static char *str_index;
static s32 nameInputResetflag;
static s32 nameEndflag;
static s32 StartEndNameflag;
static void *nameChange;
static void *name_input;
static void *_name_input;
static s8 tblInvalidName[4];
static nmeData_t *GBWK;

void ButtonGuideDispOff(void);
void ClearNameUI(void);
void DefNameDraw(void);
void *GetoNameUI(void);
char *RepColTag(char *txt, void **LegacyParamArray);
void ReturnEventObject(void);
u8 **UnicodeToIndexByte2(TextManager *this, char *str);
s32 dds3FadeCheck(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
void nmeBackSpace(void);
s8 nmeChkEntryType(nmeData_t **pData);
s8 nmeChkInvalidName(s8 Type);
void nmeDeleteCharCursorPos(s8 Mode);
void nmeDeleteEndSpace(s8 Type);
void nmeFadeOut(void);
void nmeGetInputChar(void);
s8 nmeGetInputCharMax(nmeData_t **pData);
s8 nmeGetInputModeColumnMax(s8 InputMode);
void nmeInitEntryType(s8 EntryType, nmeData_t **pData);
void nmeInitFuncCursor(s8 CursorPos, nmeData_t **pData);
void nmeInitInputMode(s8 InputMode, nmeData_t **pData);
void nmeMoveInputCursor(s8 Dir);
void nmeMoveListCapLine(s8 Dir);
void nmeSetDefaultName(s8 TargetNo, nmeData_t **pData);
void nmeSetRetLine(s8 InputMode);
void nmeUpdate1st(void);
void nmeUpdateConfirm(void);
s8 nmeUpdateFuncCursor(void);
void nmeUpdateInputCursor(void);
void nmeUpdateInputMode(void);
void nmeUpdateListCapCursor(void);
s8 nmeUpdateMoveEtcMode(cmpCursorInfo_t *pCursorInfo, s8 Dir);

// 0x1887a90
s8 SDF_ARRAYCOUNT(s8 **n) {
  return 0;
}

// 0x1888e90
void nmeBackSpace(void) {
  nmeData_t_o **p_GBWK;

LABEL_7:
  p_GBWK = &GBWK;
  if (nmeChkEntryType(p_GBWK) == 1)
  {
    if (((*p_GBWK)->InputPos - 4) < 1)
      goto LABEL_16;
  }
  else if ((*p_GBWK)->InputPos < 1)
  {
    goto LABEL_16;
  }
  nmeMoveInputCursor(255);
LABEL_16:
  nmeDeleteCharCursorPos(1);
}

// 0x188b3c0
s8 nmeChkInvalidName(s8 Type) {
  struct System_SByte_array *v4;
  struct System_SByte_array *v6;
  struct System_SByte_array *InputNums;

  if (Type > 1u)
  {
    InputNums = GBWK->InputNums;
    if (!InputNums->m_Items[2])
      return 0;
  }
  else
  {
    v4 = GBWK->InputNums;
    if (!v4->m_Items[0])
      return 0;
    v6 = GBWK->InputNums;
    if (!v6->m_Items[1])
      return 0;
  }
LABEL_26:
    return 1;
  return 1;
}

// 0x188b350
s8 nmeCompareStr(s8 Type) {
    return 0;
  return 0;
}

// 0x18880f0
void nmeDeleteCharCursorPos(s8 Mode) {
  nmeData_t_o **p_GBWK;
  s64 v6;
  s8 inited;
  struct System_SByte_array *InputNums;
  u32 v11;
  s64 v12;
  struct System_Byte_array *InputCode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v18;
  struct System_Byte_array *v19;
  Il2CppArrayBounds *v20;
  il2cpp_array_size_t v21;
  il2cpp_array_size_t v22;
  s64 v24;
  struct System_SByte_array *v26;
  struct System_Byte_array *v29;
  Il2CppArrayBounds *v30;
  il2cpp_array_size_t v31;
  u32 v32;
  il2cpp_array_size_t v33;
  u8 v34;
  il2cpp_array_size_t v35;
  il2cpp_array_size_t v36;
  struct System_Byte_array *v37;
  Il2CppArrayBounds *v38;
  il2cpp_array_size_t v39;
  il2cpp_array_size_t v40;
  u8 v42;
  il2cpp_array_size_t v43;
  il2cpp_array_size_t v44;
  struct System_Byte_array *v46;
  Il2CppArrayBounds *v47;
  il2cpp_array_size_t v48;
  il2cpp_array_size_t v49;
  struct System_Byte_array *v50;
  Il2CppArrayBounds *v51;
  il2cpp_array_size_t v52;
  il2cpp_array_size_t v53;
  struct System_SByte_array *v71;
  struct System_SByte_array *v80;
  s8 v82;

LABEL_7:
  p_GBWK = &GBWK;
  if (nmeChkEntryType(p_GBWK) == 1)
  {
    LOBYTE(v6) = (*p_GBWK)->InputPos - 4;
      goto LABEL_15;
  }
  else
  {
    LOBYTE(v6) = (*p_GBWK)->InputPos;
      goto LABEL_15;
  }
LABEL_15:
  inited = nmeChkEntryType(&GBWK);
  InputNums = GBWK->InputNums;
  v11 = inited;
  v12 = inited;
  if (InputNums->m_Items[inited] >= 1)
  {
    InputCode = GBWK->InputCode;
    bounds = InputCode->bounds;
    length = bounds[1].length;
    v18 = bounds[2].length;
    v82 = v6;
    InputCode->m_Items[v18 * (v6 + length * v12)] = -1;
    v19 = GBWK->InputCode;
    v20 = v19->bounds;
    v21 = v20[1].length;
    v22 = v20[2].length;
    v19->m_Items[v22 * (v6 + v21 * v12) + 1] = -1;
    if (Mode)
    {
      while (1)
      {
        v26 = GBWK->InputNums;
        if (v6 + 1 >= v26->m_Items[v12])
          break;
        v29 = GBWK->InputCode;
        v30 = v29->bounds;
        v31 = v30[1].length;
        v32 = v6 + 1;
        v33 = v30[2].length;
        v34 = v29->m_Items[v33 * (v6 + v31 * v12 + 1)];
        v35 = v30[1].length;
        v36 = v30[2].length;
        v29->m_Items[v36 * (v6 + v35 * v12)] = v34;
        v37 = GBWK->InputCode;
        v38 = v37->bounds;
        v39 = v38[1].length;
        v40 = v38[2].length;
        v42 = v37->m_Items[v40 * (v6 + v39 * v12 + 1) + 1];
        v43 = v38[1].length;
        v44 = v38[2].length;
        v37->m_Items[v44 * (v6 + v43 * v12) + 1] = v42;
        v46 = GBWK->InputCode;
        v47 = v46->bounds;
        v48 = v47[1].length;
        v49 = v47[2].length;
        v46->m_Items[v49 * (v6 + v48 * v12 + 1)] = -1;
        v50 = GBWK->InputCode;
        v51 = v50->bounds;
        v52 = v51[1].length;
        v53 = v51[2].length;
        v24 = v6 + v52 * v12;
        ++v6;
        v50->m_Items[v53 * (v24 + 1) + 1] = -1;
      }
    }
    v71 = GBWK->InputNums;
    if (v71->m_Items[v12] > v82)
    {
      v80 = GBWK->InputNums;
      --v80->m_Items[v12];
        goto LABEL_97;
    }
    else
    {
      {
LABEL_97:
        nmeDeleteEndSpace(v12);
        return;
      }
    }
    goto LABEL_97;
  }
}

// 0x1887b40
void nmeDeleteEndSpace(s8 Type) {
  s32 InputCharMax;
  s32 v7;
  s32 v8;
  s64 v10;
  char v11;
  struct System_Byte_array *InputCode;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v15;
  s32 v16;
  struct System_Byte_array *v17;
  Il2CppArrayBounds *v18;
  il2cpp_array_size_t v19;
  il2cpp_array_size_t v20;
  s32 v28;
  struct System_SByte_array *InputNums;
  s32 v31;

  namepushflag = 0;
  InputCharMax = nmeGetInputCharMax(&GBWK);
  v7 = InputCharMax - 1;
  v8 = v7 << 24;
  if (v7 << 24 < -16777215)
  {
LABEL_37:
    InputNums = GBWK->InputNums;
    v10 = Type;
    LOBYTE(v31) = 0;
  }
  else
  {
    v10 = Type;
    while (1)
    {
      v11 = v7;
      InputCode = GBWK->InputCode;
      bounds = InputCode->bounds;
      length = bounds[1].length;
      v15 = bounds[2].length;
      v16 = InputCode->m_Items[v15 * (v11 + length * Type)];
      v17 = GBWK->InputCode;
      v18 = v17->bounds;
      v19 = v18[1].length;
      v20 = v18[2].length;
      if (v16 != 255 && v16 != 0)
        break;
      v28 = v17->m_Items[v20 * (v11 + v19 * Type) + 1];
      if (v28 != 48 && v28 != 255)
        break;
      v7 = (v8 >> 24) - 1;
      v8 = v7 << 24;
      if (v7 << 24 <= -16777216)
        goto LABEL_37;
    }
    InputNums = GBWK->InputNums;
    v31 = HIBYTE(v8) + 1;
  }
  InputNums->m_Items[v10] = v31;
}

// 0x18888f0
void nmeGetInputChar(void) {
  cmpCursorInfo_t_o *ModeCursor;
  char CursorIndex;
  struct cmpCursorInfo_t_array *CharCursor;
  char v6;
  s32 v8;
  struct cmpCursorInfo_t_array *v9;
  s32 v10;
  s32 v13;
  s32 v15;
  TextManager_o *txtMgr;
  struct System_String_array_array *nmeTblList22;
  s32 v19;
  s64 v20;
  System_String_array *v22;
  System_Byte_array *v24;
  struct System_String_array_array *v25;
  System_Byte_array *v26;
  System_String_array *v28;
  nmeData_t_o **p_GBWK;
  s8 InputPos;
  s8 inited;
  struct System_Byte_array *InputCode;
  s8 v37;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  il2cpp_array_size_t v41;
  struct System_Byte_array *v42;
  Il2CppArrayBounds *v44;
  il2cpp_array_size_t v45;
  il2cpp_array_size_t v46;
  struct System_SByte_array *InputNums;
  struct System_SByte_array *v57;
  System_Byte_array *v60;

  ModeCursor = GBWK->ModeCursor;
  CursorIndex = cmpGetCursorIndex(ModeCursor);
  CharCursor = GBWK->CharCursor;
  v6 = CursorIndex;
  v8 = cmpGetCursorIndex(CharCursor->m_Items[0]);
  v9 = GBWK->CharCursor;
  v10 = v8;
  v13 = cmpGetCursorIndex(v9->m_Items[1]);
  if (v6 == 2)
    v15 = 16 * v10;
  else
    v15 = 15 * v10;
  v19 = v13 + v15;
  v20 = v6;
  v22 = nmeTblList22->m_Items[v6];
  v24 = UnicodeToIndexByte2(txtMgr, v22->m_Items[v19]);
  v25 = nmeTblList22;
  v26 = v24;
  v28 = v25->m_Items[v20];
  v60 = UnicodeToIndexByte2(txtMgr, v28->m_Items[v19]);
LABEL_34:
  p_GBWK = &GBWK;
  if (nmeChkEntryType(p_GBWK) == 1)
    InputPos = (*p_GBWK)->InputPos - 4;
  else
    InputPos = (*p_GBWK)->InputPos;
  inited = nmeChkEntryType(&GBWK);
  InputCode = GBWK->InputCode;
  v37 = inited;
  bounds = InputCode->bounds;
  length = bounds[1].length;
  v41 = bounds[2].length;
  InputCode->m_Items[v41 * (InputPos + length * inited)] = v26->m_Items[0];
  v42 = GBWK->InputCode;
  v44 = v42->bounds;
  v45 = v44[1].length;
  v46 = v44[2].length;
  v42->m_Items[v46 * (InputPos + v45 * inited) + 1] = v60->m_Items[1];
  InputNums = GBWK->InputNums;
  if (InputNums->m_Items[inited] != InputPos)
  {
      goto LABEL_68;
    goto LABEL_54;
  }
  v57 = GBWK->InputNums;
  ++v57->m_Items[v37];
  {
LABEL_54:
  }
LABEL_68:
  nmeMoveInputCursor(1);
  nmeDeleteEndSpace(v37);
}

// 0x1887aa0
s8 nmeGetInputCharPos(nmeData_t **pData) {
  if (nmeChkEntryType(pData) == 1)
    return (*pData)->InputPos - 4;
  else
    return (*pData)->InputPos;
}

// 0x1887ea0
void nmeMoveInputCursor(s8 Dir) {
  nmeData_t_o **p_GBWK;
  s8 InputPos;
  s8 inited;
  struct nmeData_t_o *GBWK;
  s8 v12;

LABEL_7:
  p_GBWK = &GBWK;
  if (nmeChkEntryType(p_GBWK) == 1)
  {
    InputPos = (*p_GBWK)->InputPos - 4;
      goto LABEL_15;
  }
  else
  {
    InputPos = (*p_GBWK)->InputPos;
      goto LABEL_15;
  }
LABEL_15:
  inited = nmeChkEntryType(&GBWK);
  if (inited == 2)
  {
    if (Dir < 1)
      goto LABEL_21;
    goto LABEL_28;
  }
  if (inited == 1)
  {
    if (Dir < 1)
    {
      if (!Dir)
        return;
      goto LABEL_23;
    }
LABEL_28:
    if (nmeGetInputCharMax(&GBWK) - 1 <= InputPos)
      return;
LABEL_35:
    v12 = GBWK->InputPos + 1;
    goto LABEL_39;
  }
  if (inited)
    return;
  if (Dir >= 1)
    goto LABEL_35;
LABEL_21:
  if (Dir && InputPos >= 1)
  {
LABEL_23:
    v12 = GBWK->InputPos - 1;
LABEL_39:
    GBWK->InputPos = v12;
  }
}

// 0x1888fe0
void nmeMoveListCapLine(s8 Dir) {
  struct cmpCursorInfo_t_array *CharCursor;
  struct cmpCursorPos_t_o *CursorPos;
  s16 v8;
  s16 v9;
  s32 v10;
  s64 v12;
  struct System_String_array_array *nmeTblList24;
  System_String_array *v15;
  System_String_o *v18;

  CharCursor = GBWK->CharCursor;
  CursorPos = CharCursor->m_Items[0]->CursorPos;
  NewSpecific(byte, 2u);
  v8 = Dir;
  do
  {
    v9 = CursorPos->Index + v8;
    v10 = CursorPos->ListNums - CursorPos->ShiftMax;
    CursorPos->Index = v9;
    if (v10 == v9)
      break;
    if (v10 < v9)
    {
      CursorPos->Index = v10;
      return;
    }
    if (v9 < 0)
    {
      CursorPos->Index = 0;
      return;
    }
    v12 = (16 * v9);
    v15 = nmeTblList24->m_Items[3];
    v18 = v15->m_Items[v12];
    str_index = v18;
  }
  while (!op_Inequality(v18, "　", 0));
}

// 0x1889190
void nmeSetRetLine(s8 InputMode) {
  cmpCursorInfo_t_o *FuncCursor;
  char CursorIndex;
  struct cmpCursorInfo_t_array *CharCursor;

  FuncCursor = GBWK->FuncCursor;
  CursorIndex = cmpGetCursorIndex(FuncCursor);
  CharCursor = GBWK->CharCursor;
  cmpSetCursorShift(CursorIndex + 2, CharCursor->m_Items[0]);
}

// 0x188bf90
dds3ProcessFunc_t *nmeUpdate(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v10;
  struct nmeData_t_o *GBWK;
  dds3ProcessID_t_o *v15[3];
  dds3ProcessID_t_o *id;

  id = PID;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nmeData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nmeData_t, v15);
    if ((v15[0] & 1) != 0)
      v7 = v15[2];
    else
      v7 = v15 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  else if (dds3FadeCheck())
  {
    return 0;
  }
  if ((*(*(*(*(v10 + 184) + 64LL) + 16LL) + 16LL) & 0x40) != 0)
  {
    ClearNameUI();
    id->func_ans = -1;
  }
  else
  {
    nmeUpdate1st(v10);
    GBWK->BaseRate += 2;
    if (GBWK->BaseRate >= 2304)
    {
      GBWK->BaseRate = 0;
    }
  }
  return 0;
}

// 0x188b5a0
void nmeUpdate1st(void) {
  u16 v3;
  UnityEngine_Object_o *name_input;
  UnityEngine_GameObject_o *inited;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v11;
  struct UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  u64 v15;
  s32 v16;
  struct nmeData_t_o *GBWK;
  s32 v18;
  s32 v21;
  Nme_Update_c *v22;

  v3 = cmpChkCommonInput(0x1000u);
  if (!op_Equality(name_input, 0, 0))
  {
      goto LABEL_23;
    goto LABEL_20;
  }
  inited = GetoNameUI();
  nameChange = inited;
  transform = get_transform(nameChange, 0);
  v11 = Find(transform, "nameinput", 0);
  gameObject = get_gameObject(v11);
  name_input = gameObject;
  Component_object = GetComponent_object_(name_input);
  _name_input = Component_object;
  if ((*(v15 + 295) & 2) != 0)
  {
LABEL_20:
  }
LABEL_23:
  if (*(*(*(v15 + 184) + 64LL) + 35LL) == 1)
  {
    nmeUpdateConfirm(v15);
    v16 = 2;
      goto LABEL_43;
  }
  else
  {
    v16 = 0;
    if ((*(v15 + 295) & 2) == 0)
      goto LABEL_43;
  }
  if (!*(v15 + 216))
  {
    if (!GBWK->CfmFlag)
      goto LABEL_30;
    return;
  }
LABEL_43:
  GBWK = *(*(v15 + 184) + 64LL);
  if (!GBWK->CfmFlag)
  {
LABEL_30:
    if (v16)
    {
      v18 = 0;
      if (v3 != 4096)
        goto LABEL_32;
LABEL_57:
      else if (nameOpeflag == 1)
      {
LABEL_60:
        v18 = 1;
        nameEndflag = 1;
        namecursur_flag = 0;
          goto LABEL_80;
        goto LABEL_33;
      }
      v3 = 0;
        goto LABEL_80;
      goto LABEL_33;
    }
    if (GBWK->ListCapFlag)
    {
      nmeUpdateListCapCursor(v15);
    }
    else
    {
      if (!GBWK->FuncFlag)
      {
        v18 = 0;
        v21 = 0;
          goto LABEL_55;
        goto LABEL_54;
      }
      if (nmeUpdateFuncCursor(v15))
      {
        v18 = 1;
        nameEndflag = 1;
        v21 = 1;
          goto LABEL_55;
        goto LABEL_54;
      }
    }
    v18 = 0;
    v21 = 1;
      goto LABEL_55;
LABEL_54:
LABEL_55:
    nmeUpdateInputMode(v22);
    if (v21)
      goto LABEL_56;
    goto LABEL_155;
  }
}

// 0x188bee0
void nmeUpdateBaseRate(void) {
  struct nmeData_t_o *GBWK;

  GBWK->BaseRate += 2;
  if (GBWK->BaseRate >= 2304)
  {
    GBWK->BaseRate = 0;
  }
}

// 0x188aa50
void nmeUpdateConfirm(void) {
  u16 v4;
  u32 v7;
  Il2CppObject *Component_object;
  struct System_String_array *name_des;
  TMPro_TMP_Text_o *namedes_textTM;
  System_String_o *v18;
  u64 *v19;
  s64 *v21;
  cmpCursorInfo_t_o *v23;
  cmpCursorInfo_t_o *v24;
  s8 v25;
  cmpCursorInfo_t_o *v27;
  s32 CursorIndex;
  Il2CppObject *v34;
  struct System_String_array *v37;
  System_String_o *v41;
  cmpCursorInfo_t_o *YesNoCursor;
  cmpCursorInfo_t_o *v47;
  cmpCursorInfo_t_o *v49;
  u16 v51;
  u64 i;
  u32 *nameTMPStr2;
  u32 *v58;
  struct cmpSeqInfo_t_o *SeqInfo;
  s32 v62;
  s32 v63;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  v7 = v4;
  if (yesnoflag != 1)
    goto LABEL_85;
  if (yesnoOpeflag != 1)
    goto LABEL_85;
  if (v4 > 2u)
  {
    if (v4 == 16)
    {
      nameInitflag = 0;
      YesNoCursor = GBWK->YesNoCursor;
      v24 = YesNoCursor;
      v25 = -1;
    }
    else
    {
      if (v4 != 32)
        goto LABEL_85;
      nameInitflag = 0;
      v23 = GBWK->YesNoCursor;
      v24 = v23;
      v25 = 1;
    }
    cmpMoveCursor(v24, v25);
LABEL_85:
      goto LABEL_88;
    goto LABEL_86;
  }
  if (v4 != 1)
  {
    if (v4 == 2)
    {
      namecursur_flag = 0;
      nameInputResetflag = 0;
      Chackflag = 0;
      PlistUpdateflag = 1;
      nameInitflag = 0;
      endChoiceflag = 0;
      name_count = 2;
      yesnoswith = 0;
      yesnoflag = 0;
      yesnoOpeflag = 0;
      yesnoOpeCnt = 0;
      nmeInitEntryType(0, &GBWK);
      Component_object = GetComponent_object_(name_description);
      namedes_text = Component_object;
      v18 = name_des->m_Items[1];
      v62 = 22;
      v19 = NewSpecific(object, 1u);
      v21 = sub_8D3950(s32, &v62);
      if (!v21)
        goto LABEL_67;
      goto LABEL_65;
    }
    goto LABEL_85;
  }
  v27 = GBWK->YesNoCursor;
  CursorIndex = cmpGetCursorIndex(v27);
  if (CursorIndex)
  {
    if (yesnoswith == 1)
    {
      namecursur_flag = 0;
      nameInputResetflag = 0;
      Chackflag = 0;
      PlistUpdateflag = 1;
      nameInitflag = 0;
      endChoiceflag = 0;
      name_count = 2;
      yesnoswith = 0;
      yesnoflag = 0;
      yesnoOpeflag = 0;
      yesnoOpeCnt = 0;
      nmeInitEntryType(0, &GBWK);
      v34 = GetComponent_object_(name_description);
      namedes_text = v34;
      v37 = name_des;
      v18 = v37->m_Items[1];
      v63 = 22;
      v19 = NewSpecific(object, 1u);
      v21 = sub_8D3950(s32, &v63);
      if (!v21)
      {
LABEL_67:
        v19[4] = v21;
        v41 = RepColTag(v18, v19);
        set_text(namedes_textTM, v41);
          goto LABEL_88;
LABEL_86:
        goto LABEL_88;
      }
LABEL_65:
      goto LABEL_67;
    }
    goto LABEL_85;
  }
  Chackflag = 0;
  defnameChackflag = 0;
  defnameflag = 0;
  PlistUpdateflag = 1;
  nameOpeflag = 0;
  nameInitflag = 0;
  name_fadecnt = 0;
  apoInitflag = 0;
  apoEndInitflag = 0;
  ButtonGuideDispOff();
  for (i = 0; i != 8; ++i)
  {
    v58 = &nameTMPStr2[2 * i];
    *(v58 + 4) = "";
  }
  GBWK->CfmFlag = 2;
  SeqInfo = GBWK->SeqInfo;
  SeqInfo->Flag |= 0x10u;
  nmeFadeOut();
  ReturnEventObject();
    goto LABEL_86;
LABEL_88:
  if (!cmpChkPadPressUpDown())
  {
    v47 = GBWK->YesNoCursor;
    cmpMoveCursor(v47, 0);
  }
  v49 = GBWK->YesNoCursor;
  v51 = cmpDisablePadBitStop(v49, v7, 0x30u);
  else if (nameInitflag)
  {
    return;
  }
  cmpPlaySE2(v51, 2);
}

// 0x1889520
s8 nmeUpdateFuncCursor(void) {
  u16 v3;
  s8 CursorIndex;
  cmpCursorInfo_t_o *v8;
  s8 v9;
  s8 v12;
  Nme_Update_c *v13;
  cmpCursorInfo_t_o *v16;
  s8 v17;
  cmpCursorInfo_t_o *FuncCursor;
  s8 InputModeColumnMax;
  struct cmpCursorInfo_t_array *CharCursor;
  s8 v26;
  cmpCursorInfo_t_o *v28;
  struct cmpCursorInfo_t_array *v34;
  cmpCursorInfo_t_o *v36;
  cmpCursorInfo_t_o *v40;
  cmpCursorInfo_t_o *v41;
  u16 v42;

  v3 = cmpChkCommonInput(0xF3u);
  CursorIndex = cmpGetCursorIndex(GBWK->ModeCursor);
  if (v3 > 0x10u)
  {
    if (v3 == 32)
    {
      FuncCursor = GBWK->FuncCursor;
      cmpMoveCursor(FuncCursor, 1);
      v12 = 0;
      PlistUpdateflag = 1;
        goto LABEL_95;
      goto LABEL_82;
    }
    v9 = CursorIndex;
    if (v3 == 64)
    {
      GBWK->FuncFlag = 0;
      InputModeColumnMax = nmeGetInputModeColumnMax(v9);
      CharCursor = GBWK->CharCursor;
      v26 = InputModeColumnMax;
      v28 = CharCursor->m_Items[1];
      cmpSetCursorPos(v26 - 1, v28);
LABEL_78:
      v12 = 0;
      PlistUpdateflag = 1;
        goto LABEL_95;
      goto LABEL_82;
    }
    if (v3 == 128)
    {
      GBWK->FuncFlag = 0;
      PlistUpdateflag = 1;
      if (v9 == 3)
      {
        v12 = 0;
        GBWK->ListCapFlag = 1;
          goto LABEL_95;
        goto LABEL_82;
      }
      v34 = GBWK->CharCursor;
      v36 = v34->m_Items[1];
      cmpSetCursorPos(0, v36);
    }
  }
  else
  {
    switch (v3)
    {
      case 1u:
        if (nameOpeflag == 1)
        {
          v16 = GBWK->FuncCursor;
          switch (cmpGetCursorIndex(v16))
          {
            case 0:
              v17 = 1;
              break;
            case 1:
              v17 = -1;
              break;
            case 2:
              nmeDeleteCharCursorPos(1);
              v12 = 0;
                goto LABEL_95;
              goto LABEL_82;
            case 3:
              nameOpeflag = 0;
              v12 = 1;
                goto LABEL_95;
              goto LABEL_82;
            default:
              goto LABEL_94;
          }
          nmeMoveInputCursor(v17);
          v12 = 0;
            goto LABEL_95;
        }
        else
        {
          v12 = 0;
          v3 = 0;
            goto LABEL_95;
        }
        goto LABEL_82;
      case 2u:
        nmeBackSpace();
        v12 = 0;
          goto LABEL_95;
        goto LABEL_82;
      case 0x10u:
        v8 = GBWK->FuncCursor;
        cmpMoveCursor(v8, 255);
        goto LABEL_78;
    }
  }
LABEL_94:
  v12 = 0;
    goto LABEL_95;
LABEL_82:
LABEL_95:
  nmeSetRetLine(v13);
    goto LABEL_97;
LABEL_96:
  if (cmpChkPadPressUpDown())
  {
LABEL_98:
      goto LABEL_109;
    goto LABEL_99;
  }
LABEL_102:
  v40 = GBWK->FuncCursor;
  cmpMoveCursor(v40, 0);
  {
LABEL_99:
  }
LABEL_109:
  v41 = GBWK->FuncCursor;
  v42 = cmpDisablePadBitStop(v41, v3, 0x30u);
  cmpPlaySE(v42);
  return v12;
}

// 0x188a2b0
void nmeUpdateInputCursor(void) {
  u16 v2;
  u16 v5;
  struct cmpCursorInfo_t_array *v7;
  cmpCursorInfo_t_o *v9;
  Nme_Draw_c *v10;
  struct cmpCursorInfo_t_array *v12;
  struct cmpCursorInfo_t_array *v15;
  cmpCursorInfo_t_o *v17;
  struct cmpCursorInfo_t_array *CharCursor;
  cmpCursorInfo_t_o *v27;
  struct cmpCursorInfo_t_array *v30;
  struct cmpCursorInfo_t_array *v33;
  cmpCursorInfo_t_o *v35;
  struct cmpCursorInfo_t_array *v37;
  cmpCursorInfo_t_o *v38;
  struct cmpCursorInfo_t_array *v41;
  cmpCursorInfo_t_o *v42;
  u16 v44;
  struct cmpCursorInfo_t_array *v48;
  cmpCursorInfo_t_o *v50;
  struct cmpCursorInfo_t_array *v51;
  cmpCursorInfo_t_o *v53;
  u16 v54;

  v2 = cmpChkCommonInput(0xF3u);
  v5 = v2;
  if (v2 > 0x10u)
  {
    switch (v2)
    {
      case 0x20u:
        CharCursor = GBWK->CharCursor;
        v27 = CharCursor->m_Items[0];
        cmpMoveCursorEx(v27, 1, 0);
        PlistUpdateflag = 1;
          goto LABEL_101;
        goto LABEL_51;
      case 0x40u:
        v30 = GBWK->CharCursor;
        if (!nmeUpdateMoveEtcMode(v30->m_Items[1], 255))
        {
          v33 = GBWK->CharCursor;
          v35 = v33->m_Items[1];
          cmpMoveCursor(v35, 255);
          nameLeftflag = 1;
          if ((v10->_2.bitflags2 & 2) == 0)
            goto LABEL_99;
          goto LABEL_83;
        }
        break;
      case 0x80u:
        v12 = GBWK->CharCursor;
        if (!nmeUpdateMoveEtcMode(v12->m_Items[1], 1))
        {
          v15 = GBWK->CharCursor;
          v17 = v15->m_Items[1];
          cmpMoveCursor(v17, 1);
          nameRightflag = 1;
          if ((v10->_2.bitflags2 & 2) == 0)
            goto LABEL_99;
LABEL_83:
            goto LABEL_99;
          goto LABEL_20;
        }
        break;
      default:
        goto LABEL_100;
    }
      goto LABEL_99;
    goto LABEL_83;
  }
  if (v2 == 1)
  {
    if (nameOpeflag == 1)
    {
      nmeGetInputChar();
        goto LABEL_101;
      goto LABEL_51;
    }
LABEL_85:
    v5 = 0;
      goto LABEL_101;
    goto LABEL_51;
  }
  if (v2 == 2)
  {
    if (nameOpeflag == 1)
    {
      nmeBackSpace();
        goto LABEL_101;
      goto LABEL_51;
    }
    goto LABEL_85;
  }
  if (v2 != 16)
    goto LABEL_100;
  v7 = GBWK->CharCursor;
  v9 = v7->m_Items[0];
  cmpMoveCursorEx(v9, 255, 0);
    goto LABEL_99;
LABEL_20:
LABEL_99:
  PlistUpdateflag = 1;
LABEL_100:
    goto LABEL_101;
LABEL_51:
LABEL_101:
  if (cmpChkPadPressUpDown())
    goto LABEL_111;
LABEL_102:
  v37 = GBWK->CharCursor;
  v38 = v37->m_Items[0];
  cmpMoveCursor(v38, 0);
LABEL_111:
  v41 = GBWK->CharCursor;
  v42 = v41->m_Items[0];
  v44 = cmpDisablePadBitStop(v42, v5, 0x30u);
  if (cmpChkPadPressLR())
  {
      goto LABEL_132;
    goto LABEL_121;
  }
  v48 = GBWK->CharCursor;
  v50 = v48->m_Items[1];
  cmpMoveCursor(v50, 0);
  {
LABEL_121:
  }
LABEL_132:
  v51 = GBWK->CharCursor;
  v53 = v51->m_Items[1];
  v54 = cmpDisablePadBitStop(v53, v44, 0xC0u);
  cmpPlaySE2(v54, 1);
}

// 0x1889270
void nmeUpdateInputMode(void) {
  u32 v3;
  cmpCursorInfo_t_o *v5;
  cmpCursorInfo_t_o *v6;
  s8 v7;
  cmpCursorInfo_t_o *ModeCursor;
  s8 CursorIndex;
  cmpCursorInfo_t_o *v15;
  cmpCursorInfo_t_o *v17;
  u16 v18;

  v3 = cmpChkCommonInput(0x300u);
  if (v3 == 512)
  {
    ModeCursor = GBWK->ModeCursor;
    v6 = ModeCursor;
    v7 = 1;
  }
  else
  {
    if (v3 != 256)
      goto LABEL_29;
    v5 = GBWK->ModeCursor;
    v6 = v5;
    v7 = -1;
  }
  cmpMoveCursor(v6, v7);
  CursorIndex = cmpGetCursorIndex(GBWK->ModeCursor);
  nmeInitInputMode(CursorIndex, &GBWK);
  PlistUpdateflag = 1;
LABEL_29:
  else if (cmpChkPadPressL1R1())
  {
    goto LABEL_40;
  }
  v15 = GBWK->ModeCursor;
  cmpMoveCursor(v15, 0);
LABEL_40:
  v17 = GBWK->ModeCursor;
  v18 = cmpDisablePadBitStop(v17, v3, 0x300u);
  cmpPlaySE(v18);
}

// 0x1889be0
void nmeUpdateListCapCursor(void) {
  u16 v3;
  u32 v4;
  s8 CursorIndex;
  struct cmpCursorInfo_t_array *v10;
  cmpCursorInfo_t_o *v12;
  s32 v13;
  cmpCursorInfo_t_o *v14;
  Nme_Update_c *v16;
  s8 v18;
  s8 InputModeColumnMax;
  struct cmpCursorInfo_t_array *CharCursor;
  s8 v24;
  cmpCursorInfo_t_o *v26;

  v3 = cmpChkCommonInput(0xF3u);
  v4 = v3;
  CursorIndex = cmpGetCursorIndex(GBWK->ModeCursor);
  if (v3 > 0x10u)
  {
    switch (v3)
    {
      case 0x20u:
        nmeMoveListCapLine(1);
        PlistUpdateflag = 1;
          goto LABEL_69;
        goto LABEL_62;
      case 0x40u:
        v18 = CursorIndex;
        GBWK->ListCapFlag = 0;
        GBWK->FuncFlag = 1;
        PlistUpdateflag = 1;
        InputModeColumnMax = nmeGetInputModeColumnMax(v18);
        CharCursor = GBWK->CharCursor;
        v24 = InputModeColumnMax;
        v26 = CharCursor->m_Items[1];
        v13 = v24 - 1;
        v14 = v26;
        break;
      case 0x80u:
        GBWK->ListCapFlag = 0;
        PlistUpdateflag = 1;
        v10 = GBWK->CharCursor;
        v12 = v10->m_Items[1];
        v13 = 0;
        v14 = v12;
        break;
      default:
        goto LABEL_61;
    }
    cmpSetCursorPos(v13, v14);
LABEL_61:
      goto LABEL_69;
LABEL_62:
LABEL_69:
    nmeSetRetLine(v16);
      goto LABEL_71;
LABEL_70:
LABEL_71:
    if (cmpChkPadPressUpDown())
      goto LABEL_72;
    goto LABEL_76;
  }
  if (v3 != 1)
  {
    if (v3 == 2)
    {
      nmeBackSpace();
        goto LABEL_69;
      goto LABEL_62;
    }
    if (v3 == 16)
    {
      nmeMoveListCapLine(255);
      PlistUpdateflag = 1;
        goto LABEL_69;
      goto LABEL_62;
    }
    goto LABEL_61;
  }
}

// 0x188a060
s8 nmeUpdateMoveEtcMode(cmpCursorInfo_t *pCursorInfo, s8 Dir) {
  cmpCursorInfo_t_o *ModeCursor;
  s8 CursorIndex;
  s32 v11;

  ModeCursor = GBWK->ModeCursor;
  CursorIndex = cmpGetCursorIndex(ModeCursor);
  if (cmpChkPadBitStop(pCursorInfo))
    return 0;
  if (Dir >= 1)
  {
    v11 = cmpGetCursorIndex(pCursorInfo);
    if (v11 == nmeGetInputModeColumnMax(CursorIndex) - 1)
    {
      GBWK->FuncFlag = 1;
        goto LABEL_39;
      goto LABEL_23;
    }
    return 0;
  }
  if (!Dir)
    return 0;
  if (cmpGetCursorIndex(pCursorInfo))
    return 0;
  if (CursorIndex != 3)
  {
    GBWK->FuncFlag = 1;
      goto LABEL_39;
LABEL_23:
LABEL_39:
    nmeInitFuncCursor(255, &GBWK);
    return 1;
  }
  GBWK->ListCapFlag = 1;
  return 1;
}
