#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct nbMakaProcessData_t nbMakaProcessData_t;

void DispMaka(nbMakaProcessData_t **d, s32 ox, s32 oy, u32 oc, s32 a);
void *GetBattleUI(s32 index);
nbMakaProcessData_t *GetMakaProcessData(void);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetAnime(nbMakaProcessData_t **d);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void nbMakaProcessData_t__Clear(nbMakaProcessData_t *this);

// 0x19845f0
void DispMaka(nbMakaProcessData_t **d, s32 ox, s32 oy, u32 oc, s32 a) {
    GetBattleUI(0);
    Set(0, 0);
}

// 0x19847c0
s32 GetKetaSu(u32 n, s32 m) {
  s32 v3;
  s32 v4;
  s32 v5;
  s32 v6;

  if (m < 1)
  {
    v4 = 10;
    return n % v4 / (v4 / 0xAu);
  }
  v3 = m & 3;
  if ((m - 1) < 3)
  {
    v4 = 10;
    if ((m & 3) == 0)
      return n % v4 / (v4 / 0xAu);
  }
  v5 = v3 - m;
  v4 = 10;
  do
  {
    v4 *= 10000;
    v5 += 4;
  }
  while (v5);
  if ((m & 3) != 0)
  {
    v6 = -v3;
    do
    {
      v4 *= 10;
      ++v6;
    }
    while (v6);
  }
  return n % v4 / (v4 / 0xAu);
}

// 0x1984390
nbMakaProcessData_t *GetMakaProcessData(void) {
    dds3SearchProcessName(0);
    dds3GetProcessData(0);
    return 0;
}

// 0x1984b40
nbMakaProcessData_t *InitMakaProcessData(void) {
  nbMakaProcessData_t_o *v1;

  v1 = Allocate(nbMakaProcessData_t);
  nbMakaProcessData_t___ctor(v1);
  nbMakaProcessData_t__Clear(v1);
  v1->oldmaka = DDS3_GBWK->maka;
  return v1;
}

// 0x1984840
void SetAnime(nbMakaProcessData_t **d) {
  nbMakaProcessData_t_o *v3;
  s32 stat;
  nbMakaProcessData_t_o *v5;
  s32 alpha;
  s32 offtime;
  bool v8;
  s32 v9;
  UnityEngine_GameObject_o *BattleUI;
  s32 v11;

  v3 = *d;
  stat = (*d)->stat;
  if (stat != 2)
  {
    if (stat != 1)
      return;
    v3->disp = 1;
    v5 = *d;
    alpha = (*d)->alpha;
    if (alpha != 128)
    {
      v5->alpha = alpha + 32;
      if ((*d)->alpha >= 129)
        (*d)->alpha = 128;
      return;
    }
    v5->stat = 0;
    return;
  }
  offtime = v3->offtime;
  v8 = __OFSUB__(offtime, 1);
  v9 = offtime - 1;
  if (v9 < 0 != v8)
  {
    v11 = v3->alpha;
    if (v11 < 1)
    {
      v3->disp = 0;
      v5 = *d;
    }
    v3->alpha = v11 - 20;
    if ((*d)->alpha < 0)
      (*d)->alpha = 0;
  }
  else
  {
    v3->offtime = v9;
    if (!(*d)->offtime)
    {
      BattleUI = GetBattleUI(7);
      if (get_activeSelf(BattleUI))
        SetActive(BattleUI, 0, 0);
    }
  }
}

// 0x197ee00
dds3ProcessID_t *nbInitMakaProcess(dds3ProcessID_t *parent) {
  nbMakaProcessData_t_o *data;
  u64 *v6;
  u64 *v7;
  dds3ProcessID_t_o *result;
  dds3ProcessID_t_o *target;
  dds3ProcessID_t_o *parenta;

  parenta = parent;
  target = 0;
  data = Allocate(nbMakaProcessData_t);
  nbMakaProcessData_t___ctor(data);
  nbMakaProcessData_t__Clear(data);
  data->oldmaka = DDS3_GBWK->maka;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbMakaProcess_nbMakaProcess1__);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_nbMakaProcess_nbMakaShutdown__);
  result = dds3StartProcess(StringLiteral_21483, 0x2B0Eu, 1, 1, v6, 0, v7, 0, data, 0);
  target = result;
  if (parent)
  {
    dds3LinkProcess(&parenta, &target);
    return target;
  }
  return result;
}

// 0x1984700
void nbMakaDispOff(void) {
  nbMakaProcessData_t_o *MakaProcessData;
  s32 offtime;
  UnityEngine_GameObject_o *BattleUI;

  MakaProcessData = GetMakaProcessData();
  if (MakaProcessData->disp)
  {
    if (MakaProcessData->type)
    {
      offtime = MakaProcessData->offtime;
      MakaProcessData->stat = 2;
      if (!offtime)
      {
        BattleUI = GetBattleUI(7);
        if (get_activeSelf(BattleUI))
          SetActive(BattleUI, 0, 0);
      }
    }
    else
    {
      MakaProcessData->offtime = 20;
      MakaProcessData->stat = 2;
    }
  }
}

// 0x19844f0
void nbMakaDispOn(s32 type) {
  s32 v2;
  nbMakaProcessData_t_o *MakaProcessData;
  nbMakaProcessData_t_o *v5;
  s32 maka;
  UnityEngine_GameObject_o *BattleUI;
  nbMakaProcessData_t_o **v9;
  s32 v10;
  s32 v11;
  u32 v12;
  s32 v13;

  v2 = type;
  MakaProcessData = GetMakaProcessData(*&type);
  v5 = MakaProcessData;
  if (!v2)
    *&MakaProcessData->targetx = 0x10D00000112LL;
  maka = DDS3_GBWK->maka;
  v5->stat = 1;
  v5->oldmaka = maka;
  v5->type = v2;
  BattleUI = GetBattleUI(7);
  if (!get_activeSelf(BattleUI))
  {
    SetActive(BattleUI, 1, 0);
    DispMaka(v9, v10, v11, v12, v13);
  }
}

// 0x1984990
void *nbMakaProcess1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    SetAnime(0);
    DispMaka(0, 0, 0, 0, 0);
    return 0;
}

// 0x1984ad0
void *nbMakaShutdown(dds3ProcessID_t *id) {
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3GetProcessData(&ida);
  return 0;
}
