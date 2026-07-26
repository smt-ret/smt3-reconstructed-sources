#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbCommSelProcessData_t nbCommSelProcessData_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 r_a[6];
static s32 wait_se2;
static bool bComFlag;
static s32 bComOffTime;
static s32 nbCommSelGameCnt;

void AnimeCommandList(nbCommSelProcessData_t **s);
s32 CheckSelectError(nbCommSelProcessData_t **s);
char *CutAF_DEL(char *message);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void DispComm1Comm(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2);
void DispComm1Item(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2);
void DispComm1PanelCursor(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, s32 oz, u32 col);
void DispComm1Summon(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2);
void DispComm1Talk(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2);
void DispCommandList2(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, s32 a);
void DispCommandPanel(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, s32 a);
void DispHelp1(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, s32 a);
void DispPanelCursor(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, u32 c);
void DispPanelLabel(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, u32 c);
u8 Get(s32 id);
void *GetBattleUI(s32 index);
void *GetComList(s32 listidx);
void *GetComListS(s32 listidx);
void *GetComTextTM(void *ComListObj);
nbCommSelProcessData_t *GetCommSelProcessData(void);
s32 GetNextCommType(nbCommSelProcessData_t **s, s32 dir);
char *GetStr(s32 no);
s32 GetTabMaxCount(nbCommSelProcessData_t *s);
f32 HPMPBarAdjustment(f32 bar, f32 maxbar, f32 limit);
nbCommSelProcessData_t *InitCommSelProcessData(nbMainProcessData_t *data, nbParty_t *my, nbActionProcessData_t *act);
void MemoryCommand(nbCommSelProcessData_t **s);
char *RepColTag(char *txt, void **LegacyParamArray);
void ResetSummonCommandSteffUIs(void *commandObj);
void SelectCommandList(nbCommSelProcessData_t **s);
void SelectCommandListAuto(nbCommSelProcessData_t **s);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetCommCursor2(nbCommSelProcessData_t **s);
void SetCommList(nbCommSelProcessData_t **s, nbParty_t *my);
void SetPrevCursor(nbCommSelProcessData_t **s, s32 type, s32 ind);
void bComOff(void);
void bComOffExec(void);
void bComOn(void);
s32 datGetSkillCost(datUnitWork_t *w, s32 nskill);
s32 dds3CheckConfigBit(u32 Type);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
char *frwGetHelpForUnity(s32 X, s32 Y, u32 Z, s8 HelpType, u16 HelpID, s8 DrawMode);
s32 nbCheckSkillCost(s32 formindex, s32 nskill);
void nbCommSelProcessData_t__Clear(nbCommSelProcessData_t *this);
s32 nbGetEscapeSwitch(nbMainProcessData_t *data);
s32 nbGetRandamStock(void);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbPanelHPColor(datUnitWork_t *pUnitWork);
s32 nbPanelMPColor(datUnitWork_t *pUnitWork);
void nbPlaySe(s32 no);

// 0x16de7d0
void AnimeCommandList(nbCommSelProcessData_t **s) {
  nbCommSelProcessData_t_o *v2;
  s32 helpa;
  nbCommSelProcessData_t_o *v4;
  u32 animeflag;
  s32 alpha;
  nbCommSelProcessData_t_o *v7;
  u32 v8;
  s32 v9;
  nbCommSelProcessData_t_o *v10;
  u32 v11;
  s32 ox;
  s32 v13;
  nbCommSelProcessData_t_o *v14;
  s32 openwait;
  bool v16;

  v2 = *s;
  helpa = (*s)->helpa;
  if (((*s)->animeflag & 0x20) != 0)
  {
    if (helpa <= 127)
    {
      v2->helpa = helpa + 32;
      if ((*s)->helpa >= 129)
        (*s)->helpa = 128;
    }
    v4 = *s;
    animeflag = (*s)->animeflag;
    if ((animeflag & 1) == 0)
  }
  if (helpa < 1)
  v2->helpa = helpa - 21;
  if (((*s)->helpa & 0x80000000) == 0)
  (*s)->helpa = 0;
  v4 = *s;
  animeflag = (*s)->animeflag;
  if ((animeflag & 1) == 0)
  alpha = v4->alpha;
  if (alpha != 128)
  {
    v4->alpha = alpha + 20;
    if ((*s)->alpha >= 129)
      (*s)->alpha = 128;
    v7 = *s;
    v8 = (*s)->animeflag;
    if ((v8 & 2) == 0)
  }
  v4->animeflag = animeflag & 0xFFFFFFFE;
  v7 = *s;
  v8 = (*s)->animeflag;
  if ((v8 & 2) == 0)
  v9 = v7->alpha;
  if (v9)
  {
    v7->alpha = v9 - 12;
    if ((*s)->alpha < 0)
      (*s)->alpha = 0;
    v10 = *s;
    v11 = (*s)->animeflag;
    if ((v11 & 8) == 0)
  }
  v7->animeflag = v8 & 0xFFFFFFFD;
  v10 = *s;
  v11 = (*s)->animeflag;
  if ((v11 & 8) == 0)
  {
    v14 = *s;
    if (((*s)->animeflag & 4) == 0)
      return;
  }
  ox = v10->ox;
  if (!ox)
  {
    v10->animeflag = v11 & 0xFFFFFFF7;
  }
  v13 = (ox * 0.5);
  if (!v13)
    v13 = -1;
  v10->ox = ox - v13;
  v14 = *s;
  if (((*s)->animeflag & 4) != 0)
  {
    openwait = v14->openwait;
    v16 = __OFSUB__(openwait--, 1);
    v14->openwait = openwait;
    if ((openwait < 0) ^ v16 | (openwait == 0))
      (*s)->animeflag &= ~4u;
  }
}

// 0x16e1030
s32 CheckSelectError(nbCommSelProcessData_t **s) {
  struct System_Int32_array *commcnt;
  s64 nowtype;
  struct System_SByte_array_array *commdisable;
  s64 v6;
  Il2CppClass **v9;
  struct System_Int32_array *nowcursor;
  Il2CppClass *v11;
  s64 v13;

  commcnt = (*s)->commcnt;
  nowtype = (*s)->nowtype;
  if (!commcnt->m_Items[nowtype])
    return 1;
  commdisable = (*s)->commdisable;
  v6 = (*s)->nowtype;
  v9 = &commdisable->obj.klass + v6;
  nowcursor = (*s)->nowcursor;
  v11 = v9[4];
  v13 = nowcursor->m_Items[v6];
  return *(&v11->_1.byval_arg.data + v13) > 0;
}

// 0x16dfb20
void DispComm1Comm(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2) {
    GetComList(0);
    nbGetUnitWorkPointer(0, 0);
    GetStr(0);
    Get(0);
    datGetSkillCost(0, 0);
    Set(0, 0);
    GetComTextTM(0);
    RepColTag(0, 0);
}

// 0x16df360
void DispComm1Item(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2) {
    GetComList(0);
    Get(0);
    GetComTextTM(0);
    RepColTag(0, 0);
    Set(0, 0);
}

// 0x16ddb50
void DispComm1PanelComm(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col) {

}

// 0x16ddcf0
void DispComm1PanelCursor(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, s32 oz, u32 col) {
    GetBattleUI(0);
    GetTabMaxCount(0);
}

// 0x16ddc00
void DispComm1PanelItem(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col) {
  ;
}

// 0x16ddc30
void DispComm1PanelSummon(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col) {

}

// 0x16ddbf0
void DispComm1PanelTalk(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col) {
  ;
}

// 0x16de950
void DispComm1Summon(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2) {
    GetComListS(0);
    Get(0);
    GetComTextTM(0);
    RepColTag(0, 0);
    Set(0, 0);
    nbPanelHPColor(0);
    HPMPBarAdjustment(0, 0, 0);
    nbPanelMPColor(0);
    ResetSummonCommandSteffUIs(0);
}

// 0x16df8f0
void DispComm1Talk(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2) {
    GetComList(0);
    GetStr(0);
    Get(0);
    GetComTextTM(0);
    RepColTag(0, 0);
}

// 0x16ddcd0
void DispCommCursor(s32 ox, s32 oy, s32 a) {
  ;
}

// 0x16e0330
void DispCommandList2(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, s32 a) {
    GetBattleUI(0);
    GetComList(0);
    DispComm1Comm(0, 0, 0, 0, 0, 0, 0, 0);
    DispComm1Talk(0, 0, 0, 0, 0, 0, 0, 0);
    DispComm1Item(0, 0, 0, 0, 0, 0, 0, 0);
    DispComm1Summon(0, 0, 0, 0, 0, 0, 0, 0);
    DispHelp1(0, 0, 0, 0, 0, 0);
}

// 0x16de340
void DispCommandPanel(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, s32 a) {
  u8 v6;
  s32 v7;
  s32 v11;
  s32 v12;
  u32 v13;
  nbCommSelProcessData_t_o *v16;
  s32 cnt;
  s32 v18;
  struct System_Int32_array *r_a;
  s32 v22;
  s64 drawlisty;
  struct System_Int32_array *commcnt;
  struct System_UInt16_array_array *commlist;
  System_UInt16_array *v28;
  u32 v30;
  s32 drawcursor;
  u32 v35;
  s32 v36;

  v6 = a;
  v7 = oy;
  v36 = ox;
  DispPanelCursor(s, type, ox, oy, a);
  if (type == 3)
  {
    v16 = *s;
    cnt = (*s)->cnt;
    v36 += 33;
    v7 += ((*s)->smritu * 43.0) + 302;
    v18 = 43;
    if (cnt < 1)
  }
  cnt = r_a->m_Items[type];
  v16 = *s;
  if (type > 5)
  {
    v18 = 0;
    if (cnt < 1)
  }
  v7 += 345;
  v18 = 21;
  v36 += 27;
  if (cnt >= 1)
  {
    v22 = (v6 << 24) | 0x808080;
    drawlisty = v16->drawlisty;
    v35 = v22;
    do
    {
      commcnt = v16->commcnt;
      if (drawlisty >= commcnt->m_Items[type])
      commlist = (*s)->commlist;
      v28 = commlist->m_Items[type];
      v30 = v28->m_Items[drawlisty];
      drawcursor = (*s)->drawcursor;
      if (drawlisty == drawcursor)
      {
        if ((*s)->nowstat != 2)
        DispComm1PanelCursor(s, type, v36, v7, v13, v35);
        drawcursor = (*s)->drawcursor;
      }
      if (drawlisty == drawcursor)
      {
        evtBitCheck(3086);
      }
      switch (type)
      {
        case 0:
          else          if ((v30 & 0xFFFC) == 0x8000)
          if (v30 < LODWORD(tbl->max_length))
        case 1:
        case 2:
        case 3:
          else          v7 += v18;
          break;
        default:
      }
      v16 = *s;
      ++drawlisty;
    }
    while (drawlisty < (*s)->drawlisty + cnt);
  }
  DispPanelLabel(s, type, v11, v12, v13);
}

// 0x16dffb0
void DispHelp1(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, s32 a) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v13;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  System_String_o *v16;
  TMPro_TMP_Text_o *v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Component_o *v19;
  UnityEngine_GameObject_o *v20;
  s32 v22;
  s32 v23;
  s8 v24;
  System_String_o *HelpForUnity;
  System_String_o *v27;
  System_String_o *v28;

  BattleUI = GetBattleUI(0);
  if (!op_Equality(BattleUI, 0, 0))
  {
    transform = get_transform(BattleUI, 0);
    v13 = Find(transform, StringLiteral_21242, 0);
    gameObject = get_gameObject(v13);
    Component_object = GetComponent_object_(gameObject);
    v16 = StringLiteral_416;
    v17 = Component_object;
    v18 = get_transform(BattleUI, 0);
    v19 = Find(v18, StringLiteral_21243, 0);
    v20 = get_gameObject(v19);
    if (evtBitCheck(3086) || (*s)->drawtype == 3)
    {
      if (get_activeSelf(v20))
        SetActive(v20, 0, 0);
    }
    else
    {
      if (!get_activeSelf(v20))
        SetActive(v20, 1, 0);
      switch ((*s)->drawtype)
      {
        case 0:
          switch (d)
          {
            case 0x8000u:
              {
              }
              v22 = 1;
            case 0x8001u:
            case 0x8002u:
              {
              }
              v22 = 2;
            case 0x8003u:
            default:
          }
        case 1:
          if (d == 32772)
          {
            {
            }
            v22 = 3;
            v27 = Get(v22, 0);
          }
          else
          {
            v23 = oz;
            v24 = 0;
            HelpForUnity = frwGetHelpForUnity(0, 0, v23, v24, d, 1);
            v27 = CutAF_DEL(HelpForUnity);
          }
          v16 = v27;
          v28 = Replace_5267216(v16, StringLiteral_3622, StringLiteral_416);
          set_text(v17, v28);
          break;
        case 2:
          v23 = oz;
          v24 = 1;
        case 4:
          {
          }
          v22 = 5;
        case 5:
          {
          }
          v22 = 4;
        default:
      }
    }
  }
}

// 0x16de330
void DispHelpPanel(nbCommSelProcessData_t **s, s32 d, s32 ox, s32 oy, s32 oz, u32 col, s32 a) {
  evtBitCheck(3086);
}

// 0x16ddc10
void DispHpPanel(sdfTexHandle_t *th, datUnitWork_t *w, s32 ox, s32 oy, s32 oz, u32 col) {
  ;
}

// 0x16ddc20
void DispMpPanel(sdfTexHandle_t *th, datUnitWork_t *w, s32 ox, s32 oy, s32 oz, u32 col) {
  ;
}

// 0x16dd6b0
void DispPanelCursor(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, u32 c) {
  nbCommSelProcessData_t_o *v8;
  s32 *p_cnt;
  struct System_Int32_array *r_a;
  s32 v13;
  u32 battletime;
  UnityEngine_GameObject_o *BattleUI;
  u32 v17;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v19;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v21;
  UnityEngine_Component_o *v22;
  UnityEngine_GameObject_o *v23;
  struct System_Int32_array *nowlisty;
  UnityEngine_GameObject_o *v25;
  s32 v27;
  bool activeSelf;
  UnityEngine_GameObject_o *v29;
  bool v30;
  struct System_Int32_array *v31;
  char *v33;
  struct System_Int32_array *commcnt;
  s32 v35;
  s32 v37;
  bool v38;
  UnityEngine_GameObject_o *v39;
  bool v40;

  if (type == 3)
  {
    v8 = *s;
    p_cnt = &(*s)->cnt;
  }
  else
  {
    p_cnt = &r_a->m_Items[type];
    v8 = *s;
  }
  v13 = *p_cnt;
  battletime = v8->data->battletime;
  BattleUI = GetBattleUI(0);
  if (!op_Equality(BattleUI, 0, 0))
  {
    v17 = battletime % 0x19;
    transform = get_transform(BattleUI, 0);
    v19 = Find(transform, StringLiteral_21207, 0);
    gameObject = get_gameObject(v19);
    v21 = get_transform(BattleUI, 0);
    v22 = Find(v21, StringLiteral_21208, 0);
    v23 = get_gameObject(v22);
    nowlisty = (*s)->nowlisty;
    v25 = v23;
    v27 = nowlisty->m_Items[type];
    activeSelf = get_activeSelf(gameObject);
    if (v17 > 0xD || v27 < 1)
    {
      if (!activeSelf)
      v29 = gameObject;
      v30 = 0;
    }
    else
    {
      if (activeSelf)
      v29 = gameObject;
      v30 = 1;
    }
    SetActive(v29, v30, 0);
    v31 = (*s)->nowlisty;
    v33 = v31 + 4 * type;
    commcnt = (*s)->commcnt;
    v35 = *(v33 + 8);
    v37 = commcnt->m_Items[type];
    v38 = get_activeSelf(v25);
    if (v17 > 0xD || v35 >= v37 - v13)
    {
      if (!v38)
        return;
      v39 = v25;
      v40 = 0;
    }
    else
    {
      if (v38)
        return;
      v39 = v25;
      v40 = 1;
    }
    SetActive(v39, v40, 0);
  }
}

// 0x16dd9d0
void DispPanelLabel(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, u32 c) {
  nbMainProcessData_t_o *data;
  nbParty_t_o *my;

  data = (*s)->data;
  my = (*s)->my;
  nbGetUnitWorkPointer(data, my);
}

// 0x16ddb40
void DispPanelSitaji(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, u32 c) {
  ;
}

// 0x16ddce0
void DispSummonCursor(s32 ox, s32 oy, s32 a) {
  ;
}

// 0x16df7c0
void *GetComList(s32 listidx) {
    GetBattleUI(0);
    return 0;
}

// 0x16df070
void *GetComListS(s32 listidx) {
    GetBattleUI(0);
    return 0;
}

// 0x16df1a0
void *GetComTextTM(void *ComListObj) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v4;
  UnityEngine_Object_o *gameObject;
  bool v7;
  TMPro_TextMeshProUGUI_o *result;

  transform = get_transform(ComListObj, 0);
  v4 = Find(transform, StringLiteral_21241, 0);
  gameObject = get_gameObject(v4);
  v7 = op_Equality(gameObject, 0, 0);
  result = 0;
  if (!v7)
    return GetComponent_object_(gameObject);
  return result;
}

// 0x16dd4c0
s32 GetCommListCnt(nbCommSelProcessData_t **s, s32 type) {
  s32 *p_cnt;
  struct System_Int32_array *r_a;

  if (type == 3)
  {
    p_cnt = &(*s)->cnt;
  }
  else
  {
    p_cnt = &r_a->m_Items[type];
  }
  return *p_cnt;
}

// 0x16dd580
nbCommSelProcessData_t *GetCommSelProcessData(void) {
    dds3SearchProcessName(0);
    dds3GetProcessData(0);
    return 0;
}

// 0x16e1320
s32 GetNextCommType(nbCommSelProcessData_t **s, s32 dir) {
  s32 v3;
  struct System_Int32_array *commcnt;
  s64 v5;
  struct System_Int32_array *v7;
  struct System_Int32_array *v9;
  struct System_Int32_array *v11;
  struct System_Int32_array *v13;

  if (dir)
    v3 = 1;
  else
    v3 = 5;
  commcnt = (*s)->commcnt;
  v5 = (v3 + (*s)->nowtype) % 6;
  if (commcnt->m_Items[v5] <= 0)
  {
    v5 = (v3 + v5) % 6u;
    v7 = (*s)->commcnt;
    if (v7->m_Items[v5] <= 0)
    {
      v5 = (v5 + v3) % 6u;
      v9 = (*s)->commcnt;
      if (v9->m_Items[v5] <= 0)
      {
        v5 = (v5 + v3) % 6u;
        v11 = (*s)->commcnt;
        if (v11->m_Items[v5] <= 0)
        {
          v5 = (v5 + v3) % 6u;
          v13 = (*s)->commcnt;
          if (v13->m_Items[v5] <= 0)
          {
            LODWORD(v5) = (v5 + v3) % 6u;
          }
        }
      }
    }
  }
  return v5;
}

// 0x16de160
s32 GetTabIndex(nbCommSelProcessData_t *s, s32 type) {
  u64 v3;
  s32 v4;
  struct System_Int32_array *commcnt;

  if (!type)
    return 0;
  v3 = 0;
  v4 = 0;
  do
  {
    commcnt = s->commcnt;
    if (commcnt->m_Items[v3])
      ++v4;
    if (v3 > 4)
      break;
  }
  while (type - 1LL != v3++);
  return v4;
}

// 0x16de1f0
s32 GetTabMaxCount(nbCommSelProcessData_t *s) {
  struct System_Int32_array *commcnt;
  u64 max_length_low;
  struct System_Int32_array *v4;
  s32 v6;
  struct System_Int32_array *v7;
  s32 v8;
  s32 v13;

  commcnt = s->commcnt;
  max_length_low = LODWORD(commcnt->max_length);
  v4 = commcnt;
  v6 = commcnt->m_Items[0];
  v7 = s->commcnt;
  v8 = v6 != 0;
  if (v4->m_Items[1])
    ++v8;
  if (v7->m_Items[2])
    ++v8;
  if (v4->m_Items[3])
    ++v8;
  if (v7->m_Items[4])
    v13 = v8 + 1;
  else
    v13 = v8;
  if (v7->m_Items[5])
    return v13 + 1;
  else
    return v13;
}

// 0x16e51e0
nbCommSelProcessData_t *InitCommSelProcessData(nbMainProcessData_t *data, nbParty_t *my, nbActionProcessData_t *act) {
  u64 *v7;
  char stat;
  u64 v11;
  char v12;
  u64 v13;
  u64 v14;
  u64 v16;
  u64 v18;
  u64 v20;
  u64 v22;
  u64 v24;
  u64 v26;
  u64 v28;
  u64 v30;
  u64 v32;
  nbCommSelProcessData_t_o *s;

  v7 = Allocate(nbCommSelProcessData_t);
  nbCommSelProcessData_t___ctor(v7);
  s = v7;
  nbCommSelProcessData_t__Clear(v7);
  v7[3] = data;
  v7[4] = act;
  stat = act->stat;
  v11 = v7[7];
  *(v7 + 41) = 0;
  if (stat < 0)
    v12 = 2;
  else
    v12 = 1;
  *(v7 + 40) = v12;
  *(v11 + 32) = 0;
  v13 = v7[8];
  *(v13 + 32) = 0;
  v14 = v7[7];
  *(v14 + 36) = 0;
  v16 = v7[8];
  *(v16 + 36) = 0;
  v18 = v7[7];
  *(v18 + 40) = 0;
  v20 = v7[8];
  *(v20 + 40) = 0;
  v22 = v7[7];
  *(v22 + 44) = 0;
  v24 = v7[8];
  *(v24 + 44) = 0;
  v26 = v7[7];
  *(v26 + 48) = 0;
  v28 = v7[8];
  *(v28 + 48) = 0;
  v30 = v7[7];
  *(v30 + 52) = 0;
  v32 = v7[8];
  *(v32 + 52) = 0;
  *(v7 + 132) = 16711760;
  v7[9] = my;
  v7[10] = 0;
  v7[14] = 0x3F80000000000002LL;
  v7[15] = 0xFFFFFFE200000009LL;
  *(v7 + 36) = 0;
  SetCommList(&s, my);
  SetCommCursor2(&s);
  return s;
}

// 0x16e1140
void MemoryCommand(nbCommSelProcessData_t **s) {
  nbMainProcessData_t_o *data;
  nbParty_t_o *my;
  datUnitWork_t_o *UnitWorkPointer;
  struct System_Int32_array *nowcursor;
  s64 nowtype;
  char *v9;
  struct System_UInt16_array_array *commlist;
  s64 v11;
  System_UInt16_array *v13;
  s32 v15;
  s16 v16;

  data = (*s)->data;
  my = (*s)->my;
  UnitWorkPointer = nbGetUnitWorkPointer(data, my);
  nowcursor = (*s)->nowcursor;
  nowtype = (*s)->nowtype;
  v9 = nowcursor + 4 * nowtype;
  commlist = (*s)->commlist;
  v11 = *(v9 + 8);
  v13 = commlist->m_Items[(*s)->nowtype];
  v15 = v13->m_Items[v11];
  switch ((*s)->nowtype)
  {
    case 0u:
    case 4u:
    case 5u:
      JUMPOUT(0x16E127C);
    case 1u:
      UnitWorkPointer->nowcommand = 4;
      if (v15 == 32772)
        LOWORD(v15) = 384;
    case 2u:
      v16 = 5;
    case 3u:
      v16 = 6;
      UnitWorkPointer->nowcommand = v16;
      UnitWorkPointer->nowindex = v15;
      break;
    default:
      return;
  }
}

// 0x16df260
void ResetSummonCommandSteffUIs(void *commandObj) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v4;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v6;
  s32 v7;
  UnityEngine_Transform_o *v8;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v10;
  UnityEngine_Transform_o *v11;
  UnityEngine_Component_o *v12;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Transform_o *v14;

  transform = get_transform(commandObj, 0);
  v4 = Find(transform, StringLiteral_12347, 0);
  gameObject = get_gameObject(v4);
  v6 = get_transform(gameObject, 0);
  if (get_childCount(v6) >= 1)
  {
    v7 = 0;
    do
    {
      v8 = get_transform(gameObject, 0);
      Child = GetChild(v8, v7);
      v10 = get_gameObject(Child);
      if (get_activeSelf(v10))
      {
        v11 = get_transform(gameObject, 0);
        v12 = GetChild(v11, v7);
        v13 = get_gameObject(v12);
        SetActive(v13, 0, 0);
      }
      ++v7;
      v14 = get_transform(gameObject, 0);
    }
    while (v7 < get_childCount(v14));
  }
}

// 0x16e1510
void SelectCommandList(nbCommSelProcessData_t **s) {
    GetBattleUI(0);
    DDS3_PADCHECK_REP(0);
    DDS3_PADCHECK_TRIG(0);
    nbGetUnitWorkPointer(0, 0);
    GetNextCommType(0, 0);
    CheckSelectError(0);
    MemoryCommand(0);
    evtBitCheck(0);
    evtBitOff(0);
    evtBitOn(0);
    nbPlaySe(0);
}

// 0x16e23d0
void SelectCommandListAuto(nbCommSelProcessData_t **s) {
    CheckSelectError(0);
    MemoryCommand(0);
}

// 0x16e4e30
void SetCommCursor2(nbCommSelProcessData_t **s) {
    nbGetUnitWorkPointer(0, 0);
    dds3CheckConfigBit(0);
    SetPrevCursor(0, 0, 0);
}

// 0x16e3060
void SetCommList(nbCommSelProcessData_t **s, nbParty_t *my) {
    nbGetUnitWorkPointer(0, 0);
    nbCheckSkillCost(0, 0);
    nbGetRandamStock();
    nbGetEscapeSwitch(0);
}

// 0x16e4b00
void SetPrevCursor(nbCommSelProcessData_t **s, s32 type, s32 ind) {
  nbCommSelProcessData_t_o *v7;
  s32 *p_cnt;
  s64 v9;
  struct System_Int32_array *r_a;
  s32 v13;
  struct System_Int32_array *nowcursor;
  struct System_Int32_array *nowlisty;
  struct System_Int32_array *commcnt;
  s32 v20;
  struct System_Int32_array *v21;
  char *v23;
  u32 *v24;
  s32 v25;
  s32 v26;
  struct System_Int32_array *v27;
  struct System_Int32_array *v29;
  struct System_Int32_array *v31;
  struct System_SByte_array_array *commdisable;
  System_SByte_array *v35;
  struct System_Int32_array *v37;
  struct System_Int32_array *v39;

  if (type == 3)
  {
    v7 = *s;
    p_cnt = &(*s)->cnt;
    v9 = 3;
  }
  else
  {
    v9 = type;
    p_cnt = &r_a->m_Items[type];
    v7 = *s;
  }
  v13 = *p_cnt;
  v7->nowtype = type;
  nowcursor = (*s)->nowcursor;
  nowcursor->m_Items[v9] = ind;
  nowlisty = (*s)->nowlisty;
  nowlisty->m_Items[v9] = ind;
  commcnt = (*s)->commcnt;
  v20 = v13 + ind;
  if (v20 >= commcnt->m_Items[v9])
  {
    v21 = (*s)->nowlisty;
    v23 = v21 + 4 * v9;
    v26 = *(v23 + 8);
    v24 = v23 + 32;
    v25 = v26;
    v27 = (*s)->commcnt;
    *v24 = v25 - v20 + v27->m_Items[v9];
    v29 = (*s)->nowlisty;
    if (v29->m_Items[v9] < 0)
    {
      v31 = (*s)->nowlisty;
      v31->m_Items[v9] = 0;
    }
  }
  commdisable = (*s)->commdisable;
  v35 = commdisable->m_Items[v9];
  if (v35->m_Items[ind])
  {
    (*s)->nowtype = 0;
    v37 = (*s)->nowcursor;
    v37->m_Items[v9] = 0;
    v39 = (*s)->nowlisty;
    v39->m_Items[v9] = 0;
  }
}

// 0x16e29d0
bool bComActive(void) {
  UnityEngine_Object_o *BattleUI;

  BattleUI = GetBattleUI(0);
  return op_Inequality(BattleUI, 0, 0) && get_activeSelf(BattleUI);
}

// 0x16e27e0
bool bComChk(void) {
  return bComFlag;
}

// 0x16e25f0
void bComOff(void) {
  UnityEngine_Object_o *BattleUI;

  BattleUI = GetBattleUI(0);
  if (op_Inequality(BattleUI, 0, 0) && get_activeSelf(BattleUI))
  {
    bComOffTime = 3;
  }
}

// 0x16e2850
void bComOffExec(void) {
  UnityEngine_GameObject_o *BattleUI;

  else if (!bComOffTime)
  {
    return;
  }
  else if (Postblur_DrawStop)
  {
    return;
  }
  if (!--bComOffTime)
  {
    BattleUI = GetBattleUI(0);
    if (op_Inequality(BattleUI, 0, 0) && get_activeSelf(BattleUI))
      SetActive(BattleUI, 0, 0);
  }
}

// 0x16e26d0
void bComOn(void) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;

  BattleUI = GetBattleUI(0);
  if (op_Inequality(BattleUI, 0, 0) && !get_activeSelf(BattleUI))
  {
    SetActive(BattleUI, 1, 0);
    transform = get_transform(BattleUI, 0);
    v5 = Find(transform, StringLiteral_21246, 0);
    gameObject = get_gameObject(v5);
    Component_object = GetComponent_object_(gameObject);
    SetInteger(Component_object, StringLiteral_21246, 0);
  }
}

// 0x16e2570
void nbCloseCommSel(void) {
  nbCommSelProcessData_t_o *CommSelProcessData;

  CommSelProcessData = GetCommSelProcessData();
  CommSelProcessData->nowstat = 4;
  CommSelProcessData->animeflag = CommSelProcessData->animeflag & 0xFFFFFFFC | 2;
  bComOff(CommSelProcessData);
}

// 0x16e2a90
void *nbCommSelProcess1(dds3ProcessID_t *id) {
    nbPlaySe(0);
    dds3GetProcessData(0);
    AnimeCommandList(0);
    SelectCommandListAuto(0);
    bComOn();
    SelectCommandList(0);
    bComOffExec();
    DispCommandPanel(0, 0, 0, 0, 0);
    DispCommandList2(0, 0, 0, 0, 0);
    return 0;
}

// 0x16e2f30
void *nbCommSelShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    return 0;
}

// 0x16e2490
s32 nbGetCommSelStat(void) {
  return GetCommSelProcessData()->nowstat;
}

// 0x16e54b0
void nbInitCommSelProcess(nbMainProcessData_t *data, nbParty_t *my, nbActionProcessData_t *act) {
  Il2CppObject *inited;
  u64 *v8;
  u64 *v9;
  dds3ProcessID_t_o *target;

  target = 0;
  inited = InitCommSelProcessData(data, my, act);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_nbCommSelProcess_nbCommSelProcess1__);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_nbCommSelProcess_nbCommSelShutdown__);
  target = dds3StartProcess(StringLiteral_21206, 0x2B0Eu, 1, 1, v8, 0, v9, 0, inited, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->CommSelProcessID = target;
}

// 0x16e5160
void nbSetAutoCommSel(void) {
  nbCommSelProcessData_t_o *CommSelProcessData;
  nbCommSelProcessData_t_o *s;

  s = 0;
  CommSelProcessData = GetCommSelProcessData();
  s = CommSelProcessData;
  SetCommCursor2(&s);
  CommSelProcessData->animeflag |= 0x10u;
}

// 0x16e2500
void nbSetCommSelStat(s32 stat) {
  s8 v2;

  v2 = stat;
  GetCommSelProcessData()->nowstat = v2;
}
