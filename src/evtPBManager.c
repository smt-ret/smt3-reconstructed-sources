#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct SOBED_PB_LIST SOBED_PB_LIST;
typedef struct evtPBManager_EvtPBData evtPBManager_EvtPBData;

struct evtPBManager_EvtPBData {
    u8 pb[UNKNOWN_ARRAY_SIZE];
    SOBED_PB_LIST *bed;
};

static void *PBs;

void DeletePB(bool unload);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void LoadPB(char *key, char *path, char *name);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void SetPbList(SOBED_PB_LIST *gList);

// 0x10f1d60
void BillSetPB(s32 index) {
  struct SOBED_PB_LIST_o *bed;
  SOBED_PB_LIST_o *v7;

  if (evtPBManager_EvtPBData___ContainsKey(PBs, index))
  {
    bed = evtPBManager_EvtPBData___get_Item(PBs, index).bed;
    v7 = bed;
    SetPbList(v7);
  }
}

// 0x10f1730
void DeletePB(bool unload) {
  System_Collections_Generic_Dictionary_int__evtPBManager_EvtPBData__o *PBs;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  evtPBManager_EvtPBData_array *v6;
  il2cpp_array_size_t max_length;
  u64 v9;
  struct SOBED_PB_LIST_o **p_bed;

  else
  {
    if (!PBs)
      return;
  }
  Values = evtPBManager_EvtPBData___get_Values(PBs);
  v6 = ToArray_evtPBManager_EvtPBData_(Values);
  max_length = v6->max_length;
  if (max_length >= 1)
  {
    v9 = 0;
    p_bed = &v6->m_Items[0].bed;
    do
    {
      if (*p_bed)
      {
        *p_bed = 0;
      }
      if (*(p_bed - 1))
      {
        *(p_bed - 1) = 0;
      }
      LODWORD(max_length) = v6->max_length;
      ++v9;
      p_bed += 2;
    }
    while (v9 < max_length);
  }
  evtPBManager_EvtPBData___Clear(PBs);
  if (unload)
    UnloadUnusedAssets();
}

// 0x10f1ce0
void Destroy(bool unload) {
    DeletePB(0);
}

// 0x10f1610
void Initialize(char *key, char *path) {
  System_String_o *v8;

  if (evtPBManager_EvtPBData___get_Count(PBs))
  {
    DeletePB(1);
  }
  evtPBManager_EvtPBData___Clear(PBs);
  v8 = Concat_5271136(StringLiteral_15919, key, StringLiteral_74, path);
  LoadPB(key, v8, StringLiteral_15937);
}

// 0x10f1910
void LoadPB(char *key, char *path, char *name) {
  u64 *v6;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v9;
  Il2CppObject *FileObject;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v14;
  System_String_array *v15;
  System_String_array *v17;
  s32 v18;
  System_String_array *v19;
  u64 v20;
  s64 v21;
  SOBED_PB_LIST_o *v22;
  AssetBundleCtrl_o *v24;
  System_String_o **v26;
  System_String_o *v27;
  struct System_Byte_array *FileByte;
  AssetBundleCtrl_o *v31;
  s64 v35;
  evtPBManager_EvtPBData_o v37;

  v6 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v6);
  asset_bc = get_asset_bc();
  v9 = Concat_5221536(path, StringLiteral_74, name);
  FileObject = LoadFileObject(asset_bc, key, v9);
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
    v14 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
    v15 = NewSpecific(string, 1u);
    v15->m_Items[0] = StringLiteral_489;
    v17 = Split_5246672(v14, v15, 0);
    v18 = LODWORD(v17->max_length) - 1;
    if (v18 >= 2)
    {
      v19 = v17;
      v20 = 0;
      v21 = 0;
      v35 = (v18 >> 1);
      do
      {
        v22 = Allocate(SOBED_PB_LIST);
        SOBED_PB_LIST___ctor(v22);
        v24 = get_asset_bc();
        v26 = (&v19->obj.klass + v20);
        v27 = Concat_5271136(path, StringLiteral_74, v26[4], StringLiteral_15938);
        FileByte = LoadFileByte(v24, key, v27);
        if (!Equals_5234480(v26[5], StringLiteral_3674))
        {
          v31 = get_asset_bc();
          v22->gobj = LoadPrefab_16624656(v31, key, path, v26[5]);
        }
        v37.pb = FileByte;
        v37.bed = v22;
        evtPBManager_EvtPBData___Add(PBs, v21++, v37);
        v20 += 2LL;
      }
      while (v35 != v21);
    }
  }
}
