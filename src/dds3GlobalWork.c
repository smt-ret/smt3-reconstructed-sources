#include "types.h"

typedef struct dds3GlobalWork_t dds3GlobalWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclEncycRecord_t fclEncycRecord_t;

static dds3GlobalWork_t *DDS3_GBWK;
static s32 NewGame2_SYS_ENDING0;
static s32 NewGame2_SYS_ENDING1;
static s32 NewGame2_SYS_ENDING2;
static s32 NewGame2_SYS_ENDING3;
static s32 NewGame2_SYS_ENDING4;
static s32 NewGame2_SYS_ENDING5;
static s32 NewGame2_SYS_ENDING6;
static s32 NewGame2_SYS_ENDING7;
static s32 NewGame2_SYS_ZENSHO_ALL;
static s32 NewGame2_EV_ZENSYO_ALL;
static s16 NewGame2_endcnt;
static s32 NewGame2_playtime;
static fclEncycRecord_t *NewGame2_encyc_record;
static s32 *NewGame2_boss_press[UNKNOWN_ARRAY_SIZE];
static s32 NewGame2_SYS_BOSSRASH[24];
static s32 NewGame2_config_data[14];

void NewGame2Pop(void);
void NewGame2Push(void);
void UpdateAudioVolume(s32 type);
void UserInit(void);
void datInitBossPress(void);
void datInitPlayer(void);
void dds3GlobalWork_t__Init(dds3GlobalWork_t *this);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOn(s32 no);
void evtInitGlobalWork(void);
void fclEncycInitRecord(s32 mode);
void fclEncycRecord_t__Clear(fclEncycRecord_t *this);
void fclEncycRecord_t__Copy(fclEncycRecord_t *this, fclEncycRecord_t *data);
void fldGbInit_System(s32 mode);
void frInitNameData(void);
void scrInitGlobalWork(void);

// 0x17b6900
void NewGame2Pop(void) {
    evtBitOn(0);
    fclEncycRecord_t__Clear(0);
    fclEncycRecord_t__Copy(0, 0);
}

// 0x17b5700
void NewGame2Push(void) {
    evtBitCheck(0);
    fclEncycRecord_t__Clear(0);
    fclEncycRecord_t__Copy(0, 0);
}

// 0x17b4600
void UserDestroy(void) {
  ;
}

// 0x17b4490
void UserInit(void) {
  scrInitGlobalWork();
  evtInitGlobalWork();
  DDS3_GBWK->maxstock = 8;
  datInitPlayer();
  datInitBossPress();
  DDS3_GBWK->heartsequip = 0;
  DDS3_GBWK->heartscnt = 0;
  frInitNameData();
  fldGbInit_System(0);
  fclEncycInitRecord(0);
}

// 0x17b55b0
void dds3GlobalWorkDestroy(void) {
  dds3KillProcessName(StringLiteral_14725, 0);
  DDS3_GBWK = 0;
}

// 0x17b4610
void dds3GlobalWorkInit(void) {
  Il2CppObject *v1;
  u64 *v5;
  dds3ProcessID_t_o *v7;
  dds3ProcessID_t_o *v8;
  Il2CppObject *data;
  dds3ProcessID_t_o *started;

  v1 = Allocate(dds3GlobalWork_t);
  v1[8].klass = NewSpecific(byte, 0x40u);
  v1[8].monitor = NewSpecific(byte, 4u);
  v1[9].klass = NewSpecific(byte, 4u);
  _ctor(v1, 0);
  DDS3_GBWK = v1;
  dds3GlobalWork_t__Init(DDS3_GBWK);
  DDS3_GBWK->runtime = 0;
  DDS3_GBWK->playtime = 0;
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_dds3GlobalWork_dds3GlobalWorkMainProc__);
  data = DDS3_GBWK;
  started = dds3StartProcess(StringLiteral_14725, 1u, 0, 0, v5, v7, 0, v8, data);
  UserInit(started);
}

// 0x17b4400
dds3ProcessFunc_t *dds3GlobalWorkMainProc(dds3ProcessID_t *procID) {
  ++DDS3_GBWK->runtime;
  ++DDS3_GBWK->playtime;
  return 0;
}

// 0x17b77a0
void dds3GlobalWorkUserInit2(s32 mode) {
  if (mode == 1)
  {
    NewGame2Push();
    dds3GlobalWork_t__Init(DDS3_GBWK);
  }
  DDS3_GBWK->runtime = 0;
  DDS3_GBWK->playtime = 0;
  scrInitGlobalWork();
  evtInitGlobalWork();
  DDS3_GBWK->maxstock = 8;
  datInitPlayer();
  datInitBossPress();
  DDS3_GBWK->heartsequip = 0;
  DDS3_GBWK->heartscnt = 0;
  frInitNameData();
  fldGbInit_System(0);
  fclEncycInitRecord(0);
  if (mode == 1)
  {
    NewGame2Pop();
  }
}

// 0x17b4830
void dds3GlobalWork_t__Init(dds3GlobalWork_t *this) {
    UpdateAudioVolume(0);
}
