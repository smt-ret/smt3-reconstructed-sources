#include "types.h"

typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBezier4PPart_t effBezier4PPart_t;
typedef struct nbCameraBoss_B4P_tag nbCameraBoss_B4P_tag;
typedef struct nbCameraSkillInfo_t nbCameraSkillInfo_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

struct nbCameraBoss_B4P_tag {
    effBezier4PPart_t *target;
    effBezier4PPart_t *eye;
};

static u32 nbCameraBoss_Bskagu_Cut1_Direction;
static sdfVector4_t Foru_E913_StartTarget;
static sdfVector4_t Foru_E913_StartDirection;
static sdfVector4_t Foru_E913_EndTarget;
static sdfVector4_t Foru_E913_EndDirection;
static s32 Foru_E913_Frame;
static nbCameraBoss_B4P_tag *nbCamera_MURET2_B4P;
static f32 nbCameraBoss_Sp_MURET2_Accele;
static effBezier4PPart_t *nbCamera_DOUTYO_B4P;
static f32 nbCameraBoss_BSALBI_E912_Rate;
static f32 nbCameraBoss_BSALBI_E912_Distance;
static sdfVector4_t Bsnet_E907_2_StartTarget;
static sdfVector4_t Bsnet_E907_2_StartDirection;
static f32 Bsnet_E907_2_StartDistance;
static sdfVector4_t Bsnet_E907_2_EndTarget;
static sdfVector4_t Bsnet_E907_2_EndDirection;
static f32 Bsnet_E907_2_EndDistance;
static f32 Bsnet_E907_2_Rate;
static sdfVector4_t BSARI_Cut1_Start;
static f32 BSARI_Cut1_Rate;
static s32 nbCameraBoss_BSARI_MASEHA_Frame;
static u32 nbCameraBoss_BSARI_MASEHA_Type;
static u32 nbCameraBoss_BSARI_SIMANO_Type;
static f32 nbCameraBoss_BSARI_SIMANO_Rate;
static sdfVector4_t Kagu_E909_StartTarget;
static sdfVector4_t Kagu_E909_StartDirection;
static f32 Kagu_E909_StartDistance;
static sdfVector4_t Kagu_E909_EndTarget;
static sdfVector4_t Kagu_E909_EndDirection;
static f32 Kagu_E909_EndDistance;
static s32 Kagu_E909_Frame;
static s32 Kagu_E909_Length;
static u32 nbCameraBoss_Kagu_MJINKO_Type;
static u8 nbCameraBoss_Pish_MUHENK_Type;
static s32 nbCameraBoss_Pish_MUHENK_Frame;
static s32 nbCameraBoss_BSBERU_E915_Frame;
static f32 nbCameraBoss_BSBERU_E915_Rate;
static u32 nbCameraBoss_BSLUSI_Type;
static s32 nbCameraHero_Cut_Frame;

u32 DDS3EFFECT_RAND_I(void);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
u8 Get(s32 id);
void Mult(void);
f32 SDF_DEGtoRAD(f32 n);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetRotateMatrixY(f32 aAngle);
void ToMatrix(void);
s32 dds3Bezier4PPartRun(effBezier4PPart_t **pPart, sdfVector4_t *pOut);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void effBTLModelAllHide(void);
void effBTLModelAllPopPosition(void);
void effBTLModelAllPopRotate(void);
void effBTLModelAllShow(void);
s32 effBTLModelCheckBossID(nbFormation_t **pFormation);
u32 effBTLModelGetBadStatus(nbFormation_t **pFormation);
f32 effBTLModelGetGroupMaxHeight(u32 group);
u32 effBTLModelGetGroupNumber(u32 group);
f32 effBTLModelGetHeight(nbFormation_t **pFormation);
u32 effBTLModelGetID(nbFormation_t **pFormation);
void effBTLModelGetMarkPosition2(nbFormation_t **pFormation, u32 mark);
void effBTLModelGetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos);
f32 effBTLModelGetRadius(nbFormation_t **pFormation);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
void effBTLModelGroupGetCenter(u32 group);
void effBTLModelGroupGetDirection(u32 group, sdfVector4_t *pDirection);
f32 effBTLModelGroupGetSphere(u32 group);
void effBTLModelInvokeGroupHide(void);
void effBTLModelInvokeShow(void);
void effBTLModelLook(nbFormation_t **pFormation, sdfVector4_t *pTargetPos);
void effBTLModelLook2(nbFormation_t **pFormation, sdfVector4_t *pTargetPos, f32 angle);
void effBTLModelSetPosition(nbFormation_t **pFormation, sdfVector4_t *pPos);
void effBTLModelTargetGroupHide(void);
void effBTLModelTargetPartyShow(void);
void effBTLPartGetPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pPos);
f32 effBTLPartGetScalePtr(nbFormation_t **pFormation);
u32 effBTLSkillGetID(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
u32 effBTLSkillGetInvokeParty(void);
u32 effBTLSkillGetState(void);
u32 effBTLSkillGetTargetBit(void);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
u32 effBTLSkillGetTargetNumber(void);
u32 effBTLSkillGetTargetParty(void);
void effBTLSkillSetFormationInfo(u32 InvokeID, u32 TargetBit);
void effBezier4PPart_t__Clear(effBezier4PPart_t *this);
bool evtBitCheck(s32 no);
s32 nbCameraBoss_BSALBI_InvokeTargetParty_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI1_Cut23_EX01_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI1_Cut23_EX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI1_Cut23_EX03_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI1_EP_IT_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI2_Cut1_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI2_Cut1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI2_Cut23_EX01_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI2_Cut23_EX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI2_Cut23_EX03_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI2_EP_IT_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI_Command_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI_Cut1_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI_Cut1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI_MASEHA_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARI_SIMANO_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSARUS_Command_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSBERU_Cut23_EX01_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSBERU_Cut23_EX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSBERU_EP_IT_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSKAGU_Command_Calc(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm);
s32 nbCameraBoss_BSKAGU_Command_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSKAGU_Cut23_EX01_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSKAGU_Cut23_EX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSKAGU_EP_IT_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSLUSI_Command_Calc(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm);
s32 nbCameraBoss_BSLUSI_Command_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSLUSI_Cut23_EX01_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSLUSI_Cut23_EX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSLUSI_EP_IT_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSMETA_Cut23_EX01_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSMETA_Cut23_EX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSMIZ_Command_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSNET1_Cut23_EX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSNET_EP_IT_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSONGY_Command_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSPISH_Cut23_EX01_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSPISH_Cut23_EX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSPISH_Cut23_EX03_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSPISH_EP_IT_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_BSSAMA_Command_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Baal_BAELNO_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Beru_HAENO1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Bskagu_Cut1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Bsnet_AISHOH_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Bsnet_Attack_Cut1_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Bsnet_Attack_Cut1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Bsnet_Attack_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Bsnet_Cut1_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Bsnet_Cut1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Bspish_Cut1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_CheckFix(void);
s32 nbCameraBoss_Cut2_Ptr_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
s32 nbCameraBoss_Foru_SIMON_Set(nbCamera_t **pNbCamera);
void nbCameraBoss_InvokeTarget_Set(nbCamera_t **pNbCamera, f32 rotate, f32 ratio);
s32 nbCameraBoss_Kagu_Attack_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Kagu_FLEACH_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Kagu_MJINKO_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Lusi_ASIKIK_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Lusi_Cut1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Lusi_OHNOOH_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Lusi_TWORLD_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Meta_METAT1_0_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Meta_METAT1_1_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Ongy_BUNSIN_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Pish_MUHENK_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Pish_MUHENK_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Pish_PRESS_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Samael_AKUI_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sp_DOUTYO_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sp_JAREIH_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sp_MURET2_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sp_MURET2_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sp_PSYSTL_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sukady_DAIJIS_Set(nbCamera_t **pNbCamera);
void nbCameraBoss_TargetInvoke_Set(nbCamera_t **pNbCamera, f32 rotate, f32 ratio);
s32 nbCameraDANTE_DCOMBO_KAGU_Set(s32 frame);
s32 nbCameraDANTE_DCOMBO_Set(s32 frame);
s32 nbCameraHero_Cut2_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraSetState(u16 state);
void nbCameraShot_All_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_All_Set3(nbCamera_t **pNbCamera, sdfVector4_t pTarget);
void nbCameraShot_AttackTuibi_Set(nbCamera_t **pNbCamera);
s32 nbCameraShot_BossEX02_Set(nbCamera_t **pNbCamera);
s32 nbCameraShot_BossTargetInvoke_Set(nbCamera_t **pNbCamera);
void nbCameraShot_GroundCollision(nbCamera_t **pNbCamera);
void nbCameraShot_InvokeTargetNear_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetPartyTop_Set(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTargetReverse_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_InvokeTarget_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_Invoke_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_PullOne_Calc(nbCamera_t **pNbCamera, f32 rate);
void nbCameraShot_PullOne_Init(nbCamera_t **pNbCamera);
void nbCameraShot_TargetParty_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraShot_Target_Set2(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo);
void nbCameraState_InvokeTarget_SearchSet(void);
void nbCameraState_SkillAttack_Init(void);
f32 nbGetEnemyInterval(void);
void nbGetFormRot(nbFormation_t **form);
nbMainProcessData_t *nbGetMainProcessData(void);
f32 nbGetPartyDistance(void);
void nbResetAllFormPosRot(void);
void nbSetFormRot(nbFormation_t **form, sdfVector4_t rot, bool look2);
f32 sdfAtan(f32 aX);
f32 sdfFabs(f32 c);
f32 sdfSin(f32 aRadius);

// 0xfbf230
void nbCameraBoss_BSALBI_E912_Run(void) {
  struct nbCamera_t_o *nbCameraCurrent;

  nbCameraCurrent->distance = (nbCameraBoss_BSALBI_E912_Distance * 0.65)
                                   + ((nbCameraBoss_BSALBI_E912_Distance * 0.35)
                                    * nbCameraBoss_BSALBI_E912_Rate);
  nbCameraBoss_BSALBI_E912_Rate = nbCameraBoss_BSALBI_E912_Rate * 0.95;
}

// 0xfbf0b0
void nbCameraBoss_BSALBI_E912_Set(void) {
  struct nbCamera_t_o *nbCameraCurrent;
  f32 Sphere;
  f32 v8;
  f32 v10;

  nbCameraSetState(0);
  Sphere = effBTLModelGroupGetSphere(0x200u);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
  effBTLModelGroupGetDirection(0x200u, &nbCameraCurrent->direction);
  sub_854710(&nbCameraCurrent->direction, 2u);
  sub_854930(&nbCameraCurrent->direction, 2u);
  v8 = sdfAtan(0.34907);
  v10 = v8;
  nbCameraBoss_BSALBI_E912_Rate = 1.0;
  nbCameraBoss_BSALBI_E912_Distance = Sphere / v10;
  nbCameraCurrent->distance = nbCameraBoss_BSALBI_E912_Distance;
  nbCameraCurrent->fovy = 0.69813;
}

// 0xfbf300
s32 nbCameraBoss_BSALBI_InvokeTargetParty_Set(nbCamera_t **pNbCamera) {
  u32 RandIntA;
  nbCamera_t_Fields *v6;
  nbCamera_t_Fields *v7;
  nbCamera_t_Fields *v8;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v10;

  effBTLModelAllShow();
  RandIntA = dds3GetRandIntA(2u, "");
  if (RandIntA == 1)
  {
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v10 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v10, 1u);
    v8 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
LABEL_16:
    sub_854930(v8, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
    return 1;
  }
  if (!RandIntA)
  {
    effBTLModelInvokeGroupHide();
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    v6 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(v6, 0);
    v7 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v7, 1u);
    v8 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    goto LABEL_16;
  }
  return 1;
}

// 0xfc9e10
s32 nbCameraBoss_BSARI1_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v7;
  nbCamera_t_Fields *v8;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  sub_854710(&TargetFormation->fields, 0);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v7 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v7, 1u);
  v8 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v8, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfca0f0
s32 nbCameraBoss_BSARI1_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v7;
  nbCamera_t_Fields *v8;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  sub_854710(&TargetFormation->fields, 0);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v7 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v7, 1u);
  v8 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v8, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfca3d0
s32 nbCameraBoss_BSARI1_Cut23_EX03_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 < v9)
    goto LABEL_14;
  if (dds3GetRandIntA(2u, "") <= 1)
  {
LABEL_14:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v11 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v11, 1u);
    v12 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v12, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfb8ff0
s32 nbCameraBoss_BSARI1_EP_IT_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;

  effBTLModelAllShow();
  switch (dds3GetRandIntA(4u, ""))
  {
    case 0u:
    case 1u:
    case 2u:
    case 3u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v5 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v5, 1u);
      v6 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v6, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      break;
    default:
      return 1;
  }
  return 1;
}

// 0xfc05e0
s32 nbCameraBoss_BSARI2_Cut1_Run(nbCamera_t **pNbCamera) {
  f32 BSARI_Cut1_Rate;
  nbCamera_t_o *v6;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  BSARI_Cut1_Rate = BSARI_Cut1_Rate * 0.985;
  effBTLModelGetMarkPosition2(&pFormation, 1u);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(BSARI_Cut1_Start);
  SDF_VU0__INTERPOLATE((BSARI_Cut1_Rate * 0.5) + 0.75, 0);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__SUBVECTOR();
  v6 = *pNbCamera;
  v6->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfc0400
s32 nbCameraBoss_BSARI2_Cut1_Set(nbCamera_t **pNbCamera) {
  u32 RandIntA;

  effBTLModelAllHide();
  effBTLModelInvokeShow();
  RandIntA = dds3GetRandIntA(2u, "");
  if (RandIntA == 1)
  {
    goto LABEL_18;
  }
  if (!RandIntA)
  {
LABEL_18:
    sub_854930(&BSARI_Cut1_Start, 0);
    sub_854930(&BSARI_Cut1_Start, 1u);
    sub_854930(&BSARI_Cut1_Start, 2u);
  }
  BSARI_Cut1_Rate = 1.0;
  return 1;
}

// 0xfca7d0
s32 nbCameraBoss_BSARI2_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  {
  }
  DDS3EFFECT_RAND_I();
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v11 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v11, 1u);
  v12 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v12, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfcacb0
s32 nbCameraBoss_BSARI2_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v7;
  nbCamera_t_Fields *v8;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  sub_854710(&TargetFormation->fields, 0);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v7 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v7, 1u);
  v8 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v8, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfcaf90
s32 nbCameraBoss_BSARI2_Cut23_EX03_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v4;
  nbCamera_t_Fields *v5;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v4 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v4, 1u);
  v5 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v5, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfcb110
s32 nbCameraBoss_BSARI2_EP_IT_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;

  effBTLModelAllShow();
  switch (dds3GetRandIntA(4u, ""))
  {
    case 0u:
    case 1u:
    case 2u:
    case 3u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v5 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v5, 1u);
      v6 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v6, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      break;
    default:
      return 1;
  }
  return 1;
}

// 0xfbfb10
s32 nbCameraBoss_BSARI_Command_Set(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  s64 orderindex;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v9;
  Il2CppClass **v11;
  struct nbFormation_t_array *form;
  s64 v13;
  u32 max_length;
  f32 v17;
  nbCamera_t_o *v18;
  nbCamera_t_Fields *p_fields;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v26;
  nbFormation_t_o *v27;

  v27 = 0;
  pFormation = 0;
  *&v26.x = 0;
  *&v26.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  *&v23.x = 0;
  *&v23.z = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    orderindex = MainProcessData->orderindex;
    if (orderindex == -1)
    {
      LODWORD(MainProcessData) = 0;
    }
    else
    {
      order = MainProcessData->order;
      party = MainProcessData->party;
      v9 = order->m_Items[orderindex];
      v11 = &party->obj.klass + v9;
      form = MainProcessData->form;
      v13 = SWORD1(v11[4]->_1.name);
      max_length = form->max_length;
      v27 = form->m_Items[v13];
      pFormation = form->m_Items[4];
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&p, 1u);
      sub_854930(&p, 1u);
      SDF_VU0__COPYVECTOR(&(*pNbCamera)->target, p, 0);
      effBTLModelGetSphereCenter(&v27);
      SDF_VU0__STOREVECTOR(&v24);
      effBTLModelGetHeight(&v27);
      sub_854930(&v24, 1u);
      SDF_VU0__LOADVECTOR(v24);
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v23);
      sub_854710(&v24, 0);
      sub_854710(&v23, 0);
      sub_854930(&v26, 0);
      sub_854710(&v24, 1u);
      sub_854710(&v23, 1u);
      sub_854930(&v26, 1u);
      sub_854710(&v24, 2u);
      sub_854710(&v23, 2u);
      sub_854930(&v26, 2u);
      sub_854710(&v26, 1u);
      if (v17 > -10.0)
        sub_854930(&v26, 1u);
      SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
      SDF_VU0__LOADVECTOR_B(v26);
      SDF_VU0__SUBVECTOR();
      v18 = *pNbCamera;
      v18->distance = SDF_VU0__GETLENGTH();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
      (*pNbCamera)->fovy = 0.69813;
      p_fields = &(*pNbCamera)->fields;
      effBTLModelLook(&v27, &p_fields->target);
      LODWORD(MainProcessData) = 1;
    }
  }
  return MainProcessData;
}

// 0xfc0200
s32 nbCameraBoss_BSARI_Cut1_Run(nbCamera_t **pNbCamera) {
  f32 BSARI_Cut1_Rate;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_o *v7;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  BSARI_Cut1_Rate = BSARI_Cut1_Rate * 0.9;
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(p_fields, 1u);
  sub_854930(p_fields, 1u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(BSARI_Cut1_Start);
  SDF_VU0__INTERPOLATE((BSARI_Cut1_Rate * 0.5) + 0.75, 0);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__COPYVECTOR_C_TO_A();
  SDF_VU0__SUBVECTOR();
  v7 = *pNbCamera;
  v7->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfbff10
s32 nbCameraBoss_BSARI_Cut1_Set(nbCamera_t **pNbCamera) {
  effBTLModelAllHide();
  effBTLModelInvokeShow();
  switch (dds3GetRandIntA(4u, ""))
  {
    case 0u:
      goto LABEL_25;
    case 1u:
      goto LABEL_25;
    case 2u:
      goto LABEL_25;
    case 3u:
LABEL_25:
      sub_854930(&BSARI_Cut1_Start, 0);
      sub_854930(&BSARI_Cut1_Start, 1u);
      sub_854930(&BSARI_Cut1_Start, 2u);
      break;
    default:
      break;
  }
  BSARI_Cut1_Rate = 1.0;
  return 1;
}

// 0xfc0820
s32 nbCameraBoss_BSARI_MASEHA_Run(nbCamera_t **pNbCamera) {
  u32 nbCameraBoss_BSARI_MASEHA_Type;
  s32 v8;
  s32 v9;
  s32 nbCameraBoss_BSARI_MASEHA_Frame;
  f32 v15;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v17;
  nbCamera_t_Fields *v18;
  UnityEngine_Vector4_o v21;
  UnityEngine_Vector4_o v22;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v22.x = 0;
  *&v22.z = 0;
  *&v21.x = 0;
  *&v21.z = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  effBTLModelAllShow();
  if (nbCameraBoss_BSARI_MASEHA_Type == 2)
    goto LABEL_27;
LABEL_12:
  if (nbCameraBoss_BSARI_MASEHA_Type == 1)
  {
    else
    {
      v9 = nbCameraBoss_BSARI_MASEHA_Frame;
      if (v9 > 134)
        goto LABEL_56;
    }
    sub_854930(&v22, 0);
    sub_854930(&v22, 1u);
    sub_854930(&v22, 2u);
    sub_854930(&v21, 0);
    sub_854930(&v21, 1u);
    sub_854930(&v21, 2u);
    SDF_VU0__LOADVECTOR(v22);
    SDF_VU0__LOADVECTOR_B(v21);
    v15 = v9 / 135.0;
    SDF_VU0__INTERPOLATE(v15);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
    sub_854930(&v22, 0);
    sub_854930(&v22, 1u);
    sub_854930(&v22, 2u);
    sub_854930(&v21, 0);
    sub_854930(&v21, 1u);
    goto LABEL_53;
  }
  if (!nbCameraBoss_BSARI_MASEHA_Type)
  {
    else
    {
      v8 = nbCameraBoss_BSARI_MASEHA_Frame;
      if (v8 > 29)
        goto LABEL_17;
    }
LABEL_56:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v17 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v17, 1u);
    v18 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v18, 2u);
    goto LABEL_57;
  }
LABEL_58:
  ++nbCameraBoss_BSARI_MASEHA_Frame;
  return 1;
}

// 0xfc0770
s32 nbCameraBoss_BSARI_MASEHA_Set(nbCamera_t **pNbCamera) {
  nbCameraBoss_BSARI_MASEHA_Frame = 0;
  nbCameraBoss_BSARI_MASEHA_Type = dds3GetRandIntA(3u, "");
  return 1;
}

// 0xfc13c0
s32 nbCameraBoss_BSARI_SIMANO_Run(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  u32 nbCameraBoss_BSARI_SIMANO_Type;
  f32 *p_x;
  f32 x;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;

  *&v16.x = 0;
  *&v16.z = 0;
  *&v15.x = 0;
  *&v15.z = 0;
  v4 = effBTLSkillGetInvokeFormation(0);
  effBTLModelAllShow();
  if (nbCameraBoss_BSARI_SIMANO_Type == 2)
    goto LABEL_15;
LABEL_12:
  if (nbCameraBoss_BSARI_SIMANO_Type <= 1)
    goto LABEL_15;
LABEL_16:
  sdfAtan(0.34907);
  x = v4->center.x;
  p_x = &v4->center.x;
  v17.x = x;
  v17.w = p_x[3];
  v17.y = p_x[1];
  v17.z = p_x[2];
  SDF_VU0__LOADVECTOR(v17);
  SDF_VU0__LOADVECTOR_B((*pNbCamera)->target, 0);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v15);
  sub_854710(p_x, 0);
  sub_854710(&v15, 0);
  sub_854930(&v16, 0);
  sub_854710(p_x, 1u);
  sub_854710(&v15, 1u);
  sub_854930(&v16, 1u);
  sub_854710(p_x, 2u);
  sub_854710(&v15, 2u);
  sub_854930(&v16, 2u);
  nbCameraBoss_BSARI_SIMANO_Rate = nbCameraBoss_BSARI_SIMANO_Rate * 0.95;
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR_B(v15);
  SDF_VU0__INTERPOLATE(nbCameraBoss_BSARI_SIMANO_Rate);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v16);
  SDF_VU0__INTERPOLATE(nbCameraBoss_BSARI_SIMANO_Rate);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfc1300
s32 nbCameraBoss_BSARI_SIMANO_Set(nbCamera_t **pNbCamera) {
  u32 RandIntA;

  RandIntA = dds3GetRandIntA(3u, "");
  nbCameraBoss_BSARI_SIMANO_Type = RandIntA;
  nbCameraBoss_BSARI_SIMANO_Rate = 1.0;
  return 1;
}

// 0xfbda10
s32 nbCameraBoss_BSARUS_Command_Set(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  s32 v5;
  s64 orderindex;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v10;
  struct nbFormation_t_array *form;
  s64 formindex;
  f32 v15;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v18;
  UnityEngine_Vector4_o p;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v18.x = 0;
  *&v18.z = 0;
  MainProcessData = nbGetMainProcessData();
  v5 = MainProcessData;
  if (MainProcessData)
  {
    orderindex = MainProcessData->orderindex;
    if (orderindex == -1)
    {
      return 0;
    }
    else
    {
      order = MainProcessData->order;
      party = MainProcessData->party;
      v10 = order->m_Items[orderindex];
      form = MainProcessData->form;
      formindex = party->m_Items[v10]->formindex;
      pFormation = form->m_Items[formindex];
      effBTLModelGroupGetSphere(0x200u);
      SDF_VU0__STOREVECTOR(&p);
      v5 = 1;
      sub_854930(&p, 1u);
      SDF_VU0__COPYVECTOR(&(*pNbCamera)->target, p, 0);
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&v18);
      effBTLModelGetHeight(&pFormation);
      sub_854930(&v18, 1u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__LOADVECTOR_B(v18);
      SDF_VU0__SUBVECTOR();
      v15 = SDF_VU0__GETLENGTH();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
      (*pNbCamera)->distance = v15 + 500.0;
      (*pNbCamera)->fovy = 0.69813;
      effBTLModelLook(&pFormation, &(*pNbCamera)->target, 0);
    }
  }
  return v5;
}

// 0xfceb50
s32 nbCameraBoss_BSBERU_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 >= v9)
  {
    if (dds3GetRandIntA(2u, "") <= 1)
      goto LABEL_19;
  }
  else
  {
    if (dds3GetRandIntA(2u, "") <= 1)
    {
LABEL_19:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v11 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v11, 1u);
      v12 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v12, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
    }
  }
  return 1;
}

// 0xfcf060
s32 nbCameraBoss_BSBERU_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 >= v9)
  {
    if (dds3GetRandIntA(2u, "") <= 1)
      goto LABEL_19;
  }
  else
  {
    if (dds3GetRandIntA(2u, "") <= 1)
    {
LABEL_19:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v11 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v11, 1u);
      v12 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v12, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
    }
  }
  return 1;
}

// 0xfc57b0
void nbCameraBoss_BSBERU_E915_0_Set(void) {
  struct nbCamera_t_o *nbCameraCurrent;
  s32 nbCameraBoss_BSBERU_E915_Frame;
  f32 v7;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;

  *&v9.x = 0;
  *&v9.z = 0;
  *&v8.x = 0;
  *&v8.z = 0;
  effBTLModelAllShow();
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  SDF_VU0__LOADVECTOR(v9);
  SDF_VU0__LOADVECTOR_B(v8);
  v7 = nbCameraBoss_BSBERU_E915_Frame / 200.0;
  SDF_VU0__INTERPOLATE(v7);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  SDF_VU0__LOADVECTOR(v9);
  SDF_VU0__LOADVECTOR_B(v8);
  SDF_VU0__INTERPOLATE(v7);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
  *&nbCameraCurrent->distance = 0x3F32B8C23F800000LL;
  ++nbCameraBoss_BSBERU_E915_Frame;
}

// 0xfc5a50
void nbCameraBoss_BSBERU_E915_1_Set(void) {
  struct nbCamera_t_o *nbCameraCurrent;

  sub_854930(&nbCameraCurrent->direction, 0);
  sub_854930(&nbCameraCurrent->direction, 1u);
  sub_854930(&nbCameraCurrent->direction, 2u);
  sub_854710(&nbCameraCurrent->direction, 0);
  sub_854930(&nbCameraCurrent->fields, 0);
  sub_854710(&nbCameraCurrent->direction, 1u);
  sub_854930(&nbCameraCurrent->fields, 1u);
  sub_854710(&nbCameraCurrent->direction, 2u);
  sub_854930(&nbCameraCurrent->fields, 2u);
  *&nbCameraCurrent->distance = 0x3F32B8C23F800000LL;
}

// 0xfc5bb0
void nbCameraBoss_BSBERU_E915_2_Set(void) {
  struct nbCamera_t_o *nbCameraCurrent;
  f32 nbCameraBoss_BSBERU_E915_Rate;
  s32 nbCameraBoss_BSBERU_E915_Frame;
  f32 v8;
  UnityEngine_Vector4_o v9;
  UnityEngine_Vector4_o v10;

  *&v10.x = 0;
  *&v10.z = 0;
  *&v9.x = 0;
  *&v9.z = 0;
  nbCameraBoss_BSBERU_E915_Rate = nbCameraBoss_BSBERU_E915_Rate * 0.99;
  sub_854930(&v10, 0);
  sub_854930(&v10, 1u);
  sub_854930(&v10, 2u);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  SDF_VU0__LOADVECTOR(v10);
  SDF_VU0__LOADVECTOR_B(v9);
  v8 = nbCameraBoss_BSBERU_E915_Rate * (nbCameraBoss_BSBERU_E915_Frame / 30.0);
  SDF_VU0__INTERPOLATE(v8);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
  sub_854930(&v10, 0);
  sub_854930(&v10, 1u);
  sub_854930(&v10, 2u);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  SDF_VU0__LOADVECTOR(v10);
  SDF_VU0__LOADVECTOR_B(v9);
  SDF_VU0__INTERPOLATE(v8);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
  *&nbCameraCurrent->distance = 0x3F32B8C23F800000LL;
  ++nbCameraBoss_BSBERU_E915_Frame;
}

// 0xfc5730
void nbCameraBoss_BSBERU_E915_Init(void) {
  nbCameraBoss_BSBERU_E915_Frame = 0;
  nbCameraBoss_BSBERU_E915_Rate = 1.0;
}

// 0xfcbda0
s32 nbCameraBoss_BSBERU_EP_IT_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;

  effBTLModelAllShow();
  switch (dds3GetRandIntA(4u, ""))
  {
    case 0u:
    case 1u:
    case 2u:
    case 3u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v5 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v5, 1u);
      v6 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v6, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      break;
    default:
      return 1;
  }
  return 1;
}

// 0xfb8850
s32 nbCameraBoss_BSKAGU_Command_Calc(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;
  f32 v9;
  nbCamera_t_o *v10;
  nbCamera_t_Fields *p_fields;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v18;

  pFormation = 0;
  *&v18.x = 0;
  *&v18.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v16.x = 0;
  *&v16.z = 0;
  *&v15.x = 0;
  *&v15.z = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[4];
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__STOREVECTOR(&p);
    SDF_VU0__COPYVECTOR(&(*pNbCamera)->target, p, 0);
    effBTLModelGetSphereCenter(pCmdForm);
    SDF_VU0__STOREVECTOR(&v16);
    effBTLModelGetHeight(pCmdForm);
    sub_854930(&v16, 1u);
    SDF_VU0__LOADVECTOR(v16);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&v15);
    sub_854710(&v16, 0);
    sub_854710(&v15, 0);
    sub_854930(&v18, 0);
    sub_854710(&v16, 1u);
    sub_854710(&v15, 1u);
    sub_854930(&v18, 1u);
    sub_854710(&v16, 2u);
    sub_854710(&v15, 2u);
    sub_854930(&v18, 2u);
    sub_854710(&v18, 1u);
    if (v9 > -10.0)
      sub_854930(&v18, 1u);
    SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
    SDF_VU0__LOADVECTOR_B(v18);
    SDF_VU0__SUBVECTOR();
    v10 = *pNbCamera;
    v10->distance = SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
    (*pNbCamera)->fovy = 0.69813;
    p_fields = &(*pNbCamera)->fields;
    effBTLModelLook(pCmdForm, &p_fields->target);
    LODWORD(MainProcessData) = 1;
  }
  return MainProcessData;
}

// 0xfb86d0
s32 nbCameraBoss_BSKAGU_Command_Set(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  s64 orderindex;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v10;
  Il2CppClass **v12;
  struct nbFormation_t_array *form;
  s64 v14;

  else
  {
    MainProcessData = nbGetMainProcessData();
    if (!MainProcessData)
      return 0;
  }
  orderindex = MainProcessData->orderindex;
  if (orderindex == -1)
    return 0;
  order = MainProcessData->order;
  party = MainProcessData->party;
  v10 = order->m_Items[orderindex];
  v12 = &party->obj.klass + v10;
  form = MainProcessData->form;
  v14 = SWORD1(v12[4]->_1.name);
  return nbCameraBoss_BSKAGU_Command_Calc(pNbCamera, &form->m_Items[v14]);
}

// 0xfcc580
s32 nbCameraBoss_BSKAGU_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v7;
  nbCamera_t_Fields *v8;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  sub_854710(&TargetFormation->fields, 0);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v7 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v7, 1u);
  v8 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v8, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfcc860
s32 nbCameraBoss_BSKAGU_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbFormation_t_o *v6;
  nbFormation_t_o *TargetFormation;
  f32 v8;
  f32 v9;
  f32 v11;
  u32 v12;
  u32 RandIntA;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v16;
  nbCamera_t_Fields *v17;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v6 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v6->fields, 0);
  v9 = v8;
  sub_854710(&TargetFormation->fields, 0);
  if (v9 >= v11)
  {
    RandIntA = dds3GetRandIntA(2u, "");
    if (RandIntA != 1)
    {
      if (!RandIntA)
        goto LABEL_26;
      return 1;
    }
LABEL_22:
    nbCameraShot_InvokeTarget_Set2(pNbCamera, &pNBSInfo);
    return 1;
  }
  v12 = dds3GetRandIntA(3u, "");
  if (v12 == 2)
    goto LABEL_22;
  if (v12 <= 1)
  {
LABEL_26:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v16 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v16, 1u);
    v17 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v17, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfb8b60
s32 nbCameraBoss_BSKAGU_EP_IT_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v6;
  nbCamera_t_Fields *v7;

  effBTLModelAllShow();
  {
  }
  DDS3EFFECT_RAND_I();
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v6 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v6, 1u);
  v7 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v7, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfc6880
s32 nbCameraBoss_BSLUSI_Command_Calc(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;
  f32 v9;
  nbCamera_t_o *v10;
  nbCamera_t_Fields *p_fields;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v18;

  pFormation = 0;
  *&v18.x = 0;
  *&v18.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v16.x = 0;
  *&v16.z = 0;
  *&v15.x = 0;
  *&v15.z = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    form = MainProcessData->form;
    pFormation = form->m_Items[4];
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__STOREVECTOR(&p);
    sub_854710(&p, 1u);
    sub_854930(&p, 1u);
    sub_854710(&p, 2u);
    sub_854930(&p, 2u);
    SDF_VU0__COPYVECTOR(&(*pNbCamera)->target, p, 0);
    effBTLModelGetSphereCenter(pCmdForm);
    SDF_VU0__STOREVECTOR(&v16);
    effBTLModelGetHeight(pCmdForm);
    sub_854930(&v16, 1u);
    SDF_VU0__LOADVECTOR(v16);
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&v15);
    sub_854710(&v16, 0);
    sub_854710(&v15, 0);
    sub_854930(&v18, 0);
    sub_854710(&v16, 1u);
    sub_854710(&v15, 1u);
    sub_854930(&v18, 1u);
    sub_854710(&v16, 2u);
    sub_854710(&v15, 2u);
    sub_854930(&v18, 2u);
    sub_854710(&v18, 1u);
    if (v9 > 0.0)
      sub_854930(&v18, 1u);
    SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
    SDF_VU0__LOADVECTOR_B(v18);
    SDF_VU0__SUBVECTOR();
    v10 = *pNbCamera;
    v10->distance = SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
    (*pNbCamera)->fovy = 0.87266;
    p_fields = &(*pNbCamera)->fields;
    effBTLModelLook(pCmdForm, &p_fields->target);
    LODWORD(MainProcessData) = 1;
  }
  return MainProcessData;
}

// 0xfc6bf0
s32 nbCameraBoss_BSLUSI_Command_Set(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  s64 orderindex;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v10;
  Il2CppClass **v12;
  struct nbFormation_t_array *form;
  s64 v14;

  else
  {
    MainProcessData = nbGetMainProcessData();
    if (!MainProcessData)
      return 0;
  }
  orderindex = MainProcessData->orderindex;
  if (orderindex == -1)
    return 0;
  order = MainProcessData->order;
  party = MainProcessData->party;
  v10 = order->m_Items[orderindex];
  v12 = &party->obj.klass + v10;
  form = MainProcessData->form;
  v14 = SWORD1(v12[4]->_1.name);
  return nbCameraBoss_BSLUSI_Command_Calc(pNbCamera, &form->m_Items[v14]);
}

// 0xfcfea0
s32 nbCameraBoss_BSLUSI_Cut23_AllParty_Set(nbCamera_t **pNbCamera) {
  return 0;
}

// 0xfcf580
s32 nbCameraBoss_BSLUSI_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 >= v9)
    goto LABEL_14;
  if (dds3GetRandIntA(2u, "") <= 1)
  {
LABEL_14:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v11 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v11, 1u);
    v12 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v12, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.87266;
  }
  return 1;
}

// 0xfcf980
s32 nbCameraBoss_BSLUSI_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 >= v9)
  {
    if (dds3GetRandIntA(2u, "") <= 1)
      goto LABEL_19;
  }
  else
  {
    if (dds3GetRandIntA(2u, "") <= 1)
    {
LABEL_19:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v11 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v11, 1u);
      v12 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v12, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.87266;
    }
  }
  return 1;
}

// 0xfcc220
s32 nbCameraBoss_BSLUSI_EP_IT_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v8;
  nbCamera_t_Fields *v9;

  effBTLModelAllShow();
  if (effBTLSkillGetTargetNumber() < 2)
    goto LABEL_15;
LABEL_9:
  if (dds3GetRandIntA(2u, "") < 2)
  {
LABEL_19:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v8 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v8, 1u);
    v9 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v9, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.7854;
  }
  return 1;
}

// 0xfce110
s32 nbCameraBoss_BSMETA_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 >= v9)
  {
    if (dds3GetRandIntA(2u, "") <= 1)
      goto LABEL_19;
  }
  else
  {
    if (dds3GetRandIntA(2u, "") <= 1)
    {
LABEL_19:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v11 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v11, 1u);
      v12 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v12, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
    }
  }
  return 1;
}

// 0xfce630
s32 nbCameraBoss_BSMETA_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 >= v9)
  {
    if (dds3GetRandIntA(2u, "") <= 1)
      goto LABEL_19;
  }
  else
  {
    if (dds3GetRandIntA(2u, "") <= 1)
    {
LABEL_19:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v11 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v11, 1u);
      v12 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v12, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
    }
  }
  return 1;
}

// 0xfc5010
void nbCameraBoss_BSMETA_E914_0_Set(void) {
  struct nbCamera_t_o *nbCameraCurrent;

  effBTLModelAllShow();
  sub_854930(&nbCameraCurrent->direction, 0);
  sub_854930(&nbCameraCurrent->direction, 1u);
  sub_854930(&nbCameraCurrent->direction, 2u);
  sub_854710(&nbCameraCurrent->direction, 0);
  sub_854930(&nbCameraCurrent->fields, 0);
  sub_854710(&nbCameraCurrent->direction, 1u);
  sub_854930(&nbCameraCurrent->fields, 1u);
  sub_854710(&nbCameraCurrent->direction, 2u);
  sub_854930(&nbCameraCurrent->fields, 2u);
  *&nbCameraCurrent->distance = 0x3F32B8C23F800000LL;
}

// 0xfc5190
void nbCameraBoss_BSMETA_E914_1_Set(void) {
  struct nbCamera_t_o *nbCameraCurrent;

  effBTLModelAllShow();
  sub_854930(&nbCameraCurrent->direction, 0);
  sub_854930(&nbCameraCurrent->direction, 1u);
  sub_854930(&nbCameraCurrent->direction, 2u);
  sub_854710(&nbCameraCurrent->direction, 0);
  sub_854930(&nbCameraCurrent->fields, 0);
  sub_854710(&nbCameraCurrent->direction, 1u);
  sub_854930(&nbCameraCurrent->fields, 1u);
  sub_854710(&nbCameraCurrent->direction, 2u);
  sub_854930(&nbCameraCurrent->fields, 2u);
  *&nbCameraCurrent->distance = 0x3F32B8C23F800000LL;
}

// 0xfbce30
s32 nbCameraBoss_BSMIZ_Command_Set(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  s64 orderindex;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v9;
  Il2CppClass **v11;
  struct nbFormation_t_array *form;
  s64 v13;
  u32 max_length;
  u32 ID;
  f32 v19;
  nbCamera_t_o *v20;
  nbCamera_t_Fields *p_fields;
  nbFormation_t_o *v24;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v28;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  v24 = 0;
  *&v28.x = 0;
  *&v28.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v26.x = 0;
  *&v26.z = 0;
  *&v25.x = 0;
  *&v25.z = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    orderindex = MainProcessData->orderindex;
    if (orderindex == -1)
    {
      LODWORD(MainProcessData) = 0;
    }
    else
    {
      order = MainProcessData->order;
      party = MainProcessData->party;
      v9 = order->m_Items[orderindex];
      v11 = &party->obj.klass + v9;
      form = MainProcessData->form;
      v13 = SWORD1(v11[4]->_1.name);
      max_length = form->max_length;
      pFormation = form->m_Items[v13];
      v24 = form->m_Items[4];
      ID = effBTLModelGetID(&pFormation);
      effBTLModelGetSphereCenter(&v24);
      SDF_VU0__STOREVECTOR(&p);
      if (ID == 74 || ID == 50)
      {
        sub_854710(&p, 1u);
        sub_854930(&p, 1u);
      }
      SDF_VU0__COPYVECTOR(&(*pNbCamera)->target, p, 0);
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&v26);
      effBTLModelGetHeight(&pFormation);
      sub_854930(&v26, 1u);
      SDF_VU0__LOADVECTOR(v26);
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v25);
      sub_854710(&v26, 0);
      sub_854710(&v25, 0);
      sub_854930(&v28, 0);
      sub_854710(&v26, 1u);
      sub_854710(&v25, 1u);
      sub_854930(&v28, 1u);
      sub_854710(&v26, 2u);
      sub_854710(&v25, 2u);
      sub_854930(&v28, 2u);
      sub_854710(&v28, 1u);
      if (v19 > -1.5)
        sub_854930(&v28, 1u);
      SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
      SDF_VU0__LOADVECTOR_B(v28);
      SDF_VU0__SUBVECTOR();
      v20 = *pNbCamera;
      v20->distance = SDF_VU0__GETLENGTH();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
      (*pNbCamera)->fovy = 0.69813;
      p_fields = &(*pNbCamera)->fields;
      effBTLModelLook(&pFormation, &p_fields->target);
      LODWORD(MainProcessData) = 1;
    }
  }
  return MainProcessData;
}

// 0xfcb580
s32 nbCameraBoss_BSNET1_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbFormation_t_o *v6;
  nbFormation_t_o *TargetFormation;
  f32 v8;
  f32 v9;
  f32 v11;
  u32 RandIntA;
  u32 v14;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v16;
  nbCamera_t_Fields *v17;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v6 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v6->fields, 0);
  v9 = v8;
  sub_854710(&TargetFormation->fields, 0);
  if (v9 < v11)
  {
    RandIntA = dds3GetRandIntA(2u, "");
    if (RandIntA != 1)
    {
      if (!RandIntA)
        goto LABEL_21;
      return 1;
    }
LABEL_22:
    nbCameraShot_InvokeTarget_Set2(pNbCamera, &pNBSInfo);
    return 1;
  }
  v14 = dds3GetRandIntA(2u, "");
  if (v14 == 1)
    goto LABEL_22;
  if (!v14)
  {
LABEL_21:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v16 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v16, 1u);
    v17 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v17, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfcb930
s32 nbCameraBoss_BSNET_EP_IT_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;

  effBTLModelAllShow();
  switch (dds3GetRandIntA(5u, ""))
  {
    case 0u:
    case 1u:
    case 2u:
    case 3u:
    case 4u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v5 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v5, 1u);
      v6 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v6, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      break;
    default:
      return 1;
  }
  return 1;
}

// 0xfbd2a0
s32 nbCameraBoss_BSONGY_Command_Set(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  s64 orderindex;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v9;
  Il2CppClass **v11;
  struct nbFormation_t_array *form;
  s64 v13;
  struct nbFormation_t_array *v16;
  struct nbFormation_t_array *v18;
  struct nbFormation_t_array *v20;
  struct nbFormation_t_array *v22;
  nbFormation_t_o *v25;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o pPos;

  v25 = 0;
  pFormation = 0;
  *&pPos.x = 0;
  *&pPos.z = 0;
  *&v28.x = 0;
  *&v28.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    if (effBTLModelGetGroupNumber(0x200u) <= 1 && !MainProcessData->turn
      || (orderindex = MainProcessData->orderindex, orderindex == -1))
    {
      LODWORD(MainProcessData) = 0;
    }
    else
    {
      order = MainProcessData->order;
      party = MainProcessData->party;
      v9 = order->m_Items[orderindex];
      v11 = &party->obj.klass + v9;
      form = MainProcessData->form;
      v13 = SWORD1(v11[4]->_1.name);
      pFormation = form->m_Items[v13];
      sub_854930(&v28, 0);
      sub_854930(&v28, 1u);
      sub_854930(&v28, 2u);
      sub_854930(&v28, 3u);
      SDF_VU0__COPYVECTOR(&(*pNbCamera)->target, v28, 0);
      v16 = MainProcessData->form;
      v25 = v16->m_Items[0];
      if ((~v25->stat & 3) == 0)
      {
        effBTLModelGetPosition(&v25, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&v25, &pPos);
      }
      v18 = MainProcessData->form;
      v25 = v18->m_Items[1];
      if ((~v25->stat & 3) == 0)
      {
        effBTLModelGetPosition(&v25, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&v25, &pPos);
      }
      v20 = MainProcessData->form;
      v25 = v20->m_Items[2];
      if ((~v25->stat & 3) == 0)
      {
        effBTLModelGetPosition(&v25, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&v25, &pPos);
      }
      v22 = MainProcessData->form;
      v25 = v22->m_Items[3];
      if ((~v25->stat & 3) == 0)
      {
        effBTLModelGetPosition(&v25, &pPos);
        sub_854710(&pPos, 2u);
        sub_854930(&pPos, 2u);
        effBTLModelSetPosition(&v25, &pPos);
      }
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&p);
      effBTLModelGetHeight(&pFormation);
      LODWORD(MainProcessData) = 1;
      sub_854930(&p, 1u);
      SDF_VU0__LOADVECTOR(v28);
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
      (*pNbCamera)->distance = 1700.0;
      (*pNbCamera)->fovy = 0.69813;
      effBTLModelLook(&pFormation, &(*pNbCamera)->target, 0);
    }
  }
  return MainProcessData;
}

// 0xfcd390
s32 nbCameraBoss_BSPISH_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 < v9)
    goto LABEL_14;
  if (dds3GetRandIntA(2u, "") <= 1)
  {
LABEL_14:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v11 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v11, 1u);
    v12 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v12, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfcd790
s32 nbCameraBoss_BSPISH_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbFormation_t_o *v6;
  nbFormation_t_o *TargetFormation;
  f32 v8;
  f32 v9;
  f32 v11;
  u32 v12;
  u32 RandIntA;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v16;
  nbCamera_t_Fields *v17;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v6 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v6->fields, 0);
  v9 = v8;
  sub_854710(&TargetFormation->fields, 0);
  if (v9 >= v11)
  {
    RandIntA = dds3GetRandIntA(3u, "");
    if (RandIntA != 2)
    {
      if (RandIntA <= 1)
        goto LABEL_26;
      return 1;
    }
LABEL_22:
    nbCameraShot_InvokeTarget_Set2(pNbCamera, &pNBSInfo);
    return 1;
  }
  v12 = dds3GetRandIntA(3u, "");
  if (v12 == 2)
    goto LABEL_22;
  if (v12 <= 1)
  {
LABEL_26:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v16 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v16, 1u);
    v17 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v17, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfcdd10
s32 nbCameraBoss_BSPISH_Cut23_EX03_Set(nbCamera_t **pNbCamera) {
  nbFormation_t_o *v4;
  nbFormation_t_o *TargetFormation;
  f32 v6;
  f32 v7;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;

  effBTLModelAllShow();
  effBTLModelInvokeGroupHide();
  v4 = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&v4->fields, 0);
  v7 = v6;
  sub_854710(&TargetFormation->fields, 0);
  if (v7 < v9)
    goto LABEL_14;
  if (dds3GetRandIntA(2u, "") <= 1)
  {
LABEL_14:
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v11 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v11, 1u);
    v12 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v12, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfccd00
s32 nbCameraBoss_BSPISH_EP_IT_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v6;
  nbCamera_t_Fields *v7;

  effBTLModelAllShow();
  if (nbCameraBoss_Bskagu_Cut1_Direction == 1)
  {
    dds3GetRandIntA(2u, "");
  }
  else
  {
    dds3GetRandIntA(3u, "");
  }
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v6 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v6, 1u);
  v7 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v7, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfbdc70
s32 nbCameraBoss_BSSAMA_Command_Set(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  s64 orderindex;
  struct System_SByte_array *order;
  struct nbParty_t_array *party;
  s64 v9;
  Il2CppClass **v11;
  struct nbFormation_t_array *form;
  s64 v13;
  u32 max_length;
  f32 v17;
  nbCamera_t_o *v18;
  nbCamera_t_Fields *p_fields;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v26;
  nbFormation_t_o *v27;

  v27 = 0;
  pFormation = 0;
  *&v26.x = 0;
  *&v26.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  *&v23.x = 0;
  *&v23.z = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    orderindex = MainProcessData->orderindex;
    if (orderindex == -1)
    {
      LODWORD(MainProcessData) = 0;
    }
    else
    {
      order = MainProcessData->order;
      party = MainProcessData->party;
      v9 = order->m_Items[orderindex];
      v11 = &party->obj.klass + v9;
      form = MainProcessData->form;
      v13 = SWORD1(v11[4]->_1.name);
      max_length = form->max_length;
      v27 = form->m_Items[v13];
      pFormation = form->m_Items[4];
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&p, 1u);
      sub_854930(&p, 1u);
      SDF_VU0__COPYVECTOR(&(*pNbCamera)->target, p, 0);
      effBTLModelGetSphereCenter(&v27);
      SDF_VU0__STOREVECTOR(&v24);
      effBTLModelGetHeight(&v27);
      sub_854930(&v24, 1u);
      SDF_VU0__LOADVECTOR(v24);
      SDF_VU0__LOADVECTOR_B(p);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&v23);
      sub_854710(&v24, 0);
      sub_854710(&v23, 0);
      sub_854930(&v26, 0);
      sub_854710(&v24, 1u);
      sub_854710(&v23, 1u);
      sub_854930(&v26, 1u);
      sub_854710(&v24, 2u);
      sub_854710(&v23, 2u);
      sub_854930(&v26, 2u);
      sub_854710(&v26, 1u);
      if (v17 > -10.0)
        sub_854930(&v26, 1u);
      SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
      SDF_VU0__LOADVECTOR_B(v26);
      SDF_VU0__SUBVECTOR();
      v18 = *pNbCamera;
      v18->distance = SDF_VU0__GETLENGTH();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
      (*pNbCamera)->fovy = 0.69813;
      p_fields = &(*pNbCamera)->fields;
      effBTLModelLook(&v27, &p_fields->target);
      LODWORD(MainProcessData) = 1;
    }
  }
  return MainProcessData;
}

// 0xfbe710
s32 nbCameraBoss_Baal_BAELNO_Run(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfbe620
s32 nbCameraBoss_Baal_BAELNO_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  if ((DDS3EFFECT_RAND_I() & 1) != 0)
  {
    nbCameraShot_InvokeTarget_Set2(pNbCamera, &pNBSInfo);
  }
  else
  {
    nbCameraShot_InvokeTargetReverse_Set2(pNbCamera, &pNBSInfo);
  }
  return 1;
}

// 0xfc5e40
s32 nbCameraBoss_Beru_HAENO1_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbCamera_t_o *v5;
  f32 v9;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v12;
  nbCamera_t_Fields *v13;
  nbCamera_t_o *v14;
  u32 type;
  s32 frame;
  f32 v17;
  nbCamera_t_o *v18;
  s32 v19;
  nbCamera_t_Fields *v21;
  nbCamera_t_Fields *v22;
  nbCamera_t_Fields *v23;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o pPos;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  effBTL_SkillPositionPtr_t_o *pPosPtr;

  pFormation = 0;
  v3 = Allocate(effBTL_SkillPositionPtr_t);
  effBTL_SkillPositionPtr_t___ctor(v3);
  pPosPtr = v3;
  *&p.x = 0;
  *&p.z = 0;
  *&v28.x = 0;
  *&v28.z = 0;
  *&pPos.x = 0;
  *&pPos.z = 0;
  *&v26.x = 0;
  *&v26.z = 0;
  *&v25.x = 0;
  *&v25.z = 0;
  v5 = *pNbCamera;
  if (!(*pNbCamera)->frame)
  {
    pFormation = effBTLSkillGetInvokeFormation(0);
    *(v3 + 8) = 1282;
    *(v3 + 18) = 8;
    *(v3 + 5) = 0;
    effBTLPartGetPositionPtr(&pFormation, &pPosPtr, &pPos);
    effBTLModelLook(&pFormation, &pPos);
    nbGetFormRot(&pFormation);
    SDF_VU0__STOREVECTOR(&p);
    v9 = SDF_DEGtoRAD(-8.0);
    FromEuler(0.0, v9, 0.0);
    SDF_VU0__LOADVECTOR_B(p);
    Mult();
    SDF_VU0__STOREVECTOR(&p);
    nbSetFormRot(&pFormation, p, 0);
    effBTLModelGetPosition(&pFormation, &v28);
    SDF_VU0__LOADVECTOR(pPos);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B(v28);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(-950.0);
    SDF_VU0__ADDVECTOR_A_C();
    SDF_VU0__STOREVECTOR(&v28);
    effBTLModelSetPosition(&pFormation, &v28);
    v5 = *pNbCamera;
    if (!(*pNbCamera)->frame)
    {
      v5->type = dds3GetRandIntA(2u, "");
      effBTLModelAllHide();
      effBTLModelInvokeShow();
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v12 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v12, 1u);
      v13 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v13, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      v5 = *pNbCamera;
    }
  }
  v5->type = 1;
  v14 = *pNbCamera;
  type = (*pNbCamera)->type;
  if (type == 1)
  {
    if (v14->frame == 15)
    {
      effBTLModelAllShow();
      switch (dds3GetRandIntA(4u, ""))
      {
        case 0u:
        case 1u:
        case 2u:
        case 3u:
          sub_854930(&(*pNbCamera)->direction, 0);
          sub_854930(&(*pNbCamera)->direction, 1u);
          sub_854930(&(*pNbCamera)->direction, 2u);
          v21 = &(*pNbCamera)->fields;
          sub_854710(&(*pNbCamera)->direction, 0);
          sub_854930(v21, 0);
          v22 = &(*pNbCamera)->fields;
          sub_854710(&(*pNbCamera)->direction, 1u);
          sub_854930(v22, 1u);
          v23 = &(*pNbCamera)->fields;
          sub_854710(&(*pNbCamera)->direction, 2u);
          sub_854930(v23, 2u);
          (*pNbCamera)->distance = 1.0;
          v18 = *pNbCamera;
          v19 = 1061752795;
          goto LABEL_42;
        default:
          return 1;
      }
    }
  }
  else if (!type)
  {
    frame = v14->frame;
    if (frame >= 15)
    {
      if (frame == 15)
      {
        effBTLModelAllShow();
        frame = (*pNbCamera)->frame;
      }
      v17 = fminf((frame - 15) / 45.0, 1.0);
      sub_854930(&v26, 0);
      sub_854930(&v26, 1u);
      sub_854930(&v26, 2u);
      sub_854930(&v25, 0);
      sub_854930(&v25, 1u);
      sub_854930(&v25, 2u);
      SDF_VU0__LOADVECTOR(v26);
      SDF_VU0__LOADVECTOR_B(v25);
      SDF_VU0__INTERPOLATE(v17);
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
      sub_854930(&v26, 0);
      sub_854930(&v26, 1u);
      sub_854930(&v26, 2u);
      sub_854930(&v25, 0);
      sub_854930(&v25, 1u);
      sub_854930(&v25, 2u);
      SDF_VU0__LOADVECTOR(v26);
      SDF_VU0__LOADVECTOR_B(v25);
      SDF_VU0__INTERPOLATE(v17);
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
      (*pNbCamera)->distance = 1.0;
      v18 = *pNbCamera;
      v19 = 1060288706;
LABEL_42:
      LODWORD(v18->fovy) = v19;
    }
  }
  return 1;
}

// 0xfc4940
s32 nbCameraBoss_Bskagu_Cut1_Run(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfc43d0
s32 nbCameraBoss_Bskagu_Cut1_Set(nbCamera_t **pNbCamera) {
  s32 v4;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;
  nbCamera_t_Fields *v7;
  nbCamera_t_Fields *v10;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *v12;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v14;
  nbCamera_t_Fields *v15;

  effBTLModelAllHide();
  effBTLModelInvokeShow();
  switch (dds3GetRandIntA(4u, ""))
  {
    case 0u:
    case 3u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v14 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v14, 1u);
      v15 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v15, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      v4 = 0;
      goto LABEL_20;
    case 1u:
      sub_854930(&(*pNbCamera)->direction, 0);
      v4 = 1;
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      v5 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(v5, 0);
      v6 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v6, 1u);
      v7 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v7, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
        goto LABEL_20;
        goto LABEL_12;
      goto LABEL_15;
    case 2u:
      sub_854930(&(*pNbCamera)->direction, 0);
      v4 = 1;
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      v10 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(v10, 0);
      v11 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v11, 1u);
      v12 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v12, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
        goto LABEL_20;
      else
      {
LABEL_12:
        v4 = 1;
      }
LABEL_20:
      nbCameraBoss_Bskagu_Cut1_Direction = v4;
      return 1;
    default:
      return 1;
  }
}

// 0xfc1990
s32 nbCameraBoss_Bsnet_AISHOH_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;

  effBTLModelAllShow();
  if (dds3GetRandIntA(3u, "") <= 2)
  {
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v5 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v5, 1u);
    v6 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v6, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfbe8e0
s32 nbCameraBoss_Bsnet_Attack_Cut1_Run(nbCamera_t **pNbCamera) {
  u32 ID;
  s32 v7;
  s32 frame;
  struct datUnitMotion_s_array *motion;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  ID = effBTLModelGetID(&pFormation);
  if (ID == 512)
    return 0;
  v7 = ID;
  frame = (*pNbCamera)->frame;
  motion = Get(v7, 0)->motion;
  if (frame < motion->m_Items[3]->actframe)
    (*pNbCamera)->distance = (*pNbCamera)->distance + 12.5;
  nbCameraShot_GroundCollision(pNbCamera);
  return 1;
}

// 0xfbe720
s32 nbCameraBoss_Bsnet_Attack_Cut1_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbCamera_t_Fields *p_fields;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  nbCameraState_SkillAttack_Init();
  effBTLSkillGetInvokeFormation(0);
  nbCameraState_InvokeTarget_SearchSet();
  *(v3 + 6) = 1048971922;
  *(v3 + 7) = dword_32C3100[(DDS3EFFECT_RAND_I() & 1) == 0];
  v3[4] = 0;
  nbCameraShot_Invoke_Set2(pNbCamera, &pNBSInfo);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(p_fields, 1u);
  sub_854930(p_fields, 1u);
  nbCameraShot_GroundCollision(pNbCamera);
  return 1;
}

// 0xfbf0a0
s32 nbCameraBoss_Bsnet_Attack_Run(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfbed80
s32 nbCameraBoss_Bsnet_Attack_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_o *v4;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v11;

  TargetFormation = 0;
  pFormation = 0;
  *&v11.x = 0;
  *&v11.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v9.x = 0;
  *&v9.z = 0;
  *&v8.x = 0;
  *&v8.z = 0;
  effBTLModelTargetPartyShow();
  effBTLModelInvokeGroupHide();
  TargetFormation = effBTLSkillGetTargetFormation(0);
  pFormation = effBTLSkillGetInvokeFormation(0);
  effBTLModelGetMarkPosition2(&pFormation, 0x14u);
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.25);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__STOREVECTOR(&p);
  effBTLPartGetScalePtr(&TargetFormation);
  effBTLModelGetSphereCenter(&TargetFormation);
  SDF_VU0__STOREVECTOR(&v9);
  sub_854930(&p, 1u);
  sub_854930(&v9, 1u);
  sub_854710(&v9, 0);
  sub_854930(&v9, 0);
  SDF_VU0__LOADVECTOR(v9);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v8);
  sub_854710(&v9, 0);
  sub_854710(&v8, 0);
  sub_854930(&v11, 0);
  sub_854930(&v11, 1u);
  sub_854710(&v9, 2u);
  sub_854710(&v8, 2u);
  sub_854930(&v11, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v11);
  SDF_VU0__SUBVECTOR();
  v4 = *pNbCamera;
  v4->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->fovy = 0.69813;
  effBTLModelLook(&TargetFormation, &(*pNbCamera)->target, 0);
  return 1;
}

// 0xfbec10
s32 nbCameraBoss_Bsnet_Cut1_Run(nbCamera_t **pNbCamera) {
  u32 ID;
  s32 v7;
  s32 frame;
  struct datUnitMotion_s_array *motion;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  ID = effBTLModelGetID(&pFormation);
  if (ID == 512)
    return 0;
  v7 = ID;
  frame = (*pNbCamera)->frame;
  motion = Get(v7, 0)->motion;
  if (frame < motion->m_Items[4]->actframe)
    (*pNbCamera)->distance = (*pNbCamera)->distance + -15.0;
  nbCameraShot_GroundCollision(pNbCamera);
  return 1;
}

// 0xfbea50
s32 nbCameraBoss_Bsnet_Cut1_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbCamera_t_Fields *p_fields;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  nbCameraState_SkillAttack_Init();
  effBTLSkillGetInvokeFormation(0);
  nbCameraState_InvokeTarget_SearchSet();
  *(v3 + 6) = 1048971922;
  *(v3 + 7) = dword_32C3100[(DDS3EFFECT_RAND_I() & 1) == 0];
  v3[4] = 0;
  nbCameraShot_Invoke_Set2(pNbCamera, &pNBSInfo);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(p_fields, 1u);
  sub_854930(p_fields, 1u);
  nbCameraShot_GroundCollision(pNbCamera);
  return 1;
}

// 0xfbfa50
void nbCameraBoss_Bsnet_E905_Set(void) {
  u64 *v1;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v1 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v1);
  pNBSInfo = v1;
  nbCameraShot_All_Set2(&nbCameraCurrent, &pNBSInfo);
}

// 0xfbf8c0
void nbCameraBoss_Bsnet_E907_2_Run(void) {
  UnityEngine_Vector4_o *nbCameraCurrent;
  f32 Bsnet_E907_2_Rate;
  f32 v7;

  Bsnet_E907_2_Rate = Bsnet_E907_2_Rate * 0.925;
  if ((1.0 - Bsnet_E907_2_Rate) > 0.0)
  {
    v7 = fminf(1.0 - Bsnet_E907_2_Rate, 1.0);
    SDF_VU0__LOADVECTOR(Bsnet_E907_2_StartTarget);
    SDF_VU0__LOADVECTOR_B(Bsnet_E907_2_EndTarget);
    SDF_VU0__INTERPOLATE(v7);
    SDF_VU0__STOREVECTOR(nbCameraCurrent + 1);
    SDF_VU0__LOADVECTOR(Bsnet_E907_2_StartDirection);
    SDF_VU0__LOADVECTOR_B(Bsnet_E907_2_EndDirection);
    SDF_VU0__INTERPOLATE(v7);
    SDF_VU0__STOREVECTOR(nbCameraCurrent + 2);
    nbCameraCurrent[3].x = Bsnet_E907_2_StartDistance
                                + (v7
                                 * (Bsnet_E907_2_EndDistance
                                  - Bsnet_E907_2_StartDistance));
  }
}

// 0xfbf700
void nbCameraBoss_Bsnet_E907_2_Set(void) {
  u64 *v1;
  u64 *v2;
  UnityEngine_Vector4_o *nbCameraCurrent;
  nbCamera_t_o *v9;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v1 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v1);
  pNBSInfo = v1;
  v2 = Allocate(nbCamera_t);
  nbCamera_t___ctor(v2);
  v9 = v2;
  SDF_VU0__COPYVECTOR(&Bsnet_E907_2_StartTarget, nbCameraCurrent[1]);
  SDF_VU0__COPYVECTOR(&Bsnet_E907_2_StartDirection, nbCameraCurrent[2]);
  Bsnet_E907_2_StartDistance = nbCameraCurrent[3].x;
  nbCameraShot_All_Set2(&v9, &pNBSInfo);
  SDF_VU0__COPYVECTOR(&Bsnet_E907_2_EndTarget, v9->target);
  SDF_VU0__COPYVECTOR(&Bsnet_E907_2_EndDirection, v9->direction);
  Bsnet_E907_2_EndDistance = v9->distance;
  Bsnet_E907_2_EndDistance = Bsnet_E907_2_EndDistance * 1.05;
  Bsnet_E907_2_Rate = 1.0;
}

// 0xfbf680
void nbCameraBoss_Bsnet_E907_Run(void) {
  nbCameraCurrent->distance = nbCameraCurrent->distance + -60.0;
}

// 0xfbf5c0
void nbCameraBoss_Bsnet_E907_Set(void) {
  u64 *v1;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v1 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v1);
  pNBSInfo = v1;
  nbCameraShot_All_Set2(&nbCameraCurrent, &pNBSInfo);
}

// 0xfc5000
s32 nbCameraBoss_Bspish_Cut1_Run(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfc4950
s32 nbCameraBoss_Bspish_Cut1_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v8;
  nbCamera_t_Fields *v9;
  nbCamera_t_Fields *v12;
  nbCamera_t_Fields *v13;
  nbCamera_t_Fields *v14;
  s32 v22;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  effBTLModelAllHide();
  effBTLModelInvokeShow();
  switch (dds3GetRandIntA(5u, ""))
  {
    case 0u:
    case 2u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v8 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v8, 1u);
      v9 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v9, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      nbCameraBoss_Bskagu_Cut1_Direction = 0;
      return 1;
    case 1u:
    case 3u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      v12 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(v12, 0);
      v13 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v13, 1u);
      v14 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v14, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      nbCameraBoss_Bskagu_Cut1_Direction = 1;
      return 1;
    case 4u:
      nbCameraState_SkillAttack_Init();
      effBTLSkillGetInvokeFormation(0);
      nbCameraState_InvokeTarget_SearchSet();
      *(v3 + 6) = 1048971922;
      else if ((DDS3EFFECT_RAND_I() & 1) == 0)
      {
        goto LABEL_30;
      }
      *(v3 + 7) = 1057360530;
      v22 = 0;
LABEL_39:
      nbCameraBoss_Bskagu_Cut1_Direction = v22;
      *&pNBSInfo->HeightMin = 0;
      nbCameraShot_Invoke_Set2(pNbCamera, &pNBSInfo);
      nbCameraShot_GroundCollision(pNbCamera);
      return 1;
    default:
      return 1;
  }
}

// 0xfc9910
s32 nbCameraBoss_CheckFix(void) {
  nbMainProcessData_t_o *MainProcessData;
  s64 v4;
  struct nbFormation_t_array *form;
  u32 ID;
  u32 v8;
  u64 v9;
  s32 result;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  MainProcessData = nbGetMainProcessData();
  v4 = 8;
  do
  {
    form = MainProcessData->form;
    pFormation = *(&form->obj.klass + v4);
    if ((~pFormation->stat & 3) == 0)
    {
      ID = effBTLModelGetID(&pFormation);
      if (ID > 0x108)
      {
        result = 0;
        if (ID - 291 <= 0x35 && ((1LL << (ID - 35)) & 0x38000000000007LL) != 0 || ID == 278)
          return result;
      }
      else
      {
        v8 = ID - 258;
        if (v8 <= 6 && ((1 << v8) & 0x43) != 0)
          return 0;
      }
    }
    v9 = v4 - 8;
    ++v4;
  }
  while (v9 < 9);
  return 1;
}

// 0xfb9990
s32 nbCameraBoss_CheckRotate(nbFormation_t **pFormation) {
  u32 ID;

  ID = effBTLModelGetID(pFormation);
  if (ID > 0x108)
  {
    if (ID - 291 <= 0x35 && ((1LL << (ID - 35)) & 0x38003800000007LL) != 0)
      return 0;
  }
  else if (ID - 258 < 7)
  {
    return dword_33CBA58[ID - 258];
  }
  return 1;
}

// 0xfc9a80
s32 nbCameraBoss_Command_Init(nbCamera_t **pNbCamera) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v5;
  s32 formationtype;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v9;
  struct nbFormation_t_array *v11;
  u32 ID;
  s64 v14;
  struct nbFormation_t_array *v15;
  u32 v17;
  u64 v18;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    v5 = MainProcessData;
    if (MainProcessData->orderindex == 255)
    {
LABEL_56:
      LODWORD(MainProcessData) = 0;
      return MainProcessData;
    }
    formationtype = MainProcessData->formationtype;
    if (formationtype != 13)
    {
      if (formationtype != 10)
      {
        if (formationtype == 9)
        {
          form = MainProcessData->form;
          pFormation = form->m_Items[4];
          if ((pFormation->stat & 1) != 0)
          {
            if (effBTLModelGetID(&pFormation) == 291)
            {
              LODWORD(MainProcessData) = nbCameraBoss_BSARI_Command_Set(pNbCamera);
              return MainProcessData;
            }
          }
        }
        goto LABEL_41;
      }
      v11 = MainProcessData->form;
      pFormation = v11->m_Items[4];
      if ((pFormation->stat & 1) != 0)
      {
        ID = effBTLModelGetID(&pFormation);
        if (ID == 293 || ID == 264)
        {
          LODWORD(MainProcessData) = nbCameraBoss_BSKAGU_Command_Set(pNbCamera);
          return MainProcessData;
        }
      }
LABEL_41:
      v14 = 8;
      while (1)
      {
        v15 = v5->form;
        pFormation = *(&v15->obj.klass + v14);
        if ((pFormation->stat & 1) != 0)
        {
          v17 = effBTLModelGetID(&pFormation);
          if (v17 > 0x10D)
          {
            switch (v17)
            {
              case 0x114u:
                LODWORD(MainProcessData) = nbCameraBoss_BSARUS_Command_Set(pNbCamera);
                return MainProcessData;
              case 0x11Fu:
                LODWORD(MainProcessData) = nbCameraBoss_BSSAMA_Command_Set(pNbCamera);
                return MainProcessData;
              case 0x129u:
LABEL_58:
                LODWORD(MainProcessData) = nbCameraBoss_BSMIZ_Command_Set(pNbCamera);
                return MainProcessData;
            }
          }
          else
          {
            if (v17 == 265)
              goto LABEL_58;
            if (v17 == 269)
            {
              LODWORD(MainProcessData) = nbCameraBoss_BSONGY_Command_Set(pNbCamera);
              return MainProcessData;
            }
          }
        }
        v18 = v14 - 8;
        ++v14;
        if (v18 >= 9)
          goto LABEL_56;
      }
    }
    v9 = MainProcessData->form;
    pFormation = v9->m_Items[4];
    if ((pFormation->stat & 1) == 0)
      goto LABEL_41;
    LODWORD(MainProcessData) = nbCameraBoss_BSLUSI_Command_Set(pNbCamera);
  }
  return MainProcessData;
}

// 0xfc85a0
s32 nbCameraBoss_Cut1_Init(nbCamera_t **pNbCamera) {
  u32 ID;
  u32 v6;
  s32 result;
  nbCamera_t_o **v8;
  nbCamera_t_o **v9;
  u32 v12;
  u32 RandIntA;
  nbCamera_t_o **v17;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  ID = effBTLModelGetID(&pFormation);
  v6 = effBTLSkillGetID();
  if (ID > 0x111)
  {
    result = 0;
    switch (ID)
    {
      case 0x113u:
      case 0x126u:
      case 0x127u:
      case 0x128u:
LABEL_18:
        if (v6 != 153)
          return 0;
        nbResetAllFormPosRot();
        return 0;
      case 0x123u:
        if (v6 == 168)
        {
LABEL_70:
          RandIntA = dds3GetRandIntA(3u, "");
          nbCameraBoss_BSARI_SIMANO_Type = RandIntA;
          nbCameraBoss_BSARI_SIMANO_Rate = 1.0;
        }
        else if (v6 == 253)
        {
LABEL_45:
          nbCameraBoss_BSARI_MASEHA_Frame = 0;
          nbCameraBoss_BSARI_MASEHA_Type = dds3GetRandIntA(3u, "");
        }
        else
        {
          nbCameraBoss_BSARI_Cut1_Set(v17);
        }
        return 1;
      case 0x124u:
LABEL_29:
        if (v6 - 169 > 1)
        {
          nbCameraBoss_Bsnet_Cut1_Set(pNbCamera);
        }
        else
        {
          nbCameraBoss_Bsnet_Attack_Cut1_Set(pNbCamera);
        }
        return 1;
      case 0x125u:
        nbCameraBoss_Bskagu_Cut1_Set(pNbCamera);
        return 1;
      case 0x158u:
        if (v6 != 273 && v6 != 270)
          return 0;
        v12 = dds3GetRandIntA(2u, "");
        nbCameraBoss_BSLUSI_Type = v12;
        break;
      default:
        return result;
    }
  }
  else
  {
    result = 0;
    switch (ID)
    {
      case 0x101u:
      case 0x111u:
        goto LABEL_18;
      case 0x102u:
        if (v6 == 168)
          goto LABEL_70;
        if (v6 == 253)
          goto LABEL_45;
        nbCameraBoss_BSARI2_Cut1_Set(v8);
        break;
      case 0x103u:
        goto LABEL_29;
      case 0x108u:
        if (v6 == 221)
        {
          nbCameraBoss_Pish_MUHENK_Set(v9);
        }
        else
        {
          nbCameraBoss_Bspish_Cut1_Set(pNbCamera);
        }
        return 1;
      default:
        return result;
    }
  }
  return 1;
}

// 0xfc8a80
s32 nbCameraBoss_Cut1_Run(nbCamera_t **pNbCamera) {
  u32 ID;
  u32 v6;
  s32 result;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  ID = effBTLModelGetID(&pFormation);
  v6 = effBTLSkillGetID();
  if (ID > 0x103)
  {
    result = 0;
    switch (ID)
    {
      case 0x108u:
        if (v6 == 221)
        {
          nbCameraBoss_Pish_MUHENK_Run(pNbCamera);
        }
        {
LABEL_49:
        }
        return 1;
      case 0x109u:
      case 0x10Au:
      case 0x10Bu:
      case 0x10Cu:
      case 0x10Du:
      case 0x10Eu:
      case 0x10Fu:
      case 0x110u:
      case 0x111u:
      case 0x112u:
      case 0x113u:
      case 0x114u:
      case 0x115u:
      case 0x116u:
      case 0x117u:
      case 0x118u:
      case 0x119u:
      case 0x11Au:
      case 0x11Bu:
      case 0x11Cu:
      case 0x11Du:
      case 0x11Eu:
      case 0x11Fu:
      case 0x120u:
      case 0x121u:
      case 0x122u:
        return result;
      case 0x123u:
        if (v6 == 168)
          goto LABEL_51;
        if (v6 == 253)
          goto LABEL_44;
        nbCameraBoss_BSARI_Cut1_Run(pNbCamera);
        return 1;
      case 0x124u:
        goto LABEL_19;
      case 0x125u:
          return 1;
        goto LABEL_49;
      default:
        if (ID != 344)
          return result;
        if (v6 == 270 || v6 == 273)
        {
          nbCameraBoss_Lusi_Cut1_Set(pNbCamera);
        }
        else
        {
          if (v6 != 271)
            return 0;
          nbCameraBoss_Lusi_ASIKIK_Set(pNbCamera);
        }
        break;
    }
    return 1;
  }
  if (ID == 258)
  {
    if (v6 == 168)
    {
LABEL_51:
      nbCameraBoss_BSARI_SIMANO_Run(pNbCamera);
    }
    else if (v6 == 253)
    {
LABEL_44:
      nbCameraBoss_BSARI_MASEHA_Run(pNbCamera);
    }
    else
    {
      nbCameraBoss_BSARI2_Cut1_Run(pNbCamera);
    }
    return 1;
  }
  if (ID != 259)
    return 0;
LABEL_19:
  if (v6 - 169 > 1)
  {
    return nbCameraBoss_Bsnet_Cut1_Run(pNbCamera);
  }
  else
  {
    return nbCameraBoss_Bsnet_Attack_Cut1_Run(pNbCamera);
  }
}

// 0xfc8dc0
s32 nbCameraBoss_Cut2_Init(nbCamera_t **pNbCamera) {
  u64 *v3;
  u32 ID;
  u32 v7;
  s32 result;
  f32 v10;
  f32 v11;
  u32 RandIntA;
  nbCameraSkillInfo_t_o *pNBSInfo;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  pFormation = effBTLSkillGetInvokeFormation(0);
  ID = effBTLModelGetID(&pFormation);
  v7 = effBTLSkillGetID();
  if (ID <= 0x115)
  {
    if (ID <= 0x108)
    {
      switch (ID)
      {
        case 0x100u:
          if (v7 != 244 && v7 != 10)
            return 0;
          return nbCameraBoss_Foru_SIMON_Set(pNbCamera);
        case 0x101u:
          goto LABEL_28;
        case 0x102u:
          if (v7 != 174)
            return 0;
          v10 = 0.9;
          v11 = -5.0;
          goto LABEL_145;
        case 0x103u:
          if (v7 - 169 >= 2)
            goto LABEL_123;
          v10 = 0.85;
          goto LABEL_117;
        case 0x104u:
        case 0x105u:
        case 0x106u:
        case 0x107u:
          return 0;
        case 0x108u:
          if (v7 - 219 <= 1)
          {
            nbCameraBoss_Pish_PRESS_Set(pNbCamera);
            return 1;
          }
          if (v7 == 221)
            return 1;
          break;
        default:
          if (ID != 203)
            return 0;
          goto LABEL_54;
      }
      return 0;
    }
    switch (ID)
    {
      case 0x10Du:
        if (v7 != 233)
          return 0;
        nbCameraSetState(0);
        break;
      case 0x111u:
      case 0x113u:
        goto LABEL_28;
      case 0x115u:
        if (v7 != 155)
          return 0;
        nbCameraBoss_Sukady_DAIJIS_Set(pNbCamera);
        break;
      default:
        return 0;
    }
    return 1;
  }
  if (ID > 0x148)
  {
    switch (ID)
    {
      case 0x156u:
        if (v7 == 235)
        {
          nbCameraBoss_Meta_METAT1_0_Set(pNbCamera);
          return 1;
        }
        break;
      case 0x157u:
        if (v7 == 259)
        {
          nbCameraBoss_Beru_HAENO1_Set(pNbCamera);
          return 1;
        }
        break;
      case 0x158u:
        if (v7 == 273)
        {
          nbCameraBoss_Lusi_OHNOOH_Set(pNbCamera);
          return 1;
        }
        break;
      case 0x161u:
LABEL_54:
        if (v7 == 159)
        {
          nbCameraShot_InvokeTargetParty_Set2(pNbCamera, &pNBSInfo);
          return 1;
        }
        break;
    }
    return 0;
  }
  switch (ID)
  {
    case 0x11Fu:
      if (!v7 || v7 == 165)
      {
        v10 = 0.55;
        v11 = 0.0;
LABEL_145:
        nbCameraBoss_TargetInvoke_Set(pNbCamera, v11, v10);
      }
      else
      {
        if (v7 != 242)
          return 0;
        nbCameraBoss_Samael_AKUI_Set(pNbCamera);
      }
      return 1;
    case 0x120u:
      if (v7 != 201)
        return 0;
      nbCameraBoss_Baal_BAELNO_Set(pNbCamera);
      return 1;
    case 0x121u:
    case 0x122u:
      return 0;
    case 0x123u:
      if (v7 != 171)
        return 0;
      v10 = 0.55;
LABEL_117:
      v11 = 15.0;
      goto LABEL_145;
    case 0x124u:
      if (v7 - 169 >= 2)
      {
LABEL_123:
        if (v7 != 234)
          return 0;
        nbCameraBoss_Bsnet_AISHOH_Set(pNbCamera);
      }
      else
      {
        nbCameraBoss_Bsnet_Attack_Set(pNbCamera);
      }
      return 1;
    case 0x125u:
      switch (v7)
      {
        case 0xFEu:
          nbCameraBoss_Kagu_FLEACH_Set(pNbCamera);
          break;
        case 0xF1u:
          RandIntA = dds3GetRandIntA(3u, "");
          nbCameraBoss_Kagu_MJINKO_Type = RandIntA;
          nbCameraBoss_Kagu_MJINKO_Set(pNbCamera);
          break;
        case 0xACu:
          if ((DDS3EFFECT_RAND_I() & 1) != 0)
          {
            nbCameraBoss_BSKAGU_EP_IT_Set(pNbCamera);
          }
          else
          {
            nbCameraBoss_Kagu_Attack_Set(pNbCamera);
          }
          break;
        default:
          return 0;
      }
      return 1;
    case 0x126u:
    case 0x127u:
    case 0x128u:
LABEL_28:
      if (v7 == 153)
      {
        return 1;
      }
      if (v7 == 191)
      {
        nbCameraBoss_Sp_PSYSTL_Set(pNbCamera);
        return 1;
      }
      if (v7 != 252)
        return 0;
      result = nbCameraBoss_Sp_MURET2_Set(pNbCamera);
      break;
    default:
      if (ID - 326 > 2 || v7)
        return 0;
      effBTLModelAllPopPosition();
      effBTLModelAllPopRotate();
      v11 = -12.5;
      v10 = 1.25;
      goto LABEL_145;
  }
  return result;
}

// 0xfcfeb0
s32 nbCameraBoss_Cut2_Ptr_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v7;
  u32 v8;
  s32 v10;
  char State;
  char BadStatus;
  u32 ID;
  u32 v16;
  u32 v17;
  u32 v18;
  u32 v19;
  u32 v20;
  u32 v21;
  u32 v22;
  u32 ptr_23;
  u32 v24;
  u32 v25;
  u32 v29;
  u32 v30;
  u32 v31;
  u32 TargetNumber;
  nbCameraSkillInfo_t_o *v35;
  u32 v36;
  nbCameraSkillInfo_t_o *v37;
  u32 v38;
  nbCameraSkillInfo_t_o *v39;
  u32 v40;
  nbCameraSkillInfo_t_o *v41;
  u32 v42;
  f32 v43;
  f32 v44;
  u32 v46;
  struct UnityEngine_Vector4_o *p_center;
  struct UnityEngine_Vector4_o *v52;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  TargetFormation = 0;
  else
  {
    MainProcessData = nbGetMainProcessData();
    if (!MainProcessData)
      return 0;
  }
  v7 = MainProcessData;
  v8 = effBTLSkillGetInvokeParty();
  if (v8 == effBTLSkillGetTargetParty())
    return 0;
  State = effBTLSkillGetState();
  pFormation = effBTLSkillGetInvokeFormation(0);
  BadStatus = effBTLModelGetBadStatus(&pFormation);
  ID = effBTLModelGetID(&pFormation);
  if (ID > 0x114)
  {
    if (ID <= 0x125)
    {
      switch (ID)
      {
        case 0x116u:
          if ((*pNBSInfo)->ptr_23 == 1)
          {
            if (effBTLSkillGetTargetNumber() >= 2)
            {
              nbCameraBoss_BSALBI_InvokeTargetParty_Set(pNbCamera);
            }
          }
          goto LABEL_161;
        case 0x11Fu:
          ptr_23 = (*pNBSInfo)->ptr_23;
          if (ptr_23 == 1)
            goto LABEL_115;
          if (ptr_23)
            goto LABEL_161;
          if (!(BadStatus & 0x40 | State & 0xC))
          {
            if ((DDS3EFFECT_RAND_I() & 1) != 0)
              goto LABEL_227;
          }
LABEL_115:
          nbCameraBoss_Samael_AKUI_Set(pNbCamera);
          break;
        case 0x123u:
          v24 = (*pNBSInfo)->ptr_23;
          if (v24 == 1)
            goto LABEL_126;
          if (v24)
            goto LABEL_161;
          if (BadStatus & 0x40 | State & 0xC)
            goto LABEL_126;
          if ((DDS3EFFECT_RAND_I() & 1) == 0)
            goto LABEL_126;
          goto LABEL_227;
        case 0x124u:
          goto LABEL_48;
        case 0x125u:
          v25 = (*pNBSInfo)->ptr_23;
          if (v25 == 1)
            goto LABEL_137;
          if (v25)
            goto LABEL_161;
          if (!(BadStatus & 0x40 | State & 0xC))
          {
            if ((DDS3EFFECT_RAND_I() & 1) != 0)
              goto LABEL_227;
          }
LABEL_137:
          nbCameraBoss_BSKAGU_EP_IT_Set(pNbCamera);
          break;
        default:
          goto LABEL_161;
      }
      return 1;
    }
    switch (ID)
    {
      case 0x141u:
        v16 = (*pNBSInfo)->ptr_23;
        if (v16 == 1)
          goto LABEL_153;
        if (v16)
          goto LABEL_161;
        if (BadStatus & 0x40 | State & 0xC)
        {
          if (effBTLSkillGetTargetNumber() == 1)
            goto LABEL_157;
        }
        else
        {
          if ((DDS3EFFECT_RAND_I() & 1) != 0)
            goto LABEL_227;
        }
LABEL_153:
        if (effBTLSkillGetTargetNumber() != 1)
          goto LABEL_161;
LABEL_157:
        nbCameraBoss_TargetInvoke_Set(pNbCamera, -5.0, 1.15);
        return 1;
      case 0x156u:
        v20 = (*pNBSInfo)->ptr_23;
        if (v20 == 1)
          goto LABEL_126;
        if (v20)
          goto LABEL_161;
        if (!(BadStatus & 0x40 | State & 0xC))
        {
          if ((DDS3EFFECT_RAND_I() & 1) != 0)
            goto LABEL_227;
        }
LABEL_126:
        nbCameraBoss_BSARI1_EP_IT_Set(pNbCamera);
        return 1;
      case 0x157u:
        v21 = (*pNBSInfo)->ptr_23;
        if (v21 == 1)
        {
          if (effBTLSkillGetTargetNumber() < 2)
            goto LABEL_161;
        }
        else
        {
          if (v21)
            goto LABEL_161;
          if (!(BadStatus & 0x40 | State & 0xC))
          {
            if ((DDS3EFFECT_RAND_I() & 1) != 0)
              goto LABEL_227;
          }
        }
        nbCameraBoss_BSBERU_EP_IT_Set(pNbCamera);
        return 1;
      case 0x158u:
        v22 = (*pNBSInfo)->ptr_23;
        if (v22 == 1)
          goto LABEL_104;
        if (v22)
          goto LABEL_161;
        if (!(BadStatus & 0x40 | State & 0xC))
        {
          if ((DDS3EFFECT_RAND_I() & 1) != 0)
            goto LABEL_227;
        }
LABEL_104:
        nbCameraBoss_BSLUSI_EP_IT_Set(pNbCamera);
        return 1;
      default:
        goto LABEL_161;
    }
  }
  if (ID > 0x103)
  {
    if (ID != 264)
    {
      if (ID == 276 && (*pNBSInfo)->ptr_23 == 10)
      {
LABEL_179:
        {
LABEL_180:
        }
        goto LABEL_314;
      }
      goto LABEL_161;
    }
    v19 = (*pNBSInfo)->ptr_23;
    if (v19 != 1)
    {
      if (v19)
        goto LABEL_161;
      if (!(BadStatus & 0x40 | State & 0xC))
      {
        if ((DDS3EFFECT_RAND_I() & 1) != 0)
          goto LABEL_227;
      }
    }
    nbCameraBoss_BSPISH_EP_IT_Set(pNbCamera);
    return 1;
  }
  if (ID == 258)
  {
    v18 = (*pNBSInfo)->ptr_23;
    if (v18 != 1)
    {
      if (v18)
        goto LABEL_161;
      if (!(BadStatus & 0x40 | State & 0xC))
      {
        if ((DDS3EFFECT_RAND_I() & 1) != 0)
          goto LABEL_227;
      }
    }
    nbCameraBoss_BSARI2_EP_IT_Set(pNbCamera);
    return 1;
  }
  if (ID != 259)
    goto LABEL_161;
LABEL_48:
  v17 = (*pNBSInfo)->ptr_23;
  if (v17 == 1)
  {
LABEL_55:
    nbCameraBoss_BSNET_EP_IT_Set(pNbCamera);
    return 1;
  }
  if (!v17)
  {
    if (BadStatus & 0x40 | State & 0xC)
      goto LABEL_55;
    if ((DDS3EFFECT_RAND_I() & 1) == 0)
      goto LABEL_55;
LABEL_227:
    TargetNumber = effBTLSkillGetTargetNumber();
    if (TargetNumber < 2)
    {
      {
LABEL_245:
      }
LABEL_247:
      nbCameraShot_Target_Set2(pNbCamera, pNBSInfo);
    }
    else
    {
      {
LABEL_232:
      }
LABEL_234:
      nbCameraShot_TargetParty_Set2(pNbCamera, pNBSInfo);
    }
    return 1;
  }
LABEL_161:
  if (effBTLModelCheckBossID(&pFormation))
  {
    if (effBTLModelGetHeight(&pFormation) > 500.0)
    {
      switch ((*pNBSInfo)->ptr_23)
      {
        case 0u:
          if (BadStatus & 0x40 | State & 0xC)
            goto LABEL_175;
          if ((DDS3EFFECT_RAND_I() & 1) == 0)
            goto LABEL_175;
          goto LABEL_227;
        case 1u:
LABEL_175:
          if (effBTLSkillGetTargetNumber() >= 2)
            goto LABEL_179;
          goto LABEL_216;
        case 9u:
        case 0xBu:
LABEL_216:
          nbCameraShot_BossTargetInvoke_Set(pNbCamera);
          return 1;
        case 0xAu:
          nbCameraShot_BossEX02_Set(pNbCamera);
          return 1;
        default:
          break;
      }
    }
  }
  if (!effBTLSkillGetTargetNumber())
    return 0;
  TargetFormation = effBTLSkillGetTargetFormation(0);
  v29 = effBTLModelGetID(&TargetFormation);
  if (v29 <= 0x108)
  {
    if (v29 == 258)
    {
      switch ((*pNBSInfo)->ptr_23)
      {
        case 0u:
        case 1u:
        case 2u:
          goto LABEL_309;
        case 9u:
          nbCameraBoss_BSARI2_Cut23_EX01_Set(pNbCamera);
          return 1;
        case 0xAu:
          nbCameraBoss_BSARI2_Cut23_EX02_Set(pNbCamera);
          return 1;
        case 0xBu:
          nbCameraBoss_BSARI2_Cut23_EX03_Set(pNbCamera);
          return 1;
        case 0xCu:
          v44 = 0.7;
          v43 = 10.0;
          goto LABEL_395;
        default:
          goto LABEL_330;
      }
    }
    if (v29 != 259)
    {
      if (v29 == 264)
      {
        switch ((*pNBSInfo)->ptr_23)
        {
          case 0u:
          case 1u:
          case 2u:
            goto LABEL_255;
          case 9u:
            nbCameraBoss_BSPISH_Cut23_EX01_Set(pNbCamera);
            return 1;
          case 0xAu:
            nbCameraBoss_BSPISH_Cut23_EX02_Set(pNbCamera);
            return 1;
          case 0xBu:
            nbCameraBoss_BSPISH_Cut23_EX03_Set(pNbCamera);
            return 1;
          case 0xCu:
            goto LABEL_269;
          default:
            goto LABEL_330;
        }
      }
      goto LABEL_330;
    }
LABEL_220:
    v31 = (*pNBSInfo)->ptr_23;
    if (v31 >= 3)
    {
      if (v31 == 12)
      {
LABEL_287:
        v44 = 0.55;
        v43 = 5.0;
LABEL_395:
        nbCameraBoss_InvokeTarget_Set(pNbCamera, v43, v44);
        return 1;
      }
      if (v31 == 10)
      {
        nbCameraBoss_BSNET1_Cut23_EX02_Set(pNbCamera);
        return 1;
      }
LABEL_330:
      if (effBTLModelCheckBossID(&TargetFormation))
      {
        if (effBTLModelGetHeight(&TargetFormation) > 500.0 && ((*pNBSInfo)->ptr_23 | 2) == 0xB)
        {
          nbCameraShot_AttackTuibi_Set(&nbCameraCurrent);
          return 1;
        }
      }
      return 0;
    }
LABEL_255:
      goto LABEL_318;
    goto LABEL_316;
  }
  switch (v29)
  {
    case 0x10Du:
      v30 = (*pNBSInfo)->ptr_23;
      if (v30 == 2)
        goto LABEL_205;
      if (v30 == 1)
        goto LABEL_210;
      if (v30)
        goto LABEL_330;
LABEL_205:
      if (BadStatus & 0x40 | State & 0xC)
        goto LABEL_210;
      if ((DDS3EFFECT_RAND_I() & 1) == 0)
      {
LABEL_210:
        if (effBTLSkillGetTargetNumber() > 1 || (v7->stat & 0x4000) != 0)
          goto LABEL_179;
        goto LABEL_255;
      }
      if (effBTLSkillGetTargetNumber() <= 1 && (v7->stat & 0x4000) == 0)
      {
          goto LABEL_247;
        goto LABEL_245;
      }
        goto LABEL_234;
      goto LABEL_232;
    case 0x11Fu:
      if ((*pNBSInfo)->HeightMin != 0.0)
        (*pNBSInfo)->HeightMin = 800.0;
      goto LABEL_330;
    case 0x123u:
      v35 = *pNBSInfo;
      if ((*pNBSInfo)->HeightMin == 0.0)
      {
        if (v35->WidthMin == 0.0)
        {
LABEL_252:
          v36 = v35->ptr_23;
          if (v36 > 0xC)
            goto LABEL_330;
LABEL_275:
          switch (v36)
          {
            case 0u:
            case 1u:
            case 2u:
              if (effBTLSkillGetTargetNumber() >= 2)
                goto LABEL_179;
              nbCameraBoss_InvokeTarget_Set(pNbCamera, -15.0, 0.5);
              effBTLModelInvokeGroupHide();
              break;
            case 8u:
              v44 = 0.55;
              v43 = -5.0;
              goto LABEL_395;
            case 9u:
              nbCameraBoss_BSARI1_Cut23_EX01_Set(pNbCamera);
              return 1;
            case 0xAu:
              nbCameraBoss_BSARI1_Cut23_EX02_Set(pNbCamera);
              return 1;
            case 0xBu:
              nbCameraBoss_BSARI1_Cut23_EX03_Set(pNbCamera);
              return 1;
            case 0xCu:
              goto LABEL_287;
            default:
              goto LABEL_330;
          }
          return 1;
        }
      }
      else
      {
        v35->HeightMin = 1000.0;
        v35 = *pNBSInfo;
        if ((*pNBSInfo)->WidthMin == 0.0)
          goto LABEL_252;
      }
      v35->WidthMin = 1000.0;
      v36 = (*pNBSInfo)->ptr_23;
      goto LABEL_275;
    case 0x124u:
      goto LABEL_220;
    case 0x125u:
      switch ((*pNBSInfo)->ptr_23)
      {
        case 0u:
        case 1u:
        case 2u:
          goto LABEL_255;
        case 9u:
        case 0xBu:
          nbCameraBoss_BSKAGU_Cut23_EX01_Set(pNbCamera);
          return 1;
        case 0xAu:
          nbCameraBoss_BSKAGU_Cut23_EX02_Set(pNbCamera);
          return 1;
        case 0xCu:
LABEL_269:
          v43 = 5.0;
          v44 = 1.0;
          goto LABEL_395;
        default:
          goto LABEL_330;
      }
    case 0x156u:
      v37 = *pNBSInfo;
      if ((*pNBSInfo)->HeightMin == 0.0)
      {
        if (v37->WidthMin == 0.0)
          goto LABEL_259;
      }
      else
      {
        v37->HeightMin = 1000.0;
        v37 = *pNBSInfo;
        if ((*pNBSInfo)->WidthMin == 0.0)
        {
LABEL_259:
          v38 = v37->ptr_23;
          if (v38 < 3)
            goto LABEL_309;
          goto LABEL_293;
        }
      }
      v37->WidthMin = 1000.0;
      v38 = (*pNBSInfo)->ptr_23;
      if (v38 < 3)
        goto LABEL_309;
LABEL_293:
      switch (v38)
      {
        case 0xBu:
          goto LABEL_425;
        case 0xAu:
          nbCameraBoss_BSMETA_Cut23_EX02_Set(pNbCamera);
          return 1;
        case 9u:
LABEL_425:
          nbCameraBoss_BSMETA_Cut23_EX01_Set(pNbCamera);
          return 1;
      }
      goto LABEL_330;
    case 0x157u:
      v39 = *pNBSInfo;
      if ((*pNBSInfo)->HeightMin == 0.0)
      {
        if (v39->WidthMin == 0.0)
          goto LABEL_263;
      }
      else
      {
        v39->HeightMin = 1000.0;
        v39 = *pNBSInfo;
        if ((*pNBSInfo)->WidthMin == 0.0)
        {
LABEL_263:
          v40 = v39->ptr_23;
          if (v40 >= 3)
          {
LABEL_302:
            if (v40 != 11)
            {
              if (v40 == 10)
              {
                nbCameraBoss_BSBERU_Cut23_EX02_Set(pNbCamera);
                return 1;
              }
              if (v40 != 9)
                goto LABEL_330;
            }
            nbCameraBoss_BSBERU_Cut23_EX01_Set(pNbCamera);
            return 1;
          }
          goto LABEL_309;
        }
      }
      v39->WidthMin = 1000.0;
      v40 = (*pNBSInfo)->ptr_23;
      if (v40 >= 3)
        goto LABEL_302;
LABEL_309:
      v46 = effBTLSkillGetTargetNumber();
      if (v46 < 2)
      {
          goto LABEL_318;
LABEL_316:
LABEL_318:
        nbCameraShot_InvokeTarget_Set2(pNbCamera, pNBSInfo);
        return 1;
      }
        goto LABEL_180;
LABEL_314:
      nbCameraShot_InvokeTargetParty_Set2(pNbCamera, pNBSInfo);
      return 1;
    case 0x158u:
      v41 = *pNBSInfo;
      if ((*pNBSInfo)->HeightMin != 0.0)
      {
        v41->HeightMin = 1000.0;
        v41 = *pNBSInfo;
        if ((*pNBSInfo)->WidthMin == 0.0)
          goto LABEL_267;
LABEL_320:
        v41->WidthMin = 1000.0;
        v42 = (*pNBSInfo)->ptr_23;
        goto LABEL_321;
      }
      if (v41->WidthMin != 0.0)
        goto LABEL_320;
LABEL_267:
      v42 = v41->ptr_23;
      if (v42 > 0xC)
        goto LABEL_330;
LABEL_321:
      switch (v42)
      {
        case 0u:
        case 1u:
        case 2u:
        case 8u:
        case 0xCu:
          p_center = &TargetFormation->center;
          sub_854710(&TargetFormation->center, 1u);
          sub_854930(p_center, 1u);
          if (effBTLSkillGetTargetNumber() < 2)
          {
            nbCameraBoss_InvokeTarget_Set(pNbCamera, -5.0, 0.25);
          }
          else
          {
            nbCameraShot_InvokeTargetParty_Set2(pNbCamera, pNBSInfo);
          }
          (*pNbCamera)->fovy = 0.87266;
          v52 = &TargetFormation->center;
          v10 = 1;
          sub_854710(&TargetFormation->center, 1u);
          sub_854930(v52, 1u);
          break;
        case 9u:
        case 0xBu:
          nbCameraBoss_BSLUSI_Cut23_EX01_Set(pNbCamera);
          return 1;
        case 0xAu:
          nbCameraBoss_BSLUSI_Cut23_EX02_Set(pNbCamera);
          return 1;
        default:
          goto LABEL_330;
      }
      return v10;
    default:
      goto LABEL_330;
  }
}

// 0xfd1310
s32 nbCameraBoss_Cut2_Ptr_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  return 0;
}

// 0xfc9540
s32 nbCameraBoss_Cut2_Run(nbCamera_t **pNbCamera) {
  u32 ID;
  u32 v6;
  s32 result;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  ID = effBTLModelGetID(&pFormation);
  v6 = effBTLSkillGetID();
  if (ID > 0x111)
  {
    if (ID <= 0x128)
    {
      switch (ID)
      {
        case 0x113u:
        case 0x126u:
        case 0x127u:
        case 0x128u:
          goto LABEL_28;
        case 0x11Fu:
          result = 1;
          if (!v6 || v6 == 165)
            return result;
          if (v6 != 242)
            return 0;
          goto LABEL_78;
        case 0x120u:
          if (v6 == 201)
            goto LABEL_78;
          return 0;
        case 0x123u:
          goto LABEL_46;
        case 0x124u:
          goto LABEL_52;
        case 0x125u:
          if (v6 != 241)
            return 0;
          nbCameraBoss_Kagu_MJINKO_Set(pNbCamera);
          return 1;
        default:
          return 0;
      }
    }
    if (ID - 326 < 3)
    {
      if (!v6)
        return 1;
    }
    else if (ID == 342)
    {
      if (v6 == 235)
      {
        nbCameraBoss_Meta_METAT1_1_Set(pNbCamera);
        return 1;
      }
    }
    else if (ID == 343)
    {
      if (v6 == 259)
      {
        nbCameraBoss_Beru_HAENO1_Set(pNbCamera);
        return 1;
      }
    }
    else if (ID == 344 && v6 == 272)
    {
      nbCameraBoss_Lusi_TWORLD_Set(pNbCamera);
      return 1;
    }
    return 0;
  }
  if (ID > 0x108)
  {
    if (ID == 269)
    {
      if (v6 == 233)
      {
        nbCameraBoss_Ongy_BUNSIN_Run(pNbCamera);
        return 1;
      }
    }
    else if (ID == 273)
    {
      goto LABEL_28;
    }
    return 0;
  }
  if (ID != 257)
  {
    if (ID == 258)
    {
LABEL_46:
      if (v6 == 168)
      {
        nbCameraBoss_BSARI_SIMANO_Run(pNbCamera);
      }
      else if (v6 == 253)
      {
        nbCameraBoss_BSARI_MASEHA_Run(pNbCamera);
      }
      return 1;
    }
    if (ID == 259)
    {
LABEL_52:
      if (v6 - 169 <= 1)
      {
LABEL_78:
      }
      return 1;
    }
    if (ID == 264 && v6 == 221)
    {
      nbCameraBoss_Pish_MUHENK_Run(pNbCamera);
      return 1;
    }
    return 0;
  }
LABEL_28:
  if (v6 == 153)
  {
    nbCameraBoss_Sp_JAREIH_Run(pNbCamera);
    return 1;
  }
  if (v6 != 252)
    return 0;
  return nbCameraBoss_Sp_MURET2_Run(pNbCamera);
}

// 0xfba5a0
void nbCameraBoss_Foru_E913_Run(void) {
  struct nbCamera_t_o *nbCameraCurrent;
  s16 v5;
  s32 v6;
  f32 v8;

  if ((v5 & 0x200) != 0)
  {
    v6 = v5 & 0x200;
  }
  else
  {
    v6 = 0;
  }
  v8 = fminf(Foru_E913_Frame / 190.0, 1.0);
  SDF_VU0__LOADVECTOR(Foru_E913_StartTarget);
  SDF_VU0__LOADVECTOR_B(Foru_E913_EndTarget);
  SDF_VU0__INTERPOLATE(v8);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
  SDF_VU0__LOADVECTOR(Foru_E913_StartDirection);
  SDF_VU0__LOADVECTOR_B(Foru_E913_EndDirection);
  SDF_VU0__INTERPOLATE(v8);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
  *&nbCameraCurrent->distance = 0x3F32B8C23F800000LL;
  ++Foru_E913_Frame;
}

// 0xfba500
void nbCameraBoss_Foru_E913_Set(void) {
  struct nbCamera_t_o *nbCameraCurrent;

  Foru_E913_Frame = 0;
  nbCameraCurrent->frame = 0;
}

// 0xfb9fa0
s32 nbCameraBoss_Foru_SIMON_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbFormation_t_o *TargetFormation;
  char State;
  nbCameraSkillInfo_t_o *v12;
  u32 stat;
  UnityEngine_Vector4_o v18;
  nbFormation_t_o *pFormation;
  nbCameraSkillInfo_t_o *pNBSInfo;

  pFormation = 0;
  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  *&v18.x = 0;
  *&v18.z = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  State = effBTLSkillGetState();
  if (State & 0xC | effBTLModelGetBadStatus(&pFormation) & 0x40)
    return 0;
  else if ((DDS3EFFECT_RAND_I() & 1) == 0)
  {
LABEL_14:
    effBTLModelAllShow();
    DDS3EFFECT_RAND_I();
    sub_854930(&(*pNbCamera)->fields, 0);
    sub_854930(&(*pNbCamera)->fields, 1u);
    sub_854930(&(*pNbCamera)->fields, 2u);
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
      goto LABEL_33;
    goto LABEL_29;
  }
  v12 = pNBSInfo;
  pNBSInfo->angleH = -0.2618;
  LODWORD(v12->angleW) = dword_32C3100[(DDS3EFFECT_RAND_I() & 1) == 0];
  *&v12->HeightMin = 0x43FA000000000000LL;
  nbCameraShot_TargetParty_Set2(pNbCamera, &pNBSInfo);
  {
LABEL_33:
    if (effBTLSkillGetTargetNumber())
      goto LABEL_34;
    return 1;
  }
LABEL_29:
    goto LABEL_33;
  if (effBTLSkillGetTargetNumber())
  {
LABEL_34:
    stat = TargetFormation->stat;
    effBTLModelGroupGetCenter(stat & 0x300);
    SDF_VU0__STOREVECTOR(&v18);
    effBTLModelLook(&pFormation, &v18);
  }
  return 1;
}

// 0xfb9460
void nbCameraBoss_InvokeTarget_Set(nbCamera_t **pNbCamera, f32 rotate, f32 ratio) {
  f32 v8;
  f32 v9;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v20;
  f32 v21;
  f32 Height;
  f32 v24;
  f32 v26;
  f32 v27;
  f32 v28;
  u32 ID;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  TargetFormation = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v32.x = 0;
  *&v32.z = 0;
  effBTLModelAllShow();
  effBTLSkillGetInvokeParty();
  pFormation = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  sub_854710(&pFormation->pos, 0);
  v9 = v8;
  sub_854710(&TargetFormation->pos, 0);
  v12 = flt_32C30F8[v9 > v11];
  (*pNbCamera)->fovy = 0.69813;
  v13 = v12 * rotate;
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&v32);
  sub_854710(&v32, 1u);
  sub_854930(&v32, 1u);
  effBTLModelGetSphereCenter(&TargetFormation);
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  sub_854930(&p, 1u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v32);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR(v32);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v15 = SDF_VU0__GETLENGTH();
  v16 = TargetFormation->r * TargetFormation->scl;
  v17 = v15 + (pFormation->r * pFormation->scl);
  v18 = v17 + v16;
  SetRotateMatrixY(v13);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v32);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  v20 = sdfFabs(v13);
  v21 = (v18 * sdfSin(v20)) * 1.15;
  Height = effBTLModelGetHeight(&pFormation);
  v24 = Height + ((pFormation->r * pFormation->scl) * -0.5);
  if (v24 > v21)
    v21 = v24;
  v26 = effBTLModelGetHeight(&TargetFormation);
  v27 = v26 + ((TargetFormation->r * pFormation->scl) * -0.5);
  if (v27 <= v21)
    v28 = v21;
  else
    v28 = v27;
  (*pNbCamera)->distance = (v28 * ratio) / sdfAtan(0.34907);
LABEL_33:
  ID = effBTLModelGetID(&TargetFormation);
  if (ID > 0x108)
  {
    if (ID - 291 <= 0x35 && ((1LL << (ID - 35)) & 0x38003800000007LL) != 0)
      goto LABEL_46;
  }
  else if (ID - 258 <= 6 && ((1 << (ID - 2)) & 0x43) != 0)
  {
    goto LABEL_46;
  }
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&v32);
  effBTLModelLook(&TargetFormation, &v32);
LABEL_46:
  nbCameraShot_GroundCollision(pNbCamera);
}

// 0xfc24d0
s32 nbCameraBoss_Kagu_Attack_Set(nbCamera_t **pNbCamera) {
  f32 v4;
  f32 v5;
  f32 v7;
  _BOOL4 v8;
  f32 v9;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v16;
  f32 v17;
  f32 Height;
  f32 v20;
  f32 v22;
  f32 v23;
  f32 v24;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v28;
  nbFormation_t_o *v29;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&v28.z = 0;
  v29 = 0;
  *&v28.x = 0;
  *&p.x = 0;
  *&p.z = 0;
  effBTLModelAllShow();
  effBTLSkillGetInvokeParty();
  pFormation = effBTLSkillGetTargetFormation(0);
  v29 = effBTLSkillGetInvokeFormation(0);
  sub_854710(&pFormation->pos, 0);
  v5 = v4;
  sub_854710(&v29->pos, 0);
  (*pNbCamera)->fovy = 0.69813;
  v8 = v5 > v7;
  v9 = flt_32C3110[v8];
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  sub_854930(&p, 1u);
  effBTLModelGetSphereCenter(&v29);
  SDF_VU0__STOREVECTOR(&v28);
  sub_854710(&v28, 1u);
  sub_854930(&v28, 1u);
  SDF_VU0__LOADVECTOR(v28);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v28);
  SDF_VU0__SUBVECTOR();
  v11 = SDF_VU0__GETLENGTH();
  v12 = v29->r * v29->scl;
  v13 = v11 + (pFormation->r * pFormation->scl);
  v14 = v13 + v12;
  SetRotateMatrixY(v9);
  SDF_VU0__LOADVECTOR(v28);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  v16 = sdfFabs(v9);
  v17 = (v14 * sdfSin(v16)) * 1.15;
  Height = effBTLModelGetHeight(&pFormation);
  v20 = Height + ((pFormation->r * pFormation->scl) * -0.5);
  if (v20 > v17)
    v17 = v20;
  v22 = effBTLModelGetHeight(&v29);
  v23 = v22 + ((v29->r * pFormation->scl) * -0.5);
  if (v23 <= v17)
    v24 = v17;
  else
    v24 = v23;
  (*pNbCamera)->distance = (v24 * 1.25) / sdfAtan(0.34907);
  nbCameraShot_GroundCollision(pNbCamera);
  return 1;
}

// 0xfc1d90
void nbCameraBoss_Kagu_E909_Run(void) {
  nbCamera_t_o *nbCameraCurrent;
  struct nbFormation_t_array *form;
  s32 frame;
  nbCamera_t_o *v8;
  nbCameraBoss_c *v11;
  s16 v12;
  s64 v14;
  f32 w;
  f32 z;
  s32 v20;
  f32 v22;
  nbCamera_t_o *v24;
  UnityEngine_Vector4_o v25;
  nbFormation_t_o *pFormation;
  nbCamera_t_o *pNbCamera;
  UnityEngine_Vector4_o v28;

  pFormation = 0;
  pNbCamera = 0;
  *&v25.x = 0;
  *&v25.z = 0;
  pNbCamera = nbCameraCurrent;
  form = nbGetMainProcessData()->form;
  pFormation = form->m_Items[4];
  frame = nbCameraCurrent->frame;
  if (frame)
  {
    if (frame == 135)
    {
      nbCameraBoss_BSKAGU_Command_Set(&pNbCamera);
      v8 = pNbCamera;
      SDF_VU0__COPYVECTOR(&Kagu_E909_EndTarget, pNbCamera->target);
      SDF_VU0__COPYVECTOR(&Kagu_E909_EndDirection, v8->direction);
      Kagu_E909_EndDistance = v8->distance;
      sub_854930(&Kagu_E909_StartDirection, 0);
      sub_854930(&Kagu_E909_StartDirection, 1u);
      sub_854930(&Kagu_E909_StartDirection, 2u);
      sub_854710(&Kagu_E909_StartDirection, 0);
      sub_854930(&Kagu_E909_StartTarget, 0);
      sub_854710(&Kagu_E909_StartDirection, 1u);
      sub_854930(&Kagu_E909_StartTarget, 1u);
      sub_854710(&Kagu_E909_StartDirection, 2u);
      sub_854930(&Kagu_E909_StartTarget, 2u);
      effBTLModelGetSphereCenter(&pFormation);
      SDF_VU0__STOREVECTOR(&v25);
      sub_854710(&v25, 0);
      sub_854710(&Kagu_E909_EndDirection, 0);
      sub_854930(&v25, 0);
      sub_854710(&v25, 1u);
      sub_854930(&v25, 1u);
      SDF_VU0__LOADVECTOR(v25);
      SDF_VU0__LOADVECTOR_B(Kagu_E909_StartTarget);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&Kagu_E909_StartDirection);
      Kagu_E909_StartDistance = 700.0;
      Kagu_E909_Frame = 0;
      Kagu_E909_Length = 70;
      v12 = *&v11->_2.bitflags1;
      if ((v12 & 0x200) == 0)
        goto LABEL_35;
    }
    else
    {
      if ((v12 & 0x200) == 0)
      {
LABEL_35:
        v20 = 0;
        goto LABEL_36;
      }
    }
  }
  else
  {
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__STOREVECTOR(&v25);
    v14 = *&v25.x;
    z = v25.z;
    w = v25.w;
    *&v28.x = v14;
    v28.z = z;
    v28.w = w;
    nbCameraShot_All_Set3(&pNbCamera, v28);
    nbCameraShot_GroundCollision(&pNbCamera);
    SDF_VU0__COPYVECTOR(&Kagu_E909_StartTarget, pNbCamera->target);
    SDF_VU0__COPYVECTOR(&Kagu_E909_StartDirection, pNbCamera->direction);
    Kagu_E909_StartDistance = pNbCamera->distance;
    sub_854930(&Kagu_E909_EndDirection, 0);
    sub_854930(&Kagu_E909_EndDirection, 1u);
    sub_854930(&Kagu_E909_EndDirection, 2u);
    sub_854710(&Kagu_E909_EndDirection, 0);
    sub_854930(&Kagu_E909_EndTarget, 0);
    sub_854710(&Kagu_E909_EndDirection, 1u);
    sub_854930(&Kagu_E909_EndTarget, 1u);
    sub_854710(&Kagu_E909_EndDirection, 2u);
    sub_854930(&Kagu_E909_EndTarget, 2u);
    Kagu_E909_EndDistance = 1.0;
    Kagu_E909_Frame = 0;
    Kagu_E909_Length = 120;
    v12 = *&v11->_2.bitflags1;
    if ((v12 & 0x200) == 0)
      goto LABEL_35;
  }
  v20 = v12 & 0x200;
LABEL_36:
  v22 = fminf(Kagu_E909_Frame / Kagu_E909_Length, 1.0);
  SDF_VU0__LOADVECTOR(Kagu_E909_StartTarget);
  SDF_VU0__LOADVECTOR_B(Kagu_E909_EndTarget);
  SDF_VU0__INTERPOLATE(v22);
  SDF_VU0__STOREVECTOR(&pNbCamera->target);
  SDF_VU0__LOADVECTOR(Kagu_E909_StartDirection);
  SDF_VU0__LOADVECTOR_B(Kagu_E909_EndDirection);
  SDF_VU0__INTERPOLATE(v22);
  SDF_VU0__STOREVECTOR(&pNbCamera->direction);
  v24 = pNbCamera;
  pNbCamera->distance = Kagu_E909_StartDistance
                             + (v22
                              * (Kagu_E909_EndDistance
                               - Kagu_E909_StartDistance));
  v24->fovy = 0.69813;
  ++Kagu_E909_Frame;
}

// 0xfc1d20
void nbCameraBoss_Kagu_E909_Set(void) {
  nbCameraCurrent->frame = 0;
}

// 0xfc28f0
s32 nbCameraBoss_Kagu_FLEACH_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v6;
  nbCamera_t_Fields *v7;

  effBTLModelAllShow();
  if (nbCameraBoss_Bskagu_Cut1_Direction == 1)
  {
    if (dds3GetRandIntA(2u, "") <= 1)
    {
LABEL_19:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v6 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v6, 1u);
      v7 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v7, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
    }
  }
  else
  {
    if (dds3GetRandIntA(2u, "") <= 1)
      goto LABEL_19;
  }
  return 1;
}

// 0xfc2ce0
s32 nbCameraBoss_Kagu_MJINKO_Set(nbCamera_t **pNbCamera) {
  nbCameraBoss_c *v4;
  u32 nbCameraBoss_Kagu_MJINKO_Type;
  char v7;
  f32 v8;
  nbCamera_t_Fields *v9;
  nbCamera_t_Fields *v10;
  nbCamera_t_Fields *v11;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v13;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;

  *&v18.x = 0;
  *&v18.z = 0;
  *&v17.x = 0;
  *&v17.z = 0;
  *&v16.x = 0;
  *&v16.z = 0;
  *&v15.x = 0;
  *&v15.z = 0;
  effBTLModelAllShow();
  if (!(*pNbCamera)->frame)
  {
    else
    {
      if (nbCameraBoss_Bskagu_Cut1_Direction == 1)
      {
LABEL_15:
        v7 = DDS3EFFECT_RAND_I();
        if ((v7 & 1) != 0)
        {
          nbCameraBoss_Kagu_MJINKO_Type = 1;
          if ((v4->_2.bitflags2 & 2) != 0)
            goto LABEL_8;
        }
        else
        {
          nbCameraBoss_Kagu_MJINKO_Type = 2;
          if ((v4->_2.bitflags2 & 2) != 0)
            goto LABEL_8;
        }
LABEL_9:
        if (nbCameraBoss_Kagu_MJINKO_Type != 2)
          goto LABEL_10;
LABEL_25:
        sub_854930(&(*pNbCamera)->direction, 0);
        sub_854930(&(*pNbCamera)->direction, 1u);
        sub_854930(&(*pNbCamera)->direction, 2u);
        p_fields = &(*pNbCamera)->fields;
        sub_854710(&(*pNbCamera)->direction, 0);
        sub_854930(p_fields, 0);
        v13 = &(*pNbCamera)->fields;
        sub_854710(&(*pNbCamera)->direction, 1u);
        sub_854930(v13, 1u);
        v11 = &(*pNbCamera)->fields;
        sub_854710(&(*pNbCamera)->direction, 2u);
        goto LABEL_26;
      }
    }
    else
    {
      nbCameraBoss_Kagu_MJINKO_Type = 0;
      if ((v4->_2.bitflags2 & 2) != 0)
        goto LABEL_8;
    }
    goto LABEL_9;
  }
    goto LABEL_9;
LABEL_8:
    goto LABEL_9;
  if (nbCameraBoss_Kagu_MJINKO_Type == 2)
    goto LABEL_25;
LABEL_10:
  if (nbCameraBoss_Kagu_MJINKO_Type <= 1)
  {
    v8 = fminf((*pNbCamera)->frame / 75.0, 1.0);
    sub_854930(&v18, 0);
    sub_854930(&v18, 1u);
    sub_854930(&v18, 2u);
    sub_854930(&v17, 0);
    sub_854930(&v17, 1u);
    sub_854930(&v17, 2u);
    sub_854930(&v16, 0);
    sub_854930(&v16, 1u);
    sub_854930(&v16, 2u);
    sub_854930(&v15, 0);
    sub_854930(&v15, 1u);
    sub_854930(&v15, 2u);
    SDF_VU0__LOADVECTOR(v18);
    SDF_VU0__LOADVECTOR_B(v17);
    SDF_VU0__INTERPOLATE(v8);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
    SDF_VU0__LOADVECTOR(v16);
    SDF_VU0__LOADVECTOR_B(v15);
    SDF_VU0__INTERPOLATE(v8);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
    v9 = &(*pNbCamera)->fields;
    sub_854710(v9, 0);
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(v9, 0);
    v10 = &(*pNbCamera)->fields;
    sub_854710(v10, 1u);
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v10, 1u);
    v11 = &(*pNbCamera)->fields;
    sub_854710(v11, 2u);
    sub_854710(&(*pNbCamera)->direction, 2u);
LABEL_26:
    sub_854930(v11, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfc7cd0
s32 nbCameraBoss_Lusi_ASIKIK_Set(nbCamera_t **pNbCamera) {
  s32 frame;
  f32 v4;
  UnityEngine_Vector4_o v6;
  UnityEngine_Vector4_o v7;

  *&v7.x = 0;
  *&v7.z = 0;
  *&v6.x = 0;
  *&v6.z = 0;
  frame = (*pNbCamera)->frame;
  if (!frame)
  {
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    frame = (*pNbCamera)->frame;
  }
  v4 = fminf(frame / 60.0, 1.0);
  sub_854930(&v7, 0);
  sub_854930(&v7, 1u);
  sub_854930(&v7, 2u);
  sub_854930(&v6, 0);
  sub_854930(&v6, 1u);
  sub_854930(&v6, 2u);
  SDF_VU0__LOADVECTOR(v7);
  SDF_VU0__LOADVECTOR_B(v6);
  SDF_VU0__INTERPOLATE(v4);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  sub_854930(&v7, 0);
  sub_854930(&v7, 1u);
  sub_854930(&v7, 2u);
  sub_854930(&v6, 0);
  sub_854930(&v6, 1u);
  sub_854930(&v6, 2u);
  SDF_VU0__LOADVECTOR(v7);
  SDF_VU0__LOADVECTOR_B(v6);
  SDF_VU0__INTERPOLATE(v4);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfc6d70
s32 nbCameraBoss_Lusi_Cut1_Set(nbCamera_t **pNbCamera) {
  s32 frame;
  f32 v4;
  f32 v6;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;

  *&v9.x = 0;
  *&v9.z = 0;
  *&v8.x = 0;
  *&v8.z = 0;
  frame = (*pNbCamera)->frame;
  if (!frame)
  {
    effBTLModelAllShow();
    frame = (*pNbCamera)->frame;
  }
  v4 = frame / 103.0;
  v6 = fminf(v4, 1.0);
  if (nbCameraBoss_BSLUSI_Type <= 1)
  {
    sub_854930(&v9, 0);
    sub_854930(&v9, 1u);
    sub_854930(&v9, 2u);
    sub_854930(&v8, 0);
    sub_854930(&v8, 1u);
    sub_854930(&v8, 2u);
    SDF_VU0__LOADVECTOR(v9);
    SDF_VU0__LOADVECTOR_B(v8);
    SDF_VU0__INTERPOLATE(v6);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
    sub_854930(&v9, 0);
    sub_854930(&v9, 1u);
    sub_854930(&v9, 2u);
    sub_854930(&v8, 0);
    sub_854930(&v8, 1u);
    sub_854930(&v8, 2u);
    SDF_VU0__LOADVECTOR(v9);
    SDF_VU0__LOADVECTOR_B(v8);
    SDF_VU0__INTERPOLATE(v6);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  }
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfc7840
s32 nbCameraBoss_Lusi_OHNOOH_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *v4;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;
  f32 v7;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v9;
  nbCamera_t_Fields *v10;

  effBTLModelAllShow();
  switch (dds3GetRandIntA(4u, ""))
  {
    case 0u:
    case 2u:
    case 3u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v9 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v9, 1u);
      v10 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v10, 2u);
      v7 = 0.7854;
      goto LABEL_12;
    case 1u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      v4 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(v4, 0);
      v5 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v5, 1u);
      v6 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v6, 2u);
      v7 = 0.69813;
LABEL_12:
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = v7;
      break;
    default:
      return 1;
  }
  return 1;
}

// 0xfc7150
s32 nbCameraBoss_Lusi_TWORLD_Set(nbCamera_t **pNbCamera) {
  s32 frame;
  s32 v4;
  f32 v5;
  f32 v6;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v8;
  nbCamera_t_Fields *v9;
  UnityEngine_Vector4_o v11;
  UnityEngine_Vector4_o v12;

  *&v12.x = 0;
  *&v12.z = 0;
  *&v11.x = 0;
  *&v11.z = 0;
  frame = (*pNbCamera)->frame;
  if (frame > 0x32)
  {
    v4 = frame - 51;
    if ((frame - 51) > 0x46)
      goto LABEL_5;
LABEL_13:
    v6 = fminf((v4 / 70.0) * (v4 / 70.0), 1.0);
    sub_854930(&v12, 0);
    sub_854930(&v12, 1u);
    sub_854930(&v12, 2u);
    sub_854930(&v11, 0);
    sub_854930(&v11, 1u);
    sub_854930(&v11, 2u);
    SDF_VU0__LOADVECTOR(v12);
    SDF_VU0__LOADVECTOR_B(v11);
    SDF_VU0__INTERPOLATE(v6);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
    sub_854930(&v12, 0);
    sub_854930(&v12, 1u);
    sub_854930(&v12, 2u);
    sub_854930(&v11, 0);
    sub_854930(&v11, 1u);
    sub_854930(&v11, 2u);
    SDF_VU0__LOADVECTOR(v12);
    SDF_VU0__LOADVECTOR_B(v11);
    SDF_VU0__INTERPOLATE(v6);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = ((v6 * -74.0) + 89.0) * 0.017453;
    if ((*pNbCamera)->frame != 140)
      return 1;
    goto LABEL_14;
  }
  if (!frame)
  {
    effBTLModelAllShow();
    frame = (*pNbCamera)->frame;
  }
  v5 = fminf(((frame / -50.0) + 1.0) * ((frame / -50.0) + 1.0), 1.0);
  sub_854930(&v12, 0);
  sub_854930(&v12, 1u);
  sub_854930(&v12, 2u);
  sub_854930(&v11, 0);
  sub_854930(&v11, 1u);
  sub_854930(&v11, 2u);
  SDF_VU0__LOADVECTOR(v12);
  SDF_VU0__LOADVECTOR_B(v11);
  SDF_VU0__INTERPOLATE(v5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  sub_854930(&v12, 0);
  sub_854930(&v12, 1u);
  sub_854930(&v12, 2u);
  sub_854930(&v11, 0);
  sub_854930(&v11, 1u);
  sub_854930(&v11, 2u);
  SDF_VU0__LOADVECTOR(v12);
  SDF_VU0__LOADVECTOR_B(v11);
  SDF_VU0__INTERPOLATE(v5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = ((v5 * -49.0) + 89.0) * 0.017453;
  frame = (*pNbCamera)->frame;
  v4 = frame - 51;
  if ((frame - 51) <= 0x46)
    goto LABEL_13;
LABEL_5:
  if (frame != 140)
    return 1;
LABEL_14:
  if (dds3GetRandIntA(2u, "") <= 1)
  {
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v8 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v8, 1u);
    v9 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v9, 2u);
  }
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.7854;
  return 1;
}

// 0xfc5310
s32 nbCameraBoss_Meta_METAT1_0_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v4;
  nbCamera_t_Fields *v5;

  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v4 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v4, 1u);
  v5 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v5, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfc5440
s32 nbCameraBoss_Meta_METAT1_1_Set(nbCamera_t **pNbCamera) {
  u32 RandIntA;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v7;
  nbCamera_t_Fields *v8;

  effBTLModelAllShow();
  if ((*pNbCamera)->frame == 11)
  {
    RandIntA = dds3GetRandIntA(3u, "");
    if (RandIntA == 2)
    {
      nbCameraBoss_BSARI1_EP_IT_Set(pNbCamera);
    }
    else if (RandIntA <= 1)
    {
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      p_fields = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(p_fields, 0);
      v7 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v7, 1u);
      v8 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      sub_854930(v8, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      return 1;
    }
  }
  return 1;
}

// 0xfbd830
s32 nbCameraBoss_Ongy_BUNSIN_Run(nbCamera_t **pNbCamera) {
  nbCamera_t_o *v4;
  s32 frame;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;

  *&v9.x = 0;
  *&v9.z = 0;
  *&v8.x = 0;
  *&v8.z = 0;
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  effBTLModelGroupGetSphere(0x200u);
  SDF_VU0__STOREVECTOR(&v8);
  sub_854710(&v8, 1u);
  sub_854930(&v8, 1u);
  SDF_VU0__LOADVECTOR(v8);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v9);
  SDF_VU0__SUBVECTOR();
  v4 = *pNbCamera;
  v4->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->fovy = 0.69813;
  frame = (*pNbCamera)->frame;
  SetRotateMatrixY(frame * -0.0021817);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  return 1;
}

// 0xfbd7c0
s32 nbCameraBoss_Ongy_BUNSIN_Set(nbCamera_t **pNbCamera) {
  nbCameraSetState(0);
  return 1;
}

// 0xfc38a0
s32 nbCameraBoss_Pish_MUHENK_Run(nbCamera_t **pNbCamera) {
  nbCameraBoss_c *v4;
  s32 nbCameraBoss_Pish_MUHENK_Type;
  s16 v7;
  s32 v8;
  s32 v9;
  f32 v10;
  s16 v11;
  s32 v12;
  s32 nbCameraBoss_Pish_MUHENK_Frame;
  UnityEngine_Vector4_o *v16;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;

  *&v20.x = 0;
  *&v20.z = 0;
  *&v19.x = 0;
  *&v19.z = 0;
  effBTLModelAllShow();
  if (nbCameraBoss_Pish_MUHENK_Type == 2)
    goto LABEL_23;
LABEL_9:
  if (nbCameraBoss_Pish_MUHENK_Type == 1)
  {
    v11 = *&v4->_2.bitflags1;
    if ((v11 & 0x200) != 0)
    {
      v12 = v11 & 0x200;
      if (nbCameraBoss_Pish_MUHENK_Frame <= 74)
      {
LABEL_19:
        if (v12)
          goto LABEL_20;
        goto LABEL_26;
      }
    }
    else
    {
      v12 = 0;
      if (nbCameraBoss_Pish_MUHENK_Frame <= 74)
        goto LABEL_19;
    }
    v10 = fminf((nbCameraBoss_Pish_MUHENK_Frame - 75) / 85.0, 1.0);
    sub_854930(&v20, 0);
    sub_854930(&v20, 1u);
    sub_854930(&v20, 2u);
    sub_854930(&v20, 3u);
    sub_854930(&v19, 0);
    sub_854930(&v19, 1u);
    sub_854930(&v19, 2u);
    sub_854930(&v19, 3u);
    SDF_VU0__LOADVECTOR(v20);
    SDF_VU0__LOADVECTOR_B(v19);
    SDF_VU0__INTERPOLATE(v10);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
    sub_854930(&v20, 0);
    sub_854930(&v20, 1u);
    sub_854930(&v20, 2u);
    sub_854930(&v20, 3u);
    goto LABEL_41;
  }
  if (!nbCameraBoss_Pish_MUHENK_Type)
  {
    v7 = *&v4->_2.bitflags1;
    if ((v7 & 0x200) != 0)
    {
      v8 = v7 & 0x200;
      v9 = nbCameraBoss_Pish_MUHENK_Frame;
      if (v9 <= 37)
        goto LABEL_13;
    }
    else
    {
      v8 = 0;
      v9 = nbCameraBoss_Pish_MUHENK_Frame;
      if (v9 <= 37)
      {
LABEL_13:
        v10 = fminf(v9 / 160.0, 1.0);
        sub_854930(&v20, 0);
        sub_854930(&v20, 1u);
        sub_854930(&v20, 2u);
        sub_854930(&v20, 3u);
        sub_854930(&v19, 0);
        sub_854930(&v19, 1u);
        sub_854930(&v19, 2u);
        sub_854930(&v19, 3u);
        SDF_VU0__LOADVECTOR(v20);
        SDF_VU0__LOADVECTOR_B(v19);
        SDF_VU0__INTERPOLATE(v10);
        SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
        sub_854930(&v20, 0);
        sub_854930(&v20, 1u);
        sub_854930(&v20, 2u);
        sub_854930(&v20, 3u);
        sub_854930(&v19, 0);
        sub_854930(&v19, 1u);
        goto LABEL_49;
      }
    }
    v10 = fminf((v9 - 38) / 122.0, 1.0);
    sub_854930(&v20, 0);
    sub_854930(&v20, 1u);
    sub_854930(&v20, 2u);
    sub_854930(&v20, 3u);
    sub_854930(&v19, 0);
    sub_854930(&v19, 1u);
    sub_854930(&v19, 2u);
    sub_854930(&v19, 3u);
    SDF_VU0__LOADVECTOR(v20);
    SDF_VU0__LOADVECTOR_B(v19);
    SDF_VU0__INTERPOLATE(v10);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
    sub_854930(&v20, 0);
    sub_854930(&v20, 1u);
    sub_854930(&v20, 2u);
    sub_854930(&v20, 3u);
LABEL_41:
    sub_854930(&v19, 0);
    sub_854930(&v19, 1u);
LABEL_49:
    sub_854930(&v19, 2u);
    v16 = &v19;
    goto LABEL_50;
  }
LABEL_51:
  ++nbCameraBoss_Pish_MUHENK_Frame;
  return 1;
}

// 0xfc37c0
s32 nbCameraBoss_Pish_MUHENK_Set(nbCamera_t **pNbCamera) {
  u8 RandIntA;

  effBTLModelAllShow();
  RandIntA = dds3GetRandIntA(3u, "");
  nbCameraBoss_Pish_MUHENK_Type = RandIntA;
  nbCameraBoss_Pish_MUHENK_Frame = 0;
  return 1;
}

// 0xfc3470
s32 nbCameraBoss_Pish_PRESS_Set(nbCamera_t **pNbCamera) {
  u32 RandIntA;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;
  nbCamera_t_Fields *v7;
  nbCamera_t_Fields *p_fields;

  effBTLModelAllShow();
  RandIntA = dds3GetRandIntA(3u, "");
  switch (RandIntA)
  {
    case 2u:
      goto LABEL_12;
    case 1u:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      sub_854930(&(*pNbCamera)->fields, 0);
      sub_854930(&(*pNbCamera)->fields, 1u);
      p_fields = &(*pNbCamera)->fields;
      goto LABEL_14;
    case 0u:
LABEL_12:
      sub_854930(&(*pNbCamera)->direction, 0);
      sub_854930(&(*pNbCamera)->direction, 1u);
      sub_854930(&(*pNbCamera)->direction, 2u);
      v5 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 0);
      sub_854930(v5, 0);
      v6 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 1u);
      sub_854930(v6, 1u);
      v7 = &(*pNbCamera)->fields;
      sub_854710(&(*pNbCamera)->direction, 2u);
      p_fields = v7;
LABEL_14:
      sub_854930(p_fields, 2u);
      (*pNbCamera)->distance = 1.0;
      (*pNbCamera)->fovy = 0.69813;
      break;
  }
  return 1;
}

// 0xfbe290
s32 nbCameraBoss_Samael_AKUI_Run(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfbe070
s32 nbCameraBoss_Samael_AKUI_Set(nbCamera_t **pNbCamera) {
  effBTLModelAllShow();
  nbResetAllFormPosRot();
  DDS3EFFECT_RAND_I();
  sub_854930(&(*pNbCamera)->fields, 0);
  sub_854930(&(*pNbCamera)->fields, 1u);
  sub_854930(&(*pNbCamera)->fields, 2u);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfbb900
s32 nbCameraBoss_Sp_DOUTYO_Run(nbCamera_t **pNbCamera) {
  struct effBezier4PPart_t_o *nbCamera_DOUTYO_B4P;
  struct effBezier4PPart_t_o *v7;
  nbCamera_t_o *v8;
  UnityEngine_Vector4_o v10;

  *&v10.x = 0;
  *&v10.z = 0;
  dds3Bezier4PPartRun(&nbCamera_DOUTYO_B4P, &v10);
  if (nbCamera_DOUTYO_B4P->weight > 0.75)
  {
    nbCamera_DOUTYO_B4P->step = nbCamera_DOUTYO_B4P->step * 0.965;
    v7 = nbCamera_DOUTYO_B4P;
    if (v7->step < 0.001)
    {
      v7->step = 0.0;
    }
  }
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v10);
  SDF_VU0__SUBVECTOR();
  v8 = *pNbCamera;
  v8->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  return 1;
}

// 0xfbbeb0
s32 nbCameraBoss_Sp_DOUTYO_Set(nbCamera_t **pNbCamera) {
  f32 v4;
  f32 v5;
  f32 v6;
  nbMainProcessData_t_o *MainProcessData;
  u64 v9;
  s32 v10;
  u32 v11;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v14;
  u32 stat;
  f32 v16;
  f32 v17;
  f32 Height;
  f32 v19;
  nbCamera_t_Fields *p_fields;
  struct nbFormation_t_array *v25;
  struct UnityEngine_Vector3_array *point;
  f32 v30;
  struct UnityEngine_Vector3_array *v32;
  f32 v33;
  struct UnityEngine_Vector3_array *v35;
  f32 v36;
  struct nbFormation_t_array *v39;
  f32 v41;
  f32 v42;
  struct UnityEngine_Vector3_array *v45;
  f32 v46;
  struct UnityEngine_Vector3_array *v48;
  f32 v49;
  struct UnityEngine_Vector3_array *v51;
  f32 v52;
  struct UnityEngine_Vector3_array *v54;
  f32 v55;
  struct UnityEngine_Vector3_array *v57;
  f32 v58;
  struct UnityEngine_Vector3_array *v60;
  f32 v61;
  struct UnityEngine_Vector3_array *v63;
  f32 v64;
  struct UnityEngine_Vector3_array *v66;
  f32 v67;
  struct UnityEngine_Vector3_array *v69;
  f32 v70;
  UnityEngine_Vector4_o v75;
  UnityEngine_Vector4_o v76;
  UnityEngine_Vector4_o v77;
  UnityEngine_Vector4_o v78;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v80;
  nbFormation_t_o *pFormation;

  *&v80.z = 0;
  pFormation = 0;
  *&p.z = 0;
  *&v80.x = 0;
  *&v76.x = 0;
  *&v78.z = 0;
  *&p.x = 0;
  *&v77.z = 0;
  *&v78.x = 0;
  *&v76.z = 0;
  *&v77.x = 0;
  *&v75.x = 0;
  *&v75.z = 0;
  effBTLModelAllShow();
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  MainProcessData = nbGetMainProcessData();
  v9 = 0;
  v10 = 0;
  v11 = 0;
  do
  {
    while (1)
    {
      form = MainProcessData->form;
      v14 = form->m_Items[v9];
      pFormation = v14;
      stat = v14->stat;
      if ((~stat & 0x201) != 0)
        break;
      v16 = v14->r * v14->scl;
      v17 = v16 + v16;
      v4 = v4 + v17;
      Height = effBTLModelGetHeight(&pFormation);
      if (v5 < Height)
        v5 = Height;
      ++v10;
      if (++v9 == 32)
        goto LABEL_28;
    }
    if ((~stat & 0x101) == 0)
    {
      v19 = effBTLModelGetHeight(&pFormation);
      if (v6 < v19)
        v6 = v19;
      ++v11;
    }
    ++v9;
  }
  while (v9 != 32);
LABEL_28:
  nbGetEnemyInterval();
  sub_854930(&(*pNbCamera)->fields, 0);
  sub_854930(&(*pNbCamera)->fields, 1u);
  p_fields = &(*pNbCamera)->fields;
  nbGetPartyDistance();
  sub_854930(p_fields, 2u);
  sdfAtan(0.5236);
  (*pNbCamera)->fovy = 0.69813;
  sub_854930(&v78, 0);
  sub_854930(&v78, 1u);
  nbGetPartyDistance();
  sub_854930(&v78, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v78);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__GETLENGTH();
  effBTLModelGroupGetSphere(0x100u);
  v25 = MainProcessData->form;
  else if (!LODWORD(v25->max_length))
  {
    goto LABEL_43;
  }
  effBTLModelGetSphereCenter(v25->m_Items);
  SDF_VU0__STOREVECTOR(&p);
  if (v11 <= 3)
    sub_854930(&p, 0);
  sub_854710(&(*pNbCamera)->fields, 1u);
  sub_854930(&p, 1u);
  sub_854930(&v77, 0);
  sub_854710(&v77, 0);
  sub_854930(&v77, 1u);
  sub_854930(&v77, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(v77);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v80);
  point = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 0);
  sub_8529B0(point->m_Items, 0, v30);
  v32 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 1u);
  sub_8529B0(v32->m_Items, 1, v33);
  v35 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 2u);
  sub_8529B0(v35->m_Items, 2, v36);
  v39 = MainProcessData->form;
  else if (!LODWORD(v39->max_length))
  {
    goto LABEL_58;
  }
  v41 = -effBTLModelGetHeight(v39->m_Items);
  sub_854710(&p, 1u);
  if (v42 > v41)
    sub_854930(&p, 1u);
  sub_854930(&v77, 0);
  sub_854710(&v77, 0);
  sub_854930(&v77, 1u);
  sub_854930(&v77, 2u);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v76);
  SDF_VU0__LOADVECTOR_B(v77);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v80);
  v45 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 0);
  sub_8529B0(&v45->m_Items[1], 0, v46);
  v48 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 1u);
  sub_8529B0(&v48->m_Items[1], 1, v49);
  v51 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 2u);
  sub_8529B0(&v51->m_Items[1], 2, v52);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(v78);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v75);
  SDF_VU0__LOADVECTOR_B(v76);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__LOADVECTOR_B(v77);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v80);
  v54 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 0);
  sub_8529B0(&v54->m_Items[2], 0, v55);
  v57 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 1u);
  sub_8529B0(&v57->m_Items[2], 1, v58);
  v60 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 2u);
  sub_8529B0(&v60->m_Items[2], 2, v61);
  SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(v78);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(v77);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v80);
  v63 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 0);
  sub_8529B0(&v63->m_Items[3], 0, v64);
  v66 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 1u);
  sub_8529B0(&v66->m_Items[3], 1, v67);
  v69 = nbCamera_DOUTYO_B4P->point;
  sub_854710(&v80, 2u);
  sub_8529B0(&v69->m_Items[3], 2, v70);
  nbCamera_DOUTYO_B4P->weight = 0.0;
  nbCamera_DOUTYO_B4P->step = 0.0125;
  nbCameraBoss_Sp_DOUTYO_Run(pNbCamera);
  return 1;
}

// 0xfbbd30
s32 nbCameraBoss_Sp_DOUTYO_TPFix_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v4;
  nbCamera_t_Fields *v5;

  nbCameraSetState(0x17u);
  sub_854930(&(*pNbCamera)->direction, 0);
  sub_854930(&(*pNbCamera)->direction, 1u);
  sub_854930(&(*pNbCamera)->direction, 2u);
  p_fields = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 0);
  sub_854930(p_fields, 0);
  v4 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 1u);
  sub_854930(v4, 1u);
  v5 = &(*pNbCamera)->fields;
  sub_854710(&(*pNbCamera)->direction, 2u);
  sub_854930(v5, 2u);
  (*pNbCamera)->distance = 1.0;
  (*pNbCamera)->fovy = 0.69813;
  return 1;
}

// 0xfbba70
s32 nbCameraBoss_Sp_DOUTYO_TP_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  u64 *v5;
  nbMainProcessData_t_o *MainProcessData;
  u64 v11;
  u32 v12;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v15;
  nbFormation_t_o *v16;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  else if (nbCamera_DOUTYO_B4P)
  {
    goto LABEL_11;
  }
  v5 = Allocate(effBezier4PPart_t);
  effBezier4PPart_t___ctor(v5);
  nbCamera_DOUTYO_B4P = v5;
  effBezier4PPart_t__Clear(nbCamera_DOUTYO_B4P);
LABEL_11:
  nbCameraSetState(0x17u);
  MainProcessData = nbGetMainProcessData();
  v11 = 0;
  v12 = 0;
  do
  {
    form = MainProcessData->form;
    v15 = form->m_Items[v11];
    if ((~v15->stat & 0x201) == 0)
      v12 |= 1 << v15->formindex;
    ++v11;
  }
  while (v11 != 32);
  v16 = effBTLSkillGetInvokeFormation(0);
  effBTLSkillSetFormationInfo(v16->formindex, v12);
  effBTLModelTargetGroupHide();
  *(v3 + 6) = 1058824618;
  *(v3 + 7) = dword_32C3108[(DDS3EFFECT_RAND_I() & 1) == 0];
  nbCameraShot_TargetParty_Set2(pNbCamera, &pNBSInfo);
  nbCameraShot_GroundCollision(pNbCamera);
  return 1;
}

// 0xfbca60
s32 nbCameraBoss_Sp_JAREIH_Cut1_Set(nbCamera_t **pNbCamera) {
  nbResetAllFormPosRot();
  return 0;
}

// 0xfbcae0
s32 nbCameraBoss_Sp_JAREIH_Run(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_o *v7;
  s32 frame;
  UnityEngine_Vector4_o v11;
  nbFormation_t_o *pFormation;
  nbCameraSkillInfo_t_o *pNBSInfo;

  pFormation = 0;
  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  *&v11.x = 0;
  *&v11.z = 0;
  if ((*pNbCamera)->frame >= 50)
  {
    nbCameraShot_All_Set2(pNbCamera, &pNBSInfo);
  }
  else
  {
    pFormation = effBTLSkillGetInvokeFormation(0);
    sub_854930(&v11, 0);
    sub_854930(&v11, 1u);
    sub_854930(&v11, 2u);
    effBTLModelGetSphereCenter(&pFormation);
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(p_fields, 1u);
    sub_854930(p_fields, 1u);
    SDF_VU0__LOADVECTOR((*pNbCamera)->target, 0);
    SDF_VU0__LOADVECTOR_B(v11);
    SDF_VU0__SUBVECTOR();
    v7 = *pNbCamera;
    v7->distance = SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
    (*pNbCamera)->fovy = 0.69813;
    frame = (*pNbCamera)->frame;
    SetRotateMatrixY(frame * -0.0087266);
    SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  }
  return 1;
}

// 0xfbcad0
s32 nbCameraBoss_Sp_JAREIH_Set(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfba730
s32 nbCameraBoss_Sp_MURET2_Run(nbCamera_t **pNbCamera) {
  struct effBezier4PPart_t_o *target;
  struct effBezier4PPart_t_o *eye;
  struct effBezier4PPart_t_o *v8;
  nbCamera_t_o *v9;
  UnityEngine_Vector4_o v10;
  UnityEngine_Vector4_o pOut;

  *&pOut.x = 0;
  *&pOut.z = 0;
  *&v10.x = 0;
  *&v10.z = 0;
  else if ((effBTLSkillGetState() & 0xC) != 0)
  {
    return 0;
  }
  nbCamera_MURET2_B4P->target->step = nbCamera_MURET2_B4P->target->step
                                                                     + nbCameraBoss_Sp_MURET2_Accele;
  nbCamera_MURET2_B4P->eye->step = nbCamera_MURET2_B4P->eye->step
                                                                  + nbCameraBoss_Sp_MURET2_Accele;
  target = nbCamera_MURET2_B4P->target;
  if (target->step > 0.014286)
  {
    target->step = 0.014286;
  }
  nbCamera_MURET2_B4P->eye->step = nbCamera_MURET2_B4P->target->step;
  eye = nbCamera_MURET2_B4P->eye;
  if (eye->weight > 0.75)
  {
    eye->step = eye->step * 0.965;
    v8 = nbCamera_MURET2_B4P->eye;
    if (v8->step < 0.001)
    {
      v8->step = 0.0;
    }
    nbCamera_MURET2_B4P->target->step = nbCamera_MURET2_B4P->eye->step;
  }
  dds3Bezier4PPartRun(&nbCamera_MURET2_B4P->eye, &v10);
  dds3Bezier4PPartRun(&nbCamera_MURET2_B4P->target, &pOut);
  SDF_VU0__LOADVECTOR(pOut);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v10);
  SDF_VU0__SUBVECTOR();
  v9 = *pNbCamera;
  v9->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  return 1;
}

// 0xfbaa30
s32 nbCameraBoss_Sp_MURET2_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  struct nbCameraBoss_B4P_tag_o *nbCamera_MURET2_B4P;
  u64 *v7;
  struct nbCameraBoss_B4P_tag_o *v8;
  u64 *v9;
  nbMainProcessData_t_o *MainProcessData;
  nbFormation_t_o *v15;
  f32 v16;
  f32 v17;
  u32 TargetBit;
  s32 v20;
  s64 i;
  struct nbFormation_t_array *form;
  f32 v24;
  f32 v25;
  f32 Height;
  f32 EnemyInterval;
  f32 v29;
  f32 v30;
  struct UnityEngine_Vector3_array *point;
  f32 z;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v43;
  struct UnityEngine_Vector3_array *v44;
  f32 v45;
  f32 v46;
  f32 v47;
  struct UnityEngine_Vector3_array *v49;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v56;
  struct UnityEngine_Vector3_array *v57;
  f32 v58;
  struct UnityEngine_Vector3_array *v60;
  f32 v62;
  f32 v63;
  f32 v64;
  f32 v65;
  f32 v67;
  struct UnityEngine_Vector3_array *v68;
  f32 v69;
  struct UnityEngine_Vector3_array *v71;
  f32 v73;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 v78;
  struct UnityEngine_Vector3_array *v79;
  f32 v80;
  struct UnityEngine_Vector3_array *v82;
  f32 v84;
  f32 v85;
  f32 v86;
  f32 v87;
  f32 v89;
  struct UnityEngine_Vector3_array *v90;
  f32 v91;
  struct UnityEngine_Vector3_array *v93;
  f32 v95;
  f32 v96;
  f32 v97;
  f32 v98;
  f32 v99;
  f32 v100;
  f32 v102;
  struct UnityEngine_Vector3_array *v103;
  f32 v104;
  struct UnityEngine_Vector3_array *v106;
  f32 v108;
  f32 v109;
  f32 v110;
  f32 v111;
  f32 v113;
  struct UnityEngine_Vector3_array *v114;
  f32 v115;
  struct UnityEngine_Vector3_array *v117;
  f32 v119;
  f32 v120;
  f32 v121;
  f32 v122;
  f32 v125;
  struct UnityEngine_Vector3_array *v126;
  f32 v127;
  s64 v129;
  f32 v130;
  u64 v131[2];
  UnityEngine_Vector4_o p;
  u64 v133[2];
  UnityEngine_Vector4_o v134;
  UnityEngine_Vector4_o v135;
  nbFormation_t_o *v136;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  *&v135.z = 0;
  v136 = 0;
  v130 = 0.0;
  v129 = 0;
  *&p.x = 0;
  *&v134.z = 0;
  *&v135.x = 0;
  v133[1] = 0;
  *&v134.x = 0;
  *&p.z = 0;
  v133[0] = 0;
  v131[0] = 0;
  v131[1] = 0;
  else if (nbCamera_MURET2_B4P)
  {
    goto LABEL_11;
  }
  v3 = Allocate(nbCameraBoss_B4P_tag);
  _ctor(v3, 0);
  nbCamera_MURET2_B4P = v3;
  v7 = Allocate(effBezier4PPart_t);
  effBezier4PPart_t___ctor(v7);
  nbCamera_MURET2_B4P->target = v7;
  v8 = nbCamera_MURET2_B4P;
  v9 = Allocate(effBezier4PPart_t);
  effBezier4PPart_t___ctor(v9);
  v8->eye = v9;
  effBezier4PPart_t__Clear(nbCamera_MURET2_B4P->target);
  effBezier4PPart_t__Clear(nbCamera_MURET2_B4P->eye);
LABEL_11:
  else if ((effBTLSkillGetState() & 0xC) != 0)
  {
    return 0;
  }
  effBTLModelAllHide();
  effBTLModelTargetPartyShow();
  effBTLModelInvokeShow();
  MainProcessData = nbGetMainProcessData();
  v15 = effBTLSkillGetInvokeFormation(0);
  v136 = 0;
  v16 = 0.0;
  v17 = 0.0;
  TargetBit = effBTLSkillGetTargetBit();
  v20 = 0;
  for (i = 8; i != 18; ++i)
  {
    form = MainProcessData->form;
    pFormation = *(&form->obj.klass + i);
    if (pFormation == v15 || ((1 << (i - 4)) & TargetBit) != 0)
    {
      v24 = pFormation->r * pFormation->scl;
      v25 = v24 + v24;
      Height = effBTLModelGetHeight(&pFormation);
      if (v17 < Height)
        v17 = Height;
      if (!v20)
        v136 = pFormation;
      v16 = v16 + v25;
      ++v20;
    }
  }
  EnemyInterval = nbGetEnemyInterval();
  v29 = (v20 - 1);
  v30 = v16 + (EnemyInterval * v29);
  sdfAtan(0.45379);
  sub_854930(v131, 0);
  sub_854930(v131, 1u);
  nbGetPartyDistance();
  sub_854930(v131, 2u);
  sub_854710(v131, 0);
  sub_854930(v133, 0);
  sub_854710(v131, 1u);
  sub_854930(v133, 1u);
  sub_854710(v131, 2u);
  sub_854930(v133, 2u);
  effBTLModelGetSphereCenter(&v136);
  SDF_VU0__STOREVECTOR(&p);
  sub_854930(&p, 1u);
  effBTLModelGetRadius(&v136);
  point = nbCamera_MURET2_B4P->eye->point;
  z = point->m_Items[0].z;
  v129 = *&point->m_Items[0].x;
  v130 = z;
  sub_854930(&v135, 0);
  sub_854930(&v135, 1u);
  sub_854930(&v135, 2u);
  SetRotateMatrixY(1.309);
  SDF_VU0__LOADVECTOR(v135);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v134);
  sub_854710(&v134, 0);
  sub_8529B0(&v129, 0, v39);
  sub_854710(&v134, 1u);
  sub_8529B0(&v129, 1, v40);
  sub_854710(&v134, 2u);
  sub_8529B0(&v129, 2, v41);
  sub_854710(&v134, 0);
  v43 = *(&v129 + 1);
  v44 = nbCamera_MURET2_B4P->eye->point;
  v45 = v130;
  v47 = v46;
  LODWORD(v44->m_Items[0].x) = v129;
  v44->m_Items[0].y = v43;
  v44->m_Items[0].z = v45;
  v49 = nbCamera_MURET2_B4P->eye->point;
  v51 = v49->m_Items[1].z;
  v129 = *&v49->m_Items[1].x;
  v130 = v51;
  sub_854930(&v135, 0);
  sub_854930(&v135, 1u);
  sub_854930(&v135, 2u);
  SetRotateMatrixY(1.0472);
  SDF_VU0__LOADVECTOR(v135);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v134);
  sub_854710(v133, 0);
  sub_8529B0(&v129, 0, v47 + ((v52 - v47) * 0.5));
  sub_854710(&v134, 1u);
  sub_8529B0(&v129, 1, v53);
  sub_854710(&v134, 2u);
  sub_8529B0(&v129, 2, v54);
  v56 = *(&v129 + 1);
  v57 = nbCamera_MURET2_B4P->eye->point;
  v58 = v130;
  LODWORD(v57->m_Items[1].x) = v129;
  v57->m_Items[1].y = v56;
  v57->m_Items[1].z = v58;
  v60 = nbCamera_MURET2_B4P->eye->point;
  v62 = v60->m_Items[2].z;
  v129 = *&v60->m_Items[2].x;
  v130 = v62;
  sub_854930(&v135, 0);
  sub_854930(&v135, 1u);
  sub_854930(&v135, 2u);
  SetRotateMatrixY(0.87266);
  SDF_VU0__LOADVECTOR(v135);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v134);
  sub_854710(v133, 0);
  sub_8529B0(&v129, 0, v47 + ((v63 - v47) * 0.83333));
  sub_854710(&v134, 1u);
  sub_8529B0(&v129, 1, v64);
  sub_854710(&v134, 2u);
  sub_8529B0(&v129, 2, v65);
  v67 = *(&v129 + 1);
  v68 = nbCamera_MURET2_B4P->eye->point;
  v69 = v130;
  LODWORD(v68->m_Items[2].x) = v129;
  v68->m_Items[2].y = v67;
  v68->m_Items[2].z = v69;
  v71 = nbCamera_MURET2_B4P->eye->point;
  v73 = v71->m_Items[3].z;
  v129 = *&v71->m_Items[3].x;
  v130 = v73;
  sub_854710(v133, 0);
  sub_8529B0(&v129, 0, v74);
  sub_854710(v133, 1u);
  sub_8529B0(&v129, 1, v75);
  sub_854710(v133, 2u);
  sub_8529B0(&v129, 2, v76);
  v78 = *(&v129 + 1);
  v79 = nbCamera_MURET2_B4P->eye->point;
  v80 = v130;
  LODWORD(v79->m_Items[3].x) = v129;
  v79->m_Items[3].y = v78;
  v79->m_Items[3].z = v80;
  v82 = nbCamera_MURET2_B4P->target->point;
  v84 = v82->m_Items[0].z;
  v129 = *&v82->m_Items[0].x;
  v130 = v84;
  sub_854710(&p, 0);
  sub_8529B0(&v129, 0, v85);
  sub_854710(&p, 1u);
  sub_8529B0(&v129, 1, v86);
  sub_854710(&p, 2u);
  sub_8529B0(&v129, 2, v87);
  v89 = *(&v129 + 1);
  v90 = nbCamera_MURET2_B4P->target->point;
  v91 = v130;
  LODWORD(v90->m_Items[0].x) = v129;
  v90->m_Items[0].y = v89;
  v90->m_Items[0].z = v91;
  v93 = nbCamera_MURET2_B4P->target->point;
  v95 = v93->m_Items[1].z;
  v129 = *&v93->m_Items[1].x;
  v130 = v95;
  sub_854710(&p, 0);
  v97 = v96;
  sub_854710(v131, 0);
  sub_8529B0(&v129, 0, ((v30 * 0.25) + (v97 + v98)) * 0.5);
  sub_854710(&p, 1u);
  sub_8529B0(&v129, 1, v99);
  sub_854710(&p, 2u);
  sub_8529B0(&v129, 2, v100);
  v102 = *(&v129 + 1);
  v103 = nbCamera_MURET2_B4P->target->point;
  v104 = v130;
  LODWORD(v103->m_Items[1].x) = v129;
  v103->m_Items[1].y = v102;
  v103->m_Items[1].z = v104;
  v106 = nbCamera_MURET2_B4P->target->point;
  v108 = v106->m_Items[2].z;
  v129 = *&v106->m_Items[2].x;
  v130 = v108;
  sub_854710(v131, 0);
  sub_8529B0(&v129, 0, (v30 * 0.25) + v109);
  sub_854710(&p, 1u);
  sub_8529B0(&v129, 1, v110);
  sub_854710(&p, 2u);
  sub_8529B0(&v129, 2, v111);
  v113 = *(&v129 + 1);
  v114 = nbCamera_MURET2_B4P->target->point;
  v115 = v130;
  LODWORD(v114->m_Items[2].x) = v129;
  v114->m_Items[2].y = v113;
  v114->m_Items[2].z = v115;
  v117 = nbCamera_MURET2_B4P->target->point;
  v119 = v117->m_Items[3].z;
  v129 = *&v117->m_Items[3].x;
  v130 = v119;
  sub_854710(v131, 0);
  sub_8529B0(&v129, 0, v120);
  sub_854710(v131, 1u);
  sub_8529B0(&v129, 1, v121);
  sub_854710(v131, 2u);
  sub_8529B0(&v129, 2, v122);
  v125 = *(&v129 + 1);
  v126 = nbCamera_MURET2_B4P->target->point;
  v127 = v130;
  LODWORD(v126->m_Items[3].x) = v129;
  v126->m_Items[3].y = v125;
  v126->m_Items[3].z = v127;
  nbCamera_MURET2_B4P->target->weight = 0.0;
  nbCamera_MURET2_B4P->target->step = 0.014286;
  nbCamera_MURET2_B4P->eye->weight = 0.0;
  nbCamera_MURET2_B4P->eye->step = 0.014286;
  nbCameraBoss_Sp_MURET2_Accele = 0.014286;
  nbCameraBoss_Sp_MURET2_Accele = nbCameraBoss_Sp_MURET2_Accele / 15.0;
  nbCamera_MURET2_B4P->target->step = nbCameraBoss_Sp_MURET2_Accele;
  nbCamera_MURET2_B4P->eye->step = nbCameraBoss_Sp_MURET2_Accele;
  nbCameraBoss_Sp_MURET2_Run(pNbCamera);
  return 1;
}

// 0xfbce20
s32 nbCameraBoss_Sp_PSYSTL_Run(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfbcd50
s32 nbCameraBoss_Sp_PSYSTL_Set(nbCamera_t **pNbCamera) {
  u64 *v3;
  nbCameraSkillInfo_t_o *pNBSInfo;

  v3 = Allocate(nbCameraSkillInfo_t);
  nbCameraSkillInfo_t___ctor(v3);
  pNBSInfo = v3;
  effBTLModelAllShow();
  nbCameraShot_InvokeTargetReverse_Set2(pNbCamera, &pNBSInfo);
  return 1;
}

// 0xfbe2a0
s32 nbCameraBoss_Sukady_DAIJIS_Set(nbCamera_t **pNbCamera) {
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v5;
  nbCamera_t_Fields *v6;

  effBTLModelAllShow();
  if (dds3GetRandIntA(3u, "") <= 2)
  {
    sub_854930(&(*pNbCamera)->direction, 0);
    sub_854930(&(*pNbCamera)->direction, 1u);
    sub_854930(&(*pNbCamera)->direction, 2u);
    p_fields = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 0);
    sub_854930(p_fields, 0);
    v5 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 1u);
    sub_854930(v5, 1u);
    v6 = &(*pNbCamera)->fields;
    sub_854710(&(*pNbCamera)->direction, 2u);
    sub_854930(v6, 2u);
    (*pNbCamera)->distance = 1.0;
    (*pNbCamera)->fovy = 0.69813;
  }
  return 1;
}

// 0xfb9a70
void nbCameraBoss_TargetInvoke_Set(nbCamera_t **pNbCamera, f32 rotate, f32 ratio) {
  f32 v8;
  f32 v9;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v20;
  f32 v21;
  f32 Height;
  f32 v24;
  f32 v26;
  f32 v27;
  f32 v28;
  u32 ID;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v34;
  nbFormation_t_o *pFormation;

  v34 = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v32.x = 0;
  *&v32.z = 0;
  effBTLModelAllShow();
  effBTLSkillGetInvokeParty();
  pFormation = effBTLSkillGetTargetFormation(0);
  v34 = effBTLSkillGetInvokeFormation(0);
  sub_854710(&pFormation->pos, 0);
  v9 = v8;
  sub_854710(&v34->pos, 0);
  v12 = flt_32C30F8[v9 > v11];
  (*pNbCamera)->fovy = 0.69813;
  v13 = v12 * rotate;
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&v32);
  sub_854710(&v32, 1u);
  sub_854930(&v32, 1u);
  effBTLModelGetSphereCenter(&v34);
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  sub_854930(&p, 1u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v32);
  SDF_VU0__INTERPOLATE(0.5);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR(v32);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v15 = SDF_VU0__GETLENGTH();
  v16 = v34->r * v34->scl;
  v17 = v15 + (pFormation->r * pFormation->scl);
  v18 = v17 + v16;
  SetRotateMatrixY(v13);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__LOADVECTOR_B(v32);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  v20 = sdfFabs(v13);
  v21 = (v18 * sdfSin(v20)) * 1.15;
  Height = effBTLModelGetHeight(&pFormation);
  v24 = Height + ((pFormation->r * pFormation->scl) * -0.5);
  if (v24 > v21)
    v21 = v24;
  v26 = effBTLModelGetHeight(&v34);
  v27 = v26 + ((v34->r * pFormation->scl) * -0.5);
  if (v27 <= v21)
    v28 = v21;
  else
    v28 = v27;
  (*pNbCamera)->distance = (v28 * ratio) / sdfAtan(0.34907);
LABEL_33:
  ID = effBTLModelGetID(&pFormation);
  if (ID > 0x108)
  {
    if (ID - 291 <= 0x35 && ((1LL << (ID - 35)) & 0x38003800000007LL) != 0)
      goto LABEL_46;
  }
  else if (ID - 258 <= 6 && ((1 << (ID - 2)) & 0x43) != 0)
  {
    goto LABEL_46;
  }
  effBTLModelGetSphereCenter(&v34);
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelLook(&pFormation, &p);
LABEL_46:
  nbCameraShot_GroundCollision(pNbCamera);
}

// 0xfd2d50
s32 nbCameraDANTE_DCOMBO_KAGU_Set(s32 frame) {
  struct nbCamera_t_o *nbCameraCurrent;
  UnityEngine_Vector4_o v6;
  UnityEngine_Vector4_o v7;

  *&v7.x = 0;
  *&v7.z = 0;
  *&v6.x = 0;
  *&v6.z = 0;
  if (frame <= 69)
    goto LABEL_9;
LABEL_6:
  if (frame == 70)
  {
    sub_854930(&nbCameraCurrent->direction, 0);
    sub_854930(&nbCameraCurrent->direction, 1u);
    sub_854930(&nbCameraCurrent->direction, 2u);
    sub_854710(&nbCameraCurrent->direction, 0);
    sub_854930(&nbCameraCurrent->fields, 0);
    sub_854710(&nbCameraCurrent->direction, 1u);
    sub_854930(&nbCameraCurrent->fields, 1u);
    sub_854710(&nbCameraCurrent->direction, 2u);
    sub_854930(&nbCameraCurrent->fields, 2u);
LABEL_10:
    *&nbCameraCurrent->distance = 0x3F32B8C23F800000LL;
  }
  return 1;
}

// 0xfd2b10
s32 nbCameraDANTE_DCOMBO_Set(s32 frame) {
  f32 v4;
  struct nbCamera_t_o *nbCameraCurrent;
  f32 v6;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;

  *&v9.x = 0;
  *&v9.z = 0;
  *&v8.x = 0;
  *&v8.z = 0;
  v4 = frame;
  v6 = fminf(v4 / 180.0, 1.0);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  SDF_VU0__LOADVECTOR(v9);
  SDF_VU0__LOADVECTOR_B(v8);
  SDF_VU0__INTERPOLATE(v6);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->target);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  SDF_VU0__LOADVECTOR(v9);
  SDF_VU0__LOADVECTOR_B(v8);
  SDF_VU0__INTERPOLATE(v6);
  SDF_VU0__STOREVECTOR(&nbCameraCurrent->direction);
  *&nbCameraCurrent->distance = 0x3F490FDB3F800000LL;
  return 1;
}

// 0xfd3090
s32 nbCameraDANTE_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u32 ID;
  char State;
  s32 result;
  u32 v12;
  u32 v14;
  nbFormation_t_o **p_TargetFormation;
  UnityEngine_Vector4_o *p_pPos;
  u32 v18;
  u32 v22;
  f32 v24;
  UnityEngine_Vector4_o pTargetPos;
  UnityEngine_Vector4_o pPos;
  nbFormation_t_o *TargetFormation;
  UnityEngine_Vector4_o v29;
  nbFormation_t_o *pFormation;

  *&v29.x = 0;
  *&v29.z = 0;
  pFormation = 0;
  TargetFormation = 0;
  sub_854690(&v29.x, 0.0, 0.0, 1.0, 0.0);
  *&pPos.x = 0;
  *&pPos.z = 0;
  *&pTargetPos.x = 0;
  *&pTargetPos.z = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  ID = effBTLModelGetID(&pFormation);
  if (ID - 339 < 3 || ID == 192)
  {
    State = effBTLSkillGetState();
    if (!(State & 0xC | effBTLModelGetBadStatus(&pFormation) & 0x40))
    {
      v12 = effBTLSkillGetID();
      result = 0;
      switch (v12)
      {
        case 0x107u:
          TargetFormation = effBTLSkillGetTargetFormation(0);
          effBTLModelTargetPartyShow();
          effBTLModelInvokeGroupHide();
          v14 = effBTLModelGetID(&TargetFormation);
          if (v14 == 259 || v14 == 342 || v14 == 292)
          {
            effBTLModelGetPosition(&pFormation, &pPos);
            p_TargetFormation = &TargetFormation;
            p_pPos = &pPos;
LABEL_79:
            effBTLModelLook(p_TargetFormation, p_pPos);
            return 1;
          }
          TargetFormation = effBTLSkillGetTargetFormation(0);
          effBTLModelGetPosition(&pFormation, &pPos);
          effBTLModelGetPosition(&TargetFormation, &pTargetPos);
          v22 = effBTLModelGetID(&TargetFormation);
          if (v22 > 0x108)
          {
            if (v22 - 291 > 0x35 || ((1LL << (v22 - 35)) & 0x38003800000007LL) == 0)
              goto LABEL_71;
          }
          else if (v22 - 258 > 6 || ((1 << (v22 - 2)) & 0x43) == 0)
          {
LABEL_71:
            effBTLModelLook2(&TargetFormation, &pPos, 0.087266);
          }
          SDF_VU0__LOADVECTOR(TargetFormation->rot);
          ToMatrix();
          SDF_VU0__LOADVECTOR(v29);
          SDF_VU0__APPLYMATRIX_XYZ();
          SDF_VU0__SCALEVECTOR(
            (TargetFormation->r * TargetFormation->scl) + (pFormation->cr * pFormation->scl),
            0);
          SDF_VU0__LOADVECTOR_B(pTargetPos);
          SDF_VU0__ADDVECTOR();
          sub_854710(&pPos, 1u);
          SDF_VU0__SETVECTOR_Y(v24);
          SDF_VU0__STOREVECTOR(&pPos);
          effBTLModelSetPosition(&pFormation, &pPos);
          p_TargetFormation = &pFormation;
          p_pPos = &pTargetPos;
          goto LABEL_79;
        case 0x108u:
          if (evtBitCheck(3712))
            return 0;
          goto LABEL_37;
        case 0x10Bu:
          effBTLModelTargetPartyShow();
          effBTLModelInvokeGroupHide();
          effBTLModelGetPosition(&pFormation, &pPos);
          sub_854710(&pPos, 2u);
          if ((pFormation->stat & 0x100) != 0)
            v18 = (pFormation->stat & 0x100) >> 7;
          else
            v18 = 2;
          sub_854930(&pPos, v18);
          effBTLModelSetPosition(&pFormation, &pPos);
          return 1;
        case 0x10Du:
LABEL_37:
          effBTLModelTargetPartyShow();
          effBTLModelInvokeGroupHide();
          return 1;
        default:
          return result;
      }
    }
  }
  return 0;
}

// 0xfd3840
s32 nbCameraDANTE_KAGIRI_Set(s32 frame) {
  struct nbCamera_t_o *nbCameraCurrent;
  nbFormation_t_o *v5;
  nbFormation_t_o *TargetFormation;

  if (!frame)
  {
    v5 = effBTLSkillGetInvokeFormation(0);
    TargetFormation = effBTLSkillGetTargetFormation(0);
    sub_854710(&v5->fields, 0);
    sub_854710(&TargetFormation->fields, 0);
    sub_854930(&nbCameraCurrent->direction, 0);
    sub_854930(&nbCameraCurrent->direction, 1u);
    sub_854930(&nbCameraCurrent->direction, 2u);
    sub_854710(&nbCameraCurrent->direction, 0);
    sub_854930(&nbCameraCurrent->fields, 0);
    sub_854710(&nbCameraCurrent->direction, 1u);
    sub_854930(&nbCameraCurrent->fields, 1u);
    sub_854710(&nbCameraCurrent->direction, 2u);
    sub_854930(&nbCameraCurrent->fields, 2u);
    *&nbCameraCurrent->distance = 0x3F490FDB3F800000LL;
  }
  return 1;
}

// 0xfd35f0
s32 nbCameraDANTE_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u32 ID;
  char State;
  s32 result;
  u32 v12;
  u32 v13;
  s32 frame;
  s32 v16;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  TargetFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  ID = effBTLModelGetID(&pFormation);
  if (ID - 339 >= 3 && ID != 192)
    return 0;
  State = effBTLSkillGetState();
  if (State & 0xC | effBTLModelGetBadStatus(&pFormation) & 0x40)
    return 0;
  v12 = effBTLSkillGetID();
  result = 0;
  switch (v12)
  {
    case 0x107u:
      v13 = effBTLModelGetID(&TargetFormation);
      if (v13 != 264 && v13 != 293)
      {
        if (v13 == 344)
        {
          frame = (*pNbCamera)->frame;
          nbCameraDANTE_DCOMBO_Set(frame);
        }
        goto LABEL_23;
      }
      v16 = (*pNbCamera)->frame;
      nbCameraDANTE_DCOMBO_KAGU_Set(v16);
      result = 1;
      break;
    case 0x108u:
      if (evtBitCheck(3712))
        return 0;
      goto LABEL_23;
    case 0x10Bu:
    case 0x10Du:
LABEL_23:
      result = 1;
      break;
    default:
      return result;
  }
  return result;
}

// 0xfd1320
s32 nbCameraHero_Cut1_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  nbMainProcessData_t_o *MainProcessData;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    if ((MainProcessData->stat & 8) != 0)
    {
      LODWORD(MainProcessData) = 0;
    }
    else
    {
      pFormation = effBTLSkillGetInvokeFormation(0);
      else if (effBTLModelGetID(&pFormation))
      {
LABEL_14:
        LODWORD(MainProcessData) = 0;
        return MainProcessData;
      }
      nbCameraHero_Cut_Frame = 0;
      if (!nbCameraHero_Cut2_Run(pNbCamera, pNBSInfo))
      {
        if ((*pNBSInfo)->ptr_1 != 6)
        {
          LODWORD(MainProcessData) = 0;
          return MainProcessData;
        }
        nbCameraShot_PullOne_Init(pNbCamera);
      }
      LODWORD(MainProcessData) = 1;
    }
  }
  return MainProcessData;
}

// 0xfd2700
s32 nbCameraHero_Cut1_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  nbMainProcessData_t_o *MainProcessData;
  s32 frame;
  struct datUnitMotion_s_array *motion;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    if ((MainProcessData->stat & 8) != 0)
    {
      LODWORD(MainProcessData) = 0;
    }
    else
    {
      pFormation = effBTLSkillGetInvokeFormation(0);
      else if (effBTLModelGetID(&pFormation))
      {
LABEL_14:
        LODWORD(MainProcessData) = 0;
        return MainProcessData;
      }
      if (!nbCameraHero_Cut2_Run(pNbCamera, pNBSInfo))
      {
        if ((*pNBSInfo)->ptr_1 != 6)
        {
          LODWORD(MainProcessData) = 0;
          return MainProcessData;
        }
        nbCameraShot_PullOne_Calc(pNbCamera, 0.45);
        frame = (*pNbCamera)->frame;
        motion = Get(0, 0)->motion;
        if (frame < motion->m_Items[12]->actframe)
        {
          SetRotateMatrixY(0.017453);
          SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
        }
      }
      LODWORD(MainProcessData) = 1;
    }
  }
  return MainProcessData;
}

// 0xfd2970
s32 nbCameraHero_Cut2_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  nbMainProcessData_t_o *MainProcessData;
  u32 ID;
  u32 v8;
  u32 v9;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  MainProcessData = nbGetMainProcessData();
  if (MainProcessData)
  {
    if ((MainProcessData->stat & 8) != 0)
    {
LABEL_14:
      LODWORD(MainProcessData) = 0;
      return MainProcessData;
    }
    pFormation = effBTLSkillGetInvokeFormation(0);
    else if (effBTLModelGetID(&pFormation))
    {
      goto LABEL_14;
    }
    ID = effBTLSkillGetID();
    if (ID > 0x90)
    {
      if (ID > 0xA1)
      {
        LODWORD(MainProcessData) = ID == 163;
      }
      else
      {
        v8 = ID - 147;
        if (v8 > 0xE)
          goto LABEL_14;
        LODWORD(MainProcessData) = 1;
        if (((1 << v8) & 0x6001) == 0)
          goto LABEL_14;
      }
    }
    else if (ID > 0x85)
    {
      v9 = ID - 136;
      if (v9 > 8)
        goto LABEL_14;
      LODWORD(MainProcessData) = 1;
      if (((1 << v9) & 0x181) == 0)
        goto LABEL_14;
    }
    else
    {
      LODWORD(MainProcessData) = 1;
      if (ID != 131 && ID != 133)
        goto LABEL_14;
    }
  }
  return MainProcessData;
}

// 0xfd14d0
s32 nbCameraHero_Cut2_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
  u32 TargetParty;
  u8 *MainProcessData;
  u8 *v9;
  u32 v16;
  s32 nbCameraHero_Cut_Frame;
  u32 RandIntA;
  u32 ID;
  char v31;
  s64 v32;
  f32 v36;
  f32 Sphere;
  f32 GroupMaxHeight;
  f32 v45;
  s32 v46;
  struct UnityEngine_Vector4_o *p_target;
  f32 v53;
  f32 v55;
  nbCamera_t_Fields *v58;
  nbCamera_t_Fields *v59;
  nbCamera_t_Fields *v60;
  nbCamera_t_Fields *p_fields;
  nbCamera_t_Fields *v62;
  nbCamera_t_Fields *v63;
  UnityEngine_Vector4_o v65;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  TargetFormation = 0;
  pFormation = 0;
  *&v65.x = 0;
  *&v65.z = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  TargetParty = effBTLSkillGetTargetParty();
  MainProcessData = nbGetMainProcessData();
  if (!MainProcessData)
    return MainProcessData;
  v9 = MainProcessData;
  if ((MainProcessData[124] & 8) != 0)
  {
LABEL_14:
    LODWORD(MainProcessData) = 0;
    return MainProcessData;
  }
  else if (effBTLModelGetID(&pFormation))
  {
    goto LABEL_14;
  }
  if ((effBTLSkillGetState() & 0xC) != 0 || (v9[125] & 0x40) != 0)
  {
    if (nbCameraCurrent->state != 7)
    {
      LODWORD(MainProcessData) = 1;
      if ((*pNbCamera)->frame)
        return MainProcessData;
      (*pNBSInfo)->ptr_23 = 1;
      (*pNBSInfo)->shot_23 = 1;
      if (nbCameraBoss_Cut2_Ptr_Init(pNbCamera, pNBSInfo))
      {
        effBTLModelAllShow();
        effBTLModelInvokeGroupHide();
      }
      else
      {
        nbCameraShot_InvokeTargetParty_Set2(pNbCamera, pNBSInfo);
      }
      nbCameraShot_GroundCollision(pNbCamera);
      if (effBTLSkillGetTargetNumber() != 1)
        goto LABEL_253;
      ID = effBTLModelGetID(&pFormation);
      if (ID > 0x108)
      {
        if (ID - 291 <= 0x35 && ((1LL << (ID - 35)) & 0x38003800000007LL) != 0)
          goto LABEL_253;
      }
      else
      {
        v31 = ID - 2;
        if (ID - 258 <= 6)
        {
          LODWORD(MainProcessData) = 1;
          if (((1 << v31) & 0x43) != 0)
            return MainProcessData;
        }
      }
      TargetFormation = effBTLSkillGetTargetFormation(0);
      effBTLModelGetSphereCenter(&TargetFormation);
      SDF_VU0__STOREVECTOR(&v65);
      effBTLModelLook(&pFormation, &v65);
      goto LABEL_253;
    }
  }
  v16 = effBTLSkillGetID();
  nbCameraHero_Cut_Frame = nbCameraHero_Cut_Frame + 1;
  if (v16 > 0x88)
  {
    LODWORD(MainProcessData) = 0;
    switch (v16)
    {
      case 0x8Fu:
        if (!nbCameraHero_Cut_Frame)
          goto LABEL_117;
        if (nbCameraHero_Cut_Frame <= 40)
          goto LABEL_121;
        if (nbCameraHero_Cut_Frame != 41)
          goto LABEL_253;
        goto LABEL_105;
      case 0x90u:
        if (!nbCameraHero_Cut_Frame)
          goto LABEL_117;
        if (nbCameraHero_Cut_Frame <= 86)
          goto LABEL_121;
        if (nbCameraHero_Cut_Frame == 87)
          goto LABEL_105;
        goto LABEL_253;
      case 0x93u:
        if (nbCameraHero_Cut_Frame)
        {
          if (nbCameraHero_Cut_Frame > 86)
          {
            if (nbCameraHero_Cut_Frame == 87)
              goto LABEL_132;
            goto LABEL_253;
          }
        }
        else
        {
          nbCameraShot_PullOne_Init(pNbCamera);
        }
        v36 = 0.35;
        goto LABEL_248;
      case 0xA0u:
        if (nbCameraHero_Cut_Frame)
        {
          if (nbCameraHero_Cut_Frame > 39)
          {
            if (nbCameraHero_Cut_Frame != 40)
              goto LABEL_253;
LABEL_132:
            if (nbCameraCurrent->state == 7)
              goto LABEL_253;
            nbCameraBoss_InvokeTarget_Set(pNbCamera, -25.0, 0.6);
            goto LABEL_140;
          }
        }
        else
        {
          nbCameraShot_PullOne_Init(pNbCamera);
        }
        v36 = 0.45;
        goto LABEL_248;
      case 0xA1u:
        if (nbCameraHero_Cut_Frame)
        {
          if (nbCameraHero_Cut_Frame > 49)
          {
            if (nbCameraHero_Cut_Frame != 50)
              goto LABEL_253;
            if (nbCameraCurrent->state == 7)
              goto LABEL_253;
            (*pNBSInfo)->shot_23 = 15;
            (*pNBSInfo)->ptr_23 = 11;
            if (!nbCameraBoss_Cut2_Ptr_Init(pNbCamera, pNBSInfo))
            {
              nbCameraShot_InvokeTargetNear_Set(pNbCamera, pNBSInfo);
              goto LABEL_144;
            }
            goto LABEL_140;
          }
        }
        else
        {
          nbCameraShot_PullOne_Init(pNbCamera);
        }
        v36 = 0.5;
        goto LABEL_248;
      case 0xA3u:
        if (nbCameraHero_Cut_Frame)
        {
          if (nbCameraHero_Cut_Frame > 49)
          {
            if (nbCameraHero_Cut_Frame != 50)
              goto LABEL_253;
            if (nbCameraCurrent->state == 7)
              goto LABEL_253;
            Sphere = effBTLModelGroupGetSphere(TargetParty);
            GroupMaxHeight = effBTLModelGetGroupMaxHeight(TargetParty);
            v45 = GroupMaxHeight;
            v46 = nbCameraBoss_CheckFix();
            if (v45 < 500.0 && Sphere <= 700.0 && v46)
            {
              effBTLModelAllShow();
              effBTLModelInvokeGroupHide();
              if ((DDS3EFFECT_RAND_I() & 1) != 0)
              {
                DDS3EFFECT_RAND_I();
                sub_854930(&(*pNbCamera)->direction, 0);
                sub_854930(&(*pNbCamera)->direction, 1u);
                sub_854930(&(*pNbCamera)->direction, 2u);
                p_fields = &(*pNbCamera)->fields;
                sub_854710(&(*pNbCamera)->direction, 0);
                sub_854930(p_fields, 0);
                v62 = &(*pNbCamera)->fields;
                sub_854710(&(*pNbCamera)->direction, 1u);
                sub_854930(v62, 1u);
                v63 = &(*pNbCamera)->fields;
                sub_854710(&(*pNbCamera)->direction, 2u);
                p_target = &v63->target;
              }
              else
              {
                sub_854710(&pFormation->fields, 0);
                sub_854930(&(*pNbCamera)->fields, 0);
                sub_854930(&(*pNbCamera)->fields, 1u);
                sub_854930(&(*pNbCamera)->fields, 2u);
                sub_854930(&(*pNbCamera)->direction, 0);
                sub_854930(&(*pNbCamera)->direction, 1u);
                p_target = &(*pNbCamera)->direction;
              }
              sub_854930(p_target, 2u);
              (*pNbCamera)->distance = 1.0;
              (*pNbCamera)->fovy = 0.69813;
                goto LABEL_145;
LABEL_147:
              nbCameraShot_GroundCollision(pNbCamera);
              goto LABEL_253;
            }
            (*pNBSInfo)->shot_23 = 5;
            (*pNBSInfo)->ptr_23 = 10;
            if (!nbCameraBoss_Cut2_Ptr_Init(pNbCamera, pNBSInfo))
            {
              nbCameraShot_InvokeTargetPartyTop_Set(pNbCamera, pNBSInfo);
              goto LABEL_144;
            }
            goto LABEL_140;
          }
        }
        else
        {
          nbCameraShot_PullOne_Init(pNbCamera);
        }
        v36 = 0.15;
        goto LABEL_248;
      default:
        return MainProcessData;
    }
  }
  if (v16 != 131)
  {
    if (v16 != 133)
    {
      if (v16 != 136)
        goto LABEL_14;
      if (nbCameraHero_Cut_Frame)
      {
        if (nbCameraHero_Cut_Frame > 75)
        {
          if (nbCameraHero_Cut_Frame != 76)
            goto LABEL_253;
          goto LABEL_132;
        }
      }
      else
      {
LABEL_117:
        nbCameraShot_PullOne_Init(pNbCamera);
      }
LABEL_121:
      v36 = 0.25;
LABEL_248:
      nbCameraShot_PullOne_Calc(pNbCamera, v36);
      v55 = 0.0061087;
LABEL_252:
      SetRotateMatrixY(v55);
      SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
      goto LABEL_253;
    }
    if (nbCameraHero_Cut_Frame)
    {
      if (nbCameraHero_Cut_Frame > 53)
      {
        if (nbCameraHero_Cut_Frame != 54)
          goto LABEL_253;
        if (nbCameraCurrent->state == 7)
          goto LABEL_253;
        RandIntA = dds3GetRandIntA(3u, "");
        if (RandIntA != 2)
        {
          if (RandIntA == 1)
          {
            (*pNBSInfo)->shot_23 = 5;
            (*pNBSInfo)->ptr_23 = 10;
            if (!nbCameraBoss_Cut2_Ptr_Init(pNbCamera, pNBSInfo))
            {
              nbCameraShot_InvokeTargetPartyTop_Set(pNbCamera, pNBSInfo);
              goto LABEL_253;
            }
          }
          else
          {
            if (RandIntA)
            {
LABEL_253:
              LODWORD(MainProcessData) = 1;
              return MainProcessData;
            }
            (*pNBSInfo)->shot_23 = 1;
            (*pNBSInfo)->ptr_23 = 1;
            if (!nbCameraBoss_Cut2_Ptr_Init(pNbCamera, pNBSInfo))
            {
              (*pNbCamera)->frame = 0;
              nbCameraShot_InvokeTargetParty_Set2(pNbCamera, pNBSInfo);
              goto LABEL_253;
            }
          }
          effBTLModelAllShow();
          effBTLModelInvokeGroupHide();
          goto LABEL_253;
        }
        if (nbCameraBoss_CheckFix())
        {
          effBTLModelAllShow();
          effBTLModelInvokeGroupHide();
          sub_854930(&(*pNbCamera)->direction, 0);
          sub_854930(&(*pNbCamera)->direction, 1u);
          sub_854930(&(*pNbCamera)->direction, 2u);
          v58 = &(*pNbCamera)->fields;
          sub_854710(&(*pNbCamera)->direction, 0);
          sub_854930(v58, 0);
          v59 = &(*pNbCamera)->fields;
          sub_854710(&(*pNbCamera)->direction, 1u);
          sub_854930(v59, 1u);
          v60 = &(*pNbCamera)->fields;
          sub_854710(&(*pNbCamera)->direction, 2u);
          sub_854930(v60, 2u);
          (*pNbCamera)->distance = 1.0;
          (*pNbCamera)->fovy = 0.69813;
          goto LABEL_144;
        }
        (*pNBSInfo)->shot_23 = 1;
        (*pNBSInfo)->ptr_23 = 1;
          goto LABEL_112;
LABEL_110:
LABEL_112:
        if (!nbCameraBoss_Cut2_Ptr_Init(pNbCamera, pNBSInfo))
        {
          (*pNbCamera)->frame = 0;
          nbCameraShot_InvokeTargetParty_Set2(pNbCamera, pNBSInfo);
LABEL_144:
          {
LABEL_145:
          }
          goto LABEL_147;
        }
LABEL_140:
        effBTLModelAllShow();
        effBTLModelInvokeGroupHide();
        goto LABEL_144;
      }
    }
    else
    {
      nbCameraShot_PullOne_Init(pNbCamera);
    }
    v53 = 0.25;
LABEL_212:
    nbCameraShot_PullOne_Calc(pNbCamera, v53);
    v55 = 0.0087266;
    goto LABEL_252;
  }
  if (!nbCameraHero_Cut_Frame)
  {
    nbCameraShot_PullOne_Init(pNbCamera);
    goto LABEL_200;
  }
  if (nbCameraHero_Cut_Frame <= 57)
  {
LABEL_200:
    v53 = 0.1;
    goto LABEL_212;
  }
  if (nbCameraHero_Cut_Frame != 58)
    goto LABEL_253;
LABEL_105:
  v32 = *(MainProcessData + 23);
  LODWORD(MainProcessData) = 1;
  if (*(*v32 + 60LL) != 7)
  {
    (*pNBSInfo)->shot_23 = 1;
    (*pNBSInfo)->ptr_23 = 1;
      goto LABEL_112;
    goto LABEL_110;
  }
  return MainProcessData;
}

// 0xfc82e0
s32 nbCameraShot_BossEX02_Set(nbCamera_t **pNbCamera) {
  u32 TargetParty;
  f32 v6;
  f32 v8;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v12;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v14;

  *&v14.x = 0;
  *&v14.z = 0;
  pFormation = 0;
  sub_854690(&v14.x, 1.0, 0.0, 0.0, 0.0);
  *&v12.x = 0;
  *&v12.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  effBTLModelAllShow();
  TargetParty = effBTLSkillGetTargetParty();
  effBTLModelGroupGetSphere(TargetParty);
  SDF_VU0__STOREVECTOR(&p);
  sub_854930(&p, 1u);
  pFormation = effBTLSkillGetInvokeFormation(0);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&v12);
  effBTLModelGetHeight(&pFormation);
  sub_854930(&v12, 1u);
  SDF_VU0__LOADVECTOR(v12);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__SUBVECTOR();
  v6 = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR_B(v14);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__INTERPOLATE(0.35);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  SDF_VU0__LOADVECTOR(v12);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__INTERPOLATE(0.7);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  (*pNbCamera)->fovy = 0.69813;
  v8 = sdfAtan(0.49567);
  (*pNbCamera)->distance = (v6 * 0.5) / v8;
  (*pNbCamera)->distance = (*pNbCamera)->distance
                                + fmaxf(effBTLModelGroupGetSphere(TargetParty) / v8, 1100.0);
  nbCameraShot_GroundCollision(pNbCamera);
  return 1;
}

// 0xfc7f40
s32 nbCameraShot_BossTargetInvoke_Set(nbCamera_t **pNbCamera) {
  f32 v4;
  nbCamera_t_o *v5;
  u32 ID;
  UnityEngine_Vector4_o v11;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;

  TargetFormation = 0;
  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v11.x = 0;
  *&v11.z = 0;
  effBTLModelAllShow();
  pFormation = effBTLSkillGetInvokeFormation(0);
  TargetFormation = effBTLSkillGetTargetFormation(0);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelGetSphereCenter(&TargetFormation);
  SDF_VU0__STOREVECTOR(&v11);
  effBTLModelGetHeight(&TargetFormation);
  sub_854930(&v11, 1u);
  v4 = TargetFormation->r * TargetFormation->scl;
  sub_854710(&v11, 0);
  sub_854710(&p, 0);
  sub_854710(&v11, 0);
  sub_854930(&v11, 0);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->target, 0);
  SDF_VU0__LOADVECTOR_B(v11);
  SDF_VU0__SUBVECTOR();
  v5 = *pNbCamera;
  v5->distance = SDF_VU0__GETLENGTH();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
  (*pNbCamera)->distance = (v4 / sdfAtan(0.34907)) + (*pNbCamera)->distance;
  (*pNbCamera)->distance = (*pNbCamera)->distance + 650.0;
  (*pNbCamera)->fovy = 0.69813;
LABEL_16:
  ID = effBTLModelGetID(&TargetFormation);
  if (ID > 0x108)
  {
    if (ID - 291 <= 0x35 && ((1LL << (ID - 35)) & 0x38003800000007LL) != 0)
      goto LABEL_29;
  }
  else if (ID - 258 <= 6 && ((1 << (ID - 2)) & 0x43) != 0)
  {
    goto LABEL_29;
  }
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&p);
  effBTLModelLook(&TargetFormation, &p);
LABEL_29:
  nbCameraShot_GroundCollision(pNbCamera);
  return 1;
}
