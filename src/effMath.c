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
    return 0;
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
    return 0;
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
    return 0;
}

// 0x16b0200
u32 effColorMultiply(u32 abgr0, u32 abgr1) {
  return (((BYTE2(abgr1) * (abgr0 & 0xFF0000)) | (abgr1 * abgr0)) >> 7) & 0xFF00FF
       | (2 * ((BYTE1(abgr1) * BYTE1(abgr0)) | (HIBYTE(abgr1) * ((abgr0 >> 8) & 0xFF0000)))) & 0xFF00FF00;
}

// 0x16bf140
sdfColor_t effGetBlendColor(u32 icol) {
    return (sdfColor_t){0};
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
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__INNERPRODUCT();
    SDF_VU0__GETLENGTH();
    return 0;
}

// 0x16bde20
s32 effScreenArea(f32 area) {
    SDF_VU0__STOREVECTOR(0);
    effScreenOffset();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__ADDVECTOR();
    sdfSqrt(0);
    return 0;
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
