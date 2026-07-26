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
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__SET_ROW2();
    sdfFabs(0);
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__SET_ROW0();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__GET_ROW2();
    SDF_VU0__SET_ROW1();
    SDF_VU0__RESET_ROW3();
    DiagMatrix();
    SDF_VU0__LOADVECTOR_MTXCOL_B(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__NEGVECTOR_XYZ();
    SDF_VU0__SET_ROW3();
    SDF_VU0__STOREMATRIX(0);
    SDF_VU0__STOREIDENTITY(0);
}

// 0x17c9f80
void sdf3DMakeScreenParam(sdf3DScreenParam_t **aParam) {
    SDF_VU0__STOREIDENTITY(0);
    SDF_VU0__LOADMATRIX(0);
    MultMatrix(0);
    SDF_VU0__STOREMATRIX(0);
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
