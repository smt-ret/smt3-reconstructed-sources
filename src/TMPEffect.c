#include "types.h"

typedef struct TMPEffect TMPEffect;
typedef struct TMPEffect_FADEMODE TMPEffect_FADEMODE;
typedef struct TMPEffect_TMPData TMPEffect_TMPData;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;

struct TMPEffect_TMPData {
    s32 type;
    s32 s_type;
    void *obj;
    void *scr;
    sdfColor_t color;
    f32 radd;
    f32 gadd;
    f32 badd;
    s32 count;
};

struct TMPEffect_FADEMODE {
    s32 value__;
};

static s32 TABLEMAX;
static f32 FADEFRAME;
static sdfColor32_t pC1;
static sdfColor32_t pC2;

bool IsAlready(TMPEffect *this, void *obj, s32 mode, s32 type);
void SetColor(XRD773Unity_CommonMesh *this, void col, s32 length);

// 0x1344d10
void Clear(TMPEffect_TMPData *this) {
  *&this->color.r = 0;
  *&this->color.b = 0;
  this->scr = 0;
  *(this + 7) = 0;
  *(this + 8) = 0;
}

// 0x1344020
bool IsAlready(TMPEffect *this, void *obj, s32 mode, s32 type) {
  s64 v9;
  u64 v10;
  struct TMPEffect_TMPData_array *list;
  struct TMPEffect_TMPData_array *v14;
  struct TMPEffect_TMPData_array *v16;
  struct TMPEffect_TMPData_array *v18;

  v9 = 0;
  v10 = 0;
  {
LABEL_6:
  }
  while (v10 < TABLEMAX)
  {
    list = this->list;
    if (list->m_Items[v9].type)
    {
      v14 = this->list;
      if (v14->m_Items[v9].type == mode)
      {
        v16 = this->list;
        if (v16->m_Items[v9].s_type == type)
        {
          v18 = this->list;
          if (((v18->m_Items[v9].obj->klass->vtable._0_Equals.methodPtr)(
                  v18->m_Items[v9].obj,
                  obj,
                  v18->m_Items[v9].obj->klass->vtable._0_Equals.*&type)
              & 1) != 0)
            return 1;
        }
      }
    }
    ++v10;
    ++v9;
      goto LABEL_6;
  }
  return 0;
}

// 0x1342e00
void ResetTMPEffect(TMPEffect *this) {
  long f64 v2;
  long f64 v3;
  long f64 v4;
  long f64 v5;
  s64 v7;
  u64 v8;
  u64 *v10;
  struct TMPEffect_TMPData_array *list;
  f32 v13;
  f32 v14;
  f32 v15;
  long f64 v16;
  long f64 v17;
  long f64 v18;
  long f64 v19;
  struct TMPEffect_TMPData_array *v20;
  s32 s_type;
  struct TMPEffect_TMPData_array *v23;
  Il2CppObject *v25;
  Il2CppClass *v26;
  s64 v27;
  char *v28;
  s64 *v29;
  struct TMPEffect_TMPData_array *v30;
  s32 v32;
  Il2CppObject *v33;
  s32 v34;
  s32 v35;
  Il2CppClass *v36;
  s64 v37;
  char *v38;
  s64 *v39;
  struct TMPEffect_TMPData_array *v40;
  struct TMPEffect_TMPData_array *v41;
  Il2CppObject *scr;
  s64 typeHierarchyDepth;
  Il2CppClass *klass;
  char *v47;
  s64 *v48;
  s64 v49;
  s64 v50;
  u64 v51[2];
  char *v52;

  v49 = 0;
  v50 = 0;
  v7 = 0;
  v8 = 0;
  {
LABEL_6:
  }
  while (v8 < TABLEMAX)
  {
    list = this->list;
    if (list->m_Items[v7].type == 2)
    {
      v13 = 0.5;
      v14 = 0.5;
      v15 = 0.5;
    }
    else
    {
      v13 = 1.0;
      v14 = 1.0;
      v15 = 1.0;
    }
    sub_19EC630(&v49, v13, v14, v15, 1.0);
    v20 = this->list;
    s_type = v20->m_Items[v7].s_type;
    if (s_type == 3)
    {
      v41 = this->list;
      scr = v41->m_Items[v7].scr;
      klass = scr->klass;
      if (scr->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_UI_Image)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_UI_Image, v51);
        if ((v51[0] & 1) != 0)
          v47 = v52;
        else
          v47 = v51 + 1;
        v48 = sub_8C4940(v47);
      }
      LODWORD(v17) = HIDWORD(v49);
      LODWORD(v16) = v49;
      LODWORD(v19) = HIDWORD(v50);
      LODWORD(v18) = v50;
      (klass->vtable[23].methodPtr)(v16, v17, v18, v19);
LABEL_45:
      v40 = this->list;
      if (v8 >= LODWORD(v40->max_length))
        goto LABEL_46;
      goto LABEL_5;
    }
    if (s_type != 2)
    {
      if (s_type == 1)
      {
        v23 = this->list;
        LODWORD(v2) = HIDWORD(v49);
        LODWORD(v4) = v49;
        LODWORD(v3) = HIDWORD(v50);
        LODWORD(v5) = v50;
        v25 = v23->m_Items[v7].scr;
        if (v25)
        {
          v26 = v25->klass;
          if (v25->klass->_2.typeHierarchyDepth < v27
            || v26->_2.typeHierarchy[v27 - 1] != TMPro_TextMeshProUGUI)
          {
            sub_8FC2C0(v26->_1.element_class, TMPro_TextMeshProUGUI, v51);
            if ((v51[0] & 1) != 0)
              v28 = v52;
            else
              v28 = v51 + 1;
            v29 = sub_8C4940(v28);
          }
        }
        (v25->klass->vtable[23].methodPtr)(v4, v2, v5, v3);
      }
      goto LABEL_45;
    }
    v30 = this->list;
    v32 = HIDWORD(v49);
    v33 = v30->m_Items[v7].scr;
    v34 = v50;
    v35 = HIDWORD(v50);
    if (v33)
    {
      v36 = v33->klass;
      if (v33->klass->_2.typeHierarchyDepth < v37 || v36->_2.typeHierarchy[v37 - 1] != CounterCtr)
      {
        sub_8FC2C0(v36->_1.element_class, CounterCtr, v51);
        if ((v51[0] & 1) != 0)
          v38 = v52;
        else
          v38 = v51 + 1;
        v39 = sub_8C4940(v38);
      }
    }
    LODWORD(v33[3].klass) = v49;
    HIDWORD(v33[3].klass) = v32;
    LODWORD(v33[3].monitor) = v34;
    HIDWORD(v33[3].monitor) = v35;
    v40 = this->list;
    if (v8 >= LODWORD(v40->max_length))
    {
LABEL_46:
    }
LABEL_5:
    v10 = (&v40->obj.klass + v7 * 56);
    ++v8;
    ++v7;
    v10[5] = 0;
    v10[6] = 0;
    v10[4] = 0;
    v10[9] = 0;
    v10[10] = 0;
      goto LABEL_6;
  }
  _Clear(this->table);
}

// 0x1344360
void Scroll(TMPEffect *this, void *obj, s32 top, s32 dir) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *parent;
  s32 childCount;
  s32 i;
  struct System_Collections_Generic_List_GameObject__o *c_obj;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  System_Collections_Generic_Dictionary_string__int__o *cname;
  System_WeakReference_o *Item;
  System_String_o *name;
  const MethodInfo_1221 **v19;
  u64 v20;
  s64 v21;
  struct TMPEffect_TMPData_array *list;
  struct TMPEffect_TMPData_array *v25;
  System_String_o *v27;
  s32 v28;
  System_WeakReference_o *v29;
  struct TMPEffect_TMPData_array *v30;
  Il2CppClass *v31;
  s32 v33;
  System_Object_array *ComponentsInChildren_object__441952;
  il2cpp_array_size_t max_length;
  s32 v36;
  const MethodInfo_1221 **v37;
  struct TMPEffect_TMPData_array *v38;
  char *v40;
  struct TMPEffect_TMPData_array *v41;
  struct TMPEffect_TMPData_array *v43;
  struct TMPEffect_TMPData_array *v45;
  s32 v47;
  struct TMPEffect_TMPData_array *v48;
  UnityEngine_Object_o *v50;
  UnityEngine_Object_c *klass;
  s64 v52;
  char *v53;
  s64 *v54;
  struct TMPEffect_TMPData_array *v55;
  char *v57;
  struct TMPEffect_TMPData_array *v58;
  UnityEngine_Object_c *v60;
  s64 v61;
  char *v62;
  s64 *v63;
  struct TMPEffect_TMPData_array *v64;
  struct TMPEffect_TMPData_array *v65;
  UnityEngine_Color_o *v67;
  s64 v68;
  s64 typeHierarchyDepth;
  char *v70;
  s64 *v71;
  char *v73;
  u64 v75[2];
  char *v76;
  UnityEngine_Color_o white;
  UnityEngine_Color_o v78;

  transform = get_transform(obj, 0);
  parent = get_parent(transform);
  childCount = get_childCount(parent);
  _Clear(this->c_obj);
  int___Clear(this->cname);
  if (childCount >= 1)
  {
    for (i = 0; i != childCount; ++i)
    {
      c_obj = this->c_obj;
      Child = GetChild(parent, i);
      gameObject = get_gameObject(Child);
      _Add(c_obj, gameObject);
      cname = this->cname;
      Item = _get_Item(
               this->c_obj,
               i);
      name = get_name(Item);
      int___Add(cname, name, i);
    }
  }
  v19 = &Method_System_Collections_Generic_Dictionary_string__int__get_Item__;
  v20 = 0;
  v21 = 36;
  {
LABEL_9:
  }
  while (v20 < TABLEMAX)
  {
    list = this->list;
    if (!*(list + v21 - 4))
      goto LABEL_8;
    v25 = this->list;
    v27 = get_name(*(&v25->obj.klass + v21 + 4), 0);
    if (!int___ContainsKey(this->cname, v27))
      goto LABEL_8;
    v28 = int___get_Item(this->cname, v27, *v19) - dir;
    if (v28 < 0 || v28 >= childCount)
    {
      v43 = this->list;
      white = get_white();
      *(&v43->bounds + v21 + 4) = white;
      v45 = this->list;
      v47 = *(&v45->obj.klass + v21);
      if (v47 != 3)
      {
        if (v47 == 2)
        {
          v65 = this->list;
          v67 = *(&v65->obj.monitor + v21 + 4);
          if (v67)
          {
            v68 = *&v67->r;
            if (*(*&v67->r + 288LL) < typeHierarchyDepth
              || *(*(v68 + 200) + 8 * typeHierarchyDepth - 8) != CounterCtr)
            {
              sub_8FC2C0(*(v68 + 64), CounterCtr, v75);
              if ((v75[0] & 1) != 0)
                v70 = v76;
              else
                v70 = v75 + 1;
              v71 = sub_8C4940(v70);
            }
          }
          if (op_Inequality(v67, 0, 0))
            v67[3] = get_white();
        }
        else if (v47 == 1)
        {
          v48 = this->list;
          v50 = *(&v48->obj.monitor + v21 + 4);
          if (v50)
          {
            klass = v50->klass;
            if (v50->klass->_2.typeHierarchyDepth < v52
              || klass->_2.typeHierarchy[v52 - 1] != TMPro_TextMeshProUGUI)
            {
              sub_8FC2C0(klass->_1.element_class, TMPro_TextMeshProUGUI, v75);
              if ((v75[0] & 1) != 0)
                v53 = v76;
              else
                v53 = v75 + 1;
              v54 = sub_8C4940(v53);
            }
          }
          goto LABEL_66;
        }
        goto LABEL_86;
      }
      v58 = this->list;
      v50 = *(&v58->obj.monitor + v21 + 4);
      if (v50)
      {
        v60 = v50->klass;
        if (v50->klass->_2.typeHierarchyDepth < v61 || v60->_2.typeHierarchy[v61 - 1] != UnityEngine_UI_Image)
        {
          sub_8FC2C0(v60->_1.element_class, UnityEngine_UI_Image, v75);
          if ((v75[0] & 1) != 0)
            v62 = v76;
          else
            v62 = v75 + 1;
          v63 = sub_8C4940(v62);
        }
      }
LABEL_66:
      if (op_Inequality(v50, 0, 0))
      {
        v78 = get_white();
        (v50->klass[1].vtable._0_Equals.method)(
          v50,
          v50->klass[1].vtable._1_Finalize.methodPtr,
          v78.r,
          v78.g,
          v78.b,
          v78.a);
        v64 = this->list;
        if (v20 >= LODWORD(v64->max_length))
          goto LABEL_87;
      }
      else
      {
LABEL_86:
        v64 = this->list;
        if (v20 >= LODWORD(v64->max_length))
        {
LABEL_87:
        }
      }
      v73 = v64 + v21;
      *(v73 + 12) = 0;
      *(v73 + 4) = 0;
      *(v73 - 4) = 0;
      *(v73 + 44) = 0;
      *(v73 + 36) = 0;
      goto LABEL_8;
    }
    v29 = _get_Item(
            this->c_obj,
            v28);
    v30 = this->list;
    v31 = v29;
    v33 = *(&v30->obj.klass + v21);
    switch (v33)
    {
      case 3:
        ComponentsInChildren_object__441952 = GetComponentsInChildren_object__441952(v29);
        if (!ComponentsInChildren_object__441952)
          goto LABEL_51;
        break;
      case 2:
        ComponentsInChildren_object__441952 = GetComponentsInChildren_object__441952(v29);
        if (!ComponentsInChildren_object__441952)
        {
LABEL_51:
          v55 = this->list;
          v57 = v55 + v21;
          *(v57 + 12) = 0;
          *(v57 + 4) = 0;
          *(v57 - 4) = 0;
          *(v57 + 44) = 0;
          *(v57 + 36) = 0;
          v41 = this->list;
          if (v20 >= LODWORD(v41->max_length))
          {
LABEL_32:
          }
          goto LABEL_33;
        }
        break;
      case 1:
        ComponentsInChildren_object__441952 = GetComponentsInChildren_object__441952(v29);
        if (!ComponentsInChildren_object__441952)
          goto LABEL_51;
        break;
      default:
        goto LABEL_31;
    }
    max_length = ComponentsInChildren_object__441952->max_length;
    if (!max_length)
      goto LABEL_51;
    v36 = dir;
    v37 = v19;
    v38 = this->list;
    v40 = v38 + v21;
    v19 = v37;
    dir = v36;
    *(v40 + 12) = ComponentsInChildren_object__441952->m_Items[0];
LABEL_31:
    v41 = this->list;
    if (v20 >= LODWORD(v41->max_length))
      goto LABEL_32;
LABEL_33:
    *(&v41->obj.klass + v21 + 4) = v31;
LABEL_8:
    ++v20;
    v21 += 56;
      goto LABEL_9;
  }
}

// 0x13425a0
void Start(TMPEffect *this) {
  s64 v3;
  u64 v4;
  u64 *v6;
  struct TMPEffect_TMPData_array *list;
  u64 *v9;
  struct TMPEffect_TMPData_array *v10;

  v3 = 0;
  v4 = 0;
  {
LABEL_6:
  }
  while (v4 < TABLEMAX)
  {
    list = this->list;
    v9 = (&list->obj.klass + v3);
    v9[9] = 0;
    v9[10] = 0;
    v9[7] = 0;
    v9[8] = 0;
    v9[4] = 0;
    v9[5] = 0;
    v9[6] = 0;
    v10 = this->list;
    v6 = (&v10->obj.klass + v3);
    ++v4;
    v3 += 56;
    v6[5] = 0;
    v6[6] = 0;
    v6[4] = 0;
    v6[9] = 0;
    v6[10] = 0;
      goto LABEL_6;
  }
  _Clear(this->table);
}

// 0x1343250
void StartEffect(TMPEffect *this, void *obj, s32 mode, s32 tp) {
  System_Object_array *ComponentsInChildren_object__441952;
  System_Object_array *v10;
  System_Object_array *v11;
  System_Object_array *v13;
  signed s64 v15;
  struct TMPEffect_TMPData_array **p_list;
  s64 v17;
  struct TMPEffect_TMPData_array *v20;
  Il2CppObject *v23;
  TMPEffect_o *v25;
  UnityEngine_Behaviour_o *Component_GUILayer;
  UnityEngine_Component_o *v28;
  UnityEngine_Behaviour_o *v29;
  UnityEngine_Color_o *v31;
  UnityEngine_GUILayer_o *v34;
  Il2CppObject *v36;
  TMPEffect_o *v41;
  System_Object_array *v42;
  s32 v46;
  struct TMPEffect_TMPData_array *v49;
  struct TMPEffect_TMPData_array *v54;
  s32 FADEFRAME;
  struct TMPEffect_TMPData_array *v58;
  struct TMPEffect_TMPData_array *v65;
  System_Object_array *v71;
  struct TMPEffect_TMPData_array *v72;
  Il2CppObject *v73;
  struct TMPEffect_TMPData_array *v74;
  struct TMPEffect_TMPData_array *v75;
  UnityEngine_Color_o *v80;
  UnityEngine_Color32_o rgba;
  Il2CppObject *v88;
  UnityEngine_Color32_o v89;
  long f64 v96;
  long f64 v97;
  long f64 v98;
  long f64 v99;
  System_Object_array *v100;
  s32 v101;
  System_Object_array *v102;
  UnityEngine_Color_o white;
  UnityEngine_Color_o v104;
  UnityEngine_Color_o v105;
  UnityEngine_Color_o v106;
  UnityEngine_Color_o v107;
  UnityEngine_Color_o v108;
  UnityEngine_Color_o gray;
  UnityEngine_Color_o v110;

  ComponentsInChildren_object__441952 = GetComponentsInChildren_object__441952(obj);
  v10 = GetComponentsInChildren_object__441952(obj);
  v11 = GetComponentsInChildren_object__441952(obj);
  v13 = v11;
  v102 = v10;
  switch (tp)
  {
    case 3:
      if (!v11)
        return;
      if (!v11->max_length)
        return;
      v101 = 3;
      if (IsAlready(this, obj, mode, 3))
        return;
      break;
    case 2:
      if (!v10)
        return;
      if (!v10->max_length)
        return;
      v101 = 2;
      if (IsAlready(this, obj, mode, 2))
        return;
      break;
    case 1:
      if (!ComponentsInChildren_object__441952)
        return;
      if (!ComponentsInChildren_object__441952->max_length)
        return;
      v101 = 1;
      if (IsAlready(this, obj, mode, 1))
        return;
      break;
    default:
      return;
  }
  v100 = ComponentsInChildren_object__441952;
  v15 = 0;
  p_list = &this->list;
  v17 = 84;
    goto LABEL_22;
LABEL_18:
  else
  {
    if (v15 < TABLEMAX)
      goto LABEL_23;
  }
  if (mode == 4)
  {
    v20 = *p_list;
    white = get_white();
    *(v20 + v17 - 28) = white;
    if (v101 == 3)
    {
      v36 = v13->m_Items[0];
      v105 = get_white();
      (v36->klass->vtable[23].methodPtr)(
        v36,
        v36->klass->vtable[23].v105.r,
        v105.g,
        v105.b,
        v105.a);
      v25 = this;
      Component_GUILayer = GetComponent_GUILayer_(v13->m_Items[0]);
      v28 = v13->m_Items[0];
    }
    else
    {
      if (v101 == 2)
      {
        v31 = v102->m_Items[0];
        v31[3] = get_white();
        v25 = this;
        Component_GUILayer = GetComponent_GUILayer_(v102->m_Items[0]);
        v34 = GetComponent_GUILayer_(v102->m_Items[0]);
        goto LABEL_54;
      }
      v23 = v100->m_Items[0];
      v104 = get_white();
      (v23->klass->vtable[23].methodPtr)(
        v23,
        v23->klass->vtable[23].v104.r,
        v104.g,
        v104.b,
        v104.a);
      v25 = this;
      Component_GUILayer = GetComponent_GUILayer_(v100->m_Items[0]);
      v28 = v100->m_Items[0];
    }
    v34 = GetComponent_GUILayer_(v28);
LABEL_54:
    v29 = v34;
    goto LABEL_55;
  }
  v25 = this;
  v29 = 0;
  Component_GUILayer = 0;
LABEL_55:
  if (op_Inequality(Component_GUILayer, 0, 0))
    set_enabled(Component_GUILayer, 0);
  if (op_Inequality(v29, 0, 0))
    set_enabled(v29, 0);
  v41 = v25;
  v42 = v100;
  if (mode != 4)
  {
    if (TABLEMAX != v15)
    {
      *(*p_list + v17 - 52) = mode;
      v46 = v101;
      *(*p_list + v17 - 48) = v101;
      *(*p_list + v17 - 44) = obj;
      switch (mode)
      {
        case 1:
          v49 = *p_list;
          v106 = op_Implicit_27186704(pC1.rgba);
          *(v49 + v17 - 28) = v106;
          *(*p_list + v17 - 12) = ((LOBYTE(pC1.rgba) ^ 0xFFu) / 255.0)
                                / FADEFRAME;
          *(*p_list + v17 - 8) = ((BYTE1(pC1.rgba) ^ 0xFFu) / 255.0)
                               / FADEFRAME;
          *(*p_list + v17 - 4) = ((BYTE2(pC1.rgba) ^ 0xFFu) / 255.0)
                               / FADEFRAME;
          v54 = *p_list;
          FADEFRAME = FADEFRAME + 10;
          break;
        case 3:
          v65 = *p_list;
          v108 = op_Implicit_27186704(pC1.rgba);
          *(v65 + v17 - 28) = v108;
          *(*p_list + v17 - 12) = ((128 - LOBYTE(pC1.rgba)) / 255.0)
                                / FADEFRAME;
          *(*p_list + v17 - 8) = ((128 - BYTE1(pC1.rgba)) / 255.0)
                               / FADEFRAME;
          v42 = v100;
          *(*p_list + v17 - 4) = ((128 - BYTE2(pC1.rgba)) / 255.0)
                               / FADEFRAME;
          v54 = *p_list;
          break;
        case 2:
          v58 = *p_list;
          v107 = op_Implicit_27186704(*&pC1.r);
          *(v58 + v17 - 28) = v107;
          *(*p_list + v17 - 12) = ((pC1.r - 128) / 255.0)
                                / (FADEFRAME * 0.25);
          *(*p_list + v17 - 8) = ((pC1.g - 128) / 255.0)
                               / (FADEFRAME * 0.25);
          *(*p_list + v17 - 4) = ((pC1.b - 128) / 255.0)
                               / (FADEFRAME * 0.25);
          v54 = *p_list;
          FADEFRAME = FADEFRAME / 4;
          break;
        default:
          goto LABEL_123;
      }
      v46 = v101;
      *(&v54->obj.klass + v17) = FADEFRAME;
LABEL_123:
      if (v46 == 3)
      {
        v75 = *p_list;
        *(v75 + v17 - 36) = v13->m_Items[0];
        if (mode != 1 && mode != 3)
        {
          if (mode == 2)
          {
            v88 = v13->m_Items[0];
            gray = get_gray();
            *&v96 = gray.r;
            *&v97 = gray.g;
            *&v98 = gray.b;
            *&v99 = gray.a;
            goto LABEL_182;
          }
          goto LABEL_183;
        }
        v88 = v13->m_Items[0];
          goto LABEL_178;
      }
      else
      {
        if (v46 == 2)
        {
          v74 = *p_list;
          *(v74 + v17 - 36) = v102->m_Items[0];
          if (mode == 1 || mode == 3)
          {
            v80 = v102->m_Items[0];
            rgba = pC1.rgba;
          }
          else
          {
            if (mode != 2)
              goto LABEL_183;
            v80 = v102->m_Items[0];
            rgba = *&pC1.r;
          }
          v80[3] = op_Implicit_27186704(rgba);
          goto LABEL_183;
        }
        v71 = v42;
        v72 = *p_list;
        v73 = v71->m_Items[0];
        *(v72 + v17 - 36) = v73;
        if (mode != 1 && mode != 3)
        {
          if (mode == 2)
          {
            v88 = v100->m_Items[0];
            v89 = *&pC1.r;
            goto LABEL_181;
          }
LABEL_183:
          _Add(v41->table, v15);
          return;
        }
        v88 = v100->m_Items[0];
        {
LABEL_178:
        }
      }
      v89 = pC1.rgba;
LABEL_181:
      v110 = op_Implicit_27186704(v89);
      *&v96 = v110.r;
      *&v97 = v110.g;
      *&v98 = v110.b;
      *&v99 = v110.a;
LABEL_182:
      (v88->klass->vtable[23].methodPtr)(v88, v88->klass->vtable[23].v96, v97, v98, v99);
      goto LABEL_183;
    }
  }
}

// 0x13441b0
void StopEffect(TMPEffect *this, void *obj) {
  s64 v5;
  u64 v6;
  struct TMPEffect_TMPData_array *list;
  struct TMPEffect_TMPData_array *v10;
  struct TMPEffect_TMPData_array *v12;
  u64 *v14;

  v5 = 0;
  v6 = 0;
  {
LABEL_6:
  }
  while (v6 < TABLEMAX)
  {
    list = this->list;
    if (list->m_Items[v5].type)
    {
      v10 = this->list;
      if (((v10->m_Items[v5].obj->klass->vtable._0_Equals.methodPtr)(
              v10->m_Items[v5].obj,
              obj,
              v10->m_Items[v5].obj->klass->vtable._0_Equals.method)
          & 1) != 0)
      {
        break;
      }
    }
    ++v6;
    ++v5;
      goto LABEL_6;
  }
  else if (TABLEMAX == v6)
  {
    return;
  }
  v12 = this->list;
  v14 = (&v12->obj.klass + v5 * 56);
  v14[5] = 0;
  v14[6] = 0;
  v14[4] = 0;
  v14[9] = 0;
  v14[10] = 0;
  _Remove(
    this->table,
    v6);
}

// 0x13426c0
void Update(TMPEffect *this) {
  const MethodInfo_1260 **v3;
  s32 v4;
  s32 Item;
  struct TMPEffect_TMPData_array *list;
  s64 v7;
  struct TMPEffect_TMPData_array *v9;
  f32 *v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  struct TMPEffect_TMPData_array *v16;
  struct TMPEffect_TMPData_array *v17;
  struct TMPEffect_TMPData_array *v18;
  s32 s_type;
  struct TMPEffect_TMPData_array *v20;
  Il2CppObject *v22;
  Il2CppClass *v23;
  s64 v24;
  struct TMPEffect_TMPData_array *v25;
  CounterCtr_o *scr;
  CounterCtr_c *klass;
  s64 typeHierarchyDepth;
  char *v30;
  s64 *v31;
  struct TMPEffect_TMPData_array *v33;
  u32 max_length;
  struct TMPEffect_TMPData_array *v35;
  struct TMPEffect_TMPData_array *v39;
  u32 v40;
  struct TMPEffect_TMPData_array *v41;
  struct TMPEffect_TMPData_array *v45;
  s64 v47;
  struct TMPEffect_TMPData_array *v48;
  const MethodInfo_1260 **v49;
  TMPEffect_o *v50;
  f32 g;
  f32 b;
  f32 a;
  f32 *v55;
  struct TMPEffect_TMPData_array *v56;
  char *v58;
  s32 v59;
  bool v60;
  struct TMPEffect_TMPData_array *v61;
  Il2CppClass **v63;
  char *v64;
  s64 *v65;
  char *v66;
  s64 *v67;
  UnityEngine_Color_o v68;
  UnityEngine_Color_o v69;
  u64 v70[2];
  char *v71;

  *&v69.r = 0;
  *&v69.b = 0;
  *&v68.r = 0;
  *&v68.b = 0;
  if (_get_Count(this->table)
    && _get_Count(this->table) >= 1)
  {
    v3 = &Method_System_Collections_Generic_List_int__get_Item__;
    v4 = 0;
    while (1)
    {
      Item = _get_Item(this->table, v4, *v3);
      list = this->list;
      v7 = Item;
      if ((list->m_Items[Item].s_type - 1) > 2)
        goto LABEL_64;
      v9 = this->list;
      v11 = (v9 + 56 * Item);
      v13 = v11[14];
      v12 = v11[15];
      v15 = v11[16];
      v14 = v11[17];
      *&v69.r = __PAIR64__(LODWORD(v12), LODWORD(v13));
      *&v69.b = __PAIR64__(LODWORD(v14), LODWORD(v15));
      if (*(v11 + 8) == 1)
        goto LABEL_36;
      v16 = this->list;
      if (v16->m_Items[Item].type == 3)
      {
LABEL_36:
        v33 = this->list;
        max_length = v33->max_length;
        v35 = this->list;
        v13 = v13 + v33->m_Items[Item].radd;
        v12 = v12 + v35->m_Items[Item].gadd;
        v15 = v15 + v35->m_Items[Item].badd;
        v17 = this->list;
        if (Item >= LODWORD(v17->max_length))
        {
LABEL_42:
        }
      }
      else
      {
        v17 = this->list;
        if (Item >= LODWORD(v17->max_length))
          goto LABEL_42;
      }
      if (v17->m_Items[Item].type == 2)
      {
        v39 = this->list;
        v40 = v39->max_length;
        v41 = this->list;
        v13 = v13 - v39->m_Items[Item].radd;
        v12 = v12 - v41->m_Items[Item].gadd;
        v15 = v15 - v41->m_Items[Item].badd;
        v18 = this->list;
        if (Item >= LODWORD(v18->max_length))
        {
LABEL_49:
        }
      }
      else
      {
        v18 = this->list;
        if (Item >= LODWORD(v18->max_length))
          goto LABEL_49;
      }
      s_type = v18->m_Items[Item].s_type;
      if (s_type == 3)
        break;
      if (s_type == 2)
      {
        sub_19EC630(&v69.r, v13, v12, v15, v14);
        v25 = this->list;
        scr = v25->m_Items[v7].scr;
        if (scr)
        {
          klass = scr->klass;
          if (scr->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != CounterCtr)
          {
            sub_8FC2C0(klass->_1.element_class, CounterCtr, v70);
            if ((v70[0] & 1) != 0)
              v30 = v71;
            else
              v30 = v70 + 1;
            v31 = sub_8C4940(v30);
          }
        }
        SetColor(scr, v69, 0);
        goto LABEL_55;
      }
      if (s_type == 1)
      {
        v20 = this->list;
        v22 = v20->m_Items[Item].scr;
        sub_19EC630(&v68.r, v13, v12, v15, v14);
        v23 = v22->klass;
        if (v22->klass->_2.typeHierarchyDepth < v24 || v23->_2.typeHierarchy[v24 - 1] != TMPro_TextMeshProUGUI)
        {
          sub_8FC2C0(v23->_1.element_class, TMPro_TextMeshProUGUI, v70);
          if ((v70[0] & 1) != 0)
            v64 = v71;
          else
            v64 = v70 + 1;
          v65 = sub_8C4940(v64);
        }
LABEL_54:
        (v23->vtable[23].methodPtr)(v22, v23->vtable[23].v68.r, v68.g, v68.b, v68.a);
        v69 = v68;
      }
LABEL_55:
      v48 = this->list;
      v49 = v3;
      v50 = this;
      g = v69.g;
      b = v69.b;
      a = v69.a;
      v55 = (v48 + 56 * v7);
      v55[14] = v69.r;
      v55[15] = g;
      v55[16] = b;
      v55[17] = a;
      v56 = v50->list;
      this = v50;
      v58 = v56 + 56 * v7;
      v59 = *(v58 + 21) - 1;
      v60 = *(v58 + 21) == 1;
      v3 = v49;
      *(v58 + 21) = v59;
      if (v59 < 0 || v60)
      {
        v61 = v50->list;
        v63 = &v61->obj.klass + 7 * v7;
        v63[5] = 0;
        v63[6] = 0;
        v63[4] = 0;
        v63[9] = 0;
        v63[10] = 0;
        _RemoveAt(v50->table, v4--);
      }
LABEL_64:
      if (++v4 >= _get_Count(this->table))
        return;
    }
    v45 = this->list;
    v22 = v45->m_Items[Item].scr;
    sub_19EC630(&v68.r, v13, v12, v15, v14);
    v23 = v22->klass;
    if (v22->klass->_2.typeHierarchyDepth < v47 || v23->_2.typeHierarchy[v47 - 1] != UnityEngine_UI_Image)
    {
      sub_8FC2C0(v23->_1.element_class, UnityEngine_UI_Image, v70);
      if ((v70[0] & 1) != 0)
        v66 = v71;
      else
        v66 = v70 + 1;
      v67 = sub_8C4940(v66);
    }
    goto LABEL_54;
  }
}
