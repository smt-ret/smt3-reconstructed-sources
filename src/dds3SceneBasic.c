#include "types.h"

typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static char *dds3SceneBasic_ScriptProcName;

u32 DDS3_GETBASICTYPEL(dds3Basic_t *pAreaBasic);
dds3Basic_t *dds3AddBasic(u32 type);
s32 dds3AddBasicArray(dds3BasicArrayHandle_t **hndl, s32 bufcnt);
void dds3DeleteBasic(dds3Basic_t **basic);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic);
dds3BasicArrayHandle_t *dds3GetBasicArrayHandle(s32 bufcnt);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3SceneBasicFreeScene(dds3Basic_t **pBasic);
void dds3SceneBasicReleaseScriptFile(dds3Basic_t **scene);
dds3Basic_t *dds3SceneBasicSearchNameAndType_1(dds3Basic_t *scene, u32 type, char *name);
dds3Basic_t *dds3SceneBasicSearchNameAndType_2(dds3Basic_t *scene, u32 type, char *name);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
s32 dds3SetBasicArray(dds3BasicArrayHandle_t **hndl, dds3Basic_t **data);
void fldFreeFile(void);
void *fldLoadFile(char *pFileName, char *akey);
s32 scrSearchProcedureName(void *scrdata, char *procname);
dds3ProcessID_t *scrStartScript2(s32 a, void *b, s32 c);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);

// 0x14e5dc0
dds3Basic_t *dds3AddSceneBasicData(u32 type) {
    dds3GetControlScene();
    dds3AddBasic(0);
    return 0;
}

// 0x14e60f0
void dds3DeleteSceneBasicData(dds3Basic_t **basic) {
    DDS3_GETBASICTYPEL(0);
    dds3DeleteBasic(0);
}

// 0x14f8580
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic) {
    return 0;
}

// 0x14f8790
dds3Basic_t *dds3GetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic) {
    return 0;
}

// 0x14f9790
s32 dds3GetMapNo(dds3Basic_t **scene) {
    return 0;
}

// 0x14f9360
char *dds3GetScriptProcName(void) {
  return dds3SceneBasic_ScriptProcName;
}

// 0x14f9260
void dds3SceneBasicEndScript(dds3Basic_t **scene, char *procname) {
  u64 *v4;
  dds3ProcessID_t_o *id;

  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  id = v4;
  dds3SceneBasic_ScriptProcName = StringLiteral_416;
  if (procname)
  {
    id = dds3SearchProcessName(procname);
    if (id)
    {
      dds3KillProcess(&id, 0);
    }
  }
}

// 0x14f9520
s32 dds3SceneBasicExistBasic(dds3Basic_t **scene, dds3Basic_t **target) {
    return 0;
}

// 0x14f93d0
s32 dds3SceneBasicExistBasicFromType(dds3Basic_t **scene, s32 type, dds3Basic_t *target) {
    return 0;
}

// 0x14f7dd0
void dds3SceneBasicFreeScene(dds3Basic_t **pBasic) {
    fldFreeFile();
}

// 0x14f8880
dds3BasicArrayHandle_t *dds3SceneBasicGetList(dds3Basic_t **pBasic, u32 type) {
    dds3GetBasicArrayHandle(0);
    dds3AddBasicArray(0, 0);
    dds3SetBasicArray(0, 0);
    return 0;
}

// 0x14f8c60
s32 dds3SceneBasicLoadScriptFile(dds3Basic_t **scene, char *scrfile, char *akey) {
    dds3SceneBasicReleaseScriptFile(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    return 0;
}

// 0x14f8e40
s32 dds3SceneBasicLoadScriptFile_FromMem(dds3Basic_t **scene, void *mem) {
    dds3SceneBasicReleaseScriptFile(0);
    return 0;
}

// 0x14f8a80
void dds3SceneBasicMakeScene(dds3Basic_t **pBasic, char *file, char *akey) {
    fldLoadFile(0, 0);
}

// 0x14f8c50
void dds3SceneBasicMakeScene_FromMemory(dds3Basic_t **pBasic, s32 field, s32 area, void *pF1, void *pF2, void *pTB, void *pBF) {
  ;
}

// 0x14f7ee0
void dds3SceneBasicReleaseScriptFile(dds3Basic_t **scene) {
}

// 0x14f9d40
dds3Basic_t *dds3SceneBasicSearchName(dds3Basic_t **scene, char *name) {
  dds3Basic_t_o *result;
  dds3Basic_t_o *v7;
  u32 v8;
  s32 v10;
  dds3Basic_t_o *v11;

  result = 0;
  if (name)
  {
    v7 = *scene;
    if (*scene)
    {
      v8 = 0;
      while (1)
      {
        result = dds3SceneBasicSearchNameAndType_1(v7, v8, name);
        if (result)
          break;
        if (v8 >= 0x11)
        {
          v10 = -1;
          while (1)
          {
            v11 = *scene;
            result = dds3SceneBasicSearchNameAndType_2(v11, v10 + 1, name);
            if (result)
              break;
            if (++v10 >= 0x11)
              return 0;
          }
          return result;
        }
        v7 = *scene;
        ++v8;
      }
    }
  }
  return result;
}

// 0x14f9890
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name) {
    return 0;
}

// 0x14f9a60
dds3Basic_t *dds3SceneBasicSearchNameAndType_1(dds3Basic_t *scene, u32 type, char *name) {
    return 0;
}

// 0x14f9bd0
dds3Basic_t *dds3SceneBasicSearchNameAndType_2(dds3Basic_t *scene, u32 type, char *name) {
    return 0;
}

// 0x14f8f70
dds3ProcessID_t *dds3SceneBasicStartScript(dds3Basic_t **scene, char *procname) {
    scrSearchProcedureName(0, 0);
    dds3SearchProcessName(0);
    scrStartScript2(0, 0, 0);
    return 0;
}

// 0x14eab00
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type) {
    return 0;
}

// 0x14f8450
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic) {
    dds3GetActiveCameraSceneBasic(0);
    return 0;
}

// 0x14f8670
dds3Basic_t *dds3SetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic, dds3Basic_t *pUnitBasic) {
    dds3GetActiveUnitSceneBasic(0);
    return 0;
}

// 0x14f9690
void dds3SetMapNo(dds3Basic_t **scene, s32 mapno) {
}

// 0x14f8350
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible) {
}

// 0x14f7a30
s32 sceneconstructor(dds3Basic_t *basic) {
  dds3SceneBasic_t_o *v3;
  struct dds3SceneBasicTable_t_array *v4;
  u32 *v5;
  s64 i;
  u64 v7;
  u64 *v8;
  struct dds3SceneBasicTable_t_array *basictable;
  struct dds3SceneBasicTable_t_array *v12;
  struct dds3SceneBasicTable_t_array *v14;

  v3 = Allocate(dds3SceneBasic_t);
  dds3SceneBasic_t___ctor(v3);
  if (!v3)
    return 0;
  v3->mapno = -1;
  v3->activecamera = 0;
  v3->hScrFileHandle = 0;
  v3->pScrFileData = 0;
  v3->activeunit = 0;
  v3->hFileHandle = 0;
  v3->visible = 1;
  v3->mem_hndl = 0;
  v3->basictable = 0;
  v4 = NewSpecific(dds3SceneBasicTable_t, 0x12u);
  v3->basictable = v4;
  v5 = v4;
  for (i = 4; ; ++i)
  {
    v7 = i - 4;
    v8 = Allocate(dds3SceneBasicTable_t);
    dds3SceneBasicTable_t___ctor(v8);
    *&v5[2 * i] = v8;
    basictable = v3->basictable;
    *(*(&basictable->obj.klass + i) + 16LL) = 0;
    v12 = v3->basictable;
    *(*(&v12->obj.klass + i) + 24LL) = 0;
    v14 = v3->basictable;
    *(*(&v14->obj.klass + i) + 32LL) = 0;
    if (i == 21)
      break;
    v5 = v3->basictable;
  }
  basic->workdata = v3;
  return 1;
}

// 0x14f7c00
s32 scenedestructor(dds3Basic_t *basic) {
    dds3DeleteSceneBasicData(0);
    dds3SceneBasicFreeScene(0);
    dds3SceneBasicReleaseScriptFile(0);
    return 0;
}

// 0x14f81a0
s32 scenedrawprocuder(dds3Basic_t *basic) {
    return 0;
}

// 0x14f7fe0
s32 scenemainprocuder(dds3Basic_t *basic) {
    return 0;
}
