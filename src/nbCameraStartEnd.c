#include "types.h"

typedef struct effBezier4PPart_t effBezier4PPart_t;
typedef struct nbCameraStartEnd_NBCAMERA_STARTANIM nbCameraStartEnd_NBCAMERA_STARTANIM;
typedef struct nbCameraState_Start_t nbCameraState_Start_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

struct nbCameraStartEnd_NBCAMERA_STARTANIM {
    s32 value__;
};

static f32 NBCAMERA_START_FOVY;
static f32 NBCAMERA_START_FOVY_WIDTH_RATIO;
static f32 NBCAMERA_START_EYE_S_HEIGHT;
static f32 NBCAMERA_START_EYE_E_HEIGHT;
static f32 NBCAMERA_START_LOADING_STEP;
static f32 NBCAMERA_START_RADIUS_S_MIN;
static f32 NBCAMERA_START_RADIUS_E_MIN;
static nbCameraState_Start_t *nbCameraState_Start_Camera;
static f32 nbCameraStartAnimAccele;
static f32 nbCameraStartAnimLoadEndStep;
static u32 nbCameraStartAnimProcess;
static s32 nbCameraStartAnimFrame;
static u8 nbCameraStartReadCFlag;
static s32 nbCameraStartRCount;
static u8 nbCameraStartCameraCFlag;
static s32 nbCameraStartCCount;
static f32 NBCAMERA_START_BA_RADIUS_E_MIN;
static f32 NBCAMERA_START_BA_RADIUS_P_MIN;
static f32 NBCAMERA_START_BA_WIDTH_DEF;
static s32 nbCameraStart_BA_AnimFrame;
static effBezier4PPart_t *nbCameraStart_BA_B4P_Target;
static effBezier4PPart_t *nbCameraStart_BA_B4P_Eye;
static nbCamera_t *nbCameraStateEndComPos;

void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_B_A(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
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
void SetRotateMatrixY(f32 aAngle);
s32 dds3Bezier4PPartRun(effBezier4PPart_t **pPart, sdfVector4_t *pOut);
void effBTLModelAllShow(void);
f32 effBTLModelGetHeight(nbFormation_t **pFormation);
f32 effBTLModelGetRadius(nbFormation_t **pFormation);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
f32 effBTLModelGroupGetSphereExp(u32 group, u32 model);
void effBezier4PPart_t__Clear(effBezier4PPart_t *this);
void nbCameraModelGroupGetCenter(u32 group);
f32 nbCameraModelGroupGetMaxLength(sdfVector4_t pPos, u32 group);
void nbCameraState_Start_Animation(nbCamera_t **pNbCamera);
void nbCameraState_Start_BA_Animation(nbCamera_t **pNbCamera);
void nbCameraState_Start_BA_Set(nbCamera_t **pNbCamera);
void nbCameraState_Start_Set(nbCamera_t **pNbCamera);
void nbCamera_t__Copy(nbCamera_t *this, nbCamera_t *data);
f32 nbGetEnemyInterval(void);
nbMainProcessData_t *nbGetMainProcessData(void);
f32 nbGetPartyDistance(void);
f32 sdfAtan(f32 aX);

// 0x16caae0
void nbCameraModelGroupGetCenter(u32 group) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v6;
  u64 v7;
  u32 v8;
  struct nbFormation_t_array *form;
  f32 v12;
  f32 v13;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v14.x = 0;
  *&v14.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v14.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  p.z = 0.0;
  *&p.x = 0;
  v6 = MainProcessData;
  v7 = 0;
  v8 = 0;
  do
  {
    form = v6->form;
    pFormation = form->m_Items[v7];
    if ((pFormation->stat & group) != 0 && (pFormation->stat & 1) != 0)
    {
      effBTLModelGetSphereCenter(&pFormation);
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
    v12 = v8;
    v13 = 1.0 / v12;
  }
  else
  {
    v13 = 1.0;
  }
  v14.x = v13;
  v14.y = v13;
  v14.z = v13;
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v14);
  SDF_VU0__MULVECTOR();
}

// 0x16cacc0
f32 nbCameraModelGroupGetMaxLength(sdfVector4_t pPos, u32 group) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  f32 v15;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v18;

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
    if ((pFormation->stat & group) != 0 && (pFormation->stat & 1) != 0)
    {
      effBTLModelGetSphereCenter(&pFormation);
      v18.x = x;
      v18.y = y;
      v18.z = z;
      v18.w = w;
      SDF_VU0__LOADVECTOR_B(v18);
      SDF_VU0__SUBVECTOR();
      v15 = SDF_VU0__GETLENGTH() + (pFormation->r * pFormation->scl);
      if (v15 > v8)
        v8 = v15;
    }
  }
  return v8;
}

// 0x16cae40
f32 nbCameraModelGroupGetSphere(u32 group) {
  f32 MaxLength;
  UnityEngine_Vector4_o v7;

  *&v7.x = 0;
  *&v7.z = 0;
  sub_854690(&v7.x, 0.0, 0.0, 0.0, 0.0);
  nbCameraModelGroupGetCenter(group);
  SDF_VU0__STOREVECTOR(&v7);
  MaxLength = nbCameraModelGroupGetMaxLength(v7, group);
  SDF_VU0__LOADVECTOR(v7);
  return MaxLength;
}

// 0x16cde00
void nbCameraState_End_Animation(nbCamera_t **pNbCamera) {
  ;
}

// 0x16cdea0
void nbCameraState_End_Calc(void) {

}

// 0x16cde10
void nbCameraState_End_Init(void) {

}

// 0x16cddf0
void nbCameraState_End_Set(nbCamera_t **pNbCamera) {
  ;
}

// 0x16cdf30
void nbCameraState_End_SetComPos(nbCamera_t **pNbCamera) {
  nbCamera_t__Copy(nbCameraStateEndComPos, *pNbCamera);
}

// 0x16caf10
void nbCameraState_Start_Animation(nbCamera_t **pNbCamera) {
  nbCameraStartEnd_c *v4;
  struct nbCameraStartEnd_StaticFields **p_static_fields;
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v10;
  struct nbFormation_t_array *v11;
  nbFormation_t_o *v13;
  struct nbFormation_t_array *v14;
  nbFormation_t_o *v16;
  struct nbFormation_t_array *v17;
  nbFormation_t_o *v19;
  struct nbFormation_t_array *v20;
  nbFormation_t_o *v22;
  struct nbFormation_t_array *v23;
  nbFormation_t_o *v25;
  struct nbFormation_t_array *v26;
  nbFormation_t_o *v28;
  struct nbFormation_t_array *v29;
  nbFormation_t_o *v31;
  struct nbFormation_t_array *v32;
  nbFormation_t_o *v34;
  struct nbFormation_t_array *v35;
  nbFormation_t_o *v37;
  struct effBezier4PPart_t_o *B4P_Target;
  struct effBezier4PPart_t_o *B4P_Eye;
  struct effBezier4PPart_t_o *v41;
  nbCamera_t_o *v42;
  UnityEngine_Vector4_o v47;
  UnityEngine_Vector4_o pOut;

  *&pOut.x = 0;
  *&pOut.z = 0;
  *&v47.x = 0;
  *&v47.z = 0;
  sub_854690(&pOut.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v47.x, 0.0, 0.0, 0.0, 0.0);
  switch (nbCameraStartAnimProcess)
  {
    case 0u:
      nbCameraStartAnimLoadEndStep = 0.033333;
      nbCameraState_Start_Camera->B4P_Target->weight = 0.0;
      nbCameraState_Start_Camera->B4P_Target->step = NBCAMERA_START_LOADING_STEP;
      nbCameraState_Start_Camera->B4P_Eye->weight = 0.0;
      nbCameraState_Start_Camera->B4P_Eye->step = NBCAMERA_START_LOADING_STEP;
      nbCameraStartAnimAccele = (nbCameraStartAnimLoadEndStep
                                                  - NBCAMERA_START_LOADING_STEP)
                                                 / 10.0;
      nbCameraStartAnimProcess = 1;
      if ((v4->_2.bitflags2 & 2) != 0)
        goto LABEL_99;
      goto LABEL_102;
    case 1u:
      MainProcessData = nbGetMainProcessData();
      form = MainProcessData->form;
      v10 = form->m_Items[4];
      if ((~v10->stat & 0x201) == 0 && !v10->hunit)
        goto LABEL_101;
      v11 = MainProcessData->form;
      v13 = v11->m_Items[5];
      if ((~v13->stat & 0x201) == 0 && !v13->hunit)
        goto LABEL_101;
      v14 = MainProcessData->form;
      v16 = v14->m_Items[6];
      if ((~v16->stat & 0x201) == 0 && !v16->hunit)
        goto LABEL_101;
      v17 = MainProcessData->form;
      v19 = v17->m_Items[7];
      if ((~v19->stat & 0x201) == 0 && !v19->hunit)
        goto LABEL_101;
      v20 = MainProcessData->form;
      v22 = v20->m_Items[8];
      if ((~v22->stat & 0x201) == 0 && !v22->hunit)
        goto LABEL_101;
      v23 = MainProcessData->form;
      v25 = v23->m_Items[9];
      if ((~v25->stat & 0x201) == 0 && !v25->hunit)
        goto LABEL_101;
      v26 = MainProcessData->form;
      v28 = v26->m_Items[10];
      if ((~v28->stat & 0x201) == 0 && !v28->hunit)
        goto LABEL_101;
      v29 = MainProcessData->form;
      v31 = v29->m_Items[11];
      if ((~v31->stat & 0x201) == 0 && !v31->hunit)
        goto LABEL_101;
      v32 = MainProcessData->form;
      v34 = v32->m_Items[12];
      if ((~v34->stat & 0x201) == 0 && !v34->hunit)
        goto LABEL_101;
      v35 = MainProcessData->form;
      v37 = v35->m_Items[13];
      if ((~v37->stat & 0x201) == 0 && !v37->hunit)
      {
LABEL_101:
          goto LABEL_102;
        goto LABEL_99;
      }
      nbCameraStartAnimProcess = 2;
      nbCameraStartReadCFlag = 1;
      nbCameraStartCameraCFlag = 1;
      if ((v4->_2.bitflags2 & 2) != 0)
      {
LABEL_99:
      }
LABEL_102:
      dds3Bezier4PPartRun(&nbCameraState_Start_Camera->B4P_Eye, &v47);
      dds3Bezier4PPartRun(&nbCameraState_Start_Camera->B4P_Target, &pOut);
      SDF_VU0__LOADVECTOR(pOut);
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
      SDF_VU0__LOADVECTOR_B(v47);
      SDF_VU0__SUBVECTOR();
      v42 = *pNbCamera;
      v42->distance = SDF_VU0__GETLENGTH();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
      ++nbCameraStartAnimFrame;
      if (nbCameraStartReadCFlag)
      {
        ++nbCameraStartRCount;
      }
      if (nbCameraStartCameraCFlag)
      {
        ++nbCameraStartCCount;
      }
      return;
    case 2u:
      nbCameraState_Start_Camera->B4P_Target->step = nbCameraState_Start_Camera->B4P_Target->step
                                                                                + nbCameraStartAnimAccele;
      nbCameraState_Start_Camera->B4P_Eye->step = nbCameraState_Start_Camera->B4P_Eye->step
                                                                                 + nbCameraStartAnimAccele;
      B4P_Target = nbCameraState_Start_Camera->B4P_Target;
      if (B4P_Target->step < nbCameraStartAnimLoadEndStep)
        goto LABEL_98;
      B4P_Target->step = nbCameraStartAnimLoadEndStep;
      (*p_static_fields)->nbCameraState_Start_Camera->B4P_Eye->step = (*p_static_fields)->nbCameraStartAnimLoadEndStep;
      (*p_static_fields)->nbCameraStartAnimProcess = 3;
      if ((v4->_2.bitflags2 & 2) == 0)
        goto LABEL_102;
      goto LABEL_99;
    case 3u:
      if (nbCameraState_Start_Camera->B4P_Eye->weight <= 0.75)
        goto LABEL_98;
      nbCameraStartAnimProcess = 4;
      if ((v4->_2.bitflags2 & 2) == 0)
        goto LABEL_102;
      goto LABEL_99;
    case 4u:
      nbCameraState_Start_Camera->B4P_Eye->step = nbCameraState_Start_Camera->B4P_Eye->step
                                                                             * 0.965;
      B4P_Eye = nbCameraState_Start_Camera->B4P_Eye;
      if (B4P_Eye->step < 0.001)
      {
        B4P_Eye->step = 0.0;
      }
      nbCameraState_Start_Camera->B4P_Target->step = nbCameraState_Start_Camera->B4P_Eye->step;
      v41 = nbCameraState_Start_Camera->B4P_Eye;
      if (v41->weight >= 1.0)
        goto LABEL_117;
      if (v41->step == 0.0)
      {
LABEL_117:
        nbCameraStartAnimProcess = 5;
      }
      goto LABEL_98;
    case 5u:
      return;
    default:
LABEL_98:
      if ((v4->_2.bitflags2 & 2) != 0)
        goto LABEL_99;
      goto LABEL_102;
  }
}

// 0x16cbf10
void nbCameraState_Start_BA_Animation(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;
  nbMainProcessData_t_o *v7;
  nbFormation_t_o *v9;
  struct nbFormation_t_array *v10;
  nbFormation_t_o *v12;
  struct nbFormation_t_array *v13;
  nbFormation_t_o *v15;
  struct nbFormation_t_array *v16;
  nbFormation_t_o *v17;
  struct nbFormation_t_array *v19;
  nbFormation_t_o *v21;
  struct nbFormation_t_array *v22;
  nbFormation_t_o *v24;
  struct nbFormation_t_array *v25;
  nbFormation_t_o *v27;
  struct nbFormation_t_array *v28;
  nbFormation_t_o *v30;
  struct nbFormation_t_array *v31;
  nbFormation_t_o *v33;
  struct nbFormation_t_array *v34;
  nbFormation_t_o *v36;
  nbCameraStartEnd_c *v37;
  struct effBezier4PPart_t_o *nbCameraStart_BA_B4P_Eye;
  struct effBezier4PPart_t_o *v42;
  struct effBezier4PPart_t_o *v43;
  struct effBezier4PPart_t_o *nbCameraStart_BA_B4P_Target;
  nbCamera_t_o *v45;
  struct effBezier4PPart_t_o *v48;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o pOut;

  *&pOut.x = 0;
  *&pOut.z = 0;
  *&v51.x = 0;
  *&v51.z = 0;
  sub_854690(&pOut.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v51.x, 0.0, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  form = MainProcessData->form;
  v7 = MainProcessData;
  v9 = form->m_Items[4];
  if ((~v9->stat & 0x201) == 0 && !v9->hunit)
    goto LABEL_56;
  v10 = MainProcessData->form;
  v12 = v10->m_Items[5];
  if ((~v12->stat & 0x201) == 0 && !v12->hunit)
    goto LABEL_56;
  v13 = MainProcessData->form;
  v15 = v13->m_Items[6];
  if ((~v15->stat & 0x201) == 0 && !v15->hunit)
    goto LABEL_56;
  v16 = MainProcessData->form;
  v17 = v16->m_Items[7];
  if ((~v17->stat & 0x201) == 0 && !v17->hunit)
    goto LABEL_56;
  v19 = MainProcessData->form;
  v21 = v19->m_Items[8];
  if ((~v21->stat & 0x201) == 0 && !v21->hunit)
    goto LABEL_56;
  v22 = MainProcessData->form;
  v24 = v22->m_Items[9];
  if ((~v24->stat & 0x201) == 0 && !v24->hunit)
    goto LABEL_56;
  v25 = MainProcessData->form;
  v27 = v25->m_Items[10];
  if ((~v27->stat & 0x201) == 0 && !v27->hunit)
    goto LABEL_56;
  v28 = MainProcessData->form;
  v30 = v28->m_Items[11];
  if ((~v30->stat & 0x201) == 0 && !v30->hunit)
    goto LABEL_56;
  v31 = MainProcessData->form;
  v33 = v31->m_Items[12];
  if ((~v33->stat & 0x201) == 0 && !v33->hunit)
    goto LABEL_56;
  v34 = MainProcessData->form;
  v36 = v34->m_Items[13];
  if ((~v36->stat & 0x201) == 0 && !v36->hunit)
  {
LABEL_56:
    goto LABEL_57;
  }
  nbCameraStart_BA_B4P_Eye->step = nbCameraStart_BA_B4P_Eye->step
                                                            + nbCameraStartAnimAccele;
  nbCameraStart_BA_B4P_Target->step = nbCameraStart_BA_B4P_Target->step
                                                               + nbCameraStartAnimAccele;
  if (nbCameraStart_BA_B4P_Eye->step < nbCameraStartAnimLoadEndStep)
  {
LABEL_57:
    if ((v37->_2.bitflags2 & 2) == 0)
      goto LABEL_60;
    goto LABEL_58;
  }
  nbCameraStart_BA_B4P_Eye->step = nbCameraStartAnimLoadEndStep;
  nbCameraStart_BA_B4P_Target->step = nbCameraStartAnimLoadEndStep;
  if ((v37->_2.bitflags2 & 2) != 0)
  {
LABEL_58:
  }
LABEL_60:
  dds3Bezier4PPartRun(&nbCameraStart_BA_B4P_Eye, &v51);
  dds3Bezier4PPartRun(&nbCameraStart_BA_B4P_Target, &pOut);
  v42 = nbCameraStart_BA_B4P_Eye;
  if (v42->weight > 0.75)
  {
    v42->step = v42->step * 0.965;
    v43 = nbCameraStart_BA_B4P_Eye;
    if (v43->step < 0.001)
    {
      v43->step = 0.0;
    }
    nbCameraStart_BA_B4P_Target->step = nbCameraStart_BA_B4P_Target->step
                                                                 * 0.965;
    if (nbCameraStart_BA_B4P_Target->step < 0.001)
    {
      nbCameraStart_BA_B4P_Target->step = 0.0;
    }
  }
  SDF_VU0__LOADVECTOR_B(v51);
  SDF_VU0__LOADVECTOR(pOut);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__SUBVECTOR();
  v45 = *pNbCamera;
  v45->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  v48 = nbCameraStart_BA_B4P_Eye;
  if (v48->weight >= 1.0)
    goto LABEL_98;
  if (v48->step == 0.0)
  {
LABEL_98:
    nbCameraStartAnimProcess = 5;
    v7->stat |= 0x2000u;
  }
  effBTLModelAllShow();
  ++nbCameraStart_BA_AnimFrame;
}

// 0x16cc580
void nbCameraState_Start_BA_Set(nbCamera_t **pNbCamera) {
  f32 v3;
  nbCamera_t_o *v4;
  u64 *v5;
  f32 v7;
  f32 v8;
  nbMainProcessData_t_o *MainProcessData;
  u32 v11;
  s64 i;
  struct nbFormation_t_array *form;
  s64 v14;
  f32 v16;
  f32 v17;
  f32 Height;
  f32 v19;
  f32 v20;
  bool v21;
  struct nbFormation_t_array *v22;
  nbFormation_t_o *v23;
  f32 v24;
  u32 v25;
  f32 v26;
  struct nbFormation_t_array *v27;
  f32 r;
  f32 scl;
  nbFormation_t_o *v32;
  struct nbFormation_t_array *v33;
  nbFormation_t_o *v34;
  struct nbFormation_t_array *v35;
  nbFormation_t_o *v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  struct nbFormation_t_array *v51;
  nbFormation_t_o *v52;
  struct nbFormation_t_array *v53;
  nbFormation_t_o *v54;
  struct nbFormation_t_array *v55;
  nbFormation_t_o *v56;
  struct nbFormation_t_array *v57;
  nbFormation_t_o *v58;
  f32 v59;
  f32 v60;
  f32 v61;
  f32 v64;
  f32 NBCAMERA_START_FOVY;
  f32 v67;
  f32 SphereExp;
  f32 v69;
  struct UnityEngine_Vector3_array *point;
  struct UnityEngine_Vector3_array *v74;
  struct UnityEngine_Vector3_array *v76;
  struct UnityEngine_Vector3_array *v78;
  struct UnityEngine_Vector3_array *v80;
  struct UnityEngine_Vector3_array *v82;
  f32 EnemyInterval;
  f32 v86;
  f32 v87;
  nbCameraStartEnd_c *v88;
  f32 v89;
  f32 NBCAMERA_START_BA_RADIUS_E_MIN;
  f32 *p_NBCAMERA_START_FOVY;
  f32 v94;
  f32 v95;
  struct nbFormation_t_array *v97;
  struct UnityEngine_Vector3_array *v103;
  struct UnityEngine_Vector3_array *v105;
  struct UnityEngine_Vector3_array *v107;
  struct UnityEngine_Vector3_array *v109;
  struct UnityEngine_Vector3_array *v111;
  struct UnityEngine_Vector3_array *v113;
  struct UnityEngine_Vector3_array *v116;
  struct UnityEngine_Vector3_array *v118;
  struct UnityEngine_Vector3_array *v120;
  struct UnityEngine_Vector3_array *v123;
  struct UnityEngine_Vector3_array *v125;
  struct UnityEngine_Vector3_array *v127;
  struct UnityEngine_Vector3_array *v130;
  struct UnityEngine_Vector3_array *v132;
  struct UnityEngine_Vector3_array *v134;
  struct UnityEngine_Vector3_array *v138;
  struct UnityEngine_Vector3_array *v140;
  struct UnityEngine_Vector3_array *v142;
  UnityEngine_Vector4_o v148;
  UnityEngine_Vector4_o v149;
  UnityEngine_Vector4_o v150;
  UnityEngine_Vector4_o v151;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v153;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v155;
  UnityEngine_Vector4_o v156;
  UnityEngine_Vector4_o v157;
  UnityEngine_Vector4_o v158;

  v3 = 0.0;
  *&v153.x = 0;
  *&v153.z = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v151.x = 0;
  *&v151.z = 0;
  *&v150.x = 0;
  *&v150.z = 0;
  *&v149.x = 0;
  *&v149.z = 0;
  *&v148.x = 0;
  *&v148.z = 0;
  sub_8546D0(&v153, 1.0, 0.0, 0.0);
  v4 = Allocate(nbCamera_t);
  nbCamera_t___ctor(v4);
  v5 = Allocate(nbCamera_t);
  nbCamera_t___ctor(v5);
  sub_8546D0(&p, 1.0, 0.0, 0.0);
  sub_8546D0(&v151, 1.0, 0.0, 0.0);
  sub_8546D0(&v150, 1.0, 0.0, 0.0);
  sub_8546D0(&v149, 1.0, 0.0, 0.0);
  sub_8546D0(&v148, 1.0, 0.0, 0.0);
  v7 = 0.0;
  v8 = 0.0;
  MainProcessData = nbGetMainProcessData();
  v11 = 0;
  for (i = 8; i != 18; ++i)
  {
    while (1)
    {
      form = MainProcessData->form;
      v14 = *(&form->obj.klass + i);
      pFormation = v14;
      if ((*(v14 + 136) & 1) != 0)
        break;
      if (++i == 18)
        goto LABEL_28;
    }
    v16 = *(v14 + 96) * *(v14 + 108);
    v17 = v16 + v16;
    v3 = v3 + v17;
    Height = effBTLModelGetHeight(&pFormation);
    if (v7 >= Height)
      v19 = v7;
    else
      v19 = Height;
    if (v8 > Height)
      v20 = Height;
    else
      v20 = v8;
    v21 = v11++ == 0;
    if (v21)
      v7 = Height;
    else
      v7 = v19;
    if (v21)
      v8 = Height;
    else
      v8 = v20;
  }
LABEL_28:
  v22 = MainProcessData->form;
  v23 = v22->m_Items[0];
  pFormation = v23;
  if ((v23->stat & 1) != 0)
  {
    r = v23->r;
    scl = v23->scl;
    v24 = r * scl;
    v26 = effBTLModelGetHeight(&pFormation);
    v25 = 1;
    v27 = MainProcessData->form;
    if ((v27->max_length & 0xFFFFFFFE) == 0)
    {
LABEL_37:
    }
  }
  else
  {
    v24 = 0.0;
    v25 = 0;
    v26 = 0.0;
    v27 = MainProcessData->form;
    if ((v27->max_length & 0xFFFFFFFE) == 0)
      goto LABEL_37;
  }
  v32 = v27->m_Items[1];
  pFormation = v32;
  if ((v32->stat & 1) == 0)
  {
    v33 = MainProcessData->form;
    if (LODWORD(v33->max_length) > 2uLL)
      goto LABEL_40;
LABEL_56:
  }
  v37 = v32->r;
  v38 = v32->scl;
  v39 = v37 * v38;
  v40 = effBTLModelGetHeight(&pFormation);
  if (v25)
  {
    if (v24 >= v39)
      v39 = v24;
    if (v26 < v40)
      v26 = v40;
  }
  else
  {
    v26 = v40;
  }
  v24 = v39;
  ++v25;
  v33 = MainProcessData->form;
  if (LODWORD(v33->max_length) <= 2uLL)
    goto LABEL_56;
LABEL_40:
  v34 = v33->m_Items[2];
  pFormation = v34;
  if ((v34->stat & 1) == 0)
  {
    v35 = MainProcessData->form;
    if ((v35->max_length & 0xFFFFFFFC) != 0)
      goto LABEL_42;
LABEL_68:
  }
  v42 = v34->r;
  v43 = v34->scl;
  v44 = v42 * v43;
  v45 = effBTLModelGetHeight(&pFormation);
  if (v25)
  {
    if (v24 >= v44)
      v44 = v24;
    if (v26 < v45)
      v26 = v45;
  }
  else
  {
    v26 = v45;
  }
  v24 = v44;
  ++v25;
  v35 = MainProcessData->form;
  if ((v35->max_length & 0xFFFFFFFC) == 0)
    goto LABEL_68;
LABEL_42:
  v36 = v35->m_Items[3];
  pFormation = v36;
  if ((v36->stat & 1) == 0)
  {
    if (v7 >= 450.0)
      goto LABEL_90;
LABEL_80:
    if (v26 < 300.0)
      goto LABEL_90;
    v51 = MainProcessData->form;
    v52 = v51->m_Items[0];
    pFormation = v52;
    if ((v52->stat & 1) != 0)
    {
      v52->pos.z = v52->pos.z + -250.0;
      v53 = MainProcessData->form;
      if ((v53->max_length & 0xFFFFFFFE) != 0)
      {
LABEL_84:
        v54 = v53->m_Items[1];
        pFormation = v54;
        if ((v54->stat & 1) != 0)
        {
          v54->pos.z = v54->pos.z + -250.0;
          v55 = MainProcessData->form;
          if (LODWORD(v55->max_length) > 2uLL)
          {
LABEL_86:
            v56 = v55->m_Items[2];
            pFormation = v56;
            if ((v56->stat & 1) != 0)
            {
              v56->pos.z = v56->pos.z + -250.0;
              v57 = MainProcessData->form;
              if ((v57->max_length & 0xFFFFFFFC) != 0)
              {
LABEL_88:
                v58 = v57->m_Items[3];
                pFormation = v58;
                if ((v58->stat & 1) != 0)
                  v58->pos.z = v58->pos.z + -250.0;
                goto LABEL_90;
              }
            }
            else
            {
              v57 = MainProcessData->form;
              if ((v57->max_length & 0xFFFFFFFC) != 0)
                goto LABEL_88;
            }
          }
        }
        else
        {
          v55 = MainProcessData->form;
          if (LODWORD(v55->max_length) > 2uLL)
            goto LABEL_86;
        }
      }
    }
    else
    {
      v53 = MainProcessData->form;
      if ((v53->max_length & 0xFFFFFFFE) != 0)
        goto LABEL_84;
    }
  }
  v47 = v36->r;
  v48 = v36->scl;
  v49 = v47 * v48;
  v50 = effBTLModelGetHeight(&pFormation);
  if (v25)
  {
    if (v24 >= v49)
      v49 = v24;
    if (v26 < v50)
      v26 = v50;
  }
  else
  {
    v26 = v50;
  }
  v24 = v49;
  ++v25;
  if (v7 < 450.0)
    goto LABEL_80;
LABEL_90:
  effBTLModelGroupGetSphereExp(0x100u, 0);
  SDF_VU0__STOREVECTOR(&p);
  p.y = 0.0;
  p.z = p.z - v24;
  effBTLModelGroupGetSphereExp(0x200u, 0);
  SDF_VU0__STOREVECTOR(&v148);
  v155.y = v8 * -0.5;
  v148.y = v8 * -0.5;
  if (v7 >= 450.0)
  {
    if (v7 > 800.0)
    {
      v59 = 0.715;
      goto LABEL_99;
    }
LABEL_98:
    v59 = 0.65;
    goto LABEL_99;
  }
  if (v8 > 150.0)
    goto LABEL_98;
  v59 = 0.6635;
LABEL_99:
  v155.x = v148.x;
  v155.z = v148.z;
  v155.w = v148.w;
  SDF_VU0__LOADVECTOR(v155);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v60 = SDF_VU0__GETLENGTH() * 0.5;
  v61 = v24 * 0.5;
  SDF_VU0__NORMALIZE();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(v153);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__INTERPOLATE(v59);
  SDF_VU0__STOREVECTOR(v5 + 2);
  SDF_VU0__LOADVECTOR(v148);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(v5 + 1);
  v64 = v60 - v61;
  v67 = sdfAtan((NBCAMERA_START_FOVY * 1.55) * 0.5, 0);
  *(v5 + 12) = v64 / v67;
  SphereExp = effBTLModelGroupGetSphereExp(0x100u, 0);
  v156.w = *(v5 + 11);
  v69 = *(v5 + 12) + (fmaxf(SphereExp, 480.0) / v67);
  *(v5 + 12) = v69;
  v149.x = -v69;
  v149.y = -v69;
  v149.z = -v69;
  v156.z = *(v5 + 10);
  v156.x = *(v5 + 8);
  v156.y = *(v5 + 9);
  SDF_VU0__LOADVECTOR(v156);
  SDF_VU0__LOADVECTOR_B(v149);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(*(v5 + 1), 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v151);
  point = nbCameraStart_BA_B4P_Eye->point;
  point->m_Items[3].x = v151.x;
  v74 = nbCameraStart_BA_B4P_Eye->point;
  v74->m_Items[3].y = v151.y;
  v76 = nbCameraStart_BA_B4P_Eye->point;
  v76->m_Items[3].z = v151.z;
  v78 = nbCameraStart_BA_B4P_Target->point;
  v78->m_Items[3].x = *(v5 + 4);
  v80 = nbCameraStart_BA_B4P_Target->point;
  v80->m_Items[3].y = *(v5 + 5);
  v82 = nbCameraStart_BA_B4P_Target->point;
  v82->m_Items[3].z = *(v5 + 6);
  EnemyInterval = nbGetEnemyInterval();
  if (v11 >= 2)
  {
LABEL_126:
    v86 = (v11 - 1);
    v3 = v3 + (EnemyInterval * v86);
  }
LABEL_127:
  if (v7 <= v3)
    v87 = v3;
  else
    v87 = v7;
  v89 = v87 * 0.5;
  else
  {
    if (NBCAMERA_START_BA_RADIUS_E_MIN <= v89)
      goto LABEL_140;
  }
  if ((v88->_2.bitflags2 & 2) != 0)
  {
    v89 = NBCAMERA_START_BA_RADIUS_E_MIN;
  }
  else
  {
    v89 = NBCAMERA_START_BA_RADIUS_E_MIN;
  }
LABEL_140:
  v4->target.x = 0.0;
  v4->target.y = v7 * -0.5;
  v4->target.z = nbGetPartyDistance() * 0.5;
  p_NBCAMERA_START_FOVY = &NBCAMERA_START_FOVY;
  v94 = *p_NBCAMERA_START_FOVY;
  v95 = p_NBCAMERA_START_FOVY[1];
  v4->distance = (v89 * 0.75) / sdfAtan((v94 * v95) * 0.5, 0);
  v97 = MainProcessData->form;
  else if (!LODWORD(v97->max_length))
  {
    goto LABEL_152;
  }
  effBTLModelGetSphereCenter(v97->m_Items);
  SDF_VU0__STOREVECTOR(&v150);
  if (v25 <= 3)
  {
    v150.x = NBCAMERA_START_BA_WIDTH_DEF * -0.5;
  }
  v150.y = v4->target.y;
  v157.x = v4->target.x;
  v157.y = v150.y;
  v157.z = v4->target.z;
  v157.w = v4->target.w;
  SDF_VU0__LOADVECTOR(v157);
  SDF_VU0__LOADVECTOR_B(v150);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v4->direction);
  v158.w = v4->direction.w;
  v149.x = -v4->distance;
  v149.y = v149.x;
  v149.z = v149.x;
  v158.z = v4->direction.z;
  v158.x = v4->direction.x;
  v158.y = v4->direction.y;
  SDF_VU0__LOADVECTOR(v158);
  SDF_VU0__LOADVECTOR_B(v149);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(v4->target);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v151);
  v103 = nbCameraStart_BA_B4P_Eye->point;
  v103->m_Items[0].x = v151.x;
  v105 = nbCameraStart_BA_B4P_Eye->point;
  v105->m_Items[0].y = v151.y;
  v107 = nbCameraStart_BA_B4P_Eye->point;
  v107->m_Items[0].z = v151.z;
  v109 = nbCameraStart_BA_B4P_Target->point;
  v109->m_Items[0].x = v4->target.x;
  v111 = nbCameraStart_BA_B4P_Target->point;
  v111->m_Items[0].y = v4->target.y;
  v113 = nbCameraStart_BA_B4P_Target->point;
  v113->m_Items[0].z = v4->target.z;
  v149.x = -*(v5 + 12);
  v149.y = v149.x;
  v149.z = v149.x;
  SDF_VU0__LOADVECTOR(v4->direction);
  SDF_VU0__LOADVECTOR_B(v149);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(v4->target);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v151);
  v116 = nbCameraStart_BA_B4P_Eye->point;
  v116->m_Items[1].x = v151.x;
  v118 = nbCameraStart_BA_B4P_Eye->point;
  v118->m_Items[1].y = v151.y;
  v120 = nbCameraStart_BA_B4P_Eye->point;
  v120->m_Items[1].z = v151.z;
  SDF_VU0__LOADVECTOR(v4->target);
  SDF_VU0__LOADVECTOR_B(*(v5 + 1), 0);
  SDF_VU0__INTERPOLATE(0.333);
  SDF_VU0__STOREVECTOR(&v148);
  v123 = nbCameraStart_BA_B4P_Target->point;
  v123->m_Items[1].x = v148.x;
  v125 = nbCameraStart_BA_B4P_Target->point;
  v125->m_Items[1].y = v148.y;
  v127 = nbCameraStart_BA_B4P_Target->point;
  v127->m_Items[1].z = v148.z;
  v149.x = -*(v5 + 12);
  v149.y = v149.x;
  v149.z = v149.x;
  SDF_VU0__LOADVECTOR(v4->direction);
  SDF_VU0__LOADVECTOR_B(*(v5 + 2), 0);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__LOADVECTOR_B(v149);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(v4->target);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v151);
  v130 = nbCameraStart_BA_B4P_Eye->point;
  v130->m_Items[2].x = v151.x;
  v132 = nbCameraStart_BA_B4P_Eye->point;
  v132->m_Items[2].y = v151.y;
  v134 = nbCameraStart_BA_B4P_Eye->point;
  v134->m_Items[2].z = v151.z;
  SDF_VU0__LOADVECTOR(v4->target);
  SDF_VU0__LOADVECTOR_B(*(v5 + 1), 0);
  SDF_VU0__INTERPOLATE(0.666);
  SDF_VU0__STOREVECTOR(&v148);
  v138 = nbCameraStart_BA_B4P_Target->point;
  v138->m_Items[2].x = v148.x;
  v140 = nbCameraStart_BA_B4P_Target->point;
  v140->m_Items[2].y = v148.y;
  v142 = nbCameraStart_BA_B4P_Target->point;
  v142->m_Items[2].z = v148.z;
  (*pNbCamera)->fovy = NBCAMERA_START_FOVY;
  nbCameraStart_BA_B4P_Eye->weight = 0.0;
  nbCameraStart_BA_B4P_Eye->step = NBCAMERA_START_LOADING_STEP * 0.25;
  nbCameraStart_BA_B4P_Target->weight = 0.0;
  nbCameraStart_BA_B4P_Target->step = NBCAMERA_START_LOADING_STEP
                                                                * 0.25;
  nbCameraStartAnimLoadEndStep = 0.033333;
  nbCameraStartAnimAccele = (nbCameraStartAnimLoadEndStep
                                                - NBCAMERA_START_LOADING_STEP)
                                               / 10.0;
  nbCameraStartAnimProcess = 0;
  nbCameraStart_BA_AnimFrame = 0;
  nbCameraState_Start_BA_Animation(pNbCamera);
}

// 0x16cda70
void nbCameraState_Start_Calc(void) {
  if ((nbGetMainProcessData()->stat & 0x10) != 0)
  {
    nbCameraState_Start_BA_Animation(&nbCameraCurrent);
  }
  else
  {
    nbCameraState_Start_Animation(&nbCameraCurrent);
  }
}

// 0x16cdbe0
s32 nbCameraState_Start_CheckEnd(void) {
  struct nbCameraStartEnd_StaticFields **p_static_fields;
  u64 *v6;
  struct nbCameraStartEnd_StaticFields **v7;
  u64 *v10;
  s32 nbCameraStartCCount;
  s32 nbCameraStartRCount;

  if (nbCameraStartReadCFlag)
  {
    nbCameraStartReadCFlag = 0;
    nbCameraStartRCount = (*p_static_fields)->nbCameraStartRCount;
    v6 = sub_8D3950(s32, &nbCameraStartRCount);
    Write_2930400("nbCameraStart:Read Wait = {0:D} ****\n", v6);
  }
  if (nbCameraStartCameraCFlag)
  {
    else if (nbCameraStartAnimProcess != 5)
    {
      goto LABEL_28;
    }
    nbCameraStartCameraCFlag = 0;
    nbCameraStartCCount = (*v7)->nbCameraStartCCount;
    v10 = sub_8D3950(s32, &nbCameraStartCCount);
    Write_2930400("nbCameraStart：Anim Wait = {0:D} ****\n", v10);
  }
LABEL_28:
  return nbCameraStartAnimProcess == 5;
}

// 0x16cdb70
s32 nbCameraState_Start_GetAnimFrame(void) {
  return nbCameraStartAnimFrame;
}

// 0x16cd800
void nbCameraState_Start_Init(void) {
  u64 *v5;
  u64 *v8;

  else if ((nbGetMainProcessData()->stat & 0x10) == 0)
  {
    goto LABEL_6;
  }
  else if (nbCameraStart_BA_B4P_Target)
  {
    goto LABEL_17;
  }
  v5 = Allocate(effBezier4PPart_t);
  effBezier4PPart_t___ctor(v5);
  nbCameraStart_BA_B4P_Target = v5;
  effBezier4PPart_t__Clear(nbCameraStart_BA_B4P_Target);
  {
LABEL_26:
    if (!nbCameraStart_BA_B4P_Eye)
      goto LABEL_27;
    goto LABEL_31;
  }
LABEL_18:
    goto LABEL_26;
  if (!nbCameraStart_BA_B4P_Eye)
  {
LABEL_27:
    v8 = Allocate(effBezier4PPart_t);
    effBezier4PPart_t___ctor(v8);
    nbCameraStart_BA_B4P_Eye = v8;
    effBezier4PPart_t__Clear(nbCameraStart_BA_B4P_Eye);
  }
LABEL_31:
  nbCameraState_Start_BA_Set(&nbCameraCurrent);
LABEL_38:
  nbCameraStartReadCFlag = 0;
  nbCameraStartRCount = 0;
  nbCameraStartCameraCFlag = 0;
  nbCameraStartCCount = 0;
}

// 0x16cb700
void nbCameraState_Start_Set(nbCamera_t **pNbCamera) {
  f32 v3;
  nbMainProcessData_t_o *MainProcessData;
  f32 v7;
  nbMainProcessData_t_o *v8;
  u64 v9;
  u32 v10;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v13;
  f32 v14;
  f32 v15;
  f32 Height;
  f32 EnemyInterval;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 NBCAMERA_START_FOVY;
  f32 v26;
  f32 v27;
  f32 v29;
  f32 NBCAMERA_START_RADIUS_E_MIN;
  f32 v31;
  f32 Radius;
  f32 NBCAMERA_START_RADIUS_S_MIN;
  f32 v37;
  f32 y;
  f32 v41;
  f32 NBCAMERA_START_EYE_E_HEIGHT;
  f32 v44;
  s64 v45;
  u64 v46;
  struct UnityEngine_Vector3_array *point;
  f32 z;
  f32 v51;
  f32 v52;
  struct UnityEngine_Vector3_array *v53;
  f32 *v55;
  f32 v58;
  s64 v59;
  u64 v60;
  s32 v61;
  struct UnityEngine_Vector3_array *v62;
  f32 v64;
  f32 v65;
  f32 v66;
  struct UnityEngine_Vector3_array *v67;
  f32 *v69;
  u32 v70;
  s64 v71;
  f32 v72;
  UnityEngine_Vector4_o v73;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v75;
  UnityEngine_Vector4_o v76;
  UnityEngine_Vector4_o v77;
  UnityEngine_Vector4_o v78;
  nbFormation_t_o *v79;
  nbFormation_t_o *pFormation;

  v3 = 0.0;
  v79 = 0;
  pFormation = 0;
  *&v78.x = 0;
  *&v78.z = 0;
  v72 = 0.0;
  *&v77.x = 0;
  *&v77.z = 0;
  v71 = 0;
  *&v76.x = 0;
  *&v76.z = 0;
  *&v75.x = 0;
  *&v75.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v73.x = 0;
  *&v73.z = 0;
  sub_854690(&v78.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v77.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v76.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v75.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v73.x, 0.0, 0.0, 0.0, 0.0);
  sub_8524C0(&v71, 0.0, 0.0, 0.0);
  MainProcessData = nbGetMainProcessData();
  v79 = 0;
  v7 = 0.0;
  v8 = MainProcessData;
  v9 = 0;
  v10 = 0;
  do
  {
    form = v8->form;
    v13 = form->m_Items[v9];
    pFormation = v13;
    if ((~v13->stat & 0x201) == 0)
    {
      v14 = v13->r * v13->scl;
      v15 = v14 + v14;
      Height = effBTLModelGetHeight(&pFormation);
      if (v7 < Height)
        v7 = Height;
      if (!v10)
        v79 = pFormation;
      v3 = v3 + v15;
      ++v10;
    }
    ++v9;
  }
  while (v9 != 32);
  if (v10)
  {
    EnemyInterval = nbGetEnemyInterval();
    v19 = (v10 - 1);
    v20 = v3 + (EnemyInterval * v19);
    if (v20 >= 1100.0)
      v21 = 0.7854;
    else
      v21 = (v20 / 1100.0) * 0.7854;
    else
    {
      if (v10 < 2)
        goto LABEL_33;
    }
    NBCAMERA_START_FOVY = NBCAMERA_START_FOVY * NBCAMERA_START_FOVY_WIDTH_RATIO;
LABEL_33:
    v26 = sdfAtan(NBCAMERA_START_FOVY * 0.5);
    if (v7 <= v20)
      v27 = v20;
    else
      v27 = v7;
    v29 = v27 * 0.5;
    else
    {
      if (NBCAMERA_START_RADIUS_E_MIN > v29)
        goto LABEL_42;
    }
    v31 = v29 / v26;
    v73.x = 0.0;
    v73.y = v7 * -0.5;
    v73.z = nbGetPartyDistance() * 0.5;
    *&v75.x = *&v73.x;
    v75.z = v73.z - v31;
    effBTLModelGetSphereCenter(&v79);
    SDF_VU0__STOREVECTOR(&p);
    Radius = effBTLModelGetRadius(&v79);
    NBCAMERA_START_RADIUS_S_MIN = Radius;
    if (NBCAMERA_START_RADIUS_S_MIN > NBCAMERA_START_RADIUS_S_MIN)
    {

      {
      }
    }
    *&v77.x = 0;
    v37 = fmaxf(v21, 0.43633);
    v77.z = -((NBCAMERA_START_RADIUS_S_MIN / v26) + ((v31 - (NBCAMERA_START_RADIUS_S_MIN / v26)) * 0.25));
    SetRotateMatrixY(v37);
    SDF_VU0__LOADVECTOR(v77);
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v76);
    y = v76.y;
    v41 = -NBCAMERA_START_EYE_S_HEIGHT;
    if (y < v41)
    {
      v76.y = v41;
    }
    p.x = v20 * -0.25;
    v75.y = -NBCAMERA_START_EYE_E_HEIGHT;
    SDF_VU0__LOADVECTOR_B(v73);
    v44 = 0.0;
    v45 = 0;
    v46 = 0;
    do
    {
      point = nbCameraState_Start_Camera->B4P_Target->point;
      z = point->m_Items[v45].z;
      v71 = *&point->m_Items[v45].x;
      v72 = z;
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__INTERPOLATE(v44);
      SDF_VU0__STOREVECTOR(&v78);
      v51 = v78.y;
      v52 = v78.z;
      v71 = *&v78.x;
      v72 = v78.z;
      v53 = nbCameraState_Start_Camera->B4P_Target->point;
      v44 = v44 + 0.33333;
      ++v46;
      v55 = (v53 + v45 * 12);
      ++v45;
      v55[8] = v78.x;
      v55[9] = v51;
      v55[10] = v52;
    }
    while (v46 != 4);
    SDF_VU0__LOADVECTOR_B(v75);
    v58 = 0.0;
    v59 = 0;
    v60 = 0;
    do
    {
      v62 = nbCameraState_Start_Camera->B4P_Eye->point;
      v64 = v62->m_Items[v59].z;
      v71 = *&v62->m_Items[v59].x;
      v72 = v64;
      SDF_VU0__LOADVECTOR(v76);
      SDF_VU0__INTERPOLATE(v58);
      SDF_VU0__STOREVECTOR(&v78);
      v65 = v78.y;
      v66 = v78.z;
      v71 = *&v78.x;
      v72 = v78.z;
      v67 = nbCameraState_Start_Camera->B4P_Eye->point;
      v69 = (v67 + v59 * 12);
      ++v59;
      v69[8] = v78.x;
      v69[9] = v65;
      v69[10] = v66;
      v58 = v58 + 0.33333;
      ++v60;
      v61 = (v70 >> 9) & 1;
    }
    while (v60 != 4);
    nbCameraStartAnimProcess = 0;
    nbCameraStartAnimFrame = 0;
    nbCameraState_Start_Animation(pNbCamera);
  }
}
