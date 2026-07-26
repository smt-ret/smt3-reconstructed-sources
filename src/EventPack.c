#include "types.h"

typedef struct AnimChecker AnimChecker;
typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtPackProcessData_t evtPackProcessData_t;
typedef struct evtTexManager evtTexManager;

static s32 AssetLoadWait;
static evtTexManager *currTexMngr;
static s32 DisableStop1EventNo;
static char *com_str;
static s32 evtRegistBEUnit_minor;
static s32 evtRegistBEUnit_buf;
static s32 save_serial;
static void *be_name;
static void *be_bnm;
static char *LoadPack_bename;
static void *m_key;
static void *v_key;
static s32 gSpEvtLoadPhase;
static s32 gSpEvtLoadIdx;
static s32 gSpEvtLoadNum[UNKNOWN_ARRAY_SIZE];
static s32 SPSE1;
static s32 SPFLD;
static s32 SPLNG;
static void *m_spkey1;
static void *m_spkey2;
static s32 EventNoSw;
static s32 CurrentEvent;

s32 AttachModel_26586560(dds3Basic_t *basic, char *key, char *chkname, char *name);
void BillSetTexture(evtTexManager *this);
void CheckLoadPack(evtPackProcessData_t *data);
void Destroy(evtTexManager *this, bool unload);
void Eve_DistortionBlurSetDefTex(void);
void Eve_DistortionBlurSetTex(void *hTex);
void Eve_PartialMultiBlurSetDefTex(void);
void Eve_PartialMultiFilterSetDefTex(void);
void Eve_RippleBlurSetDefTex(void);
void FinalizeLoadManager(bool sw);
bool FldDataCheck(s32 field, s32 area);
void *GetAnimator(void *obj);
char *GetAppendix(void);
char *GetDLCTag(s32 eventno);
EventEMsgData *GetData(char *key);
void Initialize(evtTexManager *this, char *key, char *path);
bool IsAnimStarted(AnimChecker *this, s32 LayerIndex);
bool IsDLC(void);
bool IsLoad(AssetBundles *this, char *key);
bool IsNoText(s32 eventno);
bool IsStartModelLoaded(void);
void Load(char *key, char *filePath);
void LoadAssetExt(char *key, char *name, char *dlc);
void LoadDirect(AssetBundleCtrl *this, char *key, char *aname, s32 dlc_id);
void LoadEventData(char *key, s32 e, bool ecmnf);
void LoadEventModel(void);
void LoadEventVoice(s32 eventno, char *key, EventEMsgData *data);
void *LoadFile_16626736(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void LoadPack(evtPackProcessData_t *data);
void Log(char *fmt, void **parray);
void MarkPibIndex(u8 ***bData);
void MarkTmxIndex(u8 ***bData);
void ReleaseManiacsChar(void);
void Remove(char *key);
void RemoveKeys(s32 type, char *key);
void SetBoostFrameRate(dds3DefaultMain *this);
void SetDrawFlag(u32 flag, u32 cnt);
void SetNormalFrameRate(dds3DefaultMain *this);
void SetShadowMode(dds3DefaultMain *this, s32 mode);
bool SpEvtCheckLoad(s32 eventno);
s32 SpEvtLoadFinished(void);
void SpEvtUnloadAll(s32 eventno);
void StartLoad(void);
void UnloadAB(AssetBundleCtrl *this, char *key);
void UnloadALL(bool all);
void WindowDispOff(bool sw);
void billAlfRaitoSet(f32 raito);
void billCutRaitoSet(f32 raito);
void billScaleRaitoSet(f32 par_scl_raito, f32 eff_scl_raito);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetControlScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
evtPackProcessData_t *evtGetPackProcessData(s32 eventno);
s32 evtLoadArea_FromMemory(s32 fld, s32 area, u8 **pF1, u8 **pF2, u8 **pTB, u8 **pBF);
s32 evtPlaySe(s32 eventno, s32 seno);
dds3ProcessID_t *evtSearchEventPack(s32 eventno);
s32 evtSetRegistUnit(s32 major, s32 minor);
void fldCmnBgmSeUnload(void);
void fldEventDataUnload(void);
void fldFileAddrResetMode(s32 mode);
void fldFootSeUnload(void);
void fldFreeNextFile(void);
void tpAlfRaitoSet(f32 raito);

// 0xfed800
void CheckLoadPack(evtPackProcessData_t *data) {
    GetDLCTag(0);
    LoadFile_16626736(0, 0, 0);
    Log(0, 0);
    MarkTmxIndex(0);
    MarkPibIndex(0);
    Destroy(0, 0);
    GetData(0);
    Initialize(0, 0, 0);
    Initialize(0, 0, 0);
    BillSetTexture(0);
}

// 0xfea200
void LoadPack(evtPackProcessData_t *data) {
    GetDLCTag(0);
    SetBoostFrameRate(0);
    Log(0, 0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    LoadEventData(0, 0, 0);
    LoadDirect(0, 0, 0, 0);
    SpEvtCheckLoad(0);
    StartLoad();
    SpEvtLoadFinished();
    Load(0, 0);
    SetNormalFrameRate(0);
}

// 0xfe7480
void SetEventPackName(s32 eventno, char **name) {
}

// 0xfeac60
bool SpEvtCheckLoad(s32 eventno) {
    Log(0, 0);
    IsNoText(0);
    IsDLC();
    return 0;
}

// 0xfeb990
s32 SpEvtLoadFinished(void) {
    IsLoad(0, 0);
    GetDLCTag(0);
    LoadAssetExt(0, 0, 0);
    LoadEventData(0, 0, 0);
    GetData(0);
    LoadEventVoice(0, 0, 0);
    LoadKeys(0, 0, 0);
    return 0;
}

// 0xfec340
void SpEvtUnloadAll(s32 eventno) {
    GetDLCTag(0);
    GetAppendix();
    IsNoText(0);
    IsDLC();
    Log(0, 0);
    UnloadAB(0, 0);
    RemoveKeys(0, 0);
    Remove(0);
    WindowDispOff(0);
    FinalizeLoadManager(0);
}

// 0xfe9d10
void UnloadALL(bool all) {
  AssetBundleCtrl_o *asset_bc;
  u32 Count;
  System_String_array *v5;
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;
  il2cpp_array_size_t max_length;
  u64 v9;
  Il2CppClass **v11;
  System_String_o **v12;
  System_String_o *v13;
  System_String_o *v14;
  System_String_o *v15;
  System_String_o *v17;
  System_String_o *v22;
  AssetBundleCtrl_o *v25;
  AssetBundleCtrl_o *v28;
  AssetBundleCtrl_o *v31;
  s32 result;

  result = 0;
  asset_bc = get_asset_bc();
  Count = HashSet_Text____get_Count(asset_bc->assetbundle);
  v5 = NewSpecific(string, Count);
  Keys = string___get_Keys(asset_bc->assetbundle);
  string___CopyTo(Keys, v5, 0);
  max_length = v5->max_length;
  if (max_length >= 1)
  {
    v9 = 0;
    do
    {
      v11 = &v5->obj.klass + v9;
      v13 = v11[4];
      v12 = (v11 + 4);
      v14 = Substring_5248048(v13, 0, 1);
      v15 = ToUpper(v14, 0);
      if (!op_Inequality(v15, StringLiteral_4683, 0)
        || !op_Inequality(v15, StringLiteral_703, 0))
      {
        result = -1;
        v17 = Substring_5248048(*v12, 1, 3);
        if (TryParse(v17, &result, 0))
        {
          if (get_Length(*v12) == 4)
          if (get_Length(*v12) == 5)
          {
            v22 = *v12;
            {
            }
            RemoveKeys(1, v22);
            RemoveKeys(3, *v12);
            RemoveKeys(4, *v12);
          }
          if (all)
          {
            while (1)
            {
              v28 = get_asset_bc();
              if (!IsLoad(v28, *v12))
                break;
              v31 = get_asset_bc();
              UnloadAB(v31, *v12);
            }
          }
          else
          {
            v25 = get_asset_bc();
            UnloadAB(v25, *v12);
          }
        }
      }
      LODWORD(max_length) = v5->max_length;
      ++v9;
    }
    while (v9 < max_length);
  }
  RemoveKeys(5, 0);
  SndAssetBundleManager_SndData___Clear(VoiceBundleTable);
  fldEventDataUnload();
  fldFootSeUnload();
  fldCmnBgmSeUnload();
  UnloadALL(0);
  ReleaseManiacsChar();
  PlayEventNo = 0;
}

// 0xfe7f00
void evtDispBlurTexSet(s32 eventno, s32 rid) {
    evtGetPackProcessData(0);
    LoadFile_16626736(0, 0, 0);
    Eve_DistortionBlurSetTex(0);
}

// 0xfe7620
s32 evtGetEventPackStat(s32 eventno) {
    evtSearchEventPack(0);
    dds3GetProcessData(0);
    return 0;
}

// 0xfe77a0
evtPackProcessData_t *evtGetPackProcessData(s32 eventno) {
    evtSearchEventPack(0);
    dds3GetProcessData(0);
    return 0;
}

// 0xfe7930
u8 **evtGetResorceData(s32 eventno, s32 rid) {
    evtSearchEventPack(0);
    tpAlfRaitoSet(0);
    billAlfRaitoSet(0);
    billScaleRaitoSet(0, 0);
    billCutRaitoSet(0);
    dds3GetProcessData(0);
    BillSetTexture(0);
    return 0;
}

// 0xfe9950
dds3ProcessID_t *evtInitMotionSeProcess(s32 unitid, s32 eventno, s32 rid) {
    evtGetPackProcessData(0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    return 0;
}

// 0xfef1c0
void evtKillAllEventPackProcess(void) {
  u64 *v1;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  {
  }
  while (1)
  {
    id = dds3SearchProcessPriority(1004);
    if (!id)
      break;
    dds3KillProcess(&id, 0);
  }
}

// 0xfef000
void evtKillEventPack(s32 eventno) {
    evtSearchEventPack(0);
    dds3GetProcessData(0);
    dds3KillProcess(0, 0);
}

// 0xfeed20
dds3ProcessID_t *evtLoadEventPack(s32 eventno) {
    evtSearchEventPack(0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    SetShadowMode(0, 0);
    return 0;
}

// 0xfe8d40
void *evtMotionSeProcess1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    dds3GetActiveScene();
    dds3SearchSceneBasic(0, 0, 0);
    evtGetPackProcessData(0);
    GetAnimator(0);
    IsAnimStarted(0, 0);
    Log(0, 0);
    evtPlaySe(0, 0);
    return 0;
}

// 0xfe98d0
void *evtMotionSeShutdown(dds3ProcessID_t *id) {
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3GetProcessData(&ida);
  ida->func_ans = -1;
  return 0;
}

// 0xfee430
void *evtPackProcess1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    CheckLoadPack(0);
    LoadPack(0);
    return 0;
}

// 0xfee5b0
void *evtPackShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    fldFreeNextFile();
    Log(0, 0);
    Destroy(0, 0);
    Destroy(0, 0);
    SpEvtUnloadAll(0);
    RemoveKeys(0, 0);
    Eve_DistortionBlurSetDefTex();
    Eve_PartialMultiBlurSetDefTex();
    Eve_RippleBlurSetDefTex();
    Eve_PartialMultiFilterSetDefTex();
    return 0;
}

// 0xfe8820
s32 evtRegistBEField(s32 eventno, s32 rid) {
    evtGetPackProcessData(0);
    FldDataCheck(0, 0);
    evtLoadArea_FromMemory(0, 0, 0, 0, 0, 0);
    fldFileAddrResetMode(0);
    SetDrawFlag(0, 0);
    return 0;
}

// 0xfe8100
s32 evtRegistBEUnit(s32 eventno, s32 rid) {
    evtGetPackProcessData(0);
    Log(0, 0);
    evtSetRegistUnit(0, 0);
    dds3GetControlScene();
    dds3SearchSceneBasic(0, 0, 0);
    AttachModel_26586560(0, 0, 0, 0);
    LoadEventModel();
    IsStartModelLoaded();
    return 0;
}

// 0xfe7500
dds3ProcessID_t *evtSearchEventPack(s32 eventno) {
    dds3SearchProcessName(0);
    return 0;
}
