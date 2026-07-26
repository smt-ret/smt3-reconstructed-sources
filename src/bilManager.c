#include "types.h"

typedef struct bilInstance_s bilInstance_s;
typedef struct bilResource_t bilResource_t;
typedef struct bilSetup_t bilSetup_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static bilSetup_t bilSetup[UNKNOWN_ARRAY_SIZE];
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
    bilReleaseBillTex(0);
    return 0;
}

// 0x1314410
void bilDraw(bilInstance_s **h) {
}

// 0x13166d0
s32 bilExistHandle(bilInstance_s **h) {
    return 0;
}

// 0x1315140
bilInstance_s *bilGetHandle(s32 id) {
    bilLoadBillTex(0);
    return 0;
}

// 0x1316c80
void bilGetMode1Matrix2(sdfMatrix4_t **tm) {
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
  return dds3StartProcess(StringLiteral_12233, 0x2B0Cu, 1, 0, v17, 0, 0, 0, 0, 0);
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
    sdfTexSet(0);
    return 0;
}

// 0x1316d50
void *bilMakeAlphaPacket(u64 aData) {
    sdfGrAllocPacketBuff(0);
    sdf2DMakeStdPacket(0, 0);
    return 0;
}

// 0x1317110
dds3ProcessFunc_t *bilManagerProcess(dds3ProcessID_t *id) {
    return 0;
}

// 0x13173c0
void bilManagerShutdown(dds3ProcessID_t **id) {
    bilDeleteHandle(0);
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
}

// 0x13143a0
void bilSetScl(bilInstance_s **h, f32 x, f32 y, f32 z) {
}

// 0x1316610
void bilSetSize(bilInstance_s **h, f32 x, f32 y, f32 z) {
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
