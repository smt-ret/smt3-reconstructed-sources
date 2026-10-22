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
  u64 v5;
  struct nbE_array *nbEtbl;
  u64 max_length_low;
  nbE_o *result;

  v5 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(nbEtbl->max_length);
    if (v5 >= max_length_low)
      return 0;
    else if (v5 >= max_length_low)
    {
      goto LABEL_12;
    }
    result = nbEtbl->m_Items[v5];
    if (result->event_no == event_no && result->index == index)
      return result;
    ++v5;
      goto LABEL_6;
  }
}

// 0x16f1430
void nbEventPbRead(s32 event_no, s32 index) {
  System_String_o *v4;
  System_String_o *v6;
  u64 v7;
  struct nbE_array *nbEtbl;
  u64 max_length_low;
  nbE_o *v12;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *Prefab_16624656;
  SOBED_PB_LIST_o *pb_list;
  s32 v19;

  v19 = event_no;
  v4 = sub_232A70(&v19, "d3");
  v6 = Concat_5224608("e", v4);
  v7 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(nbEtbl->max_length);
    if (v7 >= max_length_low)
      break;
    else if (v7 >= max_length_low)
    {
      goto LABEL_12;
    }
    v12 = nbEtbl->m_Items[v7];
    if (v19 == v12->event_no && v12->index == index)
    {
      asset_bc = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, v6, v12->path, v12->prefab);
      if (op_Inequality(Prefab_16624656, 0, 0))
      {
        pb_list->gobj = Prefab_16624656;
        pb_list->reversePB = 0;
        SetPbList(pb_list);
      }
      return;
    }
    ++v7;
      goto LABEL_6;
  }
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
  System_String_o *v6;
  System_String_o *v8;
  u64 v9;
  struct nbE_array *nbEtbl;
  u64 max_length_low;
  nbE_o *v14;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v18;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v21;
  UnityEngine_Transform_o *v23;
  f32 *p_SDF_CC_NDNM;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  UnityEngine_Transform_o *v30;
  FieldChrHD_o *v33;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  System_String_o *v37;
  AssetBundleCtrl_o *v38;
  System_Byte_array *FileByte;
  struct dds3ModelHandle_t_o *Model;
  System_Byte_array *v41;
  s32 v42;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Quaternion_o v44;
  UnityEngine_Quaternion_o v45;

  v42 = event_no;
  v6 = sub_232A70(&v42, "d3");
  v8 = Concat_5224608("e", v6);
  v9 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(nbEtbl->max_length);
    if (v9 >= max_length_low)
      break;
    else if (v9 >= max_length_low)
    {
      goto LABEL_12;
    }
    v14 = nbEtbl->m_Items[v9];
    if (v42 == v14->event_no && v14->index == index)
    {
      asset_bc = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, v8, v14->path, v14->prefab);
      if (op_Inequality(Prefab_16624656, 0, 0))
      {
        v18 = Find("Character", 0);
        transform = get_transform(v18, 0);
        v21 = Instantiate_object__425664(Prefab_16624656, transform, 0);
        v23 = get_transform(v21, 0);
        p_SDF_CC_NDNM = &SDF_CC_NDNM;
        v26 = p_SDF_CC_NDNM[2];
        v27 = p_SDF_CC_NDNM[3];
        v28 = p_SDF_CC_NDNM[4];
        v29 = p_SDF_CC_NDNM[5];
        v30 = get_transform(v21, 0);
        rotation = get_rotation(v30);
        {
        }
        v44.x = v26;
        v44.y = v27;
        v44.z = v28;
        v44.w = v29;
        v45 = op_Multiply(v44, rotation, 0);
        set_rotation(v23, v45);
        v33 = mdlSetHD(v21, 2, 0, 15);
        SetUpDateDI(v33);
        UnitHandleObjectBasic = dds3GetUnitHandleObjectBasic(pathbasic);
        v37 = Concat_5271136(v14->path, "/", v14->prefab, ".pb.bytes");
        v38 = get_asset_bc();
        FileByte = LoadFileByte(v38, v8, v37);
        Model = UnitHandleObjectBasic->Model;
        v41 = FileByte;
        Model->modelRoot = sdfModelMakeUnity(0, FileByte, 0);
        UnitHandleObjectBasic->Model->resrc->effectData = &v41->obj;
        (*pathbasic)->gameObject = v21;
        UnitHandleObjectBasic->Model->modelRoot->modelobj = v21;
      }
      return;
    }
    ++v9;
      goto LABEL_6;
  }
}

// 0x17091d0
void *nbEventProcess1(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  Il2CppObject *ProcessData;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v11;
  struct nbEventFuncList_t_array *eventfunclist;
  s64 eventno;
  s32 resource;
  s32 v18;
  u64 *v19;
  dds3ProcessID_t_o *v21;
  u64 v22[3];

  v21 = id;
  MainProcessData = nbGetMainProcessData();
  ProcessData = dds3GetProcessData(&v21);
  v5 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v22);
      if ((v22[0] & 1) != 0)
        v8 = v22[2];
      else
        v8 = v22 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  LODWORD(v22[0]) = MainProcessData->eventno;
  v11 = sub_8D3950(s32, v22);
  Write_2930400("イベント起動 -> {0:D}\n", v11);
  eventno = MainProcessData->eventno;
  resource = eventfunclist->m_Items[eventno]->resource;
  MainProcessData->eventrid = resource;
  if (resource >= 1)
    LODWORD(v5[1].monitor) = resource;
  v18 = MainProcessData->eventno;
  btlEve_BloomDof_Set(v18 + 900);
  v19 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v19,
    0,
    Method_nbEventProcess_nbEventProcess3__);
  return v19;
}

// 0x1708c50
void *nbEventProcess3(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  nbEventProcessData_t_c *v3;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v9;
  s64 i;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v15;
  struct nbFormation_t_array *v17;
  struct nbFormation_t_array *v19;
  struct nbFormation_t_array *v21;
  struct nbFormation_t_array *v23;
  struct nbFormation_t_array *v25;
  struct nbFormation_t_array *v27;
  struct nbFormation_t_array *v29;
  struct nbFormation_t_array *v31;
  struct nbFormation_t_array *v33;
  struct nbFormation_t_array *v35;
  struct nbFormation_t_array *v37;
  struct nbFormation_t_array *v39;
  struct nbFormation_t_array *v41;
  struct nbEventFuncList_t_array *eventfunclist;
  s64 eventno;
  struct nbEventFuncList_t_array *v47;
  s64 v48;
  nbFormation_t_o *v51;
  nbEventProcessData_t_o *ed;
  nbMainProcessData_t_o *data;
  dds3ProcessID_t_o *v54[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ed = 0;
  data = 0;
  v51 = 0;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v54);
      if ((v54[0] & 1) != 0)
        v7 = v54[2];
      else
        v7 = v54 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = ProcessData[1].klass;
  ed = ProcessData;
  data = v9;
  for (i = 8; i != 18; ++i)
  {
    form = v9->form;
    v51 = *(&form->obj.klass + i);
    if ((v51->stat & 1) != 0)
    {
      else
      {
        UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(i - 4);
        if (!UnitWorkFromFormindex)
          continue;
      }
      if ((UnitWorkFromFormindex->badstatus & 0xFFF) != 0)
        nbMakeBadKaifukuPacket(0, 0, &v51);
    }
  }
  ResetWaitMotion(&ed, v3);
  v15 = v9->form;
  v15->m_Items[0]->stat &= ~8u;
  v17 = v9->form;
  v17->m_Items[1]->stat &= ~8u;
  v19 = v9->form;
  v19->m_Items[2]->stat &= ~8u;
  v21 = v9->form;
  v21->m_Items[3]->stat &= ~8u;
  v23 = v9->form;
  v23->m_Items[4]->stat &= ~8u;
  v25 = v9->form;
  v25->m_Items[5]->stat &= ~8u;
  v27 = v9->form;
  v27->m_Items[6]->stat &= ~8u;
  v29 = v9->form;
  v29->m_Items[7]->stat &= ~8u;
  v31 = v9->form;
  v31->m_Items[8]->stat &= ~8u;
  v33 = v9->form;
  v33->m_Items[9]->stat &= ~8u;
  v35 = v9->form;
  v35->m_Items[10]->stat &= ~8u;
  v37 = v9->form;
  v37->m_Items[11]->stat &= ~8u;
  v39 = v9->form;
  v39->m_Items[12]->stat &= ~8u;
  v41 = v9->form;
  v41->m_Items[13]->stat &= ~8u;
  eventno = v9->eventno;
  if (eventfunclist->m_Items[eventno]->func)
  {
    v4[3].klass = 0;
    nbStartBattleEventSound(&data);
    v47 = eventfunclist;
    v48 = v9->eventno;
    return v47->m_Items[v48]->func;
  }
  else
  {
    ida->func_ans = -1;
    return 0;
  }
}

// 0x1709440
void *nbEventShutdown(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  Il2CppObject *ProcessData;
  nbEventProcessData_t_c *v6;
  Il2CppObject *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  nbEventProcessData_t_usershutdownDelegate_o *v12;
  nbEventProcessData_t_o *ed;
  nbMainProcessData_t_o *data;
  dds3ProcessID_t_o *v16[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  data = 0;
  ed = 0;
  MainProcessData = nbGetMainProcessData();
  data = MainProcessData;
  nbStopBattleEventSound(&data);
  MainProcessData->stat &= ~0x1000u;
  MainProcessData->eventno = 0;
  MainProcessData->EventProcessID = 0;
  ProcessData = dds3GetProcessData(&ida);
  v7 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v16);
      if ((v16[0] & 1) != 0)
        v10 = v16[2];
      else
        v10 = v16 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  ed = ProcessData;
  SetWaitMotion(&ed, v6);
  if (v7[4].monitor)
    v7[4].monitor = 0;
  if (v7[3].monitor)
    v7[3].monitor = 0;
  if (v7[4].klass)
    v7[4].klass = 0;
  v12 = v7[3].klass;
  if (v12)
    nbEventProcessData_t_usershutdownDelegate__Invoke(v12, ida);
  ida->func_ans = -1;
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
LABEL_37:
  }
  v5 = MainProcessData->form;
  if ((v5->m_Items[5]->stat & 1) != 0)
  {
    v23 = 5;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 5)
      return v24->m_Items[v23];
    goto LABEL_37;
  }
  v7 = MainProcessData->form;
  if ((v7->m_Items[6]->stat & 1) != 0)
  {
    v23 = 6;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 6)
      return v24->m_Items[v23];
    goto LABEL_37;
  }
  v9 = MainProcessData->form;
  if ((v9->m_Items[7]->stat & 1) != 0)
  {
    v23 = 7;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 7)
      return v24->m_Items[v23];
    goto LABEL_37;
  }
  v10 = MainProcessData->form;
  if ((v10->m_Items[8]->stat & 1) != 0)
  {
    v23 = 8;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 8)
      return v24->m_Items[v23];
    goto LABEL_37;
  }
  v12 = MainProcessData->form;
  if ((v12->m_Items[9]->stat & 1) != 0)
  {
    v23 = 9;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 9)
      return v24->m_Items[v23];
    goto LABEL_37;
  }
  v14 = MainProcessData->form;
  if ((v14->m_Items[10]->stat & 1) != 0)
  {
    v23 = 10;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 0xA)
      return v24->m_Items[v23];
    goto LABEL_37;
  }
  v16 = MainProcessData->form;
  if ((v16->m_Items[11]->stat & 1) != 0)
  {
    v23 = 11;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 0xB)
      return v24->m_Items[v23];
    goto LABEL_37;
  }
  v18 = MainProcessData->form;
  if ((v18->m_Items[12]->stat & 1) != 0)
  {
    v23 = 12;
    v24 = MainProcessData->form;
    if (LODWORD(v24->max_length) > 0xC)
      return v24->m_Items[v23];
    goto LABEL_37;
  }
  v20 = MainProcessData->form;
  if ((v20->m_Items[13]->stat & 1) == 0)
    return 0;
  v23 = 13;
  v24 = MainProcessData->form;
  if (LODWORD(v24->max_length) <= 0xD)
    goto LABEL_37;
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
  target = dds3StartProcess("nb_event", 0x3F9u, 1, 1, v6, 0, v7, 0, v3, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->EventProcessID = target;
}

// 0x17082b0
bool nbLoadBattleEventPack(nbMainProcessData_t **data) {
  s32 v4;
  s32 ep_phase;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 klass_high;
  s64 ep_index;
  struct nbEventFuncList_t_array *eventfunclist;
  struct nbEventFuncList_t_array *v18;
  s32 resource;
  dds3ProcessID_t_o *EventPack;
  dds3ProcessID_t_o **p_MainProcessID;
  char *v26;
  s64 *v27;
  u64 v28[3];

  {
    else
    {
      if (ep_phase)
        goto LABEL_5;
    }
LABEL_24:
    if (eventfunclist->m_Items[ep_index]->encno)
    {
      if (eventfunclist->m_Items[ep_index]->encno == (*data)->encno)
      {
        v18 = eventfunclist;
        resource = v18->m_Items[ep_index]->resource;
        if (resource)
        {
          EventPack = evtLoadEventPack(resource);
          ep_id2 = EventPack;
          p_MainProcessID = &(*data)->MainProcessID;
          dds3LinkProcess(p_MainProcessID, &ep_id2);
          ep_phase = 1;
        }
      }
    }
    else
    {
      if (ep_phase)
        goto LABEL_58;
    }
      goto LABEL_57;
LABEL_21:
LABEL_57:
    ++ep_index;
    goto LABEL_58;
  }
  v4 = 0;
  if (!ep_phase)
    goto LABEL_24;
LABEL_5:
  else if (ep_phase != 1)
  {
    goto LABEL_58;
  }
  ProcessData = dds3GetProcessData(&ep_id2);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPackProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPackProcessData_t, v28);
    if ((v28[0] & 1) != 0)
      v26 = v28[2];
    else
      v26 = v28 + 1;
    v27 = sub_8C4940(v26);
  }
  klass_high = HIDWORD(ProcessData[1].klass);
  if (klass_high == 2)
  {
    ep_phase = 0;
    goto LABEL_21;
  }
LABEL_58:
  return ep_index < 16;
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
  if (op_Inequality(eventfunclist->m_Items[eventno]->seid, "", 0))
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
  if (op_Inequality(eventfunclist->m_Items[eventno]->seid, "", 0))
  {
    v9 = eventfunclist;
    v10 = (*data)->eventno;
    seid = v9->m_Items[v10]->seid;
    p2sdSndStop_20178672(seid);
  }
}

// 0x16ed770
void nbUpdateEventProcessData(dds3ProcessID_t **id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  else
  {
    ProcessData = dds3GetProcessData(id);
    if (!ProcessData)
      return;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  ++HIDWORD(ProcessData[1].monitor);
  ++HIDWORD(ProcessData[2].klass);
}
