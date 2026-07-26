#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct FieldChrHD FieldChrHD;
typedef struct SOBED_PB_LIST SOBED_PB_LIST;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE nbE;
typedef struct nbEventFuncList_t nbEventFuncList_t;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;

static nbEventFuncList_t *eventfunclist[16];
static s32 ep_index;
static s32 ep_phase;
static dds3ProcessID_t *ep_id2;
static s32 nbe_uniqueid;
static nbE *nbEtbl[41];
static SOBED_PB_LIST *pb_list;

u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void ResetWaitMotion(nbEventProcessData_t **ed);
void SetPbList(SOBED_PB_LIST *gList);
void SetUpDateDI(FieldChrHD *this);
void SetWaitMotion(nbEventProcessData_t **ed);
void btlEve_BloomDof_Set(s32 btleve_no);
dds3Basic_t *dds3AddBEDEffectObjectBasic2(void *data, sdfVector4_t pos, sdfVector4_t rot);
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 evtGetEventPackStat(s32 eventno);
dds3ProcessID_t *evtLoadEventPack(s32 eventno);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
void nbEventProcessData_t__Clear(nbEventProcessData_t *this);
nbMainProcessData_t *nbGetMainProcessData(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
s32 nbMakeBadKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
void nbSetUnitMotion(nbFormation_t **form, s32 motion2, s32 mode, f32 ritu);
void nbSetWaitMotion(nbFormation_t **form, s32 motion, f32 ritu);
void nbStartBattleEventSound(nbMainProcessData_t **data);
void nbStopBattleEventSound(nbMainProcessData_t **data);
void p2sdPlaySE_20173184(char *define_name);
void p2sdSndStop_20178672(char *define_name);
sdfModelRootNode_t *sdfModelMakeUnity(sdfModelTexList_t *aTexList, u8 **bData, s32 bPos);

// 0x1708710
void ResetWaitMotion(nbEventProcessData_t **ed) {
  s64 v3;
  s64 v4;
  struct nbFormation_t_array *form;
  u64 v6;
  struct nbFormation_t_array *v8;
  struct nbFormation_t_array *v10;

  v3 = -14;
  v4 = 32;
  do
  {
    form = (*ed)->data->form;
    v6 = v3 + 14;
    if (((*(&form->obj.klass + v4))->_1.events & 1) != 0)
    {
      v8 = (*ed)->data->form;
      if (((*(&v8->obj.klass + v4))->_1.events & 2) != 0)
      {
        v10 = (*ed)->data->form;
        nbSetWaitMotion((v10 + v4), 0, 1.0, 0);
      }
    }
    ++v3;
    v4 += 8;
  }
  while (v3);
}

// 0x1708810
void SetWaitMotion(nbEventProcessData_t **ed) {
  s64 v3;
  s64 v4;
  struct nbFormation_t_array *form;
  u64 v6;
  struct nbFormation_t_array *v8;
  struct nbFormation_t_array *v10;
  struct nbFormation_t_array *v12;

  v3 = -14;
  v4 = 32;
  do
  {
    form = (*ed)->data->form;
    v6 = v3 + 14;
    if (((*(&form->obj.klass + v4))->_1.events & 1) != 0)
    {
      v8 = (*ed)->data->form;
      if (((*(&v8->obj.klass + v4))->_1.events & 2) != 0)
      {
        v10 = (*ed)->data->form;
        nbSetWaitMotion((v10 + v4), 0, 1.0, 0);
        v12 = (*ed)->data->form;
        nbSetUnitMotion((v12 + v4), 0, 0, 1.0, 0);
      }
    }
    ++v3;
    v4 += 8;
  }
  while (v3);
}

// 0x1707df0
void *TmpProcess(dds3ProcessID_t *id) {
  return 0;
}

// 0x17080a0
s32 nbCheckBattleEventPack(nbMainProcessData_t **data) {
  s64 i;
  u64 v5;
  struct nbEventFuncList_t_array *eventfunclist;
  struct nbEventFuncList_t_array *v9;
  struct nbEventFuncList_t_array *v12;
  s32 v14;

  for (i = 4; ; ++i)
  {
    v5 = i - 4;
    if (*(*(&eventfunclist->obj.klass + i) + 32LL))
    {
      v9 = eventfunclist;
      if (*(*(&v9->obj.klass + i) + 32LL) == (*data)->encno)
      {
        v12 = eventfunclist;
        v14 = *(*(&v12->obj.klass + i) + 16LL);
        if (v14)
        {
          if (evtGetEventPackStat(v14) != 2)
            break;
        }
      }
    }
    if (v5 >= 0xF)
      return 1;
  }
  return 0;
}

// 0x16ebe20
dds3Basic_t *nbCreateBasicEffect(void **p, sdfVector4_t pos, sdfVector4_t rot) {
  dds3Basic_t_o *basic;

  basic = dds3AddBEDEffectObjectBasic2(*p, pos, rot);
  dds3EffectObjectBasicStatOn(&basic, 1u);
  return basic;
}

// 0x17097c0
nbE *nbEventGetPrefabTbl(s32 event_no, s32 index) {
    return 0;
}

// 0x16f1430
void nbEventPbRead(s32 event_no, s32 index) {
    LoadPrefab_16624656(0, 0, 0, 0);
    SetPbList(0);
}

// 0x16ec260
void nbEventPrefabDelete(dds3Basic_t **pathbasic) {
  UnityEngine_Object_o *gameObject;
  UnityEngine_Object_o *v5;

  if (*pathbasic)
  {
    gameObject = (*pathbasic)->gameObject;
    if (op_Inequality(gameObject, 0, 0))
    {
      v5 = (*pathbasic)->gameObject;
      Destroy_27360000(v5);
      (*pathbasic)->gameObject = 0;
    }
  }
}

// 0x16eba20
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index) {
    LoadPrefab_16624656(0, 0, 0, 0);
    mdlSetHD(0, 0, 0, 0);
    SetUpDateDI(0);
    dds3GetUnitHandleObjectBasic(0);
    LoadFileByte(0, 0, 0);
    sdfModelMakeUnity(0, 0, 0);
}

// 0x17091d0
void *nbEventProcess1(dds3ProcessID_t *id) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    btlEve_BloomDof_Set(0);
    return 0;
}

// 0x1708c50
void *nbEventProcess3(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    nbGetUnitWorkFromFormindex(0);
    nbMakeBadKaifukuPacket(0, 0, 0);
    ResetWaitMotion(0);
    nbStartBattleEventSound(0);
    return 0;
}

// 0x1709440
void *nbEventShutdown(dds3ProcessID_t *id) {
    nbGetMainProcessData();
    nbStopBattleEventSound(0);
    dds3GetProcessData(0);
    SetWaitMotion(0);
    return 0;
}

// 0x1708ad0
s32 nbGetDeadEventFadeInFrame(s32 eventno) {
  struct nbEventFuncList_t_array *eventfunclist;

  return eventfunclist->m_Items[eventno % 100]->fadein;
}

// 0x1708a10
s32 nbGetDeadEventFadeOutFrame(s32 eventno) {
  struct nbEventFuncList_t_array *eventfunclist;

  return eventfunclist->m_Items[eventno % 100]->fadeout;
}

// 0x1708b90
s32 nbGetDeadEventFadeStopFrame(s32 eventno) {
  struct nbEventFuncList_t_array *eventfunclist;

  return eventfunclist->m_Items[eventno % 100]->fadestop;
}

// 0x1708950
s32 nbGetDeadEventFadeTime(s32 eventno) {
  struct nbEventFuncList_t_array *eventfunclist;

  return eventfunclist->m_Items[eventno % 100]->fadetime;
}

// 0x16ec7d0
nbFormation_t *nbGetEventForm(void) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v5;
  struct nbFormation_t_array *v7;
  struct nbFormation_t_array *v9;
  struct nbFormation_t_array *v10;
  struct nbFormation_t_array *v12;
  struct nbFormation_t_array *v14;
  struct nbFormation_t_array *v16;
  struct nbFormation_t_array *v18;
  struct nbFormation_t_array *v20;
  s64 v23;
  struct nbFormation_t_array *v24;

  MainProcessData = nbGetMainProcessData();
  form = MainProcessData->form;
  if ((form->m_Items[4]->stat & 1) != 0)
  {
    v23 = 4;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 4)
      return v24->m_Items[v23];
  }
  v5 = MainProcessData->form;
  if ((v5->m_Items[5]->stat & 1) != 0)
  {
    v23 = 5;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 5)
      return v24->m_Items[v23];
  }
  v7 = MainProcessData->form;
  if ((v7->m_Items[6]->stat & 1) != 0)
  {
    v23 = 6;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 6)
      return v24->m_Items[v23];
  }
  v9 = MainProcessData->form;
  if ((v9->m_Items[7]->stat & 1) != 0)
  {
    v23 = 7;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 7)
      return v24->m_Items[v23];
  }
  v10 = MainProcessData->form;
  if ((v10->m_Items[8]->stat & 1) != 0)
  {
    v23 = 8;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 8)
      return v24->m_Items[v23];
  }
  v12 = MainProcessData->form;
  if ((v12->m_Items[9]->stat & 1) != 0)
  {
    v23 = 9;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 9)
      return v24->m_Items[v23];
  }
  v14 = MainProcessData->form;
  if ((v14->m_Items[10]->stat & 1) != 0)
  {
    v23 = 10;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 0xA)
      return v24->m_Items[v23];
  }
  v16 = MainProcessData->form;
  if ((v16->m_Items[11]->stat & 1) != 0)
  {
    v23 = 11;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 0xB)
      return v24->m_Items[v23];
  }
  v18 = MainProcessData->form;
  if ((v18->m_Items[12]->stat & 1) != 0)
  {
    v23 = 12;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 0xC)
      return v24->m_Items[v23];
  }
  v20 = MainProcessData->form;
  if ((v20->m_Items[13]->stat & 1) == 0)
    return 0;
  v23 = 13;
  v24 = MainProcessData->form;
  if (LODWORD(v24->max_length) <= 0xD)
  return v24->m_Items[v23];
}

// 0x17086d0
s32 nbGetEventSeq(nbEventProcessData_t **ed) {
  if (*ed)
    return (*ed)->seq;
  else
    return 0;
}

// 0x1709620
void nbInitEventProcess(nbMainProcessData_t *data) {
  nbEventProcessData_t_o *v3;
  u64 *v6;
  u64 *v7;
  dds3ProcessID_t_o *target;

  target = 0;
  v3 = Allocate(nbEventProcessData_t);
  nbEventProcessData_t___ctor(v3);
  nbEventProcessData_t__Clear(v3);
  v3->data = data;
  v3->uniqueid = ++nbe_uniqueid;
  v3->data->stat |= 0x1000u;
  data->endtype = 0;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbEventProcess_nbEventProcess1__);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_nbEventProcess_nbEventShutdown__);
  target = dds3StartProcess(StringLiteral_21345, 0x3F9u, 1, 1, v6, 0, v7, 0, v3, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->EventProcessID = target;
}

// 0x17082b0
bool nbLoadBattleEventPack(nbMainProcessData_t **data) {
    evtLoadEventPack(0);
    dds3LinkProcess(0, 0);
    dds3GetProcessData(0);
    return 0;
}

// 0x1708240
void nbLoadBattleEventPackInit(nbMainProcessData_t **data) {
  ep_index = 0;
  ep_phase = 0;
}

// 0x1707de0
s32 nbMakeBadKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t *form) {
  return 0;
}

// 0x16eb620
void nbNextEventSeq(nbEventProcessData_t **ed) {
  if (*ed)
  {
    ++(*ed)->seq;
    (*ed)->seqtime = 0;
  }
}

// 0x17086f0
void nbSetEventSeq(nbEventProcessData_t **ed, s32 no) {
  if (*ed)
  {
    (*ed)->seq = no;
    (*ed)->seqtime = 0;
  }
}

// 0x1707e00
void nbStartBattleEventSound(nbMainProcessData_t **data) {
  struct nbEventFuncList_t_array *eventfunclist;
  s64 eventno;
  struct nbEventFuncList_t_array *v9;
  s64 v10;
  System_String_o *seid;

  eventno = (*data)->eventno;
  if (op_Inequality(eventfunclist->m_Items[eventno]->seid, StringLiteral_416, 0))
  {
    v9 = eventfunclist;
    v10 = (*data)->eventno;
    seid = v9->m_Items[v10]->seid;
    p2sdPlaySE_20173184(seid);
  }
}

// 0x1707f50
void nbStopBattleEventSound(nbMainProcessData_t **data) {
  struct nbEventFuncList_t_array *eventfunclist;
  s64 eventno;
  struct nbEventFuncList_t_array *v9;
  s64 v10;
  System_String_o *seid;

  eventno = (*data)->eventno;
  if (op_Inequality(eventfunclist->m_Items[eventno]->seid, StringLiteral_416, 0))
  {
    v9 = eventfunclist;
    v10 = (*data)->eventno;
    seid = v9->m_Items[v10]->seid;
    p2sdSndStop_20178672(seid);
  }
}

// 0x16ed770
void nbUpdateEventProcessData(dds3ProcessID_t **id) {
    dds3GetProcessData(0);
}
