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
  s16 v25;
  s32 v26;
  struct fldProcess_StaticFields **p_static_fields;
  s32 fldProcAmWait;
  struct fldGlobal_StaticFields **v38;
  dds3Basic_t_o *scene;

  scene = 0;
  if (fldGb->fieldID >= 10)
  {
    else if (fldProcCampChk(fldProcess))
    {
      return 0;
    }
    if (fldProcAmWait > 0)
      goto LABEL_32;
    if (fldAutoMapChkMode())
      goto LABEL_32;
    if ((fldProcessFlag & 0x40) != 0)
    {
LABEL_32:
      AutomapRapid = fldDbg->AutomapRapid;
      if ((AutomapRapid & (fldProcessFlag >> 6) & 1) != 0)
      {
        v10 = DDS3_PADCHECK_PRESS(2);
          goto LABEL_56;
      }
      else
      {
        v10 = DDS3_PADCHECK_TRIG(2);
          goto LABEL_56;
      }
LABEL_56:
      fieldID = fldGb->fieldID;
      if (fieldID == 38)
        goto LABEL_199;
      if (fieldID == 44)
      {
        areaID = fldGb->areaID;
        if (areaID >= 11)
        {
          if (areaID < 27)
            goto LABEL_199;
        }
      }
      v21 = fldGb;
      if (v21->fieldID == 44)
      {
        if (v21->areaID == 30)
          goto LABEL_199;
      }
      v22 = fldGb;
      if (v22->fieldID == 45)
      {
        if (v22->areaID == 29)
          goto LABEL_199;
      }
      v23 = fldGb;
      if (v23->fieldID != 45)
        goto LABEL_123;
      if (v23->areaID == 30)
      {
LABEL_199:
        if (!fldGb->NoInpAmCnt)
        {
          if ((fldProcessFlag & 0x40) != 0 && v10)
          {
            fldGb->NoInpAmCnt = 4;
            fldGb->NoInpPlCnt = 5;
            fldReleaseUnitPad();
            scene = dds3GetActiveScene();
            fldPlayerEventStop(0);
            dds3SceneBasicStartScript(&scene, "hirakenai_label");
          }
        }
      }
      else
      {
LABEL_123:
        if ((v25 & 0x200) != 0)
        {
          v26 = v25 & 0x200;
        }
        else
        {
          v26 = 0;
        }
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
                    if (!fldDbg->EncountBtnOn)
                    {
                      fldGb->NoInpAmCnt = 4;
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
          fldProcAmWait = fldProcAmWait - 1;
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
  s16 v4;
  s32 v5;
  struct fldProcess_StaticFields **p_static_fields;
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
    if (fldProcCampWait >= 1)
    {
      fldProcCampWait = fldProcCampWait - 1;
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
LABEL_38:
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
  struct fldSequenceControl_t_o *fldSequenceControl;
  u64 v8;
  s32 fieldID;
  struct System_Int32_array *pm;
  struct System_Int32_array *v26;
  u64 *v28;
  struct fldGlobalWork_t_o *fldGb;
  struct System_Int32_array *v31;
  struct System_Int32_array *v33;
  struct fldGlobalWork_t_o *v35;
  s32 areaID;
  struct System_Int32_array *v38;
  struct System_Int32_array *v40;
  s32 v42;
  struct System_Int32_array *v44;
  struct System_Int32_array *v46;
  struct System_Int32_array *v49;
  struct System_Int32_array *v51;
  struct fldGlobalWork_t_o *v53;
  struct System_Int32_array *v55;
  struct System_Int32_array *v57;
  struct fldGlobalWork_t_o *v60;
  s32 v61;
  struct dds3Effect_Blur_t_o *fldAmaraBlurBuff;
  s32 v64;
  struct System_Int32_array *v65;
  struct System_Int32_array *v67;
  struct fldGlobalWork_t_o *v70;
  struct System_Int32_array *v72;
  struct System_Int32_array *v74;
  struct fldGlobalWork_t_o *v76;
  s32 v77;
  struct fldGlobalWork_t_o *v78;
  s32 v79;
  struct System_Int32_array *v81;
  struct System_Int32_array *v83;
  struct fldGlobalWork_t_o *v85;
  struct fldGlobalWork_t_o *v86;
  struct fldGlobalWork_t_o *v87;
  struct System_Int32_array *v89;
  struct System_Int32_array *v91;
  struct fldGlobalWork_t_o *v93;
  s32 v94;
  struct System_Int32_array *v96;
  struct System_Int32_array *v98;
  struct fldGlobalWork_t_o *v100;
  struct System_Int32_array *v102;
  struct System_Int32_array *v104;
  struct fldGlobalWork_t_o *v106;
  struct System_Int32_array *v108;
  struct System_Int32_array *v110;
  struct fldGlobalWork_t_o *v112;
  struct System_Int32_array *v114;
  struct System_Int32_array *v116;
  struct fldGlobalWork_t_o *v118;
  s32 v119;
  struct fldGlobalWork_t_o *v122;
  s32 v123;
  dds3Effect_Filter_t_o *pFilter;

  pFilter = 0;
  if (dds3AdminiGetNextSequence() != -1)
  {
    fldPlayer_Enc_Correction_Unity();
    return 0;
  }
  else if (fldLoadNextGetStatus() != 1)
  {
    goto LABEL_20;
  }
  if (fldSequenceControl->phase)
  {
LABEL_20:
    if (encChk())
      return 0;
    if (fmProcessChk())
      return 0;
    if ((*(*(*(v8 + 184) + 16LL) + 16LL) & 2) != 0)
      return 0;
    if (fldProcCampChk(v8) == 1)
      return 0;
    if (!fldAutoMapChkMode())
    {
      if (!fldProcCampChk())
      {
        fldNpcDraw();
      }
    }
    fldWaveTask();
    fldAutoMapDraw();
    fldSnowTask();
    fldElvFloorTask();
    if (fldSequenceControl->phase < 4)
      return 0;
    fldPlayer_Correction_Unity();
    if ((fldProcessFlag & 0x40) != 0)
    {
      fldEve_BloomDof_AfterEnd();
      if (fldSequenceControl->phase < 4)
        return 0;
    }
    else
    {
      fldEventUpdateEx_Unity_2();
      fldEve_BloomDof_Set();
      if (fldSequenceControl->phase < 4)
        return 0;
    }
    if (fldDbg->ExBlurOn != 1)
      return 0;
    if (encChk())
      return 0;
    fieldID = fldGb->fieldID;
    if (fieldID == 18)
      goto LABEL_107;
    if (fieldID == 28)
      goto LABEL_107;
    if (fieldID == 30)
    {
LABEL_107:
      fldAmaraBlurBuff->abgr = 947945642;
      fldAmaraBlurBuff->blend = 1;
      fldAmaraBlurBuff->rotate = 0.002;
      fldAmaraBlurBuff->scale = 0.993;
      pm = fldAmaraBlurBuff->center->pm;
      pm->m_Items[0] = 0;
      v26 = fldAmaraBlurBuff->center->pm;
      v26->m_Items[1] = 0;
      dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      v28 = Allocate(dds3Effect_Filter_t);
      dds3Effect_Filter_t___ctor(v28);
      pFilter = v28;
      v28[2] = 0x210403080LL;
      dds3EffectFilter(&pFilter, 0, 0);
    }
    if (fldGb->fieldID == 12)
    {
      if (!fldGb->areaID)
      {
        fldAmaraBlurBuff->abgr = 810046080;
        fldAmaraBlurBuff->blend = 1;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 1.0;
        v31 = fldAmaraBlurBuff->center->pm;
        v31->m_Items[0] = 0;
        v33 = fldAmaraBlurBuff->center->pm;
        v33->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    v35 = fldGb;
    if (v35->fieldID == 15)
    {
      areaID = v35->areaID;
      if (areaID == 19)
        goto LABEL_149;
      if (areaID == 20)
      {
LABEL_149:
        fldAmaraBlurBuff->abgr = 407392896;
        fldAmaraBlurBuff->blend = 1;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 1.0;
        v38 = fldAmaraBlurBuff->center->pm;
        v38->m_Items[0] = 0;
        v40 = fldAmaraBlurBuff->center->pm;
        v40->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
      v42 = fldGb->areaID;
      if (v42 == 2)
        goto LABEL_172;
      if (v42 == 3)
        goto LABEL_172;
      if (v42 == 4)
      {
LABEL_172:
        fldAmaraBlurBuff->abgr = 676878464;
        fldAmaraBlurBuff->blend = 2;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 0.995;
        v44 = fldAmaraBlurBuff->center->pm;
        v44->m_Items[0] = 0;
        v46 = fldAmaraBlurBuff->center->pm;
        v46->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    if (fldGb->fieldID == 16)
    {
      fldAmaraBlurBuff->abgr = 516469960;
      fldAmaraBlurBuff->blend = 1;
      fldAmaraBlurBuff->rotate = 0.0;
      fldAmaraBlurBuff->scale = 1.0;
      v49 = fldAmaraBlurBuff->center->pm;
      v49->m_Items[0] = 0;
      v51 = fldAmaraBlurBuff->center->pm;
      v51->m_Items[1] = 0;
      dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
    }
    v53 = fldGb;
    if (v53->fieldID == 17)
    {
      if (!v53->areaID)
      {
        fldAmaraBlurBuff->abgr = 545292486;
        fldAmaraBlurBuff->blend = 1;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 1.0;
        v55 = fldAmaraBlurBuff->center->pm;
        v55->m_Items[0] = 0;
        v57 = fldAmaraBlurBuff->center->pm;
        v57->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
        Postblur_AccumTex_NowMode = 1;
      }
    }
    v60 = fldGb;
    if (v60->fieldID == 23)
    {
      v61 = v60->areaID;
      if (v61)
      {
        if (v61 == 1)
        {
          v64 = 138457308;
        }
        else
        {
          if (v61 != 6)
            goto LABEL_256;
          v64 = 276865244;
        }
      }
      else
      {
        v64 = 201367772;
      }
      fldAmaraBlurBuff->abgr = v64;
      fldAmaraBlurBuff->blend = 1;
      fldAmaraBlurBuff->rotate = 0.0;
      fldAmaraBlurBuff->scale = 0.996;
      v65 = fldAmaraBlurBuff->center->pm;
      v65->m_Items[0] = 0;
      v67 = fldAmaraBlurBuff->center->pm;
      v67->m_Items[1] = 0;
      dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
    }
LABEL_256:
    v70 = fldGb;
    if (v70->fieldID == 24)
    {
      if (v70->areaID == 17)
      {
        fldAmaraBlurBuff->abgr = 813864628;
        fldAmaraBlurBuff->blend = 1;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 0.99;
        v72 = fldAmaraBlurBuff->center->pm;
        v72->m_Items[0] = 0;
        v74 = fldAmaraBlurBuff->center->pm;
        v74->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    v76 = fldGb;
    if (v76->fieldID == 25)
    {
      v77 = v76->areaID;
      if (v77 == 16)
        goto LABEL_505;
      if (v77 == 17)
        goto LABEL_505;
      if (v77 == 18)
        goto LABEL_505;
      if (v77 == 19)
        goto LABEL_505;
      if (v77 == 20)
        goto LABEL_505;
      if (v77 == 24)
      {
LABEL_505:
        dds3EffectDistortionBlurDraw(&fldBlurKabuki, 0, 0);
      }
    }
    v78 = fldGb;
    if (v78->fieldID == 27)
    {
      v79 = v78->areaID;
      if (!v79)
        goto LABEL_334;
      if (v79 == 1)
        goto LABEL_334;
      if (v79 == 2)
        goto LABEL_334;
      if (v79 == 3)
        goto LABEL_334;
      if (v79 == 4)
      {
LABEL_334:
        fldAmaraBlurBuff->abgr = 813864628;
        fldAmaraBlurBuff->blend = 1;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 0.997;
        v81 = fldAmaraBlurBuff->center->pm;
        v81->m_Items[0] = 0;
        v83 = fldAmaraBlurBuff->center->pm;
        v83->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    v85 = fldGb;
    if (v85->fieldID == 32)
    {
      if (v85->areaID == 19)
        goto LABEL_369;
    }
    v86 = fldGb;
    if (v86->fieldID == 36)
    {
      if (v86->areaID == 20)
        goto LABEL_369;
    }
    v87 = fldGb;
    if (v87->fieldID == 37)
    {
      if (v87->areaID == 25)
      {
LABEL_369:
        fldAmaraBlurBuff->abgr = 949256320;
        fldAmaraBlurBuff->blend = 2;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 1.0;
        v89 = fldAmaraBlurBuff->center->pm;
        v89->m_Items[0] = 0;
        v91 = fldAmaraBlurBuff->center->pm;
        v91->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    v93 = fldGb;
    if (v93->fieldID == 34)
    {
      v94 = v93->areaID;
      if (v94 == 1)
        goto LABEL_392;
      if (v94 == 2)
      {
LABEL_392:
        fldAmaraBlurBuff->abgr = 812677248;
        fldAmaraBlurBuff->blend = 2;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 1.0;
        v96 = fldAmaraBlurBuff->center->pm;
        v96->m_Items[0] = 0;
        v98 = fldAmaraBlurBuff->center->pm;
        v98->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    v100 = fldGb;
    if (v100->fieldID == 36)
    {
      if (v100->areaID == 16)
      {
        fldAmaraBlurBuff->abgr = 813204138;
        fldAmaraBlurBuff->blend = 1;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 1.0;
        v102 = fldAmaraBlurBuff->center->pm;
        v102->m_Items[0] = 0;
        v104 = fldAmaraBlurBuff->center->pm;
        v104->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    v106 = fldGb;
    if (v106->fieldID == 37)
    {
      if (v106->areaID == 23)
      {
        fldAmaraBlurBuff->abgr = 595100330;
        fldAmaraBlurBuff->blend = 2;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 1.0;
        v108 = fldAmaraBlurBuff->center->pm;
        v108->m_Items[0] = 0;
        v110 = fldAmaraBlurBuff->center->pm;
        v110->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    v112 = fldGb;
    if (v112->fieldID == 37)
    {
      if (v112->areaID == 26)
      {
        fldAmaraBlurBuff->abgr = 427986080;
        fldAmaraBlurBuff->blend = 2;
        fldAmaraBlurBuff->rotate = 0.0;
        fldAmaraBlurBuff->scale = 1.0;
        v114 = fldAmaraBlurBuff->center->pm;
        v114->m_Items[0] = 0;
        v116 = fldAmaraBlurBuff->center->pm;
        v116->m_Items[1] = 0;
        dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      }
    }
    v118 = fldGb;
    if (v118->fieldID == 42)
    {
      v119 = v118->areaID;
      if (v119 == 13)
        goto LABEL_506;
      if (v119 == 25)
      {
LABEL_506:
        dds3EffectDistortionBlur_SetFldEvent(67137540);
        dds3EffectDistortionBlurDraw(&fldBlurKabuki, 0, 0);
      }
    }
    v122 = fldGb;
    if (v122->fieldID == 44)
    {
      v123 = v122->areaID;
      if (v123 == 2)
        goto LABEL_507;
      if (v123 == 4)
        goto LABEL_507;
      if (v123 == 24)
      {
LABEL_507:
        dds3EffectDistortionBlur_SetFldEvent(67137540);
        dds3EffectDistortionBlurDraw(&fldBlurKabuki, 0, 0);
      }
    }
  }
  return 0;
}

// 0x15f2cb0
void *ProcRandomEncountCheck(void) {
  struct fldEncountContol_t_o *fldEncountControl;
  struct fldGlobalWork_t_o *fldGb;
  s32 NoInpAmCnt;
  struct fldGlobalWork_t_o *v7;
  s32 NoInpPlCnt;
  struct fldGlobalWork_t_o *v9;
  s32 NoEncountCnt;
  Il2CppObject *result;
  dds3Basic_t_o *v14;
  UnityEngine_Vector4_o *p_unitPos;
  f32 x;
  f32 v19;
  f32 v21;
  s32 AgeOfMoon16;
  struct fldGlobalWork_t_o *v24;
  f32 v27;
  s32 flag;
  s32 v32;
  fldGlobal_c *v33;
  struct fldGlobalWork_t_o *v34;
  struct fldGlobalWork_t_o *v35;
  struct fldGlobalWork_t_o *v36;
  struct fldGlobalWork_t_o *v37;
  struct fldGlobalWork_t_o *v38;
  struct fldGlobal_StaticFields **p_static_fields;
  f32 v48;
  struct fldGlobalWork_t_o *v49;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  s32 v54;
  s32 Status;
  bool v59;
  s32 takarasagasi_oldmoon;
  s32 v66;
  char v72;
  s32 areaID;
  s32 v79;
  struct fldGlobalWork_t_o *v83;
  s32 encountpack;
  s32 v88;
  char v96;
  s32 v98;
  s32 v104;
  s32 v107;
  s32 v108;
  s32 encpid;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *scene;
  UnityEngine_Vector4_o v112;

  scene = 0;
  pBasic = 0;
  encpid = 0;
  NoInpAmCnt = fldGb->NoInpAmCnt;
  if (NoInpAmCnt >= 1)
  {
    fldGb->NoInpAmCnt = NoInpAmCnt - 1;
  }
  v7 = fldGb;
  NoInpPlCnt = v7->NoInpPlCnt;
  if (NoInpPlCnt >= 1)
  {
    v7->NoInpPlCnt = NoInpPlCnt - 1;
  }
  v9 = fldGb;
  NoEncountCnt = v9->NoEncountCnt;
  if (NoEncountCnt >= 1)
  {
    v9->NoEncountCnt = NoEncountCnt - 1;
  }
LABEL_34:
  else if ((fldProcessFlag & 0x40) == 0)
  {
    return 0;
  }
  if ((fldSequenceControl->flag & 1) != 0)
    return 0;
LABEL_45:
  result = dds3GetActiveScene();
  scene = result;
  if (!result)
    return result;
  v14 = result;
  result = dds3GetActiveUnitSceneBasic(v14);
  pBasic = result;
  if (!result)
    return result;
  dds3GetPosPoseSet(&pBasic);
  x = fldEncountControl->unitPos.x;
  p_unitPos = &fldEncountControl->unitPos;
  v112.x = x;
  v112.w = p_unitPos->w;
  v112.y = p_unitPos->y;
  v112.z = p_unitPos->z;
  SDF_VU0__LOADVECTOR_B(v112);
  SDF_VU0__STOREVECTOR(p_unitPos);
  SDF_VU0__SUBVECTOR();
  v19 = SDF_VU0__GETLENGTH();
  if (v19 >= 0.2)
    v21 = v19;
  else
    v21 = 0.0;
  fldGb->LastMoveLeng = v21;
  AgeOfMoon16 = evtGetAgeOfMoon16();
  v24 = fldGb;
  if (v24->NoEncountCnt >= 1)
  {
    dds3GetPosPoseSet(&pBasic);
    SDF_VU0__STOREVECTOR(p_unitPos);
    fldGb->LastMoveLeng = 0.0;
    return 0;
  }
  if (v24->fieldID <= 9)
  {
    v27 = v21 * 4.0;
  }
  else
  {
    v27 = v21;
  }
  evtMoonAddMove(v27);
  flag = fldGb->flag;
  if ((flag & 1) != 0)
    goto LABEL_463;
  if ((flag & 2) != 0)
    goto LABEL_463;
  if ((flag & 4) != 0)
    goto LABEL_463;
  if ((flag & 8) != 0)
  {
LABEL_463:
    fldReleaseUnitPad();
    scene = dds3GetActiveScene();
    fldPlayerEventStop(0);
    dds3SceneBasicStartScript(&scene, "kireta_label");
    fldPlayerPosRot();
    return 0;
  }
  v32 = evtGetAgeOfMoon16();
  v34 = fldGb;
  if (v34->fieldID == 42)
  {
    if (v34->areaID == 13)
      goto LABEL_464;
  }
  v35 = fldGb;
  if (v35->fieldID == 42)
  {
    if (v35->areaID == 25)
      goto LABEL_464;
  }
  v36 = fldGb;
  if (v36->fieldID == 44)
  {
    if (v36->areaID == 2)
      goto LABEL_464;
  }
  v37 = fldGb;
  if (v37->fieldID == 44)
  {
    if (v37->areaID == 4)
      goto LABEL_464;
  }
  v38 = fldGb;
  if (v38->fieldID == 44)
  {
    if (v38->areaID == 24)
    {
LABEL_464:
      if (fldDbg->SpProcOn)
      {
        fldGb->DmgLeng = v21 + fldGb->DmgLeng;
        if ((*p_static_fields)->fldGb->DmgLeng > 450.0)
        {
          fldProcessFlag &= ~0x40u;
          fldGb->NoroiDamegeCnt = 60;
          fldGb->DmgLeng = 0.0;
          datPartyDamageFld(4);
          return 0;
        }
      }
LABEL_251:
      if (AgeOfMoon16 == v32)
        goto LABEL_256;
      goto LABEL_252;
    }
  }
  if (fldGb->DmgOn)
    goto LABEL_465;
  if ((fldDbg->PlayerStatus & 1) != 0)
  {
LABEL_465:
    fldGb->DmgLeng = v21 + fldGb->DmgLeng;
    if (fldGb->DmgOn)
    {
      v48 = 450.0;
      if ((v33->_2.bitflags2 & 2) == 0)
      {
LABEL_213:
        v49 = fldGb;
        if (v49->DmgLeng <= v48)
          goto LABEL_251;
        if (v49->DmgOn)
        {
          if ((DDS3_GBWK->stat & 4) != 0)
          {
            gfldPlayerDamegeCnt = 0;
            fldGb->DmgLeng = 0.0;
            goto LABEL_251;
          }
          gfldPlayerDamegeCnt = 60;
          fldGb->DmgLeng = 0.0;
          v54 = 2;
        }
        else
        {
          gfldPlayerDamegeCnt = 60;
          fldGb->DmgLeng = 0.0;
          v54 = 1;
        }
        datPartyDamageFld(v54);
        if (AgeOfMoon16 == v32)
          goto LABEL_256;
LABEL_252:
        datFieldSkillKaifuku();
        goto LABEL_256;
      }
    }
    else
    {
      v48 = flt_32C3180[(fldDbg->PlayerStatus & 1) == 0];
      if ((v33->_2.bitflags2 & 2) == 0)
        goto LABEL_213;
    }
    goto LABEL_213;
  }
  fldGb->DmgLeng = 450.0;
  if (AgeOfMoon16 != v32)
    goto LABEL_252;
LABEL_256:
  Status = fldLoadNextGetStatus();
  result = 0;
  if (Status != 1)
  {
    v59 = cfgGetBit(9u) == 0;
    if (v59)
      v21 = v21 * 0.3;
    if (fldGb->fieldID <= 9)
    {
      if (!fldEveHitProcess_Chk())
      {
        if (takarasagasi_oldmoon != evtGetAgeOfMoon16())
        {
          if (!DDS3_GBWK->Moon->TakaraCnt)
          {
            v98 = datCheckSkillTakaraSagasi();
            gFldTakaraAkumaId = v98;
            if (gFldTakaraAkumaId)
            {
              fldReleaseUnitPad();
              scene = dds3GetActiveScene();
              fldPlayerEventStop(0);
              dds3SceneBasicStartScript(&scene, "takarasagasi_label");
              v104 = evtGetAgeOfMoon16();
              v107 = v104;
              takarasagasi_oldmoon = v107;
              return 0;
            }
          }
        }
      }
    }
    v66 = evtGetAgeOfMoon16();
    takarasagasi_oldmoon = v66;
    if (!fldDbg->EncountOn)
      goto LABEL_466;
    if (!fldRunEncountChk())
      goto LABEL_466;
    if (!fldDbg->SpProcOn)
    {
LABEL_466:
      if (v21 < 9998.0)
      {
        if (!fldDbg->EncountOn)
          return 0;
      }
      if ((fldProcessFlag & 0x10) == 0)
        return 0;
      v83 = fldGb;
      encpid = v83->EncPIDUpper;
      if (!encpid)
      {
        encpid = v83->EncPID;
      }
      fldDLCEncountCheck(&encpid);
      fldBattleData.encountpack = encpid;
      encountpack = fldBattleData.encountpack;
      v88 = nbEncountCalc(encountpack, v21);
      fldBattleData.encounttbl = v88;
      if (!fldBattleData.encounttbl)
        return 0;
      if (v21 <= 9998.0 && fldDbg->EncountOn != 1)
      {
        nbResetEncountCount();
        dds3FadeIn(0x80u, 0x80u, 0x80u, 6u);
        ++gEncountRireki;
        return 0;
      }
      fldEveHit_End();
      else
      {
        v96 = 1;
      }
      fldSequenceControl->flag |= 1u;
      fldSequenceControl->flag |= 2u;
      fldReleaseUnitPad();
      evtKillFieldScript();
LABEL_460:
      v108 = -1;
      return sub_8D3950(s32, &v108);
    }
    fldEveHit_End();
    else
    {
      v72 = 1;
    }
    fldSequenceControl->flag |= 1u;
    fldSequenceControl->flag |= 2u;
    fldReleaseUnitPad();
    evtKillFieldScript();
    fldBattleData.encountpack = 0;
    fldBattleData.encounttbl = 1034;
    areaID = fldGb->areaID;
    if ((areaID - 7) >= 4)
    {
      if ((areaID - 4) >= 2)
      {
        if (areaID != 3)
          goto LABEL_456;
        else
        {
          v79 = 200;
        }
      }
      else
      {
        else
        {
          v79 = 201;
        }
      }
    }
    else
    {
      v79 = 202;
    }
    fldNext_fld = 43;
    fldNext_eveno = v79;
LABEL_456:
    CallBattleSub(1034, 0);
    goto LABEL_460;
  }
  return result;
}

// 0x15f6890
dds3ProcessFunc_t *ProcSequence(dds3ProcessID_t *id) {
  struct fldSequenceControl_t_o *fldSequenceControl;
  s32 bgmMode;
  u64 v11;
  u32 v14;
  s32 CamTableIdx;
  dds3Basic_t_o *ControlScene;
  struct fldGlobal_StaticFields **p_static_fields;
  s32 SkyTblID;
  u64 *v39;
  s64 v41;
  s64 v43;
  effDistortionBlurHandle_t_o *v45;
  s32 fieldID;
  u64 *v48;
  s64 v50;
  s64 v52;
  effDistortionBlurHandle_t_o *v54;
  struct fldGlobalWork_t_o *fldGb;
  s32 v62;
  s32 areaID;
  s32 v79;
  struct fldGlobalWork_t_o *v84;
  fldUnitControl_t_o *UnitControl;
  dds3Basic_t_o *player;
  s32 fldSeLastBgm;
  struct fldGlobalWork_t_o *v109;
  s32 AllPanelCnt;
  s32 v111;
  s32 v112;
  u64 *v137;
  fldGlobal_c *v139;
  dds3Basic_t_o *v152;
  s64 *achievementTbl;
  System_String_o *v155;
  struct nbNewBattleSeqData_t_o fldBattleData;
  dds3Basic_t_o *basic;

  basic = 0;
  bgmMode = fldSceneParam.bgmMode;
  if (dds3AdminiGetNextSequence() == -1)
  {
    else if (fmProcessChk())
    {
      return 0;
    }
    fldLoadNextTask();
    if (fldSequenceControl->phase)
      goto LABEL_637;
    if (fldLoadNextGetStatus() != 1)
    {
LABEL_637:
      if (*(*(v11 + 184) + 96LL) != -1)
      {
        fldBgmSisetuLoadChk(v11);
      }
      v14 = fldProcCampChk() - 1;
      if (v14 <= 1)
      {
        ProcCampCheck();
        return 0;
      }
      if ((fldProcessFlag & 0x40) == 0)
      {
        fldPlayerPosRot();
      }
      switch (fldSequenceControl->phase)
      {
        case 0:
          SetBoostFrameRate(kernelObject);
          SetShadowMode(kernelObject, 1);
          FldDataLoadRequest();
          fldSequenceControl->phase = 1;
          goto LABEL_395;
        case 1:
          if (!IsFldDataLoaded())
            goto LABEL_395;
          if (!fldDispOn())
            return 0;
          gFldRndEncBtl = 0;
          gFldStart = 1;
          fldGbInit_Field();
          dds3BackColor = 0x80000000;
          evtEnableMoonCalc();
          gfldSkyHokan = 0;
          CamTableIdx = fldGb->CamTableIdx;
          if (CamTableIdx == 6)
            goto LABEL_638;
          if (CamTableIdx == 7)
            goto LABEL_638;
          if (CamTableIdx == 1)
          {
LABEL_638:
            fldGb->CamTableIdx = 0;
          }
          fldReadyScene();
          ControlScene = dds3GetControlScene();
          dds3SetActiveScene(ControlScene);
          fldInitInputPanel();
          evtEnableMoonDraw();
          fldInitAddressProcess();
          if (fldGb->fieldID >= 200)
          {
            fldDbg->SkyTblID = 0;
            (*p_static_fields)->fldDbg->SkyTblAnm = 0;
            SkyTblID = (*p_static_fields)->fldDbg->SkyTblID;
            fldSkySetTbl(SkyTblID, 0);
            fldSkySetTableAnime(fldDbg->SkyTblAnm);
          }
          if (fldGb->fieldID == 25)
          {
            v39 = Allocate(dds3Effect_DistortionBlurParam_t);
            dds3Effect_DistortionBlurParam_t___ctor(v39);
            v39[2] = 0x3200000023LL;
            v39[3] = 0x508080803D4CCCCDLL;
            *(v39 + 8) = 1;
            *(v39 + 36) = 0x3EAE147B3CCCCCCDLL;
            v41 = *(v39[6] + 16);
            *(v41 + 32) = 0;
            v43 = *(v39[6] + 16);
            *(v43 + 36) = 0;
            v39[7] = 0x5000000096LL;
            v45 = dds3EffectDistortionBlurCreate(v39);
            fldBlurKabuki = v45;
          }
          fieldID = fldGb->fieldID;
          if (fieldID == 42)
            goto LABEL_147;
          if (fieldID == 44)
          {
LABEL_147:
            v48 = Allocate(dds3Effect_DistortionBlurParam_t);
            dds3Effect_DistortionBlurParam_t___ctor(v48);
            v48[2] = 0x1400000014LL;
            v48[3] = 0x403000803E4CCCCDLL;
            *(v48 + 8) = 1;
            *(v48 + 36) = 0x3E4CCCCD3F800000LL;
            v50 = *(v48[6] + 16);
            *(v50 + 32) = 0;
            v52 = *(v48[6] + 16);
            *(v52 + 36) = 0;
            v48[7] = 0x6400000096LL;
            v54 = dds3EffectDistortionBlurCreate(v48);
            fldBlurKabuki = v54;
          }
          dds3FadeOut2(0);
          fldCamResetNpc();
          fldSnowSeedInit();
          fldSnowSeedReset();
          fldStatusSet();
          v62 = fldGb->fieldID;
          areaID = fldGb->areaID;
          fldPPSV2_Set(v62, areaID + 1);
          goto LABEL_250;
        case 2:
          LoadEventModel();
          if (!fldEventDataLoadChk())
            goto LABEL_395;
          if (!fldFootSeLoadChk())
            goto LABEL_395;
          if (!fldCmnBgmSeLoadChk())
            goto LABEL_395;
          if (!IsStartModelLoaded())
            goto LABEL_395;
          LODWORD(v68[2].klass->_1.namespaze) &= ~0x40u;
          fldProcStartScript();
          fldCamMain();
          fldBgmLoad();
          gFldFootSeLoadPhase = 0;
          gFldCmnBgmSeLoadPhase = 0;
          gFldEventDataLoadPhase = 0;
          goto LABEL_250;
        case 3:
          gFldBgmLoadPhase = -1;
          gFldStart = 0;
          if (fldGetRestoreMode() == 1)
            goto LABEL_243;
          if (fldGetRestoreMode() == 4)
            goto LABEL_243;
          if (fldGetRestoreMode() == 6)
            goto LABEL_243;
          if (fldBgmTokusyu)
          {
LABEL_243:
            fldBgmContinue();
            {
LABEL_247:
            }
          }
          else
          {
            if (bgmMode)
            {
              fldBgmPlay2();
                goto LABEL_247;
            }
            else
            {
              fldBgmPlay();
                goto LABEL_247;
            }
          }
          fldBgmTokusyu = 0;
          goto LABEL_250;
        case 4:
          v79 = 5;
          goto LABEL_394;
        case 5:
          SetNormalFrameRate(kernelObject);
          fldSnowInit();
          v84 = fldGb;
          if (!v84->FukiTalk)
          {
            if (v84->fieldID != 11)
              goto LABEL_639;
            if (v84->areaID != 1)
            {
LABEL_639:
              if (!dds3FadeCheck())
              {
                if (!gfldPlayerAnaCnt)
                {
                  dds3FadeIn2(8u);
                }
              }
            }
          }
          ++fldSequenceControl->phase;
          if (!dds3SearchProcessPriority(1002))
          {
            fldRegistUnitPad();
          }
          UnitControl = fldGetUnitControl();
          dds3ObjectBaseOffFlag(&UnitControl->handle, 0x40u);
          if (!KagPuzNow)
          {
            fldProcessFlag |= 0x10u;
          }
          fldProcessFlag |= 0x20u;
          fldTitleMiniStart2();
          goto LABEL_395;
        case 6:
          if (fldDbg->SpProcOn)
          {
            fldRunView();
          }
          gfldSkyHokan = 1;
          if ((fldProcessFlag & 0x40) == 0)
            goto LABEL_343;
          if (fldEveHit_ChkEveHitAfter())
            return 0;
LABEL_343:
          if ((fldProcessFlag & 0x40) != 0)
          {
            if (fldGb->FukiTalk)
            {
              fldEveHit_ChkEveHit(player);
              goto LABEL_395;
            }
          }
          if (!evtBitCheck(2208) && !evtBitCheck(2225))
            goto LABEL_532;
          if ((fldProcessFlag & 0x40) == 0)
            goto LABEL_532;
          if (!DDS3_PADCHECK_TRIG(13))
            goto LABEL_532;
          if (evtBitCheck(2800))
          {
            evtBitOff(2800);
              goto LABEL_535;
            goto LABEL_533;
          }
          evtBitOn(2800);
LABEL_532:
          {
LABEL_533:
          }
LABEL_535:
          if (fldDbg->MenuOn)
          {
            if ((v139->_2.bitflags2 & 2) == 0)
              goto LABEL_559;
LABEL_537:
LABEL_559:
            if (fldDbg->MenuOn)
              goto LABEL_564;
LABEL_560:
            ProcAmCheck();
LABEL_564:
            if ((fldProcessFlag & 0x40) != 0)
            {
              fldPanelSet(1);
              ProcRandomEncountCheck();
            }
            if ((fldSequenceControl->flag & 2) != 0)
            {
              encStart(1);
LABEL_250:
              v79 = fldSequenceControl->phase + 1;
LABEL_394:
              fldSequenceControl->phase = v79;
              goto LABEL_395;
            }
            fldPlayerCalc();
            if ((fldProcessFlag & 0x40) == 0)
            {
LABEL_395:
              v109 = fldGb;
              switch (v109->AllPanelMode)
              {
                case 2:
                case 6:
                  AllPanelCnt = v109->AllPanelCnt;
                  if (AllPanelCnt >= 1)
                  {
                    v111 = AllPanelCnt - 1;
                    goto LABEL_415;
                  }
                  break;
                case 3:
                case 7:
                  v112 = v109->AllPanelCnt;
                  if (v112 <= 14)
                  {
                    v111 = v112 + 1;
LABEL_415:
                    v109->AllPanelCnt = v111;
                  }
                  break;
                default:
                  break;
              }
              if (fldProcCampChk() != 1)
              {
                fldLightMaTask();
                fldSkyCalcTable();
                fldSkyCalcFilter();
                if (fldGb->fieldID == 1)
                {
                  fldHitWM_Mask();
                }
              }
              if (fldSequenceControl->phase >= 6)
              {
                fldSe_Task();
                fldBgmBitChk();
                if (!fldDbg->MenuOn)
                {
                  fldAutoMapProc();
                  fldAutoMapChkMode();
                }
                if (!fldAutoMapChkMode())
                {
                  if (!fldProcCampChk())
                  {
                    {
                    }
                    if (!scrSearchScriptName("kireta_label"))
                    {
                      {
                      }
                      if (!scrSearchScriptName("hirakenai_label"))
                      {
                        if (!fldGb->NoroiDamegeCnt)
                        {
                          fldNpcCalc();
                          fldItemBoxCalcTask();
                        }
                      }
                    }
                  }
                }
              }
              if (fldProcCampChk() != 1)
              {
                fldCamMain();
              }
              return 0;
            }
            if (fldGb->fieldID <= 9)
            {
              if (fldWmWarpMode == 3)
                goto LABEL_617;
            }
            v152 = player;
            fldEveHit_ChkEveHit(v152);
LABEL_617:
            if (!fldGb->NoInpPlCnt)
            {
              if (CheckTypeClose())
              {
                achievementTbl = get_achievementTbl();
                v155 = sub_B7950(0x17u, DefineAchievementID_string_, achievementTbl);
                Unlock_16599376(v155);
              }
            }
            goto LABEL_395;
          }
          ProcCampCheck();
          if ((fldSequenceControl->flag & 2) == 0)
          {
            if ((fldProcessFlag & 0x20) == 0)
              goto LABEL_395;
              goto LABEL_559;
            goto LABEL_537;
          }
          break;
        case 7:
          basic = dds3GetActiveScene();
          dds3VisibleSceneBasic(&basic, 0);
          fldPanelSet(0);
          p2sdPause(fldSeLastBgm);
          fldSeLastBgm = 0;
          p2sdPlaySE(15);
          gEncountBlurCnt = 0;
          v79 = 8;
          goto LABEL_394;
        case 8:
          ++gEncountBlurCnt;
          v79 = 9;
          goto LABEL_394;
        case 9:
          fldEventDataUnload();
          fldFootSeUnload();
          fldCmnBgmSeUnload();
          fldFreeNextFile();
          fldLoadNextFile_SetId_BtlRet(fldGb->fieldID, fldGb->areaID + 1);
          fldSequenceControl->phase = 0;
          Log("!!!!!!!!!!!!!!!!!Fight!!!!!!!!!!!!!!!!!!!!", 0);
          nbNoDestroy_MoveCache_Field_F_ModeOn();
          ++gEncountRireki;
          gFldRndEncBtl = 1;
          v137 = sub_8D3950(nbNewBattleSeqData_t, &fldBattleData);
          dds3AdminiCallSequence(20, v137, 0, 1);
          id->func_ans = -1;
          return 0;
        default:
          goto LABEL_395;
      }
    }
  }
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
      goto LABEL_21;
  }
  else
  {
    v13 = poseset[6];
    v14 = poseset[7];
    v16 = poseset[8];
    v15 = poseset[9];
    {
LABEL_21:
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
          goto LABEL_51;
        if (v24.y > 100.0)
          goto LABEL_33;
        goto LABEL_48;
      case 2:
      case 0xA:
      case 0xB:
      case 0xC:
      case 0xD:
        goto LABEL_51;
      case 3:
      case 4:
      case 7:
      case 0xE:
        if (v24.y < -200.0)
          goto LABEL_51;
        if (v24.y > 100.0)
LABEL_33:
          v22 = 256;
        else
LABEL_50:
          v22 = 257;
        break;
      case 5:
      case 6:
      case 9:
      case 0x10:
      case 0x15:
        goto LABEL_33;
      case 8:
        if (v24.x < -1000.0)
          goto LABEL_50;
LABEL_51:
        v22 = 259;
        break;
      default:
LABEL_48:
        v22 = 258;
        break;
    }
  }
  *encpid = v22;
}

// 0x15f8910
bool fldDispOn(void) {
  s32 loadField;
  System_Text_StringBuilder_o *m_head;
  bool IsDLCField;
  s64 *v8;
  System_Text_StringBuilder_o *m_akey2;
  u64 *v12;
  System_Text_StringBuilder_o *v14;
  System_String_o *v15;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v20;
  AssetBundleCtrl_o *v23;
  System_String_o *v25;
  System_String_o *v26;
  AssetBundleCtrl_o *v29;
  System_String_o *v31;
  System_String_o *v34;
  System_String_o *v35;
  System_String_o *v37;
  AssetBundleCtrl_o *v39;
  System_String_o *v41;
  AssetBundleCtrl_o *v47;
  System_String_o *v49;
  s32 v52;

  loadField = fldSceneParam.loadField;
  Clear(m_akey1, 0);
  Append_5380272(m_akey1, "fldplayer");
  Clear(m_head, 0);
  IsDLCField = IsDLCField(loadField);
  v8 = &"m";
  if (!IsDLCField)
    v8 = &"";
  Append_5380272(m_head, *v8);
  Clear(m_akey2, 0);
  v52 = loadField;
  v12 = sub_8D3950(s32, &v52);
  AppendFormat(m_akey2, "f{0:D3}", v12);
  v14 = m_akey2;
  v15 = (m_head->klass->vtable._3_ToString.methodPtr)(
          m_head,
          m_head->klass->vtable._3_ToString.method);
  Append_5380272(v14, v15);
  switch (fldInitCnt)
  {
    case 0:
      asset_bc = get_asset_bc();
      v20 = (m_akey1->klass->vtable._3_ToString.methodPtr)(
              m_akey1,
              m_akey1->klass->vtable._3_ToString.method);
      if (IsLoad(asset_bc, v20))
        goto LABEL_70;
      v23 = get_asset_bc();
      v25 = (m_akey1->klass->vtable._3_ToString.methodPtr)(
              m_akey1,
              m_akey1->klass->vtable._3_ToString.method);
      v26 = (m_akey1->klass->vtable._3_ToString.methodPtr)(
              m_akey1,
              m_akey1->klass->vtable._3_ToString.method);
      Load(v23, v25, v26, 0);
        goto LABEL_71;
      goto LABEL_32;
    case 1:
      v29 = get_asset_bc();
      v31 = (m_akey1->klass->vtable._3_ToString.methodPtr)(
              m_akey1,
              m_akey1->klass->vtable._3_ToString.method);
      if (!IsLoad(v29, v31))
        return 0;
      v34 = (m_akey2->klass->vtable._3_ToString.methodPtr)(
              m_akey2,
              m_akey2->klass->vtable._3_ToString.method);
      v35 = (m_akey2->klass->vtable._3_ToString.methodPtr)(
              m_akey2,
              m_akey2->klass->vtable._3_ToString.method);
      v37 = (m_head->klass->vtable._3_ToString.methodPtr)(
              m_head,
              m_head->klass->vtable._3_ToString.method);
      LoadAssetExt(v34, v35, v37);
      goto LABEL_48;
    case 2:
      v39 = get_asset_bc();
      v41 = (m_akey2->klass->vtable._3_ToString.methodPtr)(
              m_akey2,
              m_akey2->klass->vtable._3_ToString.method);
      if (!IsLoad(v39, v41))
        return 0;
      FldDispOn(kernelObject);
      ++fldInitCnt;
      ++fldInitCnt;
      return 1;
    case 3:
      v47 = get_asset_bc();
      v49 = (m_akey2->klass->vtable._3_ToString.methodPtr)(
              m_akey2,
              m_akey2->klass->vtable._3_ToString.method);
      if (!IsLoad(v47, v49))
        return 0;
LABEL_70:
        goto LABEL_71;
LABEL_32:
LABEL_71:
      ++fldInitCnt;
      return 0;
    case 4:
      FldDispOn(kernelObject);
      return 1;
    default:
      return 0;
  }
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
  return scrSearchScriptName("hirakenai_label") != 0;
}

// 0x15f4900
s32 fldProcKiretaChk(void) {
  return scrSearchScriptName("kireta_label") != 0;
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
  s32 fldNext_fld;

  if (!fldNext_fld)
    return 1;
LABEL_6:
  if (dds3AdminiGetNextSequence() > 0
    || dds3AdminiGetNextSequence() < 0
    && (dds3AdminiGetPrevHistoryFlag() & 1) != 0)
  {
    return 1;
  }
  else if (fldCheckNextFile(fldNext_fld))
  {
    goto LABEL_16;
  }
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
  fldProcess_c *v5;
  char v7;
  char v8;

  else
  {
    if (!fldProcShutDownFlg)
      return;
  }
  fldProcShutDownFlg = 0;
  fldSnowFree();
  else
  {
    fldProcessFlag &= ~0x10u;
  }
  if ((v5->_2.bitflags2 & 2) == 0)
  {
LABEL_19:
    fldProcessFlag &= ~0x20u;
    goto LABEL_20;
  }
LABEL_18:
    goto LABEL_19;
  v7 = byte_3F5A16D;
  fldProcessFlag &= ~0x20u;
  if ((v7 & 1) != 0)
  {
LABEL_20:
    if ((v5->_2.bitflags2 & 2) != 0)
      goto LABEL_21;
    goto LABEL_30;
  }
  {
LABEL_21:
  }
LABEL_30:
  fldProcessFlag &= ~0x80u;
  else
  {
    v8 = 1;
  }
  fldSequenceControl->flag |= 1u;
  fldSequenceControl->flag |= 2u;
  dds3KillProcessName("fldProcSequence", 1);
  dds3KillProcessName("fldProcDraw", 1);
  SetEnemyUI(kernelObject, 0, 0, 0, 0, 0, 0, 0.0, 0.0);
  SetRadarUI(kernelObject, 0, 0, 0, 0);
  fldFreeInputPanel();
  evtDisableMoonDraw();
  fldFreeAddressProcess();
  if (fldBlurKabuki)
  {
    dds3EffectDistortionBlurDelete(&fldBlurKabuki);
    fldBlurKabuki = 0;
  }
  else
  {
    scrAllReleaseScript();
  }
}

// 0x16014d0
s8 fldProcShutDown2(void) {
LABEL_10:
  sdfDelayedResrcCheck();
  return 1;
}

// 0x15f28a0
s32 fldProcStartScript(void) {
  s32 mode;
  struct System_Char_array *FoceScript;
  struct System_Char_array *gFldWap_after_scr;
  System_String_o *String_5280336;
  System_String_o *v15;
  System_String_o *startPro;
  dds3Basic_t_o **p_ControlScene;
  dds3Basic_t_o *v27;
  dds3Basic_t_o *ControlScene;
  dds3Basic_t_o *scene;

  ControlScene = 0;
  scene = 0;
  v27 = 0;
  mode = fldSceneParam.mode;
  FoceScript = fldSceneParam.FoceScript;
  else
  {
    if ((gFldWap_after_flag & 2) == 0)
      goto LABEL_35;
  }
  if (!LODWORD(gFldWap_after_scr->max_length))
    goto LABEL_17;
LABEL_12:
  if (gFldWap_after_scr->m_Items[0])
  {
    scene = dds3GetControlScene();
    fldPlayerEventStop(0);
    String_5280336 = CreateString_5280336(0, gFldWap_after_scr);
    v15 = Replace_5267216(String_5280336, " ", "");
    dds3SceneBasicStartScript(&scene, v15);
    if ((gFldWap_after_flag & 1) == 0)
    {
      Clear(gFldWap_after_scr, 0, 15, 0);
      gFldWap_after_flag &= 0xFDu;
    }
    return 1;
  }
LABEL_35:
  if (!mode)
  {
    if (FoceScript->m_Items[0])
    {
      ControlScene = dds3GetControlScene();
      fldPlayerEventStop(0);
      startPro = CreateString_5280336(0, FoceScript);
      p_ControlScene = &ControlScene;
      goto LABEL_65;
    }
  }
  if (!fldGb->startPro)
    return 0;
LABEL_39:
  v27 = dds3GetControlScene();
  fldPlayerEventStop(0);
  startPro = fldGb->startPro;
  p_ControlScene = &v27;
LABEL_65:
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
      goto LABEL_17;
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
LABEL_17:
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_fldProcess_ProcSequence__);
  dds3StartProcess("fldProcSequence", 0x3F7u, 0, 0, v8, 0, 0, 0, 0, 0);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_fldProcess_ProcDraw__);
  dds3StartProcess("fldProcDraw", 0x2B0Au, 0, 0, v10, 0, 0, 0, 0, 0);
  fldProcShutDownFlg = 1;
  InitOoyTest();
}

// 0x1601740
bool fldProc_CallSisetuReturn(void) {
  u64 v2;

  if (!fldNext_fld)
    goto LABEL_11;
LABEL_6:
  return fldProcNextJump(v2) != 0;
}

// 0x1601650
void fldProc_SisetuReturnPoint(s32 fld, s32 area, u16 **pName) {
  s32 fldSeLastBgm;

LABEL_7:
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
