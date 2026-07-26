#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_CommonSprite XRD773Unity_CommonSprite;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct XRD773Unity_GraphicManager_DRAW XRD773Unity_GraphicManager_DRAW;

struct XRD773Unity_GraphicManager {
    bool update;
    void palette_mat[UNKNOWN_ARRAY_SIZE];
    void normal_mat[UNKNOWN_ARRAY_SIZE];
    void plane_mat[UNKNOWN_ARRAY_SIZE];
    void extra_mat[UNKNOWN_ARRAY_SIZE];
    void commonmesh_mat[UNKNOWN_ARRAY_SIZE];
    void render_texture[UNKNOWN_ARRAY_SIZE];
    s32 rt_side;
    s32 layer;
};

struct XRD773Unity_GraphicManager_DRAW {
    s32 value__;
};

static s32 main_tex_id;
static s32 palette_id;

static XRD773Unity_GraphicManager *instance;

// 0x130fce0
void Continue(XRD773Unity_GraphicManager *this) {
  this->update = 0;
}

// 0x1310050
void *GetDisplayTexture(XRD773Unity_GraphicManager *this) {
  struct UnityEngine_RenderTexture_array *render_texture;

  render_texture = this->render_texture;
  return render_texture->m_Items[0];
}

// 0x1310290
s32 GetDrawMode(XRD773Unity_GraphicManager_CommonObject *this) {
  return this->draw_mode;
}

// 0x1310000
void *GetExtraMat(XRD773Unity_GraphicManager *this, s32 no) {
  struct UnityEngine_Material_array *extra_mat;

  extra_mat = this->extra_mat;
  return extra_mat->m_Items[no];
}

// 0x130fd10
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk) {
  struct dds3DefaultMain_o *kernelObject;
  Il2CppObject *commonMesh;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v11;
  s32 layer;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GUILayer_o *Component_GUILayer;
  struct UnityEngine_Material_array *commonmesh_mat;
  XRD773Unity_CommonMesh_o *v17;

  commonMesh = kernelObject->commonMesh;
  transform = get_transform(kernelObject->ObjectsFolder3D, 0);
  v11 = Instantiate_object__425520(commonMesh, transform);
  layer = this->layer;
  v13 = v11;
  if (layer != -1)
    set_layer(v11, layer);
  v14 = get_transform(v13, 0);
  Component_GUILayer = GetComponent_GUILayer_(v14);
  commonmesh_mat = this->commonmesh_mat;
  v17 = Component_GUILayer;
  set_sharedMaterial(Component_GUILayer[9].monitor, commonmesh_mat->m_Items[index]);
  return v17;
}

// 0x130fe60
XRD773Unity_CommonMesh *GetMesh2D(XRD773Unity_GraphicManager *this, s32 index) {
  struct dds3DefaultMain_o *kernelObject;
  Il2CppObject *commonMesh;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v10;
  UnityEngine_Component_o *v11;
  UnityEngine_GUILayer_o *Component_GUILayer;
  struct UnityEngine_Material_array *commonmesh_mat;
  XRD773Unity_CommonMesh_o *v14;

  commonMesh = kernelObject->commonMesh;
  transform = get_transform(kernelObject->ObjectsFolder2D, 0);
  v10 = Instantiate_object__425520(commonMesh, transform);
  v11 = get_transform(v10, 0);
  Component_GUILayer = GetComponent_GUILayer_(v11);
  commonmesh_mat = this->commonmesh_mat;
  v14 = Component_GUILayer;
  set_sharedMaterial(Component_GUILayer[9].monitor, commonmesh_mat->m_Items[index]);
  return v14;
}

// 0x130f770
void *GetNormalMat(XRD773Unity_GraphicManager *this, s32 mode) {
  struct UnityEngine_Material_array *commonmesh_mat;

  commonmesh_mat = this->commonmesh_mat;
  return commonmesh_mat->m_Items[mode];
}

// 0x1310340
void *GetPalette(XRD773Unity_GraphicManager_CommonObject *this) {
  return this->palette;
}

// 0x130f7c0
void *GetPaletteMat(XRD773Unity_GraphicManager *this, s32 mode) {
  struct UnityEngine_Material_array *palette_mat;

  palette_mat = this->palette_mat;
  return palette_mat->m_Items[mode];
}

// 0x130ffb0
void *GetPlaneMat(XRD773Unity_GraphicManager *this, s32 mode) {
  struct UnityEngine_Material_array *plane_mat;

  plane_mat = this->plane_mat;
  return plane_mat->m_Items[mode];
}

// 0x130fd00
XRD773Unity_CommonSprite *GetSprite(XRD773Unity_GraphicManager *this) {
  return 0;
}

// 0x130fcf0
bool IsUpdate(XRD773Unity_GraphicManager *this) {
  return this->update;
}

// 0x13100b0
void LateUpdate(XRD773Unity_GraphicManager_CommonObject *this) {
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v4;

  if (!this->chk_hide)
  {
    if (!get_Instance()->update)
  }
  else if (!get_Instance(XRD773Unity_GraphicManager)->update)
  {
    (this->klass->vtable._65535__ctor.methodPtr)(this, this->klass->vtable._65535__ctor.method);
    return;
  }
  if (!this->hide)
  {
    this->hide = 1;
  }
  gameObject = get_gameObject(this);
  if (get_activeSelf(gameObject))
  {
    v4 = get_gameObject(this);
    SetActive(v4, 0, 0);
  }
  this->hide = 1;
}

// 0x1310300
void ResetPalette(XRD773Unity_GraphicManager_CommonObject *this) {
  XRD773Unity_GraphicManager_CommonObject_c *klass;

  if (this->use_palette)
  {
    klass = this->klass;
    this->use_palette = 0;
    (klass[1]._1.name)(this, this->draw_mode, klass[1]._1.namespaze);
  }
  this->palette = 0;
}

// 0x13101a0
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act) {
  _BOOL4 v3;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v6;

  v3 = act;
  gameObject = get_gameObject(this);
  if (((get_activeSelf(gameObject) ^ v3) & 1) != 0)
  {
    v6 = get_gameObject(this);
    SetActive(v6, v3, 0);
  }
  this->hide = !v3;
}

// 0x1310200
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act) {
  this->chk_hide = act;
  this->hide = 1;
}

// 0x1310250
void SetDrawMode(XRD773Unity_GraphicManager_CommonObject *this, s32 mode) {
  if (this->draw_mode != mode)
  {
    (this->klass[1]._1.name)(this);
    this->draw_mode = mode;
  }
}

// 0x130ffa0
void SetLayerOff(XRD773Unity_GraphicManager *this) {
  this->layer = -1;
}

// 0x130ff90
void SetLayerOn(XRD773Unity_GraphicManager *this, s32 setlayer) {
  this->layer = setlayer;
}

// 0x1310220
void SetMaterial(XRD773Unity_GraphicManager_CommonObject *this, void *material) {
  (this->klass[1]._1.image)(this, material, this->klass[1]._1.gc_desc);
  this->draw_mode = 5;
}

// 0x1310350
void SetName(XRD773Unity_GraphicManager_CommonObject *this, char *name) {
  set_name(this, name);
}

// 0x13102a0
void SetPalette(XRD773Unity_GraphicManager_CommonObject *this, void *palette) {
  if (this->use_palette)
  {
    this->palette = palette;
  }
  else
  {
    this->use_palette = 1;
    (this->klass[1]._1.name)(this, this->draw_mode, this->klass[1]._1.namespaze);
    this->palette = palette;
  }
}

// 0x130fcd0
void Update(XRD773Unity_GraphicManager *this) {
  this->update = 1;
}
