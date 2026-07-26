#include "types.h"

typedef struct sdf3DTmPacketData_t sdf3DTmPacketData_t;
typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;
typedef struct sdfDmaTag_t sdfDmaTag_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfMatDef_t sdfMatDef_t;
typedef struct sdfMatList_t sdfMatList_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelDrawEnv_t sdfModelDrawEnv_t;
typedef struct sdfModelExtraChunkMarkPos_t sdfModelExtraChunkMarkPos_t;
typedef struct sdfModelExtraChunk_t sdfModelExtraChunk_t;
typedef struct sdfModelMorphList_t sdfModelMorphList_t;
typedef struct sdfModelNodeDef_t sdfModelNodeDef_t;
typedef struct sdfModelNodeList_t sdfModelNodeList_t;
typedef struct sdfModelNode_t sdfModelNode_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelPacketHeader_tag sdfModelPacketHeader_tag;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfModel_sdfModelClass sdfModel_sdfModelClass;
typedef struct sdfModel_sdfModelClass2 sdfModel_sdfModelClass2;

struct sdfModel_sdfModelClass {
    sdfDmaTag_t *dmatag;
    f32 blendRate[2];
    u32 itop;
    u32 mscal;
    u32 pad[UNKNOWN_ARRAY_SIZE];
};

struct sdfModel_sdfModelClass2 {
    sdfDmaTag_t *tmDmaTag;
    sdf3DTmPacketData_t *tmPacket;
    sdfDmaTag_t *linktag;
    u32 cmd[8];
};

static sdfDelayedResrcCB_t *sdfModelDelayedResrcCB;
static u8 sdfFaceDivMode;

u32 Byte2UInt32(u8 **bytedata, s32 pos);
void MultMatrixRevNoArg(void);
void SDF_VU0__APPLYMATRIX_XYZ1(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOAD_ROW0(sdfVector4_t p);
void SDF_VU0__LOAD_ROW1(sdfVector4_t p);
void SDF_VU0__LOAD_ROW2(sdfVector4_t p);
void SDF_VU0__LOAD_ROW3(sdfVector4_t p);
void SDF_VU0__SCALE_XYZ(void);
void SDF_VU0__SCALE_XYZ_REV(void);
void SDF_VU0__SETSCALE1VECTOR(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREIDENTITYVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void ToMatrix(void);
void sdf3DPrimSetTmPacket(void *aPacket);
void sdfItemArrayGrow_sdfModelNodeList(sdfModelNodeList_t *aArray);
void sdfItemArraySetCapacity_sdfModelNodeList(sdfModelNodeList_t *aArray, s32 aCapa);
sdfMatList_t *sdfMatListMake(sdfModelTexList_t *aTexList, s32 setCount, sdfMatDef_t *aData);
sdf3DTmPacketData_t *sdfModelAllocTmPacket(sdfModelNode_t **aNode);
void sdfModelEvalNode(sdfModelNode_t **aNode, sdfMatrix4_t *aParentTm, s32 aFrameId);
void sdfModelEvalTm2(sdfModelRootNode_t **aRoot, s32 aFrameId);
sdfModelRootNode_t *sdfModelMakeRoot(sdfModelTexList_t *aTexList, sdfModelDef_t *aModelData);
void sdfModelNodeAdd(sdfModelRootNode_t **aRoot, sdfModelNode_t **aParent, sdfModelNode_t **aNode);
sdfModelNode_t *sdfModelNodeNew(void);
void sdfModelNodeSetParent(sdfModelNode_t **aNode, sdfModelNode_t **aParent);
sdfModelRootNode_t *sdfModelRootNew(void);

// 0x179b8d0
s32 SDF_FOURCC(s32 a, s32 b, s32 c, s32 d) {
  return a | (b << 8) | (c << 16) & 0xFFFFFF | (d << 24);
}

// 0x179bc50
void sdfModelAllocNodeList(sdfModelRootNode_t **aRoot, s32 aLeng) {
  sdfItemArraySetCapacity_sdfModelNodeList((*aRoot)->nodeList, aLeng);
}

// 0x179b9b0
sdf3DTmPacketData_t *sdfModelAllocTmPacket(sdfModelNode_t **aNode) {
    return 0;
}

// 0x179cc30
s32 sdfModelCheckBounds(f32 aMinMax) {
  return 0;
}

// 0x179cc70
void sdfModelCopyStat(sdfModelRootNode_t **aDstRoot, sdfModelRootNode_t **aSrcRoot) {
  ;
}

// 0x179cc90
void sdfModelDrawEnvLinkOt(sdfModelOt_t **aOt, sdfModelDrawEnv_t **aEnv) {
  ;
}

// 0x179c7d0
void sdfModelEvalNode(sdfModelNode_t **aNode, sdfMatrix4_t *aParentTm, s32 aFrameId) {
    SDF_VU0__LOAD_ROW0((sdfVector4_t){0});
    SDF_VU0__LOAD_ROW1((sdfVector4_t){0});
    SDF_VU0__LOAD_ROW2((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SCALE_XYZ();
    SDF_VU0__LOAD_ROW3((sdfVector4_t){0});
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixRevNoArg();
    SDF_VU0__STOREMATRIX(0);
    sdf3DPrimSetTmPacket(0);
}

// 0x179cb80
void sdfModelEvalTm(sdfModelRootNode_t **aRoot) {
  s32 sdfFrameId;

  sdfModelEvalTm2(aRoot, sdfFrameId);
}

// 0x179ca50
void sdfModelEvalTm2(sdfModelRootNode_t **aRoot, s32 aFrameId) {
  u64 *v5;
  sdfModelRootNode_t_o *v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  UnityEngine_Matrix4x4_o *v14;
  struct sdfModelNodeList_t_o *nodeList;
  struct sdfModelNode_t_array *items;
  UnityEngine_Matrix4x4_o v20;
  sdfModelNode_t_o *aNode;

  aNode = 0;
  v5 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v5);
  v6 = *aRoot;
  v7 = *&(*aRoot)->tm.m00;
  v8 = *&(*aRoot)->tm.m20;
  v9 = *&(*aRoot)->tm.m21;
  *&v20.m01 = *&(*aRoot)->tm.m01;
  *&v20.m21 = v9;
  *&v20.m00 = v7;
  *&v20.m20 = v8;
  v10 = *&v6->tm.m02;
  v11 = *&v6->tm.m22;
  v13 = *&v6->tm.m03;
  v12 = *&v6->tm.m23;
  *&v20.m03 = v13;
  *&v20.m23 = v12;
  *&v20.m02 = v10;
  *&v20.m22 = v11;
  SDF_VU0__LOADMATRIX(&v20);
  SDF_VU0__LOADVECTOR((*aRoot)->scale, 0);
  SDF_VU0__SCALE_XYZ_REV();
  v14 = (v5 + 2);
  SDF_VU0__STOREMATRIX(v14);
  nodeList = (*aRoot)->nodeList;
  if (nodeList)
  {
    items = nodeList->items;
    aNode = items->m_Items[0];
    sdfModelEvalNode(&aNode, v14, aFrameId);
  }
}

// 0x179c1a0
s32 sdfModelGetDrawPacketSize(void *aList, s32 aShapeCount, s32 *aExtSize) {
  return 0;
}

// 0x179ccb0
sdfModelExtraChunk_t *sdfModelGetExtraChunk(sdfModelRootNode_t **aRoot, u32 aChunkId) {
  return 0;
}

// 0x179ccc0
s32 sdfModelGetExtraChunkBytePos(u8 **bData, u32 aChunkId) {
  s32 v5;

  v5 = 0;
  do
  {
    if (Byte2UInt32(bData, v5) == aChunkId)
      break;
    v5 += 4;
  }
  while (v5 < SLODWORD(bData->max_length));
  return v5;
}

// 0x179cfb0
f32 sdfModelGetFaceDivBias(sdfModelRootNode_t **aRoot) {
  return 0.0;
}

// 0x179cfa0
f32 sdfModelGetFaceDivSoften(sdfModelRootNode_t **aRoot) {
  return 0.0;
}

// 0x179cf00
s32 sdfModelGetMarkPos(sdfModelRootNode_t **aRoot, s32 aId) {
    return 0;
  return 0;
}

// 0x179cd80
s32 sdfModelGetMarkPosCount(sdfModelRootNode_t **aRoot) {
  return 0;
}

// 0x179ce90
s32 sdfModelGetMarkPosMatrix(sdfModelRootNode_t **aRoot, s32 aId) {
    return 0;
  return 0;
}

// 0x179cd60
s32 sdfModelGetNodeIndexByName(sdfModelRootNode_t **aRoot, char *aName) {
  return 0;
}

// 0x179cd70
char *sdfModelGetNodeName(sdfModelRootNode_t **aRoot, s32 aIndex) {
  return 0;
}

// 0x179b8f0
void sdfModelInitSystem(void) {
  ;
}

// 0x179c1f0
void sdfModelLinkDrawPacket(sdfModelNode_t **aNode, void **aShape, s32 aOtIndex, s32 aIndexFrom, s32 aId) {
  ;
}

// 0x179cc50
void sdfModelLinkOt(sdfModelOt_t **aOt, sdfModelRootNode_t **aRoot) {
  ;
}

// 0x179c1d0
void sdfModelLinkShapedDrawPacket(sdfModelNode_t **aNode, void **aDataPtr, sdfDrawTag_t **aDrawTag, s32 aId) {
  ;
}

// 0x179c680
sdfModelRootNode_t *sdfModelMake(sdfModelTexList_t **aTexList, sdfModelDef_t **aModelData) {
  return 0;
}

// 0x179c690
sdfModelRootNode_t *sdfModelMakeEarly(sdfModelTexList_t *aTexList, sdfModelDef_t **aModelData) {
  sdfModelDef_t_o *v7;
  sdfModelRootNode_t_o *Root;
  sdfModelDef_t_o *v10;
  s32 modelDef;
  sdfModelRootNode_t_o *v12;
  struct sdfModelNodeDef_t_array *nodeDef;
  u32 i;

  NewSpecific(sdfModelNodeDef_t, 1u);
  v7 = *aModelData;
  Root = sdfModelMakeRoot(aTexList, v7);
  Root->flags |= 4u;
  v10 = *aModelData;
  modelDef = (*aModelData)->modelDef;
  v12 = Root;
  if (modelDef)
  {
    nodeDef = v10->nodeDef;
    for (i = 0; i != modelDef; ++i)
    {
    }
  }
  return v12;
}

// 0x179c200
void sdfModelMakeLocalTm(sdfModelNode_t **aNode) {
  SDF_VU0__LOADVECTOR((*aNode)->rotate, 0);
  ToMatrix();
  SDF_VU0__LOAD_ROW3((*aNode)->pos, 0);
  SDF_VU0__STOREMATRIX(&(*aNode)->localNoScaledTm, 0);
}

// 0x179cda0
void sdfModelMakeMarkPos(sdfModelRootNode_t **aRoot, sdfModelExtraChunkMarkPos_t **aMark) {
  UnityEngine_Matrix4x4_o v4;

  *&v4.m00 = loc_F8;
  *&v4.m20 = loc_100;
  *&v4.m01 = loc_108;
  *&v4.m21 = loc_110;
  *&v4.m03 = loc_128;
  *&v4.m23 = loc_130;
  *&v4.m02 = loc_118;
  *&v4.m22 = loc_120;
  SDF_VU0__LOADMATRIX(&v4);
  SDF_VU0__LOADVECTOR((*aMark)->pos, 0);
  SDF_VU0__APPLYMATRIX_XYZ1();
}

// 0x179cd90
void sdfModelMakeMarkPosMatrix(sdfModelRootNode_t **aRoot, sdfModelExtraChunkMarkPos_t **aMark) {
  ;
}

// 0x179c460
void sdfModelMakeMorphList(sdfModelRootNode_t *root, s32 morphCount) {
  ;
}

// 0x179bc60
void sdfModelMakeNodeList(sdfModelRootNode_t **aRoot) {
  struct sdfModelNode_t_o *headNode;
  struct sdfModelNode_t_o *parent;

  headNode = (*aRoot)->headNode;
  if (headNode)
  {
    while (1)
    {
      do
      {
        parent = headNode;
        headNode = headNode->children;
      }
      while (headNode);
      while (1)
      {
        headNode = parent->next;
        if (headNode)
          break;
        parent = parent->parent;
        if (!parent)
          return;
      }
    }
  }
}

// 0x179c470
sdfModelRootNode_t *sdfModelMakeRoot(sdfModelTexList_t *aTexList, sdfModelDef_t *aModelData) {
  sdfModelRootNode_t_o *v7;
  s32 count;
  sdfModelRootNode_t_o *v11;
  sdfModelTexList_t_o *v12;
  sdfMatDef_t_o *matDef_New;
  s64 modelDef;
  struct sdfModelNodeDef_t_array *nodeDef;
  u64 v18;
  sdfModelNodeDef_t_o **m_Items;
  sdfModelNode_t_o *v23;
  s64 parentIndex;
  struct sdfModelNode_t_array *items;
  sdfModelNodeDef_t_o *v30;
  sdfModelNode_t_o *v32;
  sdfModelNode_t_o *aNode;
  sdfModelRootNode_t_o *aRoot;

  v32 = 0;
  aNode = 0;
  aRoot = 0;
  NewSpecific(sdfModelNodeDef_t, 1u);
  v7 = sdfModelRootNew();
  aRoot = v7;
  v7->texList = aTexList;
  count = aModelData->count;
  v11 = v7;
  matDef_New = aModelData->matDef_New;
  v11->matList = sdfMatListMake(v12, count, matDef_New);
  v11->extraData = aModelData->extraData;
  modelDef = aModelData->modelDef;
  nodeDef = aModelData->nodeDef;
  sdfItemArraySetCapacity_sdfModelNodeList(v11->nodeList, aModelData->modelDef);
  if (modelDef)
  {
    v18 = 0;
    m_Items = nodeDef->m_Items;
    while (1)
    {
      aNode = sdfModelNodeNew();
      v23 = aNode;
      parentIndex = m_Items[v18]->parentIndex;
      if ((parentIndex & 0x80000000) == 0)
        break;
      v32 = 0;
      sdfModelNodeAdd(&aRoot, &v32, &aNode);
      v30 = m_Items[v18++];
      v23->id = v30->id;
      if (modelDef == v18)
        return v11;
    }
    items = v11->nodeList->items;
    v32 = items->m_Items[parentIndex];
  }
  return v11;
}

// 0x179cc60
void sdfModelMorphListCopyStat(sdfModelMorphList_t *aDst, sdfModelMorphList_t *aSrc) {
  ;
}

// 0x179c1e0
sdfModelPacketHeader_tag *sdfModelNewPacketHeader(sdfModelNode_t **aNode, s32 aOtIndex, s32 aId) {
  return 0;
}

// 0x179bc90
void sdfModelNodeAdd(sdfModelRootNode_t **aRoot, sdfModelNode_t **aParent, sdfModelNode_t **aNode) {
  struct sdfModelNodeList_t_o *nodeList;
  s32 count;
  s64 v9;
  s16 v10;
  struct sdfModelNode_t_array *items;
  sdfModelNode_t_o *v12;

  nodeList = (*aRoot)->nodeList;
  count = nodeList->count;
  v9 = nodeList->count;
  v10 = count + 1;
  if (count >= nodeList->capacity)
  {
    sdfItemArrayGrow_sdfModelNodeList(nodeList, aParent);
    nodeList = (*aRoot)->nodeList;
  }
  nodeList->count = v10;
  items = (*aRoot)->nodeList->items;
  v12 = *aNode;
  items->m_Items[v9] = v12;
  (*aNode)->root = *aRoot;
  sdfModelNodeSetParent(aNode, aParent, aNode);
}

// 0x179c360
void sdfModelNodeBaseSet(sdfModelNode_t **aNode, sdfModelNodeDef_t **aDef) {
  ;
}

// 0x179bac0
void sdfModelNodeFree(sdfModelNode_t **aNode) {
}

// 0x179b900
sdfModelNode_t *sdfModelNodeNew(void) {
  sdfModelNode_t_o *v1;

  v1 = Allocate(sdfModelNode_t);
  sdfModelNode_t___ctor(v1);
  v1->color = -2139062144;
  v1->drawAttr = -1;
  v1->prev = v1;
  v1->next = v1;
  SDF_VU0__STOREIDENTITYVECTOR(&v1->rotate);
  SDF_VU0__STOREIDENTITYVECTOR(&v1->pos);
  SDF_VU0__SETSCALE1VECTOR();
  SDF_VU0__STOREVECTOR(&v1->scale);
  SDF_VU0__STOREIDENTITY(&v1->localNoScaledTm);
  return v1;
}

// 0x179c370
void sdfModelNodeSet(sdfModelNode_t **aNode, sdfModelNodeDef_t **aDef) {
  ;
}

// 0x179bdc0
void sdfModelNodeSetParent(sdfModelNode_t **aNode, sdfModelNode_t **aParent) {
}

// 0x179c380
void sdfModelNodeSetShape(sdfModelNode_t **aNode, void **aData, s32 aType) {
  sdfModel_c *v7;

  sdfModelAllocTmPacket(aNode, aData);
  SDF_VU0__LOADVECTOR((*aNode)->rotate, 0);
  ToMatrix();
  SDF_VU0__LOAD_ROW3((*aNode)->pos, 0);
  SDF_VU0__STOREMATRIX(&(*aNode)->localNoScaledTm, 0);
  {
          v7 = sdfModel,
    {
    }
  }
}

// 0x179bf70
void sdfModelNodeUnlink(sdfModelNode_t **aNode) {
  sdfModelNode_t_o *v2;
  struct sdfModelNode_t_o *parent;
  struct sdfModelNode_t_o *next;
  struct sdfModelNode_t_o *prev;
  struct sdfModelRootNode_t_o *root;

  v2 = *aNode;
  parent = (*aNode)->parent;
  if (parent)
  {
    next = v2->next;
    if (next == v2)
    {
      if (parent->children == v2)
        parent->children = 0;
    }
    else
    {
      prev = v2->prev;
      next->prev = prev;
      prev->next = next;
      if (parent->children == *aNode)
        parent->children = next;
      (*aNode)->prev = *aNode;
      (*aNode)->next = *aNode;
    }
  }
  else
  {
    root = v2->root;
    if (root->headNode == v2)
      root->headNode = 0;
  }
}

// 0x179cc20
void sdfModelOtInit(sdfModelOt_t **aModelOt, sdfGrOt_t *aOt0, sdfGrOt_t *aOt1, sdfGrOt_t *aOt2, sdfGrOt_t *aOt3) {
  ;
}

// 0x179bab0
void sdfModelPacketFree(sdfModelNode_t **aNode) {
  ;
}

// 0x179cf90
void sdfModelResetFaceDivParm(sdfModelRootNode_t **aRoot) {
  ;
}

// 0x179bc40
void sdfModelRootFree(sdfModelRootNode_t **aRoot, s32 aReleaseNodes, s32 aReleaseMatList) {
  ;
}

// 0x179b8e0
void sdfModelRootFreeResrc(sdfModelRootNode_t **aRoot) {
  ;
}

// 0x179bb50
sdfModelRootNode_t *sdfModelRootNew(void) {
  sdfModelRootNode_t_o *v1;
  u64 *v2;

  v1 = Allocate(sdfModelRootNode_t);
  sdfModelRootNode_t___ctor(v1);
  v2 = Allocate(sdfModelNodeList_t);
  sdfModelNodeList_t___ctor(v2);
  v2[2] = 0;
  v2[3] = 0x20000000000000LL;
  v2[4] = 0;
  v1->nodeList = v2;
  SDF_VU0__STOREIDENTITY(&v1->tm);
  SDF_VU0__STOREIDENTITYVECTOR(&v1->rotate);
  SDF_VU0__SETSCALE1VECTOR();
  SDF_VU0__STOREVECTOR(&v1->scale);
  v1->color = -2139062144;
  v1->drawAttr = -1;
  return v1;
}

// 0x179cca0
sdfModelExtraChunk_t *sdfModelSearchExtraChunk(sdfModelExtraChunk_t **p, u32 aChunkId) {
  return 0;
}

// 0x179ce80
sdfModelExtraChunkMarkPos_t *sdfModelSearchMarkPosData(sdfModelRootNode_t **aRoot, s32 aId) {
  return 0;
}

// 0x179c000
sdfModelNode_t *sdfModelSearchNode(sdfModelRootNode_t **aRoot, u32 aId) {
  return 0;
}

// 0x179cc80
void sdfModelSetDrawEnv(sdfModelDrawEnv_t **aEnv) {
  ;
}

// 0x179cf70
void sdfModelSetFaceDivParm(sdfModelRootNode_t **aRoot, f32 aSoften, f32 aBias) {
  (*aRoot)->faceDivSoften = aSoften;
  (*aRoot)->faceDivBias = aBias;
}

// 0x179c190
void *sdfModelSetMatRefPacket(sdfModelRootNode_t **aRoot, s32 aMatIndex, void **aBuffer, s32 aId) {
  return 0;
}

// 0x179c1b0
void *sdfModelSetNormalDrawPacket(sdfModelNode_t **aNode, void *aDataPtr, void **aBuffer, s32 aId) {
  return 0;
}

// 0x179c1c0
void *sdfModelSetOneSkinDrawPacket(sdfModelNode_t **aNode, void *aDataPtr, void **aBuffer, s32 aId) {
  return 0;
}

// 0x179c090
void *sdfModelSetTermPacket(void **aBuffer) {
    return 0;
}

// 0x179c010
void *sdfModelSetTmRefPacket(sdfModelNode_t **aNode, void **aBuffer, s32 aId) {
    return 0;
}

// 0x179cc40
void sdfModelTempPacketLinkOt(sdfModelOt_t ***ot, sdfModelRootNode_t **root) {
  ;
}
