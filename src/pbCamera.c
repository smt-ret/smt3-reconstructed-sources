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
}

// 0x1642060
void pbRotateXCamera(f32 angle) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
}

// 0x16422a0
void pbRotateYCamera(f32 angle) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
}

// 0x1642720
void pbRotateYCamera2(f32 angle, f32 radius, f32 degree) {
    sdfVu0SetRotateMatrixY(0);
    sdfVu0SetRotateMatrixX_B(0);
    sdfVu0MultMatrixNoArg();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
}

// 0x16424e0
void pbRotateZCamera(f32 angle) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfCos(0);
    sdfSin(0);
}
