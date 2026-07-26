#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbMain_procDelegate pbMain_procDelegate;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdf3DFogParam_t sdf3DFogParam_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static sdfMemHandle_t *hMem;
static u32 flowId;
static u32 flg;
static pbProcHandle_t *root;
static pbProcHandle_t *current_proc;
static pbMain_procDelegate *proc[4];
static sdfVector4_t pbCameraTgt[3];
static sdfVector4_t pbCameraEye[3];
static void *pbBGTex;
static char *a_key;
static sdf3DFogParam_t *pbInitMain_fogparam;
static u32 s_mode;
static s32 s_level;

void ClrDrawFlag(u32 flag);
bool DDS3_PADCHECK_TRIG(s32 id);
s32 FindId(s32 type, char *name);
char *GetAkey(s32 no);
char *GetAppendix(void);
char *GetPlatformStr(void);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void LoadLocalizeText(char *key, char *filename);
void Remove(char *key);
void RemoveKeys(s32 type, char *key);
void UnloadAB(AssetBundleCtrl *this, char *key);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetAmbientColor(u32 frame, sdfVector4_t col);
void dds3SetFog(sdf3DFogParam_t *fog);
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col);
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s8 fclChkSignal(s8 Idx);
s32 fldProcNextJump(void);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
void p2sdSndStopAll(void);
dds3ProcessID_t *pbGetMessageScriptProc(void);
void pbInitKeyAction(void);
void pbInitMain(u32 mode, s32 level);
pbProcHandle_t *pbStartBackGround(pbProcHandle_t **parent);
void pb_General__SET_MAP_BLK_(s32 x, s32 y, s32 v);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);

// 0x14a3500
s32 dds3DeleteDebugList(char *name) {
  return 0;
}

// 0x14a3510
void dds3PrintProcessTree(void) {
  ;
}

// 0x14a5950
dds3ProcessFunc_t *deleteDrawBG(dds3ProcessID_t *id) {
    return 0;
}

// 0x14a5580
dds3ProcessFunc_t *deleteDummy(dds3ProcessID_t *id) {
    return 0;
}

// 0x14a5690
dds3ProcessFunc_t *drawBG(dds3ProcessID_t *id) {
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    pbGetMessageScriptProc();
    fclChkSignal(0);
    return 0;
}

// 0x14a5450
dds3ProcessFunc_t *dummy(dds3ProcessID_t *id) {
    return 0;
}

// 0x14a5a60
dds3ProcessID_t *init_puzzleboy(u32 mode, s32 level) {
  s32 v6;
  struct pbProcHandle_t_o *root;
  u64 *v8;
  u64 *v9;
  System_String_o *a_key;
  System_String_o *Appendix;
  struct System_String_o *v15;
  System_String_o *v17;
  System_String_o *v18;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v21;
  AssetBundleCtrl_o *v22;
  System_String_o *PlatformStr;
  System_String_o *v24;
  System_String_o *v25;
  System_String_o *v26;
  System_String_o *v27;
  System_String_o *v28;

  flg = 0;
  s_mode = mode;
  s_level = level;
  switch (mode)
  {
    case 2u:
      v6 = 2;
    case 1u:
      v6 = 1;
    case 0u:
      v6 = 0;
      flowId = v6;
      break;
  }
  current_proc = 0;
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbMain_pbEditInitProc__);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_pbMain_pbEditMainExitProc__);
  root->id = dds3StartProcess(StringLiteral_21844, 0x3EEu, 1, 0, v8, 0, v9, 0, 0, 0);
  a_key = StringLiteral_21832;
  Appendix = GetAppendix();
  v15 = Replace_5267216(a_key, Appendix, StringLiteral_416);
  a_key = v15;
  v17 = a_key;
  v18 = GetAppendix();
  a_key = Concat_5224608(v17, v18);
  asset_bc = get_asset_bc();
  Load(asset_bc, a_key, a_key, 0);
  v21 = get_asset_bc();
  Load(v21, StringLiteral_21832, StringLiteral_21832, 0);
  v22 = get_asset_bc();
  PlatformStr = GetPlatformStr();
  v24 = GetAppendix();
  v25 = Concat_5221536(StringLiteral_21832, PlatformStr, v24);
  v26 = GetPlatformStr();
  v27 = GetAppendix();
  v28 = Concat_5221536(StringLiteral_21832, v26, v27);
  Load(v22, v25, v28, 0);
  return root->id;
}

// 0x14a4710
void init_puzzleboy2(u32 mode, s32 level) {
  u32 v4;

  pbInitMain(v4, level);
  pbStartBackGround(&root);
}

// 0x14a3530
s32 itfMiscSetVector4(sdfVector4_t p, f32 x, f32 y, f32 z, f32 w) {
  return 0;
}

// 0x14a4550
void *pbEditInit2Proc(dds3ProcessID_t *id) {
  System_String_o *Akey;
  AssetBundleCtrl_o *asset_bc;
  bool IsLoad;
  u64 *v8;
  pbMain_c *v9;
  s32 s_level;

  Akey = GetAkey(336);
  asset_bc = get_asset_bc();
  IsLoad = IsLoad(asset_bc, Akey);
  v8 = 0;
  if (IsLoad)
  {
    pbInitMain(v9, s_level);
    pbStartBackGround(&root);
    LoadKeys(1, StringLiteral_21832, 0);
    LoadKeys(3, StringLiteral_21832, 0);
    v8 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v8,
      0,
      Method_pbMain_pbEditMainProc__);
  }
  return v8;
}

// 0x14a4400
void *pbEditInitProc(dds3ProcessID_t *id) {
  AssetBundleCtrl_o *asset_bc;
  bool IsLoad;
  u64 *v7;
  System_String_o *Akey;
  AssetBundleCtrl_o *v10;

  asset_bc = get_asset_bc();
  IsLoad = IsLoad(asset_bc, a_key);
  v7 = 0;
  if (IsLoad)
  {
    Akey = GetAkey(336);
    v10 = get_asset_bc();
    Load(v10, Akey, Akey, 0);
    v7 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v7,
      0,
      Method_pbMain_pbEditInit2Proc__);
  }
  return v7;
}

// 0x14a5110
dds3ProcessFunc_t *pbEditMainExitProc(dds3ProcessID_t *id) {
  struct dds3ModelFileTable_t_array *devilModelFileTable;
  System_String_o *akey;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v10;
  AssetBundleCtrl_o *v12;
  AssetBundleCtrl_o *v14;
  System_String_o *PlatformStr;
  System_String_o *Appendix;
  System_String_o *v17;
  System_String_o *v20;
  System_String_o *v21;
  struct pbWork_t_o *pbWk;

  p2sdSndStopAll();
  RemoveKeys(1, StringLiteral_21832);
  RemoveKeys(3, StringLiteral_21832);
  akey = devilModelFileTable->m_Items[336]->akey;
  asset_bc = get_asset_bc();
  UnloadAB(asset_bc, akey);
  v10 = get_asset_bc();
  UnloadAB(v10, a_key);
  v12 = get_asset_bc();
  UnloadAB(v12, StringLiteral_21832);
  v14 = get_asset_bc();
  PlatformStr = GetPlatformStr();
  Appendix = GetAppendix();
  v17 = Concat_5221536(StringLiteral_21832, PlatformStr, Appendix);
  UnloadAB(v14, v17);
  pbWk->blockTex = 0;
  pbWk->bgTex = 0;
  pbWk->etcTex = 0;
  pbWk->helpTex = 0;
  Remove(StringLiteral_21769, 0);
  Remove(StringLiteral_21838, 0);
  v20 = GetPlatformStr();
  v21 = Concat_5224608(StringLiteral_21838, v20);
  Remove(v21, 0);
  if (pbWk->pscript)
  {
    pbWk->pscript = 0;
  }
  pbStartCameraPosflag = 0;
  fldProcNextJump();
  return 0;
}

// 0x14a4790
void *pbEditMainProc(dds3ProcessID_t *id) {
    LoadKeys(0, 0, 0);
    FindId(0, 0);
    p2sdFadeOut(0);
    DDS3_PADCHECK_TRIG(0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    return 0;
}

// 0x14a6050
pbProcHandle_t *pbGetCurrentProcess(void) {
  return current_proc;
}

// 0x14a3540
void pbInitMain(u32 mode, s32 level) {
    pb_General__SET_MAP_BLK_(0, 0, 0);
    LoadFileObject(0, 0, 0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    LoadLocalizeText(0, 0);
    GetPlatformStr();
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    dds3SetFog(0);
    ClrDrawFlag(0);
    pbInitKeyAction();
    FindId(0, 0);
    p2sdPlayBGM(0);
}

// 0x14a5dc0
pbProcHandle_t *pbStartBackGround(pbProcHandle_t **parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x14a60c0
pbProcHandle_t *pbStartDummy(pbProcHandle_t **parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x14a3520
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
