#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct DLCDevilData DLCDevilData;
typedef struct DlcFileCtr DlcFileCtr;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3KernelMain dds3KernelMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;

struct dds3KernelMain {
    u16 dds3RunTime;
    u8 dds3ReqPacketDump;
    u16 dds3DrawTimeCount;
    u16 dds3SleepTime;
};

static u32 dds3FrameCount;
static u32 dds3RunCount;
static s32 dds3FrameID;
static s32 dds3SoftResetFlag;
static s32 dds3SoftResetFlagUnLoad;
static s32 dds3SoftResetTrigFlag;
static s32 dds3SoftResetDisableFlag;
static s32 dds3PauseSign;
static u32 dds3PauseTime;
static s32 dds3SlowSign;
static s32 dds3SlowTime;
static u32 dds3SlowRunCount;
static s32 dds3SlowEndCount;
static s32 dds3CaptureSign;
static s32 dds3CaptureCount;
static void *dds3UnityTimeStopWatch;
static f32 dds3UnityRunTime_Old;
static f32 dds3UnityRunTime_Now;
static s32 dds3DebugSign;
static s32 dds3KernelDebugSign;
static s32 dds3FileLoadPrioMode;
static s32 capwait;
static void *uim;
static DLCDevilData *DLCDevilDataExp;
static DLCDevilData *DLCDevilDataMaka;

void ButtonGuideInit(void);
bool Check(DlcFileCtr *this, s32 id);
void DLCDevilLoad(void);
void Load(char *key, char *filePath);
void *LoadAsset(AssetBundleCtrl *this, char *key, char *path, char *name);
void PadEi(void);
dds3Basic_t *dds3AddWorld(s32 bufcnt);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3EffectManagerInit(void);
void dds3Effect_UpdateBigin(void);
void dds3Effect_UpdateEnd(void);
void dds3FirstInit(void);
void dds3GlobalWorkInit(void);
void dds3InitAdmini(void);
void dds3InitDebugSystem(void);
void dds3InitDrawEnv(void);
void dds3InitRandCB(void);
void dds3PadInitialize(void);
void dds3PadUpdate(void);
s32 dds3ProcessMain(void);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void effBTLSystemInit(void);
void encInitProcess(void);
void evtInitMoonProcess(void);
void evtPicturePriProcessInit(void);
void fldFirstInit(void);
void frInitFontTable(s32 GsFontNums, s32 TextNums);
void itfMesMngInitializeManager(void);
void sndInit(void);

// 0x14e3dc0
void DLCDevilAssetLoad(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;
  UnityEngine_Object_o *DLCDevilDataExp;
  AssetBundleCtrl_o *v8;
  UnityEngine_Object_o *Asset;
  struct dds3KernelMain_StaticFields *static_fields;
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v13;
  AssetBundleCtrl_o *v14;
  DlcFileCtr_o *v15;
  UnityEngine_Object_o *DLCDevilDataMaka;
  AssetBundleCtrl_o *v21;
  UnityEngine_Object_o *v24;
  struct dds3KernelMain_StaticFields *v25;
  s64 v26;
  UnityEngine_Object_o *v27;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  if (Check(dlc, 6, 0))
  {
    if (op_Equality(DLCDevilDataExp, 0, 0))
    {
      v8 = get_asset_bc();
      {
      }
      Asset = LoadAsset(
                v8,
                StringLiteral_14752,
                DLC6DataAssetPath,
                StringLiteral_14752,
                0);
      else
      {
        static_fields = dds3KernelMain->static_fields;
        if (!Asset)
      }
      if (Asset->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
      {
        if (Asset->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == DLCDevilData)
          v13 = Asset;
        else
          v13 = 0;
      }
      v13 = 0;
      static_fields->DLCDevilDataExp = v13;
    }
  }
  v14 = get_asset_bc();
  v15 = get_dlc(v14);
  if (Check(v15, 7, 0))
  {
    if (op_Equality(DLCDevilDataMaka, 0, 0))
    {
      v21 = get_asset_bc();
      {
      }
      v24 = LoadAsset(
              v21,
              StringLiteral_14753,
              DLC7DataAssetPath,
              StringLiteral_14753,
              0);
      else
      {
        v25 = dds3KernelMain->static_fields;
        if (!v24)
      }
      if (v24->klass->_2.typeHierarchyDepth >= v26)
      {
        if (v24->klass->_2.typeHierarchy[v26 - 1] == DLCDevilData)
          v27 = v24;
        else
          v27 = 0;
      }
      v27 = 0;
      v25->DLCDevilDataMaka = v27;
    }
  }
}

// 0x14e1740
void DLCDevilLoad(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;
  AssetBundleCtrl_o *v5;
  DlcFileCtr_o *v6;
  AssetBundleCtrl_o *v7;
  DlcFileCtr_o *v8;
  AssetBundleCtrl_o *v10;
  DlcFileCtr_o *v11;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  if (Check(dlc, 6, 0))
  {
    v5 = get_asset_bc();
    v6 = get_dlc(v5);
    Load(v6, StringLiteral_14752, 6, StringLiteral_14752, 0);
  }
  v7 = get_asset_bc();
  v8 = get_dlc(v7);
  if (Check(v8, 7, 0))
  {
    v10 = get_asset_bc();
    v11 = get_dlc(v10);
    Load(v11, StringLiteral_14753, 7, StringLiteral_14753, 0);
  }
}

// 0x14e1940
void KernelDebug(void) {
  ;
}

// 0x14e1930
void KernelDebugPro(void) {
  ;
}

// 0x14e39c0
bool dds3CheckDLC1(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  return Check(dlc, 1, 0);
}

// 0x14e3a40
bool dds3CheckDLC2(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  return Check(dlc, 2, 0);
}

// 0x14e3ac0
bool dds3CheckDLC3(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  return Check(dlc, 3, 0);
}

// 0x14e3b40
bool dds3CheckDLC4(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  return Check(dlc, 4, 0);
}

// 0x14e3bc0
bool dds3CheckDLC5(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  return Check(dlc, 5, 0);
}

// 0x14e3c40
bool dds3CheckDLC6(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  return Check(dlc, 6, 0);
}

// 0x14e3cc0
bool dds3CheckDLC7(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  return Check(dlc, 7, 0);
}

// 0x14e3d40
bool dds3CheckDLC8(void) {
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;

  asset_bc = get_asset_bc();
  dlc = get_dlc(asset_bc);
  return Check(dlc, 8, 0);
}

// 0x14df570
void dds3FirstInit(void) {
  u64 *v5;
  u64 *v7;
  u64 *v8;
  u64 *v11;
  u64 *v12;
  u64 *v14;
  u64 *v15;
  dds3ProcessID_t_o *started;
  UnityEngine_GameObject_o *BrighTextMesh;
  u64 *v35;

  Log(StringLiteral_14741, 0);
  dds3InitDrawEnv();
  dds3PadInitialize();
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_dds3KernelProcess_dds3FirstProcess__);
  dds3StartProcess(StringLiteral_14742, 0, 0, 0, v5, 0, 0, 0, 0, 0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_dds3KernelProcess_dds3DrawFirstProcess__);
  dds3StartProcess(StringLiteral_14743, 0x2710u, 0, 0, v7, 0, 0, 0, 0, 0);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_dds3KernelProcess_dds3DrawProcess__);
  dds3StartProcess(StringLiteral_14744, 0x4E20u, 0, 0, v8, 0, 0, 0, 0, 0);
  dds3TheWorld = 0;
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_dds3KernelProcess_dds3BasicMainProcess__);
  dds3StartProcess(StringLiteral_14745, 0x3FCu, 1, 1, v11, 0, 0, 0, 0, 0);
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_dds3KernelProcess_dds3BasicDrawProcess__);
  dds3StartProcess(StringLiteral_14746, 0x2B09u, 1, 1, v12, 0, 0, 0, 0, 0);
  frInitFontTable(256, 512);
  v14 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v14,
    0,
    Method_frFont_frFlipPacketBuf__);
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_frFont_frDestroyFontTable__);
  started = dds3StartProcess(StringLiteral_14747, 0x4E1Fu, 0, 0, v14, 0, v15, 0, 0, 0);
  create_interface(started);
  itfMesMngInitializeManager();
  sndInit();
  dds3EffectManagerInit();
  fldFirstInit();
  effBTLSystemInit();
  evtPicturePriProcessInit();
  dds3GlobalWorkInit();
  dds3SoftResetFlag = 0;
  dds3FrameCount = 0;
  dds3AddWorld(10000);
  dds3InitRandCB();
  dds3InitAdmini();
  dds3AdminiCallSequence(2, 0, 0, 0);
  dds3InitDebugSystem();
  evtInitMoonProcess();
  encInitProcess();
  BrighTextMesh = kernelObject->BrighTextMesh;
  if (!get_activeSelf(BrighTextMesh))
    SetActive(BrighTextMesh, 1, 0);
  DLCDevilLoad();
  ButtonGuideInit();
  v35 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v35,
    0,
    Method_ButtonGuide_ButtonGuideMain__);
  dds3StartProcess(StringLiteral_14748, 0x5214u, 0, 0, v35, 0, 0, 0, 0, 0);
}

// 0x14e1a30
s32 dds3GetFrameID(void) {
  return dds3FrameID;
}

// 0x14e19c0
u32 dds3GetKernelCount(void) {
  return dds3FrameCount;
}

// 0x14e1b20
void dds3PauseOff(void) {
  dds3PauseSign = 0;
  dds3PauseTime = 0;
  dds3SlowSign = 0;
}

// 0x14e1aa0
void dds3PauseOn(void) {
  dds3PauseSign = 1;
  dds3PauseTime = 0;
  dds3SlowSign = 0;
}

// 0x14e1d70
void dds3ScreenCaptureOff(void) {
  ;
}

// 0x14e1d60
void dds3ScreenCaptureOn(s32 count) {
  ;
}

// 0x14e1cd0
void dds3SlowOff(void) {
  dds3PauseSign = 0;
  dds3PauseTime = 0;
  dds3SlowSign = 0;
  dds3SlowTime = 4;
}

// 0x14e1c20
void dds3SlowOn(s32 aSlowTime, s32 slowcnt) {
  dds3PauseSign = 0;
  dds3PauseTime = 0;
  dds3SlowSign = 1;
  dds3SlowTime = aSlowTime;
  dds3SlowRunCount = dds3RunCount;
  dds3SlowEndCount = slowcnt;
}

// 0x14e1950
void dds3SoftReset(void) {
  dds3SoftResetFlag = 1;
}

// 0x14e1df0
void dds3SoftResetOff(void) {
  dds3SoftResetDisableFlag = 1;
}

// 0x14e1d80
void dds3SoftResetOn(void) {
  dds3SoftResetDisableFlag = 0;
}

// 0x14e1ba0
void dds3Stop(u32 frame) {
  dds3PauseSign = 1;
  dds3PauseTime = frame;
  dds3SlowSign = 0;
}

// 0x14dfbf0
void dds3UnityInit(void) {
  ;
}

// 0x14e1e60
void m_dds3KernelMainInit(void) {
  Log(StringLiteral_14749, 0);
  dds3FirstInit();
  Start(dds3UnityTimeStopWatch);
}

// 0x14e1f10
void m_dds3KernelMainLoop(void) {
    dds3Effect_UpdateBigin();
    dds3PadUpdate();
    dds3ProcessMain();
    PadEi();
    dds3Effect_UpdateEnd();
}
