#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct scrCode_t scrCode_t;
typedef struct scrHeader_t scrHeader_t;
typedef struct scrLabelTable_t scrLabelTable_t;
typedef struct scrProcTable_t scrProcTable_t;
typedef struct scrProcessWork_s scrProcessWork_s;
typedef struct scrTypeTable_t scrTypeTable_t;

static s32 scrHandleCount;
static scrProcessWork_s *scrHandleFirst;
static scrProcessWork_s *scrHandleLast;
static scrProcessWork_s *scrHandle_t;
static s32 LoadAssetProcNo;

scrProcessWork_s *AddScript(scrHeader_t *header, scrTypeTable_t **typetable, scrProcTable_t **proctable, scrLabelTable_t **labeltable, scrCode_t **code, u8 **mesdata, u8 **stringdata, s32 startproc);
scrProcessWork_s *AddScript2(u8 **scrdata, s32 startproc);
scrProcessWork_s *AddScript3(char *filename, s32 startproc, char *akey);
char *GetEventFileNameToAssetName(char *filename);
void InitLoadPacket(void);
bool IsCloseWindow(s32 id);
void LinkScriptHandleList(scrProcessWork_s *h);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void Log(char *fmt, void **parray);
s32 SDF_ABORT1(char *a);
dds3ProcessID_t *StartScriptProcess(s32 priority, scrProcessWork_s *h);
void UnlinkScriptHandleList(scrProcessWork_s *h);
void WindowDispOff(bool sw);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessID(s32 id);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
s32 itfMesMngInitialize(void *presource, char **master_text, char *key);
void itfMesMngRelease(s32 id);
void scrReleaseScript(scrProcessWork_s *h);
s32 scrTraceCode(scrProcessWork_s *pwork);

// 0x1c6090
scrProcessWork_s *AddScript(scrHeader_t *header, scrTypeTable_t **typetable, scrProcTable_t **proctable, scrLabelTable_t **labeltable, scrCode_t **code, u8 **mesdata, u8 **stringdata, s32 startproc) {
  u64 *v17;
  Il2CppObject *v19;
  char *v20;
  s64 i;
  u64 v22;
  u64 v23;
  s32 v24;
  u64 j;
  u64 v30;
  u64 v32;
  u64 v34;
  il2cpp_array_size_t max_length;
  System_Array_o *v36;
  il2cpp_array_size_t v37;
  System_Array_o *v38;
  void *monitor;
  System_Array_o *v40;
  void *v41;
  System_Array_o *v42;
  void *v43;
  System_Array_o *v44;
  il2cpp_array_size_t v45;
  System_Array_o *v46;
  u64 LocalIntCount;
  System_Array_o *v48;
  u64 LocalFloatCount;
  System_Array_o *v50;
  Il2CppObject *v51;
  System_Array_o *v54;
  System_Array_o *v55;
  scrHeader_t_o *src;
  System_Array_o *v57;

  v17 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v17);
  if (startproc < 0)
  if (typetable->m_Items[0].ItemCount <= startproc)
  {
    SDF_ABORT1(StringLiteral_8865);
    return 0;
  }
  else
  {
    v19 = &proctable->obj + startproc;
    v54 = labeltable;
    v55 = code;
    src = header;
    v20 = &v19[2];
    v57 = mesdata;
    for (i = 32; ; ++i)
    {
      v22 = v17[2];
      v23 = i - 32;
      v24 = *(*v20 + i);
      *(v22 + i) = v24;
      if (!v24)
        break;
      *(v17 + 28) = v19[2].monitor;
    }
    *(v17 + 29) = 0;
    for (j = 0; j != 28; ++j)
    {
      v30 = v17[15];
      *(v30 + j + 32) = 0;
      v32 = v17[16];
      v34 = v32 + 4 * j;
      *(v34 + 32) = 0;
    }
    memmove(v17 + 3, src, 0x28u);
    max_length = typetable->max_length;
    v36 = NewSpecific(scrTypeTable_t, max_length);
    v17[8] = v36;
    Copy_3886320(typetable, v36, max_length);
    v37 = proctable->max_length;
    v38 = NewSpecific(scrProcTable_t, v37);
    v17[9] = v38;
    Copy_3886320(proctable, v38, v37);
    if (v54)
    {
      monitor = v54[1].monitor;
      v40 = NewSpecific(scrLabelTable_t, monitor);
      v17[10] = v40;
      Copy_3886320(v54, v40, monitor);
    }
    v41 = v55[1].monitor;
    v42 = NewSpecific(scrCode_t, v41);
    v17[11] = v42;
    Copy_3886320(v55, v42, v41);
    if (v57)
    {
      v43 = v57[1].monitor;
      v44 = NewSpecific(byte, v43);
      v17[12] = v44;
      BlockCopy(v57, 0, v44, 0, v43);
    }
    v45 = stringdata->max_length;
    v46 = NewSpecific(byte, v45);
    v17[13] = v46;
    BlockCopy(stringdata, 0, v46, 0, v45);
    *(v17 + 34) = startproc;
    *(v17 + 148) = 0;
    *(v17 + 140) = 0xFFFFFFFFLL;
    *(v17 + 39) = 0;
    v17[24] = 0;
    v17[25] = 0;
    v17[22] = 0;
    v17[23] = 0;
    v17[20] = 0;
    v17[21] = 0;
    LocalIntCount = src->LocalIntCount;
    if ((LocalIntCount - 1) <= 0xFEu)
    {
      v48 = NewSpecific(uint, LocalIntCount);
      v17[21] = v48;
      Clear(v48, 0, src->LocalIntCount, 0);
    }
    LocalFloatCount = src->LocalFloatCount;
    if ((LocalFloatCount - 1) <= 0x7Eu)
    {
      v50 = NewSpecific(f32, LocalFloatCount);
      v17[22] = v50;
      Clear(v50, 0, src->LocalFloatCount, 0);
    }
    if (v57)
    {
      v51 = v17[12];
      *(v17 + 35) = itfMesMngInitialize(v51, 0, 0);
    }
    LinkScriptHandleList(v17, LocalFloatCount);
  }
  return v17;
}

// 0x1c6540
scrProcessWork_s *AddScript2(u8 **scrdata, s32 startproc) {
    AddScript(0, 0, 0, 0, 0, 0, 0, 0);
    SDF_ABORT1(0);
    return 0;
}

// 0x1c6d10
scrProcessWork_s *AddScript3(char *filename, s32 startproc, char *akey) {
  u64 *v7;
  u64 *v8;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v12;
  System_Byte_array *FileByte;

  v7 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v7);
  v8 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v8);
  if (!GetEventFileNameToAssetName(filename))
    return v8;
  asset_bc = get_asset_bc();
  v12 = Concat_5224608(filename, StringLiteral_4739);
  FileByte = LoadFileByte(asset_bc, akey, v12);
  return AddScript2(FileByte, startproc);
}

// 0x8ca70
void *ByteArrayToStruct_object_(u8 **buf, s32 *pos) {
  s64 v7;
  s32 v8;
  intptr_t v9;
  Il2CppObject *v10;

  v7 = (*method->rgctx_data->rgctxDataDummy)();
  {
  }
  v8 = (*method->rgctx_data[1].rgctxDataDummy)(v7);
  v9 = AllocHGlobal_1551568(v8);
  Copy(buf, *pos, v9, v8, 0);
  v10 = (*method->rgctx_data[2].rgctxDataDummy)(v9);
  FreeHGlobal(v9);
  *pos += v8;
  return v10;
}

// 0x1c8bf0
char *GetDLCTag(s32 eventno) {
  _BOOL4 v3;
  _BOOL4 v4;
  s64 *v5;

  if ((eventno - 714) > 0x10 || (v3 = 1, ((1 << (eventno + 54)) & 0x1C203) == 0))
    v3 = eventno == 731;
  v4 = evtBitCheck(3712);
  v5 = &StringLiteral_4735;
  if (!v3 || !v4)
    v5 = &StringLiteral_416;
  return *v5;
}

// 0x1c6e70
char *GetEventFileNameToAssetName(char *filename) {
  s32 Length;
  s32 IndexOf;
  System_String_o *v5;
  s32 v6;

  Replace_5267216(filename, StringLiteral_14, StringLiteral_74);
  Length = get_Length(filename);
  IndexOf = LastIndexOf(filename, 0x2Fu, 0);
  if (IndexOf == -1)
    return 0;
  v5 = Substring_5248048(filename, IndexOf + 1, Length + ~IndexOf);
  v6 = LastIndexOf(v5, 0x2Eu, 0);
  if (v6 != -1)
    return Substring_5248048(v5, 0, v6);
  return v5;
}

// 0x1c8cb0
dds3ProcessID_t *IndexToProcess(s32 id) {
  return dds3SearchProcessID(id);
}

// 0x1c8b30
bool IsDLC(void) {
  return evtBitCheck(3712);
}

// 0x1c8b40
bool IsDLCField(s32 field) {
  bool v3;

  v3 = field <= 0x29 && ((1LL << field) & 0x20000808002LL) != 0 || field == 43;
  return v3 & evtBitCheck(3712);
}

// 0x1c5df0
void LinkScriptHandleList(scrProcessWork_s *h) {
  ScrScriptProcess_c *v3;
  s32 v4;
  struct ScrScriptProcess_StaticFields *static_fields;

  {
    else
    {
      static_fields = ScrScriptProcess->static_fields;
      if (static_fields->scrHandleLast)
    }
    static_fields->scrHandleFirst = h;
    scrHandleLast = h;
    h->prev = 0;
    h->next = 0;
    if ((v3->_2.bitflags2 & 2) != 0)
  }
  v4 = 0;
  static_fields = ScrScriptProcess->static_fields;
  if (!static_fields->scrHandleLast)
  h->prev = static_fields->scrHandleLast;
  scrHandleLast->next = h;
  h->next = 0;
  scrHandleLast = h;
  ++scrHandleCount;
}

// 0x1c8d20
s32 ProcessToIndex(dds3ProcessID_t *id) {
  return id->id;
}

// 0x1c6f50
dds3ProcessID_t *StartScriptProcess(s32 priority, scrProcessWork_s *h) {
  u64 *v5;
  System_Text_Encoding_o *ASCII;
  struct scrProcTable_t_array *ProcTable;
  s64 StartProc;
  System_String_o *v10;
  System_String_o *v11;
  u64 *v12;
  u64 *v13;
  dds3ProcessID_t_o *result;

  v5 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v5);
  ASCII = get_ASCII();
  ProcTable = h->ProcTable;
  StartProc = h->StartProc;
  v10 = (ASCII->klass[1]._1.byval_arg.data)(
          ASCII,
          ProcTable->m_Items[StartProc].Name,
          *&ASCII->klass[1]._1.byval_arg.bits);
  v11 = Replace_5267216(v10, StringLiteral_859, StringLiteral_416);
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_ScrScriptProcess_scrScriptProcess__);
  v13 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v13,
    0,
    Method_ScrScriptProcess_scrScriptShutdown__);
  result = dds3StartProcess(v11, priority, 1, 1, v12, 0, v13, 0, h, 0);
  h->ProcessID = result;
  return result;
}

// 0x1c5f20
void UnlinkScriptHandleList(scrProcessWork_s *h) {
}

// 0x1c7c10
void scrAllReleaseScript(void) {
    scrReleaseScript(0);
    dds3KillProcess(0, 0);
}

// 0x1c84a0
void *scrGetUserData(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    return 0;
}

// 0x1c70e0
void scrInitGlobalWork(void) {
  s64 i;
  u64 v6;
  struct System_Int32_array *IntVariable;
  struct System_Single_array *FloatVariable;

  InitLoadPacket();
  for (i = 8; i != 264; ++i)
  {
    v6 = i - 8;
    IntVariable = DDS3_GBWK->IntVariable;
    *(&IntVariable->obj.klass + i) = 0;
    FloatVariable = DDS3_GBWK->FloatVariable;
    *(&FloatVariable->obj.klass + i) = 0;
  }
}

// 0x1c7930
scrProcessWork_s *scrRegistScript1(scrHeader_t *header, scrTypeTable_t **typetable, scrProcTable_t **proctable, scrLabelTable_t **labeltable, scrCode_t **code, u8 **mesdata, u8 **stringdata) {
  u64 *v15;
  s64 v17;
  struct System_Char_array *MagicCode;
  s64 v19;
  scrHeader_t_o v22;
  scrHeader_t_o v23;

  v15 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v15);
  *&v23.FileType = *&header->FileType;
  v17 = *&header->Resrve3;
  MagicCode = header->MagicCode;
  v19 = *&header->ExpandSize;
  *&v23.LocalIntCount = *&header->LocalIntCount;
  *&v23.Resrve3 = v17;
  v23.MagicCode = MagicCode;
  *&v23.ExpandSize = v19;
  v22 = v23;
  return AddScript(&v22, typetable, proctable, labeltable, code, mesdata, stringdata, 0);
}

// 0x1c7520
scrProcessWork_s *scrRegistScript2(u8 **scrdata) {
  u64 *v3;

  v3 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v3);
  return AddScript2(scrdata, 0);
}

// 0x1c73d0
scrProcessWork_s *scrRegistScript3(char *filename) {
  u64 *v3;

  v3 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v3);
  return AddScript3(filename, 0, StringLiteral_8867);
}

// 0x1c7a40
void scrReleaseScript(scrProcessWork_s *h) {
  System_Text_Encoding_o *ASCII;
  struct scrProcTable_t_array *ProcTable;
  s64 StartProc;
  System_String_o *v7;
  Il2CppObject *v8;
  System_String_o *v9;
  System_Object_array *v11;
  s32 MesHandle;
  bool IsCloseWindow;

  ASCII = get_ASCII();
  ProcTable = h->ProcTable;
  StartProc = h->StartProc;
  v7 = (ASCII->klass[1]._1.byval_arg.data)(
         ASCII,
         ProcTable->m_Items[StartProc].Name,
         *&ASCII->klass[1]._1.byval_arg.bits);
  v8 = Replace_5267216(v7, StringLiteral_859, StringLiteral_416);
  v9 = Format(StringLiteral_8868, v8, 0);
  v11 = Empty_string_();
  Log(v9, v11, 0);
  if (h->LocalInt)
    h->LocalInt = 0;
  if (h->LocalFloat)
    h->LocalFloat = 0;
  MesHandle = h->MesHandle;
  if ((MesHandle & 0x80000000) == 0)
  {
    IsCloseWindow = IsCloseWindow(MesHandle);
    itfMesMngRelease(h->MesHandle);
    if (IsCloseWindow)
    {
      WindowDispOff(0);
    }
  }
  if (h->MemHandle)
    h->MemHandle = 0;
  UnlinkScriptHandleList(h);
}

// 0x1c8760
s32 scrRunScript(scrProcessWork_s *h) {
    scrTraceCode(0);
    return 0;
}

// 0x1c8990
dds3ProcessFunc_t *scrScriptProcess(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    scrTraceCode(0);
    SDF_ABORT1(0);
    return 0;
}

// 0x1c85c0
void *scrScriptShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    scrReleaseScript(0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x1c7fd0
s32 scrSearchProcedureName(void *scrdata, char *procname) {
    return 0;
}

// 0x1c7ee0
scrProcessWork_s *scrSearchScriptName(char *scriptname) {
  struct scrProcessWork_s_o *scrHandleFirst;
  System_Text_Encoding_o *ASCII;
  System_String_o *v5;
  System_String_o *v6;

  else
  {
    if (!scrHandleFirst)
      return scrHandleFirst;
  }
  do
  {
    ASCII = get_ASCII();
    v5 = (ASCII->klass[1]._1.byval_arg.data)(ASCII, scrHandleFirst->Name, *&ASCII->klass[1]._1.byval_arg.bits);
    v6 = Replace_5267216(v5, StringLiteral_859, StringLiteral_416);
    if (!CompareTo_5257920(scriptname, v6))
      break;
    scrHandleFirst = scrHandleFirst->next;
  }
  while (scrHandleFirst);
  return scrHandleFirst;
}

// 0x1c7d30
s32 scrSetStartProc(scrProcessWork_s *h, s32 startproc) {
  struct scrTypeTable_t_array *TypeTable;
  s64 v4;
  struct scrProcTable_t_array *ProcTable;
  struct System_Byte_array *Name;
  u64 v7;
  struct System_Byte_array *v9;
  s32 v10;
  struct scrProcTable_t_array *v13;
  u64 v15;
  struct System_Byte_array *StackType;
  struct scrStackData_u_array *StackData;
  char *v20;

  if (startproc < 0)
    return 0;
  TypeTable = h->TypeTable;
  if (TypeTable->m_Items[0].ItemCount <= startproc)
    return 0;
  v4 = 32;
  do
  {
    ProcTable = h->ProcTable;
    Name = h->Name;
    v7 = v4 - 32;
    v9 = ProcTable->m_Items[startproc].Name;
    v10 = *(&v9->obj.klass + v4);
    *(&Name->obj.klass + v4++) = v10;
  }
  while (v10);
  v13 = h->ProcTable;
  v15 = 0;
  *&h->CP = v13->m_Items[startproc].CodeAddress;
  do
  {
    StackType = h->StackType;
    StackType->m_Items[v15] = 0;
    StackData = h->StackData;
    v20 = StackData + 4 * v15++;
    *(v20 + 8) = 0;
  }
  while (v15 != 28);
  h->StartProc = startproc;
  *&h->ScriptTimer = 0;
  *&h->ScriptTimerF = 0;
  return 1;
}

// 0x1c8380
void scrSetUserData(dds3ProcessID_t *id, void *p) {
    dds3GetProcessData(0);
}

// 0x1c75a0
dds3ProcessID_t *scrStartScript1(s32 priority, scrHeader_t *header, scrTypeTable_t **typetable, scrProcTable_t **proctable, scrLabelTable_t **labeltable, scrCode_t **code, u8 **mesdata, u8 **stringdata, s32 startproc) {
  u64 *v18;
  u64 *v19;
  s64 v21;
  struct System_Char_array *MagicCode;
  s64 v23;
  scrProcessWork_s_o *v24;
  scrHeader_t_o v28;
  scrHeader_t_o v29;

  v18 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v18);
  v19 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v19);
  *&v29.FileType = *&header->FileType;
  v21 = *&header->Resrve3;
  MagicCode = header->MagicCode;
  v23 = *&header->ExpandSize;
  *&v29.LocalIntCount = *&header->LocalIntCount;
  *&v29.Resrve3 = v21;
  v29.MagicCode = MagicCode;
  *&v29.ExpandSize = v23;
  v28 = v29;
  v24 = AddScript(&v28, typetable, proctable, labeltable, code, mesdata, stringdata, startproc);
  return StartScriptProcess(priority, v24);
}

// 0x1c76e0
dds3ProcessID_t *scrStartScript1a(s32 priority, scrHeader_t *header, scrTypeTable_t **typetable, scrProcTable_t **proctable, scrLabelTable_t **labeltable, scrCode_t **code, u8 **mesdata, u8 **stringdata, s32 startproc) {
  u64 *v18;
  u64 *v19;
  s64 v21;
  struct System_Char_array *MagicCode;
  s64 v23;
  scrProcessWork_s_o *v24;
  System_Text_Encoding_o *ASCII;
  struct scrProcTable_t_array *v26;
  s64 v27;
  System_String_o *v29;
  System_String_o *v30;
  u64 *v31;
  u64 *v32;
  dds3ProcessID_t_o *result;
  Il2CppObject *data;
  scrHeader_t_o v36;
  scrHeader_t_o v37;

  v18 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v18);
  v19 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v19);
  *&v37.FileType = *&header->FileType;
  v21 = *&header->Resrve3;
  MagicCode = header->MagicCode;
  v23 = *&header->ExpandSize;
  *&v37.LocalIntCount = *&header->LocalIntCount;
  *&v37.Resrve3 = v21;
  v37.MagicCode = MagicCode;
  *&v37.ExpandSize = v23;
  v36 = v37;
  v24 = AddScript(&v36, typetable, proctable, labeltable, code, mesdata, stringdata, startproc, data);
  ASCII = get_ASCII();
  v26 = v24->ProcTable;
  v27 = v24->StartProc;
  v29 = (ASCII->klass[1]._1.byval_arg.data)(ASCII, v26->m_Items[v27].Name, *&ASCII->klass[1]._1.byval_arg.bits);
  v30 = Replace_5267216(v29, StringLiteral_859, StringLiteral_416);
  v31 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v31,
    0,
    Method_ScrScriptProcess_scrScriptProcess__);
  v32 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v32,
    0,
    Method_ScrScriptProcess_scrScriptShutdown__);
  result = dds3StartProcess(v30, priority, 0, 1, v31, 0, v32, 0, v24, 0);
  v24->ProcessID = result;
  return result;
}

// 0x1c7460
dds3ProcessID_t *scrStartScript2(s32 priority, u8 **scrdata, s32 startproc) {
  u64 *v7;
  u64 *v8;
  scrProcessWork_s_o *v11;

  v7 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v7);
  v8 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v8);
  v11 = AddScript2(scrdata, startproc);
  return StartScriptProcess(priority, v11);
}

// 0x1c7300
dds3ProcessID_t *scrStartScript3(s32 priority, char *filename, s32 startproc, char *akey) {
  u64 *v9;
  u64 *v10;
  scrProcessWork_s_o *v13;

  v9 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v9);
  v10 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v10);
  v13 = AddScript3(filename, startproc, akey);
  return StartScriptProcess(priority, v13);
}
