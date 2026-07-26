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
    ToMatrix();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__GETVECTOR_Z();
    SDF_VU0__GETVECTOR_X();
    sdfAtan2(0, 0);
    return 0;
}

// 0x179d8c0
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ) {
    sdfCos(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
}

// 0x17a8860
void FromEulerXYZ(f32 aRotateX, f32 aRotateY, f32 aRotateZ) {
    sdfCos(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
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
    v6 = 1.0;
  }
  else
  {
    v6 = -1.0;
  }
  v5 = v5 + v6;
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
    v6 = 1.0;
  }
  else
  {
    v6 = -1.0;
  }
  v5 = v5 + v6;
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
}

// 0x17a8420
void Length(void) {
  ;
}

// 0x17a95d0
void Lerp(f32 aRatio) {
    SDF_QUAT_INNERPRODUCT();
}

// 0x17a8cf0
void LookAt(f32 aFrontX, f32 aFrontZ) {
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
}

// 0x17a80f0
void Mult(void) {
}

// 0x17a83a0
void Normalize(void) {
}

// 0x17a80c0
sdfVector4_t Q2V(sdfQuaternion_t src) {
    return (sdfVector4_t){0};
}

// 0x17a8430
f32 SDF_QUAT_INNERPRODUCT(void) {
    return 0;
}

// 0x17a90e0
void Slerp(f32 aRatio) {
    SDF_QUAT_INNERPRODUCT();
    sdfTableInterpolation(0, 0, 0);
}

// 0x179c260
void ToMatrix(void) {
}

// 0x17a8090
sdfQuaternion_t V2Q(sdfVector4_t src) {
    return (sdfQuaternion_t){0};
}
