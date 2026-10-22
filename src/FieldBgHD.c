#include "types.h"

typedef struct FieldBgHD FieldBgHD;
typedef struct RippleEffect RippleEffect;
typedef struct UiHDMesh UiHDMesh;
typedef struct dds3DefaultMain dds3DefaultMain;

s32 GetCamRunTime(void);
char *GetEventCamName(void);
void *GetMainCamera(dds3DefaultMain *this);
void RetTransparent(void *obj);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SetLightAll(UiHDMesh *this, void *rootobj);
void SetLightInit(FieldBgHD *this, void *rootobj);
void Update(RippleEffect *this);
s32 fldLightMaChk(void);

// 0xff1900
void Awake(FieldBgHD *this) {
  u64 *v3;
  u64 *v4;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  UnityEngine_Object_o *v7;
  System_String_o *v8;
  UnityEngine_Object_o *v9;
  System_String_o *v10;
  UnityEngine_Object_o *v11;
  System_String_o *v12;
  UnityEngine_Object_o *v13;
  System_String_o *v14;
  UnityEngine_Object_o *v15;
  System_String_o *v16;
  UnityEngine_Object_o *v17;
  System_String_o *v18;
  UnityEngine_Object_o *v19;
  System_String_o *v20;
  UnityEngine_GameObject_o *v21;
  UnityEngine_Object_o *v23;
  System_String_o *v24;
  UnityEngine_Object_o *v25;
  System_String_o *v26;
  UnityEngine_Object_o *v27;
  System_String_o *v28;
  UnityEngine_Object_o *v29;
  System_String_o *v30;
  UnityEngine_Object_o *v31;
  System_String_o *v32;
  UnityEngine_Object_o *v33;
  System_String_o *v34;
  UnityEngine_Object_o *v35;
  System_String_o *v36;
  UnityEngine_Object_o *v37;
  System_String_o *v38;
  UnityEngine_Object_o *v39;
  System_String_o *v40;
  UnityEngine_Object_o *v41;
  System_String_o *v42;
  UnityEngine_Object_o *v43;
  System_String_o *v44;
  fldGlobal_c *v46;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v48;
  struct fldGlobalWork_t_o *v49;
  struct fldGlobalWork_t_o *v50;
  struct fldGlobalWork_t_o *v51;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;

  v3 = Allocate(System_Collections_Generic_Dictionary_string__GameObject_);
  PropertySheet____ctor(v3);
  this->allobject = v3;
  v4 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v4);
  this->mat_list = v4;
  this->lightobj_off = 0;
  gameObject = get_gameObject(this);
  name = get_name(gameObject);
  if (Equals_5234480(name, "f002_001(Clone)", 0))
  {
    this->lmap_type = 2;
  }
  else
  {
    v7 = get_gameObject(this);
    v8 = get_name(v7);
    if (Equals_5234480(v8, "f003_001(Clone)", 0))
    {
      this->lmap_type = 3;
    }
    else
    {
      v9 = get_gameObject(this);
      v10 = get_name(v9);
      if (Equals_5234480(v10, "f004_001(Clone)", 0))
      {
        this->lmap_type = 4;
      }
      else
      {
        v11 = get_gameObject(this);
        v12 = get_name(v11);
        if (Equals_5234480(v12, "f005_001(Clone)", 0))
        {
          this->lmap_type = 5;
        }
        else
        {
          v13 = get_gameObject(this);
          v14 = get_name(v13);
          if (Equals_5234480(v14, "f006_001(Clone)", 0))
          {
            this->lmap_type = 6;
          }
          else
          {
            v15 = get_gameObject(this);
            v16 = get_name(v15);
            if (Equals_5234480(v16, "f007_001(Clone)", 0))
            {
              this->lmap_type = 7;
            }
            else
            {
              v17 = get_gameObject(this);
              v18 = get_name(v17);
              if (Equals_5234480(v18, "f008_001(Clone)", 0))
              {
                this->lmap_type = 8;
              }
              else
              {
                v19 = get_gameObject(this);
                v20 = get_name(v19);
                if (Equals_5234480(v20, "f034_002(Clone)", 0))
                  this->flg_f034_002 = 1;
              }
            }
          }
        }
      }
    }
  }
  v21 = get_gameObject(this);
  SetLightInit(this, v21);
  this->fog_calc_type = 0;
  this->fog_near_rimit = 1;
  v23 = get_gameObject(this);
  v24 = get_name(v23);
  if (op_Equality(v24, "f037_027(Clone)", 0))
    this->flg_f037_027 = 1;
  v25 = get_gameObject(this);
  v26 = get_name(v25);
  if (op_Equality(v26, "f803_001(Clone)", 0))
    this->flg_f803_001 = 1;
  v27 = get_gameObject(this);
  v28 = get_name(v27);
  if (op_Equality(v28, "f233_004(Clone)", 0))
    this->fog_calc_type = 1;
  v29 = get_gameObject(this);
  v30 = get_name(v29);
  if (op_Equality(v30, "f635_002(Clone)", 0))
    this->fog_calc_type = 1;
  v31 = get_gameObject(this);
  v32 = get_name(v31);
  if (Equals_5234480(v32, "e635_field_a")
    || (v33 = get_gameObject(this),
        v34 = get_name(v33),
        Equals_5234480(v34, "e635_field_b")))
  {
    this->fog_near_rimit = 0;
  }
  v35 = get_gameObject(this);
  v36 = get_name(v35);
  if (Equals_5234480(v36, "f635_001(Clone)", 0))
    this->fog_near_rimit = 0;
  v37 = get_gameObject(this);
  v38 = get_name(v37);
  if (Equals_5234480(v38, "f651_015(Clone)", 0))
    this->flg_f651_015 = 1;
  v39 = get_gameObject(this);
  v40 = get_name(v39);
  if (Equals_5234480(v40, "e697_field01"))
    this->fog_near_rimit = 0;
  v41 = get_gameObject(this);
  v42 = get_name(v41);
  if (Equals_5234480(v42, "e697_field02"))
    this->flg_e697_field02 = 1;
  v43 = get_gameObject(this);
  v44 = get_name(v43);
  if (Equals_5234480(v44, "f681_001(Clone)", 0))
    this->flg_f681_001 = 1;
  if (fldGb->fieldID == 33)
    this->flg_blend_ret = 1;
  if (fldGb->fieldID == 34)
    this->flg_blend_ret = 1;
  if (fldGb->fieldID == 19)
  {
    if (!fldGb->areaID)
      goto LABEL_61;
  }
LABEL_57:
  if ((v46->_2.bitflags2 & 2) == 0)
    goto LABEL_62;
LABEL_58:
LABEL_62:
  v48 = fldGb;
  if (v48->fieldID == 31)
  {
    if (v48->areaID == 14)
      this->flg_blend_ret = 1;
  }
  v49 = fldGb;
  if (v49->fieldID == 35)
  {
    if (v49->areaID == 1)
      this->flg_blend_ret = 1;
  }
  v50 = fldGb;
  if (v50->fieldID == 21)
  {
    if (v50->areaID == 21)
      this->flg_blend_ret = 1;
  }
  this->orthographic = 0;
  v51 = fldGb;
  if (v51->fieldID == 1)
  {
    else if (v51->areaID)
    {
      return;
    }
    MainCamera = GetMainCamera(kernelObject);
    Component_object = GetComponent_object_(MainCamera);
    set_orthographic(Component_object, 1);
    set_orthographicSize(Component_object, 8.4);
    this->orthographic = 1;
  }
}

// 0xff48e0
void OnDestroy(FieldBgHD *this) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;

  (this->klass->vtable._4_CallOnDestroy.methodPtr)(this, this->klass->vtable._4_CallOnDestroy.method);
  if (this->orthographic)
  {
    MainCamera = GetMainCamera(kernelObject);
    Component_object = GetComponent_object_(MainCamera);
    set_orthographic(Component_object, 0);
    set_orthographicSize(Component_object, 5.0);
    this->orthographic = 0;
  }
}

// 0xff52d0
void RetTransparent(FieldBgHD *this, void *rootobj) {
  long f64 v3;
  UnityEngine_Transform_o *transform;
  s32 v7;
  UnityEngine_Transform_o *v8;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *v11;
  UnityEngine_Renderer_o *Component_GUILayer;
  UnityEngine_Material_array *sharedMaterials;
  s32 max_length;
  UnityEngine_Material_array *v18;
  s32 v19;
  UnityEngine_Material_o *v22;
  System_String_o *name;
  System_String_o *v24;
  Il2CppObject *v25;
  long f64 v27;
  long f64 v28;
  UnityEngine_Material_o *v31;
  UnityEngine_Transform_o *v35;
  u32 v36;

  v36 = 0;
  if (!op_Equality(rootobj, 0, 0))
  {
    transform = get_transform(rootobj, 0);
    if (get_childCount(transform) >= 1)
    {
      LODWORD(v3) = 0;
      v7 = 0;
      do
      {
        v8 = get_transform(rootobj, 0);
        Child = GetChild(v8, v7);
        gameObject = get_gameObject(Child);
        v11 = get_transform(gameObject, 0);
        Component_GUILayer = GetComponent_GUILayer_(v11);
        if (op_Inequality(Component_GUILayer, 0, 0))
        {
          sharedMaterials = get_sharedMaterials(Component_GUILayer);
          v36 = 0;
          max_length = sharedMaterials->max_length;
          if (max_length >= 1)
          {
            v18 = sharedMaterials;
            v19 = 0;
            do
            {
              v22 = v18->m_Items[v19];
              SetFloat_27246832(v22, id_AlfPower, 1.0);
              name = get_name(gameObject);
              v24 = sub_232970(&v36);
              v25 = Concat_5221536(name, ":", v24);
              if (float___ContainsKey(this->modeop_dic, v25))
              {
                *&v27 = float___get_Item(this->modeop_dic, v25);
                v28 = v27;
                v31 = v18->m_Items[v36];
                if (GetFloat(v31, id_ModeOp, 0) != *&v28
                  || *&v28 == 0.0 && this->flg_blend_ret)
                {
                  goto LABEL_33;
                }
                if (*&v28 == 0.0)
                {
                  if (get_renderQueue(v18->m_Items[v36]) == 3000)
                  {
LABEL_33:
                    (this->klass->vtable._14_SetupMaterialWithBlendOp.methodPtr)(
                      this,
                      v18->m_Items[v36],
                      this->klass->vtable._14_SetupMaterialWithBlendOp.v28);
                  }
                }
              }
              else
              {
                (this->klass->vtable._14_SetupMaterialWithBlendOp.methodPtr)(
                  this,
                  v18->m_Items[v36],
                  this->klass->vtable._14_SetupMaterialWithBlendOp.v3);
              }
              v19 = v36 + 1;
              v36 = v19;
              max_length = v18->max_length;
            }
            while (v19 < max_length);
          }
        }
        RetTransparent(this, gameObject);
        ++v7;
        v35 = get_transform(rootobj, 0);
      }
      while (v7 < get_childCount(v35));
    }
  }
}

// 0xff4ba0
void SetFiledName(FieldBgHD *this, char *name) {
  this->filedname = name;
}

// 0xff49a0
void SetLayerAll(FieldBgHD *this, void *rootobj, s32 setlayer) {
  UnityEngine_Transform_o *transform;
  s64 *Enumerator;
  UnityEngine_Component_o *v9;
  UnityEngine_Component_c *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  UnityEngine_GameObject_o *gameObject;
  s64 *Interface;
  u64 v17[3];

  set_layer(rootobj, setlayer);
  transform = get_transform(rootobj, 0);
  Enumerator = GetEnumerator(transform);
  while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
  {
    v9 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
    if (v9)
    {
      klass = v9->klass;
      if (v9->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, v17);
        if ((v17[0] & 1) != 0)
          v12 = v17[2];
        else
          v12 = v17 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    gameObject = get_gameObject(v9);
    SetLayerAll(this, gameObject, setlayer);
  }
  Interface = QueryInterface(Enumerator, System_IDisposable);
  if (Interface)
    sub_22F10(0, System_IDisposable, Interface);
}

// 0xff4340
void SetLightAll(FieldBgHD *this, void *rootobj) {
  s32 v4;
  System_WeakReference_o *Item;
  UnityEngine_Material_o *v7;
  System_String_o *name;
  bool v10;
  f32 l0_a;
  s32 id_LightColor;
  f32 v0_z;
  f32 v0_x;
  f32 v0_y;
  s32 id_LightVector;
  f32 a0_a;
  f32 a0_r;
  f32 a0_g;
  s32 id_ColorAmbient;
  f32 a0_b;
  s32 v24;
  UnityEngine_Material_o *v25;
  f32 l0_r;
  f32 l0_g;
  f32 l0_b;
  f32 v29;
  s32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  s32 v34;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  UnityEngine_GameObject_o *v38;
  Il2CppObject *Component_object;
  UnityEngine_Color_o v41;
  UnityEngine_Vector4_o v42;
  UnityEngine_Color_o v43;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v44;
  UnityEngine_Color_o v45;
  UnityEngine_Color_o v46;
  UnityEngine_Vector4_o v47;
  UnityEngine_Color_o v48;
  UnityEngine_Color_o v49;

  *&v48.r = 0;
  *&v48.b = 0;
  *&v47.x = 0;
  *&v47.z = 0;
  memset(&v44, 0, sizeof(v44));
  *&v46.r = 0;
  *&v46.b = 0;
  *&v45.r = 0;
  *&v45.b = 0;
  sub_19EC630(&v48.r, this->l0_r, this->l0_g, this->l0_b, this->l0_a);
  sub_854690(&v47.x, this->v0_x, this->v0_y, this->v0_z, 0.0);
  sub_19EC630(&v46.r, this->a0_r, this->a0_g, this->a0_b, this->a0_a);
  sub_19EC630(&v45.r, this->fog_r * 0.5, this->fog_g * 0.5, this->fog_b * 0.5, this->fog_a);
  if (_get_Count(this->mat_list) >= 1)
  {
    v4 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v4);
      v7 = Item;
      if (this->lmap_type == 8)
      {
        name = get_name(Item);
        v10 = Equals_5234480(name, "Material #480(mHD)", 0);
        if (v10)
        {
          l0_a = this->l0_a;
          *&v43.r = 0;
          *&v43.b = 0;
          sub_19EC630(&v43.r, 1.0, 1.0, 1.0, l0_a);
          SetColor_27247456(v7, id_LightColor, v43);
          v0_z = this->v0_z;
          v0_x = this->v0_x;
          v0_y = this->v0_y;
          *&v42.x = 0;
          *&v42.z = 0;
          sub_854690(&v42.x, v0_x, v0_y, v0_z, 0.0);
          SetVector_27247776(v7, id_LightVector, v42);
          a0_a = this->a0_a;
          a0_r = 0.1;
          a0_g = 0.1;
          a0_b = 0.1;
        }
        else
        {
          l0_r = this->l0_r;
          l0_g = this->l0_g;
          l0_b = this->l0_b;
          v29 = this->l0_a;
          v30 = id_LightColor;
          *&v43.r = 0;
          *&v43.b = 0;
          sub_19EC630(&v43.r, l0_r, l0_g, l0_b, v29);
          SetColor_27247456(v7, v30, v43);
          v31 = this->v0_z;
          v32 = this->v0_x;
          v33 = this->v0_y;
          v34 = id_LightVector;
          *&v42.x = 0;
          *&v42.z = 0;
          sub_854690(&v42.x, v32, v33, v31, 0.0);
          SetVector_27247776(v7, v34, v42);
          a0_r = this->a0_r;
          a0_g = this->a0_g;
          a0_b = this->a0_b;
          a0_a = this->a0_a;
        }
        *&v41.r = 0;
        *&v41.b = 0;
        sub_19EC630(&v41.r, a0_r, a0_g, a0_b, a0_a);
        v49 = v41;
        v25 = v7;
        v24 = id_ColorAmbient;
      }
      else
      {
        SetColor_27247456(v7, id_LightColor, v48);
        SetVector_27247776(v7, id_LightVector, v47);
        v24 = id_ColorAmbient;
        v49 = v46;
        v25 = v7;
      }
      SetColor_27247456(v25, v24, v49);
      SetColor_27247456(v7, id_FogColor, v45);
      SetFloat_27246832(v7, id_FogStart, this->fog_start);
      SetFloat_27246832(v7, id_FogEnd, this->fog_end);
      SetFloat_27246832(v7, id_FogMin, this->fog_min);
      SetFloat_27246832(v7, id_FogDarkSpotDis, this->fog_dark_dis);
      SetVector_27247776(v7, id_FogDarkSpotVec, this->fog_dark_vec);
      ++v4;
    }
    while (v4 < _get_Count(this->mat_list));
  }
  if (!this->lightobj_off)
  {
    Values = Type___get_Values(this->allobject);
    Type___GetEnumerator(&v44, Values);
    while ((sub_4D4B20(&v44) & 1) != 0)
    {
      v38 = sub_4D4CB0(&v44);
      Component_object = GetComponent_object_(v38);
      if (op_Inequality(Component_object, 0, 0))
        SetActive(v38, 0, 0);
    }
    nullsub_48(&v44);
    this->lightobj_off = 1;
  }
}

// 0xff2080
void SetLightInit(FieldBgHD *this, void *rootobj) {
  struct System_Collections_Generic_Dictionary_string__GameObject__o *allobject;
  System_String_o *name;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v9;
  System_String_o *v10;
  UnityEngine_Object_c **v12;
  Il2CppObject *Component_object;
  UnityEngine_Material_array *sharedMaterials;
  s32 max_length;
  UnityEngine_Material_array *v17;
  System_String_o **v18;
  System_String_o **v19;
  System_String_o **v20;
  s32 v21;
  System_String_o *v25;
  UnityEngine_Material_o *v27;
  s32 id_Toon;
  u64 v30;
  UnityEngine_Object_o *v31;
  UnityEngine_Material_o *v34;
  System_String_o *v35;
  System_String_o *v36;
  System_String_o *v37;
  UnityEngine_Object_c **v40;
  System_String_o **v41;
  System_String_o **v42;
  System_String_o **v43;
  System_Collections_Generic_Dictionary_string__float__o *modeop_dic;
  UnityEngine_Material_o *v45;
  f32 Float;
  s64 v47;
  UnityEngine_Material_o *v48;
  UnityEngine_Transform_o *transform;
  s64 *Enumerator;
  UnityEngine_Component_o *v52;
  UnityEngine_Component_c *klass;
  s64 typeHierarchyDepth;
  char *v55;
  s64 *v56;
  UnityEngine_GameObject_o *gameObject;
  s64 *Interface;
  UnityEngine_Renderer_o *v60;
  UnityEngine_GameObject_o *v61;
  UnityEngine_Material_o *v62;
  s32 v63;
  u64 v64[3];

  v63 = 0;
  v62 = 0;
  allobject = this->allobject;
  name = get_name(rootobj);
  if (Animator___ContainsKey(allobject, name))
  {
    Log("same NG", 0);
  }
  else
  {
    v9 = this->allobject;
    v10 = get_name(rootobj);
    PropertySheet___Add(v9, v10, rootobj);
  }
  if (fldGb->fieldID >= 11)
    set_layer(rootobj, 16);
  v12 = &UnityEngine_Object;
  Component_object = GetComponent_object_(rootobj);
  if (op_Inequality(Component_object, 0, 0))
  {
    v60 = Component_object;
    sharedMaterials = get_sharedMaterials(Component_object);
    v63 = 0;
    max_length = sharedMaterials->max_length;
    v17 = sharedMaterials;
    if (max_length >= 1)
    {
      v18 = &"f034_002_02_pira(mHD)";
      v19 = &"LIGHTOFF_USE";
      v20 = &":";
      v21 = 0;
      v61 = rootobj;
      do
      {
        v62 = v17->m_Items[v21];
        if (((this->klass->vtable._17_GetListMatelial.methodPtr)(
                this,
                this->mat_list,
                &v62,
                this->klass->vtable._17_GetListMatelial.method)
            & 1) != 0)
        {
          if (this->lmap_type)
            EnableKeyword(v62, *v19);
          if (this->flg_f034_002)
          {
            v25 = get_name(v62);
            if (Equals_5234480(v25, *v18))
            {
              v27 = v62;
              SetTexture_27248080(v27, id_Toon, kernelObject->HighContrastMode_ToneTexture);
              SetFloat_27246832(v62, id_ToonType, 1.001);
              SetFloat_27246832(v62, id_ToonTypeStart, 0.0);
              SetFloat_27246832(v62, id_ToonRim, 29.001);
              SetFloat_27246832(v62, id_ToonTypeDiv, 1.0);
            }
          }
        }
        v30 = *v12;
        v31 = v62;
        if (((*v12)->_2.bitflags2 & 2) != 0 && !*(v30 + 216))
        if (op_Inequality(v31, 0, 0))
        {
          v34 = v62;
          if (HasProperty(v34, id_ModeOp))
          {
            v35 = get_name(rootobj);
            v36 = sub_232970(&v63);
            v37 = Concat_5221536(v35, *v20, v36);
            if (!float___ContainsKey(this->modeop_dic, v37))
            {
              v40 = v12;
              v41 = v20;
              v42 = v19;
              v43 = v18;
              modeop_dic = this->modeop_dic;
              v45 = v62;
              Float = GetFloat(v45, id_ModeOp, 0);
              float___Add(modeop_dic, v37, Float);
              v18 = v43;
              v19 = v42;
              v20 = v41;
              v12 = v40;
              rootobj = v61;
            }
          }
        }
        v47 = v63;
        v48 = v62;
        v17->m_Items[v47] = v48;
        v21 = v63 + 1;
        v63 = v21;
        max_length = v17->max_length;
      }
      while (v21 < max_length);
    }
    set_sharedMaterials(v60, v17);
  }
  transform = get_transform(rootobj, 0);
  Enumerator = GetEnumerator(transform);
  while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
  {
    v52 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
    if (v52)
    {
      klass = v52->klass;
      if (v52->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, v64);
        if ((v64[0] & 1) != 0)
          v55 = v64[2];
        else
          v55 = v64 + 1;
        v56 = sub_8C4940(v55);
      }
    }
    gameObject = get_gameObject(v52);
    SetLightInit(this, gameObject);
  }
  Interface = QueryInterface(Enumerator, System_IDisposable);
  if (Interface)
    sub_22F10(0, System_IDisposable, Interface);
}

// 0xff4bb0
void SetTransparentEvent(FieldBgHD *this, void *rootobj, u32 rgba) {
  UnityEngine_GameObject_o *v5;
  f32 v7;
  UnityEngine_Transform_o *transform;
  s32 v9;
  UnityEngine_Transform_o *v10;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *v13;
  UnityEngine_Renderer_o *Component_GUILayer;
  UnityEngine_Material_array *sharedMaterials;
  il2cpp_array_size_t max_length;
  u32 *v19;
  u64 v20;
  UnityEngine_Material_o **m_Items;
  System_String_o *name;
  UnityEngine_Material_o *v27;
  System_String_o *v29;
  System_String_o *v31;
  Il2CppObject *v33;
  s64 *v34;
  UnityEngine_Object_o *v35;
  UnityEngine_Material_o *v42;
  UnityEngine_Material_o *v48;
  UnityEngine_Material_o *v59;
  UnityEngine_Transform_o *v60;
  f32 w;
  u32 v63;
  UnityEngine_GameObject_o *v64;
  UnityEngine_Renderer_o *v65;
  UnityEngine_GameObject_o *v66;

  v5 = rootobj;
  if (!op_Equality(v5, 0, 0))
  {
    w = SDF_VU0__Retdds3ColorItoF(rgba, 128.0).w;
    if (w >= 1.0)
    {
      RetTransparent(this, v5);
    }
    else
    {
      v7 = w;
      transform = get_transform(v5, 0);
      if (get_childCount(transform) >= 1)
      {
        v9 = 0;
        v64 = v5;
        v63 = rgba;
        do
        {
          v10 = get_transform(v5, 0);
          Child = GetChild(v10, v9);
          gameObject = get_gameObject(Child);
          v13 = get_transform(gameObject, 0);
          Component_GUILayer = GetComponent_GUILayer_(v13);
          if (op_Inequality(Component_GUILayer, 0, 0))
          {
            v66 = gameObject;
            v65 = Component_GUILayer;
            sharedMaterials = get_sharedMaterials(Component_GUILayer);
            max_length = sharedMaterials->max_length;
            v19 = sharedMaterials;
            if (max_length >= 1)
            {
              v20 = 0;
              m_Items = sharedMaterials->m_Items;
              do
              {
                name = get_name(m_Items[v20]);
                if (Contains(name, "(cHD)", 0))
                {
                  if (v20 >= v19[6])
                    goto LABEL_38;
                }
                else
                {
                  v29 = get_name(m_Items[v20]);
                  v31 = Concat_5224608(v29, "(cHD)", 0);
                  v33 = m_Items[v20];
                  {
                  }
                  v34 = Instantiate_object_(v33);
                  v35 = v34;
                  m_Items[v20] = v35;
                  set_name(v35, v31);
                  _Add(this->mat_list, m_Items[v20]);
                  if (v20 >= v19[6])
                  {
LABEL_38:
                  }
                }
                v27 = m_Items[v20];
                if (!HasProperty(v27, id_ModeOp))
                  goto LABEL_46;
                v42 = m_Items[v20];
                if (GetFloat(v42, id_ModeOp, 0) == 0.0)
                {
LABEL_46:
                  SetOverrideTag(m_Items[v20], "RenderType", "Transparent");
                  v48 = m_Items[v20];
                  SetInt_27247136(v48, id_BlendOp, 0);
                  SetInt_27247136(m_Items[v20], id_SrcBlend, 5);
                  SetInt_27247136(m_Items[v20], id_DstBlend, 10);
                  SetInt_27247136(m_Items[v20], id_ZWrite, 0);
                  DisableKeyword(m_Items[v20], "_ALPHATEST_ON");
                  EnableKeyword(m_Items[v20], "_ALPHABLEND_ON");
                  DisableKeyword(m_Items[v20], "_ALPHAPREMULTIPLY_ON");
                  DisableKeyword(m_Items[v20], "_ALPHAMODULATE_ON");
                  set_renderQueue(m_Items[v20], 3000);
                }
                v59 = m_Items[v20];
                SetFloat_27246832(v59, id_AlfPower, v7);
                LODWORD(max_length) = v19[6];
                ++v20;
              }
              while (v20 < max_length);
            }
            set_sharedMaterials(v65, v19);
            v5 = v64;
            rgba = v63;
            gameObject = v66;
          }
          SetTransparentEvent(this, gameObject, rgba);
          ++v9;
          v60 = get_transform(v5, 0);
        }
        while (v9 < get_childCount(v60));
      }
    }
  }
}

// 0xff2740
void Start(FieldBgHD *this) {
  UnityEngine_Object_o *gameObject;
  UnityEngine_GameObject_o *v6;

  gameObject = get_gameObject(this);
  if (op_Inequality(gameObject, 0, 0))
  {
    Update(this);
    get_gameObject(this);
    SetLightAll(this, v6);
  }
}

// 0xff27f0
void Update(FieldBgHD *this) {
  struct sdf3DLight_t_array *dds3DirLights;
  struct sdf3DLight_t_array *v6;
  struct sdf3DLight_t_array *v8;
  fldGlobal_c *v11;
  struct fldGlobalWork_t_o *fldGb;
  f32 v13;
  struct fldGlobalWork_t_o *v14;
  struct fldGlobalWork_t_o *v16;
  struct sdf3DLight_t_array *v18;
  struct sdf3DLight_t_array *v20;
  struct sdf3DLight_t_array *v22;
  sdf3DLight_t_o *v24;
  f32 *p_fog_r;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 *p_fog_g;
  f32 *p_fog_b;
  struct fldGlobalWork_t_o *v36;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 fogFar;
  f32 v43;
  f32 v44;
  f32 fog_r;
  f32 fog_g;
  f32 fog_b;
  struct fldGlobalWork_t_o *v48;
  f32 *p_fog_min;
  f32 *p_fog_near;
  System_String_o *EventCamName;
  s32 v52;
  struct fldGlobalWork_t_o *v54;
  struct fldGlobalWork_t_o *v55;
  struct fldGlobalWork_t_o *v56;
  struct fldGlobalWork_t_o *v57;
  struct fldGlobalWork_t_o *v61;
  struct fldGlobalWork_t_o *v62;
  struct fldGlobalWork_t_o *v63;
  s32 areaID;
  struct fldGlobalWork_t_o *v66;
  struct fldGlobalWork_t_o *v67;
  struct fldGlobalWork_t_o *v68;
  struct fldGlobalWork_t_o *v69;
  struct fldGlobalWork_t_o *v70;
  struct fldGlobalWork_t_o *v71;
  struct fldGlobalWork_t_o *v72;
  s32 v73;
  s32 v74;
  u32 v75;
  struct fldGlobalWork_t_o *v76;
  struct fldGlobalWork_t_o *v77;
  struct fldGlobalWork_t_o *v78;
  struct fldGlobalWork_t_o *v79;
  struct fldGlobalWork_t_o *v80;
  struct fldGlobalWork_t_o *v81;
  struct fldGlobalWork_t_o *v82;
  struct fldGlobalWork_t_o *v83;
  struct fldGlobalWork_t_o *v84;
  struct fldGlobalWork_t_o *v85;
  struct fldGlobalWork_t_o *v86;
  u32 v87;
  struct fldGlobalWork_t_o *v88;
  struct fldGlobalWork_t_o *v89;
  struct fldGlobalWork_t_o *v90;
  struct fldGlobalWork_t_o *v91;
  s32 v92;
  System_String_o *v94;
  s32 v95;
  System_String_o *v96;
  s32 CamRunTime;
  f32 v99;
  System_String_o *v100;
  System_String_o *v101;
  f32 v102;
  struct fldGlobalWork_t_o *v104;
  UnityEngine_GameObject_o *v105;
  System_String_o *v107;
  f32 v108;

  else
  {
    if (!LODWORD(dds3DirLights->max_length))
      goto LABEL_6;
  }
  this->l0_r = dds3DirLights->m_Items[0]->color.x;
  v6 = dds3DirLights;
  this->l0_g = v6->m_Items[0]->color.y;
  v8 = dds3DirLights;
  this->l0_b = v8->m_Items[0]->color.z;
  this->l0_a = 1.0;
  (this->klass->vtable._13_SetFogSpot.methodPtr)(this, 0, this->klass->vtable._13_SetFogSpot.method);
  if (fldGb->fieldID == 218)
  {
    if (fldGb->areaID == 1)
    {
      v13 = this->l0_g * 1.5;
      this->l0_r = v13 * 0.85;
      this->l0_g = v13;
      this->l0_b = v13;
    }
  }
  v14 = fldGb;
  if (v14->fieldID == 222)
  {
    if (!fldGb->areaID)
      goto LABEL_33;
  }
LABEL_27:
  if ((v11->_2.bitflags2 & 2) == 0)
    goto LABEL_34;
LABEL_28:
LABEL_34:
  v16 = fldGb;
  if (v16->fieldID == 659)
  {
    else if (v16->areaID)
    {
      goto LABEL_47;
    }
    if (this->l0_r < 0.2)
    {
      this->l0_r = 0.2;
      if (this->l0_g >= 0.2)
      {
LABEL_40:
        if (this->l0_b >= 0.2)
          goto LABEL_47;
        goto LABEL_46;
      }
    }
    else if (this->l0_g >= 0.2)
    {
      goto LABEL_40;
    }
    this->l0_g = 0.2;
    if (this->l0_b < 0.2)
LABEL_46:
      this->l0_b = 0.2;
  }
LABEL_47:
  this->a0_r = dds3Ambient.x;
  this->a0_g = dds3Ambient.y;
  this->a0_b = dds3Ambient.z;
  this->a0_a = 1.0;
  if (this->flg_f651_015)
  {
    *&this->a0_r = 0x3F4CCCCD3F4CCCCDLL;
    this->a0_b = 0.8;
  }
  else
  {
    v18 = dds3DirLights;
    if (!LODWORD(v18->max_length))
      goto LABEL_55;
  }
  this->v0_x = v18->m_Items[0]->v.x;
  v20 = dds3DirLights;
  this->v0_y = -v20->m_Items[0]->v.y;
  v22 = dds3DirLights;
  v24 = v22->m_Items[0];
  p_fog_r = &this->fog_r;
  this->v0_z = v24->v.z;
  LODWORD(v24) = dds3FogParam->color;
  v26 = v24;
  v27 = BYTE1(v24);
  v28 = v26 * 0.0078125;
  v29 = v27 * 0.0078125;
  v30 = (v24 >> 24);
  v31 = BYTE2(v24);
  v32 = v31 * 0.0078125;
  this->fog_a = v30 * 0.0078125;
  p_fog_g = &this->fog_g;
  p_fog_b = &this->fog_b;
  this->fog_r = v28;
  this->fog_g = v29;
  this->fog_b = v32;
  if (v32 == 0.0 && v28 == 0.0 && v29 == 0.0)
  {
    *p_fog_r = 0.01;
    *p_fog_g = 0.01;
    *p_fog_b = 0.01;
  }
  v36 = fldGb;
  if (v36->fieldID != 602)
    goto LABEL_71;
  if (v36->areaID)
    goto LABEL_71;
LABEL_79:
  v43 = this->l0_g * 0.9;
  v44 = this->l0_b * 0.9;
  fog_r = this->fog_r;
  fog_g = this->fog_g;
  this->l0_r = this->l0_r * 0.9;
  this->l0_g = v43;
  fog_b = this->fog_b;
  this->fog_r = fog_r * 0.5;
  this->fog_g = fog_g * 0.5;
  this->l0_b = v44;
  this->fog_b = fog_b * 0.5;
  if (this->fog_calc_type)
  {
LABEL_72:
    v39 = dds3FogParam->fogMin / 255.0;
    this->fog_min = v39;
    v40 = dds3FogParam->fogMax / 255.0;
    this->fog_max = v40;
    v41 = dds3FogParam->fogNear / 10.0;
    this->fog_near = v41;
    fogFar = dds3FogParam->fogFar;
    this->fog_min = 1.0;
    this->fog_far = fogFar / 10.0;
    this->fog_start = ((v39 + v40) + (((v39 - v40) * (v41 + (fogFar / 10.0))) / ((fogFar / 10.0) - v41))) * 0.5;
    this->fog_end = ((v40 - v39) * (v41 * (fogFar / 10.0))) / ((fogFar / 10.0) - v41);
    goto LABEL_473;
  }
LABEL_80:
  this->fog_min = (256.0 - dds3FogParam->fogMin) * 0.0078125;
  *&this->fog_max = LODWORD(dds3FogParam->fogMax);
  this->fog_near = dds3FogParam->fogNear;
  v48 = fldGb;
  p_fog_min = &this->fog_min;
  p_fog_near = &this->fog_near;
  if (v48->fieldID != 618)
    goto LABEL_99;
  if (v48->areaID)
    goto LABEL_99;
  EventCamName = GetEventCamName();
  if (Equals_5234480(EventCamName, "cam01"))
  {
LABEL_99:
      goto LABEL_102;
    goto LABEL_100;
  }
  if (Equals_5234480(EventCamName, "cam02")
    || Equals_5234480(EventCamName, "cam03"))
  {
    *p_fog_min = 4.0;
    v52 = 1112014848;
LABEL_98:
    *p_fog_near = v52;
    *p_fog_r = *p_fog_r * 0.9;
    *p_fog_g = *p_fog_g * 0.9;
    *p_fog_b = *p_fog_b * 0.9;
    goto LABEL_99;
  }
  if (Equals_5234480(EventCamName, "cam04"))
  {
    *p_fog_min = 2.5;
    v52 = 1127481344;
    goto LABEL_98;
  }
  if (Equals_5234480(EventCamName, "cam05"))
  {
    *p_fog_min = *p_fog_min * 1.2;
    *p_fog_near = *p_fog_near + -20.0;
    *p_fog_r = *p_fog_r * 0.9;
    *p_fog_g = *p_fog_g * 0.9;
    *p_fog_b = *p_fog_b * 0.9;
      goto LABEL_102;
  }
  else
  {
    Equals_5234480(EventCamName, "cam06");
      goto LABEL_102;
  }
LABEL_100:
LABEL_102:
  v54 = fldGb;
  if (v54->fieldID == 31)
  {
    if (!v54->areaID)
      *p_fog_near = 1800.0;
  }
  v55 = fldGb;
  if (v55->fieldID == 35)
  {
    if (v55->areaID == 7)
      *p_fog_near = 500.0;
  }
  v56 = fldGb;
  if (v56->fieldID == 35)
  {
    if (v56->areaID == 4)
    {
      *p_fog_r = *p_fog_r * 0.55;
      *p_fog_g = *p_fog_g * 0.55;
      *p_fog_b = *p_fog_b * 0.55;
    }
  }
  v57 = fldGb;
  if (v57->fieldID == 60)
  {
    if (v57->areaID == 4)
    {
      *p_fog_r = 1.49;
      *p_fog_g = 1.49;
      *p_fog_b = 1.99;
      *p_fog_min = 0.75;
      *p_fog_near = 2100.0;
    }
  }
  if (gFldNowDZone)
  {
    v61 = fldGb;
    if (!v61->LightMa)
    {
      if (v61->fieldID <= 199)
      {
        this->fog_near = 120.0;
        this->fog_near_rimit = 0;
      }
    }
  }
  v62 = fldGb;
  if (v62->fieldID == 36)
  {
    if (v62->areaID == 17)
      *p_fog_near = 3000.0;
  }
  v63 = fldGb;
  if (v63->fieldID == 20)
  {
    else
    {
      areaID = v63->areaID;
      if (areaID == 14)
        goto LABEL_170;
    }
    if (areaID != 8)
      goto LABEL_175;
LABEL_170:
    if (fldLightMaChk() != 1)
    {
      this->fog_near = 200.0;
      this->fog_near_rimit = 0;
    }
  }
LABEL_175:
  v66 = fldGb;
  if (v66->fieldID == 35)
  {
    if (v66->areaID == 1)
    {
      *p_fog_near = 700.0;
      *p_fog_min = 0.3;
    }
  }
  v67 = fldGb;
  if (v67->fieldID == 24)
  {
    if (v67->areaID == 17)
    {
      *p_fog_near = 800.0;
      *p_fog_min = 0.95;
    }
  }
  v68 = fldGb;
  if (v68->fieldID == 43)
  {
    if (v68->areaID == 12)
    {
      *p_fog_near = 700.0;
      *p_fog_min = 0.9;
    }
  }
  v69 = fldGb;
  if (v69->fieldID == 44)
  {
    if (v69->areaID == 6)
    {
      *p_fog_near = 1400.0;
      *p_fog_min = 2.8;
    }
  }
  v70 = fldGb;
  if (v70->fieldID == 44)
  {
    if (v70->areaID == 24)
    {
      *p_fog_near = 400.0;
      *p_fog_r = 0.1;
      *p_fog_g = 0.1;
      *p_fog_b = 0.1;
    }
  }
  if (fldGb->fieldID == 16)
  {
    this->fog_dark_dis = -300.0;
    this->fog_near = 5000.0;
  }
  v71 = fldGb;
  if (v71->fieldID == 34)
  {
    if (!v71->areaID)
    {
      *p_fog_near = 3500.0;
      *p_fog_min = 3.5;
    }
  }
  v72 = fldGb;
  if (v72->fieldID == 34)
  {
    else
    {
      v73 = v72->areaID;
      if (v73 == 1)
        goto LABEL_247;
    }
    if (v73 != 2)
      goto LABEL_248;
LABEL_247:
    this->fog_dark_dis = -1000.0;
  }
LABEL_248:
  if (fldGb->fieldID == 34)
  {
    v74 = fldLightMaChk();
    if (v74 != 1)
    {
      v75 = fldGb->areaID;
      if (v75 <= 8 && ((1 << v75) & 0x170) != 0)
      {
        this->fog_near_rimit = 0;
        this->fog_near = 120.0;
      }
    }
  }
  v76 = fldGb;
  if (v76->fieldID == 20)
  {
    if (v76->areaID == 29)
    {
      *p_fog_near = 400.0;
      *p_fog_min = 0.8;
    }
  }
  v77 = fldGb;
  if (v77->fieldID == 17)
  {
    if (!v77->areaID)
    {
      *p_fog_near = 6500.0;
      *p_fog_min = 1.25;
    }
  }
  v78 = fldGb;
  if (v78->fieldID == 43)
  {
    if (v78->areaID == 29)
      *p_fog_min = 1.2;
  }
  v79 = fldGb;
  if (v79->fieldID == 32)
  {
    if (v79->areaID == 18)
    {
      *p_fog_r = 0.001;
      *p_fog_g = 0.001;
      *p_fog_b = 0.001;
    }
  }
  v80 = fldGb;
  if (v80->fieldID == 45)
  {
    if (v80->areaID == 29)
      *p_fog_near = 1500.0;
  }
  v81 = fldGb;
  if (v81->fieldID == 31)
  {
    if (v81->areaID == 5)
    {
      *p_fog_min = 1.0;
      *p_fog_near = 1000.0;
    }
  }
  v82 = fldGb;
  if (v82->fieldID == 31)
  {
    if (v82->areaID == 6)
      *p_fog_near = 1000.0;
  }
  v83 = fldGb;
  if (v83->fieldID == 31)
  {
    if (v83->areaID == 10)
      *p_fog_near = 1300.0;
  }
  v84 = fldGb;
  if (v84->fieldID == 31)
  {
    if (v84->areaID == 11)
      *p_fog_near = 1000.0;
  }
  v85 = fldGb;
  if (v85->fieldID == 42)
  {
    if (v85->areaID == 4)
    {
      *p_fog_min = 0.8;
      *p_fog_near = 300.0;
    }
  }
  v86 = fldGb;
  if (v86->fieldID == 27)
  {
    v87 = v86->areaID;
    if (v87 <= 4 && v87 != 1)
    {
      this->fog_dark_dis = -300.0;
      this->fog_near = 7000.0;
    }
  }
  v88 = fldGb;
  if (v88->fieldID == 15)
  {
    if (v88->areaID == 3)
      *p_fog_near = 9000.0;
  }
  v89 = fldGb;
  if (v89->fieldID == 15)
  {
    if (v89->areaID == 19)
      *p_fog_min = 0.90625;
  }
  v90 = fldGb;
  if (v90->fieldID == 15)
  {
    if ((v90->areaID - 2) <= 2)
    {
      *p_fog_min = 1.0;
      *p_fog_near = 5000.0;
    }
  }
  v91 = fldGb;
  if (v91->fieldID == 37)
  {
    else
    {
      v92 = v91->areaID;
      if (v92 == 14)
        goto LABEL_402;
    }
    if (v92 != 15)
      goto LABEL_407;
LABEL_402:
    if (fldLightMaChk() != 1)
    {
      *&this->fog_start = 0x430C000000000000LL;
      this->l0_b = 0.1;
      *&this->l0_r = 0x3DCCCCCD3DCCCCCDLL;
      *&this->fog_min = 0x40000000;
    }
  }
LABEL_407:
  if (fldGb->fieldID == 61)
  {
    *p_fog_near = 1500.0;
    *p_fog_r = 0.19153;
    *p_fog_g = 0.11719;
    *p_fog_b = 0.3125;
  }
  if (fldGb->fieldID == 730)
    this->fog_near_rimit = 0;
  if (this->flg_e697_field02 && *p_fog_near < 416.0)
    *p_fog_near = 416.0;
  if (this->flg_f681_001)
  {
    v94 = GetEventCamName();
    if (op_Equality(v94, "cam01", 0))
    {
      *p_fog_near = 225.0;
      v95 = 1036831949;
LABEL_449:
      *p_fog_r = v95;
      *p_fog_g = v95;
      *p_fog_b = v95;
      goto LABEL_450;
    }
    v96 = GetEventCamName();
    if (op_Equality(v96, "cam02", 0))
    {
      CamRunTime = GetCamRunTime();
      if (CamRunTime <= 219)
      {
        *p_fog_near = 900.0;
        goto LABEL_448;
      }
      v99 = fminf(((CamRunTime - 220) * 8.0) + 900.0, 1300.0);
LABEL_435:
      *p_fog_near = v99;
LABEL_448:
      v95 = 1008981770;
      goto LABEL_449;
    }
    v100 = GetEventCamName();
    if (op_Equality(v100, "cam03", 0))
      goto LABEL_444;
    v101 = GetEventCamName();
    if (op_Equality(v101, "cam04", 0))
    {
LABEL_444:
      v102 = *p_fog_near + 700.0;
      *p_fog_near = v102;
      *p_fog_r = 0.1;
      *p_fog_g = 0.1;
      *p_fog_b = 0.1;
      if (v102 < 1400.0)
        goto LABEL_450;
      goto LABEL_445;
    }
    v107 = GetEventCamName();
    if (op_Equality(v107, "cam08", 0))
    {
      v99 = fminf(((GetCamRunTime() - 30) * 8.0) + 900.0, 1300.0);
      goto LABEL_435;
    }
    v108 = *p_fog_near + 700.0;
    *p_fog_near = v108;
    if (v108 >= 1400.0)
    {
LABEL_445:
      *p_fog_near = 1400.0;
      if (this->fog_near_rimit)
        goto LABEL_451;
      goto LABEL_453;
    }
  }
LABEL_450:
  if (this->fog_near_rimit)
  {
LABEL_451:
    if (*p_fog_near < 255.0)
      *p_fog_near = 255.0;
  }
LABEL_453:
  v104 = fldGb;
  if (v104->fieldID == 25)
  {
    if (v104->areaID == 5)
      *p_fog_near = 2000.0;
  }
  if (fldGb->fieldID == 25
    && *p_fog_min > 1.6
    && *p_fog_near == 400.0
    && *p_fog_r > 1.4
    && *p_fog_g > 1.5
    && *p_fog_b > 1.9)
  {
    *p_fog_min = 0.65;
    *p_fog_near = 150.0;
  }
  this->fog_end = this->fog_near / 10.0;
LABEL_473:
  get_gameObject(this);
  SetLightAll(this, v105);
  (this->klass->vtable._21_UpdateOption.methodPtr)(this, this->klass->vtable._21_UpdateOption.method);
}
