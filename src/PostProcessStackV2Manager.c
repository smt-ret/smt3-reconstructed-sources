#include "types.h"

typedef struct PostProcessStackV2Manager PostProcessStackV2Manager;
typedef struct dds3DefaultMain dds3DefaultMain;

f32 GetBloomDown(s32 deveilID);
void *GetCampCameraObj(dds3DefaultMain *this);

// 0x1890aa0
void Start(PostProcessStackV2Manager *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_Rendering_PostProcessing_PostProcessProfile_o *profile;
  UnityEngine_Rendering_PostProcessing_PostProcessProfile_o *v5;
  UnityEngine_GameObject_o *CampCameraObj;
  Il2CppObject *Component_object;
  UnityEngine_Rendering_PostProcessing_PostProcessLayer_o *v11;
  System_String_array *v12;
  s32 Mask;

  Component_GUILayer = GetComponent_GUILayer_(this);
  this->volume = Component_GUILayer;
  profile = get_profile(Component_GUILayer);
  this->bloom = GetSetting_object_(profile);
  v5 = get_profile(this->volume);
  this->dof = GetSetting_object_(v5);
  CampCameraObj = GetCampCameraObj(kernelObject);
  if (op_Inequality(CampCameraObj, 0, 0))
  {
    Component_object = GetComponent_object_(CampCameraObj);
    set_allowHDR(Component_object, 0);
    v11 = AddComponent_object_(CampCameraObj);
    Init(v11, this->m_resources, 0);
    v11->volumeTrigger = get_transform(CampCameraObj, 0);
    v12 = NewSpecific(string, 1u);
    v12->m_Items[0] = "PostProcessing";
    Mask = GetMask(v12);
    v11->volumeLayer = op_Implicit_27237744(Mask);
  }
  *&this->bloom_softKnee_mul = 0x3F828F5C3F666666LL;
}

// 0x1890cd0
void Update(PostProcessStackV2Manager *this) {
  dds3KernelDraw_c *v3;
  s32 v4;
  s32 PPSV2_StatusDevilId;
  f32 BloomDown;
  f32 v8;
  s32 PPSV2_bloom_type;
  s32 v11;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *threshold;
  _BOOL4 PPSV2_dof_use;
  struct UnityEngine_Rendering_PostProcessing_DepthOfField_o *dof;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *focusDistance;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v17;
  s32 v18;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v19;
  s32 v20;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v21;
  s32 v22;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v23;
  s32 v24;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v25;
  s32 v26;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v27;
  s32 v28;
  struct UnityEngine_Rendering_PostProcessing_Bloom_o *bloom;
  f32 bloom_softKnee_mul;
  f32 v31;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v32;
  s32 v33;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v34;
  s32 v35;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v36;
  s32 v37;
  f32 PPSV2_bloom_btl_max;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v39;
  s32 v40;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v41;
  s32 v42;
  f32 v43;
  f32 PPSV2_bloom_btl_Default;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *intensity;
  s32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v50;
  s32 v51;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v52;
  s32 v53;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v54;
  s32 v55;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v56;
  s32 v57;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v58;
  s32 v59;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *v60;
  s32 v61;
  struct UnityEngine_Rendering_PostProcessing_FloatParameter_o *softKnee;

  {
    else
    {
      if (!PPSV2_StatusMode)
        goto LABEL_21;
    }
LABEL_5:
    PPSV2_StatusMode = 0;
    PPSV2_update = 1;
    this->bloom->active = 1;
    if (PPSV2_StatusDevilId)
    {
      BloomDown = GetBloomDown(PPSV2_StatusDevilId);
      v8 = 1.0;
      if (BloomDown <= 1.0)
      {
        v8 = 0.5;
      }
      else if (BloomDown > 2.1)
      {
        if (BloomDown <= 3.1)
          v8 = 1.3;
        else
          v8 = 1.8;
      }
      this->bloom->intensity->value = v8;
      this->bloom->threshold->value = 0.93;
      this->bloom->softKnee->value = this->bloom_softKnee_mul * 0.1;
        goto LABEL_51;
      goto LABEL_41;
    }
    this->bloom->intensity->value = 2.0;
    this->bloom->threshold->value = 0.93;
    this->bloom->softKnee->value = this->bloom_softKnee_mul * 0.2;
    goto LABEL_40;
  }
  v4 = 0;
  if (PPSV2_StatusMode)
    goto LABEL_5;
LABEL_21:
  else if (PPSV2_update)
  {
LABEL_24:
    if (PPSV2_bloom_type)
      this->bloom->active = 1;
    else
    {
      if (PPSV2_bloom_type > 661)
      {
LABEL_32:
        if (PPSV2_bloom_type > 750)
        {
          if (PPSV2_bloom_type > 6341)
          {
            if (PPSV2_bloom_type > 6731)
            {
              if (PPSV2_bloom_type != 6741)
              {
                if (PPSV2_bloom_type == 7052)
                {
                  this->bloom->intensity->value = 1.0;
                  threshold = this->bloom->threshold;
                  v11 = 1065185444;
LABEL_153:
                  LODWORD(threshold->value) = v11;
                  this->bloom->softKnee->value = this->bloom_softKnee_mul;
                  if ((v3->_2.bitflags2 & 2) == 0)
                  {
LABEL_240:
                    PPSV2_update = 0;
                    if ((v3->_2.bitflags2 & 2) == 0)
                      goto LABEL_51;
                    goto LABEL_41;
                  }
LABEL_239:
                  goto LABEL_240;
                }
                if (PPSV2_bloom_type == 7053)
                {
                  v11 = 1036831949;
                  this->bloom->intensity->value = 0.1;
                  threshold = this->bloom->threshold;
                  goto LABEL_153;
                }
LABEL_238:
                if ((v3->_2.bitflags2 & 2) == 0)
                  goto LABEL_240;
                goto LABEL_239;
              }
              intensity = this->bloom->intensity;
              v46 = 1077936128;
LABEL_151:
              LODWORD(intensity->value) = v46;
              v27 = this->bloom->threshold;
              v28 = 1064682127;
              goto LABEL_180;
            }
            if (PPSV2_bloom_type != 6342)
            {
              if (PPSV2_bloom_type != 6731)
                goto LABEL_238;
              v17 = this->bloom->intensity;
              v18 = 1084227584;
              goto LABEL_108;
            }
            this->bloom->intensity->value = 1.0;
            goto LABEL_140;
          }
          if (PPSV2_bloom_type > 913)
          {
            if (PPSV2_bloom_type == 2322)
            {
              PPSV2_bloom_btl_max = 3.0;
              if (PPSV2_bloom_btl_max < 3.0)
              {
                else
                {
                }
              }
              this->bloom->intensity->value = PPSV2_bloom_btl_max;
LABEL_140:
              v19 = this->bloom->threshold;
              v20 = 1064849900;
LABEL_206:
              LODWORD(v19->value) = v20;
              bloom = this->bloom;
              bloom_softKnee_mul = this->bloom_softKnee_mul;
              v31 = 0.3;
              goto LABEL_236;
            }
            if (PPSV2_bloom_type != 6341)
              goto LABEL_238;
            this->bloom->intensity->value = 6.0;
            v21 = this->bloom->threshold;
            v22 = 1064178811;
LABEL_126:
            LODWORD(v21->value) = v22;
            bloom = this->bloom;
            bloom_softKnee_mul = this->bloom_softKnee_mul;
            v31 = 0.7;
            goto LABEL_236;
          }
          switch (PPSV2_bloom_type)
          {
            case 800:
              v32 = this->bloom->intensity;
              v33 = 1077936128;
              goto LABEL_125;
            case 801:
              v50 = this->bloom->intensity;
              v51 = 1082130432;
              goto LABEL_198;
            case 802:
              v50 = this->bloom->intensity;
              v51 = 0x40000000;
LABEL_198:
              LODWORD(v50->value) = v51;
              this->bloom->threshold->value = 0.98;
              bloom = this->bloom;
              bloom_softKnee_mul = this->bloom_softKnee_mul;
              v31 = 0.8;
              goto LABEL_236;
            case 803:
              this->bloom->intensity->value = 2.0;
              v52 = this->bloom->threshold;
              v53 = 1064849900;
              goto LABEL_201;
            default:
              if (PPSV2_bloom_type != 913)
                goto LABEL_238;
              this->bloom->intensity->value = 1.5;
              break;
          }
          goto LABEL_179;
        }
        if (PPSV2_bloom_type <= 694)
        {
          if (PPSV2_bloom_type <= 673)
          {
            if (PPSV2_bloom_type == 662)
            {
              this->bloom->intensity->value = 10.0;
              v21 = this->bloom->threshold;
              v22 = 1063675494;
            }
            else
            {
              if ((PPSV2_bloom_type & 0xFFFFFFFE) != 0x2A0)
                goto LABEL_238;
              this->bloom->intensity->value = 2.0;
              v21 = this->bloom->threshold;
              v22 = 1064849900;
            }
            goto LABEL_126;
          }
          if (PPSV2_bloom_type != 674)
          {
            if (PPSV2_bloom_type != 694)
              goto LABEL_238;
LABEL_124:
            v32 = this->bloom->intensity;
            v33 = 1084227584;
LABEL_125:
            LODWORD(v32->value) = v33;
            v21 = this->bloom->threshold;
            v22 = 1064514355;
            goto LABEL_126;
          }
LABEL_129:
          v36 = this->bloom->intensity;
          v37 = 1077936128;
        }
        else
        {
          if (PPSV2_bloom_type <= 719)
          {
            if (PPSV2_bloom_type == 705)
            {
              v39 = this->bloom->intensity;
              v40 = 1065353216;
LABEL_205:
              LODWORD(v39->value) = v40;
              v19 = this->bloom->threshold;
              v20 = 1065185444;
              goto LABEL_206;
            }
            if (PPSV2_bloom_type != 719)
              goto LABEL_238;
            this->bloom->intensity->value = 4.0;
            v27 = this->bloom->threshold;
            v28 = 1064849900;
            goto LABEL_180;
          }
          if (PPSV2_bloom_type != 726)
          {
            if (PPSV2_bloom_type != 749)
            {
              if (PPSV2_bloom_type != 750)
                goto LABEL_238;
LABEL_68:
              v17 = this->bloom->intensity;
              v18 = 1077936128;
              goto LABEL_108;
            }
            this->bloom->intensity->value = 3.0;
            v27 = this->bloom->threshold;
            v28 = 1064011039;
LABEL_180:
            LODWORD(v27->value) = v28;
            bloom = this->bloom;
            bloom_softKnee_mul = this->bloom_softKnee_mul;
            v31 = 0.6;
            goto LABEL_236;
          }
          v36 = this->bloom->intensity;
          v37 = 1082130432;
        }
        LODWORD(v36->value) = v37;
        v41 = this->bloom->threshold;
        v42 = 1064682127;
LABEL_235:
        LODWORD(v41->value) = v42;
        bloom = this->bloom;
        bloom_softKnee_mul = this->bloom_softKnee_mul;
        v31 = 0.4;
LABEL_236:
        softKnee = bloom->softKnee;
LABEL_237:
        softKnee->value = bloom_softKnee_mul * v31;
        goto LABEL_238;
      }
    }
    if (PPSV2_bloom_type <= 232)
    {
      if (PPSV2_bloom_type <= 70)
      {
        if (PPSV2_bloom_type > 0x46)
          goto LABEL_238;
        switch (PPSV2_bloom_type)
        {
          case 0:
            this->bloom->active = 0;
            if ((v3->_2.bitflags2 & 2) == 0)
              goto LABEL_240;
            goto LABEL_239;
          case 1:
            v34 = this->bloom->intensity;
            v35 = 1082130432;
            goto LABEL_219;
          case 2:
            v56 = this->bloom->intensity;
            v57 = 1086324736;
            goto LABEL_222;
          case 3:
            v58 = this->bloom->intensity;
            v59 = 1091043328;
            goto LABEL_226;
          case 4:
            intensity = this->bloom->intensity;
            v46 = 1084227584;
            goto LABEL_151;
          case 5:
            this->bloom->intensity->value = 4.0;
            v41 = this->bloom->threshold;
            v42 = 1064346583;
            goto LABEL_235;
          case 6:
            v34 = this->bloom->intensity;
            v35 = 0x40000000;
            goto LABEL_219;
          case 7:
            this->bloom->intensity->value = 8.0;
            v60 = this->bloom->threshold;
            v61 = 1063843267;
            goto LABEL_229;
          case 8:
          case 16:
            v34 = this->bloom->intensity;
            v35 = 1084227584;
            goto LABEL_219;
          case 9:
            v34 = this->bloom->intensity;
            v35 = 1065353216;
LABEL_219:
            LODWORD(v34->value) = v35;
            v60 = this->bloom->threshold;
            v61 = 1064849900;
            goto LABEL_229;
          case 10:
            goto LABEL_68;
          case 11:
          case 41:
            goto LABEL_129;
          case 12:
          case 17:
          case 18:
          case 19:
          case 20:
          case 21:
          case 22:
          case 23:
          case 24:
          case 25:
          case 26:
          case 27:
          case 28:
          case 29:
          case 30:
          case 31:
          case 32:
          case 33:
          case 34:
          case 35:
          case 36:
          case 37:
          case 38:
          case 39:
          case 40:
            goto LABEL_238;
          case 13:
            v54 = this->bloom->intensity;
            v55 = 1082130432;
            goto LABEL_224;
          case 14:
            goto LABEL_83;
          case 15:
            v56 = this->bloom->intensity;
            v57 = 1069547520;
LABEL_222:
            LODWORD(v56->value) = v57;
            v60 = this->bloom->threshold;
            v61 = 1064514355;
            goto LABEL_229;
          case 42:
          case 44:
            v54 = this->bloom->intensity;
            v55 = 1065353216;
            goto LABEL_224;
          case 43:
            v54 = this->bloom->intensity;
            v55 = 0x40000000;
LABEL_224:
            LODWORD(v54->value) = v55;
            v41 = this->bloom->threshold;
            v42 = 1064849900;
            goto LABEL_235;
          case 45:
            v58 = this->bloom->intensity;
            v59 = 1077936128;
LABEL_226:
            LODWORD(v58->value) = v59;
            v19 = this->bloom->threshold;
            v20 = 1064682127;
            goto LABEL_206;
          case 46:
            this->bloom->intensity->value = 6.0;
            v27 = this->bloom->threshold;
            v28 = 1063843267;
            goto LABEL_180;
          case 47:
            this->bloom->intensity->value = 2.0;
            v60 = this->bloom->threshold;
            v61 = 1064346583;
LABEL_229:
            LODWORD(v60->value) = v61;
            bloom_softKnee_mul = this->bloom_softKnee_mul;
            softKnee = this->bloom->softKnee;
            v31 = 0.5;
            goto LABEL_237;
          default:
            if (PPSV2_bloom_type == 60)
            {
LABEL_127:
              v23 = this->bloom->intensity;
              v24 = 1065353216;
              goto LABEL_128;
            }
            if (PPSV2_bloom_type != 70)
              goto LABEL_238;
            v25 = this->bloom->intensity;
            v26 = 1065353216;
LABEL_111:
            LODWORD(v25->value) = v26;
            this->bloom->threshold->value = 0.98;
            bloom = this->bloom;
            bloom_softKnee_mul = this->bloom_softKnee_mul;
            v31 = 0.2;
            break;
        }
        goto LABEL_236;
      }
      if (PPSV2_bloom_type <= 102)
      {
        switch (PPSV2_bloom_type)
        {
          case 'G':
            v25 = this->bloom->intensity;
            v26 = 1056964608;
            goto LABEL_111;
          case 'd':
            v43 = PPSV2_bloom_btl_max;
            if (PPSV2_bloom_btl_Default > v43)
              goto LABEL_175;
            goto LABEL_178;
          case 'e':
            v48 = PPSV2_bloom_btl_max;
            v49 = 2.0;
            if (v48 >= 2.0)
              goto LABEL_194;
            if ((v3->_2.bitflags2 & 2) == 0)
              goto LABEL_193;
            goto LABEL_192;
          case 'f':
            v48 = PPSV2_bloom_btl_max;
            v49 = 2.0;
            if (v48 >= 2.0)
              goto LABEL_194;
            if ((v3->_2.bitflags2 & 2) == 0)
              goto LABEL_193;
LABEL_192:
            else
            {
              v49 = PPSV2_bloom_btl_max;
            }
LABEL_194:
            this->bloom->intensity->value = v49;
            break;
          default:
            goto LABEL_238;
        }
        goto LABEL_195;
      }
      if (PPSV2_bloom_type != 119)
      {
        if (PPSV2_bloom_type != 190)
        {
          if (PPSV2_bloom_type != 232)
            goto LABEL_238;
LABEL_83:
          this->bloom->intensity->value = 1.0;
          v19 = this->bloom->threshold;
          v20 = 1065017672;
          goto LABEL_206;
        }
        v47 = 1.7;
        if (PPSV2_bloom_btl_max < 1.7)
        {
          else
          {
            v47 = PPSV2_bloom_btl_max;
          }
        }
        this->bloom->intensity->value = v47;
LABEL_234:
        v41 = this->bloom->threshold;
        v42 = 1065017672;
        goto LABEL_235;
      }
      v43 = PPSV2_bloom_btl_max;
      PPSV2_bloom_btl_Default = 2.0;
      if (v43 < 2.0)
        goto LABEL_175;
    }
    else
    {
      if (PPSV2_bloom_type > 629)
      {
        if (PPSV2_bloom_type <= 635)
        {
          if (PPSV2_bloom_type == 634)
          {
            this->bloom->intensity->value = 4.0;
            v41 = this->bloom->threshold;
            v42 = 1064178811;
            goto LABEL_235;
          }
          if (PPSV2_bloom_type != 635)
            goto LABEL_238;
        }
        else
        {
          if (PPSV2_bloom_type == 640)
          {
LABEL_130:
            this->bloom->intensity->value = 2.0;
            v27 = this->bloom->threshold;
            v28 = 1064178811;
            goto LABEL_180;
          }
          if (PPSV2_bloom_type == 652)
          {
            this->bloom->intensity->value = 3.0;
            v27 = this->bloom->threshold;
            v28 = 1064346583;
            goto LABEL_180;
          }
          if (PPSV2_bloom_type != 661)
            goto LABEL_238;
        }
        v17 = this->bloom->intensity;
        v18 = 1082130432;
LABEL_108:
        LODWORD(v17->value) = v18;
LABEL_195:
        v41 = this->bloom->threshold;
        v42 = 1064514355;
        goto LABEL_235;
      }
      if (PPSV2_bloom_type > 600)
      {
        switch (PPSV2_bloom_type)
        {
          case 602:
            v23 = this->bloom->intensity;
            v24 = 1069547520;
            goto LABEL_128;
          case 615:
            goto LABEL_124;
          case 616:
            goto LABEL_118;
          case 617:
            this->bloom->intensity->value = 4.0;
            v52 = this->bloom->threshold;
            v53 = 1062836634;
LABEL_201:
            LODWORD(v52->value) = v53;
            bloom = this->bloom;
            bloom_softKnee_mul = this->bloom_softKnee_mul;
            v31 = 0.9;
            goto LABEL_236;
          case 618:
            v54 = this->bloom->intensity;
            v55 = 1077936128;
            goto LABEL_224;
          case 619:
            this->bloom->intensity->value = 5.0;
            v21 = this->bloom->threshold;
            v22 = 1063843267;
            goto LABEL_126;
          case 621:
            goto LABEL_127;
          case 623:
            goto LABEL_130;
          case 629:
            v39 = this->bloom->intensity;
            v40 = 1056964608;
            goto LABEL_205;
          default:
            goto LABEL_238;
        }
        goto LABEL_238;
      }
      if (PPSV2_bloom_type != 260)
      {
        if (PPSV2_bloom_type != 600)
          goto LABEL_238;
LABEL_118:
        v23 = this->bloom->intensity;
        v24 = 0x40000000;
LABEL_128:
        LODWORD(v23->value) = v24;
        goto LABEL_234;
      }
      v43 = PPSV2_bloom_btl_max;
      PPSV2_bloom_btl_Default = 1.0;
      if (v43 < 1.0)
      {
LABEL_175:
        else
        {
          PPSV2_bloom_btl_Default = v43;
        }
      }
    }
LABEL_178:
    this->bloom->intensity->value = PPSV2_bloom_btl_Default;
LABEL_179:
    v27 = this->bloom->threshold;
    v28 = 1064514355;
    goto LABEL_180;
  }
LABEL_40:
  if ((v3->_2.bitflags2 & 2) == 0)
    goto LABEL_51;
LABEL_41:
LABEL_51:
  if (!PPSV2_dof_update)
    return;
LABEL_43:
  else
  {
    dof = this->dof;
    if (PPSV2_dof_use)
      goto LABEL_46;
  }
  dof->active = 0;
  focusDistance = this->dof->focusDistance;
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_47:
  }
LABEL_57:
  focusDistance->value = PPSV2_dof1;
  this->dof->aperture->value = PPSV2_dof2;
  this->dof->focalLength->value = PPSV2_dof3 * this->dof_focal_mul;
  PPSV2_dof_update = 0;
}
