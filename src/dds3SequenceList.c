#include "types.h"

typedef struct dds3AdminiList_t dds3AdminiList_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fldSceneParam_t fldSceneParam_t;

static s32 abcd;
static dds3AdminiList_t *dds3AdminiList[45];

void ButtonGuideDispDel(void);
s32 ChkPipe(void);
void EndPipe(void);
void FilterDelete(void);
void FinishMovieViewer(void);
void InitModelViewer(void);
void InitMovieViewer(void);
void InitPipe(s32 data, s32 prevData);
void KillModelViewer(void);
void LoadDefault(s32 language);
bool ViewerEndCheck(void);
void dds3AdminiExitSequence(void);
void dds3ConfigProcessEnd(void);
void dds3ConfigProcessStart(s32 Mode);
void dds3FadeClear(void);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void evtBitOn(s32 no);
bool evtChkEndProcess(void);
void evtExitEventTest(void);
void evtExitSky(void);
void evtInitEventTest(void);
dds3ProcessID_t *evtInitSky(void);
void evtStartEvent(s32 no);
s8 fclChkCombineProcess(void);
s8 fclChkRagProcess(void);
s32 fclChkRecoverProcess(void);
s8 fclChkShopProcess(void);
s8 fclChkTerminalProcess(void);
s32 fclCombineProcessEnd(void);
void fclCombineProcessStart(void);
s32 fclRagProcessEnd(void);
void fclRagProcessStart(s8 Place);
s32 fclRecoverProcessEnd(void);
void fclRecoverProcessStart(s8 Place);
s32 fclShopProcessEnd(void);
void fclShopProcessStart(void *pPlace);
s32 fclTerminalProcessEnd(void);
void fclTerminalProcessStart(s32 TerminalType, s32 TerminalNo);
void fldAllShutDown(void);
void fldMainLoadStart(void);
s32 fldProcNextJump(void);
s8 fldProcShutDown2(void);
void fldProcTrigSequence(fldSceneParam_t *srcParam, s32 mode);
void fmProcTrigSequence(s32 mode, bool callDebug);
s32 fmProcessChk(void);
void fmShutDown(void);
s8 fmShutDown2(void);
void fmShutDownFade(void);
dds3ProcessID_t *init_puzzleboy(u32 mode, s32 level);
s32 mselShutDown(void);
s32 mselStart(s32 mode);
void nbCallNewBattle(s32 encpack, s32 data);
void nbExitBattleTest(void);
void nbInitBattleTest(void);
s8 nmeChkNameProcess(void);
void nmeNameProcessEnd(void);
void nmeNameProcessStart(s8 TargetNo, s8 EntryMode, s8 DebugMode);
s8 rstChkResult2Process(void);
void rstResult2ProcessEnd(void);
void rstResult2ProcessStart(void);
void rstSetTestParam(void);
void sndPtnTestShutDown(void);
void sndPtnTestStart(s32 no);
s32 stfDebugStart(void);
s32 stfShutDown(void);
s32 stfStart(void);
s32 titleShutDown(void);
s32 titleStart(s32 mode);

// 0x14fb600
s32 CallBattleFieldTest(s32 flg, void *data) {
  return 1;
}

// 0x14fc6c0
s32 CallBillboardTest(s32 flg, void *data) {
  return 1;
}

// 0x14fa2a0
s32 CallBootMc(s32 flg, void *data) {
  return 1;
}

// 0x14fae90
s32 CallCamp(s32 flg, void *data) {
  cmpProcessStart();
  return 1;
}

// 0x14fb8b0
s32 CallCampTest(s32 flg, void *data) {
  evtBitOn(3080);
  cmpInitTestDevilData();
  cmpInitTestGBWKStockList();
  cmpProcessStart();
  return 1;
}

// 0x14fafe0
s32 CallCombine(s32 flg, void *data) {
  return 1;
}

// 0x14fba20
s32 CallCombineTest(s32 flg, void *data) {
  fclCombineProcessStart();
  return 1;
}

// 0x14fb260
s32 CallConfig(s32 flg, void *data) {
  dds3ConfigProcessStart(1);
  return 1;
}

// 0x14f9eb0
s32 CallDebug(s32 flg, void *data) {
  UnityEngine_GameObject_o *DebugObject;
  Il2CppObject *v9;
  u64 *v12;

  Log("dds3SequenceList:CallDebug()", 0);
  DebugObject = kernelObject->DebugObject;
  SetActive(DebugObject, 1, 0);
  LoadDefault(0);
  SetActive(kernelObject->DebugFPS, 1, 0);
  dds3FadeClear();
  v9 = AddComponent_object_(DebugObject);
  dispobj = v9;
  ButtonGuideDispDel();
  FilterDelete();
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_dds3StartMenu_dds3StartMenuProcess__);
  dds3StartProcess("StartSel", 0x2AF9u, 0, 0, v12, 0, 0, 0, 0, 0);
  return 1;
}

// 0x14fa8e0
s32 CallEndSave(s32 flg, void *data) {
  fmProcTrigSequence(2, 0);
  return 1;
}

// 0x14fac40
s32 CallEvent(s32 flg, void *data) {
  s32 evtNextEventNo;

  if (flg != 1)
  {
    if (flg)
      return 1;
    Write("start event!\n", 0);
    evtNextEventNo = *il2cp::SizeOf(data, s32);
    if (evtNextEventNo < 1)
      return 1;
LABEL_17:
    evtInitSky();
    evtStartEvent(evtNextEventNo);
    return 1;
  }
  Write("イベント復帰!!\n", 0);
  if (evtNextEventNo >= 1)
    goto LABEL_17;
  return 1;
}

// 0x14fb660
s32 CallEventTest(s32 flg, void *data) {
  abcd = 0;
  evtInitEventTest();
  evtInitSky();
  return 1;
}

// 0x14fb820
s32 CallEventViewer(s32 flg, void *data) {
  return 1;
}

// 0x14faa40
s32 CallField(s32 flg, void *data) {
  const void *v5;
  fldSceneParam_t_o v8;
  u8 src[136];
  s64 dest;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  s64 v24;
  s64 v25;
  s64 v26;

  v25 = 0;
  v26 = 0;
  dest = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  if (data)
  {
    v5 = il2cp::SizeOf(data, fldSceneParam_t);
    memcpy(&dest, v5, 0x88u);
  }
  else
  {
    v25 = 0;
    v26 = 0;
    dest = 0;
    v23 = 0;
    v24 = 0;
    v21 = 0;
    v22 = 0;
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v11 = 0;
    v12 = 0;
  }
  memcpy(src, &dest, sizeof(src));
  memcpy(&v8, src, sizeof(v8));
  fldProcTrigSequence(&v8, flg);
  return 1;
}

// 0x14fc6f0
s32 CallFontTest(s32 flg, void *data) {
  return 1;
}

// 0x14fb850
s32 CallInterfaceTest(s32 flg, void *data) {
  return 1;
}

// 0x14fb630
s32 CallKernelTest(s32 flg, void *data) {
  return 1;
}

// 0x14fa3f0
s32 CallLoad(s32 flg, void *data) {
  fmProcTrigSequence(1, 0);
  return 1;
}

// 0x14fa590
s32 CallLoad2(s32 flg, void *data) {
  return 1;
}

// 0x14fa620
s32 CallLoad3(s32 flg, void *data) {
  fmProcTrigSequence(5, 0);
  return 1;
}

// 0x14fc720
s32 CallMapEditor(s32 flg, void *data) {
  return 1;
}

// 0x14fb880
s32 CallMessageScriptTest(s32 flg, void *data) {
  return 1;
}

// 0x14fcd30
s32 CallModeSelect(s32 flg, void *data) {
  s32 v4;

  if (data)
  {
    v4 = *il2cp::SizeOf(data, s32);
  }
  else
  {
    v4 = 0;
  }
  mselStart(v4);
  return 1;
}

// 0x14fc540
s32 CallModelViewerTest(s32 flg, void *data) {
  dds3KernelDebugSign = 0;
  InitModelViewer();
  return 1;
}

// 0x14fc900
s32 CallMovieViewerTest(s32 flg, void *data) {
  InitMovieViewer();
  return 1;
}

// 0x14fc3e0
s32 CallNameTest(s32 flg, void *data) {
  nmeNameProcessStart(0, 0, 1);
  return 1;
}

// 0x14fac10
s32 CallNewBattle(s32 flg, void *data) {
  return 1;
}

// 0x14fb350
s32 CallNewBattleTest(s32 flg, void *data) {
  s32 *v7;

  if (flg)
  {
    dds3AdminiExitSequence();
    fldProcNextJump();
    return 1;
  }
  if (fldBattleData.encountpack == -1)
    goto LABEL_16;
LABEL_12:
  if (data)
  {
    v7 = il2cp::SizeOf(data, nbNewBattleSeqData_t);
    nbCallNewBattle(*v7, v7[1]);
    return 1;
  }
  return 0;
}

// 0x14fca50
s32 CallPipe(s32 flg, void *data) {
  Il2CppClass *v4;
  s64 *Interface;
  char *v7;
  s64 *v8;
  u32 v9;
  s32 v10;
  s32 v12;
  u64 v17[3];

  if (data)
  {
    Interface = QueryInterface(data, s32);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v4, v17);
      if ((v17[0] & 1) != 0)
        v7 = v17[2];
      else
        v7 = v17 + 1;
      v8 = sub_8C4940(v7);
    }
    v9 = *(Interface + 6);
    v10 = *(Interface + 8);
    v12 = *(Interface + 9);
    InitPipe(v10, v12);
    fldGb->fieldID = 999;
  }
  else
  {
    InitPipe(0, 0);
  }
  return 1;
}

// 0x14fc750
s32 CallPuzzleBoy(s32 flg, void *data) {
  Il2CppClass *v4;
  s64 *Interface;
  char *v7;
  s64 *v8;
  s32 v9;
  s32 v11;
  u64 v14[3];

  if (data)
  {
    Interface = QueryInterface(data, uint);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v4, v14);
      if ((v14[0] & 1) != 0)
        v7 = v14[2];
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
    v9 = *(Interface + 8);

    {
      v9 = -1;
    }
    v11 = v9;
  }
  else
  {
    v11 = -1;
  }
  init_puzzleboy(1u, v11);
  return 1;
}

// 0x14fb040
s32 CallRag(s32 flg, void *data) {
  return 1;
}

// 0x14fbcc0
s32 CallRagTest(s32 flg, void *data) {
  evtInitSky();
  fclRagProcessStart(0);
  return 1;
}

// 0x14fb070
s32 CallRecover(s32 flg, void *data) {
  return 1;
}

// 0x14fbe70
s32 CallRecoverTest(s32 flg, void *data) {
  fclRecoverProcessStart(0);
  return 1;
}

// 0x14fb0d0
s32 CallResult2(s32 flg, void *data) {
  rstResult2ProcessStart();
  return 1;
}

// 0x14fc290
s32 CallResult2Test(s32 flg, void *data) {
  rstSetTestParam();
  rstResult2ProcessStart();
  return 1;
}

// 0x14fb010
s32 CallShop(s32 flg, void *data) {
  return 1;
}

// 0x14fbb70
s32 CallShopTest(s32 flg, void *data) {
  fclShopProcessStart(data);
  return 1;
}

// 0x14fce80
s32 CallSndPtnTest(s32 flg, void *data) {
  sndPtnTestStart(0);
  return 1;
}

// 0x14fc690
s32 CallSoundTest(s32 flg, void *data) {
  return 1;
}

// 0x14fa7c0
s32 CallStaff(s32 flg, void *data) {
  if (data)
  {
    stfDebugStart();
    return 1;
  }
  else
  {
    stfStart();
    return 1;
  }
}

// 0x14fb0a0
s32 CallTerminal(s32 flg, void *data) {
  return 1;
}

// 0x14fbfc0
s32 CallTerminalTest(s32 flg, void *data) {
  Il2CppClass *v5;
  s64 *Interface;
  char *v8;
  s64 *v9;
  u32 v10;
  s32 v11;
  s32 v13;
  s32 v14;
  s32 v15;
  u64 v18[3];

  else
  {
    evtInitSky();
    if (data)
    {
LABEL_6:
      Interface = QueryInterface(data, s32);
      if (!Interface)
      {
        sub_8FC2C0(data->klass->_1.element_class, v5, v18);
        if ((v18[0] & 1) != 0)
          v8 = v18[2];
        else
          v8 = v18 + 1;
        v9 = sub_8C4940(v8);
      }
      v10 = *(Interface + 6);
      v11 = *(Interface + 8);
      v13 = *(Interface + 9);
      v14 = v11;
      v15 = v13;
      goto LABEL_24;
    }
  }
  v14 = 0;
  v15 = 1;
LABEL_24:
  fclTerminalProcessStart(v14, v15);
  return 1;
}

// 0x14fce50
s32 CallTgs(s32 flg, void *data) {
  return 1;
}

// 0x14fa2d0
s32 CallTitle(s32 flg, void *data) {
  s32 v4;

  if (data)
  {
    v4 = *il2cp::SizeOf(data, s32);
  }
  else
  {
    v4 = 0;
  }
  titleStart(v4);
  return 1;
}

// 0x14fb620
s32 CheckBattleFieldTest(void) {
  return 0;
}

// 0x14fc6e0
s32 CheckBillboardTest(void) {
  return 0;
}

// 0x14fa2c0
s32 CheckBootMc(void) {
  return 0;
}

// 0x14faf70
s32 CheckCamp(void) {
  return cmpChkCampProcess() == 0;
}

// 0x14fb9b0
s32 CheckCampTest(void) {
  return cmpChkCampProcess() == 0;
}

// 0x14fb000
s32 CheckCombine(void) {
  return 1;
}

// 0x14fbb00
s32 CheckCombineTest(void) {
  return fclChkCombineProcess() == 0;
}

// 0x14fb340
s32 CheckConfig(void) {
  return 0;
}

// 0x14fa290
s32 CheckDebug(void) {
  return 0;
}

// 0x14fa9d0
s32 CheckEndSave(void) {
  return fmProcessChk() == 0;
}

// 0x14fae80
s32 CheckEvent(void) {
  return 0;
}

// 0x14fb7b0
s32 CheckEventTest(void) {
  return evtChkEndProcess();
}

// 0x14fb840
s32 CheckEventViewer(void) {
  return 0;
}

// 0x14fac00
s32 CheckField(void) {
  return 0;
}

// 0x14fc710
s32 CheckFontTest(void) {
  return 0;
}

// 0x14fb870
s32 CheckInterfaceTest(void) {
  return 0;
}

// 0x14fb650
s32 CheckKernelTest(void) {
  return 0;
}

// 0x14fa520
s32 CheckLoad(void) {
  return fmProcessChk() == 0;
}

// 0x14fa610
s32 CheckLoad2(void) {
  return 1;
}

// 0x14fa750
s32 CheckLoad3(void) {
  return fmProcessChk() == 0;
}

// 0x14fc740
s32 CheckMapEditor(void) {
  return 0;
}

// 0x14fb8a0
s32 CheckMessageScriptTest(void) {
  return 0;
}

// 0x14fce40
s32 CheckModeSelect(void) {
  return 0;
}

// 0x14fc680
s32 CheckModelViewerTest(void) {
  return 0;
}

// 0x14fc9e0
s32 CheckMovieViewerTest(void) {
  return ViewerEndCheck();
}

// 0x14fc4d0
s32 CheckNameTest(void) {
  return nmeChkNameProcess() == 0;
}

// 0x14fac30
s32 CheckNewBattle(void) {
  return 0;
}

// 0x14fb500
s32 CheckNewBattleTest(void) {
  if (dds3SearchProcessName("battle test"))
    return 0;
  else if (dds3SearchProcessPriority(1018))
  {
    return 0;
  }
  fldProcNextJump();
  return 1;
}

// 0x14fccc0
s32 CheckPipe(void) {
  return ChkPipe() != 1;
}

// 0x14fc8f0
s32 CheckPuzzleBoy(void) {
  return 0;
}

// 0x14fb060
s32 CheckRag(void) {
  return 1;
}

// 0x14fbe00
s32 CheckRagTest(void) {
  return fclChkRagProcess() == 0;
}

// 0x14fb090
s32 CheckRecover(void) {
  return 1;
}

// 0x14fbf50
s32 CheckRecoverTest(void) {
  return fclChkRecoverProcess() == 0;
}

// 0x14fb1f0
s32 CheckResult2(void) {
  return rstChkResult2Process() == 0;
}

// 0x14fc370
s32 CheckResult2Test(void) {
  return rstChkResult2Process() == 0;
}

// 0x14fb030
s32 CheckShop(void) {
  return 1;
}

// 0x14fbc50
s32 CheckShopTest(void) {
  return fclChkShopProcess() == 0;
}

// 0x14fcf60
s32 CheckSndPtnTest(void) {
  return dds3SearchProcessName("SndPtnTest") == 0;
}

// 0x14fc6b0
s32 CheckSoundTest(void) {
  return 0;
}

// 0x14fa8d0
s32 CheckStaff(void) {
  return 0;
}

// 0x14fb0c0
s32 CheckTerminal(void) {
  return 1;
}

// 0x14fc220
s32 CheckTerminalTest(void) {
  return fclChkTerminalProcess() == 0;
}

// 0x14fce70
s32 CheckTgs(void) {
  return 0;
}

// 0x14fa3e0
s32 CheckTitle(void) {
  return 0;
}

// 0x14fb610
s32 ExitBattleFieldTest(void) {
  return 0;
}

// 0x14fc6d0
s32 ExitBillboardTest(void) {
  return 0;
}

// 0x14fa2b0
s32 ExitBootMc(void) {
  return -1;
}

// 0x14faf00
s32 ExitCamp(void) {
  cmpProcessEnd();
  return 0;
}

// 0x14fb940
s32 ExitCampTest(void) {
  cmpProcessEnd();
  return 0;
}

// 0x14faff0
s32 ExitCombine(void) {
  return 0;
}

// 0x14fba90
s32 ExitCombineTest(void) {
  if (fclCombineProcessEnd())
    return 0;
  else
    return -1;
}

// 0x14fb2d0
s32 ExitConfig(void) {
  dds3ConfigProcessEnd();
  return 0;
}

// 0x14fa100
s32 ExitDebug(void) {
  UnityEngine_Object_o *dispobj;
  UnityEngine_GameObject_o *v6;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Object_o *v10;

  Log("dds3SequenceList:ExitDebug()", 0);
  if (op_Inequality(dispobj, 0, 0))
  {
    v6 = Find("Main Canvas/DebugMenu", 0);
    gameObject = get_gameObject(v6);
    SetActive(gameObject, 0, 0);
    v10 = dispobj;
    Destroy_27360000(v10);
    dispobj = 0;
  }
  dds3KillProcessName("StartSel", 1);
  return 1;
}

// 0x14fa950
s32 ExitEndSave(void) {
  fmShutDownFade();
  fmShutDown();
  if (fmShutDown2())
    return 0;
  else
    return -1;
}

// 0x14fadb0
s32 ExitEvent(void) {
  Write("ExitEvent\n", 0);
  evtExitSky();
  if (fldProcNextJump())
    return 0;
  else
    return -1;
}

// 0x14fb720
s32 ExitEventTest(void) {
  evtExitEventTest();
  evtExitSky();
  return 1;
}

// 0x14fb830
s32 ExitEventViewer(void) {
  return 0;
}

// 0x14fab60
s32 ExitField(void) {
  fldAllShutDown();
  if (fldProcShutDown2() == 1)
    return 0;
  else
    return -1;
}

// 0x14fc700
s32 ExitFontTest(void) {
  return 0;
}

// 0x14fb860
s32 ExitInterfaceTest(void) {
  return 0;
}

// 0x14fb640
s32 ExitKernelTest(void) {
  return 0;
}

// 0x14fa460
s32 ExitLoad(void) {
  fmShutDownFade();
  fmShutDown();
  if (!fmShutDown2())
    return -1;
  fldMainLoadStart();
  return 0;
}

// 0x14fa5a0
s32 ExitLoad2(void) {
  fldMainLoadStart();
  return 0;
}

// 0x14fa690
s32 ExitLoad3(void) {
  fmShutDownFade();
  fmShutDown();
  if (!fmShutDown2())
    return -1;
  fldMainLoadStart();
  return 0;
}

// 0x14fc730
s32 ExitMapEditor(void) {
  return 0;
}

// 0x14fb890
s32 ExitMessageScriptTest(void) {
  return 0;
}

// 0x14fcdd0
s32 ExitModeSelect(void) {
  mselShutDown();
  return 0;
}

// 0x14fc5e0
s32 ExitModelViewerTest(void) {
  dds3KernelDebugSign = 1;
  KillModelViewer();
  return 0;
}

// 0x14fc970
s32 ExitMovieViewerTest(void) {
  FinishMovieViewer();
  return 1;
}

// 0x14fc460
s32 ExitNameTest(void) {
  nmeNameProcessEnd();
  return 0;
}

// 0x14fac20
s32 ExitNewBattle(void) {
  return 0;
}

// 0x14fb490
s32 ExitNewBattleTest(void) {
  nbExitBattleTest();
  return 0;
}

// 0x14fcc20
s32 ExitPipe(void) {
  EndPipe();
  if (fldProcNextJump())
    return 0;
  else
    return -1;
}

// 0x14fc8e0
s32 ExitPuzzleBoy(void) {
  return 0;
}

// 0x14fb050
s32 ExitRag(void) {
  return 0;
}

// 0x14fbd60
s32 ExitRagTest(void) {
  evtExitSky();
  if (fclRagProcessEnd())
    return 0;
  else
    return -1;
}

// 0x14fb080
s32 ExitRecover(void) {
  return 0;
}

// 0x14fbee0
s32 ExitRecoverTest(void) {
  if (fclRecoverProcessEnd())
    return 0;
  else
    return -1;
}

// 0x14fb140
s32 ExitResult2(void) {
  if (!fldProcNextJump())
    return -1;
LABEL_6:
  rstResult2ProcessEnd();
  return 0;
}

// 0x14fc300
s32 ExitResult2Test(void) {
  rstResult2ProcessEnd();
  return 0;
}

// 0x14fb020
s32 ExitShop(void) {
  return 0;
}

// 0x14fbbe0
s32 ExitShopTest(void) {
  if (fclShopProcessEnd())
    return 0;
  else
    return -1;
}

// 0x14fcef0
s32 ExitSndPtnTest(void) {
  sndPtnTestShutDown();
  return 0;
}

// 0x14fc6a0
s32 ExitSoundTest(void) {
  return 0;
}

// 0x14fa860
s32 ExitStaff(void) {
  stfShutDown();
  return 0;
}

// 0x14fb0b0
s32 ExitTerminal(void) {
  return 0;
}

// 0x14fc180
s32 ExitTerminalTest(void) {
  evtExitSky();
  if (fclTerminalProcessEnd())
    return 0;
  else
    return -1;
}

// 0x14fce60
s32 ExitTgs(void) {
  return 0;
}

// 0x14fa370
s32 ExitTitle(void) {
  titleShutDown();
  return 0;
}
