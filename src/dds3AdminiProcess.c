#include "types.h"

typedef struct dds3AdminiData_t dds3AdminiData_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

dds3AdminiData_t *GetAdminiProcessData(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);

// 0x151f230
dds3AdminiData_t *GetAdminiProcessData(void) {
  u64 *v1;
  dds3AdminiData_t_o *result;
  dds3AdminiData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3ProcessID_t_o *v8[3];
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  id = dds3SearchProcessName("Admini");
  result = dds3GetProcessData(&id);
  if (result)
  {
    klass = result->klass;
    if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3AdminiData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3AdminiData_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  return result;
}

// 0x151f380
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore) {
  dds3AdminiData_t_o *AdminiProcessData;
  u32 Stat;
  Il2CppObject *CallData;
  u32 v12;
  u32 v13;
  s32 v14;
  u32 v15;
  s32 v16;

  if (datasize < 0x101 || !data)
  {
    AdminiProcessData = GetAdminiProcessData(*&sequence);
    Stat = AdminiProcessData->Stat;
    AdminiProcessData->CallCount = 2;
    CallData = AdminiProcessData->CallData;
    v12 = Stat & 0xFFFEFFF6;
    v13 = Stat & 0xFFFEFFF6 | 1;
    AdminiProcessData->NextSequence = sequence;
    AdminiProcessData->Stat = v13;
    if (CallData)
    {
      AdminiProcessData->CallData = 0;
      AdminiProcessData->CallDataSize = 0;
    }
    if (data)
      v14 = datasize;
    else
      v14 = 0;
    AdminiProcessData->CallDataSize = v14;
    v15 = v13 & 0xFFFEFFF3;
    AdminiProcessData->CallData = data;
    v16 = v12 | 5;
    if (!restore)
      v16 = v15;
    AdminiProcessData->Stat = v16;
  }
}

// 0x151fb00
void *dds3AdminiEndCheck(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 monitor;
  Il2CppObject *v7;
  struct dds3AdminiList_t_array *dds3AdminiList;
  struct dds3AdminiList_t_array *v12;
  s64 monitor_low;
  s32 v15;
  u64 *v16;
  char *v18;
  s64 *v19;
  dds3ProcessID_t_o *v20;
  u64 v21[3];

  v20 = id;
  ProcessData = dds3GetProcessData(&v20);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3AdminiData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3AdminiData_t, v21);
    if ((v21[0] & 1) != 0)
      v18 = v21[2];
    else
      v18 = v21 + 1;
    v19 = sub_8C4940(v18);
  }
  monitor = ProcessData[1].monitor;
  v7 = ProcessData;
  if ((monitor & 0x80000000) == 0)
  {
    if (dds3AdminiList->m_Items[monitor]->end)
    {
      v12 = dds3AdminiList;
      monitor_low = SLODWORD(v7[1].monitor);
      v15 = _Invoke(v12->m_Items[monitor_low]->end);
      if (v15 < 0)
        return 0;
      HIDWORD(v7[4].klass) = v15 + 1;
      LODWORD(v7[1].monitor) = -1;
    }
  }
  v16 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v16,
    0,
    Method_dds3AdminiProcess_dds3AdminiStartSequence__);
  return v16;
}

// 0x151f4d0
void dds3AdminiExitSequence(void) {
  dds3AdminiData_t_o *AdminiProcessData;

  AdminiProcessData = GetAdminiProcessData();
  AdminiProcessData->Stat |= 2u;
}

// 0x151f4f0
s32 dds3AdminiGetActiveSequence(void) {
  return GetAdminiProcessData()->NowSequence;
}

// 0x151f510
s32 dds3AdminiGetNextSequence(void) {
  return GetAdminiProcessData()->NextSequence;
}

// 0x151f5a0
s32 dds3AdminiGetPrevHistoryFlag(void) {
  dds3AdminiData_t_o *AdminiProcessData;
  s32 HistoryPointer;
  s32 v3;
  struct System_Byte_array *FlagHistory;
  s32 v5;
  u32 v6;

  AdminiProcessData = GetAdminiProcessData();
  HistoryPointer = AdminiProcessData->HistoryPointer;
  v3 = HistoryPointer + 7;
  FlagHistory = AdminiProcessData->FlagHistory;
  v5 = HistoryPointer + 14;
  if (v3 >= 0)
    v5 = v3;
  v6 = v3 - (v5 & 0xFFFFFFF8);
  return FlagHistory->m_Items[v6];
}

// 0x151f530
s32 dds3AdminiGetPrevSequence(void) {
  dds3AdminiData_t_o *AdminiProcessData;
  s32 HistoryPointer;
  s32 v3;
  struct System_Int32_array *SequenceHistory;
  s32 v5;
  u32 v6;

  AdminiProcessData = GetAdminiProcessData();
  HistoryPointer = AdminiProcessData->HistoryPointer;
  v3 = HistoryPointer + 7;
  SequenceHistory = AdminiProcessData->SequenceHistory;
  v5 = HistoryPointer + 14;
  if (v3 >= 0)
    v5 = v3;
  v6 = v3 - (v5 & 0xFFFFFFF8);
  return SequenceHistory->m_Items[v6];
}

// 0x151fd30
void *dds3AdminiNeoProcess(dds3ProcessID_t *id) {
  Il2CppMethodPointer methodPointer;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 name;
  u32 klass;
  u32 *gc_desc;
  struct dds3AdminiList_t_array *dds3AdminiList;
  s64 klass_low;
  s32 return_type;
  s32 v18;
  u32 *parameters;
  s32 v20;
  signed s32 v21;
  s64 v22;
  const Il2CppRGCTXData *rgctx_data;
  u32 *v27;
  s32 v28;
  s32 v30;
  const void *genericMethod;
  s32 v32;
  dds3AdminiData_t_o *AdminiProcessData;
  u32 v34;
  Il2CppObject *CallData;
  s32 v36;
  u64 *v37;
  dds3ProcessID_t_o *v39;
  u64 v40[3];

  v39 = id;
  ProcessData = dds3GetProcessData(&v39);
  v4 = ProcessData;
  if ()
  {
    methodPointer = ProcessData->methodPointer;
    if (*(ProcessData->methodPointer + 288) < typeHierarchyDepth
      || *(*(methodPointer + 25) + 8 * typeHierarchyDepth - 8) != dds3AdminiData_t)
    {
      sub_8FC2C0(*(methodPointer + 8), dds3AdminiData_t, v40);
      if ((v40[0] & 1) != 0)
        v7 = v40[2];
      else
        v7 = v40 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  name = ProcessData->name;
  if ((name & 2) != 0)
    goto LABEL_29;
  klass = ProcessData->klass;
  if ((klass & 0x80000000) == 0)
  {
    gc_desc = ProcessData[2].klass->_1.gc_desc;
    if (*(*&gc_desc[2 * klass + 8] + 32LL))
    {
      klass_low = SLODWORD(v4->klass);
      ProcessData = _Invoke(
                      dds3AdminiList->m_Items[klass_low]->check);
      if ()
        LODWORD(v4->name) |= 2u;
    }
    name = v4->name;
    ++HIDWORD(v4->name);
    if ((name & 2) != 0)
    {
LABEL_29:
      if ((v4->klass & 0x80000000) == 0)
      {
        return_type = v4->return_type;
        v18 = return_type + 7;
        parameters = v4->parameters;
        v20 = return_type + 14;
        if (v18 >= 0)
          v20 = v18;
        v21 = v18 - (v20 & 0xFFFFFFF8);
        v22 = v21;
        if ((parameters[v21 + 8] & 0x80000000) == 0)
        {
          rgctx_data = v4->rgctx_data;
          if ((*(&rgctx_data[4].rgctxDataDummy + v21) & 1) != 0)
          {
            Write("restore sequence!!\n", 0);
            v27 = v4->parameters;
            v28 = LODWORD(v4->name) | 0x10001;
            LODWORD(v4->name) = v28;
            v30 = v27[v22 + 8];
            LODWORD(v4->name) = v28 & 0xFFFFFFFB;
            genericMethod = v4->genericMethod;
            *&v4->flags = 2;
            HIDWORD(v4->klass) = v30;
            if (genericMethod)
            {
              Log("vvvv======CallData null:0002", 0);
              v4->genericMethod = 0;
              v4->token = 0;
            }
          }
        }
        v32 = v4->name;
        if ((v32 & 1) == 0)
        {
          AdminiProcessData = GetAdminiProcessData();
          v34 = AdminiProcessData->Stat & 0xFFFEFFF6;
          AdminiProcessData->CallCount = 2;
          CallData = AdminiProcessData->CallData;
          v36 = v34 | 1;
          AdminiProcessData->NextSequence = 0;
          AdminiProcessData->Stat = v36;
          if (CallData)
          {
            AdminiProcessData->CallData = 0;
            AdminiProcessData->CallDataSize = 0;
          }
          AdminiProcessData->CallData = 0;
          AdminiProcessData->CallDataSize = 0;
          AdminiProcessData->Stat = v36 & 0xFFFEFFF3;
          v32 = v4->name;
        }
        LOBYTE(name) = v32 & 0xFD;
        LODWORD(v4->name) = v32 & 0xFFFFFFFD;
      }
    }
  }
  if ((name & 1) == 0 || (HIDWORD(v4->klass) & 0x80000000) != 0)
    return 0;
  v37 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v37,
    0,
    Method_dds3AdminiProcess_dds3AdminiEndCheck__);
  return v37;
}

// 0x1520130
void *dds3AdminiNeoShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u32 monitor;
  Il2CppObject *v7;
  struct dds3AdminiList_t_array *dds3AdminiList;
  struct dds3AdminiList_t_array *v12;
  s64 monitor_low;
  char *v16;
  s64 *v17;
  dds3ProcessID_t_o *v18;
  u64 v19[3];

  v18 = id;
  ProcessData = dds3GetProcessData(&v18);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3AdminiData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3AdminiData_t, v19);
    if ((v19[0] & 1) != 0)
      v16 = v19[2];
    else
      v16 = v19 + 1;
    v17 = sub_8C4940(v16);
  }
  monitor = ProcessData[1].monitor;
  v7 = ProcessData;
  if ((monitor & 0x80000000) == 0)
  {
    if (dds3AdminiList->m_Items[monitor]->end)
    {
      v12 = dds3AdminiList;
      monitor_low = SLODWORD(v7[1].monitor);
      _Invoke(v12->m_Items[monitor_low]->end);
    }
  }
  return 0;
}

// 0x151f430
void dds3AdminiOverwriteSequence(s32 sequence, u32 **data, s32 datasize) {
  s32 v6;
  u32 v7;
  s64 v8;
  s32 v9;
  s32 v10;
  dds3AdminiData_t_o *AdminiProcessData;

  v6 = sequence;
  if (datasize < 0x101 || !data)
  {
    *&sequence = GetAdminiProcessData(*&sequence);
    v7 = *(*&sequence + 16LL) & 0xFFFEFFF6;
    *(*&sequence + 68LL) = 2;
    v8 = *(*&sequence + 56LL);
    v9 = v7 | 1;
    *(*&sequence + 28LL) = v6;
    *(*&sequence + 16LL) = v9;
    if (v8)
    {
      *(*&sequence + 56LL) = 0;
      *(*&sequence + 64LL) = 0;
    }
    if (data)
      v10 = datasize;
    else
      v10 = 0;
    *(*&sequence + 56LL) = data;
    *(*&sequence + 16LL) = v9 & 0xFFFEFFF3;
    *(*&sequence + 64LL) = v10;
  }
  AdminiProcessData = GetAdminiProcessData(*&sequence);
  AdminiProcessData->Stat |= 8u;
}

// 0x151f610
void *dds3AdminiStartSequence(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v9;
  s32 monitor_high;
  s32 klass_high;
  bool v12;
  s32 v13;
  u64 *v14;
  u32 v15;
  Il2CppClass *v16;
  s64 klass_low;
  s32 v19;
  s32 v20;
  Il2CppObject *v21;
  s32 v22;
  s32 v23;
  u32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  u32 *monitor;
  Il2CppClass *v30;
  s64 v31;
  struct dds3AdminiList_t_array *dds3AdminiList;
  s64 monitor_low;
  struct dds3AdminiList_t_array *v38;
  s64 v39;
  u64 v42;
  s32 v43;
  u32 *v45;
  u64 *v47;
  Il2CppClass *v48;
  Il2CppObject *v49;
  u64 *v52;
  u32 v53;
  char v55[4];
  dds3ProcessID_t_o *ida;
  u64 v57[3];

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3AdminiData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3AdminiData_t, v57);
      if ((v57[0] & 1) != 0)
        v7 = v57[2];
      else
        v7 = v57 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = ProcessData[1].klass;
  if ((v9 & 1) == 0)
    goto LABEL_68;
  monitor_high = HIDWORD(ProcessData[1].monitor);
  if (monitor_high < 0)
    goto LABEL_68;
  klass_high = HIDWORD(ProcessData[4].klass);
  v12 = __OFSUB__(klass_high, 1);
  v13 = klass_high - 1;
  if (v13 < 0 != v12)
  {
    v15 = v9 & 0xFFFFFFFC;
    ProcessData[1].klass = (v9 & 0xFFFFFFFC);
    LODWORD(ProcessData[1].monitor) = monitor_high;
    HIDWORD(ProcessData[1].monitor) = -1;
    if ((v9 & 4) != 0)
    {
      v16 = ProcessData[3].klass;
      klass_low = SLODWORD(ProcessData[2].klass);
      *(&v16->_1.byval_arg.data + klass_low) |= 1u;
      v15 = ProcessData[1].klass & 0xFFFFFFFB;
      LODWORD(ProcessData[1].klass) = v15;
    }
    if ((v15 & 0x10000) != 0)
    {
      v21 = ProcessData + 2;
      v25 = ProcessData[2].klass;
      v26 = v25 + 7;
      v27 = v25 + 14;
      if (v26 >= 0)
        v27 = v26;
      v24 = v26 - (v27 & 0xFFFFFFF8);
      LODWORD(ProcessData[1].klass) = v15 & 0xFFFEFFFF;
      LODWORD(v21->klass) = v24;
      v19 = 1;
    }
    else
    {
      v19 = 0;
      if ((v15 & 8) != 0)
      {
        v21 = ProcessData + 2;
        v24 = ProcessData[2].klass;
        LODWORD(ProcessData[1].klass) = v15 & 0xFFFFFFF7;
      }
      else
      {
        v21 = ProcessData + 2;
        v20 = ProcessData[2].klass;
        v22 = v20 + 1;
        if (v20 + 1 >= 0)
          v23 = v20 + 1;
        else
          v23 = v20 + 8;
        v24 = v22 - (v23 & 0xFFFFFFF8);
        LODWORD(v21->klass) = v24;
      }
    }
    monitor = ProcessData[2].monitor;
    monitor[v24 + 8] = ProcessData[1].monitor;
    v30 = ProcessData[3].klass;
    v31 = SLODWORD(ProcessData[2].klass);
    *(&v30->_1.byval_arg.data + v31) = 0;
    monitor_low = SLODWORD(v4[1].monitor);
    if (dds3AdminiList->m_Items[monitor_low]->start)
    {
      v38 = dds3AdminiList;
      v39 = SLODWORD(v4[1].monitor);
      object__int___Invoke(v38->m_Items[v39]->start, v19, v4[3].monitor);
    }
    v42 = 0;
    do
    {
      Write("[", 0);
      if (v42 == LODWORD(v21->klass))
      {
        Write("*", 0);
      }
      v45 = v4[2].monitor;
      LODWORD(v57[0]) = v45[v42 + 8];
      v47 = sub_8D3950(s32, v57);
      v48 = v4[3].klass;
      v49 = v47;
      v55[0] = *(&v48->_1.byval_arg.data + v42);
      v52 = sub_8D3950(qword_3F088F8, v55);
      Write_2930752("{0:D}, 0x{1:X2}]", v49, v52, 0);
      ++v42;
      v43 = (v53 >> 9) & 1;
    }
    while (v42 != 8);
    Write("\n", 0);
LABEL_68:
    v14 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v14,
      0,
      Method_dds3AdminiProcess_dds3AdminiNeoProcess__);
    return v14;
  }
  v14 = 0;
  HIDWORD(ProcessData[4].klass) = v13;
  return v14;
}

// 0x1520310
void dds3InitAdmini(void) {
  u64 *data;
  u64 v3;
  u64 v5;
  u64 v7;
  u64 v9;
  u64 v11;
  u64 v13;
  u64 v15;
  u64 v17;
  u64 v19;
  u64 v21;
  u64 v23;
  u64 v25;
  u64 v27;
  u64 v29;
  u64 v31;
  u64 v33;
  u64 *v35;
  u64 *v36;

  if (!dds3SearchProcessName("Admini"))
  {
    data = Allocate(dds3AdminiData_t);
    dds3AdminiData_t___ctor(data);
    v3 = data[5];
    *(data + 8) = 0;
    data[2] = 0;
    data[3] = -1;
    *(v3 + 32) = -1;
    v5 = data[6];
    *(v5 + 32) = 0;
    v7 = data[5];
    *(v7 + 36) = -1;
    v9 = data[6];
    *(v9 + 33) = 0;
    v11 = data[5];
    *(v11 + 40) = -1;
    v13 = data[6];
    *(v13 + 34) = 0;
    v15 = data[5];
    *(v15 + 44) = -1;
    v17 = data[6];
    *(v17 + 35) = 0;
    v19 = data[5];
    *(v19 + 48) = -1;
    v21 = data[6];
    *(v21 + 36) = 0;
    v23 = data[5];
    *(v23 + 52) = -1;
    v25 = data[6];
    *(v25 + 37) = 0;
    v27 = data[5];
    *(v27 + 56) = -1;
    v29 = data[6];
    *(v29 + 38) = 0;
    v31 = data[5];
    *(v31 + 60) = -1;
    v33 = data[6];
    *(v33 + 39) = 0;
    data[7] = 0;
    *(data + 16) = 0;
    v35 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v35,
      0,
      Method_dds3AdminiProcess_dds3AdminiNeoProcess__);
    v36 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v36,
      0,
      Method_dds3AdminiProcess_dds3AdminiNeoShutdown__);
    dds3StartProcess("Admini", 2u, 0, 1, v35, 0, v36, 0, data, 0);
  }
}
