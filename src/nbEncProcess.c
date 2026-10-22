#include "types.h"

typedef struct RippleEffect RippleEffect;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static s32 readbasetime;
static s32 readtime;

void Update(RippleEffect *this);
void dds3FadeColorSet(u32 r, u32 g, u32 b);
void dds3FadeIn2(u32 frame);
u32 dds3GetKernelCount(void);
u32 dds3GetProcessRunTime(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void effBTLEncountEnd(void);
void effBTLEncountStart(void);
s32 encChk(void);
void encMode(s32 mode);
s32 evtGetAgeOfMoon(void);
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type);
s32 nbCameraState_Start_CheckEnd(void);
s32 nbCheckLoadGroup(s32 side);
void nbDestroyCache(void);
void nbDispMsgHelp(s32 msgid, s32 no, s32 msgtype);
s32 nbGetJyokyoMes(nbMainProcessData_t *data, s32 jyokyomes);
nbMainProcessData_t *nbGetMainProcessData(void);
void nbGroupFormDispOn(s32 side);
void nbLoadUnitGroup(s32 side, s32 stop, s32 anime);

// 0x1706b00
void *nbEncProcess1(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  u32 KernelCount;
  u64 *v8;

  MainProcessData = nbGetMainProcessData();
  effBTLEncountStart();
  KernelCount = dds3GetKernelCount();
  readbasetime = KernelCount;
  readtime = 0;
  nbLoadUnitGroup(1, 1, (MainProcessData->stat & 0x800) == 0, 0);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_nbEncProcess_nbEncProcess2__);
  return v8;
}

// 0x1706a10
void *nbEncProcess2(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  s32 v4;
  s32 v5;
  u64 *v6;

  MainProcessData = nbGetMainProcessData();
  if (nbCheckLoadGroup(1))
    return 0;
  if ((MainProcessData->stat & 0x10) != 0)
  {
    v4 = 0;
    v5 = 1;
  }
  else
  {
    v4 = 1;
    v5 = 0;
  }
  nbLoadUnitGroup(0, v4, v5);
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbEncProcess_nbEncProcess2_5__);
  return v6;
}

// 0x17066e0
void *nbEncProcess2_5(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  u64 *v5;
  s64 v6;
  struct nbParty_t_array *v7;
  u64 v8;
  struct nbParty_t_array *v10;
  struct nbFormation_t_array *v11;
  s64 v13;
  nbFormation_t_o *v15;
  u32 v16;
  u32 KernelCount;
  s64 i;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v22;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v26;
  u32 flag;
  nbFormation_t_o *v29;
  dds3ProcessID_t_o *ida;

  ida = id;
  v29 = 0;
  MainProcessData = nbGetMainProcessData();
  if (nbCheckLoadGroup(0))
    goto LABEL_11;
  if (readtime)
  {
LABEL_11:
    if ((MainProcessData->stat & 0x800) == 0)
      goto LABEL_12;
LABEL_34:
    for (i = 8; i != 18; ++i)
    {
      party = MainProcessData->party;
      if ((*(*(&party->obj.klass + i) + 16LL) & 9) != 0)
      {
        v22 = MainProcessData->party;
        form = MainProcessData->form;
        v26 = form->m_Items[*(*(&v22->obj.klass + i) + 18LL)];
        v29 = v26;
        flag = v26->flag;
        if ((flag & 8) != 0)
          v26->flag = flag & 0xFFFFFFF7;
      }
    }
LABEL_45:
    v5 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v5,
      0,
      Method_nbEncProcess_nbEncProcess2_55__);
    return v5;
  }
  KernelCount = dds3GetKernelCount();
  readtime = KernelCount - readbasetime;
  if ((MainProcessData->stat & 0x800) != 0)
    goto LABEL_34;
LABEL_12:
  v5 = 0;
  if ((dds3GetProcessRunTime(&ida) & 7) == 0)
  {
    v6 = 8;
    while (1)
    {
      v7 = MainProcessData->party;
      v8 = v6 - 4;
      if ((*(*(&v7->obj.klass + v6) + 16LL) & 9) != 0)
      {
        v10 = MainProcessData->party;
        v11 = MainProcessData->form;
        v13 = *(*(&v10->obj.klass + v6) + 18LL);
        v15 = v11->m_Items[v13];
        v29 = v15;
        v16 = v15->flag;
        if ((v16 & 8) != 0)
          break;
      }
      ++v6;
      if (v8 >= 0xD)
        goto LABEL_45;
    }
    v15->flag = v16 & 0xFFFFFFF7;
    nbAddHitEffKoukaPacket(1, 0, &v29, 4);
    return 0;
  }
  return v5;
}

// 0x1706440
void *nbEncProcess2_55(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  u32 stat;
  nbMainProcessData_t_o *v5;
  s64 v6;
  struct nbFormation_t_array *form;
  s64 v9;
  s32 jyokyomsgid;
  s32 JyokyoMes;
  u64 *v15;

  MainProcessData = nbGetMainProcessData();
  stat = MainProcessData->stat;
  v5 = MainProcessData;
  if ((stat & 0x400) != 0)
  {
    v6 = 8;
    while (1)
    {
      form = v5->form;
      v9 = *(&form->obj.klass + v6);
      if ((*(v9 + 136) & 1) == 0)
        goto LABEL_17;
        break;
      if (evtGetAgeOfMoon() == 8)
        goto LABEL_16;
LABEL_17:
      if (++v6 == 18)
      {
        stat = v5->stat;
        goto LABEL_19;
      }
    }
    if (evtGetAgeOfMoon() != 8)
      goto LABEL_17;
LABEL_16:
    dds3ObjectBaseOnFlag((v9 + 152), 0x400u, 0, 0);
    *(*(*(v9 + 152) + 64LL) + 156LL) = 1128792064;
    goto LABEL_17;
  }
LABEL_19:
  if ((stat & 0x800) != 0)
  {
    nbGroupFormDispOn(1);
    dds3FadeColorSet(0, 0, 0);
    dds3FadeIn2(0);
    if (encChk())
    {
      encMode(1);
    }
  }
  if ((v5->stat & 0x10) != 0)
  {
    jyokyomsgid = v5->jyokyomsgid;
    JyokyoMes = nbGetJyokyoMes(v5, 6);
    nbDispMsgHelp(jyokyomsgid, JyokyoMes, 1);
  }
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_nbEncProcess_nbEncProcess2_6__);
  return v15;
}

// 0x1705f40
void *nbEncProcess2_6(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  u64 *v4;
  struct nbParty_t_array *party;
  u32 KernelCount;
  s32 readtime;

  MainProcessData = nbGetMainProcessData();
  v4 = 0;
  if (!nbCheckLoadGroup(0))
  {
    else if (readtime)
    {
      goto LABEL_10;
    }
    KernelCount = dds3GetKernelCount();
    readtime = KernelCount - readbasetime;
    party = MainProcessData->party;
    if (LODWORD(party->max_length))
      goto LABEL_11;
    goto LABEL_73;
  }
  return v4;
}

// 0x1705de0
void *nbEncProcess3(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  u64 v5;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v8;
  u32 stat;
  struct evtUnitHandle_t_o *hunit;
  nbMainProcessData_t_o *v14;

  MainProcessData = nbGetMainProcessData();
  v5 = 0;
  while (1)
  {
    form = MainProcessData->form;
    v8 = form->m_Items[v5];
    stat = v8->stat;
    if ((stat & 1) != 0)
    {
      if ((stat & 2) == 0)
        break;
      hunit = v8->hunit;
      if (!hunit || (hunit->Flag & 0x10000) != 0)
        break;
    }
    if (v5++ >= 0x1F)
    {
      if (nbCameraState_Start_CheckEnd())
      {
        effBTLEncountEnd();
        v14 = nbGetMainProcessData();
        v14->stat &= ~0x800u;
        id->func_ans = -1;
      }
      return 0;
    }
  }
  return 0;
}

// 0x1706c60
void *nbEncShutdown(dds3ProcessID_t *id) {
  nbGetMainProcessData()->EncProcessID = 0;
  return 0;
}

// 0x1706cd0
void nbInitEncProcess(nbMainProcessData_t *data) {
  u64 *v3;
  u64 *v4;
  XRD773Unity_GraphicManager_o *Instance;
  dds3ProcessID_t_o *target;

  target = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_nbEncProcess_nbEncProcess1__);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbEncProcess_nbEncShutdown__);
  target = dds3StartProcess("nb_enc", 0x3F9u, 1, 1, v3, 0, v4, 0, 0, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->EncProcessID = target;
  {
  }
  Instance = get_Instance();
  Update(Instance, 0);
}
