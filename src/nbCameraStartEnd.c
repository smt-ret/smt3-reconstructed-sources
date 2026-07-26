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
    nbGetMainProcessData();
    effBTLModelGetSphereCenter(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
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
    nbCameraModelGroupGetCenter(0);
    SDF_VU0__STOREVECTOR(0);
    nbCameraModelGroupGetMaxLength((sdfVector4_t){0}, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    return 0;
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
    nbGetMainProcessData();
    dds3Bezier4PPartRun(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
}

// 0x16cbf10
void nbCameraState_Start_BA_Animation(nbCamera_t **pNbCamera) {
    nbGetMainProcessData();
    dds3Bezier4PPartRun(0, 0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    effBTLModelAllShow();
}

// 0x16cc580
void nbCameraState_Start_BA_Set(nbCamera_t **pNbCamera) {
    nbGetMainProcessData();
    effBTLModelGetHeight(0);
    effBTLModelGroupGetSphereExp(0, 0);
    SDF_VU0__STOREVECTOR(0);
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
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    nbGetEnemyInterval();
    nbGetPartyDistance();
    effBTLModelGetSphereCenter(0);
    nbCameraState_Start_BA_Animation(0);
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
    return 0;
}

// 0x16cdb70
s32 nbCameraState_Start_GetAnimFrame(void) {
  return nbCameraStartAnimFrame;
}

// 0x16cd800
void nbCameraState_Start_Init(void) {
    nbGetMainProcessData();
    nbCameraState_Start_Set(0);
    effBezier4PPart_t__Clear(0);
    nbCameraState_Start_BA_Set(0);
}

// 0x16cb700
void nbCameraState_Start_Set(nbCamera_t **pNbCamera) {
    nbGetMainProcessData();
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
    SDF_VU0__INTERPOLATE(0);
    nbCameraState_Start_Animation(0);
}
