#include "types.h"

typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;

static dds3Basic_t *dds3TheWorld;

dds3Basic_t *dds3AddBasic(u32 type);
s32 dds3AddBasicArray(dds3BasicArrayHandle_t **hndl, s32 bufcnt);
s32 dds3CallDrawProcuder(dds3Basic_t **basic);
s32 dds3CallMainProcuder(dds3Basic_t **basic);
void dds3DeleteAllBasicArray(dds3BasicArrayHandle_t **hndl);
void dds3DeleteBasic(dds3Basic_t **basic);
void dds3DeleteBasicArray(dds3BasicArrayHandle_t **hndl);
void dds3DeleteScene(dds3Basic_t **scene);
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetSearchNextBasicArray(dds3BasicArrayHandle_t **hArray, dds3Basic_t **pBasic);

// 0x180f3c0
s32 dds3AddBasicArray(dds3BasicArrayHandle_t **hndl, s32 bufcnt) {
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  s64 v12;
  s16 v13;
  s32 v14;
  s16 v15;
  u32 *monitor;
  u32 *v18;
  s32 v20;
  u32 *v21;
  u32 *v23;
  s64 lastindex;
  u32 *v27;
  u32 *v29;
  u64 v31[3];

  if (!bufcnt)
    return 1;
  if (!dds3TheWorld)
    return 0;
LABEL_7:
  else
  {
    workdata = dds3TheWorld->workdata;
    if (!workdata)
      goto LABEL_16;
  }
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v31);
    if ((v31[0] & 1) != 0)
      v10 = v31[2];
    else
      v10 = v31 + 1;
    v11 = sub_8C4940(v10);
  }
LABEL_16:
  if (HIWORD(workdata[4].klass) < bufcnt || !*hndl)
    return 0;
  v12 = SWORD1(workdata[4].klass);
  v13 = WORD1(workdata[4].klass);
  v14 = bufcnt - 1;
  v15 = v13;
  if (bufcnt - 1 >= 1)
  {
    v15 = WORD1(workdata[4].klass);
    do
    {
      monitor = workdata[3].monitor;
      v15 = *(*&monitor[2 * v15 + 8] + 24LL);
      --v14;
      WORD1(workdata[4].klass) = v15;
    }
    while (v14);
  }
  v18 = workdata[3].monitor;
  v20 = *(*&v18[2 * v15 + 8] + 24LL);
  WORD1(workdata[4].klass) = v20;
  if (v20 == 0xFFFF)
  {
    WORD2(workdata[4].klass) = -1;
  }
  else
  {
    v21 = workdata[3].monitor;
    *(*&v21[2 * v15 + 8] + 24LL) = -1;
    v23 = workdata[3].monitor;
    *(*&v23[2 * SWORD1(workdata[4].klass) + 8] + 26LL) = -1;
  }
  HIWORD(workdata[4].klass) -= bufcnt;
  lastindex = (*hndl)->lastindex;
  if (lastindex < 0)
  {
    (*hndl)->firstindex = v13;
  }
  else
  {
    v27 = workdata[3].monitor;
    *(*&v27[2 * lastindex + 8] + 24LL) = v13;
    v29 = workdata[3].monitor;
    *(*&v29[2 * v12 + 8] + 26LL) = (*hndl)->lastindex;
  }
  (*hndl)->lastindex = v15;
  (*hndl)->nowindex = v13;
  (*hndl)->count += bufcnt;
  return 1;
}

// 0x180f010
dds3Basic_t *dds3AddScene(void) {
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3Basic_t_o *result;
  u64 *monitor;
  u64 v11[3];

  if (!dds3TheWorld)
    return 0;
LABEL_6:
  else
  {
    workdata = dds3TheWorld->workdata;
    if (workdata)
    {
LABEL_9:
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v11);
        if ((v11[0] & 1) != 0)
          v7 = v11[2];
        else
          v7 = v11 + 1;
        v8 = sub_8C4940(v7);
      }
    }
  }
  result = dds3AddBasic(1u);
  if (result)
  {
    monitor = workdata[1].monitor;
    if (monitor)
    {
      monitor[9] = result;
      result->prev = workdata[1].monitor;
    }
    else
    {
      workdata[1].klass = result;
    }
    workdata[1].monitor = result;
  }
  return result;
}

// 0x180e6f0
dds3Basic_t *dds3AddWorld(s32 bufcnt) {
  dds3Basic_t_o *v4;
  dds3Basic_t_o *v5;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u32 *v11;
  u32 *monitor;
  u64 i;
  u64 *v14;
  u64 v18;
  u64 *v19;
  s16 v21;
  u64 *v22;
  s16 v24;
  u32 *v25;
  u32 *v27;
  u64 v30[3];

  v4 = 0;
  if ((bufcnt - 32) >> 5 <= 0x3FE && !dds3TheWorld)
  {
    v5 = dds3AddBasic(0);
    workdata = v5->workdata;
    v4 = v5;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v30);
        if ((v30[0] & 1) != 0)
          v9 = v30[2];
        else
          v9 = v30 + 1;
        v10 = sub_8C4940(v9);
      }
    }
    v11 = NewSpecific(dds3BasicArray_t, bufcnt);
    workdata[3].monitor = v11;
    monitor = v11;
    for (i = 0; ; ++i)
    {
      v14 = Allocate(dds3BasicArray_t);
      dds3BasicArray_t___ctor(v14);
      *&monitor[2 * i + 8] = v14;
      if (bufcnt - 1LL == i)
        break;
      monitor = workdata[3].monitor;
    }
    v18 = 0;
    LOWORD(workdata[4].klass) = bufcnt;
    do
    {
      v19 = workdata[3].monitor;
      v21 = v18 - 1;
      if (!v18)
        v21 = -1;
      *(v19[v18 + 4] + 26LL) = v21;
      v22 = workdata[3].monitor;
      if (bufcnt - 1 == v18)
        v24 = -1;
      else
        v24 = v18 + 1;
      *(v22[v18 + 4] + 24LL) = v24;
      v25 = workdata[3].monitor;
      v27 = &v25[2 * v18++];
      *(*(v27 + 4) + 16LL) = 0;
    }
    while (bufcnt != v18);
    WORD1(workdata[4].klass) = 0;
    WORD2(workdata[4].klass) = bufcnt - 1;
    HIWORD(workdata[4].klass) = bufcnt;
    dds3TheWorld = v4;
  }
  return v4;
}

// 0x1810490
s32 dds3CallbackBasicArray(dds3BasicArrayHandle_t **hndl, void *func) {
  dds3BasicArrayHandle_t_o *v5;
  Il2CppObject *BasicArray;
  s32 result;

  if (!func)
    return 1;
  v5 = *hndl;
  if (!*hndl)
    return 1;
LABEL_7:
  if (!v5->count)
    return 1;
  v5->nowindex = v5->firstindex;
  if ((*hndl)->nowindex < 0)
    return 1;
  while (1)
  {
    BasicArray = dds3GetBasicArray(hndl, func);
    result = int___Invoke(func, BasicArray);
    if (!result)
      break;
    else if (!dds3SetNextBasicArray(hndl))
    {
      return 1;
    }
  }
  return result;
}

// 0x180f700
void dds3DeleteAllBasicArray(dds3BasicArrayHandle_t **hndl) {
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 i;
  u32 *monitor;
  u64 *v13;
  s64 v15;
  u32 *v16;
  u32 *v18;
  u64 v20[3];

  if (*hndl && (*hndl)->count)
  {
    else
    {
      if (!dds3TheWorld)
        return;
    }
    workdata = dds3TheWorld->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v20);
        if ((v20[0] & 1) != 0)
          v8 = v20[2];
        else
          v8 = v20 + 1;
        v9 = sub_8C4940(v8);
      }
    }
    for (i = (*hndl)->firstindex; (i & 0x80000000) == 0; i = *(v13[i + 4] + 24LL))
    {
      monitor = workdata[3].monitor;
      *(*&monitor[2 * i + 8] + 16LL) = 0;
      v13 = workdata[3].monitor;
    }
    v15 = SWORD2(workdata[4].klass);
    if (v15 < 0)
    {
      WORD1(workdata[4].klass) = (*hndl)->firstindex;
    }
    else
    {
      v16 = workdata[3].monitor;
      *(*&v16[2 * v15 + 8] + 24LL) = (*hndl)->firstindex;
      v18 = workdata[3].monitor;
      *(*&v18[2 * (*hndl)->firstindex + 8] + 26LL) = WORD2(workdata[4].klass);
    }
    WORD2(workdata[4].klass) = (*hndl)->lastindex;
    HIWORD(workdata[4].klass) += (*hndl)->count;
    (*hndl)->firstindex = -1;
    (*hndl)->lastindex = -1;
    (*hndl)->nowindex = -1;
    (*hndl)->count = 0;
  }
}

// 0x180f9b0
void dds3DeleteBasicArray(dds3BasicArrayHandle_t **hndl) {
  dds3BasicArrayHandle_t_o *v3;
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 *monitor;
  u32 *v11;
  s64 v13;
  s64 v14;
  u32 *v15;
  u32 *v17;
  s16 *p_lastindex;
  u32 *v20;
  u32 *v22;
  s64 v24;
  u32 *v25;
  u32 *v27;
  char *v29;
  s64 *v30;
  u64 v31[3];

  v3 = *hndl;
  if (*hndl && v3->count && (v3->nowindex & 0x80000000) == 0)
  {
    if (dds3TheWorld)
    {
      workdata = dds3TheWorld->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v31);
        if ((v31[0] & 1) != 0)
          v29 = v31[2];
        else
          v29 = v31 + 1;
        v30 = sub_8C4940(v29);
      }
      monitor = workdata[3].monitor;
      *(*&monitor[2 * (*hndl)->nowindex + 8] + 16LL) = 0;
      v11 = workdata[3].monitor;
      v13 = *(*&v11[2 * (*hndl)->nowindex + 8] + 26LL);
      v14 = *(*&v11[2 * (*hndl)->nowindex + 8] + 24LL);
      if ((v13 & 0x80000000) != 0)
      {
        (*hndl)->firstindex = v14;
        if ((v14 & 0x80000000) == 0)
        {
LABEL_23:
          v17 = workdata[3].monitor;
          p_lastindex = (*&v17[2 * v14 + 8] + 26LL);
          goto LABEL_28;
        }
      }
      else
      {
        v15 = workdata[3].monitor;
        *(*&v15[2 * v13 + 8] + 24LL) = v14;
        if ((v14 & 0x80000000) == 0)
          goto LABEL_23;
      }
      p_lastindex = &(*hndl)->lastindex;
LABEL_28:
      *p_lastindex = v13;
      v20 = workdata[3].monitor;
      *(*&v20[2 * (*hndl)->nowindex + 8] + 26LL) = -1;
      v22 = workdata[3].monitor;
      *(*&v22[2 * (*hndl)->nowindex + 8] + 24LL) = -1;
      v24 = SWORD2(workdata[4].klass);
      if (v24 < 0)
      {
        WORD1(workdata[4].klass) = (*hndl)->nowindex;
      }
      else
      {
        v25 = workdata[3].monitor;
        *(*&v25[2 * v24 + 8] + 24LL) = (*hndl)->nowindex;
        v27 = workdata[3].monitor;
        *(*&v27[2 * (*hndl)->nowindex + 8] + 26LL) = WORD2(workdata[4].klass);
      }
      WORD2(workdata[4].klass) = (*hndl)->nowindex;
      ++HIWORD(workdata[4].klass);
      --(*hndl)->count;
      (*hndl)->nowindex = v14;
    }
  }
}

// 0x180e0f0
void dds3DeleteScene(dds3Basic_t **scene) {
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3Basic_t_o *v10;
  u64 v11[3];

  if (*scene)
  {
    else
    {
      if (!dds3TheWorld)
        return;
    }
    else
    {
      workdata = dds3TheWorld->workdata;
      if (!workdata)
        goto LABEL_16;
    }
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
LABEL_16:
    v10 = *scene;
    if (workdata[1].klass == *scene)
    {
      workdata[1].klass = v10->next;
      v10 = *scene;
      if (workdata[1].monitor != *scene)
      {
LABEL_18:
        if (workdata[2].klass != v10)
          goto LABEL_19;
        goto LABEL_27;
      }
    }
    else if (workdata[1].monitor != v10)
    {
      goto LABEL_18;
    }
    workdata[1].monitor = v10->prev;
    v10 = *scene;
    if (workdata[2].klass != *scene)
    {
LABEL_19:
      if (workdata[2].monitor != v10)
        goto LABEL_20;
LABEL_28:
      workdata[2].monitor = 0;
LABEL_20:
      dds3DeleteBasic(scene);
      return;
    }
LABEL_27:
    workdata[2].klass = 0;
    if (workdata[2].monitor != *scene)
      goto LABEL_20;
    goto LABEL_28;
  }
}

// 0x180ea10
void dds3DeleteWorld(void) {
  if (dds3TheWorld)
  {
    dds3DeleteBasic(&dds3TheWorld);
    dds3TheWorld = 0;
  }
}

// 0x180e300
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl) {
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3BasicArrayHandle_t_o *prev;
  u64 *p_next;
  struct dds3BasicArrayHandle_t_o *v12;
  struct dds3BasicArrayHandle_t_o *next;
  u64 v14[3];

  if (*hndl)
  {
    else
    {
      if (!dds3TheWorld)
        return;
    }
    else
    {
      workdata = dds3TheWorld->workdata;
      if (workdata)
      {
LABEL_10:
        klass = workdata->klass;
        if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
        {
          sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v14);
          if ((v14[0] & 1) != 0)
            v8 = v14[2];
          else
            v8 = v14 + 1;
          v9 = sub_8C4940(v8);
        }
      }
    }
    dds3DeleteAllBasicArray(hndl);
    prev = (*hndl)->prev;
    if (prev)
      p_next = &prev->next;
    else
      p_next = &workdata[4].monitor;
    *p_next = (*hndl)->next;
    next = (*hndl)->next;
    v12 = (*hndl)->prev;
    if (next)
      next->prev = v12;
    else
      workdata[5].klass = v12;
  }
}

// 0x180ec20
dds3Basic_t *dds3GetActiveScene(void) {
  struct dds3Basic_t_o *dds3TheWorld;
  dds3Basic_t_o **workdata;
  dds3Basic_t_o *v5;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  if (!dds3TheWorld)
    return 0;
LABEL_6:
  workdata = dds3TheWorld->workdata;
  v5 = *workdata;
  if (LOBYTE((*workdata)[2].flag) < typeHierarchyDepth
    || *(v5[1].poseset + typeHierarchyDepth - 1) != dds3WorldBasic_t)
  {
    sub_8FC2C0(v5->poseset, dds3WorldBasic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  return workdata[4];
}

// 0x1810010
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 *monitor;
  s64 nowindex;
  char *v11;
  s64 *v12;
  u64 v13[3];

  if (!(*hndl)->count)
    return 0;
  if ((*hndl)->nowindex < 0)
    return 0;
  workdata = dds3TheWorld->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  monitor = workdata[3].monitor;
  nowindex = (*hndl)->nowindex;
  return *(*&monitor[2 * nowindex + 8] + 16LL);
}

// 0x180ff00
s32 dds3GetBasicArrayCount(dds3BasicArrayHandle_t **hndl) {
  if (*hndl)
    return (*hndl)->count;
  else
    return 0;
}

// 0x180f1c0
dds3BasicArrayHandle_t *dds3GetBasicArrayHandle(s32 bufcnt) {
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *v8;
  Il2CppClass *v11;
  char *v14;
  s64 *v15;
  dds3BasicArrayHandle_t_o *v16;
  u64 v17[3];

  v16 = 0;
  else
  {
    if (dds3TheWorld)
    {
LABEL_6:
      workdata = dds3TheWorld->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v17);
        if ((v17[0] & 1) != 0)
          v14 = v17[2];
        else
          v14 = v17 + 1;
        v15 = sub_8C4940(v14);
      }
      if (HIWORD(workdata[4].klass) < bufcnt)
        return 0;
      v8 = Allocate(dds3BasicArrayHandle_t);
      dds3BasicArrayHandle_t___ctor(v8);
      v16 = v8;
      if (!v8)
        return v8;
      *(v8 + 4) = -1;
      *(v8 + 10) = -1;
      *(v8 + 19) = 0;
      *(v8 + 30) = 0;
      *(v8 + 22) = 0;
      v11 = workdata[5].klass;
      if (v11)
      {
        v11->_1.namespaze = v8;
        v8[4] = workdata[5].klass;
        workdata[5].klass = v8;
          goto LABEL_16;
      }
      else
      {
        workdata[4].monitor = v8;
        workdata[5].klass = v8;
        {
LABEL_16:
        }
      }
      dds3AddBasicArray(&v16, bufcnt);
      return v8;
    }
  }
  return 0;
}

// 0x180eec0
dds3Basic_t *dds3GetControlScene(void) {
  struct dds3Basic_t_o *dds3TheWorld;
  dds3Basic_t_o **workdata;
  dds3Basic_t_o *v5;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  if (!dds3TheWorld)
    return 0;
LABEL_6:
  workdata = dds3TheWorld->workdata;
  v5 = *workdata;
  if (LOBYTE((*workdata)[2].flag) < typeHierarchyDepth
    || *(v5[1].poseset + typeHierarchyDepth - 1) != dds3WorldBasic_t)
  {
    sub_8FC2C0(v5->poseset, dds3WorldBasic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  return workdata[5];
}

// 0x180fd70
s32 dds3SearchDeleteBasicArray(dds3BasicArrayHandle_t **hArray, dds3Basic_t **pBasic, u32 mode) {
  dds3BasicArrayHandle_t_o *v7;
  s32 v8;

  else
  {
    v7 = *hArray;
    if (!*hArray)
      return 0;
  }
  if (!v7->count)
    return 0;
  v7->nowindex = v7->firstindex;
  if (!mode)
  {
LABEL_21:
    if (dds3SetSearchNextBasicArray(hArray, pBasic, *&mode) == 1)
    {
      dds3DeleteBasicArray(hArray);
      return 1;
    }
    return 0;
  }
LABEL_10:
  v8 = 0;
    goto LABEL_14;
LABEL_11:
LABEL_14:
  while (dds3SetSearchNextBasicArray(hArray, pBasic, *&mode) == 1)
  {
    dds3DeleteBasicArray(hArray);
    v8 = 1;
      goto LABEL_11;
  }
  return v8;
}

// 0x180ead0
void dds3SetActiveScene(dds3Basic_t *scene) {
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  else
  {
    if (!dds3TheWorld)
      return;
  }
  workdata = dds3TheWorld->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  workdata[2].klass = scene;
}

// 0x1810310
s32 dds3SetBasicArray(dds3BasicArrayHandle_t **hndl, dds3Basic_t **data) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 *monitor;
  s64 nowindex;
  char *v13;
  s64 *v14;
  u64 v15[3];

  if (!(*hndl)->count || (*hndl)->nowindex < 0)
    return 0;
  workdata = dds3TheWorld->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = workdata[3].monitor;
  nowindex = (*hndl)->nowindex;
  *(*&monitor[2 * nowindex + 8] + 16LL) = *data;
  return 1;
}

// 0x180ed70
void dds3SetControlScene(dds3Basic_t **scene) {
  struct dds3Basic_t_o *dds3TheWorld;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  else
  {
    if (!dds3TheWorld)
      return;
  }
  workdata = dds3TheWorld->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  workdata[2].monitor = *scene;
}

// 0x180ff20
s32 dds3SetFirstBasicArray(dds3BasicArrayHandle_t **hndl) {
  (*hndl)->nowindex = (*hndl)->firstindex;
  return ((*hndl)->nowindex >> 15) ^ 1;
}

// 0x1810190
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl) {
  dds3BasicArrayHandle_t_o *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 *monitor;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v3 = *hndl;
  if ((*hndl)->nowindex < 0)
    return 0;
  workdata = dds3TheWorld->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  monitor = workdata[3].monitor;
  v3->nowindex = *(*&monitor[2 * (*hndl)->nowindex + 8] + 24LL);
  return ((*hndl)->nowindex >> 15) ^ 1;
}

// 0x180ff40
s32 dds3SetSearchNextBasicArray(dds3BasicArrayHandle_t **hArray, dds3Basic_t **pBasic) {
  dds3Basic_t_o *BasicArray;

  while (1)
  {
    BasicArray = dds3GetBasicArray(hArray, pBasic);
    if (!BasicArray)
      break;
    if (*pBasic == BasicArray)
    {
      LODWORD(BasicArray) = 1;
      return BasicArray;
    }
    else
    {
      LODWORD(BasicArray) = dds3SetNextBasicArray(hArray);
      if (!BasicArray)
        return BasicArray;
    }
  }
  return BasicArray;
}

// 0x180ded0
s32 worldconstructor(dds3Basic_t *basic) {
  u64 *v3;

  v3 = Allocate(dds3WorldBasic_t);
  dds3WorldBasic_t___ctor(v3);
  if (!v3)
    return 0;
  v3[8] = 0xFFFFFFFF0000LL;
  v3[6] = 0;
  v3[7] = 0;
  v3[4] = 0;
  v3[5] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v3[9] = 0;
  v3[10] = 0;
  basic->workdata = v3;
  return 1;
}

// 0x180df60
s32 worlddestructor(dds3Basic_t *basic) {
  Il2CppObject *workdata;
  dds3WorldBasic_t_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v9;
  dds3BasicArrayHandle_t_o **p_monitor;
  void *monitor;
  u64 v15[3];

  workdata = basic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v15);
      if ((v15[0] & 1) != 0)
        v7 = v15[2];
      else
        v7 = v15 + 1;
      v8 = sub_8C4940(v7);
    }
    v9 = workdata + 1;
    while (v9->klass)
    {
      {
        dds3DeleteScene(&workdata[1], v4);
        if (!v9->klass)
          goto LABEL_16;
      }
      dds3DeleteScene(&workdata[1]);
    }
LABEL_16:
    monitor = workdata[4].monitor;
    p_monitor = &workdata[4].monitor;
    if (monitor)
    {
      do
      {
        {
          dds3FreeBasicArrayHandle(p_monitor, v4);
          if (!*p_monitor)
            return 0;
        }
        dds3FreeBasicArrayHandle(p_monitor);
      }
      while (*p_monitor);
    }
  }
  return 0;
}

// 0x180e5d0
s32 worlddrawprocuder(dds3Basic_t *basic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Basic_t_o **v6;
  Il2CppClass *v7;
  char *v9;
  s64 *v10;
  u64 v11[3];

  workdata = basic->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  v7 = workdata[2].klass;
  v6 = &workdata[2];
  if (v7)
  {
    dds3CallDrawProcuder(v6);
  }
  return 1;
}

// 0x180e4b0
s32 worldmainprocuder(dds3Basic_t *basic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Basic_t_o **v6;
  Il2CppClass *v7;
  char *v9;
  s64 *v10;
  u64 v11[3];

  workdata = basic->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3WorldBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3WorldBasic_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  v7 = workdata[2].klass;
  v6 = &workdata[2];
  if (v7)
  {
    dds3CallMainProcuder(v6);
  }
  return 1;
}
