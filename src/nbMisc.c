#include "types.h"

typedef struct FieldChrHD FieldChrHD;
typedef struct datUnitVisual_s datUnitVisual_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbMisc_Btl_BloomDown nbMisc_Btl_BloomDown;
typedef struct nbParty_t nbParty_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct nbMisc_Btl_BloomDown {
    s32 deveilID;
    f32 max;
};

static f32 nbMisc_datDevilVisual_dmy;
static f32 nbMisc_datEncountPack_dmy;
static s32 nbMisc_datEncount_dmy;
static s32 nbMisc_datDevilFormat_dmy;
static s32 nbMisc_tblSkill_dmy;
static s32 datSpecialSkill_dmy;
static s32 datNormalSkill_dmy;
static u32 nbMisc_datAisyo_dmy;
static s32 nbMisc_dmy_step;
static s32 nbMisc_dmy_idx;
static f32 ShadowLightYR;
static f32 ShadowLightYR_E;
static f32 ShadowLightYR_P;
static f32 ShadowSkillPow;
static bool ShadowFastE;
static bool ShadowFastP;
static s32 ShadowFld;
static s32 ShadowArea;
static s32 Base_PPSV2_bloom_type;
static nbMisc_Btl_BloomDown *Tbl_Btl_BloomDown[114];

void BloomDown(void);
f32 CalcRadiusShadow(u32 group, f32 *aPShadow2_CamY_add);
void DofOff(void);
u8 Get(s32 id);
datUnitVisual_t *Get2(s32 id);
f32 GetBloomDown(s32 deveilID);
void *GetHitNum(s32 idx, s32 copyNumber);
void *GetMainCamera(dds3DefaultMain *this);
void *GetTargetMark2D(s32 idx);
f32 OOYDEG(f32 a);
f32 OOYRAD(f32 a);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
f32 SDF_VU0__GETVECTOR_Y(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetLayerAll2(FieldChrHD *this, void *rootobj, s32 setlayer);
void SetLayerAll_FadeModeOff(FieldChrHD *this, void *rootobj);
void SetLayerAll_FadeModeOn(FieldChrHD *this, void *rootobj, s32 setlayer);
void SetShadowMode(dds3DefaultMain *this, s32 mode);
void SpShadow_BSONGY(void);
void ToMatrix(void);
void Unlock_16599376(char *id);
s32 datCheckStockFull(void);
s32 datGetItemSkillNo(s32 itemid);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
s32 datSearchDevilStock(s32 id);
void datSetDevilWork(s32 id, datUnitWork_t *w);
f32 dds3CameraObjectBasicGetFovy(dds3Basic_t **pBasic);
void dds3CameraObjectBasicGetTgtCam(dds3Basic_t **pBasic, sdfVector4_t *tgtpos, sdfVector4_t *campos);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetActiveScene(void);
u32 dds3GetRandIntA(u32 aLimit, char *name);
s32 dds3ObjectBaseCheckFlag(dds3Basic_t **pObjectBasic, u32 flag);
u32 effBTLModelGetID(nbFormation_t **pFormation);
void effBTLModelGetMarkPosition2(nbFormation_t **pFormation, u32 mark);
s32 effBTLSkillCheckRun(void);
bool effBTLSkillCheckRun2(u32 skillid);
u32 effBTLSkillGetID(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
u32 effBTLSystemGetRGBA(u32 id);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon16(void);
void evtSetAgeOfMoon(s32 age);
s32 fclEncycRegist(datUnitWork_t *punit, s32 overwrite, bool update);
void itfMesMngSetVar(s32 id, s32 index, s32 num, s32 type);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
nbFormation_t *nbGetEventForm(void);
nbMainProcessData_t *nbGetMainProcessData(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbHatudoCheckSkill(datUnitWork_t *work, s32 skill);
void nbSetEnemyFormation(nbMainProcessData_t **data);
void nbSetEnemyStartData_0(nbMainProcessData_t *data, s32 enc);
void nbSetEnemyStartData_1(nbMainProcessData_t *data, s32 enc);
void nbSetOrder(void);
void nbSetOrderSide(s32 side);
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty);
void nbSortOrder(s32 start);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSin(f32 aRadius);

// 0x120fc50
void BloomDown(void) {
  f32 PPSV2_bloom_btl_Default;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  f32 BloomDown;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v11;
  UnityEngine_Object_o *modelobj;
  s32 ID;
  dds3KernelDraw_c *v15;
  struct dds3KernelDraw_StaticFields **p_static_fields;
  struct dds3KernelDraw_StaticFields *static_fields;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 16; ++i)
  {
    form = MainProcessData->form;
    v11 = form->m_Items[i];
    pFormation = v11;
    if ((~v11->stat & 3) == 0)
    {
      modelobj = v11->hunit->modelobj;
      if (op_Inequality(modelobj, 0, 0)
        && get_activeSelf(pFormation->hunit->modelobj))
      {
        ID = effBTLModelGetID(&pFormation);
        BloomDown = GetBloomDown(ID);
        if (BloomDown < PPSV2_bloom_btl_Default)
      }
    }
  }
  p_static_fields = &v15->static_fields;
  static_fields = v15->static_fields;
  if (static_fields->PPSV2_bloom_btl_max != PPSV2_bloom_btl_Default)
  {
    static_fields->PPSV2_update = 1;
    (*p_static_fields)->PPSV2_bloom_btl_max = PPSV2_bloom_btl_Default;
  }
}

// 0x120fe90
void CalcBloom(void) {
  nbMainProcessData_t_o *MainProcessData;
  s32 v8;
  dds3KernelDraw_c *v9;
  struct dds3KernelDraw_StaticFields **p_static_fields;
  struct dds3KernelDraw_StaticFields *static_fields;
  struct dds3KernelDraw_StaticFields *v12;
  s32 Base_PPSV2_bloom_type;
  struct dds3KernelDraw_StaticFields *v14;
  s32 PPSV2_bloom_type;
  dds3KernelDraw_c *v17;

  else
  {
    MainProcessData = nbGetMainProcessData();
    if (!MainProcessData)
  }
  if ((MainProcessData->stat & 0x1000) == 0)
  if (PPSV2_bloom_type <= 899)
  {
    BloomDown();
    v8 = effBTLSkillCheckRun();
    if (v8)
    {
      p_static_fields = &v9->static_fields;
      static_fields = v9->static_fields;
      if (static_fields->PPSV2_bloom_type == 190)
        return;
      static_fields->PPSV2_update = 1;
      v12 = *p_static_fields;
      Base_PPSV2_bloom_type = 190;
    }
    else
    {
      v14 = v9->static_fields;
      PPSV2_bloom_type = v14->PPSV2_bloom_type;
      if (PPSV2_bloom_type == Base_PPSV2_bloom_type)
        return;
      PPSV2_update = 1;
      v12 = v17->static_fields;
    }
    v12->PPSV2_bloom_type = Base_PPSV2_bloom_type;
  }
}

// 0x120eae0
f32 CalcRadiusShadow(u32 group, f32 *aPShadow2_CamY_add) {
    nbGetMainProcessData();
    dds3GetActiveScene();
    dds3GetActiveCameraSceneBasic(0);
    dds3CameraObjectBasicGetTgtCam(0, 0, 0);
    dds3CameraObjectBasicGetFovy(0);
    effBTLModelGetID(0);
    dds3ObjectBaseCheckFlag(0, 0);
    SetLayerAll_FadeModeOn(0, 0, 0);
    SetLayerAll_FadeModeOff(0, 0);
    effBTLModelGetMarkPosition2(0, 0);
    SDF_VU0__STOREVECTOR(0);
    sdfAtan2(0, 0);
    OOYDEG(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    return 0;
}

// 0x120e420
void CalcShadow(void) {
    effBTLSkillCheckRun();
    OOYRAD(0);
    CalcRadiusShadow(0, 0);
    SDF_VU0__STOREVECTOR(0);
    sdfSin(0);
    sdfCos(0);
    SpShadow_BSONGY();
}

// 0x1210100
bool ChkNbEventRun(void) {
  nbMainProcessData_t_o *MainProcessData;

  else
  {
    MainProcessData = nbGetMainProcessData();
    if (MainProcessData)
      LODWORD(MainProcessData) = (BYTE1(MainProcessData->stat) >> 4) & 1;
  }
  return MainProcessData;
}

// 0x120f990
s32 ChkUseMarukage(s32 deveilID) {
  s32 result;
  char v3;
  char v4;
  char v5;

  if (deveilID > 178)
  {
    if (deveilID > 275)
    {
      if (deveilID > 318)
      {
        v5 = deveilID - 114;
        if ((deveilID - 370) > 0x11)
          return 0;
        result = 1;
        if (((1 << v5) & 0x30003) == 0)
          return 0;
      }
      else
      {
        v4 = deveilID - 38;
        if ((deveilID - 294) > 0x18)
          return 0;
        result = 1;
        if (((1 << v4) & 0x1000007) == 0)
          return 0;
      }
    }
    else
    {
      v3 = deveilID - 1;
      if ((deveilID - 257) > 0x12)
        return 0;
      result = 1;
      if (((1 << v3) & 0x50001) == 0)
        return 0;
    }
  }
  else
  {
    if (deveilID > 39)
      return (deveilID - 132) <= 0x2E && ((1LL << (deveilID + 124)) & 0x400000000031LL) != 0;
    if (deveilID == 14)
      return 2;
    if ((deveilID - 36) >= 3)
      return 0;
    return -1;
  }
  return result;
}

// 0x120e350
void Dai2keitai(s32 unitid) {
  if ((byte_3F59042 & 1) != 0)
  {
    if (unitid != 264)
      return;
  }
  else
  {
    if (unitid != 264)
      return;
  }
  PPSV2_update = 1;
  Base_PPSV2_bloom_type = 2322;
  PPSV2_bloom_type = 2322;
}

// 0x120e2d0
void FieldArea_Alpha(s32 fld, s32 area) {
  ShadowFld = fld;
  ShadowArea = area;
}

// 0x120fa80
f32 GetBloomDown(s32 deveilID) {
    return 0;
}

// 0x120d900
void InitShadow(void) {
  nbMisc_c *v8;
  struct nbMisc_StaticFields *static_fields;
  struct nbMisc_StaticFields *v12;
  struct nbMisc_StaticFields *v14;
  struct nbMisc_StaticFields *v16;
  struct nbMisc_StaticFields *v18;
  struct nbMisc_StaticFields *v20;
  struct nbMisc_StaticFields *v22;
  struct nbMisc_StaticFields *v24;
  struct nbMisc_StaticFields *v26;
  struct nbMisc_StaticFields *v28;
  struct nbMisc_StaticFields *v31;
  dds3KernelDraw_c *v32;
  struct dds3KernelDraw_StaticFields *v33;
  s32 PPSV2_bloom_type;

  PShadow_CamX = 0.0;
  PShadow_CamY = 7.0;
  PShadow_CamZ = -2.0;
  PShadow_RotX = 60.0;
  PShadow_RotY = 180.0;
  PShadow_CamSize = 6.0;
  PShadow_CamFar = 16.0;
  PShadow_Alp = 0.2;
  PShadow_OnOff = 1.0;
  PShadow_VecClipOnOff = 0.0;
  PShadow_YClipOnOff = 1.0;
  PShadow_ClipY = 0.0;
  PShadow2_CamX = 0.0;
  PShadow2_CamY = 7.0;
  PShadow2_CamZ = 3.0;
  PShadow2_RotX = 60.0;
  PShadow2_RotY = 0.0;
  PShadow2_CamSize = 5.0;
  PShadow2_Alp = 0.2;
  PShadow2_OnOff = 1.0;
  SetShadowMode(kernelObject, 2);
  ShadowFastE = 1;
  ShadowFastP = 1;
  PPSV2_update = 1;
  PPSV2_bloom_type = 100;
  DofOff();
  BattleMarukageAlpMul = 0.6;
  static_fields = nbMisc->static_fields;
  if (static_fields->ShadowFld == 216)
  {
    if (static_fields->ShadowArea == 3)
    {
      PShadow2_Alp = 0.4;
      PShadow_Alp = 0.4;
    }
  }
  else  PShadow2_Alp = 1.0;
  PShadow_Alp = 1.0;
  BattleMarukageAlpMul = 1.0;
  else
  {
    v12 = v8->static_fields;
    if (v12->ShadowFld != 219)
  }
  if (v12->ShadowArea != 1)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PPSV2_bloom_type = 119;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    v14 = v8->static_fields;
    if (v14->ShadowFld != 223)
  }
  v14 = nbMisc->static_fields;
  if (v14->ShadowFld != 223)
  if (v14->ShadowArea != 3)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PPSV2_bloom_type = 101;
  PShadow2_Alp = 0.4;
  PShadow_Alp = 0.4;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    v16 = v8->static_fields;
    if (v16->ShadowFld != 232)
  }
  v16 = nbMisc->static_fields;
  if (v16->ShadowFld != 232)
  if (v16->ShadowArea != 6)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PPSV2_bloom_type = 232;
  PShadow2_Alp = 0.6;
  PShadow_Alp = 0.6;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    v18 = v8->static_fields;
    if (v18->ShadowFld != 235)
  }
  v18 = nbMisc->static_fields;
  if (v18->ShadowFld != 235)
  if (v18->ShadowArea != 7)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PShadow2_Alp = 0.4;
  PShadow_Alp = 0.4;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    v20 = v8->static_fields;
    if (v20->ShadowFld != 235)
  }
  v20 = nbMisc->static_fields;
  if (v20->ShadowFld != 235)
  if (v20->ShadowArea != 3)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PShadow2_Alp = 0.4;
  PShadow_Alp = 0.4;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    v22 = v8->static_fields;
    if (v22->ShadowFld != 240)
  }
  v22 = nbMisc->static_fields;
  if (v22->ShadowFld != 240)
  if (v22->ShadowArea != 1)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PPSV2_bloom_type = 102;
  PShadow2_Alp = 0.4;
  PShadow_Alp = 0.4;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    v24 = v8->static_fields;
    if (v24->ShadowFld != 243)
  }
  v24 = nbMisc->static_fields;
  if (v24->ShadowFld != 243)
  if (v24->ShadowArea != 1)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PShadow2_Alp = 0.4;
  PShadow_Alp = 0.4;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    v26 = v8->static_fields;
    if (v26->ShadowFld != 244)
  }
  v26 = nbMisc->static_fields;
  if (v26->ShadowFld != 244)
  if (v26->ShadowArea != 3)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PShadow2_Alp = 0.6;
  PShadow_Alp = 0.6;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    v28 = v8->static_fields;
    if (v28->ShadowFld != 245)
  }
  v28 = nbMisc->static_fields;
  if (v28->ShadowFld != 245)
  if (v28->ShadowArea != 1)
  {
    if ((v8->_2.bitflags2 & 2) == 0)
  }
  PShadow2_Alp = 0.5;
  PShadow_Alp = 0.5;
  if ((v8->_2.bitflags2 & 2) == 0)
  {
    if (ShadowFld != 260)
  }
  if (ShadowFld != 260)
  PPSV2_bloom_type = 260;
  v31 = v8->static_fields;
  if (v31->ShadowFld == 261)
  {
    PShadow2_Alp = 0.8;
    PShadow_Alp = 0.8;
  }
  v33 = v32->static_fields;
  PPSV2_bloom_type = v33->PPSV2_bloom_type;
  Base_PPSV2_bloom_type = PPSV2_bloom_type;
}

// 0x120f780
void SpShadow_BSONGY(void) {
  nbMainProcessData_t_o *MainProcessData;
  s64 i;
  struct nbFormation_t_array *form;
  UnityEngine_Object_o *modelobj;
  UnityEngine_GameObject_o *v8;
  Il2CppObject *Component_object;
  FieldChrHD_o *v11;
  UnityEngine_GameObject_o *v12;
  s32 v13;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  MainProcessData = nbGetMainProcessData();
  for (i = 8; i != 20; ++i)
  {
    form = MainProcessData->form;
    pFormation = *(&form->obj.klass + i);
    if (effBTLModelGetID(&pFormation) == 269 && (~pFormation->stat & 3) == 0)
    {
      modelobj = pFormation->hunit->modelobj;
      if (op_Inequality(modelobj, 0, 0)
        && get_activeSelf(pFormation->hunit->modelobj))
      {
        v8 = pFormation->hunit->modelobj;
        Component_object = GetComponent_object_(v8);
        if (dds3ObjectBaseCheckFlag(&pFormation->basic, 0x400u))
        {
          else          v11 = Component_object;
          v12 = v8;
          v13 = 15;
        }
        v11 = Component_object;
        v12 = v8;
        v13 = 14;
        SetLayerAll2(v11, v12, v13);
        continue;
      }
    }
  }
}

// 0x120d260
void nbAddKagututiMoon(nbMainProcessData_t *data) {
  nbFormation_t_o *EventForm;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 AgeOfMoon16;
  s32 v8;

  else
  {
    EventForm = nbGetEventForm();
    if (!EventForm)
      return;
  }
  formindex = EventForm->formindex;
  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (!UnitWorkFromFormindex)
      return;
  }
  if (UnitWorkFromFormindex->id == 293)
  {
    AgeOfMoon16 = evtGetAgeOfMoon16();
    v8 = AgeOfMoon16 + 17;
    if (AgeOfMoon16 + 2 >= 0)
      v8 = AgeOfMoon16 + 2;
    evtSetAgeOfMoon(AgeOfMoon16 + 2 - (v8 & 0xFFFFFFF0), 0);
  }
}

// 0x1208c10
void nbAddOrder(s32 findex) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v7;
  struct nbFormation_t_array *v9;
  s32 orderindex;
  s16 partyindex;
  s32 v13;
  s64 i;
  struct System_SByte_array *order;
  s64 v17;
  struct System_SByte_array *v18;

  MainProcessData = nbGetMainProcessData();
  form = MainProcessData->form;
  if ((form->m_Items[findex]->stat & 1) != 0)
  {
    v7 = MainProcessData->form;
    if ((v7->m_Items[findex]->stat & 0x40) != 0)
    {
      v9 = MainProcessData->form;
      orderindex = MainProcessData->orderindex;
      if (orderindex <= 10)
      {
        partyindex = v9->m_Items[findex]->partyindex;
        v13 = orderindex + 1;
        for (i = MainProcessData->orderindex + 33LL; ; ++i)
        {
          order = MainProcessData->order;
          if (*(&order->obj.klass + i) < 0)
            break;
          v17 = i - 32;
          if (v17 >= 11)
            return;
        }
        v18 = MainProcessData->order;
        *(&v18->obj.klass + i) = partyindex;
        nbSortOrder(v13);
      }
    }
  }
}

// 0x120b8b0
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex) {
  struct datUnitWork_t_array *enemyunit;
  s64 v7;
  struct datUnitWork_t_array *v8;
  datUnitWork_t_o *v10;
  struct datUnitWork_t_array *v14;
  struct datUnitWork_t_array *v16;
  struct datUnitWork_t_array *v18;
  struct datUnitWork_t_array *v20;
  struct datUnitWork_t_array *v22;
  struct datUnitWork_t_array *v24;
  struct datUnitWork_t_array *v26;
  struct datUnitWork_t_array *v28;
  struct datUnitWork_t_array *v30;

  if ((byte_3F59032 & 1) != 0)
  {
    enemyunit = data->enemyunit;
    if (LODWORD(enemyunit->max_length))
  }
  enemyunit = data->enemyunit;
  if (!LODWORD(enemyunit->max_length))
  if ((enemyunit->m_Items[0]->flag & 1) == 0)
  {
    v7 = 0;
    v8 = data->enemyunit;
    if (!LODWORD(v8->max_length))
  }
  v14 = data->enemyunit;
  if ((v14->m_Items[1]->flag & 1) == 0)
  {
    v7 = 1;
    v8 = data->enemyunit;
    if (LODWORD(v8->max_length) > 1)
  }
  v16 = data->enemyunit;
  if ((v16->m_Items[2]->flag & 1) != 0)
  {
    v18 = data->enemyunit;
    if ((v18->m_Items[3]->flag & 1) != 0)
    {
      v20 = data->enemyunit;
      if ((v20->m_Items[4]->flag & 1) != 0)
      {
        v22 = data->enemyunit;
        if ((v22->m_Items[5]->flag & 1) != 0)
        {
          v24 = data->enemyunit;
          if ((v24->m_Items[6]->flag & 1) != 0)
          {
            v26 = data->enemyunit;
            if ((v26->m_Items[7]->flag & 1) != 0)
            {
              v28 = data->enemyunit;
              if ((v28->m_Items[8]->flag & 1) != 0)
              {
                v30 = data->enemyunit;
                if ((v30->m_Items[9]->flag & 1) != 0)
                {
                  LODWORD(v7) = -1;
                  return v7;
                }
                v7 = 9;
                v8 = data->enemyunit;
                if (LODWORD(v8->max_length) <= 9)
              }
              else
              {
                v7 = 8;
                v8 = data->enemyunit;
                if (LODWORD(v8->max_length) <= 8)
              }
            }
            else
            {
              v7 = 7;
              v8 = data->enemyunit;
              if (LODWORD(v8->max_length) <= 7)
            }
          }
          else
          {
            v7 = 6;
            v8 = data->enemyunit;
            if (LODWORD(v8->max_length) <= 6)
          }
        }
        else
        {
          v7 = 5;
          v8 = data->enemyunit;
          if (LODWORD(v8->max_length) <= 5)
        }
      }
      else
      {
        v7 = 4;
        v8 = data->enemyunit;
        if (LODWORD(v8->max_length) <= 4)
      }
    }
    else
    {
      v7 = 3;
      v8 = data->enemyunit;
      if (LODWORD(v8->max_length) <= 3)
    }
  }
  else
  {
    v7 = 2;
    v8 = data->enemyunit;
    if (LODWORD(v8->max_length) <= 2)
  }
  v10 = v8->m_Items[v7];
  datSetDevilWork(id, v10);
  v10->maxhp = Get(id, 1, 0)->maxhp;
  v10->hp = Get(id, 1, 0)->hp;
  v10->maxmp = Get(id, 1, 0)->maxmp;
  v10->mp = Get(id, 1, 0)->mp;
  v10->flag |= 2u;
  return v7;
}

// 0x120d140
s32 nbCheckDeadEvent(nbFormation_t *form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;

  formindex = form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (!UnitWorkFromFormindex)
    return 0;
  if ((UnitWorkFromFormindex->flag & 4) == 0)
  {
    id = UnitWorkFromFormindex->id;
    if ((UnitWorkFromFormindex->badstatus & 0xFFF) != 0x200)
    id = 255;
  }
  id = 0;
  if ((UnitWorkFromFormindex->badstatus & 0xFFF) == 0x200)
  if (!id)
    return 0;
  return Get(id, 0)->deadeventno;
}

// 0x120d020
s32 nbCheckDeadScript(nbFormation_t *form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;

  formindex = form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (!UnitWorkFromFormindex)
    return 0;
  if ((UnitWorkFromFormindex->flag & 4) == 0)
  {
    id = UnitWorkFromFormindex->id;
    if ((UnitWorkFromFormindex->badstatus & 0xFFF) != 0x200)
    id = 255;
  }
  id = 0;
  if ((UnitWorkFromFormindex->badstatus & 0xFFF) == 0x200)
  if (!id)
    return 0;
  return Get(id, 0)->deadscriptid;
}

// 0x120ced0
s32 nbCheckEventDead(nbFormation_t *form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;
  datDevilAI_t_o *v8;

  formindex = form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (!UnitWorkFromFormindex)
    return 0;
  if ((UnitWorkFromFormindex->flag & 4) != 0)
  {
    id = 0;
    if ((UnitWorkFromFormindex->badstatus & 0xFFF) != 0x200)
    {
      if (!id)
        return 0;
    }
  }
  else
  {
    id = UnitWorkFromFormindex->id;
    if ((UnitWorkFromFormindex->badstatus & 0xFFF) != 0x200)
  }
  id = 255;
  v8 = Get(id, 0);
  return v8->deadscriptid || v8->deadeventno != 0;
}

// 0x120c060
void nbClearCommandMemeoyRenzoku(void) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v5;
  datUnitWork_t_o *v8;
  datUnitWork_t_o *v11;

  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(0);
    if (!UnitWorkFromFormindex)
  }
  if (UnitWorkFromFormindex->prevtarea == 2)
  {
    *&UnitWorkFromFormindex->prevtarea = -1;
  }
  v5 = nbGetUnitWorkFromFormindex(1);
  if (!v5)
  if (v5->prevtarea == 2)
  {
    *&v5->prevtarea = -1;
  }
  v8 = nbGetUnitWorkFromFormindex(2);
  if (!v8)
  if (v8->prevtarea == 2)
  {
    *&v8->prevtarea = -1;
  }
  v11 = nbGetUnitWorkFromFormindex(3);
  if (!v11)
    return;
  if (v11->prevtarea == 2)
    *&v11->prevtarea = -1;
}

// 0x120a3d0
void nbDrawCylinder(sdfDrawTag_t *tag, sdfVector4_t pos, sdfVector4_t rot, sdfVector4_t cen, f32 r, f32 scl, f32 h) {
  ;
}

// 0x120a6b0
void nbDrawNumber(sdfTexHandle_t *tex, u32 num, s32 x, s32 y, u32 c, s32 mod, nbFormation_t *form, s32 number) {
    GetHitNum(0, 0);
    SDF_VU0__Retdds3ColorItoF(0, 0);
    Set(0, 0);
}

// 0x120a6a0
void nbDrawNumber1(sdfTexHandle_t *tex, s32 num, s32 x, s32 y, u32 c) {
  ;
}

// 0x120a3e0
void nbDrawTargetCursor(nbMainProcessData_t *data, nbFormation_t *form, sdfDrawTag_t *tag, s32 curidx) {
    GetMainCamera(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    GetTargetMark2D(0);
}

// 0x120a200
void nbGetFormCenter(nbFormation_t *form) {
  SDF_VU0__LOADVECTOR(form->orgrot);
  ToMatrix();
  SDF_VU0__LOADVECTOR(form->center);
  SDF_VU0__SCALEVECTOR(form->scl);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B(form->orgpos);
  SDF_VU0__ADDVECTOR();
}

// 0x120a270
void nbGetFormForward(nbFormation_t *form) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
}

// 0x120a080
void nbGetFormSphereTop(nbFormation_t *form) {
  f32 v3;

  SDF_VU0__LOADVECTOR(form->center);
  SDF_VU0__SCALEVECTOR(form->scl);
  SDF_VU0__LOADVECTOR_B(form->pos);
  SDF_VU0__ADDVECTOR();
  v3 = SDF_VU0__GETVECTOR_Y() - (form->r * form->scl);
  SDF_VU0__SETVECTOR_Y(v3);
}

// 0x120a0f0
void nbGetFormTop(nbFormation_t *form) {
  sdfModelRootNode_t_o *modelRoot;
  f32 v4;

  if ((~form->stat & 3) != 0)
  modelRoot = form->hunit->Model->modelRoot;
  if (!sdfModelGetMarkPosUnity(modelRoot, 2))
  {
    SDF_VU0__LOADVECTOR(form->center);
    SDF_VU0__SCALEVECTOR(form->scl);
    SDF_VU0__LOADVECTOR_B(form->pos);
    SDF_VU0__ADDVECTOR();
    v4 = SDF_VU0__GETVECTOR_Y() - (form->r * form->scl);
    SDF_VU0__SETVECTOR_Y(v4);
  }
}

// 0x120ad20
s32 nbGetItemSkillNo(nbActionProcessData_t *a, s32 itemid) {
  s32 result;

  result = datGetItemSkillNo(itemid);
  if (itemid == 1)
    return a->massuruid;
  return result;
}

// 0x120b540
s32 nbGetJyokyoMes(nbMainProcessData_t *data, s32 jyokyomes) {
  return ((data->stat >> 3) & 1) + jyokyomes;
}

// 0x120b550
u32 nbGetModelColor(nbFormation_t *form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u16 badstatus;
  u32 v7;
  s32 v8;
  u32 result;

  formindex = form->formindex;
  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (!UnitWorkFromFormindex)
      return -2139062144;
  }
  badstatus = UnitWorkFromFormindex->badstatus;
  v7 = badstatus & 0xFFF;
  if (v7 <= 0x20)
  {
    if (v7 <= 8)
    {
      switch (badstatus & 0xFFF)
      {
        case 1:
          result = effBTLSystemGetRGBA(1u);
          break;
        case 2:
          result = effBTLSystemGetRGBA(2u);
          break;
        case 3:
          return -2139062144;
        case 4:
          result = effBTLSystemGetRGBA(3u);
          break;
        default:
          if (v7 != 8)
            return -2139062144;
          result = effBTLSystemGetRGBA(4u);
          break;
      }
    }
    else if ((badstatus & 0xFFF) == 0x10)
    {
      return effBTLSystemGetRGBA(5u);
    }
    else
    {
      if ((badstatus & 0xFFF) != 0x20)
        return -2139062144;
      return effBTLSystemGetRGBA(6u);
    }
  }
  else if (v7 <= 0x80)
  {
    if ((badstatus & 0xFFF) == 0x40)
    {
      return effBTLSystemGetRGBA(7u);
    }
    else
    {
      if ((badstatus & 0xFFF) != 0x80)
        return -2139062144;
      return effBTLSystemGetRGBA(8u);
    }
  }
  else
  {
    v8 = badstatus & 0xFFF;
    if (v8 != 256)
    {
      if (v8 == 512)
      {
        return effBTLSystemGetRGBA(0xAu);
      }
      if (v7 == 1024)
      {
        return effBTLSystemGetRGBA(0xBu);
      }
      return -2139062144;
    }
    return effBTLSystemGetRGBA(9u);
  }
  return result;
}

// 0x120b0c0
s32 nbGetNakama(datUnitWork_t *s) {
    datCheckStockFull();
    datSearchDevilStock(0);
    datSetDevilWork(0, 0);
    fclEncycRegist(0, 0, 0);
    Unlock_16599376(0);
    return 0;
}

// 0x120bcc0
s32 nbGetRandamStock(void) {
  u64 *v2;
  u64 v3;
  u32 v4;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v9;
  struct datUnitWork_t_array *v12;
  struct datUnitWork_t_array *v15;
  struct datUnitWork_t_array *v18;
  char *v21;
  u32 RandIntA;

  v2 = NewSpecific(s32, 0x10u);
  v3 = 0;
  v4 = 0;
  do
  {
    unitwork = DDS3_GBWK->unitwork;
    if ((unitwork->m_Items[v3]->flag & 1) != 0)
    {
      v9 = DDS3_GBWK->unitwork;
      if ((v9->m_Items[v3]->flag & 2) == 0)
      {
        v12 = DDS3_GBWK->unitwork;
        if ((v12->m_Items[v3]->flag & 0x10) == 0)
        {
          v15 = DDS3_GBWK->unitwork;
          if ((v15->m_Items[v3]->badstatus & 0xFFF) != 0x800)
          {
            v18 = DDS3_GBWK->unitwork;
            if (v18->m_Items[v3]->hp)
            {
              v21 = v2 + 4 * v4++;
              *(v21 + 8) = v3;
            }
          }
        }
      }
    }
    ++v3;
  }
  while (v3 != 16);
  if (!v4)
    return -1;
  RandIntA = dds3GetRandIntA(v4, StringLiteral_416);
  return *(v2 + RandIntA + 8);
}

// 0x120a3c0
void nbGetSphere(sdfDrawTag_t *tag, sdfVector4_t pos, sdfVector4_t rot, sdfVector4_t cen, f32 r, f32 scl) {
  ;
}

// 0x120a8c0
void nbGetTargetTypeRuleArea(nbActionProcessData_t *a, datUnitWork_t *work, s32 *ctype, s32 *crule, s32 *carea, s32 rev) {
  s16 nowcommand;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 nowindex;
  s32 ItemSkillNo;
  struct nbMainProcessData_t_o *data;
  datNormalSkill_c *v20;
  struct datNormalSkill_t_array *tbl;
  s32 targettype;
  struct datNormalSkill_t_array *v24;
  s32 targetarea;
  s32 v27;
  struct datNormalSkill_t_array *v28;
  struct datNormalSkill_t_array *v30;
  u8 targetrule;
  struct datNormalSkill_t_array *v33;
  u8 v35;
  s32 *v36;
  struct datNormalSkill_t_array *v37;
  s32 v38;
  s32 v40;
  s32 v41;
  s32 v42;
  struct datNormalSkill_t_array *v43;
  u8 v45;
  u8 v46;
  s32 v47;
  s32 *v48;
  s32 *v49;

  nowcommand = work->nowcommand;
  v14 = 0;
  v15 = 0;
  v16 = 2;
  switch (nowcommand)
  {
    case 0:
      if (rev)
        v16 = 1;
      else
        v16 = 2;
      v14 = 2 * (rev != 0);
      v15 = nbHatudoCheckSkill(work, 304) != 0 && rev == 0;
      break;
    case 1:
    case 5:
      nowindex = work->nowindex;
      if (nowcommand != 1)
      {
        ItemSkillNo = datGetItemSkillNo(nowindex);
        if (nowindex == 1)
          nowindex = a->massuruid;
        else
          nowindex = ItemSkillNo;
      }
      targettype = tbl->m_Items[nowindex]->targettype;
      if (targettype == 2)
        v15 = 2;
      else
        v15 = targettype == 1;
      v24 = tbl;
      targetarea = v24->m_Items[nowindex]->targetarea;
      if (rev)
        v27 = 2;
      else
        v27 = 1;
      v47 = v27;
      v28 = tbl;
      v46 = v28->m_Items[nowindex]->targetarea;
      v30 = tbl;
      targetrule = v30->m_Items[nowindex]->targetrule;
      v33 = tbl;
      v35 = v33->m_Items[nowindex]->targetrule;
      v48 = crule;
      v49 = ctype;
      if ((v20->_2.bitflags2 & 2) != 0)
      {
        v36 = carea;
      }
      else
      {
        v36 = carea;
      }
      v37 = tbl;
      v38 = v35 & 2;
      v40 = v37->m_Items[nowindex]->targetrule & 4;
      v41 = v38 | targetrule & 1;
      v42 = v41 | v40;
      v43 = tbl;
      v16 = (targetarea << 31 >> 31) & v47 | v46 & 2;
      v45 = v43->m_Items[nowindex]->targetrule;
      carea = v36;
      crule = v48;
      ctype = v49;
      v14 = v42 | v45 & 8;
      break;
    case 4:
      break;
    case 6:
      data = a->data;
      if ((data->stat & 8) != 0)
      v15 = 0;
      v16 = 1;
      if (data->playerpcnt >= 4)
        v14 = 2;
      else
        v14 = 12;
      break;
    default:
      v16 = 0;
      v14 = 0;
      v15 = 0;
      break;
  }
  *ctype = v15;
  *crule = v14;
  *carea = v16;
}

// 0x120cd60
s32 nbGetUnitID(datUnitWork_t *work) {
  s32 id;

  if (work)
  {
    if ((work->flag & 4) != 0)
      id = 0;
    else
      id = work->id;
    if ((work->badstatus & 0xFFF) == 0x200)
      LODWORD(work) = 255;
    else
      LODWORD(work) = id;
  }
  return work;
}

// 0x120cd90
datUnitVisual_t *nbGetUnitVisual(datUnitWork_t *work) {
    Get(0);
    return 0;
}

// 0x120d380
bool nbMisc_TableAccessInit(void) {
  nbMisc_c *v2;
  struct nbMisc_StaticFields **p_static_fields;
  struct nbMisc_StaticFields *static_fields;
  s32 nbMisc_dmy_idx;
  datUnitVisual_t_o *v6;
  bool result;
  s32 v8;
  struct nbMisc_StaticFields *v10;
  struct datEncountPack_t_array *tbl;
  struct datEncountTbl_s_array *enctable;
  struct datEncountRitu_s_array *ritu;
  u32 sensei;
  struct datEncount_t_array *v19;
  s32 flag;
  u32 v22;
  u32 v24;
  datDevilFormat_t_o *v25;
  s32 level;
  struct fclSkillParam_t_array *Event;
  s32 TargetLevel;
  struct datSpecialSkill_t_array *v33;
  s32 n;
  struct datNormalSkill_t_array *v37;
  s32 cost;

  p_static_fields = &v2->static_fields;
  static_fields = v2->static_fields;
  switch (static_fields->nbMisc_dmy_step)
  {
    case 0:
      static_fields->nbMisc_dmy_idx = 0;
      nbMisc_dmy_idx = (*p_static_fields)->nbMisc_dmy_idx;
      v6 = Get2(nbMisc_dmy_idx);
      result = 0;
      nbMisc_datDevilVisual_dmy = v6->formsize;
    case 1:
      static_fields->nbMisc_dmy_idx += 32;
      v8 = (*p_static_fields)->nbMisc_dmy_idx;
      nbMisc_datDevilVisual_dmy = nbMisc_datDevilVisual_dmy
                                                                + Get2(v8)->formsize;
      v10 = nbMisc->static_fields;
      if (v10->nbMisc_dmy_idx < 352)
        return 0;
      result = 0;
      ++v10->nbMisc_dmy_step;
      return result;
    case 2:
      enctable = tbl->m_Items[0]->enctable;
      ritu = enctable->m_Items[0]->ritu;
      sensei = ritu->m_Items[0]->sensei;
      result = 0;
      nbMisc_datEncountPack_dmy = sensei;
      v10 = nbMisc->static_fields;
    case 3:
      v19 = tbl;
      flag = v19->m_Items[0]->flag;
      nbMisc_datEncount_dmy = flag;
    case 4:
      v22 = Get(0, 0, 0, 0);
      v24 = v22;
      nbMisc_datAisyo_dmy = v24;
    case 5:
      v25 = Get(0, 1, 0);
      level = v25->level;
      nbMisc_datDevilFormat_dmy = level;
    case 6:
      Event = Get(0, 0)->Event;
      TargetLevel = Event->m_Items[0]->TargetLevel;
      nbMisc_tblSkill_dmy = TargetLevel;
    case 7:
      v33 = tbl;
      n = v33->m_Items[0]->n;
      datSpecialSkill_dmy = n;
    case 8:
      v37 = tbl;
      cost = v37->m_Items[0]->cost;
      datNormalSkill_dmy = cost;
      nbMisc_dmy_step = 0;
      return 1;
    default:
      return 0;
  }
}

// 0x1209b90
s32 nbScreenOffset(sdfIVector4_t **pos, nbKoukaPacket_t *p) {
  u32 ID;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  f32 v15;
  UnityEngine_Camera_o *v16;
  f32 v17;
  f32 w;
  f32 v19;
  f32 width;
  s32 height;
  struct GlobalData_StaticFields *static_fields;
  f32 v23;
  struct System_Int32_array *pm;
  struct System_Int32_array *v26;
  UnityEngine_Vector4_o v28;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector3_o v30;
  UnityEngine_Vector3_o v31;
  UnityEngine_Vector4_o v32;

  *&v28.x = 0;
  *&v28.z = 0;
  pFormation = 0;
  else  if (!evtBitCheck(3712))
  {
    pFormation = effBTLSkillGetInvokeFormation(0);
    ID = effBTLModelGetID(&pFormation);
    if (p)
    {
      if (ID == 192 && p->time < 6u)
        return 0;
    }
  }
  *&v28.x = 0;
  *&v28.z = 0;
  SDF_VU0__STOREVECTOR(&v28);
  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  v15 = v28.x / 100.0;
  v16 = Component_object;
  v17 = v28.y / -100.0;
  w = v28.w;
  v28.x = v28.x / 100.0;
  v28.y = v28.y / -100.0;
  v19 = v28.z / 100.0;
  v28.z = v28.z / 100.0;
  v32.x = v15;
  v32.y = v17;
  v32.z = v19;
  v32.w = w;
  v31 = op_Implicit_8738992(v32);
  v30 = WorldToScreenPoint_27174640(v16, v31);
  width = get_width(0);
  height = get_height(0);
  static_fields = GlobalData->static_fields;
  v23 = static_fields->screen_hei / height;
  pm = (*pos)->pm;
  pm->m_Items[0] = ((v30.x - (width * 0.5)) * (static_fields->screen_wid / width));
  v26 = (*pos)->pm;
  v26->m_Items[1] = ((v30.y - (height * 0.5)) * v23);
  return 1;
}

// 0x120b3e0
void nbSetDevilNameMes(s32 hmsg, s32 no, datUnitWork_t *work) {
  s32 id;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;

  id = work->id;
  if (id)
  {
    v8 = hmsg;
    v9 = no;
    v10 = id;
    v11 = 1;
  }
  else
  {
    v11 = 10;
    v8 = hmsg;
    v9 = 0;
    v10 = 0;
  }
  itfMesMngSetVar(v8, v9, v10, v11);
}

// 0x120c210
void nbSetEnemyStartData(nbMainProcessData_t *data, s32 enc) {
  nbSetEnemyStartData_0(data, enc);
  nbSetEnemyStartData_1(data, enc);
}

// 0x120c290
void nbSetEnemyStartData_0(nbMainProcessData_t *data, s32 enc) {
  struct nbFormation_t_array *form;
  struct nbParty_t_array *party;
  struct nbFormation_t_array *v9;
  struct nbParty_t_array *v11;
  struct nbFormation_t_array *v13;
  struct nbParty_t_array *v15;
  struct nbFormation_t_array *v17;
  struct nbParty_t_array *v19;
  struct nbFormation_t_array *v21;
  struct nbParty_t_array *v23;
  struct nbFormation_t_array *v25;
  struct nbParty_t_array *v27;
  struct nbFormation_t_array *v29;
  struct nbParty_t_array *v31;
  struct nbFormation_t_array *v33;
  struct nbParty_t_array *v35;
  struct nbFormation_t_array *v37;
  struct nbParty_t_array *v39;
  struct nbFormation_t_array *v41;
  struct nbParty_t_array *v43;
  u64 v45;
  s32 v46;
  struct System_UInt16_array *devil;
  struct System_UInt16_array *v50;
  s32 v52;
  struct datUnitWork_t_array *enemyunit;
  datUnitWork_t_o *v55;
  struct datUnitWork_t_array *v56;
  datUnitWork_t_o *v58;
  struct System_UInt16_array *v60;
  s32 v62;
  struct datUnitWork_t_array *v63;
  datUnitWork_t_o *v65;
  struct System_UInt16_array *v66;
  struct datUnitWork_t_array *v68;
  datUnitWork_t_o *v70;
  struct System_UInt16_array *v71;
  struct datUnitWork_t_array *v73;
  datUnitWork_t_o *v75;
  struct System_UInt16_array *v76;
  struct datUnitWork_t_array *v78;
  datUnitWork_t_o *v80;
  nbMainProcessData_t_o *dataa;

  dataa = data;
  form = data->form;
  form->m_Items[4]->stat = 512;
  party = data->party;
  party->m_Items[4]->flag = 0;
  v9 = data->form;
  v9->m_Items[5]->stat = 512;
  v11 = data->party;
  v11->m_Items[5]->flag = 0;
  v13 = data->form;
  v13->m_Items[6]->stat = 512;
  v15 = data->party;
  v15->m_Items[6]->flag = 0;
  v17 = data->form;
  v17->m_Items[7]->stat = 512;
  v19 = data->party;
  v19->m_Items[7]->flag = 0;
  v21 = data->form;
  v21->m_Items[8]->stat = 512;
  v23 = data->party;
  v23->m_Items[8]->flag = 0;
  v25 = data->form;
  v25->m_Items[9]->stat = 512;
  v27 = data->party;
  v27->m_Items[9]->flag = 0;
  v29 = data->form;
  v29->m_Items[10]->stat = 512;
  v31 = data->party;
  v31->m_Items[10]->flag = 0;
  v33 = data->form;
  v33->m_Items[11]->stat = 512;
  v35 = data->party;
  v35->m_Items[11]->flag = 0;
  v37 = data->form;
  v37->m_Items[12]->stat = 512;
  v39 = data->party;
  v39->m_Items[12]->flag = 0;
  v41 = data->form;
  v41->m_Items[13]->stat = 512;
  v43 = data->party;
  v43->m_Items[13]->flag = 0;
  v45 = 0;
  v46 = 0;
  do
  {
    devil = Get(enc, 0)->devil;
    if (devil->m_Items[v45])
    {
      v50 = Get(enc, 0)->devil;
      v52 = v50->m_Items[v45];
      enemyunit = dataa->enemyunit;
      v55 = enemyunit->m_Items[v46];
      datSetDevilWork(v52, v55);
      v56 = dataa->enemyunit;
      v58 = v56->m_Items[v46];
      v60 = Get(enc, 0)->devil;
      v62 = v60->m_Items[v45];
      v58->maxhp = Get(v62, 1, 0)->maxhp;
      v63 = dataa->enemyunit;
      v65 = v63->m_Items[v46];
      v66 = Get(enc, 0)->devil;
      v65->hp = Get(v66->m_Items[v45], 1, 0)->hp;
      v68 = dataa->enemyunit;
      v70 = v68->m_Items[v46];
      v71 = Get(enc, 0)->devil;
      v70->maxmp = Get(v71->m_Items[v45], 1, 0)->maxmp;
      v73 = dataa->enemyunit;
      v75 = v73->m_Items[v46];
      v76 = Get(enc, 0)->devil;
      v75->mp = Get(v76->m_Items[v45], 1, 0)->mp;
      v78 = dataa->enemyunit;
      v80 = v78->m_Items[v46];
      v80->flag |= 2u;
      nbAddUnitStock(&dataa, 1, v46++, v45 + 4);
    }
    ++v45;
  }
  while (v45 != 10);
}

// 0x120c9c0
void nbSetEnemyStartData_1(nbMainProcessData_t *data, s32 enc) {
  datEncount_t_o *v5;
  nbMainProcessData_t_o *v7;
  s32 maxcall;
  nbMainProcessData_t_o *dataa;

  dataa = data;
  nbSetEnemyFormation(&dataa);
  v5 = Get(enc, 0);
  v7 = dataa;
  if (v5->maxcall)
  {
    maxcall = Get(enc, 0)->maxcall;
  }
  else
  {
    maxcall = -1;
  }
  v7->nakamayobi = maxcall;
}

// 0x120b490
void nbSetJyokyoMes(nbActionProcessData_t **a, s32 jyokyomes, s32 var_id, s32 var_ind) {
  nbActionProcessData_t_o *v9;
  struct nbMainProcessData_t_o *data;

  v9 = *a;
  data = (*a)->data;
  v9->jyokyomes = ((data->stat >> 3) & 1) + jyokyomes;
  (*a)->jyo_varid = var_id;
  (*a)->jyo_varind = var_ind;
}

// 0x1209880
void nbSetNextOrder(void) {
  nbMainProcessData_t_o *MainProcessData;
  s32 orderindex;
  s8 v5;
  s32 v6;
  nbMainProcessData_t_o *v7;
  struct System_SByte_array *order;
  struct System_SByte_array *v11;

  MainProcessData = nbGetMainProcessData();
  orderindex = MainProcessData->orderindex;
  if (orderindex < 0)
  v5 = orderindex + 1;
  v6 = (orderindex + 1);
  v7 = MainProcessData;
  MainProcessData->orderindex = v5;
  if (v6 > 11)
  {
    nbSetOrder();
  }
  else
  {
    while (1)
    {
      order = MainProcessData->order;
      if ((order->m_Items[v6] & 0x80000000) == 0)
        break;
      v6 = ++MainProcessData->orderindex;
      if (v6 >= 12)
    }
  }
  v11 = v7->order;
  v7->activeunit = v11->m_Items[v7->orderindex];
}

// 0x120adb0
void nbSetNormalSkill0(datUnitWork_t *work) {
  struct datSkill_t_array *v4;
  datSkill_t_o *v7;
  struct datNormalSkill_t_array *v8;
  datNormalSkill_t_o *v10;
  datNormalSkillVisual_t_o *v11;
  s32 id;
  u8 attackcnt;
  s8 attackattr;
  s64 nowindex;
  struct datSkill_t_array *tbl;
  struct datNormalSkill_t_array *v21;
  s64 v22;
  s32 v23;

  if (work->nowcommand == 1)
  {
    nowindex = work->nowindex;
    if ((nowindex & 0xFFFC) != 0xA4)
      return;
    v7 = tbl->m_Items[nowindex];
    v21 = tbl;
    v22 = work->nowindex;
    v23 = work->nowindex;
    v10 = v21->m_Items[v22];
    v11 = Get(v23, 0);
    if ((work->flag & 4) == 0)
    {
      id = work->id;
      attackcnt = Get(id, 1, 0)->attackcnt;
      attackattr = Get(work->id, 1, 0)->attackattr;
      Get(work->id, 1, 0);
      if (!v10)
    }
  }
  else
  {
    if (work->nowcommand)
      return;
    v4 = tbl;
    v7 = v4->m_Items[0];
    v8 = tbl;
    v10 = v8->m_Items[0];
    v11 = Get(0, 0);
    if (nbHatudoCheckSkill(work, 304))
    {
      v10->targettype = 1;
      if ((work->flag & 4) == 0)
    }
    else
    {
      v10->targettype = 0;
      if ((work->flag & 4) == 0)
    }
  }
  attackattr = 0;
  attackcnt = 1;
  if (v10)
  {
    v7->skillattr = attackattr;
    v10->targetcntmin = attackcnt;
    v10->targetcntmax = attackcnt;
    v11->animetype = 0;
  }
  Write(StringLiteral_21488, 0);
}

// 0x12097b0
void nbSetOrder(void) {
    nbGetMainProcessData();
    nbSetOrderSide(0);
}

// 0x12091e0
void nbSetOrderSide(s32 side) {
  nbMainProcessData_t_o *MainProcessData;
  struct System_SByte_array *order;
  nbMainProcessData_t_o *v6;
  struct System_SByte_array *v8;
  struct System_SByte_array *v10;
  struct System_SByte_array *v12;
  struct System_SByte_array *v14;
  struct System_SByte_array *v16;
  struct System_SByte_array *v18;
  struct System_SByte_array *v20;
  struct System_SByte_array *v22;
  struct System_SByte_array *v24;
  struct System_SByte_array *v26;
  struct System_SByte_array *v28;
  s64 v30;
  s64 i;
  struct nbParty_t_array *party;
  u64 v33;
  struct nbParty_t_array *v35;
  struct System_SByte_array *v37;
  s64 v38;
  struct nbParty_t_array *v40;
  struct nbParty_t_array *v41;
  struct System_SByte_array *v42;
  struct nbParty_t_array *v44;
  struct nbParty_t_array *v48;
  struct System_SByte_array *v50;
  char *v52;
  struct nbParty_t_array *v53;
  struct nbParty_t_array *v55;
  struct System_SByte_array *v57;
  char *v59;
  struct nbParty_t_array *v60;
  struct nbParty_t_array *v61;
  struct System_SByte_array *v62;
  struct System_SByte_array *v66;
  s16 v68;

  MainProcessData = nbGetMainProcessData();
  order = MainProcessData->order;
  v6 = MainProcessData;
  order->m_Items[0] = -1;
  v8 = MainProcessData->order;
  v8->m_Items[1] = -1;
  v10 = MainProcessData->order;
  v10->m_Items[2] = -1;
  v12 = MainProcessData->order;
  v12->m_Items[3] = -1;
  v14 = MainProcessData->order;
  v14->m_Items[4] = -1;
  v16 = MainProcessData->order;
  v16->m_Items[5] = -1;
  v18 = MainProcessData->order;
  v18->m_Items[6] = -1;
  v20 = MainProcessData->order;
  v20->m_Items[7] = -1;
  v22 = MainProcessData->order;
  v22->m_Items[8] = -1;
  v24 = MainProcessData->order;
  v24->m_Items[9] = -1;
  v26 = MainProcessData->order;
  v26->m_Items[10] = -1;
  v28 = MainProcessData->order;
  v28->m_Items[11] = -1;
  MainProcessData->orderindex = -1;
  if (side)
  {
    LODWORD(v30) = 0;
    for (i = 8; i != 18; ++i)
    {
      party = MainProcessData->party;
      v33 = i - 4;
      if ((*(*(&party->obj.klass + i) + 16LL) & 1) != 0)
      {
        v35 = MainProcessData->party;
        if ((*(*(&v35->obj.klass + i) + 16LL) & 0x20) == 0)
        {
          v37 = MainProcessData->order;
          v38 = v30;
          LODWORD(v30) = v30 + 1;
          v37->m_Items[v38] = v33;
        }
      }
    }
  }
  v40 = MainProcessData->party;
  if ((v40->m_Items[0]->flag & 1) == 0)
  v41 = MainProcessData->party;
  if ((v41->m_Items[0]->flag & 0x20) != 0)
  {
    v30 = 0;
    v44 = MainProcessData->party;
    if ((v44->max_length & 0xFFFFFFFE) == 0)
  }
  else
  {
    v42 = MainProcessData->order;
    v42->m_Items[0] = 0;
    v30 = 1;
    v44 = MainProcessData->party;
  }
  if ((v44->m_Items[1]->flag & 1) != 0)
  {
    v48 = MainProcessData->party;
    if ((v48->m_Items[1]->flag & 0x20) == 0)
    {
      v50 = MainProcessData->order;
      v52 = v50 + v30;
      v30 = (v30 + 1);
      v52[32] = 1;
    }
  }
  v53 = MainProcessData->party;
  if ((v53->m_Items[2]->flag & 1) != 0)
  {
    v55 = MainProcessData->party;
    if ((v55->m_Items[2]->flag & 0x20) == 0)
    {
      v57 = MainProcessData->order;
      v59 = v57 + v30;
      v30 = (v30 + 1);
      v59[32] = 2;
    }
  }
  v60 = MainProcessData->party;
  if ((v60->m_Items[3]->flag & 1) != 0)
  {
    v61 = MainProcessData->party;
    if ((v61->m_Items[3]->flag & 0x20) == 0)
    {
      v62 = MainProcessData->order;
      v62->m_Items[v30] = 3;
    }
  }
  if (v30 < 1)
  {
    MainProcessData->orderindex = -1;
    v68 = -1;
  }
  MainProcessData->orderindex = 0;
  nbSortOrder(0);
  v66 = v6->order;
  v68 = v66->m_Items[v6->orderindex];
  v6->activeunit = v68;
}

// 0x120cab0
void nbSetPlayerStartData(nbMainProcessData_t *data) {
    nbAddUnitStock(0, 0, 0, 0);
    nbSetPlayerFormation(0, 0);
}

// 0x120bf90
void nbSetRenzokuEncount(s32 enc) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v5;
  s32 formationtype;

  MainProcessData = nbGetMainProcessData();
  MainProcessData->encno = enc;
  v5 = MainProcessData;
  formationtype = Get(enc, 0)->formationtype;
  v5->endtype = 0;
  v5->activeunit = -1;
  v5->orderindex = -1;
  v5->turn = 0;
  *&v5->nextphase = 0;
  v5->formationtype = formationtype;
  *&v5->previndex = 0xFFFF;
}

// 0x1208dd0
void nbSortOrder(s32 start) {
    nbGetMainProcessData();
    nbGetUnitWorkPointer(0, 0);
    datGetParam(0, 0);
}

// 0x1209e70
void nbToCurrectClipOffsetForOrg(sdfIVector4_t **pos) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  f32 v8;
  UnityEngine_Camera_o *v9;
  f32 v10;
  f32 w;
  f32 v12;
  s32 screen_wid;
  s32 width;
  f32 v15;
  s32 screen_hei;
  f32 v17;
  f32 v18;
  struct GlobalData_StaticFields *static_fields;
  struct System_Int32_array *pm;
  f32 v21;
  struct System_Int32_array *v23;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector3_o v26;
  UnityEngine_Vector3_o v27;
  UnityEngine_Vector4_o v28;

  *&v25.x = 0;
  *&v25.z = 0;
  SDF_VU0__STOREVECTOR(&v25);
  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  v8 = v25.x / 100.0;
  v9 = Component_object;
  v10 = v25.y / -100.0;
  w = v25.w;
  v25.x = v25.x / 100.0;
  v25.y = v25.y / -100.0;
  v12 = v25.z / 100.0;
  v25.z = v25.z / 100.0;
  v28.x = v8;
  v28.y = v10;
  v28.z = v12;
  v28.w = w;
  v27 = op_Implicit_8738992(v28);
  v26 = WorldToScreenPoint_27174640(v9, v27);
  width = get_width(0);
  v15 = screen_wid;
  v17 = v26.x * (v15 / width);
  v18 = screen_hei / get_height(0);
  static_fields = GlobalData->static_fields;
  pm = (*pos)->pm;
  v21 = 3584.0 / static_fields->screen_hei;
  pm->m_Items[0] = (v17 * (8192.0 / static_fields->screen_wid)) >> 4;
  v23 = (*pos)->pm;
  v23->m_Items[1] = ((v26.y * v18) * v21) >> 3;
}

// 0x1209a00
void nbUpdateOrder(void) {
  nbMainProcessData_t_o *MainProcessData;
  s64 i;
  struct System_SByte_array *order;
  u64 v5;
  struct System_SByte_array *v7;
  struct nbParty_t_array *party;
  s64 v10;
  struct System_SByte_array *v12;
  struct nbParty_t_array *v13;
  s64 v15;
  struct System_SByte_array *v17;

  MainProcessData = nbGetMainProcessData();
  for (i = 32; i != 44; ++i)
  {
    order = MainProcessData->order;
    v5 = i - 32;
    if ((*(&order->obj.klass + i) & 0x80000000) == 0)
    {
      v7 = MainProcessData->order;
      party = MainProcessData->party;
      v10 = *(&v7->obj.klass + i);
      if ((party->m_Items[v10]->flag & 1) == 0)
      v12 = MainProcessData->order;
      v13 = MainProcessData->party;
      v15 = *(&v12->obj.klass + i);
      if ((v13->m_Items[v15]->flag & 0x20) != 0)
      {
        v17 = MainProcessData->order;
        *(&v17->obj.klass + i) = -1;
      }
    }
  }
}
