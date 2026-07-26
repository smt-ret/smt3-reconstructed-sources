#include "types.h"

typedef struct BlendHD BlendHD;
typedef struct FieldChrHD FieldChrHD;

void ChangeBlend(FieldChrHD *this, f32 blendop);

// 0xfdf380
void ChangeBlend(BlendHD *this, f32 blendop) {
  UnityEngine_Object_o *rootObject;
  Il2CppObject *Component_object;

  rootObject = this->rootObject;
  if (op_Inequality(rootObject, 0, 0))
  {
    Component_object = GetComponent_object_(this->rootObject);
    if (op_Inequality(Component_object, 0, 0))
      ChangeBlend(Component_object, blendop);
  }
}

// 0xfdf360
void Start(BlendHD *this) {
  ;
}

// 0xfdf370
void Update(BlendHD *this) {
  ;
}
