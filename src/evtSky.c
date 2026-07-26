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
  id = dds3SearchProcessName(StringLiteral_15987);
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
  return dds3StartProcess(StringLiteral_15987, 0x2B0Eu, 1, 1, v3, 0, v4, 0, 0, 0);
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
  evtSky_c *v13;
  s16 v14;
  struct evtSky_StaticFields *v15;
  struct evtSky_StaticFields *static_fields;
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
      static_fields = v13->static_fields;
      v17 = 0;
    }
    else
    {
      skyabase_par = RgbPar;
      skyatarget_par = v14;
      v15 = v13->static_fields;
      if (!v15->skyabase_par)
      {
        v15->skyabase_par = 100;
      }
      static_fields = v13->static_fields;
      if (static_fields->skyatarget_par)
      v17 = 100;
    }
    static_fields->skyatarget_par = v17;
    v19 = 1;
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
  evtSky_c *v4;
  struct evtSky_StaticFields *static_fields;
  struct evtSky_StaticFields *v6;
  f32 v7;
  s32 skyabase;
  s32 skyatarget;
  evtSky_c *v11;
  struct evtSky_StaticFields *v12;
  struct evtSky_StaticFields *v13;
  s32 skyabase_par;
  s32 skyatarget_par;
  struct evtSky_StaticFields *v16;

  static_fields = v4->static_fields;
  if (static_fields->skyanime)
  {
    ++static_fields->skyanow;
    v6 = evtSky->static_fields;
    LOWORD(v2) = v6->skyanow;
    LOWORD(v3) = v6->skyamax;
    v7 = v2 / v3;
    skyabase = v6->skyabase;
    skyatarget = v6->skyatarget;
    fldSkySetAlphaOfs((v7 * (skyatarget - skyabase)) + skyabase, 0);
    v12 = evtSky->static_fields;
    if (v12->skyabase_par)
    if (v12->skyatarget_par)
    {
      v13 = v11->static_fields;
      skyabase_par = v13->skyabase_par;
      skyatarget_par = v13->skyatarget_par;
      fldSkySet_RgbPar((v7 * (skyatarget_par - skyabase_par)) + skyabase_par, 0);
    }
    v16 = v11->static_fields;
    if (v16->skyanow >= v16->skyamax)
    {
      v16->skyanime = 0;
    }
  }
}
