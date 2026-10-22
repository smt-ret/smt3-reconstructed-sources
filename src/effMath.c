#include "types.h"

typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct effBezier4PPart_t effBezier4PPart_t;
typedef struct effBezier4P_t effBezier4P_t;
typedef struct effBezier7PPart_t effBezier7PPart_t;
typedef struct effBezier7P_t effBezier7P_t;

void *GetMainCamera(dds3DefaultMain *this);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
f32 SDF_VU0__INNERPRODUCT(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void effBezier4PPart_t__Clear(effBezier4PPart_t *this);
void effScreenOffset(void);
f32 sdfSqrt(f32 aValue);

// 0x16ab130
effBezier4P_t *dds3Bezier4PCreate(u32 number) {
  u32 *v3;
  effBezier4P_t_o *v4;
  u64 v5;
  u32 *v6;
  u64 *v9;
  u32 *pPart;
  s64 v15;
  u32 *v17;

  v3 = NewSpecific(effBezier4PPart_t, number);
  v4 = Allocate(effBezier4P_t);
  effBezier4P_t___ctor(v4);
  v4->pPart = NewSpecific(effBezier4PPart_t, number);
  if (number)
  {
    v5 = 0;
    v6 = v3 + 8;
    do
    {
      v9 = Allocate(effBezier4PPart_t);
      effBezier4PPart_t___ctor(v9);
      *&v6[2 * v5] = v9;
      effBezier4PPart_t__Clear(v9);
      *(*&v6[2 * v5] + 24LL) = 0;
      *(*&v6[2 * v5] + 28LL) = 1028443341;
      pPart = v4->pPart;
      v15 = *&v6[2 * v5];
      v17 = &pPart[2 * v5++];
      *(v17 + 4) = v15;
    }
    while (number != v5);
  }
  v4->number = number;
  v4->hMem = 0;
  return v4;
}

// 0x16ab520
void dds3Bezier4PDelete(effBezier4P_t *pEffBezier4P) {
  ;
}

// 0x16abce0
effBezier4PPart_t *dds3Bezier4PGetPart(effBezier4P_t **pEffBezier4P, u32 index) {
  struct effBezier4PPart_t_array *pPart;

  pPart = (*pEffBezier4P)->pPart;
  return pPart->m_Items[index];
}

// 0x16be7d0
void dds3Bezier4PPartInit(effBezier4P_t **pEffBezier4P, u32 index) {
  struct effBezier4PPart_t_array *pPart;

  pPart = (*pEffBezier4P)->pPart;
  *&pPart->m_Items[index]->weight = 0x3D4CCCCD00000000LL;
}

// 0x16be1b0
s32 dds3Bezier4PPartRun(effBezier4PPart_t **pPart, sdfVector4_t *pOut) {
  u64 *v5;
  f32 weight;
  f32 v7;
  struct UnityEngine_Vector3_array *point;
  u32 v9;
  f32 z;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v21;
  f32 v22;
  bool v23;

  v5 = NewSpecific(f32, 4u);
  weight = (*pPart)->weight;
  v7 = 1.0 - weight;
  point = (*pPart)->point;
  v9 = *(v5 + 6);
  *(v5 + 8) = v7 * (v7 * v7);
  *(v5 + 9) = (weight * (v7 * v7)) * 3.0;
  *(v5 + 10) = ((weight * weight) * v7) * 3.0;
  *(v5 + 11) = weight * (weight * weight);
  pOut->x = (((point->m_Items[0].x * *(v5 + 8)) + (point->m_Items[1].x * *(v5 + 9)))
                  + (point->m_Items[2].x * *(v5 + 10)))
                 + (point->m_Items[3].x * *(v5 + 11));
  pOut->y = (((point->m_Items[0].y * *(v5 + 8)) + (point->m_Items[1].y * *(v5 + 9)))
                  + (point->m_Items[2].y * *(v5 + 10)))
                 + (point->m_Items[3].y * *(v5 + 11));
  z = point->m_Items[0].z;
  v15 = *(v5 + 8);
  v16 = point->m_Items[1].z;
  v17 = *(v5 + 9);
  v18 = point->m_Items[2].z;
  v19 = *(v5 + 10);
  v21 = point->m_Items[3].z * *(v5 + 11);
  pOut->w = 1.0;
  pOut->z = (((z * v15) + (v16 * v17)) + (v18 * v19)) + v21;
  v22 = weight + (*pPart)->step;
  v23 = v22 <= 1.0;
  if (v22 > 1.0)
    v22 = 1.0;
  (*pPart)->weight = v22;
  return v23;
}

// 0x16acb90
s32 dds3Bezier4PRun(effBezier4P_t **pEffBezier4P, u32 index, sdfVector4_t *pOut) {
  u64 *v7;
  struct effBezier4PPart_t_array *pPart;
  u64 *v9;
  effBezier4PPart_t_o *v11;
  u32 v12;
  f32 weight;
  f32 v14;
  struct UnityEngine_Vector3_array *point;
  f32 v38;
  bool v39;

  v7 = NewSpecific(f32, 4u);
  pPart = (*pEffBezier4P)->pPart;
  v9 = v7;
  v11 = pPart->m_Items[index];
  v12 = *(v7 + 6);
  weight = v11->weight;
  v14 = 1.0 - weight;
  point = v11->point;
  *(v7 + 8) = v14 * (v14 * v14);
  *(v7 + 9) = (weight * (v14 * v14)) * 3.0;
  *(v7 + 10) = ((weight * weight) * v14) * 3.0;
  *(v7 + 11) = weight * (weight * weight);
  sub_8527D0(&point->m_Items[0].x, 0);
  sub_8527D0(&point->m_Items[1].x, 0);
  sub_8527D0(&point->m_Items[2].x, 0);
  sub_8527D0(&point->m_Items[3].x, 0);
  sub_854930(pOut, 0);
  sub_8527D0(&point->m_Items[0].x, 1);
  sub_8527D0(&point->m_Items[1].x, 1);
  sub_8527D0(&point->m_Items[2].x, 1);
  sub_8527D0(&point->m_Items[3].x, 1);
  sub_854930(pOut, 1u);
  sub_8527D0(&point->m_Items[0].x, 2);
  sub_8527D0(&point->m_Items[1].x, 2);
  sub_8527D0(&point->m_Items[2].x, 2);
  sub_8527D0(&point->m_Items[3].x, 2);
  sub_854930(pOut, 2u);
  v38 = weight + v11->step;
  v39 = v38 <= 1.0;
  if (v38 > 1.0)
    v38 = 1.0;
  v11->weight = v38;
  return v39;
}

// 0x16be830
effBezier7P_t *dds3Bezier7PCreate(u32 number) {
  u32 *v3;
  effBezier7P_t_o *v4;
  u64 v5;
  u32 *v6;
  effBezier7PPart_t_o *v10;
  u32 *pPart;
  s64 v15;
  u32 *v17;

  v3 = NewSpecific(effBezier7PPart_t, number);
  v4 = Allocate(effBezier7P_t);
  effBezier7P_t___ctor(v4);
  if (number)
  {
    v5 = 0;
    v6 = v3 + 8;
    do
    {
      v10 = Allocate(effBezier7PPart_t);
      effBezier7PPart_t___ctor(v10);
      *&v6[2 * v5] = v10;
      v10->segment = 0;
      *(*&v6[2 * v5] + 28LL) = 0;
      *(*&v6[2 * v5] + 32LL) = 1028443341;
      pPart = v4->pPart;
      v15 = *&v6[2 * v5];
      v17 = &pPart[2 * v5++];
      *(v17 + 4) = v15;
    }
    while (number != v5);
  }
  v4->number = number;
  v4->hMem = 0;
  return v4;
}

// 0x16bea80
void dds3Bezier7PDelete(effBezier7P_t **pEffBezier7P) {
  ;
}

// 0x16beaa0
s32 dds3Bezier7PPartRun(effBezier7PPart_t **pPart, sdfVector4_t *pOut) {
  u64 *v4;
  f32 weight;
  f32 v6;
  s64 segment;
  struct UnityEngine_Vector3_array *point;
  u32 v9;
  u64 *v10;
  f32 *p_x;
  u32 v16;
  f32 *v18;
  u32 v20;
  f32 *v22;
  u32 v24;
  f32 *v26;
  f32 v42;
  effBezier7PPart_t_o *v43;
  f32 v44;
  s32 result;
  effBezier7PPart_t_o **v50;

  v4 = NewSpecific(f32, 4u);
  weight = (*pPart)->weight;
  v6 = 1.0 - weight;
  segment = (*pPart)->segment;
  point = (*pPart)->point;
  v9 = *(v4 + 6);
  v10 = v4;
  *(v4 + 8) = v6 * (v6 * v6);
  *(v4 + 9) = (weight * (v6 * v6)) * 3.0;
  *(v4 + 10) = ((weight * weight) * v6) * 3.0;
  *(v4 + 11) = weight * (weight * weight);
  p_x = &point->m_Items[segment].x;
  sub_8527D0(p_x, 0);
  v16 = segment + 1;
  v18 = &point->m_Items[segment + 1].x;
  v50 = pPart;
  sub_8527D0(v18, 0);
  v20 = segment + 2;
  v22 = &point->m_Items[segment + 2].x;
  sub_8527D0(v22, 0);
  v24 = segment + 3;
  v26 = &point->m_Items[v24].x;
  sub_8527D0(v26, 0);
  sub_854930(pOut, 0);
  sub_8527D0(p_x, 1);
  sub_8527D0(v18, 1);
  sub_8527D0(v22, 1);
  sub_8527D0(v26, 1);
  sub_854930(pOut, 1u);
  sub_8527D0(p_x, 2);
  sub_8527D0(v18, 2);
  sub_8527D0(v22, 2);
  sub_8527D0(v26, 2);
  sub_854930(pOut, 2u);
  v42 = 1.0;
  sub_854930(pOut, 3u);
  v43 = *v50;
  v44 = weight + (*v50)->step;
  if (v44 > 1.0)
  {
    if (segment > 2)
    {
      result = 0;
      goto LABEL_64;
    }
    v44 = v44 + -1.0;
    LODWORD(segment) = segment + 3;
  }
  v43->segment = segment;
  v43 = *v50;
  v42 = v44;
  result = 1;
LABEL_64:
  v43->weight = v42;
  return result;
}

// 0x16bf130
void dds3Bezier7PPartRun2(effBezier7PPart_t *pPart, sdfVector4_t *pOut) {
  ;
}

// 0x16bea90
s32 dds3Bezier7PRun(effBezier7P_t *pEffBezier7P, u32 index, sdfVector4_t *pOut) {
  return 1;
}

// 0x16aa750
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate) {
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  s32 x;
  s16 y;
  s32 v18;
  s32 z;
  s32 v20;
  s32 w;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o v25;

  if (rate < 1.0)
  {
    if (rate <= 0.0)
    {
      return abgr0;
    }
    else
    {
      v7 = abgr0;
      v8 = (abgr0 & 0xFF00);
      v9 = (abgr0 & 0xFF000000);
      v10 = (abgr0 & 0xFF0000);
      *&v24.x = 0;
      *&v24.z = 0;
      sub_854690(&v24.x, v7, v8, v10, v9);
      v11 = abgr1;
      v12 = (abgr1 & 0xFF00);
      v13 = (abgr1 & 0xFF000000);
      v14 = (abgr1 & 0xFF0000);
      *&v23.x = 0;
      *&v23.z = 0;
      sub_854690(&v23.x, v11, v12, v14, v13);
      v25 = Lerp(v24, v23, rate, 0);
      x = v25.x;
      if (v25.x >= 0.0)
        LOBYTE(x) = v25.x;
      if (v25.y >= 0.0)
        y = v25.y;
      else
        y = v25.y;
      v18 = y & 0xFF00 | x;
      z = v25.z;
      if (v25.z < 0.0)
        z = v25.z;
      v20 = v18 | z & 0xFF0000;
      w = v25.w;
      if (v25.w >= 0.0)
        w = v25.w;
      return v20 | w & 0xFF000000;
    }
  }
  return abgr1;
}

// 0x16b0200
u32 effColorMultiply(u32 abgr0, u32 abgr1) {
  return (((BYTE2(abgr1) * (abgr0 & 0xFF0000)) | (abgr1 * abgr0)) >> 7) & 0xFF00FF
       | (2 * ((BYTE1(abgr1) * BYTE1(abgr0)) | (HIBYTE(abgr1) * ((abgr0 >> 8) & 0xFF0000)))) & 0xFF00FF00;
}

// 0x16bf140
sdfColor_t effGetBlendColor(u32 icol) {
  f32 v2;
  f32 v3;
  f32 v4;
  f32 v5;
  s64 v10;
  s64 v11;
  UnityEngine_Color_o result;

  v10 = 0;
  v11 = 0;
  v2 = HIBYTE(icol);
  v3 = icol;
  v4 = BYTE1(icol);
  v5 = BYTE2(icol);
  sub_19EC630(&v10, v3 * 0.0078125, v4 * 0.0078125, v5 * 0.0078125, v2 * 0.0078125);
  result.g = *(&v10 + 1);
  LODWORD(result.r) = v10;
  result.a = *(&v11 + 1);
  LODWORD(result.b) = v11;
  return result;
}

// 0x16bf1c0
sdfColor_t effGetVertexColor(u32 icol, sdfColor_t blend_col) {
  f32 v3;
  f32 v5;
  f32 v7;
  f32 v9;
  UnityEngine_Color_o result;

  v3 = icol;
  result.r = blend_col.r * (v3 * 0.0039216);
  v5 = BYTE1(icol);
  result.g = blend_col.g * (v5 * 0.0039216);
  v7 = BYTE2(icol);
  result.b = blend_col.b * (v7 * 0.0039216);
  v9 = HIBYTE(icol);
  result.a = blend_col.a * (v9 * 0.0078125);
  return result;
}

// 0x16bf230
sdfColor_t effGetVertexColorT(u32 icol, sdfColor_t blend_col) {
  f32 v3;
  f32 v5;
  f32 v7;
  f32 v9;
  UnityEngine_Color_o result;

  v3 = icol;
  result.r = blend_col.r * (v3 * 0.0078125);
  v5 = BYTE1(icol);
  result.g = blend_col.g * (v5 * 0.0078125);
  v7 = BYTE2(icol);
  result.b = blend_col.b * (v7 * 0.0078125);
  v9 = HIBYTE(icol);
  result.a = blend_col.a * (v9 * 0.0078125);
  return result;
}

// 0x16be040
f32 effLinePointLength(sdfVector4_t pDir, sdfVector4_t pLinePos, sdfVector4_t pPos) {
  f32 z;
  f32 w;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o v15;
  s64 v16;
  s64 v17;
  UnityEngine_Vector4_o v18;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;

  z = pDir.z;
  w = pDir.w;
  y = pDir.y;
  x = pDir.x;
  v15 = pDir;
  *&v18.x = v16;
  *&v18.z = v17;
  v8 = pLinePos.w;
  v9 = pLinePos.z;
  v10 = pLinePos.y;
  v11 = pLinePos.x;
  *&v14.x = 0;
  *&v14.z = 0;
  *&v13.x = 0;
  *&v13.z = 0;
  SDF_VU0__LOADVECTOR(v18);
  v19.x = v11;
  v19.y = v10;
  v19.z = v9;
  v19.w = v8;
  SDF_VU0__LOADVECTOR_B(v19);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&v13);
  v20.x = x;
  v20.y = y;
  v20.z = z;
  v20.w = w;
  SDF_VU0__LOADVECTOR_B(v20);
  SDF_VU0__INNERPRODUCT();
  sub_854710(&v15, 0);
  sub_854930(&v14, 0);
  sub_854710(&v15, 1u);
  sub_854930(&v14, 1u);
  sub_854710(&v15, 2u);
  sub_854930(&v14, 2u);
  SDF_VU0__LOADVECTOR(v13);
  SDF_VU0__LOADVECTOR_B(v14);
  SDF_VU0__SUBVECTOR();
  return SDF_VU0__GETLENGTH();
}

// 0x16bde20
s32 effScreenArea(f32 area) {
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v15;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;

  *&v20.x = 0;
  *&v20.z = 0;
  *&v19.x = 0;
  *&v19.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v17.x = 0;
  *&v17.z = 0;
  SDF_VU0__STOREVECTOR(&v17);
  effScreenOffset();
  SDF_VU0__STOREVECTOR(&p);
  sub_854930(&v20, 2u);
  sub_854930(&v20, 1u);
  sub_854930(&v20, 0);
  SDF_VU0__LOADVECTOR(v17);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(dds3CameraUpVector);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(v20);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__ADDVECTOR();
  effScreenOffset();
  SDF_VU0__STOREVECTOR(&v19);
  sub_854710(&v19, 0);
  v7 = v6;
  sub_854710(&p, 0);
  v9 = v8;
  sub_854710(&v19, 1u);
  v11 = v10;
  sub_854710(&p, 1u);
  v13 = v11 - v12;
  SDF_VU0__LOADVECTOR(p);
  v15 = v7 - v9;
  return sdfSqrt((v15 * v15) + (v13 * v13), 0);
}

// 0x16bdc50
void effScreenOffset(void) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  s64 v6;
  UnityEngine_Camera_o *v7;
  f32 w;
  f32 z;
  f32 *p_SDF_CC_NDNM;
  f32 v13;
  f32 v14;
  f32 v15;
  s32 width;
  s32 v17;
  f32 v18;
  s32 height;
  s32 v20;
  UnityEngine_Vector4_o v21;
  UnityEngine_Vector3_o v22;
  UnityEngine_Vector3_o v23;
  UnityEngine_Vector3_o v24;
  UnityEngine_Vector3_o v25;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;

  *&v21.x = 0;
  *&v21.z = 0;
  SDF_VU0__STOREVECTOR(&v21);
  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  v6 = *&v21.x;
  v7 = Component_object;
  z = v21.z;
  w = v21.w;
  *&v26.x = v6;
  v26.z = z;
  v26.w = w;
  v22 = op_Implicit_8738992(v26);
  p_SDF_CC_NDNM = &SDF_CC_NDNM;
  v13 = p_SDF_CC_NDNM[41];
  v14 = p_SDF_CC_NDNM[42];
  v15 = p_SDF_CC_NDNM[43];
  v25.x = v13;
  v25.y = v14;
  v25.z = v15;
  v24 = Scale(v22, v25);
  v23 = WorldToScreenPoint_27174640(v7, v24);
  width = get_width(0);
  if (width >= 0)
    v17 = width;
  else
    v17 = width + 1;
  v18 = v23.x - (v17 >> 1);
  height = get_height(0);
  if (height >= 0)
    v20 = height;
  else
    v20 = height + 1;
  v27.z = 0.0;
  v27.w = 0.0;
  v27.y = v23.y - (v20 >> 1);
  v27.x = v18;
  SDF_VU0__LOADVECTOR(v27);
}
