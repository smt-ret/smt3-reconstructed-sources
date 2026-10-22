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
  nbKoukaPacket_t_o **v3;
  nbKoukaPacket_t_o *v5;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  nbKoukaPacket_t_o *v11;
  nbKoukaProcessData_t_o *prev;
  u32 i;
  Il2CppObject *v15;
  Il2CppClass *v16;
  s64 v17;
  char *v18;
  s64 *v19;
  effBTLCutHandle_t_o **p_cuteff;
  struct effBTLCutHandle_t_o *cuteff;
  nbKoukaProcessData_t_o *next;
  effPCPBossBUNSIN_t_o *v23;
  effPCPBossBUNSIN_t_c *v24;
  s64 v25;
  char *v26;
  s64 *v27;
  effPCPBossBUNSIN2_t_o *v28;
  effPCPBossBUNSIN2_t_c *v29;
  s64 v30;
  char *v31;
  s64 *v32;
  effPCPBossONGY_t_o *v33;
  effPCPBossONGY_t_c *v34;
  s64 v35;
  char *v36;
  s64 *v37;
  effPCPBossONGY2_t_o *v38;
  effPCPBossONGY2_t_c *v39;
  s64 v40;
  char *v41;
  s64 *v42;
  effBTLSysHandle_t_o *hEffBTLSys;
  effBTL_t_o *hBTLEffect;
  u64 v45[2];
  char *v46;

  v3 = p;
  hEffBTLSys = 0;
  hBTLEffect = 0;
  v5 = *v3;
  switch ((*v3)->type)
  {
    case 0:
    case 0x15:
    case 0x2B:
      if (v5->cuteff)
      {
        effBTLCutDelete(&v5->cuteff);
        (*v3)->cuteff = 0;
        v5 = *v3;
        if ((*v3)->type != 43)
          goto LABEL_44;
      }
      else if ((*v3)->type != 43)
      {
        goto LABEL_44;
      }
      v6 = v5->data1->p;
      if (v6)
      {
        klass = v6->klass;
        if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBTL_t)
        {
          sub_8FC2C0(klass->_1.element_class, effBTL_t, v45);
          if ((v45[0] & 1) != 0)
            v9 = v46;
          else
            v9 = v45 + 1;
          v10 = sub_8C4940(v9);
        }
      }
      hBTLEffect = v5->data1->p;
      effBTLDelete(&hBTLEffect);
      v11 = *v3;
      prev = (*v3)->prev;
      if (!prev)
        goto LABEL_45;
      goto LABEL_46;
    case 0xF:
      i = v5->data1->i;
      if (i > 0xA || i == 3)
        goto LABEL_44;
      v15 = v5->data2->p;
      if (v15)
      {
        v16 = v15->klass;
        if (v15->klass->_2.typeHierarchyDepth < v17
          || v16->_2.typeHierarchy[v17 - 1] != effBTLSysHandle_t)
        {
          sub_8FC2C0(v16->_1.element_class, effBTLSysHandle_t, v45);
          if ((v45[0] & 1) != 0)
            v18 = v46;
          else
            v18 = v45 + 1;
          v19 = sub_8C4940(v18);
        }
      }
      hEffBTLSys = v5->data2->p;
      effBTLSystemDelete2(&hEffBTLSys);
      v11 = *v3;
      prev = (*v3)->prev;
      if (!prev)
        goto LABEL_45;
      goto LABEL_46;
    case 0x1A:
      cuteff = v5->cuteff;
      p_cuteff = &v5->cuteff;
      if (cuteff)
      {
        effBTLSystemCut1Delete(p_cuteff);
        (*v3)->cuteff = 0;
      }
      goto LABEL_44;
    case 0x27:
      v23 = v5->data1->p;
      if (v23)
      {
        v24 = v23->klass;
        if (v23->klass->_2.typeHierarchyDepth < v25
          || v24->_2.typeHierarchy[v25 - 1] != effPCPBossBUNSIN_t)
        {
          sub_8FC2C0(v24->_1.element_class, effPCPBossBUNSIN_t, v45);
          if ((v45[0] & 1) != 0)
            v26 = v46;
          else
            v26 = v45 + 1;
          v27 = sub_8C4940(v26);
        }
      }
      effPCPBossBUNSINDelete(v23);
      v11 = *v3;
      prev = (*v3)->prev;
      if (!prev)
        goto LABEL_45;
      goto LABEL_46;
    case 0x28:
      v28 = v5->data1->p;
      if (v28)
      {
        v29 = v28->klass;
        if (v28->klass->_2.typeHierarchyDepth < v30
          || v29->_2.typeHierarchy[v30 - 1] != effPCPBossBUNSIN2_t)
        {
          sub_8FC2C0(v29->_1.element_class, effPCPBossBUNSIN2_t, v45);
          if ((v45[0] & 1) != 0)
            v31 = v46;
          else
            v31 = v45 + 1;
          v32 = sub_8C4940(v31);
        }
      }
      effPCPBossBUNSIN2Delete(v28);
      v11 = *v3;
      prev = (*v3)->prev;
      if (!prev)
        goto LABEL_45;
      goto LABEL_46;
    case 0x29:
      v33 = v5->data1->p;
      if (v33)
      {
        v34 = v33->klass;
        if (v33->klass->_2.typeHierarchyDepth < v35
          || v34->_2.typeHierarchy[v35 - 1] != effPCPBossONGY_t)
        {
          sub_8FC2C0(v34->_1.element_class, effPCPBossONGY_t, v45);
          if ((v45[0] & 1) != 0)
            v36 = v46;
          else
            v36 = v45 + 1;
          v37 = sub_8C4940(v36);
        }
      }
      effPCPBossONGYDelete(v33);
      v11 = *v3;
      prev = (*v3)->prev;
      if (!prev)
        goto LABEL_45;
      goto LABEL_46;
    case 0x2A:
      v38 = v5->data1->p;
      if (v38)
      {
        v39 = v38->klass;
        if (v38->klass->_2.typeHierarchyDepth < v40
          || v39->_2.typeHierarchy[v40 - 1] != effPCPBossONGY2_t)
        {
          sub_8FC2C0(v39->_1.element_class, effPCPBossONGY2_t, v45);
          if ((v45[0] & 1) != 0)
            v41 = v46;
          else
            v41 = v45 + 1;
          v42 = sub_8C4940(v41);
        }
      }
      effPCPBossONGY2Delete(v38);
      v11 = *v3;
      prev = (*v3)->prev;
      if (!prev)
        goto LABEL_45;
      goto LABEL_46;
    default:
LABEL_44:
      v11 = *v3;
      prev = (*v3)->prev;
      if (!prev)
LABEL_45:
        prev = *k;
LABEL_46:
      prev->first = v11->next;
      next = (*v3)->next;
      if (!next)
        next = *k;
      next->last = (*v3)->prev;
      --(*k)->packetcnt;
      return;
  }
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
      goto LABEL_4;
    goto LABEL_3;
  }
  last = v3->last;
  p_last = &v3->last;
  v5 = last;
  if (last)
  {
LABEL_3:
    v5->next = p;
    p->prev = (*k)->last;
    p_last = &(*k)->last;
  }
LABEL_4:
  *p_last = p;
  ++(*k)->packetcnt;
}

// 0x19774b0
void NumEffectClip(nbKoukaPacket_t **p) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 *v7;
  u64 *v8;
  u64 *v10;
  u64 *v11;
  u64 *v13;
  u64 *v15;
  u32 *v16;
  struct System_Int32_array *pm;
  u32 max_length;
  s32 v21;
  s32 v23;
  nbFormation_t_o **p_form;
  nbFormation_t_o **v33;
  u32 ID;
  s64 *v39;
  signed s32 TargetNumber;
  signed s32 v41;
  u32 v42;
  sdfModelRootNode_t_o *modelRoot;
  s64 v48;
  s32 v49;
  s64 v50;
  s32 v52;
  s32 v53;
  s32 v55;
  sdfModelRootNode_t_o *v57;
  s64 v62;
  s32 v63;
  s64 v65;
  s32 v67;
  s32 v68;
  s32 v69;
  s64 v70;
  s64 v71;
  s64 v73;
  s64 v76;
  s64 v91;
  s64 v92;
  s64 v94;
  s64 v97;
  s64 *v109;
  u64 *v112;
  struct System_Int32_array *v115;
  s32 v118;
  struct System_Int32_array *v119;
  s32 v121;
  struct System_Int32_array *v122;
  s32 v124;
  struct System_Int32_array *v125;
  s32 v127;
  nbFormation_t_o **v128;
  nbFormation_t_o **v131;
  nbKoukaPacket_t_o **v133;
  nbFormation_t_o *v134;
  sdfIVector4_t_o *v135;
  UnityEngine_Vector4_o v136;
  UnityEngine_Vector4_o pa;
  sdfIVector4_t_o *pos;
  nbFormation_t_o *TargetFormation;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v141;

  TargetFormation = 0;
  pFormation = 0;
  *&pa.x = 0;
  *&pa.z = 0;
  *&v136.x = 0;
  *&v136.z = 0;
  v134 = 0;
  v135 = 0;
  v3 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v3);
  pos = v3;
  v4 = NewSpecific(sdfIVector4_t, 4u);
  v5 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v5);
  v4[4] = v5;
  v7 = v4 + 4;
  v8 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v8);
  v4[5] = v8;
  v10 = v4 + 5;
  v11 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v11);
  v4[6] = v11;
  v13 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v13);
  v4[7] = v13;
  v15 = NewSpecific(UnityEngine_Vector4, 2u);
  v16 = NewSpecific(s32, 2u);
  SDF_VU0__STOREVECTOR(&pa);
  nbToCurrectClipOffsetForOrg(&pos);
  pm = pos->pm;
  max_length = pm->max_length;
  v21 = pm->m_Items[0];
  v23 = pos->pm->m_Items[1];
  else if (!effBTLSkillCheckRun())
  {
    goto LABEL_51;
  }
  if (!evtBitCheck(3712))
  {
    else if (effBTLSkillGetID() != 269)
    {
      goto LABEL_51;
    }
    pFormation = effBTLSkillGetInvokeFormation(0);
    if (effBTLModelGetID(&pFormation) == 192)
    {
      p_form = &(*p)->form;
      effBTLModelGetSphereCenter(p_form);
      SDF_VU0__STOREVECTOR(&v136);
      v141.x = v136.x;
      v141.y = v136.y + (((*p)->form->h * (*p)->form->scl) * 0.5);
      v136.y = v141.y;
      goto LABEL_257;
    }
  }
LABEL_51:
  if ((v21 - 13) <= 0x1E6 && (v23 - 75) < 0xF9)
  {
    v141 = pa;
LABEL_258:
    SDF_VU0__LOADVECTOR(v141);
    return;
  }
  v33 = &(*p)->form;
  effBTLModelGetSphereCenter(v33);
  SDF_VU0__STOREVECTOR(&v136);
  else if (!effBTLSkillCheckRun())
  {
    goto LABEL_93;
  }
  ID = effBTLSkillGetID();
  if (ID - 263 <= 6 && ((1 << (ID - 7)) & 0x53) != 0)
  {
    pFormation = effBTLSkillGetInvokeFormation(0);
    if (effBTLModelGetID(&pFormation) == 192)
    {
      v136.y = v136.y + (((*p)->form->h * (*p)->form->scl) * 0.35);
      SDF_VU0__LOADVECTOR(v136);
      v39 = &"RunNumEffectKouka : DANTE 0x10B\n";
LABEL_76:
      Write(*v39, 0);
      return;
    }
  }
  else if (ID == 158)
  {
    TargetNumber = effBTLSkillGetTargetNumber();
    if (TargetNumber >= 1)
    {
      v41 = TargetNumber;
      v42 = 0;
      while (1)
      {
        TargetFormation = effBTLSkillGetTargetFormation(v42);
        if (effBTLModelGetID(&TargetFormation) == 344)
          break;
        if (++v42 >= v41)
          goto LABEL_93;
      }
      SDF_VU0__LOADVECTOR(v136);
      v39 = &"RunNumEffectKouka : BSLUSI & SRAPPA\n";
      goto LABEL_76;
    }
  }
LABEL_93:
  v133 = p;
  modelRoot = (*p)->form->hunit->Model->modelRoot;
  if (!sdfModelGetMarkPosUnity(modelRoot, 10))
  {
    SDF_VU0__LOADVECTOR(v136);
    if (*(v15 + 6))
      goto LABEL_98;
LABEL_161:
  }
  if (!*(v15 + 6))
    goto LABEL_161;
LABEL_98:
  SDF_VU0__STOREVECTOR(v15 + 2);
  nbToCurrectClipOffsetForOrg(v4 + 4);
  v48 = *(*v7 + 16LL);
  v49 = *(v48 + 32);
  v50 = *(*v7 + 16LL);
  v52 = v23 - *(v50 + 36);
  v53 = v21 - v49;
  v55 = sdfSqrt((v53 * v53) + (v52 * v52), 0);
  v16[8] = v55;
  v57 = (*p)->form->hunit->Model->modelRoot;
  if (sdfModelGetMarkPosUnity(v57, 0))
  {
    if (*(v15 + 6) <= 1u)
      goto LABEL_118;
  }
  else
  {
    SDF_VU0__LOADVECTOR(v136);
    if (*(v15 + 6) <= 1u)
    {
LABEL_118:
    }
  }
  SDF_VU0__STOREVECTOR(v15 + 3);
  nbToCurrectClipOffsetForOrg(v4 + 5);
  v62 = *(*v10 + 16LL);
  v63 = *(v62 + 32);
  v65 = *(*v10 + 16LL);
  v67 = v21 - v63;
  v68 = v23 - *(v65 + 36);
  v69 = sdfSqrt((v67 * v67) + (v68 * v68), 0);
  v16[9] = v69;
  if (v16[8] < v16[9])
  {
    v70 = *(*v7 + 16LL);
    if (*(v70 + 32) >= 13)
    {
      v71 = *(*v7 + 16LL);
      if (*(v71 + 32) <= 499)
      {
        v73 = *(*v7 + 16LL);
        if (*(v73 + 36) >= 75)
        {
          v76 = *(*v7 + 16LL);
          if (*(v76 + 36) <= 323)
          {
            SDF_VU0__LOADVECTOR(*(v15 + 2), 0);
            v39 = &"RunNumEffectKouka : CLIP 0\n";
            goto LABEL_76;
          }
        }
      }
    }
  }
  v91 = *(*v10 + 16LL);
  if (*(v91 + 32) < 13)
    goto LABEL_204;
  v92 = *(*v10 + 16LL);
  if (*(v92 + 32) > 499)
    goto LABEL_204;
  v94 = *(*v10 + 16LL);
  if (*(v94 + 36) < 75)
    goto LABEL_204;
  v97 = *(*v10 + 16LL);
  if (*(v97 + 36) > 323)
  {
LABEL_204:
    SDF_VU0__LOADVECTOR(*(v15 + 3), 0);
    SDF_VU0__LOADVECTOR_B(v136);
    SDF_VU0__SUBVECTOR();
    if (SDF_VU0__GETLENGTH() >= 1000.0)
    {
      SDF_VU0__LOADVECTOR(*(v15 + 2), 0);
      v109 = &"RunNumEffectKouka : CLIP 2-2\n";
    }
    else
    {
      sub_854710(&v136, 1u);
      sub_854930(&v136, 1u);
      SDF_VU0__LOADVECTOR(v136);
      v109 = &"RunNumEffectKouka : CLIP 2-1\n";
    }
    Write(*v109, 0);
  }
  else
  {
    SDF_VU0__LOADVECTOR(*(v15 + 3), 0);
    Write("RunNumEffectKouka : CLIP 1\n", 0);
    v134 = effBTLSkillGetTargetFormation(0);
    if (effBTLModelGetID(&v134) == 291)
    {
      sub_854710(&v136, 1u);
      sub_854930(&v136, 1u);
      SDF_VU0__LOADVECTOR(v136);
    }
  }
  v112 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v112);
  v135 = v112;
  nbScreenOffset(&v135, 0);
  v115 = v135->pm;
  v118 = v115->m_Items[0];
  if (v118 < screen_wid / -2)
    goto LABEL_255;
  v119 = v135->pm;
  v121 = v119->m_Items[0];
  if (v121 > screen_wid / 2)
    goto LABEL_255;
  v122 = v135->pm;
  v124 = v122->m_Items[1];
  if (v124 < screen_hei / -2)
    goto LABEL_255;
  v125 = v135->pm;
  v127 = v125->m_Items[1];
  if (v127 > screen_hei / 2)
  {
LABEL_255:
    v128 = &(*v133)->form;
    if (effBTLModelGetID(v128) == 343)
    {
      SDF_VU0__LOADVECTOR(*(v15 + 3), 0);
    }
    v131 = &(*v133)->form;
    if (effBTLModelGetID(v131) == 276)
    {
      v141.x = v136.x;
      v141.y = v136.y;
LABEL_257:
      v141.z = v136.z;
      v141.w = v136.w;
      goto LABEL_258;
    }
  }
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
  nbKoukaPacket_t_o **v3;
  nbKoukaPacket_t_o *v4;
  effPCPBossBUNSIN_t_o *v5;
  effPCPBossBUNSIN_t_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  effPCPBossBUNSIN2_t_o *v10;
  effPCPBossBUNSIN2_t_c *v11;
  s64 v12;
  char *v13;
  s64 *v14;
  effPCPBossONGY_t_o *v15;
  effPCPBossONGY_t_c *v16;
  s64 v17;
  char *v18;
  s64 *v19;
  effPCPBossONGY2_t_o *v20;
  effPCPBossONGY2_t_c *v21;
  s64 v22;
  char *v23;
  s64 *v24;
  effPCPBossONGY2_t_o *pPCPBossONGY2;
  effPCPBossBUNSIN_t_o *pPCPBossBUNSIN;
  u64 v27[2];
  char *v28;

  v3 = p;
  pPCPBossONGY2 = 0;
  pPCPBossBUNSIN = 0;
  v4 = *v3;
  switch ((*v3)->type)
  {
    case '\'':
      v5 = v4->data1->p;
      if (v5)
      {
        klass = v5->klass;
        if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPBossBUNSIN_t)
        {
          sub_8FC2C0(klass->_1.element_class, effPCPBossBUNSIN_t, v27);
          if ((v27[0] & 1) != 0)
            v8 = v28;
          else
            v8 = v27 + 1;
          v9 = sub_8C4940(v8);
        }
      }
      pPCPBossBUNSIN = v5;
      effPCPBossBUNSINDraw(&pPCPBossBUNSIN);
      break;
    case '(':
      v10 = v4->data1->p;
      if (v10)
      {
        v11 = v10->klass;
        if (v10->klass->_2.typeHierarchyDepth < v12
          || v11->_2.typeHierarchy[v12 - 1] != effPCPBossBUNSIN2_t)
        {
          sub_8FC2C0(v11->_1.element_class, effPCPBossBUNSIN2_t, v27);
          if ((v27[0] & 1) != 0)
            v13 = v28;
          else
            v13 = v27 + 1;
          v14 = sub_8C4940(v13);
        }
      }
      effPCPBossBUNSIN2Draw(v10);
      break;
    case ')':
      v15 = v4->data1->p;
      if (v15)
      {
        v16 = v15->klass;
        if (v15->klass->_2.typeHierarchyDepth < v17
          || v16->_2.typeHierarchy[v17 - 1] != effPCPBossONGY_t)
        {
          sub_8FC2C0(v16->_1.element_class, effPCPBossONGY_t, v27);
          if ((v27[0] & 1) != 0)
            v18 = v28;
          else
            v18 = v27 + 1;
          v19 = sub_8C4940(v18);
        }
      }
      effPCPBossONGYDraw(v15);
      break;
    case '*':
      v20 = v4->data1->p;
      if (v20)
      {
        v21 = v20->klass;
        if (v20->klass->_2.typeHierarchyDepth < v22
          || v21->_2.typeHierarchy[v22 - 1] != effPCPBossONGY2_t)
        {
          sub_8FC2C0(v21->_1.element_class, effPCPBossONGY2_t, v27);
          if ((v27[0] & 1) != 0)
            v23 = v28;
          else
            v23 = v27 + 1;
          v24 = sub_8C4940(v23);
        }
      }
      pPCPBossONGY2 = v20;
      effPCPBossONGY2Draw(&pPCPBossONGY2);
      break;
    default:
      return;
  }
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
      goto LABEL_25;
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
          goto LABEL_36;
        case 1:
        case 2:
          goto LABEL_27;
        case 4:
        case 8:
          goto LABEL_29;
        default:
          goto LABEL_23;
      }
    }
    if (v6 == 16)
      goto LABEL_27;
    if (v6 != 32)
      goto LABEL_23;
    goto LABEL_29;
  }
  if (v6 <= 128)
  {
    if (v6 != 64 && v6 != 128)
      goto LABEL_23;
    goto LABEL_29;
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
    goto LABEL_36;
  }
  if (v6 == 512)
  {
LABEL_29:
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
LABEL_36:
    nbSetWaitMotion(v19, 2, v18);
    return;
  }
  if (v6 != 1024)
  {
LABEL_23:
    v10 = Equals_5234480(v4->form->akey, "dvl0x00");
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
LABEL_25:
    nbSetDamage(p_form, f, i);
    return;
  }
LABEL_27:
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
      goto LABEL_20;
    }
    if (!v6)
    {
      v7 = v4->data1->i;
      v8 = 0;
      v9 = 0;
      v10 = 0;
LABEL_20:
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
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 i;
  datUnitWork_t_o *v10;
  UnityEngine_Object_o *modelobj;
  UnityEngine_Object_o *v14;
  struct nbFormation_t_o *v15;
  s16 v16;
  nbFormation_t_o **p_form;
  dds3Basic_t_o **p_basic;
  struct nbFormation_t_o *form;
  s32 v22;
  u32 v24;
  dds3Basic_t_o *v26;
  Il2CppObject *workdata;
  dds3UnitObjectBasicWorkData_t_c *v28;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  struct evtUnitHandle_t_o **v31;
  struct evtUnitHandle_t_o *v32;
  s64 v33;
  struct nbFormation_t_o *v34;
  struct evtUnitHandle_t_o *hunit;
  s64 v36;
  struct evtUnitHandle_t_o *v37;
  struct nbMainProcessData_t_o *data;
  dds3Basic_t_o **p_baselight;
  struct dds3Basic_t_o *baselight;
  struct nbFormation_t_o *v42;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  s64 v48;
  s64 v49;
  u16 MaxHp;
  u32 hp;
  u16 MaxMp;
  u32 mp;
  char *v56;
  s64 *v57;
  char *v58;
  s64 *v59;
  effBTLSysHandle_t_o *hEffBTLSys;
  dds3Basic_t_o *pBasic;
  s64 v62;
  s64 v63;
  u64 v64[2];
  char *v65;
  dds3Basic_t_o *unitbasic;
  UnityEngine_Vector4_o v67;
  UnityEngine_Vector4_o v68;

  v62 = 0;
  v63 = 0;
  unitbasic = 0;
  hEffBTLSys = 0;
  pBasic = 0;
  sub_854690(&v62, 0.0, 1.0, 0.0, 0.0);
  formindex = (*p)->form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  i = (*p)->data1->i;
  v10 = UnitWorkFromFormindex;
  if (i == 1)
  {
    p_form = &(*p)->form;
    v16 = 1;
    if (nbCheckLoadUnitPackFile(p_form, 1, 255, 0))
    {
      p_basic = &(*p)->form->basic;
      dds3DeleteSceneBasicData(p_basic);
      (*p)->form->basic = 0;
      (*p)->form->serial = 0;
      (*p)->form->hunit = 0;
      form = (*p)->form;
      if ((form->anime & 0x100) != 0 && form->badeff)
      {
        hEffBTLSys = form->badeff;
        effBTLSystemDelete2(&hEffBTLSys);
        (*p)->form->badeff = 0;
        form = (*p)->form;
      }
      form->stat &= ~2u;
      v22 = evtSetRegistUnit(1, 255);
      (*p)->form->stat |= 2u;
      v24 = v22;
      pBasic = dds3GetActiveScene();
      v26 = dds3SearchSceneBasic(&pBasic, v24, 5u);
      unitbasic = v26;
      workdata = v26->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v64);
        if ((v64[0] & 1) != 0)
          v56 = v65;
        else
          v56 = v64 + 1;
        v57 = sub_8C4940(v56);
      }
      LODWORD(workdata[4].klass) = 1;
      (*p)->form->basic = v26;
      v31 = v26->workdata;
      v32 = *v31;
      v33 = v28->_2.typeHierarchyDepth;
      if (LOBYTE((*v31)->ExBefore) < v33 || *(*&v32->Sin + 8 * v33 - 8) != v28)
      {
        sub_8FC2C0(*&v32->TargetLightDir.x, v28, v64);
        if ((v64[0] & 1) != 0)
          v58 = v65;
        else
          v58 = v64 + 1;
        v59 = sub_8C4940(v58);
      }
      (*p)->form->hunit = v31[4];
      (*p)->form->serial = v24;
      (*p)->form->hunit->Model->modelRoot->modelobj = (*p)->form->modelobj;
      (*p)->form->hunit->Model->Owner = v26;
      (*p)->form->hunit->Model->Owner->gameObject = (*p)->form->modelobj;
      (*p)->form->hunit->modelobj = (*p)->form->modelobj;
      v34 = (*p)->form;
      hunit = v34->hunit;
      v36 = *&v34->modelrot.x;
      *&v34 = v34->modelrot.z;
      *&hunit->modelrot.x = v36;
      LODWORD(hunit->modelrot.z) = v34;
      (*p)->form->hunit->modelanm = (*p)->form->modelanm;
      v37 = (*p)->form->hunit;
      v37->Flag |= 0x200000u;
      data = (*k)->data;
      baselight = data->baselight;
      p_baselight = &data->baselight;
      if (baselight)
        dds3LinkLightObjectToUnitObject(p_baselight, &unitbasic, 1u);
      nbSetWaitMotion(&(*p)->form, 0, 1.0, 0);
      nbSetUnitMotion(&(*p)->form, 0, 1, 1.0, 0);
      v42 = (*p)->form;
      x = v42->pos.x;
      y = v42->pos.y;
      z = v42->pos.z;
      w = v42->pos.w;
      v67.x = x;
      v67.y = y;
      v67.z = z;
      v67.w = w;
      dds3SetPosPoseSet(&unitbasic, v67);
      SDF_VU0__LOADVECTOR((*p)->form->pos, 0);
      if ((*p)->form->partyindex <= 3)
      {
        v48 = v62;
        v49 = v63;
        *&v68.x = v48;
        *&v68.z = v49;
        dds3SetRotPoseSet(&unitbasic, v68);
      }
      dds3ObjectBaseOnFlag(&unitbasic, 0x400u, 0);
      unitbasic->poseset->r = 50.0;
      (*p)->form->stat |= 0x8000u;
      v16 = 0;
      if ((v10->flag & 0x20) == 0)
      {
        MaxHp = datGetMaxHp(v10);
        hp = v10->hp;
        v10->maxhp = MaxHp;
        if (hp > MaxHp)
          v10->hp = MaxHp;
        MaxMp = datGetMaxMp(v10);
        mp = v10->mp;
        v10->maxmp = MaxMp;
        v16 = 0;
        if (mp > MaxMp)
          v10->mp = MaxMp;
      }
    }
  }
  else
  {
    if (!i)
    {
      datSetBadStat(v10, 0x200u);
      ++(*p)->data1->i;
      modelobj = (*p)->form->modelobj;
      if (op_Inequality(modelobj, 0, 0))
      {
        v14 = (*p)->form->modelobj;
        Destroy_27360000(v14);
        (*p)->form->modelobj = 0;
      }
      v15 = (*p)->form;
      v15->akey = GetAkey(255);
      (*p)->form->read_minor = 255;
    }
    v16 = 1;
  }
  (*p)->framelength = v16;
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
  nbKoukaPacket_t_o **v3;
  u32 i;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppObject *v11;
  u64 v12[3];

  v3 = p;
  v11 = 0;
  i = (*v3)->data1->i;
  if (i <= 0xA && i != 3)
  {
    v6 = (*v3)->data2->p;
    if (v6)
    {
      klass = v6->klass;
      if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBTLSysHandle_t)
      {
        sub_8FC2C0(klass->_1.element_class, effBTLSysHandle_t, v12);
        if ((v12[0] & 1) != 0)
          v9 = v12[2];
        else
          v9 = v12 + 1;
        v10 = sub_8C4940(v9);
      }
    }
    v11 = (*v3)->data2->p;
    effBTLSystemDraw(&v11);
  }
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
  u64 *v4;
  nbKoukaPacket_t_o *v6;
  s32 i;
  nbFormation_t_o *form;
  nbFormation_t_o *v9;
  u32 v10;
  s32 framelength;
  nbKoukaPacket_t_o *v14;
  struct System_Int32_array *pm;
  u32 max_length;
  s32 v19;
  s32 v21;
  struct System_Int16_array *s;
  s32 formindex;
  s32 v25;
  UnityEngine_GameObject_o *HitNum;
  nbKoukaPacket_t_o *v28;
  f32 v29;
  f32 v30;
  f32 v31;
  UnityEngine_Transform_o *transform;
  s64 *v33;
  f32 v35;
  f32 v36;
  UnityEngine_Transform_o *v37;
  UnityEngine_Component_o *v38;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v40;
  UnityEngine_Component_o *v41;
  UnityEngine_GameObject_o *v42;
  s64 *achievementTbl;
  System_String_o *v46;
  UnityEngine_Transform_o *v47;
  System_String_o *v48;
  UnityEngine_Component_o *v49;
  UnityEngine_GameObject_o *v50;
  UnityEngine_Transform_o *v51;
  UnityEngine_Component_o *v52;
  UnityEngine_GameObject_o *v53;
  UnityEngine_Component_o *v54;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_Component_o *v56;
  UnityEngine_GUILayer_o *v57;
  u64 v58;
  f32 value;
  sdfIVector4_t_o *pos;
  UnityEngine_Vector4_o v61;
  UnityEngine_Color_o v62;
  UnityEngine_Vector3_o v63;

  value = 0.0;
  v58 = 0;
  v4 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v4);
  pos = v4;
  v6 = *p;
  if (!(*p)->time)
  {
    i = v6->data1->i;
    if (i)
    {
      if ((i - 1) <= 3)
      {
        form = v6->form;
        nbGetFormTop(form);
      }
    }
    else
    {
      v9 = v6->form;
      nbGetFormSphereTop(v9);
    }
    NumEffectClip(p);
    SDF_VU0__LOADVECTOR_B((*p)->form->pos, 0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__STOREVECTOR(&(*p)->v, 0);
    v6 = *p;
  }
  v10 = -2139062144;
  if ((v6->data1->i - 1) <= 3 && v6->time >= 0x10u)
  {
    framelength = v6->framelength;
    if (framelength <= 6)
      v10 = (352321536 * framelength) | 0x808080;
  }
  v61 = SDF_VU0__Retdds3ColorItoF(v10, 128.0);
  nbPnl_rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  nbPnl_rsetAlpha(0);
  SDF_VU0__LOADVECTOR((*p)->v, 0);
  SDF_VU0__LOADVECTOR_B((*p)->form->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__VECTOR_W_SET_ZERO();
  v14 = *p;
  if (nbScreenOffset(&pos, v14))
  {
    pm = pos->pm;
    max_length = pm->max_length;
    v19 = pm->m_Items[0];
    v21 = pos->pm->m_Items[1];
    s = (*p)->data1->s;
    formindex = (*p)->form->formindex;
    v25 = s->m_Items[0];
    HitNum = GetHitNum(formindex, v25);
    if (!op_Equality(HitNum, 0, 0))
    {
      v28 = *p;
      v29 = v19;
      v30 = v21;
      switch ((*p)->data1->i)
      {
        case 0:
          v31 = 38.0;
          transform = get_transform(HitNum, 0);
          v33 = &"talk";
          goto LABEL_52;
        case 1:
          v35 = v30 + 18.0;
          v36 = (2 * v28->time);
          v37 = get_transform(HitNum, 0);
          v38 = Find(v37, "weakpoint", 0);
          gameObject = get_gameObject(v38);
          if (!get_activeSelf(gameObject))
          {
            v40 = get_transform(HitNum, 0);
            v41 = Find(v40, "weakpoint", 0);
            v42 = get_gameObject(v41);
            SetActive(v42, 1, 0);
            if ((*p)->form->partyindex >= 4)
            {
              if (++SystemWork->WeakCount >= 100)
              {
                achievementTbl = get_achievementTbl();
                v46 = sub_B7950(0xEu, DefineAchievementID_string_, achievementTbl);
                Unlock_16599376(v46);
              }
            }
          }
          v30 = v35 + v36;
          v47 = get_transform(HitNum, 0);
          v48 = "weakpoint";
          goto LABEL_55;
        case 2:
          v30 = v30 + 19.0;
          v31 = (2 * v28->time);
          transform = get_transform(HitNum, 0);
          v33 = &"critical";
          goto LABEL_52;
        case 3:
          v30 = v30 + 18.0;
          v31 = (2 * v28->time);
          transform = get_transform(HitNum, 0);
          v33 = &"miss";
          goto LABEL_52;
        case 4:
          v30 = v30 + 17.0;
          v31 = (2 * v28->time);
          transform = get_transform(HitNum, 0);
          v33 = &"block";
LABEL_52:
          v49 = Find(transform, *v33, 0);
          v50 = get_gameObject(v49);
          if (!get_activeSelf(v50))
          {
            v51 = get_transform(HitNum, 0);
            v52 = Find(v51, *v33, 0);
            v53 = get_gameObject(v52);
            SetActive(v53, 1, 0);
          }
          v30 = v30 + v31;
          v47 = get_transform(HitNum, 0);
          v48 = *v33;
LABEL_55:
          v54 = Find(v47, v48, 0);
          Component_GUILayer = GetComponent_GUILayer_(v54);
          v62 = op_Implicit_27186336(v61);
          (Component_GUILayer->klass[1].vtable._0_Equals.method)(
            Component_GUILayer,
            Component_GUILayer->klass[1].vtable._1_Finalize.methodPtr,
            v62.r,
            v62.g,
            v62.b,
            v62.a);
          break;
        default:
          break;
      }
      v56 = get_transform(HitNum, 0);
      v57 = GetComponent_GUILayer_(v56);
      sub_8524C0(&v58, 0.0, 0.0, 0.0);
      v63.z = value;
      v63.x = v29;
      v63.y = v30;
      v58 = __PAIR64__(LODWORD(v30), LODWORD(v29));
      set_localPosition(v57, v63);
    }
  }
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
      goto LABEL_18;
    }
    if (!s->m_Items[1])
    {
      v13 = (*p)->data1->s;
      f = (*p)->data2->f;
      i = v13->m_Items[0];
      p_form = &(*p)->form;
      goto LABEL_13;
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
LABEL_18:
      nbSetUnitMotion(p_form, i, v8, f);
      return;
    }
LABEL_13:
    v8 = 0;
    goto LABEL_18;
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
  u64 *v5;
  nbKoukaPacket_t_o *v7;
  s64 i;
  s64 v9;
  u32 v10;
  u32 v11;
  s32 framelength;
  s32 v13;
  nbFormation_t_o *form;
  nbKoukaPacket_t_o *v17;
  nbKoukaPacket_t_o *v19;
  u32 v20;
  u32 v21;
  struct System_Int32_array *v22;
  u32 v23;
  s32 v25;
  s32 v27;
  s32 v28;
  nbFormation_t_o *v29;
  sdfTexHandle_t_o *v30;
  struct System_Int32_array *v31;
  u32 v32;
  s32 v34;
  u32 v36;
  struct System_Int32_array *pm;
  sdfTexHandle_t_o *hPnlTex3;
  u32 max_length;
  s32 v41;
  s32 v43;
  s32 time;
  nbFormation_t_o *v45;
  struct System_Int16_array *s;
  s32 v48;
  nbFormation_t_o *v49;
  nbFormation_t_o *v50;
  s32 formindex;
  s64 *achievementTbl;
  System_String_o *v54;
  sdfTexHandle_t_o *tex;
  sdfIVector4_t_o *pos;

  v5 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v5);
  pos = v5;
  v7 = *p;
  if ((*p)->time)
  {
    i = v7->data1->i;
    if (i <= 5)
      goto LABEL_5;
  }
  else
  {
    form = v7->form;
    nbGetFormTop(form);
    NumEffectClip(p);
    SDF_VU0__LOADVECTOR_B((*p)->form->pos, 0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__STOREVECTOR(&(*p)->v, 0);
    v7 = *p;
    i = (*p)->data1->i;
    if (i <= 5)
    {
LABEL_5:
      v9 = 4 * i;
      v10 = *(&unk_3444230 + v9);
      v11 = *(&unk_3444248 + v9);
      if (v7->time < 0x10u)
        goto LABEL_13;
      goto LABEL_6;
    }
  }
  v10 = 0;
  v11 = 0;
  if (v7->time < 0x10u)
    goto LABEL_13;
LABEL_6:
  framelength = v7->framelength;
  if (framelength <= 6)
  {
    v13 = 352321536 * framelength;
    v11 = v13 | v11 & 0xB0B0B0;
    v10 = v13 | v10 & 0x80B0A0;
  }
LABEL_13:
  SDF_VU0__LOADVECTOR(v7->v);
  SDF_VU0__LOADVECTOR_B((*p)->form->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__VECTOR_W_SET_ZERO();
  v17 = *p;
  if (nbScreenOffset(&pos, v17))
  {
    v19 = *p;
    v20 = (*p)->data1->i;
    if (v20 < 4)
    {
      v36 = v19->data2->i;
      pm = pos->pm;
      hPnlTex3 = (*k)->data->hPnlTex3;
      max_length = pm->max_length;
      v41 = pm->m_Items[0];
      v43 = pos->pm->m_Items[1];
      time = (*p)->time;
      v45 = (*p)->form;
      s = (*p)->data1->s;
      v48 = s->m_Items[0];
      nbDrawNumber(hPnlTex3, v36, v41, v43 + 2 * time, v11, 0, v45, v48);
    }
    else if ((v20 & 0xFFFFFFFE) == 4)
    {
      v21 = v19->data2->i;
      v22 = pos->pm;
      v23 = v22->max_length;
      tex = (*k)->data->hPnlTex3;
      v25 = v22->m_Items[0];
      v27 = pos->pm->m_Items[1];
      v28 = (*p)->time;
      v29 = (*p)->form;
      nbDrawNumber(tex, v21, v25, v27 + 2 * v28 + 24, v11, -1, v29, 0);
      v30 = (*k)->data->hPnlTex3;
      v31 = pos->pm;
      v32 = v31->max_length;
      v34 = v31->m_Items[0];
      nbDrawNumber(
        v30,
        (*p)->partyno,
        v34,
        pos->pm->m_Items[1] + 2 * (*p)->time,
        v10,
        1,
        (*p)->form,
        1,
        0);
    }
    v49 = effBTLSkillGetInvokeFormation(0);
    if ((*p)->time == 1 && (*p)->data2->i >= 0x3E7u)
    {
      v50 = v49;
      if (nbCheckFormationPlayerSide(v49->formindex))
      {
        if (((*p)->data1->i | 4) == 4)
        {
          formindex = v50->formindex;
          nbGetUnitWorkFromFormindex(formindex);
          achievementTbl = get_achievementTbl();
          v54 = sub_B7950(0xFu, DefineAchievementID_string_, achievementTbl);
          Unlock_16599376(v54);
        }
      }
    }
  }
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
  struct nbParty_t_array *party;
  s64 partyno;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *form;
  struct nbParty_t_array *v10;
  s64 v11;
  s64 formindex;
  nbFormation_t_o *v15;
  s32 type;
  s64 v19;
  evtUnitHandle_t_o **p_hunit;
  f32 w;
  f32 z;
  s32 i;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o orgrot;
  UnityEngine_Vector4_o v27;

  *&v25.x = 0;
  *&v25.z = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  sub_854690(&v25.x, 0.0, 0.0, -1.0, 0.0);
  sub_854690(&v24.x, 0.0, 0.0, 0.0, 0.0);
  party = (*k)->data->party;
  partyno = (*p)->partyno;
  if ((party->m_Items[partyno]->flag & 1) != 0)
  {
    data = (*k)->data;
    form = data->form;
    v10 = data->party;
    v11 = (*p)->partyno;
    formindex = v10->m_Items[v11]->formindex;
    v15 = form->m_Items[formindex];
    type = (*p)->type;
    if (type == 4)
    {
      orgrot = v15->orgrot;
      v15->stat &= ~0x20u;
      SDF_VU0__LOADVECTOR(orgrot);
      ToMatrix();
      SDF_VU0__LOADIDENTITYVECTOR();
      SDF_VU0__SETVECTOR_Z(1.0);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__STOREVECTOR(&v24);
    }
    else if (type == 3)
    {
      v15->stat |= 0x20u;
      SDF_VU0__COPYVECTOR(&v24, (*p)->v, 0);
    }
    SDF_VU0__LOADVECTOR(v25);
    SDF_VU0__LOADVECTOR_B(v24);
    dds3RotationArc();
    SDF_VU0__STOREVECTOR(&v24);
    v19 = *&v24.x;
    p_hunit = &v15->hunit;
    z = v24.z;
    w = v24.w;
    i = (*p)->data1->i;
    *&v27.x = v19;
    v27.z = z;
    v27.w = w;
    evtSetUnitRot1(p_hunit, v27, i);
  }
}

// 0x1977170
void RunSakeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  nbSetSake(&(*p)->form, (*p)->data1->f, (*p)->data2->f, 0);
}

// 0x19795e0
void RunSeKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  s32 i;
  struct nbMainProcessData_t_o *data;
  s64 *v9;
  struct nbMainProcessData_t_o *v10;
  s64 *v13;
  s32 type;
  System_Object_array *v15;
  s64 *v16;
  s64 *v17;
  s32 v21;

  i = (*p)->data1->i;
  data = (*k)->data;
  if ((i & 0xFFFFFFFE) == 0x10008 && data->d31_rebehansya != 0)
  {
    data->d31_rebehansya = 0;
    if (evtBitCheck(3712))
    {
      v9 = &"D192M_MSEC0_10";
    }
    else
    {
      v9 = &"D192R_MSEC0_10";
    }
    p2sdSndStop_20178672(*v9);
  }
  v10 = (*k)->data;
  if (i == 65544 && v10->d31_andahansya != 0)
  {
    v10->d31_andahansya = 0;
    if (evtBitCheck(3712))
    {
      v13 = &"D192M_MSEC0_16";
    }
    else
    {
      v13 = &"D192R_MSEC0_16";
    }
    p2sdSndStop_20178672(*v13);
  }
  type = (*p)->type;
  if (type == 29)
  {
LABEL_34:
    p2sdPlaySE(i);
    return;
  }
  if (type != 28)
  {
    if (type != 25)
      return;
    goto LABEL_34;
  }
  v21 = i;
  v15 = NewSpecific(object, 1u);
  v16 = sub_8D3950(uint, &v21);
  v17 = v16;
  v15->m_Items[0] = v17;
  dds3Printf("se2 [%08X] play!\n", v15);
  p2sdPlaySE(i);
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
  nbKoukaPacket_t_o *v4;
  effBTLCutHandle_t_o **p_cuteff;
  s32 type;
  s32 v7;
  nbKoukaPacket_t_o *v9;
  Il2CppObject *v10;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  struct System_Int16_array *s;
  u32 max_length;
  u16 v17;
  nbFormation_t_o *form;
  u32 v20;
  Il2CppObject *v22;
  u64 v23[3];

  v22 = 0;
  v4 = *p;
  p_cuteff = &(*p)->cuteff;
  if (*p_cuteff)
  {
    type = v4->type;
    v7 = v4->type;
    if (type <= 21)
    {
      if (v7 && v7 != 21)
        return;
      goto LABEL_27;
    }
    if (v7 != 26)
    {
      if (v7 != 43)
        return;
LABEL_27:
      effBTLCutDraw(p_cuteff);
      return;
    }
    effBTLSystemCut1Draw(p_cuteff);
  }
  else
  {
    Write("cutcreate 3\n", 0);
    v9 = *p;
    v10 = (*p)->data1->p;
    if (v10)
    {
      klass = v10->klass;
      if (v10->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effBTL_t)
      {
        sub_8FC2C0(klass->_1.element_class, effBTL_t, v23);
        if ((v23[0] & 1) != 0)
          v13 = v23[2];
        else
          v13 = v23 + 1;
        v14 = sub_8C4940(v13);
      }
    }
    v22 = (*p)->data1->p;
    s = v9->data2->s;
    max_length = s->max_length;
    v17 = s->m_Items[0];
    form = v9->form;
    v20 = v9->data2->s->m_Items[1];
    v9->cuteff = effBTLCutCreate(&v22, v17, form, v20);
  }
}

// 0x197a600
void RunSkillNameKouka(nbKoukaProcessData_t **k, nbKoukaPacket_t **p) {
  s32 i;
  s32 v5;

  i = (*p)->data1->i;
  else
  {
    v5 = i;
  }
  nbDispSkillName(v5, p);
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
LABEL_30:
    v20 = (*p)->data2->s;
    v21 = v20->m_Items[0];
    nbAddOrder(v21);
    return;
  }
  v18 = *k;
  p_data = &v18->data;
  nbSetPartyFormation(p_data, 0x100u);
  if (((*k)->data->stat & 8) == 0)
    goto LABEL_30;
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
        goto LABEL_7;
      case 6:
      case 8:
        p_i = &form->modelcol;
LABEL_7:
        v9 = *p_i;
        i = v4->data1->i;
        if (v7 >= 2)
          goto LABEL_8;
        goto LABEL_15;
      default:
        i = 0;
        v9 = 0;
        if (v7 >= 2)
        {
LABEL_8:
          if ((type - 7) < 2)
          {
            p_hunit = &form->hunit;
            evtSetUnitColorA(p_hunit, i, v9);
          }
        }
        else
        {
LABEL_15:
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
      goto LABEL_9;
    goto LABEL_8;
  }
  last = v13->last;
  p_last = &v13->last;
  v15 = last;
  if (last)
  {
LABEL_8:
    v15->next = v9;
    v9[5] = (*k)->last;
    p_last = &(*k)->last;
  }
LABEL_9:
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
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *data;
  s32 name_low;
  bool v14;
  u32 v15;
  s32 v16;
  bool v17;
  char *v19;
  s64 *v20;
  dds3ProcessID_t_o *KoukaProcessID;
  u64 v22[3];

  KoukaProcessID = 0;
  KoukaProcessID = nbGetMainProcessData()->KoukaProcessID;
  ProcessData = dds3GetProcessData(&KoukaProcessID);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v22);
    if ((v22[0] & 1) != 0)
      v19 = v22[2];
    else
      v19 = v22 + 1;
    v20 = sub_8C4940(v19);
  }
  data = ProcessData[2].klass;
  if (!data)
    return 0;
  while (1)
  {
    name_low = SLOWORD(data->_1.name);
    v14 = name_low <= start && start - frame < name_low;
    if (v14)
    {
      v15 = BYTE4(data->_1.name);
      v14 = v15 > 0x1D;
      v16 = (1 << v15) & 0x32000000;
      v17 = v14 || v16 == 0;
      if (!v17 && LODWORD(data->_1.parent->_1.byval_arg.data) == se)
        break;
    }
    data = data->_1.byval_arg.data;
    if (!data)
      return 0;
  }
  return 1;
}

// 0x1974350
void nbDecodePackData(void *p, s32 major, s32 minor) {
  ;
}

// 0x1975580
void nbDelAllKoukaPacketType(s32 type) {
  nbMainProcessData_t_o *MainProcessData;
  dds3ProcessID_t_o **p_KoukaProcessID;
  Il2CppObject *ProcessData;
  nbKoukaProcessData_t_c *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  nbKoukaPacket_t_o *next;
  s32 v11;
  char *v13;
  s64 *v14;
  nbKoukaPacket_t_o *v15;
  u64 v16[3];

  v15 = 0;
  else
  {
    MainProcessData = nbGetMainProcessData(nbMainProcess);
    if (!MainProcessData->KoukaProcessID)
      return;
  }
  p_KoukaProcessID = &MainProcessData->KoukaProcessID;
  ProcessData = dds3GetProcessData(p_KoukaProcessID);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v16);
    if ((v16[0] & 1) != 0)
      v13 = v16[2];
    else
      v13 = v16 + 1;
    v14 = sub_8C4940(v13);
  }
  next = ProcessData[2].klass;
  while (1)
  {
    v15 = next;
    if (!next)
      break;
    v11 = next->type;
    next = next->next;
    if (v11 == type)
      nbDelKoukaPacket(&v15, v7);
  }
}

// 0x1971430
void nbDelAllMojiNumEffectKoukaPacket(nbFormation_t **form, s32 motno) {
  nbMainProcessData_t_o *MainProcessData;
  dds3ProcessID_t_o **p_KoukaProcessID;
  Il2CppObject *ProcessData;
  nbKoukaProcessData_t_c *v10;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  nbKoukaPacket_t_o *next;
  nbKoukaPacket_t_o *v14;
  s32 type;
  struct nbKoukaData_t_o *data1;
  s32 i;
  struct System_Int16_array *v19;
  s32 v20;
  s32 v21;
  struct System_Int16_array *s;
  s32 formindex;
  s32 v24;
  UnityEngine_GameObject_o *HitNum;
  u32 v27;
  s32 v32;
  s32 v33;
  char *v37;
  s64 *v38;
  nbKoukaPacket_t_o *v39;
  u64 v40[3];

  v39 = 0;
  else
  {
    MainProcessData = nbGetMainProcessData(nbMainProcess);
    if (!MainProcessData->KoukaProcessID)
      return;
  }
  p_KoukaProcessID = &MainProcessData->KoukaProcessID;
  ProcessData = dds3GetProcessData(p_KoukaProcessID);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v40);
    if ((v40[0] & 1) != 0)
      v37 = v40[2];
    else
      v37 = v40 + 1;
    v38 = sub_8C4940(v37);
  }
  next = ProcessData[2].klass;
  v39 = next;
  if (next)
  {
    while (1)
    {
      v14 = next;
      next = next->next;
      type = v14->type;
      if (type != 22 && type != 16)
        goto LABEL_50;
      data1 = v14->data1;
      i = data1->i;
      if (motno == 3)
        break;
      if (i != 5)
      {
        s = data1->s;
        formindex = v14->form->formindex;
        v24 = s->m_Items[0];
        v32 = formindex;
        v33 = v24;
        goto LABEL_48;
      }
LABEL_49:
      if (v14->form == *form)
      {
        nbDelKoukaPacket(&v39, v10);
        v39 = next;
        if (!next)
          return;
      }
      else
      {
LABEL_50:
        v39 = next;
        if (!next)
          return;
      }
    }
    if ((i & 0xFFFFFFFE) == 2)
    {
      v19 = data1->s;
      v20 = v14->form->formindex;
      v21 = v19->m_Items[0];
      HitNum = GetHitNum(v20, v21);
      SetActive(HitNum, 0, 0);
      i = v14->data1->i;
    }
    if (i != 5)
      goto LABEL_49;
    v27 = v14->form->formindex;
    else if ((byte_3F5AB5A & 1) != 0)
    {
      goto LABEL_40;
    }
    goto LABEL_40;
  }
}

// 0x1975400
void nbDelAllUniqueIDKoukaPacket(s32 uniqueid) {
  nbMainProcessData_t_o *MainProcessData;
  dds3ProcessID_t_o **p_KoukaProcessID;
  Il2CppObject *ProcessData;
  nbKoukaProcessData_t_c *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  nbKoukaPacket_t_o *next;
  s32 v11;
  char *v13;
  s64 *v14;
  nbKoukaPacket_t_o *v15;
  u64 v16[3];

  v15 = 0;
  else
  {
    MainProcessData = nbGetMainProcessData(nbMainProcess);
    if (!MainProcessData->KoukaProcessID)
      return;
  }
  p_KoukaProcessID = &MainProcessData->KoukaProcessID;
  ProcessData = dds3GetProcessData(p_KoukaProcessID);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v16);
    if ((v16[0] & 1) != 0)
      v13 = v16[2];
    else
      v13 = v16 + 1;
    v14 = sub_8C4940(v13);
  }
  next = ProcessData[2].klass;
  while (1)
  {
    v15 = next;
    if (!next)
      break;
    v11 = next->uniqueid;
    next = next->next;
    if (v11 == uniqueid)
      nbDelKoukaPacket(&v15, v7);
  }
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
          goto LABEL_21;
        }
        v6 = *v2;
        first = next;
      }
    }
    else
    {
LABEL_21:
      v16 = v6->data1->s;
      formindex = v6->form->formindex;
      v19 = v16->m_Items[0];
      HitNum = GetHitNum(formindex, v19);
      SetActive(HitNum, 0, 0);
      transform = get_transform(HitNum, 0);
      v22 = Find(transform, "num_damage", 0);
      gameObject = get_gameObject(v22);
      SetActive(gameObject, 0, 0);
      v24 = get_transform(HitNum, 0);
      v25 = Find(v24, "critical", 0);
      v26 = get_gameObject(v25);
      SetActive(v26, 0, 0);
      v27 = get_transform(HitNum, 0);
      v28 = Find(v27, "weakpoint", 0);
      v29 = get_gameObject(v28);
      SetActive(v29, 0, 0);
      v30 = get_transform(HitNum, 0);
      v31 = Find(v30, "miss", 0);
      v32 = get_gameObject(v31);
      SetActive(v32, 0, 0);
      v33 = get_transform(HitNum, 0);
      v34 = Find(v33, "block", 0);
      v35 = get_gameObject(v34);
      SetActive(v35, 0, 0);
      v36 = get_transform(HitNum, 0);
      v37 = Find(v36, "talk", 0);
      v38 = get_gameObject(v37);
      SetActive(v38, 0, 0);
    }
  }
  k = nbGetKoukaProcessData(KoukaProcessData);
  DelKoukaPacket(&k, v2);
}

// 0x1975700
void nbDelUnEventKoukaPacket(void) {
  nbMainProcessData_t_o *MainProcessData;
  dds3ProcessID_t_o **p_KoukaProcessID;
  Il2CppObject *ProcessData;
  nbKoukaProcessData_t_c *v6;
  Il2CppObject *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  nbKoukaPacket_t_o *next;
  nbKoukaPacket_t_o *v13;
  s32 type;
  s32 v15;
  Il2CppClass *v16;
  nbKoukaPacket_t_o *v18[3];
  nbKoukaPacket_t_o *p;

  p = 0;
  else
  {
    MainProcessData = nbGetMainProcessData(nbMainProcess);
    if (!MainProcessData->KoukaProcessID)
      return;
  }
  p_KoukaProcessID = &MainProcessData->KoukaProcessID;
  ProcessData = dds3GetProcessData(p_KoukaProcessID);
  v7 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v18);
      if ((v18[0] & 1) != 0)
        v10 = v18[2];
      else
        v10 = v18 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  next = ProcessData[2].klass;
  p = next;
  if (next)
  {
    while (1)
    {
      v13 = next;
      next = next->next;
      type = v13->type;
      if (type <= 25)
      {
        if (type == 11)
        {
          nbReturnUnit(v13->party->partyindex, 0, v13->data1->i);
          v16 = v7[1].klass;
          if (HIDWORD(v16->_1.castClass) == 271)
            HIDWORD(v16->_1.klass) |= 0x2000u;
          goto LABEL_29;
        }
        v15 = v13->type;
        if (v15 == 14)
        {
          else
          {
            effBTLSkillEnd();
            p = next;
            if (!next)
              return;
          }
        }
        else
        {
          if (v15 != 25)
            goto LABEL_29;
LABEL_21:
          p = next;
          if (!next)
            return;
        }
      }
      else
      {
        if (type == 36 || type <= 0x30 && ((1LL << type) & 0x1800030000000LL) != 0)
          goto LABEL_21;
LABEL_29:
        nbDelKoukaPacket(&p, v6);
        p = next;
        if (!next)
          return;
      }
    }
  }
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
  nbKoukaProcessData_t_o *result;
  nbKoukaProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  dds3ProcessID_t_o *v7[3];
  dds3ProcessID_t_o *id;

  id = 0;
  id = dds3SearchProcessName("nb_kouka");
  result = dds3GetProcessData(&id);
  if (result)
  {
    klass = result->klass;
    if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v7);
      if ((v7[0] & 1) != 0)
        v5 = v7[2];
      else
        v5 = v7 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  return result;
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
  target = dds3StartProcess("nb_kouka", 0x2B08u, 1, 1, v4, 0, v5, 0, v3, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->KoukaProcessID = target;
}

// 0x197aa00
void *nbKoukaProcess1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  nbKoukaProcessData_t_c *v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  nbKoukaPacket_t_o *next;
  u32 v11;
  nbKoukaPacket_t_o *v12;
  Il2CppClass *v13;
  s32 i;
  nbKoukaPacket_t_o *v18;
  s32 AgeOfMoon16;
  s32 v24;
  struct nbFormation_t_o *form;
  s32 startframe;
  bool v28;
  s32 v29;
  nbKoukaPacket_t_o *p;
  nbKoukaProcessData_t_o *k;
  dds3ProcessID_t_o *ida;
  effBTLSysHandle_t_o *hEffBTLSys[3];

  ida = id;
  k = 0;
  p = 0;
  ProcessData = dds3GetProcessData(&ida);
  v5 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, hEffBTLSys);
      if ((hEffBTLSys[0] & 1) != 0)
        v8 = hEffBTLSys[2];
      else
        v8 = hEffBTLSys + 1;
      v9 = sub_8C4940(v8);
    }
  }
  next = ProcessData[2].klass;
  p = next;
  k = ProcessData;
  if (next)
  {
    v11 = 22762;
    while (1)
    {
      v18 = next;
      next = next->next;
      if (v18->type <= 0x37 && ((1LL << v18->type) & 0xA428630C3037E1LL) != 0)
      {
        form = v18->form;
        if (form)
        {
          if ((form->flag & 7) != 0)
            goto LABEL_143;
        }
      }
      startframe = v18->startframe;
      v28 = __OFSUB__(startframe, 1);
      v29 = startframe - 1;
      if (v29 < 0 == v28)
        break;
      if (v18->framelength < 0)
      {
        nbDelKoukaPacket(&p, v3);
        p = next;
        if (!next)
          return 0;
      }
      else if ((v18->flag & 2) != 0)
      {
LABEL_143:
        p = next;
        if (!next)
          return 0;
      }
      else
      {
        switch (v18->type)
        {
          case 0:
          case 0x15:
          case 0x1A:
          case 0x2B:
            RunSkillEffectKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 1:
          case 2:
            RunMoveKouka(&k, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 3:
          case 4:
            RunRotKouka(&k, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 5:
          case 6:
          case 7:
          case 8:
            RunUnitColKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 9:
          case 0xA:
          case 0x25:
          case 0x35:
            RunDamageMotionKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0xB:
            nbReturnUnit(v18->party->partyindex, 0, v18->data1->i);
            v13 = v5[1].klass;
            if (HIDWORD(v13->_1.castClass) != 271)
              goto LABEL_129;
            HIDWORD(v13->_1.klass) |= 0x2000u;
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0xC:
            RunSummonKouka(&k, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0xD:
            nbSetSake(&v18->form, v18->data1->f, v18->data2->f);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0xE:
          case 0x36:
            RunSkillColorKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0xF:
            RunHitEffectKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x10:
            RunNumEffectKouka(&k, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x11:
            if ((BYTE6(v5[1].klass->_1.klass) & 2) != 0)
              goto LABEL_129;
            nbAddHpMp(v18->form->formindex, v18->data1->i, v18->data2->i);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x12:
          case 0x1F:
            RunPressKouka(&k, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x13:
            nbSetBadStat(v18->form->formindex, v18->data1->i, v18->data2->i);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x14:
            RunBadMotKaifukuKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x16:
            RunMojiEffectKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x17:
            RunBadEffKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x18:
            AgeOfMoon16 = evtGetAgeOfMoon16();
            v24 = AgeOfMoon16 + 17;
            if (AgeOfMoon16 + 2 >= 0)
              v24 = AgeOfMoon16 + 2;
            evtSetAgeOfMoon(AgeOfMoon16 + 2 - (v24 & 0xFFFFFFF0), 0);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x34:
            RunPadShockKouka(ProcessData, &p);
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x38:
            nbPanelStockFadeOUT();
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x39:
            nbPanelStockEnd();
            v12 = p;
            if ((p->flag & 1) == 0)
              goto LABEL_130;
            break;
          case 0x3A:
            RunHatudoEffectEndKouka(&k, &p);
            goto LABEL_129;
          default:
LABEL_129:
            v12 = p;
            if ((p->flag & 1) == 0)
LABEL_130:
              --v12->framelength;
            break;
        }
        ++v12->time;
        p = next;
        if (!next)
          return 0;
      }
    }
    v18->startframe = v29;
    goto LABEL_143;
  }
  return 0;
}

// 0x197b290
void *nbKoukaShutdown(dds3ProcessID_t *id) {
  nbKoukaProcessData_t_o *ProcessData;
  nbKoukaProcessData_t_o *v4;
  nbKoukaProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbKoukaProcessData_t_o *k;
  dds3ProcessID_t_o *ida;
  u64 v13[3];

  ida = id;
  k = 0;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v13);
      if ((v13[0] & 1) != 0)
        v7 = v13[2];
      else
        v7 = v13 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  k = ProcessData;
  if (ProcessData->first)
  {
    DelKoukaPacket(&k, &ProcessData->first);
    while (v4->first)
      DelKoukaPacket(&k, &v4->first);
  }
  v4->data->KoukaProcessID = 0;
  return 0;
}

// 0x1974340
s32 nbLoadSound(s32 id) {
  return 0;
}

// 0x1975970
void nbOnOffKoukaPacketFlag(s32 type, u32 flg, s32 sw) {
  char v5;
  nbMainProcessData_t_o *MainProcessData;
  dds3ProcessID_t_o **p_KoukaProcessID;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v13;
  Il2CppClass *data;
  Il2CppClass *v16;
  char *v17;
  s64 *v18;
  u64 v19[3];

  v5 = flg;
  else
  {
    MainProcessData = nbGetMainProcessData(nbMainProcess);
    if (!MainProcessData->KoukaProcessID)
      return;
  }
  p_KoukaProcessID = &MainProcessData->KoukaProcessID;
  ProcessData = dds3GetProcessData(p_KoukaProcessID);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v19);
    if ((v19[0] & 1) != 0)
      v17 = v19[2];
    else
      v17 = v19 + 1;
    v18 = sub_8C4940(v17);
  }
  v13 = ProcessData[2].klass;
  if (v13)
  {
    if (sw)
    {
      do
      {
        data = v13->_1.byval_arg.data;
        if (SBYTE4(v13->_1.name) == type)
          BYTE5(v13->_1.name) |= v5;
        v13 = data;
      }
      while (data);
    }
    else
    {
      do
      {
        v16 = v13->_1.byval_arg.data;
        if (SBYTE4(v13->_1.name) == type)
          BYTE5(v13->_1.name) &= ~v5;
        v13 = v16;
      }
      while (v16);
    }
  }
}
