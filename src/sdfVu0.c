#include "types.h"

static sdfMatrix4_t sdfIdentityMatrix;
static sdfVector4_t sdfAllOneVector;

void MultMatrixNoArg(void);
void MultMatrixRevNoArg(void);
void ReverseMatrix(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYMATRIX_A_TO_B(void);
void SDF_VU0__COPYMATRIX_A_TO_C(void);
void SDF_VU0__COPYMATRIX_B_TO_A(void);
void SDF_VU0__COPYMATRIX_B_TO_C(void);
void SDF_VU0__COPYMATRIX_C_TO_A(void);
void SDF_VU0__COPYMATRIX_C_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__GET_ROW2(void);
f32 SDF_VU0__INNERPRODUCT(void);
void SDF_VU0__LOADIDENTITY(void);
void SDF_VU0__LOADIDENTITY_B(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__SET_ROW0(void);
void SDF_VU0__SET_ROW1(void);
void SDF_VU0__SET_ROW2(void);
void SDF_VU0__SET_ROW3(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetRotateMatrixX(f32 aAngle);
void SetRotateMatrixY_B(f32 aAngle);
void SetRotateMatrixZ_B(f32 aAngle);
void StoreRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis, sdfMatrix4_t *aMtx);
f32 sdfCos(f32 aRadius);
f32 sdfSin(f32 aRadius);

// 0x15d7cf0
void ApplyMatrix(sdfVector4_t *aReVector, sdfVector4_t aVector) {
  SDF_VU0__LOADVECTOR(aVector);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(aReVector);
}

// 0x15d5a50
void CopyMatrixAtoB(void) {
  SDF_VU0__COPYMATRIX_A_TO_B();
}

// 0x15d5a60
void CopyMatrixAtoC(void) {
  SDF_VU0__COPYMATRIX_A_TO_C();
}

// 0x15d5a70
void CopyMatrixBtoA(void) {
  SDF_VU0__COPYMATRIX_B_TO_A();
}

// 0x15d5a80
void CopyMatrixBtoC(void) {
  SDF_VU0__COPYMATRIX_B_TO_C();
}

// 0x15d5a90
void CopyMatrixCtoA(void) {
  SDF_VU0__COPYMATRIX_C_TO_A();
}

// 0x15d5aa0
void CopyMatrixCtoB(void) {
  SDF_VU0__COPYMATRIX_C_TO_B();
}

// 0x15d5ae0
void DiagMatrix(void) {
}

// 0x15d7f70
void Init(void) {
  ;
}

// 0x15d7d30
f32 InnerProduct(sdfVector4_t aVectorA, sdfVector4_t aVectorB) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o v8;

  w = aVectorB.w;
  z = aVectorB.z;
  y = aVectorB.y;
  x = aVectorB.x;
  SDF_VU0__LOADVECTOR(aVectorA);
  v8.x = x;
  v8.y = y;
  v8.z = z;
  v8.w = w;
  SDF_VU0__LOADVECTOR_B(v8);
  return SDF_VU0__INNERPRODUCT();
}

// 0x15d5df0
void InversMatrix(void) {
}

// 0x15d5ab0
void LoadIdentity(void) {
  SDF_VU0__LOADIDENTITY();
}

// 0x15d5ac0
void LoadIdentity_B(void) {
  SDF_VU0__LOADIDENTITY_B();
}

// 0x15d5990
void LoadMatrix(sdfMatrix4_t *aMatrix) {
  s64 v2;
  s64 v3;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  UnityEngine_Matrix4x4_o v8;

  v2 = *&aMatrix->m00;
  v3 = *&aMatrix->m20;
  v4 = *&aMatrix->m21;
  *&v8.m01 = *&aMatrix->m01;
  *&v8.m21 = v4;
  *&v8.m00 = v2;
  *&v8.m20 = v3;
  v5 = *&aMatrix->m02;
  v6 = *&aMatrix->m22;
  v7 = *&aMatrix->m23;
  *&v8.m03 = *&aMatrix->m03;
  *&v8.m23 = v7;
  *&v8.m02 = v5;
  *&v8.m22 = v6;
  SDF_VU0__LOADMATRIX(&v8);
}

// 0x15d59e0
void LoadMatrix_B(sdfMatrix4_t *aMatrix) {
  s64 v2;
  s64 v3;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  UnityEngine_Matrix4x4_o v8;

  v2 = *&aMatrix->m00;
  v3 = *&aMatrix->m20;
  v4 = *&aMatrix->m21;
  *&v8.m01 = *&aMatrix->m01;
  *&v8.m21 = v4;
  *&v8.m00 = v2;
  *&v8.m20 = v3;
  v5 = *&aMatrix->m02;
  v6 = *&aMatrix->m22;
  v7 = *&aMatrix->m23;
  *&v8.m03 = *&aMatrix->m03;
  *&v8.m23 = v7;
  *&v8.m02 = v5;
  *&v8.m22 = v6;
  SDF_VU0__LOADMATRIX_B(&v8);
}

// 0x15d7e00
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown) {
  f32 x;
  f32 w;
  f32 z;
  f32 y;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  s64 v14;
  s64 v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;

  x = aTarget.x;
  w = aEye.w;
  z = aEye.z;
  y = aEye.y;
  v8 = aEye.x;
  v9 = aTarget.w;
  v10 = aTarget.z;
  v11 = aTarget.y;
  v16.x = v8;
  v16.y = y;
  v16.z = z;
  v16.w = w;
  SDF_VU0__LOADVECTOR(v16);
  SDF_VU0__SET_ROW3();
  SDF_VU0__COPYVECTOR_A_TO_B();
  v17.x = x;
  v17.y = v11;
  v17.z = v10;
  v17.w = v9;
  SDF_VU0__LOADVECTOR(v17);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__SET_ROW2();
  SDF_VU0__COPYVECTOR_A_TO_B();
  *&v18.x = v14;
  *&v18.z = v15;
  SDF_VU0__LOADVECTOR(v18);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__SET_ROW0();
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__GET_ROW2();
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__SET_ROW1();
  ReverseMatrix();
}

// 0x15d7bb0
void MultMatrix(sdfMatrix4_t *aMatrix) {
  s64 v3;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  UnityEngine_Matrix4x4_o v11;

  v3 = *&aMatrix->m00;
  v4 = *&aMatrix->m20;
  v5 = *&aMatrix->m21;
  *&v11.m01 = *&aMatrix->m01;
  *&v11.m21 = v5;
  *&v11.m00 = v3;
  *&v11.m20 = v4;
  v6 = *&aMatrix->m02;
  v7 = *&aMatrix->m22;
  v8 = *&aMatrix->m23;
  *&v11.m03 = *&aMatrix->m03;
  *&v11.m23 = v8;
  *&v11.m02 = v6;
  *&v11.m22 = v7;
  SDF_VU0__LOADMATRIX_B(&v11);
  MultMatrixNoArg();
}

// 0x15d77c0
void MultMatrixNoArg(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  struct sdf_vu0r_StaticFields *static_fields;
  s64 v21;
  s64 v22;
  s64 v23;
  UnityEngine_Matrix4x4_o v24;
  UnityEngine_Matrix4x4_o v25;
  UnityEngine_Matrix4x4_o v26;
  UnityEngine_Matrix4x4_o v27;
  UnityEngine_Matrix4x4_o v28;

  p_x = &vf00.x;
  v4 = p_x[16];
  v5 = p_x[17];
  v6 = p_x[19];
  *&v28.m01 = p_x[18];
  *&v28.m21 = v6;
  *&v28.m00 = v4;
  *&v28.m20 = v5;
  v7 = p_x[20];
  v8 = p_x[21];
  v9 = p_x[23];
  *&v28.m03 = p_x[22];
  *&v28.m23 = v9;
  *&v28.m02 = v7;
  *&v28.m22 = v8;
  v10 = p_x[8];
  v11 = p_x[9];
  v12 = p_x[11];
  *&v27.m01 = p_x[10];
  *&v27.m21 = v12;
  *&v27.m00 = v10;
  *&v27.m20 = v11;
  v13 = p_x[12];
  v14 = p_x[13];
  v16 = p_x[14];
  v15 = p_x[15];
  *&v27.m03 = v16;
  *&v27.m23 = v15;
  *&v27.m02 = v13;
  *&v27.m22 = v14;
  v25 = v28;
  v24 = v27;
  op_Multiply(&v26, &v25, &v24, 0);
  v18 = *&v26.m00;
  v17 = *&v26.m20;
  v19 = *&v26.m21;
  static_fields = sdf_vu0r->static_fields;
  *&static_fields->mtx_A.m01 = *&v26.m01;
  *&static_fields->mtx_A.m21 = v19;
  *&static_fields->mtx_A.m00 = v18;
  *&static_fields->mtx_A.m20 = v17;
  v22 = *&v26.m02;
  v21 = *&v26.m22;
  v23 = *&v26.m23;
  *&static_fields->mtx_A.m03 = *&v26.m03;
  *&static_fields->mtx_A.m23 = v23;
  *&static_fields->mtx_A.m02 = v22;
  *&static_fields->mtx_A.m22 = v21;
}

// 0x15d7910
void MultMatrixNoArg_C(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  struct sdf_vu0r_StaticFields *static_fields;
  s64 v21;
  s64 v22;
  s64 v23;
  UnityEngine_Matrix4x4_o v24;
  UnityEngine_Matrix4x4_o v25;
  UnityEngine_Matrix4x4_o v26;
  UnityEngine_Matrix4x4_o v27;
  UnityEngine_Matrix4x4_o v28;

  p_x = &vf00.x;
  v4 = p_x[24];
  v5 = p_x[25];
  v6 = p_x[27];
  *&v28.m01 = p_x[26];
  *&v28.m21 = v6;
  *&v28.m00 = v4;
  *&v28.m20 = v5;
  v7 = p_x[28];
  v8 = p_x[29];
  v9 = p_x[31];
  *&v28.m03 = p_x[30];
  *&v28.m23 = v9;
  *&v28.m02 = v7;
  *&v28.m22 = v8;
  v10 = p_x[8];
  v11 = p_x[9];
  v12 = p_x[11];
  *&v27.m01 = p_x[10];
  *&v27.m21 = v12;
  *&v27.m00 = v10;
  *&v27.m20 = v11;
  v13 = p_x[12];
  v14 = p_x[13];
  v16 = p_x[14];
  v15 = p_x[15];
  *&v27.m03 = v16;
  *&v27.m23 = v15;
  *&v27.m02 = v13;
  *&v27.m22 = v14;
  v25 = v28;
  v24 = v27;
  op_Multiply(&v26, &v25, &v24, 0);
  v18 = *&v26.m00;
  v17 = *&v26.m20;
  v19 = *&v26.m21;
  static_fields = sdf_vu0r->static_fields;
  *&static_fields->mtx_A.m01 = *&v26.m01;
  *&static_fields->mtx_A.m21 = v19;
  *&static_fields->mtx_A.m00 = v18;
  *&static_fields->mtx_A.m20 = v17;
  v22 = *&v26.m02;
  v21 = *&v26.m22;
  v23 = *&v26.m23;
  *&static_fields->mtx_A.m03 = *&v26.m03;
  *&static_fields->mtx_A.m23 = v23;
  *&static_fields->mtx_A.m02 = v22;
  *&static_fields->mtx_A.m22 = v21;
}

// 0x15d7c50
void MultMatrixRev(sdfMatrix4_t *aMatrix) {
  s64 v3;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  UnityEngine_Matrix4x4_o v11;

  v3 = *&aMatrix->m00;
  v4 = *&aMatrix->m20;
  v5 = *&aMatrix->m21;
  *&v11.m01 = *&aMatrix->m01;
  *&v11.m21 = v5;
  *&v11.m00 = v3;
  *&v11.m20 = v4;
  v6 = *&aMatrix->m02;
  v7 = *&aMatrix->m22;
  v8 = *&aMatrix->m23;
  *&v11.m03 = *&aMatrix->m03;
  *&v11.m23 = v8;
  *&v11.m02 = v6;
  *&v11.m22 = v7;
  SDF_VU0__LOADMATRIX_B(&v11);
  MultMatrixRevNoArg();
}

// 0x15d7670
void MultMatrixRevNoArg(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  struct sdf_vu0r_StaticFields *static_fields;
  s64 v21;
  s64 v22;
  s64 v23;
  UnityEngine_Matrix4x4_o v24;
  UnityEngine_Matrix4x4_o v25;
  UnityEngine_Matrix4x4_o v26;
  UnityEngine_Matrix4x4_o v27;
  UnityEngine_Matrix4x4_o v28;

  p_x = &vf00.x;
  v4 = p_x[8];
  v5 = p_x[9];
  v6 = p_x[11];
  *&v28.m01 = p_x[10];
  *&v28.m21 = v6;
  *&v28.m00 = v4;
  *&v28.m20 = v5;
  v7 = p_x[12];
  v8 = p_x[13];
  v9 = p_x[15];
  *&v28.m03 = p_x[14];
  *&v28.m23 = v9;
  *&v28.m02 = v7;
  *&v28.m22 = v8;
  v10 = p_x[16];
  v11 = p_x[17];
  v12 = p_x[19];
  *&v27.m01 = p_x[18];
  *&v27.m21 = v12;
  *&v27.m00 = v10;
  *&v27.m20 = v11;
  v13 = p_x[20];
  v14 = p_x[21];
  v16 = p_x[22];
  v15 = p_x[23];
  *&v27.m03 = v16;
  *&v27.m23 = v15;
  *&v27.m02 = v13;
  *&v27.m22 = v14;
  v25 = v28;
  v24 = v27;
  op_Multiply(&v26, &v25, &v24, 0);
  v18 = *&v26.m00;
  v17 = *&v26.m20;
  v19 = *&v26.m21;
  static_fields = sdf_vu0r->static_fields;
  *&static_fields->mtx_A.m01 = *&v26.m01;
  *&static_fields->mtx_A.m21 = v19;
  *&static_fields->mtx_A.m00 = v18;
  *&static_fields->mtx_A.m20 = v17;
  v22 = *&v26.m02;
  v21 = *&v26.m22;
  v23 = *&v26.m23;
  *&static_fields->mtx_A.m03 = *&v26.m03;
  *&static_fields->mtx_A.m23 = v23;
  *&static_fields->mtx_A.m02 = v22;
  *&static_fields->mtx_A.m22 = v21;
}

// 0x15d7a60
void MultMatrixRevNoArg_C(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  struct sdf_vu0r_StaticFields *static_fields;
  s64 v21;
  s64 v22;
  s64 v23;
  UnityEngine_Matrix4x4_o v24;
  UnityEngine_Matrix4x4_o v25;
  UnityEngine_Matrix4x4_o v26;
  UnityEngine_Matrix4x4_o v27;
  UnityEngine_Matrix4x4_o v28;

  p_x = &vf00.x;
  v4 = p_x[8];
  v5 = p_x[9];
  v6 = p_x[11];
  *&v28.m01 = p_x[10];
  *&v28.m21 = v6;
  *&v28.m00 = v4;
  *&v28.m20 = v5;
  v7 = p_x[12];
  v8 = p_x[13];
  v9 = p_x[15];
  *&v28.m03 = p_x[14];
  *&v28.m23 = v9;
  *&v28.m02 = v7;
  *&v28.m22 = v8;
  v10 = p_x[24];
  v11 = p_x[25];
  v12 = p_x[27];
  *&v27.m01 = p_x[26];
  *&v27.m21 = v12;
  *&v27.m00 = v10;
  *&v27.m20 = v11;
  v13 = p_x[28];
  v14 = p_x[29];
  v16 = p_x[30];
  v15 = p_x[31];
  *&v27.m03 = v16;
  *&v27.m23 = v15;
  *&v27.m02 = v13;
  *&v27.m22 = v14;
  v25 = v28;
  v24 = v27;
  op_Multiply(&v26, &v25, &v24, 0);
  v18 = *&v26.m00;
  v17 = *&v26.m20;
  v19 = *&v26.m21;
  static_fields = sdf_vu0r->static_fields;
  *&static_fields->mtx_A.m01 = *&v26.m01;
  *&static_fields->mtx_A.m21 = v19;
  *&static_fields->mtx_A.m00 = v18;
  *&static_fields->mtx_A.m20 = v17;
  v22 = *&v26.m02;
  v21 = *&v26.m22;
  v23 = *&v26.m23;
  *&static_fields->mtx_A.m03 = *&v26.m03;
  *&static_fields->mtx_A.m23 = v23;
  *&static_fields->mtx_A.m02 = v22;
  *&static_fields->mtx_A.m22 = v21;
}

// 0x15d7d90
void OuterProduct(sdfVector4_t *aReVector, sdfVector4_t aVectorA, sdfVector4_t aVectorB) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o v9;

  w = aVectorB.w;
  z = aVectorB.z;
  y = aVectorB.y;
  x = aVectorB.x;
  SDF_VU0__LOADVECTOR(aVectorA);
  v9.x = x;
  v9.y = y;
  v9.z = z;
  v9.w = w;
  SDF_VU0__LOADVECTOR_B(v9);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__STOREVECTOR(aReVector);
}

// 0x15d5b90
void ReverseMatrix(void) {
}

// 0x15d6ea0
void RotateMatrixX(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
}

// 0x15d70f0
void RotateMatrixY(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
}

// 0x15d7340
void RotateMatrixZ(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
}

// 0x15d6900
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o aMtx;
  UnityEngine_Vector4_o v11;

  w = aAxis.w;
  z = aAxis.z;
  y = aAxis.y;
  x = aAxis.x;
  memset(&aMtx, 0, sizeof(aMtx));
  v11.x = x;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  StoreRotateMatrixAxis(aAngle, v11, &aMtx);
  v9 = aMtx;
  SDF_VU0__LOADMATRIX(&v9);
}

// 0x15d6db0
void SetRotateMatrixAxis_B(f32 aAngle, sdfVector4_t aAxis) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o aMtx;
  UnityEngine_Vector4_o v11;

  w = aAxis.w;
  z = aAxis.z;
  y = aAxis.y;
  x = aAxis.x;
  memset(&aMtx, 0, sizeof(aMtx));
  v11.x = x;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  StoreRotateMatrixAxis(aAngle, v11, &aMtx);
  v9 = aMtx;
  SDF_VU0__LOADMATRIX_B(&v9);
}

// 0x15d6230
void SetRotateMatrixX(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__STOREIDENTITY(0);
    SDF_VU0__LOADMATRIX(0);
}

// 0x15d7590
void SetRotateMatrixXYZ(f32 **aAngles) {
  f32 v5;

  v5 = aAngles->m_Items[0];
  SetRotateMatrixX(v5);
  SetRotateMatrixY_B(aAngles->m_Items[1]);
  MultMatrixRevNoArg();
  SetRotateMatrixZ_B(aAngles->m_Items[2]);
  MultMatrixRevNoArg();
}

// 0x15d69f0
void SetRotateMatrixX_B(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__STOREIDENTITY(0);
    SDF_VU0__LOADMATRIX_B(0);
}

// 0x15d6370
void SetRotateMatrixY(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__STOREIDENTITY(0);
    SDF_VU0__LOADMATRIX(0);
}

// 0x15d6b30
void SetRotateMatrixY_B(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__STOREIDENTITY(0);
    SDF_VU0__LOADMATRIX_B(0);
}

// 0x15d64b0
void SetRotateMatrixZ(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__STOREIDENTITY(0);
    SDF_VU0__LOADMATRIX(0);
}

// 0x15d6c70
void SetRotateMatrixZ_B(f32 aAngle) {
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__STOREIDENTITY(0);
    SDF_VU0__LOADMATRIX_B(0);
}

// 0x15d5ad0
void StoreIdentity(sdfMatrix4_t *aMatrix) {
  SDF_VU0__STOREIDENTITY(aMatrix);
}

// 0x15d5a30
void StoreMatrix(sdfMatrix4_t *aMatrix) {
  SDF_VU0__STOREMATRIX(aMatrix);
}

// 0x15d5a40
void StoreMatrix_B(sdfMatrix4_t *aMatrix) {
  SDF_VU0__STOREMATRIX_B(aMatrix);
}

// 0x15d65f0
void StoreRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis, sdfMatrix4_t *aMtx) {
    sdfSin(0);
    sdfCos(0);
}

// 0x15d5980
void sdfVu0LoadMatrix(sdfMatrix4_t *aMatrix) {
  ;
}

// 0x15d5950
void sdfVu0MultMatrixNoArg(void) {
  ;
}

// 0x15d5960
void sdfVu0SetRotateMatrixXYZ(f32 **aAngles) {
  ;
}

// 0x15d5940
void sdfVu0SetRotateMatrixX_B(f32 aAngle) {
  ;
}

// 0x15d5930
void sdfVu0SetRotateMatrixY(f32 aAngle) {
  ;
}

// 0x15d5970
void sdfVu0StoreMatrix(sdfMatrix4_t *aMatrix) {
  ;
}
