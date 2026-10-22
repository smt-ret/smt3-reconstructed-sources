#include "types.h"

typedef struct CounterCtr CounterCtr;
typedef struct RippleEffect RippleEffect;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclRagExchangeRate_t fclRagExchangeRate_t;
typedef struct fclSprite_t fclSprite_t;
typedef struct lstListWindow_t lstListWindow_t;

static char *gRagCaptionStr[3];
static void *ListObjs;
static void *TextObjs;
static void *CCtrObjs;
static void *MatCols;
static void *d_path;
static void *d_name;
static s32 CsrMoveSw;

s32 CMP_XM(s32 a);
s32 CMP_YM(s32 b);
void DrawBackPanel(char *name);
void DrawCaption2(char *name, char *caption, void *txt);
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style);
void DrawHelp2(char *path, s32 itemid);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
u8 Get(s32 id);
void *GetGameObject(char *name);
char *RepColTag(char *txt, void **LegacyParamArray);
void ScrollEffect(void *obj);
void Set2(CounterCtr *this, s32 val, sdfColor_t col, s32 colidx);
void SetInstitutionColor(CounterCtr *this, s32 val, s32 colidx);
void Update(RippleEffect *this);
void UpdateDrawFlag(char *name);
void UpdateItemCursor(void *csrobj, cmpCursorPos_t *csr, f32 y, f32 ofsy);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkDbgProcess(void);
void fclDrawBG(fclSprite_t *pSprite, u32 OtNo);
s8 fclRagChkExchange(fclRagExchangeRate_t **pRate);
void ragDrawDevilPanelParts(void);
void ragDrawDevilWindow(lstListWindow_t *pListWindow, u8 Type, s8 **pIdxList, s32 top, s8 Mode);
void ragDrawExchangeRate(u8 type, u8 index);
void ragDrawItemPanelParts(void);
void ragDrawItemWindow(lstListWindow_t *pListWindow, u8 Type, s8 **pIdxList, s32 top, s8 Mode);
void ragDrawSeqConfirm(void);
void ragDrawSeqErr(void);
void ragDrawSeqItem(s8 Mode);
void ragDrawSeqMitama(s8 Mode);
void ragDrawSeqRoot(s32 Mode);
void ragDrawSeqSeirei(s8 Mode);
void ragDrawSeqStatus(void);
fclRagExchangeRate_t **ragGetExchangeRate(s8 Type, u8 Index);

// 0x13cf670
void FinalizeGameObject(void) {
  PropertySheet___Clear(CCtrObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(ListObjs);
}

// 0x13ceb20
void InitializeGameObject(void) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v3;
  u64 *v4;
  s32 v5;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v7;
  s32 v9;
  System_WeakReference_o *Item;
  System_WeakReference_o *v11;
  const MethodInfo_1260 **v14;
  u32 v15;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v16;
  System_String_o *v17;
  UnityEngine_Component_o *v18;
  UnityEngine_GameObject_o *v19;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *TextObjs;
  System_String_o *v21;
  System_Collections_Generic_Dictionary_object__object__o *v22;
  UnityEngine_Shader_o *v23;
  Il2CppObject *v24;
  Il2CppObject *v25;
  Il2CppObject *v26;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *CCtrObjs;
  System_String_o *v28;
  System_Collections_Generic_Dictionary_object__object__o *v29;
  UnityEngine_Shader_o *v30;
  Il2CppObject *v31;
  Il2CppObject *v32;
  Il2CppObject *v33;
  System_WeakReference_o *v35;
  UnityEngine_Transform_o *v36;
  u32 v37;
  UnityEngine_Transform_o *v38;
  u64 *v39;
  System_String_o *v41;
  s32 v43;
  const MethodInfo_1260 **v44;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *ListObjs;
  System_WeakReference_o *v46;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v47;
  System_String_o *v48;
  UnityEngine_Component_o *v49;
  UnityEngine_GameObject_o *v50;
  System_Collections_Generic_Dictionary_object__object__o *v51;
  Il2CppObject *v52;
  Il2CppObject *v53;
  Il2CppObject *Component_object;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v59;
  UnityEngine_Transform_o *v60;
  UnityEngine_Component_o *v61;
  UnityEngine_GameObject_o *v62;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v63;
  UnityEngine_Transform_o *v64;
  UnityEngine_Component_o *v65;
  UnityEngine_GameObject_o *v66;
  UnityEngine_Transform_o *v67;
  UnityEngine_Component_o *v68;
  UnityEngine_GameObject_o *v69;
  s32 v71;
  UnityEngine_Transform_o *v72;
  UnityEngine_Transform_o *v73;
  u64 *v74;
  System_String_o *v75;
  UnityEngine_Object_o *v76;
  System_String_o *name;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v80;
  UnityEngine_GameObject_o *v81;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v82;
  System_String_o *v83;
  UnityEngine_Component_o *v84;
  UnityEngine_GameObject_o *v85;
  System_Collections_Generic_Dictionary_object__object__o *v86;
  Il2CppObject *v87;
  Il2CppObject *v88;
  Il2CppObject *v90;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v93;
  System_String_o *v94;
  UnityEngine_Component_o *v95;
  UnityEngine_GameObject_o *v96;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v97;
  System_String_o *v98;
  UnityEngine_Component_o *v99;
  UnityEngine_GameObject_o *v100;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v101;
  System_String_o *v102;
  System_Collections_Generic_Dictionary_object__object__o *v103;
  UnityEngine_Shader_o *v104;
  Il2CppObject *v105;
  Il2CppObject *v106;
  Il2CppObject *v107;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v108;
  System_String_o *v109;
  System_Collections_Generic_Dictionary_object__object__o *v110;
  UnityEngine_Shader_o *v111;
  Il2CppObject *v112;
  Il2CppObject *v113;
  Il2CppObject *v114;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v115;
  System_String_o *v116;
  System_Collections_Generic_Dictionary_object__object__o *v117;
  UnityEngine_Shader_o *v118;
  Il2CppObject *v119;
  Il2CppObject *v120;
  Il2CppObject *v121;
  UnityEngine_GameObject_o *v124;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v126;
  UnityEngine_Transform_o *v127;
  UnityEngine_Component_o *v128;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_GameObject_o *GameObject;
  UnityEngine_GameObject_o *v131;
  s32 v132;
  u32 v133;

  GameObject = GetGameObject("ragitemlist");
  transform = get_transform(GameObject, 0);
  v3 = Find(transform, "ragitem_row", 0);
  v4 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v4);
  if (get_childCount(v3) >= 1)
  {
    v5 = 0;
    do
    {
      Child = GetChild(v3, v5);
      v7 = get_gameObject(Child);
      _Add(v4, v7);
      ++v5;
    }
    while (v5 < get_childCount(v3));
  }
  if (_get_Count(v4) >= 1)
  {
    v9 = 0;
    do
    {
      Item = _get_Item(
               v4,
               v9);
      if (get_activeSelf(Item))
      {
        v11 = _get_Item(
                v4,
                v9);
        SetActive(v11, 0, 0);
      }
      ++v9;
    }
    while (v9 < _get_Count(v4));
  }
  PropertySheet___Clear(ListObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(CCtrObjs);
  v14 = &Method_System_Collections_Generic_List_GameObject__get_Item__;
  v15 = 0;
  while (1)
  {
    if (v15 >= LISTMAX)
      break;
    v35 = _get_Item(v4, v15, *v14);
    v36 = get_transform(v35, 0);
    v37 = v15 + 1;
    v133 = v37;
    v38 = v36;
    v39 = sub_8D3950(s32, &v133);
    v41 = Format("rag_row{0:D2}", v39, 0);
    v43 = v37 - 1;
    v44 = v14;
    v46 = _get_Item(v4, v43, *v14);
    PropertySheet___Add(ListObjs, v41, v46);
    v47 = ListObjs;
    v48 = Concat_5224608(v41, "_name");
    v49 = Find(v38, "Text_nameTM", 0);
    v50 = get_gameObject(v49);
    PropertySheet___Add(v47, v48, v50);
    v51 = ListObjs;
    v52 = Concat_5224608(v41, "_name");
    v53 = object___get_Item(v51, v52);
    Component_object = GetComponent_object_(v53);
    if (op_Inequality(Component_object, 0, 0))
      set_enabled(Component_object, 0);
    v16 = ListObjs;
    v17 = Concat_5224608(v41, "_lv");
    v18 = Find(v38, "lvnum", 0);
    v19 = get_gameObject(v18);
    PropertySheet___Add(v16, v17, v19);
    v21 = Concat_5224608(v41, "_name");
    v22 = ListObjs;
    v23 = v21;
    v24 = Concat_5224608(v41, "_name");
    v25 = object___get_Item(v22, v24);
    v26 = GetComponent_object_(v25);
    PropertySheet___Add(TextObjs, v23, v26);
    v28 = Concat_5224608(v41, "_lv");
    v29 = ListObjs;
    v30 = v28;
    v31 = Concat_5224608(v41, "_lv");
    v32 = object___get_Item(v29, v31);
    v33 = GetComponent_object_(v32);
    PropertySheet___Add(CCtrObjs, v30, v33);
    v15 = v43 + 1;
    v14 = v44;
  }
  v59 = ListObjs;
  v60 = get_transform(GameObject, 0);
  v61 = Find(v60, "ragsumindex_base", 0);
  v62 = get_gameObject(v61);
  PropertySheet___Add(v59, "ragsumindex_base", v62);
  v63 = ListObjs;
  v64 = get_transform(GameObject, 0);
  v65 = Find(v64, "ragitemindex_base", 0);
  v66 = get_gameObject(v65);
  PropertySheet___Add(v63, "ragitemindex_base", v66);
  v67 = get_transform(GameObject, 0);
  v68 = Find(v67, "menu_cursur", 0);
  v69 = get_gameObject(v68);
  PropertySheet___Add(ListObjs, "menu_cursor", v69);
  v71 = 1;
  v131 = GetGameObject("ragjewel");
  do
  {
    v72 = get_transform(v131, 0);
    v132 = v71;
    v73 = v72;
    v74 = sub_8D3950(s32, &v132);
    v75 = Format("ragjewel_row{0:D2}", v74, 0);
    v76 = Find(v73, v75, 0);
    name = get_name(v76);
    v80 = ListObjs;
    v81 = get_gameObject(v76);
    PropertySheet___Add(v80, name, v81);
    v82 = ListObjs;
    v83 = Concat_5224608(name, "_name");
    v84 = Find(v76, "Text_nameTM", 0);
    v85 = get_gameObject(v84);
    PropertySheet___Add(v82, v83, v85);
    v86 = ListObjs;
    v87 = Concat_5224608(name, "_name");
    v88 = object___get_Item(v86, v87);
    v90 = GetComponent_object_(v88);
    if (op_Inequality(v90, 0, 0))
      set_enabled(v90, 0);
    v93 = ListObjs;
    v94 = Concat_5224608(name, "_jewel");
    v95 = Find(v76, "num_jewel", 0);
    v96 = get_gameObject(v95);
    PropertySheet___Add(v93, v94, v96);
    v97 = ListObjs;
    v98 = Concat_5224608(name, "_possess");
    v99 = Find(v76, "num_possess", 0);
    v100 = get_gameObject(v99);
    PropertySheet___Add(v97, v98, v100);
    v101 = TextObjs;
    v102 = Concat_5224608(name, "_name");
    v103 = ListObjs;
    v104 = v102;
    v105 = Concat_5224608(name, "_name");
    v106 = object___get_Item(v103, v105);
    v107 = GetComponent_object_(v106);
    PropertySheet___Add(v101, v104, v107);
    v108 = CCtrObjs;
    v109 = Concat_5224608(name, "_jewel");
    v110 = ListObjs;
    v111 = v109;
    v112 = Concat_5224608(name, "_jewel");
    v113 = object___get_Item(v110, v112);
    v114 = GetComponent_object_(v113);
    PropertySheet___Add(v108, v111, v114);
    v115 = CCtrObjs;
    v116 = Concat_5224608(name, "_possess");
    v117 = ListObjs;
    v118 = v116;
    v119 = Concat_5224608(name, "_possess");
    v120 = object___get_Item(v117, v119);
    v121 = GetComponent_object_(v120);
    PropertySheet___Add(v115, v118, v121);
    ++v71;
  }
  while (v71 != 4);
  v124 = GetGameObject("ragtitle");
  v126 = TextObjs;
  v127 = get_transform(v124, 0);
  v128 = Find(v127, "Text_ragtitleTM", 0);
  Component_GUILayer = GetComponent_GUILayer_(v128);
  PropertySheet___Add(v126, "ragtitle", Component_GUILayer);
}

// 0x13d0b20
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

// 0x13d2e00
void UpdateList(s32 mode) {
  struct System_SByte_array *v4;
  s32 v6;
  struct System_SByte_array *gFclSignal;
  s32 v10;
  struct System_SByte_array *v12;
  s32 v14;

  switch (mode)
  {
    case 3:
      v10 = gFclSignal->m_Items[0];
      ragDrawSeqMitama(v10 == 0);
      break;
    case 2:
      v12 = gFclSignal;
      v14 = v12->m_Items[0];
      ragDrawSeqSeirei(v14 == 0);
      break;
    case 1:
      v4 = gFclSignal;
      v6 = v4->m_Items[0];
      ragDrawSeqItem(v6 == 0);
      break;
  }
}

// 0x13d27a0
void *ragDraw(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct System_SByte_array *gFclSignal;
  s16 v15;
  s32 v16;
  struct cmpSeqInfo_t_o *SeqInfo;
  u8 Flag;
  struct System_SByte_array *v20;
  s32 v22;
  struct System_SByte_array *v24;
  s32 v26;
  struct System_SByte_array *v28;
  s32 v30;
  UnityEngine_Object_o *statusUIScr;
  dds3ProcessID_t_o *v37;
  u64 v38[3];

  v37 = PID;
  ProcessData = dds3GetProcessData(&v37);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataRag_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataRag_t, v38);
    if ((v38[0] & 1) != 0)
      v7 = v38[2];
    else
      v7 = v38 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  else if (fclChkDbgProcess())
  {
    return 0;
  }
  if (gFclSignal->m_Items[1])
  {
    if ((v15 & 0x200) != 0)
    {
      v16 = v15 & 0x200;
    }
    else
    {
      v16 = 0;
    }
    SeqInfo = GBWK->SeqInfo;
    Flag = SeqInfo->Flag;
    if ((Flag & 0x20) != 0)
    {
      cmpUpdateTerminate(SeqInfo);
      v37->func_ans = -1;
    }
    else
    {
      if ((Flag & 2) != 0)
      {
        switch (SeqInfo->Current)
        {
          case 0:
            ragDrawSeqRoot(1);
            break;
          case 1:
            v20 = gFclSignal;
            v22 = v20->m_Items[0];
            ragDrawSeqItem(v22 == 0);
            break;
          case 2:
            v24 = gFclSignal;
            v26 = v24->m_Items[0];
            ragDrawSeqSeirei(v26 == 0);
            break;
          case 3:
            v28 = gFclSignal;
            v30 = v28->m_Items[0];
            ragDrawSeqMitama(v30 == 0);
            break;
          case 4:
          case 5:
            ragDrawSeqRoot(0);
            break;
          case 6:
            ragDrawSeqErr();
            break;
          case 7:
            statusUIScr = _statusUIScr;
            if (op_Inequality(statusUIScr, 0, 0))
            {
              ragDrawSeqStatus();
            }
            break;
          case 8:
            ragDrawSeqConfirm();
            break;
          default:
            return 0;
        }
      }
    }
  }
  return 0;
}

// 0x13cfe50
void ragDrawDevilPanelParts(void) {
  Il2CppObject *Item;
  Il2CppObject *v5;

  DrawBackPanel("ragbgcolor");
  DrawBackPanel("ragbase");
  Item = object___get_Item(ListObjs, "ragsumindex_base");
  v5 = object___get_Item(ListObjs, "ragitemindex_base");
  if (!get_activeSelf(v5))
  {
    if (get_activeSelf(Item))
      return;
LABEL_13:
    SetActive(Item, 1, 0);
    return;
  }
  SetActive(v5, 0, 0);
  if (!get_activeSelf(Item))
    goto LABEL_13;
}

// 0x13d0ba0
void ragDrawDevilWindow(lstListWindow_t *pListWindow, u8 Type, s8 **pIdxList, s32 top, s8 Mode) {
  struct cmpCursorInfo_t_o *CursorInfo;
  UnityEngine_GameObject_o *GameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_Object_o *v15;
  System_String_o *name;
  cmpCursorPos_t_o *CursorPos;
  Il2CppObject *Item;
  const MethodInfo_1221 **v26;
  u64 v27;
  u64 v30;
  System_Text_StringBuilder_o *d_name;
  u64 *v32;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v35;
  const MethodInfo_1221 **v36;
  Il2CppObject *v37;
  u32 v40;
  struct fclRagDevil_t_array *fclRagSeireiTbl;
  u32 v45;
  s32 DevilID;
  struct fclRagDevil_t_array *v47;
  Il2CppClass **v50;
  struct fclRagDevil_t_array *fclRagMitamaTbl;
  struct fclRagDevil_t_array *v54;
  s32 v57;
  fclRagExchangeRate_t_array *ExchangeRate;
  s8 v61;
  u32 v63;
  u8 v64;
  System_String_o *v67;
  System_Text_StringBuilder_o *d_path;
  System_String_o *v71;
  System_Collections_Generic_Dictionary_object__object__o *TextObjs;
  Il2CppObject *v74;
  Il2CppObject *v75;
  System_Object_array *v76;
  System_Object_array *v77;
  s64 *v78;
  s64 *v80;
  System_String_o *v82;
  System_Collections_Generic_List_int__o *MatCols;
  s32 v86;
  System_Text_StringBuilder_o *v90;
  System_String_o *v91;
  System_Collections_Generic_Dictionary_object__object__o *v93;
  Il2CppObject *v94;
  Il2CppObject *v95;
  s32 CMB_UPINFO_COL;
  s32 v100;
  f32 v102;
  f32 v103;
  f32 v104;
  f32 v105;
  System_Collections_Generic_Dictionary_object__object__o *CCtrObjs;
  Il2CppObject *v110;
  Il2CppObject *v111;
  System_Text_StringBuilder_o *v115;
  u64 *v116;
  System_Collections_Generic_Dictionary_object__object__o *v118;
  Il2CppObject *v119;
  Il2CppObject *v120;
  Il2CppObject *v124;
  s32 ismsgend;
  bool activeSelf;
  cmpCursorPos_t_o *v129;
  struct cmpCursorPos_t_o *v133;
  s32 Shift;
  long f64 v136;
  long f64 v137;
  long f64 v138;
  long f64 v139;
  f32 r;
  f32 g;
  f32 b;
  f32 a;
  s32 v144;
  struct cmpCursorInfo_t_o *v145;
  s32 v146;
  s8 *v149;
  s32 v151;
  s32 col2;
  UnityEngine_Color_o white;
  UnityEngine_Color_o gray;
  UnityEngine_Color_o v155;
  UnityEngine_Color_o v156;
  UnityEngine_Color_o v157;
  UnityEngine_Color_o v158;

  CursorInfo = pListWindow->CursorInfo;
  col2 = 2;
  ragDrawDevilPanelParts();
  GameObject = GetGameObject("ragitemlist");
  if (!get_activeSelf(GameObject))
    SetActive(GameObject, 1, 0);
  transform = get_transform(GameObject, 0);
  Find(transform, "ragitem_row", 0);
  v13 = get_transform(GameObject, 0);
  v14 = Find(v13, "ragscroll", 0);
  v15 = get_gameObject(v14);
  name = get_name(v15);
  CursorPos = CursorInfo->CursorPos;
  DrawScrollBar(v15, name, CursorPos);
  if (ScrollDir)
  {
    Item = object___get_Item(ListObjs, "rag_row01");
    ScrollEffect(Item);
  }
  _Clear(MatCols);
  if (CursorInfo->CursorPos->ShiftMax)
  {
    v26 = &Method_System_Collections_Generic_Dictionary_string__GameObject__get_Item__;
    v144 = top;
    v145 = CursorInfo;
    v27 = 0;
    v146 = top;
    v149 = &pIdxList->m_Items[top];
    while (1)
    {
      v30 = v27;
      Clear(d_name, 0);
      ++v27;
      v151 = v30 + 1;
      v32 = sub_8D3950(s32, &v151);
      AppendFormat(d_name, "rag_row{0:D2}", v32);
      v35 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      v36 = v26;
      v37 = object___get_Item(ListObjs, v35, *v26);
      if (!get_activeSelf(v37))
        SetActive(v37, 1, 0);
      v40 = v146 + v30;
      if (Type == 1)
      {
        v45 = v30 + v144;
        DevilID = fclRagSeireiTbl->m_Items[v149[v30]]->DevilID;
        v47 = fclRagSeireiTbl;
        v50 = &v47->obj.klass + v149[v30];
      }
      else
      {
        DevilID = fclRagMitamaTbl->m_Items[v149[v30]]->DevilID;
        v54 = fclRagMitamaTbl;
        v50 = &v54->obj.klass + v149[v30];
        v45 = v146 + v30;
      }
      v57 = *(v50[4]->_1.namespaze + 16);
      ExchangeRate = ragGetExchangeRate(Type, v149[v30]);
      v61 = fclRagChkExchange(ExchangeRate);
      if (Mode)
        v63 = (v61 == 0) | 2;
      else
        v63 = v61 == 0;
      v64 = v61;
      cmpGetCursorBlurFontCol(CursorInfo, v40, v30, v63, 256, &col2, 0);
      v67 = Get(DevilID, 0);
      Clear(d_path, 0);
      v71 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      Append_5380272(d_path, v71);
      Append_5380272(d_path, "_name");
      v74 = (d_path->klass->vtable._3_ToString.methodPtr)(
              d_path,
              d_path->klass->vtable._3_ToString.method);
      v75 = object___get_Item(TextObjs, v74);
      v76 = NewSpecific(object, 1u);
      v151 = col2;
      v77 = v76;
      v78 = sub_8D3950(s32, &v151);
      v80 = v78;
      v77->m_Items[0] = v80;
      v82 = RepColTag(v67, v77);
      set_text(v75, v82);
      if (v64)
      {
        white = get_white();
        *&v136 = white.r;
        *&v137 = white.g;
        *&v138 = white.b;
        *&v139 = white.a;
      }
      else
      {
        gray = get_gray();
        *&v136 = gray.r;
        *&v137 = gray.g;
        *&v138 = gray.b;
        *&v139 = gray.a;
      }
      CursorInfo = v145;
      (v75->klass->vtable[23].methodPtr)(v75, v75->klass->vtable[23].v136, v137, v138, v139);
      if (v64)
        v86 = col2;
      else
        v86 = 2;
      v26 = v36;
      _Add(MatCols, v86);
      Clear(d_path, 0);
      v90 = d_path;
      v91 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      Append_5380272(v90, v91);
      Append_5380272(d_path, "_lv");
      v93 = ListObjs;
      v94 = (d_path->klass->vtable._3_ToString.methodPtr)(
              d_path,
              d_path->klass->vtable._3_ToString.method);
      v95 = object___get_Item(v93, v94, *v36);
      if (!get_activeSelf(v95))
        SetActive(v95, 1, 0);
      if (!v64)
        goto LABEL_108;
      if (Get(DevilID, 1, 0)->level < v57)
      {
        v100 = v64;
        v155 = get_white();
        r = v155.r;
        g = v155.g;
        b = v155.b;
        a = v155.a;
        if (v64)
        {
LABEL_109:
          v102 = r;
          v103 = g;
          v104 = b;
          v105 = a;
          v100 = 2 * (CMB_UPINFO_COL == CMB_UPINFO_COL);
            goto LABEL_113;
LABEL_106:
          goto LABEL_113;
        }
      }
      else
      {
LABEL_108:
        CMB_UPINFO_COL = 0;
        v100 = v64;
        v157 = get_white();
        r = v157.r;
        g = v157.g;
        b = v157.b;
        a = v157.a;
        if (v64)
          goto LABEL_109;
      }
      v156 = get_gray();
      v102 = v156.r;
      v103 = v156.g;
      v104 = v156.b;
      v105 = v156.a;
        goto LABEL_106;
LABEL_113:
      v110 = (d_path->klass->vtable._3_ToString.methodPtr)(
               d_path,
               d_path->klass->vtable._3_ToString.method);
      v111 = object___get_Item(CCtrObjs, v110);
      v158.r = v102;
      v158.g = v103;
      v158.b = v104;
      v158.a = v105;
      Set2(v111, v57, v158, v100);
      if (v27 >= v145->CursorPos->ShiftMax)
        goto LABEL_116;
    }
  }
  LODWORD(v27) = 0;
LABEL_116:
    goto LABEL_120;
LABEL_117:
LABEL_120:
  while (1)
  {
    if (v27 >= LISTMAX)
      break;
    Clear(d_name, 0);
    v115 = d_name;
    LODWORD(v27) = v27 + 1;
    v151 = v27;
    v116 = sub_8D3950(s32, &v151);
    AppendFormat(v115, "rag_row{0:D2}", v116);
    v118 = ListObjs;
    v119 = (d_name->klass->vtable._3_ToString.methodPtr)(
             d_name,
             d_name->klass->vtable._3_ToString.method);
    v120 = object___get_Item(v118, v119);
    if (get_activeSelf(v120))
      SetActive(v120, 0, 0);
    _Add(MatCols, -1);
      goto LABEL_117;
  }
  v124 = object___get_Item(ListObjs, "menu_cursor");
  ismsgend = GBWK->ismsgend;
  activeSelf = get_activeSelf(v124);
  if (ismsgend)
  {
    if (!activeSelf)
      SetActive(v124, 1, 0);
    v129 = CursorInfo->CursorPos;
    UpdateItemCursor(v124, v129, -246.0, -62.0);
      goto LABEL_142;
LABEL_149:
      goto LABEL_150;
    goto LABEL_144;
  }
  if (activeSelf)
    SetActive(v124, 0, 0);
    goto LABEL_149;
LABEL_142:
    goto LABEL_149;
    goto LABEL_150;
LABEL_144:
LABEL_150:
  _ToArray(MatCols);
  v133 = CursorInfo->CursorPos;
  if (v133->EffFlag)
  {
    Shift = v133->Shift;
    CsrMoveSw = Shift;
  }
  DrawBackPanel("ragitemlist");
}

// 0x13cf720
void ragDrawExchangeRate(u8 type, u8 index) {
  UnityEngine_GameObject_o *GameObject;
  fclRagExchangeRate_t_array *ExchangeRate;
  System_Int32_c **v9;
  u64 v10;
  fclRagExchangeRate_t_o **m_Items;
  s64 v14;
  System_Text_StringBuilder_o *d_name;
  u64 v16;
  u64 *v17;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v20;
  Il2CppObject *Item;
  UnityEngine_GameObject_o *v22;
  s64 ItemID;
  bool activeSelf;
  System_String_o *v27;
  System_Text_StringBuilder_o *d_path;
  System_String_o *v31;
  System_Collections_Generic_Dictionary_object__object__o *TextObjs;
  Il2CppObject *v34;
  Il2CppObject *v35;
  System_String_o *text;
  System_Object_array *v37;
  s64 v38;
  System_Int32_c **v39;
  s64 *v40;
  s64 *v42;
  System_String_o *v44;
  System_Text_StringBuilder_o *v46;
  System_String_o *v47;
  System_Collections_Generic_Dictionary_object__object__o *CCtrObjs;
  Il2CppObject *v50;
  Il2CppObject *v51;
  System_Text_StringBuilder_o *v54;
  System_String_o *v55;
  System_Collections_Generic_Dictionary_object__object__o *v57;
  Il2CppObject *v58;
  Il2CppObject *v60;
  struct System_Byte_array *v62;
  fclRagExchangeRate_t_array *v64;
  s32 v65;
  s32 v66;

  GameObject = GetGameObject("ragjewel");
  ExchangeRate = ragGetExchangeRate(type, index);
  if (!get_activeSelf(GameObject))
    SetActive(GameObject, 1, 0);
  v9 = &s32;
  v10 = 0;
  m_Items = ExchangeRate->m_Items;
  v64 = ExchangeRate;
  do
  {
    while (1)
    {
      Clear(d_name, 0);
      v14 = *v9;
      v16 = v10 + 1;
      v66 = v10 + 1;
      v17 = sub_8D3950(v14, &v66);
      AppendFormat(d_name, "ragjewel_row{0:D2}", v17);
      v20 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      Item = object___get_Item(ListObjs, v20);
      v22 = Item;
      ItemID = m_Items[v10]->ItemID;
      activeSelf = get_activeSelf(Item);
      if (!ItemID)
        break;
      if (!activeSelf)
        SetActive(v22, 1, 0);
      v27 = Get(ItemID, 0);
      Clear(d_path, 0);
      v31 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      Append_5380272(d_path, v31);
      Append_5380272(d_path, "_name");
      v34 = (d_path->klass->vtable._3_ToString.methodPtr)(
              d_path,
              d_path->klass->vtable._3_ToString.method);
      v35 = object___get_Item(TextObjs, v34);
      set_text(v35, v27);
      text = get_text(v35);
      v37 = NewSpecific(object, 1u);
      v38 = *v9;
      v65 = 18;
      v39 = v9;
      v40 = sub_8D3950(v38, &v65);
      v42 = v40;
      v37->m_Items[0] = v42;
      v44 = RepColTag(text, v37);
      set_text(v35, v44);
      Clear(d_path, 0);
      v46 = d_path;
      v47 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      Append_5380272(v46, v47);
      Append_5380272(d_path, "_jewel");
      v50 = (d_path->klass->vtable._3_ToString.methodPtr)(
              d_path,
              d_path->klass->vtable._3_ToString.method);
      v51 = object___get_Item(CCtrObjs, v50);
      ExchangeRate = v64;
      v9 = v39;
      SetInstitutionColor(v51, m_Items[v10]->Nums, 0);
      Clear(d_path, 0);
      v54 = d_path;
      v55 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      Append_5380272(v54, v55);
      Append_5380272(d_path, "_possess");
      v57 = CCtrObjs;
      v58 = (d_path->klass->vtable._3_ToString.methodPtr)(
              d_path,
              d_path->klass->vtable._3_ToString.method);
      v60 = object___get_Item(v57, v58);
      v62 = DDS3_GBWK->item;
      SetInstitutionColor(v60, v62->m_Items[ItemID], 0);
      ++v10;
      if (v16 == 3)
        goto LABEL_43;
    }
    if (activeSelf)
      SetActive(v22, 0, 0);
    ++v10;
  }
  while (v16 != 3);
LABEL_43:
  UpdateDrawFlag("ragjewel");
}

// 0x13cfcf0
void ragDrawItemPanelParts(void) {
  Il2CppObject *Item;
  Il2CppObject *v5;

  DrawBackPanel("ragbgcolor");
  DrawBackPanel("ragbase");
  Item = object___get_Item(ListObjs, "ragsumindex_base");
  v5 = object___get_Item(ListObjs, "ragitemindex_base");
  if (!get_activeSelf(Item))
  {
    if (get_activeSelf(v5))
      return;
LABEL_13:
    SetActive(v5, 1, 0);
    return;
  }
  SetActive(Item, 0, 0);
  if (!get_activeSelf(v5))
    goto LABEL_13;
}

// 0x13cffb0
void ragDrawItemWindow(lstListWindow_t *pListWindow, u8 Type, s8 **pIdxList, s32 top, s8 Mode) {
  UnityEngine_GameObject_o *GameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_Object_o *v15;
  System_String_o *name;
  cmpCursorPos_t_o *CursorPos;
  Il2CppObject *Item;
  u64 v26;
  u64 v29;
  System_Text_StringBuilder_o *d_name;
  u64 *v31;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v34;
  Il2CppObject *v35;
  u32 v38;
  struct fclRagItem_t_array *fclRagItemTbl;
  s64 ItemID;
  System_SByte_array *v44;
  fclRagExchangeRate_t_array *ExchangeRate;
  s8 v49;
  char v50;
  System_Array_o *v51;
  s32 v54;
  System_String_o *v57;
  System_Text_StringBuilder_o *d_path;
  System_String_o *v61;
  System_Collections_Generic_Dictionary_object__object__o *TextObjs;
  Il2CppObject *v64;
  Il2CppObject *v65;
  System_Object_array *v66;
  System_Object_array *v67;
  s64 *v68;
  s64 *v70;
  System_String_o *v72;
  System_Collections_Generic_List_int__o *MatCols;
  s32 v76;
  System_Text_StringBuilder_o *v80;
  System_String_o *v81;
  System_Collections_Generic_Dictionary_object__object__o *v83;
  Il2CppObject *v84;
  Il2CppObject *v85;
  System_Text_StringBuilder_o *v89;
  u64 *v90;
  System_Collections_Generic_Dictionary_object__object__o *v92;
  Il2CppObject *v93;
  Il2CppObject *v94;
  Il2CppObject *v98;
  s32 ismsgend;
  bool activeSelf;
  cmpCursorPos_t_o *v103;
  struct cmpCursorPos_t_o *v106;
  s32 Shift;
  long f64 v109;
  long f64 v110;
  long f64 v111;
  long f64 v112;
  s32 v113;
  s8 *v116;
  struct cmpCursorInfo_t_o *pCursorInfo;
  s32 v118;
  s32 col2;
  UnityEngine_Color_o gray;
  UnityEngine_Color_o white;

  pCursorInfo = pListWindow->CursorInfo;
  col2 = 2;
  ragDrawItemPanelParts();
  GameObject = GetGameObject("ragitemlist");
  if (!get_activeSelf(GameObject))
    SetActive(GameObject, 1, 0);
  transform = get_transform(GameObject, 0);
  Find(transform, "ragitem_row", 0);
  v13 = get_transform(GameObject, 0);
  v14 = Find(v13, "ragscroll", 0);
  v15 = get_gameObject(v14);
  name = get_name(v15);
  CursorPos = pCursorInfo->CursorPos;
  DrawScrollBar(v15, name, CursorPos);
  if (ScrollDir)
  {
    Item = object___get_Item(ListObjs, "rag_row01");
    ScrollEffect(Item);
  }
  _Clear(MatCols);
  if (pCursorInfo->CursorPos->ShiftMax)
  {
    v26 = 0;
    v113 = top;
    v116 = &pIdxList->m_Items[top];
    while (1)
    {
      Clear(d_name, 0);
      v29 = v26 + 1;
      v118 = v26 + 1;
      v31 = sub_8D3950(s32, &v118);
      AppendFormat(d_name, "rag_row{0:D2}", v31);
      v34 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      v35 = object___get_Item(ListObjs, v34);
      if (!get_activeSelf(v35))
        SetActive(v35, 1, 0);
      v38 = v113 + v26;
      ItemID = fclRagItemTbl->m_Items[v116[v26]]->ItemID;
      v44 = pIdxList;
      ExchangeRate = ragGetExchangeRate(Type, v116[v26]);
      v49 = fclRagChkExchange(ExchangeRate);
      v50 = v49 == 0;
        break;
      if ((byte_3F59715 & 1) == 0)
        goto LABEL_50;
LABEL_51:
      v51 = NewSpecific(sbyte, 0x19u);
      InitializeArray_1543888(v51, Field__PrivateImplementationDetails__1611B884F9514B730E1DFD40ABEFFAC12FD56E0F);
      if ((ItemID - 64) <= 0x18u)
      {
        v54 = *(&v51[-2].klass + ItemID);
        if (v54)
        {
          v50 = (v49 == 0) | (cmbChkGetHearts(v54) != 0);
        }
      }
      if (Mode)
        v50 |= 2u;
      cmpGetCursorBlurFontCol(pCursorInfo, v38, v26, v50 & 2, 256, &col2, 0);
      v57 = Get(ItemID, 0);
      Clear(d_path, 0);
      v61 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      Append_5380272(d_path, v61);
      Append_5380272(d_path, "_name");
      v64 = (d_path->klass->vtable._3_ToString.methodPtr)(
              d_path,
              d_path->klass->vtable._3_ToString.method);
      v65 = object___get_Item(TextObjs, v64);
      v66 = NewSpecific(object, 1u);
      v118 = col2;
      v67 = v66;
      v68 = sub_8D3950(s32, &v118);
      v70 = v68;
      v67->m_Items[0] = v70;
      v72 = RepColTag(v57, v67);
      set_text(v65, v72);
      pIdxList = v44;
      if ((v50 & 1) != 0)
      {
        gray = get_gray();
        *&v109 = gray.r;
        *&v110 = gray.g;
        *&v111 = gray.b;
        *&v112 = gray.a;
      }
      else
      {
        white = get_white();
        *&v109 = white.r;
        *&v110 = white.g;
        *&v111 = white.b;
        *&v112 = white.a;
      }
      (v65->klass->vtable[23].methodPtr)(v65, v65->klass->vtable[23].v109, v110, v111, v112);
      if ((v50 & 1) != 0)
        v76 = 2;
      else
        v76 = col2;
      _Add(MatCols, v76);
      Clear(d_path, 0);
      v80 = d_path;
      v81 = (d_name->klass->vtable._3_ToString.methodPtr)(
              d_name,
              d_name->klass->vtable._3_ToString.method);
      Append_5380272(v80, v81);
      Append_5380272(d_path, "_lv");
      v83 = ListObjs;
      v84 = (d_path->klass->vtable._3_ToString.methodPtr)(
              d_path,
              d_path->klass->vtable._3_ToString.method);
      v85 = object___get_Item(v83, v84);
      if (get_activeSelf(v85))
        SetActive(v85, 0, 0);
      v26 = v29;
      if (v29 >= pCursorInfo->CursorPos->ShiftMax)
        goto LABEL_94;
    }
    if ((byte_3F59715 & 1) != 0)
      goto LABEL_51;
LABEL_50:
    goto LABEL_51;
  }
  LODWORD(v29) = 0;
LABEL_94:
    goto LABEL_99;
LABEL_97:
LABEL_99:
  while (1)
  {
    if (v29 >= LISTMAX)
      break;
    Clear(d_name, 0);
    v89 = d_name;
    LODWORD(v29) = v29 + 1;
    v118 = v29;
    v90 = sub_8D3950(s32, &v118);
    AppendFormat(v89, "rag_row{0:D2}", v90);
    v92 = ListObjs;
    v93 = (d_name->klass->vtable._3_ToString.methodPtr)(d_name, d_name->klass->vtable._3_ToString.method);
    v94 = object___get_Item(v92, v93);
    if (get_activeSelf(v94))
      SetActive(v94, 0, 0);
    _Add(MatCols, -1);
      goto LABEL_97;
  }
  v98 = object___get_Item(ListObjs, "menu_cursor");
  ismsgend = GBWK->ismsgend;
  activeSelf = get_activeSelf(v98);
  if (ismsgend)
  {
    if (!activeSelf)
      SetActive(v98, 1, 0);
    v103 = pCursorInfo->CursorPos;
    UpdateItemCursor(v98, v103, -246.0, -62.0);
      goto LABEL_127;
LABEL_125:
    goto LABEL_127;
  }
  if (activeSelf)
    SetActive(v98, 0, 0);
    goto LABEL_125;
LABEL_127:
  _ToArray(MatCols);
  v106 = pCursorInfo->CursorPos;
  if (v106->EffFlag)
  {
    Shift = v106->Shift;
    CsrMoveSw = Shift;
  }
  DrawBackPanel("ragitemlist");
}

// 0x13d22c0
void ragDrawSeqConfirm(void) {
  s32 Last;
  UnityEngine_Object_o *statusUIScr;

  Last = GBWK->SeqInfo->Last;
  if (Last == 3 || Last == 2)
  {
    statusUIScr = _statusUIScr;
    if (op_Inequality(statusUIScr, 0, 0))
    {
      ragDrawSeqStatus();
    }
  }
  else if (Last == 1)
  {
    ragDrawSeqItem(1);
  }
}

// 0x13d25c0
void ragDrawSeqErr(void) {
  UnityEngine_Object_o *statusUIScr;

  switch (GBWK->SeqInfo->Last)
  {
    case 1:
      ragDrawSeqItem(1);
      break;
    case 2:
      ragDrawSeqSeirei(1);
      break;
    case 3:
      ragDrawSeqMitama(1);
      break;
    case 7:
      statusUIScr = _statusUIScr;
      if (op_Inequality(statusUIScr, 0, 0))
      {
        ragDrawSeqStatus();
      }
      break;
    default:
      return;
  }
}

// 0x13d1900
void ragDrawSeqItem(s8 Mode) {
  struct fclDataRag_t_o *GBWK;
  cmpCursorInfo_t_o *CursorInfo;
  s32 Index;
  struct System_SByte_array *ItemList;
  s32 CursorIndex;
  s64 v11;
  s64 v13;
  struct fclRagItem_t_array *fclRagItemTbl;
  s32 ItemID;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_Collections_Generic_Dictionary_object__object__o *v18;
  System_String_o *v20;
  Il2CppObject *Item;

  CursorInfo = GBWK->ItemWindow->CursorInfo;
  Index = CursorInfo->CursorPos->Index;
  ItemList = GBWK->ItemList;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  v11 = ItemList + CursorIndex;
  v13 = *(v11 + 32);
  ItemID = fclRagItemTbl->m_Items[v13]->ItemID;
  else
  {
    v18 = *static_fields;
    if (!LODWORD((*static_fields)->entries))
      goto LABEL_19;
  }
  v20 = *&v18->count;
  Item = object___get_Item(static_fields[2], "ragtitle");
  DrawCaption2("ragtitle", v20, Item);
  ragDrawItemWindow(GBWK->ItemWindow, 0, GBWK->ItemList, Index, Mode);
  ragDrawExchangeRate(0, v13);
  DrawHelp2("raghelp", ItemID);
  Update(0);
}

// 0x13d1d20
void ragDrawSeqMitama(s8 Mode) {
  struct fclDataRag_t_o *GBWK;
  struct System_SByte_array *MitamaList;
  cmpCursorInfo_t_o *CursorInfo;
  s32 Index;
  s32 CursorIndex;
  s64 v10;
  u8 v13;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *comparer;
  Il2CppObject *Item;

  MitamaList = GBWK->MitamaList;
  CursorInfo = GBWK->MitamaWindow->CursorInfo;
  Index = CursorInfo->CursorPos->Index;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  v10 = CursorIndex;
  v13 = MitamaList->m_Items[v10];
  comparer = (*static_fields)->comparer;
  Item = object___get_Item(static_fields[2], "ragtitle");
  DrawCaption2("ragtitle", comparer, Item);
  ragDrawDevilWindow(GBWK->MitamaWindow, 2u, MitamaList, Index, Mode);
  ragDrawExchangeRate(2u, v13);
  Update(0);
}

// 0x13d2420
void ragDrawSeqRoot(s32 Mode) {
  struct System_SByte_array *gFclSignal;
  s32 v4;
  cmpCursorInfo_t_o *CursorInfo;

  if (!Mode)
  {
    v4 = 1;
    goto LABEL_23;
  }
  if (!LODWORD(gFclSignal->max_length))
    goto LABEL_16;
LABEL_12:
  if (gFclSignal->m_Items[0])
  {
    v4 = 0;
  }
  else
  {
    if (GBWK->SeqInfo->Last == 4)
      v4 = 1;
    else
      v4 = 2;
  }
LABEL_23:
  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  DrawCommandSelectMenu(CursorInfo, 0, v4);
  Update(0);
}

// 0x13d1b50
void ragDrawSeqSeirei(s8 Mode) {
  struct fclDataRag_t_o *GBWK;
  struct System_SByte_array *SeireiList;
  cmpCursorInfo_t_o *CursorInfo;
  s32 Index;
  s32 CursorIndex;
  s64 v10;
  u8 v13;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *v16;
  Il2CppObject *Item;

  SeireiList = GBWK->SeireiList;
  CursorInfo = GBWK->SeireiWindow->CursorInfo;
  Index = CursorInfo->CursorPos->Index;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  v10 = CursorIndex;
  v13 = SeireiList->m_Items[v10];
  v16 = *&(*static_fields)->freeList;
  Item = object___get_Item(static_fields[2], "ragtitle");
  DrawCaption2("ragtitle", v16, Item);
  ragDrawDevilWindow(GBWK->SeireiWindow, 1u, SeireiList, Index, Mode);
  ragDrawExchangeRate(1u, v13);
  Update(0);
}

// 0x13d1ef0
void ragDrawSeqStatus(void) {
  System_SByte_array *v1;
  datUnitWork_t_o *v2;
  datUnitWork_t_o *v3;
  fclSprite_t_o *SpriteBG;
  s32 v9;
  s32 v11;
  s32 Z;
  u16 id;
  u16 maxhp;
  u64 v17;
  s8 *m_Items;
  char Param;
  struct System_SByte_array *v20;
  struct System_SByte_array *v23;
  char *v25;
  s8 v27;

  v1 = NewSpecific(sbyte, 6u);
  v2 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v2);
  v3 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v3);
  cmpModelInitCore();
  SpriteBG = GBWK->SpriteBG;
  fclDrawBG(SpriteBG, 7u);
  v9 = CMP_XM(0);
  v11 = CMP_YM(51);
  Z = GBWK->SpriteBG->Z;
  cmpDrawBoxF(v9, v11, Z, 512, 360, 0x33u, 7u);
  id = GBWK->Devil->id;
  cmbCopyDefaultDevilToStock(id, v3);
  cmbCopyCustomDevilToStock(v2, GBWK->Devil);
  maxhp = v2->maxhp;
  v2->mp = v2->maxmp;
  v2->hp = maxhp;
  v17 = 0;
  m_Items = v1->m_Items;
  do
  {
    Param = datGetParam(v2, v17);
    v20 = v3->param;
    m_Items[v17] = Param - v20->m_Items[v17];
    v23 = v2->param;
    v25 = v23 + v17;
    v27 = m_Items[v17++];
    v25[32] -= v27;
  }
  while (v17 != 6);
  cmpStatSetCompareUnit(v3);
  cmpDrawStatusComEx(v2, 0x80u, 255, 2, v1, 0, 0xA09DC380, 3, 2, 2);
  cmpStatSetCompareUnit(0);
  Update(0);
}
