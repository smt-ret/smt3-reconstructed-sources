#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE904_funcDelegate nbE904_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;

static nbE904_funcDelegate *func[2];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static dds3Basic_t *pPBCameraBasic01;
static s32 pPBCameraBasicIndex;

void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void effBTLModelColorSet(effBTL_SkillModel_t **pModel, nbFormation_t **pFormation);
void effBTLPointLightSet(effBTL_SkillLight_t **pLight, nbFormation_t **pFormation);
void effBTLSkillEnd(void);
void effBTLSkillStart(u32 id, u32 stat);
void effBTL_SkillLight_t__Clear(effBTL_SkillLight_t *this);
void effBTL_SkillModel_t__Clear(effBTL_SkillModel_t *this);
void effPadVibeFadeOUT(u32 mode, u8 power, s32 frame);
u8 **evtGetResorceData(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
void nbPanelAllHide(void);
void nbResetFormPosRot(nbFormation_t **form);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbSingleFormExceptedDispOff(nbFormation_t **form);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16f30c0
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x16f32e0
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 191)
    return 0;
  Write(StringLiteral_21328, 0);
  ed->data->endtype = 1;
  return 1;
}

// 0x16f30d0
s32 Test(nbEventProcessData_t *ed) {
  struct nbFormation_t_array *v3;
  evtUnitHandle_t_o **p_hunit;
  System_Byte_array *ResorceData;
  System_Byte_array *v10;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o v14;

  form = 0;
  v3 = ed->data->form;
  form = v3->m_Items[5];
  nbPanelAllHide();
  nbSingleFormExceptedDispOff(&form);
  p_hunit = &form->hunit;
  evtSetUnitMotion(p_hunit, 23, 0, 0, 2);
  ResorceData = evtGetResorceData(904, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  v10 = evtGetResorceData(904, 2);
  nbAddSkillEffectKoukaPacket3(0, 0, v10, 2, &form);
  nbAddFadeOutKoukaPacket(90, 0, 70, 1);
  nbResetFormPosRot(&form);
  v14.x = -111.43;
  v14.y = 0.0;
  v14.z = 394.81;
  v14.w = 0.0;
  nbSetFormPos(&form, v14);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f3380
void *nbE904Process_1(dds3ProcessID_t *id) {
    effBTL_SkillLight_t__Clear(0);
    effBTL_SkillModel_t__Clear(0);
    dds3GetActiveScene();
    dds3GetProcessData(0);
    nbEventPrefabDelete(0);
    dds3DeleteSceneBasicData(0);
    effBTLSkillEnd();
    dds3GetUnitHandleObjectBasic(0);
    nbCameraHelperModelSet(0);
    evtRegistBEUnit(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    nbEventPrefabRead(0, 0, 0);
    evtSetUnitMotion(0, 0, 0, 0, 0);
    nbCameraSetState(0);
    effBTLPointLightSet(0, 0);
    effBTLModelColorSet(0, 0);
    effBTLSkillStart(0, 0);
    dds3PadAct(0, 0, 0);
    effPadVibeFadeOUT(0, 0, 0);
    nbUpdateEventProcessData(0);
    return 0;
}
