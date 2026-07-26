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
    }
    v19 = 0;
  }
  ProcessID = scrGetScriptHandle()->ProcessID;
  v11 = fldEveHitResID_Find(ProcessID);
  v12 = dds3SearchSceneBasic(&pBasic, v11, 0x11u);
  if (!v12)
  v14 = v12;
  IntPara = scrGetIntPara(0);
  fldInputPanelSetMessage(IntPara);
  fldInputPanelSetDraw(1);
  v18 = fldInputPanelCheckKey();
  if (v18 != -1)
  {
    if (v18 == 1)
    {
      v19 = 1;
    }
  }
  v19 = -1;
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
    }
    v19 = 0;
  }
  ProcessID = scrGetScriptHandle()->ProcessID;
  v11 = fldEveHitResID_Find(ProcessID);
  v12 = dds3SearchSceneBasic(&pBasic, v11, 0x11u);
  if (!v12)
  v14 = v12;
  IntPara = scrGetIntPara(0);
  fldInputPanelSetMessage(IntPara);
  fldInputPanelSetDraw(1);
  v18 = fldInputPanelCheckKey();
  if (v18 != -1)
  {
    if (v18 == 1)
    {
      v19 = 1;
    }
  }
  v19 = -1;
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
    scrGetIntPara(0);
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    resetCamNormal();
    return 0;
}

// 0x1030310
s32 fldCommand_CAM_SEL_PHOKAN(void) {
    scrGetIntPara(0);
    fldGetUnitFollowCamera();
    dds3GetActiveScene();
    dds3SetActiveCameraSceneBasic(0, 0);
    dds3CameraObjectBasicGetTgtCam(0, 0, 0);
    hokanCamStart();
    dds3SearchSceneBasic(0, 0, 0);
    return 0;
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
        {
          v16 = 0;
        }
      }
      else
      {
      }
    }
    {
    }
  }
  {
  }
  v16 = 1;
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);

  {
    v7 = fldGb->areaID + 1;
    {
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
    }
  }
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);
  v7 = fldGb->areaID + 1;
  {
  }
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
          case 1:
            v40 = 4;
          case 0:
            v40 = 3;
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);

  {
    v7 = fldGb->areaID + 1;
    {
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
    }
  }
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);
  v7 = fldGb->areaID + 1;
  {
  }
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
          case 1:
            v39 = 1;
          case 2:
            v39 = 2;
          case 3:
            v39 = 6;
          case 4:
            v39 = 7;
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);

  {
    v7 = fldGb->areaID + 1;
    {
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
    }
  }
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);
  v7 = fldGb->areaID + 1;
  {
  }
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);
  v7 = fldGb->areaID + 1;
  {
  }
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
    scrGetIntPara(0);
    fldBgmPlay();
    return 0;
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

  Write(StringLiteral_16596, 0);
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
    evtGetAgeOfMoon();
    dds3GetRandIntA(0, 0);
    scrSetIntReturnValue(0);
    return 0;
}

// 0x1037f60
s32 fldCommand_FLD_GET_KIRETA(void) {
    scrGetIntPara(0);
    scrSetIntReturnValue(0);
    return 0;
}

// 0x10357f0
s32 fldCommand_FLD_GET_TAKARA_TBL(void) {
    scrGetScriptHandle();
    fldEveHitTakaraIdx_Find(0);
    scrGetIntPara(0);
    scrSetIntReturnValue(0);
    return 0;
}

// 0x1035080
s32 fldCommand_FLD_GIMIC_HOJI(void) {
    scrGetIntPara(0);
    fldGbSetGimic(0, 0, 0, 0);
    return 0;
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);

  {
    v7 = fldGb->areaID + 1;
    {
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
    }
  }
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
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
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);

  {
    v7 = fldGb->areaID + 1;
    {
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
    }
  }
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
  v12 = v9;
  fldAutoMapOpenBlock2(IntPara, v7, v12);
  return 1;
}

// 0x10383c0
s32 fldCommand_FLD_MODEL_DANTE(void) {
    scrSetIntReturnValue(0);
    return 0;
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
    scrGetIntPara(0);
    scrGetStrPara(0);
    fldCommand_GetHojiID(0);
    fldGbSetView(0, 0, 0, 0);
    dds3GetControlScene();
    dds3SceneBasicGetList(0, 0);
    dds3GetBasicArrayCount(0);
    dds3SetFirstBasicArray(0);
    dds3GetBasicArray(0);
    dds3MatterObjectBasicSetAlpMode(0, 0);
    dds3SetNextBasicArray(0);
    dds3FreeBasicArrayHandle(0);
    return 0;
}

// 0x1033ab0
s32 fldCommand_FLD_MODEL_OFF2(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;

  IntPara = scrGetIntPara(0);
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);

  {
    v7 = fldGb->areaID + 1;
    {
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
    }
  }
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
  v12 = v9;
  fldGbSetEView(IntPara, v7, v12, 1);
  return 1;
}

// 0x1031010
s32 fldCommand_FLD_MODEL_ON(void) {
    scrGetIntPara(0);
    scrGetStrPara(0);
    fldCommand_GetHojiID(0);
    fldGbSetView(0, 0, 0, 0);
    dds3GetControlScene();
    dds3SceneBasicGetList(0, 0);
    dds3GetBasicArrayCount(0);
    dds3SetFirstBasicArray(0);
    dds3GetBasicArray(0);
    dds3MatterObjectBasicSetAlpMode(0, 0);
    dds3SetNextBasicArray(0);
    dds3FreeBasicArrayHandle(0);
    return 0;
}

// 0x1033910
s32 fldCommand_FLD_MODEL_ON2(void) {
  s32 IntPara;
  s32 v7;
  s32 v9;
  s32 v12;

  IntPara = scrGetIntPara(0);
  IntPara = fldGb->fieldID;
  {
  }
  v7 = scrGetIntPara(1);

  {
    v7 = fldGb->areaID + 1;
    {
      v9 = scrGetIntPara(2);
      if (!v9)
        return 1;
    }
  }
  v9 = scrGetIntPara(2);
  if (!v9)
    return 1;
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
    scrGetIntPara(0);
    scrGetStrPara(0);
    fldCommand_GetHojiID(0);
    fldGbSetNpc(0, 0, 0, 0);
    fldNpcHojiRefresh();
    return 0;
}

// 0x10344a0
s32 fldCommand_FLD_NPC_ON(void) {
    scrGetIntPara(0);
    scrGetStrPara(0);
    fldCommand_GetHojiID(0);
    fldGbSetNpc(0, 0, 0, 0);
    fldNpcHojiRefresh();
    return 0;
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
    scrGetIntPara(0);
    evtBitCheck(0);
    dds3GetRandIntA(0, 0);
    scrSetIntReturnValue(0);
    return 0;
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
    fldDoor_ChkWarp();
    fldDoor_Warp(0);
    scrGetScriptHandle();
    fldEveHitResName_Find(0);
    return 0;
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
    fldDoor_ChkWarp();
    scrGetScriptHandle();
    fldEveHitResID_Find(0);
    fldDoorRun_FindStart(0);
    return 0;
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

  v3 = StrStr(*pName, StringLiteral_16589);
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
  v8 = Format(StringLiteral_16588, *pName, 0);
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
        v8 = scrGetIntPara(1);
        fldLoadNextFile(IntPara, v8);
        return 1;
      }
    }
    else
    {
      IntPara = fldGb->fieldID;
    }
  }
  return 1;
}

// 0x102f900
s32 fldCommand_SET_CHASE_CAMERA(void) {
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    GetMotionMinorNum();
    fldPlayerFastSet();
    resetCamNormal();
    resetCamWM_Sub(0);
    fldGetFollowCameraControl();
    MakeWarpIndex_21489856(0, 0);
    return 0;
}

// 0x102f6b0
s32 fldCommand_SET_FIX_CAMERA(void) {
    dds3GetControlScene();
    scrGetIntPara(0);
    dds3SearchSceneBasic(0, 0, 0);
    resetCamTgtPlayer();
    MakeWarpIndex_21489856(0, 0);
    return 0;
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
