#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbCameraProcess_nbCameraStateTable_t nbCameraProcess_nbCameraStateTable_t;
typedef struct nbCameraProcess_nbCameraStateTable_t_calcDelegate nbCameraProcess_nbCameraStateTable_t_calcDelegate;
typedef struct nbCameraProcess_nbCameraStateTable_t_initDelegate nbCameraProcess_nbCameraStateTable_t_initDelegate;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

struct nbCameraProcess_nbCameraStateTable_t {
    char *pDebugString;
    nbCameraProcess_nbCameraStateTable_t_initDelegate *Init;
    nbCameraProcess_nbCameraStateTable_t_calcDelegate *Calc;
    s32 rep;
};

static nbCamera_t *nbCameraCurrent;
static nbCameraProcess_nbCameraStateTable_t *nbCameraStateTable[30];
static void *bCameraObj;
static void *bCameraCtrl;
static void *rCameraObj;
static void *rCameraCtrl;

void *GetMainCamera(dds3DefaultMain *this);
void *GetRenderCamera(dds3DefaultMain *this);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetRotateMatrixY(f32 aAngle);
void ToMatrix(void);
void dds3CameraObjectBasicSetFovy(dds3Basic_t **pBasic, f32 fovy);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetControlScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void effBTLModelAllHide(void);
void effBTLModelAllPopPosition(void);
void effBTLModelAllPopRotate(void);
void effBTLModelAllShow(void);
f32 effBTLModelGetHeight(nbFormation_t **pFormation);
void effBTLModelShowRun(void);
void effBTLModelTargetGroupHide(void);
void effBTLModelTargetPartyShow(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
void effBTLSkillSetFormationInfo(u32 InvokeID, u32 TargetBit);
s32 nbCameraCheckNiidaCamera(void);
void nbCameraCheckStateChange(void);
void nbCameraInit(void);
void nbCameraPressProcessRun(void);
void nbCameraSetState(u16 state);
void nbCameraShot_All_Set(nbCamera_t **pNbCamera);
s32 nbGetActionSeq(dds3ProcessID_t *id);
nbMainProcessData_t *nbGetMainProcessData(void);
f32 nbGetPartyDistance(void);
void nbRestartMotion(void);
void nbSetEnemyFormation(nbMainProcessData_t **data);
f32 sdfAtan(f32 aX);

// 0x167b790
u8 effBTLDebug_CameraAllEditCheck(void) {
  return 0;
}

// 0x167b7a0
u8 effBTLDebug_CameraViewCheck(void) {
  return 0;
}

// 0x167b7c0
void effDebugStringDraw(s32 x, s32 y, s32 attr, char **pString) {
  ;
}

// 0x167b7b0
void effDebugWindowDraw(s32 x, s32 y, s32 w, s32 h, u32 bg_c, u32 frame_c) {
  ;
}

// 0x167b8f0
void nbCameraAnim_DistanceSet(nbCamera_t **pNbCamera, s32 frame, f32 distance, s32 start_f) {
  (*pNbCamera)->anim->distance_f = frame;
  (*pNbCamera)->anim->distance_s = -distance / frame;
  (*pNbCamera)->distance = (*pNbCamera)->distance
                                + ((*pNbCamera)->anim->distance_s * start_f);
}

// 0x167b810
void nbCameraAnim_RotateSet(nbCamera_t **pNbCamera, s32 frame, f32 rotate, s32 start_f) {
  f32 rotate_s;

  (*pNbCamera)->anim->rotate_f = frame;
  (*pNbCamera)->anim->rotate_s = rotate / frame;
  rotate_s = (*pNbCamera)->anim->rotate_s;
  SetRotateMatrixY(rotate_s * start_f);
  SDF_VU0__LOADVECTOR((*pNbCamera)->direction, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&(*pNbCamera)->direction, 0);
}

// 0x167b7d0
void nbCameraAnim_Stop(nbCamera_t **pNbCamera) {
  (*pNbCamera)->anim->rotate_f = 0;
  (*pNbCamera)->anim->rotate_s = 0.0;
  (*pNbCamera)->anim->distance_f = 0;
  (*pNbCamera)->anim->distance_s = 0.0;
}

// 0x167cbe0
s32 nbCameraCheckNiidaCamera(void) {
  dds3Basic_t_o *ControlScene;
  System_String_o *name;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  nbGetMainProcessData();
  ControlScene = dds3GetControlScene();
  pBasic = ControlScene;
  if (ControlScene)
  {
    name = dds3GetActiveCameraSceneBasic(&pBasic)->name;
    LODWORD(ControlScene) = Equals_5234480(name, nbSetNiidaCamera_name);
  }
  return ControlScene;
}

// 0x167ccf0
void nbCameraCheckStateChange(void) {
  nbMainProcessData_t_o *MainProcessData;
  struct dds3ProcessID_t_array *ActionProcessID;
  s64 NowActionProcess;
  nbMainProcessData_t_o *v6;
  struct dds3ProcessID_t_array *v8;
  s64 v9;
  dds3ProcessID_t_o *v11;
  s32 ActionSeq;
  u32 orderindex;
  struct System_SByte_array *order;
  u32 max_length;
  struct System_SByte_array *v18;
  s64 v20;
  struct nbParty_t_array *party;
  signed s32 v22;
  u32 v23;
  struct System_SByte_array *v24;
  s64 v26;
  u32 formindex;
  struct nbFormation_t_array *form;
  u32 v30;
  u16 v32;
  nbCameraProcess_c *v33;
  struct nbCameraProcess_StaticFields *static_fields;

  else
  {
    MainProcessData = nbGetMainProcessData();
    if (!MainProcessData)
      return;
  }
  ActionProcessID = MainProcessData->ActionProcessID;
  NowActionProcess = MainProcessData->NowActionProcess;
  v6 = MainProcessData;
  if (ActionProcessID->m_Items[NowActionProcess])
  {
    v8 = MainProcessData->ActionProcessID;
    v9 = MainProcessData->NowActionProcess;
    v11 = v8->m_Items[v9];
    ActionSeq = nbGetActionSeq(v11);
    orderindex = v6->orderindex;
    if (orderindex == -1)
    if ((orderindex & 0x80000000) == 0)
    {
      order = v6->order;
      max_length = order->max_length;
      if (orderindex < max_length)
      {
        if ((order->m_Items[v6->orderindex] & 0x80000000) == 0)
        {
          v18 = v6->order;
          v20 = v18 + v6->orderindex;
          party = v6->party;
          v22 = *(v20 + 32);
          v23 = party->max_length;
          if (v22 < v23)
          {
            v24 = v6->order;
            v26 = v24->m_Items[v6->orderindex];
            formindex = party->m_Items[v26]->formindex;
            if ((formindex & 0x80000000) == 0)
            {
              form = v6->form;
              v30 = form->max_length;
              if (formindex < v30)
              {
                if ((form->m_Items[party->m_Items[v26]->formindex]->stat & 0x100) != 0)
                {
                  if (ActionSeq == 1)
                  {
                    {
                    }
                    v32 = 2;
                  }
                  if (ActionSeq != 10)
                  {
                    if (ActionSeq == 5)
                    {
                      {
                      }
                      v32 = 4;
                    }
                    else
                    {
                      if (ActionSeq != 4)
                        return;
                      {
                      }
                      static_fields = v33->static_fields;
                      v32 = 3;
                      static_fields->nbCameraCurrent->state = 2;
                    }
                    nbCameraSetState(v32);
                    return;
                  }
                  v32 = 17;
                }
                if (ActionSeq == 1)
                {
                  effBTLModelAllShow();
                  return;
                }
                if (ActionSeq != 10)
                  return;
              }
            }
          }
        }
      }
    }
  }
}

// 0x167e2e0
void *nbCameraDraw(dds3ProcessID_t *id) {
  nbCameraProcess_c *v5;
  struct nbCameraProcess_StaticFields *static_fields;
  struct nbCameraProcess_nbCameraStateTable_t_array *nbCameraStateTable;
  s64 state;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  UnityEngine_Object_o *bCameraObj;
  f32 v23;
  UnityEngine_Transform_o *transform;
  f32 v25;
  f32 v26;
  f32 v27;
  UnityEngine_Transform_o *v28;
  struct dds3KernelDraw_StaticFields *v29;
  f32 z;
  f32 x;
  f32 y;
  UnityEngine_Transform_o *v33;
  f32 v34;
  struct UnityEngine_GameObject_o *RenderCamera;
  UnityEngine_Object_o *rCameraObj;
  Il2CppObject *v43;
  UnityEngine_Transform_o *v45;
  UnityEngine_Transform_o *v46;
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o p;
  f32 v50;
  f32 v51;
  UnityEngine_Vector3_o v52;
  UnityEngine_Vector3_o v53;
  UnityEngine_Vector3_o v54;
  UnityEngine_Vector3_o v55;
  UnityEngine_Vector3_o v56;
  UnityEngine_Vector3_o v57;

  *&p.x = 0;
  *&p.z = 0;
  *&v48.x = 0;
  *&v48.z = 0;
  else if ((nbGetMainProcessData()->stat & 0x200000) != 0)
  {
    return 0;
  }
  if (dds3DebugSign
  {
  }
  if (nbGetMainProcessData()->debug)
  {
    static_fields = v5->static_fields;
    nbCameraStateTable = static_fields->nbCameraStateTable;
    state = static_fields->nbCameraCurrent->state;
    Format(StringLiteral_21160, nbCameraStateTable->m_Items[state]->pDebugString, 0);
  }
  MainCamera = GetMainCamera(kernelObject);
  bCameraObj = MainCamera;
  Component_object = GetComponent_object_(bCameraObj);
  bCameraCtrl = Component_object;
  if (op_Inequality(bCameraObj, 0, 0))
  {
    SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
    SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(600.0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__LOADVECTOR_B(dds3CameraOffset);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&p);
    v51 = p.x / 100.0;
    v50 = p.y / -100.0;
    v23 = p.z / 100.0;
    transform = get_transform(bCameraObj, 0);
    get_position(transform);
    SDF_VU0__LOADVECTOR(dds3CameraEyePos);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(&v48);
    v25 = v48.y / -100.0;
    v26 = v48.x / 100.0;
    v27 = v48.z / 100.0;
    v28 = get_transform(bCameraObj, 0);
    v52.x = v26;
    v52.y = v25;
    v52.z = v27;
    set_localPosition(v28, v52);
    v29 = dds3KernelDraw->static_fields;
    z = v29->dds3CameraUpVector.z;
    x = v29->dds3CameraUpVector.x;
    y = v29->dds3CameraUpVector.y;
    v33 = get_transform(bCameraObj, 0);
    v53.y = v50;
    v53.x = v51;
    v53.z = v23;
    v56.x = x;
    v56.y = y;
    v56.z = z;
    LookAt_27488480(v33, v53, v56);
    v34 = (dds3ScreenParam->fovy * 360.0) / 6.2832;
    set_fieldOfView(bCameraCtrl, v34);
    RenderCamera = GetRenderCamera(kernelObject);
    rCameraObj = RenderCamera;
    if (op_Inequality(rCameraObj, 0, 0))
    {
      v43 = GetComponent_object_(rCameraObj);
      rCameraCtrl = v43;
      v45 = get_transform(rCameraObj, 0);
      v54.x = v26;
      v54.y = v25;
      v54.z = v27;
      set_localPosition(v45, v54);
      v46 = get_transform(rCameraObj, 0);
      v55.y = v50;
      v55.x = v51;
      v55.z = v23;
      v57.x = x;
      v57.y = y;
      v57.z = z;
      LookAt_27488480(v46, v55, v57);
      set_fieldOfView(rCameraCtrl, v34);
    }
  }
  return 0;
}

// 0x167c440
void nbCameraEventSetTarget(nbFormation_t **pTargetForm) {
  nbFormation_t_o *v3;

  v3 = effBTLSkillGetInvokeFormation(0);
  effBTLSkillSetFormationInfo(v3->formindex, 1 << (*pTargetForm)->formindex, 0);
  nbCameraSetState(0x18u);
}

// 0x167cb20
void nbCameraInit(void) {
  nbCameraShot_All_Set(&nbCameraCurrent);
  nbCameraCurrent->state_change = 0;
  nbCameraCurrent->state_old2 = 0;
  nbCameraCurrent->state_old = 0;
  nbCameraCurrent->state = 0;
}

// 0x167d060
void *nbCameraProcess_(dds3ProcessID_t *id) {
    nbGetMainProcessData();
    nbCameraCheckStateChange();
    nbRestartMotion();
    nbSetEnemyFormation(0);
    effBTLModelShowRun();
    nbCameraPressProcessRun();
    nbCameraCheckNiidaCamera();
    dds3GetControlScene();
    dds3GetActiveCameraSceneBasic(0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR_B(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3CameraObjectBasicSetFovy(0, 0);
    return 0;
}

// 0x167c970
void nbCameraScriptSet(sdfVector4_t pPos, sdfVector4_t pQ) {
    effBTLModelAllPopPosition();
    effBTLModelAllPopRotate();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    nbCameraSetState(0);
}

// 0x167c500
void nbCameraScriptSet1Shot(nbFormation_t **pTargetForm) {
  nbFormation_t_o *v3;

  v3 = effBTLSkillGetInvokeFormation(0);
  effBTLSkillSetFormationInfo(v3->formindex, 1 << (*pTargetForm)->formindex, 0);
  effBTLModelAllPopPosition();
  effBTLModelAllPopRotate();
  effBTLModelAllHide();
  effBTLModelTargetGroupHide();
  nbCameraSetState(0x1Au);
}

// 0x167c600
void nbCameraScriptSetBougai(nbFormation_t **pTargetForm) {
    effBTLSkillGetInvokeFormation(0);
    effBTLSkillSetFormationInfo(0, 0);
    effBTLModelAllPopPosition();
    effBTLModelAllPopRotate();
    effBTLModelAllHide();
    effBTLModelTargetPartyShow();
    nbGetMainProcessData();
    effBTLModelGetHeight(0);
    sdfAtan(0);
    nbGetPartyDistance();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__NORMALIZE();
    nbCameraSetState(0);
}

// 0x167c130
void nbCameraSetBougai(nbFormation_t **pTargetForm) {
  nbFormation_t_o *v3;

  v3 = effBTLSkillGetInvokeFormation(0);
  effBTLSkillSetFormationInfo(v3->formindex, 1 << (*pTargetForm)->formindex, 0);
  nbCameraSetState(0xDu);
}

// 0x167c370
void nbCameraSetHojo(nbFormation_t **pHojo, nbFormation_t **pTarget1, nbFormation_t **pTarget2) {
  u32 v7;
  u32 formindex;

  v7 = (1 << (*pTarget2)->formindex) | (1 << (*pTarget1)->formindex);
  formindex = (*pHojo)->formindex;
  effBTLSkillSetFormationInfo(formindex, v7);
  nbCameraSetState(0x10u);
}

// 0x167bf70
void nbCameraSetState(u16 state) {
  struct nbCameraProcess_nbCameraStateTable_t_array *nbCameraStateTable;

  nbCameraCurrent->state_change = state;
  if (nbCameraStateTable->m_Items[state]->rep)
  {
    nbCameraCurrent->state = 0;
  }
}

// 0x167c050
void nbCameraSetState2(u16 state) {
  struct nbCameraProcess_nbCameraStateTable_t_array *nbCameraStateTable;

  nbCameraCurrent->state_change = state;
  if (nbCameraStateTable->m_Items[state]->rep)
  {
    nbCameraCurrent->state = 0;
  }
}

// 0x167c1f0
void nbCameraSetTaizi(nbFormation_t **pInvokeForm, nbFormation_t **pTargetForm) {
  u32 v5;
  u32 formindex;

  v5 = 1 << (*pTargetForm)->formindex;
  formindex = (*pInvokeForm)->formindex;
  effBTLSkillSetFormationInfo(formindex, v5);
  nbCameraSetState(0xEu);
}

// 0x167c2b0
void nbCameraSetTarget(nbFormation_t **pTargetForm) {
  nbFormation_t_o *v3;

  v3 = effBTLSkillGetInvokeFormation(0);
  effBTLSkillSetFormationInfo(v3->formindex, 1 << (*pTargetForm)->formindex, 0);
  nbCameraSetState(0xFu);
}

// 0x167e850
dds3ProcessFunc_t *nbCameraShutdown(dds3ProcessID_t *id) {
  nbGetMainProcessData()->CameraProcessID = 0;
  return 0;
}

// 0x167bda0
void nbCameraState_DebugShotAll_Init(void) {
  nbCameraShot_All_Set(&nbCameraCurrent);
}

// 0x167bb70
void nbCameraState_EnemyParty_SearchSet(void) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    effBTLSkillSetFormationInfo(0, 0);
}

// 0x166c050
void nbCameraState_InvokeTargetSelect_SearchSet(void) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    effBTLSkillSetFormationInfo(0, 0);
}

// 0x167b940
void nbCameraState_InvokeTarget_SearchSet(void) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    effBTLSkillSetFormationInfo(0, 0);
}

// 0x167e8c0
void nbInitCameraProcess(nbMainProcessData_t **data) {
  u64 *v3;
  u64 *v4;
  u64 *v6;
  dds3ProcessID_t_o *started;
  dds3ProcessID_t_o *target;

  target = 0;
  started = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_nbCameraProcess_nbCameraProcess___);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbCameraProcess_nbCameraShutdown__);
  target = dds3StartProcess(StringLiteral_21161, 0x3FBu, 2, 1, v3, 0, v4, 0, 0, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->CameraProcessID = target;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbCameraProcess_nbCameraDraw__);
  started = dds3StartProcess(StringLiteral_21162, 0x2B0Eu, 1, 1, v6, 0, 0, 0, 0, 0);
  dds3LinkProcess(&target, &started);
  nbCameraInit();
}
