#include "types.h"

typedef struct dds3DrawEnv_t dds3DrawEnv_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct effDebug effDebug;
typedef struct effHandle_t effHandle_t;
typedef struct effPCP_ThunderPolyParam_t effPCP_ThunderPolyParam_t;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdf3DFogParam_t sdf3DFogParam_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfRandCB_t sdfRandCB_t;

struct effDebug {
    sdfMat_t *effDebugSelectCursorDraw_pMat;
    u32 effDebugSelectCursorDraw_vc[3];
    sdfVector4_t *effDebugSelectCursorDraw_vertex;
    f32 effDebugSelectCursorDraw_rotateY;
};

static s32 SCE_WRONLY;
static s32 SCE_TRUNC;
static s32 SCE_CREAT;
static s32 DDS3EFFECT_BLEND_ADD;
static s32 DDS3_SCREEN_OFFX;
static s32 DDS3_SCREEN_OFFY;
static sdfGrOt_t *dds3Ot[1];
static sdfRandCB_t *dds3Effect_Rand;
static dds3DrawEnv_t *dds3DrawEnv;
static sdfModelOt_t *dds3ModelOt[11];

void MultMatrixNoArg(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void SetRotateMatrixX(f32 aAngle);
void effScreenOffset(void);
f32 sdfCos(f32 aRadius);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
void *sdfGrAllocPacketBuff(s32 aSize);
void *sdfPrimMake3DLine(sdfVector4_t aVertex, u32 aColor, s32 aNumOfVert, s32 aMode);
f32 sdfSin(f32 aRadius);

// 0x1387430
s8 SDF_ARRAYCOUNT(s8 **n) {
  s32 v4;

  v4 = n->m_Items[0];
  return *il2cp::SizeOf(n, sbyte) / v4;
}

// 0x13873b0
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix) {
  return a | (4 * b) | (16 * c) | fix | (d << 6);
}

// 0x13873f0
s32 SDF_GS_SET_TEST(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  return ate | (2 * atst) | (16 * aref) | (afail << 12) | (date << 14) | (datm << 15) | (zte << 16) | (ztst << 17);
}

// 0x13873d0
s32 SDF_GS_SET_TEX1(s32 lcm, s32 xml, s32 mmag, s32 mmin, s32 mtba, s32 l, s32 k) {
  return lcm | (4 * xml) | (32 * mmag) | (mmin << 6) | (mtba << 9) | k | (l << 19);
}

// 0x13875a0
effHandle_t *dds3EffectLoad(void *pD3P) {
  return 0;
}

// 0x13875d0
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc) {
  return 0;
}

// 0x13875b0
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData) {
  return 0;
}

// 0x13875c0
dds3ModelHandle_t *dds3EffectPartGetHandle(effPartHandle_t *hEffPart) {
  return 0;
}

// 0x13874b0
void *dds3PrimFrameRect(s32 aX, s32 aY, u32 aZ, s32 aW, s32 aH, u32 aBgCol, u32 aFrameCol) {
  s32 v9;

  v9 = 0;
  return sub_8D3950(s32, &v9);
}

// 0x1387510
void *dds3PrimLine(s32 aX0, s32 aY0, u32 aZ0, u32 aColor0, s32 aX1, s32 aY1, u32 aZ1, u32 aColor1, s32 aMode) {
  s32 v11;

  v11 = 0;
  return sub_8D3950(s32, &v11);
}

// 0x1387600
dds3TrackPoly_t *dds3TrackPolyCreate(s32 number, s32 face, s32 rec, s32 type) {
  return 0;
}

// 0x1387570
void dds3TrackPolyDelete(dds3TrackPoly_t *hTrackPoly) {
  ;
}

// 0x1387590
void dds3TrackPolySetMode(dds3TrackPoly_t *hTrackPoly, u16 mode) {
  ;
}

// 0x1387cb0
void effDebugLineDraw(effDebug *this, sdfVector4_t pPos0, sdfVector4_t pPos1) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  u64 *v12;
  u64 *v13;
  s64 *v14;
  s64 *v15;
  s64 *v17;
  Il2CppClass *v18;
  s64 *v19;
  s64 *Interface;
  char *v23;
  s64 *v24;
  Il2CppClass *v25;
  s64 *v26;
  char *v27;
  s64 *v28;
  u64 *v30;
  s32 *v32;
  Il2CppObject *v33;
  sdfDrawTag_t_o *v35;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v38;
  s64 *v39;
  s64 v42;
  f32 v43;
  s64 v44;
  f32 v45;
  s64 v46;
  f32 v48;
  s64 v49;
  f32 v52;
  u64 *v54;
  struct sdfGrOt_t_array *dds3Ot;
  char v74[4];
  char v75[16];
  char *v76;
  UnityEngine_Vector4_o v77;
  UnityEngine_Vector4_o v78;

  w = pPos1.w;
  z = pPos1.z;
  y = pPos1.y;
  x = pPos1.x;
  v8 = pPos0.w;
  v9 = pPos0.z;
  v10 = pPos0.y;
  v11 = pPos0.x;
  v12 = NewSpecific(UnityEngine_Vector4, 2u);
  v13 = NewSpecific(int__, 2u);
  v14 = NewSpecific(s32, 2u);
  v15 = v14;
  v13[4] = v15;
  v74[0] = 0;
  v17 = sub_8D3950(bool, v74);
  if (v17)
  {
    v19 = v17;
    Interface = QueryInterface(v17, s32);
    if (!Interface)
    {
      sub_8FC2C0(*(*v19 + 64), v18, v75);
      if ((v75[0] & 1) != 0)
        v23 = v76;
      else
        v23 = &v75[1];
      v24 = sub_8C4940(v23);
    }
    v26 = QueryInterface(v19, s32);
    if (!v26)
    {
      sub_8FC2C0(*(*v19 + 64), v25, v75);
      if ((v75[0] & 1) != 0)
        v27 = v76;
      else
        v27 = &v75[1];
      v28 = sub_8C4940(v27);
    }
  }
  else
  {
    v26 = 0;
  }
  v13[5] = v26;
  v30 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v30);
  v32 = il2cp::SizeOf(v30, s32);
  v33 = sdfGrAllocPacketBuff(*v32);
  v35 = v33;
  if (v33)
  {
    klass = v33->klass;
    if (v33->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v75);
      if ((v75[0] & 1) != 0)
        v38 = v76;
      else
        v38 = &v75[1];
      v39 = sub_8C4940(v38);
    }
  }
  sdfDrawTagInit(v35);
  v77.x = v11;
  v77.y = v10;
  v77.z = v9;
  v77.w = v8;
  SDF_VU0__LOADVECTOR(v77);
  effScreenOffset();
  SDF_VU0__STOREVECTOR(v12 + 2);
  v78.x = x;
  v78.y = y;
  v78.z = z;
  v78.w = w;
  SDF_VU0__LOADVECTOR(v78);
  effScreenOffset();
  SDF_VU0__STOREVECTOR(v12 + 3);
  v42 = v13[4];
  sub_854710((v12 + 4), 0);
  *(v42 + 32) = v43 - 1792;
  v44 = v13[4];
  sub_854710((v12 + 4), 1u);
  *(v44 + 36) = 2 * v45 - 3872;
  v46 = v13[5];
  sub_854710((v12 + 6), 0);
  *(v46 + 32) = v48 - 1792;
  v49 = v13[5];
  sub_854710((v12 + 6), 1u);
  *(v49 + 36) = 2 * v52 - 3872;
  if (!*(v13 + 6))
    goto LABEL_81;
LABEL_59:
  *v75 = 0;
  v54 = sub_8D3950(s32, v75);
  sdfDrawTagLink(v35, v54);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v35);
}

// 0x1388500
void effDebugLineDraw2(effDebug *this, sdfVector4_t pPos0, sdfVector4_t pPos1, u32 abgr) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  u64 *v13;
  u64 *v14;
  s64 *v15;
  s64 *v16;
  s64 *v18;
  Il2CppClass *v19;
  s64 *v20;
  s64 *Interface;
  char *v24;
  s64 *v25;
  Il2CppClass *v26;
  s64 *v27;
  char *v28;
  s64 *v29;
  u64 *v31;
  s32 *v33;
  Il2CppObject *v34;
  sdfDrawTag_t_o *v36;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v39;
  s64 *v40;
  s64 v43;
  f32 v44;
  s64 v45;
  f32 v46;
  s64 v47;
  f32 v49;
  s64 v50;
  f32 v53;
  u64 *v55;
  struct sdfGrOt_t_array *dds3Ot;
  char v75[4];
  char v76[16];
  char *v77;
  UnityEngine_Vector4_o v78;
  UnityEngine_Vector4_o v79;

  w = pPos1.w;
  z = pPos1.z;
  y = pPos1.y;
  x = pPos1.x;
  v9 = pPos0.w;
  v10 = pPos0.z;
  v11 = pPos0.y;
  v12 = pPos0.x;
  v13 = NewSpecific(UnityEngine_Vector4, 2u);
  v14 = NewSpecific(int__, 2u);
  v15 = NewSpecific(s32, 2u);
  v16 = v15;
  v14[4] = v16;
  v75[0] = 0;
  v18 = sub_8D3950(bool, v75);
  if (v18)
  {
    v20 = v18;
    Interface = QueryInterface(v18, s32);
    if (!Interface)
    {
      sub_8FC2C0(*(*v20 + 64), v19, v76);
      if ((v76[0] & 1) != 0)
        v24 = v77;
      else
        v24 = &v76[1];
      v25 = sub_8C4940(v24);
    }
    v27 = QueryInterface(v20, s32);
    if (!v27)
    {
      sub_8FC2C0(*(*v20 + 64), v26, v76);
      if ((v76[0] & 1) != 0)
        v28 = v77;
      else
        v28 = &v76[1];
      v29 = sub_8C4940(v28);
    }
  }
  else
  {
    v27 = 0;
  }
  v14[5] = v27;
  v31 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v31);
  v33 = il2cp::SizeOf(v31, s32);
  v34 = sdfGrAllocPacketBuff(*v33);
  v36 = v34;
  if (v34)
  {
    klass = v34->klass;
    if (v34->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v76);
      if ((v76[0] & 1) != 0)
        v39 = v77;
      else
        v39 = &v76[1];
      v40 = sub_8C4940(v39);
    }
  }
  sdfDrawTagInit(v36);
  v78.x = v12;
  v78.y = v11;
  v78.z = v10;
  v78.w = v9;
  SDF_VU0__LOADVECTOR(v78);
  effScreenOffset();
  SDF_VU0__STOREVECTOR(v13 + 2);
  v79.x = x;
  v79.y = y;
  v79.z = z;
  v79.w = w;
  SDF_VU0__LOADVECTOR(v79);
  effScreenOffset();
  SDF_VU0__STOREVECTOR(v13 + 3);
  v43 = v14[4];
  sub_854710((v13 + 4), 0);
  *(v43 + 32) = v44 - 1792;
  v45 = v14[4];
  sub_854710((v13 + 4), 1u);
  *(v45 + 36) = 2 * v46 - 3872;
  v47 = v14[5];
  sub_854710((v13 + 6), 0);
  *(v47 + 32) = v49 - 1792;
  v50 = v14[5];
  sub_854710((v13 + 6), 1u);
  *(v50 + 36) = 2 * v53 - 3872;
  if (!*(v14 + 6))
    goto LABEL_81;
LABEL_59:
  *v76 = 0;
  v55 = sub_8D3950(s32, v76);
  sdfDrawTagLink(v36, v55);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v36);
}

// 0x1387630
void effDebugPointDraw(effDebug *this, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  u32 *v7;
  u64 *v8;
  s32 *v10;
  Il2CppObject *v11;
  sdfDrawTag_t_o *v13;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  f32 v18;
  f32 v21;
  u32 v23;
  u64 *v24;
  struct sdfGrOt_t_array *dds3Ot;
  UnityEngine_Vector4_o p;
  u64 v30[3];
  UnityEngine_Vector4_o v31;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  *&p.x = 0;
  *&p.z = 0;
  v7 = NewSpecific(s32, 2u);
  v8 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v8);
  v10 = il2cp::SizeOf(v8, s32);
  v11 = sdfGrAllocPacketBuff(*v10);
  v13 = v11;
  if (v11)
  {
    klass = v11->klass;
    if (v11->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v30);
      if ((v30[0] & 1) != 0)
        v16 = v30[2];
      else
        v16 = v30 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  sdfDrawTagInit(v13);
  v31.x = x;
  v31.y = y;
  v31.z = z;
  v31.w = w;
  SDF_VU0__LOADVECTOR(v31);
  effScreenOffset();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 0);
  v7[8] = v18 - 1792;
  sub_854710(&p, 1u);
  v7[9] = 2 * v21 - 3872;
  v23 = v7[6];
  if (!v23)
    goto LABEL_30;
LABEL_23:
  LODWORD(v30[0]) = 0;
  v24 = sub_8D3950(s32, v30);
  sdfDrawTagLink(v13, v24);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v13);
}

// 0x1387970
void effDebugPointDraw2(effDebug *this, sdfVector4_t pPos, u32 color) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  u32 *v8;
  u64 *v9;
  s32 *v11;
  Il2CppObject *v12;
  sdfDrawTag_t_o *v14;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  f32 v19;
  f32 v22;
  u32 v24;
  u64 *v25;
  struct sdfGrOt_t_array *dds3Ot;
  UnityEngine_Vector4_o p;
  u64 v31[3];
  UnityEngine_Vector4_o v32;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  *&p.x = 0;
  *&p.z = 0;
  v8 = NewSpecific(s32, 2u);
  v9 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v9);
  v11 = il2cp::SizeOf(v9, s32);
  v12 = sdfGrAllocPacketBuff(*v11);
  v14 = v12;
  if (v12)
  {
    klass = v12->klass;
    if (v12->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v31);
      if ((v31[0] & 1) != 0)
        v17 = v31[2];
      else
        v17 = v31 + 1;
      v18 = sub_8C4940(v17);
    }
  }
  sdfDrawTagInit(v14);
  v32.x = x;
  v32.y = y;
  v32.z = z;
  v32.w = w;
  SDF_VU0__LOADVECTOR(v32);
  effScreenOffset();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 0);
  v8[8] = v19 - 1792;
  sub_854710(&p, 1u);
  v8[9] = 2 * v22 - 3872;
  v24 = v8[6];
  if (!v24)
    goto LABEL_30;
LABEL_23:
  LODWORD(v31[0]) = 0;
  v25 = sub_8D3950(s32, v31);
  sdfDrawTagLink(v14, v25);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v14);
}

// 0x1389640
void effDebugSelectCursorDraw(effDebug *this, sdfVector4_t pPos) {
  ;
}

// 0x1388d50
void effDebugStringDraw(effDebug *this, s32 x, s32 y, s32 attr, char **pString) {
  u64 *v10;
  s32 *v12;
  Il2CppObject *v13;
  sdfDrawTag_t_o *v15;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  s32 DDS3_SCREEN_OFFX;
  s32 DDS3_SCREEN_OFFY;
  System_String_o *v25;
  System_Object_array *v27;
  Il2CppObject *v28;
  struct sdfGrOt_t_array *dds3Ot;
  u64 v31[3];

  v10 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v10);
  v12 = il2cp::SizeOf(v10, s32);
  v13 = sdfGrAllocPacketBuff(*v12);
  v15 = v13;
  if (v13)
  {
    klass = v13->klass;
    if (v13->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v31);
      if ((v31[0] & 1) != 0)
        v18 = v31[2];
      else
        v18 = v31 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  sdfDrawTagInit(v15);
  v25 = *pString;
  v27 = Empty_string_();
  v28 = sdfDevPrintf(DDS3_SCREEN_OFFX + 16 * x, DDS3_SCREEN_OFFY + 8 * y, 0xFF0000u, attr, v25, v27);
  sdfDrawTagLink(v15, v28);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v15);
}

// 0x138a430
void effDebugWindowDraw(effDebug *this, s32 x, s32 y, s32 w, s32 h, s32 bg_c, s32 frame_c) {
  u64 *v8;
  s32 *v10;
  Il2CppObject *v11;
  sdfDrawTag_t_o *v13;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  u64 *v19;
  struct sdfGrOt_t_array *dds3Ot;
  u64 v22[3];

  v8 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v8);
  v10 = il2cp::SizeOf(v8, s32);
  v11 = sdfGrAllocPacketBuff(*v10);
  v13 = v11;
  if (v11)
  {
    klass = v11->klass;
    if (v11->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v22);
      if ((v22[0] & 1) != 0)
        v16 = v22[2];
      else
        v16 = v22 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  sdfDrawTagInit(v13);
LABEL_20:
  LODWORD(v22[0]) = 0;
  v19 = sub_8D3950(s32, v22);
  sdfDrawTagLink(v13, v19);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v13);
}

// 0x1389650
void effDebugWireframeCylinderDraw(effDebug *this, sdfVector4_t pCenter, f32 radius_max, f32 height_max, u32 abgr) {
  f32 w;
  s64 *v8;
  u64 *v9;
  u64 *v10;
  s32 *v12;
  Il2CppObject *v13;
  sdfDrawTag_t_o *v15;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  u64 i;
  u64 *v22;
  s64 v23;
  u32 v24;
  f32 v25;
  s32 v26;
  Il2CppClass *v29;
  s64 *Interface;
  char *v31;
  s64 *v32;
  s32 v34;
  s32 v35;
  s64 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  u32 *v41;
  Il2CppObject *v43;
  u64 *v44;
  s64 v45;
  bool v46;
  f32 v48;
  s32 v49;
  Il2CppClass *v50;
  s64 *v51;
  char *v52;
  s64 *v53;
  s32 v55;
  s32 v56;
  s64 v57;
  f32 v58;
  f32 v59;
  f32 v60;
  f32 v61;
  u32 *v62;
  Il2CppObject *v64;
  u64 *v65;
  s64 v66;
  f32 v68;
  s32 v69;
  Il2CppClass *v70;
  s64 *v71;
  char *v72;
  s64 *v73;
  s32 v75;
  s32 v76;
  s64 v77;
  f32 v78;
  f32 v79;
  f32 v80;
  f32 v81;
  u32 *v82;
  Il2CppObject *v84;
  u64 *v85;
  s64 v86;
  f32 v88;
  s32 v89;
  Il2CppClass *v90;
  s64 *v91;
  char *v92;
  s64 *v93;
  s32 v95;
  s32 v96;
  s64 v97;
  f32 v98;
  f32 v99;
  f32 v100;
  f32 v101;
  u32 *v102;
  Il2CppObject *v104;
  struct sdfGrOt_t_array *dds3Ot;
  f32 v107;
  f32 x;
  f32 y;
  f32 p;
  UnityEngine_Vector4_o v111;
  UnityEngine_Vector4_o v112;
  u64 v113[2];
  char *v114;
  UnityEngine_Vector4_o v115;
  UnityEngine_Vector4_o v116;
  UnityEngine_Vector4_o v117;
  UnityEngine_Vector4_o v118;
  UnityEngine_Vector4_o v119;
  UnityEngine_Vector4_o v120;
  UnityEngine_Vector4_o v121;
  UnityEngine_Vector4_o v122;

  w = pCenter.w;
  y = pCenter.y;
  p = pCenter.z;
  x = pCenter.x;
  *&v111.x = 0;
  *&v111.z = 0;
  *&v112.x = 0;
  *&v112.z = 0;
  v8 = NewSpecific(UnityEngine_Vector4, 0x28u);
  v9 = NewSpecific(uint, 0x28u);
  v10 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v10);
  v12 = il2cp::SizeOf(v10, s32);
  v13 = sdfGrAllocPacketBuff(*v12);
  v15 = v13;
  if (v13)
  {
    klass = v13->klass;
    if (v13->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v113);
      if ((v113[0] & 1) != 0)
        v18 = v114;
      else
        v18 = v113 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  sdfDrawTagInit(v15);
  for (i = 0; i != 40; ++i)
  {
    *(v9 + i + 8) = abgr;
  }
  v22 = il2cp::SizeOf(v8, UnityEngine_Vector4);
  v23 = v22[1];
  *&v111.x = *v22;
  *&v111.z = v23;
  v24 = 0;
  do
  {
    sub_854930(&v112, 0);
    sub_854930(&v112, 1u);
    sub_854930(&v112, 2u);
    v115.x = x;
    v115.y = y;
    v115.z = p;
    v115.w = w;
    SDF_VU0__LOADVECTOR_B(v115);
    SDF_VU0__LOADVECTOR(v112);
    SDF_VU0__ADDVECTOR();
    v25 = 0.0;
    v26 = 20;
    do
    {
      SDF_VU0__STOREVECTOR(&v111);
      v25 = v25 + 0.31416;
      sdfCos(v25);
      sub_854930(&v112, 0);
      sub_854930(&v112, 1u);
      sdfSin(v25);
      sub_854930(&v112, 2u);
      SDF_VU0__LOADVECTOR(v112);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&v111);
      --v26;
    }
    while (v26);
    else if (!v8)
    {
      goto LABEL_35;
    }
    Interface = QueryInterface(v8, sbyte);
    if (!Interface)
    {
      sub_8FC2C0(*(*v8 + 64), v29, v113);
      if ((v113[0] & 1) != 0)
        v31 = v114;
      else
        v31 = v113 + 1;
      v32 = sub_8C4940(v31);
    }
LABEL_36:
    v34 = *(Interface + 32);
    v35 = *il2cp::SizeOf(Interface, sbyte) / v34;
    v36 = il2cp::SizeOf(v8, UnityEngine_Vector4);
    v38 = *v36;
    v37 = *(v36 + 4);
    v39 = *(v36 + 8);
    v40 = *(v36 + 12);
    v41 = il2cp::SizeOf(v9, uint);
    v116.x = v38;
    v116.y = v37;
    v116.z = v39;
    v116.w = v40;
    v43 = sdfPrimMake3DLine(v116, *v41, v35, 128);
    sdfDrawTagLink(v15, v43);
    v44 = il2cp::SizeOf(v8, UnityEngine_Vector4);
    v45 = v44[1];
    v46 = v24++ >= 0x13;
    *&v111.x = *v44;
    *&v111.z = v45;
  }
  while (!v46);
  v117.x = x;
  v117.y = y;
  v117.z = p;
  v117.w = w;
  SDF_VU0__LOADVECTOR_B(v117);
  v48 = 0.0;
  v49 = 20;
  do
  {
    sdfCos(v48);
    sub_854930(&v112, 0);
    sub_854930(&v112, 1u);
    sdfSin(v48);
    sub_854930(&v112, 2u);
    SDF_VU0__LOADVECTOR(v112);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v111);
    sdfCos(v48);
    sub_854930(&v112, 0);
    sub_854930(&v112, 1u);
    sdfSin(v48);
    sub_854930(&v112, 2u);
    SDF_VU0__LOADVECTOR(v112);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v111);
    v48 = v48 + 0.31416;
    --v49;
  }
  while (v49);
  if (!v8)
  {
LABEL_59:
    v51 = 0;
    goto LABEL_60;
  }
LABEL_53:
  v51 = QueryInterface(v8, sbyte);
  if (!v51)
  {
    sub_8FC2C0(*(*v8 + 64), v50, v113);
    if ((v113[0] & 1) != 0)
      v52 = v114;
    else
      v52 = v113 + 1;
    v53 = sub_8C4940(v52);
  }
LABEL_60:
  v107 = w;
  v55 = *(v51 + 32);
  v56 = *il2cp::SizeOf(v51, sbyte) / v55;
  v57 = il2cp::SizeOf(v8, UnityEngine_Vector4);
  v58 = *v57;
  v59 = *(v57 + 4);
  v61 = *(v57 + 8);
  v60 = *(v57 + 12);
  v62 = il2cp::SizeOf(v9, uint);
  v118.x = v58;
  v118.y = v59;
  v118.z = v61;
  v118.w = v60;
  v64 = sdfPrimMake3DLine(v118, *v62, v56, 128);
  sdfDrawTagLink(v15, v64);
  v65 = il2cp::SizeOf(v8, UnityEngine_Vector4);
  v119.x = x;
  v119.y = y;
  v119.z = p;
  v119.w = v107;
  v66 = v65[1];
  *&v111.x = *v65;
  *&v111.z = v66;
  SDF_VU0__LOADVECTOR_B(v119);
  v68 = 0.0;
  v69 = 10;
  do
  {
    sdfCos(v68);
    sub_854930(&v112, 0);
    sub_854930(&v112, 1u);
    sdfSin(v68);
    sub_854930(&v112, 2u);
    SDF_VU0__LOADVECTOR(v112);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v111);
    sdfCos(v68 + 3.1416);
    sub_854930(&v112, 0);
    sub_854930(&v112, 1u);
    sdfSin(v68 + 3.1416);
    sub_854930(&v112, 2u);
    SDF_VU0__LOADVECTOR(v112);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v111);
    v68 = v68 + 0.31416;
    --v69;
  }
  while (v69);
  if (!v8)
  {
LABEL_81:
    v71 = 0;
    goto LABEL_82;
  }
LABEL_75:
  v71 = QueryInterface(v8, sbyte);
  if (!v71)
  {
    sub_8FC2C0(*(*v8 + 64), v70, v113);
    if ((v113[0] & 1) != 0)
      v72 = v114;
    else
      v72 = v113 + 1;
    v73 = sub_8C4940(v72);
  }
LABEL_82:
  v75 = *(v71 + 32);
  v76 = *il2cp::SizeOf(v71, sbyte) / v75;
  v77 = il2cp::SizeOf(v8, UnityEngine_Vector4);
  v78 = *v77;
  v79 = *(v77 + 4);
  v81 = *(v77 + 8);
  v80 = *(v77 + 12);
  v82 = il2cp::SizeOf(v9, uint);
  v120.x = v78;
  v120.y = v79;
  v120.z = v81;
  v120.w = v80;
  v84 = sdfPrimMake3DLine(v120, *v82, (v76 + ((v76 & 0x80) >> 7)) >> 1, 128, 0);
  sdfDrawTagLink(v15, v84);
  v85 = il2cp::SizeOf(v8, UnityEngine_Vector4);
  v121.x = x;
  v121.y = y;
  v121.z = p;
  v121.w = v107;
  v86 = v85[1];
  *&v111.x = *v85;
  *&v111.z = v86;
  SDF_VU0__LOADVECTOR_B(v121);
  v88 = 0.0;
  v89 = 10;
  do
  {
    sdfCos(v88);
    sub_854930(&v112, 0);
    sub_854930(&v112, 1u);
    sdfSin(v88);
    sub_854930(&v112, 2u);
    SDF_VU0__LOADVECTOR(v112);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v111);
    sdfCos(v88 + 3.1416);
    sub_854930(&v112, 0);
    sub_854930(&v112, 1u);
    sdfSin(v88 + 3.1416);
    sub_854930(&v112, 2u);
    SDF_VU0__LOADVECTOR(v112);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v111);
    v88 = v88 + 0.31416;
    --v89;
  }
  while (v89);
  if (!v8)
  {
LABEL_103:
    v91 = 0;
    goto LABEL_104;
  }
LABEL_97:
  v91 = QueryInterface(v8, sbyte);
  if (!v91)
  {
    sub_8FC2C0(*(*v8 + 64), v90, v113);
    if ((v113[0] & 1) != 0)
      v92 = v114;
    else
      v92 = v113 + 1;
    v93 = sub_8C4940(v92);
  }
LABEL_104:
  v95 = *(v91 + 32);
  v96 = *il2cp::SizeOf(v91, sbyte) / v95;
  v97 = il2cp::SizeOf(v8, UnityEngine_Vector4);
  v98 = *v97;
  v99 = *(v97 + 4);
  v100 = *(v97 + 8);
  v101 = *(v97 + 12);
  v102 = il2cp::SizeOf(v9, uint);
  v122.x = v98;
  v122.y = v99;
  v122.z = v100;
  v122.w = v101;
  v104 = sdfPrimMake3DLine(v122, *v102, (v96 + ((v96 & 0x80) >> 7)) >> 1, 128, 0);
  sdfDrawTagLink(v15, v104);
  sdfDrawTagLinkOt(dds3Ot->m_Items[44], v15);
}

// 0x1388fb0
void effDebugWireframeSphereDraw(effDebug *this, sdfVector4_t pCenter, f32 radius_max, u32 abgr) {
  f32 y;
  f32 x;
  s64 *v8;
  u64 *v9;
  u64 *v10;
  s32 *v12;
  Il2CppObject *v13;
  sdfDrawTag_t_o *v15;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  u64 i;
  s32 v22;
  u32 v23;
  s64 *v24;
  s64 v25;
  s64 v26;
  f32 v27;
  s32 v28;
  Il2CppClass *v31;
  s64 *Interface;
  char *v33;
  s64 *v34;
  s32 v36;
  s32 v37;
  s64 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  u32 *v43;
  Il2CppObject *v45;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v52;
  s32 v53;
  f32 z;
  f32 w;
  UnityEngine_Matrix4x4_o v56;
  UnityEngine_Matrix4x4_o v57;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v60;
  u64 v61[2];
  char *v62;
  UnityEngine_Vector4_o v63;
  UnityEngine_Vector4_o v64;

  y = pCenter.y;
  x = pCenter.x;
  z = pCenter.z;
  w = pCenter.w;
  *&p.x = 0;
  *&p.z = 0;
  *&v60.x = 0;
  *&v60.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v8 = NewSpecific(UnityEngine_Vector4, 0x28u);
  v9 = NewSpecific(uint, 0x28u);
  v10 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v10);
  v12 = il2cp::SizeOf(v10, s32);
  v13 = sdfGrAllocPacketBuff(*v12);
  v15 = v13;
  if (v13)
  {
    klass = v13->klass;
    if (v13->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v61);
      if ((v61[0] & 1) != 0)
        v18 = v62;
      else
        v18 = v61 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  sdfDrawTagInit(v15);
  for (i = 0; i != 40; ++i)
  {
    *(v9 + i + 8) = abgr;
  }
  SDF_VU0__STOREIDENTITY(&aMatrix);
  v22 = 0;
  do
  {
    v23 = 0;
    v53 = v22;
    do
    {
      v24 = il2cp::SizeOf(v8, UnityEngine_Vector4);
      v25 = *v24;
      v26 = v24[1];
      v57 = aMatrix;
      *&p.x = v25;
      *&p.z = v26;
      SDF_VU0__LOADMATRIX(&v57);
      v63.z = z;
      v63.w = w;
      v63.x = x;
      v63.y = y;
      SDF_VU0__LOADVECTOR_B(v63);
      sub_854930(&v60, 0);
      sub_854930(&v60, 1u);
      sub_854930(&v60, 2u);
      SDF_VU0__LOADVECTOR(v60);
      SDF_VU0__VECTOR_W_SET_ZERO();
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__ADDVECTOR();
      v27 = 0.0;
      v28 = 20;
      do
      {
        SDF_VU0__STOREVECTOR(&p);
        v27 = v27 + 0.31416;
        sdfCos(v27);
        sub_854930(&v60, 0);
        sub_854930(&v60, 1u);
        sdfSin(v27);
        sub_854930(&v60, 2u);
        SDF_VU0__LOADVECTOR(v60);
        SDF_VU0__VECTOR_W_SET_ZERO();
        SDF_VU0__APPLYMATRIX();
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&p);
        --v28;
      }
      while (v28);
      else if (!v8)
      {
        goto LABEL_36;
      }
      Interface = QueryInterface(v8, sbyte);
      if (!Interface)
      {
        sub_8FC2C0(*(*v8 + 64), v31, v61);
        if ((v61[0] & 1) != 0)
          v33 = v62;
        else
          v33 = v61 + 1;
        v34 = sub_8C4940(v33);
      }
LABEL_37:
      v36 = *(Interface + 32);
      v37 = *il2cp::SizeOf(Interface, sbyte) / v36;
      v38 = il2cp::SizeOf(v8, UnityEngine_Vector4);
      v39 = *v38;
      v40 = *(v38 + 4);
      v42 = *(v38 + 8);
      v41 = *(v38 + 12);
      v43 = il2cp::SizeOf(v9, uint);
      v64.x = v39;
      v64.y = v40;
      v64.z = v42;
      v64.w = v41;
      v45 = sdfPrimMake3DLine(v64, *v43, v37, 128);
      sdfDrawTagLink(v15, v45);
    }
    while (v23++ < 0xD);
    SetRotateMatrixX(1.5708);
    v56 = aMatrix;
    SDF_VU0__LOADMATRIX_B(&v56);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(&aMatrix);
    v22 = 1;
  }
  while (!v53);
  v52 = dds3Ot->m_Items[44];
  sdfDrawTagLinkOt(v52, v15);
}

// 0x1387620
effPCP_ThunderPoly_t *effPCP_ThunderPolyCreate(effPCP_ThunderPolyParam_t *pParam) {
  return 0;
}

// 0x1387580
void effPkt3DPrimLinkPoly(sdfDrawTag_t *pTag, sdf3DPrimPolyParm_t *pParam) {
  ;
}

// 0x1387420
s32 mdlFileLoad(s32 major, s32 minor, u32 regFlags, char *filename, void *callback, void *parm) {
  return 0;
}

// 0x13875e0
dds3ModelHandle_t *mdlLoad(u32 aMajor, u32 aMinor) {
  return 0;
}

// 0x1387610
sdf3DFogParam_t *pbInitMain_fogparam(f32 a, f32 b, f32 c, f32 d, s32 e) {
  return 0;
}

// 0x13875f0
dds3ProcessID_t *scrStartScript2(s32 a, void *b, s32 c) {
  return 0;
}

// 0x1387410
s32 sdfModelGetMarkPos(sdfModelRootNode_t *aRoot, s32 aId) {
  return 0;
}
