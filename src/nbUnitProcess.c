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
  s32 v5;

  v5 = motion;
  if ((nbGetMainProcessData()->stat & 0x1000) == 0)
    goto LABEL_6;
  return v5;
}

// 0x15bf530
void RegistUnit(nbMainProcessData_t **data, s32 major, s32 minor, nbFormation_t **form, datUnitWork_t **w) {
  s32 v12;
  u32 v14;
  dds3Basic_t_o *v16;
  Il2CppObject *workdata;
  dds3UnitObjectBasicWorkData_t_c *v18;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  struct evtUnitHandle_t_o **v21;
  struct evtUnitHandle_t_o *v22;
  s64 v23;
  struct evtUnitHandle_t_o *hunit;
  f32 z;
  struct evtUnitHandle_t_o *v26;
  f32 v28;
  UnityEngine_Object_o *modelobj;
  struct evtUnitHandle_t_o *v31;
  f32 v32;
  f32 v33;
  f32 v34;
  nbFormation_t_o *v37;
  f32 x;
  f32 y;
  f32 v41;
  f32 v42;
  nbFormation_t_o *v44;
  s64 v45;
  s64 v46;
  evtUnitHandle_t_o **p_hunit;
  datUnitWork_t_o *v50;
  s32 formindex;
  datUnitVisual_t_o *UnitVisual;
  datUnitVisual_t_o *v53;
  u32 v55;
  f32 v56;
  s32 v58;
  s32 v60;
  nbFormation_t_o *v61;
  f32 scl;
  dds3ModelHandle_t_o **p_Model;
  char *v64;
  s64 *v65;
  char *v66;
  s64 *v67;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *unitbasic;
  s64 v70;
  s64 v71;
  s64 v72;
  f32 v73;
  char *v74;
  UnityEngine_Vector4_o v75;
  UnityEngine_Vector4_o v76;

  v70 = 0;
  v71 = 0;
  pBasic = 0;
  unitbasic = 0;
  sub_854690(&v70, 0.0, 1.0, 0.0, 0.0);
  v12 = evtSetRegistUnit(major, minor);
  (*form)->stat |= 2u;
  v14 = v12;
  pBasic = dds3GetActiveScene();
  v16 = dds3SearchSceneBasic(&pBasic, v14, 5u);
  unitbasic = v16;
  workdata = v16->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, &v72);
    if ((v72 & 1) != 0)
      v64 = v74;
    else
      v64 = &v72 + 1;
    v65 = sub_8C4940(v64);
  }
  LODWORD(workdata[4].klass) = 1;
  (*form)->basic = v16;
  v21 = v16->workdata;
  v22 = *v21;
  v23 = v18->_2.typeHierarchyDepth;
  if (LOBYTE((*v21)->ExBefore) < v23 || *(*&v22->Sin + 8 * v23 - 8) != v18)
  {
    sub_8FC2C0(*&v22->TargetLightDir.x, v18, &v72);
    if ((v72 & 1) != 0)
      v66 = v74;
    else
      v66 = &v72 + 1;
    v67 = sub_8C4940(v66);
  }
  (*form)->hunit = v21[4];
  (*form)->hunit->Model->modelRoot->modelobj = (*form)->modelobj;
  (*form)->hunit->Model->Owner = v16;
  (*form)->hunit->Model->Owner->gameObject = (*form)->modelobj;
  (*form)->hunit->modelobj = (*form)->modelobj;
  hunit = (*form)->hunit;
  z = (*form)->modelrot.z;
  *&hunit->modelrot.x = *&(*form)->modelrot.x;
  hunit->modelrot.z = z;
  (*form)->hunit->modelanm = (*form)->modelanm;
  v26 = (*form)->hunit;
  v73 = 0.0;
  v72 = 0;
  sub_8524C0(&v72, 0.0, 0.0, 0.0);
  v28 = v73;
  *&v26->modelofs.x = v72;
  v26->modelofs.z = v28;
  (*form)->hunit->formindex = (*form)->formindex;
  modelobj = (*form)->hunit->modelobj;
  if (op_Inequality(modelobj, 0, 0))
  {
    if (major == 1 && minor == 342)
    {
      v31 = (*form)->hunit;
      v73 = 0.0;
      v72 = 0;
      v32 = 2.0;
      v33 = 0.0;
LABEL_26:
      sub_8524C0(&v72, 0.0, v32, v33);
      v34 = v73;
      *&v31->modelofs.x = v72;
      v31->modelofs.z = v34;
      goto LABEL_27;
    }
    if (major == 1 && minor == 343)
    {
      v33 = 2.5;
      v32 = 0.0;
      v31 = (*form)->hunit;
      v73 = 0.0;
      v72 = 0;
      goto LABEL_26;
    }
  }
LABEL_27:
  (*form)->serial = v14;
  (*form)->hunit->Flag |= 0x200000u;
  if ((*data)->baselight)
    dds3LinkLightObjectToUnitObject(&(*data)->baselight, &unitbasic, 1u, 0);
  nbSetWaitMotion(form, 0, 1.0);
  nbSetUnitMotion(form, 0, 1, 1.0);
  v37 = *form;
  v37->modelcol = nbGetModelColor(v37);
  if (minor == 297)
    (*form)->anime |= 0x400u;
  x = (*form)->pos.x;
  y = (*form)->pos.y;
  v42 = (*form)->pos.z;
  v41 = (*form)->pos.w;
  v75.x = x;
  v75.y = y;
  v75.z = v42;
  v75.w = v41;
  dds3SetPosPoseSet(&unitbasic, v75);
  v44 = *form;
  if ((*form)->partyindex <= 3)
  {
    v45 = v70;
    v46 = v71;
    *&v76.x = v45;
    *&v76.z = v46;
    dds3SetRotPoseSet(&unitbasic, v76);
    v44 = *form;
  }
  if ((v44->anime & 0x200) != 0)
  {
    formindex = v44->formindex;
    nbFormDispOff(formindex);
    v50 = *w;
      goto LABEL_47;
  }
  else
  {
    p_hunit = &v44->hunit;
    evtSetUnitColorRGB(p_hunit, 0, 0);
    evtSetUnitColorA(&(*form)->hunit, 0, 0, 0);
    v50 = *w;
    {
LABEL_47:
    }
  }
  UnitVisual = nbGetUnitVisual(v50);
  if (UnitVisual->shadowsize)
  {
    v53 = UnitVisual;
    dds3ObjectBaseOnFlag(&unitbasic, 0x400u, 0);
    v55 = v53->shadowsize - 2;
    if (v55 > 2)
      v56 = 50.0;
    else
      v56 = flt_33CD388[v55];
    unitbasic->poseset->r = v56;
      goto LABEL_61;
  }
  else
  {
    dds3ObjectBaseOffFlag(&unitbasic, 0x400u);
      goto LABEL_61;
  }
LABEL_61:
  v58 = ChkUseMarukage(minor);
  if ((v58 - 1) <= 1)
  {
    v60 = v58;
    dds3ObjectBaseOnFlag(&(*form)->basic, 0x2000u, 0, 0);
    if (v60 == 2)
      dds3ObjectBaseOnFlag(&(*form)->basic, 0x4000u, 0, 0);
  }
  v61 = *form;
  scl = (*form)->scl;
  if (scl != 1.0)
  {
    p_Model = &v61->hunit->Model;
    mdlSetEffectScale(p_Model, scl);
    v61 = *form;
  }
  v61->flag &= ~2u;
  (*form)->flag |= 4u;
}

// 0x15bf030
void RunBadAction(nbMainProcessData_t **data, nbFormation_t **form) {
  dds3Basic_t_o **p_basic;
  s64 v6;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v9;
  UnityEngine_Vector4_o v10;

  *&v9.x = 0;
  *&v9.z = 0;
  if ((*form)->basic)
  {
    dds3GetRandFloatA("RunBadAction");
    SDF_VU0__COPYVECTOR(&v9, (*form)->pos, 0);
    sub_854710(&v9, 0);
    sub_854930(&v9, 0);
    p_basic = &(*form)->basic;
    v6 = *&v9.x;
    z = v9.z;
    w = v9.w;
    *&v10.x = v6;
    v10.z = z;
    v10.w = w;
    dds3SetPosPoseSet(p_basic, v10);
  }
}

// 0x15bf180
void RunDamage(nbMainProcessData_t **data, nbFormation_t **form) {
  u64 v3;
  nbFormation_t_o *v5;
  s32 type;
  f32 mf;
  f32 v8;
  UnityEngine_Animator_o *modelanm;
  dds3Basic_t_o **p_basic;
  s64 v12;
  f32 w;
  f32 z;
  UnityEngine_Animator_o *v16;
  dds3Basic_t_o **v19;
  s64 v20;
  f32 v21;
  f32 v22;
  f32 range;
  UnityEngine_Animator_o *v24;
  dds3Basic_t_o **v26;
  s64 v27;
  f32 v28;
  f32 v29;
  UnityEngine_Vector4_o v30;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o v33;

  *&v30.x = 0;
  *&v30.z = 0;
  v5 = *form;
  if (!(*form)->basic)
  {
    v5->type = 0;
    (*form)->time = 0;
    return;
  }
  type = v5->type;
  if (type != 3)
  {
    if (type == 1)
    {
      mf = v5->data1->mf;
      if (mf > 0.0)
      {
        LODWORD(v3) = v5->time;
        v8 = v3;
        if (mf == v8)
        {
          modelanm = v5->modelanm;
          mdlSetMotionSpeedAnimator(modelanm, 0.0);
          v5 = *form;
        }
      }
      if (v5->tartime <= v5->time)
      {
        v5->type = 0;
        (*form)->time = 0;
        SDF_VU0__COPYVECTOR(&v30, (*form)->pos, 0);
        p_basic = &(*form)->basic;
        v12 = *&v30.x;
        z = v30.z;
        w = v30.w;
        *&v31.x = v12;
        v31.z = z;
        v31.w = w;
        dds3SetPosPoseSet(p_basic, v31);
        if (((*form)->anime & 0x80) == 0)
        {
          v16 = (*form)->modelanm;
          if (mdlGetMotionSpeedAnimator(v16) == 0.0)
            nbSetUnitMotion(form, 0, 1, 1.0);
        }
        return;
      }
    }
    goto LABEL_24;
  }
  if (v5->tartime > v5->time)
  {
LABEL_24:
    dds3GetRandFloatA("");
    SDF_VU0__COPYVECTOR(&v30, (*form)->pos, 0);
    sub_854710(&v30, 0);
    sub_854930(&v30, 0);
    v19 = &(*form)->basic;
    v20 = *&v30.x;
    v22 = v30.z;
    v21 = v30.w;
    *&v32.x = v20;
    v32.z = v22;
    v32.w = v21;
    dds3SetPosPoseSet(v19, v32);
    range = (*form)->range;
    if (range > 0.0)
    {
      (*form)->range = range + -0.7;
      if ((*form)->range < 0.0)
        (*form)->range = 0.0;
    }
    return;
  }
  v5->anime |= 0x80u;
  v24 = (*form)->modelanm;
  mdlSetMotionSpeedAnimator(v24, 0.0);
  (*form)->type = 0;
  (*form)->time = 0;
  SDF_VU0__COPYVECTOR(&v30, (*form)->pos, 0);
  v26 = &(*form)->basic;
  v27 = *&v30.x;
  v29 = v30.z;
  v28 = v30.w;
  *&v33.x = v27;
  v33.z = v29;
  v33.w = v28;
  dds3SetPosPoseSet(v26, v33);
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
LABEL_18:
    if ((flag & 2) == 0)
      goto LABEL_19;
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
        goto LABEL_19;
      }
      if ((flag & 0x40) == 0)
        goto LABEL_19;
      if (!nbCheckLoadUnitPackFile_Model(form, 1, v11, 1))
      {
LABEL_19:
        v17 = 0;
        goto LABEL_33;
      }
      v17 = 1;
      RegistUnit(data, 1, v11, form, &w);
      v19 = *form;
      v20 = (*form)->flag & 0xFFFFFFDF;
    }
    v19->flag = v20;
    (*form)->flag &= ~0x40u;
LABEL_33:
    if (((*form)->flag & 0xC) != 4)
      return v17;
    akey = (*form)->akey;
    LoadBossAIMSG(akey);
    dds3GetRandIntA(0, "");
    if (((*form)->anime & 0x200) != 0)
    {
      v25 = (*form)->formindex;
      nbFormDispOff(v25);
      (*form)->anime &= ~0x200u;
      v24 = UnitWorkFromFormindex->badstatus & 0xFFF;
      if ((UnitWorkFromFormindex->badstatus & 0xFFF) == 0)
        goto LABEL_48;
    }
    else
    {
      nbMakeUnitFadeInPacket(0, 0, form, 0, 15, 15, 20);
      v24 = UnitWorkFromFormindex->badstatus & 0xFFF;
      if ((UnitWorkFromFormindex->badstatus & 0xFFF) == 0)
        goto LABEL_48;
    }
    nbAddBadEffKoukaPacket(1, 0, form, v24);
    nbAddBadMotKoukaPacket(1, 0, form, UnitWorkFromFormindex->badstatus & 0xFFF);
LABEL_48:
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
      goto LABEL_18;
    }
  }
}

// 0x15bee50
void RunSake(nbMainProcessData_t **data, nbFormation_t **form) {
  nbFormation_t_o *v4;
  f32 addmovet;
  f32 movet;
  nbFormation_t_o *v7;
  dds3Basic_t_o **p_basic;
  s64 v10;
  f32 w;
  f32 z;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;

  *&v13.x = 0;
  *&v13.z = 0;
  v4 = *form;
  if (!(*form)->basic)
  {
    v4->type = 0;
    (*form)->time = 0;
    return;
  }
  addmovet = v4->addmovet;
  movet = v4->movet;
  if (addmovet >= 0.0)
  {
    v4->addmovet = addmovet + 0.02;
    (*form)->movet = (addmovet * (1.0 - movet)) + (*form)->movet;
    v7 = *form;
    if ((*form)->movet >= 0.99)
    {
      v7->addmovet = v7->data1->mf * -0.6;
      v7 = *form;
    }
  }
  else
  {
    v4->addmovet = addmovet + -0.01;
    (*form)->movet = (addmovet * movet) + (*form)->movet;
    v7 = *form;
    if ((*form)->movet <= 0.01)
    {
      v7->type = 0;
      SDF_VU0__COPYVECTOR(&v13, (*form)->pos, 0);
      goto LABEL_12;
    }
  }
  SDF_VU0__COPYVECTOR(&v13, v7->pos);
  sub_854710(&v13, 0);
  sub_854930(&v13, 0);
LABEL_12:
  p_basic = &(*form)->basic;
  v10 = *&v13.x;
  z = v13.z;
  w = v13.w;
  *&v14.x = v10;
  v14.z = z;
  v14.w = w;
  dds3SetPosPoseSet(p_basic, v14);
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
        goto LABEL_35;
      v7 = *work;
    }
    v12 = datCheckDying(v7);
    p_hunit = &(*form)->hunit;
    if (v12)
    {
      if (mdlGetMotionMinorNumForUnity(p_hunit, 0) == 22)
        goto LABEL_35;
      v15 = &(*form)->hunit;
      if ((mdlGetMotionMinorNumForUnity(v15, 0) | 2) != 2)
        goto LABEL_35;
LABEL_34:
      nbSetWaitMotion(form, 0, 1.0);
      nbSetUnitMotion(form, 0, 1, 1.0);
      goto LABEL_35;
    }
    if (mdlGetMotionMinorNumForUnity(p_hunit, 0) == 22)
    {
      v18 = &(*form)->hunit;
      if (mdlGetMotionMinorNumForUnity(v18, 0) == 22)
        goto LABEL_34;
    }
  }
LABEL_35:
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
  struct dds3Basic_t_o *basic;
  UnityEngine_Vector4_o v4;

  *&v4.x = 0;
  sub_854690(&v4.x, 0.0, 1.0, 0.0, 0.0);
  basic = (*form)->basic;
  if (basic)
  {
    SDF_VU0__COPYVECTOR(&(*form)->pos, basic->poseset->pos, 0);
    SDF_VU0__LOADVECTOR((*form)->basic->poseset->rot, 0);
    SDF_VU0__LOADVECTOR_B(v4);
    Mult();
    SDF_VU0__STOREVECTOR(&(*form)->rot, 0);
  }
}

// 0x15bab00
void mdlAnimSetBattle(evtUnitHandle_t **h, s32 motion) {
  UnityEngine_Animator_o *modelanm;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  dds3ModelHandle_t_o **p_Model;
  s32 MinorNum;
  s32 v15;
  s64 Integer_8773456;
  UnityEngine_Component_o *v18;
  UnityEngine_AnimatorClipInfo_array *CurrentAnimatorClipInfo;
  UnityEngine_Object_o *v20;
  System_String_o *name;
  s32 *v23;
  UnityEngine_Animator_o *v24;
  s32 v25;
  s32 v26;
  evtUnitHandle_t_o *v28;
  dds3ModelHandle_t_o **v29;
  struct dds3ModelHandle_t_o *Model;
  UnityEngine_GameObject_o *v31;
  Il2CppObject *v33;
  s32 *p_id_anim;
  dds3ModelHandle_t_o **v36;
  s32 v39;
  s32 *v41;
  System_String_o *v42;
  s32 v43;
  System_String_o *v44;
  s32 v45;
  s32 v46;
  u64 *v47;
  dds3ModelHandle_t_o **v49;
  s32 v50;
  u64 *v51;
  u64 *v52;
  UnityEngine_AnimatorStateInfo_o v53;
  s32 v54;
  s64 v55;
  s64 v56;
  s64 v57;
  s64 v58;
  s64 v59;

  v58 = 0;
  v59 = 0;
  v55 = 0;
  v54 = 0;
  v56 = 0;
  v57 = 0;
  if (*h)
  {
    modelanm = (*h)->modelanm;
    if (!op_Equality(modelanm, 0, 0))
    {
      transform = get_transform((*h)->modelobj, 0);
      Child = GetChild(transform, 0);
      gameObject = get_gameObject(Child);
      Component_object = GetComponent_object_(gameObject);
      if (!op_Inequality(Component_object, 0, 0))
        goto LABEL_28;
      p_Model = &(*h)->Model;
      MinorNum = mdlGetMinorNum(p_Model);
      if (AnimClipSearch(Component_object, MinorNum, motion))
      {
        v15 = motion + 100;
        HIDWORD(v59) = motion + 100;
        Integer_8773456 = GetInteger_8773456(modelanm, id_anim);
        if (motion)
          v18 = Child;
        else
          v18 = 0;
        if (motion)
        {
          if (Integer_8773456 == v15)
          {
            CurrentAnimatorClipInfo = GetCurrentAnimatorClipInfo(modelanm, 0);
            if (CurrentAnimatorClipInfo && SLODWORD(CurrentAnimatorClipInfo->max_length) >= 1)
            {
              v20 = sub_85F130(CurrentAnimatorClipInfo->m_Items);
              name = get_name(v20);
              if (Contains(name, "_RE", 0))
                name = Replace_5267216(name, "_RE", "");
              else
                Child = v18;
              GetCurrentAnimatorStateInfo(&v53, modelanm, 0);
              v55 = *&v53.m_Name;
              v56 = *&v53.m_FullPath;
              v57 = *&v53.m_Length;
              v58 = *&v53.m_SpeedMultiplier;
              LODWORD(v59) = v53.m_Loop;
              v42 = Replace_5267216(name, "b", "b1");
              v54 = sub_85FB20(&v55);
              v43 = StringToHash(v42);
              if (!sub_232930(&v54, v43))
              {
                v44 = sub_232970(&v59 + 1);
                v42 = Concat_5224608("b", v44);
                v54 = sub_85FB20(&v55);
                v45 = StringToHash(v42);
                if (!sub_232930(&v54, v45))
                {
                  v46 = HIDWORD(v59) - 100;
                  v53.m_Name = HIDWORD(v59) - 100;
                  v47 = sub_8D3950(s32, &v53);
                  v42 = Format("b10{0:x}", v47, 0);
                  if (v46 >= 16)
                  {
                    v49 = &(*h)->Model;
                    v50 = mdlGetMinorNum(v49);
                    if (!evtBitCheck(3712) && ((v50 - 339) < 3 || v50 == 192))
                    {
                      v53.m_Name = v46;
                      v51 = sub_8D3950(s32, &v53);
                      v42 = Format("b1{0:x}", v51, 0);
                    }
                    if (v50 == 202 || v50 == 352 || v50 == 293)
                    {
                      v53.m_Name = v46;
                      v52 = sub_8D3950(s32, &v53);
                      v42 = Format("b1{0:x}", v52, 0);
                    }
                  }
                }
              }
              ResetStateNormalizedTimeOffset(Component_object);
              Play_8777152(modelanm, v42, 0, 0.0);
              goto LABEL_65;
            }
          }
          else if (motion == 13)
          {
            v36 = &(*h)->Model;
            if (mdlGetMinorNum(v36) == 75)
            {
              v15 = 213;
              HIDWORD(v59) = 213;
                goto LABEL_62;
              goto LABEL_64;
            }
            v15 = 113;
          }
          {
LABEL_62:
          }
LABEL_64:
          SetInteger_8774000(modelanm, id_anim, v15);
LABEL_65:
          UpdateNormalizeTime(Component_object);
          goto LABEL_33;
        }
        if (Integer_8773456 == v15)
        {
          p_id_anim = &id_anim;
          v24 = modelanm;
          v25 = *p_id_anim;
          v26 = motion + 100;
        }
        else
        {
          v39 = mdlAnimSetBattleQuickWait(*h, Integer_8773456, 0);
          HIDWORD(v59) = v39;
          v41 = &id_anim;
          v24 = modelanm;
          v25 = *v41;
          v26 = v39;
        }
      }
      else
      {
LABEL_28:
        v23 = &id_anim;
        v24 = modelanm;
        v25 = *v23;
        v26 = 100;
      }
      SetInteger_8774000(v24, v25, v26);
LABEL_33:
      v28 = *h;
      Model = v28->Model;
      v29 = &v28->Model;
      if (Model->motionMinorNum != motion)
      {
        mdlMotionSub(v29, 0, motion);
      }
      v31 = get_gameObject(Child);
      v33 = GetComponent_object_(v31);
      if (op_Inequality(v33, 0, 0))
        ResetFlag(v33, 0, 0);
    }
  }
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
    else if (!IsModelRaido(MinorNum))
    {
      goto LABEL_13;
    }
  }
  if ((old_motion - 109) < 0xA)
  {
    v10 = (0x383u >> (old_motion - 109)) & 1;
    goto LABEL_14;
  }
LABEL_13:
  v10 = 0;
LABEL_14:
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
        goto LABEL_25;
      v13 = old_motion == 108;
      v14 = old_motion == 112;
      v15 = (old_motion == 103) | v12;
    }
    v16 = v13 | v15;
  }
  v17 = v14;
  v12 = v17 | v16;
LABEL_25:
  v18 = (old_motion == 112 && MinorNum == 69)
      | (old_motion == 112 && MinorNum == 56)
      | (old_motion == 108 && MinorNum == 45)
      | v12;
  if (MinorNum == 75)
  {
    v19 = (old_motion == 104) | v18;
    v20 = (old_motion | 4) == 111;
LABEL_27:
    v21 = v20;
    goto LABEL_36;
  }
  v22 = (old_motion == 112 && MinorNum == 95) | (old_motion == 116 && MinorNum == 79) | v18;
  if (MinorNum != 301 && MinorNum != 100)
  {
    if (MinorNum == 99)
    {
LABEL_35:
      v21 = old_motion == 112;
      v19 = (old_motion == 108) | (old_motion == 103) | v22;
LABEL_36:
      v22 = v21 | v19;
      goto LABEL_37;
    }
    v23 = MinorNum - 102;
    goto LABEL_34;
  }
  v22 |= old_motion == 112 || old_motion == 108 || old_motion == 103;
  v23 = MinorNum - 102;
  if ((MinorNum - 102) <= 0x1D)
  {
LABEL_34:
    switch (v23)
    {
      case 0:
        goto LABEL_35;
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
        goto LABEL_47;
      case 23:
        goto LABEL_56;
      case 27:
        if ((v22 & 1) != 0 || (old_motion - 103) <= 7 && ((1 << (old_motion - 103)) & 0xA1) != 0)
          return motion + 200;
        break;
      case 29:
        goto LABEL_46;
      default:
        goto LABEL_45;
    }
    return result;
  }
LABEL_45:
  if (MinorNum == 319)
LABEL_46:
    v22 |= old_motion == 109 || (old_motion | 2) == 110 || old_motion == 103;
LABEL_47:
  v24 = (old_motion == 108 && MinorNum == 142) | v22;
  if (MinorNum != 143)
  {
    v22 = (old_motion == 112 && MinorNum == 147) | v24;
    if (MinorNum != 315 && MinorNum != 168)
    {
LABEL_37:
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
LABEL_56:
    v19 = (old_motion == 103) | v22;
    v20 = (old_motion | 1) == 109;
    goto LABEL_27;
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
  s32 result;
  bool v6;
  UnityEngine_GUILayer_o *Component_GUILayer;
  f32 StateNormalizedTimeOffset;
  f32 v10;
  UnityEngine_AnimatorStateInfo_o v11;
  UnityEngine_AnimatorStateInfo_o v12;

  memset(&v12, 0, sizeof(v12));
  if (op_Equality(mAnimator, 0, 0))
    return 1;
  GetCurrentAnimatorStateInfo(&v11, mAnimator, 0);
  v12 = v11;
  v6 = sub_85FBA0(&v12);
  result = 0;
  if (!v6)
  {
    if (sub_85FB80(&v12) <= 0.0)
    {
      return 0;
    }
    else
    {
      Component_GUILayer = GetComponent_GUILayer_(mAnimator);
      if (op_Inequality(Component_GUILayer, 0, 0))
        StateNormalizedTimeOffset = GetStateNormalizedTimeOffset(Component_GUILayer);
      else
        StateNormalizedTimeOffset = 0.0;
      v10 = sub_85FB40(&v12);
      return (v10 - StateNormalizedTimeOffset) >= (1.0 / sub_85FB80(&v12));
    }
  }
  return result;
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
  struct nbParty_t_array *party;
  s32 v11;
  struct nbParty_t_array *v12;
  datUnitWork_t_o *v13;
  s16 v14;
  datUnitVisual_t_o *v15;
  struct nbParty_t_array *v16;
  struct nbParty_t_array *v19;
  struct nbParty_t_array *v20;
  struct nbParty_t_array *v23;
  struct nbParty_t_array *v25;
  struct nbParty_t_array *v27;
  struct datUnitWork_t_array *unitwork;
  datUnitVisual_t_o *v32;
  struct datUnitWork_t_array *v33;
  Il2CppClass **v35;
  struct nbParty_t_array *v36;
  struct nbParty_t_array *v38;
  struct nbParty_t_array *v40;
  struct nbParty_t_array *v42;
  struct nbParty_t_array *v44;
  struct nbParty_t_array *v46;
  struct datUnitWork_t_array *enemyunit;
  datUnitVisual_t_o *UnitVisual;
  struct datUnitWork_t_array *v51;
  struct datUnitWork_t_array *v53;
  struct nbParty_t_array *v55;
  s64 v56;
  struct nbParty_t_array *v58;
  struct nbParty_t_array *v60;
  u64 v62;
  struct nbParty_t_array *v63;
  struct System_Int16_array *count;
  char *v67;
  s16 EquipHeartsAisyo;
  u32 flag;
  u64 i;
  struct nbParty_t_array *v80;
  struct System_UInt32_array *aisyo;
  u32 v83;
  char *v85;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v88;
  nbFormation_t_o *v90;
  s32 *p_stat;
  u32 v92;
  u32 stat;
  struct nbFormation_t_array *v94;
  struct nbFormation_t_array *v96;
  nbFormation_t_o *v98;
  struct nbFormation_t_array *v99;
  struct nbFormation_t_array *v101;
  struct nbFormation_t_array *v103;
  struct nbFormation_t_array *v105;
  struct nbFormation_t_array *v107;
  struct nbFormation_t_array *v110;
  struct nbFormation_t_array *v112;
  struct nbFormation_t_array *v114;
  struct nbFormation_t_array *v116;
  struct nbFormation_t_array *v118;
  struct nbFormation_t_array *v120;

  if (side)
  {
    if (side == 1)
    {
      party = (*data)->party;
      if ((party->m_Items[4]->flag & 1) != 0)
      {
        v16 = (*data)->party;
        if ((v16->m_Items[5]->flag & 1) != 0)
        {
          v20 = (*data)->party;
          if ((v20->m_Items[6]->flag & 1) != 0)
          {
            v25 = (*data)->party;
            if ((v25->m_Items[7]->flag & 1) != 0)
            {
              v36 = (*data)->party;
              if ((v36->m_Items[8]->flag & 1) != 0)
              {
                v38 = (*data)->party;
                if ((v38->m_Items[9]->flag & 1) != 0)
                {
                  v40 = (*data)->party;
                  if ((v40->m_Items[10]->flag & 1) != 0)
                  {
                    v42 = (*data)->party;
                    if ((v42->m_Items[11]->flag & 1) != 0)
                    {
                      v44 = (*data)->party;
                      if ((v44->m_Items[12]->flag & 1) != 0)
                      {
                        v46 = (*data)->party;
                        if ((v46->m_Items[13]->flag & 1) != 0)
                          v11 = -1;
                        else
                          v11 = 13;
                      }
                      else
                      {
                        v11 = 12;
                      }
                    }
                    else
                    {
                      v11 = 11;
                    }
                  }
                  else
                  {
                    v11 = 10;
                  }
                }
                else
                {
                  v11 = 9;
                }
              }
              else
              {
                v11 = 8;
              }
            }
            else
            {
              v11 = 7;
            }
          }
          else
          {
            v11 = 6;
          }
        }
        else
        {
          v11 = 5;
        }
      }
      else
      {
        v11 = 4;
      }
      enemyunit = (*data)->enemyunit;
      v13 = enemyunit->m_Items[stockno];
      nbGetUnitID(v13);
      UnitVisual = nbGetUnitVisual(v13);
      v51 = (*data)->enemyunit;
      v15 = UnitVisual;
      v51->m_Items[stockno]->flag |= 2u;
      v53 = (*data)->enemyunit;
      v14 = 3;
      v53->m_Items[stockno]->flag |= 0x20u;
      ++(*data)->enemypcnt;
    }
    else
    {
      v13 = 0;
      v14 = 0;
      v15 = 0;
      v11 = -1;
    }
  }
  else
  {
    v12 = (*data)->party;
    if ((v12->m_Items[0]->flag & 1) != 0)
    {
      v19 = (*data)->party;
      if ((v19->m_Items[1]->flag & 1) != 0)
      {
        v23 = (*data)->party;
        if ((v23->m_Items[2]->flag & 1) != 0)
        {
          v27 = (*data)->party;
          if ((v27->m_Items[3]->flag & 1) != 0)
            v11 = -1;
          else
            v11 = 3;
        }
        else
        {
          v11 = 2;
        }
      }
      else
      {
        v11 = 1;
      }
    }
    else
    {
      v11 = 0;
    }
    unitwork = DDS3_GBWK->unitwork;
    v13 = unitwork->m_Items[stockno];
    nbGetUnitID(v13);
    v32 = nbGetUnitVisual(v13);
    v33 = DDS3_GBWK->unitwork;
    v15 = v32;
    v35 = &v33->obj.klass + stockno;
    v14 = 1;
    LODWORD(v35[4]->_1.name) |= 2u;
    ++(*data)->playerpcnt;
  }
  v55 = (*data)->party;
  v56 = v11;
  v55->m_Items[v11]->flag = v14;
  v58 = (*data)->party;
  v58->m_Items[v56]->formindex = formindex;
  v60 = (*data)->party;
  v62 = 0;
  v60->m_Items[v56]->statindex = stockno;
  do
  {
    v63 = (*data)->party;
    count = v63->m_Items[v56]->count;
    v67 = count + 2 * v62++;
    *(v67 + 16) = 0;
  }
  while (v62 != 20);
  if ((v13->flag & 4) != 0)
  {
    else
    {
      EquipHeartsAisyo = rstGetEquipHeartsAisyo();
      if (EquipHeartsAisyo)
        goto LABEL_101;
    }
  }
  for (i = 0; i != 16; ++i)
  {
    v80 = (*data)->party;
    aisyo = v80->m_Items[v56]->aisyo;
    v83 = datGetAisyo(v13, i);
    v85 = aisyo + 4 * i;
    *(v85 + 8) = v83;
  }
LABEL_121:
  form = (*data)->form;
  form->m_Items[formindex]->stat = 65;
  if (formindex > 3)
  {
    v88 = (*data)->form;
    v90 = v88->m_Items[formindex];
    stat = v90->stat;
    p_stat = &v90->stat;
    v92 = stat;
    if (formindex <= 13)
    {
      *p_stat = v92 | 0x200;
      if (v15->autowait != 1)
        goto LABEL_137;
    }
    else
    {
      *p_stat = v92 | 0x400;
      if (v15->autowait != 1)
        goto LABEL_137;
    }
    goto LABEL_134;
  }
  v94 = (*data)->form;
  v94->m_Items[formindex]->stat |= 0x100u;
  if (v15->autowait == 1)
  {
LABEL_134:
    v96 = (*data)->form;
    v98 = v96->m_Items[formindex];
    v98->stat |= 0x80u;
  }
LABEL_137:
  v99 = (*data)->form;
  v99->m_Items[formindex]->partyindex = v56;
  v101 = (*data)->form;
  v101->m_Items[formindex]->formindex = formindex;
  v103 = (*data)->form;
  v103->m_Items[formindex]->r = v15->formsize;
  v105 = (*data)->form;
  v105->m_Items[formindex]->cr = 0.0;
  v107 = (*data)->form;
  SDF_VU0__COPYVECTOR(&v107->m_Items[formindex]->center, v15->center);
  v110 = (*data)->form;
  v110->m_Items[formindex]->scl = v15->formscale;
  v112 = (*data)->form;
  v112->m_Items[formindex]->h = v15->formheight;
  v114 = (*data)->form;
  v114->m_Items[formindex]->oneshotr = v15->oneshotr;
  v116 = (*data)->form;
  v116->m_Items[formindex]->allshotr = v15->allshotr;
  v118 = (*data)->form;
  v118->m_Items[formindex]->badeff = 0;
  v120 = (*data)->form;
  nbGetMotionNo(&v120->m_Items[formindex], 0);
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
    goto LABEL_9;
LABEL_6:
  if (v2 != 1)
    return 0;
  LODWORD(v2) = 4;
  v4 = 10;
LABEL_10:
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
      goto LABEL_20;
  }
  else
  {
    v18 = &datHuman;
      goto LABEL_20;
  }
  if (!v19[54])
  {
    v19 = *v18;
  }
LABEL_20:
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
  target = dds3StartProcess("nb_unit", 0x3F9u, 1, 1, v3, 0, v4, 0, 0, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->UnitProcessID = target;
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_nbUnitProcess_nbUnitDrawProcess1__);
  started = dds3StartProcess("nb_unitdraw", 0x2B0Eu, 1, 1, v6, 0, 0, 0, 0, 0);
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
  u64 v6;
  nbMainProcessData_t_o *MainProcessData;
  u64 v8;
  struct nbFormation_t_array *v9;
  Il2CppClass **v11;
  Il2CppClass *v12;
  struct nbFormation_t_array *form;

  LODWORD(v6) = side;
  else
  {
    MainProcessData = nbGetMainProcessData();
    if (v6)
      goto LABEL_6;
  }
  v8 = (v6 + 4);
  if (!stop)
    goto LABEL_18;
  do
  {
    while (1)
    {
LABEL_8:
      v9 = MainProcessData->form;
      v11 = &v9->obj.klass + v6;
      v12 = v11[4];
      if ((v12->_1.events & 0x43) == 0x41)
      {
        LODWORD(v12->_1.fields) = 4;
        HIDWORD(v11[4]->_1.fields) = 0;
        HIDWORD(v11[4]->_1.events) &= 0xFFFFFFF9;
        HIDWORD(v11[4]->_1.events) |= 1u;
        HIDWORD(v11[4]->_1.events) |= 8u;
        if (!anime)
          break;
      }
      if (++v6 >= v8)
        return;
    }
    LODWORD(v11[4]->_1.properties) |= 0x200u;
    ++v6;
  }
  while (v6 < v8);
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
LABEL_41:
          if (v26 == 512)
          {
            UnitWorkPointer->badstatus = badstatus & 0xFDFF;
            v24->maxhp = datGetMaxHp(v24);
            v24->maxmp = datGetMaxMp(v24);
          }
          v24->badstatus = 2048;
          v24->hp = 0;
LABEL_60:
          datClearCommMemory(v24);
          v27 = v12->flag;
          if ((v27 & 2) != 0)
            goto LABEL_64;
          goto LABEL_49;
        }
      }
      else
      {
        UnitWorkPointer->flag &= ~2u;
        badstatus = UnitWorkPointer->badstatus;
        v26 = badstatus & 0xFFF;
        if (dead)
          goto LABEL_41;
      }
      if (v26 <= 4)
      {
        if (v26 != 4 && v26 - 1 >= 2)
          goto LABEL_60;
      }
      else
      {
        v28 = badstatus & 0xFFF;
        if (v28 != 8 && v28 != 128 && v28 != 16)
          goto LABEL_60;
      }
      UnitWorkPointer->badstatus = badstatus & 0xF000;
      goto LABEL_60;
    }
    v27 = v12->flag;
    if ((v27 & 2) != 0)
    {
LABEL_64:
      --v10->enemypcnt;
LABEL_65:
      *&v12->flag = -65536;
      v12->statindex = -1;
      return;
    }
LABEL_49:
    if ((v27 & 4) == 0)
      --v10->playerpcnt;
    goto LABEL_65;
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
          goto LABEL_49;
        goto LABEL_18;
      case 1:
        goto LABEL_24;
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
        goto LABEL_14;
      case 14:
      case 15:
LABEL_14:
        if (DyingBadWaitMotion != 22)
          goto LABEL_15;
        goto LABEL_19;
      case 23:
        nexthokanb = (*form)->nexthokanb;
        nexthokan = (*form)->nexthokan;
        goto LABEL_24;
      default:
        nexthokan = 0;
        if (DyingBadWaitMotion > 2)
        {
LABEL_18:
          v28 = nexthokan;
          if (DyingBadWaitMotion == 22)
          {
LABEL_19:
            nexthokan = v28;
          }
          else
          {
LABEL_15:
            nexthokan = v28;
            if (DyingBadWaitMotion != 13)
              goto LABEL_24;
          }
        }
        else
        {
LABEL_49:
          if ((DyingBadWaitMotion | 2) != 2)
          {
LABEL_24:
            evtSetUnitMotion(&h, MotionNo, nexthokanb, nexthokan, mode);
            goto LABEL_28;
          }
        }
        if (mdlGetMotionMinorNumForUnity(&h, 0) != MotionNo)
          goto LABEL_24;
LABEL_28:
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
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v7;
  UnityEngine_GameObject_o *TargetMark2D;
  s32 v10;
  bool activeSelf;
  UnityEngine_Object_o *modelobj;

  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 16; ++i)
  {
    form = MainProcessData->form;
    v7 = form->m_Items[i];
    TargetMark2D = GetTargetMark2D(i);
    if (op_Inequality(TargetMark2D, 0, 0))
    {
      v10 = v7->anime & 0x1C;
      activeSelf = get_activeSelf(TargetMark2D);
      if (v10)
      {
        if (activeSelf)
          goto LABEL_21;
        else if (nbWaitUntilCreateMainCamera_1Frame)
        {
          goto LABEL_21;
        }
        SetActive(TargetMark2D, 1, 0);
        TargetMark2DAnim(i);
          goto LABEL_32;
        goto LABEL_22;
      }
      if (activeSelf)
      {
        SetActive(TargetMark2D, 0, 0);
        if ((v7->anime & 0x100) == 0)
          continue;
        goto LABEL_34;
      }
    }
LABEL_33:
    if ((v7->anime & 0x100) == 0)
      continue;
LABEL_34:
    if (v7->badeff)
    {
      modelobj = v7->modelobj;
      if (op_Inequality(modelobj, 0, 0)
        && get_activeSelf(v7->modelobj))
      {
        effBTLSystemDraw(&v7->badeff);
      }
    }
  }
  nbWaitUntilCreateMainCamera_1Frame = 0;
  return 0;
}

// 0x15c0150
void *nbUnitProcess2(dds3ProcessID_t *id) {
  dds3UnitObjectBasicWorkData_t_c *v3;
  nbMainProcessData_t_o *v4;
  u64 v5;
  struct nbFormation_t_array *v6;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v11;
  nbFormation_t_o *v12;
  s32 v13;
  u32 autotime;
  nbFormation_t_o *v15;
  s32 v16;
  nbFormation_t_o *v17;
  struct dds3Basic_t_o *basic;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 monitor;
  s32 v23;
  u32 v24;
  u32 v25;
  char *v28;
  s64 *v29;
  datUnitWork_t_o *v30;
  nbFormation_t_o *form;
  nbMainProcessData_t_o *data;
  UnityEngine_Vector4_o v33;
  u64 v34[3];

  *&v33.x = 0;
  *&v33.z = 0;
  form = 0;
  data = 0;
  v30 = 0;
  sub_854690(&v33.x, 1.0, 1.0, 1.0, 0.0);
  data = nbGetMainProcessData();
  v4 = data;
  v5 = 0;
  do
  {
    v6 = v4->form;
    form = v6->m_Items[v5];
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v5);
    v30 = UnitWorkFromFormindex;
    if ((form->stat & 1) != 0)
    {
      v11 = UnitWorkFromFormindex;
      switch (form->type)
      {
        case 0:
          if (!UnitWorkFromFormindex)
            goto LABEL_24;
          v13 = UnitWorkFromFormindex->badstatus & 0xFFF;
          if (v13 != 16 && v13 != 1)
            goto LABEL_24;
          RunBadAction(UnitWorkFromFormindex, &form);
          v12 = form;
          if ((~form->stat & 0x82) == 0)
            goto LABEL_25;
          goto LABEL_31;
        case 1:
        case 3:
          RunDamage(UnitWorkFromFormindex, &form);
          v12 = form;
          if ((~form->stat & 0x82) == 0)
            goto LABEL_25;
          goto LABEL_31;
        case 2:
          RunSake(UnitWorkFromFormindex, &form);
          goto LABEL_24;
        case 4:
          RunLoad(&data, &form);
          v12 = form;
          if ((~form->stat & 0x82) != 0)
            goto LABEL_31;
          goto LABEL_25;
        default:
LABEL_24:
          v12 = form;
          if ((~form->stat & 0x82) == 0)
          {
LABEL_25:
            if (v12->type != 3 && mdlChkMotionEnd(v12, v3))
            {
              if (form->hunit->NowMotion || (autotime = form->autotime) == 0)
                nbSetUnitMotion(&form, 0, 3, 1.0);
              else
                form->autotime = autotime - 1;
            }
          }
LABEL_31:
          UpdateFormAnime(&data, &form, &v30);
          v15 = form;
          if ((form->type - 1) >= 4)
          {
            if (!v11 || (v16 = v11->badstatus & 0xFFF, v16 != 1) && v16 != 16)
            {
              UpdateFormPosRot(&form, v3);
              v15 = form;
            }
          }
          if (v15->basic)
          {
            SDF_VU0__LOADVECTOR(v33);
            SDF_VU0__SCALEVECTOR(form->scl);
            v17 = form;
            form->basic->poseset->flag |= 1u;
            v17->basic->poseset->flag &= ~2u;
            SDF_VU0__STOREVECTOR(&v17->basic->poseset->scl);
            v15 = form;
            basic = form->basic;
            if (basic)
            {
              workdata = basic->workdata;
              klass = workdata->klass;
              if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
                || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
              {
                sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v34);
                if ((v34[0] & 1) != 0)
                  v28 = v34[2];
                else
                  v28 = v34 + 1;
                v29 = sub_8C4940(v28);
              }
              monitor = workdata[3].monitor;
              v23 = monitor | 1;
              v24 = monitor & 0xFFFFFFFE;
              if ((form->stat & 0x2000) != 0)
                v25 = v23;
              else
                v25 = v24;
              LODWORD(workdata[3].monitor) = v25;
              v15->basic->poseset->flag |= 1u;
              v15->basic->poseset->flag &= ~2u;
            }
          }
          ++v15->time;
          break;
      }
    }
  }
  while (v5++ < 0xF);
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
