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
    nbCameraSetState(0);
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGroupGetDirection(0, 0);
    sdfAtan(0);
}

// 0xfbf300
s32 nbCameraBoss_BSALBI_InvokeTargetParty_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    effBTLModelInvokeGroupHide();
    return 0;
}

// 0xfc9e10
s32 nbCameraBoss_BSARI1_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    return 0;
}

// 0xfca0f0
s32 nbCameraBoss_BSARI1_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    return 0;
}

// 0xfca3d0
s32 nbCameraBoss_BSARI1_Cut23_EX03_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfb8ff0
s32 nbCameraBoss_BSARI1_EP_IT_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
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
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfca7d0
s32 nbCameraBoss_BSARI2_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0xfcacb0
s32 nbCameraBoss_BSARI2_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    return 0;
}

// 0xfcaf90
s32 nbCameraBoss_BSARI2_Cut23_EX03_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    return 0;
}

// 0xfcb110
s32 nbCameraBoss_BSARI2_EP_IT_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfbfb10
s32 nbCameraBoss_BSARI_Command_Set(nbCamera_t **pNbCamera) {
    nbGetMainProcessData();
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__GETLENGTH();
    effBTLModelLook(0, 0);
    return 0;
}

// 0xfc0200
s32 nbCameraBoss_BSARI_Cut1_Run(nbCamera_t **pNbCamera) {
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__COPYVECTOR_C_TO_A();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    return 0;
}

// 0xfbff10
s32 nbCameraBoss_BSARI_Cut1_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfc0820
s32 nbCameraBoss_BSARI_MASEHA_Run(nbCamera_t **pNbCamera) {
    effBTLSkillGetInvokeFormation(0);
    effBTLModelAllShow();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    return 0;
}

// 0xfc0770
s32 nbCameraBoss_BSARI_MASEHA_Set(nbCamera_t **pNbCamera) {
  nbCameraBoss_BSARI_MASEHA_Frame = 0;
  nbCameraBoss_BSARI_MASEHA_Type = dds3GetRandIntA(3u, StringLiteral_416);
  return 1;
}

// 0xfc13c0
s32 nbCameraBoss_BSARI_SIMANO_Run(nbCamera_t **pNbCamera) {
    effBTLSkillGetInvokeFormation(0);
    effBTLModelAllShow();
    sdfAtan(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__INTERPOLATE(0);
    return 0;
}

// 0xfc1300
s32 nbCameraBoss_BSARI_SIMANO_Set(nbCamera_t **pNbCamera) {
  u32 RandIntA;

  RandIntA = dds3GetRandIntA(3u, StringLiteral_416);
  nbCameraBoss_BSARI_SIMANO_Type = RandIntA;
  nbCameraBoss_BSARI_SIMANO_Rate = 1.0;
  return 1;
}

// 0xfbda10
s32 nbCameraBoss_BSARUS_Command_Set(nbCamera_t **pNbCamera) {
    nbGetMainProcessData();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetSphereCenter(0);
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    effBTLModelLook(0, 0);
    return 0;
}

// 0xfceb50
s32 nbCameraBoss_BSBERU_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfcf060
s32 nbCameraBoss_BSBERU_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfc57b0
void nbCameraBoss_BSBERU_E915_0_Set(void) {
    effBTLModelAllShow();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
}

// 0xfc5a50
void nbCameraBoss_BSBERU_E915_1_Set(void) {
}

// 0xfc5bb0
void nbCameraBoss_BSBERU_E915_2_Set(void) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
}

// 0xfc5730
void nbCameraBoss_BSBERU_E915_Init(void) {
  nbCameraBoss_BSBERU_E915_Frame = 0;
  nbCameraBoss_BSBERU_E915_Rate = 1.0;
}

// 0xfcbda0
s32 nbCameraBoss_BSBERU_EP_IT_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfb8850
s32 nbCameraBoss_BSKAGU_Command_Calc(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm) {
    nbGetMainProcessData();
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__GETLENGTH();
    effBTLModelLook(0, 0);
    return 0;
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
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    return 0;
}

// 0xfcc860
s32 nbCameraBoss_BSKAGU_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    nbCameraShot_InvokeTarget_Set2(0, 0);
    return 0;
}

// 0xfb8b60
s32 nbCameraBoss_BSKAGU_EP_IT_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    DDS3EFFECT_RAND_I();
    return 0;
}

// 0xfc6880
s32 nbCameraBoss_BSLUSI_Command_Calc(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm) {
    nbGetMainProcessData();
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__GETLENGTH();
    effBTLModelLook(0, 0);
    return 0;
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
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfcf980
s32 nbCameraBoss_BSLUSI_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfcc220
s32 nbCameraBoss_BSLUSI_EP_IT_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLSkillGetTargetNumber();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfce110
s32 nbCameraBoss_BSMETA_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfce630
s32 nbCameraBoss_BSMETA_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfc5010
void nbCameraBoss_BSMETA_E914_0_Set(void) {
    effBTLModelAllShow();
}

// 0xfc5190
void nbCameraBoss_BSMETA_E914_1_Set(void) {
    effBTLModelAllShow();
}

// 0xfbce30
s32 nbCameraBoss_BSMIZ_Command_Set(nbCamera_t **pNbCamera) {
    nbGetMainProcessData();
    effBTLModelGetID(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__GETLENGTH();
    effBTLModelLook(0, 0);
    return 0;
}

// 0xfcb580
s32 nbCameraBoss_BSNET1_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    nbCameraShot_InvokeTarget_Set2(0, 0);
    return 0;
}

// 0xfcb930
s32 nbCameraBoss_BSNET_EP_IT_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfbd2a0
s32 nbCameraBoss_BSONGY_Command_Set(nbCamera_t **pNbCamera) {
    nbGetMainProcessData();
    effBTLModelGetGroupNumber(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetPosition(0, 0);
    effBTLModelSetPosition(0, 0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    effBTLModelLook(0, 0);
    return 0;
}

// 0xfcd390
s32 nbCameraBoss_BSPISH_Cut23_EX01_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfcd790
s32 nbCameraBoss_BSPISH_Cut23_EX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    nbCameraShot_InvokeTarget_Set2(0, 0);
    return 0;
}

// 0xfcdd10
s32 nbCameraBoss_BSPISH_Cut23_EX03_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfccd00
s32 nbCameraBoss_BSPISH_EP_IT_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfbdc70
s32 nbCameraBoss_BSSAMA_Command_Set(nbCamera_t **pNbCamera) {
    nbGetMainProcessData();
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__GETLENGTH();
    effBTLModelLook(0, 0);
    return 0;
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
    effBTLSkillGetInvokeFormation(0);
    effBTLPartGetPositionPtr(0, 0, 0);
    effBTLModelLook(0, 0);
    nbGetFormRot(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_DEGtoRAD(0);
    FromEuler(0, 0, 0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    nbSetFormRot(0, (sdfVector4_t){0}, 0);
    effBTLModelGetPosition(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__ADDVECTOR_A_C();
    effBTLModelSetPosition(0, 0);
    dds3GetRandIntA(0, 0);
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    effBTLModelAllShow();
    SDF_VU0__INTERPOLATE(0);
    return 0;
}

// 0xfc4940
s32 nbCameraBoss_Bskagu_Cut1_Run(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfc43d0
s32 nbCameraBoss_Bskagu_Cut1_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfc1990
s32 nbCameraBoss_Bsnet_AISHOH_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
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
    nbCameraState_SkillAttack_Init();
    effBTLSkillGetInvokeFormation(0);
    nbCameraState_InvokeTarget_SearchSet();
    DDS3EFFECT_RAND_I();
    nbCameraShot_Invoke_Set2(0, 0);
    nbCameraShot_GroundCollision(0);
    return 0;
}

// 0xfbf0a0
s32 nbCameraBoss_Bsnet_Attack_Run(nbCamera_t **pNbCamera) {
  return 1;
}

// 0xfbed80
s32 nbCameraBoss_Bsnet_Attack_Set(nbCamera_t **pNbCamera) {
    effBTLModelTargetPartyShow();
    effBTLModelInvokeGroupHide();
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    effBTLPartGetScalePtr(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__GETLENGTH();
    effBTLModelLook(0, 0);
    return 0;
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
    nbCameraState_SkillAttack_Init();
    effBTLSkillGetInvokeFormation(0);
    nbCameraState_InvokeTarget_SearchSet();
    DDS3EFFECT_RAND_I();
    nbCameraShot_Invoke_Set2(0, 0);
    nbCameraShot_GroundCollision(0);
    return 0;
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
  nbCameraBoss_c *v4;
  struct nbCameraBoss_StaticFields *static_fields;
  f32 Bsnet_E907_2_Rate;
  f32 v7;

  static_fields = v4->static_fields;
  Bsnet_E907_2_Rate = static_fields->Bsnet_E907_2_Rate;
  static_fields->Bsnet_E907_2_Rate = Bsnet_E907_2_Rate * 0.925;
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
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    dds3GetRandIntA(0, 0);
    nbCameraState_SkillAttack_Init();
    effBTLSkillGetInvokeFormation(0);
    nbCameraState_InvokeTarget_SearchSet();
    DDS3EFFECT_RAND_I();
    nbCameraShot_Invoke_Set2(0, 0);
    nbCameraShot_GroundCollision(0);
    return 0;
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
                LODWORD(MainProcessData) = nbCameraBoss_BSMIZ_Command_Set(pNbCamera);
                return MainProcessData;
            }
          }
          else
          {
            if (v17 == 265)
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
      }
    }
    v9 = MainProcessData->form;
    pFormation = v9->m_Items[4];
    if ((pFormation->stat & 1) == 0)
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
        if (v6 != 153)
          return 0;
        nbResetAllFormPosRot();
        return 0;
      case 0x123u:
        if (v6 == 168)
        {
          RandIntA = dds3GetRandIntA(3u, StringLiteral_416);
          nbCameraBoss_BSARI_SIMANO_Type = RandIntA;
          nbCameraBoss_BSARI_SIMANO_Rate = 1.0;
        }
        else if (v6 == 253)
        {
          nbCameraBoss_BSARI_MASEHA_Frame = 0;
          nbCameraBoss_BSARI_MASEHA_Type = dds3GetRandIntA(3u, StringLiteral_416);
        }
        else
        {
          nbCameraBoss_BSARI_Cut1_Set(v17);
        }
        return 1;
      case 0x124u:
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
        v12 = dds3GetRandIntA(2u, StringLiteral_416);
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
      case 0x102u:
        if (v6 == 168)
        if (v6 == 253)
        nbCameraBoss_BSARI2_Cut1_Set(v8);
        break;
      case 0x103u:
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
        if (v6 == 253)
        nbCameraBoss_BSARI_Cut1_Run(pNbCamera);
        return 1;
      case 0x124u:
      case 0x125u:
          return 1;
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
      nbCameraBoss_BSARI_SIMANO_Run(pNbCamera);
    }
    else if (v6 == 253)
    {
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
        case 0x102u:
          if (v7 != 174)
            return 0;
          v10 = 0.9;
          v11 = -5.0;
        case 0x103u:
          if (v7 - 169 >= 2)
          v10 = 0.85;
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
      v11 = 15.0;
    case 0x124u:
      if (v7 - 169 >= 2)
      {
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
          RandIntA = dds3GetRandIntA(3u, StringLiteral_416);
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
  }
  return result;
}

// 0xfcfeb0
s32 nbCameraBoss_Cut2_Ptr_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    nbGetMainProcessData();
    effBTLSkillGetInvokeParty();
    effBTLSkillGetTargetParty();
    effBTLSkillGetState();
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetBadStatus(0);
    effBTLModelGetID(0);
    effBTLSkillGetTargetNumber();
    nbCameraBoss_BSALBI_InvokeTargetParty_Set(0);
    DDS3EFFECT_RAND_I();
    nbCameraBoss_Samael_AKUI_Set(0);
    nbCameraBoss_BSKAGU_EP_IT_Set(0);
    nbCameraBoss_TargetInvoke_Set(0, 0, 0);
    nbCameraBoss_BSARI1_EP_IT_Set(0);
    nbCameraBoss_BSBERU_EP_IT_Set(0);
    nbCameraBoss_BSLUSI_EP_IT_Set(0);
    nbCameraBoss_BSPISH_EP_IT_Set(0);
    nbCameraBoss_BSARI2_EP_IT_Set(0);
    nbCameraBoss_BSNET_EP_IT_Set(0);
    nbCameraShot_Target_Set2(0, 0);
    nbCameraShot_TargetParty_Set2(0, 0);
    effBTLModelCheckBossID(0);
    effBTLModelGetHeight(0);
    nbCameraShot_BossTargetInvoke_Set(0);
    nbCameraShot_BossEX02_Set(0);
    effBTLSkillGetTargetFormation(0);
    nbCameraBoss_BSARI2_Cut23_EX01_Set(0);
    nbCameraBoss_BSARI2_Cut23_EX02_Set(0);
    nbCameraBoss_BSARI2_Cut23_EX03_Set(0);
    nbCameraBoss_BSPISH_Cut23_EX01_Set(0);
    nbCameraBoss_BSPISH_Cut23_EX02_Set(0);
    nbCameraBoss_BSPISH_Cut23_EX03_Set(0);
    nbCameraBoss_InvokeTarget_Set(0, 0, 0);
    nbCameraBoss_BSNET1_Cut23_EX02_Set(0);
    nbCameraShot_AttackTuibi_Set(0);
    effBTLModelInvokeGroupHide();
    nbCameraBoss_BSARI1_Cut23_EX01_Set(0);
    nbCameraBoss_BSARI1_Cut23_EX02_Set(0);
    nbCameraBoss_BSARI1_Cut23_EX03_Set(0);
    nbCameraBoss_BSKAGU_Cut23_EX01_Set(0);
    nbCameraBoss_BSKAGU_Cut23_EX02_Set(0);
    nbCameraBoss_BSMETA_Cut23_EX02_Set(0);
    nbCameraBoss_BSMETA_Cut23_EX01_Set(0);
    nbCameraBoss_BSBERU_Cut23_EX02_Set(0);
    nbCameraBoss_BSBERU_Cut23_EX01_Set(0);
    nbCameraShot_InvokeTarget_Set2(0, 0);
    nbCameraShot_InvokeTargetParty_Set2(0, 0);
    nbCameraBoss_BSLUSI_Cut23_EX01_Set(0);
    nbCameraBoss_BSLUSI_Cut23_EX02_Set(0);
    return 0;
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
        case 0x11Fu:
          result = 1;
          if (!v6 || v6 == 165)
            return result;
          if (v6 != 242)
            return 0;
        case 0x120u:
          if (v6 == 201)
          return 0;
        case 0x123u:
        case 0x124u:
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
    else    return 0;
  }
  if (ID != 257)
  {
    if (ID == 258)
    {
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
      return 1;
    }
    if (ID == 264 && v6 == 221)
    {
      nbCameraBoss_Pish_MUHENK_Run(pNbCamera);
      return 1;
    }
    return 0;
  }
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
  nbCameraBoss_c *v4;
  s16 v5;
  s32 v6;
  struct nbCameraBoss_StaticFields *static_fields;
  f32 v8;

  if ((v5 & 0x200) != 0)
  {
    v6 = v5 & 0x200;
  }
  else
  {
    v6 = 0;
  }
  static_fields = v4->static_fields;
  v8 = fminf(static_fields->Foru_E913_Frame / 190.0, 1.0);
  SDF_VU0__LOADVECTOR(static_fields->Foru_E913_StartTarget);
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
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    effBTLSkillGetState();
    effBTLModelGetBadStatus(0);
    DDS3EFFECT_RAND_I();
    effBTLModelAllShow();
    nbCameraShot_TargetParty_Set2(0, 0);
    effBTLSkillGetTargetNumber();
    effBTLModelGroupGetCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelLook(0, 0);
    return 0;
}

// 0xfb9460
void nbCameraBoss_InvokeTarget_Set(nbCamera_t **pNbCamera, f32 rotate, f32 ratio) {
    effBTLModelAllShow();
    effBTLSkillGetInvokeParty();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
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
    effBTLModelGetID(0);
    effBTLModelLook(0, 0);
    nbCameraShot_GroundCollision(0);
}

// 0xfc24d0
s32 nbCameraBoss_Kagu_Attack_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
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
    nbCameraShot_GroundCollision(0);
    return 0;
}

// 0xfc1d90
void nbCameraBoss_Kagu_E909_Run(void) {
    nbGetMainProcessData();
    nbCameraBoss_BSKAGU_Command_Set(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    nbCameraShot_All_Set3(0, (sdfVector4_t){0});
    nbCameraShot_GroundCollision(0);
    SDF_VU0__INTERPOLATE(0);
}

// 0xfc1d20
void nbCameraBoss_Kagu_E909_Set(void) {
  nbCameraCurrent->frame = 0;
}

// 0xfc28f0
s32 nbCameraBoss_Kagu_FLEACH_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfc2ce0
s32 nbCameraBoss_Kagu_MJINKO_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    DDS3EFFECT_RAND_I();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0xfc7cd0
s32 nbCameraBoss_Lusi_ASIKIK_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllHide();
    effBTLModelInvokeShow();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0xfc6d70
s32 nbCameraBoss_Lusi_Cut1_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0xfc7840
s32 nbCameraBoss_Lusi_OHNOOH_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfc7150
s32 nbCameraBoss_Lusi_TWORLD_Set(nbCamera_t **pNbCamera) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfc5310
s32 nbCameraBoss_Meta_METAT1_0_Set(nbCamera_t **pNbCamera) {
    return 0;
}

// 0xfc5440
s32 nbCameraBoss_Meta_METAT1_1_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    nbCameraBoss_BSARI1_EP_IT_Set(0);
    return 0;
}

// 0xfbd830
s32 nbCameraBoss_Ongy_BUNSIN_Run(nbCamera_t **pNbCamera) {
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SetRotateMatrixY(0);
    SDF_VU0__APPLYMATRIX();
    return 0;
}

// 0xfbd7c0
s32 nbCameraBoss_Ongy_BUNSIN_Set(nbCamera_t **pNbCamera) {
  nbCameraSetState(0);
  return 1;
}

// 0xfc38a0
s32 nbCameraBoss_Pish_MUHENK_Run(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0xfc37c0
s32 nbCameraBoss_Pish_MUHENK_Set(nbCamera_t **pNbCamera) {
  u8 RandIntA;

  effBTLModelAllShow();
  RandIntA = dds3GetRandIntA(3u, StringLiteral_416);
  nbCameraBoss_Pish_MUHENK_Type = RandIntA;
  nbCameraBoss_Pish_MUHENK_Frame = 0;
  return 1;
}

// 0xfc3470
s32 nbCameraBoss_Pish_PRESS_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
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
    return 0;
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
    effBTLModelGroupGetSphere(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__NORMALIZE();
    SDF_VU0__MULVECTOR();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__INTERPOLATE(0);
    nbCameraBoss_Sp_DOUTYO_Run(0);
    return 0;
}

// 0xfbbd30
s32 nbCameraBoss_Sp_DOUTYO_TPFix_Set(nbCamera_t **pNbCamera) {
    nbCameraSetState(0);
    return 0;
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
  else  v5 = Allocate(effBezier4PPart_t);
  effBezier4PPart_t___ctor(v5);
  nbCamera_DOUTYO_B4P = v5;
  effBezier4PPart_t__Clear(nbCamera_DOUTYO_B4P);
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
    nbCameraShot_All_Set2(0, 0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SetRotateMatrixY(0);
    SDF_VU0__APPLYMATRIX();
    return 0;
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
    effBezier4PPart_t__Clear(0);
    effBTLSkillGetState();
    effBTLModelAllHide();
    effBTLModelTargetPartyShow();
    effBTLModelInvokeShow();
    nbGetMainProcessData();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetBit();
    effBTLModelGetHeight(0);
    nbGetEnemyInterval();
    sdfAtan(0);
    nbGetPartyDistance();
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetRadius(0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    nbCameraBoss_Sp_MURET2_Run(0);
    return 0;
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
    effBTLModelAllShow();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfb9a70
void nbCameraBoss_TargetInvoke_Set(nbCamera_t **pNbCamera, f32 rotate, f32 ratio) {
    effBTLModelAllShow();
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
    effBTLModelGetID(0);
    effBTLModelLook(0, 0);
    nbCameraShot_GroundCollision(0);
}

// 0xfd2d50
s32 nbCameraDANTE_DCOMBO_KAGU_Set(s32 frame) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0xfd2b10
s32 nbCameraDANTE_DCOMBO_Set(s32 frame) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0xfd3090
s32 nbCameraDANTE_Init(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetID(0);
    effBTLSkillGetState();
    effBTLModelGetBadStatus(0);
    effBTLSkillGetID();
    effBTLSkillGetTargetFormation(0);
    effBTLModelTargetPartyShow();
    effBTLModelInvokeGroupHide();
    effBTLModelGetPosition(0, 0);
    effBTLModelLook(0, 0);
    effBTLModelLook2(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__SETVECTOR_Y(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelSetPosition(0, 0);
    evtBitCheck(0);
    return 0;
}

// 0xfd3840
s32 nbCameraDANTE_KAGIRI_Set(s32 frame) {
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    return 0;
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
      }
      v16 = (*pNbCamera)->frame;
      nbCameraDANTE_DCOMBO_KAGU_Set(v16);
      result = 1;
      break;
    case 0x108u:
      if (evtBitCheck(3712))
        return 0;
    case 0x10Bu:
    case 0x10Du:
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
      LODWORD(MainProcessData) = 0;
      return MainProcessData;
    }
    pFormation = effBTLSkillGetInvokeFormation(0);
    else    ID = effBTLSkillGetID();
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
        LODWORD(MainProcessData) = 1;
        if (((1 << v8) & 0x6001) == 0)
      }
    }
    else if (ID > 0x85)
    {
      v9 = ID - 136;
      if (v9 > 8)
      LODWORD(MainProcessData) = 1;
      if (((1 << v9) & 0x181) == 0)
    }
    else
    {
      LODWORD(MainProcessData) = 1;
      if (ID != 131 && ID != 133)
    }
  }
  return MainProcessData;
}

// 0xfd14d0
s32 nbCameraHero_Cut2_Run(nbCamera_t **pNbCamera, nbCameraSkillInfo_t **pNBSInfo) {
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetParty();
    nbGetMainProcessData();
    effBTLModelGetID(0);
    effBTLSkillGetState();
    nbCameraBoss_Cut2_Ptr_Init(0, 0);
    effBTLModelAllShow();
    effBTLModelInvokeGroupHide();
    nbCameraShot_InvokeTargetParty_Set2(0, 0);
    nbCameraShot_GroundCollision(0);
    effBTLSkillGetTargetNumber();
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelLook(0, 0);
    effBTLSkillGetID();
    nbCameraShot_PullOne_Init(0);
    nbCameraBoss_InvokeTarget_Set(0, 0, 0);
    nbCameraShot_InvokeTargetNear_Set(0, 0);
    effBTLModelGroupGetSphere(0);
    effBTLModelGetGroupMaxHeight(0);
    nbCameraBoss_CheckFix();
    DDS3EFFECT_RAND_I();
    nbCameraShot_InvokeTargetPartyTop_Set(0, 0);
    nbCameraShot_PullOne_Calc(0, 0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfc82e0
s32 nbCameraShot_BossEX02_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLSkillGetTargetParty();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetSphereCenter(0);
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__INTERPOLATE(0);
    sdfAtan(0);
    nbCameraShot_GroundCollision(0);
    return 0;
}

// 0xfc7f40
s32 nbCameraShot_BossTargetInvoke_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    sdfAtan(0);
    effBTLModelGetID(0);
    effBTLModelLook(0, 0);
    nbCameraShot_GroundCollision(0);
    return 0;
}
