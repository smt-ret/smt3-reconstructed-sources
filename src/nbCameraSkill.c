#include "types.h"

typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct nbCameraSkillInfo_t nbCameraSkillInfo_t;
typedef struct nbCameraSkillPtr_t nbCameraSkillPtr_t;
typedef struct nbCamera_AllTable_t nbCamera_AllTable_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static f32 nbCameraSkill_Ptr_HA[8];
static f32 nbCameraSkill_Ptr_WA[8];
static f32 nbCameraSkill_Ptr_H[4];
static f32 nbCameraSkill_Ptr_W[7];
static s32 nbCamera_Analyze_Frame;
static s32 nbCamera_Analyze_Wait;
static sdfVector4_t nbCamera_Analyze_Target;
static f32 nbCamera_Analyze_Distance;
static f32 nbCamera_Analyze_Rate;
static f32 nbCamera_Analyze_Rate_Add;
static f32 nbCameraModelMotionCr;
static u32 nbCameraSkillAttack_Move_Frame;
static nbCameraSkillInfo_t *nbCameraSkillNBSInfo;
static sdfVector4_t nbCamera_Cut1Enemy_Target;
static s32 nbCamera_Cut1Enemy_Frame;
static f32 nbCamera_Cut1Enemy_Distance;
static f32 nbCamera_Cut1Enemy_Rate;
static sdfVector4_t nbCameraState_EnemyBad_StartTarget;
static sdfVector4_t nbCameraState_EnemyBad_EndTarget;
static f32 nbCameraState_EnemyBad_Rate;
static f32 nbCameraState_EnemyBad_Distance;

u32 DDS3EFFECT_RAND_I(void);
f32 EulerAngleAxisY(void);
u8 Get(s32 id);
void MultMatrixRevNoArg(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetDrawFlag(u32 flag, u32 cnt);
void SetRotateMatrixX(f32 aAngle);
void SetRotateMatrixXYZ(f32 **aAngles);
void SetRotateMatrixY(f32 aAngle);
void SetRotateMatrixY_B(f32 aAngle);
void bCameraShot_AttackInvokeTargetPartyNear_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void effBTLModelAllHide(void);
void effBTLModelAllPopPosition(void);
void effBTLModelAllPopRotate(void);
void effBTLModelAllShow(void);
s32 effBTLModelCheckBossID(nbFormation_t **pFormation);
u32 effBTLModelGetBadStatus(nbFormation_t **pFormation);
void effBTLModelGetDirection(nbFormation_t **pFormation, sdfVector4_t *pDirection);
u32 effBTLModelGetGroupNumber(u32 group);
f32 effBTLModelGetHeight(nbFormation_t **pFormation);
u32 effBTLModelGetID(nbFormation_t **pFormation);
void effBTLModelGetMarkPosition2(nbFormation_t **pFormation, u32 mark);
s32 effBTLModelGetMarkPositionEvalTm(nbFormation_t **pFormation, u32 mark);
void effBTLModelGetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos);
f32 effBTLModelGetRadius(nbFormation_t **pFormation);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
void effBTLModelGroupGetDirection(u32 group, sdfVector4_t *pDirection);
f32 effBTLModelGroupGetSphere(u32 group);
void effBTLModelGroupPopPosition(u32 group);
void effBTLModelInvokeGroupHide(void);
void effBTLModelInvokePartyHide(void);
void effBTLModelInvokePartyShow(void);
void effBTLModelInvokeShow(void);
void effBTLModelLook(nbFormation_t **pFormation, sdfVector4_t *pTargetPos);
void effBTLModelLook2(nbFormation_t **pFormation, sdfVector4_t *pTargetPos, f32 angle);
void effBTLModelSetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos);
void effBTLModelTargetGroupHide(void);
void effBTLModelTargetPartyShow(void);
void effBTLModelTargetShow(void);
u32 effBTLSkillGetID(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
u32 effBTLSkillGetInvokeParty(void);
u32 effBTLSkillGetState(void);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
u32 effBTLSkillGetTargetNumber(void);
u32 effBTLSkillGetTargetParty(void);
void effBTLSkillSetFormationInfo(u32 InvokeID, u32 TargetBit);
void nbCameraAnim_RotateSet(nbCamera_t **pNbCamera, s32 frame, f32 rotate, s32 start_f);
s32 nbCameraBoss_CheckRotate(nbFormation_t **pFormation);
s32 nbCameraBoss_Cut1_Init(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Cut1_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Cut2_Init(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Cut2_Ptr_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
s32 nbCameraBoss_Cut2_Ptr_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
s32 nbCameraBoss_Cut2_Run(nbCamera_t **pNbCamera);
s32 nbCameraDANTE_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
s32 nbCameraDANTE_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
nbCamera_AllTable_t *nbCameraGetModelAllTable(nbFormation_t *pFormation);
s32 nbCameraHero_Cut1_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
s32 nbCameraHero_Cut1_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
s32 nbCameraHero_Cut2_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
s32 nbCameraHero_Cut2_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraSetState(u16 state);
void nbCameraShot_AllParty_Set(nbCamera_t **pNbCamera);
void nbCameraShot_All_Set(nbCamera_t **pNbCamera);
void nbCameraShot_All_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_AttackTuibiReverse_Set(nbCamera_t **pNbCamera);
void nbCameraShot_AttackTuibi_Set(nbCamera_t **pNbCamera);
void nbCameraShot_GroundCollision(nbCamera_t **pNbCamera);
void nbCameraShot_InvokeParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetNearReverse_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetNear_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetPartyTop2_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetPartyTop_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetReverse_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTarget_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_Invoke_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_One_Calc(nbCamera_t **pNbCamera, nbFormation_t **pFormation);
void nbCameraShot_One_Init(nbCamera_t **pNbCamera, nbFormation_t **pFormation);
void nbCameraShot_Summon_Set(nbCamera_t **pNbCamera);
void nbCameraShot_TargetParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_Target_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraState_Analyze_Calc(nbCamera_t **pNbCamera);
void nbCameraState_Analyze_Set(nbCamera_t **pNbCamera);
void nbCameraState_Cut1Enemy_Calc(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraState_Cut1Enemy_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraState_InvokeTarget_SearchSet(void);
void nbCameraState_SkillAttack_Calc(void);
void nbCameraState_SkillAttack_Init(void);
void nbCamera_SkillInfo_Set(nbCameraSkillInfo_t **pInfo, nbCameraSkillPtr_t *pPtr);
f32 nbGetEnemyInterval(void);
nbMainProcessData_t *nbGetMainProcessData(void);
f32 nbGetPartyDistance(void);
f32 sdfAtan(f32 aX);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfFabs(f32 c);
f32 sdfSin(f32 aRadius);
f32 sdfSqrt(f32 aValue);

// 0x1686ea0
void bCameraShot_AttackInvokeTargetPartyNear_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u32 v5;
  f32 Sphere;
  f32 v8;
  nbMainProcessData_t_o *MainProcessData;
  u64 v11;
  s32 v12;
  f32 Height;
  struct nbFormation_t_array *form;
  f32 v18;
  f32 v20;
  f32 v22;
  f32 v23;
  f32 v24;
  nbCamera_t_o *v26;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v29;
  nbFormation_t_o *v30;
  nbFormation_t_o *pFormation;
  nbFormation_t_o *v32;
  nbFormation_t_o *TargetFormation;

  v32 = 0;
  TargetFormation = 0;
  v30 = 0;
  pFormation = 0;
  *&v29.x = 0;
  *&v29.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v27.x = 0;
  *&v27.z = 0;
  effBTLModelAllShow();
  effBTLModelAllPopRotate();
  v32 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  v5 = effBTLSkillGetInvokeParty();
  Sphere = effBTLModelGroupGetSphere(v5);
  SDF_VU0__STOREVECTOR(&p);
  v8 = 0.0;
  MainProcessData = nbGetMainProcessData();
  v11 = 0;
  v12 = 1;
  v30 = 0;
  do
  {
    while (1)
    {
      form = MainProcessData->form;
      pFormation = form->m_Items[v11];
      if ((pFormation->stat & 3) != 3 || (pFormation->stat & v5) == 0)
        break;
      else
      {
        Height = effBTLModelGetHeight(&pFormation);
        if (v12)
          goto LABEL_27;
      }
      if (Height < v8)
      {
LABEL_27:
        v8 = Height;
        v12 = 0;
        v30 = pFormation;
        break;
      }
      v12 = 0;
      if (++v11 == 32)
        goto LABEL_29;
    }
    ++v11;
  }
  while (v11 != 32);
LABEL_29:
  if (v30)
  {
    sub_854930(&p, 1u);
    effBTLModelGetSphereCenter(&v30);
    SDF_VU0__STOREVECTOR(&v27);
    sub_854710(&p, 1u);
    sub_854710(&v27, 1u);
    sub_854930(&p, 1u);
  }
  effBTLModelGetSphereCenter(&TargetFormation);
  SDF_VU0__STOREVECTOR(&v29);
  effBTLModelGetHeight(&TargetFormation);
  sub_854930(&v29, 1u);
  v18 = TargetFormation->r * TargetFormation->scl;
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v29);
  SDF_VU0__SUBVECTOR();
  v20 = SDF_VU0__GETLENGTH();
  v22 = sdfAtan(0.34907);
  if (v18 <= 150.0)
  {
    if (v18 <= 90.0)
      v18 = v18 + v18;
    else
      v18 = v18 * 1.5;
  }
  v23 = v18 / v22;
  v24 = v20 + (v18 / v22);
  if ((Sphere / sdfAtan(0.47124)) > v24)
  {
    effBTLModelGetSphereCenter(&v32);
    SDF_VU0__STOREVECTOR(&v27);
    sub_854710(&p, 0);
    sub_854710(&v27, 0);
    sub_854710(&p, 0);
    sub_854930(&p, 0);
  }
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v29);
  SDF_VU0__SUBVECTOR();
  v26 = *pNbCamera;
  v26->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = (v23 * 1.05) + (*pNbCamera)->distance;
  (*pNbCamera)->fovy = 0.69813;
}

// 0x1680090
void mdlGetPosition(dds3ModelHandle_t *aHandle) {
  ;
}

// 0x168a870
void nbCameraEnemyPartySet(nbCamera_t **pNbCamera, f32 angleH, f32 angleW) {
  u64 *v6;
  nbMainProcessData_t_o *MainProcessData;
  u64 v10;
  u32 v11;
  u32 v12;
  struct nbFormation_t_array *form;
  s32 v15;
  bool v16;
  s32 v17;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v6 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v6);
  pNBSInfo = v6;
  MainProcessData = nbGetMainProcessData();
  v10 = 0;
  v11 = 0;
  v12 = 0;
  do
  {
    form = MainProcessData->form;
    v15 = form->m_Items[v10]->stat & 0x203;
    v16 = v15 == 515;
    if (v15 == 515)
      v17 = 1 << v10;
    else
      v17 = 0;
    if (v16)
      v11 = v10;
    ++v10;
    v12 |= v17;
  }
  while (v10 != 32);
  effBTLSkillSetFormationInfo(v11, v12);
  v6[4] = 0x442F000000000000LL;
  *(v6 + 6) = angleH;
  *(v6 + 7) = angleW;
  nbCameraShot_TargetParty_Set2(&nbCameraCurrent, &pNBSInfo);
}

// 0x167be30
void nbCameraShot_All_Set(nbCamera_t **pNbCamera) {
  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  effBTLModelAllShow();
  sub_854930(&(*pNbCamera)->fields, 0);
  sub_854930(&(*pNbCamera)->fields, 1u);
  sub_854930(&(*pNbCamera)->fields, 2u);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
}

// 0x16862b0
void nbCameraShot_All_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  f32 v5;
  f32 v6;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  u32 stat;
  f32 Height;
  f32 v14;
  nbCamera_t_Fields *p_fields;
  f32 v18;
  f32 v19;
  UnityEngine_Vector4_o v21;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&v21.x = 0;
  *&v21.z = 0;
  effBTLModelAllShow();
  v5 = 0.0;
  v6 = 0.0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    while (1)
    {
      form = MainProcessData->form;
      pFormation = form->m_Items[i];
      stat = pFormation->stat;
      if ((~stat & 0x201) != 0)
        break;
      Height = effBTLModelGetHeight(&pFormation);
      if (v5 < Height)
        v5 = Height;
      if (++i == 32)
        goto LABEL_27;
    }
    if ((~stat & 0x101) == 0)
    {
      v14 = effBTLModelGetHeight(&pFormation);
      if (v6 < v14)
        v6 = v14;
    }
  }
LABEL_27:
  nbGetEnemyInterval();
  sub_854930(&(*pNbCamera)->fields, 0);
  sub_854930(&(*pNbCamera)->fields, 1u);
  p_fields = &(*pNbCamera)->fields;
  nbGetPartyDistance();
  sub_854930(p_fields, 2u);
  v18 = sdfAtan(0.5236);
  (*pNbCamera)->fovy = 0.69813;
  sub_854930(&v21, 0);
  sub_854930(&v21, 1u);
  nbGetPartyDistance();
  sub_854930(&v21, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v21);
  SDF_VU0__SUBVECTOR();
  v19 = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = v19 + (fmaxf(effBTLModelGroupGetSphere(0x100u), 250.0) / v18);
}

// 0x1686600
void nbCameraShot_All_Set3(nbCamera_t **pNbCamera, sdfVector4_t pTarget) {
  f32 v5;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  u32 stat;
  f32 Height;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v14;
  nbCamera_t_Fields *v15;
  f32 v17;
  f32 v19;
  UnityEngine_Vector4_o v21;
  UnityEngine_Vector4_o v22;
  nbFormation_t_o *pFormation;

  v22 = pTarget;
  pFormation = 0;
  *&v21.x = 0;
  *&v21.z = 0;
  effBTLModelAllShow();
  v5 = 0.0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    while (1)
    {
      form = MainProcessData->form;
      pFormation = form->m_Items[i];
      stat = pFormation->stat;
      if ((~stat & 0x201) != 0)
        break;
      effBTLModelGetHeight(&pFormation);
      if (++i == 32)
        goto LABEL_25;
    }
    if ((~stat & 0x101) == 0)
    {
      Height = effBTLModelGetHeight(&pFormation);
      if (v5 < Height)
        v5 = Height;
    }
  }
LABEL_25:
  nbGetEnemyInterval();
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&v22, 0);
  sub_854930(p_fields, 0);
  v14 = &(*pNbCamera)->fields;
  sub_854710(&v22, 1u);
  sub_854930(v14, 1u);
  v15 = &(*pNbCamera)->fields;
  sub_854710(&v22, 2u);
  sub_854930(v15, 2u);
  v17 = sdfAtan(0.5236);
  (*pNbCamera)->fovy = 0.69813;
  sub_854930(&v21, 0);
  sub_854930(&v21, 1u);
  nbGetPartyDistance();
  sub_854930(&v21, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v21);
  SDF_VU0__SUBVECTOR();
  v19 = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = v19 + (fmaxf(effBTLModelGroupGetSphere(0x100u), 250.0) / v17);
}

// 0x16877f0
void nbCameraShot_AttackTuibiReverse_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *v5;
  nbFormation_t_o *v7;
  f32 v8;
  f32 v9;
  f32 v10;
  nbCamera_t_o *v11;
  f32 angle;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v19;
  f32 v20;
  f32 Height;
  f32 v23;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 fovy;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v31;
  nbFormation_t_o *pFormation;

  v31 = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v29.x = 0;
  *&v29.z = 0;
  effBTLModelAllShow();
  effBTLModelTargetGroupHide();
  effBTLSkillGetInvokeParty();
  TargetFormation = effBTLSkillGetTargetFormation(0);
  pFormation = TargetFormation;
  v5 = effBTLSkillGetInvokeFormation(0);
  v31 = v5;
  if (!(*pNbCamera)->frame)
  {
    v7 = v5;
    sub_854710(&TargetFormation->pos, 0);
    v9 = v8;
    sub_854710(&v7->pos, 0);
    LODWORD((*pNbCamera)->angle) = dword_32C3198[v9 > v10];
  }
  v11 = *pNbCamera;
  v11->fovy = 0.69813;
  angle = v11->angle;
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&v29);
  sub_854710(&v29, 1u);
  sub_854930(&v29, 1u);
  effBTLModelGetSphereCenter(&v31);
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  sub_854930(&p, 1u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v29);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR(v29);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v14 = SDF_VU0__GETLENGTH();
  v15 = v31->r * v31->scl;
  v16 = v14 + (pFormation->r * pFormation->scl);
  v17 = v16 + v15;
  SetRotateMatrixY(angle);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v29);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  v19 = sdfFabs(angle);
  v20 = (v17 * sdfSin(v19)) * 1.15;
  Height = effBTLModelGetHeight(&pFormation);
  v23 = Height + ((pFormation->r * pFormation->scl) * -0.5);
  if (v23 > v20)
    v20 = v23;
  v25 = effBTLModelGetHeight(&v31);
  v26 = v25 + ((v31->r * pFormation->scl) * -0.5);
  if (v26 <= v20)
    v27 = v20;
  else
    v27 = v26;
  fovy = (*pNbCamera)->fovy;
  (*pNbCamera)->distance = (v27 * 0.5) / sdfAtan(fovy * 0.5);
}

// 0x16873a0
void nbCameraShot_AttackTuibi_Set(nbCamera_t **pNbCamera) {
  u32 v3;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 angle;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v18;
  f32 v20;
  f32 Height;
  f32 v23;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 fovy;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  TargetFormation = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v29.x = 0;
  *&v29.z = 0;
  v3 = effBTLSkillGetInvokeParty();
  if (v3 == effBTLSkillGetTargetParty())
  {
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    effBTLModelTargetShow();
    {
LABEL_11:
    }
  }
  else
  {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
      goto LABEL_11;
  }
  TargetFormation = effBTLSkillGetTargetFormation(0);
  pFormation = effBTLSkillGetInvokeFormation(0);
  (*pNbCamera)->fovy = 0.69813;
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&v29);
  sub_854710(&v29, 1u);
  sub_854930(&v29, 1u);
  effBTLModelGetSphereCenter(&TargetFormation);
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v29);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  if (!(*pNbCamera)->frame)
  {
    sub_854710(&v29, 0);
    v9 = v8;
    sub_854710(&p, 0);
    LODWORD((*pNbCamera)->angle) = dword_32C3198[v9 > v10];
  }
  angle = (*pNbCamera)->angle;
  SDF_VU0__LOADVECTOR(v29);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v13 = SDF_VU0__GETLENGTH();
  v14 = TargetFormation->r * TargetFormation->scl;
  v15 = v13 + (pFormation->r * pFormation->scl);
  v16 = v15 + v14;
  SetRotateMatrixY(angle);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v29);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  v18 = sdfFabs(angle);
  v20 = (v16 * sdfSin(v18)) * 1.15;
  Height = effBTLModelGetHeight(&pFormation);
  v23 = Height + ((pFormation->r * pFormation->scl) * -0.5);
  if (v23 > v20)
    v20 = v23;
  v25 = effBTLModelGetHeight(&TargetFormation);
  v26 = v25 + ((TargetFormation->r * pFormation->scl) * -0.5);
  if (v26 <= v20)
    v27 = v20;
  else
    v27 = v26;
  fovy = (*pNbCamera)->fovy;
  (*pNbCamera)->distance = (v27 * 0.5) / sdfAtan(fovy * 0.5);
}

// 0x166c280
void nbCameraShot_GroundCollision(nbCamera_t **pNbCamera) {
  f32 v3;
  f32 v5;
  f32 v6;
  f32 distance;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  *&v9.x = 0;
  *&v9.z = 0;
  *&v8.x = 0;
  *&v8.z = 0;
  sub_854930(&v8, 0);
  sub_854710(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR_B(v8);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B((*pNbCamera)->target, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  if (v3 > -20.0)
  {
    SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
    SDF_VU0__SETVECTOR_Y(0.0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__SETVECTOR_Y(0.0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&v9);
    sub_854710(&(*pNbCamera)->fields, 1u);
    v6 = v5 + 20.0;
    distance = (*pNbCamera)->distance;
    sdfSqrt((v6 * v6) + (distance * distance), 0);
    sub_854710(&v9, 0);
    sub_854930(&p, 0);
    sub_854930(&p, 1u);
    sub_854710(&v9, 2u);
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  }
}

// 0x1685d20
void nbCameraShot_InvokeParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u64 *v6;
  u32 v8;
  f32 Sphere;
  f32 fovy;
  f32 v13;
  nbCameraSkillInfo_t_o *v14;
  f32 v15;
  f32 HeightMin;
  f32 WidthMin;
  f32 v18;
  f32 v19;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 angleW;
  nbCamera_t_o *v27;
  s32 v29;
  f32 v30;
  s32 v31;
  f32 v33;
  u32 v34;
  struct UnityEngine_Vector4_o *p_direction;
  struct UnityEngine_Vector4_o *v38;
  struct UnityEngine_Vector4_o *v39;
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  *&v40.x = 0;
  *&v40.z = 0;
  v6 = NewSpecific(f32, 3u);
  effBTLModelAllHide();
  effBTLModelInvokePartyShow();
  v8 = effBTLSkillGetInvokeParty();
  (*pNbCamera)->fovy = 0.69813;
  Sphere = effBTLModelGroupGetSphere(v8);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  fovy = (*pNbCamera)->fovy;
  v13 = sdfAtan((fovy * 1.35) * 0.5, 0);
  v14 = *pNBSInfo;
  v15 = v13;
  HeightMin = (*pNBSInfo)->HeightMin;
  if (HeightMin != 0.0)
  {
    sub_854930(&(*pNbCamera)->fields, 1u);
    v14 = *pNBSInfo;
    HeightMin = (*pNBSInfo)->HeightMin;
  }
  WidthMin = v14->WidthMin;
  if (HeightMin <= (Sphere + Sphere))
    v18 = Sphere;
  else
    v18 = HeightMin * 0.5;
  if (WidthMin > (v18 + v18))
    v18 = WidthMin * 0.5;
  v19 = v18 / v15;
  if (v14->angleH > 0.0)
  {
    sub_854710(&(*pNbCamera)->fields, 1u);
    v22 = v21;
    v23 = v19 * 1.15;
    sdfSqrt((v23 * v23) + (v22 * v22), 0);
    effBTLModelGroupGetDirection(v8, &v40);
    sub_854710(&v40, 0);
    sub_854930(&p, 0);
    sub_854710(&v40, 1u);
    sub_854930(&p, 1u);
    sub_854710(&v40, 2u);
    sub_854930(&p, 2u);
    angleW = (*pNBSInfo)->angleW;
    SetRotateMatrixY(angleW);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&p);
    sub_854710(&p, 0);
    sub_854710(&(*pNbCamera)->fields, 0);
    sub_854930(&p, 0);
    sub_854710(&p, 2u);
    sub_854710(&(*pNbCamera)->fields, 2u);
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    v27 = *pNbCamera;
    v27->distance = SDF_VU0__GETLENGTH() * 0.85;
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
    return;
  }
  effBTLModelGroupGetDirection(v8, &v40);
  sub_854710(&v40, 2u);
  v29 = *(v6 + 6);
  if (v30 <= 0.0)
  {
    v31 = 1030248086;
    if (!v29)
      goto LABEL_37;
  }
  else
  {
    v31 = -1117235562;
    if (!v29)
    {
LABEL_37:
    }
  }
  *(v6 + 8) = v31;
  v33 = (*pNBSInfo)->angleW;
  v34 = *(v6 + 6);
  *(v6 + 9) = v33;
  *(v6 + 10) = 0;
  SetRotateMatrixXYZ(v6);
  SDF_VU0__LOADVECTOR(v40);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&v40);
  p_direction = &(*pNbCamera)->direction;
  sub_854710(&v40, 0);
  sub_854930(p_direction, 0);
  v38 = &(*pNbCamera)->direction;
  sub_854710(&v40, 1u);
  sub_854930(v38, 1u);
  v39 = &(*pNbCamera)->direction;
  sub_854710(&v40, 2u);
  sub_854930(v39, 2u);
  (*pNbCamera)->distance = v19;
}

// 0x1684b70
void nbCameraShot_InvokeTargetNearReverse_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  f32 v5;
  f32 r;
  f32 scl;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 Height;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v19;
  f32 v20;
  f32 v22;
  f32 v23;
  UnityEngine_Vector4_o pTargetPos;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v31;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.z = 0;
  v31 = 0;
  *&v28.x = 0;
  *&v29.z = 0;
  *&p.x = 0;
  *&v28.z = 0;
  *&v29.x = 0;
  *&pTargetPos.x = 0;
  *&pTargetPos.z = 0;
  effBTLModelAllShow();
  effBTLModelTargetGroupHide();
  pFormation = effBTLSkillGetTargetFormation(0);
  v31 = effBTLSkillGetInvokeFormation(0);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelGetSphereCenter(&v31);
  SDF_VU0__STOREVECTOR(&v29);
  SDF_VU0__LOADVECTOR(v29);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v5 = SDF_VU0__GETLENGTH();
  r = pFormation->r;
  scl = pFormation->scl;
  v8 = v5;
  v9 = v31->scl;
  v10 = v31->r;
  SDF_VU0__LOADVECTOR(v29);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.65);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  Height = effBTLModelGetHeight(&v31);
  if ((Height - effBTLModelGetHeight(&pFormation)) < 250.0)
  {
    sub_854710(&p, 1u);
    sub_854930(&v29, 1u);
  }
  SDF_VU0__LOADVECTOR(v29);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v28);
  sub_854710(&v28, 2u);
  if (v13 <= 0.0)
  {
    v14 = 0.5236;
  }
  else
  {
    v14 = -0.5236;
  }
  SetRotateMatrixX(v14);
  v15 = (r * scl) + (v10 * v9);
  sub_854710(&v31->fields, 0);
  v17 = v16;
  sub_854710(&pFormation->fields, 0);
  if (v17 <= v19)
  {
    v20 = 0.69813;
  }
  else
  {
    v20 = -0.69813;
  }
  SetRotateMatrixY_B(v20);
  v22 = v8 + v15;
  v23 = v22 * 0.5;
  MultMatrixRevNoArg();
  SDF_VU0__LOADVECTOR(v28);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = v23 / sdfAtan(0.41888);
  (*pNbCamera)->fovy = 0.69813;
  if (nbCameraBoss_CheckRotate(&pFormation))
  {
    effBTLModelGetSphereCenter(&v31);
    SDF_VU0__STOREVECTOR(&pTargetPos);
    effBTLModelLook(&pFormation, &pTargetPos);
  }
}

// 0x1684770
void nbCameraShot_InvokeTargetNear_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v15;
  f32 v16;
  f32 v18;
  f32 v19;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.z = 0;
  TargetFormation = 0;
  *&v24.x = 0;
  *&v25.z = 0;
  *&p.x = 0;
  *&v24.z = 0;
  *&v25.x = 0;
  *&v23.x = 0;
  *&v23.z = 0;
  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  pFormation = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelGetSphereCenter(&TargetFormation);
  SDF_VU0__STOREVECTOR(&v25);
  SDF_VU0__LOADVECTOR(v25);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v5 = SDF_VU0__GETLENGTH();
  v6 = pFormation->r * pFormation->scl;
  v7 = TargetFormation->r * TargetFormation->scl;
  SDF_VU0__LOADVECTOR(v25);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.4);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  sub_854710(&p, 1u);
  sub_854930(&v25, 1u);
  SDF_VU0__LOADVECTOR(v25);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v24);
  sub_854710(&v24, 2u);
  if (v9 <= 0.0)
  {
    v10 = 0.5236;
  }
  else
  {
    v10 = -0.5236;
  }
  SetRotateMatrixX(v10);
  v11 = v6 + v7;
  sub_854710(&TargetFormation->fields, 0);
  v13 = v12;
  sub_854710(&pFormation->fields, 0);
  if (v13 <= v15)
  {
    v16 = 0.69813;
  }
  else
  {
    v16 = -0.69813;
  }
  SetRotateMatrixY_B(v16);
  v18 = v5 + v11;
  v19 = v18 * 0.5;
  MultMatrixRevNoArg();
  SDF_VU0__LOADVECTOR(v24);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = v19 / sdfAtan(0.41888);
  (*pNbCamera)->fovy = 0.69813;
  if (nbCameraBoss_CheckRotate(&TargetFormation))
  {
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__STOREVECTOR(&v23);
    effBTLModelLook(&TargetFormation, &v23);
  }
}

// 0x1685650
void nbCameraShot_InvokeTargetPartyTop2_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u32 TargetParty;
  f32 Sphere;
  nbCameraSkillInfo_t_o **v7;
  f32 v9;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  f32 Height;
  u32 TargetNumber;
  u32 v21;
  u32 v22;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  nbFormation_t_o *v27;

  pFormation = 0;
  v27 = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  v27 = effBTLSkillGetInvokeFormation(0);
  TargetParty = effBTLSkillGetTargetParty();
  Sphere = effBTLModelGroupGetSphere(TargetParty);
  SDF_VU0__STOREVECTOR(&p);
  if ((Sphere + Sphere) > 1400.0)
    goto LABEL_27;
  v9 = 0.0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[i];
    if ((pFormation->stat & 3) == 3 && (pFormation->stat & TargetParty) != 0)
    {
      Height = effBTLModelGetHeight(&pFormation);
      if (Height > v9)
        v9 = Height;
    }
  }
  if (v9 > 500.0)
    goto LABEL_27;
  if ((v27->stat & 0x100) == 0)
    goto LABEL_77;
  if (DDS3EFFECT_RAND_I() % 5 == 1)
  {
LABEL_27:
    nbCameraShot_InvokeTargetParty_Set2(pNbCamera, v7);
  }
  else
  {
LABEL_77:
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    sub_854710(&v27->fields, 0);
    sub_854930(&(*pNbCamera)->fields, 0);
    sub_854930(&(*pNbCamera)->fields, 1u);
    sub_854930(&(*pNbCamera)->fields, 2u);
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
    if (nbCameraBoss_CheckRotate(&v27))
    {
      effBTLModelLook(&v27, &p);
    }
    effBTLModelGetPosition(&v27, &v24);
    TargetNumber = effBTLSkillGetTargetNumber();
    if (TargetNumber)
    {
      v21 = TargetNumber;
      v22 = 0;
      while (1)
      {
        pFormation = effBTLSkillGetTargetFormation(v22);
        else
        {
          if (nbCameraBoss_CheckRotate(&pFormation))
            goto LABEL_62;
LABEL_74:
          if (v21 == ++v22)
            return;
        }
      }
    }
  }
}

// 0x1684fa0
void nbCameraShot_InvokeTargetPartyTop_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u32 TargetParty;
  f32 Sphere;
  nbCameraSkillInfo_t_o **v7;
  f32 v9;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  f32 Height;
  u32 TargetNumber;
  u32 v21;
  u32 j;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  TargetFormation = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  TargetParty = effBTLSkillGetTargetParty();
  Sphere = effBTLModelGroupGetSphere(TargetParty);
  SDF_VU0__STOREVECTOR(&p);
  if ((Sphere + Sphere) > 1400.0)
    goto LABEL_35;
  if (effBTLModelGetHeight(&pFormation) <= 150.0)
    goto LABEL_35;
  v9 = 0.0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    TargetFormation = form->m_Items[i];
    if ((TargetFormation->stat & 3) == 3 && (TargetFormation->stat & TargetParty) != 0)
    {
      Height = effBTLModelGetHeight(&TargetFormation);
      if (Height > v9)
        v9 = Height;
    }
  }
  if (v9 > 500.0)
    goto LABEL_35;
  if (DDS3EFFECT_RAND_I() % 5 == 1)
  {
LABEL_35:
    nbCameraShot_InvokeTargetParty_Set2(pNbCamera, v7);
  }
  else
  {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    sub_854710(&pFormation->fields, 0);
    sub_854930(&(*pNbCamera)->fields, 0);
    sub_854930(&(*pNbCamera)->fields, 1u);
    sub_854930(&(*pNbCamera)->fields, 2u);
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
    if (nbCameraBoss_CheckRotate(&pFormation))
    {
      effBTLModelLook(&pFormation, &p);
    }
    effBTLModelGetPosition(&pFormation, &v24);
    TargetNumber = effBTLSkillGetTargetNumber();
    if (TargetNumber)
    {
      v21 = TargetNumber;
      for (j = 0; j != v21; ++j)
      {
        TargetFormation = effBTLSkillGetTargetFormation(j);
        if (nbCameraBoss_CheckRotate(&TargetFormation)
          && (~TargetFormation->stat & 3) == 0
          && TargetFormation->formindex != pFormation->formindex)
        {
          effBTLModelLook2(&TargetFormation, &v24, 0.5236);
        }
      }
    }
  }
}

// 0x1681fa0
void nbCameraShot_InvokeTargetParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v7;
  nbFormation_t_o *v8;
  u32 v9;
  u32 TargetParty;
  nbCamera_AllTable_t_o *ModelAllTable;
  u32 TargetNumber;
  f32 v15;
  f32 v16;
  u32 v17;
  u32 i;
  f32 Height;
  f32 Sphere;
  nbCamera_t_o *v23;
  f32 v26;
  f32 scl;
  f32 v28;
  f32 distance;
  f32 v30;
  f32 *p_distance;
  f32 v32;
  f32 v34;
  f32 v36;
  f32 v37;
  f32 v40;
  u64 j;
  struct nbFormation_t_array *form;
  nbCamera_t_o *v46;
  f32 v47;
  f32 r;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 angle;
  u32 v57;
  u32 v59;
  u32 v60;
  UnityEngine_Vector4_o pPos;
  UnityEngine_Vector4_o v63;
  UnityEngine_Vector4_o v64;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  nbFormation_t_o *v67;
  nbFormation_t_o *v68;

  v67 = 0;
  v68 = 0;
  *&p.z = 0;
  pFormation = 0;
  *&v63.x = 0;
  *&v64.z = 0;
  *&p.x = 0;
  *&v63.z = 0;
  *&v64.x = 0;
  *&pPos.x = 0;
  *&pPos.z = 0;
  effBTLModelTargetPartyShow();
  effBTLModelInvokeGroupHide();
  MainProcessData = nbGetMainProcessData();
  if (!MainProcessData)
    return;
  v7 = MainProcessData;
  v8 = effBTLSkillGetInvokeFormation(0);
  v68 = v8;
  v9 = effBTLSkillGetInvokeParty();
  TargetParty = effBTLSkillGetTargetParty();
  ModelAllTable = nbCameraGetModelAllTable(v8);
  v67 = 0;
  TargetNumber = effBTLSkillGetTargetNumber();
  if (!TargetNumber)
    return;
  v15 = 1000000.0;
  v16 = 0.0;
  v17 = TargetNumber;
  for (i = 0; i != v17; ++i)
  {
    pFormation = effBTLSkillGetTargetFormation(i);
    if ((~pFormation->stat & 3) == 0)
    {
      Height = effBTLModelGetHeight(&pFormation);
      if (Height < v15)
      {
        v15 = Height;
        v67 = pFormation;
      }
      if (Height > v16)
        v16 = Height;
    }
  }
  if (!v67)
    return;
  Sphere = effBTLModelGroupGetSphere(TargetParty);
  SDF_VU0__STOREVECTOR(&p);
  if (v15 > 150.0)
  {
    sub_854930(&p, 1u);
    effBTLModelGetSphereCenter(&v67);
    SDF_VU0__STOREVECTOR(&v64);
    sub_854710(&p, 1u);
    sub_854710(&v64, 1u);
  }
  sub_854930(&p, 1u);
  effBTLModelGetSphereCenter(&v68);
  SDF_VU0__STOREVECTOR(&v63);
  effBTLModelGetHeight(&v68);
  sub_854930(&v63, 1u);
  sub_854710(&v63, 1u);
  sub_854930(&v63, 1u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v63);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  v23 = *pNbCamera;
  v23->distance = SDF_VU0__GETLENGTH();
  v26 = sdfAtan(0.34907);
  scl = v68->scl;
  v28 = v68->r * scl;
  distance = ModelAllTable->distance;
  if (distance == 0.0)
  {
    if (v28 <= 150.0)
    {
      p_distance = &(*pNbCamera)->distance;
      v32 = *p_distance;
      if (v28 <= 90.0)
        v34 = v28 + v28;
      else
        v34 = v28 * 1.5;
      v30 = v34 / v26;
    }
    else
    {
      v30 = v28 / v26;
      p_distance = &(*pNbCamera)->distance;
      v32 = *p_distance;
    }
    *p_distance = v30 + v32;
      goto LABEL_56;
  }
  else
  {
    (*pNbCamera)->distance = (scl * distance) + (*pNbCamera)->distance;
      goto LABEL_56;
  }
LABEL_56:
  v36 = sdfAtan(0.47124);
  v37 = 550.0;
  if (Sphere >= 550.0 || v16 <= 150.0 || v15 >= 150.0)
    v37 = Sphere;
  v40 = v37 / v36;
  if ((v37 / v36) > (*pNbCamera)->distance)
  {
    for (j = 0; j != 32; ++j)
    {
      form = v7->form;
      pFormation = form->m_Items[j];
      if ((pFormation->stat & 3) == 3 && (pFormation->stat & v9) != 0)
      {
        effBTLModelGetPosition(&pFormation, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&pFormation, &pPos);
      }
    }
    sub_854710(&v63, 2u);
    sub_854930(&v63, 2u);
    (*pNbCamera)->distance = v40;
  }
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v63);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  v46 = *pNbCamera;
  if (!(*pNbCamera)->frame)
  {
    v47 = v68->scl;
    r = v68->r;
    v49 = v46->distance;
    v46->angle = sdfAtan(((r * v47) * 1.5) / v49, 0);
    sub_854710(&v63, 0);
    if (v50 <= 0.0 || (sub_854710(&v63, 0), v51 < v28) && (sub_854710(&v63, 0), v52 > -v28))
      (*pNbCamera)->angle = -(*pNbCamera)->angle;
  }
  angle = (*pNbCamera)->angle;
  SetRotateMatrixY(angle);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->fovy = 0.69813;
  if (nbCameraBoss_CheckRotate(&v68))
  {
    effBTLModelLook(&v68, &p);
  }
  effBTLModelGetPosition(&v68, &pPos);
  v57 = effBTLSkillGetTargetNumber();
  if (v57)
  {
    v59 = v57;
    v60 = 0;
    while (1)
    {
      pFormation = effBTLSkillGetTargetFormation(v60);
      else if (!nbCameraBoss_CheckRotate(&pFormation))
      {
        goto LABEL_124;
      }
      if ((~pFormation->stat & 3) != 0 || pFormation->formindex == v68->formindex)
        goto LABEL_124;
      else
      {
        if (nbCameraBoss_CheckRotate(&pFormation))
          goto LABEL_118;
LABEL_124:
        if (v59 == ++v60)
          return;
      }
    }
  }
}

// 0x16842c0
void nbCameraShot_InvokeTargetReverse_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  nbFormation_t_o *TargetFormation;
  f32 radius;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v14;
  f32 v16;
  f32 v17;
  UnityEngine_Vector4_o v22;
  UnityEngine_Vector4_o pTargetPos;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v25;
  nbFormation_t_o *pFormation;

  v25 = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&pTargetPos.x = 0;
  *&pTargetPos.z = 0;
  *&v22.x = 0;
  *&v22.z = 0;
  effBTLModelAllShow();
  effBTLModelTargetGroupHide();
  TargetFormation = effBTLSkillGetTargetFormation(0);
  pFormation = TargetFormation;
  v25 = effBTLSkillGetInvokeFormation(0);
  radius = nbCameraGetModelAllTable(TargetFormation)->radius;
  if (radius == 0.0)
    radius = TargetFormation->r;
  v9 = radius * TargetFormation->scl;
  if (v9 > 100.0)
    v9 = v9 * (100.0 / v9);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  sub_854930(&p, 1u);
  effBTLModelGetSphereCenter(&v25);
  SDF_VU0__STOREVECTOR(&pTargetPos);
  SDF_VU0__LOADVECTOR(pTargetPos);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&v22);
  SDF_VU0__SUBVECTOR();
  v10 = SDF_VU0__GETLENGTH();
  sub_854710(&pTargetPos, 0);
  v12 = v11;
  sub_854710(&p, 0);
  if (v12 <= v14)
  {
    v16 = sdfAtan((v9 * 1.7) / v10, 0);
  }
  else
  {
    v16 = -sdfAtan((v9 * 1.7) / v10, 0);
  }
  SetRotateMatrixY(v16);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v22);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(pTargetPos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&pTargetPos);
  SDF_VU0__LOADVECTOR(pTargetPos);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v17 = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = v17 + ((v9 * 2.5) / sdfAtan(0.34907));
  (*pNbCamera)->fovy = 0.69813;
  if (nbCameraBoss_CheckRotate(&pFormation))
  {
    effBTLModelLook2(&pFormation, &pTargetPos, 0.5236);
  }
  if (nbCameraBoss_CheckRotate(&v25))
  {
    effBTLModelLook(&v25, &p);
  }
}

// 0x1683e00
void nbCameraShot_InvokeTarget_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  nbFormation_t_o *v6;
  f32 radius;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v14;
  f32 v16;
  f32 v17;
  UnityEngine_Vector4_o v22;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.z = 0;
  TargetFormation = 0;
  *&v23.x = 0;
  *&v24.z = 0;
  *&p.x = 0;
  *&v23.z = 0;
  *&v24.x = 0;
  *&v22.x = 0;
  *&v22.z = 0;
  effBTLModelTargetPartyShow();
  effBTLModelInvokeGroupHide();
  TargetFormation = effBTLSkillGetTargetFormation(0);
  v6 = effBTLSkillGetInvokeFormation(0);
  pFormation = v6;
  radius = nbCameraGetModelAllTable(v6)->radius;
  if (radius == 0.0)
    radius = v6->r;
  v9 = radius * v6->scl;
  if (v9 > 100.0)
    v9 = v9 * (100.0 / v9);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  sub_854930(&p, 1u);
  effBTLModelGetSphereCenter(&TargetFormation);
  SDF_VU0__STOREVECTOR(&v24);
  SDF_VU0__STOREVECTOR(&v22);
  SDF_VU0__LOADVECTOR(v24);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&v23);
  SDF_VU0__SUBVECTOR();
  v10 = SDF_VU0__GETLENGTH();
  sub_854710(&v24, 0);
  v12 = v11;
  sub_854710(&p, 0);
  if (v12 <= v14)
  {
    v16 = sdfAtan((v9 * 1.7) / v10, 0);
  }
  else
  {
    v16 = -sdfAtan((v9 * 1.7) / v10, 0);
  }
  SetRotateMatrixY(v16);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v23);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(v24);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v24);
  SDF_VU0__LOADVECTOR(v24);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v17 = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = v17 + ((v9 * 2.5) / sdfAtan(0.47124));
  (*pNbCamera)->fovy = 0.69813;
  if (nbCameraBoss_CheckRotate(&pFormation))
  {
    effBTLModelLook(&pFormation, &v22);
  }
  if (nbCameraBoss_CheckRotate(&TargetFormation))
  {
    effBTLModelLook2(&TargetFormation, &p, 0.5236);
  }
}

// 0x1682890
void nbCameraShot_Invoke_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u64 *v6;
  f32 Radius;
  f32 fovy;
  f32 v11;
  f32 v13;
  nbCameraSkillInfo_t_o *v14;
  f32 v15;
  f32 HeightMin;
  f32 WidthMin;
  f32 v18;
  f32 v19;
  f32 angleH;
  f32 v22;
  u32 v23;
  f32 v24;
  u32 v27;
  f32 angleW;
  f32 v32;
  struct UnityEngine_Vector4_o *p_direction;
  struct UnityEngine_Vector4_o *v34;
  struct UnityEngine_Vector4_o *v35;
  UnityEngine_Vector4_o v36;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&v36.x = 0;
  *&v36.z = 0;
  v6 = NewSpecific(f32, 3u);
  effBTLModelAllHide();
  effBTLModelInvokeShow();
  pFormation = effBTLSkillGetInvokeFormation(0);
  (*pNbCamera)->fovy = 0.69813;
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  Radius = effBTLModelGetRadius(&pFormation);
  fovy = (*pNbCamera)->fovy;
  v11 = Radius;
  v13 = sdfAtan((fovy * 1.35) * 0.5, 0);
  v14 = *pNBSInfo;
  v15 = v13;
  HeightMin = (*pNBSInfo)->HeightMin;
  if (HeightMin != 0.0)
  {
    sub_854930(&(*pNbCamera)->fields, 1u);
    v14 = *pNBSInfo;
    HeightMin = (*pNBSInfo)->HeightMin;
  }
  WidthMin = v14->WidthMin;
  if (HeightMin <= (v11 + v11))
    v18 = v11;
  else
    v18 = HeightMin * 0.5;
  if (WidthMin <= (v18 + v18))
    v19 = v18;
  else
    v19 = WidthMin * 0.5;
  effBTLModelGetDirection(&pFormation, &v36);
  sub_854710(&v36, 2u);
  angleH = (*pNBSInfo)->angleH;
  if (v22 > 0.0)
  {
    v23 = *(v6 + 6);
    v24 = -angleH;
    *(v6 + 8) = v24;
    *(v6 + 9) = -(*pNBSInfo)->angleW;
    if (*(v6 + 6) > 2u)
      goto LABEL_36;
LABEL_35:
  }
  v27 = *(v6 + 6);
  *(v6 + 8) = angleH;
  angleW = (*pNBSInfo)->angleW;
  *(v6 + 9) = angleW;
  if (*(v6 + 6) <= 2u)
    goto LABEL_35;
LABEL_36:
  v32 = v19 / v15;
  *(v6 + 10) = 0;
  SetRotateMatrixXYZ(v6);
  SDF_VU0__LOADVECTOR(v36);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&v36);
  p_direction = &(*pNbCamera)->direction;
  sub_854710(&v36, 0);
  sub_854930(p_direction, 0);
  v34 = &(*pNbCamera)->direction;
  sub_854710(&v36, 1u);
  sub_854930(v34, 1u);
  v35 = &(*pNbCamera)->direction;
  sub_854710(&v36, 2u);
  sub_854930(v35, 2u);
  (*pNbCamera)->distance = v32;
}

// 0x16839a0
void nbCameraShot_One_Calc(nbCamera_t **pNbCamera, nbFormation_t **pFormation) {
  if (!effBTLModelGetMarkPositionEvalTm(pFormation, 1u))
  {
    effBTLModelGetSphereCenter(pFormation);
  }
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
}

// 0x16832e0
void nbCameraShot_One_Init(nbCamera_t **pNbCamera, nbFormation_t **pFormation) {
  u64 *v6;
  u32 v8;
  u32 TargetParty;
  u32 v11;
  f32 fovy;
  u32 v13;
  u32 TargetNumber;
  f32 v18;
  f32 v19;
  f32 v21;
  f32 v22;
  f32 v24;
  u32 v27;
  s32 v28;
  u32 v34;
  f32 v38;
  f32 v39;
  f32 v43;
  u64 v48[2];
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormationa;

  *&p.z = 0;
  pFormationa = 0;
  *&v49.z = 0;
  *&p.x = 0;
  *&v49.x = 0;
  v48[0] = 0;
  v48[1] = 0;
  v6 = NewSpecific(f32, 3u);
  effBTLModelAllHide();
  effBTLModelInvokeGroupHide();
  v8 = effBTLSkillGetInvokeParty();
  TargetParty = effBTLSkillGetTargetParty();
  (*pNbCamera)->fovy = 0.69813;
  v11 = TargetParty;
  fovy = (*pNbCamera)->fovy;
  (*pNbCamera)->distance = ((*pFormation)->oneshotr * (*pFormation)->scl)
                                / sdfAtan(fovy * 0.5);
  v13 = *(v6 + 6);
  *(v6 + 8) = 0;
  *(v6 + 9) = 0;
  *(v6 + 10) = 0;
  TargetNumber = effBTLSkillGetTargetNumber();
  if (v8 == v11 || TargetNumber != 1)
  {
    SDF_VU0__LOADVECTOR((*pFormation)->rot, 0);
    v24 = EulerAngleAxisY();
    if (*(v6 + 6) > 1u)
      goto LABEL_31;
LABEL_30:
  }
  pFormationa = effBTLSkillGetTargetFormation(0);
  effBTLModelGetSphereCenter(&pFormationa);
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelGetSphereCenter(pFormation);
  SDF_VU0__STOREVECTOR(&v49);
  sub_854710(&p, 0);
  sub_854710(&v49, 0);
  sub_854930(v48, 0);
  sub_854710(&p, 2u);
  sub_854710(&v49, 2u);
  sub_854930(v48, 2u);
  sub_854710(v48, 0);
  v19 = v18;
  sub_854710(v48, 2u);
  v22 = v21;
  v24 = sdfAtan2(v19, v22);
  if (*(v6 + 6) <= 1u)
    goto LABEL_30;
LABEL_31:
  *(v6 + 9) = v24;
  v27 = DDS3EFFECT_RAND_I() & 3;
  if (v27 == 1)
  {
    v28 = -1098511726;
    if (*(v6 + 6))
      goto LABEL_39;
LABEL_38:
  }
  if (v27 == 2)
  {
    v28 = 1035122882;
    if (*(v6 + 6))
      goto LABEL_39;
    goto LABEL_38;
  }
  if (v27 != 3)
  {
    v28 = 1048971922;
    if (*(v6 + 6))
      goto LABEL_39;
    goto LABEL_38;
  }
  v28 = -1112360766;
  if (!*(v6 + 6))
    goto LABEL_38;
LABEL_39:
  *(v6 + 8) = v28;
  nbCameraCurrent->anim->rotate_f = 0;
  nbCameraCurrent->anim->rotate_s = 0.0;
  nbCameraCurrent->anim->distance_f = 0;
  nbCameraCurrent->anim->distance_s = 0.0;
  v34 = DDS3EFFECT_RAND_I() & 3;
  if (v34 == 1)
  {
    v43 = -1.0472;
    goto LABEL_77;
  }
  if (v34 == 2)
  {
    nbCameraAnim_RotateSet(&nbCameraCurrent, 60, -0.2618, 0);
    v38 = *(v6 + 9);
    v39 = 0.34907;
    goto LABEL_72;
  }
  if (v34 != 3)
  {
    v43 = 1.0472;
LABEL_77:
    nbCameraAnim_RotateSet(&nbCameraCurrent, 60, v43, -20);
    goto LABEL_78;
  }
  nbCameraAnim_RotateSet(&nbCameraCurrent, 60, 0.2618, 0);
  v38 = *(v6 + 9);
  v39 = -0.34907;
LABEL_72:
  *(v6 + 9) = v38 + v39;
LABEL_78:
  SetRotateMatrixXYZ(v6);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  sub_854930(&(*pNbCamera)->direction, 3u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  Postblur_DrawStop = 1;
}

// 0x1683cd0
void nbCameraShot_PullOne_Calc(nbCamera_t **pNbCamera, f32 rate) {
  nbCamera_t_Fields *p_fields;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(p_fields, 1u);
  sub_854930(p_fields, 1u);
  nbCameraShot_GroundCollision(pNbCamera);
}

// 0x1683a50
void nbCameraShot_PullOne_Init(nbCamera_t **pNbCamera) {
  u64 *v4;
  nbFormation_t_o *v6;
  UnityEngine_Vector4_o *v8;
  f32 fovy;
  f32 v10;
  f32 x;
  u32 v12;
  f32 v15;

  v4 = NewSpecific(f32, 3u);
  effBTLModelAllHide();
  effBTLModelInvokeGroupHide();
  v6 = effBTLSkillGetInvokeFormation(0);
  (*pNbCamera)->fovy = 0.69813;
  v8 = v6;
  fovy = (*pNbCamera)->fovy;
  v10 = sdfAtan((fovy * 0.5) * 2.25, 0);
  x = v8[6].x;
  if (x <= v8[6].y)
    x = v8[6].y;
  (*pNbCamera)->distance = (x * v8[6].w) / v10;
  v12 = *(v4 + 6);
  *(v4 + 8) = 0;
  *(v4 + 10) = 0;
  SDF_VU0__LOADVECTOR(v8[4]);
  v15 = EulerAngleAxisY();
  *(v4 + 9) = -v15;
  SetRotateMatrixXYZ(v4);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  sub_854930(&(*pNbCamera)->direction, 3u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
}

// 0x16818f0
void nbCameraShot_TargetParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u64 *v6;
  u32 TargetParty;
  f32 Sphere;
  f32 fovy;
  f32 v12;
  f32 v14;
  nbCameraSkillInfo_t_o *v15;
  f32 v16;
  f32 HeightMin;
  f32 WidthMin;
  f32 v19;
  f32 v20;
  f32 angleH;
  f32 v23;
  u32 v24;
  f32 v25;
  u32 v28;
  f32 v32;
  struct UnityEngine_Vector4_o *p_direction;
  struct UnityEngine_Vector4_o *v34;
  struct UnityEngine_Vector4_o *v35;
  f32 v36;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 angleW;
  nbCamera_t_o *v44;
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o pDirection;

  *&p.x = 0;
  *&p.z = 0;
  *&v45.x = 0;
  *&v45.z = 0;
  *&pDirection.x = 0;
  *&pDirection.z = 0;
  v6 = NewSpecific(f32, 3u);
  effBTLModelAllHide();
  effBTLModelTargetPartyShow();
  TargetParty = effBTLSkillGetTargetParty();
  (*pNbCamera)->fovy = 0.69813;
  Sphere = effBTLModelGroupGetSphere(TargetParty);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  fovy = (*pNbCamera)->fovy;
  v12 = fovy * flt_32C3190[effBTLSkillGetTargetNumber() > 1];
  v14 = sdfAtan(v12 * 0.5);
  v15 = *pNBSInfo;
  v16 = v14;
  HeightMin = (*pNBSInfo)->HeightMin;
  if (HeightMin != 0.0)
  {
    sub_854930(&(*pNbCamera)->fields, 1u);
    v15 = *pNBSInfo;
    HeightMin = (*pNBSInfo)->HeightMin;
  }
  WidthMin = v15->WidthMin;
  if (HeightMin <= (Sphere + Sphere))
    v19 = Sphere;
  else
    v19 = HeightMin * 0.5;
  if (WidthMin <= (v19 + v19))
    v20 = v19;
  else
    v20 = WidthMin * 0.5;
  effBTLModelGroupGetDirection(TargetParty, &pDirection);
  sub_854710(&pDirection, 2u);
  angleH = (*pNBSInfo)->angleH;
  if (v23 > 0.0)
  {
    v24 = *(v6 + 6);
    v25 = -angleH;
    *(v6 + 8) = v25;
    *(v6 + 9) = -(*pNBSInfo)->angleW;
    if (*(v6 + 6) > 2u)
      goto LABEL_36;
LABEL_35:
  }
  v28 = *(v6 + 6);
  *(v6 + 8) = angleH;
  *(v6 + 9) = LODWORD((*pNBSInfo)->angleW);
  if (*(v6 + 6) <= 2u)
    goto LABEL_35;
LABEL_36:
  v32 = v20 / v16;
  *(v6 + 10) = 0;
  SetRotateMatrixXYZ(v6);
  SDF_VU0__LOADVECTOR(pDirection);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&pDirection);
  p_direction = &(*pNbCamera)->direction;
  sub_854710(&pDirection, 0);
  sub_854930(p_direction, 0);
  v34 = &(*pNbCamera)->direction;
  sub_854710(&pDirection, 1u);
  sub_854930(v34, 1u);
  v35 = &(*pNbCamera)->direction;
  sub_854710(&pDirection, 2u);
  sub_854930(v35, 2u);
  (*pNbCamera)->distance = v32;
  *&p.x = 0;
  *&p.z = 0;
  *&v45.x = 0;
  *&v45.z = 0;
  sub_854930(&v45, 0);
  sub_854710(&v45, 0);
  sub_854930(&v45, 1u);
  sub_854930(&v45, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR_B(v45);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B((*pNbCamera)->target, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  if (v36 > 0.0)
  {
    sub_854710(&(*pNbCamera)->fields, 1u);
    v39 = v38;
    v40 = v32 * 1.15;
    sdfSqrt((v40 * v40) + (v39 * v39), 0);
    effBTLModelGroupGetDirection(TargetParty, &pDirection);
    sub_854710(&pDirection, 0);
    sub_854930(&p, 0);
    sub_854710(&pDirection, 1u);
    sub_854930(&p, 1u);
    sub_854710(&pDirection, 2u);
    sub_854930(&p, 2u);
    angleW = (*pNBSInfo)->angleW;
    SetRotateMatrixY(angleW);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&p);
    sub_854710(&p, 0);
    sub_854710(&(*pNbCamera)->fields, 0);
    sub_854930(&p, 0);
    sub_854710(&p, 2u);
    sub_854710(&(*pNbCamera)->fields, 2u);
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    v44 = *pNbCamera;
    v44->distance = SDF_VU0__GETLENGTH() * 0.85;
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  }
}

// 0x1682c40
void nbCameraShot_Target_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u64 *v6;
  f32 Radius;
  f32 fovy;
  f32 v11;
  f32 v13;
  nbCameraSkillInfo_t_o *v14;
  f32 v15;
  f32 HeightMin;
  f32 WidthMin;
  f32 v18;
  f32 v19;
  f32 angleH;
  f32 v22;
  u32 v23;
  f32 v24;
  u32 v27;
  f32 v31;
  struct UnityEngine_Vector4_o *p_direction;
  struct UnityEngine_Vector4_o *v33;
  struct UnityEngine_Vector4_o *v34;
  f32 v35;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 angleW;
  nbCamera_t_o *v43;
  UnityEngine_Vector4_o v44;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o pDirection;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v44.x = 0;
  *&v44.z = 0;
  *&pDirection.x = 0;
  *&pDirection.z = 0;
  v6 = NewSpecific(f32, 3u);
  effBTLModelAllHide();
  effBTLModelTargetPartyShow();
  pFormation = effBTLSkillGetTargetFormation(0);
  (*pNbCamera)->fovy = 0.69813;
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  Radius = effBTLModelGetRadius(&pFormation);
  fovy = (*pNbCamera)->fovy;
  v11 = Radius;
  v13 = sdfAtan((fovy * 1.35) * 0.5, 0);
  v14 = *pNBSInfo;
  v15 = v13;
  HeightMin = (*pNBSInfo)->HeightMin;
  if (HeightMin != 0.0)
  {
    sub_854930(&(*pNbCamera)->fields, 1u);
    v14 = *pNBSInfo;
    HeightMin = (*pNBSInfo)->HeightMin;
  }
  WidthMin = v14->WidthMin;
  if (HeightMin <= (v11 + v11))
    v18 = v11;
  else
    v18 = HeightMin * 0.5;
  if (WidthMin <= (v18 + v18))
    v19 = v18;
  else
    v19 = WidthMin * 0.5;
  effBTLModelGetDirection(&pFormation, &pDirection);
  sub_854710(&pDirection, 2u);
  angleH = (*pNBSInfo)->angleH;
  if (v22 > 0.0)
  {
    v23 = *(v6 + 6);
    v24 = -angleH;
    *(v6 + 8) = v24;
    *(v6 + 9) = -(*pNBSInfo)->angleW;
    if (*(v6 + 6) > 2u)
      goto LABEL_36;
LABEL_35:
  }
  v27 = *(v6 + 6);
  *(v6 + 8) = angleH;
  *(v6 + 9) = LODWORD((*pNBSInfo)->angleW);
  if (*(v6 + 6) <= 2u)
    goto LABEL_35;
LABEL_36:
  v31 = v19 / v15;
  *(v6 + 10) = 0;
  SetRotateMatrixXYZ(v6);
  SDF_VU0__LOADVECTOR(pDirection);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&pDirection);
  p_direction = &(*pNbCamera)->direction;
  sub_854710(&pDirection, 0);
  sub_854930(p_direction, 0);
  v33 = &(*pNbCamera)->direction;
  sub_854710(&pDirection, 1u);
  sub_854930(v33, 1u);
  v34 = &(*pNbCamera)->direction;
  sub_854710(&pDirection, 2u);
  sub_854930(v34, 2u);
  (*pNbCamera)->distance = v31;
  *&p.x = 0;
  *&p.z = 0;
  *&v44.x = 0;
  *&v44.z = 0;
  sub_854930(&v44, 0);
  sub_854710(&v44, 0);
  sub_854930(&v44, 1u);
  sub_854930(&v44, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR_B(v44);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B((*pNbCamera)->target, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  if (v35 > 0.0)
  {
    sub_854710(&(*pNbCamera)->fields, 1u);
    v38 = v37;
    v39 = v31 * 1.15;
    sdfSqrt((v39 * v39) + (v38 * v38), 0);
    effBTLModelGetDirection(&pFormation, &pDirection);
    sub_854710(&pDirection, 0);
    sub_854930(&p, 0);
    sub_854710(&pDirection, 1u);
    sub_854930(&p, 1u);
    sub_854710(&pDirection, 2u);
    sub_854930(&p, 2u);
    angleW = (*pNBSInfo)->angleW;
    SetRotateMatrixY(angleW);
    SDF_VU0__LOADVECTOR(p);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&p);
    sub_854710(&p, 0);
    sub_854710(&(*pNbCamera)->fields, 0);
    sub_854930(&p, 0);
    sub_854710(&p, 2u);
    sub_854710(&(*pNbCamera)->fields, 2u);
    sub_854930(&p, 2u);
    SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    v43 = *pNbCamera;
    v43->distance = SDF_VU0__GETLENGTH() * 0.85;
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  }
}

// 0x1686a30
void nbCameraState_Analyze_Calc(nbCamera_t **pNbCamera) {
  u32 ID;
  u32 v6;
  nbCameraSkill_c *v7;
  f32 v9;
  nbCamera_t_o *v14;
  f32 fovy;
  f32 v18;
  f32 v19;
  f32 v20;
  nbCamera_t_o *v22;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  *&v23.x = 0;
  *&v23.z = 0;
  pFormation = effBTLSkillGetTargetFormation(0);
  ID = effBTLModelGetID(&pFormation);
  v6 = ID;
  if (ID - 258 <= 0x23 && ((1LL << (ID - 2)) & 0xE00000043LL) != 0)
  {
    effBTLModelInvokePartyHide();
    return;
  }
  nbCamera_Analyze_Rate = nbCamera_Analyze_Rate
                                           + nbCamera_Analyze_Rate_Add;
  if (nbCamera_Analyze_Rate <= 0.215)
  {
    v9 = 0.725;
    if ((*&v7->_2.bitflags1 & 0x200) != 0)
    {
LABEL_20:
    }
  }
  else
  {
    v9 = 1.1;
    if ((*&v7->_2.bitflags1 & 0x200) != 0)
      goto LABEL_20;
  }
  nbCamera_Analyze_Rate_Add = nbCamera_Analyze_Rate_Add * v9;
  if (nbCamera_Analyze_Rate < 0.0)
  {
    nbCamera_Analyze_Rate = 0.0;
  }
  sub_854930(&v24, 0);
  sub_854710(&v24, 0);
  sub_854930(&v24, 1u);
  sub_854930(&v24, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR_B(v24);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B((*pNbCamera)->target, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v23);
  effBTLModelGetMarkPosition2(&pFormation, 1u);
  SDF_VU0__LOADVECTOR_B(nbCamera_Analyze_Target);
  SDF_VU0__INTERPOLATE(nbCamera_Analyze_Rate);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v23);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  v14 = *pNbCamera;
  v14->distance = SDF_VU0__GETLENGTH();
  if (nbCamera_Analyze_Rate > 0.001)
  {
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  }
  (*pNbCamera)->fovy = 0.69813;
  fovy = (*pNbCamera)->fovy;
  v18 = sdfAtan(fovy * 0.5);
  if (v6 == 130 || v6 == 287)
    v19 = (pFormation->oneshotr * pFormation->scl) * 1.25;
  else
    v19 = pFormation->oneshotr * pFormation->scl;
  v20 = v19 / v18;
  v22 = *pNbCamera;
  v22->distance = v20
                       + ((nbCamera_Analyze_Distance - v20)
                        * nbCamera_Analyze_Rate);
  if ((*pNbCamera)->distance < v20)
    (*pNbCamera)->distance = v20;
  ++nbCamera_Analyze_Frame;
}

// 0x1686960
void nbCameraState_Analyze_Set(nbCamera_t **pNbCamera) {
  SDF_VU0__COPYVECTOR(&nbCamera_Analyze_Target, (*pNbCamera)->target, 0);
  nbCamera_Analyze_Distance = (*pNbCamera)->distance;
  nbCamera_Analyze_Rate = 1.0;
  nbCamera_Analyze_Rate_Add = -0.01;
  nbCamera_Analyze_Frame = 1;
  nbCamera_Analyze_Wait = 5;
}

// 0x1688b30
void nbCameraState_Cut1Enemy_Calc(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  nbCamera_t_o *v8;
  f32 fovy;
  f32 v11;
  f32 v12;
  nbCamera_t_o *v13;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v15;
  nbFormation_t_o *pFormation;

  *&v15.z = 0;
  pFormation = 0;
  *&v15.x = 0;
  *&p.x = 0;
  *&p.z = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  if ((nbCamera_Cut1Enemy_Frame & 0x80000000) == 0)
  {
    nbCamera_Cut1Enemy_Rate = nbCamera_Cut1Enemy_Rate * 0.88;
    sub_854930(&v15, 0);
    sub_854710(&v15, 0);
    sub_854930(&v15, 1u);
    sub_854930(&v15, 2u);
    SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
    SDF_VU0__LOADVECTOR_B(v15);
    SDF_VU0__MULVECTOR();
    SDF_VU0__LOADVECTOR_B((*pNbCamera)->target, 0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&p);
    effBTLModelGetMarkPosition2(&pFormation, 1u);
    SDF_VU0__LOADVECTOR_B(nbCamera_Cut1Enemy_Target);
    SDF_VU0__INTERPOLATE(nbCamera_Cut1Enemy_Rate);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    v8 = *pNbCamera;
    v8->distance = SDF_VU0__GETLENGTH();
    if (nbCamera_Cut1Enemy_Rate > 0.001)
    {
      SDF_VU0__COPYVECTOR_C_TO_A();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
    }
    (*pNbCamera)->fovy = 0.69813;
    fovy = (*pNbCamera)->fovy;
    v11 = sdfAtan(fovy * 0.5);
    v12 = ((pFormation->oneshotr * pFormation->scl) * 1.25) / v11;
    v13 = *pNbCamera;
    v13->distance = v12
                         + ((nbCamera_Cut1Enemy_Distance - v12)
                          * nbCamera_Cut1Enemy_Rate);
    if ((*pNbCamera)->distance < v12)
      (*pNbCamera)->distance = v12;
  }
  ++nbCamera_Cut1Enemy_Frame;
}

// 0x1688960
void nbCameraState_Cut1Enemy_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u64 *v4;
  char v6;
  f32 v9;
  nbFormation_t_o *pFormation;
  nbCameraSkillInfo_t_o *pNBSInfoa;

  pFormation = 0;
  v4 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v4);
  pNBSInfoa = v4;
  v4[4] = 0x4416000000000000LL;
  v6 = DDS3EFFECT_RAND_I();
  v9 = 1.0;
  if ((v6 & 1) == 0)
    v9 = -1.0;
  *(v4 + 6) = v9;
  *(v4 + 7) = 0;
  nbCameraShot_InvokeParty_Set2(pNbCamera, &pNBSInfoa);
  SDF_VU0__COPYVECTOR(
    &nbCamera_Cut1Enemy_Target,
    (*pNbCamera)->target,
    0);
  nbCamera_Cut1Enemy_Distance = (*pNbCamera)->distance;
  pFormation = effBTLSkillGetInvokeFormation(0);
  effBTLModelGetMarkPosition2(&pFormation, 1u);
  SDF_VU0__LOADVECTOR_B(nbCamera_Cut1Enemy_Target);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  nbCamera_Cut1Enemy_Rate = 1.0;
  nbCamera_Cut1Enemy_Frame = 0;
}

// 0x168ad30
void nbCameraState_EnemyBad_Calc(void) {
  UnityEngine_Vector4_o *nbCameraCurrent;
  UnityEngine_Vector4_o v5;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  *&v5.x = 0;
  *&v5.z = 0;
  nbCameraState_EnemyBad_Rate = nbCameraState_EnemyBad_Rate * 0.925;
  sub_854930(&v5, 0);
  sub_854710(&v5, 0);
  sub_854930(&v5, 1u);
  sub_854930(&v5, 2u);
  SDF_VU0__LOADVECTOR(nbCameraCurrent[2]);
  SDF_VU0__LOADVECTOR_B(v5);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(nbCameraCurrent[1]);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(nbCameraState_EnemyBad_EndTarget);
  SDF_VU0__LOADVECTOR_B(nbCameraState_EnemyBad_StartTarget);
  SDF_VU0__INTERPOLATE(nbCameraState_EnemyBad_Rate);
  SDF_VU0__STOREVECTOR(nbCameraCurrent + 1);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(nbCameraCurrent + 2);
  nbCameraCurrent[3].x = nbCameraState_EnemyBad_Distance
                              * ((nbCameraState_EnemyBad_Rate * 0.3) + 0.7);
}

// 0x168aa20
void nbCameraState_EnemyBad_Init(void) {
  u64 *v1;
  nbCamera_t_o *nbCameraCurrent;
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v7;
  u64 v8;
  u32 v9;
  u32 v10;
  struct nbFormation_t_array *form;
  s32 v13;
  bool v14;
  s32 v15;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v22;
  struct nbFormation_t_array *v24;
  s64 formindex;
  nbCameraSkillInfo_t_o *v28;
  nbFormation_t_o *pFormation;
  nbCamera_t_o *pNbCamera;

  pNbCamera = 0;
  pFormation = 0;
  v1 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v1);
  v28 = v1;
  pNbCamera = nbCameraCurrent;
  MainProcessData = nbGetMainProcessData();
  v7 = MainProcessData;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  do
  {
    form = MainProcessData->form;
    v13 = form->m_Items[v8]->stat & 0x203;
    v14 = v13 == 515;
    if (v13 == 515)
      v15 = 1 << v8;
    else
      v15 = 0;
    if (v14)
      v9 = v8;
    ++v8;
    v10 |= v15;
  }
  while (v8 != 32);
  effBTLSkillSetFormationInfo(v9, v10);
  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  effBTLModelAllHide();
  effBTLModelTargetPartyShow();
  v1[3] = 1043511490;
  v1[4] = 0x442F000000000000LL;
  nbCameraShot_TargetParty_Set2(&pNbCamera, &v28);
  SDF_VU0__COPYVECTOR(&nbCameraState_EnemyBad_StartTarget, nbCameraCurrent->target);
  order = v7->order;
  party = v7->party;
  v22 = order->m_Items[v7->orderindex];
  v24 = v7->form;
  formindex = party->m_Items[v22]->formindex;
  pFormation = v24->m_Items[formindex];
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&nbCameraState_EnemyBad_EndTarget);
  sub_854710(&nbCameraState_EnemyBad_StartTarget, 1u);
  sub_854930(&nbCameraState_EnemyBad_EndTarget, 1u);
  nbCameraState_EnemyBad_Distance = nbCameraCurrent->distance;
  nbCameraState_EnemyBad_Rate = 1.0;
}

// 0x168a650
void nbCameraState_EnemySide_Init(void) {
  u64 *v1;
  nbMainProcessData_t_o *MainProcessData;
  u64 v5;
  u32 v6;
  u32 v7;
  struct nbFormation_t_array *form;
  s32 v10;
  bool v11;
  s32 v12;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v1 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v1);
  pNBSInfo = v1;
  MainProcessData = nbGetMainProcessData();
  v5 = 0;
  v6 = 0;
  v7 = 0;
  do
  {
    form = MainProcessData->form;
    v10 = form->m_Items[v5]->stat & 0x203;
    v11 = v10 == 515;
    if (v10 == 515)
      v12 = 1 << v5;
    else
      v12 = 0;
    if (v11)
      v6 = v5;
    ++v5;
    v7 |= v12;
  }
  while (v5 != 32);
  effBTLSkillSetFormationInfo(v6, v7);
  effBTLModelAllHide();
  effBTLModelTargetPartyShow();
  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  v1[4] = 0x442F000000000000LL;
  *(v1 + 6) = 1048971922;
  *(v1 + 7) = dword_32C3BE0[DDS3EFFECT_RAND_I() & 3];
  nbCameraShot_TargetParty_Set2(&nbCameraCurrent, &pNBSInfo);
}

// 0x168a430
void nbCameraState_PlayerSide_Init(void) {
  u64 *v1;
  nbMainProcessData_t_o *MainProcessData;
  u64 v5;
  u32 v6;
  u32 v7;
  struct nbFormation_t_array *form;
  s32 v10;
  bool v11;
  s32 v12;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v1 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v1);
  pNBSInfo = v1;
  MainProcessData = nbGetMainProcessData();
  v5 = 0;
  v6 = 0;
  v7 = 0;
  do
  {
    form = MainProcessData->form;
    v10 = form->m_Items[v5]->stat & 0x103;
    v11 = v10 == 259;
    if (v10 == 259)
      v12 = 1 << v5;
    else
      v12 = 0;
    if (v11)
      v6 = v5;
    ++v5;
    v7 |= v12;
  }
  while (v5 != 32);
  effBTLSkillSetFormationInfo(v6, v7);
  effBTLModelAllHide();
  effBTLModelTargetPartyShow();
  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  v1[4] = 0x442F000000000000LL;
  *(v1 + 6) = 1048971922;
  *(v1 + 7) = dword_32C3BE0[DDS3EFFECT_RAND_I() & 3];
  nbCameraShot_TargetParty_Set2(&nbCameraCurrent, &pNBSInfo);
}

// 0x16882e0
void nbCameraState_SkillAttack_Calc(void) {
  u64 *v1;
  f32 cr;
  f32 scl;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  v1 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v1);
  pFormation = effBTLSkillGetInvokeFormation(0);
  else if (!effBTLModelCheckBossID(&pFormation))
  {
    goto LABEL_18;
  }
  if (!nbCameraBoss_Cut2_Run(&nbCameraCurrent))
  {
LABEL_18:
    else if (nbCameraCurrent->frame)
    {
      goto LABEL_21;
    }
    cr = pFormation->cr;
    scl = pFormation->scl;
    nbCameraModelMotionCr = cr * scl;
      goto LABEL_30;
    goto LABEL_22;
  }
}

// 0x1687c00
void nbCameraState_SkillAttack_Init(void) {
  u32 v6;
  u32 TargetParty;
  u64 *v9;
  u64 *v10;
  u32 v12;
  u64 v14;
  f64 v15;
  f32 v17;
  s16 v18;
  s32 v19;
  struct System_Single_array *nbCameraSkill_Ptr_HA;
  s32 max_length;
  f32 v23;
  struct System_Single_array *nbCameraSkill_Ptr_WA;
  s32 v26;
  struct System_Single_array *nbCameraSkill_Ptr_H;
  s64 v29;
  struct System_Single_array *nbCameraSkill_Ptr_W;
  s64 v32;
  nbCameraSkillInfo_t_o **v36;
  f32 Sphere;
  f32 v39;
  u64 *v42;
  nbCameraSkillInfo_t_o **v43;
  f32 v46;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  TargetFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  else if (nbCameraCurrent->frame)
  {
    goto LABEL_11;
  }
  SetDrawFlag(0x2000000u, 1u);
LABEL_11:
  pFormation = effBTLSkillGetInvokeFormation(0);
  else if (!effBTLModelCheckBossID(&pFormation))
  {
    goto LABEL_26;
  }
  if (nbCameraBoss_Cut2_Init(&nbCameraCurrent))
    return;
LABEL_26:
  effBTLModelAllPopPosition();
  if (effBTLSkillGetTargetNumber() != 1)
    goto LABEL_48;
LABEL_32:
  pFormation = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  v6 = effBTLSkillGetInvokeParty();
  TargetParty = effBTLSkillGetTargetParty();
  if (v6 != TargetParty && (pFormation->stat & 0x200) != 0)
  {
    v9 = Allocate(nbCameraSkillPtr_t);
    nbCameraSkillPtr_t___ctor(v9);
    v10 = Allocate(nbCameraSkillInfo_t);
    nbCameraSkillInfo_t___ctor(v10);
    *(v9 + 6) = DDS3EFFECT_RAND_I() % 0x12;
    v12 = DDS3EFFECT_RAND_I();
    LODWORD(v14) = *(v9 + 6);
    *(v9 + 7) = v12 % 0xE;
    v15 = v14;
    v9[4] = 0;
    v17 = v15;
    if ((v18 & 0x200) != 0)
    {
      v19 = v18 & 0x200;
    }
    else
    {
      v19 = 0;
    }
    max_length = nbCameraSkill_Ptr_HA->max_length;
    v23 = 0.0;
    if (max_length <= v17)
      v17 = 0.0;
    *(v10 + 6) = LODWORD(nbCameraSkill_Ptr_HA->m_Items[v17]);
    LODWORD(v15) = *(v9 + 6);
    v26 = nbCameraSkill_Ptr_WA->max_length;
    *&v15 = *&v15;
    if (v26 > *&v15)
      v23 = *&v15;
    *(v10 + 7) = LODWORD(nbCameraSkill_Ptr_WA->m_Items[v23]);
    v29 = *(v9 + 8);
    *(v10 + 8) = LODWORD(nbCameraSkill_Ptr_H->m_Items[v29]);
    v32 = *(v9 + 9);
    *(v10 + 9) = LODWORD(nbCameraSkill_Ptr_W->m_Items[v32]);
    nbCameraState_InvokeTarget_SearchSet();
    Sphere = effBTLModelGroupGetSphere(0x200u);
    v39 = Sphere + Sphere;
    if (v39 >= 1500.0)
    {
      v46 = v39;
      v42 = sub_8D3950(f32, &v46);
      Write_2930400("nbCameraState_SkillAttack : {0:f} < NBCAMERA_ATTACK_MOVE_WIDTH_MAX\n", v42);
      nbCameraShot_InvokeTargetReverse_Set2(&nbCameraCurrent, v43);
        goto LABEL_87;
    }
    else
    {
      bCameraShot_AttackInvokeTargetPartyNear_Set(&nbCameraCurrent, v36);
      {
LABEL_87:
      }
    }
    nbCameraSkillAttack_Move_Frame = 11;
    if (v6 == TargetParty)
      return;
    goto LABEL_100;
  }
  nbCameraSkillAttack_Move_Frame = 0;
  if (v6 != TargetParty)
  {
LABEL_100:
    if (nbCameraBoss_CheckRotate(&TargetFormation))
    {
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&p);
      effBTLModelLook(&TargetFormation, &p);
    }
  }
}

// 0x1689290
void nbCameraState_SkillCut1_Calc(void) {
  nbCameraSkillInfo_t_o **v4;
  u64 v6;
  s32 v7;
  nbFormation_t_o *v12;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  v12 = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  else if (effBTLModelCheckBossID(&pFormation))
  {
LABEL_9:
    if (nbCameraBoss_Cut1_Run(&nbCameraCurrent))
      return;
  }
  if (!nbCameraHero_Cut1_Run(&nbCameraCurrent, &nbCameraSkillNBSInfo))
  {
    v7 = *(*(*(v6 + 184) + 80LL) + 16LL);
    if (v7 == 2)
    {
      nbCameraState_SkillAttack_Calc(v6);
    }
    else if (!v7)
    {
      if ((pFormation->stat & 0x100) != 0)
      {
        v12 = effBTLSkillGetInvokeFormation(0);
        nbCameraShot_One_Calc(&nbCameraCurrent, &v12);
          goto LABEL_60;
      }
      else
      {
        if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
        nbCameraState_Cut1Enemy_Calc(&nbCameraCurrent, v4);
          goto LABEL_60;
      }
LABEL_47:
LABEL_60:
      {
LABEL_61:
      }
LABEL_63:
      nbCameraShot_GroundCollision(&nbCameraCurrent, v4);
      return;
    }
      goto LABEL_60;
    goto LABEL_47;
  }
}

// 0x1688e80
void nbCameraState_SkillCut1_Init(void) {
  nbCameraSkillInfo_t_o **v4;
  u64 v6;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  else if (nbCameraCurrent->frame)
  {
    goto LABEL_11;
  }
  SetDrawFlag(0x2000000u, 1u);
LABEL_11:
  effBTLModelAllPopRotate();
  effBTLModelAllPopPosition();
  pFormation = effBTLSkillGetInvokeFormation(0);
  if (!effBTLModelCheckBossID(&pFormation))
    goto LABEL_82;
  if (!nbCameraBoss_Cut1_Init(&nbCameraCurrent))
  {
LABEL_82:
    if (!nbCameraHero_Cut1_Init(&nbCameraCurrent, &nbCameraSkillNBSInfo))
    {
      switch (*(*(*(v6 + 184) + 80LL) + 16LL))
      {
        case 0:
          if ((pFormation->stat & 0x100) != 0)
          {
            if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
            nbCameraShot_One_Init(&nbCameraCurrent, &pFormation);
          }
          else
          {
            if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
            nbCameraState_Cut1Enemy_Init(&nbCameraCurrent, v4);
          }
          break;
        case 2:
        case 0xA:
          nbCameraState_SkillAttack_Init(v6);
          break;
        case 3:
          if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
          nbCameraShot_InvokeTargetReverse_Set2(&nbCameraCurrent, v4);
          break;
        case 4:
          nbCameraShot_TargetParty_Set2(
            &nbCameraCurrent,
            (*(v6 + 184) + 80LL));
          break;
        case 8:
          nbCameraShot_Summon_Set(&nbCameraCurrent, v4);
          break;
        default:
          return;
      }
    }
  }
}

// 0x168a0c0
void nbCameraState_SkillCut2_Calc(void) {
  u64 v7;
  s32 v8;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  else if (!effBTLModelCheckBossID(&pFormation))
  {
    goto LABEL_18;
  }
  if (!nbCameraBoss_Cut2_Run(&nbCameraCurrent))
  {
LABEL_18:
    if (nbCameraHero_Cut2_Run(&nbCameraCurrent, &nbCameraSkillNBSInfo))
    {
      return;
    }
    if (nbCameraDANTE_Run(&nbCameraCurrent, &nbCameraSkillNBSInfo))
    {
      return;
    }
    if (nbCameraBoss_Cut2_Ptr_Run(&nbCameraCurrent, &nbCameraSkillNBSInfo))
    {
      return;
    }
    v8 = *(*(*(v7 + 184) + 80LL) + 20LL);
    if (v8 == 14)
    {
      if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
      nbCameraState_Analyze_Calc(&nbCameraCurrent);
    }
    else if (v8 == 4)
    {
      nbCameraState_SkillAttack_Calc(v7);
        goto LABEL_69;
      goto LABEL_67;
    }
    {
LABEL_69:
      nbCameraShot_GroundCollision(&nbCameraCurrent);
      return;
    }
LABEL_67:
    goto LABEL_69;
  }
}

// 0x16895a0
void nbCameraState_SkillCut2_Init(void) {
  struct nbCameraSkillPtr_t_array *tbl;
  u32 ID;
  f32 cr;
  f32 scl;
  u32 v24;
  u32 TargetParty;
  nbCameraSkillInfo_t_o **v26;
  u32 v27;
  u32 TargetNumber;
  u32 GroupNumber;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  ID = effBTLSkillGetID();
  nbCamera_SkillInfo_Set(&nbCameraSkillNBSInfo, tbl->m_Items[ID]);
  if (!effBTLSkillGetTargetNumber())
  {
    if (nbCameraSkillNBSInfo->shot_23 == 19)
    {
LABEL_43:
      nbCameraShot_Invoke_Set2(&nbCameraCurrent, &nbCameraSkillNBSInfo);
    }
    else
    {
      Write("nbCameraSkillCut2:Not Target !!!!!!\n", 0);
      nbCameraCurrent->anim->rotate_f = 0;
      nbCameraCurrent->anim->rotate_s = 0.0;
      nbCameraCurrent->anim->distance_f = 0;
      nbCameraCurrent->anim->distance_s = 0.0;
      nbCameraShot_All_Set(&nbCameraCurrent);
    }
    return;
  }
  pFormation = effBTLSkillGetInvokeFormation(0);
  nbCameraCurrent->anim->rotate_f = 0;
  nbCameraCurrent->anim->rotate_s = 0.0;
  nbCameraCurrent->anim->distance_f = 0;
  nbCameraCurrent->anim->distance_s = 0.0;
  else if (effBTLModelCheckBossID(&pFormation))
  {
LABEL_24:
    if (nbCameraBoss_Cut2_Init(&nbCameraCurrent))
      return;
  }
  if (!nbCameraHero_Cut2_Init(&nbCameraCurrent, &nbCameraSkillNBSInfo))
  {
    if (!nbCameraDANTE_Init(&nbCameraCurrent, &nbCameraSkillNBSInfo))
    {
      if (!nbCameraBoss_Cut2_Ptr_Init(&nbCameraCurrent, &nbCameraSkillNBSInfo))
      {
        cr = pFormation->cr;
        scl = pFormation->scl;
        nbCameraModelMotionCr = cr * scl;
        v24 = effBTLSkillGetInvokeParty();
        TargetParty = effBTLSkillGetTargetParty();
        if (v24 == TargetParty)
        {
          switch (nbCameraSkillNBSInfo->shot_23)
          {
            case 0xDu:
              goto LABEL_123;
            case 0x11u:
              nbCameraShot_All_Set2(&nbCameraCurrent, v26);
              return;
            case 0x12u:
              goto LABEL_127;
            case 0x13u:
              goto LABEL_134;
            case 0x14u:
              goto LABEL_141;
            default:
              if (effBTLSkillGetTargetNumber() < 2)
              {
                GroupNumber = effBTLModelGetGroupNumber(v24);
                if (v24 != 512 || GroupNumber < 2)
                {
                  {
                    goto LABEL_126;
                  }
LABEL_220:
LABEL_221:
                  nbCameraShot_Target_Set2(&nbCameraCurrent, &nbCameraSkillNBSInfo);
                  return;
                }
                  goto LABEL_172;
              }
              else
              {
                  goto LABEL_172;
              }
                goto LABEL_172;
              goto LABEL_171;
          }
        }
        v27 = TargetParty;
        TargetNumber = effBTLSkillGetTargetNumber();
        if (TargetNumber < 2)
        {
          switch (nbCameraSkillNBSInfo->shot_23)
          {
            case 1u:
              nbCameraShot_InvokeTarget_Set2(&nbCameraCurrent, v26);
              return;
            case 2u:
            case 0xDu:
LABEL_123:
                goto LABEL_221;
LABEL_126:
              goto LABEL_220;
            case 5u:
LABEL_150:
              nbCameraShot_InvokeTargetPartyTop_Set(&nbCameraCurrent, v26);
              return;
            case 6u:
LABEL_157:
              nbCameraShot_InvokeTargetPartyTop2_Set(&nbCameraCurrent, v26);
              return;
            case 7u:
                goto LABEL_235;
              goto LABEL_233;
            case 0xEu:
              nbCameraShot_InvokeTarget_Set2(&nbCameraCurrent, v26);
              nbCameraState_Analyze_Set(&nbCameraCurrent);
              return;
            case 0xFu:
              if (nbCameraModelMotionCr >= 450.0)
              {
                {
                }
                nbCameraShot_AttackTuibi_Set(&nbCameraCurrent, v26);
              }
              else
              {
                {
                }
                nbCameraShot_InvokeTargetNear_Set(&nbCameraCurrent, v26);
              }
              return;
            case 0x10u:
              effBTLModelGroupPopPosition(v27);
              if (nbCameraModelMotionCr >= 450.0)
              {
                {
LABEL_233:
                }
LABEL_235:
                nbCameraShot_InvokeTargetReverse_Set2(&nbCameraCurrent, v26);
              }
              else
              {
                {
                }
                nbCameraShot_InvokeTargetNearReverse_Set(&nbCameraCurrent, v26);
              }
              break;
            case 0x12u:
LABEL_127:
              nbCameraShot_AllParty_Set(&nbCameraCurrent, v26);
              return;
            case 0x13u:
LABEL_134:
              goto LABEL_43;
            default:
              return;
          }
        }
        else
        {
          switch (nbCameraSkillNBSInfo->shot_23)
          {
            case 1u:
              nbCameraShot_InvokeTargetParty_Set2(&nbCameraCurrent, v26);
              break;
            case 2u:
LABEL_141:
              nbCameraShot_TargetParty_Set2(&nbCameraCurrent, &nbCameraSkillNBSInfo);
              break;
            case 5u:
              goto LABEL_150;
            case 6u:
              goto LABEL_157;
            case 0x12u:
              goto LABEL_127;
            case 0x13u:
              goto LABEL_134;
            default:
              return;
          }
        }
      }
    }
  }
}

// 0x168a420
void nbCameraState_SkillEnd_Calc(void) {
  ;
}

// 0x168a410
void nbCameraState_SkillEnd_Init(void) {
  ;
}

// 0x16887f0
void nbCameraState_SkillStart_Init(void) {
  struct nbCameraSkillPtr_t_array *tbl;
  u32 ID;
  s32 v8;

  ID = effBTLSkillGetID();
  nbCamera_SkillInfo_Set(&nbCameraSkillNBSInfo, tbl->m_Items[ID]);
  v8 = effBTLSkillGetID();
  if (!Get(v8, 0)->hatudo)
  {
    nbCameraSetState(7u);
  }
}

// 0x16800a0
void nbCamera_SkillInfo_Set(nbCameraSkillInfo_t **pInfo, nbCameraSkillPtr_t *pPtr) {
  char State;
  u32 v6;
  u32 TargetParty;
  u32 v8;
  u64 *v10;
  u32 v12;
  u32 ptr_shot_23;
  nbCameraSkillInfo_t_o *v14;
  nbMainProcessData_t_o *MainProcessData;
  s64 *v19;
  nbCameraSkillInfo_t_o *v22;
  u32 v23;
  s64 ptr_angleH;
  nbCameraSkillInfo_t_o *v26;
  struct System_Single_array *v27;
  char *v29;
  f32 *v30;
  s64 ptr_angleW;
  nbCameraSkillInfo_t_o *v33;
  struct System_Single_array *v34;
  u32 v37;
  nbCameraSkillInfo_t_o *v38;
  u32 v39;
  u32 v41;
  struct System_Single_array *nbCameraSkill_Ptr_WA;
  f32 *v44;
  u32 RandIntA;
  struct System_Single_array *v47;
  f32 v49;
  u32 v50;
  struct System_Single_array *v52;
  char v55;
  u32 v56;
  s32 v57;
  u32 v59;
  struct System_Single_array *v61;
  u32 v63;
  char v64;
  struct System_Single_array *v66;
  s64 v67;
  f32 angleH;
  struct System_Single_array *v72;
  nbCameraSkillInfo_t_o *v75;
  struct System_Single_array *v76;
  f32 angleW;
  struct System_Single_array *v80;
  f32 v83;
  struct System_Single_array *v84;
  u32 v87;
  nbCameraSkillInfo_t_o *v89;
  struct System_Single_array *v90;
  f32 v92;
  struct System_Single_array *v94;
  struct System_Single_array *v97;
  nbCameraSkillInfo_t_o *v100;
  struct System_Single_array *nbCameraSkill_Ptr_H;
  s64 ptr_H;
  struct System_Single_array *nbCameraSkill_Ptr_W;
  s64 ptr_W;
  struct System_Single_array *v107;
  f32 Sphere;
  f32 v111;
  struct System_Single_array *v112;
  f32 v115;
  f32 v117;
  struct System_Single_array *v118;
  f32 v121;
  struct System_Single_array *v122;
  s64 *v124;
  nbCameraSkillInfo_t_o *v128;
  struct System_Single_array *v129;
  u32 v131;
  u64 *v133;
  f32 v135;
  struct System_Single_array *v136;
  f32 v139;
  struct System_Single_array *v140;
  s64 *v142;
  struct System_Single_array *v143;
  f32 v146;
  struct System_Single_array *v147;
  u32 v149;
  u32 v150;
  u32 v152;
  struct System_Single_array *nbCameraSkill_Ptr_HA;
  u32 v156;
  u32 v157;
  u32 v159;
  char v160;
  char v162;
  char v165;
  struct System_Single_array *v166;
  char v168;
  struct System_Single_array *v169;
  char v171;
  struct System_Single_array *v172;
  struct System_Single_array *v175;
  char v177;
  struct System_Single_array *v178;
  struct System_Single_array *v180;
  struct System_Single_array *v183;
  struct System_Single_array *v186;
  u32 v188;
  u32 v189;
  struct System_Single_array *v192;
  struct System_Single_array *v195;
  u32 ptr_shot_1;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  State = effBTLSkillGetState();
  pFormation = effBTLSkillGetInvokeFormation(0);
  v6 = effBTLSkillGetInvokeParty();
  TargetParty = effBTLSkillGetTargetParty();
  (*pInfo)->ptr_1 = pPtr->ptr_shot_1;
  (*pInfo)->ptr_23 = pPtr->ptr_shot_23;
  ptr_shot_1 = pPtr->ptr_shot_1;
  v8 = TargetParty;
  v10 = sub_8D3950(uint, &ptr_shot_1);
  Write_2930400("pPtr->ptr_shot_1:{0:D}\n", v10);
  v12 = pPtr->ptr_shot_1;
  switch (v12)
  {
    case 0u:
    case 6u:
    case 9u:
      v12 = 0;
      break;
    case 5u:
    case 7u:
      if ((pFormation->stat & 0x100) != 0)
        v12 = 2;
      else
        v12 = 10;
      break;
    case 8u:
      v12 = 8;
      break;
    default:
      break;
  }
  (*pInfo)->shot_1 = v12;
  ptr_shot_23 = pPtr->ptr_shot_23;
  switch (ptr_shot_23)
  {
    case 0u:
      v14 = *pInfo;
      if ((DDS3EFFECT_RAND_I() & 1) != 0)
        ptr_shot_23 = 1;
      else
        ptr_shot_23 = 2;
      break;
    case 8u:
      v14 = *pInfo;
      if ((pFormation->stat & 0x100) != 0)
        ptr_shot_23 = 1;
      else
        ptr_shot_23 = 7;
      break;
    case 9u:
    case 0xBu:
      v14 = *pInfo;
      if ((pFormation->stat & 0x100) != 0)
        ptr_shot_23 = 15;
      else
        ptr_shot_23 = 16;
      break;
    case 0xAu:
      v14 = *pInfo;
      ptr_shot_23 = 5;
      break;
    case 0xCu:
      v14 = *pInfo;
      ptr_shot_23 = 1;
      break;
    case 0xDu:
      v14 = *pInfo;
      ptr_shot_23 = 13;
      break;
    case 0xEu:
      v14 = *pInfo;
      ptr_shot_23 = 14;
      break;
    default:
      v14 = *pInfo;
      break;
  }
  v14->shot_23 = ptr_shot_23;
  if ((effBTLModelGetBadStatus(&pFormation) & 0x40) != 0)
    goto LABEL_49;
LABEL_36:
  if ((State & 0xC) != 0)
  {
    MainProcessData = nbGetMainProcessData();
    else if (effBTLSkillGetID() != 152)
    {
      goto LABEL_59;
    }
    if (MainProcessData->encno == 1024)
    {
      v19 = &"nbCamera: PEIRU(0x400) JIBAKU!!!\n";
LABEL_68:
      Write(*v19, 0);
      goto LABEL_69;
    }
LABEL_59:
    v22 = *pInfo;
    if (v6 == v8)
    {
      v23 = 20;
    }
    else
    {
      if (v22->shot_23 != 2)
        goto LABEL_64;
      v23 = 1;
    }
    v22->ptr_23 = v23;
    (*pInfo)->shot_23 = v23;
LABEL_64:
    v19 = &"nbCamera: HANSYA or KYUSYUU!!!\n";
    goto LABEL_68;
  }
LABEL_69:
  ptr_angleH = pPtr->ptr_angleH;
  switch (ptr_angleH)
  {
    case 0:
      v149 = DDS3EFFECT_RAND_I();
      v26 = *pInfo;
      v150 = v149 % 7;
      v152 = v150 + 1;
      v29 = nbCameraSkill_Ptr_HA + 4 * v152;
      goto LABEL_76;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      v26 = *pInfo;
      v27 = nbCameraSkill_Ptr_HA;
      if (ptr_angleH >= LODWORD(v27->max_length))
        goto LABEL_74;
      goto LABEL_75;
    case 9:
        goto LABEL_316;
      goto LABEL_419;
    case 10:
      v156 = DDS3EFFECT_RAND_I();
      v26 = *pInfo;
      v157 = v156 % 3;
      v27 = nbCameraSkill_Ptr_HA;
      ptr_angleH = v157 + 5;
      if (ptr_angleH < LODWORD(v27->max_length))
        goto LABEL_75;
      goto LABEL_74;
    case 11:
      v159 = DDS3EFFECT_RAND_I() & 1;
      v160 = DDS3EFFECT_RAND_I();
      v26 = *pInfo;
      if ((v160 & 1) != 0)
      {
        v27 = nbCameraSkill_Ptr_HA;
        ptr_angleH = v159 | 6;
        if (ptr_angleH < LODWORD(v27->max_length))
        {
LABEL_75:
          v29 = v27 + 4 * ptr_angleH;
LABEL_76:
          v30 = (v29 + 32);
          goto LABEL_77;
        }
      }
      else
      {
        v27 = nbCameraSkill_Ptr_HA;
        ptr_angleH = v159 | 2;
        if (ptr_angleH < LODWORD(v27->max_length))
          goto LABEL_75;
      }
      goto LABEL_74;
    case 12:
      v162 = DDS3EFFECT_RAND_I();
      v26 = *pInfo;
      if ((v162 & 1) == 0)
        goto LABEL_390;
      goto LABEL_344;
    case 13:
      v165 = DDS3EFFECT_RAND_I();
      v26 = *pInfo;
      if ((v165 & 1) == 0)
        goto LABEL_364;
LABEL_344:
      v166 = nbCameraSkill_Ptr_HA;
      v30 = &v166->m_Items[7];
      goto LABEL_77;
    case 14:
      v168 = DDS3EFFECT_RAND_I();
      v26 = *pInfo;
      if ((v168 & 1) == 0)
        goto LABEL_364;
      v169 = nbCameraSkill_Ptr_HA;
      v30 = &v169->m_Items[5];
      goto LABEL_77;
    case 15:
      v171 = DDS3EFFECT_RAND_I();
      v26 = *pInfo;
      if ((v171 & 1) != 0)
        goto LABEL_384;
LABEL_364:
      v172 = nbCameraSkill_Ptr_HA;
      v30 = &v172->m_Items[1];
      goto LABEL_77;
    case 16:
      if ((DDS3EFFECT_RAND_I() & 1) != 0)
      {
        {
LABEL_316:
        }
LABEL_419:
        v188 = DDS3EFFECT_RAND_I();
        v26 = *pInfo;
        v189 = v188 % 3;
        v27 = nbCameraSkill_Ptr_HA;
        ptr_angleH = v189 + 1;
        if (ptr_angleH < LODWORD(v27->max_length))
          goto LABEL_75;
LABEL_74:
      }
      v26 = *pInfo;
      v175 = nbCameraSkill_Ptr_HA;
      v30 = &v175->m_Items[6];
LABEL_77:
      v26->angleH = *v30;
LABEL_78:
      ptr_angleW = pPtr->ptr_angleW;
      switch (ptr_angleW)
      {
        case 0:
          v37 = DDS3EFFECT_RAND_I();
          v38 = *pInfo;
          v39 = v37 % 7;
          v41 = v39 + 1;
          v44 = (nbCameraSkill_Ptr_WA + 4 * v41);
          goto LABEL_156;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
          v33 = *pInfo;
          v34 = nbCameraSkill_Ptr_WA;
          if (ptr_angleW >= LODWORD(v34->max_length))
            goto LABEL_83;
          goto LABEL_84;
        case 9:
          RandIntA = dds3GetRandIntA(3u, "");
          if (RandIntA == 2)
            goto LABEL_140;
          if (RandIntA == 1)
          {
            v38 = *pInfo;
            v192 = nbCameraSkill_Ptr_WA;
            v49 = v192->m_Items[2];
          }
          else
          {
            if (RandIntA)
              goto LABEL_158;
            v38 = *pInfo;
            v47 = nbCameraSkill_Ptr_WA;
            v49 = v47->m_Items[1];
          }
          goto LABEL_157;
        case 10:
          v50 = dds3GetRandIntA(3u, "");
          if (v50 == 2)
            goto LABEL_402;
          if (v50 == 1)
          {
            v38 = *pInfo;
            v195 = nbCameraSkill_Ptr_WA;
            v49 = v195->m_Items[6];
          }
          else
          {
            if (v50)
              goto LABEL_158;
            v38 = *pInfo;
            v52 = nbCameraSkill_Ptr_WA;
            v49 = v52->m_Items[5];
          }
          goto LABEL_157;
        case 11:
          v55 = DDS3EFFECT_RAND_I();
          v56 = dds3GetRandIntA(3u, "");
          if (v56 == 2)
            goto LABEL_396;
          v57 = v55 & 1;
          if (v56 == 1)
          {
            v33 = *pInfo;
            v34 = nbCameraSkill_Ptr_WA;
            ptr_angleW = v57 | 6u;
            if (ptr_angleW < LODWORD(v34->max_length))
            {
LABEL_84:
              v33->angleW = v34->m_Items[ptr_angleW];
                goto LABEL_159;
              goto LABEL_85;
            }
LABEL_83:
          }
          if (!v56)
          {
            v33 = *pInfo;
            v34 = nbCameraSkill_Ptr_WA;
            ptr_angleW = v57 | 2u;
            if (ptr_angleW < LODWORD(v34->max_length))
              goto LABEL_84;
            goto LABEL_83;
          }
          goto LABEL_158;
        case 12:
          v59 = dds3GetRandIntA(3u, "");
          if (v59 == 2)
          {
LABEL_396:
            v38 = *pInfo;
            v183 = nbCameraSkill_Ptr_WA;
            v49 = v183->m_Items[4];
          }
          else if (v59 == 1)
          {
LABEL_402:
            v38 = *pInfo;
            v186 = nbCameraSkill_Ptr_WA;
            v49 = v186->m_Items[7];
          }
          else
          {
            if (v59)
              goto LABEL_158;
LABEL_140:
            v38 = *pInfo;
            v61 = nbCameraSkill_Ptr_WA;
            v49 = v61->m_Items[3];
          }
          goto LABEL_157;
        case 13:
          v63 = DDS3EFFECT_RAND_I() & 1;
          v64 = DDS3EFFECT_RAND_I();
          v38 = *pInfo;
          if ((v64 & 1) != 0)
          {
            v66 = nbCameraSkill_Ptr_WA;
            v67 = v63 | 2;
            if (v67 >= LODWORD(v66->max_length))
            {
LABEL_154:
            }
          }
          else
          {
            v66 = nbCameraSkill_Ptr_WA;
            v67 = v63 | 6;
            if (v67 >= LODWORD(v66->max_length))
              goto LABEL_154;
          }
          v44 = (v66 + 4 * v67);
LABEL_156:
          v49 = v44[8];
LABEL_157:
          v38->angleW = v49;
LABEL_158:
            goto LABEL_159;
LABEL_85:
LABEL_159:
          if (effBTLModelGroupGetSphere(v8) >= 700.0)
          {
            angleH = (*pInfo)->angleH;
            v72 = nbCameraSkill_Ptr_HA;
            if (angleH < v72->m_Items[6])
            {
              Write("PartyWidth 14m over H!!!\n", 0);
              v75 = *pInfo;
              v76 = nbCameraSkill_Ptr_HA;
              v75->angleH = v76->m_Items[6];
            }
            angleW = (*pInfo)->angleW;
            v80 = nbCameraSkill_Ptr_WA;
            if (angleW > v80->m_Items[3])
              goto LABEL_443;
            v83 = (*pInfo)->angleW;
            v84 = nbCameraSkill_Ptr_WA;
            if (v83 < v84->m_Items[7])
            {
LABEL_443:
              Write("PartyWidth 14m over W!!!\n", 0);
              v87 = dds3GetRandIntA(3u, "");
              switch (v87)
              {
                case 2u:
                  v89 = *pInfo;
                  v94 = nbCameraSkill_Ptr_WA;
                  v92 = v94->m_Items[4];
                  goto LABEL_214;
                case 1u:
                  v89 = *pInfo;
                  v97 = nbCameraSkill_Ptr_WA;
                  v92 = v97->m_Items[7];
                  goto LABEL_214;
                case 0u:
                  v89 = *pInfo;
                  v90 = nbCameraSkill_Ptr_WA;
                  v92 = v90->m_Items[3];
LABEL_214:
                  v89->angleW = v92;
                  break;
              }
            }
          }
          v100 = *pInfo;
          ptr_H = pPtr->ptr_H;
          v100->HeightMin = nbCameraSkill_Ptr_H->m_Items[ptr_H];
          ptr_W = pPtr->ptr_W;
          (*pInfo)->WidthMin = nbCameraSkill_Ptr_W->m_Items[ptr_W];
          v107 = nbCameraSkill_Ptr_H;
          if ((*pInfo)->HeightMin <= v107->m_Items[0])
          {
            Sphere = effBTLModelGroupGetSphere(v8);
            SDF_VU0__STOREVECTOR(&p);
            if (Sphere <= 600.0)
              goto LABEL_234;
            v111 = (*pInfo)->angleH;
            v112 = nbCameraSkill_Ptr_HA;
            if (v111 >= v112->m_Items[3])
            {
              v124 = &"PARTY : pInfo->angleH width 12m over\n";
            }
            else
            {
LABEL_234:
              sub_854710(&p, 1u);
              if (v115 <= -200.0)
                goto LABEL_247;
              v117 = (*pInfo)->angleH;
              v118 = nbCameraSkill_Ptr_HA;
              if (v117 >= v118->m_Items[3])
              {
                v124 = &"PARTY : pInfo->angleH height 1m under\n";
              }
              else
              {
LABEL_247:
                if (Sphere <= 250.0)
                  goto LABEL_267;
                v121 = (*pInfo)->angleH;
                v122 = nbCameraSkill_Ptr_HA;
                if (v121 < v122->m_Items[3])
                  goto LABEL_267;
                v124 = &"PARTY : pInfo->angleH height 2m under or width 5m over\n";
              }
            }
            Write(*v124, 0);
            v128 = *pInfo;
            v129 = nbCameraSkill_Ptr_HA;
            v128->angleH = v129->m_Items[4];
LABEL_267:
            sub_854710(&p, 1u);
            ptr_shot_1 = v131;
            v133 = sub_8D3950(f32, &ptr_shot_1);
            Write_2930400("PARTY : height {0:f} \n", v133);
          }
          v135 = (*pInfo)->angleH;
          if (v8 == 256)
          {
            v136 = nbCameraSkill_Ptr_HA;
            if (v135 <= v136->m_Items[6])
            {
              v139 = (*pInfo)->angleW;
              v140 = nbCameraSkill_Ptr_WA;
              if (v139 >= v140->m_Items[2])
              {
                v142 = &"PLAYER : pInfo->angleW over !!!!\n";
LABEL_304:
                Write(*v142, 0);
                (*pInfo)->angleW = -(*pInfo)->angleW;
              }
            }
          }
          else
          {
            v143 = nbCameraSkill_Ptr_HA;
            if (v135 <= v143->m_Items[6])
            {
              v146 = (*pInfo)->angleW;
              v147 = nbCameraSkill_Ptr_WA;
              if (v146 <= v147->m_Items[6])
              {
                v142 = &"ENEMY : pInfo->angleW over !!!!\n";
                goto LABEL_304;
              }
            }
          }
          return;
        default:
          goto LABEL_158;
      }
    case 17:
      v177 = DDS3EFFECT_RAND_I();
      v26 = *pInfo;
      if ((v177 & 1) != 0)
      {
LABEL_390:
        v180 = nbCameraSkill_Ptr_HA;
        v30 = &v180->m_Items[3];
      }
      else
      {
LABEL_384:
        v178 = nbCameraSkill_Ptr_HA;
        v30 = &v178->m_Items[2];
      }
      goto LABEL_77;
    default:
      goto LABEL_78;
  }
}
