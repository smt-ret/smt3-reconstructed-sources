#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTLSysHandle_t effBTLSysHandle_t;
typedef struct effBTL_t effBTL_t;
typedef struct effPCPBossBUNSIN2_t effPCPBossBUNSIN2_t;
typedef struct effPCPBossBUNSIN_t effPCPBossBUNSIN_t;
typedef struct effPCPBossONGY2_t effPCPBossONGY2_t;
typedef struct effPCPBossONGY_t effPCPBossONGY_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbKoukaProcessData_t nbKoukaProcessData_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

void DelKoukaPacket(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
char *GetAkey(s32 no);
void *GetHitNum(s32 idx, s32 copyNumber);
void NumEffectClip(nbKoukaPacket_t **p);
void RunAnalyzeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunBadEffKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunBadMotKaifukuKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunBossEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunDamageMotionKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunFadeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunFlyKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunFormOnOffKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunHatudoEffectEndKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunHelpKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunHitEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunHitStopKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunMojiEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunMotionKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunMotionStopKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunMoveKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunNumEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunPadShockKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunPcmKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunPressKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunRotKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunSeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunSkillColorKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunSkillEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunSummonKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void RunUnitColKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__SETVECTOR_Z(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void ToMatrix(void);
f32 ToTime(s32 frame);
void Unlock_16599376(char *id);
u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
void datSetBadStat(datUnitWork_t *work, u32 badstat);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3FadeIn2(u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkLightObjectToUnitObject(dds3Basic_t **lightbasic, dds3Basic_t **unitbasic, u32 frame);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
void dds3Printf(char *str, void **LegacyParamArray);
void dds3RotationArc(void);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3SlowOn(s32 aSlowTime, s32 slowcnt);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3Stop(u32 frame);
effBTLCutHandle_t *effBTLCutCreate(effBTL_t **hBTLEffect, u16 CutNum, nbFormation_t *pFormation, u32 stat);
void effBTLCutDelete(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutDraw(effBTLCutHandle_t **hBTLCutEffect);
u32 effBTLCutGetFrame(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutSetCutEndFrame(effBTLCutHandle_t **hBTLCutEffect, u32 frame);
void effBTLDelete(effBTL_t **hBTLEffect);
u32 effBTLModelGetID(nbFormation_t **pFormation);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
s32 effBTLSkillCheckRun(void);
void effBTLSkillEnd(void);
u32 effBTLSkillGetID(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
u32 effBTLSkillGetTargetNumber(void);
void effBTLSkillStart(u32 id, u32 stat);
effBTLSysHandle_t *effBTLSystemCreate(nbFormation_t **pFormation, u32 id);
void effBTLSystemCut1Delete(effBTLCutHandle_t **hBTLCutEffect);
void effBTLSystemCut1Draw(effBTLCutHandle_t **hBTLCutEffect);
void effBTLSystemDelete(effBTLSysHandle_t **hEffBTLSys);
void effBTLSystemDelete2(effBTLSysHandle_t **hEffBTLSys);
void effBTLSystemDraw(effBTLSysHandle_t **hEffBTLSys);
void effPCPBossBUNSIN2Delete(effPCPBossBUNSIN2_t *pPCPBossBUNSIN2);
void effPCPBossBUNSIN2Draw(effPCPBossBUNSIN2_t *pPCPBossBUNSIN2);
void effPCPBossBUNSINDelete(effPCPBossBUNSIN_t *pPCPBossBUNSIN);
void effPCPBossBUNSINDraw(effPCPBossBUNSIN_t **pPCPBossBUNSIN);
void effPCPBossONGY2Delete(effPCPBossONGY2_t *pPCPBossONGY2);
void effPCPBossONGY2Draw(effPCPBossONGY2_t **pPCPBossONGY2);
void effPCPBossONGYDelete(effPCPBossONGY_t *pPCPBossONGY);
void effPCPBossONGYDraw(effPCPBossONGY_t *pPCPBossONGY);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon16(void);
void evtSetAgeOfMoon(s32 age);
s32 evtSetRegistUnit(s32 major, s32 minor);
void evtSetUnitColorA(evtUnitHandle_t **h, u32 frame, u32 a);
void evtSetUnitColorRGB(evtUnitHandle_t **h, u32 frame, u32 rgb);
void evtSetUnitRot1(evtUnitHandle_t **h, sdfVector4_t rot, s32 para1);
void mdlSetMotionSpeedAnimator(void *mAnimator, f32 speed);
void nbAddHpMp(s32 formindex, s32 type, s32 n);
void nbAddOrder(s32 findex);
s32 nbCheckFormationPlayerSide(s32 formindex);
s32 nbCheckLoadUnitPackFile(nbFormation_t **form, s32 major, s32 minor, bool semiflg);
void nbDelKoukaPacket(nbKoukaPacket_t **p);
void nbDispJyokyoHelp(s32 msgid, s32 no, s32 var_id, s32 var_ind);
void nbDispSkillName(s32 id);
void nbDrawNumber(sdfTexHandle_t *tex, u32 num, s32 x, s32 y, u32 c, s32 mod, nbFormation_t *form, s32 number);
void nbFormDispOff(s32 formindex);
void nbFormDispOn(s32 formindex);
void nbGetFormSphereTop(nbFormation_t *form);
void nbGetFormTop(nbFormation_t *form);
nbKoukaProcessData_t *nbGetKoukaProcessData(void);
nbMainProcessData_t *nbGetMainProcessData(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
void nbPanelAnalyzeDraw(datUnitWork_t *pUnitWork);
void nbPanelDraw(s32 flag);
void nbPanelStockEnd(void);
void nbPanelStockFadeOUT(void);
void nbPnl_rsetAlpha(s32 mode);
void nbPnl_rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void nbReturnUnit(s32 partyno, s32 lost, s32 dead);
s32 nbScreenOffset(sdfIVector4_t **pos, nbKoukaPacket_t *p);
void nbSetBadStat(s32 formindex, s32 sw, s32 badstat);
void nbSetBadstatMotion(nbFormation_t **form, s32 type, f32 range);
void nbSetBadstatMotion2(nbFormation_t **form);
void nbSetDamage(nbFormation_t **form, f32 range, s32 week);
void nbSetDamage2(nbFormation_t **form, f32 range);
void nbSetEnemyFormation(nbMainProcessData_t **data);
s32 nbSetHojoKouka(s32 formindex, u32 hojotype, s32 hojopoint, s32 nvirtual);
void nbSetPartyFormation(nbMainProcessData_t **data, u32 group);
void nbSetSake(nbFormation_t **form, f32 range, f32 speed);
void nbSetUnitHomeMove(s32 partyno, f32 speed);
void nbSetUnitMotion(nbFormation_t **form, s32 motion2, s32 mode, f32 ritu);
void nbSetUnitMove(s32 partyno, sdfVector4_t pos, f32 speed);
void nbSetWaitMotion(nbFormation_t **form, s32 motion, f32 ritu);
void nbSummonUnit(s32 side, s32 stockno, s32 formindex);
void nbToCurrectClipOffsetForOrg(sdfIVector4_t **pos);
void nbUpdateOrder(void);
s32 p2sdPlaySE(s32 a);
void p2sdPlaySE_Dead(s32 devil_id);
void p2sdSndStop_20178672(char *define_name);
bool p2sdStatusSE_Dead(void);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSqrt(f32 aValue);

// 0x19747c0
void DelKoukaPacket(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    effBTLCutDelete(0);
    effBTLDelete(0);
    effBTLSystemDelete2(0);
    effBTLSystemCut1Delete(0);
    effPCPBossBUNSINDelete(0);
    effPCPBossBUNSIN2Delete(0);
    effPCPBossONGYDelete(0);
    effPCPBossONGY2Delete(0);
}

// 0x197b3f0
nbKoukaProcessData_t *InitKoukaProcessData(nbMainProcessData_t **data) {
  nbKoukaProcessData_t_o *v3;
  nbMainProcessData_t_o *v4;

  v3 = Allocate(nbKoukaProcessData_t);
  nbKoukaProcessData_t___ctor(v3);
  v4 = *data;
  v3->packetcnt = 0;
  v3->data = v4;
  v3->first = 0;
  v3->last = 0;
  return v3;
}

// 0x19745c0
void LinkKoukaPacket(nbKoukaProcessData_t **k, nbKoukaPacket_t *p) {
  nbKoukaProcessData_t_o *v3;
  struct nbKoukaPacket_t_o **p_last;
  struct nbKoukaPacket_t_o *v5;
  struct nbKoukaPacket_t_o *last;

  v3 = *k;
  if (!(*k)->first)
  {
    v3->first = p;
    p_last = &(*k)->last;
    v5 = *p_last;
    if (!*p_last)
  }
  last = v3->last;
  p_last = &v3->last;
  v5 = last;
  if (last)
  {
    v5->next = p;
    p->prev = (*k)->last;
    p_last = &(*k)->last;
  }
  *p_last = p;
  ++(*k)->packetcnt;
}

// 0x19774b0
void NumEffectClip(nbKoukaPacket_t **p) {
    SDF_VU0__STOREVECTOR(0);
    nbToCurrectClipOffsetForOrg(0);
    effBTLSkillCheckRun();
    evtBitCheck(0);
    effBTLSkillGetID();
    effBTLSkillGetInvokeFormation(0);
    effBTLModelGetID(0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    effBTLSkillGetTargetNumber();
    effBTLSkillGetTargetFormation(0);
    sdfModelGetMarkPosUnity(0, 0);
    sdfSqrt(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    nbScreenOffset(0, 0);
}

// 0x1979a30
void RunAnalyzeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v7;

  formindex = (*p)->form->formindex;
  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex, p);
    if (!UnitWorkFromFormindex)
      return;
  }
  v7 = UnitWorkFromFormindex;
  nbPanelAnalyzeDraw(v7);
  nbPanelDraw(0);
}

// 0x19772b0
void RunBadEffKaifukuKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  struct nbFormation_t_o *form;
  effBTLSysHandle_t_o *badeff;
  effBTLSysHandle_t_o *hEffBTLSys;

  hEffBTLSys = 0;
  form = (*p)->form;
  if ((form->anime & 0x100) != 0)
  {
    badeff = form->badeff;
    if (badeff)
    {
      hEffBTLSys = badeff;
      effBTLSystemDelete(&hEffBTLSys);
      (*p)->form->badeff = 0;
      (*p)->form->anime &= ~0x100u;
    }
  }
}

// 0x1977190
void RunBadEffKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v4;
  struct nbFormation_t_o *form;
  effBTLSysHandle_t_o *badeff;
  u32 i;
  nbFormation_t_o **p_form;
  struct nbFormation_t_o *v9;
  struct nbFormation_t_o *v10;
  effBTLSysHandle_t_o *hEffBTLSys;

  hEffBTLSys = 0;
  v4 = *p;
  form = (*p)->form;
  if ((form->anime & 0x100) != 0)
  {
    badeff = form->badeff;
    if (badeff)
    {
      hEffBTLSys = badeff;
      effBTLSystemDelete(&hEffBTLSys);
      (*p)->form->badeff = 0;
      (*p)->form->anime &= ~0x100u;
      v4 = *p;
    }
  }
  i = v4->data1->i;
  if (i)
  {
    v10 = v4->form;
    p_form = &v4->form;
    v9 = v10;
    v9->badeff = effBTLSystemCreate(p_form, i);
    (*p)->form->anime |= 0x100u;
  }
}

// 0x19794f0
void RunBadMotKaifukuKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  struct nbFormation_t_o *form;
  UnityEngine_Animator_o *modelanm;
  f32 motspeed;

  form = (*p)->form;
  modelanm = form->modelanm;
  motspeed = form->motspeed;
  mdlSetMotionSpeedAnimator(modelanm, motspeed);
  nbSetWaitMotion(&(*p)->form, 0, 1.0, 0);
  nbSetUnitMotion(&(*p)->form, 0, 1, 1.0, 0);
  (*p)->form->anime &= ~0x80u;
  (*p)->form->type = 0;
  (*p)->form->time = 0;
}

// 0x19794d0
void RunBadStatKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbSetBadStat(
    (*p)->form->formindex,
    (*p)->data1->i,
    (*p)->data2->i,
    0);
}

// 0x1975ce0
void RunBossEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    effPCPBossBUNSINDraw(0);
    effPCPBossBUNSIN2Draw(0);
    effPCPBossONGYDraw(0);
    effPCPBossONGY2Draw(0);
}

// 0x1976b60
void RunDamageMotionKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v4;
  s32 type;
  s32 v6;
  nbFormation_t_o **p_form;
  f32 f;
  s32 i;
  bool v10;
  nbKoukaPacket_t_o *v11;
  bool v12;
  nbFormation_t_o **v13;
  struct nbFormation_t_o *v15;
  UnityEngine_Animator_o *v16;
  f32 v17;
  f32 v18;
  nbFormation_t_o **v19;
  struct nbFormation_t_o *form;
  UnityEngine_Animator_o *modelanm;
  f32 motspeed;

  v4 = *p;
  type = (*p)->type;
  if ((*p)->type <= 10)
  {
    if (type == 9)
    {
      p_form = &v4->form;
      f = v4->data1->f;
      i = v4->data2->i;
    }
    if (type != 10)
      return;
  }
  else if (type != 37)
  {
    if (type == 53)
      nbSetDamage2(&v4->form, v4->data1->f);
    return;
  }
  v6 = v4->data2->i;
  if (v6 <= 32)
  {
    if (v6 <= 8)
    {
      switch (v6)
      {
        case -1:
          nbSetDamage2(&v4->form, v4->data1->f);
          nbSetUnitMotion(&(*p)->form, 2, 0, 1.0, 0);
          (*p)->form->anime &= ~0x80u;
          v19 = &(*p)->form;
          v18 = 1.0;
        case 1:
        case 2:
        case 4:
        case 8:
        default:
      }
    }
    if (v6 == 16)
    if (v6 != 32)
  }
  if (v6 <= 128)
  {
    if (v6 != 64 && v6 != 128)
  }
  if (v6 == 256)
  {
    if (type == 10)
    {
      nbSetDamage(&v4->form, v4->data1->f, 1);
      v4 = *p;
      form = (*p)->form;
      if ((form->anime & 0x80) != 0)
      {
        modelanm = form->modelanm;
        motspeed = form->motspeed;
        mdlSetMotionSpeedAnimator(modelanm, motspeed);
        v4 = *p;
      }
    }
    v4->form->anime &= ~0x80u;
    v19 = &(*p)->form;
    v18 = 0.5;
  }
  if (v6 == 512)
  {
    if (type == 10)
    {
      nbSetDamage(&v4->form, v4->data1->f, 1);
      v4 = *p;
      v15 = (*p)->form;
      if ((v15->anime & 0x80) != 0)
      {
        v16 = v15->modelanm;
        v17 = v15->motspeed;
        mdlSetMotionSpeedAnimator(v16, v17);
        v4 = *p;
      }
    }
    v4->form->anime &= ~0x80u;
    v18 = 1.0;
    v19 = &(*p)->form;
    nbSetWaitMotion(v19, 2, v18);
    return;
  }
  if (v6 != 1024)
  {
    v10 = Equals_5234480(v4->form->akey, StringLiteral_14722);
    v11 = *p;
    v12 = v10;
    p_form = &(*p)->form;
    if (!v12)
    {
      nbSetBadstatMotion(p_form, v11->data2->i, v11->data1->f);
      return;
    }
    f = v11->data1->f;
    i = 1;
    nbSetDamage(p_form, f, i);
    return;
  }
  v13 = &v4->form;
  if (type == 10)
    nbSetBadstatMotion(v13, v6, v4->data1->f);
  else
    nbSetBadstatMotion2(v13);
  set_keepAnimatorControllerStateOnDisable((*p)->form->modelanm, 1, 0);
}

// 0x197a4a0
void RunDeadEventKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  (*k)->data->actionstackp = 0;
  (*k)->data->eventno = (*p)->data1->i;
}

// 0x197a4d0
void RunFadeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v4;
  s32 type;
  s32 v6;
  u32 v7;
  u32 v8;
  u32 v9;
  u32 v10;
  u32 i;

  v4 = *p;
  type = (*p)->type;
  if (type == 48)
  {
    i = v4->data1->i;
    dds3FadeIn2(i);
  }
  else if (type == 47)
  {
    v6 = v4->data2->i;
    if (v6 == 1)
    {
      v7 = v4->data1->i;
      v8 = 255;
      v9 = 255;
      v10 = 255;
    }
    if (!v6)
    {
      v7 = v4->data1->i;
      v8 = 0;
      v9 = 0;
      v10 = 0;
      dds3FadeOut(v8, v9, v10, v7);
    }
  }
}

// 0x197a6b0
void RunFlareChargeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  s32 AgeOfMoon16;
  s32 v4;

  AgeOfMoon16 = evtGetAgeOfMoon16();
  v4 = AgeOfMoon16 + 17;
  if (AgeOfMoon16 + 2 >= 0)
    v4 = AgeOfMoon16 + 2;
  evtSetAgeOfMoon(AgeOfMoon16 + 2 - (v4 & 0xFFFFFFF0), 0);
}

// 0x1979d30
void RunFlyKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    nbGetUnitWorkFromFormindex(0);
    nbCheckLoadUnitPackFile(0, 0, 0, 0);
    dds3DeleteSceneBasicData(0);
    effBTLSystemDelete2(0);
    evtSetRegistUnit(0, 0);
    dds3GetActiveScene();
    dds3SearchSceneBasic(0, 0, 0);
    dds3LinkLightObjectToUnitObject(0, 0, 0);
    nbSetWaitMotion(0, 0, 0);
    nbSetUnitMotion(0, 0, 0, 0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3ObjectBaseOnFlag(0, 0, 0);
    datGetMaxHp(0);
    datGetMaxMp(0);
    datSetBadStat(0, 0);
    GetAkey(0);
}

// 0x1979cf0
void RunFormFlagOnOffKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v3;
  struct nbFormation_t_o *form;
  u32 stat;
  s32 i;
  s32 v7;
  s32 v8;

  v3 = *p;
  form = (*p)->form;
  if (form)
  {
    stat = form->stat;
    if ((stat & 1) != 0)
    {
      i = v3->data1->i;
      v7 = v3->data2->i;
      if (i)
        v8 = v7 | stat;
      else
        v8 = stat & ~v7;
      form->stat = v8;
    }
  }
}

// 0x1979c20
void RunFormOnOffKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  struct nbFormation_t_o *form;
  s32 i;
  s32 formindex;
  s32 v7;

  form = (*p)->form;
  if (form && (form->stat & 1) != 0)
  {
    i = (*p)->data1->i;
    formindex = form->formindex;
    if (i)
    {
      else
      {
        v7 = form->formindex;
      }
      nbFormDispOn(v7, p);
    }
    else
    {
      nbFormDispOff(formindex, p);
    }
  }
}

// 0x19760b0
void RunHatudoEffectEndKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  struct nbKoukaPacket_t_o *i;
  u32 Frame;
  effBTLCutHandle_t_o *hBTLCutEffect;

  hBTLCutEffect = 0;
  for (i = (*k)->first; i; i = i->next)
  {
    if (i->uniqueid == (*p)->uniqueid && i->type == 26 && i->framelength >= 13)
    {
      i->framelength = 12;
      hBTLCutEffect = i->cuteff;
      Frame = effBTLCutGetFrame(&hBTLCutEffect);
      effBTLCutSetCutEndFrame(&hBTLCutEffect, Frame + 12);
    }
  }
}

// 0x1979b00
void RunHelpKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v6;
  s32 jyokyomsgid;
  struct System_Int16_array *s;
  u32 max_length;
  s32 v10;
  s32 v12;
  s32 i;

  v6 = *p;
  if ((*p)->type == 35)
  {
    jyokyomsgid = (*k)->data->jyokyomsgid;
    s = v6->data1->s;
    max_length = s->max_length;
    v10 = s->m_Items[0];
    v12 = v6->data1->s->m_Items[1];
    i = v6->data2->i;
    nbDispJyokyoHelp(jyokyomsgid, v10, v12, i);
  }
}

// 0x1977370
void RunHitEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    effBTLSystemDraw(0);
}

// 0x1979970
void RunHitStopKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  if ((*p)->time == 1)
  {
    dds3SlowOn(3, 24);
  }
  else if (!(*p)->time)
  {
    dds3Stop(0xCu);
  }
}

// 0x197a680
void RunHojoKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbSetHojoKouka(
    (*p)->form->formindex,
    (*p)->data1->i,
    (*p)->data2->i,
    0,
    0);
}

// 0x1979350
void RunHpMpKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  if (((*k)->data->stat & 0x20000) == 0)
    nbAddHpMp(
      (*p)->form->formindex,
      (*p)->data1->i,
      (*p)->data2->i,
      0);
}

// 0x1978ce0
void RunMojiEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    nbGetFormTop(0);
    nbGetFormSphereTop(0);
    NumEffectClip(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__Retdds3ColorItoF(0, 0);
    nbPnl_rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    nbPnl_rsetAlpha(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    nbScreenOffset(0, 0);
    GetHitNum(0, 0);
    Unlock_16599376(0);
}

// 0x1976a20
void RunMotionKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v3;
  s32 type;
  s32 i;
  f32 f;
  nbFormation_t_o **p_form;
  s32 v8;
  struct System_Int16_array *s;
  s32 v12;
  struct System_Int16_array *v13;
  struct System_Int16_array *v15;

  v3 = *p;
  type = (*p)->type;
  if (type == 55)
  {
    s = v3->data1->s;
    v12 = s->m_Items[1];
    if ((v12 - 2) < 2 || v12 == 1)
    {
      v15 = (*p)->data1->s;
      f = (*p)->data2->f;
      i = v15->m_Items[0];
      p_form = &(*p)->form;
      v8 = 3;
    }
    if (!s->m_Items[1])
    {
      v13 = (*p)->data1->s;
      f = (*p)->data2->f;
      i = v13->m_Items[0];
      p_form = &(*p)->form;
    }
  }
  else if (type == 27)
  {
    i = v3->data1->i;
    f = 1.0;
    p_form = &v3->form;
    if (i == 23)
    {
      v8 = 2;
      nbSetUnitMotion(p_form, i, v8, f);
      return;
    }
    v8 = 0;
  }
}

// 0x19768e0
void RunMotionStopKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  struct nbFormation_t_o *form;
  s32 type;
  UnityEngine_Animator_o *v6;
  struct evtUnitHandle_t_o *v7;
  s32 v8;
  UnityEngine_Animator_o *modelanm;
  f32 motspeed;
  struct evtUnitHandle_t_o *hunit;
  struct evtUnitHandle_t_o *v12;

  form = (*p)->form;
  if ((~form->stat & 3) == 0)
  {
    type = (*p)->type;
    if (type == 33)
    {
      modelanm = form->modelanm;
      motspeed = form->motspeed;
      mdlSetMotionSpeedAnimator(modelanm, motspeed);
      hunit = (*p)->form->hunit;
      hunit->Flag &= ~0x400000u;
      v12 = (*p)->form->hunit;
      v12->Flag &= ~0x40u;
      v7 = (*p)->form->hunit;
      v8 = v7->Flag | 0x20;
    }
    else
    {
      if (type != 32)
        return;
      v6 = form->modelanm;
      mdlSetMotionSpeedAnimator(v6, 0.0);
      v7 = (*p)->form->hunit;
      v8 = v7->Flag | 0x400000;
    }
    v7->Flag = v8;
  }
}

// 0x1976430
void RunMoveKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  struct nbParty_t_array *party;
  s64 partyno;
  nbKoukaPacket_t_o *v6;
  s32 type;

  party = (*k)->data->party;
  partyno = (*p)->partyno;
  if ((party->m_Items[partyno]->flag & 1) != 0)
  {
    v6 = *p;
    type = (*p)->type;
    if (type == 2)
    {
      nbSetUnitHomeMove(v6->partyno, v6->data1->f);
    }
    else if (type == 1)
    {
      nbSetUnitMove(v6->partyno, v6->v, v6->data1->f);
    }
  }
}

// 0x19787c0
void RunNumEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    nbGetFormTop(0);
    NumEffectClip(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    nbScreenOffset(0, 0);
    nbDrawNumber(0, 0, 0, 0, 0, 0, 0, 0);
    effBTLSkillGetInvokeFormation(0);
    nbCheckFormationPlayerSide(0);
    nbGetUnitWorkFromFormindex(0);
    Unlock_16599376(0);
}

// 0x197a730
void RunPadShockKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v4;
  struct System_Int16_array *s;
  u32 max_length;
  u32 v7;
  s16 v9;
  struct System_Int16_array *v10;
  u32 v12;

  v4 = *p;
  s = (*p)->data1->s;
  max_length = s->max_length;
  v7 = s->m_Items[0];
  v9 = (*p)->data1->s->m_Items[1];
  v10 = v4->data2->s;
  v12 = v10->m_Items[0];
  dds3PadAct(v7, v9, v12);
}

// 0x1979870
void RunPcmKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  s32 i;

  else if (p2sdStatusSE_Dead())
  {
    return;
  }
  if (((*k)->data->flag & 1) == 0 && (*p)->type == 36)
  {
    i = (*p)->data1->i;
    p2sdPlaySE_Dead(i);
    (*k)->data->flag |= 1u;
  }
}

// 0x1979390
void RunPressKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  struct nbMainProcessData_t_o *data;
  u32 stat;
  nbKoukaPacket_t_o *v5;
  s32 type;
  s32 press4_ten;
  struct System_Int16_array *s;
  struct nbMainProcessData_t_o *v10;
  struct System_Int16_array *v11;
  s32 v12;
  s32 v14;
  struct nbMainProcessData_t_o *v15;

  data = (*k)->data;
  stat = data->stat;
  if ((stat & 0x10000) == 0)
  {
    v5 = *p;
    type = (*p)->type;
    if (type == 31)
    {
      if ((stat & 8) != 0)
        press4_ten = 0;
      else
        press4_ten = data->press4_ten;
      s = v5->data1->s;
      data->press4_p = (s->m_Items[0] + data->press4_p) & ~((s->m_Items[0] + data->press4_p) >> 31);
      v10 = (*k)->data;
      v11 = (*p)->data1->s;
      v12 = v10->press4_ten;
      v14 = (v11->m_Items[1] + v12) & ~((v11->m_Items[1] + v12) >> 31);
      v10->press4_ten = (v11->m_Items[1] + v12) & ~((v11->m_Items[1] + v12) >> 31);
      v15 = (*k)->data;
      if ((v15->stat & 8) == 0)
        v15->d31_press_total += press4_ten - v14;
    }
    else if (type == 18)
    {
      data->press3 = fminf(fmaxf(data->press3 + v5->data1->f, 0.0), 1.0);
    }
  }
}

// 0x1974370
void RunReturnKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t *p) {
  struct nbMainProcessData_t_o *data;

  nbReturnUnit(p->party->partyindex, 0, p->data1->i);
  data = (*k)->data;
  if (data->encno == 271)
    data->stat |= 0x2000u;
}

// 0x1976500
void RunRotKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__LOADIDENTITYVECTOR();
    SDF_VU0__SETVECTOR_Z(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    dds3RotationArc();
    evtSetUnitRot1(0, (sdfVector4_t){0}, 0);
}

// 0x1977170
void RunSakeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbSetSake(&(*p)->form, (*p)->data1->f, (*p)->data2->f, 0);
}

// 0x19795e0
void RunSeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    evtBitCheck(0);
    p2sdSndStop_20178672(0);
    p2sdPlaySE(0);
    dds3Printf(0, 0);
}

// 0x197a840
void RunSkillColorKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v4;
  s32 type;
  u32 i;
  u32 v7;

  v4 = *p;
  type = (*p)->type;
  if (type == 14)
  {
    else
    {
      effBTLSkillEnd();
    }
  }
  else if (type == 54)
  {
    i = v4->data1->i;
    v7 = v4->data2->i;
    effBTLSkillStart(i, v7);
  }
}

// 0x19761a0
void RunSkillEffectKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    effBTLCutDraw(0);
    effBTLSystemCut1Draw(0);
    effBTLCutCreate(0, 0, 0, 0);
}

// 0x197a600
void RunSkillNameKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
    nbDispSkillName(0);
}

// 0x197a990
void RunStockPanelEndKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  {
    nbPanelStockEnd();
  }
}

// 0x197a920
void RunStockPanelFadeOutKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  {
    nbPanelStockFadeOUT();
  }
}

// 0x1976ee0
void RunSummonKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  struct System_Int16_array *s;
  u32 max_length;
  s32 v7;
  struct System_Int16_array *v9;
  struct System_Int16_array *v13;
  nbKoukaProcessData_t_Fields *p_fields;
  nbKoukaProcessData_t_o *v18;
  nbMainProcessData_t_o **p_data;
  struct System_Int16_array *v20;
  s32 v21;

  nbUpdateOrder();
  s = (*p)->data1->s;
  max_length = s->max_length;
  v7 = s->m_Items[0];
  v9 = (*p)->data2->s;
  nbSummonUnit(v7, (*p)->data1->s->m_Items[1], v9->m_Items[0], 0);
  v13 = (*p)->data1->s;
  if (v13->m_Items[0])
  {
    if (v13->m_Items[0] != 1)
      return;
    p_fields = &(*k)->fields;
    nbSetEnemyFormation(&p_fields->data);
    if (((*k)->data->stat & 8) == 0)
      return;
    v20 = (*p)->data2->s;
    v21 = v20->m_Items[0];
    nbAddOrder(v21);
    return;
  }
  v18 = *k;
  p_data = &v18->data;
  nbSetPartyFormation(p_data, 0x100u);
  if (((*k)->data->stat & 8) == 0)
}

// 0x1976790
void RunUnitColKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o *v4;
  struct nbFormation_t_o *form;
  s32 type;
  u32 v7;
  u32 *p_i;
  u32 v9;
  u32 i;
  evtUnitHandle_t_o **p_hunit;
  evtUnitHandle_t_o **v12;

  v4 = *p;
  form = (*p)->form;
  if ((~form->stat & 3) == 0)
  {
    type = v4->type;
    v7 = type - 5;
    switch (v4->type)
    {
      case 5:
      case 7:
        p_i = &v4->data2->i;
      case 6:
      case 8:
        p_i = &form->modelcol;
        v9 = *p_i;
        i = v4->data1->i;
        if (v7 >= 2)
      default:
        i = 0;
        v9 = 0;
        if (v7 >= 2)
        {
          if ((type - 7) < 2)
          {
            p_hunit = &form->hunit;
            evtSetUnitColorA(p_hunit, i, v9);
          }
        }
        else
        {
          v12 = &form->hunit;
          evtSetUnitColorRGB(v12, i, v9);
        }
        break;
    }
  }
}

// 0x1974620
void UnlinkKoukaPacket(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  u64 *p_klass;
  u64 *v4;

  p_klass = &(*p)->prev->klass;
  if (!p_klass)
    p_klass = *k;
  p_klass[4] = (*p)->next;
  v4 = &(*p)->next->klass;
  if (!v4)
    v4 = *k;
  v4[5] = (*p)->prev;
  --(*k)->packetcnt;
}

// 0x1974320
void evtSetWaitHokanFrame(evtUnitHandle_t *h, s32 before, s32 smooth) {
  ;
}

// 0x1974360
void mdlSetPosition(dds3ModelHandle_t *aHandle) {
  ;
}

// 0x1974670
nbKoukaPacket_t *nbAddKoukaPacket(nbKoukaProcessData_t **k, s32 startframe, s32 framelength, s32 uniqueid) {
  u64 *v9;
  f32 v11;
  u64 v12;
  nbKoukaProcessData_t_o *v13;
  struct nbKoukaPacket_t_o **p_last;
  struct nbKoukaPacket_t_o *v15;
  struct nbKoukaPacket_t_o *last;

  v9 = Allocate(nbKoukaPacket_t);
  nbKoukaPacket_t___ctor(v9);
  *(v9 + 8) = startframe;
  *(v9 + 9) = framelength;
  *(v9 + 30) = ToTime(startframe);
  v11 = ToTime(framelength);
  *(v9 + 18) = -1;
  v12 = v9[11];
  *(v9 + 31) = v11;
  *(v9 + 5) = 0;
  *(v9 + 6) = uniqueid;
  v9[4] = 0;
  v9[10] = 0;
  v9[7] = 0;
  v9[8] = 0;
  v9[5] = 0;
  v9[6] = 0;
  *(v12 + 32) = 0;
  *(v9[12] + 32) = 0;
  v13 = *k;
  if (!(*k)->first)
  {
    v13->first = v9;
    p_last = &(*k)->last;
    v15 = *p_last;
    if (!*p_last)
  }
  last = v13->last;
  p_last = &v13->last;
  v15 = last;
  if (last)
  {
    v15->next = v9;
    v9[5] = (*k)->last;
    p_last = &(*k)->last;
  }
  *p_last = v9;
  ++(*k)->packetcnt;
  return v9;
}

// 0x1974330
s32 nbCheckModelLoad(nbMainProcessData_t *data, s32 major, s32 minor) {
  return 0;
}

// 0x1975b30
s32 nbCheckSePacket(s32 start, s32 se, s32 frame) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    return 0;
}

// 0x1974350
void nbDecodePackData(void *p, s32 major, s32 minor) {
  ;
}

// 0x1975580
void nbDelAllKoukaPacketType(s32 type) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    nbDelKoukaPacket(0);
}

// 0x1971430
void nbDelAllMojiNumEffectKoukaPacket(nbFormation_t **form, s32 motno) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    nbDelKoukaPacket(0);
    GetHitNum(0, 0);
}

// 0x1975400
void nbDelAllUniqueIDKoukaPacket(s32 uniqueid) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    nbDelKoukaPacket(0);
}

// 0x1974e40
void nbDelKoukaPacket(nbKoukaPacket_t **p) {
  nbKoukaPacket_t_o **v2;
  nbKoukaProcessData_t_o *KoukaProcessData;
  nbKoukaPacket_t_o *v6;
  s32 type;
  struct nbKoukaPacket_t_o *first;
  struct nbKoukaPacket_t_o *next;
  struct System_Int16_array *s;
  struct System_Int16_array *v13;
  s32 v14;
  struct System_Int16_array *v16;
  s32 formindex;
  s32 v19;
  UnityEngine_GameObject_o *HitNum;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v22;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v24;
  UnityEngine_Component_o *v25;
  UnityEngine_GameObject_o *v26;
  UnityEngine_Transform_o *v27;
  UnityEngine_Component_o *v28;
  UnityEngine_GameObject_o *v29;
  UnityEngine_Transform_o *v30;
  UnityEngine_Component_o *v31;
  UnityEngine_GameObject_o *v32;
  UnityEngine_Transform_o *v33;
  UnityEngine_Component_o *v34;
  UnityEngine_GameObject_o *v35;
  UnityEngine_Transform_o *v36;
  UnityEngine_Component_o *v37;
  UnityEngine_GameObject_o *v38;
  nbKoukaProcessData_t_o *k;

  v2 = p;
  KoukaProcessData = nbGetKoukaProcessData(p);
  k = KoukaProcessData;
  v6 = *v2;
  type = (*v2)->type;
  if (type == 22 || type == 16)
  {
    first = KoukaProcessData->first;
    if (first)
    {
      while (1)
      {
        next = first->next;
        if (v6 != first
          && v6->type == first->type
          && v6->form->formindex == first->form->formindex)
        {
          s = v6->data1->s;
          v13 = first->data1->s;
          v14 = s->m_Items[0];
          if (v14 == v13->m_Items[0])
            break;
        }
        if (!next)
        {
          v6 = *v2;
        }
        v6 = *v2;
        first = next;
      }
    }
    else
    {
      v16 = v6->data1->s;
      formindex = v6->form->formindex;
      v19 = v16->m_Items[0];
      HitNum = GetHitNum(formindex, v19);
      SetActive(HitNum, 0, 0);
      transform = get_transform(HitNum, 0);
      v22 = Find(transform, StringLiteral_21418, 0);
      gameObject = get_gameObject(v22);
      SetActive(gameObject, 0, 0);
      v24 = get_transform(HitNum, 0);
      v25 = Find(v24, StringLiteral_21419, 0);
      v26 = get_gameObject(v25);
      SetActive(v26, 0, 0);
      v27 = get_transform(HitNum, 0);
      v28 = Find(v27, StringLiteral_21420, 0);
      v29 = get_gameObject(v28);
      SetActive(v29, 0, 0);
      v30 = get_transform(HitNum, 0);
      v31 = Find(v30, StringLiteral_21421, 0);
      v32 = get_gameObject(v31);
      SetActive(v32, 0, 0);
      v33 = get_transform(HitNum, 0);
      v34 = Find(v33, StringLiteral_21422, 0);
      v35 = get_gameObject(v34);
      SetActive(v35, 0, 0);
      v36 = get_transform(HitNum, 0);
      v37 = Find(v36, StringLiteral_21423, 0);
      v38 = get_gameObject(v37);
      SetActive(v38, 0, 0);
    }
  }
  k = nbGetKoukaProcessData(KoukaProcessData);
  DelKoukaPacket(&k, v2);
}

// 0x1975700
void nbDelUnEventKoukaPacket(void) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
    nbReturnUnit(0, 0, 0);
    effBTLSkillEnd();
    nbDelKoukaPacket(0);
}

// 0x1974500
s32 nbGetKoukaPacketCnt(void) {
  return nbGetKoukaProcessData()->packetcnt;
}

// 0x1974570
s32 nbGetKoukaPacketTypeCnt(s32 type) {
  struct nbKoukaPacket_t_o *first;
  s32 result;
  s32 v5;

  first = nbGetKoukaProcessData(*&type)->first;
  if (!first)
    return 0;
  result = 0;
  do
  {
    v5 = first->type;
    first = first->next;
    if (v5 == type)
      ++result;
  }
  while (first);
  return result;
}

// 0x19743d0
nbKoukaProcessData_t *nbGetKoukaProcessData(void) {
    dds3SearchProcessName(0);
    dds3GetProcessData(0);
    return 0;
}

// 0x1974520
s32 nbGetUniqueIdKoukaPacketCnt(s32 uniqueid) {
  struct nbKoukaPacket_t_o *first;
  s32 result;
  s32 v5;

  first = nbGetKoukaProcessData(*&uniqueid)->first;
  if (!first)
    return 0;
  result = 0;
  do
  {
    v5 = first->uniqueid;
    first = first->next;
    if (v5 == uniqueid)
      ++result;
  }
  while (first);
  return result;
}

// 0x197b460
void nbInitKoukaProcess(nbMainProcessData_t *data) {
  nbKoukaProcessData_t_o *v3;
  u64 *v4;
  u64 *v5;
  dds3ProcessID_t_o *target;

  target = 0;
  v3 = Allocate(nbKoukaProcessData_t);
  nbKoukaProcessData_t___ctor(v3);
  v3->data = data;
  v3->packetcnt = 0;
  v3->first = 0;
  v3->last = 0;
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbKoukaProcess_nbKoukaProcess1__);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_nbKoukaProcess_nbKoukaShutdown__);
  target = dds3StartProcess(StringLiteral_21417, 0x2B08u, 1, 1, v4, 0, v5, 0, v3, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->KoukaProcessID = target;
}

// 0x197aa00
void *nbKoukaProcess1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    nbDelKoukaPacket(0);
    RunSkillEffectKouka(0, 0);
    RunMoveKouka(0, 0);
    RunRotKouka(0, 0);
    RunUnitColKouka(0, 0);
    RunDamageMotionKouka(0, 0);
    nbReturnUnit(0, 0, 0);
    RunSummonKouka(0, 0);
    nbSetSake(0, 0, 0);
    RunSkillColorKouka(0, 0);
    RunHitEffectKouka(0, 0);
    RunNumEffectKouka(0, 0);
    nbAddHpMp(0, 0, 0);
    RunPressKouka(0, 0);
    nbSetBadStat(0, 0, 0);
    RunBadMotKaifukuKouka(0, 0);
    RunMojiEffectKouka(0, 0);
    RunBadEffKouka(0, 0);
    effBTLSystemDelete(0);
    RunSeKouka(0, 0);
    RunMotionKouka(0, 0);
    RunHitStopKouka(0, 0);
    RunMotionStopKouka(0, 0);
    RunAnalyzeKouka(0, 0);
    RunHelpKouka(0, 0);
    RunPcmKouka(0, 0);
    RunFormOnOffKouka(0, 0);
    RunBossEffectKouka(0, 0);
    RunFlyKouka(0, 0);
    RunFadeKouka(0, 0);
    nbDispSkillName(0);
    nbSetHojoKouka(0, 0, 0, 0);
    evtGetAgeOfMoon16();
    evtSetAgeOfMoon(0);
    RunPadShockKouka(0, 0);
    nbPanelStockFadeOUT();
    nbPanelStockEnd();
    RunHatudoEffectEndKouka(0, 0);
    return 0;
}

// 0x197b290
void *nbKoukaShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    DelKoukaPacket(0, 0);
    return 0;
}

// 0x1974340
s32 nbLoadSound(s32 id) {
  return 0;
}

// 0x1975970
void nbOnOffKoukaPacketFlag(s32 type, u32 flg, s32 sw) {
    nbGetMainProcessData();
    dds3GetProcessData(0);
}
