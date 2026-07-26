#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct evtTexManager evtTexManager;

struct evtTexManager {
    void Textures[UNKNOWN_ARRAY_SIZE];
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
  v11 = Concat_5271136(StringLiteral_15919, key, StringLiteral_74, path);
  LoadTexture(this, key, v11, StringLiteral_15999);
}

// 0x1953d00
void LoadTexture(evtTexManager *this, char *key, char *path, char *name) {
    LoadFileObject(0, 0, 0);
    LoadFile(0, 0, 0, 0, 0);
}

// 0x1954430
void LoadTexture_26559536(evtTexManager *this, void ***tex, char *key) {
    billClrTexture(0);
    LoadFileObject(0, 0, 0);
    LoadFile(0, 0, 0, 0, 0);
}
