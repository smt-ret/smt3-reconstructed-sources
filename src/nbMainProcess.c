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
static void oTargetMark2D[UNKNOWN_ARRAY_SIZE];
static void oHitNum[UNKNOWN_ARRAY_SIZE];
static void oBattle_UI[UNKNOWN_ARRAY_SIZE];
static void oBattle_UI_PreLoad[UNKNOWN_ARRAY_SIZE];
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
}

// 0x1982e10
void BattleUIPreRead(void) {
    LoadPrefab_16624656(0, 0, 0, 0);
}

// 0x19823a0
void BattleUIRead(void) {
    LoadPrefab_16624656(0, 0, 0, 0);
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
      Write(StringLiteral_21433, 0);
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
    return 0;
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
    return 0;
}

// 0x19829a0
void SetActiveToAllHitNum(s32 idx, bool bActive) {
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
    Get(0);
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
  Play_8766576(Component_object, StringLiteral_21447);
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
  v5 = MainProcessData;
  v6 = 0;
  while (1)
  {
    if (!CheckErrorActionStack(v5, v6))
      break;
    if (++v6 >= v5->actionstackp)
      return 0;
  }
  Write(StringLiteral_21434, 0);
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
    data->stat ^= 0x100000u;
  if (DDS3_PAD2CHECK_TRIG(3))
    data->debug = (data->debug & 1) == 0;
  if ((data->stat & 8) != 0 && evtBitCheck(3089))
  {
    if (!dds3GetRandIntA(5u, StringLiteral_416))
    {
      form = data->form;
      nbAddDeadPcmPacket(0, 0, &form->m_Items[2]);
      nbAddPadShockPacket(0, 0, 1, 150, 20);
    }
    if (!dds3GetRandIntA(5u, StringLiteral_416))
    {
      v11 = data->form;
      nbAddDeadPcmPacket(0, 0, &v11->m_Items[2]);
      nbAddPadShockPacket(0, 0, 1, 150, 20);
    }
  }
}

// 0x196dad0
nbMainProcessData_t *nbGetMainProcessData(void) {
    dds3SearchProcessPriority(0);
    dds3GetProcessData(0);
    return 0;
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
    SetDrawFlag(0, 0);
    SetBoostFrameRate(0);
    nbCamera_t__Clear(0);
    nbCameraState_Start_t__Clear(0);
    nbInitMainProcessData();
    Get(0);
    evtSetAgeOfMoon(0);
    SetFlag(0);
    ClearLocalBit();
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    evtEnableMoonDraw();
    evtDeadMoonInit();
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
    dds3GetProcessData(0);
    nbUpdateSoundTable(0);
    nbGetMainProcessData();
    nbMainProcessSetUp();
    StageLoad_BlockMode(0);
    nbGetStageStat();
    InitShadow(0);
    SetNormalFrameRate(0);
    nbSetEnemyStartData_0(0, 0);
    nbSetEnemyStartData_1(0, 0);
    nbCameraSetState(0);
    encChk();
    encMode(0);
    nbFormDispOff(0);
    nbPanelPressTurnOmit();
    nbInitEncProcess(0);
    nbPanelPressGaugeStart();
    nbCameraPressProcessThrough();
    nbTurnPBInitSetting();
    nbCameraPressProcessCheckRun();
    nbPanelPressTurnStart();
    nbCameraPressProcessGetFrame();
    nbGetKoukaProcessData();
    nbGetActionSeq(0);
    nbCheckActionStack();
    CheckActionProcessEnd(0);
    p2sdStatusSE_Dead();
    nbGetJyokyoMes(0, 0);
    nbDispMsgHelp(0, 0, 0);
    nbClearCommandMemeoyRenzoku();
    nbSetPhase(0);
    return 0;
}

// 0x197f150
void nbMainProcessClear(void) {
    GetBattleUI(0);
    BattleUIDelete();
    nbGetMainProcessData();
    nbNoDestroy_MoveCache_Party(0);
    dds3DeleteSceneBasicData(0);
    nbNoDestroy_MoveCache_Field_B(0);
    FilterDelete();
    UnloadAB(0, 0);
    RemoveKeys(0, 0);
}

// 0x1980bf0
bool nbMainProcessSetUp(void) {
    BattleUIRead();
    Load(0, 0);
    IsLoad(0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
    return 0;
}

// 0x1981450
void *nbMainShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    nbFreeSound(0);
    effBTLDelete(0);
    itfMesMngRelease(0);
    nbFreeFlyUnitPack(0);
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
    }
  }
  while (CheckErrorActionStack(MainProcessData, v8));
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
    Write(StringLiteral_21435, 0);
    data->endtype = 6;
  }
  unitwork = DDS3_GBWK->unitwork;
  if (!unitwork->m_Items[0]->hp)
  {
    data->endtype = 2;
    v11 = data->party;
    if (LODWORD(v11->max_length))
  }
  v11 = data->party;
  if (!LODWORD(v11->max_length))
  if ((v11->m_Items[0]->flag & 1) == 0)
  v12 = data->party;
  if ((v12->m_Items[0]->flag & 0x20) != 0)
  {
    data->endtype = 2;
  }
  else  nbResetTurnSetAnimKeepState();
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
          if (!Equals_5234480(name, StringLiteral_21436))
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
    if ((byte_3F5AB50 & 1) != 0)
    {
      MainProcessData = nbGetMainProcessData();
      v11 = 6;
      MainProcessData->nextphase = v11;
      return;
    }
  }
  nbGetMainProcessData()->actionstackp = 0;
  if (data->eventno >= 1)
  {
    MainProcessData = nbGetMainProcessData();
    v11 = 3;
  }
  if (data->press4_p > 0 || data->press4_ten > 0)
  {
    if ((data->stat & 0x40000) == 0)
    {
      nbSetNextOrder();
    }
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
      }
      else if (v16 != 128 && v16 != 16)
      {
        form = data->form;
        party = data->party;
        interfaceOffsets_low = SLOWORD((*(&form->obj.klass + v13))->_1.interfaceOffsets);
        if ((party->m_Items[interfaceOffsets_low]->flag & 0x20) == 0)
        {
          RandIntA = dds3GetRandIntA(7u, StringLiteral_416);
          v25 = data->form;
          nbMakeBadKaifukuPacket(RandIntA, 0, (v25 + v13));
        }
      }
      flag = UnitWorkFromFormindex->flag;
      if ((data->stat & 8) != 0)
      {
        if ((flag & 0x20) == 0)
      }
      else    }
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
    dds3KillProcess(0, 0);
    nbInitDebugProcess(0);
}

// 0x197d720
void nbSetEndPhase(nbMainProcessData_t *data) {
    evtBitCheck(0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    rstChkResultEntry();
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
    nbGetUnitWorkPointer(0, 0);
    Get(0);
    evtBitCheck(0);
    nbSetHojoCounter(0, 0, 0);
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
