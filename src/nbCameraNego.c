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
    effBTLSkillGetTargetFormation(0);
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
    nbGetMainProcessData();
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillGetTargetFormation(0);
    effBTLModelAllShow();
    nbCameraGetModelAllTable(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__INTERPOLATE(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_A();
    effBTLModelGetHeight(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    sdfAtan(0);
    effBTLModelGetPosition(0, 0);
    effBTLModelSetPosition(0, 0);
    SDF_VU0__NORMALIZE();
    effBTLModelLook(0, 0);
}

// 0x16796f0
void nbCameraState_NegoTaizi_Calc(void) {
    effBTLSkillGetTargetParty();
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
}

// 0x1679680
void nbCameraState_NegoTaizi_Init(void) {
  effBTLModelTargetGroupHide();
  effBTLModelInvokeGroupHide();
}

// 0x1679d40
void nbCameraState_NegoTarget_Calc(void) {
    effBTLSkillGetTargetFormation(0);
    effBTLModelGetID(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetMarkPosition(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__ADDVECTOR();
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
    effBTLModelAllHide();
    effBTLModelTargetGroupHide();
    effBTLSkillGetTargetFormation(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__NORMALIZE();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    sdfAtan(0);
    effBTLModelGetMarkPosition(0, 0);
    effBTLModelGetSphereCenter(0);
}
