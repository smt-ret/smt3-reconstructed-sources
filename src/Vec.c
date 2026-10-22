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
  sdfMatrix4_t_Fields *p_fields;
  f32 m00;
  f32 m11;
  f32 m22;
  f32 v9;
  s64 v10;
  sdfMatrix4_t_Fields *v11;
  _BOOL4 v12;
  u32 v13;
  u32 v14;
  u32 v15;
  s32 v16;
  f32 v17;
  s32 v18;
  f32 v19;
  long f64 v21;
  f32 v22;
  f32 v23;

  p_fields = &mat->fields;
  m00 = mat->pm.m00;
  m11 = mat->pm.m11;
  m22 = mat->pm.m22;
  v9 = ((m00 + m11) + m22) + 1.0;
  if (v9 >= 1.0)
  {
    sdfSqrt(v9);
    sub_854930(q, 3u);
    sub_854930(q, 0);
    sub_854930(q, 1u);
    sub_854930(q, 2u);
  }
  else
  {
    if (m00 > m11)
      v10 = 0;
    else
      v10 = 5;
    v11 = &mat->fields;
    v12 = m00 <= m11;
    if (m22 <= (loc_19FFB20)(v11, v10, 0))
      v13 = v12;
    else
      v13 = 2;
    v14 = (v13 + 1) % 3;
    v15 = (v14 + 1) % 3;
    v16 = 4 * v14;
    LODWORD(v17) = COERCE_UNSIGNED_INT128((loc_19FFB20)(p_fields, v13 & 0xFFFFFFF3 | (4 * (v13 & 3)), 0));
    v18 = 4 * v15;
    LODWORD(v19) = COERCE_UNSIGNED_INT128((loc_19FFB20)(p_fields, 5 * v14, 0));
    v21 = (loc_19FFB20)(p_fields, (4 * v15) | v15, 0);
    v22 = *&v21;
    v23 = sdfSqrt(((v17 - v19) - v22) + 1.0, 0);
    if ((v23 + v23) == 0.0)
    {
      sub_854930(q, v13);
      sub_854930(q, v14);
      sub_854930(q, v15);
    }
    else
    {
      sub_854930(q, v13);
      (loc_19FFB20)(p_fields, (4 * v13) | v14, 0);
      (loc_19FFB20)(p_fields, v13 | v16, 0);
      sub_854930(q, v14);
      (loc_19FFB20)(p_fields, (4 * v13) | v15, 0);
      (loc_19FFB20)(p_fields, v13 | v18, 0);
      sub_854930(q, v15);
      (loc_19FFB20)(p_fields, (v15 | v16), 0);
      (loc_19FFB20)(p_fields, (v18 | v14), 0);
    }
    sub_854930(q, 3u);
  }
}

// 0x134ac60
void SetVec(sdfVector4_t *pVec, f32 x, f32 y, f32 z) {
  sub_854930(pVec, 0);
  sub_854930(pVec, 1u);
  sub_854930(pVec, 2u);
}

// 0x134aa00
void VecAdd(sdfVector4_t *pVec, sdfVector4_t pVec2) {
  UnityEngine_Vector4_o v4;

  v4 = pVec2;
  sub_854710(pVec, 0);
  sub_854710(&v4, 0);
  sub_854930(pVec, 0);
  sub_854710(pVec, 1u);
  sub_854710(&v4, 1u);
  sub_854930(pVec, 1u);
  sub_854710(pVec, 2u);
  sub_854710(&v4, 2u);
  sub_854930(pVec, 2u);
}

// 0x134bb80
sdfVector4_t VecMaltMat(sdfVector4_t *vec, sdfMatrix4_t *mat) {
  s64 v4;
  s64 v9;
  s64 v10;
  UnityEngine_Vector4_o result;

  v9 = 0;
  v10 = 0;
  sub_854710(vec, 0);
  sub_854710(vec, 1u);
  sub_854710(vec, 2u);
  sub_854930(&v9, 0);
  sub_854710(vec, 0);
  sub_854710(vec, 1u);
  sub_854710(vec, 2u);
  sub_854930(&v9, 1u);
  sub_854710(vec, 0);
  sub_854710(vec, 1u);
  sub_854710(vec, 2u);
  sub_854930(&v9, 2u);
  v4 = v10;
  *&vec->x = v9;
  *&vec->z = v4;
  result.x = vec->x;
  result.y = vec->y;
  result.z = vec->z;
  result.w = vec->w;
  return result;
}

// 0x134a950
f32 VecNormalize(sdfVector4_t *pVec) {
  f32 v3;

  v3 = Vecscalar(*pVec, pVec);
  if (v3 != 0.0)
  {
    sub_854710(pVec, 0);
    sub_854930(pVec, 0);
    sub_854710(pVec, 1u);
    sub_854930(pVec, 1u);
    sub_854710(pVec, 2u);
    sub_854930(pVec, 2u);
  }
  return v3;
}

// 0x134a040
void VecRotateAx(sdfVector4_t *pVec, sdfVector4_t rvec, f32 Radian) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  s64 v10;
  sdfMatrix3_t_o *v11;
  struct UnityEngine_Vector3_array *pm;
  f32 v14;
  f32 v15;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  struct UnityEngine_Vector3_array *v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  struct UnityEngine_Vector3_array *v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  struct UnityEngine_Vector3_array *v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  struct UnityEngine_Vector3_array *v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  struct UnityEngine_Vector3_array *v60;
  f32 v61;
  f32 v62;
  f32 v63;
  f32 v64;
  f32 v65;
  f32 v66;
  f32 v67;
  f32 v68;
  struct UnityEngine_Vector3_array *v70;
  f32 v71;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 v77;
  f32 v78;
  struct UnityEngine_Vector3_array *v80;
  f32 v81;
  f32 v82;
  f32 v83;
  f32 v84;
  f32 v85;
  f32 v86;
  f32 v87;
  f32 v88;
  struct UnityEngine_Vector3_array *v90;
  f32 v91;
  f32 v92;
  f32 v93;
  f32 v94;
  f32 v95;
  f32 v96;
  struct UnityEngine_Vector3_array *v98;
  struct UnityEngine_Vector3_array *v100;
  struct UnityEngine_Vector3_array *v102;
  struct UnityEngine_Vector3_array *v104;
  struct UnityEngine_Vector3_array *v106;
  struct UnityEngine_Vector3_array *v108;
  struct UnityEngine_Vector3_array *v110;
  struct UnityEngine_Vector3_array *v112;
  struct UnityEngine_Vector3_array *v114;
  u64 v116[2];
  UnityEngine_Vector4_o pVeca;

  w = rvec.w;
  z = rvec.z;
  y = rvec.y;
  x = rvec.x;
  pVeca.x = x;
  pVeca.y = y;
  pVeca.z = z;
  pVeca.w = w;
  v10 = *&pVec->z;
  v116[0] = *&pVec->x;
  v116[1] = v10;
  v11 = Allocate(sdfMatrix3_t);
  sdfMatrix3_t___ctor(v11);
  VecNormalize(&pVeca);
  pm = v11->pm;
  sub_854710(&pVeca, 0);
  v15 = v14;
  sub_854710(&pVeca, 0);
  v18 = v17;
  v19 = sdfCos(Radian);
  v20 = sdfCos(Radian);
  sub_8529B0(pm->m_Items, 0, v20 + ((v15 * v18) * (1.0 - v19)));
  v22 = v11->pm;
  sub_854710(&pVeca, 0);
  v24 = v23;
  sub_854710(&pVeca, 1u);
  v26 = v25;
  v27 = sdfCos(Radian);
  sub_854710(&pVeca, 2u);
  v29 = v28;
  v30 = sdfSin(Radian);
  sub_8529B0(v22->m_Items, 1, ((v24 * v26) * (1.0 - v27)) - (v29 * v30));
  v32 = v11->pm;
  sub_854710(&pVeca, 0);
  v34 = v33;
  sub_854710(&pVeca, 2u);
  v36 = v35;
  v37 = sdfCos(Radian);
  sub_854710(&pVeca, 1u);
  v39 = v38;
  v40 = sdfSin(Radian);
  sub_8529B0(v32->m_Items, 2, ((v34 * v36) * (1.0 - v37)) + (v39 * v40));
  v42 = v11->pm;
  sub_854710(&pVeca, 1u);
  v44 = v43;
  sub_854710(&pVeca, 0);
  v46 = v45;
  v47 = sdfCos(Radian);
  sub_854710(&pVeca, 2u);
  v49 = v48;
  v50 = sdfSin(Radian);
  sub_8529B0(&v42->m_Items[1], 0, ((v44 * v46) * (1.0 - v47)) + (v49 * v50));
  v52 = v11->pm;
  sub_854710(&pVeca, 1u);
  v54 = v53;
  sub_854710(&pVeca, 1u);
  v56 = v55;
  v57 = sdfCos(Radian);
  v58 = sdfCos(Radian);
  sub_8529B0(&v52->m_Items[1], 1, v58 + ((v54 * v56) * (1.0 - v57)));
  v60 = v11->pm;
  sub_854710(&pVeca, 1u);
  v62 = v61;
  sub_854710(&pVeca, 2u);
  v64 = v63;
  v65 = sdfCos(Radian);
  sub_854710(&pVeca, 0);
  v67 = v66;
  v68 = sdfSin(Radian);
  sub_8529B0(&v60->m_Items[1], 2, ((v62 * v64) * (1.0 - v65)) - (v67 * v68));
  v70 = v11->pm;
  sub_854710(&pVeca, 2u);
  v72 = v71;
  sub_854710(&pVeca, 0);
  v74 = v73;
  v75 = sdfCos(Radian);
  sub_854710(&pVeca, 1u);
  v77 = v76;
  v78 = sdfSin(Radian);
  sub_8529B0(&v70->m_Items[2], 0, ((v72 * v74) * (1.0 - v75)) - (v77 * v78));
  v80 = v11->pm;
  sub_854710(&pVeca, 2u);
  v82 = v81;
  sub_854710(&pVeca, 1u);
  v84 = v83;
  v85 = sdfCos(Radian);
  sub_854710(&pVeca, 0);
  v87 = v86;
  v88 = sdfSin(Radian);
  sub_8529B0(&v80->m_Items[2], 1, ((v82 * v84) * (1.0 - v85)) + (v87 * v88));
  v90 = v11->pm;
  sub_854710(&pVeca, 2u);
  v92 = v91;
  sub_854710(&pVeca, 2u);
  v94 = v93;
  v95 = sdfCos(Radian);
  v96 = sdfCos(Radian);
  sub_8529B0(&v90->m_Items[2], 2, v96 + ((v92 * v94) * (1.0 - v95)));
  sub_854710(v116, 0);
  v98 = v11->pm;
  sub_8527D0(&v98->m_Items[0].x, 0);
  sub_854710(v116, 1u);
  v100 = v11->pm;
  sub_8527D0(&v100->m_Items[1].x, 0);
  sub_854710(v116, 2u);
  v102 = v11->pm;
  sub_8527D0(&v102->m_Items[2].x, 0);
  sub_854930(pVec, 0);
  sub_854710(v116, 0);
  v104 = v11->pm;
  sub_8527D0(&v104->m_Items[0].x, 1);
  sub_854710(v116, 1u);
  v106 = v11->pm;
  sub_8527D0(&v106->m_Items[1].x, 1);
  sub_854710(v116, 2u);
  v108 = v11->pm;
  sub_8527D0(&v108->m_Items[2].x, 1);
  sub_854930(pVec, 1u);
  sub_854710(v116, 0);
  v110 = v11->pm;
  sub_8527D0(&v110->m_Items[0].x, 2);
  sub_854710(v116, 1u);
  v112 = v11->pm;
  sub_8527D0(&v112->m_Items[1].x, 2);
  sub_854710(v116, 2u);
  v114 = v11->pm;
  sub_8527D0(&v114->m_Items[2].x, 2);
  sub_854930(pVec, 2u);
}

// 0x1349bc0
void VecRotateX(sdfVector4_t *pVec, f32 Radian) {
  u64 v6[2];

  v6[0] = 0;
  v6[1] = 0;
  sub_854710(pVec, 1u);
  sdfCos(Radian);
  sub_854710(pVec, 2u);
  sdfSin(Radian);
  sub_854930(v6, 1u);
  sub_854710(pVec, 1u);
  sdfSin(Radian);
  sub_854710(pVec, 2u);
  sdfCos(Radian);
  sub_854930(v6, 2u);
  sub_854710(v6, 1u);
  sub_854930(pVec, 1u);
  sub_854710(v6, 2u);
  sub_854930(pVec, 2u);
}

// 0x1349d40
void VecRotateY(sdfVector4_t *pVec, f32 Radian) {
  u64 v6[2];

  v6[0] = 0;
  v6[1] = 0;
  sub_854710(pVec, 0);
  sdfCos(Radian);
  sub_854710(pVec, 2u);
  sdfSin(Radian);
  sub_854930(v6, 0);
  sub_854710(pVec, 0);
  sdfSin(Radian);
  sub_854710(pVec, 2u);
  sdfCos(Radian);
  sub_854930(v6, 2u);
  sub_854710(v6, 0);
  sub_854930(pVec, 0);
  sub_854710(v6, 2u);
  sub_854930(pVec, 2u);
}

// 0x1349ec0
void VecRotateZ(sdfVector4_t *pVec, f32 Radian) {
  u64 v6[2];

  v6[0] = 0;
  v6[1] = 0;
  sub_854710(pVec, 0);
  sdfCos(Radian);
  sub_854710(pVec, 1u);
  sdfSin(Radian);
  sub_854930(v6, 0);
  sub_854710(pVec, 0);
  sdfSin(Radian);
  sub_854710(pVec, 1u);
  sdfCos(Radian);
  sub_854930(v6, 1u);
  sub_854710(v6, 0);
  sub_854930(pVec, 0);
  sub_854710(v6, 1u);
  sub_854930(pVec, 1u);
}

// 0x134aae0
void VecSub(sdfVector4_t *pVec, sdfVector4_t pVec2) {
  UnityEngine_Vector4_o v4;

  v4 = pVec2;
  sub_854710(pVec, 0);
  sub_854710(&v4, 0);
  sub_854930(pVec, 0);
  sub_854710(pVec, 1u);
  sub_854710(&v4, 1u);
  sub_854930(pVec, 1u);
  sub_854710(pVec, 2u);
  sub_854710(&v4, 2u);
  sub_854930(pVec, 2u);
}

// 0x134abc0
void VecTranslate(sdfVector4_t *pVec, f32 tx, f32 ty, f32 tz) {
  sub_854710(pVec, 0);
  sub_854930(pVec, 0);
  sub_854710(pVec, 1u);
  sub_854930(pVec, 1u);
  sub_854710(pVec, 2u);
  sub_854930(pVec, 2u);
}

// 0x134acc0
void VecZoom(sdfVector4_t *pVec, f32 s) {
  sub_854710(pVec, 0);
  sub_854930(pVec, 0);
  sub_854710(pVec, 1u);
  sub_854930(pVec, 1u);
  sub_854710(pVec, 2u);
  sub_854930(pVec, 2u);
}

// 0x134b020
void Veccross(sdfVector4_t *vec, sdfVector4_t vec1, sdfVector4_t vec2) {
  UnityEngine_Vector4_o v6;
  UnityEngine_Vector4_o pVec;

  pVec = vec1;
  v6 = vec2;
  VecNormalize(&pVec);
  VecNormalize(&v6);
  sub_854710(&pVec, 1u);
  sub_854710(&v6, 2u);
  sub_854710(&pVec, 2u);
  sub_854710(&v6, 1u);
  sub_854930(vec, 0);
  sub_854710(&pVec, 2u);
  sub_854710(&v6, 0);
  sub_854710(&pVec, 0);
  sub_854710(&v6, 2u);
  sub_854930(vec, 1u);
  sub_854710(&pVec, 0);
  sub_854710(&v6, 1u);
  sub_854710(&pVec, 1u);
  sub_854710(&v6, 0);
  sub_854930(vec, 2u);
}

// 0x134ae70
f32 Vecdot(sdfVector4_t vec1, sdfVector4_t vec2) {
  f32 v5;
  f32 v6;
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
  UnityEngine_Vector4_o pVec;

  pVec = vec1;
  v17 = vec2;
  VecNormalize(&pVec);
  VecNormalize(&v17);
  sub_854710(&pVec, 0);
  v6 = v5;
  sub_854710(&v17, 0);
  v8 = v7;
  sub_854710(&pVec, 1u);
  v10 = v9;
  sub_854710(&v17, 1u);
  v12 = v11;
  sub_854710(&pVec, 2u);
  v14 = v13;
  sub_854710(&v17, 2u);
  return ((v6 * v8) + (v10 * v12)) + (v14 * v15);
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
  f32 v2;
  f32 v3;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v13;
  f32 v14;
  UnityEngine_Vector4_o v16;

  v16 = pVec;
  sub_854710(&v16, 0);
  v3 = v2;
  sub_854710(&v16, 0);
  v5 = v4;
  sub_854710(&v16, 1u);
  v7 = v6;
  sub_854710(&v16, 1u);
  v9 = v8;
  sub_854710(&v16, 2u);
  v11 = v10;
  sub_854710(&v16, 2u);
  v14 = v13;
  return sdfSqrt(((v3 * v5) + (v7 * v9)) + (v11 * v14), 0);
}

// 0x134bd00
sdfMemHandle_t *bezierGetPos(sdfVector4_t **point, s32 n, s32 n_line) {
  __int128 v4;
  u64 *v8;
  u64 *v9;
  u64 v10;
  f32 *v12;
  s64 *Ptr;
  Il2CppClass *v14;
  s64 *v15;
  s64 *Interface;
  char *v17;
  s64 *v18;
  u64 v19;
  f32 *v21;
  f32 *v22;
  f32 v23;
  s32 v24;
  s32 v25;
  f32 v33;
  u64 v34;
  __int128 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  u64 v39;
  f32 v41;
  s32 v42;
  bool v43;
  f32 v44;
  s32 v45;
  UnityEngine_Vector4_o *v47;
  f32 v48;
  f32 v49;
  f32 v51;
  f32 v52;
  f32 v54;
  f32 v55;
  s64 v57;
  u64 *v60;
  s32 v62;
  u64 v63[3];

  v8 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v8);
  v9 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v9);
  v10 = (n + 1);
  v12 = NewSpecific(f32, v10);
  Ptr = sdfMemGetPtr(v8);
  if (!Ptr)
    goto LABEL_12;
LABEL_6:
  v15 = Ptr;
  Interface = QueryInterface(Ptr, UnityEngine_Vector4);
  if (!Interface)
  {
    sub_8FC2C0(*(*v15 + 64), v14, v63);
    if ((v63[0] & 1) != 0)
      v17 = v63[2];
    else
      v17 = v63 + 1;
    v18 = sub_8C4940(v17);
  }
LABEL_13:
  v62 = n_line;
  if ((n & 0x80000000) == 0)
  {
    v19 = 0;
    do
    {
      v21 = &v12[v19];
      v21[8] = 1.0;
      v22 = v21 + 8;
      if (v19)
      {
        v23 = 1.0;
        v24 = 0;
        v25 = n;
        do
        {
          v23 = (v23 * v25--) / ++v24;
          *v22 = v23;
        }
        while (v19 != v24);
      }
      ++v19;
    }
    while (v19 != v10);
  }
  sub_854710(point->m_Items, 0);
  sub_854930((Interface + 4), 0);
  sub_854710(point->m_Items, 1u);
  sub_854930((Interface + 4), 1u);
  sub_854710(point->m_Items, 2u);
  sub_854930((Interface + 4), 2u);
  if ((n_line & 0x80000000) == 0)
  {
    v33 = 1.0;
    v34 = 0;
    do
    {
      LODWORD(v4) = 0;
      v35 = v4;
      if ((n & 0x80000000) == 0)
      {
        v36 = v34 / v62;
        LODWORD(v35) = 0;
        v4 = v35;
        v37 = 0.0;
        v38 = v33 - v36;
        v39 = 0;
        do
        {
          v41 = v33;
          if (v39)
          {
            v41 = v33;
            v42 = 2;
            do
            {
              v41 = v36 * v41;
              v43 = v42++ > v39;
            }
            while (!v43);
          }
          v44 = v33;
          if (n - v39 >= 1)
          {
            v44 = v33;
            v45 = 2;
            do
            {
              v44 = v38 * v44;
              v43 = v45++ > (n - v39);
            }
            while (!v43);
          }
          v47 = &point->m_Items[v39];
          v48 = v12[v39 + 8] * (v41 * v44);
          sub_854710(v47, 0);
          v51 = v48 * v49;
          sub_854710(v47, 1u);
          *&v4 = *&v4 + v51;
          v37 = v37 + (v48 * v52);
          sub_854710(v47, 2u);
          v55 = v48 * v54;
          v33 = 1.0;
          *&v35 = *&v35 + v55;
          ++v39;
        }
        while (v39 != v10);
      }
      v57 = &Interface[2 * v34 + 4];
      sub_854930(v57, 0);
      sub_854930(v57, 1u);
      sub_854930(v57, 2u);
      ++v34;
    }
    while (v34 != v62 + 1);
  }
  v60 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v60);
  return v60;
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
