#include "types.h"

typedef struct sdf3DScreenParam_t sdf3DScreenParam_t;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfIVector3_t sdfIVector3_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelExtraChunkMarkPos_t sdfModelExtraChunkMarkPos_t;
typedef struct sdfModelExtraChunk_t sdfModelExtraChunk_t;
typedef struct sdfModelNodeDef_t sdfModelNodeDef_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfPacDecodeCb_t sdfPacDecodeCb_t;
typedef struct sdfPacStdBlockHeader_t sdfPacStdBlockHeader_t;

f32 Byte2Float(u8 **data, s32 pos);
u16 Byte2UInt16(u8 **bytedata, s32 pos);
u32 Byte2UInt32(u8 **bytedata, s32 pos);
void SDF_VU0__ClipTest(sdfVector4_t reg);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__SCALE_XYZ(void);

// 0x15abf30
void SDF_VU0__ADDVECTOR(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  v8 = p_x[8];
  v9 = p_x[9];
  v11 = p_x[10];
  v10 = p_x[11];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_A = op_Addition(v12, v13);
}

// 0x15ac020
void SDF_VU0__ADDVECTOR_A_C(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  v8 = p_x[12];
  v9 = p_x[13];
  v11 = p_x[14];
  v10 = p_x[15];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_A = op_Addition(v12, v13);
}

// 0x15ac110
void SDF_VU0__ADDVECTOR_B_A(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[8];
  v5 = p_x[9];
  v6 = p_x[10];
  v7 = p_x[11];
  v8 = p_x[4];
  v9 = p_x[5];
  v11 = p_x[6];
  v10 = p_x[7];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_B = op_Addition(v12, v13);
}

// 0x15ac2f0
void SDF_VU0__ADDVECTOR_B_C(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[8];
  v5 = p_x[9];
  v6 = p_x[10];
  v7 = p_x[11];
  v8 = p_x[12];
  v9 = p_x[13];
  v11 = p_x[14];
  v10 = p_x[15];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_B = op_Addition(v12, v13);
}

// 0x15ac200
void SDF_VU0__ADDVECTOR_C_A(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[12];
  v5 = p_x[13];
  v6 = p_x[14];
  v7 = p_x[15];
  v8 = p_x[4];
  v9 = p_x[5];
  v11 = p_x[6];
  v10 = p_x[7];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_C = op_Addition(v12, v13);
}

// 0x15acd20
void SDF_VU0__APPLYMATRIX(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Vector4_o v11;

  sub_19FF440(&mtx_A, 0, &v10);
  x = vct_A.x;
  y = vct_A.y;
  z = vct_A.z;
  w = vct_A.w;
  v11.x = x;
  v9 = v10;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  vct_A = op_Multiply_27264976(&v9, v11);
}

// 0x15acf30
void SDF_VU0__APPLYMATRIX_B(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Vector4_o v11;

  sub_19FF440(&mtx_A, 0, &v10);
  x = vct_B.x;
  y = vct_B.y;
  z = vct_B.z;
  w = vct_B.w;
  v11.x = x;
  v9 = v10;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  vct_B = op_Multiply_27264976(&v9, v11);
}

// 0x15ad280
void SDF_VU0__APPLYMATRIX_XYZ(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Vector4_o v11;

  vct_A.w = 0.0;
  sub_19FF440(&mtx_A, 0, &v10);
  x = vct_A.x;
  y = vct_A.y;
  z = vct_A.z;
  w = vct_A.w;
  v11.x = x;
  v9 = v10;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  vct_A = op_Multiply_27264976(&v9, v11);
}

// 0x15ad040
void SDF_VU0__APPLYMATRIX_XYZ1(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Vector4_o v11;

  vct_A.w = 1.0;
  sub_19FF440(&mtx_A, 0, &v10);
  x = vct_A.x;
  y = vct_A.y;
  z = vct_A.z;
  w = vct_A.w;
  v11.x = x;
  v9 = v10;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  vct_A = op_Multiply_27264976(&v9, v11);
}

// 0x15ad160
void SDF_VU0__APPLYMATRIX_XYZ1_B(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Vector4_o v11;

  vct_B.w = 1.0;
  sub_19FF440(&mtx_A, 0, &v10);
  x = vct_B.x;
  y = vct_B.y;
  z = vct_B.z;
  w = vct_B.w;
  v11.x = x;
  v9 = v10;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  vct_B = op_Multiply_27264976(&v9, v11);
}

// 0x15ad390
void SDF_VU0__APPLYMATRIX_XYZ_B(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Vector4_o v11;

  vct_B.w = 0.0;
  sub_19FF440(&mtx_A, 0, &v10);
  x = vct_B.x;
  y = vct_B.y;
  z = vct_B.z;
  w = vct_B.w;
  v11.x = x;
  v9 = v10;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  vct_B = op_Multiply_27264976(&v9, v11);
}

// 0x15ae7f0
void SDF_VU0__CLIPTEST(void) {
  SDF_VU0__ClipTest(*&v2[2].klass->_1.name);
}

// 0x15ae8d0
void SDF_VU0__CLIPTESTWAIT(void) {
  ;
}

// 0x15ae860
void SDF_VU0__CLIPTEST_B(void) {
  SDF_VU0__ClipTest(v2[2].klass->_1.byval_arg);
}

// 0x15a9e90
void SDF_VU0__COPYMATRIX_A_TO_B(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;

  p_x = &vf00.x;
  v4 = p_x[11];
  p_x[18] = p_x[10];
  p_x[19] = v4;
  v5 = p_x[9];
  p_x[16] = p_x[8];
  p_x[17] = v5;
  v6 = p_x[15];
  p_x[22] = p_x[14];
  p_x[23] = v6;
  v7 = p_x[13];
  p_x[20] = p_x[12];
  p_x[21] = v7;
}

// 0x15a9f20
void SDF_VU0__COPYMATRIX_A_TO_C(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;

  p_x = &vf00.x;
  v4 = p_x[11];
  p_x[26] = p_x[10];
  p_x[27] = v4;
  v5 = p_x[9];
  p_x[24] = p_x[8];
  p_x[25] = v5;
  v6 = p_x[15];
  p_x[30] = p_x[14];
  p_x[31] = v6;
  v7 = p_x[13];
  p_x[28] = p_x[12];
  p_x[29] = v7;
}

// 0x15a9fb0
void SDF_VU0__COPYMATRIX_B_TO_A(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;

  p_x = &vf00.x;
  v4 = p_x[19];
  p_x[10] = p_x[18];
  p_x[11] = v4;
  v5 = p_x[17];
  p_x[8] = p_x[16];
  p_x[9] = v5;
  v6 = p_x[23];
  p_x[14] = p_x[22];
  p_x[15] = v6;
  v7 = p_x[21];
  p_x[12] = p_x[20];
  p_x[13] = v7;
}

// 0x15aa040
void SDF_VU0__COPYMATRIX_B_TO_C(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;

  p_x = &vf00.x;
  v4 = p_x[11];
  p_x[26] = p_x[10];
  p_x[27] = v4;
  v5 = p_x[9];
  p_x[24] = p_x[8];
  p_x[25] = v5;
  v6 = p_x[15];
  p_x[30] = p_x[14];
  p_x[31] = v6;
  v7 = p_x[13];
  p_x[28] = p_x[12];
  p_x[29] = v7;
}

// 0x15aa0d0
void SDF_VU0__COPYMATRIX_C_TO_A(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;

  p_x = &vf00.x;
  v4 = p_x[27];
  p_x[10] = p_x[26];
  p_x[11] = v4;
  v5 = p_x[25];
  p_x[8] = p_x[24];
  p_x[9] = v5;
  v6 = p_x[31];
  p_x[14] = p_x[30];
  p_x[15] = v6;
  v7 = p_x[29];
  p_x[12] = p_x[28];
  p_x[13] = v7;
}

// 0x15aa160
void SDF_VU0__COPYMATRIX_C_TO_B(void) {
  u64 *p_x;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;

  p_x = &vf00.x;
  v4 = p_x[27];
  p_x[18] = p_x[26];
  p_x[19] = v4;
  v5 = p_x[25];
  p_x[16] = p_x[24];
  p_x[17] = v5;
  v6 = p_x[31];
  p_x[22] = p_x[30];
  p_x[23] = v6;
  v7 = p_x[29];
  p_x[20] = p_x[28];
  p_x[21] = v7;
}

// 0x15aba60
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src) {
  *dst = src;
}

// 0x15aba80
void SDF_VU0__COPYVECTOR_A_TO_B(void) {
  f32 w;

  *&vct_B.x = *&vct_A.x;
  w = vct_A.w;
  vct_B.z = vct_A.z;
  vct_B.w = w;
}

// 0x15abb00
void SDF_VU0__COPYVECTOR_A_TO_C(void) {
  f32 w;

  *&vct_C.x = *&vct_A.x;
  w = vct_A.w;
  vct_C.z = vct_A.z;
  vct_C.w = w;
}

// 0x15abb80
void SDF_VU0__COPYVECTOR_B_TO_A(void) {
  f32 w;

  *&vct_A.x = *&vct_B.x;
  w = vct_B.w;
  vct_A.z = vct_B.z;
  vct_A.w = w;
}

// 0x15abc00
void SDF_VU0__COPYVECTOR_B_TO_C(void) {
  f32 w;

  *&vct_C.x = *&vct_B.x;
  w = vct_B.w;
  vct_C.z = vct_B.z;
  vct_C.w = w;
}

// 0x15abc80
void SDF_VU0__COPYVECTOR_C_TO_A(void) {
  f32 w;

  *&vct_A.x = *&vct_C.x;
  w = vct_C.w;
  vct_A.z = vct_C.z;
  vct_A.w = w;
}

// 0x15abd00
void SDF_VU0__COPYVECTOR_C_TO_B(void) {
  f32 w;

  *&vct_B.x = *&vct_C.x;
  w = vct_C.w;
  vct_B.z = vct_C.z;
  vct_B.w = w;
}

// 0x15ae690
void SDF_VU0__ClipTest(sdfVector4_t reg) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v6;

  w = reg.w;
  z = reg.z;
  y = reg.y;
  x = reg.x;
  clip <<= 6;
  if (x > w)
  {
    clip |= 1u;
    v6 = -w;
    if (x >= -w)
    {
LABEL_5:
      if (y <= w)
        goto LABEL_6;
      goto LABEL_13;
    }
  }
  else
  {
    v6 = -w;
    if (x >= -w)
      goto LABEL_5;
  }
  clip |= 2u;
  if (y <= w)
  {
LABEL_6:
    if (y >= v6)
      goto LABEL_7;
    goto LABEL_14;
  }
LABEL_13:
  clip |= 4u;
  if (y >= v6)
  {
LABEL_7:
    if (z <= w)
      goto LABEL_8;
    goto LABEL_15;
  }
LABEL_14:
  clip |= 8u;
  if (z <= w)
  {
LABEL_8:
    if (z >= v6)
      return;
    goto LABEL_9;
  }
LABEL_15:
  clip |= 0x10u;
  if (z >= v6)
    return;
LABEL_9:
  clip |= 0x20u;
}

// 0x15ab9e0
void SDF_VU0__FTOI0(void) {
  ;
}

// 0x15ab9f0
void SDF_VU0__FTOI0_B(void) {
  ;
}

// 0x15aba20
void SDF_VU0__FTOI12(void) {
  ;
}

// 0x15aba30
void SDF_VU0__FTOI12_B(void) {
  ;
}

// 0x15aba40
void SDF_VU0__FTOI15(void) {
  ;
}

// 0x15aba50
void SDF_VU0__FTOI15_B(void) {
  ;
}

// 0x15aba00
void SDF_VU0__FTOI4(void) {
  ;
}

// 0x15aba10
void SDF_VU0__FTOI4_B(void) {
  ;
}

// 0x15ae8e0
void SDF_VU0__GETCLIPFLAG(s32 *r) {
  *r = clip;
}

// 0x15ad9a0
f32 SDF_VU0__GETLENGTH(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  long f64 v8;
  f64 v9;
  long f64 v10;
  UnityEngine_Vector3_o v12;
  UnityEngine_Vector3_o v13;
  UnityEngine_Vector4_o v14;

  v12.z = 0.0;
  *&v12.x = 0;
  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v7 = p_x[6];
  v6 = p_x[7];
  v14.x = v4;
  v14.y = v5;
  v14.z = v7;
  v14.w = v6;
  v13 = op_Implicit_8738992(v14);
  *&v9 = v13.x;
  *&v10 = v13.y;
  v12 = v13;
  v8 = sub_8535D0(&v12.x, 0, v9, v10);
  return *&v8;
}

// 0x15ab310
f32 SDF_VU0__GETVECTOR_W(void) {
  return vct_A.w;
}

// 0x15ab1c0
f32 SDF_VU0__GETVECTOR_X(void) {
  return vct_A.x;
}

// 0x15ab230
f32 SDF_VU0__GETVECTOR_Y(void) {
  return vct_A.y;
}

// 0x15ab2a0
f32 SDF_VU0__GETVECTOR_Z(void) {
  return vct_A.z;
}

// 0x15add90
void SDF_VU0__GET_ROW0(void) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  sub_1A00880(&mtx_A, 0);
  vct_A.x = v4;
  vct_A.y = v5;
  vct_A.z = v6;
  vct_A.w = v7;
}

// 0x15ade20
void SDF_VU0__GET_ROW1(void) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  sub_1A00880(&mtx_A, 1u);
  vct_A.x = v4;
  vct_A.y = v5;
  vct_A.z = v6;
  vct_A.w = v7;
}

// 0x15adeb0
void SDF_VU0__GET_ROW2(void) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  sub_1A00880(&mtx_A, 2u);
  vct_A.x = v4;
  vct_A.y = v5;
  vct_A.z = v6;
  vct_A.w = v7;
}

// 0x15adf40
void SDF_VU0__GET_ROW3(void) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  sub_1A00880(&mtx_A, 3u);
  vct_A.x = v4;
  vct_A.y = v5;
  vct_A.z = v6;
  vct_A.w = v7;
}

// 0x15ad610
f32 SDF_VU0__INNERPRODUCT(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  UnityEngine_Vector3_o v10;
  UnityEngine_Vector3_o v11;
  UnityEngine_Vector4_o v12;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v7 = p_x[6];
  v6 = p_x[7];
  v12.x = v4;
  v12.y = v5;
  v12.z = v7;
  v12.w = v6;
  v10 = op_Implicit_8738992(v12);
  v11 = op_Implicit_8738992(vct_B);
  return Dot(v10, v11);
}

// 0x15ada80
void SDF_VU0__INTERPOLATE(f32 rate) {
  f32 *p_x;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;

  p_x = &vf00.x;
  v7 = p_x[4];
  v8 = p_x[5];
  v9 = p_x[6];
  v10 = p_x[7];
  v11 = p_x[8];
  v12 = p_x[9];
  v13 = p_x[10];
  v14 = p_x[11];
  v15 = rate;
  v17.x = v7;
  v17.y = v8;
  v17.z = v9;
  v17.w = v10;
  v18.x = v11;
  v18.y = v12;
  v18.z = v13;
  v18.w = v14;
  vct_A = Lerp(v17, v18, v15, 0);
}

// 0x15ab960
void SDF_VU0__ITOF0(void) {
  ;
}

// 0x15ab970
void SDF_VU0__ITOF0_B(void) {
  ;
}

// 0x15ab9a0
void SDF_VU0__ITOF12(void) {
  ;
}

// 0x15ab9b0
void SDF_VU0__ITOF12_B(void) {
  ;
}

// 0x15ab9c0
void SDF_VU0__ITOF15(void) {
  ;
}

// 0x15ab9d0
void SDF_VU0__ITOF15_B(void) {
  ;
}

// 0x15ab980
void SDF_VU0__ITOF4(void) {
  ;
}

// 0x15ab990
void SDF_VU0__ITOF4_B(void) {
  ;
}

// 0x15ace30
void SDF_VU0__LD_APPLYMATRIX(sdfVector4_t *vec) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Vector4_o v11;

  sub_19FF440(&mtx_A, 0, &v10);
  x = vec->x;
  y = vec->y;
  z = vec->z;
  w = vec->w;
  v11.x = x;
  v9 = v10;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  *vec = op_Multiply_27264976(&v9, v11);
}

// 0x15aa1f0
void SDF_VU0__LOADIDENTITY(void) {
  u64 *p_x;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  UnityEngine_Matrix4x4_o v11;

  get_identity(&v11, 0);
  p_x = &vf00.x;
  v6 = *&v11.m00;
  v5 = *&v11.m20;
  v7 = *&v11.m21;
  p_x[10] = *&v11.m01;
  p_x[11] = v7;
  p_x[8] = v6;
  p_x[9] = v5;
  v9 = *&v11.m02;
  v8 = *&v11.m22;
  v10 = *&v11.m23;
  p_x[14] = *&v11.m03;
  p_x[15] = v10;
  p_x[12] = v9;
  p_x[13] = v8;
}

// 0x15aaee0
void SDF_VU0__LOADIDENTITYVECTOR(void) {
  f32 w;

  *&vct_A.x = *&vf00.x;
  w = vf00.w;
  vct_A.z = vf00.z;
  vct_A.w = w;
}

// 0x15aaf60
void SDF_VU0__LOADIDENTITYVECTOR_B(void) {
  f32 w;

  *&vct_A.x = *&vf00.x;
  w = vf00.w;
  vct_A.z = vf00.z;
  vct_A.w = w;
}

// 0x15aafe0
void SDF_VU0__LOADIDENTITYVECTOR_C(void) {
  f32 w;

  *&vct_A.x = *&vf00.x;
  w = vf00.w;
  vct_A.z = vf00.z;
  vct_A.w = w;
}

// 0x15aa2b0
void SDF_VU0__LOADIDENTITY_B(void) {
  u64 *p_x;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  UnityEngine_Matrix4x4_o v11;

  get_identity(&v11, 0);
  p_x = &vf00.x;
  v6 = *&v11.m00;
  v5 = *&v11.m20;
  v7 = *&v11.m21;
  p_x[18] = *&v11.m01;
  p_x[19] = v7;
  p_x[16] = v6;
  p_x[17] = v5;
  v9 = *&v11.m02;
  v8 = *&v11.m22;
  v10 = *&v11.m23;
  p_x[22] = *&v11.m03;
  p_x[23] = v10;
  p_x[20] = v9;
  p_x[21] = v8;
}

// 0x15a9b00
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix) {
  u64 *p_x;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;

  v7 = *&aMatrix->m01;
  v8 = *&aMatrix->m21;
  v5 = *&aMatrix->m00;
  v6 = *&aMatrix->m20;
  v11 = *&aMatrix->m03;
  v12 = *&aMatrix->m23;
  v9 = *&aMatrix->m02;
  v10 = *&aMatrix->m22;
  p_x = &vf00.x;
  p_x[10] = v7;
  p_x[11] = v8;
  p_x[8] = v5;
  p_x[9] = v6;
  p_x[14] = v11;
  p_x[15] = v12;
  p_x[12] = v9;
  p_x[13] = v10;
}

// 0x15a9c30
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix) {
  u64 *p_x;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;

  v7 = *&aMatrix->m01;
  v8 = *&aMatrix->m21;
  v5 = *&aMatrix->m00;
  v6 = *&aMatrix->m20;
  v11 = *&aMatrix->m03;
  v12 = *&aMatrix->m23;
  v9 = *&aMatrix->m02;
  v10 = *&aMatrix->m22;
  p_x = &vf00.x;
  p_x[18] = v7;
  p_x[19] = v8;
  p_x[16] = v5;
  p_x[17] = v6;
  p_x[22] = v11;
  p_x[23] = v12;
  p_x[20] = v9;
  p_x[21] = v10;
}

// 0x15a9d60
void SDF_VU0__LOADMATRIX_C(sdfMatrix4_t *aMatrix) {
  u64 *p_x;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;

  v7 = *&aMatrix->m01;
  v8 = *&aMatrix->m21;
  v5 = *&aMatrix->m00;
  v6 = *&aMatrix->m20;
  v11 = *&aMatrix->m03;
  v12 = *&aMatrix->m23;
  v9 = *&aMatrix->m02;
  v10 = *&aMatrix->m22;
  p_x = &vf00.x;
  p_x[26] = v7;
  p_x[27] = v8;
  p_x[24] = v5;
  p_x[25] = v6;
  p_x[30] = v11;
  p_x[31] = v12;
  p_x[28] = v9;
  p_x[29] = v10;
}

// 0x15ab800
void SDF_VU0__LOADSHORTVECTOR(s32 p) {
  ;
}

// 0x15ab810
void SDF_VU0__LOADSHORTVECTOR_B(s32 p) {
  ;
}

// 0x15aab80
void SDF_VU0__LOADVECTOR(sdfVector4_t p) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 *p_x;

  w = p.w;
  z = p.z;
  y = p.y;
  x = p.x;
  p_x = &vf00.x;
  p_x[4] = x;
  p_x[5] = y;
  p_x[6] = z;
  p_x[7] = w;
}

// 0x15aaca0
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 *p_x;

  w = p.w;
  z = p.z;
  y = p.y;
  x = p.x;
  p_x = &vf00.x;
  p_x[8] = x;
  p_x[9] = y;
  p_x[10] = z;
  p_x[11] = w;
}

// 0x15aadc0
void SDF_VU0__LOADVECTOR_C(sdfVector4_t p) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 *p_x;

  w = p.w;
  z = p.z;
  y = p.y;
  x = p.x;
  p_x = &vf00.x;
  p_x[12] = x;
  p_x[13] = y;
  p_x[14] = z;
  p_x[15] = w;
}

// 0x15ab820
void SDF_VU0__LOADVECTOR_MTXCOL(sdfMatrix4_t *p) {
  s32 v5;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  u32 *p_x;

  sub_1A00070(p, 0);
  v6 = v5;
  v8 = v7;
  v10 = v9;
  v12 = v11;
  p_x = &vf00.x;
  p_x[4] = v6;
  p_x[5] = v8;
  p_x[6] = v10;
  p_x[7] = v12;
}

// 0x15ab8c0
void SDF_VU0__LOADVECTOR_MTXCOL_B(sdfMatrix4_t *p) {
  s32 v5;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  u32 *p_x;

  sub_1A00070(p, 0);
  v6 = v5;
  v8 = v7;
  v10 = v9;
  v12 = v11;
  p_x = &vf00.x;
  p_x[8] = v6;
  p_x[9] = v8;
  p_x[10] = v10;
  p_x[11] = v12;
}

// 0x15ab6c0
void SDF_VU0__LOADVECTOR_UNALIGN(sdfVector4_t p) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 *p_x;

  w = p.w;
  z = p.z;
  y = p.y;
  x = p.x;
  p_x = &vf00.x;
  p_x[4] = x;
  p_x[5] = y;
  p_x[6] = z;
  p_x[7] = w;
}

// 0x15ab760
void SDF_VU0__LOADVECTOR_UNALIGN_B(sdfVector4_t p) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 *p_x;

  w = p.w;
  z = p.z;
  y = p.y;
  x = p.x;
  p_x = &vf00.x;
  p_x[8] = x;
  p_x[9] = y;
  p_x[10] = z;
  p_x[11] = w;
}

// 0x15ab580
void SDF_VU0__LOADVECTOR_XYZ(sdfVector4_t p) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 *p_x;

  w = p.w;
  z = p.z;
  y = p.y;
  x = p.x;
  p_x = &vf00.x;
  p_x[4] = x;
  p_x[5] = y;
  p_x[6] = z;
  p_x[7] = w;
  vct_A.w = 0.0;
}

// 0x15ab620
void SDF_VU0__LOADVECTOR_XYZ_B(sdfVector4_t p) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 *p_x;

  w = p.w;
  z = p.z;
  y = p.y;
  x = p.x;
  p_x = &vf00.x;
  p_x[8] = x;
  p_x[9] = y;
  p_x[10] = z;
  p_x[11] = w;
  vct_B.w = 0.0;
}

// 0x15adfd0
void SDF_VU0__LOAD_ROW0(sdfVector4_t p) {
  sub_1A00AD0(&mtx_A, 0);
}

// 0x15ae070
void SDF_VU0__LOAD_ROW1(sdfVector4_t p) {
  sub_1A00AD0(&mtx_A, 1u);
}

// 0x15ae110
void SDF_VU0__LOAD_ROW2(sdfVector4_t p) {
  sub_1A00AD0(&mtx_A, 2u);
}

// 0x15ae1b0
void SDF_VU0__LOAD_ROW3(sdfVector4_t p) {
  sub_1A00AD0(&mtx_A, 3u);
}

// 0x15ae250
void SDF_VU0__MATRIX_ROW3_W_SET_ONE(void) {
  sub_19FFD30(&mtx_A, 3, 3);
}

// 0x15ac890
void SDF_VU0__MULVECTOR(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  v8 = p_x[8];
  v9 = p_x[9];
  v11 = p_x[10];
  v10 = p_x[11];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_A = Scale(v12, v13);
}

// 0x15acb70
void SDF_VU0__NEGVECTOR_XYZ(void) {
  vct_A.x = -vct_A.x;
  vct_A.y = -vct_A.y;
  vct_A.z = -vct_A.z;
}

// 0x15acc00
void SDF_VU0__NEGVECTOR_XYZ_B(void) {
  vct_B.x = -vct_B.x;
  vct_B.y = -vct_B.y;
  vct_B.z = -vct_B.z;
}

// 0x15acc90
void SDF_VU0__NEGVECTOR_XYZ_C(void) {
  vct_C.x = -vct_C.x;
  vct_C.y = -vct_C.y;
  vct_C.z = -vct_C.z;
}

// 0x15ad890
void SDF_VU0__NORMALIZE(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  UnityEngine_Vector3_o v10;
  UnityEngine_Vector4_o v11;
  UnityEngine_Vector3_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v7 = p_x[6];
  v6 = p_x[7];
  v13.x = v4;
  v13.y = v5;
  v13.z = v7;
  v13.w = v6;
  v10 = op_Implicit_8738992(v13);
  v12 = Normalize(v10, 0);
  v11 = op_Implicit(v12, 0);
  vct_A.x = v11.x;
  vct_A.y = v11.y;
  vct_A.z = v11.z;
}

// 0x15ad740
void SDF_VU0__OUTERPRODUCT(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  UnityEngine_Vector3_o v10;
  UnityEngine_Vector3_o v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector3_o v13;
  UnityEngine_Vector4_o v14;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v7 = p_x[6];
  v6 = p_x[7];
  v14.x = v4;
  v14.y = v5;
  v14.z = v7;
  v14.w = v6;
  v10 = op_Implicit_8738992(v14);
  v11 = op_Implicit_8738992(vct_B);
  v13 = Cross(v10, v11);
  v12 = op_Implicit(v13, 0);
  vct_A.x = v12.x;
  vct_A.y = v12.y;
  vct_A.z = v12.z;
}

// 0x15ad4a0
void SDF_VU0__PERSVECTOR(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  f32 v10;
  UnityEngine_Matrix4x4_o v12;
  UnityEngine_Matrix4x4_o v13;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;

  vct_A.w = 1.0;
  sub_19FF440(&mtx_A, 0, &v13);
  x = vct_A.x;
  y = vct_A.y;
  z = vct_A.z;
  w = vct_A.w;
  v16.x = x;
  v12 = v13;
  v16.y = y;
  v16.z = z;
  v16.w = w;
  v14 = op_Multiply_27264976(&v12, v16);
  v10 = 1.0 / v14.w;
  v15 = op_Multiply(v14, v10, 0);
  vct_A.x = v15.x;
  vct_A.y = v15.y;
  vct_A.z = v15.z;
  vct_A.w = v10;
}

// 0x15ae500
void SDF_VU0__RESET_ROW3(void) {
  sub_1A00AD0(&mtx_A, 3u);
}

// 0x15aeb90
u32 SDF_VU0__Retdds3ColorFtoI(sdfVector4_t rgba, f32 ratio) {
  f32 v3;
  f32 v4;
  s32 v5;
  f32 v6;
  u8 v7;
  u8 v8;
  u8 v9;
  s32 v10;

  v3 = rgba.y * ratio;
  v4 = rgba.z * ratio;
  v5 = v3;
  v6 = rgba.x * ratio;
  if (v3 >= 0.0)
    LOBYTE(v5) = v3;
  if (v4 >= 0.0)
    v7 = v4;
  else
    v7 = v4;
  v8 = vcvts_n_s32_f32(rgba.w, 7u);
  v9 = vcvts_n_u32_f32(rgba.w, 7u);
  if ((rgba.w * 128.0) < 0.0)
    v9 = v8;
  v10 = v6;
  if (v6 >= 0.0)
    LOBYTE(v10) = v6;
  return v10 | (v9 << 24) | (v5 << 8) | (v7 << 16);
}

// 0x15aea30
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio) {
  f32 v3;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  s64 v12;
  s64 v13;
  UnityEngine_Vector4_o result;

  v3 = 1.0 / ratio;
  v12 = 0;
  v13 = 0;
  v4 = BYTE1(rgba);
  v5 = BYTE2(rgba);
  v6 = HIBYTE(rgba);
  v7 = rgba;
  sub_854690(&v12, v3 * v7, v3 * v4, v3 * v5, v6 * 0.0078125);
  result.y = *(&v12 + 1);
  LODWORD(result.x) = v12;
  result.w = *(&v13 + 1);
  LODWORD(result.z) = v13;
  return result;
}

// 0x15aa760
void SDF_VU0__SCALE(void) {
  f32 w;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  UnityEngine_Vector4_o v13;

  SDF_VU0__SCALE_XYZ();
  sub_1A00880(&mtx_A, 3u);
  w = vct_A.w;
  v6 = v5;
  v8 = v7;
  v10 = v9;
  v12 = v11;
  v13.x = v6;
  v13.y = v8;
  v13.z = v10;
  v13.w = v12;
  op_Multiply(v13, w, 0);
  sub_1A00AD0(&mtx_A, 3u);
}

// 0x15ac980
void SDF_VU0__SCALEVECTOR(f32 v) {
  f32 *p_x;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  UnityEngine_Vector4_o v10;

  p_x = &vf00.x;
  v6 = p_x[4];
  v7 = p_x[5];
  v9 = p_x[6];
  v8 = p_x[7];
  v10.x = v6;
  v10.y = v7;
  v10.z = v9;
  v10.w = v8;
  vct_A = op_Multiply(v10, v, 0);
}

// 0x15acb40
void SDF_VU0__SCALEVECTOR_A_AND_B(f32 v) {
  SDF_VU0__SCALEVECTOR(v);
  SDF_VU0__SCALEVECTOR_B(v);
}

// 0x15aca60
void SDF_VU0__SCALEVECTOR_B(f32 v) {
  f32 *p_x;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  UnityEngine_Vector4_o v10;

  p_x = &vf00.x;
  v6 = p_x[8];
  v7 = p_x[9];
  v9 = p_x[10];
  v8 = p_x[11];
  v10.x = v6;
  v10.y = v7;
  v10.z = v9;
  v10.w = v8;
  vct_B = op_Multiply(v10, v, 0);
}

// 0x15aa860
void SDF_VU0__SCALE_XYZ(void) {
  f32 x;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o v15;

  sub_1A00880(&mtx_A, 0);
  x = vct_A.x;
  v6 = v5;
  v8 = v7;
  v10 = v9;
  v12 = v11;
  v13.x = v6;
  v13.y = v8;
  v13.z = v10;
  v13.w = v12;
  op_Multiply(v13, x, 0);
  sub_1A00AD0(&mtx_A, 0);
  sub_1A00880(&mtx_A, 1u);
  op_Multiply(v14, vct_A.y, 0);
  sub_1A00AD0(&mtx_A, 1u);
  sub_1A00880(&mtx_A, 2u);
  op_Multiply(v15, vct_A.z, 0);
  sub_1A00AD0(&mtx_A, 2u);
}

// 0x15aa9e0
void SDF_VU0__SCALE_XYZ_REV(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o v21;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  sub_1A00880((p_x + 16), 0);
  v9 = v8;
  v11 = v10;
  v13 = v12;
  v15 = v14;
  v16.x = v9;
  v16.y = v11;
  v16.z = v13;
  v16.w = v15;
  v19.x = v4;
  v19.y = v5;
  v19.z = v6;
  v19.w = 1.0;
  Scale(v16, v19);
  sub_1A00AD0(&mtx_A, 0);
  sub_1A00880(&mtx_A, 1u);
  v20.x = v4;
  v20.y = v5;
  v20.z = v6;
  v20.w = 1.0;
  Scale(v17, v20);
  sub_1A00AD0(&mtx_A, 1u);
  sub_1A00880(&mtx_A, 2u);
  v21.x = v4;
  v21.y = v5;
  v21.z = v6;
  v21.w = 1.0;
  Scale(v18, v21);
  sub_1A00AD0(&mtx_A, 2u);
}

// 0x15ae5f0
void SDF_VU0__SETSCALE1VECTOR(void) {
  f32 v4;
  f32 v5;
  s64 v6;
  s64 v7;

  v6 = 0;
  v7 = 0;
  sub_854690(&v6, 1.0, 1.0, 1.0, 0.0);
  v5 = *&v7;
  v4 = *(&v7 + 1);
  *&vct_A.x = v6;
  vct_A.z = v5;
  vct_A.w = v4;
}

// 0x15ab500
void SDF_VU0__SETVECTOR_W(f32 v) {
  vct_A.w = v;
}

// 0x15ab380
void SDF_VU0__SETVECTOR_X(f32 v) {
  vct_A.x = v;
}

// 0x15ab400
void SDF_VU0__SETVECTOR_Y(f32 v) {
  vct_A.y = v;
}

// 0x15ab480
void SDF_VU0__SETVECTOR_Z(f32 v) {
  vct_A.z = v;
}

// 0x15adb90
void SDF_VU0__SET_ROW0(void) {
  sub_1A00AD0(&mtx_A, 0);
}

// 0x15adc10
void SDF_VU0__SET_ROW1(void) {
  sub_1A00AD0(&mtx_A, 1u);
}

// 0x15adc90
void SDF_VU0__SET_ROW2(void) {
  sub_1A00AD0(&mtx_A, 2u);
}

// 0x15add10
void SDF_VU0__SET_ROW3(void) {
  sub_1A00AD0(&mtx_A, 3u);
}

// 0x15aa370
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix) {
  s64 v3;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  UnityEngine_Matrix4x4_o v9;

  get_identity(&v9, 0);
  v4 = *&v9.m00;
  v3 = *&v9.m20;
  v5 = *&v9.m21;
  *&aMatrix->m01 = *&v9.m01;
  *&aMatrix->m21 = v5;
  *&aMatrix->m00 = v4;
  *&aMatrix->m20 = v3;
  v7 = *&v9.m02;
  v6 = *&v9.m22;
  v8 = *&v9.m23;
  *&aMatrix->m03 = *&v9.m03;
  *&aMatrix->m23 = v8;
  *&aMatrix->m02 = v7;
  *&aMatrix->m22 = v6;
}

// 0x15ab060
void SDF_VU0__STOREIDENTITYVECTOR(sdfVector4_t *p) {
  struct sdf_vu0r_StaticFields *static_fields;
  s64 v5;
  f32 z;

  v5 = *&vf00.x;
  z = vf00.z;
  *&static_fields = vf00.w;
  *&p->x = v5;
  p->z = z;
  LODWORD(p->w) = static_fields;
}

// 0x15a9bb0
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix) {
  memmove(aMatrix, &mtx_A, 0x40u);
}

// 0x15a9ce0
void SDF_VU0__STOREMATRIX_B(sdfMatrix4_t *aMatrix) {
  memmove(aMatrix, &mtx_B, 0x40u);
}

// 0x15a9e10
void SDF_VU0__STOREMATRIX_C(sdfMatrix4_t *aMatrix) {
  memmove(aMatrix, &mtx_C, 0x40u);
}

// 0x15aac20
void SDF_VU0__STOREVECTOR(sdfVector4_t *p) {
  struct sdf_vu0r_StaticFields *static_fields;
  s64 v5;
  f32 z;

  v5 = *&vct_A.x;
  z = vct_A.z;
  *&static_fields = vct_A.w;
  *&p->x = v5;
  p->z = z;
  LODWORD(p->w) = static_fields;
}

// 0x15aad40
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p) {
  struct sdf_vu0r_StaticFields *static_fields;
  s64 v5;
  f32 z;

  v5 = *&vct_B.x;
  z = vct_B.z;
  *&static_fields = vct_B.w;
  *&p->x = v5;
  p->z = z;
  LODWORD(p->w) = static_fields;
}

// 0x15aae60
void SDF_VU0__STOREVECTOR_C(sdfVector4_t *p) {
  struct sdf_vu0r_StaticFields *static_fields;
  s64 v5;
  f32 z;

  v5 = *&vct_C.x;
  z = vct_C.z;
  *&static_fields = vct_C.w;
  *&p->x = v5;
  p->z = z;
  LODWORD(p->w) = static_fields;
}

// 0x15ae2d0
void SDF_VU0__STORE_ROW0(sdfVector4_t *p) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  sub_1A00880(&mtx_A, 0);
  p->x = v4;
  p->y = v5;
  p->z = v6;
  p->w = v7;
}

// 0x15ae350
void SDF_VU0__STORE_ROW1(sdfVector4_t *p) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  sub_1A00880(&mtx_A, 1u);
  p->x = v4;
  p->y = v5;
  p->z = v6;
  p->w = v7;
}

// 0x15ae3e0
void SDF_VU0__STORE_ROW2(sdfVector4_t *p) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  sub_1A00880(&mtx_A, 2u);
  p->x = v4;
  p->y = v5;
  p->z = v6;
  p->w = v7;
}

// 0x15ae470
void SDF_VU0__STORE_ROW3(sdfVector4_t *p) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  sub_1A00880(&mtx_A, 3u);
  p->x = v4;
  p->y = v5;
  p->z = v6;
  p->w = v7;
}

// 0x15ac3e0
void SDF_VU0__SUBVECTOR(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  v8 = p_x[8];
  v9 = p_x[9];
  v11 = p_x[10];
  v10 = p_x[11];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_A = op_Subtraction(v12, v13);
}

// 0x15ac4d0
void SDF_VU0__SUBVECTOR_A_C(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  v8 = p_x[12];
  v9 = p_x[13];
  v11 = p_x[14];
  v10 = p_x[15];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_A = op_Subtraction(v12, v13);
}

// 0x15ac5c0
void SDF_VU0__SUBVECTOR_B_A(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[8];
  v5 = p_x[9];
  v6 = p_x[10];
  v7 = p_x[11];
  v8 = p_x[4];
  v9 = p_x[5];
  v11 = p_x[6];
  v10 = p_x[7];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_B = op_Subtraction(v12, v13);
}

// 0x15ac7a0
void SDF_VU0__SUBVECTOR_B_C(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[8];
  v5 = p_x[9];
  v6 = p_x[10];
  v7 = p_x[11];
  v8 = p_x[12];
  v9 = p_x[13];
  v11 = p_x[14];
  v10 = p_x[15];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_B = op_Subtraction(v12, v13);
}

// 0x15ac6b0
void SDF_VU0__SUBVECTOR_C_A(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  p_x = &vf00.x;
  v4 = p_x[12];
  v5 = p_x[13];
  v6 = p_x[14];
  v7 = p_x[15];
  v8 = p_x[4];
  v9 = p_x[5];
  v11 = p_x[6];
  v10 = p_x[7];
  v12.x = v4;
  v12.y = v5;
  v12.z = v6;
  v12.w = v7;
  v13.x = v8;
  v13.y = v9;
  v13.z = v11;
  v13.w = v10;
  vct_C = op_Subtraction(v12, v13);
}

// 0x15abd80
void SDF_VU0__SWAPVECTOR_A_B(void) {
  f32 y;
  f32 z;
  f32 w;
  s64 v7;
  f32 v8;
  f32 v9;

  y = vct_B.y;
  z = vct_B.z;
  w = vct_B.w;
  v7 = *&vct_A.x;
  v8 = vct_A.z;
  v9 = vct_A.w;
  vct_A.x = vct_B.x;
  vct_A.y = y;
  vct_A.z = z;
  vct_A.w = w;
  *&vct_B.x = v7;
  vct_B.z = v8;
  vct_B.w = v9;
}

// 0x15abe10
void SDF_VU0__SWAPVECTOR_A_C(void) {
  f32 y;
  f32 z;
  f32 w;
  s64 v7;
  f32 v8;
  f32 v9;

  y = vct_C.y;
  z = vct_C.z;
  w = vct_C.w;
  v7 = *&vct_A.x;
  v8 = vct_A.z;
  v9 = vct_A.w;
  vct_A.x = vct_C.x;
  vct_A.y = y;
  vct_A.z = z;
  vct_A.w = w;
  *&vct_C.x = v7;
  vct_C.z = v8;
  vct_C.w = v9;
}

// 0x15abea0
void SDF_VU0__SWAPVECTOR_B_C(void) {
  f32 y;
  f32 z;
  f32 w;
  s64 v7;
  f32 v8;
  f32 v9;

  y = vct_C.y;
  z = vct_C.z;
  w = vct_C.w;
  v7 = *&vct_B.x;
  v8 = vct_B.z;
  v9 = vct_B.w;
  vct_B.x = vct_C.x;
  vct_B.y = y;
  vct_B.z = z;
  vct_B.w = w;
  *&vct_C.x = v7;
  vct_C.z = v8;
  vct_C.w = v9;
}

// 0x15aa410
void SDF_VU0__TRANSLATE(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Vector4_o v11;

  sub_19FF440(&mtx_A, 0, &v10);
  x = vct_A.x;
  y = vct_A.y;
  z = vct_A.z;
  w = vct_A.w;
  v11.x = x;
  v9 = v10;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  op_Multiply_27264976(&v9, v11);
  sub_1A00AD0(&mtx_A, 3u);
}

// 0x15aa520
void SDF_VU0__TRANSLATE_XYZ(void) {
  f32 x;
  f32 y;
  f32 z;
  UnityEngine_Matrix4x4_o v8;
  UnityEngine_Matrix4x4_o v9;
  UnityEngine_Vector4_o v10;

  x = vct_A.x;
  y = vct_A.y;
  z = vct_A.z;
  sub_19FF440(&mtx_A, 0, &v9);
  v10.w = 1.0;
  v8 = v9;
  v10.x = x;
  v10.y = y;
  v10.z = z;
  op_Multiply_27264976(&v8, v10);
  sub_1A00AD0(&mtx_A, 3u);
}

// 0x15aa630
void SDF_VU0__TRANSMATRIX(void) {
  s64 p_mtx_A;
  struct UnityEngine_Matrix4x4_o *v4;
  struct UnityEngine_Matrix4x4_o *v5;

  p_mtx_A = &mtx_A;
  sub_19FFB10(p_mtx_A, 3, 0);
  sub_19FFD30(p_mtx_A, 3, 0);
  v4 = &mtx_A;
  sub_19FFB10(v4, 3, 1);
  sub_19FFD30(v4, 3, 1);
  v5 = &mtx_A;
  sub_19FFB10(v5, 3, 2);
  sub_19FFD30(v5, 3, 2);
}

// 0x15ab0e0
void SDF_VU0__VECTOR_W_SET_ONE(void) {
  vct_A.w = 1.0;
}

// 0x15ab150
void SDF_VU0__VECTOR_W_SET_ZERO(void) {
  vct_A.w = 0.0;
}

// 0x15ae580
void SDF_VU0__ZEROVECTOR_W(void) {
  vct_A.w = 0.0;
}

// 0x15aeab0
u32 SDF_VU0__dds3ColorFtoI(f32 ratio) {
  f32 *p_x;
  f32 v6;
  f32 v7;
  s32 v8;
  u32 v9;
  bool v10;
  f32 v11;
  f32 v12;
  u8 v13;
  u8 v14;
  s32 v15;
  u8 v16;
  f32 v17;
  u8 v18;

  p_x = &vf00.x;
  v6 = p_x[4];
  v7 = p_x[5] * ratio;
  v8 = v7;
  v9 = v7;
  v10 = v7 < 0.0;
  v11 = p_x[7];
  v12 = p_x[6] * ratio;
  v13 = vcvts_n_u32_f32(v11, 7u);
  if (v10)
    v14 = v8;
  else
    v14 = v9;
  v15 = v12;
  if (v12 >= 0.0)
    LOBYTE(v15) = v12;
  v16 = vcvts_n_s32_f32(v11, 7u);
  v17 = v6 * ratio;
  if ((v11 * 128.0) >= 0.0)
    v16 = v13;
  if (v17 >= 0.0)
    v18 = v17;
  else
    v18 = v17;
  return v18 | (v14 << 8) | (v16 << 24) | (v15 << 16);
}

// 0x15ae940
void SDF_VU0__dds3ColorItoF(u32 rgba) {
  f32 v3;
  f32 v4;
  f32 v5;
  f32 v6;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  u32 *p_x;
  s64 v14;
  s64 v15;

  v3 = BYTE1(rgba);
  v14 = 0;
  v15 = 0;
  v4 = BYTE2(rgba);
  v5 = HIBYTE(rgba);
  v6 = rgba;
  sub_854690(&v14, v6 * 0.0078125, v3 * 0.0078125, v4 * 0.0078125, v5 * 0.0078125);
  v9 = v14;
  v8 = HIDWORD(v14);
  v11 = v15;
  v10 = HIDWORD(v15);
  p_x = &vf00.x;
  p_x[4] = v9;
  p_x[5] = v8;
  p_x[6] = v11;
  p_x[7] = v10;
}

// 0x15af880
void sdf3DScreenParam_t__Copy(sdf3DScreenParam_t *this, sdf3DScreenParam_t *data) {
  f32 z;
  f32 w;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;

  this->flags = data->flags;
  this->aspect = data->aspect;
  this->projDist = data->projDist;
  this->fovy = data->fovy;
  this->ox = data->ox;
  this->oy = data->oy;
  this->width = data->width;
  this->height = data->height;
  this->zMin = data->zMin;
  this->zMax = data->zMax;
  this->nearClip = data->nearClip;
  this->farClip = data->farClip;
  memmove(&this->TM, &data->TM, 0x40u);
  z = data->scale.z;
  w = data->scale.w;
  *&this->scale.x = *&data->scale.x;
  this->scale.z = z;
  this->scale.w = w;
  v7 = data->trans.z;
  v8 = data->trans.w;
  *&this->trans.x = *&data->trans.x;
  this->trans.z = v7;
  this->trans.w = v8;
  v9 = data->cameraPos.z;
  v10 = data->cameraPos.w;
  *&this->cameraPos.x = *&data->cameraPos.x;
  this->cameraPos.z = v9;
  this->cameraPos.w = v10;
}

// 0x15b2ce0
void sdfIVector2_t__Copy(sdfIVector2_t *this, sdfIVector2_t *v) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v4;
  s32 v5;
  struct System_Int32_array *v6;
  struct System_Int32_array *v7;
  s32 v9;

  pm = v->pm;
  v4 = this->pm;
  v5 = pm->m_Items[0];
  v4->m_Items[0] = v5;
  v6 = v->pm;
  v7 = this->pm;
  v9 = v6->m_Items[1];
  v7->m_Items[1] = v9;
}

// 0x15b2bf0
sdfIVector2_t *sdfIVector2_t__Create(s32 x, s32 y) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  Il2CppClass *v8;

  v5 = Allocate(sdfIVector2_t);
  v5[1].klass = NewSpecific(s32, 2u);
  _ctor(v5, 0);
  klass = v5[1].klass;
  LODWORD(klass->_1.byval_arg.data) = x;
  v8 = v5[1].klass;
  HIDWORD(v8->_1.byval_arg.data) = y;
  return v5;
}

// 0x15b2f20
void sdfIVector3_t__Copy(sdfIVector3_t *this, sdfIVector3_t *v) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v4;
  s32 v5;
  struct System_Int32_array *v6;
  struct System_Int32_array *v7;
  s32 v9;
  struct System_Int32_array *v11;
  struct System_Int32_array *v12;
  s32 v14;

  pm = v->pm;
  v4 = this->pm;
  v5 = pm->m_Items[0];
  v4->m_Items[0] = v5;
  v6 = v->pm;
  v7 = this->pm;
  v9 = v6->m_Items[1];
  v7->m_Items[1] = v9;
  v11 = v->pm;
  v12 = this->pm;
  v14 = v11->m_Items[2];
  v12->m_Items[2] = v14;
}

// 0x15b2da0
sdfIVector3_t *sdfIVector3_t__Create(s32 x, s32 y, s32 z) {
  Il2CppObject *v7;
  Il2CppClass *klass;
  Il2CppClass *v10;
  Il2CppClass *v12;

  v7 = Allocate(sdfIVector3_t);
  v7[1].klass = NewSpecific(s32, 3u);
  _ctor(v7, 0);
  klass = v7[1].klass;
  LODWORD(klass->_1.byval_arg.data) = x;
  v10 = v7[1].klass;
  HIDWORD(v10->_1.byval_arg.data) = y;
  v12 = v7[1].klass;
  v12->_1.byval_arg.bits = z;
  return v7;
}

// 0x15b3180
void sdfIVector4_t__Copy(sdfIVector4_t *this, sdfIVector4_t *v) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v4;
  s32 v5;
  struct System_Int32_array *v6;
  struct System_Int32_array *v7;
  s32 v9;
  struct System_Int32_array *v11;
  struct System_Int32_array *v12;
  s32 v14;
  struct System_Int32_array *v16;
  struct System_Int32_array *v17;
  s32 v19;

  pm = v->pm;
  v4 = this->pm;
  v5 = pm->m_Items[0];
  v4->m_Items[0] = v5;
  v6 = v->pm;
  v7 = this->pm;
  v9 = v6->m_Items[1];
  v7->m_Items[1] = v9;
  v11 = v->pm;
  v12 = this->pm;
  v14 = v11->m_Items[2];
  v12->m_Items[2] = v14;
  v16 = v->pm;
  v17 = this->pm;
  v19 = v16->m_Items[3];
  v17->m_Items[3] = v19;
}

// 0x15b3030
sdfIVector4_t *sdfIVector4_t__Create(s32 x, s32 y, s32 z, s32 w) {
  Il2CppObject *v9;
  Il2CppClass *klass;
  Il2CppClass *v12;
  Il2CppClass *v14;
  Il2CppClass *v16;

  v9 = Allocate(sdfIVector4_t);
  v9[1].klass = NewSpecific(s32, 4u);
  _ctor(v9, 0);
  klass = v9[1].klass;
  LODWORD(klass->_1.byval_arg.data) = x;
  v12 = v9[1].klass;
  HIDWORD(v12->_1.byval_arg.data) = y;
  v14 = v9[1].klass;
  v14->_1.byval_arg.bits = z;
  v16 = v9[1].klass;
  *(&v16->_1.byval_arg.bits + 1) = w;
  return v9;
}

// 0x15b38a0
void sdfModelDef_t__bCopy(sdfModelDef_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  u32 v10;
  s32 v11;
  u32 v12;
  System_Array_o *v13;

  v7 = *bPos;
  this->modelDef = Byte2UInt32(bytedata, v7);
  *bPos += 4;
  this->matDef_Old = 0;
  v8 = *bPos + 4;
  *bPos = v8;
  this->morphCount = Byte2UInt32(bytedata, v8);
  v9 = *bPos + 4;
  *bPos = v9;
  v10 = Byte2UInt32(bytedata, v9);
  *bPos += 4;
  v11 = v10 + v7;
  v12 = LODWORD(bytedata->max_length) - v11;
  v13 = NewSpecific(byte, v12);
  Copy_3880080(bytedata, v11, v13, 0, v12);
  this->extraData = v13;
}

// 0x15b3dd0
s32 sdfModelExtraChunkMarkPos_t__GetId(sdfModelExtraChunkMarkPos_t *this, u8 **bytedata, s32 bPos) {
  return Byte2UInt32(bytedata, bPos + 4);
}

// 0x15b3e50
s32 sdfModelExtraChunkMarkPos_t__GetSize(sdfModelExtraChunkMarkPos_t *this) {
  return 64;
}

// 0x15b3b80
void sdfModelExtraChunkMarkPos_t__bCopy(sdfModelExtraChunkMarkPos_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;

  v7 = *bPos;
  this->nodeId = Byte2UInt32(bytedata, v7);
  v8 = *bPos + 4;
  *bPos = v8;
  this->id = Byte2UInt32(bytedata, v8);
  v9 = *bPos + 4;
  *bPos = v9;
  this->param = Byte2UInt32(bytedata, v9);
  v10 = *bPos + 4;
  *bPos = v10;
  this->pad1 = Byte2UInt32(bytedata, v10);
  *bPos += 4;
  *&this->pos.x = 0;
  *&this->pos.z = 0;
  this->pos.x = Byte2Float(bytedata, *bPos);
  v11 = *bPos + 4;
  *bPos = v11;
  this->pos.y = Byte2Float(bytedata, v11);
  v12 = *bPos + 4;
  *bPos = v12;
  this->pos.z = Byte2Float(bytedata, v12);
  v13 = *bPos + 4;
  *bPos = v13;
  this->pos.w = Byte2Float(bytedata, v13);
  *bPos += 4;
  *&this->forward.x = 0;
  *&this->forward.z = 0;
  this->forward.x = Byte2Float(bytedata, *bPos);
  v14 = *bPos + 4;
  *bPos = v14;
  this->forward.y = Byte2Float(bytedata, v14);
  v15 = *bPos + 4;
  *bPos = v15;
  this->forward.z = Byte2Float(bytedata, v15);
  v16 = *bPos + 4;
  *bPos = v16;
  this->forward.w = Byte2Float(bytedata, v16);
  *bPos += 4;
  *&this->up.x = 0;
  *&this->up.z = 0;
  this->up.x = Byte2Float(bytedata, *bPos);
  v17 = *bPos + 4;
  *bPos = v17;
  this->up.y = Byte2Float(bytedata, v17);
  v18 = *bPos + 4;
  *bPos = v18;
  this->up.z = Byte2Float(bytedata, v18);
  v19 = *bPos + 4;
  *bPos = v19;
  this->up.w = Byte2Float(bytedata, v19);
  *bPos += 4;
}

// 0x15b3f60
s32 sdfModelExtraChunk_t__GetSize(sdfModelExtraChunk_t *this) {
  return 16;
}

// 0x15b3e70
void sdfModelExtraChunk_t__bCopy(sdfModelExtraChunk_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  this->sPos = *bPos;
  v7 = *bPos;
  this->chunkId = Byte2UInt32(bytedata, v7);
  v8 = *bPos + 4;
  *bPos = v8;
  this->size = Byte2UInt32(bytedata, v8);
  v9 = *bPos + 4;
  *bPos = v9;
  this->data0 = Byte2UInt32(bytedata, v9);
  v10 = *bPos + 4;
  *bPos = v10;
  this->data1 = Byte2UInt32(bytedata, v10);
  *bPos += 4;
}

// 0x15b40a0
void sdfModelNodeDef_t__bCopy(sdfModelNodeDef_t *this, u8 **bytedata, s32 *bPos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;

  v7 = *bPos;
  this->format = Byte2UInt16(bytedata, v7);
  v8 = *bPos + 2;
  *bPos = v8;
  this->pad0 = Byte2UInt16(bytedata, v8);
  v9 = *bPos + 2;
  *bPos = v9;
  this->pad1 = Byte2UInt32(bytedata, v9);
  v10 = *bPos + 4;
  *bPos = v10;
  this->id = Byte2UInt32(bytedata, v10);
  v11 = *bPos + 4;
  *bPos = v11;
  this->parentIndex = Byte2UInt32(bytedata, v11);
  *bPos += 4;
  *&this->rotate.x = 0;
  *&this->rotate.z = 0;
  this->rotate.x = Byte2Float(bytedata, *bPos);
  v12 = *bPos + 4;
  *bPos = v12;
  this->rotate.y = Byte2Float(bytedata, v12);
  v13 = *bPos + 4;
  *bPos = v13;
  this->rotate.z = Byte2Float(bytedata, v13);
  v14 = *bPos + 4;
  *bPos = v14;
  this->rotate.w = Byte2Float(bytedata, v14);
  *bPos += 4;
  *&this->pos.x = 0;
  *&this->pos.z = 0;
  this->pos.x = Byte2Float(bytedata, *bPos);
  v15 = *bPos + 4;
  *bPos = v15;
  this->pos.y = Byte2Float(bytedata, v15);
  v16 = *bPos + 4;
  *bPos = v16;
  this->pos.z = Byte2Float(bytedata, v16);
  v17 = *bPos + 4;
  *bPos = v17;
  this->pos.w = Byte2Float(bytedata, v17);
  *bPos += 4;
  *&this->scale.x = 0;
  *&this->scale.z = 0;
  this->scale.x = Byte2Float(bytedata, *bPos);
  v18 = *bPos + 4;
  *bPos = v18;
  this->scale.y = Byte2Float(bytedata, v18);
  v19 = *bPos + 4;
  *bPos = v19;
  this->scale.z = Byte2Float(bytedata, v19);
  v20 = *bPos + 4;
  *bPos = v20;
  this->scale.w = Byte2Float(bytedata, v20);
  v21 = *bPos + 4;
  *bPos = v21;
  this->bounds = Byte2Float(bytedata, v21);
  *bPos += 4;
  this->shape = NewSpecific(object, 3u);
  *bPos += 12;
}

// 0x15b4510
void sdfModelRootNode_t__dCopy(sdfModelRootNode_t *this, sdfModelRootNode_t **dst) {
  sdfModelRootNode_t_o *v3;
  sdfModelRootNode_t_o *v4;
  f32 z;
  f32 w;
  sdfModelRootNode_t_o *v7;
  f32 v8;
  f32 v9;

  (*dst)->nodeList = this->nodeList;
  (*dst)->headNode = this->headNode;
  (*dst)->texList = this->texList;
  (*dst)->matList = this->matList;
  (*dst)->morphList = this->morphList;
  (*dst)->motion = this->motion;
  (*dst)->complexNodeId = this->complexNodeId;
  (*dst)->flags = this->flags;
  (*dst)->drawAttr = this->drawAttr;
  (*dst)->color = this->color;
  v3 = *dst;
  *&v3->tm.m03 = 0;
  *&v3->tm.m23 = 0;
  *&v3->tm.m02 = 0;
  *&v3->tm.m22 = 0;
  *&v3->tm.m01 = 0;
  *&v3->tm.m21 = 0;
  *&v3->tm.m00 = 0;
  *&v3->tm.m20 = 0;
  v4 = *dst;
  z = this->rotate.z;
  w = this->rotate.w;
  *&v4->rotate.x = *&this->rotate.x;
  v4->rotate.z = z;
  v4->rotate.w = w;
  v7 = *dst;
  v8 = this->scale.z;
  v9 = this->scale.w;
  *&v7->scale.x = *&this->scale.x;
  v7->scale.z = v8;
  v7->scale.w = v9;
  (*dst)->light = this->light;
  (*dst)->fog = this->fog;
  (*dst)->faceDivSoften = this->faceDivSoften;
  (*dst)->faceDivBias = this->faceDivBias;
  (*dst)->extraData = this->extraData;
  (*dst)->zBias = this->zBias;
  (*dst)->modelobj = 0;
  (*dst)->oData = this->oData;
  (*dst)->effpos_type = this->effpos_type;
  (*dst)->reversePB = this->reversePB;
}

// 0x15b8960
void sdfPacDecodeCb_t__Clear(sdfPacDecodeCb_t *this) {
  *&this->stat = 0;
  *&this->srcLength = 0;
  this->workPtr = 0;
  HIDWORD(this->decodeWork) = 0;
  *(&this->decodeCb + 4) = 0;
  *(&this->decompWork + 4) = 0;
  *&this->rest = 0;
  this->onEnd = 0;
  this->srcData = 0;
  this->callback = 0;
  this->decoder = 0;
  this->resrcHead = 0;
  this->resrcTail = 0;
}

// 0x15b9350
s32 sdfPacStdBlockHeader_t__Set(sdfPacStdBlockHeader_t *this, u8 **data, s32 index) {
  s64 v8;
  u32 v10;
  u8 compression;
  s32 v12;
  struct System_Byte_array *v13;

  v8 = index + 1LL;
  this->fileType = data->m_Items[index];
  this->compression = data->m_Items[v8];
  this->userId = ToUInt16(data, index + 2);
  this->size = ToUInt32(data, index + 4, 0);
  this->magicCode = ToUInt32(data, index + 8, 0);
  v10 = ToUInt32(data, index + 12, 0);
  compression = this->compression;
  this->realSize = v10;
  v12 = compression & 0xF0;
  v13 = NewSpecific(byte, compression & 0xF0);
  this->compdata = v13;
  Copy_3880080(data, index + 16, v13, 0, v12);
  return 16;
}
