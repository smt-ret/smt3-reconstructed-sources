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
    sdfVector4_t effDebugSelectCursorDraw_vertex[UNKNOWN_ARRAY_SIZE];
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
static dds3DrawEnv_t dds3DrawEnv[UNKNOWN_ARRAY_SIZE];
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
    return 0;
}

// 0x1387510
void *dds3PrimLine(s32 aX0, s32 aY0, u32 aZ0, u32 aColor0, s32 aX1, s32 aY1, u32 aZ1, u32 aColor1, s32 aMode) {
    return 0;
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
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x1388500
void effDebugLineDraw2(effDebug *this, sdfVector4_t pPos0, sdfVector4_t pPos1, u32 abgr) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x1387630
void effDebugPointDraw(effDebug *this, sdfVector4_t pPos) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x1387970
void effDebugPointDraw2(effDebug *this, sdfVector4_t pPos, u32 color) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x1389640
void effDebugSelectCursorDraw(effDebug *this, sdfVector4_t pPos) {
  ;
}

// 0x1388d50
void effDebugStringDraw(effDebug *this, s32 x, s32 y, s32 attr, char **pString) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x138a430
void effDebugWindowDraw(effDebug *this, s32 x, s32 y, s32 w, s32 h, s32 bg_c, s32 frame_c) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x1389650
void effDebugWireframeCylinderDraw(effDebug *this, sdfVector4_t pCenter, f32 radius_max, f32 height_max, u32 abgr) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    sdfCos(0);
    sdfSin(0);
    sdfPrimMake3DLine((sdfVector4_t){0}, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
}

// 0x1388fb0
void effDebugWireframeSphereDraw(effDebug *this, sdfVector4_t pCenter, f32 radius_max, u32 abgr) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    SDF_VU0__STOREIDENTITY(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    sdfCos(0);
    sdfSin(0);
    sdfPrimMake3DLine((sdfVector4_t){0}, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    SetRotateMatrixX(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
    sdfDrawTagLinkOt(0, 0);
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
