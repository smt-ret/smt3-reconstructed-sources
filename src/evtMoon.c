#include "types.h"

typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtMoonProcessData_t evtMoonProcessData_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static sdfTexHandle_t *DeadMoonTmx;
static f32 gMoonCnt;
static s32 gMoonCngCnt;
static bool DeadMoonFlg;
static s32 evtDeadMoonDraw_total_cnt;
static s32 evtDeadMoonDraw_a_cnt;
static dds3ProcessID_t *moonprocess_id;
static f32 evtMoonProcess2_anmcnt_futo;
static f32 evtMoonProcess2_anmcnt_hoso;
static f32 evtMoonProcess2_anmcnt_hika;
static f32 evtMoonProcess2_anmcnt_bou;

void DrwSprite2D(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba, sdfTexHandle_t *th);
void DrwSprite2DF(f32 x, f32 y, f32 w, f32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba, sdfTexHandle_t *th);
void DrwSprite2D_17010048(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, u32 rgba, sdfTexHandle_t *th);
void SetMoonUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, s32 type);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOn(s32 no);
void evtDeadMoonDraw(evtMoonProcessData_t *data);
void evtMoonDrawSprite(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgb, sdfTexHandle_t *th, s32 ox, s32 oy, f32 cnt, f32 a0, f32 a1, f32 s0, f32 s1);
s32 fldChkVortex(void);
void fldEsutoMaClearMsg(void);
void fldLightMaClearMsg(void);
void fldRiberaMaClearMsg(void);
void fldRifutoMaClearMsg(void);
s32 fmProcessChk(void);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
f32 sdfSin(f32 aRadius);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);

// 0x10ee8b0
void evtDeadMoonDraw(evtMoonProcessData_t *data) {
  f32 gMoonCnt;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  s32 ox;
  s32 oy;
  s32 evtDeadMoonDraw_a_cnt;
  f32 v20;
  f32 v21;
  sdfTexHandle_t_o *th;
  f32 v23;
  s32 v24;
  s32 v27;
  f32 v28;
  f32 v29;
  sdfTexHandle_t_o *MoonTmx3;
  evtMoon_c *v32;
  s32 evtDeadMoonDraw_total_cnt;
  s16 v34;
  s32 v35;
  s32 v36;
  f32 v37;

  if (DeadMoonFlg)
  {
    SetMoonUI(kernelObject, 1, 0, 0, 9);
    if ((DDS3_GBWK->Moon->Stat & 2) != 0)
    {
      v9 = gMoonCnt * 0.0;
      v10 = (1.0 - gMoonCnt) * 0.0;
      v11 = (gMoonCnt * 0.0) + ((1.0 - gMoonCnt) * -250.0);
      v12 = v9 + v10;
      ox = v11;
      oy = v12;
      rsetOtOfs(71);
      rsetAlpha(0);
      rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
      DrwSprite2D_17010048(ox + 12, oy + 14, 108, 54, 1, 1, 108, 54, 0x80808080, DeadMoonTmx);
      rsetAlpha(1);
      if (evtDeadMoonDraw_a_cnt <= 23)
      {
        v20 = (evtDeadMoonDraw_a_cnt * -60.0) / 24.0;
        v21 = 80.0;
      }
      else
      {
        v20 = ((evtDeadMoonDraw_a_cnt - 24) * 60.0) / 24.0;
        v21 = 20.0;
      }
      th = data->MoonTmx3;
      v23 = fmaxf(fminf(v20 + v21, 100.0), 0.0);
      v24 = oy + 16;
      evtMoonDrawSprite(ox + 36, oy + 16, 33, 31, 59, 21, 33, 31, 8421504, th, ox, oy, 0.0, v23, v23, 100.0, 100.0);
      v27 = evtDeadMoonDraw_a_cnt;
      if (v27 <= 23)
      {
        v28 = (v27 * 60.0) / 24.0;
      }
      else
      {
        v28 = (((v27 - 24) * 60.0) / -24.0) + 60.0;
      }
      v29 = fmaxf(fminf(v28, 100.0), 0.0);
      MoonTmx3 = data->MoonTmx3;
      evtMoonDrawSprite(ox + 38, v24, 35, 31, 93, 21, 35, 31, 8421504, MoonTmx3, ox, oy, 0.0, v29, v29, 100.0, 100.0);
      if (evtDeadMoonDraw_total_cnt < 18)
      {
        v37 = fmaxf(fminf(0.0, 100.0), 0.0);
        {
LABEL_65:
          evtMoonDrawSprite(ox + 38, v24, 37, 29, 110, 1, 17, 14, 8421504, DeadMoonTmx, ox, oy, 0.0, v37, v37, 100.0, 100.0);
          rsetAlpha(0);
          ++evtDeadMoonDraw_total_cnt;
          evtDeadMoonDraw_total_cnt %= 74;
          ++evtDeadMoonDraw_a_cnt;
          evtDeadMoonDraw_a_cnt %= 48;
          return;
        }
LABEL_55:
        goto LABEL_65;
      }
      if ((v34 & 0x200) != 0)
      {
        v35 = v34 & 0x200;
        if (evtDeadMoonDraw_total_cnt <= 47)
          goto LABEL_50;
      }
      else
      {
        v35 = 0;
        if (evtDeadMoonDraw_total_cnt <= 47)
        {
LABEL_50:
          v36 = evtDeadMoonDraw_total_cnt - 18;
          goto LABEL_64;
        }
      }
      v36 = 74 - evtDeadMoonDraw_total_cnt;
LABEL_64:
      v37 = fmaxf(fminf((v36 * 80.0) / 30.0, 100.0), 0.0);
      if ((v32->_2.bitflags2 & 2) == 0)
        goto LABEL_65;
      goto LABEL_55;
    }
  }
}

// 0x10ee7c0
void evtDeadMoonFree(void) {
  sdfTexHandle_t_o *DeadMoonTmx;

  if (DeadMoonTmx)
  {
    sdfTexFreeDelayed(DeadMoonTmx);
  }
  DeadMoonTmx = 0;
  DeadMoonFlg = 0;
}

// 0x10ee750
void evtDeadMoonInit(void) {
  DeadMoonFlg = 1;
}

// 0x10ef0f0
void evtDisableMoonCalc(void) {
  struct evtMoon_t_o *Moon;

  Moon = DDS3_GBWK->Moon;
  Moon->Stat &= ~1u;
}

// 0x10ef220
void evtDisableMoonDraw(void) {
  struct evtMoon_t_o *Moon;

  Moon = DDS3_GBWK->Moon;
  Moon->Stat &= ~2u;
  gMoonCnt = 0.0;
}

// 0x10ef350
void evtDisableMoonDraw2(void) {
  struct evtMoon_t_o *Moon;

  Moon = DDS3_GBWK->Moon;
  Moon->Stat &= ~2u;
}

// 0x10ef070
void evtEnableMoonCalc(void) {
  struct evtMoon_t_o *Moon;

  Moon = DDS3_GBWK->Moon;
  Moon->Stat |= 1u;
}

// 0x10ef170
void evtEnableMoonDraw(void) {
  struct evtMoon_t_o *Moon;

  Moon = DDS3_GBWK->Moon;
  Moon->Stat |= 2u;
  gMoonCnt = 1.0;
}

// 0x10ef2d0
void evtEnableMoonDraw2(void) {
  struct evtMoon_t_o *Moon;

  Moon = DDS3_GBWK->Moon;
  Moon->Stat |= 2u;
}

// 0x10f1530
void evtFreeMoonProcess(void) {
  else if (!moonprocess_id)
  {
    return;
  }
  dds3KillProcess(&moonprocess_id, 1);
}

// 0x10eeed0
s32 evtGetAgeOfMoon(void) {
  if (DDS3_GBWK->Moon->Age <= 8)
    return DDS3_GBWK->Moon->Age;
  else
    return 8 - (DDS3_GBWK->Moon->Age & 7);
}

// 0x10eef60
s32 evtGetAgeOfMoon16(void) {
  return DDS3_GBWK->Moon->Age;
}

// 0x10f1260
void evtInitMoonProcess(void) {
  u64 *v2;
  u64 *v3;
  dds3ProcessID_t_o *started;
  struct evtMoon_t_o *Moon;
  struct evtMoon_t_o *v10;

  else if (moonprocess_id)
  {
    return;
  }
  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_evtMoon_evtMoonProcess1__);
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_evtMoon_evtMoonShutdown__);
  started = dds3StartProcess("moon", 0x2B0Bu, 1, 1, v2, 0, v3, 0, 0, 0);
  moonprocess_id = started;
  Moon = DDS3_GBWK->Moon;
  Moon->Stat |= 1u;
  v10 = DDS3_GBWK->Moon;
  v10->Stat &= ~2u;
  gMoonCnt = 0.0;
  DDS3_GBWK->Moon->Age = 0;
  DDS3_GBWK->Moon->MoveCnt = 0.0;
  DDS3_GBWK->Moon->TakaraCnt = 0;
  DDS3_GBWK->fldSave->AnahoriCnt = 0;
}

// 0x10f0b40
void evtMoonAddMove(f32 leng) {
  struct dds3GlobalWork_StaticFields **p_static_fields;
  struct evtMoon_t_o *Moon;
  struct evtMoon_t_o *v7;
  s32 Age;
  s32 v9;
  s32 v10;
  u32 v11;
  s32 v13;
  struct evtMoon_t_o *v14;
  struct evtMoon_t_o *v15;
  struct dds3GlobalWork_StaticFields **v18;
  struct fldSave_t_o *fldSave;
  s32 AnahoriCnt;
  u64 *v22;
  bool v24;
  s32 v28;

  Moon = DDS3_GBWK->Moon;
  if ((Moon->Stat & 1) != 0)
  {
    Moon->MoveCnt = Moon->MoveCnt + leng;
    v7 = DDS3_GBWK->Moon;
    if (v7->MoveCnt > 4500.0)
    {
      v7->MoveCnt = 0.0;
      Age = (*p_static_fields)->DDS3_GBWK->Moon->Age;
      v9 = Age + 1;
      v10 = Age + 16;
      if (Age + 1 >= 0)
        v10 = Age + 1;
      v11 = v10 & 0xFFFFFFF0;
      v13 = v9 - v11;
      DDS3_GBWK->Moon->Age = v13;
      DDS3_GBWK->Moon->MoveCnt = 0.0;
      gMoonCngCnt = 30;
      if (!DDS3_GBWK->Moon->Age)
      {
        fldEsutoMaClearMsg();
        fldRiberaMaClearMsg();
        fldRifutoMaClearMsg();
        fldLightMaClearMsg();
      }
      v14 = DDS3_GBWK->Moon;
      ++v14->TakaraCnt;
      v15 = DDS3_GBWK->Moon;
      if (v15->TakaraCnt >= 13)
      {
        v15->TakaraCnt = 0;
      }
      if (evtBitCheck(1282))
      {
        fldSave = DDS3_GBWK->fldSave;
        AnahoriCnt = fldSave->AnahoriCnt;
        if (AnahoriCnt <= 239)
        {
          fldSave->AnahoriCnt = AnahoriCnt + 1;
          v28 = (*v18)->DDS3_GBWK->fldSave->AnahoriCnt;
          v22 = sub_8D3950(s32, &v28);
          Write_2930400("moon anahori:{0:D}\n", v22);
        }
        v24 = evtBitCheck(1284);
        if (v24)
        {
          if (DDS3_GBWK->fldSave->AnahoriCnt == 48)
          {
            evtBitOn(1285);
          }
          if (DDS3_GBWK->fldSave->AnahoriCnt != 112)
            return;
LABEL_79:
          evtBitOn(1286);
          return;
        }
        if (DDS3_GBWK->fldSave->AnahoriCnt == 48)
        {
          evtBitOn(1285);
        }
        if (DDS3_GBWK->fldSave->AnahoriCnt == 160)
          goto LABEL_79;
      }
      else if (!evtBitCheck(1283))
      {
        DDS3_GBWK->fldSave->AnahoriCnt = 0;
      }
    }
  }
}

// 0x10ee580
void evtMoonDrawSprite(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgb, sdfTexHandle_t *th, s32 ox, s32 oy, f32 cnt, f32 a0, f32 a1, f32 s0, f32 s1) {
  f32 v29;
  f32 v30;
  f32 v31;
  s32 v32;
  s64 v33;
  s32 v34;
  f32 v35;
  f32 v36;

  v29 = (sdfSin(cnt) * 0.5) + 0.5;
  v30 = v29 * a0;
  v31 = w;
  v32 = ((v29 * s0) + ((1.0 - v29) * s1));
  v33 = 1374389535LL * ((v30 + ((1.0 - v29) * a1)) << 7);
  v34 = (v33 >> 37) + (v33 >> 63);
  v35 = (h * v32) / 100.0;
  v36 = (v31 * v32) / 100.0;
  DrwSprite2DF(
    (((v31 - v36) * 0.5) + ox) + x,
    (((h - v35) * 0.5) + oy) + y,
    v36,
    v35,
    u,
    v,
    uw,
    vh,
    rgb | (v34 << 24),
    th,
    0);
}

// 0x10f1040
void *evtMoonProcess1(dds3ProcessID_t *id) {
  evtMoonProcessData_t_o *v2;
  u64 *v4;
  dds3ProcessID_t_o *ida;

  ida = id;
  v2 = Allocate(evtMoonProcessData_t);
  evtMoonProcessData_t___ctor(v2);
  v2->MoonTmx5 = 0;
  v2->MoonTmx6 = 0;
  v2->MoonTmx3 = 0;
  v2->MoonTmx4 = 0;
  v2->MoonTmx1 = 0;
  v2->MoonTmx2 = 0;
  dds3SetProcessData(&ida, v2);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_evtMoon_evtMoonProcess2__);
  return v4;
}

// 0x10ef3d0
dds3ProcessFunc_t *evtMoonProcess2(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  evtMoonProcessData_t_c *v6;
  evtMoonProcessData_t_o *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  struct evtMoon_t_o *Moon;
  evtMoon_c *v14;
  f32 v16;
  s16 v18;
  s32 v19;
  f32 v22;
  f32 gMoonCnt;
  f32 v27;
  s32 v28;
  s32 v29;
  s32 v32;
  s32 v33;
  sdfTexHandle_t_o *MoonTmx2;
  sdfTexHandle_t_o *v41;
  sdfTexHandle_t_o *v43;
  s64 Age;
  s32 v47;
  s64 v48;
  s32 v49;
  s32 v50;
  sdfTexHandle_t_o *MoonTmx3;
  s32 v52;
  sdfTexHandle_t_o *MoonTmx5;
  f32 evtMoonProcess2_anmcnt_bou;
  sdfTexHandle_t_o *MoonTmx4;
  f32 v59;
  s32 v60;
  s32 v61;
  s32 v62;
  s32 v63;
  s32 v64;
  s32 v65;
  s32 v66;
  sdfTexHandle_t_o *v68;
  sdfTexHandle_t_o *v70;
  sdfTexHandle_t_o *v73;
  sdfTexHandle_t_o *MoonTmx6;
  s32 v76;
  sdfTexHandle_t_o *v78;
  f32 evtMoonProcess2_anmcnt_hika;
  s32 v80;
  f32 v82;
  f32 v83;
  s32 v84;
  sdfTexHandle_t_o *v86;
  f32 v87;
  f32 v88;
  s32 v89;
  s32 v90;
  sdfTexHandle_t_o *v92;
  sdfTexHandle_t_o *v94;
  sdfTexHandle_t_o *v96;
  sdfTexHandle_t_o *v98;
  sdfTexHandle_t_o *v100;
  sdfTexHandle_t_o *MoonTmx1;
  sdfTexHandle_t_o *v104;
  s32 gMoonCngCnt;
  evtMoon_c *v111;
  f32 v112;
  s32 v113;
  f32 v114;
  f32 v115;
  sdfTexHandle_t_o *v116;
  s32 v119;
  sdfTexHandle_t_o *v120;
  sdfTexHandle_t_o *v121;
  s32 v124;
  sdfTexHandle_t_o *v125;
  s32 methoda;
  sdfTexHandle_t_o *tha;
  sdfTexHandle_t_o *th;
  s32 ox;
  s32 oy;
  s32 x;
  s32 rgba;
  dds3ProcessID_t_o *v139[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  else if (fmProcessChk())
  {
    return 0;
  }
  if (fldChkVortex())
  {
    ProcessData = dds3GetProcessData(&ida);
    v7 = ProcessData;
    if (ProcessData)
    {
      klass = ProcessData->klass;
      if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtMoonProcessData_t)
      {
        sub_8FC2C0(klass->_1.element_class, evtMoonProcessData_t, v139);
        if ((v139[0] & 1) != 0)
          v10 = v139[2];
        else
          v10 = v139 + 1;
        v11 = sub_8C4940(v10);
      }
    }
    Moon = DDS3_GBWK->Moon;
    if ((Moon->Stat & 2) != 0)
    {
      if (gMoonCnt < 1.0)
      {
        gMoonCnt = gMoonCnt + 0.1;
        if (gMoonCnt > 1.0)
        {
          gMoonCnt = 1.0;
        }
      }
    }
    else
    {
      v16 = gMoonCnt;
      if (v16 > 0.0)
      {
        gMoonCnt = v16 + -0.1;
        if (gMoonCnt < 0.0)
        {
          gMoonCnt = 0.0;
          v18 = *&v14->_2.bitflags1;
          if ((v18 & 0x200) != 0)
          {
LABEL_38:
            v19 = v18 & 0x200;
            if (!DeadMoonFlg)
              goto LABEL_41;
LABEL_66:
            evtDeadMoonDraw(v7, v6);
            return 0;
          }
LABEL_65:
          v19 = 0;
          if (!DeadMoonFlg)
          {
LABEL_41:
            v22 = gMoonCnt;
            if ((DDS3_GBWK->Moon->Stat & 2) != 0)
            {
              v27 = 0.0;
              v28 = ((v22 * 0.0) + ((1.0 - v22) * -250.0));
              v29 = ((v22 * 0.0) + ((1.0 - v22) * 0.0));
              rsetOtOfs(71);
              rsetAlpha(0);
              rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
              DrwSprite2D_17010048(v28 + 16, v29 + 21, 97, 43, 1, 1, 97, 43, 0x80808080, v7->MoonTmx1);
              v32 = DDS3_GBWK->Moon->Age - 1;
              if (v32 > 0xE)
                v33 = 0;
              else
                v33 = dword_33CC1E8[v32];
              SetMoonUI(kernelObject, 1, v28, v29, v33);
              rsetAlpha(1);
              switch (DDS3_GBWK->Moon->Age)
              {
                case 5:
                case 0xB:
                  MoonTmx2 = v7->MoonTmx2;
                  evtMoonDrawSprite(
                    15,
                    4,
                    58,
                    62,
                    62,
                    1,
                    58,
                    62,
                    8421504,
                    MoonTmx2,
                    ((v22 * 0.0) + ((1.0 - v22) * -250.0)),
                    ((v22 * 0.0) + ((1.0 - v22) * 0.0)),
                    evtMoonProcess2_anmcnt_hoso,
                    20.0,
                    10.0,
                    100.0,
                    100.0);
                  break;
                case 6:
                case 0xA:
                  v41 = v7->MoonTmx2;
                  evtMoonDrawSprite(
                    15,
                    4,
                    58,
                    62,
                    62,
                    1,
                    58,
                    62,
                    8421504,
                    v41,
                    ((v22 * 0.0) + ((1.0 - v22) * -250.0)),
                    ((v22 * 0.0) + ((1.0 - v22) * 0.0)),
                    evtMoonProcess2_anmcnt_hoso,
                    40.0,
                    20.0,
                    100.0,
                    100.0);
                  break;
                case 7:
                case 9:
                  v43 = v7->MoonTmx2;
                  evtMoonDrawSprite(
                    15,
                    4,
                    58,
                    62,
                    62,
                    1,
                    58,
                    62,
                    8421504,
                    v43,
                    ((v22 * 0.0) + ((1.0 - v22) * -250.0)),
                    ((v22 * 0.0) + ((1.0 - v22) * 0.0)),
                    evtMoonProcess2_anmcnt_hoso,
                    50.0,
                    20.0,
                    100.0,
                    100.0);
                  break;
                case 8:
                  v73 = v7->MoonTmx2;
                  evtMoonDrawSprite(15, 4, 58, 62, 62, 1, 58, 62, 8421504, v73, v28, v29, evtMoonProcess2_anmcnt_hoso, 30.0, 100.0, 100.0, 100.0);
                  break;
                default:
                  break;
              }
              rsetAlpha(0);
              Age = DDS3_GBWK->Moon->Age;
              v47 = v29 + 21;
              if (Age > 0xF)
              {
                v50 = 8421504;
                rgba = 0;
                v49 = 8421504;
              }
              else
              {
                v48 = 4 * Age;
                rgba = *(&unk_33CC224 + v48);
                v49 = *(&unk_33CC264 + v48);
                v50 = *(&unk_33CC2A4 + v48);
              }
              MoonTmx3 = v7->MoonTmx3;
              tha = MoonTmx3;
              v52 = v29 + 21;
              DrwSprite2D(v28 + 30, v47, 28, 28, 30, 21, 28, 28, v50, tha);
              x = v28 + 30;
              DrwSprite2D(v28 + 30, v47, 28, 28, 99, 30, 28, 28, v49, v7->MoonTmx1);
              rsetAlpha(1);
              switch (DDS3_GBWK->Moon->Age)
              {
                case 5:
                case 0xB:
                  MoonTmx5 = v7->MoonTmx5;
                  evtMoonDrawSprite(29, 20, 31, 32, 90, 1, 31, 32, 8421504, MoonTmx5, v28, v29, evtMoonProcess2_anmcnt_bou, 35.0, 100.0, 100.0, 100.0);
                  MoonTmx4 = v7->MoonTmx4;
                  v59 = 35.0;
                  v60 = 82;
                  v61 = 29;
                  v62 = 20;
                  v63 = 31;
                  v64 = 32;
                  v65 = 31;
                  v66 = 32;
                  goto LABEL_129;
                case 6:
                case 0xA:
                  v68 = v7->MoonTmx4;
                  evtMoonDrawSprite(26, 18, 39, 36, 41, 1, 39, 36, 8421504, v68, v28, v29, evtMoonProcess2_anmcnt_bou, 35.0, 100.0, 100.0, 100.0);
                  evtMoonDrawSprite(26, 18, 39, 36, 1, 1, 39, 36, 8421504, v7->MoonTmx4, v28, v29, evtMoonProcess2_anmcnt_bou, 100.0, 35.0, 100.0, 100.0);
                  goto LABEL_140;
                case 7:
                case 9:
                  v70 = v7->MoonTmx5;
                  evtMoonDrawSprite(24, 15, 43, 42, 45, 1, 43, 42, 8421504, v70, v28, v29, evtMoonProcess2_anmcnt_bou, 40.0, 100.0, 100.0, 100.0);
                  MoonTmx4 = v7->MoonTmx5;
                  v59 = 40.0;
                  v61 = 24;
                  v62 = 15;
                  v63 = 43;
                  v64 = 42;
                  v60 = 1;
                  v65 = 43;
                  v66 = 42;
LABEL_129:
                  evtMoonDrawSprite(v61, v62, v63, v64, v60, 1, v65, v66, 8421504, MoonTmx4, v28, v29, evtMoonProcess2_anmcnt_bou, 100.0, v59, 100.0, 100.0);
                    goto LABEL_144;
                  goto LABEL_142;
                case 8:
                  MoonTmx6 = v7->MoonTmx6;
                  {
                    v76 = ((v22 * 0.0) + ((1.0 - v22) * -250.0));
                  }
                  else
                  {
                    v76 = ((v22 * 0.0) + ((1.0 - v22) * -250.0));
                  }
                  evtMoonDrawSprite(18, 10, 54, 51, 57, 1, 54, 51, 8421504, MoonTmx6, v76, v29, evtMoonProcess2_anmcnt_bou, 35.0, 100.0, 100.0, 100.0);
                  evtMoonDrawSprite(18, 10, 54, 51, 1, 1, 54, 51, 8421504, v7->MoonTmx6, v76, v29, evtMoonProcess2_anmcnt_bou, 100.0, 35.0, 100.0, 100.0);
                  v28 = v76;
LABEL_140:
                  v52 = v29 + 21;
                  break;
                default:
                  break;
              }
              {
LABEL_142:
              }
LABEL_144:
              switch (DDS3_GBWK->Moon->Age)
              {
                case 0:
                  MoonTmx1 = v7->MoonTmx1;
                  v87 = 100.0;
                  oy = ((v22 * 0.0) + ((1.0 - v22) * 0.0));
                  ox = v28;
                  th = MoonTmx1;
                  methoda = 4866303;
                  v83 = 70.0;
                  v84 = 99;
                  v88 = 70.0;
                  v82 = 70.0;
                  goto LABEL_159;
                case 1:
                case 0xF:
                  v78 = v7->MoonTmx1;
                  v80 = 6316208;
                  goto LABEL_153;
                case 2:
                case 0xE:
                  v78 = v7->MoonTmx1;
                  v80 = 7368864;
LABEL_153:
                  v82 = 60.0;
                  v83 = 75.0;
                  v84 = 99;
                  oy = ((v22 * 0.0) + ((1.0 - v22) * 0.0));
                  ox = v28;
                  th = v78;
                  methoda = v80;
                  goto LABEL_158;
                case 3:
                case 0xD:
                  v86 = v7->MoonTmx1;
                  v83 = 75.0;
                  v82 = 70.0;
                  oy = ((v22 * 0.0) + ((1.0 - v22) * 0.0));
                  ox = v28;
                  th = v86;
                  methoda = 8421520;
                  v84 = 99;
LABEL_158:
                  v87 = 90.0;
                  v88 = 75.0;
LABEL_159:
                  v89 = 28;
                  v90 = 28;
                  goto LABEL_186;
                case 4:
                case 0xC:
                  v92 = v7->MoonTmx1;
                  evtMoonDrawSprite(15, 4, 58, 62, 99, 1, 28, 28, 8421504, v92, v28, v29, evtMoonProcess2_anmcnt_hika, 70.0, 70.0, 70.0, 90.0);
                  v83 = 20.0;
                  v88 = 20.0;
                  evtMoonProcess2_anmcnt_hika = evtMoonProcess2_anmcnt_futo;
                  th = v7->MoonTmx2;
                  v87 = 75.0;
                  v82 = 60.0;
                  goto LABEL_185;
                case 5:
                case 0xB:
                  v94 = v7->MoonTmx1;
                  evtMoonDrawSprite(15, 4, 58, 62, 99, 1, 28, 28, 8421504, v94, v28, v29, evtMoonProcess2_anmcnt_hika, 55.0, 65.0, 75.0, 100.0);
                  v96 = v7->MoonTmx2;
                  v82 = 50.0;
                  v87 = 65.0;
                  goto LABEL_172;
                case 6:
                case 0xA:
                  v98 = v7->MoonTmx1;
                  evtMoonDrawSprite(15, 4, 58, 62, 99, 1, 28, 28, 8421504, v98, v28, v29, evtMoonProcess2_anmcnt_hika, 70.0, 70.0, 75.0, 100.0);
                  v96 = v7->MoonTmx2;
                  v82 = 65.0;
                  v87 = 85.0;
LABEL_172:
                  evtMoonProcess2_anmcnt_hika = evtMoonProcess2_anmcnt_futo;
                  th = v96;
                  v88 = 60.0;
                  v83 = 40.0;
                  goto LABEL_185;
                case 7:
                case 9:
                  v100 = v7->MoonTmx1;
                  evtMoonDrawSprite(15, 4, 58, 62, 99, 1, 28, 28, 8421504, v100, v28, v29, evtMoonProcess2_anmcnt_hika, 80.0, 80.0, 110.0, 80.0);
                  v87 = 100.0;
                  v82 = 80.0;
                  evtMoonProcess2_anmcnt_hika = evtMoonProcess2_anmcnt_futo;
                  th = v7->MoonTmx2;
                  v88 = 70.0;
                  v83 = 50.0;
                  goto LABEL_185;
                case 8:
                  v104 = v7->MoonTmx1;
                  evtMoonDrawSprite(15, 4, 58, 62, 99, 1, 28, 28, 8421504, v104, v28, v29, evtMoonProcess2_anmcnt_hika, 100.0, 100.0, 100.0, 130.0);
                  evtMoonDrawSprite(15, 4, 58, 62, 99, 1, 28, 28, 8421504, v7->MoonTmx1, v28, v29, evtMoonProcess2_anmcnt_hika, 40.0, 40.0, 100.0, 130.0);
                  v82 = 100.0;
                  v87 = 130.0;
                  evtMoonProcess2_anmcnt_hika = evtMoonProcess2_anmcnt_futo;
                  th = v7->MoonTmx2;
                  v88 = 80.0;
                  v83 = 60.0;
LABEL_185:
                  oy = ((v22 * 0.0) + ((1.0 - v22) * 0.0));
                  ox = v28;
                  methoda = 8421504;
                  v84 = 1;
                  v89 = 58;
                  v90 = 62;
LABEL_186:
                  evtMoonDrawSprite(15, 4, 58, 62, v84, 1, v89, v90, methoda, th, ox, oy, evtMoonProcess2_anmcnt_hika, v83, v88, v82, v87);
                  break;
                default:
                  break;
              }
              rsetAlpha(0);
              if (gMoonCngCnt >= 1)
              {
                gMoonCngCnt = gMoonCngCnt - 1;
                rsetAlpha(1);
                switch (DDS3_GBWK->Moon->Age)
                {
                  case 0:
                  case 1:
                  case 2:
                  case 3:
                  case 0xD:
                  case 0xE:
                  case 0xF:
                    v112 = gMoonCngCnt * 25.0;
                    v27 = 100.0;
                    goto LABEL_216;
                  case 4:
                  case 0xC:
                    v27 = 110.0;
                    v112 = gMoonCngCnt * 35.0;
LABEL_216:
                    v115 = v112 / 30.0;
                    v116 = v7->MoonTmx1;
                    if ((v111->_2.bitflags2 & 2) == 0)
                      goto LABEL_231;
                    goto LABEL_229;
                  case 5:
                  case 0xB:
                    v113 = gMoonCngCnt;
                    v114 = 60.0;
                    goto LABEL_228;
                  case 6:
                  case 7:
                  case 9:
                  case 0xA:
                    v113 = gMoonCngCnt;
                    v114 = 80.0;
                    goto LABEL_228;
                  case 8:
                    v113 = gMoonCngCnt;
                    v114 = 100.0;
LABEL_228:
                    v115 = (v113 * v114) / 30.0;
                    v27 = 120.0;
                    v116 = v7->MoonTmx1;
                    if ((v111->_2.bitflags2 & 2) != 0)
                      goto LABEL_229;
                    goto LABEL_231;
                  default:
                    v115 = 0.0;
                    v116 = v7->MoonTmx1;
                      goto LABEL_231;
LABEL_229:
LABEL_231:
                    evtMoonDrawSprite(15, 4, 58, 62, 99, 1, 28, 28, 0xFFFFFF, v116, v28, v29, 0.0, v115, v115, v27, v27);
                    rsetAlpha(0);
                    break;
                }
              }
              {
                v119 = x;
              }
              else
              {
                v119 = x;
              }
              if (!DDS3_GBWK->Moon->Age)
              {
                v120 = v7->MoonTmx3;
                DrwSprite2D(v119, v52, 28, 28, 1, 21, 28, 28, rgba, v120);
              }
              v121 = v7->MoonTmx3;
              DrwSprite2D(v119, v52, 28, 28, 1, 21, 28, 28, rgba | 0x808080, v121);
              v124 = DDS3_GBWK->Moon->Age;
              if (v124 == 15 || v124 == 1)
              {
                v125 = v7->MoonTmx1;
                DrwSprite2D(v119, v52, 28, 28, 99, 30, 28, 28, 645955712, v125);
              }
              evtMoonProcess2_anmcnt_futo = evtMoonProcess2_anmcnt_futo + 0.1;
              evtMoonProcess2_anmcnt_hoso = evtMoonProcess2_anmcnt_hoso + 0.3;
              evtMoonProcess2_anmcnt_hika = evtMoonProcess2_anmcnt_hika + 0.1;
              evtMoonProcess2_anmcnt_bou = evtMoonProcess2_anmcnt_bou + 0.2;
            }
            else
            {
              SetMoonUI(kernelObject, 0, 0, 0, 0);
            }
            return 0;
          }
          goto LABEL_66;
        }
      }
    }
    v18 = *&v14->_2.bitflags1;
    if ((v18 & 0x200) != 0)
      goto LABEL_38;
    goto LABEL_65;
  }
  return 0;
}

// 0x10f1110
void *evtMoonShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3ProcessID_t_o *v10[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_13;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtMoonProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtMoonProcessData_t, v10);
    if ((v10[0] & 1) != 0)
      v6 = v10[2];
    else
      v6 = v10 + 1;
    v7 = sub_8C4940(v6);
  }
LABEL_13:
  moonprocess_id = 0;
  return 0;
}

// 0x10eefd0
void evtSetAgeOfMoon(s32 age) {
  s32 v4;

  v4 = age + 15;
  if (age >= 0)
    v4 = age;
  DDS3_GBWK->Moon->Age = age - (v4 & 0xFFFFFFF0);
  DDS3_GBWK->Moon->MoveCnt = 0.0;
}
