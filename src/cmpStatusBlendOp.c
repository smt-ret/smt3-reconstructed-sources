#include "types.h"

typedef struct cmpStatusBlendOp cmpStatusBlendOp;
typedef struct dds3DefaultMain dds3DefaultMain;

static s32 id_RGB_Power;

s32 GetStChrMinor(dds3DefaultMain *this);
s32 GetStChrUnknown(dds3DefaultMain *this);
void SetStChrUnknown(dds3DefaultMain *this, s32 flag);
bool evtBitCheck(s32 no);

// 0x11cfc30
void Awake(cmpStatusBlendOp *this) {
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;

  gameObject = get_gameObject(this);
  Component_object = GetComponent_object_(gameObject);
  this->material = (Component_object->klass->vtable[32].methodPtr)(
                            Component_object,
                            Component_object->klass->vtable[32].method);
}

// 0x11cfca0
void Start(cmpStatusBlendOp *this) {
  ;
}

// 0x11cfcb0
void Update(cmpStatusBlendOp *this) {
  s32 StChrMinor;
  f32 v7;
  f32 v8;
  UnityEngine_Material_o *v11;
  UnityEngine_Material_o *v13;
  s32 v14;
  UnityEngine_Material_o *v17;
  struct UnityEngine_Material_o *v20;
  s32 *v21;
  UnityEngine_Material_o *v22;
  s32 v23;
  f32 v24;
  UnityEngine_Material_o *v27;
  UnityEngine_Material_o *v30;
  s32 id_BlendPower;
  f32 v32;
  UnityEngine_Material_o *material;
  struct UnityEngine_Material_o *v38;
  s32 *p_id_RGB_Power;

  StChrMinor = GetStChrMinor(kernelObject);
  if (GetStChrUnknown(kernelObject))
  {
    SetStChrUnknown(kernelObject, 0);
    v7 = 0.1;
    v8 = 0.25;
    if (StChrMinor != 87)
    {
LABEL_11:
      if (StChrMinor == 51)
      {
        if (!evtBitCheck(3717))
        {
          SetOverrideTag(this->material, "RenderType", "Transparent");
          material = this->material;
          SetInt_27247136(material, id_BlendOp, 0);
          SetInt_27247136(this->material, id_SrcBlend, 5);
          v13 = this->material;
          v14 = 1;
          goto LABEL_40;
        }
      }
      else if (StChrMinor == 37)
      {
        SetOverrideTag(this->material, "RenderType", "Transparent");
        v11 = this->material;
        SetInt_27247136(v11, id_BlendOp, 0);
        SetInt_27247136(this->material, id_SrcBlend, 1);
        v13 = this->material;
        v14 = 10;
LABEL_40:
        SetInt_27247136(v13, id_DstBlend, v14);
        SetInt_27247136(this->material, id_ZWrite, 0);
        DisableKeyword(this->material, "_ALPHATEST_ON");
        EnableKeyword(this->material, "_ALPHABLEND_ON");
        DisableKeyword(this->material, "_ALPHAPREMULTIPLY_ON");
LABEL_41:
        DisableKeyword(this->material, "_ALPHAMODULATE_ON");
        set_renderQueue(this->material, 3000);
        v32 = 100.0;
LABEL_42:
        SetFloat_27246832(this->material, id_BlendPower, v7 * v32);
        v38 = this->material;
        p_id_RGB_Power = &id_RGB_Power;
        v22 = v38;
        v23 = *p_id_RGB_Power;
        v24 = v8;
        goto LABEL_46;
      }
LABEL_28:
      SetOverrideTag(this->material, "RenderType", "Transparent");
      v27 = this->material;
      SetInt_27247136(v27, id_BlendOp, 0);
      SetInt_27247136(this->material, id_SrcBlend, 1);
      SetInt_27247136(this->material, id_DstBlend, 10);
      SetInt_27247136(this->material, id_ZWrite, 0);
      DisableKeyword(this->material, "_ALPHATEST_ON");
      DisableKeyword(this->material, "_ALPHABLEND_ON");
      EnableKeyword(this->material, "_ALPHAPREMULTIPLY_ON");
      goto LABEL_41;
    }
  }
  else
  {
    v7 = 1.0;
    v8 = 1.0;
    if (StChrMinor != 87)
      goto LABEL_11;
  }
  if (!evtBitCheck(3717))
  {
    SetOverrideTag(this->material, "RenderType", "Transparent");
    v30 = this->material;
    SetInt_27247136(v30, id_BlendOp, 0);
    SetInt_27247136(this->material, id_SrcBlend, 5);
    SetInt_27247136(this->material, id_DstBlend, 1);
    SetInt_27247136(this->material, id_ZWrite, 0);
    DisableKeyword(this->material, "_ALPHATEST_ON");
    EnableKeyword(this->material, "_ALPHABLEND_ON");
    DisableKeyword(this->material, "_ALPHAPREMULTIPLY_ON");
    DisableKeyword(this->material, "_ALPHAMODULATE_ON");
    set_renderQueue(this->material, 3000);
    v32 = 80.0;
    goto LABEL_42;
  }
  if (!evtBitCheck(3717))
    goto LABEL_28;
  SetOverrideTag(this->material, "RenderType", "Transparent");
  v17 = this->material;
  SetInt_27247136(v17, id_BlendOp, 0);
  SetInt_27247136(this->material, id_SrcBlend, 1);
  SetInt_27247136(this->material, id_DstBlend, 10);
  SetInt_27247136(this->material, id_ZWrite, 0);
  DisableKeyword(this->material, "_ALPHATEST_ON");
  DisableKeyword(this->material, "_ALPHABLEND_ON");
  EnableKeyword(this->material, "_ALPHAPREMULTIPLY_ON");
  DisableKeyword(this->material, "_ALPHAMODULATE_ON");
  set_renderQueue(this->material, 3000);
  SetFloat_27246832(this->material, id_BlendPower, v7 * 100.0);
  v20 = this->material;
  v21 = &id_RGB_Power;
  v22 = v20;
  v23 = *v21;
  v24 = v8 + v8;
LABEL_46:
  SetFloat_27246832(v22, v23, v24);
  this->st_minor = StChrMinor;
}
