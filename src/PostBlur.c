#include "types.h"

typedef struct PostBlur PostBlur;
typedef struct PostBlur_BlendType PostBlur_BlendType;

struct PostBlur_BlendType {
    s32 value__;
};

f32 GetConfigBright(void);
void dds3FadeColorGet(u32 *r, u32 *g, u32 *b, u32 *a);
u32 dds3GetKernelCount(void);
s32 encModeGet(void);
f32 perlinNoise(PostBlur *this, sdfVector2_t *uv, sdfVector2_t *size);

// 0x188e590
void Awake(PostBlur *this) {
  u64 *v3;
  UnityEngine_Texture2D_o **p_distTexture;
  s32 v5;
  u64 *v6;
  s32 v7;
  f32 v8;
  f32 v9;
  f32 v12;
  struct UnityEngine_Texture2D_o *distTexture;
  f32 x;
  f32 v15;
  s32 v16;
  u32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  u32 *v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  u32 v32;
  f32 *v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  s32 v39;
  s32 v40;
  s32 v41;
  s32 v42;
  u32 v43;
  s32 v44;
  s32 v45;
  u32 *v47;
  s32 v48;
  s32 v49;
  s32 v50;
  s32 v51;
  u32 v52;
  s32 v53;
  s32 v54;
  u32 *v56;
  s32 v57;
  s32 v58;
  s32 v59;
  s32 v60;
  s32 v61;
  s32 v62;
  s32 v63;
  u32 v64;
  u32 *v66;
  s32 v67;
  s32 v68;
  s32 v69;
  s32 v70;
  s32 v71;
  s32 v72;
  s32 v73;
  u32 v74;
  f32 *v76;
  f32 v77;
  f32 v78;
  s32 v79;
  s32 v80;
  s32 v82;
  f32 v83;
  s32 v84;
  f32 v85;
  f32 v86;
  s32 v87;
  s32 v88;
  s32 v89;
  s32 v90;
  f32 v91;
  f32 v92;
  f32 v93;
  f32 v96;
  struct UnityEngine_Texture2D_o *v97;
  f32 v98;
  f32 v99;
  f32 v100;
  s32 v101;
  s32 v102;
  s32 v103;
  s32 v104;
  s32 v105;
  u32 *v107;
  s32 v108;
  s32 v109;
  s32 v110;
  s32 v112;
  f32 v113;
  u32 v114;
  s32 v116;
  s32 v117;
  s32 v118;
  s32 v120;
  f32 v121;
  u32 v122;
  s32 v124;
  UnityEngine_Vector2_o *uv;
  s32 uva;
  UnityEngine_Vector2_o *uvb;
  u64 *v128;
  s32 v129;
  UnityEngine_Vector2_o *p_normalNoise_uv2;
  s64 v131;
  s64 v132;
  s64 v133;
  s64 v134;
  s64 v135;
  s64 v136;

  this->_MainTexID = PropertyToID("_MainTex");
  this->_ScreenTexID = PropertyToID("_ScreenTex");
  this->_DistortionTexID = PropertyToID("_DistortionTex");
  this->_FilterTexID = PropertyToID("_FilterTex");
  this->_BackupTexID = PropertyToID("_BackupTex");
  this->_FilterAlpID = PropertyToID("_FilterAlp");
  this->_BlurRotateID = PropertyToID("_BlurRotate");
  this->_BlurScaleID = PropertyToID("_BlurScale");
  this->_BlurBlendID = PropertyToID("_BlurBlend");
  this->_BlurColID = PropertyToID("_BlurCol");
  this->_BlurCenterID = PropertyToID("_BlurCenter");
  this->_MultiBlurRotateID = PropertyToID("_MultiBlurRotate");
  this->_MultiBlurScaleID = PropertyToID("_MultiBlurScale");
  this->_MultiBlurBlendID = PropertyToID("_MultiBlurBlend");
  this->_MultiBlurColID = PropertyToID("_MultiBlurCol");
  this->_MultiBlurAreaID = PropertyToID("_MultiBlurArea");
  this->_MultiBlurCenterID = PropertyToID("_MultiBlurCenter");
  this->_DistortionBlurTimeID = PropertyToID("_DistortionBlurTime");
  this->_DistortionBlurBlendID = PropertyToID("_DistortionBlurBlend");
  this->_DistortionBlurColID = PropertyToID("_DistortionBlurCol");
  this->_DistortionBlurAreaXID = PropertyToID("_DistortionBlurAreaX");
  this->_DistortionBlurAreaYID = PropertyToID("_DistortionBlurAreaY");
  this->_DistortionBlurCenterID = PropertyToID("_DistortionBlurCenter");
  this->_DistortionBlurDistor1ID = PropertyToID("_DistortionBlurDistor1");
  this->_DistortionBlurDistor2ID = PropertyToID("_DistortionBlurDistor2");
  this->_DistortionMoyaRotateID = PropertyToID("_DistortionMoyaRotate");
  this->_DistortionMoyaAlpID = PropertyToID("_DistortionMoyaAlp");
  this->_DistortionMoyaColID = PropertyToID("_DistortionMoyaCol");
  this->_FilterBlendID = PropertyToID("_FilterBlend");
  this->_FilterColID = PropertyToID("_FilterCol");
  this->_MultiFilterBlendID = PropertyToID("_MultiFilterBlend");
  this->_MultiFilterColID = PropertyToID("_MultiFilterCol");
  this->_MultiFilterAreaID = PropertyToID("_MultiFilterArea");
  this->_MultiFilterCenterID = PropertyToID("_MultiFilterCenter");
  this->_EncountBlurBlendID = PropertyToID("_EncountBlurBlend");
  this->_Encount1st_FadeColID = PropertyToID("_Encount1st_FadeCol");
  v3 = Allocate(UnityEngine_Texture2D);
  _ctor_27469040(v3, 512, 512, 4, 0);
  p_distTexture = &this->distTexture;
  this->distTexture = v3;
  set_wrapMode(v3, 0);
  set_filterMode(this->distTexture, 1);
  LODWORD(v3) = (this->distTexture->klass->vtable._4_get_width.methodPtr)(
                  this->distTexture,
                  this->distTexture->klass->vtable._4_get_width.method);
  v5 = (this->distTexture->klass->vtable._6_get_height.methodPtr)(
         this->distTexture,
         this->distTexture->klass->vtable._6_get_height.method);
  v6 = NewSpecific(UnityEngine_Color, (v5 * v3));
  if ((this->distTexture->klass->vtable._6_get_height.methodPtr)(
         this->distTexture,
         this->distTexture->klass->vtable._6_get_height.method) >= 2)
  {
    v129 = 0;
    uv = &this->normalNoise_uv2;
    do
    {
      if (((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
             *p_distTexture,
             (*p_distTexture)->klass->vtable._4_get_width.method) >= 2)
      {
        v7 = 0;
        do
        {
          v8 = (1.0
              / (this->distTexture->klass->vtable._4_get_width.methodPtr)(
                  this->distTexture,
                  this->distTexture->klass->vtable._4_get_width.method))
             * v7;
          v9 = (1.0
              / (this->distTexture->klass->vtable._6_get_height.methodPtr)(
                  this->distTexture,
                  this->distTexture->klass->vtable._6_get_height.method))
             * v129;
          this->normalNoise_uv2.x = v8;
          this->normalNoise_uv2.y = v9;
          this->normalNoise_size2.x = 1.3;
          this->normalNoise_size2.y = 1.3;
          this->normalNoise_ret.x = perlinNoise(this, uv, &this->normalNoise_size2);
          this->normalNoise_size2.x = 1.3;
          this->normalNoise_size2.y = 1.3;
          this->normalNoise_uv2.x = v8 + 2.0;
          this->normalNoise_uv2.y = v9 + 2.0;
          v12 = perlinNoise(this, uv, &this->normalNoise_size2);
          distTexture = this->distTexture;
          this->normalNoise_ret.y = v12;
          this->normalNoise_ret.z = 1.0;
          x = this->normalNoise_ret.x;
          v15 = v12;
          v16 = (distTexture->klass->vtable._4_get_width.methodPtr)(
                  distTexture,
                  distTexture->klass->vtable._4_get_width.method);
          v135 = 0;
          v136 = 0;
          sub_19EC630(&v135, x, v15, 0.0, 0.0);
          v17 = v7 + v129 * v16;
          v18 = HIDWORD(v135);
          v19 = v136;
          v20 = HIDWORD(v136);
          v22 = &v6[2 * v17];
          v22[8] = v135;
          v22[9] = v18;
          v22[10] = v19;
          v22[11] = v20;
          ++v7;
          v23 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          if (v23 >= 0)
            v24 = v23;
          else
            v24 = v23 + 1;
        }
        while (v7 < v24 >> 1);
      }
      v25 = v129 + 1;
      v26 = ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
              *p_distTexture,
              (*p_distTexture)->klass->vtable._6_get_height.method);
      if (v26 >= 0)
        v27 = v26;
      else
        v27 = v26 + 1;
      ++v129;
    }
    while (v25 < v27 >> 1);
  }
  if (((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
         *p_distTexture,
         (*p_distTexture)->klass->vtable._6_get_height.method) > 1)
  {
    v28 = 0;
    v29 = -1;
    do
    {
      uva = v29;
      if (((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
             *p_distTexture,
             (*p_distTexture)->klass->vtable._4_get_width.method) >= 2)
      {
        v30 = 0;
        v31 = -1;
        v124 = v28;
        do
        {
          v32 = v30
              + v28
              * ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v34 = &v6[2 * v32];
          v35 = v34[8];
          v36 = v34[9];
          v37 = v34[10];
          v38 = v34[11];
          v39 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v40 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v135 = 0;
          v136 = 0;
          sub_19EC630(&v135, v35, v36, v37, v38);
          v41 = v39 + v28 * v40;
          v42 = HIDWORD(v135);
          v43 = v31 + v41;
          v45 = v136;
          v44 = HIDWORD(v136);
          v47 = &v6[2 * v43];
          v47[8] = v135;
          v47[9] = v42;
          v47[10] = v45;
          v47[11] = v44;
          v48 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v49 = ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._6_get_height.method);
          v133 = 0;
          v134 = 0;
          sub_19EC630(&v133, v35, v36, v37, v38);
          v50 = uva + v49;
          v51 = HIDWORD(v133);
          v52 = v30 + v48 * v50;
          v54 = v134;
          v53 = HIDWORD(v134);
          v56 = &v6[2 * v52];
          v56[8] = v133;
          v56[9] = v51;
          v56[10] = v54;
          v56[11] = v53;
          v57 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v58 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v59 = ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._6_get_height.method);
          v131 = 0;
          v132 = 0;
          sub_19EC630(&v131, v35, v36, v37, v38);
          v60 = v57 + v58 * (uva + v59);
          v61 = HIDWORD(v131);
          v63 = v132;
          v62 = HIDWORD(v132);
          v64 = v31 + v60;
          v66 = &v6[2 * v64];
          v66[8] = v131;
          v66[9] = v61;
          v66[10] = v63;
          v66[11] = v62;
          ++v30;
          v67 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v28 = v124;
          if (v67 >= 0)
            v68 = v67;
          else
            v68 = v67 + 1;
          --v31;
        }
        while (v30 < v68 >> 1);
      }
      ++v28;
      v69 = ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
              *p_distTexture,
              (*p_distTexture)->klass->vtable._6_get_height.method);
      if (v69 >= 0)
        v70 = v69;
      else
        v70 = v69 + 1;
      v29 = uva - 1;
    }
    while (v28 < v70 >> 1);
  }
  if (((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
         *p_distTexture,
         (*p_distTexture)->klass->vtable._6_get_height.method) >= 1)
  {
    v128 = v6;
    p_normalNoise_uv2 = &this->normalNoise_uv2;
    v71 = 0;
    uvb = &this->normalNoise_size2;
    do
    {
      if (((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
             *p_distTexture,
             (*p_distTexture)->klass->vtable._4_get_width.method) >= 1)
      {
        v72 = 0;
        v73 = 0;
        do
        {
          v74 = v73
              + v71
              * ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v76 = &v6[2 * v74];
          v78 = v76[8];
          v77 = v76[9];
          v79 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          v80 = ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._6_get_height.method);
          if (v80 >= 0)
            v82 = v80;
          else
            v82 = v80 + 1;
          v83 = ((v82 >> 1) - v71);
          if (v79 >= 0)
            v84 = v79;
          else
            v84 = v79 + 1;
          v85 = (v72 + (v84 >> 1));
          v86 = sqrtf((v85 * v85) + (v83 * v83));
          v87 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                  *p_distTexture,
                  (*p_distTexture)->klass->vtable._4_get_width.method);
          if (v87 >= 0)
            v88 = v87;
          else
            v88 = v87 + 1;
          if (v86 > (v88 >> 1))
          {
            v89 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                    *p_distTexture,
                    (*p_distTexture)->klass->vtable._4_get_width.method);
            if (v89 >= 0)
              v90 = v89;
            else
              v90 = v89 + 1;
            v86 = (v90 >> 1);
          }
          v91 = (v86
               * (1.0
                / ((this->distTexture->klass->vtable._4_get_width.methodPtr)(
                     this->distTexture,
                     this->distTexture->klass->vtable._4_get_width.method)
                 * -0.5)))
              + 1.0;
          v92 = (1.0
               / (this->distTexture->klass->vtable._4_get_width.methodPtr)(
                   this->distTexture,
                   this->distTexture->klass->vtable._4_get_width.method))
              * v73;
          v93 = (1.0
               / (this->distTexture->klass->vtable._6_get_height.methodPtr)(
                   this->distTexture,
                   this->distTexture->klass->vtable._6_get_height.method))
              * v71;
          this->normalNoise_uv2.x = v92;
          this->normalNoise_uv2.y = v93;
          this->normalNoise_size2.x = 1.3;
          this->normalNoise_size2.y = 1.3;
          this->normalNoise_ret.x = perlinNoise(this, p_normalNoise_uv2, uvb);
          this->normalNoise_size2.x = 1.3;
          this->normalNoise_size2.y = 1.3;
          this->normalNoise_uv2.x = v92 + 2.0;
          this->normalNoise_uv2.y = v93 + 2.0;
          v96 = perlinNoise(this, p_normalNoise_uv2, uvb);
          v97 = this->distTexture;
          v98 = this->normalNoise_ret.x;
          this->normalNoise_ret.y = v96;
          this->normalNoise_ret.z = 1.0;
          v99 = (v78 * (1.0 - v91)) + (v91 * v98);
          v100 = (v77 * (1.0 - v91)) + (v91 * v96);
          v101 = (v97->klass->vtable._4_get_width.methodPtr)(v97, v97->klass->vtable._4_get_width.method);
          v135 = 0;
          v136 = 0;
          sub_19EC630(&v135, v99, v100, 0.0, 0.0);
          v6 = v128;
          v102 = v73 + v71 * v101;
          v103 = HIDWORD(v135);
          v105 = v136;
          v104 = HIDWORD(v136);
          v107 = &v128[2 * v102];
          v107[8] = v135;
          v107[9] = v103;
          v107[10] = v105;
          v107[11] = v104;
          ++v73;
          --v72;
          p_distTexture = &this->distTexture;
        }
        while (v73 < (this->distTexture->klass->vtable._4_get_width.methodPtr)(
                        this->distTexture,
                        this->distTexture->klass->vtable._4_get_width.method));
      }
      ++v71;
    }
    while (v71 < ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
                    *p_distTexture,
                    (*p_distTexture)->klass->vtable._6_get_height.method));
  }
  if (((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
         *p_distTexture,
         (*p_distTexture)->klass->vtable._6_get_height.method) >= 1)
  {
    v108 = 0;
    do
    {
      if (((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
             *p_distTexture,
             (*p_distTexture)->klass->vtable._4_get_width.method) >= 1)
      {
        v109 = 0;
        do
        {
          v110 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                   *p_distTexture,
                   (*p_distTexture)->klass->vtable._4_get_width.method);
          v112 = ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
                   *p_distTexture,
                   (*p_distTexture)->klass->vtable._6_get_height.method);
          v113 = PerlinNoise(((1.0 / v110) * v109) * 7.0, ((1.0 / v112) * v108) * 7.0, 0);
          v114 = v109
               + v108
               * ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                   *p_distTexture,
                   (*p_distTexture)->klass->vtable._4_get_width.method);
          *&v6[2 * v114 + 5] = v113;
          ++v109;
        }
        while (v109 < ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                         *p_distTexture,
                         (*p_distTexture)->klass->vtable._4_get_width.method));
      }
      ++v108;
    }
    while (v108 < ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
                     *p_distTexture,
                     (*p_distTexture)->klass->vtable._6_get_height.method));
  }
  if (((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
         *p_distTexture,
         (*p_distTexture)->klass->vtable._6_get_height.method) >= 1)
  {
    v116 = 0;
    do
    {
      if (((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
             *p_distTexture,
             (*p_distTexture)->klass->vtable._4_get_width.method) >= 1)
      {
        v117 = 0;
        do
        {
          v118 = ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                   *p_distTexture,
                   (*p_distTexture)->klass->vtable._4_get_width.method);
          v120 = ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
                   *p_distTexture,
                   (*p_distTexture)->klass->vtable._6_get_height.method);
          v121 = PerlinNoise(((1.0 / v118) * v117) * 10.0, ((1.0 / v120) * v116) * 10.0, 0);
          v122 = v117
               + v116
               * ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                   *p_distTexture,
                   (*p_distTexture)->klass->vtable._4_get_width.method);
          *(&v6[2 * v122 + 5] + 1) = v121;
          ++v117;
        }
        while (v117 < ((*p_distTexture)->klass->vtable._4_get_width.methodPtr)(
                         *p_distTexture,
                         (*p_distTexture)->klass->vtable._4_get_width.method));
      }
      ++v116;
    }
    while (v116 < ((*p_distTexture)->klass->vtable._6_get_height.methodPtr)(
                     *p_distTexture,
                     (*p_distTexture)->klass->vtable._6_get_height.method));
  }
  SetPixels_27471904(*p_distTexture, v6);
  set_anisoLevel(*p_distTexture, 0);
  set_name(*p_distTexture, "distTexture");
  Apply_27472496(*p_distTexture);
}

// 0x188f520
void OnDisable(PostBlur *this) {
  UnityEngine_Object_o *accumTexture;
  struct UnityEngine_RenderTexture_o **p_accumTexture;
  UnityEngine_Object_o *v6;
  UnityEngine_Object_o *material;
  UnityEngine_Object_o *v9;
  UnityEngine_Object_o *Adjust_material;
  UnityEngine_Object_o *v12;
  UnityEngine_Object_o *Encount1st_material;
  UnityEngine_Object_o *v15;

  accumTexture = this->accumTexture;
  p_accumTexture = &this->accumTexture;
  if (op_Inequality(accumTexture, 0, 0))
  {
    v6 = *p_accumTexture;
    DestroyImmediate_27360336(v6);
  }
  material = this->material;
  if (op_Inequality(material, 0, 0))
  {
    v9 = this->material;
    DestroyImmediate_27360336(v9);
  }
  *p_accumTexture = 0;
  this->material = 0;
  Adjust_material = this->Adjust_material;
  if (op_Inequality(Adjust_material, 0, 0))
  {
    v12 = this->Adjust_material;
    DestroyImmediate_27360336(v12);
  }
  this->Adjust_material = 0;
  Encount1st_material = this->Encount1st_material;
  if (op_Inequality(Encount1st_material, 0, 0))
  {
    v15 = this->Encount1st_material;
    DestroyImmediate_27360336(v15);
  }
  this->Encount1st_material = 0;
}

// 0x188f420
void OnEnable(PostBlur *this) {
  UnityEngine_Shader_o *shader;
  u64 *v4;
  UnityEngine_Shader_o *Adjust_shader;
  u64 *v6;
  UnityEngine_Shader_o *Encount1st_shader;
  u64 *v8;

  shader = this->shader;
  v4 = Allocate(UnityEngine_Material);
  _ctor(v4, shader, 0);
  this->material = v4;
  set_hideFlags(v4, 61);
  Adjust_shader = this->Adjust_shader;
  v6 = Allocate(UnityEngine_Material);
  _ctor(v6, Adjust_shader, 0);
  this->Adjust_material = v6;
  set_hideFlags(v6, 61);
  Encount1st_shader = this->Encount1st_shader;
  v8 = Allocate(UnityEngine_Material);
  _ctor(v8, Encount1st_shader, 0);
  this->Encount1st_material = v8;
  set_hideFlags(v8, 61);
  SetTexture_27248080(this->material, this->_DistortionTexID, this->distTexture);
}

// 0x188fd20
void OnRenderImage(PostBlur *this, void *source, void *destination) {
  UnityEngine_Object_o *accumTexture;
  UnityEngine_Object_o *v9;
  UnityEngine_Object_o *v11;
  s32 screen_wid;
  s32 screen_hei;
  u64 *v16;
  s32 v17;
  s32 v18;
  s32 v19;
  struct UnityEngine_RenderTexture_o *v20;
  UnityEngine_RenderTexture_o *v22;
  UnityEngine_RenderTexture_o *v23;
  s32 Postblur_DrawStop;
  u32 a[2];
  s64 g;

  *a = 0;
  g = 0;
  accumTexture = this->accumTexture;
  if (op_Equality(accumTexture, 0, 0))
  {
    v9 = this->accumTexture;
    if (op_Equality(v9, 0, 0))
    {
      v11 = this->accumTexture;
      DestroyImmediate_27360336(v11);
    }
    this->accumTexture = 0;
    v16 = Allocate(UnityEngine_RenderTexture);
    if (screen_wid >= 0)
      v17 = screen_wid;
    else
      v17 = screen_wid + 1;
    v18 = v17 >> 1;
    if (screen_hei >= 0)
      v19 = screen_hei;
    else
      v19 = screen_hei + 1;
    v20 = v16;
    _ctor_27407312(v16, v18, v19 >> 1, 0);
    this->accumTexture = v20;
    set_hideFlags(v20, 61);
    set_filterMode(this->accumTexture, 1);
    set_wrapMode(this->accumTexture, 1);
    set_autoGenerateMips(this->accumTexture, 0);
    set_anisoLevel(this->accumTexture, 0);
    set_name(this->accumTexture, "accumTexture");
    v22 = this->accumTexture;
    Blit(source, v22, 0);
  }
  if (this->refresh_Blit)
  {
    v23 = this->accumTexture;
    Blit(source, v23, 0);
    this->refresh_Blit = 0;
  }
  if (Postblur_DrawStop < 1)
    goto LABEL_41;
LABEL_36:
  Postblur_DrawStop = Postblur_DrawStop - 1;
  this->encount1st_Blit = 0;
}

// 0x188f6e0
void Update(PostBlur *this) {
  u32 Postblur_blur_blend;
  u32 Postblur_multiblur_blend;
  s64 Postblur_distortionblur_blend;
  u32 Postblur_filter_blend;
  u32 Postblur_multifilter_blend;
  f32 Postblur_distortionblur_distor1;
  f32 Postblur_distortionblur_distor2;
  f32 distortionblur_a;
  f32 v12;
  UnityEngine_Material_o *material;
  f32 *static_fields;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 Adj_ColorR;
  f32 Adj_ColorG;
  f32 Adj_ColorB;
  UnityEngine_Material_o *Adjust_material;
  UnityEngine_Object_o *kernelObject;
  UnityEngine_Object_o *PostBlurMaterial;
  UnityEngine_Color_o v31;
  UnityEngine_Color_o v32;

  if (this->GameParamActive)
  {
    if (Postblur_refresh)
      this->refresh_Blit = 1;
    if (Postblur_Encount1st)
    {
      this->encount1st_Blit = 1;
      Postblur_Encount1st = 0;
      this->encount1st_Blit_Frm = dds3GetKernelCount();
    }
    this->blur_rotation = Postblur_blur_rotation;
    this->blur_scale = Postblur_blur_scale;
    if (Postblur_blur_blend <= 4)
      this->blur_blend = Postblur_blur_blend;
    this->blur_r = Postblur_blur_r;
    this->blur_g = Postblur_blur_g;
    this->blur_b = Postblur_blur_b;
    this->blur_a = Postblur_blur_a;
    this->blur_center_x = Postblur_blur_center_x;
    this->blur_center_y = Postblur_blur_center_y;
    this->multiblur_rotation = Postblur_multiblur_rotation;
    this->multiblur_scale = Postblur_multiblur_scale;
    if (Postblur_multiblur_blend <= 4)
      this->multiblur_blend = Postblur_multiblur_blend;
    this->multiblur_r = Postblur_multiblur_r;
    this->multiblur_g = Postblur_multiblur_g;
    this->multiblur_b = Postblur_multiblur_b;
    this->multiblur_a = Postblur_multiblur_a;
    this->multiblur_area = Postblur_multiblur_area;
    this->multiblur_center_x = Postblur_multiblur_center_x;
    this->multiblur_center_y = Postblur_multiblur_center_y;
    if (Postblur_distortionblur_blend <= 6 && ((0x5Fu >> Postblur_distortionblur_blend) & 1) != 0)
      this->distortionblur_blend = dword_33CDBAC[Postblur_distortionblur_blend];
    this->distortionblur_r = Postblur_distortionblur_r;
    this->distortionblur_g = Postblur_distortionblur_g;
    this->distortionblur_b = Postblur_distortionblur_b;
    this->distortionblur_a = Postblur_distortionblur_a;
    this->distortionblur_area_x = Postblur_distortionblur_area_x;
    this->distortionblur_area_y = Postblur_distortionblur_area_y;
    this->distortionblur_center_x = Postblur_distortionblur_center_x;
    this->distortionblur_center_y = Postblur_distortionblur_center_y;
    this->distortionblur_moyaalp = Postblur_distortionblur_moyaalp;
    this->distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd;
    this->distortionblur_moya_r = Postblur_distortionblur_moya_r;
    this->distortionblur_moya_g = Postblur_distortionblur_moya_g;
    this->distortionblur_moya_b = Postblur_distortionblur_moya_b;
    this->distortionblur_moya_sizemul = Postblur_distortionblur_moya_sizemul;
    if (Postblur_filter_blend <= 4)
      this->filter_blend = Postblur_filter_blend;
    this->filter_r = Postblur_filter_r;
    this->filter_g = Postblur_filter_g;
    this->filter_b = Postblur_filter_b;
    this->filter_a = Postblur_filter_a;
    if (Postblur_multifilter_blend <= 5)
      this->multifilter_blend = Postblur_multifilter_blend;
    this->multifilter_r = Postblur_multifilter_r;
    this->multifilter_g = Postblur_multifilter_g;
    this->multifilter_b = Postblur_multifilter_b;
    this->multifilter_a = Postblur_multifilter_a;
    this->multifilter_area = Postblur_multifilter_area;
    this->multifilter_center_x = Postblur_multifilter_center_x;
    this->multifilter_center_y = Postblur_multifilter_center_y;
  }
  this->distortionblur_distor1 = Postblur_distortionblur_distor1;
  distortionblur_a = this->distortionblur_a;
  this->distortionblur_distor2 = Postblur_distortionblur_distor2;
  if (distortionblur_a < 0.2)
  {
    v12 = distortionblur_a * 5.0;
    this->distortionblur_distor1 = Postblur_distortionblur_distor1 * v12;
    this->distortionblur_distor2 = Postblur_distortionblur_distor2 * v12;
  }
  this->encountblur_blend = Postblur_encountblur_blend != 0;
  material = this->material;
  v15 = static_fields[192];
  v16 = static_fields[193];
  v17 = static_fields[194];
  *&v32.r = 0;
  *&v32.b = 0;
  sub_19EC630(&v32.r, v15, v16, v17, 1.0);
  SetColor(material, "_Adj_ColorRGBA", v32, 0);
  Adjust_material = this->Adjust_material;
  *&v31.r = 0;
  *&v31.b = 0;
  sub_19EC630(&v31.r, Adj_ColorR, Adj_ColorG, Adj_ColorB, 1.0);
  SetColor(Adjust_material, "_Adj_ColorRGBA", v31, 0);
  if (op_Inequality(kernelObject, 0, 0))
  {
    PostBlurMaterial = kernelObject->PostBlurMaterial;
    if (op_Equality(PostBlurMaterial, 0, 0))
    {
      kernelObject->PostBlurMaterial = this->material;
      kernelObject->PostBlurDisTexture = this->distTexture;
    }
  }
}

// 0x188e4e0
sdfVector3_t normalNoise(PostBlur *this, sdfVector2_t *uv, sdfVector2_t *size) {
  f32 y;
  f32 v5;
  UnityEngine_Vector2_o *p_normalNoise_uv2;
  UnityEngine_Vector2_o *p_normalNoise_size2;
  f32 v11;
  f32 v12;
  UnityEngine_Vector3_o result;

  y = uv->y;
  this->normalNoise_uv2.x = uv->x;
  this->normalNoise_uv2.y = y;
  v5 = size->y;
  p_normalNoise_uv2 = &this->normalNoise_uv2;
  p_normalNoise_size2 = &this->normalNoise_size2;
  this->normalNoise_size2.x = size->x;
  this->normalNoise_size2.y = v5;
  this->normalNoise_ret.x = perlinNoise(this, &this->normalNoise_uv2, &this->normalNoise_size2);
  v11 = uv->y;
  this->normalNoise_uv2.x = uv->x + 2.0;
  this->normalNoise_uv2.y = v11 + 2.0;
  v12 = size->y;
  this->normalNoise_size2.x = size->x;
  this->normalNoise_size2.y = v12;
  result.y = perlinNoise(this, p_normalNoise_uv2, p_normalNoise_size2);
  this->normalNoise_ret.y = result.y;
  this->normalNoise_ret.z = 1.0;
  result.x = this->normalNoise_ret.x;
  result.z = 1.0;
  return result;
}

// 0x188e2f0
f32 perlinNoise(PostBlur *this, sdfVector2_t *uv, sdfVector2_t *size) {
  f32 y;
  f32 x;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  UnityEngine_Vector2_o v24;
  UnityEngine_Vector2_o v25;
  UnityEngine_Vector2_o v26;
  UnityEngine_Vector2_o v27;
  UnityEngine_Vector2_o v28;

  x = uv->x;
  y = uv->y;
  v28.x = x;
  v28.y = y;
  v24 = op_Multiply_8725248(v28, 2.0);
  this->perlinNoise_uv2 = v24;
  v10 = size->x;
  v11 = size->y;
  this->perlinNoise_size2.x = size->x;
  this->perlinNoise_size2.y = v11;
  v12 = v10;
  v13 = v11;
  v14 = PerlinNoise(v24.x * v12, v24.y * v13);
  v25 = op_Multiply_8725248(*uv, 4.0);
  this->perlinNoise_uv2 = v25;
  v15 = size->y;
  v16 = v25.x * size->x;
  this->perlinNoise_size2.x = size->x;
  this->perlinNoise_size2.y = v15;
  v17 = PerlinNoise(v16, v25.y * v15);
  v26 = op_Multiply_8725248(*uv, 8.0);
  this->perlinNoise_uv2 = v26;
  v18 = size->y;
  v19 = v26.x * size->x;
  this->perlinNoise_size2.x = size->x;
  this->perlinNoise_size2.y = v18;
  v20 = PerlinNoise(v19, v26.y * v18);
  v27 = op_Multiply_8725248(*uv, 16.0);
  this->perlinNoise_uv2 = v27;
  v21 = size->y;
  v22 = v27.x * size->x;
  this->perlinNoise_size2.x = size->x;
  this->perlinNoise_size2.y = v21;
  return ((((v14 * 0.5) + 0.0) + (v17 * 0.25)) + (v20 * 0.125))
       + (PerlinNoise(v22, v27.y * v21) * 0.0625);
}
