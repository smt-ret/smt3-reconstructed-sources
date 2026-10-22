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
LABEL_6:
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

  IndexOf_5262640 = LastIndexOf_5262640(name, "/");
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
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  s32 v5;
  evtTexManager_o *v6;
  UnityEngine_Object_o *kuti_scr;
  struct evtKutiManager_o *v10;
  evtTexManager_c *klass;
  s64 typeHierarchyDepth;
  char *currentValue;
  s64 *v14;
  s32 v19;
  System_String_o *Item;
  AssetBundleCtrl_o *asset_bc;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v27;
  s64 v28;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v29;
  s64 v30;

  v30 = 0;
  memset(&v29, 0, sizeof(v29));
  Values = evtLoadManager_eLoadData___get_Values(objects);
  evtLoadManager_eLoadData___GetEnumerator(&v27, Values);
  v29 = v27;
  v30 = v28;
  while ((sub_4D5560(&v29) & 1) != 0)
  {
    v5 = sub_4D56E0(&v29) >> 32;
    if (v5 == 12)
    {
      if (v6)
      {
        klass = v6->klass;
        if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtTexManager)
        {
          sub_8FC2C0(klass->_1.element_class, evtTexManager, &v27);
          if ((v27.dictionary & 1) != 0)
            currentValue = v27.currentValue;
          else
            currentValue = &v27.dictionary + 1;
          v14 = sub_8C4940(currentValue);
        }
      }
      Destroy(v6, 1, 0);
    }
    else if (v5 == 13)
    {
      if (op_Inequality(kuti_scr, 0, 0))
      {
        v10 = kuti_scr;
        if ((byte_3F589F5 & 1) == 0)
          goto LABEL_21;
LABEL_22:
        if (sw)
          PropertySheet___Clear(v10->TimeLine);
        v10->KutiSwitch = 0;
        v10->MsgTime = 0.0;
        v10->hUnit = 0;
        v10->KutiName = 0;
      }
    }
  }
  nullsub_49(&v29);
  PropertySheet___Clear(rep_tbl);
  evtLoadManager_eLoadData___Clear(objects);
  step_cnt = 0;
  eventno = 0;
  v19 = 0;
  {
LABEL_40:
  }
  while (v19 < _get_Count(keys))
  {
    asset_bc = get_asset_bc();
    Item = _get_Item(
             keys,
             v19);
    UnloadAB(asset_bc, Item);
    ++v19;
      goto LABEL_40;
  }
  _Clear(keys);
  UnloadUnusedAssets();
}

// 0x10ebf10
void *GetData(char *name) {
  s32 IndexOf_5262640;
  s32 v5;
  s32 Length;

  IndexOf_5262640 = LastIndexOf_5262640(name, "/");
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

  IndexOf_5262640 = LastIndexOf_5262640(name, "/");
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
    _ctor(v8, "KutiManager", 0);
    kuti_obj = v8;
    transform = get_transform(kuti_obj, 0);
    v12 = Find("Canvas_UI", 0);
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
      load_init(v3);
      return 0;
    case 2:
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
    v4 = Contains(name, "player_tatoo_e723", 0);
    v5 = get_name(obj);
    v6 = Contains(v5, "player_tatoo_e723_010", 0);
    v7 = get_name(obj);
    v8 = Contains(v7, "player_tatoo_e723_030", 0);
    v9 = get_name(obj);
    v10 = Contains(v9, "dante_e723", 0);
    v11 = get_name(obj);
    v12 = Contains(v11, "dante_e723_010", 0);
    v13 = get_name(obj);
    v14 = Contains(v13, "dante_e723_020", 0);
    v15 = get_name(obj);
    v16 = Contains(v15, "dante_e723_030", 0);
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
    v31 = Equals_5234480(name, "f723_010");
    v32 = get_name(prefab);
    v33 = v31 | Equals_5234480(v32, "f723_020");
    v34 = get_name(prefab);
    v5 = v33 | Equals_5234480(v34, "f723_030");
    if (!evtBitCheck(151))
      goto LABEL_12;
    goto LABEL_11;
  }
  v5 = 0;
  if (evtBitCheck(151))
  {
LABEL_11:
    v6 = get_name(prefab);
    v7 = v5 | Equals_5234480(v6, "f699_005");
    v8 = get_name(prefab);
    v9 = v7 | Equals_5234480(v8, "f699_010");
    v10 = get_name(prefab);
    v11 = v9 | Equals_5234480(v10, "f699_020");
    v12 = get_name(prefab);
    v13 = v11 | Equals_5234480(v12, "f699_030");
    v14 = get_name(prefab);
    v5 = v13 | Equals_5234480(v14, "f699_040");
  }
LABEL_12:
  if (evtBitCheck(3716))
  {
    v15 = get_name(prefab);
    if (((v5 | Equals_5234480(v15, "f807_001")) & 1) == 0)
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
    v20 = Find("Field", 0);
    transform = get_transform(v20, 0);
    v23 = Instantiate_object__425664(prefab, transform, 0);
    v24 = AddComponent_object_(v23);
    v25 = Concat_5224608(v17, "(Clone)", 0);
    SetFiledName(v24, v25);
    v27 = Concat_5224608(v17, "(Clone)", 0);
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

  v6 = Concat_5271136("dds3data/fld/f/", key, "/", name);
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
  u64 *v6;
  System_String_o *v8;
  System_String_o *DLCTag;
  struct System_String_o *v10;
  System_String_o *v12;
  System_String_o *v13;
  u64 *v14;
  System_String_o *v15;
  u64 *v16;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *akey;
  AssetBundleCtrl_o *v19;
  System_String_o *v20;
  Il2CppObject *FileObject;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v28;
  System_String_array *v29;
  System_String_array *v32;
  il2cpp_array_size_t max_length;
  u64 v36;
  struct System_Collections_Generic_List_string__o *lists;
  s32 eventno;
  s32 v41;

  SetBoostFrameRate(kernelObject);
  step_cnt = 1;
  load_index = 0;
  _Clear(keys);
  v41 = evtno;
  v6 = sub_8D3950(s32, &v41);
  v8 = Format("e{0:D3}", v6, 0);
  DLCTag = GetDLCTag(evtno);
  v10 = Concat_5224608(v8, DLCTag);
  akey = v10;
  v12 = Concat_5224608("dds3data/event/", akey);
  eventno = evtno;
  v13 = v12;
  v14 = sub_8D3950(s32, &eventno);
  v15 = Format("e{0:D3}list.bytes", v14, 0);
  v16 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v16);
  asset_bc = get_asset_bc();
  v19 = asset_bc;
  v20 = Concat_5221536(v13, "/", v15);
  FileObject = LoadFileObject(v19, akey, v20);
  if (FileObject)
  {
    if (FileObject->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (FileObject->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        FileObject = 0;
    }
    else
    {
      FileObject = 0;
    }
    bytes = get_bytes(FileObject);
    Unicode = get_Unicode();
    v28 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
    v29 = NewSpecific(string, 1u);
    v29->m_Items[0] = "\r\n";
    v32 = Split_5246672(v28, v29, 0);
    _Clear(lists);
    max_length = v32->max_length;
    if (max_length >= 2)
    {
      v36 = 0;
      do
      {
        else
        {
          if (v36 >= max_length)
          {
LABEL_38:
          }
        }
        _Add(lists, v32->m_Items[v36]);
        max_length = LODWORD(v32->max_length);
        ++v36;
      }
      while (v36 < ((max_length << 32) - 0x100000000LL) >> 32);
    }
  }
  else
  {
    step_cnt = 4;
    SetNormalFrameRate(kernelObject);
  }
}

// 0x10ec840
void load_init(void) {
  System_String_o *Item;
  u64 *v4;
  System_String_array *v6;
  il2cpp_array_size_t *p_max_length;
  System_String_array *v9;
  System_String_o *v11;
  System_String_o *Appendix;
  bool v14;
  s64 *v16;
  System_String_o *v17;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v22;
  System_Object_array *v24;
  AssetBundleCtrl_o *v25;
  UnityEngine_Rendering_PostProcessing_PropertySheet_o **v27;
  System_String_o *v28;
  evtTexManager_o *AudioClip;
  System_String_o *v32;
  System_String_o *v33;
  System_String_o *v34;
  s32 v36;
  AssetBundleCtrl_o *v37;
  System_String_o *v39;
  UnityEngine_Rendering_PostProcessing_PropertySheet_o **v40;
  System_String_o *v41;
  s64 *v42;
  System_String_o *v44;
  System_String_o *v46;
  s32 v48;
  UnityEngine_Rendering_PostProcessing_PropertySheet_o *v50;
  s32 v51;
  s32 load_index;
  AssetBundleCtrl_o *v59;
  AssetBundleCtrl_o *v60;
  System_String_o *v62;
  System_String_o *v63;
  System_String_o *v65;
  AssetBundleCtrl_o *v66;
  AssetBundleCtrl_o *v68;
  System_String_o *v70;
  System_String_o *LangCode;
  System_String_o *v72;
  UnityEngine_Rendering_PostProcessing_PropertySheet_o **v74;
  System_String_o *v75;
  System_String_o *v76;
  UnityEngine_Object_o *Asset;
  s64 typeHierarchyDepth;
  AssetBundleCtrl_o *v79;
  System_String_o *v80;
  UnityEngine_Object_o *kuti_scr;
  struct evtKutiManager_o *v85;
  s32 Count;
  UnityEngine_GameObject_o *Prefab_16624656;
  UnityEngine_Shader_o *v102;
  System_String_o *v108;
  UnityEngine_GameObject_o *v109;
  char *v112;
  s64 *v113;
  UnityEngine_GameObject_o *v114;
  s32 result;
  u64 v119[3];
  evtLoadManager_eLoadData_o v120;

  result = 0;
  Item = _get_Item(
           lists,
           load_index);
  v4 = NewSpecific(char, 1u);
  *(v4 + 16) = 44;
  v6 = Split(Item, v4);
  p_max_length = &v6->max_length;
  v9 = v6;
  v11 = v6->m_Items[0];
  Appendix = GetAppendix();
  v14 = CheckDLCKey(v11);
  v16 = &"m";
  if (!v14)
    v16 = &"";
  if (*p_max_length == 1)
    goto LABEL_73;
  v17 = *v16;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, v11))
  {
    _Add(keys, v11);
    v32 = v11;
    v33 = v11;
    v34 = 0;
LABEL_47:
    LoadAssetExt(v32, v33, v34);
    v36 = 2;
LABEL_84:
    step_cnt = v36;
    return;
  }
  result = -1;
  if (!TryParse(v9->m_Items[1], &result, 0))
  {
    v22 = Concat_5221536("!!!!! Load Type Error = ", v9->m_Items[1], " !!!!!");
    v24 = Empty_string_();
    Log(v22, v24, 0);
  }
  switch (result % 100)
  {
    case 0:
      v37 = get_asset_bc();
      v41 = v9->m_Items[2];
      v40 = &v9->m_Items[2];
      v39 = v41;
      v42 = &"sound/bgm";
      goto LABEL_66;
    case 1:
      v37 = get_asset_bc();
      v44 = v9->m_Items[2];
      v40 = &v9->m_Items[2];
      v39 = v44;
      v42 = &"sound/se";
      goto LABEL_66;
    case 3:
      v37 = get_asset_bc();
      v46 = v9->m_Items[2];
      v40 = &v9->m_Items[2];
      v39 = v46;
      v42 = &"sound/Voice";
LABEL_66:
      v27 = v40;
      AudioClip = LoadAudioClip(v37, v11, *v42, v39);
      if (*(v40 - 6) <= 2u)
        goto LABEL_67;
      goto LABEL_68;
    case 4:
      v59 = get_asset_bc();
      v27 = &v9->m_Items[3];
      Prefab_16624656 = LoadPrefab_16624656(v59, v11, v9->m_Items[4], v9->m_Items[3]);
      AudioClip = Prefab_16624656;
      if (Animator___ContainsKey(rep_tbl, v9->m_Items[2]))
      {
        HashSet_Text____Remove(rep_tbl, v9->m_Items[2]);
      }
      v102 = v9->m_Items[2];
      PropertySheet___Add(rep_tbl, v102, *v27);
      v48 = result / 100;
      if (!AudioClip)
        goto LABEL_73;
      goto LABEL_69;
    case 6:
      v60 = get_asset_bc();
      v27 = &v9->m_Items[2];
      v62 = Concat_5271136("dds3data/event/", v11, "/", v9->m_Items[2]);
      AudioClip = LoadFileByte(v60, v11, v62);
      if (LODWORD(v9->max_length) > 2)
        goto LABEL_68;
      goto LABEL_67;
    case 7:
      v63 = GetAppendix();
      v65 = Concat_5224608(v11, v63);
      v66 = get_asset_bc();
      if (IsLoad(v66, v65))
      {
        v68 = get_asset_bc();
        v70 = Concat_5224608(v11, Appendix);
        LangCode = GetLangCode();
        v72 = Concat_5224608("dds3data/event/localize_text/", LangCode);
        v75 = v9->m_Items[2];
        v74 = &v9->m_Items[2];
        v76 = Concat_5224608(v75, Appendix);
        Asset = LoadAsset(v68, v70, v72, v76, 0);
        if (Asset
              Asset->klass->_2.typeHierarchyDepth >= typeHierarchyDepth))
        {
          if (Asset->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == EventEMsgData)
            AudioClip = Asset;
          else
            AudioClip = 0;
          if (*p_max_length > 2u)
          {
LABEL_191:
            v48 = 0;
            v27 = v74;
            if (!AudioClip)
              goto LABEL_73;
            goto LABEL_69;
          }
        }
        else
        {
          AudioClip = 0;
          if (*p_max_length > 2u)
            goto LABEL_191;
        }
LABEL_190:
      }
      _Add(keys, v65);
      v32 = v65;
      v33 = v65;
      v34 = v17;
      goto LABEL_47;
    case 10:
      v79 = get_asset_bc();
      v80 = v9->m_Items[3];
      v108 = v9->m_Items[2];
      v74 = &v9->m_Items[2];
      v109 = LoadPrefab_16624656(v79, v11, v80, v108);
      AudioClip = v109;
      if (AudioClip)
      {
        if (AudioClip->klass != UnityEngine_GameObject)
        {
          sub_8FC2C0(AudioClip->klass->_1.element_class, UnityEngine_GameObject, v119);
          if ((v119[0] & 1) != 0)
            v112 = v119[2];
          else
            v112 = v119 + 1;
          v113 = sub_8C4940(v112);
        }
        v114 = AudioClip;
      }
      else
      {
        v114 = 0;
      }
      SetEvtInstCash(v114, 0);
      if (*p_max_length <= 2u)
        goto LABEL_190;
      goto LABEL_191;
    case 11:
    case 14:
      v25 = get_asset_bc();
      v27 = &v9->m_Items[2];
      v28 = Concat_5271136("dds3data/event/", v11, "/", v9->m_Items[2]);
      AudioClip = LoadFileObject(v25, v11, v28);
      if (LODWORD(v9->max_length) > 2)
        goto LABEL_68;
      goto LABEL_67;
    case 12:
      AudioClip = Allocate(evtTexManager);
      _ctor(AudioClip, 0);
      v27 = &v9->m_Items[2];
      Initialize(AudioClip, v11, v9->m_Items[2], 0);
      if (LODWORD(v9->max_length) <= 2)
      {
LABEL_67:
      }
LABEL_68:
      v48 = 0;
      if (AudioClip)
        goto LABEL_69;
      goto LABEL_73;
    case 13:
      if (!op_Inequality(kuti_scr, 0, 0))
        goto LABEL_199;
      v85 = kuti_scr;
      Count = HashSet_Text____get_Count(v85->TimeLine);
      if (Count)
      {
        Append(kuti_scr, v11, v9->m_Items[2], 1);
          goto LABEL_202;
LABEL_200:
        goto LABEL_202;
      }
      Initialize(kuti_scr, v11, v9->m_Items[2], 1);
LABEL_199:
        goto LABEL_200;
LABEL_202:
      AudioClip = kuti_scr;
      v48 = 0;
      v27 = &v9->m_Items[2];
      if (AudioClip)
      {
LABEL_69:
        v50 = *v27;
        v51 = result;
        v120.mode = v48;
        v120.type = v51;
        v120.data = AudioClip;
        evtLoadManager_eLoadData___Add(objects, v50, v120);
      }
LABEL_73:
      ++load_index;
      if (load_index >= _get_Count(lists))
      {
        SetNormalFrameRate(kernelObject);
        v36 = 4;
        goto LABEL_84;
      }
      return;
    default:
      goto LABEL_73;
  }
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
