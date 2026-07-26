#include "types.h"

typedef struct XRD773Unity_AdjustMesh XRD773Unity_AdjustMesh;

// 0x134c910
void Awake(XRD773Unity_AdjustMesh *this) {
}

// 0x134ccb0
void LateUpdate(XRD773Unity_AdjustMesh *this) {
  f32 fieldOfView;
  f32 v5;
  UnityEngine_Camera_o *cam;
  UnityEngine_Transform_o *transform;

  fieldOfView = get_fieldOfView(this->cam);
  v5 = tanf((fieldOfView * 0.5) * 0.017453);
  cam = this->cam;
  this->scl.y = v5;
  this->scl.x = v5 * get_aspect(cam);
  transform = get_transform(this, 0);
  set_localScale(transform, this->scl);
}

// 0x134cc10
void OnDestroy(XRD773Unity_AdjustMesh *this) {
  UnityEngine_Object_o *mesh;
  UnityEngine_MeshFilter_o *Component_GUILayer;

  mesh = this->mesh;
  Destroy_27360000(mesh);
  Component_GUILayer = GetComponent_GUILayer_(this);
  set_sharedMesh(Component_GUILayer, 0);
  this->mesh = 0;
}
