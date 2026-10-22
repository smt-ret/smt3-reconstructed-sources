#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct CounterCtr CounterCtr;
typedef struct TMPEffect TMPEffect;
typedef struct cmpCmdSelInfo_t cmpCmdSelInfo_t;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct sdf3DFogParam_t sdf3DFogParam_t;

static void *fclObj;
static s32 ScrollVal;
static s32 ScrollDir;
static void *fclTfm;
static void *objs;
static s32 csrmove_sw;
static void *menu_msg;
static s32 menu_id;
static u32 draw_flag;
static s32 fcl_type;
static TMPEffect *Effect;
static f32 fclFaceDivSoften;
static f32 fclFaceDivBias;
static sdfVector4_t fclLightCol;
static sdfVector4_t fclLightDir;
static sdfVector4_t fclAmbient;
static sdf3DFogParam_t *fclFogParam;

void ButtonGuideDispOut(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
char *GetLocalizeText(char *ID);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
char *RepColTag(char *txt, void **LegacyParamArray);
void ResetEffect(void);
void ResetTMPEffect(TMPEffect *this);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void Scroll(TMPEffect *this, void *obj, s32 top, s32 dir);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetInstitutionColor(CounterCtr *this, s32 val, s32 colidx);
void SetMenuItem(cmpCursorInfo_t *csr, s32 mid, bool sw);
void SetMenuItemText(s32 csr, bool sw, bool anim);
void StartEffect(TMPEffect *this, void *obj, s32 mode, s32 tp);
void StopEffect(TMPEffect *this, void *obj);
void UpdateDrawFlag(char *name);
void UpdateMenuCursor(cmpCursorPos_t *csr, f32 y, f32 ofsy);
void dds3SetAmbientColor(u32 frame, sdfVector4_t col);
void dds3SetFogColor(u32 frame, sdfVector4_t col);
void dds3SetFogPara(u32 frame, f32 max, f32 min, f32 near, f32 far);
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col);
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir);
s8 fclChkItemHearts(u16 ItemID);
char *frwGetHelpForUnity(s32 X, s32 Y, u32 Z, s8 HelpType, u16 HelpID, s8 DrawMode);

// 0xf844c0
bool CheckStatusUI(void) {
  UnityEngine_Object_o *statusUIScr;

  statusUIScr = _statusUIScr;
  return !op_Equality(statusUIScr, 0, 0);
}

// 0xf7c4a0
void ClearMenuText(void) {
  _Clear(menu_msg);
}

// 0xf82650
void DrawBackPanel(char *name) {
  Il2CppObject *Item;
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *gameObject;

  if (Animator___ContainsKey(objs, name))
  {
    UpdateDrawFlag(name);
    Item = object___get_Item(objs, name);
    transform = get_transform(Item, 0);
    gameObject = get_gameObject(transform);
    if (!get_activeSelf(gameObject))
      SetActive(gameObject, 1, 0);
  }
}

// 0xf79f70
void DrawCaption2(char *name, char *caption, void *txt) {
  Il2CppObject *Item;
  System_String_o *LocalizeText;
  System_String_o *text;
  System_String_o *v14;
  System_Object_array *v15;
  s64 *v16;
  s64 *v18;
  System_String_o *v21;
  s32 v22;

  if (Animator___ContainsKey(objs, name))
  {
    if (!op_Equality(txt, 0, 0))
    {
      UpdateDrawFlag(name);
      Item = object___get_Item(objs, name);
      if (!get_activeSelf(Item))
        SetActive(Item, 1, 0);
      LocalizeText = GetLocalizeText(caption);
      text = get_text(txt);
      if (!op_Equality(text, LocalizeText, 0))
      {
        set_text(txt, LocalizeText);
        if (Equals_5239888(name, "comtitle", 4))
        {
          v14 = get_text(txt);
          v22 = 18;
          v15 = NewSpecific(object, 1u);
          v16 = sub_8D3950(s32, &v22);
          v18 = v16;
          v15->m_Items[0] = v18;
          v21 = RepColTag(v14, v15);
          set_text(txt, v21);
        }
      }
    }
  }
}

// 0xf7a700
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style) {
  Il2CppObject *Item;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *parent;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *v15;
  UnityEngine_GameObject_o *v16;
  u64 v17;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Component_o *v21;
  UnityEngine_GameObject_o *v22;
  bool activeSelf;
  fclUI_c *v33;
  struct cmpCursorPos_t_o *CursorPos;
  struct System_Byte_array *pFlag;
  u64 v36;
  s32 ListNums;
  char *v39;
  Il2CppObject *Component_object;
  s32 EffFlag;
  s32 v45;
  struct cmpCursorPos_t_o *v46;
  struct System_Byte_array *v47;
  s64 v48;
  s64 v49;
  s64 v50;
  s32 v52;
  s32 v53;
  s32 v54;
  s32 v55;

  if (Animator___ContainsKey(objs, "institutionUI"))
  {
    Item = object___get_Item(objs, "institutionUI");
    transform = get_transform(Item, 0);
    parent = get_parent(transform);
    gameObject = get_gameObject(parent);
    if (!get_activeSelf(gameObject))
    {
      v15 = get_parent(transform);
      v16 = get_gameObject(v15);
      SetActive(v16, 1, 0);
    }
    if (*(*(v17 + 184) + 48LL) != mid)
    {
      ResetEffect(v17);
      UpdateMenuCursor(csr->CursorPos, -12.0, -56.0);
      SetMenuItem(csr, mid, 1);
    }
    if ((*(v17 + 295) & 2) != 0 && !*(v17 + 216))
    UpdateDrawFlag("institutionUI");
    v20 = get_gameObject(transform);
    v21 = Find(transform, "institution_menu/insmenu_cursur", 0);
    v22 = get_gameObject(v21);
    if (!get_activeSelf(v20))
    {
      SetMenuItem(csr, mid, 0);
      SetActive(v20, 1, 0);
    }
    activeSelf = get_activeSelf(v22);
    if ((style - 1) > 1)
    {
      if (!activeSelf)
      {
        SetActive(v22, 1, 0);
        SetMenuItem(csr, mid, 1);
      }
    }
    else if (activeSelf)
    {
      SetActive(v22, 0, 0);
      SetMenuItem(csr, mid, style == 1);
      csr->CursorPos->EffFlag = 0;
LABEL_98:
      csrmove_sw = 0;
      return;
    }
    if (!csr->CursorPos->EffFlag)
      return;
    if (csrmove_sw)
    {
      if ((v33->_2.bitflags2 & 2) == 0
      {
        CursorPos = csr->CursorPos;
        pFlag = CursorPos->pFlag;
        if (pFlag)
        {
          if (CursorPos->ListNums)
          {
            v36 = 0;
            ListNums = 0;
            if (!LODWORD(pFlag->max_length))
            {
LABEL_55:
            }
            while (1)
            {
              v39 = pFlag + v36++;
              ListNums += ((v39[32] >> 1) & 1) == 0;
              if (v36 >= CursorPos->ListNums)
                break;
              pFlag = CursorPos->pFlag;
              if (v36 >= LODWORD(pFlag->max_length))
                goto LABEL_55;
            }
          }
          else
          {
            ListNums = 0;
          }
        }
        else
        {
          ListNums = CursorPos->ListNums;
        }
        v46 = csr->CursorPos;
        v47 = v46->pFlag;
        v48 = v46->Shift + v46->Index;
        if (v47)
        {
          if (v48 < 1)
          {
            LODWORD(v48) = 0;
          }
          else
          {
            v49 = 0;
            v50 = v48 - 1;
            LODWORD(v48) = 0;
            if (!LODWORD(v47->max_length))
            {
LABEL_77:
            }
            while (1)
            {
              LODWORD(v48) = v48 + (((v47->m_Items[v49] >> 1) & 1) == 0);
              if (v50 == v49)
                break;
              v47 = v46->pFlag;
              if (++v49 >= LODWORD(v47->max_length))
                goto LABEL_77;
            }
            v46 = csr->CursorPos;
          }
        }
        if (v48 + 1 < ListNums)
          v52 = v48 + 1;
        else
          v52 = 0;
        if (v48 <= 0)
          v53 = ListNums;
        else
          v53 = v48;
        v54 = v53 - 1;
        if (v46->EffFlag == 254)
          v55 = v54;
        else
          v55 = v52;
        SetMenuItemText(v55, 0, 1);
        SetMenuItemText(v48, 1, 1);
        UpdateMenuCursor(csr->CursorPos, -12.0, -56.0);
      }
      goto LABEL_98;
    }
    Component_object = GetComponent_object_(v22);
    if (op_Inequality(Component_object, 0, 0))
    {
      EffFlag = csr->CursorPos->EffFlag;
      if (EffFlag == 255)
      {
        SetTrigger(Component_object, "up");
        EffFlag = csr->CursorPos->EffFlag;
      }
      if (EffFlag == 254)
        SetTrigger(Component_object, "down");
    }
    v45 = csr->CursorPos->EffFlag;
    csrmove_sw = v45;
  }
}

// 0xf82750
void DrawHelp(char *path, s32 itemid) {
  Il2CppObject *Item;
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v9;
  System_String_o *HelpForUnity;
  System_String_o *v11;
  u64 *v12;
  System_String_array *v14;
  il2cpp_array_size_t max_length;
  System_String_array *v16;
  u64 *v17;
  System_String_o *v18;
  UnityEngine_Component_o *v19;
  UnityEngine_GameObject_o *v20;
  Il2CppObject *Component_object;
  Il2CppObject *v23;
  s64 v24;
  u64 *v26;
  System_String_o *v27;
  UnityEngine_Component_o *v28;
  UnityEngine_GameObject_o *v29;
  Il2CppObject *v30;
  Il2CppObject *v32;
  u64 *v34;
  System_String_o *v35;
  UnityEngine_Component_o *v36;
  UnityEngine_GameObject_o *v37;
  Il2CppObject *v38;
  Il2CppObject *v40;
  struct System_Byte_array *v44;
  s32 v46;
  s8 v47;
  s8 v49;
  UnityEngine_Component_o *v50;
  UnityEngine_GUILayer_o *Component_GUILayer;
  s32 v53;
  UnityEngine_GameObject_o *v54;
  UnityEngine_GameObject_o *v56;
  System_String_o *v57;
  s32 v58;

  v57 = path;
  Item = object___get_Item(objs, path);
  transform = get_transform(Item, 0);
  gameObject = get_gameObject(transform);
  if (!get_activeSelf(gameObject))
  {
    v9 = get_gameObject(transform);
    SetActive(v9, 1, 0);
  }
  HelpForUnity = frwGetHelpForUnity(0, 0, 0, 1, itemid, 1);
  if (itemid)
    v11 = HelpForUnity;
  else
    v11 = "";
  v12 = NewSpecific(char, 1u);
  *(v12 + 16) = 10;
  v14 = Split(v11, v12);
  max_length = v14->max_length;
  v58 = 1;
  v16 = v14;
  v17 = sub_8D3950(s32, &v58);
  v18 = Format("Text{0:D2}TM", v17, 0);
  v19 = Find(transform, v18, 0);
  v20 = get_gameObject(v19);
  Component_object = GetComponent_object_(v20);
  set_text(Component_object, "");
  v23 = GetComponent_object_(v20);
  v24 = max_length << 32;
  if (op_Inequality(v23, 0, 0))
    set_enabled(v23, 0);
  if (v24 >= 1)
  {
    set_text(Component_object, v16->m_Items[0]);
  }
  v58 = 2;
  v26 = sub_8D3950(s32, &v58);
  v27 = Format("Text{0:D2}TM", v26, 0);
  v28 = Find(transform, v27, 0);
  v29 = get_gameObject(v28);
  v30 = GetComponent_object_(v29);
  set_text(v30, "");
  v32 = GetComponent_object_(v29);
  if (op_Inequality(v32, 0, 0))
    set_enabled(v32, 0);
  if (v24 >= 0x100000001LL)
  {
    set_text(v30, v16->m_Items[1]);
  }
  v58 = 3;
  v34 = sub_8D3950(s32, &v58);
  v35 = Format("Text{0:D2}TM", v34, 0);
  v36 = Find(transform, v35, 0);
  v37 = get_gameObject(v36);
  v38 = GetComponent_object_(v37);
  set_text(v38, "");
  v40 = GetComponent_object_(v37);
  if (op_Inequality(v40, 0, 0))
    set_enabled(v40, 0);
  if (v24 >= 0x200000001LL)
  {
    set_text(v38, v16->m_Items[2]);
  }
  v44 = DDS3_GBWK->item;
  v46 = v44->m_Items[itemid];
  v47 = fclChkItemHearts(itemid);
  if (v47)
  {
    v49 = v47;
    v46 = cmbChkGetHearts(v49) != 0;
  }
  v50 = Find(transform, "num_posses", 0);
  Component_GUILayer = GetComponent_GUILayer_(v50);
  SetInstitutionColor(Component_GUILayer, v46, 1);
  v53 = cmpChkDoNotBuyItemTokusyu(itemid);
  v54 = get_gameObject(Component_GUILayer);
  if ((((v53 == 0) ^ get_activeSelf(v54)) & 1) != 0)
  {
    v56 = get_gameObject(Component_GUILayer);
    SetActive(v56, v53 == 0, 0);
  }
  UpdateDrawFlag(v57);
}

// 0xf82d40
void DrawHelp2(char *path, s32 itemid) {
  Il2CppObject *Item;
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v9;
  System_String_o *HelpForUnity;
  System_String_o *v11;
  u64 *v12;
  System_String_array *v14;
  il2cpp_array_size_t max_length;
  System_String_array *v16;
  u64 *v17;
  System_String_o *v18;
  UnityEngine_Component_o *v19;
  UnityEngine_GameObject_o *v20;
  Il2CppObject *Component_object;
  Il2CppObject *v23;
  s64 v24;
  u64 *v26;
  System_String_o *v27;
  UnityEngine_Component_o *v28;
  UnityEngine_GameObject_o *v29;
  Il2CppObject *v30;
  Il2CppObject *v32;
  u64 *v34;
  System_String_o *v35;
  UnityEngine_Component_o *v36;
  UnityEngine_GameObject_o *v37;
  Il2CppObject *v38;
  Il2CppObject *v40;
  struct System_Byte_array *v44;
  s32 v46;
  s8 v47;
  s8 v49;
  UnityEngine_Component_o *v50;
  UnityEngine_GUILayer_o *Component_GUILayer;
  System_String_o *name;
  s32 v54;
  UnityEngine_Color_o white;

  name = path;
  Item = object___get_Item(objs, path);
  transform = get_transform(Item, 0);
  gameObject = get_gameObject(transform);
  if (!get_activeSelf(gameObject))
  {
    v9 = get_gameObject(transform);
    SetActive(v9, 1, 0);
  }
  HelpForUnity = frwGetHelpForUnity(0, 0, 0, 1, itemid, 1);
  if (itemid)
    v11 = HelpForUnity;
  else
    v11 = "";
  v12 = NewSpecific(char, 1u);
  *(v12 + 16) = 10;
  v14 = Split(v11, v12);
  max_length = v14->max_length;
  v54 = 1;
  v16 = v14;
  v17 = sub_8D3950(s32, &v54);
  v18 = Format("Text{0:D2}TM", v17, 0);
  v19 = Find(transform, v18, 0);
  v20 = get_gameObject(v19);
  Component_object = GetComponent_object_(v20);
  set_text(Component_object, "");
  v23 = GetComponent_object_(v20);
  v24 = max_length << 32;
  if (op_Inequality(v23, 0, 0))
    set_enabled(v23, 0);
  if (v24 >= 1)
  {
    set_text(Component_object, v16->m_Items[0]);
  }
  v54 = 2;
  v26 = sub_8D3950(s32, &v54);
  v27 = Format("Text{0:D2}TM", v26, 0);
  v28 = Find(transform, v27, 0);
  v29 = get_gameObject(v28);
  v30 = GetComponent_object_(v29);
  set_text(v30, "");
  v32 = GetComponent_object_(v29);
  if (op_Inequality(v32, 0, 0))
    set_enabled(v32, 0);
  if (v24 >= 0x100000001LL)
  {
    set_text(v30, v16->m_Items[1]);
  }
  v54 = 3;
  v34 = sub_8D3950(s32, &v54);
  v35 = Format("Text{0:D2}TM", v34, 0);
  v36 = Find(transform, v35, 0);
  v37 = get_gameObject(v36);
  v38 = GetComponent_object_(v37);
  set_text(v38, "");
  v40 = GetComponent_object_(v37);
  if (op_Inequality(v40, 0, 0))
    set_enabled(v40, 0);
  if (v24 >= 0x200000001LL)
  {
    set_text(v38, v16->m_Items[2]);
  }
  v44 = DDS3_GBWK->item;
  v46 = v44->m_Items[itemid];
  v47 = fclChkItemHearts(itemid);
  if (v47)
  {
    v49 = v47;
    v46 = cmbChkGetHearts(v49) != 0;
  }
  v50 = Find(transform, "num_possess", 0);
  Component_GUILayer = GetComponent_GUILayer_(v50);
  white = get_white();
  Set(Component_GUILayer, v46, white, 0, 0);
  UpdateDrawFlag(name);
}

// 0xf841c0
void DrawModePanelText(void *obj, char **list, s32 csr, bool sw) {
  _BOOL4 v9;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v11;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GUILayer_o *Component_GUILayer;
  System_String_o *v18;
  System_String_o *LocalizeText;
  System_Object_array *v20;
  s64 *v21;
  s64 *v23;
  System_String_o *v25;
  System_String_o *v26;
  f32 x;
  UnityEngine_Transform_o *v28;
  UnityEngine_Component_o *v29;
  UnityEngine_GameObject_o *v30;
  UnityEngine_Transform_o *v31;
  UnityEngine_Component_o *v32;
  UnityEngine_GUILayer_o *v33;
  UnityEngine_GUILayer_o *v34;
  UnityEngine_Transform_o *v35;
  UnityEngine_Component_o *v36;
  UnityEngine_GUILayer_o *v37;
  UnityEngine_GUILayer_o *v38;
  _BOOL4 v40;
  UnityEngine_Vector2_o v41;
  UnityEngine_Vector2_o v42;

  v9 = sw;
  transform = get_transform(obj, 0);
  v11 = Find(transform, "stretch_off", 0);
  gameObject = get_gameObject(v11);
  v13 = get_transform(gameObject, 0);
  v14 = Find(v13, "TextTM", 0);
  Component_GUILayer = GetComponent_GUILayer_(v14);
  v18 = list->m_Items[csr];
  LocalizeText = GetLocalizeText(v18);
  v40 = v9;
  v20 = NewSpecific(object, 1u);
  v21 = sub_8D3950(s32, &v40);
  v23 = v21;
  v20->m_Items[0] = v23;
  v25 = RepColTag(LocalizeText, v20);
  v26 = Concat_5224608(v25, "</material>");
  set_text(Component_GUILayer, v26);
  x = GetPreferredValues(Component_GUILayer).x;
  v28 = get_transform(obj, 0);
  v29 = Find(v28, "stretch_on", 0);
  v30 = get_gameObject(v29);
  v31 = get_transform(v30, 0);
  v32 = Find(v31, "TextTM", 0);
  v33 = GetComponent_GUILayer_(v32);
  set_text(v33, v26);
  v34 = GetComponent_GUILayer_(v33);
  v41.y = get_sizeDelta(v34).y;
  v41.x = x;
  set_sizeDelta(v34, v41);
  v35 = get_transform(v30, 0);
  v36 = Find(v35, "TextTM/Text_gTM", 0);
  v37 = GetComponent_GUILayer_(v36);
  set_text(v37, v26);
  v38 = GetComponent_GUILayer_(v37);
  v42.y = get_sizeDelta(v38).y;
  v42.x = x;
  set_sizeDelta(v38, v42);
}

// 0xf824d0
void DrawPayMoney(char *name, CounterCtr *ctr, u32 col, s32 val) {
  Il2CppObject *Item;
  UnityEngine_Color32_o c;
  UnityEngine_Color_o v14;

  c.rgba = 0;
  if (Animator___ContainsKey(objs, name))
  {
    UpdateDrawFlag(name);
    Item = object___get_Item(objs, name);
    if (!get_activeSelf(Item))
      SetActive(Item, 1, 0);
    if (!op_Equality(ctr, 0, 0))
    {
      sub_19ED4B0(&c, SBYTE2(col), SBYTE1(col), col, SHIBYTE(col));
      v14 = op_Implicit_27186704(c.rgba);
      Set(ctr, val, v14, 0, 0);
    }
  }
}

// 0xf7a1f0
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp) {
  s16 v8;
  s32 v9;
  struct fclUI_StaticFields **p_static_fields;
  s32 ScrollVal;
  s32 Index;
  s32 v14;
  UnityEngine_Transform_o *transform;
  System_String_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  s32 v20;
  UnityEngine_Transform_o *v21;
  System_String_o *v22;
  UnityEngine_Component_o *v23;
  UnityEngine_GameObject_o *v24;
  Il2CppObject *v25;

  if ((v8 & 0x200) != 0)
  {
    v9 = v8 & 0x200;
  }
  else
  {
    v9 = 0;
  }
  Index = cp->Index;
  if (ScrollVal == Index)
  {
    ScrollDir = 0;
    if (get_activeSelf(obj))
      goto LABEL_19;
LABEL_18:
    SetActive(obj, 1, 0);
    goto LABEL_19;
  }
  ScrollDir = Index - ScrollVal;
  (*p_static_fields)->ScrollVal = cp->Index;
  if (!get_activeSelf(obj))
    goto LABEL_18;
LABEL_19:
  v14 = cp->ShiftMax < cp->ListNums && cp->ShiftMax + cp->Index != cp->ListNums;
  transform = get_transform(obj, 0);
  v16 = Concat_5224608(name, "_yad");
  v17 = Find(transform, v16, 0);
  gameObject = get_gameObject(v17);
  Component_object = GetComponent_object_(gameObject);
  SetInteger(Component_object, "scrollya", v14);
  v20 = cp->Index != 0;
  v21 = get_transform(obj, 0);
  v22 = Concat_5224608(name, "_yau");
  v23 = Find(v21, v22, 0);
  v24 = get_gameObject(v23);
  v25 = GetComponent_object_(v24);
  SetInteger(v25, "scrollya", v20);
}

// 0xf82380
void DrawTotalMoney(char *name, CounterCtr *ctr) {
  Il2CppObject *Item;
  s32 maka;
  UnityEngine_Color_o white;

  if (Animator___ContainsKey(objs, name))
  {
    UpdateDrawFlag(name);
    Item = object___get_Item(objs, name);
    if (!get_activeSelf(Item))
      SetActive(Item, 1, 0);
    maka = DDS3_GBWK->maka;
    white = get_white();
    Set(ctr, maka, white, 0, 0);
  }
}

// 0xf7d910
void FinalizeUI(void) {
  UnityEngine_Object_o *Effect;
  UnityEngine_Object_o *v7;
  UnityEngine_Object_o *fclObj;
  UnityEngine_Object_o *gameObject;

  PropertySheet___Clear(objs);
  if (op_Inequality(Effect, 0, 0))
  {
    v7 = Effect;
    Destroy_27360000(v7);
  }
  Effect = 0;
  if (op_Inequality(fclObj, 0, 0))
  {
    gameObject = get_gameObject(fclObj);
    Destroy_27360000(gameObject);
  }
  fclObj = 0;
  fcl_type = 0;
  UnloadUnusedAssets();
}

// 0xf84870
void GetCurrentParam(void) {
  f32 sdfFaceDivSoften;
  struct sdf3DLight_t_array *dds3DirLights;
  struct sdf3DLight_t_array *v9;
  struct sdf3DLight_t_array *v11;
  struct sdf3DLight_t_array *v13;
  struct sdf3DLight_t_array *v15;
  struct sdf3DLight_t_array *v17;
  struct sdf3DLight_t_array *v19;
  struct sdf3DLight_t_array *v21;

  fclFaceDivSoften = sdfFaceDivSoften;
  fclFaceDivBias = sdfFaceDivBias;
  else
  {
    if (!LODWORD(dds3DirLights->max_length))
      goto LABEL_12;
  }
  fclLightCol.x = dds3DirLights->m_Items[0]->color.x;
  v9 = dds3DirLights;
  fclLightCol.y = v9->m_Items[0]->color.y;
  v11 = dds3DirLights;
  fclLightCol.z = v11->m_Items[0]->color.z;
  v13 = dds3DirLights;
  fclLightCol.w = v13->m_Items[0]->color.w;
  v15 = dds3DirLights;
  fclLightDir.x = v15->m_Items[0]->v.x;
  v17 = dds3DirLights;
  fclLightDir.y = v17->m_Items[0]->v.y;
  v19 = dds3DirLights;
  fclLightDir.z = v19->m_Items[0]->v.z;
  v21 = dds3DirLights;
  fclLightDir.w = v21->m_Items[0]->v.w;
  fclAmbient.x = dds3Ambient.x;
  fclAmbient.y = dds3Ambient.y;
  fclAmbient.z = dds3Ambient.z;
  fclAmbient.w = dds3Ambient.w;
  fclFogParam->fogMax = dds3FogParam->fogMax;
  fclFogParam->fogMin = dds3FogParam->fogMin;
  fclFogParam->fogNear = dds3FogParam->fogNear;
  fclFogParam->fogFar = dds3FogParam->fogFar;
  fclFogParam->color = dds3FogParam->color;
}

// 0xf790d0
void *GetGameObject(char *name) {
  if (!Animator___ContainsKey(objs, name))
    return 0;
  return object___get_Item(objs, name);
}

// 0xf83ad0
s32 GetMenuLength(cmpCursorPos_t *csr) {
  struct System_Byte_array *pFlag;
  u64 v3;
  s32 v4;
  char *v6;

  pFlag = csr->pFlag;
  if (!pFlag)
    return csr->ListNums;
  if (!csr->ListNums)
    return 0;
  v3 = 0;
  v4 = 0;
  if (!LODWORD(pFlag->max_length))
  {
LABEL_6:
  }
  while (1)
  {
    v6 = pFlag + v3++;
    v4 += ((v6[32] >> 1) & 1) == 0;
    if (v3 >= csr->ListNums)
      return v4;
    pFlag = csr->pFlag;
    if (v3 >= LODWORD(pFlag->max_length))
      goto LABEL_6;
  }
}

// 0xf82310
void *GetRootGameObject(void) {
  return fclObj;
}

// 0xf83b80
s32 Idx2Pos(cmpCursorPos_t *csr) {
  s64 v2;
  struct System_Byte_array *pFlag;
  s64 v4;
  s64 v5;

  v2 = csr->Shift + csr->Index;
  pFlag = csr->pFlag;
  if (pFlag)
  {
    if (v2 < 1)
    {
      LODWORD(v2) = 0;
    }
    else
    {
      v4 = 0;
      v5 = v2 - 1;
      LODWORD(v2) = 0;
      if (!LODWORD(pFlag->max_length))
      {
LABEL_6:
      }
      while (1)
      {
        LODWORD(v2) = v2 + (((pFlag->m_Items[v4] >> 1) & 1) == 0);
        if (v5 == v4)
          break;
        pFlag = csr->pFlag;
        if (++v4 >= LODWORD(pFlag->max_length))
          goto LABEL_6;
      }
    }
  }
  return v2;
}

// 0xf7cfa0
void InitializeUI(s32 eventno) {
  u64 *v3;
  System_String_o *v4;
  System_String_o *v6;
  System_String_o *v7;
  s64 *v8;
  System_String_o *v9;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v17;
  struct UnityEngine_Transform_o *v19;
  s32 childCount;
  s32 i;
  UnityEngine_Component_o *Child;
  UnityEngine_Object_o *gameObject;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *objs;
  UnityEngine_Rendering_PostProcessing_PropertySheet_o *v29;
  System_String_o *name;
  UnityEngine_GameObject_o *v32;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v36;
  s32 v38;

  v38 = eventno;
  v3 = sub_8D3950(s32, &v38);
  v4 = Format("e{0:D3}", v3, 0);
  v6 = "dds3data/UI";
  v7 = v4;
  switch (eventno)
  {
    case 800:
      v8 = &"combUI";
      goto LABEL_9;
    case 801:
      v8 = &"recovUI";
      goto LABEL_9;
    case 802:
      v8 = &"shopUI";
      goto LABEL_9;
    case 803:
      v8 = &"ragUI";
      goto LABEL_9;
    case 804:
      v8 = &"terminalUI";
LABEL_9:
      v9 = *v8;
      asset_bc = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, v7, v6, v9);
      if (!op_Equality(Prefab_16624656, 0, 0))
      {
        v13 = Find("Canvas_UI", 0);
        transform = get_transform(v13, 0);
        v17 = Instantiate_object__425520(Prefab_16624656, transform);
        fclObj = v17;
        set_name(fclObj, v9);
        AddComponent_object_(fclObj);
        v19 = get_transform(fclObj, 0);
        fclTfm = v19;
        PropertySheet___Clear(objs);
        childCount = get_childCount(fclTfm);
        SetActive(fclObj, 0, 0);
        if (childCount >= 1)
        {
          for (i = 0; i != childCount; ++i)
          {
            Child = GetChild(fclTfm, i);
            gameObject = get_gameObject(Child);
            v29 = gameObject;
            name = get_name(gameObject);
            PropertySheet___Add(objs, name, v29);
            SetActive(v29, 0, 0);
          }
        }
        _Clear(menu_msg);
        menu_id = -1;
        draw_flag = 0;
        fcl_type = eventno;
        v32 = Find("Canvas_UI", 0);
        Component_object = GetComponent_object_(v32);
        if (op_Equality(Component_object, 0, 0))
        {
          v36 = Find("Canvas_UI", 0);
          Component_object = AddComponent_object_(v36);
        }
        Effect = Component_object;
      }
      break;
    default:
      return;
  }
}

// 0xf83f20
s32 Pos2Idx(cmpCursorPos_t *csr, s32 pos) {
  struct System_Byte_array *pFlag;
  u64 v5;

  pFlag = csr->pFlag;
  if (pFlag)
  {
    if (csr->ListNums)
    {
      v5 = 0;
      if (!LODWORD(pFlag->max_length))
      {
LABEL_4:
      }
      while (1)
      {
        pos = pos + ((pFlag->m_Items[v5] >> 1) & 1) - 1;
        if (pos < 0)
          return v5;
        if (++v5 >= csr->ListNums)
          return 0;
        pFlag = csr->pFlag;
        if (v5 >= LODWORD(pFlag->max_length))
          goto LABEL_4;
      }
    }
    else
    {
      return 0;
    }
  }
  return pos;
}

// 0xf84be0
void RemakeFldSky(void) {
  f32 *static_fields;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;

  v4 = static_fields[20];
  v5 = static_fields[21];
  v7 = static_fields[22];
  v6 = static_fields[23];
  v8.x = v4;
  v8.y = v5;
  v8.z = v7;
  v8.w = v6;
  dds3SetLightColor(0, 0, v8);
  dds3SetLightDir(0, 0, fclLightDir);
  dds3SetAmbientColor(0, fclAmbient);
  v9 = SDF_VU0__Retdds3ColorItoF(fclFogParam->color, 255.0);
  dds3SetFogColor(0, v9);
  dds3SetFogPara(0, fclFogParam->fogMax, fclFogParam->fogMin, fclFogParam->fogNear, fclFogParam->fogFar);
}

// 0xf807b0
void ResetEffect(void) {
  UnityEngine_Object_o *Effect;

  if (!op_Equality(Effect, 0, 0))
  {
    ResetTMPEffect(Effect);
  }
}

// 0xf7a400
void ScrollEffect(void *obj) {
  UnityEngine_Object_o *Effect;

  if (!op_Equality(Effect, 0, 0))
  {
    Scroll(Effect, obj, ScrollVal, ScrollDir);
  }
}

// 0xf7d3b0
void SetButtonGuide(s32 mode, bool sw) {
  s64 *v6;
  System_String_o *v7;

  switch (fcl_type)
  {
    case 0x320:
      if (sw)
      {
        switch (mode)
        {
          case 11:
            v6 = &"CMB11";
            goto LABEL_33;
          case 12:
            v6 = &"CMB12";
            goto LABEL_33;
          case 13:
            v6 = &"CMB13";
            goto LABEL_33;
          case 14:
            v6 = &"CMB14";
            goto LABEL_33;
          case 15:
            v6 = &"CMB15";
            goto LABEL_33;
          case 16:
            v6 = &"CMB16";
            goto LABEL_33;
          case 17:
            v6 = &"CMB17";
            goto LABEL_33;
          case 18:
            v6 = &"CMB20";
            goto LABEL_33;
          default:
            goto LABEL_24;
        }
      }
      v7 = 0;
      switch (mode)
      {
        case 0:
          v6 = &"CMB01";
          goto LABEL_33;
        case 2:
          v6 = &"CMB10";
          goto LABEL_33;
        case 3:
          v6 = &"CMB19";
          goto LABEL_33;
        case 5:
          v6 = &"CMB02";
          goto LABEL_33;
        case 6:
          v6 = &"CMB04";
          goto LABEL_33;
        case 7:
        case 11:
        case 12:
          v6 = &"CMB05";
          goto LABEL_33;
        case 8:
          v6 = &"CMB07";
          goto LABEL_33;
        case 9:
          v6 = &"CMB03";
          goto LABEL_33;
        default:
          goto LABEL_34;
      }
      goto LABEL_34;
    case 0x321:
      if (mode == 5)
      {
        v6 = &"REC04";
      }
      else
      {
        if (mode)
          goto LABEL_24;
        v6 = &"REC01";
      }
      goto LABEL_33;
    case 0x322:
      if (mode == 8)
      {
        v6 = &"SHOP04";
      }
      else
      {
        if (mode)
          goto LABEL_24;
        v6 = &"SHOP01";
      }
      goto LABEL_33;
    case 0x323:
      if (mode == 8)
      {
        v6 = &"RAG03";
      }
      else if (mode == 7)
      {
        v6 = &"RAG05";
      }
      else
      {
        if (mode)
          goto LABEL_24;
        v6 = &"RAG01";
      }
      goto LABEL_33;
    case 0x324:
      if (mode == 5)
      {
        v6 = &"TML03";
      }
      else if (mode == 1)
      {
        v6 = &"TML02";
      }
      else
      {
        if (mode)
        {
LABEL_24:
          v7 = 0;
          goto LABEL_34;
        }
        v6 = &"TML01";
      }
LABEL_33:
      v7 = *v6;
LABEL_34:
      if (IsNullOrEmpty(v7))
      {
        ButtonGuideDispOut();
      }
      else
      {
        ButtonGuideDispSet(v7, 0, 0, 90);
      }
      return;
    default:
      goto LABEL_24;
  }
}

// 0xf834c0
void SetMenuItem(cmpCursorInfo_t *csr, s32 mid, bool sw) {
  Il2CppObject *v11;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *parent;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *v15;
  UnityEngine_GameObject_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_Transform_o *v18;
  s32 childCount;
  u64 *v20;
  System_WeakReference_c *klass;
  s32 i;
  UnityEngine_Transform_o *Child;
  System_WeakReference_o *v25;
  UnityEngine_GameObject_o *v26;
  cmpCursorInfo_t_o *v27;
  struct cmpCursorPos_t_o *CursorPos;
  s64 v29;
  struct System_Byte_array *pFlag;
  s64 v31;
  s64 v32;
  u64 v34;
  s32 v35;
  s32 v36;
  struct System_Byte_array *v38;
  System_WeakReference_o *v40;
  UnityEngine_GameObject_o *v41;
  System_WeakReference_o *v42;
  UnityEngine_Component_o *v43;
  UnityEngine_GUILayer_o *Component_GUILayer;
  System_String_o *v47;
  System_String_o *LocalizeText;
  s32 v50;
  System_Object_array *v51;
  System_Object_array *v52;
  s64 *v53;
  s64 *v55;
  System_String_o *v57;
  System_WeakReference_o *v58;
  struct System_Byte_array *v60;
  cmpCursorInfo_t_o *v61;
  s32 v63;
  System_WeakReference_o *Item;
  s32 v65;

  menu_id = mid;
  if (_get_Count(menu_msg) <= mid)
    return;
  if (!Animator___ContainsKey(objs, "institutionUI"))
    return;
  v61 = csr;
  Item = _get_Item(
           menu_msg,
           menu_id);
  v11 = object___get_Item(objs, "institutionUI");
  transform = get_transform(v11, 0);
  parent = get_parent(transform);
  gameObject = get_gameObject(parent);
  if (!get_activeSelf(gameObject))
  {
    v15 = get_parent(transform);
    v16 = get_gameObject(v15);
    SetActive(v16, 1, 0);
  }
  v17 = Find(transform, "institution_menu/insmenu_window", 0);
  v18 = get_transform(v17, 0);
  childCount = get_childCount(v18);
  v20 = Allocate(System_Collections_Generic_List_Transform_);
  __ctor(v20);
  klass = Item[1].klass;
  _Clear(v20);
  if (childCount >= 1)
  {
    for (i = 0; i != childCount; ++i)
    {
      Child = GetChild(v18, i);
      _Add(v20, Child);
      v25 = _get_Item(
              v20,
              i);
      v26 = get_gameObject(v25);
      SetActive(v26, i - childCount == -1, 0);
    }
  }
  v27 = v61;
  CursorPos = v61->CursorPos;
  v29 = CursorPos->Shift + CursorPos->Index;
  pFlag = CursorPos->pFlag;
  if (pFlag)
  {
    if (v29 < 1)
    {
      LODWORD(v29) = 0;
      if (klass >= 1)
        goto LABEL_30;
      return;
    }
    v31 = 0;
    v32 = v29 - 1;
    LODWORD(v29) = 0;
    if (!LODWORD(pFlag->max_length))
    {
LABEL_27:
    }
    while (1)
    {
      LODWORD(v29) = v29 + (((pFlag->m_Items[v31] >> 1) & 1) == 0);
      if (v32 == v31)
        break;
      pFlag = CursorPos->pFlag;
      if (++v31 >= LODWORD(pFlag->max_length))
        goto LABEL_27;
    }
  }
  if (klass >= 1)
  {
LABEL_30:
    v63 = childCount - 3;
    v34 = 0;
    v35 = 0;
    do
    {
      while (1)
      {
        v60 = v27->CursorPos->pFlag;
        if (v60)
          break;
        v36 = 0;
LABEL_36:
        v40 = _get_Item(
                v20,
                v35);
        v41 = get_gameObject(v40);
        SetActive(v41, 1, 0);
        v42 = _get_Item(
                v20,
                v35);
        v43 = Find(v42, "TextTM", 0);
        Component_GUILayer = GetComponent_GUILayer_(v43);
        v47 = *(&Item[1].monitor + v34);
        LocalizeText = GetLocalizeText(v47);
        if (op_Inequality(Component_GUILayer, 0, 0))
        {
          if (v36)
            v50 = 2;
          else
            v50 = v29 == v35 && sw;
          v51 = NewSpecific(object, 1u);
          v65 = v50;
          v52 = v51;
          v53 = sub_8D3950(s32, &v65);
          v55 = v53;
          v52->m_Items[0] = v55;
          v57 = RepColTag(LocalizeText, v52);
          set_text(Component_GUILayer, v57);
          v27 = v61;
        }
        v58 = _get_Item(
                v20,
                v35);
        GetComponent_GUILayer_(v58);
        if (klass - 1 == v34)
          v35 = v63;
        else
          ++v35;
        if (klass == ++v34)
          return;
      }
      if ((v60->m_Items[v34] & 2) == 0)
      {
        v38 = v27->CursorPos->pFlag;
        v36 = v38->m_Items[v34] & 1;
        goto LABEL_36;
      }
      ++v34;
    }
    while (klass != v34);
  }
}

// 0xf83c30
void SetMenuItemText(s32 csr, bool sw, bool anim) {
  Il2CppObject *Item;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *parent;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *v12;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_Transform_o *v15;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Component_o *v19;
  UnityEngine_GUILayer_o *Component_GUILayer;
  System_String_o *text;
  UnityEngine_Component_o *v23;
  UnityEngine_GUILayer_o *v24;
  UnityEngine_Behaviour_o *v25;
  System_String_o *v26;
  UnityEngine_GameObject_o *v28;
  System_String_o *v29;
  UnityEngine_GameObject_o *v32;
  UnityEngine_Color_o white;

  Item = object___get_Item(objs, "institutionUI");
  transform = get_transform(Item, 0);
  parent = get_parent(transform);
  gameObject = get_gameObject(parent);
  if (!get_activeSelf(gameObject))
  {
    v12 = get_parent(transform);
    v13 = get_gameObject(v12);
    SetActive(v13, 1, 0);
  }
  v14 = Find(transform, "institution_menu/insmenu_window", 0);
  v15 = get_transform(v14, 0);
  get_childCount(v15);
  Child = GetChild(v15, csr);
  v17 = get_gameObject(Child);
  v18 = get_transform(v17, 0);
  v19 = Find(v18, "TextTM", 0);
  Component_GUILayer = GetComponent_GUILayer_(v19);
  text = get_text(Component_GUILayer);
  if (op_Inequality(Component_GUILayer, 0, 0))
  {
    v23 = get_transform(Component_GUILayer, 0);
    v24 = GetComponent_GUILayer_(v23);
    if (sw)
    {
      v25 = v24;
      v26 = Replace_5267216(text, "<material=\"TMC00\">", "<material=\"TMC01\">");
      set_text(Component_GUILayer, v26);
      white = get_white();
      (Component_GUILayer->klass[1].vtable._0_Equals.method)(
        Component_GUILayer,
        Component_GUILayer->klass[1].vtable._1_Finalize.methodPtr,
        white.r,
        white.g,
        white.b,
        white.a);
      set_enabled(v25, 0);
      if (anim)
      {
        v28 = get_gameObject(Component_GUILayer);
        StopEffect(v28);
      }
    }
    else
    {
      v29 = Replace_5267216(text, "<material=\"TMC01\">", "<material=\"TMC00\">");
      set_text(Component_GUILayer, v29);
      if (anim)
      {
        v32 = get_gameObject(Component_GUILayer);
        StartEffect(v32, 1, 1);
      }
    }
  }
}

// 0xf7c520
void SetRootMenuText(cmpCmdSelInfo_t **csel, char **menu) {
  cmpCmdSelInfo_t_o *v5;

  v5 = *csel;
  cmpInitCmdSelInfo(v5, menu, menu->max_length);
  _Add(menu_msg, menu);
}

// 0xf840c0
void StartEffect(void *tmpobj, s32 mode, s32 type) {
  UnityEngine_Object_o *Effect;

  if (!op_Equality(Effect, 0, 0))
  {
    StartEffect(Effect, tmpobj, mode, type, 0);
  }
}

// 0xf84560
void StatusTitleOff(void) {
  struct statusUI_o *statusUIScr;
  UnityEngine_GameObject_o *titleObj;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v9;
  UnityEngine_GameObject_o *v11;
  UnityEngine_GameObject_o *v14;
  UnityEngine_Transform_o *v15;
  UnityEngine_Component_o *v16;
  UnityEngine_GameObject_o *v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Component_o *v19;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Transform_o *v21;
  UnityEngine_Component_o *v22;
  UnityEngine_GameObject_o *v23;
  UnityEngine_GameObject_o *v24;
  UnityEngine_Transform_o *v25;
  UnityEngine_Component_o *v26;
  UnityEngine_GameObject_o *v28;

  RibbonOld = -1;
  statusUIScr = _statusUIScr;
  if (!op_Equality(statusUIScr, 0, 0))
  {
    titleObj = statusUIScr->titleObj;
    if (op_Inequality(titleObj, 0, 0) && get_activeSelf(titleObj))
      SetActive(titleObj, 0, 0);
    gameObject = get_gameObject(statusUIScr);
    transform = get_transform(gameObject, 0);
    v9 = Find(transform, "title_window", 0);
    v11 = get_gameObject(v9);
    if (op_Inequality(v11, 0, 0) && get_activeSelf(v11))
      SetActive(v11, 0, 0);
    v14 = get_gameObject(_statusUIScr);
    v15 = get_transform(v14, 0);
    v16 = Find(v15, "comstatus_parts", 0);
    v17 = get_gameObject(v16);
    v18 = get_transform(v17, 0);
    v19 = Find(v18, "comveiw", 0);
    v20 = get_gameObject(v19);
    SetActive(v20, 0, 0);
    v21 = get_transform(v17, 0);
    v22 = Find(v21, "comnote", 0);
    v23 = get_gameObject(v22);
    SetActive(v23, 0, 0);
    v24 = get_gameObject(statusUIScr);
    v25 = get_transform(v24, 0);
    v26 = Find(v25, "slvup", 0);
    v28 = get_gameObject(v26);
    if (op_Inequality(v28, 0, 0) && get_activeSelf(v28))
      SetActive(v28, 0, 0);
    SetInteger(statusUIScr->infoAnim, "sinfo", 0);
  }
}

// 0xf83fd0
void StopEffect(void *tmpobj) {
  UnityEngine_Object_o *Effect;

  if (!op_Equality(Effect, 0, 0))
  {
    StopEffect(Effect, tmpobj, 0);
  }
}

// 0xf7b140
void Update(void) {
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  System_Object_array *v5;
  u64 v6;
  Il2CppObject **m_Items;
  s32 v8;
  s32 Count;

  Values = Type___get_Values(objs);
  v5 = ToArray_object_(Values);
  v6 = 0;
  m_Items = v5->m_Items;
  v8 = 1;
  {
LABEL_9:
  }
  while (1)
  {
    Count = HashSet_Text____get_Count(objs);
    if (v6 >= Count)
      break;
    else if ((draw_flag & v8) == 0)
    {
      goto LABEL_15;
    }
    ++v6;
    v8 *= 2;
      goto LABEL_9;
  }
  draw_flag = 0;
}

// 0xf794a0
void UpdateDrawFlag(char *name) {
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;
  System_Object_array *v5;
  il2cpp_array_size_t max_length;
  System_Object_array *v7;
  u64 v8;
  Il2CppObject **m_Items;

  Keys = string___get_Keys(objs);
  v5 = ToArray_object_(Keys);
  max_length = v5->max_length;
  if (max_length < 1)
  {
    LODWORD(v8) = 0;
  }
  else
  {
    v7 = v5;
    v8 = 0;
    m_Items = v5->m_Items;
    do
    {
      if (Equals_5234480(m_Items[v8], name))
        break;
      LODWORD(max_length) = v7->max_length;
      ++v8;
    }
    while (v8 < max_length);
  }
  if (v8 != get_Length(name))
  {
    draw_flag |= 1 << v8;
  }
}

// 0xf7a4f0
void UpdateItemCursor(void *csrobj, cmpCursorPos_t *csr, f32 y, f32 ofsy) {
  u32 v5;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v10;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v12;

  LOBYTE(v5) = csr->Shift;
  transform = get_transform(csrobj, 0);
  localPosition = get_localPosition(transform);
  v10 = get_transform(csrobj, 0);
  v12.x = localPosition.x;
  v12.y = (v5 * ofsy) + y;
  v12.z = localPosition.z;
  set_localPosition(v10, v12);
}

// 0xf832c0
void UpdateMenuCursor(cmpCursorPos_t *csr, f32 y, f32 ofsy) {
  Il2CppObject *Item;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *parent;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *v12;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GameObject_o *v16;
  s64 v17;
  struct System_Byte_array *pFlag;
  s64 v19;
  s64 v20;
  UnityEngine_Transform_o *v22;
  UnityEngine_Transform_o *v23;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v25;

  Item = object___get_Item(objs, "institutionUI");
  transform = get_transform(Item, 0);
  parent = get_parent(transform);
  gameObject = get_gameObject(parent);
  if (!get_activeSelf(gameObject))
  {
    v12 = get_parent(transform);
    v13 = get_gameObject(v12);
    SetActive(v13, 1, 0);
  }
  v14 = Find(transform, "institution_menu/insmenu_cursur", 0);
  v16 = get_gameObject(v14);
  v17 = csr->Shift + csr->Index;
  pFlag = csr->pFlag;
  if (pFlag)
  {
    if (v17 < 1)
    {
      LODWORD(v17) = 0;
    }
    else
    {
      v19 = 0;
      v20 = v17 - 1;
      LODWORD(v17) = 0;
      if (!LODWORD(pFlag->max_length))
      {
LABEL_16:
      }
      while (1)
      {
        LODWORD(v17) = v17 + (((pFlag->m_Items[v19] >> 1) & 1) == 0);
        if (v20 == v19)
          break;
        pFlag = csr->pFlag;
        if (++v19 >= LODWORD(pFlag->max_length))
          goto LABEL_16;
      }
    }
  }
  v22 = get_transform(v16, 0);
  localPosition = get_localPosition(v22);
  v23 = get_transform(v16, 0);
  v25.y = (v17 * ofsy) + y;
  v25.x = localPosition.x;
  v25.z = localPosition.z;
  set_localPosition(v23, v25);
}
