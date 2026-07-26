#include "types.h"

typedef struct ModelHD ModelHD;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelExtraChunkMarkPos_t sdfModelExtraChunkMarkPos_t;
typedef struct sdfModelExtraChunk_t sdfModelExtraChunk_t;
typedef struct sdfModelNodeDef_t sdfModelNodeDef_t;
typedef struct sdfModelNode_t sdfModelNode_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;

static u32 SDF_CC_NDNM;
static u32 SDF_CC_MPOS;
static sdfQuaternion_t mod_quat;
static sdfMatrix4_t mod_matrix;
static sdfVector3_t mod_vertex;
static sdfMatrix4_t mod_v_matrix;
static sdfVector3_t mod_pos;
static sdfMatrix4_t mod_p_matrix;
static char *sdfModelGetNodeName_no_name_strUnity;

u32 Byte2UInt32(u8 **bytedata, s32 pos);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
s32 GetMPosCount(ModelHD *this);
sdfModelExtraChunkMarkPos_t *GetMPosData(ModelHD *this, s32 id);
void MultMatrixRev(sdfMatrix4_t *aMatrix);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOAD_ROW3(sdfVector4_t p);
void SDF_VU0__NEGVECTOR_XYZ(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__SETSCALE1VECTOR(void);
void SDF_VU0__SET_ROW0(void);
void SDF_VU0__SET_ROW1(void);
void SDF_VU0__SET_ROW2(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREIDENTITYVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetMPosCount(ModelHD *this, s32 count);
void SetMPosData(ModelHD *this, s32 index, sdfModelExtraChunkMarkPos_t *data);
void ToMatrix(void);
void sdfModelDef_t__bCopy(sdfModelDef_t *this, u8 **bytedata, s32 *bPos);
s32 sdfModelExtraChunkMarkPos_t__GetId(sdfModelExtraChunkMarkPos_t *this, u8 **bytedata, s32 bPos);
void sdfModelExtraChunkMarkPos_t__bCopy(sdfModelExtraChunkMarkPos_t *this, u8 **bytedata, s32 *bPos);
s32 sdfModelExtraChunk_t__GetSize(sdfModelExtraChunk_t *this);
void sdfModelExtraChunk_t__bCopy(sdfModelExtraChunk_t *this, u8 **bytedata, s32 *bPos);
sdfModelExtraChunk_t *sdfModelGetExtraChunkUnity(sdfModelRootNode_t *aRoot, u32 aChunkId);
void *sdfModelGetGameObject_24769808(sdfModelRootNode_t *aRoot, sdfModelExtraChunkMarkPos_t *aMark);
char *sdfModelGetNodeNameUnity(sdfModelRootNode_t *aRoot, s32 aIndex);
sdfMatrix4_t *sdfModelGetNodeTm(void *retstr, void *aObject);
s32 sdfModelMakeMarkPosMatrixUnity(sdfModelRootNode_t **aRoot, sdfModelExtraChunkMarkPos_t *aMark);
s32 sdfModelMakeMarkPosUnity(sdfModelRootNode_t **aRoot, sdfModelExtraChunkMarkPos_t *aMark);
sdfModelRootNode_t *sdfModelMakeRootUnity(sdfModelTexList_t *aTexList, u8 **bytedata, s32 bPos);
void sdfModelNodeAddUnity(sdfModelRootNode_t **aRoot, sdfModelNode_t **aParent, sdfModelNode_t **aNode);
void sdfModelNodeBaseSetUnity(sdfModelNode_t **aNode, sdfModelNodeDef_t *aDef);
void sdfModelNodeDef_t__bCopy(sdfModelNodeDef_t *this, u8 **bytedata, s32 *bPos);
sdfModelNode_t *sdfModelNodeNewUnity(void);
void sdfModelNodeSetParentUnity(sdfModelNode_t **aNode, sdfModelNode_t **aParent);
void sdfModelNodeSetUnity(sdfModelNode_t **aNode, sdfModelNodeDef_t *aDef);
sdfModelRootNode_t *sdfModelRootNewUnity(void);
sdfModelExtraChunk_t *sdfModelSearchExtraChunkUnity(u8 **bData, u32 aChunkId);
sdfModelExtraChunkMarkPos_t *sdfModelSearchMarkPosDataUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x179d2f0
void sdfModelAllocNodeListUnity(sdfModelRootNode_t **aRoot, s32 aLeng) {
  struct sdfModelNodeList_t_o *nodeList;

  nodeList = (*aRoot)->nodeList;
  nodeList->items = NewSpecific(sdfModelNode_t, aLeng);
  (*aRoot)->nodeList->capacity = aLeng;
  (*aRoot)->nodeList->count = 0;
}

// 0x179e7b0
sdfModelExtraChunk_t *sdfModelGetExtraChunkUnity(sdfModelRootNode_t *aRoot, u32 aChunkId) {
    sdfModelSearchExtraChunkUnity(0, 0);
    return 0;
}

// 0x179fa40
void *sdfModelGetGameObject(sdfModelRootNode_t *aRoot, s32 aId) {
  sdfModelExtraChunkMarkPos_t_o *v5;

  v5 = sdfModelSearchMarkPosDataUnity(aRoot, aId);
  return sdfModelGetGameObject_24769808(aRoot, v5);
}

// 0x179f510
void *sdfModelGetGameObject_24769808(sdfModelRootNode_t *aRoot, sdfModelExtraChunkMarkPos_t *aMark) {
    sdfModelGetNodeNameUnity(0, 0);
    return 0;
}

// 0x179ec70
s32 sdfModelGetMarkPosCountUnity(sdfModelRootNode_t *aRoot) {
  UnityEngine_Object_o *modelobj;
  Il2CppObject *Component_object;
  s32 MPosCount;
  sdfModelExtraChunk_t_o *ExtraChunkUnity;
  u32 size;

  if (!aRoot)
    return 0;
  modelobj = aRoot->modelobj;
  if (op_Inequality(modelobj, 0, 0))
  {
    Component_object = GetComponent_object_(aRoot->modelobj);
    if (op_Inequality(Component_object, 0, 0))
    {
      MPosCount = GetMPosCount(Component_object);
      if ((MPosCount & 0x80000000) == 0)
        return MPosCount;
    }
  }
  else
  {
    Component_object = 0;
  }
  MPosCount = 0;
  ExtraChunkUnity = sdfModelGetExtraChunkUnity(aRoot, SDF_CC_MPOS);
  if (ExtraChunkUnity)
  {
    size = ExtraChunkUnity->size;
    MPosCount = (size - sdfModelExtraChunk_t__GetSize(ExtraChunkUnity)) / 64;
    if (op_Inequality(Component_object, 0, 0))
      SetMPosCount(Component_object, MPosCount);
  }
  return MPosCount;
}

// 0x179f0f0
s32 sdfModelGetMarkPosMatrixUnity(sdfModelRootNode_t *aRoot, s32 aId) {
  sdfModelExtraChunkMarkPos_t_o *v5;
  sdfModelRootNode_t_o *aRoota;

  aRoota = aRoot;
  v5 = sdfModelSearchMarkPosDataUnity(aRoot, aId);
  return sdfModelMakeMarkPosMatrixUnity(&aRoota, v5);
}

// 0x179f810
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId) {
  sdfModelExtraChunkMarkPos_t_o *v5;
  sdfModelRootNode_t_o *aRoota;

  aRoota = aRoot;
  v5 = sdfModelSearchMarkPosDataUnity(aRoot, aId);
  return sdfModelMakeMarkPosUnity(&aRoota, v5);
}

// 0x179e8d0
char *sdfModelGetNodeNameUnity(sdfModelRootNode_t *aRoot, s32 aIndex) {
    sdfModelGetExtraChunkUnity(0, 0);
    return 0;
}

// 0x179e500
sdfMatrix4_t *sdfModelGetNodeTm(void *retstr, void *aObject) {
    return 0;
}

// 0x179d6d0
void sdfModelLinkDrawPacketUnity(sdfModelNode_t **aNode, void *aShape, s32 aOtIndex, s32 aIndexFrom, s32 aId) {
  ;
}

// 0x179d6e0
void sdfModelMakeLocalTmUnity(sdfModelNode_t **aNode) {
  SDF_VU0__LOADVECTOR((*aNode)->rotate, 0);
  ToMatrix();
  SDF_VU0__LOAD_ROW3((*aNode)->pos, 0);
  SDF_VU0__STOREMATRIX(&(*aNode)->localNoScaledTm, 0);
}

// 0x179f180
s32 sdfModelMakeMarkPosMatrixUnity(sdfModelRootNode_t **aRoot, sdfModelExtraChunkMarkPos_t *aMark) {
    sdfModelGetGameObject_24769808(0, 0);
    sdfModelGetNodeTm(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SET_ROW2();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__NEGVECTOR_XYZ();
    SDF_VU0__SET_ROW1();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SET_ROW0();
    SDF_VU0__LOAD_ROW3((sdfVector4_t){0});
    MultMatrixRev(0);
    return 0;
}

// 0x179f8a0
s32 sdfModelMakeMarkPosUnity(sdfModelRootNode_t **aRoot, sdfModelExtraChunkMarkPos_t *aMark) {
    sdfModelGetGameObject_24769808(0, 0);
    sdfModelGetNodeTm(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    return 0;
}

// 0x179def0
sdfModelRootNode_t *sdfModelMakeRootUnity(sdfModelTexList_t *aTexList, u8 **bytedata, s32 bPos) {
  sdfModelDef_t_o *v7;
  sdfModelNodeDef_t_o *v8;
  sdfModelRootNode_t_o *v11;
  sdfModelRootNode_t_o *v13;
  s32 modelDef;
  u32 v15;
  struct sdfModelNodeList_t_o *nodeList;
  s64 parentIndex;
  sdfModelNode_t_o *v22;
  struct sdfModelNode_t_array *items;
  s32 v27;
  sdfModelNode_t_o *aParent;
  sdfModelNode_t_o *aNode;
  sdfModelRootNode_t_o *aRoot;
  s32 bPosa;

  bPosa = bPos;
  aNode = 0;
  aRoot = 0;
  aParent = 0;
  v27 = 0;
  v7 = Allocate(sdfModelDef_t);
  sdfModelDef_t___ctor(v7);
  sdfModelDef_t__bCopy(v7, bytedata, &bPosa);
  v8 = Allocate(sdfModelNodeDef_t);
  sdfModelNodeDef_t___ctor(v8);
  v11 = sdfModelRootNewUnity();
  aRoot = v11;
  v11->texList = aTexList;
  v11->matList = 0;
  v13 = v11;
  v11->extraData = v7->extraData;
  modelDef = v7->modelDef;
  v15 = Byte2UInt32(bytedata, modelDef + bPos);
  nodeList = v13->nodeList;
  nodeList->items = NewSpecific(sdfModelNode_t, v15);
  v13->nodeList->capacity = v15;
  v13->nodeList->count = 0;
  v27 = bPos + 32;
  if (v15)
  {
    while (1)
    {
      sdfModelNodeDef_t__bCopy(v8, bytedata, &v27);
      aNode = sdfModelNodeNewUnity();
      parentIndex = v8->parentIndex;
      v22 = aNode;
      if ((parentIndex & 0x80000000) == 0)
        break;
      aParent = 0;
      sdfModelNodeAddUnity(&aRoot, &aParent, &aNode);
      --v15;
      v22->id = v8->id;
      if (!v15)
        return v13;
    }
    items = v13->nodeList->items;
    aParent = items->m_Items[parentIndex];
  }
  return v13;
}

// 0x179e150
sdfModelRootNode_t *sdfModelMakeUnity(sdfModelTexList_t *aTexList, u8 **bData, s32 bPos) {
  u32 v7;
  s32 v8;
  s32 v9;
  sdfModelRootNode_t_o *RootUnity;
  sdfModelDef_t_o *v12;
  u64 *v13;
  s32 modelDef;
  u32 v18;
  u64 v19;
  s64 v20;
  struct sdfModelNode_t_array *items;
  sdfModelNode_t_o *aNode;
  s32 v26;
  s32 bPosa;

  bPosa = bPos;
  aNode = 0;
  v26 = 0;
  if (!bData)
    return 0;
  v7 = (bPos + 15) & 0xFFFFFFF0;
  if ((v7 | 8) >= SLODWORD(bData->max_length))
  {
    bPosa = -1;
    Log(StringLiteral_22012, 0);
    return 0;
  }
  v8 = v7 + 32;
  while (1)
  {
    if (ToUInt32(bData, v8 - 24, 0) == 808469581)
      break;
    v9 = v8 - 8;
    v8 += 16;
    if (v9 >= SLODWORD(bData->max_length))
  }
  bPosa = v8 - 32;
  if (v8 - 32 < 0)
  bPosa = v8;
  v12 = Allocate(sdfModelDef_t);
  sdfModelDef_t___ctor(v12);
  sdfModelDef_t__bCopy(v12, bData, &bPosa);
  v13 = Allocate(sdfModelNodeDef_t);
  sdfModelNodeDef_t___ctor(v13);
  RootUnity = sdfModelMakeRootUnity(aTexList, bData, v8);
  modelDef = v12->modelDef;
  v18 = Byte2UInt32(bData, modelDef + v8);
  v26 = v8 + 32;
  if (v18)
  {
    v19 = 0;
    v20 = v18;
    do
    {
      sdfModelNodeDef_t__bCopy(v13, bData, &v26);
      items = RootUnity->nodeList->items;
      aNode = items->m_Items[v19];
      sdfModelNodeSetUnity(&aNode, v13);
      ++v19;
    }
    while (v20 != v19);
  }
  return RootUnity;
}

// 0x179d380
void sdfModelNodeAddUnity(sdfModelRootNode_t **aRoot, sdfModelNode_t **aParent, sdfModelNode_t **aNode) {
  struct sdfModelNodeList_t_o *nodeList;
  s64 count;
  struct sdfModelNode_t_array *items;
  sdfModelNode_t_o *v10;

  nodeList = (*aRoot)->nodeList;
  count = nodeList->count;
  nodeList->count = count + 1;
  items = (*aRoot)->nodeList->items;
  v10 = *aNode;
  items->m_Items[count] = v10;
  (*aNode)->root = *aRoot;
  sdfModelNodeSetParentUnity(aNode, aParent, aNode);
}

// 0x179d740
void sdfModelNodeBaseSetUnity(sdfModelNode_t **aNode, sdfModelNodeDef_t *aDef) {
    FromEuler(0, 0, 0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__LOAD_ROW3((sdfVector4_t){0});
    SDF_VU0__STOREMATRIX(0);
}

// 0x179d180
sdfModelNode_t *sdfModelNodeNewUnity(void) {
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

// 0x179d490
void sdfModelNodeSetParentUnity(sdfModelNode_t **aNode, sdfModelNode_t **aParent) {
}

// 0x179dc20
void sdfModelNodeSetUnity(sdfModelNode_t **aNode, sdfModelNodeDef_t *aDef) {
    sdfModelNodeBaseSetUnity(0, 0);
}

// 0x179d640
void sdfModelNodeUnlinkUnity(sdfModelNode_t **aNode) {
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

// 0x179d230
sdfModelRootNode_t *sdfModelRootNewUnity(void) {
  sdfModelRootNode_t_o *v1;
  u64 *v2;

  v1 = Allocate(sdfModelRootNode_t);
  sdfModelRootNode_t___ctor(v1);
  v2 = Allocate(sdfModelNodeList_t);
  sdfModelNodeList_t___ctor(v2);
  v1->nodeList = v2;
  SDF_VU0__STOREIDENTITY(&v1->tm);
  SDF_VU0__STOREIDENTITYVECTOR(&v1->rotate);
  SDF_VU0__SETSCALE1VECTOR();
  SDF_VU0__STOREVECTOR(&v1->scale);
  v1->color = -2139062144;
  v1->drawAttr = -1;
  return v1;
}

// 0x179e6d0
sdfModelExtraChunk_t *sdfModelSearchExtraChunkUnity(u8 **bData, u32 aChunkId) {
  sdfModelExtraChunk_t_o *v5;
  u32 chunkId;
  s32 v7;
  s32 bPos;

  bPos = 0;
  if (!bData)
    return 0;
  v5 = Allocate(sdfModelExtraChunk_t);
  sdfModelExtraChunk_t___ctor(v5);
  bPos = 0;
  sdfModelExtraChunk_t__bCopy(v5, bData, &bPos);
  chunkId = v5->chunkId;
  if (!chunkId)
    return 0;
  v7 = 0;
  while (chunkId != aChunkId)
  {
    v7 += v5->size;
    if (v7 < SLODWORD(bData->max_length))
    {
      bPos = v7;
      sdfModelExtraChunk_t__bCopy(v5, bData, &bPos);
      chunkId = v5->chunkId;
      if (chunkId)
        continue;
    }
    return 0;
  }
  return v5;
}

// 0x179ee00
sdfModelExtraChunkMarkPos_t *sdfModelSearchMarkPosDataUnity(sdfModelRootNode_t *aRoot, s32 aId) {
    GetMPosData(0, 0);
    sdfModelGetExtraChunkUnity(0, 0);
    sdfModelExtraChunk_t__GetSize(0);
    sdfModelExtraChunkMarkPos_t__GetId(0, 0, 0);
    sdfModelExtraChunkMarkPos_t__bCopy(0, 0, 0);
    SetMPosCount(0, 0);
    SetMPosData(0, 0, 0);
    return 0;
}
