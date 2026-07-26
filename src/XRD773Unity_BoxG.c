#include "types.h"

typedef struct XRD773Unity_BoxG XRD773Unity_BoxG;
typedef struct XRD773Unity_BoxObjectPool_object_ XRD773Unity_BoxObjectPool_object_;

void *_Get(XRD773Unity_BoxObjectPool_object_ *this);
void _Release(XRD773Unity_BoxObjectPool_object_ *this, void *element);

// 0x134cd90
void ModifyMesh(XRD773Unity_BoxG *this, void *vh) {
    _Get(0);
    _Release(0, 0);
}

// 0x134d310
void Refresh(XRD773Unity_BoxG *this) {
  UnityEngine_Object_o *graphic;
  UnityEngine_UI_Graphic_o *v5;

  graphic = get_graphic(this);
  if (op_Inequality(graphic, 0, 0))
  {
    v5 = get_graphic(this);
    (v5->klass->vtable._32_get_material.methodPtr)(v5, v5->klass->vtable._32_get_material.method);
  }
}
