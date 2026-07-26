#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3ResetProcessFlag(dds3ProcessID_t **target, u32 flag, s32 type);
void dds3SetProcessFlag(dds3ProcessID_t **target, u32 flag, s32 type);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void effBTLEncountStart(void);
void nbBgmLoad(s32 encdata);
s32 nbBgmLoadChk(void);
void nbBgmPlay(void);
nbMainProcessData_t *nbGetMainProcessData(void);
bool nbLoadBattleEventPack(nbMainProcessData_t **data);
void nbLoadBattleEventPackInit(nbMainProcessData_t **data);
void nbLoadFlyUnitPack(nbMainProcessData_t **data);
void nbStageLoad(s32 major, s32 minor);

// 0x197bb60
void nbInitMaeProcess(nbMainProcessData_t **data) {
  u64 *v3;
  u64 *v4;
  dds3ProcessID_t_o *target;

  target = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_nbMaeProcess_nbMaeProcess0__);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbMaeProcess_nbMaeShutdown__);
  target = dds3StartProcess(StringLiteral_21432, 0x3F9u, 1, 1, v3, 0, v4, 0, 0, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->MaeProcessID = target;
}

// 0x197b9f0
void *nbMaeProcess0(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  s32 StageMajor;
  s32 StageMinor;
  u64 *v8;

  MainProcessData = nbGetMainProcessData();
  StageMajor = MainProcessData->StageMajor;
  StageMinor = MainProcessData->StageMinor;
  nbStageLoad(StageMajor, StageMinor);
  effBTLEncountStart();
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_nbMaeProcess_nbMaeProcess01__);
  return v8;
}

// 0x197b8b0
void *nbMaeProcess01(dds3ProcessID_t *id) {
  dds3ProcessID_t_o **p_StageProcessID;
  u64 *v7;
  nbMainProcessData_t_o *data;

  data = 0;
  data = nbGetMainProcessData();
  nbLoadBattleEventPackInit(&data);
  nbLoadFlyUnitPack(&data);
  p_StageProcessID = &data->StageProcessID;
  dds3SetProcessFlag(p_StageProcessID, 0x20u, 0);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_nbMaeProcess_nbMaeProcess02__);
  return v7;
}

// 0x197b7a0
void *nbMaeProcess02(dds3ProcessID_t *id) {
  u64 *v5;
  dds3ProcessID_t_o **p_StageProcessID;
  nbMainProcessData_t_o *data;

  data = 0;
  data = nbGetMainProcessData();
  v5 = 0;
  if (!nbLoadBattleEventPack(&data))
  {
    p_StageProcessID = &data->StageProcessID;
    dds3ResetProcessFlag(p_StageProcessID, 0x20u, 0);
    v5 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v5,
      0,
      Method_nbMaeProcess_nbMaeProcessBGMLoad__);
  }
  return v5;
}

// 0x197b5d0
void *nbMaeProcess1(dds3ProcessID_t *id) {
  nbBgmPlay();
  id->func_ans = -1;
  return 0;
}

// 0x197b700
void *nbMaeProcessBGMLoad(dds3ProcessID_t *id) {
  u64 *v2;

  nbBgmLoad(0);
  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_nbMaeProcess_nbMaeProcessBGMSync__);
  return v2;
}

// 0x197b650
void *nbMaeProcessBGMSync(dds3ProcessID_t *id) {
  u64 *v2;

  v2 = 0;
  if (nbBgmLoadChk() == 1)
  {
    v2 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v2,
      0,
      Method_nbMaeProcess_nbMaeProcess1__);
  }
  return v2;
}

// 0x197baf0
void *nbMaeShutdown(dds3ProcessID_t *id) {
  nbGetMainProcessData()->MaeProcessID = 0;
  return 0;
}
