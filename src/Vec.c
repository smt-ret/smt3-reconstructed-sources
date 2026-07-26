#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;

f32 VecNormalize(sdfVector4_t *pVec);
f32 Vecdot(sdfVector4_t vec1, sdfVector4_t vec2);
f32 Vecscalar(sdfVector4_t pVec);
f32 sdfCos(f32 aRadius);
void *sdfMemGetPtr(sdfMemHandle_t *aHandle);
f32 sdfSin(f32 aRadius);
f32 sdfSqrt(f32 aValue);

// 0x134b1b0
void MatRotateX(sdfMatrix4_t **pmat, f32 Radian) {
  sdfMatrix4_t_o *v5;
  f32 m10;
  f32 v8;
  f32 m20;
  f32 m11;
  f32 v11;
  f32 m21;
  f32 m12;
  f32 v14;
  f32 m22;
  f32 m13;
  f32 v17;
  f32 m23;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;

  v5 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v5);
  v5->pm.m00 = (*pmat)->pm.m00;
  v5->pm.m01 = (*pmat)->pm.m01;
  v5->pm.m02 = (*pmat)->pm.m02;
  v5->pm.m03 = (*pmat)->pm.m03;
  m10 = (*pmat)->pm.m10;
  v8 = sdfCos(Radian);
  m20 = (*pmat)->pm.m20;
  v5->pm.m10 = (m10 * v8) + (m20 * sdfSin(Radian));
  m11 = (*pmat)->pm.m11;
  v11 = sdfCos(Radian);
  m21 = (*pmat)->pm.m21;
  v5->pm.m11 = (m11 * v11) + (m21 * sdfSin(Radian));
  m12 = (*pmat)->pm.m12;
  v14 = sdfCos(Radian);
  m22 = (*pmat)->pm.m22;
  v5->pm.m12 = (m12 * v14) + (m22 * sdfSin(Radian));
  m13 = (*pmat)->pm.m13;
  v17 = sdfCos(Radian);
  m23 = (*pmat)->pm.m23;
  v5->pm.m13 = (m13 * v17) + (m23 * sdfSin(Radian));
  v19 = (*pmat)->pm.m10;
  v20 = sdfSin(Radian);
  v21 = (*pmat)->pm.m20;
  v5->pm.m20 = (v21 * sdfCos(Radian)) - (v19 * v20);
  v22 = (*pmat)->pm.m11;
  v23 = sdfSin(Radian);
  v24 = (*pmat)->pm.m21;
  v5->pm.m21 = (v24 * sdfCos(Radian)) - (v22 * v23);
  v25 = (*pmat)->pm.m12;
  v26 = sdfSin(Radian);
  v27 = (*pmat)->pm.m22;
  v5->pm.m22 = (v27 * sdfCos(Radian)) - (v25 * v26);
  v28 = (*pmat)->pm.m13;
  v29 = sdfSin(Radian);
  v30 = (*pmat)->pm.m23;
  v5->pm.m23 = (v30 * sdfCos(Radian)) - (v28 * v29);
  v5->pm.m30 = (*pmat)->pm.m30;
  v5->pm.m31 = (*pmat)->pm.m31;
  v5->pm.m32 = (*pmat)->pm.m32;
  v5->pm.m33 = (*pmat)->pm.m33;
  *pmat = v5;
}

// 0x134b490
void MatRotateY(sdfMatrix4_t **pmat, f32 Radian) {
  sdfMatrix4_t_o *v5;
  f32 m00;
  f32 v8;
  f32 m20;
  f32 m01;
  f32 v11;
  f32 m21;
  f32 m02;
  f32 v14;
  f32 m22;
  f32 m03;
  f32 v17;
  f32 m23;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;

  v5 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v5);
  m00 = (*pmat)->pm.m00;
  v8 = sdfCos(Radian);
  m20 = (*pmat)->pm.m20;
  v5->pm.m00 = (m00 * v8) - (m20 * sdfSin(Radian));
  m01 = (*pmat)->pm.m01;
  v11 = sdfCos(Radian);
  m21 = (*pmat)->pm.m21;
  v5->pm.m01 = (m01 * v11) - (m21 * sdfSin(Radian));
  m02 = (*pmat)->pm.m02;
  v14 = sdfCos(Radian);
  m22 = (*pmat)->pm.m22;
  v5->pm.m02 = (m02 * v14) - (m22 * sdfSin(Radian));
  m03 = (*pmat)->pm.m03;
  v17 = sdfCos(Radian);
  m23 = (*pmat)->pm.m23;
  v5->pm.m03 = (m03 * v17) - (m23 * sdfSin(Radian));
  v5->pm.m10 = (*pmat)->pm.m10;
  v5->pm.m11 = (*pmat)->pm.m11;
  v5->pm.m12 = (*pmat)->pm.m12;
  v5->pm.m13 = (*pmat)->pm.m13;
  v19 = (*pmat)->pm.m00;
  v20 = sdfSin(Radian);
  v21 = (*pmat)->pm.m20;
  v5->pm.m20 = (v19 * v20) + (v21 * sdfCos(Radian));
  v22 = (*pmat)->pm.m01;
  v23 = sdfSin(Radian);
  v24 = (*pmat)->pm.m21;
  v5->pm.m21 = (v22 * v23) + (v24 * sdfCos(Radian));
  v25 = (*pmat)->pm.m02;
  v26 = sdfSin(Radian);
  v27 = (*pmat)->pm.m22;
  v5->pm.m22 = (v25 * v26) + (v27 * sdfCos(Radian));
  v28 = (*pmat)->pm.m03;
  v29 = sdfSin(Radian);
  v30 = (*pmat)->pm.m23;
  v5->pm.m23 = (v28 * v29) + (v30 * sdfCos(Radian));
  v5->pm.m30 = (*pmat)->pm.m30;
  v5->pm.m31 = (*pmat)->pm.m31;
  v5->pm.m32 = (*pmat)->pm.m32;
  v5->pm.m33 = (*pmat)->pm.m33;
  *pmat = v5;
}

// 0x134b770
void MatRotateZ(sdfMatrix4_t **pmat, f32 Radian) {
  sdfMatrix4_t_o *v5;
  f32 m00;
  f32 v8;
  f32 m10;
  f32 m01;
  f32 v11;
  f32 m11;
  f32 m02;
  f32 v14;
  f32 m12;
  f32 m03;
  f32 v17;
  f32 m13;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;

  v5 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v5);
  m00 = (*pmat)->pm.m00;
  v8 = sdfCos(Radian);
  m10 = (*pmat)->pm.m10;
  v5->pm.m00 = (m00 * v8) + (m10 * sdfSin(Radian));
  m01 = (*pmat)->pm.m01;
  v11 = sdfCos(Radian);
  m11 = (*pmat)->pm.m11;
  v5->pm.m01 = (m01 * v11) + (m11 * sdfSin(Radian));
  m02 = (*pmat)->pm.m02;
  v14 = sdfCos(Radian);
  m12 = (*pmat)->pm.m12;
  v5->pm.m02 = (m02 * v14) + (m12 * sdfSin(Radian));
  m03 = (*pmat)->pm.m03;
  v17 = sdfCos(Radian);
  m13 = (*pmat)->pm.m13;
  v5->pm.m03 = (m03 * v17) + (m13 * sdfSin(Radian));
  v19 = (*pmat)->pm.m00;
  v20 = sdfSin(Radian);
  v21 = (*pmat)->pm.m10;
  v5->pm.m10 = (v21 * sdfCos(Radian)) - (v19 * v20);
  v22 = (*pmat)->pm.m01;
  v23 = sdfSin(Radian);
  v24 = (*pmat)->pm.m11;
  v5->pm.m11 = (v24 * sdfCos(Radian)) - (v22 * v23);
  v25 = (*pmat)->pm.m02;
  v26 = sdfSin(Radian);
  v27 = (*pmat)->pm.m12;
  v5->pm.m12 = (v27 * sdfCos(Radian)) - (v25 * v26);
  v28 = (*pmat)->pm.m03;
  v29 = sdfSin(Radian);
  v30 = (*pmat)->pm.m13;
  v5->pm.m13 = (v30 * sdfCos(Radian)) - (v28 * v29);
  v5->pm.m20 = (*pmat)->pm.m20;
  v5->pm.m21 = (*pmat)->pm.m21;
  v5->pm.m22 = (*pmat)->pm.m22;
  v5->pm.m23 = (*pmat)->pm.m23;
  v5->pm.m30 = (*pmat)->pm.m30;
  v5->pm.m31 = (*pmat)->pm.m31;
  v5->pm.m32 = (*pmat)->pm.m32;
  v5->pm.m33 = (*pmat)->pm.m33;
  *pmat = v5;
}

// 0x134ba50
void MatTrPos(sdfMatrix4_t **pmat, sdfMatrix4_t *amat) {
  u64 *v5;

  v5 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v5);
  (*pmat)->pm.m00 = amat->pm.m00;
  (*pmat)->pm.m01 = amat->pm.m10;
  (*pmat)->pm.m02 = amat->pm.m20;
  (*pmat)->pm.m03 = amat->pm.m30;
  (*pmat)->pm.m10 = amat->pm.m01;
  (*pmat)->pm.m11 = amat->pm.m11;
  (*pmat)->pm.m12 = amat->pm.m21;
  (*pmat)->pm.m13 = amat->pm.m31;
  (*pmat)->pm.m20 = amat->pm.m02;
  (*pmat)->pm.m21 = amat->pm.m12;
  (*pmat)->pm.m22 = amat->pm.m22;
  (*pmat)->pm.m23 = amat->pm.m32;
  (*pmat)->pm.m30 = amat->pm.m03;
  (*pmat)->pm.m31 = amat->pm.m13;
  (*pmat)->pm.m32 = amat->pm.m23;
  (*pmat)->pm.m33 = amat->pm.m33;
}

// 0x134c2f0
void QurtFromMatrix(sdfVector4_t *q, sdfMatrix4_t *mat) {
    sdfSqrt(0);
}

// 0x134ac60
void SetVec(sdfVector4_t *pVec, f32 x, f32 y, f32 z) {
}

// 0x134aa00
void VecAdd(sdfVector4_t *pVec, sdfVector4_t pVec2) {
}

// 0x134bb80
sdfVector4_t VecMaltMat(sdfVector4_t *vec, sdfMatrix4_t *mat) {
    return (sdfVector4_t){0};
}

// 0x134a950
f32 VecNormalize(sdfVector4_t *pVec) {
    Vecscalar((sdfVector4_t){0});
    return 0;
}

// 0x134a040
void VecRotateAx(sdfVector4_t *pVec, sdfVector4_t rvec, f32 Radian) {
    VecNormalize(0);
    sdfCos(0);
    sdfSin(0);
}

// 0x1349bc0
void VecRotateX(sdfVector4_t *pVec, f32 Radian) {
    sdfCos(0);
    sdfSin(0);
}

// 0x1349d40
void VecRotateY(sdfVector4_t *pVec, f32 Radian) {
    sdfCos(0);
    sdfSin(0);
}

// 0x1349ec0
void VecRotateZ(sdfVector4_t *pVec, f32 Radian) {
    sdfCos(0);
    sdfSin(0);
}

// 0x134aae0
void VecSub(sdfVector4_t *pVec, sdfVector4_t pVec2) {
}

// 0x134abc0
void VecTranslate(sdfVector4_t *pVec, f32 tx, f32 ty, f32 tz) {
}

// 0x134acc0
void VecZoom(sdfVector4_t *pVec, f32 s) {
}

// 0x134b020
void Veccross(sdfVector4_t *vec, sdfVector4_t vec1, sdfVector4_t vec2) {
    VecNormalize(0);
}

// 0x134ae70
f32 Vecdot(sdfVector4_t vec1, sdfVector4_t vec2) {
    VecNormalize(0);
    return 0;
}

// 0x134af50
f32 VecdotRad(sdfVector4_t vec1, sdfVector4_t vec2) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v12;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o v15;

  w = vec2.w;
  z = vec2.z;
  y = vec2.y;
  x = vec2.x;
  v7 = vec1.w;
  v8 = vec1.z;
  v9 = vec1.y;
  v10 = vec1.x;
  v14.x = v10;
  v14.y = v9;
  v14.z = v8;
  v14.w = v7;
  v15.x = x;
  v15.y = y;
  v15.z = z;
  v15.w = w;
  v12 = Vecdot(v14, v15);
  return acosf(v12);
}

// 0x134ad50
f32 Vecscalar(sdfVector4_t pVec) {
    sdfSqrt(0);
    return 0;
}

// 0x134bd00
sdfMemHandle_t *bezierGetPos(sdfVector4_t **point, s32 n, s32 n_line) {
    sdfMemGetPtr(0);
    return 0;
}

// 0x134c2c0
f32 i_pow(f32 x, f32 n) {
  f32 v3;
  s32 v4;

  v3 = 1.0;
  if (n >= 1.0)
  {
    v3 = 1.0;
    v4 = 2;
    do
      v3 = v3 * x;
    while (v4++ <= n);
  }
  return v3;
}
