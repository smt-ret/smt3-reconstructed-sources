#include "types.h"

typedef struct sdfShapeFacePacketIF_t sdfShapeFacePacketIF_t;
typedef struct sdfShape_t sdfShape_t;

void *sdfShapeMakePacketEx2(sdfShape_t *aShape, s32 aMaterialIndex, s32 aExAttr);

// 0x17ab340
void sdfShapeAllocFace(sdfShape_t *aShape) {
  ;
}

// 0x17ab360
void sdfShapeAllocFaceColor(sdfShape_t *aShape) {
  ;
}

// 0x17ab350
void sdfShapeAllocFaceNormal(sdfShape_t *aShape) {
  ;
}

// 0x17ab310
void sdfShapeAllocNormal(sdfShape_t *aShape) {
  ;
}

// 0x17ab320
void sdfShapeAllocUV(sdfShape_t *aShape, s32 aChannel) {
  ;
}

// 0x17ab330
void sdfShapeAllocVertColor(sdfShape_t *aShape) {
  ;
}

// 0x17ab2f0
void sdfShapeAllocVertex(sdfShape_t *aShape) {
  if (!aShape->vertexListHandle)
    aShape->flags |= 1u;
}

// 0x17ab610
void sdfShapeBuildFaceNormal(sdfShape_t *aShape) {
  ;
}

// 0x17ab7d0
void sdfShapeBuildLocalIndexList(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
  aIF->indexCount = 0;
}

// 0x17ab620
void sdfShapeBuildNormal(sdfShape_t *aShape) {
  ;
}

// 0x17ab270
void sdfShapeFree(sdfShape_t *aShape) {
  ;
}

// 0x17ab520
void sdfShapeFreeFace(sdfShape_t *aShape) {
  u64 *v2;

  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
}

// 0x17ab5c0
void sdfShapeFreeFaceColor(sdfShape_t *aShape) {
  u64 *v2;

  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
}

// 0x17ab570
void sdfShapeFreeFaceNormal(sdfShape_t *aShape) {
  u64 *v2;

  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
}

// 0x17ab3c0
void sdfShapeFreeNormal(sdfShape_t *aShape) {
  u64 *v2;

  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
}

// 0x17aba00
void sdfShapeFreePacket(void *aPacket) {
  ;
}

// 0x17ab410
void sdfShapeFreeUV(sdfShape_t *aShape, s32 aChannel) {
  u64 *v5;
  struct sdfMemHandle_t_array *uvListHandles;
  struct sdfMemHandle_t_array *v8;

  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  uvListHandles = aShape->uvListHandles;
  if (uvListHandles->m_Items[aChannel])
  {
    v8 = aShape->uvListHandles;
    v8->m_Items[aChannel] = 0;
  }
}

// 0x17ab4d0
void sdfShapeFreeVertColor(sdfShape_t *aShape) {
  u64 *v2;

  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
}

// 0x17ab370
void sdfShapeFreeVertex(sdfShape_t *aShape) {
  u64 *v2;

  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
}

// 0x17ab9a0
void *sdfShapeMakePacket(sdfShape_t *aShape) {
    return 0;
}

// 0x17ab860
void sdfShapeMakePacketAlign16(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
  ;
}

// 0x17ab870
void sdfShapeMakePacketClose(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
}

// 0x17abc30
void *sdfShapeMakePacketEx(sdfShape_t *aShape, s32 aMaterialIndex) {
  return sdfShapeMakePacketEx2(aShape, aMaterialIndex);
}

// 0x17aba10
void *sdfShapeMakePacketEx2(sdfShape_t *aShape, s32 aMaterialIndex, s32 aExAttr) {
  Il2CppObject *v4;
  u64 *v5;
  Il2CppObject *v6;

  v4 = Allocate(sdfShapeFacePacketIF_t);
  v4[1].klass = NewSpecific(s32, 0x30u);
  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  v4[3].klass = v5;
  _ctor(v4, 0);
  v6 = Allocate(sdfShapeClass);
  v6[2].klass = NewSpecific(s32, 2u);
  v6[3].monitor = NewSpecific(s32, 1u);
  _ctor(v6, 0);
  return v6;
}

// 0x17ab7f0
void sdfShapeMakePacketFace(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
  ;
}

// 0x17ab850
void sdfShapeMakePacketFooter(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
  ;
}

// 0x17ab7e0
void sdfShapeMakePacketHeader(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
  ;
}

// 0x17ab830
void sdfShapeMakePacketMultiUV(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF, s32 aCh0, s32 aCh1) {
  ;
}

// 0x17ab810
void sdfShapeMakePacketNormal(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
  ;
}

// 0x17ab820
void sdfShapeMakePacketUV(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF, s32 aChannel) {
  ;
}

// 0x17ab840
void sdfShapeMakePacketVertColor(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
  ;
}

// 0x17ab800
void sdfShapeMakePacketVertex(sdfShape_t *aShape, sdfShapeFacePacketIF_t *aIF) {
  ;
}

// 0x17abc40
void sdfShapeMakeRefPacket(void *aRefPacket, void *aShapePacket) {
  ;
}

// 0x17ab280
sdfShape_t *sdfShapeNewTriangleIndex(s32 aVertexCount, s32 aFaceCount) {
  sdfShape_t_o *v5;

  v5 = Allocate(sdfShape_t);
  sdfShape_t___ctor(v5);
  v5->vertexCount = aVertexCount;
  v5->faceCount = aFaceCount;
  return v5;
}

// 0x17ab6e0
s32 sdfShapeRegistLocalIndex(sdfShapeFacePacketIF_t *aIF, s32 aVertNum) {
  s32 indexCount;
  signed s32 v4;
  struct System_Int32_array *v5;
  u32 v6;
  s32 v8;
  u32 v9;
  struct System_Int32_array *index;

  indexCount = aIF->indexCount;
  if (indexCount < 1)
  {
    v6 = -1;
    index = aIF->index;
    v6 = ~v6;
    index->m_Items[v6] = aVertNum;
    ++aIF->indexCount;
    return v6;
  }
  v4 = 0;
  while (1)
  {
    v5 = aIF->index;
    v6 = (indexCount + v4) >> 1;
    v8 = v5->m_Items[(indexCount + v4) >> 1];
    if (v8 == aVertNum)
      break;
    if (v8 < aVertNum)
      v4 = v6 + 1;
    else
      indexCount = (indexCount + v4) >> 1;
    if (indexCount <= v4)
    {
      if (v8 >= aVertNum)
        v9 = v6;
      else
        v9 = v6 + 1;
      v6 = ~v9;
      break;
    }
  }
  if ((v6 & 0x80000000) != 0)
  return v6;
}

// 0x17ab630
s32 sdfShapeSearchLocalIndex(sdfShapeFacePacketIF_t *aIF, s32 aVertNum) {
  s32 indexCount;
  s32 v4;
  struct System_Int32_array *index;
  u32 v6;
  s32 v8;
  u32 v9;

  indexCount = aIF->indexCount;
  if (indexCount < 1)
    return -1;
  v4 = 0;
  while (1)
  {
    index = aIF->index;
    v6 = (v4 + indexCount) >> 1;
    v8 = index->m_Items[(v4 + indexCount) >> 1];
    if (v8 == aVertNum)
      break;
    if (v8 < aVertNum)
      v4 = v6 + 1;
    else
      indexCount = (v4 + indexCount) >> 1;
    if (indexCount <= v4)
    {
      if (v8 >= aVertNum)
        v9 = v6;
      else
        v9 = v6 + 1;
      return ~v9;
    }
  }
  return v6;
}
