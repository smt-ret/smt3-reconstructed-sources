#include "types.h"

typedef struct FldNameData FldNameData;
typedef struct RippleEffect RippleEffect;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static char *gTerminalCaptionStr[2];
static void *ListObjs;
static void *TextObjs;
static void *AnimObjs;
static s32 ChildCount;
static void *MatCols;
static s32 CsrMoveSw;

void DrawCaption2(char *name, char *caption, void *txt);
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
void *GetGameObject(char *name);
char *GetSaveNmlName(FldNameData *this, s32 TmnlId);
char *GetSaveSmlName(FldNameData *this, s32 TmnlId);
char *RepColTag(char *txt, void **LegacyParamArray);
void ScrollEffect(void *obj);
void Update(RippleEffect *this);
void UpdateDrawFlag(char *name);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkDbgProcess(void);
s8 fclChkSignal(s8 Idx);
s8 trmChkEventWait(void);
void trmDrawSeqConfirm(void);
void trmDrawSeqRoot(s8 CursorStyle);
void trmDrawSeqTrans(void);
void trmDrawTerminalName(void *obj, void *txt, char *name, u32 color);
void trmDrawTerminalNamePanel(void);
char *trmGetTerminalName(s32 TerminalNo, s32 TerminalType);

// 0xf791a0
void FinalizeGameObject(void) {
  PropertySheet___Clear(AnimObjs);
  PropertySheet___Clear(ListObjs);
  PropertySheet___Clear(TextObjs);
}

// 0xf78af0
void InitializeGameObject(void) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v3;
  u64 *v4;
  s32 v7;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v9;
  s32 v10;
  System_WeakReference_o *Item;
  System_WeakReference_o *v12;
  s32 Count;
  fclTerminalDraw_c *v15;
  s32 v16;
  u64 *v18;
  System_String_o *v19;
  System_WeakReference_o *v20;
  UnityEngine_Transform_o *v22;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *ListObjs;
  System_WeakReference_o *v25;
  UnityEngine_Component_o *v27;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v29;
  System_String_o *v30;
  UnityEngine_GameObject_o *v31;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *TextObjs;
  System_String_o *v33;
  UnityEngine_GUILayer_o *Component_GUILayer;
  struct System_Collections_Generic_Dictionary_string__Animation__o *AnimObjs;
  System_String_o *v36;
  UnityEngine_GUILayer_o *v37;
  System_Collections_Generic_Dictionary_Shader__PropertySheet__o *v38;
  UnityEngine_Transform_o *v39;
  UnityEngine_Component_o *v40;
  UnityEngine_GameObject_o *v41;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v42;
  UnityEngine_Transform_o *v43;
  UnityEngine_Component_o *v44;
  UnityEngine_GameObject_o *v45;
  UnityEngine_GameObject_o *v47;
  struct System_Collections_Generic_Dictionary_string__TextMeshProUGUI__o *v48;
  UnityEngine_Transform_o *v49;
  UnityEngine_Component_o *v50;
  UnityEngine_GUILayer_o *v51;
  UnityEngine_GameObject_o *GameObject;
  s32 v53;

  GameObject = GetGameObject("menu_tmnl");
  transform = get_transform(GameObject, 0);
  v3 = Find(transform, "tmnlmenu_window", 0);
  v4 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v4);
  PropertySheet___Clear(ListObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(AnimObjs);
  if (get_childCount(v3) >= 1)
  {
    v7 = 0;
    do
    {
      Child = GetChild(v3, v7);
      v9 = get_gameObject(Child);
      _Add(v4, v9);
      ++v7;
    }
    while (v7 < get_childCount(v3));
  }
  if (_get_Count(v4) >= 1)
  {
    v10 = 0;
    do
    {
      Item = _get_Item(
               v4,
               v10);
      if (get_activeSelf(Item))
      {
        v12 = _get_Item(
                v4,
                v10);
        SetActive(v12, 0, 0);
      }
      ++v10;
    }
    while (v10 < _get_Count(v4));
  }
  Count = _get_Count(v4);
  v16 = 0;
  ChildCount = Count;
  if ((v15->_2.bitflags2 & 2) != 0)
  {
LABEL_23:
  }
  while (1)
  {
    if (v16 >= ChildCount)
      break;
    v53 = v16 + 1;
    v18 = sub_8D3950(s32, &v53);
    v19 = Format("termwnd{0:D2}", v18, 0);
    v20 = _get_Item(
            v4,
            v16);
    v22 = get_transform(v20, 0);
    v25 = _get_Item(
            v4,
            v16);
    PropertySheet___Add(ListObjs, v19, v25);
    v27 = Find(v22, "tmnl_text/TextTM", 0);
    if (op_Inequality(v27, 0, 0))
    {
      v29 = ListObjs;
      v30 = Concat_5224608("t_", v19);
      v31 = get_gameObject(v27);
      PropertySheet___Add(v29, v30, v31);
      v33 = Concat_5224608("t_", v19);
      Component_GUILayer = GetComponent_GUILayer_(v27);
      PropertySheet___Add(TextObjs, v33, Component_GUILayer);
      v36 = Concat_5224608("t_", v19);
      v37 = GetComponent_GUILayer_(v27);
      PropertySheet___Add(AnimObjs, v36, v37);
    }
    ++v16;
      goto LABEL_23;
  }
  v38 = ListObjs;
  v39 = get_transform(GameObject, 0);
  v40 = Find(v39, "menu_cursur", 0);
  v41 = get_gameObject(v40);
  PropertySheet___Add(v38, "menu_cursor", v41);
  v42 = ListObjs;
  v43 = get_transform(GameObject, 0);
  v44 = Find(v43, "tmnlscroll", 0);
  v45 = get_gameObject(v44);
  PropertySheet___Add(v42, "tmnlscroll", v45);
  v47 = GetGameObject("tmnltitle");
  v48 = TextObjs;
  v49 = get_transform(v47, 0);
  v50 = Find(v49, "Text_tmnltitleTM", 0);
  v51 = GetComponent_GUILayer_(v50);
  PropertySheet___Add(v48, "tmnltitle", v51);
}

// 0xf7a570
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

// 0xf7ad90
dds3ProcessFunc_t *trmDraw(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s16 v13;
  s32 v14;
  struct cmpSeqInfo_t_o *SeqInfo;
  u8 Flag;
  s32 Current;
  dds3ProcessID_t_o *v23[3];
  dds3ProcessID_t_o *id;

  id = PID;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataTerminal_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataTerminal_t, v23);
    if ((v23[0] & 1) != 0)
      v7 = v23[2];
    else
      v7 = v23 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  if (fclChkDbgProcess() != 1)
  {
    if (trmChkEventWait() != 1)
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
      Flag = SeqInfo->Flag;
      if ((Flag & 0x20) != 0)
      {
        cmpUpdateTerminate(SeqInfo);
        id->func_ans = -1;
      }
      else
      {
        if ((Flag & 2) != 0)
        {
          Current = SeqInfo->Current;
          if (Current == 5)
          {
            trmDrawSeqConfirm();
          }
          else if (Current == 1)
          {
            trmDrawSeqTrans();
          }
          else if (!SeqInfo->Current)
          {
            if (fclChkSignal(0) == 1)
            {
              {
              }
              trmDrawSeqRoot(0);
            }
            else
            {
              {
              }
              trmDrawSeqRoot(2);
            }
          }
        }
        Update();
      }
    }
  }
  return 0;
}

// 0xf7a5f0
void trmDrawSeqConfirm(void) {
  struct fclDataTerminal_t_o *GBWK;
  cmpCursorInfo_t_o *CursorInfo;

  trmDrawTerminalNamePanel();
  else
  {
    if (!GBWK->TerminalType)
      return;
  }
  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  DrawCommandSelectMenu(CursorInfo, 0, 1);
}

// 0xf7acc0
void trmDrawSeqRoot(s8 CursorStyle) {
  cmpCursorInfo_t_o *CursorInfo;

  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  DrawCommandSelectMenu(CursorInfo, 0, CursorStyle);
  trmDrawTerminalNamePanel();
}

// 0xf79760
void trmDrawSeqTrans(void) {
  u32 v2;
  cmpCursorInfo_t_o *CursorInfo;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_Collections_Generic_Dictionary_object__object__o *v6;
  System_String_o *v8;
  Il2CppObject *Item;
  UnityEngine_GameObject_o *GameObject;
  Il2CppObject *v17;
  System_String_o *name;
  cmpCursorPos_t_o *CursorPos;
  struct cmpCursorPos_t_o *v23;
  u32 ListNums;
  u32 ShiftMax;
  u32 v27;
  Il2CppObject *v30;
  s32 v33;
  s32 v36;
  u64 *v37;
  Il2CppObject *v38;
  u64 *v39;
  Il2CppObject *v41;
  struct System_SByte_array *TerminalList;
  s32 v45;
  s32 v48;
  s16 v50;
  s32 v51;
  Il2CppObject *v52;
  Il2CppObject *v54;
  System_String_o *SaveNmlName;
  System_Collections_Generic_List_int__o *MatCols;
  s32 v59;
  const MethodInfo_1260 *v60;
  Il2CppObject *v62;
  Il2CppObject *v64;
  Il2CppObject *v65;
  Il2CppObject *v66;
  Il2CppObject *v67;
  Il2CppObject *v70;
  struct cmpCursorPos_t_o *v71;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v73;
  struct cmpCursorPos_t_o *v75;
  s32 Shift;
  s32 v78;
  s32 v79;
  s32 col2;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v82;

  col2 = 0;
  CursorInfo = GBWK->TransWindow->CursorInfo;
  col2 = 2;
  else
  {
    v6 = *static_fields;
    if (!LODWORD((*static_fields)->entries))
      goto LABEL_9;
  }
  v8 = *&v6->count;
  Item = object___get_Item(static_fields[2], "tmnltitle");
  DrawCaption2("tmnltitle", v8, Item);
  trmDrawTerminalNamePanel();
  GameObject = GetGameObject("menu_tmnl");
  if (!get_activeSelf(GameObject))
    SetActive(GameObject, 1, 0);
  v17 = object___get_Item(ListObjs, "tmnlscroll");
  name = get_name(v17);
  CursorPos = CursorInfo->CursorPos;
  DrawScrollBar(v17, name, CursorPos);
  v23 = CursorInfo->CursorPos;
  ListNums = v23->ListNums;
  ShiftMax = v23->ShiftMax;
  if (ListNums <= ShiftMax)
    v27 = ListNums;
  else
    v27 = ShiftMax;
  if (ScrollDir)
  {
    v30 = object___get_Item(ListObjs, "termwnd01");
    ScrollEffect(v30);
  }
  _Clear(MatCols);
  v33 = 0;
  {
LABEL_42:
  }
  while (1)
  {
    if (v33 >= ChildCount)
      break;
    v36 = v33 + 1;
    v79 = v33 + 1;
    v37 = sub_8D3950(s32, &v79);
    v38 = Format("termwnd{0:D2}", v37, 0);
    v78 = v33 + 1;
    v39 = sub_8D3950(s32, &v78);
    v41 = Format("t_termwnd{0:D2}", v39, 0);
    if (v33 < v27)
    {
      cmpGetCursorBlurFontCol(CursorInfo, v33, v33, 0, 256, &col2, 0);
      TerminalList = GBWK->TerminalList;
      v45 = v33 + CursorInfo->CursorPos->Index;
      v48 = TerminalList->m_Items[v45];
      v52 = object___get_Item(ListObjs, v38);
      v54 = object___get_Item(TextObjs, v41);
      SaveNmlName = GetSaveNmlName(fldNameData, v48);
      trmDrawTerminalName(v52, v54, SaveNmlName, col2);
      v59 = col2;
      v60 = Method_System_Collections_Generic_List_int__Add__;
LABEL_82:
      _Add(MatCols, v59, v60);
      goto LABEL_40;
    }
    if ((v50 & 0x200) != 0)
    {
      v51 = v50 & 0x200;
    }
    else
    {
      v51 = 0;
    }
    if (v33 != ChildCount - 1)
    {
      v65 = object___get_Item(AnimObjs, v41);
      set_enabled(v65, 0);
      v66 = object___get_Item(ListObjs, v38);
      v67 = object___get_Item(TextObjs, v41);
      trmDrawTerminalName(v66, v67, 0, col2);
      v60 = Method_System_Collections_Generic_List_int__Add__;
      v59 = -1;
      goto LABEL_82;
    }
    v62 = object___get_Item(ListObjs, v38);
    ++v33;
    if (get_activeSelf(v62))
      goto LABEL_41;
    v64 = object___get_Item(ListObjs, v38);
    SetActive(v64, 1, 0);
LABEL_40:
    v33 = v36;
LABEL_41:
      goto LABEL_42;
  }
  v70 = object___get_Item(ListObjs, "menu_cursor");
  v71 = CursorInfo->CursorPos;
  LOBYTE(v2) = v71->Shift;
  transform = get_transform(v70, 0);
  localPosition = get_localPosition(transform);
  v73 = get_transform(v70, 0);
  v82.x = localPosition.x;
  v82.y = (v2 * -56.0) + -12.0;
  v82.z = localPosition.z;
  set_localPosition(v73, v82);
  _ToArray(MatCols);
  v75 = CursorInfo->CursorPos;
  if (v75->EffFlag)
  {
    Shift = v75->Shift;
    CsrMoveSw = Shift;
  }
  UpdateDrawFlag("menu_tmnl");
}

// 0xf795f0
void trmDrawTerminalName(void *obj, void *txt, char *name, u32 color) {
  bool IsNullOrEmpty;
  System_String_o *v10;
  System_Object_array *v11;
  s64 *v12;
  s64 *v14;
  u32 v17;
  UnityEngine_Color_o white;

  if (!get_activeSelf(obj))
    SetActive(obj, 1, 0);
  IsNullOrEmpty = IsNullOrEmpty(name);
  v10 = 0;
  if (!IsNullOrEmpty)
  {
    v17 = color;
    v11 = NewSpecific(object, 1u);
    v12 = sub_8D3950(s32, &v17);
    v14 = v12;
    v11->m_Items[0] = v14;
    v10 = RepColTag(name, v11);
  }
  set_text(txt, v10);
  white = get_white();
  (txt->klass->vtable._27_SetLayoutDirty.methodPtr)(
    txt,
    txt->klass->vtable._27_SetLayoutDirty.white.r,
    white.g,
    white.b,
    white.a);
}

// 0xf79310
void trmDrawTerminalNamePanel(void) {
  UnityEngine_GameObject_o *GameObject;
  TMPro_TMP_Text_o *monitor;
  struct fclDataTerminal_t_o *GBWK;
  s32 TerminalNo;
  s32 TerminalType;
  System_String_o *TerminalName;

  GameObject = GetGameObject("tmnlcurrent");
  if (!op_Equality(GameObject, 0, 0))
  {
    if (!get_activeSelf(GameObject))
      SetActive(GameObject, 1, 0);
    monitor = GetComponent_object_(GameObject)[1].monitor;
    TerminalNo = GBWK->TerminalNo;
    TerminalType = GBWK->TerminalType;
    TerminalName = trmGetTerminalName(TerminalNo, TerminalType);
    set_text(monitor, TerminalName);
    UpdateDrawFlag("tmnlcurrent");
  }
}

// 0xf79250
char *trmGetTerminalName(s32 TerminalNo, s32 TerminalType) {
  if (TerminalType)
  {
    return GetSaveSmlName(fldNameData, TerminalNo);
  }
  else
  {
    return GetSaveNmlName(fldNameData, TerminalNo);
  }
}
