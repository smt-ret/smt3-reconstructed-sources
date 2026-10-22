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
  dds3Basic_t_o *ControlScene;
  nbMainProcessData_t_o *v7;
  u32 v8;
  dds3Basic_t_o **p_baselight;
  nbMainProcessData_t_o *v12;
  u32 v13;
  dds3Basic_t_o **p_niidalight;
  UnityEngine_Vector4_o v17;

  *&v17.x = 0;
  *&v17.z = 0;
  sub_854690(&v17.x, -1000.0, 0.0, 0.0, 0.0);
  ControlScene = dds3GetControlScene();
  if (!dds3SceneBasicSearchNameAndType(ControlScene, 9u, "BTL_DEF_LIGHT"))
  {
    v7 = *data;
    v8 = dds3SerializeID();
    v7->baselight = dds3AddLightObjectBasic(v8);
    p_baselight = &(*data)->baselight;
    dds3SetLightObjectResoruce(p_baselight, nbBaseUnitLight);
    dds3SetPosPoseSet(&(*data)->baselight, v17, 0);
    dds3SetBasicName(&(*data)->baselight, "BTL_DEF_LIGHT", 0);
  }
  v12 = *data;
  v13 = dds3SerializeID();
  v12->niidalight = dds3AddLightObjectBasic(v13);
  p_niidalight = &(*data)->niidalight;
  dds3SetLightObjectResoruce(p_niidalight, nbBaseUnitLight);
}

// 0x15827d0
void SetSceneEnv(void) {
  fldSkyBattle();
  setenv = 1;
}

// 0x1583640
void StageFree(void) {
  u64 *v3;
  System_String_o *v5;
  AssetBundleCtrl_o *asset_bc;
  nbMainProcessData_t_o *MainProcessData;
  s16 major;

  major = StageData->major;
  v3 = sub_8D3950(s16, &major);
  v5 = Format("f{0:D3}", v3, 0);
  asset_bc = get_asset_bc();
  UnloadAB(asset_bc, v5);
  MainProcessData = nbGetMainProcessData();
  evtFreeStage();
  StageData->major = 0;
  StageData->minor = 0;
  *&MainProcessData->StageMajor = 0;
  StageData->now = 0;
}

// 0x15830d0
void StageLoad(void) {
  nbMainProcessData_t_o *MainProcessData;
  u64 *v5;
  System_String_o *v7;
  struct nbStageProcess_StaticFields **p_static_fields;
  struct nbStageProcessData_t_o *StageData;
  s32 stat;
  AssetBundleCtrl_o *v13;
  AssetBundleCtrl_o *asset_bc;
  struct nbStageProcessData_t_o *v18;
  s32 v19;
  s32 minor;
  f32 v24;
  s64 v26;
  s64 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 Fovy;
  s16 major;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *ActiveCameraSceneBasic;
  nbMainProcessData_t_o *data;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v44;
  s64 v45;
  s64 v46;
  UnityEngine_Vector4_o v47;

  v45 = 0;
  v46 = 0;
  *&v44.x = 0;
  *&v44.z = 0;
  pBasic = 0;
  *&p.x = 0;
  *&p.z = 0;
  ActiveCameraSceneBasic = 0;
  data = 0;
  sub_854690(&v45, 213.0, -276.67, -636.84, 0.0);
  sub_854690(&v44.x, 0.0, 0.0, 1.0, 1.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  MainProcessData = nbGetMainProcessData();
  data = MainProcessData;
  major = StageData->major;
  v5 = sub_8D3950(s16, &major);
  v7 = Format("f{0:D3}", v5, 0);
  stat = StageData->stat;
  if (StageData->stat)
  {
    if (stat == 1)
    {
      asset_bc = get_asset_bc();
      if (IsLoad(asset_bc, v7))
      {
        *(v16[2].klass->_1.gc_desc + 16) = 2;
        FieldClsStop();
        v18 = StageData;
        v19 = v18->major;
        minor = v18->minor;
        evtLoadArea(v19, minor);
        pBasic = dds3GetActiveScene();
        ActiveCameraSceneBasic = dds3GetActiveCameraSceneBasic(&pBasic);
        v24 = SDF_DEGtoRAD(50.0);
        dds3CameraObjectBasicSetFovy(&ActiveCameraSceneBasic, v24);
        v26 = v45;
        v27 = v46;
        *&v47.x = v26;
        *&v47.z = v27;
        dds3SetPosPoseSet(&ActiveCameraSceneBasic, v47);
        SDF_VU0__LOADVECTOR(v44);
        v28 = SDF_DEGtoRAD(-15.0);
        v29 = SDF_DEGtoRAD(-20.0);
        v30 = SDF_DEGtoRAD(0.0);
        FromEuler(v28, v29, v30);
        SDF_VU0__STOREVECTOR(&p);
        dds3SetRotPoseSet(&ActiveCameraSceneBasic, p);
        dds3CameraObjectBasicSetFovy(&ActiveCameraSceneBasic, 0.69813);
        dds3CameraObjectBasicGetFovy(&ActiveCameraSceneBasic);
        Fovy = dds3CameraObjectBasicGetFovy(&ActiveCameraSceneBasic);
        dds3SetScreenFovy(Fovy);
        nbSetNiidaCamera(&data);
        nbSetEventCamera(&data);
        dds3SetActiveCameraSceneBasic(&pBasic, &MainProcessData->niidacamera);
        SetBattleLight(&data);
        fldSkyBattle();
        setenv = 1;
      }
    }
    else if (stat == 2)
    {
      StageData->stat = 3;
      MainProcessData->StageMajor = (*p_static_fields)->StageData->major;
      MainProcessData->StageMinor = (*p_static_fields)->StageData->minor;
    }
  }
  else
  {
    if (!gStageBlockMode)
    {
      StageData->stat = 1;
      v13 = get_asset_bc();
      Load(v13, v7, v7, 0);
      BtlDispOn(kernelObject);
    }
  }
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
  target = dds3StartProcess("nb_stage", 0x3F9u, 1, 1, v7, 0, v8, 0, 0, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->StageProcessID = target;
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_nbStageProcess_nbStageDrawProcess1__);
  started = dds3StartProcess("nb_draw_stage", 0x2B0Eu, 1, 1, v10, 0, 0, 0, 0, 0);
  dds3LinkProcess(&target, &started);
  else if (encChk())
  {
    return;
  }
  dds3FadeOut(0, 0, 0, 0);
}

// 0x1582c10
void nbSetEventCamera(nbMainProcessData_t **data) {
  u32 v4;
  dds3Basic_t_o *v6;
  f32 v9;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v11;
  UnityEngine_Vector4_o v12;

  *&v12.x = 0;
  *&v12.z = 0;
  pBasic = 0;
  *&v11.x = 0;
  *&v11.z = 0;
  sub_854690(&v12.x, 0.0, -100.0, -600.0, 0.0);
  sub_854690(&v11.x, 0.0, 0.0, 0.0, 1.0);
  v4 = dds3SerializeID();
  v6 = dds3AddCameraObjectBasicTypeFree(v4, v12, v11);
  pBasic = v6;
  v6->name = nbSetEventCamera_name;
  dds3SetRadiusPoseSet(&pBasic, 10.0);
  dds3ObjectBaseCreateMover(&pBasic);
  dds3ObjectBaseSetPadControl(&pBasic, 0);
  v9 = SDF_DEGtoRAD(40.0);
  dds3CameraObjectBasicSetFovy(&pBasic, v9);
  (*data)->eventcamera = pBasic;
}

// 0x1582a70
void nbSetNiidaCamera(nbMainProcessData_t **data) {
  u32 v4;
  dds3Basic_t_o *v6;
  f32 v9;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v11;
  UnityEngine_Vector4_o v12;

  *&v12.x = 0;
  *&v12.z = 0;
  pBasic = 0;
  *&v11.x = 0;
  *&v11.z = 0;
  sub_854690(&v12.x, 0.0, -100.0, -600.0, 0.0);
  sub_854690(&v11.x, 0.0, 0.0, 0.0, 1.0);
  v4 = dds3SerializeID();
  v6 = dds3AddCameraObjectBasicTypeFree(v4, v12, v11);
  pBasic = v6;
  v6->name = nbSetNiidaCamera_name;
  dds3SetRadiusPoseSet(&pBasic, 10.0);
  dds3ObjectBaseCreateMover(&pBasic);
  dds3ObjectBaseSetPadControl(&pBasic, 0);
  v9 = SDF_DEGtoRAD(50.0);
  dds3CameraObjectBasicSetFovy(&pBasic, v9);
  (*data)->niidacamera = pBasic;
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
    StageFree(v4);
    return 0;
  }
  else
  {
    if (v5 != 2)
      return 0;
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
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v4;
  s32 fieldID;
  nbStageProcess_c *v6;
  u32 v8;
  signed s32 v9;
  struct dds3Effect_Blur_t_o *fldAmaraBlurBuff;
  s32 v11;
  u32 bluralp;
  u32 v16;
  struct fldGlobalWork_t_o *v17;
  struct fldGlobalWork_t_o *v18;
  struct fldGlobalWork_t_o *v19;
  struct System_Int32_array *pm;
  struct System_Int32_array *v22;
  struct fldGlobalWork_t_o *v24;
  struct fldGlobalWork_t_o *v26;
  struct fldGlobalWork_t_o *v27;
  f32 v29;
  s32 v30;
  struct fldGlobalWork_t_o *v31;

  if (fldGb->fieldID == 215)
  {
    else if (fldGb->areaID)
    {
      goto LABEL_10;
    }
    v9 = (30 * StageData->bluralp) >> 7;
    if (v9)
    {
      v11 = 6589590;
      goto LABEL_90;
    }
    return;
  }
LABEL_10:
  v4 = fldGb;
  fieldID = v4->fieldID;
  if (fieldID != 218)
  {
    else if (fieldID == 216)
    {
      goto LABEL_25;
    }
    else if (fieldID != 202)
    {
      goto LABEL_58;
    }
    if (!v4->areaID)
    {
      v16 = StageData->bluralp;
      if ((v16 & 0xFFFFFF8) == 0)
        return;
      v9 = v16 >> 3;
      if ((v6->_2.bitflags2 & 2) == 0)
        goto LABEL_89;
      goto LABEL_87;
    }
LABEL_58:
    v17 = fldGb;
    if (v17->fieldID == 224)
    {
      if (v17->areaID == 2)
        goto LABEL_82;
    }
    v18 = fldGb;
    if (v18->fieldID == 224)
    {
      if (v18->areaID == 5)
        goto LABEL_82;
    }
    v19 = fldGb;
    if (v19->fieldID != 232)
      goto LABEL_160;
    if (v19->areaID == 1)
    {
LABEL_82:
      v9 = (30 * StageData->bluralp) >> 7;
      if (!v9)
        return;
    }
    else
    {
LABEL_160:
      v24 = fldGb;
      if (v24->fieldID == 232)
      {
        if (v24->areaID == 1)
        {
          v9 = (30 * StageData->bluralp) >> 7;
          if (v9)
          {
            v11 = 11835010;
            goto LABEL_90;
          }
          return;
        }
      }
      v26 = fldGb;
      if (v26->fieldID == 234)
      {
        if (!v26->areaID)
        {
          v9 = (30 * StageData->bluralp) >> 7;
          if (!v9)
            return;
LABEL_30:
          v11 = 9876680;
          goto LABEL_90;
        }
      }
      v27 = fldGb;
      if (v27->fieldID == 223)
      {
        if (v27->areaID == 2)
        {
          v29 = ((30 * StageData->bluralp) >> 7);
          v30 = (v29 + v29);
          if (v30 >= 128)
            LOBYTE(v9) = 0x80;
          else
            LOBYTE(v9) = (v29 + v29);
          if (v30 >= 1)
          {
            v11 = 2650752;
            goto LABEL_90;
          }
          return;
        }
      }
      v31 = fldGb;
      if (v31->fieldID != 240)
        return;
      if (v31->areaID)
        return;
      v9 = (((30 * StageData->bluralp) >> 7) * 0.6);
      if (v9 < 1)
        return;
    }
    if ((v6->_2.bitflags2 & 2) == 0)
    {
LABEL_89:
      v11 = 8558260;
LABEL_90:
      fldAmaraBlurBuff->abgr = v11 & 0xFFFFFF | (v9 << 24);
      fldAmaraBlurBuff->blend = 1;
      fldAmaraBlurBuff->rotate = 0.0;
      fldAmaraBlurBuff->scale = 1.0;
      pm = fldAmaraBlurBuff->center->pm;
      pm->m_Items[0] = 0;
      v22 = fldAmaraBlurBuff->center->pm;
      v22->m_Items[1] = 0;
      dds3EffectBlur(&fldAmaraBlurBuff, 0, 0);
      return;
    }
LABEL_87:
    goto LABEL_89;
  }
  v8 = StageData->bluralp;
  if ((v8 & 0xFFFFFF8) != 0)
  {
    v9 = v8 >> 3;
    v11 = 13145800;
    goto LABEL_90;
  }
}

// 0x1581f90
s32 sdfDelayedResrcCheck(void) {
  return 0;
}
