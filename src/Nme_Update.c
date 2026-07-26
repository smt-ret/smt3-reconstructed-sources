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
  struct Nme_Update_StaticFields *static_fields;
  nmeData_t_o **p_GBWK;

  static_fields = Nme_Update->static_fields;
  p_GBWK = &static_fields->GBWK;
  if (nmeChkEntryType(p_GBWK) == 1)
  {
    if (((*p_GBWK)->InputPos - 4) < 1)
  }
  else  nmeMoveInputCursor(255);
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
  struct Nme_Update_StaticFields *static_fields;
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

  static_fields = Nme_Update->static_fields;
  p_GBWK = &static_fields->GBWK;
  if (nmeChkEntryType(p_GBWK) == 1)
  {
    LOBYTE(v6) = (*p_GBWK)->InputPos - 4;
  }
  else
  {
    LOBYTE(v6) = (*p_GBWK)->InputPos;
  }
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
    }
    else
    {
      {
        nmeDeleteEndSpace(v12);
        return;
      }
    }
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
  struct Nme_Update_StaticFields *static_fields;
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
  static_fields = Nme_Update->static_fields;
  p_GBWK = &static_fields->GBWK;
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
  v57 = GBWK->InputNums;
  ++v57->m_Items[v37];
  {
  }
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
  struct Nme_Update_StaticFields *static_fields;
  nmeData_t_o **p_GBWK;
  s8 InputPos;
  s8 inited;
  struct nmeData_t_o *GBWK;
  s8 v12;

  static_fields = Nme_Update->static_fields;
  p_GBWK = &static_fields->GBWK;
  if (nmeChkEntryType(p_GBWK) == 1)
  {
    InputPos = (*p_GBWK)->InputPos - 4;
  }
  else
  {
    InputPos = (*p_GBWK)->InputPos;
  }
  inited = nmeChkEntryType(&GBWK);
  if (inited == 2)
  {
    if (Dir < 1)
  }
  if (inited == 1)
  {
    if (Dir < 1)
    {
      if (!Dir)
        return;
    }
    if (nmeGetInputCharMax(&GBWK) - 1 <= InputPos)
      return;
    v12 = GBWK->InputPos + 1;
  }
  if (inited)
    return;
  if (Dir >= 1)
  if (Dir && InputPos >= 1)
  {
    v12 = GBWK->InputPos - 1;
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
  while (!op_Inequality(v18, StringLiteral_5526, 0));
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
    dds3GetProcessData(0);
    dds3FadeCheck();
    ClearNameUI();
    nmeUpdate1st();
    return 0;
}

// 0x188b5a0
void nmeUpdate1st(void) {
    GetoNameUI();
    nmeUpdateConfirm();
    nmeUpdateListCapCursor();
    nmeUpdateFuncCursor();
    nmeUpdateInputMode();
    nmeUpdateInputCursor();
    nmeChkInvalidName(0);
    nmeInitEntryType(0, 0);
    DefNameDraw();
    nmeSetDefaultName(0, 0);
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
    nmeInitEntryType(0, 0);
    RepColTag(0, 0);
    ButtonGuideDispOff();
    nmeFadeOut();
    ReturnEventObject();
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
      v12 = 0;
      PlistUpdateflag = 1;
    }
    if (v3 == 128)
    {
      GBWK->FuncFlag = 0;
      PlistUpdateflag = 1;
      if (v9 == 3)
      {
        v12 = 0;
        GBWK->ListCapFlag = 1;
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
            case 3:
              nameOpeflag = 0;
              v12 = 1;
            default:
          }
          nmeMoveInputCursor(v17);
          v12 = 0;
        }
        else
        {
          v12 = 0;
          v3 = 0;
        }
      case 2u:
        nmeBackSpace();
        v12 = 0;
      case 0x10u:
        v8 = GBWK->FuncCursor;
        cmpMoveCursor(v8, 255);
    }
  }
  v12 = 0;
  nmeSetRetLine(v13);
  v40 = GBWK->FuncCursor;
  cmpMoveCursor(v40, 0);
  {
  }
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
      case 0x40u:
        v30 = GBWK->CharCursor;
        if (!nmeUpdateMoveEtcMode(v30->m_Items[1], 255))
        {
          v33 = GBWK->CharCursor;
          v35 = v33->m_Items[1];
          cmpMoveCursor(v35, 255);
          nameLeftflag = 1;
          if ((v10->_2.bitflags2 & 2) == 0)
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
        }
        break;
      default:
    }
  }
  if (v2 == 1)
  {
    if (nameOpeflag == 1)
    {
      nmeGetInputChar();
    }
    v5 = 0;
  }
  if (v2 == 2)
  {
    if (nameOpeflag == 1)
    {
      nmeBackSpace();
    }
  }
  if (v2 != 16)
  v7 = GBWK->CharCursor;
  v9 = v7->m_Items[0];
  cmpMoveCursorEx(v9, 255, 0);
  PlistUpdateflag = 1;
  if (cmpChkPadPressUpDown())
  v37 = GBWK->CharCursor;
  v38 = v37->m_Items[0];
  cmpMoveCursor(v38, 0);
  v41 = GBWK->CharCursor;
  v42 = v41->m_Items[0];
  v44 = cmpDisablePadBitStop(v42, v5, 0x30u);
  v48 = GBWK->CharCursor;
  v50 = v48->m_Items[1];
  cmpMoveCursor(v50, 0);
  {
  }
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
    v5 = GBWK->ModeCursor;
    v6 = v5;
    v7 = -1;
  }
  cmpMoveCursor(v6, v7);
  CursorIndex = cmpGetCursorIndex(GBWK->ModeCursor);
  nmeInitInputMode(CursorIndex, &GBWK);
  PlistUpdateflag = 1;
  else  v15 = GBWK->ModeCursor;
  cmpMoveCursor(v15, 0);
  v17 = GBWK->ModeCursor;
  v18 = cmpDisablePadBitStop(v17, v3, 0x300u);
  cmpPlaySE(v18);
}

// 0x1889be0
void nmeUpdateListCapCursor(void) {
    nmeMoveListCapLine(0);
    nmeGetInputModeColumnMax(0);
    nmeSetRetLine(0);
    nmeBackSpace();
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
    nmeInitFuncCursor(255, &GBWK);
    return 1;
  }
  GBWK->ListCapFlag = 1;
  return 1;
}
