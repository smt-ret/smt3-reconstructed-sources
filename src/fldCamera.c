#include "types.h"

typedef struct FLDCAM_t FLDCAM_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fldFollowCameraControl_t fldFollowCameraControl_t;
typedef struct fldUnitControl_t fldUnitControl_t;
typedef struct scrProcessWork_s scrProcessWork_s;

static void *fldCameraObj;
static void *flgCameraCtrl;
static f32 CameraFieldView;
static f32 CameraMoveLR;
static f32 CameraMoveUD;
static f32 CameraMoveDir;
static f32 CameraBackDir;
static f32 CameraCamLeng;
static s32 ooyTestYukaHitIdx;
static s32 ooyTestKeisyaHitIdx;
static f32 fldCamDirLockRotY;
static sdfVector4_t g_targetPos;
static sdfVector4_t g_cameraPos;
static f32 ooyCamSakaOld;
static sdfVector4_t hs_targetPos;
static sdfVector4_t hs_cameraPos;
static sdfVector4_t he_targetPos;
static sdfVector4_t he_cameraPos;
static s32 hokanCamCount;
static s32 hokanCamTimeM;
static s32 fldCamMiwatasi;
static s32 fldCamMiwatasiCnt;
static f32 fldCamMiwatasiX;
static f32 fldCamMiwatasiY;
static FLDCAM_t *gCamTable[32];
static f32 fViewDistance;
static f32 fViewDist;
static f32 fViewMaxDistance;
static s32 fldCamResetOn;
static bool bNoHokan;
static s32 calcCamNormal_inp_rd;
static f32 MiwatasiX;
static f32 MiwatasiY;
static s32 gFldElvCam;
static sdfVector4_t gFldElvCamPosCam;
static sdfVector4_t gFldElvCamPosTgt;
static f32 gFldElvCamCnt;
static f32 fldDbgCameraIsidaKakudo;

f32 EulerAngleAxisY(void);
sdfVector3_t GetSphericalPosition(f32 angle1, f32 angle2, f32 radius);
f32 GetT_Y(f32 px, f32 pz, f32 **tx, f32 **ty, f32 **tz);
f32 LockH360(f32 mirux, f32 miruz, f32 mirax, f32 miraz);
f32 OOYDEG(f32 a);
f32 OOYRAD(f32 a);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
bool SetEventCamera(dds3Basic_t *cam);
void dds3CameraObjectBasicGetTgtCam(dds3Basic_t **pBasic, sdfVector4_t *tgtpos, sdfVector4_t *campos);
void dds3CameraObjectBasicSetFovy(dds3Basic_t **pBasic, f32 fovy);
void dds3CameraObjectBasicSetTargetPos(dds3Basic_t **pBasic, sdfVector4_t targetPos);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetActiveScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
void dds3GetRotPoseSet(dds3Basic_t **pBasic);
void dds3GetTMPoseSet(dds3Basic_t **pBasic);
void dds3OnPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetScreenFovy(f32 fovy);
bool evtBitCheck(s32 no);
void fldCamCalcSaka(void);
void fldCamElvTask(void);
dds3Basic_t *fldCamNowEveCamera(bool nc);
void fldCamSetLeng(void);
fldFollowCameraControl_t *fldGetFollowCameraControl(void);
fldUnitControl_t *fldGetUnitControl(void);
dds3Basic_t *fldGetUnitFollowCamera(void);
s32 fldHitChkCamera(sdfVector4_t eyepos, sdfVector4_t disppos, sdfVector4_t *hitpos);
void fldPlayerAlpOff(void);
void fldPlayerAlpOn(void);
void fldPlayerOff(void);
void fldPlayerSdwOff(void);
void fldPlayerSvsOff(void);
void fldPlayerSvsOn(void);
s8 fldProcCheckFlag(u32 flag);
void hokanCamNormal(void);
void resetCamWM_Sub(f32 hokan);
scrProcessWork_s *scrSearchScriptName(char *scriptname);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
f32 sdfSin(f32 aRadius);
f32 sdfSqrt(f32 aValue);

// 0x1024520
sdfVector3_t GetSphericalPosMove(f32 angle1, f32 angle2, f32 radius) {
  f32 v9;
  f32 v10;
  f32 v12;
  f32 v14;
  f32 v16;
  f32 v18;
  f32 v19;
  f32 v20;
  UnityEngine_Vector3_o SphericalPosition;
  UnityEngine_Vector3_o result;

  v9 = fmodf(angle2 + 360.0, 360.0);
  v10 = v9 / 360.0;
  v12 = v9;
  v14 = Evaluate(fldCameraParam->_dirDistance, v10, 0);
  v16 = v14 * radius;
  SphericalPosition = GetSphericalPosition(v12, 90.0, v16);
  v18 = angle1 * 0.017453;
  v19 = SphericalPosition.z * sdfSin(v18);
  v20 = sdfCos(v18);
  result.y = SphericalPosition.y;
  result.z = SphericalPosition.z * v20;
  result.x = v19;
  return result;
}

// 0x1024690
sdfVector3_t GetSphericalPosition(f32 angle1, f32 angle2, f32 radius) {
    sdfSin(0);
    sdfCos(0);
    return (sdfVector3_t){0};
}

// 0x10203c0
f32 GetT_Y(f32 px, f32 pz, f32 **tx, f32 **ty, f32 **tz) {
  u32 max_length;
  s64 v10;
  s64 v11;
  s64 v12;
  f32 v14;
  f32 v16;
  f32 v18;
  f32 v23;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  u32 v41;
  f32 v45;
  f32 v47;

  if ((byte_3F58806 & 1) != 0)
  {
    max_length = tx->max_length;
    if (max_length)
  }
  max_length = tx->max_length;
  if (!max_length)
  if (tx->m_Items[0] != tx->m_Items[1])
  {
    v41 = tx->max_length;
    if (tx->m_Items[0] == tx->m_Items[2])
    {
      v10 = 0;
      v11 = 1;
      v12 = 2;
      if (LODWORD(tx->max_length) > 1)
    }
    else
    {
      v11 = 0;
      v10 = 1;
      v12 = 2;
      if (LODWORD(tx->max_length))
    }
  }
  v10 = 0;
  v11 = 2;
  v12 = 1;
  if (LODWORD(tx->max_length) <= 2)
  v14 = tx->m_Items[v11];
  v16 = ty->m_Items[v11];
  v18 = tz->m_Items[v11];
  v47 = ty->m_Items[v10];
  v23 = tx->m_Items[v12];
  v45 = ty->m_Items[v12];
  v26 = tz->m_Items[v12];
  v27 = tz->m_Items[v10] - v18;
  v28 = tx->m_Items[v10] - v14;
  v29 = v26 - v18;
  v30 = v23 - v14;
  v31 = sdfSqrt((v28 * v28) + (v27 * v27), 0);
  v32 = sdfSqrt((v30 * v30) + (v29 * v29), 0);
  v33 = ((px - v14) * v31) / v28;
  v34 = ((px - v14) * v32) / v30;
  v35 = v18 + ((v27 * v33) / v31);
  v36 = v16 + (((v47 - v16) * v33) / v31);
  v37 = (v18 + ((v29 * v34) / v32)) - v35;
  if (v37 >= 0.001 || v37 <= -0.001)
    v38 = ((pz - v35) * ((v16 + (((v45 - v16) * v34) / v32)) - v36)) / v37;
  else
    v38 = 0.0;
  return v36 + v38;
}

// 0x1020220
f32 LockH360(f32 mirux, f32 miruz, f32 mirax, f32 miraz) {
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;

  if (mirux == mirax && miruz == miraz)
  {
    v10 = 0.0;
  }
  else
  {
    v11 = mirux - mirax;
    v12 = miruz - miraz;
    if (v11 >= 0.0)
      v13 = v11;
    else
      v13 = -v11;
    if (v12 >= 0.0)
      v14 = v12;
    else
      v14 = -v12;
    v10 = sdfAtan2(v14, v13) * 57.325;
    if (v11 >= 0.0)
    {
      if (v12 >= 0.0)
        v10 = v10 + 180.0;
      else
        v10 = 180.0 - v10;
    }
    else if (v12 >= 0.0)
    {
      v10 = -v10;
    }
  }
  return (((360.0 - v10) + 90.0) % 360);
}

// 0x1020110
f32 LockP360(f32 mirux, f32 miruz, f32 mirax, f32 miraz) {
  f32 result;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;

  if (mirux == mirax && miruz == miraz)
    return 0.0;
  v11 = mirux - mirax;
  v12 = miruz - miraz;
  if (v11 >= 0.0)
    v13 = v11;
  else
    v13 = -v11;
  if (v12 >= 0.0)
    v14 = v12;
  else
    v14 = -v12;
  result = sdfAtan2(v14, v13) * 57.325;
  if (v11 >= 0.0)
  {
    if (v12 >= 0.0)
      return result + 180.0;
    else
      return 180.0 - result;
  }
  else if (v12 >= 0.0)
  {
    return -result;
  }
  return result;
}

// 0x102c950
bool SetEventCamera(dds3Basic_t *cam) {
    return 0;
}

// 0x1020990
void fldCamCalcSaka(void) {
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    GetT_Y(0, 0, 0, 0, 0);
}

// 0x102a950
void fldCamElvEnd(void) {
  gFldElvCam = 0;
}

// 0x102a310
void fldCamElvStart(s32 updown) {
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  ActiveScene = 0;
  gFldElvCam = updown;
  ActiveScene = dds3GetActiveScene();
  pBasic = dds3GetActiveCameraSceneBasic(&ActiveScene);
  dds3CameraObjectBasicGetTgtCam(&pBasic, &gFldElvCamPosTgt, &gFldElvCamPosCam);
  gFldElvCamCnt = 0.0;
}

// 0x102a410
void fldCamElvTask(void) {
    dds3GetActiveScene();
    dds3GetActiveCameraSceneBasic(0);
    sdfSin(0);
    dds3OnPoseSetFlag(0, 0);
}

// 0x102a9c0
void *fldCamMain(void) {
    fldGetFollowCameraControl();
    fldGetUnitControl();
    fldPlayerAlpOn();
    evtBitCheck(0);
    fldCamNowEveCamera(0);
    fldPlayerSvsOn();
    fldPlayerAlpOff();
    fldPlayerSdwOff();
    fldCamElvTask();
    fldPlayerSvsOff();
    fldProcCheckFlag(0);
    resetCamWM_Sub(0);
    fldCamCalcSaka();
    OOYRAD(0);
    dds3CameraObjectBasicSetFovy(0, 0);
    scrSearchScriptName(0);
    fldPlayerOff();
    dds3FadeIn(0, 0, 0, 0);
    hokanCamNormal();
    return 0;
}

// 0x102c2c0
void fldCamMainEventForUnity(void) {
    dds3SearchProcessPriority(0);
    dds3SearchProcessName(0);
    dds3GetActiveScene();
    dds3GetActiveCameraSceneBasic(0);
    dds3CameraObjectBasicGetTgtCam(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SetEventCamera(0);
}

// 0x102be30
void fldCamMainForUnity(void) {
  UnityEngine_Object_o *fldCameraObj;
  fldCamera_c *v6;
  struct fldCamera_StaticFields *static_fields;
  f32 v8;
  f32 v9;
  f32 v10;
  UnityEngine_Transform_o *transform;
  struct fldCamera_StaticFields *v14;
  f32 v15;
  f32 v16;
  f32 v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o tgtpos;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector3_o v22;
  UnityEngine_Vector3_o v23;

  pBasic = 0;
  *&tgtpos.x = 0;
  *&tgtpos.z = 0;
  *&v19.x = 0;
  *&v19.z = 0;
  if (!op_Equality(fldCameraObj, 0, 0))
  {
    pBasic = fldGetUnitFollowCamera();
    *&tgtpos.x = 0;
    *&tgtpos.z = 0;
    *&v19.x = 0;
    *&v19.z = 0;
    dds3CameraObjectBasicGetTgtCam(&pBasic, &tgtpos, &v19);
    static_fields = v6->static_fields;
    v8 = static_fields->g_cameraPos.y / -100.0;
    v9 = static_fields->g_cameraPos.x / 100.0;
    v10 = static_fields->g_cameraPos.z / 100.0;
    transform = get_transform(static_fields->fldCameraObj, 0);
    v22.x = v9;
    v22.y = v8;
    v22.z = v10;
    set_localPosition(transform, v22);
    set_fieldOfView(
      flgCameraCtrl,
      (dds3ScreenParam->fovy * 360.0) / 6.2832,
      0);
    v14 = fldCamera->static_fields;
    v15 = v14->g_targetPos.y / -100.0;
    v16 = v14->g_targetPos.x / 100.0;
    v17 = v14->g_targetPos.z / 100.0;
    v18 = get_transform(v14->fldCameraObj, 0);
    v23.x = v16;
    v23.y = v15;
    v23.z = v17;
    LookAt_27488768(v18, v23);
  }
}

// 0x102cab0
s32 fldCamMiwatasiChk(void) {
  return fldCamMiwatasi;
}

// 0x1029450
dds3Basic_t *fldCamNowEveCamera(bool nc) {
  dds3Basic_t_o *result;
  dds3Basic_t_o *v5;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  result = dds3GetActiveScene();
  pBasic = result;
  if (result)
  {
    result = dds3GetActiveCameraSceneBasic(&pBasic);
    if (result)
    {
      v5 = result;
      if (IsNullOrEmpty(result->name))
      {
        if (nc)
          return v5;
        else
          return 0;
      }
      else if (Equals_5234480(v5->name, StringLiteral_15158))
      {
        return 0;
      }
      else
      {
        return v5;
      }
    }
  }
  return result;
}

// 0x102cb20
s32 fldCamNpcCamChk(char **pName) {
  struct fldGlobalWork_t_o *fldGb;

  if (!*pName)
    return 0;
  if (fldGb->cammode != 5)
    return 0;
  return !Compare(fldGb->cammode5name, *pName, 0);
}

// 0x1020920
void fldCamResetNpc(void) {
  fldCamResetOn = 0;
}

// 0x1020790
void fldCamSetLeng(void) {
    sdfSqrt(0);
}

// 0x102c040
void fldCamSyukanSuriawase(void) {
  dds3Basic_t_o *ActiveCameraSceneBasic;
  fldCamera_c *v9;
  struct fldCamera_StaticFields *static_fields;
  struct FLDCAM_t_array *gCamTable;
  s64 CamTableIdx;
  f32 fovy;
  f32 v17;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  if (dds3SearchProcessName(StringLiteral_16586))
  {
    else if (fldGb->cammode)
    {
      return;
    }
    if (evtBitCheck(2800))
    {
      if (!scrSearchScriptName(StringLiteral_16585))
      {
        pBasic = dds3GetActiveScene();
        ActiveCameraSceneBasic = dds3GetActiveCameraSceneBasic(&pBasic);
        if (ActiveCameraSceneBasic == fldGetUnitFollowCamera())
        {
          static_fields = v9->static_fields;
          gCamTable = static_fields->gCamTable;
          CamTableIdx = fldGb->CamTableIdx;
          fovy = gCamTable->m_Items[CamTableIdx]->fovy;
          v17 = OOYRAD(fovy);
          dds3SetScreenFovy(v17);
        }
      }
    }
  }
}

// 0x102bca0
void fldCameraInit(void) {
  CameraMoveLR = 4.5;
  CameraMoveUD = fldCameraParam->_moveUD;
  CameraMoveDir = fldCameraParam->_moveDir;
  CameraBackDir = fldCameraParam->_backDir;
  CameraCamLeng = 20.0;
}

// 0x102bd80
void fldSetUnitFollowCameraForUnity(void) {
  UnityEngine_GameObject_o *v1;
  UnityEngine_GameObject_o *gameObject;

  v1 = Find(StringLiteral_5605, 0);
  gameObject = get_gameObject(v1);
  fldCameraObj = gameObject;
  flgCameraCtrl = GetComponent_object_(fldCameraObj);
}

// 0x1022ae0
void hokanCamNormal(void) {
    fldGetFollowCameraControl();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
}

// 0x1022730
void hokanCamStart(void) {
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
}

// 0x1021530
void resetCamNormal(void) {
    fldGetFollowCameraControl();
    fldGetUnitControl();
    dds3GetRotPoseSet(0);
    EulerAngleAxisY();
    OOYDEG(0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    fldHitChkCamera((sdfVector4_t){0}, (sdfVector4_t){0}, 0);
    sdfSqrt(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    fldCamSetLeng();
}

// 0x1021e70
void resetCamNormal2(void) {
    fldGetFollowCameraControl();
    fldGetUnitControl();
    dds3GetRotPoseSet(0);
    EulerAngleAxisY();
    OOYDEG(0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    fldHitChkCamera((sdfVector4_t){0}, (sdfVector4_t){0}, 0);
    sdfSqrt(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    fldCamSetLeng();
}

// 0x1025600
void resetCamTgtPlayer(void) {
    fldGetFollowCameraControl();
    fldGetUnitControl();
    dds3GetRotPoseSet(0);
    EulerAngleAxisY();
    OOYDEG(0);
    dds3CameraObjectBasicSetTargetPos(0, (sdfVector4_t){0});
    dds3GetTMPoseSet(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfSqrt(0);
    LockH360(0, 0, 0, 0);
}

// 0x1027f40
void resetCamWM2(void) {
  resetCamWM_Sub(0.0);
}

// 0x1026fb0
void resetCamWM_Sub(f32 hokan) {
    fldGetFollowCameraControl();
    OOYRAD(0);
    dds3SetScreenFovy(0);
    dds3CameraObjectBasicSetTargetPos(0, (sdfVector4_t){0});
    sdfSin(0);
    sdfCos(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1022e70
void setNoHokamOne(void) {
  bNoHokan = 1;
}
