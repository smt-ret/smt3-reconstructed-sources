#include "types.h"

typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3MoverBasicObjFunc_t dds3MoverBasicObjFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldFollowCameraControl_t fldFollowCameraControl_t;
typedef struct scrProcessWork_s scrProcessWork_s;

static s32 fld_itembox_kakuritu_tbl[9];

s32 GetMotionMinorNum(void);
bool IsBGMFadeOut(void);
void MakeWarpIndex_21489856(s32 cammode, char *camname);
f32 OOYRAD(f32 a);
char *StrStr(char *stringToSearch, char *stringToFind);
void dds3CameraObjectBasicGetTgtCam(dds3Basic_t **pBasic, sdfVector4_t *tgtpos, sdfVector4_t *campos);
void dds3EffectDistortionBlur_SetFldEventCntF(f32 feve_UnityEx_cntF);
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic);
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3GetBasicArrayCount(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetControlScene(void);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void dds3MatterObjectBasicSetAlpMode(dds3Basic_t **aPtr, s32 alpmode);
void dds3ObjectBaseMatterAnimeSpeed(dds3Basic_t **pObjectBasic, s32 mode);
s32 dds3ObjectBaseSetPrimaryControl(dds3Basic_t **basic, dds3MoverBasicObjFunc_t *func);
dds3BasicArrayHandle_t *dds3SceneBasicGetList(dds3Basic_t **pBasic, u32 type);
dds3Basic_t *dds3SceneBasicSearchName(dds3Basic_t **scene, char *name);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
s32 dds3SetFirstBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void evtDisableMoonDraw(void);
void evtDisableMoonDraw2(void);
void evtEnableMoonDraw(void);
void evtEnableMoonDraw2(void);
s32 evtGetAgeOfMoon(void);
evtUnitHandle_t *evtGetUnitHandle(s32 serial);
void evtUpdateEx_FLD_MSE_After(s32 seid);
void fldAnahoriSelectDel(void);
s32 fldAnahoriSelectGet(void);
void fldAnahoriSelectInit(void);
void fldAnahoriSelectNext(void);
void fldAutoMapCloseBlock2(s32 fld, s32 area, s32 SBlock);
void fldAutoMapOpenBlock2(s32 fld, s32 area, s32 SBlock);
void fldBgmContinue(void);
void fldBgmFadeOut(void);
void fldBgmLoad(void);
s32 fldBgmLoadChk(void);
void fldBgmPause(void);
void fldBgmPlay(void);
void fldBgmStop(void);
s32 fldCommand_GetHojiID(char **pName);
s32 fldCommand_SEARCH_ID(char **pName);
void fldDoorRun_FindStart(s32 resid);
s32 fldDoor_ChkWarp(void);
void fldDoor_ElvExit(s32 select);
void fldDoor_ExitCamera(char **evename);
s32 fldDoor_GetElvTbl(s32 getmode);
s32 fldDoor_GetHasigoTbl(s32 getmode);
s32 fldDoor_GetWarpEff(void);
void fldDoor_Warp(char **evename);
void fldDoor_WarpCash(char **evename);
void fldDoor_WarpEx(s32 ex_no);
void fldElvFloorEnd(void);
s32 fldElvFloorEndChk(void);
void fldElvFloorStart(s32 from, s32 to);
s32 fldEveHitResID_Find(dds3ProcessID_t *pid);
char *fldEveHitResName_Find(dds3ProcessID_t *pid);
s32 fldEveHitTakaraIdx_Find(dds3ProcessID_t *pid);
s32 fldEveHit_ChkDir(dds3Basic_t *unit, dds3Basic_t *put);
s32 fldEveHit_ChkDir2(dds3Basic_t *unit, dds3Basic_t *put);
void fldFreeNextFile(void);
s32 fldGbChkTakaraOpen(s32 idx);
void fldGbSetAnime(s32 fld, s32 area, s32 blk, s32 onoff);
void fldGbSetEAnime(s32 fld, s32 area, s32 grp, s32 onoff);
void fldGbSetEAnimeCngID(s32 fld, s32 area, s32 grp, s32 animeid);
void fldGbSetEView(s32 fld, s32 area, s32 grp, s32 onoff);
void fldGbSetGimic(s32 fld, s32 area, s32 hojiID, s32 toplast);
void fldGbSetHit(s32 fld, s32 area, s32 blk, s32 onoff);
void fldGbSetNpc(s32 fld, s32 area, s32 hojiID, s32 onoff);
void fldGbSetTakaraOpen(s32 idx);
void fldGbSetView(s32 fld, s32 area, s32 blk, s32 onoff);
fldFollowCameraControl_t *fldGetFollowCameraControl(void);
s32 fldGetRestoreMode(void);
dds3Basic_t *fldGetUnitFollowCamera(void);
s32 fldInfChkFastPanel(s32 aline);
s32 fldInfGet(s32 aline, s32 acol);
s32 fldInfNext(s32 aline, s32 asel);
void fldInfToWAP(void);
s32 fldInputPanelCheckKey(void);
void fldInputPanelSetDraw(s32 flag);
void fldInputPanelSetMessage(s32 no);
s32 fldLoadNextFile(s32 field, s32 area);
void fldMotionSePlay(s32 seid, s32 subid);
void fldMotionSeStop(s32 seid, s32 subid);
void fldNpcHojiRefresh(void);
void fldNpcLightSet(evtUnitHandle_t *hEveUnit);
s32 fldPlayerFastSet(void);
void fldPlayerMotReset(void);
void fldProcOffFlag(u32 flag);
void fldProcOnFlag(u32 flag);
void fldRegistUnitPad(void);
void fldReleaseUnitPad(void);
void fldRunDanteStanceSet(s32 id, bool recover);
void fldSePlay(s32 seid);
void fldSeStop(s32 seid);
void fldSkySetFilter(s32 idx, s32 mode, s32 hokan);
void fldSkySetFilterAnime(s32 type);
void fldSkySetTbl(s32 idx, s32 hokan);
void fldTitleStart(s32 fld, s32 waittime);
s32 fldWapGetDoor(s32 getmode);
void hokanCamStart(void);
void resetCamNormal(void);
void resetCamTgtPlayer(void);
void resetCamWM_Sub(f32 hokan);
s32 scrGetIntPara(s32 n);
scrProcessWork_s *scrGetScriptHandle(void);
char *scrGetStrPara(s32 n);
void scrSetIntReturnValue(s32 i);
f32 sdfCos(f32 aRadius);
f32 sdfSin(f32 aRadius);

// 0x102dca0
s32 fldCommand_ACT_WIN_DSP(void) {
  u64 *v1;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *ActiveUnitSceneBasic;
  dds3ProcessID_t_o *ProcessID;
  s32 v11;
  dds3Basic_t_o *v12;
  dds3Basic_t_o *v14;
  s32 IntPara;
  s32 v18;
  s32 v19;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  ActiveScene = dds3GetActiveScene();
  pBasic = ActiveScene;
  ActiveUnitSceneBasic = dds3GetActiveUnitSceneBasic(ActiveScene);
  if (!ActiveUnitSceneBasic)
  {
    {
LABEL_41:
    }
LABEL_44:
    v19 = 0;
    goto LABEL_45;
  }
  ProcessID = scrGetScriptHandle()->ProcessID;
  v11 = fldEveHitResID_Find(ProcessID);
  v12 = dds3SearchSceneBasic(&pBasic, v11, 0x11u);
  if (!v12)
    goto LABEL_40;
  v14 = v12;
  if (fldGb->fieldID >= 11)
  {
    if (!fldEveHit_ChkDir(ActiveUnitSceneBasic, v14))
    {
LABEL_40:
        goto LABEL_41;
      goto LABEL_44;
    }
  }
  IntPara = scrGetIntPara(0);
  fldInputPanelSetMessage(IntPara);
  fldInputPanelSetDraw(1);
  v18 = fldInputPanelCheckKey();
  if (v18 != -1)
  {
    if (v18 == 1)
    {
      v19 = 1;
      goto LABEL_45;
    }
    goto LABEL_40;
  }
  v19 = -1;
LABEL_45:
  scrSetIntReturnValue(v19);
  return 1;
}

// 0x102e7b0
s32 fldCommand_ACT_WIN_DSP2(void) {
  u64 *v1;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *ActiveUnitSceneBasic;
  dds3ProcessID_t_o *ProcessID;
  s32 v11;
  dds3Basic_t_o *v12;
  dds3Basic_t_o *v14;
  s32 IntPara;
  s32 v18;
  s32 v19;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  ActiveScene = dds3GetActiveScene();
  pBasic = ActiveScene;
  ActiveUnitSceneBasic = dds3GetActiveUnitSceneBasic(ActiveScene);
  if (!ActiveUnitSceneBasic)
  {
    {
LABEL_41:
    }
LABEL_44:
    v19 = 0;
    goto LABEL_45;
  }
  ProcessID = scrGetScriptHandle()->ProcessID;
  v11 = fldEveHitResID_Find(ProcessID);
  v12 = dds3SearchSceneBasic(&pBasic, v11, 0x11u);
  if (!v12)
    goto LABEL_40;
  v14 = v12;
  if (fldGb->fieldID >= 11)
  {
    if (!fldEveHit_ChkDir2(ActiveUnitSceneBasic, v14))
    {
LABEL_40:
        goto LABEL_41;
      goto LABEL_44;
    }
  }
  IntPara = scrGetIntPara(0);
  fldInputPanelSetMessage(IntPara);
  fldInputPanelSetDraw(1);
  v18 = fldInputPanelCheckKey();
  if (v18 != -1)
  {
    if (v18 == 1)
    {
      v19 = 1;
      goto LABEL_45;
    }
    goto LABEL_40;
  }
  v19 = -1;
LABEL_45:
  scrSetIntReturnValue(v19);
  return 1;
}

// 0x102f070
s32 fldCommand_ACT_WIN_DSP3(void) {
  s32 IntPara;
  s32 v4;
  s32 v6;

  IntPara = scrGetIntPara(0);
  fldInputPanelSetMessage(IntPara);
  fldInputPanelSetDraw(1);
  v4 = fldInputPanelCheckKey();
  if (v4 == -1)
  {
    v6 = -1;
  }
  else if (v4 == 1)
  {
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  scrSetIntReturnValue(v6);
  return 1;
}

// 0x102fea0
s32 fldCommand_CAM_DIR(void) {
  f32 v5;
  struct fldGlobalWork_t_o *fldGb;
  f32 PlayerKakudo;
  f32 v10;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  u64 v19[2];
  u64 v20[2];

  v20[0] = 0;
  v20[1] = 0;
  v19[0] = 0;
  v19[1] = 0;
  else if ((scrGetIntPara(0) & 0x80000000) == 0)
  {
    goto LABEL_6;
  }
  PlayerKakudo = fldGb->PlayerKakudo;
  v5 = -PlayerKakudo;
LABEL_21:
  ooyCamKakudo = v5;
  v10 = fldGb->PlayerKakudo;
  v12 = OOYRAD(v10 + 180.0);
  sdfSin(v12);
  sub_854930(v20, 0);
  sub_854930(v20, 1u);
  v13 = OOYRAD(fldGb->PlayerKakudo + 180.0);
  sdfCos(v13);
  sub_854930(v20, 2u);
  v14 = OOYRAD(ooyCamKakudo);
  sdfSin(v14);
  sub_854930(v19, 0);
  sub_854930(v19, 1u);
  v15 = OOYRAD(ooyCamKakudo);
  sdfCos(v15);
  sub_854930(v19, 2u);
  sub_854710(v20, 0);
  sub_854930(&g_targetPos, 0);
  sub_854710(v20, 1u);
  sub_854930(&g_targetPos, 1u);
  sub_854710(v20, 2u);
  sub_854930(&g_targetPos, 2u);
  sub_854710(v19, 0);
  sub_854930(&g_cameraPos, 0);
  sub_854710(v19, 1u);
  sub_854930(&g_cameraPos, 1u);
  sub_854710(v19, 2u);
  sub_854930(&g_cameraPos, 2u);
  resetCamNormal();
  return 1;
}

// 0x1030310
s32 fldCommand_CAM_SEL_PHOKAN(void) {
  s32 IntPara;
  dds3Basic_t_o *ActiveScene;
  UnityEngine_Vector4_o campos;
  UnityEngine_Vector4_o tgtpos;
  dds3Basic_t_o *pCameraBasic;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  *&tgtpos.z = 0;
  pCameraBasic = 0;
  ActiveScene = 0;
  *&tgtpos.x = 0;
  *&campos.x = 0;
  *&campos.z = 0;
  if (scrGetIntPara(0) == -1)
  {
    pCameraBasic = fldGetUnitFollowCamera();
    if (pCameraBasic)
    {
      ActiveScene = dds3GetActiveScene();
      pBasic = dds3SetActiveCameraSceneBasic(&ActiveScene, &pCameraBasic);
      if (pBasic)
      {
        dds3CameraObjectBasicGetTgtCam(&pBasic, &tgtpos, &campos);
        hokanCamStart();
        sub_854710(&tgtpos, 0);
        sub_854930(&hs_targetPos, 0);
        sub_854710(&tgtpos, 1u);
        sub_854930(&hs_targetPos, 1u);
        sub_854710(&tgtpos, 2u);
        sub_854930(&hs_targetPos, 2u);
        sub_854710(&campos, 0);
        sub_854930(&hs_cameraPos, 0);
        sub_854710(&campos, 1u);
        sub_854930(&hs_cameraPos, 1u);
        sub_854710(&campos, 2u);
        sub_854930(&hs_cameraPos, 2u);
        hokanCamCount = 0;
        hokanCamTimeM = scrGetIntPara(1);
        fldGb->cammode = 4;
      }
    }
  }
  else
  {
    ActiveScene = dds3GetActiveScene();
    IntPara = scrGetIntPara(0);
    pCameraBasic = dds3SearchSceneBasic(&ActiveScene, IntPara, 4u);
    if (pCameraBasic)
    {
      ActiveScene = dds3GetActiveScene();
      dds3SetActiveCameraSceneBasic(&ActiveScene, &pCameraBasic);
    }
  }
  return 1;
}

// 0x102f1a0
s32 fldCommand_DIR_HIT_CNTR(void) {
  u64 *v1;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *ActiveUnitSceneBasic;
  dds3ProcessID_t_o *ProcessID;
  s32 v11;
  dds3Basic_t_o *v12;
  dds3Basic_t_o *v14;
  s32 v15;
  s32 v16;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  if (fldGb->fieldID > 9)
  {
    ActiveScene = dds3GetActiveScene();
    pBasic = ActiveScene;
    ActiveUnitSceneBasic = dds3GetActiveUnitSceneBasic(ActiveScene);
    if (ActiveUnitSceneBasic)
    {
      ProcessID = scrGetScriptHandle()->ProcessID;
      v11 = fldEveHitResID_Find(ProcessID);
      v12 = dds3SearchSceneBasic(&pBasic, v11, 0x11u);
      if (v12)
      {
        v14 = v12;
        v15 = fldEveHit_ChkDir(ActiveUnitSceneBasic, v14);
        if (v15)
        {
            goto LABEL_29;
          goto LABEL_32;
        }
        {
LABEL_39:
          v16 = 0;
          goto LABEL_40;
        }
      }
      else
      {
          goto LABEL_39;
      }
    }
    {
      goto LABEL_39;
    }
    goto LABEL_39;
  }
  {
LABEL_29:
  }
LABEL_32:
  v16 = 1;
LABEL_40:
  scrSetIntReturnValue(v16);
  return 1;
}

// 0x102f640
s32 fldCommand_ENCOUNT_OFF(void) {
  fldProcOffFlag(0x10u);
  return 1;
}

// 0x102f5d0
s32 fldCommand_ENCOUNT_ON(void) {
  fldProcOnFlag(0x10u);
  return 1;
}

// 0x1037e50
s32 fldCommand_FLD_ANAHORI_DEL(void) {
  fldAnahoriSelectDel();
  return 1;
}

// 0x1037d40
s32 fldCommand_FLD_ANAHORI_GET(void) {
  s32 v3;

  v3 = fldAnahoriSelectGet();
  scrSetIntReturnValue(v3);
  return 1;
}

// 0x1037cd0
s32 fldCommand_FLD_ANAHORI_INIT(void) {
  fldAnahoriSelectInit();
  return 1;
}

// 0x1037de0
s32 fldCommand_FLD_ANAHORI_NEXT(void) {
  fldAnahoriSelectNext();
  return 1;
}

// 0x1033f90
s32 fldCommand_FLD_ANIME_ID2(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;
  s32 v14;

  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_23;
  }
  else
  {
    v7 = fldGb->areaID + 1;
    {
LABEL_23:
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
      goto LABEL_24;
    }
  }
    goto LABEL_23;
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
LABEL_24:
  v12 = v9;
  v14 = scrGetIntPara(3);
  fldGbSetEAnimeCngID(IntPara, v7, v12, v14);
  return 1;
}

// 0x1032960
s32 fldCommand_FLD_ANIME_OFF(void) {
  s32 IntPara;
  s32 v7;
  s32 HojiID;
  s32 v13;
  s32 v14;
  s32 v15;
  struct fldGlobalWork_t_o *fldGb;
  s32 v34;
  u32 v36;
  s32 v39;
  s32 v40;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *pObjectBasic;
  System_String_o *pName;

  pObjectBasic = 0;
  pName = 0;
  pBasic = 0;
  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_22;
    goto LABEL_16;
  }
  v7 = fldGb->areaID + 1;
  {
LABEL_16:
  }
LABEL_22:
  pName = scrGetStrPara(2);
  if (pName)
  {
    HojiID = fldCommand_GetHojiID(&pName);
    v13 = IntPara;
    v14 = v7;
    v15 = HojiID;
  }
  else
  {
    fldGbSetAnime(IntPara, v7, 0, 1);
    fldGbSetAnime(IntPara, v7, 1, 1);
    fldGbSetAnime(IntPara, v7, 2, 1);
    fldGbSetAnime(IntPara, v7, 3, 1);
    fldGbSetAnime(IntPara, v7, 4, 1);
    fldGbSetAnime(IntPara, v7, 5, 1);
    fldGbSetAnime(IntPara, v7, 6, 1);
    fldGbSetAnime(IntPara, v7, 7, 1);
    fldGbSetAnime(IntPara, v7, 8, 1);
    fldGbSetAnime(IntPara, v7, 9, 1);
    fldGbSetAnime(IntPara, v7, 10, 1);
    fldGbSetAnime(IntPara, v7, 11, 1);
    fldGbSetAnime(IntPara, v7, 12, 1);
    fldGbSetAnime(IntPara, v7, 13, 1);
    fldGbSetAnime(IntPara, v7, 14, 1);
    v13 = IntPara;
    v14 = v7;
    v15 = 15;
  }
  fldGbSetAnime(v13, v14, v15, 1);
  if (IntPara == fldGb->fieldID)
  {
    if (v7 == fldGb->areaID + 1)
    {
      v34 = fldCommand_SEARCH_ID(&pName);
      if (v34 != -1)
      {
        v36 = v34;
        pBasic = dds3GetControlScene();
        pObjectBasic = dds3SearchSceneBasic(&pBasic, v36, 6u);
        v39 = scrGetIntPara(3);
        switch (v39)
        {
          case 2:
            v40 = 5;
            goto LABEL_106;
          case 1:
            v40 = 4;
            goto LABEL_106;
          case 0:
            v40 = 3;
LABEL_106:
            dds3ObjectBaseMatterAnimeSpeed(&pObjectBasic, v40);
            break;
        }
      }
    }
  }
  return 1;
}

// 0x1033df0
s32 fldCommand_FLD_ANIME_OFF2(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;

  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_23;
  }
  else
  {
    v7 = fldGb->areaID + 1;
    {
LABEL_23:
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
      goto LABEL_24;
    }
  }
    goto LABEL_23;
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
LABEL_24:
  v12 = v9;
  fldGbSetEAnime(IntPara, v7, v12, 1);
  return 1;
}

// 0x1032300
s32 fldCommand_FLD_ANIME_ON(void) {
  s32 IntPara;
  s32 v7;
  s32 HojiID;
  s32 v13;
  s32 v14;
  s32 v15;
  struct fldGlobalWork_t_o *fldGb;
  s32 v34;
  u32 v36;
  s32 v39;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *pObjectBasic;
  System_String_o *pName;

  pObjectBasic = 0;
  pName = 0;
  pBasic = 0;
  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_22;
    goto LABEL_16;
  }
  v7 = fldGb->areaID + 1;
  {
LABEL_16:
  }
LABEL_22:
  pName = scrGetStrPara(2);
  if (pName)
  {
    HojiID = fldCommand_GetHojiID(&pName);
    v13 = IntPara;
    v14 = v7;
    v15 = HojiID;
  }
  else
  {
    fldGbSetAnime(IntPara, v7, 0, 0);
    fldGbSetAnime(IntPara, v7, 1, 0);
    fldGbSetAnime(IntPara, v7, 2, 0);
    fldGbSetAnime(IntPara, v7, 3, 0);
    fldGbSetAnime(IntPara, v7, 4, 0);
    fldGbSetAnime(IntPara, v7, 5, 0);
    fldGbSetAnime(IntPara, v7, 6, 0);
    fldGbSetAnime(IntPara, v7, 7, 0);
    fldGbSetAnime(IntPara, v7, 8, 0);
    fldGbSetAnime(IntPara, v7, 9, 0);
    fldGbSetAnime(IntPara, v7, 10, 0);
    fldGbSetAnime(IntPara, v7, 11, 0);
    fldGbSetAnime(IntPara, v7, 12, 0);
    fldGbSetAnime(IntPara, v7, 13, 0);
    fldGbSetAnime(IntPara, v7, 14, 0);
    v13 = IntPara;
    v14 = v7;
    v15 = 15;
  }
  fldGbSetAnime(v13, v14, v15, 0);
  if (IntPara == fldGb->fieldID)
  {
    if (v7 == fldGb->areaID + 1)
    {
      v34 = fldCommand_SEARCH_ID(&pName);
      if (v34 != -1)
      {
        v36 = v34;
        pBasic = dds3GetControlScene();
        pObjectBasic = dds3SearchSceneBasic(&pBasic, v36, 6u);
        switch (scrGetIntPara(3))
        {
          case 0:
            v39 = 0;
            goto LABEL_106;
          case 1:
            v39 = 1;
            goto LABEL_106;
          case 2:
            v39 = 2;
            goto LABEL_106;
          case 3:
            v39 = 6;
            goto LABEL_106;
          case 4:
            v39 = 7;
LABEL_106:
            dds3ObjectBaseMatterAnimeSpeed(&pObjectBasic, v39);
            break;
          default:
            return 1;
        }
      }
    }
  }
  return 1;
}

// 0x1033c50
s32 fldCommand_FLD_ANIME_ON2(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;

  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_23;
  }
  else
  {
    v7 = fldGb->areaID + 1;
    {
LABEL_23:
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
      goto LABEL_24;
    }
  }
    goto LABEL_23;
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
LABEL_24:
  v12 = v9;
  fldGbSetEAnime(IntPara, v7, v12, 0);
  return 1;
}

// 0x1033450
s32 fldCommand_FLD_ATARI_OFF(void) {
  s32 IntPara;
  s32 v7;
  s32 HojiID;
  s32 v13;
  s32 v14;
  s32 v15;
  System_String_o *pName;

  pName = 0;
  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_22;
    goto LABEL_16;
  }
  v7 = fldGb->areaID + 1;
  {
LABEL_16:
  }
LABEL_22:
  pName = scrGetStrPara(2);
  if (pName)
  {
    HojiID = fldCommand_GetHojiID(&pName);
    v13 = IntPara;
    v14 = v7;
    v15 = HojiID;
  }
  else
  {
    fldGbSetHit(IntPara, v7, 0, 1);
    fldGbSetHit(IntPara, v7, 1, 1);
    fldGbSetHit(IntPara, v7, 2, 1);
    fldGbSetHit(IntPara, v7, 3, 1);
    fldGbSetHit(IntPara, v7, 4, 1);
    fldGbSetHit(IntPara, v7, 5, 1);
    fldGbSetHit(IntPara, v7, 6, 1);
    fldGbSetHit(IntPara, v7, 7, 1);
    fldGbSetHit(IntPara, v7, 8, 1);
    fldGbSetHit(IntPara, v7, 9, 1);
    fldGbSetHit(IntPara, v7, 10, 1);
    fldGbSetHit(IntPara, v7, 11, 1);
    fldGbSetHit(IntPara, v7, 12, 1);
    fldGbSetHit(IntPara, v7, 13, 1);
    fldGbSetHit(IntPara, v7, 14, 1);
    v13 = IntPara;
    v14 = v7;
    v15 = 15;
  }
  fldGbSetHit(v13, v14, v15, 1);
  return 1;
}

// 0x1032f90
s32 fldCommand_FLD_ATARI_ON(void) {
  s32 IntPara;
  s32 v7;
  s32 HojiID;
  s32 v13;
  s32 v14;
  s32 v15;
  System_String_o *pName;

  pName = 0;
  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_22;
    goto LABEL_16;
  }
  v7 = fldGb->areaID + 1;
  {
LABEL_16:
  }
LABEL_22:
  pName = scrGetStrPara(2);
  if (pName)
  {
    HojiID = fldCommand_GetHojiID(&pName);
    v13 = IntPara;
    v14 = v7;
    v15 = HojiID;
  }
  else
  {
    fldGbSetHit(IntPara, v7, 0, 0);
    fldGbSetHit(IntPara, v7, 1, 0);
    fldGbSetHit(IntPara, v7, 2, 0);
    fldGbSetHit(IntPara, v7, 3, 0);
    fldGbSetHit(IntPara, v7, 4, 0);
    fldGbSetHit(IntPara, v7, 5, 0);
    fldGbSetHit(IntPara, v7, 6, 0);
    fldGbSetHit(IntPara, v7, 7, 0);
    fldGbSetHit(IntPara, v7, 8, 0);
    fldGbSetHit(IntPara, v7, 9, 0);
    fldGbSetHit(IntPara, v7, 10, 0);
    fldGbSetHit(IntPara, v7, 11, 0);
    fldGbSetHit(IntPara, v7, 12, 0);
    fldGbSetHit(IntPara, v7, 13, 0);
    fldGbSetHit(IntPara, v7, 14, 0);
    v13 = IntPara;
    v14 = v7;
    v15 = 15;
  }
  fldGbSetHit(v13, v14, v15, 0);
  return 1;
}

// 0x1036f80
s32 fldCommand_FLD_BGM_CONTINUE(void) {
  struct fldGlobalWork_t_o *fldGb;

  fldGb->BgmId = scrGetIntPara(0);
  fldBgmContinue();
  return 1;
}

// 0x1037130
s32 fldCommand_FLD_BGM_FADE(void) {
  fldBgmFadeOut();
  return 1;
}

// 0x1037050
s32 fldCommand_FLD_BGM_PAUSE(void) {
  fldBgmPause();
  return 1;
}

// 0x1036e50
s32 fldCommand_FLD_BGM_PLAY(void) {
  struct fldGlobalWork_t_o *fldGb;
  u64 *v5;
  s32 BgmId;

  fldGb->BgmId = scrGetIntPara(0);
  BgmId = fldGb->BgmId;
  v5 = sub_8D3950(s32, &BgmId);
  Write_2930400("FLD_BGM_PLAY:{0:D}\n", v5);
  fldBgmPlay();
  return 1;
}

// 0x1036d70
s32 fldCommand_FLD_BGM_RELOAD(void) {
  fldBgmLoad();
  return 1;
}

// 0x1036de0
s32 fldCommand_FLD_BGM_RELOAD_WAIT(void) {
  return fldBgmLoadChk() == 1;
}

// 0x10370c0
s32 fldCommand_FLD_BGM_STOP(void) {
  fldBgmStop();
  return 1;
}

// 0x1036290
s32 fldCommand_FLD_CALL_WAPEX(void) {
  s32 IntPara;

  Write("FLD_CALL_WAPEX\n", 0);
  IntPara = scrGetIntPara(0);
  fldDoor_WarpEx(IntPara);
  return 1;
}

// 0x10355b0
s32 fldCommand_FLD_CHK_ANA(void) {
  s32 v3;

  if (fldGetRestoreMode() == 3)
  {
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  scrSetIntReturnValue(v3);
  return 1;
}

// 0x10354f0
s32 fldCommand_FLD_CHK_BTL(void) {
  s32 v3;

  if (fldGetRestoreMode() == 1)
  {
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  scrSetIntReturnValue(v3);
  return 1;
}

// 0x1035730
s32 fldCommand_FLD_CHK_EVE(void) {
  s32 v3;

  if (fldGetRestoreMode() == 2)
  {
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  scrSetIntReturnValue(v3);
  return 1;
}

// 0x1035670
s32 fldCommand_FLD_CHK_SISETU(void) {
  s32 v3;

  if (fldGetRestoreMode() == 4)
  {
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  scrSetIntReturnValue(v3);
  return 1;
}

// 0x1035e30
s32 fldCommand_FLD_CHK_TAKARA_OPEN(void) {
  u64 *v1;
  dds3ProcessID_t_o *ProcessID;
  s32 v6;
  s32 v8;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  ProcessID = scrGetScriptHandle()->ProcessID;
  v6 = fldEveHitTakaraIdx_Find(ProcessID);
  if (fldGbChkTakaraOpen(v6) == 1)
  {
    v8 = 1;
  }
  else
  {
    v8 = 0;
  }
  scrSetIntReturnValue(v8);
  return 1;
}

// 0x1038560
s32 fldCommand_FLD_DANTE_AI_START(void) {
  else if (bFirstStance)
  {
    return 1;
  }
  evtBitOn(2804);
  return 1;
}

// 0x10384c0
s32 fldCommand_FLD_DANTE_AI_STOP(void) {
  else if (bFirstStance)
  {
    return 1;
  }
  evtBitOff(2804);
  return 1;
}

// 0x1038600
s32 fldCommand_FLD_DANTE_STANCE(void) {
  s32 IntPara;

  else if (bFirstStance)
  {
    return 1;
  }
  IntPara = scrGetIntPara(0);
  fldRunDanteStanceSet(IntPara, 0);
  return 1;
}

// 0x1036860
s32 fldCommand_FLD_ELV_ENDCHK(void) {
  s32 v3;

  v3 = fldElvFloorEndChk();
  scrSetIntReturnValue(v3);
  return 1;
}

// 0x10367f0
s32 fldCommand_FLD_ELV_FLOOREND(void) {
  fldElvFloorEnd();
  return 1;
}

// 0x1036740
s32 fldCommand_FLD_ELV_FLOORSTART(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  fldElvFloorStart(IntPara, v4);
  return 1;
}

// 0x1037680
s32 fldCommand_FLD_EXIT_CAMERA(void) {
  u64 *v1;
  dds3ProcessID_t_o *ProcessID;
  System_String_o *evename;

  evename = 0;
  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  ProcessID = scrGetScriptHandle()->ProcessID;
  evename = fldEveHitResName_Find(ProcessID);
  if (evename)
  {
    fldDoor_ExitCamera(&evename);
  }
  return 1;
}

// 0x1030ee0
s32 fldCommand_FLD_FILTER(void) {
  struct fldDebug_t_o *fldDbg;
  s32 FilterID;
  s32 IntPara;
  s32 v8;
  s32 v9;

  fldDbg->FilterID = scrGetIntPara(0);
  fldDbg->FilterID = LOBYTE(fldDbg->FilterID);
  FilterID = fldDbg->FilterID;
  IntPara = scrGetIntPara(1);
  v8 = scrGetIntPara(2);
  fldSkySetFilter(FilterID, IntPara, v8);
  v9 = scrGetIntPara(3);
  fldSkySetFilterAnime(v9);
  return 1;
}

// 0x1038200
s32 fldCommand_FLD_GET_ITEMBOX_RND(void) {
  struct System_Int32_array *fld_itembox_kakuritu_tbl;
  s32 AgeOfMoon;
  signed s32 v7;
  signed s32 v8;
  u64 *v9;
  u64 *v11;
  s32 v13;
  signed s32 v15;
  u32 RandIntA;

  AgeOfMoon = evtGetAgeOfMoon();
  v7 = fld_itembox_kakuritu_tbl->m_Items[AgeOfMoon];
  RandIntA = dds3GetRandIntA(0x64u, "");
  v8 = RandIntA;
  v9 = sub_8D3950(s32, &RandIntA);
  v15 = v7;
  v11 = sub_8D3950(s32, &v15);
  Write_2930752("ITEMBOX_RND {0:D} / {1:D}\n", v9, v11);
  if (v8 <= v7)
  {
    v13 = 1;
  }
  else
  {
    v13 = 0;
  }
  scrSetIntReturnValue(v13);
  return 1;
}

// 0x1037f60
s32 fldCommand_FLD_GET_KIRETA(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 flag;
  u32 v6;
  s32 v8;
  s32 v10;
  s32 v12;
  s32 v13;

  switch (scrGetIntPara(0))
  {
    case 0:
      else
      {
        flag = fldGb->flag;
        if ((flag & 1) == 0)
          goto LABEL_31;
      }
      v6 = flag & 0xFFFFFFFE;
      goto LABEL_41;
    case 1:
      else
      {
        v8 = fldGb->flag;
        if ((v8 & 2) == 0)
          goto LABEL_31;
      }
      v6 = v8 & 0xFFFFFFFD;
      goto LABEL_41;
    case 2:
      else
      {
        v10 = fldGb->flag;
        if ((v10 & 4) == 0)
          goto LABEL_31;
      }
      v6 = v10 & 0xFFFFFFFB;
      goto LABEL_41;
    case 3:
      else
      {
        v12 = fldGb->flag;
        if ((v12 & 8) == 0)
          goto LABEL_31;
      }
      v6 = v12 & 0xFFFFFFF7;
LABEL_41:
      v13 = 1;
      fldGb->flag = v6;
      {
LABEL_32:
      }
LABEL_42:
      scrSetIntReturnValue(v13);
      return 1;
    default:
      goto LABEL_31;
  }
}

// 0x10357f0
s32 fldCommand_FLD_GET_TAKARA_TBL(void) {
  u64 *v1;
  dds3ProcessID_t_o *ProcessID;
  s32 v5;
  u64 *v8;
  u64 *v9;
  u64 *v11;
  s32 klass;
  s32 handle_high;
  s32 handle_low;
  s32 v22;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  ProcessID = scrGetScriptHandle()->ProcessID;
  v5 = fldEveHitTakaraIdx_Find(ProcessID);
  switch (scrGetIntPara(0))
  {
    case 0:
      v22 = *&_get_Item(
                fldHitData->_fldItemBoxTbl,
                v5)->isLongReference;
      v8 = sub_8D3950(s32, &v22);
      handle_low = SLOWORD(_get_Item(
                             fldHitData->_fldItemBoxTbl,
                             v5)->gcHandle.handle);
      v9 = sub_8D3950(s32, &handle_low);
      handle_high = SHIWORD(_get_Item(
                              fldHitData->_fldItemBoxTbl,
                              v5)->gcHandle.handle);
      v11 = sub_8D3950(s32, &handle_high);
      Write_2930912("Type:{0:D} ID:{1:x} Num:{2:D}\n", v8, v9, v11);
      klass = *&_get_Item(
                  fldHitData->_fldItemBoxTbl,
                  v5)->isLongReference;
        goto LABEL_38;
      goto LABEL_17;
    case 1:
      klass = SLOWORD(_get_Item(
                        fldHitData->_fldItemBoxTbl,
                        v5)->gcHandle.handle);
        goto LABEL_38;
      goto LABEL_17;
    case 2:
      klass = SHIWORD(_get_Item(
                        fldHitData->_fldItemBoxTbl,
                        v5)->gcHandle.handle);
        goto LABEL_38;
      goto LABEL_17;
    case 3:
      klass = _get_Item(
                fldHitData->_fldItemBoxTbl,
                v5)[1].klass;
        goto LABEL_38;
      goto LABEL_17;
    case 4:
      klass = HIDWORD(_get_Item(
                        fldHitData->_fldItemBoxTbl,
                        v5)[1].klass);
        goto LABEL_38;
LABEL_17:
LABEL_38:
      scrSetIntReturnValue(klass);
      break;
    default:
      return 1;
  }
  return 1;
}

// 0x1035080
s32 fldCommand_FLD_GIMIC_HOJI(void) {
  System_Object_array *v2;
  s64 *v3;
  s64 *v4;
  s64 *v6;
  s64 *v7;
  s64 *v9;
  s64 *v10;
  s64 *v12;
  s64 *v14;
  s32 fieldID;
  s32 v21;
  s32 v25;
  s32 v27;
  s32 v29;
  s32 v35;
  s32 v36;
  s32 v37;
  s32 IntPara;

  v2 = NewSpecific(object, 4u);
  IntPara = scrGetIntPara(0);
  v3 = sub_8D3950(s32, &IntPara);
  v4 = v3;
  v2->m_Items[0] = v4;
  v37 = scrGetIntPara(1);
  v6 = sub_8D3950(s32, &v37);
  v7 = v6;
  v2->m_Items[1] = v7;
  v36 = scrGetIntPara(2);
  v9 = sub_8D3950(s32, &v36);
  v10 = v9;
  v2->m_Items[2] = v10;
  v35 = scrGetIntPara(3);
  v12 = sub_8D3950(s32, &v35);
  v14 = v12;
  v2->m_Items[3] = v14;
  Write_2930544("CALL GIMIC_HOJI {0:D} {1:D} {2:D} {3:D}\n", v2);
  fieldID = scrGetIntPara(0);
  if (fieldID)
  {
      goto LABEL_33;
    goto LABEL_27;
  }
  fieldID = fldGb->fieldID;
  {
LABEL_27:
  }
LABEL_33:
  v21 = scrGetIntPara(1);
  if (v21)
  {
      goto LABEL_41;
    goto LABEL_35;
  }
  v21 = fldGb->areaID + 1;
  {
LABEL_35:
  }
LABEL_41:
  v25 = scrGetIntPara(2);
  if (v25)
  {
    v27 = scrGetIntPara(3);
    fldGbSetGimic(fieldID, v21, v25, v27);
  }
  else
  {
    do
    {
      v29 = scrGetIntPara(3);
      fldGbSetGimic(fieldID, v21, v25++, v29);
    }
    while (v25 != 16);
  }
  return 1;
}

// 0x1036ba0
s32 fldCommand_FLD_INF_GET(void) {
  s32 IntPara;
  s32 v4;
  s32 v5;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  v5 = fldInfGet(IntPara, v4);
  scrSetIntReturnValue(v5);
  return 1;
}

// 0x1036c60
s32 fldCommand_FLD_INF_GETPANEL(void) {
  s32 v3;

  v3 = fldInfChkFastPanel(1);
  scrSetIntReturnValue(v3);
  return 1;
}

// 0x1036d00
s32 fldCommand_FLD_INF_GOWAP(void) {
  fldInfToWAP();
  return 1;
}

// 0x1036ae0
s32 fldCommand_FLD_INF_NEXT(void) {
  s32 IntPara;
  s32 v4;
  s32 v5;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  v5 = fldInfNext(IntPara, v4);
  scrSetIntReturnValue(v5);
  return 1;
}

// 0x1030df0
s32 fldCommand_FLD_KANKYO(void) {
  struct fldDebug_t_o *fldDbg;
  s32 SkyTblID;
  s32 IntPara;

  fldDbg->SkyTblID = scrGetIntPara(0);
  SkyTblID = fldDbg->SkyTblID;
  IntPara = scrGetIntPara(1);
  fldSkySetTbl(SkyTblID, IntPara);
  return 1;
}

// 0x1034300
s32 fldCommand_FLD_MAP_OFF(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;

  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_23;
  }
  else
  {
    v7 = fldGb->areaID + 1;
    {
LABEL_23:
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
      goto LABEL_24;
    }
  }
    goto LABEL_23;
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
LABEL_24:
  v12 = v9;
  fldAutoMapCloseBlock2(IntPara, v7, v12);
  return 1;
}

// 0x1034160
s32 fldCommand_FLD_MAP_ON(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;

  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_23;
  }
  else
  {
    v7 = fldGb->areaID + 1;
    {
LABEL_23:
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
      goto LABEL_24;
    }
  }
    goto LABEL_23;
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
LABEL_24:
  v12 = v9;
  fldAutoMapOpenBlock2(IntPara, v7, v12);
  return 1;
}

// 0x10383c0
s32 fldCommand_FLD_MODEL_DANTE(void) {
  struct dds3Basic_t_o *player3;
  s32 v5;

  else
  {
    if (player3)
      goto LABEL_6;
  }
  v5 = -1;
LABEL_18:
  scrSetIntReturnValue(v5);
  return 1;
}

// 0x1037840
s32 fldCommand_FLD_MODEL_LIGHT(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;

  v1 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v1);
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  fldNpcLightSet(UnitHandle);
  return 1;
}

// 0x1031880
s32 fldCommand_FLD_MODEL_OFF(void) {
  System_Object_array *v2;
  s64 *v3;
  s64 *v4;
  s64 *v6;
  s64 *v7;
  s64 *StrPara;
  s64 *v10;
  s64 *v12;
  s64 *v14;
  s32 fieldID;
  s32 v21;
  s32 v24;
  s64 v27;
  struct fldGlobalWork_t_o *fldGb;
  u64 *v46;
  Il2CppObject *workdata;
  dds3MatterObjectBasicWorkData_t_c *v52;
  s64 typeHierarchyDepth;
  Il2CppClass *klass;
  s32 v55;
  Il2CppObject *v60;
  s64 v61;
  char *v63;
  s64 *v64;
  s32 v65;
  s32 IntPara;
  dds3Basic_t_o *aPtr;
  dds3Basic_t_o *pBasic;
  dds3BasicArrayHandle_t_o *hndl;
  System_String_o *pName;
  u64 v71[3];

  hndl = 0;
  pName = 0;
  aPtr = 0;
  pBasic = 0;
  v2 = NewSpecific(object, 4u);
  LODWORD(v71[0]) = scrGetIntPara(0);
  v3 = sub_8D3950(s32, v71);
  v4 = v3;
  v2->m_Items[0] = v4;
  IntPara = scrGetIntPara(1);
  v6 = sub_8D3950(s32, &IntPara);
  v7 = v6;
  v2->m_Items[1] = v7;
  StrPara = scrGetStrPara(2);
  v10 = StrPara;
  v2->m_Items[2] = v10;
  v65 = scrGetIntPara(3);
  v12 = sub_8D3950(s32, &v65);
  v14 = v12;
  v2->m_Items[3] = v14;
  Write_2930544("OFF {0:D} {1:D} {2} {3:D}\n", v2);
  fieldID = scrGetIntPara(0);
  if (fieldID)
  {
      goto LABEL_33;
    goto LABEL_27;
  }
  fieldID = fldGb->fieldID;
  {
LABEL_27:
  }
LABEL_33:
  v21 = scrGetIntPara(1);
  if (v21)
  {
      goto LABEL_41;
    goto LABEL_35;
  }
  v21 = fldGb->areaID + 1;
  {
LABEL_35:
  }
LABEL_41:
  v24 = scrGetIntPara(3);
  pName = scrGetStrPara(2);
  if (pName)
  {
    LODWORD(v27) = fldCommand_GetHojiID(&pName);
    fldGbSetView(fieldID, v21, v27, 1);
  }
  else
  {
    fldGbSetView(fieldID, v21, 0, 1);
    fldGbSetView(fieldID, v21, 1, 1);
    fldGbSetView(fieldID, v21, 2, 1);
    fldGbSetView(fieldID, v21, 3, 1);
    fldGbSetView(fieldID, v21, 4, 1);
    fldGbSetView(fieldID, v21, 5, 1);
    fldGbSetView(fieldID, v21, 6, 1);
    fldGbSetView(fieldID, v21, 7, 1);
    fldGbSetView(fieldID, v21, 8, 1);
    fldGbSetView(fieldID, v21, 9, 1);
    fldGbSetView(fieldID, v21, 10, 1);
    fldGbSetView(fieldID, v21, 11, 1);
    fldGbSetView(fieldID, v21, 12, 1);
    fldGbSetView(fieldID, v21, 13, 1);
    fldGbSetView(fieldID, v21, 14, 1);
    fldGbSetView(fieldID, v21, 15, 1);
    v27 = 16;
  }
  if (fieldID == fldGb->fieldID)
  {
    else if (v21 != fldGb->areaID + 1)
    {
      return 1;
    }
    v46 = Allocate(dds3BasicArrayHandle_t);
    dds3BasicArrayHandle_t___ctor(v46);
    hndl = v46;
    pBasic = dds3GetControlScene();
    hndl = dds3SceneBasicGetList(&pBasic, 6u);
    if (dds3GetBasicArrayCount(&hndl))
    {
      dds3SetFirstBasicArray(&hndl);
      if (v24)
      {
        while (1)
        {
          aPtr = dds3GetBasicArray(&hndl);
          workdata = aPtr->workdata;
          klass = workdata->klass;
          if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
          {
            break;
          }
          if (v27 == LODWORD(workdata[1].monitor))
          {
            switch (v24)
            {
              case 1:
                v55 = 6;
                goto LABEL_127;
              case 2:
                v55 = 8;
                goto LABEL_127;
              case 3:
                v55 = 10;
                goto LABEL_127;
              case 4:
                v55 = 12;
LABEL_127:
                dds3MatterObjectBasicSetAlpMode(&aPtr, v55);
                break;
              default:
                break;
            }
          }
          else if (!dds3SetNextBasicArray(&hndl))
          {
            goto LABEL_151;
          }
        }
LABEL_156:
        sub_8FC2C0(klass->_1.element_class, v52, v71);
        if ((v71[0] & 1) != 0)
          v63 = v71[2];
        else
          v63 = v71 + 1;
        v64 = sub_8C4940(v63);
      }
      do
      {
        aPtr = dds3GetBasicArray(&hndl);
        v60 = aPtr->workdata;
        klass = v60->klass;
        if (v60->klass->_2.typeHierarchyDepth < v61
          || klass->_2.typeHierarchy[v61 - 1] != dds3MatterObjectBasicWorkData_t)
        {
          goto LABEL_156;
        }
        if (v27 == LODWORD(v60[1].monitor))
          dds3MatterObjectBasicSetAlpMode(&aPtr, 2);
      }
      while (dds3SetNextBasicArray(&hndl));
LABEL_151:
      dds3FreeBasicArrayHandle(&hndl);
    }
  }
  return 1;
}

// 0x1033ab0
s32 fldCommand_FLD_MODEL_OFF2(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;

  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_23;
  }
  else
  {
    v7 = fldGb->areaID + 1;
    {
LABEL_23:
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
      goto LABEL_24;
    }
  }
    goto LABEL_23;
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
LABEL_24:
  v12 = v9;
  fldGbSetEView(IntPara, v7, v12, 1);
  return 1;
}

// 0x1031010
s32 fldCommand_FLD_MODEL_ON(void) {
  s32 IntPara;
  s32 v7;
  s32 v10;
  s64 v13;
  struct fldGlobalWork_t_o *fldGb;
  u64 *v32;
  Il2CppObject *workdata;
  dds3MatterObjectBasicWorkData_t_c *v38;
  s64 typeHierarchyDepth;
  Il2CppClass *klass;
  s32 v41;
  Il2CppObject *v42;
  s64 v43;
  char *v45;
  s64 *v46;
  dds3Basic_t_o *aPtr;
  dds3Basic_t_o *pBasic;
  dds3BasicArrayHandle_t_o *hndl;
  System_String_o *pName;
  u64 v51[3];

  hndl = 0;
  pName = 0;
  pBasic = 0;
  aPtr = 0;
  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_22;
    goto LABEL_16;
  }
  v7 = fldGb->areaID + 1;
  {
LABEL_16:
  }
LABEL_22:
  v10 = scrGetIntPara(3);
  pName = scrGetStrPara(2);
  if (pName)
  {
    LODWORD(v13) = fldCommand_GetHojiID(&pName);
    fldGbSetView(IntPara, v7, v13, 0);
  }
  else
  {
    fldGbSetView(IntPara, v7, 0, 0);
    fldGbSetView(IntPara, v7, 1, 0);
    fldGbSetView(IntPara, v7, 2, 0);
    fldGbSetView(IntPara, v7, 3, 0);
    fldGbSetView(IntPara, v7, 4, 0);
    fldGbSetView(IntPara, v7, 5, 0);
    fldGbSetView(IntPara, v7, 6, 0);
    fldGbSetView(IntPara, v7, 7, 0);
    fldGbSetView(IntPara, v7, 8, 0);
    fldGbSetView(IntPara, v7, 9, 0);
    fldGbSetView(IntPara, v7, 10, 0);
    fldGbSetView(IntPara, v7, 11, 0);
    fldGbSetView(IntPara, v7, 12, 0);
    fldGbSetView(IntPara, v7, 13, 0);
    fldGbSetView(IntPara, v7, 14, 0);
    fldGbSetView(IntPara, v7, 15, 0);
    v13 = 16;
  }
  if (IntPara == fldGb->fieldID)
  {
    else if (v7 != fldGb->areaID + 1)
    {
      return 1;
    }
    v32 = Allocate(dds3BasicArrayHandle_t);
    dds3BasicArrayHandle_t___ctor(v32);
    hndl = v32;
    pBasic = dds3GetControlScene();
    hndl = dds3SceneBasicGetList(&pBasic, 6u);
    if (dds3GetBasicArrayCount(&hndl))
    {
      dds3SetFirstBasicArray(&hndl);
      if (v10)
      {
        while (1)
        {
          aPtr = dds3GetBasicArray(&hndl);
          workdata = aPtr->workdata;
          klass = workdata->klass;
          if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
          {
            break;
          }
          if (v13 == LODWORD(workdata[1].monitor))
          {
            switch (v10)
            {
              case 1:
                v41 = 5;
                goto LABEL_108;
              case 2:
                v41 = 7;
                goto LABEL_108;
              case 3:
                v41 = 9;
                goto LABEL_108;
              case 4:
                v41 = 11;
LABEL_108:
                dds3MatterObjectBasicSetAlpMode(&aPtr, v41);
                break;
              default:
                break;
            }
          }
          else if (!dds3SetNextBasicArray(&hndl))
          {
            goto LABEL_128;
          }
        }
LABEL_133:
        sub_8FC2C0(klass->_1.element_class, v38, v51);
        if ((v51[0] & 1) != 0)
          v45 = v51[2];
        else
          v45 = v51 + 1;
        v46 = sub_8C4940(v45);
      }
      do
      {
        aPtr = dds3GetBasicArray(&hndl);
        v42 = aPtr->workdata;
        klass = v42->klass;
        if (v42->klass->_2.typeHierarchyDepth < v43
          || klass->_2.typeHierarchy[v43 - 1] != dds3MatterObjectBasicWorkData_t)
        {
          goto LABEL_133;
        }
        if (v13 == LODWORD(v42[1].monitor))
          dds3MatterObjectBasicSetAlpMode(&aPtr, 1);
      }
      while (dds3SetNextBasicArray(&hndl));
LABEL_128:
      dds3FreeBasicArrayHandle(&hndl);
    }
  }
  return 1;
}

// 0x1033910
s32 fldCommand_FLD_MODEL_ON2(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;

  IntPara = scrGetIntPara(0);
  if (IntPara)
  {
      goto LABEL_14;
    goto LABEL_8;
  }
  IntPara = fldGb->fieldID;
  {
LABEL_8:
  }
LABEL_14:
  v7 = scrGetIntPara(1);
  if (v7)
  {
      goto LABEL_23;
  }
  else
  {
    v7 = fldGb->areaID + 1;
    {
LABEL_23:
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
      goto LABEL_24;
    }
  }
    goto LABEL_23;
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
LABEL_24:
  v12 = v9;
  fldGbSetEView(IntPara, v7, v12, 0);
  return 1;
}

// 0x10372e0
s32 fldCommand_FLD_MSE_PLAY(void) {
  s32 IntPara;
  s32 v5;

  IntPara = scrGetIntPara(0);
  fldMotionSePlay(IntPara, 0);
  v5 = scrGetIntPara(0);
  evtUpdateEx_FLD_MSE_After(v5);
  return 1;
}

// 0x10373c0
s32 fldCommand_FLD_MSE_PLAY2(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  fldMotionSePlay(IntPara, v4);
  return 1;
}

// 0x1037470
s32 fldCommand_FLD_MSE_STOP2(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  fldMotionSeStop(IntPara, v4);
  return 1;
}

// 0x1034a90
s32 fldCommand_FLD_NPC_OFF(void) {
  u64 *v2;
  u64 *v3;
  Il2CppObject *StrPara;
  s32 fieldID;
  s32 v11;
  s32 HojiID;
  s32 v17;
  s32 v18;
  s32 v19;
  struct fldGlobalWork_t_o *fldGb;
  s32 v39;
  s32 IntPara;
  System_String_o *pName;

  pName = 0;
  IntPara = scrGetIntPara(0);
  v2 = sub_8D3950(s32, &IntPara);
  v39 = scrGetIntPara(1);
  v3 = sub_8D3950(s32, &v39);
  StrPara = scrGetStrPara(2);
  Write_2930912("CMD NPC_OFF({0:D},{1:D},{2})\n", v2, v3, StrPara, 0);
  fieldID = scrGetIntPara(0);
  if (fieldID)
  {
      goto LABEL_17;
    goto LABEL_11;
  }
  fieldID = fldGb->fieldID;
  {
LABEL_11:
  }
LABEL_17:
  v11 = scrGetIntPara(1);
  if (v11)
  {
      goto LABEL_25;
    goto LABEL_19;
  }
  v11 = fldGb->areaID + 1;
  {
LABEL_19:
  }
LABEL_25:
  pName = scrGetStrPara(2);
  if (pName)
  {
    HojiID = fldCommand_GetHojiID(&pName);
    v17 = fieldID;
    v18 = v11;
    v19 = HojiID;
  }
  else
  {
    fldGbSetNpc(fieldID, v11, 0, 1);
    fldGbSetNpc(fieldID, v11, 1, 1);
    fldGbSetNpc(fieldID, v11, 2, 1);
    fldGbSetNpc(fieldID, v11, 3, 1);
    fldGbSetNpc(fieldID, v11, 4, 1);
    fldGbSetNpc(fieldID, v11, 5, 1);
    fldGbSetNpc(fieldID, v11, 6, 1);
    fldGbSetNpc(fieldID, v11, 7, 1);
    fldGbSetNpc(fieldID, v11, 8, 1);
    fldGbSetNpc(fieldID, v11, 9, 1);
    fldGbSetNpc(fieldID, v11, 10, 1);
    fldGbSetNpc(fieldID, v11, 11, 1);
    fldGbSetNpc(fieldID, v11, 12, 1);
    fldGbSetNpc(fieldID, v11, 13, 1);
    fldGbSetNpc(fieldID, v11, 14, 1);
    v17 = fieldID;
    v18 = v11;
    v19 = 15;
  }
  fldGbSetNpc(v17, v18, v19, 1);
  if (fieldID == fldGb->fieldID)
  {
    if (v11 == fldGb->areaID + 1)
    {
      fldNpcHojiRefresh();
    }
  }
  return 1;
}

// 0x10344a0
s32 fldCommand_FLD_NPC_ON(void) {
  u64 *v2;
  u64 *v3;
  Il2CppObject *StrPara;
  s32 fieldID;
  s32 v11;
  s32 HojiID;
  s32 v17;
  s32 v18;
  s32 v19;
  struct fldGlobalWork_t_o *fldGb;
  s32 v39;
  s32 IntPara;
  System_String_o *pName;

  pName = 0;
  IntPara = scrGetIntPara(0);
  v2 = sub_8D3950(s32, &IntPara);
  v39 = scrGetIntPara(1);
  v3 = sub_8D3950(s32, &v39);
  StrPara = scrGetStrPara(2);
  Write_2930912("CMD NPC_ON({0:D},{1:D},{2})\n", v2, v3, StrPara, 0);
  fieldID = scrGetIntPara(0);
  if (fieldID)
  {
      goto LABEL_17;
    goto LABEL_11;
  }
  fieldID = fldGb->fieldID;
  {
LABEL_11:
  }
LABEL_17:
  v11 = scrGetIntPara(1);
  if (v11)
  {
      goto LABEL_25;
    goto LABEL_19;
  }
  v11 = fldGb->areaID + 1;
  {
LABEL_19:
  }
LABEL_25:
  pName = scrGetStrPara(2);
  if (pName)
  {
    HojiID = fldCommand_GetHojiID(&pName);
    v17 = fieldID;
    v18 = v11;
    v19 = HojiID;
  }
  else
  {
    fldGbSetNpc(fieldID, v11, 0, 0);
    fldGbSetNpc(fieldID, v11, 1, 0);
    fldGbSetNpc(fieldID, v11, 2, 0);
    fldGbSetNpc(fieldID, v11, 3, 0);
    fldGbSetNpc(fieldID, v11, 4, 0);
    fldGbSetNpc(fieldID, v11, 5, 0);
    fldGbSetNpc(fieldID, v11, 6, 0);
    fldGbSetNpc(fieldID, v11, 7, 0);
    fldGbSetNpc(fieldID, v11, 8, 0);
    fldGbSetNpc(fieldID, v11, 9, 0);
    fldGbSetNpc(fieldID, v11, 10, 0);
    fldGbSetNpc(fieldID, v11, 11, 0);
    fldGbSetNpc(fieldID, v11, 12, 0);
    fldGbSetNpc(fieldID, v11, 13, 0);
    fldGbSetNpc(fieldID, v11, 14, 0);
    v17 = fieldID;
    v18 = v11;
    v19 = 15;
  }
  fldGbSetNpc(v17, v18, v19, 0);
  if (fieldID == fldGb->fieldID)
  {
    if (v11 == fldGb->areaID + 1)
    {
      fldNpcHojiRefresh();
    }
  }
  return 1;
}

// 0x1037ec0
s32 fldCommand_FLD_NPC_SINEN(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  gFldKyouseiTalk = IntPara;
  return 1;
}

// 0x1037930
s32 fldCommand_FLD_SAGASI_AKUMA(void) {
  u64 v3;
  struct datTakaraSagasiT_s_array *tbl;
  struct datTakaraSagasiT_s_array *v8;
  struct datTakaraSagasiT_s_array *v11;
  struct datTakaraSagasiI_s_array *itemtbl;
  u32 par;
  signed s32 RandIntA;
  s64 v17;
  struct datTakaraSagasiT_s_array *v19;
  u64 v20;
  struct datTakaraSagasiI_s_array *v22;
  s32 v25;
  struct datTakaraSagasiT_s_array *v27;
  struct datTakaraSagasiI_s_array *v29;
  s32 gFldTakaraAkumaId;

  if (!scrGetIntPara(0))
    goto LABEL_56;
LABEL_6:
  v3 = 0;
  while (1)
  {
    tbl = datTakaraSagasi->tbl;
    if (!tbl->m_Items[v3]->flag)
      break;
    v8 = datTakaraSagasi->tbl;
    if (evtBitCheck(v8->m_Items[v3]->flag))
      break;
LABEL_39:
    if (v3++ >= 3)
    {
      v25 = 3;
      goto LABEL_61;
    }
  }
  v11 = datTakaraSagasi->tbl;
  itemtbl = v11->m_Items[v3]->itemtbl;
  par = itemtbl->m_Items[7]->par;
  RandIntA = dds3GetRandIntA(par, "");
  v17 = 4;
  while (1)
  {
    v19 = datTakaraSagasi->tbl;
    v20 = v17 - 4;
    v22 = v19->m_Items[v3]->itemtbl;
    if (RandIntA <= *(*(&v22->obj.klass + v17) + 18LL))
      break;
    ++v17;
    if (v20 >= 7)
      goto LABEL_39;
  }
  v27 = datTakaraSagasi->tbl;
  v29 = v27->m_Items[v3]->itemtbl;
  gFldTakaraAkumaId = *(*(&v29->obj.klass + v17) + 16LL);
  {
LABEL_53:
  }
LABEL_60:
  v25 = gFldTakaraAkumaId;
LABEL_61:
  scrSetIntReturnValue(v25);
  return 1;
}

// 0x10375e0
s32 fldCommand_FLD_SET_ENCOUNT(void) {
  struct fldGlobalWork_t_o *fldGb;

  fldGb->EncPID = scrGetIntPara(0);
  return 1;
}

// 0x1035d50
s32 fldCommand_FLD_SET_TAKARA_OPEN(void) {
  u64 *v1;
  dds3ProcessID_t_o *ProcessID;
  s32 v6;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  ProcessID = scrGetScriptHandle()->ProcessID;
  v6 = fldEveHitTakaraIdx_Find(ProcessID);
  fldGbSetTakaraOpen(v6);
  return 1;
}

// 0x10371a0
s32 fldCommand_FLD_SE_PLAY(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  fldSePlay(IntPara);
  return 1;
}

// 0x1037240
s32 fldCommand_FLD_SE_STOP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  fldSeStop(IntPara);
  return 1;
}

// 0x1037520
s32 fldCommand_FLD_TITLE_START(void) {
  return 1;
}

// 0x1037530
s32 fldCommand_FLD_TITLE_START2(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  fldTitleStart(IntPara, v4);
  return 1;
}

// 0x10386f0
s32 fldCommand_FLD_WAIT_CROSSFADE(void) {
  return !IsBGMFadeOut();
}

// 0x1035f60
s32 fldCommand_FLD_WARP_CALL_FIELD(void) {
  u64 *v1;
  System_String_o **p_evename;
  dds3ProcessID_t_o *ProcessID;
  s64 v10;
  System_String_o *evename;

  v10 = 0;
  evename = 0;
  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  Write("FLD_WARP_CALL_FIELD\n", 0);
  else if (fldDoor_ChkWarp())
  {
    goto LABEL_9;
  }
  ProcessID = scrGetScriptHandle()->ProcessID;
  evename = fldEveHitResName_Find(ProcessID);
  if (evename)
  {
    p_evename = &evename;
    goto LABEL_25;
  }
  return 1;
}

// 0x1036360
s32 fldCommand_FLD_WARP_CASH_F(void) {
  u64 *v1;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *ActiveUnitSceneBasic;
  dds3Basic_t_o *v7;
  scrProcessWork_s_o *ScriptHandle;
  dds3ProcessID_t_o *ProcessID;
  s32 v11;
  System_String_o *v14;
  dds3Basic_t_o *v15;
  dds3Basic_t_o *v18;
  dds3Basic_t_o *pBasic;
  System_String_o *evename;

  evename = 0;
  pBasic = 0;
  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  ActiveScene = dds3GetActiveScene();
  pBasic = ActiveScene;
  ActiveUnitSceneBasic = dds3GetActiveUnitSceneBasic(ActiveScene);
  if (ActiveUnitSceneBasic)
  {
    v7 = ActiveUnitSceneBasic;
    ScriptHandle = scrGetScriptHandle();
    ProcessID = ScriptHandle->ProcessID;
    v11 = fldEveHitResID_Find(ProcessID);
    v14 = fldEveHitResName_Find(ScriptHandle->ProcessID);
    evename = v14;
    v15 = dds3SearchSceneBasic(&pBasic, v11, 0x11u);
    if (v15)
    {
      v18 = v15;
      if (fldEveHit_ChkDir(v7, v18) && v14)
      {
        fldDoor_WarpCash(&evename);
      }
    }
  }
  return 1;
}

// 0x10366a0
s32 fldCommand_FLD_WARP_ELV_EXIT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  fldDoor_ElvExit(IntPara);
  return 1;
}

// 0x10365f0
s32 fldCommand_FLD_WARP_ELV_GETTBL(void) {
  s32 IntPara;
  s32 ElvTbl;

  IntPara = scrGetIntPara(0);
  ElvTbl = fldDoor_GetElvTbl(IntPara);
  scrSetIntReturnValue(ElvTbl);
  return 1;
}

// 0x1036900
s32 fldCommand_FLD_WARP_GET_DOOR(void) {
  s32 IntPara;
  s32 Door;

  IntPara = scrGetIntPara(0);
  Door = fldWapGetDoor(IntPara);
  scrSetIntReturnValue(Door);
  return 1;
}

// 0x1037770
s32 fldCommand_FLD_WARP_GET_WARPEFF(void) {
  s32 WarpEff;

  WarpEff = fldDoor_GetWarpEff();
  scrSetIntReturnValue(WarpEff);
  dds3EffectDistortionBlur_SetFldEventCntF(0.0);
  return 1;
}

// 0x1036540
s32 fldCommand_FLD_WARP_HASIGO_GETTBL(void) {
  s32 IntPara;
  s32 HasigoTbl;

  IntPara = scrGetIntPara(0);
  HasigoTbl = fldDoor_GetHasigoTbl(IntPara);
  scrSetIntReturnValue(HasigoTbl);
  return 1;
}

// 0x10369b0
s32 fldCommand_FLD_WARP_RUN_START(void) {
  u64 *v1;
  s32 v4;
  dds3ProcessID_t_o *ProcessID;
  s32 v8;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  else if (fldDoor_ChkWarp())
  {
    goto LABEL_6;
  }
  ProcessID = scrGetScriptHandle()->ProcessID;
  v8 = fldEveHitResID_Find(ProcessID);
  v4 = v8;
LABEL_21:
  fldDoorRun_FindStart(v4);
  return 1;
}

// 0x1030ad0
s32 fldCommand_FREE_CASH_F(void) {
  if (fldGb->fieldID >= 10)
  {
    fldFreeNextFile();
  }
  return 1;
}

// 0x1030c80
s32 fldCommand_GetHojiID(char **pName) {
  System_String_o *v3;
  s32 Length;
  s32 v5;
  u16 Chars;

  v3 = StrStr(*pName, "hoji");
  if (v3)
  {
    Length = get_Length(*pName);
    if (Length < 4)
    {
      LODWORD(v3) = 0;
    }
    else
    {
      v5 = Length;
      Chars = get_Chars(*pName, Length - 2);
      LODWORD(v3) = 10 * Chars + get_Chars(*pName, v5 - 1) - 528;
    }
  }
  return v3;
}

// 0x102f3d0
s32 fldCommand_PAD_DISABLE(void) {
  dds3Basic_t_o *ActiveScene;

  fldReleaseUnitPad();
  ActiveScene = dds3GetActiveScene();
  if (dds3GetActiveUnitSceneBasic(ActiveScene))
  {
    fldPlayerMotReset();
  }
  return 1;
}

// 0x102f4c0
s32 fldCommand_PAD_ENABLE(void) {
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *basic;

  basic = 0;
  ActiveScene = dds3GetActiveScene();
  basic = dds3GetActiveUnitSceneBasic(ActiveScene);
  if (basic)
  {
    dds3ObjectBaseSetPrimaryControl(&basic, 0);
    fldPlayerMotReset();
    fldRegistUnitPad();
  }
  return 1;
}

// 0x1030b70
s32 fldCommand_SEARCH_ID(char **pName) {
  System_String_o *v4;
  dds3Basic_t_o *v5;
  Il2CppObject *v8;
  dds3Basic_t_o *scene;

  scene = 0;
  scene = dds3GetControlScene();
  v4 = *pName;
  v5 = dds3SceneBasicSearchName(&scene, v4);
  if (v5)
    return v5->serialID;
  v8 = Format("field SEARCH_ID NotFound:[{0}]\n", *pName, 0);
  Log(v8, 0);
  return -1;
}

// 0x1030770
s32 fldCommand_SET_ALLPANEL(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 result;

  fldGb->AllPanelMode = scrGetIntPara(0);
  fldGb->AllPanelCnt = 0;
  switch (fldGb->AllPanelMode)
  {
    case 0:
      evtDisableMoonDraw();
      goto LABEL_14;
    case 1:
      evtEnableMoonDraw();
      result = 1;
      break;
    case 2:
      evtDisableMoonDraw2();
      fldGb->AllPanelCnt = 15;
      result = 1;
      break;
    case 3:
      evtEnableMoonDraw2();
      fldGb->AllPanelCnt = 0;
      result = 1;
      break;
    default:
LABEL_14:
      result = 1;
      break;
  }
  return result;
}

// 0x1030d50
s32 fldCommand_SET_CAMTBL(void) {
  struct fldGlobalWork_t_o *fldGb;

  fldGb->CamTableIdx = scrGetIntPara(0);
  return 1;
}

// 0x1030980
s32 fldCommand_SET_CASH_F(void) {
  s32 IntPara;
  s32 v8;

  if (fldGb->fieldID >= 10)
  {
    IntPara = scrGetIntPara(0);
    if (IntPara)
    {
      {
LABEL_18:
        v8 = scrGetIntPara(1);
        fldLoadNextFile(IntPara, v8);
        return 1;
      }
    }
    else
    {
      IntPara = fldGb->fieldID;
        goto LABEL_18;
    }
    goto LABEL_18;
  }
  return 1;
}

// 0x102f900
s32 fldCommand_SET_CHASE_CAMERA(void) {
  f32 PlayerKakudo;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  s32 MotionMinorNum;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;

  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  fldGb->cammode = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  PlayerKakudo = fldGb->PlayerKakudo;
  ooyCamKakudo = -PlayerKakudo;
  v6 = OOYRAD(fldGb->PlayerKakudo + 180.0);
  sdfSin(v6);
  sub_854930(&v22, 0);
  sub_854930(&v22, 1u);
  v7 = OOYRAD(fldGb->PlayerKakudo + 180.0);
  sdfCos(v7);
  sub_854930(&v22, 2u);
  v8 = OOYRAD(ooyCamKakudo);
  sdfSin(v8);
  sub_854930(&v20, 0);
  sub_854930(&v20, 1u);
  v9 = OOYRAD(ooyCamKakudo);
  sdfCos(v9);
  sub_854930(&v20, 2u);
  sub_854710(&v22, 0);
  sub_854930(&g_targetPos, 0);
  sub_854710(&v22, 1u);
  sub_854930(&g_targetPos, 1u);
  sub_854710(&v22, 2u);
  sub_854930(&g_targetPos, 2u);
  sub_854710(&v20, 0);
  sub_854930(&g_cameraPos, 0);
  sub_854710(&v20, 1u);
  sub_854930(&g_cameraPos, 1u);
  sub_854710(&v20, 2u);
  sub_854930(&g_cameraPos, 2u);
  if (fldGb->fieldID < 11)
    goto LABEL_52;
  MotionMinorNum = GetMotionMinorNum();
  if (MotionMinorNum)
  {
    if (MotionMinorNum != 9)
    {
LABEL_52:
      fldPlayerFastSet();
    }
  }
  if (fldGb->fieldID > 9)
  {
    resetCamNormal();
    goto LABEL_41;
  }
LABEL_37:
  resetCamWM_Sub(0.0);
LABEL_41:
  fldGetFollowCameraControl();
  MakeWarpIndex_21489856(0, "01cam_01");
  return 1;
}

// 0x102f6b0
s32 fldCommand_SET_FIX_CAMERA(void) {
  s32 IntPara;
  dds3Basic_t_o *v5;
  dds3Basic_t_o *v7;
  s64 p_campos;
  struct UnityEngine_Vector4_o *v10;
  struct UnityEngine_Vector4_o *v11;
  s32 cammode;
  System_String_o *name;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  pBasic = dds3GetControlScene();
  IntPara = scrGetIntPara(0);
  v5 = dds3SearchSceneBasic(&pBasic, IntPara, 4u);
  if (v5)
  {
    v7 = v5;
    fldGb->cammode = 1;
    p_campos = &fldGb->campos;
    sub_854710(&v7->poseset->pos, 0);
    sub_854930(p_campos, 0);
    v10 = &fldGb->campos;
    sub_854710(&v7->poseset->pos, 1u);
    sub_854930(v10, 1u);
    v11 = &fldGb->campos;
    sub_854710(&v7->poseset->pos, 2u);
    sub_854930(v11, 2u);
    resetCamTgtPlayer();
    cammode = fldGb->cammode;
    name = v7->name;
    MakeWarpIndex_21489856(cammode, name);
  }
  else
  {
    Write("定点カメラERR:カメラリソースが見付からない\n", 0);
  }
  return 1;
}

// 0x102fe20
s32 fldCommand_SET_LOCK_CAMERA(void) {
  fldGb->cammode = 3;
  return 1;
}

// 0x10306c0
s32 fldCommand_SET_NPC_CAMERA(void) {
  System_String_o *StrPara;

  StrPara = scrGetStrPara(0);
  fldGb->cammode = 5;
  fldGb->cammode5name = StrPara;
  return 1;
}

// 0x1030970
void fldPanelSet(s32 mode) {
  ;
}
