#include "types.h"

typedef struct bilInstance_s bilInstance_s;
typedef struct bilResource_t bilResource_t;
typedef struct bilSetup_t bilSetup_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static bilSetup_t *bilSetup;
static dds3ProcessID_t *bilProcessID;
static bilResource_t *bilResource[18];

s32 bilDeleteHandle(bilInstance_s **h);
s32 bilLoadBillTex(s32 id);
s32 bilReleaseBillTex(s32 id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void *sdf2DMakeStdPacket(void *aPacket, s32 aLeng);
void *sdfGrAllocPacketBuff(s32 aSize);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);
sdfTexHandle_t *sdfTexSet(void *aTex);

// 0x1315880
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix) {
  return a | (4 * b) | (16 * c) | fix | (d << 6);
}

// 0x13157a0
s32 SDF_VU0_COPYVECTOR(sdfVector4_t a, sdfVector4_t b) {
  return 0;
}

// 0x1315800
s32 SDF_VU0_COPYVECTOR_A_TO_C(void) {
  return 0;
}

// 0x1315810
s32 SDF_VU0_COPYVECTOR_C_TO_A(void) {
  return 0;
}

// 0x13157c0
s32 SDF_VU0_GET_ROW0(void) {
  return 0;
}

// 0x13157d0
s32 SDF_VU0_GET_ROW1(void) {
  return 0;
}

// 0x13157e0
s32 SDF_VU0_GET_ROW2(void) {
  return 0;
}

// 0x13158a0
f32 SDF_VU0_INNERPRODUCT(void) {
  return 0.0;
}

// 0x13157f0
s32 SDF_VU0_LOADIDENTITY(void) {
  return 0;
}

// 0x1315850
s32 SDF_VU0_LOADMATRIX(sdfMatrix4_t *a) {
  return 0;
}

// 0x1315820
s32 SDF_VU0_LOADVECTOR(sdfVector4_t a) {
  return 0;
}

// 0x1315840
s32 SDF_VU0_LOADVECTOR_B(sdfVector4_t p) {
  return 0;
}

// 0x13157b0
s32 SDF_VU0_SCALE(void) {
  return 0;
}

// 0x1315870
s32 SDF_VU0_STOREIDENTITY(sdfMatrix4_t *aMatrix) {
  return 0;
}

// 0x1315860
s32 SDF_VU0_STOREMATRIX(sdfMatrix4_t *a) {
  return 0;
}

// 0x1315830
s32 SDF_VU0_STOREVECTOR(sdfVector4_t p) {
  return 0;
}

// 0x13158b0
f32 acosf(f32 a) {
  return 0.0;
}

// 0x1314b60
s32 bilDeleteHandle(bilInstance_s **h) {
  Il2CppObject *v3;
  struct bilResource_t_array *bilResource;
  s64 Id;
  struct bilResource_t_array *v9;
  s64 v10;
  Il2CppObject *workdata;
  s32 v14;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  struct bilInstance_s_o *Prev;
  u64 *p_Next;
  struct bilInstance_s_o *Next;
  u64 *p_Prev;
  u64 v24[3];

  v3 = Allocate(bilProcessData_t);
  v3[2].monitor = NewSpecific(bilInstance_s, 0x12u);
  v3[3].klass = NewSpecific(bilInstance_s, 0x12u);
  _ctor(v3, 0);
  Id = (*h)->Id;
  --bilResource->m_Items[Id]->TexHandleCount;
  v9 = bilResource;
  v10 = (*h)->Id;
  if (v9->m_Items[v10]->TexHandleCount)
  {
      goto LABEL_21;
  }
  else
  {
    v14 = (*h)->Id;
    bilReleaseBillTex(v14);
      goto LABEL_21;
  }
LABEL_21:
  workdata = bilProcessID->workdata;
  if (!workdata)
    goto LABEL_28;
LABEL_22:
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != bilProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, bilProcessData_t, v24);
    if ((v24[0] & 1) != 0)
      v17 = v24[2];
    else
      v17 = v24 + 1;
    v18 = sub_8C4940(v17);
  }
LABEL_28:
  Prev = (*h)->Prev;
  if (Prev)
    p_Next = &Prev->Next;
  else
    p_Next = &workdata[1].monitor;
  *p_Next = (*h)->Next;
  Next = (*h)->Next;
  if (Next)
    p_Prev = &Next->Prev;
  else
    p_Prev = &workdata[2].klass;
  *p_Prev = (*h)->Prev;
  --LODWORD(workdata[1].klass);
  return 1;
}

// 0x1314410
void bilDraw(bilInstance_s **h) {
  Il2CppObject *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  bilInstance_s_o *v10;
  Il2CppClass *v11;
  s64 Id;
  Il2CppClass *v14;
  s64 v16;
  bilInstance_s_o *v17;
  Il2CppClass *v18;
  s64 *Interface;
  char *v20;
  s64 *v21;
  Il2CppClass *v22;
  s64 *v23;
  u32 *monitor;
  bilInstance_s_o *v25;
  u64 v30[2];
  char *v31;

  v3 = Allocate(bilProcessData_t);
  v3[2].monitor = NewSpecific(bilInstance_s, 0x12u);
  v3[3].klass = NewSpecific(bilInstance_s, 0x12u);
  _ctor(v3, 0);
  else
  {
    workdata = bilProcessID->workdata;
    if (!workdata)
      goto LABEL_14;
  }
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != bilProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, bilProcessData_t, v30);
    if ((v30[0] & 1) != 0)
      v8 = v31;
    else
      v8 = v30 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_14:
  v10 = *h;
  v10->Draw = 0;
  v11 = workdata[3].klass;
  Id = v10->Id;
  if (*(&v11->_1.byval_arg.data + Id))
  {
    v14 = workdata[3].klass;
    v16 = *(&v14->_1.byval_arg.data + Id);
    v17 = *h;
    if (*h)
    {
      Interface = QueryInterface(*h, bilInstance_s);
      if (!Interface)
      {
        sub_8FC2C0(v17->klass->_1.element_class, v18, v30);
        if ((v30[0] & 1) != 0)
          v20 = v31;
        else
          v20 = v30 + 1;
        v21 = sub_8C4940(v20);
      }
    }
    else
    {
      Interface = 0;
    }
    *(v16 + 80) = Interface;
    v22 = workdata[3].klass;
    v23 = *h;
    if (!v23)
      goto LABEL_35;
LABEL_34:
    goto LABEL_35;
  }
  monitor = workdata[2].monitor;
  v25 = *h;
  *&monitor[2 * Id + 8] = v25;
  v22 = workdata[3].klass;
  v23 = *h;
  if (v23)
    goto LABEL_34;
LABEL_35:
  *(&v22->_1.byval_arg.data + Id) = v23;
}

// 0x13166d0
s32 bilExistHandle(bilInstance_s **h) {
  Il2CppObject *v3;
  Il2CppObject *v4;
  u64 *v5;
  Il2CppObject *workdata;
  s64 typeHierarchyDepth;
  Il2CppClass *klass;
  bilInstance_s_o *monitor;
  char *v13;
  s64 *v14;
  u64 v15[3];

  v3 = Allocate(bilProcessData_t);
  v3[2].monitor = NewSpecific(bilInstance_s, 0x12u);
  v3[3].klass = NewSpecific(bilInstance_s, 0x12u);
  _ctor(v3, 0);
  v4 = Allocate(bilInstance_s);
  v5 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v5);
  v4[3].monitor = v5;
  _ctor(v4, 0);
  workdata = bilProcessID->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != bilProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, bilProcessData_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  monitor = workdata[1].monitor;
  if (!monitor)
    return 0;
  while (monitor != *h)
  {
    monitor = monitor->Next;
    if (!monitor)
      return 0;
  }
  return 1;
}

// 0x1315140
bilInstance_s *bilGetHandle(s32 id) {
  Il2CppObject *v3;
  struct bilResource_t_array *bilResource;
  struct bilResource_t_array *v9;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  u64 *p_castClass;
  s32 v18;
  struct bilResource_t_array *v20;
  bilResource_t_o *v22;
  u64 v24[3];

  v3 = Allocate(bilProcessData_t);
  v3[2].monitor = NewSpecific(bilInstance_s, 0x12u);
  v3[3].klass = NewSpecific(bilInstance_s, 0x12u);
  _ctor(v3, 0);
  if (!bilResource->m_Items[id]->TexHandle)
  {
    bilLoadBillTex(id);
  }
  *init_proc = id;
  loc_34 = -2139062144;
  v9 = bilResource;
  loc_38 = v9->m_Items[id]->TexHandle;
  sub_854930(16, 0);
  sub_854930(16, 1u);
  sub_854930(16, 2u);
  sub_854930(16, 3u);
  sub_854930(32, 0);
  sub_854930(32, 1u);
  sub_854930(32, 2u);
  sub_854930(32, 3u);
  loc_40 = 0;
  loc_48 = 0;
  loc_50 = 0;
  workdata = bilProcessID->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != bilProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, bilProcessData_t, v24);
      if ((v24[0] & 1) != 0)
        v15 = v24[2];
      else
        v15 = v24 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  if (workdata[2].klass)
  {
    loc_40 = workdata[2].klass;
    p_castClass = &workdata[2].klass->_1.castClass;
  }
  else
  {
    p_castClass = &workdata[1].monitor;
  }
  *p_castClass = 0;
  v18 = LODWORD(workdata[1].klass) + 1;
  workdata[2].klass = 0;
  LODWORD(workdata[1].klass) = v18;
  v20 = bilResource;
  v22 = v20->m_Items[id];
  ++v22->TexHandleCount;
  return 0;
}

// 0x1316c80
void bilGetMode1Matrix2(sdfMatrix4_t **tm) {
  bilManager_c *v3;
  u64 v4[2];

  v4[0] = 0;
  v4[1] = 0;
  sub_854690(v4, 0.0, 1.0, 0.0, 0.0);
  {
          v3 = bilManager,
    {
    }
  }
}

// 0x1316a20
dds3ProcessID_t *bilInitManager(void) {
  u64 *v1;
  u64 *v2;
  s64 i;
  u64 v6;
  struct bilResource_t_array *bilResource;
  struct bilResource_t_array *v9;
  s64 v11;
  s64 v12;
  u64 v13;
  u64 v15;
  u64 *v17;

  v1 = Allocate(bilProcessData_t);
  v1[5] = NewSpecific(bilInstance_s, 0x12u);
  v1[6] = NewSpecific(bilInstance_s, 0x12u);
  _ctor(v1, 0);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  for (i = 4; i != 22; ++i)
  {
    v6 = i - 4;
    *(*(&bilResource->obj.klass + i) + 16LL) = 0;
    v9 = bilResource;
    v11 = *(&v9->obj.klass + i);
    *(v11 + 24) = 0;
  }
  v12 = 4;
  *(v1 + 4) = 0;
  v1[3] = 0;
  v1[4] = 0;
  do
  {
    v13 = v1[5];
    *(v13 + 8 * v12) = 0;
    v15 = v1[6];
    *(v15 + 8 * v12++) = 0;
  }
  while (v12 != 22);
  v17 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v17,
    0,
    Method_bilManager_bilManagerProcess__);
  return dds3StartProcess("BillManager", 0x2B0Cu, 1, 0, v17, 0, 0, 0, 0, 0);
}

// 0x1316950
void bilKillManager(void) {
  else if (!bilProcessID)
  {
    return;
  }
  dds3KillProcess(&bilProcessID, 0);
}

// 0x1315900
s32 bilLoadBillTex(s32 id) {
  u64 *v3;
  u64 *v4;
  u64 *v6;
  struct bilSetup_t_array *bilSetup;
  u64 *v11;
  sdfTexHandle_t_o *v13;
  struct bilResource_t_array *bilResource;
  struct bilResource_t_array *v18;
  struct System_UInt16_array_array *UvTable;
  System_UInt16_array *v21;
  struct bilResource_t_array *v22;
  struct System_UInt16_array_array *v24;
  System_UInt16_array *v25;
  struct bilResource_t_array *v27;
  struct System_UInt16_array_array *v29;
  System_UInt16_array *v31;
  struct bilResource_t_array *v33;
  struct System_UInt16_array_array *v35;
  System_UInt16_array *v37;
  struct bilResource_t_array *v39;
  struct System_UInt16_array_array *v41;
  System_UInt16_array *v43;
  struct bilResource_t_array *v45;
  struct System_UInt16_array_array *v47;
  System_UInt16_array *v49;
  struct bilResource_t_array *v51;
  struct System_UInt16_array_array *v53;
  System_UInt16_array *v55;
  struct bilResource_t_array *v57;
  struct System_UInt16_array_array *v59;
  System_UInt16_array *v61;
  u64 v63;
  struct bilResource_t_array *v65;
  struct System_Single_array_array *v67;
  System_Single_array *v69;
  u32 v71;
  struct bilResource_t_array *v72;
  struct System_Single_array_array *XyOffset;
  struct bilResource_t_array *v78;
  struct System_Single_array_array *v80;
  System_Single_array *v82;
  struct bilResource_t_array *v85;
  struct System_Single_array_array *v87;
  System_Single_array *v89;
  struct bilResource_t_array *v91;
  struct System_Single_array_array *v93;
  System_Single_array *v95;
  struct bilResource_t_array *v96;
  struct System_Single_array_array *v98;
  System_Single_array *v100;
  f32 v102;
  struct bilSetup_t_array *v103;
  struct System_Single_array *Offset;
  struct bilResource_t_array *v108;
  struct System_Single_array_array *v110;
  System_Single_array *v112;
  struct bilResource_t_array *v113;
  struct System_Single_array_array *v115;
  System_Single_array *v117;
  f32 v119;
  struct bilSetup_t_array *v120;
  struct System_Single_array *v122;
  s8 v129[4];
  s32 v130;

  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v4);
  v130 = 0;
  v6 = sub_8D3950(s32, &v130);
  v129[0] = bilSetup->m_Items[id]->File;
  v11 = sub_8D3950(sbyte, v129);
  Write_2930400("bilLoadBillTex(): {0} loading...\n", v11, 0);
  v13 = sdfTexSet(v6);
  bilResource->m_Items[id]->TexHandle = v13;
  v18 = bilResource;
  UvTable = v18->m_Items[id]->UvTable;
  v21 = UvTable->m_Items[0];
  v21->m_Items[0] = 0;
  v22 = bilResource;
  v24 = v22->m_Items[id]->UvTable;
  v25 = v24->m_Items[0];
  v25->m_Items[1] = 0;
  v27 = bilResource;
  v29 = v27->m_Items[id]->UvTable;
  v31 = v29->m_Items[1];
  v31->m_Items[0] = 16 * v13->width;
  v33 = bilResource;
  v35 = v33->m_Items[id]->UvTable;
  v37 = v35->m_Items[1];
  v37->m_Items[1] = 0;
  v39 = bilResource;
  v41 = v39->m_Items[id]->UvTable;
  v43 = v41->m_Items[2];
  v43->m_Items[0] = 16 * v13->width;
  v45 = bilResource;
  v47 = v45->m_Items[id]->UvTable;
  v49 = v47->m_Items[2];
  v49->m_Items[1] = 16 * v13->height;
  v51 = bilResource;
  v53 = v51->m_Items[id]->UvTable;
  v55 = v53->m_Items[3];
  v55->m_Items[0] = 0;
  v57 = bilResource;
  v59 = v57->m_Items[id]->UvTable;
  v61 = v59->m_Items[3];
  v63 = 0;
  v61->m_Items[1] = 16 * v13->height;
  do
  {
    if (v63 != 3 && v63)
    {
      v72 = bilResource;
      XyOffset = v72->m_Items[id]->XyOffset;
      v69 = XyOffset->m_Items[v63];
      v71 = 0;
    }
    else
    {
      v65 = bilResource;
      v67 = v65->m_Items[id]->XyOffset;
      v69 = v67->m_Items[v63];
      v71 = 0x80000000;
    }
    LODWORD(v69->m_Items[0]) = v71;
    if (v63 > 1)
    {
      v85 = bilResource;
      v87 = v85->m_Items[id]->XyOffset;
      v89 = v87->m_Items[v63];
      v89->m_Items[1] = 0.0;
      {
LABEL_95:
      }
    }
    else
    {
      v78 = bilResource;
      v80 = v78->m_Items[id]->XyOffset;
      v82 = v80->m_Items[v63];
      v82->m_Items[1] = -0.0;
        goto LABEL_95;
    }
    v91 = bilResource;
    v93 = v91->m_Items[id]->XyOffset;
    v95 = v93->m_Items[v63];
    v96 = bilResource;
    v98 = v96->m_Items[id]->XyOffset;
    v100 = v98->m_Items[v63];
    v102 = v100->m_Items[0];
    v103 = bilSetup;
    Offset = v103->m_Items[id]->Offset;
    v95->m_Items[0] = (v102 + Offset->m_Items[0]) * 0.0625;
    v108 = bilResource;
    v110 = v108->m_Items[id]->XyOffset;
    v112 = v110->m_Items[v63];
    v113 = bilResource;
    v115 = v113->m_Items[id]->XyOffset;
    v117 = v115->m_Items[v63];
    v119 = v117->m_Items[1];
    v120 = bilSetup;
    v122 = v120->m_Items[id]->Offset;
    ++v63;
    v112->m_Items[1] = (v119 + v122->m_Items[1]) * 0.0625;
  }
  while (v63 != 4);
  return 1;
}

// 0x1316d50
void *bilMakeAlphaPacket(u64 aData) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  Il2CppClass *element_class;
  s32 *v8;
  Il2CppObject *v9;
  Il2CppClass *klass;
  Il2CppObject *v11;
  s64 typeHierarchyDepth;
  Il2CppClass *v13;
  s32 *v14;
  Il2CppObject *result;
  Il2CppClass *v16;
  s64 v17;
  char *v18;
  s64 *v19;
  char *v20;
  s64 *v21;
  char *v22;
  s64 *v23;
  char *v24;
  s64 *v25;
  u64 v26[2];
  char *v27;

  v3 = Allocate(bilManager_AnonymousClass);
  v4 = Allocate(sdfGrPacketHeader_t);
  sdfGrPacketHeader_t___ctor(v4);
  v3[1].klass = v4;
  v5 = Allocate(sdfGrTagStdReg_t);
  sdfGrTagStdReg_t___ctor(v5);
  v3[1].monitor = v5;
  _ctor(v3, 0);
  element_class = v3->klass->_1.element_class;
  {
    sub_8FC2C0(element_class, s32, v26);
    if ((v26[0] & 1) != 0)
      v22 = v27;
    else
      v22 = v26 + 1;
    v23 = sub_8C4940(v22);
  }
  v8 = sub_8D3F90(v3);
  v9 = sdfGrAllocPacketBuff(*v8);
  if (!v9)
    sub_8C38A0();
  klass = v9->klass;
  v11 = v9;
  if (v9->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != bilManager_AnonymousClass)
  {
    sub_8FC2C0(klass->_1.element_class, bilManager_AnonymousClass, v26);
    if ((v26[0] & 1) != 0)
      v18 = v27;
    else
      v18 = v26 + 1;
    v19 = sub_8C4940(v18);
  }
  v13 = klass->_1.element_class;
  {
    sub_8FC2C0(v13, s32, v26);
    if ((v26[0] & 1) != 0)
      v24 = v27;
    else
      v24 = v26 + 1;
    v25 = sub_8C4940(v24);
  }
  v14 = sub_8D3F90(v11);
  result = sdf2DMakeStdPacket(v11, *v14);
  v16 = result->klass;
  if (result->klass->_2.typeHierarchyDepth < v17
    || v16->_2.typeHierarchy[v17 - 1] != bilManager_AnonymousClass)
  {
    sub_8FC2C0(v16->_1.element_class, bilManager_AnonymousClass, v26);
    if ((v26[0] & 1) != 0)
      v20 = v27;
    else
      v20 = v26 + 1;
    v21 = sub_8C4940(v20);
  }
  *(result[1].monitor + 3) = aData;
  *(result[1].monitor + 4) = 66;
  return result;
}

// 0x1317110
dds3ProcessFunc_t *bilManagerProcess(dds3ProcessID_t *id) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  Il2CppObject *v8;
  u64 *v9;
  u64 *v10;
  u64 *v11;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  s64 i;
  u64 *monitor;
  Il2CppClass *v20;
  u64 v23[3];

  v3 = Allocate(bilProcessData_t);
  v3[2].monitor = NewSpecific(bilInstance_s, 0x12u);
  v3[3].klass = NewSpecific(bilInstance_s, 0x12u);
  _ctor(v3, 0);
  v4 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v4);
  v5 = Allocate(sdfGrRefPacketHeader_t);
  sdfGrRefPacketHeader_t___ctor(v5);
  v6 = Allocate(sdfBillBoardTMPacket_t);
  sdfBillBoardTMPacket_t___ctor(v6);
  v7 = Allocate(sdfBillBoard1Packet_t);
  sdfBillBoard1Packet_t___ctor(v7);
  v8 = Allocate(bilInstance_s);
  v9 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v9);
  v8[3].monitor = v9;
  _ctor(v8, 0);
  v10 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v10);
  v11 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v11);
  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != bilProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, bilProcessData_t, v23);
      if ((v23[0] & 1) != 0)
        v15 = v23[2];
      else
        v15 = v23 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  for (i = 4; i != 22; ++i)
  {
    monitor = workdata[2].monitor;
    monitor[i] = 0;
    v20 = workdata[3].klass;
    *(&v20->_1.image + i) = 0;
  }
  return 0;
}

// 0x13173c0
void bilManagerShutdown(dds3ProcessID_t **id) {
  Il2CppObject *workdata;
  bilProcessData_t_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  bilInstance_s_o *i;
  bilInstance_s_o **p_monitor;
  bilInstance_s_o *monitor;
  char *v11;
  s64 *v12;
  u64 v13[3];

  workdata = (*id)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != bilProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, bilProcessData_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  monitor = workdata[1].monitor;
  p_monitor = &workdata[1].monitor;
  for (i = monitor; ; i = *p_monitor)
  {
    if (!i)
      break;
    bilDeleteHandle(p_monitor, v4);
  }
  bilProcessID = 0;
}

// 0x13163c0
s32 bilReleaseBillTex(s32 id) {
  struct bilResource_t_array *bilResource;
  struct bilResource_t_array *v7;
  sdfTexHandle_t_o *TexHandle;
  struct bilResource_t_array *v10;

  if (bilResource->m_Items[id]->TexHandle)
  {
    v7 = bilResource;
    TexHandle = v7->m_Items[id]->TexHandle;
    sdfTexFreeDelayed(TexHandle);
    v10 = bilResource;
    v10->m_Items[id]->TexHandle = 0;
  }
  return 1;
}

// 0x13166c0
void bilSetColor(bilInstance_s **h, u32 color) {
  (*h)->Color = color;
}

// 0x13165a0
void bilSetPos(bilInstance_s **h, sdfVector4_t pos) {

}

// 0x1314330
void bilSetPosXYZ(bilInstance_s **h, f32 x, f32 y, f32 z) {
  sub_854930(&(*h)->fields, 0);
  sub_854930(&(*h)->fields, 1u);
  sub_854930(&(*h)->fields, 2u);
}

// 0x13143a0
void bilSetScl(bilInstance_s **h, f32 x, f32 y, f32 z) {
  sub_854930(&(*h)->Scl, 0);
  sub_854930(&(*h)->Scl, 1u);
  sub_854930(&(*h)->Scl, 2u);
}

// 0x1316610
void bilSetSize(bilInstance_s **h, f32 x, f32 y, f32 z) {
  sub_854930(&(*h)->Scl, 0);
  sub_854930(&(*h)->Scl, 1u);
  sub_854930(&(*h)->Scl, 2u);
}

// 0x13158e0
void sdfVu0LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aUp) {
  ;
}

// 0x13158c0
void sdfVu0MultMatrixRevNoArg(void) {
  ;
}

// 0x13158f0
void sdfVu0ReverseMatrix(void) {
  ;
}

// 0x13158d0
void sdfVu0SetRotateMatrixZ_B(f32 aAngle) {
  ;
}
