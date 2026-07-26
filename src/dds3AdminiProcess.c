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
    dds3SearchProcessName(0);
    dds3GetProcessData(0);
    return 0;
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
    dds3GetProcessData(0);
    return 0;
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
    dds3GetProcessData(0);
    GetAdminiProcessData();
    return 0;
}

// 0x1520130
void *dds3AdminiNeoShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
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
    dds3GetProcessData(0);
    return 0;
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

  if (!dds3SearchProcessName(StringLiteral_14644))
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
    dds3StartProcess(StringLiteral_14644, 2u, 0, 1, v35, 0, v36, 0, data, 0);
  }
}
