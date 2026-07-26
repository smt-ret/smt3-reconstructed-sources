#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3MoverBasicObjFunc_t dds3MoverBasicObjFunc_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effHandle_t effHandle_t;
typedef struct sdf3DFogParam_t sdf3DFogParam_t;
typedef struct sdf3DLight_t sdf3DLight_t;

static sdfVector4_t UnitInitPosRot;
static sdf3DLight_t *fld_default_light[3];
static sdf3DFogParam_t *fld_default_fog;
static sdfVector4_t fld_default_ambient;
static sdf3DLight_t fld_light_dst[UNKNOWN_ARRAY_SIZE];
static sdf3DFogParam_t *fld_fog_dst;
static sdfVector4_t fld_ambient_dst;
static char *evtStartEvent_path;
static s32 evtStartEvent_no;
static char *evtStartEvent_name;
static s32 process;
static void *m_head;
static void *m_akey;
static void *m_aname;
static void *m_tkey;
static void *m_tname;

void AttachModel(dds3Basic_t *basic, s32 major, s32 minor);
void FromRotation(f32 aAngle);
char *GetAppendix(void);
char *GetDLCTag(s32 eventno);
EventEMsgData *GetData(char *key);
char *GetEventFileNameToAssetName(char *filename);
char *GetFieldAssetName(char *fmt, s32 field);
bool IsLoad(AssetBundles *this, char *key);
bool IsNoText_26552416(char *eventno);
void LoadAssetExt(char *key, char *name, char *dlc);
void LoadEventData(char *key, s32 e, bool ecmnf);
void LoadEventVoice(s32 eventno, char *key, EventEMsgData *data);
void LoadKeys(s32 type, char *key, char *path);
void Log(char *fmt, void **parray);
void Mult(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetBoostFrameRate(dds3DefaultMain *this);
void SetNormalFrameRate(dds3DefaultMain *this);
bool SpEvtCheckLoad(s32 eventno);
s32 SpEvtLoadFinished(void);
dds3Basic_t *dds3AddCameraObjectBasicTypeFree(u32 serialID, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddScene(void);
dds3Basic_t *dds3AddUnitObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot);
void dds3DeleteScene(dds3Basic_t **scene);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3EffectSetLoop(effHandle_t **hEffect, u8 loop);
dds3Basic_t *dds3GetActiveScene(void);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
s32 dds3GetProcessCount(u32 type);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
dds3PathBasicControl_t *dds3MoverBasicGetPathControl(dds3Basic_t **pMoverBasic);
void dds3MoverBasicMakePath(dds3Basic_t **pMoverBasic);
void dds3MoverBasicSetPath(dds3Basic_t **pMoverBasic, dds3Basic_t **pPathBasic);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3ObjectBaseGetControlBasic(dds3Basic_t **pObjectBasic, u32 itemType);
void *dds3ObjectBaseGetModelHandle(dds3Basic_t **pObjectBasic);
dds3PathBasicControl_t *dds3ObjectBaseGetPathControl(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseMakeUnit(dds3Basic_t **pObjectBasic, s32 major, s32 minor);
void dds3ObjectBaseMatterAnimeSpeed(dds3Basic_t **pObjectBasic, s32 mode);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
s32 dds3ObjectBaseRegistArea(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3ObjectBaseSetControlBasic(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic);
s32 dds3ObjectBaseSetPadControl(dds3Basic_t **pObjectBasic, dds3MoverBasicObjFunc_t *pFuncPadControl);
void dds3PathBasicControlAlterMode(dds3PathBasicControl_t **pControl, u32 mode);
f32 dds3PathBasicControlGetRatio(dds3PathBasicControl_t **pControl);
void dds3PathBasicControlSetRatio(dds3PathBasicControl_t **pControl, f32 ratio);
void dds3PathBasicLoopOff(dds3PathBasicControl_t **pControl);
void dds3PathBasicLoopOn(dds3PathBasicControl_t **pControl);
u32 dds3PathBasicPathControlGetMode(dds3PathBasicControl_t **pControl);
void dds3PathBasicPause(dds3PathBasicControl_t **pControl);
void dds3PathBasicPauseOff(dds3PathBasicControl_t **pControl);
void dds3SceneBasicMakeScene(dds3Basic_t **pBasic, char *file, char *akey);
dds3ProcessID_t *dds3SearchProcessNumber(u32 type, s32 n);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
u32 dds3SerializeID(void);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetActiveScene(dds3Basic_t *scene);
void dds3SetAmbient(sdfVector4_t ambient);
void dds3SetControlScene(dds3Basic_t **scene);
void dds3SetFog(sdf3DFogParam_t *fog);
void dds3SetLight(sdf3DLight_t *light, u32 no);
void dds3SetMapNo(dds3Basic_t **scene, s32 mapno);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3SetScreenFovy(f32 fovy);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void evtFreeStage(void);
void evtSetTestCamera(void);
void fldMakeFilePath(char **pathstr, s32 field, s32 area);
void fldSetCharClr(void);
void mdlLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber);
dds3ProcessID_t *scrStartScript3(s32 priority, char *filename, s32 startproc, char *akey);
s32 sdfDelayedResrcCheck(void);

// 0x1952810
bool IsNoText(s32 eventno) {
  return (eventno - 699) <= 0x39 && ((1LL << (eventno + 69)) & 0x3F000000000000FLL) != 0
      || eventno == 610
      || eventno == 676
      || eventno == 810;
}

// 0x1952860
bool IsNoText_26552416(char *eventno) {
  System_String_o *v4;
  System_String_o *Appendix;
  System_String_o *v6;

  v4 = ToUpper(eventno, 0);
  Appendix = GetAppendix();
  v6 = Concat_5224608(StringLiteral_15997, Appendix);
  return op_Equality(v4, v6, 0);
}

// 0x1951c50
void *LoadEvent1(dds3ProcessID_t *id) {
    GetDLCTag(0);
    GetEventFileNameToAssetName(0);
    GetAppendix();
    SetBoostFrameRate(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    IsNoText_26552416(0);
    LoadEventData(0, 0, 0);
    SpEvtCheckLoad(0);
    SpEvtLoadFinished();
    Log(0, 0);
    LoadEventData(0, 0, 0);
    scrStartScript3(0, 0, 0, 0);
    dds3KillProcess(0, 0);
    SetNormalFrameRate(0);
    return 0;
}

// 0x1952900
void LoadEventData(char *key, s32 e, bool ecmnf) {
    Log(0, 0);
    GetDLCTag(0);
    LoadEventData(0, 0, 0);
    LoadKeys(0, 0, 0);
    GetData(0);
    LoadEventVoice(0, 0, 0);
}

// 0x1953110
dds3Basic_t *evtAddCamera(sdfVector4_t eye, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  u32 v12;
  dds3Basic_t_o *result;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = eye.w;
  v9 = eye.z;
  v10 = eye.y;
  v11 = eye.x;
  pBasic = 0;
  v12 = dds3SerializeID();
  v16.x = v11;
  v16.y = v10;
  v16.z = v9;
  v16.w = v8;
  v17.x = x;
  v17.y = y;
  v17.z = z;
  v17.w = w;
  result = dds3AddCameraObjectBasicTypeFree(v12, v16, v17);
  pBasic = result;
  if (result)
  {
    dds3SetRadiusPoseSet(&pBasic, 1.0);
    return pBasic;
  }
  return result;
}

// 0x1952fc0
s32 evtCheckPathStat(dds3Basic_t *obj) {
  u32 Mode;
  f32 v5;
  dds3PathBasicControl_t_o *PathControl;
  dds3Basic_t_o *pMoverBasic;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = obj;
  PathControl = 0;
  pMoverBasic = 0;
  if (!obj)
    return -1;
  pMoverBasic = dds3ObjectBaseGetControlBasic(&pObjectBasic, 1u);
  if (!pMoverBasic)
    return -1;
  PathControl = dds3MoverBasicGetPathControl(&pMoverBasic);
  if (!PathControl)
    return -1;
  Mode = dds3PathBasicPathControlGetMode(&PathControl);
  if (!Mode)
  {
    v5 = 1.0;
    return dds3PathBasicControlGetRatio(&PathControl) != v5;
  }
  if (Mode != 1)
    return -1;
  v5 = 0.0;
  return dds3PathBasicControlGetRatio(&PathControl) != v5;
}

// 0x1953220
void evtEffectLoopControl(dds3Basic_t *eff, s32 sw) {
    dds3EffectSetLoop(0, 0);
}

// 0x1950e30
void evtFreeAllUnit(void) {
    dds3GetControlScene();
    dds3DeleteSceneBasicData(0);
}

// 0x1950d90
void evtFreeStage(void) {
  dds3Basic_t_o *scene;

  scene = 0;
  scene = dds3GetControlScene();
  if (scene)
  {
    dds3DeleteScene(&scene);
  }
}

// 0x1952b70
void evtKillFieldScript(void) {
  u64 *v1;
  s32 v3;
  dds3ProcessID_t_o *v4;
  Il2CppObject *p_obj;
  s32 v8;
  dds3ProcessID_t_o *v10;
  Il2CppObject *v11;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  v3 = 0;
  while (1)
  {
    if (v3 >= dds3GetProcessCount(1u))
      break;
    v4 = dds3SearchProcessNumber(1u, v3);
    id = v4;
    ++v3;
    if (v4->priority == 1002)
    {
      p_obj = &v4->name->obj;
      Write_2930400(StringLiteral_15998, p_obj);
      dds3KillProcess(&id, 0);
      v3 = 0;
    }
  }
  v8 = 0;
  while (1)
  {
    if (v8 >= dds3GetProcessCount(2u))
      break;
    v10 = dds3SearchProcessNumber(2u, v8);
    id = v10;
    ++v8;
    if (v10->priority == 1002)
    {
      v11 = &v10->name->obj;
      Write_2930400(StringLiteral_15998, v11);
      dds3KillProcess(&id, 0);
    }
  }
}

// 0x1950ff0
s32 evtLoadArea(s32 fld, s32 area) {
    evtFreeStage();
    fldSetCharClr();
    dds3AddScene();
    dds3SetControlScene(0);
    dds3SetActiveScene(0);
    dds3SetMapNo(0, 0);
    fldMakeFilePath(0, 0, 0);
    GetFieldAssetName(0, 0);
    dds3SceneBasicMakeScene(0, 0, 0);
    evtSetTestCamera();
    dds3SetScreenFovy(0);
    dds3SetLight(0, 0);
    dds3SetFog(0);
    dds3SetAmbient((sdfVector4_t){0});
    return 0;
}

// 0x1951540
s32 evtLoadArea_FromMemory(s32 fld, s32 area, u8 **pF1, u8 **pF2, u8 **pTB, u8 **pBF) {
    evtFreeStage();
    dds3AddScene();
    dds3SetControlScene(0);
    dds3SetActiveScene(0);
    dds3SetMapNo(0, 0);
    fldMakeFilePath(0, 0, 0);
    dds3SceneBasicMakeScene(0, 0, 0);
    evtSetTestCamera();
    dds3SetScreenFovy(0);
    dds3SetLight(0, 0);
    dds3SetFog(0);
    dds3SetAmbient((sdfVector4_t){0});
    sdfDelayedResrcCheck();
    return 0;
}

// 0x1950290
s32 evtLoadUnit(s32 major, s32 minor) {
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3SetRadiusPoseSet(0, 0);
    dds3ObjectBaseMakeUnit(0, 0, 0);
    AttachModel(0, 0, 0);
    dds3ObjectBaseGetModelHandle(0);
    mdlLoopMotion(0, 0, 0);
    dds3GetControlScene();
    dds3SearchSceneBasic(0, 0, 0);
    dds3ObjectBaseSetControlBasic(0, 0);
    dds3ObjectBaseRegistArea(0);
    dds3ObjectBaseSetPadControl(0, 0);
    return 0;
}

// 0x1952e70
void evtPathDir(dds3Basic_t *basic, s32 dir) {
  dds3PathBasicControl_t_o *pControl;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = basic;
  pControl = dds3ObjectBaseGetPathControl(&pObjectBasic);
  if (pControl)
    dds3PathBasicControlAlterMode(&pControl, dir);
}

// 0x1952ec0
s32 evtPathLinkAndMake(dds3Basic_t *path, dds3Basic_t *obj) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *pMoverBasic;
  dds3Basic_t_o *pObjectBasic;
  dds3Basic_t_o *pPathBasic;

  pObjectBasic = obj;
  pPathBasic = path;
  pMoverBasic = 0;
  if (path)
  {
    BaseControlWorkData = dds3GetBaseControlWorkData(&pObjectBasic);
    if (BaseControlWorkData)
    {
      pBasic = BaseControlWorkData->pBasic;
      pMoverBasic = pBasic->m_Items[1];
      if (pMoverBasic)
      {
        dds3MoverBasicSetPath(&pMoverBasic, &pPathBasic);
        dds3MoverBasicMakePath(&pMoverBasic);
        LODWORD(BaseControlWorkData) = 1;
      }
      else
      {
        LODWORD(BaseControlWorkData) = 0;
      }
    }
  }
  else
  {
    LODWORD(BaseControlWorkData) = 0;
  }
  return BaseControlWorkData;
}

// 0x19530b0
void evtPathLoop(dds3Basic_t *basic, s32 sw) {
  dds3PathBasicControl_t_o *pControl;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = basic;
  pControl = dds3ObjectBaseGetPathControl(&pObjectBasic);
  if (pControl)
  {
    if (sw)
      dds3PathBasicLoopOn(&pControl);
    else
      dds3PathBasicLoopOff(&pControl);
  }
}

// 0x1952e10
void evtPathRate(dds3Basic_t *basic, f32 rate) {
  dds3PathBasicControl_t_o *pControl;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = basic;
  pControl = dds3ObjectBaseGetPathControl(&pObjectBasic);
  if (pControl)
    dds3PathBasicControlSetRatio(&pControl, fminf(fmaxf(rate, 0.0), 1.0), 0);
}

// 0x1952dd0
void evtPathStart(dds3Basic_t *basic) {
  dds3PathBasicControl_t_o *PathControl;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = basic;
  PathControl = dds3ObjectBaseGetPathControl(&pObjectBasic);
  if (PathControl)
    dds3PathBasicPauseOff(&PathControl);
}

// 0x1952d90
void evtPathStop(dds3Basic_t *basic) {
  dds3PathBasicControl_t_o *PathControl;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = basic;
  PathControl = dds3ObjectBaseGetPathControl(&pObjectBasic);
  if (PathControl)
    dds3PathBasicPause(&PathControl);
}

// 0x1950040
s32 evtSetRegistUnit(s32 major, s32 minor) {
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3SetRadiusPoseSet(0, 0);
    dds3ObjectBaseMakeUnit(0, 0, 0);
    dds3ObjectBaseGetModelHandle(0);
    mdlLoopMotion(0, 0, 0);
    dds3ObjectBaseSetPadControl(0, 0);
    return 0;
}

// 0x194fed0
void evtSetTestCamera(void) {
    dds3SerializeID();
    dds3AddCameraObjectBasicTypeFree(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetRadiusPoseSet(0, 0);
    dds3ObjectBaseCreateMover(0);
    dds3GetControlScene();
    dds3SetActiveCameraSceneBasic(0, 0);
    dds3ObjectBaseSetPadControl(0, 0);
}

// 0x1950b20
void evtSetUnitPos(s32 unitID, s32 posID) {
    dds3GetControlScene();
    dds3SearchSceneBasic(0, 0, 0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3GetPosPoseSet(0);
}

// 0x1953420
s32 evtStageAnimeControl(s32 type, s32 mode) {
    dds3GetActiveScene();
    dds3ObjectBaseMatterAnimeSpeed(0, 0);
    return 0;
}

// 0x1951ab0
void evtStartEvent(s32 no) {
    GetDLCTag(0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
}
