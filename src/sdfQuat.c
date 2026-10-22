#include "types.h"

void Mult(void);
f32 SDF_QUAT_INNERPRODUCT(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
f32 SDF_VU0__GETVECTOR_X(void);
f32 SDF_VU0__GETVECTOR_Z(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void ToMatrix(void);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
f32 sdfTableInterpolation(f32 aValue, u8 **aTable, s32 aTableSize);

// 0x17a9810
f32 EulerAngleAxisY(void) {
  sdfVu0_c *v2;
  f32 v3;
  f32 v5;
  f32 v7;
  u64 v9[8];
  UnityEngine_Vector4_o v10;

  memset(v9, 0, sizeof(v9));
  ToMatrix();
  memmove(v9, v2->static_fields, 0x40u);
  sub_1A00880(v9, 0);
  SDF_VU0__LOADVECTOR(v10);
  SDF_VU0__APPLYMATRIX_XYZ();
  v3 = SDF_VU0__GETVECTOR_Z();
  v5 = SDF_VU0__GETVECTOR_X();
  v7 = v5;
  return sdfAtan2(v3, v7);
}

// 0x179d8c0
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ) {
  f32 v6;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  s32 v19;
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
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  UnityEngine_Vector4_o v40;
  f32 v41;
  f32 v42;

  v41 = aRotateY;
  v42 = aRotateZ;
  v6 = aRotateX * -0.5;
  v39 = sdfCos(v6);
  v9 = (v6 * 0.15915) - (v6 * 0.15915);
  v10 = v9 + 1.0;
  if (v9 >= -0.5)
    v10 = (v6 * 0.15915) - (v6 * 0.15915);
  if (v9 > 0.5)
    v11 = v9 + -1.0;
  else
    v11 = v10;
  v12 = -0.5 - v11;
  if (v11 >= -0.25)
    v12 = v11;
  if (v11 > 0.25)
    v13 = 0.5 - v11;
  else
    v13 = v12;
  v14 = v13 * 4.0;
  v15 = v14 * (v14 * v14);
  v16 = (v14 * v14) * v15;
  v17 = (v14 * v14) * v16;
  v37 = (((v14 * 1.5708) + (v15 * -0.64596)) + (v16 * 0.07969)) + (v17 * -0.0046738);
  v36 = ((v14 * v14) * v17) * 0.00015148;
  v38 = sdfCos(v41 * -0.5);
  v19 = ((v41 * -0.5) * 0.15915);
  v20 = ((v41 * -0.5) * 0.15915) - v19;
  v21 = v20 + 1.0;
  if (v20 >= -0.5)
    v21 = ((v41 * -0.5) * 0.15915) - v19;
  if (v20 > 0.5)
    v22 = v20 + -1.0;
  else
    v22 = v21;
  v23 = -0.5 - v22;
  if (v22 >= -0.25)
    v23 = v22;
  if (v22 > 0.25)
    v24 = 0.5 - v22;
  else
    v24 = v23;
  v25 = v24 * 4.0;
  v26 = v25 * v25;
  v27 = v25 * (v25 * v25);
  v28 = (((v25 * 1.5708) + (v27 * -0.64596)) + (((v25 * v25) * v27) * 0.07969)) + ((v26 * (v26 * v27)) * -0.0046738);
  v41 = -0.0046738;
  v29 = (v26 * (v26 * ((v25 * v25) * v27))) * 0.00015148;
  v30 = sdfCos(v42 * -0.5);
  v31 = ((v42 * -0.5) * 0.15915) - ((v42 * -0.5) * 0.15915);
  if (v31 <= 0.5)
  {
    v32 = -0.5;
    if (v31 >= -0.5)
      goto LABEL_31;
    v33 = 1.0;
  }
  else
  {
    v32 = -0.5;
    v33 = -1.0;
  }
  v31 = v31 + v33;
LABEL_31:
  if (v31 <= 0.25)
  {
    if (v31 < -0.25)
      v31 = v32 - v31;
  }
  else
  {
    v31 = 0.5 - v31;
  }
  v34 = v31 * 4.0;
  *&v40.x = 0;
  *&v40.z = 0;
  v35 = ((((v34 * 1.5708) + ((v34 * (v34 * v34)) * -0.64596)) + (((v34 * v34) * (v34 * (v34 * v34))) * 0.07969))
       + (((v34 * v34) * ((v34 * v34) * (v34 * (v34 * v34)))) * v41))
      + (((v34 * v34) * ((v34 * v34) * ((v34 * v34) * (v34 * (v34 * v34))))) * 0.00015148);
  sub_854690(
    &v40.x,
    ((v37 + v36) * (v38 * v30)) + (v39 * ((v28 + v29) * v35)),
    (v39 * (v30 * (v28 + v29))) - ((v37 + v36) * (v38 * v35)),
    ((v37 + v36) * (v30 * (v28 + v29))) + (v39 * (v38 * v35)),
    (v39 * (v38 * v30)) - ((v37 + v36) * ((v28 + v29) * v35)));
  SDF_VU0__LOADVECTOR(v40);
}

// 0x17a8860
void FromEulerXYZ(f32 aRotateX, f32 aRotateY, f32 aRotateZ) {
  f32 v9;
  s32 v10;
  f32 v11;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  s32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  s32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v59;
  UnityEngine_Vector4_o v60;
  f32 v61;
  f32 v62;

  v9 = -aRotateX;
  v58 = aRotateZ;
  if (aRotateX >= -3.1416)
  {
    if (aRotateX <= 3.1416)
      goto LABEL_11;
    v10 = (aRotateX / -6.2832) - 1;
  }
  else
  {
    v10 = (aRotateX / -6.2832) + 1;
  }
  v9 = (v10 * -6.2832) - aRotateX;
LABEL_11:
  v11 = v9 * 0.5;
  v13 = sdfCos(v9 * 0.5);
  v14 = (v11 * 0.15915) - (v11 * 0.15915);
  v15 = v14 + 1.0;
  if (v14 >= -0.5)
    v15 = (v11 * 0.15915) - (v11 * 0.15915);
  if (v14 > 0.5)
    v16 = v14 + -1.0;
  else
    v16 = v15;
  v17 = -0.5 - v16;
  if (v16 >= -0.25)
    v17 = v16;
  if (v16 > 0.25)
    v17 = 0.5 - v16;
  v18 = v17 * 4.0;
  v19 = v18 * v18;
  v20 = v18 * (v18 * v18);
  v62 = 1.5708;
  v21 = (v18 * 1.5708) + (v20 * -0.64596);
  v22 = v19 * (v19 * v20);
  v23 = (v19 * v20) * 0.07969;
  v24 = -aRotateY;
  v61 = -0.64596;
  v59 = v13;
  if (aRotateY >= -3.1416)
  {
    if (aRotateY <= 3.1416)
      goto LABEL_25;
    v25 = (aRotateY / -6.2832) - 1;
  }
  else
  {
    v25 = (aRotateY / -6.2832) + 1;
  }
  v24 = (v25 * -6.2832) - aRotateY;
LABEL_25:
  v26 = v24 * 0.5;
  v27 = v19 * v22;
  v28 = v21 + v23;
  v57 = v22 * -0.0046738;
  v30 = sdfCos(v24 * 0.5);
  v31 = (v26 * 0.15915) - (v26 * 0.15915);
  v32 = v31 + 1.0;
  if (v31 >= -0.5)
    v32 = (v26 * 0.15915) - (v26 * 0.15915);
  if (v31 > 0.5)
    v33 = v31 + -1.0;
  else
    v33 = v32;
  v34 = -0.5 - v33;
  v35 = 0.5 - v33;
  if (v33 >= -0.25)
    v34 = v33;
  if (v33 <= 0.25)
    v35 = v34;
  v36 = v35 * 4.0;
  v37 = v36 * (v36 * v36);
  v38 = (v36 * v36) * v37;
  v39 = (v36 * v36) * v38;
  v40 = (v36 * v36) * v39;
  v41 = ((v36 * v62) + (v37 * v61)) + (v38 * 0.07969);
  v42 = -v58;
  if (v58 >= -3.1416)
  {
    v43 = 0.5;
    v44 = v30;
    if (v58 <= 3.1416)
      goto LABEL_39;
    v45 = (v58 / -6.2832) - 1;
  }
  else
  {
    v43 = 0.5;
    v44 = v30;
    v45 = (v58 / -6.2832) + 1;
  }
  v42 = (v45 * -6.2832) - v58;
LABEL_39:
  v46 = v28 + v57;
  v47 = v42 * v43;
  v48 = v41 + (v39 * -0.0046738);
  v49 = v27 * 0.00015148;
  v50 = v40 * 0.00015148;
  v51 = sdfCos(v42 * v43);
  v52 = (v47 * 0.15915) - (v47 * 0.15915);
  if (v52 <= v43)
  {
    if (v52 >= -0.5)
      goto LABEL_44;
    v53 = 1.0;
  }
  else
  {
    v53 = -1.0;
  }
  v52 = v52 + v53;
LABEL_44:
  if (v52 <= 0.25)
  {
    if (v52 < -0.25)
      v52 = -0.5 - v52;
  }
  else
  {
    v52 = v43 - v52;
  }
  v54 = v52 * 4.0;
  *&v60.x = 0;
  *&v60.z = 0;
  v55 = v54 * v54;
  v56 = ((((v54 * v62) + ((v54 * (v54 * v54)) * v61)) + ((v55 * (v54 * (v54 * v54))) * 0.07969))
       + ((v55 * (v55 * (v54 * (v54 * v54)))) * -0.0046738))
      + ((v55 * (v55 * (v55 * (v54 * (v54 * v54))))) * 0.00015148);
  sub_854690(
    &v60.x,
    ((v46 + v49) * (v44 * v51)) + (v59 * ((v48 + v50) * v56)),
    (v59 * ((v48 + v50) * v51)) - ((v46 + v49) * (v44 * v56)),
    ((v46 + v49) * ((v48 + v50) * v51)) + (v59 * (v44 * v56)),
    (v59 * (v44 * v51)) - ((v46 + v49) * ((v48 + v50) * v56)));
  SDF_VU0__LOADVECTOR(v60);
}

// 0x17a8560
void FromRotation(f32 aAngle) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  v4 = aAngle * 0.5;
  v5 = (v4 * 0.15915) - (v4 * 0.15915);
  if (v5 <= 0.5)
  {
    if (v5 >= -0.5)
      goto LABEL_11;
    v6 = 1.0;
  }
  else
  {
    v6 = -1.0;
  }
  v5 = v5 + v6;
LABEL_11:
  if (v5 <= 0.25)
  {
    if (v5 < -0.25)
      v5 = -0.5 - v5;
  }
  else
  {
    v5 = 0.5 - v5;
  }
  v7 = v5 * 4.0;
  SDF_VU0__SCALEVECTOR(
    ((((v7 * 1.5708) + ((v7 * (v7 * v7)) * -0.64596)) + (((v7 * v7) * (v7 * (v7 * v7))) * 0.07969))
   + (((v7 * v7) * ((v7 * v7) * (v7 * (v7 * v7)))) * -0.0046738))
  + (((v7 * v7) * ((v7 * v7) * ((v7 * v7) * (v7 * (v7 * v7))))) * 0.00015148),
    0);
  vct_A.w = sdfCos(v4);
}

// 0x17a86e0
void FromRotation_B(f32 aAngle) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;

  v4 = aAngle * 0.5;
  v5 = (v4 * 0.15915) - (v4 * 0.15915);
  if (v5 <= 0.5)
  {
    if (v5 >= -0.5)
      goto LABEL_11;
    v6 = 1.0;
  }
  else
  {
    v6 = -1.0;
  }
  v5 = v5 + v6;
LABEL_11:
  if (v5 <= 0.25)
  {
    if (v5 < -0.25)
      v5 = -0.5 - v5;
  }
  else
  {
    v5 = 0.5 - v5;
  }
  v7 = v5 * 4.0;
  SDF_VU0__SCALEVECTOR_B(
    ((((v7 * 1.5708) + ((v7 * (v7 * v7)) * -0.64596)) + (((v7 * v7) * (v7 * (v7 * v7))) * 0.07969))
   + (((v7 * v7) * ((v7 * v7) * (v7 * (v7 * v7)))) * -0.0046738))
  + (((v7 * v7) * ((v7 * v7) * ((v7 * v7) * (v7 * (v7 * v7))))) * 0.00015148),
    0);
  vct_B.w = sdfCos(v4);
}

// 0x17a8550
f32 InnerProduct(void) {
  return SDF_QUAT_INNERPRODUCT();
}

// 0x17a8240
void Inverse(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  f32 v14;
  s64 v15;
  s64 v16;
  UnityEngine_Quaternion_o v17;
  UnityEngine_Quaternion_o v18;
  UnityEngine_Vector4_o v19;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  v15 = 0;
  v16 = 0;
  sub_1A1BDD0(&v15, v4, v5, v6, v7);
  v9 = v15;
  v10 = v16;
  *&v18.x = v9;
  *&v18.z = v10;
  v17 = Inverse(v18, 0);
  v15 = 0;
  v16 = 0;
  sub_854690(&v15, v17.x, v17.y, v17.z, v17.w);
  v11 = v15;
  v12 = v16;
  v14 = sub_8553D0(&vct_A.x, 0);
  *&v19.x = v11;
  *&v19.z = v12;
  vct_A = op_Division(v19, v14);
}

// 0x17a8420
void Length(void) {
  ;
}

// 0x17a95d0
void Lerp(f32 aRatio) {
  f32 v4;
  sdf_vu0r_c *v5;
  f32 *p_x;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 w;
  f32 *v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v22;
  f32 v24;
  f32 v25;
  f32 v26;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o v30;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o v32;

  v4 = SDF_QUAT_INNERPRODUCT();
  if (v4 >= 0.0)
  {
    *&vct_C.x = *&vct_B.x;
    w = vct_B.w;
    vct_C.z = vct_B.z;
    vct_C.w = w;
    v11 = 1.0;
    if ((v5->_2.bitflags2 & 2) != 0)
      goto LABEL_11;
  }
  else
  {
    p_x = &vf00.x;
    v7 = p_x[8];
    v8 = p_x[9];
    v10 = p_x[10];
    v9 = p_x[11];
    v30.x = v7;
    v30.y = v8;
    v30.z = v10;
    v30.w = v9;
    v27 = op_UnaryNegation(v30);
    vct_C = v27;
    v11 = 1.0;
    if ((v5->_2.bitflags2 & 2) != 0)
    {
LABEL_11:
    }
  }
  v14 = &vf00.x;
  v15 = v11 - aRatio;
  v16 = v14[4];
  v17 = v14[5];
  v19 = v14[6];
  v18 = v14[7];
  v31.x = v16;
  v31.y = v17;
  v31.z = v19;
  v31.w = v18;
  v28 = op_Multiply(v31, v15, 0);
  v32 = op_Multiply(vct_C, aRatio, 0);
  v29 = op_Addition(v28, v32);
  vct_A = v29;
  v22 = sub_855290(&vct_A.x, 0);
  vct_A.x = v22;
  vct_A.y = v24;
  vct_A.z = v25;
  vct_A.w = v26;
}

// 0x17a8cf0
void LookAt(f32 aFrontX, f32 aFrontZ) {
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o p;
  f32 v33;
  f32 v34;

  *&p.x = 0;
  *&p.z = 0;
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 0);
  v6 = v5;
  sub_854710(&p, 1u);
  if (aFrontZ >= 0.0)
    v8 = v7;
  else
    v8 = -v7;
  sub_854710(&p, 2u);
  v11 = v10;
  v12 = (v6 * v6) + (v11 * v11);
  if (v12 < 0.000001)
  {
    *&v31.x = 0;
    *&v31.z = 0;
    if (v8 >= 0.0)
      v13 = -0.70711;
    else
      v13 = 0.70711;
    sub_854690(&v31.x, 0.70711, 0.0, 0.0, v13);
    SDF_VU0__LOADVECTOR(v31);
    return;
  }
  v34 = aFrontZ;
  v14 = v8 * v8;
  v33 = aFrontX;
  v15 = v14 + v12;
  else
  {
    v16 = sqrtf(v15);
  }
  if ((byte_3F5A732 & 1) != 0)
  {
    {
LABEL_25:
      v18 = sqrtf(v12);
      goto LABEL_26;
    }
  }
  else
  {
      goto LABEL_25;
  }
    goto LABEL_25;
  v18 = sqrtf(v12);
LABEL_26:
  v19 = v16 + v18;
  v20 = v14 + (v19 * v19);
  else
  {
    v21 = sqrtf(v20);
    v22 = v34;
  }
  *&v31.x = 0;
  *&v31.z = 0;
  sub_854690(&v31.x, v8 * (1.0 / v21), 0.0, 0.0, v19 * (1.0 / v21));
  SDF_VU0__LOADVECTOR(v31);
  v24 = v33 - (v6 * (1.0 / v18));
  v25 = (v11 * (1.0 / v18)) + v22;
  v26 = (v24 * v24) + (v25 * v25);
  if (v26 >= 0.000001)
  {
    v29 = 1.0 / sqrtf(v26);
    v27 = v24 * v29;
    v28 = v25 * v29;
    *&v31.x = 0;
    *&v31.z = 0;
  }
  else
  {
    *&v31.x = 0;
    *&v31.z = 0;
    v27 = 1.0;
    v28 = 0.0;
  }
  sub_854690(&v31.x, 0.0, v27, 0.0, v28);
  SDF_VU0__LOADVECTOR_B(v31);
  Mult();
}

// 0x17a80f0
void Mult(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  s64 v13;
  s64 v14;
  s64 v16;
  s64 v17;
  f32 v19;
  f32 v20;
  s64 v21;
  s64 v22;
  UnityEngine_Quaternion_o v23;
  UnityEngine_Quaternion_o v24;
  UnityEngine_Quaternion_o v25;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  v21 = 0;
  v22 = 0;
  sub_1A1BDD0(&v21, v4, v5, v6, v7);
  x = vct_B.x;
  y = vct_B.y;
  z = vct_B.z;
  w = vct_B.w;
  v13 = v21;
  v14 = v22;
  v21 = 0;
  v22 = 0;
  sub_1A1BDD0(&v21, x, y, z, w);
  v16 = v21;
  v17 = v22;
  *&v24.x = v13;
  *&v24.z = v14;
  *&v25.x = v16;
  *&v25.z = v17;
  v23 = op_Multiply(v24, v25, 0);
  v21 = 0;
  v22 = 0;
  sub_854690(&v21, v23.x, v23.y, v23.z, v23.w);
  v20 = *&v22;
  v19 = *(&v22 + 1);
  *&vct_A.x = v21;
  vct_A.z = v20;
  vct_A.w = v19;
}

// 0x17a83a0
void Normalize(void) {
  f32 v3;
  f32 v5;
  f32 v6;
  f32 v7;

  v3 = sub_855290(&vct_A.x, 0);
  vct_A.x = v3;
  vct_A.y = v5;
  vct_A.z = v6;
  vct_A.w = v7;
}

// 0x17a80c0
sdfVector4_t Q2V(sdfQuaternion_t src) {
  s64 v6;
  s64 v7;
  UnityEngine_Vector4_o result;

  v6 = 0;
  v7 = 0;
  sub_854690(&v6, src.x, src.y, src.z, src.w);
  result.y = *(&v6 + 1);
  LODWORD(result.x) = v6;
  result.w = *(&v7 + 1);
  LODWORD(result.z) = v7;
  return result;
}

// 0x17a8430
f32 SDF_QUAT_INNERPRODUCT(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  s64 v13;
  s64 v14;
  s64 v16;
  s64 v17;
  s64 v19;
  s64 v20;
  UnityEngine_Quaternion_o v21;
  UnityEngine_Quaternion_o v22;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  v19 = 0;
  v20 = 0;
  sub_1A1BDD0(&v19, v4, v5, v6, v7);
  x = vct_B.x;
  y = vct_B.y;
  z = vct_B.z;
  w = vct_B.w;
  v13 = v19;
  v14 = v20;
  v19 = 0;
  v20 = 0;
  sub_1A1BDD0(&v19, x, y, z, w);
  v16 = v19;
  v17 = v20;
  *&v21.x = v13;
  *&v21.z = v14;
  *&v22.x = v16;
  *&v22.z = v17;
  return Dot(v21, v22);
}

// 0x17a90e0
void Slerp(f32 aRatio) {
  f32 v5;
  f32 *p_x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 w;
  f32 v15;
  f32 v16;
  f32 v18;
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
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 *v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v50;
  f32 v52;
  f32 v53;
  f32 v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;
  UnityEngine_Vector4_o v59;
  UnityEngine_Vector4_o v60;

  v5 = SDF_QUAT_INNERPRODUCT();
  if (v5 >= 0.0)
  {
    *&vct_C.x = *&vct_B.x;
    w = vct_B.w;
    vct_C.z = vct_B.z;
    vct_C.w = w;
  }
  else
  {
    p_x = &vf00.x;
    v8 = p_x[8];
    v9 = p_x[9];
    v11 = p_x[10];
    v10 = p_x[11];
    v58.x = v8;
    v58.y = v9;
    v58.z = v11;
    v58.w = v10;
    v5 = -v5;
    v55 = op_UnaryNegation(v58);
    vct_C = v55;
  }
  v15 = 1.0 - aRatio;
  if (v5 < 0.999)
  {
    if (v5 >= 0.0)
    {
      v16 = 1.0;
    }
    else
    {
      v5 = -v5;
      v16 = -1.0;
    }
    if (v5 >= 1.0)
    {
      v18 = 0.0;
    }
    else
    {
      v18 = (1.0 - sdfTableInterpolation(v5, sdfSinTable, 128)) * 1.5708;
    }
    v19 = ((v16 * v18) * 0.15915) - ((v16 * v18) * 0.15915);
    v20 = v19 + 1.0;
    v21 = v19 + -1.0;
    if (v19 >= -0.5)
      v20 = ((v16 * v18) * 0.15915) - ((v16 * v18) * 0.15915);
    if (v19 <= 0.5)
      v21 = v20;
    v22 = -0.5 - v21;
    if (v21 >= -0.25)
      v22 = v21;
    if (v21 > 0.25)
      v22 = 0.5 - v21;
    v23 = v22 * 4.0;
    v24 = ((((v23 * 1.5708) + ((v23 * (v23 * v23)) * -0.64596)) + (((v23 * v23) * (v23 * (v23 * v23))) * 0.07969))
         + (((v23 * v23) * ((v23 * v23) * (v23 * (v23 * v23)))) * -0.0046738))
        + (((v23 * v23) * ((v23 * v23) * ((v23 * v23) * (v23 * (v23 * v23))))) * 0.00015148);
    v25 = ((v15 * (v16 * v18)) * 0.15915) - ((v15 * (v16 * v18)) * 0.15915);
    v26 = v25 + 1.0;
    if (v25 >= -0.5)
      v26 = ((v15 * (v16 * v18)) * 0.15915) - ((v15 * (v16 * v18)) * 0.15915);
    if (v25 > 0.5)
      v27 = v25 + -1.0;
    else
      v27 = v26;
    v28 = -0.5 - v27;
    if (v27 >= -0.25)
      v28 = v27;
    if (v27 > 0.25)
      v29 = 0.5 - v27;
    else
      v29 = v28;
    v30 = v29 * 4.0;
    v31 = v30 * v30;
    v32 = v30 * (v30 * v30);
    v33 = (v30 * v30) * v32;
    v34 = (v30 * v30) * v33;
    v35 = (v30 * 1.5708) + (v32 * -0.64596);
    v36 = v33 * 0.07969;
    v37 = (v31 * (v31 * v33)) * 0.00015148;
    v38 = v35 + v36;
    v39 = (((v16 * v18) * aRatio) * 0.15915) - (((v16 * v18) * aRatio) * 0.15915);
    if (v39 <= 0.5)
    {
      if (v39 < -0.5)
        v39 = v39 + 1.0;
    }
    else
    {
      v39 = v39 + -1.0;
    }
    v40 = -0.5 - v39;
    v41 = 0.5 - v39;
    if (v39 >= -0.25)
      v40 = v39;
    if (v39 <= 0.25)
      v41 = v40;
    v42 = v41 * 4.0;
    v15 = ((v38 + (v34 * -0.0046738)) + v37) / v24;
    aRatio = (((((v42 * 1.5708) + ((v42 * (v42 * v42)) * -0.64596)) + (((v42 * v42) * (v42 * (v42 * v42))) * 0.07969))
             + (((v42 * v42) * ((v42 * v42) * (v42 * (v42 * v42)))) * -0.0046738))
            + (((v42 * v42) * ((v42 * v42) * ((v42 * v42) * (v42 * (v42 * v42))))) * 0.00015148))
           / v24;
  }
  v43 = &vf00.x;
  v44 = v43[4];
  v45 = v43[5];
  v47 = v43[6];
  v46 = v43[7];
  v59.x = v44;
  v59.y = v45;
  v59.z = v47;
  v59.w = v46;
  v56 = op_Multiply(v59, v15, 0);
  v60 = op_Multiply(vct_C, aRatio, 0);
  v57 = op_Addition(v56, v60);
  vct_A = v57;
  v50 = sub_855290(&vct_A.x, 0);
  vct_A.x = v50;
  vct_A.y = v52;
  vct_A.z = v53;
  vct_A.w = v54;
}

// 0x179c260
void ToMatrix(void) {
  f32 *p_x;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v15;
  s64 v16;
  s64 v17;
  UnityEngine_Matrix4x4_o v18;
  UnityEngine_Quaternion_o v19;

  p_x = &vf00.x;
  v4 = p_x[4];
  v5 = p_x[5];
  v6 = p_x[6];
  v7 = p_x[7];
  *&v18.m00 = 0;
  *&v18.m20 = 0;
  sub_1A1BDD0(&v18.m00, v4, v5, v6, v7);
  v9 = *&v18.m00;
  v10 = *&v18.m20;
  *&v19.x = v9;
  *&v19.z = v10;
  Rotate(&v18, v19, 0);
  v12 = *&v18.m00;
  v11 = *&v18.m20;
  v13 = *&v18.m21;
  *&mtx_A.m01 = *&v18.m01;
  *&mtx_A.m21 = v13;
  *&mtx_A.m00 = v12;
  *&mtx_A.m20 = v11;
  v16 = *&v18.m02;
  v15 = *&v18.m22;
  v17 = *&v18.m23;
  *&mtx_A.m03 = *&v18.m03;
  *&mtx_A.m23 = v17;
  *&mtx_A.m02 = v16;
  *&mtx_A.m22 = v15;
}

// 0x17a8090
sdfQuaternion_t V2Q(sdfVector4_t src) {
  s64 v6;
  s64 v7;
  UnityEngine_Quaternion_o result;

  v6 = 0;
  v7 = 0;
  sub_1A1BDD0(&v6, src.x, src.y, src.z, src.w);
  result.y = *(&v6 + 1);
  LODWORD(result.x) = v6;
  result.w = *(&v7 + 1);
  LODWORD(result.z) = v7;
  return result;
}
