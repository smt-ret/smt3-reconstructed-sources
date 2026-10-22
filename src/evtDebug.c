#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtDebug_evtSceneDisp evtDebug_evtSceneDisp;
typedef struct sdfDrawTag_t sdfDrawTag_t;

struct evtDebug_evtSceneDisp {
    char *name;
    s32 type;
    s32 y;
    s32 num;
};

static char *str_freecamera;
static s32 debug_draw;
static s32 event_mode;
static char *event_filename;
static s32 free_camera;
static char *VoiceName;
static s32 bStatus;
static char *cam_name;
static char *SpkName;
static char *TagName;
static s32 itfon;
static void *fieldObj;
static s32 EventDebugProcess1_e;
static s32 EvtNo1;
static s32 EvtNo2;
static char *DlcHead;
static s32 IsDataCheck;
static s32 EvtDante[7];
static s32 E646_Type;
static char *E646_Text[6];
static char *E655_Text[2];
static s32 E677_Type;
static char *E677_Text[2];
static s32 E681_Type;
static char *E681_Text[2];
static s32 E705_Ending_Type;
static char *E705_Ending_Text[11];
static char *E_BossBtlAfter_Text[2];
static char *E_OldFuku_Text[2];
static s32 dpy;
static s32 curbase;
static s32 curpoint;
static evtDebug_evtSceneDisp *data;
static char *Text_Nodata;
static void *Dic_EveName;

void *CheckAssetBundleData(void);
bool DDS3_PAD2CHECK_REP(s32 id);
bool DDS3_PAD2CHECK_TRIG(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
char *GetDLCTag(s32 eventno);
char *GetDbgEventName(s32 eve_id);
char *GetEventFileNameToAssetName(char *filename);
bool IsFadeOutWindow(void);
bool IsFileExists(AssetBundleCtrl *this, char *key, char *path_name);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void LoadAssetExt(char *key, char *name, char *dlc);
void LoadEventData(char *key, s32 e, bool ecmnf);
void Log(char *fmt, void **parray);
bool SpEvtCheckLoad(s32 eventno);
s32 SpEvtLoadFinished(void);
void StartLoad(void);
void UnloadAB(AssetBundleCtrl *this, char *key);
f32 dds3CameraObjectBasicGetFovy(dds3Basic_t **pBasic);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void dds3SetScreenFovy(f32 fovy);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void evtBitAllOff(void);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void evtFreeStage(void);
void scrAllReleaseScript(void);
dds3ProcessID_t *scrStartScript3(s32 priority, char *filename, s32 startproc, char *akey);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x1362080
void ActivateCamera(dds3Basic_t **camera) {
  f32 Fovy;
  dds3Basic_t_o *pSceneBasic;

  pSceneBasic = 0;
  pSceneBasic = dds3GetActiveScene();
  dds3SetActiveCameraSceneBasic(&pSceneBasic, camera);
  Fovy = dds3CameraObjectBasicGetFovy(camera);
  dds3SetScreenFovy(Fovy);
}

// 0x13619d0
s32 CameraLength(void) {
  dds3Basic_t_o *ActiveScene;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  char *v8;
  s64 *v9;
  u64 v11[3];

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
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  v6 = workdata[2].klass;
  LODWORD(ActiveScene) = LODWORD(v6->_1.element_class->_1.name) - 1;
  return ActiveScene;
}

// 0x1364810
void *CheckAssetBundleData(void) {
  s32 EventDebugProcess1_e;
  System_String_o *DLCTag;
  Il2CppObject *v5;
  u64 *v6;
  System_String_o *v8;
  s32 IsDataCheck;
  s32 v11;
  u64 *v12;
  u64 *v13;
  System_String_o *v15;
  AssetBundleCtrl_o *v16;
  System_String_o *v17;
  bool IsFileExists;
  u64 *v21;
  AssetBundleCtrl_o *asset_bc;
  bool IsLoad;
  AssetBundleCtrl_o *v27;
  bool v28;
  s32 v30;
  s32 v31;
  System_String_o *v33;
  s32 v35;
  s32 v36;
  s32 v37;

  DLCTag = GetDLCTag(EventDebugProcess1_e);
  v37 = EventDebugProcess1_e;
  v5 = DLCTag;
  v6 = sub_8D3950(s32, &v37);
  v8 = Format_5268592("e{0:D3}{1}", v6, v5);
  if (IsDataCheck == 1)
  {
    asset_bc = get_asset_bc();
    IsLoad = IsLoad(asset_bc, v8);
    if (!IsLoad)
    {
      v31 = EventDebugProcess1_e;
      v33 = GetDLCTag(v31);
      LoadAssetExt(v8, v8, v33);
      v30 = 2;
      goto LABEL_50;
    }
    {
LABEL_38:
      v30 = 3;
LABEL_50:
      v21 = 0;
      IsDataCheck = v30;
      return v21;
    }
LABEL_31:
    goto LABEL_38;
  }
  if (IsDataCheck != 2)
  {
    if (IsDataCheck != 3)
      return 0;
    v36 = EventDebugProcess1_e;
    v11 = v36;
    v12 = sub_8D3950(s32, &v36);
    v35 = v11;
    v13 = sub_8D3950(s32, &v35);
    v15 = Format_5268688("dds3data/event/e{0:D3}{1}/e{2:D3}.bf", v12, v5, v13);
    v16 = get_asset_bc();
    v17 = Concat_5224608(v15, ".bytes");
    IsFileExists = IsFileExists(v16, v8, v17);
    v21 = 0;
    IsDataCheck = 0;
    if (IsFileExists)
    {
      dds3BackColor = 0x80000000;
      event_mode = 0;
      event_filename = v15;
      v21 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v21,
        0,
        Method_evtDebug_EventDebugProcess2__);
    }
    return v21;
  }
  v27 = get_asset_bc();
  v28 = IsLoad(v27, v8);
  v21 = 0;
  if (v28)
  {
      goto LABEL_38;
    goto LABEL_31;
  }
  return v21;
}

// 0x13618d0
bool DispStatus(void) {
  if (!dds3DebugSign)
    return 0;
LABEL_6:
  if (!bStatus)
    return 0;
LABEL_9:
  return debug_draw == 1;
}

// 0x1361dc0
void DrawTag(void) {
  u64 *v2;
  System_Object_array *v4;
  s64 *SpkName;
  Il2CppObject *v9;
  u64 *v10;
  s64 *TagName;
  u64 *v12;
  Il2CppObject *v14;
  struct sdfGrOt_t_array *dds3Ot;

  else if (IsFadeOutWindow())
  {
    return;
  }
  v2 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v2);
  v4 = NewSpecific(object, 1u);
  v4->m_Items[0] = SpkName;
  v9 = sdfDevPrintf(28864, 35056, 0xFF0000u, 0, "S:{0}", v4);
  sdfDrawTagLink(v2, v9);
  v10 = NewSpecific(object, 1u);
  v12 = v10;
  v12[4] = TagName;
  v14 = sdfDevPrintf(28864, 35152, 0xFF0000u, 0, "M:{0}", v12);
  sdfDrawTagLink(v2, v14);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v2);
}

// 0x1362ab0
void *EventDebugProcess1(dds3ProcessID_t *id) {
  u64 v3;

  if (!IsDataCheck)
    goto LABEL_11;
LABEL_6:
  return CheckAssetBundleData(v3);
}

// 0x1362190
void *EventDebugProcess2(dds3ProcessID_t *id) {
  s32 EventDebugProcess1_e;
  System_String_o *DLCTag;
  u64 *v5;
  System_String_o *v6;
  System_String_o *v7;
  System_String_o *EventFileNameToAssetName;
  System_String_o *v10;
  System_Object_array *v13;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v17;
  s32 v20;
  System_String_o *v21;
  System_Object_array *v23;
  AssetBundleCtrl_o *v25;
  AssetBundleCtrl_o *v28;
  AssetBundleCtrl_o *v30;
  System_String_o *v32;
  u64 *v34;
  System_String_o *v36;
  AssetBundleCtrl_o *v37;
  System_String_o *v38;
  System_String_o *v39;
  System_Object_array *v41;
  AssetBundleCtrl_o *v42;
  AssetBundleCtrl_o *v43;
  u64 *v46;
  System_String_o *v48;
  AssetBundleCtrl_o *v49;
  bool v51;
  s32 v54;
  UnityEngine_GameObject_o *v62;
  Il2CppObject *Component_object;
  System_String_o *event_filename;
  s32 v69;
  s32 v70;
  s32 v71;
  bool v72[4];

  v72[0] = 0;
  v71 = EventDebugProcess1_e;
  DLCTag = GetDLCTag(EventDebugProcess1_e);
  v5 = sub_8D3950(s32, &v71);
  v6 = Format("e{0:D3}", v5, 0);
  v7 = Concat_5224608(v6, DLCTag);
  EventFileNameToAssetName = GetEventFileNameToAssetName(event_filename);
  v10 = Concat_5224608(EventFileNameToAssetName, DLCTag);
  switch (event_mode)
  {
    case 0:
      v13 = Empty_string_();
      Log("LoadPack[0] : AssetCheck", v13, 0);
      asset_bc = get_asset_bc();
      if (IsLoad(asset_bc, v7))
      {
        v17 = get_asset_bc();
        UnloadAB(v17, v7);
        v20 = 1;
        break;
      }
      goto LABEL_138;
    case 1:
LABEL_138:
      v20 = 2;
      break;
    case 2:
      v21 = Concat_5224608("LoadPack[1] : AssetLoad = ", v7);
      v23 = Empty_string_();
      Log(v21, v23, 0);
      v25 = get_asset_bc();
      if (!IsLoad(v25, v7))
      {
        LoadAssetExt(v7, v10, DLCTag);
      }
      v20 = 3;
      break;
    case 3:
      v28 = get_asset_bc();
      if (!IsLoad(v28, v7))
        return 0;
      goto LABEL_51;
    case 4:
      v30 = get_asset_bc();
      if (!IsLoad(v30, "ecmn"))
        return 0;
LABEL_51:
      v20 = 5;
      break;
    case 5:
      v32 = GetDLCTag(EventDebugProcess1_e);
      if (IsNullOrEmpty(v32))
        goto LABEL_77;
      v70 = EventDebugProcess1_e;
      v34 = sub_8D3950(s32, &v70);
      v36 = Format("e{0:D3}", v34, 0);
      v37 = get_asset_bc();
      v72[0] = IsLoad(v37, v36);
      v38 = sub_3C0020(v72);
      v39 = Concat_5224608("LoadPack[5] : fxx ", v38);
      v41 = Empty_string_();
      Log(v39, v41, 0);
      v42 = get_asset_bc();
      if (IsLoad(v42, v36))
        goto LABEL_77;
      v43 = get_asset_bc();
      Load(v43, v36, v36, 0);
      v20 = 6;
      break;
    case 6:
      v69 = EventDebugProcess1_e;
      v46 = sub_8D3950(s32, &v69);
      v48 = Format("e{0:D3}", v46, 0);
      v49 = get_asset_bc();
      if (!IsLoad(v49, v48))
        return 0;
LABEL_77:
      v20 = 7;
      break;
    case 7:
      v51 = !SpEvtCheckLoad(EventDebugProcess1_e);
      if (v51)
        v54 = 9;
      else
        v54 = 8;
      event_mode = v54;
      return 0;
    case 8:
      if (SpEvtLoadFinished() != 1)
        return 0;
      v20 = 9;
      break;
    case 9:
      PlayEventNo = EventDebugProcess1_e;
      if (EventDebugProcess1_e == 602
        || EventDebugProcess1_e == 726
        || EventDebugProcess1_e == 809
        || (EventDebugProcess1_e - 740) <= 8)
      {
        DisableStop1EventNo = EventDebugProcess1_e;
      }
      StartLoad();
      v20 = 10;
      break;
    case 0xA:
      if (!Load(EventDebugProcess1_e, 0))
        return 0;
      LoadEventData(v7, EventDebugProcess1_e, 0, 0);
      v62 = Find("kernel", 0);
      Component_object = GetComponent_object_(v62);
      SetActive(Component_object[14].klass, 1, 0);
      scrStartScript3(1003, event_filename, 0, v7);
      v20 = 11;
      break;
    case 0xB:
      return 0;
    default:
      return 0;
  }
  event_mode = v20;
  return 0;
}

// 0x1362a20
void *EventDebugSelectFlash(dds3ProcessID_t *id) {
  u64 *v2;

  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_evtDebug_EventDebugProcess1__);
  return v2;
}

// 0x1364cf0
void *EventDebugShutdown(dds3ProcessID_t *id) {
  scrAllReleaseScript();
  id->func_ans = -1;
  return 0;
}

// 0x1361b20
dds3Basic_t *GetCamera(char *name) {
  dds3Basic_t_o *ActiveScene;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  Il2CppClass *element_class;
  Il2CppObject *v11;
  Il2CppClass *v12;
  s64 v13;
  Il2CppClass *v14;
  char *v17;
  s64 *v18;
  char *v19;
  s64 *v20;
  u64 v21[2];
  char *v22;

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
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v21);
    if ((v21[0] & 1) != 0)
      v17 = v22;
    else
      v17 = v21 + 1;
    v18 = sub_8C4940(v17);
  }
  v7 = workdata[2].klass;
  element_class = v7->_1.element_class;
  else if (free_camera == 1)
  {
    return element_class->_1.byval_arg.data;
  }
  v11 = ActiveScene->workdata;
  v12 = v11->klass;
  if (v11->klass->_2.typeHierarchyDepth < v13 || v12->_2.typeHierarchy[v13 - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(v12->_1.element_class, dds3SceneBasic_t, v21);
    if ((v21[0] & 1) != 0)
      v19 = v22;
    else
      v19 = v21 + 1;
    v20 = sub_8C4940(v19);
  }
  v14 = v11[2].klass;
  ActiveScene = v14->_1.element_class->_1.namespaze;
  if (cam_name && ActiveScene)
  {
    do
    {
      if (Equals_5234480(ActiveScene->name, name))
        break;
      ActiveScene = ActiveScene->next;
    }
    while (ActiveScene);
  }
  return ActiveScene;
}

// 0x1364be0
char *GetDbgEventName(s32 eve_id) {
  bool v7;

  if (evtBitCheck(3712) && ((eve_id & 0xFFFFFFFC) == 0x2D8 || eve_id == 723))
    eve_id += 1000;
  v7 = TerrainUtility_TerrainMap___ContainsKey(Dic_EveName, eve_id);
  if (v7)
  {
    return TerrainUtility_TerrainMap___get_Item(Dic_EveName, eve_id);
  }
  else
  {
    return Text_Nodata;
  }
}

// 0x1362aa0
bool IsDlcEvent(void) {
  return evtBitCheck(3712);
}

// 0x13618c0
bool IsPaused(void) {
  return 0;
}

// 0x1362180
bool WindowOnOff(bool eevt) {
  return 0;
}

// 0x1362170
void draweventdebug(void) {
  ;
}

// 0x1364f80
bool evtChkEndProcess(void) {
  dds3ProcessID_t_o *v2;

  v2 = dds3SearchProcessName("EventTest");
  return (v2 | dds3SearchProcessName("PolygonMovie")) == 0;
}

// 0x1364ec0
void evtExitEventTest(void) {
  dds3KillProcessName("EventTest", 1);
  dds3KillProcessName("PolygonMovie", 0);
  else
  {
    evtFreeStage();
  }
}

// 0x1364d70
void evtInitEventTest(void) {
  u64 *v4;
  u64 *v5;

  dds3BackColor = 0x80000000;
  event_mode = 0;
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_evtDebug_EventDebugProcess1__);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_evtDebug_EventDebugShutdown__);
  dds3StartProcess("EventTest", 0x2AF9u, 1, 1, v4, 0, v5, 0, 0, 0);
}

// 0x1365020
void *evtSceneDispProcess(dds3ProcessID_t *id) {
  u64 *v2;
  u32 v4;
  struct evtDebug_evtSceneDisp_array *v5;
  evtDebug_c **v23;
  dds3Basic_t_o *ActiveScene;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v32;
  s64 *v33;
  u64 v34;
  s32 v35;
  evtDebug_c *v36;
  struct evtDebug_evtSceneDisp_array *data;
  u64 v39;
  s64 v40;
  struct evtDebug_evtSceneDisp_array *v42;
  u64 v44;
  struct evtDebug_StaticFields *static_fields;
  bool v46;
  s32 v47;
  s32 v48;
  s64 v49;
  s64 v50;
  s32 v51;
  evtDebug_c **v52;
  System_String_o *v54;
  System_Object_array *v56;
  Il2CppObject *v58;
  s32 dpy;
  System_Object_array *v60;
  struct evtDebug_evtSceneDisp_array *v61;
  Il2CppClass *v62;
  System_Object_array *v63;
  s64 type;
  s64 *v67;
  s64 *v68;
  Il2CppObject *v70;
  struct evtDebug_evtSceneDisp_array *v71;
  Il2CppClass *v72;
  s64 v74;
  u64 v76;
  s64 v77;
  bool v78;
  s32 v79;
  struct evtDebug_StaticFields *v81;
  struct evtDebug_evtSceneDisp_array *v82;
  bool v84;
  s32 v85;
  s32 v86;
  s32 v87;
  System_Object_array *v88;
  System_Object_array *v89;
  s64 *v90;
  s64 *v92;
  Il2CppObject *v95;
  u64 v96;
  s64 v97;
  u64 v99;
  s64 v100;
  s64 v102;
  u64 v104;
  s64 v105;
  u64 v107;
  s64 v108;
  s32 v112;
  System_Object_array *v114;
  Il2CppObject *v116;
  u64 *v117;
  u64 v120;
  struct sdfGrOt_t_array *dds3Ot;
  struct sdfGrOt_t_array *v125;
  u64 v129;
  s16 v130;
  s32 v131;
  struct evtDebug_StaticFields *v132;
  s64 p_static_fields;
  s32 curpoint;
  struct evtDebug_evtSceneDisp_array *v135;
  s64 v136;
  u64 v138;
  u64 v140;
  struct evtDebug_StaticFields *v141;
  u64 *v142;
  s32 curbase;
  struct evtDebug_evtSceneDisp_array *v144;
  s64 v146;
  s64 v147;
  u64 v149;
  u64 v151;
  s16 v152;
  s32 v153;
  struct evtDebug_StaticFields *v154;
  s64 v155;
  s32 v156;
  s32 v159;
  s64 v160;
  s64 v161;
  s64 v163;
  s64 v164;
  u64 v166;
  u64 v167;
  struct evtDebug_StaticFields *v168;
  s32 v169;
  struct evtDebug_evtSceneDisp_array *v170;
  s64 v171;
  u64 v173;
  u64 v175;
  struct evtDebug_StaticFields *v176;
  s32 v177;
  bool v178;
  u64 v180;
  struct evtDebug_StaticFields *v181;
  Il2CppClass *v182;
  struct evtDebug_evtSceneDisp_array *v183;
  s64 v184;
  s64 v186;
  u64 v188;
  s32 v189;
  Il2CppObject *monitor;
  struct evtDebug_evtSceneDisp_array *v191;
  s64 v192;
  u64 v194;
  u64 v196;
  dds3Basic_t_o *v198;
  Il2CppObject *v199;
  s32 v200;
  sdfDrawTag_t_o *aTag;
  dds3ProcessID_t_o *ida;
  u64 v203[3];

  ida = id;
  v2 = NewSpecific(evtDebug_evtSceneDisp, 0x11u);
  v4 = *(v2 + 6);
  v5 = v2;
  v2[4] = "AREA";
  v2[5] = 2;
  v2[6] = 0;
  v2[7] = "MOVER";
  v2[8] = 3;
  v2[9] = 0;
  v2[10] = "CAMERA_O";
  v2[11] = 4;
  v2[12] = 0;
  v2[13] = "UNIT_O";
  v2[14] = 5;
  v2[15] = 0;
  v2[16] = "MATTER_O";
  v2[17] = 6;
  v2[18] = 0;
  v2[19] = "EFFECT_O";
  v2[20] = 7;
  v2[21] = 0;
  v2[22] = "EVENT_O";
  v2[23] = 8;
  v2[24] = 0;
  v2[25] = "LIGHT_O";
  v2[26] = 9;
  v2[27] = 0;
  v2[28] = "STATIC_M";
  v2[29] = 10;
  v2[30] = 0;
  v2[31] = "MODEL_R";
  v2[32] = 11;
  v2[33] = 0;
  v2[34] = "EFFECT";
  v2[35] = 12;
  v2[36] = 0;
  v2[37] = "EVENT";
  v2[38] = 13;
  v2[39] = 0;
  v2[40] = "FOG";
  v2[41] = 14;
  v2[42] = 0;
  v2[43] = "LIGHT";
  v2[44] = 15;
  v2[45] = 0;
  v2[46] = "PATH";
  v2[47] = 16;
  v2[48] = 0;
  v2[49] = "POINT";
  v2[50] = 17;
  v2[51] = 0;
  v2[52] = "";
  v2[53] = 0;
  v23 = &evtDebug;
  v2[54] = 0;
  data = v5;
  aTag = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(aTag);
  sdfDrawTagInit(aTag);
  else
  {
    ActiveScene = dds3GetActiveScene();
    v198 = ActiveScene;
    if (ActiveScene)
    {
LABEL_46:
      workdata = ActiveScene->workdata;
      if (workdata)
      {
        klass = workdata->klass;
        if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
        {
          sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v203);
          if ((v203[0] & 1) != 0)
            v32 = v203[2];
          else
            v32 = v203 + 1;
          v33 = sub_8C4940(v32);
        }
      }
      v34 = 0;
      v200 = 0;
      v35 = 2;
      v199 = ActiveScene->workdata;
      {
LABEL_54:
        goto LABEL_57;
      }
      while (1)
      {
LABEL_57:
        if (!data->m_Items[v34].type)
          goto LABEL_179;
        v39 = *v23;
        if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v39 + 216))
        {
          v39 = *v23;
        }
        v40 = *(*(v39 + 184) + 232LL);
        *(v40 + 24 * v34 + 48) = 0;
        v42 = (*v23)->static_fields->data;
        v42->m_Items[v34].y = 0;
        v44 = *v23;
        static_fields = (*v23)->static_fields;
        if (v34 != static_fields->curbase)
          break;
        if ((*(v44 + 295) & 2) != 0 && !*(v44 + 216))
        {
          v44 = *v23;
          static_fields = (*v23)->static_fields;
        }
        v46 = static_fields->curpoint == 0;
        v47 = v200;
        if (v46)
          v47 = 1;
        v200 = v47;
        if (v46)
          v48 = 4;
        else
          v48 = 5;
        if ((*(v44 + 295) & 2) != 0)
          goto LABEL_78;
LABEL_81:
        v49 = *(v44 + 184);
        v50 = *(v49 + 232);
        v51 = *(v49 + 216);
        v52 = v23;
        v54 = *(v50 + 24 * v34 + 32);
        v56 = Empty_string_();
        v58 = sdfDevPrintf(29056, 96 * (v35 - v51) + 30976, 0xFEFFFFu, v48, v54, v56, 0);
        sdfDrawTagLink(aTag, v58);
        dpy = (*v52)->static_fields->dpy;
        v60 = NewSpecific(object, 1u);
        v61 = (*v52)->static_fields->data;
        v62 = workdata[2].klass;
        v63 = v60;
        type = v61->m_Items[v34].type;
        LODWORD(v203[0]) = *(*(&v62->_1.byval_arg.data + type) + 16LL);
        v67 = sub_8D3950(s32, v203);
        v68 = v67;
        v63->m_Items[0] = v68;
        v70 = sdfDevPrintf(30976, 96 * (v35 - dpy) + 30976, 0xFEFFFFu, v48, "[%2d]", v63, 0);
        sdfDrawTagLink(aTag, v70);
        v71 = (*v52)->static_fields->data;
        v72 = workdata[2].klass;
        v23 = v52;
        v74 = v71->m_Items[v34].type;
        v76 = *v52;
        v77 = *(*(&v72->_1.byval_arg.data + v74) + 24LL);
        v78 = ((*v52)->_2.bitflags2 & 2) == 0;
        if (v77)
        {
          v79 = 0;
          do
          {
            if (v78 || *(v76 + 216))
            {
              v81 = *(v76 + 184);
              if (v34 == v81->curbase)
                goto LABEL_109;
            }
            else
            {
              v76 = *v23;
              v81 = (*v23)->static_fields;
              if (v34 == v81->curbase)
              {
LABEL_109:
                if ((*(v76 + 295) & 2) != 0 && !*(v76 + 216))
                {
                  v76 = *v23;
                  v81 = (*v23)->static_fields;
                  v82 = v81->data;
                  if (v34 >= LODWORD(v82->max_length))
                    goto LABEL_112;
                }
                else
                {
                  v82 = v81->data;
                  if (v34 >= LODWORD(v82->max_length))
                  {
LABEL_112:
                  }
                }
                v84 = v82->m_Items[v34].num == v81->curpoint - 1;
                v85 = v200;
                if (v84)
                  v85 = 1;
                v200 = v85;
                if (v84)
                  v86 = 4;
                else
                  v86 = 14;
                if ((*(v76 + 295) & 2) == 0)
                  goto LABEL_124;
LABEL_120:
                if (!*(v76 + 216))
                {
                  v76 = *v23;
                }
                goto LABEL_124;
              }
            }
            v86 = 14;
            if ((*(v76 + 295) & 2) != 0)
              goto LABEL_120;
LABEL_124:
            v87 = *(*(v76 + 184) + 216LL);
            v88 = NewSpecific(object, 1u);
            LODWORD(v203[0]) = *(v77 + 20);
            v89 = v88;
            v90 = sub_8D3950(uint, v203);
            v92 = v90;
            v89->m_Items[0] = v92;
            v95 = sdfDevPrintf(
                    1152 * v79 + 31936,
                    96 * (v35 - v87) + 30976,
                    0xFEFFFFu,
                    v86,
                    "%05X,",
                    v89,
                    0);
            sdfDrawTagLink(aTag, v95);
            ++v79;
            v23 = v52;
            if (v79 >= 4)
            {
              v96 = *v52;
              if (((*v52)->_2.bitflags2 & 2) != 0 && !*(v96 + 216))
              {
                v96 = *v52;
              }
              v97 = *(*(v96 + 184) + 232LL);
              ++v35;
              v79 = 0;
              ++*(v97 + 24 * v34 + 44);
            }
            v99 = *v52;
            if (((*v52)->_2.bitflags2 & 2) != 0 && !*(v99 + 216))
            {
              v99 = *v52;
            }
            v100 = *(*(v99 + 184) + 232LL);
            ++*(v100 + 24 * v34 + 48);
            v76 = *v52;
            v77 = *(v77 + 72);
            v78 = ((*v52)->_2.bitflags2 & 2) == 0;
          }
          while (v77);
        }
        if (v78)
        {
          workdata = v199;
        }
        else
        {
          workdata = v199;
          if (!*(v76 + 216))
          {
            v76 = *v23;
          }
        }
        v102 = *(*(v76 + 184) + 232LL);
        if (*(v102 + 24 * v34 + 48) >= 1)
        {
          v104 = *v23;
          if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v104 + 216))
          {
            v104 = *v23;
          }
          v105 = *(*(v104 + 184) + 232LL);
          if ((*(v105 + 24 * v34 + 48) & 3) == 0)
          {
            v107 = *v23;
            if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v107 + 216))
            {
              v107 = *v23;
            }
            v108 = *(*(v107 + 184) + 232LL);
            --v35;
            --*(v108 + 24 * v34 + 44);
          }
        }
        ++v34;
        ++v35;
        v36 = *v23;
        if (((*v23)->_2.bitflags2 & 2) != 0)
          goto LABEL_54;
      }
      v48 = 0;
      if ((*(v44 + 295) & 2) == 0)
        goto LABEL_81;
LABEL_78:
      if (!*(v44 + 216))
      {
        v44 = *v23;
      }
      goto LABEL_81;
    }
  }
  v112 = dpy;
  v114 = Empty_string_();
  v116 = sdfDevPrintf(29056, 96 * (4 - v112) + 30976, 0xFEFFFFu, 0, "NO SCENE", v114, 0);
  sdfDrawTagLink(aTag, v116);
  v200 = 0;
  workdata = 0;
  LODWORD(v34) = 0;
  v35 = 3;
LABEL_179:
  v117 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v117);
  sdfDrawTagInit(v117);
  v120 = *v23;
  if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v120 + 216))
  {
    v120 = *v23;
  }
  dds3ConsPanelTagLink(v117, 24, 12 * (2 - *(*(v120 + 184) + 216LL)), 39, v35, 0);
  sdfDrawTagLinkOt(dds3Ot->m_Items[81], v117);
  v125 = dds3Ot;
  sdfDrawTagLinkOt(v125->m_Items[81], aTag);
  if (!v200)
  {
    v140 = *v23;
    if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v140 + 216))
    {
      v140 = *v23;
    }
    *(*(v140 + 184) + 220LL) = 0;
    v141 = *(v140 + 184);
    goto LABEL_214;
  }
  else if (!DDS3_PAD2CHECK_REP(7))
  {
    goto LABEL_240;
  }
  v129 = *v23;
  v130 = *&(*v23)->_2.bitflags1;
  if ((v130 & 0x200) == 0)
  {
    v131 = 0;
    p_static_fields = v129 + 184;
    v132 = *(v129 + 184);
    curpoint = v132->curpoint;
    if (curpoint)
      goto LABEL_198;
LABEL_218:
    if (v131 && !*(v129 + 216))
    {
      v129 = *v23;
      p_static_fields = &(*v23)->static_fields;
      v132 = *p_static_fields;
    }
    curbase = v132->curbase;
    if (curbase < v34 - 1)
    {
      if ((*(v129 + 295) & 2) != 0 && !*(v129 + 216))
      {
        p_static_fields = &(*v23)->static_fields;
        v132 = *p_static_fields;
        curbase = *(*p_static_fields + 220LL);
      }
      v144 = v132->data;
      v132->dpy += v144->m_Items[curbase].y;
      v146 = *(*p_static_fields + 232LL);
      v147 = *(*p_static_fields + 220LL);
      v149 = *v23;
      if (!*(v146 + 24 * v147 + 44))
      {
        if ((*(v149 + 295) & 2) != 0 && !*(v149 + 216))
        {
          v149 = *v23;
        }
        ++*(*(v149 + 184) + 216LL);
      }
      if ((*(v149 + 295) & 2) != 0 && !*(v149 + 216))
      {
        v149 = *v23;
      }
      ++*(*(v149 + 184) + 220LL);
        goto LABEL_208;
      goto LABEL_241;
    }
LABEL_240:
      goto LABEL_241;
    goto LABEL_208;
  }
  if (!*(v129 + 216))
  {
    v129 = *v23;
    v130 = *&(*v23)->_2.bitflags1;
  }
  v131 = v130 & 0x200;
  p_static_fields = v129 + 184;
  v132 = *(v129 + 184);
  curpoint = v132->curpoint;
  if (!curpoint)
    goto LABEL_218;
LABEL_198:
  if (v131 && !*(v129 + 216))
  {
    v132 = (*v23)->static_fields;
    curpoint = v132->curpoint;
  }
  v135 = v132->data;
  v136 = v132->curbase;
  if (curpoint + 4 > v135->m_Items[v136].num)
    goto LABEL_240;
  v138 = *v23;
  if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v138 + 216))
  {
    v138 = *v23;
  }
  *(*(v138 + 184) + 224LL) += 4;
  {
LABEL_208:
  }
LABEL_241:
  if (!DDS3_PAD2CHECK_REP(6))
    goto LABEL_275;
  v151 = *v23;
  v152 = *&(*v23)->_2.bitflags1;
  if ((v152 & 0x200) == 0)
  {
    v153 = 0;
    v155 = v151 + 184;
    v154 = *(v151 + 184);
    v156 = v154->curpoint;
    if (v156)
      goto LABEL_244;
LABEL_257:
    if (v153 && !*(v151 + 216))
    {
      v151 = *v23;
      v155 = &(*v23)->static_fields;
      v154 = *v155;
    }
    v159 = v154->curbase;
    if (v159 >= 1)
    {
      if ((*(v151 + 295) & 2) != 0 && !*(v151 + 216))
      {
        v155 = &(*v23)->static_fields;
        v154 = *v155;
        v159 = *(*v155 + 220LL);
      }
      v154->curbase = v159 - 1;
      v160 = *(*v155 + 232LL);
      v161 = *(*v155 + 220LL);
      *(*v155 + 216LL) -= *(v160 + 24 * v161 + 44);
      v163 = *(*v155 + 232LL);
      v164 = *(*v155 + 220LL);
      if (!*(v163 + 24 * v164 + 44))
      {
        v166 = *v23;
        if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v166 + 216))
        {
          v166 = *v23;
        }
        --*(*(v166 + 184) + 216LL);
          goto LABEL_276;
        goto LABEL_251;
      }
    }
    goto LABEL_275;
  }
  if (!*(v151 + 216))
  {
    v151 = *v23;
    v152 = *&(*v23)->_2.bitflags1;
  }
  v153 = v152 & 0x200;
  v155 = v151 + 184;
  v154 = *(v151 + 184);
  v156 = v154->curpoint;
  if (!v156)
    goto LABEL_257;
LABEL_244:
  if (v153 && !*(v151 + 216))
  {
    v151 = *v23;
    v154 = (*v23)->static_fields;
    v156 = v154->curpoint;
    if (v156 >= 5)
      goto LABEL_247;
  }
  else if (v156 >= 5)
  {
LABEL_247:
    if ((*(v151 + 295) & 2) != 0 && !*(v151 + 216))
    {
      v154 = (*v23)->static_fields;
      v156 = v154->curpoint;
    }
    v154->curpoint = v156 - 4;
      goto LABEL_276;
    goto LABEL_251;
  }
LABEL_275:
    goto LABEL_276;
LABEL_251:
LABEL_276:
  if (!DDS3_PAD2CHECK_REP(5))
    goto LABEL_291;
LABEL_277:
  v167 = *v23;
  if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v167 + 216))
  {
    v167 = *v23;
  }
  v168 = *(v167 + 184);
  v169 = v168->curpoint;
  if (v169 >= 1)
  {
    if ((*(v167 + 295) & 2) != 0 && !*(v167 + 216))
    {
      v168 = (*v23)->static_fields;
      v169 = v168->curpoint;
    }
    v170 = v168->data;
    v171 = v168->curbase;
    if (v169 < v170->m_Items[v171].num)
    {
      v173 = *v23;
      if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v173 + 216))
      {
        v173 = *v23;
      }
      ++*(*(v173 + 184) + 224LL);
    }
  }
LABEL_291:
  if (DDS3_PAD2CHECK_REP(4))
  {
    v175 = *v23;
    if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v175 + 216))
    {
      v175 = *v23;
    }
    v176 = *(v175 + 184);
    v177 = v176->curpoint;
    if (v177 >= 1)
    {
      if ((*(v175 + 295) & 2) != 0 && !*(v175 + 216))
      {
        v175 = *v23;
        v176 = (*v23)->static_fields;
        v177 = v176->curpoint;
      }
      if (v177 >= 2)
      {
        if ((*(v175 + 295) & 2) != 0 && !*(v175 + 216))
        {
          v176 = (*v23)->static_fields;
          v177 = v176->curpoint;
        }
        v176->curpoint = v177 - 1;
      }
    }
  }
  v178 = DDS3_PAD2CHECK_TRIG(1);
  if (!v198 || !v178)
    goto LABEL_342;
  v180 = *v23;
  if (((*v23)->_2.bitflags2 & 2) == 0 || *(v180 + 216))
  {
    v181 = *(v180 + 184);
    if (v181->curpoint)
      goto LABEL_315;
    goto LABEL_332;
  }
  v180 = *v23;
  v181 = (*v23)->static_fields;
  if (!v181->curpoint)
  {
LABEL_332:
    if ((*(v180 + 295) & 2) != 0 && !*(v180 + 216))
    {
      v181 = (*v23)->static_fields;
    }
    v191 = v181->data;
    v192 = v181->curbase;
    if (v191->m_Items[v192].num >= 1)
    {
      v194 = *v23;
      if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v194 + 216))
      {
        v194 = *v23;
      }
      *(*(v194 + 184) + 224LL) = 1;
    }
LABEL_342:
    v142 = 0;
    if (!DDS3_PAD2CHECK_TRIG(3))
      return v142;
    v196 = *v23;
    if (((*v23)->_2.bitflags2 & 2) != 0 && !*(v196 + 216))
    {
      v196 = *v23;
    }
    v141 = *(v196 + 184);
    if (!v141->curpoint)
    {
      v142 = 0;
      ida->func_ans = -1;
      return v142;
    }
    if ((*(v196 + 295) & 2) != 0 && !*(v196 + 216))
    {
      v141 = (*v23)->static_fields;
    }
LABEL_214:
    v142 = 0;
    v141->curpoint = 0;
    return v142;
  }
LABEL_315:
  v182 = workdata[2].klass;
  if ((*(v180 + 295) & 2) != 0 && !*(v180 + 216))
  {
    v181 = (*v23)->static_fields;
  }
  v183 = v181->data;
  v184 = v181->curbase;
  v186 = v183->m_Items[v184].type;
  v188 = *v23;
  v189 = 0;
  monitor = *(*(&v182->_1.byval_arg.data + v186) + 24LL);
  if (((*v23)->_2.bitflags2 & 2) != 0)
  {
LABEL_323:
    if (!*(v188 + 216))
    {
      v188 = *v23;
    }
  }
  while (v189 < *(*(v188 + 184) + 224LL) - 1)
  {
    ++v189;
    monitor = monitor[4].monitor;
    if ((*(v188 + 295) & 2) != 0)
      goto LABEL_323;
  }
  dds3SetProcessData(&ida, monitor);
  v142 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v142,
    0,
    Method_dds3DbgBasic_dds3DebugBasic__);
  return v142;
}

// 0x1366790
void evtSceneDispShutdown(dds3ProcessID_t *id) {
  dpy = 0;
}
