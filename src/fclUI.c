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
    UpdateDrawFlag(0);
    GetLocalizeText(0);
    RepColTag(0, 0);
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
  struct fclUI_StaticFields *static_fields;
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

  if (Animator___ContainsKey(objs, StringLiteral_16529))
  {
    Item = object___get_Item(objs, StringLiteral_16529);
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
      if ((*(v17 + 295) & 2) != 0 && !*(v17 + 216))
      ResetEffect(v17);
      UpdateMenuCursor(csr->CursorPos, -12.0, -56.0);
      SetMenuItem(csr, mid, 1);
    }
    if ((*(v17 + 295) & 2) != 0 && !*(v17 + 216))
    UpdateDrawFlag(StringLiteral_16529);
    v20 = get_gameObject(transform);
    v21 = Find(transform, StringLiteral_16530, 0);
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
      static_fields = fclUI->static_fields;
      static_fields->csrmove_sw = 0;
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
            while (1)
            {
              v39 = pFlag + v36++;
              ListNums += ((v39[32] >> 1) & 1) == 0;
              if (v36 >= CursorPos->ListNums)
                break;
              pFlag = CursorPos->pFlag;
              if (v36 >= LODWORD(pFlag->max_length))
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
            while (1)
            {
              LODWORD(v48) = v48 + (((v47->m_Items[v49] >> 1) & 1) == 0);
              if (v50 == v49)
                break;
              v47 = v46->pFlag;
              if (++v49 >= LODWORD(v47->max_length))
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
      static_fields = v33->static_fields;
    }
    Component_object = GetComponent_object_(v22);
    if (op_Inequality(Component_object, 0, 0))
    {
      EffFlag = csr->CursorPos->EffFlag;
      if (EffFlag == 255)
      {
        SetTrigger(Component_object, StringLiteral_16531);
        EffFlag = csr->CursorPos->EffFlag;
      }
      if (EffFlag == 254)
        SetTrigger(Component_object, StringLiteral_16532);
    }
    v45 = csr->CursorPos->EffFlag;
    csrmove_sw = v45;
  }
}

// 0xf82750
void DrawHelp(char *path, s32 itemid) {
    frwGetHelpForUnity(0, 0, 0, 0, 0, 0);
    fclChkItemHearts(0);
    SetInstitutionColor(0, 0, 0);
    UpdateDrawFlag(0);
}

// 0xf82d40
void DrawHelp2(char *path, s32 itemid) {
    frwGetHelpForUnity(0, 0, 0, 0, 0, 0);
    fclChkItemHearts(0);
    Set(0, 0);
    UpdateDrawFlag(0);
}

// 0xf841c0
void DrawModePanelText(void *obj, char **list, s32 csr, bool sw) {
    GetLocalizeText(0);
    RepColTag(0, 0);
}

// 0xf824d0
void DrawPayMoney(char *name, CounterCtr *ctr, u32 col, s32 val) {
    UpdateDrawFlag(0);
    Set(0, 0);
}

// 0xf7a1f0
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp) {
  fclUI_c *v7;
  s16 v8;
  s32 v9;
  struct fclUI_StaticFields *static_fields;
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
  p_static_fields = &v7->static_fields;
  static_fields = v7->static_fields;
  ScrollVal = static_fields->ScrollVal;
  Index = cp->Index;
  if (ScrollVal == Index)
  {
    static_fields->ScrollDir = 0;
    if (get_activeSelf(obj))
    SetActive(obj, 1, 0);
  }
  static_fields->ScrollDir = Index - ScrollVal;
  (*p_static_fields)->ScrollVal = cp->Index;
  if (!get_activeSelf(obj))
  v14 = cp->ShiftMax < cp->ListNums && cp->ShiftMax + cp->Index != cp->ListNums;
  transform = get_transform(obj, 0);
  v16 = Concat_5224608(name, StringLiteral_16524);
  v17 = Find(transform, v16, 0);
  gameObject = get_gameObject(v17);
  Component_object = GetComponent_object_(gameObject);
  SetInteger(Component_object, StringLiteral_16525, v14);
  v20 = cp->Index != 0;
  v21 = get_transform(obj, 0);
  v22 = Concat_5224608(name, StringLiteral_16526);
  v23 = Find(v21, v22, 0);
  v24 = get_gameObject(v23);
  v25 = GetComponent_object_(v24);
  SetInteger(v25, StringLiteral_16525, v20);
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
  while (1)
  {
    v6 = pFlag + v3++;
    v4 += ((v6[32] >> 1) & 1) == 0;
    if (v3 >= csr->ListNums)
      return v4;
    pFlag = csr->pFlag;
    if (v3 >= LODWORD(pFlag->max_length))
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
      while (1)
      {
        LODWORD(v2) = v2 + (((pFlag->m_Items[v4] >> 1) & 1) == 0);
        if (v5 == v4)
          break;
        pFlag = csr->pFlag;
        if (++v4 >= LODWORD(pFlag->max_length))
      }
    }
  }
  return v2;
}

// 0xf7cfa0
void InitializeUI(s32 eventno) {
    LoadPrefab_16624656(0, 0, 0, 0);
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
      while (1)
      {
        pos = pos + ((pFlag->m_Items[v5] >> 1) & 1) - 1;
        if (pos < 0)
          return v5;
        if (++v5 >= csr->ListNums)
          return 0;
        pFlag = csr->pFlag;
        if (v5 >= LODWORD(pFlag->max_length))
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
  fclUI_c *v2;
  f32 *static_fields;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;

  static_fields = v2->static_fields;
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
            v6 = &StringLiteral_16506;
          case 12:
            v6 = &StringLiteral_16507;
          case 13:
            v6 = &StringLiteral_16508;
          case 14:
            v6 = &StringLiteral_16509;
          case 15:
            v6 = &StringLiteral_16510;
          case 16:
            v6 = &StringLiteral_16511;
          case 17:
            v6 = &StringLiteral_16512;
          case 18:
            v6 = &StringLiteral_16513;
          default:
        }
      }
      v7 = 0;
      switch (mode)
      {
        case 0:
          v6 = &StringLiteral_16498;
        case 2:
          v6 = &StringLiteral_16504;
        case 3:
          v6 = &StringLiteral_16505;
        case 5:
          v6 = &StringLiteral_16499;
        case 6:
          v6 = &StringLiteral_16501;
        case 7:
        case 11:
        case 12:
          v6 = &StringLiteral_16502;
        case 8:
          v6 = &StringLiteral_16503;
        case 9:
          v6 = &StringLiteral_16500;
        default:
      }
    case 0x321:
      if (mode == 5)
      {
        v6 = &StringLiteral_16515;
      }
      else
      {
        if (mode)
        v6 = &StringLiteral_16514;
      }
    case 0x322:
      if (mode == 8)
      {
        v6 = &StringLiteral_16517;
      }
      else
      {
        if (mode)
        v6 = &StringLiteral_16516;
      }
    case 0x323:
      if (mode == 8)
      {
        v6 = &StringLiteral_16519;
      }
      else if (mode == 7)
      {
        v6 = &StringLiteral_16520;
      }
      else
      {
        if (mode)
        v6 = &StringLiteral_16518;
      }
    case 0x324:
      if (mode == 5)
      {
        v6 = &StringLiteral_16523;
      }
      else if (mode == 1)
      {
        v6 = &StringLiteral_16522;
      }
      else
      {
        if (mode)
        {
          v7 = 0;
        }
        v6 = &StringLiteral_16521;
      }
      v7 = *v6;
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
  }
}

// 0xf834c0
void SetMenuItem(cmpCursorInfo_t *csr, s32 mid, bool sw) {
    GetLocalizeText(0);
    RepColTag(0, 0);
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

  Item = object___get_Item(objs, StringLiteral_16529);
  transform = get_transform(Item, 0);
  parent = get_parent(transform);
  gameObject = get_gameObject(parent);
  if (!get_activeSelf(gameObject))
  {
    v12 = get_parent(transform);
    v13 = get_gameObject(v12);
    SetActive(v13, 1, 0);
  }
  v14 = Find(transform, StringLiteral_16533, 0);
  v15 = get_transform(v14, 0);
  get_childCount(v15);
  Child = GetChild(v15, csr);
  v17 = get_gameObject(Child);
  v18 = get_transform(v17, 0);
  v19 = Find(v18, StringLiteral_16534, 0);
  Component_GUILayer = GetComponent_GUILayer_(v19);
  text = get_text(Component_GUILayer);
  if (op_Inequality(Component_GUILayer, 0, 0))
  {
    v23 = get_transform(Component_GUILayer, 0);
    v24 = GetComponent_GUILayer_(v23);
    if (sw)
    {
      v25 = v24;
      v26 = Replace_5267216(text, StringLiteral_16535, StringLiteral_16536);
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
      v29 = Replace_5267216(text, StringLiteral_16536, StringLiteral_16535);
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
    v9 = Find(transform, StringLiteral_16261, 0);
    v11 = get_gameObject(v9);
    if (op_Inequality(v11, 0, 0) && get_activeSelf(v11))
      SetActive(v11, 0, 0);
    v14 = get_gameObject(_statusUIScr);
    v15 = get_transform(v14, 0);
    v16 = Find(v15, StringLiteral_12359, 0);
    v17 = get_gameObject(v16);
    v18 = get_transform(v17, 0);
    v19 = Find(v18, StringLiteral_16236, 0);
    v20 = get_gameObject(v19);
    SetActive(v20, 0, 0);
    v21 = get_transform(v17, 0);
    v22 = Find(v21, StringLiteral_16223, 0);
    v23 = get_gameObject(v22);
    SetActive(v23, 0, 0);
    v24 = get_gameObject(statusUIScr);
    v25 = get_transform(v24, 0);
    v26 = Find(v25, StringLiteral_16541, 0);
    v28 = get_gameObject(v26);
    if (op_Inequality(v28, 0, 0) && get_activeSelf(v28))
      SetActive(v28, 0, 0);
    SetInteger(statusUIScr->infoAnim, StringLiteral_12357, 0);
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

  Item = object___get_Item(objs, StringLiteral_16529);
  transform = get_transform(Item, 0);
  parent = get_parent(transform);
  gameObject = get_gameObject(parent);
  if (!get_activeSelf(gameObject))
  {
    v12 = get_parent(transform);
    v13 = get_gameObject(v12);
    SetActive(v13, 1, 0);
  }
  v14 = Find(transform, StringLiteral_16530, 0);
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
      while (1)
      {
        LODWORD(v17) = v17 + (((pFlag->m_Items[v19] >> 1) & 1) == 0);
        if (v20 == v19)
          break;
        pFlag = csr->pFlag;
        if (++v19 >= LODWORD(pFlag->max_length))
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
