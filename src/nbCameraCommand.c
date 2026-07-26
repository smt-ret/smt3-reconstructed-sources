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
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    sdfFabs(0);
    sdfSqrt(0);
}

// 0x166aba0
nbCamera_AllTable_t *nbCameraGetModelAllTable(nbFormation_t *pFormation) {
  nbCameraCommand_c *v3;
  s32 formindex;

  if (!pFormation || (pFormation->stat & 1) == 0)
  {
      return nbCameraGetModelAllTable_Dummy;
  }
  formindex = pFormation->formindex;
  nbGetUnitWorkFromFormindex(formindex);
  {
          v3 = nbCameraCommand,
    {
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
    nbGetMainProcessData();
    effBTLModelGetSphereCenter(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    nbCameraGetModelAllTable(0);
    return 0;
}

// 0x166ac80
f32 nbCameraGroupGetSphere(u32 group) {
    effBTLModelGroupGetCenter(0);
    SDF_VU0__STOREVECTOR(0);
    nbCameraGroupGetMaxLength((sdfVector4_t){0}, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    return 0;
}

// 0x166b6a0
void nbCameraShot_AllParty_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllShow();
    effBTLModelAllPopPosition();
    effBTLModelAllPopRotate();
    nbCameraState_InvokeTargetSelect_SearchSet();
    nbGetMainProcessData();
    effBTLModelGetHeight(0);
    effBTLModelGetPosition(0, 0);
    effBTLModelSetPosition(0, 0);
    effBTLModelGroupGetSphere(0);
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
    nbCameraShot_GroundCollision(0);
}

// 0x1669ea0
void nbCameraShot_CommandFixPos_Calc2(nbCamera_t **pNbCamera, nbFormation_t **pCmdForm) {
    nbGetMainProcessData();
    nbCameraGetModelAllTable(0);
    effBTLModelGetPosition2(0, 0);
    effBTLModelGetID(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetHeight(0);
    effBTLModelGetPosition(0, 0);
    effBTLModelSetPosition(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__GETLENGTH();
    sdfAtan(0);
    SDF_VU0__NORMALIZE();
    sdfAtan2(0, 0);
    SetRotateMatrixY(0);
    SDF_VU0__APPLYMATRIX();
    effBTLModelLook(0, 0);
    effBTLModelLook2(0, 0, 0);
    nbCameraGroupGetSphere(0);
}

// 0x166b5e0
void nbCameraShot_CommandFixPos_Set(nbCamera_t **pNbCamera) {
    effBTLModelGetGroupNumber(0);
    nbCameraShot_CommandFixPos_Set2(0);
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
    effBTLModelAllPopPosition();
    effBTLModelAllPopRotate();
    effBTLModelAllShow();
    effBTLSkillGetInvokeParty();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    sdfAtan(0);
    effBTLModelGroupGetDirection(0, 0);
    SetRotateMatrixX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
}

// 0x166c6d0
void nbCameraShot_Summon_Set(nbCamera_t **pNbCamera) {
    effBTLModelAllPopPosition();
    effBTLModelAllPopRotate();
    effBTLModelAllShow();
    effBTLSkillGetInvokeParty();
    effBTLModelGroupGetSphere(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelGetInvokeGroupNumber();
    nbGetSummonInterval();
    nbFormationGetRadiusDef();
    sdfAtan(0);
    effBTLModelGroupGetDirection(0, 0);
    SetRotateMatrixX(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
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
        if ((*(v13 + 295) & 2) != 0 && !*(v13 + 216))
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
  if (state_old == 10)
  if (state_old == 17)
  if (nbCameraCRSetPlayerFormRequestFlag)
  {
    nbSetPlayerFormation(&data, 0);
    nbCameraCRSetPlayerFormRequestFlag = 0;
  }
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
    if (v12 == 768)
    {
      nbCameraShot_AllParty_Set(&nbCameraCurrent);
    }
    else
    {
      if (v6 == TargetParty)
      {
        nbWaitUntilCreateMainCamera_1Frame = 1;
        nbCameraShot_FriendParty_Set(&nbCameraCurrent);
      }
      else
      {
        effBTLModelAllPopPosition();
        effBTLModelAllPopRotate();
        effBTLModelAllShow();
        nbCameraShot_CommandFixPos_Set(&nbCameraCurrent);
        nbCameraCommand_GroundCollision(&nbCameraCurrent);
        nbCameraState_Command_KORONZCheck();
      }
    }
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
  nbCameraShot_Summon_Set(&nbCameraCurrent);
  {
  }
  nbCameraCommand_GroundCollision(&nbCameraCurrent);
}

// 0x166ad90
void nbCameraState_Command_KORONZCheck(void) {
    nbGetMainProcessData();
    effBTLModelGetID(0);
    effBTLModelShow(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR_B(0);
    SDF_VU0__STOREVECTOR(0);
    effBTLModelCheckBoundsHide(0, 0, 0, 0, 0, 0);
}
