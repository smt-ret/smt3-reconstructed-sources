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
    else if (DDS3_PADCHECK_PRESS(10))
    {
      else      return -1;
    }
    return -1;
  }
  else  if (!DDS3_PADCHECK_PRESS(10))
  if (!DDS3_PADCHECK_TRIG(10))
    return -1;
  else if (DDS3_PADCHECK_PRESS(8))
  {
    return -1;
  }
  return cfgGetBit(7u) == 0;
}

// 0x10da790
bool fldCheckBatStatusMotion(void) {
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v5;

  if ((fldDbg->PlayerStatus & 2) != 0)
    return 1;
  unitwork = DDS3_GBWK->unitwork;
  if ((unitwork->m_Items[0]->badstatus & 0x40) != 0)
    return 1;
  v5 = DDS3_GBWK->unitwork;
  return HIBYTE(v5->m_Items[0]->badstatus) & 1;
}

// 0x10dab50
void fldPlayerAlpOff(void) {
    dds3ObjectBaseGetModelHandle(0);
}

// 0x10dace0
void fldPlayerAlpOn(void) {
    dds3ObjectBaseGetModelHandle(0);
}

// 0x10da550
void fldPlayerAnimation(s32 act, bool init) {
  UnityEngine_Object_o *fldPlayerAnm;
  UnityEngine_GameObject_o *fldPlayerObj;
  UnityEngine_Object_o *fldPlayerAnmM;
  UnityEngine_GameObject_o *fldPlayerObjM;

  if (init)
  else if (fldPlayerAct == act)
  {
    return;
  }
  if (!fldCamNowEveCamera(0))
  {
    if (op_Inequality(fldPlayerAnm, 0, 0))
    {
      mdlSingleMotionForUnity(fldPlayerObj, StringLiteral_4572, act, 1, 0);
      fldPlayerAct = act;
      if (op_Inequality(fldPlayerAnmM, 0, 0))
      {
        mdlSingleMotionForUnity(fldPlayerObjM, StringLiteral_4572, act, 1, 0);
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
  fldCamera_c *v47;
  struct fldCamera_StaticFields *static_fields;
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
    if (fldProcCheckFlag(0x40u))

    {
      if (mdlGetMotionMinorNum(v8) != 10)
      {
        Write(StringLiteral_16722, 0);
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
        {
          fldPlayerCalcForUnity(v38);
          return 0;
        }
        if (!*(v38 + 216))
      }
      fldGb->NoroiDamegeCnt = 0;
      fldProcOnFlag(0x40u);
      {
        v25 = fldProcCheckFlag(0x40u) == 0;
        if (!v25)
        {
          if (*(*(*(v27 + 184) + 72LL) + 20LL) <= 9)
          {
            fldPlayerCalc_Wm2(v27);
          }
          fldWmWarpMode = 0;
          v29 = *(*(*(v27 + 184) + 72LL) + 40LL);
          if (v29 == 3)
          {
            v32 = fldPlayerCalc_Nml();
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
            }
            else
            {
              fldPlayerCalc_Nml();
            }
            if (!*(v32 + 216))
          }
          fldPlayerMirChk(v32);
        }
        v33 = *(*(v27 + 184) + 72LL);
        if (v33->fieldID <= 9)
        {
          if (*(*(v39 + 184) + 184LL) == 1)
          {
            if ((*(v39 + 295) & 2) != 0 && !*(v39 + 216))
            fldPlayerCalc_Wm3(v39);
          }
          else
          {
            evtBitCheck(1883);
          }
        }
        if ((*(v27 + 295) & 2) != 0 && !*(v27 + 216))
        {
          v33 = fldGb;
        }

        {
          static_fields = v47->static_fields;
          if (ooyCamLeng < static_fields->CameraCamLeng)
          {
            fldPlayerSvsOn(v34);
          }
        }
        if (!*(v34 + 216))
        {
          fldPlayerSvsOff();
          {
            v49 = fldPlayerCalcHasigo(v37);
            fldPlayerCalc_Hit();
            fldPlayerCalc_WarpRun();
            MotionMinorNum = mdlGetMotionMinorNum(v52);
            fldPlayerMotionSe(MotionMinorNum, MotionMinorNum);
          }
          if (!*(v37 + 216))
        }
        fldPlayerSvsOff(v34);
      }
    }
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
        v3 = v3 + -360.0;
      while (v3 >= 360.0);
    }
  }
  else
  {
    if (v3 >= 360.0)
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
  }
  else
  {
    v16 = v6 - 90.0;
  }
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
  }
  if (v20 >= -180.0)
  {
    v22 = v6 - 180.0;
  }
  v23 = v6 + 360.0;
  if (v4 > 180)
    v23 = v4;
  v22 = v23 - flt_32C3138[v4 > 180];
  {
  }
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
  }
  if (v4 <= 270)
    v6 = v6 + 360.0;
  v28 = v6 - flt_32C3148[v4 > 270];
  {
  }
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
        v3 = v3 + -360.0;
      while (v3 >= 360.0);
    }
  }
  else
  {
    if (v3 >= 360.0)
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
  }
  else
  {
    v16 = v6 - 45.0;
  }
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
  }
  else
  {
    v21 = v6 - 90.0;
  }
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
  }
  else
  {
    v26 = v6 - 135.0;
  }
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
  }
  if (v30 >= -180.0)
  {
    v32 = v6 - 180.0;
  }
  v33 = v6 + 360.0;
  if (v4 > 180)
    v33 = v4;
  v32 = v33 - flt_32C3138[v4 > 180];
  {
  }
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
  }
  else
  {
    v37 = v6 - 225.0;
  }
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
  }
  else
  {
    v43 = v6 - 270.0;
  }
  v46 = sdfFabs(v43);
  if (v46 < v13)
  {
    v41 = 6;
    v13 = v46;
  }
  if ((315.0 - v6) <= 180.0 && (315.0 - v6) >= -180.0)
  {
    v48 = v6 - 315.0;
  }
  if (v4 <= 315)
    v6 = v6 + 360.0;
  v48 = v6 - flt_32C3150[v4 > 315];
  {
  }
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
    dds3CheckPoseSetFlag(0, 0);
    GetFiledCeiling(0, 0);
    fldProcCheckFlag(0);
    evtBitCheck(0);
    fldCamNowEveCamera(0);
    CheckPlayerCtrl();
}

// 0x10cd2b0
s32 fldPlayerCalcHasigo(void) {
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    fldPlayerSdwOff();
    fldPlayerSvsOff();
    return 0;
}

// 0x10d3c80
void fldPlayerCalc_FastStart(void) {
  struct fldPlayer_StaticFields **p_static_fields;
  struct fldPlayer_StaticFields *static_fields;

  else
  {
    p_static_fields = &fldPlayer->static_fields;
    static_fields = fldPlayer->static_fields;
    if (static_fields->fldWmWarpMode)
      return;
  }
  static_fields->fldWmWarpMode = 2;
  (*p_static_fields)->fldWmFastMove = 60.0;
}

// 0x10c3190
void fldPlayerCalc_Hit(void) {
    fldHitChkUnitElv((sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x10cd890
s32 fldPlayerCalc_Nml(void) {
    dds3ObjectBaseGetModelHandle(0);
    mdlGetMotionMinorNum(0);
    fldPlayerSingleMotion(0, 0);
    dds3FadeIn2(0);
    mdlChkMotionEndForUnity_26964128(0, 0);
    fldPlayerMotionSe(0, 0);
    fldProcOnFlag(0);
    fldSePlay(0);
    dds3PadAct(0, 0, 0);
    fldStatusSet();
    fldProcCheckFlag(0);
    fldCamMiwatasiChk();
    fldPlayerObjSetControlSvs(0, 0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    fldPlayerOff();
    dds3OnPoseSetFlag(0, 0);
    DDS3_PADCHECK_PRESS(0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    dds3GetRotPoseSet(0);
    EulerAngleAxisY();
    SDF_VU0__LOADMATRIX(0);
    InversMatrix();
    DDS3_PADCHECK_TRIG(0);
    fldDmgStart(0, 0, 0);
    sdfFabs(0);
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    fldHitChkUnit((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    fldHitChkUnitDamage((sdfVector4_t){0});
    fldPlayerCalc360_8(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    fldPlayerOn();
    fldPlayerSdwOn();
    fldPlayerSvsOff();
    fldPlayerSvsOn();
    fldCameraCheckTurnType(0);
    fldPlayerCalc360_4(0);
    dds3FadeIn(0, 0, 0, 0);
    return 0;
}

// 0x10d68f0
s32 fldPlayerCalc_Nml_syukan(void) {
    dds3ObjectBaseGetModelHandle(0);
    mdlGetMotionMinorNum(0);
    fldPlayerSingleMotion(0, 0);
    dds3FadeIn2(0);
    mdlChkMotionEndForUnity_26964128(0, 0);
    fldPlayerMotionSe(0, 0);
    fldProcOnFlag(0);
    fldSePlay(0);
    dds3PadAct(0, 0, 0);
    fldStatusSet();
    fldCamMiwatasiChk();
    fldPlayerObjSetControlSvs(0, 0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    fldPlayerOff();
    dds3OnPoseSetFlag(0, 0);
    DDS3_PADCHECK_PRESS(0);
    DDS3_PADCHECK_TRIG(0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    dds3GetRotPoseSet(0);
    EulerAngleAxisY();
    SDF_VU0__LOADMATRIX(0);
    InversMatrix();
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    fldHitChkUnit((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfFabs(0);
    fldHitChkUnitDamage((sdfVector4_t){0});
    fldPlayerCalc360_8(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    fldPlayerCalc360_4(0);
    fldPlayerOn();
    dds3FadeIn(0, 0, 0, 0);
    fldDmgStart(0, 0, 0);
    return 0;
}

// 0x10cbe90
void fldPlayerCalc_WarpRun(void) {
    dds3ObjectBaseGetModelHandle(0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    dds3OnPoseSetFlag(0, 0);
    dds3GetRotPoseSet(0);
    EulerAngleAxisY();
    SDF_VU0__LOADMATRIX(0);
    InversMatrix();
    OOYRAD(0);
    sdfSin(0);
    sdfCos(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    fldHitChkUnit((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfFabs(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    mdlGetMotionMinorNum(0);
    fldPlayerSingleMotion(0, 0);
}

// 0x10d3c10
void fldPlayerCalc_WarpStart(void) {
  fldWmWarpMode = 1;
}

// 0x10d4430
s32 fldPlayerCalc_Wm2(void) {
    fldSePlay(0);
    dds3FadeIn(0, 0, 0, 0);
    dds3PadAct(0, 0, 0);
    fldStatusSet();
    dds3OnPoseSetFlag(0, 0);
    DDS3_PADCHECK_PRESS(0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADMATRIX(0);
    InversMatrix();
    fldPlayerCalc_Wm4();
    fldHitChkUnitVWM((sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfFabs(0);
    fldHitChkUnitDamage((sdfVector4_t){0});
    OOYRAD(0);
    FromEuler(0, 0, 0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
    evtBitCheck(0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3ObjectBaseOffFlag(0, 0);
    sdfAtan2(0, 0);
    OOYDEG(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
    sdfSin(0);
    sdfCos(0);
    return 0;
}

// 0x10d3d40
void fldPlayerCalc_Wm3(void) {
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
}

// 0x10d40a0
void fldPlayerCalc_Wm4(void) {
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
}

// 0x10da8d0
s32 fldPlayerChkAna(void) {
  struct fldPlayer_StaticFields *static_fields;

  else
  {
    static_fields = fldPlayer->static_fields;
    if (static_fields->gfldPlayerAnaCnt)
      return 1;
  }
  if (static_fields->gfldPlayerDamegeCnt)
    return 1;
  return static_fields->gfldPlayerHasiCnt != 0;
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
    fldPlayerFastSetForUnity();
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    fldHitChkUnit((sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3OffPoseSetFlag(0, 0);
    return 0;
}

// 0x10dae80
void fldPlayerFastSetForUnity(void) {
    SetCharacterType(0, 0);
    fldPlayerAnimation(0, 0);
}

// 0x10cad90
s32 fldPlayerMirChk(void) {
    dds3ObjectBaseCheckFlag(0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    fldPlayerMirAreaChk();
    dds3CheckPoseSetFlag(0, 0);
    dds3ObjectBaseOffFlag(0, 0);
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
    dds3ObjectBaseGetModelHandle(0);
    mdlGetMotionFrameForUnity(0);
    fldSePlay(0);
    sdfSqrt(0);
    dds3GetRandA(0);
    fldSeVol(0, 0);
}

// 0x10d3530
void fldPlayerObjSetControlSvs(dds3Basic_t **pObjectBasic, s32 svs, void *obj) {
  Il2CppObject *Component_object;

  dds3ObjectBaseSetControlBasicSvs(pObjectBasic, svs);
  else  if (!op_Inequality(obj, 0, 0))
  Component_object = GetComponent_object_(obj);
  if (svs)
  {
    SetTransparent(Component_object, (svs << 23) & 0xFF000000, 0.25, 0, 0);
  }
  else
  {
    RetTransparent(Component_object, 0);
  }
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
    setNoHokamOne();
    fldPlayerPosRot_RESTORE();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    OOYRAD(0);
    FromRotation(0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3GetRotPoseSet(0);
    EulerAngleAxisY();
    OOYDEG(0);
    dds3GetPosPoseSet(0);
    dds3OnPoseSetFlag(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    fldPlayerSdwOn();
    sdfFabs(0);
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

  p_handle = &fldUnitControl->handle;
  dds3ObjectBaseOffFlag(p_handle, 0x400u);
  dds3ObjectBaseOffFlag(p_handle, 0x200u);
}

// 0x10d3a30
void fldPlayerSdwOn(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  u32 v4;

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
    case 3:
      v6 = 6;
      if (!init)
    case 4:
      v6 = 3;
      if (!init)
    case 5:
      v6 = 2;
      if (!init)
    case 6:
      v6 = 4;
      if (!init)
    case 7:
      if (fldCheckBatStatusMotion())
        v6 = 50;
      else
        v6 = 0;
      if (!init)
    case 8:
      if (init)
    case 9:
      v6 = 52;
      if (!init)
    case 12:
      v6 = 56;
      if (!init)
    case 16:
      v6 = 51;
      if (!init)
    case 17:
      v6 = 50;
      if (!init)
    case 20:
      v6 = 60;
      if (!init)
    case 21:
      v6 = 61;
      if (!init)
    case 22:
      v6 = 62;
      if (!init)
    default:
      v6 = 0;
      if (init)
      if (fldPlayerAct != v6)
      {
        if (!fldCamNowEveCamera(0))
        {
          mdlSingleMotionForUnity(fldPlayerObj, StringLiteral_4572, v6, 1, 0);
          mdlSingleMotionForUnity(fldPlayerObjM, StringLiteral_4572, v6, 1, 0);
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

  p_handle = &fldUnitControl->handle;
  fldPlayerObjSetControlSvs(p_handle, 0, fldPlayerObj);
  dds3ObjectBaseOffFlag(p_handle, 0x800u);
}

// 0x10d3b10
void fldPlayerSvsOn(void) {
  struct fldUnitControl_t_o *fldUnitControl;
  dds3Basic_t_o **p_handle;

  p_handle = &fldUnitControl->handle;
  fldPlayerObjSetControlSvs(p_handle, 128, fldPlayerObj);
  dds3ObjectBaseOnFlag(p_handle, 0x800u, 0);
}

// 0x10dc470
void fldPlayer_Correction_Unity(void) {
    mdlGetMotionMinorNum(0);
    fldProcCampChk();
    fldElvChk();
}

// 0x10dc7d0
void fldPlayer_Enc_Correction_Unity(void) {
    encChk();
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

  Integer = GetInteger(fldPlayerAnm, StringLiteral_4572);
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
