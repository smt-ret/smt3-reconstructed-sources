#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct AssetBundles_STOCK AssetBundles_STOCK;
typedef struct DlcFileCtr DlcFileCtr;

struct AssetBundles {
    void *manifest;
    void *stock;
};

struct AssetBundles_STOCK {
    char *key;
    char *filename;
    s32 dlc_id;
};

static AssetBundles *Manifest;
static AssetBundleCtrl *_Ctrl_k__BackingField;
static DlcFileCtr *_Dlc_k__BackingField;

bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void LoadDirect(AssetBundleCtrl *this, char *key, char *aname, s32 dlc_id);
bool LoadManifest(AssetBundles *this);
void Load_16632688(AssetBundles *this, char *key, s32 dlc_id, char *filename);
void UnloadAB(AssetBundleCtrl *this, char *key);
void UnloadDependencies(AssetBundles *this, char *filename);

// 0xfdcf40
bool IsLoad(AssetBundles *this, char *key) {
  UnityEngine_AssetBundleManifest_o *manifest;
  struct AssetBundleCtrl_o *Ctrl_k__BackingField;
  UnityEngine_Object_o *v12;
  System_String_o *name;
  System_String_array *AllDependencies;
  il2cpp_array_size_t max_length;
  bool v18;
  System_String_array *v19;
  u64 v20;
  System_String_o **m_Items;
  System_String_o *v23;

  if (!LoadManifest(this, key))
    return 0;
  if (!IsLoad(_Ctrl_k__BackingField, key))
    return 0;
  manifest = this->manifest;
  Ctrl_k__BackingField = _Ctrl_k__BackingField;
  if (Animator___ContainsKey(Ctrl_k__BackingField->assetbundle, key))
  {
    v12 = *(object___get_Item(Ctrl_k__BackingField->assetbundle, key)[1].monitor
          + 4);
  }
  else
  {
    v12 = 0;
  }
  name = get_name(v12);
  AllDependencies = GetAllDependencies(manifest, name);
  max_length = AllDependencies->max_length;
  v18 = 1;
  if (max_length >= 1)
  {
    v19 = AllDependencies;
    v20 = 0;
    m_Items = AllDependencies->m_Items;
    while (1)
    {
      v23 = m_Items[v20];
        break;
      if ((byte_3F5879B & 1) == 0)
      if (!IsLoad(_Ctrl_k__BackingField, v23))
        return 0;
      LODWORD(max_length) = v19->max_length;
      if (++v20 >= max_length)
        return 1;
    }
    if ((byte_3F5879B & 1) != 0)
  }
  return v18;
}

// 0xfdc940
void Load(AssetBundles *this, char *key, char *filename) {
  AssetBundleCtrl_o *Ctrl_k__BackingField;
  System_String_o *v10;
  System_String_array *AllDependencies;
  il2cpp_array_size_t max_length;
  System_String_array *v15;
  u64 v16;
  System_String_o **m_Items;
  System_String_o *v19;
  AssetBundleCtrl_o *v21;
  System_String_o *v22;
  System_Collections_Generic_List_AssetBundles_STOCK__o *stock;
  AssetBundles_STOCK_o v25;

  if (!LoadManifest(this, key))
  {
    stock = this->stock;
    v25.key = key;
    v25.filename = filename;
    *&v25.dlc_id = 0xFFFFFFFFLL;
    _Add(stock, &v25);
    return;
  }
  Ctrl_k__BackingField = _Ctrl_k__BackingField;
  v10 = ToLower(filename, 0);
  LoadDirect(Ctrl_k__BackingField, key, v10, -1);
  AllDependencies = GetAllDependencies(this->manifest, filename);
  max_length = AllDependencies->max_length;
  if (max_length >= 1)
  {
    v15 = AllDependencies;
    v16 = 0;
    m_Items = AllDependencies->m_Items;
    while (1)
    {
      v19 = m_Items[v16];
        break;
      if ((byte_3F5879B & 1) == 0)
      v21 = _Ctrl_k__BackingField;
      v22 = ToLower(v19, 0);
      LoadDirect(v21, v19, v22, -1);
      LODWORD(max_length) = v15->max_length;
      if (++v16 >= max_length)
        return;
    }
    if ((byte_3F5879B & 1) != 0)
  }
}

// 0xfdc5b0
bool LoadManifest(AssetBundles *this) {
    IsLoad(0, 0);
    UnloadAB(0, 0);
    Load(0, 0);
    Load_16632688(0, 0, 0, 0);
    return 0;
}

// 0xfdcb70
void Load_16632688(AssetBundles *this, char *key, s32 dlc_id, char *filename) {
  DlcFileCtr_o *v11;
  System_String_array *AllDependencies;
  il2cpp_array_size_t max_length;
  System_String_array *v15;
  u64 v16;
  System_String_o **m_Items;
  System_String_o *v20;
  System_String_o *v21;
  AssetBundleCtrl_o *Ctrl_k__BackingField;
  System_String_o *v26;
  DlcFileCtr_o *v28;
  System_Collections_Generic_List_AssetBundles_STOCK__o *stock;
  AssetBundles_STOCK_o v30;

  if (!LoadManifest(this, key))
  {
    stock = this->stock;
    v30.key = key;
    v30.filename = filename;
    v30.dlc_id = dlc_id;
    *(&v30.dlc_id + 1) = 0;
    _Add(stock, &v30);
    return;
  }
  Load(v11, key, dlc_id, filename);
  AllDependencies = GetAllDependencies(this->manifest, filename);
  max_length = AllDependencies->max_length;
  if (max_length >= 1)
  {
    v15 = AllDependencies;
    v16 = 0;
    m_Items = AllDependencies->m_Items;
    while (1)
    {
      while (1)
      {
        v20 = m_Items[v16];
        v21 = Concat_5224608(resourcePath, v20);
        if (!Exists(v21))
          break;
        if ((byte_3F5879B & 1) == 0)
        Ctrl_k__BackingField = _Ctrl_k__BackingField;
        v26 = ToLower(v20, 0);
        LoadDirect(Ctrl_k__BackingField, v20, v26, -1);
        LODWORD(max_length) = v15->max_length;
        if (++v16 >= max_length)
          return;
      }
        break;
      if ((byte_3F5879D & 1) == 0)
      Load(v28, v20, dlc_id, v20);
      LODWORD(max_length) = v15->max_length;
      if (++v16 >= max_length)
        return;
    }
    if ((byte_3F5879D & 1) != 0)
  }
}

// 0xfdd1d0
void Unload(AssetBundles *this, char *key) {
  struct AssetBundleCtrl_o *Ctrl_k__BackingField;
  UnityEngine_Object_o *v9;
  System_String_o *name;

  if (LoadManifest(this, key))
  {
    Ctrl_k__BackingField = _Ctrl_k__BackingField;
    if (Animator___ContainsKey(Ctrl_k__BackingField->assetbundle, key))
    {
      v9 = *(object___get_Item(Ctrl_k__BackingField->assetbundle, key)[1].monitor
           + 4);
    }
    else
    {
      v9 = 0;
    }
    if (op_Inequality(v9, 0, 0))
    {
      name = get_name(v9);
      UnloadDependencies(this, name);
      UnloadAB(_Ctrl_k__BackingField, key);
    }
  }
}

// 0xfdd3c0
void UnloadDependencies(AssetBundles *this, char *filename) {
  System_String_array *AllDependencies;
  il2cpp_array_size_t max_length;
  System_String_o **m_Items;
  System_String_array *v10;
  u64 v11;
  System_String_o *v13;

  if (LoadManifest(this, filename))
  {
    AllDependencies = GetAllDependencies(this->manifest, filename);
    max_length = AllDependencies->max_length;
    if (max_length >= 1)
    {
      m_Items = AllDependencies->m_Items;
      v10 = AllDependencies;
      v11 = 0;
      while (1)
      {
        v13 = m_Items[v11];
          break;
        if ((byte_3F5879B & 1) == 0)
        UnloadAB(_Ctrl_k__BackingField, v13);
        LODWORD(max_length) = v10->max_length;
        if (++v11 >= max_length)
          return;
      }
      if ((byte_3F5879B & 1) != 0)
    }
  }
}
