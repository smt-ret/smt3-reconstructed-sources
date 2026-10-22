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
  dds3Basic_t_o *result;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  struct dds3Basic_t_o *v7;
  Il2CppClass *v8;
  s64 v10;
  s64 v11;
  s32 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  if (type - 2 > 0xF)
    return 0;
  else
  {
    result = dds3GetControlScene();
    if (!result)
      return result;
  }
  workdata = result->workdata;
  klass = workdata->klass;
  v7 = result;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  v8 = workdata[2].klass;
  v10 = *(&v8->_1.byval_arg.data + type);
  result = dds3AddBasic(type);
  if (result)
  {
    result->workpointer = v7;
    v11 = *(v10 + 32);
    if (v11)
    {
      *(v11 + 72) = result;
      result->prev = *(v10 + 32);
    }
    else
    {
      *(v10 + 24) = result;
    }
    v12 = *(v10 + 16) + 1;
    *(v10 + 32) = result;
    *(v10 + 16) = v12;
  }
  return result;
}

// 0x14e60f0
void dds3DeleteSceneBasicData(dds3Basic_t **basic) {
  dds3Basic_t_o *v3;
  u32 v4;
  dds3Basic_t_o *v5;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v9;
  s64 v11;
  s32 v12;
  struct dds3Basic_t_o *next;
  s32 v14;
  struct dds3Basic_t_o *prev;
  char *v17;
  s64 *v18;
  u64 v19[3];

  v3 = *basic;
  if (*basic)
  {
    v4 = DDS3_GETBASICTYPEL(v3);
    if (v4 - 2 <= 0xF)
    {
      v5 = *basic;
      workdata = (*basic)->workpointer->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v19);
        if ((v19[0] & 1) != 0)
          v17 = v19[2];
        else
          v17 = v19 + 1;
        v18 = sub_8C4940(v17);
      }
      v9 = workdata[2].klass;
      v11 = *(&v9->_1.byval_arg.data + v4);
      if (*(v11 + 24) == v5)
      {
        next = v5->next;
        v12 = 1;
        if (*(v11 + 32) != v5)
        {
LABEL_14:
          v14 = 0;
          prev = 0;
            goto LABEL_15;
          goto LABEL_19;
        }
      }
      else
      {
        v12 = 0;
        next = 0;
        if (*(v11 + 32) != v5)
          goto LABEL_14;
      }
      prev = v5->prev;
      v14 = 1;
      {
LABEL_15:
      }
LABEL_19:
      dds3DeleteBasic(basic);
      --*(v11 + 16);
      if (v12)
        *(v11 + 24) = next;
      if (v14)
        *(v11 + 32) = prev;
    }
  }
}

// 0x14f8580
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic) {
  dds3Basic_t_o **workdata;
  dds3Basic_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)[2].flag) < typeHierarchyDepth
    || *(v4[1].poseset + typeHierarchyDepth - 1) != dds3SceneBasic_t)
  {
    sub_8FC2C0(v4->poseset, dds3SceneBasic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[5];
}

// 0x14f8790
dds3Basic_t *dds3GetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic) {
  dds3Basic_t_o **workdata;
  dds3Basic_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = pSceneBasic->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)[2].flag) < typeHierarchyDepth
    || *(v4[1].poseset + typeHierarchyDepth - 1) != dds3SceneBasic_t)
  {
    sub_8FC2C0(v4->poseset, dds3SceneBasic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[6];
}

// 0x14f9790
s32 dds3GetMapNo(dds3Basic_t **scene) {
  s32 *workdata;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  if (!*scene)
    return -1;
  workdata = (*scene)->workdata;
  v4 = *workdata;
  if (*(*workdata + 288LL) < typeHierarchyDepth
    || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3SceneBasic_t)
  {
    sub_8FC2C0(*(v4 + 64), dds3SceneBasic_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[4];
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
  dds3SceneBasic_ScriptProcName = "";
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
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 i;
  Il2CppClass *v11;
  dds3Basic_t_o *next;
  u64 v16[3];

  if (!*scene || !*target)
    return 0;
  workdata = (*scene)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v16);
      if ((v16[0] & 1) != 0)
        v8 = v16[2];
      else
        v8 = v16 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  for (i = 0; ; ++i)
  {
    v11 = workdata[2].klass;
    next = *(*(&v11->_1.byval_arg.data + i) + 24LL);
    if (next)
      break;
LABEL_18:
    if (i >= 0x11)
      return 0;
  }
  while (next != *target)
  {
    next = next->next;
    if (!next)
      goto LABEL_18;
  }
  return 1;
}

// 0x14f93d0
s32 dds3SceneBasicExistBasicFromType(dds3Basic_t **scene, s32 type, dds3Basic_t *target) {
  s32 result;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v11;
  dds3Basic_t_o *next;
  char *v14;
  s64 *v15;
  u64 v16[3];

  result = 0;
  if (target && *scene)
  {
    workdata = (*scene)->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v16);
      if ((v16[0] & 1) != 0)
        v14 = v16[2];
      else
        v14 = v16 + 1;
      v15 = sub_8C4940(v14);
    }
    v11 = workdata[2].klass;
    next = *(*(&v11->_1.byval_arg.data + type) + 24LL);
    if (next)
    {
      while (next != target)
      {
        next = next->next;
        if (!next)
          return 0;
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

// 0x14f7dd0
void dds3SceneBasicFreeScene(dds3Basic_t **pBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = (*pBasic)->workdata;
  fldFreeFile();
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  workdata[3].monitor = 0;
}

// 0x14f8880
dds3BasicArrayHandle_t *dds3SceneBasicGetList(dds3Basic_t **pBasic, u32 type) {
  u64 *v5;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v9;
  Il2CppClass *v12;
  char *v15;
  s64 *v16;
  dds3Basic_t_o *data;
  dds3BasicArrayHandle_t_o *hndl;
  u64 v19[3];

  data = 0;
  v5 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v5);
  hndl = v5;
  workdata = (*pBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v19);
    if ((v19[0] & 1) != 0)
      v15 = v19[2];
    else
      v15 = v19 + 1;
    v16 = sub_8C4940(v15);
  }
  v9 = workdata[2].klass;
  if (!*(*(&v9->_1.byval_arg.data + type) + 16LL))
    return 0;
  hndl = dds3GetBasicArrayHandle(0);
  v12 = workdata[2].klass;
  data = *(*(&v12->_1.byval_arg.data + type) + 24LL);
  do
  {
    dds3AddBasicArray(&hndl, 1);
    dds3SetBasicArray(&hndl, &data);
    data = data->next;
  }
  while (data);
  return hndl;
}

// 0x14f8c60
s32 dds3SceneBasicLoadScriptFile(dds3Basic_t **scene, char *scrfile, char *akey) {
  u64 *v7;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  System_String_o *v15;
  System_Byte_array *v16;
  System_Byte_array *v18[3];
  System_Byte_array *aTopPtr;

  v7 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v7);
  aTopPtr = 0;
  workdata = (*scene)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v18);
      if ((v18[0] & 1) != 0)
        v11 = v18[2];
      else
        v11 = v18 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  if (IsNullOrEmpty(scrfile))
    return 0;
  Write_2930400("script {0}\n", scrfile);
  if (workdata[4].klass)
  {
    dds3SceneBasicReleaseScriptFile(scene);
  }
  v15 = Concat_5224608(scrfile, ".bytes");
  sdfDevLoadFileUnity_25061072(v15, &aTopPtr, 0, akey);
  v16 = aTopPtr;
  if (!aTopPtr)
    return 0;
  workdata[4].klass = v7;
  workdata[4].monitor = v16;
  return 1;
}

// 0x14f8e40
s32 dds3SceneBasicLoadScriptFile_FromMem(dds3Basic_t **scene, void *mem) {
  Il2CppObject *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v3 = mem;
  workdata = (*scene)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  if (v3 && workdata[4].klass)
  {
    dds3SceneBasicReleaseScriptFile(scene, mem);
  }
  return 0;
}

// 0x14f8a80
void dds3SceneBasicMakeScene(dds3Basic_t **pBasic, char *file, char *akey) {
  Il2CppObject *workdata;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  Il2CppClass *v13;
  s64 v14;
  char *v15;
  s64 *v16;
  u64 v17[2];
  char *v18;

  workdata = (*pBasic)->workdata;
  v8 = fldLoadFile(file, akey);
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v17);
      if ((v17[0] & 1) != 0)
        v11 = v18;
      else
        v11 = v17 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  if (v8)
  {
    v13 = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < v14 || v13->_2.typeHierarchy[v14 - 1] != sdfMemHandle_t)
    {
      sub_8FC2C0(v13->_1.element_class, sdfMemHandle_t, v17);
      if ((v17[0] & 1) != 0)
        v15 = v18;
      else
        v15 = v17 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  workdata[3].monitor = v8;
}

// 0x14f8c50
void dds3SceneBasicMakeScene_FromMemory(dds3Basic_t **pBasic, s32 field, s32 area, void *pF1, void *pF2, void *pTB, void *pBF) {
  ;
}

// 0x14f7ee0
void dds3SceneBasicReleaseScriptFile(dds3Basic_t **scene) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = (*scene)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (workdata[4].monitor)
    workdata[4].monitor = 0;
  workdata[4].klass = 0;
  workdata[4].monitor = 0;
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
        goto LABEL_10;
LABEL_8:
LABEL_10:
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
          goto LABEL_8;
      }
    }
  }
  return result;
}

// 0x14f9890
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name) {
  dds3Basic_t_o *next;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v11;
  System_String_o *v13;
  Il2CppClass *v14;
  System_String_o *v16;
  char *v18;
  s64 *v19;
  u64 v20[3];

  next = 0;
  if (scene && name)
  {
    workdata = scene->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v20);
      if ((v20[0] & 1) != 0)
        v18 = v20[2];
      else
        v18 = v20 + 1;
      v19 = sub_8C4940(v18);
    }
    v11 = workdata[2].klass;
    next = *(*(&v11->_1.byval_arg.data + type) + 24LL);
    if (next)
    {
      while (1)
      {
        v13 = next->name;
        if (!IsNullOrEmpty(v13) && Equals_5234480(v13, name))
          break;
        next = next->next;
        if (!next)
          goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      v14 = workdata[2].klass;
      for (next = *(*(&v14->_1.byval_arg.data + type) + 24LL); next; next = next->next)
      {
        v16 = next->name;
        if (!IsNullOrEmpty(v16) && Contains(v16, name, 0))
          break;
      }
    }
  }
  return next;
}

// 0x14f9a60
dds3Basic_t *dds3SceneBasicSearchNameAndType_1(dds3Basic_t *scene, u32 type, char *name) {
  dds3Basic_t_o *i;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v11;
  System_String_o *v13;
  char *v15;
  s64 *v16;
  u64 v17[3];

  i = 0;
  if (scene && name)
  {
    workdata = scene->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v17);
      if ((v17[0] & 1) != 0)
        v15 = v17[2];
      else
        v15 = v17 + 1;
      v16 = sub_8C4940(v15);
    }
    v11 = workdata[2].klass;
    for (i = *(*(&v11->_1.byval_arg.data + type) + 24LL); i; i = i->next)
    {
      v13 = i->name;
      if (!IsNullOrEmpty(v13) && Equals_5234480(v13, name))
        break;
    }
  }
  return i;
}

// 0x14f9bd0
dds3Basic_t *dds3SceneBasicSearchNameAndType_2(dds3Basic_t *scene, u32 type, char *name) {
  dds3Basic_t_o *i;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v11;
  System_String_o *v13;
  char *v15;
  s64 *v16;
  u64 v17[3];

  i = 0;
  if (scene && name)
  {
    workdata = scene->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v17);
      if ((v17[0] & 1) != 0)
        v15 = v17[2];
      else
        v15 = v17 + 1;
      v16 = sub_8C4940(v15);
    }
    v11 = workdata[2].klass;
    for (i = *(*(&v11->_1.byval_arg.data + type) + 24LL); i; i = i->next)
    {
      v13 = i->name;
      if (!IsNullOrEmpty(v13) && Contains(v13, name, 0))
        break;
    }
  }
  return i;
}

// 0x14f8f70
dds3ProcessID_t *dds3SceneBasicStartScript(dds3Basic_t **scene, char *procname) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *monitor;
  s32 v9;
  s32 v11;
  Il2CppClass *v14;
  s64 *Interface;
  char *v16;
  s64 *v17;
  System_String_o *v19;
  Il2CppObject *v20;
  char *v21;
  s64 *v22;
  u64 v23[2];
  char *v24;

  workdata = (*scene)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v23);
    if ((v23[0] & 1) != 0)
      v21 = v24;
    else
      v21 = v23 + 1;
    v22 = sub_8C4940(v21);
  }
  monitor = workdata[4].monitor;
  if (!monitor)
  {
    Write("script data invalid!!\n", 0);
    return 0;
  }
  if (!procname)
  {
    v19 = "script null name {0}\n";
    v20 = 0;
    goto LABEL_39;
  }
  v9 = scrSearchProcedureName(monitor, procname);
  if (v9 < 0)
  {
    v19 = "script procname invalid [{0}]\n";
    v20 = procname;
LABEL_39:
    Write_2930400(v19, v20);
    return 0;
  }
  v11 = v9;
  if (dds3SearchProcessName(procname))
    return 0;
  dds3SceneBasic_ScriptProcName = procname;
  Interface = QueryInterface(monitor, byte);
  if (!Interface)
  {
    sub_8FC2C0(monitor->klass->_1.element_class, v14, v23);
    if ((v23[0] & 1) != 0)
      v16 = v24;
    else
      v16 = v23 + 1;
    v17 = sub_8C4940(v16);
  }
  return scrStartScript2(1002, Interface, v11);
}

// 0x14eab00
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v10;
  Il2CppClass *v12;
  dds3Basic_t_o *result;
  char *v15;
  s64 *v16;
  u64 v17[3];

  workdata = (*pBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v17);
    if ((v17[0] & 1) != 0)
      v15 = v17[2];
    else
      v15 = v17 + 1;
    v16 = sub_8C4940(v15);
  }
  v10 = workdata[2].klass;
  if (!*(*(&v10->_1.byval_arg.data + type) + 16LL))
    return 0;
  v12 = workdata[2].klass;
  result = *(*(&v12->_1.byval_arg.data + type) + 24LL);
  do
  {
    if (result->serialID == serialID)
      break;
    result = result->next;
  }
  while (result);
  return result;
}

// 0x14f8450
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic) {
  dds3Basic_t_o **v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3Basic_t_o *result;
  u64 v11[3];

  v3 = pCameraBasic;
  workdata = (*pSceneBasic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  result = dds3GetActiveCameraSceneBasic(pSceneBasic, pCameraBasic);
  workdata[2].monitor = *v3;
  return result;
}

// 0x14f8670
dds3Basic_t *dds3SetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic, dds3Basic_t *pUnitBasic) {
  dds3Basic_t_o *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3Basic_t_o *result;
  u64 v11[3];

  v3 = pUnitBasic;
  workdata = pSceneBasic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  result = dds3GetActiveUnitSceneBasic(pSceneBasic, pUnitBasic);
  workdata[3].klass = v3;
  return result;
}

// 0x14f9690
void dds3SetMapNo(dds3Basic_t **scene, s32 mapno) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  if (*scene)
  {
    workdata = (*scene)->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
    LODWORD(workdata[1].klass) = mapno;
  }
}

// 0x14f8350
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*basic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
    LODWORD(workdata[5].klass) = visible;
  }
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
  Il2CppObject *workdata;
  dds3SceneBasic_t_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9;
  Il2CppClass *v10;
  Il2CppClass *v12;
  dds3Basic_t_o **v14;
  dds3Basic_t_o *v17;
  u64 v18[3];

  v17 = basic;
  workdata = basic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
    v9 = 0;
    v10 = workdata[2].klass;
    if (!LODWORD(v10->_1.namespaze))
    {
LABEL_14:
    }
    while (1)
    {
      if (*(*(&v10->_1.byval_arg.data + v9) + 24LL))
      {
        v12 = workdata[2].klass;
        v14 = (*(&v12->_1.byval_arg.data + v9) + 24LL);
        dds3DeleteSceneBasicData(v14, v4);
      }
      else if (++v9 == 18)
      {
        dds3SceneBasicFreeScene(&v17, v4);
        dds3SceneBasicReleaseScriptFile(&v17);
        return 0;
      }
      v10 = workdata[2].klass;
      if (v9 >= LODWORD(v10->_1.namespaze))
        goto LABEL_14;
    }
  }
  return 0;
}

// 0x14f81a0
s32 scenedrawprocuder(dds3Basic_t *basic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 result;
  Il2CppClass *v9;
  Il2CppClass *v11;
  Il2CppObject *v13;
  void *monitor;
  Il2CppObject *v15;
  Il2CppObject *v16;
  u64 v17[3];

  workdata = basic->workdata;
  if (!workdata)
    return 0;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v17);
    if ((v17[0] & 1) != 0)
      v6 = v17[2];
    else
      v6 = v17 + 1;
    v7 = sub_8C4940(v6);
  }
  if (!LODWORD(workdata[5].klass))
    return 1;
  v9 = workdata[2].klass;
  if (!*(v9->_1.this_arg.data + 4))
    return 1;
  v11 = workdata[2].klass;
  v13 = *(v11->_1.this_arg.data + 3);
  monitor = v13[2].monitor;
  if (!monitor)
    return 1;
  if (!*(monitor + 5))
    return 1;
  v15 = v13[4].monitor;
  int___Invoke(*(monitor + 5), v13);
  if (!v15)
    return 1;
  do
  {
    v16 = v15[4].monitor;
    int___Invoke(*(v15[2].monitor + 5), v15);
    result = 1;
    v15 = v16;
  }
  while (v16);
  return result;
}

// 0x14f7fe0
s32 scenemainprocuder(dds3Basic_t *basic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 i;
  Il2CppClass *v10;
  Il2CppClass *v12;
  Il2CppObject *v14;
  System_Func_object__int__o **monitor;
  Il2CppObject *v16;
  Il2CppObject *v17;
  u64 v18[3];

  workdata = basic->workdata;
  if (!workdata)
    return 0;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v18);
    if ((v18[0] & 1) != 0)
      v6 = v18[2];
    else
      v6 = v18 + 1;
    v7 = sub_8C4940(v6);
  }
  for (i = 0; i != 18; ++i)
  {
    v10 = workdata[2].klass;
    if (*(*(&v10->_1.byval_arg.data + i) + 16LL))
    {
      v12 = workdata[2].klass;
      v14 = *(*(&v12->_1.byval_arg.data + i) + 24LL);
      monitor = v14[2].monitor;
      if (monitor)
      {
        if (monitor[4])
        {
          v16 = v14[4].monitor;
          int___Invoke(monitor[4], v14);
          if (v16)
          {
            do
            {
              v17 = v16[4].monitor;
              int___Invoke(
                *(v16[2].monitor + 4),
                v16);
              v16 = v17;
            }
            while (v17);
          }
        }
      }
    }
  }
  return 1;
}
