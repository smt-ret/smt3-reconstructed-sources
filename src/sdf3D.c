#include "types.h"

typedef struct sdf3DFogPacket_t sdf3DFogPacket_t;
typedef struct sdf3DFogParam_t sdf3DFogParam_t;
typedef struct sdf3DInitPacket_t sdf3DInitPacket_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct sdf3DScreenParam_t sdf3DScreenParam_t;
typedef struct sdf3DViewportPacket_t sdf3DViewportPacket_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrRefPacketHeader_t sdfGrRefPacketHeader_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static sdfTexHandle_t *sdfStdSpecularTex;
static sdfTexHandle_t *sdfStdSpecularTex2;
static u64 sdfStdSpecularTex2_tex0reg;
static sdfTexHandle_t *sdfStdRefmapTex;
static sdf3DScreenParam_t *sdf3DScreenParam;
static sdfMatrix4_t sdf3DScreenTm;
static sdfMatrix4_t sdfCameraTm;
static sdfVector4_t sdf3DEyeOffset;
static sdf3DLightParallelPacket_t *sdf3DLightDefault;
static sdf3DFogPacket_t *sdf3DFogDefault;
static f32 sdfFaceDivSoften;
static f32 sdfFaceDivBias;

void DiagMatrix(void);
void MultMatrix(sdfMatrix4_t *aMatrix);
void MultMatrixRev(sdfMatrix4_t *aMatrix);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_B_A(void);
void SDF_VU0__APPLYMATRIX_XYZ1(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__GET_ROW2(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_MTXCOL_B(sdfMatrix4_t *p);
void SDF_VU0__NEGVECTOR_XYZ(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__RESET_ROW3(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SET_ROW0(void);
void SDF_VU0__SET_ROW1(void);
void SDF_VU0__SET_ROW2(void);
void SDF_VU0__SET_ROW3(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void sdf3DScreenParam_t__Copy(sdf3DScreenParam_t *this, sdf3DScreenParam_t *data);
f32 sdfFabs(f32 c);

// 0x17c9d00
u32 SDF_VIF_SET_DIRECT(u32 addr) {
  return addr | 0x50000000;
}

// 0x17cabc0
void sdf3DInit(s32 aNestLevelLimit) {

}

// 0x17cabb0
void sdf3DInitSpecularTex2(void) {
  ;
}

// 0x17caba0
void sdf3DLinkInitPacket(sdfDrawTag_t *aTag, sdf3DInitPacket_t *aPacket) {
  ;
}

// 0x17cab90
void sdf3DMakeDirectRefPacket(sdfGrRefPacketHeader_t *aPacket, void *aData, s32 aLeng) {
  ;
}

// 0x17caa90
void sdf3DMakeFogPacket(sdf3DFogPacket_t *aPacket, sdf3DFogParam_t *aParam) {
  struct System_Single_array *fogParm;
  f32 fogMax;
  f32 fogMin;
  f32 fogNear;
  f32 fogFar;
  struct System_Single_array *v9;
  struct System_Single_array *v11;
  struct System_Single_array *v13;

  fogParm = aPacket->fogParm;
  fogMax = aParam->fogMax;
  fogMin = aParam->fogMin;
  fogNear = aParam->fogNear;
  fogFar = aParam->fogFar;
  fogParm->m_Items[0] = fogMin;
  v9 = aPacket->fogParm;
  v9->m_Items[1] = fogMax;
  v11 = aPacket->fogParm;
  v11->m_Items[2] = ((fogMin + fogMax) + (((fogMin - fogMax) * (fogNear + fogFar)) / (fogFar - fogNear))) * 0.5;
  v13 = aPacket->fogParm;
  v13->m_Items[3] = ((fogMax - fogMin) * (fogNear * fogFar)) / (fogFar - fogNear);
}

// 0x17ca330
void sdf3DMakeLightParallelPacket(sdf3DLightParallelPacket_t *aPacket, sdf3DLight_t **aLights, sdfVector4_t aAmbient) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct UnityEngine_Vector4_array *color;
  u64 v12;
  sdf3DLight_t_o *v13;
  s64 i;
  sdf3DLight_t_o *v16;
  struct UnityEngine_Vector4_array *normal;
  struct UnityEngine_Vector4_array *v19;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v23;
  struct UnityEngine_Vector4_array *v25;
  struct UnityEngine_Vector4_array *v27;
  struct UnityEngine_Vector4_array *v29;
  struct UnityEngine_Vector4_array *v31;
  struct UnityEngine_Vector4_array *v33;
  struct UnityEngine_Vector4_array *v35;
  struct UnityEngine_Vector4_array *v37;
  struct UnityEngine_Vector4_array *v39;
  f32 v42;
  f32 v43;
  f32 v45;
  f32 v46;
  sdfVu0_c *v48;
  s32 v49;
  s32 v50;
  f32 v51;
  struct sdf3D_StaticFields *static_fields;
  s64 v56;
  s64 v57;
  s64 v58;
  s64 v59;
  s64 v60;
  s64 v61;
  s64 v62;
  UnityEngine_Matrix4x4_o v63;
  u64 dest[8];
  s64 v65;
  s64 v66;
  UnityEngine_Vector4_o v67;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v69;
  UnityEngine_Vector4_o v70;

  w = aAmbient.w;
  z = aAmbient.z;
  y = aAmbient.y;
  x = aAmbient.x;
  v69.x = x;
  v69.y = y;
  v69.z = z;
  v69.w = w;
  *&v67.x = 0;
  *&v67.z = 0;
  v65 = 0;
  v66 = 0;
  memset(dest, 0, sizeof(dest));
  *&p.x = 0;
  *&p.z = 0;
  SDF_VU0__LOADVECTOR_B(v69);
  color = aPacket->color;
  SDF_VU0__STOREVECTOR_B(&color->m_Items[3]);
  v12 = 0;
  v13 = 0;
  for (i = 32; i != 80; i += 16)
  {
    while (1)
    {
      v16 = aLights->m_Items[v12];
      if (!v16)
        break;
      if (!v13)
        v13 = aLights->m_Items[v12];
      SDF_VU0__LOADVECTOR(v16->v);
      SDF_VU0__NORMALIZE();
      SDF_VU0__SCALEVECTOR(-1.0);
      SDF_VU0__STOREVECTOR(&p);
      normal = aPacket->normal;
      sub_854710(&p, 0);
      sub_854930(normal->m_Items, v12);
      v19 = aPacket->normal;
      sub_854710(&p, 1u);
      sub_854930(&v19->m_Items[1], v12);
      v21 = aPacket->normal;
      sub_854710(&p, 2u);
      sub_854930(&v21->m_Items[2], v12);
      SDF_VU0__LOADVECTOR(v16->color);
      SDF_VU0__ADDVECTOR_B_A();
      v23 = aPacket->color;
      SDF_VU0__STOREVECTOR((v23 + i), 0);
      i += 16;
      ++v12;
      if (i == 80)
        goto LABEL_36;
    }
    v25 = aPacket->normal;
    sub_854930(v25->m_Items, v12);
    v27 = aPacket->normal;
    sub_854930(&v27->m_Items[1], v12);
    v29 = aPacket->normal;
    sub_854930(&v29->m_Items[2], v12);
    v31 = aPacket->color;
    sub_854930(v31 + i, 0);
    v33 = aPacket->color;
    sub_854930(v33 + i, 1u);
    v35 = aPacket->color;
    sub_854930(v35 + i, 2u);
    v37 = aPacket->color;
    sub_854930(v37 + i, 3u);
    ++v12;
  }
LABEL_36:
  v39 = aPacket->color;
  SDF_VU0__STOREVECTOR_B(&v39->m_Items[4]);
  if (v13)
  {
    *&v67.x = 0;
    *&v67.z = 0;
    SDF_VU0__LOADVECTOR(v13->v);
    SDF_VU0__NORMALIZE();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__SET_ROW2();
    SDF_VU0__STOREVECTOR(&v67);
    sub_854710(&v67, 0);
    v43 = v42;
    if (sdfFabs(v43) >= 0.000001)
      goto LABEL_48;
    sub_854710(&v67, 2u);
    v46 = v45;
    if (sdfFabs(v46) >= 0.000001)
    {
LABEL_48:
      sub_854690(&v65, 0.0, 0.0, 0.0, 0.0);
      memmove(dest, v48->static_fields, 0x40u);
      sub_19FFB10(dest, 1, 0);
      LODWORD(v65) = v49;
      memmove(dest, sdfVu0->static_fields, 0x40u);
      sub_19FFB10(dest, 1, 1);
      HIDWORD(v65) = v50;
      memmove(dest, sdfVu0->static_fields, 0x40u);
      sub_19FFB10(dest, 1, 2);
      v70.z = v51;
      *&v66 = v51;
      v70.w = *(&v66 + 1);
      *&v70.x = v65;
    }
    else
    {
      sub_854710(&v67, 1u);
      sub_854930(&v67, 0);
      sub_854930(&v67, 1u);
      sub_854930(&v67, 2u);
      sub_854930(&v67, 3u);
      v70 = v67;
    }
    SDF_VU0__LOADVECTOR_B(v70);
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__SET_ROW0();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__GET_ROW2();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__SET_ROW1();
    SDF_VU0__RESET_ROW3();
    DiagMatrix();
    SDF_VU0__LOADVECTOR(v13->v);
    SDF_VU0__NORMALIZE();
    v56 = *&sdfCameraTm.m00;
    v57 = *&sdfCameraTm.m20;
    v58 = *&sdfCameraTm.m21;
    *&v63.m01 = *&sdfCameraTm.m01;
    *&v63.m21 = v58;
    *&v63.m00 = v56;
    *&v63.m20 = v57;
    v59 = *&sdfCameraTm.m02;
    v60 = *&sdfCameraTm.m22;
    v62 = *&sdfCameraTm.m03;
    v61 = *&sdfCameraTm.m23;
    *&v63.m03 = v62;
    *&v63.m23 = v61;
    *&v63.m02 = v59;
    *&v63.m22 = v60;
    SDF_VU0__LOADVECTOR_MTXCOL_B(&v63);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__NEGVECTOR_XYZ();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SET_ROW3();
    SDF_VU0__STOREMATRIX(&aPacket->TM);
  }
  else
  {
    SDF_VU0__STOREIDENTITY(&aPacket->TM);
  }
}

// 0x17c9f80
void sdf3DMakeScreenParam(sdf3DScreenParam_t **aParam) {
  f32 fovy;
  UnityEngine_Matrix4x4_o v6;
  UnityEngine_Matrix4x4_o v7;
  UnityEngine_Matrix4x4_o v8;
  UnityEngine_Matrix4x4_o aMatrix;

  memset(&aMatrix, 0, sizeof(aMatrix));
  SDF_VU0__STOREIDENTITY(&aMatrix);
  sub_19FFD30(&aMatrix, 0, 0);
  sub_19FFD30(&aMatrix, 1, 1);
  sub_19FFD30(&aMatrix, 2, 2);
  sub_19FFD30(&aMatrix, 3, 2);
  v8 = aMatrix;
  SDF_VU0__LOADMATRIX(&v8);
  SDF_VU0__STOREIDENTITY(&aMatrix);
  if (((*aParam)->flags & 2) != 0)
  {
    fovy = (*aParam)->fovy;
    tanf(fovy * 0.5);
  }
  sub_19FFD30(&aMatrix, 0, 0);
  sub_19FFD30(&aMatrix, 1, 1);
  sub_19FFD30(&aMatrix, 2, 2);
  sub_19FFD30(&aMatrix, 2, 3);
  sub_19FFD30(&aMatrix, 3, 2);
  sub_19FFD30(&aMatrix, 3, 3);
  v7 = aMatrix;
  v6 = v7;
  MultMatrix(&v6);
  SDF_VU0__STOREMATRIX(&(*aParam)->TM, 0);
  sub_854930(&(*aParam)->scale, 0);
  sub_854930(&(*aParam)->scale, 1u);
  sub_854930(&(*aParam)->scale, 2u);
  sub_854930(&(*aParam)->scale, 3u);
  sub_854930(&(*aParam)->trans, 0);
  sub_854930(&(*aParam)->trans, 1u);
  sub_854930(&(*aParam)->trans, 2u);
  sub_854930(&(*aParam)->trans, 3u);
}

// 0x17c9d10
void sdf3DMakeViewportPacket(sdf3DViewportPacket_t *aPacket, sdf3DScreenParam_t *aParam, sdfMatrix4_t *aCamera) {
  ;
}

// 0x17c9d20
void sdf3DSetCamera(sdf3DScreenParam_t *aParam, sdfMatrix4_t *aCamera) {
  s64 v5;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  UnityEngine_Matrix4x4_o v20;
  UnityEngine_Matrix4x4_o v21;
  UnityEngine_Matrix4x4_o v22;

  v5 = *&aCamera->m00;
  v6 = *&aCamera->m20;
  v7 = *&aCamera->m21;
  *&v22.m01 = *&aCamera->m01;
  *&v22.m21 = v7;
  *&v22.m00 = v5;
  *&v22.m20 = v6;
  v8 = *&aCamera->m02;
  v9 = *&aCamera->m22;
  v10 = *&aCamera->m23;
  *&v22.m03 = *&aCamera->m03;
  *&v22.m23 = v10;
  *&v22.m02 = v8;
  *&v22.m22 = v9;
  SDF_VU0__LOADMATRIX(&v22);
  SDF_VU0__STOREMATRIX(&sdfCameraTm);
  v14 = *&aParam->TM.m00;
  v15 = *&aParam->TM.m20;
  v16 = *&aParam->TM.m21;
  *&v21.m01 = *&aParam->TM.m01;
  *&v21.m21 = v16;
  *&v21.m00 = v14;
  *&v21.m20 = v15;
  v17 = *&aParam->TM.m23;
  v18 = *&aParam->TM.m02;
  v19 = *&aParam->TM.m22;
  *&v21.m03 = *&aParam->TM.m03;
  *&v21.m23 = v17;
  *&v21.m02 = v18;
  *&v21.m22 = v19;
  v20 = v21;
  MultMatrixRev(&v20);
  SDF_VU0__LOADVECTOR(aParam->cameraPos);
  SDF_VU0__STOREMATRIX(&sdf3DScreenTm);
  SDF_VU0__APPLYMATRIX_XYZ1();
  SDF_VU0__STOREVECTOR(&sdf3DEyeOffset);
  sdf3DScreenParam_t__Copy(sdf3DScreenParam, aParam);
}

// 0x17c9f10
void sdf3DSetDefaultFog(sdf3DFogPacket_t *aFog) {
  sdf3DFogDefault = aFog;
}

// 0x17c9ea0
void sdf3DSetDefaultLight(sdf3DLightParallelPacket_t *aLight) {
  sdf3DLightDefault = aLight;
}
