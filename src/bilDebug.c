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
    bilGetHandle(0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
}

// 0x1313f30
dds3ProcessFunc_t *bilTestProcess(dds3ProcessID_t *id) {
    sdfCos(0);
    sdfSin(0);
    bilDraw(0);
    return 0;
}

// 0x1314760
void bilTestShutdown(dds3ProcessID_t *id) {
    bilDeleteHandle(0);
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
