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
    SetLightInit(0, 0);
    GetMainCamera(0);
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
}

// 0xff4ba0
void SetFiledName(FieldBgHD *this, char *name) {
  this->filedname = name;
}

// 0xff49a0
void SetLayerAll(FieldBgHD *this, void *rootobj, s32 setlayer) {
}

// 0xff4340
void SetLightAll(FieldBgHD *this, void *rootobj) {
}

// 0xff2080
void SetLightInit(FieldBgHD *this, void *rootobj) {
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
                if (Contains(name, StringLiteral_4650, 0))
                {
                  if (v20 >= v19[6])
                }
                else
                {
                  v29 = get_name(m_Items[v20]);
                  v31 = Concat_5224608(v29, StringLiteral_4650);
                  v33 = m_Items[v20];
                  {
                  }
                  v34 = Instantiate_object_(v33);
                  v35 = v34;
                  m_Items[v20] = v35;
                  set_name(v35, v31);
                  _Add(this->mat_list, m_Items[v20]);
                }
                v27 = m_Items[v20];
                if (!HasProperty(v27, id_ModeOp))
                v42 = m_Items[v20];
                if (GetFloat(v42, id_ModeOp, 0) == 0.0)
                {
                  SetOverrideTag(m_Items[v20], StringLiteral_4782, StringLiteral_4783);
                  v48 = m_Items[v20];
                  SetInt_27247136(v48, id_BlendOp, 0);
                  SetInt_27247136(m_Items[v20], id_SrcBlend, 5);
                  SetInt_27247136(m_Items[v20], id_DstBlend, 10);
                  SetInt_27247136(m_Items[v20], id_ZWrite, 0);
                  DisableKeyword(m_Items[v20], StringLiteral_4784);
                  EnableKeyword(m_Items[v20], StringLiteral_4785);
                  DisableKeyword(m_Items[v20], StringLiteral_4786);
                  DisableKeyword(m_Items[v20], StringLiteral_4787);
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
    GetEventCamName();
    fldLightMaChk();
    GetCamRunTime();
    SetLightAll(0, 0);
}
