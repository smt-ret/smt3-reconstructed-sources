#include "types.h"

typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfMotGetKeyIf_t sdfMotGetKeyIf_t;
typedef struct sdfMotNodeMatBase_t sdfMotNodeMatBase_t;
typedef struct sdfMotNodeModelBase_t sdfMotNodeModelBase_t;
typedef struct sdfMotNodeMorph_t sdfMotNodeMorph_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct sdfMotionCutChunk_t sdfMotionCutChunk_t;
typedef struct sdfMotionNodeVTBL_t sdfMotionNodeVTBL_t;
typedef struct sdfMotionNode_t sdfMotionNode_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;
typedef struct sdfMotion_sdfMotionNodeGenerator_t sdfMotion_sdfMotionNodeGenerator_t;

static sdfMotion_sdfMotionNodeGenerator_t *sdfMotionMajorDef[3];
static sdfMotion_sdfMotionNodeGenerator_t *sdfMotGenNodeDef[5];
static sdfMotionNodeVTBL_t *sdfMotNodeVTBL_modelLinerPos;
static sdfMotionNodeVTBL_t *sdfMotNodeVTBL_modelLinerRotXYZ;
static sdfMotionNodeVTBL_t *sdfMotNodeVTBL_modelLinerScale;
static sdfMotionNodeVTBL_t *sdfMotNodeVTBL_modelLerpRotQuat;
static sdfMotionNodeVTBL_t *sdfMotNodeVTBL_modelVisible;

s32 SDF_ABORT1(char *a);
void SDF_ASSERT(bool result);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADVECTOR_XYZ(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_XYZ_B(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void sdfMotGenModelInit(sdfMotNodeModelBase_t *aBase, sdfMotionCtrlr_t *aCtrlr, sdfMotionNodeVTBL_t *aVTBL, u32 aNodeId);
void sdfMotGetKey(sdfMotionNode_t *aThis, f32 aFrame, sdfMotGetKeyIf_t **aItf);
void sdfMotionChangeBlend(sdfMotionCtrlr_t *aCtrlr, s32 aCutNum, s32 aType, f32 aPreFrame, f32 aBlendLeng);
void sdfMotionSeek(sdfMotionCtrlr_t *aCtrlr, f32 aFrame);

// 0x17a1ef0
s32 SDF_MOTTYP_GETMINOR(u32 id) {
  return id;
}

// 0x17a13d0
void sdfMotCLBK_Destroy(sdfMotionNode_t *aNode) {
  ;
}

// 0x17a13e0
void sdfMotCLBK_SetCut(sdfMotionNode_t *aNode, sdfMotionCutChunk_t *aTable) {
  aNode->table = aTable;
}

// 0x17a3670
void sdfMotCLBK_matAmbientBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  u64 *v6;
  sdfMotGetKeyIf_t_o *aItf;

  v6 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v6, 0);
  aItf = v6;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a35b0
void sdfMotCLBK_matAmbientInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a35d0
void sdfMotCLBK_matAmbientSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  u64 *v5;
  sdfMotGetKeyIf_t_o *aItf;

  v5 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v5, 0);
  aItf = v5;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3a00
void sdfMotCLBK_matConstantBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  u64 *v6;
  sdfMotGetKeyIf_t_o *aItf;

  v6 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v6, 0);
  aItf = v6;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3940
void sdfMotCLBK_matConstantInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3960
void sdfMotCLBK_matConstantSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  u64 *v5;
  sdfMotGetKeyIf_t_o *aItf;

  v5 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v5, 0);
  aItf = v5;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3510
void sdfMotCLBK_matDiffuseBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  u64 *v6;
  sdfMotGetKeyIf_t_o *aItf;

  v6 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v6, 0);
  aItf = v6;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3450
void sdfMotCLBK_matDiffuseInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3470
void sdfMotCLBK_matDiffuseSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  u64 *v5;
  sdfMotGetKeyIf_t_o *aItf;

  v5 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v5, 0);
  aItf = v5;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3be0
void sdfMotCLBK_matMultiDiffuseBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  u64 *v6;
  sdfMotGetKeyIf_t_o *aItf;

  v6 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v6, 0);
  aItf = v6;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3b20
void sdfMotCLBK_matMultiDiffuseInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3b40
void sdfMotCLBK_matMultiDiffuseSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  u64 *v5;
  sdfMotGetKeyIf_t_o *aItf;

  v5 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v5, 0);
  aItf = v5;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3ea0
void sdfMotCLBK_matMultiUvw2BlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  u64 *v6;
  sdfMotGetKeyIf_t_o *aItf;

  v6 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v6, 0);
  aItf = v6;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3de0
void sdfMotCLBK_matMultiUvw2InitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3e00
void sdfMotCLBK_matMultiUvw2Seek(sdfMotionNode_t *aThis, f32 aFrame) {
  u64 *v5;
  sdfMotGetKeyIf_t_o *aItf;

  v5 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v5, 0);
  aItf = v5;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3b10
void sdfMotCLBK_matMultiUvwBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  ;
}

// 0x17a3ae0
void sdfMotCLBK_matMultiUvwInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3b00
void sdfMotCLBK_matMultiUvwSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  ;
}

// 0x17a38a0
void sdfMotCLBK_matRefMapBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  u64 *v6;
  sdfMotGetKeyIf_t_o *aItf;

  v6 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v6, 0);
  aItf = v6;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3870
void sdfMotCLBK_matRefMapInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3890
void sdfMotCLBK_matRefMapSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  ;
}

// 0x17a37d0
void sdfMotCLBK_matSpecularBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  u64 *v6;
  sdfMotGetKeyIf_t_o *aItf;

  v6 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v6, 0);
  aItf = v6;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3710
void sdfMotCLBK_matSpecularInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3730
void sdfMotCLBK_matSpecularSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  u64 *v5;
  sdfMotGetKeyIf_t_o *aItf;

  v5 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v5, 0);
  aItf = v5;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3d40
void sdfMotCLBK_matUvw2BlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  u64 *v6;
  sdfMotGetKeyIf_t_o *aItf;

  v6 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v6, 0);
  aItf = v6;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3c80
void sdfMotCLBK_matUvw2InitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3ca0
void sdfMotCLBK_matUvw2Seek(sdfMotionNode_t *aThis, f32 aFrame) {
  u64 *v5;
  sdfMotGetKeyIf_t_o *aItf;

  v5 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v5, 0);
  aItf = v5;
  sdfMotGetKey(aThis, aFrame, &aItf);
}

// 0x17a3ad0
void sdfMotCLBK_matUvwBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  ;
}

// 0x17a3aa0
void sdfMotCLBK_matUvwInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3ac0
void sdfMotCLBK_matUvwSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  ;
}

// 0x17a2e50
void sdfMotCLBK_modelLerpRotQuatBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  ;
}

// 0x17a2e40
void sdfMotCLBK_modelLerpRotQuatSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  ;
}

// 0x17a2790
void sdfMotCLBK_modelLinerPosBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  ;
}

// 0x17a24e0
void sdfMotCLBK_modelLinerPosSeek(sdfMotionNode_t *aThis, f32 aFrame) {
    sdfMotGetKey(0, 0, 0);
    SDF_VU0__LOADVECTOR_XYZ((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_XYZ_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x17a28f0
void sdfMotCLBK_modelLinerRotXYZBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  ;
}

// 0x17a28e0
void sdfMotCLBK_modelLinerRotXYZSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  ;
}

// 0x17a2cf0
void sdfMotCLBK_modelLinerScaleBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  ;
}

// 0x17a2a40
void sdfMotCLBK_modelLinerScaleSeek(sdfMotionNode_t *aThis, f32 aFrame) {
    sdfMotGetKey(0, 0, 0);
    SDF_VU0__LOADVECTOR_XYZ((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_XYZ_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x17a20d0
void sdfMotCLBK_modelPosInitBlend(sdfMotionNode_t *aThis) {
}

// 0x17a21c0
void sdfMotCLBK_modelRotInitBlend(sdfMotionNode_t *aThis) {
}

// 0x17a22b0
void sdfMotCLBK_modelScaleInitBlend(sdfMotionNode_t *aThis) {
}

// 0x17a3200
void sdfMotCLBK_modelVisibleBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
    sdfMotGetKey(0, 0, 0);
}

// 0x17a2e60
void sdfMotCLBK_modelVisibleInitBlend(sdfMotionNode_t *aThis) {
}

// 0x17a30a0
void sdfMotCLBK_modelVisibleSeek(sdfMotionNode_t *aThis, f32 aFrame) {
    sdfMotGetKey(0, 0, 0);
}

// 0x17a4040
void sdfMotCLBK_morphBlendSeek(sdfMotionNode_t *aThis, f32 aFrame, f32 aBlendRate) {
  ;
}

// 0x17a3f50
void sdfMotCLBK_morphInitBlend(sdfMotionNode_t *aThis) {
  ;
}

// 0x17a3ff0
void sdfMotCLBK_morphSeek(sdfMotionNode_t *aThis, f32 aFrame) {
  u64 *v3;

  v3 = Allocate(sdfMotGetKeyIf_t);
  _ctor(v3, 0);
}

// 0x17a35c0
sdfMotionNode_t *sdfMotGenMatAmbient(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3950
sdfMotionNode_t *sdfMotGenMatConstant(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3460
sdfMotionNode_t *sdfMotGenMatDiffuse(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a33d0
void sdfMotGenMatInit(sdfMotNodeMatBase_t *aBase, sdfMotionCtrlr_t *aCtrlr, sdfMotionNodeVTBL_t *aVTBL, u32 aNodeId) {
  struct sdfMotionNode_t_o *nodeBase;

  nodeBase = aBase->nodeBase;
  nodeBase->vtbl = aVTBL;
  nodeBase->owner = aCtrlr;
}

// 0x17a3b30
sdfMotionNode_t *sdfMotGenMatMultiDiffuse(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3af0
sdfMotionNode_t *sdfMotGenMatMultiUvw(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3df0
sdfMotionNode_t *sdfMotGenMatMultiUvw2(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3360
sdfMotionNode_t *sdfMotGenMatNode(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
    return 0;
  return 0;
}

// 0x17a3880
sdfMotionNode_t *sdfMotGenMatRefMap(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3720
sdfMotionNode_t *sdfMotGenMatSpecular(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3ab0
sdfMotionNode_t *sdfMotGenMatUvw(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3c90
sdfMotionNode_t *sdfMotGenMatUvw2(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a2000
void sdfMotGenModelInit(sdfMotNodeModelBase_t *aBase, sdfMotionCtrlr_t *aCtrlr, sdfMotionNodeVTBL_t *aVTBL, u32 aNodeId) {
  struct sdfMotionNode_t_o *nodeBase;

  nodeBase = aBase->nodeBase;
  nodeBase->vtbl = aVTBL;
  nodeBase->owner = aCtrlr;
  SDF_ASSERT(0);
  aBase->modelNode = 0;
}

// 0x17a2d00
sdfMotionNode_t *sdfMotGenModelLerpRotQuat(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
    sdfMotGenModelInit(0, 0, 0, 0);
    return 0;
}

// 0x17a23a0
sdfMotionNode_t *sdfMotGenModelLinerPos(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
    sdfMotGenModelInit(0, 0, 0, 0);
    return 0;
}

// 0x17a27a0
sdfMotionNode_t *sdfMotGenModelLinerRotXYZ(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
    sdfMotGenModelInit(0, 0, 0, 0);
    return 0;
}

// 0x17a2900
sdfMotionNode_t *sdfMotGenModelLinerScale(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
    sdfMotGenModelInit(0, 0, 0, 0);
    return 0;
}

// 0x17a2f60
sdfMotionNode_t *sdfMotGenModelVisible(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
    sdfMotGenModelInit(0, 0, 0, 0);
    return 0;
}

// 0x17a3fe0
sdfMotionNode_t *sdfMotGenMorph(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a3f60
void sdfMotGenMorphInit(sdfMotNodeMorph_t *aBase, sdfMotionCtrlr_t *aCtrlr, sdfMotionNodeVTBL_t *aVTBL, u32 aNodeId) {
  struct sdfMotionNode_t_o *nodeBase;

  nodeBase = aBase->nodeBase;
  nodeBase->vtbl = aVTBL;
  nodeBase->owner = aCtrlr;
}

// 0x17a3f40
sdfMotionNode_t *sdfMotGenMorphNode(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  return 0;
}

// 0x17a1f00
sdfMotionNode_t *sdfMotGenNode(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  struct sdfMotion_sdfMotionNodeGenerator_t_array *sdfMotGenNodeDef;
  struct sdfMotion_sdfMotionNodeGenerator_t_array *v10;

  SDF_ASSERT(aTypeId < SLODWORD(sdfMotGenNodeDef->max_length), 0);
  v10 = sdfMotGenNodeDef;
  return Invoke(v10->m_Items[aTypeId], aCtrlr, aTypeId, aNodeId);
}

// 0x17a13f0
void sdfMotGetKey(sdfMotionNode_t *aThis, f32 aFrame, sdfMotGetKeyIf_t **aItf) {
  struct sdfMotionCutChunk_t_o *table;
  struct System_UInt16_array *keyFrameList;
  s32 numOfKey;
  s32 keyElemSize;
  sdfMotGetKeyIf_t_o *v11;
  char *max_length;
  u64 v13;
  u64 v14;
  u16 *m_Items;
  struct System_Byte_array *key_frame;
  struct System_Byte_array *v19;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s64 v26;
  s32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  s32 v32;
  s64 v34;
  u32 v35;
  sdfMotGetKeyIf_t_o *v36;
  s32 frameLength;
  bool v38;
  s32 v39;
  sdfMotGetKeyIf_t_o *v40;
  f32 v41;
  s32 v43;

  table = aThis->table;
  keyFrameList = table->keyFrameList;
  numOfKey = table->numOfKey;
  keyElemSize = table->keyElemSize;
  v11 = *aItf;
  v11->key_frame = NewSpecific(byte, 2 * (keyFrameList->max_length & 0x7FFFFFFF));
  LODWORD(max_length) = keyFrameList->max_length;
  if (max_length >= 1)
  {
    v13 = 0;
    v14 = 0;
    m_Items = keyFrameList->m_Items;
    do
    {
      key_frame = (*aItf)->key_frame;
      key_frame->m_Items[v13 + 1] = HIBYTE(m_Items[v14]);
      v19 = (*aItf)->key_frame;
      max_length = v19 + v13;
      v13 += 2LL;
      max_length[32] = m_Items[v14];
      LODWORD(max_length) = keyFrameList->max_length;
      ++v14;
    }
    while (v14 < max_length);
  }
  v22 = aFrame;
  v23 = 0;
  v24 = numOfKey - 1;
  while (1)
  {
    v25 = v24 + v23 + 1;
    v26 = v25 >> 1;
    v28 = keyFrameList->m_Items[v26];
    if (v22 >= v28)
      v23 = v25 >> 1;
    else
      v24 = v26 - 1;
    if (v23 >= v24)
      break;
    max_length = keyFrameList->max_length;
  }
  if (v22 >= v28)
    v29 = v25 >> 1;
  else
    v29 = v26 - 1;
  v30 = (numOfKey + 1) & 0x1FFFE;
  v31 = v30 + v29 * keyElemSize;
  v32 = 2 * v31;
  (*aItf)->basePtr = 2 * v31;
  v34 = v29 + 1LL;
  v35 = keyFrameList->m_Items[v29];
  if (v34 == numOfKey)
  {
    v36 = *aItf;
    if (aThis->owner->playType)
    {
      v36->nextPtr = 2 * v30;
      frameLength = aThis->owner->frameLength;
      v39 = frameLength - v35;
      v38 = frameLength == v35;
      v40 = *aItf;
      if (!v38)
      {
        v41 = (aFrame - v35) / v39;
      }
    }
    else
    {
      v36->nextPtr = v32;
      v40 = *aItf;
    }
  }
  else
  {
    (*aItf)->nextPtr = 2 * (v31 + keyElemSize);
    v43 = keyFrameList->m_Items[v34];
    v39 = v43 - v35;
    v38 = v43 == v35;
    v40 = *aItf;
    if (!v38)
  }
  v40->nextPtr = v32;
  v40 = *aItf;
  v41 = 0.0;
  v40->rate = v41;
}

// 0x17a17e0
u32 sdfMotInterpolateKeyColor(sdfMotGetKeyIf_t *aItf) {
  System_Byte_array *key_frame;
  s32 basePtr;

  key_frame = aItf->key_frame;
  basePtr = aItf->basePtr;
  ToUInt32(key_frame, basePtr, 0);
  ToUInt32(aItf->key_frame, aItf->nextPtr, 0);
  return 0;
}

// 0x17a17d0
u32 sdfMotInterpolateKeyColorSub(u32 aColor0, u32 aColor1, f32 aRate) {
  return 0;
}

// 0x17a16e0
f32 sdfMotInterpolateKeyFloat(sdfMotGetKeyIf_t *aItf) {
  System_Byte_array *key_frame;
  s32 basePtr;
  f32 v5;
  f32 v7;
  f32 rate;
  f32 v9;

  key_frame = aItf->key_frame;
  basePtr = aItf->basePtr;
  v5 = ToSingle(key_frame, basePtr, 0);
  v7 = ToSingle(aItf->key_frame, aItf->nextPtr, 0);
  rate = aItf->rate;
  v9 = v7;
  return (v5 + (v9 * rate)) - (v5 * rate);
}

// 0x17a16c0
f32 sdfMotInterpolateKeyFloatSub(f32 aV0, f32 aV1, f32 aRate) {
  return ((aV1 * aRate) + aV0) - (aV0 * aRate);
}

// 0x17a1b80
u32 sdfMotInterpolateKeyUvw(sdfMotGetKeyIf_t *aItf, f32 ***aDst) {
  u32 v3;
  struct System_Byte_array *key_frame;
  s64 basePtr;
  u32 max_length;
  System_Single_array *v7;
  f32 v9;
  char *v10;
  s64 nextPtr;
  f32 v13;
  struct System_Byte_array *v15;
  s64 v16;
  u32 v17;
  System_Single_array *v18;
  u32 v20;
  s64 v21;
  f32 v23;
  struct System_Byte_array *v25;
  s64 v26;
  u32 v27;
  System_Single_array *v28;
  u32 v30;
  s64 v31;
  f32 v33;
  struct System_Byte_array *v35;
  s64 v36;
  u32 v37;
  System_Single_array *v38;
  u32 v40;
  s64 v41;
  f32 v43;
  struct System_Byte_array *v45;
  s64 v46;
  u32 v47;
  System_Single_array *v48;
  u32 v50;
  s64 v51;

  key_frame = aItf->key_frame;
  basePtr = aItf->basePtr;
  max_length = key_frame->max_length;
  v7 = *aDst;
  v9 = 1.0 - aItf->rate;
  v10 = key_frame + basePtr;
  nextPtr = aItf->nextPtr;
  LOBYTE(v3) = aItf->key_frame->m_Items[nextPtr];
  v13 = v3;
  v7->m_Items[0] = (v9 * v10[32]) + (aItf->rate * v13);
  v15 = aItf->key_frame;
  v16 = aItf->basePtr + 1LL;
  v17 = v15->max_length;
  v18 = *aDst;
  v20 = v15->m_Items[v16];
  v21 = aItf->nextPtr;
  LOBYTE(v13) = aItf->key_frame->m_Items[v21 + 1];
  v23 = LODWORD(v13);
  v18->m_Items[1] = (v9 * v20) + (aItf->rate * v23);
  v25 = aItf->key_frame;
  v26 = aItf->basePtr + 2LL;
  v27 = v25->max_length;
  v28 = *aDst;
  v30 = v25->m_Items[v26];
  v31 = aItf->nextPtr;
  LOBYTE(v23) = aItf->key_frame->m_Items[v31 + 2];
  v33 = LODWORD(v23);
  v28->m_Items[2] = (v9 * v30) + (aItf->rate * v33);
  v35 = aItf->key_frame;
  v36 = aItf->basePtr + 3LL;
  v37 = v35->max_length;
  v38 = *aDst;
  v40 = v35->m_Items[v36];
  v41 = aItf->nextPtr;
  LOBYTE(v33) = aItf->key_frame->m_Items[v41 + 3];
  v43 = LODWORD(v33);
  v38->m_Items[3] = (v9 * v40) + (aItf->rate * v43);
  v45 = aItf->key_frame;
  v46 = aItf->basePtr + 4LL;
  v47 = v45->max_length;
  v48 = *aDst;
  v50 = v45->m_Items[v46];
  v51 = aItf->nextPtr;
  LOBYTE(v43) = aItf->key_frame->m_Items[v51 + 4];
  v48->m_Items[4] = (v9 * v50) + (aItf->rate * LODWORD(v43));
  return 0;
}

// 0x17a18a0
void sdfMotInterpolateKeyUvwSub(f32 ***aDst, s32 **aSrc0, s32 **aSrc1, f32 aRate) {
  System_Single_array *v5;
  f32 v6;
  System_Single_array *v8;
  System_Single_array *v10;
  System_Single_array *v14;
  System_Single_array *v16;

  v5 = *aDst;
  v6 = 1.0 - aRate;
  v5->m_Items[0] = (v6 * aSrc0->m_Items[0]) + (aSrc1->m_Items[0] * aRate);
  v8 = *aDst;
  v8->m_Items[1] = (v6 * aSrc0->m_Items[1]) + (aSrc1->m_Items[1] * aRate);
  v10 = *aDst;
  v10->m_Items[2] = (v6 * aSrc0->m_Items[2]) + (aSrc1->m_Items[2] * aRate);
  v14 = *aDst;
  v14->m_Items[3] = (v6 * aSrc0->m_Items[3]) + (aSrc1->m_Items[3] * aRate);
  v16 = *aDst;
  v16->m_Items[4] = (v6 * aSrc0->m_Items[4]) + (aSrc1->m_Items[4] * aRate);
}

// 0x17a17c0
void sdfMotInterpolateKeyXYZ(sdfMotGetKeyIf_t *aItf) {
  ;
}

// 0x17a0ff0
void sdfMotionChange(sdfMotionCtrlr_t *aCtrlr, s32 aCutNum, s32 aType) {
  sdfMotionChangeBlend(aCtrlr, aCutNum, aType, 0.0, 0.0);
}

// 0x17a0dc0
void sdfMotionChangeBlend(sdfMotionCtrlr_t *aCtrlr, s32 aCutNum, s32 aType, f32 aPreFrame, f32 aBlendLeng) {
  u8 v8;
  struct sdfMotionPlayBook_t_o *playbook;
  s32 numOfCut;
  struct sdfMotionNodeList_t_o *nodeList;
  u64 v14;
  struct sdfMotionNode_t_array *items;
  f32 blendPreLength;
  struct sdfMotionPlayBook_t_o *v18;
  struct sdfMotionCutDef_t_array *cutList;
  sdfMotionCutDef_t_o *v21;
  struct sdfMotionNodeList_t_o *v22;
  s64 v23;
  struct sdfMotionNode_t_array *v24;
  sdfMotionNode_t_o *v26;
  struct sdfMotionCutChunk_t_array *cutChunk;
  s64 v29;

  v8 = aType;
  playbook = aCtrlr->playbook;
  if (playbook)
  {
    numOfCut = playbook->numOfCut;
    SDF_ASSERT(numOfCut > aCutNum);
    aCtrlr->cutNumber = aCutNum;
    if (aBlendLeng <= 0.0)
    {
      blendPreLength = 0.0;
      *&aCtrlr->blendLength = 0;
    }
    else
    {
      nodeList = aCtrlr->nodeList;
      aCtrlr->blendLength = aBlendLeng;
      aCtrlr->blendPreLength = -aPreFrame;
      if (nodeList->count < 1)
      {
        blendPreLength = -aPreFrame;
      }
      else
      {
        v14 = 0;
        do
        {
          items = nodeList->items;
          sdfMotCLBK_InitBlend_t__Invoke(items->m_Items[v14]->vtbl->initBlend, items->m_Items[v14]);
          nodeList = aCtrlr->nodeList;
          ++v14;
        }
        while (v14 < nodeList->count);
        blendPreLength = aCtrlr->blendPreLength;
      }
    }
    aCtrlr->frame = blendPreLength;
    v18 = aCtrlr->playbook;
    aCtrlr->playType = v8;
    aCtrlr->stat = 1;
    cutList = v18->cutList;
    v21 = cutList->m_Items[aCutNum];
    if (v21)
    {
      aCtrlr->frameLength = v21->frameLength;
      v22 = aCtrlr->nodeList;
      if (v22->count >= 1)
      {
        v23 = 4;
        do
        {
          v24 = v22->items;
          v26 = *(&v24->obj.klass + v23);
          cutChunk = v21->cutChunk;
          sdfMotCLBK_SetCut_t__Invoke(v26->vtbl->setCut, v26, *(&cutChunk->obj.klass + v23), 0);
          v22 = aCtrlr->nodeList;
          v29 = v23 - 3;
          ++v23;
        }
        while (v29 < v22->count);
      }
    }
    else
    {
      aCtrlr->frameLength = 0;
      aCtrlr->stat = 5;
    }
  }
}

// 0x17a0cb0
void sdfMotionCtrlrFree(sdfMotionCtrlr_t **aCtrlr) {
  sdfMotionCtrlr_t_o *v3;
  struct sdfModelRootNode_t_o *rootNode;
  sdfMotionCtrlr_t_o **p_motion;
  sdfMotionCtrlr_t_o *v6;
  bool v7;
  struct sdfMotionNodeList_t_o *nodeList;
  s64 count;
  struct sdfMotionNode_t_array *items;
  u64 v11;
  s64 v12;
  sdfMotionNode_t_o *v14;

  v3 = *aCtrlr;
  if (*aCtrlr)
  {
    rootNode = v3->rootNode;
    if (rootNode)
    {
      p_motion = &rootNode->motion;
      do
      {
        v6 = *p_motion;
        v7 = *p_motion == 0;
        p_motion = &(*p_motion)->next;
        v7 = v7 || v6 == v3;
      }
      while (!v7);
    }
    nodeList = v3->nodeList;
    if (nodeList)
    {
      count = nodeList->count;
      if (count >= 1)
      {
        items = nodeList->items;
        v11 = 0;
        v12 = count;
        do
        {
          v14 = items->m_Items[v11];
          sdfMotCLBK_Destroy_t__Invoke(v14->vtbl->destroy, v14);
          ++v11;
        }
        while (v12 != v11);
        v3 = *aCtrlr;
      }
    }
    v3->nodeList = 0;
    *aCtrlr = 0;
  }
}

// 0x17a0c30
sdfMotionCtrlr_t *sdfMotionCtrlrNew(sdfModelRootNode_t *aModel, sdfMotionPlayBook_t *aBook) {
  sdfMotionCtrlr_t_o *v5;

  v5 = Allocate(sdfMotionCtrlr_t);
  sdfMotionCtrlr_t___ctor(v5);
  v5->next = aModel->motion;
  aModel->motion = v5;
  v5->rootNode = aModel;
  v5->playbook = aBook;
  return v5;
}

// 0x17a11d0
s32 sdfMotionNext(sdfMotionCtrlr_t *aCtrlr) {
  s32 v3;
  s64 *v4;
  f32 blendPreLength;
  f32 frame;
  f32 v7;
  f32 v8;

  v3 = 0;
  switch (aCtrlr->stat)
  {
    case 0u:
      v4 = &StringLiteral_22016;
    case 1u:
      blendPreLength = aCtrlr->blendPreLength;
      sdfMotionSeek(aCtrlr, blendPreLength);
      return 0;
    case 4u:
      frame = aCtrlr->frame;
      v7 = frame + aCtrlr->speed;
      LOWORD(frame) = aCtrlr->frameLength;
      v8 = LODWORD(frame);
      if (aCtrlr->playType)
      {
        if (v7 >= v8)
        {
          *&aCtrlr->blendLength = 0;
          do
            v7 = v7 - v8;
          while (v7 >= v8);
          v3 = 2;
        }
        v3 = 0;
        sdfMotionSeek(aCtrlr, v7);
        return v3;
      }
      if (v7 < v8)
      sdfMotionSeek(aCtrlr, v8);
      aCtrlr->stat = 5;
      return 1;
    case 5u:
    case 6u:
      return v3;
    default:
      v4 = &StringLiteral_22017;
      SDF_ABORT1(*v4);
      return 0;
  }
}

// 0x17a0c20
void sdfMotionNodeBaseInit(sdfMotionNode_t *aNode, sdfMotionCtrlr_t *aCtrlr, sdfMotionNodeVTBL_t *aVTBL) {
  aNode->vtbl = aVTBL;
  aNode->owner = aCtrlr;
}

// 0x17a0c00
void sdfMotionNodeFree(sdfMotionNode_t *aNode) {
  sdfMotCLBK_Destroy_t__Invoke(aNode->vtbl->destroy, aNode);
}

// 0x17a04d0
sdfMotionNode_t *sdfMotionNodeNew(sdfMotionCtrlr_t *aCtrlr, u32 aTypeId, u32 aNodeId) {
  s64 v8;
  struct sdfMotion_sdfMotionNodeGenerator_t_array *sdfMotionMajorDef;
  struct sdfMotion_sdfMotionNodeGenerator_t_array *v11;

  v8 = HIWORD(aTypeId);
  SDF_ASSERT(v8 < SLODWORD(sdfMotionMajorDef->max_length), 0);
  v11 = sdfMotionMajorDef;
  return Invoke(v11->m_Items[v8], aCtrlr, aTypeId, aNodeId);
}

// 0x17a1390
void sdfMotionPause(sdfMotionCtrlr_t *aCtrlr) {
  s32 stat;

  stat = aCtrlr->stat;
  if (stat != 6)
  {
    aCtrlr->statBeforePause = stat;
    aCtrlr->stat = 6;
  }
}

// 0x17a13b0
void sdfMotionPauseOff(sdfMotionCtrlr_t *aCtrlr) {
  if (aCtrlr->stat == 6)
    aCtrlr->stat = aCtrlr->statBeforePause;
}

// 0x17a1080
void sdfMotionSeek(sdfMotionCtrlr_t *aCtrlr, f32 aFrame) {
  f32 blendLength;
  f32 v6;
  f32 v7;
  struct sdfMotionNodeList_t_o *v8;
  f32 v9;
  u64 v10;
  struct sdfMotionNode_t_array *v11;
  struct sdfMotionNodeList_t_o *nodeList;
  s64 count;
  u64 v15;
  s64 v16;
  struct sdfMotionNode_t_array *items;

  aCtrlr->frame = aFrame;
  blendLength = aCtrlr->blendLength;
  v6 = aFrame - aCtrlr->blendPreLength;
  aCtrlr->stat = 4;
  if (v6 >= blendLength)
  {
    nodeList = aCtrlr->nodeList;
    count = nodeList->count;
    if (count >= 1)
    {
      v15 = 0;
      v16 = count - 1LL;
      items = nodeList->items;
      while (1)
      {
        sdfMotCLBK_Seek_t__Invoke(items->m_Items[v15]->vtbl->seek, items->m_Items[v15], aFrame);
        if (v16 == v15)
          break;
        ++v15;
        items = aCtrlr->nodeList->items;
        if (v15 >= LODWORD(items->max_length))
      }
    }
  }
  else
  {
    v7 = 0.0;
    if (v6 >= 0.0)
      v7 = v6 / blendLength;
    v8 = aCtrlr->nodeList;
    if (v8->count >= 1)
    {
      v9 = fmaxf(aFrame, 0.0);
      v10 = 0;
      do
      {
        v11 = v8->items;
        sdfMotCLBK_BlendSeek_t__Invoke(v11->m_Items[v10]->vtbl->blendSeek, v11->m_Items[v10], v9, v7);
        v8 = aCtrlr->nodeList;
        ++v10;
      }
      while (v10 < v8->count);
    }
  }
}
