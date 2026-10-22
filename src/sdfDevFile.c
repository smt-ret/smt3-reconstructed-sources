#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);

// 0x17e6520
sdfMemHandle_t *sdfDevLoadFile(char *aFilename, void **aTopPtr, s32 aSizePtr) {
  u64 *v4;
  u64 *v5;

  v4 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v4);
  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  return v5;
}

// 0x17e64a0
sdfMemHandle_t *sdfDevLoadFileEx(char *aFilename, void *aTopPtr, s32 *aSizePtr, s32 aMergin) {
  u64 *v5;
  u64 *v6;

  v5 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v5);
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  return v6;
}

// 0x17e65a0
void *sdfDevLoadFileUnity(char *aFilename, void **aTopPtr, s32 aSizePtr, char *akey) {
  Il2CppObject *v9;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *FileObject;

  v9 = Concat_5271136("sdfDevLoadFileUnity:file=", aFilename, " akey=", akey);
  Log(v9, 0);
  asset_bc = get_asset_bc();
  FileObject = LoadFileObject(asset_bc, akey, aFilename);
  if (!FileObject)
  {
    Log("sdfDevLoadFileUnity:null", 0);
  }
  *aTopPtr = FileObject;
  return FileObject;
}

// 0x17e66d0
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey) {
  AssetBundleCtrl_o *asset_bc;

  asset_bc = get_asset_bc();
  *aTopPtr = LoadFileByte(asset_bc, akey, aFilename);
  return 0;
}

// 0x17e6980
sdfMemHandle_t *sdfDevLoadModel(char *aFilename, sdfModelDef_t **aModelDefPtr) {
  u64 *v4;

  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  Write_2930400("{0} loading...\n", aFilename);
  return v4;
}

// 0x17e6a80
sdfMemHandle_t *sdfDevLoadMotion(char *aFilename, sdfMotionPlayBook_t **aPlayBookPtr) {
  u64 *v4;

  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  Write_2930400("{0} loading...\n", aFilename);
  return v4;
}

// 0x17e6760
sdfTexHandle_t *sdfDevLoadTex(char *aFilename) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v4);
  Write_2930400("{0} loading...\n", aFilename);
  return v4;
}

// 0x17e6870
sdfModelTexList_t *sdfDevLoadTexList(char *aFilename) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(sdfModelTexList_t);
  sdfModelTexList_t___ctor(v3);
  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  Write_2930400("{0} loading...\n", aFilename);
  return v3;
}

// 0x17e6920
sdfModelDef_t *sdfFixupModelBinary(void *aData) {
  u64 *v2;

  v2 = Allocate(sdfModelDef_t);
  sdfModelDef_t___ctor(v2);
  return v2;
}

// 0x17e6a20
sdfMotionPlayBook_t *sdfFixupMotionBinary(void *aData) {
  u64 *v2;

  v2 = Allocate(sdfMotionPlayBook_t);
  sdfMotionPlayBook_t___ctor(v2);
  return v2;
}

// 0x17e6810
sdfModelTexList_t *sdfTexSetTB(void *aData) {
  u64 *v2;

  v2 = Allocate(sdfModelTexList_t);
  sdfModelTexList_t___ctor(v2);
  return v2;
}
