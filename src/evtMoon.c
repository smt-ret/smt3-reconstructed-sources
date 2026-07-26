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
          evtMoonDrawSprite(ox + 38, v24, 37, 29, 110, 1, 17, 14, 8421504, DeadMoonTmx, ox, oy, 0.0, v37, v37, 100.0, 100.0);
          rsetAlpha(0);
          ++evtDeadMoonDraw_total_cnt;
          evtDeadMoonDraw_total_cnt %= 74;
          ++evtDeadMoonDraw_a_cnt;
          evtDeadMoonDraw_a_cnt %= 48;
          return;
        }
      }
      if ((v34 & 0x200) != 0)
      {
        v35 = v34 & 0x200;
        if (evtDeadMoonDraw_total_cnt <= 47)
      }
      else
      {
        v35 = 0;
        if (evtDeadMoonDraw_total_cnt <= 47)
        {
          v36 = evtDeadMoonDraw_total_cnt - 18;
        }
      }
      v36 = 74 - evtDeadMoonDraw_total_cnt;
      v37 = fmaxf(fminf((v36 * 80.0) / 30.0, 100.0), 0.0);
      if ((v32->_2.bitflags2 & 2) == 0)
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
  started = dds3StartProcess(StringLiteral_14710, 0x2B0Bu, 1, 1, v2, 0, v3, 0, 0, 0);
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
    fldEsutoMaClearMsg();
    fldRiberaMaClearMsg();
    fldRifutoMaClearMsg();
    fldLightMaClearMsg();
    evtBitCheck(0);
    evtBitOn(0);
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
    fmProcessChk();
    fldChkVortex();
    dds3GetProcessData(0);
    evtDeadMoonDraw(0);
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    DrwSprite2D_17010048(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SetMoonUI(0, 0, 0, 0, 0);
    evtMoonDrawSprite(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    DrwSprite2D(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    return 0;
}

// 0x10f1110
void *evtMoonShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
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
