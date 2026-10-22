#include "types.h"

typedef struct RippleEffect RippleEffect;

void UpdateShaderParameters(RippleEffect *this);

// 0x1892b80
void Awake(RippleEffect *this) {
  this->initflg = 0;
}

// 0x1892db0
void OnRenderImage(RippleEffect *this, void *source, void *destination) {
  UnityEngine_Material_o *material;

  if (this->initflg)
  {
    material = this->material;
    Blit_27233792(source, destination, material);
  }
  else
  {
    Blit(source, destination, 0);
  }
}

// 0x1892b90
void Update(RippleEffect *this) {
  UnityEngine_Object_o *shader;
  u64 *v4;
  s32 v5;
  UnityEngine_Texture2D_o *gradTexture;
  s32 i;
  s32 v8;
  f32 v9;
  UnityEngine_Texture2D_o *v10;
  s32 v11;
  UnityEngine_Shader_o *v12;
  u64 *v13;
  UnityEngine_Color_o v15;

  if (this->initflg)
    goto LABEL_12;
  shader = this->shader;
  if (!op_Inequality(shader, 0, 0))
  {
LABEL_12:
    UpdateShaderParameters(this);
  }
  else
  {
    v4 = Allocate(UnityEngine_Texture2D);
    _ctor_27469040(v4, 2048, 1, 1, 0);
    this->gradTexture = v4;
    set_wrapMode(v4, 1);
    set_filterMode(this->gradTexture, 1);
    v5 = (this->gradTexture->klass->vtable._4_get_width.methodPtr)(
           this->gradTexture,
           this->gradTexture->klass->vtable._4_get_width.method);
    gradTexture = this->gradTexture;
    if (v5 >= 1)
    {
      for (i = 0; i < v11; ++i)
      {
        v8 = (gradTexture->klass->vtable._4_get_width.methodPtr)(
               gradTexture,
               gradTexture->klass->vtable._4_get_width.method);
        v9 = Evaluate(this->waveform, (1.0 / v8) * i, 0);
        v10 = this->gradTexture;
        *&v15.r = 0;
        *&v15.b = 0;
        sub_19EC630(&v15.r, v9, v9, v9, v9);
        SetPixel(v10, i, 0, v15);
        v11 = (this->gradTexture->klass->vtable._4_get_width.methodPtr)(
                this->gradTexture,
                this->gradTexture->klass->vtable._4_get_width.method);
        gradTexture = this->gradTexture;
      }
    }
    Apply_27472496(gradTexture);
    v12 = this->shader;
    v13 = Allocate(UnityEngine_Material);
    _ctor(v13, v12, 0);
    this->material = v13;
    set_hideFlags(v13, 52);
    SetTexture(this->material, "_GradTex", this->gradTexture, 0);
    UpdateShaderParameters(this);
    this->initflg = 1;
  }
}

// 0x1892510
void UpdateShaderParameters(RippleEffect *this) {
  UnityEngine_Camera_o *Component_GUILayer;
  struct System_Single_array *Postblur_rippeblur_area;
  struct System_Single_array *Postblur_rippeblur_center_x;
  struct System_Single_array *Postblur_rippeblur_center_y;
  struct System_Single_array *Postblur_rippeblur_time;
  struct System_Single_array *v14;
  struct System_Single_array *v16;
  struct System_Single_array *v18;
  struct System_Single_array *v20;
  struct System_Single_array *v22;
  struct System_Single_array *v24;
  struct System_Single_array *v26;
  struct System_Single_array *v28;
  struct System_Single_array *v30;
  struct System_Single_array *v32;
  struct System_Single_array *v34;
  struct System_Single_array *v36;
  struct System_Single_array *v38;
  struct System_Single_array *v40;
  struct System_Single_array *v42;
  struct System_Single_array *v44;
  f32 rippleblur_center_x_1;
  f32 rippleblur_area_1;
  f32 v48;
  f32 rippleblur_center_y_1;
  f32 ripple_time_1;
  UnityEngine_Material_o *material;
  f32 rippleblur_center_x_2;
  f32 rippleblur_area_2;
  UnityEngine_Material_o *v54;
  f32 rippleblur_center_y_2;
  f32 ripple_time_2;
  f32 rippleblur_center_x_3;
  f32 rippleblur_area_3;
  UnityEngine_Material_o *v59;
  f32 rippleblur_center_y_3;
  f32 ripple_time_3;
  f32 rippleblur_center_x_4;
  f32 rippleblur_area_4;
  UnityEngine_Material_o *v64;
  f32 rippleblur_center_y_4;
  f32 ripple_time_4;
  f32 rippleblur_center_x_5;
  f32 rippleblur_area_5;
  UnityEngine_Material_o *v69;
  f32 rippleblur_center_y_5;
  f32 ripple_time_5;
  UnityEngine_Material_o *v72;
  f32 aspect;
  f32 waveSpeed;
  UnityEngine_Material_o *v75;
  f32 v76;
  f32 refractionStrength;
  UnityEngine_Vector4_o v78;
  UnityEngine_Vector4_o v79;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o v82;
  UnityEngine_Vector4_o v83;
  UnityEngine_Vector4_o v84;
  UnityEngine_Color_o v85;

  Component_GUILayer = GetComponent_GUILayer_(this);
  this->refractionStrength = Postblur_rippeblur_power;
  this->rippleblur_area_1 = Postblur_rippeblur_area->m_Items[0];
  this->rippleblur_center_x_1 = Postblur_rippeblur_center_x->m_Items[0];
  this->rippleblur_center_y_1 = Postblur_rippeblur_center_y->m_Items[0];
  this->ripple_time_1 = Postblur_rippeblur_time->m_Items[0];
  v14 = Postblur_rippeblur_area;
  this->rippleblur_area_2 = v14->m_Items[1];
  v16 = Postblur_rippeblur_center_x;
  this->rippleblur_center_x_2 = v16->m_Items[1];
  v18 = Postblur_rippeblur_center_y;
  this->rippleblur_center_y_2 = v18->m_Items[1];
  v20 = Postblur_rippeblur_time;
  this->ripple_time_2 = v20->m_Items[1];
  v22 = Postblur_rippeblur_area;
  this->rippleblur_area_3 = v22->m_Items[2];
  v24 = Postblur_rippeblur_center_x;
  this->rippleblur_center_x_3 = v24->m_Items[2];
  v26 = Postblur_rippeblur_center_y;
  this->rippleblur_center_y_3 = v26->m_Items[2];
  v28 = Postblur_rippeblur_time;
  this->ripple_time_3 = v28->m_Items[2];
  v30 = Postblur_rippeblur_area;
  this->rippleblur_area_4 = v30->m_Items[3];
  v32 = Postblur_rippeblur_center_x;
  this->rippleblur_center_x_4 = v32->m_Items[3];
  v34 = Postblur_rippeblur_center_y;
  this->rippleblur_center_y_4 = v34->m_Items[3];
  v36 = Postblur_rippeblur_time;
  this->ripple_time_4 = v36->m_Items[3];
  v38 = Postblur_rippeblur_area;
  this->rippleblur_area_5 = v38->m_Items[4];
  v40 = Postblur_rippeblur_center_x;
  this->rippleblur_center_x_5 = v40->m_Items[4];
  v42 = Postblur_rippeblur_center_y;
  this->rippleblur_center_y_5 = v42->m_Items[4];
  v44 = Postblur_rippeblur_time;
  rippleblur_area_1 = this->rippleblur_area_1;
  rippleblur_center_x_1 = this->rippleblur_center_x_1;
  v48 = v44->m_Items[4];
  rippleblur_center_y_1 = this->rippleblur_center_y_1;
  ripple_time_1 = this->ripple_time_1;
  material = this->material;
  this->ripple_time_5 = v48;
  *&v84.x = 0;
  *&v84.z = 0;
  sub_854690(&v84.x, rippleblur_center_x_1, rippleblur_center_y_1, rippleblur_area_1, ripple_time_1);
  SetVector(material, "_Drop1", v84);
  rippleblur_area_2 = this->rippleblur_area_2;
  rippleblur_center_x_2 = this->rippleblur_center_x_2;
  v54 = this->material;
  rippleblur_center_y_2 = this->rippleblur_center_y_2;
  ripple_time_2 = this->ripple_time_2;
  *&v83.x = 0;
  *&v83.z = 0;
  sub_854690(&v83.x, rippleblur_center_x_2, rippleblur_center_y_2, rippleblur_area_2, ripple_time_2);
  SetVector(v54, "_Drop2", v83);
  rippleblur_area_3 = this->rippleblur_area_3;
  rippleblur_center_x_3 = this->rippleblur_center_x_3;
  v59 = this->material;
  rippleblur_center_y_3 = this->rippleblur_center_y_3;
  ripple_time_3 = this->ripple_time_3;
  *&v82.x = 0;
  *&v82.z = 0;
  sub_854690(&v82.x, rippleblur_center_x_3, rippleblur_center_y_3, rippleblur_area_3, ripple_time_3);
  SetVector(v59, "_Drop3", v82);
  rippleblur_area_4 = this->rippleblur_area_4;
  rippleblur_center_x_4 = this->rippleblur_center_x_4;
  v64 = this->material;
  rippleblur_center_y_4 = this->rippleblur_center_y_4;
  ripple_time_4 = this->ripple_time_4;
  *&v81.x = 0;
  *&v81.z = 0;
  sub_854690(&v81.x, rippleblur_center_x_4, rippleblur_center_y_4, rippleblur_area_4, ripple_time_4);
  SetVector(v64, "_Drop4", v81);
  rippleblur_area_5 = this->rippleblur_area_5;
  rippleblur_center_x_5 = this->rippleblur_center_x_5;
  v69 = this->material;
  rippleblur_center_y_5 = this->rippleblur_center_y_5;
  ripple_time_5 = this->ripple_time_5;
  *&v80.x = 0;
  *&v80.z = 0;
  sub_854690(&v80.x, rippleblur_center_x_5, rippleblur_center_y_5, rippleblur_area_5, ripple_time_5);
  SetVector(v69, "_Drop5", v80);
  v72 = this->material;
  aspect = get_aspect(Component_GUILayer);
  waveSpeed = this->waveSpeed;
  *&v79.x = 0;
  *&v79.z = 0;
  sub_854690(&v79.x, aspect, 1.0, 1.0 / waveSpeed, 0.0);
  SetVector(v72, "_Params1", v79);
  v75 = this->material;
  v76 = get_aspect(Component_GUILayer);
  refractionStrength = this->refractionStrength;
  *&v78.x = 0;
  *&v78.z = 0;
  sub_854690(&v78.x, 1.0, 1.0 / v76, refractionStrength, 0.0);
  SetVector(v75, "_Params2", v78);
  *&this->reflectionColor.r = 0x3C23D70A3C23D70ALL;
  this->reflectionColor.b = 0.01;
  v85.a = this->reflectionColor.a;
  v85.r = 0.01;
  v85.g = 0.01;
  v85.b = 0.01;
  SetColor(this->material, "_Reflection", v85, 0);
}
