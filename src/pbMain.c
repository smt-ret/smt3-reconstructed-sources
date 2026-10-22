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
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  workdata = id->workdata;
  else if (!workdata)
  {
    return 0;
  }
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  return 0;
}

// 0x14a5580
dds3ProcessFunc_t *deleteDummy(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  return 0;
}

// 0x14a5690
dds3ProcessFunc_t *drawBG(dds3ProcessID_t *id) {
  s32 *workdata;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v8;
  u64 v13[3];

  workdata = id->workdata;
  if (workdata)
  {
    v4 = *workdata;
    if (*(*workdata + 288LL) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != pbProcHandle_t)
    {
      sub_8FC2C0(*(v4 + 64), pbProcHandle_t, v13);
      if ((v13[0] & 1) != 0)
        v6 = v13[2];
      else
        v6 = v13 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = workdata[6] >> 16;
  if (v8 == 5)
    goto LABEL_28;
LABEL_13:
  if (v8 == 1)
  {
    workdata[6] = 0;
  }
  rsetOtOfs(39);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  rsetTest(1, 5, 128, 3, 0, 0, 1, 2);
  rsetOtOfs(71);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  else if (pbGetMessageScriptProc())
  {
    goto LABEL_24;
  }
  fclChkSignal(0);
  {
LABEL_25:
  }
  return 0;
}

// 0x14a5450
dds3ProcessFunc_t *dummy(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  workdata = id->workdata;
  else if (!workdata)
  {
    goto LABEL_15;
  }
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  LODWORD(workdata[1].monitor) = 0x20000;
LABEL_15:
  id->func_ans = -1;
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
      goto LABEL_21;
    case 1u:
      v6 = 1;
      goto LABEL_21;
    case 0u:
      v6 = 0;
LABEL_21:
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
  root->id = dds3StartProcess("puzzleBoy-root", 0x3EEu, 1, 0, v8, 0, v9, 0, 0, 0);
  a_key = "pazzleboy";
  Appendix = GetAppendix();
  v15 = Replace_5267216(a_key, Appendix, "");
  a_key = v15;
  v17 = a_key;
  v18 = GetAppendix();
  a_key = Concat_5224608(v17, v18);
  asset_bc = get_asset_bc();
  Load(asset_bc, a_key, a_key, 0);
  v21 = get_asset_bc();
  Load(v21, "pazzleboy", "pazzleboy", 0);
  v22 = get_asset_bc();
  PlatformStr = GetPlatformStr();
  v24 = GetAppendix();
  v25 = Concat_5221536("pazzleboy", PlatformStr, v24);
  v26 = GetPlatformStr();
  v27 = GetAppendix();
  v28 = Concat_5221536("pazzleboy", v26, v27);
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
    LoadKeys(1, "pazzleboy", 0);
    LoadKeys(3, "pazzleboy", 0);
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
  RemoveKeys(1, "pazzleboy");
  RemoveKeys(3, "pazzleboy");
  akey = devilModelFileTable->m_Items[336]->akey;
  asset_bc = get_asset_bc();
  UnloadAB(asset_bc, akey);
  v10 = get_asset_bc();
  UnloadAB(v10, a_key);
  v12 = get_asset_bc();
  UnloadAB(v12, "pazzleboy");
  v14 = get_asset_bc();
  PlatformStr = GetPlatformStr();
  Appendix = GetAppendix();
  v17 = Concat_5221536("pazzleboy", PlatformStr, Appendix);
  UnloadAB(v14, v17);
  pbWk->blockTex = 0;
  pbWk->bgTex = 0;
  pbWk->etcTex = 0;
  pbWk->helpTex = 0;
  Remove("PBMESSAGE", 0);
  Remove("PUZZLEBOY", 0);
  v20 = GetPlatformStr();
  v21 = Concat_5224608("PUZZLEBOY", v20);
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
  pbMain_c *v3;
  struct pbMain_procDelegate_array *proc;
  s64 flowId;
  struct pbMain_procDelegate_array *v13;
  s64 v14;
  struct pbProcHandle_t_o *v16;
  struct pbProcHandle_t_o *current_proc;
  s32 mes_low;
  s64 *v21;
  Il2CppClass *v22;
  s64 *v23;
  s64 *Interface;
  char *v25;
  s64 *v26;
  Il2CppObject *p_obj;
  struct pbProcHandle_t_o *v30;
  u64 *v31;
  struct pbProcHandle_t_o *v34;
  s32 v39;
  s32 v41;
  u64 v42[3];

  else if (flg)
  {
    goto LABEL_6;
  }
  LoadKeys(1, "pazzleboy", 0);
  LoadKeys(3, "pazzleboy", 0);
  if (proc->m_Items[flowId])
  {
    v13 = proc;
    v14 = flowId;
    v16 = Invoke(v13->m_Items[v14], &root);
    current_proc = v16;
    flg = 1;
    if ((v3->_2.bitflags2 & 2) == 0)
    {
LABEL_25:
      switch (current_proc->mes >> 16)
      {
        case 0:
        case 1:
          break;
        case 2:
        case 5:
          flg = 0;
          mes_low = flowId + 1;
          goto LABEL_65;
        case 3:
          flg = 0;
          mes_low = flowId - 1;
          goto LABEL_65;
        case 4:
          flg = 0;
          v34 = current_proc;
          mes_low = LOWORD(v34->mes);
LABEL_65:
          flowId = mes_low;
          break;
        case 6:
          Write("********* Puzzle boy process halted (1).\n", 0);
          v39 = FindId(0, "JYAKYO02_BGM00");
          p2sdFadeOut(v39);
          goto LABEL_87;
        default:
          p_obj = &current_proc->id->name->obj;
          Write_2930400("{0}\n", p_obj);
          v30 = current_proc;
          LODWORD(v42[0]) = v30->mes >> 16;
          v31 = sub_8D3950(s32, v42);
          Write_2930400("default {0:D}\n", v31);
          break;
      }
      else if (!DDS3_PADCHECK_TRIG(12))
      {
        goto LABEL_75;
      }
LABEL_75:
      {
LABEL_72:
      }
LABEL_76:
      DDS3_PADCHECK_TRIG(9);
      return 0;
    }
LABEL_7:
    goto LABEL_25;
  }
  Write("********* Puzzle boy process halted (0).\n", 0);
  v41 = 0;
  v21 = sub_8D3950(uint, &v41);
  if (v21)
  {
    v23 = v21;
    Interface = QueryInterface(v21, uint);
    if (!Interface)
    {
      sub_8FC2C0(*(*v23 + 64), v22, v42);
      if ((v42[0] & 1) != 0)
        v25 = v42[2];
      else
        v25 = v42 + 1;
      v26 = sub_8C4940(v25);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3AdminiCallSequence(0, Interface, 0, 0);
LABEL_87:
  id->func_ans = -1;
  return 0;
}

// 0x14a6050
pbProcHandle_t *pbGetCurrentProcess(void) {
  return current_proc;
}

// 0x14a3540
void pbInitMain(u32 mode, s32 level) {
  Il2CppObject *v4;
  u64 *v5;
  s32 v10;
  s32 i;
  struct System_UInt16_array *exit_pos;
  u16 v16;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *FileObject;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v23;
  s64 *v24;
  struct pbWork_t_o *pbWk;
  AssetBundleCtrl_o *v26;
  Il2CppObject *v27;
  Il2CppClass *v28;
  s64 v29;
  char *v30;
  s64 *v31;
  struct pbWork_t_o *v32;
  AssetBundleCtrl_o *v33;
  Il2CppObject *v34;
  Il2CppClass *v35;
  s64 v36;
  char *v37;
  s64 *v38;
  struct pbWork_t_o *v39;
  AssetBundleCtrl_o *v40;
  Il2CppObject *v41;
  Il2CppClass *v42;
  s64 v43;
  char *v44;
  s64 *v45;
  struct pbWork_t_o *v46;
  AssetBundleCtrl_o *v47;
  Il2CppObject *v48;
  Il2CppClass *v49;
  s64 v50;
  char *v51;
  s64 *v52;
  System_String_o *PlatformStr;
  System_String_o *v56;
  System_String_o *v57;
  System_String_o *v58;
  struct UnityEngine_Vector4_array *pbCameraEye;
  struct UnityEngine_Vector4_array *v62;
  struct UnityEngine_Vector4_array *v64;
  struct UnityEngine_Vector4_array *v66;
  struct UnityEngine_Vector4_array *pbCameraTgt;
  struct UnityEngine_Vector4_array *v70;
  struct UnityEngine_Vector4_array *v72;
  struct UnityEngine_Vector4_array *v74;
  struct UnityEngine_Vector4_array *v76;
  struct UnityEngine_Vector4_array *v78;
  struct UnityEngine_Vector4_array *v80;
  struct UnityEngine_Vector4_array *v82;
  struct UnityEngine_Vector4_array *v84;
  struct UnityEngine_Vector4_array *v86;
  struct UnityEngine_Vector4_array *v88;
  struct UnityEngine_Vector4_array *v90;
  struct UnityEngine_Vector4_array *v92;
  struct UnityEngine_Vector4_array *v94;
  struct UnityEngine_Vector4_array *v96;
  struct UnityEngine_Vector4_array *v98;
  struct UnityEngine_Vector4_array *v100;
  struct UnityEngine_Vector4_array *v102;
  struct UnityEngine_Vector4_array *v104;
  struct UnityEngine_Vector4_array *v106;
  s32 Id;
  u64 v114[2];
  char *v115;
  UnityEngine_Vector4_o v116;
  UnityEngine_Vector4_o v117;
  UnityEngine_Vector4_o v118;
  UnityEngine_Vector4_o v119;
  UnityEngine_Vector4_o v120;
  UnityEngine_Vector4_o v121;
  UnityEngine_Vector4_o v122;

  v4 = Allocate(pbWork_t);
  v5 = Allocate(pbBackup_t);
  pbBackup_t___ctor(v5);
  v4[1].klass = v5;
  _ctor(v4, 0);
  v10 = 0;
  pbWk = v4;
  for (i = 0; ; i = 0)
  {
    do
    {
      pb_General__SET_MAP_BLK_(i++, v10, 1);
    }
    while (i != 20);
    if (++v10 == 20)
      break;
  }
  pbWk->camera_mode = 1;
  exit_pos = pbWk->bup->exit_pos;
  exit_pos->m_Items[1] = -2;
  exit_pos->m_Items[0] = -2;
  if (level <= 0)
    v16 = 0;
  else
    v16 = level - 1;
  pbWk->stage = 0;
  pbWk->level = v16;
  asset_bc = get_asset_bc();
  FileObject = LoadFileObject(asset_bc, "common", "dds3data/UI/tex/BG_pzl.png");
  else
  {
    if (!FileObject)
      goto LABEL_38;
  }
  klass = FileObject->klass;
  if (FileObject->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
  {
    sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v114);
    if ((v114[0] & 1) != 0)
      v23 = v115;
    else
      v23 = v114 + 1;
    v24 = sub_8C4940(v23);
  }
LABEL_38:
  pbBGTex = FileObject;
  v26 = get_asset_bc();
  v27 = LoadFileObject(v26, "pazzleboy", "dds3data/pb/sample1.tga");
  if (v27)
  {
    v28 = v27->klass;
    if (v27->klass->_2.typeHierarchyDepth < v29 || v28->_2.typeHierarchy[v29 - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(v28->_1.element_class, UnityEngine_Texture, v114);
      if ((v114[0] & 1) != 0)
        v30 = v115;
      else
        v30 = v114 + 1;
      v31 = sub_8C4940(v30);
    }
  }
  pbWk->blockTex = v27;
  v32 = pbWk;
  v33 = get_asset_bc();
  v34 = LoadFileObject(v33, "pazzleboy", "dds3data/pb/p_boy03.tga");
  if (v34)
  {
    v35 = v34->klass;
    if (v34->klass->_2.typeHierarchyDepth < v36 || v35->_2.typeHierarchy[v36 - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(v35->_1.element_class, UnityEngine_Texture, v114);
      if ((v114[0] & 1) != 0)
        v37 = v115;
      else
        v37 = v114 + 1;
      v38 = sub_8C4940(v37);
    }
  }
  v32->bgTex = v34;
  v39 = pbWk;
  v40 = get_asset_bc();
  v41 = LoadFileObject(v40, "pazzleboy", "dds3data/pb/p_boy01.tga");
  if (v41)
  {
    v42 = v41->klass;
    if (v41->klass->_2.typeHierarchyDepth < v43 || v42->_2.typeHierarchy[v43 - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(v42->_1.element_class, UnityEngine_Texture, v114);
      if ((v114[0] & 1) != 0)
        v44 = v115;
      else
        v44 = v114 + 1;
      v45 = sub_8C4940(v44);
    }
  }
  v39->etcTex = v41;
  v46 = pbWk;
  v47 = get_asset_bc();
  v48 = LoadFileObject(v47, "pazzleboy", "dds3data/pb/p_boy02.tga");
  if (v48)
  {
    v49 = v48->klass;
    if (v48->klass->_2.typeHierarchyDepth < v50 || v49->_2.typeHierarchy[v50 - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(v49->_1.element_class, UnityEngine_Texture, v114);
      if ((v114[0] & 1) != 0)
        v51 = v115;
      else
        v51 = v114 + 1;
      v52 = sub_8C4940(v51);
    }
  }
  v46->helpTex = v48;
  pbWk->pscript = 0;
  sdfDevLoadFileUnity_25061072("dds3data/pb/pbmsg.bf.bytes", &pbWk->pscript, 0, "pazzleboy");
  LoadLocalizeText("pazzleboy", "PBMESSAGE");
  LoadLocalizeText("pazzleboy", "PUZZLEBOY");
  PlatformStr = GetPlatformStr();
  v56 = Concat_5224608("pazzleboy", PlatformStr);
  v57 = GetPlatformStr();
  v58 = Concat_5224608("PUZZLEBOY", v57);
  LoadLocalizeText(v56, v58);
  pbWk->menu_proc = 0;
  pbWk->help_proc = 0;
  sub_854930(pbCameraEye->m_Items, 0);
  v62 = pbCameraEye;
  sub_854930(v62->m_Items, 1u);
  v64 = pbCameraEye;
  sub_854930(v64->m_Items, 2u);
  v66 = pbCameraEye;
  sub_854930(v66->m_Items, 3u);
  sub_854930(pbCameraTgt->m_Items, 0);
  v70 = pbCameraTgt;
  sub_854930(v70->m_Items, 1u);
  v72 = pbCameraTgt;
  sub_854930(v72->m_Items, 2u);
  v74 = pbCameraTgt;
  sub_854930(v74->m_Items, 3u);
  v76 = pbCameraEye;
  sub_854930(&v76->m_Items[1], 0);
  v78 = pbCameraEye;
  sub_854930(&v78->m_Items[1], 1u);
  v80 = pbCameraEye;
  sub_854930(&v80->m_Items[1], 2u);
  v82 = pbCameraEye;
  sub_854930(&v82->m_Items[1], 3u);
  v84 = pbCameraTgt;
  sub_854930(&v84->m_Items[1], 0);
  v86 = pbCameraTgt;
  sub_854930(&v86->m_Items[1], 1u);
  v88 = pbCameraTgt;
  sub_854930(&v88->m_Items[1], 2u);
  v90 = pbCameraTgt;
  sub_854930(&v90->m_Items[1], 3u);
  v92 = pbCameraEye;
  sub_854930(&v92->m_Items[2], 0);
  v94 = pbCameraEye;
  sub_854930(&v94->m_Items[2], 1u);
  v96 = pbCameraEye;
  sub_854930(&v96->m_Items[2], 2u);
  v98 = pbCameraEye;
  sub_854930(&v98->m_Items[2], 3u);
  v100 = pbCameraTgt;
  sub_854930(&v100->m_Items[2], 0);
  v102 = pbCameraTgt;
  sub_854930(&v102->m_Items[2], 1u);
  v104 = pbCameraTgt;
  sub_854930(&v104->m_Items[2], 2u);
  v106 = pbCameraTgt;
  sub_854930(&v106->m_Items[2], 3u);
  v116.x = 0.0;
  v116.y = 0.0;
  v116.z = 0.0;
  v116.w = 0.0;
  dds3SetLightColor(0, 0, v116);
  v117.x = 0.0;
  v117.y = 0.0;
  v117.z = 0.0;
  v117.w = 0.0;
  dds3SetLightDir(0, 0, v117);
  v118.x = 0.0;
  v118.y = 0.0;
  v118.z = 0.0;
  v118.w = 0.0;
  dds3SetLightColor(0, 1u, v118);
  v119.x = 0.0;
  v119.y = 0.0;
  v119.z = 0.0;
  v119.w = 0.0;
  dds3SetLightDir(0, 1u, v119);
  v120.x = 0.0;
  v120.y = 0.0;
  v120.z = 0.0;
  v120.w = 0.0;
  dds3SetLightColor(0, 2u, v120);
  v121.x = 0.0;
  v121.y = 0.0;
  v121.z = 0.0;
  v121.w = 0.0;
  dds3SetLightDir(0, 2u, v121);
  v122.x = 0.0;
  v122.y = 0.0;
  v122.z = 0.0;
  v122.w = 0.0;
  dds3SetAmbientColor(0, v122);
  dds3ScreenParam->fovy = 0.62832;
  dds3SetFog(pbInitMain_fogparam);
  ClrDrawFlag(0x400u);
  pbInitKeyAction();
  Id = FindId(0, "JYAKYO02_BGM00");
  p2sdPlayBGM(Id);
}

// 0x14a5dc0
pbProcHandle_t *pbStartBackGround(pbProcHandle_t **parent) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  pbProcHandle_t_Fields *p_fields;
  s32 v14;
  s32 v15;

  v3 = Allocate(pbProcHandle_t);
  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  v3[1].klass = v4;
  v14 = 0;
  v3[2].klass = sub_8D3950(s32, &v14);
  _ctor(v3, 0);
  v5 = Allocate(pbProcHandle_t);
  v6 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v6);
  v5[2] = v6;
  v15 = 0;
  v5[4] = sub_8D3950(s32, &v15);
  _ctor(v5, 0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_pbMain_drawBG__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbMain_deleteDrawBG__);
  v5[2] = dds3StartProcess("pb-draw-bg", 0x2AFDu, 1, 1, v7, 0, v8, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, v5 + 2);
  }
  else
  {
    *(v5 + 6) = 0;
      goto LABEL_21;
  }
LABEL_21:
  dds3SetProcessData(v5 + 2, v5);
  return v5;
}

// 0x14a60c0
pbProcHandle_t *pbStartDummy(pbProcHandle_t **parent) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  pbProcHandle_t_Fields *p_fields;
  s32 v15;
  s32 v16;
  s32 v17;

  v3 = Allocate(pbProcHandle_t);
  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  v3[1].klass = v4;
  v16 = 0;
  v3[2].klass = sub_8D3950(s32, &v16);
  _ctor(v3, 0);
  v5 = Allocate(pbProcHandle_t);
  v6 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v6);
  v5[2] = v6;
  v17 = 0;
  v5[4] = sub_8D3950(s32, &v17);
  _ctor(v5, 0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_pbMain_dummy__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbMain_deleteDummy__);
  v5[2] = dds3StartProcess("pb-proc-dummy", 0x3EEu, 1, 1, v7, 0, v8, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, v5 + 2);
  }
  v15 = 0;
  v5[4] = sub_8D3950(s32, &v15);
  else
  {
    *(v5 + 6) = 0;
      goto LABEL_21;
  }
LABEL_21:
  dds3SetProcessData(v5 + 2, v5);
  return v5;
}

// 0x14a3520
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
