#include "types.h"

typedef struct ModelHD ModelHD;

void DelAnime(void *trn);

// 0x129f750
void DelAnime(void *trn) {
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
  _ctor(v3, StringLiteral_5201, 0);
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
