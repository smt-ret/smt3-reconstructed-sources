#include "types.h"

typedef struct ModelHD ModelHD;

void DelAnime(void *trn);

// 0x129f750
void DelAnime(void *trn) {
  UnityEngine_Object_o *Component_GUILayer;
  UnityEngine_Object_o *v7;
  UnityEngine_Object_o *v10;
  UnityEngine_Object_o *v13;
  s64 *Enumerator;
  UnityEngine_Transform_o *v16;
  UnityEngine_Transform_c *v17;
  UnityEngine_Transform_c *klass;
  s64 typeHierarchyDepth;
  char *v20;
  s64 *v21;
  s64 *Interface;
  u64 v23[3];

  Component_GUILayer = GetComponent_GUILayer_(trn);
  if (op_Inequality(Component_GUILayer, 0, 0))
  {
    Destroy_27360000(Component_GUILayer);
  }
  v7 = GetComponent_GUILayer_(trn);
  if (op_Inequality(v7, 0, 0))
  {
    Destroy_27360000(v7);
  }
  v10 = GetComponent_GUILayer_(trn);
  if (op_Inequality(v10, 0, 0))
  {
    Destroy_27360000(v10);
  }
  v13 = GetComponent_GUILayer_(trn);
  if (op_Inequality(v13, 0, 0))
  {
    Destroy_27360000(v13);
  }
  Enumerator = GetEnumerator(trn);
  while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
  {
    v16 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
    if (v16)
    {
      klass = v16->klass;
      if (v16->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, v23);
        if ((v23[0] & 1) != 0)
          v20 = v23[2];
        else
          v20 = v23 + 1;
        v21 = sub_8C4940(v20);
      }
    }
    DelAnime(v16, v17);
  }
  Interface = QueryInterface(Enumerator, System_IDisposable);
  if (Interface)
    sub_22F10(0, System_IDisposable, Interface);
}

// 0x129f560
ModelHD *GetCopy(void *rootobj) {
  u64 *v3;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v5;
  UnityEngine_Transform_o *parent;
  UnityEngine_Object_o *Component_object;
  UnityEngine_Object_c *klass;
  const char *namespaze;
  u64 v12;
  Il2CppObject *v14;

  v3 = Allocate(UnityEngine_GameObject);
  _ctor(v3, "copy", 0);
  transform = get_transform(v3, 0);
  v5 = get_transform(rootobj, 0);
  parent = get_parent(v5);
  set_parent(transform, parent);
  Component_object = GetComponent_object_(rootobj);
  if (op_Inequality(Component_object, 0, 0))
  {
    klass = Component_object[1].klass;
    namespaze = klass->_1.namespaze;
    if (namespaze >= 1)
    {
      v12 = 0;
      do
      {
        v14 = *(&klass->_1.byval_arg.data + v12);
        if (get_activeInHierarchy(v14))
        {
          Instantiate_object__425664(v14, transform, 1);
        }
        LODWORD(namespaze) = klass->_1.namespaze;
        ++v12;
      }
      while (v12 < namespaze);
    }
  }
  DelAnime(transform);
  if (get_childCount(transform) >= 1)
    return AddComponent_object_(v3);
  Destroy_27360000(v3);
  return 0;
}
