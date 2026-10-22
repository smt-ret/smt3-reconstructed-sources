#include "types.h"

typedef struct ChildHD ChildHD;
typedef struct ModelHD ModelHD;

// 0xfe2990
void CallOnDestroy(ChildHD *this) {
  struct System_Collections_Generic_List_Material__o *mat_list;

  mat_list = this->mat_list;
  if (mat_list)
  {
    _Clear(mat_list);
    this->mat_list = 0;
  }
}

// 0xfe2b40
char *GetMatelialKey(ChildHD *this) {
  return "(cHD)";
}

// 0xfe2b90
void *GetOptionMaterial(ChildHD *this, s32 idx) {
  UnityEngine_Material_o *result;

  result = this->mat_list;
  if (result)
  {
    if (_get_Count(result) <= idx)
      return 0;
    else
      return _get_Item(
               this->mat_list,
               idx);
  }
  return result;
}

// 0xfe29f0
ModelHD *GetRoot(ChildHD *this) {
  UnityEngine_Object_o *root;
  UnityEngine_Transform_o *transform;
  UnityEngine_Object_o *Component_GUILayer;

  root = this->root;
  if (op_Equality(root, 0, 0))
  {
    transform = get_transform(this, 0);
    while (1)
    {
      transform = get_parent(transform);
      if (!op_Inequality(transform, 0, 0))
        break;
      Component_GUILayer = GetComponent_GUILayer_(transform);
      if (op_Inequality(Component_GUILayer, 0, 0))
      {
        this->root = (*&Component_GUILayer->klass[1]._2.thread_static_fields_size)(
                              Component_GUILayer,
                              *&Component_GUILayer->klass[1]._2.flags);
        return this->root;
      }
    }
  }
  return this->root;
}

// 0xfe2980
void OnDestroy(ChildHD *this) {
  (this->klass->vtable._4_CallOnDestroy.methodPtr)(this, this->klass->vtable._4_CallOnDestroy.method);
}

// 0xfe2b30
void UpdateOption(ChildHD *this) {
  ;
}
