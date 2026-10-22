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
    goto LABEL_48;
  if (typetable->m_Items[0].ItemCount <= startproc)
  {
LABEL_48:
    SDF_ABORT1("scrStartScript(..) invalid start procedure!!\n", 0);
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
  u64 *v5;
  struct System_Char_array *v7;
  s64 v8;
  s32 v9;
  s64 v10;
  u64 *v14;
  scrTypeTable_t_array *v16;
  u64 v17;
  u64 *v18;
  s64 v19;
  u64 i;
  s64 Type;
  s32 v27;
  s64 v28;
  s64 v29;
  scrHeader_t_o v30;
  s64 v31;
  s64 v32;
  s64 v33;
  s64 v34;
  s64 v35;
  s32 v36;
  s64 v37;
  s64 v38;

  v37 = 0;
  v38 = 0;
  v5 = Allocate(scrHandle_t);
  scrHandle_t___ctor(v5);
  v36 = 0;
  v31 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  sub_17C8640(&v31, scrdata, &v36);
  v8 = v31;
  v7 = v32;
  v9 = v33;
  v10 = HIDWORD(v33);
  v37 = v34;
  v38 = v35;
  if (*(v32 + 32) != 70)
    goto LABEL_38;
  if (*(v32 + 34) != 76)
    goto LABEL_38;
  if (*(v32 + 36) != 87)
    goto LABEL_38;
  if (*(v32 + 38) == 48)
  {
    v14 = NewSpecific(scrTypeTable_t, HIDWORD(v33));
    v16 = v14;
    v28 = v8;
    v27 = v9;
    if (v10 >= 1)
    {
      v17 = 0;
      v18 = v14 + 5;
      v29 = v10;
      do
      {
        v31 = 0;
        v32 = 0;
        sub_17C9360(&v31, scrdata, &v36);
        v19 = v32;
        *(v18 - 1) = v31;
        *v18 = v19;
        LODWORD(v10) = v29;
        ++v17;
        v18 += 2;
      }
      while (v29 != v17);
      for (i = 0; i != v29; ++i)
      {
        Type = v16->m_Items[i].Type;
        if (Type <= 4)
          __asm { BR              X9 }
      }
    }
    v32 = v38;
    v31 = v37;
    v30.MagicCode = v7;
    *&v30.FileType = v28;
    v30.ExpandSize = v27;
    v30.TypeTableCount = v10;
    *&v30.LocalIntCount = v31;
    *&v30.Resrve3 = v32;
    return AddScript(&v30, v16, 0, 0, 0, 0, 0, startproc);
  }
  else
  {
LABEL_38:
    SDF_ABORT1("invalid script data!!\n");
  }
  return v5;
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
LABEL_6:
  asset_bc = get_asset_bc();
  v12 = Concat_5224608(filename, ".bytes");
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
  v5 = &"m";
  if (!v3 || !v4)
    v5 = &"";
  return *v5;
}

// 0x1c6e70
char *GetEventFileNameToAssetName(char *filename) {
  s32 Length;
  s32 IndexOf;
  System_String_o *v5;
  s32 v6;

  Replace_5267216(filename, "\\", "/");
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

  {
    else
    {
      if (scrHandleLast)
        goto LABEL_5;
    }
LABEL_13:
    scrHandleFirst = h;
    scrHandleLast = h;
    h->prev = 0;
    h->next = 0;
    if ((v3->_2.bitflags2 & 2) != 0)
      goto LABEL_9;
    goto LABEL_17;
  }
  v4 = 0;
  if (!scrHandleLast)
    goto LABEL_13;
LABEL_5:
  h->prev = scrHandleLast;
  scrHandleLast->next = h;
  h->next = 0;
  scrHandleLast = h;
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
LABEL_17:
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
  v11 = Replace_5267216(v10, " ", "");
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
  ScrScriptProcess_c *v3;
  struct scrProcessWork_s_o *next;
  struct scrProcessWork_s_o *prev;

  if (scrHandleFirst == h)
    goto LABEL_11;
LABEL_6:
  h->prev->next = h->next;
  if ((v3->_2.bitflags2 & 2) == 0)
    goto LABEL_15;
LABEL_7:
LABEL_15:
  if (scrHandleLast != h)
    goto LABEL_16;
LABEL_19:
  prev = h->prev;
  scrHandleLast = prev;
  h->prev = 0;
  h->next = 0;
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_17:
  }
LABEL_23:
  --scrHandleCount;
}

// 0x1c7c10
void scrAllReleaseScript(void) {
  struct scrProcessWork_s_o *scrHandleFirst;

  else
  {
    if (scrHandleFirst)
      goto LABEL_6;
  }
}

// 0x1c84a0
void *scrGetUserData(dds3ProcessID_t *id) {
  u64 *v2;
  Il2CppObject **ProcessData;
  Il2CppObject *v5;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3ProcessID_t_o *v10[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  v2 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v2);
  ProcessData = dds3GetProcessData(&ida);
  v5 = *ProcessData;
  if (LOBYTE((*ProcessData)[18].klass) < typeHierarchyDepth
    || *(v5[12].monitor + typeHierarchyDepth - 1) != scrProcessWork_s)
  {
    sub_8FC2C0(v5[4].klass, scrProcessWork_s, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  return ProcessData[26];
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
  return AddScript3(filename, 0, "EventAB");
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
  v8 = Replace_5267216(v7, " ", "");
  v9 = Format("procedure end <{0}>\n", v8, 0);
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
  scrProcessWork_s_o *v3;

  else
  {
    v3 = h;
  }
  return scrTraceCode(v3);
}

// 0x1c8990
dds3ProcessFunc_t *scrScriptProcess(dds3ProcessID_t *id) {
  scrProcessWork_s_c *v2;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v8;
  dds3ProcessID_t_o *v11[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  else if (!ProcessData)
  {
    goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != scrProcessWork_s)
  {
    sub_8FC2C0(klass->_1.element_class, scrProcessWork_s, v11);
    if ((v11[0] & 1) != 0)
      v6 = v11[2];
    else
      v6 = v11 + 1;
    v7 = sub_8C4940(v6);
  }
LABEL_15:
  v8 = scrTraceCode(ProcessData, v2);
  if (v8 == 2)
  {
LABEL_21:
    ida->func_ans = -1;
    return 0;
  }
  if (!v8)
  {
    SDF_ABORT1("scrScriptProcess(..) error script!\n", 0);
    goto LABEL_21;
  }
  return 0;
}

// 0x1c85c0
void *scrScriptShutdown(dds3ProcessID_t *id) {
  u64 *v2;
  Il2CppObject *ProcessData;
  scrProcessWork_s_c *v6;
  Il2CppClass *klass;
  scrProcessWork_s_o *v8;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  dds3ProcessID_t_o *v13[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  v2 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v2);
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_18;
  }
  klass = ProcessData->klass;
  v8 = ProcessData;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != scrProcessWork_s)
  {
    sub_8FC2C0(klass->_1.element_class, scrProcessWork_s, v13);
    if ((v13[0] & 1) != 0)
      v10 = v13[2];
    else
      v10 = v13 + 1;
    v11 = sub_8C4940(v10);
  }
  scrReleaseScript(v8, v6);
LABEL_18:
  ida->func_ans = -1;
  dds3SetProcessData(&ida, 0);
  return 0;
}

// 0x1c7fd0
s32 scrSearchProcedureName(void *scrdata, char *procname) {
  Il2CppClass *v5;
  s64 *Interface;
  char *v7;
  s64 *v8;
  u64 *v9;
  u64 *v10;
  s64 v11;
  u64 *v12;
  u64 *v13;
  u64 v14;
  u64 *v15;
  s64 v16;
  u64 i;
  u32 *v20;
  s32 v22;
  s32 v23;
  u32 *v24;
  s32 v26;
  System_Text_Encoding_o *ASCII;
  struct System_Byte_array *Name;
  System_String_o *v29;
  System_String_o *v30;
  scrProcTable_t_o v32;
  char *v33;
  s64 v34;
  s64 v35;
  s32 v36;

  v36 = 0;
  if (!scrdata)
    return -1;
  Interface = QueryInterface(scrdata, byte);
  if (!Interface)
  {
    sub_8FC2C0(scrdata->klass->_1.element_class, v5, &v32);
    if ((v32.Name & 1) != 0)
      v7 = v33;
    else
      v7 = &v32.Name + 1;
    v8 = sub_8C4940(v7);
  }
  v36 = 0;
  v9 = Allocate(scrHandle_t);
  scrHandle_t___ctor(v9);
  v10 = Allocate(System_Collections_Generic_List_scrProcTable_t_);
  __ctor(
    v10);
  v34 = 0;
  v35 = 0;
  *&v32.CodeAddress = 0;
  v33 = 0;
  v32.Name = 0;
  sub_17C8640(&v32, Interface, &v36);
  v11 = HIDWORD(v33);
  v12 = NewSpecific(scrTypeTable_t, HIDWORD(v33));
  if (v11 <= 0)
  {
    _Clear(v10);
  }
  else
  {
    v13 = v12;
    v14 = 0;
    v15 = v12 + 5;
    do
    {
      v32.Name = 0;
      *&v32.CodeAddress = 0;
      sub_17C9360(&v32, Interface, &v36);
      v16 = *&v32.CodeAddress;
      ++v14;
      *(v15 - 1) = v32.Name;
      *v15 = v16;
      v15 += 2;
    }
    while (v11 != v14);
    _Clear(v10);
    for (i = 0; i != v11; ++i)
    {
      v20 = &v13[2 * i];
      if (!v20[8])
      {
        v22 = v20[11];
        v23 = 0;
        v24 = v20 + 10;
        v36 = v22;
        if (i >= *(v13 + 6))
        {
LABEL_22:
        }
        while (v23 < *v24)
        {
          v32.Name = 0;
          *&v32.CodeAddress = 0;
          sub_17C91B0(&v32, Interface, &v36);
          _Add(v10, v32);
          ++v23;
          if (i >= *(v13 + 6))
            goto LABEL_22;
        }
      }
    }
  }
  if (!_get_Count(v10)
    || _get_Count(v10) < 1)
  {
    return -1;
  }
  v26 = 0;
  while (1)
  {
    ASCII = get_ASCII();
    Name = _get_Item(
             v10,
             v26).Name;
    v29 = (ASCII->klass[1]._1.byval_arg.data)(ASCII, Name, *&ASCII->klass[1]._1.byval_arg.bits);
    v30 = Replace_5267216(v29, " ", "");
    if (!CompareTo_5257920(procname, v30))
      break;
    if (++v26 >= _get_Count(v10))
      return -1;
  }
  return v26;
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
    v6 = Replace_5267216(v5, " ", "");
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
  u64 *v4;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  dds3ProcessID_t_o *v11;
  u64 v12[3];

  v11 = id;
  v4 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v4);
  ProcessData = dds3GetProcessData(&v11);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != scrProcessWork_s)
  {
    sub_8FC2C0(klass->_1.element_class, scrProcessWork_s, v12);
    if ((v12[0] & 1) != 0)
      v9 = v12[2];
    else
      v9 = v12 + 1;
    v10 = sub_8C4940(v9);
  }
  ProcessData[13].klass = p;
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
  v30 = Replace_5267216(v29, " ", "");
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
