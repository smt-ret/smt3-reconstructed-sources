#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct typeNbResultLvupAnmWork typeNbResultLvupAnmWork;
typedef struct typeNbResultWork typeNbResultWork;

static s32 barname;
static s32 skipFlag;
static sdfMemHandle_t *hNbResTexFile1;
static sdfMemHandle_t *hNbResTexFile2;
static sdfMemHandle_t *hNbResTexFile3;
static void *pNbResTexFile1;
static void *pNbResTexFile2;
static void *pNbResTexFile3;
static sdfTexHandle_t *hResultTex1;
static sdfTexHandle_t *hResultTex2;
static sdfTexHandle_t *hResultTex3;
static s32 gResultUpAnimeCnt;
static s32 gResultDoAnimeCnt;
static s32 gResultQuitCnt;
static s32 gResultFinWait;
static s32 gResultNowLoading;
static s32 gResultSeFlag;
static s32 AllExp;
static typeNbResultWork gnbResultWork[UNKNOWN_ARRAY_SIZE];
static typeNbResultLvupAnmWork gnbResultLvupAnmWork[UNKNOWN_ARRAY_SIZE];
static f32 nbResultDrawBG_hikari_cntf;
static void *oResult_UI;
static void *brtitle;
static void *brgetexp;
static void *brgetitem;
static void *brparty[4];

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void ClearResultUI(void);
void ClearStage(void);
bool DDS3_PADCHECK_PRESS(s32 id);
void FadeoutBGM(char *name, f32 fadeTime);
u8 Get(s32 id);
s32 GetAddExp(s32 stock, s32 exp);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetAnimator(void *obj, char *animkey, s32 animno);
void ShutdownProcess(void);
void Unlock_16599376(char *id);
void datAddExp(datUnitWork_t *w, s32 exp);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
s32 datCheckSyojiSkill(datUnitWork_t *work, u32 skill);
void dds3FadeIn2(u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
u32 dds3GetProcessRunTime(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void evtFreeStage(void);
s32 fldLoadNextFile_BtlRet(void);
s32 fldLoadNextGetStatus(void);
s32 fldLoadNextTask(void);
void fldSkySetAlpha(s32 alp);
char *frGetCNameString(s8 TargetNo);
s32 nbGetKakutokuExp(nbMainProcessData_t *data);
s32 nbGetKakutokuMaka(nbMainProcessData_t *data);
nbMainProcessData_t *nbGetMainProcessData(void);
void nbResultAddExp(void);
void nbResultDrawBG(nbMainProcessData_t *p);
void nbResultDrawPC1(s32 j, s32 x, s32 y, s32 cnt, datUnitWork_t *unit, s32 idx, nbMainProcessData_t *p);
s32 nbResultFinWaitChk(nbMainProcessData_t *p);
void nbResultLoad(void);
void nbResultLvupAnmAdd(s32 x, s32 y);
void nbResultSkip(nbMainProcessData_t *p);
s32 p2sdPlaySE(s32 a);
void rDevilFrameOff(void);
void rItemOn(void);
u32 rstCalcExpFromLevel(u8 Index, s32 Level);
u8 rstCalcLevelFromExp(u8 Index, u32 Exp);

// 0x157cde0
void ClearResultUI(void) {
  UnityEngine_Object_o *oResult_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oResult_UI, 0, 0))
  {
    v6 = oResult_UI;
    Destroy_27360000(v6);
    oResult_UI = 0;
  }
}

// 0x157ba70
void ClearStage(void) {
  nbMainProcessData_t_o *MainProcessData;
  s64 i;
  struct nbFormation_t_array *form;
  u64 v6;
  struct nbFormation_t_array *v8;
  struct nbFormation_t_array *v10;
  struct nbFormation_t_array *v12;
  s64 v14;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v17;
  struct nbParty_t_array *v19;
  struct nbParty_t_array *v21;
  struct nbParty_t_array *v23;
  struct nbParty_t_array *v25;
  struct nbParty_t_array *v27;
  struct nbParty_t_array *v29;
  struct nbParty_t_array *v31;
  struct nbParty_t_array *v33;
  struct nbParty_t_array *v35;
  struct nbParty_t_array *v37;
  struct nbParty_t_array *v39;
  struct nbParty_t_array *v41;

  MainProcessData = nbGetMainProcessData();
  for (i = 4; i != 36; ++i)
  {
    form = MainProcessData->form;
    v6 = i - 4;
    if ((*(*(&form->obj.klass + i) + 136LL) & 1) != 0)
    {
      v8 = MainProcessData->form;
      if (*(*(&v8->obj.klass + i) + 216LL))
      {
        v10 = MainProcessData->form;
        *(*(&v10->obj.klass + i) + 216LL) = 0;
      }
    }
    v12 = MainProcessData->form;
    v14 = *(&v12->obj.klass + i);
    *(v14 + 136) = 0;
  }
  party = MainProcessData->party;
  party->m_Items[0]->flag |= 0x28u;
  v17 = MainProcessData->party;
  v17->m_Items[1]->flag |= 0x28u;
  v19 = MainProcessData->party;
  v19->m_Items[2]->flag |= 0x28u;
  v21 = MainProcessData->party;
  v21->m_Items[3]->flag |= 0x28u;
  v23 = MainProcessData->party;
  v23->m_Items[4]->flag |= 0x28u;
  v25 = MainProcessData->party;
  v25->m_Items[5]->flag |= 0x28u;
  v27 = MainProcessData->party;
  v27->m_Items[6]->flag |= 0x28u;
  v29 = MainProcessData->party;
  v29->m_Items[7]->flag |= 0x28u;
  v31 = MainProcessData->party;
  v31->m_Items[8]->flag |= 0x28u;
  v33 = MainProcessData->party;
  v33->m_Items[9]->flag |= 0x28u;
  v35 = MainProcessData->party;
  v35->m_Items[10]->flag |= 0x28u;
  v37 = MainProcessData->party;
  v37->m_Items[11]->flag |= 0x28u;
  v39 = MainProcessData->party;
  v39->m_Items[12]->flag |= 0x28u;
  v41 = MainProcessData->party;
  v41->m_Items[13]->flag |= 0x28u;
  evtFreeStage();
}

// 0x1577c30
s32 GetAddExp(s32 stock, s32 exp) {
  u32 v6;
  struct datUnitWork_t_array *unitwork;
  s32 v10;
  s32 v11;

  v6 = rstCalcExpFromLevel(stock, 256);
  unitwork = DDS3_GBWK->unitwork;
  v10 = v6 + ~unitwork->m_Items[stock]->exp;
  v11 = v10 & ~(v10 >> 31);
  if (v11 <= exp)
    return v11;
  else
    return exp;
}

// 0x157a860
void *GetResultUI(void) {
  return oResult_UI;
}

// 0x1578d00
void SetAnimator(void *obj, char *animkey, s32 animno) {
  Il2CppObject *Component_object;
  s32 Integer;

  if (op_Inequality(obj, 0, 0))
  {
    Component_object = GetComponent_object_(obj);
    if (op_Inequality(Component_object, 0, 0))
    {
      Integer = GetInteger(Component_object, animkey);
      if (Contains(animkey, StringLiteral_21579, 0))
      {
        if (animno == 2)
        {
          if (Integer == 2)
            Play_8777152(Component_object, StringLiteral_21592, 0, 0.0);
        }
        else if (animno == 1)
        {
          if (Integer)
            return;
          SetInteger(Component_object, animkey, animno);
          return;
        }
      }
      if (Integer != animno)
    }
  }
}

// 0x157b880
void ShutdownProcess(void) {
  nbMainProcessData_t_o *MainProcessData;
  dds3ProcessID_t_o **p_PanelProcessID;

  MainProcessData = nbGetMainProcessData();
  if (MainProcessData->AutoCommProcessID)
  {
    dds3KillProcess(&MainProcessData->AutoCommProcessID, 1);
    MainProcessData->AutoCommProcessID = 0;
  }
  if (MainProcessData->CameraProcessID)
  {
    dds3KillProcess(&MainProcessData->CameraProcessID, 1);
    MainProcessData->CameraProcessID = 0;
  }
  if (MainProcessData->EffectProcessID)
  {
    dds3KillProcess(&MainProcessData->EffectProcessID, 1);
    MainProcessData->EffectProcessID = 0;
  }
  if (MainProcessData->UnitProcessID)
  {
    dds3KillProcess(&MainProcessData->UnitProcessID, 1);
    MainProcessData->UnitProcessID = 0;
  }
  if (MainProcessData->HelpProcessID)
  {
    dds3KillProcess(&MainProcessData->HelpProcessID, 1);
    MainProcessData->HelpProcessID = 0;
  }
  if (MainProcessData->PanelProcessID)
  {
    p_PanelProcessID = &MainProcessData->PanelProcessID;
    dds3KillProcess(p_PanelProcessID, 1);
    *p_PanelProcessID = 0;
  }
}

// 0x157d1f0
void nbInitResultProcess(nbMainProcessData_t *data) {
    dds3FadeOut(0, 0, 0, 0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
}

// 0x1577d30
void nbResult1StLoad(void) {
  ;
}

// 0x157be70
void nbResultAddExp(void) {
  nbMainProcessData_t_o *MainProcessData;
  struct System_Byte_array *item;
  nbMainProcessData_t_o *v5;
  struct System_Byte_array *itemcnt;
  struct System_Byte_array *v8;
  struct System_Byte_array *v9;
  s32 v10;
  s32 v11;
  struct System_Byte_array *v12;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;
  struct System_Byte_array *v18;
  s32 v19;
  s32 v21;
  struct System_Byte_array *v22;
  struct System_Byte_array *v25;
  struct System_Byte_array *v27;
  struct System_Byte_array *v29;
  s32 v30;
  s32 v32;
  struct System_Byte_array *v33;
  struct System_Byte_array *v34;
  struct System_Byte_array *v36;
  struct System_Byte_array *v38;
  s32 v39;
  s32 v41;
  s32 KakutokuMaka;
  u64 i;
  s32 KakutokuExp;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v52;
  u32 flag;
  struct datSpecialSkill_t_array *tbl;
  s32 AddExp;

  MainProcessData = nbGetMainProcessData();
  item = MainProcessData->item;
  v5 = MainProcessData;
  if (!item->m_Items[0])
  itemcnt = MainProcessData->itemcnt;
  if (itemcnt->m_Items[0])
  {
    v8 = MainProcessData->item;
    v9 = MainProcessData->itemcnt;
    v10 = v8->m_Items[0];
    v11 = v9->m_Items[0];
    datAddItem(v10, v11);
    v12 = v5->item;
  }
  else
  {
    v12 = MainProcessData->item;
    if ((v12->max_length & 0xFFFFFFFE) == 0)
  }
  if (v12->m_Items[1])
  {
    v14 = v5->itemcnt;
    if (v14->m_Items[1])
    {
      v16 = v5->item;
      v18 = v5->itemcnt;
      v19 = v16->m_Items[1];
      v21 = v18->m_Items[1];
      datAddItem(v19, v21);
      v22 = v5->item;
      if (LODWORD(v22->max_length) > 2uLL)
    }
  }
  v22 = v5->item;
  if (LODWORD(v22->max_length) <= 2uLL)
  if (v22->m_Items[2])
  {
    v25 = v5->itemcnt;
    if (v25->m_Items[2])
    {
      v27 = v5->item;
      v29 = v5->itemcnt;
      v30 = v27->m_Items[2];
      v32 = v29->m_Items[2];
      datAddItem(v30, v32);
    }
  }
  v33 = v5->item;
  if (v33->m_Items[3])
  {
    v34 = v5->itemcnt;
    if (v34->m_Items[3])
    {
      v36 = v5->item;
      v38 = v5->itemcnt;
      v39 = v36->m_Items[3];
      v41 = v38->m_Items[3];
      datAddItem(v39, v41);
    }
  }
  KakutokuMaka = nbGetKakutokuMaka(v5);
  datAddMaka(KakutokuMaka);
  for (i = 0; i != 16; ++i)
  {
    KakutokuExp = nbGetKakutokuExp(v5);
    unitwork = DDS3_GBWK->unitwork;
    v52 = unitwork->m_Items[i];
    flag = v52->flag;
    if ((flag & 1) != 0)
    {
      if ((flag & 2) != 0)
      if (datCheckSyojiSkill(v52, 0x162u))
      {
        if (KakutokuExp >= 1)
        {
          KakutokuExp /= tbl->m_Items[66]->n;
        }
        if ((v52->badstatus & 0xFFF) != 0x800 && v52->hp)
        {
          AddExp = GetAddExp(i, KakutokuExp);
          datAddExp(v52, AddExp);
        }
        continue;
      }
    }
  }
}

// 0x157ab90
void nbResultDrawBG(nbMainProcessData_t *p) {
    nbGetMainProcessData();
    rItemOn();
    Get(0);
    Set(0, 0);
    nbResultDrawPC1(0, 0, 0, 0, 0, 0, 0);
    rDevilFrameOff();
    nbGetKakutokuExp(0);
    nbGetKakutokuMaka(0);
    p2sdPlaySE(0);
}

// 0x1579090
void nbResultDrawPC1(s32 j, s32 x, s32 y, s32 cnt, datUnitWork_t *unit, s32 idx, nbMainProcessData_t *p) {
    rstCalcExpFromLevel(0, 0);
    rstCalcLevelFromExp(0, 0);
    nbResultLvupAnmAdd(0, 0);
    Set(0, 0);
    SetAnimator(0, 0, 0);
    frGetCNameString(0);
    Get(0);
}

// 0x157a570
s32 nbResultFinWaitChk(nbMainProcessData_t *p) {
  s32 v2;
  s64 i;
  u64 v5;
  struct typeNbResultWork_array *gnbResultWork;
  struct typeNbResultWork_array *v9;
  nbResultProcess_c *v11;
  struct nbResultProcess_StaticFields *static_fields;
  s32 gResultFinWait;

  v2 = 0;
  for (i = 4; i != 8; ++i)
  {
    v5 = i - 4;
    if (*(*(&gnbResultWork->obj.klass + i) + 16LL))
    {
      v9 = gnbResultWork;
      if ((*(*(&gnbResultWork->obj.klass + i) + 68LL)
          + *(*(*(&gnbResultWork->obj.klass + i) + 40LL) + 32LL)) > *(*(&v9->obj.klass + i) + 20LL))
        v2 = 1;
    }
  }
  if (!v2)
  {
    static_fields = v11->static_fields;
    gResultFinWait = static_fields->gResultFinWait;
    if (gResultFinWait <= 59)
    {
      static_fields->gResultFinWait = gResultFinWait + 1;
    }
  }
  return gResultFinWait;
}

// 0x1577d40
void nbResultLoad(void) {
    GetAddExp(0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
    SetAnimator(0, 0, 0);
}

// 0x1578ee0
void nbResultLvupAnmAdd(s32 x, s32 y) {
  s64 i;
  u64 v7;
  struct typeNbResultLvupAnmWork_array *gnbResultLvupAnmWork;
  struct typeNbResultLvupAnmWork_array *v11;
  struct typeNbResultLvupAnmWork_array *v13;
  struct typeNbResultLvupAnmWork_array *v15;
  struct typeNbResultLvupAnmWork_array *v17;

  for (i = 4; ; ++i)
  {
    v7 = i - 4;
    if (!*(*(&gnbResultLvupAnmWork->obj.klass + i) + 16LL))
      break;
    if (v7 >= 0x3F)
      return;
  }
  v11 = gnbResultLvupAnmWork;
  *(*(&v11->obj.klass + i) + 16LL) = 1;
  v13 = gnbResultLvupAnmWork;
  *(*(&v13->obj.klass + i) + 20LL) = x;
  v15 = gnbResultLvupAnmWork;
  *(*(&v15->obj.klass + i) + 24LL) = y;
  v17 = gnbResultLvupAnmWork;
  *(*(&v17->obj.klass + i) + 28LL) = 20;
}

// 0x1579080
void nbResultLvupAnmDraw(void) {
  ;
}

// 0x157cee0
void *nbResultProcess1(dds3ProcessID_t *id) {
  nbMainProcessData_t_o *MainProcessData;
  u64 *v7;

  MainProcessData = nbGetMainProcessData();
  ShutdownProcess();
  KakutokuExp = nbGetKakutokuExp(MainProcessData);
  AllExp = KakutokuExp;
  nbResultLoad();
  gResultFinWait = 0;
  gResultNowLoading = 0;
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_nbResultProcess_nbResultProcess2__);
  return v7;
}

// 0x157c420
void *nbResultProcess2(dds3ProcessID_t *id) {
    dds3GetProcessRunTime(0);
    dds3FadeIn2(0);
    dds3GetActiveScene();
    ClearStage();
    nbGetMainProcessData();
    fldLoadNextFile_BtlRet();
    Unlock_16599376(0);
    fldLoadNextTask();
    fldLoadNextGetStatus();
    ButtonGuideDispSet(0, 0, 0, 0);
    DDS3_PADCHECK_PRESS(0);
    nbResultFinWaitChk(0);
    dds3FadeOut(0, 0, 0, 0);
    nbResultSkip(0);
    nbResultDrawBG(0);
    nbResultAddExp();
    FadeoutBGM(0, 0);
    ClearResultUI();
    return 0;
}

// 0x157cfe0
void *nbResultShutdown(dds3ProcessID_t *id) {
  nbGetMainProcessData()->ResultProcessID = 0;
  hResultTex1 = 0;
  hResultTex2 = 0;
  hResultTex3 = 0;
  fldSkySetAlpha(0);
  ButtonGuideDispOff();
  return 0;
}

// 0x157a190
void nbResultSkip(nbMainProcessData_t *p) {
  u64 v3;
  s32 v4;
  struct typeNbResultWork_array *gnbResultWork;
  struct typeNbResultWork_array *v8;
  s32 unitidx;
  u32 exp_cnt;
  u8 v12;
  struct typeNbResultWork_array *v14;
  u8 v15;
  struct typeNbResultWork_array *v17;
  u8 v19;
  struct typeNbResultWork_array *v21;
  struct typeNbResultWork_array *v24;

  gResultUpAnimeCnt = 900;
  v3 = 0;
  v4 = 227;
  gResultSeFlag = 0;
  do
  {
    if (gnbResultWork->m_Items[v3]->useflg)
    {
      v8 = gnbResultWork;
      unitidx = v8->m_Items[v3]->unitidx;
      exp_cnt = gnbResultWork->m_Items[v3]->exp_cnt;
      v12 = rstCalcLevelFromExp(unitidx, exp_cnt);
      v14 = gnbResultWork;
      v15 = v12;
      v14->m_Items[v3]->exp_cnt = v14->m_Items[v3]->addexp
                                       + gnbResultWork->m_Items[v3]->unit->exp;
      v17 = gnbResultWork;
      v19 = rstCalcLevelFromExp(unitidx, v17->m_Items[v3]->exp_cnt);
      v21 = gnbResultWork;
      v21->m_Items[v3]->l_lv = v19;
      if (v19 > v15)
      {
        gResultSeFlag |= 2u;
        v24 = gnbResultWork;
        v24->m_Items[v3]->lvupflg = 1;
        nbResultLvupAnmAdd(317, v4);
      }
    }
    ++v3;
    v4 += 40;
  }
  while (v3 != 4);
  else  p2sdPlaySE(17);
  gResultSeFlag = 0;
}

// 0x1578e60
void nbResultTexDel(void) {
  hResultTex1 = 0;
  hResultTex2 = 0;
  hResultTex3 = 0;
}

// 0x157a780
void rDevilFrameOff(void) {
  UnityEngine_Object_o *oResult_UI;

  op_Inequality(oResult_UI, 0, 0);
}

// 0x157a770
void rDevilFrameOn(void) {
  ;
}

// 0x157aa40
void rItemOff(void) {
  UnityEngine_Object_o *oResult_UI;

  if (op_Inequality(oResult_UI, 0, 0))
  {
    if (get_activeSelf(brgetitem))
    {
      SetActive(brgetitem, 0, 0);
    }
  }
}

// 0x157a8d0
void rItemOn(void) {
  UnityEngine_Object_o *oResult_UI;

  if (op_Inequality(oResult_UI, 0, 0))
  {
    if (!get_activeSelf(brgetitem))
    {
      SetActive(brgetitem, 1, 0);
      SetAnimator(brgetitem, StringLiteral_21574, 1);
    }
  }
}
