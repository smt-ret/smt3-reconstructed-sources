#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;

void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void MakeCamera(dds3Basic_t **pBasic);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void ToMatrix(void);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3SetScreenFovy(f32 fovy);

// 0x15243e0
s32 CameraObjectBasicConstructor(dds3Basic_t *pBasic) {
    dds3InitPoseSet(0);
    dds3ObjectBaseInitControlWorkData(0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    return 0;
}

// 0x1524540
s32 CameraObjectBasicDestructor(dds3Basic_t *pBasic) {
    dds3ObjectBaseFreeControlWorkData(0);
    return 0;
}

// 0x1524b50
s32 CameraObjectBasicDrawprocuder(dds3Basic_t *pBasic) {
  return 1;
}

// 0x1524670
s32 CameraObjectBasicMainprocuder(dds3Basic_t *pBasic) {
    MakeCamera(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3GetControlScene();
    dds3GetActiveCameraSceneBasic(0);
    dds3SetScreenFovy(0);
    return 0;
}

// 0x1524930
void MakeCamera(dds3Basic_t **pBasic) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__STOREMATRIX(0);
}

// 0x1525260
dds3Basic_t *dds3AddCameraObjectBasic(u32 serialID, sdfVector4_t eyePos, sdfVector4_t eyeVector, sdfVector4_t vertical, f32 fovy, u32 mode) {
    dds3AddSceneBasicData(0);
    dds3ObjectBaseCreateMover(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    MakeCamera(0);
    return 0;
}

// 0x1524c50
dds3Basic_t *dds3AddCameraObjectBasicDef(u32 serialID) {
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  pObjectBasic = dds3AddSceneBasicData(4u);
  pObjectBasic->serialID = serialID;
  dds3ObjectBaseCreateMover(&pObjectBasic);
  return pObjectBasic;
}

// 0x1524ce0
dds3Basic_t *dds3AddCameraObjectBasicTypeFree(u32 serialID, sdfVector4_t pos, sdfVector4_t rot) {
    dds3AddSceneBasicData(0);
    dds3ObjectBaseCreateMover(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    MakeCamera(0);
    return 0;
}

// 0x1524fd0
dds3Basic_t *dds3AddCameraObjectBasicTypeLookAt(u32 serialID, sdfVector4_t eyePos, sdfVector4_t targetPos, sdfVector4_t vertical) {
    dds3AddSceneBasicData(0);
    dds3ObjectBaseCreateMover(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    MakeCamera(0);
    return 0;
}

// 0x1525e90
void dds3CameraObjectBasicAlterMode(dds3Basic_t **pBasic, u32 mode) {
}

// 0x15255a0
void dds3CameraObjectBasicGetCameraTM(dds3Basic_t **pBasic) {
    SDF_VU0__LOADMATRIX(0);
}

// 0x1524b60
dds3ObjectBaseControlWorkData_t *dds3CameraObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
    return 0;
}

// 0x1525ad0
f32 dds3CameraObjectBasicGetFovy(dds3Basic_t **pBasic) {
    return 0;
}

// 0x1525da0
u32 dds3CameraObjectBasicGetMode(dds3Basic_t **pBasic) {
    return 0;
}

// 0x15257e0
void dds3CameraObjectBasicGetTargetPos(dds3Basic_t **pBasic) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
}

// 0x1525bc0
void dds3CameraObjectBasicGetTgtCam(dds3Basic_t **pBasic, sdfVector4_t *tgtpos, sdfVector4_t *campos) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
}

// 0x15258d0
void dds3CameraObjectBasicSetFovy(dds3Basic_t **pBasic, f32 fovy) {
}

// 0x15259d0
void dds3CameraObjectBasicSetFovy2(dds3Basic_t **pBasic, f32 fovy) {
}

// 0x15256b0
void dds3CameraObjectBasicSetTargetPos(dds3Basic_t **pBasic, sdfVector4_t targetPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1525530
void dds3DeleteCameraObjectBasic(dds3Basic_t **pBasic) {
  dds3DeleteSceneBasicData(pBasic);
}
