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
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;
  struct datUnitMotion_s_array *motion;
  s32 motion_no;
  s32 v16;
  u64 *v18;
  System_String_o *v19;
  s32 v20;

  if (op_Inequality(modelobj, 0, 0) && !get_activeSelf(modelobj))
  {
    SetActive(modelobj, 1, 0);
    formindex = form->formindex;
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if ((UnitWorkFromFormindex->badstatus & 0x1EC) != 0)
      Play_8777392(form->modelanm, "b102");
    id = UnitWorkFromFormindex->id;
    motion = Get(id, 0)->motion;
    motion_no = motion->m_Items[22]->motion_no;
    if (motion_no || !UnitWorkFromFormindex->id)
    {
      if (datCheckDying(UnitWorkFromFormindex) == 1)
      {
        v16 = UnitWorkFromFormindex->id;
        if ((v16 - 349) >= 4 && v16 != 353 && motion_no >= 10)
          motion_no -= 6;
        v20 = motion_no + 100;
        v18 = sub_8D3950(s32, &v20);
        v19 = Concat("b", v18);
        if ((UnitWorkFromFormindex->badstatus & 0x13) == 0)
          Play_8777392(form->modelanm, v19);
      }
    }
  }
  (*aHandle)->stat &= ~1u;
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
        goto LABEL_18;
    }
    else
    {
      ID = -1;
      if ((v10->stat & 0x40) == 0)
      {
LABEL_18:
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
    goto LABEL_18;
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
  s32 formindex;
  s32 v4;

  formindex = (*form)->formindex;
  else
  {
    v4 = formindex;
  }
  nbFormDispOff(v4);
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
  s32 formindex;
  s32 v4;

  formindex = (*form)->formindex;
  else
  {
    v4 = formindex;
  }
  nbFormDispOn(v4);
}

// 0x1970c00
void nbFormatFormation(nbMainProcessData_t **data, s32 index) {
  struct nbFormation_t_array *form;
  nbFormation_t_o *v7;
  u32 stat;
  s32 v9;
  s32 v10;
  UnityEngine_Vector4_o v11;
  UnityEngine_Vector4_o v12;

  *&v12.x = 0;
  *&v12.z = 0;
  *&v11.x = 0;
  *&v11.z = 0;
  sub_854690(&v12.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v11.x, 0.0, 0.0, 0.0, 1.0);
  form = (*data)->form;
  v7 = form->m_Items[index];
  nbFormation_t__Clear(v7);
  v7->r = 100.0;
  v7->formindex = index;
  *&v7->cr = 0x3F80000042C80000LL;
  if (index <= 3)
  {
    v10 = v7->stat | 0x100;
  }
  else
  {
    stat = v7->stat;
    v9 = stat | 0x400;
    v10 = stat | 0x200;
    if (index > 13)
      v10 = v9;
  }
  v7->stat = v10;
  SDF_VU0__COPYVECTOR(&v7->pos, v12);
  SDF_VU0__COPYVECTOR(&v7->orgpos, v12);
  SDF_VU0__COPYVECTOR(&v7->rot, v11);
  SDF_VU0__COPYVECTOR(&v7->orgrot, v11);
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
  nbMainProcessData_t_o *MainProcessData;
  u64 v5;
  s64 v6;
  struct nbFormation_t_array *form;

  MainProcessData = nbGetMainProcessData();
  v5 = 0;
  v6 = 32;
  do
  {
    form = MainProcessData->form;
    else if (v5 >= LODWORD(form->max_length))
    {
LABEL_12:
    }
    nbResetFormPosRot((form + v6));
    ++v5;
    v6 += 8;
  }
  while (v5 != 16);
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
  struct nbFormation_t_array *v6;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  u32 v14;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  nbFormation_t_o *v20;
  struct UnityEngine_Vector4_o *v21;
  f32 scl;
  struct UnityEngine_Vector4_o *v23;
  s64 *v24;
  s64 i;
  struct nbFormation_t_array *v29;
  nbFormation_t_o *v30;
  s64 j;
  struct nbFormation_t_array *v38;
  nbFormation_t_o *v39;
  struct nbFormation_t_array *v45;
  nbFormation_t_o *v47;
  struct nbFormation_t_array *v48;
  nbFormation_t_o *v50;
  struct nbFormation_t_array *v52;
  nbFormation_t_o *v54;
  s64 k;
  struct nbFormation_t_array *v59;
  s64 v60;
  s32 v62;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u32 v66;
  f32 v67;
  f32 v68;
  f32 v69;
  f32 v70;
  struct nbFormation_t_array *v74;
  nbFormation_t_o *v76;
  struct nbFormation_t_array *v80;
  f32 v83;
  f32 v84;
  f32 v85;
  f32 v86;
  u32 ID;
  struct UnityEngine_Vector4_o *v89;
  struct nbFormation_t_array *v93;
  u32 v95;
  struct UnityEngine_Vector4_o *v96;
  struct UnityEngine_Vector4_o *v97;
  struct nbFormation_t_array *v102;
  nbFormation_t_o *v105;
  f32 v106;
  struct UnityEngine_Vector4_o *v107;
  struct nbFormation_t_array *v108;
  nbFormation_t_o *v110;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct nbFormation_t_array *v117;
  f32 v120;
  f32 v121;
  f32 v122;
  f32 v123;
  nbFormation_t_Fields *p_fields;
  struct UnityEngine_Vector4_o *v125;
  struct UnityEngine_Vector4_o *v126;
  struct UnityEngine_Vector4_o *v127;
  struct UnityEngine_Vector4_o *p_center;
  struct UnityEngine_Vector4_o *v129;
  f32 v130;
  f32 v131;
  f32 v132;
  f32 v133;
  UnityEngine_Vector4_o v134;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *v136;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o v138;
  UnityEngine_Vector4_o v139;
  UnityEngine_Vector4_o v140;
  UnityEngine_Vector4_o v141;
  UnityEngine_Vector4_o v142;
  UnityEngine_Vector4_o v143;
  UnityEngine_Vector4_o v144;
  UnityEngine_Vector4_o v145;

  v136 = 0;
  form = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v134.x = 0;
  *&v134.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v134.x, 0.0, 0.0, 0.0, 0.0);
  switch ((*data)->formationtype)
  {
    case 0:
      v24 = &"nbSetEnemyFormation:ENC_FORMATION_NORMAL\n";
      goto LABEL_171;
    case 1:
      Write("nbSetEnemyFormation:ENC_FORMATION_ARSIEL\n", 0);
      nbSetPartyFormation(data, 0x200u);
      for (i = 8; i != 18; ++i)
      {
        while (1)
        {
          v29 = (*data)->form;
          v30 = *(&v29->obj.klass + i);
          form = v30;
          if ((v30->stat & 1) != 0)
            break;
          if (++i == 18)
            return;
        }
        SDF_VU0__LOADVECTOR(v30->pos);
        SDF_VU0__STOREVECTOR(&p);
        sub_854710(&p, 2u);
        sub_854930(&p, 2u);
        nbSetFormPos(&form, p);
        SDF_VU0__COPYVECTOR(&form->orgpos, p);
      }
      return;
    case 2:
      v24 = &"nbSetEnemyFormation:ENC_FORMATION_GIRIME\n";
      goto LABEL_171;
    case 3:
      Write("nbSetEnemyFormation:ENC_FORMATION_MARA\n", 0);
      nbSetPartyFormation(data, 0x200u);
      nbSetPartyFormation(data, 0x200u);
      for (j = 8; j != 18; ++j)
      {
        while (1)
        {
          v38 = (*data)->form;
          v39 = *(&v38->obj.klass + j);
          form = v39;
          if ((v39->stat & 1) != 0)
            break;
          if (++j == 18)
            return;
        }
        SDF_VU0__LOADVECTOR(v39->pos);
        SDF_VU0__STOREVECTOR(&p);
        sub_854710(&p, 2u);
        sub_854930(&p, 2u);
        nbSetFormPos(&form, p);
        SDF_VU0__COPYVECTOR(&form->orgpos, p);
      }
      return;
    case 4:
      Write("nbSetEnemyFormation:ENC_FORMATION_3SISTER\n", 0);
      nbSetPartyFormation(data, 0x200u);
      v45 = (*data)->form;
      v47 = v45->m_Items[5];
      form = v47;
      if ((v47->stat & 1) != 0)
      {
        SDF_VU0__LOADVECTOR(v47->pos);
        SDF_VU0__STOREVECTOR(&p);
        v108 = (*data)->form;
        v110 = v108->m_Items[4];
        v136 = v110;
        SDF_VU0__LOADVECTOR(v110->pos);
        SDF_VU0__STOREVECTOR(&v134);
        if ((v110->stat & 1) != 0)
        {
          sub_854710(&p, 2u);
          sub_854930(&v134, 2u);
          sub_854710(&p, 0);
          sub_854930(&v134, 0);
          x = v134.x;
          y = v134.y;
          z = v134.z;
          w = v134.w;
          v143.x = x;
          v143.y = y;
          v143.z = z;
          v143.w = w;
          nbSetFormPos(&v136, v143);
          SDF_VU0__COPYVECTOR(&v110->orgpos, v134);
        }
        v117 = (*data)->form;
        v54 = v117->m_Items[6];
        v136 = v54;
        SDF_VU0__LOADVECTOR(v54->pos);
        SDF_VU0__STOREVECTOR(&v134);
        if ((v54->stat & 1) != 0)
          goto LABEL_200;
      }
      else
      {
        v48 = (*data)->form;
        v50 = v48->m_Items[4];
        form = v50;
        SDF_VU0__LOADVECTOR(v50->pos);
        SDF_VU0__STOREVECTOR(&p);
        if ((form->stat & 1) != 0)
        {
          v52 = (*data)->form;
          v54 = v52->m_Items[6];
          v136 = v54;
          SDF_VU0__LOADVECTOR(v54->pos);
          SDF_VU0__STOREVECTOR(&v134);
          if ((v54->stat & 1) != 0)
          {
LABEL_200:
            sub_854710(&p, 2u);
            sub_854930(&v134, 2u);
            sub_854710(&p, 0);
            sub_854930(&v134, 0);
            v121 = v134.x;
            v120 = v134.y;
            v123 = v134.z;
            v122 = v134.w;
            v144.x = v121;
            v144.y = v120;
            v144.z = v123;
            v144.w = v122;
            nbSetFormPos(&v136, v144);
            v145 = v134;
            p_fields = &v54->fields;
            goto LABEL_216;
          }
        }
      }
      return;
    case 5:
      Write("nbSetEnemyFormation:ENC_FORMATION_ALBION\n", 0);
      nbSetPartyFormation(data, 0x200u);
      for (k = 8; k != 18; ++k)
      {
        while (1)
        {
          v59 = (*data)->form;
          v60 = *(&v59->obj.klass + k);
          form = v60;
          if ((*(v60 + 136) & 1) != 0)
            break;
          if (++k == 18)
            return;
        }
        v62 = *(v60 + 178);
        UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v62);
        SDF_VU0__LOADVECTOR(form->pos);
        SDF_VU0__STOREVECTOR(&p);
        switch (UnitWorkFromFormindex->id)
        {
          case 0x116u:
            sub_854710(&p, 2u);
            v66 = 2;
            goto LABEL_111;
          case 0x117u:
          case 0x118u:
          case 0x119u:
          case 0x11Au:
            sub_854710(&p, 2u);
            sub_854930(&p, 2u);
            sub_854710(&p, 0);
            v66 = 0;
LABEL_111:
            sub_854930(&p, v66);
            break;
          default:
            break;
        }
        v68 = p.x;
        v67 = p.y;
        v70 = p.z;
        v69 = p.w;
        v140.x = v68;
        v140.y = v67;
        v140.z = v70;
        v140.w = v69;
        nbSetFormPos(&form, v140);
        SDF_VU0__COPYVECTOR(&form->orgpos, p);
      }
      return;
    case 6:
      v24 = &"nbSetEnemyFormation:ENC_FORMATION_TENSI\n";
      goto LABEL_171;
    case 7:
      Write("nbSetEnemyFormation:ENC_FORMATION_BAAL\n", 0);
      nbSetPartyFormation(data, 0x200u);
      v74 = (*data)->form;
      v76 = v74->m_Items[4];
      form = v76;
      if ((v76->stat & 1) == 0)
        return;
      SDF_VU0__LOADVECTOR(v76->pos);
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&p, 0);
      sub_854930(&p, 0);
      v141 = p;
      goto LABEL_215;
    case 8:
      Write("nbSetEnemyFormation:ENC_FORMATION_NET\n", 0);
      nbSetPartyFormation(data, 0x200u);
      v80 = (*data)->form;
      form = v80->m_Items[4];
      if ((form->stat & 1) == 0)
        return;
      sub_854930(&p, 0);
      sub_854930(&p, 1u);
      sub_854930(&p, 2u);
      v84 = p.x;
      v83 = p.y;
      v86 = p.z;
      v85 = p.w;
      v142.x = v84;
      v142.y = v83;
      v142.z = v86;
      v142.w = v85;
      nbSetFormPos(&form, v142);
      SDF_VU0__COPYVECTOR(&form->orgpos, p);
      ID = effBTLModelGetID(&form);
      if (ID == 259)
      {
        p_center = &form->center;
        *&form->r = 0x4443000043C80000LL;
        sub_854930(p_center, 0);
        v126 = &form->center;
        goto LABEL_207;
      }
      if (ID != 292)
        return;
      v89 = &form->center;
      *&form->r = 0x4443000043C80000LL;
      sub_854930(v89, 0);
      sub_854930(&form->center, 1u);
      v23 = &form->center;
      goto LABEL_208;
    case 9:
    case 0xB:
      Write("nbSetEnemyFormation:ENC_FORMATION_ARI\n", 0);
      nbSetPartyFormation(data, 0x200u);
      v6 = (*data)->form;
      form = v6->m_Items[4];
      if ((form->stat & 1) == 0)
        return;
      sub_854930(&p, 0);
      sub_854930(&p, 1u);
      sub_854930(&p, 2u);
      v10 = p.x;
      v9 = p.y;
      v12 = p.z;
      v11 = p.w;
      v138.x = v10;
      v138.y = v9;
      v138.z = v12;
      v138.w = v11;
      nbSetFormPos(&form, v138);
      SDF_VU0__COPYVECTOR(&form->orgpos, p);
      v14 = effBTLModelGetID(&form);
      switch (v14)
      {
        case 0x102u:
          v125 = &form->center;
          *&form->r = 0x4422800043AF0000LL;
          sub_854930(v125, 0);
          v126 = &form->center;
LABEL_207:
          sub_854930(v126, 1u);
          v23 = &form->center;
          break;
        case 0x123u:
          v127 = &form->center;
          *&form->r = 0x443B800043AF0000LL;
          sub_854930(v127, 0);
          sub_854930(&form->center, 1u);
          v23 = &form->center;
          break;
        case 0x156u:
          sub_854930(&p, 0);
          sub_854930(&p, 1u);
          sub_854930(&p, 2u);
          v17 = p.x;
          v16 = p.y;
          v19 = p.z;
          v18 = p.w;
          v139.x = v17;
          v139.y = v16;
          v139.z = v19;
          v139.w = v18;
          nbSetFormPos(&form, v139);
          SDF_VU0__COPYVECTOR(&form->orgpos, p);
          v20 = form;
          v21 = &form->center;
          scl = form->scl;
          form->r = 200.0 / scl;
          v20->h = 700.0 / scl;
          sub_854930(v21, 0);
          sub_854930(&form->center, 1u);
          v23 = &form->center;
          break;
        default:
          return;
      }
LABEL_208:
      sub_854930(v23, 2u);
      return;
    case 0xA:
      Write("nbSetEnemyFormation:ENC_FORMATION_KAGU\n", 0);
      nbSetPartyFormation(data, 0x200u);
      v93 = (*data)->form;
      form = v93->m_Items[4];
      if ((form->stat & 1) == 0)
        return;
      v95 = effBTLModelGetID(&form);
      if (v95 == 264)
      {
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sub_854710(&p, 2u);
        sub_854930(&p, 2u);
        v129 = &form->center;
        *&form->r = 0x447A000043FA0000LL;
        sub_854930(v129, 0);
        sub_854930(&form->center, 1u);
        v97 = &form->center;
      }
      else
      {
        if (v95 != 293)
          goto LABEL_211;
        sub_854930(&p, 0);
        sub_854930(&p, 1u);
        sub_854710(&p, 2u);
        sub_854930(&p, 2u);
        v96 = &form->center;
        *&form->r = 0x4461000044160000LL;
        sub_854930(v96, 0);
        sub_854930(&form->center, 1u);
        v97 = &form->center;
      }
      sub_854930(v97, 2u);
LABEL_211:
      v131 = p.x;
      v130 = p.y;
      v133 = p.z;
      v132 = p.w;
      v141.x = v131;
      v141.y = v130;
      v141.z = v133;
      v141.w = v132;
LABEL_215:
      nbSetFormPos(&form, v141);
      v145 = p;
      p_fields = &form->fields;
LABEL_216:
      SDF_VU0__COPYVECTOR(&p_fields->orgpos, v145);
      return;
    case 0xC:
      v24 = &"nbSetEnemyFormation:ENC_FORMATION_BERU\n";
LABEL_171:
      Write(*v24, 0);
      nbSetPartyFormation(data, 0x200u);
      return;
    case 0xD:
      Write("nbSetEnemyFormation:ENC_FORMATION_LUSI\n", 0);
      nbSetPartyFormation(data, 0x200u);
      v102 = (*data)->form;
      form = v102->m_Items[4];
      SDF_VU0__LOADVECTOR(form->pos);
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&p, 1u);
      sub_854930(&p, 1u);
      sub_854710(&p, 2u);
      sub_854930(&p, 2u);
      nbSetFormPos(&form, p);
      SDF_VU0__COPYVECTOR(&form->orgpos, p);
      v105 = form;
      v106 = form->scl;
      v107 = &form->center;
      form->r = 200.0 / v106;
      v105->h = 1500.0 / v106;
      sub_854930(v107, 0);
      sub_854930(&form->center, 1u);
      v23 = &form->center;
      goto LABEL_208;
    default:
      return;
  }
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
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  dds3Basic_t_o **p_basic;
  s64 v11;
  f32 v12;
  f32 v13;
  UnityEngine_Vector4_o v14;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;
  UnityEngine_Vector4_o v19;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  *&v15.x = 0;
  *&v15.z = 0;
  *&v14.x = 0;
  *&v14.z = 0;
  sub_854690(&v15.x, 0.0, 1.0, 0.0, 0.0);
  sub_854690(&v14.x, 0.0, 0.0, 0.0, 0.0);
  v16.x = x;
  v16.y = y;
  v16.z = z;
  v16.w = w;
  SDF_VU0__COPYVECTOR(&(*form)->rot, v16, 0);
  if ((~(*form)->stat & 3) == 0 && (*form)->basic)
  {
    v17.x = x;
    v17.y = y;
    v17.z = z;
    v17.w = w;
    SDF_VU0__LOADVECTOR(v17);
    SDF_VU0__LOADVECTOR_B(v15);
    Mult();
    SDF_VU0__STOREVECTOR(&v14);
    p_basic = &(*form)->basic;
    v11 = *&v14.x;
    v13 = v14.z;
    v12 = v14.w;
    *&v18.x = v11;
    v18.z = v13;
    v18.w = v12;
    dds3SetRotPoseSet(p_basic, v18);
    v19.x = x;
    v19.y = y;
    v19.z = z;
    v19.w = w;
    SDF_VU0__COPYVECTOR(&(*form)->rot, v19, 0);
  }
}

// 0x196ef40
void nbSetPartyFormation(nbMainProcessData_t **data, u32 group) {
  f32 v5;
  u64 *v6;
  u64 *v8;
  u64 v9;
  u32 v10;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v13;
  u32 stat;
  f32 v15;
  s64 v16;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 *p_nbFormPlayerInterval;
  f32 v24;
  f32 v25;
  u64 i;
  struct nbFormation_t_array *v27;
  s64 v29;
  f32 v31;
  u32 v33;
  f32 v34;
  u64 v35;
  struct nbFormation_t_array *v36;
  s64 v38;
  f32 r;
  f32 scl;
  f32 v42;
  f32 v43;
  f32 v44;
  u32 ID;
  s64 v48;
  s64 v49;
  u32 v51;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v53;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;

  v5 = 0.0;
  *&v56.x = 0;
  *&v56.z = 0;
  *&v55.x = 0;
  *&v55.z = 0;
  *&v53.z = 0;
  pFormation = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v53.x = 0;
  sub_854690(&v56.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v55.x, 0.0, 1.0, 0.0, 0.0);
  sub_854690(&v53.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&dst.x, 0.0, 0.0, 0.0, 0.0);
  v6 = NewSpecific(uint, 0x20u);
  v8 = v6;
  v9 = 0;
  v10 = 0;
  do
  {
    while (1)
    {
      form = (*data)->form;
      v13 = form->m_Items[v9];
      pFormation = v13;
      stat = v13->stat;
      if ((stat & group) != 0 && ((stat & 1) != 0 || (v13->stat & 0x808) == 0x808))
        break;
      if (++v9 == 32)
        goto LABEL_14;
    }
    v16 = v10;
    v15 = v13->r * v13->scl;
    v5 = v5 + (v15 + v15);
    ++v10;
    *(v6 + v16 + 8) = v9++;
  }
  while (v9 != 32);
LABEL_14:
  if (v10)
  {
    if (v10 == 1)
    {
      v18 = 0.0;
    }
    else if (v5 <= 1200.0)
    {
      v18 = 50.0;
      v19 = (v10 - 1);
      v20 = (1200.0 - v5) / v19;
      if (v20 >= 50.0)
      {
        v18 = (1200.0 - v5) / v19;
        if (v20 > 100.0)
          v18 = 100.0;
      }
    }
    else
    {
      v18 = 50.0;
    }
    if ((group & 0x100) != 0)
    {
      p_nbFormPlayerInterval = &nbFormPlayerInterval;
    }
    else
    {
      p_nbFormPlayerInterval = &nbFormEnemyInterval;
    }
    *p_nbFormPlayerInterval = v18;
    v24 = sdfAtan(v18 / 1200.0);
    v25 = -v24;
    for (i = 0; i != v10; ++i)
    {
      v27 = (*data)->form;
      v29 = *(v8 + i + 8);
      pFormation = v27->m_Items[v29];
      v31 = pFormation->r * pFormation->scl;
      v25 = v24 + (v25 + sdfAtan((v31 + v31) / 1200.0, 0));
    }
    if ((group & 0x100) != 0)
      v57 = v56;
    else
      v57 = v55;
    SDF_VU0__COPYVECTOR(&dst, v57);
    v33 = (*data)->formationtype - 8;
    v34 = v25 * -0.5;
    v35 = 0;
    v36 = (*data)->form;
    if (!*(v8 + 6))
    {
LABEL_49:
    }
    while (1)
    {
      v38 = *(v8 + v35 + 8);
      pFormation = v36->m_Items[v38];
      r = pFormation->r;
      scl = pFormation->scl;
      v42 = sdfAtan((r * scl) / 1200.0, 0);
      v43 = v34 + v42;
      v44 = v42;
      sdfSin(v43);
      sub_854930(&v53, 0);
      sub_854930(&v53, 1u);
      sdfCos(v43);
      sub_854930(&v53, 2u);
      ID = effBTLModelGetID(&pFormation);
      if (v33 >= 3 && ID == 155 && (pFormation->stat & 0x100) != 0)
      {
        Write("nbSetPartyFormation : DV_ALBION\n", 0);
        sub_854710(&v53, 2u);
        sub_854930(&v53, 2u);
      }
      v48 = *&v53.x;
      v49 = *&v53.z;
      *&v58.x = v48;
      *&v58.z = v49;
      nbSetFormPos(&pFormation, v58);
      SDF_VU0__COPYVECTOR(&pFormation->orgpos, v53);
      nbSetFormRot(&pFormation, dst, 0);
      SDF_VU0__COPYVECTOR(&pFormation->orgrot, dst);
      if (((*data)->stat & 0x10) == 0)
      {
        v51 = pFormation->stat;
        if ((v51 & 0x2000) != 0)
          pFormation->stat = v51 & 0xFFFFDFFF;
      }
      if (v10 - 1LL == v35)
        break;
      ++v35;
      v34 = v24 + (v44 + v43);
      v36 = (*data)->form;
      if (v35 >= *(v8 + 6))
        goto LABEL_49;
    }
  }
}

// 0x1970b90
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty) {
  nbSetPartyFormation(data, 0x100u);
}

// 0x19717d0
void nbSetPlayerSummonFormation(nbMainProcessData_t **data) {
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v4;
  struct nbFormation_t_array *v6;
  struct nbFormation_t_array *v8;
  struct nbFormation_t_array *v11;
  nbFormation_t_o *v12;
  s64 v13;
  struct nbFormation_t_array *v15;
  struct nbFormation_t_array *v17;
  struct nbFormation_t_array *v19;
  UnityEngine_Vector4_o *v21;

  form = (*data)->form;
  form->m_Items[0]->stat &= ~0x800u;
  v4 = (*data)->form;
  v4->m_Items[1]->stat &= ~0x800u;
  v6 = (*data)->form;
  v6->m_Items[2]->stat &= ~0x800u;
  v8 = (*data)->form;
  v8->m_Items[3]->stat &= ~0x800u;
  v11 = (*data)->form;
  v12 = v11->m_Items[1];
  if ((v12->stat & 1) == 0)
  {
    v13 = 0;
LABEL_24:
    v19 = (*data)->form;
    v21 = v19->m_Items[v13];
    SDF_VU0__COPYVECTOR(&v12->orgpos, v21[1]);
    sub_854710(&v12->fields, 0);
    sub_854930(&v12->fields, 0);
    SDF_VU0__COPYVECTOR(&v12->pos, v12->orgpos);
    SDF_VU0__COPYVECTOR(&v12->orgrot, v21[2]);
    SDF_VU0__COPYVECTOR(&v12->rot, v12->orgrot);
    v12->stat |= 0x800u;
    return;
  }
  v15 = (*data)->form;
  v12 = v15->m_Items[2];
  if ((v12->stat & 1) == 0)
  {
    v13 = 1;
    goto LABEL_24;
  }
  v17 = (*data)->form;
  v12 = v17->m_Items[3];
  if ((v12->stat & 1) == 0)
  {
    v13 = 2;
    goto LABEL_24;
  }
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
