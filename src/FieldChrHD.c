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
  if (Equals_5234480(name, "Atlus/AtlusMat"))
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
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  f32 v9;
  UnityEngine_Object_o *v10;
  System_String_o *v11;
  bool v12;
  UnityEngine_Object_o *v13;
  System_String_o *v14;
  UnityEngine_Object_o *v15;
  System_String_o *v16;
  UnityEngine_Object_o *v17;
  System_String_o *v18;
  UnityEngine_Object_o *v19;
  System_String_o *v20;
  UnityEngine_GameObject_o *v21;
  s32 v23;
  System_WeakReference_o *Item;
  s32 id_Toon;
  UnityEngine_Object_o *v30;
  System_String_o *v31;
  UnityEngine_Object_o *v32;
  System_String_o *v33;
  UnityEngine_Object_o *v34;
  System_String_o *v35;
  UnityEngine_Object_o *v36;
  System_String_o *v37;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *Child;
  UnityEngine_Object_o *v42;
  System_String_o *v43;
  UnityEngine_Object_o *v44;
  System_String_o *v45;
  UnityEngine_Object_o *v47;
  System_String_o *v48;
  UnityEngine_Object_o *v49;
  System_String_o *v50;
  UnityEngine_Object_o *v51;
  System_String_o *v52;
  UnityEngine_Object_o *v53;
  System_String_o *v54;
  UnityEngine_Object_o *v55;
  System_String_o *v56;
  UnityEngine_Object_o *v57;
  System_String_o *v58;
  UnityEngine_Object_o *v59;
  System_String_o *v60;
  UnityEngine_Object_o *v61;
  System_String_o *v62;
  UnityEngine_Object_o *v63;
  System_String_o *v64;
  UnityEngine_Object_o *v65;
  System_String_o *v66;
  UnityEngine_Object_o *v68;
  System_String_o *v69;
  UnityEngine_Object_o *v70;
  System_String_o *v71;
  UnityEngine_Object_o *v72;
  System_String_o *v73;
  UnityEngine_Object_o *v74;
  System_String_o *v75;
  UnityEngine_Object_o *v78;
  System_String_o *v79;
  UnityEngine_Object_o *v80;
  System_String_o *v81;
  s32 v82;
  System_WeakReference_o *v83;
  System_String_o *v84;
  UnityEngine_Object_o *v85;
  System_String_o *v86;
  UnityEngine_Object_o *v87;
  System_String_o *v88;
  UnityEngine_Object_o *v89;
  System_String_o *v91;
  UnityEngine_Quaternion_o v92;

  this->layerset = 0;
  v3 = Allocate(System_Collections_Generic_Dictionary_string__GameObject_);
  PropertySheet____ctor(v3);
  this->allobject = v3;
  v4 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v4);
  this->mat_list = v4;
  v5 = Allocate(System_Collections_Generic_List_float_);
  __ctor(v5);
  this->modeop_list = v5;
  v6 = Allocate(System_Collections_Generic_List_float_);
  __ctor(v6);
  this->Initial_BlendPower_list = v6;
  this->lightobj_off = 0;
  gameObject = get_gameObject(this);
  name = get_name(gameObject);
  if (Equals_5234480(name, "npc_gomo_e694"))
  {
    v9 = 0.3;
  }
  else
  {
    v10 = get_gameObject(this);
    v11 = get_name(v10);
    v12 = Equals_5234480(v11, "npc_luci_e694");
    v9 = 0.3;
    if (!v12)
      v9 = 0.0;
  }
  this->_ToonTypeStart_Offset = v9;
  v13 = get_gameObject(this);
  v14 = get_name(v13);
  if (Equals_5234480(v14, "npc_mane_e636"))
    this->_ToonTypeStart_Offset = -0.5;
  v15 = get_gameObject(this);
  v16 = get_name(v15);
  if (Equals_5234480(v16, "mark_wpc(Clone)", 0))
  {
    this->mode_lmap_player = 1;
    this->toon_rim = 27.0;
  }
  v17 = get_gameObject(this);
  v18 = get_name(v17);
  if (Equals_5234480(v18, "mark_npc(Clone)", 0))
  {
    this->mode_lmap_npc = 1;
    this->toon_rim = 27.0;
  }
  v19 = get_gameObject(this);
  v20 = get_name(v19);
  if (Equals_5234480(v20, "devil_0x47_e634_0"))
    this->SpecularType = 1;
  v21 = get_gameObject(this);
  SetMatInit(this, v21, 1);
  if (this->chg_rq)
    (this->klass->vtable._15_ChangeRenderQueue.methodPtr)(this, this->klass->vtable._15_ChangeRenderQueue.method);
  if (_get_Count(this->mat_list) >= 1)
  {
    v23 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v23);
      SetTexture_27248080(Item, id_Toon, kernelObject->HighContrastMode_ToneTexture);
      ++v23;
    }
    while (v23 < _get_Count(this->mat_list));
  }
  this->fog_calc_type = 0;
  this->fog_near_rimit = 1;
  v30 = get_gameObject(this);
  v31 = get_name(v30);
  if (Equals_5234480(v31, "devil_0x123_e681_0"))
  {
    this->fog_calc_type = 1;
    this->devil_0x123_e681_0 = 1;
  }
  v32 = get_gameObject(this);
  v33 = get_name(v32);
  if (Equals_5234480(v33, "e726_lucifer"))
    (this->klass->vtable._24_SetGray.methodPtr)(this, this->klass->vtable._24_SetGray.2.0);
  v34 = get_gameObject(this);
  v35 = get_name(v34);
  if (!Equals_5234480(v35, "mani_e697"))
  {
    v36 = get_gameObject(this);
    v37 = get_name(v36);
    if (Contains(v37, "mani_e697", 0))
    {
      this->fog_near_rimit = 0;
      this->mode_battle = 2.0;
      transform = get_transform(this, 0);
      Child = GetChild(transform, 0);
      {
      }
      v92 = Euler(-90.0, -30.0, 0.0);
      set_rotation(Child, v92);
      Update(this);
    }
  }
  v42 = get_gameObject(this);
  v43 = get_name(v42);
  if (Equals_5234480(v43, "e697_field01"))
    this->fog_near_rimit = 0;
  v44 = get_gameObject(this);
  v45 = get_name(v44);
  if (Equals_5234480(v45, "e635_tukue"))
    goto LABEL_43;
  v47 = get_gameObject(this);
  v48 = get_name(v47);
  if (Equals_5234480(v48, "e634_sinen_a")
    || (v49 = get_gameObject(this),
        v50 = get_name(v49),
        Equals_5234480(v50, "e634_sinen_b"))
    || (v51 = get_gameObject(this),
        v52 = get_name(v51),
        Equals_5234480(v52, "e635_sinen_c"))
    || (v53 = get_gameObject(this),
        v54 = get_name(v53),
        Equals_5234480(v54, "e635_sinen_d")))
  {
LABEL_43:
    this->fog_near_rimit = 0;
    this->mode_battle = 2.0;
    Update(this);
  }
  v55 = get_gameObject(this);
  v56 = get_name(v55);
  if (Equals_5234480(v56, "mani_e632"))
    this->e632_mani = 1;
  v57 = get_gameObject(this);
  v58 = get_name(v57);
  if (Equals_5234480(v58, "e634_sinen_a")
    || (v59 = get_gameObject(this),
        v60 = get_name(v59),
        Equals_5234480(v60, "e634_sinen_b"))
    || (v61 = get_gameObject(this),
        v62 = get_name(v61),
        Equals_5234480(v62, "e635_sinen_c"))
    || (v63 = get_gameObject(this),
        v64 = get_name(v63),
        Equals_5234480(v64, "e635_sinen_d")))
  {
    this->e635_sinen = 1;
  }
  v65 = get_gameObject(this);
  v66 = get_name(v65);
  if (Equals_5234480(v66, "e655_field1")
    || (v68 = get_gameObject(this),
        v69 = get_name(v68),
        Equals_5234480(v69, "e655_field2"))
    || (v70 = get_gameObject(this),
        v71 = get_name(v70),
        Equals_5234480(v71, "e655_field")))
  {
    this->fog_near_rimit = 0;
    this->mode_battle = 2.0;
    Update(this);
  }
  v72 = get_gameObject(this);
  v73 = get_name(v72);
  if (Contains(v73, "e655_siren_s", 0))
    this->fog_near_rimit = 0;
  v74 = get_gameObject(this);
  v75 = get_name(v74);
  if (Contains(v75, "player_tatoo_e655", 0))
  {
    this->fog_near_rimit = 0;
    this->mode_battle = 2.0;
    SetFog(this, 0.0);
    Update(this);
  }
  v78 = get_gameObject(this);
  v79 = get_name(v78);
  if (Equals_5234480(v79, "dante_e723_020")
    || (v80 = get_gameObject(this),
        v81 = get_name(v80),
        Equals_5234480(v81, "dante_e723_030")))
  {
    this->mode_dante_e723 = 1;
    if (_get_Count(this->mat_list) >= 1)
    {
      v82 = 0;
      while (1)
      {
        v83 = _get_Item(
                this->mat_list,
                v82);
        v84 = get_name(v83);
        if (op_Equality(v84, "Material #291(mHD)", 0))
          break;
        if (++v82 >= _get_Count(this->mat_list))
          goto LABEL_67;
      }
      this->mode_dante_e723_Mat_kosinuno = v82;
    }
  }
LABEL_67:
  v85 = get_gameObject(this);
  v86 = get_name(v85);
  if (Contains(v86, "raidou_e730", 0)
    || (v87 = get_gameObject(this),
        v88 = get_name(v87),
        Contains(v88, "dante_e730", 0)))
  {
    this->fog_near_rimit = 0;
  }
  v89 = get_gameObject(this);
  v91 = get_name(v89);
  SceneLight_Char_SetUp(v91);
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
  UnityEngine_Object_o *chr_model;
  UnityEngine_Object_o *kage_model;
  f32 mode_battle;
  UnityEngine_Transform_o *v7;
  UnityEngine_Transform_o *v8;
  s32 v9;
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v14;
  f32 v15;
  f32 v16;
  UnityEngine_Transform_o *v17;
  UnityEngine_Vector3_o v18;
  UnityEngine_Vector3_o v19;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v21;

  v19.z = 0.0;
  *&v19.x = 0;
  v18.z = 0.0;
  *&v18.x = 0;
  chr_model = this->chr_model;
  if (op_Inequality(chr_model, 0, 0))
  {
    kage_model = this->kage_model;
    if (op_Inequality(kage_model, 0, 0))
    {
      mode_battle = this->mode_battle;
      if (mode_battle == 0.0 || mode_battle == 7.0)
      {
        transform = get_transform(this->chr_model, 0);
        position = get_position(transform);
        v14 = get_transform(this, 0);
        v15 = (get_position(v14).y + 0.01) + 0.08;
        v16 = position.z - this->kage_offset;
        v17 = get_transform(this->kage_model, 0);
        v21.x = position.x;
        v21.y = v15;
        v21.z = v16;
        set_position(v17, v21);
      }
      else
      {
        sub_8524C0(&v19.x, this->btl_marukage_pos.x, this->btl_marukage_pos.y, this->btl_marukage_pos.z);
        v7 = get_transform(this->kage_model, 0);
        set_position(v7, v19);
        sub_8524C0(&v18.x, this->btl_marukage_scl, 1.0, this->btl_marukage_scl);
        v8 = get_transform(this->kage_model, 0);
        set_localScale(v8, v18);
        if (_get_Count(this->kage_mat_list) >= 1)
        {
          v9 = 0;
          do
          {
            Item = _get_Item(
                     this->kage_mat_list,
                     v9);
            SetFloat_27246832(Item, id_BlendPower, this->btl_marukage_alp * 100.0);
            ++v9;
          }
          while (v9 < _get_Count(this->kage_mat_list));
        }
      }
    }
  }
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
    if (!Equals_5234480(name, "npc_051_0"))
    {
      v6 = get_gameObject(this);
      v7 = get_name(v6);
      if (!Equals_5234480(v7, "npc_052_1"))
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
      SetFloat(Item, "_BlendPower", aBlendPower);
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
        SetFloat(Item, "_BlendPower", v7 * BlendPowerMul);
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
  f32 mode_battle;
  struct nbFormation_t_o *unit_form;
  struct evtUnitHandle_t_o *hunit;
  struct evtUnitHandle_t_o *v8;
  struct evtUnitHandle_t_o *v9;
  System_String_o *name;
  nbFormation_t_o *v12;
  System_String_o *v13;
  dds3Basic_t_o *player;
  evtUnitHandle_t_o *v16;
  struct evtUnitHandle_t_o *v18;
  struct sdf3DLight_t_array *fld_player_lights;
  struct sdf3DLight_t_array *v22;
  struct sdf3DLight_t_array *v24;
  struct sdf3DLight_t_array *v26;
  struct sdf3DLight_t_array *v28;
  struct sdf3DLight_t_array *v30;
  System_String_o *v33;
  evtUnitHandle_t_o *v34;
  System_String_o *v35;
  f32 *p_v0_x;
  f32 *p_v0_y;
  s32 v38;
  System_WeakReference_o *Item;
  s32 id_ColorAmbient;
  s32 id_ToonType;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  UnityEngine_GameObject_o *v55;
  Il2CppObject *Component_object;
  struct sdf3DLight_t_array *dds3DirLights;
  struct sdf3DLight_t_array *v62;
  struct sdf3DLight_t_array *v64;
  struct sdf3DLight_t_array *v66;
  struct sdf3DLight_t_array *v68;
  struct sdf3DLight_t_array *v70;
  struct evtUnitHandle_t_o *v72;
  System_String_o *v73;
  evtUnitHandle_t_o *v75;
  System_String_o *v76;
  struct System_Int32_array *IntVariable;
  u32 v82;
  dds3Basic_t_o *v83;
  dds3Basic_t_o *v85;
  evtUnitHandle_t_o *UnitHandle2;
  evtUnitHandle_t_o *v87;
  f32 l0_r;
  f32 v89;
  f32 v90;
  f32 v91;
  System_String_o *v93;
  struct evtUnitHandle_t_o *v94;
  struct evtUnitHandle_t_o *v95;
  System_String_o *v96;
  evtUnitHandle_t_o *v98;
  System_String_o *v99;
  struct evtUnitHandle_t_o *v100;
  struct evtUnitHandle_t_o *v101;
  f32 bias;
  bool v103;
  f32 v104;
  System_String_o *v106;
  evtUnitHandle_t_o *v108;
  System_String_o *v109;
  struct evtUnitHandle_t_o *v110;
  struct evtUnitHandle_t_o *v111;
  f32 fog_r;
  f32 *p_bias;
  UnityEngine_Transform_o *transform;
  f32 x;
  UnityEngine_Transform_o *v116;
  f32 y;
  UnityEngine_Transform_o *v118;
  f32 z;
  f32 v121;
  s32 v122;
  s32 v123;
  f32 *a0_b;
  f32 *a0_r;
  f32 *p_l0_r;
  System_String_o *v127;
  nbFormation_t_o *v129;
  System_String_o *v130;
  f32 v131;
  f32 *l0_b;
  f32 *a0_g;
  f32 *l0_g;
  f32 *l0_ga;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v137;
  UnityEngine_Color_o v138;
  UnityEngine_Vector4_o v139;
  UnityEngine_Color_o v140;
  UnityEngine_Color_o v141;
  UnityEngine_Color_o v142;
  UnityEngine_Color_o v143;
  UnityEngine_Vector4_o v144;
  UnityEngine_Color_o v145;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v147;
  UnityEngine_Vector4_o v148;
  UnityEngine_Vector4_o v149;
  UnityEngine_Vector4_o v150;
  UnityEngine_Vector4_o v151;
  UnityEngine_Vector4_o v152;
  UnityEngine_Vector4_o v153;
  UnityEngine_Vector4_o v154;
  UnityEngine_Vector4_o v155;
  UnityEngine_Vector4_o v156;
  UnityEngine_Vector4_o v157;
  UnityEngine_Vector4_o v158;
  UnityEngine_Color_o v159;

  *&v145.r = 0;
  *&v145.b = 0;
  pBasic = 0;
  memset(&v137, 0, sizeof(v137));
  *&v144.x = 0;
  *&v144.z = 0;
  *&v143.r = 0;
  *&v143.b = 0;
  *&v142.r = 0;
  *&v142.b = 0;
  *&v141.r = 0;
  *&v141.b = 0;
  *&v140.r = 0;
  *&v140.b = 0;
  *&v139.x = 0;
  *&v139.z = 0;
  *&v138.r = 0;
  *&v138.b = 0;
  mode_battle = this->mode_battle;
  if (mode_battle != 0.0 && mode_battle != 7.0)
  {
    if (mode_battle == 1.0)
    {
      unit_form = this->unit_form;
      if (unit_form)
      {
        hunit = unit_form->hunit;
        if (hunit)
        {
          this->hunit = hunit;
          v147 = SDF_VU0__Retdds3ColorItoF(hunit->NowLightRGB, 128.0);
          v8 = this->hunit;
          this->l0_r = v147.x;
          this->l0_g = v147.y;
          this->l0_b = v147.z;
          this->l0_a = 1.0;
          this->v0_x = v8->NowLightDir.x / 100.0;
          this->v0_y = v8->NowLightDir.y / -100.0;
          this->v0_z = v8->NowLightDir.z / 100.0;
          v148 = SDF_VU0__Retdds3ColorItoF(v8->NowAmbientRGB, 128.0);
          v9 = this->hunit;
          this->a0_r = v148.x;
          this->a0_g = v148.y;
          this->a0_b = v148.z;
          this->a0_a = 1.0;
          this->soften = v9->soften;
          this->bias = v9->bias;
          name = get_name(rootobj);
          v12 = this->unit_form;
          v13 = name;
          BattleLight_Char_Color(v13, v12, &this->l0_r, &this->l0_g, &this->l0_b, &this->v0_x, &this->v0_y, &this->v0_z, &this->a0_r, &this->a0_g, &this->a0_b, &this->soften, &this->bias, &this->toon_div, &this->toon_rim);
        }
      }
      goto LABEL_44;
    }
    if (mode_battle == 2.0)
    {
      if (this->hunit)
      {
        if (ChkUseSceneLight(&this->hunit) || this->e632_mani)
        {
          this->l0_r = dds3DirLights->m_Items[0]->color.x;
          v62 = dds3DirLights;
          this->l0_g = v62->m_Items[0]->color.y;
          v64 = dds3DirLights;
          this->l0_b = v64->m_Items[0]->color.z;
          this->l0_a = 1.0;
          v66 = dds3DirLights;
          this->v0_x = v66->m_Items[0]->v.x;
          v68 = dds3DirLights;
          this->v0_y = -v68->m_Items[0]->v.y;
          v70 = dds3DirLights;
          this->v0_z = v70->m_Items[0]->v.z;
          this->a0_r = dds3Ambient.x;
          this->a0_g = dds3Ambient.y;
          this->a0_b = dds3Ambient.z;
          this->a0_a = 1.0;
          v72 = this->hunit;
          this->soften = fminf(v72->soften, 20.0) + 0.001;
          this->bias = v72->bias * -1.1;
          v73 = get_name(rootobj);
          v75 = this->hunit;
          v76 = v73;
          SceneLight_Char_Color(v76, v75, &this->l0_r, &this->l0_g, &this->l0_b, &this->v0_x, &this->v0_y, &this->v0_z, &this->a0_r, &this->a0_g, &this->a0_b, &this->soften, &this->bias, &this->toon_div, &this->toon_rim);
        }
        else
        {
          v155 = SDF_VU0__Retdds3ColorItoF(this->hunit->NowLightRGB, 128.0);
          v100 = this->hunit;
          this->l0_r = v155.x;
          this->l0_g = v155.y;
          this->l0_b = v155.z;
          this->l0_a = 1.0;
          this->v0_x = v100->NowLightDir.x / 100.0;
          this->v0_y = v100->NowLightDir.y / -100.0;
          this->v0_z = v100->NowLightDir.z / 100.0;
          v156 = SDF_VU0__Retdds3ColorItoF(v100->NowAmbientRGB, 128.0);
          v101 = this->hunit;
          this->a0_r = v156.x;
          this->a0_g = v156.y;
          this->a0_b = v156.z;
          this->a0_a = 1.0;
          this->soften = fminf(v101->soften, 20.0) + 0.001;
          bias = v101->bias;
          LODWORD(v101) = this->player_tatoo_e618;
          this->bias = bias * -1.1;
          if (v101)
          {
            v103 = v156.y == 0.0 || v156.x == 0.0;
            v104 = v156.z / 0.59375;
            if (v103 || v156.z == 0.0)
              v104 = 0.0;
            this->l0_r = v104;
            this->l0_g = v104;
            this->l0_b = v104;
          }
          v106 = get_name(rootobj);
          v108 = this->hunit;
          v109 = v106;
          BasicLight_Char_Color(v109, v108, &this->l0_r, &this->l0_g, &this->l0_b, &this->v0_x, &this->v0_y, &this->v0_z, &this->a0_r, &this->a0_g, &this->a0_b, &this->soften, &this->bias, &this->toon_div, &this->toon_rim);
        }
      }
      goto LABEL_44;
    }
    if (mode_battle == 3.0)
    {
      *&this->l0_r = 0x3F8000003F800000LL;
      *&this->l0_b = 0x3F8000003F800000LL;
      *&this->a0_r = 0x3EE666663EF5C28FLL;
      *&this->a0_b = 0x3F8000003F0A3D71LL;
      *&this->v0_x = 0xBEA3D70A3F5C28F6LL;
      this->v0_z = 0.38;
      *&this->soften = 1088421888;
      l0_g = &this->l0_g;
      this->Exlflg = 0;
      if (evtBitCheck(3717))
      {
        pBasic = dds3GetActiveScene();
        if (pBasic)
        {
          IntVariable = DDS3_GBWK->IntVariable;
          v82 = IntVariable->m_Items[12];
          v83 = dds3SearchSceneBasic(&pBasic, v82, 5u);
          if (v83)
          {
            v85 = v83;
            UnitHandle2 = evtGetUnitHandle2(v85);
            if (UnitHandle2)
            {
              v87 = UnitHandle2;
              v151 = SDF_VU0__Retdds3ColorItoF(UnitHandle2->NowLightRGB, 128.0);
              this->l0_r = v151.x;
              this->l0_g = v151.y;
              this->l0_b = v151.z;
              this->l0_a = 1.0;
              if (v151.x > v151.y || v151.x > v151.z)
              {
                *l0_g = v151.x;
                this->l0_b = v151.x;
              }
              v152 = SDF_VU0__Retdds3ColorItoF(v87->NowAmbientRGB, 128.0);
              l0_r = this->l0_r;
              this->a0_r = v152.x;
              this->a0_g = v152.y;
              this->a0_b = v152.z;
              v89 = (v152.x + 1.0) * l0_r;
              v90 = this->l0_b;
              v91 = (v152.y + 1.0) * this->l0_g;
              this->Exl0_r = v89;
              this->a0_a = 1.0;
              this->Exl0_a = 1.0;
              this->Exl0_g = v91;
              this->Exlflg = 1;
              this->Exl0_b = (v152.z + 1.0) * v90;
            }
          }
        }
      }
      v93 = get_name(rootobj);
      CampLight_Char_Color(v93, &this->l0_r, l0_g, &this->l0_b, &this->v0_x, &this->v0_y, &this->v0_z, &this->a0_r, &this->a0_g, &this->a0_b, &this->soften, &this->bias, &this->toon_div, &this->toon_rim);
      goto LABEL_44;
    }
    if (mode_battle == 4.0)
    {
      v94 = this->hunit;
      if (v94)
      {
        v153 = SDF_VU0__Retdds3ColorItoF(v94->NowLightRGB, 128.0);
        this->l0_a = 1.0;
        v95 = this->hunit;
        this->l0_r = v153.x;
        this->l0_g = v153.y;
        this->l0_b = v153.z;
        this->v0_x = v95->NowLightDir.x / 100.0;
        this->v0_y = v95->NowLightDir.y / -100.0;
        this->v0_z = v95->NowLightDir.z / 100.0;
        v154 = SDF_VU0__Retdds3ColorItoF(v95->NowAmbientRGB, 128.0);
        *&this->a0_a = 0x3F8000003F800000LL;
        this->a0_r = v154.x;
        this->a0_g = v154.y;
        this->a0_b = v154.z;
        this->bias = 0.3;
        v96 = get_name(rootobj);
        v98 = this->hunit;
        v99 = v96;
        FieldLight_Char_Color(v99, v98, &this->l0_r, &this->l0_g, &this->l0_b, &this->v0_x, &this->v0_y, &this->v0_z, &this->a0_r, &this->a0_g, &this->a0_b, &this->soften, &this->bias, &this->toon_div, &this->toon_rim);
      }
      goto LABEL_44;
    }
    if (mode_battle == 5.0)
    {
      v110 = this->hunit;
      if (v110)
      {
        v157 = SDF_VU0__Retdds3ColorItoF(v110->NowLightRGB, 128.0);
        v111 = this->hunit;
        this->l0_r = v157.x;
        this->l0_g = v157.y;
        this->l0_b = v157.z;
        this->l0_a = 1.0;
        this->v0_x = v111->NowLightDir.x / 100.0;
        this->v0_y = v111->NowLightDir.y / -100.0;
        this->v0_z = v111->NowLightDir.z / 100.0;
        v158 = SDF_VU0__Retdds3ColorItoF(v111->NowAmbientRGB, 128.0);
        this->a0_r = v158.x;
        fog_r = this->fog_r;
        this->a0_g = v158.y;
        this->a0_b = v158.z;
        if (fog_r == 0.0 && this->fog_g == 0.0 && this->fog_b == 0.0)
        {
          *&this->fog_r = 0x3D4CCCCD3D4CCCCDLL;
          this->fog_b = 0.05;
        }
        this->a0_a = 1.0;
      }
      goto LABEL_44;
    }
    if (mode_battle != 6.0)
      goto LABEL_44;
    *&this->l0_r = 0x3F8000003F800000LL;
    *&this->l0_b = 0x3F8000003F800000LL;
    a0_g = &this->a0_g;
    *&this->a0_b = 0;
    *&this->a0_r = 0;
    *&this->v0_x = 1065353216;
    l0_ga = &this->v0_z;
    this->v0_z = 0.5;
    *&this->soften = 1088421888;
    p_bias = &this->bias;
    transform = get_transform(this->chr_model, 0);
    x = get_position(transform).x;
    v116 = get_transform(this->chr_model, 0);
    y = get_position(v116).y;
    v118 = get_transform(this->chr_model, 0);
    z = get_position(v118).z;
    GetLight(&this->l0_r, &this->l0_g, &this->l0_b, &this->a0_r, a0_g, &this->a0_b, &this->bias, &this->v0_x, &this->v0_y, l0_ga, x, y, z);
    v121 = *p_bias * -1.1;
    v122 = -1092196762;
    *p_bias = v121;
    if (v121 >= -0.45)
    {
      v122 = 1055286886;
      if (v121 <= 0.45)
      {
        a0_b = &this->a0_b;
        a0_r = &this->a0_r;
        p_l0_r = &this->l0_r;
        v131 = v121;
LABEL_172:
        v127 = get_name(rootobj);
        v129 = this->unit_form;
        v130 = v127;
        BattleLight_Char_Color(v130, v129, p_l0_r, &this->l0_g, &this->l0_b, &this->v0_x, &this->v0_y, l0_ga, a0_r, a0_g, a0_b, &this->soften, &this->bias, &this->toon_div, &this->toon_rim);
        *p_bias = v131;
        goto LABEL_44;
      }
      v123 = 1055286886;
    }
    else
    {
      v123 = -1092196762;
    }
    a0_b = &this->a0_b;
    a0_r = &this->a0_r;
    p_l0_r = &this->l0_r;
    v131 = *&v123;
    *p_bias = v122;
    goto LABEL_172;
  }
  v16 = evtGetUnitHandle2(player);
  this->hunit = v16;
  if (v16)
  {
    v149 = SDF_VU0__Retdds3ColorItoF(v16->NowLightRGB, 128.0);
    this->l0_a = 1.0;
    v18 = this->hunit;
    this->l0_r = v149.x;
    this->l0_g = v149.y;
    this->l0_b = v149.z;
    this->v0_x = v18->NowLightDir.x / 100.0;
    this->v0_y = v18->NowLightDir.y / -100.0;
    this->v0_z = v18->NowLightDir.z / 100.0;
    v150 = SDF_VU0__Retdds3ColorItoF(v18->NowAmbientRGB, 128.0);
    this->a0_r = v150.x;
    this->a0_g = v150.y;
    this->a0_b = v150.z;
  }
  else
  {
    this->l0_r = fld_player_lights->m_Items[0]->color.x;
    v22 = fld_player_lights;
    this->l0_g = v22->m_Items[0]->color.y;
    v24 = fld_player_lights;
    this->l0_b = v24->m_Items[0]->color.z;
    this->l0_a = 0.5;
    v26 = fld_player_lights;
    this->v0_x = v26->m_Items[0]->v.x;
    v28 = fld_player_lights;
    this->v0_y = -v28->m_Items[0]->v.y;
    v30 = fld_player_lights;
    this->v0_z = v30->m_Items[0]->v.z;
    this->a0_r = dds3Ambient.x;
    this->a0_g = dds3Ambient.y;
    this->a0_b = dds3Ambient.z;
  }
  *&this->a0_a = 0x40E000003F800000LL;
  this->bias = 0.0;
  v33 = get_name(rootobj);
  v34 = this->hunit;
  v35 = v33;
  p_v0_x = &this->v0_x;
  p_v0_y = &this->v0_y;
  FieldLight_Char_Color(v35, v34, &this->l0_r, &this->l0_g, &this->l0_b, p_v0_x, p_v0_y, &this->v0_z, &this->a0_r, &this->a0_g, &this->a0_b, &this->soften, &this->bias, &this->toon_div, &this->toon_rim);
  if (this->mode_battle == 7.0)
  {
    this->l0_r = this->l0_r * 0.7;
    this->l0_g = this->l0_g * 0.7;
    this->l0_b = this->l0_b * 0.7;
  }
LABEL_44:
  sub_19EC630(&v145.r, this->l0_r, this->l0_g, this->l0_b, this->l0_a);
  sub_854690(&v144.x, this->v0_x, this->v0_y, this->v0_z, 0.0);
  sub_19EC630(&v143.r, this->a0_r, this->a0_g, this->a0_b, this->a0_a);
  sub_19EC630(&v142.r, this->fog_r * 0.5, this->fog_g * 0.5, this->fog_b * 0.5, this->fog_a);
  sub_19EC630(&v141.r, this->Exl0_r, this->Exl0_g, this->Exl0_b, this->Exl0_a);
  if (_get_Count(this->mat_list) >= 1)
  {
    v38 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v38);
      if (this->mode_dante_e723 && v38 == this->mode_dante_e723_Mat_kosinuno)
      {
        sub_19EC630(&v140.r, this->l0_r * 0.7, this->l0_g * 0.7, this->l0_b * 0.7, this->l0_a);
        sub_854690(&v139.x, -this->v0_x, -this->v0_y, -this->v0_z, 0.0);
        sub_19EC630(&v138.r, this->a0_r * 1.6, this->a0_g * 1.6, this->a0_b * 1.6, this->a0_a);
        SetColor_27247456(Item, id_LightColor, v140);
        SetVector_27247776(Item, id_LightVector, v139);
        v159 = v138;
      }
      else
      {
        SetColor_27247456(Item, id_LightColor, v145);
        SetVector_27247776(Item, id_LightVector, v144);
        v159 = v143;
      }
      SetColor_27247456(Item, id_ColorAmbient, v159);
      SetFloat_27246832(Item, id_ToonType, ToonType + this->soften);
      SetFloat_27246832(
        Item,
        id_ToonTypeStart,
        (ToonTypeStart + this->_ToonTypeStart_Offset) + this->bias,
        0);
      SetFloat_27246832(Item, id_ToonRim, this->toon_rim);
      SetFloat_27246832(Item, id_ToonTypeDiv, this->toon_div);
      SetColor_27247456(Item, id_FogColor, v142);
      SetFloat_27246832(Item, id_FogStart, this->fog_start);
      SetFloat_27246832(Item, id_FogEnd, this->fog_end);
      SetFloat_27246832(Item, id_FogMin, this->fog_min);
      SetFloat_27246832(Item, id_FogDarkSpotDis, this->fog_dark_dis);
      SetVector_27247776(Item, id_FogDarkSpotVec, this->fog_dark_vec);
      SetFloat_27246832(Item, id_RasterLevel, this->rasterLevel);
      SetFloat_27246832(Item, id_CombineClipY, this->CombineClipY);
      if (this->Exlflg)
      {
        if (HasProperty(Item, id_ExLightColor))
        {
          SetColor_27247456(Item, id_ExLightColor, v141);
        }
      }
      ++v38;
    }
    while (v38 < _get_Count(this->mat_list));
  }
  if (!this->lightobj_off)
  {
    Values = Type___get_Values(this->allobject);
    Type___GetEnumerator(&v137, Values);
    while ((sub_4D4B20(&v137) & 1) != 0)
    {
      v55 = sub_4D4CB0(&v137);
      Component_object = GetComponent_object_(v55);
      if (op_Inequality(Component_object, 0, 0))
        SetActive(v55, 0, 0);
    }
    nullsub_48(&v137);
    this->lightobj_off = 1;
  }
}

// 0x1137ca0
void SetMatInit(FieldChrHD *this, void *rootobj, bool blendshape_clr) {
  u32 *v7;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *allobject;
  System_String_o *name;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v11;
  System_String_o *v12;
  UnityEngine_Object_o *animator;
  Il2CppObject *Component_object;
  bool v16;
  UnityEngine_Material_array *sharedMaterials;
  il2cpp_array_size_t max_length;
  u32 *v19;
  u64 v20;
  UnityEngine_Material_o **m_Items;
  UnityEngine_Material_o *v25;
  s32 id_SpecularTex;
  UnityEngine_Texture_o *SpecularTexture2;
  UnityEngine_Object_o *v33;
  System_String_o *v34;
  UnityEngine_Material_o *v35;
  System_String_o *v36;
  f32 v37;
  System_String_o *v38;
  UnityEngine_Material_o *v39;
  Il2CppObject *v42;
  Il2CppObject *sharedMesh;
  Il2CppObject *v45;
  System_String_o *v46;
  System_String_o *v47;
  u64 *v48;
  u32 vertexCount;
  UnityEngine_Vector3_array *v50;
  u32 v51;
  UnityEngine_Vector3_array *v52;
  s32 v53;
  u32 v54;
  UnityEngine_Vector3_array *v55;
  System_Type_o *BlendShapeName;
  u64 v58;
  u64 *p_z;
  u64 *v60;
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;
  Il2CppObject *v64;
  UnityEngine_Vector3_array *Item;
  UnityEngine_Transform_o *transform;
  s64 *Enumerator;
  UnityEngine_Component_o *v68;
  UnityEngine_Component_c *klass;
  s64 typeHierarchyDepth;
  char *currentKey;
  s64 *v72;
  UnityEngine_GameObject_o *gameObject;
  s64 *Interface;
  u8 v76[24];
  Il2CppObject *v77;
  u32 *v78;
  UnityEngine_Object_o *v79;
  System_Collections_Generic_Dictionary_KeyCollection_Enumerator_TKey__TValue__o v80;
  System_Collections_Generic_Dictionary_KeyCollection_Enumerator_TKey__TValue__o v81;
  UnityEngine_Material_o *v82;
  UnityEngine_Vector3_o zero;
  UnityEngine_Vector3_o v84;

  v7 = v76;
  v82 = 0;
  memset(&v80, 0, sizeof(v80));
  allobject = this->allobject;
  name = get_name(rootobj);
  if (!Animator___ContainsKey(allobject, name))
  {
    v11 = this->allobject;
    v12 = get_name(rootobj);
    PropertySheet___Add(v11, v12, rootobj);
  }
  animator = this->animator;
  if (op_Equality(animator, 0, 0))
    this->animator = GetComponent_object_(rootobj);
  Component_object = GetComponent_object_(rootobj);
  v16 = op_Inequality(Component_object, 0, 0);
  v79 = rootobj;
  if (v16)
  {
    sharedMaterials = get_sharedMaterials(Component_object);
    max_length = sharedMaterials->max_length;
    v19 = sharedMaterials;
    if (max_length >= 1)
    {
      v20 = 0;
      m_Items = sharedMaterials->m_Items;
      do
      {
        v82 = *m_Items;
        if (((this->klass->vtable._17_GetListMatelial.methodPtr)(
                this,
                this->mat_list,
                &v82,
                this->klass->vtable._17_GetListMatelial.method)
            & 1) == 0)
          goto LABEL_41;
        v25 = v82;
        if (this->SpecularType)
        {
          SpecularTexture2 = kernelObject->SpecularTexture2;
        }
        else
        {
          SpecularTexture2 = kernelObject->SpecularTexture;
        }
        SetTexture_27248080(v25, id_SpecularTex, SpecularTexture2);
        (this->klass->vtable._19_AddMatList.methodPtr)(this, v82, this->klass->vtable._19_AddMatList.method);
        if (!this->mode_lmap_player)
          goto LABEL_41;
        v33 = v79;
        v34 = get_name(v79);
        if (Equals_5234480(v34, "wpc"))
        {
          SetFloat(v82, "_SpecularLevel", 100.0);
          v35 = v82;
          v36 = "_Gloss";
          v37 = 2.0;
        }
        else
        {
          v38 = get_name(v33);
          if (!Equals_5234480(v38, "GeoSphere01"))
            goto LABEL_41;
          v35 = v82;
          v36 = "_SpecularLevel";
          v37 = 0.0;
        }
        SetFloat(v35, v36, v37);
LABEL_41:
        v39 = v82;
        max_length = v19[6];
        ++v20;
        *m_Items++ = v39;
      }
      while (v20 < max_length);
    }
    set_sharedMaterials(Component_object, v19);
    set_shadowCastingMode(Component_object, 0);
    set_receiveShadows(Component_object, 0);
    rootobj = v79;
    v7 = v76;
  }
  v42 = GetComponent_object_(rootobj);
  if (op_Inequality(v42, 0, 0) && blendshape_clr)
  {
    v77 = v42;
    v78 = v76;
    sharedMesh = get_sharedMesh(v42);
    v45 = Instantiate_object_(sharedMesh);
    v46 = get_name(v45);
    v47 = Concat_5224608(v46, "(clone)", 0);
    set_name(v45, v47);
    v48 = Allocate(System_Collections_Generic_Dictionary_string__Vector3_);
    PropertySheet____ctor(v48);
    vertexCount = get_vertexCount(v45);
    v50 = NewSpecific(UnityEngine_Vector3, vertexCount);
    v51 = get_vertexCount(v45);
    v52 = NewSpecific(UnityEngine_Vector3, v51);
    if (get_blendShapeCount(v45) >= 1)
    {
      v53 = 0;
      do
      {
        v54 = get_vertexCount(v45);
        v55 = NewSpecific(UnityEngine_Vector3, v54);
        GetBlendShapeFrameVertices(v45, v53, 0, v55, v50, v52);
        BlendShapeName = GetBlendShapeName(v45, v53);
        AttributeUsageAttribute___set_Item(v48, BlendShapeName, v55);
        ++v53;
      }
      while (v53 < get_blendShapeCount(v45));
    }
    ClearBlendShapes(v45);
    if (get_vertexCount(v45) >= 1)
    {
      v58 = 0;
      p_z = &v52->m_Items[0].z;
      v60 = &v50->m_Items[0].z;
      do
      {
        zero = get_zero();
        *(v60 - 1) = zero;
        v84 = get_zero();
        *(p_z - 1) = v84;
        ++v58;
        p_z = (p_z + 12);
        v60 = (v60 + 12);
      }
      while (v58 < get_vertexCount(v45));
    }
    Keys = string___get_Keys(v48);
    object___GetEnumerator(
      &v81,
      Keys);
    v80 = v81;
    while ((sub_4402C0(&v80) & 1) != 0)
    {
      v64 = sub_440450(&v80);
      Item = object___get_Item(v48, v64);
      AddBlendShapeFrame(v45, v64, 100.0, Item, v50, v52);
    }
    v7 = v78;
    *v78 = 614;
    nullsub_33(&v80);
    set_sharedMesh(v77, v45);
    rootobj = v79;
  }
  transform = get_transform(rootobj, 0);
  Enumerator = GetEnumerator(transform);
  while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
  {
    v68 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
    if (v68)
    {
      klass = v68->klass;
      if (v68->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, &v81);
        if ((v81.dictionary & 1) != 0)
          currentKey = v81.currentKey;
        else
          currentKey = &v81.dictionary + 1;
        v72 = sub_8C4940(currentKey);
      }
    }
    gameObject = get_gameObject(v68);
    SetMatInit(this, gameObject, blendshape_clr);
  }
  *v7 = 698;
  Interface = QueryInterface(Enumerator, System_IDisposable);
  if (Interface)
    sub_22F10(0, System_IDisposable, Interface);
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
  f32 v10;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  UnityEngine_Object_o *v14;
  System_String_o *v15;
  f32 v16;
  s32 v17;
  System_WeakReference_o *Item;
  f32 mode_battle;
  s32 v22;
  s32 v23;
  System_WeakReference_o *v25;
  UnityEngine_Object_o *v36;
  System_String_o *v37;
  UnityEngine_Object_o *v38;
  System_String_o *v39;
  System_Collections_Generic_List_WeakReference_EtwSession___o *kage_mat_list;
  UnityEngine_Material_o *v42;
  System_Collections_Generic_List_Enumerator_T__o v44;

  memset(&v44, 0, sizeof(v44));
  v10 = fminf(COERCE_FLOAT(LODWORD(SDF_VU0__Retdds3ColorItoF(rgba, 128.0).w)), 1.0);
  st_alf = v10;
  gameObject = get_gameObject(this);
  name = get_name(gameObject);
  if (Equals_5234480(name, "npc_051_0")
    || (v14 = get_gameObject(this),
        v15 = get_name(v14),
        Equals_5234480(v15, "npc_052_1")))
  {
    if (_get_Count(this->mat_list) >= 1)
    {
      v16 = fminf(v10, 0.5);
      v17 = 0;
      do
      {
        Item = _get_Item(
                 this->mat_list,
                 v17);
        SetInt_27247136(Item, id_BlendOp, 0);
        SetFloat_27246832(Item, id_AlfPower, v16);
        ++v17;
      }
      while (v17 < _get_Count(this->mat_list));
    }
  }
  else
  {
    mode_battle = this->mode_battle;
    if (_get_Count(this->mat_list) >= 1)
    {
      v22 = queueoffset + 3000;
      v23 = 0;
      do
      {
        v25 = _get_Item(
                this->mat_list,
                v23);
        if (GetInt(v25, id_SrcBlend) != 5)
        {
          if (HasProperty(v25, id_ModeOp))
          {
            SetOverrideTag(v25, "RenderType", "Transparent");
            SetInt_27247136(v25, id_BlendOp, 0);
            SetInt_27247136(v25, id_SrcBlend, 5);
            SetInt_27247136(v25, id_DstBlend, 10);
            SetInt_27247136(v25, id_ZWrite, 1);
            DisableKeyword(v25, "_ALPHATEST_ON");
            EnableKeyword(v25, "_ALPHABLEND_ON");
            DisableKeyword(v25, "_ALPHAPREMULTIPLY_ON");
            DisableKeyword(v25, "_ALPHAMODULATE_ON");
            set_renderQueue(v25, v22);
          }
        }
        SetFloat_27246832(v25, id_AlfPower, v10);
        SetFloat_27246832(v25, id_AlfRGBPower, alfrgb);
        if (mode_battle == 0.0)
        {
          if (HasProperty(v25, id_StencilComp))
          {
            SetInt_27247136(v25, id_StencilComp, 5);
          }
        }
        ++v23;
      }
      while (v23 < _get_Count(this->mat_list));
    }
    v36 = get_gameObject(this);
    v37 = get_name(v36);
    if (op_Equality(v37, "devil_0x15d_e740_0", 0)
      || (v38 = get_gameObject(this),
          v39 = get_name(v38),
          op_Equality(v39, "devil_0xc6_e745_0", 0)))
    {
      SetActive(this, HIBYTE(rgba) != 0, 0);
    }
    kage_mat_list = this->kage_mat_list;
    if (kage_mat_list)
    {
      __GetEnumerator(&v44, kage_mat_list);
      while ((sub_1A11200(&v44) & 1) != 0)
      {
        v42 = sub_1A11350(&v44);
        SetFloat_27246832(v42, id_AlfPower, v10);
      }
      nullsub_111(&v44);
    }
  }
}

// 0x1139620
void SetUpDateDI(FieldChrHD *this) {
  this->update_di = 1;
}

// 0x1139430
void Start(FieldChrHD *this) {
  UnityEngine_Object_o *gameObject;
  UnityEngine_GameObject_o *v5;
  UnityEngine_Object_o *v7;
  System_String_o *name;
  struct evtUnitHandle_t_o *hunit;
  struct dds3Basic_t_o *Owner;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  s32 v16;
  s32 v17;
  void *v18;
  s64 v19;
  u64 v20[3];

  if (this->blur)
  {
    this->update_di = 1;
  }
  else
  {
    gameObject = get_gameObject(this);
    if (op_Inequality(gameObject, 0, 0))
    {
      v5 = get_gameObject(this);
      SetLightAll(this, v5);
    }
    v7 = get_gameObject(this);
    name = get_name(v7);
    if (Equals_5234480(name, "player_tatoo_e618"))
    {
      hunit = this->hunit;
      if (hunit)
      {
        Owner = hunit->Owner;
        if (Owner)
        {
          if (Owner->name)
          {
            workdata = hunit->BasicLight->workdata;
            v18 = 0;
            v19 = 0;
            sub_854690(&v18, 0.0, 0.0, 0.0, 0.0);
            if (workdata)
            {
              klass = workdata->klass;
              if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
                || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
              {
                sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v20);
                if ((v20[0] & 1) != 0)
                  v14 = v20[2];
                else
                  v14 = v20 + 1;
                v15 = sub_8C4940(v14);
              }
            }
            v17 = v19;
            v16 = HIDWORD(v19);
            workdata[1].monitor = v18;
            LODWORD(workdata[2].klass) = v17;
            HIDWORD(workdata[2].klass) = v16;
            this->player_tatoo_e618 = 1;
          }
        }
      }
    }
  }
}

// 0x1138680
void Update(FieldChrHD *this) {
  u32 color;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  _BOOL4 devil_0x123_e681_0;
  f32 v14;
  f32 fog_end;
  bool v16;
  f32 v17;
  UnityEngine_GameObject_o *v18;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Object_o *v23;
  System_String_o *v24;
  UnityEngine_GameObject_o *v25;
  UnityEngine_Transform_o *transform;
  UnityEngine_GameObject_o *v27;
  UnityEngine_Transform_o *v28;
  struct fldGlobalWork_t_o *fldGb;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  struct fldGlobalWork_t_o *v34;
  s32 areaID;
  s32 v37;
  u32 v38;
  struct fldGlobalWork_t_o *v42;
  UnityEngine_Object_o *v43;
  System_String_o *v44;
  struct fldGlobalWork_t_o *v48;
  struct fldGlobalWork_t_o *v49;
  UnityEngine_Object_o *v50;
  System_String_o *v51;
  UnityEngine_Object_o *v52;
  System_String_o *v53;
  f32 fog_near;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v58;

  if (!this->update_di)
  {
    (this->klass->vtable._13_SetFogSpot.methodPtr)(this, 1, this->klass->vtable._13_SetFogSpot.method);
    color = dds3FogParam->color;
    v6 = color;
    this->fog_r = v6 * 0.0078125;
    v7 = BYTE1(color);
    this->fog_g = v7 * 0.0078125;
    v8 = BYTE2(color);
    this->fog_b = v8 * 0.0078125;
    v9 = HIBYTE(color);
    this->fog_a = v9 * 0.0078125;
    if (this->fog_calc_type)
    {
      v10 = dds3FogParam->fogMin / 255.0;
      this->fog_min = v10;
      v11 = dds3FogParam->fogMax / 255.0;
      this->fog_max = v11;
      v12 = dds3FogParam->fogNear / 10.0;
      this->fog_near = v12;
      devil_0x123_e681_0 = this->devil_0x123_e681_0;
      v14 = dds3FogParam->fogFar / 10.0;
      this->fog_far = v14;
      this->fog_start = ((v10 + v11) + (((v10 - v11) * (v12 + v14)) / (v14 - v12))) * 0.5;
      fog_end = ((v11 - v10) * (v12 * v14)) / (v14 - v12);
      this->fog_end = fog_end;
      if (devil_0x123_e681_0 && (v16 = evtBitCheck(146), fog_end = this->fog_end, v16))
        v17 = 20.0;
      else
        v17 = 5.0;
      this->fog_min = 1.0;
      this->fog_end = fog_end + v17;
      if (this->layerset)
        goto LABEL_17;
    }
    else
    {
      this->fog_min = (256.0 - dds3FogParam->fogMin) * 0.0078125;
      this->fog_max = dds3FogParam->fogMax;
      this->fog_start = 0.0;
      this->fog_near = dds3FogParam->fogNear;
      if (fldGb->fieldID == 26)
      {
        if (fldGb->areaID == 19)
        {
          gameObject = get_gameObject(this);
          name = get_name(gameObject);
          if (Equals_5234480(name, "devil_0x5e_0"))
          {
            if (fldLightMaChk() != 1)
            {
              this->fog_near_rimit = 0;
              this->fog_near = 120.0;
              *&this->fog_r = 0x3C23D70A3C23D70ALL;
              *&this->fog_b = 0x3F8000003C23D70ALL;
            }
          }
        }
      }
      v34 = fldGb;
      if (v34->fieldID == 21)
      {
        areaID = v34->areaID;
        if (areaID == 2)
          goto LABEL_172;
        if (areaID == 16)
          goto LABEL_172;
        if (areaID == 17)
          goto LABEL_172;
        if (areaID == 18)
          goto LABEL_172;
        if (areaID == 12)
          goto LABEL_172;
        if (areaID == 15)
          goto LABEL_172;
        if (areaID == 19)
          goto LABEL_172;
        if (areaID == 25)
          goto LABEL_172;
        if (areaID == 8)
        {
LABEL_172:
          if (fldLightMaChk() != 1)
          {
            this->fog_near = 120.0;
            this->fog_near_rimit = 0;
          }
        }
      }
      if (fldGb->fieldID == 34 && this->mode_battle == 5.0)
      {
        v37 = fldLightMaChk();
        if (v37 != 1)
        {
          v38 = fldGb->areaID;
          if (v38 <= 8 && ((1 << v38) & 0x170) != 0)
          {
            this->fog_near_rimit = 0;
            this->fog_near = 120.0;
          }
        }
      }
      if (fldGb->fieldID == 36 && this->mode_battle == 5.0)
      {
        if (!fldLightMaChk())
        {
          if (fldGb->areaID == 6)
          {
            this->fog_near_rimit = 0;
            this->fog_near = 120.0;
          }
        }
      }
      if (!fldLightMaChk())
      {
        v42 = fldGb;
        if (v42->fieldID == 29)
        {
          if (v42->areaID == 1)
          {
            v43 = get_gameObject(this);
            v44 = get_name(v43);
            if (Contains(v44, "npc_mane", 0))
            {
              this->fog_near_rimit = 0;
              this->fog_near = 200.0;
              *&this->fog_r = 0x3C23D70A3C23D70ALL;
              *&this->fog_b = 0x3F8000003C23D70ALL;
            }
          }
        }
      }
      if (gFldNowDZone)
      {
        v48 = fldGb;
        if (!v48->LightMa)
        {
          if (v48->fieldID <= 199 && this->mode_battle == 5.0)
          {
            this->fog_near_rimit = 0;
            this->fog_near = 200.0;
            *&this->fog_r = 0x3C23D70A3C23D70ALL;
            *&this->fog_b = 0x3F8000003C23D70ALL;
          }
        }
      }
      v49 = fldGb;
      if (v49->fieldID == 31)
      {
        if (v49->areaID == 6)
          this->fog_near = 1000.0;
      }
      v50 = get_gameObject(this);
      v51 = get_name(v50);
      if (Equals_5234480(v51, "npc_hikawa_e697"))
        this->fog_near = 3000.0;
      v52 = get_gameObject(this);
      v53 = get_name(v52);
      if (Equals_5234480(v53, "npc_isamu_e655"))
        this->fog_near = 3000.0;
      if (this->fog_near_rimit && this->fog_near < 255.0)
        this->fog_near = 255.0;
      if (fldGb->fieldID == 807)
      {
        fog_near = 5.0;
        this->fog_near = 5.0;
      }
      else
      {
        fog_near = this->fog_near;
      }
      this->fog_end = fog_near / 10.0;
      if (this->layerset)
        goto LABEL_17;
    }
    v18 = get_gameObject(this);
    SetLayerAll(this, v18);
    this->layerset = 1;
LABEL_17:
    v20 = get_gameObject(this);
    SetLightAll(this, v20);
    KageMove(this);
    (this->klass->vtable._21_UpdateOption.methodPtr)(this, this->klass->vtable._21_UpdateOption.method);
    v23 = get_gameObject(this);
    v24 = get_name(v23);
    if (Equals_5234480(v24, "kage_e661"))
    {
      v25 = get_gameObject(this);
      transform = get_transform(v25, 0);
      position = get_position(transform);
      v27 = get_gameObject(this);
      v28 = get_transform(v27, 0);
      v58.x = position.x;
      v58.y = position.y;
      v58.z = position.z + 0.3;
      set_position(v28, v58);
    }
  }
}

// 0x113ad20
void UpdateGlobal(FieldChrHD *this) {
  Update(this);
}
