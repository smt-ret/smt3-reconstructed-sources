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
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  s64 v18;
  f32 v19;
  UnityEngine_Vector3_o result;

  v8 = angle1 * 0.017453;
  v9 = angle2 * 0.017453;
  v10 = sdfSin(v8);
  v11 = sdfCos(v9);
  v12 = sdfSin(v8);
  v13 = (v12 * radius) * sdfSin(v9);
  v14 = sdfCos(v8);
  v19 = 0.0;
  v18 = 0;
  sub_8524C0(&v18, (v10 * radius) * v11, v13, v14 * radius);
  result.y = *(&v18 + 1);
  LODWORD(result.x) = v18;
  result.z = v19;
  return result;
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
      goto LABEL_3;
LABEL_30:
  }
  max_length = tx->max_length;
  if (!max_length)
    goto LABEL_30;
LABEL_3:
  if (tx->m_Items[0] != tx->m_Items[1])
  {
    v41 = tx->max_length;
    if (tx->m_Items[0] == tx->m_Items[2])
    {
      v10 = 0;
      v11 = 1;
      v12 = 2;
      if (LODWORD(tx->max_length) > 1)
        goto LABEL_7;
    }
    else
    {
      v11 = 0;
      v10 = 1;
      v12 = 2;
      if (LODWORD(tx->max_length))
        goto LABEL_7;
    }
LABEL_6:
  }
  v10 = 0;
  v11 = 2;
  v12 = 1;
  if (LODWORD(tx->max_length) <= 2)
    goto LABEL_6;
LABEL_7:
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

LABEL_7:
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
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v7;
  struct dds3PoseSet_t_o *poseset;
  UnityEngine_Transform_o *v10;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Quaternion_o v15;
  UnityEngine_Vector3_o v16;
  UnityEngine_Vector4_o v17;

  *&v15.x = 0;
  *&v15.z = 0;
  if (!cam
    || !IsNullOrEmpty(cam->name)
    && Equals_5234480(cam->name, "P_Cam"))
  {
    return 0;
  }
  sub_1A1BDD0(&v15.x, cam->poseset->rot.x, -cam->poseset->rot.y, cam->poseset->rot.z, cam->poseset->rot.w);
  transform = get_transform(fldCameraObj, 0);
  set_localRotation(transform, v15);
  v7 = get_transform(fldCameraObj, 0);
  poseset = cam->poseset;
  v10 = v7;
  x = poseset->scl.x;
  y = poseset->scl.y;
  z = poseset->scl.z;
  w = poseset->scl.w;
  v17.x = x;
  v17.y = y;
  v17.z = z;
  v17.w = w;
  v16 = op_Implicit_8738992(v17);
  set_localScale(v10, v16);
  return 1;
}

// 0x1020990
void fldCamCalcSaka(void) {
  u64 *v1;
  u64 *v2;
  u64 *v4;
  s16 v8;
  s32 v9;
  s32 *p_ooyTestKeisyaHitIdx;
  s64 v13;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v17;
  struct collision_s_array *v19;
  struct collision_s_array *v21;
  struct collision_s_array *v25;
  struct UnityEngine_Vector4_array *point;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  struct collision_s_array *v34;
  struct UnityEngine_Vector4_array *v36;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  struct collision_s_array *v43;
  struct UnityEngine_Vector4_array *v45;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  struct collision_s_array *v52;
  struct UnityEngine_Vector4_array *v54;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v59;
  struct collision_s_array *v61;
  struct UnityEngine_Vector4_array *v63;
  f32 v65;
  f32 v66;
  f32 v67;
  f32 v68;
  struct collision_s_array *v70;
  struct UnityEngine_Vector4_array *v72;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 v77;
  struct collision_s_array *v79;
  struct UnityEngine_Vector4_array *v81;
  f32 v83;
  f32 v84;
  f32 v85;
  f32 v86;
  struct collision_s_array *v88;
  struct UnityEngine_Vector4_array *v90;
  f32 v92;
  f32 v93;
  f32 v94;
  f32 v95;
  struct collision_s_array *v97;
  struct UnityEngine_Vector4_array *v99;
  f32 v101;
  f32 v102;
  f32 v104;
  f32 v105;
  f32 playerX;
  f32 v112;
  f32 v114;
  f32 v116;
  struct FLDCAM_t_array *gCamTable;
  struct fldGlobalWork_t_o *fldGb;
  s64 CamTableIdx;
  f32 playerZ;
  f32 leng;
  f32 v123;
  f32 v125;
  struct FLDCAM_t_array *v126;
  s64 v127;
  f32 T_Y;
  struct fldGlobalWork_t_o *v131;
  f32 v132;
  f32 v133;
  f32 v134;
  struct FLDCAM_t_array *v135;
  struct fldGlobalWork_t_o *v136;
  s64 v137;
  f32 v138;
  f32 v140;
  f32 v141;
  f32 v142;
  f32 v144;
  struct FLDCAM_t_array *v145;
  s64 v146;
  u64 v148[2];

  v1 = NewSpecific(f32, 3u);
  v2 = NewSpecific(f32, 3u);
  v4 = NewSpecific(f32, 3u);
  v148[0] = 0;
  v148[1] = 0;
  ooyTestCamSaka = 0.0;
  fldGb->PlayerSaka = 0.0;
  if ((v8 & 0x200) != 0)
  {
    v9 = v8 & 0x200;
    if (ooyTestKeisyaHitIdx != -1)
      goto LABEL_11;
  }
  else
  {
    v9 = 0;
    if (ooyTestKeisyaHitIdx != -1)
    {
LABEL_11:
      p_ooyTestKeisyaHitIdx = &ooyTestKeisyaHitIdx;
LABEL_26:
      v13 = *p_ooyTestKeisyaHitIdx;
      if (gfldCollision)
      {
        if (gfldCollision->m_Items[v13]->matter)
        {
          v17 = gfldCollision;
          sub_854710(&v17->m_Items[v13]->matter->poseset->pos, 0);
          sub_854930(v148, 0);
          v19 = gfldCollision;
          sub_854710(&v19->m_Items[v13]->matter->poseset->pos, 1u);
          sub_854930(v148, 1u);
          v21 = gfldCollision;
          sub_854710(&v21->m_Items[v13]->matter->poseset->pos, 2u);
        }
        else
        {
          sub_854930(v148, 0);
          sub_854930(v148, 1u);
        }
        sub_854930(v148, 2u);
        v25 = gfldCollision;
        point = v25->m_Items[v13]->point;
        sub_854710(point->m_Items, 0);
        v30 = v29;
        sub_854710(v148, 0);
        v32 = v30 + v31;
        *(v1 + 8) = v32;
        v34 = gfldCollision;
        v36 = v34->m_Items[v13]->point;
        sub_854710(v36->m_Items, 1u);
        v39 = v38;
        sub_854710(v148, 1u);
        v41 = v39 + v40;
        *(v2 + 8) = v41;
        v43 = gfldCollision;
        v45 = v43->m_Items[v13]->point;
        sub_854710(v45->m_Items, 2u);
        v48 = v47;
        sub_854710(v148, 2u);
        v50 = v48 + v49;
        *(v4 + 8) = v50;
        v52 = gfldCollision;
        v54 = v52->m_Items[v13]->point;
        sub_854710(&v54->m_Items[1], 0);
        v57 = v56;
        sub_854710(v148, 0);
        v59 = v57 + v58;
        *(v1 + 9) = v59;
        v61 = gfldCollision;
        v63 = v61->m_Items[v13]->point;
        sub_854710(&v63->m_Items[1], 1u);
        v66 = v65;
        sub_854710(v148, 1u);
        v68 = v66 + v67;
        *(v2 + 9) = v68;
        v70 = gfldCollision;
        v72 = v70->m_Items[v13]->point;
        sub_854710(&v72->m_Items[1], 2u);
        v75 = v74;
        sub_854710(v148, 2u);
        v77 = v75 + v76;
        *(v4 + 9) = v77;
        v79 = gfldCollision;
        v81 = v79->m_Items[v13]->point;
        sub_854710(&v81->m_Items[2], 0);
        v84 = v83;
        sub_854710(v148, 0);
        v86 = v84 + v85;
        *(v1 + 10) = v86;
        v88 = gfldCollision;
        v90 = v88->m_Items[v13]->point;
        sub_854710(&v90->m_Items[2], 1u);
        v93 = v92;
        sub_854710(v148, 1u);
        v95 = v93 + v94;
        *(v2 + 10) = v95;
        v97 = gfldCollision;
        v99 = v97->m_Items[v13]->point;
        sub_854710(&v99->m_Items[2], 2u);
        v102 = v101;
        sub_854710(v148, 2u);
        v105 = v102 + v104;
        *(v4 + 10) = v105;
        playerX = fldGb->playerX;
        v112 = OOYRAD(ooyCamKakudo);
        v114 = sdfSin(v112);
        v116 = v114;
        CamTableIdx = fldGb->CamTableIdx;
        playerZ = fldGb->playerZ;
        leng = gCamTable->m_Items[CamTableIdx]->leng;
        v123 = OOYRAD(ooyCamKakudo);
        v125 = sdfCos(v123);
        v126 = gCamTable;
        v127 = fldGb->CamTableIdx;
        T_Y = GetT_Y(
                playerX - (v116 * leng),
                playerZ - (v125 * v126->m_Items[v127]->leng),
                v1,
                v2,
                v4);
        ooyTestCamSaka = fldGb->playerY - T_Y;
        v131 = fldGb;
        v132 = v131->playerX;
        v133 = OOYRAD(-v131->PlayerKakudo);
        v134 = sdfSin(v133);
        v135 = gCamTable;
        v136 = fldGb;
        v137 = v136->CamTableIdx;
        v138 = v134;
        v140 = v135->m_Items[v137]->leng;
        v141 = v136->playerZ;
        v142 = OOYRAD(-v136->PlayerKakudo);
        v144 = sdfCos(v142);
        v145 = gCamTable;
        v146 = fldGb->CamTableIdx;
        fldGb->PlayerSaka = fldGb->playerY
                                                                    - GetT_Y(
                                                                        v132 - (v138 * v140),
                                                                        v141 - (v144 * v145->m_Items[v146]->leng),
                                                                        v1,
                                                                        v2,
                                                                        v4);
      }
      return;
    }
  }
  if ((ooyTestYukaHitIdx & 0x80000000) == 0)
  {
    p_ooyTestKeisyaHitIdx = &ooyTestYukaHitIdx;
    goto LABEL_26;
  }
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
  fldCamera_c *v2;
  s32 gFldElvCam;
  _BOOL4 v6;
  f32 v7;
  _BOOL4 v8;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  if (gFldElvCam)
  {
    if ((v2->_2.bitflags2 & 2) == 0)
    {
      v6 = gFldElvCam == 1;
      goto LABEL_9;
    }
    else
    {
      v6 = gFldElvCam == 1;
      {
LABEL_9:
        if (v6 || gFldElvCam == 2)
          v7 = 1.0;
        else
          v7 = 0.0;
LABEL_12:
        v8 = gFldElvCam == -1;
        goto LABEL_32;
      }
    }
    if (v6 || gFldElvCam == 2)
      v7 = 1.0;
    else
      v7 = 0.0;
LABEL_27:
    v8 = gFldElvCam == -1;
      goto LABEL_32;
    goto LABEL_31;
  }
}

// 0x102a9c0
void *fldCamMain(void) {
  fldFollowCameraControl_t_o *FollowCameraControl;
  fldUnitControl_t_o *UnitControl;
  UnityEngine_Object_o *fldCameraObj;
  struct fldGlobalWork_t_o *fldGb;
  dds3Basic_t_o *v12;
  s32 fieldID;
  struct System_Byte_array_array_array *dds3PadAnalog;
  System_Byte_array_array *v19;
  System_Byte_array *v20;
  s32 v21;
  s32 v23;
  s32 v24;
  s32 v25;
  struct System_Byte_array_array_array *v30;
  System_Byte_array_array *v31;
  System_Byte_array *v32;
  struct System_Byte_array_array_array *v37;
  System_Byte_array_array *v38;
  System_Byte_array *v39;
  struct System_Byte_array_array_array *v44;
  System_Byte_array_array *v45;
  System_Byte_array *v46;
  dds3Basic_t_o **p_handle;
  f32 v56;
  dds3Basic_t_o **v61;
  s32 v63;
  struct FLDCAM_t_array *gCamTable;
  s32 v67;
  f32 v68;
  s64 CamTableIdx;
  f32 fovy;
  f32 v75;
  struct FLDCAM_t_array *v77;
  s64 v78;
  Il2CppClass **v80;
  u32 v88;
  u64 v97;
  bool v106;
  f32 v110;
  s32 v113;

  FollowCameraControl = fldGetFollowCameraControl();
  UnitControl = fldGetUnitControl();
  if (op_Equality(fldCameraObj, 0, 0) || !UnitControl->handle)
    return 0;
  fldPlayerAlpOn();
  if (evtBitCheck(2800))
  {
    if (!fldCamNowEveCamera(0))
    {
      if (fldGb->fieldID >= 11)
      {
        if (!fldGb->cammode)
        {
          fldPlayerSvsOn();
          fldPlayerAlpOff();
          fldPlayerSdwOff();
        }
      }
    }
  }
  v12 = fldCamNowEveCamera(0);
  if (v12)
  {
    fldGb->syukan_cam_reset_flg = 1;
    fldCamElvTask();
    fldPlayerSvsOff();
    return 0;
  }
  fieldID = fldGb->fieldID;
  if (fieldID == 18)
    goto LABEL_390;
  if (fieldID == 28)
    goto LABEL_390;
  if (fieldID == 30)
  {
LABEL_390:
    fldGb->CamTableIdx = 1;
  }
  if (fldGb->fieldID < 11)
    goto LABEL_81;
  if (fldProcCheckFlag(0x40u) != 1)
  {
LABEL_81:
    v23 = 0;
    v21 = 0;
    v24 = 0;
    v25 = 0;
      goto LABEL_136;
    goto LABEL_82;
  }
  v19 = dds3PadAnalog->m_Items[0];
  v20 = v19->m_Items[1];
  if (v20->m_Items[0] > 0x3Fu)
  {
    v21 = 0;
      goto LABEL_93;
    goto LABEL_91;
  }
  Log("fldCamMain:ANALOG[RL]", 0);
  v21 = 1;
  {
LABEL_91:
  }
LABEL_93:
  v30 = dds3PadAnalog;
  v31 = v30->m_Items[0];
  v32 = v31->m_Items[1];
  if (v32->m_Items[0] < 0xC1u)
  {
    v23 = 0;
      goto LABEL_108;
    goto LABEL_106;
  }
  Log("fldCamMain:ANALOG[RR]", 0);
  v23 = 1;
  {
LABEL_106:
  }
LABEL_108:
  v37 = dds3PadAnalog;
  v38 = v37->m_Items[0];
  v39 = v38->m_Items[1];
  if (v39->m_Items[1] > 0x3Fu)
  {
    v24 = 0;
      goto LABEL_123;
    goto LABEL_121;
  }
  Log("fldCamMain:ANALOG[RD]", 0);
  v24 = 1;
  {
LABEL_121:
  }
LABEL_123:
  v44 = dds3PadAnalog;
  v45 = v44->m_Items[0];
  v46 = v45->m_Items[1];
  if (v46->m_Items[1] < 0xC1u)
  {
    v25 = 0;
      goto LABEL_136;
    goto LABEL_82;
  }
  Log("fldCamMain:ANALOG[RU]", 0);
  v25 = 1;
  {
LABEL_82:
  }
LABEL_136:
  if (fldGb->fieldID <= 9)
  {
    resetCamWM_Sub(8.0);
    return 0;
  }
  fldCamCalcSaka();
  if (gFldNowTalk)
  {
    fldGb->syukan_cam_reset_flg = 1;
    p_handle = &FollowCameraControl->handle;
    if (gFldNowTalk == 2)
    {
      v56 = OOYRAD(50.0);
      dds3CameraObjectBasicSetFovy(p_handle, v56);
      CameraFieldView = 50.0;
        goto LABEL_210;
LABEL_208:
      goto LABEL_210;
    }
    v68 = OOYRAD(40.0);
    dds3CameraObjectBasicSetFovy(p_handle, v68);
    CameraFieldView = 40.0;
      goto LABEL_208;
  }
  else
  {
    v113 = v25;
    if (fldGb->cammode || !evtBitCheck(2800))
    {
      else
      {
        v63 = v21;
      }
      {
        v67 = v23;
      }
      else
      {
        v67 = v23;
      }
      v61 = &FollowCameraControl->handle;
    }
    else
    {
      v61 = &FollowCameraControl->handle;
      if (!scrSearchScriptName("elvstart_label"))
      {
        v110 = OOYRAD(60.0);
        dds3CameraObjectBasicSetFovy(v61, v110);
        CameraFieldView = 60.0;
          goto LABEL_208;
        goto LABEL_210;
      }
      else
      {
        v63 = v21;
      }
      {
        v67 = v23;
      }
      else
      {
        v67 = v23;
      }
    }
    CamTableIdx = fldGb->CamTableIdx;
    fovy = gCamTable->m_Items[CamTableIdx]->fovy;
    v75 = OOYRAD(fovy);
    dds3CameraObjectBasicSetFovy(v61, v75);
    v77 = gCamTable;
    v78 = fldGb->CamTableIdx;
    v80 = &v77->obj.klass + v78;
    v21 = v63;
    CameraFieldView = *(&v80[4]->_1.namespaze + 1);
    v25 = v113;
    v23 = v67;
      goto LABEL_208;
  }
LABEL_210:
  if (fldGb->cammode)
  {
    fldCamMiwatasi = 0;
    fldCamMiwatasiCnt = 0;
    fldCamMiwatasiX = 0.0;
    fldCamMiwatasiY = 0.0;
  }
  switch (fldGb->cammode)
  {
    case 0:
      if (gFldNowTalk)
      {
        fldPlayerOff();
      }
      if (!v24 && !v23 && !v21 && !v25)
      {
        calcCamUDReset();
        if (gFldNowTalk)
        {
          if (fldGb->FukiTalk)
            goto LABEL_308;
          if (fldCamResetOn)
          {
LABEL_308:
            {
LABEL_311:
              calcCamNormalNPC(v97);
              return 0;
            }
          }
          else
          {
            v88 = 1;
LABEL_298:
            dds3FadeIn(v88, 0, 0, 6u);
              goto LABEL_311;
          }
          goto LABEL_311;
        }
        if (!fldGb->FukiTalk)
        {
          if (fldCamResetOn)
          {
            dds3FadeIn(2u, 0, 0, 6u);
          }
        }
        v106 = evtBitCheck(2800);
        if (v106)
        {
          calcCamSyukan();
            goto LABEL_383;
        }
        else
        {
          calcCamNormal();
            goto LABEL_383;
        }
LABEL_383:
        goto LABEL_384;
      }
      calcCamMiwatasi();
      break;
    case 1:
      if (gFldNowTalk)
      {
        fldPlayerOff();
      }
      if (!gFldNowTalk)
      {
        if (!fldGb->FukiTalk)
        {
          if (fldCamResetOn)
          {
            dds3FadeIn(6u, 0, 0, 6u);
          }
        }
        calcCamTgtPlayer();
        goto LABEL_348;
      }
      if (!fldGb->FukiTalk)
      {
        if (!fldCamResetOn)
        {
          v88 = 5;
          goto LABEL_298;
        }
      }
      goto LABEL_308;
    case 3:
      if (gFldNowTalk)
      {
        fldPlayerOff();
      }
      if (!gFldNowTalk)
      {
        if (!fldGb->FukiTalk)
        {
          if (fldCamResetOn)
          {
            dds3FadeIn(4u, 0, 0, 6u);
          }
        }
        calcCamDirLock();
LABEL_348:
LABEL_384:
        fldCamResetOn = 0;
        return 0;
      }
      if (!fldGb->FukiTalk)
      {
        if (!fldCamResetOn)
        {
          v88 = 3;
          goto LABEL_298;
        }
      }
      goto LABEL_308;
    case 4:
      hokanCamNormal();
      return 0;
    case 5:
      fldPlayerOff();
      goto LABEL_308;
    default:
      return 0;
  }
  return 0;
}

// 0x102c2c0
void fldCamMainEventForUnity(void) {
  UnityEngine_Object_o *fldCameraObj;
  UnityEngine_GameObject_o *v7;
  UnityEngine_GameObject_o *gameObject;
  dds3Basic_t_o *ActiveScene;
  f32 v18;
  f32 v20;
  f32 v21;
  UnityEngine_Transform_o *transform;
  UnityEngine_Object_o *fldPlayerObj;
  UnityEngine_Object_o *v28;
  UnityEngine_Transform_o *v31;
  s32 v33;
  s32 v35;
  UnityEngine_Transform_o *v36;
  UnityEngine_Transform_o *v38;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  UnityEngine_Transform_o *v46;
  UnityEngine_RaycastHit_o v48;
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o tgtpos;
  UnityEngine_Vector4_o campos;
  dds3Basic_t_o *cam;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v55;
  UnityEngine_Vector3_o v56;
  UnityEngine_Vector3_o v57;
  UnityEngine_Vector3_o v58;
  UnityEngine_Vector3_o v59;

  pBasic = 0;
  *&campos.z = 0;
  cam = 0;
  *&v49.x = 0;
  *&tgtpos.z = 0;
  *&campos.x = 0;
  *&v49.z = 0;
  *&tgtpos.x = 0;
  memset(&v48, 0, sizeof(v48));
  else if (dds3SearchProcessPriority(1018))
  {
    return;
  }
  if (!dds3SearchProcessName("PipeMain"))
  {
    if (op_Equality(fldCameraObj, 0, 0))
    {
      v7 = Find("Main Camera", 0);
      gameObject = get_gameObject(v7);
      fldCameraObj = gameObject;
      flgCameraCtrl = GetComponent_object_(fldCameraObj);
    }
    ActiveScene = dds3GetActiveScene();
    pBasic = ActiveScene;
    campos = get_zero();
    tgtpos = get_zero();
    if (ActiveScene)
    {
      cam = dds3GetActiveCameraSceneBasic(&pBasic);
      dds3CameraObjectBasicGetTgtCam(&cam, &tgtpos, &campos);
      if (cam)
      {
        sub_854690(&v49.x, 0.0, 0.0, 0.0, 0.0);
        v49.x = dds3CameraOffset.x * 0.7;
        v49.y = dds3CameraOffset.y * 0.7;
        SDF_VU0__LOADVECTOR(tgtpos);
        SDF_VU0__LOADVECTOR_B(campos);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__NORMALIZE();
        SDF_VU0__SCALEVECTOR(600.0);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__LOADVECTOR_B(v49);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&tgtpos);
        SDF_VU0__LOADVECTOR(campos);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&campos);
        v18 = campos.x / 100.0;
        v20 = campos.y / -100.0;
        v21 = campos.z / 100.0;
        transform = get_transform(fldCameraObj, 0);
        v55.x = v18;
        v55.y = v20;
        v55.z = v21;
        set_localPosition(transform, v55);
        if (op_Inequality(fldPlayerObj, 0, 0))
        {
          v28 = fldCameraObj;
          if (op_Inequality(v28, 0, 0))
          {
            if (fldGb->cammode != 1)
            {
              v31 = get_transform(fldPlayerObj, 0);
              position = get_position(v31);
              v33 = 1 << NameToLayer("character");
              v35 = ~v33;
              v36 = get_transform(fldCameraObj, 0);
              v59 = get_position(v36);
              v56.x = position.x;
              v56.y = position.y + 1.4;
              v56.z = position.z;
              if (Linecast_8861088(v56, v59, &v48, v35))
              {
                v38 = get_transform(fldCameraObj, 0);
                v57.x = sub_874C00(&v48);
                set_position(v38, v57);
              }
            }
          }
        }
        v42 = (dds3ScreenParam->fovy * 360.0) / 6.2832;
        set_fieldOfView(flgCameraCtrl, v42);
        v43 = tgtpos.y / -100.0;
        v44 = tgtpos.x / 100.0;
        v45 = tgtpos.z / 100.0;
        v46 = get_transform(fldCameraObj, 0);
        v58.x = v44;
        v58.y = v43;
        v58.z = v45;
        LookAt_27488768(v46, v58);
        SetEventCamera(cam);
      }
    }
  }
}

// 0x102be30
void fldCamMainForUnity(void) {
  UnityEngine_Object_o *fldCameraObj;
  f32 v8;
  f32 v9;
  f32 v10;
  UnityEngine_Transform_o *transform;
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
    v8 = g_cameraPos.y / -100.0;
    v9 = g_cameraPos.x / 100.0;
    v10 = g_cameraPos.z / 100.0;
    transform = get_transform(fldCameraObj, 0);
    v22.x = v9;
    v22.y = v8;
    v22.z = v10;
    set_localPosition(transform, v22);
    set_fieldOfView(
      flgCameraCtrl,
      (dds3ScreenParam->fovy * 360.0) / 6.2832,
      0);
    v15 = g_targetPos.y / -100.0;
    v16 = g_targetPos.x / 100.0;
    v17 = g_targetPos.z / 100.0;
    v18 = get_transform(fldCameraObj, 0);
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
      else if (Equals_5234480(v5->name, "P_Cam"))
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
  f32 v3;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v18;
  f32 v20;

  sub_854710(&g_targetPos, 0);
  v4 = v3;
  sub_854710(&g_cameraPos, 0);
  v6 = v5;
  sub_854710(&g_targetPos, 1u);
  v8 = v7;
  sub_854710(&g_cameraPos, 1u);
  v10 = v8 - v9;
  sub_854710(&g_targetPos, 2u);
  v12 = v11;
  sub_854710(&g_cameraPos, 2u);
  v15 = v12 - v14;
  v16 = v4 - v6;
  v18 = sdfSqrt(((v16 * v16) + (v10 * v10)) + (v15 * v15), 0);
  v20 = v18;
  ooyCamLeng = v20 + -50.0;
}

// 0x102c040
void fldCamSyukanSuriawase(void) {
  dds3Basic_t_o *ActiveCameraSceneBasic;
  struct FLDCAM_t_array *gCamTable;
  s64 CamTableIdx;
  f32 fovy;
  f32 v17;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  if (dds3SearchProcessName("fldProcSequence"))
  {
    else if (fldGb->cammode)
    {
      return;
    }
    if (evtBitCheck(2800))
    {
      if (!scrSearchScriptName("elvstart_label"))
      {
        pBasic = dds3GetActiveScene();
        ActiveCameraSceneBasic = dds3GetActiveCameraSceneBasic(&pBasic);
        if (ActiveCameraSceneBasic == fldGetUnitFollowCamera())
        {
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

  v1 = Find("Main Camera", 0);
  gameObject = get_gameObject(v1);
  fldCameraObj = gameObject;
  flgCameraCtrl = GetComponent_object_(fldCameraObj);
}

// 0x1022ae0
void hokanCamNormal(void) {
  fldFollowCameraControl_t_o *FollowCameraControl;
  s64 v6;
  s64 v7;
  dds3Basic_t_o **p_handle;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;

  *&v13.x = 0;
  *&v13.z = 0;
  *&v12.x = 0;
  *&v12.z = 0;
  FollowCameraControl = fldGetFollowCameraControl();
  sub_854710(&he_targetPos, 0);
  sub_854710(&hs_targetPos, 0);
  sub_854930(&v13, 0);
  sub_854710(&he_targetPos, 1u);
  sub_854710(&hs_targetPos, 1u);
  sub_854930(&v13, 1u);
  sub_854710(&he_targetPos, 2u);
  sub_854710(&hs_targetPos, 2u);
  sub_854930(&v13, 2u);
  sub_854710(&he_cameraPos, 0);
  sub_854710(&he_cameraPos, 0);
  sub_854930(&v12, 0);
  sub_854710(&he_cameraPos, 1u);
  sub_854710(&he_cameraPos, 1u);
  sub_854930(&v12, 1u);
  sub_854710(&he_cameraPos, 2u);
  sub_854710(&he_cameraPos, 2u);
  sub_854930(&v12, 2u);
  SDF_VU0__COPYVECTOR(&g_targetPos, v13);
  SDF_VU0__COPYVECTOR(&g_cameraPos, v12);
  v6 = *&v12.x;
  v7 = *&v12.z;
  p_handle = &FollowCameraControl->handle;
  *&v14.x = v6;
  *&v14.z = v7;
  dds3SetPosPoseSet(p_handle, v14);
  int___Invoke(
    (*p_handle)->basicfunction->mainprocuder,
    *p_handle);
  ++hokanCamCount;
  if (hokanCamTimeM < hokanCamCount)
  {
    fldGb->cammode = 0;
  }
}

// 0x1022730
void hokanCamStart(void) {
  f32 v4;
  f32 v7;
  f32 ooyCamKakudo;
  f32 v9;
  f32 v14;

  v4 = OOYRAD(ooyCamKakudo);
  sdfSin(v4);
  sub_854930(&he_targetPos, 0);
  sub_854930(&he_targetPos, 1u);
  v7 = OOYRAD(ooyCamKakudo);
  sdfCos(v7);
  sub_854930(&he_targetPos, 2u);
  sub_854930(&he_targetPos, 3u);
  v9 = OOYRAD(ooyCamKakudo);
  sdfSin(v9);
  sub_854930(&he_cameraPos, 0);
  sub_854930(&he_cameraPos, 1u);
  v14 = OOYRAD(ooyCamKakudo);
  sdfCos(v14);
  sub_854930(&he_cameraPos, 2u);
  sub_854930(&he_cameraPos, 3u);
}

// 0x1021530
void resetCamNormal(void) {
  fldFollowCameraControl_t_o *FollowCameraControl;
  fldUnitControl_t_Fields *p_fields;
  struct fldGlobalWork_t_o *fldGb;
  f32 v9;
  struct fldGlobalWork_t_o *v10;
  f32 v11;
  struct fldGlobalWork_t_o *v12;
  f32 v13;
  struct fldGlobalWork_t_o *v14;
  f32 v16;
  f32 ooyCamKakudo;
  f32 v21;
  struct fldGlobalWork_t_o *v23;
  f32 v26;
  f32 v27;
  f32 v30;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o hitpos;
  UnityEngine_Vector4_o v58;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v60;
  UnityEngine_Vector4_o v61;
  UnityEngine_Vector4_o v62;
  UnityEngine_Vector4_o v63;
  UnityEngine_Vector4_o v64;

  *&hitpos.x = 0;
  *&hitpos.z = 0;
  *&v56.x = 0;
  *&v56.z = 0;
  *&v62.x = 0;
  *&v62.z = 0;
  *&v61.x = 0;
  *&v61.z = 0;
  *&v60.x = 0;
  *&v60.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v58.x = 0;
  *&v58.z = 0;
  FollowCameraControl = fldGetFollowCameraControl();
  *&hitpos.x = 0;
  *&hitpos.z = 0;
  *&v56.x = 0;
  *&v56.z = 0;
  p_fields = &fldGetUnitControl()->fields;
  dds3GetRotPoseSet(&p_fields->handle);
  v9 = EulerAngleAxisY();
  fldGb->PlayerKakudo = OOYDEG(v9);
  fldGb->PlayerKakudoGoal = fldGb->PlayerKakudo;
  dds3GetPosPoseSet(&p_fields->handle);
  SDF_VU0__STOREVECTOR(&v56);
  v10 = fldGb;
  sub_854710(&v56, 0);
  v10->playerX = v11;
  v10->playerOldX = v11;
  v12 = fldGb;
  sub_854710(&v56, 1u);
  v12->playerY = v13;
  v12->playerOldY = v13;
  v14 = fldGb;
  sub_854710(&v56, 2u);
  v14->playerZ = v16;
  v14->playerOldZ = v16;
  ooyCamKakudoY = 0.0;
  ooyCamKakudo = -fldGb->PlayerKakudo;
  fldCamKakudoGoal = ooyCamKakudo;
  v21 = OOYRAD(ooyCamKakudo);
  sdfSin(v21);
  sub_854930(&v62, 0);
  v23 = fldGb;
  sub_854930(&v62, 1u);
  v26 = OOYRAD(ooyCamKakudo);
  sdfCos(v26);
  sub_854930(&v62, 2u);
  v27 = OOYRAD(ooyCamKakudo);
  sdfSin(v27);
  sub_854930(&v60, 0);
  sub_854930(&v60, 1u);
  v30 = OOYRAD(ooyCamKakudo);
  sdfCos(v30);
  sub_854930(&v60, 2u);
  SDF_VU0__COPYVECTOR(&g_targetPos, v62);
  SDF_VU0__COPYVECTOR(&g_cameraPos, v60);
  ooyTestCamSaka = 0.0;
  ooyCamSakaOld = 0.0;
  ooyTestKeisyaHitIdx = -1;
  ooyTestYukaHitIdx = -1;
  sub_854710(&v60, 1u);
  sub_854930(&v60, 1u);
  ooyCamSakaOld = ooyTestCamSaka;
  sub_854930(&v61, 0);
  sub_854930(&v61, 1u);
  sub_854930(&v61, 2u);
  SDF_VU0__COPYVECTOR(&dst, v61);
  SDF_VU0__COPYVECTOR(&v58, v60);
  x = v58.x;
  y = v58.y;
  z = v58.z;
  w = v58.w;
  v40 = dst.x;
  v39 = dst.y;
  v42 = dst.z;
  v41 = dst.w;
  v63.x = x;
  v63.y = y;
  v63.z = z;
  v63.w = w;
  v64.x = v40;
  v64.y = v39;
  v64.z = v42;
  v64.w = v41;
  fldHitChkCamera(v63, v64, &hitpos);
  sub_854710(&hitpos, 0);
  v44 = v43;
  sub_854710(&v61, 0);
  v46 = v45;
  sub_854710(&hitpos, 1u);
  v48 = v47;
  sub_854710(&v61, 1u);
  v50 = v48 - v49;
  sub_854710(&hitpos, 2u);
  v52 = v51;
  sub_854710(&v61, 2u);
  v54 = sdfSqrt((((v44 - v46) * (v44 - v46)) + (v50 * v50)) + ((v52 - v53) * (v52 - v53)), 0);
  sub_854710(&v61, 0);
  sub_854710(&hitpos, 0);
  sub_854710(&v61, 1u);
  sub_854710(&hitpos, 1u);
  sub_854710(&v61, 2u);
  sub_854710(&hitpos, 2u);
  fViewDist = v54
                                               * (fViewDistance
                                                / fViewMaxDistance);
  sub_854710(&v61, 0);
  sub_854930(&v60, 0);
  sub_854710(&v61, 1u);
  sub_854930(&v60, 1u);
  sub_854710(&v61, 2u);
  sub_854930(&v60, 2u);
  dds3SetPosPoseSet(&FollowCameraControl->handle, v60);
  SDF_VU0__COPYVECTOR(&g_targetPos, v62);
  SDF_VU0__COPYVECTOR(&g_cameraPos, v60);
  v55 = int___Invoke(FollowCameraControl->handle->basicfunction->mainprocuder, FollowCameraControl->handle);
  fldCamSetLeng();
}

// 0x1021e70
void resetCamNormal2(void) {
  fldFollowCameraControl_t_o *FollowCameraControl;
  fldUnitControl_t_Fields *p_fields;
  struct fldGlobalWork_t_o *fldGb;
  f32 v9;
  struct fldGlobalWork_t_o *v11;
  f32 v12;
  struct fldGlobalWork_t_o *v13;
  f32 v14;
  struct fldGlobalWork_t_o *v15;
  f32 v16;
  f32 v18;
  struct fldGlobalWork_t_o *v20;
  f32 v23;
  f32 v24;
  f32 v27;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o hitpos;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;
  UnityEngine_Vector4_o v59;
  UnityEngine_Vector4_o v60;

  *&hitpos.x = 0;
  *&hitpos.z = 0;
  *&v52.x = 0;
  *&v52.z = 0;
  *&v58.x = 0;
  *&v58.z = 0;
  *&v57.x = 0;
  *&v57.z = 0;
  *&v56.x = 0;
  *&v56.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v54.x = 0;
  *&v54.z = 0;
  FollowCameraControl = fldGetFollowCameraControl();
  *&hitpos.x = 0;
  *&hitpos.z = 0;
  *&v52.x = 0;
  *&v52.z = 0;
  p_fields = &fldGetUnitControl()->fields;
  dds3GetRotPoseSet(&p_fields->handle);
  v9 = EulerAngleAxisY();
  fldGb->PlayerKakudo = OOYDEG(v9);
  dds3GetPosPoseSet(&p_fields->handle);
  SDF_VU0__STOREVECTOR(&v52);
  fldGb->playerOldX = fldGb->playerX;
  fldGb->playerOldY = fldGb->playerY;
  fldGb->playerOldZ = fldGb->playerZ;
  v11 = fldGb;
  sub_854710(&v52, 0);
  v11->playerX = v12;
  v13 = fldGb;
  sub_854710(&v52, 1u);
  v13->playerY = v14;
  v15 = fldGb;
  sub_854710(&v52, 2u);
  v15->playerZ = v16;
  v18 = OOYRAD(fldGb->PlayerKakudo + 180.0);
  sdfSin(v18);
  sub_854930(&v58, 0);
  v20 = fldGb;
  sub_854930(&v58, 1u);
  v23 = OOYRAD(fldGb->PlayerKakudo + 180.0);
  sdfCos(v23);
  sub_854930(&v58, 2u);
  v24 = OOYRAD(ooyCamKakudo);
  sdfSin(v24);
  sub_854930(&v56, 0);
  sub_854930(&v56, 1u);
  v27 = OOYRAD(ooyCamKakudo);
  sdfCos(v27);
  sub_854930(&v56, 2u);
  SDF_VU0__COPYVECTOR(&g_targetPos, v58);
  SDF_VU0__COPYVECTOR(&g_cameraPos, v56);
  sub_854710(&v56, 1u);
  sub_854930(&v56, 1u);
  ooyCamSakaOld = ooyTestCamSaka;
  sub_854930(&v57, 0);
  sub_854930(&v57, 1u);
  sub_854930(&v57, 2u);
  SDF_VU0__COPYVECTOR(&dst, v57);
  SDF_VU0__COPYVECTOR(&v54, v56);
  x = v54.x;
  y = v54.y;
  z = v54.z;
  w = v54.w;
  v36 = dst.x;
  v35 = dst.y;
  v38 = dst.z;
  v37 = dst.w;
  v59.x = x;
  v59.y = y;
  v59.z = z;
  v59.w = w;
  v60.x = v36;
  v60.y = v35;
  v60.z = v38;
  v60.w = v37;
  fldHitChkCamera(v59, v60, &hitpos);
  sub_854710(&hitpos, 0);
  v40 = v39;
  sub_854710(&v57, 0);
  v42 = v41;
  sub_854710(&hitpos, 1u);
  v44 = v43;
  sub_854710(&v57, 1u);
  v46 = v44 - v45;
  sub_854710(&hitpos, 2u);
  v48 = v47;
  sub_854710(&v57, 2u);
  v50 = sdfSqrt((((v40 - v42) * (v40 - v42)) + (v46 * v46)) + ((v48 - v49) * (v48 - v49)), 0);
  sub_854710(&v57, 0);
  sub_854710(&hitpos, 0);
  sub_854710(&v57, 1u);
  sub_854710(&hitpos, 1u);
  sub_854710(&v57, 2u);
  sub_854710(&hitpos, 2u);
  fViewDist = v50
                                               * (fViewDistance
                                                / fViewMaxDistance);
  sub_854710(&v57, 0);
  sub_854930(&v56, 0);
  sub_854710(&v57, 1u);
  sub_854930(&v56, 1u);
  sub_854710(&v57, 2u);
  sub_854930(&v56, 2u);
  dds3SetPosPoseSet(&FollowCameraControl->handle, v56);
  SDF_VU0__COPYVECTOR(&g_targetPos, v58);
  SDF_VU0__COPYVECTOR(&g_cameraPos, v56);
  v51 = int___Invoke(FollowCameraControl->handle->basicfunction->mainprocuder, FollowCameraControl->handle);
  fldCamSetLeng();
}

// 0x1025600
void resetCamTgtPlayer(void) {
  fldFollowCameraControl_t_o *FollowCameraControl;
  fldUnitControl_t_Fields *p_fields;
  struct fldGlobalWork_t_o *fldGb;
  f32 v9;
  struct fldGlobalWork_t_o *v11;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v35;
  f32 v36;
  UnityEngine_Vector4_o v38;
  UnityEngine_Vector4_o v39;

  *&v39.x = 0;
  *&v39.z = 0;
  *&v38.x = 0;
  *&v38.z = 0;
  FollowCameraControl = fldGetFollowCameraControl();
  p_fields = &fldGetUnitControl()->fields;
  dds3GetRotPoseSet(&p_fields->handle);
  v9 = EulerAngleAxisY();
  fldGb->PlayerKakudo = OOYDEG(v9);
  fldGb->PlayerKakudoGoal = fldGb->PlayerKakudo;
  sub_854930(&v39, 0);
  v11 = fldGb;
  sub_854930(&v39, 1u);
  sub_854930(&v39, 2u);
  sub_854710(&g_targetPos, 0);
  sub_854710(&v39, 0);
  sub_854710(&g_targetPos, 0);
  sub_854930(&v39, 0);
  sub_854710(&g_targetPos, 1u);
  sub_854710(&v39, 1u);
  sub_854710(&g_targetPos, 1u);
  sub_854930(&v39, 1u);
  sub_854710(&g_targetPos, 2u);
  sub_854710(&v39, 2u);
  sub_854710(&g_targetPos, 2u);
  sub_854930(&v39, 2u);
  dds3CameraObjectBasicSetTargetPos(&FollowCameraControl->handle, v39);
  dds3GetTMPoseSet(&p_fields->handle);
  sub_854930(&v38, 3u);
  sub_854710(&fldGb->campos, 0);
  sub_854930(&v38, 0);
  sub_854710(&fldGb->campos, 1u);
  sub_854930(&v38, 1u);
  sub_854710(&fldGb->campos, 2u);
  sub_854930(&v38, 2u);
  dds3SetPosPoseSet(&FollowCameraControl->handle, v38);
  sub_854710(&g_cameraPos, 0);
  sub_854710(&v38, 0);
  sub_854710(&g_cameraPos, 0);
  sub_854930(&v38, 0);
  sub_854710(&g_cameraPos, 1u);
  sub_854710(&v38, 1u);
  sub_854710(&g_cameraPos, 1u);
  sub_854930(&v38, 1u);
  sub_854710(&g_cameraPos, 2u);
  sub_854710(&v38, 2u);
  sub_854710(&g_cameraPos, 2u);
  sub_854930(&v38, 2u);
  dds3SetPosPoseSet(&FollowCameraControl->handle, v38);
  SDF_VU0__COPYVECTOR(&g_targetPos, v39);
  SDF_VU0__COPYVECTOR(&g_cameraPos, v38);
  int___Invoke(FollowCameraControl->handle->basicfunction->mainprocuder, FollowCameraControl->handle);
  sub_854710(&v39, 0);
  v15 = v14;
  sub_854710(&v38, 0);
  v17 = v16;
  sub_854710(&v39, 1u);
  v19 = v18;
  sub_854710(&v38, 1u);
  v21 = v19 - v20;
  sub_854710(&v39, 2u);
  v23 = v22;
  sub_854710(&v38, 2u);
  v26 = v23 - v25;
  v27 = v15 - v17;
  ooyCamLeng = sdfSqrt(((v27 * v27) + (v21 * v21)) + (v26 * v26), 0);
  sub_854710(&v38, 0);
  v29 = v28;
  sub_854710(&v38, 2u);
  v31 = v30;
  sub_854710(&v39, 0);
  v33 = v32;
  sub_854710(&v39, 2u);
  v36 = LockH360(v29, v31, v33, v35);
  ooyCamKakudo = v36;
  ooyCamKakudo = ooyCamKakudo + 180.0;
}

// 0x1027f40
void resetCamWM2(void) {
  resetCamWM_Sub(0.0);
}

// 0x1026fb0
void resetCamWM_Sub(f32 hokan) {
  f32 v4;
  fldFollowCameraControl_t_o *FollowCameraControl;
  fldGlobal_c *v7;
  s16 v8;
  s32 v9;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  f32 playerZ;
  f32 v13;
  s64 v14;
  s64 v15;
  s32 v16;
  struct FLDCAM_t_array *gCamTable;
  u32 max_length;
  struct FLDCAM_t_array *v21;
  s64 CamTableIdx;
  f32 fovy;
  f32 v29;
  s32 v32;
  f32 v33;
  struct FLDCAM_t_array *v38;
  u32 v42;
  dds3Basic_t_o **p_handle;
  f32 v49;
  struct FLDCAM_t_array *v54;
  f32 v57;
  u32 v61;
  f32 v65;
  f32 v66;
  s64 v68;
  s64 v69;
  UnityEngine_Vector4_o v72;
  UnityEngine_Vector4_o v73;
  f32 v74;
  f32 v75;
  UnityEngine_Vector4_o v76;

  *&v73.x = 0;
  *&v73.z = 0;
  *&v72.x = 0;
  *&v72.z = 0;
  v4 = 0.0;
  FollowCameraControl = fldGetFollowCameraControl();
  sub_854690(&v73.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v72.x, 0.0, 0.0, 0.0, 1.0);
  if ((v8 & 0x200) != 0)
  {
    v9 = v8 & 0x200;
  }
  else
  {
    v9 = 0;
  }
  fieldID = fldGb->fieldID;
  playerZ = fldGb->playerZ;
  fieldID = fldGb->fieldID;
  if (fieldID != 2)
    goto LABEL_19;
LABEL_14:
  v13 = (fmaxf(fminf(playerZ, 3500.0), -4300.0) + -3500.0) / -7800.0;
  v4 = 1.0 - v13;
  v14 = 8;
  v15 = 9;
  if ((v7->_2.bitflags2 & 2) == 0)
    goto LABEL_20;
LABEL_15:
LABEL_20:
  if (fieldID == 3)
  {
LABEL_21:
    v13 = (fmaxf(fminf(playerZ, 4300.0), -4000.0) + -4300.0) / -8300.0;
    v4 = 1.0 - v13;
    v14 = 10;
    v15 = 11;
  }
LABEL_22:
  if (fieldID == 5)
  {
LABEL_25:
    v13 = (fmaxf(fminf(playerZ, 4600.0), -3600.0) + -4600.0) / -8200.0;
    v4 = 1.0 - v13;
    v14 = 12;
    v15 = 13;
  }
LABEL_26:
  if (fieldID == 8)
  {
LABEL_29:
    v13 = (fmaxf(fminf(playerZ, 1200.0), -3100.0) + -1200.0) / -4300.0;
    v4 = 1.0 - v13;
    v14 = 14;
    v15 = 15;
  }
LABEL_30:
  else if (fieldID == 1)
  {
    goto LABEL_33;
  }
  if ((fieldID & 0xFFFFFFFE) == 2)
  {
    max_length = gCamTable->max_length;
    fovy = (v4 * gCamTable->m_Items[v14]->fovy) + (v13 * gCamTable->m_Items[v15]->fovy);
      goto LABEL_58;
    goto LABEL_64;
  }
  v16 = 7;
LABEL_52:
  fldGb->CamTableIdx = v16;
  v21 = gCamTable;
  CamTableIdx = fldGb->CamTableIdx;
  fovy = v21->m_Items[CamTableIdx]->fovy;
  {
LABEL_58:
  }
LABEL_64:
  v29 = OOYRAD(fovy);
  dds3SetScreenFovy(v29);
  v32 = fldGb->fieldID;
  if (v32 == 1)
  {
    v33 = fmaxf(playerZ, -1100.0);
    playerZ = 1100.0;
    if (v33 > 1100.0)
      goto LABEL_95;
    goto LABEL_94;
  }
  else if (v32 == 4)
  {
    goto LABEL_76;
  }
  else if (v32 == 6)
  {
    goto LABEL_93;
  }
  if (v32 == 7)
  {
LABEL_93:
    v33 = fmaxf(playerZ, -2348.0);
    playerZ = 811.0;
    if (v33 > 811.0)
      goto LABEL_95;
LABEL_94:
    playerZ = v33;
    goto LABEL_95;
  }
  if (v32 == 8)
  {
    v33 = fmaxf(playerZ, -3100.0);
    playerZ = 1200.0;
    if (v33 <= 1200.0)
      goto LABEL_94;
  }
LABEL_95:
  sub_854930(&v73, 0);
  v38 = gCamTable;
  sub_854930(&v73, 1u);
  sub_854930(&v73, 2u);
  if (v14)
  {
    v42 = gCamTable->max_length;
    sub_854930(&v73, 0);
    sub_854930(&v73, 1u);
    sub_854930(&v73, 2u);
  }
  if (hokan > 0.0)
  {
    sub_854710(&g_targetPos, 0);
    sub_854710(&v73, 0);
    sub_854710(&g_targetPos, 0);
    sub_854930(&v73, 0);
    sub_854710(&g_targetPos, 1u);
    sub_854710(&v73, 1u);
    sub_854710(&g_targetPos, 1u);
    sub_854930(&v73, 1u);
    sub_854710(&g_targetPos, 2u);
    sub_854710(&v73, 2u);
    sub_854710(&g_targetPos, 2u);
    sub_854930(&v73, 2u);
  }
  p_handle = &FollowCameraControl->handle;
  dds3CameraObjectBasicSetTargetPos(p_handle, v73);
  v49 = OOYRAD(180.0);
  sdfSin(v49);
  v54 = gCamTable;
  sub_854930(&v72, 0);
  sub_854930(&v72, 1u);
  v57 = OOYRAD(180.0);
  sdfCos(v57);
  sub_854930(&v72, 2u);
  if (v14)
  {
    v61 = gCamTable->max_length;
    v75 = playerZ;
    v74 = hokan;
    v65 = OOYRAD(180.0);
    sdfSin(v65);
    sub_854930(&v72, 0);
    sub_854930(&v72, 1u);
    v66 = OOYRAD(180.0);
    sdfCos(v66);
    sub_854930(&v72, 2u);
    hokan = v74;
  }
  if (hokan > 0.0)
  {
    sub_854710(&g_cameraPos, 0);
    sub_854710(&v72, 0);
    sub_854710(&g_cameraPos, 0);
    sub_854930(&v72, 0);
    sub_854710(&g_cameraPos, 1u);
    sub_854710(&v72, 1u);
    sub_854710(&g_cameraPos, 1u);
    sub_854930(&v72, 1u);
    sub_854710(&g_cameraPos, 2u);
    sub_854710(&v72, 2u);
    sub_854710(&g_cameraPos, 2u);
    sub_854930(&v72, 2u);
  }
  v68 = *&v72.x;
  v69 = *&v72.z;
  *&v76.x = v68;
  *&v76.z = v69;
  dds3SetPosPoseSet(p_handle, v76);
  int___Invoke(
    (*p_handle)->basicfunction->mainprocuder,
    *p_handle);
  SDF_VU0__COPYVECTOR(&g_targetPos, v73);
  SDF_VU0__COPYVECTOR(&g_cameraPos, v72);
}

// 0x1022e70
void setNoHokamOne(void) {
  bNoHokan = 1;
}
