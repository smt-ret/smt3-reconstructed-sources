#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBattleMisc_effBTLPartfunc_t effBattleMisc_effBTLPartfunc_t;
typedef struct effBattleMisc_effBTLPartfunc_t_funcDelegate effBattleMisc_effBTLPartfunc_t_funcDelegate;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

struct effBattleMisc_effBTLPartfunc_t {
    effBattleMisc_effBTLPartfunc_t_funcDelegate *func;
};

static u8 effBTLModelShowFlag[UNKNOWN_ARRAY_SIZE];
static u32 effBTL_Ptr_FadeFrame[4];
static f32 effBTL_Ptr_H[6];
static f32 effBTL_Ptr_D[11];
static sdfVector4_t effBTLPartPtrModelCenterOffset[UNKNOWN_ARRAY_SIZE];
static effBattleMisc_effBTLPartfunc_t *GetPositionPtrTable[6];

void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
void InversMatrix(void);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void MultMatrixNoArg(void);
void MultMatrixRev(sdfMatrix4_t *aMatrix);
void MultMatrixRevNoArg(void);
void ReverseMatrix(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_B_A(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__APPLYMATRIX_B(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADIDENTITY(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__LOAD_ROW3(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__PERSVECTOR(void);
void SDF_VU0__RESET_ROW3(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__SWAPVECTOR_A_C(void);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void SetRotateMatrixX(f32 aAngle);
void SetRotateMatrixY(f32 aAngle);
void SetRotateMatrixY_B(f32 aAngle);
void ToMatrix(void);
void dds3CameraObjectBasicGetTargetPos(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetActiveScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
void effBTLModelGetCircumference(nbFormation_t **pFormation, sdfVector4_t *pDirection);
f32 effBTLModelGetHeight(nbFormation_t **pFormation);
void effBTLModelGetMarkPosition2(nbFormation_t **pFormation, u32 mark);
void effBTLModelGroupGetCenter(u32 group);
f32 effBTLModelGroupGetMaxLength(sdfVector4_t *pPos, u32 group);
f32 effBTLModelGroupGetSphere(u32 group);
f32 effBTLModelGroupGetSphereExp(u32 group, u32 model);
void effBTLModelInvokePartyShow(void);
void effBTLModelLook(nbFormation_t **pFormation, sdfVector4_t *pTargetPos);
void effBTLPartGetPartyPositionPtr(u32 group, effBTL_SkillPositionPtr_t **pPosPtr);
void effBTLPartGetPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pPos);
void effBTLPartPtrGetModelCenter(nbFormation_t **pFormation);
void effBTLPartPtrModelGroupGetCenterAndHeight(u32 group, sdfVector4_t *pCenter, f32 *pHeightAve, f32 *pHeightMax, f32 *pFrontMax);
s32 effBTLSkillCheckRun(void);
u32 effBTLSkillGetID(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
u32 effBTLSkillGetInvokeParty(void);
u32 effBTLSkillGetTargetBit(void);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
u32 effBTLSkillGetTargetNumber(void);
u32 effBTLSkillGetTargetParty(void);
f32 effLinePointLength(sdfVector4_t pDir, sdfVector4_t pLinePos, sdfVector4_t pPos);
void mdlGetPosition(dds3ModelHandle_t **aHandle);
void nbFormDispOff2(nbFormation_t **form);
void nbFormDispOn2(nbFormation_t **form);
void nbGetFormPos(nbFormation_t **form);
void nbGetFormRot(nbFormation_t **form);
nbMainProcessData_t *nbGetMainProcessData(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbSetFormRot(nbFormation_t **form, sdfVector4_t rot, bool look2);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
f32 sdfFabs(f32 c);
s32 sdfModelGetMarkPosMatrixUnity(sdfModelRootNode_t *aRoot, s32 aId);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSin(f32 aRadius);

// 0x14c4290
f32 Byte2Float(u8 **bytedata, s32 pos) {
  return ToSingle(bytedata, pos, 0);
}

// 0x14c4190
u16 Byte2UInt16(u8 **bytedata, s32 pos) {
  return ToInt16(bytedata, pos, 0);
}

// 0x14c4210
u32 Byte2UInt32(u8 **bytedata, s32 pos) {
  return ToInt32(bytedata, pos, 0);
}

// 0x14c4310
sdfQuaternion_t ExtractRotation(sdfMatrix4_t *matrix) {
  f32 m02;
  f32 m12;
  f32 m22;
  f32 m01;
  f32 m11;
  f32 m21;
  UnityEngine_Vector3_o v9;
  UnityEngine_Vector3_o v10;

  m02 = matrix->m02;
  m12 = matrix->m12;
  m22 = matrix->m22;
  m01 = matrix->m01;
  m11 = matrix->m11;
  m21 = matrix->m21;
  v9.x = m02;
  v9.y = m12;
  v9.z = m22;
  v10.x = m01;
  v10.y = m11;
  v10.z = m21;
  return LookRotation(v9, v10);
}

// 0x14c0710
void effBTLModelAllHide(void) {
    nbGetMainProcessData();
}

// 0x14bf6d0
void effBTLModelAllPopPosition(void) {
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *v5;
  nbFormation_t_o *v7;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o v13;

  form = 0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    v5 = MainProcessData->form;
    v7 = v5->m_Items[i];
    form = v7;
    if ((~v7->stat & 3) == 0)
    {
      else if ((byte_3F59A64 & 1) != 0)
      {
        x = v7->orgpos.x;
        y = v7->orgpos.y;
        z = v7->orgpos.z;
        w = v7->orgpos.w;
        v13.x = x;
        v13.y = y;
        v13.z = z;
        v13.w = w;
        nbSetFormPos(&form, v13);
        continue;
      }
    }
  }
}

// 0x14bf870
void effBTLModelAllPopRotate(void) {
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *v5;
  nbFormation_t_o *v7;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o v13;

  form = 0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    v5 = MainProcessData->form;
    v7 = v5->m_Items[i];
    form = v7;
    if ((~v7->stat & 3) == 0)
    {
      x = v7->orgrot.x;
      y = v7->orgrot.y;
      z = v7->orgrot.z;
      w = v7->orgrot.w;
      v13.x = x;
      v13.y = y;
      v13.z = z;
      v13.w = w;
      nbSetFormRot(&form, v13, 0);
    }
  }
}

// 0x14bf6c0
void effBTLModelAllPushPosition(void) {
  ;
}

// 0x14bf860
void effBTLModelAllPushRotate(void) {
  ;
}

// 0x14c05a0
void effBTLModelAllShow(void) {
    nbGetMainProcessData();
}

// 0x14c1ca0
s32 effBTLModelCheckBossID(nbFormation_t **pFormation) {
  nbFormation_t_o *v3;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;

  v3 = *pFormation;
  if (*pFormation && (v3->stat & 1) != 0)
  {
    formindex = v3->formindex;
    else
    {
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
      if (UnitWorkFromFormindex)
        return UnitWorkFromFormindex->id > 0xFFu;
    }
  }
  return 0;
}

// 0x14c3e10
void effBTLModelCheckBoundsHide(nbFormation_t **pFormation, f32 w, f32 h, sdfVector4_t *pTarget, sdfVector4_t *pEye, sdfVector4_t *pUp) {
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    MultMatrixRev(0);
    SDF_VU0__STOREMATRIX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(0);
    ToMatrix();
    SDF_VU0__LOAD_ROW3((sdfVector4_t){0});
}

// 0x14c1d50
u32 effBTLModelGetBadStatus(nbFormation_t **pFormation) {
  s32 formindex;

  formindex = (*pFormation)->formindex;
  return nbGetUnitWorkFromFormindex(formindex)->badstatus;
}

// 0x14bc630
void effBTLModelGetCircumference(nbFormation_t **pFormation, sdfVector4_t *pDirection) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__SWAPVECTOR_A_C();
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_C_TO_B();
}

// 0x14bc740
void effBTLModelGetCircumferencePtr(nbFormation_t **pFormation, u16 ptr_y, u16 ptr_x) {
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetCircumference(0, 0);
}

// 0x14bc420
void effBTLModelGetDirection(nbFormation_t **pFormation, sdfVector4_t *pDirection) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x14bc5b0
void effBTLModelGetDirection2(nbFormation_t **pFormation) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX_XYZ();
}

// 0x14bee60
f32 effBTLModelGetGroupMaxHeight(u32 group) {
  f32 v3;
  nbMainProcessData_t_o *MainProcessData;
  u64 v6;
  s32 v7;
  struct nbFormation_t_array *form;
  f32 Height;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  v3 = 0.0;
  MainProcessData = nbGetMainProcessData();
  v6 = 0;
  v7 = 1;
  do
  {
    while (1)
    {
      form = MainProcessData->form;
      pFormation = form->m_Items[v6];
      if ((pFormation->stat & 3) != 3 || (pFormation->stat & group) == 0)
        break;
      Height = effBTLModelGetHeight(&pFormation);
      if (v7)
      if (v3 < Height)
      v7 = 0;
      if (++v6 == 32)
        return v3;
    }
    Height = effBTLModelGetHeight(&pFormation);
    if (!v7)
    v3 = Height;
    v7 = 0;
    ++v6;
  }
  while (v6 != 32);
  return v3;
}

// 0x14bed80
u32 effBTLModelGetGroupNumber(u32 group) {
  nbMainProcessData_t_o *MainProcessData;
  u64 v4;
  u32 v5;
  struct nbFormation_t_array *form;
  Il2CppClass **v8;

  MainProcessData = nbGetMainProcessData();
  v4 = 0;
  v5 = 0;
  do
  {
    form = MainProcessData->form;
    v8 = &form->obj.klass + v4++;
    v5 += (v8[4]->_1.events & group) != 0 && (~LODWORD(v8[4]->_1.events) & 3) == 0;
  }
  while (v4 != 32);
  return v5;
}

// 0x14bc900
f32 effBTLModelGetHeight(nbFormation_t **pFormation) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0x14bad10
u32 effBTLModelGetID(nbFormation_t **pFormation) {
  nbFormation_t_o *v3;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;

  v3 = *pFormation;
  if (!*pFormation)
    return 512;
  if ((v3->stat & 1) == 0)
    return 512;
  formindex = v3->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if ((UnitWorkFromFormindex->flag & 4) != 0)
    return 0;
  else
    return UnitWorkFromFormindex->id;
}

// 0x14c1a80
u32 effBTLModelGetInvokeGroupNumber(void) {
  u32 v3;
  nbMainProcessData_t_o *MainProcessData;
  u64 v5;
  u32 v6;
  struct nbFormation_t_array *form;
  Il2CppClass **v9;

  v3 = effBTLSkillGetInvokeParty();
  MainProcessData = nbGetMainProcessData();
  v5 = 0;
  v6 = 0;
  do
  {
    form = MainProcessData->form;
    v9 = &form->obj.klass + v5++;
    v6 += (v9[4]->_1.events & v3) != 0 && (~LODWORD(v9[4]->_1.events) & 3) == 0;
  }
  while (v5 != 32);
  return v6;
}

// 0x14bce10
s32 effBTLModelGetMarkMatrix(nbFormation_t **pFormation, u32 mark) {
  struct evtUnitHandle_t_o *hunit;
  sdfModelRootNode_t_o *modelRoot;

  if ((~(*pFormation)->stat & 3) != 0)
    return 0;
  hunit = (*pFormation)->hunit;
  if (!hunit)
    return 0;
  modelRoot = hunit->Model->modelRoot;
  return sdfModelGetMarkPosMatrixUnity(modelRoot, mark);
}

// 0x14bcec0
void effBTLModelGetMarkMatrix2(nbFormation_t **pFormation, u32 mark) {
  struct evtUnitHandle_t_o *hunit;
  sdfModelRootNode_t_o *modelRoot;

  if ((~(*pFormation)->stat & 3) != 0)
  hunit = (*pFormation)->hunit;
  if (!hunit)
  modelRoot = hunit->Model->modelRoot;
  if (!sdfModelGetMarkPosMatrixUnity(modelRoot, mark))
    SDF_VU0__LOADIDENTITY();
}

// 0x14bca40
s32 effBTLModelGetMarkPosition(nbFormation_t **pFormation, u32 mark) {
  struct evtUnitHandle_t_o *hunit;
  sdfModelRootNode_t_o *modelRoot;

  if ((~(*pFormation)->stat & 3) != 0)
    return 0;
  hunit = (*pFormation)->hunit;
  if (!hunit)
    return 0;
  modelRoot = hunit->Model->modelRoot;
  return sdfModelGetMarkPosUnity(modelRoot, mark);
}

// 0x14bcaf0
void effBTLModelGetMarkPosition2(nbFormation_t **pFormation, u32 mark) {
  struct evtUnitHandle_t_o *hunit;
  sdfModelRootNode_t_o *modelRoot;

  if ((~(*pFormation)->stat & 3) != 0)
  hunit = (*pFormation)->hunit;
  if (!hunit)
  modelRoot = hunit->Model->modelRoot;
  if (!sdfModelGetMarkPosUnity(modelRoot, mark))
  {
    SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
    ToMatrix();
    SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
    SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
    SDF_VU0__ADDVECTOR();
  }
}

// 0x14bcc70
void effBTLModelGetMarkPosition3(dds3ModelHandle_t *hModel, u32 mark) {
    sdfModelGetMarkPosUnity(0, 0);
    mdlGetPosition(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
}

// 0x14bcd60
s32 effBTLModelGetMarkPositionEvalTm(nbFormation_t **pFormation, u32 mark) {
  struct evtUnitHandle_t_o *hunit;
  sdfModelRootNode_t_o *modelRoot;

  if ((~(*pFormation)->stat & 3) != 0)
    return 0;
  hunit = (*pFormation)->hunit;
  if (!hunit)
    return 0;
  modelRoot = hunit->Model->modelRoot;
  return sdfModelGetMarkPosUnity(modelRoot, mark);
}

// 0x14bd7b0
void effBTLModelGetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos) {
  if ((~(*pFormation)->stat & 3) == 0)
  {
    nbGetFormPos(pFormation);
    SDF_VU0__STOREVECTOR(pPos);
  }
}

// 0x14bf550
void effBTLModelGetPosition2(nbFormation_t **pFormation, sdfVector4_t *pPos) {
  dds3ModelHandle_t_o **p_Model;

  if ((~(*pFormation)->stat & 3) == 0)
  {
    p_Model = &(*pFormation)->hunit->Model;
    mdlGetPosition(p_Model);
    SDF_VU0__STOREVECTOR(pPos);
  }
}

// 0x14bc400
f32 effBTLModelGetRadius(nbFormation_t **pFormation) {
  f32 r;

  r = (*pFormation)->r;
  if (r <= (*pFormation)->h)
    r = (*pFormation)->h;
  return (*pFormation)->scl * r;
}

// 0x14bf610
void effBTLModelGetRotate(nbFormation_t **pFormation, sdfVector4_t *pRot) {
  if ((~(*pFormation)->stat & 3) == 0)
  {
    nbGetFormRot(pFormation);
    SDF_VU0__STOREVECTOR(pRot);
  }
}

// 0x14bc380
void effBTLModelGetSphereCenter(nbFormation_t **pFormation) {
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
  SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
  SDF_VU0__ADDVECTOR();
}

// 0x14c1b90
u32 effBTLModelGetTargetGroupNumber(void) {
  u32 TargetParty;
  nbMainProcessData_t_o *MainProcessData;
  u64 v5;
  u32 v6;
  struct nbFormation_t_array *form;
  Il2CppClass **v9;

  TargetParty = effBTLSkillGetTargetParty();
  MainProcessData = nbGetMainProcessData();
  v5 = 0;
  v6 = 0;
  do
  {
    form = MainProcessData->form;
    v9 = &form->obj.klass + v5++;
    v6 += (v9[4]->_1.events & TargetParty) != 0 && (~LODWORD(v9[4]->_1.events) & 3) == 0;
  }
  while (v5 != 32);
  return v6;
}

// 0x14bca20
f32 effBTLModelGetWidth(nbFormation_t **pFormation) {
  return (*pFormation)->r * (*pFormation)->scl;
}

// 0x14bfe60
void effBTLModelGroupDiameterDisposition(u32 group) {
    nbGetMainProcessData();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    nbSetFormPos(0, (sdfVector4_t){0});
    nbGetFormPos(0);
}

// 0x14bcfd0
void effBTLModelGroupGetCenter(u32 group) {
    nbGetMainProcessData();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__MULVECTOR();
}

// 0x14be5a0
void effBTLModelGroupGetDirection(u32 group, sdfVector4_t *pDirection) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x14bd3c0
f32 effBTLModelGroupGetLineMaxLength(sdfVector4_t *pVec, sdfVector4_t *pPos, u32 group) {
    nbGetMainProcessData();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effLinePointLength((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    return 0;
}

// 0x14bd1f0
f32 effBTLModelGroupGetMaxLength(sdfVector4_t *pPos, u32 group) {
  f32 v5;
  nbMainProcessData_t_o *MainProcessData;
  u64 v8;
  s32 v9;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v12;
  f32 scl;
  f32 r;
  f32 h;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 result;

  v5 = 0.0;
  MainProcessData = nbGetMainProcessData();
  v8 = 0;
  v9 = 0;
  do
  {
    form = MainProcessData->form;
    v12 = form->m_Items[v8];
    if ((v12->stat & 3) == 3 && (v12->stat & group) != 0)
    {
      SDF_VU0__LOADVECTOR(v12->rot);
      ToMatrix();
      SDF_VU0__LOADVECTOR(v12->center);
      SDF_VU0__SCALEVECTOR(v12->scl);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__LOADVECTOR_B(v12->pos);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__LOADVECTOR_B(*pPos);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__GETLENGTH();
      scl = v12->scl;
      r = v12->r;
      h = v12->h;
      v17 = h * 0.5;
      v18 = (h * scl) * 0.5;
      if (r <= v17)
        v19 = v18;
      else
        v19 = r * scl;
      v20 = v19 + 0.0;
      if (v20 > v5)
        v5 = v20;
      ++v9;
    }
    ++v8;
  }
  while (v8 != 32);
  result = v5 * 1.33;
  if (v9 != 1)
    return v5;
  return result;
}

// 0x14bd860
f32 effBTLModelGroupGetSphere(u32 group) {
  return effBTLModelGroupGetSphereExp(group, 1u);
}

// 0x14bd920
f32 effBTLModelGroupGetSphere2(u32 group) {
  return effBTLModelGroupGetSphereExp(group, 1u);
}

// 0x14bda60
f32 effBTLModelGroupGetSphereExp(u32 group, u32 model) {
    nbGetMainProcessData();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0x14bd990
f32 effBTLModelGroupGetSphereOld(u32 group) {
    effBTLModelGroupGetCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGroupGetMaxLength(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    return 0;
}

// 0x14bdd80
f32 effBTLModelGroupGetVectorSphere(u32 group, sdfVector4_t *pTarget, sdfVector4_t *pEye) {
    nbGetMainProcessData();
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    MultMatrixRev(0);
    SDF_VU0__STOREMATRIX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__PERSVECTOR();
    SDF_VU0__MULVECTOR();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__COPYVECTOR_C_TO_A();
    return 0;
}

// 0x14bd5a0
f32 effBTLModelGroupGetWidthX(u32 group) {
    nbGetMainProcessData();
    nbGetFormPos(0);
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0x14bec70
void effBTLModelGroupLook(u32 group, sdfVector4_t *pPos) {
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[i];
    if ((pFormation->stat & 3) == 3 && (pFormation->stat & group) != 0)
    {
      effBTLModelLook(&pFormation, pPos);
    }
  }
}

// 0x14bf990
void effBTLModelGroupPopPosition(u32 group) {
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *v6;
  nbFormation_t_o *v8;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o v15;

  form = 0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    v6 = MainProcessData->form;
    v8 = v6->m_Items[i];
    form = v8;
    if ((v8->stat & 3) == 3 && (v8->stat & group) != 0)
    {
      else if ((byte_3F59A64 & 1) != 0)
      {
        x = v8->orgpos.x;
        y = v8->orgpos.y;
        z = v8->orgpos.z;
        w = v8->orgpos.w;
        v15.x = x;
        v15.y = y;
        v15.z = z;
        v15.w = w;
        nbSetFormPos(&form, v15);
        continue;
      }
    }
  }
}

// 0x14bfb20
void effBTLModelGroupRotate(u32 group, f32 angle) {
    nbGetMainProcessData();
    SetRotateMatrixY(0);
    SDF_VU0__STOREMATRIX(0);
    effBTLModelGroupGetCenter(0);
    SDF_VU0__STOREVECTOR(0);
    nbGetFormPos(0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    nbSetFormPos(0, (sdfVector4_t){0});
}

// 0x14c0290
void effBTLModelHide(nbFormation_t **pFormation) {
  struct System_Byte_array *effBTLModelShowFlag;
  s64 formindex;

  formindex = (*pFormation)->formindex;
  effBTLModelShowFlag->m_Items[formindex] = 0;
}

// 0x14c1020
void effBTLModelInvokeGroupHide(void) {
  nbMainProcessData_t_o *MainProcessData;
  u32 v5;
  nbFormation_t_o *v8;
  u64 v9;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v12;
  struct System_Byte_array *v15;
  s64 formindex;
  char v18;
  char *v19;
  struct System_Byte_array *effBTLModelShowFlag;

  MainProcessData = nbGetMainProcessData();
  v5 = effBTLSkillGetInvokeParty();
  if (v5 != 512 || MainProcessData->formationtype != 4)
  {
    v8 = effBTLSkillGetInvokeFormation(0);
    v9 = 0;
    while (1)
    {
      form = MainProcessData->form;
      v12 = form->m_Items[v9];
      if ((v12->stat & 3) != 3 || (v12->stat & v5) == 0)
      if (v12 == v8)
      {
        else        v19 = &effBTLModelShowFlag->m_Items[v8->formindex];
        v18 = 1;
      }
        break;
      if ((byte_3F59A6B & 1) == 0)
      v15 = effBTLModelShowFlag;
      formindex = v12->formindex;
      v18 = 0;
      v19 = &v15->m_Items[formindex];
      *v19 = v18;
      if (++v9 == 32)
        return;
    }
    if ((byte_3F59A6B & 1) != 0)
  }
  effBTLModelInvokePartyShow();
}

// 0x14c0d80
void effBTLModelInvokeHide(void) {
  nbFormation_t_o *v3;
  struct System_Byte_array *effBTLModelShowFlag;
  s64 formindex;

  v3 = effBTLSkillGetInvokeFormation(0);
  formindex = v3->formindex;
  effBTLModelShowFlag->m_Items[formindex] = 0;
}

// 0x14c1720
void effBTLModelInvokePartyHide(void) {
    effBTLSkillGetInvokeParty();
    nbGetMainProcessData();
}

// 0x14c0a50
void effBTLModelInvokePartyShow(void) {
    effBTLSkillGetInvokeParty();
    nbGetMainProcessData();
}

// 0x14c0880
void effBTLModelInvokeShow(void) {
  nbFormation_t_o *v5;
  struct System_Byte_array *effBTLModelShowFlag;
  s64 formindex;

  if (nbGetMainProcessData()->formationtype == 4)
  {
    else if (effBTLSkillGetInvokeParty() == 512)
    {
      effBTLModelInvokePartyShow();
      return;
    }
  }
  v5 = effBTLSkillGetInvokeFormation(0);
  formindex = v5->formindex;
  effBTLModelShowFlag->m_Items[formindex] = 1;
}

// 0x14be720
void effBTLModelLook(nbFormation_t **pFormation, sdfVector4_t *pTargetPos) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    sdfAtan2(0, 0);
    FromEuler(0, 0, 0);
    nbSetFormRot(0, (sdfVector4_t){0}, 0);
}

// 0x14be970
void effBTLModelLook2(nbFormation_t **pFormation, sdfVector4_t *pTargetPos, f32 angle) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    sdfSin(0);
    sdfCos(0);
    sdfFabs(0);
    sdfAtan2(0, 0);
    FromEuler(0, 0, 0);
    nbSetFormRot(0, (sdfVector4_t){0}, 0);
}

// 0x14bf4b0
void effBTLModelSetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v9;

  x = pPos->x;
  y = pPos->y;
  z = pPos->z;
  w = pPos->w;
  v9.x = x;
  v9.y = y;
  v9.z = z;
  v9.w = w;
  nbSetFormPos(pFormation, v9);
}

// 0x14bf600
void effBTLModelSetRotate(nbFormation_t **pFormation, sdfVector4_t *pRot) {
  ;
}

// 0x14c01f0
void effBTLModelShow(nbFormation_t **pFormation) {
  struct System_Byte_array *effBTLModelShowFlag;
  s64 formindex;

  formindex = (*pFormation)->formindex;
  effBTLModelShowFlag->m_Items[formindex] = 1;
}

// 0x14c0100
void effBTLModelShowInit(void) {
  struct System_Byte_array *v2;
  u64 v4;
  struct System_Byte_array *effBTLModelShowFlag;
  char *v8;

  v2 = NewSpecific(byte, 0x20u);
  v4 = 0;
  effBTLModelShowFlag = v2;
  do
  {
    v8 = effBTLModelShowFlag + v4++;
    v8[32] = -1;
  }
  while (v4 != 32);
}

// 0x14c0330
void effBTLModelShowRun(void) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v4;
  u64 v5;
  struct nbFormation_t_array *v6;
  nbFormation_t_o *v8;
  struct System_Byte_array *effBTLModelShowFlag;
  u32 formindex;
  struct System_Byte_array *v15;
  struct System_Byte_array *v17;
  nbFormation_t_o *form;

  form = 0;
  else
  {
    MainProcessData = nbGetMainProcessData();
    if (MainProcessData)
    {
      v4 = MainProcessData;
      v5 = 0;
      while (1)
      {
        v6 = v4->form;
        v8 = v6->m_Items[v5];
        form = v8;
        formindex = v8->formindex;
        if (effBTLModelShowFlag->m_Items[formindex] == 1)
          break;
        v15 = effBTLModelShowFlag;
        if (!v15->m_Items[form->formindex])
        {
          nbFormDispOff2(&form);
        }
        v17 = effBTLModelShowFlag;
        ++v5;
        v17->m_Items[form->formindex] = -1;
        if (v5 == 32)
          return;
      }
      nbFormDispOn2(&form);
    }
  }
}

// 0x14c1300
void effBTLModelTargetGroupHide(void) {
    effBTLSkillGetTargetParty();
    effBTLSkillGetTargetBit();
    nbGetMainProcessData();
}

// 0x14c0ea0
void effBTLModelTargetHide(void) {
  u32 TargetNumber;
  u32 v4;
  u32 v5;
  nbFormation_t_o *TargetFormation;
  struct System_Byte_array *effBTLModelShowFlag;
  s64 formindex;

  else
  {
    TargetNumber = effBTLSkillGetTargetNumber();
    if (TargetNumber)
    {
      v4 = TargetNumber;
      v5 = 0;
      while (1)
      {
        TargetFormation = effBTLSkillGetTargetFormation(v5);
          break;
        if ((byte_3F59A6B & 1) == 0)
        formindex = TargetFormation->formindex;
        ++v5;
        effBTLModelShowFlag->m_Items[formindex] = 0;
        if (v4 == v5)
          return;
      }
      if ((byte_3F59A6B & 1) != 0)
    }
  }
}

// 0x14c18d0
void effBTLModelTargetPartyHide(void) {
    effBTLSkillGetTargetParty();
    nbGetMainProcessData();
}

// 0x14c1570
void effBTLModelTargetPartyShow(void) {
    effBTLSkillGetTargetParty();
    nbGetMainProcessData();
}

// 0x14c0c00
void effBTLModelTargetShow(void) {
  u32 TargetNumber;
  u32 v4;
  u32 v5;
  nbFormation_t_o *TargetFormation;
  struct System_Byte_array *effBTLModelShowFlag;
  s64 formindex;

  else
  {
    TargetNumber = effBTLSkillGetTargetNumber();
    if (TargetNumber)
    {
      v4 = TargetNumber;
      v5 = 0;
      while (1)
      {
        TargetFormation = effBTLSkillGetTargetFormation(v5);
          break;
        if ((byte_3F59A6A & 1) == 0)
        formindex = TargetFormation->formindex;
        ++v5;
        effBTLModelShowFlag->m_Items[formindex] = 1;
        if (v4 == v5)
          return;
      }
      if ((byte_3F59A6A & 1) != 0)
    }
  }
}

// 0x14c3d60
void effBTLPartDebugPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
    effBTLPartGetPositionPtr(0, 0, 0);
}

// 0x14bbc50
u32 effBTLPartGetFadeFramePtr(u32 PtrNum) {
    return 0;
}

// 0x14c3160
void effBTLPartGetInvokePartyPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
  u32 v6;

  v6 = effBTLSkillGetInvokeParty();
  effBTLPartGetPartyPositionPtr(v6, pPosPtr);
}

// 0x14c3650
void effBTLPartGetModelMarkPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
  nbFormation_t_o *v6;
  u32 id;
  u32 v8;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u32 v11;
  s32 height;
  struct evtUnitHandle_t_o *hunit;
  sdfModelRootNode_t_o *modelRoot;

  else  if ((*pPosPtr)->height > 1u)
  v6 = *pFormation;
  if (*pFormation && (v6->stat & 1) != 0)
  {
    formindex = v6->formindex;
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if ((UnitWorkFromFormindex->flag & 4) != 0)
      id = 0;
    else
      id = UnitWorkFromFormindex->id;
  }
  else
  {
    id = 512;
  }
  else
  {
    v8 = effBTLSkillGetID();
    if (id <= 0x103)
    {
      if (id != 258 && id != 259)
      SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
      ToMatrix();
      SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
      SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
      SDF_VU0__ADDVECTOR();
      return;
    }
  }
  v11 = v8;
  if (id != 264)
  {
    if (id == 291 || id == 292)
    if (id != 293)
    {
      if (id != 321)
    }
  }
  if (!effBTLSkillCheckRun() || v11 - 221 > 0x21 || ((1LL << (v11 + 35)) & 0x200100001LL) == 0)
  height = (*pPosPtr)->height;
  if ((~(*pFormation)->stat & 3) != 0)
  hunit = (*pFormation)->hunit;
  if (!hunit)
  modelRoot = hunit->Model->modelRoot;
  if (!sdfModelGetMarkPosUnity(modelRoot, height))
}

// 0x14c29f0
void effBTLPartGetModelPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
    effBTLPartPtrGetModelCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SetRotateMatrixY_B(0);
    MultMatrixNoArg();
    SDF_VU0__APPLYMATRIX_XYZ();
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    ReverseMatrix();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
}

// 0x14c2e40
void effBTLPartGetPartyPositionPtr(u32 group, effBTL_SkillPositionPtr_t **pPosPtr) {
    nbGetMainProcessData();
    effBTLPartPtrModelGroupGetCenterAndHeight(0, 0, 0, 0, 0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
}

// 0x14bbd40
void effBTLPartGetPointLightPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pDir) {
    effBTLPartGetPositionPtr(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x14c2530
void effBTLPartGetPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pPos) {
  struct effBattleMisc_effBTLPartfunc_t_array *GetPositionPtrTable;
  s64 target;

  target = (*pPosPtr)->target;
  Invoke(
    GetPositionPtrTable->m_Items[target]->func,
    pFormation,
    pPosPtr);
  SDF_VU0__STOREVECTOR(pPos);
}

// 0x14c39a0
f32 effBTLPartGetRadiusPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetParty();
    effBTLModelGroupGetCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGroupGetMaxLength(0, 0);
    return 0;
}

// 0x14c3b40
void effBTLPartGetRotateMatrixPtr(effBTL_SkillPositionPtr_t **pPosPtr, sdfMatrix4_t *pMatrix) {
  s32 height;
  s64 direction;
  dds3KernelDraw_c *v7;
  struct dds3KernelDraw_StaticFields *static_fields;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  f32 v16;
  f32 v17;
  struct System_Single_array *effBTL_Ptr_D;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o dds3CameraTargetPos;
  UnityEngine_Vector4_o v27;

  height = (*pPosPtr)->height;
  if (height == 4 || (direction = (*pPosPtr)->direction, direction == 9))
  {
    static_fields = v7->static_fields;
    dds3CameraTargetPos = static_fields->dds3CameraTargetPos;
    x = static_fields->dds3CameraEyePos.x;
    y = static_fields->dds3CameraEyePos.y;
    z = static_fields->dds3CameraEyePos.z;
    w = static_fields->dds3CameraEyePos.w;
    v27.x = x;
    v27.y = y;
    v27.z = z;
    v27.w = w;
    *&v25.x = 0;
    *&v25.z = pMatrix;
    LookAtMatrix(dds3CameraTargetPos, v27, v25);
    ReverseMatrix();
    SDF_VU0__RESET_ROW3();
  }
  if (height != 3 && height != 5 && (direction | 2) != 0xA)
  {
    v16 = 0.0;
    if (direction > 8)
    v17 = effBTL_Ptr_D->m_Items[direction];
  }
  v16 = 1.5708;
  if (direction <= 8)
  v17 = 0.0;
  SetRotateMatrixX(v16);
  SetRotateMatrixY_B(v17);
  MultMatrixRevNoArg();
  SDF_VU0__STOREMATRIX(pMatrix);
}

// 0x14c1e20
f32 effBTLPartGetScalePtr(nbFormation_t **pFormation) {
  nbFormation_t_o *v3;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u32 id;
  u32 v7;
  f32 result;
  f32 v9;

  v3 = *pFormation;
  if (*pFormation && (v3->stat & 1) != 0)
  {
    formindex = v3->formindex;
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if ((UnitWorkFromFormindex->flag & 4) == 0)
    {
      id = UnitWorkFromFormindex->id;
      if (id > 0x108)
      {
        if (id > 0x125)
        {
          result = 3.0;
          if (id == 321 || id == 344)
            return result;
        }
        else
        {
          if (id == 274)
            return 2.7;
          if (id - 291 < 3)
            return 3.0;
        }
      }
      else
      {
        v7 = id - 258;
        if (v7 <= 6 && ((1 << v7) & 0x43) != 0)
          return 3.0;
      }
    }
  }
  v9 = ((*pFormation)->scl * (((*pFormation)->r + ((*pFormation)->h * 0.5)) * 0.5)) * 0.014286;
  result = 2.0;
  if (v9 <= 2.0)
    return fmaxf(v9, 0.8);
  return result;
}

// 0x14c1dd0
f32 effBTLPartGetScalePtrSub(nbFormation_t **pFormation) {
  f32 v2;

  v2 = ((*pFormation)->scl * (((*pFormation)->r + ((*pFormation)->h * 0.5)) * 0.5)) * 0.014286;
  if (v2 > 2.0)
    return 2.0;
  else
    return fmaxf(v2, 0.8);
}

// 0x14c3200
void effBTLPartGetTargetPartyPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
  u32 TargetParty;

  TargetParty = effBTLSkillGetTargetParty();
  effBTLPartGetPartyPositionPtr(TargetParty, pPosPtr);
}

// 0x14c32a0
void effBTLPartGetWorldPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
    nbGetMainProcessData();
    SetRotateMatrixY(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    dds3GetActiveScene();
    dds3GetActiveCameraSceneBasic(0);
    dds3CameraObjectBasicGetTargetPos(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    dds3GetPosPoseSet(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
}

// 0x14c2000
void effBTLPartPtrGetAllModelCenterOffset(void) {
    nbGetMainProcessData();
    nbGetUnitWorkFromFormindex(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__SUBVECTOR();
    InversMatrix();
}

// 0x14bf330
void effBTLPartPtrGetModelCenter(nbFormation_t **pFormation) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__APPLYMATRIX_B();
}

// 0x14befb0
void effBTLPartPtrModelGroupGetCenterAndHeight(u32 group, sdfVector4_t *pCenter, f32 *pHeightAve, f32 *pHeightMax, f32 *pFrontMax) {
    nbGetMainProcessData();
    effBTLPartPtrGetModelCenter(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
}

// 0x14c23f0
void effBTLPartPtrResetAllModelCenterOffset(void) {
    nbGetMainProcessData();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
}

// 0x14bc350
void effDebugLineDraw(sdfVector4_t pPos0, sdfVector4_t pPos1) {
  ;
}

// 0x14bc360
void effDebugPointDraw(sdfVector4_t pPos) {
  ;
}

// 0x14bc340
void effDebugPointDraw2(sdfVector4_t pPos, u32 color) {
  ;
}

// 0x14bc370
s32 sdfModelCheckBounds(f32 **aMinMax) {
  return 0;
}
