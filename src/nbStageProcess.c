#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3MoverBasicObjFunc_t dds3MoverBasicObjFunc_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fldResourceLight_t fldResourceLight_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbStageProcessData_t nbStageProcessData_t;

static fldResourceLight_t *nbBaseUnitLight;
static nbStageProcessData_t *StageData;
static dds3Effect_Blur_t *fldAmaraBlurBuff;
static bool setenv;
static char *nbSetNiidaCamera_name;
static char *nbSetEventCamera_name;
static bool gStageBlockMode;

void BtlDispOn(dds3DefaultMain *this);
void CalcBloom(void);
void CalcShadow(void);
void FieldArea_Alpha(s32 fld, s32 area);
void FieldClsStop(void);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
f32 SDF_DEGtoRAD(f32 n);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetBattleLight(nbMainProcessData_t **data);
void StageFree(void);
void StageLoad(void);
void UnloadAB(AssetBundleCtrl *this, char *key);
dds3Basic_t *dds3AddCameraObjectBasicTypeFree(u32 serialID, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddLightObjectBasic(u32 serial);
f32 dds3CameraObjectBasicGetFovy(dds3Basic_t **pBasic);
void dds3CameraObjectBasicSetFovy(dds3Basic_t **pBasic, f32 fovy);
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID);
void dds3FadeColorSet(u32 r, u32 g, u32 b);
void dds3FadeIn2(u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetControlScene(void);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
s32 dds3ObjectBaseSetPadControl(dds3Basic_t **pObjectBasic, dds3MoverBasicObjFunc_t *pFuncPadControl);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
u32 dds3SerializeID(void);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetBasicName(dds3Basic_t **basic, char *name);
void dds3SetLightObjectResoruce(dds3Basic_t **basic, fldResourceLight_t *resource);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3SetScreenFovy(f32 fovy);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 encChk(void);
void evtFreeStage(void);
s32 evtLoadArea(s32 fld, s32 area);
void fldSkyBattle(void);
void fldSkyCalcFilter(void);
void fldSkyCalcTable(void);
void fldSkyDrawFilter(void);
void fldSkySetAlpha(s32 alp);
void fldSkySet_RgbPar(s32 par);
nbMainProcessData_t *nbGetMainProcessData(void);
void nbSetEventCamera(nbMainProcessData_t **data);
void nbSetNiidaCamera(nbMainProcessData_t **data);
void nbStageSp(void);

// 0x1582fb0
void FieldClsStop(void) {
  nbStageProcess_c *v2;

  {
          v2 = nbStageProcess,
    {
            v2 = nbStageProcess,
      {
              v2 = nbStageProcess,
        {
        }
      }
    }
  }
}

// 0x1582870
void SetBattleLight(nbMainProcessData_t **data) {
    dds3GetControlScene();
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    dds3SerializeID();
    dds3AddLightObjectBasic(0);
    dds3SetLightObjectResoruce(0, 0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
}

// 0x15827d0
void SetSceneEnv(void) {
  fldSkyBattle();
  setenv = 1;
}

// 0x1583640
void StageFree(void) {
    UnloadAB(0, 0);
    nbGetMainProcessData();
    evtFreeStage();
}

// 0x15830d0
void StageLoad(void) {
    nbGetMainProcessData();
    IsLoad(0, 0);
    FieldClsStop();
    evtLoadArea(0, 0);
    dds3GetActiveScene();
    dds3GetActiveCameraSceneBasic(0);
    SDF_DEGtoRAD(0);
    dds3CameraObjectBasicSetFovy(0, 0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromEuler(0, 0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3CameraObjectBasicGetFovy(0);
    dds3SetScreenFovy(0);
    nbSetNiidaCamera(0);
    nbSetEventCamera(0);
    dds3SetActiveCameraSceneBasic(0, 0);
    SetBattleLight(0);
    fldSkyBattle();
    Load(0, 0);
    BtlDispOn(0);
}

// 0x1583060
void StageLoad_BlockMode(bool mode) {
  gStageBlockMode = mode;
}

// 0x1581f80
void evtFreeAllUnit(void) {
  ;
}

// 0x1581fa0
void evtFreeStage(void) {
  ;
}

// 0x1582f40
s32 nbGetStageStat(void) {
  return StageData->now;
}

// 0x1583b20
void nbInitStageProcess(nbMainProcessData_t **data) {
  u64 *v3;
  u64 *v4;
  u64 *v7;
  u64 *v8;
  u64 *v10;
  dds3ProcessID_t_o *started;
  dds3ProcessID_t_o *target;

  v3 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v3);
  target = v3;
  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  started = v4;
  StageData->stat = 0;
  StageData->now = 0;
  StageData->req = 0;
  StageData->major = 0;
  StageData->minor = 0;
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_nbStageProcess_nbStageProcess1__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_nbStageProcess_nbStageShutdown__);
  target = dds3StartProcess(StringLiteral_21600, 0x3F9u, 1, 1, v7, 0, v8, 0, 0, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->StageProcessID = target;
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_nbStageProcess_nbStageDrawProcess1__);
  started = dds3StartProcess(StringLiteral_21601, 0x2B0Eu, 1, 1, v10, 0, 0, 0, 0, 0);
  dds3LinkProcess(&target, &started);
  else if (encChk())
  {
    return;
  }
  dds3FadeOut(0, 0, 0, 0);
}

// 0x1582c10
void nbSetEventCamera(nbMainProcessData_t **data) {
    dds3SerializeID();
    dds3AddCameraObjectBasicTypeFree(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetRadiusPoseSet(0, 0);
    dds3ObjectBaseCreateMover(0);
    dds3ObjectBaseSetPadControl(0, 0);
    SDF_DEGtoRAD(0);
    dds3CameraObjectBasicSetFovy(0, 0);
}

// 0x1582a70
void nbSetNiidaCamera(nbMainProcessData_t **data) {
    dds3SerializeID();
    dds3AddCameraObjectBasicTypeFree(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetRadiusPoseSet(0, 0);
    dds3ObjectBaseCreateMover(0);
    dds3ObjectBaseSetPadControl(0, 0);
    SDF_DEGtoRAD(0);
    dds3CameraObjectBasicSetFovy(0, 0);
}

// 0x1583dc0
void nbStageBlurAlp(s32 alp) {
  StageData->bluralp = alp;
}

// 0x1583a20
void *nbStageDrawProcess1(dds3ProcessID_t *id) {
  if (StageData->now == 1)
  {
    fldSkyCalcTable();
    fldSkyCalcFilter();
    fldSkyDrawFilter();
    nbStageSp();
    CalcShadow();
    CalcBloom();
  }
  return 0;
}

// 0x157d180
void nbStageFilterAlp(s32 alp) {
  fldSkySetAlpha(alp);
}

// 0x1582ea0
void nbStageFree(void) {
  StageData->major = 0;
  StageData->minor = 0;
  StageData->stat = 0;
  StageData->now = 3;
  StageData->bluralp = 0;
}

// 0x1582db0
void nbStageLoad(s32 major, s32 minor) {
  u16 v3;
  s16 v4;
  struct nbStageProcessData_t_o *StageData;
  s32 v7;
  s32 v8;

  v3 = minor;
  v4 = major;
  StageData->major = v4;
  StageData->minor = v3;
  StageData->stat = 0;
  StageData->now = 2;
  StageData->bluralp = 128;
  v7 = StageData->major;
  v8 = StageData->minor;
  FieldArea_Alpha(v7, v8);
}

// 0x15837a0
void *nbStageProcess1(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  u64 v4;
  s32 v5;
  struct nbStageProcessData_t_o *StageData;

  MainProcessData = nbGetMainProcessData();
  v5 = *(*(*(v4 + 184) + 8LL) + 17LL);
  if (v5 == 3)
  {
    if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
    StageFree(v4);
    return 0;
  }
  else
  {
    if (v5 != 2)
      return 0;
    if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
    StageLoad(v4);
    if (StageData->stat != 3)
      return 0;
    StageData->now = 1;
    if ((MainProcessData->stat & 0x800) != 0)
      return 0;
    if (!encChk())
    {
      dds3FadeColorSet(0, 0, 0);
      dds3FadeIn2(0xFu);
      return 0;
    }
    else
    {
      return 0;
    }
  }
}

// 0x1583950
void *nbStageShutdown(dds3ProcessID_t *id) {
  nbGetMainProcessData()->StageProcessID = 0;
  StageFree();
  StageData->now = 0;
  fldSkySet_RgbPar(0);
  return 0;
}

// 0x1581fb0
void nbStageSp(void) {
    dds3EffectBlur(0, 0, 0);
}

// 0x1581f90
s32 sdfDelayedResrcCheck(void) {
  return 0;
}
