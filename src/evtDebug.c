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
static evtDebug_evtSceneDisp data[UNKNOWN_ARRAY_SIZE];
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
    dds3GetActiveScene();
    return 0;
}

// 0x1364810
void *CheckAssetBundleData(void) {
    GetDLCTag(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    IsFileExists(0, 0, 0);
    return 0;
}

// 0x13618d0
bool DispStatus(void) {
  struct evtDebug_StaticFields *static_fields;

  if (!dds3DebugSign)
    return 0;
  static_fields = evtDebug->static_fields;
  if (!static_fields->bStatus)
    return 0;
  return static_fields->debug_draw == 1;
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
  v9 = sdfDevPrintf(28864, 35056, 0xFF0000u, 0, StringLiteral_15637, v4);
  sdfDrawTagLink(v2, v9);
  v10 = NewSpecific(object, 1u);
  v12 = v10;
  v12[4] = TagName;
  v14 = sdfDevPrintf(28864, 35152, 0xFF0000u, 0, StringLiteral_15638, v12);
  sdfDrawTagLink(v2, v14);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v2);
}

// 0x1362ab0
void *EventDebugProcess1(dds3ProcessID_t *id) {
    sdfDrawTagInit(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    evtBitCheck(0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    GetDbgEventName(0);
    sdfDrawTagLinkOt(0, 0);
    DDS3_PADCHECK_REP(0);
    evtBitOn(0);
    evtBitOff(0);
    DDS3_PADCHECK_TRIG(0);
    GetDLCTag(0);
    dds3FadeOut(0, 0, 0, 0);
    evtBitAllOff();
    CheckAssetBundleData();
    return 0;
}

// 0x1362190
void *EventDebugProcess2(dds3ProcessID_t *id) {
    GetDLCTag(0);
    GetEventFileNameToAssetName(0);
    Log(0, 0);
    IsLoad(0, 0);
    UnloadAB(0, 0);
    LoadAssetExt(0, 0, 0);
    Load(0, 0);
    SpEvtCheckLoad(0);
    SpEvtLoadFinished();
    StartLoad();
    Load(0, 0);
    LoadEventData(0, 0, 0);
    scrStartScript3(0, 0, 0, 0);
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
    dds3GetActiveScene();
    return 0;
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

  v2 = dds3SearchProcessName(StringLiteral_15655);
  return (v2 | dds3SearchProcessName(StringLiteral_15656)) == 0;
}

// 0x1364ec0
void evtExitEventTest(void) {
    dds3KillProcessName(0, 0);
    evtFreeStage();
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
  dds3StartProcess(StringLiteral_15655, 0x2AF9u, 1, 1, v4, 0, v5, 0, 0, 0);
}

// 0x1365020
void *evtSceneDispProcess(dds3ProcessID_t *id) {
    sdfDrawTagInit(0);
    dds3GetActiveScene();
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
    DDS3_PAD2CHECK_REP(0);
    DDS3_PAD2CHECK_TRIG(0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x1366790
void evtSceneDispShutdown(dds3ProcessID_t *id) {
  dpy = 0;
}
