#include "types.h"

typedef struct XRD773Unity_BoxG XRD773Unity_BoxG;
typedef struct XRD773Unity_BoxObjectPool_object_ XRD773Unity_BoxObjectPool_object_;

void *_Get(XRD773Unity_BoxObjectPool_object_ *this);
void _Release(XRD773Unity_BoxObjectPool_object_ *this, void *element);

// 0x134cd90
void ModifyMesh(XRD773Unity_BoxG *this, void *vh) {
  System_Collections_Generic_List_T__o *v6;
  s32 rgba;
  f32 z;
  f32 x;
  f32 y;
  s32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  s32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  s32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  s32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  s32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  UnityEngine_UIVertex_o v32;
  UnityEngine_UIVertex_o v33;
  UnityEngine_UIVertex_o v34;
  UnityEngine_UIVertex_o v35;
  UnityEngine_UIVertex_o v36;
  UnityEngine_UIVertex_o v37;
  s64 v38;
  s64 v39;
  s64 v40;
  s64 v41;
  s64 v42;
  s64 v43;
  f32 w;
  UnityEngine_UIVertex_o v45;

  w = 0.0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  if (((this->klass->vtable._9_IsActive.methodPtr)(this, this->klass->vtable._9_IsActive.method) & 1) != 0)
  {
    {
    }
    v6 = _Get();
    GetUIVertexStream(vh, v6);
    if (_get_Count(v6) == 6)
    {
      _get_Item(
        &v37,
        v6,
        0);
      w = v37.tangent.w;
      v42 = *&v37.normal.z;
      v43 = *&v37.tangent.y;
      v41 = *&v37.normal.x;
      v39 = *&v37.uv1.y;
      v40 = *&v37.uv2.y;
      v38 = *&v37.uv0.y;
      rgba = op_Implicit(this->c_LD, 0).rgba;
      z = this->p_LD.z;
      x = this->uv_LD.x;
      y = this->uv_LD.y;
      *&v45.position.x = *&this->p_LD.x;
      v45.tangent.w = w;
      v45.color.rgba = rgba;
      v45.position.z = z;
      *&v45.tangent.y = v43;
      *&v45.normal.z = v42;
      *&v45.normal.x = v41;
      *&v45.color.r = x;
      v45.uv0.x = y;
      *&v45.uv2.y = v40;
      *&v45.uv1.y = v39;
      *&v45.uv0.y = v38;
      _set_Item(v6, 0, &v45);
      _get_Item(
        &v36,
        v6,
        5);
      w = v36.tangent.w;
      v42 = *&v36.normal.z;
      v43 = *&v36.tangent.y;
      v41 = *&v36.normal.x;
      v39 = *&v36.uv1.y;
      v40 = *&v36.uv2.y;
      v38 = *&v36.uv0.y;
      v11 = op_Implicit(this->c_LD, 0).rgba;
      v12 = this->p_LD.z;
      v13 = this->uv_LD.x;
      v14 = this->uv_LD.y;
      *&v45.position.x = *&this->p_LD.x;
      v45.tangent.w = w;
      v45.color.rgba = v11;
      v45.position.z = v12;
      *&v45.tangent.y = v43;
      *&v45.normal.z = v42;
      *&v45.normal.x = v41;
      *&v45.color.r = v13;
      v45.uv0.x = v14;
      *&v45.uv2.y = v40;
      *&v45.uv1.y = v39;
      *&v45.uv0.y = v38;
      _set_Item(v6, 5, &v45);
      _get_Item(
        &v35,
        v6,
        1);
      w = v35.tangent.w;
      v42 = *&v35.normal.z;
      v43 = *&v35.tangent.y;
      v41 = *&v35.normal.x;
      v39 = *&v35.uv1.y;
      v40 = *&v35.uv2.y;
      v38 = *&v35.uv0.y;
      v15 = op_Implicit(this->c_LU, 0).rgba;
      v16 = this->p_LU.z;
      v17 = this->uv_LU.x;
      v18 = this->uv_LU.y;
      *&v45.position.x = *&this->p_LU.x;
      v45.tangent.w = w;
      v45.color.rgba = v15;
      v45.position.z = v16;
      *&v45.tangent.y = v43;
      *&v45.normal.z = v42;
      *&v45.normal.x = v41;
      *&v45.color.r = v17;
      v45.uv0.x = v18;
      *&v45.uv2.y = v40;
      *&v45.uv1.y = v39;
      *&v45.uv0.y = v38;
      _set_Item(v6, 1, &v45);
      _get_Item(
        &v34,
        v6,
        2);
      w = v34.tangent.w;
      v42 = *&v34.normal.z;
      v43 = *&v34.tangent.y;
      v41 = *&v34.normal.x;
      v39 = *&v34.uv1.y;
      v40 = *&v34.uv2.y;
      v38 = *&v34.uv0.y;
      v19 = op_Implicit(this->c_RU, 0).rgba;
      v20 = this->p_RU.z;
      v21 = this->uv_RU.x;
      v22 = this->uv_RU.y;
      *&v45.position.x = *&this->p_RU.x;
      v45.tangent.w = w;
      v45.color.rgba = v19;
      v45.position.z = v20;
      *&v45.tangent.y = v43;
      *&v45.normal.z = v42;
      *&v45.normal.x = v41;
      *&v45.color.r = v21;
      v45.uv0.x = v22;
      *&v45.uv2.y = v40;
      *&v45.uv1.y = v39;
      *&v45.uv0.y = v38;
      _set_Item(v6, 2, &v45);
      _get_Item(
        &v33,
        v6,
        3);
      w = v33.tangent.w;
      v42 = *&v33.normal.z;
      v43 = *&v33.tangent.y;
      v41 = *&v33.normal.x;
      v39 = *&v33.uv1.y;
      v40 = *&v33.uv2.y;
      v38 = *&v33.uv0.y;
      v23 = op_Implicit(this->c_RU, 0).rgba;
      v24 = this->p_RU.z;
      v25 = this->uv_RU.x;
      v26 = this->uv_RU.y;
      *&v45.position.x = *&this->p_RU.x;
      v45.tangent.w = w;
      v45.color.rgba = v23;
      v45.position.z = v24;
      *&v45.tangent.y = v43;
      *&v45.normal.z = v42;
      *&v45.normal.x = v41;
      *&v45.color.r = v25;
      v45.uv0.x = v26;
      *&v45.uv2.y = v40;
      *&v45.uv1.y = v39;
      *&v45.uv0.y = v38;
      _set_Item(v6, 3, &v45);
      _get_Item(
        &v32,
        v6,
        4);
      w = v32.tangent.w;
      v42 = *&v32.normal.z;
      v43 = *&v32.tangent.y;
      v41 = *&v32.normal.x;
      v39 = *&v32.uv1.y;
      v40 = *&v32.uv2.y;
      v38 = *&v32.uv0.y;
      v27 = op_Implicit(this->c_RD, 0).rgba;
      v28 = this->p_RD.z;
      v29 = this->uv_RD.x;
      v30 = this->uv_RD.y;
      *&v45.position.x = *&this->p_RD.x;
      v45.tangent.w = w;
      v45.color.rgba = v27;
      v45.position.z = v28;
      *&v45.tangent.y = v43;
      *&v45.normal.z = v42;
      *&v45.normal.x = v41;
      *&v45.color.r = v29;
      v45.uv0.x = v30;
      *&v45.uv2.y = v40;
      *&v45.uv1.y = v39;
      *&v45.uv0.y = v38;
      _set_Item(v6, 4, &v45);
      Clear(vh, 0);
      AddUIVertexTriangleStream(vh, v6);
      {
      }
      _Release(v6);
    }
  }
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
