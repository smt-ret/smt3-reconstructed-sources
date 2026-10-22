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
LABEL_9:
    v4 = *s;
    animeflag = (*s)->animeflag;
    if ((animeflag & 1) == 0)
      goto LABEL_15;
    goto LABEL_10;
  }
  if (helpa < 1)
    goto LABEL_9;
  v2->helpa = helpa - 21;
  if (((*s)->helpa & 0x80000000) == 0)
    goto LABEL_9;
  (*s)->helpa = 0;
  v4 = *s;
  animeflag = (*s)->animeflag;
  if ((animeflag & 1) == 0)
    goto LABEL_15;
LABEL_10:
  alpha = v4->alpha;
  if (alpha != 128)
  {
    v4->alpha = alpha + 20;
    if ((*s)->alpha >= 129)
      (*s)->alpha = 128;
LABEL_15:
    v7 = *s;
    v8 = (*s)->animeflag;
    if ((v8 & 2) == 0)
      goto LABEL_19;
    goto LABEL_16;
  }
  v4->animeflag = animeflag & 0xFFFFFFFE;
  v7 = *s;
  v8 = (*s)->animeflag;
  if ((v8 & 2) == 0)
    goto LABEL_19;
LABEL_16:
  v9 = v7->alpha;
  if (v9)
  {
    v7->alpha = v9 - 12;
    if ((*s)->alpha < 0)
      (*s)->alpha = 0;
LABEL_19:
    v10 = *s;
    v11 = (*s)->animeflag;
    if ((v11 & 8) == 0)
      goto LABEL_28;
    goto LABEL_20;
  }
  v7->animeflag = v8 & 0xFFFFFFFD;
  v10 = *s;
  v11 = (*s)->animeflag;
  if ((v11 & 8) == 0)
  {
LABEL_28:
    v14 = *s;
    if (((*s)->animeflag & 4) == 0)
      return;
    goto LABEL_29;
  }
LABEL_20:
  ox = v10->ox;
  if (!ox)
  {
    v10->animeflag = v11 & 0xFFFFFFF7;
    goto LABEL_28;
  }
  v13 = (ox * 0.5);
  if (!v13)
    v13 = -1;
  v10->ox = ox - v13;
  v14 = *s;
  if (((*s)->animeflag & 4) != 0)
  {
LABEL_29:
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
  UnityEngine_GameObject_o *ComList;
  nbCommSelProcessData_t_o *v15;
  nbMainProcessData_t_o *data;
  UnityEngine_GameObject_o *v17;
  nbParty_t_o *my;
  datUnitWork_t_o *UnitWorkPointer;
  s32 v21;
  System_String_o *Str;
  datUnitWork_t_o *v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  struct datNormalSkill_t_array *tbl;
  s32 costtype;
  s32 SkillCost;
  UnityEngine_Transform_o *transform;
  s64 *v36;
  UnityEngine_Component_o *v37;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  TMPro_TMP_Text_o *ComTextTM;
  System_Object_array *v42;
  s64 *v43;
  s64 *v45;
  System_String_o *v47;
  s32 v49;
  UnityEngine_Color_o v50;

  *&v50.r = 0;
  *&v50.b = 0;
  ComList = GetComList(listidx, d);
  v15 = *s;
  data = (*s)->data;
  v17 = ComList;
  my = v15->my;
  UnitWorkPointer = nbGetUnitWorkPointer(data, my);
  switch (d)
  {
    case 0x8000u:
      v21 = 0;
      goto LABEL_26;
    case 0x8001u:
      v21 = 1;
      goto LABEL_26;
    case 0x8002u:
      v21 = 2;
      goto LABEL_26;
    case 0x8003u:
      v21 = 4;
LABEL_26:
      Str = GetStr(v21);
      goto LABEL_27;
    default:
      v25 = UnitWorkPointer;
      Str = Get(d, 0, 0);
      if (col2 == 2)
      {
        v26 = 0.5;
        v27 = 1.0;
        v28 = 0.5;
        v29 = 0.5;
      }
      else
      {
        v26 = 1.0;
        v29 = 1.0;
        v28 = 1.0;
        v27 = 1.0;
      }
      sub_19EC630(&v50.r, v26, v29, v28, v27);
      costtype = tbl->m_Items[d]->costtype;
      if (costtype == 2)
      {
        SkillCost = datGetSkillCost(v25, d);
        transform = get_transform(v17, 0);
        v36 = &"bmenu_mp";
      }
      else
      {
        if (costtype != 1)
        {
LABEL_27:
            goto LABEL_52;
          goto LABEL_28;
        }
        SkillCost = datGetSkillCost(v25, d);
        transform = get_transform(v17, 0);
        v36 = &"bmenu_hp";
      }
      v37 = Find(transform, *v36, 0);
      gameObject = get_gameObject(v37);
      SetActive(gameObject, 1, 0);
      Component_object = GetComponent_object_(v17);
      Set(Component_object, SkillCost, v50, 0, 0);
        goto LABEL_52;
LABEL_28:
LABEL_52:
      ComTextTM = GetComTextTM(v17);
      if (op_Inequality(ComTextTM, 0, 0))
      {
        v49 = col2;
        v42 = NewSpecific(object, 1u);
        v43 = sub_8D3950(s32, &v49);
        v45 = v43;
        v42->m_Items[0] = v45;
        v47 = RepColTag(Str, v42);
        set_text(ComTextTM, v47);
      }
      return;
  }
}

// 0x16df360
void DispComm1Item(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2) {
  UnityEngine_GameObject_o *ComList;
  System_String_o *v14;
  TMPro_TMP_Text_o *ComTextTM;
  System_Object_array *v19;
  s64 *v20;
  s64 *v22;
  System_String_o *v24;
  struct System_Byte_array *item;
  u32 v28;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v31;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_Transform_o *v33;
  UnityEngine_Component_o *v34;
  UnityEngine_GUILayer_o *v35;
  UnityEngine_Sprite_o *sprite;
  UnityEngine_Transform_o *v37;
  UnityEngine_Component_o *v38;
  UnityEngine_GUILayer_o *v39;
  UnityEngine_Transform_o *v40;
  UnityEngine_Component_o *v41;
  UnityEngine_GUILayer_o *v42;
  UnityEngine_Sprite_o *v43;
  UnityEngine_Transform_o *v44;
  UnityEngine_Component_o *v45;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v47;
  UnityEngine_Component_o *v48;
  UnityEngine_GameObject_o *v49;
  UnityEngine_Transform_o *v50;
  UnityEngine_Component_o *v51;
  UnityEngine_GameObject_o *v52;
  UnityEngine_Transform_o *v53;
  UnityEngine_Component_o *v54;
  UnityEngine_GameObject_o *v55;
  UnityEngine_Transform_o *v56;
  UnityEngine_Component_o *v57;
  UnityEngine_GameObject_o *v58;
  UnityEngine_Transform_o *v59;
  UnityEngine_Component_o *v60;
  UnityEngine_GameObject_o *v61;
  s32 v63;
  UnityEngine_Color_o v64;

  ComList = GetComList(listidx, d);
  v14 = Get(d, 0);
  ComTextTM = GetComTextTM(ComList);
  if (op_Inequality(ComTextTM, 0, 0))
  {
    v63 = col2;
    v19 = NewSpecific(object, 1u);
    v20 = sub_8D3950(s32, &v63);
    v22 = v20;
    v19->m_Items[0] = v22;
    v24 = RepColTag(v14, v19);
    set_text(ComTextTM, v24);
  }
  item = DDS3_GBWK->item;
  v28 = item->m_Items[d];
  Component_object = GetComponent_object_(ComList);
  v64.r = 0.0;
  v64.g = 0.0;
  v64.b = 0.0;
  v64.a = 0.0;
  Set(Component_object, v28, v64, 0, 0);
  transform = get_transform(ComList, 0);
  v31 = Find(transform, "num_item_count01", 0);
  Component_GUILayer = GetComponent_GUILayer_(v31);
  v33 = get_transform(ComList, 0);
  v34 = Find(v33, "num_hp02", 0);
  v35 = GetComponent_GUILayer_(v34);
  sprite = get_sprite(v35);
  set_sprite(Component_GUILayer, sprite);
  v37 = get_transform(ComList, 0);
  v38 = Find(v37, "num_item_count02", 0);
  v39 = GetComponent_GUILayer_(v38);
  v40 = get_transform(ComList, 0);
  v41 = Find(v40, "num_hp03", 0);
  v42 = GetComponent_GUILayer_(v41);
  v43 = get_sprite(v42);
  set_sprite(v39, v43);
  v44 = get_transform(ComList, 0);
  v45 = Find(v44, "num_hp01", 0);
  gameObject = get_gameObject(v45);
  SetActive(gameObject, 0, 0);
  v47 = get_transform(ComList, 0);
  v48 = Find(v47, "num_hp02", 0);
  v49 = get_gameObject(v48);
  SetActive(v49, 0, 0);
  v50 = get_transform(ComList, 0);
  v51 = Find(v50, "num_hp03", 0);
  v52 = get_gameObject(v51);
  SetActive(v52, 0, 0);
  v53 = get_transform(ComList, 0);
  v54 = Find(v53, "bmenu_multiply", 0);
  v55 = get_gameObject(v54);
  SetActive(v55, 1, 0);
  if (v28 >= 0xA)
  {
    v56 = get_transform(ComList, 0);
    v57 = Find(v56, "num_item_count01", 0);
    v58 = get_gameObject(v57);
    SetActive(v58, 1, 0);
  }
  v59 = get_transform(ComList, 0);
  v60 = Find(v59, "num_item_count02", 0);
  v61 = get_gameObject(v60);
  SetActive(v61, 1, 0);
}

// 0x16ddb50
void DispComm1PanelComm(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col) {

}

// 0x16ddcf0
void DispComm1PanelCursor(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, s32 oz, u32 col) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v12;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v14;
  UnityEngine_Component_o *v15;
  UnityEngine_GameObject_o *v17;
  nbCommSelProcessData_t_o *v18;
  s32 v20;
  s32 TabMaxCount;
  s32 v26;
  s32 v27;
  u64 *v28;
  System_String_o *v29;
  UnityEngine_Transform_o *v30;
  UnityEngine_Component_o *v31;
  UnityEngine_GameObject_o *v33;
  bool activeSelf;
  UnityEngine_GameObject_o *v35;
  bool v36;
  u64 *v37;
  System_String_o *v38;
  UnityEngine_Transform_o *v39;
  UnityEngine_Component_o *v40;
  UnityEngine_Object_o *v42;
  bool v43;
  UnityEngine_GameObject_o *v44;
  bool v45;
  UnityEngine_Transform_o *v46;
  UnityEngine_Component_o *v47;
  UnityEngine_GameObject_o *v48;
  s32 i;
  s32 v50;
  u64 *v51;
  System_String_o *v52;
  UnityEngine_Transform_o *v53;
  UnityEngine_Component_o *v54;
  UnityEngine_Object_o *v56;
  bool v57;
  UnityEngine_GameObject_o *v58;
  bool v59;
  UnityEngine_GameObject_o *v60;
  s32 v61;
  s32 v62;
  s32 v63;
  s32 v64;

  BattleUI = GetBattleUI(0);
  if (op_Inequality(BattleUI, 0, 0))
  {
    transform = get_transform(BattleUI, 0);
    v12 = Find(transform, "bmenu/bmenu_tab", 0);
    gameObject = get_gameObject(v12);
    v60 = BattleUI;
    v14 = get_transform(BattleUI, 0);
    v15 = Find(v14, "bmenu/bmenu_tabpt", 0);
    v17 = get_gameObject(v15);
    v18 = *s;
    else
    {
      v61 = type;
      if (type)
        goto LABEL_17;
    }
    v20 = 0;
LABEL_28:
    TabMaxCount = GetTabMaxCount(*s);
    v26 = 0;
    while (1)
    {
      v27 = v26 + 1;
      v64 = v26 + 1;
      v28 = sub_8D3950(s32, &v64);
      v29 = Concat("bmenu_tab0", v28);
      v30 = get_transform(gameObject, 0);
      v31 = Find(v30, v29, 0);
      v33 = get_gameObject(v31);
      if (op_Inequality(v33, 0, 0))
      {
        activeSelf = get_activeSelf(v33);
        if (v20 == v26)
        {
          if (!activeSelf)
          {
            v35 = v33;
            v36 = 1;
LABEL_38:
            SetActive(v35, v36, 0);
          }
        }
        else if (activeSelf)
        {
          v35 = v33;
          v36 = 0;
          goto LABEL_38;
        }
      }
      v63 = v26 + 1;
      v37 = sub_8D3950(s32, &v63);
      v38 = Concat("bmenu_tabpt0", v37);
      v39 = get_transform(v17, 0);
      v40 = Find(v39, v38, 0);
      v42 = get_gameObject(v40);
      if (!op_Inequality(v42, 0, 0))
        goto LABEL_49;
      v43 = get_activeSelf(v42);
      if (v26 >= TabMaxCount)
      {
        if (v43)
        {
          v44 = v42;
          v45 = 0;
          goto LABEL_48;
        }
      }
      else if (!v43)
      {
        v44 = v42;
        v45 = 1;
LABEL_48:
        SetActive(v44, v45, 0);
      }
LABEL_49:
      ++v26;
      if (v27 == 5)
      {
        v46 = get_transform(v60, 0);
        v47 = Find(v46, "bmenu/bmenu_title", 0);
        v48 = get_gameObject(v47);
        for (i = 0; ; ++i)
        {
          v50 = i + 1;
          v62 = i + 1;
          v51 = sub_8D3950(s32, &v62);
          v52 = Concat("bmenu_title0", v51);
          v53 = get_transform(v48, 0);
          v54 = Find(v53, v52, 0);
          v56 = get_gameObject(v54);
          if (!op_Inequality(v56, 0, 0))
            goto LABEL_61;
          v57 = get_activeSelf(v56);
          if (v61 == i)
          {
            if (!v57)
            {
              v58 = v56;
              v59 = 1;
LABEL_60:
              SetActive(v58, v59, 0);
            }
          }
          else if (v57)
          {
            v58 = v56;
            v59 = 0;
            goto LABEL_60;
          }
LABEL_61:
          if (v50 == 6)
            return;
        }
      }
    }
  }
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
  UnityEngine_GameObject_o *ComListS;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v17;
  s32 id;
  System_String_o *v19;
  TMPro_TMP_Text_o *ComTextTM;
  System_Object_array *v23;
  s64 *v24;
  s64 *v26;
  System_String_o *v28;
  s32 v29;
  s32 level;
  Il2CppObject *Component_object;
  s32 v33;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v35;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *v37;
  UnityEngine_Transform_o *v38;
  UnityEngine_Component_o *v39;
  UnityEngine_GameObject_o *v40;
  Il2CppObject *v41;
  u32 v42;
  u32 v43;
  UnityEngine_UI_Image_o *v44;
  f32 v45;
  UnityEngine_Transform_o *v46;
  UnityEngine_Component_o *v47;
  UnityEngine_GameObject_o *v48;
  Il2CppObject *v49;
  UnityEngine_Transform_o *v50;
  UnityEngine_Component_o *v51;
  UnityEngine_GameObject_o *v52;
  Il2CppObject *v53;
  u32 v54;
  u32 v55;
  UnityEngine_UI_Image_o *v56;
  f32 v57;
  u16 badstatus;
  u32 v60;
  s32 v61;
  UnityEngine_Transform_o *v62;
  s64 *v63;
  s32 v64;
  UnityEngine_GameObject_o *v65;
  UnityEngine_Component_o *v67;
  UnityEngine_Transform_o *v70;
  UnityEngine_Component_o *v71;
  UnityEngine_Behaviour_o *Component_GUILayer;
  UnityEngine_Transform_o *v73;
  UnityEngine_Component_o *v74;
  UnityEngine_Behaviour_o *v75;
  UnityEngine_Color_o v76;
  s32 v77;

  *&v76.r = 0;
  *&v76.b = 0;
  ComListS = GetComListS(listidx, d);
  unitwork = DDS3_GBWK->unitwork;
  v17 = unitwork->m_Items[d];
  id = v17->id;
  v19 = Get(id, 0);
  ComTextTM = GetComTextTM(ComListS);
  if (op_Inequality(ComTextTM, 0, 0))
  {
    v77 = col2;
    v23 = NewSpecific(object, 1u);
    v24 = sub_8D3950(s32, &v77);
    v26 = v24;
    v23->m_Items[0] = v26;
    v28 = RepColTag(v19, v23);
    set_text(ComTextTM, v28);
  }
  sub_19EC630(&v76.r, 1.0, 1.0, 1.0, 1.0);
  if (v17->hp)
    v29 = (v17->badstatus >> 11) & 1;
  else
    v29 = 1;
  if (v17->level >= 0x63u)
    level = 99;
  else
    level = v17->level;
  Component_object = GetComponent_object_(ComListS);
  Set(Component_object, level, v76, v29, 0);
  v33 = nbPanelHPColor(v17);
  transform = get_transform(ComListS, 0);
  v35 = Find(transform, "barhp", 0);
  gameObject = get_gameObject(v35);
  v37 = GetComponent_object_(gameObject);
  Set(v37, v17->hp, v76, v33, 0);
  v38 = get_transform(ComListS, 0);
  v39 = Find(v38, "barhp/barhp_color", 0);
  v40 = get_gameObject(v39);
  v41 = GetComponent_object_(v40);
  LOWORD(v42) = v17->hp;
  LOWORD(v43) = v17->maxhp;
  v44 = v41;
  v45 = HPMPBarAdjustment(v42, v43, 0.075);
  set_fillAmount(v44, v45);
  LODWORD(v44) = nbPanelMPColor(v17);
  v46 = get_transform(ComListS, 0);
  v47 = Find(v46, "barmp", 0);
  v48 = get_gameObject(v47);
  v49 = GetComponent_object_(v48);
  Set(v49, v17->mp, v76, v44, 0);
  v50 = get_transform(ComListS, 0);
  v51 = Find(v50, "barmp/barmp_color", 0);
  v52 = get_gameObject(v51);
  v53 = GetComponent_object_(v52);
  LOWORD(v54) = v17->mp;
  LOWORD(v55) = v17->maxmp;
  v56 = v53;
  v57 = HPMPBarAdjustment(v54, v55, 0.075);
  set_fillAmount(v56, v57);
  badstatus = v17->badstatus;
  v60 = badstatus & 0xFFF;
  if ((badstatus & 0xFFF) != 0)
  {
    if (v60 <= 0x40)
    {
      if (v60 <= 8)
      {
        v65 = 0;
        switch (badstatus & 0xFFF)
        {
          case 1:
            v62 = get_transform(ComListS, 0);
            v63 = &"steff/steff_shock";
            break;
          case 2:
            v62 = get_transform(ComListS, 0);
            v63 = &"steff/steff_freeze";
            break;
          case 3:
            goto LABEL_67;
          case 4:
            v62 = get_transform(ComListS, 0);
            v63 = &"steff/steff_sleep";
            break;
          default:
            if (v60 != 8)
              goto LABEL_70;
            v62 = get_transform(ComListS, 0);
            v63 = &"steff/steff_panic";
            break;
        }
LABEL_66:
        v67 = Find(v62, *v63, 0);
        v65 = get_gameObject(v67);
LABEL_67:
          goto LABEL_71;
        goto LABEL_68;
      }
      v64 = badstatus & 0xFFF;
      switch (v64)
      {
        case 16:
          v62 = get_transform(ComListS, 0);
          v63 = &"steff/steff_bind";
          goto LABEL_66;
        case 32:
          v62 = get_transform(ComListS, 0);
          v63 = &"steff/steff_close";
          goto LABEL_66;
        case 64:
          v62 = get_transform(ComListS, 0);
          v63 = &"steff/steff_poison";
          goto LABEL_66;
      }
    }
    else
    {
      v61 = badstatus & 0xFFF;
      if (v60 <= 0x100)
      {
        if (v61 == 128)
        {
          v62 = get_transform(ComListS, 0);
          v63 = &"steff/steff_charm";
          goto LABEL_66;
        }
        if (v61 == 256)
        {
          v62 = get_transform(ComListS, 0);
          v63 = &"steff/steff_palyze";
          goto LABEL_66;
        }
      }
      else
      {
        switch (v61)
        {
          case 512:
            v62 = get_transform(ComListS, 0);
            v63 = &"steff/steff_fly";
            goto LABEL_66;
          case 1024:
            v62 = get_transform(ComListS, 0);
            v63 = &"steff/steff_stone";
            goto LABEL_66;
          case 2048:
            v62 = get_transform(ComListS, 0);
            v63 = &"steff/steff_dead";
            goto LABEL_66;
        }
      }
    }
LABEL_70:
    v65 = 0;
    {
LABEL_71:
      if (op_Inequality(v65, 0, 0) && !get_activeSelf(v65))
      {
        ResetSummonCommandSteffUIs(ComListS);
        SetActive(v65, 1, 0);
        v70 = get_transform(ComListS, 0);
        v71 = Find(v70, "steff", 0);
        Component_GUILayer = GetComponent_GUILayer_(v71);
        if (get_enabled(Component_GUILayer))
        {
          v73 = get_transform(ComListS, 0);
          v74 = Find(v73, "steff", 0);
          v75 = GetComponent_GUILayer_(v74);
          set_enabled(v75, 0);
        }
      }
      return;
    }
LABEL_68:
    goto LABEL_71;
  }
  ResetSummonCommandSteffUIs(ComListS);
}

// 0x16df8f0
void DispComm1Talk(nbCommSelProcessData_t **s, u16 d, s32 ox, s32 oy, s32 oz, u32 col, s32 listidx, s32 col2) {
  UnityEngine_GameObject_o *ComList;
  System_String_o *Str;
  TMPro_TMP_Text_o *ComTextTM;
  System_Object_array *v19;
  s64 *v20;
  s64 *v22;
  System_String_o *v24;
  s32 v26;

  ComList = GetComList(listidx, d);
  if (d == 32772)
  {
    Str = GetStr(5);
    {
LABEL_11:
    }
  }
  else
  {
    Str = Get(d, 0, 0);
      goto LABEL_11;
  }
  ComTextTM = GetComTextTM(ComList);
  if (op_Inequality(ComTextTM, 0, 0))
  {
    v26 = col2;
    v19 = NewSpecific(object, 1u);
    v20 = sub_8D3950(s32, &v26);
    v22 = v20;
    v19->m_Items[0] = v22;
    v24 = RepColTag(Str, v19);
    set_text(ComTextTM, v24);
  }
}

// 0x16ddcd0
void DispCommCursor(s32 ox, s32 oy, s32 a) {
  ;
}

// 0x16e0330
void DispCommandList2(nbCommSelProcessData_t **s, s32 type, s32 ox, s32 oy, s32 a) {
  s32 *p_cnt;
  struct System_Int32_array *r_a;
  UnityEngine_GameObject_o *BattleUI;
  nbCommSelProcessData_t_o *v15;
  s32 v16;
  s64 drawlisty;
  s32 v18;
  s32 v19;
  struct System_Int32_array *commcnt;
  struct System_UInt16_array_array *commlist;
  System_UInt16_array *v24;
  u32 v25;
  nbCommSelProcessData_t_o *v27;
  s32 v28;
  struct System_SByte_array_array *commdisable;
  struct System_SByte_array_array *v30;
  System_SByte_array *v32;
  s32 v34;
  System_SByte_array *v36;
  s32 v38;
  UnityEngine_GameObject_o *ComList;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v41;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v43;
  UnityEngine_Component_o *v44;
  UnityEngine_GameObject_o *v45;
  UnityEngine_Transform_o *v46;
  UnityEngine_Component_o *v47;
  UnityEngine_GameObject_o *v48;
  UnityEngine_Transform_o *v49;
  UnityEngine_Component_o *v50;
  UnityEngine_GameObject_o *v51;
  UnityEngine_Transform_o *v52;
  UnityEngine_Component_o *v53;
  UnityEngine_GameObject_o *v54;
  UnityEngine_Transform_o *v55;
  UnityEngine_Component_o *v56;
  UnityEngine_GameObject_o *v57;
  UnityEngine_Transform_o *v58;
  UnityEngine_Component_o *v59;
  UnityEngine_GameObject_o *v60;
  UnityEngine_Transform_o *v61;
  UnityEngine_Component_o *v62;
  UnityEngine_GameObject_o *v63;
  UnityEngine_Transform_o *v64;
  UnityEngine_Component_o *v65;
  UnityEngine_GameObject_o *v66;
  UnityEngine_Transform_o *v67;
  UnityEngine_Component_o *v68;
  UnityEngine_GameObject_o *v69;
  UnityEngine_Transform_o *v70;
  UnityEngine_Component_o *v71;
  UnityEngine_GameObject_o *v72;
  UnityEngine_Transform_o *v73;
  UnityEngine_Component_o *v74;
  UnityEngine_GameObject_o *v75;
  UnityEngine_Transform_o *v76;
  UnityEngine_Component_o *v77;
  UnityEngine_GameObject_o *v78;
  UnityEngine_Transform_o *v79;
  UnityEngine_Component_o *v80;
  UnityEngine_GameObject_o *v81;
  UnityEngine_Transform_o *v82;
  UnityEngine_Component_o *v83;
  UnityEngine_GameObject_o *v84;
  s32 v85;
  s32 v86;
  s32 v87;
  u32 v88;
  UnityEngine_Transform_o *v90;
  UnityEngine_Component_o *v91;
  UnityEngine_GameObject_o *v92;
  nbCommSelProcessData_t_o **v93;
  nbCommSelProcessData_t_o **v94;
  nbCommSelProcessData_t_o **v95;
  UnityEngine_Transform_o *v96;
  UnityEngine_Component_o *v97;
  UnityEngine_GameObject_o *v98;
  UnityEngine_Transform_o *v99;
  UnityEngine_Component_o *v100;
  UnityEngine_GameObject_o *v101;
  f32 v102;
  UnityEngine_Transform_o *v103;
  UnityEngine_Transform_o *v104;
  UnityEngine_Transform_o *v105;
  f32 x;
  f32 v107;
  f32 z;
  UnityEngine_GameObject_o *v109;
  UnityEngine_Component_o *v110;
  UnityEngine_GameObject_o *v111;
  UnityEngine_Transform_o *v112;
  UnityEngine_Transform_o *v113;
  UnityEngine_Transform_o *v114;
  u64 *v115;
  System_String_o *v116;
  UnityEngine_Component_o *v117;
  UnityEngine_GameObject_o *v118;
  UnityEngine_Transform_o *v119;
  UnityEngine_Transform_o *v120;
  u64 *v121;
  System_String_o *v122;
  UnityEngine_Component_o *v123;
  UnityEngine_GameObject_o *v124;
  UnityEngine_Transform_o *v125;
  UnityEngine_Transform_o *v126;
  u64 *v127;
  s64 *v128;
  UnityEngine_Transform_o *v129;
  u64 *v130;
  System_String_o *v131;
  UnityEngine_Component_o *v132;
  UnityEngine_GameObject_o *v133;
  UnityEngine_Transform_o *v134;
  UnityEngine_Transform_o *v135;
  u64 *v136;
  System_String_o *v137;
  UnityEngine_Component_o *v138;
  UnityEngine_GameObject_o *v139;
  UnityEngine_Transform_o *v140;
  UnityEngine_Transform_o *v141;
  u64 *v142;
  System_String_o *v143;
  UnityEngine_Component_o *v144;
  UnityEngine_GameObject_o *v145;
  UnityEngine_Transform_o *v146;
  System_String_o *v147;
  UnityEngine_Component_o *v148;
  UnityEngine_GameObject_o *v149;
  s32 oz;
  UnityEngine_GameObject_o *v152;
  s32 v153;
  s32 col2;
  s32 v156;
  s32 v157;
  s64 v158;
  u16 d;
  s32 v160;
  s32 v161;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v163;
  UnityEngine_Vector3_o v164;
  UnityEngine_Vector3_o v165;
  UnityEngine_Vector3_o v166;

  oz = (*s)->oz;
LABEL_7:
  if (type == 3)
  {
    p_cnt = &(*s)->cnt;
  }
  else
  {
    p_cnt = &r_a->m_Items[type];
  }
  v158 = *p_cnt;
  BattleUI = GetBattleUI(0);
  if (!op_Equality(BattleUI, 0, 0))
  {
    v152 = BattleUI;
    if (v158 < 1)
    {
      v157 = 0;
      if (type == 3)
        goto LABEL_101;
    }
    else
    {
      v15 = *s;
      v16 = -66;
      drawlisty = (*s)->drawlisty;
      v18 = 0;
      v19 = 0;
      v157 = 0;
      v153 = (*s)->drawlisty;
      do
      {
        commcnt = v15->commcnt;
        if (drawlisty < commcnt->m_Items[type])
        {
          commlist = (*s)->commlist;
          v24 = commlist->m_Items[type];
          v25 = v153 + v19;
          d = v24->m_Items[drawlisty];
          v27 = *s;
          if (v25 == (*s)->drawcursor)
          {
            v28 = 1;
            v156 = -1979777280;
            commdisable = v27->commdisable;
            if (LODWORD(commdisable->max_length) <= type)
              goto LABEL_42;
          }
          else
          {
            v30 = v27->commdisable;
            v32 = v30->m_Items[type];
            v28 = 2 * (v32->m_Items[drawlisty] != 0);
            if (v32->m_Items[drawlisty])
              v34 = 1296780032;
            else
              v34 = -1600273664;
            v156 = v34;
            commdisable = (*s)->commdisable;
            if (LODWORD(commdisable->max_length) <= type)
            {
LABEL_42:
            }
          }
          v36 = commdisable->m_Items[type];
          if (v36->m_Items[drawlisty])
            v38 = 2;
          else
            v38 = v28;
          col2 = v38;
          ComList = GetComList(v19);
          if (!get_activeSelf(ComList))
            SetActive(ComList, 1, 0);
          transform = get_transform(ComList, 0);
          v41 = Find(transform, "num_hp01", 0);
          gameObject = get_gameObject(v41);
          if (get_activeSelf(gameObject))
          {
            v43 = get_transform(ComList, 0);
            v44 = Find(v43, "num_hp01", 0);
            v45 = get_gameObject(v44);
            SetActive(v45, 0, 0);
          }
          v46 = get_transform(ComList, 0);
          v47 = Find(v46, "num_hp02", 0);
          v48 = get_gameObject(v47);
          if (get_activeSelf(v48))
          {
            v49 = get_transform(ComList, 0);
            v50 = Find(v49, "num_hp02", 0);
            v51 = get_gameObject(v50);
            SetActive(v51, 0, 0);
          }
          v52 = get_transform(ComList, 0);
          v53 = Find(v52, "num_hp03", 0);
          v54 = get_gameObject(v53);
          if (get_activeSelf(v54))
          {
            v55 = get_transform(ComList, 0);
            v56 = Find(v55, "num_hp03", 0);
            v57 = get_gameObject(v56);
            SetActive(v57, 0, 0);
          }
          v58 = get_transform(ComList, 0);
          v59 = Find(v58, "bmenu_hp", 0);
          v60 = get_gameObject(v59);
          if (get_activeSelf(v60))
          {
            v61 = get_transform(ComList, 0);
            v62 = Find(v61, "bmenu_hp", 0);
            v63 = get_gameObject(v62);
            SetActive(v63, 0, 0);
          }
          v64 = get_transform(ComList, 0);
          v65 = Find(v64, "bmenu_mp", 0);
          v66 = get_gameObject(v65);
          if (get_activeSelf(v66))
          {
            v67 = get_transform(ComList, 0);
            v68 = Find(v67, "bmenu_mp", 0);
            v69 = get_gameObject(v68);
            SetActive(v69, 0, 0);
          }
          v70 = get_transform(ComList, 0);
          v71 = Find(v70, "num_item_count01", 0);
          v72 = get_gameObject(v71);
          if (get_activeSelf(v72))
          {
            v73 = get_transform(ComList, 0);
            v74 = Find(v73, "num_item_count01", 0);
            v75 = get_gameObject(v74);
            SetActive(v75, 0, 0);
          }
          v76 = get_transform(ComList, 0);
          v77 = Find(v76, "num_item_count02", 0);
          v78 = get_gameObject(v77);
          if (get_activeSelf(v78))
          {
            v79 = get_transform(ComList, 0);
            v80 = Find(v79, "num_item_count02", 0);
            v81 = get_gameObject(v80);
            SetActive(v81, 0, 0);
          }
          v82 = get_transform(ComList, 0);
          v83 = Find(v82, "bmenu_multiply", 0);
          v84 = get_gameObject(v83);
          if (get_activeSelf(v84))
          {
            v90 = get_transform(ComList, 0);
            v91 = Find(v90, "bmenu_multiply", 0);
            v92 = get_gameObject(v91);
            SetActive(v92, 0, 0);
          }
          switch (type)
          {
            case 0:
            case 4:
            case 5:
              DispComm1Comm(s, d, v85, v86, v87, v88, v19, col2);
              break;
            case 1:
              DispComm1Talk(v93, d, v85, v86, v87, v88, v19, col2);
              break;
            case 2:
              DispComm1Item(v94, d, v85, v86, v87, v88, v19, col2);
              break;
            case 3:
              DispComm1Summon(v95, d, v85, v86, v87, v88, v19, col2);
              break;
            default:
              break;
          }
          ++v157;
          if ((v156 | a) == 0x89FEFF80)
          {
            v96 = get_transform(v152, 0);
            if (type == 3)
            {
              v97 = Find(v96, "bmenu/summon_command/bmenu_cursur/bmenu_cursur01", 0);
              v98 = get_gameObject(v97);
              v99 = get_transform(v152, 0);
              v100 = Find(v99, "bmenu/summon_command/bmenu_cursur/bmenu_cursur02", 0);
              v101 = get_gameObject(v100);
              if ((*s)->cnt == 2)
                v102 = 0.0;
              else
                v102 = 100.0;
              v103 = get_transform(v98, 0);
              localPosition = get_localPosition(v103);
              v104 = get_transform(v98, 0);
              v165.x = localPosition.x;
              v165.y = (v102 + 0.0) + v18;
              v165.z = localPosition.z;
              set_localPosition(v104, v165);
              v105 = get_transform(v101, 0);
              v163 = get_localPosition(v105);
              x = v163.x;
              v107 = (v102 + -48.0) + v18;
              z = v163.z;
              v109 = v101;
            }
            else
            {
              v110 = Find(v96, "bmenu/normal_command/bmenu_cursur", 0);
              v111 = get_gameObject(v110);
              v112 = get_transform(v111, 0);
              v164 = get_localPosition(v112);
              x = v164.x;
              z = v164.z;
              v109 = v111;
              v107 = v16;
            }
            v113 = get_transform(v109, 0);
            v166.x = x;
            v166.y = v107;
            v166.z = z;
            set_localPosition(v113, v166);
          }
          if (v25 == (*s)->drawcursor)
          {
            DispHelp1(s, d, v85, v86, oz, v88);
          }
        }
        v15 = *s;
        ++drawlisty;
        ++v19;
        v18 -= 100;
        v16 -= 50;
      }
      while (drawlisty < (*s)->drawlisty + v158);
      BattleUI = v152;
      if (type == 3)
      {
LABEL_101:
        if (v157 <= 0)
        {
          v160 = 1;
          v114 = get_transform(BattleUI, 0);
          v115 = sub_8D3950(s32, &v160);
          v116 = Concat("bmenu/summon_command/bmenu_command/bmenu_command_s0", v115);
          v117 = Find(v114, v116, 0);
          v118 = get_gameObject(v117);
          SetActive(v118, 0, 0);
        }
        else if (v157 != 1)
        {
          if (v157 > 2)
            return;
          goto LABEL_115;
        }
        v119 = get_transform(BattleUI, 0);
        v160 = 2;
        v120 = v119;
        v121 = sub_8D3950(s32, &v160);
        v122 = Concat("bmenu/summon_command/bmenu_command/bmenu_command_s0", v121);
        v123 = Find(v120, v122, 0);
        v124 = get_gameObject(v123);
        SetActive(v124, 0, 0);
LABEL_115:
        v125 = get_transform(BattleUI, 0);
        v160 = 3;
        v126 = v125;
        v127 = sub_8D3950(s32, &v160);
        v128 = &"bmenu/summon_command/bmenu_command/bmenu_command_s0";
LABEL_120:
        v147 = Concat(*v128, v127);
        v148 = Find(v126, v147, 0);
        v149 = get_gameObject(v148);
        SetActive(v149, 0, 0);
        return;
      }
    }
    if (v157 <= 0)
    {
      v161 = 1;
      v129 = get_transform(BattleUI, 0);
      v130 = sub_8D3950(s32, &v161);
      v131 = Concat("bmenu/normal_command/bmenu_command/bmenu_command0", v130);
      v132 = Find(v129, v131, 0);
      v133 = get_gameObject(v132);
      SetActive(v133, 0, 0);
    }
    else if (v157 != 1)
    {
      if (v157 > 2)
      {
        if (v157 != 3)
          return;
LABEL_119:
        v146 = get_transform(BattleUI, 0);
        v161 = 4;
        v126 = v146;
        v127 = sub_8D3950(s32, &v161);
        v128 = &"bmenu/normal_command/bmenu_command/bmenu_command0";
        goto LABEL_120;
      }
LABEL_118:
      v140 = get_transform(BattleUI, 0);
      v161 = 3;
      v141 = v140;
      v142 = sub_8D3950(s32, &v161);
      v143 = Concat("bmenu/normal_command/bmenu_command/bmenu_command0", v142);
      v144 = Find(v141, v143, 0);
      v145 = get_gameObject(v144);
      SetActive(v145, 0, 0);
      goto LABEL_119;
    }
    v134 = get_transform(BattleUI, 0);
    v161 = 2;
    v135 = v134;
    v136 = sub_8D3950(s32, &v161);
    v137 = Concat("bmenu/normal_command/bmenu_command/bmenu_command0", v136);
    v138 = Find(v135, v137, 0);
    v139 = get_gameObject(v138);
    SetActive(v139, 0, 0);
    goto LABEL_118;
  }
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
      goto LABEL_66;
    goto LABEL_18;
  }
  cnt = r_a->m_Items[type];
  v16 = *s;
  if (type > 5)
  {
    v18 = 0;
    if (cnt < 1)
      goto LABEL_66;
    goto LABEL_18;
  }
  v7 += 345;
  v18 = 21;
  v36 += 27;
  if (cnt >= 1)
  {
LABEL_18:
    v22 = (v6 << 24) | 0x808080;
    drawlisty = v16->drawlisty;
    v35 = v22;
    do
    {
      commcnt = v16->commcnt;
      if (drawlisty >= commcnt->m_Items[type])
        goto LABEL_65;
      commlist = (*s)->commlist;
      v28 = commlist->m_Items[type];
      v30 = v28->m_Items[drawlisty];
      drawcursor = (*s)->drawcursor;
      if (drawlisty == drawcursor)
      {
        if ((*s)->nowstat != 2)
          goto LABEL_37;
        DispComm1PanelCursor(s, type, v36, v7, v13, v35);
        drawcursor = (*s)->drawcursor;
      }
      if (drawlisty == drawcursor)
      {
LABEL_37:
        evtBitCheck(3086);
      }
      switch (type)
      {
        case 0:
          else if ((byte_3F5A3DB & 1) != 0)
          {
            goto LABEL_49;
          }
LABEL_49:
          if ((v30 & 0xFFFC) == 0x8000)
            goto LABEL_64;
          if (v30 < LODWORD(tbl->max_length))
            goto LABEL_64;
          goto LABEL_63;
        case 1:
        case 2:
          goto LABEL_64;
        case 3:
          else if ((byte_3F5A3DC & 1) != 0)
          {
            goto LABEL_59;
          }
LABEL_59:
          if (v30 >= LODWORD(DDS3_GBWK->unitwork->max_length))
          {
LABEL_63:
          }
LABEL_64:
          v7 += v18;
          break;
        default:
          goto LABEL_64;
      }
LABEL_65:
      v16 = *s;
      ++drawlisty;
    }
    while (drawlisty < (*s)->drawlisty + cnt);
  }
LABEL_66:
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
    v13 = Find(transform, "bhelp_window/TextTM", 0);
    gameObject = get_gameObject(v13);
    Component_object = GetComponent_object_(gameObject);
    v16 = "";
    v17 = Component_object;
    v18 = get_transform(BattleUI, 0);
    v19 = Find(v18, "bhelp_window", 0);
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
              goto LABEL_46;
            case 0x8001u:
              goto LABEL_23;
            case 0x8002u:
              {
              }
              v22 = 2;
              goto LABEL_46;
            case 0x8003u:
              goto LABEL_27;
            default:
              goto LABEL_37;
          }
        case 1:
          if (d == 32772)
          {
            {
            }
            v22 = 3;
LABEL_46:
            v27 = Get(v22, 0);
          }
          else
          {
LABEL_37:
            v23 = oz;
            v24 = 0;
LABEL_38:
            HelpForUnity = frwGetHelpForUnity(0, 0, v23, v24, d, 1);
            v27 = CutAF_DEL(HelpForUnity);
          }
          v16 = v27;
LABEL_48:
          v28 = Replace_5267216(v16, "\n", "");
          set_text(v17, v28);
          break;
        case 2:
          v23 = oz;
          v24 = 1;
          goto LABEL_38;
        case 4:
LABEL_27:
          {
          }
          v22 = 5;
          goto LABEL_46;
        case 5:
LABEL_23:
          {
          }
          v22 = 4;
          goto LABEL_46;
        default:
          goto LABEL_48;
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

LABEL_7:
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
    v19 = Find(transform, "bmenu/bmenu_scroll_up/bmenu_scroll_on", 0);
    gameObject = get_gameObject(v19);
    v21 = get_transform(BattleUI, 0);
    v22 = Find(v21, "bmenu/bmenu_scroll_down/bmenu_scroll_on", 0);
    v23 = get_gameObject(v22);
    nowlisty = (*s)->nowlisty;
    v25 = v23;
    v27 = nowlisty->m_Items[type];
    activeSelf = get_activeSelf(gameObject);
    if (v17 > 0xD || v27 < 1)
    {
      if (!activeSelf)
        goto LABEL_32;
      v29 = gameObject;
      v30 = 0;
    }
    else
    {
      if (activeSelf)
        goto LABEL_32;
      v29 = gameObject;
      v30 = 1;
    }
    SetActive(v29, v30, 0);
LABEL_32:
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
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  u64 *v7;
  System_String_o *v8;
  UnityEngine_Component_o *v9;
  s32 v11;

  BattleUI = GetBattleUI(0);
  gameObject = 0;
  if (!op_Equality(BattleUI, 0, 0))
  {
    v11 = listidx + 1;
    transform = get_transform(BattleUI, 0);
    v7 = sub_8D3950(s32, &v11);
    v8 = Concat("bmenu/normal_command/bmenu_command/bmenu_command0", v7);
    v9 = Find(transform, v8, 0);
    gameObject = get_gameObject(v9);
    if (!get_activeSelf(gameObject))
      SetActive(gameObject, 1, 0);
  }
  return gameObject;
}

// 0x16df070
void *GetComListS(s32 listidx) {
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  u64 *v7;
  System_String_o *v8;
  UnityEngine_Component_o *v9;
  s32 v11;

  BattleUI = GetBattleUI(0);
  gameObject = 0;
  if (!op_Equality(BattleUI, 0, 0))
  {
    v11 = listidx + 1;
    transform = get_transform(BattleUI, 0);
    v7 = sub_8D3950(s32, &v11);
    v8 = Concat("bmenu/summon_command/bmenu_command/bmenu_command_s0", v7);
    v9 = Find(transform, v8, 0);
    gameObject = get_gameObject(v9);
    if (!get_activeSelf(gameObject))
      SetActive(gameObject, 1, 0);
  }
  return gameObject;
}

// 0x16df1a0
void *GetComTextTM(void *ComListObj) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v4;
  UnityEngine_Object_o *gameObject;
  bool v7;
  TMPro_TextMeshProUGUI_o *result;

  transform = get_transform(ComListObj, 0);
  v4 = Find(transform, "bmenu_text01TM", 0);
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
  nbCommSelProcessData_t_o *result;
  nbCommSelProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  dds3ProcessID_t_o *v7[3];
  dds3ProcessID_t_o *id;

  id = 0;
  id = dds3SearchProcessName("nb_commsel");
  result = dds3GetProcessData(&id);
  if (result)
  {
    klass = result->klass;
    if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbCommSelProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbCommSelProcessData_t, v7);
      if ((v7[0] & 1) != 0)
        v5 = v7[2];
      else
        v5 = v7 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  return result;
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
      goto LABEL_19;
    case 2u:
      v16 = 5;
      goto LABEL_18;
    case 3u:
      v16 = 6;
LABEL_18:
      UnitWorkPointer->nowcommand = v16;
LABEL_19:
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
  v4 = Find(transform, "steff", 0);
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
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v7;
  UnityEngine_GameObject_o *gameObject;
  nbCommSelProcessData_t_o *v9;
  struct System_Int32_array *v10;
  s64 v11;
  s64 v12;
  char *v14;
  struct System_Int32_array *v15;
  s32 v17;
  bool v18;
  bool v19;
  UnityEngine_Transform_o *v20;
  UnityEngine_Component_o *v21;
  UnityEngine_GameObject_o *v22;
  Il2CppObject *v23;
  s64 nowtype;
  nbCommSelProcessData_t_o *v25;
  s32 *p_cnt;
  struct System_Int32_array *r_a;
  struct System_Int32_array *nowcursor;
  s32 v31;
  s64 v32;
  u32 v33;
  char *v35;
  struct System_Int32_array *nowlisty;
  s32 v37;
  struct System_Int32_array *commcnt;
  s32 v40;
  s32 v42;
  s32 v43;
  s32 v47;
  s32 v48;
  UnityEngine_GameObject_o *v49;
  s32 v50;
  struct System_Int32_array *v51;
  s64 v52;
  struct System_Int32_array *v54;
  s64 v55;
  struct System_Int32_array *v57;
  s64 v58;
  nbMainProcessData_t_o *data;
  nbParty_t_o *my;
  s32 v63;
  s32 NextCommType;
  s32 v67;
  bool v68;
  s32 v69;
  s32 v72;
  s32 v73;
  bool v74;
  s32 v75;
  UnityEngine_Transform_o *v77;
  UnityEngine_Component_o *v78;
  UnityEngine_GameObject_o *v79;
  Il2CppObject *Component_object;
  s32 v81;
  System_String_o *v82;
  s32 v83;
  struct System_Int32_array *v88;
  struct System_Int32_array *v90;
  UnityEngine_Transform_o *v92;
  UnityEngine_Component_o *v93;
  UnityEngine_GameObject_o *v94;
  Il2CppObject *v95;
  struct System_Int32_array *v96;
  s64 v97;
  nbCommSelProcessData_t_o *v99;
  struct System_Int32_array *v100;
  s64 v101;
  u64 v103;
  struct System_Int32_array *v104;
  s64 v105;
  struct System_UInt16_array_array *commlist;
  s64 v108;
  System_UInt16_array *v110;
  struct System_Int32_array *v112;
  s64 v113;

  if (((*s)->data->stat & 0x200000) == 0)
  {
    BattleUI = GetBattleUI(0);
    if (op_Inequality(BattleUI, 0, 0))
    {
      transform = get_transform(BattleUI, 0);
      v7 = Find(transform, "bmenu/normal_command/bmenu_cursur", 0);
      gameObject = get_gameObject(v7);
      if (!get_activeSelf(gameObject))
        SetActive(gameObject, 1, 0);
    }
    if ((*s)->nowtype != 3)
    {
LABEL_63:
      if (((*s)->animeflag & 4) != 0)
        return;
      nowtype = (*s)->nowtype;
      if (nowtype == 3)
      {
        v25 = *s;
        p_cnt = &(*s)->cnt;
      }
      else
      {
        p_cnt = &r_a->m_Items[nowtype];
        v25 = *s;
      }
      nowcursor = v25->nowcursor;
      v31 = *p_cnt;
      v32 = v25->nowtype;
      v33 = v25->nowtype;
      v35 = nowcursor + 4 * v32;
      nowlisty = v25->nowlisty;
      v37 = *(v35 + 8);
      commcnt = v25->commcnt;
      v40 = nowlisty->m_Items[v32];
      v42 = commcnt->m_Items[v25->nowtype];
      if (v42 < 2)
      {
        v43 = -1;
        goto LABEL_138;
      }
      if (DDS3_PADCHECK_REP(6))
      {
        if (v37)
        {
          if (v31 < 4 || v37 > v40 + 1)
          {
            v47 = v37-- <= v40;
            v40 -= v47;
            v43 = 4;
              goto LABEL_113;
          }
          else
          {
            if (v40 <= 0)
              v40 = 0;
            else
              --v40;
            --v37;
            v43 = 4;
              goto LABEL_113;
          }
        }
        else
        {
          if (DDS3_PADCHECK_TRIG(6))
          {
            v37 = v42 - 1;
            v40 = (v42 - v31) & ~((v42 - v31) >> 31);
            v43 = 4;
              goto LABEL_113;
          }
          else
          {
            v37 = 0;
            v43 = -1;
              goto LABEL_113;
          }
        }
      }
      else
      {
        v43 = -1;
          goto LABEL_113;
      }
LABEL_113:
      if (DDS3_PADCHECK_REP(7))
      {
LABEL_114:
        v48 = v31;
        v49 = BattleUI;
        if (v37 == v42 - 1)
        {
          if (DDS3_PADCHECK_TRIG(7))
          {
            v43 = 4;
            v40 = 0;
            v37 = 0;
          }
          else
          {
            v37 = v42 - 1;
          }
        }
        else
        {
          v50 = v40 + v48;
          if (v48 < 4 || v37 < v50 - 2)
          {
            if (++v37 >= v50)
              ++v40;
          }
          else
          {
            if (v40 + 1 + v48 <= v42)
              ++v40;
            else
              v40 = v42 - v48;
            ++v37;
          }
          v43 = 4;
        }
        goto LABEL_131;
      }
LABEL_121:
      v49 = BattleUI;
LABEL_131:
      v51 = (*s)->nowcursor;
      v52 = (*s)->nowtype;
      v51->m_Items[v52] = v37;
      v54 = (*s)->nowlisty;
      v55 = (*s)->nowtype;
      v54->m_Items[v55] = v40;
      v57 = (*s)->commcnt;
      v58 = (*s)->nowtype;
      BattleUI = v49;
      v57->m_Items[v58] = v42;
LABEL_138:
      data = (*s)->data;
      my = (*s)->my;
      nbGetUnitWorkPointer(data, my);
      v63 = (*s)->nowtype;
      if (DDS3_PADCHECK_REP(4))
      {
        NextCommType = GetNextCommType(s, 0);
        if (NextCommType != (*s)->nowtype)
        {
          v67 = NextCommType;
          v68 = DDS3_PADCHECK_TRIG(4);
          v69 = (*s)->nowtype;
          if (v68 && v67 > v69 || v67 < v69)
          {
            v43 = 4;
            (*s)->nowtype = v67;
          }
        }
      }
      if (DDS3_PADCHECK_REP(5))
      {
        v72 = GetNextCommType(s, 1);
        if (v72 != (*s)->nowtype)
        {
          v73 = v72;
          v74 = DDS3_PADCHECK_TRIG(5);
          v75 = (*s)->nowtype;
          if (v74 && v73 < v75 || v73 > v75)
          {
            v43 = 4;
            (*s)->nowtype = v73;
          }
        }
      }
      if (op_Inequality(BattleUI, 0, 0))
      {
        v77 = get_transform(BattleUI, 0);
        v78 = Find(v77, "bmenu", 0);
        v79 = get_gameObject(v78);
        Component_object = GetComponent_object_(v79);
        v81 = (*s)->nowtype;
        if (v81 != v63)
        {
          if (v81 == 3)
          {
            v82 = "bmenu";
            if ((*s)->cnt == 2)
              v83 = 2;
            else
              v83 = 4;
            goto LABEL_182;
          }
          if (v63 == 3)
          {
            v82 = "bmenu";
            v83 = 1;
LABEL_182:
            SetInteger(Component_object, v82, v83);
          }
        }
      }
      else if (DDS3_PADCHECK_REP(1))
      {
        goto LABEL_186;
      }
      if (DDS3_PADCHECK_TRIG(3))
      {
        if ((*s)->nowtype)
          goto LABEL_209;
        v88 = (*s)->nowcursor;
        if (v88->m_Items[0])
          goto LABEL_209;
        v90 = (*s)->nowlisty;
        if (v90->m_Items[0])
        {
LABEL_209:
          if ((*s)->nowtype == 3)
          {
            if (op_Inequality(BattleUI, 0, 0))
            {
              v92 = get_transform(BattleUI, 0);
              v93 = Find(v92, "bmenu", 0);
              v94 = get_gameObject(v93);
              v95 = GetComponent_object_(v94);
              SetInteger(v95, "bmenu", 1);
            }
          }
          (*s)->nowtype = 0;
          v96 = (*s)->nowcursor;
          v97 = (*s)->nowtype;
          v96->m_Items[v97] = 0;
          v99 = *s;
          v100 = (*s)->nowlisty;
          v101 = v99->nowtype;
          v100->m_Items[v101] = 0;
          v43 = 10;
            goto LABEL_249;
          goto LABEL_248;
        }
      }
      else
      {
        if (DDS3_PADCHECK_TRIG(0))
        {
          v103 = 0;
          (*s)->nowtype = 0;
          while (1)
          {
            v104 = (*s)->commcnt;
            v105 = (*s)->nowtype;
            if (v103 >= v104->m_Items[v105])
              break;
            commlist = (*s)->commlist;
            v108 = (*s)->nowtype;
            v110 = commlist->m_Items[v108];
            if (v110->m_Items[v103] == 32770)
            {
              v112 = (*s)->nowcursor;
              v113 = (*s)->nowtype;
              v112->m_Items[v113] = v103;
              break;
            }
            ++v103;
          }
          (*s)->nowstat = 3;
          MemoryCommand(s);
          v43 = 8;
          wait_se2 = 1;
            goto LABEL_249;
          goto LABEL_248;
        }
      }
      goto LABEL_247;
    }
    else if (DDS3_PADCHECK_TRIG(6))
    {
      goto LABEL_31;
    }
    if (!DDS3_PADCHECK_TRIG(7))
    {
      if (!DDS3_PADCHECK_REP(6))
      {
        if (!DDS3_PADCHECK_REP(7))
          goto LABEL_63;
      }
    }
LABEL_31:
    v9 = *s;
    if ((*s)->cnt != 2)
      goto LABEL_63;
    v10 = v9->nowcursor;
    v11 = v9->nowtype;
    v12 = v11;
    v14 = v10 + 4 * v11;
    v15 = v9->nowlisty;
    v17 = *(v14 + 8) - v15->m_Items[v12];
    if (DDS3_PADCHECK_TRIG(6))
    {
      if (!v17)
        goto LABEL_58;
    }
    else
    {
      v18 = DDS3_PADCHECK_REP(6);
      if (!v17 && v18)
        goto LABEL_58;
    }
    if (DDS3_PADCHECK_TRIG(7))
    {
      if (v17 != 1)
        goto LABEL_63;
    }
    else
    {
      v19 = DDS3_PADCHECK_REP(7);
      if (v17 != 1 || !v19)
        goto LABEL_63;
    }
LABEL_58:
    (*s)->cnt = 3;
    (*s)->animeflag |= 4u;
    (*s)->openwait = 10;
    if (op_Inequality(BattleUI, 0, 0))
    {
      v20 = get_transform(BattleUI, 0);
      v21 = Find(v20, "bmenu", 0);
      v22 = get_gameObject(v21);
      v23 = GetComponent_object_(v22);
      SetInteger(v23, "bmenu", 3);
    }
    goto LABEL_63;
  }
}

// 0x16e23d0
void SelectCommandListAuto(nbCommSelProcessData_t **s) {
  nbCommSelProcessData_t_o **v5;

  else if (CheckSelectError(s))
  {
    return;
  }
  (*s)->nowstat = 3;
  else
  {
    v5 = s;
  }
  MemoryCommand(v5);
}

// 0x16e4e30
void SetCommCursor2(nbCommSelProcessData_t **s) {
  nbMainProcessData_t_o *data;
  nbParty_t_o *my;
  datUnitWork_t_o *UnitWorkPointer;
  s32 prevcommand;
  s32 previndex;
  s32 v13;
  u64 v14;
  u64 i;
  struct System_Int32_array *commcnt;
  struct System_UInt16_array_array *commlist;
  System_UInt16_array *v20;
  s32 v22;
  nbCommSelProcessData_t_o **v23;
  s32 v24;

  data = (*s)->data;
  my = (*s)->my;
  UnitWorkPointer = nbGetUnitWorkPointer(data, my);
  prevcommand = UnitWorkPointer->prevcommand;
  previndex = UnitWorkPointer->previndex;
  if (!dds3CheckConfigBit(0xCu))
    goto LABEL_14;
LABEL_9:
    goto LABEL_17;
LABEL_10:
LABEL_17:
  if (!dds3CheckConfigBit(0xBu))
  {
LABEL_18:
    v13 = ((*s)->act->stat << 24) >> 31;
    previndex &= v13;
    prevcommand &= v13;
  }
LABEL_19:
  v14 = 0;
  for (i = 0; ; i = 0)
  {
    while (1)
    {
      commcnt = (*s)->commcnt;
      if (i >= commcnt->m_Items[v14])
        break;
      commlist = (*s)->commlist;
      v20 = commlist->m_Items[v14];
      v22 = v20->m_Items[i];
      switch (v20->m_Items[i])
      {
        case 0x8000u:
          if (!prevcommand)
            goto LABEL_30;
          goto LABEL_20;
        case 0x8001u:
          if (prevcommand == 2)
            goto LABEL_30;
          goto LABEL_20;
        case 0x8002u:
          if (prevcommand == 3)
            goto LABEL_30;
          goto LABEL_20;
        case 0x8003u:
          if (prevcommand == 7)
          {
LABEL_30:
            v23 = s;
            v24 = v14;
            goto LABEL_34;
          }
          goto LABEL_20;
        case 0x8004u:
          goto LABEL_20;
        default:
          if (v14 == 2)
          {
            if (prevcommand == 5 && previndex == v22)
            {
              v23 = s;
              v24 = 2;
              goto LABEL_34;
            }
          }
          else if (v14 == 1)
          {
            if (prevcommand == 4 && previndex == v22)
            {
              v23 = s;
              v24 = 1;
              goto LABEL_34;
            }
          }
          else if (!v14 && prevcommand == 1 && previndex == v22)
          {
            v23 = s;
            v24 = 0;
LABEL_34:
            SetPrevCursor(v23, v24, i);
          }
LABEL_20:
          ++i;
          break;
      }
    }
    if (++v14 == 6)
      break;
  }
}

// 0x16e3060
void SetCommList(nbCommSelProcessData_t **s, nbParty_t *my) {
  nbMainProcessData_t_o *data;
  datUnitWork_t_o *UnitWorkPointer;
  struct System_Int32_array *commcnt;
  u16 badstatus;
  datUnitWork_t_o *v10;
  struct System_Int32_array *v12;
  struct System_Int32_array *v14;
  struct System_Int32_array *v16;
  struct System_Int32_array *v18;
  struct System_Int32_array *v20;
  struct System_UInt16_array_array *commlist;
  struct System_Int32_array *v23;
  System_UInt16_array *v24;
  s64 v25;
  struct System_SByte_array_array *commdisable;
  struct System_Int32_array *v28;
  System_SByte_array *v29;
  s64 v30;
  struct System_Int32_array *v32;
  struct System_UInt16_array_array *v34;
  struct System_Int32_array *v36;
  System_UInt16_array *v37;
  s64 v39;
  struct System_SByte_array_array *v41;
  struct System_Int32_array *v43;
  System_SByte_array *v44;
  s64 v46;
  struct System_SByte_array_array *v48;
  struct System_Int32_array *v50;
  System_SByte_array *v51;
  s64 v53;
  struct System_Int32_array *v55;
  nbCommSelProcessData_t_o *v57;
  u32 stat;
  s32 skillcnt;
  u64 v60;
  s64 v61;
  struct System_Int32_array *skill;
  s32 v64;
  struct datSkill_t_array *tbl;
  struct datNormalSkill_t_array *v69;
  struct System_UInt16_array_array *v71;
  struct System_Int32_array *v72;
  System_UInt16_array *v73;
  s64 v74;
  struct System_SByte_array_array *v76;
  struct System_Int32_array *v77;
  System_SByte_array *v78;
  s64 v79;
  struct datNormalSkill_t_array *v82;
  nbCommSelProcessData_t_o *v84;
  struct System_SByte_array_array *v85;
  struct System_Int32_array *v86;
  System_SByte_array *v87;
  s64 v88;
  struct datNormalSkill_t_array *v91;
  nbCommSelProcessData_t_o *v93;
  struct System_SByte_array_array *v94;
  struct System_Int32_array *v95;
  System_SByte_array *v96;
  s64 v97;
  struct System_SByte_array_array *v99;
  struct System_Int32_array *v100;
  System_SByte_array *v101;
  s64 v102;
  struct datNormalSkill_t_array *v105;
  struct System_SByte_array_array *v107;
  struct System_Int32_array *v108;
  System_SByte_array *v109;
  s64 v110;
  struct System_SByte_array_array *v112;
  struct System_Int32_array *v113;
  System_SByte_array *v114;
  s64 v115;
  char *v117;
  char v118;
  struct datNegoSkill_t_array *v120;
  struct System_UInt16_array_array *v122;
  System_UInt16_array *v124;
  struct System_Int32_array *v125;
  s64 v127;
  struct System_SByte_array_array *v129;
  struct System_Int32_array *v131;
  System_SByte_array *v132;
  s64 v134;
  struct System_SByte_array_array *v136;
  struct System_Int32_array *v138;
  System_SByte_array *v139;
  s64 v141;
  struct System_Int32_array *v143;
  nbCommSelProcessData_t_o *v149;
  struct System_Int32_array *v155;
  struct System_UInt16_array_array *v169;
  u32 max_length;
  struct System_Int32_array *v172;
  System_UInt16_array *v173;
  s64 v175;
  struct System_SByte_array_array *v177;
  struct System_Int32_array *v179;
  System_SByte_array *v180;
  s64 v182;
  struct System_Int32_array *v184;
  struct System_Int32_array *v187;
  System_UInt16_array *v188;
  s64 v190;
  struct System_SByte_array_array *v192;
  struct System_Int32_array *v194;
  System_SByte_array *v195;
  s64 v197;
  struct System_SByte_array_array *v200;
  struct System_Int32_array *v202;
  System_SByte_array *v203;
  s64 v205;
  struct System_Int32_array *v207;
  struct System_UInt16_array_array *v209;
  struct System_Int32_array *v210;
  System_UInt16_array *v211;
  s64 v212;
  struct System_SByte_array_array *v214;
  struct System_Int32_array *v215;
  System_SByte_array *v216;
  s64 v217;
  struct System_Int32_array *v219;
  u64 i;
  struct datItem_t_array *v222;
  struct System_Byte_array *item;
  u64 max_length_low;
  struct System_UInt16_array_array *v229;
  struct System_Int32_array *v231;
  System_UInt16_array *v232;
  s64 v234;
  struct System_SByte_array_array *v236;
  struct System_Int32_array *v238;
  System_SByte_array *v239;
  s64 v241;
  struct datItem_t_array *v244;
  nbCommSelProcessData_t_o *v246;
  struct System_SByte_array_array *v247;
  struct System_Int32_array *v249;
  System_SByte_array *v250;
  s64 v252;
  struct datItem_t_array *v255;
  nbCommSelProcessData_t_o *v257;
  struct System_SByte_array_array *v258;
  struct System_Int32_array *v260;
  System_SByte_array *v261;
  s64 v263;
  struct System_SByte_array_array *v265;
  struct System_Int32_array *v267;
  System_SByte_array *v268;
  s64 v270;
  struct System_Int32_array *v272;
  u64 v274;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Int32_array *stocklist;
  struct datUnitWork_t_array *unitwork;
  s64 v280;
  struct datUnitWork_t_array *v283;
  struct datUnitWork_t_array *v286;
  struct System_UInt16_array_array *v288;
  struct System_Int32_array *v290;
  System_UInt16_array *v291;
  s64 v293;
  struct System_SByte_array_array *v295;
  struct System_Int32_array *v297;
  System_SByte_array *v298;
  s64 v300;
  struct datUnitWork_t_array *v303;
  struct datUnitWork_t_array *v306;
  struct System_SByte_array_array *v308;
  struct System_Int32_array *v310;
  System_SByte_array *v311;
  s64 v313;
  struct System_Int32_array *v315;
  s32 v325;

  data = (*s)->data;
  UnitWorkPointer = nbGetUnitWorkPointer(data, my);
  commcnt = (*s)->commcnt;
  badstatus = UnitWorkPointer->badstatus;
  v10 = UnitWorkPointer;
  commcnt->m_Items[0] = 0;
  v12 = (*s)->commcnt;
  v12->m_Items[1] = 0;
  v14 = (*s)->commcnt;
  v14->m_Items[2] = 0;
  v16 = (*s)->commcnt;
  v16->m_Items[3] = 0;
  v18 = (*s)->commcnt;
  v18->m_Items[4] = 0;
  v20 = (*s)->commcnt;
  v20->m_Items[5] = 0;
  commlist = (*s)->commlist;
  v23 = (*s)->commcnt;
  v24 = commlist->m_Items[0];
  v25 = v23->m_Items[0];
  v24->m_Items[v25] = 0x8000;
  commdisable = (*s)->commdisable;
  v28 = (*s)->commcnt;
  v29 = commdisable->m_Items[0];
  v30 = v28->m_Items[0];
  v29->m_Items[v30] = 0;
  v32 = (*s)->commcnt;
  v325 = badstatus & 0xFFF;
  ++v32->m_Items[0];
  if ((UnitWorkPointer->flag & 4) != 0)
  {
    v34 = (*s)->commlist;
    v36 = (*s)->commcnt;
    v37 = v34->m_Items[1];
    v39 = v36->m_Items[1];
    v37->m_Items[v39] = -32764;
    v41 = (*s)->commdisable;
    v43 = (*s)->commcnt;
    v44 = v41->m_Items[1];
    v46 = v43->m_Items[1];
    v44->m_Items[v46] = 0;
    if (v325 == 512)
    {
      v48 = (*s)->commdisable;
      v50 = (*s)->commcnt;
      v51 = v48->m_Items[1];
      v53 = v50->m_Items[1];
      v51->m_Items[v53] = 5;
    }
    v55 = (*s)->commcnt;
    ++v55->m_Items[1];
  }
  v57 = *s;
  stat = (*s)->data->stat;
  if ((stat & 0x4000000) != 0)
  {
    skillcnt = 512;
  }
  else
  {
    skillcnt = UnitWorkPointer->skillcnt;
    if (skillcnt < 1)
      goto LABEL_199;
  }
  v60 = 0;
  v61 = skillcnt - 1LL;
  if ((stat & 0x4000000) == 0)
    goto LABEL_59;
LABEL_133:
  v64 = v60;
  if (v60)
  {
    while (1)
    {
      if (tbl->m_Items[v64]->type == 2)
      {
        v120 = tbl;
        if (v120->m_Items[v64 - 384]->type <= 6)
        {
          v122 = (*s)->commlist;
          v124 = v122->m_Items[1];
          v125 = (*s)->commcnt;
          v127 = v125->m_Items[1];
          v124->m_Items[v127] = v64;
          v129 = (*s)->commdisable;
          v131 = (*s)->commcnt;
          v132 = v129->m_Items[1];
          v134 = v131->m_Items[1];
          v132->m_Items[v134] = 0;
          if (v325 == 512)
          {
            v136 = (*s)->commdisable;
            v138 = (*s)->commcnt;
            v139 = v136->m_Items[1];
            v141 = v138->m_Items[1];
            v139->m_Items[v141] = 5;
          }
          v143 = (*s)->commcnt;
          ++v143->m_Items[1];
        }
        goto LABEL_164;
      }
      if (tbl->m_Items[v64]->type)
        goto LABEL_164;
      v69 = tbl;
      if ((v69->m_Items[v64]->use & 2) == 0)
        goto LABEL_164;
      v71 = (*s)->commlist;
      v72 = (*s)->commcnt;
      v73 = v71->m_Items[0];
      v74 = v72->m_Items[0];
      v73->m_Items[v74] = v64;
      v76 = (*s)->commdisable;
      v77 = (*s)->commcnt;
      v78 = v76->m_Items[0];
      v79 = v77->m_Items[0];
      v78->m_Items[v79] = 0;
      v82 = tbl;
      if ((v82->m_Items[v64]->flag & 1) != 0)
      {
        v84 = *s;
        if (((*s)->data->stat & 1) != 0)
        {
          v85 = v84->commdisable;
          v86 = v84->commcnt;
          v87 = v85->m_Items[0];
          v88 = v86->m_Items[0];
          v87->m_Items[v88] = 1;
        }
      }
      v91 = tbl;
      if ((v91->m_Items[v64]->flag & 2) != 0)
      {
        v93 = *s;
        if (((*s)->data->stat & 4) != 0)
        {
          v94 = v93->commdisable;
          v95 = v93->commcnt;
          v96 = v94->m_Items[0];
          v97 = v95->m_Items[0];
          v96->m_Items[v97] = 2;
        }
      }
      if (nbCheckSkillCost((*s)->my->formindex, v64, 0))
      {
        v99 = (*s)->commdisable;
        v100 = (*s)->commcnt;
        v101 = v99->m_Items[0];
        v102 = v100->m_Items[0];
        v101->m_Items[v102] = 3;
      }
      v105 = tbl;
      if (v105->m_Items[v64]->koukatype == 1 && (v10->badstatus & 0xFFF) == 0x20)
      {
        v107 = (*s)->commdisable;
        v108 = (*s)->commcnt;
        v109 = v107->m_Items[0];
        v110 = v108->m_Items[0];
        v109->m_Items[v110] = 5;
      }
      if (v64 != 223)
        break;
      v149 = *s;
      if ((*s)->data->playerpcnt >= 4)
        goto LABEL_175;
      if (nbGetRandamStock() < 0)
        goto LABEL_174;
LABEL_181:
      v155 = (*s)->commcnt;
      ++v155->m_Items[0];
      v57 = *s;
      if (v61 == v60)
        goto LABEL_199;
LABEL_58:
      ++v60;
      if ((v57->data->stat & 0x4000000) != 0)
        goto LABEL_133;
LABEL_59:
      skill = v10->skill;
      v64 = skill->m_Items[v60];
      if (!v64)
        goto LABEL_164;
    }
    if (v64 != 72 || nbGetEscapeSwitch((*s)->data, 0))
      goto LABEL_181;
    v112 = (*s)->commdisable;
    v113 = (*s)->commcnt;
    v114 = v112->m_Items[0];
    v115 = v113->m_Items[0];
    v117 = v114 + v115;
    v118 = 1;
    goto LABEL_180;
  }
LABEL_164:
  v57 = *s;
  if (v61 != v60)
    goto LABEL_58;
LABEL_199:
  v169 = v57->commlist;
  max_length = v169->max_length;
  if ((v10->flag & 4) == 0)
  {
    v172 = v57->commcnt;
    v173 = v169->m_Items[4];
    v175 = v172->m_Items[4];
    v173->m_Items[v175] = -32765;
    v177 = (*s)->commdisable;
    v179 = (*s)->commcnt;
    v180 = v177->m_Items[4];
    v182 = v179->m_Items[4];
    v180->m_Items[v182] = 0;
    v184 = (*s)->commcnt;
    ++v184->m_Items[4];
    v57 = *s;
    v169 = (*s)->commlist;
    max_length = v169->max_length;
  }
  v187 = v57->commcnt;
  v188 = v169->m_Items[5];
  v190 = v187->m_Items[5];
  v188->m_Items[v190] = -32767;
  v192 = (*s)->commdisable;
  v194 = (*s)->commcnt;
  v195 = v192->m_Items[5];
  v197 = v194->m_Items[5];
  v195->m_Items[v197] = 0;
  if (!nbGetEscapeSwitch((*s)->data, 0))
  {
    v200 = (*s)->commdisable;
    v202 = (*s)->commcnt;
    v203 = v200->m_Items[5];
    v205 = v202->m_Items[5];
    v203->m_Items[v205] = 1;
  }
  v207 = (*s)->commcnt;
  ++v207->m_Items[5];
  v209 = (*s)->commlist;
  v210 = (*s)->commcnt;
  v211 = v209->m_Items[0];
  v212 = v210->m_Items[0];
  v211->m_Items[v212] = -32766;
  v214 = (*s)->commdisable;
  v215 = (*s)->commcnt;
  v216 = v214->m_Items[0];
  v217 = v215->m_Items[0];
  v216->m_Items[v217] = 0;
  v219 = (*s)->commcnt;
  ++v219->m_Items[0];
  if ((v10->flag & 4) != 0)
  {
    for (i = 0; i != 160; ++i)
    {
      item = DDS3_GBWK->item;
      if (item->m_Items[i])
      {
        v222 = tbl;
        max_length_low = LODWORD(v222->max_length);
        if (i < max_length_low)
        {
          else if (i >= max_length_low)
          {
LABEL_264:
          }
          if ((v222->m_Items[i]->use & 2) != 0)
          {
            v229 = (*s)->commlist;
            v231 = (*s)->commcnt;
            v232 = v229->m_Items[2];
            v234 = v231->m_Items[2];
            v232->m_Items[v234] = i;
            v236 = (*s)->commdisable;
            v238 = (*s)->commcnt;
            v239 = v236->m_Items[2];
            v241 = v238->m_Items[2];
            v239->m_Items[v241] = 0;
            v244 = tbl;
            if ((v244->m_Items[i]->flag & 1) != 0)
            {
              v246 = *s;
              if (((*s)->data->stat & 1) != 0)
              {
                v247 = v246->commdisable;
                v249 = v246->commcnt;
                v250 = v247->m_Items[2];
                v252 = v249->m_Items[2];
                v250->m_Items[v252] = 1;
              }
            }
            v255 = tbl;
            if ((v255->m_Items[i]->flag & 8) != 0)
            {
              v257 = *s;
              if (((*s)->data->stat & 4) != 0)
              {
                v258 = v257->commdisable;
                v260 = v257->commcnt;
                v261 = v258->m_Items[2];
                v263 = v260->m_Items[2];
                v261->m_Items[v263] = 2;
              }
            }
            if (i == 56 && !nbGetEscapeSwitch((*s)->data, 0))
            {
              v265 = (*s)->commdisable;
              v267 = (*s)->commcnt;
              v268 = v265->m_Items[2];
              v270 = v267->m_Items[2];
              v268->m_Items[v270] = 1;
            }
            v272 = (*s)->commcnt;
            ++v272->m_Items[2];
          }
        }
      }
    }
    v274 = 0;
      goto LABEL_324;
LABEL_322:
LABEL_324:
    while (1)
    {
      if (v274 >= DDS3_GBWK->stockcnt)
        break;
      else
      {
        stocklist = DDS3_GBWK->stocklist;
        if (v274 >= LODWORD(stocklist->max_length))
          goto LABEL_328;
      }
      unitwork = DDS3_GBWK->unitwork;
      v280 = stocklist->m_Items[v274];
      if ((unitwork->m_Items[v280]->flag & 1) != 0)
      {
        v283 = DDS3_GBWK->unitwork;
        if ((v283->m_Items[v280]->flag & 4) == 0)
        {
          v286 = DDS3_GBWK->unitwork;
          if ((v286->m_Items[v280]->flag & 2) == 0)
          {
            v288 = (*s)->commlist;
            v290 = (*s)->commcnt;
            v291 = v288->m_Items[3];
            v293 = v290->m_Items[3];
            v291->m_Items[v293] = v280;
            v295 = (*s)->commdisable;
            v297 = (*s)->commcnt;
            v298 = v295->m_Items[3];
            v300 = v297->m_Items[3];
            v298->m_Items[v300] = 0;
            v303 = DDS3_GBWK->unitwork;
            if (!v303->m_Items[v280]->hp)
              goto LABEL_368;
            v306 = DDS3_GBWK->unitwork;
            if (v306->m_Items[v280]->badstatus == 2048)
            {
LABEL_368:
              v308 = (*s)->commdisable;
              v310 = (*s)->commcnt;
              v311 = v308->m_Items[3];
              v313 = v310->m_Items[3];
              v311->m_Items[v313] = 4;
            }
            v315 = (*s)->commcnt;
            ++v315->m_Items[3];
          }
        }
      }
      ++v274;
        goto LABEL_322;
    }
  }
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

LABEL_7:
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
    v5 = Find(transform, "bmenu", 0);
    gameObject = get_gameObject(v5);
    Component_object = GetComponent_object_(gameObject);
    SetInteger(Component_object, "bmenu", 0);
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
  s32 wait_se2;
  s32 v5;
  u64 *v8;
  Il2CppObject *v10;
  Il2CppObject *ProcessData;
  nbCommSelProcessData_t_c *v14;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  nbCommSelProcessData_t_o *v20;
  s32 nowstat;
  s32 v22;
  s64 nowtype;
  struct System_Int32_array *nowcursor;
  struct System_Int32_array *nowlisty;
  s64 v29;
  u32 animeflag;
  s32 ox;
  s32 oy;
  s32 alpha;
  nbCommSelProcessData_t_o *s;
  dds3ProcessID_t_o *ida;
  u64 v41[3];

  ida = id;
  s = 0;
  ++nbCommSelGameCnt;
  if (wait_se2)
  {
    else
    {
      v5 = wait_se2 - 1;
      wait_se2 = v5;
      if (v5)
        goto LABEL_21;
    }
    nbPlaySe(8);
    LODWORD(v41[0]) = nbCommSelGameCnt;
    v8 = sub_8D3950(s32, v41);
    v10 = Concat("001:nbCommSelGameCnt:", v8);
    Log(v10, 0);
  }
LABEL_21:
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_30;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbCommSelProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbCommSelProcessData_t, v41);
    if ((v41[0] & 1) != 0)
      v17 = v41[2];
    else
      v17 = v41 + 1;
    v18 = sub_8C4940(v17);
  }
LABEL_30:
  s = ProcessData;
  AnimeCommandList(&s, v14);
  v20 = s;
  nowstat = s->nowstat;
  switch (nowstat)
  {
    case 4:
      if ((s->animeflag & 2) == 0)
      {
        ida->func_ans = -1;
        return 0;
      }
      break;
    case 2:
      if ((s->act->stat & 0x80) != 0)
      {
        SelectCommandListAuto(&s);
        v20 = s;
        if (s->nowstat != 3)
          break;
      }
      else
      {
        bComOn();
        SelectCommandList(&s);
        v20 = s;
        if (s->nowstat != 3)
          break;
      }
      if ((v20->act->stat & 0x80) == 0)
      {
        v20->nowstat = 2;
        v22 = 1;
        if ((v20->animeflag & 0x10) == 0)
          goto LABEL_55;
        goto LABEL_60;
      }
      break;
    case 1:
      v22 = 0;
      s->nowstat = 2;
      if ((v20->animeflag & 0x10) != 0)
        goto LABEL_60;
LABEL_55:
      nowtype = v20->nowtype;
      nowcursor = v20->nowcursor;
      v20->drawtype = nowtype;
      v20->drawcursor = nowcursor->m_Items[nowtype];
      nowlisty = v20->nowlisty;
      v29 = v20->nowtype;
      v20->drawlisty = nowlisty->m_Items[v29];
      goto LABEL_60;
    default:
      break;
  }
  v22 = 0;
  if ((v20->animeflag & 0x10) == 0)
    goto LABEL_55;
LABEL_60:
  animeflag = v20->animeflag;
  if ((v20->act->stat & 0x80) == 0 || (animeflag & 0x10) != 0)
  {
    ox = v20->ox;
    oy = v20->oy;
    alpha = v20->alpha;
    v20->animeflag = animeflag & 0xFFFFFFDF;
    if ((animeflag & 2) == 0 && v20->nowstat == 2 && v20->drawtype != 3)
      v20->animeflag = animeflag | 0x20;
    bComOffExec();
    DispCommandPanel(&s, s->drawtype, ox, oy, alpha);
    DispCommandList2(&s, s->drawtype, ox, oy, alpha);
    if (v22)
      s->nowstat = 3;
  }
  return 0;
}

// 0x16e2f30
void *nbCommSelShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  char *v7;
  s64 *v8;
  dds3ProcessID_t_o *v9[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbCommSelProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbCommSelProcessData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  monitor = ProcessData[1].monitor;
  if (monitor[39] == ida)
    monitor[39] = 0;
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
  target = dds3StartProcess("nb_commsel", 0x2B0Eu, 1, 1, v8, 0, v9, 0, inited, 0);
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
