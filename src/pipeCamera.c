#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct tagPipeObject tagPipeObject;

static void *pipeCameraObj;
static void *pipeCameraCtrl;
static sdfVector4_t pipeVertical;
static sdfVector4_t pipeCameraPos;
static sdfVector4_t pipeTargetPos;
static dds3Basic_t *pipe_Camera;

void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SetCamera(void);
void SetVec(sdfVector4_t *pVec, f32 x, f32 y, f32 z);
f32 VecNormalize(sdfVector4_t *pVec);
void VecRotateX(sdfVector4_t *pVec, f32 Radian);
void VecZoom(sdfVector4_t *pVec, f32 s);
void Veccross(sdfVector4_t *vec, sdfVector4_t vec1, sdfVector4_t vec2);
f32 Vecdot(sdfVector4_t vec1, sdfVector4_t vec2);
dds3Basic_t *dds3AddCameraObjectBasicTypeLookAt(u32 serialID, sdfVector4_t eyePos, sdfVector4_t targetPos, sdfVector4_t vertical);
void dds3CameraObjectBasicGetTgtCam(dds3Basic_t **pBasic, sdfVector4_t *tgtpos, sdfVector4_t *campos);
void dds3CameraObjectBasicSetTargetPos(dds3Basic_t **pBasic, sdfVector4_t targetPos);
dds3Basic_t *dds3GetActiveScene(void);
u32 dds3SerializeID(void);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetBasicName(dds3Basic_t **basic, char *name);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius);
void dds3SetScreenFovy(f32 fovy);
void getPosTranslate(tagPipeObject *objPtr, sdfVector4_t *pos);
tagPipeObject *objMyData(void);
f32 sdfFabs(f32 c);
f32 sdfSqrt(f32 aValue);

// 0x14b7e80
void AddCamera(void) {
  s64 v3;
  u32 v5;
  struct dds3Basic_t_o *v7;
  dds3Basic_t_o *pSceneBasic;
  UnityEngine_Vector4_o v14;

  pSceneBasic = 0;
  v5 = dds3SerializeID();
  *&v14.x = 0;
  *&v14.z = v3;
  v7 = dds3AddCameraObjectBasicTypeLookAt(v5, pipeCameraPos, pipeTargetPos, v14);
  pipe_Camera = v7;
  dds3SetBasicName(&pipe_Camera, StringLiteral_21885);
  dds3CameraObjectBasicSetTargetPos(&pipe_Camera, pipeTargetPos);
  dds3SetRadiusPoseSet(&pipe_Camera, 2.0);
  pSceneBasic = dds3GetActiveScene();
  dds3SetActiveCameraSceneBasic(&pSceneBasic, &pipe_Camera);
  dds3SetScreenFovy(0.87965);
  SetCamera();
}

// 0x14b8330
void CalcCamera(void) {
    dds3CameraObjectBasicSetTargetPos(0, (sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SetCamera();
}

// 0x14b7aa0
void CamActionQuake(void) {
    SetVec(0, 0, 0, 0);
    VecNormalize(0);
    VecZoom(0, 0);
}

// 0x14b4920
void PipeCamera(void) {
    objMyData();
    getPosTranslate(0, 0);
    SetVec(0, 0, 0, 0);
    VecNormalize(0);
    VecZoom(0, 0);
}

// 0x14b5130
void PipeCameraAction(void) {
    objMyData();
    getPosTranslate(0, 0);
    SetVec(0, 0, 0, 0);
    VecNormalize(0);
    VecZoom(0, 0);
    sdfSqrt(0);
    sdfFabs(0);
    VecRotateX(0, 0);
}

// 0x14b5f00
void PipeCameraAction2(void) {
    objMyData();
    getPosTranslate(0, 0);
    SetVec(0, 0, 0, 0);
    VecNormalize(0);
    VecZoom(0, 0);
}

// 0x14b6d40
void PipeCameraAction3(void) {
    objMyData();
    getPosTranslate(0, 0);
    SetVec(0, 0, 0, 0);
    VecNormalize(0);
    VecZoom(0, 0);
    sdfSqrt(0);
    sdfFabs(0);
    VecRotateX(0, 0);
}

// 0x14b8050
void SetCamera(void) {
  UnityEngine_Object_o *pipeCameraObj;
  UnityEngine_GameObject_o *v5;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  f32 v11;
  f32 v12;
  f32 v13;
  UnityEngine_Transform_o *transform;
  f32 v17;
  struct pipeCamera_StaticFields *static_fields;
  f32 w;
  f32 x;
  f32 y;
  f32 v22;
  f32 v23;
  f32 v24;
  UnityEngine_Transform_o *v25;
  UnityEngine_Transform_o *v26;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o campos;
  UnityEngine_Vector3_o v29;
  UnityEngine_Vector3_o v30;
  UnityEngine_Vector3_o v31;
  UnityEngine_Vector4_o v32;

  *&campos.x = 0;
  *&campos.z = 0;
  *&zero.x = 0;
  *&zero.z = 0;
  v5 = Find(StringLiteral_5605, 0);
  gameObject = get_gameObject(v5);
  pipeCameraObj = gameObject;
  Component_object = GetComponent_object_(pipeCameraObj);
  pipeCameraCtrl = Component_object;
  campos = get_zero();
  zero = get_zero();
  dds3CameraObjectBasicGetTgtCam(&pipe_Camera, &zero, &campos);
  v11 = campos.x / 100.0;
  v12 = campos.y / -100.0;
  v13 = campos.z / 100.0;
  transform = get_transform(pipeCameraObj, 0);
  v29.x = v11;
  v29.y = v12;
  v29.z = v13;
  set_localPosition(transform, v29);
  set_fieldOfView(
    pipeCameraCtrl,
    (dds3ScreenParam->fovy * 360.0) / 6.2832,
    0);
  v17 = zero.y / -100.0;
  static_fields = pipeCamera->static_fields;
  w = static_fields->pipeVertical.w;
  x = static_fields->pipeVertical.x;
  y = static_fields->pipeVertical.y;
  v22 = -static_fields->pipeVertical.z;
  v23 = zero.x / 100.0;
  v24 = zero.z / 100.0;
  v25 = get_transform(static_fields->pipeCameraObj, 0);
  v32.x = x;
  v32.y = y;
  v32.z = v22;
  v32.w = w;
  v26 = v25;
  v31 = op_Implicit_8738992(v32);
  v30.x = v23;
  v30.y = v17;
  v30.z = v24;
  LookAt_27488480(v26, v30, v31);
}

// 0x14b45c0
void getViewPortMatrix(sdfMatrix4_t **mat) {
    VecNormalize(0);
    Veccross(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    Vecdot((sdfVector4_t){0}, (sdfVector4_t){0});
}

// 0x14b8520
s8 pipeCamGetMode(s32 mapIdx, s32 prevArea) {
  s8 result;
  bool v5;

  result = 1;
  switch (prevArea)
  {
    case ')':
      return mapIdx == 1;
    case '*':
      v5 = mapIdx < 4;
    case '+':
      v5 = mapIdx < 6;
    case ',':
      v5 = mapIdx < 8;
      result = v5;
      break;
    case '-':
      return result;
    default:
      result = 0;
      break;
  }
  return result;
}
