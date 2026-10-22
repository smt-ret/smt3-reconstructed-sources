#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLSysHandle_t effBTLSysHandle_t;
typedef struct effBTL_t effBTL_t;
typedef struct nbActionStack_t nbActionStack_t;
typedef struct nbCameraState_Start_t nbCameraState_Start_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbKoukaProcessData_t nbKoukaProcessData_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbMainProcess_NBMCLEAR_PHASE nbMainProcess_NBMCLEAR_PHASE;
typedef struct nbMainProcess_NBMSETUP_PHASE nbMainProcess_NBMSETUP_PHASE;
typedef struct nbMainProcess_UILoadTable nbMainProcess_UILoadTable;
typedef struct nbParty_t nbParty_t;

struct nbMainProcess_UILoadTable {
    s32 preload;
    s32 ui_index;
    char *akey;
    char *folder;
    char *prefab;
};

struct nbMainProcess_NBMSETUP_PHASE {
    s32 value__;
};

struct nbMainProcess_NBMCLEAR_PHASE {
    s32 value__;
};

static char *nbDebugCamera_freename;
static char *nbDebugCamera_gamename;
static s32 nbDebugCamera_draw;
static char *nbDebugMainProcess_seq[23];
static char *nbDebugMainProcess_acttype[6];
static void *stopwatch;
static void *stopwatch2;
static f32 oldtime;
static f32 dead_voice_waitmax;
static f32 dead_voice_time;
static s32 SubPhase;
static void *unitAB_List;
static s32 nbUnloadTime;
static s32 nbmsetup_phase;
static void *oTargetMark2D;
static void *oHitNum;
static void *oBattle_UI;
static void *oBattle_UI_PreLoad;
static char *SKILLSE_AKEY;
static s32 nbmclear_phase;
static nbMainProcess_UILoadTable *battleUIprefab[8];

void BattleUIDelete(void);
void BattleUIRead(void);
s32 CheckActionProcessEnd(nbMainProcessData_t *data);
s32 CheckErrorActionStack(nbMainProcessData_t *data, s32 index);
void CheckSenseiOrBackAttack(nbMainProcessData_t *data);
void ClearLocalBit(void);
void ClrDrawFlag(u32 flag);
bool DDS3_PAD2CHECK_TRIG(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void FilterDelete(void);
u8 Get(s32 id);
void *GetBattleUI(s32 index);
void InitShadow(dds3DefaultMain *this);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void LoadBattleLocalizeText(void);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void RemoveBattleLocalizeText(void);
void RemoveKeys(s32 type, char *key);
void SetBoostFrameRate(dds3DefaultMain *this);
void SetDebugFlag(nbMainProcessData_t *data);
void SetDrawFlag(u32 flag, u32 cnt);
void SetFlag(nbMainProcessData_t *data);
void SetNormalFrameRate(dds3DefaultMain *this);
void SobedClear(void);
void StageLoad_BlockMode(bool mode);
void UnloadAB(AssetBundleCtrl *this, char *key);
u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
void datSetAutoKaifukuSkill(datUnitWork_t *work, s32 skill);
void datUnitWork_t__Clear(datUnitWork_t *this);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void effBTLDelete(effBTL_t **hBTLEffect);
void effBTLSystemDelete2(effBTLSysHandle_t **hEffBTLSys);
s32 encChk(void);
void encMode(s32 mode);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtDeadMoonFree(void);
void evtDeadMoonInit(void);
void evtDisableMoonDraw(void);
void evtEnableMoonDraw(void);
void evtSetAgeOfMoon(s32 age);
s32 itfMesMngInitialize(void *presource, char **master_text, char *key);
void itfMesMngRelease(s32 id);
void nbActionStack_t__Clear(nbActionStack_t *this);
nbKoukaPacket_t *nbAddDeadPcmPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
void nbAddKagututiMoon(nbMainProcessData_t *data);
nbKoukaPacket_t *nbAddPadShockPacket(s32 startframe, s32 uniqueid, s32 mode, s32 pow, s32 time);
void nbBgmFadeOut(void);
void nbCameraCRSetPlayerFormRequest(void);
s32 nbCameraPressProcessCheckRun(void);
s32 nbCameraPressProcessGetFrame(void);
void nbCameraPressProcessInit(void);
void nbCameraPressProcessThrough(void);
void nbCameraSetState(u16 state);
void nbCameraState_Start_t__Clear(nbCameraState_Start_t *this);
void nbCamera_t__Clear(nbCamera_t *this);
s32 nbCheckActionStack(void);
s32 nbCheckBackAttack(nbMainProcessData_t *data);
s32 nbCheckBadKaifuku(datUnitWork_t *work, s32 type);
s32 nbCheckBadStatusGameOver(nbMainProcessData_t *data);
s32 nbCheckRenzokuEncount(nbMainProcessData_t *data);
s32 nbCheckSensei(nbMainProcessData_t *data);
void nbClearCommandMemeoyRenzoku(void);
void nbDelUnEventKoukaPacket(void);
void nbDispMsgHelp(s32 msgid, s32 no, s32 msgtype);
void nbFormDispOff(s32 formindex);
void nbFormatFormation(nbMainProcessData_t **data, s32 index);
void nbFreeFlyUnitPack(nbMainProcessData_t **data);
void nbFreeSound(nbMainProcessData_t *data);
s32 nbGetActionSeq(dds3ProcessID_t *id);
void nbGetEncountTableItem(nbMainProcessData_t *data);
s32 nbGetJyokyoMes(nbMainProcessData_t *data, s32 jyokyomes);
nbKoukaProcessData_t *nbGetKoukaProcessData(void);
nbMainProcessData_t *nbGetMainProcessData(void);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
s32 nbGetStageStat(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
void nbInitActionProcess(nbMainProcessData_t **data, s32 type, s32 from, s32 to, s32 d);
void nbInitAtoProcess(nbMainProcessData_t *data);
void nbInitAutoCommProcess(nbMainProcessData_t *data);
void nbInitCameraProcess(nbMainProcessData_t **data);
void nbInitDebugProcess(nbMainProcessData_t **data);
void nbInitEffectProcess(nbMainProcessData_t **data);
void nbInitEncProcess(nbMainProcessData_t *data);
void nbInitEventProcess(nbMainProcessData_t *data);
void nbInitHelpProcess(nbMainProcessData_t *data);
void nbInitKoukaProcess(nbMainProcessData_t *data);
void nbInitMaeProcess(nbMainProcessData_t **data);
void *nbInitMainProcessData(void);
dds3ProcessID_t *nbInitMakaProcess(dds3ProcessID_t *parent);
void nbInitPanelProcess(nbMainProcessData_t *data);
void nbInitResultProcess(nbMainProcessData_t *data);
void nbInitSound(nbMainProcessData_t *data);
void nbInitStageProcess(nbMainProcessData_t **data);
void nbInitTarSelProcess(nbMainProcessData_t *data);
void nbInitUnitProcess(nbMainProcessData_t **data);
void nbMainProcessClear(void);
void nbMainProcessData_t__Clear(nbMainProcessData_t *this);
bool nbMainProcessSetUp(void);
s32 nbMakeBadKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
void nbNoDestroy_MoveCache_Field_B(void *modelobj);
void nbNoDestroy_MoveCache_Party(void *modelobj);
void nbPackEmptyFormation(nbMainProcessData_t **data);
void nbPanelPressGaugeEncountHide(void);
void nbPanelPressGaugeStart(void);
void nbPanelPressTurnOmit(void);
void nbPanelPressTurnStart(void);
void nbPanelStockHide(void);
s32 nbPopAction(nbActionStack_t **act);
void nbPushAction(s32 type, s32 from, s32 to, s32 d);
void nbResetTurnSetAnimKeepState(void);
void nbSetActionMaePhase(nbMainProcessData_t *data);
void nbSetActionPhase(nbMainProcessData_t *data);
void nbSetAtoPhase(nbMainProcessData_t *data);
void nbSetChkEndPhase(nbMainProcessData_t *data);
void nbSetChkTurnPhase(nbMainProcessData_t *data);
void nbSetDebugPhase(nbMainProcessData_t *data);
void nbSetEndPhase(nbMainProcessData_t *data);
void nbSetEnemyStartData_0(nbMainProcessData_t *data, s32 enc);
void nbSetEnemyStartData_1(nbMainProcessData_t *data, s32 enc);
void nbSetHojoCounter(s32 formindex, s32 type, s32 point);
void nbSetMaePhase(nbMainProcessData_t *data);
void nbSetNextOrder(void);
void nbSetOrder(void);
void nbSetPhase(s32 phase);
void nbSetPlayerStartData(nbMainProcessData_t *data);
void nbSetPressMaePhase(nbMainProcessData_t *data);
void nbSetResultPhase(nbMainProcessData_t *data);
void nbTurnPBInitSetting(void);
void nbUpdateSoundTable(nbMainProcessData_t *data);
bool p2sdStatusSE_Dead(void);
s8 rstChkResultEntry(void);

// 0x1982b90
void BattleUIDelete(void) {
  s64 v2;
  s16 v4;
  u64 v5;
  s32 i;
  struct nbMainProcess_UILoadTable_array *battleUIprefab;
  u64 max_length_low;
  struct UnityEngine_GameObject_array *oBattle_UI;
  struct UnityEngine_GameObject_array *v13;
  UnityEngine_Object_o *v15;
  struct UnityEngine_GameObject_array *v17;
  UnityEngine_Object_o *v19;
  struct UnityEngine_GameObject_array *v20;

  v2 = 4;
  v5 = 0;
  if ((v4 & 0x200) != 0)
    goto LABEL_7;
LABEL_6:
  for (i = 0; ; i = v4 & 0x200)
  {
    max_length_low = LODWORD(battleUIprefab->max_length);
    if (v5 >= max_length_low)
      break;
    else if (v5 >= max_length_low)
    {
      goto LABEL_14;
    }
    if (*(*(&battleUIprefab->obj.klass + v2) + 16LL))
    {
      SetActive(*(&oBattle_UI->obj.klass + v2), 0, 0);
LABEL_40:
      v20 = oBattle_UI;
      *(&v20->obj.klass + v2) = 0;
      goto LABEL_5;
    }
    v13 = oBattle_UI;
    v15 = *(&v13->obj.klass + v2);
    if (op_Inequality(v15, 0, 0))
    {
      v17 = oBattle_UI;
      v19 = *(&v17->obj.klass + v2);
      Destroy_27360000(v19);
      goto LABEL_40;
    }
LABEL_5:
    ++v2;
    v5 = v2 - 4;
    if ((v4 & 0x200) == 0)
      goto LABEL_6;
LABEL_7:
  }
  oBattle_UI = 0;
}

// 0x1982e10
void BattleUIPreRead(void) {
  struct UnityEngine_GameObject_array *v4;
  nbMainProcess_c *v5;
  u64 v6;
  struct nbMainProcess_UILoadTable_array *battleUIprefab;
  u64 max_length_low;
  nbMainProcess_UILoadTable_o *v10;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  struct UnityEngine_GameObject_array *oBattle_UI_PreLoad;
  s64 ui_index;
  UnityEngine_GameObject_o *v17;
  UnityEngine_Transform_o *transform;
  s64 *v20;
  s64 *v21;
  struct UnityEngine_GameObject_array *v23;
  s64 v24;
  struct UnityEngine_GameObject_array *v26;
  s64 v27;

  v4 = NewSpecific(UnityEngine_GameObject, LODWORD(battleUIprefab->max_length));
  oBattle_UI_PreLoad = v4;
  v6 = 0;
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
  while (1)
  {
    max_length_low = LODWORD(battleUIprefab->max_length);
    if (v6 >= max_length_low)
      break;
    else if (v6 >= max_length_low)
    {
      goto LABEL_15;
    }
    v10 = battleUIprefab->m_Items[v6];
    if (v10->preload == 1)
    {
      asset_bc = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, v10->akey, v10->folder, v10->prefab);
      ui_index = v10->ui_index;
      v17 = Find("Canvas_UI", 0);
      transform = get_transform(v17, 0);
      v20 = Instantiate_object__425664(Prefab_16624656, transform, 0);
      v21 = v20;
      oBattle_UI_PreLoad->m_Items[ui_index] = v21;
      v23 = oBattle_UI_PreLoad;
      v24 = v10->ui_index;
      SetActive(v23->m_Items[v24], 0, 0);
      v26 = oBattle_UI_PreLoad;
      v27 = v10->ui_index;
      AddComponent_object_(v26->m_Items[v27]);
    }
    ++v6;
      goto LABEL_9;
  }
}

// 0x19823a0
void BattleUIRead(void) {
  struct UnityEngine_GameObject_array *v4;
  nbMainProcess_c *v5;
  u64 v6;
  struct nbMainProcess_UILoadTable_array *battleUIprefab;
  u64 max_length_low;
  nbMainProcess_UILoadTable_o *v10;
  struct UnityEngine_GameObject_array *oBattle_UI_PreLoad;
  struct UnityEngine_GameObject_array *oBattle_UI;
  s64 ui_index;
  s64 *v17;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  struct UnityEngine_GameObject_array *v23;
  s64 v24;
  UnityEngine_GameObject_o *v25;
  UnityEngine_Transform_o *transform;
  s64 *v28;
  s64 *v29;
  struct UnityEngine_GameObject_array *v31;
  s64 v32;
  struct UnityEngine_GameObject_array *v34;
  s64 v35;

  v4 = NewSpecific(UnityEngine_GameObject, LODWORD(battleUIprefab->max_length));
  oBattle_UI = v4;
  v6 = 0;
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
  while (1)
  {
    max_length_low = LODWORD(battleUIprefab->max_length);
    if (v6 >= max_length_low)
      break;
    else if (v6 >= max_length_low)
    {
      goto LABEL_15;
    }
    v10 = battleUIprefab->m_Items[v6];
    if (v10->preload)
    {
      ui_index = v10->ui_index;
      v17 = oBattle_UI_PreLoad->m_Items[ui_index];
      oBattle_UI->m_Items[ui_index] = v17;
    }
    else
    {
      asset_bc = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, v10->akey, v10->folder, v10->prefab);
      v23 = oBattle_UI;
      v24 = v10->ui_index;
      v25 = Find("Canvas_UI", 0);
      transform = get_transform(v25, 0);
      v28 = Instantiate_object__425664(Prefab_16624656, transform, 0);
      v29 = v28;
      v23->m_Items[v24] = v29;
      v31 = oBattle_UI;
      v32 = v10->ui_index;
      SetActive(v31->m_Items[v32], 0, 0);
      v34 = oBattle_UI;
      v35 = v10->ui_index;
      AddComponent_object_(v34->m_Items[v35]);
    }
    ++v6;
      goto LABEL_9;
  }
}

// 0x197e3d0
s32 CheckActionProcessEnd(nbMainProcessData_t *data) {
  struct dds3ProcessID_t_array *ActionProcessID;
  struct dds3ProcessID_t_array *v3;
  struct dds3ProcessID_t_array *v4;
  struct dds3ProcessID_t_array *v6;

  ActionProcessID = data->ActionProcessID;
  if (ActionProcessID->m_Items[0])
    return 0;
  v3 = data->ActionProcessID;
  if (v3->m_Items[1])
    return 0;
  v4 = data->ActionProcessID;
  if (v4->m_Items[2])
    return 0;
  v6 = data->ActionProcessID;
  return v6->m_Items[3] == 0;
}

// 0x197e5c0
s32 CheckActionRun(nbMainProcessData_t *data) {
  s64 i;
  struct nbFormation_t_array *form;
  u64 v4;
  struct nbFormation_t_array *v6;

  for (i = 4; ; ++i)
  {
    form = data->form;
    v4 = i - 4;
    if ((*(*(&form->obj.klass + i) + 136LL) & 1) != 0)
    {
      v6 = data->form;
      if ((*(*(&v6->obj.klass + i) + 140LL) & 7) != 0)
        break;
    }
    if (v4 >= 0xF)
      return 1;
  }
  return 0;
}

// 0x197e860
s32 CheckErrorActionStack(nbMainProcessData_t *data, s32 index) {
  struct nbActionStack_t_array *actionstack;
  struct nbParty_t_array *party;
  s64 to;
  struct nbActionStack_t_array *v10;
  struct nbParty_t_array *v11;
  s64 v13;
  struct nbActionStack_t_array *v15;
  struct nbActionStack_t_array *v17;
  struct nbActionStack_t_array *v19;
  struct nbParty_t_array *v20;
  s64 from;
  nbParty_t_o *v24;
  u16 badstatus;
  u32 v26;
  s32 result;

  actionstack = data->actionstack;
  party = data->party;
  to = actionstack->m_Items[index]->to;
  if ((party->m_Items[to]->flag & 1) == 0)
    return 1;
  v10 = data->actionstack;
  v11 = data->party;
  v13 = v10->m_Items[index]->to;
  if ((v11->m_Items[v13]->flag & 0x20) != 0)
    return 1;
  if (data->endtype)
  {
    v15 = data->actionstack;
    if (v15->m_Items[index]->type != 5)
      return 1;
  }
  v17 = data->actionstack;
  if (v17->m_Items[index]->type != 4)
    return 0;
  v19 = data->actionstack;
  v20 = data->party;
  from = v19->m_Items[index]->from;
  v24 = v20->m_Items[from];
  badstatus = nbGetUnitWorkPointer(data, v24)->badstatus;
  v26 = badstatus & 0xFFF;
  if (v26 > 0x10)
  {
    result = 1;
    if (v26 == 128 || v26 == 256 || v26 == 1024)
      return result;
    return 0;
  }
  if (v26 - 1 < 2)
    return 1;
  result = 1;
  if ((badstatus & 0xFFF) != 4 && (badstatus & 0xFFF) != 0x10)
    return 0;
  return result;
}

// 0x197e4b0
void CheckSenseiOrBackAttack(nbMainProcessData_t *data) {
  u32 stat;
  signed s32 v5;

  if (nbCheckSensei(data) && !evtBitCheck(3082))
  {
    data->stat |= 0x80u;
    if (nbCheckBackAttack(data))
    {
      data->stat |= 0x10u;
      Write("backattack!!\n", 0);
    }
    data->stat |= 8u;
  }
  stat = data->stat;
  v5 = stat & 0xFFFFFF67 | 0x88;
  if ((stat & 0x8000) == 0)
    v5 = data->stat;
  if (v5 < 0 || (stat & 0x8000) != 0)
  {
    if (v5 < 0)
      v5 |= 0x98u;
    data->stat = v5;
  }
}

// 0x1981380
void ClearLocalBit(void) {
  evtBitOff(3056);
  evtBitOff(3057);
  evtBitOff(3058);
  evtBitOff(3059);
  evtBitOff(3060);
  evtBitOff(3061);
  evtBitOff(3062);
  evtBitOff(3063);
  evtBitOff(3064);
  evtBitOff(3065);
  evtBitOff(3066);
  evtBitOff(3067);
  evtBitOff(3068);
  evtBitOff(3069);
  evtBitOff(3070);
  evtBitOff(3071);
}

// 0x197e3c0
void DebugDisp2(nbMainProcessData_t *data) {
  ;
}

// 0x1981300
void FreeJyocyuData(nbMainProcessData_t *data) {
  effBTL_t_o **p_HatudoEff;

  p_HatudoEff = &data->HatudoEff;
  effBTLDelete(p_HatudoEff);
  *p_HatudoEff = 0;
}

// 0x1973210
void *GetBattleUI(s32 index) {
  struct UnityEngine_GameObject_array *oBattle_UI;
  s64 v5;

  if (!oBattle_UI)
    return 0;
LABEL_6:
  else
  {
    v5 = index;
    if (LODWORD(oBattle_UI->max_length) <= index)
      goto LABEL_9;
  }
  return oBattle_UI->m_Items[v5];
}

// 0x1975100
void *GetHitNum(s32 idx, s32 copyNumber) {
  struct System_Collections_Generic_List_GameObject__array *oHitNum;
  struct System_Collections_Generic_List_GameObject__array *v10;
  Il2CppObject *object;
  Il2CppObject *v14;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v16;
  UnityEngine_Transform_o *parent;
  UnityEngine_Transform_o *v18;
  UnityEngine_Transform_o *v19;
  UnityEngine_Transform_o *v20;
  UnityEngine_Transform_o *v21;
  struct System_Collections_Generic_List_GameObject__array *v22;
  struct System_Collections_Generic_List_GameObject__array *v25;
  struct System_Collections_Generic_List_GameObject__array *v28;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o localScale;

  if (copyNumber)
  {
    if (_get_Count(oHitNum->m_Items[idx]) <= copyNumber)
    {
      v10 = oHitNum;
      object = First_object_(v10->m_Items[idx]);
      v14 = Instantiate_object_(object);
      transform = get_transform(v14, 0);
      v16 = get_transform(object, 0);
      parent = get_parent(v16);
      SetParent(transform, parent);
      v18 = get_transform(v14, 0);
      v19 = get_transform(object, 0);
      localPosition = get_localPosition(v19);
      set_localPosition(v18, localPosition);
      v20 = get_transform(v14, 0);
      v21 = get_transform(object, 0);
      localScale = get_localScale(v21);
      set_localScale(v20, localScale);
      v22 = oHitNum;
      _Add(v22->m_Items[idx], v14);
    }
    v25 = oHitNum;
    return _get_Item(
             v25->m_Items[idx],
             copyNumber);
  }
  else
  {
    v28 = oHitNum;
    return First_object_(v28->m_Items[idx]);
  }
}

// 0x1982900
void *GetHitNumList(s32 idx, s32 copyNumber) {
  struct System_Collections_Generic_List_GameObject__array *oHitNum;

  return oHitNum->m_Items[idx];
}

// 0x1982740
void *GetTargetMark2D(s32 idx) {
  struct UnityEngine_GameObject_array *oTargetMark2D;
  s64 v5;

  if (!oTargetMark2D)
    return 0;
LABEL_6:
  else
  {
    v5 = idx;
    if (LODWORD(oTargetMark2D->max_length) <= idx)
      goto LABEL_9;
  }
  return oTargetMark2D->m_Items[v5];
}

// 0x19829a0
void SetActiveToAllHitNum(s32 idx, bool bActive) {
  _BOOL4 v3;
  struct System_Collections_Generic_List_GameObject__array *oHitNum;
  UnityEngine_GameObject_o *v9;
  System_Collections_Generic_List_Enumerator_T__o v10;

  v3 = bActive;
  memset(&v10, 0, sizeof(v10));
  __GetEnumerator(&v10, oHitNum->m_Items[idx]);
  while ((sub_1A11200(&v10) & 1) != 0)
  {
    v9 = sub_1A11350(&v10);
    if (!op_Equality(v9, 0, 0) && ((get_activeSelf(v9) ^ v3) & 1) != 0)
      SetActive(v9, v3, 0);
  }
  nullsub_111(&v10);
}

// 0x197e670
void SetBattleFlag(nbMainProcessData_t *data) {
  s32 encno;

  encno = data->encno;
  if ((Get(encno, 0)->flag & 1) != 0)
    data->stat |= 1u;
}

// 0x19816d0
void SetDebugFlag(nbMainProcessData_t *data) {
  bool v3;
  u32 stat;
  u32 v5;
  s32 v6;
  bool v7;
  u32 v8;
  u32 v9;
  u32 v10;
  bool v11;
  u32 v12;
  u32 v13;
  u32 v14;
  bool v15;
  u32 v16;
  u32 v17;
  u32 v18;
  bool v19;
  u32 v20;
  u32 v21;
  u32 v22;
  bool v23;
  u32 v24;
  u32 v25;
  u32 v26;
  bool v27;
  u32 v28;
  u32 v29;
  u32 v30;
  bool v31;
  u32 v32;
  u32 v33;
  u32 v34;
  bool v35;
  u32 v36;
  u32 v37;
  u32 v38;
  bool v39;
  u32 v40;
  s32 v41;
  u32 v42;
  bool v43;
  u32 v44;
  u32 v45;
  u32 v46;

  v3 = evtBitCheck(3076);
  stat = data->stat;
  v5 = stat & 0xFE7FFFFF;
  v6 = stat | 0x800000;
  if (!v3)
    v6 = v5;
  data->stat = v6 | 0x1000000;
  v7 = evtBitCheck(3072);
  v8 = data->stat;
  v9 = v8 & 0xFFFDFFFF;
  v10 = v8 | 0x20000;
  if (!v7)
    v10 = v9;
  data->stat = v10;
  v11 = evtBitCheck(3073);
  v12 = data->stat;
  v13 = v12 & 0xFFFEFFFF;
  v14 = v12 | 0x10000;
  if (!v11)
    v14 = v13;
  data->stat = v14;
  v15 = evtBitCheck(3074);
  v16 = data->stat;
  v17 = v16 & 0xFFFBFFFF;
  v18 = v16 | 0x40000;
  if (!v15)
    v18 = v17;
  data->stat = v18;
  v19 = evtBitCheck(3075);
  v20 = data->stat;
  v21 = v20 & 0xFFBFFFFF;
  v22 = v20 | 0x400000;
  if (!v19)
    v22 = v21;
  data->stat = v22;
  v23 = evtBitCheck(3077);
  v24 = data->stat;
  v25 = v24 & 0xFDFFFFFF;
  v26 = v24 | 0x2000000;
  if (!v23)
    v26 = v25;
  data->stat = v26;
  v27 = evtBitCheck(3078);
  v28 = data->stat;
  v29 = v28 & 0xFBFFFFFF;
  v30 = v28 | 0x4000000;
  if (!v27)
    v30 = v29;
  data->stat = v30;
  v31 = evtBitCheck(3079);
  v32 = data->stat;
  v33 = v32 & 0xF7FFFFFF;
  v34 = v32 | 0x8000000;
  if (!v31)
    v34 = v33;
  data->stat = v34;
  v35 = evtBitCheck(3085);
  v36 = data->stat;
  v37 = v36 & 0xBFFFFFFF;
  v38 = v36 | 0x40000000;
  if (!v35)
    v38 = v37;
  data->stat = v38;
  v39 = evtBitCheck(3088);
  v40 = data->stat;
  v41 = v40 & 0x7FFFFFFF;
  v42 = v40 | 0x80000000;
  if (!v39)
    v42 = v41;
  data->stat = v42;
  v43 = evtBitCheck(3090);
  v44 = data->stat;
  v45 = v44 & 0xFFFF7FFF;
  v46 = v44 | 0x8000;
  if (!v43)
    v46 = v45;
  data->stat = v46;
}

// 0x197bc90
void SetDummy(nbMainProcessData_t *data) {
  ;
}

// 0x1982210
void SetFlag(nbMainProcessData_t *data) {
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  s32 v9;
  s32 encno;
  s32 packindex;
  s32 packno;
  s32 encpackno;

  encpackno = data->encpackno;
  v4 = sub_8D3950(s32, &encpackno);
  Write_2930400("encpackno = {0:D}\n", v4);
  packno = data->packno;
  v5 = sub_8D3950(s32, &packno);
  Write_2930400("packno = {0:D}\n", v5);
  packindex = data->packindex;
  v6 = sub_8D3950(s32, &packindex);
  Write_2930400("packindex = {0:D}\n", v6);
  encno = data->encno;
  v7 = sub_8D3950(s32, &encno);
  Write_2930400("encno = {0:D}\n", v7);
  v9 = data->encno;
  if (v9 == 199)
    data->stat |= 0x400u;
  if ((Get(v9, 0)->flag & 8) != 0)
    data->stat |= 0x800u;
}

// 0x19812f0
void SetJyocyuData(nbMainProcessData_t *data) {
  ;
}

// 0x1982840
void TargetMark2DAnim(s32 idx) {
  struct UnityEngine_GameObject_array *oTargetMark2D;
  Il2CppObject *Component_object;

  Component_object = GetComponent_object_(oTargetMark2D->m_Items[idx]);
  Play_8766576(Component_object, "bcursur_chara");
}

// 0x197bc80
void fileSyncAll(void) {
  ;
}

// 0x197ec70
s32 nbCheckActionStack(void) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v5;
  s32 v6;

  MainProcessData = nbGetMainProcessData();
  if (MainProcessData->actionstackp < 1)
    return 0;
LABEL_6:
  v5 = MainProcessData;
  v6 = 0;
  while (1)
  {
    if (!CheckErrorActionStack(v5, v6))
      break;
    if (++v6 >= v5->actionstackp)
      return 0;
  }
  Write("ありますよ!!\n", 0);
  return 1;
}

// 0x197ed90
void nbClearActionStack(void) {
  nbGetMainProcessData()->actionstackp = 0;
}

// 0x197e3a0
void nbDebugCamera(nbMainProcessData_t *data) {
  ;
}

// 0x197e3b0
void nbDebugMainProcess(nbMainProcessData_t *data) {
  ;
}

// 0x197dfc0
void nbDebugSelect(nbMainProcessData_t *data) {
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v11;

  if (DDS3_PADCHECK_TRIG(8))
LABEL_6:
    data->stat ^= 0x100000u;
LABEL_7:
  if (DDS3_PAD2CHECK_TRIG(3))
LABEL_10:
    data->debug = (data->debug & 1) == 0;
LABEL_11:
  if ((data->stat & 8) != 0 && evtBitCheck(3089))
  {
    if (!dds3GetRandIntA(5u, ""))
    {
      form = data->form;
      nbAddDeadPcmPacket(0, 0, &form->m_Items[2]);
      nbAddPadShockPacket(0, 0, 1, 150, 20);
    }
    if (!dds3GetRandIntA(5u, ""))
    {
      v11 = data->form;
      nbAddDeadPcmPacket(0, 0, &v11->m_Items[2]);
      nbAddPadShockPacket(0, 0, 1, 150, 20);
    }
  }
}

// 0x196dad0
nbMainProcessData_t *nbGetMainProcessData(void) {
  nbMainProcessData_t_o *result;
  nbMainProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3ProcessID_t_o *v8[3];
  dds3ProcessID_t_o *id;

  id = 0;
  result = dds3SearchProcessPriority(1018);
  id = result;
  if (result)
  {
    else
    {
      result = dds3GetProcessData(&id);
      if (!result)
        return result;
    }
    klass = result->klass;
    if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbMainProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbMainProcessData_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  return result;
}

// 0x197dde0
nbParty_t *nbGetPartyFromFormindex(s32 formindex) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v7;
  struct nbParty_t_array *party;
  u32 partyindex;

  if (formindex > 15)
    return 0;
  MainProcessData = nbGetMainProcessData();
  form = MainProcessData->form;
  v7 = form->m_Items[formindex];
  if ((~v7->stat & 0x41) != 0)
    return 0;
  party = MainProcessData->party;
  partyindex = v7->partyindex;
  return party->m_Items[partyindex];
}

// 0x197def0
u32 nbGetSelectBit(nbMainProcessData_t *data) {
  u64 v2;
  u32 v3;
  struct nbFormation_t_array *form;
  s32 stat_low;
  s32 v7;

  v2 = 0;
  v3 = 0;
  do
  {
    form = data->form;
    stat_low = LOBYTE(form->m_Items[v2]->stat);
    v7 = 1 << v2++;
    v3 |= v7 & (stat_low << 28 >> 31);
  }
  while (v2 != 16);
  return v3;
}

// 0x196d810
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex) {
  nbMainProcessData_t_o *MainProcessData;
  datUnitWork_t_o *result;
  nbParty_t_o *v9;
  s64 v11;
  struct datUnitWork_t_array *unitwork;

  if (formindex >= 16)
  {
    v11 = formindex - 16LL;
    unitwork = DDS3_GBWK->unitwork;
    return unitwork->m_Items[v11];
  }
  else
  {
    MainProcessData = nbGetMainProcessData();
    result = nbGetPartyFromFormindex(formindex);
    if (result)
    {
      v9 = result;
      if ((result->flag & 1) != 0)
      {
        return nbGetUnitWorkPointer(MainProcessData, v9);
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}

// 0x197dcf0
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party) {
  s16 flag;
  struct datUnitWork_t_array *enemyunit;
  s64 statindex;

  flag = party->flag;
  if ((flag & 1) == 0)
    return 0;
  if ((flag & 2) != 0)
  {
    enemyunit = data->enemyunit;
  }
  else
  {
    if ((flag & 4) != 0)
      return 0;
    enemyunit = DDS3_GBWK->unitwork;
  }
  statindex = party->statindex;
  return enemyunit->m_Items[statindex];
}

// 0x19739e0
void nbInitMainProcess(s32 encpackno, s32 packno, s32 packindex, s32 encno, s32 stagemajor, s32 stageminor) {
  s16 v7;
  s16 v8;
  u64 *v15;
  u64 *v18;
  u64 *v21;
  u64 *v24;
  Il2CppObject *inited;
  nbMainProcessData_t_o *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v34;
  s64 *v35;
  u64 *v37;
  u64 *v38;
  u64 *v39;
  u64 *v40;
  u64 *v41;
  s32 v43;
  u64 *v46;
  u64 *v47;
  s32 formationtype;
  s32 v52;
  u64 v53[3];
  s32 v54;
  s32 v55;

  v7 = stageminor;
  v8 = stagemajor;
  SetDrawFlag(0x20000000u, 1u);
  SetDrawFlag(0x40000000u, 1u);
  SetBoostFrameRate(kernelObject);
  v15 = Allocate(nbStageProcessData_t);
  nbStageProcessData_t___ctor(v15);
  StageData = v15;
  v18 = Allocate(nbCamera_t);
  nbCamera_t___ctor(v18);
  nbCameraCurrent = v18;
  nbCamera_t__Clear(nbCameraCurrent);
  nbCameraCurrent->fovy = 0.69813;
  v21 = Allocate(nbCameraState_Start_t);
  nbCameraState_Start_t___ctor(v21);
  nbCameraState_Start_Camera = v21;
  nbCameraState_Start_t__Clear(nbCameraState_Start_Camera);
  v24 = Allocate(nbCamera_t);
  nbCamera_t___ctor(v24);
  nbCameraStateEndComPos = v24;
  nbCamera_t__Clear(nbCameraStateEndComPos);
  _Clear(unitAB_List);
  inited = nbInitMainProcessData();
  data = inited;
  if (inited)
  {
    klass = inited->klass;
    if (inited->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbMainProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbMainProcessData_t, v53);
      if ((v53[0] & 1) != 0)
        v34 = v53[2];
      else
        v34 = v53 + 1;
      v35 = sub_8C4940(v34);
    }
  }
  LODWORD(inited[4].klass) = encpackno;
  HIDWORD(inited[4].klass) = packno;
  LODWORD(inited[4].monitor) = packindex;
  HIDWORD(inited[4].monitor) = encno;
  data->formationtype = Get(encno, 0)->formationtype;
  LODWORD(v53[0]) = data->encpackno;
  v37 = sub_8D3950(s32, v53);
  Write_2930400("encpackno = {0:D}\n", v37);
  v55 = data->packno;
  v38 = sub_8D3950(s32, &v55);
  Write_2930400("packno = {0:D}\n", v38);
  v54 = data->packindex;
  v39 = sub_8D3950(s32, &v54);
  Write_2930400("packindex = {0:D}\n", v39);
  v52 = data->encno;
  v40 = sub_8D3950(s32, &v52);
  Write_2930400("encno = {0:D}\n", v40);
  formationtype = data->formationtype;
  v41 = sub_8D3950(s32, &formationtype);
  Write_2930400("formationtype = {0:D}\n", v41);
  v43 = data->encno;
  data->StageMajor = v8;
  data->StageMinor = v7;
  if (v43 == 473)
  {
    evtSetAgeOfMoon(0);
  }
  SetFlag(data);
  ClearLocalBit();
  nbmsetup_phase = 0;
  nbmclear_phase = 0;
  nbUnloadTime = 0;
  v46 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v46,
    0,
    Method_nbMainProcess_nbMainProcess1__);
  v47 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v47,
    0,
    Method_nbMainProcess_nbMainShutdown__);
  data->MainProcessID = dds3StartProcess(
                                 "nb_main",
                                 0x3FAu,
                                 1,
                                 1,
                                 v46,
                                 0,
                                 v47,
                                 0,
                                 data,
                                 0);
  evtEnableMoonDraw();
  if (data->encno == 451)
  {
    evtDeadMoonInit();
    evtSetAgeOfMoon(1);
  }
}

// 0x1981880
void *nbInitMainProcessData(void) {
  u64 *v1;
  u32 *v2;
  u32 *v3;
  u64 i;
  u64 *v5;
  s32 j;
  u32 *v11;
  u32 *v12;
  s64 k;
  u64 v14;
  u64 *v15;
  u64 v17;
  u32 *v20;
  u32 *v21;
  u64 m;
  u64 *v23;
  u64 n;
  u64 v27;
  u64 v29;
  u64 *v31;
  u64 *v32;
  u64 *v33;
  u64 v35;
  u64 *v36;
  u64 v38;
  u64 *v39;
  u64 v41;
  u64 *v42;
  u64 v44;
  u64 *v45;
  u64 *v47;
  u64 *v48;
  u64 v50;
  u64 *v51;
  u64 v53;
  u64 *v54;
  u64 v55;
  u64 v56;
  u64 v58;
  u64 v60;
  u64 v62;
  u64 v64;
  u64 v66;
  u64 v68;
  Il2CppObject *tbl;
  nbMainProcessData_t_o *data;

  v1 = Allocate(nbMainProcessData_t);
  nbMainProcessData_t___ctor(v1);
  data = v1;
  nbMainProcessData_t__Clear(v1);
  v2 = NewSpecific(nbFormation_t, 0x20u);
  v1[2] = v2;
  v3 = v2;
  for (i = 0; ; ++i)
  {
    v5 = Allocate(nbFormation_t);
    nbFormation_t___ctor(v5);
    *&v3[2 * i + 8] = v5;
    if (i == 31)
      break;
    v3 = v1[2];
  }
  for (j = 0; j != 32; ++j)
  {
    nbFormatFormation(&data, j);
  }
  v11 = NewSpecific(datUnitWork_t, 0xAu);
  v1[3] = v11;
  v12 = v11;
  for (k = 4; ; ++k)
  {
    v14 = k - 4;
    v15 = Allocate(datUnitWork_t);
    datUnitWork_t___ctor(v15);
    *&v12[2 * k] = v15;
    v17 = v1[3];
    datUnitWork_t__Clear(*(v17 + 8 * k), 0);
    if (k == 13)
      break;
    v12 = v1[3];
  }
  v20 = NewSpecific(nbParty_t, 0xEu);
  v1[4] = v20;
  v21 = v20;
  for (m = 0; ; ++m)
  {
    v23 = Allocate(nbParty_t);
    nbParty_t___ctor(v23);
    *&v21[2 * m + 8] = v23;
    if (m == 13)
      break;
    v21 = v1[4];
  }
  for (n = 0; n != 14; ++n)
  {
    v27 = v1[4];
    *(*(v27 + 8 * n + 32) + 16LL) = 0;
    v29 = v1[4];
    *(*(v29 + 8 * n + 32) + 22LL) = n;
  }
  v31 = NewSpecific(nbActionStack_t, 8u);
  v1[11] = v31;
  v32 = v31;
  v33 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v33);
  v32[4] = v33;
  v35 = v1[11];
  v36 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v36);
  *(v35 + 40) = v36;
  v38 = v1[11];
  v39 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v39);
  *(v38 + 48) = v39;
  v41 = v1[11];
  v42 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v42);
  *(v41 + 56) = v42;
  v44 = v1[11];
  v45 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v45);
  *(v44 + 64) = v45;
  v47 = v1[11];
  v48 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v48);
  v47[9] = v48;
  v50 = v1[11];
  v51 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v51);
  *(v50 + 80) = v51;
  v53 = v1[11];
  v54 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v54);
  *(v53 + 88) = v54;
  v55 = v1[11];
  nbActionStack_t__Clear(*(v55 + 32), 0);
  v56 = v1[11];
  nbActionStack_t__Clear(*(v56 + 40), 0);
  v58 = v1[11];
  nbActionStack_t__Clear(*(v58 + 48), 0);
  v60 = v1[11];
  nbActionStack_t__Clear(*(v60 + 56), 0);
  v62 = v1[11];
  nbActionStack_t__Clear(*(v62 + 64), 0);
  v64 = v1[11];
  nbActionStack_t__Clear(*(v64 + 72), 0);
  v66 = v1[11];
  nbActionStack_t__Clear(*(v66 + 80), 0);
  v68 = v1[11];
  nbActionStack_t__Clear(*(v68 + 88), 0);
  *(v1 + 24) = 0;
  nbInitSound(v1);
  *(v1 + 22) = -1;
  *(v1 + 57) = -1;
  *(v1 + 10) = 0;
  *(v1 + 112) = -1;
  *(v1 + 133) = 0;
  v1[61] = 0;
  *(v1 + 140) = 0x3F80000000000000LL;
  *(v1 + 31) = 0;
  SetDebugFlag(v1);
  *(v1 + 114) = itfMesMngInitialize(tbl, 0, 0);
  LoadBattleLocalizeText();
  return v1;
}

// 0x1974090
void nbKillMainProcess(void) {
  dds3ProcessID_t_o **p_MainProcessID;

  if (dds3SearchProcessPriority(1018))
  {
    p_MainProcessID = &nbGetMainProcessData()->MainProcessID;
    dds3KillProcess(p_MainProcessID, 1);
  }
  evtDisableMoonDraw();
  evtDeadMoonFree();
  ClrDrawFlag(0x20000000u);
  ClrDrawFlag(0x40000000u);
}

// 0x197fa40
void *nbMainProcess1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 v12;
  u64 v16;
  s32 v17;
  s32 monitor_high;
  s32 klass_high;
  nbMainProcessData_t_o *MainProcessData;
  char v27;
  s64 v29;
  Il2CppClass *v30;
  u64 v31;
  Il2CppClass *v33;
  struct nbKoukaPacket_t_o *first;
  s32 v37;
  s32 type;
  struct datUnitWork_t_array *unitwork;
  s32 v48;
  s32 JyokyoMes;
  u32 *monitor;
  s64 klass_low;
  u32 *v57;
  s64 v58;
  dds3ProcessID_t_o *v60;
  s32 v69;
  s32 monitor_low;
  s32 v73;
  s32 v74;
  s32 v76;
  dds3ProcessID_t_o *v84[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ++nbUnloadTime;
  ProcessData = dds3GetProcessData(&ida);
  v5 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbMainProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbMainProcessData_t, v84);
      if ((v84[0] & 1) != 0)
        v8 = v84[2];
      else
        v8 = v84 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  LODWORD(ProcessData[8].klass) = 0;
  nbUpdateSoundTable(v5);
  v12 = 1;
  switch (BYTE5(v5[8].klass))
  {
    case 0:
      nb1st = 1;
      v12 = 1;
      nbGetMainProcessData()->nextphase = 1;
      SubPhase = 0;
      dead_voice_time = 0.0;
      goto LABEL_298;
    case 1:
      v17 = *(*(v16 + 184) + 68LL);
      if (v17 != 1)
      {
        if (v17)
          goto LABEL_274;
        if (nbMainProcessSetUp(v16))
          goto LABEL_274;
        StageLoad_BlockMode(0);
        {
LABEL_357:
        }
LABEL_359:
LABEL_360:
        v12 = 0;
        ++SubPhase;
        goto LABEL_298;
      }
      if (nbGetStageStat() != 1)
        goto LABEL_274;
      nbGetMainProcessData()->nextphase = 2;
      InitShadow(0);
      SetNormalFrameRate(kernelObject);
LABEL_273:
      SubPhase = 0;
      goto LABEL_297;
    case 2:
      switch (SubPhase)
      {
        case 0:
          nbGetMainProcessData()->actionstackp = 0;
          monitor_high = HIDWORD(v5[4].monitor);
          nbSetEnemyStartData_0(v5, monitor_high);
          goto LABEL_360;
        case 1:
          v76 = HIDWORD(v5[4].monitor);
          nbSetEnemyStartData_1(v5, v76);
            goto LABEL_359;
          goto LABEL_357;
        case 2:
          nbCameraSetState(1u);
          if ((BYTE5(v5[7].monitor) & 8) == 0)
          {
            if (encChk())
            {
              encMode(1);
            }
          }
          nbFormDispOff(0);
          nbFormDispOff(1);
          nbFormDispOff(2);
          nbFormDispOff(3);
          nbPanelPressTurnOmit();
            goto LABEL_359;
          goto LABEL_357;
        case 3:
          nbInitEncProcess(v5);
            goto LABEL_359;
          goto LABEL_357;
        case 4:
          nbPanelPressGaugeStart();
            goto LABEL_357;
          goto LABEL_359;
        case 5:
          if (v5[25].klass)
          {
            v12 = 0;
          }
          else
          {
            nbCameraPressProcessThrough();
            v12 = 1;
            nbGetMainProcessData()->nextphase = 3;
          }
          nbTurnPBInitSetting();
          break;
        default:
          goto LABEL_274;
      }
      goto LABEL_298;
    case 3:
      if (v5[25].monitor)
        goto LABEL_274;
      klass_high = HIDWORD(v5[6].klass);
      if (klass_high == 8 || klass_high == 1)
        goto LABEL_287;
      MainProcessData = nbGetMainProcessData();
      v27 = 5;
      goto LABEL_296;
    case 4:
      if (!nbCameraPressProcessCheckRun())
        goto LABEL_191;
      goto LABEL_274;
    case 5:
      if (!LOWORD(v5[8].monitor))
      {
        nbPanelPressTurnStart();
      }
      if (nbCameraPressProcessGetFrame() < 10)
        goto LABEL_274;
      MainProcessData = nbGetMainProcessData();
      v27 = 4;
      goto LABEL_296;
    case 6:
      v29 = 4;
      break;
    case 7:
      if (HIDWORD(v5[6].klass) == 7)
      {
        first = nbGetKoukaProcessData()->first;
        if (first)
        {
          v37 = 0;
          do
          {
            type = first->type;
            first = first->next;
            if (type == 46)
              ++v37;
          }
          while (first);
          if (v37)
            goto LABEL_274;
        }
        unitwork = DDS3_GBWK->unitwork;
        if (!unitwork->m_Items[0]->hp)
        {
          v12 = 0;
          HIDWORD(v5[6].klass) = 0;
          goto LABEL_298;
        }
        MainProcessData = nbGetMainProcessData();
        v27 = 3;
        goto LABEL_296;
      }
      monitor = v5[18].monitor;
      klass_low = SLODWORD(v5[19].klass);
      if (!*&monitor[2 * klass_low + 8])
        goto LABEL_382;
      v57 = v5[18].monitor;
      v58 = SLODWORD(v5[19].klass);
      v60 = *&v57[2 * v58 + 8];
      if (nbGetActionSeq(v60) >= 20)
      {
LABEL_382:
        MainProcessData = nbGetMainProcessData();
        v27 = 8;
        goto LABEL_296;
      }
      goto LABEL_274;
    case 8:
      MainProcessData = nbGetMainProcessData();
      v27 = 9;
      goto LABEL_296;
    case 9:
      if ((BYTE4(v5[7].monitor) & 0x40) != 0)
      {
        if (8 * (nbCheckActionStack() != 0) > LOWORD(v5[8].monitor))
          goto LABEL_274;
      }
      else if (LOWORD(v5[8].monitor) < 8u)
      {
        goto LABEL_274;
      }
      if (nbCheckActionStack() || (v69 = HIDWORD(v5[6].klass)) == 0)
      {
        MainProcessData = nbGetMainProcessData();
        v27 = 10;
      }
      else
      {
        if (v69 == 7)
          goto LABEL_297;
        if (v69 == 5)
        {
          MainProcessData = nbGetMainProcessData();
          v27 = 15;
        }
        else
        {
LABEL_287:
          MainProcessData = nbGetMainProcessData();
          v27 = 11;
        }
      }
      goto LABEL_296;
    case 0xA:
      goto LABEL_298;
    case 0xB:
      if (!CheckActionProcessEnd(v5) || v5[16].monitor)
        goto LABEL_274;
      dead_voice_time = dead_voice_time + 1.0;
      if (dead_voice_time > dead_voice_waitmax)
        goto LABEL_170;
      if (p2sdStatusSE_Dead())
        goto LABEL_274;
LABEL_170:
      MainProcessData = nbGetMainProcessData();
      v27 = 12;
      goto LABEL_296;
    case 0xC:
      if (v5[17].klass)
        goto LABEL_274;
      MainProcessData = nbGetMainProcessData();
      v27 = 13;
      goto LABEL_296;
    case 0xD:
      ida->func_ans = -1;
      return 0;
    case 0xE:
      if (v5[22].monitor)
        goto LABEL_274;
LABEL_191:
      MainProcessData = nbGetMainProcessData();
      v27 = 6;
      goto LABEL_296;
    case 0xF:
      if (!CheckActionProcessEnd(v5))
        goto LABEL_274;
      v48 = v5[28].monitor;
      JyokyoMes = nbGetJyokyoMes(v5, 72);
      nbDispMsgHelp(v48, JyokyoMes, 1);
      HIDWORD(v5[7].monitor) &= 0xFFFFFF67;
      nbClearCommandMemeoyRenzoku();
      nbGetMainProcessData()->nextphase = 2;
      goto LABEL_273;
    default:
      goto LABEL_274;
  }
  do
  {
    v30 = v5[1].klass;
    v31 = v29 - 4;
    if ((*(*(&v30->_1.image + v29) + 136LL) & 1) != 0)
    {
      v33 = v5[1].klass;
      if ((*(*(&v33->_1.image + v29) + 140LL) & 7) != 0)
      {
LABEL_274:
        v12 = 0;
        goto LABEL_298;
      }
    }
    ++v29;
  }
  while (v31 < 0xF);
  MainProcessData = nbGetMainProcessData();
  v27 = 7;
LABEL_296:
  MainProcessData->nextphase = v27;
LABEL_297:
  v12 = 1;
LABEL_298:
  monitor_low = LOWORD(v5[8].monitor);
  if (monitor_low == 0xFFFF)
    v73 = -82;
  else
    v73 = 0;
  if (v73 != -82)
    LOWORD(v5[8].monitor) = monitor_low + 1;
  ++HIDWORD(v5[8].monitor);
  if (v12)
  {
    v74 = SBYTE6(v5[8].klass);
    nbSetPhase(v74);
  }
  return 0;
}

// 0x197f150
void nbMainProcessClear(void) {
  s64 v2;
  nbMainProcess_c *v3;
  u64 v4;
  struct UnityEngine_GameObject_array *oTargetMark2D;
  u64 max_length_low;
  UnityEngine_Object_o *v8;
  struct UnityEngine_GameObject_array *v10;
  UnityEngine_Object_o *v12;
  struct UnityEngine_GameObject_array *v13;
  u64 v15;
  s32 v16;
  s16 v17;
  Il2CppClass **v18;
  s32 i;
  struct System_Collections_Generic_List_GameObject__array *oHitNum;
  u64 v21;
  UnityEngine_Object_o *v24;
  s32 v26;
  struct System_Collections_Generic_List_GameObject__array *v29;
  struct System_Collections_Generic_List_GameObject__array *v31;
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v37;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v39;
  UnityEngine_Component_o *v40;
  UnityEngine_GameObject_o *v41;
  nbMainProcessData_t_o *MainProcessData;
  u64 v46;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v49;
  UnityEngine_Object_o *modelobj;
  UnityEngine_Object_o *v51;
  struct dds3Basic_t_o **p_basic;
  struct dds3Basic_t_o *basic;
  struct dds3Basic_t_o *v54;
  UnityEngine_Object_o *FildMapObj;
  UnityEngine_GameObject_o *v59;
  s32 v61;
  s32 Count;
  System_String_o *Item;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v70;
  System_String_o *SKILLSE_AKEY;
  System_Collections_Generic_List_Enumerator_T__o v73;
  System_Collections_Generic_List_Enumerator_T__o v74;

  v2 = 4;
  memset(&v74, 0, sizeof(v74));
  v4 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(oTargetMark2D->max_length);
    if (v4 >= max_length_low)
      break;
    else if (v4 >= max_length_low)
    {
      goto LABEL_12;
    }
    v8 = *(&oTargetMark2D->obj.klass + v2);
    if (op_Inequality(v8, 0, 0))
    {
      v10 = oTargetMark2D;
      v12 = *(&v10->obj.klass + v2);
      Destroy_27360000(v12);
      v13 = oTargetMark2D;
      *(&v13->obj.klass + v2) = 0;
    }
    ++v2;
    v4 = v2 - 4;
      goto LABEL_6;
  }
  v15 = 0;
  v16 = -1;
  v17 = *&v3->_2.bitflags1;
  if ((v17 & 0x200) != 0)
    goto LABEL_34;
LABEL_33:
  for (i = 0; ; i = v17 & 0x200)
  {
    v21 = LODWORD(oHitNum->max_length);
    if (v15 >= v21)
      break;
    else if (v15 >= v21)
    {
      goto LABEL_41;
    }
    __GetEnumerator(&v73, oHitNum->m_Items[v15]);
    v74 = v73;
    while ((sub_1A11200(&v74) & 1) != 0)
    {
      v24 = sub_1A11350(&v74);
      if (op_Inequality(v24, 0, 0))
      {
        Destroy_27360000(v24);
      }
    }
    v26 = v16 + 1;
    nullsub_111(&v74);
    if (v26 == -1)
    {
      v16 = -1;
        goto LABEL_60;
    }
    else
    {
      v16 = v26 + ~(v26 >> 31);
        goto LABEL_60;
    }
LABEL_60:
    v29 = oHitNum;
    _Clear(v29->m_Items[v15]);
    v31 = oHitNum;
    v18 = &v31->obj.klass + v15++;
    v18[4] = 0;
    if ((v17 & 0x200) == 0)
      goto LABEL_33;
LABEL_34:
  }
  BattleUI = GetBattleUI(2);
  if (op_Inequality(BattleUI, 0, 0))
  {
    transform = get_transform(BattleUI, 0);
    v37 = Find(transform, "bauto/auto_off", 0);
    gameObject = get_gameObject(v37);
    SetActive(gameObject, 1, 0);
    v39 = get_transform(BattleUI, 0);
    v40 = Find(v39, "bauto/auto_on", 0);
    v41 = get_gameObject(v40);
    SetActive(v41, 0, 0);
  }
  BattleUIDelete();
  MainProcessData = nbGetMainProcessData();
  v46 = 0;
  while (1)
  {
LABEL_76:
    form = MainProcessData->form;
    v49 = form->m_Items[v46];
    modelobj = v49->modelobj;
    if (!op_Inequality(modelobj, 0, 0))
      goto LABEL_96;
    v51 = v49->modelobj;
    if (v46 <= 3)
      break;
    Destroy_27360000(v51);
    basic = v49->basic;
    p_basic = &v49->basic;
    p_basic[11] = 0;
    if (basic)
      goto LABEL_87;
LABEL_96:
    if (++v46 == 32)
      goto LABEL_97;
  }
  nbNoDestroy_MoveCache_Party(v51);
  v54 = v49->basic;
  p_basic = &v49->basic;
  p_basic[11] = 0;
  if (!v54)
    goto LABEL_96;
LABEL_87:
  dds3DeleteSceneBasicData(p_basic);
  *p_basic = 0;
  if (++v46 != 32)
    goto LABEL_76;
LABEL_97:
  if (op_Inequality(FildMapObj, 0, 0))
  {
    v59 = FildMapObj;
    nbNoDestroy_MoveCache_Field_B(v59);
    FildMapObj = 0;
    FilterDelete();
  }
  v61 = 0;
  {
LABEL_117:
  }
  while (1)
  {
    Count = _get_Count(unitAB_List);
    if (v61 >= Count)
      break;
    Item = _get_Item(
             unitAB_List,
             v61);
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, Item);
    if (!Equals_5234480(Item, "dvl0x00"))
    {
      RemoveKeys(4, Item);
    }
    ++v61;
      goto LABEL_117;
  }
  _Clear(unitAB_List);
  v70 = get_asset_bc();
  UnloadAB(v70, SKILLSE_AKEY);
  RemoveKeys(3, SKILLSE_AKEY);
  UnloadUnusedAssets();
}

// 0x1980bf0
bool nbMainProcessSetUp(void) {
  u64 v2;
  struct nbMainProcess_StaticFields *static_fields;
  u64 *v7;
  struct System_Collections_Generic_List_GameObject__array *v9;
  UnityEngine_GameObject_o *v11;
  UnityEngine_Component_o *transform;
  UnityEngine_Transform_o *v14;
  s32 SiblingIndex;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v21;
  s64 v23;
  AssetBundleCtrl_o *v24;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v26;
  UnityEngine_Transform_o *v28;
  Il2CppObject *v29;
  u64 *v30;
  System_String_o *v31;
  u32 *oTargetMark2D;
  u64 v34;
  struct UnityEngine_GameObject_array *v37;
  UnityEngine_Transform_o *v40;
  AssetBundleCtrl_o *v41;
  Il2CppObject *v42;
  UnityEngine_GameObject_o *v43;
  UnityEngine_Transform_o *v45;
  Il2CppObject *v46;
  u64 *v47;
  u32 *oHitNum;
  struct System_Collections_Generic_List_GameObject__array *v52;
  Il2CppObject *object;
  UnityEngine_Transform_o *v55;
  s32 v56;

  static_fields = *(v2 + 184);
  switch (nbmsetup_phase)
  {
    case 0:
      UnloadUnusedAssets();
        goto LABEL_91;
      goto LABEL_93;
    case 1:
      if (!oTargetMark2D)
      {
        v7 = NewSpecific(UnityEngine_GameObject, 0x10u);
        *(*(v2 + 184) + 88LL) = v7;
      }
      if (!*(*(v2 + 184) + 96LL))
      {
        v9 = NewSpecific(System_Collections_Generic_List_GameObject_, 0x10u);
        oHitNum = v9;
      }
      v11 = Find("Canvas_UI/buttonguide01", 0);
      transform = get_transform(v11, 0);
      if (op_Inequality(transform, 0, 0))
      {
        v14 = get_transform(transform, 0);
        SiblingIndex = GetSiblingIndex(v14);
      }
      else
      {
        SiblingIndex = 0;
      }
      v23 = 4;
      break;
    case 2:
      BattleUIRead(v2);
      goto LABEL_42;
    case 3:
      asset_bc = get_asset_bc();
      Load(asset_bc, SKILLSE_AKEY, SKILLSE_AKEY, 0);
LABEL_42:
      goto LABEL_94;
    case 4:
      v21 = get_asset_bc();
      if (!IsLoad(v21, SKILLSE_AKEY))
        return 1;
      goto LABEL_90;
    default:
      return 0;
  }
  do
  {
    v24 = get_asset_bc();
    Prefab_16624656 = LoadPrefab_16624656(v24, "common", "dds3data/UI/battleUI", "bcursur_chara");
    v26 = Find("Canvas_UI", 0);
    v28 = get_transform(v26, 0);
    v29 = Instantiate_object__425664(Prefab_16624656, v28, 0);
    AddComponent_object_(v29);
    v56 = v23 - 4;
    v30 = sub_8D3950(s32, &v56);
    v31 = Concat("target_marker2D", v30);
    set_name(v29, v31);
    else
    {
      v34 = v23 - 4;
      if (!v29)
        goto LABEL_65;
    }
LABEL_65:
    *&oTargetMark2D[2 * v23] = v29;
    v37 = oTargetMark2D;
    SetActive(*(&v37->obj.klass + v23), 0, 0);
    if (SiblingIndex)
    {
      v40 = get_transform(v29, 0);
      SetSiblingIndex(v40, ++SiblingIndex);
    }
    v41 = get_asset_bc();
    v42 = LoadPrefab_16624656(v41, "common", "dds3data/UI/battleUI", "bhit_ef");
    v43 = Find("Canvas_UI", 0);
    v45 = get_transform(v43, 0);
    v46 = Instantiate_object__425664(v42, v45, 0);
    AddComponent_object_(v46);
    v47 = Allocate(System_Collections_Generic_List_GameObject_);
    __ctor(
      v47);
    _Add(v47, v46);
    else
    {
      if (!v47)
        goto LABEL_83;
    }
LABEL_83:
    *&oHitNum[2 * v23] = v47;
    v52 = oHitNum;
    object = First_object_(
               *(&v52->obj.klass + v23));
    SetActive(object, 0, 0);
    if (SiblingIndex)
    {
      v55 = get_transform(v46, 0);
      SetSiblingIndex(v55, ++SiblingIndex);
    }
    ++v23;
  }
  while (v23 != 20);
LABEL_90:
  {
LABEL_91:
  }
LABEL_93:
LABEL_94:
  ++nbmsetup_phase;
  return 1;
}

// 0x1981450
void *nbMainShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  nbMainProcessData_t_o *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v9;
  s32 monitor;
  Il2CppObject *v15;
  dds3ProcessID_t_o *v16[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  v15 = 0;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbMainProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbMainProcessData_t, v16);
      if ((v16[0] & 1) != 0)
        v7 = v16[2];
      else
        v7 = v16 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v15 = ProcessData;
  if (v4)
  {
    v9 = v4;
    {
      v9 = v4;
    }
    nbFreeSound(v4);
    effBTLDelete(&v9->HatudoEff);
    v9->HatudoEff = 0;
    monitor = v15[28].monitor;
    itfMesMngRelease(monitor);
    nbFreeFlyUnitPack(&v15);
  }
  RemoveBattleLocalizeText();
  return 0;
}

// 0x197eac0
s32 nbPopAction(nbActionStack_t **act) {
  nbMainProcessData_t_o *MainProcessData;
  s32 actionstackp;
  s32 v8;
  struct nbActionStack_t_array *actionstack;
  s64 v11;
  struct nbActionStack_t_array *v13;
  s64 v14;
  struct nbActionStack_t_array *v16;
  s64 v17;
  struct nbActionStack_t_array *v19;
  s64 v20;
  nbActionStack_t_o *v21;

  MainProcessData = nbGetMainProcessData();
  do
  {
    while (1)
    {
      actionstackp = MainProcessData->actionstackp;
      v8 = actionstackp - 1;
      if (actionstackp < 1)
        return 0;
      MainProcessData->actionstackp = v8;
        break;
      if (!CheckErrorActionStack(MainProcessData, v8))
        goto LABEL_13;
    }
  }
  while (CheckErrorActionStack(MainProcessData, v8));
LABEL_13:
  actionstack = MainProcessData->actionstack;
  v11 = MainProcessData->actionstackp;
  (*act)->type = actionstack->m_Items[v11]->type;
  v13 = MainProcessData->actionstack;
  v14 = MainProcessData->actionstackp;
  (*act)->from = v13->m_Items[v14]->from;
  v16 = MainProcessData->actionstack;
  v17 = MainProcessData->actionstackp;
  (*act)->to = v16->m_Items[v17]->to;
  v19 = MainProcessData->actionstack;
  v20 = MainProcessData->actionstackp;
  v21 = *act;
  v21->data = v19->m_Items[v20]->data;
  return 1;
}

// 0x197e700
void nbPushAction(s32 type, s32 from, s32 to, s32 d) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbActionStack_t_array *actionstack;
  s64 actionstackp;
  struct nbActionStack_t_array *v14;
  s64 v15;
  struct nbActionStack_t_array *v17;
  s64 v18;
  struct nbActionStack_t_array *v20;
  s64 v21;

  MainProcessData = nbGetMainProcessData();
  actionstack = MainProcessData->actionstack;
  actionstackp = MainProcessData->actionstackp;
  actionstack->m_Items[actionstackp]->type = type;
  v14 = MainProcessData->actionstack;
  v15 = MainProcessData->actionstackp;
  v14->m_Items[v15]->from = from;
  v17 = MainProcessData->actionstack;
  v18 = MainProcessData->actionstackp;
  v17->m_Items[v18]->to = to;
  v20 = MainProcessData->actionstack;
  v21 = MainProcessData->actionstackp;
  v20->m_Items[v21]->data = d;
  ++MainProcessData->actionstackp;
}

// 0x197c5a0
void nbSetActionMaePhase(nbMainProcessData_t *data) {
  struct System_SByte_array *order;
  s64 orderindex;
  s32 v9;

  else if (nbCheckActionStack(nbMainProcess))
  {
    return;
  }
  order = data->order;
  orderindex = data->orderindex;
  v9 = order->m_Items[orderindex];
  nbPushAction(0, v9, 0, 0);
}

// 0x197c680
void nbSetActionPhase(nbMainProcessData_t *data) {
  nbActionStack_t_o *v2;
  s32 type;
  s32 from;
  s32 v8;
  s32 to;
  nbActionStack_t_o *v11;
  nbMainProcessData_t_o *dataa;

  dataa = data;
  v2 = Allocate(nbActionStack_t);
  nbActionStack_t___ctor(v2);
  v11 = v2;
  nbPopAction(&v11);
  nbPackEmptyFormation(&dataa);
  type = v2->type;
  from = v2->from;
  to = v2->to;
  v8 = v2->data;
  nbInitActionProcess(&dataa, type, from, to, v8);
  nbCameraCRSetPlayerFormRequest();
}

// 0x197d170
void nbSetAtoPhase(nbMainProcessData_t *data) {
  u64 i;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v7;
  u16 badstatus;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v11;
  datUnitWork_t_o *v12;
  datUnitWork_t_o *v14;
  datUnitWork_t_o *v15;
  datUnitWork_t_o *v17;
  datUnitWork_t_o *v18;
  datUnitWork_t_o *v20;

  for (i = 0; i != 16; ++i)
  {
    unitwork = DDS3_GBWK->unitwork;
    v7 = unitwork->m_Items[i];
    badstatus = v7->badstatus;
    if (nbCheckBadKaifuku(v7, 3))
    {
      if ((badstatus & 0xFFF) == 0x200)
      {
        v7->badstatus &= ~0x200u;
        v7->maxhp = datGetMaxHp(v7);
        v7->maxmp = datGetMaxMp(v7);
      }
      v7->badstatus &= 0xF000u;
    }
  }
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(0);
  if (UnitWorkFromFormindex)
  {
    v11 = UnitWorkFromFormindex;
    if ((UnitWorkFromFormindex->badstatus & 0xFFF) != 0x800)
    {
      if (UnitWorkFromFormindex->hp)
      {
        datSetAutoKaifukuSkill(v11, 346);
        datSetAutoKaifukuSkill(v11, 347);
        datSetAutoKaifukuSkill(v11, 348);
      }
    }
  }
  v12 = nbGetUnitWorkFromFormindex(1);
  if (v12)
  {
    v14 = v12;
    if ((v12->badstatus & 0xFFF) != 0x800)
    {
      if (v12->hp)
      {
        datSetAutoKaifukuSkill(v14, 346);
        datSetAutoKaifukuSkill(v14, 347);
        datSetAutoKaifukuSkill(v14, 348);
      }
    }
  }
  v15 = nbGetUnitWorkFromFormindex(2);
  if (v15)
  {
    v17 = v15;
    if ((v15->badstatus & 0xFFF) != 0x800)
    {
      if (v15->hp)
      {
        datSetAutoKaifukuSkill(v17, 346);
        datSetAutoKaifukuSkill(v17, 347);
        datSetAutoKaifukuSkill(v17, 348);
      }
    }
  }
  v18 = nbGetUnitWorkFromFormindex(3);
  if (v18)
  {
    v20 = v18;
    if ((v18->badstatus & 0xFFF) != 0x800)
    {
      if (v18->hp)
      {
        datSetAutoKaifukuSkill(v20, 346);
        datSetAutoKaifukuSkill(v20, 347);
        datSetAutoKaifukuSkill(v20, 348);
      }
    }
  }
  nbInitAtoProcess(data);
}

// 0x197c7b0
void nbSetChkEndPhase(nbMainProcessData_t *data) {
  s64 v3;
  struct nbParty_t_array *party;
  u64 v5;
  struct nbParty_t_array *v7;
  struct datUnitWork_t_array *unitwork;
  struct nbParty_t_array *v11;
  struct nbParty_t_array *v12;
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_GameObject_o *v21;
  UnityEngine_Transform_o *transform;
  s32 v23;
  UnityEngine_Transform_o *v24;
  UnityEngine_Object_o *Child;
  System_String_o *name;
  UnityEngine_Transform_o *v27;
  UnityEngine_Component_o *v28;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v30;

  if (data->endtype)
    goto LABEL_37;
  if (!data->enemypcnt)
    data->endtype = 1;
  v3 = 8;
  do
  {
    party = data->party;
    v5 = v3 - 4;
    if ((*(*(&party->obj.klass + v3) + 16LL) & 1) != 0)
    {
      v7 = data->party;
      if ((*(*(&v7->obj.klass + v3) + 16LL) & 0x20) == 0)
        break;
    }
    ++v3;
  }
  while (v5 <= 0xC);
  if (v3 == 18)
    data->endtype = 1;
  if (nbCheckBadStatusGameOver(data))
  {
    Write("全員行動不能!!\n", 0);
    data->endtype = 6;
  }
  unitwork = DDS3_GBWK->unitwork;
  if (!unitwork->m_Items[0]->hp)
  {
    data->endtype = 2;
    v11 = data->party;
    if (LODWORD(v11->max_length))
      goto LABEL_27;
LABEL_34:
  }
  v11 = data->party;
  if (!LODWORD(v11->max_length))
    goto LABEL_34;
LABEL_27:
  if ((v11->m_Items[0]->flag & 1) == 0)
    goto LABEL_36;
  v12 = data->party;
  if ((v12->m_Items[0]->flag & 0x20) != 0)
  {
LABEL_36:
    data->endtype = 2;
  }
  else if (!data->endtype)
  {
    goto LABEL_41;
  }
LABEL_37:
  nbResetTurnSetAnimKeepState();
LABEL_41:
  else if (nbCheckActionStack(nbMainProcess))
  {
    return;
  }
  if (data->endtype == 1 && nbCheckRenzokuEncount(data))
  {
    data->endtype = 5;
    nbPanelStockHide();
    BattleUI = GetBattleUI(0);
    if (op_Inequality(BattleUI, 0, 0))
    {
      if (get_activeSelf(BattleUI))
        SetActive(BattleUI, 0, 0);
      v21 = GetBattleUI(2);
      transform = get_transform(v21, 0);
      if (get_childCount(transform) >= 1)
      {
        v23 = 0;
        do
        {
          v24 = get_transform(v21, 0);
          Child = GetChild(v24, v23);
          name = get_name(Child);
          if (!Equals_5234480(name, "bauto"))
          {
            v27 = get_transform(v21, 0);
            v28 = GetChild(v27, v23);
            gameObject = get_gameObject(v28);
            SetActive(gameObject, 0, 0);
          }
          ++v23;
          v30 = get_transform(v21, 0);
        }
        while (v23 < get_childCount(v30));
      }
    }
  }
}

// 0x197cbc0
void nbSetChkTurnPhase(nbMainProcessData_t *data) {
  s32 v5;
  nbMainProcessData_t_o *MainProcessData;
  char v11;
  s64 v13;
  s64 v14;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u32 v16;
  u32 flag;
  struct nbFormation_t_array *form;
  struct nbParty_t_array *party;
  s64 interfaceOffsets_low;
  s32 RandIntA;
  struct nbFormation_t_array *v25;
  u32 stat;
  u8 turn;
  u8 v29;

  v5 = nbCheckActionStack();
  if (v5)
  {
      goto LABEL_37;
LABEL_8:
LABEL_37:
    if ((byte_3F5AB50 & 1) != 0)
    {
LABEL_39:
      MainProcessData = nbGetMainProcessData();
      v11 = 6;
LABEL_43:
      MainProcessData->nextphase = v11;
      return;
    }
LABEL_38:
    goto LABEL_39;
  }
  nbGetMainProcessData()->actionstackp = 0;
  if (data->eventno >= 1)
  {
      goto LABEL_23;
LABEL_21:
LABEL_23:
    MainProcessData = nbGetMainProcessData();
    v11 = 3;
    goto LABEL_43;
  }
  if (data->press4_p > 0 || data->press4_ten > 0)
  {
    if ((data->stat & 0x40000) == 0)
    {
      nbSetNextOrder();
    }
      goto LABEL_37;
    goto LABEL_8;
  }
  v13 = 32;
  v14 = -16;
  do
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v14 + 16);
    if (nbCheckBadKaifuku(UnitWorkFromFormindex, 0))
    {
      v16 = UnitWorkFromFormindex->badstatus & 0xFFF;
      if (v16 <= 8)
      {
        if (v16 != 4 && v16 != 8)
          goto LABEL_59;
      }
      else if (v16 != 128 && v16 != 16)
      {
LABEL_59:
        form = data->form;
        party = data->party;
        interfaceOffsets_low = SLOWORD((*(&form->obj.klass + v13))->_1.interfaceOffsets);
        if ((party->m_Items[interfaceOffsets_low]->flag & 0x20) == 0)
        {
          RandIntA = dds3GetRandIntA(7u, "");
          v25 = data->form;
          nbMakeBadKaifukuPacket(RandIntA, 0, (v25 + v13));
        }
        goto LABEL_70;
      }
      flag = UnitWorkFromFormindex->flag;
      if ((data->stat & 8) != 0)
      {
        if ((flag & 0x20) == 0)
          goto LABEL_70;
      }
      else if ((flag & 0x20) != 0)
      {
        goto LABEL_70;
      }
      goto LABEL_59;
    }
LABEL_70:
    ++v14;
    v13 += 8;
  }
  while (v14);
  nbSetHojoCounter(0, 18, 0);
  nbSetHojoCounter(1, 18, 0);
  nbSetHojoCounter(2, 18, 0);
  nbSetHojoCounter(3, 18, 0);
  nbSetHojoCounter(4, 18, 0);
  nbSetHojoCounter(5, 18, 0);
  nbSetHojoCounter(6, 18, 0);
  nbSetHojoCounter(7, 18, 0);
  nbSetHojoCounter(8, 18, 0);
  nbSetHojoCounter(9, 18, 0);
  nbSetHojoCounter(10, 18, 0);
  nbSetHojoCounter(11, 18, 0);
  nbSetHojoCounter(12, 18, 0);
  nbSetHojoCounter(13, 18, 0);
  nbSetHojoCounter(14, 18, 0);
  nbSetHojoCounter(15, 18, 0);
  stat = data->stat;
  data->stat = stat & 0xFFFFFF6F;
  if ((stat & 8) == 0)
  {
    data->stat = stat & 0xFFFFFF67 | 8;
      goto LABEL_23;
    goto LABEL_21;
  }
  data->stat = stat & 0xFFFFFF67;
  turn = data->turn;
  if ((turn + 1) < 0x63u)
    v29 = turn + 1;
  else
    v29 = 99;
  data->turn = v29;
  nbGetMainProcessData()->nextphase = 3;
  nbAddKagututiMoon(data);
}

// 0x197db30
void nbSetDebugPhase(nbMainProcessData_t *data) {
  struct dds3ProcessID_t_array *ActionProcessID;
  s64 NowActionProcess;
  struct dds3ProcessID_t_array *v6;
  s64 v7;
  nbMainProcessData_t_o *dataa;

  dataa = data;
  if (data->CommSelProcessID)
  {
    dds3KillProcess(&data->CommSelProcessID, 1);
  }
  ActionProcessID = data->ActionProcessID;
  NowActionProcess = data->NowActionProcess;
  if (ActionProcessID->m_Items[NowActionProcess])
  {
    v6 = data->ActionProcessID;
    v7 = data->NowActionProcess;
    else if (v7 >= LODWORD(v6->max_length))
    {
      goto LABEL_14;
    }
    dds3KillProcess(&v6->m_Items[v7], 1);
  }
  data->NowActionProcess = 0;
  nbInitDebugProcess(&dataa);
}

// 0x197d720
void nbSetEndPhase(nbMainProcessData_t *data) {
  u64 *v3;
  u64 *v5;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v10;
  s32 v13;
  u64 *v14;
  struct datUnitWork_t_array *v18;
  struct datUnitWork_t_array *v20;
  struct datUnitWork_t_array *v22;
  struct datUnitWork_t_array *v23;
  s32 v27;

  v3 = NewSpecific(uint, 1u);
  v5 = v3;
  *(v3 + 8) = 799;
  DDS3_GBWK->encountcnt = 0;
  DDS3_GBWK->encountkyori = 0.0;
  unitwork = DDS3_GBWK->unitwork;
  if (!unitwork->m_Items[0]->hp)
    goto LABEL_25;
  v10 = DDS3_GBWK->unitwork;
  if (v10->m_Items[0]->badstatus == 2048)
  {
LABEL_25:
    v18 = DDS3_GBWK->unitwork;
    v18->m_Items[0]->flag = 7;
    v20 = DDS3_GBWK->unitwork;
    v20->m_Items[0]->badstatus = 0;
    v22 = DDS3_GBWK->unitwork;
    v22->m_Items[0]->hp = DDS3_GBWK->unitwork->m_Items[0]->maxhp;
    v23 = DDS3_GBWK->unitwork;
    v23->m_Items[0]->mp = DDS3_GBWK->unitwork->m_Items[0]->maxmp;
    if ((data->endtype | 4) == 6)
      goto LABEL_16;
  }
  else if ((data->endtype | 4) == 6)
  {
LABEL_16:
    if (!evtBitCheck(3084))
    {
      v13 = *(v5 + 8);
      Write("game over !!\n", 0);
      v27 = v13;
      v14 = sub_8D3950(s32, &v27);
      dds3AdminiCallSequence(8, v14, 4, 0);
    }
    return;
  }
  else if (!rstChkResultEntry())
  {
    return;
  }
  Write("level up !!\n", 0);
  dds3AdminiCallSequence(15, 0, 0, 1);
}

// 0x197c220
void nbSetEventPhase(nbMainProcessData_t *data) {
  if (data->eventno >= 1)
  {
    nbInitEventProcess(data);
    nbDelUnEventKoukaPacket();
  }
}

// 0x197df80
void nbSetFormationSideFlag(nbFormation_t *form, s32 index) {
  u32 *p_stat;
  u32 stat;
  s32 v5;
  s32 v6;

  form->formindex = index;
  if (index > 3)
  {
    stat = form->stat;
    p_stat = &form->stat;
    v5 = stat | 0x400;
    v6 = stat | 0x200;
    if (index > 13)
      v6 = v5;
    *p_stat = v6;
  }
  else
  {
    form->stat |= 0x100u;
  }
}

// 0x197bfd0
void nbSetMaePhase(nbMainProcessData_t *data) {
  s32 encno;
  nbMainProcessData_t_o *v11;
  nbMainProcessData_t_o *v13;
  nbMainProcessData_t_o *dataa;

  dataa = data;
LABEL_7:
  encno = data->encno;
  if ((Get(encno, 0)->flag & 1) != 0)
    data->stat |= 1u;
  CheckSenseiOrBackAttack(data);
  nbSetPlayerStartData(data);
  nbInitUnitProcess(&dataa);
  nbInitKoukaProcess(dataa);
  nbInitTarSelProcess(dataa);
  nbInitMaeProcess(&dataa);
  nbInitEffectProcess(&dataa);
  nbInitCameraProcess(&dataa);
  v11 = dataa;
  nbInitPanelProcess(v11);
  v13 = dataa;
  nbInitHelpProcess(v13);
  nbInitAutoCommProcess(dataa);
  nbInitMakaProcess(dataa->MainProcessID);
  nbInitStageProcess(&dataa);
  StageLoad_BlockMode(1);
  nbPanelPressGaugeEncountHide();
}

// 0x197dc80
void nbSetNextPhase(s32 phase) {
  s8 v2;

  v2 = phase;
  nbGetMainProcessData()->nextphase = v2;
}

// 0x197bca0
void nbSetPhase(s32 phase) {
  s8 v2;
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v6;

  v2 = phase;
  MainProcessData = nbGetMainProcessData();
  MainProcessData->nextphase = -1;
  MainProcessData->phase = v2;
  MainProcessData->phasetime = 0;
  v6 = MainProcessData;
  switch (v2)
  {
    case 1:
      nbSetMaePhase(v6);
      break;
    case 3:
      if (v6->eventno >= 1)
      {
        nbInitEventProcess(v6);
        nbDelUnEventKoukaPacket();
      }
      break;
    case 5:
      nbSetPressMaePhase(v6);
      nbCameraPressProcessInit();
      break;
    case 6:
      nbSetActionMaePhase(v6);
      break;
    case 7:
      nbSetActionPhase(v6);
      break;
    case 9:
      nbSetChkEndPhase(v6);
      break;
    case 10:
      nbSetChkTurnPhase(v6);
      break;
    case 11:
      nbSetAtoPhase(v6);
      break;
    case 12:
      nbSetResultPhase(v6);
      break;
    case 13:
      nbSetEndPhase(v6);
      break;
    case 14:
      nbSetDebugPhase(v6);
      break;
    default:
      return;
  }
}

// 0x197c2b0
void nbSetPressMaePhase(nbMainProcessData_t *data) {
  u64 stat;
  u64 v5;
  bool v6;
  s64 v7;
  s64 v8;
  u64 v9;
  s64 v10;
  datUnitWork_t_o *UnitWorkPointer;
  struct nbParty_t_array *party;
  u64 v14;
  struct nbParty_t_array *v16;
  struct nbParty_t_array *v18;
  nbParty_t_o *v20;
  s16 press4_p;
  u64 v25;
  bool v26;
  u32 v27;
  s16 v28;
  s32 v29;
  u32 v30;
  u32 v31;

  stat = data->stat;
  data->press4_p = 0;
  data->press3 = 1.0;
  v5 = stat & 8;
  v6 = (stat & 8) == 0;
  v7 = (stat >> 1) & 4;
  if (v6)
    v8 = 4;
  else
    v8 = 10;
  v9 = v8 + (v5 >> 1);
  v10 = v7 + 4;
  do
  {
    party = data->party;
    v14 = v10 - 4;
    if ((*(*(&party->obj.klass + v10) + 16LL) & 1) != 0)
    {
      v16 = data->party;
      if ((*(*(&v16->obj.klass + v10) + 16LL) & 0x20) == 0)
      {
        v18 = data->party;
        v20 = *(&v18->obj.klass + v10);
        UnitWorkPointer = nbGetUnitWorkPointer(data, v20);
        if (UnitWorkPointer)
          goto LABEL_20;
      }
    }
LABEL_29:
    v25 = v10 - 3;
    ++v10;
  }
  while (v25 < v9);
  v26 = evtBitCheck(2240);
  v27 = data->stat & 8;
  if (v26)
  {
    v28 = data->press4_p;
    if (!v27)
    {
      data->press4_p = v28 + 1;
      data->press4_ten = v28 + 1;
      goto LABEL_34;
    }
    data->press4_ten = v28;
LABEL_36:
    v29 = 10;
  }
  else
  {
    data->press4_ten = data->press4_p;
    if (v27)
      goto LABEL_36;
LABEL_34:
    v27 = 0;
    v29 = 4;
  }
  v30 = v27 >> 1;
  v31 = v29 + (v27 >> 1);
  do
  {
    nbSetHojoCounter(v30, 14, 0);
    nbSetHojoCounter(v30++, 13, 0);
  }
  while (v30 < v31);
  data->endtype = 0;
  nbSetOrder();
}

// 0x197c530
void nbSetPressNiidaPhase(nbMainProcessData_t *data) {
  {
    nbCameraPressProcessInit();
  }
}

// 0x197d4d0
void nbSetResultPhase(nbMainProcessData_t *data) {
  s64 i;
  struct nbFormation_t_array *form;
  u64 v9;
  struct nbFormation_t_array *v11;
  struct nbFormation_t_array *v13;
  effBTLSysHandle_t_o **v15;
  struct nbFormation_t_array *v16;
  u32 endtype;

  nbMainProcessClear();
  SobedClear();
  evtDisableMoonDraw();
  for (i = 4; i != 20; ++i)
  {
    form = data->form;
    v9 = i - 4;
    if ((*(*(&form->obj.klass + i) + 136LL) & 1) != 0)
    {
      v11 = data->form;
      if (*(*(&v11->obj.klass + i) + 184LL))
      {
        v13 = data->form;
        v15 = (*(&v13->obj.klass + i) + 184LL);
        effBTLSystemDelete2(v15);
        v16 = data->form;
        *(*(&v16->obj.klass + i) + 184LL) = 0;
      }
    }
  }
  endtype = data->endtype;
  if ((endtype | 8) == 9)
  {
    nbGetEncountTableItem(data);
    endtype = data->endtype;
  }
  if (endtype <= 9 && ((1 << endtype) & 0x212) != 0)
  {
    nbInitResultProcess(data);
  }
  else
  {
    nbBgmFadeOut();
  }
}
