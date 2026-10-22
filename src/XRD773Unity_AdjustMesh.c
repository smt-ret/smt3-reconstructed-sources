#include "types.h"

typedef struct XRD773Unity_AdjustMesh XRD773Unity_AdjustMesh;

// 0x134c910
void Awake(XRD773Unity_AdjustMesh *this) {
  u64 *v3;
  s32 v4;
  s32 v5;
  s32 v7;
  s32 v8;
  s32 v10;
  s32 v11;
  s32 v13;
  s32 v14;
  System_Array_o *v16;
  u64 *v17;
  UnityEngine_MeshFilter_o *Component_GUILayer;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *parent;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v23;
  UnityEngine_Vector3_o v24;
  s64 v25;
  s32 v26;
  s64 v27;
  s32 v28;
  s64 v29;
  s32 v30;
  s64 v31;
  s32 v32;

  v3 = NewSpecific(UnityEngine_Vector3, 4u);
  v32 = 0;
  v31 = 0;
  sub_8524C0(&v31, -0.5, 0.5, 0.0);
  v4 = HIDWORD(v31);
  v5 = v32;
  *(v3 + 8) = v31;
  *(v3 + 9) = v4;
  *(v3 + 10) = v5;
  v30 = 0;
  v29 = 0;
  sub_8524C0(&v29, 0.5, 0.5, 0.0);
  v7 = HIDWORD(v29);
  v8 = v30;
  *(v3 + 11) = v29;
  *(v3 + 12) = v7;
  *(v3 + 13) = v8;
  v28 = 0;
  v27 = 0;
  sub_8524C0(&v27, -0.5, -0.5, 0.0);
  v10 = HIDWORD(v27);
  v11 = v28;
  *(v3 + 14) = v27;
  *(v3 + 15) = v10;
  *(v3 + 16) = v11;
  v26 = 0;
  v25 = 0;
  sub_8524C0(&v25, 0.5, -0.5, 0.0);
  v13 = HIDWORD(v25);
  v14 = v26;
  *(v3 + 17) = v25;
  *(v3 + 18) = v13;
  *(v3 + 19) = v14;
  v16 = NewSpecific(s32, 6u);
  InitializeArray_1543888(v16, Field__PrivateImplementationDetails__1B287FBF8016A1357E0FA5B7B88403B0659ECE97);
  v17 = Allocate(UnityEngine_Mesh);
  _ctor(v17, 0);
  this->mesh = v17;
  MarkDynamic(v17);
  set_subMeshCount(this->mesh, 2);
  set_vertices(this->mesh, v3);
  SetTriangles(this->mesh, v16, 0);
  SetTriangles(this->mesh, v16, 1);
  Component_GUILayer = GetComponent_GUILayer_(this);
  set_sharedMesh(Component_GUILayer, this->mesh);
  transform = get_transform(this, 0);
  parent = get_parent(transform);
  gameObject = get_gameObject(parent);
  this->cam = GetComponent_object_(gameObject);
  this->scl = get_one();
  v23 = get_transform(this, 0);
  v24.z = 0.0;
  *&v24.x = 0;
  sub_8524C0(&v24.x, 0.0, 0.0, 0.5);
  set_localPosition(v23, v24);
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
