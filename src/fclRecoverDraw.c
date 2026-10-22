#include "types.h"

typedef struct CounterCtr CounterCtr;
typedef struct RippleEffect RippleEffect;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;

static char *gRecoverCaptionStr[5];
static void *ListObjs;
static void *TextObjs;
static void *CCtrObjs;
static void *BImgObjs;
static void *AnimObjs;
static s32 ChildCount;
static void *MatCols;
static s32 CsrMoveSw;

void DrawBackPanel(char *name);
void DrawCaption2(char *name, char *caption, void *txt);
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style);
void DrawPayMoney(char *name, CounterCtr *ctr, u32 col, s32 val);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
void DrawTotalMoney(char *name, CounterCtr *ctr);
u8 Get(s32 id);
void *GetGameObject(char *name);
char *RepColTag(char *txt, void **LegacyParamArray);
void ScrollEffect(void *obj);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void Update(RippleEffect *this);
void UpdateDrawFlag(char *name);
void UpdateItemCursor(void *csrobj, cmpCursorPos_t *csr, f32 y, f32 ofsy);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkSignal(s8 Idx);
char *frGetCNameString(s8 TargetNo);
void lstDrawListWindowCursor(lstListWindow_t *pListWindow, u32 OtNo);
void rcvDrawPayMoney(u32 Color, s32 Val);
void rcvDrawSeqAllRecover(void);
void rcvDrawSeqRecover(void);
void rcvDrawSeqRoot(s32 Mode);
void rcvDrawStockWindow(lstListWindow_t *window, s8 mode);
void rcvDrawStockWindowList(void *obj, u32 Col, s8 localstockidx, bool curidx);

// 0x19911b0
void DispInsfee(s32 sw) {
  Il2CppObject *Item;

  Item = object___get_Item(AnimObjs, "rcvfee");
  SetInteger(Item, "insfee", sw);
}

// 0x19910c0
void FinalizeGameObject(void) {
  PropertySheet___Clear(AnimObjs);
  PropertySheet___Clear(BImgObjs);
  PropertySheet___Clear(CCtrObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(ListObjs);
}

// 0x198ffd0
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
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *ListObjs;
  UnityEngine_Transform_o *v18;
  UnityEngine_Component_o *v19;
  UnityEngine_GameObject_o *v20;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v21;
  UnityEngine_Transform_o *v22;
  UnityEngine_Component_o *v23;
  UnityEngine_GameObject_o *v24;
  u32 v26;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *AnimObjs;
  System_String_o *v28;
  System_Collections_Generic_Dictionary_object__object__o *v29;
  UnityEngine_Shader_o *v30;
  Il2CppObject *v31;
  Il2CppObject *v32;
  Il2CppObject *v33;
  struct System_Collections_Generic_Dictionary_string__Animator__o *v34;
  System_String_o *v35;
  System_Collections_Generic_Dictionary_object__object__o *v36;
  UnityEngine_Shader_o *v37;
  Il2CppObject *v38;
  Il2CppObject *v39;
  Il2CppObject *v40;
  System_WeakReference_o *v42;
  UnityEngine_Transform_o *v43;
  System_WeakReference_o *v44;
  System_String_o *name;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v48;
  System_WeakReference_o *v49;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v50;
  System_String_o *v51;
  UnityEngine_Component_o *v52;
  UnityEngine_GameObject_o *v53;
  System_Collections_Generic_Dictionary_object__object__o *v54;
  Il2CppObject *v55;
  Il2CppObject *v56;
  Il2CppObject *Component_object;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *TextObjs;
  System_String_o *v62;
  System_Collections_Generic_Dictionary_object__object__o *v63;
  UnityEngine_Shader_o *v64;
  Il2CppObject *v65;
  Il2CppObject *v66;
  Il2CppObject *v67;
  System_Collections_Generic_Dictionary_object__object__o *v68;
  Il2CppObject *v69;
  Il2CppObject *v70;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v71;
  System_String_o *v72;
  UnityEngine_Component_o *v73;
  UnityEngine_GameObject_o *v74;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v75;
  System_String_o *v76;
  UnityEngine_Component_o *v77;
  UnityEngine_GameObject_o *v78;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v79;
  System_String_o *v80;
  UnityEngine_Component_o *v81;
  UnityEngine_GameObject_o *v82;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *CCtrObjs;
  System_String_o *v84;
  System_Collections_Generic_Dictionary_object__object__o *v85;
  UnityEngine_Shader_o *v86;
  Il2CppObject *v87;
  Il2CppObject *v88;
  Il2CppObject *v89;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v90;
  System_String_o *v91;
  System_Collections_Generic_Dictionary_object__object__o *v92;
  UnityEngine_Shader_o *v93;
  Il2CppObject *v94;
  Il2CppObject *v95;
  Il2CppObject *v96;
  struct System_Collections_Generic_Dictionary_string__Image__o *BImgObjs;
  System_String_o *v98;
  System_Collections_Generic_Dictionary_object__object__o *v99;
  UnityEngine_Shader_o *v100;
  Il2CppObject *v101;
  Il2CppObject *v102;
  Il2CppObject *v103;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v104;
  System_String_o *v105;
  UnityEngine_Component_o *v106;
  UnityEngine_GameObject_o *v107;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v108;
  System_String_o *v109;
  UnityEngine_Component_o *v110;
  UnityEngine_GameObject_o *v111;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v112;
  System_String_o *v113;
  UnityEngine_Component_o *v114;
  UnityEngine_GameObject_o *v115;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v116;
  System_String_o *v117;
  UnityEngine_Component_o *v118;
  UnityEngine_GameObject_o *v119;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v120;
  System_String_o *v121;
  System_Collections_Generic_Dictionary_object__object__o *v122;
  UnityEngine_Shader_o *v123;
  Il2CppObject *v124;
  Il2CppObject *v125;
  Il2CppObject *v126;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v127;
  System_String_o *v128;
  System_Collections_Generic_Dictionary_object__object__o *v129;
  UnityEngine_Shader_o *v130;
  Il2CppObject *v131;
  Il2CppObject *v132;
  Il2CppObject *v133;
  struct System_Collections_Generic_Dictionary_string__Image__o *v134;
  System_String_o *v135;
  System_Collections_Generic_Dictionary_object__object__o *v136;
  UnityEngine_Shader_o *v137;
  Il2CppObject *v138;
  Il2CppObject *v139;
  Il2CppObject *v140;
  struct System_Collections_Generic_Dictionary_string__Image__o *v141;
  System_String_o *v142;
  System_Collections_Generic_Dictionary_object__object__o *v143;
  UnityEngine_Shader_o *v144;
  Il2CppObject *v145;
  Il2CppObject *v146;
  Il2CppObject *v147;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v148;
  System_String_o *v149;
  UnityEngine_Component_o *v150;
  UnityEngine_GameObject_o *v151;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v152;
  System_String_o *v153;
  UnityEngine_Component_o *v154;
  UnityEngine_GameObject_o *v155;
  System_Collections_Generic_Dictionary_object__object__o *v156;
  Il2CppObject *v157;
  Il2CppObject *v158;
  UnityEngine_Transform_o *v159;
  s32 childCount;
  s32 v164;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v165;
  u64 *v166;
  System_String_o *v167;
  System_String_o *v168;
  UnityEngine_Component_o *v169;
  UnityEngine_GameObject_o *v170;
  s32 v171;
  UnityEngine_GameObject_o *v173;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v176;
  Il2CppObject *v177;
  struct System_Collections_Generic_Dictionary_string__CounterCtr__o *v178;
  UnityEngine_Transform_o *v179;
  UnityEngine_Component_o *v180;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_GameObject_o *v183;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v185;
  UnityEngine_Transform_o *v186;
  UnityEngine_Component_o *v187;
  UnityEngine_GUILayer_o *v188;
  UnityEngine_GameObject_o *v189;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v190;
  UnityEngine_Transform_o *v191;
  UnityEngine_Component_o *v192;
  UnityEngine_GUILayer_o *v193;
  u64 *v194;
  s32 v195;
  UnityEngine_Color_o white;

  GameObject = GetGameObject("rcvlist");
  transform = get_transform(GameObject, 0);
  v4 = Find(transform, "rcv_row", 0);
  v5 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v5);
  PropertySheet___Clear(ListObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(CCtrObjs);
  PropertySheet___Clear(BImgObjs);
  PropertySheet___Clear(AnimObjs);
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
  ChildCount = Count;
  v18 = get_transform(GameObject, 0);
  v19 = Find(v18, "menu_cursur", 0);
  v20 = get_gameObject(v19);
  PropertySheet___Add(ListObjs, "menu_cursor", v20);
  v21 = ListObjs;
  v22 = get_transform(GameObject, 0);
  v23 = Find(v22, "rcvscroll", 0);
  v24 = get_gameObject(v23);
  PropertySheet___Add(v21, "rcvscroll", v24);
  v26 = 0;
  v194 = v5;
  while (1)
  {
    if (v26 >= LISTMAX)
      break;
    v42 = _get_Item(
            v5,
            v26);
    v43 = get_transform(v42, 0);
    v44 = _get_Item(
            v5,
            v26);
    name = get_name(v44);
    v48 = ListObjs;
    v49 = _get_Item(
            v5,
            v26);
    PropertySheet___Add(v48, name, v49);
    v50 = ListObjs;
    v51 = Concat_5224608(name, "_name");
    v52 = Find(v43, "Text_nameTM", 0);
    v53 = get_gameObject(v52);
    PropertySheet___Add(v50, v51, v53);
    v54 = ListObjs;
    v55 = Concat_5224608(name, "_name");
    v56 = object___get_Item(v54, v55);
    Component_object = GetComponent_object_(v56);
    if (op_Inequality(Component_object, 0, 0))
      set_enabled(Component_object, 0);
    v62 = Concat_5224608(name, "_name");
    v63 = ListObjs;
    v64 = v62;
    v65 = Concat_5224608(name, "_name");
    v66 = object___get_Item(v63, v65);
    v67 = GetComponent_object_(v66);
    PropertySheet___Add(TextObjs, v64, v67);
    v68 = TextObjs;
    v69 = Concat_5224608(name, "_name");
    v70 = object___get_Item(v68, v69);
    white = get_white();
    (v70->klass->vtable[23].methodPtr)(
      v70,
      v70->klass->vtable[23].white.r,
      white.g,
      white.b,
      white.a);
    v71 = ListObjs;
    v72 = Concat_5224608(name, "_hp");
    v73 = Find(v43, "rcvhpbar/rcvhpnum_current", 0);
    v74 = get_gameObject(v73);
    PropertySheet___Add(v71, v72, v74);
    v75 = ListObjs;
    v76 = Concat_5224608(name, "_mhp");
    v77 = Find(v43, "rcvhpbar/rcvhpnum_full", 0);
    v78 = get_gameObject(v77);
    PropertySheet___Add(v75, v76, v78);
    v79 = ListObjs;
    v80 = Concat_5224608(name, "_hpbar");
    v81 = Find(v43, "rcvhpbar/rcvhpbar_color", 0);
    v82 = get_gameObject(v81);
    PropertySheet___Add(v79, v80, v82);
    v84 = Concat_5224608(name, "_hp");
    v85 = ListObjs;
    v86 = v84;
    v87 = Concat_5224608(name, "_hp");
    v88 = object___get_Item(v85, v87);
    v89 = GetComponent_object_(v88);
    PropertySheet___Add(CCtrObjs, v86, v89);
    v90 = CCtrObjs;
    v91 = Concat_5224608(name, "_mhp");
    v92 = ListObjs;
    v93 = v91;
    v94 = Concat_5224608(name, "_mhp");
    v95 = object___get_Item(v92, v94);
    v96 = GetComponent_object_(v95);
    PropertySheet___Add(v90, v93, v96);
    v98 = Concat_5224608(name, "_hpbar");
    v99 = ListObjs;
    v100 = v98;
    v101 = Concat_5224608(name, "_hpbar");
    v102 = object___get_Item(v99, v101);
    v103 = GetComponent_object_(v102);
    PropertySheet___Add(BImgObjs, v100, v103);
    v104 = ListObjs;
    v105 = Concat_5224608(name, "_mp");
    v106 = Find(v43, "rcvmpbar/rcvmpnum_current", 0);
    v107 = get_gameObject(v106);
    PropertySheet___Add(v104, v105, v107);
    v108 = ListObjs;
    v109 = Concat_5224608(name, "_mmp");
    v110 = Find(v43, "rcvmpbar/rcvmpnum_full", 0);
    v111 = get_gameObject(v110);
    PropertySheet___Add(v108, v109, v111);
    v112 = ListObjs;
    v113 = Concat_5224608(name, "_mpbar");
    v114 = Find(v43, "rcvmpbar/rcvmpbar_color", 0);
    v115 = get_gameObject(v114);
    PropertySheet___Add(v112, v113, v115);
    v116 = ListObjs;
    v117 = Concat_5224608(name, "_mpbar_d");
    v118 = Find(v43, "rcvmpbar/rcvmpbar_grey", 0);
    v119 = get_gameObject(v118);
    PropertySheet___Add(v116, v117, v119);
    v120 = CCtrObjs;
    v121 = Concat_5224608(name, "_mp");
    v122 = ListObjs;
    v123 = v121;
    v124 = Concat_5224608(name, "_mp");
    v125 = object___get_Item(v122, v124);
    v126 = GetComponent_object_(v125);
    PropertySheet___Add(v120, v123, v126);
    v127 = CCtrObjs;
    v128 = Concat_5224608(name, "_mmp");
    v129 = ListObjs;
    v130 = v128;
    v131 = Concat_5224608(name, "_mmp");
    v132 = object___get_Item(v129, v131);
    v133 = GetComponent_object_(v132);
    PropertySheet___Add(v127, v130, v133);
    v134 = BImgObjs;
    v135 = Concat_5224608(name, "_mpbar");
    v136 = ListObjs;
    v137 = v135;
    v138 = Concat_5224608(name, "_mpbar");
    v139 = object___get_Item(v136, v138);
    v140 = GetComponent_object_(v139);
    PropertySheet___Add(v134, v137, v140);
    v141 = BImgObjs;
    v142 = Concat_5224608(name, "_mpbar_d");
    v143 = ListObjs;
    v144 = v142;
    v145 = Concat_5224608(name, "_mpbar_d");
    v146 = object___get_Item(v143, v145);
    v147 = GetComponent_object_(v146);
    PropertySheet___Add(v141, v144, v147);
    v148 = ListObjs;
    v149 = Concat_5224608(name, "_steff");
    v150 = Find(v43, "steff", 0);
    v151 = get_gameObject(v150);
    PropertySheet___Add(v148, v149, v151);
    v152 = ListObjs;
    v153 = Concat_5224608(name, "_rcvstatus");
    v154 = Find(v43, "rcvstatus", 0);
    v155 = get_gameObject(v154);
    PropertySheet___Add(v152, v153, v155);
    v156 = ListObjs;
    v157 = Concat_5224608(name, "_steff");
    v158 = object___get_Item(v156, v157);
    v159 = get_transform(v158, 0);
    childCount = get_childCount(v159);
    if (childCount >= 1)
    {
      v164 = 0;
      do
      {
        v165 = ListObjs;
        v195 = v164;
        v166 = sub_8D3950(s32, &v195);
        v167 = Format("_steff_{0:D2}", v166, 0);
        v168 = Concat_5224608(name, v167);
        v169 = GetChild(v159, v164);
        v170 = get_gameObject(v169);
        PropertySheet___Add(v165, v168, v170);
        ++v164;
        v171 = get_childCount(v159);
      }
      while (v164 < v171);
    }
    v28 = Concat_5224608(name, "_steff");
    v29 = ListObjs;
    v30 = v28;
    v31 = Concat_5224608(name, "_steff");
    v32 = object___get_Item(v29, v31);
    v33 = GetComponent_object_(v32);
    PropertySheet___Add(AnimObjs, v30, v33);
    v34 = AnimObjs;
    v35 = Concat_5224608(name, "_rcvstatus");
    v36 = ListObjs;
    v37 = v35;
    v38 = Concat_5224608(name, "_rcvstatus");
    v39 = object___get_Item(v36, v38);
    v40 = GetComponent_object_(v39);
    PropertySheet___Add(v34, v37, v40);
    v5 = v194;
    ++v26;
  }
  v173 = GetGameObject("rcvfee");
  if (op_Inequality(v173, 0, 0))
  {
    v176 = AnimObjs;
    v177 = GetComponent_object_(v173);
    PropertySheet___Add(v176, "rcvfee", v177);
    v178 = CCtrObjs;
    v179 = get_transform(v173, 0);
    v180 = Find(v179, "insfee/num_money", 0);
    Component_GUILayer = GetComponent_GUILayer_(v180);
    PropertySheet___Add(v178, "rcvfee", Component_GUILayer);
  }
  v183 = GetGameObject("rcvmoney");
  v185 = CCtrObjs;
  v186 = get_transform(v183, 0);
  v187 = Find(v186, "num_money", 0);
  v188 = GetComponent_GUILayer_(v187);
  PropertySheet___Add(v185, "num_money", v188);
  v189 = GetGameObject("rcvtitle");
  v190 = TextObjs;
  v191 = get_transform(v189, 0);
  v192 = Find(v191, "Text_rcvtitleTM", 0);
  v193 = GetComponent_GUILayer_(v192);
  PropertySheet___Add(v190, "rcvtitle", v193);
}

// 0x1992850
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

// 0x19931c0
dds3ProcessFunc_t *rcvDraw(dds3ProcessID_t *PID) {
  u64 *v2;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  s16 v13;
  s32 v14;
  struct fclDataRecover_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  struct fclDataRecover_t_o *v21;
  s32 v22;
  struct System_Int32_array *Price;
  s32 v25;
  u32 v26;
  struct cmpSeqInfo_t_o *v28;
  dds3ProcessID_t_o *v32;
  u64 v33[3];

  v32 = PID;
  v2 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v2);
  ProcessData = dds3GetProcessData(&v32);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataRecover_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataRecover_t, v33);
    if ((v33[0] & 1) != 0)
      v9 = v33[2];
    else
      v9 = v33 + 1;
    v10 = sub_8C4940(v9);
  }
LABEL_15:
  GBWK = ProcessData;
  if (fclChkSignal(1))
  {
    if ((v13 & 0x200) != 0)
    {
      v14 = v13 & 0x200;
    }
    else
    {
      v14 = 0;
    }
    SeqInfo = GBWK->SeqInfo;
    if ((SeqInfo->Flag & 0x20) != 0)
    {
      cmpUpdateTerminate(SeqInfo);
      v32->func_ans = -1;
    }
    else
    {
      CursorInfo = GBWK->StockWindow->CursorInfo;
      CursorIndex = cmpGetCursorIndex(CursorInfo);
      v21 = GBWK;
      if (v21->SeqInfo->Current == 5)
        v22 = 0;
      else
        v22 = CursorIndex;
      Price = v21->Price;
      v25 = Price->m_Items[v22];
      rcvDrawPayMoney(v26, v25);
      v28 = GBWK->SeqInfo;
      if ((v28->Flag & 2) != 0)
      {
        switch (v28->Current)
        {
          case 0:
            rcvDrawSeqRoot(1);
            break;
          case 1:
            rcvDrawSeqAllRecover();
            break;
          case 2:
            rcvDrawSeqRecover();
            break;
          default:
            return 0;
        }
      }
    }
  }
  return 0;
}

// 0x1991250
void rcvDrawPayMoney(u32 Color, s32 Val) {
  Il2CppObject *Item;

  Item = object___get_Item(CCtrObjs, "rcvfee");
  DrawPayMoney("rcvfee", Item, 0xFFFFFFFF, Val);
}

// 0x19928d0
void rcvDrawSeqAllRecover(void) {
  u64 *v1;
  bool v3;
  s8 v7;
  lstListWindow_t_o *StockWindow;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *v11;
  Il2CppObject *Item;

  v1 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v1);
  v3 = fclChkSignal(0) == 0;
  v7 = v3;
  StockWindow = GBWK->StockWindow;
  rcvDrawStockWindow(StockWindow, v7);
  v11 = *&(*static_fields)->count;
  Item = object___get_Item(static_fields[2], "rcvtitle");
  DrawCaption2("rcvtitle", v11, Item);
  Update(0);
}

// 0x1992ec0
void rcvDrawSeqDispel(void) {
  u64 *v1;
  Il2CppObject *Item;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *values;
  Il2CppObject *v9;

  v1 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v1);
  Item = object___get_Item(CCtrObjs, "num_money");
  DrawTotalMoney("rcvmoney", Item);
  values = (*static_fields)->values;
  v9 = object___get_Item(static_fields[2], "rcvtitle");
  DrawCaption2("rcvtitle", values, v9);
  Update(0);
}

// 0x1992a50
void rcvDrawSeqRecover(void) {
  u64 *v1;
  bool v3;
  s8 v7;
  lstListWindow_t_o *StockWindow;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *v11;
  Il2CppObject *Item;

  v1 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v1);
  v3 = fclChkSignal(0) == 0;
  v7 = v3;
  StockWindow = GBWK->StockWindow;
  rcvDrawStockWindow(StockWindow, v7);
  v11 = *&(*static_fields)->freeList;
  Item = object___get_Item(static_fields[2], "rcvtitle");
  DrawCaption2("rcvtitle", v11, Item);
  Update(0);
}

// 0x1992d50
void rcvDrawSeqRevive(void) {
  bool v2;
  s8 v6;
  lstListWindow_t_o *StockWindow;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *keys;
  Il2CppObject *Item;

  v2 = fclChkSignal(0) == 0;
  v6 = v2;
  StockWindow = GBWK->StockWindow;
  rcvDrawStockWindow(StockWindow, v6);
  keys = (*static_fields)->keys;
  Item = object___get_Item(static_fields[2], "rcvtitle");
  DrawCaption2("rcvtitle", keys, Item);
  Update(0);
}

// 0x1993010
void rcvDrawSeqRoot(s32 Mode) {
  u64 *v3;
  s32 v5;
  Il2CppObject *Item;

  v3 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v3);
  if (Mode)
  {
    v5 = 0;
    if (!fclChkSignal(0))
    {
      if (GBWK->SeqInfo->Last == 6)
        v5 = 1;
      else
        v5 = 2;
    }
  }
  else
  {
    v5 = 1;
  }
  Item = object___get_Item(CCtrObjs, "num_money");
  DrawTotalMoney("rcvmoney", Item);
  DrawCommandSelectMenu(GBWK->CmdSelInfo->CursorInfo, 0, v5);
  Update(0);
}

// 0x1992bd0
void rcvDrawSeqStatusRecover(void) {
  u64 *v1;
  bool v3;
  s8 v7;
  lstListWindow_t_o *StockWindow;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *comparer;
  Il2CppObject *Item;

  v1 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v1);
  v3 = fclChkSignal(0) == 0;
  v7 = v3;
  StockWindow = GBWK->StockWindow;
  rcvDrawStockWindow(StockWindow, v7);
  comparer = (*static_fields)->comparer;
  Item = object___get_Item(static_fields[2], "rcvtitle");
  DrawCaption2("rcvtitle", comparer, Item);
  Update(0);
}

// 0x1992000
void rcvDrawStockWindow(lstListWindow_t *window, s8 mode) {
  u64 *v4;
  struct cmpCursorInfo_t_o *CursorInfo;
  UnityEngine_GameObject_o *GameObject;
  UnityEngine_Transform_o *transform;
  Il2CppObject *Item;
  System_String_o *name;
  cmpCursorPos_t_o *CursorPos;
  u32 v16;
  u64 v17;
  Il2CppObject *v21;
  u64 v24;
  u64 v26;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  u64 *v28;
  Il2CppObject *v29;
  Il2CppObject *v31;
  s32 Index;
  struct System_Int32_array *Price;
  s32 v36;
  s32 v38;
  u32 v39;
  struct cmpCursorPos_t_o *v44;
  s32 v45;
  s8 v46;
  bool v48;
  s16 v51;
  s32 v52;
  System_Collections_Generic_Dictionary_object__object__o *v54;
  u64 *v55;
  Il2CppObject *v56;
  Il2CppObject *v57;
  Il2CppObject *v61;
  s32 ismsgend;
  bool activeSelf;
  cmpCursorPos_t_o *v66;
  struct cmpCursorPos_t_o *v70;
  s32 Shift;
  Il2CppObject *v74;
  lstListWindow_t_o *pListWindow;
  struct cmpCursorPos_t_o *v78;
  s32 v80;
  s32 v81;
  s32 col2;

  v4 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v4);
  pListWindow = window;
  CursorInfo = window->CursorInfo;
  col2 = 2;
  DrawBackPanel("rcvbgcolor");
  GameObject = GetGameObject("rcvlist");
  if (!get_activeSelf(GameObject))
    SetActive(GameObject, 1, 0);
  transform = get_transform(GameObject, 0);
  Find(transform, "rcv_row", 0);
  Item = object___get_Item(ListObjs, "rcvscroll");
  name = get_name(Item);
  CursorPos = CursorInfo->CursorPos;
  DrawScrollBar(Item, name, CursorPos);
  v17 = CursorInfo->CursorPos;
  v16 = *(v17 + 16);
  LODWORD(v17) = *(v17 + 22);
  if (v16 <= v17)
    v17 = v16;
  else
  v78 = v17;
  if (ScrollDir)
  {
    v21 = object___get_Item(ListObjs, "rcv_row01");
    ScrollEffect(v21);
  }
  _Clear(MatCols);
  if (v78)
  {
    v24 = 0;
    while (1)
    {
      v26 = v24;
      ++v24;
      v81 = v26 + 1;
      v28 = sub_8D3950(s32, &v81);
      v29 = Format("rcv_row{0:D2}", v28, 0);
      v31 = object___get_Item(ListObjs, v29);
      Index = CursorInfo->CursorPos->Index;
      Price = GBWK->Price;
      v36 = Price->m_Items[v26];
      v38 = v26 + Index;
      if (mode)
        v39 = (v36 > DDS3_GBWK->maka) | 2;
      else
        v39 = v36 > DDS3_GBWK->maka;
      cmpGetCursorBlurFontCol(CursorInfo, v26, v26, v39, 256, &col2, 0);
      _Add(MatCols, col2);
      v44 = CursorInfo->CursorPos;
      v45 = col2;
      v46 = v26 + v44->Index;
      if (v38 == v44->Shift)
        break;
      v48 = 0;
        goto LABEL_58;
LABEL_61:
      rcvDrawStockWindowList(v31, v45, v46, v48);
      if (v24 >= v78)
        goto LABEL_64;
    }
    v48 = GBWK->ismsgend != 0;
      goto LABEL_61;
LABEL_58:
    goto LABEL_61;
  }
  LODWORD(v24) = 0;
LABEL_64:
  if ((v51 & 0x200) != 0)
    goto LABEL_76;
  while (1)
  {
    v52 = 0;
    if (v24 >= ChildCount)
      break;
    while (1)
    {
      v54 = ListObjs;
      LODWORD(v24) = v24 + 1;
      v80 = v24;
      v55 = sub_8D3950(s32, &v80);
      v56 = Format("rcv_row{0:D2}", v55, 0);
      v57 = object___get_Item(v54, v56);
      if (get_activeSelf(v57))
        SetActive(v57, 0, 0);
      _Add(MatCols, -1);
      if ((v51 & 0x200) == 0)
        break;
LABEL_76:
      v52 = v51 & 0x200;
      if (v24 >= ChildCount)
        goto LABEL_79;
    }
  }
LABEL_79:
  v61 = object___get_Item(ListObjs, "menu_cursor");
  ismsgend = GBWK->ismsgend;
  activeSelf = get_activeSelf(v61);
  if (ismsgend)
  {
    if (!activeSelf)
      SetActive(v61, 1, 0);
    v66 = CursorInfo->CursorPos;
    UpdateItemCursor(v61, v66, -326.0, -62.0);
      goto LABEL_97;
  }
  else
  {
    if (activeSelf)
      SetActive(v61, 0, 0);
      goto LABEL_97;
  }
LABEL_97:
    goto LABEL_101;
LABEL_98:
LABEL_101:
  _ToArray(MatCols);
  v70 = CursorInfo->CursorPos;
  if (v70->EffFlag)
  {
    Shift = v70->Shift;
    CsrMoveSw = Shift;
  }
  else
  {
  }
  v74 = object___get_Item(CCtrObjs, "num_money");
  DrawTotalMoney("rcvmoney", v74);
  if (mode)
  {
      goto LABEL_117;
  }
  else
  {
    lstDrawListWindowCursor(pListWindow, 0);
      goto LABEL_117;
  }
LABEL_117:
  UpdateDrawFlag("rcvlist");
}

// 0x1991320
void rcvDrawStockWindowList(void *obj, u32 Col, s8 localstockidx, bool curidx) {
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct datUnitWork_t_array *unitwork;
  struct System_SByte_array *StockIdx;
  datUnitWork_t_o *v17;
  s32 id;
  System_String_o *CNameString;
  System_String_o *v20;
  System_String_o *name;
  long f64 v22;
  long f64 v23;
  long f64 v24;
  long f64 v25;
  Il2CppObject *v27;
  s32 badstatus;
  Il2CppObject *Item;
  System_Object_array *v31;
  s64 *v32;
  s64 *v34;
  System_String_o *v36;
  Il2CppObject *v39;
  s32 v40;
  System_Collections_Generic_Dictionary_object__object__o *CCtrObjs;
  Il2CppObject *v44;
  Il2CppObject *v45;
  System_Collections_Generic_Dictionary_object__object__o *v46;
  Il2CppObject *v47;
  Il2CppObject *v48;
  u32 v50;
  u32 v51;
  f32 v53;
  f32 v56;
  System_Collections_Generic_Dictionary_object__object__o *BImgObjs;
  Il2CppObject *v58;
  Il2CppObject *v59;
  System_Collections_Generic_Dictionary_object__object__o *v60;
  Il2CppObject *v61;
  Il2CppObject *v62;
  System_Collections_Generic_Dictionary_object__object__o *v63;
  Il2CppObject *v64;
  Il2CppObject *v65;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v67;
  Il2CppObject *v68;
  System_Collections_Generic_Dictionary_object__object__o *v71;
  Il2CppObject *v72;
  Il2CppObject *v73;
  System_Collections_Generic_Dictionary_object__object__o *v75;
  Il2CppObject *v76;
  Il2CppObject *v77;
  u32 v79;
  u32 v80;
  System_Collections_Generic_Dictionary_object__object__o *v82;
  Il2CppObject *v83;
  Il2CppObject *v84;
  f32 v86;
  f32 v89;
  System_Collections_Generic_Dictionary_object__object__o *v90;
  Il2CppObject *v91;
  Il2CppObject *v92;
  System_Collections_Generic_Dictionary_object__object__o *v93;
  Il2CppObject *v94;
  Il2CppObject *v95;
  UnityEngine_Transform_o *transform;
  s32 childCount;
  s32 v101;
  System_Collections_Generic_Dictionary_object__object__o *v102;
  u64 *v103;
  System_String_o *v104;
  Il2CppObject *v105;
  Il2CppObject *v106;
  s32 v107;
  System_Collections_Generic_Dictionary_object__object__o *AnimObjs;
  Il2CppObject *v109;
  Il2CppObject *v111;
  u32 v112;
  u32 v113;
  s32 v114;
  System_Collections_Generic_Dictionary_object__object__o *v118;
  Il2CppObject *v119;
  Il2CppObject *v121;
  s32 v122;
  System_Collections_Generic_Dictionary_object__object__o *v125;
  Il2CppObject *v126;
  Il2CppObject *v127;
  System_Collections_Generic_Dictionary_object__object__o *v130;
  Il2CppObject *v131;
  Il2CppObject *v132;
  System_Collections_Generic_Dictionary_object__object__o *v134;
  Il2CppObject *v135;
  Il2CppObject *v136;
  u32 v138;
  u32 v139;
  System_Collections_Generic_Dictionary_object__object__o *v141;
  Il2CppObject *v142;
  Il2CppObject *v143;
  f32 v145;
  f32 v148;
  System_Collections_Generic_Dictionary_object__object__o *v149;
  Il2CppObject *v150;
  Il2CppObject *v151;
  long f64 v152;
  long f64 v153;
  long f64 v154;
  long f64 v155;
  s32 v156;
  _BOOL4 v157;
  UnityEngine_Color_o gray;
  UnityEngine_Color_o white;
  UnityEngine_Color_o v160;

  get_transform(obj, 0);
  if (!get_activeSelf(obj))
    SetActive(obj, 1, 0);
  unitwork = DDS3_GBWK->unitwork;
  StockIdx = GBWK->LocalStock->StockIdx;
  v17 = unitwork->m_Items[StockIdx->m_Items[localstockidx]];
  if ((v17->flag & 4) != 0)
  {
    CNameString = frGetCNameString(0);
  }
  else
  {
    id = v17->id;
    CNameString = Get(id, 0);
  }
  v20 = CNameString;
  name = get_name(obj);
  if (Col == 2)
  {
    gray = get_gray();
    *&v152 = gray.r;
    *&v153 = gray.g;
    *&v154 = gray.b;
    *&v155 = gray.a;
  }
  else
  {
    white = get_white();
    *&v152 = white.r;
    *&v153 = white.g;
    *&v154 = white.b;
    *&v155 = white.a;
  }
  v22 = v152;
  v23 = v153;
  v24 = v154;
  v25 = v155;
  v27 = Concat_5224608(name, "_name");
  badstatus = v17->badstatus;
  Item = object___get_Item(TextObjs, v27);
  v157 = curidx;
  v31 = NewSpecific(object, 1u);
  v32 = sub_8D3950(UI_COL, &v157);
  v34 = v32;
  v31->m_Items[0] = v34;
  v36 = RepColTag(v20, v31);
  set_text(Item, v36);
  v39 = object___get_Item(TextObjs, v27);
  (v39->klass->vtable[23].methodPtr)(v39, v39->klass->vtable[23].v22, v23, v24, v25);
  if (badstatus == 2048)
    v40 = 3;
  else
    v40 = 0;
  v160 = get_white();
  v44 = Concat_5224608(name, "_hp");
  v45 = object___get_Item(CCtrObjs, v44);
  Set(v45, v17->hp, v160, v40, 0);
  v46 = CCtrObjs;
  v47 = Concat_5224608(name, "_mhp");
  v48 = object___get_Item(v46, v47);
  Set(v48, v17->maxhp, v160, v40, 0);
  LOWORD(v50) = v17->hp;
  LOWORD(v51) = v17->maxhp;
  v53 = v50 / v51;
  if (v53 < 1.0 && v53 >= 0.95)
    v53 = 0.95;
  if (v53 > 0.05 || v53 <= 0.0)
    v56 = v53;
  else
    v56 = 0.05;
  v58 = Concat_5224608(name, "_hpbar");
  v59 = object___get_Item(BImgObjs, v58);
  set_fillAmount(v59, v56);
  v60 = CCtrObjs;
  v61 = Concat_5224608(name, "_mp");
  v62 = object___get_Item(v60, v61);
  Set(v62, v17->mp, v160, v40, 0);
  v63 = CCtrObjs;
  v64 = Concat_5224608(name, "_mmp");
  v65 = object___get_Item(v63, v64);
  Set(v65, v17->maxmp, v160, v40, 0);
  v67 = Concat_5224608(name, "_mpbar");
  v68 = object___get_Item(ListObjs, v67);
  if (!get_activeSelf(v68))
  {
    v71 = ListObjs;
    v72 = Concat_5224608(name, "_mpbar");
    v73 = object___get_Item(v71, v72);
    SetActive(v73, 1, 0);
  }
  v75 = ListObjs;
  v76 = Concat_5224608(name, "_mpbar_d");
  v77 = object___get_Item(v75, v76);
  if (get_activeSelf(v77))
  {
    v82 = ListObjs;
    v83 = Concat_5224608(name, "_mpbar_d");
    v84 = object___get_Item(v82, v83);
    SetActive(v84, 0, 0);
  }
  LOWORD(v79) = v17->mp;
  LOWORD(v80) = v17->maxmp;
  v86 = v79 / v80;
  if (v86 < 1.0 && v86 >= 0.95)
    v86 = 0.95;
  if (v86 > 0.05 || v86 <= 0.0)
    v89 = v86;
  else
    v89 = 0.05;
  v90 = BImgObjs;
  v91 = Concat_5224608(name, "_mpbar");
  v92 = object___get_Item(v90, v91);
  set_fillAmount(v92, v89);
  v93 = ListObjs;
  v94 = Concat_5224608(name, "_steff");
  v95 = object___get_Item(v93, v94);
  transform = get_transform(v95, 0);
  childCount = get_childCount(transform);
  if (childCount >= 1)
  {
    v101 = 0;
    do
    {
      v102 = ListObjs;
      v156 = v101;
      v103 = sub_8D3950(s32, &v156);
      v104 = Format("_steff_{0:D2}", v103, 0);
      v105 = Concat_5224608(name, v104);
      v106 = object___get_Item(v102, v105);
      if (get_activeSelf(v106))
        SetActive(v106, 0, 0);
      ++v101;
      v107 = get_childCount(transform);
    }
    while (v101 < v107);
  }
  v109 = Concat_5224608(name, "_steff");
  v111 = object___get_Item(AnimObjs, v109);
  if (!op_Equality(v111, 0, 0))
  {
    v112 = v17->badstatus;
    if (v112 > 0x40)
    {
      if (v112 > 0x200)
      {
        if (v112 == 1024)
        {
          v114 = 13;
        }
        else
        {
          if (v112 != 2048)
          {
LABEL_118:
            v114 = 0;
            goto LABEL_119;
          }
          v114 = 5;
        }
      }
      else
      {
        switch (v112)
        {
          case 0x80u:
            v114 = 2;
            break;
          case 0x100u:
            v114 = 8;
            break;
          case 0x200u:
            v114 = 7;
            break;
          default:
            goto LABEL_118;
        }
      }
    }
    else
    {
      if (v112 <= 8)
      {
        v113 = v112 - 1;
        if (v113 < 8)
        {
          v114 = dword_32C2174[v113];
          goto LABEL_119;
        }
        goto LABEL_118;
      }
      switch (v112)
      {
        case 0x10u:
          v114 = 1;
          break;
        case 0x20u:
          v114 = 3;
          break;
        case 0x40u:
          v114 = 10;
          break;
        default:
          goto LABEL_118;
      }
    }
LABEL_119:
    SetInteger(v111, "steff", v114);
    v118 = AnimObjs;
    v119 = Concat_5224608(name, "_rcvstatus");
    v121 = object___get_Item(v118, v119);
    if (!op_Equality(v121, 0, 0))
    {
      v122 = 1;
      switch (v114)
      {
        case 3:
          goto LABEL_161;
        case 5:
          SetInteger(v121, "rcvstatus", 3);
          v125 = ListObjs;
          v126 = Concat_5224608(name, "_mpbar");
          v127 = object___get_Item(v125, v126);
          if (get_activeSelf(v127))
          {
            v130 = ListObjs;
            v131 = Concat_5224608(name, "_mpbar");
            v132 = object___get_Item(v130, v131);
            SetActive(v132, 0, 0);
          }
          v134 = ListObjs;
          v135 = Concat_5224608(name, "_mpbar_d");
          v136 = object___get_Item(v134, v135);
          if (!get_activeSelf(v136))
          {
            v141 = ListObjs;
            v142 = Concat_5224608(name, "_mpbar_d");
            v143 = object___get_Item(v141, v142);
            SetActive(v143, 1, 0);
          }
          LOWORD(v138) = v17->mp;
          LOWORD(v139) = v17->maxmp;
          v145 = v138 / v139;
          if (v145 < 1.0 && v145 >= 0.95)
            v145 = 0.95;
          if (v145 > 0.05 || v145 <= 0.0)
            v148 = v145;
          else
            v148 = 0.05;
          v149 = BImgObjs;
          v150 = Concat_5224608(name, "_mpbar_d");
          v151 = object___get_Item(v149, v150);
          set_fillAmount(v151, v148);
          return;
        case 8:
          v122 = 4;
          goto LABEL_161;
        case 10:
          v122 = 5;
          goto LABEL_161;
        default:
          v122 = 0;
LABEL_161:
          SetInteger(v121, "rcvstatus", v122);
          break;
      }
    }
  }
}
