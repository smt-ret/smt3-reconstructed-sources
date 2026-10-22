#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE914_funcDelegate nbE914_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static nbE914_funcDelegate *func[2];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static s32 pPBCameraBasicIndex;

void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void effBTLModelColorSet(effBTL_SkillModel_t **pModel, nbFormation_t **pFormation);
void effBTLPointLightSet(effBTL_SkillLight_t **pLight, nbFormation_t **pFormation);
void effBTLSkillStart(u32 id, u32 stat);
void effBTL_SkillLight_t__Clear(effBTL_SkillLight_t *this);
void effBTL_SkillModel_t__Clear(effBTL_SkillModel_t *this);
u8 **evtGetResorceData(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
void nbCameraBoss_BSMETA_E914_1_Set(void);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
void nbDelAllKoukaPacketType(s32 type);
void nbEventPbRead(s32 event_no, s32 index);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
nbFormation_t *nbGetEventForm(void);
void nbPanelAllHide(void);
void nbSetEnemyFormation(nbMainProcessData_t **data);
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty);
void nbSingleFormExceptedDispOff(nbFormation_t **form);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x1703e90
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x1704060
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 271)
    return 0;
  Write("メタトロン死亡\n", 0);
  nbDelAllKoukaPacketType(43);
  ed->data->endtype = 1;
  return 1;
}

// 0x1703eb0
s32 Test(nbEventProcessData_t *ed) {
  evtUnitHandle_t_o **p_hunit;
  System_Byte_array *ResorceData;
  nbFormation_t_o *form;

  form = 0;
  form = nbGetEventForm();
  nbPanelAllHide();
  nbSingleFormExceptedDispOff(&form);
  p_hunit = &form->hunit;
  evtSetUnitMotion(p_hunit, 23, 0, 0, 2);
  nbEventPbRead(914, 1);
  ResorceData = evtGetResorceData(914, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  nbAddFadeOutKoukaPacket(230, 0, 40, 1);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x1703ea0
void nbBgmStop(void) {
  ;
}

// 0x1704110
void *nbE914Process_1(dds3ProcessID_t *id) {
  u64 *v2;
  u64 *v3;
  u64 *v4;
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v10;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  struct nbE914_funcDelegate_array *func;
  s64 seq;
  s32 time;
  dds3ModelHandle_t_o *Model;
  s32 eventrid;
  s32 v31;
  dds3Basic_t_o *v34;
  s32 v38;
  nbFormation_t_o *EventForm;
  effBTL_SkillLight_t_o *v43;
  effBTL_SkillLight_t_o *v44;
  effBTL_SkillModel_t_o *v45;
  dds3Basic_t_o *pBasic;
  effBTL_SkillModel_t_o *pModel;
  effBTL_SkillLight_t_o *pLight;
  nbFormation_t_o *form;
  evtUnitHandle_t_o *h;
  dds3ProcessID_t_o *ida;
  u64 v53[3];

  ida = id;
  form = 0;
  pBasic = 0;
  v2 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v2);
  h = v2;
  v3 = Allocate(effBTL_SkillLight_t);
  effBTL_SkillLight_t___ctor(v3);
  pLight = v3;
  effBTL_SkillLight_t__Clear(v3);
  v4 = Allocate(effBTL_SkillModel_t);
  effBTL_SkillModel_t___ctor(v4);
  pModel = v4;
  effBTL_SkillModel_t__Clear(v4);
  pBasic = dds3GetActiveScene();
  ProcessData = dds3GetProcessData(&ida);
  v10 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v53);
      if ((v53[0] & 1) != 0)
        v13 = v53[2];
      else
        v13 = v53 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  seq = v10->seq;
  if (Invoke(func->m_Items[seq], v10))
  {
    pPBCameraBasicCurrent = 0;
    if (pPBCameraBasic00)
    {
      nbEventPrefabDelete(&pPBCameraBasic00);
      dds3DeleteSceneBasicData(&pPBCameraBasic00);
      pPBCameraBasic00 = 0;
    }
    ida->func_ans = -1;
    return 0;
  }
  time = v10->time;
  if (time >= 1)
  {
    if (pPBCameraBasicCurrent)
    {
      h = dds3GetUnitHandleObjectBasic(&pPBCameraBasicCurrent);
      Model = h->Model;
      if (Model)
      {
        nbCameraHelperModelSet(Model);
      }
    }
    time = v10->time;
  }
  if (time == 110)
  {
    nbCameraBoss_BSMETA_E914_1_Set();
    pPBCameraBasicCurrent = 0;
    v38 = v10->time;
    if (v38 != 1)
      goto LABEL_82;
LABEL_94:
    EventForm = nbGetEventForm();
    v43 = pLight;
    form = EventForm;
    pLight->pos_ptr->target = 2;
    v43->pos_ptr->height = 1;
    v43->pos_ptr->direction = 0;
    v43->pos_ptr->radius = 0;
    v44 = v43;
    {
      v44 = v43;
    }
    v43->diffuse = -2132344833;
    v44->ambient = -2144199128;
    v44->color_anim->fade_in_frame = 0;
    v44->color_anim->fade_in_pattern = 0;
    v44->color_anim->fade_out_frame = 10000;
    v44->color_anim->fade_out_pattern = 0;
    v45 = pModel;
    pModel->color = -2138925418;
    v45->color_anim->fade_in_frame = 0;
    v45->color_anim->fade_in_pattern = 0;
    v45->color_anim->fade_out_frame = 10000;
    v45->color_anim->fade_out_pattern = 0;
    effBTLPointLightSet(&pLight, &form);
    effBTLModelColorSet(&pModel, &form);
    goto LABEL_104;
  }
  if (!time)
  {
    form = nbGetEventForm();
    nbSingleFormExceptedDispOff(&form);
    nbCameraSetState(0x17u);
    eventrid = v10->eventrid;
    v31 = evtRegistBEUnit(eventrid, 2);
    v34 = dds3SearchSceneBasic(&pBasic, v31, 5u);
    pPBCameraBasic00 = v34;
    pPBCameraBasicIndex = 2;
    nbEventPrefabRead(&pPBCameraBasic00, v10->eventrid, pPBCameraBasicIndex);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic00);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    pPBCameraBasicCurrent = pPBCameraBasic00;
    nbSetEnemyFormation(&v10->data);
    nbSetPlayerFormation(&v10->data, 0);
  }
  v38 = v10->time;
  if (v38 == 1)
    goto LABEL_94;
LABEL_82:
  if (!v38)
  {
    effBTLSkillStart(0x202u, 0);
  }
LABEL_104:
  nbUpdateEventProcessData(&ida);
  return 0;
}
