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
static typeNbResultWork *gnbResultWork;
static typeNbResultLvupAnmWork *gnbResultLvupAnmWork;
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
      if (Contains(animkey, "brchara", 0))
      {
        if (animno == 2)
        {
          if (Integer == 2)
            Play_8777152(Component_object, "brchara_lvup", 0, 0.0);
        }
        else if (animno == 1)
        {
          if (Integer)
            return;
LABEL_19:
          SetInteger(Component_object, animkey, animno);
          return;
        }
      }
      if (Integer != animno)
        goto LABEL_19;
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
  nbResultProcess_c *v3;
  struct typeNbResultWork_array *gnbResultWork;
  struct typeNbResultLvupAnmWork_array *v27;
  nbResultProcess_c *v28;
  u64 v29;
  u32 *gnbResultLvupAnmWork;
  u64 *v31;
  u64 *v34;
  u64 *v35;
  dds3ProcessID_t_o *target;

  target = 0;
  if (!gnbResultWork)
    goto LABEL_11;
LABEL_6:
  if ((v3->_2.bitflags2 & 2) == 0)
    goto LABEL_45;
LABEL_7:
LABEL_45:
  if (gnbResultLvupAnmWork)
    goto LABEL_61;
LABEL_46:
  v27 = NewSpecific(typeNbResultLvupAnmWork, 0x40u);
  gnbResultLvupAnmWork = v27;
  v29 = 0;
  if ((v28->_2.bitflags2 & 2) != 0)
  {
LABEL_52:
    goto LABEL_54;
  }
  while (1)
  {
LABEL_54:
    v31 = Allocate(typeNbResultLvupAnmWork);
    _ctor(v31, 0);
    *&gnbResultLvupAnmWork[2 * v29 + 8] = v31;
    if (v29 == 63)
      break;
    ++v29;
      goto LABEL_52;
  }
LABEL_61:
  dds3FadeOut(0, 0, 0, 0);
  v34 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v34,
    0,
    Method_nbResultProcess_nbResultProcess1__);
  v35 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v35,
    0,
    Method_nbResultProcess_nbResultShutdown__);
  target = dds3StartProcess("nb_result", 0x3F9u, 1, 1, v34, 0, v35, 0, 0, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->ResultProcessID = target;
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
    goto LABEL_19;
  itemcnt = MainProcessData->itemcnt;
  if (itemcnt->m_Items[0])
  {
    v8 = MainProcessData->item;
    v9 = MainProcessData->itemcnt;
    v10 = v8->m_Items[0];
    v11 = v9->m_Items[0];
    datAddItem(v10, v11);
    v12 = v5->item;
    if ((v12->max_length & 0xFFFFFFFE) == 0)
    {
LABEL_33:
    }
  }
  else
  {
LABEL_19:
    v12 = MainProcessData->item;
    if ((v12->max_length & 0xFFFFFFFE) == 0)
      goto LABEL_33;
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
        goto LABEL_36;
LABEL_35:
    }
  }
  v22 = v5->item;
  if (LODWORD(v22->max_length) <= 2uLL)
    goto LABEL_35;
LABEL_36:
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
        goto LABEL_84;
      if (datCheckSyojiSkill(v52, 0x162u))
      {
        if (KakutokuExp >= 1)
        {
          KakutokuExp /= tbl->m_Items[66]->n;
        }
LABEL_84:
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
  u64 *v3;
  u64 *v4;
  u32 *v5;
  u32 *v7;
  nbMainProcessData_t_o *v9;
  nbMainProcessData_t_o *MainProcessData;
  u32 v13;
  u32 v14;
  struct System_Byte_array *item;
  struct System_Byte_array *v16;
  struct System_Byte_array *v17;
  s64 v27;
  struct System_Byte_array *v28;
  struct System_Byte_array *v29;
  struct System_Byte_array *v30;
  struct System_Byte_array *v31;
  s32 v32;
  struct System_Byte_array *itemcnt;
  s32 v34;
  s32 v42;
  struct System_Byte_array *v43;
  struct System_Byte_array *v45;
  struct System_Byte_array *v47;
  struct System_Byte_array *v49;
  s32 v51;
  struct System_Byte_array *v53;
  s32 v55;
  u64 v57;
  char v58;
  u64 v59;
  u32 *v60;
  UnityEngine_Transform_o *transform;
  u64 v63;
  UnityEngine_Transform_o *v64;
  u64 *v65;
  System_String_o *v66;
  UnityEngine_Component_o *v67;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v69;
  s32 v71;
  bool activeSelf;
  UnityEngine_Transform_o *v73;
  UnityEngine_Component_o *v74;
  UnityEngine_GameObject_o *v75;
  Il2CppObject *Component_object;
  s32 v79;
  System_String_o *v80;
  UnityEngine_Transform_o *v81;
  UnityEngine_Component_o *v82;
  UnityEngine_GameObject_o *v83;
  Il2CppObject *v84;
  s32 v86;
  struct nbResultProcess_StaticFields *static_fields;
  s32 gResultUpAnimeCnt;
  u64 v89;
  s32 v90;
  s32 v91;
  s64 v92;
  s64 v94;
  s64 v95;
  s64 v97;
  struct nbResultProcess_StaticFields *v100;
  UnityEngine_Transform_o *v101;
  UnityEngine_Component_o *v102;
  UnityEngine_GameObject_o *v103;
  Il2CppObject *v104;
  s32 KakutokuExp;
  UnityEngine_Transform_o *v106;
  UnityEngine_Component_o *v107;
  UnityEngine_GameObject_o *v108;
  Il2CppObject *v109;
  s32 KakutokuMaka;
  struct System_Byte_array *v111;
  s32 v112;
  struct System_Byte_array *v114;
  s32 v115;
  u32 *v117;
  UnityEngine_Color_o v120;
  UnityEngine_Color_o v121;
  nbMainProcessData_t_o *v122;

  v3 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v3);
  v4 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v4);
  v5 = NewSpecific(s32, 3u);
  v7 = NewSpecific(s32, 3u);
  MainProcessData = nbGetMainProcessData();
  ++gResultUpAnimeCnt;
  v13 = v5[6];
  v5[8] = 0;
  v5[9] = 0;
  v5[10] = 0;
  v14 = v7[6];
  v7[8] = 0;
  v7[9] = 0;
  v7[10] = 0;
  item = p->item;
  if (!item->m_Items[0])
    goto LABEL_31;
  v16 = p->item;
  if (v16->m_Items[0] < 0x40u)
    goto LABEL_38;
  v17 = p->item;
  if (v17->m_Items[0] >= 0x59u)
  {
LABEL_38:
    v31 = p->item;
    v32 = v31->m_Items[0];
    v5[8] = v32;
    itemcnt = p->itemcnt;
    v34 = itemcnt->m_Items[0];
    v27 = 1;
    v7[8] = v34;
    v28 = p->item;
    if ((v28->max_length & 0xFFFFFFFE) == 0)
    {
LABEL_44:
    }
  }
  else
  {
LABEL_31:
    v27 = 0;
    v28 = p->item;
    if ((v28->max_length & 0xFFFFFFFE) == 0)
      goto LABEL_44;
  }
  if (!v28->m_Items[1])
    goto LABEL_50;
  v29 = p->item;
  if (v29->m_Items[1] < 0x40u)
    goto LABEL_156;
  v30 = p->item;
  if (v30->m_Items[1] >= 0x59u)
  {
LABEL_156:
    v111 = p->item;
    v112 = v111->m_Items[1];
    v5[v27 + 8] = v112;
    v114 = p->itemcnt;
    v115 = v114->m_Items[1];
    v117 = &v7[v27];
    v27 = (v27 + 1);
    v117[8] = v115;
    v42 = 1;
    v43 = p->item;
    if (LODWORD(v43->max_length) <= 2uLL)
    {
LABEL_51:
    }
  }
  else
  {
LABEL_50:
    v42 = v27;
    v43 = p->item;
    if (LODWORD(v43->max_length) <= 2uLL)
      goto LABEL_51;
  }
  if (v43->m_Items[2])
  {
    v45 = p->item;
    if (v45->m_Items[2] < 0x40u)
      goto LABEL_59;
    v47 = p->item;
    if (v47->m_Items[2] >= 0x59u)
    {
LABEL_59:
      v49 = p->item;
      v51 = v49->m_Items[2];
      v5[v27 + 8] = v51;
      v53 = p->itemcnt;
      v55 = v53->m_Items[2];
      v7[v27 + 8] = v55;
      v42 = 1;
    }
  }
  if (v42 && *(*(v57 + 184) + 80LL) >= 9)
  {
    v58 = *(v57 + 295);
    v122 = MainProcessData;
    rItemOn(v57);
    v59 = 0;
    v60 = v5 + 8;
    do
    {
      while (1)
      {
        transform = get_transform(brgetitem, 0);
        v63 = v59 + 1;
        LODWORD(v121.r) = v59 + 1;
        v64 = transform;
        v65 = sub_8D3950(s32, &v121);
        v66 = Concat("brget_item0", v65);
        v67 = Find(v64, v66, 0);
        gameObject = get_gameObject(v67);
        v69 = gameObject;
        v71 = v60[v59];
        activeSelf = get_activeSelf(gameObject);
        if (!v71)
          break;
        if (!activeSelf)
          SetActive(v69, 1, 0);
        v73 = get_transform(v69, 0);
        v74 = Find(v73, "TextTM", 0);
        v75 = get_gameObject(v74);
        Component_object = GetComponent_object_(v75);
        v79 = v60[v59];
        v80 = Get(v79, 0);
        set_text(Component_object, v80);
        v81 = get_transform(v69, 0);
        v82 = Find(v81, "num_exp", 0);
        v83 = get_gameObject(v82);
        v84 = GetComponent_object_(v83);
        v86 = v7[v59 + 8];
        *&v121.r = 0;
        *&v121.b = 0;
        sub_19EC630(&v121.r, 1.0, 1.0, 1.0, 1.0);
        Set(v84, v86, v121, 0, 0);
        ++v59;
        if (v63 == 3)
          goto LABEL_97;
      }
      if (activeSelf)
        SetActive(v69, 0, 0);
      ++v59;
    }
    while (v63 != 3);
LABEL_97:
    MainProcessData = v122;
  }
  *(*(v57 + 184) + 100LL) = 0;
  static_fields = *(v57 + 184);
  if (gResultUpAnimeCnt >= 21)
  {
    v89 = 0;
    v90 = -20;
    v91 = 208;
    gResultDoAnimeCnt = gResultUpAnimeCnt - 55;
    if ((*(v57 + 295) & 2) != 0)
    {
LABEL_106:
      goto LABEL_109;
    }
    while (1)
    {
LABEL_109:
      v92 = *(*(v57 + 184) + 112LL);
      if (*(*(v92 + 8 * v89 + 32) + 16LL))
      {
        v94 = *(v57 + 184);
        v95 = *(v94 + 112);
        nbResultDrawPC1(
          v89,
          63,
          v91,
          v90 + *(v94 + 80),
          *(*(v95 + 8 * v89 + 32) + 40LL),
          *(*(v95 + 8 * v89 + 32) + 32LL),
          v9);
        if (v89 == 3)
        {
LABEL_132:
          break;
        }
      }
      else
      {
        v97 = *(*(v57 + 184) + 112LL);
        if (*(*(v97 + 8 * v89 + 32) + 16LL))
        {
          if (v89 == 3)
            goto LABEL_132;
        }
        {
          rDevilFrameOff();
          if (v89 == 3)
            goto LABEL_132;
        }
        else
        {
          rDevilFrameOff(nbResultProcess);
          if (v89 == 3)
            goto LABEL_132;
        }
      }
      ++v89;
      v90 -= 6;
      v91 += 40;
        goto LABEL_106;
    }
  }
  v100 = *(v57 + 184);
  if (gResultUpAnimeCnt >= 1)
  {
    v101 = get_transform(brgetexp, 0);
    v102 = Find(v101, "brget_exp/britem_base/num_exp", 0);
    v103 = get_gameObject(v102);
    v104 = GetComponent_object_(v103);
    KakutokuExp = nbGetKakutokuExp(MainProcessData);
    *&v121.r = 0;
    *&v121.b = 0;
    sub_19EC630(&v121.r, 1.0, 1.0, 1.0, 1.0);
    Set(v104, KakutokuExp, v121, 0, 0);
    v106 = get_transform(brgetexp, 0);
    v107 = Find(v106, "brget_makka/britem_base/num_exp", 0);
    v108 = get_gameObject(v107);
    v109 = GetComponent_object_(v108);
    KakutokuMaka = nbGetKakutokuMaka(MainProcessData);
    *&v120.r = 0;
    *&v120.b = 0;
    sub_19EC630(&v120.r, 1.0, 1.0, 1.0, 1.0);
    Set(v109, KakutokuMaka, v120, 0, 0);
  }
  if ((*(v57 + 295) & 2) != 0 && !*(v57 + 216))
  {
    if ((gResultSeFlag & 1) == 0)
      goto LABEL_148;
  }
  else if ((*(*(v57 + 184) + 100LL) & 1) == 0)
  {
    goto LABEL_148;
  }
  p2sdPlaySE(5);
LABEL_148:
  if ((*(v57 + 295) & 2) != 0 && !*(v57 + 216))
  {
    if ((gResultSeFlag & 2) == 0)
      return;
  }
  else if ((*(*(v57 + 184) + 100LL) & 2) == 0)
  {
    return;
  }
  p2sdPlaySE(17);
}

// 0x1579090
void nbResultDrawPC1(s32 j, s32 x, s32 y, s32 cnt, datUnitWork_t *unit, s32 idx, nbMainProcessData_t *p) {
  u8 v8;
  struct typeNbResultWork_array *gnbResultWork;
  struct typeNbResultWork_array *v20;
  typeNbResultWork_o *v22;
  struct UnityEngine_GameObject_array *brparty;
  struct typeNbResultWork_array *v27;
  u64 v29;
  struct typeNbResultWork_array *v33;
  struct typeNbResultWork_array *v36;
  u32 max_length;
  struct UnityEngine_GameObject_array *v39;
  typeNbResultWork_o *v42;
  struct typeNbResultWork_array *v44;
  struct typeNbResultWork_array *v47;
  struct typeNbResultWork_array *v49;
  struct typeNbResultWork_array *v52;
  struct typeNbResultWork_array *v54;
  struct typeNbResultWork_array *v57;
  struct typeNbResultWork_array *v59;
  struct typeNbResultWork_array *v62;
  s32 l_lv;
  u32 v65;
  struct typeNbResultWork_array *v66;
  u32 v67;
  u32 v69;
  struct typeNbResultWork_array *v70;
  u32 v71;
  s32 exp_cnt;
  u8 v74;
  struct typeNbResultWork_array *v77;
  s32 v78;
  struct typeNbResultWork_array *v81;
  struct typeNbResultWork_array *v83;
  struct typeNbResultWork_array *v85;
  struct typeNbResultWork_array *v87;
  struct typeNbResultWork_array *v89;
  UnityEngine_GameObject_o *v92;
  struct typeNbResultWork_array *v93;
  struct typeNbResultWork_array *v96;
  struct typeNbResultWork_array *v98;
  struct typeNbResultWork_array *v101;
  struct typeNbResultWork_array *v104;
  s32 v106;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v108;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  struct typeNbResultWork_array *v113;
  struct typeNbResultWork_array *v116;
  s32 v118;
  UnityEngine_Transform_o *v121;
  UnityEngine_Component_o *v122;
  UnityEngine_GameObject_o *v123;
  Il2CppObject *v124;
  u64 *v125;
  System_String_o *v126;
  System_String_o *v128;
  UnityEngine_Transform_o *v130;
  UnityEngine_Component_o *v131;
  UnityEngine_GameObject_o *v132;
  Il2CppObject *v133;
  f32 v134;
  f32 fillAmount;
  struct typeNbResultWork_array *v139;
  nbResultProcess_c *v141;
  struct typeNbResultWork_array *v142;
  struct typeNbResultWork_array *v144;
  UnityEngine_Transform_o *v147;
  UnityEngine_Component_o *v148;
  UnityEngine_GameObject_o *v149;
  Il2CppObject *v151;
  s32 id;
  System_String_o *CNameString;
  datUnitWork_t_o *v154;
  UnityEngine_GameObject_o *obj;
  UnityEngine_Color_o v156;
  s32 v157;

  v8 = idx;
  ++barname;
  if (barname == 5)
  {
    barname = 1;
  }
  if (gnbResultWork->m_Items[j]->stopcnt >= 1)
  {
    v20 = gnbResultWork;
    v22 = v20->m_Items[j];
    --v22->stopcnt;
  }
  if (cnt >= 1)
  {
    obj = brparty->m_Items[j];
    v27 = gnbResultWork;
    v29 = 96207267450LL * gnbResultWork->m_Items[j]->ofsx;
    v27->m_Items[j]->ofsx = (v29 >> 63) + (SHIDWORD(v29) >> 5);
    if (skipFlag)
    {
      if (cnt < 13)
        return;
LABEL_37:
      v154 = unit;
      if (gResultDoAnimeCnt >= 1)
      {
        v33 = gnbResultWork;
        if (!v33->m_Items[j]->stopcnt)
        {
          v36 = gnbResultWork;
          max_length = v36->max_length;
          v42 = v36->m_Items[j];
          v42->exp_cnt += gnbResultWork->m_Items[j]->resultadd;
          v44 = gnbResultWork;
          if ((v44->m_Items[j]->addexp + v154->exp) > v44->m_Items[j]->exp_cnt)
          {
            gResultSeFlag |= 1u;
            {
LABEL_84:
              v49 = gnbResultWork;
              if (v49->m_Items[j]->lvupanmflg)
              {
                v52 = gnbResultWork;
                ++v52->m_Items[j]->lvupanmcnt;
                v54 = gnbResultWork;
                if (v54->m_Items[j]->lvupanmcnt >= 16)
                {
                  v57 = gnbResultWork;
                  v57->m_Items[j]->lvupanmflg = 0;
                  v59 = gnbResultWork;
                  v59->m_Items[j]->lvupanmcnt = 0;
                }
              }
              v62 = gnbResultWork;
              l_lv = v62->m_Items[j]->l_lv;
              v65 = rstCalcExpFromLevel(v8, l_lv);
              v66 = gnbResultWork;
              v67 = v65;
              v69 = rstCalcExpFromLevel(v8, v66->m_Items[j]->l_lv + 1);
              v70 = gnbResultWork;
              v71 = v69;
              exp_cnt = v70->m_Items[j]->exp_cnt;
              v74 = rstCalcLevelFromExp(v8, gnbResultWork->m_Items[j]->exp_cnt);
              v77 = gnbResultWork;
              v78 = v74;
              if (v77->m_Items[j]->l_lv < v74)
              {
                gResultSeFlag |= 2u;
                v81 = gnbResultWork;
                v81->m_Items[j]->lvupflg = 1;
                v83 = gnbResultWork;
                v83->m_Items[j]->l_lv = v78;
                v85 = gnbResultWork;
                v85->m_Items[j]->stopcnt = 15;
                v87 = gnbResultWork;
                v87->m_Items[j]->lvupanmflg = 1;
                v89 = gnbResultWork;
                v89->m_Items[j]->lvupanmcnt = 0;
                nbResultLvupAnmAdd(x + 254, y + 19);
              }
              {
                v92 = obj;
              }
              else
              {
                v92 = obj;
              }
              v93 = gnbResultWork;
              if (v93->m_Items[j]->lvupflg)
              {
                v96 = gnbResultWork;
                ++v96->m_Items[j]->lvuplvanmcnt;
                v98 = gnbResultWork;
                if (v98->m_Items[j]->lvuplvanmcnt >= 9)
                {
                  v101 = gnbResultWork;
                  v101->m_Items[j]->lvuplvanmcnt = 8;
                }
              }
              v104 = gnbResultWork;
              if (v104->m_Items[j]->l_lv >= 99)
                v106 = 99;
              else
                v106 = v104->m_Items[j]->l_lv;
              transform = get_transform(v92, 0);
              v108 = Find(transform, "num_lv", 0);
              gameObject = get_gameObject(v108);
              Component_object = GetComponent_object_(gameObject);
              *&v156.r = 0;
              *&v156.b = 0;
              sub_19EC630(&v156.r, 1.0, 1.0, 1.0, 1.0);
              Set(Component_object, v106, v156, 0, 0);
              v113 = gnbResultWork;
              if (v113->m_Items[j]->lvupanmflg)
              {
                v116 = gnbResultWork;
                if (v116->m_Items[j]->lvupanmcnt < 6)
                {
                  v118 = 0;
LABEL_180:
                  v121 = get_transform(v92, 0);
                  v122 = Find(v121, "num_nextexp", 0);
                  v123 = get_gameObject(v122);
                  v124 = GetComponent_object_(v123);
                  *&v156.r = 0;
                  *&v156.b = 0;
                  sub_19EC630(&v156.r, 1.0, 1.0, 1.0, 1.0);
                  Set(v124, v118, v156, 0, 0);
                  v157 = j + 1;
                  v125 = sub_8D3950(s32, &v157);
                  v126 = Format("brchara{0:00}/brexpbar/brexpbar_color", v125, 0);
                  v128 = Concat_5224608("brparty/", v126);
                  v130 = get_transform(oResult_UI, 0);
                  v131 = Find(v130, v128, 0);
                  v132 = get_gameObject(v131);
                  v133 = GetComponent_object_(v132);
                  v134 = (exp_cnt - v67) / (v71 - v67);
                  fillAmount = get_fillAmount(v133);
                  set_fillAmount(v133, v134);
                  if (v134 < 0.015)
                    set_fillAmount(v133, 0.015);
                  if (get_fillAmount(v133) < fillAmount)
                  {
                    {
                    }
                    SetAnimator(v92, "brchara", 2);
                  }
                  v139 = gnbResultWork;
                  if (!v139->m_Items[j]->lvupanmflg)
                    goto LABEL_215;
                  v142 = gnbResultWork;
                  if (v142->m_Items[j]->lvupanmcnt <= 1)
                  {
                    if ((*&v141->_2.bitflags1 & 0x200) == 0)
                      goto LABEL_213;
                  }
                  else
                  {
                    v144 = gnbResultWork;
                    if (v144->m_Items[j]->lvupanmcnt < 11)
                      goto LABEL_215;
                    {
LABEL_213:
LABEL_215:
                      v147 = get_transform(v92, 0);
                      v148 = Find(v147, "TextTM", 0);
                      v149 = get_gameObject(v148);
                      v151 = GetComponent_object_(v149);
                      if ((v154->flag & 4) != 0)
                      {
                        CNameString = frGetCNameString(0);
                      }
                      else
                      {
                        id = v154->id;
                        CNameString = Get(id, 0);
                      }
                      set_text(v151, CNameString);
                      return;
                    }
                  }
                  goto LABEL_213;
                }
              }
              v118 = v71 - exp_cnt;
              goto LABEL_180;
            }
LABEL_82:
            goto LABEL_84;
          }
          v47 = gnbResultWork;
          v47->m_Items[j]->exp_cnt = gnbResultWork->m_Items[j]->addexp
                                          + v154->exp;
          if (!skipFlag)
          {
            SetAnimator(obj, "brchara", 3, *&cnt);
          }
        }
      }
        goto LABEL_84;
      goto LABEL_82;
    }
    v39 = brparty;
    SetAnimator(v39->m_Items[j], "brchara", 1, *&cnt);
    if (cnt >= 13)
      goto LABEL_37;
  }
}

// 0x157a570
s32 nbResultFinWaitChk(nbMainProcessData_t *p) {
  s32 v2;
  s64 i;
  u64 v5;
  struct typeNbResultWork_array *gnbResultWork;
  struct typeNbResultWork_array *v9;
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
    if (gResultFinWait <= 59)
    {
      gResultFinWait = gResultFinWait + 1;
    }
  }
  return gResultFinWait;
}

// 0x1577d40
void nbResultLoad(void) {
  nbResultProcess_c *v3;
  u64 v4;
  struct typeNbResultWork_array *gnbResultWork;
  struct typeNbResultWork_array *v7;
  struct typeNbResultWork_array *v9;
  struct typeNbResultWork_array *v11;
  struct typeNbResultWork_array *v13;
  struct typeNbResultWork_array *v15;
  struct typeNbResultWork_array *v17;
  struct typeNbResultWork_array *v19;
  struct typeNbResultWork_array *v21;
  struct typeNbResultWork_array *v23;
  struct typeNbResultWork_array *v25;
  u64 v27;
  s32 v28;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Int32_array *stocklist;
  struct datUnitWork_t_array *unitwork;
  s32 v34;
  struct datUnitWork_t_array *v37;
  struct typeNbResultWork_array *v40;
  struct typeNbResultWork_array *v42;
  typeNbResultWork_o *v45;
  struct datUnitWork_t_array *v46;
  struct typeNbResultWork_array *v48;
  typeNbResultWork_o *v50;
  struct datUnitWork_t_array *v51;
  struct typeNbResultWork_array *v54;
  struct typeNbResultWork_array *v56;
  struct typeNbResultWork_array *v58;
  typeNbResultWork_o *v60;
  struct datUnitWork_t_array *v61;
  struct typeNbResultWork_array *v64;
  struct typeNbResultWork_array *v66;
  struct typeNbResultWork_array *v68;
  struct typeNbResultWork_array *v70;
  struct typeNbResultWork_array *v73;
  typeNbResultWork_o *v75;
  struct typeNbResultWork_array *v77;
  struct typeNbResultWork_array *v79;
  struct typeNbResultWork_array *v82;
  typeNbResultWork_o *v84;
  struct typeNbResultWork_array *v86;
  s32 v88;
  bool v89;
  struct typeNbResultWork_array *v91;
  s64 i;
  u64 v95;
  struct typeNbResultLvupAnmWork_array *gnbResultLvupAnmWork;
  struct typeNbResultLvupAnmWork_array *v98;
  struct typeNbResultLvupAnmWork_array *v100;
  struct typeNbResultLvupAnmWork_array *v102;
  s64 v104;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v107;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v111;
  UnityEngine_Transform_o *v113;
  UnityEngine_Component_o *v114;
  struct UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v118;
  UnityEngine_Component_o *v119;
  struct UnityEngine_GameObject_o *v120;
  UnityEngine_Transform_o *v123;
  UnityEngine_Component_o *v124;
  struct UnityEngine_GameObject_o *v125;
  struct UnityEngine_GameObject_array *v127;
  struct UnityEngine_GameObject_array *brparty;
  UnityEngine_Transform_o *v131;
  UnityEngine_Component_o *v132;
  s64 *v133;
  s64 *v134;
  struct UnityEngine_GameObject_array *v137;
  UnityEngine_Transform_o *v138;
  UnityEngine_Component_o *v139;
  s64 *v140;
  s64 *v141;
  struct UnityEngine_GameObject_array *v144;
  UnityEngine_Transform_o *v145;
  UnityEngine_Component_o *v146;
  s64 *v147;
  s64 *v148;
  struct UnityEngine_GameObject_array *v151;
  UnityEngine_Transform_o *v152;
  UnityEngine_Component_o *v153;
  s64 *v154;
  s64 *v156;
  s64 j;
  u64 v160;
  struct UnityEngine_GameObject_array *v161;
  struct UnityEngine_GameObject_array *v164;
  struct UnityEngine_GameObject_array *v166;

  gResultUpAnimeCnt = 0;
  gResultDoAnimeCnt = 0;
  v4 = 0;
  gResultQuitCnt = 0;
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
    goto LABEL_11;
  }
  while (1)
  {
LABEL_11:
    gnbResultWork->m_Items[v4]->useflg = 0;
    v7 = gnbResultWork;
    v7->m_Items[v4]->exp_cnt = 0;
    v9 = gnbResultWork;
    v9->m_Items[v4]->l_lv = 0;
    v11 = gnbResultWork;
    v11->m_Items[v4]->lvupflg = 0;
    v13 = gnbResultWork;
    v13->m_Items[v4]->unitidx = 0;
    v15 = gnbResultWork;
    v15->m_Items[v4]->unit = 0;
    v17 = gnbResultWork;
    v17->m_Items[v4]->lvupanmflg = 0;
    v19 = gnbResultWork;
    v19->m_Items[v4]->lvupanmcnt = 0;
    v21 = gnbResultWork;
    v21->m_Items[v4]->lvuplvanmcnt = 0;
    v23 = gnbResultWork;
    v23->m_Items[v4]->ofsx = 0;
    v25 = gnbResultWork;
    v25->m_Items[v4]->stopcnt = 0;
    if (v4 == 3)
      break;
    ++v4;
      goto LABEL_9;
  }
  v27 = 0;
  v28 = 0;
    goto LABEL_39;
LABEL_37:
LABEL_39:
  while (1)
  {
    if (v27 >= DDS3_GBWK->stockcnt)
      break;
    else
    {
      stocklist = DDS3_GBWK->stocklist;
      if (v27 >= LODWORD(stocklist->max_length))
        goto LABEL_43;
    }
    unitwork = DDS3_GBWK->unitwork;
    v34 = stocklist->m_Items[v27];
    if ((unitwork->m_Items[v34]->flag & 1) != 0)
    {
      v37 = DDS3_GBWK->unitwork;
      if ((v37->m_Items[v34]->flag & 2) != 0)
      {
        v40 = gnbResultWork;
        v40->m_Items[v28]->useflg = 1;
        v42 = gnbResultWork;
        v45 = v42->m_Items[v28];
        v46 = DDS3_GBWK->unitwork;
        v45->exp_cnt = v46->m_Items[v34]->exp;
        v48 = gnbResultWork;
        v50 = v48->m_Items[v28];
        v51 = DDS3_GBWK->unitwork;
        v50->l_lv = v51->m_Items[v34]->level;
        v54 = gnbResultWork;
        v54->m_Items[v28]->lvupflg = 0;
        v56 = gnbResultWork;
        v56->m_Items[v28]->unitidx = v34;
        v58 = gnbResultWork;
        v60 = v58->m_Items[v28];
        v61 = DDS3_GBWK->unitwork;
        v60->unit = v61->m_Items[v34];
        v64 = gnbResultWork;
        v64->m_Items[v28]->lvupanmflg = 0;
        v66 = gnbResultWork;
        v66->m_Items[v28]->lvupanmcnt = 0;
        v68 = gnbResultWork;
        v68->m_Items[v28]->lvuplvanmcnt = 0;
        v70 = gnbResultWork;
        v70->m_Items[v28]->ofsx = 192;
        v73 = gnbResultWork;
        v75 = v73->m_Items[v28];
        v75->addexp = GetAddExp(v34, AllExp);
        v77 = gnbResultWork;
        v77->m_Items[v28]->resultadd = gnbResultWork->m_Items[v28]->addexp
                                            / 45;
        v79 = gnbResultWork;
        if (v79->m_Items[v28]->addexp % 45 >= 1)
        {
          v82 = gnbResultWork;
          v84 = v82->m_Items[v28];
          ++v84->resultadd;
        }
        v86 = gnbResultWork;
        if (v86->m_Items[v28]->resultadd <= 0)
        {
          v91 = gnbResultWork;
          v91->m_Items[v28]->resultadd = 1;
          v88 = v28 + 1;
          v89 = v28++ <= 2;
          if (!v89)
            goto LABEL_117;
        }
        else
        {
          v88 = v28 + 1;
          v89 = v28++ <= 2;
          if (!v89)
            goto LABEL_117;
        }
      }
    }
    ++v27;
      goto LABEL_37;
  }
  v88 = v28;
LABEL_117:
  for (i = 4; i != 68; ++i)
  {
    v95 = i - 4;
    *(*(&gnbResultLvupAnmWork->obj.klass + i) + 16LL) = 0;
    v98 = gnbResultLvupAnmWork;
    *(*(&v98->obj.klass + i) + 20LL) = 0;
    v100 = gnbResultLvupAnmWork;
    *(*(&v100->obj.klass + i) + 24LL) = 0;
    v102 = gnbResultLvupAnmWork;
    v104 = *(&v102->obj.klass + i);
    *(v104 + 28) = 0;
  }
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", "dds3data/UI", "resultUI");
  v107 = Find("Canvas_UI", 0);
  transform = get_transform(v107, 0);
  v111 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  oResult_UI = v111;
  AddComponent_object_(oResult_UI);
  v113 = get_transform(oResult_UI, 0);
  v114 = Find(v113, "brtitle", 0);
  gameObject = get_gameObject(v114);
  brtitle = gameObject;
  SetAnimator(brtitle, "brtitle", 0);
  v118 = get_transform(oResult_UI, 0);
  v119 = Find(v118, "brgetexp", 0);
  v120 = get_gameObject(v119);
  brgetexp = v120;
  SetAnimator(brgetexp, "brgetexp", 1);
  v123 = get_transform(oResult_UI, 0);
  v124 = Find(v123, "brgetitem", 0);
  v125 = get_gameObject(v124);
  brgetitem = v125;
  SetActive(brgetitem, 0, 0);
  v127 = NewSpecific(UnityEngine_GameObject, 4u);
  brparty = v127;
  v131 = get_transform(oResult_UI, 0);
  v132 = Find(v131, "brparty/brchara01", 0);
  v133 = get_gameObject(v132);
  v134 = v133;
  brparty->m_Items[0] = v134;
  v137 = brparty;
  v138 = get_transform(oResult_UI, 0);
  v139 = Find(v138, "brparty/brchara02", 0);
  v140 = get_gameObject(v139);
  v141 = v140;
  v137->m_Items[1] = v141;
  v144 = brparty;
  v145 = get_transform(oResult_UI, 0);
  v146 = Find(v145, "brparty/brchara03", 0);
  v147 = get_gameObject(v146);
  v148 = v147;
  v144->m_Items[2] = v148;
  v151 = brparty;
  v152 = get_transform(oResult_UI, 0);
  v153 = Find(v152, "brparty/brchara04", 0);
  v154 = get_gameObject(v153);
  v156 = v154;
  v151->m_Items[3] = v156;
  for (j = 4; j != 8; ++j)
  {
    while (1)
    {
      v160 = j - 4;
      if (j - 4 >= v88)
        break;
      v161 = brparty;
      SetActive(*(&v161->obj.klass + j), 1, 0);
      v164 = brparty;
      SetAnimator(*(&v164->obj.klass + j++), "brchara", 0);
      if (j == 8)
        return;
    }
    v166 = brparty;
    SetActive(*(&v166->obj.klass + j), 0, 0);
  }
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
  nbMainProcessData_t_o *MainProcessData;
  s32 NextFile_BtlRet;
  s64 *achievementTbl;
  System_String_o *v12;
  nbResultProcess_c *v18;
  nbMainProcessData_t_o *v23;
  u64 v27;
  s64 i;
  u64 v29;
  s64 v30;
  Il2CppObject *Component_object;
  u32 Integer;
  struct typeNbResultWork_array *gnbResultWork;
  System_String_o *v36;
  UnityEngine_Animator_o *v37;
  s32 v38;
  struct nbResultProcess_StaticFields *v39;
  s32 gResultQuitCnt;
  struct nbResultProcess_StaticFields *v41;
  System_String_o *bgmno;
  dds3ProcessID_t_o *ida;

  ida = id;
  if (dds3GetProcessRunTime(&ida) == 2)
  {
    dds3FadeIn2(0xAu);
  }
  if (dds3GetProcessRunTime(&ida) >= 0x10)
  {
    if (dds3GetActiveScene())
    {
      ClearStage();
    }
  }
  MainProcessData = nbGetMainProcessData();
  if (dds3GetProcessRunTime(&ida) == 20)
  {
    NextFile_BtlRet = fldLoadNextFile_BtlRet();
    gResultNowLoading = NextFile_BtlRet;
    achievementTbl = get_achievementTbl();
    v12 = sub_B7950(0xDu, DefineAchievementID_string_, achievementTbl);
    Unlock_16599376(v12);
  }
  if (gResultNowLoading)
  {
    fldLoadNextTask();
    if (!fldLoadNextGetStatus())
    {
      gResultNowLoading = 0;
      Write("pac1 done\n", 0);
    }
  }
  ButtonGuideDispSet("RSLT01", 0, 0, 90);
  if (dds3GetProcessRunTime(&ida) >= 0x15)
  {
    else if (DDS3_PADCHECK_PRESS(1))
    {
      goto LABEL_76;
    }
    if (!DDS3_PADCHECK_PRESS(3))
    {
        goto LABEL_80;
LABEL_67:
LABEL_80:
      if (nbResultFinWaitChk(v18) < 15)
        goto LABEL_101;
      goto LABEL_81;
    }
LABEL_76:
    nbResultSkip(v23);
    skipFlag = 1;
      goto LABEL_80;
    goto LABEL_67;
  }
  skipFlag = 0;
  {
LABEL_102:
  }
LABEL_104:
  nbResultDrawBG(MainProcessData);
  if (skipFlag == 1)
  {
    for (i = 4; i != 8; ++i)
    {
      while (1)
      {
        v29 = i - 4;
        v30 = *(*(v27 + 184) + 168LL);
        Component_object = GetComponent_object_(
                             *(v30 + 8 * i));
        Integer = GetInteger(Component_object, "brchara");
        if (!*(*(&gnbResultWork->obj.klass + i) + 28LL))
          break;
        if (Integer == 1)
        {
          SetInteger(Component_object, "brchara", 5);
          Play_8777152(Component_object, "brchara_OnlyLvupMoji", 0, 0.0);
          if (++i == 8)
            goto LABEL_124;
        }
        else
        {
          if (Integer)
            goto LABEL_120;
          v36 = "brchara";
          v37 = Component_object;
          v38 = 5;
LABEL_123:
          SetInteger(v37, v36, v38);
          if (++i == 8)
            goto LABEL_124;
        }
      }
      if (Integer <= 1)
      {
        v36 = "brchara";
        v37 = Component_object;
        v38 = 4;
        goto LABEL_123;
      }
LABEL_120:
    }
  }
LABEL_124:
  v39 = *(v27 + 184);
  if (gResultQuitCnt >= 1)
  {
    if (gResultQuitCnt <= 99)
    {
      gResultQuitCnt = gResultQuitCnt + 1;
    }
    v41 = *(v27 + 184);
    if (gResultQuitCnt >= 16)
    {
      if (!gResultNowLoading)
      {
        nbResultAddExp(v27);
        FadeoutBGM(bgmno, 1.0);
        ++LODWORD(v46[2].klass->_1.gc_desc);
        ida->func_ans = -1;
        ClearResultUI();
        skipFlag = 0;
      }
    }
  }
  return 0;
}

// 0x157cfe0
void *nbResultShutdown(dds3ProcessID_t *id) {
  nbGetMainProcessData()->ResultProcessID = 0;
LABEL_10:
  hResultTex1 = 0;
  hResultTex2 = 0;
  hResultTex3 = 0;
LABEL_17:
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
  else if ((gResultSeFlag & 2) == 0)
  {
    goto LABEL_42;
  }
  p2sdPlaySE(17);
LABEL_42:
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

LABEL_7:
  op_Inequality(oResult_UI, 0, 0);
}

// 0x157a770
void rDevilFrameOn(void) {
  ;
}

// 0x157aa40
void rItemOff(void) {
  UnityEngine_Object_o *oResult_UI;

LABEL_7:
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

LABEL_7:
  if (op_Inequality(oResult_UI, 0, 0))
  {
    if (!get_activeSelf(brgetitem))
    {
      SetActive(brgetitem, 1, 0);
      SetAnimator(brgetitem, "brgetitem", 1);
    }
  }
}
