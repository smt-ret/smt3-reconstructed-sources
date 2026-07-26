#include "types.h"

typedef struct FieldChrHD FieldChrHD;
typedef struct RippleEffect RippleEffect;
typedef struct UiHDMesh UiHDMesh;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbFormation_t nbFormation_t;

static f32 st_alf;

void BasicLight_Char_Color(char *objname, evtUnitHandle_t *hunit, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim);
void BattleLight_Char_Color(char *objname, nbFormation_t *unit_form, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim);
void CampLight_Char_Color(char *objname, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim);
bool ChkUseSceneLight(evtUnitHandle_t **h);
void FieldLight_Char_Color(char *objname, evtUnitHandle_t *hunit, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim);
void GetLight(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *bias, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 unity_x, f32 unity_y, f32 unity_z);
void KageMove(FieldChrHD *this);
void KageSetMatInit(FieldChrHD *this, void *rootobj);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SceneLight_Char_Color(char *objname, evtUnitHandle_t *hunit, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim);
void SceneLight_Char_SetUp(char *objname);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetFog(FieldChrHD *this, f32 fogflg);
void SetLayerAll(FieldChrHD *this, void *rootobj);
void SetLayerAll2(FieldChrHD *this, void *rootobj, s32 setlayer);
void SetLightAll(UiHDMesh *this, void *rootobj);
void SetMatInit(UiHDMesh *this, void *rootobj);
void Update(RippleEffect *this);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
bool evtBitCheck(s32 no);
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit);
s32 fldLightMaChk(void);
s32 mdlGetMotionMinorNumForUnity(evtUnitHandle_t **h, s32 layer);

// 0x1139270
void AddMatList(FieldChrHD *this, void *mat) {
  bool HasProperty;
  System_Collections_Generic_List_float__o *modeop_list;
  f32 Float;
  const MethodInfo_1260 *v11;
  UnityEngine_Object_o *shader;
  System_String_o *name;
  bool v16;
  struct System_Collections_Generic_List_float__o *Initial_BlendPower_list;
  f32 v20;
  const MethodInfo_1260 *v21;
  System_Collections_Generic_List_float__o *v22;

  HasProperty = HasProperty(mat, id_ModeOp);
  modeop_list = this->modeop_list;
  if (HasProperty)
  {
    Float = GetFloat(mat, id_ModeOp, 0);
    v11 = Method_System_Collections_Generic_List_float__Add__;
  }
  else
  {
    v11 = Method_System_Collections_Generic_List_float__Add__;
    Float = -1.0;
  }
  _Add(modeop_list, Float, v11);
  shader = get_shader(mat);
  name = get_name(shader);
  if (Equals_5234480(name, StringLiteral_4818))
  {
    v16 = HasProperty(mat, id_BlendPower);
    Initial_BlendPower_list = this->Initial_BlendPower_list;
    if (v16)
    {
      v20 = GetFloat(mat, id_BlendPower, 0);
      v21 = Method_System_Collections_Generic_List_float__Add__;
    }
    else
    {
      v21 = Method_System_Collections_Generic_List_float__Add__;
      v20 = -1.0;
    }
    v22 = Initial_BlendPower_list;
  }
  else
  {
    v22 = this->Initial_BlendPower_list;
    v21 = Method_System_Collections_Generic_List_float__Add__;
    v20 = -1.0;
  }
  _Add(v22, v20, v21);
}

// 0x1137390
void Awake(FieldChrHD *this) {
    SetMatInit(0, 0);
    Update(0);
    SetFog(0, 0);
    SceneLight_Char_SetUp(0);
}

// 0x113c620
void ChangeBlend(FieldChrHD *this, f32 blendop) {
  long f64 v3;
  s32 v5;
  System_WeakReference_o *Item;

  v3 = *&blendop;
  if (_get_Count(this->mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v5);
      (this->klass->vtable._14_SetupMaterialWithBlendOp.methodPtr)(
        this,
        Item,
        this->klass->vtable._14_SetupMaterialWithBlendOp.v3);
      ++v5;
    }
    while (v5 < _get_Count(this->mat_list));
  }
}

// 0x113b6f0
bool ChkMotion(FieldChrHD *this, s32 motion) {
  struct nbFormation_t_o *unit_form;
  evtUnitHandle_t_o **p_hunit;

  unit_form = this->unit_form;
  if (!unit_form)
    return 0;
  p_hunit = &unit_form->hunit;
  return mdlGetMotionMinorNumForUnity(p_hunit, 0) == motion;
}

// 0x113b690
f32 GetBattle(FieldChrHD *this) {
  return this->mode_battle;
}

// 0x113b7b0
evtUnitHandle_t *GetEveUnit(FieldChrHD *this) {
  return this->hunit;
}

// 0x113b6e0
nbFormation_t *GetForm(FieldChrHD *this) {
  return this->unit_form;
}

// 0x113c370
f32 GetTransparent(FieldChrHD *this) {
  return st_alf;
}

// 0x113b6a0
s32 IsBattleQueue(FieldChrHD *this) {
  return this->mode_battle == 1.0;
}

// 0x113ade0
void KageMove(FieldChrHD *this) {
}

// 0x113b3e0
void KageSetMatInit(FieldChrHD *this, void *rootobj) {
  UnityEngine_Transform_o *transform;
  s32 v6;
  UnityEngine_Transform_o *v7;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *v10;
  UnityEngine_Renderer_o *Component_GUILayer;
  UnityEngine_Material_array *sharedMaterials;
  il2cpp_array_size_t max_length;
  u32 *v16;
  u64 v17;
  s64 **m_Items;
  s64 *v21;
  UnityEngine_Transform_o *v23;
  s64 *v24;

  v24 = 0;
  transform = get_transform(rootobj, 0);
  if (get_childCount(transform) >= 1)
  {
    v6 = 0;
    do
    {
      v7 = get_transform(rootobj, 0);
      Child = GetChild(v7, v6);
      gameObject = get_gameObject(Child);
      v10 = get_transform(gameObject, 0);
      Component_GUILayer = GetComponent_GUILayer_(v10);
      if (op_Inequality(Component_GUILayer, 0, 0))
      {
        sharedMaterials = get_sharedMaterials(Component_GUILayer);
        max_length = sharedMaterials->max_length;
        v16 = sharedMaterials;
        if (max_length >= 1)
        {
          v17 = 0;
          m_Items = sharedMaterials->m_Items;
          do
          {
            v24 = *m_Items;
            (this->klass->vtable._17_GetListMatelial.methodPtr)(
              this,
              this->kage_mat_list,
              &v24,
              this->klass->vtable._17_GetListMatelial.method);
            v21 = v24;
            max_length = v16[6];
            ++v17;
            *m_Items++ = v21;
          }
          while (v17 < max_length);
        }
        set_sharedMaterials(Component_GUILayer, v16);
        set_shadowCastingMode(Component_GUILayer, 0);
        set_receiveShadows(Component_GUILayer, 0);
      }
      KageSetMatInit(this, gameObject);
      ++v6;
      v23 = get_transform(rootobj, 0);
    }
    while (v6 < get_childCount(v23));
  }
}

// 0x113b980
void KageSetRenserQueue(FieldChrHD *this, s32 OverlayQueue) {
  s32 v5;
  System_WeakReference_o *Item;

  if (_get_Count(this->kage_mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      Item = _get_Item(
               this->kage_mat_list,
               v5);
      set_renderQueue(Item, OverlayQueue);
      ++v5;
    }
    while (v5 < _get_Count(this->kage_mat_list));
  }
}

// 0x113ba30
void KageSet_Battle(FieldChrHD *this, f32 x, f32 z, f32 size, f32 alp) {
  this->btl_marukage_pos.x = x;
  this->btl_marukage_pos.y = 0.09;
  this->btl_marukage_pos.z = z;
  this->btl_marukage_scl = size;
  this->btl_marukage_alp = alp;
}

// 0x113b7d0
void KageSet_Size_BlendPower(FieldChrHD *this, f32 OverlaySize, f32 aBlendPower) {
  UnityEngine_Object_o *chr_model;
  UnityEngine_Object_o *kage_model;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v11;
  s32 v12;
  System_WeakReference_o *Item;
  UnityEngine_Vector3_o localScale;
  UnityEngine_Vector3_o v17;

  chr_model = this->chr_model;
  if (op_Inequality(chr_model, 0, 0))
  {
    kage_model = this->kage_model;
    if (op_Inequality(kage_model, 0, 0))
    {
      transform = get_transform(this->chr_model, 0);
      localScale = get_localScale(transform);
      v11 = get_transform(this->kage_model, 0);
      v17.x = localScale.x * OverlaySize;
      v17.y = localScale.y;
      v17.z = localScale.z * OverlaySize;
      set_localScale(v11, v17);
    }
  }
  if (_get_Count(this->kage_mat_list) >= 1)
  {
    v12 = 0;
    do
    {
      Item = _get_Item(
               this->kage_mat_list,
               v12);
      SetFloat_27246832(Item, id_BlendPower, aBlendPower);
      ++v12;
    }
    while (v12 < _get_Count(this->kage_mat_list));
  }
}

// 0x113c060
void RetTransparent(FieldChrHD *this) {
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  UnityEngine_Object_o *v6;
  System_String_o *v7;
  f32 mode_battle;
  s32 v9;
  System_WeakReference_o *Item;
  f32 v11;
  System_WeakReference_o *v18;
  f32 v19;

  LODWORD(st_alf) = 1065353216;
  if (_get_Count(this->modeop_list))
  {
    gameObject = get_gameObject(this);
    name = get_name(gameObject);
    if (!Equals_5234480(name, StringLiteral_4825))
    {
      v6 = get_gameObject(this);
      v7 = get_name(v6);
      if (!Equals_5234480(v7, StringLiteral_4826))
      {
        mode_battle = this->mode_battle;
        if (_get_Count(this->mat_list) >= 1)
        {
          v9 = 0;
          if (mode_battle == 0.0)
          {
            do
            {
              Item = _get_Item(
                       this->mat_list,
                       v9);
              v11 = _get_Item(
                      this->modeop_list,
                      v9);
              (this->klass->vtable._14_SetupMaterialWithBlendOp.methodPtr)(
                this,
                Item,
                this->klass->vtable._14_SetupMaterialWithBlendOp.v11);
              SetFloat_27246832(Item, id_AlfPower, 1.0);
              SetFloat_27246832(Item, id_AlfRGBPower, 0.0);
              if (HasProperty(Item, id_StencilComp))
              {
                SetInt_27247136(Item, id_StencilComp, 8);
              }
              ++v9;
            }
            while (v9 < _get_Count(this->mat_list));
          }
          else
          {
            do
            {
              v18 = _get_Item(
                      this->mat_list,
                      v9);
              v19 = _get_Item(
                      this->modeop_list,
                      v9);
              (this->klass->vtable._14_SetupMaterialWithBlendOp.methodPtr)(
                this,
                v18,
                this->klass->vtable._14_SetupMaterialWithBlendOp.v19);
              SetFloat_27246832(v18, id_AlfPower, 1.0);
              SetFloat_27246832(v18, id_AlfRGBPower, 0.0);
              ++v9;
            }
            while (v9 < _get_Count(this->mat_list));
          }
        }
      }
    }
  }
}

// 0x113b620
void SetBattle(FieldChrHD *this, f32 flg) {
  bool v3;

  v3 = flg > 6 || ((1 << flg) & 0x4A) == 0;
  this->mode_battle = flg;
  if (!v3)
  {
    *&this->renderqueue_add = 0xC4E00000C1CLL;
    this->chg_rq = ((this->klass->vtable._15_ChangeRenderQueue.methodPtr)(
                             this,
                             this->klass->vtable._15_ChangeRenderQueue.method)
                         & 1) == 0;
  }
}

// 0x113c6e0
void SetBlendPower(FieldChrHD *this, f32 aBlendPower) {
  s32 v5;
  System_WeakReference_o *Item;

  if (_get_Count(this->mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v5);
      SetFloat(Item, StringLiteral_4829, aBlendPower);
      ++v5;
    }
    while (v5 < _get_Count(this->mat_list));
  }
}

// 0x113c8e0
void SetCampD0x55(FieldChrHD *this) {
  long f64 v2;
  s32 v4;
  System_WeakReference_o *Item;

  if (_get_Count(this->mat_list) >= 1)
  {
    LODWORD(v2) = 0;
    v4 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v4);
      if (HasProperty(Item, id_ModeOp))
      {
        if (GetFloat(Item, id_ModeOp, 0) == 4.0)
        {
          SetFloat_27246832(Item, id_ModeOp, 0.0);
          (this->klass->vtable._14_SetupMaterialWithBlendOp.methodPtr)(
            this,
            Item,
            this->klass->vtable._14_SetupMaterialWithBlendOp.v2);
        }
      }
      ++v4;
    }
    while (v4 < _get_Count(this->mat_list));
  }
}

// 0x113c7c0
void SetCombineClipY(FieldChrHD *this, f32 y) {
  this->CombineClipY = y;
}

// 0x113c7d0
void SetCombine_AtlusMat_Color(FieldChrHD *this, f32 BlendPowerMul) {
  s32 v5;
  System_WeakReference_o *Item;
  f32 v7;

  if (_get_Count(this->mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      if (_get_Item(
             this->Initial_BlendPower_list,
             v5) >= 0.0)
      {
        Item = _get_Item(
                 this->mat_list,
                 v5);
        v7 = _get_Item(
               this->Initial_BlendPower_list,
               v5);
        SetFloat(Item, StringLiteral_4829, v7 * BlendPowerMul);
      }
      ++v5;
    }
    while (v5 < _get_Count(this->mat_list));
  }
}

// 0x113b7a0
void SetEveUnit(FieldChrHD *this, evtUnitHandle_t *hunit_tmp) {
  this->hunit = hunit_tmp;
}

// 0x1139160
void SetFog(FieldChrHD *this, f32 fogflg) {
  s32 v5;
  System_WeakReference_o *Item;

  if (_get_Count(this->modeop_list)
    && _get_Count(this->mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v5);
      SetFloat_27246832(Item, id_Use_FogOff, fogflg);
      ++v5;
    }
    while (v5 < _get_Count(this->mat_list));
  }
}

// 0x113b6c0
void SetForm(FieldChrHD *this, nbFormation_t *form) {
  this->unit_form = form;
  if (form)
    this->hunit = form->hunit;
}

// 0x113c530
void SetGray(FieldChrHD *this, f32 flag) {
  s32 v5;
  System_WeakReference_o *Item;

  if (_get_Count(this->mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v5);
      SetFloat_27246832(Item, id_mDirect, flag);
      ++v5;
    }
    while (v5 < _get_Count(this->mat_list));
  }
}

// 0x113b7c0
void SetLayer(FieldChrHD *this, s32 layer_tmp) {
  this->layer = layer_tmp;
  this->layerset = 0;
}

// 0x113ad30
void SetLayerAll(FieldChrHD *this, void *rootobj) {
  UnityEngine_Transform_o *transform;
  s32 v6;
  UnityEngine_Transform_o *v7;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v11;

  transform = get_transform(rootobj, 0);
  if (get_childCount(transform) >= 1)
  {
    v6 = 0;
    do
    {
      v7 = get_transform(rootobj, 0);
      Child = GetChild(v7, v6);
      gameObject = get_gameObject(Child);
      set_layer(gameObject, this->layer);
      SetLayerAll(this, gameObject);
      ++v6;
      v11 = get_transform(rootobj, 0);
    }
    while (v6 < get_childCount(v11));
  }
}

// 0x113b050
void SetLayerAll2(FieldChrHD *this, void *rootobj, s32 setlayer) {
  UnityEngine_Transform_o *transform;
  s32 v8;
  UnityEngine_Transform_o *v9;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v13;

  if (!op_Equality(rootobj, 0, 0))
  {
    set_layer(rootobj, setlayer);
    transform = get_transform(rootobj, 0);
    if (get_childCount(transform) >= 1)
    {
      v8 = 0;
      do
      {
        v9 = get_transform(rootobj, 0);
        Child = GetChild(v9, v8);
        gameObject = get_gameObject(Child);
        set_layer(gameObject, setlayer);
        SetLayerAll2(this, gameObject, setlayer);
        ++v8;
        v13 = get_transform(rootobj, 0);
      }
      while (v8 < get_childCount(v13));
    }
    this->layerset = 1;
  }
}

// 0x113b250
void SetLayerAll_FadeModeOff(FieldChrHD *this, void *rootobj) {
  s32 layer;
  s32 FadeMode_bkup_layer;

  if (!op_Equality(rootobj, 0, 0) && this->FadeMode_bkup_layer)
  {
    layer = get_layer(rootobj);
    FadeMode_bkup_layer = this->FadeMode_bkup_layer;
    if (layer != FadeMode_bkup_layer)
      SetLayerAll2(this, rootobj, FadeMode_bkup_layer);
  }
}

// 0x113b180
void SetLayerAll_FadeModeOn(FieldChrHD *this, void *rootobj, s32 setlayer) {
  if (!op_Equality(rootobj, 0, 0) && get_layer(rootobj) != setlayer)
  {
    this->FadeMode_bkup_layer = get_layer(rootobj);
    SetLayerAll2(this, rootobj, setlayer);
  }
}

// 0x1139630
void SetLightAll(FieldChrHD *this, void *rootobj) {
    SDF_VU0__Retdds3ColorItoF(0, 0);
    BattleLight_Char_Color(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    ChkUseSceneLight(0);
    SceneLight_Char_Color(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    BasicLight_Char_Color(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    evtBitCheck(0);
    dds3GetActiveScene();
    dds3SearchSceneBasic(0, 0, 0);
    evtGetUnitHandle2(0);
    CampLight_Char_Color(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    FieldLight_Char_Color(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    GetLight(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x1137ca0
void SetMatInit(FieldChrHD *this, void *rootobj, bool blendshape_clr) {
}

// 0x113b310
void SetModelObject(FieldChrHD *this, void *chr, void *kage) {
  u64 *v7;

  this->chr_model = chr;
  this->kage_model = kage;
  if (op_Inequality(kage, 0, 0))
  {
    v7 = Allocate(System_Collections_Generic_List_Material_);
    __ctor(v7);
    this->kage_mat_list = v7;
    KageSetMatInit(this, this->kage_model);
  }
}

// 0x113c3e0
void SetRGB(FieldChrHD *this, u32 abgr) {
  s32 v5;
  System_WeakReference_o *Item;
  UnityEngine_Vector4_o v9;

  v9 = SDF_VU0__Retdds3ColorItoF(abgr, 128.0);
  if (_get_Count(this->mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v5);
      SetFloat_27246832(Item, id_all_r, v9.x);
      SetFloat_27246832(Item, id_all_g, v9.y);
      SetFloat_27246832(Item, id_all_b, v9.z);
      ++v5;
    }
    while (v5 < _get_Count(this->mat_list));
  }
}

// 0x113c7b0
void SetRasterLevel(FieldChrHD *this, f32 val) {
  this->rasterLevel = val;
}

// 0x113ba50
void SetTransparent(FieldChrHD *this, u32 rgba, f32 alfrgb, s32 queueoffset) {
    SDF_VU0__Retdds3ColorItoF(0, 0);
    SetActive(0, 0);
}

// 0x1139620
void SetUpDateDI(FieldChrHD *this) {
  this->update_di = 1;
}

// 0x1139430
void Start(FieldChrHD *this) {
    SetLightAll(0, 0);
}

// 0x1138680
void Update(FieldChrHD *this) {
    evtBitCheck(0);
    fldLightMaChk();
    SetLayerAll(0, 0);
    SetLightAll(0, 0);
    KageMove(0);
}

// 0x113ad20
void UpdateGlobal(FieldChrHD *this) {
  Update(this);
}
