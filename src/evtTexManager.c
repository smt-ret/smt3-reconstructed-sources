#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct evtTexManager evtTexManager;

struct evtTexManager {
    void *Textures;
};

void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void LoadTexture(evtTexManager *this, char *key, char *path, char *name);
void billClrTexture(bool allclear);
void billSetTexture(void **pTexture);

// 0x19543c0
void BillSetTexture(evtTexManager *this) {
  UnityEngine_Texture_array *Textures;

  Textures = this->Textures;
  billSetTexture(Textures);
}

// 0x1953c70
void DeleteTexture(evtTexManager *this, bool unload) {
  struct UnityEngine_Texture_array *Textures;
  Il2CppClass **max_length;
  u64 v5;

  Textures = this->Textures;
  if (Textures)
  {
    max_length = Textures->max_length;
    if (max_length >= 1)
    {
      v5 = 0;
      do
      {
        max_length = &Textures->obj.klass + v5++;
        max_length[4] = 0;
        Textures = this->Textures;
        LODWORD(max_length) = Textures->max_length;
      }
      while (v5 < max_length);
    }
    if (unload)
      UnloadUnusedAssets();
  }
}

// 0x1954330
void Destroy(evtTexManager *this, bool unload) {
  struct UnityEngine_Texture_array *Textures;
  Il2CppClass **max_length;
  u64 v5;

  Textures = this->Textures;
  if (Textures)
  {
    max_length = Textures->max_length;
    if (max_length >= 1)
    {
      v5 = 0;
      do
      {
        max_length = &Textures->obj.klass + v5++;
        max_length[4] = 0;
        Textures = this->Textures;
        LODWORD(max_length) = Textures->max_length;
      }
      while (v5 < max_length);
    }
    if (unload)
      UnloadUnusedAssets();
  }
}

// 0x1953b50
void Initialize(evtTexManager *this, char *key, char *path) {
  struct UnityEngine_Texture_array *Textures;
  Il2CppClass **max_length;
  u64 v9;
  System_String_o *v11;

  Textures = this->Textures;
  if (Textures)
  {
    max_length = Textures->max_length;
    if (max_length >= 1)
    {
      v9 = 0;
      do
      {
        max_length = &Textures->obj.klass + v9++;
        max_length[4] = 0;
        Textures = this->Textures;
        LODWORD(max_length) = Textures->max_length;
      }
      while (v9 < max_length);
    }
    UnloadUnusedAssets();
  }
  this->Textures = 0;
  billClrTexture(0);
  v11 = Concat_5271136("dds3data/event/", key, "/", path);
  LoadTexture(this, key, v11, "TexList.bytes");
}

// 0x1953d00
void LoadTexture(evtTexManager *this, char *key, char *path, char *name) {
  u64 *v9;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v12;
  Il2CppObject *FileObject;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v17;
  System_String_array *v18;
  System_String_array *v20;
  u64 *v21;
  u32 *v23;
  s32 *v24;
  s64 v25;
  u64 v26;
  AssetBundleCtrl_o *v27;
  s64 *File;
  s64 *v31;
  s64 v32;
  s64 v33;
  char *v34;
  s64 *v35;
  s64 v37;
  s64 v38;
  char *v39;
  s64 *v40;
  struct UnityEngine_Texture_array *Textures;
  UnityEngine_Object_o *v44;
  u32 *v45;
  AssetBundleCtrl_o *v46;
  s64 *v48;
  s64 *v49;
  s64 v50;
  s64 v51;
  char *v52;
  s64 *v53;
  s64 v55;
  s64 v56;
  char *v57;
  s64 *v58;
  s64 v60;
  u64 v62[2];
  char *v63;

  v9 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v9);
  asset_bc = get_asset_bc();
  v12 = Concat_5221536(path, "/", name);
  FileObject = LoadFileObject(asset_bc, key, v12);
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
    v17 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
    v18 = NewSpecific(string, 1u);
    v18->m_Items[0] = "\r\n";
    v20 = Split_5246672(v17, v18, 0);
    v21 = NewSpecific(UnityEngine_Texture, (LODWORD(v20->max_length) - 1));
    this->Textures = v21;
    v23 = (v21 + 3);
    if (*(v21 + 6) >= 1)
    {
      v24 = v21;
      v25 = 4;
      do
      {
        v26 = v25 - 4;
        v27 = get_asset_bc();
        File = LoadFile(v27, key, path, *(&v20->obj.klass + v25), ".png", 0);
        v31 = File;
        if (File)
        {
          v32 = *File;
          if (*(*File + 288) < v33 || *(*(v32 + 200) + 8 * v33 - 8) != UnityEngine_Texture)
          {
            sub_8FC2C0(*(v32 + 64), UnityEngine_Texture, v62);
            if ((v62[0] & 1) != 0)
              v34 = v63;
            else
              v34 = v62 + 1;
            v35 = sub_8C4940(v34);
          }
          v37 = *v31;
          if (*(*v31 + 288) < v38 || *(*(v37 + 200) + 8 * v38 - 8) != UnityEngine_Texture)
          {
            sub_8FC2C0(*(v37 + 64), UnityEngine_Texture, v62);
            if ((v62[0] & 1) != 0)
              v39 = v63;
            else
              v39 = v62 + 1;
            v40 = sub_8C4940(v39);
          }
        }
        *&v24[2 * v25] = v31;
        Textures = this->Textures;
        v44 = *(&Textures->obj.klass + v25);
        if (op_Equality(v44, 0, 0))
        {
          v45 = this->Textures;
          v46 = get_asset_bc();
          v48 = LoadFile(v46, key, path, *(&v20->obj.klass + v25), ".tga", 0);
          v49 = v48;
          if (v48)
          {
            v50 = *v48;
            if (*(*v48 + 288) < v51 || *(*(v50 + 200) + 8 * v51 - 8) != UnityEngine_Texture)
            {
              sub_8FC2C0(*(v50 + 64), UnityEngine_Texture, v62);
              if ((v62[0] & 1) != 0)
                v52 = v63;
              else
                v52 = v62 + 1;
              v53 = sub_8C4940(v52);
            }
            v55 = *v49;
            if (*(*v49 + 288) < v56 || *(*(v55 + 200) + 8 * v56 - 8) != UnityEngine_Texture)
            {
              sub_8FC2C0(*(v55 + 64), UnityEngine_Texture, v62);
              if ((v62[0] & 1) != 0)
                v57 = v63;
              else
                v57 = v62 + 1;
              v58 = sub_8C4940(v57);
            }
          }
          *&v45[2 * v25] = v49;
        }
        v24 = this->Textures;
        v60 = v25 - 3;
        v23 = (v24 + 6);
        ++v25;
      }
      while (v60 < v24[6]);
    }
  }
}

// 0x1954430
void LoadTexture_26559536(evtTexManager *this, void ***tex, char *key) {
  UnityEngine_Texture_array *v5;
  u64 v6;
  Il2CppClass **v8;
  System_String_o *v9;
  s32 Length;
  s32 v11;
  System_String_array *v12;
  System_String_o *v18;
  u64 *v19;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v22;
  Il2CppObject *FileObject;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v27;
  System_String_array *v28;
  System_String_array *v30;
  UnityEngine_Texture_array *v31;
  s64 v33;
  u32 *v34;
  u64 v35;
  AssetBundleCtrl_o *v36;
  s64 *File;
  s64 *v39;
  s64 v40;
  s64 v41;
  char *v42;
  s64 *v43;
  s64 v45;
  s64 v46;
  char *v47;
  s64 *v48;
  s64 v50;
  u64 v58[2];
  char *v59;

  billClrTexture(0);
  v5 = *tex;
  if (*tex)
  {
    if (SLODWORD(v5->max_length) >= 1)
    {
      v6 = 0;
      do
      {
        v8 = &v5->obj.klass + v6++;
        v8[4] = 0;
        v5 = *tex;
      }
      while (v6 < SLODWORD((*tex)->max_length));
    }
    UnloadUnusedAssets();
  }
  *tex = 0;
  v9 = ToUpper(key, 0);
  Length = get_Length(v9);
  if (get_Chars(v9, Length - 1) == 77)
  {
    v11 = get_Length(v9);
    v9 = Substring_5248048(v9, 0, v11 - 1);
  }
  v12 = NewSpecific(string, 5u);
  v12->m_Items[0] = "dds3data/fld/f/";
  v12->m_Items[1] = key;
  v12->m_Items[2] = "/";
  v12->m_Items[3] = v9;
  v12->m_Items[4] = "_TEX";
  v18 = Concat_5271600(v12);
  v19 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v19);
  asset_bc = get_asset_bc();
  v22 = Concat_5224608(v18, "/TexList.bytes");
  FileObject = LoadFileObject(asset_bc, key, v22);
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
    v27 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
    v28 = NewSpecific(string, 1u);
    v28->m_Items[0] = "\r\n";
    v30 = Split_5246672(v27, v28, 0);
    v31 = NewSpecific(UnityEngine_Texture, (LODWORD(v30->max_length) - 1));
    *tex = v31;
    if (SLODWORD(v31->max_length) >= 1)
    {
      v33 = 4;
      v34 = v31;
      do
      {
        v35 = v33 - 4;
        v36 = get_asset_bc();
        File = LoadFile(v36, key, v18, *(&v30->obj.klass + v33), ".tga", 0);
        v39 = File;
        if (File)
        {
          v40 = *File;
          if (*(*File + 288) < v41 || *(*(v40 + 200) + 8 * v41 - 8) != UnityEngine_Texture)
          {
            sub_8FC2C0(*(v40 + 64), UnityEngine_Texture, v58);
            if ((v58[0] & 1) != 0)
              v42 = v59;
            else
              v42 = v58 + 1;
            v43 = sub_8C4940(v42);
          }
          v45 = *v39;
          if (*(*v39 + 288) < v46 || *(*(v45 + 200) + 8 * v46 - 8) != UnityEngine_Texture)
          {
            sub_8FC2C0(*(v45 + 64), UnityEngine_Texture, v58);
            if ((v58[0] & 1) != 0)
              v47 = v59;
            else
              v47 = v58 + 1;
            v48 = sub_8C4940(v47);
          }
        }
        *&v34[2 * v33] = v39;
        v34 = *tex;
        v50 = v33 - 3;
        ++v33;
      }
      while (v50 < SLODWORD((*tex)->max_length));
    }
  }
}
