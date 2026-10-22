#include "types.h"

void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
f32 sdfCos(f32 aRadius);
f32 sdfSin(f32 aRadius);
void sdfVu0MultMatrixNoArg(void);
void sdfVu0SetRotateMatrixX_B(f32 aAngle);
void sdfVu0SetRotateMatrixY(f32 aAngle);

// 0x1641ef0
void pbMoveCameraEye(sdfVector4_t eye) {
  s64 p_dds3CameraEyePos;
  s64 v7;
  s64 v10;
  UnityEngine_Vector4_o v11;

  v11 = eye;
  p_dds3CameraEyePos = &dds3CameraEyePos;
  sub_854710(p_dds3CameraEyePos, 0);
  sub_854710(&v11, 0);
  sub_854930(p_dds3CameraEyePos, 0);
  v7 = &dds3CameraEyePos;
  sub_854710(v7, 1u);
  sub_854710(&v11, 1u);
  sub_854930(v7, 1u);
  v10 = &dds3CameraEyePos;
  sub_854710(v10, 2u);
  sub_854710(&v11, 2u);
  sub_854930(v10, 2u);
}

// 0x1642060
void pbRotateXCamera(f32 angle) {
  UnityEngine_Vector4_o v6;

  *&v6.x = 0;
  *&v6.z = 0;
  SDF_VU0__COPYVECTOR(&v6, dds3CameraEyePos);
  sub_854710(&v6, 1u);
  sub_854710(&dds3CameraTargetPos, 1u);
  sub_854930(&v6, 1u);
  sub_854710(&v6, 2u);
  sub_854710(&dds3CameraTargetPos, 2u);
  sub_854930(&v6, 2u);
  sdfCos(angle);
  sub_854710(&v6, 1u);
  sdfSin(angle);
  sub_854710(&v6, 2u);
  sdfSin(angle);
  sub_854710(&v6, 1u);
  sdfCos(angle);
  sub_854710(&v6, 2u);
  sub_854710(&dds3CameraTargetPos, 1u);
  sub_854930(&dds3CameraEyePos, 1u);
  sub_854710(&dds3CameraTargetPos, 2u);
  sub_854930(&dds3CameraEyePos, 2u);
}

// 0x16422a0
void pbRotateYCamera(f32 angle) {
  UnityEngine_Vector4_o v6;

  *&v6.x = 0;
  *&v6.z = 0;
  SDF_VU0__COPYVECTOR(&v6, dds3CameraEyePos);
  sub_854710(&v6, 0);
  sub_854710(&dds3CameraTargetPos, 0);
  sub_854930(&v6, 0);
  sub_854710(&v6, 2u);
  sub_854710(&dds3CameraTargetPos, 2u);
  sub_854930(&v6, 2u);
  sdfCos(angle);
  sub_854710(&v6, 0);
  sdfSin(angle);
  sub_854710(&v6, 2u);
  sdfSin(angle);
  sub_854710(&v6, 0);
  sdfCos(angle);
  sub_854710(&v6, 2u);
  sub_854710(&dds3CameraTargetPos, 0);
  sub_854930(&dds3CameraEyePos, 0);
  sub_854710(&dds3CameraTargetPos, 2u);
  sub_854930(&dds3CameraEyePos, 2u);
}

// 0x1642720
void pbRotateYCamera2(f32 angle, f32 radius, f32 degree) {
  UnityEngine_Vector4_o v8;

  *&v8.x = 0;
  *&v8.z = 0;
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  sub_854930(&v8, 3u);
  sdfVu0SetRotateMatrixY(angle);
  sdfVu0SetRotateMatrixX_B(-degree);
  sdfVu0MultMatrixNoArg();
  SDF_VU0__LOADVECTOR(v8);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&v8);
  sub_854710(&v8, 0);
  sub_854710(&dds3CameraTargetPos, 0);
  sub_854930(&dds3CameraEyePos, 0);
  sub_854710(&v8, 1u);
  sub_854710(&dds3CameraTargetPos, 1u);
  sub_854930(&dds3CameraEyePos, 1u);
  sub_854710(&v8, 2u);
  sub_854710(&dds3CameraTargetPos, 2u);
  sub_854930(&dds3CameraEyePos, 2u);
}

// 0x16424e0
void pbRotateZCamera(f32 angle) {
  UnityEngine_Vector4_o v6;

  *&v6.x = 0;
  *&v6.z = 0;
  SDF_VU0__COPYVECTOR(&v6, dds3CameraEyePos);
  sub_854710(&v6, 0);
  sub_854710(&dds3CameraTargetPos, 0);
  sub_854930(&v6, 0);
  sub_854710(&v6, 1u);
  sub_854710(&dds3CameraTargetPos, 1u);
  sub_854930(&v6, 1u);
  sdfCos(angle);
  sub_854710(&v6, 0);
  sdfSin(angle);
  sub_854710(&v6, 1u);
  sdfSin(angle);
  sub_854710(&v6, 0);
  sdfCos(angle);
  sub_854710(&v6, 1u);
  sub_854710(&dds3CameraTargetPos, 0);
  sub_854930(&dds3CameraEyePos, 0);
  sub_854710(&dds3CameraTargetPos, 1u);
  sub_854930(&dds3CameraEyePos, 1u);
}
