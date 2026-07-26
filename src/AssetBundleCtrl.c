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
  v9 = Concat_5224608(StringLiteral_4583, path_name);
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

  v9 = StringLiteral_4586;
  v10 = Concat_5271136(path, StringLiteral_74, name, v9);
  return LoadFile_16626736(this, key, v10);
}

// 0xfdb290
void *LoadAudioClip(AssetBundleCtrl *this, char *key, char *path, char *name) {
  System_String_o *v9;
  System_String_o *v10;
  UnityEngine_AudioClip_o *result;

  v9 = StringLiteral_4585;
  v10 = Concat_5271136(path, StringLiteral_74, name, v9);
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
}

// 0xfdacf0
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension) {
  System_String_o *v11;

  v11 = Concat_5271136(path, StringLiteral_74, name, extension);
  return LoadFile_16626736(this, key, v11);
}

// 0xfdae40
void *LoadFileAsync(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension) {
  System_String_o *v11;

  v11 = Concat_5271136(path, StringLiteral_74, name, extension);
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
  v8 = Concat_5224608(StringLiteral_4583, path_name);
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
  v8 = Concat_5224608(StringLiteral_4583, path_name);
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

  v9 = StringLiteral_4582;
  v10 = Concat_5271136(path, StringLiteral_74, name, v9);
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

  v13 = StringLiteral_4582;
  v14 = Concat_5271136(path, StringLiteral_74, name, v13);
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

  v9 = StringLiteral_4582;
  v10 = Concat_5271136(path, StringLiteral_74, name, v9);
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
  v10->m_Items[0] = StringLiteral_4583;
  v10->m_Items[1] = path;
  v10->m_Items[2] = StringLiteral_74;
  v10->m_Items[3] = name;
  v10->m_Items[4] = StringLiteral_4584;
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
}

// 0xfda9c0
void UnloadABAll(AssetBundleCtrl *this) {
  StopAllCoroutines(this);
  PropertySheet___Clear(this->assetbundle);
  UnloadAllAssetBundles(0);
}
