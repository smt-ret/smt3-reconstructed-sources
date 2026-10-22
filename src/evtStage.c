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
static sdf3DLight_t *fld_light_dst;
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
  v6 = Concat_5224608("E715M", Appendix);
  return op_Equality(v4, v6, 0);
}

// 0x1951c50
void *LoadEvent1(dds3ProcessID_t *id) {
  System_Text_StringBuilder_o *m_head;
  s32 evtStartEvent_no;
  System_String_o *DLCTag;
  System_Text_StringBuilder_o *m_akey;
  u64 *v10;
  System_Text_StringBuilder_o *v12;
  System_String_o *v13;
  System_Text_StringBuilder_o *m_aname;
  System_String_o *EventFileNameToAssetName;
  System_Text_StringBuilder_o *v18;
  System_String_o *v19;
  System_Text_StringBuilder_o *m_tkey;
  u64 *v22;
  System_Text_StringBuilder_o *v24;
  System_String_o *v25;
  System_Text_StringBuilder_o *v27;
  System_String_o *Appendix;
  System_Text_StringBuilder_o *m_tname;
  System_String_o *v31;
  System_Text_StringBuilder_o *v33;
  System_String_o *v34;
  System_Text_StringBuilder_o *v35;
  System_String_o *v36;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v43;
  bool IsLoad;
  AssetBundleCtrl_o *v49;
  System_String_o *v51;
  AssetBundleCtrl_o *v54;
  System_String_o *v56;
  bool v58;
  evtStage_c *v59;
  s32 v60;
  AssetBundleCtrl_o *v62;
  System_String_o *v64;
  System_String_o *v67;
  System_String_o *v69;
  s32 v70;
  s32 v71;
  bool v72;
  s32 v75;
  System_Object_array *v79;
  s64 *v83;
  s64 *v84;
  s64 *v89;
  s64 *v90;
  System_String_o *v93;
  System_Object_array *v95;
  System_String_o *v96;
  System_String_o *evtStartEvent_path;
  System_String_o *v101;
  System_String_o *v105;
  System_String_o *v106;
  System_String_o *v108;
  s32 v110;
  System_String_o *v111;
  bool IsNoText_26552416;
  System_String_o *v116;
  System_String_o *v117;
  System_String_o *v119;
  s32 v120;
  s32 v121;
  dds3ProcessID_t_o *ida;

  ida = id;
  Clear(m_head, 0);
  DLCTag = GetDLCTag(evtStartEvent_no);
  Append_5380272(m_head, DLCTag);
  Clear(m_akey, 0);
  v121 = evtStartEvent_no;
  v10 = sub_8D3950(s32, &v121);
  AppendFormat(m_akey, "e{0:D3}", v10);
  v12 = m_akey;
  v13 = (m_head->klass->vtable._3_ToString.methodPtr)(m_head, m_head->klass->vtable._3_ToString.method);
  Append_5380272(v12, v13);
  Clear(m_aname, 0);
  EventFileNameToAssetName = GetEventFileNameToAssetName(evtStartEvent_path);
  Append_5380272(m_aname, EventFileNameToAssetName);
  v18 = m_aname;
  v19 = (m_head->klass->vtable._3_ToString.methodPtr)(m_head, m_head->klass->vtable._3_ToString.method);
  Append_5380272(v18, v19);
  Clear(m_tkey, 0);
  v120 = evtStartEvent_no;
  v22 = sub_8D3950(s32, &v120);
  AppendFormat(m_tkey, "e{0:D3}", v22);
  v24 = m_tkey;
  v25 = (m_head->klass->vtable._3_ToString.methodPtr)(m_head, m_head->klass->vtable._3_ToString.method);
  Append_5380272(v24, v25);
  v27 = m_tkey;
  Appendix = GetAppendix();
  Append_5380272(v27, Appendix);
  Clear(m_tname, 0);
  v31 = GetEventFileNameToAssetName(evtStartEvent_path);
  Append_5380272(m_tname, v31);
  v33 = m_tname;
  v34 = (m_head->klass->vtable._3_ToString.methodPtr)(m_head, m_head->klass->vtable._3_ToString.method);
  Append_5380272(v33, v34);
  v35 = m_tname;
  v36 = GetAppendix();
  Append_5380272(v35, v36);
  switch (process)
  {
    case 0:
      SetBoostFrameRate(kernelObject);
      asset_bc = get_asset_bc();
      v43 = (m_akey->klass->vtable._3_ToString.methodPtr)(
              m_akey,
              m_akey->klass->vtable._3_ToString.method);
      IsLoad = IsLoad(asset_bc, v43);

      {
        v105 = (m_akey->klass->vtable._3_ToString.methodPtr)(
                 m_akey,
                 m_akey->klass->vtable._3_ToString.method);
        v106 = (m_aname->klass->vtable._3_ToString.methodPtr)(
                 m_aname,
                 m_aname->klass->vtable._3_ToString.method);
        v108 = (m_head->klass->vtable._3_ToString.methodPtr)(
                 m_head,
                 m_head->klass->vtable._3_ToString.method);
        LoadAssetExt(v105, v106, v108);
      }
      v60 = 1;
      goto LABEL_124;
    case 1:
      v49 = get_asset_bc();
      v51 = (m_akey->klass->vtable._3_ToString.methodPtr)(
              m_akey,
              m_akey->klass->vtable._3_ToString.method);
      if (!IsLoad(v49, v51))
        return 0;
      v54 = get_asset_bc();
      v56 = (m_tkey->klass->vtable._3_ToString.methodPtr)(
              m_tkey,
              m_tkey->klass->vtable._3_ToString.method);
      v58 = IsLoad(v54, v56);
      if (v58)
      {
LABEL_42:
        v60 = 3;
        goto LABEL_124;
      }
      v110 = evtStartEvent_no;
      if ((v110 - 699) <= 0x39 && ((1LL << (v110 + 69)) & 0x3F000000000000FLL) != 0 || v110 == 676 || v110 == 610)
      {
        if ((v59->_2.bitflags2 & 2) == 0)
          goto LABEL_58;
LABEL_132:
        goto LABEL_58;
      }
      if (v110 == 810)
      {
        if ((*&v59->_2.bitflags1 & 0x200) == 0)
          goto LABEL_58;
        goto LABEL_132;
      }
      v111 = (m_tkey->klass->vtable._3_ToString.methodPtr)(
               m_tkey,
               m_tkey->klass->vtable._3_ToString.method);
      IsNoText_26552416 = IsNoText_26552416(v111);
      if (!IsNoText_26552416)
      {
        v116 = (m_tkey->klass->vtable._3_ToString.methodPtr)(
                 m_tkey,
                 m_tkey->klass->vtable._3_ToString.method);
        v117 = (m_tname->klass->vtable._3_ToString.methodPtr)(
                 m_tname,
                 m_tname->klass->vtable._3_ToString.method);
        v119 = (m_head->klass->vtable._3_ToString.methodPtr)(
                 m_head,
                 m_head->klass->vtable._3_ToString.method);
        LoadAssetExt(v116, v117, v119);
        goto LABEL_42;
      }
LABEL_58:
      v60 = 4;
LABEL_124:
      process = v60;
      return 0;
    case 3:
      v62 = get_asset_bc();
      v64 = (m_tkey->klass->vtable._3_ToString.methodPtr)(
              m_tkey,
              m_tkey->klass->vtable._3_ToString.method);
      if (!IsLoad(v62, v64))
        return 0;
      v67 = (m_tkey->klass->vtable._3_ToString.methodPtr)(
              m_tkey,
              m_tkey->klass->vtable._3_ToString.method);
      v69 = (m_tkey->klass->vtable._3_ToString.methodPtr)(
              m_tkey,
              m_tkey->klass->vtable._3_ToString.method);
      v70 = evtStartEvent_no;
      LoadEventData(v67, v69, v70, 0, 0);
      goto LABEL_57;
    case 4:
      v71 = evtStartEvent_no;
      v72 = !SpEvtCheckLoad(v71);
      if (v72)
        v75 = 6;
      else
        v75 = 5;
      process = v75;
      return 0;
    case 5:
      if (SpEvtLoadFinished() != 1)
        return 0;
      v60 = 6;
      goto LABEL_124;
    case 6:
      v79 = NewSpecific(object, 4u);
      v79->m_Items[0] = "Load Event Data : ";
      v121 = evtStartEvent_no;
      v83 = sub_8D3950(s32, &v121);
      v84 = v83;
      v79->m_Items[1] = v84;
      v79->m_Items[2] = ",";
      v89 = (m_tkey->klass->vtable._3_ToString.methodPtr)(
              m_tkey,
              m_tkey->klass->vtable._3_ToString.method);
      v90 = v89;
      v79->m_Items[3] = v90;
      v93 = Concat_5270224(v79);
      v95 = Empty_string_();
      Log(v93, v95, 0);
      v96 = (m_tkey->klass->vtable._3_ToString.methodPtr)(
              m_tkey,
              m_tkey->klass->vtable._3_ToString.method);
      LoadEventData(v96, evtStartEvent_no, 0);
      v101 = (m_akey->klass->vtable._3_ToString.methodPtr)(
               m_akey,
               m_akey->klass->vtable._3_ToString.method);
      scrStartScript3(1003, evtStartEvent_path, 0, v101);
      dds3KillProcess(&ida, 0);
      SetNormalFrameRate(kernelObject);
      process = 0;
      return 0;
    default:
      return 0;
  }
}

// 0x1952900
void LoadEventData(char *key, s32 e, bool ecmnf) {
  u64 *v6;
  System_String_o *v7;
  System_Object_array *v9;
  System_String_o *DLCTag;
  u64 *v12;
  System_String_o *v13;
  System_String_o *v15;
  EventEMsgData_o *Data;
  u64 *v18;
  System_String_o *v20;
  EventEMsgData_o *v22;
  s32 v23;
  s32 v24;
  s32 v25;

  v25 = e;
  v6 = sub_8D3950(s32, &v25);
  v7 = Concat("LoadEventData : ", v6);
  v9 = Empty_string_();
  Log(v7, v9, 0);
  DLCTag = GetDLCTag(e);
  v24 = e;
  v12 = sub_8D3950(s32, &v24);
  v13 = Format("e{0:D3}", v12, 0);
  v15 = Concat_5224608(v13, DLCTag);
  LoadEventData(key, v15, e, 0, 0);
  LoadKeys(1, key, 0);
  LoadKeys(3, key, 0);
  Data = GetData(key, 0);
  LoadEventVoice(e, key, Data);
  if (!IsNullOrEmpty(DLCTag))
  {
    v23 = e;
    v18 = sub_8D3950(s32, &v23);
    v20 = Format("e{0:D3}", v18, 0);
    v22 = GetData(key, 0);
    LoadEventVoice(e, v20, v22);
  }
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
  u64 *v5;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u32 monitor_high;
  effHandle_t_o *v13;
  effHandle_t_c *v14;
  s64 v15;
  char *v16;
  s64 *v17;
  effHandle_t_o *v18;
  u64 v19[2];
  char *v20;

  v5 = Allocate(effHandle_t);
  effHandle_t___ctor(v5);
  v18 = v5;
  workdata = eff->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v19);
      if ((v19[0] & 1) != 0)
        v10 = v20;
      else
        v10 = v19 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  monitor_high = HIDWORD(workdata[1].monitor);
  if (monitor_high <= 8 && ((1 << monitor_high) & 0x182) != 0)
  {
    v13 = workdata[2].klass;
    if (v13)
    {
      v14 = v13->klass;
      if (v13->klass->_2.typeHierarchyDepth < v15 || v14->_2.typeHierarchy[v15 - 1] != effHandle_t)
      {
        sub_8FC2C0(v14->_1.element_class, effHandle_t, v19);
        if ((v19[0] & 1) != 0)
          v16 = v20;
        else
          v16 = v19 + 1;
        v17 = sub_8C4940(v16);
      }
    }
    v18 = v13;
    if (!sw)
    {
      dds3EffectSetLoop(&v18, 0);
    }
  }
}

// 0x1950e30
void evtFreeAllUnit(void) {
  dds3Basic_t_o *ControlScene;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  Il2CppClass *v11;
  dds3Basic_t_o **p_namespaze;
  u64 v14[3];

  else
  {
    ControlScene = dds3GetControlScene();
    if (!ControlScene)
      return;
  }
  workdata = ControlScene->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v14);
      if ((v14[0] & 1) != 0)
        v7 = v14[2];
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = workdata[2].klass;
  if (LODWORD(v9->_1.namespaze) <= 5)
  {
LABEL_16:
  }
  while (v9->_1.castClass->_1.namespaze)
  {
    v11 = workdata[2].klass;
    p_namespaze = &v11->_1.castClass->_1.namespaze;
    dds3DeleteSceneBasicData(p_namespaze);
    v9 = workdata[2].klass;
    if (LODWORD(v9->_1.namespaze) <= 5)
      goto LABEL_16;
  }
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
      Write_2930400("kill field script -> [{0}]\n", p_obj);
      dds3KillProcess(&id, 0);
      v3 = 0;
    }
  }
LABEL_21:
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
      Write_2930400("kill field script -> [{0}]\n", v11);
      dds3KillProcess(&id, 0);
      goto LABEL_21;
    }
  }
}

// 0x1950ff0
s32 evtLoadArea(s32 fld, s32 area) {
  Il2CppObject *v10;
  u64 *v11;
  u64 *v12;
  System_String_o *v14;
  System_String_o *FieldAssetName;
  f32 v18;
  u64 v20;
  s64 v21;
  s16 v23;
  s32 i;
  u32 *fld_light_dst;
  u64 *v27;
  struct sdf3DLight_t_array *fld_default_light;
  struct sdf3DLight_t_array *v32;
  sdf3DLight_t_o *v33;
  struct sdf3DLight_t_array *v36;
  sdf3DLight_t_o *v37;
  struct sdf3DLight_t_array *v39;
  struct sdf3DLight_t_array *v41;
  u64 *v43;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  f32 v52;
  f32 v53;
  s64 v55;
  f32 v56[3];
  s32 v57;
  dds3Basic_t_o *scene;
  System_String_o *pathstr;

  scene = 0;
  pathstr = "";
  evtFreeStage();
  fldSetCharClr();
  scene = dds3AddScene();
  dds3SetControlScene(&scene);
  dds3SetActiveScene(scene);
  dds3SetMapNo(&scene, area + (fld << 16), 0);
  fldMakeFilePath(&pathstr, fld, area);
  LODWORD(v55) = fld;
  v10 = pathstr;
  v11 = sub_8D3950(s32, &v55);
  v57 = area;
  v12 = sub_8D3950(s32, &v57);
  v14 = Format_5268688("{0}f{1:D3}_{2:D3}", v10, v11, v12);
  FieldAssetName = GetFieldAssetName("f{0:D3}", fld);
  dds3SceneBasicMakeScene(&scene, v14, FieldAssetName);
  evtSetTestCamera();
  if (fld <= 9)
  {
    v18 = 0.94248;
  }
  else
  {
    v18 = 0.75398;
  }
  dds3SetScreenFovy(v18);
  v20 = 0;
  v21 = 8;
  if ((v23 & 0x200) != 0)
    goto LABEL_34;
LABEL_33:
  for (i = 0; ; i = v23 & 0x200)
  {
    if (v20 >= SLODWORD(fld_default_light->max_length))
      break;
    v27 = Allocate(sdf3DLight_t);
    sdf3DLight_t___ctor(v27);
    *&fld_light_dst[v21] = v27;
    v32 = fld_light_dst;
    v33 = *(&fld_default_light->obj.klass + v21 * 4);
    sdf3DLight_t__Clone(v33, (v32 + v21 * 4), 0);
    ++v20;
    v21 += 2;
    if ((v23 & 0x200) == 0)
      goto LABEL_33;
LABEL_34:
  }
  v36 = fld_light_dst;
  if (!LODWORD(v36->max_length))
    goto LABEL_57;
LABEL_53:
  v37 = v36->m_Items[0];
  dds3SetLight(v37, 0);
  v39 = fld_light_dst;
  dds3SetLight(v39->m_Items[1], 1u);
  v41 = fld_light_dst;
  dds3SetLight(v41->m_Items[2], 2u);
  v43 = Allocate(sdf3DFogParam_t);
  sdf3DFogParam_t___ctor(v43);
  fld_fog_dst = v43;
  sdf3DFogParam_t__Clone(fld_default_fog, &fld_fog_dst);
  dds3SetFog(fld_fog_dst);
  x = fld_default_ambient.x;
  y = fld_default_ambient.y;
  z = fld_default_ambient.z;
  w = fld_default_ambient.w;
  v55 = 0;
  *v56 = 0;
  sub_854690(&v55, x, y, z, w);
  v53 = v56[0];
  v52 = v56[1];
  *&fld_ambient_dst.x = v55;
  fld_ambient_dst.z = v53;
  fld_ambient_dst.w = v52;
  dds3SetAmbient(fld_ambient_dst);
  return 1;
}

// 0x1951540
s32 evtLoadArea_FromMemory(s32 fld, s32 area, u8 **pF1, u8 **pF2, u8 **pTB, u8 **pBF) {
  Il2CppObject *v17;
  u64 *v18;
  u64 *v19;
  System_String_o *v20;
  u64 *v21;
  System_String_o *v22;
  u64 v26;
  s64 v27;
  s16 v29;
  s32 i;
  u32 *fld_light_dst;
  u64 *v33;
  struct sdf3DLight_t_array *fld_default_light;
  struct sdf3DLight_t_array *v38;
  sdf3DLight_t_o *v39;
  struct sdf3DLight_t_array *v42;
  sdf3DLight_t_o *v43;
  struct sdf3DLight_t_array *v45;
  struct sdf3DLight_t_array *v47;
  u64 *v49;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  f32 v58;
  f32 v59;
  s64 v62;
  s64 v63;
  s32 v64;
  s32 v65;
  dds3Basic_t_o *scene;
  System_String_o *pathstr;

  scene = 0;
  pathstr = "";
  pFldNextFileDataBF = &pBF->obj;
  pFldNextFileDataTB = &pTB->obj;
  pFldNextFileDataF1 = &pF1->obj;
  pFldNextFileDataF2 = &pF2->obj;
  evtFreeStage();
  scene = dds3AddScene();
  dds3SetControlScene(&scene);
  dds3SetActiveScene(scene);
  dds3SetMapNo(&scene, area + (fld << 16), 0);
  fldMakeFilePath(&pathstr, fld, area);
  LODWORD(v62) = fld;
  v17 = pathstr;
  v18 = sub_8D3950(s32, &v62);
  v65 = area;
  v19 = sub_8D3950(s32, &v65);
  v20 = Format_5268688("{0}f{1:D3}_{2:D3}", v17, v18, v19);
  v64 = fld;
  v21 = sub_8D3950(s32, &v64);
  v22 = Format("f{0:D3}", v21, 0);
  dds3SceneBasicMakeScene(&scene, v20, v22);
  evtSetTestCamera();
  dds3SetScreenFovy(0.75398);
  v26 = 0;
  v27 = 8;
  if ((v29 & 0x200) != 0)
    goto LABEL_22;
LABEL_21:
  for (i = 0; ; i = v29 & 0x200)
  {
    if (v26 >= SLODWORD(fld_default_light->max_length))
      break;
    v33 = Allocate(sdf3DLight_t);
    sdf3DLight_t___ctor(v33);
    *&fld_light_dst[v27] = v33;
    v38 = fld_light_dst;
    v39 = *(&fld_default_light->obj.klass + v27 * 4);
    sdf3DLight_t__Clone(v39, (v38 + v27 * 4), 0);
    ++v26;
    v27 += 2;
    if ((v29 & 0x200) == 0)
      goto LABEL_21;
LABEL_22:
  }
  v42 = fld_light_dst;
  if (!LODWORD(v42->max_length))
    goto LABEL_45;
LABEL_41:
  v43 = v42->m_Items[0];
  dds3SetLight(v43, 0);
  v45 = fld_light_dst;
  dds3SetLight(v45->m_Items[1], 1u);
  v47 = fld_light_dst;
  dds3SetLight(v47->m_Items[2], 2u);
  v49 = Allocate(sdf3DFogParam_t);
  sdf3DFogParam_t___ctor(v49);
  fld_fog_dst = v49;
  sdf3DFogParam_t__Clone(fld_default_fog, &fld_fog_dst);
  dds3SetFog(fld_fog_dst);
  x = fld_default_ambient.x;
  y = fld_default_ambient.y;
  z = fld_default_ambient.z;
  w = fld_default_ambient.w;
  v62 = 0;
  v63 = 0;
  sub_854690(&v62, x, y, z, w);
  v59 = *&v63;
  v58 = *(&v63 + 1);
  *&fld_ambient_dst.x = v62;
  fld_ambient_dst.z = v59;
  fld_ambient_dst.w = v58;
  dds3SetAmbient(fld_ambient_dst);
  do
  {
    {
      if (sdfDelayedResrcCheck() != 1)
        return 1;
    }
  }
  while (sdfDelayedResrcCheck() == 1);
  return 1;
}

// 0x1950290
s32 evtLoadUnit(s32 major, s32 minor) {
  u32 v6;
  s64 v8;
  s64 v9;
  u32 v10;
  s64 v11;
  s64 v12;
  dds3Basic_t_o *v15;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v20;
  s64 *v21;
  dds3Basic_t_o *pItemBasic;
  dds3Basic_t_o *pBasic;
  dds3ModelHandle_t_o *aHandle;
  dds3Basic_t_o *pObjectBasic;
  s64 v29;
  s64 v30;
  s64 v31;
  s64 v32;
  u64 v33[3];
  UnityEngine_Vector4_o v34;
  UnityEngine_Vector4_o v35;

  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  aHandle = 0;
  pObjectBasic = 0;
  pItemBasic = 0;
  pBasic = 0;
  sub_854690(&v31, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v29, 0.0, 0.0, 0.0, 1.0);
  v6 = dds3SerializeID();
  v8 = v31;
  v9 = v32;
  v10 = v6;
  v11 = v29;
  v12 = v30;
  *&v34.x = v8;
  *&v34.z = v9;
  *&v35.x = v11;
  *&v35.z = v12;
  pObjectBasic = dds3AddUnitObjectBasic(v10, v34, v35);
  dds3ObjectBaseOnFlag(&pObjectBasic, 0x20u, 0);
  dds3SetRadiusPoseSet(&pObjectBasic, 10.0);
  dds3ObjectBaseMakeUnit(&pObjectBasic, major, minor);
  v15 = pObjectBasic;
  AttachModel(v15, major, minor);
  ModelHandle = dds3ObjectBaseGetModelHandle(&pObjectBasic);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v33);
      if ((v33[0] & 1) != 0)
        v20 = v33[2];
      else
        v20 = v33 + 1;
      v21 = sub_8C4940(v20);
    }
  }
  aHandle = ModelHandle;
  mdlLoopMotion(&aHandle, 0, 0);
  pBasic = dds3GetControlScene();
  pItemBasic = dds3SearchSceneBasic(&pBasic, 0x10000u, 2u);
  dds3ObjectBaseSetControlBasic(&pObjectBasic, &pItemBasic);
  dds3ObjectBaseRegistArea(&pObjectBasic);
  dds3ObjectBaseSetPadControl(&pObjectBasic, 0);
  dds3ObjectBaseOnFlag(&pObjectBasic, 0x400u, 0);
  return v10;
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
  u32 v6;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  dds3ModelHandle_t_o *aHandle;
  dds3Basic_t_o *pObjectBasic;
  u64 v22[3];
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;

  pObjectBasic = 0;
  aHandle = 0;
  v6 = dds3SerializeID();
  x = UnitInitPosRot.x;
  y = UnitInitPosRot.y;
  z = UnitInitPosRot.z;
  w = UnitInitPosRot.w;
  v23.x = x;
  v23.y = y;
  v23.z = z;
  v23.w = w;
  v24.x = x;
  v24.y = y;
  v24.z = z;
  v24.w = w;
  pObjectBasic = dds3AddUnitObjectBasic(v6, v23, v24);
  dds3ObjectBaseOnFlag(&pObjectBasic, 0x20u, 0);
  dds3SetRadiusPoseSet(&pObjectBasic, 10.0);
  dds3ObjectBaseMakeUnit(&pObjectBasic, major, minor);
  ModelHandle = dds3ObjectBaseGetModelHandle(&pObjectBasic);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v22);
      if ((v22[0] & 1) != 0)
        v17 = v22[2];
      else
        v17 = v22 + 1;
      v18 = sub_8C4940(v17);
    }
  }
  aHandle = ModelHandle;
  mdlLoopMotion(&aHandle, 0, 0);
  dds3ObjectBaseSetPadControl(&pObjectBasic, 0);
  return v6;
}

// 0x194fed0
void evtSetTestCamera(void) {
  u32 v2;
  dds3Basic_t_o *ControlScene;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v7;
  UnityEngine_Vector4_o v8;

  *&v8.x = 0;
  *&v8.z = 0;
  *&v7.x = 0;
  *&v7.z = 0;
  ControlScene = 0;
  pBasic = 0;
  sub_854690(&v8.x, 0.0, -100.0, -600.0, 0.0);
  sub_854690(&v7.x, 0.0, 0.0, 0.0, 1.0);
  v2 = dds3SerializeID();
  pBasic = dds3AddCameraObjectBasicTypeFree(v2, v8, v7);
  dds3SetRadiusPoseSet(&pBasic, 10.0);
  dds3ObjectBaseCreateMover(&pBasic);
  ControlScene = dds3GetControlScene();
  dds3SetActiveCameraSceneBasic(&ControlScene, &pBasic);
  dds3ObjectBaseSetPadControl(&pBasic, 0);
}

// 0x1950b20
void evtSetUnitPos(s32 unitID, s32 posID) {
  dds3Basic_t_o *v8;
  dds3Basic_t_o *v9;
  s64 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 *static_fields;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o p;
  dds3Basic_t_o *v24;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o v26;

  v24 = 0;
  *&p.x = 0;
  *&p.z = 0;
  pBasic = 0;
  sub_854690(&p.x, 0.0, 1.0, 0.0, 1.0);
  pBasic = dds3GetControlScene();
  v24 = dds3SearchSceneBasic(&pBasic, unitID, 5u);
  if (v24)
  {
    v8 = dds3SearchSceneBasic(&pBasic, posID, 0x11u);
    if (v8)
    {
      v9 = v8;
      v10 = il2cp::SizeOf(v8->workdata, fldResourcePoint_t);
      v11 = *v10;
      v12 = *(v10 + 4);
      v13 = *(v10 + 8);
      v14 = *(v10 + 12);
      v15 = *(v10 + 16);
      v16 = *(v10 + 20);
      v17 = *(v10 + 24);
      v18 = *(v10 + 28);
      if (Equals_5234480(v9->name, "ppos01"))
      {
        v11 = static_fields[45];
        v12 = static_fields[46];
        v13 = static_fields[47];
        v14 = static_fields[48];
        v15 = static_fields[49];
        v16 = static_fields[50];
        v17 = static_fields[51];
        v18 = static_fields[52];
      }
      v25.x = v11;
      v25.y = v12;
      v25.z = v13;
      v25.w = v14;
      dds3SetPosPoseSet(&v24, v25);
      SDF_VU0__LOADVECTOR(p);
      FromRotation(3.1416);
      v26.x = v15;
      v26.y = v16;
      v26.z = v17;
      v26.w = v18;
      SDF_VU0__LOADVECTOR_B(v26);
      Mult();
      SDF_VU0__STOREVECTOR(&p);
      dds3SetRotPoseSet(&v24, p);
      dds3GetPosPoseSet(&v24);
      SDF_VU0__STOREVECTOR(&v24->poseset->pos2);
    }
  }
}

// 0x1953420
s32 evtStageAnimeControl(s32 type, s32 mode) {
  dds3Basic_t_o *ActiveScene;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v9;
  s32 v11;
  char *v12;
  s64 *v13;
  dds3Basic_t_o *v15[3];
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  else
  {
    ActiveScene = dds3GetActiveScene();
    if (!ActiveScene)
      return ActiveScene;
  }
  workdata = ActiveScene->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v15);
    if ((v15[0] & 1) != 0)
      v12 = v15[2];
    else
      v12 = v15 + 1;
    v13 = sub_8C4940(v12);
  }
  v9 = workdata[2].klass;
  pObjectBasic = v9->_1.declaringType->_1.namespaze;
  if (pObjectBasic)
  {
    v11 = 3 * type + mode;
    do
    {
      dds3ObjectBaseMatterAnimeSpeed(&pObjectBasic, v11);
      pObjectBasic = pObjectBasic->next;
    }
    while (pObjectBasic);
  }
  LODWORD(ActiveScene) = 1;
  return ActiveScene;
}

// 0x1951ab0
void evtStartEvent(s32 no) {
  Il2CppObject *DLCTag;
  u64 *v5;
  u64 *v6;
  struct System_String_o *v7;
  u64 *v9;
  s32 v11;
  s32 v12;

  evtStartEvent_no = no;
  v12 = no;
  DLCTag = GetDLCTag(no);
  v5 = sub_8D3950(s32, &v12);
  v11 = no;
  v6 = sub_8D3950(s32, &v11);
  v7 = Format_5268688("dds3data/event/e{0:D3}{1}/e{2:D3}.bf", v5, DLCTag, v6);
  evtStartEvent_path = v7;
  process = 0;
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_evtStage_LoadEvent1__);
  dds3StartProcess("EventLoad", 0x3EBu, 0, 1, v9, 0, 0, 0, 0, 0);
}
