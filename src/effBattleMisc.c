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

static u8 *effBTLModelShowFlag;
static u32 effBTL_Ptr_FadeFrame[4];
static f32 effBTL_Ptr_H[6];
static f32 effBTL_Ptr_D[11];
static sdfVector4_t *effBTLPartPtrModelCenterOffset;
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
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v7;

  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v7 = form->m_Items[i];
    if ((~v7->stat & 3) == 0)
    {
      else if ((byte_3F59A6B & 1) != 0)
      {
        goto LABEL_16;
      }
      goto LABEL_16;
    }
  }
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
LABEL_16:
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
      goto LABEL_16;
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
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v7;

  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v7 = form->m_Items[i];
    if ((~v7->stat & 3) == 0)
    {
      else if ((byte_3F59A6A & 1) != 0)
      {
        goto LABEL_16;
      }
      goto LABEL_16;
    }
  }
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
  u64 *v12;
  s64 v13;
  struct evtUnitHandle_t_o *hunit;
  u64 *v16;
  f32 z;
  f32 v19;
  f32 x;
  f32 y;
  f32 v25;
  struct sdf3DScreenParam_t_o *dds3ScreenParam;
  s64 v27;
  s64 v28;
  s64 v29;
  s64 v30;
  s64 v31;
  s64 v32;
  s64 v33;
  u32 v35;
  f32 v36;
  f32 v37;
  UnityEngine_Matrix4x4_o v48;
  UnityEngine_Matrix4x4_o v49;
  UnityEngine_Vector4_o p;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;

  *&p.x = 0;
  *&p.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  v12 = NewSpecific(f32, 6u);
  if ((~(*pFormation)->stat & 3) == 0)
  {
    hunit = (*pFormation)->hunit;
    if (hunit)
    {
      if (hunit->Model)
      {
        v16 = v12;
        v53.x = pTarget->x;
        v53.y = pTarget->y;
        z = pTarget->z;
        v19 = pTarget->w;
        x = pEye->x;
        y = pEye->y;
        v54.z = pEye->z;
        v54.w = pEye->w;
        v53.z = z;
        v53.w = v19;
        v54.x = x;
        v54.y = y;
        *&v52.x = 0;
        *&v52.z = v13;
        LookAtMatrix(v53, v54, v52);
        {
          v25 = w;
        }
        else
        {
          v25 = w;
        }
        v27 = *&dds3ScreenParam->TM.m00;
        v28 = *&dds3ScreenParam->TM.m20;
        v29 = *&dds3ScreenParam->TM.m21;
        *&v49.m01 = *&dds3ScreenParam->TM.m01;
        *&v49.m21 = v29;
        *&v49.m00 = v27;
        *&v49.m20 = v28;
        v30 = *&dds3ScreenParam->TM.m02;
        v31 = *&dds3ScreenParam->TM.m22;
        v33 = *&dds3ScreenParam->TM.m03;
        v32 = *&dds3ScreenParam->TM.m23;
        *&v49.m03 = v33;
        *&v49.m23 = v32;
        *&v49.m02 = v30;
        *&v49.m22 = v31;
        MultMatrixRev(&v49);
        SDF_VU0__STOREMATRIX(&aMatrix);
        SDF_VU0__LOADVECTOR((*pFormation)->pos, 0);
        SDF_VU0__VECTOR_W_SET_ONE();
        SDF_VU0__STOREVECTOR(&p);
        SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
        ToMatrix();
        SDF_VU0__LOAD_ROW3(p);
        v48 = aMatrix;
        MultMatrixRev(&v48);
        v35 = *(v16 + 6);
        v36 = -v25;
        v37 = -h;
        *(v16 + 8) = v36;
        *(v16 + 9) = v37;
        *(v16 + 10) = v36;
        *(v16 + 11) = v25;
        *(v16 + 12) = 0;
        *(v16 + 13) = v25;
      }
    }
  }
}

// 0x14c1d50
u32 effBTLModelGetBadStatus(nbFormation_t **pFormation) {
  s32 formindex;

  formindex = (*pFormation)->formindex;
  return nbGetUnitWorkFromFormindex(formindex)->badstatus;
}

// 0x14bc630
void effBTLModelGetCircumference(nbFormation_t **pFormation, sdfVector4_t *pDirection) {
  UnityEngine_Vector4_o v5;

  *&v5.x = 0;
  *&v5.z = 0;
  sub_854690(&v5.x, 0.0, 0.0, 0.0, 0.0);
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR(*pDirection);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
  SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
  SDF_VU0__ADDVECTOR();
  v5.x = (*pFormation)->r;
  v5.y = v5.x;
  v5.z = v5.x;
  SDF_VU0__SWAPVECTOR_A_C();
  SDF_VU0__LOADVECTOR_B(v5);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__ADDVECTOR();
}

// 0x14bc740
void effBTLModelGetCircumferencePtr(nbFormation_t **pFormation, u16 ptr_y, u16 ptr_x) {
  System_Array_o *v7;
  f32 v10;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  *&v14.x = 0;
  *&v14.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v14.x, 0.0, 0.0, 1.0, 0.0);
  v7 = NewSpecific(f32, 8u);
  InitializeArray_1543888(v7, Field__PrivateImplementationDetails__38B2831ABB719391961B26A24600D092452BE39D);
  v10 = *(&v7[2].klass + ptr_x);
  SetRotateMatrixX(v10);
  SetRotateMatrixY_B(*(&v7[2].klass + ptr_y), 0);
  MultMatrixRevNoArg();
  SDF_VU0__LOADVECTOR(v14);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelGetCircumference(pFormation, &p);
}

// 0x14bc420
void effBTLModelGetDirection(nbFormation_t **pFormation, sdfVector4_t *pDirection) {
  f32 *v5;
  s32 v6;
  s32 v7;
  s32 v8;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  u32 stat;
  s64 v21;
  s64 v22;
  s64 v23;
  s64 v24;
  UnityEngine_Vector4_o v25;

  v23 = 0;
  v24 = 0;
  v5 = NewSpecific(UnityEngine_Vector4, 2u);
  sub_854690(&v23, 0.0, 0.0, 1.0, 0.0);
  v6 = HIDWORD(v23);
  v8 = v24;
  v7 = HIDWORD(v24);
  *(v5 + 8) = v23;
  *(v5 + 9) = v6;
  *(v5 + 10) = v8;
  *(v5 + 11) = v7;
  v21 = 0;
  v22 = 0;
  sub_854690(&v21, 0.0, 0.0, -1.0, 0.0);
  v11 = *&v21;
  v10 = *(&v21 + 1);
  v13 = *&v22;
  v12 = *(&v22 + 1);
  *(v5 + 12) = v21;
  v5[13] = v10;
  v5[14] = v13;
  v5[15] = v12;
  stat = (*pFormation)->stat;
  if ((stat & 0x100) != 0)
  {
    v25 = *(v5 + 2);
  }
  else
  {
    if ((stat & 0x200) == 0)
      return;
    v25.x = v11;
    v25.y = v10;
    v25.z = v13;
    v25.w = v12;
  }
  SDF_VU0__COPYVECTOR(pDirection, v25);
}

// 0x14bc5b0
void effBTLModelGetDirection2(nbFormation_t **pFormation) {
  UnityEngine_Vector4_o v3;

  *&v3.x = 0;
  sub_854690(&v3.x, 0.0, 0.0, 1.0, 0.0);
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR(v3);
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
        goto LABEL_18;
        break;
      Height = effBTLModelGetHeight(&pFormation);
      if (v7)
        goto LABEL_21;
LABEL_16:
      if (v3 < Height)
        goto LABEL_21;
      v7 = 0;
LABEL_18:
      if (++v6 == 32)
        return v3;
    }
    Height = effBTLModelGetHeight(&pFormation);
    if (!v7)
      goto LABEL_16;
LABEL_21:
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
  UnityEngine_Vector4_o v5;

  *&v5.x = 0;
  *&v5.z = 0;
  sub_854690(&v5.x, 0.0, 0.0, 0.0, 0.0);
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
  SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v5);
  return (((*pFormation)->h * (*pFormation)->scl) * 0.5) - v5.y;
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

LABEL_7:
  if ((~(*pFormation)->stat & 3) != 0)
    goto LABEL_13;
  hunit = (*pFormation)->hunit;
  if (!hunit)
    goto LABEL_13;
  modelRoot = hunit->Model->modelRoot;
  if (!sdfModelGetMarkPosMatrixUnity(modelRoot, mark))
LABEL_13:
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

LABEL_7:
  if ((~(*pFormation)->stat & 3) != 0)
    goto LABEL_13;
  hunit = (*pFormation)->hunit;
  if (!hunit)
    goto LABEL_13;
  modelRoot = hunit->Model->modelRoot;
  if (!sdfModelGetMarkPosUnity(modelRoot, mark))
  {
LABEL_13:
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
  sdfModelRootNode_t_o *modelRoot;
  UnityEngine_Vector4_o v8;
  dds3ModelHandle_t_o *aHandle;

  aHandle = hModel;
  *&v8.x = 0;
  *&v8.z = 0;
  sub_854690(&v8.x, 0.0, 0.0, 0.0, 0.0);
  if (hModel)
  {
    modelRoot = hModel->modelRoot;
    if (!sdfModelGetMarkPosUnity(modelRoot, mark))
    {
      mdlGetPosition(&aHandle);
    }
  }
  else
  {
    SDF_VU0__LOADVECTOR(v8);
  }
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
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *v8;
  f32 z;
  f32 x;
  UnityEngine_Vector4_o pos;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *form;

  *&p.z = 0;
  form = 0;
  *&pos.z = 0;
  *&p.x = 0;
  *&pos.x = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&pos.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  effBTLModelGroupGetSphere(group);
  SDF_VU0__STOREVECTOR(&p);
  for (i = 0; i != 32; ++i)
  {
    v8 = MainProcessData->form;
    form = v8->m_Items[i];
    if ((form->stat & 3) == 3 && (form->stat & group) != 0)
    {
      else if ((byte_3F59A65 & 1) != 0)
      {
        goto LABEL_22;
      }
      goto LABEL_22;
    }
  }
}

// 0x14bcfd0
void effBTLModelGroupGetCenter(u32 group) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v6;
  u64 v7;
  u32 v8;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v11;
  f32 v13;
  f32 v14;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  *&v15.x = 0;
  *&v15.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v15.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  p.z = 0.0;
  *&p.x = 0;
  v6 = MainProcessData;
  v7 = 0;
  v8 = 0;
  do
  {
    form = v6->form;
    v11 = form->m_Items[v7];
    if ((v11->stat & 3) == 3 && (v11->stat & group) != 0)
    {
      SDF_VU0__LOADVECTOR(v11->rot);
      ToMatrix();
      SDF_VU0__LOADVECTOR(v11->center);
      SDF_VU0__SCALEVECTOR(v11->scl);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__LOADVECTOR_B(v11->pos);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__ADDVECTOR_B_A();
      SDF_VU0__STOREVECTOR_B(&p);
      ++v8;
    }
    ++v7;
  }
  while (v7 != 32);
  if (v8)
  {
    v13 = v8;
    v14 = 1.0 / v13;
  }
  else
  {
    v14 = 1.0;
  }
  v15.x = v14;
  v15.y = v14;
  v15.z = v14;
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v15);
  SDF_VU0__MULVECTOR();
}

// 0x14be5a0
void effBTLModelGroupGetDirection(u32 group, sdfVector4_t *pDirection) {
  s16 v4;
  f32 *v5;
  s32 v6;
  s32 v7;
  s32 v8;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  UnityEngine_Vector4_o v24;

  v4 = group;
  v22 = 0;
  v23 = 0;
  v5 = NewSpecific(UnityEngine_Vector4, 2u);
  sub_8546D0(&v22, 0.0, 0.0, 1.0);
  v6 = HIDWORD(v22);
  v8 = v23;
  v7 = HIDWORD(v23);
  *(v5 + 8) = v22;
  *(v5 + 9) = v6;
  *(v5 + 10) = v8;
  *(v5 + 11) = v7;
  v20 = 0;
  v21 = 0;
  sub_8546D0(&v20, 0.0, 0.0, -1.0);
  v11 = *&v20;
  v10 = *(&v20 + 1);
  v13 = *&v21;
  v12 = *(&v21 + 1);
  *(v5 + 12) = v20;
  v5[13] = v10;
  v5[14] = v13;
  v5[15] = v12;
  if ((v4 & 0x100) != 0)
  {
    v24 = *(v5 + 2);
  }
  else
  {
    if ((v4 & 0x200) == 0)
      return;
    v24.x = v11;
    v24.y = v10;
    v24.z = v13;
    v24.w = v12;
  }
  SDF_VU0__COPYVECTOR(pDirection, v24);
}

// 0x14bd3c0
f32 effBTLModelGroupGetLineMaxLength(sdfVector4_t *pVec, sdfVector4_t *pPos, u32 group) {
  f32 v7;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v14;
  f32 v17;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v20;

  v7 = 0.0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v14 = form->m_Items[i];
    if ((v14->stat & 3) == 3 && (v14->stat & group) != 0)
    {
      SDF_VU0__LOADVECTOR(v14->rot);
      ToMatrix();
      SDF_VU0__LOADVECTOR(v14->center);
      SDF_VU0__SCALEVECTOR(v14->scl);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__LOADVECTOR_B(v14->pos);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&p);
      *&v20.x = 0;
      v17 = effLinePointLength(*pVec, *pPos, v20) + (v14->r * v14->scl);
      if (v17 > v7)
        v7 = v17;
    }
  }
  return v7;
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
LABEL_7:
  return effBTLModelGroupGetSphereExp(group, 1u);
}

// 0x14bd920
f32 effBTLModelGroupGetSphere2(u32 group) {
  return effBTLModelGroupGetSphereExp(group, 1u);
}

// 0x14bda60
f32 effBTLModelGroupGetSphereExp(u32 group, u32 model) {
  f32 v5;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  nbMainProcessData_t_o *MainProcessData;
  u64 v14;
  s32 v15;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v18;
  u32 stat;
  bool v20;
  f32 scl;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  UnityEngine_Vector4_o v35;
  UnityEngine_Vector4_o v36;

  v5 = 0.0;
  *&v35.x = 0;
  *&v35.z = 0;
  sub_854690(&v35.x, 0.0, 0.0, 0.0, 0.0);
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0.0;
  MainProcessData = nbGetMainProcessData();
  v14 = 0;
  v15 = 1;
  do
  {
    while (1)
    {
      while (1)
      {
        form = MainProcessData->form;
        v18 = form->m_Items[v14];
        stat = v18->stat;
        v20 = (stat & group) == 0 || (v18->stat & 1) == 0;
        if (v20 || model && (stat & 2) == 0)
          goto LABEL_45;
        SDF_VU0__LOADVECTOR(v18->rot);
        ToMatrix();
        SDF_VU0__LOADVECTOR(v18->center);
        SDF_VU0__SCALEVECTOR(v18->scl);
        SDF_VU0__APPLYMATRIX();
        SDF_VU0__LOADVECTOR_B(v18->pos);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&v35);
        scl = v18->scl;
        v22 = v18->r * scl;
        v23 = v35.x + v22;
        v24 = v35.x - v22;
        v25 = v22 + v35.z;
        v26 = v35.z - v22;
        v27 = ((scl * v18->h) * 0.5) - v35.y;
        if (v15)
          break;
        if (v5 < v22)
          v5 = v22;
        if (v8 >= v23)
          v28 = v8;
        else
          v28 = v35.x + v22;
        if (v7 <= v23)
          v23 = v7;
        if (v28 >= v24)
          v8 = v28;
        else
          v8 = v24;
        if (v23 <= v24)
          v7 = v23;
        else
          v7 = v24;
        if (v10 >= v25)
          v29 = v10;
        else
          v29 = v25;
        if (v9 <= v25)
          v25 = v9;
        if (v29 >= v26)
          v10 = v29;
        else
          v10 = v26;
        if (v25 <= v26)
          v9 = v25;
        else
          v9 = v26;
        v15 = 0;
        if (v11 < v27)
          v11 = v27;
LABEL_45:
        if (++v14 == 32)
          goto LABEL_57;
      }
      v8 = v23 <= v24 ? v35.x - v22 : v35.x + v22;
      v7 = v23 <= v24 ? v35.x + v22 : v35.x - v22;
      v11 = v27;
      v15 = 0;
      if (v25 <= v26)
        break;
      v10 = v22 + v35.z;
      v9 = v35.z - v22;
      v5 = v22;
      if (++v14 == 32)
        goto LABEL_57;
    }
    v10 = v35.z - v22;
    v9 = v22 + v35.z;
    v5 = v22;
    ++v14;
  }
  while (v14 != 32);
LABEL_57:
  v35.w = 0.0;
  v30 = (v8 - v7) * 0.5;
  v31 = (v10 - v9) * 0.5;
  v32 = v11 * 0.5;
  v35.z = (v10 + v9) * 0.5;
  v35.x = (v8 + v7) * 0.5;
  v35.y = v11 * -0.5;
  if (v30 <= v31)
  {
    if (v31 > v32)
      v32 = (v10 - v9) * 0.5;
  }
  else if (v30 > v32)
  {
    v32 = (v8 - v7) * 0.5;
  }
  v33 = (v5 * 0.25) + v32;
  v36.w = 0.0;
  v36.x = (v8 + v7) * 0.5;
  v36.y = v11 * -0.5;
  v36.z = (v10 + v9) * 0.5;
  SDF_VU0__LOADVECTOR(v36);
  return v33;
}

// 0x14bd990
f32 effBTLModelGroupGetSphereOld(u32 group) {
  f32 MaxLength;
  UnityEngine_Vector4_o v7;

  *&v7.x = 0;
  *&v7.z = 0;
  sub_854690(&v7.x, 0.0, 0.0, 0.0, 0.0);
  effBTLModelGroupGetCenter(group);
  SDF_VU0__STOREVECTOR(&v7);
  MaxLength = effBTLModelGroupGetMaxLength(&v7, group);
  SDF_VU0__LOADVECTOR(v7);
  return MaxLength;
}

// 0x14bdd80
f32 effBTLModelGroupGetVectorSphere(u32 group, sdfVector4_t *pTarget, sdfVector4_t *pEye) {
  u64 *v7;
  u64 *v8;
  s64 v14;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  struct sdf3DScreenParam_t_o *dds3ScreenParam;
  s64 v24;
  s64 v25;
  s64 v26;
  s64 v27;
  s64 v28;
  s64 v29;
  s64 v30;
  u64 v32;
  UnityEngine_Vector4_o *v33;
  UnityEngine_Vector4_o *v34;
  s64 v36;
  s64 v38;
  char v41;
  u32 v48;
  f32 v50;
  u64 v51;
  u64 *v52;
  char *v54;
  f32 *v55;
  u64 v56;
  f32 *v57;
  f32 *v58;
  f32 *v59;
  f32 *v60;
  f32 v65;
  u32 v66;
  s64 v73;
  s64 v76;
  f32 v78;
  u64 *v84;
  u32 *aTarget_8;
  UnityEngine_Matrix4x4_o v87;
  UnityEngine_Matrix4x4_o v88;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o v90;
  UnityEngine_Vector4_o v91;
  UnityEngine_Vector4_o v92;
  UnityEngine_Vector4_o v93;

  memset(&aMatrix, 0, sizeof(aMatrix));
  v84 = NewSpecific(UnityEngine_Vector4, 0x20u);
  v7 = NewSpecific(UnityEngine_Vector4, 0x20u);
  v8 = NewSpecific(byte, 0x20u);
  aTarget_8 = NewSpecific(s32, 2u);
  *&v90.x = nbGetMainProcessData();
  v91 = *pTarget;
  v14 = *&v90.x;
  x = pEye->x;
  y = pEye->y;
  z = pEye->z;
  w = pEye->w;
  v93.x = x;
  v93.y = y;
  v93.z = z;
  v93.w = w;
  *&v90.x = 0;
  LookAtMatrix(v91, v93, v90);
  v24 = *&dds3ScreenParam->TM.m00;
  v25 = *&dds3ScreenParam->TM.m20;
  v26 = *&dds3ScreenParam->TM.m21;
  *&v88.m01 = *&dds3ScreenParam->TM.m01;
  *&v88.m21 = v26;
  *&v88.m00 = v24;
  *&v88.m20 = v25;
  v27 = *&dds3ScreenParam->TM.m02;
  v28 = *&dds3ScreenParam->TM.m22;
  v30 = *&dds3ScreenParam->TM.m03;
  v29 = *&dds3ScreenParam->TM.m23;
  *&v88.m03 = v30;
  *&v88.m23 = v29;
  *&v88.m02 = v27;
  *&v88.m22 = v28;
  MultMatrixRev(&v88);
  SDF_VU0__STOREMATRIX(&aMatrix);
  v32 = 0;
  v33 = (v7 + 4);
  v34 = (v84 + 4);
  do
  {
    v36 = *(v14 + 16);
    v38 = *(v36 + 8 * v32 + 32);
    if ((*(v38 + 136) & 3) != 3 || (*(v38 + 136) & group) == 0)
    {
      v41 = 0;
    }
    else
    {
      SDF_VU0__LOADVECTOR(*(v38 + 64), 0);
      ToMatrix();
      SDF_VU0__LOADVECTOR(*(v38 + 80), 0);
      SDF_VU0__SCALEVECTOR(*(v38 + 108), 0);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__LOADVECTOR_B(*(v38 + 48), 0);
      SDF_VU0__ADDVECTOR();
      v87 = aMatrix;
      SDF_VU0__LOADMATRIX(&v87);
      SDF_VU0__STOREVECTOR(v34);
      SDF_VU0__PERSVECTOR();
      SDF_VU0__LOADVECTOR_B(dds3ScreenParam->scale);
      SDF_VU0__MULVECTOR();
      SDF_VU0__LOADVECTOR_B(dds3ScreenParam->trans);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(v33);
      v33->z = 0.0;
      v41 = 1;
    }
    *(v8 + v32++ + 32) = v41;
    ++v33;
    ++v34;
  }
  while (v32 != 32);
  v48 = aTarget_8[6];
  aTarget_8[8] = 0;
  v50 = 0.0;
  v51 = 0;
  v52 = v8 + 4;
  aTarget_8[9] = 0;
  do
  {
    if (*(v8 + v51 + 32))
    {
      v54 = v7 + 44;
      v55 = &v7[2 * v51];
      v56 = 0;
      v57 = v55 + 8;
      v58 = v55 + 9;
      v59 = v55 + 10;
      v60 = v55 + 11;
      do
      {
        if (v51 != v56 && *(v52 + v56))
        {
          v92.x = *v57;
          v92.y = *v58;
          v92.z = *v59;
          v92.w = *v60;
          SDF_VU0__LOADVECTOR(v92);
          SDF_VU0__LOADVECTOR_B(*(v54 - 12), 0);
          SDF_VU0__SUBVECTOR();
          v65 = SDF_VU0__GETLENGTH();
          if (v65 > v50)
          {
            v66 = aTarget_8[6];
            aTarget_8[8] = v51;
            v52 = v8 + 4;
            v50 = v65;
            aTarget_8[9] = v56;
          }
        }
        ++v56;
        v54 += 16;
      }
      while (v56 != 32);
    }
    ++v51;
  }
  while (v51 != 32);
 if (!aTarget_8[6])
  {
    goto LABEL_76;
  }
  v73 = aTarget_8[8];
  SDF_VU0__LOADVECTOR(*&v84[2 * v73 + 4]);
  SDF_VU0__COPYVECTOR_A_TO_C();
  v76 = aTarget_8[9];
  SDF_VU0__LOADVECTOR_B(*&v84[2 * v76 + 4]);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__SUBVECTOR();
  v78 = SDF_VU0__GETLENGTH();
  SDF_VU0__COPYVECTOR_C_TO_A();
  return v78;
}

// 0x14bd5a0
f32 effBTLModelGroupGetWidthX(u32 group) {
  f32 v3;
  f32 v5;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *v9;
  nbFormation_t_o *v12;
  f32 v13;
  f32 v14;
  f32 v15;
  UnityEngine_Vector4_o v17;
  nbFormation_t_o *form;

  v3 = 0.0;
  form = 0;
  *&v17.x = 0;
  *&v17.z = 0;
  sub_854690(&v17.x, 0.0, 0.0, 0.0, 0.0);
  v5 = 0.0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    v9 = MainProcessData->form;
    form = v9->m_Items[i];
    if ((form->stat & 3) == 3 && (form->stat & group) != 0)
    {
      else if ((byte_3F59A65 & 1) != 0)
      {
LABEL_19:
        v12 = form;
        if ((~form->stat & 3) == 0)
        {
          nbGetFormPos(&form);
          SDF_VU0__STOREVECTOR(&v17);
          v12 = form;
        }
        v13 = v12->r * v12->scl;
        v14 = v17.x + v13;
        if (v3 >= (v17.x + v13))
          v15 = v3;
        else
          v15 = v17.x + v13;
        if (v5 <= v14)
          v14 = v5;
        v5 = v17.x - v13;
        if (v15 >= (v17.x - v13))
          v3 = v15;
        else
          v3 = v17.x - v13;
        if (v14 <= v5)
          v5 = v14;
        continue;
      }
      goto LABEL_19;
    }
  }
  return v3 - v5;
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
LABEL_19:
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
      goto LABEL_19;
    }
  }
}

// 0x14bfb20
void effBTLModelGroupRotate(u32 group, f32 angle) {
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *v11;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  UnityEngine_Matrix4x4_o v19;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o p;
  UnityEngine_Matrix4x4_o aMatrix;
  nbFormation_t_o *form[2];
  UnityEngine_Vector4_o v24;

  form[0] = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v20.x = 0;
  *&v20.z = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v20.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  SetRotateMatrixY(angle);
  SDF_VU0__STOREMATRIX(&aMatrix);
  effBTLModelGroupGetCenter(group);
  SDF_VU0__STOREVECTOR(&p);
  for (i = 0; i != 32; ++i)
  {
    v11 = MainProcessData->form;
    form[0] = v11->m_Items[i];
    if ((form[0]->stat & 3) == 3 && (form[0]->stat & group) != 0)
    {
      else if ((byte_3F59A65 & 1) != 0)
      {
LABEL_25:
        if ((~form[0]->stat & 3) == 0)
        {
          nbGetFormPos(form);
          SDF_VU0__STOREVECTOR(&v20);
        }
        p.y = v20.y;
        v19 = aMatrix;
        SDF_VU0__LOADMATRIX(&v19);
        SDF_VU0__LOADVECTOR(v20);
        SDF_VU0__LOADVECTOR_B(p);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__APPLYMATRIX();
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&v20);
        x = v20.x;
        y = v20.y;
        z = v20.z;
        w = v20.w;
        v24.x = x;
        v24.y = y;
        v24.z = z;
        v24.w = w;
        nbSetFormPos(form, v24);
        continue;
      }
      goto LABEL_25;
    }
  }
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
        goto LABEL_51;
      if (v12 == v8)
      {
        else if ((byte_3F59A6A & 1) == 0)
        {
LABEL_43:
        }
        v19 = &effBTLModelShowFlag->m_Items[v8->formindex];
        v18 = 1;
        goto LABEL_50;
      }
        break;
      if ((byte_3F59A6B & 1) == 0)
        goto LABEL_33;
LABEL_34:
      v15 = effBTLModelShowFlag;
      formindex = v12->formindex;
      v18 = 0;
      v19 = &v15->m_Items[formindex];
LABEL_50:
      *v19 = v18;
LABEL_51:
      if (++v9 == 32)
        return;
    }
    if ((byte_3F59A6B & 1) != 0)
      goto LABEL_34;
LABEL_33:
    goto LABEL_34;
  }
  effBTLModelInvokePartyShow();
}

// 0x14c0d80
void effBTLModelInvokeHide(void) {
  nbFormation_t_o *v3;
  struct System_Byte_array *effBTLModelShowFlag;
  s64 formindex;

  v3 = effBTLSkillGetInvokeFormation(0);
LABEL_10:
  formindex = v3->formindex;
  effBTLModelShowFlag->m_Items[formindex] = 0;
}

// 0x14c1720
void effBTLModelInvokePartyHide(void) {
  u32 v3;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v9;

  v3 = effBTLSkillGetInvokeParty();
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v9 = form->m_Items[i];
    if ((v9->stat & 3) == 3 && (v9->stat & v3) != 0)
    {
      else if ((byte_3F59A6B & 1) != 0)
      {
        goto LABEL_22;
      }
      goto LABEL_22;
    }
  }
}

// 0x14c0a50
void effBTLModelInvokePartyShow(void) {
  u32 v3;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v9;

  v3 = effBTLSkillGetInvokeParty();
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v9 = form->m_Items[i];
    if ((v9->stat & 3) == 3 && (v9->stat & v3) != 0)
    {
      else if ((byte_3F59A6A & 1) != 0)
      {
        goto LABEL_22;
      }
      goto LABEL_22;
    }
  }
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
LABEL_10:
      effBTLModelInvokePartyShow();
      return;
    }
  }
  v5 = effBTLSkillGetInvokeFormation(0);
LABEL_22:
  formindex = v5->formindex;
  effBTLModelShowFlag->m_Items[formindex] = 1;
}

// 0x14be720
void effBTLModelLook(nbFormation_t **pFormation, sdfVector4_t *pTargetPos) {
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v10;
  f32 v11;
  f32 v12;
  s64 v14;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o p;
  s64 v19;
  s64 v20;
  UnityEngine_Vector4_o v21;

  v19 = 0;
  v20 = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v17.x = 0;
  *&v17.z = 0;
  sub_854690(&v19, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v17.x, 0.0, 0.0, 0.0, 0.0);
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
  SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  *&v19 = pTargetPos->x - p.x;
  v6 = pTargetPos->z - p.z;
  *&v20 = v6;
  if (*&v19 != 0.0 || v6 != 0.0)
  {
    sub_854710(&v19, 0);
    v8 = v7;
    sub_854710(&v19, 2u);
    v11 = v10;
    v12 = sdfAtan2(v8, v11);
    FromEuler(0.0, v12, 0.0);
    SDF_VU0__STOREVECTOR(&v17);
    v14 = *&v17.x;
    z = v17.z;
    w = v17.w;
    *&v21.x = v14;
    v21.z = z;
    v21.w = w;
    nbSetFormRot(pFormation, v21, 0);
  }
}

// 0x14be970
void effBTLModelLook2(nbFormation_t **pFormation, sdfVector4_t *pTargetPos, f32 angle) {
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v14;
  f32 v15;
  f32 v17;
  f32 v18;
  s64 v20;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o p;
  s64 c;
  s64 aX;
  UnityEngine_Vector4_o v27;

  c = 0;
  aX = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v23.x = 0;
  *&v23.z = 0;
  sub_854690(&c, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v23.x, 0.0, 0.0, 0.0, 0.0);
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
  SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  *&c = pTargetPos->x - p.x;
  v9 = pTargetPos->z - p.z;
  *&aX = v9;
  if (*&c != 0.0 || v9 != 0.0)
  {
    v10 = sdfSin(angle);
    v11 = (v10 / sdfCos(angle)) * *&aX;
    v12 = sdfFabs(v11);
    v14 = sdfFabs(*&c);
    v15 = *&c;
    if (v12 <= v14)
    {
      if (*&c >= 0.0)
      {
        v15 = sdfFabs(v11);
        v17 = *&aX;
          goto LABEL_24;
        goto LABEL_18;
      }
      v15 = -sdfFabs(v11);
    }
    v17 = *&aX;
    {
LABEL_24:
      v18 = sdfAtan2(v15, v17);
      FromEuler(0.0, v18, 0.0);
      SDF_VU0__STOREVECTOR(&v23);
      v20 = *&v23.x;
      z = v23.z;
      w = v23.w;
      *&v27.x = v20;
      v27.z = z;
      v27.w = w;
      nbSetFormRot(pFormation, v27, 0);
      return;
    }
LABEL_18:
    goto LABEL_24;
  }
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
LABEL_6:
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
            goto LABEL_33;
LABEL_26:
          goto LABEL_33;
        }
          goto LABEL_26;
LABEL_33:
        v17 = effBTLModelShowFlag;
        ++v5;
        v17->m_Items[form->formindex] = -1;
        if (v5 == 32)
          return;
      }
      nbFormDispOn2(&form);
        goto LABEL_33;
      goto LABEL_26;
    }
  }
}

// 0x14c1300
void effBTLModelTargetGroupHide(void) {
  u32 TargetParty;
  u32 TargetBit;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v10;

  TargetParty = effBTLSkillGetTargetParty();
  TargetBit = effBTLSkillGetTargetBit();
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v10 = form->m_Items[i];
    if ((v10->stat & 3) == 3 && (v10->stat & TargetParty) != 0)
    {
      if ((TargetBit & 1) == 0)
      {
        else if ((byte_3F59A6B & 1) != 0)
        {
          goto LABEL_25;
        }
        goto LABEL_25;
      }
      else if ((byte_3F59A6A & 1) != 0)
      {
        goto LABEL_35;
      }
      goto LABEL_35;
    }
LABEL_42:
    TargetBit >>= 1;
  }
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
LABEL_6:
      v4 = TargetNumber;
      v5 = 0;
      while (1)
      {
        TargetFormation = effBTLSkillGetTargetFormation(v5);
          break;
        if ((byte_3F59A6B & 1) == 0)
          goto LABEL_15;
LABEL_16:
        formindex = TargetFormation->formindex;
        ++v5;
        effBTLModelShowFlag->m_Items[formindex] = 0;
        if (v4 == v5)
          return;
      }
      if ((byte_3F59A6B & 1) != 0)
        goto LABEL_16;
LABEL_15:
      goto LABEL_16;
    }
  }
}

// 0x14c18d0
void effBTLModelTargetPartyHide(void) {
  u32 TargetParty;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v9;

  TargetParty = effBTLSkillGetTargetParty();
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v9 = form->m_Items[i];
    if ((v9->stat & 3) == 3 && (v9->stat & TargetParty) != 0)
    {
      else if ((byte_3F59A6B & 1) != 0)
      {
        goto LABEL_22;
      }
      goto LABEL_22;
    }
  }
}

// 0x14c1570
void effBTLModelTargetPartyShow(void) {
  u32 TargetParty;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v9;

  TargetParty = effBTLSkillGetTargetParty();
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v9 = form->m_Items[i];
    if ((v9->stat & 3) == 3 && (v9->stat & TargetParty) != 0)
    {
      else if ((byte_3F59A6A & 1) != 0)
      {
        goto LABEL_22;
      }
      goto LABEL_22;
    }
  }
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
LABEL_6:
      v4 = TargetNumber;
      v5 = 0;
      while (1)
      {
        TargetFormation = effBTLSkillGetTargetFormation(v5);
          break;
        if ((byte_3F59A6A & 1) == 0)
          goto LABEL_15;
LABEL_16:
        formindex = TargetFormation->formindex;
        ++v5;
        effBTLModelShowFlag->m_Items[formindex] = 1;
        if (v4 == v5)
          return;
      }
      if ((byte_3F59A6A & 1) != 0)
        goto LABEL_16;
LABEL_15:
      goto LABEL_16;
    }
  }
}

// 0x14c3d60
void effBTLPartDebugPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
  UnityEngine_Vector4_o v7;

  *&v7.x = 0;
  *&v7.z = 0;
  sub_854690(&v7.x, 0.0, 0.0, 0.0, 0.0);
  effBTLPartGetPositionPtr(pFormation, pPosPtr, &v7);
}

// 0x14bbc50
u32 effBTLPartGetFadeFramePtr(u32 PtrNum) {
  struct System_UInt32_array *effBTL_Ptr_FadeFrame;
  il2cpp_array_size_t max_length;

  max_length = effBTL_Ptr_FadeFrame->max_length;
  if (PtrNum >= max_length)
    return 0;
  else if (max_length <= PtrNum)
  {
    goto LABEL_10;
  }
  return effBTL_Ptr_FadeFrame->m_Items[PtrNum];
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

  else if ((nbGetMainProcessData()->stat & 0x1000) != 0)
  {
    goto LABEL_42;
  }
  if ((*pPosPtr)->height > 1u)
    goto LABEL_42;
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
LABEL_18:
      if (id != 258 && id != 259)
        goto LABEL_42;
LABEL_52:
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
      goto LABEL_52;
    if (id != 293)
    {
      if (id != 321)
        goto LABEL_42;
      goto LABEL_52;
    }
  }
  if (!effBTLSkillCheckRun() || v11 - 221 > 0x21 || ((1LL << (v11 + 35)) & 0x200100001LL) == 0)
    goto LABEL_52;
LABEL_42:
  height = (*pPosPtr)->height;
LABEL_46:
  if ((~(*pFormation)->stat & 3) != 0)
    goto LABEL_52;
  hunit = (*pFormation)->hunit;
  if (!hunit)
    goto LABEL_52;
  modelRoot = hunit->Model->modelRoot;
  if (!sdfModelGetMarkPosUnity(modelRoot, height))
    goto LABEL_52;
}

// 0x14c29f0
void effBTLPartGetModelPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr) {
  s64 height;
  s64 direction;
  signed s32 radius;
  f32 v9;
  nbFormation_t_o *v10;
  f32 h;
  f32 v12;
  f32 v14;
  bool v15;
  f32 v16;
  f32 y;
  struct System_Single_array *effBTL_Ptr_H;
  f32 x;
  f32 z;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 w;
  f32 *static_fields;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  struct System_Single_array *effBTL_Ptr_D;
  f32 v42;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v48;
  u64 v49;
  s64 v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;

  v49 = 0;
  v50 = 0;
  *&v48.x = 0;
  *&v48.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&v49, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v48.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  height = (*pPosPtr)->height;
  direction = (*pPosPtr)->direction;
  radius = (*pPosPtr)->radius;
  if (radius)
  {
    v9 = radius;
    v10 = *pFormation;
  }
  else
  {
    v10 = *pFormation;
    v9 = (*pFormation)->r * (*pFormation)->scl;
  }
  h = v10->h;
  v12 = h * 0.5;
  effBTLPartPtrGetModelCenter(pFormation);
  SDF_VU0__STOREVECTOR(&p);
  if (height != 5)
  {
    y = p.y;
    v16 = y - (v12 * effBTL_Ptr_H->m_Items[height]);
    if ((direction | 2) != 0xA)
    {
LABEL_21:
      if (height == 4)
        goto LABEL_26;
      goto LABEL_22;
    }
    v14 = v16 - v9;
    v15 = (*pPosPtr)->radius == 0;
LABEL_19:
    if (!v15)
      v16 = v14;
    goto LABEL_21;
  }
  if ((direction | 2) == 0xA)
  {
    v14 = -v9;
    v15 = (*pPosPtr)->radius == 0;
    v16 = -1.0;
    goto LABEL_19;
  }
  v16 = -1.0;
LABEL_22:
  if (direction != 9)
  {
    if ((direction | 2) == 0xA)
    {
      v49 = __PAIR64__(LODWORD(v16), LODWORD(p.x));
      *&v50 = p.z;
      x = p.x;
      z = p.z;
    }
    else
    {
      *&v48.x = 0;
      v48.z = 1.0;
      v37 = v16;
      SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
      ToMatrix();
      v42 = effBTL_Ptr_D->m_Items[direction];
      SetRotateMatrixY_B(v42);
      MultMatrixNoArg();
      SDF_VU0__LOADVECTOR(v48);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__STOREVECTOR(&v48);
      v16 = v37 + (v9 * v48.y);
      x = p.x + (v9 * v48.x);
      z = p.z + (v9 * v48.z);
      *&v49 = x;
      *(&v49 + 1) = v16;
      *&v50 = z;
    }
    v53.x = x;
    v53.y = v16;
    v53.z = z;
    v53.w = *(&v50 + 1);
    SDF_VU0__LOADVECTOR(v53);
    return;
  }
LABEL_26:
  if (v9 <= v12)
    v23 = v12;
  else
    v23 = v9;
  v48.z = -v23;
  *&v48.x = 0;
  p.y = v16;
  v24 = p.x;
  v25 = p.z;
  w = p.w;
  v33 = static_fields[38];
  v34 = static_fields[39];
  v35 = static_fields[40];
  v36 = static_fields[41];
  v54.x = v33;
  v54.y = v34;
  v54.z = v35;
  v54.w = v36;
  *&v51.x = 0;
  v52.x = v24;
  v52.y = v16;
  v52.z = v25;
  v52.w = w;
  LookAtMatrix(v52, v54, v51);
  ReverseMatrix();
  SDF_VU0__LOADVECTOR(v48);
  SDF_VU0__VECTOR_W_SET_ZERO();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__ADDVECTOR();
}

// 0x14c2e40
void effBTLPartGetPartyPositionPtr(u32 group, effBTL_SkillPositionPtr_t **pPosPtr) {
  f32 y;
  s32 height;
  s64 direction;
  signed s32 radius;
  f32 v13;
  f32 v15;
  struct System_Single_array *effBTL_Ptr_D;
  f32 v19;
  f32 pFrontMax;
  s64 pHeightMax;
  UnityEngine_Vector4_o pCenter;
  UnityEngine_Vector4_o p;
  u64 v24;
  s64 v25;
  UnityEngine_Vector4_o v26;

  y = 0.0;
  v24 = 0;
  v25 = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&pCenter.x = 0;
  *&pCenter.z = 0;
  sub_854690(&v24, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&pCenter.x, 0.0, 0.0, 0.0, 0.0);
  pHeightMax = 0;
  pFrontMax = 0.0;
  height = (*pPosPtr)->height;
  direction = (*pPosPtr)->direction;
  nbGetMainProcessData();
  effBTLPartPtrModelGroupGetCenterAndHeight(group, &pCenter, &pHeightMax + 1, &pHeightMax, &pFrontMax);
  radius = (*pPosPtr)->radius;
  if (radius)
    v13 = radius;
  else
    v13 = 500.0;
  switch (height)
  {
    case 0:
    case 1:
      y = pCenter.y;
      goto LABEL_14;
    case 2:
      y = *(&pHeightMax + 1);
      if (direction == 10)
        goto LABEL_29;
      goto LABEL_15;
    case 3:
      LODWORD(y) = pHeightMax;
      if (direction == 10)
        goto LABEL_29;
      goto LABEL_15;
    case 5:
      if ((direction | 2) == 0xA)
      {
        if (radius)
          y = -radius;
        else
          y = -1.0;
        if (direction == 10)
          goto LABEL_29;
      }
      else
      {
        y = -1.0;
        if (direction == 10)
        {
LABEL_29:
          v24 = __PAIR64__(LODWORD(y), LODWORD(pCenter.x));
          *&v25 = pCenter.z;
          v26.x = pCenter.x;
          v26.z = pCenter.z;
          goto LABEL_30;
        }
      }
LABEL_15:
      if (direction == 8)
      {
        v24 = __PAIR64__(LODWORD(y), LODWORD(pCenter.x));
        *&v25 = pFrontMax;
        v26.x = pCenter.x;
        v26.z = pFrontMax;
      }
      else
      {
        v15 = 1.0;
        if ((group & 0x100) == 0)
          v15 = -1.0;
        *&p.x = 0;
        p.z = v15;
        v19 = effBTL_Ptr_D->m_Items[direction];
        SetRotateMatrixY(v19);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__APPLYMATRIX_XYZ();
        SDF_VU0__STOREVECTOR(&p);
        y = y + (v13 * p.y);
        v26.x = pCenter.x + (v13 * p.x);
        v26.z = pFrontMax + (v13 * p.z);
        *&v24 = v26.x;
        *(&v24 + 1) = y;
        *&v25 = v26.z;
      }
LABEL_30:
      v26.w = *(&v25 + 1);
      v26.y = y;
      SDF_VU0__LOADVECTOR(v26);
      return;
    default:
LABEL_14:
      if (direction != 10)
        goto LABEL_15;
      goto LABEL_29;
  }
}

// 0x14bbd40
void effBTLPartGetPointLightPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pDir) {
  UnityEngine_Vector4_o v9;

  *&v9.x = 0;
  *&v9.z = 0;
  sub_854690(&v9.x, 0.0, 0.0, 0.0, 0.0);
  effBTLPartGetPositionPtr(pFormation, pPosPtr, &v9);
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
  SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__LOADVECTOR_B(v9);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(pDir);
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
  f32 MaxLength;
  u32 TargetParty;
  u32 v9;
  u32 v11;
  UnityEngine_Vector4_o v13;

  MaxLength = 0.0;
  *&v13.x = 0;
  *&v13.z = 0;
  sub_854690(&v13.x, 0.0, 0.0, 0.0, 0.0);
  switch ((*pPosPtr)->target)
  {
    case 0u:
      return (*pFormation)->r * (*pFormation)->scl;
    case 1u:
      TargetParty = effBTLSkillGetInvokeParty();
      goto LABEL_13;
    case 2u:
      TargetParty = effBTLSkillGetTargetParty();
LABEL_13:
      v9 = TargetParty;
      effBTLModelGroupGetCenter(v9);
      SDF_VU0__STOREVECTOR(&v13);
      v11 = v9;
      goto LABEL_21;
    case 3u:
      effBTLModelGroupGetCenter(0x700u);
      SDF_VU0__STOREVECTOR(&v13);
      v11 = 1792;
LABEL_21:
      MaxLength = effBTLModelGroupGetMaxLength(&v13, v11);
      break;
    default:
      return MaxLength;
  }
  return MaxLength;
}

// 0x14c3b40
void effBTLPartGetRotateMatrixPtr(effBTL_SkillPositionPtr_t **pPosPtr, sdfMatrix4_t *pMatrix) {
  s32 height;
  s64 direction;
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
    x = dds3CameraEyePos.x;
    y = dds3CameraEyePos.y;
    z = dds3CameraEyePos.z;
    w = dds3CameraEyePos.w;
    v27.x = x;
    v27.y = y;
    v27.z = z;
    v27.w = w;
    *&v25.x = 0;
    *&v25.z = pMatrix;
    LookAtMatrix(dds3CameraTargetPos, v27, v25);
    ReverseMatrix();
    SDF_VU0__RESET_ROW3();
    goto LABEL_28;
  }
  if (height != 3 && height != 5 && (direction | 2) != 0xA)
  {
    v16 = 0.0;
    if (direction > 8)
      goto LABEL_16;
LABEL_18:
    v17 = effBTL_Ptr_D->m_Items[direction];
    goto LABEL_24;
  }
  v16 = 1.5708;
  if (direction <= 8)
    goto LABEL_18;
LABEL_16:
  v17 = 0.0;
LABEL_24:
  SetRotateMatrixX(v16);
  SetRotateMatrixY_B(v17);
  MultMatrixRevNoArg();
LABEL_28:
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

LABEL_7:
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
  f32 v5;
  s64 height;
  s64 direction;
  signed s32 radius;
  f32 v11;
  f32 v12;
  f32 v13;
  struct System_Single_array *effBTL_Ptr_D;
  f32 v17;
  dds3Basic_t_o *ActiveCameraSceneBasic;
  struct System_Single_array *effBTL_Ptr_H;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o p;
  s64 v26;
  s64 v27;
  dds3Basic_t_o *v28;
  UnityEngine_Vector4_o v29;

  v5 = 0.0;
  v26 = 0;
  v27 = 0;
  *&p.x = 0;
  *&p.z = 0;
  v28 = 0;
  pBasic = 0;
  sub_854690(&v26, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  if (((*pFormation)->stat & 0x40) != 0)
  {
    height = (*pPosPtr)->height;
    direction = (*pPosPtr)->direction;
    nbGetMainProcessData();
    radius = (*pPosPtr)->radius;
    if (radius)
      v11 = radius;
    else
      v11 = 750.0;
    if (height != 4 && direction != 9)
    {
      if (height == 5)
      {
        if ((direction | 2) != 0xA)
        {
          v12 = -1.0;
LABEL_18:
          *&p.x = 0;
          v13 = 1.0;
          if (((*pFormation)->stat & 0x100) == 0)
            v13 = -1.0;
          p.z = v13;
          v17 = effBTL_Ptr_D->m_Items[direction];
          SetRotateMatrixY(v17);
          SDF_VU0__LOADVECTOR(p);
          SDF_VU0__APPLYMATRIX_XYZ();
          SDF_VU0__STOREVECTOR(&p);
          v29.x = v11 * p.x;
          v12 = v12 + (v11 * p.y);
          v5 = v11 * p.z;
          *&v26 = v11 * p.x;
          *(&v26 + 1) = v12;
          goto LABEL_46;
        }
        if (radius)
          v12 = -radius;
        else
          v12 = -1.0;
        if ((direction | 2) != 0xA)
          goto LABEL_18;
      }
      else
      {
        v12 = effBTL_Ptr_H->m_Items[height] * 250.0;
        if ((direction | 2) != 0xA)
          goto LABEL_18;
      }
      LODWORD(v26) = 0;
      v29.x = 0.0;
      *(&v26 + 1) = v12;
LABEL_46:
      v29.w = *(&v27 + 1);
      v29.y = v12;
      v29.z = v5;
      *&v27 = v5;
      SDF_VU0__LOADVECTOR(v29);
      return;
    }
    pBasic = dds3GetActiveScene();
    ActiveCameraSceneBasic = dds3GetActiveCameraSceneBasic(&pBasic);
    p.z = 750.0;
    v28 = ActiveCameraSceneBasic;
    *&p.x = 0x443B8000443B8000LL;
    dds3CameraObjectBasicGetTargetPos(&v28);
    SDF_VU0__COPYVECTOR_A_TO_B();
    dds3GetPosPoseSet(&v28);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__MULVECTOR();
  }
}

// 0x14c2000
void effBTLPartPtrGetAllModelCenterOffset(void) {
  nbMainProcessData_t_o *MainProcessData;
  struct UnityEngine_Vector4_array *effBTLPartPtrModelCenterOffset;
  u64 v11;
  s64 v12;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v16;
  s32 formindex;
  struct UnityEngine_Vector4_array *v22;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;

  *&p.z = 0;
  pFormation = 0;
  *&v25.z = 0;
  *&p.x = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  *&v25.x = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v25.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v24.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  else if (!effBTLPartPtrModelCenterOffset)
  {
    goto LABEL_9;
  }
  v11 = 0;
  v12 = 32;
  do
  {
    form = MainProcessData->form;
    v16 = form->m_Items[v11];
    pFormation = v16;
    formindex = v16->formindex;
    else
    {
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
      if (!UnitWorkFromFormindex)
        goto LABEL_44;
    }
    if ((UnitWorkFromFormindex->badstatus & 0x413) != 0)
    {
      SDF_VU0__LOADVECTOR(v16->rot);
      ToMatrix();
      SDF_VU0__LOADVECTOR(v16->center);
      SDF_VU0__SCALEVECTOR(v16->scl);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__LOADVECTOR_B(v16->pos);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&p);
      effBTLModelGetMarkPosition2(&pFormation, 0);
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__STOREVECTOR(&v25);
      SDF_VU0__LOADVECTOR(v16->rot);
      ToMatrix();
      InversMatrix();
      SDF_VU0__LOADVECTOR(v25);
      SDF_VU0__APPLYMATRIX();
        goto LABEL_41;
LABEL_38:
      goto LABEL_41;
    }
    SDF_VU0__LOADVECTOR(v24);
      goto LABEL_38;
LABEL_41:
    v22 = effBTLPartPtrModelCenterOffset;
    SDF_VU0__STOREVECTOR((v22 + v12), 0);
LABEL_44:
    ++v11;
    v12 += 16;
  }
  while (v11 != 32);
}

// 0x14bf330
void effBTLPartPtrGetModelCenter(nbFormation_t **pFormation) {
  struct UnityEngine_Vector4_array *effBTLPartPtrModelCenterOffset;
  s64 formindex;
  UnityEngine_Vector4_o v7;

  *&v7.x = 0;
  *&v7.z = 0;
  sub_854690(&v7.x, 0.0, 0.0, 0.0, 0.0);
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*pFormation)->center, 0);
  SDF_VU0__SCALEVECTOR((*pFormation)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*pFormation)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v7);
  SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
  ToMatrix();
  formindex = (*pFormation)->formindex;
  SDF_VU0__LOADVECTOR_B(effBTLPartPtrModelCenterOffset->m_Items[formindex]);
  SDF_VU0__APPLYMATRIX_B();
  SDF_VU0__LOADVECTOR(v7);
  SDF_VU0__ADDVECTOR();
}

// 0x14befb0
void effBTLPartPtrModelGroupGetCenterAndHeight(u32 group, sdfVector4_t *pCenter, f32 *pHeightAve, f32 *pHeightMax, f32 *pFrontMax) {
  f32 v11;
  nbMainProcessData_t_o *MainProcessData;
  u64 v15;
  u32 v16;
  f32 v17;
  f32 v18;
  struct nbFormation_t_array *v19;
  nbFormation_t_o *v21;
  f32 v23;
  f32 v24;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v27;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  UnityEngine_Vector4_o v33;
  UnityEngine_Vector4_o v34;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;

  v11 = 0.0;
  *&p.z = 0;
  pFormation = 0;
  *&v34.z = 0;
  *&p.x = 0;
  *&v33.x = 0;
  *&v33.z = 0;
  *&v34.x = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v34.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v33.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  v15 = 0;
  v16 = 0;
  v34.z = 0.0;
  *&v34.x = 0;
  if ((group & 0x100) != 0)
  {
    v17 = -100000.0;
    v18 = 0.0;
    do
    {
      form = MainProcessData->form;
      v27 = form->m_Items[v15];
      pFormation = v27;
      if ((v27->stat & 3) == 3 && (v27->stat & group) != 0)
      {
        effBTLPartPtrGetModelCenter(&pFormation);
        SDF_VU0__LOADVECTOR_B(v34);
        SDF_VU0__STOREVECTOR(&p);
        SDF_VU0__ADDVECTOR_B_A();
        SDF_VU0__STOREVECTOR_B(&v34);
        ++v16;
        v29 = v27->r * v27->scl;
        v30 = p.y - v29;
        if (v17 < (p.z + v29))
          v17 = p.z + v29;
        v11 = v11 + v30;
        if (v18 > v30)
          v18 = p.y - v29;
      }
      ++v15;
    }
    while (v15 != 32);
  }
  else
  {
    v11 = 0.0;
    v17 = 100000.0;
    v18 = 0.0;
    do
    {
      v19 = MainProcessData->form;
      v21 = v19->m_Items[v15];
      pFormation = v21;
      if ((v21->stat & 3) == 3 && (v21->stat & group) != 0)
      {
        effBTLPartPtrGetModelCenter(&pFormation);
        SDF_VU0__LOADVECTOR_B(v34);
        SDF_VU0__STOREVECTOR(&p);
        SDF_VU0__ADDVECTOR_B_A();
        SDF_VU0__STOREVECTOR_B(&v34);
        ++v16;
        v23 = v21->r * v21->scl;
        v24 = p.y - v23;
        if (v17 > (p.z - v23))
          v17 = p.z - v23;
        v11 = v11 + v24;
        if (v18 > v24)
          v18 = p.y - v23;
      }
      ++v15;
    }
    while (v15 != 32);
  }
  if (v16)
  {
    v31 = v16;
    v33.y = 1.0 / v31;
    v33.z = 1.0 / v31;
    v33.x = 1.0 / v31;
    SDF_VU0__LOADVECTOR(v34);
    SDF_VU0__LOADVECTOR_B(v33);
    SDF_VU0__MULVECTOR();
    SDF_VU0__STOREVECTOR(pCenter);
    *pFrontMax = v17;
    v32 = v11 / v31;
  }
  else
  {
    v32 = 0.0;
    v18 = 0.0;
    *&pCenter->y = 0;
    pCenter->x = 0.0;
    *pFrontMax = 0.0;
  }
  *pHeightAve = v32;
  *pHeightMax = v18;
}

// 0x14c23f0
void effBTLPartPtrResetAllModelCenterOffset(void) {
  nbMainProcessData_t_o *MainProcessData;
  u64 v4;
  s64 v5;
  struct UnityEngine_Vector4_array *effBTLPartPtrModelCenterOffset;
  UnityEngine_Vector4_o v10;

  *&v10.x = 0;
  *&v10.z = 0;
  sub_8546D0(&v10, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  SDF_VU0__LOADVECTOR(v10);
  v4 = 0;
  v5 = 32;
  do
  {
    SDF_VU0__STOREVECTOR((effBTLPartPtrModelCenterOffset + v5), 0);
    ++v4;
    v5 += 16;
  }
  while (v4 != 32);
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
