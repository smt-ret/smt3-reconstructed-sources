#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataTerminal_t fclDataTerminal_t;

bool CanStopVideo(void);
bool DDS3_PADCHECK_TRIG(s32 id);
s8 FclDebug(s8 Mode, void *pData);
bool IsLoad(AssetBundles *this, char *key);
void Log(char *fmt, void **parray);
void ResetEffect(void);
void SetButtonGuide(s32 mode, bool sw);
void WindowDispOff(bool sw);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void evtBitOn(s32 no);
s32 evtCheckPolygonMovieRun(dds3ProcessID_t *id);
s32 evtCheckSoundLoad(s32 eventno);
s32 evtLoadSound(s32 eventno);
void evtResetPolygonMovieFlag(dds3ProcessID_t *id, u32 flag);
void evtSetPolygonMovieFlag(dds3ProcessID_t *id, u32 flag);
dds3ProcessID_t *evtStartPolygonMovie2(s32 priority, s32 eventno, s32 cutno);
s8 fclChkDbgProcess(void);
s8 fclChkSignal(s8 Idx);
void fclFreeStage(void);
void fclInitTerminalCore(s32 TerminalType, s32 TerminalNo, fclDataTerminal_t *pData, bool flg);
void fclScriptForcedEnd(dds3ProcessID_t *PID);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s8 fclSetVal(s8 Idx, s32 Val);
void fclUpdateTerminalInit(fclDataTerminal_t *data);
void fldSetCharClr(void);
void fmProcTrigSequence(s32 mode, bool callDebug);
s32 fmProcessChk(void);
s32 movieCheckDrawStat(void);
s32 movieCheckEnd(void);
s32 moviePlay(s32 aNum, s32 Layer);
void movieStop(void);
void p2sdSndStopAll(void);
s32 slGetExitMode(void);
void slSetTmnlID(s32 type, s32 id);
s32 trmCheckSaveAct(void);
s8 trmChkEventWait(void);
s8 trmEndEvent(s32 BgmMode);
s32 trmGetJumpTerminalNo(void);
void trmSetProcessTerm(void);
s8 trmStartEvent(void);
void trmStartSaveAct(s32 Mode);
void trmUpdateAct(void);
void trmUpdateActLearge(void);
void trmUpdateActSmall(void);
s8 trmUpdateDebug(void);
void trmUpdateSave(void);
void trmUpdateSaveActIn(void);
void trmUpdateSaveActOut(void);
s8 trmUpdateSeqConfirm(void);
void trmUpdateSeqRoot(void);
void trmUpdateSeqTrans(void);

// 0xf822e0
void CheckSave(void) {
  ;
}

// 0xf822f0
void CheckTransportCount(void) {
  ;
}

// 0xf7f9b0
void trmActInitMisc(void) {
  else
  {
    p2sdSndStopAll();
  }
}

// 0xf7f280
s32 trmCheckSaveAct(void) {
  dds3ProcessID_t_o **p_PMPID;

  p_PMPID = &GBWK->PMPID;
  if (dds3GetProcessStat(p_PMPID) - 1 < 3)
    return 1;
  fclFreeStage();
  return 0;
}

// 0xf7f360
s32 trmGetJumpTerminalNo(void) {
  struct fclDataTerminal_t_o *GBWK;
  struct System_SByte_array *TerminalList;
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;

  else
  {
    if (GBWK->TerminalType)
      goto LABEL_6;
  }
  TerminalList = GBWK->TerminalList;
  CursorInfo = GBWK->TransWindow->CursorInfo;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  return TerminalList->m_Items[CursorIndex];
}

// 0xf7ee70
void trmStartSaveAct(s32 Mode) {
  u32 *v4;
  s16 v6;
  s32 v7;
  struct fclDataTerminal_t_o *GBWK;
  s32 TerminalNo;
  s32 v10;
  u32 v11;
  s32 TerminalType;
  u32 v14;
  s32 v16;
  s32 ExitMode;
  s32 v20;
  u32 v22;
  struct fclDataTerminal_t_o *v27;
  dds3ProcessID_t_o *started;

  v4 = NewSpecific(s32, 3u);
  if ((v6 & 0x200) != 0)
  {
    v7 = v6 & 0x200;
  }
  else
  {
    v7 = 0;
  }
  TerminalNo = GBWK->TerminalNo;
  v10 = TerminalNo & 0xFFFE;
  v11 = TerminalNo - 23;
  if (v10 == 18 || v11 <= 1)
  {
    else
    {
      TerminalType = GBWK->TerminalType;
      v14 = v4[6];
      if (v14)
        goto LABEL_15;
    }
  }
  v22 = v4[6];
  if (!GBWK->TerminalType)
    goto LABEL_61;
LABEL_32:
  v4[8] = 10;
  v4[9] = 20;
  v16 = 805;
  v4[10] = 30;
  if (!Mode)
    goto LABEL_37;
LABEL_22:
  ExitMode = slGetExitMode();
  if (!ExitMode)
  {
LABEL_56:
      goto LABEL_58;
LABEL_41:
LABEL_58:
    started = 0;
    v27 = GBWK;
    goto LABEL_59;
  }
LABEL_25:
  if (ExitMode == 1)
  {
    v20 = v4[9];
  }
  else
  {
    v20 = 0;
  }
  evtLoadSound(v16);
  while (!evtCheckSoundLoad(v16))
    ;
  v27 = GBWK;
  started = evtStartPolygonMovie2(1000, v16, v20);
LABEL_59:
  v27->PMPID = started;
}

// 0xf81c00
dds3ProcessFunc_t *trmUpdate(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s8 Current;
  fclTerminalInit_c *v12;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v18;
  struct fclDataTerminal_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  dds3ProcessID_t_o *v33[3];
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataTerminal_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataTerminal_t, v33);
    if ((v33[0] & 1) != 0)
      v8 = v33[2];
    else
      v8 = v33 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_15:
  GBWK = ProcessData;
  Current = GBWK->SeqInfo->Current;
  if (fclChkDbgProcess() != 1)
  {
    else if (GBWK->Initialized)
    {
      goto LABEL_22;
    }
    asset_bc = get_asset_bc();
    if (IsLoad(asset_bc, "e804"))
    {
      v18 = get_asset_bc();
      if (IsLoad(v18, "f804"))
      {
        fclUpdateTerminalInit(GBWK);
        GBWK->Initialized = 1;
        if ((v12->_2.bitflags2 & 2) == 0)
          goto LABEL_41;
        goto LABEL_23;
      }
    }
  }
  return 0;
}

// 0xf816b0
void trmUpdateAct(void) {
  fclTerminalInit_c *v2;
  s32 v3;
  struct fclDataTerminal_t_o *GBWK;

  else if ((GBWK->ActFlag & 0x80000000) == 0)
  {
    goto LABEL_15;
  }
  v3 = dds3FadeCheck();
  if (v3)
  {
LABEL_15:
    else if (GBWK->LastTerminalType)
    {
LABEL_18:
      trmUpdateActSmall(v2);
      return;
    }
    trmUpdateActLearge(v2);
    return;
  }
  inited = trmEndEvent(1);
  GBWK->TerminalNo = trmGetJumpTerminalNo();
  GBWK->LastTerminalType = GBWK->TerminalType;
  GBWK->TerminalType = 0;
  fclInitTerminalCore(GBWK->TerminalType, GBWK->TerminalNo, GBWK, 1);
  GBWK->ActFlag = 0;
}

// 0xf80880
void trmUpdateActLearge(void) {
  struct fclDataTerminal_t_o *GBWK;
  struct fclDataTerminal_t_o *v5;
  char v6;
  UnityEngine_Object_o *FildMapObj;
  s32 ActFlag;
  s32 v17;
  char v18;
  dds3ProcessID_t_o *PMPID;
  s32 TerminalNo;
  dds3ProcessID_t_o **p_PMPID;
  bool v28;
  dds3ProcessID_t_o **v31;
  s32 v33;

  switch (GBWK->ActFlag)
  {
    case 0:
      GBWK->PMPID = evtStartPolygonMovie2(1000, 804, 30);
      evtSetPolygonMovieFlag(GBWK->PMPID, 1u);
      WindowDispOff(0);
      v5 = GBWK;
      v6 = 5;
      goto LABEL_88;
    case 1:
      if (!movieCheckDrawStat())
        return;
      fldSetCharClr();
      if (op_Inequality(FildMapObj, 0, 0))
      {
        SetActive(FildMapObj, 0, 0);
      }
      dds3FadeIn(0, 0, 0, 0);
      v5 = GBWK;
      v6 = 2;
      goto LABEL_88;
    case 3:
      movieStop();
      PMPID = GBWK->PMPID;
      evtResetPolygonMovieFlag(PMPID, 1u);
      v5 = GBWK;
      v6 = 4;
      goto LABEL_88;
    case 5:
      moviePlay(3, -1);
      TerminalNo = GBWK->TerminalNo;
      if (TerminalNo == 32)
        goto LABEL_83;
      if (TerminalNo == 33)
      {
LABEL_83:
        evtBitOn(964);
      }
      v5 = GBWK;
      v6 = 1;
      goto LABEL_88;
    default:
      ActFlag = GBWK->ActFlag;
      if (ActFlag == 4)
      {
        p_PMPID = &GBWK->PMPID;
        v28 = dds3GetProcessStat(p_PMPID) == 3;
        v18 = v28;
        v31 = &GBWK->PMPID;
        if (!dds3GetProcessStat(v31))
          goto LABEL_107;
      }
      else
      {
        if (ActFlag != 2)
          return;
        v17 = movieCheckEnd();
        v18 = v17 != 0;
        if (CanStopVideo())
        {
          v18 = (v17 != 0) | DDS3_PADCHECK_TRIG(1);
          if (DDS3_PADCHECK_TRIG(3))
            goto LABEL_107;
        }
      }
      if ((v18 & 1) == 0)
        return;
LABEL_107:
      v5 = GBWK;
      v33 = v5->ActFlag;
      if (v33 == 4)
      {
        fclFreeStage();
        GBWK->SeqInfo->Current = 0;
        GBWK->SeqInfo->Change = 1;
        GBWK->EventEnd = 0;
        SetButtonGuide(0, 0);
      }
      else if (v33 == 2)
      {
        v6 = 3;
LABEL_88:
        v5->ActFlag = v6;
      }
      return;
  }
}

// 0xf80f20
void trmUpdateActSmall(void) {
  struct fclDataTerminal_t_o *GBWK;
  s32 ActFlag;
  struct fclDataTerminal_t_o *v5;
  dds3ProcessID_t_o **p_PMPID;
  dds3ProcessID_t_o **v10;
  dds3ProcessID_t_o *PMPID2;
  struct fclDataTerminal_t_o *v15;
  char v16;
  u32 ProcessStat;
  dds3ProcessID_t_o **v20;
  s32 v22;
  s32 v24;
  s32 v26;
  struct fclDataTerminal_t_o *v28;
  char v29;
  dds3ProcessID_t_o *PMPID;
  s32 v33;
  struct fclDataTerminal_t_o *v34;
  dds3ProcessID_t_o *v35;

  ActFlag = GBWK->ActFlag;
  if (ActFlag == 2)
  {
    if (dds3GetProcessStat(&GBWK->PMPID) == 1)
      goto LABEL_29;
    p_PMPID = &GBWK->PMPID;
    if (dds3GetProcessStat(p_PMPID) == 2)
    {
LABEL_29:
      v10 = &GBWK->PMPID;
      dds3KillProcess(v10, 0);
      fclFreeStage();
      p2sdSndStopAll();
    }
    PMPID2 = GBWK->PMPID2;
    evtResetPolygonMovieFlag(PMPID2, 1u);
    v15 = GBWK;
    v16 = 3;
    goto LABEL_49;
  }
  if (!GBWK->ActFlag)
  {
    GBWK->PMPID2 = evtStartPolygonMovie2(1000, 804, 30);
    v5 = GBWK;
    v5->PMPID = evtStartPolygonMovie2(1000, 805, 50);
    evtSetPolygonMovieFlag(GBWK->PMPID, 1u);
    evtSetPolygonMovieFlag(GBWK->PMPID2, 1u);
    GBWK->ActFlag = 1;
    return;
  }
  if (ActFlag == 3)
    goto LABEL_103;
LABEL_53:
  if (ActFlag == 1)
  {
    ProcessStat = dds3GetProcessStat(&GBWK->PMPID);
    v20 = &GBWK->PMPID;
    v22 = (ProcessStat == 3) | (dds3GetProcessStat(v20) == 0);
    v24 = v22 | DDS3_PADCHECK_TRIG(1);
    v26 = v24 | DDS3_PADCHECK_TRIG(3);
    v28 = GBWK;
    v29 = v26 | (v28->ActStartFlag == 2);
    if (v26 & 1 | (v28->ActStartFlag == 2))
    {
      v28->ActStartFlag = 2;
    }
    PMPID = GBWK->PMPID;
    if (evtCheckPolygonMovieRun(PMPID))
    {
      v33 = v29 & 1;
      v34 = GBWK;
      if (!v34->ActStartFlag)
      {
        v35 = v34->PMPID;
        evtResetPolygonMovieFlag(v35, 1u);
        dds3FadeIn(0, 0, 0, 0);
        GBWK->ActStartFlag = 1;
        if (!v33)
          return;
        goto LABEL_120;
      }
      goto LABEL_119;
    }
  }
}

// 0xf82220
s8 trmUpdateDebug(void) {
  Il2CppObject *GBWK;
  s8 v4;

  v4 = FclDebug(1, GBWK);
  return (v4 + 3) < 2 || ~v4 != 0;
}

// 0xf81830
void trmUpdateSave(void) {
  else if (fmProcessChk())
  {
    return;
  }
  trmStartSaveAct(1);
  GBWK->SeqInfo->Current = 8;
  GBWK->SeqInfo->Change = 1;
  SetButtonGuide(8, 0);
}

// 0xf81930
void trmUpdateSaveActIn(void) {
  dds3ProcessID_t_o *ScriptPID;
  struct fclDataTerminal_t_o *GBWK;
  s32 TerminalType;
  s32 TerminalNo;

  else if (dds3FadeCheck())
  {
    return;
  }
  fldSetCharClr();
  ScriptPID = GBWK->ScriptPID;
  fclScriptForcedEnd(ScriptPID);
  GBWK->ScriptPID = 0;
  trmEndEvent(0);
  TerminalType = GBWK->TerminalType;
  TerminalNo = GBWK->TerminalNo;
  slSetTmnlID(TerminalType, TerminalNo);
  fmProcTrigSequence(0, 0);
  GBWK->SeqInfo->Current = 2;
  GBWK->SeqInfo->Change = 1;
  SetButtonGuide(2, 0);
}

// 0xf81b00
void trmUpdateSaveActOut(void) {
  if ((byte_3F584EA & 1) != 0)
  {
    if (trmCheckSaveAct())
      return;
  }
  else
  {
    if (trmCheckSaveAct())
      return;
  }
  *(*(*(*(v3[2].klass->_1.gc_desc + 4) + 24LL) + 32LL) + 17LL) = 1;
  trmStartEvent();
  GBWK->SeqInfo->Current = 0;
  GBWK->SeqInfo->Change = 1;
  SetButtonGuide(0, 0);
  GBWK->EventEnd = 0;
}

// 0xf7fa20
s8 trmUpdateSeqConfirm(void) {
  dds3ProcessID_t_o **p_ScriptPID;
  s8 v5;
  s32 v7;
  s16 v9;
  s32 v10;
  struct fclDataTerminal_t_o *GBWK;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **v13;
  dds3ProcessID_t_o *ScriptPID;
  System_Byte_array *v24;
  dds3ProcessID_t_o **v25;

  p_ScriptPID = &GBWK->ScriptPID;
  if (dds3GetProcessStat(p_ScriptPID) == 2)
    return 0;
  v7 = fclChkSignal(2);
  if (v7 > 1)
    return 1;
  if (!v7)
  {
    p2sdSndStopAll();
    dds3FadeOut(0, 0, 0, 0x14u);
    GBWK->SeqInfo->Current = 6;
    GBWK->SeqInfo->Change = 1;
    SetButtonGuide(6, 0);
    ScriptPID = GBWK->ScriptPID;
    fclScriptForcedEnd(ScriptPID);
    GBWK->ScriptPID = 0;
    return 1;
  }
  if (v7 != 1)
    return 1;
  if ((v9 & 0x200) != 0)
  {
    v10 = v9 & 0x200;
    if (GBWK->TerminalType)
      goto LABEL_19;
  }
  else
  {
    v10 = 0;
    if (GBWK->TerminalType)
    {
LABEL_19:
      pScriptData = GBWK->pScriptData;
      v13 = &GBWK->ScriptPID;
      *v13 = fclScriptStart(pScriptData, 1, v13);
      GBWK->SeqInfo->Current = 0;
      GBWK->SeqInfo->Change = 2;
      SetButtonGuide(0, 0);
      return 1;
    }
  }
  v24 = GBWK->pScriptData;
  v25 = &GBWK->ScriptPID;
  *v25 = fclScriptStart(v24, 2, v25);
  GBWK->SeqInfo->Current = 1;
  GBWK->SeqInfo->Change = 2;
  v5 = 1;
  SetButtonGuide(1, 0);
  return v5;
}

// 0xf7fe00
void trmUpdateSeqRoot(void) {
  u16 v4;
  cmpCursorInfo_t_o *v9;
  u64 *v10;
  System_String_o *v11;
  System_Object_array *v13;
  cmpCursorInfo_t_o *v16;
  cmpCursorInfo_t_o *v18;
  s8 v19;
  fclTerminalInit_c *v20;
  struct fclDataTerminal_t_o *GBWK;
  s32 JumpTerminalNo;
  struct fclDataTerminal_t_o *v26;
  s32 v29;
  cmpCursorInfo_t_o *CursorInfo;
  s32 TerminalNo;
  dds3ProcessID_t_o *ScriptPID;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  s32 CursorIndex;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  if (fclChkSignal(0))
  {
    if (v4 > 2u)
    {
      if (v4 == 16)
      {
        CursorInfo = GBWK->CmdSelInfo->CursorInfo;
        cmpMoveCursor(CursorInfo, 255);
      }
      else if (v4 == 32)
      {
        v9 = GBWK->CmdSelInfo->CursorInfo;
        cmpMoveCursor(v9, 1);
        CursorIndex = cmpGetCursorIndex(GBWK->CmdSelInfo->CursorInfo);
        v10 = sub_8D3950(s32, &CursorIndex);
        v11 = Concat("PAD_D : ", v10);
        v13 = Empty_string_();
        Log(v11, v13, 0);
          goto LABEL_138;
        goto LABEL_78;
      }
    }
    else
    {
      if (v4 == 1)
      {
        v16 = GBWK->CmdSelInfo->CursorInfo;
        if (cmpChkCursorIndexStat(v16))
        {
          v18 = GBWK->CmdSelInfo->CursorInfo;
          v19 = cmpGetCursorIndex(v18) + 1;
          switch (v19)
          {
            case 1:
              GBWK->TransWindow->Panel->Timer2 = 0;
              if (GBWK->TerminalType)
              {
                JumpTerminalNo = trmGetJumpTerminalNo(v20);
                fclSetVal(0, JumpTerminalNo);
                v26 = GBWK;
                v26->ScriptPID = fclScriptStart(v26->pScriptData, 3, &v26->ScriptPID);
                GBWK->SeqInfo->Current = 5;
                GBWK->SeqInfo->Change = 1;
                v29 = 5;
              }
              else
              {
                pScriptData = GBWK->pScriptData;
                p_ScriptPID = &GBWK->ScriptPID;
                *p_ScriptPID = fclScriptStart(pScriptData, 2, p_ScriptPID);
                GBWK->SeqInfo->Current = v19;
                GBWK->SeqInfo->Change = 1;
                ResetEffect();
                v29 = 1;
              }
              goto LABEL_137;
            case 2:
              dds3FadeOut(0, 0, 0, 0xAu);
              GBWK->SeqInfo->Current = 7;
              GBWK->SeqInfo->Change = 1;
              v29 = 7;
              goto LABEL_137;
            case 3:
              TerminalNo = GBWK->TerminalNo;
              if (TerminalNo == 32)
                goto LABEL_117;
              if (TerminalNo == 33)
                goto LABEL_117;
              gEventStat = 4;
              ScriptPID = GBWK->ScriptPID;
              fclScriptForcedEnd(ScriptPID);
              GBWK->ScriptPID = 0;
              GBWK->SeqInfo->Current = 3;
              GBWK->SeqInfo->Change = 1;
              v29 = 3;
              goto LABEL_137;
            case 4:
LABEL_117:
              if (!gCallMode)
              {
                dds3FadeOut(0, 0, 0, 0x14u);
              }
                goto LABEL_132;
              goto LABEL_133;
            default:
              goto LABEL_77;
          }
        }
        v4 = 0x8000;
          goto LABEL_138;
        goto LABEL_78;
      }
      if (v4 == 2)
      {
        if (!gCallMode)
        {
          dds3FadeOut(0, 0, 0, 0x14u);
        }
LABEL_133:
        GBWK->SeqInfo->Current = 4;
        v29 = 4;
LABEL_137:
        SetButtonGuide(v29, 0);
          goto LABEL_138;
        goto LABEL_78;
      }
    }
LABEL_77:
      goto LABEL_138;
LABEL_78:
LABEL_138:
    if (!cmpChkPadPressUpDown())
      goto LABEL_139;
    goto LABEL_146;
  }
}

// 0xf7f4e0
void trmUpdateSeqTrans(void) {
  u32 v5;
  cmpCursorInfo_t_o *v7;
  struct fclDataTerminal_t_o *v9;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  System_Byte_array *v12;
  s32 v13;
  cmpCursorInfo_t_o *v15;
  cmpCursorInfo_t_o *v16;
  s8 v17;
  s32 JumpTerminalNo;
  struct fclDataTerminal_t_o *GBWK;
  s32 v26;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *v31;
  cmpCursorInfo_t_o *v35;
  cmpCursorInfo_t_o *v37;
  u16 v38;

  v3 = cmpChkCommonInput(CMP_PE_NORMAL);
  v5 = v3;
  if (v3 > 2u)
  {
    if (v3 == 16)
    {
      CursorInfo = GBWK->TransWindow->CursorInfo;
      v16 = CursorInfo;
      v17 = -1;
    }
    else
    {
      if (v3 != 32)
        goto LABEL_50;
      v15 = GBWK->TransWindow->CursorInfo;
      v16 = v15;
      v17 = 1;
    }
    cmpMoveCursor(v16, v17);
  }
  else
  {
    if (v3 == 1)
    {
      JumpTerminalNo = trmGetJumpTerminalNo();
      fclSetVal(0, JumpTerminalNo);
      GBWK->ScriptPID = fclScriptStart(GBWK->pScriptData, 3, &GBWK->ScriptPID);
      GBWK->SeqInfo->Current = 5;
      GBWK->SeqInfo->Change = 1;
      v26 = 5;
LABEL_68:
      SetButtonGuide(v26, 0);
        goto LABEL_69;
      goto LABEL_51;
    }
    if (v3 == 2)
    {
      v7 = GBWK->TransWindow->CursorInfo;
      cmpResetCursorInfo(v7);
      v9 = GBWK;
      if (v9->TerminalType)
      {
        pScriptData = v9->pScriptData;
        p_ScriptPID = &v9->ScriptPID;
        v12 = pScriptData;
        v13 = 1;
      }
      else
      {
        v31 = v9->pScriptData;
        p_ScriptPID = &v9->ScriptPID;
        v12 = v31;
        v13 = 0;
      }
      *p_ScriptPID = fclScriptStart(v12, v13, p_ScriptPID);
      GBWK->SeqInfo->Current = 0;
      GBWK->SeqInfo->Change = 2;
      v26 = 0;
      goto LABEL_68;
    }
  }
LABEL_50:
    goto LABEL_69;
LABEL_51:
LABEL_69:
  if (cmpChkPadPressUpDown())
    goto LABEL_77;
LABEL_70:
  v35 = GBWK->TransWindow->CursorInfo;
  cmpMoveCursor(v35, 0);
LABEL_77:
  v37 = GBWK->TransWindow->CursorInfo;
  v38 = cmpDisablePadBitStop(v37, v5, 0x30u);
  cmpPlaySE(v38);
}
