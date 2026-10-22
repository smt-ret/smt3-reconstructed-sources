#include "types.h"

typedef struct fldTitleName fldTitleName;

// 0x1478bd0
void Awake(fldTitleName *this) {
  struct UnityEngine_GameObject_array *tree;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  s64 *gameObject;
  s64 *v7;
  struct UnityEngine_GameObject_array *v9;
  UnityEngine_Transform_o *v10;
  UnityEngine_Component_o *v11;
  s64 *v12;
  s64 *v13;
  struct UnityEngine_GameObject_array *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  s64 *v18;
  s64 *v19;
  struct UnityEngine_GameObject_array *v21;
  struct UnityEngine_GameObject_array *v23;
  struct UnityEngine_GameObject_array *v25;

  tree = this->tree;
  this->b_start = 0;
  transform = get_transform(this, 0);
  v5 = Find(transform, "fareain_2nd", 0);
  gameObject = get_gameObject(v5);
  v7 = gameObject;
  tree->m_Items[0] = v7;
  v9 = this->tree;
  v10 = get_transform(this, 0);
  v11 = Find(v10, "fareain_1st", 0);
  v12 = get_gameObject(v11);
  v13 = v12;
  v9->m_Items[1] = v13;
  v15 = this->tree;
  v16 = get_transform(this, 0);
  v17 = Find(v16, "fareain_1st_amara", 0);
  v18 = get_gameObject(v17);
  v19 = v18;
  v15->m_Items[2] = v19;
  v21 = this->tree;
  SetActive(v21->m_Items[0], 0, 0);
  v23 = this->tree;
  SetActive(v23->m_Items[1], 0, 0);
  v25 = this->tree;
  SetActive(v25->m_Items[2], 0, 0);
  this->animtime = 0;
  this->b_amara = 0;
}

// 0x1479200
bool IsFinished(fldTitleName *this) {
  struct UnityEngine_GameObject_array *tree;
  s64 v4;
  Il2CppObject *Component_object;

  tree = this->tree;
  if (this->b_amara)
    v4 = 2;
  else
    v4 = 1;
  Component_object = GetComponent_object_(tree->m_Items[v4]);
  return get_isPlaying(Component_object, 0);
}

// 0x1479290
bool IsFinishedMini(fldTitleName *this) {
  struct UnityEngine_GameObject_array *tree;
  Il2CppObject *Component_object;

  tree = this->tree;
  Component_object = GetComponent_object_(tree->m_Items[0]);
  return get_isPlaying(Component_object, 0);
}

// 0x1478e40
void SetSprite(fldTitleName *this, bool amara, void **a, void **b) {
  struct UnityEngine_GameObject_array *tree;
  u32 max_length;
  UnityEngine_GameObject_o **v12;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_GUILayer_o *v19;
  UnityEngine_Component_o *v21;
  UnityEngine_GUILayer_o *v22;
  UnityEngine_GUILayer_o *v23;
  struct UnityEngine_GameObject_array *v25;
  UnityEngine_Transform_o *v27;
  UnityEngine_Component_o *v28;
  UnityEngine_GUILayer_o *v29;
  UnityEngine_GUILayer_o *v30;

  if (a && a->max_length)
  {
    tree = this->tree;
    max_length = tree->max_length;
    if (amara)
    {
      v12 = &tree->m_Items[2];
    }
    else
    {
      v12 = &tree->m_Items[1];
    }
    transform = get_transform(*v12, 0);
    this->b_amara = amara;
    v16 = transform;
    if (op_Inequality(v16, 0, 0))
    {
      v17 = Find(v16, "areaname", 0);
      Component_GUILayer = GetComponent_GUILayer_(v17);
      v19 = Component_GUILayer;
      set_sprite(Component_GUILayer, a->m_Items[0]);
      (v19->klass[2].vtable._0_Equals.methodPtr)(v19, v19->klass[2].vtable._0_Equals.method);
      v21 = Find(v16, "areaname_g", 0);
      v22 = GetComponent_GUILayer_(v21);
      v23 = v22;
      set_sprite(v22, a->m_Items[0]);
      (v23->klass[2].vtable._0_Equals.methodPtr)(v23, v23->klass[2].vtable._0_Equals.method);
    }
  }
  if (b && b->max_length)
  {
    v25 = this->tree;
    v27 = get_transform(v25->m_Items[0], 0);
    v28 = Find(v27, "areaname", 0);
    v29 = GetComponent_GUILayer_(v28);
    v30 = v29;
    set_sprite(v29, b->m_Items[0]);
    (v30->klass[2].vtable._0_Equals.methodPtr)(v30, v30->klass[2].vtable._0_Equals.method);
  }
}

// 0x14790b0
void StartAnim(fldTitleName *this, bool in1st, s32 timer) {
  struct UnityEngine_GameObject_array *tree;
  s64 v8;
  UnityEngine_GameObject_o *v10;
  Il2CppObject *Component_object;
  s64 *v12;
  struct UnityEngine_GameObject_array *v14;
  System_String_o *v16;

  if ((byte_3F59858 & 1) != 0)
  {
    tree = this->tree;
    if (in1st)
    {
LABEL_3:
      if (this->b_amara)
        v8 = 2;
      else
        v8 = 1;
      v10 = tree->m_Items[v8];
      SetActive(v10, 1, 0);
      Component_object = GetComponent_object_(v10);
      v12 = &"fareain_1st";
      goto LABEL_15;
    }
  }
  else
  {
    tree = this->tree;
    if (in1st)
      goto LABEL_3;
  }
  SetActive(tree->m_Items[0], 1, 0);
  v14 = this->tree;
  Component_object = GetComponent_object_(v14->m_Items[0]);
  v12 = &"fareain_2nd";
LABEL_15:
  v16 = *v12;
  this->animname = *v12;
  Play_8766576(Component_object, v16);
  this->b_start = 1;
  this->animtime = timer;
}

// 0x14791f0
void Update(fldTitleName *this) {
  ;
}
