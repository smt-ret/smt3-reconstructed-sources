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
    p2sdSndStopAll();
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
    return 0;
}

// 0xf7ee70
void trmStartSaveAct(s32 Mode) {
    trmEndEvent(0);
    slGetExitMode();
    evtLoadSound(0);
    evtCheckSoundLoad(0);
    evtStartPolygonMovie2(0, 0, 0);
}

// 0xf81c00
dds3ProcessFunc_t *trmUpdate(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    fclChkDbgProcess();
    trmChkEventWait();
    SetButtonGuide(0, 0);
    trmUpdateDebug();
    trmUpdateSeqRoot();
    trmUpdateSeqTrans();
    trmUpdateSave();
    dds3FadeCheck();
    trmSetProcessTerm();
    trmUpdateSeqConfirm();
    trmUpdateAct();
    trmUpdateSaveActIn();
    trmUpdateSaveActOut();
    IsLoad(0, 0);
    fclUpdateTerminalInit(0);
    return 0;
}

// 0xf816b0
void trmUpdateAct(void) {
  fclTerminalInit_c *v2;
  s32 v3;
  struct fclDataTerminal_t_o *GBWK;

  else  v3 = dds3FadeCheck();
  if (v3)
  {
    else if (GBWK->LastTerminalType)
    {
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
    case 3:
      movieStop();
      PMPID = GBWK->PMPID;
      evtResetPolygonMovieFlag(PMPID, 1u);
      v5 = GBWK;
      v6 = 4;
    case 5:
      moviePlay(3, -1);
      TerminalNo = GBWK->TerminalNo;
      if (TerminalNo == 32)
      if (TerminalNo == 33)
      {
        evtBitOn(964);
      }
      v5 = GBWK;
      v6 = 1;
    default:
      ActFlag = GBWK->ActFlag;
      if (ActFlag == 4)
      {
        p_PMPID = &GBWK->PMPID;
        v28 = dds3GetProcessStat(p_PMPID) == 3;
        v18 = v28;
        v31 = &GBWK->PMPID;
        if (!dds3GetProcessStat(v31))
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
        }
      }
      if ((v18 & 1) == 0)
        return;
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
        v5->ActFlag = v6;
      }
      return;
  }
}

// 0xf80f20
void trmUpdateActSmall(void) {
    dds3GetProcessStat(0);
    dds3KillProcess(0, 0);
    fclFreeStage();
    p2sdSndStopAll();
    evtResetPolygonMovieFlag(0, 0);
    evtStartPolygonMovie2(0, 0, 0);
    evtSetPolygonMovieFlag(0, 0);
    SetButtonGuide(0, 0);
    DDS3_PADCHECK_TRIG(0);
    evtCheckPolygonMovieRun(0);
    dds3FadeIn(0, 0, 0, 0);
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
  }
  else
  {
    v10 = 0;
    if (GBWK->TerminalType)
    {
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
    fclChkSignal(0);
    Log(0, 0);
    trmGetJumpTerminalNo();
    fclSetVal(0, 0);
    fclScriptStart(0, 0, 0);
    ResetEffect();
    dds3FadeOut(0, 0, 0, 0);
    fclScriptForcedEnd(0);
    SetButtonGuide(0, 0);
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
      SetButtonGuide(v26, 0);
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
    }
  }
  if (cmpChkPadPressUpDown())
  v35 = GBWK->TransWindow->CursorInfo;
  cmpMoveCursor(v35, 0);
  v37 = GBWK->TransWindow->CursorInfo;
  v38 = cmpDisablePadBitStop(v37, v5, 0x30u);
  cmpPlaySE(v38);
}
