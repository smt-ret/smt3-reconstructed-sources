#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effDistortionBlurHandle_t effDistortionBlurHandle_t;
typedef struct fldEncountContol_t fldEncountContol_t;
typedef struct fldSceneParam_t fldSceneParam_t;
typedef struct fldSequenceControl_t fldSequenceControl_t;
typedef struct fldUnitControl_t fldUnitControl_t;
typedef struct nbNewBattleSeqData_t nbNewBattleSeqData_t;
typedef struct scrProcessWork_s scrProcessWork_s;

static s32 fldBgmTokusyu;
static fldEncountContol_t *fldEncountControl;
static fldSequenceControl_t *fldSequenceControl;
static u32 fldProcessFlag;
static nbNewBattleSeqData_t fldBattleData;
static s32 gEncountRireki;
static s32 gFldTakaraAkumaId;
static s32 gEncountBlurCnt;
static effDistortionBlurHandle_t *fldBlurKabuki;
static s32 gFldRndEncBtl;
static s32 takarasagasi_oldmoon;
static s32 fldProcCampWait;
static s32 fldProcAmWait;
static s32 gFldStart;
static s32 fldInitCnt;
static void *m_akey1;
static void *m_akey2;
static void *m_head;
static dds3Effect_Blur_t *fldAmaraBlurBuff;
static s32 fldProcShutDownFlg;
static s32 fldNext_fld;
static s32 fldNext_eveno;

void CallBattleSub(s32 encno, s32 eventno);
bool CheckTypeClose(void);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void FldDataLoadRequest(void);
void FldDispOn(dds3DefaultMain *this);
void InitOoyTest(void);
bool IsDLCField(s32 area);
bool IsFldDataLoaded(void);
bool IsLoad(AssetBundles *this, char *key);
bool IsStartModelLoaded(void);
void Load(char *key, char *filePath);
void LoadAssetExt(char *key, char *name, char *dlc);
void LoadEventModel(void);
void MakeWarpIndex_21490048(fldSceneParam_t *param);
void *ProcAmCheck(void);
void *ProcCampCheck(void);
void *ProcRandomEncountCheck(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetBoostFrameRate(dds3DefaultMain *this);
void SetEnemyUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, s32 type, bool bad, bool direction, f32 cameraDir, f32 playerDir);
void SetNormalFrameRate(dds3DefaultMain *this);
void SetRadarUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, s32 type);
void SetShadowMode(dds3DefaultMain *this, s32 mode);
void Unlock_16599376(char *id);
s32 datCheckSkillTakaraSagasi(void);
void datFieldSkillKaifuku(void);
void datPartyDamageFld(s32 mode);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
s32 dds3AdminiGetNextSequence(void);
s32 dds3AdminiGetPrevHistoryFlag(void);
s32 dds3CheckPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID);
effDistortionBlurHandle_t *dds3EffectDistortionBlurCreate(dds3Effect_DistortionBlurParam_t *pParam);
void dds3EffectDistortionBlurDelete(effDistortionBlurHandle_t **hDistortionBlur);
void dds3EffectDistortionBlurDraw(effDistortionBlurHandle_t **hDistortionBlur, bool bPS2mode, s32 SkillID);
void dds3EffectDistortionBlur_SetFldEvent(s32 feve_UnityEx_id);
void dds3EffectFilter(dds3Effect_Filter_t *pFilter);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeIn2(u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut2(u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
dds3ProcessID_t *dds3SceneBasicStartScript(dds3Basic_t **scene, char *procname);
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority);
void dds3SetActiveScene(dds3Basic_t *scene);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible);
s32 encChk(void);
void encStart(bool bRandomEncount);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void evtDisableMoonDraw(void);
void evtEnableMoonCalc(void);
void evtEnableMoonDraw(void);
s32 evtGetAgeOfMoon16(void);
void evtKillFieldScript(void);
void evtMoonAddMove(f32 leng);
s32 fldAutoMapChkMode(void);
void fldAutoMapDraw(void);
void fldAutoMapProc(void);
void fldAutoMapSeqStart(void);
void fldBgmBitChk(void);
void fldBgmContinue(void);
void fldBgmLoad(void);
void fldBgmPlay(void);
void fldBgmPlay2(void);
s32 fldBgmSisetuLoadChk(void);
void *fldCamMain(void);
void fldCamResetNpc(void);
bool fldCheckNextFile(s32 field);
s32 fldChkVortex(void);
s32 fldCmnBgmSeLoadChk(void);
void fldCmnBgmSeUnload(void);
void fldDLCEncountCheck(s32 *encpid);
bool fldDispOn(void);
void fldDoor_EveBtlExit(s32 field, s32 eveno);
bool fldDoor_SiseExit(void);
void fldDoor_Terminal(s32 type, s32 idx);
void fldElvFloorTask(void);
s32 fldEveHitProcess_Chk(void);
void fldEveHit_ChkEveHit(dds3Basic_t *pObjectBasic);
s32 fldEveHit_ChkEveHitAfter(void);
void fldEveHit_End(void);
void fldEve_BloomDof_AfterEnd(void);
void fldEve_BloomDof_Set(void);
s32 fldEventDataLoadChk(void);
void fldEventDataUnload(void);
void fldEventUpdateEx_Unity_2(void);
s32 fldFootSeLoadChk(void);
void fldFootSeUnload(void);
void fldFreeAddressProcess(void);
void fldFreeInputPanel(void);
void fldFreeNextFile(void);
void fldGbInit_Field(void);
s32 fldGetRestoreMode(void);
fldUnitControl_t *fldGetUnitControl(void);
void fldHitWM_Mask(void);
void fldInitAddressProcess(void);
void fldInitInputPanel(void);
void fldItemBoxCalcTask(void);
void fldLightMaTask(void);
void fldLoadNextFile_SetId_BtlRet(s32 field, s32 area);
s32 fldLoadNextGetStatus(void);
s32 fldLoadNextTask(void);
void fldNpcCalc(void);
void fldNpcDraw(void);
void fldPPSV2_Set(s32 fld, s32 area);
void fldPanelSet(s32 mode);
s32 fldPlayerCalc(void);
s32 fldPlayerChkAna(void);
void fldPlayerEventStop(bool sw);
void fldPlayerMotReset(void);
void fldPlayerPosRot(void);
void fldPlayer_Correction_Unity(void);
void fldPlayer_Enc_Correction_Unity(void);
s32 fldProcCampChk(void);
s32 fldProcNextJump(void);
s32 fldProcStartScript(void);
void fldReadyScene(void);
void fldRegistUnitPad(void);
void fldReleaseUnitPad(void);
s32 fldRunEncountChk(void);
void fldRunView(void);
void fldSe_Task(void);
void fldSkyCalcFilter(void);
void fldSkyCalcTable(void);
void fldSkyRefreshTbl(void);
void fldSkySetTableAnime(s32 type);
void fldSkySetTbl(s32 idx, s32 hokan);
void fldSnowFree(void);
void fldSnowInit(void);
void fldSnowSeedInit(void);
void fldSnowSeedReset(void);
void fldSnowTask(void);
void fldStatusSet(void);
void fldTitleMiniStart2(void);
void fldWaveTask(void);
s32 fmProcessChk(void);
s32 nbEncountCalc(s32 id, f32 length);
void nbNoDestroy_MoveCache_Field_F_ModeOn(void);
void nbResetEncountCount(void);
void p2sdBGMStopAll(void);
void p2sdPause(s32 MidiNo);
s32 p2sdPlaySE(s32 a);
void scrAllReleaseScript(void);
scrProcessWork_s *scrSearchScriptName(char *scriptname);
s32 sdfDelayedResrcCheck(void);

// 0x15f5ec0
void *ProcAmCheck(void) {
  s32 AutomapRapid;
  _BOOL4 v10;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  struct fldGlobalWork_t_o *v21;
  struct fldGlobalWork_t_o *v22;
  struct fldGlobalWork_t_o *v23;
  fldProcess_c *v24;
  s16 v25;
  s32 v26;
  struct fldProcess_StaticFields **p_static_fields;
  struct fldProcess_StaticFields *static_fields;
  s32 fldProcAmWait;
  fldGlobal_c *v37;
  struct fldGlobal_StaticFields **v38;
  struct fldGlobal_StaticFields *v39;
  dds3Basic_t_o *scene;

  scene = 0;
  if (fldGb->fieldID >= 10)
  {
    else if (fldProcCampChk(fldProcess))
    {
      return 0;
    }
    if (fldProcAmWait > 0)
    if (fldAutoMapChkMode())
    if ((fldProcessFlag & 0x40) != 0)
    {
      AutomapRapid = fldDbg->AutomapRapid;
      if ((AutomapRapid & (fldProcessFlag >> 6) & 1) != 0)
      {
        v10 = DDS3_PADCHECK_PRESS(2);
      }
      else
      {
        v10 = DDS3_PADCHECK_TRIG(2);
      }
      fieldID = fldGb->fieldID;
      if (fieldID == 38)
      if (fieldID == 44)
      {
        areaID = fldGb->areaID;
        if (areaID >= 11)
        {
          if (areaID < 27)
        }
      }
      v21 = fldGb;
      if (v21->fieldID == 44)
      {
        if (v21->areaID == 30)
      }
      v22 = fldGb;
      if (v22->fieldID == 45)
      {
        if (v22->areaID == 29)
      }
      v23 = fldGb;
      if (v23->fieldID != 45)
      if (v23->areaID == 30)
      {
        if (!fldGb->NoInpAmCnt)
        {
          if ((fldProcessFlag & 0x40) != 0 && v10)
          {
            fldGb->NoInpAmCnt = 4;
            fldGb->NoInpPlCnt = 5;
            fldReleaseUnitPad();
            scene = dds3GetActiveScene();
            fldPlayerEventStop(0);
            dds3SceneBasicStartScript(&scene, StringLiteral_16725);
          }
        }
      }
      else
      {
        if ((v25 & 0x200) != 0)
        {
          v26 = v25 & 0x200;
        }
        else
        {
          v26 = 0;
        }
        p_static_fields = &v24->static_fields;
        static_fields = v24->static_fields;
        fldProcAmWait = static_fields->fldProcAmWait;
        if (fldProcAmWait < 1)
        {
          if (fldProcAmWait <= 0)
          {
            if (!fldAutoMapChkMode())
            {
              if (!fldGb->NoInpAmCnt)
              {
                if (!fldPlayerChkAna())
                {
                  if (v10)
                  {
                    v38 = &v37->static_fields;
                    v39 = v37->static_fields;
                    if (!v39->fldDbg->EncountBtnOn)
                    {
                      v39->fldGb->NoInpAmCnt = 4;
                      (*v38)->fldGb->NoInpPlCnt = 8;
                      fldReleaseUnitPad();
                      fldPlayerPosRot();
                      {
                      }
                      dds3FadeOut(0, 0, 0, 4u);
                      fldProcAmWait = 5;
                      fldPlayerMotReset();
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          static_fields->fldProcAmWait = fldProcAmWait - 1;
          if (!(*p_static_fields)->fldProcAmWait)
          {
            scene = dds3GetActiveScene();
            dds3VisibleSceneBasic(&scene, 0);
            dds3FadeIn2(4u);
            fldAutoMapSeqStart();
          }
        }
      }
    }
  }
  return 0;
}

// 0x15f4b50
void *ProcCampCheck(void) {
  fldProcess_c *v3;
  s16 v4;
  s32 v5;
  struct fldProcess_StaticFields **p_static_fields;
  struct fldProcess_StaticFields *static_fields;
  s32 fldProcCampWait;
  u64 v12;
  s32 v13;
  char v27;
  dds3Basic_t_o *basic;

  basic = 0;
  if (fldChkVortex())
  {
    if ((v4 & 0x200) != 0)
    {
      v5 = v4 & 0x200;
    }
    else
    {
      v5 = 0;
    }
    p_static_fields = &v3->static_fields;
    static_fields = v3->static_fields;
    fldProcCampWait = static_fields->fldProcCampWait;
    if (fldProcCampWait >= 1)
    {
      static_fields->fldProcCampWait = fldProcCampWait - 1;
      if (!(*p_static_fields)->fldProcCampWait)
      {
        basic = dds3GetActiveScene();
        dds3VisibleSceneBasic(&basic, 0);
        dds3FadeIn2(4u);
        cmpProcessStart();
      }
      return 0;
    }
    else if ((fldProcessFlag & 0x20) == 0)
    {
      if ((*(v12 + 295) & 2) != 0 && !*(v12 + 216))
      v13 = fldProcCampChk(v12);
      if (v13 == 3)
      {
        fldSequenceControl->flag &= ~1u;
        fldRegistUnitPad();
        evtEnableMoonDraw();
        fldSkyRefreshTbl();
        fldStatusSet();
        basic = dds3GetActiveScene();
        dds3VisibleSceneBasic(&basic, 1);
        fldProcessFlag |= 0x20u;
        fldProcessFlag &= ~0x80u;
        if (cmpGetExitState() == 1)
        {
          dds3FadeOut2(0);
          fldEveHit_End();
          else
          {
            v27 = 1;
          }
          fldSequenceControl->flag |= 1u;
          fldSequenceControl->flag |= 2u;
          fldReleaseUnitPad();
          evtKillFieldScript();
          p2sdBGMStopAll();
          dds3AdminiCallSequence(4, 0, 0, 0);
        }
        else
        {
          dds3FadeOut2(0);
          dds3FadeIn2(8u);
        }
        return 0;
      }
    }
    if ((*(v12 + 295) & 2) != 0 && !*(v12 + 216))
    if ((fldProcessFlag & 0x20) != 0)
    {
      if ((fldProcessFlag & 0x40) != 0)
      {
        if ((fldSequenceControl->flag & 1) == 0)
        {
          if (!fldPlayerChkAna())
          {
            if (!fldAutoMapChkMode())
            {
              if (!fldGb->NoInpAmCnt)
              {
                if (DDS3_PADCHECK_TRIG(0))
                {
                  p2sdPlaySE(14);
                  fldSequenceControl->flag |= 1u;
                  fldReleaseUnitPad();
                  fldPlayerPosRot();
                  evtDisableMoonDraw();
                  fldGb->NoInpAmCnt = 4;
                  fldGb->NoInpPlCnt = 8;
                  fldProcessFlag &= ~0x20u;
                  fldProcessFlag |= 0x80u;
                  dds3FadeOut(0, 0, 0, 4u);
                  fldProcCampWait = 5;
                  fldPlayerMotReset();
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

// 0x15fefd0
dds3ProcessFunc_t *ProcDraw(dds3ProcessID_t *id) {
    dds3AdminiGetNextSequence();
    fldPlayer_Enc_Correction_Unity();
    fldLoadNextGetStatus();
    encChk();
    fmProcessChk();
    fldProcCampChk();
    fldAutoMapChkMode();
    fldNpcDraw();
    fldWaveTask();
    fldAutoMapDraw();
    fldSnowTask();
    fldElvFloorTask();
    fldPlayer_Correction_Unity();
    fldEve_BloomDof_AfterEnd();
    fldEventUpdateEx_Unity_2();
    fldEve_BloomDof_Set();
    dds3EffectBlur(0, 0, 0);
    dds3EffectFilter(0);
    dds3EffectDistortionBlurDraw(0, 0, 0);
    dds3EffectDistortionBlur_SetFldEvent(0);
    return 0;
}

// 0x15f2cb0
void *ProcRandomEncountCheck(void) {
    dds3GetActiveScene();
    dds3GetActiveUnitSceneBasic(0);
    dds3GetPosPoseSet(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    evtGetAgeOfMoon16();
    evtMoonAddMove(0);
    fldReleaseUnitPad();
    fldPlayerEventStop(0);
    dds3SceneBasicStartScript(0, 0);
    fldPlayerPosRot();
    datPartyDamageFld(0);
    datFieldSkillKaifuku();
    fldLoadNextGetStatus();
    fldEveHitProcess_Chk();
    datCheckSkillTakaraSagasi();
    fldRunEncountChk();
    fldDLCEncountCheck(0);
    nbEncountCalc(0, 0);
    nbResetEncountCount();
    dds3FadeIn(0, 0, 0, 0);
    fldEveHit_End();
    evtKillFieldScript();
    CallBattleSub(0, 0);
    return 0;
}

// 0x15f6890
dds3ProcessFunc_t *ProcSequence(dds3ProcessID_t *id) {
    dds3AdminiGetNextSequence();
    fmProcessChk();
    fldLoadNextTask();
    fldLoadNextGetStatus();
    fldBgmSisetuLoadChk();
    fldProcCampChk();
    ProcCampCheck();
    fldPlayerPosRot();
    SetBoostFrameRate(0);
    SetShadowMode(0, 0);
    FldDataLoadRequest();
    IsFldDataLoaded();
    fldDispOn();
    fldGbInit_Field();
    evtEnableMoonCalc();
    fldReadyScene();
    dds3GetControlScene();
    dds3SetActiveScene(0);
    fldInitInputPanel();
    evtEnableMoonDraw();
    fldInitAddressProcess();
    fldSkySetTbl(0, 0);
    fldSkySetTableAnime(0);
    dds3EffectDistortionBlurCreate(0);
    dds3FadeOut2(0);
    fldCamResetNpc();
    fldSnowSeedInit();
    fldSnowSeedReset();
    fldStatusSet();
    fldPPSV2_Set(0, 0);
    LoadEventModel();
    fldEventDataLoadChk();
    fldFootSeLoadChk();
    fldCmnBgmSeLoadChk();
    IsStartModelLoaded();
    fldProcStartScript();
    fldCamMain();
    fldBgmLoad();
    fldGetRestoreMode();
    fldBgmContinue();
    fldBgmPlay2();
    fldBgmPlay();
    SetNormalFrameRate(0);
    fldSnowInit();
    dds3FadeCheck();
    dds3FadeIn2(0);
    dds3SearchProcessPriority(0);
    fldRegistUnitPad();
    fldGetUnitControl();
    dds3ObjectBaseOffFlag(0, 0);
    fldTitleMiniStart2();
    fldRunView();
    fldEveHit_ChkEveHitAfter();
    fldEveHit_ChkEveHit(0);
    evtBitCheck(0);
    DDS3_PADCHECK_TRIG(0);
    evtBitOff(0);
    evtBitOn(0);
    ProcAmCheck();
    fldPanelSet(0);
    ProcRandomEncountCheck();
    encStart(0);
    fldPlayerCalc();
    fldLightMaTask();
    fldSkyCalcTable();
    fldSkyCalcFilter();
    fldHitWM_Mask();
    fldSe_Task();
    fldBgmBitChk();
    fldAutoMapProc();
    fldAutoMapChkMode();
    scrSearchScriptName(0);
    fldNpcCalc();
    fldItemBoxCalcTask();
    CheckTypeClose();
    Unlock_16599376(0);
    dds3GetActiveScene();
    dds3VisibleSceneBasic(0, 0);
    p2sdPause(0);
    p2sdPlaySE(0);
    fldEventDataUnload();
    fldFootSeUnload();
    fldCmnBgmSeUnload();
    fldFreeNextFile();
    fldLoadNextFile_SetId_BtlRet(0, 0);
    nbNoDestroy_MoveCache_Field_F_ModeOn();
    dds3AdminiCallSequence(0, 0, 0, 0);
    return 0;
}

// 0x15f6820
void RetryMapLoad(void) {
  fldSequenceControl->phase = 0;
}

// 0x15fef60
void SoftReset(void) {
  fldInitCnt = 0;
}

// 0x15f4610
void fldDLCEncountCheck(s32 *encpid) {
  s32 fieldID;
  fldUnitControl_t_o *UnitControl;
  struct dds3Basic_t_o *handle;
  fldUnitControl_t_o *v8;
  dds3PoseSet_t_o **p_poseset;
  s32 v10;
  f32 *poseset;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  struct fldGlobalWork_t_o *fldGb;
  s32 v21;
  s32 v22;
  u32 areaID;
  UnityEngine_Vector3_o v24;
  UnityEngine_Vector4_o v25;

  fieldID = fldGb->fieldID;
  if (fieldID != 60)
  {
    if (fieldID != 61)
      return;
  }
  UnitControl = fldGetUnitControl();
  if (!UnitControl)
    return;
  handle = UnitControl->handle;
  v8 = UnitControl;
  if (!handle)
    return;
  p_poseset = &handle->poseset;
  v10 = dds3CheckPoseSetFlag(p_poseset, 8u);
  poseset = v8->handle->poseset;
  if (v10)
  {
    v13 = poseset[18];
    v14 = poseset[19];
    v16 = poseset[20];
    v15 = poseset[21];
  }
  else
  {
    v13 = poseset[6];
    v14 = poseset[7];
    v16 = poseset[8];
    v15 = poseset[9];
    {
    }
  }
  v25.x = v13;
  v25.y = v14;
  v25.z = v16;
  v25.w = v15;
  v24 = op_Implicit_8738992(v25);
  v21 = fldGb->fieldID;
  if (v21 == 61)
  {
    areaID = fldGb->areaID;
    if (areaID >= 0x11)
    {
      if (areaID - 17 < 3 || areaID - 20 >= 3)
        v22 = 260;
      else
        v22 = 262;
    }
    else
    {
      v22 = 261;
    }
  }
  else
  {
    if (v21 != 60)
      return;
    switch (fldGb->areaID)
    {
      case 0:
      case 1:
        if (v24.y < -200.0)
        if (v24.y > 100.0)
      case 2:
      case 0xA:
      case 0xB:
      case 0xC:
      case 0xD:
      case 3:
      case 4:
      case 7:
      case 0xE:
        if (v24.y < -200.0)
        if (v24.y > 100.0)
          v22 = 256;
        else
          v22 = 257;
        break;
      case 5:
      case 6:
      case 9:
      case 0x10:
      case 0x15:
      case 8:
        if (v24.x < -1000.0)
        v22 = 259;
        break;
      default:
        v22 = 258;
        break;
    }
  }
  *encpid = v22;
}

// 0x15f8910
bool fldDispOn(void) {
    IsDLCField(0);
    IsLoad(0, 0);
    Load(0, 0);
    LoadAssetExt(0, 0, 0);
    FldDispOn(0);
    return 0;
}

// 0x15f5e00
s32 fldProcAmChk(void) {
  else if (fldProcAmWait > 0)
  {
    return 2;
  }
  return fldAutoMapChkMode() != 0;
}

// 0x15f4a00
s32 fldProcCampChk(void) {
  else if (fldProcCampWait > 0)
  {
    return 2;
  }
  else if (cmpChkCampProcess())
  {
    return 1;
  }
  if ((fldProcessFlag & 0x20) != 0)
    return 0;
  else
    return 3;
}

// 0x15f4350
s8 fldProcCheckFlag(u32 flag) {
  return (fldProcessFlag & flag) != 0;
}

// 0x15f4980
s32 fldProcHirakenaiChk(void) {
  return scrSearchScriptName(StringLiteral_16725) != 0;
}

// 0x15f4900
s32 fldProcKiretaChk(void) {
  return scrSearchScriptName(StringLiteral_16723) != 0;
}

// 0x15f4550
void fldProcNext(s32 fld, s32 eveno) {
  fldNext_fld = fld;
  fldNext_eveno = eveno;
  if (fld == 14 && eveno == 603)
  {
    fldBgmTokusyu = 1;
  }
}

// 0x1601820
s32 fldProcNextJump(void) {
    dds3AdminiGetNextSequence();
    dds3AdminiGetPrevHistoryFlag();
    fldCheckNextFile(0);
    fldDoor_EveBtlExit(0, 0);
    return 0;
}

// 0x15f4450
void fldProcOffFlag(u32 flag) {
  fldProcessFlag &= ~flag;
}

// 0x15f5d80
void fldProcOnFlag(u32 flag) {
  fldProcessFlag |= flag;
}

// 0x16015d0
void fldProcSetTerminal(s32 type, s32 idx) {
  fldDoor_Terminal(type, idx);
}

// 0x1601080
void fldProcShutDown(void) {
    fldSnowFree();
    dds3KillProcessName(0, 0);
    SetEnemyUI(0, 0, 0, 0, 0, 0, 0, 0, 0);
    SetRadarUI(0, 0, 0, 0, 0);
    fldFreeInputPanel();
    evtDisableMoonDraw();
    fldFreeAddressProcess();
    dds3EffectDistortionBlurDelete(0);
    scrAllReleaseScript();
}

// 0x16014d0
s8 fldProcShutDown2(void) {
  sdfDelayedResrcCheck();
  return 1;
}

// 0x15f28a0
s32 fldProcStartScript(void) {
  fldMain_c *v2;
  struct fldMain_StaticFields *static_fields;
  s32 mode;
  struct System_Char_array *FoceScript;
  struct fldWap_StaticFields *v7;
  struct System_Char_array *gFldWap_after_scr;
  System_String_o *String_5280336;
  System_String_o *v15;
  struct fldWap_StaticFields *v17;
  System_String_o *startPro;
  dds3Basic_t_o **p_ControlScene;
  dds3Basic_t_o *v27;
  dds3Basic_t_o *ControlScene;
  dds3Basic_t_o *scene;

  ControlScene = 0;
  scene = 0;
  v27 = 0;
  static_fields = v2->static_fields;
  mode = static_fields->fldSceneParam.mode;
  FoceScript = static_fields->fldSceneParam.FoceScript;
  else
  {
    v7 = fldWap->static_fields;
    if ((v7->gFldWap_after_flag & 2) == 0)
  }
  if (!LODWORD(gFldWap_after_scr->max_length))
  if (gFldWap_after_scr->m_Items[0])
  {
    scene = dds3GetControlScene();
    fldPlayerEventStop(0);
    String_5280336 = CreateString_5280336(0, gFldWap_after_scr);
    v15 = Replace_5267216(String_5280336, StringLiteral_859, StringLiteral_416);
    dds3SceneBasicStartScript(&scene, v15);
    v17 = fldWap->static_fields;
    if ((v17->gFldWap_after_flag & 1) == 0)
    {
      Clear(v17->gFldWap_after_scr, 0, 15, 0);
      gFldWap_after_flag &= 0xFDu;
    }
    return 1;
  }
  if (!mode)
  {
    if (FoceScript->m_Items[0])
    {
      ControlScene = dds3GetControlScene();
      fldPlayerEventStop(0);
      startPro = CreateString_5280336(0, FoceScript);
      p_ControlScene = &ControlScene;
    }
  }
  if (!fldGb->startPro)
    return 0;
  v27 = dds3GetControlScene();
  fldPlayerEventStop(0);
  startPro = fldGb->startPro;
  p_ControlScene = &v27;
  dds3SceneBasicStartScript(p_ControlScene, startPro);
  return 1;
}

// 0x1600d80
void fldProcTrigSequence(fldSceneParam_t *srcParam, s32 mode) {
  u64 *v8;
  u64 *v10;
  fldSceneParam_t_o v13;
  u8 dest[136];

  fldSequenceControl->fields = 0;
  else
  {
    fldSceneParam.mode = mode;
    if (mode)
  }
  fldSceneParam.noUnit = srcParam->noUnit;
  fldSceneParam.pointResrcID = srcParam->pointResrcID;
  fldSceneParam.pointResName = srcParam->pointResName;
  fldSceneParam.loadField = srcParam->loadField;
  fldSceneParam.loadArea = srcParam->loadArea;
  fldSceneParam.loadScript = srcParam->loadScript;
  fldSceneParam.callmode = srcParam->callmode;
  fldSceneParam.bgm = srcParam->bgm;
  fldSceneParam.bgmMode = srcParam->bgmMode;
  fldSceneParam.camMode = srcParam->camMode;
  fldSceneParam.camName = srcParam->camName;
  fldSceneParam.FoceScript = srcParam->FoceScript;
  fldSceneParam.loadMode = srcParam->loadMode;
  memcpy(dest, &fldSceneParam, sizeof(dest));
  memcpy(&v13, dest, sizeof(v13));
  MakeWarpIndex_21490048(&v13);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_fldProcess_ProcSequence__);
  dds3StartProcess(StringLiteral_16586, 0x3F7u, 0, 0, v8, 0, 0, 0, 0, 0);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_fldProcess_ProcDraw__);
  dds3StartProcess(StringLiteral_16727, 0x2B0Au, 0, 0, v10, 0, 0, 0, 0, 0);
  fldProcShutDownFlg = 1;
  InitOoyTest();
}

// 0x1601740
bool fldProc_CallSisetuReturn(void) {
  u64 v2;

  if (!fldNext_fld)
  if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
  return fldProcNextJump(v2) != 0;
}

// 0x1601650
void fldProc_SisetuReturnPoint(s32 fld, s32 area, u16 **pName) {
  s32 fldSeLastBgm;

  p2sdPause(fldSeLastBgm);
  fldSeLastBgm = 0;
}

// 0x15f43d0
s8 fldSeqCheckFlag(u32 flag) {
  return (fldSequenceControl->flag & flag) != 0;
}

// 0x15f55d0
void fldSeqOffFlag(u32 flag) {
  fldSequenceControl->flag &= ~flag;
}

// 0x15f44d0
void fldSeqOnFlag(u32 flag) {
  fldSequenceControl->flag |= flag;
}
