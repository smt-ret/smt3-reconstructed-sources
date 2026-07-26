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
}

// 0x12a1710
bool ChangeRenderQueue(ModelHD *this) {
    return 0;
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
      aName = Replace_5267216(aName, StringLiteral_212, StringLiteral_558);
      if (!Animator___ContainsKey(this->allobject, aName))
      {
        v9 = Replace_5267216(aName, StringLiteral_5202, StringLiteral_5203);
        if (Animator___ContainsKey(this->allobject, v9)
          || (v9 = Replace_5267216(aName, StringLiteral_5202, StringLiteral_5204),
              Animator___ContainsKey(this->allobject, v9))
          || (v9 = Replace_5267216(aName, StringLiteral_5205, StringLiteral_5206),
              Animator___ContainsKey(this->allobject, v9)))
        {
          allobject = this->allobject;
          v7 = Method_System_Collections_Generic_Dictionary_string__GameObject__get_Item__;
          v8 = v9;
          return object___get_Item(allobject, v8, v7);
        }
        aName = Replace_5267216(aName, StringLiteral_5205, StringLiteral_5207);
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
    return 0;
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
  return StringLiteral_5209;
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
    this->mpos = NewSpecific(sdfModelExtraChunkMarkPos_t, count);
    return;
  }
  if (!this->mpos)
}

// 0x12a19a0
void SetMPosData(ModelHD *this, s32 index, sdfModelExtraChunkMarkPos_t *data) {
  struct sdfModelExtraChunkMarkPos_t_array *mpos;

  mpos = this->mpos;
  mpos->m_Items[index] = data;
}

// 0x12a1ac0
void SetMatInit(ModelHD *this, void *rootobj) {
}

// 0x12a0400
void SetRGB(ModelHD *this, sdfVector4_t rgb) {
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
}
