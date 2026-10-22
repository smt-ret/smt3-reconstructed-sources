#include "types.h"

typedef struct AnimChecker AnimChecker;
typedef struct FldCameraParam FldCameraParam;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;

static s32 gPlayerMsk;
static s32 gPlayerMskBak;
static f32 fldCamKakudoGoal;
static f32 gfldPlayerKakudo2;
static s32 gfldPlayerKakudo2Mode;
static s32 gfldPlayerAnaCnt;
static s32 gfldPlayerHasiCnt;
static s32 gfldPlayerDamegeCnt;
static s32 gKeyInputDir;
static s32 gKeyInputCnt;
static bool gWmRotSetOn;
static f32 gWmRotX;
static f32 gWmRotZ;
static bool bRestoreMode;
static void *fldPlayerObj;
static void *fldPlayerAnm;
static void *fldPlayerObjM;
static void *fldPlayerAnmM;
static s32 fldPlayerAct;
static bool playerRun;
static s32 PlayerStayCnt;
static s32 gCameraWait[3];
static f32 gCameraSpeed[3];
static f32 gJidouRotSpeed;
static s32 fldPlayerCalc_Nml_old_gKeyInputDir;
static sdfVector4_t fldWmNowNml;
static sdfVector4_t fldWmPrevNml;
static sdfVector4_t fldWmNextNml;
static s32 fldWmOldYukaHitIdx;
static s32 fldWmHohanCnt;
static s32 fldWmWarpMode;
static f32 fldWmSize;
static f32 fldWmFastMove;
static sdfVector4_t fldWmFastBase;
static s32 gFldPlayerSyukanDly;

void CheckPlayerCtrl(void);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
f32 EulerAngleAxisY(void);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
void FromRotation(f32 aAngle);
f32 GetFiledCeiling(FldCameraParam *this, s32 fieldID);
void InversMatrix(void);
f32 OOYDEG(f32 a);
f32 OOYRAD(f32 a);
void RetTransparent(void *obj);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetCharacterType(AnimChecker *this, s32 type);
void SetTransparent(void *obj, u32 rgba, f32 alfrgb);
s32 dds3CheckPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeIn2(u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
u32 dds3GetRandA(char *name);
void dds3GetRotPoseSet(dds3Basic_t **pBasic);
s32 dds3ObjectBaseCheckFlag(dds3Basic_t **pObjectBasic, u32 flag);
void *dds3ObjectBaseGetModelHandle(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3ObjectBaseSetControlBasicSvs(dds3Basic_t **pObjectBasic, s32 svs);
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3OnPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3SetSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
dds3ObjectBaseControlWorkData_t *dds3UnitObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
s32 encChk(void);
bool evtBitCheck(s32 no);
s32 fldAutoMapChkMode(void);
s32 fldCamMiwatasiChk(void);
dds3Basic_t *fldCamNowEveCamera(bool nc);
s32 fldCameraCheckTurnType(s32 moveSlow);
bool fldCheckBatStatusMotion(void);
void fldDmgStart(f32 x, f32 y, f32 z);
bool fldElvChk(void);
void fldHitChkUnit(sdfVector4_t phys_pos);
void fldHitChkUnitDamage(sdfVector4_t phys_pos);
void fldHitChkUnitElv(sdfVector4_t phys_pos);
void fldHitChkUnitVWM(sdfVector4_t phys_pos);
void fldPlayerAnimation(s32 act, bool init);
f32 fldPlayerCalc360_4(f32 aKakudo);
f32 fldPlayerCalc360_8(f32 aKakudo);
void fldPlayerCalcForUnity(void);
s32 fldPlayerCalcHasigo(void);
void fldPlayerCalc_Hit(void);
s32 fldPlayerCalc_Nml(void);
s32 fldPlayerCalc_Nml_syukan(void);
void fldPlayerCalc_WarpRun(void);
s32 fldPlayerCalc_Wm2(void);
void fldPlayerCalc_Wm3(void);
void fldPlayerCalc_Wm4(void);
void fldPlayerFastSetForUnity(void);
bool fldPlayerMirAreaChk(void);
s32 fldPlayerMirChk(void);
void fldPlayerMotReset2(void);
void fldPlayerMotionSe(s32 hisMotion, s32 upMotion);
void fldPlayerObjSetControlSvs(dds3Basic_t **pObjectBasic, s32 svs, void *obj);
void fldPlayerOff(void);
void fldPlayerOn(void);
void fldPlayerPosRot_RESTORE(void);
void fldPlayerSdwOff(void);
void fldPlayerSdwOn(void);
void fldPlayerSingleMotion(s32 upMotion, bool init);
void fldPlayerSvsOff(void);
void fldPlayerSvsOn(void);
s32 fldProcCampChk(void);
s8 fldProcCheckFlag(u32 flag);
void fldProcOnFlag(u32 flag);
void fldSePlay(s32 seid);
void fldSeVol(s32 seid, s32 vol);
void fldStatusSet(void);
s32 mdlChkMotionEndForUnity_26964128(void *obj, s32 index);
s32 mdlGetMotionFrameForUnity(void *obj);
s32 mdlGetMotionMinorNum(dds3ModelHandle_t **aHandle);
void mdlSingleMotionForUnity(void *obj, char *name, s32 value, bool reset, s32 index);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
f32 sdfFabs(f32 c);
f32 sdfSin(f32 aRadius);
f32 sdfSqrt(f32 aValue);
void setNoHokamOne(void);

// 0x10ca0d0
void AddCameraSpeed(bool add, s32 type, f32 spd) {
  struct System_Single_array *gCameraSpeed;
  struct System_Single_array *v10;
  struct System_Single_array *v13;
  char *v15;
  s32 v16;
  struct System_Single_array *v17;
  struct System_Single_array *v19;
  struct System_Single_array *v22;

  if (add)
  {
    gCameraSpeed->m_Items[type] = gCameraSpeed->m_Items[type] + spd;
    v10 = gCameraSpeed;
    if (v10->m_Items[type] > 60.0)
    {
      v13 = gCameraSpeed;
      v15 = v13 + 4 * type;
      v16 = 1114636288;
LABEL_32:
      *(v15 + 8) = v16;
    }
  }
  else
  {
    v17 = gCameraSpeed;
    v17->m_Items[type] = v17->m_Items[type] - spd;
    v19 = gCameraSpeed;
    if (v19->m_Items[type] < 0.1)
    {
      v22 = gCameraSpeed;
      v15 = v22 + 4 * type;
      v16 = 1036831949;
      goto LABEL_32;
    }
  }
}

// 0x10c9e10
void AddCameraWait(bool add, s32 type) {
  struct System_Int32_array *gCameraWait;
  struct System_Int32_array *v8;
  struct System_Int32_array *v11;
  struct System_Int32_array *v13;
  struct System_Int32_array *v15;
  struct System_Int32_array *v18;

  if (add)
  {
    ++gCameraWait->m_Items[type];
    v8 = gCameraWait;
    if (v8->m_Items[type] >= 61)
    {
      v11 = gCameraWait;
      v11->m_Items[type] = 60;
    }
  }
  else
  {
    v13 = gCameraWait;
    --v13->m_Items[type];
    v15 = gCameraWait;
    if (v15->m_Items[type] < 0)
    {
      v18 = gCameraWait;
      v18->m_Items[type] = 0;
    }
  }
}

// 0x10ca030
f32 GetCameraSpeed(s32 type) {
  struct System_Single_array *gCameraSpeed;

  return gCameraSpeed->m_Items[type];
}

// 0x10c9d70
s32 GetCameraWait(s32 type) {
  struct System_Int32_array *gCameraWait;

  return gCameraWait->m_Items[type];
}

// 0x10dc950
s32 GetMotionMinorNum(void) {
  dds3ModelHandle_t_o *v2;

  return mdlGetMotionMinorNum(v2);
}

// 0x10ca2f0
f32 R360_LR(f32 a, f32 b) {
  f32 v3;
  f32 v4;

  if (a < 0.0 || b < 0.0)
  {
    a = a + 360.0;
    b = b + 360.0;
  }
  v3 = (a % 360);
  v4 = (b % 360);
  if ((v3 - v4) <= 180.0 && (v3 - v4) >= -180.0)
    return v4 - v3;
  if (v3 >= v4)
    return (v4 + 360.0) - v3;
  return v4 - (v3 + 360.0);
}

// 0x10c2060
void WmRotClear(void) {
  gWmRotSetOn = 0;
}

// 0x10d3760
s32 fldCameraCheckTurnType(s32 moveSlow) {
  if (!moveSlow)
  {
    else if (!DDS3_PADCHECK_PRESS(8))
    {
      goto LABEL_35;
    }
    else if (!DDS3_PADCHECK_PRESS(10))
    {
      goto LABEL_42;
    }
LABEL_35:
    else if (DDS3_PADCHECK_PRESS(10))
    {
LABEL_38:
      else if (!DDS3_PADCHECK_PRESS(8))
      {
        goto LABEL_49;
      }
      return -1;
    }
    return -1;
  }
  else if (!DDS3_PADCHECK_TRIG(8))
  {
    goto LABEL_23;
  }
  if (!DDS3_PADCHECK_PRESS(10))
    goto LABEL_42;
LABEL_23:
  if (!DDS3_PADCHECK_TRIG(10))
    return -1;
LABEL_26:
  else if (DDS3_PADCHECK_PRESS(8))
  {
    return -1;
  }
LABEL_49:
  return cfgGetBit(7u) == 0;
}

// 0x10da790
bool fldCheckBatStatusMotion(void) {
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v5;

  if ((fldDbg->PlayerStatus & 2) != 0)
    return 1;
LABEL_6:
  unitwork = DDS3_GBWK->unitwork;
  if ((unitwork->m_Items[0]->badstatus & 0x40) != 0)
    return 1;
  v5 = DDS3_GBWK->unitwork;
  return HIBYTE(v5->m_Items[0]->badstatus) & 1;
}

// 0x10dab50
void fldPlayerAlpOff(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3ModelHandle_t_o *v4;
  dds3Basic_t_o **p_handle2;
  struct dds3Basic_t_o *handle2;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];

LABEL_7:
  v4 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v4);
  v4->modelRoot->color = 0;
  handle2 = fldUnitControl->handle2;
  p_handle2 = &fldUnitControl->handle2;
  if (handle2)
  {
    ModelHandle = dds3ObjectBaseGetModelHandle(p_handle2);
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v12);
      if ((v12[0] & 1) != 0)
        v10 = v12[2];
      else
        v10 = v12 + 1;
      v11 = sub_8C4940(v10);
    }
    HIDWORD(ModelHandle[4].klass->_1.element_class) = 0;
  }
}

// 0x10dace0
void fldPlayerAlpOn(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3ModelHandle_t_o *v4;
  dds3Basic_t_o **p_handle2;
  struct dds3Basic_t_o *handle2;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];

LABEL_7:
  v4 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v4);
  v4->modelRoot->color = -2139062144;
  handle2 = fldUnitControl->handle2;
  p_handle2 = &fldUnitControl->handle2;
  if (handle2)
  {
    ModelHandle = dds3ObjectBaseGetModelHandle(p_handle2);
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v12);
      if ((v12[0] & 1) != 0)
        v10 = v12[2];
      else
        v10 = v12 + 1;
      v11 = sub_8C4940(v10);
    }
    HIDWORD(ModelHandle[4].klass->_1.element_class) = -2139062144;
  }
}

// 0x10da550
void fldPlayerAnimation(s32 act, bool init) {
  UnityEngine_Object_o *fldPlayerAnm;
  UnityEngine_GameObject_o *fldPlayerObj;
  UnityEngine_Object_o *fldPlayerAnmM;
  UnityEngine_GameObject_o *fldPlayerObjM;

  if (init)
    goto LABEL_4;
  else if (fldPlayerAct == act)
  {
    return;
  }
  if (!fldCamNowEveCamera(0))
  {
LABEL_4:
    if (op_Inequality(fldPlayerAnm, 0, 0))
    {
      mdlSingleMotionForUnity(fldPlayerObj, "anim", act, 1, 0);
      fldPlayerAct = act;
      if (op_Inequality(fldPlayerAnmM, 0, 0))
      {
        mdlSingleMotionForUnity(fldPlayerObjM, "anim", act, 1, 0);
      }
    }
  }
}

// 0x10d94d0
s32 fldPlayerCalc(void) {
  u64 *v1;
  dds3ModelHandle_t_o *v8;
  f32 *fldGb;
  f32 v15;
  f32 v16;
  f32 v17;
  UnityEngine_GameObject_o *fldPlayerObj;
  bool v25;
  u64 v27;
  s32 v29;
  u64 v32;
  struct fldGlobalWork_t_o *v33;
  u64 v34;
  u64 v37;
  u64 v38;
  u64 v39;
  bool v42;
  f32 ooyCamLeng;
  dds3ModelHandle_t_o *v52;
  s32 MotionMinorNum;

  v1 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v1);
  playerRun = 0;
  else if (fldDbg->MenuOn)
  {
    return 0;
  }
  else if (!fldAutoMapChkMode())
  {
LABEL_12:
    if (fldProcCheckFlag(0x40u))
      goto LABEL_16;
    if (fldGb->NoroiDamegeCnt < 1)
    {
LABEL_16:
        goto LABEL_75;
    }
    else
    {
      if (mdlGetMotionMinorNum(v8) != 10)
      {
        Write("noroi damage on\n", 0);
        fldPlayerSingleMotion(10, 0);
        v15 = fldGb[78];
        v16 = fldGb[79];
        v17 = fldGb[80];
        fldDmgStart(v15, v16, v17);
        fldSePlay(34);
        dds3PadAct(0, 1u, 0x1Eu);
        dds3PadAct(1u, 0x96u, 0x1Eu);
        fldStatusSet();
      }
      if (!mdlChkMotionEndForUnity_26964128(fldPlayerObj, 0))
      {
LABEL_170:
        {
LABEL_173:
          fldPlayerCalcForUnity(v38);
          return 0;
        }
LABEL_171:
        goto LABEL_173;
      }
      fldGb->NoroiDamegeCnt = 0;
      fldProcOnFlag(0x40u);
      {
LABEL_75:
        v25 = fldProcCheckFlag(0x40u) == 0;
        if (!v25)
        {
          if (*(*(*(v27 + 184) + 72LL) + 20LL) <= 9)
          {
            fldPlayerCalc_Wm2(v27);
              goto LABEL_173;
            goto LABEL_171;
          }
          fldWmWarpMode = 0;
          v29 = *(*(*(v27 + 184) + 72LL) + 40LL);
          if (v29 == 3)
          {
            v32 = fldPlayerCalc_Nml();
            goto LABEL_169;
          }
          if (v29 == 1)
          {
            fldPlayerSvsOff();
            v32 = fldPlayerCalc_Nml();
          }
          else
          {
            v42 = evtBitCheck(2800);
            if (v42)
            {
              fldPlayerCalc_Nml_syukan();
                goto LABEL_169;
            }
            else
            {
              fldPlayerCalc_Nml();
                goto LABEL_169;
            }
          }
LABEL_169:
          fldPlayerMirChk(v32);
          goto LABEL_170;
        }
        v33 = *(*(v27 + 184) + 72LL);
        if (v33->fieldID <= 9)
        {
          if (*(*(v39 + 184) + 184LL) == 1)
          {
            fldPlayerCalc_Wm3(v39);
              goto LABEL_173;
          }
          else
          {
            evtBitCheck(1883);
              goto LABEL_173;
          }
          goto LABEL_171;
        }
        if ((*(v27 + 295) & 2) != 0 && !*(v27 + 216))
        {
          v33 = fldGb;
        }
        if ((v33->cammode | 2) == 3)
        {
            goto LABEL_157;
        }
        else
        {
          if (ooyCamLeng < CameraCamLeng)
          {
            fldPlayerSvsOn(v34);
              goto LABEL_160;
            goto LABEL_158;
          }
            goto LABEL_157;
        }
        if (!*(v34 + 216))
        {
          fldPlayerSvsOff();
          {
LABEL_160:
            v49 = fldPlayerCalcHasigo(v37);
            fldPlayerCalc_Hit();
            fldPlayerCalc_WarpRun();
            MotionMinorNum = mdlGetMotionMinorNum(v52);
            fldPlayerMotionSe(MotionMinorNum, MotionMinorNum);
            goto LABEL_169;
          }
LABEL_158:
          goto LABEL_160;
        }
LABEL_157:
        fldPlayerSvsOff(v34);
          goto LABEL_160;
        goto LABEL_158;
      }
    }
    goto LABEL_75;
  }
  return 0;
}

// 0x10ca9f0
f32 fldPlayerCalc360_4(f32 aKakudo) {
  f32 v3;
  s32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  bool v8;
  f32 v9;
  f32 v10;
  f32 v12;
  f32 v13;
  s32 v14;
  f32 v16;
  f32 v17;
  f32 v19;
  f32 v20;
  f32 v22;
  f32 v23;
  f32 v25;
  f32 v26;
  f32 v28;
  s32 v29;

  v3 = aKakudo;
  if ((byte_3F58902 & 1) != 0)
  {
    if (aKakudo >= 360.0)
    {
      do
LABEL_5:
        v3 = v3 + -360.0;
      while (v3 >= 360.0);
    }
  }
  else
  {
    if (v3 >= 360.0)
      goto LABEL_5;
  }
  while (v3 < 0.0)
    v3 = v3 + 360.0;
  v4 = v3 % 360;
  v5 = 0.0;
  v6 = v4;
  v7 = 0.0 - v4;
  if (v7 > 180.0 || (v8 = v7 < -180.0, v9 = v4, v8))
  {
    v9 = v4 <= 0 ? v6 + 360.0 : v4;
    v5 = 0.0;
    if (v4 > 0)
      v5 = 360.0;
  }
  v10 = v9 - v5;
  v12 = sdfFabs(v10);
  if (v12 >= 900.0)
    v13 = 900.0;
  else
    v13 = v12;
  if (v12 < 900.0)
    v14 = 0;
  else
    v14 = -1;
  if ((90.0 - v6) > 180.0 || (90.0 - v6) < -180.0)
  {
    if (v4 <= 90)
      v17 = v6 + 360.0;
    else
      v17 = v4;
    v16 = v17 - flt_32C3128[v4 > 90];
      goto LABEL_41;
  }
  else
  {
    v16 = v6 - 90.0;
      goto LABEL_41;
  }
LABEL_41:
  v19 = sdfFabs(v16);
  if (v19 < v13)
  {
    v14 = 2;
    v13 = v19;
  }
  else
  {
    v20 = 180.0 - v6;
    if ((180.0 - v6) > 180.0)
      goto LABEL_51;
  }
  if (v20 >= -180.0)
  {
    v22 = v6 - 180.0;
      goto LABEL_54;
    goto LABEL_48;
  }
LABEL_51:
  v23 = v6 + 360.0;
  if (v4 > 180)
    v23 = v4;
  v22 = v23 - flt_32C3138[v4 > 180];
  {
LABEL_48:
  }
LABEL_54:
  v25 = sdfFabs(v22);
  if (v25 >= v13)
  {
    v26 = v13;
  }
  else
  {
    v14 = 4;
    v26 = v25;
  }
  if ((270.0 - v6) <= 180.0 && (270.0 - v6) >= -180.0)
  {
    v28 = v6 - 270.0;
      goto LABEL_68;
    goto LABEL_63;
  }
  if (v4 <= 270)
    v6 = v6 + 360.0;
  v28 = v6 - flt_32C3148[v4 > 270];
  {
LABEL_63:
  }
LABEL_68:
  if (sdfFabs(v28) >= v26)
    v29 = v14;
  else
    v29 = 6;
  if (v29 <= 6 && ((0x55u >> v29) & 1) != 0)
    return flt_33CC02C[v29];
  else
    return v3;
}

// 0x10ca3c0
f32 fldPlayerCalc360_8(f32 aKakudo) {
  f32 v3;
  s32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  bool v8;
  f32 v9;
  f32 v10;
  f32 v12;
  f32 v13;
  s32 v14;
  f32 v16;
  f32 v17;
  f32 v19;
  f32 v21;
  f32 v22;
  f32 v24;
  f32 v26;
  f32 v27;
  f32 v29;
  f32 v30;
  f32 v32;
  f32 v33;
  f32 v35;
  f32 v37;
  f32 v38;
  f32 v40;
  s32 v41;
  f32 v43;
  f32 v44;
  f32 v46;
  f32 v48;
  s32 v49;

  v3 = aKakudo;
  if ((byte_3F58901 & 1) != 0)
  {
    if (aKakudo >= 360.0)
    {
      do
LABEL_5:
        v3 = v3 + -360.0;
      while (v3 >= 360.0);
    }
  }
  else
  {
    if (v3 >= 360.0)
      goto LABEL_5;
  }
  while (v3 < 0.0)
    v3 = v3 + 360.0;
  v4 = v3 % 360;
  v5 = 0.0;
  v6 = v4;
  v7 = 0.0 - v4;
  if (v7 > 180.0 || (v8 = v7 < -180.0, v9 = v4, v8))
  {
    v9 = v4 <= 0 ? v6 + 360.0 : v4;
    v5 = 0.0;
    if (v4 > 0)
      v5 = 360.0;
  }
  v10 = v9 - v5;
  v12 = sdfFabs(v10);
  if (v12 >= 900.0)
    v13 = 900.0;
  else
    v13 = v12;
  if (v12 < 900.0)
    v14 = 0;
  else
    v14 = -1;
  if ((45.0 - v6) > 180.0 || (45.0 - v6) < -180.0)
  {
    if (v4 <= 45)
      v17 = v6 + 360.0;
    else
      v17 = v4;
    v16 = v17 - flt_32C3120[v4 > 45];
      goto LABEL_41;
  }
  else
  {
    v16 = v6 - 45.0;
      goto LABEL_41;
  }
LABEL_41:
  v19 = sdfFabs(v16);
  if (v19 < v13)
  {
    v13 = v19;
    v14 = 1;
  }
  if ((90.0 - v6) > 180.0 || (90.0 - v6) < -180.0)
  {
    if (v4 <= 90)
      v22 = v6 + 360.0;
    else
      v22 = v4;
    v21 = v22 - flt_32C3128[v4 > 90];
      goto LABEL_55;
  }
  else
  {
    v21 = v6 - 90.0;
      goto LABEL_55;
  }
LABEL_55:
  v24 = sdfFabs(v21);
  if (v24 < v13)
  {
    v14 = 2;
    v13 = v24;
  }
  if ((135.0 - v6) > 180.0 || (135.0 - v6) < -180.0)
  {
    if (v4 <= 135)
      v27 = v6 + 360.0;
    else
      v27 = v4;
    v26 = v27 - flt_32C3130[v4 > 135];
      goto LABEL_69;
  }
  else
  {
    v26 = v6 - 135.0;
      goto LABEL_69;
  }
LABEL_69:
  v29 = sdfFabs(v26);
  if (v29 < v13)
  {
    v14 = 3;
    v13 = v29;
  }
  else
  {
    v30 = 180.0 - v6;
    if ((180.0 - v6) > 180.0)
      goto LABEL_79;
  }
  if (v30 >= -180.0)
  {
    v32 = v6 - 180.0;
      goto LABEL_82;
    goto LABEL_76;
  }
LABEL_79:
  v33 = v6 + 360.0;
  if (v4 > 180)
    v33 = v4;
  v32 = v33 - flt_32C3138[v4 > 180];
  {
LABEL_76:
  }
LABEL_82:
  v35 = sdfFabs(v32);
  if (v35 < v13)
  {
    v14 = 4;
    v13 = v35;
  }
  if ((225.0 - v6) > 180.0 || (225.0 - v6) < -180.0)
  {
    if (v4 <= 225)
      v38 = v6 + 360.0;
    else
      v38 = v4;
    v37 = v38 - flt_32C3140[v4 > 225];
      goto LABEL_96;
  }
  else
  {
    v37 = v6 - 225.0;
      goto LABEL_96;
  }
LABEL_96:
  v40 = sdfFabs(v37);
  if (v40 >= v13)
    v41 = v14;
  else
    v41 = 5;
  if (v40 < v13)
    v13 = v40;
  if ((270.0 - v6) > 180.0 || (270.0 - v6) < -180.0)
  {
    if (v4 <= 270)
      v44 = v6 + 360.0;
    else
      v44 = v4;
    v43 = v44 - flt_32C3148[v4 > 270];
      goto LABEL_113;
  }
  else
  {
    v43 = v6 - 270.0;
      goto LABEL_113;
  }
LABEL_113:
  v46 = sdfFabs(v43);
  if (v46 < v13)
  {
    v41 = 6;
    v13 = v46;
  }
  if ((315.0 - v6) <= 180.0 && (315.0 - v6) >= -180.0)
  {
    v48 = v6 - 315.0;
      goto LABEL_126;
    goto LABEL_121;
  }
  if (v4 <= 315)
    v6 = v6 + 360.0;
  v48 = v6 - flt_32C3150[v4 > 315];
  {
LABEL_121:
  }
LABEL_126:
  if (sdfFabs(v48) >= v13)
    v49 = v41;
  else
    v49 = 7;
  if (v49 > 7)
    return v3;
  else
    return flt_32C20D4[v49];
}

// 0x10d9d10
void fldPlayerCalcForUnity(void) {
  UnityEngine_Transform_o *transform;
  struct fldUnitControl_t_o *fldUnitControl;
  dds3PoseSet_t_o **p_poseset;
  s32 v8;
  f32 *poseset;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  UnityEngine_Transform_o *v18;
  UnityEngine_Transform_o *v23;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  UnityEngine_Transform_o *v32;
  UnityEngine_Transform_o *v33;
  f32 FiledCeiling;
  f32 v37;
  UnityEngine_Transform_o *v38;
  struct fldGlobalWork_t_o *fldGb;
  UnityEngine_GameObject_o *PlayerCeiling;
  UnityEngine_GameObject_o *v45;
  bool v46;
  UnityEngine_Transform_o *v47;
  f32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  UnityEngine_GameObject_o *v57;
  UnityEngine_Transform_o *v60;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v63;
  f32 y;
  bool v66;
  dds3Basic_t_o *v68;
  UnityEngine_GameObject_o *v70;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v74;
  u32 *interfaceOffsets;
  f32 v76;
  s32 cammode;
  UnityEngine_Transform_o *v78;
  char *v79;
  s64 *v80;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Quaternion_o v82;
  char *v83;
  UnityEngine_Vector3_o v84;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v87;
  UnityEngine_Vector3_o v88;
  UnityEngine_Vector3_o v89;
  UnityEngine_Vector4_o v90;
  UnityEngine_Quaternion_o v91;

  *&rotation.x = 0;
  *&rotation.z = 0;
  else if (fldDbg->MenuOn)
  {
    return;
  }
  transform = get_transform(fldPlayerObj, 0);
  get_localPosition(transform);
  p_poseset = &fldUnitControl->handle->poseset;
  v8 = dds3CheckPoseSetFlag(p_poseset, 8u);
  poseset = fldUnitControl->handle->poseset;
  if (v8)
  {
    v11 = poseset[18];
    v12 = poseset[19];
    v14 = poseset[20];
    v13 = poseset[21];
      goto LABEL_22;
  }
  else
  {
    v11 = poseset[6];
    v12 = poseset[7];
    v14 = poseset[8];
    v13 = poseset[9];
    {
LABEL_22:
    }
  }
  v90.x = v11;
  v90.y = v12;
  v90.z = v14;
  v90.w = v13;
  v84 = op_Implicit_8738992(v90);
  v18 = get_transform(fldPlayerObj, 0);
  v87.x = v84.x / 100.0;
  v87.y = v84.y / -100.0;
  v87.z = v84.z / 100.0;
  set_localPosition(v18, v87);
  if (fldGb->fieldID <= 9)
  {
    v47 = get_transform(fldPlayerObj, 0);
    sub_854710(&fldUnitControl->handle->poseset->rot, 0);
    v49 = v48;
    sub_854710(&fldUnitControl->handle->poseset->rot, 1u);
    v51 = v50;
    sub_854710(&fldUnitControl->handle->poseset->rot, 2u);
    v53 = v52;
    sub_854710(&fldUnitControl->handle->poseset->rot, 3u);
    *&v82.x = 0;
    *&v82.z = 0;
    sub_1A1BDD0(&v82.x, v49, v51, v53, v54);
    set_localRotation(v47, v82);
  }
  else
  {
    v23 = get_transform(fldPlayerObj, 0);
    rotation = get_rotation(v23);
    sub_1A1CAE0(&rotation.x, 0);
    v27 = v26;
    v29 = v28;
    v30 = -fmodf(fldGb->PlayerKakudo + 180.0, 360.0);
    v32 = get_transform(fldPlayerObj, 0);
    v91 = Euler(v27, v30, v29);
    set_rotation(v32, v91);
    v33 = get_transform(fldPlayerObj, 0);
    position = get_position(v33);
    FiledCeiling = GetFiledCeiling(fldCameraParam, fldGb->fieldID);
    v37 = position.y + FiledCeiling;
    v38 = get_transform(PlayerCeiling, 0);
    v88.x = position.x;
    v88.y = v37;
    v88.z = position.z;
    set_position(v38, v88);
    if (!fldProcCheckFlag(0x40u))
      goto LABEL_58;
    if (fldGb->fieldID != 16)
      goto LABEL_69;
    if (fldGb->CamTableIdx == 4)
    {
LABEL_58:
      v45 = PlayerCeiling;
      v46 = 0;
    }
    else
    {
LABEL_69:
      v57 = PlayerCeiling;
      v45 = v57;
      v46 = 1;
    }
    cmpSetupObject(v45, v46);
    v60 = get_transform(fldPlayerObj, 0);
    Child = GetChild(v60, 0);
    gameObject = get_gameObject(Child);
    v63 = get_transform(gameObject, 0);
    localPosition = get_localPosition(v63);
    y = localPosition.y;
    v66 = evtBitCheck(2800);
    v68 = fldCamNowEveCamera(0);
    if (v68)
      v70 = gameObject;
    else
      v70 = 0;
    if (v68)
    {
      workdata = player->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, &v82);
        if ((LOBYTE(v82.x) & 1) != 0)
          v79 = v83;
        else
          v79 = &v82.x + 1;
        v80 = sub_8C4940(v79);
      }
      v74 = workdata[2].klass;
      if (v74)
      {
        interfaceOffsets = v74->_1.interfaceOffsets;
        if (interfaceOffsets)
        {
          if ((interfaceOffsets[4] & 1) != 0)
            gameObject = v70;
          else
            y = 0.0;
        }
      }
    }
    else
    {
      y = 0.0;
      v76 = 0.0;
      cammode = fldGb->cammode;
      if (cammode != 1)
      {
        v76 = -1000.0;
        if (cammode == 3)
          v76 = 0.0;
      }
      if (v66)
        y = v76;
    }
    v78 = get_transform(gameObject, 0);
    v89.x = localPosition.x;
    v89.y = y;
    v89.z = localPosition.z;
    set_localPosition(v78, v89);
  }
  CheckPlayerCtrl();
}

// 0x10cd2b0
s32 fldPlayerCalcHasigo(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  s32 gfldPlayerHasiCnt;
  dds3Basic_t_o **p_handle;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v21;
  f32 v22;
  struct fldGlobalWork_t_o *v23;
  f32 v24;
  struct fldGlobalWork_t_o *v25;
  f32 v26;
  UnityEngine_Vector4_o v27;

  *&v27.x = 0;
  *&v27.z = 0;
LABEL_7:
  *&v27.x = 0;
  *&v27.z = 0;
  else
  {
    if (gfldPlayerHasiCnt >= 1)
      goto LABEL_13;
  }
  else if ((gfldPlayerHasiCnt & 0x80000000) == 0)
  {
    return 0;
  }
  p_handle = &fldUnitControl->handle;
  dds3GetPosPoseSet(p_handle);
  SDF_VU0__STOREVECTOR(&v27);
  fldGb->playerOldX = fldGb->playerX;
  fldGb->playerOldY = fldGb->playerY;
  fldGb->playerOldZ = fldGb->playerZ;
  v21 = fldGb;
  sub_854710(&v27, 0);
  v21->playerX = v22;
  v23 = fldGb;
  sub_854710(&v27, 1u);
  v23->playerY = v24 + 1.95;
  v25 = fldGb;
  sub_854710(&v27, 2u);
  v25->playerZ = v26;
  sub_854930(&v27, 0);
LABEL_20:
  sub_854930(&v27, 1u);
  sub_854930(&v27, 2u);
  dds3SetPosPoseSet(p_handle, v27);
  fldPlayerSdwOff();
  fldPlayerSvsOff();
  return 0;
}

// 0x10d3c80
void fldPlayerCalc_FastStart(void) {
  struct fldPlayer_StaticFields **p_static_fields;

  else
  {
    if (fldWmWarpMode)
      return;
  }
  fldWmWarpMode = 2;
  (*p_static_fields)->fldWmFastMove = 60.0;
}

// 0x10c3190
void fldPlayerCalc_Hit(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  s64 v6;
  s64 v7;
  struct fldGlobal_StaticFields **p_static_fields;
  struct fldGlobalWork_t_o *fldGb;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  dds3Basic_t_o **p_handle;
  s64 v17;
  s64 v18;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o v21;

  *&p.x = 0;
  *&p.z = 0;
  v17 = 0;
  v18 = 0;
LABEL_7:
  *&p.x = 0;
  *&p.z = 0;
  v17 = 0;
  v18 = 0;
  if (fldUnitControl)
  {
    else if (gfldPlayerKakudo2Mode == 1)
    {
      return;
    }
    if (l_UseCollision)
    {
      sub_854930(&v17, 0);
      sub_854930(&v17, 1u);
      sub_854930(&v17, 2u);
      v6 = v17;
      v7 = v18;
      *&v20.x = v6;
      *&v20.z = v7;
      fldHitChkUnitElv(v20);
      if (fldGb->HitUpdate)
      {
        fldGb->playerX = fldGb->playerNewX;
        (*p_static_fields)->fldGb->playerY = (*p_static_fields)->fldGb->playerNewY;
        (*p_static_fields)->fldGb->playerZ = (*p_static_fields)->fldGb->playerNewZ;
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sub_854930(&p, 2u);
        x = p.x;
        y = p.y;
        z = p.z;
        w = p.w;
        p_handle = &fldUnitControl->handle;
        v21.x = x;
        v21.y = y;
        v21.z = z;
        v21.w = w;
        dds3SetPosPoseSet(p_handle, v21);
        fldGb->HitUpdate = 0;
        dds3GetPosPoseSet(p_handle);
        SDF_VU0__STOREVECTOR(&p);
        SDF_VU0__COPYVECTOR(&(*p_handle)->poseset->pos2, p, 0);
      }
    }
  }
}

// 0x10cd890
s32 fldPlayerCalc_Nml(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  fldUnitControl_t_Fields *p_fields;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3Basic_t_o **p_handle2;
  u64 v12;
  s32 MotionMinorNum;
  UnityEngine_GameObject_o *fldPlayerObj;
  s32 v20;
  fldGlobal_c *v22;
  s32 v23;
  u64 v25;
  struct dds3PoseSet_t_o *poseset;
  s64 p_pos2;
  struct dds3PoseSet_t_o *v29;
  s64 v30;
  struct dds3PoseSet_t_o *v31;
  s64 v32;
  fldPlayer_c *v38;
  dds3ModelHandle_t_o *v42;
  UnityEngine_GameObject_o *v45;
  struct dds3PoseSet_t_o *v53;
  s64 v54;
  struct dds3PoseSet_t_o *v55;
  s64 v56;
  struct dds3PoseSet_t_o *v57;
  s64 v58;
  f32 *v64;
  f32 v65;
  f32 v66;
  f32 v67;
  dds3PoseSet_t_o **p_poseset;
  dds3PoseSet_t_o **v73;
  struct System_Byte_array_array_array *dds3PadAnalog;
  System_Byte_array_array *v76;
  System_Byte_array *v77;
  u32 v79;
  bool v80;
  struct System_Byte_array_array_array *v81;
  System_Byte_array_array *v82;
  System_Byte_array *v83;
  u32 v84;
  struct System_Byte_array_array_array *v86;
  System_Byte_array_array *v87;
  System_Byte_array *v88;
  u32 v91;
  _BOOL4 v92;
  struct System_Byte_array_array_array *v93;
  System_Byte_array_array *v95;
  System_Byte_array *v97;
  u32 v99;
  s32 v100;
  s32 v101;
  bool v103;
  bool v104;
  char v106;
  s32 v110;
  s32 NoInpPlCnt;
  struct fldGlobalWork_t_o *fldGb;
  bool v116;
  f32 v117;
  struct fldGlobalWork_t_o *v118;
  f32 v119;
  struct fldGlobalWork_t_o *v120;
  f32 v122;
  dds3Basic_t_o **p_handle;
  s16 v126;
  s32 v127;
  struct fldGlobalWork_t_o *v141;
  f32 v142;
  f32 v143;
  fldGlobal_c *v145;
  s32 v148;
  s32 v149;
  s32 v150;
  s64 v152;
  s64 v153;
  s64 v154;
  s64 v155;
  s64 v156;
  s64 v157;
  s64 v158;
  dds3ModelHandle_t_o *v161;
  f32 PlayerKakudoGoal;
  f32 ooyCamKakudo;
  s16 v171;
  s32 v172;
  f32 v175;
  s16 v176;
  struct fldPlayer_StaticFields **p_static_fields;
  s32 v179;
  f32 v182;
  s16 v183;
  f32 *v185;
  f32 v186;
  f32 v187;
  f32 v188;
  f32 v192;
  s16 v193;
  f32 v196;
  s16 v197;
  s16 v199;
  s32 v200;
  f32 v203;
  s16 v204;
  f32 v207;
  s16 v208;
  struct fldGlobalWork_t_o *v210;
  s32 v211;
  f32 v212;
  fldPlayer_c *v216;
  f32 v217;
  s16 v218;
  s32 v219;
  f32 v222;
  s16 v223;
  f32 v226;
  s16 v227;
  s32 v228;
  f32 gJidouRotSpeed;
  f32 v232;
  s32 v235;
  f32 v237;
  f32 v238;
  s32 v243;
  s32 PlayerStayCnt;
  s32 v247;
  f32 v249;
  f32 v251;
  s16 v252;
  s32 v253;
  struct fldGlobalWork_t_o *v254;
  f32 PlayerSaka;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v260;
  struct fldGlobalWork_t_o *v263;
  f32 v265;
  f32 v266;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct fldGlobalWork_t_o *v275;
  f32 v276;
  struct fldGlobalWork_t_o *v277;
  f32 v278;
  struct fldGlobalWork_t_o *v279;
  f32 v280;
  s64 v282;
  s64 v283;
  struct fldGlobal_StaticFields **v284;
  struct fldGlobalWork_t_o *v285;
  f32 v287;
  f32 v288;
  f32 v289;
  f32 v290;
  f32 v292;
  f32 v293;
  f32 v295;
  f32 v296;
  f32 v297;
  s64 v298;
  f32 v299;
  f32 v300;
  f32 v302;
  f32 v303;
  f32 v304;
  s64 v305;
  f32 v306;
  f32 v307;
  f32 v309;
  f32 v310;
  f32 v311;
  s64 v312;
  s64 v313;
  s64 v314;
  s64 v315;
  s64 v316;
  f32 v317;
  f32 v318;
  f32 v319;
  f32 v320;
  struct fldGlobalWork_t_o *v325;
  f32 PlayerKakudo;
  f32 v328;
  f32 v329;
  f32 v330;
  f32 v332;
  f32 v333;
  s32 gKeyInputDir;
  f32 v335;
  f32 v336;
  f32 v340;
  f32 v341;
  f32 v343;
  f32 v344;
  f32 v345;
  f32 v346;
  f32 v349;
  f32 v350;
  f32 v351;
  f32 v352;
  struct fldGlobalWork_t_o *v354;
  s32 cammode;
  f32 v356;
  fldPlayer_c *v359;
  f32 v360;
  f32 v362;
  f32 v363;
  f32 v365;
  f32 v366;
  struct System_Byte_array_array_array *v369;
  System_Byte_array_array *v370;
  System_Byte_array *v371;
  struct System_Int32_array *gCameraWait;
  f32 v376;
  f32 v377;
  f32 v378;
  s16 v383;
  s32 v384;
  s32 v386;
  struct System_Single_array *gCameraSpeed;
  f32 v390;
  f32 v391;
  struct System_Single_array *v393;
  f32 v398;
  f32 v399;
  f32 v400;
  _BOOL4 v401;
  f32 v402;
  f32 v403;
  f32 v404;
  f32 v410;
  f32 v411;
  f32 v412;
  _BOOL4 v413;
  f32 v414;
  f32 v415;
  f32 v416;
  struct System_Single_array *v420;
  f32 v421;
  f32 v423;
  s16 v424;
  f32 v427;
  f32 v428;
  f32 v430;
  f32 v432;
  f32 fldCamKakudoGoal;
  f32 v435;
  f32 v436;
  _BOOL4 v437;
  bool v438;
  s32 v439;
  f32 v440;
  f32 v441;
  f32 v442;
  f32 v443;
  f32 v444;
  fldTest_c *v445;
  struct System_Byte_array_array_array *v447;
  System_Byte_array_array *v448;
  System_Byte_array *v449;
  struct System_Byte_array_array_array *v454;
  System_Byte_array_array *v455;
  System_Byte_array *v456;
  s32 v460;
  Il2CppClass *v462;
  f32 v463;
  f32 v465;
  fldPlayer_c *v468;
  struct fldGlobalWork_t_o *v470;
  f32 v471;
  f32 v473;
  f32 v474;
  f32 v475;
  f32 v476;
  f32 v479;
  f32 v480;
  f32 ooyCamLeng;
  s32 v495;
  s32 v496;
  struct datUnitWork_t_array *v501;
  struct datUnitWork_t_array *v504;
  s32 v506;
  struct fldGlobalWork_t_o *v508;
  f32 v509;
  struct fldGlobalWork_t_o *v510;
  f32 v511;
  struct fldGlobalWork_t_o *v512;
  f32 v514;
  s64 p_ppos01Point;
  struct fldResourcePoint_t_o *v517;
  struct fldResourcePoint_t_o *v518;
  struct fldResourcePoint_t_o *v519;
  struct UnityEngine_Vector4_o *p_rot;
  struct UnityEngine_Vector4_o *v521;
  struct UnityEngine_Vector4_o *v522;
  struct UnityEngine_Vector4_o *v523;
  f32 v526;
  f32 v530;
  f32 v531;
  struct System_Int32_array *v533;
  f32 v535;
  f32 v536;
  struct System_Int32_array *v538;
  f32 v540;
  f32 v541;
  struct System_Int32_array *v543;
  f32 v545;
  f32 v546;
  struct System_Int32_array *v548;
  f32 v550;
  f32 v551;
  struct System_Int32_array *v553;
  f32 v555;
  f32 v556;
  f32 v558;
  f32 v559;
  struct System_Single_array *v561;
  f32 v562;
  f32 v564;
  f32 v568;
  s16 v569;
  f32 v571;
  s16 v572;
  s32 v573;
  s32 v576;
  f32 v578;
  s16 v579;
  s16 v581;
  s32 v582;
  f32 v584;
  f32 v585;
  f32 v587;
  f32 v588;
  f32 v590;
  f32 v591;
  f32 v592;
  f32 v593;
  f32 v595;
  s16 v596;
  s32 v597;
  f32 v599;
  s16 v600;
  s32 v601;
  f32 v606;
  f32 v607;
  f32 v608;
  f32 v609;
  _BOOL4 v611;
  s32 v612;
  _BOOL4 v613;
  _BOOL4 v614;
  s32 v615;
  s32 PlayerAction;
  _BOOL4 v617;
  dds3Basic_t_o **pBasic;
  s32 v619;
  _BOOL4 v620;
  UnityEngine_Matrix4x4_o v621;
  s64 v622;
  s64 v623;
  u64 v624[2];
  UnityEngine_Vector4_o v625;
  UnityEngine_Vector4_o v626;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  u64 v629[4];
  UnityEngine_Vector4_o v630;
  UnityEngine_Vector4_o v631;
  UnityEngine_Vector4_o v632;
  UnityEngine_Vector4_o v633;
  UnityEngine_Vector4_o v634;
  UnityEngine_Vector4_o v635;
  UnityEngine_Vector4_o v636;
  UnityEngine_Vector4_o v637;
  UnityEngine_Vector4_o v638;
  UnityEngine_Vector4_o v639;

  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v626.x = 0;
  *&v626.z = 0;
  *&v625.x = 0;
  *&v625.z = 0;
  v624[0] = 0;
  v624[1] = 0;
  v622 = 0;
  v623 = 0;
LABEL_7:
  p_fields = &fldUnitControl->fields;
  ModelHandle = dds3ObjectBaseGetModelHandle(&fldUnitControl->handle);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v629);
      if ((v629[0] & 1) != 0)
        v8 = v629[2];
      else
        v8 = v629 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v626.x = 0;
  *&v626.z = 0;
  sub_854690(&v625.x, 0.0, 1.0, 0.0, 1.0);
  p_handle2 = &fldUnitControl->handle2;
  if (fldUnitControl->handle2)
    dds3ObjectBaseGetModelHandle(&fldUnitControl->handle2);
  else if (gfldPlayerAnaCnt > 0)
  {
LABEL_22:
    MotionMinorNum = mdlGetMotionMinorNum(v12);
    if (MotionMinorNum != 13)
    {
      fldPlayerSingleMotion(13, 0);
      if (MotionMinorNum == 8)
      {
        dds3FadeIn2(8u);
      }
    }
    v20 = mdlChkMotionEndForUnity_26964128(fldPlayerObj, 0);
    if (!v20)
    {
      fldPlayerMotionSe(MotionMinorNum, 13);
      return 0;
    }
    gfldPlayerAnaCnt = 0;
    fldProcOnFlag(0x40u);
    fldGb->NoInpPlCnt = 9;
    if ((v22->_2.bitflags2 & 2) != 0)
      goto LABEL_54;
    goto LABEL_64;
  }
  {
LABEL_54:
  }
LABEL_64:
  if (fldGb->GunDmgOn)
  {
    else if (gfldPlayerDamegeCnt < 1)
    {
      goto LABEL_125;
    }
    if (mdlGetMotionMinorNum(v25) != 10)
    {
      poseset = p_fields->handle->poseset;
      p_pos2 = &poseset->pos2;
      sub_854710(&poseset->pos, 0);
      sub_854930(p_pos2, 0);
      v29 = p_fields->handle->poseset;
      v30 = &v29->pos2;
      sub_854710(&v29->pos, 1u);
      sub_854930(v30, 1u);
      v31 = p_fields->handle->poseset;
      v32 = &v31->pos2;
      sub_854710(&v31->pos, 2u);
      sub_854930(v32, 2u);
      fldPlayerSingleMotion(10, 0);
      fldSePlay(34);
      dds3PadAct(0, 1u, 0x1Eu);
      dds3PadAct(1u, 0x64u, 0x1Eu);
      fldStatusSet();
    }
    if (--gfldPlayerDamegeCnt)
      return 0;
    fldGb->GunDmgOn = 0;
    if ((v38->_2.bitflags2 & 2) == 0)
    {
LABEL_121:
      gfldPlayerDamegeCnt = 0;
      fldProcOnFlag(0x40u);
LABEL_125:
      if (!fldProcCheckFlag(0x40u))
        return 0;
      else if (fldCamMiwatasiChk())
      {
        goto LABEL_132;
      }
      if (l_UseCollision)
      {
        p_poseset = &p_fields->handle->poseset;
        dds3OnPoseSetFlag(p_poseset, 8u);
        if (*p_handle2)
        {
          v73 = &(*p_handle2)->poseset;
          dds3OnPoseSetFlag(v73, 8u);
        }
      }
      v76 = dds3PadAnalog->m_Items[0];
      v77 = v76->m_Items[0];
      v79 = v77->m_Items[0];
      v80 = v79 < 0x40;
      v81 = dds3PadAnalog;
      v82 = v81->m_Items[0];
      v83 = v82->m_Items[0];
      v84 = v83->m_Items[0];
      v619 = v84 > 0xC0;
      v86 = dds3PadAnalog;
      v87 = v86->m_Items[0];
      v88 = v87->m_Items[0];
      v91 = v88->m_Items[1];
      v92 = v91 < 0x40;
      v93 = dds3PadAnalog;
      v95 = v93->m_Items[0];
      v97 = v95->m_Items[0];
      pBasic = &fldUnitControl->handle;
      v99 = v97->m_Items[1];
      v100 = v99 > 0xC0;
      if (v79 < 0x40)
      {
        v101 = 1;
      }
      else
      {
        v101 = 0;
        if (v91 >= 0x40 && v84 <= 0xC0 && v99 <= 0xC0)
        {
          v103 = DDS3_PADCHECK_PRESS(4);
          v104 = v103 || v80;
          v106 = DDS3_PADCHECK_PRESS(5) | v619;
          v101 = v104;
          v619 = v106 & 1;
          v100 = (DDS3_PADCHECK_PRESS(6) | v100) & 1;
          v92 = DDS3_PADCHECK_PRESS(7) || v91 < 0x40;
          {
LABEL_227:
            if (DDS3_PADCHECK_PRESS(3))
              goto LABEL_228;
            if (!DDS3_PADCHECK_PRESS(8))
              goto LABEL_237;
            if (DDS3_PADCHECK_PRESS(10))
LABEL_228:
              v110 = 1;
            else
LABEL_237:
              v110 = 0;
            NoInpPlCnt = fldGb->NoInpPlCnt;
            dds3GetPosPoseSet(pBasic);
            SDF_VU0__STOREVECTOR(&p);
            fldGb->playerOldX = fldGb->playerX;
            fldGb->playerOldY = fldGb->playerY;
            fldGb->playerOldZ = fldGb->playerZ;
            v116 = NoInpPlCnt < 1;
            sub_854710(&p, 0);
            fldGb->playerX = v117;
            v118 = fldGb;
            sub_854710(&p, 1u);
            v118->playerY = v119;
            v120 = fldGb;
            sub_854710(&p, 2u);
            v617 = v101 != 0 && NoInpPlCnt < 1;
            v613 = v619 != 0 && NoInpPlCnt < 1;
            v620 = v100 != 0 && NoInpPlCnt < 1;
            v120->playerZ = v122;
            v614 = v92 && NoInpPlCnt < 1;
            v612 = v614 || v620 || v617 || v613;
            p_handle = &fldUnitControl->handle;
            if (v612 == 1)
            {
              if (l_UseCollision)
              {
                if ((v126 & 0x200) != 0)
                {
                  v127 = v126 & 0x200;
                }
                else
                {
                  v127 = 0;
                }
                v141 = fldGb;
                if (v141->PlayerSaka <= 0.0)
                {
                  sub_854710(&p, 1u);
                  v143 = 10.0;
                }
                else
                {
                  sub_854710(&p, 1u);
                  v143 = 5.0;
                }
                v141->playerY = v142 + v143;
              }
            }
              goto LABEL_299;
LABEL_295:
            else
            {
              if (ooyCamKakudo >= 360.0)
                goto LABEL_300;
            }
            while (1)
            {
              if (ooyCamKakudo >= 0.0)
                break;
              ooyCamKakudo = ooyCamKakudo + 360.0;
            }
            {
LABEL_312:
            }
            while (fldGb->PlayerKakudo >= 360.0)
            {
              fldGb->PlayerKakudo = fldGb->PlayerKakudo + -360.0;
              if ((v145->_2.bitflags2 & 2) != 0)
                goto LABEL_312;
            }
            while (1)
            {
              if (fldGb->PlayerKakudo >= 0.0)
                break;
              fldGb->PlayerKakudo = fldGb->PlayerKakudo + 360.0;
            }
            dds3GetRotPoseSet(pBasic);
            SDF_VU0__STOREVECTOR(&v626);
            EulerAngleAxisY();
            sub_854690(v624, 0.0, 0.0, 0.0, 0.0);
            sub_19FFB10(&dds3CameraTM, 0, 0);
            LODWORD(v624[0]) = v148;
            sub_19FFB10(&dds3CameraTM, 0, 1);
            LODWORD(v624[0]) = v149;
            sub_19FFB10(&dds3CameraTM, 0, 2);
            LODWORD(v624[0]) = v150;
            v152 = *&dds3CameraTM.m00;
            v153 = *&dds3CameraTM.m01;
            v154 = *&dds3CameraTM.m21;
            *&v621.m20 = *&dds3CameraTM.m20;
            *&v621.m01 = v153;
            v155 = *&dds3CameraTM.m03;
            v156 = *&dds3CameraTM.m23;
            v158 = *&dds3CameraTM.m02;
            v157 = *&dds3CameraTM.m22;
            *&v621.m00 = v152;
            *&v621.m03 = v155;
            *&v621.m23 = v156;
            *&v621.m22 = v157;
            *&v621.m21 = v154;
            *&v621.m02 = v158;
            SDF_VU0__LOADMATRIX(&v621);
            InversMatrix();
            fldUnitControl->moveFlag = 0;
            v615 = mdlGetMotionMinorNum(v161);
            dds3GetPosPoseSet(pBasic);
            v611 = v110 != 0 && NoInpPlCnt < 1;
            if (!v611)
            {
              PlayerAction = 0;
                goto LABEL_349;
              goto LABEL_343;
            }
            PlayerAction = fldDbg->PlayerAction;
            if ((PlayerAction - 3) < 8)
              goto LABEL_348;
            if (PlayerAction)
            {
              if (PlayerAction == 1)
              {
LABEL_348:
                  goto LABEL_349;
                goto LABEL_343;
              }
              if (PlayerAction == 2)
              {
                if (DDS3_PADCHECK_TRIG(3))
                {
                  v185 = fldGb;
                  v186 = v185[78];
                  v187 = v185[79];
                  v188 = v185[80];
                  fldDmgStart(v186, v187, v188);
                  fldSePlay(34);
                }
                PlayerAction = 2;
                {
LABEL_349:
                  PlayerKakudoGoal = fldGb->PlayerKakudoGoal;
                  if (v620 && v617)
                  {
                    if ((v171 & 0x200) != 0)
                    {
                      v172 = v171 & 0x200;
                    }
                    else
                    {
                      v172 = 0;
                    }
                    PlayerKakudoGoal = 45.0 - ooyCamKakudo;
                    if (gKeyInputDir != 7)
                    {
                      v179 = 7;
LABEL_437:
                      gKeyInputDir = v179;
                      goto LABEL_438;
                    }
                    goto LABEL_572;
                  }
                  if (v619 != 0 && v620)
                  {
                    v175 = ooyCamKakudo;
                    if ((v176 & 0x200) != 0)
                    {
                      v172 = v176 & 0x200;
                    }
                    else
                    {
                      v172 = 0;
                    }
                    PlayerKakudoGoal = -45.0 - v175;
                    if (gKeyInputDir != 1)
                    {
                      v179 = 1;
                      goto LABEL_437;
                    }
LABEL_572:
                    ++gKeyInputCnt;
                    if ((v199 & 0x200) == 0)
                      goto LABEL_439;
                    goto LABEL_576;
                  }
                  if (v92 && v116 && v617)
                  {
                    v192 = ooyCamKakudo;
                    if ((v193 & 0x200) != 0)
                    {
                      v172 = v193 & 0x200;
                    }
                    else
                    {
                      v172 = 0;
                    }
                    PlayerKakudoGoal = 135.0 - v192;
                    if (gKeyInputDir != 5)
                    {
                      v179 = 5;
                      goto LABEL_437;
                    }
                    goto LABEL_572;
                  }
                  if (v619 != 0 && v92 && NoInpPlCnt < 1)
                  {
                    v182 = ooyCamKakudo;
                    if ((v183 & 0x200) != 0)
                    {
                      v172 = v183 & 0x200;
                    }
                    else
                    {
                      v172 = 0;
                    }
                    PlayerKakudoGoal = -135.0 - v182;
                    if (gKeyInputDir != 3)
                    {
                      v179 = 3;
                      goto LABEL_437;
                    }
                    goto LABEL_572;
                  }
                  if (v620)
                  {
                    v196 = ooyCamKakudo;
                    if ((v197 & 0x200) != 0)
                    {
                      v172 = v197 & 0x200;
                    }
                    else
                    {
                      v172 = 0;
                    }
                    PlayerKakudoGoal = -v196;
                    if (gKeyInputDir)
                    {
                      gKeyInputDir = 0;
LABEL_438:
                      (*p_static_fields)->gKeyInputCnt = 0;
                      if ((v199 & 0x200) == 0)
                      {
LABEL_439:
                        v200 = 0;
                        goto LABEL_579;
                      }
LABEL_576:
                      v200 = v199 & 0x200;
LABEL_579:
                      v254 = fldGb;
                      PlayerSaka = v254->PlayerSaka;
                      if (PlayerSaka > 0.0)
                      {
                        sdfFabs(PlayerSaka);
                      }
                      if ((fldDbg->PlayerStatus & 2) != 0)
                        goto LABEL_609;
                      {
                      }
                      unitwork = DDS3_GBWK->unitwork;
                      if ((unitwork->m_Items[0]->badstatus & 0x40) != 0)
                        goto LABEL_609;
                      {
                      }
                      v260 = DDS3_GBWK->unitwork;
                      if ((v260->m_Items[0]->badstatus & 0x100) != 0)
                      {
LABEL_609:
                          goto LABEL_610;
                      }
                      else
                      {
                          goto LABEL_610;
                      }
LABEL_610:
                      v263 = fldGb;
                      if (v263->fieldID == 17)
                      {
                        if (v263->areaID == 2
                        {
                        }
                      }
                      v265 = OOYRAD(-PlayerKakudoGoal);
                      sdfSin(v265);
                      sub_854930(&p, 0);
                      sub_854930(&p, 1u);
                      v266 = OOYRAD(-PlayerKakudoGoal);
                      sdfCos(v266);
                      sub_854930(&p, 2u);
                      x = p.x;
                      y = p.y;
                      z = p.z;
                      w = p.w;
                      v631.x = x;
                      v631.y = y;
                      v631.z = z;
                      v631.w = w;
                      dds3SetPosPoseSet(pBasic, v631);
                      v243 = 0;
                      v235 = 1;
                        goto LABEL_639;
                      goto LABEL_637;
                    }
                    goto LABEL_572;
                  }
                  if (v92 && NoInpPlCnt < 1)
                  {
                    v203 = ooyCamKakudo;
                    if ((v204 & 0x200) != 0)
                    {
                      v172 = v204 & 0x200;
                    }
                    else
                    {
                      v172 = 0;
                    }
                    PlayerKakudoGoal = 180.0 - v203;
                    if (gKeyInputDir != 4)
                    {
                      v179 = 4;
                      goto LABEL_437;
                    }
                    goto LABEL_572;
                  }
                  if (v617)
                  {
                    v207 = ooyCamKakudo;
                    if ((v208 & 0x200) != 0)
                    {
                      v172 = v208 & 0x200;
                    }
                    else
                    {
                      v172 = 0;
                    }
                    PlayerKakudoGoal = 90.0 - v207;
                    if (gKeyInputDir != 6)
                    {
                      v179 = 6;
                      goto LABEL_437;
                    }
                    goto LABEL_572;
                  }
                  if (v619 != 0 && NoInpPlCnt < 1)
                  {
                    v222 = ooyCamKakudo;
                    if ((v223 & 0x200) != 0)
                    {
                      v172 = v223 & 0x200;
                    }
                    else
                    {
                      v172 = 0;
                    }
                    PlayerKakudoGoal = -90.0 - v222;
                    if (gKeyInputDir != 2)
                    {
                      v179 = 2;
                      goto LABEL_437;
                    }
                    goto LABEL_572;
                  }
                  gKeyInputDir = -1;
                  gKeyInputCnt = 0;
                  {
                  }
                  v232 = Clamp(gJidouRotSpeed + -0.1, 0.0, 1.0);
                  gJidouRotSpeed = v232;
                  if (PlayerStayCnt <= 0)
                    v235 = 8;
                  else
                    v235 = v615;
                  sub_854930(&p, 0);
                  sub_854930(&p, 1u);
                  sub_854930(&p, 2u);
                  v238 = p.x;
                  v237 = p.y;
                  v630.z = p.z;
                  v630.w = p.w;
                  v630.x = v238;
                  v630.y = v237;
                  dds3SetPosPoseSet(pBasic, v630);
                  v243 = 0;
                  {
LABEL_542:
                    if (PlayerStayCnt < 1)
                    {
LABEL_641:
                      if (l_UseCollision)
                      {
                        if (v613 || v617 || v620 || v614)
                        {
                          v622 = 0;
                          v623 = 0;
                          v275 = fldGb;
                          sub_854710(&p, 0);
                          v275->playerX = v276;
                          v277 = fldGb;
                          sub_854710(&p, 1u);
                          v277->playerY = v278;
                          v279 = fldGb;
                          sub_854710(&p, 2u);
                          v279->playerZ = v280;
                          sub_854930(&v622, 0);
                          sub_854930(&v622, 1u);
                          sub_854930(&v622, 2u);
                          v282 = v622;
                          v283 = v623;
                          *&v632.x = v282;
                          *&v632.z = v283;
                          fldHitChkUnit(v632);
                          v285 = fldGb;
                          if (v285->HitUpdate)
                          {
                            v285->playerX = v285->playerNewX;
                            (*v284)->fldGb->playerY = (*v284)->fldGb->playerNewY + 44.0;
                            (*v284)->fldGb->playerZ = (*v284)->fldGb->playerNewZ;
                            sub_854930(&p, 0);
                            sub_854930(&p, 1u);
                            sub_854930(&p, 2u);
                            v288 = p.x;
                            v287 = p.y;
                            v290 = p.z;
                            v289 = p.w;
                            v633.x = v288;
                            v633.y = v287;
                            v633.z = v290;
                            v633.w = v289;
                            dds3SetPosPoseSet(p_handle, v633);
                            fldGb->HitUpdate = 0;
                          }
                          playerRun = 1;
                        }
                        dds3GetPosPoseSet(p_handle);
                        SDF_VU0__STOREVECTOR(&p);
                        SDF_VU0__COPYVECTOR(&dst, (*p_handle)->poseset->pos2, 0);
                        sub_854710(&dst, 0);
                        v293 = v292;
                        sub_854710(&p, 0);
                        v296 = v295;
                        v297 = sdfFabs(v293 - v296);
                        v298 = &(*p_handle)->poseset->pos2;
                        if (v297 >= 1.0)
                        {
                          sub_854710(&dst, 0);
                          sub_854710(&p, 0);
                          sub_854710(&dst, 0);
                        }
                        else
                        {
                          sub_854710(&p, 0);
                        }
                        sub_854930(v298, 0);
                        sub_854710(&dst, 1u);
                        v300 = v299;
                        sub_854710(&p, 1u);
                        v303 = v302;
                        v304 = sdfFabs(v300 - v303);
                        v305 = &(*p_handle)->poseset->pos2;
                        if (v304 >= 1.0)
                        {
                          sub_854710(&dst, 1u);
                          sub_854710(&p, 1u);
                          sub_854710(&dst, 1u);
                        }
                        else
                        {
                          sub_854710(&p, 1u);
                        }
                        sub_854930(v305, 1u);
                        sub_854710(&dst, 2u);
                        v307 = v306;
                        sub_854710(&p, 2u);
                        v310 = v309;
                        v311 = sdfFabs(v307 - v310);
                        v312 = &(*p_handle)->poseset->pos2;
                        if (v311 >= 1.0)
                        {
                          sub_854710(&dst, 2u);
                          sub_854710(&p, 2u);
                          sub_854710(&dst, 2u);
                        }
                        else
                        {
                          sub_854710(&p, 2u);
                        }
                        sub_854930(v312, 2u);
                        sub_854930(&(*p_handle)->poseset->pos2, 3u);
                        if (*p_handle2)
                        {
                          v313 = &(*p_handle2)->poseset->pos2;
                          sub_854710(&(*p_handle)->poseset->pos2, 0);
                          sub_854930(v313, 0);
                          v314 = &(*p_handle2)->poseset->pos2;
                          sub_854710(&(*p_handle)->poseset->pos2, 1u);
                          sub_854930(v314, 1u);
                          v315 = &(*p_handle2)->poseset->pos2;
                          sub_854710(&(*p_handle)->poseset->pos2, 2u);
                          sub_854930(v315, 2u);
                          v316 = &(*p_handle2)->poseset->pos2;
                          sub_854710(&(*p_handle)->poseset->pos2, 3u);
                          sub_854930(v316, 3u);
                        }
                      }
                      v318 = p.x;
                      v317 = p.y;
                      v320 = p.z;
                      v319 = p.w;
                      v634.x = v318;
                      v634.y = v317;
                      v634.z = v320;
                      v634.w = v319;
                      fldHitChkUnitDamage(v634);
                      for (; PlayerKakudoGoal >= 360.0; PlayerKakudoGoal = PlayerKakudoGoal + -360.0)
                        ;
                      while (PlayerKakudoGoal < 0.0)
                        PlayerKakudoGoal = PlayerKakudoGoal + 360.0;
                      v325 = fldGb;
                      v325->PlayerKakudoGoal = fldPlayerCalc360_8(PlayerKakudoGoal);
                      PlayerKakudo = fldGb->PlayerKakudo;
                      if (PlayerKakudo >= 0.0)
                      {
                        v328 = PlayerKakudoGoal;
                      }
                      else
                      {
                        PlayerKakudo = PlayerKakudo + 360.0;
                        v328 = PlayerKakudoGoal + 360.0;
                      }
                      v329 = (PlayerKakudo % 360);
                      v330 = (v328 % 360);
                      if ((v329 - v330) > 180.0 || (v329 - v330) < -180.0)
                      {
                        if (v329 >= v330)
                          v330 = v330 + 360.0;
                        else
                          v329 = v329 + 360.0;
                      }
                      v332 = v330 - v329;
                      v333 = 3.0;
                      if (gKeyInputDir != 2)
                      {
                        if (gKeyInputDir != 6)
                        {
                          if (gKeyInputDir != 3)
                          {
                            if (gKeyInputDir != 5)
                            {
                              if (gKeyInputDir == 1)
                              {
                                v333 = 5.0;
                              }
                              else
                              {
                                if (gKeyInputDir == 7)
                                  v333 = 5.0;
                                else
                                  v333 = 6.0;
                              }
                            }
                          }
                        }
                      }
                      v335 = v332 / v333;
                      if (v243)
                        v335 = v332 * 0.5;
                      if (v335 < 0.0)
                        v335 = -v335;
                      v336 = fmaxf(v335, 2.0);
                      if ((v332 < 0.0 || v332 > v336) && (v332 > 0.0 || v332 < -v336))
                      {
                        if (v332 < 0.0)
                        {
                          {
                          }
                          PlayerKakudoGoal = fldGb->PlayerKakudo - v336;
                          {
LABEL_754:
                            fldGb->PlayerKakudo = PlayerKakudoGoal;
                            SDF_VU0__LOADVECTOR(v625);
                            v340 = fldGb->PlayerKakudo;
                            v341 = OOYRAD(v340);
                            FromRotation(v341);
                            SDF_VU0__STOREVECTOR(&v626);
                            v344 = v626.x;
                            v343 = v626.y;
                            v346 = v626.z;
                            v345 = v626.w;
                            v635.x = v344;
                            v635.y = v343;
                            v635.z = v346;
                            v635.w = v345;
                            dds3SetRotPoseSet(p_handle, v635);
                            if (*p_handle2)
                            {
                              v350 = v626.x;
                              v349 = v626.y;
                              v352 = v626.z;
                              v351 = v626.w;
                              v636.x = v350;
                              v636.y = v349;
                              v636.z = v352;
                              v636.w = v351;
                              dds3SetRotPoseSet(p_handle2, v636);
                            }
                            v354 = fldGb;
                            cammode = v354->cammode;
                            if (cammode == 3)
                              goto LABEL_1107;
                            if (cammode == 1)
                            {
LABEL_1107:
                              if (ooyCamLeng >= 80.0)
                              {
                                {
                                }
                                gPlayerMsk -= 16;
                                if (gPlayerMsk < 0)
                                {
                                  {
                                  }
                                  gPlayerMsk = 0;
                                }
                              }
                              else
                              {
                                {
                                }
                                gPlayerMsk += 8;
                                if (gPlayerMsk >= 121)
                                {
                                  {
                                  }
                                  gPlayerMsk = 120;
                                  {
LABEL_1131:
                                    if (ooyCamLeng < 50.0)
                                    {
                                      {
                                      }
                                      gPlayerMsk = 128;
                                    }
                                    {
                                    }
                                    gPlayerMsk = 0;
                                    fldPlayerObjSetControlSvs(p_handle, gPlayerMsk, fldPlayerObj);
                                    fldPlayerOn();
                                    fldPlayerSdwOn();
                                    {
                                    }
                                    if ((fldGb->cammode | 2) == 3)
                                    {
                                      {
                                      }
                                      fldPlayerSvsOff();
                                      v495 = v615;
                                      v496 = PlayerAction - 1;
                                      if ((PlayerAction - 1) <= 9)
LABEL_1147:
                                        v235 = dword_33CC048[v496];
                                    }
                                    else
                                    {
                                      {
                                      }
                                      v526 = ooyCamLeng;
                                      v495 = v615;
                                      {
                                      }
                                      if (v526 >= CameraCamLeng)
                                      {
                                        {
                                        }
                                        fldPlayerSvsOff();
                                        v496 = PlayerAction - 1;
                                        if ((PlayerAction - 1) <= 9)
                                          goto LABEL_1147;
                                      }
                                      else
                                      {
                                        {
                                        }
                                        fldPlayerSvsOn();
                                        v496 = PlayerAction - 1;
                                        if ((PlayerAction - 1) <= 9)
                                          goto LABEL_1147;
                                      }
                                    }
                                    sub_854710(&(*p_handle)->poseset->pos, 1u);
                                    sub_854710(&(*p_handle)->poseset->pos2, 1u);
                                    {
                                    }
                                    if ((fldDbg->PlayerStatus & 2) != 0)
                                      goto LABEL_1164;
                                    {
                                    }
                                    v501 = DDS3_GBWK->unitwork;
                                    if ((v501->m_Items[0]->badstatus & 0x40) != 0)
                                      goto LABEL_1164;
                                    {
                                    }
                                    v504 = DDS3_GBWK->unitwork;
                                    if ((v504->m_Items[0]->badstatus & 0x100) != 0)
                                    {
LABEL_1164:
                                      v506 = v235 - 1;
                                      if ((v235 - 1) <= 7 && ((0xF9u >> v506) & 1) != 0)
                                        v235 = dword_32C2114[v506];
                                    }
                                    {
                                    }
                                    if ((byte_3F58927 & 1) != 0)
                                    {
                                      if (v495 == v235)
                                        goto LABEL_1172;
                                    }
                                    else
                                    {
                                      if (v495 == v235)
                                      {
LABEL_1172:
                                        {
LABEL_1180:
                                          v508 = fldGb;
                                          sub_854710(&p, 0);
                                          v508->playerX = v509;
                                          v510 = fldGb;
                                          sub_854710(&p, 1u);
                                          v510->playerY = v511;
                                          v512 = fldGb;
                                          sub_854710(&p, 2u);
                                          v512->playerZ = v514;
                                          {
                                          }
                                          p_ppos01Point = &ppos01Point;
                                          sub_854710(&(*p_handle)->poseset->pos2, 0);
                                          sub_854930(p_ppos01Point, 0);
                                          v517 = &ppos01Point;
                                          v23 = 1;
                                          sub_854710(&(*p_handle)->poseset->pos2, 1u);
                                          sub_854930(v517, 1u);
                                          v518 = &ppos01Point;
                                          sub_854710(&(*p_handle)->poseset->pos2, 2u);
                                          sub_854930(v518, 2u);
                                          v519 = &ppos01Point;
                                          sub_854710(&(*p_handle)->poseset->pos2, 3u);
                                          sub_854930(v519, 3u);
                                          p_rot = &ppos01Point.rot;
                                          sub_854710(&(*p_handle)->poseset->rot, 0);
                                          sub_854930(p_rot, 0);
                                          v521 = &ppos01Point.rot;
                                          sub_854710(&(*p_handle)->poseset->rot, 1u);
                                          sub_854930(v521, 1u);
                                          v522 = &ppos01Point.rot;
                                          sub_854710(&(*p_handle)->poseset->rot, 2u);
                                          sub_854930(v522, 2u);
                                          v523 = &ppos01Point.rot;
                                          sub_854710(&(*p_handle)->poseset->rot, 3u);
                                          sub_854930(v523, 3u);
                                          fldPlayerMotionSe(v495, v235);
                                          return v23;
                                        }
LABEL_1173:
                                        goto LABEL_1180;
                                      }
                                    }
                                    {
                                    }
                                    fldPlayerSingleMotion(v235, 0);
                                      goto LABEL_1180;
                                    goto LABEL_1173;
                                  }
LABEL_1129:
                                  goto LABEL_1131;
                                }
                              }
                                goto LABEL_1131;
                              goto LABEL_1129;
                            }
                            if (v243)
                            {
                              v356 = v354->PlayerKakudo;
                              ooyCamKakudo = -v356;
                              v360 = fldGb->PlayerKakudoGoal;
                              fldCamKakudoGoal = -v360;
                              *&ooyCamKakudo = LODWORD(fldCamKakudoGoal);
                              if (!v612)
                              {
LABEL_1034:
                                {
                                }
                                v447 = dds3PadAnalog;
                                v448 = v447->m_Items[0];
                                v449 = v448->m_Items[1];
                                if (v449->m_Items[0] != 128)
                                  goto LABEL_1103;
                                {
                                }
                                v454 = dds3PadAnalog;
                                v455 = v454->m_Items[0];
                                v456 = v455->m_Items[1];
                                if (v456->m_Items[1] != 128)
                                {
LABEL_1103:
                                  {
LABEL_1106:
                                    v480 = fldPlayerCalc360_8(fldCamKakudoGoal, v468);
                                    fldCamKakudoGoal = v480;
                                    fldPlayerCalc_Nml_old_gKeyInputDir = gKeyInputDir;
                                    goto LABEL_1107;
                                  }
LABEL_1104:
                                  goto LABEL_1106;
                                }
                                {
                                }
                                v460 = fldCameraCheckTurnType(v243);
                                if (v243)
                                {
                                  if (v460)
                                  {
                                    if (v460 != 1)
                                      goto LABEL_1103;
                                    {
                                    }
                                    v462 = v461[2].klass;
                                    v463 = 88.0;
                                  }
                                  else
                                  {
                                    {
                                    }
                                    v462 = v461[2].klass;
                                    v463 = -88.0;
                                  }
                                  *&v462->_1.gc_desc = *&v462->_1.gc_desc + v463;
                                  v465 = fldPlayerCalc360_4(*&v461[2].klass->_1.gc_desc);
                                  fldCamKakudoGoal = v465;
                                  {
                                  }
                                  fldGb->PlayerKakudoGoal = -fldCamKakudoGoal;
                                    goto LABEL_1106;
                                  goto LABEL_1104;
                                }
                                if (v460)
                                {
                                  if (v460 != 1)
                                    goto LABEL_1103;
                                  ooyCamKakudo = ooyCamKakudo + 4.5;
                                  if (!v611)
                                    goto LABEL_1096;
                                }
                                else
                                {
                                  ooyCamKakudo = ooyCamKakudo + -4.5;
                                  if (!v611)
                                    goto LABEL_1096;
                                }
                                {
                                }
                                v470 = fldGb;
                                v470->PlayerKakudo = -ooyCamKakudo;
                                SDF_VU0__LOADVECTOR(v625);
                                v471 = OOYRAD(fldGb->PlayerKakudo);
                                FromRotation(v471);
                                SDF_VU0__STOREVECTOR(&v626);
                                v474 = v626.x;
                                v473 = v626.y;
                                v476 = v626.z;
                                v475 = v626.w;
                                {
                                }
                                v637.x = v474;
                                v637.y = v473;
                                v637.z = v476;
                                v637.w = v475;
                                dds3SetRotPoseSet(p_handle, v637);
LABEL_1096:
                                v479 = ooyCamKakudo;
                                {
                                }
                                fldCamKakudoGoal = fldPlayerCalc360_8(v479);
                                goto LABEL_1103;
                              }
LABEL_987:
                              v430 = ooyCamKakudo;
                              if (SLODWORD(v430) == SLODWORD(fldCamKakudoGoal))
                                goto LABEL_1034;
                              v432 = ooyCamKakudo;
                              v435 = v432 + 360.0;
                              v436 = fldCamKakudoGoal + 360.0;
                              v437 = v432 < 0.0 || fldCamKakudoGoal < 0.0;
                              v438 = !v437;
                              if (!v437)
                                v435 = v432;
                              v439 = v435 % 360;
                              if (v438)
                                v436 = fldCamKakudoGoal;
                              v440 = v439;
                              v441 = (v436 % 360);
                              v442 = v439 - v441;
                              if (v442 > 180.0 || v442 < -180.0)
                              {
                                if (v440 >= v441)
                                  v441 = v441 + 360.0;
                                else
                                  v440 = v440 + 360.0;
                              }
                              v443 = v441 - v440;
                              if (gKeyInputDir)
                                v444 = 0.2;
                              else
                                v444 = 0.5;
                              if ((v443 < 0.0 || v443 > v444) && (v443 > 0.0 || v443 < -v444))
                              {
                                if (v443 >= 0.0)
                                {
                                  {
                                  }
                                  fldCamKakudoGoal = v444 + ooyCamKakudo;
                                  if ((v445->_2.bitflags2 & 2) == 0)
                                    goto LABEL_1033;
                                }
                                else
                                {
                                  {
                                  }
                                  fldCamKakudoGoal = ooyCamKakudo - v444;
                                  if ((v445->_2.bitflags2 & 2) == 0)
                                    goto LABEL_1033;
                                }
                              }
                              else
                              {
                                  goto LABEL_1033;
                              }
LABEL_1033:
                              ooyCamKakudo = fldCamKakudoGoal;
                              goto LABEL_1034;
                            }
                            v362 = gJidouRotSpeed;
                            {
                            }
                            v363 = 1.0;
                            v365 = Clamp(v362, 0.0, 1.0);
                            v366 = v365;
                            if (v365 >= 0.2)
                            {
                              if (v365 >= 0.3)
                              {
                                if (v365 < 0.5)
                                  v363 = 0.8;
                                {
LABEL_802:
                                  if (fldCameraCheckTurnType(0) != -1)
                                    goto LABEL_822;
                                  {
                                  }
                                  v369 = dds3PadAnalog;
                                  v370 = v369->m_Items[0];
                                  v371 = v370->m_Items[1];
                                  if (v371->m_Items[0] != 128)
                                  {
LABEL_822:
                                    {
                                    }
                                    v376 = gJidouRotSpeed;
                                    {
                                    }
                                    v377 = -0.05;
                                    goto LABEL_829;
                                  }
                                  {
                                  }
                                  if (gKeyInputDir == 3)
                                  {
                                    if (gKeyInputCnt > gCameraWait->m_Items[2])
                                    {
                                      {
LABEL_1208:
                                        v530 = gJidouRotSpeed;
                                        {
                                        }
                                        v531 = Clamp((v363 * 0.2) + v530, 0.0, 1.0, 0);
                                        gJidouRotSpeed = v531;
                                        goto LABEL_1212;
                                      }
LABEL_1206:
                                      goto LABEL_1208;
                                    }
                                    {
                                    }
                                    if (gJidouRotSpeed > 0.01)
                                    {
                                      if ((v359->_2.bitflags2 & 2) == 0)
                                        goto LABEL_1208;
                                      goto LABEL_1206;
                                    }
                                  }
LABEL_1212:
                                  if (gKeyInputDir == 5)
                                  {
                                    v533 = gCameraWait;
                                    if (gKeyInputCnt > v533->m_Items[2])
                                    {
                                      {
LABEL_1231:
                                        v535 = gJidouRotSpeed;
                                        {
                                        }
                                        v536 = Clamp((v363 * 0.2) + v535, 0.0, 1.0, 0);
                                        gJidouRotSpeed = v536;
                                        goto LABEL_1235;
                                      }
LABEL_1229:
                                      goto LABEL_1231;
                                    }
                                    {
                                    }
                                    if (gJidouRotSpeed > 0.01)
                                    {
                                      if ((v359->_2.bitflags2 & 2) == 0)
                                        goto LABEL_1231;
                                      goto LABEL_1229;
                                    }
                                  }
LABEL_1235:
                                  if (gKeyInputDir == 1)
                                  {
                                    v538 = gCameraWait;
                                    if (gKeyInputCnt > v538->m_Items[0])
                                    {
                                      {
LABEL_1254:
                                        v540 = gJidouRotSpeed;
                                        {
                                        }
                                        v541 = Clamp((v363 * 0.05) + v540, 0.0, 1.0, 0);
                                        gJidouRotSpeed = v541;
                                        goto LABEL_1258;
                                      }
LABEL_1252:
                                      goto LABEL_1254;
                                    }
                                    {
                                    }
                                    if (gJidouRotSpeed > 0.01)
                                    {
                                      if ((v359->_2.bitflags2 & 2) == 0)
                                        goto LABEL_1254;
                                      goto LABEL_1252;
                                    }
                                  }
LABEL_1258:
                                  if (gKeyInputDir == 7)
                                  {
                                    v543 = gCameraWait;
                                    if (gKeyInputCnt > v543->m_Items[0])
                                    {
                                      {
LABEL_1277:
                                        v545 = gJidouRotSpeed;
                                        {
                                        }
                                        v546 = Clamp((v363 * 0.05) + v545, 0.0, 1.0, 0);
                                        gJidouRotSpeed = v546;
                                        goto LABEL_1281;
                                      }
LABEL_1275:
                                      goto LABEL_1277;
                                    }
                                    {
                                    }
                                    if (gJidouRotSpeed > 0.01)
                                    {
                                      if ((v359->_2.bitflags2 & 2) == 0)
                                        goto LABEL_1277;
                                      goto LABEL_1275;
                                    }
                                  }
LABEL_1281:
                                  if (gKeyInputDir == 2)
                                  {
                                    v548 = gCameraWait;
                                    if (gKeyInputCnt > v548->m_Items[1])
                                    {
                                      {
LABEL_1300:
                                        v550 = gJidouRotSpeed;
                                        {
                                        }
                                        v551 = Clamp((v363 * 0.1) + v550, 0.0, 1.0, 0);
                                        gJidouRotSpeed = v551;
                                        goto LABEL_1304;
                                      }
LABEL_1298:
                                      goto LABEL_1300;
                                    }
                                    {
                                    }
                                    if (gJidouRotSpeed > 0.01)
                                    {
                                      if ((v359->_2.bitflags2 & 2) == 0)
                                        goto LABEL_1300;
                                      goto LABEL_1298;
                                    }
                                  }
LABEL_1304:
                                  if (gKeyInputDir != 6)
                                    goto LABEL_1327;
                                  v553 = gCameraWait;
                                  if (gKeyInputCnt <= v553->m_Items[1])
                                  {
                                    {
                                    }
                                    if (gJidouRotSpeed <= 0.01)
                                      goto LABEL_1327;
                                    if ((v359->_2.bitflags2 & 2) == 0)
                                    {
LABEL_1323:
                                      v555 = gJidouRotSpeed;
                                      {
                                      }
                                      v556 = Clamp((v363 * 0.1) + v555, 0.0, 1.0, 0);
                                      gJidouRotSpeed = v556;
LABEL_1327:
                                      if (gKeyInputDir == 4)
                                      {
                                        v558 = gJidouRotSpeed;
                                        {
                                        }
                                        v559 = Clamp(v558 + -0.1, 0.0, 1.0);
                                        gJidouRotSpeed = v559;
                                      }
                                      if (gKeyInputDir)
                                      {
LABEL_830:
                                        if (gKeyInputCnt > 3)
                                          goto LABEL_841;
                                        if (gJidouRotSpeed > 0.01)
                                        {
LABEL_841:
                                          if (gKeyInputDir == 1)
                                            goto LABEL_878;
                                        }
                                        if (gKeyInputCnt > 3)
                                          goto LABEL_853;
                                        if (gJidouRotSpeed > 0.01)
                                        {
LABEL_853:
                                          if (gKeyInputDir == 3)
                                            goto LABEL_878;
                                        }
                                        if (gKeyInputCnt > 3)
                                          goto LABEL_865;
                                        if (gJidouRotSpeed > 0.01)
                                        {
LABEL_865:
                                          if (gKeyInputDir == 5)
                                            goto LABEL_878;
                                        }
                                        if (gKeyInputCnt <= 3)
                                        {
                                          if (gJidouRotSpeed <= 0.01)
                                            goto LABEL_1530;
                                        }
                                        if (gKeyInputDir == 7)
                                        {
LABEL_878:
                                          v383 = *&v359->_2.bitflags1;
                                          if ((v383 & 0x200) != 0)
                                          {
                                            v384 = v383 & 0x200;
                                            v386 = gKeyInputDir;
                                            if (v386 == 3)
                                            {
LABEL_880:
                                              v390 = v366 * gCameraSpeed->m_Items[2];
                                              {
LABEL_888:
                                                v391 = v390 + ooyCamKakudo;
                                                {
LABEL_982:
                                                  ooyCamKakudo = v391;
                                                  v427 = ooyCamKakudo;
                                                  {
                                                  }
                                                  v428 = fldPlayerCalc360_8(v427);
                                                  fldCamKakudoGoal = v428;
                                                  goto LABEL_986;
                                                }
LABEL_980:
                                                goto LABEL_982;
                                              }
LABEL_886:
                                              goto LABEL_888;
                                            }
                                          }
                                          else
                                          {
                                            v384 = 0;
                                            v386 = gKeyInputDir;
                                            if (v386 == 3)
                                              goto LABEL_880;
                                          }
                                          if (v386 == 5)
                                          {
                                            v393 = gCameraSpeed;
                                            v390 = v366 * v393->m_Items[2];
                                              goto LABEL_978;
                                            goto LABEL_903;
                                          }
                                          {
                                          }
                                          v398 = fldGb->PlayerKakudo;
                                          {
                                          }
                                          v391 = -v398;
                                          v399 = ooyCamKakudo;
                                          {
                                          }
                                          v400 = v399 + 360.0;
                                          v401 = v398 > 0.0 || v399 < 0.0;
                                          if (!v401)
                                            v400 = v399;
                                          v402 = 360.0 - v398;
                                          if (!v401)
                                            v402 = -v398;
                                          v403 = (v400 % 360);
                                          v404 = (v402 % 360);
                                          if ((v403 - v404) > 180.0 || (v403 - v404) < -180.0)
                                          {
                                            if (v403 >= v404)
                                              v404 = v404 + 360.0;
                                            else
                                              v403 = v403 + 360.0;
                                          }
                                          v420 = gCameraSpeed;
                                          v421 = v404 - v403;
                                          v423 = v366 * (v421 / v420->m_Items[0]);
                                          if (v423 >= 0.0)
                                            v390 = v366 * (v421 / v420->m_Items[0]);
                                          else
                                            v390 = -v423;
                                          if ((v421 < 0.0 || v421 > v390) && (v421 > 0.0 || v421 < -v390))
                                          {
                                            if (v421 < 0.0)
                                              goto LABEL_977;
                                            goto LABEL_1360;
                                          }
                                        }
                                        else
                                        {
LABEL_1530:
                                          if (gKeyInputCnt <= 2)
                                          {
                                            if (gJidouRotSpeed <= 0.01)
                                              goto LABEL_945;
                                          }
                                          if (gKeyInputDir != 2)
                                          {
LABEL_945:
                                            if (gKeyInputCnt <= 2)
                                            {
                                              if (gJidouRotSpeed <= 0.01)
                                                goto LABEL_986;
                                            }
                                            if (gKeyInputDir != 6)
                                            {
LABEL_986:
                                              if (!v612)
                                                goto LABEL_1034;
                                              goto LABEL_987;
                                            }
                                          }
                                          {
                                          }
                                          v410 = fldGb->PlayerKakudo;
                                          {
                                          }
                                          v391 = -v410;
                                          v411 = ooyCamKakudo;
                                          {
                                          }
                                          v412 = v411 + 360.0;
                                          v413 = v410 > 0.0 || v411 < 0.0;
                                          if (!v413)
                                            v412 = v411;
                                          v414 = 360.0 - v410;
                                          if (!v413)
                                            v414 = -v410;
                                          v415 = (v412 % 360);
                                          v416 = (v414 % 360);
                                          if ((v415 - v416) > 180.0 || (v415 - v416) < -180.0)
                                          {
                                            if (v415 >= v416)
                                              v416 = v416 + 360.0;
                                            else
                                              v415 = v415 + 360.0;
                                          }
                                          v561 = gCameraSpeed;
                                          v562 = v416 - v415;
                                          v564 = v366 * (v562 / v561->m_Items[1]);
                                          if (v564 >= 0.0)
                                            v390 = v366 * (v562 / v561->m_Items[1]);
                                          else
                                            v390 = -v564;
                                          if ((v562 < 0.0 || v562 > v390) && (v562 > 0.0 || v562 < -v390))
                                          {
                                            if (v562 < 0.0)
                                            {
LABEL_977:
                                              if ((v424 & 0x200) == 0)
                                              {
LABEL_978:
                                                v391 = ooyCamKakudo - v390;
                                                goto LABEL_979;
                                              }
LABEL_903:
                                              goto LABEL_978;
                                            }
LABEL_1360:
                                            if ((v424 & 0x200) == 0)
                                              goto LABEL_888;
                                            goto LABEL_886;
                                          }
                                        }
LABEL_979:
                                          goto LABEL_982;
                                        goto LABEL_980;
                                      }
                                      v376 = gJidouRotSpeed;
                                      {
                                      }
                                      v377 = -0.1;
LABEL_829:
                                      v378 = Clamp(v376 + v377, 0.0, 1.0);
                                      gJidouRotSpeed = v378;
                                      goto LABEL_830;
                                    }
                                  }
                                  {
                                    goto LABEL_1323;
                                  }
                                  goto LABEL_1323;
                                }
                              }
                              else
                              {
                                v363 = 0.6;
                                  goto LABEL_802;
                              }
                            }
                            else
                            {
                              v363 = 0.4;
                                goto LABEL_802;
                            }
                            goto LABEL_802;
                          }
LABEL_752:
                          goto LABEL_754;
                        }
                        PlayerKakudoGoal = v336 + fldGb->PlayerKakudo;
                      }
                        goto LABEL_754;
                      goto LABEL_752;
                    }
                    v247 = PlayerStayCnt - 1;
LABEL_640:
                    PlayerStayCnt = v247;
                    goto LABEL_641;
                  }
LABEL_540:
                  goto LABEL_542;
                }
LABEL_343:
                goto LABEL_349;
              }
LABEL_427:
              PlayerAction = 0;
                goto LABEL_349;
              goto LABEL_343;
            }
            if ((fldGb->cammode | 2) == 3)
              goto LABEL_427;
            gJidouRotSpeed = 0.0;
            v210 = fldGb;
            v211 = v210->cammode;
            if (v211 != 3)
            {
              if (v211 != 1)
              {
                v212 = v210->PlayerKakudo;
                ooyCamKakudo = -v212;
              }
            }
            PlayerKakudoGoal = fldGb->PlayerKakudoGoal;
            if (v620 && v617)
            {
              v217 = ooyCamKakudo;
              if ((v218 & 0x200) != 0)
              {
                v219 = v218 & 0x200;
              }
              else
              {
                v219 = 0;
              }
              v249 = 45.0 - v217;
              if (gKeyInputDir == 7)
              {
                ++gKeyInputCnt;
                v235 = 6;
                if ((v216->_2.bitflags2 & 2) == 0)
                  goto LABEL_1426;
LABEL_1424:
                goto LABEL_1426;
              }
              gKeyInputDir = 7;
              gKeyInputCnt = 0;
              v235 = 6;
              if ((v216->_2.bitflags2 & 2) != 0)
                goto LABEL_1424;
LABEL_1426:
              if (gKeyInputDir > 7u)
              {
                if ((v581 & 0x200) == 0)
                  goto LABEL_1428;
              }
              else
              {
                if ((v581 & 0x200) == 0)
                {
LABEL_1428:
                  v582 = 0;
                  goto LABEL_1433;
                }
              }
              v582 = v581 & 0x200;
LABEL_1433:
              v584 = fldGb->PlayerSaka;
              if (v584 > 0.0)
              {
                sdfFabs(v584);
              }
              v585 = -v249;
              v587 = OOYRAD(-v249);
              sdfSin(v587);
              sub_854930(&p, 0);
              sub_854930(&p, 1u);
              v588 = OOYRAD(v585);
              sdfCos(v588);
              sub_854930(&p, 2u);
              v591 = p.x;
              v590 = p.y;
              v593 = p.z;
              v592 = p.w;
              v638.x = v591;
              v638.y = v590;
              v638.z = v593;
              v638.w = v592;
              dds3SetPosPoseSet(p_handle, v638);
              v243 = 1;
              PlayerAction = 0;
                goto LABEL_639;
LABEL_637:
LABEL_639:
              v247 = 2;
              goto LABEL_640;
            }
            if (v619 != 0 && v620)
            {
              v226 = ooyCamKakudo;
              if ((v227 & 0x200) != 0)
              {
                v228 = v227 & 0x200;
              }
              else
              {
                v228 = 0;
              }
              v249 = -45.0 - v226;
              if (gKeyInputDir == 1)
              {
                ++gKeyInputCnt;
                v235 = 5;
                if ((v216->_2.bitflags2 & 2) != 0)
                  goto LABEL_1424;
              }
              else
              {
                gKeyInputDir = 1;
                gKeyInputCnt = 0;
                v235 = 5;
                if ((v216->_2.bitflags2 & 2) != 0)
                  goto LABEL_1424;
              }
              goto LABEL_1426;
            }
            if (v92 && v116 && v617)
            {
              v568 = ooyCamKakudo;
              if ((v569 & 0x200) != 0)
              {
                v253 = v569 & 0x200;
              }
              else
              {
                v253 = 0;
              }
              v249 = 135.0 - v568;
              if (gKeyInputDir == 5)
                goto LABEL_1407;
              v576 = 5;
              goto LABEL_1421;
            }
            if (v619 != 0 && v92 && NoInpPlCnt < 1)
            {
              v251 = ooyCamKakudo;
              if ((v252 & 0x200) != 0)
              {
                v253 = v252 & 0x200;
              }
              else
              {
                v253 = 0;
              }
              v249 = -135.0 - v251;
              if (gKeyInputDir == 3)
              {
LABEL_1407:
                ++gKeyInputCnt;
                goto LABEL_1422;
              }
              v576 = 3;
LABEL_1421:
              gKeyInputDir = v576;
              gKeyInputCnt = 0;
LABEL_1422:
              v235 = 7;
              goto LABEL_1423;
            }
            if (v620)
            {
              v571 = ooyCamKakudo;
              if ((v572 & 0x200) != 0)
              {
                v573 = v572 & 0x200;
                v249 = -v571;
                if (!gKeyInputDir)
                  goto LABEL_1391;
              }
              else
              {
                v573 = 0;
                v249 = -v571;
                if (!gKeyInputDir)
                {
LABEL_1391:
                  ++gKeyInputCnt;
                  v235 = 1;
                  goto LABEL_1423;
                }
              }
              gKeyInputDir = 0;
              gKeyInputCnt = 0;
              v235 = 1;
            }
            else
            {
              if (v92 && NoInpPlCnt < 1)
              {
                v578 = ooyCamKakudo;
                if ((v579 & 0x200) != 0)
                {
                  v253 = v579 & 0x200;
                }
                else
                {
                  v253 = 0;
                }
                v249 = 180.0 - v578;
                if (gKeyInputDir == 4)
                  goto LABEL_1407;
                v576 = 4;
                goto LABEL_1421;
              }
              if (v617)
              {
                v595 = ooyCamKakudo;
                if ((v596 & 0x200) != 0)
                {
                  v597 = v596 & 0x200;
                }
                else
                {
                  v597 = 0;
                }
                v249 = 90.0 - v595;
                if (gKeyInputDir == 6)
                {
                  ++gKeyInputCnt;
                  v235 = 6;
                }
                else
                {
                  v235 = 6;
                  gKeyInputDir = 6;
                  gKeyInputCnt = 0;
                }
              }
              else
              {
                if (v619 == 0 || NoInpPlCnt >= 1)
                {
                  if (PlayerStayCnt <= 0)
                    v235 = 8;
                  else
                    v235 = v615;
                  gKeyInputDir = -1;
                  gKeyInputCnt = 0;
                  sub_854930(&p, 0);
                  sub_854930(&p, 1u);
                  sub_854930(&p, 2u);
                  v607 = p.x;
                  v606 = p.y;
                  v609 = p.z;
                  v608 = p.w;
                  p_handle = &fldUnitControl->handle;
                  v639.x = v607;
                  v639.y = v606;
                  v639.z = v609;
                  v639.w = v608;
                  dds3SetPosPoseSet(pBasic, v639);
                  PlayerAction = 0;
                  v243 = 1;
                    goto LABEL_542;
                  goto LABEL_540;
                }
                v599 = ooyCamKakudo;
                if ((v600 & 0x200) != 0)
                {
                  v601 = v600 & 0x200;
                }
                else
                {
                  v601 = 0;
                }
                v249 = -90.0 - v599;
                if (gKeyInputDir == 2)
                {
                  ++gKeyInputCnt;
                  v235 = 5;
                }
                else
                {
                  gKeyInputDir = 2;
                  gKeyInputCnt = 0;
                  v235 = 5;
                }
              }
            }
LABEL_1423:
            p_handle = &fldUnitControl->handle;
            if ((v216->_2.bitflags2 & 2) == 0)
              goto LABEL_1426;
            goto LABEL_1424;
          }
LABEL_225:
          goto LABEL_227;
        }
      }
        goto LABEL_227;
      goto LABEL_225;
    }
LABEL_93:
    goto LABEL_121;
  }
  else if (gfldPlayerDamegeCnt < 1)
  {
    goto LABEL_125;
  }
  if (!fldGb->DmgOn)
  {
    if ((fldDbg->PlayerStatus & 1) != 0)
    {
      fldSePlay(34);
      dds3FadeIn(0x80u, 0x20u, 0x20u, 6u);
      dds3PadAct(0, 1u, 6u);
      dds3PadAct(1u, 0x96u, 6u);
      fldStatusSet();
      gfldPlayerDamegeCnt = 0;
      fldProcOnFlag(0x40u);
      return 0;
    }
  }
  if (mdlGetMotionMinorNum(v42) == 10)
  {
    v45 = fldPlayerObj;
    if (!mdlChkMotionEndForUnity_26964128(v45, 0))
      return 0;
    Write("damage off\n", 0);
      goto LABEL_121;
    goto LABEL_93;
  }
  v53 = p_fields->handle->poseset;
  v54 = &v53->pos2;
  sub_854710(&v53->pos, 0);
  sub_854930(v54, 0);
  v55 = p_fields->handle->poseset;
  v56 = &v55->pos2;
  sub_854710(&v55->pos, 1u);
  sub_854930(v56, 1u);
  v57 = p_fields->handle->poseset;
  v58 = &v57->pos2;
  sub_854710(&v57->pos, 2u);
  sub_854930(v58, 2u);
  Write("damage on\n", 0);
  fldPlayerSingleMotion(10, 0);
  v64 = fldGb;
  v65 = v64[78];
  v66 = v64[79];
  v67 = v64[80];
  fldDmgStart(v65, v66, v67);
  fldSePlay(34);
  dds3PadAct(0, 1u, 0x1Eu);
  dds3PadAct(1u, 0x96u, 0x1Eu);
  fldStatusSet();
  return 0;
}

// 0x10d68f0
s32 fldPlayerCalc_Nml_syukan(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11;
  s32 MotionMinorNum;
  UnityEngine_GameObject_o *fldPlayerObj;
  s32 v19;
  fldGlobal_c *v21;
  s32 v22;
  u64 v24;
  fldPlayer_c *v30;
  dds3ModelHandle_t_o *v33;
  s32 v36;
  UnityEngine_GameObject_o *v38;
  dds3PoseSet_t_o **p_poseset;
  s32 v47;
  _BOOL4 v48;
  char v49;
  s32 v50;
  s32 v51;
  f32 *v54;
  f32 v55;
  f32 v56;
  f32 v57;
  bool v62;
  bool v64;
  bool v66;
  bool v68;
  bool v74;
  struct fldGlobalWork_t_o *fldGb;
  s32 NoInpPlCnt;
  s32 v78;
  _BOOL4 v84;
  s32 v85;
  s32 v88;
  struct fldGlobalWork_t_o *v91;
  _BOOL4 v92;
  f32 v93;
  struct fldGlobalWork_t_o *v94;
  f32 v95;
  struct fldGlobalWork_t_o *v96;
  s32 v98;
  f32 v99;
  s16 v102;
  s32 v103;
  struct fldGlobalWork_t_o *v104;
  f32 v105;
  f32 v106;
  fldGlobal_c *v108;
  s64 v112;
  s64 v113;
  s64 v114;
  s64 v115;
  s64 v116;
  s64 v117;
  s64 v118;
  dds3ModelHandle_t_o *v121;
  s32 v122;
  _BOOL4 v125;
  s32 v126;
  f32 v128;
  fldGlobal_c *v130;
  f32 ooyCamKakudo;
  f32 PlayerSaka;
  s16 v133;
  s32 v134;
  f32 PlayerKakudoGoal;
  f32 v137;
  f32 v138;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s32 v145;
  struct fldGlobalWork_t_o *v148;
  f32 v149;
  struct fldGlobalWork_t_o *v150;
  f32 v151;
  struct fldGlobalWork_t_o *v152;
  f32 v153;
  s64 v155;
  s64 v156;
  struct fldGlobal_StaticFields **p_static_fields;
  struct fldGlobalWork_t_o *v158;
  f32 v160;
  f32 v161;
  f32 v162;
  f32 v163;
  f32 v164;
  f32 v165;
  f32 v167;
  f32 v168;
  f32 v169;
  s64 p_pos2;
  f32 v171;
  f32 v172;
  f32 v174;
  f32 v175;
  f32 v176;
  s64 v177;
  f32 v178;
  f32 v179;
  f32 v181;
  f32 v182;
  f32 v183;
  s64 v184;
  f32 v185;
  f32 v186;
  f32 v187;
  f32 v188;
  struct fldGlobalWork_t_o *v193;
  fldGlobal_c *v195;
  f32 PlayerKakudo;
  f32 v197;
  f32 v198;
  f32 v199;
  f32 v200;
  f32 v201;
  f32 v202;
  f32 v203;
  f32 v205;
  f32 v206;
  f32 v208;
  f32 v209;
  f32 v210;
  f32 v211;
  fldPlayer_c *v213;
  fldTest_c *v214;
  f32 v216;
  s32 v217;
  f32 fldCamKakudoGoal;
  f32 v221;
  f32 v222;
  f32 v225;
  f32 v226;
  f32 v227;
  f32 v228;
  f32 v229;
  f32 v230;
  f32 v233;
  f32 v234;
  fldPlayer_c *v236;
  f32 v239;
  f32 v240;
  f32 v242;
  f32 v243;
  u64 v244;
  f32 v245;
  f32 v246;
  s32 gFldPlayerSyukanDly;
  f32 v249;
  f32 v250;
  f32 v251;
  _BOOL4 v252;
  f32 v253;
  f32 v254;
  f32 v255;
  f32 v256;
  f32 v257;
  struct fldGlobalWork_t_o *v260;
  f32 v262;
  f32 v264;
  f32 v265;
  f32 v266;
  f32 v267;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v274;
  s32 v279;
  struct fldGlobalWork_t_o *v280;
  f32 v281;
  struct fldGlobalWork_t_o *v282;
  f32 v283;
  struct fldGlobalWork_t_o *v284;
  f32 v285;
  s64 p_ppos01Point;
  struct fldResourcePoint_t_o *v290;
  struct fldResourcePoint_t_o *v291;
  struct fldResourcePoint_t_o *v292;
  struct UnityEngine_Vector4_o *p_rot;
  struct UnityEngine_Vector4_o *v294;
  struct UnityEngine_Vector4_o *v295;
  struct UnityEngine_Vector4_o *v296;
  f32 v300;
  f32 v301;
  f32 v302;
  f32 v303;
  __int128 v304;
  _BOOL4 v305;
  s32 v306;
  dds3Basic_t_o **v307;
  struct fldUnitControl_t_o *v308;
  s32 v309;
  s64 v310;
  bool v311;
  _BOOL4 v312;
  s32 v313;
  s32 v314;
  s32 v315;
  UnityEngine_Matrix4x4_o v316;
  s64 v317;
  s64 v318;
  UnityEngine_Vector4_o v319;
  UnityEngine_Vector4_o v320;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  u64 v323[4];
  UnityEngine_Vector4_o v324;
  UnityEngine_Vector4_o v325;
  UnityEngine_Vector4_o v326;
  UnityEngine_Vector4_o v327;
  UnityEngine_Vector4_o v328;
  UnityEngine_Vector4_o v329;
  UnityEngine_Vector4_o v330;

  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v320.x = 0;
  *&v320.z = 0;
  *&v319.x = 0;
  *&v319.z = 0;
  v317 = 0;
  v318 = 0;
LABEL_7:
  p_handle = &fldUnitControl->handle;
  ModelHandle = dds3ObjectBaseGetModelHandle(&fldUnitControl->handle);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v323);
      if ((v323[0] & 1) != 0)
        v8 = v323[2];
      else
        v8 = v323 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v320.x = 0;
  *&v320.z = 0;
  sub_854690(&v319.x, 0.0, 1.0, 0.0, 1.0);
  else if (gfldPlayerAnaCnt > 0)
  {
LABEL_20:
    MotionMinorNum = mdlGetMotionMinorNum(v11);
    if (MotionMinorNum != 13)
    {
      fldPlayerSingleMotion(13, 0);
      if (MotionMinorNum == 8)
      {
        dds3FadeIn2(8u);
      }
    }
    v19 = mdlChkMotionEndForUnity_26964128(fldPlayerObj, 0);
    if (!v19)
    {
      fldPlayerMotionSe(MotionMinorNum, 13);
      return 0;
    }
    gfldPlayerAnaCnt = 0;
    fldProcOnFlag(0x40u);
    fldGb->NoInpPlCnt = 14;
    if ((v21->_2.bitflags2 & 2) != 0)
      goto LABEL_52;
    goto LABEL_62;
  }
  {
LABEL_52:
  }
LABEL_62:
  if (fldGb->GunDmgOn)
  {
    else if (gfldPlayerDamegeCnt < 1)
    {
      goto LABEL_122;
    }
    if (mdlGetMotionMinorNum(v24) != 10)
    {
      fldPlayerSingleMotion(10, 0);
      fldSePlay(34);
      dds3PadAct(0, 1u, 0x1Eu);
      dds3PadAct(1u, 0x64u, 0x1Eu);
      fldStatusSet();
    }
    if (--gfldPlayerDamegeCnt)
      return 0;
    fldGb->GunDmgOn = 0;
    if ((v30->_2.bitflags2 & 2) == 0)
    {
LABEL_118:
      gfldPlayerDamegeCnt = 0;
      fldProcOnFlag(0x40u);
LABEL_122:
      else if (fldCamMiwatasiChk())
      {
        goto LABEL_125;
      }
      if (l_UseCollision)
      {
        p_poseset = &(*p_handle)->poseset;
        dds3OnPoseSetFlag(p_poseset, 8u);
      }
      v308 = fldUnitControl;
      if (gFldPlayerSyukanDly)
      {
        v47 = 0;
        v304 = 0u;
        v48 = 0;
        v310 = 0;
        v49 = 0;
        v50 = 0;
        v51 = 0;
        v314 = 0;
      }
      else
      {
        v62 = DDS3_PADCHECK_PRESS(4);
        v64 = DDS3_PADCHECK_PRESS(5);
        v66 = DDS3_PADCHECK_PRESS(6);
        v68 = DDS3_PADCHECK_PRESS(7);
        v311 = DDS3_PADCHECK_PRESS(3);
        if (DDS3_PADCHECK_PRESS(8))
        {
          DDS3_PADCHECK_TRIG(10);
        }
        if (DDS3_PADCHECK_TRIG(8))
        {
          DDS3_PADCHECK_PRESS(10);
        }
        if (DDS3_PADCHECK_TRIG(8))
        {
          DDS3_PADCHECK_TRIG(10);
        }
        v312 = DDS3_PADCHECK_PRESS(8);
        v74 = DDS3_PADCHECK_PRESS(10);
        HIDWORD(v310) = v74;
        v314 = v66;
        NoInpPlCnt = fldGb->NoInpPlCnt;
        v51 = v68;
        if (NoInpPlCnt < 1)
        {
          v78 = v311;
        }
        else
        {
          v78 = 0;
          fldGb->NoInpPlCnt = NoInpPlCnt - 1;
        }
        LODWORD(v310) = v64;
        v84 = 0;
        v49 = v312;
        v50 = v62;
        v85 = v314 | v51;
        v48 = 0;
        if (!v78 && !v85 && !v312 && !v74)
        {
          v48 = DDS3_PADCHECK_PRESS(4);
          v84 = DDS3_PADCHECK_PRESS(5);
        }
        DWORD2(v304) = v84;
        LODWORD(v304) = v51 & (v78 == 0) & ~v50 & (v310 ^ 1);
        if (v78)
        {
          if (v312)
          {
            DWORD1(v304) = 0;
            v47 = 1;
            HIDWORD(v304) = 1;
            v49 = 1;
          }
          else if (v74)
          {
            DWORD1(v304) = 1;
            HIDWORD(v304) = 0;
            v49 = 0;
            v47 = 1;
            HIDWORD(v310) = 1;
          }
          else
          {
            v49 = v50 & (v85 ^ 1);
            v47 = 1;
            DWORD1(v304) = 0;
            HIDWORD(v304) = 0;
            HIDWORD(v310) = v310 & (v85 ^ 1);
          }
        }
        else
        {
          v47 = 0;
          DWORD1(v304) = 0;
          HIDWORD(v304) = 0;
        }
      }
      v305 = v48;
      v313 = fldGb->NoInpPlCnt;
      if (v313 >= 1)
        v88 = 0;
      else
        v88 = v51;
      v309 = v88;
      dds3GetPosPoseSet(p_handle);
      SDF_VU0__STOREVECTOR(&p);
      v307 = p_handle;
      fldGb->playerOldX = fldGb->playerX;
      fldGb->playerOldY = fldGb->playerY;
      fldGb->playerOldZ = fldGb->playerZ;
      v91 = fldGb;
      v92 = v313 > 0;
      sub_854710(&p, 0);
      v91->playerX = v93;
      v94 = fldGb;
      sub_854710(&p, 1u);
      v94->playerY = v95;
      v96 = fldGb;
      sub_854710(&p, 2u);
      v98 = v50 == 0 || v92;
      v315 = v314 == 0 || v92;
      v96->playerZ = v99;
      v306 = HIDWORD(v310) == 0 || v92;
      if (v306 != 1 || v309 || !v315 || v310 != 0 && !v92 || !v98 || (v49 & (v313 < 1)) != 0)
      {
        if (l_UseCollision)
        {
          if ((v102 & 0x200) != 0)
          {
            v103 = v102 & 0x200;
          }
          else
          {
            v103 = 0;
          }
          v104 = fldGb;
          if (v104->PlayerSaka <= 0.0)
          {
            sub_854710(&p, 1u);
            v106 = 10.0;
          }
          else
          {
            sub_854710(&p, 1u);
            v106 = 5.0;
          }
          v104->playerY = v105 + v106;
        }
      }
        goto LABEL_299;
LABEL_295:
      else
      {
        if (ooyCamKakudo >= 360.0)
          goto LABEL_300;
      }
      while (1)
      {
        if (ooyCamKakudo >= 0.0)
          break;
        ooyCamKakudo = ooyCamKakudo + 360.0;
      }
      {
LABEL_312:
      }
      while (fldGb->PlayerKakudo >= 360.0)
      {
        fldGb->PlayerKakudo = fldGb->PlayerKakudo + -360.0;
        if ((v108->_2.bitflags2 & 2) != 0)
          goto LABEL_312;
      }
      while (1)
      {
        if (fldGb->PlayerKakudo >= 0.0)
          break;
        fldGb->PlayerKakudo = fldGb->PlayerKakudo + 360.0;
      }
      dds3GetRotPoseSet(v307);
      SDF_VU0__STOREVECTOR(&v320);
      EulerAngleAxisY();
      v112 = *&dds3CameraTM.m00;
      v113 = *&dds3CameraTM.m20;
      v114 = *&dds3CameraTM.m21;
      *&v316.m01 = *&dds3CameraTM.m01;
      *&v316.m21 = v114;
      *&v316.m00 = v112;
      *&v316.m20 = v113;
      v115 = *&dds3CameraTM.m02;
      v116 = *&dds3CameraTM.m22;
      v118 = *&dds3CameraTM.m03;
      v117 = *&dds3CameraTM.m23;
      *&v316.m03 = v118;
      *&v316.m23 = v117;
      *&v316.m02 = v115;
      *&v316.m22 = v116;
      SDF_VU0__LOADMATRIX(&v316);
      InversMatrix();
      v308->moveFlag = 0;
      v122 = mdlGetMotionMinorNum(v121);
      dds3GetPosPoseSet(v307);
      v125 = v47 == 0 || v313 > 0;
      if ((v315 | v125 | v98) == 1 && (v47 != 0) | v315 & 1 | !(v49 & (v313 < 1)))
      {
        if (((v310 == 0) | v315 | v125) != 1 || !((HIDWORD(v310) == 0) | (v47 != 0) | v315 & 1))
        {
          v128 = -45.0;
            goto LABEL_356;
          goto LABEL_354;
        }
        v126 = v309 == 0 || v125;
        if (((v126 | v98) & 1) == 0)
        {
          v128 = 135.0;
            goto LABEL_356;
          goto LABEL_354;
        }
        if ((v310 == 0 || v313 > 0) | v126 & 1)
        {
          if ((v49 & (v313 < 1)) != 0)
          {
            v128 = 90.0;
              goto LABEL_356;
LABEL_354:
LABEL_356:
            PlayerSaka = fldGb->PlayerSaka;
            if (PlayerSaka <= 0.0)
            {
              v133 = *&v130->_2.bitflags1;
              if ((v133 & 0x200) != 0)
              {
LABEL_367:
                v134 = v133 & 0x200;
LABEL_372:
                PlayerKakudoGoal = v128 - ooyCamKakudo;
                v137 = OOYRAD(-PlayerKakudoGoal);
                sdfSin(v137);
                sub_854930(&p, 0);
                sub_854930(&p, 1u);
                v138 = OOYRAD(-PlayerKakudoGoal);
                sdfCos(v138);
                sub_854930(&p, 2u);
                x = p.x;
                y = p.y;
                z = p.z;
                w = p.w;
                v324.x = x;
                v324.y = y;
                v324.z = z;
                v324.w = w;
                dds3SetPosPoseSet(v307, v324);
                v145 = 1;
                {
LABEL_385:
                }
LABEL_387:
                if (l_UseCollision)
                {
                  if ((v306 & (v310 == 0 || v92) & v315 & (v309 == 0) & v98 & !(v49 & (v313 < 1))) == 0)
                  {
                    v317 = 0;
                    v318 = 0;
                    v148 = fldGb;
                    sub_854710(&p, 0);
                    v148->playerX = v149;
                    v150 = fldGb;
                    sub_854710(&p, 1u);
                    v150->playerY = v151;
                    v152 = fldGb;
                    sub_854710(&p, 2u);
                    v152->playerZ = v153;
                    sub_854930(&v317, 0);
                    sub_854930(&v317, 1u);
                    sub_854930(&v317, 2u);
                    v155 = v317;
                    v156 = v318;
                    *&v325.x = v155;
                    *&v325.z = v156;
                    fldHitChkUnit(v325);
                    v158 = fldGb;
                    if (v158->HitUpdate)
                    {
                      v158->playerX = v158->playerNewX;
                      (*p_static_fields)->fldGb->playerY = (*p_static_fields)->fldGb->playerNewY + 44.0;
                      (*p_static_fields)->fldGb->playerZ = (*p_static_fields)->fldGb->playerNewZ;
                      sub_854930(&p, 0);
                      sub_854930(&p, 1u);
                      sub_854930(&p, 2u);
                      v161 = p.x;
                      v160 = p.y;
                      v163 = p.z;
                      v162 = p.w;
                      v326.x = v161;
                      v326.y = v160;
                      v326.z = v163;
                      v326.w = v162;
                      dds3SetPosPoseSet(v307, v326);
                      fldGb->HitUpdate = 0;
                    }
                  }
                  dds3GetPosPoseSet(v307);
                  SDF_VU0__STOREVECTOR(&p);
                  SDF_VU0__COPYVECTOR(&dst, (*v307)->poseset->pos2, 0);
                  sub_854710(&dst, 0);
                  v165 = v164;
                  sub_854710(&p, 0);
                  v168 = v167;
                  v169 = sdfFabs(v165 - v168);
                  p_pos2 = &(*v307)->poseset->pos2;
                  if (v169 >= 1.0)
                  {
                    sub_854710(&dst, 0);
                    sub_854710(&p, 0);
                    sub_854710(&dst, 0);
                  }
                  else
                  {
                    sub_854710(&p, 0);
                  }
                  sub_854930(p_pos2, 0);
                  sub_854710(&dst, 1u);
                  v172 = v171;
                  sub_854710(&p, 1u);
                  v175 = v174;
                  v176 = sdfFabs(v172 - v175);
                  v177 = &(*v307)->poseset->pos2;
                  if (v176 >= 1.0)
                  {
                    sub_854710(&dst, 1u);
                    sub_854710(&p, 1u);
                    sub_854710(&dst, 1u);
                  }
                  else
                  {
                    sub_854710(&p, 1u);
                  }
                  sub_854930(v177, 1u);
                  sub_854710(&dst, 2u);
                  v179 = v178;
                  sub_854710(&p, 2u);
                  v182 = v181;
                  v183 = sdfFabs(v179 - v182);
                  v184 = &(*v307)->poseset->pos2;
                  if (v183 >= 1.0)
                  {
                    sub_854710(&dst, 2u);
                    sub_854710(&p, 2u);
                    sub_854710(&dst, 2u);
                  }
                  else
                  {
                    sub_854710(&p, 2u);
                  }
                  sub_854930(v184, 2u);
                  sub_854930(&(*v307)->poseset->pos2, 3u);
                }
                v186 = p.x;
                v185 = p.y;
                v188 = p.z;
                v187 = p.w;
                v327.x = v186;
                v327.y = v185;
                v327.z = v188;
                v327.w = v187;
                fldHitChkUnitDamage(v327);
                for (; PlayerKakudoGoal >= 360.0; PlayerKakudoGoal = PlayerKakudoGoal + -360.0)
                  ;
                while (PlayerKakudoGoal < 0.0)
                  PlayerKakudoGoal = PlayerKakudoGoal + 360.0;
                v193 = fldGb;
                v193->PlayerKakudoGoal = fldPlayerCalc360_8(PlayerKakudoGoal);
                PlayerKakudo = fldGb->PlayerKakudo;
                v197 = PlayerKakudo + 360.0;
                if (PlayerKakudo >= 0.0)
                  v197 = fldGb->PlayerKakudo;
                v198 = PlayerKakudoGoal + 360.0;
                if (PlayerKakudo >= 0.0)
                  v198 = PlayerKakudoGoal;
                v199 = (v197 % 360);
                v200 = (v198 % 360);
                if ((v199 - v200) > 180.0 || (v199 - v200) < -180.0)
                {
                  if (v199 >= v200)
                    v200 = v200 + 360.0;
                  else
                    v199 = v199 + 360.0;
                }
                v201 = v200 - v199;
                v202 = v201 / 6.0;
                if ((v201 / 6.0) < 0.0)
                  v202 = -(v201 / 6.0);
                v203 = fmaxf(v202, 2.0);
                if ((v201 < 0.0 || v201 > v203) && (v201 > 0.0 || v201 < -v203))
                {
                  if (v201 < 0.0)
                  {
                    PlayerKakudoGoal = PlayerKakudo - v203;
                    if ((v195->_2.bitflags2 & 2) == 0)
                    {
LABEL_467:
                      fldGb->PlayerKakudo = PlayerKakudoGoal;
                      SDF_VU0__LOADVECTOR(v319);
                      v205 = fldGb->PlayerKakudo;
                      v206 = OOYRAD(v205);
                      FromRotation(v206);
                      SDF_VU0__STOREVECTOR(&v320);
                      v209 = v320.x;
                      v208 = v320.y;
                      v211 = v320.z;
                      v210 = v320.w;
                      v328.x = v209;
                      v328.y = v208;
                      v328.z = v211;
                      v328.w = v210;
                      dds3SetRotPoseSet(v307, v328);
                      v216 = fldCamKakudoGoal - ooyCamKakudo;
                      if (v216 < 0.0)
                        v216 = -v216;
                      if (v216 >= 1.0)
                        goto LABEL_508;
                      if ((v213->_2.bitflags2 & 2) != 0)
                      {
                        v217 = v122;
                        if ((v214->_2.bitflags2 & 2) == 0)
                        {
LABEL_486:
                          ooyCamKakudo = fldCamKakudoGoal;
                          if ((v305 | HIDWORD(v304)) == 0 || v313 > 0)
                          {
                            if (*(&v304 + 4) != 0 && v313 <= 0)
                            {
                              v122 = v217;
                              v239 = ooyCamKakudo + 50.0;
                              v240 = fldPlayerCalc360_4(v239);
                              fldCamKakudoGoal = v240;
                              gFldPlayerSyukanDly = 2;
                              {
LABEL_552:
                                v245 = fldCamKakudoGoal;
                                v246 = v245 - *(*(v244 + 184) + 52LL);
                                if (v246 < 0.0)
                                  v246 = -v246;
                                if (v246 < 1.0)
                                {
                                  if (gFldPlayerSyukanDly >= 1)
                                  {
                                    gFldPlayerSyukanDly = gFldPlayerSyukanDly - 1;
                                    if ((v236->_2.bitflags2 & 2) == 0)
                                    {
LABEL_603:
                                      fldCamKakudoGoal = fldPlayerCalc360_8(fldCamKakudoGoal, v244);
                                      {
                                      }
                                      v260 = fldGb;
                                      {
                                      }
                                      v260->PlayerKakudo = -ooyCamKakudo;
                                      fldGb->PlayerKakudoGoal = -fldCamKakudoGoal;
                                      SDF_VU0__LOADVECTOR(v319);
                                      v262 = OOYRAD(fldGb->PlayerKakudo);
                                      FromRotation(v262);
                                      SDF_VU0__STOREVECTOR(&v320);
                                      v265 = v320.x;
                                      v264 = v320.y;
                                      v267 = v320.z;
                                      v266 = v320.w;
                                      {
                                      }
                                      v329.x = v265;
                                      v329.y = v264;
                                      v329.z = v267;
                                      v329.w = v266;
                                      dds3SetRotPoseSet(v307, v329);
                                      fldPlayerOn();
                                      if ((fldDbg->PlayerStatus & 2) != 0)
                                        goto LABEL_635;
                                      {
                                      }
                                      unitwork = DDS3_GBWK->unitwork;
                                      if ((unitwork->m_Items[0]->badstatus & 0x40) != 0)
                                        goto LABEL_635;
                                      {
                                      }
                                      v274 = DDS3_GBWK->unitwork;
                                      if ((v274->m_Items[0]->badstatus & 0x100) != 0)
                                      {
LABEL_635:
                                        if (v145 == 8)
                                          v279 = 18;
                                        else
                                          v279 = v145;
                                        if (v279 == 1)
                                          v145 = 17;
                                        else
                                          v145 = v279;
                                          goto LABEL_642;
                                      }
                                      else
                                      {
                                          goto LABEL_642;
                                      }
LABEL_642:
                                      if ((byte_3F58927 & 1) == 0)
                                      {
LABEL_626:
                                        if (v122 != v145)
                                        {
LABEL_627:
                                          {
                                          }
                                          fldPlayerSingleMotion(v145, 0);
                                            goto LABEL_645;
                                          goto LABEL_631;
                                        }
LABEL_644:
                                        {
LABEL_645:
                                          v280 = fldGb;
                                          sub_854710(&p, 0);
                                          v280->playerX = v281;
                                          v282 = fldGb;
                                          sub_854710(&p, 1u);
                                          v282->playerY = v283;
                                          v284 = fldGb;
                                          sub_854710(&p, 2u);
                                          v284->playerZ = v285;
                                          fldPlayerMotionSe(v122, v145);
                                          {
                                          }
                                          p_ppos01Point = &ppos01Point;
                                          sub_854710(&(*v307)->poseset->pos2, 0);
                                          sub_854930(p_ppos01Point, 0);
                                          v290 = &ppos01Point;
                                          v22 = 1;
                                          sub_854710(&(*v307)->poseset->pos2, 1u);
                                          sub_854930(v290, 1u);
                                          v291 = &ppos01Point;
                                          sub_854710(&(*v307)->poseset->pos2, 2u);
                                          sub_854930(v291, 2u);
                                          v292 = &ppos01Point;
                                          sub_854710(&(*v307)->poseset->pos2, 3u);
                                          sub_854930(v292, 3u);
                                          p_rot = &ppos01Point.rot;
                                          sub_854710(&(*v307)->poseset->rot, 0);
                                          sub_854930(p_rot, 0);
                                          v294 = &ppos01Point.rot;
                                          sub_854710(&(*v307)->poseset->rot, 1u);
                                          sub_854930(v294, 1u);
                                          v295 = &ppos01Point.rot;
                                          sub_854710(&(*v307)->poseset->rot, 2u);
                                          sub_854930(v295, 2u);
                                          v296 = &ppos01Point.rot;
                                          sub_854710(&(*v307)->poseset->rot, 3u);
                                          sub_854930(v296, 3u);
                                          return v22;
                                        }
LABEL_631:
                                        goto LABEL_645;
                                      }
LABEL_643:
                                      if (v122 != v145)
                                        goto LABEL_627;
                                      goto LABEL_644;
                                    }
LABEL_566:
                                    goto LABEL_603;
                                  }
LABEL_602:
                                  if ((v236->_2.bitflags2 & 2) == 0)
                                    goto LABEL_603;
                                  goto LABEL_566;
                                }
                                v249 = fldCamKakudoGoal;
                                v250 = *(*(v244 + 184) + 52LL);
                                v251 = v250 + 360.0;
                                v252 = v249 < 0.0 || v250 < 0.0;
                                if (!v252)
                                  v251 = *(*(v244 + 184) + 52LL);
                                v253 = v249 + 360.0;
                                if (!v252)
                                  v253 = v249;
                                v254 = (v251 % 360);
                                v255 = (v253 % 360);
                                if ((v254 - v255) > 180.0 || (v254 - v255) < -180.0)
                                {
                                  if (v254 < v255)
                                  {
                                    v256 = v255 - (v254 + 360.0);
                                    if (v256 < 0.0)
                                      goto LABEL_586;
LABEL_585:
                                    if (v256 <= 10.0)
                                    {
LABEL_598:
                                      *(*(v244 + 184) + 52LL) = v249;
                                      goto LABEL_602;
                                    }
LABEL_586:
                                    if (v256 > 0.0 || v256 < -10.0)
                                    {
                                      if (v256 >= 0.0)
                                      {
                                        if ((*(v244 + 294) & 0x200) != 0 && !*(v244 + 216))
                                        {
                                          v250 = ooyCamKakudo;
                                        }
                                        v257 = 10.0;
                                      }
                                      else
                                      {
                                        if ((*(v244 + 294) & 0x200) != 0 && !*(v244 + 216))
                                        {
                                          v250 = ooyCamKakudo;
                                        }
                                        v257 = -10.0;
                                      }
                                      v249 = v250 + v257;
                                    }
                                    goto LABEL_598;
                                  }
                                  v255 = v255 + 360.0;
                                }
                                v256 = v255 - v254;
                                if (v256 < 0.0)
                                  goto LABEL_586;
                                goto LABEL_585;
                              }
LABEL_509:
                              goto LABEL_552;
                            }
                            v122 = v217;
                            if (v304)
                            {
                              v221 = ooyCamKakudo + 140.0;
                              v222 = fldPlayerCalc360_4(v221);
                              fldCamKakudoGoal = v222;
                              gFldPlayerSyukanDly = 2;
                              v225 = fldCamKakudoGoal;
                              v226 = ooyCamKakudo;
                              v227 = v225 + 360.0;
                              v228 = v226 + 360.0;
                              if (v225 >= 0.0 && v226 >= 0.0)
                              {
                                v228 = ooyCamKakudo;
                                v227 = fldCamKakudoGoal;
                              }
                              v229 = (v228 % 360);
                              v230 = (v227 % 360);
                              if ((v229 - v230) > 180.0 || (v229 - v230) < -180.0)
                              {
                                if (v229 >= v230)
                                  v230 = v230 + 360.0;
                                else
                                  v229 = v229 + 360.0;
                              }
                              v242 = v230 - v229;
                              if (v242 == -180)
                                v242 = 180.0;
                              if ((v242 < 0.0 || v242 > 10.0) && (v242 > 0.0 || v242 < -10.0))
                              {
                                if (v242 >= 0.0)
                                {
                                  {
                                    v226 = ooyCamKakudo;
                                  }
                                  v243 = 10.0;
                                }
                                else
                                {
                                  {
                                    v226 = ooyCamKakudo;
                                  }
                                  v243 = -10.0;
                                }
                                v225 = v226 + v243;
                              }
                              ooyCamKakudo = v225;
                                goto LABEL_552;
                              goto LABEL_509;
                            }
                          }
                          else
                          {
                            v122 = v217;
                            v233 = ooyCamKakudo + -50.0;
                            v234 = fldPlayerCalc360_4(v233);
                            fldCamKakudoGoal = v234;
                            gFldPlayerSyukanDly = 2;
                          }
LABEL_508:
                            goto LABEL_552;
                          goto LABEL_509;
                        }
                      }
                      else
                      {
                        v217 = v122;
                          goto LABEL_486;
                      }
                      goto LABEL_486;
                    }
LABEL_465:
                    goto LABEL_467;
                  }
                  PlayerKakudoGoal = v203 + PlayerKakudo;
                }
                if ((v195->_2.bitflags2 & 2) == 0)
                  goto LABEL_467;
                goto LABEL_465;
              }
            }
            else
            {
              sdfFabs(PlayerSaka);
              if ((v133 & 0x200) != 0)
                goto LABEL_367;
            }
            v134 = 0;
            goto LABEL_372;
          }
          if (HIDWORD(v310) == 0 || v313 > 0)
          {
            if ((v315 & 1) != 0)
            {
              PlayerKakudoGoal = fldGb->PlayerKakudoGoal;
              if (v304 || !v309)
              {
                gKeyInputDir = -1;
                gKeyInputCnt = 0;
                sub_854930(&p, 0);
                sub_854930(&p, 1u);
                sub_854930(&p, 2u);
                v301 = p.x;
                v300 = p.y;
                v303 = p.z;
                v302 = p.w;
                v330.x = v301;
                v330.y = v300;
                v330.z = v303;
                v330.w = v302;
                dds3SetPosPoseSet(v307, v330);
                v145 = 8;
                  goto LABEL_385;
                goto LABEL_387;
              }
              v128 = 180.0;
                goto LABEL_356;
            }
            else
            {
              v128 = -0.0;
                goto LABEL_356;
            }
              goto LABEL_356;
            goto LABEL_355;
          }
          v128 = -90.0;
            goto LABEL_356;
        }
        else
        {
          v128 = -135.0;
            goto LABEL_356;
        }
          goto LABEL_356;
        goto LABEL_355;
      }
      v128 = 45.0;
        goto LABEL_356;
      goto LABEL_354;
    }
LABEL_116:
    goto LABEL_118;
  }
  else if (gfldPlayerDamegeCnt < 1)
  {
    goto LABEL_122;
  }
  if (!fldGb->DmgOn)
  {
    if ((fldDbg->PlayerStatus & 1) != 0)
    {
      fldSePlay(34);
      dds3FadeIn(0x80u, 0x20u, 0x20u, 6u);
      dds3PadAct(0, 1u, 6u);
      dds3PadAct(1u, 0x96u, 6u);
      fldStatusSet();
      gfldPlayerDamegeCnt = 0;
      fldProcOnFlag(0x40u);
      return 0;
    }
  }
  v36 = mdlGetMotionMinorNum(v33);
  if (v36 == 10)
  {
    v38 = fldPlayerObj;
    if (!mdlChkMotionEndForUnity_26964128(v38, 0))
      return 0;
      goto LABEL_118;
    goto LABEL_116;
  }
  fldPlayerSingleMotion(10, 0);
  v54 = fldGb;
  v55 = v54[78];
  v56 = v54[79];
  v57 = v54[80];
  fldDmgStart(v55, v56, v57);
  fldSePlay(34);
  dds3PadAct(0, 1u, 0x1Eu);
  dds3PadAct(1u, 0x96u, 0x1Eu);
  fldStatusSet();
  return 0;
}

// 0x10cbe90
void fldPlayerCalc_WarpRun(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3Basic_t_o **p_handle2;
  struct fldGlobalWork_t_o *fldGb;
  f32 v15;
  struct fldGlobalWork_t_o *v16;
  f32 v17;
  struct fldGlobalWork_t_o *v18;
  f32 v20;
  dds3PoseSet_t_o **p_poseset;
  dds3PoseSet_t_o **v23;
  s16 v26;
  s32 v27;
  struct fldGlobalWork_t_o *v28;
  f32 v29;
  f32 v30;
  fldGlobal_c *v32;
  s64 v37;
  s64 v38;
  s64 v39;
  s64 v40;
  s64 v41;
  s64 v42;
  s64 v43;
  f32 gfldPlayerKakudo2;
  f32 v49;
  f32 v50;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct fldGlobalWork_t_o *v59;
  f32 v60;
  struct fldGlobalWork_t_o *v61;
  f32 v62;
  struct fldGlobalWork_t_o *v63;
  f32 v64;
  s64 v66;
  s64 v67;
  struct fldGlobal_StaticFields **p_static_fields;
  struct fldGlobalWork_t_o *v70;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 v77;
  f32 v79;
  f32 v80;
  f32 v81;
  s64 p_pos2;
  f32 v83;
  f32 v84;
  f32 v86;
  f32 v87;
  f32 v88;
  s64 v89;
  f32 v90;
  f32 v91;
  f32 v93;
  f32 v94;
  f32 v95;
  s64 v96;
  s64 v97;
  s64 v98;
  s64 v99;
  s64 v100;
  f32 PlayerKakudo;
  f32 v105;
  f32 v106;
  f32 v107;
  _BOOL4 v108;
  bool v109;
  s32 v110;
  f32 v111;
  f32 v112;
  f32 v113;
  f32 v114;
  f32 v115;
  f32 v116;
  fldGlobal_c *v117;
  f32 v119;
  f32 v120;
  f32 v122;
  f32 v123;
  f32 v124;
  f32 v125;
  f32 v127;
  f32 v128;
  f32 v129;
  f32 v130;
  s32 v132;
  struct fldGlobalWork_t_o *v136;
  f32 v137;
  struct fldGlobalWork_t_o *v138;
  f32 v139;
  struct fldGlobalWork_t_o *v140;
  f32 v141;
  UnityEngine_Matrix4x4_o v142;
  s64 v143;
  s64 v144;
  UnityEngine_Vector4_o v145;
  UnityEngine_Vector4_o v146;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  dds3ModelHandle_t_o *v149[4];
  dds3ModelHandle_t_o *aHandle;
  UnityEngine_Vector4_o v151;
  UnityEngine_Vector4_o v152;
  UnityEngine_Vector4_o v153;
  UnityEngine_Vector4_o v154;
  UnityEngine_Vector4_o v155;

  aHandle = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v146.x = 0;
  *&v146.z = 0;
  *&v145.x = 0;
  *&v145.z = 0;
  v143 = 0;
  v144 = 0;
LABEL_7:
  p_handle = &fldUnitControl->handle;
  ModelHandle = dds3ObjectBaseGetModelHandle(&fldUnitControl->handle);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v149);
      if ((v149[0] & 1) != 0)
        v8 = v149[2];
      else
        v8 = v149 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  aHandle = ModelHandle;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v146.x = 0;
  *&v146.z = 0;
  sub_854690(&v145.x, 0.0, 1.0, 0.0, 1.0);
  else if (gfldPlayerKakudo2Mode != 1)
  {
    return;
  }
  p_handle2 = &fldUnitControl->handle2;
  if (fldUnitControl->handle2)
    dds3ObjectBaseGetModelHandle(&fldUnitControl->handle2);
  dds3GetPosPoseSet(&fldUnitControl->handle);
  SDF_VU0__STOREVECTOR(&p);
  fldGb->playerOldX = fldGb->playerX;
  fldGb->playerOldY = fldGb->playerY;
  fldGb->playerOldZ = fldGb->playerZ;
  sub_854710(&p, 0);
  fldGb->playerX = v15;
  v16 = fldGb;
  sub_854710(&p, 1u);
  v16->playerY = v17;
  v18 = fldGb;
  sub_854710(&p, 2u);
  v18->playerZ = v20;
  if (l_UseCollision)
  {
    p_poseset = &(*p_handle)->poseset;
    dds3OnPoseSetFlag(p_poseset, 8u);
    if (*p_handle2)
    {
      v23 = &(*p_handle2)->poseset;
      dds3OnPoseSetFlag(v23, 8u);
    }
  }
  if (l_UseCollision)
  {
    if ((v26 & 0x200) != 0)
    {
      v27 = v26 & 0x200;
    }
    else
    {
      v27 = 0;
    }
    v28 = fldGb;
    if (v28->PlayerSaka <= 0.0)
    {
      v29 = 10.0;
      if (v27)
      {
LABEL_55:
      }
    }
    else
    {
      v29 = 5.0;
      if (v27)
        goto LABEL_55;
    }
    sub_854710(&p, 1u);
    v28->playerY = v30 + v29;
  }
    goto LABEL_64;
LABEL_60:
  else
  {
    if (ooyCamKakudo >= 360.0)
      goto LABEL_65;
  }
  while (1)
  {
    if (ooyCamKakudo >= 0.0)
      break;
    ooyCamKakudo = ooyCamKakudo + 360.0;
  }
  {
LABEL_77:
  }
  while (fldGb->PlayerKakudo >= 360.0)
  {
    fldGb->PlayerKakudo = fldGb->PlayerKakudo + -360.0;
    if ((v32->_2.bitflags2 & 2) != 0)
      goto LABEL_77;
  }
  while (1)
  {
    if (fldGb->PlayerKakudo >= 0.0)
      break;
    fldGb->PlayerKakudo = fldGb->PlayerKakudo + 360.0;
  }
    goto LABEL_97;
LABEL_93:
  else
  {
    if (gfldPlayerKakudo2 >= 360.0)
      goto LABEL_98;
  }
  while (1)
  {
    if (gfldPlayerKakudo2 >= 0.0)
      break;
    gfldPlayerKakudo2 = gfldPlayerKakudo2 + 360.0;
  }
  dds3GetRotPoseSet(&fldUnitControl->handle);
  SDF_VU0__STOREVECTOR(&v146);
  EulerAngleAxisY();
  v37 = *&dds3CameraTM.m00;
  v38 = *&dds3CameraTM.m20;
  v39 = *&dds3CameraTM.m21;
  *&v142.m01 = *&dds3CameraTM.m01;
  *&v142.m21 = v39;
  *&v142.m00 = v37;
  *&v142.m20 = v38;
  v40 = *&dds3CameraTM.m02;
  v41 = *&dds3CameraTM.m22;
  v43 = *&dds3CameraTM.m03;
  v42 = *&dds3CameraTM.m23;
  *&v142.m03 = v43;
  *&v142.m23 = v42;
  *&v142.m02 = v40;
  *&v142.m22 = v41;
  SDF_VU0__LOADMATRIX(&v142);
  InversMatrix();
  fldUnitControl->moveFlag = 0;
  v49 = OOYRAD(-gfldPlayerKakudo2);
  sdfSin(v49);
  sub_854930(&p, 0);
  sub_854930(&p, 1u);
  v50 = OOYRAD(-gfldPlayerKakudo2);
  sdfCos(v50);
  sub_854930(&p, 2u);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v151.x = x;
  v151.y = y;
  v151.z = z;
  v151.w = w;
  dds3SetPosPoseSet(p_handle, v151);
  if (l_UseCollision)
  {
    v143 = 0;
    v144 = 0;
    v59 = fldGb;
    sub_854710(&p, 0);
    v59->playerX = v60;
    v61 = fldGb;
    sub_854710(&p, 1u);
    v61->playerY = v62;
    v63 = fldGb;
    sub_854710(&p, 2u);
    v63->playerZ = v64;
    sub_854930(&v143, 0);
    sub_854930(&v143, 1u);
    sub_854930(&v143, 2u);
    v66 = v143;
    v67 = v144;
    *&v152.x = v66;
    *&v152.z = v67;
    fldHitChkUnit(v152);
    v70 = fldGb;
    if (v70->HitUpdate)
    {
      v70->playerX = v70->playerNewX;
      (*p_static_fields)->fldGb->playerY = (*p_static_fields)->fldGb->playerNewY + 44.0;
      (*p_static_fields)->fldGb->playerZ = (*p_static_fields)->fldGb->playerNewZ;
      sub_854930(&p, 0);
      sub_854930(&p, 1u);
      sub_854930(&p, 2u);
      v73 = p.x;
      v72 = p.y;
      v75 = p.z;
      v74 = p.w;
      v153.x = v73;
      v153.y = v72;
      v153.z = v75;
      v153.w = v74;
      dds3SetPosPoseSet(p_handle, v153);
      fldGb->HitUpdate = 0;
    }
    dds3GetPosPoseSet(p_handle);
    SDF_VU0__STOREVECTOR(&p);
    SDF_VU0__COPYVECTOR(&dst, (*p_handle)->poseset->pos2, 0);
    sub_854710(&dst, 0);
    v77 = v76;
    sub_854710(&p, 0);
    v80 = v79;
    v81 = sdfFabs(v77 - v80);
    p_pos2 = &(*p_handle)->poseset->pos2;
    if (v81 >= 1.0)
    {
      sub_854710(&dst, 0);
      sub_854710(&p, 0);
      sub_854710(&dst, 0);
    }
    else
    {
      sub_854710(&p, 0);
    }
    sub_854930(p_pos2, 0);
    sub_854710(&dst, 1u);
    v84 = v83;
    sub_854710(&p, 1u);
    v87 = v86;
    v88 = sdfFabs(v84 - v87);
    v89 = &(*p_handle)->poseset->pos2;
    if (v88 >= 1.0)
    {
      sub_854710(&dst, 1u);
      sub_854710(&p, 1u);
      sub_854710(&dst, 1u);
    }
    else
    {
      sub_854710(&p, 1u);
    }
    sub_854930(v89, 1u);
    sub_854710(&dst, 2u);
    v91 = v90;
    sub_854710(&p, 2u);
    v94 = v93;
    v95 = sdfFabs(v91 - v94);
    v96 = &(*p_handle)->poseset->pos2;
    if (v95 >= 1.0)
    {
      sub_854710(&dst, 2u);
      sub_854710(&p, 2u);
      sub_854710(&dst, 2u);
    }
    else
    {
      sub_854710(&p, 2u);
    }
    sub_854930(v96, 2u);
    sub_854930(&(*p_handle)->poseset->pos2, 3u);
    if (*p_handle2)
    {
      v97 = &(*p_handle2)->poseset->pos2;
      sub_854710(&(*p_handle)->poseset->pos2, 0);
      sub_854930(v97, 0);
      v98 = &(*p_handle2)->poseset->pos2;
      sub_854710(&(*p_handle)->poseset->pos2, 1u);
      sub_854930(v98, 1u);
      v99 = &(*p_handle2)->poseset->pos2;
      sub_854710(&(*p_handle)->poseset->pos2, 2u);
      sub_854930(v99, 2u);
      v100 = &(*p_handle2)->poseset->pos2;
      sub_854710(&(*p_handle)->poseset->pos2, 3u);
      sub_854930(v100, 3u);
    }
  }
  PlayerKakudo = fldGb->PlayerKakudo;
  v105 = gfldPlayerKakudo2;
  v106 = PlayerKakudo + 360.0;
  v107 = v105 + 360.0;
  v108 = PlayerKakudo < 0.0 || v105 < 0.0;
  v109 = !v108;
  if (!v108)
    v106 = PlayerKakudo;
  v110 = v106 % 360;
  if (v109)
    v107 = gfldPlayerKakudo2;
  v111 = v110;
  v112 = (v107 % 360);
  v113 = v110 - v112;
  if (v113 > 180.0 || v113 < -180.0)
  {
    if (v111 >= v112)
      v112 = v112 + 360.0;
    else
      v111 = v111 + 360.0;
  }
  v114 = v112 - v111;
  v115 = v114 / 6.0;
  if ((v114 / 6.0) < 0.0)
    v115 = -(v114 / 6.0);
  v116 = fmaxf(v115, 2.0);
  if ((v114 < 0.0 || v114 > v116) && (v114 > 0.0 || v114 < -v116))
  {
    if (v114 >= 0.0)
    {
      v105 = v116 + fldGb->PlayerKakudo;
      if ((v117->_2.bitflags2 & 2) == 0)
        goto LABEL_218;
    }
    else
    {
      v105 = fldGb->PlayerKakudo - v116;
      if ((v117->_2.bitflags2 & 2) == 0)
        goto LABEL_218;
    }
  }
  else
  {
      goto LABEL_218;
  }
LABEL_218:
  fldGb->PlayerKakudo = v105;
  SDF_VU0__LOADVECTOR(v145);
  v119 = fldGb->PlayerKakudo;
  v120 = OOYRAD(v119);
  FromRotation(v120);
  SDF_VU0__STOREVECTOR(&v146);
  v123 = v146.x;
  v122 = v146.y;
  v125 = v146.z;
  v124 = v146.w;
  v154.x = v123;
  v154.y = v122;
  v154.z = v125;
  v154.w = v124;
  dds3SetRotPoseSet(p_handle, v154);
  if (*p_handle2)
  {
    v128 = v146.x;
    v127 = v146.y;
    v130 = v146.z;
    v129 = v146.w;
    v155.x = v128;
    v155.y = v127;
    v155.z = v130;
    v155.w = v129;
    dds3SetRotPoseSet(p_handle2, v155);
  }
  if (fldGb->fieldID == 23)
    v132 = 8;
  else
    v132 = 4;
  if (mdlGetMotionMinorNum(&aHandle) != v132)
  {
    fldPlayerSingleMotion(v132, 0);
  }
  v136 = fldGb;
  sub_854710(&p, 0);
  v136->playerX = v137;
  v138 = fldGb;
  sub_854710(&p, 1u);
  v138->playerY = v139;
  v140 = fldGb;
  sub_854710(&p, 2u);
  v140->playerZ = v141;
}

// 0x10d3c10
void fldPlayerCalc_WarpStart(void) {
  fldWmWarpMode = 1;
}

// 0x10d4430
s32 fldPlayerCalc_Wm2(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  s32 gfldPlayerDamegeCnt;
  dds3PoseSet_t_o **p_poseset;
  _BOOL4 v14;
  _BOOL4 v16;
  _BOOL4 v18;
  _BOOL4 v20;
  _BOOL4 v23;
  dds3Basic_t_o **p_handle;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  struct fldGlobalWork_t_o *fldGb;
  f32 v32;
  struct fldGlobalWork_t_o *v33;
  f32 v34;
  struct fldGlobalWork_t_o *v35;
  f32 v37;
  struct fldGlobalWork_t_o *v40;
  f32 v41;
  s64 v44;
  s64 v45;
  s64 v46;
  s64 v47;
  s64 v48;
  s64 v49;
  s64 v50;
  u64 v54;
  struct fldPlayer_StaticFields *v55;
  s16 v56;
  s32 v57;
  s32 fldWmWarpMode;
  _BOOL4 v59;
  s32 v60;
  s32 v61;
  s32 v62;
  s32 v63;
  fldTest_c *v65;
  s32 v66;
  f32 v67;
  f32 ooyCamKakudo;
  f32 v69;
  f32 v70;
  f32 v72;
  f32 v73;
  f32 v75;
  f32 v76;
  f32 v77;
  f32 v78;
  struct fldGlobalWork_t_o *v80;
  f32 v81;
  struct fldGlobalWork_t_o *v82;
  f32 v83;
  struct fldGlobalWork_t_o *v84;
  f32 v85;
  s64 v87;
  s64 v88;
  fldGlobal_c *v89;
  struct fldGlobalWork_t_o *v90;
  struct fldGlobalWork_t_o *v91;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v97;
  f32 v98;
  f32 v100;
  f32 v101;
  f32 v102;
  s64 p_pos2;
  f32 v104;
  f32 v105;
  f32 v107;
  f32 v108;
  f32 v109;
  s64 v110;
  f32 v111;
  f32 v112;
  f32 v114;
  f32 v115;
  f32 v116;
  s64 v117;
  f32 v119;
  f32 v120;
  f32 v121;
  f32 v122;
  struct fldGlobalWork_t_o *v125;
  f32 v126;
  struct fldGlobalWork_t_o *v127;
  f32 v128;
  struct fldGlobalWork_t_o *v129;
  f32 v130;
  s64 v132;
  s64 v133;
  fldGlobal_c *v134;
  struct fldGlobalWork_t_o *v135;
  struct fldGlobalWork_t_o *v136;
  f32 v138;
  f32 v139;
  f32 v140;
  f32 v141;
  f32 v142;
  f32 v143;
  f32 v145;
  f32 v146;
  f32 v147;
  s64 v148;
  f32 v149;
  f32 v150;
  f32 v152;
  f32 v153;
  f32 v154;
  s64 v155;
  f32 v156;
  f32 v157;
  f32 v159;
  f32 v160;
  f32 v161;
  s64 v162;
  f32 v163;
  f32 v164;
  f32 v165;
  f32 v166;
  struct fldGlobalWork_t_o *v169;
  f32 v170;
  struct fldGlobalWork_t_o *v171;
  f32 v172;
  struct fldGlobalWork_t_o *v173;
  f32 v175;
  s32 fldWmOldYukaHitIdx;
  struct collision_s_array *gfldCollision;
  s64 ooyTestYukaHitIdx;
  struct collision_s_array *v187;
  s64 v188;
  struct collision_s_array *v190;
  s64 v191;
  s16 v195;
  s32 v196;
  f32 v200;
  f32 v202;
  f32 v203;
  f32 v204;
  f32 v205;
  f32 v210;
  f32 v211;
  f32 v213;
  f32 v214;
  f32 v216;
  f32 v217;
  f32 v218;
  f32 v219;
  f32 v220;
  f32 v221;
  f32 v223;
  f32 v224;
  f32 v226;
  f32 v227;
  f32 v228;
  f32 v229;
  f32 v231;
  f32 v232;
  f32 v233;
  f32 v234;
  UnityEngine_Transform_o *v238;
  fldPlayer_c *v239;
  f32 v241;
  f32 v242;
  f32 v243;
  f32 v245;
  s64 v248;
  s64 v249;
  UnityEngine_Object_o *fldPlayerObj;
  UnityEngine_Transform_o *transform;
  s64 v256;
  UnityEngine_Transform_o *v257;
  s64 v258;
  UnityEngine_Matrix4x4_o v260;
  u64 v261[2];
  s64 v262;
  s64 v263;
  s64 v264;
  s64 v265;
  s64 v266;
  s64 v267;
  UnityEngine_Vector4_o v268;
  UnityEngine_Vector4_o v269;
  UnityEngine_Vector4_o v270;
  UnityEngine_Vector4_o v271;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector3_o v274;
  UnityEngine_Vector4_o v275;
  UnityEngine_Vector4_o v276;
  UnityEngine_Vector4_o v277;
  UnityEngine_Vector4_o v278;
  UnityEngine_Vector4_o v279;
  UnityEngine_Vector4_o v280;
  UnityEngine_Vector4_o v281;
  UnityEngine_Vector4_o v282;
  UnityEngine_Vector4_o v283;
  UnityEngine_Vector4_o v284;
  UnityEngine_Vector4_o v285;
  UnityEngine_Quaternion_o v286;

  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v271.x = 0;
  *&v271.z = 0;
  *&v270.x = 0;
  *&v270.z = 0;
  *&v269.x = 0;
  *&v269.z = 0;
  *&v268.x = 0;
  *&v268.z = 0;
  v266 = 0;
  v267 = 0;
  v264 = 0;
  v265 = 0;
  v262 = 0;
  v263 = 0;
  v261[0] = 0;
  v261[1] = 0;
LABEL_7:
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v271.x = 0;
  *&v271.z = 0;
  *&v270.x = 0;
  *&v270.z = 0;
  *&v269.x = 0;
  *&v269.z = 0;
  *&v268.x = 0;
  *&v268.z = 0;
  sub_854690(&v266, 1.0, 1.0, 1.0, 1.0);
  if (gfldPlayerDamegeCnt < 1)
    goto LABEL_42;
LABEL_13:
  if (gfldPlayerDamegeCnt == 60)
  {
    fldSePlay(34);
    dds3FadeIn(0x80u, 0x20u, 0x20u, 6u);
    dds3PadAct(0, 1u, 8u);
    dds3PadAct(1u, 0x64u, 8u);
    fldStatusSet();
  }
  gfldPlayerDamegeCnt -= 10;
  if (gfldPlayerDamegeCnt <= 0)
  {
    gfldPlayerDamegeCnt = 0;
    {
LABEL_45:
      if (l_UseCollision)
      {
        p_poseset = &fldUnitControl->handle->poseset;
        dds3OnPoseSetFlag(p_poseset, 8u);
      }
      v14 = DDS3_PADCHECK_PRESS(4);
      v16 = DDS3_PADCHECK_PRESS(5);
      v18 = DDS3_PADCHECK_PRESS(6);
      v20 = DDS3_PADCHECK_PRESS(7);
      DDS3_PADCHECK_PRESS(3);
      v23 = fldGb->NoInpPlCnt < 1;
      p_handle = &fldUnitControl->handle;
      v25 = v16 && v23;
      v26 = v14 && v23;
      v27 = v20 && v23;
      v28 = v18 && v23;
      dds3GetPosPoseSet(&fldUnitControl->handle);
      SDF_VU0__STOREVECTOR(&p);
      SDF_VU0__STOREVECTOR(&v271);
      fldGb->playerOldX = fldGb->playerX;
      fldGb->playerOldY = fldGb->playerY;
      fldGb->playerOldZ = fldGb->playerZ;
      sub_854710(&p, 0);
      fldGb->playerX = v32;
      v33 = fldGb;
      sub_854710(&p, 1u);
      v33->playerY = v34;
      v35 = fldGb;
      sub_854710(&p, 2u);
      v35->playerZ = v37;
      if ((v27 | v28 | v26 | v25) == 1)
      {
        if (l_UseCollision)
        {
          v40 = fldGb;
          sub_854710(&p, 1u);
          v40->playerY = v41 + 3.0;
        }
      }
      v44 = *&dds3CameraTM.m00;
      v45 = *&dds3CameraTM.m20;
      v46 = *&dds3CameraTM.m21;
      *&v260.m01 = *&dds3CameraTM.m01;
      *&v260.m21 = v46;
      *&v260.m00 = v44;
      *&v260.m20 = v45;
      v47 = *&dds3CameraTM.m02;
      v48 = *&dds3CameraTM.m22;
      v50 = *&dds3CameraTM.m03;
      v49 = *&dds3CameraTM.m23;
      *&v260.m03 = v50;
      *&v260.m23 = v49;
      *&v260.m02 = v47;
      *&v260.m22 = v48;
      SDF_VU0__LOADMATRIX(&v260);
      InversMatrix();
      fldUnitControl->moveFlag = 0;
      dds3GetPosPoseSet(&fldUnitControl->handle);
      v55 = *(v54 + 184);
      if (fldWmWarpMode == 1)
      {
        fldWmWarpMode = 0;
      }
      if (*(*(v54 + 184) + 184LL) == 2)
      {
        fldPlayerCalc_Wm4(v54);
      }
      if (*(*(v54 + 184) + 184LL) == 3)
      {
        fldPlayerCalc_Wm4(v54);
      }
      v56 = *(v54 + 294);
      if ((v56 & 0x200) != 0)
      {
        v57 = v56 & 0x200;
      }
      else
      {
        v57 = 0;
      }
      fldWmWarpMode = *(*(v54 + 184) + 184LL);
      v59 = fldWmWarpMode == 0;
      v60 = v25 & v59;
      v61 = v26 & v59;
      v62 = v27 & v59;
      v63 = v28 & v59;
      if (fldWmWarpMode)
      {
          goto LABEL_162;
LABEL_126:
LABEL_162:
        if (!l_UseCollision)
          goto LABEL_212;
LABEL_163:
        if ((v60 | v61 | v63 | v62) != 1)
          goto LABEL_190;
        v264 = 0;
        v265 = 0;
        v80 = fldGb;
        sub_854710(&p, 0);
        v80->playerX = v81;
        v82 = fldGb;
        sub_854710(&p, 1u);
        v82->playerY = v83;
        v84 = fldGb;
        sub_854710(&p, 2u);
        v84->playerZ = v85;
        sub_854930(&v264, 0);
        sub_854930(&v264, 1u);
        sub_854930(&v264, 2u);
        v87 = v264;
        v88 = v265;
        *&v276.x = v87;
        *&v276.z = v88;
        fldHitChkUnitVWM(v276);
        v90 = fldGb;
        if (!v90->HitUpdate)
          goto LABEL_190;
        v90->playerX = v90->playerNewX;
        v91 = fldGb;
        if (v91->fieldID == 1)
        {
          v91->playerY = (v91->playerNewY + 44.0) + -11.0;
          if ((v89->_2.bitflags2 & 2) == 0)
            goto LABEL_186;
        }
        else
        {
          v91->playerY = v91->playerNewY + 44.0;
          if ((v89->_2.bitflags2 & 2) == 0)
            goto LABEL_186;
        }
LABEL_186:
        fldGb->playerZ = fldGb->playerNewZ;
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sub_854930(&p, 2u);
        x = p.x;
        y = p.y;
        z = p.z;
        w = p.w;
        v277.x = x;
        v277.y = y;
        v277.z = z;
        v277.w = w;
        dds3SetPosPoseSet(p_handle, v277);
        fldGb->HitUpdate = 0;
LABEL_190:
        dds3GetPosPoseSet(p_handle);
        SDF_VU0__STOREVECTOR(&p);
        SDF_VU0__COPYVECTOR(&dst, (*p_handle)->poseset->pos2, 0);
        sub_854710(&dst, 0);
        v98 = v97;
        sub_854710(&p, 0);
        v101 = v100;
        v102 = sdfFabs(v98 - v101);
        p_pos2 = &(*p_handle)->poseset->pos2;
        if (v102 >= 1.0)
        {
          sub_854710(&dst, 0);
          sub_854710(&p, 0);
          sub_854710(&dst, 0);
        }
        else
        {
          sub_854710(&p, 0);
        }
        sub_854930(p_pos2, 0);
        sub_854710(&dst, 1u);
        v105 = v104;
        sub_854710(&p, 1u);
        v108 = v107;
        v109 = sdfFabs(v105 - v108);
        v110 = &(*p_handle)->poseset->pos2;
        if (v109 >= 1.0)
        {
          sub_854710(&dst, 1u);
          sub_854710(&p, 1u);
          sub_854710(&dst, 1u);
        }
        else
        {
          sub_854710(&p, 1u);
        }
        sub_854930(v110, 1u);
        sub_854710(&dst, 2u);
        v112 = v111;
        sub_854710(&p, 2u);
        v115 = v114;
        v116 = sdfFabs(v112 - v115);
        v117 = &(*p_handle)->poseset->pos2;
        if (v116 >= 1.0)
        {
          sub_854710(&dst, 2u);
          sub_854710(&p, 2u);
          sub_854710(&dst, 2u);
        }
        else
        {
          sub_854710(&p, 2u);
        }
        sub_854930(v117, 2u);
        sub_854930(&(*p_handle)->poseset->pos2, 3u);
LABEL_212:
        if (!l_UseCollision)
        {
LABEL_268:
          v164 = p.x;
          v163 = p.y;
          v166 = p.z;
          v165 = p.w;
          v281.x = v164;
          v281.y = v163;
          v281.z = v166;
          v281.w = v165;
          fldHitChkUnitDamage(v281);
          v169 = fldGb;
          sub_854710(&p, 0);
          v169->playerX = v170;
          v171 = fldGb;
          sub_854710(&p, 1u);
          v171->playerY = v172;
          v173 = fldGb;
          sub_854710(&p, 2u);
          v173->playerZ = v175;
          if ((ooyTestYukaHitIdx & 0x80000000) == 0)
          {
            if (fldWmOldYukaHitIdx != ooyTestYukaHitIdx)
            {
              sub_854710(&fldWmNowNml, 0);
              sub_854930(&fldWmPrevNml, 0);
              sub_854710(&fldWmNowNml, 1u);
              sub_854930(&fldWmPrevNml, 1u);
              sub_854710(&fldWmNowNml, 2u);
              sub_854930(&fldWmPrevNml, 2u);
              sub_854710(&gfldCollision->m_Items[ooyTestYukaHitIdx]->normal, 0);
              sub_854930(&fldWmNextNml, 0);
              v187 = gfldCollision;
              v188 = ooyTestYukaHitIdx;
              sub_854710(&v187->m_Items[v188]->normal, 1u);
              sub_854930(&fldWmNextNml, 1u);
              v190 = gfldCollision;
              v191 = ooyTestYukaHitIdx;
              sub_854710(&v190->m_Items[v191]->normal, 2u);
              sub_854930(&fldWmNextNml, 2u);
              fldWmOldYukaHitIdx = ooyTestYukaHitIdx;
              fldWmHohanCnt = 0;
            }
          }
          if ((v195 & 0x200) != 0)
          {
            v196 = v195 & 0x200;
            if (fldWmHohanCnt <= 7)
            {
LABEL_303:
              sub_854710(&fldWmNextNml, 0);
              sub_854710(&fldWmPrevNml, 0);
              sub_854710(&fldWmNextNml, 1u);
              sub_854710(&fldWmPrevNml, 1u);
              sub_854710(&fldWmNextNml, 2u);
              sub_854710(&fldWmPrevNml, 2u);
              sub_854710(&fldWmPrevNml, 0);
              sub_854930(&fldWmNowNml, 0);
              sub_854710(&fldWmPrevNml, 1u);
              sub_854930(&fldWmNowNml, 1u);
              sub_854710(&fldWmPrevNml, 2u);
              sub_854930(&fldWmNowNml, 2u);
              ++fldWmHohanCnt;
              {
LABEL_307:
              }
LABEL_316:
              if (fldGb->fieldID == 1)
              {
                v200 = OOYRAD(-40.0);
                FromEuler(v200, 0.0, 0.0);
                SDF_VU0__STOREVECTOR(&v268);
                v203 = v268.x;
                v202 = v268.y;
                v205 = v268.z;
                v204 = v268.w;
                v282.x = v203;
                v282.y = v202;
                v282.z = v205;
                v282.w = v204;
                dds3SetRotPoseSet(p_handle, v282);
                  goto LABEL_382;
                goto LABEL_381;
              }
              if (ooyTestYukaHitIdx < 0)
              {
LABEL_380:
                  goto LABEL_382;
LABEL_381:
LABEL_382:
                if (fldWmWarpMode)
                  goto LABEL_402;
LABEL_383:
                fldWmSize = 1.0;
                sub_854710(&v266, 0);
                sub_854930(&v266, 0);
                sub_854710(&v266, 1u);
                sub_854930(&v266, 1u);
                sub_854710(&v266, 2u);
                sub_854930(&v266, 2u);
                v248 = v266;
                v249 = v267;
                *&v284.x = v248;
                *&v284.z = v249;
                dds3SetSclPoseSet(p_handle, v284);
                {
                }
                if (op_Inequality(fldPlayerObj, 0, 0))
                {
                  transform = get_transform(fldPlayerObj, 0);
                  v256 = v266;
                  v257 = transform;
                  v258 = v267;
                  {
                  }
                  *&v285.x = v256;
                  *&v285.z = v258;
                  v274 = op_Implicit_8738992(v285);
                  set_localScale(v257, v274);
                  if (!evtBitCheck(1883))
                    goto LABEL_404;
LABEL_403:
                  dds3ObjectBaseOnFlag(p_handle, 1u, 0);
                  return 0;
                }
LABEL_402:
                if (!evtBitCheck(1883))
                {
LABEL_404:
                  dds3ObjectBaseOffFlag(p_handle, 1u);
                  return 0;
                }
                goto LABEL_403;
              }
              sub_854690(v261, 0.0, 1.0, 0.0, 1.0);
              sub_854710(&fldWmNowNml, 0);
              sub_854930(v261, 0);
              sub_854710(&fldWmNowNml, 1u);
              sub_854930(v261, 1u);
              sub_854710(&fldWmNowNml, 2u);
              sub_854930(v261, 2u);
              sub_854710(v261, 0);
              v211 = v210;
              sub_854710(v261, 1u);
              v214 = v213;
              v216 = sdfAtan2(v211, v214);
              if (v216 >= 0.0)
                v217 = v216;
              else
                v217 = -v216;
              v218 = OOYRAD(180.0) - v217;
              if (v216 >= 0.0)
                v219 = v218;
              else
                v219 = -v218;
              sub_854710(v261, 2u);
              v221 = v220;
              sub_854710(v261, 1u);
              v224 = v223;
              v226 = sdfAtan2(v221, v224);
              if (v226 >= 0.0)
                v227 = v226;
              else
                v227 = -v226;
              v228 = OOYRAD(180.0) - v227;
              if (v226 >= 0.0)
                v229 = -v228;
              else
                v229 = v228;
              FromEuler(v229, 0.0, v219);
              SDF_VU0__STOREVECTOR(&v268);
              v232 = v268.x;
              v231 = v268.y;
              v234 = v268.z;
              v233 = v268.w;
              v283.x = v232;
              v283.y = v231;
              v283.z = v234;
              v283.w = v233;
              dds3SetRotPoseSet(p_handle, v283);
              v238 = get_transform(mhfldPlayerFileBk, 0);
              if (gWmRotSetOn)
              {
                v241 = (gWmRotX - v229) * 0.5;
                v242 = (gWmRotZ - v219) * 0.5;
                if ((v239->_2.bitflags2 & 2) == 0)
                  goto LABEL_373;
              }
              else
              {
                v241 = -v229;
                v242 = -v219;
                if ((v239->_2.bitflags2 & 2) == 0)
                {
LABEL_373:
                  gWmRotSetOn = 1;
                  gWmRotX = v241;
                  gWmRotZ = v242;
                  v243 = OOYDEG(v241);
                  v245 = OOYDEG(v242);
                  {
                  }
                  v286 = Euler(v243, 0.0, v245);
                  set_rotation(v238, v286);
                  goto LABEL_380;
                }
              }
              goto LABEL_373;
            }
          }
          else
          {
            v196 = 0;
            if (fldWmHohanCnt <= 7)
              goto LABEL_303;
          }
          sub_854710(&fldWmNextNml, 0);
          sub_854930(&fldWmNowNml, 0);
          sub_854710(&fldWmNextNml, 1u);
          sub_854930(&fldWmNowNml, 1u);
          sub_854710(&fldWmNextNml, 2u);
          sub_854930(&fldWmNowNml, 2u);
            goto LABEL_307;
          goto LABEL_316;
        }
        if ((v60 | v61 | v63 | v62) != 1)
          goto LABEL_246;
        sub_854710(&p, 0);
        sub_854710(&v271, 0);
        sub_854930(&v270, 0);
        sub_854710(&p, 1u);
        sub_854710(&v271, 1u);
        sub_854930(&v270, 1u);
        sub_854710(&p, 2u);
        sub_854710(&v271, 2u);
        sub_854930(&v270, 2u);
        sub_854930(&v270, 3u);
        SDF_VU0__LOADVECTOR(v270);
        SDF_VU0__NORMALIZE();
        SDF_VU0__STOREVECTOR(&v269);
        sub_854710(&v271, 0);
        sub_854710(&v269, 0);
        sub_854930(&p, 0);
        sub_854710(&v271, 1u);
        sub_854710(&v269, 1u);
        sub_854930(&p, 1u);
        sub_854710(&v271, 2u);
        sub_854710(&v269, 2u);
        sub_854930(&p, 2u);
        v120 = p.x;
        v119 = p.y;
        v122 = p.z;
        v121 = p.w;
        v278.x = v120;
        v278.y = v119;
        v278.z = v122;
        v278.w = v121;
        dds3SetPosPoseSet(p_handle, v278);
        v262 = 0;
        v263 = 0;
        v125 = fldGb;
        sub_854710(&p, 0);
        v125->playerX = v126;
        v127 = fldGb;
        sub_854710(&p, 1u);
        v127->playerY = v128;
        v129 = fldGb;
        sub_854710(&p, 2u);
        v129->playerZ = v130;
        sub_854930(&v262, 0);
        sub_854930(&v262, 1u);
        sub_854930(&v262, 2u);
        v132 = v262;
        v133 = v263;
        *&v279.x = v132;
        *&v279.z = v133;
        fldHitChkUnitVWM(v279);
        v135 = fldGb;
        if (!v135->HitUpdate)
        {
LABEL_246:
          dds3GetPosPoseSet(p_handle);
          SDF_VU0__STOREVECTOR(&p);
          SDF_VU0__COPYVECTOR(&dst, (*p_handle)->poseset->pos2, 0);
          sub_854710(&dst, 0);
          v143 = v142;
          sub_854710(&p, 0);
          v146 = v145;
          v147 = sdfFabs(v143 - v146);
          v148 = &(*p_handle)->poseset->pos2;
          if (v147 >= 1.0)
          {
            sub_854710(&dst, 0);
            sub_854710(&p, 0);
            sub_854710(&dst, 0);
          }
          else
          {
            sub_854710(&p, 0);
          }
          sub_854930(v148, 0);
          sub_854710(&dst, 1u);
          v150 = v149;
          sub_854710(&p, 1u);
          v153 = v152;
          v154 = sdfFabs(v150 - v153);
          v155 = &(*p_handle)->poseset->pos2;
          if (v154 >= 1.0)
          {
            sub_854710(&dst, 1u);
            sub_854710(&p, 1u);
            sub_854710(&dst, 1u);
          }
          else
          {
            sub_854710(&p, 1u);
          }
          sub_854930(v155, 1u);
          sub_854710(&dst, 2u);
          v157 = v156;
          sub_854710(&p, 2u);
          v160 = v159;
          v161 = sdfFabs(v157 - v160);
          v162 = &(*p_handle)->poseset->pos2;
          if (v161 >= 1.0)
          {
            sub_854710(&dst, 2u);
            sub_854710(&p, 2u);
            sub_854710(&dst, 2u);
          }
          else
          {
            sub_854710(&p, 2u);
          }
          sub_854930(v162, 2u);
          sub_854930(&(*p_handle)->poseset->pos2, 3u);
          goto LABEL_268;
        }
        v135->playerX = v135->playerNewX;
        v136 = fldGb;
        if (v136->fieldID == 1)
        {
          v136->playerY = (v136->playerNewY + 44.0) + -11.0;
          if ((v134->_2.bitflags2 & 2) == 0)
            goto LABEL_242;
        }
        else
        {
          v136->playerY = v136->playerNewY + 44.0;
          if ((v134->_2.bitflags2 & 2) == 0)
            goto LABEL_242;
        }
LABEL_242:
        fldGb->playerZ = fldGb->playerNewZ;
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sub_854930(&p, 2u);
        v139 = p.x;
        v138 = p.y;
        v141 = p.z;
        v140 = p.w;
        v280.x = v139;
        v280.y = v138;
        v280.z = v141;
        v280.w = v140;
        dds3SetPosPoseSet(p_handle, v280);
        fldGb->HitUpdate = 0;
        goto LABEL_246;
      }
      ooyCamKakudo = 0.0;
      v66 = v60 ^ 1;
      if (((v62 ^ 1) & 1) == 0 && (v66 & 1) == 0)
      {
        v67 = 45.0;
        if ((v65->_2.bitflags2 & 2) != 0)
          goto LABEL_135;
LABEL_148:
        v69 = v67 - ooyCamKakudo;
        v70 = -v69;
        v72 = OOYRAD(v70);
        sdfSin(v72);
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        v73 = OOYRAD(v70);
        sdfCos(v73);
        goto LABEL_158;
      }
      if (((v62 ^ 1 | v61 ^ 1) & 1) != 0)
      {
        if (((v63 ^ 1 | v66) & 1) != 0)
        {
          if (((v63 ^ 1 | v61 ^ 1) & 1) != 0)
          {
            if (v62)
            {
              v67 = -0.0;
              if ((v65->_2.bitflags2 & 2) == 0)
                goto LABEL_148;
            }
            else if (v63)
            {
              v67 = 180.0;
              if ((v65->_2.bitflags2 & 2) == 0)
                goto LABEL_148;
            }
            else
            {
              if (!v60)
              {
                if (!v61)
                {
                  sub_854930(&p, 0);
                  sub_854930(&p, 1u);
LABEL_158:
                  sub_854930(&p, 2u);
                  v76 = p.x;
                  v75 = p.y;
                  v78 = p.z;
                  v77 = p.w;
                  v275.x = v76;
                  v275.y = v75;
                  v275.z = v78;
                  v275.w = v77;
                  dds3SetPosPoseSet(p_handle, v275);
                    goto LABEL_162;
                  goto LABEL_126;
                }
                v67 = -90.0;
                if ((v65->_2.bitflags2 & 2) != 0)
                  goto LABEL_135;
                goto LABEL_148;
              }
              v67 = 90.0;
              if ((v65->_2.bitflags2 & 2) == 0)
                goto LABEL_148;
            }
          }
          else
          {
            v67 = -135.0;
            if ((v65->_2.bitflags2 & 2) == 0)
              goto LABEL_148;
          }
        }
        else
        {
          v67 = 135.0;
          if ((v65->_2.bitflags2 & 2) == 0)
            goto LABEL_148;
        }
      }
      else
      {
        v67 = -45.0;
        if ((v65->_2.bitflags2 & 2) == 0)
          goto LABEL_148;
      }
LABEL_135:
      goto LABEL_148;
    }
LABEL_43:
    goto LABEL_45;
  }
  return 0;
}

// 0x10d3d40
void fldPlayerCalc_Wm3(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  s64 v7;
  s64 v8;
  dds3Basic_t_o **p_handle;
  UnityEngine_Object_o *fldPlayerObj;
  UnityEngine_Transform_o *transform;
  s64 v18;
  UnityEngine_Transform_o *v19;
  s64 v20;
  s64 v21;
  s64 v22;
  UnityEngine_Vector3_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o v25;

  v21 = 0;
  v22 = 0;
LABEL_7:
  sub_854690(&v21, 1.0, 1.0, 1.0, 1.0);
  else if (fldWmWarpMode != 1)
  {
    return;
  }
  sub_854710(&v21, 0);
  sub_854930(&v21, 0);
  sub_854710(&v21, 1u);
  sub_854930(&v21, 1u);
  sub_854710(&v21, 2u);
  sub_854930(&v21, 2u);
  v7 = v21;
  v8 = v22;
  p_handle = &fldUnitControl->handle;
  *&v24.x = v7;
  *&v24.z = v8;
  dds3SetSclPoseSet(p_handle, v24);
  fldWmSize = fldWmSize + -0.08;
  if (fldWmSize <= 0.1)
  {
    fldWmSize = 0.1;
  }
  if (op_Inequality(fldPlayerObj, 0, 0))
  {
    transform = get_transform(fldPlayerObj, 0);
    v18 = v21;
    v19 = transform;
    v20 = v22;
    *&v25.x = v18;
    *&v25.z = v20;
    v23 = op_Implicit_8738992(v25);
    set_localScale(v19, v23);
  }
}

// 0x10d40a0
void fldPlayerCalc_Wm4(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  struct fldPlayer_StaticFields **p_static_fields;
  s64 v10;
  s64 v11;
  dds3Basic_t_o **p_handle;
  UnityEngine_Object_o *fldPlayerObj;
  UnityEngine_Transform_o *transform;
  s64 v21;
  UnityEngine_Transform_o *v22;
  s64 v23;
  s64 v24;
  s64 v25;
  UnityEngine_Vector3_o v26;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o v28;

  v24 = 0;
  v25 = 0;
LABEL_7:
  sub_854690(&v24, 1.0, 1.0, 1.0, 1.0);
  if (fldWmWarpMode == 2)
  {
    fldWmWarpMode = 3;
    (*p_static_fields)->fldWmSize = 0.1;
  }
  else
  {
    sub_854710(&v24, 0);
    sub_854930(&v24, 0);
    sub_854710(&v24, 1u);
    sub_854930(&v24, 1u);
    sub_854710(&v24, 2u);
    sub_854930(&v24, 2u);
    v10 = v24;
    v11 = v25;
    p_handle = &fldUnitControl->handle;
    *&v27.x = v10;
    *&v27.z = v11;
    dds3SetSclPoseSet(p_handle, v27);
    fldWmSize = fldWmSize + 0.04;
    if (fldWmSize > 1.0)
    {
      fldWmSize = 1.0;
      fldWmWarpMode = 0;
    }
    if (op_Inequality(fldPlayerObj, 0, 0))
    {
      transform = get_transform(fldPlayerObj, 0);
      v21 = v24;
      v22 = transform;
      v23 = v25;
      *&v28.x = v21;
      *&v28.z = v23;
      v26 = op_Implicit_8738992(v28);
      set_localScale(v22, v26);
    }
  }
}

// 0x10da8d0
s32 fldPlayerChkAna(void) {
  else
  {
    if (gfldPlayerAnaCnt)
      return 1;
  }
  if (gfldPlayerDamegeCnt)
    return 1;
LABEL_9:
  return gfldPlayerHasiCnt != 0;
}

// 0x10bae50
void fldPlayerEventStop(bool sw) {
  s32 v5;

  if ((fldGb->fieldID & 0xFFFFFFFE) == 60 && sw)
    v5 = 5;
  else
    v5 = 0;
  fldPlayerAnimation(v5, 0);
}

// 0x10bd5d0
s32 fldPlayerFastSet(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;
  struct fldGlobalWork_t_o *fldGb;
  f32 v11;
  struct fldGlobalWork_t_o *v12;
  f32 v13;
  struct fldGlobalWork_t_o *v14;
  f32 v15;
  s64 v17;
  s64 v18;
  struct fldGlobal_StaticFields **p_static_fields;
  struct fldGlobalWork_t_o *v21;
  struct fldGlobalWork_t_o *v24;
  f32 v25;
  struct fldGlobalWork_t_o *v26;
  f32 v27;
  struct fldGlobalWork_t_o *v28;
  f32 v29;
  s64 v31;
  s64 v32;
  fldGlobal_c *v33;
  struct fldGlobalWork_t_o *v34;
  struct fldGlobalWork_t_o *v35;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s64 v42;
  s64 v43;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector4_o v46;
  UnityEngine_Vector4_o v47;

  *&p.x = 0;
  *&p.z = 0;
  v42 = 0;
  v43 = 0;
LABEL_7:
  *&p.x = 0;
  *&p.z = 0;
  v42 = 0;
  v43 = 0;
  LODWORD(v4[2].klass->_1.name) = 0;
  fldPlayerFastSetForUnity();
  if (l_UseCollision)
  {
    p_handle = &fldUnitControl->handle;
    if (fldGb->fieldID > 9)
    {
      dds3GetPosPoseSet(p_handle);
      SDF_VU0__STOREVECTOR(&p);
      fldGb->playerOldX = fldGb->playerX;
      fldGb->playerOldY = fldGb->playerY;
      fldGb->playerOldZ = fldGb->playerZ;
      sub_854710(&p, 0);
      fldGb->playerX = v11;
      v12 = fldGb;
      sub_854710(&p, 1u);
      v12->playerY = v13 + 10.0;
      v14 = fldGb;
      sub_854710(&p, 2u);
      v14->playerZ = v15;
      sub_854930(&v42, 0);
      sub_854930(&v42, 1u);
      sub_854930(&v42, 2u);
      v17 = v42;
      v18 = v43;
      *&v45.x = v17;
      *&v45.z = v18;
      fldHitChkUnit(v45);
      v21 = fldGb;
      if (!v21->HitUpdate)
        goto LABEL_63;
      v21->playerX = v21->playerNewX;
      (*p_static_fields)->fldGb->playerY = (*p_static_fields)->fldGb->playerNewY + 44.0;
      (*p_static_fields)->fldGb->playerZ = (*p_static_fields)->fldGb->playerNewZ;
LABEL_59:
      sub_854930(&p, 0);
      sub_854930(&p, 1u);
      sub_854930(&p, 2u);
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v47.x = x;
      v47.y = y;
      v47.z = z;
      v47.w = w;
      dds3SetPosPoseSet(p_handle, v47);
      fldGb->HitUpdate = 0;
LABEL_63:
      dds3GetPosPoseSet(p_handle);
      SDF_VU0__STOREVECTOR(&p);
      SDF_VU0__COPYVECTOR(&(*p_handle)->poseset->pos2, p, 0);
      dds3OffPoseSetFlag(&(*p_handle)->poseset, 8u, 0);
      return 0;
    }
    dds3GetPosPoseSet(p_handle);
    SDF_VU0__STOREVECTOR(&p);
    fldGb->playerOldX = fldGb->playerX;
    fldGb->playerOldY = fldGb->playerY;
    fldGb->playerOldZ = fldGb->playerZ;
    v24 = fldGb;
    sub_854710(&p, 0);
    v24->playerX = v25;
    v26 = fldGb;
    sub_854710(&p, 1u);
    v26->playerY = v27 + 20.0;
    v28 = fldGb;
    sub_854710(&p, 2u);
    v28->playerZ = v29;
    sub_854930(&v42, 0);
    sub_854930(&v42, 1u);
    sub_854930(&v42, 2u);
    v31 = v42;
    v32 = v43;
    *&v46.x = v31;
    *&v46.z = v32;
    fldHitChkUnit(v46);
    v34 = fldGb;
    if (!v34->HitUpdate)
      goto LABEL_63;
    v34->playerX = v34->playerNewX;
    v35 = fldGb;
    if (v35->fieldID == 1)
    {
      v35->playerY = (v35->playerNewY + 44.0) + -11.0;
      if ((v33->_2.bitflags2 & 2) == 0)
        goto LABEL_58;
    }
    else
    {
      v35->playerY = v35->playerNewY + 44.0;
      if ((v33->_2.bitflags2 & 2) == 0)
        goto LABEL_58;
    }
LABEL_58:
    fldGb->playerZ = fldGb->playerNewZ;
    goto LABEL_59;
  }
  return 0;
}

// 0x10dae80
void fldPlayerFastSetForUnity(void) {
  struct UnityEngine_GameObject_o *mhfldPlayerFileBk;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *v10;
  UnityEngine_GameObject_o *v13;
  Il2CppObject *v14;
  UnityEngine_Object_o *v16;
  bool v19;
  struct UnityEngine_Animator_o *monitor;
  UnityEngine_Transform_o *transform;
  UnityEngine_Object_o *fldPlayerObjM;
  UnityEngine_Transform_o *v35;
  struct dds3Basic_t_o *handle;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v41;
  s64 *v42;
  u64 v43[3];
  UnityEngine_Quaternion_o v44;
  UnityEngine_Quaternion_o v45;

  fldPlayerObj = mhfldPlayerFileBk;
  fldPlayerObjM = mhfldPlayerFileM;
  if (fldGb->fieldID <= 9)
  {
    fldPlayerAnm = GetComponent_object_(fldPlayerObj);
    if (fldGb->fieldID == 1)
    {
      transform = get_transform(fldPlayerObj, 0);
      {
      }
      v44 = Euler(45.0, 0.0, 0.0);
      set_rotation(transform, v44);
    }
    if (op_Inequality(fldPlayerObjM, 0, 0))
    {
      fldPlayerAnmM = GetComponent_object_(fldPlayerObjM);
      if (fldGb->fieldID == 1)
      {
        v35 = get_transform(fldPlayerObjM, 0);
        {
        }
        v45 = Euler(45.0, 0.0, 0.0);
        set_rotation(v35, v45);
      }
    }
      goto LABEL_77;
  }
  else
  {
    Component_object = GetComponent_object_(fldPlayerObj);
    fldPlayerAnm = Component_object[1].monitor;
    gameObject = get_gameObject(fldPlayerAnm);
    v10 = GetComponent_object_(gameObject);
    if (op_Equality(v10, 0, 0))
    {
      v13 = get_gameObject(fldPlayerAnm);
      v14 = AddComponent_object_(v13);
      SetCharacterType(v14, 1);
    }
    v16 = fldPlayerObjM;
    v19 = op_Inequality(v16, 0, 0);
    if (v19)
    {
      monitor = GetComponent_object_(fldPlayerObjM)[1].monitor;
      fldPlayerAnmM = monitor;
    }
    fldPlayerAnimation(0, 1);
      goto LABEL_77;
  }
LABEL_77:
LABEL_79:
  else
  {
    handle = fldUnitControl->handle;
    if (!handle)
      return;
  }
  handle->gameObject = fldPlayerObj;
  workdata = handle->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v43);
    if ((v43[0] & 1) != 0)
      v41 = v43[2];
    else
      v41 = v43 + 1;
    v42 = sub_8C4940(v41);
  }
  *(workdata[2].klass->_1.interfaceOffsets + 12) = handle;
}

// 0x10cad90
s32 fldPlayerMirChk(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle2;
  fldUnitControl_t_Fields *p_fields;
  dds3PoseSet_t_o **p_poseset;
  s32 v10;
  struct dds3PoseSet_t_o *poseset;
  s32 *p_y;
  u32 *p_x;
  u32 *p_z;
  u32 *p_w;
  u32 *v16;
  s32 *v17;
  u32 *v18;
  u32 *v19;
  u32 v20;
  s32 v21;
  u32 v22;
  f32 v23;
  f32 v24;
  UnityEngine_Object_o *v27;
  f32 v29;
  f32 v31;
  f32 v32;
  UnityEngine_Transform_o *v33;
  UnityEngine_Transform_o *v34;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  UnityEngine_Transform_o *v43;
  UnityEngine_Transform_o *v44;
  UnityEngine_Object_o *fldPlayerObjM;
  UnityEngine_Transform_o *transform;
  UnityEngine_Vector3_o v52;
  UnityEngine_Quaternion_o rotation;
  s64 v54;
  u64 v55;
  UnityEngine_Vector3_o v56;
  UnityEngine_Quaternion_o v57;

  *&rotation.x = 0;
  *&rotation.z = 0;
  v54 = 0;
  v55 = 0;
LABEL_7:
  if (fldUnitControl)
  {
    p_handle2 = &fldUnitControl->handle2;
    if (fldUnitControl->handle2)
    {
      p_fields = &fldUnitControl->fields;
      if (dds3ObjectBaseCheckFlag(&fldUnitControl->handle, 1u))
      {
        dds3ObjectBaseOnFlag(p_handle2, 1u, 0);
      }
      else
      {
        if (fldPlayerMirAreaChk())
        {
          p_poseset = &p_fields->handle->poseset;
          v10 = dds3CheckPoseSetFlag(p_poseset, 8u);
          poseset = p_fields->handle->poseset;
          p_y = &poseset->pos.y;
          p_x = &poseset->pos.x;
          p_z = &poseset->pos.z;
          p_w = &poseset->pos.w;
          v16 = &poseset->pos2.x;
          v17 = &poseset->pos2.y;
          v18 = &poseset->pos2.z;
          v19 = &poseset->pos2.w;
          if (v10)
            p_x = v16;
          else
            v19 = p_w;
          if (v10)
          {
            p_y = v17;
            p_z = v18;
          }
          v20 = *p_z;
          v21 = *p_y;
          v22 = *v19;
          LODWORD(v54) = *p_x;
          HIDWORD(v54) = v21;
          v55 = __PAIR64__(v22, v20);
          sub_854710(&v54, 1u);
          if (v23 <= -3.5 || (sub_854710(&v54, 1u), v24 >= 3.5))
          {
            dds3ObjectBaseOnFlag(p_handle2, 1u, 0);
            if (op_Inequality(fldPlayerObjM, 0, 0))
            {
              transform = get_transform(fldPlayerObjM, 0);
              v52.z = 0.0;
              *&v52.x = 0;
              sub_8524C0(&v52.x, 0.0, 0.0, 0.0);
              set_localScale(transform, v52);
            }
          }
          else
          {
            dds3ObjectBaseOffFlag(p_handle2, 1u);
            v27 = fldPlayerObjM;
            if (op_Inequality(v27, 0, 0))
            {
              v29 = *&v54 / 100.0;
              v31 = -0.02 - (*(&v54 + 1) / 100.0);
              v32 = *&v55 / 100.0;
              v33 = get_transform(fldPlayerObjM, 0);
              v56.x = v29;
              v56.y = v31;
              v56.z = v32;
              set_localPosition(v33, v56);
              v34 = get_transform(fldPlayerObj, 0);
              rotation = get_rotation(v34);
              sub_1A1CAE0(&rotation.x, 0);
              v38 = v37;
              v40 = v39;
              v41 = -fmodf(fldGb->PlayerKakudo + 180.0, 360.0);
              v43 = get_transform(fldPlayerObjM, 0);
              {
              }
              v57 = Euler(v38, v41, v40);
              set_rotation(v43, v57);
              v44 = get_transform(fldPlayerObjM, 0);
              v52.z = 0.0;
              *&v52.x = 0;
              sub_8524C0(&v52.x, 1.0, -1.0, 1.0);
              set_localScale(v44, v52);
              SetActive(fldPlayerObjM, 1, 0);
            }
          }
        }
      }
    }
  }
  return 0;
}

// 0x10db490
void fldPlayerMotReset(void) {
  u64 *v1;
  dds3Basic_t_o *ActiveScene;
  dds3ModelHandle_t_o *v8;
  s32 MotionMinorNum;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  v1 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v1);
  if (fldGb->fieldID >= 10)
  {
    ActiveScene = dds3GetActiveScene();
    pBasic = dds3GetActiveUnitSceneBasic(ActiveScene);
    if (pBasic)
    {
      dds3UnitObjectBasicGetControlWorkData(&pBasic);
      MotionMinorNum = mdlGetMotionMinorNum(v8);
      if (MotionMinorNum != 9)
      {
        fldPlayerSingleMotion(9, 0);
      }
    }
  }
}

// 0x10da9b0
void fldPlayerMotReset2(void) {
  u64 *v1;
  dds3Basic_t_o *ActiveScene;
  dds3ModelHandle_t_o *v8;
  s32 MotionMinorNum;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  v1 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v1);
  if (fldGb->fieldID >= 10)
  {
    ActiveScene = dds3GetActiveScene();
    pBasic = dds3GetActiveUnitSceneBasic(ActiveScene);
    if (pBasic)
    {
      dds3UnitObjectBasicGetControlWorkData(&pBasic);
      MotionMinorNum = mdlGetMotionMinorNum(v8);
      if (MotionMinorNum != 9)
      {
        fldPlayerSingleMotion(9, 0);
      }
    }
  }
}

// 0x10cb290
void fldPlayerMotion(s32 hisMotion, s32 upMotion, f32 motHokan) {
  if (hisMotion != upMotion)
  {
    fldPlayerSingleMotion(upMotion, 0);
  }
}

// 0x10cb5a0
void fldPlayerMotionSe(s32 hisMotion, s32 upMotion) {
  UnityEngine_GameObject_o *fldPlayerObj;
  s32 MotionFrameForUnity;
  fldGlobal_c *v11;
  struct fldGlobalWork_t_o *fldGb;
  f32 PlayerMotionFrame;
  s32 v14;
  s32 fieldID;
  s16 v16;
  s32 v17;
  struct fldGlobalWork_t_o *v18;
  s32 FootSEUp;
  s32 v20;
  s32 FootSE;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v34;
  f32 v35;
  f32 v36;
  s32 v38;
  s32 v39;
  u32 RandA;
  u32 v41;
  s32 v43;
  s32 v44;
  u32 v45;
  s32 v46;
  s32 v48;
  s32 v49;

LABEL_7:
  dds3ObjectBaseGetModelHandle(&fldUnitControl->handle);
  MotionFrameForUnity = mdlGetMotionFrameForUnity(fldPlayerObj);
  PlayerMotionFrame = fldGb->PlayerMotionFrame;
  fldGb->PlayerMotionFrame = MotionFrameForUnity;
  if (hisMotion != 11)
  {
    if (hisMotion == 13)
    {
      if (MotionFrameForUnity >= 12 && PlayerMotionFrame < 12.0)
      {
        v14 = 39;
LABEL_55:
        fldSePlay(v14);
        return;
      }
      return;
    }
    v16 = *&v11->_2.bitflags1;
    if ((v16 & 0x200) != 0)
    {
      v17 = v16 & 0x200;
      v18 = fldGb;
      FootSEUp = v18->FootSEUp;
      if (FootSEUp)
      {
LABEL_34:
        if (FootSEUp != 4)
        {
          if (FootSEUp != 3)
          {
            if (FootSEUp == 2)
              goto LABEL_40;
            goto LABEL_65;
          }
          goto LABEL_69;
        }
        goto LABEL_67;
      }
    }
    else
    {
      v17 = 0;
      v18 = fldGb;
      FootSEUp = v18->FootSEUp;
      if (FootSEUp)
        goto LABEL_34;
    }
    FootSE = v18->FootSE;
    if (FootSE != 3)
    {
      if (FootSE != 2)
      {
        if (FootSE == 1)
        {
LABEL_40:
          v20 = 20;
          if ((v11->_2.bitflags2 & 2) == 0)
            goto LABEL_70;
LABEL_41:
LABEL_70:
          if (fldGb->cammode == 1)
          {
            sub_854710(&g_cameraPos, 0);
            v24 = v23;
            sub_854710(&g_targetPos, 0);
            v26 = v25;
            sub_854710(&g_cameraPos, 1u);
            v28 = v27;
            sub_854710(&g_targetPos, 1u);
            v30 = v28 - v29;
            sub_854710(&g_cameraPos, 2u);
            v32 = v31;
            sub_854710(&g_targetPos, 2u);
            v35 = v32 - v34;
            v36 = v24 - v26;
            v38 = 127
                * (7000
                 - fmaxf(fminf(sdfSqrt(((v36 * v36) + (v30 * v30)) + (v35 * v35), 0) + -500.0, 7000.0), 0.0));
            if (v38 > 895999)
            {
              v39 = 127;
              if (hisMotion > 0x10)
                goto LABEL_100;
            }
            else
            {
              v39 = (v38 / 7000) & ~((v38 / 7000) >> 31);
              if (hisMotion > 0x10)
                goto LABEL_100;
            }
          }
          else
          {
            v39 = (dds3GetRandA("") >> 2) ^ 0x7F;
            if (hisMotion > 0x10)
              goto LABEL_100;
          }
          if (((1 << hisMotion) & 0x10301) != 0)
          {
LABEL_87:
            RandA = dds3GetRandA("");
            v41 = dds3GetRandA("");
            v43 = upMotion - 1;
            v44 = ((RandA >> 4) - 3 * (((2863311531u * (RandA >> 4)) >> 32) >> 1)) | v20;
            v45 = ((v41 >> 4) % 3) | v20;
            switch (v43)
            {
              case 0:
              case 1:
              case 2:
              case 16:
              case 18:
              case 19:
                if (MotionFrameForUnity >= 4 && PlayerMotionFrame < 4.0)
                {
                  fldSeVol(v44, v39);
                }
                if (MotionFrameForUnity >= 13 && PlayerMotionFrame < 13.0)
                  goto LABEL_147;
                break;
              case 3:
                if (MotionFrameForUnity >= 4 && PlayerMotionFrame < 4.0)
                {
                  fldSeVol(v44, v39);
                }
                if (MotionFrameForUnity >= 20 && PlayerMotionFrame < 20.0)
                  goto LABEL_147;
                break;
              case 4:
              case 5:
                if (MotionFrameForUnity >= 2 && PlayerMotionFrame < 2.0)
                {
                  fldSeVol(v44, v39);
                }
                if (MotionFrameForUnity >= 16 && PlayerMotionFrame < 16.0)
                  goto LABEL_147;
                break;
              case 6:
                if (PlayerMotionFrame != 0.0)
                {
                  if (MotionFrameForUnity >= 14 && PlayerMotionFrame < 14.0)
                  {
                    fldSeVol(v44, v39);
                  }
                  if (MotionFrameForUnity >= 28 && PlayerMotionFrame < 28.0)
                  {
LABEL_147:
                    v46 = v45;
                    goto LABEL_151;
                  }
                }
                break;
              case 13:
              case 14:
                v48 = (dds3GetRandA("") % 0x1F) ^ 0x7F;
                if (MotionFrameForUnity >= 1 && PlayerMotionFrame < 1.0)
                {
                  fldSeVol(36, v48);
                }
                if (MotionFrameForUnity >= 18 && PlayerMotionFrame < 18.0)
                {
                  v46 = 55;
                  v49 = v48;
                  goto LABEL_152;
                }
                break;
              default:
                return;
            }
            return;
          }
LABEL_100:
          if (upMotion == 8)
          {
            v46 = v20 | 3;
LABEL_151:
            v49 = v39;
LABEL_152:
            fldSeVol(v46, v49);
            return;
          }
          goto LABEL_87;
        }
LABEL_65:
        v20 = 16;
        if ((v11->_2.bitflags2 & 2) == 0)
          goto LABEL_70;
        goto LABEL_41;
      }
LABEL_69:
      v20 = 24;
      if ((v11->_2.bitflags2 & 2) == 0)
        goto LABEL_70;
      goto LABEL_41;
    }
LABEL_67:
    v20 = 28;
    if ((v11->_2.bitflags2 & 2) == 0)
      goto LABEL_70;
    goto LABEL_41;
  }
  fieldID = fldGb->fieldID;
  if (fieldID != 602)
  {
    if (MotionFrameForUnity >= 29 && PlayerMotionFrame < 29.0 && fieldID != 11)
    {
      v14 = 37;
      goto LABEL_55;
    }
  }
}

// 0x10d3530
void fldPlayerObjSetControlSvs(dds3Basic_t **pObjectBasic, s32 svs, void *obj) {
  Il2CppObject *Component_object;

  dds3ObjectBaseSetControlBasicSvs(pObjectBasic, svs);
  else if (gPlayerMskBak == svs)
  {
    goto LABEL_18;
  }
  if (!op_Inequality(obj, 0, 0))
    goto LABEL_18;
  Component_object = GetComponent_object_(obj);
  if (!op_Inequality(Component_object, 0, 0))
  {
LABEL_18:
      goto LABEL_21;
    goto LABEL_19;
  }
  if (svs)
  {
    SetTransparent(Component_object, (svs << 23) & 0xFF000000, 0.25, 0, 0);
      goto LABEL_21;
  }
  else
  {
    RetTransparent(Component_object, 0);
      goto LABEL_21;
  }
LABEL_19:
LABEL_21:
  gPlayerMskBak = svs;
}

// 0x10ba520
void fldPlayerOff(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle2;
  struct dds3Basic_t_o *handle2;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *Child;
  UnityEngine_Object_o *fldPlayerObjM;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v15;

LABEL_7:
  dds3ObjectBaseOnFlag(&fldUnitControl->handle, 1u, 0);
  handle2 = fldUnitControl->handle2;
  p_handle2 = &fldUnitControl->handle2;
  if (handle2)
    dds3ObjectBaseOnFlag(p_handle2, 1u, 0);
  fldPlayerMotReset2();
  transform = get_transform(fldPlayerObj, 0);
  Child = GetChild(transform, 0);
  localPosition = get_localPosition(Child);
  v15.x = localPosition.x;
  v15.z = localPosition.z;
  v15.y = 0.0;
  set_localPosition(Child, v15);
  SetActive(fldPlayerObj, 0, 0);
  if (op_Inequality(fldPlayerObjM, 0, 0))
  {
    SetActive(fldPlayerObjM, 0, 0);
  }
}

// 0x10ba350
void fldPlayerOn(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle2;
  struct dds3Basic_t_o *handle2;
  UnityEngine_Object_o *fldPlayerObjM;

LABEL_7:
  dds3ObjectBaseOffFlag(&fldUnitControl->handle, 1u);
  handle2 = fldUnitControl->handle2;
  p_handle2 = &fldUnitControl->handle2;
  if (handle2)
    dds3ObjectBaseOffFlag(p_handle2, 1u);
  fldStatusSet();
  if (!evtBitCheck(2800))
  {
    SetActive(fldPlayerObj, 1, 0);
    if (op_Inequality(fldPlayerObjM, 0, 0))
    {
      SetActive(fldPlayerObjM, 1, 0);
    }
  }
}

// 0x10db630
void fldPlayerPosRot(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  fldUnitControl_t_Fields *p_fields;
  s32 cammode;
  s32 v7;
  s32 gFldNowTalk;
  s32 v15;
  f32 PlayerKakudo;
  f32 v19;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 v25;
  struct fldGlobalWork_t_o *fldGb;
  f32 v30;
  struct fldGlobalWork_t_o *v32;
  f32 v33;
  struct fldGlobalWork_t_o *v34;
  f32 v35;
  struct fldGlobalWork_t_o *v36;
  f32 v37;
  struct dds3Basic_t_o *v39;
  dds3Basic_t_o **p_handle2;
  struct dds3Basic_t_o *handle2;
  dds3PoseSet_t_o **p_poseset;
  u64 v43;
  dds3Basic_t_o *v45;
  f32 v46;
  f32 v47;
  f32 v49;
  f32 v50;
  f32 v51;
  s64 v52;
  f32 v53;
  f32 v54;
  f32 v56;
  f32 v57;
  f32 v58;
  s64 v59;
  f32 v60;
  f32 v61;
  f32 v63;
  f32 v64;
  f32 v65;
  s64 v66;
  UnityEngine_Vector4_o v93;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v96;
  UnityEngine_Vector4_o v97;

  *&v96.x = 0;
  *&v96.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
LABEL_7:
  *&v96.x = 0;
  *&v96.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  if (fldUnitControl)
  {
    p_fields = &fldUnitControl->fields;
    if (fldUnitControl->handle)
    {
      else
      {
        cammode = fldGb->cammode;
        if (!cammode)
          goto LABEL_18;
      }
      else if (cammode != 1)
      {
        goto LABEL_22;
      }
LABEL_18:
      if (fldGb->fieldID >= 11)
      {
        if (gFldNowTalk == 1)
          goto LABEL_33;
        if (gFldNowTalk == 2)
        {
LABEL_33:
          if (!fldGb->cammode)
          {
            setNoHokamOne();
          }
          fldPlayerPosRot_RESTORE();
          v7 = 1;
LABEL_45:
          else
          {
            if (!bRestoreMode)
              goto LABEL_73;
          }
          bRestoreMode = 0;
          v15 = fldGb->cammode;
          if (!v15)
            goto LABEL_128;
          if (v15 == 1)
          {
LABEL_128:
            *&v93.x = 0;
            *&v93.z = 0;
            sub_854690(&v93.x, 0.0, 1.0, 0.0, 1.0);
            SDF_VU0__LOADVECTOR(v93);
            PlayerKakudo = fldGb->PlayerKakudo;
            v19 = OOYRAD(PlayerKakudo);
            FromRotation(v19);
            SDF_VU0__STOREVECTOR(&p);
            x = p.x;
            y = p.y;
            z = p.z;
            w = p.w;
            v97.x = x;
            v97.y = y;
            v97.z = z;
            v97.w = w;
            dds3SetRotPoseSet(&fldUnitControl->handle, v97);
            dds3GetRotPoseSet(&fldUnitControl->handle);
            v25 = EulerAngleAxisY();
            OOYDEG(v25);
            if (!v7)
              return;
          }
LABEL_73:
          dds3GetRotPoseSet(&fldUnitControl->handle);
          v30 = EulerAngleAxisY();
          fldGb->PlayerKakudo = OOYDEG(v30);
          fldGb->PlayerKakudoGoal = fldGb->PlayerKakudo;
          dds3GetPosPoseSet(&fldUnitControl->handle);
          SDF_VU0__STOREVECTOR(&v96);
          fldGb->playerOldX = fldGb->playerX;
          fldGb->playerOldY = fldGb->playerY;
          fldGb->playerOldZ = fldGb->playerZ;
          v32 = fldGb;
          sub_854710(&v96, 0);
          v32->playerX = v33;
          v34 = fldGb;
          sub_854710(&v96, 1u);
          v34->playerY = v35;
          v36 = fldGb;
          sub_854710(&v96, 2u);
          v36->playerZ = v37;
          dds3OnPoseSetFlag(&fldUnitControl->handle->poseset, 1u);
          dds3OnPoseSetFlag(&fldUnitControl->handle->poseset, 8u);
          handle2 = fldUnitControl->handle2;
          p_handle2 = &fldUnitControl->handle2;
          v39 = handle2;
          if (handle2)
          {
            p_poseset = &v39->poseset;
            dds3OnPoseSetFlag(p_poseset, 1u);
            dds3OnPoseSetFlag(&(*p_handle2)->poseset, 8u, 0);
          }
          else if (gfldPlayerHasiCnt)
          {
            goto LABEL_90;
          }
          fldPlayerSdwOn(v43);
          SDF_VU0__COPYVECTOR(&dst, p_fields->handle->poseset->pos2);
          sub_854710(&dst, 0);
          v47 = v46;
          sub_854710(&v96, 0);
          v50 = v49;
          v51 = sdfFabs(v47 - v50);
          v52 = &p_fields->handle->poseset->pos2;
          if (v51 >= 1.0)
          {
            sub_854710(&dst, 0);
            sub_854710(&v96, 0);
            sub_854710(&dst, 0);
          }
          else
          {
            sub_854710(&v96, 0);
          }
          sub_854930(v52, 0);
          sub_854710(&dst, 1u);
          v54 = v53;
          sub_854710(&v96, 1u);
          v57 = v56;
          v58 = sdfFabs(v54 - v57);
          v59 = &p_fields->handle->poseset->pos2;
          if (v58 >= 1.0)
          {
            sub_854710(&dst, 1u);
            sub_854710(&v96, 1u);
            sub_854710(&dst, 1u);
          }
          else
          {
            sub_854710(&v96, 1u);
          }
          sub_854930(v59, 1u);
          sub_854710(&dst, 2u);
          v61 = v60;
          sub_854710(&v96, 2u);
          v64 = v63;
          v65 = sdfFabs(v61 - v64);
          v66 = &p_fields->handle->poseset->pos2;
          if (v65 >= 1.0)
          {
            sub_854710(&dst, 2u);
            sub_854710(&v96, 2u);
            sub_854710(&dst, 2u);
          }
          else
          {
            sub_854710(&v96, 2u);
          }
          sub_854930(v66, 2u);
          sub_854930(&p_fields->handle->poseset->pos2, 3u);
          v45 = *p_handle2;
          if (!*p_handle2)
            goto LABEL_119;
          goto LABEL_115;
        }
      }
LABEL_22:
      v7 = 0;
      goto LABEL_45;
    }
  }
}

// 0x10c0f00
void fldPlayerPosRot_RESTORE(void) {
  s16 v3;
  s32 v4;
  struct fldGlobalWork_t_o *fldGb;
  f32 PlayerKakudoGoal;
  f32 v7;
  f32 v9;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  PlayerKakudoGoal = fldGb->PlayerKakudoGoal;
  if (PlayerKakudoGoal > 360.0)
    PlayerKakudoGoal = PlayerKakudoGoal + -360.0;
  if (PlayerKakudoGoal >= 0.0)
    v7 = PlayerKakudoGoal;
  else
    v7 = PlayerKakudoGoal + 360.0;
  v9 = fldPlayerCalc360_8(v7);
  fldGb->PlayerKakudo = v9;
  fldGb->PlayerKakudoGoal = v9;
  bRestoreMode = 1;
}

// 0x10cd6b0
void fldPlayerSdwOff(void) {
  dds3Basic_t_o **p_handle;

LABEL_7:
  p_handle = &fldUnitControl->handle;
  dds3ObjectBaseOffFlag(p_handle, 0x400u);
  dds3ObjectBaseOffFlag(p_handle, 0x200u);
}

// 0x10d3a30
void fldPlayerSdwOn(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  u32 v4;

LABEL_7:
  if (fldUnitControl->handle2)
    v4 = 1024;
  else
    v4 = 512;
  dds3ObjectBaseOnFlag(&fldUnitControl->handle, v4, 0);
}

// 0x10cb320
void fldPlayerSingleMotion(s32 upMotion, bool init) {
  s32 v5;
  s32 v6;
  UnityEngine_GameObject_o *fldPlayerObj;

  v5 = upMotion - 1;
  v6 = 5;
  switch (v5)
  {
    case 0:
      if (fldCheckBatStatusMotion())
        v6 = 51;
      else
        v6 = 1;
      goto LABEL_10;
    case 3:
      v6 = 6;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 4:
      v6 = 3;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 5:
      v6 = 2;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 6:
      v6 = 4;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 7:
      if (fldCheckBatStatusMotion())
        v6 = 50;
      else
        v6 = 0;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 8:
LABEL_10:
      if (init)
        goto LABEL_11;
      goto LABEL_49;
    case 9:
      v6 = 52;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 12:
      v6 = 56;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 16:
      v6 = 51;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 17:
      v6 = 50;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 20:
      v6 = 60;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 21:
      v6 = 61;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    case 22:
      v6 = 62;
      if (!init)
        goto LABEL_49;
      goto LABEL_11;
    default:
      v6 = 0;
      if (init)
        goto LABEL_11;
LABEL_49:
      if (fldPlayerAct != v6)
      {
        if (!fldCamNowEveCamera(0))
        {
LABEL_11:
          mdlSingleMotionForUnity(fldPlayerObj, "anim", v6, 1, 0);
          mdlSingleMotionForUnity(fldPlayerObjM, "anim", v6, 1, 0);
          fldPlayerAct = v6;
        }
      }
      return;
  }
}

// 0x10d36c0
void fldPlayerStayCheck(s32 *upMotion, s32 hisMotion) {
 if (PlayerStayCnt < 1)
  {
    return;
  }
  *upMotion = hisMotion;
}

// 0x10cd790
void fldPlayerSvsOff(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;

LABEL_7:
  p_handle = &fldUnitControl->handle;
  fldPlayerObjSetControlSvs(p_handle, 0, fldPlayerObj);
  dds3ObjectBaseOffFlag(p_handle, 0x800u);
}

// 0x10d3b10
void fldPlayerSvsOn(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;

LABEL_7:
  p_handle = &fldUnitControl->handle;
  fldPlayerObjSetControlSvs(p_handle, 128, fldPlayerObj);
  dds3ObjectBaseOnFlag(p_handle, 0x800u, 0);
}

// 0x10dc470
void fldPlayer_Correction_Unity(void) {
  s32 fieldID;
  UnityEngine_Object_o *fldPlayerObj;
  UnityEngine_Transform_o *transform;
  dds3ModelHandle_t_o *v9;
  UnityEngine_Transform_o *v13;
  f32 v14;
  UnityEngine_Transform_o *v15;
  fldPlayer_c *v17;
  UnityEngine_Vector3_o v26;
  UnityEngine_Vector3_o localPosition;

  fieldID = fldGb->fieldID;
  if (fieldID >= 10)
  {
    if (fieldID <= 99)
    {
      if (op_Inequality(fldPlayerObj, 0, 0))
      {
        transform = get_transform(fldPlayerObj, 0);
        localPosition = get_localPosition(transform);
        if (mdlGetMotionMinorNum(v9) == 15)
        {
          v13 = get_transform(fldPlayerObj, 0);
          v14 = 0.04;
        }
        else
        {
          if (fldProcCampChk())
            goto LABEL_50;
          if (fldDbg->MenuOn)
            goto LABEL_50;
          if (gfldPlayerDamegeCnt)
            goto LABEL_50;
          if (fldGb->NoroiDamegeCnt)
            goto LABEL_50;
          if (fldElvChk())
          {
LABEL_50:
              goto LABEL_51;
            goto LABEL_27;
          }
          v13 = get_transform(fldPlayerObj, 0);
          v14 = -0.02;
        }
        v15 = v13;
        v26.z = 0.0;
        *&v26.x = 0;
        sub_8524C0(&v26.x, localPosition.x, localPosition.y + v14, localPosition.z);
        set_localPosition(v15, v26);
          goto LABEL_51;
LABEL_27:
LABEL_51:
        if ((mdlGetMotionMinorNum(v17) & 0xFFFFFFFE) != 0xE)
          return;
        goto LABEL_52;
      }
    }
  }
}

// 0x10dc7d0
void fldPlayer_Enc_Correction_Unity(void) {
  UnityEngine_Object_o *fldPlayerObj;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v8;
  UnityEngine_Vector3_o v9;
  UnityEngine_Vector3_o localPosition;

  if (encChk())
  {
    if (op_Inequality(fldPlayerObj, 0, 0))
    {
      transform = get_transform(fldPlayerObj, 0);
      localPosition = get_localPosition(transform);
      v8 = get_transform(fldPlayerObj, 0);
      v9.z = 0.0;
      *&v9.x = 0;
      sub_8524C0(&v9.x, localPosition.x, localPosition.y + -0.02, localPosition.z);
      set_localPosition(v8, v9);
    }
  }
}

// 0x10c3030
void fldWapAnimCheck(bool sw) {
  UnityEngine_Object_o *fldPlayerObj;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GUILayer_o *Component_GUILayer;
  f32 v11;

  if (!op_Equality(fldPlayerObj, 0, 0))
  {
    transform = get_transform(fldPlayerObj, 0);
    Child = GetChild(transform, 0);
    Component_GUILayer = GetComponent_GUILayer_(Child);
    if (!op_Equality(Component_GUILayer, 0, 0)
      && get_isActiveAndEnabled(Component_GUILayer))
    {
      v11 = 0.0;
      if (sw)
        v11 = 1.0;
      set_speed(Component_GUILayer, v11);
    }
  }
}

// 0x10d3380
s32 mdlGetMotionMinorNum(dds3ModelHandle_t *model) {
  s32 Integer;
  s32 result;

  Integer = GetInteger(fldPlayerAnm, "anim");
  result = 9;
  switch (Integer)
  {
    case 0:
      result = 8;
      break;
    case 1:
      result = Integer;
      break;
    case 2:
      result = 6;
      break;
    case 3:
      result = 5;
      break;
    case 4:
      result = 7;
      break;
    case 5:
      return result;
    case 6:
      result = 4;
      break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 16:
      result = 0;
      break;
    case 11:
    case 14:
    case 15:
      result = Integer;
      break;
    case 13:
      result = Integer;
      break;
    case 50:
      result = 18;
      break;
    case 51:
      result = 17;
      break;
    case 52:
      result = 10;
      break;
    case 56:
      result = 13;
      break;
    case 60:
      result = 21;
      break;
    case 61:
      result = 22;
      break;
    case 62:
      result = 23;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
