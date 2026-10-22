#include "types.h"

typedef struct nbCamera_AllTable_t nbCamera_AllTable_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static s32 nbCamera_NegoBougai_Frame;
static s32 nbCamera_NegoBougai_Wait;
static sdfVector4_t nbCamera_NegoBougai_Target;
static f32 nbCamera_NegoBougai_Distance;
static f32 nbCamera_NegoBougai_Rate;
static f32 nbCamera_NegoHojo_Distance;
static f32 nbCamera_NegoHojo_Rate;

void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetRotateMatrixY(f32 aAngle);
void ToMatrix(void);
void effBTLModelAllHide(void);
void effBTLModelAllShow(void);
f32 effBTLModelGetHeight(nbFormation_t **pFormation);
u32 effBTLModelGetID(nbFormation_t **pFormation);
s32 effBTLModelGetMarkPosition(nbFormation_t **pFormation, u32 mark);
void effBTLModelGetMarkPosition2(nbFormation_t **pFormation, u32 mark);
void effBTLModelGetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
void effBTLModelInvokeGroupHide(void);
void effBTLModelLook(nbFormation_t **pFormation, sdfVector4_t *pTargetPos);
void effBTLModelSetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos);
void effBTLModelTargetGroupHide(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
u32 effBTLSkillGetTargetParty(void);
nbCamera_AllTable_t *nbCameraGetModelAllTable(nbFormation_t *pFormation);
void nbCameraShot_GroundCollision(nbCamera_t **pNbCamera);
nbMainProcessData_t *nbGetMainProcessData(void);
f32 sdfAtan(f32 aX);
f32 sdfFabs(f32 c);
f32 sdfSin(f32 aRadius);

// 0x1679310
void nbCameraState_NegoBougai_Calc(void) {
  nbFormation_t_o *TargetFormation;
  struct nbCamera_t_o *nbCameraCurrent;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&v13.x = 0;
  *&v13.z = 0;
  *&v12.x = 0;
  *&v12.z = 0;
  TargetFormation = effBTLSkillGetTargetFormation(0);
  pFormation = TargetFormation;
  else if ((~TargetFormation->stat & 3) != 0)
  {
    return;
  }
  if (nbCamera_NegoBougai_Frame >= nbCamera_NegoBougai_Wait)
  {
    nbCamera_NegoBougai_Rate = nbCamera_NegoBougai_Rate * 0.835;
    sub_854930(&v13, 0);
    sub_854710(&v13, 0);
    sub_854930(&v13, 1u);
    sub_854930(&v13, 2u);
    SDF_VU0__LOADVECTOR(nbCameraCurrent->direction);
    SDF_VU0__LOADVECTOR_B(v13);
    SDF_VU0__MULVECTOR();
    SDF_VU0__LOADVECTOR_B(nbCameraCurrent->target);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v12);
    effBTLModelGetMarkPosition2(&pFormation, 1u);
    SDF_VU0__LOADVECTOR_B(nbCamera_NegoBougai_Target);
    SDF_VU0__INTERPOLATE(nbCamera_NegoBougai_Rate);
    SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
    SDF_VU0__LOADVECTOR_B(v12);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    nbCameraCurrent->distance = SDF_VU0__GETLENGTH();
    if (nbCamera_NegoBougai_Rate > 0.001)
    {
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
    }
    nbCameraCurrent->fovy = 0.69813;
    v10 = ((pFormation->oneshotr * pFormation->scl) * 1.25) / sdfAtan(0.34907);
    v11 = v10 + ((nbCamera_NegoBougai_Distance - v10) * nbCamera_NegoBougai_Rate);
    nbCameraCurrent->distance = v11;
    if (v11 < v10)
      nbCameraCurrent->distance = v10;
  }
  ++nbCamera_NegoBougai_Frame;
}

// 0x16790e0
void nbCameraState_NegoBougai_Init(void) {
  UnityEngine_Vector4_o *nbCameraCurrent;

  SDF_VU0__COPYVECTOR(&nbCamera_NegoBougai_Target, nbCameraCurrent[1]);
  nbCamera_NegoBougai_Distance = nbCameraCurrent[3].x;
  nbCamera_NegoBougai_Rate = 1.0;
  nbCamera_NegoBougai_Frame = 0;
  nbCamera_NegoBougai_Wait = 15;
}

// 0x16791c0
void nbCameraState_NegoBougai_Init2(void) {
  UnityEngine_Vector4_o *nbCameraCurrent;

  SDF_VU0__COPYVECTOR(&nbCamera_NegoBougai_Target, nbCameraCurrent[1]);
  nbCamera_NegoBougai_Distance = nbCameraCurrent[3].x;
  nbCamera_NegoBougai_Rate = 1.0;
  nbCamera_NegoBougai_Frame = 0;
  nbCamera_NegoBougai_Wait = 8;
}

// 0x16792a0
void nbCameraState_NegoBougai_SetWaitFrame(u32 frame) {
  nbCamera_NegoBougai_Wait = frame;
}

// 0x167ad60
void nbCameraState_NegoHojo_Calc(void) {
  struct nbCamera_t_o *nbCameraCurrent;

  nbCamera_NegoHojo_Rate = nbCamera_NegoHojo_Rate * 0.925;
  nbCameraCurrent->distance = nbCamera_NegoHojo_Distance
                                   * (1.0 - nbCamera_NegoHojo_Rate);
}

// 0x167a150
void nbCameraState_NegoHojo_Init(void) {
  u64 *v1;
  u64 *v2;
  u64 *v4;
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v7;
  struct nbCamera_t_o *nbCameraCurrent;
  nbFormation_t_o *v10;
  s64 *TargetFormation;
  s64 *v12;
  f32 **v14;
  s64 *v15;
  s64 *v17;
  f32 **v19;
  nbCamera_AllTable_t_o *ModelAllTable;
  f32 v28;
  f32 *v29;
  f32 *v30;
  f32 v32;
  f32 v40;
  f32 *v42;
  f32 v45;
  f32 *v47;
  f32 v49;
  s64 v50;
  f32 v52;
  f32 v55;
  f32 v58;
  f32 distance;
  f32 scl;
  f32 v61;
  f32 v62;
  f32 v66;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v68;
  struct nbFormation_t_array *v70;
  struct nbFormation_t_array *v72;
  f32 v77;
  UnityEngine_Vector4_o v79;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o pPos;
  nbFormation_t_o *v82;
  nbFormation_t_o *pFormation;

  v82 = 0;
  pFormation = 0;
  v1 = NewSpecific(nbFormation_t, 2u);
  *&pPos.x = 0;
  *&pPos.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  v2 = NewSpecific(f32, 2u);
  v4 = NewSpecific(UnityEngine_Vector4, 2u);
  *&v79.x = 0;
  *&v79.z = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    v7 = MainProcessData;
    v10 = effBTLSkillGetInvokeFormation(0);
    pFormation = v10;
    TargetFormation = effBTLSkillGetTargetFormation(0);
    v12 = TargetFormation;
    v1[4] = v12;
    v14 = (v1 + 4);
    v15 = effBTLSkillGetTargetFormation(1u);
    v17 = v15;
    v1[5] = v17;
    v19 = (v1 + 5);
    effBTLModelAllShow();
    ModelAllTable = nbCameraGetModelAllTable(v10);
    effBTLModelGetSphereCenter(v1 + 4);
    SDF_VU0__STOREVECTOR(v4 + 2);
    effBTLModelGetSphereCenter(v1 + 5);
    SDF_VU0__STOREVECTOR(v4 + 3);
    SDF_VU0__LOADVECTOR_B(*(v4 + 2), 0);
    SDF_VU0__INTERPOLATE(0.5);
    SDF_VU0__STOREVECTOR(&p);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B(*(v4 + 2), 0);
    SDF_VU0__SUBVECTOR();
    v28 = SDF_VU0__GETLENGTH();
    *(v2 + 8) = v28;
    v29 = (v2 + 4);
    v30 = *v14;
    if ((*v14)[24] <= ((*v14)[25] * 0.5))
    {
      v32 = (v30[25] * v30[27]) * 0.5;
    }
    else
    {
      v32 = v30[24] * v30[27];
    }
    *v29 = *v29 + v32;
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__LOADVECTOR_B(*(v4 + 3), 0);
    SDF_VU0__SUBVECTOR();
    v40 = SDF_VU0__GETLENGTH();
    *(v2 + 9) = v40;
    v42 = v2 + 9;
    v45 = *v42;
    v47 = *v19;
    if ((*v19)[24] <= ((*v19)[25] * 0.5))
    {
      v52 = v45 + ((v47[25] * v47[27]) * 0.5);
      v50 = v2[3];
      *(v2 + 9) = v52;
      if (!v50)
      {
LABEL_78:
      }
    }
    else
    {
      v49 = v45 + (v47[24] * v47[27]);
      v50 = v2[3];
      *(v2 + 9) = v49;
      if (!v50)
        goto LABEL_78;
    }
    if (*v29 > *v42)
      v42 = (v2 + 4);
    v55 = *v42;
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__STOREVECTOR(&v79);
    effBTLModelGetHeight(&pFormation);
    sub_854930(&v79, 1u);
    sub_854710(&v79, 1u);
    sub_854930(&v79, 1u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
    SDF_VU0__LOADVECTOR_B(v79);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    nbCameraCurrent->distance = SDF_VU0__GETLENGTH();
    v58 = sdfAtan(0.34907);
    distance = ModelAllTable->distance;
    scl = pFormation->scl;
    if (distance == 0.0)
    {
      v61 = pFormation->r * scl;
      if (v61 <= 150.0)
      {
        if (v61 <= 90.0)
          v61 = v61 + v61;
        else
          v61 = v61 * 1.5;
      }
      v62 = v61 / v58;
    }
    else
    {
      v62 = scl * distance;
    }
    nbCameraCurrent->distance = v62 + nbCameraCurrent->distance;
    v66 = v55 / sdfAtan(0.49567);
    if (v66 > nbCameraCurrent->distance)
    {
      form = v7->form;
      v82 = form->m_Items[0];
      v82 = form->m_Items[0];
      if ((~v82->stat & 0x103) == 0)
      {
        effBTLModelGetPosition(&v82, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&v82, &pPos);
      }
      v68 = v7->form;
      v82 = v68->m_Items[1];
      if ((~v82->stat & 0x103) == 0)
      {
        effBTLModelGetPosition(&v82, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&v82, &pPos);
      }
      v70 = v7->form;
      v82 = v70->m_Items[2];
      if ((~v82->stat & 0x103) == 0)
      {
        effBTLModelGetPosition(&v82, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&v82, &pPos);
      }
      v72 = v7->form;
      v82 = v72->m_Items[3];
      if ((~v82->stat & 0x103) == 0)
      {
        effBTLModelGetPosition(&v82, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&v82, &pPos);
      }
      sub_854710(&v79, 2u);
      sub_854930(&v79, 2u);
      nbCameraCurrent->distance = v66;
    }
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__LOADVECTOR_B(v79);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
    nbCameraCurrent->fovy = 0.69813;
    effBTLModelLook(&pFormation, &p);
    v77 = nbCameraCurrent->distance;
    nbCamera_NegoHojo_Distance = v77;
    nbCamera_NegoHojo_Rate = 0.5;
  }
}

// 0x16796f0
void nbCameraState_NegoTaizi_Calc(void) {
  struct nbCamera_t_o *nbCameraCurrent;
  nbFormation_t_o *v4;
  f32 angle;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v16;
  f32 v18;
  f32 Height;
  f32 v21;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 fovy;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;
  nbCamera_t_o *pNbCamera;

  pNbCamera = 0;
  TargetFormation = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v28.x = 0;
  *&v28.z = 0;
  pNbCamera = nbCameraCurrent;
  effBTLSkillGetTargetParty();
  TargetFormation = effBTLSkillGetTargetFormation(0);
  v4 = effBTLSkillGetInvokeFormation(0);
  pFormation = v4;
  if ((~TargetFormation->stat & 3) == 0 && (~v4->stat & 3) == 0)
  {
    nbCameraCurrent->fovy = 0.69813;
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__STOREVECTOR(&v28);
    sub_854710(&v28, 1u);
    sub_854930(&v28, 1u);
    effBTLModelGetSphereCenter(&TargetFormation);
    SDF_VU0__STOREVECTOR(&p);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__LOADVECTOR_B(v28);
    SDF_VU0__INTERPOLATE(0.5);
    SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
    if (nbCameraCurrent->frame)
    {
      angle = nbCameraCurrent->angle;
    }
    else
    {
      sub_854710(&v28, 0);
      v8 = v7;
      sub_854710(&p, 0);
      if (v8 <= v9)
      {
        nbCameraCurrent->angle = -0.5236;
        angle = -0.5236;
      }
      else
      {
        nbCameraCurrent->angle = 0.5236;
        angle = 0.5236;
      }
    }
    SDF_VU0__LOADVECTOR(v28);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__SUBVECTOR();
    v11 = SDF_VU0__GETLENGTH();
    v12 = TargetFormation->r * TargetFormation->scl;
    v13 = v11 + (pFormation->r * pFormation->scl);
    v14 = v13 + v12;
    SetRotateMatrixY(angle);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__LOADVECTOR_B(v28);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
    v16 = sdfFabs(angle);
    v18 = v14 * sdfSin(v16);
    Height = effBTLModelGetHeight(&pFormation);
    v21 = Height + ((pFormation->r * pFormation->scl) * -0.5);
    if (v21 > v18)
      v18 = v21;
    v23 = effBTLModelGetHeight(&TargetFormation);
    v24 = v23 + ((TargetFormation->r * pFormation->scl) * -0.5);
    if (v24 <= v18)
      v25 = v18;
    else
      v25 = v24;
    fovy = nbCameraCurrent->fovy;
    nbCameraCurrent->distance = (v25 * 0.5) / sdfAtan(fovy * 0.5);
    nbCameraShot_GroundCollision(&pNbCamera);
  }
}

// 0x1679680
void nbCameraState_NegoTaizi_Init(void) {
  effBTLModelTargetGroupHide();
  effBTLModelInvokeGroupHide();
}

// 0x1679d40
void nbCameraState_NegoTarget_Calc(void) {
  UnityEngine_Vector4_o *nbCameraCurrent;
  u32 ID;
  f32 v8;
  u64 *v9;
  s32 v10;
  u64 *v11;
  s32 v12;
  u64 *v13;
  s32 v14;
  s32 v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v17.x = 0;
  *&v17.z = 0;
  pFormation = effBTLSkillGetTargetFormation(0);
  if ((~pFormation->stat & 3) == 0)
  {
    ID = effBTLModelGetID(&pFormation);
    if (ID == 61 || ID == 91)
    {
      *&p.x = 0;
      *&p.z = 0;
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&p);
      effBTLModelGetMarkPosition(&pFormation, 1u);
      SDF_VU0__STOREVECTOR(&p);
      sub_854930(&p, 1u);
      SDF_VU0__LOADVECTOR(p);
    }
    else
    {
      if (ID != 62)
      {
LABEL_25:
        *&v17.x = 0;
        *&v17.z = 0;
        effBTLModelGetSphereCenter(&pFormation);
        SDF_VU0__STOREVECTOR(&v17);
        effBTLModelGetMarkPosition(&pFormation, 1u);
        SDF_VU0__LOADVECTOR_B(v17);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__STOREVECTOR(&v17);
        sub_854710(&v17, 0);
        v16.x = v8;
        v9 = sub_8D3950(f32, &v16);
        sub_854710(&v17, 1u);
        v15 = v10;
        v11 = sub_8D3950(f32, &v15);
        sub_854710(&v17, 2u);
        v14 = v12;
        v13 = sub_8D3950(f32, &v14);
        Format_5268688("[%f:%f:%f]\n", v9, v11, v13);
        return;
      }
      *&v16.x = 0;
      *&v16.z = 0;
      sub_854690(&v16.x, 16.092, -50.881, -37.809, 0.0);
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__LOADVECTOR_B(v16);
      SDF_VU0__ADDVECTOR();
    }
    SDF_VU0__STOREVECTOR(nbCameraCurrent + 1);
    goto LABEL_25;
  }
}

// 0x167a030
void nbCameraState_NegoTarget_Calc2(void) {
  UnityEngine_Vector4_o *nbCameraCurrent;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetTargetFormation(0);
  if ((~pFormation->stat & 3) == 0)
  {
    if (!effBTLModelGetMarkPosition(&pFormation, 1u))
    {
      effBTLModelGetSphereCenter(&pFormation);
    }
    SDF_VU0__STOREVECTOR(nbCameraCurrent + 1);
  }
}

// 0x1679b20
void nbCameraState_NegoTarget_Init(void) {
  struct nbCamera_t_o *nbCameraCurrent;
  nbFormation_t_o *TargetFormation;
  UnityEngine_Vector4_o *v6;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  effBTLModelAllHide();
  effBTLModelTargetGroupHide();
  TargetFormation = effBTLSkillGetTargetFormation(0);
  pFormation = TargetFormation;
  if ((~TargetFormation->stat & 3) == 0)
  {
    v6 = TargetFormation;
    sub_854930(&nbCameraCurrent->direction, 0);
    sub_854930(&nbCameraCurrent->direction, 1u);
    sub_854930(&nbCameraCurrent->direction, 2u);
    SDF_VU0__LOADVECTOR(v6[4]);
    ToMatrix();
    SDF_VU0__LOADVECTOR(nbCameraCurrent->direction);
    SDF_VU0__NORMALIZE();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
    nbCameraCurrent->fovy = 0.69813;
    nbCameraCurrent->distance = (v6[7].x * v6[6].w) / sdfAtan(0.34907);
    if (!effBTLModelGetMarkPosition(&pFormation, 1u))
    {
      effBTLModelGetSphereCenter(&pFormation);
    }
    SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
  }
}
