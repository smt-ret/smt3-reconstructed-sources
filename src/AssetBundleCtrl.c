#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundleCtrl_Data AssetBundleCtrl_Data;
typedef struct AssetBundleCtrl_LoadData AssetBundleCtrl_LoadData;
typedef struct AssetBundleCtrl__LoadCoroutine_d__11 AssetBundleCtrl__LoadCoroutine_d__11;

struct AssetBundleCtrl_LoadData {
    s32 count;
    char *aname;
    void *assetbundle;
};

struct AssetBundleCtrl_Data {
    s32 count;
    AssetBundleCtrl_LoadData *ld;
};

struct AssetBundleCtrl__LoadCoroutine_d__11 {
    s32 __1__state;
    void *__2__current;
    AssetBundleCtrl *__4__this;
    s32 dlc_id;
    char *key;
    void *_req_5__2;
    void *_result_5__3[1];
};

static char *resourcePath;

void LoadDirect(AssetBundleCtrl *this, char *key, char *aname, s32 dlc_id);
void *LoadFileAsync_16626960(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadFile_16626736(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadPrefab_16624272(AssetBundleCtrl *this, char *key, char *path, char *name, void *parent, char *name2);

// 0xfda410
void *GetAB(AssetBundleCtrl *this, char *key) {
  if (Animator___ContainsKey(this->assetbundle, key))
  {
    return *(object___get_Item(this->assetbundle, key)[1].monitor
           + 4);
  }
  else
  {
    return 0;
  }
}

// 0xfda4b0
char *GetABName(AssetBundleCtrl *this, char *key) {
  if (Animator___ContainsKey(this->assetbundle, key))
  {
    return *(object___get_Item(this->assetbundle, key)[1].monitor
           + 3);
  }
  else
  {
    return 0;
  }
}

// 0xfdb7e0
char **GetKeys(AssetBundleCtrl *this) {
  u32 Count;
  System_String_array *v4;
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;

  Count = HashSet_Text____get_Count(this->assetbundle);
  v4 = NewSpecific(string, Count);
  Keys = string___get_Keys(this->assetbundle);
  string___CopyTo(Keys, v4, 0);
  return v4;
}

// 0xfdb6b0
bool IsFileExists(AssetBundleCtrl *this, char *key, char *path_name) {
  UnityEngine_Object_o *v8;
  System_String_o *v9;

  if (Animator___ContainsKey(this->assetbundle, key))
  {
    v8 = *(object___get_Item(this->assetbundle, key)[1].monitor
         + 4);
  }
  else
  {
    v8 = 0;
  }
  if (!op_Inequality(v8, 0, 0))
    return 0;
  v9 = Concat_5224608("Assets/AssetBundle/AssetData/", path_name);
  return Contains(v8, v9, 0);
}

// 0xfda340
bool IsLoad(AssetBundleCtrl *this, char *key) {
  UnityEngine_Object_o *v6;

  if (!Animator___ContainsKey(this->assetbundle, key))
    return 0;
  v6 = *(object___get_Item(this->assetbundle, key)[1].monitor
       + 4);
  return op_Inequality(v6, 0, 0);
}

// 0xfd9c40
void Load(AssetBundleCtrl *this, char *key, char *aname) {
  System_String_o *v6;

  v6 = ToLower(aname, 0);
  LoadDirect(this, key, v6, -1);
}

// 0xfdb370
void *LoadAsset(AssetBundleCtrl *this, char *key, char *path, char *name) {
  System_String_o *v9;
  System_String_o *v10;

  v9 = ".asset";
  v10 = Concat_5271136(path, "/", name, v9);
  return LoadFile_16626736(this, key, v10);
}

// 0xfdb290
void *LoadAudioClip(AssetBundleCtrl *this, char *key, char *path, char *name) {
  System_String_o *v9;
  System_String_o *v10;
  UnityEngine_AudioClip_o *result;

  v9 = ".wav";
  v10 = Concat_5271136(path, "/", name, v9);
  result = LoadFile_16626736(this, key, v10);
  if (result)
  {
    if (result->klass != UnityEngine_AudioClip)
      return 0;
  }
  return result;
}

// 0xfda290
void *LoadCoroutine(AssetBundleCtrl *this, char *key, s32 dlc_id) {
  u64 *v7;

  v7 = Allocate(AssetBundleCtrl__LoadCoroutine_d__11);
  _ctor(v7, 0);
  *(v7 + 4) = 0;
  v7[4] = this;
  v7[6] = key;
  *(v7 + 10) = dlc_id;
  return v7;
}

// 0xfd9c80
void LoadDirect(AssetBundleCtrl *this, char *key, char *aname, s32 dlc_id) {
  void *Item;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  s64 v11;
  Il2CppObject *v12;
  u64 *v13;
  System_String_array *v14;
  s64 *v20;
  s64 *v21;
  s64 *v26;
  s64 *v27;
  Il2CppObject *v33;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v35;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v36;

  memset(&v36, 0, sizeof(v36));
  if (Animator___ContainsKey(this->assetbundle, key))
  {
    Item = object___get_Item(this->assetbundle, key);
  }
  else
  {
    Item = Allocate(AssetBundleCtrl_Data);
    _ctor(Item, 0);
    Values = Type___get_Values(this->assetbundle);
    Type___GetEnumerator(&v35, Values);
    v36 = v35;
    while ((sub_4D4B20(&v36) & 1) != 0)
    {
      v11 = sub_4D4CB0(&v36);
      if (Equals_5234480(aname, *(*(v11 + 24) + 24LL), 0))
      {
        *(Item + 3) = *(v11 + 24);
        break;
      }
    }
    nullsub_48(&v36);
    if (!*(Item + 3))
    {
      v12 = Allocate(AssetBundleCtrl_LoadData);
      v12[1].monitor = Empty;
      _ctor(v12, 0);
      *(Item + 3) = v12;
      v12[1].monitor = aname;
    }
    PropertySheet___Add(this->assetbundle, key, Item);
  }
  ++*(Item + 4);
  if (++*(*(Item + 3) + 16LL) >= 2)
  {
    v14 = NewSpecific(string, 7u);
    v14->m_Items[0] = "AssetBundleCtrl:Loaded:";
    v14->m_Items[1] = key;
    v14->m_Items[2] = ":";
    v20 = sub_232970(Item + 4);
    v21 = v20;
    v14->m_Items[3] = v21;
    v14->m_Items[4] = "(";
    v26 = sub_232970((*(Item + 3) + 16LL));
    v27 = v26;
    v14->m_Items[5] = v27;
    v14->m_Items[6] = ")";
    v33 = Concat_5271600(v14);
    Log(v33, 0);
  }
  else
  {
    v13 = Allocate(AssetBundleCtrl__LoadCoroutine_d__11);
    _ctor(v13, 0);
    *(v13 + 4) = 0;
    v13[4] = this;
    v13[6] = key;
    *(v13 + 10) = dlc_id;
    StartCoroutine_27343696(this, v13);
  }
}

// 0xfdacf0
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension) {
  System_String_o *v11;

  v11 = Concat_5271136(path, "/", name, extension);
  return LoadFile_16626736(this, key, v11);
}

// 0xfdae40
void *LoadFileAsync(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension) {
  System_String_o *v11;

  v11 = Concat_5271136(path, "/", name, extension);
  return LoadFileAsync_16626960(this, key, v11);
}

// 0xfdb510
void *LoadFileAsync_16626960(AssetBundleCtrl *this, char *key, char *path_name) {
  UnityEngine_AssetBundle_o *v7;
  System_String_o *v8;

  if (Animator___ContainsKey(this->assetbundle, key))
  {
    v7 = *(object___get_Item(this->assetbundle, key)[1].monitor
         + 4);
  }
  else
  {
    v7 = 0;
  }
  v8 = Concat_5224608("Assets/AssetBundle/AssetData/", path_name);
  return LoadAssetAsync(v7, v8);
}

// 0xfdb600
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name) {
  UnityEngine_Object_o *File_16626736;
  s64 typeHierarchyDepth;

  File_16626736 = LoadFile_16626736(this, key, path_name);
  if (File_16626736)
  {
    if (File_16626736->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (File_16626736->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        File_16626736 = 0;
    }
    else
    {
      File_16626736 = 0;
    }
  }
  return get_bytes(File_16626736);
}

// 0xfdb5f0
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name) {
  return LoadFile_16626736(this, key, path_name);
}

// 0xfdb430
void *LoadFile_16626736(AssetBundleCtrl *this, char *key, char *path_name) {
  UnityEngine_AssetBundle_o *v7;
  System_String_o *v8;

  if (Animator___ContainsKey(this->assetbundle, key))
  {
    v7 = *(object___get_Item(this->assetbundle, key)[1].monitor
         + 4);
  }
  else
  {
    v7 = 0;
  }
  v8 = Concat_5224608("Assets/AssetBundle/AssetData/", path_name);
  return LoadAsset(v7, v8, 0);
}

// 0xfdaa30
void *LoadPrefab(AssetBundleCtrl *this, char *key, char *path, char *name, char *par, char *name2) {
  UnityEngine_GameObject_o *v12;

  v12 = Find(par, 0);
  return LoadPrefab_16624272(this, key, path, name, v12, name2);
}

// 0xfdad80
void *LoadPrefabAsync(AssetBundleCtrl *this, char *key, char *path, char *name) {
  System_String_o *v9;
  System_String_o *v10;

  v9 = ".prefab";
  v10 = Concat_5271136(path, "/", name, v9);
  return LoadFileAsync_16626960(this, key, v10);
}

// 0xfdaa90
void *LoadPrefab_16624272(AssetBundleCtrl *this, char *key, char *path, char *name, void *parent, char *name2) {
  System_String_o *v13;
  System_String_o *v14;
  UnityEngine_Object_o *File_16626736;
  Il2CppObject *v17;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v20;
  UnityEngine_GameObject_o *v21;
  System_String_o *v22;

  v13 = ".prefab";
  v14 = Concat_5271136(path, "/", name, v13);
  File_16626736 = LoadFile_16626736(this, key, v14);
  if (File_16626736)
  {
    if (File_16626736->klass == UnityEngine_GameObject)
      v17 = File_16626736;
    else
      v17 = 0;
  }
  else
  {
    v17 = 0;
  }
  transform = get_transform(parent, 0);
  v20 = Instantiate_object__425520(v17, transform);
  v21 = v20;
  if (name2)
    v22 = name2;
  else
    v22 = name;
  set_name(v20, v22);
  return v21;
}

// 0xfdac10
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name) {
  System_String_o *v9;
  System_String_o *v10;
  UnityEngine_GameObject_o *result;

  v9 = ".prefab";
  v10 = Concat_5271136(path, "/", name, v9);
  result = LoadFile_16626736(this, key, v10);
  if (result)
  {
    if (result->klass != UnityEngine_GameObject)
      return 0;
  }
  return result;
}

// 0xfdaed0
void **LoadSprite(AssetBundleCtrl *this, char *key, char *path, char *name) {
  UnityEngine_AssetBundle_o *v9;
  System_String_array *v10;
  System_String_o *v17;

  if (Animator___ContainsKey(this->assetbundle, key))
  {
    v9 = *(object___get_Item(this->assetbundle, key)[1].monitor
         + 4);
  }
  else
  {
    v9 = 0;
  }
  v10 = NewSpecific(string, 5u);
  v10->m_Items[0] = "Assets/AssetBundle/AssetData/";
  v10->m_Items[1] = path;
  v10->m_Items[2] = "/";
  v10->m_Items[3] = name;
  v10->m_Items[4] = ".png";
  v17 = Concat_5271600(v10);
  return LoadAssetWithSubAssets_object_(v9, v17);
}

// 0xfdb1c0
void **LoadSprite_16626112(AssetBundleCtrl *this, char *key, char *fullPath) {
  UnityEngine_AssetBundle_o *v7;

  if (Animator___ContainsKey(this->assetbundle, key))
  {
    v7 = *(object___get_Item(this->assetbundle, key)[1].monitor
         + 4);
  }
  else
  {
    v7 = 0;
  }
  return LoadAssetWithSubAssets_object_(v7, fullPath);
}

// 0xfda550
void UnloadAB(AssetBundleCtrl *this, char *key) {
  Il2CppObject *Item;
  s32 *v6;
  Il2CppObject *v7;
  System_String_array *v8;
  s64 *v12;
  s64 *v13;
  s64 *v16;
  s64 *v17;
  Il2CppObject *v21;
  s32 *monitor;
  UnityEngine_Object_o *v24;

  if (Animator___ContainsKey(this->assetbundle, key))
  {
    Item = object___get_Item(this->assetbundle, key);
    v6 = &Item[1];
    --LODWORD(Item[1].klass);
    --*(Item[1].monitor + 4);
    v7 = Item;
    v8 = NewSpecific(string, 7u);
    v8->m_Items[0] = "AssetBundleCtrl:Unload:";
    v8->m_Items[1] = key;
    v8->m_Items[2] = "-";
    v12 = sub_232970(v6);
    v13 = v12;
    v8->m_Items[3] = v13;
    v8->m_Items[4] = "(";
    v16 = sub_232970(v7[1].monitor + 4);
    v17 = v16;
    v8->m_Items[5] = v17;
    v8->m_Items[6] = ")";
    v21 = Concat_5271600(v8);
    Log(v21, 0);
    if (*v6 <= 0)
    {
      HashSet_Text____Remove(this->assetbundle, key);
      monitor = v7[1].monitor;
      if (monitor[4] > 0)
        return;
    }
    else
    {
      monitor = v7[1].monitor;
      if (monitor[4] > 0)
        return;
    }
    monitor[4] = 0;
    v24 = *(v7[1].monitor + 4);
    if (op_Inequality(v24, 0, 0))
    {
      Unload(*(v7[1].monitor + 4), 0, 0);
      *(v7[1].monitor + 4) = 0;
    }
  }
}

// 0xfda9c0
void UnloadABAll(AssetBundleCtrl *this) {
  StopAllCoroutines(this);
  PropertySheet___Clear(this->assetbundle);
  UnloadAllAssetBundles(0);
}
