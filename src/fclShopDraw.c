#include "types.h"

typedef struct CounterCtr CounterCtr;
typedef struct RippleEffect RippleEffect;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclPanelPos_t fclPanelPos_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;

static char *gShopCaptionStr[2];
static void *ListObjs;
static void *TextObjs;
static void *CCtrObjs;
static void *AnimFee;
static s32 ChildCount;
static void *MatCols;
static s32 CsrMoveSw;

s32 CMP_Y(s32 b);
void DispItemList(void *obj, bool sw);
void DispItemUD(void *obj, s32 val, s32 mode);
void DrawBackPanel(char *name);
void DrawCaption2(char *name, char *caption, void *txt);
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style);
void DrawHelp(char *path, s32 itemid);
void DrawPayMoney(char *name, CounterCtr *ctr, u32 col, s32 val);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
void DrawTotalMoney(char *name, CounterCtr *ctr);
u8 Get(s32 id);
void *GetGameObject(char *name);
char *GetLocalizeText(char *ID);
char *RepColTag(char *txt, void **LegacyParamArray);
void ScrollEffect(void *obj);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetInstitutionColor(CounterCtr *this, s32 val, s32 colidx);
void Update(RippleEffect *this);
void UpdateDrawFlag(char *name);
void UpdateItemCursor(void *csrobj, cmpCursorPos_t *csr, f32 y, f32 ofsy);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkDbgProcess(void);
s8 fclChkItemHearts(u16 ItemID);
s8 fclChkSignal(s8 Idx);
void fclInitPanelPos(s32 X, s32 Y, u32 Z, u16 W, u16 H, s32 Work, fclPanelPos_t *pPanelPos);
void lstDrawListWindowCursor(lstListWindow_t *pListWindow, u32 OtNo);
void shopClearNumControl(void);
s32 shpCalcItemPrice(s32 Index, s8 Mode);
s8 shpChkChoiceMax(s32 Index, s8 Mode, s8 CalcMode);
void shpDrawBuyItem(s8 Place, lstListWindow_t *pListWindow, s8 mode);
void shpDrawItem(char *path, u32 col, u16 item, s32 price);
void shpDrawNumsControl(cmpCursorInfo_t *csr, s32 val, s8 mode);
void shpDrawPanelParts(s32 mode);
void shpDrawPayMoney(u32 Color, s32 Val);
void shpDrawSellItem(s8 Place, lstListWindow_t *pListWindow, s8 Mode);
void shpDrawSeqBuy(s8 Mode);
void shpDrawSeqConfirm(s8 Mode);
void shpDrawSeqRoot(s32 Mode);
void shpDrawSeqSelect(s8 Mode);
void shpDrawSeqSell(s8 Mode);

// 0x19a18f0
void DispInsfee(s32 sw) {
  UnityEngine_Object_o *AnimFee;

  if (op_Inequality(AnimFee, 0, 0))
  {
    SetInteger(AnimFee, "insfee", sw);
  }
}

// 0x19a1ab0
void DispItemList(void *obj, bool sw) {
  _BOOL4 v3;
  System_String_o *name;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v9;
  Il2CppObject *Item;
  System_Collections_Generic_Dictionary_object__object__o *v13;
  Il2CppObject *v14;
  Il2CppObject *v15;
  System_Collections_Generic_Dictionary_object__object__o *v18;
  Il2CppObject *v19;
  Il2CppObject *v20;

  v3 = sw;
  name = get_name(obj);
  v9 = Concat_5224608(name, "_shopitemtex_x");
  Item = object___get_Item(ListObjs, v9);
  if (((get_activeSelf(Item) ^ v3) & 1) != 0)
    SetActive(Item, v3, 0);
  v13 = ListObjs;
  v14 = Concat_5224608(name, "_shop_numud");
  v15 = object___get_Item(v13, v14);
  if (((get_activeSelf(v15) ^ v3) & 1) != 0)
    SetActive(v15, v3, 0);
  v18 = ListObjs;
  v19 = Concat_5224608(name, "_num_item");
  v20 = object___get_Item(v18, v19);
  if (((get_activeSelf(v20) ^ v3) & 1) != 0)
    SetActive(v20, v3, 0);
}

// 0x19a1c90
void DispItemUD(void *obj, s32 val, s32 mode) {
  System_String_o *name;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v10;
  Il2CppObject *Item;
  System_Collections_Generic_Dictionary_object__object__o *v14;
  Il2CppObject *v15;
  Il2CppObject *v16;
  System_Collections_Generic_Dictionary_object__object__o *v19;
  Il2CppObject *v20;
  Il2CppObject *v21;
  u32 v22;

  name = get_name(obj);
  v10 = Concat_5224608(name, "_shop_numud_c");
  Item = object___get_Item(ListObjs, v10);
  if (!get_activeSelf(Item))
    SetActive(Item, 1, 0);
  v14 = ListObjs;
  v15 = Concat_5224608(name, "_shop_numud_u");
  v16 = object___get_Item(v14, v15);
  if (((mode ^ get_activeSelf(v16)) & 1) != 0)
    SetActive(v16, mode & 1, 0);
  v19 = ListObjs;
  v20 = Concat_5224608(name, "_shop_numud_d");
  v21 = object___get_Item(v19, v20);
  v22 = mode & 2;
  if (get_activeSelf(v21) != v22 >> 1)
    SetActive(v21, v22 != 0, 0);
}

// 0x19a1870
void FinalizeGameObject(void) {
  PropertySheet___Clear(ListObjs);
}

// 0x19a0a80
void InitializeGameObject(void) {
  UnityEngine_GameObject_o *GameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v4;
  u64 *v5;
  s32 v8;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v10;
  s32 v11;
  System_WeakReference_o *Item;
  System_WeakReference_o *v13;
  s32 Count;
  u32 v17;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v18;
  System_String_o *v19;
  UnityEngine_Component_o *v20;
  UnityEngine_GameObject_o *v21;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v22;
  System_String_o *v23;
  UnityEngine_Component_o *v24;
  UnityEngine_GameObject_o *v25;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v26;
  System_String_o *v27;
  UnityEngine_Component_o *v28;
  UnityEngine_GameObject_o *v29;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v30;
  System_String_o *v31;
  UnityEngine_Component_o *v32;
  UnityEngine_GameObject_o *v33;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v34;
  System_String_o *v35;
  UnityEngine_Component_o *v36;
  UnityEngine_GameObject_o *v37;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *TextObjs;
  System_String_o *v39;
  System_Collections_Generic_Dictionary_object__object__o *v40;
  UnityEngine_Shader_o *v41;
  Il2CppObject *v42;
  Il2CppObject *v43;
  Il2CppObject *v44;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *CCtrObjs;
  System_String_o *v46;
  System_Collections_Generic_Dictionary_object__object__o *v47;
  UnityEngine_Shader_o *v48;
  Il2CppObject *v49;
  Il2CppObject *v50;
  Il2CppObject *v51;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v52;
  System_String_o *v53;
  System_Collections_Generic_Dictionary_object__object__o *v54;
  UnityEngine_Shader_o *v55;
  Il2CppObject *v56;
  Il2CppObject *v57;
  Il2CppObject *v58;
  System_WeakReference_o *v60;
  UnityEngine_Component_o *v61;
  System_WeakReference_o *v62;
  System_String_o *name;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *ListObjs;
  UnityEngine_GameObject_o *v67;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v68;
  System_String_o *v69;
  UnityEngine_Component_o *v70;
  UnityEngine_GameObject_o *v71;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v72;
  System_String_o *v73;
  UnityEngine_Component_o *v74;
  UnityEngine_GameObject_o *v75;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v76;
  System_String_o *v77;
  System_Collections_Generic_Dictionary_object__object__o *v78;
  UnityEngine_Shader_o *v79;
  Il2CppObject *v80;
  Il2CppObject *v81;
  UnityEngine_Transform_o *v82;
  UnityEngine_Component_o *v83;
  UnityEngine_GameObject_o *v84;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v85;
  System_String_o *v86;
  System_Collections_Generic_Dictionary_object__object__o *v87;
  UnityEngine_Shader_o *v88;
  Il2CppObject *v89;
  Il2CppObject *v90;
  UnityEngine_Transform_o *v91;
  UnityEngine_Component_o *v92;
  UnityEngine_GameObject_o *v93;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v94;
  System_String_o *v95;
  System_Collections_Generic_Dictionary_object__object__o *v96;
  UnityEngine_Shader_o *v97;
  Il2CppObject *v98;
  Il2CppObject *v99;
  UnityEngine_Transform_o *v100;
  UnityEngine_Component_o *v101;
  UnityEngine_GameObject_o *v102;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v103;
  System_String_o *v104;
  UnityEngine_Component_o *v105;
  UnityEngine_GameObject_o *v106;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v107;
  System_String_o *v108;
  UnityEngine_Component_o *v109;
  UnityEngine_GameObject_o *v110;
  System_Collections_Generic_Dictionary_object__object__o *v111;
  Il2CppObject *v112;
  Il2CppObject *v113;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v118;
  UnityEngine_Transform_o *v119;
  UnityEngine_Component_o *v120;
  UnityEngine_GameObject_o *v122;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v124;
  UnityEngine_Transform_o *v125;
  UnityEngine_Component_o *v126;
  UnityEngine_GameObject_o *v127;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v128;
  UnityEngine_Transform_o *v129;
  UnityEngine_Component_o *v130;
  UnityEngine_GameObject_o *v131;
  UnityEngine_GameObject_o *v132;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v133;
  UnityEngine_GameObject_o *v134;
  UnityEngine_Transform_o *v135;
  UnityEngine_Component_o *v136;
  UnityEngine_GameObject_o *v137;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v138;
  UnityEngine_Transform_o *v139;
  UnityEngine_Component_o *v140;
  UnityEngine_GameObject_o *v141;
  UnityEngine_GameObject_o *v142;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v143;
  UnityEngine_Transform_o *v144;
  UnityEngine_Component_o *v145;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_GameObject_o *v148;
  Il2CppObject *v151;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v153;
  UnityEngine_Transform_o *v154;
  UnityEngine_Component_o *v155;
  UnityEngine_GUILayer_o *v156;
  UnityEngine_GameObject_o *v158;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v160;
  UnityEngine_Transform_o *v161;
  UnityEngine_Component_o *v162;
  UnityEngine_GUILayer_o *v163;
  u64 *v164;

  GameObject = GetGameObject("shoplist");
  transform = get_transform(GameObject, 0);
  v4 = Find(transform, "shop_row", 0);
  v5 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v5);
  PropertySheet___Clear(ListObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(CCtrObjs);
  if (get_childCount(v4) >= 1)
  {
    v8 = 0;
    do
    {
      Child = GetChild(v4, v8);
      v10 = get_gameObject(Child);
      _Add(v5, v10);
      ++v8;
    }
    while (v8 < get_childCount(v4));
  }
  if (_get_Count(v5) >= 1)
  {
    v11 = 0;
    do
    {
      Item = _get_Item(
               v5,
               v11);
      if (get_activeSelf(Item))
      {
        v13 = _get_Item(
                v5,
                v11);
        SetActive(v13, 0, 0);
      }
      ++v11;
    }
    while (v11 < _get_Count(v5));
  }
  Count = _get_Count(v5);
  v17 = 0;
  v164 = v5;
  ChildCount = Count;
  while (1)
  {
    if (v17 >= LISTMAX)
      break;
    v60 = _get_Item(
            v5,
            v17);
    v61 = get_transform(v60, 0);
    v62 = _get_Item(
            v5,
            v17);
    name = get_name(v62);
    v67 = get_gameObject(v61);
    PropertySheet___Add(ListObjs, name, v67);
    v68 = ListObjs;
    v69 = Concat_5224608(name, "_shopitemtex_x");
    v70 = Find(v61, "shopitemtex_x", 0);
    v71 = get_gameObject(v70);
    PropertySheet___Add(v68, v69, v71);
    v72 = ListObjs;
    v73 = Concat_5224608(name, "_shop_numud");
    v74 = Find(v61, "shop_numud", 0);
    v75 = get_gameObject(v74);
    PropertySheet___Add(v72, v73, v75);
    v76 = ListObjs;
    v77 = Concat_5224608(name, "_shop_numud_c");
    v78 = ListObjs;
    v79 = v77;
    v80 = Concat_5224608(name, "_shop_numud");
    v81 = object___get_Item(v78, v80);
    v82 = get_transform(v81, 0);
    v83 = Find(v82, "shop_numud_c", 0);
    v84 = get_gameObject(v83);
    PropertySheet___Add(v76, v79, v84);
    v85 = ListObjs;
    v86 = Concat_5224608(name, "_shop_numud_u");
    v87 = ListObjs;
    v88 = v86;
    v89 = Concat_5224608(name, "_shop_numud");
    v90 = object___get_Item(v87, v89);
    v91 = get_transform(v90, 0);
    v92 = Find(v91, "shop_numud_u", 0);
    v93 = get_gameObject(v92);
    PropertySheet___Add(v85, v88, v93);
    v94 = ListObjs;
    v95 = Concat_5224608(name, "_shop_numud_d");
    v96 = ListObjs;
    v97 = v95;
    v98 = Concat_5224608(name, "_shop_numud");
    v99 = object___get_Item(v96, v98);
    v100 = get_transform(v99, 0);
    v101 = Find(v100, "shop_numud_d", 0);
    v102 = get_gameObject(v101);
    PropertySheet___Add(v94, v97, v102);
    v103 = ListObjs;
    v104 = Concat_5224608(name, "_num_item");
    v105 = Find(v61, "num_item", 0);
    v106 = get_gameObject(v105);
    PropertySheet___Add(v103, v104, v106);
    v107 = ListObjs;
    v108 = Concat_5224608(name, "_name");
    v109 = Find(v61, "Text_nameTM", 0);
    v110 = get_gameObject(v109);
    PropertySheet___Add(v107, v108, v110);
    v111 = ListObjs;
    v112 = Concat_5224608(name, "_name");
    v113 = object___get_Item(v111, v112);
    Component_object = GetComponent_object_(v113);
    if (op_Inequality(Component_object, 0, 0))
      set_enabled(Component_object, 0);
    v5 = v164;
    v18 = ListObjs;
    v19 = Concat_5224608(name, "_money");
    v20 = Find(v61, "moneynum", 0);
    v21 = get_gameObject(v20);
    PropertySheet___Add(v18, v19, v21);
    v22 = ListObjs;
    v23 = Concat_5224608(name, "_makka_off");
    v24 = Find(v61, "shoptex_makka/shoptex_makka00", 0);
    v25 = get_gameObject(v24);
    PropertySheet___Add(v22, v23, v25);
    v26 = ListObjs;
    v27 = Concat_5224608(name, "_makka_on");
    v28 = Find(v61, "shoptex_makka/shoptex_makka01", 0);
    v29 = get_gameObject(v28);
    PropertySheet___Add(v26, v27, v29);
    v30 = ListObjs;
    v31 = Concat_5224608(name, "_x");
    v32 = Find(v61, "shopitemtex_x", 0);
    v33 = get_gameObject(v32);
    PropertySheet___Add(v30, v31, v33);
    v34 = ListObjs;
    v35 = Concat_5224608(name, "_num");
    v36 = Find(v61, "num_item", 0);
    v37 = get_gameObject(v36);
    PropertySheet___Add(v34, v35, v37);
    v39 = Concat_5224608(name, "_name");
    v40 = ListObjs;
    v41 = v39;
    v42 = Concat_5224608(name, "_name");
    v43 = object___get_Item(v40, v42);
    v44 = GetComponent_object_(v43);
    PropertySheet___Add(TextObjs, v41, v44);
    v46 = Concat_5224608(name, "_num");
    v47 = ListObjs;
    v48 = v46;
    v49 = Concat_5224608(name, "_num");
    v50 = object___get_Item(v47, v49);
    v51 = GetComponent_object_(v50);
    PropertySheet___Add(CCtrObjs, v48, v51);
    v52 = CCtrObjs;
    v53 = Concat_5224608(name, "_money");
    v54 = ListObjs;
    v55 = v53;
    v56 = Concat_5224608(name, "_money");
    v57 = object___get_Item(v54, v56);
    v58 = GetComponent_object_(v57);
    PropertySheet___Add(v52, v55, v58);
    ++v17;
  }
  v118 = GetGameObject("shoplist");
  v119 = get_transform(v118, 0);
  v120 = Find(v119, "shopindex_base", 0);
  v122 = get_gameObject(v120);
  v124 = ListObjs;
  v125 = get_transform(v122, 0);
  v126 = Find(v125, "shopindextex_buy", 0);
  v127 = get_gameObject(v126);
  PropertySheet___Add(v124, "shopindex_buy", v127);
  v128 = ListObjs;
  v129 = get_transform(v122, 0);
  v130 = Find(v129, "shopindextex_sell", 0);
  v131 = get_gameObject(v130);
  PropertySheet___Add(v128, "shopindex_sell", v131);
  v132 = GetGameObject("shoplist");
  v133 = ListObjs;
  v134 = v132;
  v135 = get_transform(v132, 0);
  v136 = Find(v135, "shopscroll", 0);
  v137 = get_gameObject(v136);
  PropertySheet___Add(v133, "shoplist_scroll", v137);
  v138 = ListObjs;
  v139 = get_transform(v134, 0);
  v140 = Find(v139, "menu_cursur", 0);
  v141 = get_gameObject(v140);
  PropertySheet___Add(v138, "shoplist_cursor", v141);
  v142 = GetGameObject("shopmoney");
  v143 = CCtrObjs;
  v144 = get_transform(v142, 0);
  v145 = Find(v144, "num_money", 0);
  Component_GUILayer = GetComponent_GUILayer_(v145);
  PropertySheet___Add(v143, "num_money", Component_GUILayer);
  v148 = GetGameObject("shopfee");
  if (op_Inequality(v148, 0, 0))
  {
    v151 = GetComponent_object_(v148);
    AnimFee = v151;
    v153 = CCtrObjs;
    v154 = get_transform(v148, 0);
    v155 = Find(v154, "insfee/num_money", 0);
    v156 = GetComponent_GUILayer_(v155);
    PropertySheet___Add(v153, "shopfee", v156);
  }
  v158 = GetGameObject("shoptitle");
  v160 = TextObjs;
  v161 = get_transform(v158, 0);
  v162 = Find(v161, "Text_shoptitleTM", 0);
  v163 = GetComponent_GUILayer_(v162);
  PropertySheet___Add(v160, "shoptitle", v163);
}

// 0x19a30a0
void SetCursorEffect(cmpCursorInfo_t *ci, void *list, char *bas, s32 len, s32 **matcol) {
  struct cmpCursorPos_t_o *CursorPos;
  s32 Shift;

  CursorPos = ci->CursorPos;
  if (CursorPos->EffFlag)
  {
    Shift = CursorPos->Shift;
    CsrMoveSw = Shift;
  }
}

// 0x19a1e70
void shopClearNumControl(void) {
  s32 v2;
  u32 v4;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  u64 *v6;
  Il2CppObject *v7;
  Il2CppObject *Item;
  s32 v11;

  v2 = 1;
  v4 = 0;
  {
LABEL_6:
  }
  while (v4 < LISTMAX)
  {
    v11 = v2;
    v6 = sub_8D3950(s32, &v11);
    v7 = Format("shop_row{0:D2}", v6, 0);
    Item = object___get_Item(ListObjs, v7);
    DispItemList(Item, 0);
    ++v2;
    v4 = v2 - 1;
      goto LABEL_6;
  }
}

// 0x19a4210
void *shpDraw(dds3ProcessID_t *PID) {
  u64 *v2;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  s16 v16;
  s32 v17;
  struct fclDataShop_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  u32 v20;
  s32 PayMoney;
  struct cmpSeqInfo_t_o *v24;
  s32 v25;
  bool v26;
  dds3ProcessID_t_o *v33;
  u64 v34[3];

  v33 = PID;
  v2 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v2);
  ProcessData = dds3GetProcessData(&v33);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataShop_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataShop_t, v34);
    if ((v34[0] & 1) != 0)
      v9 = v34[2];
    else
      v9 = v34 + 1;
    v10 = sub_8C4940(v9);
  }
LABEL_15:
  GBWK = ProcessData;
  else if (fclChkDbgProcess())
  {
    return 0;
  }
  if (fclChkSignal(1))
  {
    if ((v16 & 0x200) != 0)
    {
      v17 = v16 & 0x200;
    }
    else
    {
      v17 = 0;
    }
    SeqInfo = GBWK->SeqInfo;
    if ((SeqInfo->Flag & 0x20) != 0)
    {
      cmpUpdateTerminate(SeqInfo);
      v33->func_ans = -1;
    }
    else
    {
      PayMoney = GBWK->PayMoney;
      shpDrawPayMoney(v20, PayMoney);
      v24 = GBWK->SeqInfo;
      if ((v24->Flag & 2) != 0)
      {
        switch (v24->Current)
        {
          case 0:
            v25 = 1;
            goto LABEL_67;
          case 1:
            v26 = fclChkSignal(0) == 0;
            if (v26)
              goto LABEL_117;
            shpDrawSeqBuy(0);
            break;
          case 2:
            v26 = fclChkSignal(0) == 0;
            if (v26)
              goto LABEL_121;
            shpDrawSeqSell(0);
            break;
          case 3:
          case 4:
            goto LABEL_63;
          case 5:
            v26 = fclChkSignal(0) == 0;
            if (v26)
            {
LABEL_117:
              shpDrawSeqBuy(2);
            }
            else
            {
              shpDrawSeqSelect(0);
            }
            break;
          case 6:
            v26 = fclChkSignal(0) == 0;
            if (v26)
            {
LABEL_121:
              shpDrawSeqSell(2);
            }
            else
            {
              shpDrawSeqSelect(1);
            }
            break;
          case 7:
            shpDrawSeqBuy(1);
            break;
          case 8:
          case 9:
            if (v24->Last == 5)
            {
              shpDrawSeqConfirm(0);
            }
            else
            {
              shpDrawSeqConfirm(1);
            }
            break;
          case 0xA:
          case 0xB:
LABEL_63:
            v25 = 0;
LABEL_67:
            shpDrawSeqRoot(v25);
            break;
          default:
            return 0;
        }
      }
    }
  }
  return 0;
}

// 0x19a2840
void shpDrawBuyItem(s8 Place, lstListWindow_t *pListWindow, s8 mode) {
  struct cmpCursorInfo_t_o *CursorInfo;
  UnityEngine_GameObject_o *GameObject;
  Il2CppObject *Item;
  System_String_o *name;
  cmpCursorPos_t_o *CursorPos;
  System_String_o *v14;
  struct cmpCursorPos_t_o *v16;
  u32 ListNums;
  u32 ShiftMax;
  u32 v19;
  Il2CppObject *v23;
  u32 v27;
  s32 Index;
  u32 v30;
  struct System_UInt16_array *BuyItemList;
  u16 v33;
  s32 v34;
  s32 v37;
  s32 maka;
  s32 v40;
  s8 v41;
  s8 v43;
  u32 v44;
  u64 *v47;
  System_String_o *v48;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  u64 *v53;
  Il2CppObject *v54;
  Il2CppObject *v55;
  s32 CursorIndex;
  struct System_UInt16_array *v61;
  s32 v63;
  Il2CppObject *v67;
  s32 ismsgend;
  bool activeSelf;
  cmpCursorPos_t_o *v72;
  struct cmpCursorPos_t_o *v76;
  s32 Shift;
  u32 v80;
  u32 v81;
  s32 col2;

  CursorInfo = pListWindow->CursorInfo;
  col2 = 2;
  shpDrawPanelParts(1, pListWindow);
  GameObject = GetGameObject("shoplist");
  if (!get_activeSelf(GameObject))
    SetActive(GameObject, 1, 0);
  Item = object___get_Item(ListObjs, "shoplist_scroll");
  name = get_name(Item);
  CursorPos = CursorInfo->CursorPos;
  v14 = name;
  DrawScrollBar(Item, v14, CursorPos);
  v16 = CursorInfo->CursorPos;
  ListNums = v16->ListNums;
  ShiftMax = v16->ShiftMax;
  if (ListNums <= ShiftMax)
    v19 = ListNums;
  else
    v19 = ShiftMax;
  if (ScrollDir)
  {
    v23 = object___get_Item(ListObjs, "shop_row01");
    ScrollEffect(v23);
  }
  _Clear(MatCols);
  v27 = 0;
  while (v27 < v19)
  {
    Index = CursorInfo->CursorPos->Index;
    v30 = v27 + Index;
    BuyItemList = GBWK->BuyItemList;
    v33 = BuyItemList->m_Items[v30];
    if (!v33)
      break;
    v34 = shpCalcItemPrice(v27 + CursorInfo->CursorPos->Index, 0);
    v37 = shpCalcItemPrice(v27 + CursorInfo->CursorPos->Index, 0);
    maka = DDS3_GBWK->maka;
    v40 = v37 > maka;
    v41 = fclChkItemHearts(v33);
    if (v41)
    {
      v43 = v41;
      v40 = (v37 > maka) | (cmbChkGetHearts(v43) != 0);
    }
    if (mode)
      v44 = v40 | 2;
    else
      v44 = v40;
    cmpGetCursorBlurFontCol(CursorInfo, v27, v27, v44, 256, &col2, 0);
    _Add(MatCols, col2);
    v81 = ++v27;
    v47 = sub_8D3950(s32, &v81);
    v48 = Format("shop_row{0:D2}", v47, 0);
    shpDrawItem(v48, col2, v33, v34);
  }
  {
LABEL_67:
  }
  while (v27 < LISTMAX)
  {
    ++v27;
    v80 = v27;
    v53 = sub_8D3950(s32, &v80);
    v54 = Format("shop_row{0:D2}", v53, 0);
    v55 = object___get_Item(ListObjs, v54);
    if (get_activeSelf(v55))
      SetActive(v55, 0, 0);
    _Add(MatCols, -1);
      goto LABEL_67;
  }
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  v61 = GBWK->BuyItemList;
  v63 = v61->m_Items[CursorIndex];
  DrawHelp("shophelp", v63);
  v67 = object___get_Item(ListObjs, "shoplist_cursor");
  ismsgend = GBWK->ismsgend;
  activeSelf = get_activeSelf(v67);
  if (ismsgend)
  {
    if (!activeSelf)
      SetActive(v67, 1, 0);
    v72 = CursorInfo->CursorPos;
    UpdateItemCursor(v67, v72, -346.0, -62.0);
      goto LABEL_109;
  }
  else
  {
    if (activeSelf)
      SetActive(v67, 0, 0);
      goto LABEL_109;
  }
LABEL_109:
    goto LABEL_113;
LABEL_110:
LABEL_113:
  _ToArray(MatCols);
  v76 = CursorInfo->CursorPos;
  if (v76->EffFlag)
  {
    Shift = v76->Shift;
    CsrMoveSw = Shift;
  }
}

// 0x19a23e0
void shpDrawItem(char *path, u32 col, u16 item, s32 price) {
  Il2CppObject *v10;
  System_String_o *v13;
  System_Collections_Generic_Dictionary_object__object__o *TextObjs;
  Il2CppObject *v16;
  Il2CppObject *v17;
  long f64 v19;
  long f64 v20;
  long f64 v21;
  long f64 v22;
  u32 v23;
  System_String_o *LocalizeText;
  System_Object_array *v25;
  s64 *v26;
  s64 *v28;
  System_String_o *v30;
  System_Collections_Generic_Dictionary_object__object__o *CCtrObjs;
  Il2CppObject *v34;
  Il2CppObject *v35;
  UnityEngine_Component_o *v36;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v38;
  Il2CppObject *v39;
  System_Collections_Generic_Dictionary_object__object__o *v42;
  Il2CppObject *v43;
  Il2CppObject *v44;
  UnityEngine_GameObject_o *gameObject;
  bool activeSelf;
  UnityEngine_GameObject_o *v47;
  UnityEngine_GameObject_o *v48;
  bool v49;
  UnityEngine_GameObject_o *v50;
  long f64 v52;
  long f64 v53;
  long f64 v54;
  long f64 v55;
  u32 v56;
  UnityEngine_Color_o gray;
  UnityEngine_Color_o white;
  UnityEngine_Color_o v59;

  v10 = object___get_Item(ListObjs, path);
  if (!get_activeSelf(v10))
    SetActive(v10, 1, 0);
  v13 = Get(item, 0);
  v16 = Concat_5224608(path, "_name");
  v17 = object___get_Item(TextObjs, v16);
  if (col == 2)
  {
    gray = get_gray();
    *&v52 = gray.r;
    *&v53 = gray.g;
    *&v54 = gray.b;
    *&v55 = gray.a;
  }
  else
  {
    white = get_white();
    *&v52 = white.r;
    *&v53 = white.g;
    *&v54 = white.b;
    *&v55 = white.a;
  }
  v19 = v52;
  v20 = v53;
  v21 = v54;
  v22 = v55;
  if (col == 2)
    v23 = 0;
  else
    v23 = col;
  LocalizeText = GetLocalizeText(v13);
  v56 = v23;
  v25 = NewSpecific(object, 1u);
  v26 = sub_8D3950(s32, &v56);
  v28 = v26;
  v25->m_Items[0] = v28;
  v30 = RepColTag(LocalizeText, v25);
  set_text(v17, v30);
  (v17->klass->vtable[23].methodPtr)(v17, v17->klass->vtable[23].v19, v20, v21, v22);
  v34 = Concat_5224608(path, "_money");
  v35 = object___get_Item(CCtrObjs, v34);
  v59.r = *&v19;
  v59.g = *&v20;
  v59.b = *&v21;
  v59.a = *&v22;
  v36 = v35;
  Set(v35, price, v59, 0, 0);
  v38 = Concat_5224608(path, "_makka_on");
  v39 = object___get_Item(ListObjs, v38);
  if (get_activeSelf(v39))
    SetActive(v39, 0, 0);
  v42 = ListObjs;
  v43 = Concat_5224608(path, "_makka_off");
  v44 = object___get_Item(v42, v43);
  gameObject = get_gameObject(v36);
  activeSelf = get_activeSelf(gameObject);
  if (price)
  {
    if (!activeSelf)
    {
      v47 = get_gameObject(v36);
      SetActive(v47, 1, 0);
    }
    if (!get_activeSelf(v44))
    {
      v48 = v44;
      v49 = 1;
LABEL_47:
      SetActive(v48, v49, 0);
    }
  }
  else
  {
    if (activeSelf)
    {
      v50 = get_gameObject(v36);
      SetActive(v50, 0, 0);
    }
    if (get_activeSelf(v44))
    {
      v48 = v44;
      v49 = 0;
      goto LABEL_47;
    }
  }
}

// 0x19a1fa0
void shpDrawNumsControl(cmpCursorInfo_t *csr, s32 val, s8 mode) {
  u32 v6;
  s32 Shift;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  u64 *v10;
  Il2CppObject *v11;
  Il2CppObject *Item;
  u64 *v15;
  System_String_o *v17;
  System_Collections_Generic_Dictionary_object__object__o *v19;
  Il2CppObject *v20;
  Il2CppObject *v21;
  bool activeSelf;
  System_Collections_Generic_Dictionary_object__object__o *CCtrObjs;
  Il2CppObject *v26;
  Il2CppObject *v27;
  Il2CppObject *v28;
  s32 v29;
  s32 v32;
  u32 v33;

  v6 = 0;
  Shift = csr->CursorPos->Shift;
  {
LABEL_6:
  }
  while (v6 < LISTMAX)
  {
    v33 = v6 + 1;
    v10 = sub_8D3950(s32, &v33);
    v11 = Format("shop_row{0:D2}", v10, 0);
    Item = object___get_Item(ListObjs, v11);
    DispItemList(Item, v6++ == Shift);
      goto LABEL_6;
  }
  v32 = Shift + 1;
  v15 = sub_8D3950(s32, &v32);
  v17 = Format("shop_row{0:D2}", v15, 0);
  v19 = ListObjs;
  v20 = Concat_5224608(v17, "_x");
  v21 = object___get_Item(v19, v20);
  activeSelf = get_activeSelf(v21);
  if (val)
  {
    if (!activeSelf)
      SetActive(v21, 1, 0);
    v26 = Concat_5224608(v17, "_num");
    v27 = object___get_Item(CCtrObjs, v26);
    SetInstitutionColor(v27, val, 1);
    v28 = object___get_Item(ListObjs, v17);
    DispItemUD(v28, v29, mode);
  }
  else if (activeSelf)
  {
    SetActive(v21, 0, 0);
  }
}

// 0x19a2230
void shpDrawPanelParts(s32 mode) {
  Il2CppObject *Item;
  Il2CppObject *v6;
  bool activeSelf;
  UnityEngine_GameObject_o *v9;
  bool v10;

  DrawBackPanel("shopbgcolor");
  DrawBackPanel("shopbase");
  Item = object___get_Item(ListObjs, "shopindex_buy");
  v6 = object___get_Item(ListObjs, "shopindex_sell");
  activeSelf = get_activeSelf(Item);
  if (mode)
  {
    if (!activeSelf)
      SetActive(Item, 1, 0);
    if (get_activeSelf(v6))
    {
      v9 = v6;
      v10 = 0;
LABEL_18:
      SetActive(v9, v10, 0);
    }
  }
  else
  {
    if (activeSelf)
      SetActive(Item, 0, 0);
    if (!get_activeSelf(v6))
    {
      v9 = v6;
      v10 = 1;
      goto LABEL_18;
    }
  }
  UpdateDrawFlag("shoplist");
}

// 0x19a19e0
void shpDrawPayMoney(u32 Color, s32 Val) {
  Il2CppObject *Item;

  Item = object___get_Item(CCtrObjs, "shopfee");
  DrawPayMoney("shopfee", Item, 0xFFFFFFFF, Val);
}

// 0x19a3120
void shpDrawSellItem(s8 Place, lstListWindow_t *pListWindow, s8 Mode) {
  struct cmpCursorInfo_t_o *CursorInfo;
  UnityEngine_GameObject_o *GameObject;
  Il2CppObject *Item;
  System_String_o *name;
  cmpCursorPos_t_o *CursorPos;
  struct cmpCursorPos_t_o *v15;
  u32 ListNums;
  u32 ShiftMax;
  u32 v19;
  Il2CppObject *v22;
  u32 v26;
  s32 Index;
  u32 v29;
  struct System_UInt16_array *ItemIdx;
  u16 v32;
  s32 v34;
  s32 v35;
  u32 v37;
  u64 *v40;
  System_String_o *v41;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  u64 *v46;
  Il2CppObject *v47;
  Il2CppObject *v48;
  s32 CursorIndex;
  struct System_UInt16_array *v54;
  s32 v56;
  Il2CppObject *v60;
  s32 ismsgend;
  bool activeSelf;
  cmpCursorPos_t_o *v65;
  struct cmpCursorPos_t_o *v69;
  s32 Shift;
  lstListWindow_t_o *pListWindowa;
  u32 v74;
  u32 v75;
  s32 col2;

  CursorInfo = pListWindow->CursorInfo;
  col2 = 2;
  shpDrawPanelParts(0, pListWindow);
  GameObject = GetGameObject("shoplist");
  if (!get_activeSelf(GameObject))
    SetActive(GameObject, 1, 0);
  Item = object___get_Item(ListObjs, "shoplist_scroll");
  name = get_name(Item);
  CursorPos = CursorInfo->CursorPos;
  DrawScrollBar(Item, name, CursorPos);
  v15 = CursorInfo->CursorPos;
  ListNums = v15->ListNums;
  ShiftMax = v15->ShiftMax;
  if (ListNums <= ShiftMax)
    v19 = ListNums;
  else
    v19 = ShiftMax;
  if (ScrollDir)
  {
    v22 = object___get_Item(ListObjs, "shop_row01");
    ScrollEffect(v22);
  }
  _Clear(MatCols);
  v26 = 0;
  pListWindowa = pListWindow;
  while (v26 < v19)
  {
    Index = CursorInfo->CursorPos->Index;
    v29 = v26 + Index;
    ItemIdx = GBWK->SellItemList->ItemIdx;
    v32 = ItemIdx->m_Items[v29];
    v34 = shpCalcItemPrice(v26 + CursorInfo->CursorPos->Index, 1);
    v35 = cmpChkDoNotBuyItemTokusyu(v32);
    if (v35 == 1)
      v34 = 0;
    if (Mode)
      v37 = (v35 == 1) | 2;
    else
      v37 = v35 == 1;
    cmpGetCursorBlurFontCol(CursorInfo, v26, v26, v37, 256, &col2, 0);
    _Add(MatCols, col2);
    v75 = ++v26;
    v40 = sub_8D3950(s32, &v75);
    v41 = Format("shop_row{0:D2}", v40, 0);
    shpDrawItem(v41, col2, v32, v34);
  }
  {
LABEL_60:
  }
  while (v26 < LISTMAX)
  {
    ++v26;
    v74 = v26;
    v46 = sub_8D3950(s32, &v74);
    v47 = Format("shop_row{0:D2}", v46, 0);
    v48 = object___get_Item(ListObjs, v47);
    if (get_activeSelf(v48))
      SetActive(v48, 0, 0);
    _Add(MatCols, -1);
      goto LABEL_60;
  }
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  v54 = GBWK->SellItemList->ItemIdx;
  v56 = v54->m_Items[CursorIndex];
  DrawHelp("shophelp", v56);
  v60 = object___get_Item(ListObjs, "shoplist_cursor");
  ismsgend = GBWK->ismsgend;
  activeSelf = get_activeSelf(v60);
  if (ismsgend)
  {
    if (!activeSelf)
      SetActive(v60, 1, 0);
    v65 = CursorInfo->CursorPos;
    UpdateItemCursor(v60, v65, -346.0, -62.0);
    if (!Mode)
    {
LABEL_105:
      lstDrawListWindowCursor(pListWindowa, 0);
        goto LABEL_106;
      goto LABEL_101;
    }
  }
  else if (activeSelf)
  {
    SetActive(v60, 0, 0);
    if (!Mode)
      goto LABEL_105;
  }
  else if (!Mode)
  {
    goto LABEL_105;
  }
    goto LABEL_106;
LABEL_101:
LABEL_106:
    goto LABEL_109;
LABEL_107:
LABEL_109:
  _ToArray(MatCols);
  v69 = CursorInfo->CursorPos;
  if (v69->EffFlag)
  {
    Shift = v69->Shift;
    CsrMoveSw = Shift;
  }
}

// 0x19a3a80
void shpDrawSeqBuy(s8 Mode) {
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_Collections_Generic_Dictionary_object__object__o *v4;
  System_String_o *v6;
  Il2CppObject *Item;
  Il2CppObject *v9;
  fclShopInit_c *v13;

  else
  {
    v4 = *static_fields;
    if (!LODWORD((*static_fields)->entries))
      goto LABEL_6;
  }
  v6 = *&v4->count;
  Item = object___get_Item(static_fields[2], "shoptitle");
  DrawCaption2("shoptitle", v6, Item);
  v9 = object___get_Item(CCtrObjs, "num_money");
  DrawTotalMoney("shopmoney", v9);
  shopClearNumControl();
  shpDrawBuyItem(v13, GBWK->ListWindow, Mode);
  Update(0);
}

// 0x19a4020
void shpDrawSeqConfirm(s8 Mode) {
  u64 *v3;
  struct fclDataShop_t_o *GBWK;
  cmpCursorInfo_t_o *CursorInfo;
  s32 ChoiceNums;

  v3 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v3);
  if (Mode)
  {
    shpDrawSeqSell(2);
  }
  else
  {
    shpDrawSeqBuy(2);
  }
  CursorInfo = GBWK->ListWindow->CursorInfo;
  ChoiceNums = GBWK->ChoiceNums;
  shpDrawNumsControl(CursorInfo, ChoiceNums, 4);
}

// 0x19a4130
void shpDrawSeqErr(void) {
  shpDrawSeqBuy(1);
}

// 0x19a38f0
void shpDrawSeqRoot(s32 Mode) {
  s32 v3;
  Il2CppObject *Item;

  if (Mode)
  {
    v3 = 0;
    if (!fclChkSignal(0))
    {
      if (GBWK->SeqInfo->Last == 3)
        v3 = 1;
      else
        v3 = 2;
    }
  }
  else
  {
    v3 = 1;
  }
  Item = object___get_Item(CCtrObjs, "num_money");
  DrawTotalMoney("shopmoney", Item);
  DrawCommandSelectMenu(GBWK->CmdSelInfo->CursorInfo, 0, v3);
  Update(0);
}

// 0x19a3d90
void shpDrawSeqSelect(s8 Mode) {
  u64 *v3;
  s16 v8;
  s32 v9;
  s32 ChoiceNums;
  s32 v11;
  s32 v13;
  s16 v15;
  s32 v16;
  struct fclDataShop_t_o *GBWK;
  s32 v18;
  s32 v19;
  s8 v20;
  struct lstListWindow_t_o *ListWindow;
  struct cmpCursorInfo_t_o *CursorInfo;
  struct fclPanelPos_t_o *Pos;
  s32 X;
  s32 Y;
  s32 Shift;
  s32 StepY;
  s32 v29;
  struct fclDataShop_t_o *v32;
  s32 v33;
  cmpCursorInfo_t_o *v34;

  v3 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v3);
  if (Mode)
  {
    shpDrawSeqSell(1);
  }
  else
  {
    shpDrawSeqBuy(1);
  }
  if ((v8 & 0x200) != 0)
  {
    v9 = v8 & 0x200;
  }
  else
  {
    v9 = 0;
  }
  ChoiceNums = GBWK->ChoiceNums;
  v11 = ChoiceNums == 1;
  if (ChoiceNums == 99)
    v11 = 2;
  v13 = shpChkChoiceMax(-1, Mode, 1);
  if ((v15 & 0x200) != 0)
  {
    v16 = v15 & 0x200;
  }
  else
  {
    v16 = 0;
  }
  if (v11 == 1)
    v18 = 4;
  else
    v18 = 2;
  if (v13 <= GBWK->ChoiceNums)
    v19 = v18;
  else
    v19 = v11;
  if (v19)
    v20 = v19;
  else
    v20 = 3;
  ListWindow = GBWK->ListWindow;
  CursorInfo = ListWindow->CursorInfo;
  Pos = ListWindow->Pos;
  X = Pos->X;
  Y = Pos->Y;
  Shift = CursorInfo->CursorPos->Shift;
  StepY = CursorInfo->StepY;
  v29 = CMP_Y(StepY * Shift);
  fclInitPanelPos(X, v29 + Y, 0xFFFFFu, 0, 0, 0, v3);
  v32 = GBWK;
  v33 = v32->ChoiceNums;
  v34 = v32->ListWindow->CursorInfo;
  shpDrawNumsControl(v34, v33, v20);
}

// 0x19a3c10
void shpDrawSeqSell(s8 Mode) {
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *v6;
  Il2CppObject *Item;
  Il2CppObject *v9;
  fclShopInit_c *v13;

  v6 = *&(*static_fields)->freeList;
  Item = object___get_Item(static_fields[2], "shoptitle");
  DrawCaption2("shoptitle", v6, Item);
  v9 = object___get_Item(CCtrObjs, "num_money");
  DrawTotalMoney("shopmoney", v9);
  shopClearNumControl();
  shpDrawSellItem(v13, GBWK->ListWindow, Mode);
  Update(0);
}

// 0x19a41a0
void shpDrawServiceTicket(void) {
  shpDrawSeqRoot(0);
}
