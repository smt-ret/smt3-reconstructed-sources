#include "types.h"

typedef struct bilInstance_s bilInstance_s;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfModelOt_t sdfModelOt_t;

static sdfModelOt_t *dds3ModelOt[11];
static bilInstance_s *billh[2];
static dds3ModelHandle_t *model;
static s32 select;

s32 bilDeleteHandle(bilInstance_s **h);
void bilDraw(bilInstance_s **h);
bilInstance_s *bilGetHandle(s32 id);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
f32 sdfCos(f32 aRadius);
f32 sdfSin(f32 aRadius);

// 0x1313e90
bool SDF_PADCHECK_PRESS(s32 id) {
  return 0;
}

// 0x1313e80
bool SDF_PADCHECK_TRIG(s32 a) {
  return 0;
}

// 0x1313dc0
s32 SDF_VU0_ADDVECTOR(void) {
  return 0;
}

// 0x1313dd0
s32 SDF_VU0_APPLYMATRIX(void) {
  return 0;
}

// 0x1313d60
s32 SDF_VU0_COPYVECTOR(sdfVector4_t a, sdfVector4_t b) {
  return 0;
}

// 0x1313df0
s32 SDF_VU0_COPYVECTOR_A_TO_C(void) {
  return 0;
}

// 0x1313e00
s32 SDF_VU0_COPYVECTOR_C_TO_A(void) {
  return 0;
}

// 0x1313d80
s32 SDF_VU0_GET_ROW0(void) {
  return 0;
}

// 0x1313d90
s32 SDF_VU0_GET_ROW1(void) {
  return 0;
}

// 0x1313da0
s32 SDF_VU0_GET_ROW2(void) {
  return 0;
}

// 0x1313de0
s32 SDF_VU0_LOADIDENTITY(void) {
  return 0;
}

// 0x1313e50
s32 SDF_VU0_LOADMATRIX(sdfMatrix4_t *a) {
  return 0;
}

// 0x1313e20
s32 SDF_VU0_LOADVECTOR(sdfVector4_t a) {
  return 0;
}

// 0x1313e40
s32 SDF_VU0_LOADVECTOR_B(sdfVector4_t p) {
  return 0;
}

// 0x1313d70
s32 SDF_VU0_SCALE(void) {
  return 0;
}

// 0x1313e10
s32 SDF_VU0_SCALEVECTOR(f32 a) {
  return 0;
}

// 0x1313e70
s32 SDF_VU0_STOREIDENTITY(sdfMatrix4_t *aMatrix) {
  return 0;
}

// 0x1313e60
s32 SDF_VU0_STOREMATRIX(sdfMatrix4_t *a) {
  return 0;
}

// 0x1313e30
s32 SDF_VU0_STOREVECTOR(sdfVector4_t p) {
  return 0;
}

// 0x1313db0
s32 SDF_VU0_SUBVECTOR(void) {
  return 0;
}

// 0x1314e30
void bilTest(void) {
  u64 v2;
  s32 v3;
  u64 i;
  struct bilInstance_s_array_array *billh;
  bilInstance_s_array *v8;
  s64 v10;
  u64 *v13;
  u64 *v14;

  v2 = 0;
  v3 = 0;
  do
  {
    if (v2 < 3)
    {
      v3 = v2 + 1;
    }
    else if ((v2 - 3) <= 1)
    {
      v3 = v2 + 7;
    }
    for (i = 0; i != 20; ++i)
    {
      v8 = billh->m_Items[v2];
      bilGetHandle(v3);
      v10 = v8 + 8 * i;
      *(v10 + 32) = 0;
    }
    ++v2;
  }
  while (v2 != 5);
  select = 0;
  sub_854930(&dds3CameraTargetPos, 0);
  sub_854930(&dds3CameraTargetPos, 1u);
  sub_854930(&dds3CameraTargetPos, 2u);
  sub_854930(&dds3CameraEyePos, 0);
  sub_854930(&dds3CameraEyePos, 1u);
  sub_854930(&dds3CameraEyePos, 2u);
  v13 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v13);
  model = v13;
  v14 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v14,
    0,
    Method_bilDebug_bilTestProcess__);
  dds3StartProcess("BillTest", 0x3E8u, 1, 0, v14, 0, 0, 0, 0, 0);
}

// 0x1313f30
dds3ProcessFunc_t *bilTestProcess(dds3ProcessID_t *id) {
  s64 v2;
  s64 v3;
  u64 v5;
  struct bilInstance_s_array_array *billh;
  s64 select;
  f32 v10;
  bilInstance_s_array *v11;
  struct bilInstance_s_array_array *v15;
  s64 v16;
  bilInstance_s_array *v18;
  struct bilInstance_s_array_array *v22;
  s64 v23;
  bilInstance_s_array *v25;

  v2 = -20;
  v3 = 32;
  do
  {
    v5 = v2 + 20;
    v10 = v5 * 0.31416;
    v11 = billh->m_Items[select];
    sdfCos(v10);
    sdfSin(v10);
    else if (v5 >= LODWORD(v11->max_length))
    {
LABEL_17:
    }
    sub_854930(&(*(&v11->obj.klass + v3))->_1.name, 0);
    sub_854930(&(*(&v11->obj.klass + v3))->_1.name, 1u);
    sub_854930(&(*(&v11->obj.klass + v3))->_1.name, 2u);
    v15 = billh;
    v16 = select;
    v18 = v15->m_Items[v16];
    sub_854930(&(*(&v18->obj.klass + v3))->_1.byval_arg, 0);
    sub_854930(&(*(&v18->obj.klass + v3))->_1.byval_arg, 1u);
    sub_854930(&(*(&v18->obj.klass + v3))->_1.byval_arg, 2u);
    v22 = billh;
    v23 = select;
    v25 = v22->m_Items[v23];
    bilDraw((v25 + v3));
    ++v2;
    v3 += 8;
  }
  while (v2);
    goto LABEL_54;
  {
    if (!LODWORD(dds3ModelOt->max_length))
    {
LABEL_29:
    }
  }
  else
  {
LABEL_54:
    if (!LODWORD(dds3ModelOt->max_length))
      goto LABEL_29;
  }
  return 0;
}

// 0x1314760
void bilTestShutdown(dds3ProcessID_t *id) {
  u64 v2;
  s64 v3;
  struct bilInstance_s_array_array *billh;
  bilInstance_s_array *v5;
  u64 v8;
  s64 i;
  struct bilInstance_s_array_array *v11;
  bilInstance_s_array *v12;
  u64 v15;
  s64 j;
  struct bilInstance_s_array_array *v18;
  bilInstance_s_array *v20;
  u64 v22;
  s64 k;
  struct bilInstance_s_array_array *v25;
  bilInstance_s_array *v26;
  u64 v29;
  s64 m;
  struct bilInstance_s_array_array *v32;
  bilInstance_s_array *v34;

  v2 = 0;
  v3 = 32;
  do
  {
    else
    {
      if (!LODWORD(billh->max_length))
        goto LABEL_15;
    }
    v5 = billh->m_Items[0];
    else
    {
      if (v2 >= LODWORD(v5->max_length))
        goto LABEL_17;
    }
    bilDeleteHandle((v5 + v3));
    ++v2;
    v3 += 8;
  }
  while (v2 != 20);
  v8 = 0;
  for (i = 32; i != 192; i += 8)
  {
    v11 = billh;
    v12 = v11->m_Items[1];
    else
    {
      if (v8 >= LODWORD(v12->max_length))
        goto LABEL_30;
    }
    bilDeleteHandle((v12 + i));
    ++v8;
  }
  v15 = 0;
  for (j = 32; j != 192; j += 8)
  {
    v18 = billh;
    v20 = v18->m_Items[2];
    else if (v15 >= LODWORD(v20->max_length))
    {
LABEL_43:
    }
    bilDeleteHandle((v20 + j));
    ++v15;
  }
  v22 = 0;
  for (k = 32; k != 192; k += 8)
  {
    v25 = billh;
    v26 = v25->m_Items[3];
    else
    {
      if (v22 >= LODWORD(v26->max_length))
        goto LABEL_56;
    }
    bilDeleteHandle((v26 + k));
    ++v22;
  }
  v29 = 0;
  for (m = 32; m != 192; m += 8)
  {
    v32 = billh;
    v34 = v32->m_Items[4];
    else if (v29 >= LODWORD(v34->max_length))
    {
LABEL_69:
    }
    bilDeleteHandle((v34 + m));
    ++v29;
  }
}

// 0x1313ea0
void mdlFree(dds3ModelHandle_t *aHandle) {
  ;
}

// 0x1313ec0
void mdlLink(dds3ModelHandle_t *aHandle, sdfModelOt_t *aModelOt) {
  ;
}

// 0x1313ed0
dds3ModelHandle_t *mdlLoad(s32 aMajor, s32 aMinor) {
  u64 *v3;

  v3 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v3);
  return v3;
}

// 0x1313eb0
void sdfVu0SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aVector) {
  ;
}
