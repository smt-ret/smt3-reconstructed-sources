#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static u16 skyanime;
static u16 skyanow;
static u16 skyamax;
static s16 skyabase;
static s16 skyatarget;
static s16 skyabase_par;
static s16 skyatarget_par;
static s32 fldbokasi;

void Get_OW_SkyAlp(s32 idx, s32 alp, s32 *to_alp, s32 *to_par);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void evtUpdateSkyAlpha(void);
void fldSkyDrawFilter(void);
s32 fldSkyGetAlphaOfs(void);
s32 fldSkyGetFilterNowIdx(void);
s32 fldSkyGet_RgbPar(void);
void fldSkySetAlpha(s32 alp);
void fldSkySetAlphaOfs(s32 alp);
void fldSkySetFilter(s32 idx, s32 mode, s32 hokan);
void fldSkySetFilterAnime(s32 type);
void fldSkySet_RgbPar(s32 par);

// 0x194ec70
s32 evtCheckSkyAlphaAnime(void) {
  return skyanime;
}

// 0x194f000
void evtExitSky(void) {
  u64 *v1;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  id = dds3SearchProcessName("sky");
  if (id)
  {
    dds3KillProcess(&id, 1);
  }
}

// 0x194f0d0
dds3ProcessID_t *evtInitSky(void) {
  u64 *v1;
  u64 *v3;
  u64 *v4;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  fldSkySetFilterAnime(0);
  fldSkySetAlpha(0);
  fldSkySetAlphaOfs(0);
  fldSkySetFilter(18, 1, 0);
  fldSkySet_RgbPar(0);
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_evtSky_evtSkyProcess1__);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_evtSky_evtSkyShutdown__);
  return dds3StartProcess("sky", 0x2B0Eu, 1, 1, v3, 0, v4, 0, 0, 0);
}

// 0x194e950
void evtSetBokasi(s32 sw) {
  fldbokasi = sw;
}

// 0x194e9c0
void evtSetSkyAlpha(s32 frame, s32 a) {
  s32 RgbPar;
  s32 FilterNowIdx;
  s32 v8;
  s32 AlphaOfs;
  s16 v11;
  s16 v14;
  s16 v17;
  s16 v19;
  s32 to_par;
  s32 to_alp;

  to_alp = 0;
  to_par = 0;
  RgbPar = fldSkyGet_RgbPar();
  FilterNowIdx = fldSkyGetFilterNowIdx();
  Get_OW_SkyAlp(FilterNowIdx, a, &to_alp, &to_par);
  v8 = to_alp;
  fldSkySet_RgbPar(to_par);
  AlphaOfs = fldSkyGetAlphaOfs();
  if (AlphaOfs != v8)
  {
    if (!frame)
    {
      fldSkySetAlphaOfs(v8);
      else
      {
        v19 = 0;
      }
      goto LABEL_47;
    }
    v11 = AlphaOfs;
    skyanow = 0;
    skyamax = frame;
    skyabase = v11;
    skyatarget = v8;
    v14 = to_par;
    if (!(to_par | RgbPar) || RgbPar == 100 && to_par == 0)
    {
      skyabase_par = 0;
      v17 = 0;
    }
    else
    {
      skyabase_par = RgbPar;
      skyatarget_par = v14;
      if (!skyabase_par)
      {
        skyabase_par = 100;
      }
      if (skyatarget_par)
        goto LABEL_43;
      v17 = 100;
    }
    skyatarget_par = v17;
LABEL_43:
    v19 = 1;
LABEL_47:
    skyanime = v19;
  }
}

// 0x194eec0
dds3ProcessFunc_t *evtSkyProcess1(dds3ProcessID_t *id) {
  evtUpdateSkyAlpha();
  fldSkyDrawFilter();
  return 0;
}

// 0x194ef50
void *evtSkyShutdown(dds3ProcessID_t *id) {
  fldSkySet_RgbPar(0);
  skyanime = 0;
  fldbokasi = 0;
  id->func_ans = -1;
  return 0;
}

// 0x194ece0
void evtUpdateSkyAlpha(void) {
  u32 v2;
  u32 v3;
  f32 v7;
  s32 skyabase;
  s32 skyatarget;
  s32 skyabase_par;
  s32 skyatarget_par;

  if (skyanime)
  {
    ++skyanow;
    LOWORD(v2) = skyanow;
    LOWORD(v3) = skyamax;
    v7 = v2 / v3;
    fldSkySetAlphaOfs((v7 * (skyatarget - skyabase)) + skyabase, 0);
    if (skyabase_par)
      goto LABEL_35;
    if (skyatarget_par)
    {
LABEL_35:
      fldSkySet_RgbPar((v7 * (skyatarget_par - skyabase_par)) + skyabase_par, 0);
    }
    if (skyanow >= skyamax)
    {
      skyanime = 0;
    }
  }
}
