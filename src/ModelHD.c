#include "types.h"

typedef struct ChildHD ChildHD;
typedef struct ModelHD ModelHD;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct sdfModelExtraChunkMarkPos_t sdfModelExtraChunkMarkPos_t;

static s32 id_LightColor;
static s32 id_ExLightColor;
static s32 id_LightVector;
static s32 id_ColorAmbient;
static s32 id_AmbientLight;
static s32 id_Toon;
static s32 id_ToonType;
static s32 id_ToonTypeStart;
static s32 id_ToonTypeDiv;
static s32 id_ToonRim;
static s32 id_FogColor;
static s32 id_FogStart;
static s32 id_FogEnd;
static s32 id_FogMin;
static s32 id_FogDarkSpotDis;
static s32 id_FogDarkSpotCol;
static s32 id_FogDarkSpotVec;
static s32 id_Config_Bright;
static s32 id_RasterLevel;
static s32 id_CombineClipY;
static s32 id_ModeOp;
static s32 id_SpecularTex;
static s32 id_SrefTex;
static s32 id_Use_FogOff;
static s32 id_AlfPower;
static s32 id_AlfRGBPower;
static s32 id_BlendOp;
static s32 id_SrcBlend;
static s32 id_DstBlend;
static s32 id_ZWrite;
static s32 id_all_r;
static s32 id_all_g;
static s32 id_all_b;
static s32 id_mDirect;
static s32 id_BlendPower;
static s32 id_Adj_Bright;
static s32 id_Adj_ColorR;
static s32 id_Adj_ColorG;
static s32 id_Adj_ColorB;
static s32 id_StencilComp;

void *GetMainCamera(dds3DefaultMain *this);
bool IsUpdate(XRD773Unity_GraphicManager *this);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void StepFrame(ModelHD *this);

// 0x12a2150
void AddMatList(ModelHD *this, void *mat) {
  System_Collections_Generic_List_float__o *modeop_list;
  f32 Float;

  modeop_list = this->modeop_list;
  if (modeop_list)
  {
    if (HasProperty(mat, id_ModeOp))
    {
      Float = GetFloat(mat, id_ModeOp, 0);
    }
    else
    {
      Float = -1.0;
    }
    _Add(modeop_list, Float);
  }
}

// 0x12a2370
void AddOption(ModelHD *this, ChildHD *opt) {
  u32 v5;
  UnityEngine_Object_o *v7;
  System_Collections_Generic_List_datEncount_t__o *option;

  if (this->mat_list)
  {
    v5 = 0;
    do
    {
      v7 = (opt->klass->vtable._23_GetOptionMaterial.methodPtr)(
             opt,
             v5,
             opt->klass->vtable._23_GetOptionMaterial.method);
      if (op_Equality(v7, 0, 0))
        break;
      ++v5;
      _Add(this->mat_list, v7);
      (this->klass->vtable._19_AddMatList.methodPtr)(this, v7, this->klass->vtable._19_AddMatList.method);
    }
    while (this->mat_list);
  }
  option = this->option;
  if (!option)
  {
    option = Allocate(System_Collections_Generic_List_ChildHD_);
    __ctor(
      option);
    this->option = option;
  }
  _Add(option, opt);
}

// 0x129fc50
void CallLateUpdate(ModelHD *this) {
  XRD773Unity_GraphicManager_o *Instance;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v5;

  if (this->chk_hide)
  {
    {
    }
    Instance = get_Instance();
    if (IsUpdate(Instance))
    {
      if (this->hide)
      {
        gameObject = get_gameObject(this);
        if (get_activeSelf(gameObject))
        {
          v5 = get_gameObject(this);
          SetActive(v5, 0, 0);
        }
      }
      this->hide = 1;
    }
  }
}

// 0x129fae0
void CallOnDestroy(ModelHD *this) {
  System_Collections_Generic_List_WeakReference_EtwSession___o *mat_list;
  UnityEngine_Object_o *v5;
  System_Collections_Generic_List_Enumerator_T__o v6;

  memset(&v6, 0, sizeof(v6));
  mat_list = this->mat_list;
  if (mat_list)
  {
    __GetEnumerator(&v6, mat_list);
    while ((sub_1A11200(&v6) & 1) != 0)
    {
      v5 = sub_1A11350(&v6);
      Destroy_27360000(v5);
    }
    nullsub_111(&v6);
    _Clear(this->mat_list);
    this->mat_list = 0;
  }
}

// 0x12a1710
bool ChangeRenderQueue(ModelHD *this) {
  struct System_Collections_Generic_List_Material__o *mat_list;
  s32 v4;
  s32 renderqueue_semi;
  f32 Item;
  System_WeakReference_o *v7;
  System_WeakReference_o *v8;
  s32 v10;

  v10 = 0;
  mat_list = this->mat_list;
  if (mat_list)
  {
    if (_get_Count(mat_list) >= 1)
    {
      v4 = 0;
      do
      {
        renderqueue_semi = this->renderqueue_semi;
        Item = _get_Item(
                 this->modeop_list,
                 v4);
        v10 = -1082130432;
        if (!sub_4FDAD0(&v10, Item))
        {
          v10 = 0;
          if (!sub_4FDAD0(&v10, Item))
          {
            v10 = 1065353216;
            if (!sub_4FDAD0(&v10, Item))
            {
              v10 = 1082130432;
              if (sub_4FDAD0(&v10, Item))
              {
                renderqueue_semi = this->renderqueue_add;
              }
              else
              {
                v10 = 1084227584;
                if (sub_4FDAD0(&v10, Item)
                  || (v10 = 1088421888, sub_4FDAD0(&v10, Item))
                  || (v10 = 1090519040, sub_4FDAD0(&v10, Item)))
                {
                  renderqueue_semi = this->renderqueue_sub;
                }
              }
              v7 = _get_Item(
                     this->mat_list,
                     v4);
              if ((get_renderQueue(v7) - 3000) <= 0x3E7)
              {
                v8 = _get_Item(
                       this->mat_list,
                       v4);
                set_renderQueue(v8, renderqueue_semi);
              }
            }
          }
        }
        ++v4;
      }
      while (v4 < _get_Count(this->mat_list));
    }
    LOBYTE(mat_list) = 1;
  }
  return mat_list;
}

// 0x129ff80
void *GetGameObjectByName(ModelHD *this, char *aName) {
  UnityEngine_GameObject_o *result;
  System_Collections_Generic_Dictionary_object__object__o *allobject;
  const MethodInfo_1221 *v7;
  Il2CppObject *v8;
  System_String_o *v9;
  bool v10;

  result = this->allobject;
  if (result)
  {
    if (!Animator___ContainsKey(result, aName))
    {
      aName = Replace_5267216(aName, " ", "_");
      if (!Animator___ContainsKey(this->allobject, aName))
      {
        v9 = Replace_5267216(aName, "脊椎", "spine");
        if (Animator___ContainsKey(this->allobject, v9)
          || (v9 = Replace_5267216(aName, "脊椎", "Spine"),
              Animator___ContainsKey(this->allobject, v9))
          || (v9 = Replace_5267216(aName, "首", "neck"),
              Animator___ContainsKey(this->allobject, v9)))
        {
          allobject = this->allobject;
          v7 = Method_System_Collections_Generic_Dictionary_string__GameObject__get_Item__;
          v8 = v9;
          return object___get_Item(allobject, v8, v7);
        }
        aName = Replace_5267216(aName, "首", "Neck");
        v10 = Animator___ContainsKey(this->allobject, aName);
        result = 0;
        if (!v10)
          return result;
      }
    }
    allobject = this->allobject;
    v7 = Method_System_Collections_Generic_Dictionary_string__GameObject__get_Item__;
    v8 = aName;
    return object___get_Item(allobject, v8, v7);
  }
  return result;
}

// 0x12a1eb0
bool GetListMatelial(ModelHD *this, void *list, void **mat) {
  UnityEngine_Object_o *v7;
  System_String_o *name;
  System_String_o *v9;
  System_String_o *v10;
  UnityEngine_Object_o *v11;
  System_String_o *v12;
  _BOOL8 v13;
  Il2CppObject *v15;
  Il2CppObject *v16;
  System_Collections_Generic_List_Enumerator_T__o v18;

  memset(&v18, 0, sizeof(v18));
  v7 = *mat;
  if (op_Inequality(v7, 0, 0))
  {
    name = get_name(*mat);
    v9 = (this->klass->vtable._18_GetMatelialKey.methodPtr)(this, this->klass->vtable._18_GetMatelialKey.method);
    v10 = Concat_5224608(name, v9);
    __GetEnumerator(&v18, list);
    while ((sub_1A11200(&v18) & 1) != 0)
    {
      v11 = sub_1A11350(&v18);
      v12 = get_name(v11);
      if (op_Equality(v12, v10, 0))
      {
        *mat = v11;
        nullsub_111(&v18);
        goto LABEL_11;
      }
    }
    nullsub_111(&v18);
    v15 = *mat;
    v16 = Instantiate_object_(v15);
    *mat = v16;
    set_name(v16, v10);
    _Add(list, *mat);
    return &xmmword_0 + 1;
  }
  else
  {
LABEL_11:
    LOBYTE(v13) = 0;
  }
  return v13;
}

// 0x12a1980
s32 GetMPosCount(ModelHD *this) {
  struct sdfModelExtraChunkMarkPos_t_array *mpos;

  mpos = this->mpos;
  if (mpos)
    return mpos->max_length;
  else
    return -1;
}

// 0x12a1a30
sdfModelExtraChunkMarkPos_t *GetMPosData(ModelHD *this, s32 id) {
  struct sdfModelExtraChunkMarkPos_t_array *mpos;
  il2cpp_array_size_t max_length;
  u64 v5;
  sdfModelExtraChunkMarkPos_t_o *result;

  mpos = this->mpos;
  if (!mpos)
    return 0;
  max_length = mpos->max_length;
  if (max_length < 1)
    return 0;
  v5 = 0;
  while (1)
  {
    result = mpos->m_Items[v5];
    if (result)
    {
      if (result->id == id)
        break;
    }
    LODWORD(max_length) = mpos->max_length;
    if (++v5 >= max_length)
      return 0;
  }
  return result;
}

// 0x12a2100
char *GetMatelialKey(ModelHD *this) {
  return "(mHD)";
}

// 0x12a2240
ModelHD *GetRoot(ModelHD *this) {
  return this;
}

// 0x129fc40
void LateUpdate(ModelHD *this) {
  (this->klass->vtable._5_CallLateUpdate.methodPtr)(this, this->klass->vtable._5_CallLateUpdate.method);
}

// 0x129fad0
void OnDestroy(ModelHD *this) {
  (this->klass->vtable._4_CallOnDestroy.methodPtr)(this, this->klass->vtable._4_CallOnDestroy.method);
}

// 0x129fd10
void SetActive(ModelHD *this, bool act) {
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

// 0x12a0150
void SetAlpha(ModelHD *this, f32 alpha) {
  long f64 v3;
  struct System_Collections_Generic_List_Material__o *mat_list;
  f32 v7;
  bool v8;
  s32 v9;
  System_WeakReference_o *Item;
  s32 v16;
  System_WeakReference_o *v17;
  f32 v18;

  mat_list = this->mat_list;
  if (mat_list)
  {
    v7 = fminf(alpha, 1.0);
    if (this->adjcol.w != v7)
    {
      v8 = v7 < 1.0 || this->modeop_list == 0;
      if (_get_Count(mat_list) >= 1)
      {
        if (v8)
        {
          LODWORD(v3) = 2.0;
          v9 = 0;
          do
          {
            Item = _get_Item(
                     this->mat_list,
                     v9);
            if (GetInt(Item, id_SrcBlend) != 5)
            {
              if (HasProperty(Item, id_ModeOp))
                (this->klass->vtable._14_SetupMaterialWithBlendOp.methodPtr)(
                  this,
                  Item,
                  this->klass->vtable._14_SetupMaterialWithBlendOp.v3);
            }
            SetFloat_27246832(Item, id_AlfPower, v7);
            ++v9;
          }
          while (v9 < _get_Count(this->mat_list));
        }
        else
        {
          v16 = 0;
          do
          {
            v17 = _get_Item(
                    this->mat_list,
                    v16);
            v18 = _get_Item(
                    this->modeop_list,
                    v16);
            (this->klass->vtable._14_SetupMaterialWithBlendOp.methodPtr)(
              this,
              v17,
              this->klass->vtable._14_SetupMaterialWithBlendOp.v18);
            SetFloat_27246832(v17, id_AlfPower, v7);
            ++v16;
          }
          while (v16 < _get_Count(this->mat_list));
        }
      }
      this->adjcol.w = v7;
    }
  }
}

// 0x12a03c0
void SetAlpha_19530688(ModelHD *this, u32 rgba) {
  long f64 v4;
  UnityEngine_Vector4_o v5;

  v5 = SDF_VU0__Retdds3ColorItoF(rgba, 128.0);
  *&v4 = v5.w;
  (this->klass->vtable._7_SetAlpha.methodPtr)(
    this,
    this->klass->vtable._7_SetAlpha.v4,
    v5.y,
    v5.z);
}

// 0x129fd70
void SetAutoHide(ModelHD *this, bool act) {
  this->chk_hide = act;
  this->hide = 1;
}

// 0x12a0790
void SetColor(ModelHD *this, sdfVector4_t color) {
  long f64 v4;
  long f64 v5;
  long f64 v6;

  v4 = *&color.w;
  v5 = *&color.z;
  v6 = *&color.y;
  (this->klass->vtable._7_SetAlpha.methodPtr)(this, this->klass->vtable._7_SetAlpha.*&color.w);
  (this->klass->vtable._9_SetRGB.methodPtr)(this, this->klass->vtable._9_SetRGB.*&color, v6, v5, v4);
}

// 0x12a0800
void SetColor_19531776(ModelHD *this, u32 color) {
  UnityEngine_Vector4_o v4;

  v4 = SDF_VU0__Retdds3ColorItoF(color, 128.0);
  (this->klass->vtable._11_SetColor.methodPtr)(
    this,
    this->klass->vtable._11_SetColor.v4.x,
    v4.y,
    v4.z,
    v4.w);
}

// 0x12a0840
void SetFogSpot(ModelHD *this, u32 type) {
  UnityEngine_Object_o *fldPlayerObj;
  UnityEngine_GameObject_o *v9;
  UnityEngine_GameObject_o *MainCamera;
  UnityEngine_Transform_o *transform;
  f32 x;
  f32 y;
  f32 z;
  UnityEngine_Transform_o *v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Transform_o *v19;
  f32 v20;
  f32 v21;
  f32 v22;
  UnityEngine_Transform_o *v23;
  UnityEngine_Transform_o *v24;
  UnityEngine_Transform_o *v25;
  struct fldGlobalWork_t_o *fldGb;
  s64 v29;
  f32 v30;
  UnityEngine_Vector3_o v31;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Vector3_o v33;
  UnityEngine_Vector3_o v34;

  *&this->fog_dark_vec.z = 0;
  *&this->fog_dark_vec.x = 0;
  *&this->fog_dark_dis = 0;
  if (op_Inequality(fldPlayerObj, 0, 0))
  {
    v9 = fldPlayerObj;
    MainCamera = GetMainCamera(kernelObject);
    transform = get_transform(MainCamera, 0);
    rotation = get_rotation(transform);
    if (type)
    {
      x = this->fog_dark_vecoff1.x;
      y = this->fog_dark_vecoff1.y;
      z = this->fog_dark_vecoff1.z;
      {
      }
      v33.x = x;
      v33.y = y;
      v33.z = z;
      op_Multiply_27379552(rotation, v33);
      v17 = get_transform(v9, 0);
      this->fog_dark_vec.x = get_position(v17).x;
      v18 = get_transform(v9, 0);
      this->fog_dark_vec.y = get_position(v18).y + 1.0;
      v19 = get_transform(v9, 0);
      v30 = get_position(v19).z;
    }
    else
    {
      v20 = this->fog_dark_vecoff0.x;
      v21 = this->fog_dark_vecoff0.y;
      v22 = this->fog_dark_vecoff0.z;
      {
      }
      v34.x = v20;
      v34.y = v21;
      v34.z = v22;
      v31 = op_Multiply_27379552(rotation, v34);
      v23 = get_transform(v9, 0);
      this->fog_dark_vec.x = v31.x + get_position(v23).x;
      v24 = get_transform(v9, 0);
      this->fog_dark_vec.y = (v31.y + get_position(v24).y) + 1.0;
      v25 = get_transform(v9, 0);
      v30 = v31.z + COERCE_FLOAT(LODWORD(get_position(v25).z));
    }
    this->fog_dark_vec.z = v30;
    this->fog_dark_vec.w = 0.0;
  }
  if (gFldNowDZone)
  {
    else
    {
      if (fldGb->LightMa)
        return;
    }
    if (fldGb->fieldID <= 199)
    {
      if (type)
        v29 = 1077936128;
      else
        v29 = 1082130432;
      *&this->fog_dark_dis = v29 & 0xFFFFFFFFFFFFLL | 0x4000000000000000LL;
    }
  }
}

// 0x129fd90
void SetFrameAnime(ModelHD *this, bool act) {
  _BOOL4 v3;
  UnityEngine_Object_o *frame_anm;
  UnityEngine_Object_o *animator;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Object_o *v10;

  v3 = act;
  frame_anm = this->frame_anm;
  if (((op_Inequality(frame_anm, 0, 0) ^ v3) & 1) != 0)
  {
    animator = this->animator;
    if (!op_Equality(animator, 0, 0))
    {
      if (v3)
      {
        gameObject = get_gameObject(this->animator);
        this->frame_anm = AddComponent_object_(gameObject);
      }
      else
      {
        v10 = this->frame_anm;
        Destroy_27360000(v10);
        this->frame_anm = 0;
      }
    }
  }
}

// 0x12a18f0
void SetMPosCount(ModelHD *this, s32 count) {
  if ((byte_3F591C1 & 1) != 0)
  {
    if (this->mpos)
      return;
LABEL_5:
    this->mpos = NewSpecific(sdfModelExtraChunkMarkPos_t, count);
    return;
  }
  if (!this->mpos)
    goto LABEL_5;
}

// 0x12a19a0
void SetMPosData(ModelHD *this, s32 index, sdfModelExtraChunkMarkPos_t *data) {
  struct sdfModelExtraChunkMarkPos_t_array *mpos;

  mpos = this->mpos;
  mpos->m_Items[index] = data;
}

// 0x12a1ac0
void SetMatInit(ModelHD *this, void *rootobj) {
  struct System_Collections_Generic_Dictionary_string__GameObject__o *allobject;
  System_String_o *name;
  struct System_Collections_Generic_Dictionary_string__GameObject__o *v7;
  System_String_o *v8;
  UnityEngine_Object_o *animator;
  Il2CppObject *Component_object;
  UnityEngine_Material_array *sharedMaterials;
  il2cpp_array_size_t max_length;
  u32 *v14;
  u64 v15;
  s64 **m_Items;
  s64 *v19;
  UnityEngine_Transform_o *transform;
  s64 *Enumerator;
  UnityEngine_Component_o *v23;
  UnityEngine_Component_c *klass;
  s64 typeHierarchyDepth;
  char *v26;
  s64 *v27;
  UnityEngine_GameObject_o *gameObject;
  s64 *Interface;
  u64 v30[3];
  s64 *v31;

  v31 = 0;
  allobject = this->allobject;
  if (allobject)
  {
    name = get_name(rootobj);
    if (!Animator___ContainsKey(allobject, name))
    {
      v7 = this->allobject;
      v8 = get_name(rootobj);
      PropertySheet___Add(v7, v8, rootobj);
    }
  }
  animator = this->animator;
  if (op_Equality(animator, 0, 0))
    this->animator = GetComponent_object_(rootobj);
  Component_object = GetComponent_object_(rootobj);
  if (op_Inequality(Component_object, 0, 0))
  {
    sharedMaterials = get_sharedMaterials(Component_object);
    max_length = sharedMaterials->max_length;
    v14 = sharedMaterials;
    if (max_length >= 1)
    {
      v15 = 0;
      m_Items = sharedMaterials->m_Items;
      do
      {
        v31 = *m_Items;
        if (((this->klass->vtable._17_GetListMatelial.methodPtr)(
                this,
                this->mat_list,
                &v31,
                this->klass->vtable._17_GetListMatelial.method)
            & 1) != 0)
          (this->klass->vtable._19_AddMatList.methodPtr)(this, v31, this->klass->vtable._19_AddMatList.method);
        v19 = v31;
        max_length = v14[6];
        ++v15;
        *m_Items++ = v19;
      }
      while (v15 < max_length);
    }
    set_sharedMaterials(Component_object, v14);
  }
  transform = get_transform(rootobj, 0);
  Enumerator = GetEnumerator(transform);
  while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
  {
    v23 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
    if (v23)
    {
      klass = v23->klass;
      if (v23->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, v30);
        if ((v30[0] & 1) != 0)
          v26 = v30[2];
        else
          v26 = v30 + 1;
        v27 = sub_8C4940(v26);
      }
    }
    gameObject = get_gameObject(v23);
    (this->klass->vtable._16_SetMatInit.methodPtr)(this, gameObject, this->klass->vtable._16_SetMatInit.method);
  }
  Interface = QueryInterface(Enumerator, System_IDisposable);
  if (Interface)
    sub_22F10(0, System_IDisposable, Interface);
}

// 0x12a0400
void SetRGB(ModelHD *this, sdfVector4_t rgb) {
  f32 z;
  f32 y;
  f32 x;
  System_Collections_Generic_List_WeakReference_EtwSession___o *mat_list;
  f32 v8;
  f32 v9;
  f32 v10;
  bool v11;
  UnityEngine_Material_o *v14;
  UnityEngine_Material_o *v20;
  System_Collections_Generic_List_Enumerator_T__o v23;
  System_Collections_Generic_List_Enumerator_T__o v24;

  z = rgb.z;
  y = rgb.y;
  x = rgb.x;
  memset(&v24, 0, sizeof(v24));
  mat_list = this->mat_list;
  if (mat_list)
  {
    v9 = this->adjcol.x;
    v8 = this->adjcol.y;
    v10 = this->adjcol.z;
    v11 = v9 == x && v8 == y;
    if (!v11 || v10 != z)
    {
      __GetEnumerator(&v23, mat_list);
      v24 = v23;
      if (v9 == x)
      {
        while ((sub_1A11200(&v24) & 1) != 0)
        {
          v20 = sub_1A11350(&v24);
          if (v8 != y)
          {
            SetFloat_27246832(v20, id_Adj_ColorG, y);
          }
          if (v10 != z)
          {
            SetFloat_27246832(v20, id_Adj_ColorB, z);
          }
        }
      }
      else
      {
        while ((sub_1A11200(&v24) & 1) != 0)
        {
          v14 = sub_1A11350(&v24);
          SetFloat_27246832(v14, id_Adj_ColorR, x);
          if (v8 != y)
          {
            SetFloat_27246832(v14, id_Adj_ColorG, y);
          }
          if (v10 != z)
          {
            SetFloat_27246832(v14, id_Adj_ColorB, z);
          }
        }
      }
      nullsub_111(&v24);
      this->adjcol.x = x;
      this->adjcol.y = y;
      this->adjcol.z = z;
    }
  }
}

// 0x12a0750
void SetRGB_19531600(ModelHD *this, u32 rgb) {
  UnityEngine_Vector4_o v4;

  v4 = SDF_VU0__Retdds3ColorItoF(rgb, 128.0);
  (this->klass->vtable._9_SetRGB.methodPtr)(
    this,
    this->klass->vtable._9_SetRGB.v4.x,
    v4.y,
    v4.z,
    v4.w);
}

// 0x12a0bb0
void SetupMaterialWithBlendOp(ModelHD *this, void *material, f32 blendOp) {
  s32 renderqueue_semi;
  UnityEngine_Material_o *v15;
  s32 id_BlendOp;
  s32 v17;
  s32 id_ZWrite;
  UnityEngine_Material_o *v21;
  s32 v22;
  s32 id_SrcBlend;
  s32 v28;
  UnityEngine_Material_o *v29;
  s32 id_DstBlend;
  UnityEngine_Material_o *v31;
  s32 v32;
  s32 v44;

  v44 = 0;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "");
    SetInt_27247136(material, id_BlendOp, 0);
    SetInt_27247136(material, id_SrcBlend, 1);
    SetInt_27247136(material, id_DstBlend, 0);
    SetInt_27247136(material, id_ZWrite, 1);
    DisableKeyword(material, "_ALPHATEST_ON");
    DisableKeyword(material, "_ALPHABLEND_ON");
    DisableKeyword(material, "_ALPHAPREMULTIPLY_ON");
    DisableKeyword(material, "_ALPHAMODULATE_ON");
    renderqueue_semi = -1;
    goto LABEL_27;
  }
  v44 = 1065353216;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "TransparentCutout");
    SetInt_27247136(material, id_BlendOp, 0);
    SetInt_27247136(material, id_SrcBlend, 1);
    SetInt_27247136(material, id_DstBlend, 0);
    SetInt_27247136(material, id_ZWrite, 1);
    EnableKeyword(material, "_ALPHATEST_ON");
    DisableKeyword(material, "_ALPHABLEND_ON");
    DisableKeyword(material, "_ALPHAPREMULTIPLY_ON");
    DisableKeyword(material, "_ALPHAMODULATE_ON");
    renderqueue_semi = 2450;
    goto LABEL_27;
  }
  v44 = 0x40000000;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    v15 = material;
    v17 = 0;
LABEL_18:
    SetInt_27247136(v15, id_BlendOp, v17);
    SetInt_27247136(material, id_SrcBlend, 5);
    SetInt_27247136(material, id_DstBlend, 10);
    SetInt_27247136(material, id_ZWrite, 0);
    DisableKeyword(material, "_ALPHATEST_ON");
    EnableKeyword(material, "_ALPHABLEND_ON");
    DisableKeyword(material, "_ALPHAPREMULTIPLY_ON");
LABEL_25:
    DisableKeyword(material, "_ALPHAMODULATE_ON");
LABEL_26:
    renderqueue_semi = this->renderqueue_semi;
LABEL_27:
    set_renderQueue(material, renderqueue_semi);
    return;
  }
  v44 = 1077936128;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    SetInt_27247136(material, id_BlendOp, 0);
    SetInt_27247136(material, id_SrcBlend, 1);
    SetInt_27247136(material, id_DstBlend, 10);
    v21 = material;
    v22 = 0;
LABEL_24:
    SetInt_27247136(v21, id_ZWrite, v22);
    DisableKeyword(material, "_ALPHATEST_ON");
    DisableKeyword(material, "_ALPHABLEND_ON");
    EnableKeyword(material, "_ALPHAPREMULTIPLY_ON");
    goto LABEL_25;
  }
  v44 = 1082130432;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    SetInt_27247136(material, id_BlendOp, 0);
    SetInt_27247136(material, id_SrcBlend, 5);
    SetInt_27247136(material, id_DstBlend, 1);
    SetInt_27247136(material, id_ZWrite, 0);
    DisableKeyword(material, "_ALPHATEST_ON");
    EnableKeyword(material, "_ALPHABLEND_ON");
    DisableKeyword(material, "_ALPHAPREMULTIPLY_ON");
    DisableKeyword(material, "_ALPHAMODULATE_ON");
    renderqueue_semi = this->renderqueue_add;
    goto LABEL_27;
  }
  v44 = 1084227584;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    SetInt_27247136(material, id_BlendOp, 2);
    v28 = 5;
    v29 = material;
LABEL_39:
    SetInt_27247136(v29, id_SrcBlend, v28);
    v31 = material;
    v32 = 1;
LABEL_40:
    SetInt_27247136(v31, id_DstBlend, v32);
    SetInt_27247136(material, id_ZWrite, 0);
    DisableKeyword(material, "_ALPHATEST_ON");
    EnableKeyword(material, "_ALPHABLEND_ON");
    DisableKeyword(material, "_ALPHAPREMULTIPLY_ON");
    DisableKeyword(material, "_ALPHAMODULATE_ON");
    renderqueue_semi = this->renderqueue_sub;
    goto LABEL_27;
  }
  v44 = 1086324736;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    SetInt_27247136(material, id_BlendOp, 0);
    SetInt_27247136(material, id_SrcBlend, 2);
    SetInt_27247136(material, id_DstBlend, 10);
    SetInt_27247136(material, id_ZWrite, 0);
    DisableKeyword(material, "_ALPHATEST_ON");
    DisableKeyword(material, "_ALPHABLEND_ON");
    DisableKeyword(material, "_ALPHAPREMULTIPLY_ON");
    EnableKeyword(material, "_ALPHAMODULATE_ON");
    goto LABEL_26;
  }
  v44 = 1088421888;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    SetInt_27247136(material, id_BlendOp, 2);
    v29 = material;
    v28 = 2;
    goto LABEL_39;
  }
  v44 = 1090519040;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    SetInt_27247136(material, id_BlendOp, 2);
    SetInt_27247136(material, id_SrcBlend, 5);
    v32 = 10;
    v31 = material;
    goto LABEL_40;
  }
  v44 = 1091567616;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    v15 = material;
    v17 = 1;
    goto LABEL_18;
  }
  v44 = 1092616192;
  if (sub_4FDAD0(&v44, blendOp))
  {
    SetOverrideTag(material, "RenderType", "Transparent");
    SetInt_27247136(material, id_BlendOp, 0);
    SetInt_27247136(material, id_SrcBlend, 1);
    SetInt_27247136(material, id_DstBlend, 10);
    v21 = material;
    v22 = 1;
    goto LABEL_24;
  }
}

// 0x129feb0
void StepFrame(ModelHD *this) {
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v4;
  UnityEngine_Object_o *frame_anm;

  if (this->chk_hide)
  {
    gameObject = get_gameObject(this);
    if (!get_activeSelf(gameObject))
    {
      v4 = get_gameObject(this);
      SetActive(v4, 1, 0);
    }
    this->hide = 0;
  }
  frame_anm = this->frame_anm;
  if (op_Inequality(frame_anm, 0, 0))
    StepFrame(this->frame_anm);
}

// 0x12a2250
void UpdateOption(ModelHD *this) {
  struct System_Collections_Generic_List_ChildHD__o *option;
  s64 v4;
  System_Collections_Generic_List_Enumerator_T__o v5;

  memset(&v5, 0, sizeof(v5));
  option = this->option;
  if (option)
  {
    __GetEnumerator(&v5, option);
    while ((sub_1A11200(&v5) & 1) != 0)
    {
      v4 = sub_1A11350(&v5);
      (*(*v4 + 632LL))(v4, *(*v4 + 640LL));
    }
    nullsub_111(&v5);
  }
}
