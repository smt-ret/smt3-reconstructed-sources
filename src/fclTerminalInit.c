#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct cmpCmdSelInfo_t cmpCmdSelInfo_t;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataTerminal_t fclDataTerminal_t;
typedef struct fclPanel_t fclPanel_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static char *gFclTerminalTexFile;
static fclDataTerminal_t *GBWK;
static s8 gCallMode;
static s32 gProcessStat;
static s32 gEventStat;
static char *gNmlTerminalMenuStr[4];
static char *gNmlTerminalMenuStr2[4];
static char *gNmlTerminalMenuStr3[4];
static char *gSmlTerminalMenuStr[4];
static s8 FCL_NML_TERM_MENU_ARRAY;
static s8 FCL_SML_TERM_MENU_ARRAY;
static u8 *gCommandFlag;

void ButtonGuideDispOff(void);
s32 CMP_XM(s32 a);
s32 CMP_YM(s32 b);
void DLCTerminalList(fclDataTerminal_t **term);
void FadeOutWindow(void);
void FilterDelete(void);
void FinalizeGameObject(void);
void FinalizeUI(void);
s32 FindId(s32 type, char *name);
char *GetAppendix(void);
void InitializeGameObject(void);
void InitializeModelCameraForUnity(void);
void InitializeUI(s32 eventno);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void LoadLocalizeText(char *key, char *filename);
void Remove(char *key);
void SetButtonGuide(s32 mode, bool sw);
void SetRootMenuText(cmpCmdSelInfo_t **csel, char **menu);
void UnloadAB(AssetBundleCtrl *this, char *key);
void WindowDispOff(bool sw);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtStartEvent(s32 no);
void fclFreeStage(void);
fclDataTerminal_t *fclInitTerminal(s32 TerminalType, s32 TerminalNo, cmpSeqInfo_t *pParentSeqInfo);
void fclInitTerminalCore(s32 TerminalType, s32 TerminalNo, fclDataTerminal_t *pData, bool flg);
void fclScriptForcedEnd(dds3ProcessID_t *PID);
void fclSetPanelTex(fclPanel_t *pPanel, u32 UV1, u32 UV2, u32 UV3, u32 UV4, sdfTexHandle_t *TexHandle);
void fldProcSetTerminal(s32 type, s32 idx);
bool fldProc_CallSisetuReturn(void);
void lstInitListWindow(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Style, lstListWindow_t *pListWindow);
void nbResetEncountCount(void);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
s32 scrGetIntPara(s32 n);
void scrSetIntReturnValue(s32 i);
s32 trmChkJumpSmallToLearge(fclDataTerminal_t *pData);
s8 trmCreateEventProcessName(s32 Type, char **pBuf);
void trmCreateTerminalList(fclDataTerminal_t *pDataTerminal);
void trmEndBGM(void);
s32 trmGetEventNo(s32 Mode, fclDataTerminal_t *pData);
void trmInitRootMenu(s8 TerminalType, u16 TerminalNo, cmpCmdSelInfo_t *pCmdSelInfo, fclDataTerminal_t *pData);
void trmInitTransWindow(lstListWindow_t *pListWindow, s8 TerminalCount, sdfTexHandle_t *TexHandle);
void trmSetNmlRootMenu(u16 TerminalNo, cmpCmdSelInfo_t *pCmdSelInfo, fclDataTerminal_t *pData);
void trmStartBGM(s32 TerminalType, s32 TerminalNo, bool nocheck);

// 0xf7de90
s8 fclChkTerminalProcess(void) {
  s32 gProcessStat;
  bool v4;
  u32 v5;
  char v6;

  v4 = gProcessStat == 0;
  v5 = gProcessStat - 1;
  v6 = !v4;
  return (v5 < 2) & v6;
}

// 0xf7d690
void *fclDestroyTerminal(dds3ProcessID_t *PID) {
  struct fclTerminalInit_StaticFields **p_static_fields;
  struct fclDataTerminal_t_o *GBWK;
  s32 TerminalType;
  s32 TerminalNo;
  dds3ProcessID_t_o *ScriptPID;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v19;
  AssetBundleCtrl_o *v20;
  System_String_o *Appendix;
  System_String_o *v22;

  if (GBWK)
  {
    gProcessStat = 0;
    GBWK = (*p_static_fields)->GBWK;
    TerminalType = GBWK->TerminalType;
    TerminalNo = GBWK->TerminalNo;
    fldProcSetTerminal(TerminalType, TerminalNo);
    ScriptPID = GBWK->ScriptPID;
    fclScriptForcedEnd(ScriptPID);
    FinalizeGameObject();
    FinalizeUI();
    Remove("TERMINAL_MES_DATA", 0);
    Remove("FACILITY", 0);
    WindowDispOff(0);
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, "f804");
    v19 = get_asset_bc();
    UnloadAB(v19, "e804");
    v20 = get_asset_bc();
    Appendix = GetAppendix();
    v22 = Concat_5224608("e804", Appendix);
    UnloadAB(v20, v22);
    GBWK = 0;
    trmEndBGM();
  }
  PID->func_ans = -1;
  return 0;
}

// 0xf7cb00
fclDataTerminal_t *fclInitTerminal(s32 TerminalType, s32 TerminalNo, cmpSeqInfo_t *pParentSeqInfo) {
  u16 v5;
  s8 v6;
  fclDataTerminal_t_o *v7;
  cmpSeqInfo_t_o *SeqInfo;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *Appendix;
  System_String_o *v15;
  System_String_o *v16;
  System_String_o *v17;
  AssetBundleCtrl_o *v18;
  AssetBundleCtrl_o *v19;
  struct cmpSeqInfo_t_o *v21;

  v5 = TerminalNo;
  v6 = TerminalType;
  v7 = Allocate(fclDataTerminal_t);
  fclDataTerminal_t___ctor(v7);
  FilterDelete();
  SeqInfo = v7->SeqInfo;
  cmpInitSeqInfo(SeqInfo, pParentSeqInfo);
  asset_bc = get_asset_bc();
  Appendix = GetAppendix();
  v15 = Concat_5224608("e804", Appendix);
  v16 = GetAppendix();
  v17 = Concat_5224608("e804", v16);
  Load(asset_bc, v15, v17, 0);
  v18 = get_asset_bc();
  Load(v18, "e804", "e804", 0);
  v19 = get_asset_bc();
  Load(v19, "f804", "f804", 0);
  v21 = v7->SeqInfo;
  v7->Initialized = 0;
  v21->Current = 0;
  v7->SeqInfo->Last = 0;
  v7->SeqInfo->Change = 1;
  v7->ScriptPID = 0;
  v7->TerminalType = v6;
  v7->TerminalNo = v5;
LABEL_19:
  gEventStat = 0;
  nbResetEncountCount();
  InitializeModelCameraForUnity();
  return v7;
}

// 0xf7c9d0
void fclInitTerminalCore(s32 TerminalType, s32 TerminalNo, fclDataTerminal_t *pData, bool flg) {
  u16 v7;
  s8 v8;
  cmpCmdSelInfo_t_o *CmdSelInfo;
  lstListWindow_t_o *TransWindow;
  s8 TerminalCnt;
  struct sdfTexHandle_t_array *TexHandle;
  sdfTexHandle_t_o *v16;

  v7 = TerminalNo;
  v8 = TerminalType;
  pData->TerminalType = v8;
  pData->TerminalNo = v7;
  else
  {
    trmCreateTerminalList(pData, *&TerminalNo);
    if (!flg)
      goto LABEL_10;
  }
  CmdSelInfo = pData->CmdSelInfo;
  trmInitRootMenu(v8, v7, CmdSelInfo, pData);
LABEL_10:
  TransWindow = pData->TransWindow;
  TerminalCnt = pData->TerminalCnt;
  TexHandle = pData->TexHandle;
  v16 = TexHandle->m_Items[0];
  trmInitTransWindow(TransWindow, TerminalCnt, v16);
}

// 0xf7dfb0
s32 fclTerminal(void) {
  u32 gProcessStat;
  s32 gEventStat;
  AssetBundleCtrl_o *asset_bc;

  else
  {
    if (gProcessStat >= 2)
      goto LABEL_6;
  }
  gCallMode = 1;
  if (gEventStat == 5)
  {
    gEventStat = 3;
    GBWK->SeqInfo->Current = 0;
    GBWK->SeqInfo->Change = 1;
    GBWK->EventEnd = 0;
    goto LABEL_42;
  }
  if (gEventStat != 4)
  {
    if (gEventStat == 2)
    {
      asset_bc = get_asset_bc();
      if (IsLoad(asset_bc, "e804"))
      {
        trmStartBGM(GBWK->TerminalType, GBWK->TerminalNo, 0);
        gEventStat = 3;
      }
    }
    goto LABEL_42;
  }
  gEventStat = 5;
  scrSetIntReturnValue(2);
  return 1;
}

// 0xf7e5e0
s32 fclTerminalDisableTalk(void) {
  struct System_Byte_array *gCommandFlag;
  struct fclDataTerminal_t_o *GBWK;
  struct cmpCursorPos_t_o *CursorPos;

  gCommandFlag->m_Items[2] |= 2u;
  if (GBWK)
  {
    CursorPos = GBWK->CmdSelInfo->CursorInfo->CursorPos;
    ++CursorPos->InvisibleListNums;
  }
  return 1;
}

// 0xf7e500
s32 fclTerminalEnableTalk(void) {
  struct System_Byte_array *gCommandFlag;
  struct fclDataTerminal_t_o *GBWK;
  struct cmpCursorPos_t_o *CursorPos;

  gCommandFlag->m_Items[2] &= ~2u;
  if (GBWK)
  {
    CursorPos = GBWK->CmdSelInfo->CursorInfo->CursorPos;
    --CursorPos->InvisibleListNums;
  }
  return 1;
}

// 0xf7e2f0
s32 fclTerminalMenuMask(void) {
  s32 IntPara;
  struct System_Byte_array *gCommandFlag;

  IntPara = scrGetIntPara(0);
  else
  {
    if (IntPara >= FCL_NML_TERM_MENU_ARRAY)
      return 1;
  }
  gCommandFlag->m_Items[IntPara] |= 1u;
  return 1;
}

// 0xf7e400
s32 fclTerminalMenuMaskDef(void) {
  s64 v2;
  u64 v4;
  struct System_Byte_array *gCommandFlag;

  v2 = 32;
  v4 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v4 >= FCL_NML_TERM_MENU_ARRAY)
      return 1;
    else
    {
      if (v4 >= LODWORD(gCommandFlag->max_length))
        goto LABEL_12;
    }
    *(&gCommandFlag->obj.klass + v2++) = 0;
    v4 = v2 - 32;
      goto LABEL_6;
  }
}

// 0xf7dd60
s32 fclTerminalProcessEnd(void) {
  if (evtBitCheck(58))
    goto LABEL_7;
  if (!fldProc_CallSisetuReturn())
    return 0;
LABEL_7:
  FadeOutWindow();
  dds3KillProcessName("terminal", 1);
  dds3KillProcessName("terminal_draw", 1);
  dds3KillProcessName("terminal_update", 1);
  return 1;
}

// 0xf7db00
void fclTerminalProcessStart(s32 TerminalType, s32 TerminalNo) {
  u64 *v7;
  Il2CppObject *data;
  u64 *v10;
  u64 *v11;
  u64 *v12;

  else if (GBWK)
  {
    return;
  }
  GBWK = fclInitTerminal(TerminalType, TerminalNo, 0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_fclTerminalCalc_trmCalc__);
  data = GBWK;
  dds3StartProcess("terminal", 0x404u, 1, 1, v7, 0, 0, 0, data, 0);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_fclTerminalDraw_trmDraw__);
  dds3StartProcess(
    "terminal_draw",
    0x2B14u,
    1,
    1,
    v10,
    0,
    0,
    0,
    GBWK,
    0);
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_fclTerminalUpdate_trmUpdate__);
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_fclTerminalInit_fclDestroyTerminal__);
  dds3StartProcess(
    "terminal_update",
    0x5210u,
    1,
    1,
    v11,
    0,
    v12,
    0,
    GBWK,
    0);
  gCallMode = 0;
  gProcessStat = 1;
}

// 0xf7c9c0
void fclTerminalTexFree(fclDataTerminal_t *pData) {
  ;
}

// 0xf7c9b0
void fclTerminalTexLoad(fclDataTerminal_t *pData) {
  ;
}

// 0xf7df10
void fclTerminateTerminal(void) {
  struct fclDataTerminal_t_o *GBWK;

  if (GBWK)
  {
    GBWK->SeqInfo->Flag |= 0x10u;
  }
}

// 0xf7cda0
void fclUpdateTerminalInit(fclDataTerminal_t *data) {
  AssetBundleCtrl_o *asset_bc;
  s32 TerminalType;
  s32 TerminalNo;

  LoadKeys(1, "e804", 0);
  LoadKeys(3, "e804", 0);
  asset_bc = get_asset_bc();
  data->pScriptData = LoadFileByte(asset_bc, "e804", "dds3data/facility/scr/terminal/message.bf.bytes");
  LoadLocalizeText("e804", "TERMINAL_MES_DATA");
  LoadLocalizeText("common", "FACILITY");
  InitializeUI(804);
  InitializeGameObject();
  TerminalType = data->TerminalType;
  TerminalNo = data->TerminalNo;
  fclInitTerminalCore(TerminalType, TerminalNo, data, 1);
  SetButtonGuide(0, 0);
  ButtonGuideDispOff();
  data->EventEnd = 0;
}

// 0xf78580
s8 trmChkEventWait(void) {
  System_String_o *v7;
  System_String_o *pBuf;

  pBuf = "";
LABEL_7:
  else if (gEventStat == 2)
  {
    return 1;
  }
  else if (gEventStat != 6)
  {
    return 0;
  }
  trmCreateEventProcessName(0, &pBuf);
  v7 = pBuf;
  else if (dds3SearchProcessName(pBuf))
  {
    return 1;
  }
  return 0;
}

// 0xf7c5e0
s32 trmChkJumpSmallToLearge(fclDataTerminal_t *pData) {
  s64 i;
  struct System_SByte_array *TerminalList;
  u64 *v7;
  struct System_SByte_array *v9;
  s32 v12;
  s64 v13;
  char v15[4];

  if (pData->TerminalCnt < 1)
    return 0;
  for (i = 32; ; ++i)
  {
    TerminalList = pData->TerminalList;
    v15[0] = *(&TerminalList->obj.klass + i);
    v7 = sub_8D3950(sbyte, v15);
    Write_2930400("{0:x}\n", v7);
    v9 = pData->TerminalList;
    v12 = *(&v9->obj.klass + i);
    if (v12 == *(&_get_Item(
                     fldHitData->_fldSaveSml,
                     pData->TerminalNo)->isLongReference
                + 1))
      break;
    v13 = i - 31;
    if (v13 >= pData->TerminalCnt)
      return 0;
  }
  return 1;
}

// 0xf7ba80
s8 trmCreateEventProcessName(s32 Type, char **pBuf) {
  s32 EventNo;
  u64 *v7;
  s64 *v8;
  s32 v10;
  s32 v11;

  EventNo = trmGetEventNo(1, GBWK);
  if (EventNo < 0)
    return 0;
  if (Type)
  {
    v10 = EventNo;
    v7 = sub_8D3950(s32, &v10);
    v8 = &"e{0:D}_trm";
  }
  else
  {
    v11 = EventNo;
    v7 = sub_8D3950(s32, &v11);
    v8 = &"e{0:D}_main";
  }
  *pBuf = Format(*v8, v7, 0);
  return 1;
}

// 0xf7bf20
void trmCreateTerminalList(fclDataTerminal_t *pDataTerminal) {
  u64 i;
  struct System_Int32_array *gFldSaveNmlIdxTbl;
  s32 v7;
  System_WeakReference_o *Item;
  u32 TerminalCnt;
  struct System_SByte_array *TerminalList;
  u64 *v16;
  s8 v17[4];
  fclDataTerminal_t_o *term;

  term = pDataTerminal;
  pDataTerminal->TerminalCnt = 0;
  for (i = 0; i != 32; ++i)
  {
    v7 = gFldSaveNmlIdxTbl->m_Items[i];
    if (term->TerminalType || v7 != term->TerminalNo)
    {
      if (*(&_get_Item(
                fldHitData->_fldSaveNml,
                v7)->isLongReference
           + 1))
      {
        Item = _get_Item(
                 fldHitData->_fldSaveNml,
                 v7);
        if (evtBitCheck(*(&Item->isLongReference + 1), 0))
        {
          TerminalCnt = term->TerminalCnt;
          TerminalList = term->TerminalList;
          ++term->TerminalCnt;
          TerminalList->m_Items[TerminalCnt] = v7;
        }
      }
    }
  }
  if (evtBitCheck(1217))
  {
    DLCTerminalList(&term);
  }
  v17[0] = term->TerminalCnt;
  v16 = sub_8D3950(sbyte, v17);
  Write_2930400("Transport count = {0:D}\n", v16);
}

// 0xf7bb80
void trmEndBGM(void) {
  s32 Id;

  Id = FindId(0, "TERM_BGM01");
  p2sdFadeOut(Id);
}

// 0xf7bc20
s8 trmEndEvent(s32 BgmMode) {
  dds3ProcessID_t_o *ScriptPID;
  System_String_o *v10;
  System_String_o *pBuf;

  pBuf = "";
  if (BgmMode)
  {
    trmEndBGM();
  }
  ScriptPID = GBWK->ScriptPID;
  fclScriptForcedEnd(ScriptPID);
  GBWK->ScriptPID = 0;
  gEventStat = 0;
  if (trmCreateEventProcessName(0, &pBuf))
  {
    v10 = pBuf;
    dds3KillProcessName(v10, 0);
    trmCreateEventProcessName(1, &pBuf);
    dds3KillProcessName(pBuf, 0);
    fclFreeStage();
  }
  return 1;
}

// 0xf78a70
s8 trmGetCallMode(void) {
  return gCallMode;
}

// 0xf7b600
s32 trmGetEventNo(s32 Mode, fclDataTerminal_t *pData) {
  struct System_Byte_array *gCommandFlag;
  struct cmpCursorPos_t_o *CursorPos;
  s32 v9;
  u32 TerminalNo;
  bool v11;
  struct System_Byte_array *v14;
  struct cmpCursorPos_t_o *v16;
  struct System_Byte_array *v18;
  struct cmpCursorPos_t_o *v20;
  struct System_Byte_array *v21;
  struct cmpCursorPos_t_o *v23;
  struct System_Byte_array *v24;
  struct cmpCursorPos_t_o *v26;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *v29;

  if (pData->TerminalType)
  {
    if (!evtBitCheck(13))
    {
      gCommandFlag->m_Items[0] |= 2u;
      if (Mode)
      {
        CursorPos = pData->CmdSelInfo->CursorInfo->CursorPos;
        ++CursorPos->InvisibleListNums;
      }
    }
    v9 = 805;
  }
  else
  {
    TerminalNo = pData->TerminalNo;
    if (TerminalNo > 9)
    {
      if ((TerminalNo & 0xFFFE) == 0x12 || TerminalNo - 23 <= 1)
      {
        v14 = gCommandFlag;
        v14->m_Items[0] |= 2u;
        if (Mode)
        {
          v16 = pData->CmdSelInfo->CursorInfo->CursorPos;
          ++v16->InvisibleListNums;
        }
        v9 = 806;
      }
      else
      {
LABEL_21:
        v9 = 804;
      }
    }
    else
    {
      v9 = 804;
      switch (pData->TerminalNo)
      {
        case 1u:
          if (evtBitCheck(13))
            goto LABEL_21;
          v11 = evtBitCheck(9);
          if (v11)
          {
              goto LABEL_52;
            goto LABEL_50;
          }
          v24 = gCommandFlag;
          v24->m_Items[0] |= 2u;
          if (Mode)
          {
            v26 = pData->CmdSelInfo->CursorInfo->CursorPos;
            ++v26->InvisibleListNums;
          }
          v9 = 619;
          break;
        case 2u:
          if (evtBitCheck(13))
            goto LABEL_21;
          if (evtBitCheck(9) && evtBitCheck(10))
          {
            v18 = gCommandFlag;
            v18->m_Items[0] |= 2u;
            if (Mode)
            {
              v20 = pData->CmdSelInfo->CursorInfo->CursorPos;
              ++v20->InvisibleListNums;
            }
            v9 = 623;
          }
          else
          {
            {
LABEL_50:
            }
LABEL_52:
            v21 = gCommandFlag;
            v21->m_Items[0] |= 2u;
            if (!Mode)
              goto LABEL_21;
            v23 = pData->CmdSelInfo->CursorInfo->CursorPos;
            ++v23->InvisibleListNums;
            v9 = 804;
          }
          break;
        case 3u:
          v9 = 804;
          if (!evtBitCheck(52))
          {
            if (evtBitCheck(14))
              v9 = 640;
            else
              v9 = 804;
          }
          break;
        case 9u:
          if (evtBitCheck(83))
            goto LABEL_21;
          if (evtBitCheck(79))
          {
            v9 = 662;
          }
          else if (evtBitCheck(75))
          {
            v9 = 660;
          }
          else if (evtBitCheck(68))
          {
            v9 = 656;
          }
          else if (evtBitCheck(62))
          {
            v9 = 652;
          }
          else
          {
            v9 = 646;
          }
          break;
        default:
          break;
      }
    }
  }
  CursorInfo = pData->CmdSelInfo->CursorInfo;
  v29 = gCommandFlag;
  cmpSetCursorFlag(CursorInfo, v29);
  return v9;
}

// 0xf7b520
s32 trmGetEventStat(void) {
  return gEventStat;
}

// 0xf7c760
void trmInitRootMenu(s8 TerminalType, u16 TerminalNo, cmpCmdSelInfo_t *pCmdSelInfo, fclDataTerminal_t *pData) {
  System_String_array *gSmlTerminalMenuStr;
  cmpCursorInfo_t_o *CursorInfo;
  struct System_Byte_array *v20;
  struct System_Byte_array *gCommandFlag;
  System_Byte_array *v24;
  cmpCmdSelInfo_t_o *csel;

  csel = pCmdSelInfo;
  Clear(gCommandFlag, 0, gCommandFlag->max_length, 0);
  if (TerminalType)
  {
    SetRootMenuText(&csel, gSmlTerminalMenuStr);
    if (trmChkJumpSmallToLearge(pData))
    {
        goto LABEL_28;
LABEL_15:
LABEL_28:
      gCommandFlag->m_Items[2] |= 2u;
      pCmdSelInfo->CursorInfo->CursorPos->InvisibleListNums = 1;
      CursorInfo = pCmdSelInfo->CursorInfo;
        goto LABEL_31;
LABEL_21:
      goto LABEL_31;
    }
    else
    {
      v20 = gCommandFlag;
      if (!LODWORD(v20->max_length))
        goto LABEL_26;
    }
    v20->m_Items[0] |= 1u;
      goto LABEL_28;
    goto LABEL_15;
  }
  trmSetNmlRootMenu(TerminalNo, pCmdSelInfo, pData);
  CursorInfo = pCmdSelInfo->CursorInfo;
    goto LABEL_21;
LABEL_31:
  v24 = gCommandFlag;
  cmpSetCursorFlag(CursorInfo, v24);
}

// 0xf7c150
void trmInitTransWindow(lstListWindow_t *pListWindow, s8 TerminalCount, sdfTexHandle_t *TexHandle) {
  s32 v7;
  s32 v8;
  cmpCursorInfo_t_o *CursorInfo;

  v7 = CMP_XM(0);
  v8 = CMP_YM(83);
  lstInitListWindow(v7, v8, 0xFFFFFu, 297, 211, 0x19191E59u, 1, pListWindow);
  fclSetPanelTex(pListWindow->Panel, 0, 0, 0, 0, TexHandle);
  CursorInfo = pListWindow->CursorInfo;
  cmpInitCursorInfo(CursorInfo, TerminalCount, 7u, 0);
  cmpInitCursorSize(pListWindow->CursorInfo, 46, 7, 152, 25, 29);
}

// 0xf7b590
void trmSetEventStat(s32 Val) {
  gEventStat = Val;
}

// 0xf7c290
void trmSetNmlRootMenu(u16 TerminalNo, cmpCmdSelInfo_t *pCmdSelInfo, fclDataTerminal_t *pData) {
  s32 EventNo;
  System_String_array **p_gNmlTerminalMenuStr2;
  System_String_array *v11;
  struct System_Byte_array *gCommandFlag;
  cmpCmdSelInfo_t_o *csel;

  csel = pCmdSelInfo;
  EventNo = trmGetEventNo(1, pData, pData);
  if (EventNo == 662)
  {
    p_gNmlTerminalMenuStr2 = &gNmlTerminalMenuStr2;
    if (TerminalNo >= 0x20u)
    {
LABEL_11:
      p_gNmlTerminalMenuStr2 = &gNmlTerminalMenuStr3;
    }
  }
  else
  {
    p_gNmlTerminalMenuStr2 = &gNmlTerminalMenuStr;
    if (TerminalNo >= 0x20u)
      goto LABEL_11;
  }
  v11 = *p_gNmlTerminalMenuStr2;
LABEL_23:
  _Clear(menu_msg);
  SetRootMenuText(&csel, v11);
  gCommandFlag->m_Items[2] |= 2u;
  pCmdSelInfo->CursorInfo->CursorPos->InvisibleListNums = 1;
}

// 0xf7be00
void trmSetProcessTerm(void) {
  dds3ProcessID_t_o *ScriptPID;

  if (gCallMode)
  {
    ScriptPID = GBWK->ScriptPID;
    fclScriptForcedEnd(ScriptPID);
    gEventStat = 6;
    gProcessStat = 2;
    gCallMode = 0;
  }
}

// 0xf78940
void trmStartBGM(s32 TerminalType, s32 TerminalNo, bool nocheck) {
  s32 EventNo;
  s32 Id;

  EventNo = trmGetEventNo(0, GBWK, nocheck);
  if (TerminalType || nocheck || TerminalNo > 9 || ((1 << TerminalNo) & 0x20A) == 0 || EventNo == 804)
  {
    Id = FindId(0, "TERM_BGM01");
    p2sdPlayBGM(Id);
  }
}

// 0xf78770
s8 trmStartEvent(void) {
  s32 gEventStat;
  s32 EventNo;

LABEL_7:
  if (gEventStat == 6 || gEventStat == 2)
    return 1;
  if (gEventStat)
    return 0;
  if (trmGetEventNo(1, GBWK) < 0)
    return 0;
LABEL_20:
  EventNo = trmGetEventNo(1, GBWK);
  evtStartEvent(EventNo);
  gEventStat = 2;
  return 1;
}
