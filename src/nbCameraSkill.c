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
    effBTLModelAllShow();
    effBTLModelAllPopRotate();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeParty();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    nbGetMainProcessData();
    effBTLModelGetHeight(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    sdfAtan(0);
    SDF_VU0__NORMALIZE();
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
}

// 0x16862b0
void nbCameraShot_All_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelAllShow();
    nbGetMainProcessData();
    effBTLModelGetHeight(0);
    nbGetEnemyInterval();
    nbGetPartyDistance();
    sdfAtan(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGroupGetSphere(0);
}

// 0x1686600
void nbCameraShot_All_Set3(nbCamera_t **pNbCamera, sdfVector4_t pTarget) {
    effBTLModelAllShow();
    nbGetMainProcessData();
    effBTLModelGetHeight(0);
    nbGetEnemyInterval();
    sdfAtan(0);
    nbGetPartyDistance();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGroupGetSphere(0);
}

// 0x16877f0
void nbCameraShot_AttackTuibiReverse_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelTargetGroupHide();
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SetRotateMatrixY(0);
    SDF_VU0__NORMALIZE();
    SDF_VU0__APPLYMATRIX();
    sdfFabs(0);
    sdfSin(0);
    effBTLModelGetHeight(0);
    sdfAtan(0);
}

// 0x16873a0
void nbCameraShot_AttackTuibi_Set(nbCamera_t **pNbCamera) {
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetParty();
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    effBTLModelTargetShow();
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SetRotateMatrixY(0);
    SDF_VU0__NORMALIZE();
    SDF_VU0__APPLYMATRIX();
    sdfFabs(0);
    sdfSin(0);
    effBTLModelGetHeight(0);
    sdfAtan(0);
}

// 0x166c280
void nbCameraShot_GroundCollision(nbCamera_t **pNbCamera) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__SETVECTOR_Y(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    sdfSqrt(0);
}

// 0x1685d20
void nbCameraShot_InvokeParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelAllHide();
    effBTLModelInvokePartyShow();
    effBTLSkillGetInvokeParty();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    sdfAtan(0);
    sdfSqrt(0);
    effBTLModelGroupGetDirection(0, 0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
    SetRotateMatrixXYZ(0);
}

// 0x1684b70
void nbCameraShot_InvokeTargetNearReverse_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelAllShow();
    effBTLModelTargetGroupHide();
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__INTERPOLATE(0);
    effBTLModelGetHeight(0);
    SDF_VU0__NORMALIZE();
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    SDF_VU0__APPLYMATRIX();
    sdfAtan(0);
    nbCameraBoss_CheckRotate(0);
    effBTLModelLook(0, 0);
}

// 0x1684770
void nbCameraShot_InvokeTargetNear_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__NORMALIZE();
    SetRotateMatrixX(0);
    SetRotateMatrixY_B(0);
    MultMatrixRevNoArg();
    SDF_VU0__APPLYMATRIX();
    sdfAtan(0);
    nbCameraBoss_CheckRotate(0);
    effBTLModelLook(0, 0);
}

// 0x1685650
void nbCameraShot_InvokeTargetPartyTop2_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetParty();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    nbGetMainProcessData();
    effBTLModelGetHeight(0);
    DDS3EFFECT_RAND_I();
    nbCameraShot_InvokeTargetParty_Set2(0, 0);
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    nbCameraBoss_CheckRotate(0);
    effBTLModelLook(0, 0);
    effBTLModelGetPosition(0, 0);
    effBTLSkillGetTargetNumber();
    effBTLSkillGetTargetFormation(0);
    effBTLModelLook2(0, 0, 0);
}

// 0x1684fa0
void nbCameraShot_InvokeTargetPartyTop_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetParty();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetHeight(0);
    nbGetMainProcessData();
    DDS3EFFECT_RAND_I();
    nbCameraShot_InvokeTargetParty_Set2(0, 0);
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    nbCameraBoss_CheckRotate(0);
    effBTLModelLook(0, 0);
    effBTLModelGetPosition(0, 0);
    effBTLSkillGetTargetNumber();
    effBTLSkillGetTargetFormation(0);
    effBTLModelLook2(0, 0, 0);
}

// 0x1681fa0
void nbCameraShot_InvokeTargetParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelTargetPartyShow();
    effBTLModelInvokeGroupHide();
    nbGetMainProcessData();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetParty();
    nbCameraGetModelAllTable(0);
    effBTLSkillGetTargetNumber();
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetHeight(0);
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__GETLENGTH();
    sdfAtan(0);
    effBTLModelGetPosition(0, 0);
    effBTLModelSetPosition(0, 0);
    SDF_VU0__NORMALIZE();
    SetRotateMatrixY(0);
    SDF_VU0__APPLYMATRIX();
    nbCameraBoss_CheckRotate(0);
    effBTLModelLook(0, 0);
    effBTLModelLook2(0, 0, 0);
}

// 0x16842c0
void nbCameraShot_InvokeTargetReverse_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelAllShow();
    effBTLModelTargetGroupHide();
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeFormation(0);
    nbCameraGetModelAllTable(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    sdfAtan(0);
    SetRotateMatrixY(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__NORMALIZE();
    nbCameraBoss_CheckRotate(0);
    effBTLModelLook2(0, 0, 0);
    effBTLModelLook(0, 0);
}

// 0x1683e00
void nbCameraShot_InvokeTarget_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelTargetPartyShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeFormation(0);
    nbCameraGetModelAllTable(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    sdfAtan(0);
    SetRotateMatrixY(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__NORMALIZE();
    nbCameraBoss_CheckRotate(0);
    effBTLModelLook(0, 0);
    effBTLModelLook2(0, 0, 0);
}

// 0x1682890
void nbCameraShot_Invoke_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetRadius(0);
    sdfAtan(0);
    effBTLModelGetDirection(0, 0);
    SetRotateMatrixXYZ(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
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
    effBTLModelAllHide();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetParty();
    sdfAtan(0);
    effBTLSkillGetTargetNumber();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    EulerAngleAxisY();
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    sdfAtan2(0, 0);
    DDS3EFFECT_RAND_I();
    nbCameraAnim_RotateSet(0, 0, 0, 0);
    SetRotateMatrixXYZ(0);
    SDF_VU0__APPLYMATRIX();
}

// 0x1683cd0
void nbCameraShot_PullOne_Calc(nbCamera_t **pNbCamera, f32 rate) {
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    nbCameraShot_GroundCollision(0);
}

// 0x1683a50
void nbCameraShot_PullOne_Init(nbCamera_t **pNbCamera) {
    effBTLModelAllHide();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    sdfAtan(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    EulerAngleAxisY();
    SetRotateMatrixXYZ(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
}

// 0x16818f0
void nbCameraShot_TargetParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelAllHide();
    effBTLModelTargetPartyShow();
    effBTLSkillGetTargetParty();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLSkillGetTargetNumber();
    sdfAtan(0);
    effBTLModelGroupGetDirection(0, 0);
    SetRotateMatrixXYZ(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    sdfSqrt(0);
    SetRotateMatrixY(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
}

// 0x1682c40
void nbCameraShot_Target_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLModelAllHide();
    effBTLModelTargetPartyShow();
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetRadius(0);
    sdfAtan(0);
    effBTLModelGetDirection(0, 0);
    SetRotateMatrixXYZ(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    sdfSqrt(0);
    SetRotateMatrixY(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
}

// 0x1686a30
void nbCameraState_Analyze_Calc(nbCamera_t **pNbCamera) {
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetID(0);
    effBTLModelInvokePartyHide();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
    sdfAtan(0);
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
    effBTLSkillGetInvokeFormation(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__NORMALIZE();
    sdfAtan(0);
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
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
}

// 0x168aa20
void nbCameraState_EnemyBad_Init(void) {
    nbGetMainProcessData();
    effBTLSkillSetFormationInfo(0, 0);
    effBTLModelAllPopPosition();
    effBTLModelAllPopRotate();
    effBTLModelAllHide();
    effBTLModelTargetPartyShow();
    nbCameraShot_TargetParty_Set2(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
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
    effBTLSkillGetInvokeFormation(0);
    effBTLModelCheckBossID(0);
    nbCameraBoss_Cut2_Run(0);
    effBTLSkillGetTargetNumber();
    nbCameraShot_InvokeTargetParty_Set2(0, 0);
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetParty();
    nbCameraShot_AttackTuibi_Set(0);
    effBTLModelGroupPopPosition(0);
    nbCameraShot_InvokeTargetReverse_Set2(0, 0);
    nbCameraShot_AttackTuibiReverse_Set(0);
    nbCameraShot_GroundCollision(0);
}

// 0x1687c00
void nbCameraState_SkillAttack_Init(void) {
    SetDrawFlag(0, 0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelCheckBossID(0);
    nbCameraBoss_Cut2_Init(0);
    effBTLModelAllPopPosition();
    effBTLSkillGetTargetNumber();
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetParty();
    DDS3EFFECT_RAND_I();
    nbCameraState_InvokeTarget_SearchSet();
    effBTLModelGroupGetSphere(0);
    nbCameraShot_InvokeTargetReverse_Set2(0, 0);
    bCameraShot_AttackInvokeTargetPartyNear_Set(0, 0);
    nbCameraBoss_CheckRotate(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelLook(0, 0);
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
    if (nbCameraBoss_Cut1_Run(&nbCameraCurrent))
      return;
  }
  if (!nbCameraHero_Cut1_Run(&nbCameraCurrent, &nbCameraSkillNBSInfo))
  {
    v7 = *(*(*(v6 + 184) + 80LL) + 16LL);
    if (v7 == 2)
    {
      if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
      nbCameraState_SkillAttack_Calc(v6);
    }
    else if (!v7)
    {
      if ((pFormation->stat & 0x100) != 0)
      {
        v12 = effBTLSkillGetInvokeFormation(0);
        nbCameraShot_One_Calc(&nbCameraCurrent, &v12);
      }
      else
      {
        if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
        nbCameraState_Cut1Enemy_Calc(&nbCameraCurrent, v4);
      }
      {
      }
      nbCameraShot_GroundCollision(&nbCameraCurrent, v4);
      return;
    }
  }
}

// 0x1688e80
void nbCameraState_SkillCut1_Init(void) {
  nbCameraSkillInfo_t_o **v4;
  u64 v6;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  else  SetDrawFlag(0x2000000u, 1u);
  effBTLModelAllPopRotate();
  effBTLModelAllPopPosition();
  pFormation = effBTLSkillGetInvokeFormation(0);
  if (!effBTLModelCheckBossID(&pFormation))
  if (!nbCameraBoss_Cut1_Init(&nbCameraCurrent))
  {
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
          if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
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
  else  if (!nbCameraBoss_Cut2_Run(&nbCameraCurrent))
  {
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
      if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
      nbCameraState_SkillAttack_Calc(v7);
    }
    {
      nbCameraShot_GroundCollision(&nbCameraCurrent);
      return;
    }
  }
}

// 0x16895a0
void nbCameraState_SkillCut2_Init(void) {
  struct nbCameraSkillPtr_t_array *tbl;
  u32 ID;
  nbCameraProcess_c *v10;
  struct nbCameraProcess_StaticFields *v11;
  nbCameraSkill_c *v13;
  nbCameraProcess_c *v16;
  struct nbCameraProcess_StaticFields *static_fields;
  f32 cr;
  f32 scl;
  u32 v24;
  u32 TargetParty;
  nbCameraSkillInfo_t_o **v26;
  u32 v27;
  u32 TargetNumber;
  struct nbCameraSkill_StaticFields *v29;
  u32 GroupNumber;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  ID = effBTLSkillGetID();
  nbCamera_SkillInfo_Set(&nbCameraSkillNBSInfo, tbl->m_Items[ID]);
  if (!effBTLSkillGetTargetNumber())
  {
    if (nbCameraSkillNBSInfo->shot_23 == 19)
    {
      nbCameraShot_Invoke_Set2(&nbCameraCurrent, &nbCameraSkillNBSInfo);
    }
    else
    {
      Write(StringLiteral_21203, 0);
      static_fields = v16->static_fields;
      static_fields->nbCameraCurrent->anim->rotate_f = 0;
      static_fields->nbCameraCurrent->anim->rotate_s = 0.0;
      static_fields->nbCameraCurrent->anim->distance_f = 0;
      static_fields->nbCameraCurrent->anim->distance_s = 0.0;
      nbCameraShot_All_Set(&nbCameraCurrent);
    }
    return;
  }
  pFormation = effBTLSkillGetInvokeFormation(0);
  v11 = v10->static_fields;
  v11->nbCameraCurrent->anim->rotate_f = 0;
  v11->nbCameraCurrent->anim->rotate_s = 0.0;
  v11->nbCameraCurrent->anim->distance_f = 0;
  v11->nbCameraCurrent->anim->distance_s = 0.0;
  else if (effBTLModelCheckBossID(&pFormation))
  {
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
            case 0x11u:
              nbCameraShot_All_Set2(&nbCameraCurrent, v26);
              return;
            case 0x12u:
            case 0x13u:
            case 0x14u:
            default:
              if (effBTLSkillGetTargetNumber() < 2)
              {
                GroupNumber = effBTLModelGetGroupNumber(v24);
                if (v24 != 512 || GroupNumber < 2)
                {
                  {
                  }
                  nbCameraShot_Target_Set2(&nbCameraCurrent, &nbCameraSkillNBSInfo);
                  return;
                }
              }
              else
              {
              }
          }
        }
        v27 = TargetParty;
        TargetNumber = effBTLSkillGetTargetNumber();
        if (TargetNumber < 2)
        {
          v29 = v13->static_fields;
          switch (v29->nbCameraSkillNBSInfo->shot_23)
          {
            case 1u:
              nbCameraShot_InvokeTarget_Set2(&nbCameraCurrent, v26);
              return;
            case 2u:
            case 0xDu:
            case 5u:
              nbCameraShot_InvokeTargetPartyTop_Set(&nbCameraCurrent, v26);
              return;
            case 6u:
              nbCameraShot_InvokeTargetPartyTop2_Set(&nbCameraCurrent, v26);
              return;
            case 7u:
            case 0xEu:
              nbCameraShot_InvokeTarget_Set2(&nbCameraCurrent, v26);
              nbCameraState_Analyze_Set(&nbCameraCurrent);
              return;
            case 0xFu:
              if (v29->nbCameraModelMotionCr >= 450.0)
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
                }
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
              nbCameraShot_AllParty_Set(&nbCameraCurrent, v26);
              return;
            case 0x13u:
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
              nbCameraShot_TargetParty_Set2(&nbCameraCurrent, &nbCameraSkillNBSInfo);
              break;
            case 5u:
            case 6u:
            case 0x12u:
            case 0x13u:
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
    effBTLSkillGetState();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetParty();
    DDS3EFFECT_RAND_I();
    effBTLModelGetBadStatus(0);
    nbGetMainProcessData();
    effBTLSkillGetID();
    dds3GetRandIntA(0, 0);
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
}
