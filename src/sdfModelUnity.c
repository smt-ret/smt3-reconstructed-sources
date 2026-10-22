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
  s64 *extraData;
  Il2CppClass *v6;
  s64 *Interface;
  char *v8;
  s64 *v9;
  u64 v11[3];

  extraData = aRoot->extraData;
  if (!extraData)
    goto LABEL_12;
LABEL_6:
  Interface = QueryInterface(extraData, byte);
  if (!Interface)
  {
    sub_8FC2C0(*(*extraData + 64), v6, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return sdfModelSearchExtraChunkUnity(Interface, aChunkId);
}

// 0x179fa40
void *sdfModelGetGameObject(sdfModelRootNode_t *aRoot, s32 aId) {
  sdfModelExtraChunkMarkPos_t_o *v5;

  v5 = sdfModelSearchMarkPosDataUnity(aRoot, aId);
  return sdfModelGetGameObject_24769808(aRoot, v5);
}

// 0x179f510
void *sdfModelGetGameObject_24769808(sdfModelRootNode_t *aRoot, sdfModelExtraChunkMarkPos_t *aMark) {
  UnityEngine_Object_o *modelobj;
  bool v6;
  UnityEngine_Object_o *obj;
  sdfModelExtraChunkMarkPos_t_Fields *p_fields;
  UnityEngine_GameObject_o *v10;
  Il2CppObject *Component_object;
  s32 nodeId;
  System_String_o *NodeNameUnity;
  System_String_o *v18;
  System_String_o *v19;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  System_String_o *v23;
  System_String_o *v24;
  s32 v28;

  if (!aRoot)
    return 0;
  modelobj = aRoot->modelobj;
  v6 = op_Equality(modelobj, 0, 0);
  obj = 0;
  if (aMark && !v6)
  {
    obj = aMark->obj;
    if (!op_Inequality(obj, 0, 0))
    {
      p_fields = &aMark->fields;
      v10 = aRoot->modelobj;
      if (aMark->nodeId)
      {
        Component_object = GetComponent_object_(v10);
        if (op_Inequality(Component_object, 0, 0))
        {
          nodeId = p_fields->nodeId;
          NodeNameUnity = sdfModelGetNodeNameUnity(aRoot, nodeId);
          obj = (Component_object->klass->vtable[6].methodPtr)(
                  Component_object,
                  NodeNameUnity,
                  Component_object->klass->vtable[6].method);
          if (!op_Equality(obj, 0, 0))
            goto LABEL_41;
          v18 = sub_232A70(&aMark->nodeId, "d3");
          v19 = Concat_5224608("node", v18);
        }
        else
        {
          Component_object = GetComponent_object_(aRoot->modelobj);
          if (!op_Inequality(Component_object, 0, 0))
            goto LABEL_41;
          v23 = sub_232A70(&aMark->nodeId, "d3");
          v24 = Concat_5224608("node", v23);
          obj = (Component_object->klass->vtable[6].methodPtr)(
                  Component_object,
                  v24,
                  Component_object->klass->vtable[6].method);
          if (!op_Equality(obj, 0, 0))
            goto LABEL_41;
          v28 = p_fields->nodeId;
          v19 = sdfModelGetNodeNameUnity(aRoot, v28);
        }
        obj = (Component_object->klass->vtable[6].methodPtr)(
                Component_object,
                v19,
                Component_object->klass->vtable[6].method);
LABEL_41:
        aMark->obj = obj;
        return obj;
      }
      transform = get_transform(v10, 0);
      Child = GetChild(transform, 0);
      obj = get_gameObject(Child);
      aMark->obj = obj;
    }
  }
  return obj;
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
      goto LABEL_17;
    }
  }
  else
  {
    Component_object = 0;
  }
  MPosCount = 0;
LABEL_17:
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
  sdfModelExtraChunk_t_o *ExtraChunkUnity;
  s64 sPos;
  s64 size;
  s64 *extraData;
  Il2CppClass *v11;
  s64 *Interface;
  char *v13;
  s64 *v14;
  s64 v15;
  s32 v16;
  u64 *v17;
  u64 *v18;
  u64 *v19;
  s32 v20;
  u64 v21;
  s32 v22;
  s32 v25;
  u32 v26;
  s32 v27;
  s32 v28;
  System_Text_Encoding_o *Encoding_5348256;
  u64 *v32;
  u64 v33;
  s32 v36;
  u64 v37[3];

  ExtraChunkUnity = sdfModelGetExtraChunkUnity(aRoot, SDF_CC_NDNM);
  if (!ExtraChunkUnity)
    goto LABEL_31;
  v36 = aIndex;
  sPos = ExtraChunkUnity->sPos;
  size = ExtraChunkUnity->size;
  extraData = aRoot->extraData;
  if (extraData)
  {
    Interface = QueryInterface(extraData, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*extraData + 64), v11, v37);
      if ((v37[0] & 1) != 0)
        v13 = v37[2];
      else
        v13 = v37 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  else
  {
    Interface = 0;
  }
  v15 = size + sPos;
  v16 = sPos + 8;
  v17 = NewSpecific(byte, 0x100u);
  if (v16 < v15)
  {
    v18 = v17;
    v19 = v17 + 4;
    while (1)
    {
      v20 = v16;
      v21 = 0;
      while (1)
      {
        v22 = *(Interface + v16 + v21 + 32);
        *(v19 + v21) = v22;
        if (!v22)
          break;
        ++v21;
        if ((v16 + v21) >= v15)
          goto LABEL_31;
      }
      v25 = v16 + v21 + 3;
      if (v16 + v21 >= 0)
        v25 = v16 + v21;
      v26 = v25 & 0xFFFFFFFC;
      v27 = v16 + v21 - v26;
      v28 = v26 + 4;
      if (ToInt32(Interface, v28, 0) == v36)
        break;
      v16 = v16 - v27 + v21 + 8;
      if (v20 - v27 + v21 + 8 >= v15)
        goto LABEL_31;
    }
    Encoding_5348256 = GetEncoding_5348256("Shift_JIS");
    v32 = NewSpecific(byte, v21);
    if (v21)
    {
      v33 = 0;
      do
      {
        *(v32 + v33 + 32) = *(v18 + v33 + 32);
        ++v33;
      }
      while (v21 != v33);
    }
    return (Encoding_5348256->klass[1]._1.byval_arg.data)(
             Encoding_5348256,
             v32,
             *&Encoding_5348256->klass[1]._1.byval_arg.bits);
  }
  else
  {
LABEL_31:
    return sdfModelGetNodeName_no_name_strUnity;
  }
}

// 0x179e500
sdfMatrix4_t *sdfModelGetNodeTm(void *retstr, void *aObject) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v7;
  UnityEngine_Transform_o *v8;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  UnityEngine_Matrix4x4_o *result;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  UnityEngine_Matrix4x4_o v20;
  UnityEngine_Matrix4x4_o v21;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v23;
  UnityEngine_Vector3_o lossyScale;
  UnityEngine_Quaternion_o rotation;

  memset(&v21, 0, sizeof(v21));
  get_identity(&v20, 0);
  v21 = v20;
  transform = get_transform(aObject, 0);
  position = get_position(transform);
  v23 = op_Multiply(position, 100.0, 0);
  v7 = get_transform(aObject, 0);
  rotation = get_rotation(v7);
  v8 = get_transform(aObject, 0);
  lossyScale = get_lossyScale(v8);
  result = sub_19FED50(
             &v21,
             0,
             v23.x,
             v23.y,
             v23.z,
             rotation.x,
             rotation.y,
             rotation.z,
             rotation.w,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             *&lossyScale.x,
             LODWORD(lossyScale.z));
  v16 = *&v21.m21;
  *&retstr->m01 = *&v21.m01;
  *&retstr->m21 = v16;
  v17 = *&v21.m20;
  *&retstr->m00 = *&v21.m00;
  *&retstr->m20 = v17;
  v18 = *&v21.m23;
  *&retstr->m03 = *&v21.m03;
  *&retstr->m23 = v18;
  v19 = *&v21.m22;
  *&retstr->m02 = *&v21.m02;
  *&retstr->m22 = v19;
  return result;
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
  sdfModelRootNode_t_o *v5;
  UnityEngine_Object_o *GameObject_24769808;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 y;
  f32 v14;
  f32 v15;
  f32 x;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  s64 v28;
  s64 v29;
  s64 v30;
  s64 v31;
  s64 v32;
  s64 v33;
  s64 v34;
  UnityEngine_Matrix4x4_o v37;
  UnityEngine_Matrix4x4_o v38;
  UnityEngine_Matrix4x4_o v39;
  UnityEngine_Matrix4x4_o v40;
  UnityEngine_Matrix4x4_o v41;
  UnityEngine_Matrix4x4_o v42;
  UnityEngine_Matrix4x4_o v43;
  u64 v44[2];
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;
  UnityEngine_Matrix4x4_o v48;
  UnityEngine_Matrix4x4_o v49;

  memset(&v49, 0, sizeof(v49));
  memset(&v48, 0, sizeof(v48));
  if (!aMark)
    return 0;
  v5 = *aRoot;
  GameObject_24769808 = sdfModelGetGameObject_24769808(v5, aMark);
  if (!op_Inequality(GameObject_24769808, 0, 0))
    return 0;
  sdfModelGetNodeTm(&v49, GameObject_24769808);
  sub_1A00070(&v49, 3u);
  v10 = v9;
  v12 = v11;
  y = aMark->forward.y;
  v15 = v14;
  x = aMark->forward.x;
  v18 = v17;
  v19 = -aMark->forward.z;
  *&v47.x = 0;
  *&v47.z = 0;
  sub_854690(&v47.x, x, v19, y, 0.0);
  SDF_VU0__LOADVECTOR(v47);
  SDF_VU0__SET_ROW2();
  SDF_VU0__COPYVECTOR_A_TO_B();
  v20 = aMark->up.y;
  v21 = aMark->up.x;
  v22 = -aMark->up.z;
  *&v46.x = 0;
  *&v46.z = 0;
  sub_854690(&v46.x, v21, v22, v20, 0.0);
  SDF_VU0__LOADVECTOR(v46);
  SDF_VU0__NEGVECTOR_XYZ();
  SDF_VU0__SET_ROW1();
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__SET_ROW0();
  v23 = aMark->pos.y;
  v24 = aMark->pos.x;
  v25 = -aMark->pos.z;
  *&v45.x = 0;
  *&v45.z = 0;
  sub_854690(&v45.x, v24, v25, v23, 1.0);
  SDF_VU0__LOAD_ROW3(v45);
  v44[0] = 0;
  v44[1] = 0;
  sub_854690(v44, v15, -v10, v12, v18);
  sub_1A009D0(&v49, 3);
  v28 = *&mod_matrix.m00;
  v29 = *&mod_matrix.m20;
  v30 = *&mod_matrix.m21;
  *&v43.m01 = *&mod_matrix.m01;
  *&v43.m21 = v30;
  *&v43.m00 = v28;
  *&v43.m20 = v29;
  v31 = *&mod_matrix.m02;
  v32 = *&mod_matrix.m22;
  v34 = *&mod_matrix.m03;
  v33 = *&mod_matrix.m23;
  *&v43.m03 = v34;
  *&v43.m23 = v33;
  v42 = v49;
  *&v43.m02 = v31;
  *&v43.m22 = v32;
  v40 = v43;
  v39 = v42;
  op_Multiply(&v41, &v40, &v39, 0);
  v48 = v41;
  sub_19FF440(&v48, 0, &v38);
  v37 = v38;
  MultMatrixRev(&v37);
  return 1;
}

// 0x179f8a0
s32 sdfModelMakeMarkPosUnity(sdfModelRootNode_t **aRoot, sdfModelExtraChunkMarkPos_t *aMark) {
  sdfModelRootNode_t_o *v5;
  UnityEngine_Object_o *GameObject_24769808;
  f32 x;
  f32 y;
  f32 z;
  long f64 v12;
  long f64 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  s64 v21;
  f32 v22;
  UnityEngine_Matrix4x4_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector3_o v25;
  UnityEngine_Vector4_o v26;

  memset(&v23, 0, sizeof(v23));
  if (!aMark)
    return 0;
  v5 = *aRoot;
  GameObject_24769808 = sdfModelGetGameObject_24769808(v5, aMark);
  if (!op_Inequality(GameObject_24769808, 0, 0))
    return 0;
  sdfModelGetNodeTm(&v23, GameObject_24769808);
  x = aMark->pos.x;
  y = aMark->pos.y;
  z = aMark->pos.z;
  v22 = 0.0;
  v21 = 0;
  sub_8524C0(&v21, -x, z, -y);
  v14 = sub_1A00CF0(&v23.m00, *&v21, *(&v21 + 1), v22, v12);
  v15 = *&v14;
  v17 = v16;
  v19 = v18;
  v25.x = v15;
  v25.y = v17;
  v25.z = v19;
  v24 = op_Implicit(v25, 0);
  v26.x = v24.x;
  v26.z = v24.z;
  v26.w = v24.w;
  v26.y = -v24.y;
  SDF_VU0__LOADVECTOR(v26);
  return 1;
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
        goto LABEL_19;
LABEL_22:
      sdfModelNodeAddUnity(&aRoot, &aParent, &aNode);
      --v15;
      v22->id = v8->id;
      if (!v15)
        return v13;
    }
    items = v13->nodeList->items;
    aParent = items->m_Items[parentIndex];
      goto LABEL_22;
LABEL_19:
    goto LABEL_22;
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
LABEL_16:
    bPosa = -1;
LABEL_17:
    Log("MD00 NoData", 0);
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
      goto LABEL_16;
  }
  bPosa = v8 - 32;
  if (v8 - 32 < 0)
    goto LABEL_17;
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
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v10;

  (*aNode)->shape = aDef;
  (*aNode)->id = aDef->id;
  sub_854710(&aDef->rotate, 0);
  v6 = v5;
  sub_854710(&aDef->rotate, 1u);
  v8 = v7;
  sub_854710(&aDef->rotate, 2u);
  FromEuler(v6, v8, v10);
  SDF_VU0__STOREVECTOR(&(*aNode)->rotate, 0);
  SDF_VU0__COPYVECTOR(&(*aNode)->pos, aDef->pos, 0);
  SDF_VU0__COPYVECTOR(&(*aNode)->scale, aDef->scale, 0);
  sub_854930(&(*aNode)->pos, 3u);
  SDF_VU0__LOADVECTOR((*aNode)->rotate, 0);
  ToMatrix();
  SDF_VU0__LOAD_ROW3((*aNode)->pos, 0);
  SDF_VU0__STOREMATRIX(&(*aNode)->localNoScaledTm, 0);
  (*aNode)->bounds = aDef->bounds;
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
  sdfModelNode_t_o *v5;
  struct sdfModelNode_t_o *parent;
  sdfModelNode_t_o *v10;
  struct sdfModelNode_t_o *children;
  sdfModelNode_t_o *v12;
  struct sdfModelRootNode_t_o *v13;
  struct sdfModelNode_t_o *headNode;
  struct sdfModelRootNode_t_o *root;

  v5 = *aNode;
  if (*aParent)
  {
    parent = v5->parent;
    if (parent != *aParent)
    {
      else if (parent)
      {
        goto LABEL_8;
      }
      root = v5->root;
      if (root->headNode == v5)
      {
        root->headNode = 0;
        v10 = *aParent;
        children = (*aParent)->children;
        v12 = *aNode;
        if (children)
          goto LABEL_24;
        goto LABEL_26;
      }
      goto LABEL_23;
    }
  }
  else
  {
    v13 = v5->root;
    headNode = v13->headNode;
    if (headNode != v5)
    {
      v13->headNode = v5;
      if (headNode)
      {
        (*aNode)->children = headNode;
        headNode->parent = *aNode;
      }
      (*aNode)->parent = 0;
    }
  }
}

// 0x179dc20
void sdfModelNodeSetUnity(sdfModelNode_t **aNode, sdfModelNodeDef_t *aDef) {
  u64 *v5;
  struct System_Object_array *shape;
  struct System_Object_array *v11;
  u64 v12;
  struct System_Object_array *v15;
  u64 v16;

  v5 = Allocate(object);
  _ctor(v5, 0);
  sdfModelNodeBaseSetUnity(aNode, aDef);
  if (aDef->format != 1)
  {
    if (aDef->format)
      return;

    {
      if (LODWORD(aDef->shape->max_length) > 1)
        goto LABEL_28;
    }
  }
  shape = aDef->shape;
  if (shape->m_Items[0])
  {
    v11 = aDef->shape;
    v12 = 0;
    do
    {
    }
    while (v11->m_Items[v12++]);
    v15 = aDef->shape;
    v16 = 0;
    do
    {
    }
    while (v15->m_Items[v16++]);
  }
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
  UnityEngine_Object_o *modelobj;
  bool v6;
  Il2CppObject *Component_object;
  sdfModelExtraChunkMarkPos_t_o *MPosData;
  sdfModelExtraChunk_t_o *ExtraChunkUnity;
  sdfModelExtraChunk_t_o *v14;
  u32 size;
  s32 v16;
  s32 sPos;
  s32 v18;
  s64 *extraData;
  Il2CppClass *v20;
  s64 *Interface;
  char *v22;
  s64 *v23;
  s32 v24;
  s32 v25;
  s32 v26;
  u64 v29[3];
  s32 bPos;

  bPos = 0;
  if (!aRoot)
    return 0;
  modelobj = aRoot->modelobj;
  v6 = op_Inequality(modelobj, 0, 0);
  Component_object = 0;
  if (!v6)
    goto LABEL_13;
  Component_object = GetComponent_object_(aRoot->modelobj);
  if (!op_Inequality(Component_object, 0, 0)
    || (MPosData = GetMPosData(Component_object, aId)) == 0)
  {
LABEL_13:
    ExtraChunkUnity = sdfModelGetExtraChunkUnity(aRoot, SDF_CC_MPOS);
    if (!ExtraChunkUnity)
      return 0;
    v14 = ExtraChunkUnity;
    MPosData = Allocate(sdfModelExtraChunkMarkPos_t);
    sdfModelExtraChunkMarkPos_t___ctor(MPosData);
    size = v14->size;
    v16 = size - sdfModelExtraChunk_t__GetSize(v14);
    if (v16 >= 0)
      v18 = v16;
    else
      v18 = v16 + 63;
    sPos = v14->sPos;
    bPos = sdfModelExtraChunk_t__GetSize(v14) + sPos;
    extraData = aRoot->extraData;
    if (extraData)
    {
      Interface = QueryInterface(extraData, byte);
      if (!Interface)
      {
        sub_8FC2C0(*(*extraData + 64), v20, v29);
        if ((v29[0] & 1) != 0)
          v22 = v29[2];
        else
          v22 = v29 + 1;
        v23 = sub_8C4940(v22);
      }
      if (v16 < 64)
        return 0;
    }
    else
    {
      Interface = 0;
      if (v16 < 64)
        return 0;
    }
    v24 = v18 >> 6;
    v25 = bPos;
    v26 = 0;
    while (sdfModelExtraChunkMarkPos_t__GetId(MPosData, Interface, v25) != aId)
    {
      ++v26;
      v25 += 64;
      bPos = v25;
      if (v26 >= v24)
        return 0;
    }
    sdfModelExtraChunkMarkPos_t__bCopy(MPosData, Interface, &bPos);
    if (op_Inequality(Component_object, 0, 0))
    {
      SetMPosCount(Component_object, v24);
      SetMPosData(Component_object, v26, MPosData);
    }
  }
  return MPosData;
}
