#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct FieldBgHD FieldBgHD;
typedef struct FieldChrHD FieldChrHD;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct evtKutiManager evtKutiManager;
typedef struct evtLoadManager_eLoadData evtLoadManager_eLoadData;
typedef struct evtTexManager evtTexManager;
typedef struct evtUnitHandle_t evtUnitHandle_t;

struct evtLoadManager_eLoadData {
    s32 mode;
    s32 type;
    void *data;
};

static s32 eventno;
static char *akey;
static void *keys;
static void *lists;
static void *objects;
static void *rep_tbl;
static EventEMsgData *event_msg;
static void *kuti_obj;
static evtKutiManager *kuti_scr;
static s32 step_cnt;
static s32 load_index;
static void *inst_cash_dic;

void Append(evtKutiManager *this, char *key, char *path, bool evt);
bool CheckDLCKey(char *key);
void Destroy(evtTexManager *this, bool unload);
void FinalizeLoadManager(bool sw);
char *GetAppendix(void);
char *GetDLCTag(s32 eventno);
char *GetLangCode(void);
void Initialize(evtTexManager *this, char *key, char *path);
bool IsFileExists(AssetBundleCtrl *this, char *key, char *path_name);
bool IsLoad(AssetBundles *this, char *key);
void *LoadAsset(AssetBundleCtrl *this, char *key, char *path, char *name);
void LoadAssetExt(char *key, char *name, char *dlc);
void *LoadAudioClip(AssetBundleCtrl *this, char *key, char *path, char *name);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Log(char *fmt, void **parray);
void SetBoostFrameRate(dds3DefaultMain *this);
void SetEvtInstCash(void *prefab, s32 type);
void SetFiledName(FieldBgHD *this, char *name);
void SetNormalFrameRate(dds3DefaultMain *this);
void UnloadAB(AssetBundleCtrl *this, char *key);
bool evtBitCheck(s32 no);
void evtUpdateEx_FieldLoadAfter(FieldBgHD *fobj, void *rootobj, char *mname);
void init_readlist(s32 evtno);
void load_init(void);
void load_wait(void);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);

// 0x10edea0
bool CheckCashField(void) {
  UnityEngine_Object_o *FildMapObj;

  if (!bDanteEvent)
    return 0;
  if (op_Inequality(FildMapObj, 0, 0))
  {
    Destroy(FildMapObj, 1.0, 0);
  }
  return 1;
}

// 0x10ec1c0
bool Contains(char *name) {
  s32 IndexOf_5262640;
  s32 v5;
  s32 Length;

  IndexOf_5262640 = LastIndexOf_5262640(name, StringLiteral_74);
  if (IndexOf_5262640 != -1)
  {
    v5 = IndexOf_5262640;
    Length = get_Length(name);
    name = Substring_5248048(name, v5 + 1, Length + ~v5);
  }
  return evtLoadManager_eLoadData___ContainsKey(objects, name);
}

// 0x10edc30
void EndFKuti(void) {
  UnityEngine_Object_o *kuti_scr;
  struct evtKutiManager_o *v6;

  if (op_Inequality(kuti_scr, 0, 0))
  {
    v6 = kuti_scr;
    PropertySheet___Clear(v6->TimeLine);
    v6->KutiSwitch = 0;
    v6->MsgTime = 0.0;
    v6->hUnit = 0;
    v6->KutiName = 0;
  }
}

// 0x10eb9a0
void FinalizeLoadManager(bool sw) {
    Destroy(0, 0);
    UnloadAB(0, 0);
}

// 0x10ebf10
void *GetData(char *name) {
  s32 IndexOf_5262640;
  s32 v5;
  s32 Length;

  IndexOf_5262640 = LastIndexOf_5262640(name, StringLiteral_74);
  if (IndexOf_5262640 != -1)
  {
    v5 = IndexOf_5262640;
    Length = get_Length(name);
    name = Substring_5248048(name, v5 + 1, Length + ~v5);
  }
  if (!evtLoadManager_eLoadData___ContainsKey(objects, name))
    return 0;
  return evtLoadManager_eLoadData___get_Item(objects, name).data;
}

// 0x10edd40
void *GetEvtInstCash(void *obj) {
  UnityEngine_GameObject_o *v4;
  System_Collections_Generic_Dictionary_GameObject__Animator__o *inst_cash_dic;
  System_String_o *name;
  bool v8;
  System_Collections_Generic_Dictionary_object__object__o *v11;
  Il2CppObject *v12;
  Il2CppObject *Item;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v14;
  System_String_o *v15;

  v4 = 0;
  if (op_Inequality(obj, 0, 0))
  {
    name = get_name(obj);
    v8 = Animator___ContainsKey(inst_cash_dic, name);
    v4 = 0;
    if (v8)
    {
      v11 = inst_cash_dic;
      v12 = get_name(obj);
      Item = object___get_Item(v11, v12);
      v14 = inst_cash_dic;
      v4 = Item;
      v15 = get_name(obj);
      HashSet_Text____Remove(v14, v15);
    }
  }
  return v4;
}

// 0x10ec030
evtKutiManager *GetKutiManager(void) {
  return kuti_scr;
}

// 0x10ec0a0
s32 GetMode(char *name) {
  s32 IndexOf_5262640;
  s32 v5;
  s32 Length;

  IndexOf_5262640 = LastIndexOf_5262640(name, StringLiteral_74);
  if (IndexOf_5262640 != -1)
  {
    v5 = IndexOf_5262640;
    Length = get_Length(name);
    name = Substring_5248048(name, v5 + 1, Length + ~v5);
  }
  if (!evtLoadManager_eLoadData___ContainsKey(objects, name))
    return 0;
  return evtLoadManager_eLoadData___get_Item(objects, name).mode;
}

// 0x10eb7a0
void InitializeLoadManager(void) {
  UnityEngine_Object_o *kuti_scr;
  UnityEngine_Object_o *kuti_obj;
  u64 *v8;
  UnityEngine_Transform_o *transform;
  UnityEngine_GameObject_o *v12;
  UnityEngine_Transform_o *v13;

  if (op_Inequality(kuti_scr, 0, 0))
  {
    FinalizeLoadManager(0);
  }
  if (op_Equality(kuti_obj, 0, 0))
  {
    v8 = Allocate(UnityEngine_GameObject);
    _ctor(v8, StringLiteral_15918, 0);
    kuti_obj = v8;
    transform = get_transform(kuti_obj, 0);
    v12 = Find(StringLiteral_4905, 0);
    v13 = get_transform(v12, 0);
    SetParent(transform, v13);
    AddComponent_object_(kuti_obj);
  }
  kuti_scr = GetComponent_object_(kuti_obj);
}

// 0x10ec300
s32 Load(s32 eventno) {
  u64 v3;
  s32 v4;

  v4 = 1;
  switch (*(*(v3 + 184) + 72LL))
  {
    case 0:
      if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
      init_readlist(eventno);
      return 0;
    case 1:
      if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
      load_init(v3);
      return 0;
    case 2:
      if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
      load_wait(v3);
      return 0;
    case 4:
      return v4;
    default:
      return 0;
  }
}

// 0x10ee1d0
FieldChrHD *PriChrHDGet(void *obj) {
  bool v3;
  FieldChrHD_o *result;
  bool v6;
  bool v7;

  v3 = evtBitCheck(3712);
  result = 0;
  if (v3)
  {
    v6 = evtBitCheck(256);
    result = 0;
    if (!v6)
    {
      v7 = op_Inequality(obj, 0, 0);
      result = 0;
      if (v7)
        return GetComponent_object_(obj);
    }
  }
  return result;
}

// 0x10edfc0
void PriChrHDSet(void *obj) {
  System_String_o *name;
  bool v4;
  System_String_o *v5;
  bool v6;
  System_String_o *v7;
  bool v8;
  System_String_o *v9;
  bool v10;
  System_String_o *v11;
  bool v12;
  System_String_o *v13;
  bool v14;
  System_String_o *v15;
  bool v16;

  if (!op_Equality(obj, 0, 0) && evtBitCheck(3712) && !evtBitCheck(256))
  {
    name = get_name(obj);
    v4 = Contains(name, StringLiteral_15282, 0);
    v5 = get_name(obj);
    v6 = Contains(v5, StringLiteral_15279, 0);
    v7 = get_name(obj);
    v8 = Contains(v7, StringLiteral_15280, 0);
    v9 = get_name(obj);
    v10 = Contains(v9, StringLiteral_15281, 0);
    v11 = get_name(obj);
    v12 = Contains(v11, StringLiteral_15325, 0);
    v13 = get_name(obj);
    v14 = Contains(v13, StringLiteral_4808, 0);
    v15 = get_name(obj);
    v16 = Contains(v15, StringLiteral_4809, 0);
    if (v4 || v6 || v8 || v10 || v12 || v14 || v16)
    {
      mdlSetHD(obj, 2, 0, 15);
    }
  }
}

// 0x10ec290
void *ReplaceName(void) {
  return rep_tbl;
}

// 0x10ed710
void SetEvtInstCash(void *prefab, s32 type) {
  s32 v5;
  System_String_o *v6;
  s32 v7;
  System_String_o *v8;
  s32 v9;
  System_String_o *v10;
  s32 v11;
  System_String_o *v12;
  s32 v13;
  System_String_o *v14;
  System_String_o *v15;
  System_String_o *v17;
  bool v19;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v23;
  Il2CppObject *v24;
  System_String_o *v25;
  System_String_o *v27;
  System_String_o *name;
  _BOOL4 v31;
  System_String_o *v32;
  s32 v33;
  System_String_o *v34;

  if (op_Equality(prefab, 0, 0))
    return;
  if (evtBitCheck(3712) && !evtBitCheck(256))
  {
    name = get_name(prefab);
    v31 = Equals_5234480(name, StringLiteral_15927);
    v32 = get_name(prefab);
    v33 = v31 | Equals_5234480(v32, StringLiteral_15928);
    v34 = get_name(prefab);
    v5 = v33 | Equals_5234480(v34, StringLiteral_15929);
    if (!evtBitCheck(151))
  }
  v5 = 0;
  if (evtBitCheck(151))
  {
    v6 = get_name(prefab);
    v7 = v5 | Equals_5234480(v6, StringLiteral_15930);
    v8 = get_name(prefab);
    v9 = v7 | Equals_5234480(v8, StringLiteral_15931);
    v10 = get_name(prefab);
    v11 = v9 | Equals_5234480(v10, StringLiteral_15932);
    v12 = get_name(prefab);
    v13 = v11 | Equals_5234480(v12, StringLiteral_15933);
    v14 = get_name(prefab);
    v5 = v13 | Equals_5234480(v14, StringLiteral_15934);
  }
  if (evtBitCheck(3716))
  {
    v15 = get_name(prefab);
    if (((v5 | Equals_5234480(v15, StringLiteral_15935)) & 1) == 0)
      return;
  }
  else if ((v5 & 1) == 0)
  {
    return;
  }
  v17 = get_name(prefab);
  v19 = Animator___ContainsKey(inst_cash_dic, v17);
  if (!type && !v19)
  {
    v20 = Find(StringLiteral_5598, 0);
    transform = get_transform(v20, 0);
    v23 = Instantiate_object__425664(prefab, transform, 0);
    v24 = AddComponent_object_(v23);
    v25 = Concat_5224608(v17, StringLiteral_8890);
    SetFiledName(v24, v25);
    v27 = Concat_5224608(v17, StringLiteral_8890);
    evtUpdateEx_FieldLoadAfter(v24, v23, v27);
    SetActive(v23, 0, 0);
    PropertySheet___Add(inst_cash_dic, v17, v23);
  }
}

// 0x10edad0
void StartFKuti(char *key, char *name) {
  System_String_o *v6;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *kuti_scr;

  v6 = Concat_5271136(StringLiteral_15926, key, StringLiteral_74, name);
  asset_bc = get_asset_bc();
  if (IsFileExists(asset_bc, key, v6))
  {
    if (op_Inequality(kuti_scr, 0, 0))
    {
      Initialize(kuti_scr, key, name, 0);
    }
  }
}

// 0x10ebe50
void StartLoad(void) {
  FinalizeLoadManager(0);
  eventno = 0;
  evtLoadManager_eLoadData___Clear(objects);
  PropertySheet___Clear(rep_tbl);
  step_cnt = 0;
}

// 0x10ec3f0
void init_readlist(s32 evtno) {
    SetBoostFrameRate(0);
    GetDLCTag(0);
    LoadFileObject(0, 0, 0);
    SetNormalFrameRate(0);
}

// 0x10ec840
void load_init(void) {
    GetAppendix();
    CheckDLCKey(0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    Log(0, 0);
    LoadAudioClip(0, 0, 0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
    LoadFileByte(0, 0, 0);
    GetLangCode();
    LoadAsset(0, 0, 0, 0);
    SetEvtInstCash(0, 0);
    LoadFileObject(0, 0, 0);
    Initialize(0, 0, 0);
    Append(0, 0, 0, 0);
    Initialize(0, 0, 0);
    SetNormalFrameRate(0);
}

// 0x10ed610
void load_wait(void) {
  System_Collections_Generic_List_datEncount_t__o *keys;
  s32 Count;
  System_String_o *Item;
  AssetBundleCtrl_o *asset_bc;

  Count = _get_Count(keys);
  Item = _get_Item(
           keys,
           Count - 1);
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, Item))
  {
    step_cnt = 1;
  }
}
