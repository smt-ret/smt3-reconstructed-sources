#include "types.h"

typedef struct AnimCheckerBattle AnimCheckerBattle;
typedef struct datUnitVisual_s datUnitVisual_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLSysHandle_t effBTLSysHandle_t;
typedef struct evtAnimCheck evtAnimCheck;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldTitleName fldTitleName;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;

bool AnimClipSearch(AnimCheckerBattle *this, s32 dvlno, s32 animno);
s32 ChkUseMarukage(s32 deveilID);
u8 Get(s32 id);
s32 GetDyingBadWaitMotion(nbFormation_t **form, s32 motion, datUnitWork_t **work);
f32 GetStateNormalizedTimeOffset(AnimCheckerBattle *this);
void *GetTargetMark2D(s32 idx);
bool IsBtlMotionFinished(AnimCheckerBattle *this);
bool IsFinished(fldTitleName *this);
bool IsModelDante(s32 id);
bool IsModelRaido(s32 id);
void LoadBossAIMSG(char *key);
void Mult(void);
void RegistUnit(nbMainProcessData_t **data, s32 major, s32 minor, nbFormation_t **form, datUnitWork_t **w);
void ResetFlag(evtAnimCheck *this, evtUnitHandle_t *hndl, s32 LayerIndex);
void ResetStateNormalizedTimeOffset(AnimCheckerBattle *this);
void RunBadAction(nbMainProcessData_t **data, nbFormation_t **form);
void RunDamage(nbMainProcessData_t **data, nbFormation_t **form);
bool RunLoad(nbMainProcessData_t **data, nbFormation_t **form);
void RunSake(nbMainProcessData_t **data, nbFormation_t **form);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void TargetMark2DAnim(s32 idx);
void UpdateFormAnime(nbMainProcessData_t **data, nbFormation_t **form, datUnitWork_t **work);
void UpdateFormPosRot(nbFormation_t **form);
void UpdateNormalizeTime(AnimCheckerBattle *this);
s32 datCheckDying(datUnitWork_t *work);
void datClearCommMemory(datUnitWork_t *work);
u32 datGetAisyo(datUnitWork_t *work, s32 attr);
u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
f32 dds3GetRandFloatA(char *name);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void dds3LinkLightObjectToUnitObject(dds3Basic_t **lightbasic, dds3Basic_t **unitbasic, u32 frame);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void effBTLSystemDelete2(effBTLSysHandle_t **hEffBTLSys);
void effBTLSystemDraw(effBTLSysHandle_t **hEffBTLSys);
bool evtBitCheck(s32 no);
s32 evtSetRegistUnit(s32 major, s32 minor);
void evtSetUnitColorA(evtUnitHandle_t **h, u32 frame, u32 a);
void evtSetUnitColorRGB(evtUnitHandle_t **h, u32 frame, u32 rgb);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
void evtSetWaitHokanFrame(evtUnitHandle_t *h, s32 before, s32 smooth);
void evtSetWaitMotion(evtUnitHandle_t **h, s32 motion);
void evtSetWaitMotionSpeed(evtUnitHandle_t **h, f32 sp);
void mdlAnimSetBattle(evtUnitHandle_t **h, s32 motion);
s32 mdlAnimSetBattleQuickWait(evtUnitHandle_t *h, s32 old_motion, s32 motion);
bool mdlChkMotionEnd(dds3ModelHandle_t *HNDL);
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle);
s32 mdlGetMotionMinorNumForUnity(evtUnitHandle_t **h, s32 layer);
f32 mdlGetMotionSpeedAnimator(void *mAnimator);
void mdlMotionSub(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber);
void mdlSetEffectScale(dds3ModelHandle_t **aHandle, f32 aScale);
void mdlSetMotionSpeedAnimator(void *mAnimator, f32 speed);
nbKoukaPacket_t *nbAddBadEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 bad);
nbKoukaPacket_t *nbAddBadMotKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 badstat);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
s32 nbCheckLoadUnitPackFile_MSE(nbFormation_t **form, s32 major, s32 minor, bool semiflg);
s32 nbCheckLoadUnitPackFile_Model(nbFormation_t **form, s32 major, s32 minor, bool semiflg);
void nbCheckLoadUnitPackFile_ModelInit(nbFormation_t **form);
void nbDrawTargetCursor(nbMainProcessData_t *data, nbFormation_t *form, sdfDrawTag_t *tag, s32 curidx);
void nbFormDispOff(s32 formindex);
nbMainProcessData_t *nbGetMainProcessData(void);
u32 nbGetModelColor(nbFormation_t *form);
s32 nbGetMotionNo(nbFormation_t **form, s32 motion);
f32 nbGetMotionSpeed(nbFormation_t **form, s32 motion, f32 ritu);
s32 nbGetUnitID(datUnitWork_t *work);
datUnitVisual_t *nbGetUnitVisual(datUnitWork_t *work);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
void nbLoadUnitPackFile(nbFormation_t **form, s32 major, s32 minor);
s32 nbMakeUnitFadeInPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 col, s32 delay, s32 aframe, s32 colframe);
void nbReturnUnit(s32 partyno, s32 lost, s32 dead);
void nbSetFormationSideFlag(nbFormation_t *form, s32 index);
void nbSetHpScale(nbFormation_t *form);
void nbSetUnitMotion(nbFormation_t **form, s32 motion2, s32 mode, f32 ritu);
void nbSetWaitMotion(nbFormation_t **form, s32 motion, f32 ritu);
s16 rstGetEquipHeartsAisyo(void);

// 0x15bfc90
s32 CheckLoad(nbMainProcessData_t **data) {
  u64 v2;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v5;

  v2 = 0;
  while (1)
  {
    form = (*data)->form;
    v5 = form->m_Items[v2];
    if ((v5->stat & 1) != 0 && (v5->flag & 2) != 0)
      break;
    if (v2++ >= 0xF)
      return 0;
  }
  return 1;
}

// 0x15bb670
s32 GetDyingBadWaitMotion(nbFormation_t **form, s32 motion, datUnitWork_t **work) {
    nbGetMainProcessData();
    datCheckDying(0);
    Get(0);
    return 0;
}

// 0x15bf530
void RegistUnit(nbMainProcessData_t **data, s32 major, s32 minor, nbFormation_t **form, datUnitWork_t **w) {
    evtSetRegistUnit(0, 0);
    dds3GetActiveScene();
    dds3SearchSceneBasic(0, 0, 0);
    dds3LinkLightObjectToUnitObject(0, 0, 0);
    nbSetWaitMotion(0, 0, 0);
    nbSetUnitMotion(0, 0, 0, 0);
    nbGetModelColor(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    nbFormDispOff(0);
    evtSetUnitColorRGB(0, 0, 0);
    evtSetUnitColorA(0, 0, 0);
    nbGetUnitVisual(0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3ObjectBaseOffFlag(0, 0);
    ChkUseMarukage(0);
    mdlSetEffectScale(0, 0);
}

// 0x15bf030
void RunBadAction(nbMainProcessData_t **data, nbFormation_t **form) {
    dds3GetRandFloatA(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
}

// 0x15bf180
void RunDamage(nbMainProcessData_t **data, nbFormation_t **form) {
    mdlSetMotionSpeedAnimator(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    mdlGetMotionSpeedAnimator(0);
    nbSetUnitMotion(0, 0, 0, 0);
    dds3GetRandFloatA(0);
}

// 0x15bfd20
bool RunLoad(nbMainProcessData_t **data, nbFormation_t **form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 UnitID;
  u32 flag;
  s32 v11;
  u64 v12;
  struct nbFormation_t_array *v13;
  nbFormation_t_o *v15;
  bool v17;
  nbFormation_t_o *v19;
  u32 v20;
  System_String_o *akey;
  u32 v24;
  s32 v25;
  datUnitWork_t_o *w;

  w = 0;
  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  w = UnitWorkFromFormindex;
  UnitID = nbGetUnitID(UnitWorkFromFormindex);
  flag = (*form)->flag;
  v11 = UnitID;
  if ((flag & 1) == 0)
  {
    if ((flag & 2) == 0)
    if ((flag & 0x10) != 0)
    {
      nbLoadUnitPackFile(form, 1, v11);
      (*form)->flag &= ~0x10u;
      v19 = *form;
      v17 = 0;
      v20 = (*form)->flag | 0x20;
    }
    else
    {
      if ((flag & 0x20) != 0)
      {
        if (nbCheckLoadUnitPackFile_MSE(form, 1, v11, 1))
        {
          (*form)->flag &= ~0x20u;
          (*form)->flag |= 0x40u;
          nbCheckLoadUnitPackFile_ModelInit(form);
        }
      }
      if ((flag & 0x40) == 0)
      if (!nbCheckLoadUnitPackFile_Model(form, 1, v11, 1))
      {
        v17 = 0;
      }
      v17 = 1;
      RegistUnit(data, 1, v11, form, &w);
      v19 = *form;
      v20 = (*form)->flag & 0xFFFFFFDF;
    }
    v19->flag = v20;
    (*form)->flag &= ~0x40u;
    if (((*form)->flag & 0xC) != 4)
      return v17;
    akey = (*form)->akey;
    LoadBossAIMSG(akey);
    dds3GetRandIntA(0, StringLiteral_416);
    if (((*form)->anime & 0x200) != 0)
    {
      v25 = (*form)->formindex;
      nbFormDispOff(v25);
      (*form)->anime &= ~0x200u;
      v24 = UnitWorkFromFormindex->badstatus & 0xFFF;
      if ((UnitWorkFromFormindex->badstatus & 0xFFF) == 0)
    }
    else
    {
      nbMakeUnitFadeInPacket(0, 0, form, 0, 15, 15, 20);
      v24 = UnitWorkFromFormindex->badstatus & 0xFFF;
      if ((UnitWorkFromFormindex->badstatus & 0xFFF) == 0)
    }
    nbAddBadEffKoukaPacket(1, 0, form, v24);
    nbAddBadMotKoukaPacket(1, 0, form, UnitWorkFromFormindex->badstatus & 0xFFF);
    (*form)->flag &= ~4u;
    (*form)->type = 0;
    return v17;
  }
  v12 = 0;
  while (1)
  {
    v13 = (*data)->form;
    v15 = v13->m_Items[v12];
    if ((v15->stat & 1) != 0 && (v15->flag & 2) != 0)
      return 0;
    if (v12++ >= 0xF)
    {
      (*form)->flag &= ~1u;
      (*form)->flag |= 2u;
      (*form)->flag |= 0x10u;
      flag = (*form)->flag;
    }
  }
}

// 0x15bee50
void RunSake(nbMainProcessData_t **data, nbFormation_t **form) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
}

// 0x15be6f0
void UpdateFormAnime(nbMainProcessData_t **data, nbFormation_t **form, datUnitWork_t **work) {
  datUnitWork_t_o *v7;
  s32 id;
  struct datUnitMotion_s_array *motion;
  s32 v12;
  evtUnitHandle_t_o **p_hunit;
  evtUnitHandle_t_o **v15;
  evtUnitHandle_t_o **v18;
  nbFormation_t_o *v20;
  f32 addmovet;
  f32 v22;
  nbFormation_t_o *v23;
  nbFormation_t_o *v24;
  dds3Basic_t_o **p_basic;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  u32 anime;
  UnityEngine_Vector4_o tarpos;
  UnityEngine_Vector4_o v33;

  if (((*form)->stat & 2) != 0 && ((*data)->stat & 0x1000) == 0)
  {
    v7 = *work;
    id = (*work)->id;
    if ((*work)->id)
    {
      motion = Get(id, 0)->motion;
      if (!motion->m_Items[22]->motion_no)
      v7 = *work;
    }
    v12 = datCheckDying(v7);
    p_hunit = &(*form)->hunit;
    if (v12)
    {
      if (mdlGetMotionMinorNumForUnity(p_hunit, 0) == 22)
      v15 = &(*form)->hunit;
      if ((mdlGetMotionMinorNumForUnity(v15, 0) | 2) != 2)
      nbSetWaitMotion(form, 0, 1.0);
      nbSetUnitMotion(form, 0, 1, 1.0);
    }
    if (mdlGetMotionMinorNumForUnity(p_hunit, 0) == 22)
    {
      v18 = &(*form)->hunit;
      if (mdlGetMotionMinorNumForUnity(v18, 0) == 22)
    }
  }
  v20 = *form;
  if (((*form)->anime & 0x60) != 0)
  {
    addmovet = v20->addmovet;
    v22 = (1.0 - v20->movet) * addmovet;
    v20->addmovet = addmovet + 0.02;
    (*form)->movet = (*form)->movet + fmaxf(v22, 0.01);
    v23 = *form;
    if ((*form)->movet > 1.0)
    {
      v23->movet = 1.0;
      v23 = *form;
    }
    SDF_VU0__LOADVECTOR(v23->startpos);
    SDF_VU0__SCALEVECTOR(1.0 - (*form)->movet, 0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    v24 = *form;
    if (((*form)->anime & 0x20) != 0)
      tarpos = v24->tarpos;
    else
      tarpos = v24->orgpos;
    SDF_VU0__LOADVECTOR(tarpos);
    SDF_VU0__SCALEVECTOR((*form)->movet, 0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__STOREVECTOR(&(*form)->pos, 0);
    v20 = *form;
    p_basic = &(*form)->basic;
    if (*p_basic)
    {
      x = v20->pos.x;
      y = v20->pos.y;
      z = v20->pos.z;
      w = v20->pos.w;
      v33.x = x;
      v33.y = y;
      v33.z = z;
      v33.w = w;
      dds3SetPosPoseSet(p_basic, v33);
      v20 = *form;
    }
    if (v20->movet >= 1.0)
    {
      anime = v20->anime;
      if ((anime & 0x40) != 0)
      {
        v20->stat &= ~0x10u;
        v20 = *form;
        anime = (*form)->anime;
      }
      v20->anime = anime & 0xFFFFFFDF;
      (*form)->anime &= ~0x40u;
      v20 = *form;
    }
  }
  if ((v20->anime & 0x400) != 0)
    nbSetHpScale(v20);
}

// 0x15beae0
void UpdateFormPosRot(nbFormation_t **form) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
}

// 0x15bab00
void mdlAnimSetBattle(evtUnitHandle_t **h, s32 motion) {
    mdlGetMinorNum(0);
    AnimClipSearch(0, 0, 0);
    evtBitCheck(0);
    ResetStateNormalizedTimeOffset(0);
    UpdateNormalizeTime(0);
    mdlAnimSetBattleQuickWait(0, 0, 0);
    mdlMotionSub(0, 0, 0);
    ResetFlag(0, 0, 0);
}

// 0x15bb510
bool mdlAnimSetBattleLoop(evtUnitHandle_t **h, s32 new_motion) {
  UnityEngine_Object_o *modelanm;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;

  if (!*h)
    return 0;
  modelanm = (*h)->modelanm;
  if (op_Equality(modelanm, 0, 0))
    return 0;
  transform = get_transform((*h)->modelobj, 0);
  Child = GetChild(transform, 0);
  gameObject = get_gameObject(Child);
  Component_object = GetComponent_object_(gameObject);
  if (!op_Inequality(Component_object, 0, 0))
    return 0;
  if (!IsBtlMotionFinished(Component_object))
    return 0;
  mdlAnimSetBattle(h, new_motion);
  return 1;
}

// 0x15bb150
s32 mdlAnimSetBattleQuickWait(evtUnitHandle_t *h, s32 old_motion, s32 motion) {
  dds3ModelHandle_t_o **p_Model;
  s32 MinorNum;
  u32 v10;
  s32 result;
  s32 v12;
  _BOOL4 v13;
  bool v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  bool v20;
  _BOOL4 v21;
  s32 v22;
  s32 v23;
  s32 v24;

  p_Model = &h->Model;
  MinorNum = mdlGetMinorNum(p_Model);
  if (!IsModelDante(MinorNum))
  {
    else  }
  if ((old_motion - 109) < 0xA)
  {
    v10 = (0x383u >> (old_motion - 109)) & 1;
  }
  v10 = 0;
  result = motion + 100;
  v12 = (old_motion == 108 && MinorNum == 0) | v10;
  if (MinorNum == 35)
  {
    v16 = (old_motion == 103) | v12;
    v14 = (old_motion | 1) == 109;
  }
  else
  {
    if (MinorNum == 33)
    {
      v15 = (old_motion == 103) | v12;
      v13 = (old_motion | 1) == 109;
      v14 = old_motion == 110;
    }
    else
    {
      if (MinorNum != 16)
      v13 = old_motion == 108;
      v14 = old_motion == 112;
      v15 = (old_motion == 103) | v12;
    }
    v16 = v13 | v15;
  }
  v17 = v14;
  v12 = v17 | v16;
  v18 = (old_motion == 112 && MinorNum == 69)
      | (old_motion == 112 && MinorNum == 56)
      | (old_motion == 108 && MinorNum == 45)
      | v12;
  if (MinorNum == 75)
  {
    v19 = (old_motion == 104) | v18;
    v20 = (old_motion | 4) == 111;
    v21 = v20;
  }
  v22 = (old_motion == 112 && MinorNum == 95) | (old_motion == 116 && MinorNum == 79) | v18;
  if (MinorNum != 301 && MinorNum != 100)
  {
    if (MinorNum == 99)
    {
      v21 = old_motion == 112;
      v19 = (old_motion == 108) | (old_motion == 103) | v22;
      v22 = v21 | v19;
    }
    v23 = MinorNum - 102;
  }
  v22 |= old_motion == 112 || old_motion == 108 || old_motion == 103;
  v23 = MinorNum - 102;
  if ((MinorNum - 102) <= 0x1D)
  {
    switch (v23)
    {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 22:
      case 24:
      case 25:
      case 26:
      case 28:
      case 23:
      case 27:
        if ((v22 & 1) != 0 || (old_motion - 103) <= 7 && ((1 << (old_motion - 103)) & 0xA1) != 0)
          return motion + 200;
        break;
      case 29:
      default:
    }
    return result;
  }
  if (MinorNum == 319)
    v22 |= old_motion == 109 || (old_motion | 2) == 110 || old_motion == 103;
  v24 = (old_motion == 108 && MinorNum == 142) | v22;
  if (MinorNum != 143)
  {
    v22 = (old_motion == 112 && MinorNum == 147) | v24;
    if (MinorNum != 315 && MinorNum != 168)
    {
      if (MinorNum == 205 || MinorNum == 355 || MinorNum == 299)
      {
        if ((v22 & 1) == 0 && ((old_motion - 103) > 9 || ((1 << (old_motion - 103)) & 0x221) == 0))
          return result;
      }
      else if (!v22)
      {
        return result;
      }
      return motion + 200;
    }
    v19 = (old_motion == 103) | v22;
    v20 = (old_motion | 1) == 109;
  }
  if (old_motion == 112 || old_motion == 108 || (old_motion == 103) | v24 & 1)
    return motion + 200;
  return result;
}

// 0x15ba720
s32 mdlChkMotionEnd(nbFormation_t *form) {
  UnityEngine_Object_o *modelanm;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;

  modelanm = form->modelanm;
  if (op_Equality(modelanm, 0, 0))
    return 1;
  transform = get_transform(form->modelobj, 0);
  Child = GetChild(transform, 0);
  gameObject = get_gameObject(Child);
  Component_object = GetComponent_object_(gameObject);
  return op_Equality(Component_object, 0, 0) || IsFinished(Component_object, 0, 0);
}

// 0x15ba830
s32 mdlChkMotionEndBattle(evtUnitHandle_t *h, void *chr_trans, void *mAnimator) {
    GetStateNormalizedTimeOffset(0);
    return 0;
}

// 0x15ba9c0
s32 mdlChkMotionEndBattleDying(evtUnitHandle_t *h, void *chr_trans, void *mAnimator) {
  s32 result;
  s32 Integer_8773456;
  evtUnitHandle_t_o *v11;
  evtUnitHandle_t_o *ha;

  ha = h;
  if (op_Equality(mAnimator, 0, 0))
    return 0;
  if (h->WaitMotion != 22)
    return 0;
  Integer_8773456 = GetInteger_8773456(mAnimator, id_anim);
  result = mdlGetMotionMinorNumForUnity(&ha, 0);
  if (result)
  {
    if (Integer_8773456 == 100 || Integer_8773456 == 0)
    {
      v11 = ha;
      ha->Model->motionMajorNum = 0;
      result = 1;
      v11->Model->motionMinorNum = 0;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

// 0x15ba710
s32 mdlGetMotionLength(dds3ModelHandle_t *aHandle) {
  return 0;
}

// 0x15bc6a0
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex) {
    nbGetUnitID(0);
    nbGetUnitVisual(0);
    rstGetEquipHeartsAisyo();
    Get(0);
    datGetAisyo(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    nbGetMotionNo(0, 0);
}

// 0x15be5b0
s32 nbCheckLoad(nbFormation_t **form) {
  return ((*form)->stat & 0x43) == 0x41 && (((*form)->flag >> 2) & 1) == 0;
}

// 0x15be5e0
s32 nbCheckLoadGroup(s32 side) {
  u64 v2;
  nbMainProcessData_t_o *MainProcessData;
  s32 v4;
  u64 v5;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v8;

  LODWORD(v2) = side;
  MainProcessData = nbGetMainProcessData();
  if (!v2)
  if (v2 != 1)
    return 0;
  LODWORD(v2) = 4;
  v4 = 10;
  v5 = (v2 + v4);
  while (1)
  {
    form = MainProcessData->form;
    v8 = form->m_Items[v2];
    if ((v8->stat & 0x43) == 0x41 && (v8->flag & 4) == 0)
      break;
    if (++v2 >= v5)
      return 0;
  }
  return 1;
}

// 0x15bf520
s32 nbCheckModelLoad(nbMainProcessData_t **data, s32 major, s32 minor) {
  return 0;
}

// 0x15ba6e0
void nbDeleteSound(s32 id) {
  ;
}

// 0x15bc3a0
s32 nbGetMotionActframe(nbFormation_t **form, s32 motion, f32 ritu) {
  u32 v4;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct datUnitMotion_s_array *v12;

  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  v12 = nbGetUnitVisual(UnitWorkFromFormindex)->motion;
  LOWORD(v4) = v12->m_Items[motion]->actframe;
  return (v4 / nbGetMotionSpeed(form, motion, ritu));
}

// 0x15bc2c0
s32 nbGetMotionEndData(nbFormation_t **form, s32 motion) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct datUnitMotion_s_array *v8;

  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  v8 = nbGetUnitVisual(UnitWorkFromFormindex)->motion;
  return v8->m_Items[motion]->se_endframe;
}

// 0x15bc1e0
s32 nbGetMotionEndType(nbFormation_t **form, s32 motion) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct datUnitMotion_s_array *v8;

  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  v8 = nbGetUnitVisual(UnitWorkFromFormindex)->motion;
  return v8->m_Items[motion]->se_endtype;
}

// 0x15bc000
s32 nbGetMotionNo(nbFormation_t **form, s32 motion) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitVisual_t_o *UnitVisual;
  struct datUnitMotion_s_array *v10;
  struct datUnitMotion_s_array *v12;
  struct datUnitMotion_s_array *v14;
  nbFormation_t_o *v15;
  struct datUnitMotion_s_array *v17;

  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  nbGetUnitID(UnitWorkFromFormindex);
  UnitVisual = nbGetUnitVisual(UnitWorkFromFormindex);
  v10 = UnitVisual->motion;
  (*form)->cr = v10->m_Items[motion]->atarisize;
  (*form)->cr = (*form)->cr * (*form)->scl;
  v12 = UnitVisual->motion;
  (*form)->movey = v12->m_Items[motion]->movey;
  v14 = UnitVisual->motion;
  v15 = *form;
  v15->movez = v14->m_Items[motion]->movez;
  v17 = nbGetUnitVisual(UnitWorkFromFormindex)->motion;
  return v17->m_Items[motion]->motion_no;
}

// 0x15bc4b0
s32 nbGetMotionNoOrg(nbFormation_t **form, s32 motion) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 UnitID;
  datUnitVisual_t_o *UnitVisual;
  struct datUnitMotion_s_array *v11;
  struct datUnitMotion_s_array *v13;
  struct datUnitMotion_s_array *v15;
  nbFormation_t_o *v16;
  void **v18;
  u32 *v19;
  s64 v20;

  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  UnitID = nbGetUnitID(UnitWorkFromFormindex);
  UnitVisual = nbGetUnitVisual(UnitWorkFromFormindex);
  v11 = UnitVisual->motion;
  (*form)->cr = v11->m_Items[motion]->atarisize;
  (*form)->cr = (*form)->cr * (*form)->scl;
  v13 = UnitVisual->motion;
  (*form)->movey = v13->m_Items[motion]->movey;
  v15 = UnitVisual->motion;
  v16 = *form;
  v16->movez = v15->m_Items[motion]->movez;
  if (UnitID)
  {
    v18 = &datDevilVisual;
  }
  else
  {
    v18 = &datHuman;
  }
  if (!v19[54])
  {
    v19 = *v18;
  }
  v20 = **(v19 + 23);
  return *(v20 + motion + 32);
}

// 0x15bbf00
f32 nbGetMotionSpeed(nbFormation_t **form, s32 motion, f32 ritu) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct datUnitMotion_s_array *v10;
  f32 result;

  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  v10 = nbGetUnitVisual(UnitWorkFromFormindex)->motion;
  result = v10->m_Items[motion]->motionsp;
  if (ritu != 1.0)
    return result * ritu;
  return result;
}

// 0x15c05a0
void nbInitUnitProcess(nbMainProcessData_t **data) {
  u64 *v3;
  u64 *v4;
  u64 *v6;
  dds3ProcessID_t_o *started;
  dds3ProcessID_t_o *target;

  target = 0;
  started = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_nbUnitProcess_nbUnitProcess2__);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbUnitProcess_nbUnitShutdown__);
  target = dds3StartProcess(StringLiteral_21678, 0x3F9u, 1, 1, v3, 0, v4, 0, 0, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->UnitProcessID = target;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbUnitProcess_nbUnitDrawProcess1__);
  started = dds3StartProcess(StringLiteral_21679, 0x2B0Eu, 1, 1, v6, 0, 0, 0, 0, 0);
  dds3LinkProcess(&target, &started);
}

// 0x15ba6f0
s32 nbLoadSound(s32 id) {
  return 0;
}

// 0x15bd330
void nbLoadUnit(nbFormation_t **form, s32 stop, s32 anime) {
  if (((*form)->stat & 0x43) == 0x41)
  {
    (*form)->type = 4;
    (*form)->time = 0;
    (*form)->flag &= 0xFFFFFFF9;
    (*form)->flag |= 1u;
    if (stop)
      (*form)->flag |= 8u;
    if (!anime)
      (*form)->anime |= 0x200u;
  }
}

// 0x15be390
void nbLoadUnitGroup(s32 side, s32 stop, s32 anime) {
    nbGetMainProcessData();
}

// 0x15bd960
void nbResetUnitAnime(s32 partyno, s32 animetype) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbFormation_t_array *form;
  struct nbParty_t_array *v11;
  u32 formindex;
  nbFormation_t_o *v15;

  MainProcessData = nbGetMainProcessData();
  party = MainProcessData->party;
  if ((party->m_Items[partyno]->flag & 1) != 0)
  {
    v8 = MainProcessData->party;
    if ((v8->m_Items[partyno]->flag & 8) == 0)
    {
      form = MainProcessData->form;
      v11 = MainProcessData->party;
      formindex = v11->m_Items[partyno]->formindex;
      if (!animetype)
      {
        v15 = form->m_Items[formindex];
        v15->anime = v15->anime & 0xFFFFFFFC | 2;
      }
    }
  }
}

// 0x15bd3b0
void nbReturnAllEnemyUnit(void) {
  nbReturnUnit(4, 0, 0);
  nbReturnUnit(5, 0, 0);
  nbReturnUnit(6, 0, 0);
  nbReturnUnit(7, 0, 0);
  nbReturnUnit(8, 0, 0);
  nbReturnUnit(9, 0, 0);
  nbReturnUnit(10, 0, 0);
  nbReturnUnit(11, 0, 0);
  nbReturnUnit(12, 0, 0);
  nbReturnUnit(13, 0, 0);
}

// 0x15bd460
void nbReturnUnit(s32 partyno, s32 lost, s32 dead) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbParty_t_array *party;
  nbMainProcessData_t_o *v10;
  nbParty_t_o *v12;
  s16 flag;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v16;
  UnityEngine_Object_o *modelobj;
  UnityEngine_Object_o *v19;
  s32 formindex;
  datUnitWork_t_o *UnitWorkPointer;
  s16 v23;
  datUnitWork_t_o *v24;
  u16 badstatus;
  u32 v26;
  s16 v27;
  s32 v28;
  effBTLSysHandle_t_o *hEffBTLSys;

  hEffBTLSys = 0;
  MainProcessData = nbGetMainProcessData();
  party = MainProcessData->party;
  v10 = MainProcessData;
  v12 = party->m_Items[partyno];
  flag = v12->flag;
  if ((flag & 1) != 0)
  {
    if ((flag & 8) == 0)
    {
      form = MainProcessData->form;
      v16 = form->m_Items[v12->formindex];
      if ((v16->stat & 2) != 0)
      {
        dds3DeleteSceneBasicData(&v16->basic);
        v16->basic = 0;
        v16->serial = 0;
        v16->hunit = 0;
        modelobj = v16->modelobj;
        if (op_Inequality(modelobj, 0, 0))
        {
          v19 = v16->modelobj;
          Destroy_27360000(v19);
          v16->modelobj = 0;
        }
      }
      if ((v16->anime & 0x100) != 0 && v16->badeff)
      {
        hEffBTLSys = v16->badeff;
        effBTLSystemDelete2(&hEffBTLSys);
        v16->badeff = 0;
      }
      *&v16->stat = 0;
      v16->anime = 0;
      v16->type = 0;
      v16->partyindex = 0;
      formindex = v12->formindex;
      nbSetFormationSideFlag(v16, formindex);
      v12->flag |= 8u;
    }
    UnitWorkPointer = nbGetUnitWorkPointer(v10, v12);
    v23 = v12->flag;
    v24 = UnitWorkPointer;
    if ((v23 & 2) != 0)
    {
      UnitWorkPointer->flag = 0;
    }
    else if ((v23 & 4) == 0)
    {
      if (lost)
      {
        UnitWorkPointer->flag = 0;
        badstatus = UnitWorkPointer->badstatus;
        v26 = badstatus & 0xFFF;
        if (dead)
        {
          if (v26 == 512)
          {
            UnitWorkPointer->badstatus = badstatus & 0xFDFF;
            v24->maxhp = datGetMaxHp(v24);
            v24->maxmp = datGetMaxMp(v24);
          }
          v24->badstatus = 2048;
          v24->hp = 0;
          datClearCommMemory(v24);
          v27 = v12->flag;
          if ((v27 & 2) != 0)
        }
      }
      else
      {
        UnitWorkPointer->flag &= ~2u;
        badstatus = UnitWorkPointer->badstatus;
        v26 = badstatus & 0xFFF;
        if (dead)
      }
      if (v26 <= 4)
      {
        if (v26 != 4 && v26 - 1 >= 2)
      }
      else
      {
        v28 = badstatus & 0xFFF;
        if (v28 != 8 && v28 != 128 && v28 != 16)
      }
      UnitWorkPointer->badstatus = badstatus & 0xF000;
    }
    v27 = v12->flag;
    if ((v27 & 2) != 0)
    {
      --v10->enemypcnt;
      *&v12->flag = -65536;
      v12->statindex = -1;
      return;
    }
    if ((v27 & 4) == 0)
      --v10->playerpcnt;
  }
}

// 0x15be0e0
void nbSetBadstatMotion(nbFormation_t **form, s32 type, f32 range) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbParty_t_array *party;
  datUnitWork_t_o *UnitWorkPointer;
  datUnitWork_t_o *v11;
  struct nbFormData_t_o *data1;
  u32 v14;
  f32 mf;
  u32 v16;

  MainProcessData = nbGetMainProcessData();
  (*form)->type = 3;
  (*form)->time = 0;
  (*form)->tartime = 0;
  (*form)->range = range;
  party = MainProcessData->party;
  UnitWorkPointer = nbGetUnitWorkPointer(MainProcessData, party->m_Items[(*form)->partyindex], 0);
  if (((*form)->stat & 0x40) != 0)
  {
    v11 = UnitWorkPointer;
    nbSetUnitMotion(form, 1, 0, 1.0);
    data1 = (*form)->data1;
    LOWORD(v14) = nbGetUnitVisual(v11)->badframe;
    data1->mf = v14;
    mf = (*form)->data1->mf;
    v16 = mf;
    if (mf >= 0.0)
      v16 = mf;
    (*form)->tartime = v16;
  }
}

// 0x15be250
void nbSetBadstatMotion2(nbFormation_t **form) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbParty_t_array *party;
  UnityEngine_Animator_o *modelanm;

  MainProcessData = nbGetMainProcessData();
  (*form)->type = 0;
  (*form)->time = 0;
  (*form)->tartime = 0;
  party = MainProcessData->party;
  nbGetUnitWorkPointer(MainProcessData, party->m_Items[(*form)->partyindex], 0);
  if (((*form)->stat & 0x40) != 0)
  {
    nbSetUnitMotion(form, 1, 0, 1.0);
    modelanm = (*form)->modelanm;
    mdlSetMotionSpeedAnimator(modelanm, 0.0);
    (*form)->anime |= 0x80u;
  }
}

// 0x15bdf50
void nbSetDamage(nbFormation_t **form, f32 range, s32 week) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v10;
  struct nbFormData_t_o *data1;
  u32 v13;
  f32 mf;
  u32 v15;

  (*form)->type = 1;
  (*form)->time = 0;
  (*form)->tartime = 20;
  (*form)->range = range;
  (*form)->data1->mf = 0.0;
  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (((*form)->stat & 0x40) != 0)
  {
    v10 = UnitWorkFromFormindex;
    nbSetUnitMotion(form, 1, 0, 1.0);
    if (!week)
    {
      data1 = (*form)->data1;
      LOWORD(v13) = nbGetUnitVisual(v10)->badframe;
      data1->mf = v13;
      mf = (*form)->data1->mf;
      v15 = mf;
      if (mf >= 0.0)
        v15 = mf;
      (*form)->tartime = v15;
    }
  }
}

// 0x15be0a0
void nbSetDamage2(nbFormation_t **form, f32 range) {
  (*form)->type = 1;
  (*form)->time = 0;
  (*form)->tartime = 20;
  (*form)->range = range;
  (*form)->data1->mf = 0.0;
}

// 0x15bb800
void nbSetNegoWaitMotion(nbFormation_t **form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 v6;
  bool v7;

  formindex = (*form)->formindex;
  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (!UnitWorkFromFormindex)
      return;
  }
  v6 = UnitWorkFromFormindex->badstatus & 0xFFF;
  v7 = v6 == 4 || v6 == 8;
  if (!v7 && v6 != 512)
  {
    nbSetWaitMotion(form, 13, 1.0);
    nbSetUnitMotion(form, 13, 0, 1.0);
  }
}

// 0x15bdf10
void nbSetSake(nbFormation_t **form, f32 range, f32 speed) {
  (*form)->type = 2;
  (*form)->range = range;
  (*form)->movet = 0.0;
  (*form)->addmovet = speed;
  (*form)->data1->mf = speed;
}

// 0x15bd810
void nbSetUnitAnime(s32 partyno, s32 animetype) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbFormation_t_array *form;
  struct nbParty_t_array *v11;
  u32 formindex;
  nbFormation_t_o *v15;

  MainProcessData = nbGetMainProcessData();
  party = MainProcessData->party;
  if ((party->m_Items[partyno]->flag & 1) != 0)
  {
    v8 = MainProcessData->party;
    if ((v8->m_Items[partyno]->flag & 8) == 0)
    {
      form = MainProcessData->form;
      v11 = MainProcessData->party;
      formindex = v11->m_Items[partyno]->formindex;
      if (!animetype)
      {
        v15 = form->m_Items[formindex];
        v15->anime = v15->anime & 0xFFFFFFFC | 1;
      }
    }
  }
}

// 0x15bdcf0
void nbSetUnitHomeMove(s32 partyno, f32 speed) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbFormation_t_array *form;
  struct nbParty_t_array *v11;
  nbFormation_t_o *v14;
  u32 v15;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o orgpos;
  UnityEngine_Vector4_o v22;
  UnityEngine_Vector4_o pos;

  MainProcessData = nbGetMainProcessData();
  party = MainProcessData->party;
  if ((party->m_Items[partyno]->flag & 1) != 0)
  {
    v8 = MainProcessData->party;
    if ((v8->m_Items[partyno]->flag & 8) == 0)
    {
      form = MainProcessData->form;
      v11 = MainProcessData->party;
      v14 = form->m_Items[v11->m_Items[partyno]->formindex];
      if (speed == 1.0)
      {
        orgpos = v14->orgpos;
        v15 = v14->anime & 0xFFFFFF9F;
        v14->stat &= ~0x10u;
        v14->anime = v15;
        SDF_VU0__COPYVECTOR(&v14->pos, orgpos);
        if (v14->basic)
        {
          x = v14->orgpos.x;
          y = v14->orgpos.y;
          z = v14->orgpos.z;
          w = v14->orgpos.w;
          v22.x = x;
          v22.y = y;
          v22.z = z;
          v22.w = w;
          dds3SetPosPoseSet(&v14->basic, v22);
        }
      }
      else
      {
        pos = v14->pos;
        v14->anime = v14->anime & 0xFFFFFF9F | 0x40;
        SDF_VU0__COPYVECTOR(&v14->startpos, pos);
        SDF_VU0__COPYVECTOR(&v14->tarpos, v14->orgpos);
        v14->movet = 0.0;
        v14->addmovet = speed;
      }
    }
  }
}

// 0x15bbac0
void nbSetUnitMotion(nbFormation_t **form, s32 motion2, s32 mode, f32 ritu) {
  u64 *v9;
  nbMainProcessData_t_o *MainProcessData;
  nbFormation_t_o *v12;
  struct nbParty_t_array *party;
  u32 partyindex;
  datUnitWork_t_o *UnitWorkPointer;
  datUnitWork_t_o *v18;
  datUnitVisual_t_o *UnitVisual;
  s32 DyingBadWaitMotion;
  f32 MotionSpeed;
  s32 MotionNo;
  s32 nexthokanb;
  s32 v28;
  s32 nexthokan;
  UnityEngine_Animator_o *modelanm;
  struct datUnitMotion_s_array *motion;
  struct datUnitMotion_s_array *v34;
  s32 v36;
  s32 v37;
  struct datUnitMotion_s_array *v39;
  struct datUnitMotion_s_array *v41;
  nbFormation_t_o *v43;
  datUnitWork_t_o *v44;
  evtUnitHandle_t_o *h;

  v44 = 0;
  v9 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v9);
  h = v9;
  MainProcessData = nbGetMainProcessData();
  v12 = *form;
  h = (*form)->hunit;
  party = MainProcessData->party;
  partyindex = v12->partyindex;
  UnitWorkPointer = nbGetUnitWorkPointer(MainProcessData, party->m_Items[partyindex]);
  v44 = UnitWorkPointer;
  if (((*form)->anime & 0x80) == 0)
  {
    v18 = UnitWorkPointer;
    UnitVisual = nbGetUnitVisual(v18);
    DyingBadWaitMotion = GetDyingBadWaitMotion(UnitVisual, motion2, &v44);
    MotionSpeed = nbGetMotionSpeed(form, DyingBadWaitMotion, ritu);
    MotionNo = nbGetMotionNo(form, DyingBadWaitMotion);
    nexthokanb = 0;
    v28 = 15;
    nexthokan = DyingBadWaitMotion;
    switch (DyingBadWaitMotion)
    {
      case 0:
      case 2:
      case 13:
      case 22:
        nexthokanb = (*form)->nexthokanb;
        nexthokan = (*form)->nexthokan;
        if (DyingBadWaitMotion <= 2)
      case 1:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 24:
      case 25:
        nexthokanb = 0;
        v28 = 0;
      case 14:
      case 15:
        if (DyingBadWaitMotion != 22)
      case 23:
        nexthokanb = (*form)->nexthokanb;
        nexthokan = (*form)->nexthokan;
      default:
        nexthokan = 0;
        if (DyingBadWaitMotion > 2)
        {
          v28 = nexthokan;
          if (DyingBadWaitMotion == 22)
          {
            nexthokan = v28;
          }
          else
          {
            nexthokan = v28;
            if (DyingBadWaitMotion != 13)
          }
        }
        else
        {
          if ((DyingBadWaitMotion | 2) != 2)
          {
            evtSetUnitMotion(&h, MotionNo, nexthokanb, nexthokan, mode);
          }
        }
        if (mdlGetMotionMinorNumForUnity(&h, 0) != MotionNo)
        modelanm = (*form)->modelanm;
        mdlSetMotionSpeedAnimator(modelanm, MotionSpeed);
        (*form)->motspeed = MotionSpeed;
        motion = UnitVisual->motion;
        (*form)->nexthokan = motion->m_Items[DyingBadWaitMotion]->hframe;
        v34 = UnitVisual->motion;
        (*form)->nexthokanb = v34->m_Items[DyingBadWaitMotion]->bframe;
        if (mode == 3 || !mode)
        {
          v36 = (*form)->nexthokanb;
          v37 = (*form)->nexthokan;
          evtSetWaitHokanFrame(&h, v36, v37);
          v39 = UnitVisual->motion;
          (*form)->nexthokan = v39->m_Items[(*form)->waitmot]->hframe;
          v41 = UnitVisual->motion;
          (*form)->nexthokanb = v41->m_Items[(*form)->waitmot]->bframe;
          if (mode == 3 && (*form)->motendtype == 2)
          {
            v43 = *form;
            v43->motspeed = nbGetMotionSpeed(form, 0, 1.0);
          }
        }
        break;
    }
  }
}

// 0x15bdab0
void nbSetUnitMove(s32 partyno, sdfVector4_t pos, f32 speed) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  nbMainProcessData_t_o *MainProcessData;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v13;
  struct nbFormation_t_array *form;
  struct nbParty_t_array *v16;
  nbFormation_t_o *v19;
  u32 anime;
  u32 v21;
  dds3Basic_t_o **p_basic;
  struct dds3Basic_t_o *basic;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o v28;

  w = pos.w;
  z = pos.z;
  y = pos.y;
  x = pos.x;
  MainProcessData = nbGetMainProcessData();
  party = MainProcessData->party;
  if ((party->m_Items[partyno]->flag & 1) != 0)
  {
    v13 = MainProcessData->party;
    if ((v13->m_Items[partyno]->flag & 8) == 0)
    {
      form = MainProcessData->form;
      v16 = MainProcessData->party;
      v19 = form->m_Items[v16->m_Items[partyno]->formindex];
      anime = v19->anime;
      v19->stat |= 0x10u;
      v21 = anime & 0xFFFFFF9F;
      if (speed == 1.0)
      {
        v25.x = x;
        v25.y = y;
        v25.z = z;
        v25.w = w;
        v19->anime = v21;
        SDF_VU0__COPYVECTOR(&v19->pos, v25);
        basic = v19->basic;
        p_basic = &v19->basic;
        if (basic)
        {
          v26.x = x;
          v26.y = y;
          v26.z = z;
          v26.w = w;
          dds3SetPosPoseSet(p_basic, v26);
        }
      }
      else
      {
        v27 = v19->pos;
        v19->anime = v21 | 0x20;
        SDF_VU0__COPYVECTOR(&v19->startpos, v27);
        v28.x = x;
        v28.y = y;
        v28.z = z;
        v28.w = w;
        SDF_VU0__COPYVECTOR(&v19->tarpos, v28);
        v19->movet = 0.0;
        v19->addmovet = speed;
      }
    }
  }
}

// 0x15bb8f0
void nbSetWaitMotion(nbFormation_t **form, s32 motion, f32 ritu) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 DyingBadWaitMotion;
  struct datUnitMotion_s_array *v13;
  s32 motion_no;
  struct datUnitMotion_s_array *v17;
  f32 motionsp;
  evtUnitHandle_t_o **p_hunit;
  f32 v21;
  datUnitWork_t_o *work;

  work = 0;
  formindex = (*form)->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  work = UnitWorkFromFormindex;
  DyingBadWaitMotion = GetDyingBadWaitMotion(UnitWorkFromFormindex, motion, &work);
  nbGetUnitID(UnitWorkFromFormindex);
  v13 = nbGetUnitVisual(UnitWorkFromFormindex)->motion;
  motion_no = v13->m_Items[DyingBadWaitMotion]->motion_no;
  v17 = nbGetUnitVisual(UnitWorkFromFormindex)->motion;
  motionsp = v17->m_Items[DyingBadWaitMotion]->motionsp;
  p_hunit = &(*form)->hunit;
  v21 = motionsp * ritu;
  evtSetWaitMotion(p_hunit, motion_no);
  evtSetWaitMotionSpeed(&(*form)->hunit, v21, 0);
  (*form)->waitmot = DyingBadWaitMotion;
}

// 0x15bd220
void nbSummonUnit(s32 side, s32 stockno, s32 formindex) {
  struct nbFormation_t_array *form;
  Il2CppClass **v10;
  char *v11;
  Il2CppClass *v12;
  Il2CppClass *v13;
  nbMainProcessData_t_o *data;

  data = 0;
  data = nbGetMainProcessData();
  nbAddUnitStock(&data, side, stockno, formindex);
  form = data->form;
  v10 = &form->obj.klass + formindex;
  v13 = v10[4];
  v11 = (v10 + 4);
  v12 = v13;
  if ((v13->_1.events & 0x43) == 0x41)
  {
    LODWORD(v12->_1.fields) = 4;
    *(*v11 + 132LL) = 0;
    *(*v11 + 140LL) &= 0xFFFFFFF9;
    *(*v11 + 140LL) |= 1u;
  }
}

// 0x15beb90
void *nbUnitDrawProcess1(dds3ProcessID_t *id) {
    nbGetMainProcessData();
    GetTargetMark2D(0);
    nbDrawTargetCursor(0, 0, 0, 0);
    TargetMark2DAnim(0);
    effBTLSystemDraw(0);
    return 0;
}

// 0x15c0150
void *nbUnitProcess2(dds3ProcessID_t *id) {
    nbGetMainProcessData();
    nbGetUnitWorkFromFormindex(0);
    RunBadAction(0, 0);
    RunDamage(0, 0);
    RunSake(0, 0);
    RunLoad(0, 0);
    mdlChkMotionEnd(0);
    nbSetUnitMotion(0, 0, 0, 0);
    UpdateFormAnime(0, 0, 0);
    UpdateFormPosRot(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0x15c0530
void *nbUnitShutdown(dds3ProcessID_t *id) {
  nbGetMainProcessData()->UnitProcessID = 0;
  return 0;
}

// 0x15ba700
void sdfMotionSeek(sdfMotionCtrlr_t *aCtrlr, f32 aFrame) {
  ;
}
