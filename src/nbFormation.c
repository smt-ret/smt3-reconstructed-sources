#include "types.h"

typedef struct datUnitVisual_s datUnitVisual_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct effBTLSysHandle_t effBTLSysHandle_t;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static bool nb1st;
static f32 nbFormPlayerInterval;
static f32 nbFormEnemyInterval;

u8 Get(s32 id);
void Mult(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
s32 SetForm(nbEventProcessData_t *ed);
s32 datCheckDying(datUnitWork_t *work);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
u32 effBTLModelGetID(nbFormation_t **pFormation);
effBTLSysHandle_t *effBTLSystemCreate(nbFormation_t **pFormation, u32 id);
void effBTLSystemDelete2(effBTLSysHandle_t **hEffBTLSys);
u32 effBTLSystemGetID(effBTLSysHandle_t **hEffBTLSys);
void mdlSetMotionSpeedAnimator(void *mAnimator, f32 speed);
void mdlShowUnity(dds3ModelHandle_t **aHandle, void *modelobj, nbFormation_t *form);
void nbCopyFormation(nbMainProcessData_t **data, s32 sindex, s32 dindex);
void nbDelAllMojiNumEffectKoukaPacket(nbFormation_t **form, s32 motno);
void nbFormDispOff(s32 formindex);
void nbFormDispOn(s32 formindex);
void nbFormatFormation(nbMainProcessData_t **data, s32 index);
void nbFormation_t__Clear(nbFormation_t *this);
void nbFormation_t__Copy(nbFormation_t *this, nbFormation_t *data);
nbMainProcessData_t *nbGetMainProcessData(void);
datUnitVisual_t *nbGetUnitVisual(datUnitWork_t *work);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
void nbResetFormPosRot(nbFormation_t **form);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbSetFormRot(nbFormation_t **form, sdfVector4_t rot, bool look2);
void nbSetPartyFormation(nbMainProcessData_t **data, u32 group);
void nbSetUnitMotion(nbFormation_t **form, s32 motion2, s32 mode, f32 ritu);
f32 sdfAtan(f32 aX);
f32 sdfCos(f32 aRadius);
f32 sdfSin(f32 aRadius);

// 0x196d540
void mdlHideUnity(dds3ModelHandle_t **aHandle, void *modelobj) {
  if (op_Inequality(modelobj, 0, 0) && get_activeSelf(modelobj))
    SetActive(modelobj, 0, 0);
  (*aHandle)->stat |= 1u;
}

// 0x196d4b0
void mdlSetMotionSpeed(dds3ModelHandle_t *aHandle, f32 speed) {
  struct sdfMotionCtrlr_t_o *motionCtrlr;

  if (aHandle)
  {
    motionCtrlr = aHandle->motionCtrlr;
    if (motionCtrlr)
      motionCtrlr->speed = speed;
  }
}

// 0x196d5f0
void mdlShowUnity(dds3ModelHandle_t **aHandle, void *modelobj, nbFormation_t *form) {
    nbGetUnitWorkFromFormindex(0);
    Get(0);
    datCheckDying(0);
}

// 0x196e010
void nbAllFormDispOff(void) {
  nbFormDispOff(0);
  nbFormDispOff(1);
  nbFormDispOff(2);
  nbFormDispOff(3);
  nbFormDispOff(4);
  nbFormDispOff(5);
  nbFormDispOff(6);
  nbFormDispOff(7);
  nbFormDispOff(8);
  nbFormDispOff(9);
  nbFormDispOff(10);
  nbFormDispOff(11);
  nbFormDispOff(12);
  nbFormDispOff(13);
  nbFormDispOff(14);
  nbFormDispOff(15);
}

// 0x196e260
void nbAllFormDispOn(void) {
  nbFormDispOn(0);
  nbFormDispOn(1);
  nbFormDispOn(2);
  nbFormDispOn(3);
  nbFormDispOn(4);
  nbFormDispOn(5);
  nbFormDispOn(6);
  nbFormDispOn(7);
  nbFormDispOn(8);
  nbFormDispOn(9);
  nbFormDispOn(10);
  nbFormDispOn(11);
  nbFormDispOn(12);
  nbFormDispOn(13);
  nbFormDispOn(14);
  nbFormDispOn(15);
}

// 0x1970d50
void nbCopyFormation(nbMainProcessData_t **data, s32 sindex, s32 dindex) {
  struct nbFormation_t_array *form;
  u32 max_length;
  nbFormation_t_o *v10;
  nbFormation_t_o *v12;
  u32 ID;
  struct nbParty_t_array *party;
  UnityEngine_GameObject_o *modelobj;
  Il2CppObject *Component_object;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  if (sindex != dindex)
  {
    form = (*data)->form;
    max_length = form->max_length;
    v10 = form->m_Items[sindex];
    v12 = (*data)->form->m_Items[dindex];
    pFormation = v12;
    if (v10->badeff)
    {
      ID = effBTLSystemGetID(&v10->badeff);
      effBTLSystemDelete2(&v10->badeff);
      v10->badeff = 0;
      if ((v10->stat & 0x40) == 0)
    }
    else
    {
      ID = -1;
      if ((v10->stat & 0x40) == 0)
      {
        nbFormation_t__Copy(v12, v10);
        v12->formindex = dindex;
        if ((ID & 0x80000000) == 0)
        {
          v12->badeff = effBTLSystemCreate(&pFormation, ID);
          v12 = pFormation;
        }
        modelobj = v12->modelobj;
        if (op_Inequality(modelobj, 0, 0))
        {
          Component_object = GetComponent_object_(modelobj);
          if (op_Inequality(Component_object, 0, 0))
            SetForm(Component_object, pFormation, 0);
        }
        return;
      }
    }
    party = (*data)->party;
    party->m_Items[v10->partyindex]->formindex = dindex;
  }
}

// 0x196e570
void nbDoubleFormExceptedDispOff(nbFormation_t **form1, nbFormation_t **form2) {
  s32 i;

  for (i = 0; i != 16; ++i)
  {
    while (i == (*form1)->formindex || i == (*form2)->formindex)
    {
      nbFormDispOn(i++, form2);
      if (i == 16)
        return;
    }
    nbFormDispOff(i, form2);
  }
}

// 0x196d940
void nbFormDispOff(s32 formindex) {
  struct nbFormation_t_array *form;
  nbFormation_t_o *v7;
  dds3Basic_t_o **p_basic;
  struct evtUnitHandle_t_o *hunit;
  UnityEngine_GameObject_o *modelobj;

  form = nbGetMainProcessData()->form;
  v7 = form->m_Items[formindex];
  if ((~v7->stat & 3) == 0)
  {
    p_basic = &v7->basic;
    if (v7->basic)
    {
      hunit = v7->hunit;
      modelobj = hunit->modelobj;
      if (op_Inequality(modelobj, 0, 0) && get_activeSelf(modelobj))
        SetActive(modelobj, 0, 0);
      hunit->Model->stat |= 1u;
      dds3ObjectBaseOnFlag(p_basic, 0x1000u, 0);
    }
  }
}

// 0x196dc20
void nbFormDispOff2(nbFormation_t **form) {
    nbFormDispOff(0);
}

// 0x196dca0
void nbFormDispOn(s32 formindex) {
  struct nbFormation_t_array *form;
  nbFormation_t_o *v8;
  struct evtUnitHandle_t_o *hunit;
  dds3ModelHandle_t_o **p_Model;
  UnityEngine_GameObject_o *modelobj;

  form = nbGetMainProcessData()->form;
  v8 = form->m_Items[formindex];
  if ((~v8->stat & 3) == 0 && v8->basic)
  {
    if (!formindex && nb1st)
    {
      Postblur_DrawStop = 1;
      nb1st = 0;
    }
    hunit = v8->hunit;
    p_Model = &hunit->Model;
    modelobj = hunit->modelobj;
    mdlShowUnity(p_Model, modelobj, v8);
    dds3ObjectBaseOffFlag(&v8->basic, 0x1000u);
  }
}

// 0x196de30
void nbFormDispOn2(nbFormation_t **form) {
    nbFormDispOn(0);
}

// 0x1970c00
void nbFormatFormation(nbMainProcessData_t **data, s32 index) {
    nbFormation_t__Clear(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x196d4d0
void nbFormation1st(void) {
  nb1st = 1;
}

// 0x196ee50
f32 nbFormationGetRadiusDef(void) {
  return 100.0;
}

// 0x196eed0
f32 nbGetEnemyInterval(void) {
  return nbFormEnemyInterval;
}

// 0x196edf0
void nbGetFormPos(nbFormation_t **form) {
  SDF_VU0__LOADVECTOR((*form)->pos, 0);
}

// 0x196ee10
void nbGetFormRot(nbFormation_t **form) {
  SDF_VU0__LOADVECTOR((*form)->rot, 0);
}

// 0x196ee30
f32 nbGetPartyDistance(void) {
  return 800.0;
}

// 0x196ee60
f32 nbGetPlayerInterval(void) {
  return nbFormPlayerInterval;
}

// 0x196ee40
f32 nbGetSummonInterval(void) {
  return 50.0;
}

// 0x196deb0
void nbGroupFormDispOff(s32 side) {
  s64 v3;
  u32 v4;
  u32 v5;

  if (side <= 2)
  {
    v3 = 4LL * side;
    v4 = *(&unk_3444224 + v3);
    v5 = v4 + *(&unk_3444218 + v3);
    do
    {
      nbFormDispOff(v4++);
    }
    while (v4 < v5);
  }
}

// 0x196df60
void nbGroupFormDispOn(s32 side) {
  s64 v3;
  u32 v4;
  u32 v5;

  if (side <= 2)
  {
    v3 = 4LL * side;
    v4 = *(&unk_3444224 + v3);
    v5 = v4 + *(&unk_3444218 + v3);
    do
    {
      nbFormDispOn(v4++);
    }
    while (v4 < v5);
  }
}

// 0x1970fa0
void nbMoveFormation(nbMainProcessData_t **data, s32 sindex, s32 dindex) {
  if (sindex != dindex)
  {
    nbCopyFormation(data, sindex, dindex);
    nbFormatFormation(data, sindex);
  }
}

// 0x1971040
void nbPackEmptyFormation(nbMainProcessData_t **data) {
  struct nbFormation_t_array *form;
  u64 v7;
  struct nbFormation_t_array *v8;
  u64 v9;
  struct nbFormation_t_array *v12;
  struct nbFormation_t_array *v14;
  s64 v16;
  struct nbFormation_t_array *v17;
  s64 v19;
  s32 v20;
  struct nbFormation_t_array *v22;
  struct nbFormation_t_array *v24;
  s64 v26;
  struct nbFormation_t_array *v27;
  s64 v29;
  s32 v30;
  struct nbFormation_t_array *v32;

  form = (*data)->form;
  if ((form->m_Items[0]->stat & 1) == 0)
  {
    v7 = 0;
    while (v7 < 3)
    {
      v8 = (*data)->form;
      v9 = v7++;
      if ((v8->m_Items[v9 + 1]->stat & 1) != 0)
      {
        if (v7)
        {
          nbCopyFormation(data, v7, 0);
          nbFormatFormation(data, v7);
        }
        v12 = (*data)->form;
        nbDelAllMojiNumEffectKoukaPacket(v12->m_Items, 0);
        break;
      }
    }
  }
  v14 = (*data)->form;
  if ((v14->m_Items[1]->stat & 1) == 0)
  {
    v16 = 6;
    while ((v16 - 5) <= 2)
    {
      v17 = (*data)->form;
      v19 = *(&v17->obj.klass + v16++);
      if ((*(v19 + 136) & 1) != 0)
      {
        if (v16 != 6)
        {
          v20 = v16 - 5;
          nbCopyFormation(data, v20, 1);
          nbFormatFormation(data, v20);
        }
        v22 = (*data)->form;
        nbDelAllMojiNumEffectKoukaPacket(&v22->m_Items[1], 0);
        break;
      }
    }
  }
  v24 = (*data)->form;
  if ((v24->m_Items[2]->stat & 1) == 0)
  {
    v26 = 7;
    while ((v26 - 5) <= 2)
    {
      v27 = (*data)->form;
      v29 = *(&v27->obj.klass + v26++);
      if ((*(v29 + 136) & 1) != 0)
      {
        if (v26 != 7)
        {
          v30 = v26 - 5;
          nbCopyFormation(data, v30, 2);
          nbFormatFormation(data, v30);
        }
        v32 = (*data)->form;
        nbDelAllMojiNumEffectKoukaPacket(&v32->m_Items[2], 0);
        return;
      }
    }
  }
}

// 0x196ed00
void nbResetAllFormPosRot(void) {
    nbGetMainProcessData();
    nbResetFormPosRot(0);
}

// 0x196ec30
void nbResetFormPosRot(nbFormation_t **form) {
  nbFormation_t_o *v3;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v9;

  v3 = *form;
  if (((*form)->stat & 1) != 0)
  {
    x = v3->orgpos.x;
    y = v3->orgpos.y;
    z = v3->orgpos.z;
    w = v3->orgpos.w;
    v9.x = x;
    v9.y = y;
    v9.z = z;
    v9.w = w;
    nbSetFormPos(form, v9);
    nbSetFormRot(form, (*form)->orgrot, 0);
  }
}

// 0x196e650
void nbRestartMotion(void) {
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *v6;
  nbFormation_t_o *v8;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitVisual_t_o *UnitVisual;
  f32 formsize;
  datUnitVisual_t_o *v13;
  u64 j;
  struct nbFormation_t_array *v15;
  nbFormation_t_o *v17;
  f32 motspeed;
  UnityEngine_Animator_o *modelanm;
  nbFormation_t_o *v20;
  u32 stat;
  nbFormation_t_o *form;

  form = 0;
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 16; ++i)
  {
    v6 = MainProcessData->form;
    v8 = v6->m_Items[i];
    form = v8;
    if ((~v8->stat & 0x8003) == 0)
    {
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(i);
      UnitVisual = nbGetUnitVisual(UnitWorkFromFormindex);
      formsize = UnitVisual->formsize;
      v13 = UnitVisual;
      v8->cr = 0.0;
      v8->r = formsize;
      SDF_VU0__COPYVECTOR(&v8->center, UnitVisual->center);
      v8->scl = v13->formscale;
      v8->h = v13->formheight;
      v8->oneshotr = v13->oneshotr;
      v8->allshotr = v13->allshotr;
      v8->stat &= ~0x8000u;
    }
  }
  for (j = 0; j != 16; ++j)
  {
    v15 = MainProcessData->form;
    v17 = v15->m_Items[j];
    form = v17;
    if ((~v17->stat & 0x4003) == 0)
    {
      motspeed = v17->motspeed;
      modelanm = v17->modelanm;
      mdlSetMotionSpeedAnimator(modelanm, motspeed);
      v20 = form;
      form->hunit->Flag &= ~0x400000u;
      v20->hunit->Flag &= ~0x40u;
      v20->hunit->Flag |= 0x20u;
      stat = v20->stat;
      *&v20->nexthokan = 0;
      v20->stat = stat & 0xFFFFBFFF;
      nbSetUnitMotion(&form, 0, 1, 1.0);
    }
  }
}

// 0x196f5e0
void nbSetEnemyFormation(nbMainProcessData_t **data) {
    nbSetPartyFormation(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    nbSetFormPos(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    nbGetUnitWorkFromFormindex(0);
    effBTLModelGetID(0);
}

// 0x1971a80
s32 nbSetEnemySummonFormation(nbMainProcessData_t **data, s32 devilid) {
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v7;
  struct nbFormation_t_array *v9;
  struct nbFormation_t_array *v11;
  struct nbFormation_t_array *v13;
  struct nbFormation_t_array *v15;
  struct nbFormation_t_array *v17;
  struct nbFormation_t_array *v19;
  struct nbFormation_t_array *v21;
  struct nbFormation_t_array *v23;
  s32 encno;
  datEncount_t_o *v26;
  s64 maxparty;
  s32 v29;
  nbMainProcessData_t_o *v30;
  s64 v31;
  s64 v32;
  struct nbFormation_t_array *v33;
  nbFormation_t_o *v34;
  u32 stat;
  f32 formsize;
  s64 v38;
  s64 v39;
  struct nbFormation_t_array *v40;
  nbFormation_t_o *v41;
  u32 v42;

  form = (*data)->form;
  form->m_Items[4]->stat &= ~0x800u;
  v7 = (*data)->form;
  v7->m_Items[5]->stat &= ~0x800u;
  v9 = (*data)->form;
  v9->m_Items[6]->stat &= ~0x800u;
  v11 = (*data)->form;
  v11->m_Items[7]->stat &= ~0x800u;
  v13 = (*data)->form;
  v13->m_Items[8]->stat &= ~0x800u;
  v15 = (*data)->form;
  v15->m_Items[9]->stat &= ~0x800u;
  v17 = (*data)->form;
  v17->m_Items[10]->stat &= ~0x800u;
  v19 = (*data)->form;
  v19->m_Items[11]->stat &= ~0x800u;
  v21 = (*data)->form;
  v21->m_Items[12]->stat &= ~0x800u;
  v23 = (*data)->form;
  v23->m_Items[13]->stat &= ~0x800u;
  encno = (*data)->encno;
  v26 = Get(encno, 0);
  maxparty = v26->maxparty;
  v29 = 0;
  if (v26->maxparty)
  {
    v30 = *data;
    if ((*data)->nakamayobi)
    {
      if (devilid >= 1)
      {
        v31 = 0;
        v29 = 0;
        v32 = maxparty - 1;
        while (1)
        {
          v33 = v30->form;
          v34 = v33->m_Items[v31 + 4];
          stat = v34->stat;
          if ((stat & 1) != 0)
          {
            if (v32 == v31)
              return v29;
          }
          else
          {
            v34->stat = stat | 0x800;
            formsize = Get(devilid, 0)->formsize;
            v29 = 1;
            v34->r = formsize * Get(devilid, 0)->formscale;
            if (v32 == v31)
              return v29;
          }
          v30 = *data;
          ++v31;
        }
      }
      v38 = 0;
      v29 = 0;
      v39 = maxparty - 1;
      while (1)
      {
        v40 = v30->form;
        v41 = v40->m_Items[v38 + 4];
        v42 = v41->stat;
        if ((v42 & 1) != 0)
        {
          if (v39 == v38)
            return v29;
        }
        else
        {
          v29 = 1;
          v41->stat = v42 | 0x800;
          if (v39 == v38)
            return v29;
        }
        v30 = *data;
        ++v38;
      }
    }
  }
  return v29;
}

// 0x196e8b0
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  nbFormation_t_o *v9;
  dds3Basic_t_o **p_basic;
  struct dds3Basic_t_o *basic;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;

  w = pos.w;
  z = pos.z;
  y = pos.y;
  x = pos.x;
  v12.x = x;
  v12.y = y;
  v12.z = z;
  v12.w = w;
  SDF_VU0__COPYVECTOR(&(*form)->pos, v12, 0);
  v9 = *form;
  if ((~(*form)->stat & 3) == 0)
  {
    basic = v9->basic;
    p_basic = &v9->basic;
    if (basic)
    {
      v13.x = x;
      v13.y = y;
      v13.z = z;
      v13.w = w;
      dds3SetPosPoseSet(p_basic, v13);
      v14.z = z;
      v14.w = w;
      v14.x = x;
      v14.y = y;
      SDF_VU0__COPYVECTOR(&(*form)->pos, v14, 0);
    }
  }
}

// 0x196eb60
void nbSetFormPosRot(nbFormation_t **form, sdfVector4_t pos, sdfVector4_t rot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o v15;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  v8 = pos.w;
  v9 = pos.z;
  v10 = pos.y;
  v11 = pos.x;
  v14.x = v11;
  v14.y = v10;
  v14.z = v9;
  v14.w = v8;
  nbSetFormPos(form, v14);
  v15.x = x;
  v15.y = y;
  v15.z = z;
  v15.w = w;
  nbSetFormRot(form, v15, 0);
}

// 0x196e9c0
void nbSetFormRot(nbFormation_t **form, sdfVector4_t rot, bool look2) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
}

// 0x196ef40
void nbSetPartyFormation(nbMainProcessData_t **data, u32 group) {
    sdfAtan(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfSin(0);
    sdfCos(0);
    effBTLModelGetID(0);
    nbSetFormPos(0, (sdfVector4_t){0});
    nbSetFormRot(0, (sdfVector4_t){0}, 0);
}

// 0x1970b90
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty) {
  nbSetPartyFormation(data, 0x100u);
}

// 0x19717d0
void nbSetPlayerSummonFormation(nbMainProcessData_t **data) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x196e4b0
void nbSingleFormExceptedDispOff(nbFormation_t **form) {
  s32 i;

  for (i = 0; i != 16; ++i)
  {
    while (i == (*form)->formindex)
    {
      nbFormDispOn(i++);
      if (i == 16)
        return;
    }
    nbFormDispOff(i);
  }
}
