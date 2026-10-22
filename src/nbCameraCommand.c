#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbCamera_AllTable_t nbCamera_AllTable_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static f32 nbCameraShot_CommandFixPos_Calc2_dist;
static f32 nbCameraShot_CommandFixPos_Calc2_up;
static nbCamera_AllTable_t *nbCameraGetModelAllTable_Dummy;
static s32 nbCameraCRSetPlayerFormRequestFlag;
static u32 nbCameraState_CommandRoot_OrderIndex;
static bool nbWaitUntilCreateMainCamera_1Frame;
static nbCamera_AllTable_t *nbCamera_AllTable[384];

void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetRotateMatrixX(f32 aAngle);
void SetRotateMatrixY(f32 aAngle);
void effBTLModelAllPopPosition(void);
void effBTLModelAllPopRotate(void);
void effBTLModelAllShow(void);
void effBTLModelCheckBoundsHide(nbFormation_t **pFormation, f32 w, f32 h, sdfVector4_t *pTarget, sdfVector4_t *pEye, sdfVector4_t *pUp);
u32 effBTLModelGetGroupNumber(u32 group);
f32 effBTLModelGetHeight(nbFormation_t **pFormation);
u32 effBTLModelGetID(nbFormation_t **pFormation);
u32 effBTLModelGetInvokeGroupNumber(void);
void effBTLModelGetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos);
void effBTLModelGetPosition2(nbFormation_t **pFormation, sdfVector4_t *pPos);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
void effBTLModelGroupGetCenter(u32 group);
void effBTLModelGroupGetDirection(u32 group, sdfVector4_t *pDirection);
f32 effBTLModelGroupGetSphere(u32 group);
void effBTLModelLook(nbFormation_t **pFormation, sdfVector4_t *pTargetPos);
void effBTLModelLook2(nbFormation_t **pFormation, sdfVector4_t *pTargetPos, f32 angle);
void effBTLModelSetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos);
void effBTLModelShow(nbFormation_t **pFormation);
u32 effBTLSkillGetInvokeParty(void);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
u32 effBTLSkillGetTargetNumber(void);
u32 effBTLSkillGetTargetParty(void);
s32 nbCameraBoss_Command_Init(nbCamera_t **pNbCamera);
void nbCameraCommand_GroundCollision(nbCamera_t **pNbCamera);
nbCamera_AllTable_t *nbCameraGetModelAllTable(nbFormation_t *pFormation);
f32 nbCameraGroupGetMaxLength(sdfVector4_t pPos, u32 group);
f32 nbCameraGroupGetSphere(u32 group);
void nbCameraShot_AllParty_Set(nbCamera_t **pNbCamera);
void nbCameraShot_CommandFixPos_Calc2(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm);
void nbCameraShot_CommandFixPos_Set(nbCamera_t **pNbCamera);
void nbCameraShot_CommandFixPos_Set2(nbCamera_t **pNbCamera);
void nbCameraShot_FriendParty_Set(nbCamera_t **pNbCamera);
void nbCameraShot_GroundCollision(nbCamera_t **pNbCamera);
void nbCameraShot_Summon_Set(nbCamera_t **pNbCamera);
void nbCameraState_CommandRoot_Init(void);
void nbCameraState_Command_KORONZCheck(void);
void nbCameraState_InvokeTargetSelect_SearchSet(void);
f32 nbFormationGetRadiusDef(void);
s32 nbGetActionSeq(dds3ProcessID_t *id);
nbMainProcessData_t *nbGetMainProcessData(void);
f32 nbGetSummonInterval(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty);
f32 sdfAtan(f32 aX);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfFabs(f32 c);
f32 sdfSqrt(f32 aValue);

// 0x1669e90
void dds3CrossfadeStart(u32 frame) {
  ;
}

// 0x1669e70
u8 effBTLDebug_CameraAllEditCheck(void) {
  return 0;
}

// 0x1669e80
u8 effBTLDebug_CameraAllTableCheck(void) {
  return 0;
}

// 0x166c950
void nbCameraCRSetPlayerFormRequest(void) {
  nbCameraCRSetPlayerFormRequestFlag = 1;
}

// 0x166b3f0
void nbCameraCommandSetFixPosition(void) {
  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  effBTLModelAllShow();
}

// 0x166c9c0
void nbCameraCommand_GroundCollision(nbCamera_t **pNbCamera) {
  f32 v3;
  s32 v4;
  u64 *v6;
  f32 v7;
  f32 v8;
  f32 v10;
  f32 v11;
  f32 v12;
  s32 v13;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  *&v14.x = 0;
  *&v14.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v14.x, 0.0, 0.0, 0.0, 0.0);
  sub_854930(&v14, 0);
  sub_854710(&v14, 0);
  sub_854930(&v14, 1u);
  sub_854930(&v14, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR_B(v14);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B((*pNbCamera)->target, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  if (v3 > -20.0)
  {
    sub_854710(&p, 1u);
    v13 = v4;
    v6 = sub_8D3950(f32, &v13);
    Write_2930400("nbCameraCommandGroundChk:{0:f}\n", v6);
    sub_854710(&p, 1u);
    v8 = v7 + 20.0;
    sub_854710(&(*pNbCamera)->direction, 1u);
    v11 = v10;
    v12 = sdfFabs(v8 / v11);
    (*pNbCamera)->distance = (*pNbCamera)->distance - sdfSqrt((v8 * v8) + (v12 * v12), 0);
  }
}

// 0x166aba0
nbCamera_AllTable_t *nbCameraGetModelAllTable(nbFormation_t *pFormation) {
  nbCameraCommand_c *v3;
  s32 formindex;

  if (!pFormation || (pFormation->stat & 1) == 0)
  {
      return nbCameraGetModelAllTable_Dummy;
    goto LABEL_13;
  }
  formindex = pFormation->formindex;
  nbGetUnitWorkFromFormindex(formindex);
  {
          v3 = nbCameraCommand,
    {
LABEL_13:
    }
  }
  return nbCameraGetModelAllTable_Dummy;
}

// 0x166b160
f32 nbCameraGetModelRadius(nbFormation_t *pFormation) {
  f32 result;

  result = nbCameraGetModelAllTable(pFormation)->radius;
  if (result == 0.0)
    return pFormation->r * pFormation->scl;
  return result;
}

// 0x166b1e0
f32 nbCameraGroupGetMaxLength(sdfVector4_t pPos, u32 group) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  f32 v16;
  nbFormation_t_o *v17;
  f32 v18;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v23;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  pFormation = 0;
  v8 = 0.0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[i];
    if ((pFormation->stat & 3) == 3 && (pFormation->stat & group) != 0)
    {
      effBTLModelGetSphereCenter(&pFormation);
      v23.x = x;
      v23.y = y;
      v23.z = z;
      v23.w = w;
      SDF_VU0__LOADVECTOR_B(v23);
      SDF_VU0__SUBVECTOR();
      v16 = SDF_VU0__GETLENGTH();
      v17 = pFormation;
      v18 = v16;
      else if ((byte_3F5A2E9 & 1) != 0)
      {
        goto LABEL_22;
      }
      goto LABEL_22;
    }
  }
  return v8;
}

// 0x166ac80
f32 nbCameraGroupGetSphere(u32 group) {
  s64 v5;
  f32 w;
  f32 z;
  f32 MaxLength;
  UnityEngine_Vector4_o v10;
  UnityEngine_Vector4_o v11;

  *&v10.x = 0;
  *&v10.z = 0;
  sub_854690(&v10.x, 0.0, 0.0, 0.0, 0.0);
  effBTLModelGroupGetCenter(group);
  SDF_VU0__STOREVECTOR(&v10);
  v5 = *&v10.x;
  z = v10.z;
  w = v10.w;
  *&v11.x = v5;
  v11.z = z;
  v11.w = w;
  MaxLength = nbCameraGroupGetMaxLength(v11, group);
  SDF_VU0__LOADVECTOR(v10);
  return MaxLength;
}

// 0x166b6a0
void nbCameraShot_AllParty_Set(nbCamera_t **pNbCamera) {
  f32 v3;
  f32 v8;
  nbMainProcessData_t_o *MainProcessData;
  s32 v11;
  s64 i;
  struct nbFormation_t_array *form;
  f32 Height;
  struct nbFormation_t_array *v16;
  nbFormation_t_o *v18;
  f32 r;
  f32 scl;
  f32 v21;
  f32 v22;
  s32 v23;
  struct nbFormation_t_array *v24;
  nbFormation_t_o *v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  struct nbFormation_t_array *v31;
  nbFormation_t_o *v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  bool v38;
  struct nbFormation_t_array *v39;
  nbFormation_t_o *v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  struct nbFormation_t_array *v46;
  struct nbFormation_t_array *v48;
  struct nbFormation_t_array *v50;
  struct nbFormation_t_array *v52;
  f32 v54;
  f32 v55;
  f32 v58;
  UnityEngine_Vector4_o pPos;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v62;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v64;

  v3 = 0.0;
  *&pPos.x = 0;
  *&v64.x = 0;
  *&v64.z = 0;
  *&v62.z = 0;
  pFormation = 0;
  *&p.z = 0;
  *&v62.x = 0;
  *&pPos.z = 0;
  *&p.x = 0;
  sub_8546D0(&v64, 1.0, 0.0, 0.0);
  sub_854690(&v62.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&pPos.x, 0.0, 0.0, 0.0, 0.0);
  effBTLModelAllShow();
  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  nbCameraState_InvokeTargetSelect_SearchSet();
  v8 = 0.0;
  MainProcessData = nbGetMainProcessData();
  v11 = 1;
  for (i = 8; i != 18; ++i)
  {
    while (1)
    {
      form = MainProcessData->form;
      pFormation = *(&form->obj.klass + i);
      if ((~pFormation->stat & 3) != 0)
        break;
      Height = effBTLModelGetHeight(&pFormation);
      if (!v11)
        goto LABEL_22;
LABEL_19:
      v11 = 0;
      v8 = Height;
      v3 = Height;
      if (++i == 18)
        goto LABEL_27;
    }
  }
LABEL_27:
  v16 = MainProcessData->form;
  v18 = v16->m_Items[0];
  pFormation = v18;
  if ((~v18->stat & 3) != 0)
  {
    v21 = 0.0;
    v23 = 1;
    v22 = 0.0;
    v24 = MainProcessData->form;
    if ((v24->max_length & 0xFFFFFFFE) == 0)
      goto LABEL_36;
  }
  else
  {
    r = v18->r;
    scl = v18->scl;
    v21 = r * scl;
    v22 = effBTLModelGetHeight(&pFormation);
    v23 = 0;
    v24 = MainProcessData->form;
    if ((v24->max_length & 0xFFFFFFFE) == 0)
    {
LABEL_36:
    }
  }
  v26 = v24->m_Items[1];
  pFormation = v26;
  if ((~v26->stat & 3) != 0)
  {
    v29 = v21;
    v31 = MainProcessData->form;
    if (LODWORD(v31->max_length) > 2uLL)
      goto LABEL_46;
    goto LABEL_45;
  }
  v27 = v26->r;
  v28 = v26->scl;
  v29 = v27 * v28;
  v30 = effBTLModelGetHeight(&pFormation);
  if (v23)
  {
    v23 = 0;
    v22 = v30;
    v31 = MainProcessData->form;
    if (LODWORD(v31->max_length) > 2uLL)
      goto LABEL_46;
LABEL_45:
  }
  if (v21 >= v29)
    v29 = v21;
  if (v22 < v30)
    v22 = v30;
  v31 = MainProcessData->form;
  if (LODWORD(v31->max_length) <= 2uLL)
    goto LABEL_45;
LABEL_46:
  v33 = v31->m_Items[2];
  pFormation = v33;
  if ((~v33->stat & 3) == 0)
  {
    v34 = v33->r * v33->scl;
    v35 = effBTLModelGetHeight(&pFormation);
    if (v29 >= v34)
      v36 = v29;
    else
      v36 = v34;
    if (v22 >= v35)
      v37 = v22;
    else
      v37 = v35;
    v38 = v23 == 0;
    if (v23)
      v29 = v34;
    else
      v29 = v36;
    v23 = 0;
    if (v38)
      v22 = v37;
    else
      v22 = v35;
  }
  v39 = MainProcessData->form;
  v41 = v39->m_Items[3];
  pFormation = v41;
  if ((~v41->stat & 3) != 0)
  {
LABEL_70:
    if (v3 >= 450.0)
      goto LABEL_100;
    goto LABEL_71;
  }
  v42 = v41->r;
  v43 = v41->scl;
  v44 = v42 * v43;
  v45 = effBTLModelGetHeight(&pFormation);
  if (v23)
  {
    v29 = v44;
    v22 = v45;
    goto LABEL_70;
  }
  if (v29 < v44)
    v29 = v44;
  if (v22 < v45)
    v22 = v45;
  if (v3 < 450.0)
  {
LABEL_71:
    if (v22 >= 300.0)
    {
      v46 = MainProcessData->form;
      pFormation = v46->m_Items[0];
      if ((~pFormation->stat & 3) == 0)
      {
        effBTLModelGetPosition(&pFormation, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&pFormation, &pPos);
      }
      v48 = MainProcessData->form;
      pFormation = v48->m_Items[1];
      if ((~pFormation->stat & 3) == 0)
      {
        effBTLModelGetPosition(&pFormation, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&pFormation, &pPos);
      }
      v50 = MainProcessData->form;
      pFormation = v50->m_Items[2];
      if ((~pFormation->stat & 3) == 0)
      {
        effBTLModelGetPosition(&pFormation, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&pFormation, &pPos);
      }
      v52 = MainProcessData->form;
      pFormation = v52->m_Items[3];
      if ((~pFormation->stat & 3) == 0)
      {
        effBTLModelGetPosition(&pFormation, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&pFormation, &pPos);
      }
    }
  }
LABEL_100:
  effBTLModelGroupGetSphere(0x100u);
  SDF_VU0__STOREVECTOR(&p);
  sub_854930(&p, 1u);
  sub_854710(&p, 2u);
  sub_854930(&p, 2u);
  effBTLModelGroupGetSphere(0x200u);
  SDF_VU0__STOREVECTOR(&v62);
  sub_854710(&p, 0);
  sub_854930(&v62, 0);
  sub_854930(&v62, 1u);
  if (v3 >= 450.0)
  {
    if (v3 > 800.0)
    {
      v54 = 0.715;
      goto LABEL_109;
    }
LABEL_108:
    v54 = 0.65;
    goto LABEL_109;
  }
  if (v8 > 150.0)
    goto LABEL_108;
  v54 = 0.6635;
LABEL_109:
  SDF_VU0__LOADVECTOR(v62);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v55 = (SDF_VU0__GETLENGTH() * 0.5) - (v29 * 0.5);
  SDF_VU0__NORMALIZE();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(v64);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__INTERPOLATE(v54);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR(v62);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  (*pNbCamera)->fovy = 0.69813;
  v58 = sdfAtan(0.54105);
  (*pNbCamera)->distance = v55 / v58;
  (*pNbCamera)->distance = (*pNbCamera)->distance
                                + (fmaxf(effBTLModelGroupGetSphere(0x100u), 480.0) / v58);
  nbCameraShot_GroundCollision(pNbCamera);
}

// 0x1669ea0
void nbCameraShot_CommandFixPos_Calc2(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm) {
  f32 v5;
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v9;
  nbFormation_t_o *v10;
  nbCamera_AllTable_t_o *ModelAllTable;
  s32 v13;
  f32 v14;
  f32 v15;
  u64 m;
  struct nbFormation_t_array *v17;
  f32 Height;
  f32 v20;
  struct nbFormation_t_array *v21;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v25;
  struct nbFormation_t_array *v27;
  u32 ID;
  struct nbFormation_t_array *v31;
  struct nbFormation_t_array *v33;
  u64 i;
  struct nbFormation_t_array *v39;
  nbCamera_t_o *v41;
  f32 v44;
  f32 r;
  f32 scl;
  f32 distance;
  f32 v49;
  UnityEngine_Vector4_o v79;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  nbFormation_t_o *v84;

  v5 = 0.0;
  *&p.z = 0;
  pFormation = 0;
  *&v81.z = 0;
  *&p.x = 0;
  *&v79.x = 0;
  *&v80.z = 0;
  *&v81.x = 0;
  v84 = 0;
  *&v79.z = 0;
  *&v80.x = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v81.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v80.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v79.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    v9 = MainProcessData;
    v10 = *pCmdForm;
    ModelAllTable = nbCameraGetModelAllTable(v10);
    v13 = 1;
    switch (v9->formationtype)
    {
      case 4:
      case 0xA:
      case 0xD:
        v13 = 0;
        goto LABEL_12;
      case 8:
        form = v9->form;
        v84 = form->m_Items[4];
        effBTLModelGetPosition2(&v84, &v79);
        sub_854710(&v79, 0);
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sub_854710(&v79, 2u);
        sub_854930(&p, 2u);
        v5 = 150.0;
        v20 = 700.0;
        v15 = 300.0;
        goto LABEL_64;
      case 9:
      case 0xB:
        v21 = v9->form;
        if ((v21->m_Items[4]->stat & 1) == 0)
          goto LABEL_33;
        v27 = v9->form;
        ID = effBTLModelGetID(&v27->m_Items[4]);
        if (ID == 258)
        {
          v33 = v9->form;
          v84 = v33->m_Items[4];
          effBTLModelGetSphereCenter(&v84);
          SDF_VU0__STOREVECTOR(&v79);
          sub_854930(&p, 0);
          sub_854930(&p, 1u);
          sub_854710(&v79, 2u);
          sub_854930(&p, 2u);
          v5 = 150.0;
          v20 = 500.0;
          v15 = 700.0;
        }
        else
        {
          if (ID != 342 && ID != 291)
          {
LABEL_33:
            v13 = 0;
            v15 = 0.0;
            v14 = 0.0;
            v20 = 0.0;
            goto LABEL_69;
          }
          v31 = v9->form;
          v84 = v31->m_Items[4];
          effBTLModelGetSphereCenter(&v84);
          SDF_VU0__STOREVECTOR(&v79);
          sub_854930(&p, 0);
          sub_854930(&p, 1u);
          sub_854710(&v79, 2u);
          sub_854930(&p, 2u);
          v5 = 150.0;
          v20 = 500.0;
          v15 = 900.0;
        }
LABEL_64:
        v13 = 0;
        v14 = v15;
LABEL_65:
        sub_854930(&p, 1u);
        effBTLModelGetSphereCenter(&v84);
        SDF_VU0__STOREVECTOR(&v81);
        sub_854710(&p, 1u);
        sub_854710(&v81, 1u);
LABEL_69:
        sub_854930(&p, 1u);
        effBTLModelGetSphereCenter(pCmdForm);
        SDF_VU0__STOREVECTOR(&v80);
        effBTLModelGetHeight(pCmdForm);
        sub_854930(&v80, 1u);
        sub_854710(&v80, 1u);
        sub_854930(&v80, 1u);
        for (i = 0; i != 32; ++i)
        {
          v39 = v9->form;
          pFormation = v39->m_Items[i];
          if ((~pFormation->stat & 0x103) == 0)
          {
            effBTLModelGetPosition(&pFormation, &v79);
            sub_854710(&v79, 2u);
            sub_854930(&v79, 2u);
            effBTLModelSetPosition(&pFormation, &v79);
          }
        }
        sub_854710(&v80, 2u);
        sub_854930(&v80, 2u);
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
        SDF_VU0__LOADVECTOR_B(v80);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__COPYVECTOR_A_TO_C();
        v41 = *pNbCamera;
        v41->distance = SDF_VU0__GETLENGTH();
        v44 = sdfAtan(0.34907);
        r = (*pCmdForm)->r;
        scl = (*pCmdForm)->scl;
        else
        {
          distance = ModelAllTable->distance;
          if (distance == 0.0)
            goto LABEL_87;
        }
        v49 = distance * (*pCmdForm)->scl;
        goto LABEL_94;
      case 0xC:
        v25 = v9->form;
        v15 = 0.0;
        v14 = 0.0;
        v20 = 0.0;
        v13 = 0;
        if ((v25->m_Items[4]->stat & 1) == 0)
          goto LABEL_69;
        goto LABEL_12;
      default:
LABEL_12:
        v84 = 0;
        v14 = 1000000.0;
        v15 = 0.0;
        for (m = 0; m != 32; ++m)
        {
          v17 = v9->form;
          pFormation = v17->m_Items[m];
          if ((~pFormation->stat & 0x203) == 0)
          {
            Height = effBTLModelGetHeight(&pFormation);
            if (Height < v14)
            {
              v14 = Height;
              v84 = pFormation;
            }
            if (Height > v15)
              v15 = Height;
          }
        }
        if (!v84)
          return;
        v20 = nbCameraGroupGetSphere(0x200u) + 50.0;
        SDF_VU0__STOREVECTOR(&p);
        if (v14 <= 150.0)
          goto LABEL_69;
        v5 = 0.0;
        goto LABEL_65;
    }
  }
}

// 0x166b5e0
void nbCameraShot_CommandFixPos_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_o **v4;

  effBTLModelGetGroupNumber(0x100u);
  effBTLModelGetGroupNumber(0x200u);
  else
  {
    v4 = pNbCamera;
  }
  nbCameraShot_CommandFixPos_Set2(v4);
}

// 0x166b460
void nbCameraShot_CommandFixPos_Set2(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  s64 orderindex;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v9;
  struct nbFormation_t_array *form;
  s64 formindex;
  nbFormation_t_o *pCmdForm;

  pCmdForm = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    orderindex = MainProcessData->orderindex;
    if (orderindex != -1)
    {
      order = MainProcessData->order;
      party = MainProcessData->party;
      v9 = order->m_Items[orderindex];
      form = MainProcessData->form;
      formindex = party->m_Items[v9]->formindex;
      pCmdForm = form->m_Items[formindex];
      if ((pCmdForm->stat & 0x200) == 0)
      {
        if (!nbCameraBoss_Command_Init(pNbCamera))
        {
          nbCameraShot_CommandFixPos_Calc2(pNbCamera, &pCmdForm);
        }
      }
    }
  }
}

// 0x166c4f0
void nbCameraShot_FriendParty_Set(nbCamera_t **pNbCamera) {
  u32 v4;
  f32 Sphere;
  f32 v7;
  f32 fovy;
  UnityEngine_Vector4_o *p_direction;

  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  effBTLModelAllShow();
  v4 = effBTLSkillGetInvokeParty();
  Sphere = effBTLModelGroupGetSphere(v4);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  sub_854930(&(*pNbCamera)->fields, 0);
  (*pNbCamera)->fovy = 0.69813;
  v7 = fmaxf(Sphere, 250.0);
  fovy = (*pNbCamera)->fovy;
  (*pNbCamera)->distance = v7 / sdfAtan((fovy * 1.42) * 0.5, 0);
  p_direction = &(*pNbCamera)->direction;
  effBTLModelGroupGetDirection(v4, p_direction);
  SetRotateMatrixX(-0.2618);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
}

// 0x166c6d0
void nbCameraShot_Summon_Set(nbCamera_t **pNbCamera) {
  u32 v4;
  f32 Sphere;
  f32 v7;
  f32 SummonInterval;
  f32 RadiusDef;
  nbCamera_t_Fields *p_fields;
  f32 fovy;
  UnityEngine_Vector4_o *p_direction;

  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  effBTLModelAllShow();
  v4 = effBTLSkillGetInvokeParty();
  Sphere = effBTLModelGroupGetSphere(v4);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  sub_854930(&(*pNbCamera)->fields, 0);
  v7 = fmaxf(Sphere, 250.0);
  if (effBTLModelGetInvokeGroupNumber() <= 3)
  {
    SummonInterval = nbGetSummonInterval();
    RadiusDef = nbFormationGetRadiusDef();
    p_fields = &(*pNbCamera)->fields;
    v7 = v7 + (SummonInterval + (RadiusDef * 0.5));
    sub_854710(p_fields, 0);
    sub_854930(p_fields, 0);
  }
  (*pNbCamera)->fovy = 0.69813;
  fovy = (*pNbCamera)->fovy;
  (*pNbCamera)->distance = v7 / sdfAtan((fovy * 1.42) * 0.5, 0);
  p_direction = &(*pNbCamera)->direction;
  effBTLModelGroupGetDirection(v4, p_direction);
  SetRotateMatrixX(-0.2618);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
}

// 0x166ce80
void nbCameraState_CommandRoot_Calc(void) {
  nbMainProcessData_t_o *MainProcessData;
  struct dds3ProcessID_t_array *ActionProcessID;
  s64 NowActionProcess;
  nbMainProcessData_t_o *v6;
  struct dds3ProcessID_t_array *v8;
  s64 v9;
  dds3ProcessID_t_o *v11;
  u64 v13;

  MainProcessData = nbGetMainProcessData();
  ActionProcessID = MainProcessData->ActionProcessID;
  NowActionProcess = MainProcessData->NowActionProcess;
  v6 = MainProcessData;
  if (ActionProcessID->m_Items[NowActionProcess])
  {
    v8 = MainProcessData->ActionProcessID;
    v9 = MainProcessData->NowActionProcess;
    v11 = v8->m_Items[v9];
    if (nbGetActionSeq(v11) == 1)
    {
      if (*(*(v13 + 184) + 20LL) != v6->orderindex)
      {
        nbCameraState_CommandRoot_Init(v13);
      }
    }
  }
}

// 0x166cc00
void nbCameraState_CommandRoot_Init(void) {
  u32 state_old;
  nbMainProcessData_t_o *data;

  data = 0;
  data = nbGetMainProcessData();
  state_old = nbCameraCurrent->state_old;
  if (state_old == 1)
    goto LABEL_19;
  if (state_old == 10)
    goto LABEL_19;
LABEL_13:
  if (state_old == 17)
    goto LABEL_19;
LABEL_22:
  if (nbCameraCRSetPlayerFormRequestFlag)
  {
    nbSetPlayerFormation(&data, 0);
    nbCameraCRSetPlayerFormRequestFlag = 0;
  }
LABEL_37:
  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  effBTLModelAllShow();
  nbCameraShot_CommandFixPos_Set(&nbCameraCurrent);
  nbCameraCommand_GroundCollision(&nbCameraCurrent);
  nbCameraState_Command_KORONZCheck();
  nbCameraState_CommandRoot_OrderIndex = data->orderindex;
}

// 0x166d340
void nbCameraState_CommandTargetSel_Calc(void) {
  ;
}

// 0x166cff0
void nbCameraState_CommandTargetSel_Init(void) {
  nbMainProcessData_t_o *MainProcessData;
  u32 v6;
  u32 TargetParty;
  u32 TargetNumber;
  u32 v10;
  u32 v11;
  s32 v12;
  nbFormation_t_o *TargetFormation;

  MainProcessData = nbGetMainProcessData();
  nbCameraState_InvokeTargetSelect_SearchSet();
  v6 = effBTLSkillGetInvokeParty();
  TargetParty = effBTLSkillGetTargetParty();
  TargetNumber = effBTLSkillGetTargetNumber();
  if (!TargetNumber)
  {
    v12 = 0;
    if (MainProcessData->TarSelType == 1)
      goto LABEL_19;
LABEL_29:
    if (v12 == 768)
    {
      nbCameraShot_AllParty_Set(&nbCameraCurrent);
        goto LABEL_26;
    }
    else
    {
      if (v6 == TargetParty)
      {
        nbWaitUntilCreateMainCamera_1Frame = 1;
        nbCameraShot_FriendParty_Set(&nbCameraCurrent);
          goto LABEL_26;
      }
      else
      {
        effBTLModelAllPopPosition();
        effBTLModelAllPopRotate();
        effBTLModelAllShow();
        nbCameraShot_CommandFixPos_Set(&nbCameraCurrent);
        nbCameraCommand_GroundCollision(&nbCameraCurrent);
        nbCameraState_Command_KORONZCheck();
          goto LABEL_26;
      }
    }
    goto LABEL_59;
  }
  v10 = TargetNumber;
  v11 = 0;
  v12 = 0;
  do
  {
    TargetFormation = effBTLSkillGetTargetFormation(v11++);
    v12 |= TargetFormation->stat & 0x300;
  }
  while (v10 != v11);
  if (MainProcessData->TarSelType != 1)
    goto LABEL_29;
LABEL_19:
  nbCameraShot_Summon_Set(&nbCameraCurrent);
  {
LABEL_26:
  }
LABEL_59:
  nbCameraCommand_GroundCollision(&nbCameraCurrent);
}

// 0x166ad90
void nbCameraState_Command_KORONZCheck(void) {
  nbMainProcessData_t_o *MainProcessData;
  s64 orderindex;
  nbMainProcessData_t_o *v5;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v9;
  u64 formindex;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v14;
  u64 i;
  struct nbFormation_t_array *v16;
  nbFormation_t_o *v18;
  f32 v23;
  f32 v24;
  f32 h;
  f32 scl;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o pEye;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&pEye.x = 0;
  *&pEye.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v27.x = 0;
  *&v27.z = 0;
  sub_854690(&pEye.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v27.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    orderindex = MainProcessData->orderindex;
    v5 = MainProcessData;
    if (orderindex != -1)
    {
      order = MainProcessData->order;
      party = MainProcessData->party;
      v9 = order->m_Items[orderindex];
      formindex = party->m_Items[v9]->formindex;
      if (formindex <= 0xF)
      {
        form = MainProcessData->form;
        v14 = form->m_Items[formindex];
        if ((v14->stat & 0x200) == 0)
        {
          for (i = 0; i != 32; ++i)
          {
            v16 = v5->form;
            v18 = v16->m_Items[i];
            pFormation = v18;
            if ((v18->stat & 0x103) == 0x103 && v18 != v14)
            {
              if (effBTLModelGetID(&pFormation) == 130)
              {
                effBTLModelShow(&pFormation);
                sub_854930(&v27, 0);
                sub_854710(&v27, 0);
                sub_854930(&v27, 1u);
                sub_854930(&v27, 2u);
                SDF_VU0__LOADVECTOR(nbCameraCurrent->direction);
                SDF_VU0__LOADVECTOR_B(v27);
                SDF_VU0__MULVECTOR();
                SDF_VU0__LOADVECTOR_B(nbCameraCurrent->target);
                SDF_VU0__ADDVECTOR();
                SDF_VU0__STOREVECTOR_B(&p);
                SDF_VU0__STOREVECTOR(&pEye);
                sub_854710(&pFormation->center, 1u);
                v24 = v23;
                h = pFormation->h;
                scl = pFormation->scl;
                effBTLModelCheckBoundsHide(
                  &pFormation,
                  115.0,
                  -(v24 + ((h * scl) * -0.5)),
                  &p,
                  &pEye,
                  &dds3CameraUpVector,
                  0);
              }
            }
          }
        }
      }
    }
  }
}
