#include "types.h"

typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;

static sdfVector4_t sdfGeomObjBox_norm[6];

// 0x17eebf0
void *sdfGeomObjBox(s32 aMatIndex, s32 aFlags, f32 aX, f32 aY, f32 aZ, s32 aSectX, s32 aSectY, s32 aSectZ) {
  return 0;
}

// 0x17eeb80
sdfModelRootNode_t *sdfGeomObjMakeModel(void *aPacket, sdfModelTexList_t *aTexList) {
  return 0;
}

// 0x17eebe0
sdfIVector4_t *sdfGeomObjPlateFace(sdfIVector4_t *facePtr, s32 pointNum, s32 w, s32 h) {
  return facePtr;
}

// 0x17eebd0
sdfVector4_t sdfGeomObjPlateNormal(sdfVector4_t normPtr, sdfVector4_t src, s32 pointCount) {
  return normPtr;
}

// 0x17eeba0
sdfVector4_t sdfGeomObjPlateVertexXY(sdfVector4_t vertPtr, f32 aX, f32 aY, f32 aZ, s32 aSectX, s32 aSectY) {
  return vertPtr;
}

// 0x17eebb0
sdfVector4_t sdfGeomObjPlateVertexXZ(sdfVector4_t vertPtr, f32 aX, f32 aY, f32 aZ, s32 aSectX, s32 aSectZ) {
  return vertPtr;
}

// 0x17eebc0
sdfVector4_t sdfGeomObjPlateVertexYZ(sdfVector4_t vertPtr, f32 aX, f32 aY, f32 aZ, s32 aSectY, s32 aSectZ) {
  return vertPtr;
}

// 0x17eeb90
void *sdfGeomObjSphere(s32 aMatIndex, s32 aFlags, f32 aRadiusH, f32 aRadiusV, s32 aSectH, s32 aSectV) {
  return 0;
}
