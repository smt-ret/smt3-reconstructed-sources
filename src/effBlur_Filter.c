#include "types.h"

typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistBlurPart_tag dds3Effect_DistBlurPart_tag;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_PartialMultiFilter_t dds3Effect_PartialMultiFilter_t;
typedef struct dds3Effect_RipBlurPart_tag dds3Effect_RipBlurPart_tag;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct effDistortionBlurHandle_t effDistortionBlurHandle_t;
typedef struct effPkt2DTriStripParm_t effPkt2DTriStripParm_t;
typedef struct effRippleBlurHandle_t effRippleBlurHandle_t;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 DDS3_SCREEN_OFFX;
static s32 DDS3_SCREEN_OFFY;
static f32 DDS3EFFECT_MULTIFILTER_GETEX_SCALE;
static bool EventMode;
static s32 EventNo;
static f32 FldEve_Pow;
static s32 FldEve_UnityEx_ID;
static f32 FldEve_UnityEx_CntF;
static f32 E601_alp_CntF;
static f32 E601_area_CntF;
static s32 E628_pm_CntI;
static f32 E655_After_CntF;
static f32 E655_After_CntF2;
static f32 E674_aradia_CntF;
static f32 E674_aradia_CntF2;
static s32 E674_aradia_fdof_CntI;
static f32 E748_alp;
static f32 Majin_CntF;
static void *DistortionBlur_Sprite;
static bool evePicFlag;
static bool UpdateFlg_AllOff;
static bool UpdateFlg_blur;
static bool UpdateFlg_distortionblur;
static bool UpdateFlg_multiblur;
static bool UpdateFlg_filter;
static bool UpdateFlg_multifilter;
static void *dbg_fps;

bool ChkNbEventRun(void);
void Clear(mdlManager_mdlTbMbAbLoadCb_t *this);
void ClrDrawFlag(u32 flag);
u32 DDS3EFFECT_RAND_I(void);
f32 DDS3EFFECT_RAND_PM(void);
void DrawStopExec(void);
u32 GetDrawFlag(void);
char *GetEventCamName(void);
void *GetMainCamera(dds3DefaultMain *this);
char *GetNowCameraName(void);
char *GetNowName_SCR_RUN(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void ScreenStop1(void);
void SetDrawFlag(u32 flag, u32 cnt);
sdfTexHandle_t *dds3BillboardGetGeneralTex(s32 number);
void dds3EffectRipBlurPartInit(dds3Effect_RippleBlurParam_t *pParam, dds3Effect_RipBlurPart_tag **pPart);
f32 dds3FadeGetAlphaF(void);
f32 dds3FadeGetColAverageF(void);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
bool effBTLSkillCheckRun2(u32 skillid);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
bool evtBitCheck(s32 no);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x137d1b0
void FldEve_Blur_Pow(f32 pow) {
  FldEve_Pow = pow;
}

// 0x137a030
f32 HD_X(f32 valx) {
  return valx;
}

// 0x137a040
f32 HD_Y(f32 valy) {
  return valy;
}

// 0x13867f0
void Set_EventID(s32 eno) {
  EventNo = eno;
}

// 0x1386780
void Set_EventMode(bool onoff) {
  EventMode = onoff;
}

// 0x1383d60
void Set_PicFlag(bool flag) {
  evePicFlag = flag;
}

// 0x137a020
s32 blur_SCREEN_HEIGHT(void) {
  return 1080;
}

// 0x137a010
s32 blur_SCREEN_WIDTH(void) {
  return 1920;
}

// 0x137a3c0
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID) {
  u64 v4;
  f32 *static_fields;
  f32 v10;
  f32 v11;
  f32 v13;
  _BOOL4 EventMode;
  s32 v15;
  s32 blend;
  dds3KernelDraw_c *v17;
  f32 rotate;
  s16 v20;
  s32 v21;
  f32 v23;
  f64 v24;
  f64 v25;
  f64 v26;
  s32 v27;
  f32 Postblur_blur_g;
  f32 v30;
  f32 Postblur_blur_r;
  f32 Postblur_blur_b;
  s32 EventNo;
  s32 v36;
  f32 Postblur_blur_a;
  f32 v42;
  s32 width;
  struct System_Int32_array *pm;
  s32 v46;
  s32 v48;
  s32 v50;
  s32 height;
  struct System_Int32_array *v53;
  s32 v54;
  s32 v56;
  s32 v58;
  f32 v60;
  struct System_Int32_array *v61;
  s32 v63;
  s32 v65;
  struct System_Int32_array *v67;
  s32 v69;
  f32 Postblur_blur_center_x;
  f32 v72;
  f32 Postblur_blur_center_y;
  struct dds3KernelDraw_StaticFields **p_static_fields;
  effBlur_Filter_c *v79;
  s32 v80;
  System_String_o *EventCamName;
  bool v86;
  System_String_o *v89;
  System_String_o *v97;
  System_String_o *v98;
  bool v100;
  System_String_o *v103;
  struct dds3KernelDraw_StaticFields **v106;
  System_String_o *v108;
  struct dds3KernelDraw_StaticFields *v110;
  f32 v111;
  System_String_o *v113;
  System_String_o *v116;
  System_String_o *v119;
  System_String_o *v122;
  System_String_o *v126;
  System_String_o *v131;
  System_String_o *v137;
  bool v138;
  f32 v140;
  s16 v146;
  s32 v147;
  struct dds3KernelDraw_StaticFields *v148;
  struct dds3KernelDraw_StaticFields **v149;
  s32 v151;
  effBlur_Filter_c *v152;
  s32 v156;
  System_String_o *v157;
  System_String_o *v171;
  System_String_o *v172;
  f32 v175;
  System_String_o *NowCameraName;
  bool v180;
  s32 v183;
  f32 v185;
  System_String_o *v187;
  bool v188;
  f32 v190;
  s32 v194;
  dds3KernelDraw_c *v195;
  f32 scale;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v205;
  s32 fieldID;
  struct fldGlobalWork_t_o *v209;
  f32 v216;
  f32 v217;

  v10 = static_fields[205];
  v11 = static_fields[206];
  v13 = static_fields[207];
  else
  {
    if (!SkillID)
      goto LABEL_21;
  }
  if (!EventMode)
    goto LABEL_21;
  v15 = 0;
  if (ChkNbEventRun())
  {
      goto LABEL_23;
LABEL_15:
LABEL_23:
    if (EventNo == 682)
      goto LABEL_17;
    goto LABEL_24;
  }
LABEL_26:
  rotate = (*pBlur)->rotate;
  Postblur_blur_rotation = rotate / 6.28;
  Postblur_blur_scale = (*pBlur)->scale;
  *&v4 = Postblur_blur_rotation;
  if (*&v4 > -0.001)
  {
    if (*&v4 < 0.001)
    {
      Postblur_blur_rotation = 0.0;
    }
  }
  if (v15)
  {
    v20 = *&v17->_2.bitflags1;
    if ((v20 & 0x200) != 0)
    {
      v21 = v20 & 0x200;
    }
    else
    {
      v21 = 0;
    }
    *&v4 = Postblur_blur_scale;
    if (*&v4 < 1.0)
    {
      v23 = (1.0 - *&v4) / -3.0;
LABEL_57:
      *&v4 = v23 + 1.0;
      LODWORD(Postblur_blur_scale) = v4;
      goto LABEL_58;
    }
    if (*&v4 > 1.0)
    {
      v23 = (*&v4 + -1.0) * 0.4;
      goto LABEL_57;
    }
  }
LABEL_58:
  Postblur_blur_blend = 1;
  LOBYTE(v4) = (*pBlur)->abgr;
  v24 = v4;
  *&v24 = v24;
  *&v24 = *&v24 * 0.0078125;
  Postblur_blur_r = *&v24;
  LOBYTE(v24) = BYTE1((*pBlur)->abgr);
  v25 = *&v24;
  *&v25 = v25;
  Postblur_blur_g = *&v25 * 0.0078125;
  LOBYTE(v25) = BYTE2((*pBlur)->abgr);
  v26 = *&v25;
  *&v26 = v26;
  *&v26 = *&v26 * 0.0078125;
  Postblur_blur_b = *&v26;
  LOBYTE(v26) = HIBYTE((*pBlur)->abgr);
  *&v26 = *&v26;
  Postblur_blur_a = *&v26 * 0.0078125;
  v27 = (*pBlur)->blend;
  if (v27 > 67)
  {
    if (v27 == 72)
      goto LABEL_79;
    if (v27 != 68)
      goto LABEL_132;
  }
  else if (v27 != 1)
  {
    if (v27 != 2)
      goto LABEL_132;
LABEL_79:
    Postblur_blur_blend = 2;
    if (Postblur_blur_r < Postblur_blur_g)
    {
      if ((v17->_2.bitflags2 & 2) != 0)
      {
        else
        {
          Postblur_blur_r = Postblur_blur_g;
            goto LABEL_87;
        }
LABEL_86:
LABEL_87:
        if (Postblur_blur_r < Postblur_blur_b)
        {
LABEL_88:
          if ((v17->_2.bitflags2 & 2) == 0)
          {
            Postblur_blur_r = Postblur_blur_b;
            if (Postblur_blur_b <= 1.0)
              goto LABEL_132;
            goto LABEL_120;
          }
          Postblur_blur_r = Postblur_blur_b;
          if (Postblur_blur_r > 1.0)
          {
LABEL_120:
            Postblur_blur_r = Postblur_blur_r / Postblur_blur_r;
            Postblur_blur_g = Postblur_blur_g / Postblur_blur_r;
            Postblur_blur_b = Postblur_blur_b / Postblur_blur_r;
            Postblur_blur_a = ((Postblur_blur_r + -1.1) * 0.5) + Postblur_blur_a;
            if ((v15 & 1) == 0)
              goto LABEL_124;
            goto LABEL_133;
          }
LABEL_132:
          if (v15)
            goto LABEL_133;
LABEL_124:
          v36 = 0;
          if ((v17->_2.bitflags2 & 2) == 0)
            goto LABEL_146;
          goto LABEL_125;
        }
LABEL_131:
        if (Postblur_blur_r <= 1.0)
          goto LABEL_132;
        goto LABEL_120;
      }
      Postblur_blur_r = Postblur_blur_g;
    }
    if ((v17->_2.bitflags2 & 2) == 0)
      goto LABEL_87;
    goto LABEL_86;
  }
  Postblur_blur_g = Postblur_blur_r;
  if (Postblur_blur_g < Postblur_blur_g)
  {
    if ((v17->_2.bitflags2 & 2) != 0)
    {
      else
      {
          goto LABEL_74;
      }
LABEL_75:
      v30 = Postblur_blur_b;
      if (Postblur_blur_g < v30)
        goto LABEL_76;
LABEL_128:
      if (Postblur_blur_g <= 1.0)
        goto LABEL_132;
      goto LABEL_96;
    }
  }
  if ((v17->_2.bitflags2 & 2) == 0)
    goto LABEL_75;
LABEL_74:
    goto LABEL_75;
  v30 = Postblur_blur_b;
  if (Postblur_blur_g >= v30)
    goto LABEL_128;
LABEL_76:
  if ((v17->_2.bitflags2 & 2) != 0)
  {
    else
    {
      Postblur_blur_g = Postblur_blur_b;
      if (Postblur_blur_g <= 1.0)
        goto LABEL_132;
    }
  }
  else
  {
    Postblur_blur_g = v30;
    if (v30 <= 1.0)
      goto LABEL_132;
  }
LABEL_96:
  Postblur_blur_r = Postblur_blur_r / Postblur_blur_g;
  Postblur_blur_g = Postblur_blur_g / Postblur_blur_g;
  Postblur_blur_b = Postblur_blur_b / Postblur_blur_g;
  if (SkillID == 263)
    goto LABEL_132;
  if (v15)
  {
    if (EventNo == 661)
      goto LABEL_133;
    if (EventNo == 693)
      goto LABEL_133;
    LOBYTE(v15) = 1;
  }
  Postblur_blur_blend = 2;
  Postblur_blur_a = ((Postblur_blur_g + -1.5) * 0.5) + Postblur_blur_a;
  if ((v15 & 1) == 0)
    goto LABEL_124;
LABEL_133:
  if (Postblur_blur_a > 0.0)
  {
    Postblur_blur_a = Postblur_blur_a * 1.1;
    if (Postblur_blur_a > 1.0)
    {
      Postblur_blur_a = 1.0;
    }
  }
  v36 = 1;
  if ((v17->_2.bitflags2 & 2) != 0)
  {
LABEL_125:
  }
LABEL_146:
  v42 = Postblur_blur_a;
  Postblur_blur_a = v42 * FldEve_Pow;
  FldEve_Pow = 1.0;
  if (Postblur_blur_a < 0.0)
  {
    Postblur_blur_a = 0.0;
  }
  if (bPS2mode)
  {
    width = get_width(0);
    pm = (*pBlur)->center->pm;
    v46 = width;
    v48 = pm->m_Items[0];
    v50 = get_width(0);
    Postblur_blur_center_x = (((((v46 * 0.5) / 320.0) * v48) / (v50 * 0.5)) * 0.5) + 0.5;
    height = get_height(0);
    v53 = (*pBlur)->center->pm;
    v54 = height;
    v56 = v53->m_Items[1];
    v58 = get_height(0);
    v60 = ((((v54 * 0.5) / 224.0) * v56) / (v58 * 0.5)) * 0.5;
  }
  else
  {
    v61 = (*pBlur)->center->pm;
    v63 = v61->m_Items[0];
    v65 = get_width(0);
    Postblur_blur_center_x = (v63 / v65) + 0.5;
    v67 = (*pBlur)->center->pm;
    v69 = v67->m_Items[1];
    v60 = v69 / get_height(0);
  }
  Postblur_blur_center_y = 0.5 - v60;
  if (Postblur_blur_center_x >= -0.5)
  {
    else
    {
      v72 = 1.5;
      if (Postblur_blur_center_x > 1.5)
        goto LABEL_225;
    }
    else
    {
      if (Postblur_blur_center_y < -0.5)
        goto LABEL_225;
    }
    if (Postblur_blur_center_y <= v72)
    {
      if (SkillID != 263)
        goto LABEL_228;
      goto LABEL_186;
    }
  }
LABEL_225:
  else
  {
    Postblur_blur_blend = 0;
    if (SkillID != 263)
      goto LABEL_228;
  }
LABEL_186:
  Postblur_blur_a = Postblur_blur_a * 0.7;
  if (Postblur_blur_a > 0.45)
  {
    Postblur_blur_a = 0.45;
    if (!v36)
      goto LABEL_758;
    goto LABEL_194;
  }
LABEL_228:
  if (!v36)
    goto LABEL_758;
LABEL_194:
  if (EventNo == 601)
  {
    if (Postblur_blur_blend == 2)
    {
      Postblur_blur_scale = 0.98;
      (*p_static_fields)->Postblur_blur_center_x = 0.5;
      (*p_static_fields)->Postblur_blur_center_y = 0.53;
    }
  }
  else
  {
    v80 = EventNo;
    if (v80 == 614)
      goto LABEL_233;
  }
  else if (v80 != 704)
  {
    goto LABEL_212;
  }
LABEL_233:
  Postblur_blur_scale = 0.995;
  if ((v79->_2.bitflags2 & 2) == 0)
  {
LABEL_237:
    if (EventNo == 617)
      goto LABEL_215;
LABEL_238:
    if ((v79->_2.bitflags2 & 2) == 0)
      goto LABEL_240;
    goto LABEL_239;
  }
LABEL_213:
    goto LABEL_237;
  if (EventNo != 617)
    goto LABEL_238;
LABEL_215:
  Postblur_blur_scale = 0.99;
  Postblur_blur_a = Postblur_blur_a * 0.7;
  if ((v79->_2.bitflags2 & 2) == 0)
  {
LABEL_240:
    if (EventNo != 628)
      goto LABEL_275;
    goto LABEL_241;
  }
LABEL_239:
    goto LABEL_240;
  if (EventNo != 628)
    goto LABEL_275;
LABEL_241:
  if (Postblur_blur_blend != 1)
  {
LABEL_274:
LABEL_275:
    if ((v79->_2.bitflags2 & 2) == 0)
      goto LABEL_276;
    goto LABEL_263;
  }
LABEL_244:
  Postblur_blur_a = Postblur_blur_a * 0.7;
  EventCamName = GetEventCamName();
  v86 = op_Equality(EventCamName, "c02", 0);
  if (v86)
  {
    if (E628_pm_CntI == 44)
    {
      Postblur_blur_a = 0.0;
    }
    ++E628_pm_CntI;
    if ((v79->_2.bitflags2 & 2) == 0)
      goto LABEL_276;
  }
  else
  {
    E628_pm_CntI = 0;
    if ((v79->_2.bitflags2 & 2) == 0)
      goto LABEL_276;
  }
LABEL_263:
LABEL_276:
  if (EventNo != 634)
    goto LABEL_293;
LABEL_277:
  if (op_Equality(evtUpdateEx_FieldName, "f634_050(Clone)", 0))
  {
    v89 = GetEventCamName();
    if (op_Equality(v89, "cam11", 0))
    {
      if (Postblur_blur_blend == 2)
      {
        Postblur_blur_a = Postblur_blur_a * 0.7;
      }
    }
  }
LABEL_293:
  if (EventNo == 646)
  {
    if (op_Equality(evtUpdateEx_FieldName, "f646_004(Clone)", 0))
    {
      Postblur_blur_scale = 1.01;
      Postblur_blur_a = Postblur_blur_a * 0.4;
    }
  }
  if (EventNo == 651)
  {
    if (op_Equality(evtUpdateEx_FieldName, "f651_001(Clone)", 0))
    {
      v97 = GetEventCamName();
      if (op_Equality(v97, "cam10", 0))
        goto LABEL_321;
      v98 = GetEventCamName();
      if (op_Equality(v98, "cam11", 0))
      {
LABEL_321:
        Postblur_blur_a = Postblur_blur_a * 0.7;
      }
    }
  }
  else if (EventNo != 655)
  {
    goto LABEL_367;
  }
  v100 = evtBitCheck(68);
  if (!v100)
  {
    if (Postblur_blur_blend == 2)
    {
      v108 = GetEventCamName();
      if (!op_Equality(v108, "cam03", 0))
        goto LABEL_367;
      v111 = 0.7;
    }
    else
    {
      Postblur_blur_rotation = 0.0;
      (*v106)->Postblur_blur_scale = 1.0;
      v110 = *v106;
      v111 = 0.3;
    }
    Postblur_blur_a = Postblur_blur_a * v111;
    goto LABEL_367;
  }
  if (Postblur_blur_blend == 2)
  {
    Postblur_blur_a = Postblur_blur_a * 1.2;
  }
  v103 = GetEventCamName();
  if (op_Equality(v103, "cam02a", 0))
  {
    E655_After_CntF = 0.0;
    E655_After_CntF2 = 0.0;
      goto LABEL_368;
    goto LABEL_345;
  }
LABEL_367:
    goto LABEL_368;
LABEL_345:
LABEL_368:
  if (EventNo != 661)
    goto LABEL_417;
LABEL_369:
  if (op_Equality(evtUpdateEx_FieldName, "f661_010(Clone)", 0))
  {
    v113 = GetEventCamName();
    if (op_Equality(v113, "cam06", 0))
    {
      Postblur_blur_b = Postblur_blur_b * 0.7;
      Postblur_blur_a = Postblur_blur_a * 0.7;
    }
    v116 = GetEventCamName();
    if (op_Equality(v116, "cam07", 0))
    {
      Postblur_blur_center_x = 0.36;
      Postblur_blur_center_y = 0.8;
      Postblur_blur_a = Postblur_blur_a * 0.7;
    }
    v119 = GetEventCamName();
    if (op_Equality(v119, "cam09", 0))
    {
      Postblur_blur_a = Postblur_blur_a * 1.2;
    }
    v122 = GetEventCamName();
    if (op_Equality(v122, "cam10", 0))
    {
      Postblur_blur_a = Postblur_blur_a * 1.3;
      if (Postblur_blur_a > 0.85)
      {
        Postblur_blur_a = 0.85;
      }
    }
    v126 = GetEventCamName();
    if (op_Equality(v126, "cam11", 0))
    {
      Postblur_blur_rotation = -0.02;
      Postblur_blur_a = Postblur_blur_a * 1.2;
    }
  }
LABEL_417:
  if (EventNo == 671)
  {
    Postblur_blur_blend = 1;
  }
  if (EventNo == 674)
  {
    if (Postblur_blur_blend == 2)
    {
      v131 = GetEventCamName();
      if (op_Equality(v131, "cam25", 0))
      {
        Postblur_blur_g = Postblur_blur_g * 0.6;
        Postblur_blur_b = Postblur_blur_b * 0.6;
        Postblur_blur_a = Postblur_blur_a * 0.4;
      }
    }
  }
  if (EventNo == 693)
  {
    if (op_Equality(evtUpdateEx_FieldName, "f693_020(Clone)", 0))
    {
      Postblur_blur_scale = 0.998;
      Postblur_blur_r = 0.8;
      Postblur_blur_g = 0.9;
      Postblur_blur_b = 1.0;
      Postblur_blur_a = 0.5;
    }
  }
  if (EventNo == 697)
  {
    v137 = GetEventCamName();
    v138 = op_Equality(v137, "cam01", 0);
    if (v138)
    {
      v140 = 0.5;
    }
    else
    {
      v140 = 0.7;
    }
    Postblur_blur_a = Postblur_blur_a * v140;
  }
  if (EventNo == 703)
  {
    if (op_Equality(evtUpdateEx_FieldName, "f676_030(Clone)", 0))
    {
      Postblur_blur_scale = Postblur_blur_scale * 0.99;
      Postblur_blur_blend = 1;
      Postblur_blur_a = Postblur_blur_a * 1.3;
    }
  }
  if (EventNo == 705)
  {
    if ((v146 & 0x200) != 0)
    {
      v147 = v146 & 0x200;
    }
    else
    {
      v147 = 0;
    }
    if (Postblur_blur_blend == 2)
    {
      Postblur_blur_scale = Postblur_blur_scale + -0.01;
      (*v149)->Postblur_blur_r = (*v149)->Postblur_blur_r * 0.7;
      (*v149)->Postblur_blur_g = (*v149)->Postblur_blur_g * 0.7;
      v148 = *v149;
    }
    {
    }
    Postblur_blur_a = Postblur_blur_a * 0.6;
  }
  else
  {
    v151 = EventNo;
    if (v151 == 705)
      goto LABEL_516;
  }
  if (EventNo == 699)
    goto LABEL_516;
LABEL_505:
    goto LABEL_524;
LABEL_506:
    goto LABEL_524;
  if (EventNo == 715)
  {
LABEL_508:
    Postblur_blur_r = Postblur_blur_r * 0.8;
    Postblur_blur_g = Postblur_blur_g * 0.8;
    Postblur_blur_a = Postblur_blur_a * 0.35;
    if ((v152->_2.bitflags2 & 2) == 0)
      goto LABEL_527;
    goto LABEL_526;
  }
LABEL_525:
  if ((v152->_2.bitflags2 & 2) == 0)
    goto LABEL_527;
LABEL_526:
LABEL_527:
  v156 = EventNo;
  if (v156 == 718)
    goto LABEL_567;
LABEL_528:
  if (EventNo == 719)
    goto LABEL_567;
LABEL_531:
  if ((v152->_2.bitflags2 & 2) == 0)
    goto LABEL_571;
LABEL_532:
LABEL_571:
  if (EventNo != 723)
  {
LABEL_572:
      goto LABEL_575;
    goto LABEL_573;
  }
LABEL_534:
  if (evtBitCheck(3712))
    goto LABEL_572;
  v157 = GetEventCamName();
  if (op_Equality(v157, "camera02", 0)
    || op_Equality(v157, "camera03", 0)
    || op_Equality(v157, "camera04", 0))
  {
    Postblur_blur_g = Postblur_blur_g * 0.8;
    Postblur_blur_a = Postblur_blur_a * 1.3;
    {
LABEL_573:
    }
  }
  else
  {
    Postblur_blur_a = Postblur_blur_a * 0.7;
      goto LABEL_573;
  }
LABEL_575:
  if (EventNo == 723 && evtBitCheck(3712))
  {
    Postblur_blur_a = Postblur_blur_a * 0.7;
    if (Postblur_blur_g < 0.89)
    {
      Postblur_blur_g = 0.89;
    }
    if (Postblur_blur_b < 0.4)
    {
      Postblur_blur_b = 0.4;
    }
    if (evtUpdateEx_Dante_e730after)
    {
      v171 = GetEventCamName();
      if (op_Equality(v171, "cam01", 0))
        goto LABEL_605;
      v172 = GetEventCamName();
      if (op_Equality(v172, "cam02", 0))
      {
LABEL_605:
        v175 = 0.9;
LABEL_620:
        Postblur_blur_a = Postblur_blur_a * v175;
        goto LABEL_621;
      }
      v216 = Postblur_blur_b * 0.1;
      v217 = 1.05;
LABEL_828:
      Postblur_blur_b = v216;
      Postblur_blur_a = Postblur_blur_a * v217;
        goto LABEL_624;
      goto LABEL_622;
    }
    NowCameraName = GetNowCameraName();
    if (op_Equality(NowCameraName, "Camera03", 0)
      || op_Equality(NowCameraName, "Camera04", 0)
      || op_Equality(NowCameraName, "Camera05", 0)
      || op_Equality(NowCameraName, "Camera06", 0))
    {
      v175 = 1.1;
      goto LABEL_620;
    }
    if (op_Equality(NowCameraName, "Camera07", 0))
    {
      Postblur_blur_g = 0.95;
      v216 = Postblur_blur_b * 0.6;
      v217 = 1.1;
      goto LABEL_828;
    }
  }
LABEL_621:
    goto LABEL_624;
LABEL_622:
LABEL_624:
  if (EventNo == 726)
  {
    v180 = op_Equality(evtUpdateEx_FieldName, "f726_010(Clone)", 0);
    if (v180)
    {
      Postblur_blur_scale = Postblur_blur_scale * 0.99;
      Postblur_blur_r = Postblur_blur_r * 1.2;
      Postblur_blur_g = Postblur_blur_g * 1.2;
      Postblur_blur_b = Postblur_blur_b * 1.2;
        goto LABEL_657;
      goto LABEL_633;
    }
    if (Postblur_blur_blend == 2)
    {
      v185 = Postblur_blur_a;
      if (v185 < 0.4)
      {
        Postblur_blur_a = v185 + v185;
      }
    }
    if (Postblur_blur_scale == 1.0)
    {
      Postblur_blur_scale = 0.99;
    }
  }
    goto LABEL_657;
LABEL_633:
LABEL_657:
  v183 = EventNo;
  if (v183 >= 740)
  {
LABEL_658:
    if (v183 > 750)
      goto LABEL_758;
    if (v183 != 748)
    {
LABEL_698:
      v194 = EventNo;
      if (v194 == 741)
        goto LABEL_706;
      if (v194 == 742)
      {
LABEL_706:
        if (Postblur_blur_a > 0.9)
        {
          if (Postblur_blur_r < v10)
          {
            Postblur_blur_r = v10;
          }
          if (Postblur_blur_g < v11)
          {
            Postblur_blur_g = v11;
          }
          if (Postblur_blur_b < v13)
          {
            Postblur_blur_b = v13;
          }
        }
        if (Postblur_blur_a > 0.7)
        {
          scale = (*pBlur)->scale;
          Postblur_blur_scale = scale;
        }
      }
      else
      {
        if (v194 == 750)
        {
          Postblur_blur_a = Postblur_blur_a * 0.5;
          Postblur_blur_scale = (*pBlur)->scale;
          goto LABEL_758;
        }
        if (Postblur_blur_a > 0.7)
        {
          Postblur_blur_a = 0.7;
          Postblur_blur_scale = (*pBlur)->scale;
          if ((v195->_2.bitflags2 & 2) == 0)
            goto LABEL_745;
          goto LABEL_743;
        }
      }
      if ((v195->_2.bitflags2 & 2) == 0)
      {
LABEL_745:
        if (Postblur_blur_scale >= 1.0)
        {
          Postblur_blur_a = Postblur_blur_a * 0.85;
        }
        goto LABEL_758;
      }
LABEL_743:
      goto LABEL_745;
    }
    v187 = GetEventCamName();
    v188 = op_Equality(v187, "01cam_10", 0);
    if (v188)
    {
      E748_alp = E748_alp + 0.02;
      v190 = 1.0;
      if (E748_alp <= 1.0)
        goto LABEL_691;
    }
    else
    {
      v190 = 0.6;
    }
    goto LABEL_690;
  }
LABEL_758:
  if (fldGb->fieldID == 37)
  {
    if (fldGb->areaID == 26)
    {
      Postblur_blur_r = Postblur_blur_r * 0.5;
      Postblur_blur_g = Postblur_blur_g * 0.5;
      Postblur_blur_b = Postblur_blur_b * 0.5;
      Postblur_blur_a = Postblur_blur_a * 0.25;
    }
  }
  v205 = fldGb;
  fieldID = v205->fieldID;
  if (fieldID >= 200)
  {
    if (fieldID <= 499)
    {
      if (fieldID == 244)
      {
        if (v205->areaID == 2)
        {
          if (ChkNbEventRun())
          {
            Postblur_blur_a = Postblur_blur_a * 0.5;
          }
        }
      }
      v209 = fldGb;
      if (v209->fieldID == 245)
      {
        if (v209->areaID == 2)
        {
          if (ChkNbEventRun())
          {
            Postblur_blur_a = Postblur_blur_a * 0.5;
          }
        }
      }
    }
  }
  if (SkillID == 216)
  {
    Postblur_blur_a = Postblur_blur_a * 0.5;
  }
  UpdateFlg_blur = 1;
}

// 0x137a050
void dds3EffectBlur_AlphaMultiParmSet(dds3Effect_Blur_t **pBlur, effPkt2DTriStripParm_t **pSpriteParm) {
  struct sdfGrTagXYZ2_t_o *xyz0;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *pm;
  struct sdfIVector2_t_array *v9;
  struct System_Int32_array *v11;
  struct sdfIVector2_t_array *v13;
  struct System_Int32_array *v15;
  struct sdfIVector2_t_array *v17;
  struct System_Int32_array *v19;

  (*pSpriteParm)->rgba->r = 128;
  (*pSpriteParm)->rgba->g = 128;
  (*pSpriteParm)->rgba->b = 128;
  (*pSpriteParm)->rgba->a = HIBYTE((*pBlur)->abgr);
  xyz0 = (*pSpriteParm)->xyz0;
  xy = (*pBlur)->xy;
  pm = xy->m_Items[0]->pm;
  xyz0->x = DDS3_SCREEN_OFFX + 16 * pm->m_Items[0];
  v9 = (*pBlur)->xy;
  v11 = v9->m_Items[0]->pm;
  (*pSpriteParm)->xyz0->y = DDS3_SCREEN_OFFY + 8 * v11->m_Items[1];
  (*pSpriteParm)->xyz1->x = (*pSpriteParm)->xyz0->x;
  v13 = (*pBlur)->xy;
  v15 = v13->m_Items[1]->pm;
  (*pSpriteParm)->xyz1->y = DDS3_SCREEN_OFFY + 8 * v15->m_Items[1];
  v17 = (*pBlur)->xy;
  v19 = v17->m_Items[1]->pm;
  (*pSpriteParm)->xyz2->x = DDS3_SCREEN_OFFX
                                        + 16 * v19->m_Items[0];
  (*pSpriteParm)->xyz2->y = (*pSpriteParm)->xyz0->y;
  (*pSpriteParm)->xyz3->x = (*pSpriteParm)->xyz2->x;
  (*pSpriteParm)->xyz3->y = (*pSpriteParm)->xyz1->y;
  (*pSpriteParm)->stq0->s = 0.0;
  (*pSpriteParm)->stq0->t = 0.0;
  (*pSpriteParm)->stq1->s = 0.0;
  (*pSpriteParm)->stq1->t = 1.0;
  (*pSpriteParm)->stq2->s = 1.0;
  (*pSpriteParm)->stq2->t = 0.0;
  (*pSpriteParm)->stq3->s = 1.0;
  (*pSpriteParm)->stq3->t = 1.0;
  (*pSpriteParm)->xyz0->z = 0;
  (*pSpriteParm)->xyz0->adc = 0;
  (*pSpriteParm)->xyz1->z = 0;
  (*pSpriteParm)->xyz1->adc = 0;
  (*pSpriteParm)->xyz2->z = 0;
  (*pSpriteParm)->xyz2->adc = 0;
  (*pSpriteParm)->xyz3->z = 0;
  (*pSpriteParm)->xyz3->adc = 0;
}

// 0x137f3f0
void dds3EffectDistBlurPartInit(dds3Effect_DistortionBlurParam_t *pParam, dds3Effect_DistBlurPart_tag **pPart) {
  dds3Effect_DistBlurPart_tag_o *v5;
  struct dds3Effect_Blur_t_o *Blur;
  u64 *v7;
  struct sdfIVector2_t_array *v8;
  struct sdfIVector2_t_o *center;
  s32 width;
  struct System_Int32_array *pm;
  struct System_Int32_array *v13;
  s32 v15;
  f32 area;
  f32 v17;
  s32 v18;
  struct System_Int32_array *v20;
  struct System_Int32_array *v21;
  f32 v23;
  s32 v24;
  struct System_Int32_array *v26;
  u32 max_length;
  s32 v28;
  s32 v30;
  struct sdfIVector2_t_array *xy;
  u64 *v32;
  struct sdfIVector2_t_array *v34;
  s32 v35;
  s32 v36;
  struct System_Int32_array *v38;
  s32 v39;
  struct sdfIVector2_t_array *v41;
  s32 v42;
  struct System_Int32_array *v44;
  struct sdfIVector2_t_array *v46;
  u64 *v47;
  struct sdfIVector2_t_array *v49;
  struct System_Int32_array *v51;
  struct sdfIVector2_t_array *v53;
  struct System_Int32_array *v55;
  s32 v56;

  v5 = *pPart;
  v5->wait = DDS3EFFECT_RAND_I() % (pParam->interval + 1);
  (*pPart)->radiun = -3.1416;
  Blur = (*pPart)->Blur;
  Blur->abgr = pParam->abgr;
  Blur->blend = pParam->blend;
  Blur->rotate = pParam->rotate;
  v7 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v7);
  Blur->center = v7;
  v8 = NewSpecific(sdfIVector2_t, 2u);
  center = Blur->center;
  Blur->xy = v8;
  width = pParam->width;
  pm = center->pm;
  v13 = pParam->center->pm;
  v15 = v13->m_Items[0];
  area = pParam->area;
  v17 = area;
  v18 = (DDS3EFFECT_RAND_PM() * v17) + v15;
  pm->m_Items[0] = v18;
  v20 = Blur->center->pm;
  v21 = pParam->center->pm;
  v23 = v21->m_Items[1];
  v24 = (DDS3EFFECT_RAND_PM() * v17) + v23;
  v20->m_Items[1] = v24;
  v26 = Blur->center->pm;
  max_length = v26->max_length;
  v28 = v26->m_Items[0];
  v30 = Blur->center->pm->m_Items[1];
  xy = Blur->xy;
  v32 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v32);
  xy->m_Items[0] = v32;
  v34 = Blur->xy;
  v35 = width >> 1;
  v36 = v28 + 960;
  v38 = v34->m_Items[0]->pm;
  v39 = v35;
  v38->m_Items[0] = v36 - v39;
  v41 = Blur->xy;
  v42 = v30 + 540;
  v44 = v41->m_Items[0]->pm;
  v44->m_Items[1] = v42 - v39;
  v46 = Blur->xy;
  v47 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v47);
  v46->m_Items[1] = v47;
  v49 = Blur->xy;
  v51 = v49->m_Items[1]->pm;
  v51->m_Items[0] = v36 + v39;
  v53 = Blur->xy;
  v55 = v53->m_Items[1]->pm;
  v56 = v42 + v39;
  v55->m_Items[1] = v56;
}

// 0x137f870
effDistortionBlurHandle_t *dds3EffectDistortionBlurCreate(dds3Effect_DistortionBlurParam_t *pParam) {
  effDistortionBlurHandle_t_o *v3;

  v3 = Allocate(effDistortionBlurHandle_t);
  effDistortionBlurHandle_t___ctor(v3);
  v3->param = pParam;
  return v3;
}

// 0x137f8e0
void dds3EffectDistortionBlurDelete(effDistortionBlurHandle_t **hDistortionBlur) {
  ;
}

// 0x137f8f0
void dds3EffectDistortionBlurDraw(effDistortionBlurHandle_t **hDistortionBlur, bool bPS2mode, s32 SkillID) {
  u64 v4;
  _BOOL4 EventMode;
  s32 v11;
  s32 blend;
  dds3KernelDraw_c *v17;
  f32 speed;
  f32 v19;
  s32 width;
  f32 v21;
  f32 distortion;
  f64 v23;
  f64 v24;
  f64 v25;
  f32 Postblur_distortionblur_r;
  f32 Postblur_distortionblur_b;
  f32 v29;
  s16 v30;
  s32 v32;
  f32 v33;
  s32 v34;
  struct System_Int32_array *pm;
  s32 v36;
  s32 v38;
  s32 v40;
  s32 height;
  struct System_Int32_array *v43;
  s32 v44;
  s32 v46;
  s32 v48;
  dds3KernelDraw_c *v49;
  f32 v50;
  struct System_Int32_array *v51;
  s32 v53;
  s32 v55;
  struct System_Int32_array *v57;
  s32 v59;
  f32 Postblur_distortionblur_center_x;
  f32 v62;
  f32 v63;
  f32 Postblur_distortionblur_center_y;
  System_String_o *EventCamName;
  bool v68;
  struct dds3KernelDraw_StaticFields **p_static_fields;
  s32 v72;
  f32 v73;
  effBlur_Filter_c *v75;
  s32 EventNo;
  f32 v91;
  System_String_o *v92;
  f32 v98;
  f32 E655_After_CntF;
  f32 E655_After_CntF2;
  f32 v106;
  System_String_o *NowName_SCR_RUN;
  bool v112;
  struct dds3KernelDraw_StaticFields **v114;
  System_String_o *v116;
  bool v117;
  effBlur_Filter_c *v120;
  f32 E674_aradia_CntF;
  f32 v122;
  u64 v123;
  u32 number;
  f32 v125;
  f32 v126;
  f32 v128;
  f32 v129;
  f32 v132;
  s32 v139;
  f32 AlphaF;
  f32 ColAverageF;
  f32 v143;
  f32 v144;
  struct dds3KernelDraw_StaticFields **v145;
  System_String_o *v148;
  f32 v151;
  s32 v152;
  System_String_o *v154;
  u64 v159;
  u32 abgr;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  struct fldGlobalWork_t_o *v171;
  struct fldGlobalWork_t_o *v174;
  effBlur_Filter_c *v176;
  s32 FldEve_UnityEx_ID;
  f32 v181;
  f32 FldEve_UnityEx_CntF;
  f32 v186;
  f32 v188;
  f32 v191;
  f32 v193;
  f32 v195;
  f32 v196;
  f32 v198;
  s16 v201;
  s32 v202;
  f32 v203;
  f32 v205;
  f32 v206;
  f32 v208;
  f64 v210;
  f32 v211;
  f32 v212;
  u32 v213;

  v11 = EventMode;
  if (SkillID && EventMode)
  {
    v11 = EventMode & ChkNbEventRun();
  }
  blend = (*hDistortionBlur)->param->blend;
  if (blend == 68 || blend == 1)
  {
    Postblur_distortionblur_blend = 1;
    blend = (*hDistortionBlur)->param->blend;
  }
  if (blend == 72 || blend == 2)
  {
    Postblur_distortionblur_blend = 2;
    blend = (*hDistortionBlur)->param->blend;
  }
  if (blend == 66)
  {
    Postblur_distortionblur_blend = 3;
  }
  Postblur_distortionblur_moyaalp = 0.0;
  Postblur_distortionblur_moyarotspd = 0.003;
  Postblur_distortionblur_moya_r = 1.0;
  Postblur_distortionblur_moya_g = 1.0;
  Postblur_distortionblur_moya_b = 1.0;
  Postblur_distortionblur_moya_sizemul = 1.0;
  speed = (*hDistortionBlur)->param->speed;
  if (v11)
  {
    v19 = 4.0;
    if ((*&v17->_2.bitflags1 & 0x200) == 0)
      goto LABEL_43;
  }
  else
  {
    v19 = 10.0;
    if ((*&v17->_2.bitflags1 & 0x200) == 0)
      goto LABEL_43;
  }
LABEL_43:
  Postblur_distortionblur_speed = speed * v19;
  width = (*hDistortionBlur)->param->width;
  if (v11)
  {
    v21 = 400.0;
    if ((*&v17->_2.bitflags1 & 0x200) == 0)
      goto LABEL_48;
  }
  else
  {
    v21 = 150.0;
    if ((*&v17->_2.bitflags1 & 0x200) == 0)
      goto LABEL_48;
  }
LABEL_48:
  Postblur_distortionblur_distor1 = width / v21;
  distortion = (*hDistortionBlur)->param->distortion;
  *&v4 = distortion * 0.5;
  Postblur_distortionblur_distor2 = distortion * 0.5;
  LOBYTE(v4) = (*hDistortionBlur)->param->abgr;
  v23 = v4;
  *&v23 = v23;
  Postblur_distortionblur_r = *&v23 * 0.0078125;
  LOBYTE(v23) = BYTE1((*hDistortionBlur)->param->abgr);
  v24 = *&v23;
  *&v24 = v24;
  *&v24 = *&v24 * 0.0078125;
  Postblur_distortionblur_g = *&v24;
  LOBYTE(v24) = BYTE2((*hDistortionBlur)->param->abgr);
  v25 = *&v24;
  *&v25 = v25;
  Postblur_distortionblur_b = *&v25 * 0.0078125;
  LOBYTE(v25) = HIBYTE((*hDistortionBlur)->param->abgr);
  *&v25 = *&v25;
  Postblur_distortionblur_a = *&v25 * 0.0078125;
  if (Postblur_distortionblur_r >= Postblur_distortionblur_g)
  {
LABEL_54:
    if ((v17->_2.bitflags2 & 2) == 0)
      goto LABEL_56;
    goto LABEL_55;
  }
  if ((v17->_2.bitflags2 & 2) == 0)
  {
    Postblur_distortionblur_r = Postblur_distortionblur_g;
    goto LABEL_54;
  }
  else
  {
    Postblur_distortionblur_r = Postblur_distortionblur_g;
      goto LABEL_56;
  }
LABEL_55:
LABEL_56:
  if (Postblur_distortionblur_r >= Postblur_distortionblur_b)
    goto LABEL_73;
LABEL_57:
  Postblur_distortionblur_r = Postblur_distortionblur_b;
  v29 = 1.0;
  if (Postblur_distortionblur_b <= 1.0)
    goto LABEL_60;
LABEL_74:
  Postblur_distortionblur_r = Postblur_distortionblur_r
                                                / Postblur_distortionblur_r;
  Postblur_distortionblur_g = Postblur_distortionblur_g
                                                / Postblur_distortionblur_r;
  Postblur_distortionblur_b = Postblur_distortionblur_b
                                                / Postblur_distortionblur_r;
  v30 = *&v17->_2.bitflags1;
  if (v11)
  {
LABEL_61:
    Postblur_distortionblur_a = Postblur_distortionblur_a * 2.4;
    if (Postblur_distortionblur_a > 0.8)
    {
      v32 = 1061997773;
LABEL_86:
      LODWORD(Postblur_distortionblur_a) = v32;
      goto LABEL_87;
    }
    goto LABEL_87;
  }
LABEL_78:
  Postblur_distortionblur_a = Postblur_distortionblur_a * 0.6;
  if (Postblur_distortionblur_a > v29)
  {
    v32 = 1065353216;
    goto LABEL_86;
  }
LABEL_87:
  v33 = (*hDistortionBlur)->param->area / 224.0;
  Postblur_distortionblur_area_y = v33;
  Postblur_distortionblur_area_x = v33;
  if (bPS2mode)
  {
    v34 = get_width(0);
    pm = (*hDistortionBlur)->param->center->pm;
    v36 = v34;
    v38 = pm->m_Items[0];
    v40 = get_width(0);
    Postblur_distortionblur_center_x = (((((v36 * 0.5) / 320.0) * v38) / (v40 * 0.5)) * 0.5) + 0.5;
    height = get_height(0);
    v43 = (*hDistortionBlur)->param->center->pm;
    v44 = height;
    v46 = v43->m_Items[1];
    v48 = get_height(0);
    v50 = ((((v44 * 0.5) / 224.0) * v46) / (v48 * 0.5)) * 0.5;
  }
  else
  {
    v51 = (*hDistortionBlur)->param->center->pm;
    v53 = v51->m_Items[0];
    v55 = get_width(0);
    Postblur_distortionblur_center_x = (v53 / v55) + 0.5;
    v57 = (*hDistortionBlur)->param->center->pm;
    v59 = v57->m_Items[1];
    v50 = v59 / get_height(0);
  }
  Postblur_distortionblur_center_y = 0.5 - v50;
  v62 = -0.5;
  if (Postblur_distortionblur_center_x >= -0.5)
  {
    else
    {
      v63 = 1.5;
      if (Postblur_distortionblur_center_x > 1.5)
        goto LABEL_174;
    }
    else
    {
      if (Postblur_distortionblur_center_y < -0.5)
        goto LABEL_174;
    }
    if (Postblur_distortionblur_center_y <= v63)
    {
      if ((v49->_2.bitflags2 & 2) == 0)
        goto LABEL_177;
      goto LABEL_122;
    }
  }
LABEL_174:
  else
  {
    Postblur_distortionblur_blend = 0;
    if ((v49->_2.bitflags2 & 2) == 0)
      goto LABEL_177;
  }
LABEL_122:
LABEL_177:
  Postblur_distortionblur_speedmode = 0;
  if (!v11)
    goto LABEL_506;
LABEL_124:
  Postblur_distortionblur_speedmode = 1;
  if (EventNo == 601)
  {
    Postblur_distortionblur_center_x = 0.5;
    Postblur_distortionblur_center_y = 0.5;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 1.5;
    Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2
                                                        + Postblur_distortionblur_distor2;
    EventCamName = GetEventCamName();
    v68 = op_Equality(EventCamName, "cam01", 0);
    if (v68)
    {
      Postblur_distortionblur_area_x = 1.0;
      (*p_static_fields)->Postblur_distortionblur_area_y = 0.7;
      (*p_static_fields)->Postblur_distortionblur_center_x = 0.5;
      (*p_static_fields)->Postblur_distortionblur_center_y = 0.67;
      (*p_static_fields)->Postblur_distortionblur_distor1 = (*p_static_fields)->Postblur_distortionblur_distor1 * 0.2;
      v72 = 1050253722;
      v73 = 0.5;
    }
    else
    {
      Postblur_distortionblur_blend = 1;
      (*p_static_fields)->Postblur_distortionblur_area_x = 1.0;
      (*p_static_fields)->Postblur_distortionblur_area_y = 0.5;
      (*p_static_fields)->Postblur_distortionblur_center_x = 0.5;
      (*p_static_fields)->Postblur_distortionblur_center_y = 0.63;
      (*p_static_fields)->Postblur_distortionblur_distor1 = (*p_static_fields)->Postblur_distortionblur_distor1 * 0.3;
      v73 = 1.1;
      (*p_static_fields)->Postblur_distortionblur_distor2 = (*p_static_fields)->Postblur_distortionblur_distor2 * 1.5;
      v72 = 1063675494;
    }
    LODWORD((*p_static_fields)->Postblur_distortionblur_moyaalp) = v72;
    (*p_static_fields)->Postblur_distortionblur_moyarotspd = (*p_static_fields)->Postblur_distortionblur_moyarotspd
                                                           * v73;
  }
  else
  {
    if (EventNo == 614)
      goto LABEL_182;
  }
  else if (EventNo == 704)
  {
    goto LABEL_182;
  }
  if (EventNo != 705)
  {
    if ((v75->_2.bitflags2 & 2) == 0)
      goto LABEL_186;
    goto LABEL_158;
  }
LABEL_182:
  Postblur_distortionblur_blend = 1;
  Postblur_distortionblur_speed = 0.5;
  Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 1.2;
  Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 4.0;
  Postblur_distortionblur_a = Postblur_distortionblur_a * 3.0;
  Postblur_distortionblur_moyaalp = 1.0;
  if ((v75->_2.bitflags2 & 2) == 0)
  {
LABEL_186:
    if (EventNo == 615)
      goto LABEL_160;
LABEL_187:
    if ((v75->_2.bitflags2 & 2) == 0)
      goto LABEL_190;
    goto LABEL_188;
  }
LABEL_158:
    goto LABEL_186;
  if (EventNo != 615)
    goto LABEL_187;
LABEL_160:
  Postblur_distortionblur_moyaalp = Postblur_distortionblur_a * -0.1;
  Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1
                                                      * (Postblur_distortionblur_a * 1.1);
  Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2
                                                      * (Postblur_distortionblur_a * 1.1);
  if ((v75->_2.bitflags2 & 2) != 0)
  {
LABEL_188:
  }
LABEL_190:
  if (EventNo == 617)
  {
    Postblur_distortionblur_a = Postblur_distortionblur_a * 0.8;
    if (Postblur_distortionblur_a > 0.4)
    {
      Postblur_distortionblur_a = 0.4;
    }
  }
  if (EventNo == 628)
  {
    Postblur_distortionblur_a = Postblur_distortionblur_a * 0.7;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.8;
    Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 0.9;
  }
  if (EventNo == 629)
  {
    Postblur_distortionblur_speed = 0.5;
    Postblur_distortionblur_distor1 = 0.25;
    Postblur_distortionblur_distor2 = 0.055;
  }
  if (EventNo == 634)
  {
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.7;
    Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 0.7;
  }
  if (EventNo == 646)
  {
    if (op_Equality(evtUpdateEx_FieldName, "f646_004(Clone)", 0))
    {
      Postblur_distortionblur_speed = 0.7;
      Postblur_distortionblur_distor1 = 0.3;
      Postblur_distortionblur_distor2 = 1.0;
      Postblur_distortionblur_a = Postblur_distortionblur_a * 0.3;
      Postblur_distortionblur_moyaalp = -0.2;
      Postblur_distortionblur_a = 0.3;
    }
  }
  if (EventNo == 651)
  {
    Postblur_distortionblur_a = Postblur_distortionblur_a * 0.9;
    if (Postblur_distortionblur_a > 0.66)
    {
      Postblur_distortionblur_a = 0.66;
    }
    v91 = Postblur_distortionblur_a * 1.5152;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * v91;
    Postblur_distortionblur_distor2 = v91 * Postblur_distortionblur_distor2;
    Postblur_distortionblur_speed = Postblur_distortionblur_speed * 1.4;
    Postblur_distortionblur_speed = v91 * Postblur_distortionblur_speed;
    v92 = GetEventCamName();
    if (op_Equality(v92, "cam11", 0))
    {
      Postblur_distortionblur_moyaalp = v91 * 0.2;
    }
  }
  if (EventNo == 655 && evtBitCheck(68))
  {
    Postblur_distortionblur_a = Postblur_distortionblur_a * 0.3;
    v98 = (Postblur_distortionblur_a + Postblur_distortionblur_a)
        + (Postblur_distortionblur_a + Postblur_distortionblur_a);
    if (E655_After_CntF < v98)
    {
      E655_After_CntF = E655_After_CntF + 0.01;
      if (E655_After_CntF > v98)
        E655_After_CntF = v98;
    }
    if (E655_After_CntF <= v98)
      v98 = E655_After_CntF;
    E655_After_CntF = v98;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 1.5;
    Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2
                                                         + Postblur_distortionblur_distor2;
    Postblur_distortionblur_speed = 0.8;
    Postblur_distortionblur_moyaalp = v98 * -0.5;
    Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                            * 2.5;
    Postblur_distortionblur_moya_r = 0.6;
    Postblur_distortionblur_moya_g = 1.0;
    Postblur_distortionblur_moya_b = 1.0;
    Postblur_distortionblur_moya_sizemul = 0.7;
    if (E655_After_CntF2 < 0.5)
    {
      E655_After_CntF2 = E655_After_CntF2 + 0.005;
    }
    v106 = E655_After_CntF2;
    Postblur_distortionblur_a = v106;
  }
  if (EventNo == 671)
  {
    Postblur_distortionblur_speed = 1.5;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 1.5;
    Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2
                                                         + Postblur_distortionblur_distor2;
    Postblur_distortionblur_a = Postblur_distortionblur_a * 0.6;
    NowName_SCR_RUN = GetNowName_SCR_RUN();
    if (op_Equality(NowName_SCR_RUN, "e671_030_1", 0))
    {
        goto LABEL_304;
LABEL_313:
      Postblur_distortionblur_moyaalp = Postblur_distortionblur_a * v62;
      goto LABEL_314;
    }
    v112 = op_Equality(evtUpdateEx_FieldName, "f671_030(Clone)", 0);
    if (v112)
    {
      v62 = -0.1;
        goto LABEL_313;
    }
    else
    {
      v62 = -0.45;
        goto LABEL_313;
    }
LABEL_304:
    goto LABEL_313;
  }
LABEL_314:
  else if (EventNo != 674)
  {
    goto LABEL_411;
  }
  if (Postblur_distortionblur_blend != 2)
  {
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.3;
    (*v114)->Postblur_distortionblur_distor2 = (*v114)->Postblur_distortionblur_distor2 * 0.9;
      goto LABEL_412;
    goto LABEL_329;
  }
  v116 = GetEventCamName();
  v117 = op_Equality(v116, "cam25", 0);
  if (v117)
  {
    Postblur_distortionblur_g = Postblur_distortionblur_g * 0.2;
    Postblur_distortionblur_b = Postblur_distortionblur_b * 0.2;
    Postblur_distortionblur_a = Postblur_distortionblur_a * 0.4;
    Postblur_distortionblur_center_x = 0.5;
    Postblur_distortionblur_center_y = 0.5;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.5;
    Postblur_distortionblur_moyaalp = 1.0;
      goto LABEL_412;
    goto LABEL_329;
  }
  Postblur_distortionblur_speed = 1.5;
  Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.5;
  Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 0.5;
  Postblur_distortionblur_a = Postblur_distortionblur_a * 0.2;
  Postblur_distortionblur_moyaalp = 1.0;
  if ((*hDistortionBlur)->param->number > 2)
  {
    E674_aradia_CntF = E674_aradia_CntF + 0.1;
    E674_aradia_CntF2 = E674_aradia_CntF2 + 0.05;
    if ((v120->_2.bitflags2 & 2) == 0)
      goto LABEL_354;
  }
  else
  {
    E674_aradia_CntF = 0.0;
    E674_aradia_CntF2 = 0.0;
    if ((v120->_2.bitflags2 & 2) == 0)
      goto LABEL_354;
  }
LABEL_354:
  v122 = sinf(E674_aradia_CntF);
  *&v123 = sinf(E674_aradia_CntF2) * 0.1;
  number = (*hDistortionBlur)->param->number;
  if (number > 0x13)
  {
    v126 = 0.0;
  }
  else
  {
    v125 = (20 - number);
    v126 = (v125 / 20.0) * 0.5;
  }
  v128 = v122 * 0.15;
  v129 = *&v123 + -0.1;
  Postblur_distortionblur_moya_r = v128 + 0.85;
  Postblur_distortionblur_moya_g = 0.85 - v128;
  Postblur_distortionblur_moya_r = v129 + Postblur_distortionblur_moya_r;
  Postblur_distortionblur_moya_g = v129 + Postblur_distortionblur_moya_g;
  if (Postblur_distortionblur_moya_r < 0.0)
  {
    Postblur_distortionblur_moya_r = 0.0;
  }
  if (Postblur_distortionblur_moya_g < 0.0)
  {
    Postblur_distortionblur_moya_g = 0.0;
  }
  Postblur_distortionblur_moya_b = 1.0;
  Postblur_distortionblur_moya_sizemul = 0.6;
  LODWORD(v123) = (*hDistortionBlur)->param->number;
  v132 = v123;
  Postblur_distortionblur_moya_sizemul = Postblur_distortionblur_moya_sizemul
                                                            + ((v132 / 100.0) * 0.2);
  Postblur_distortionblur_moya_r = v126 + Postblur_distortionblur_moya_r;
  Postblur_distortionblur_moya_g = v126 + Postblur_distortionblur_moya_g;
  Postblur_distortionblur_moya_b = v126 + Postblur_distortionblur_moya_b;
  if (Postblur_distortionblur_moya_r > v29)
  {
    Postblur_distortionblur_moya_r = 1.0;
  }
  if (Postblur_distortionblur_moya_g > v29)
  {
    Postblur_distortionblur_moya_g = 1.0;
  }
  if (Postblur_distortionblur_moya_b > v29)
  {
    Postblur_distortionblur_moya_b = 1.0;
  }
  Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                          * 1.6;
  if ((*hDistortionBlur)->param->number >= 0x5A)
  {
    Postblur_blur_blend = 1;
    Postblur_blur_rotation = 0.0;
    Postblur_blur_scale = 0.95;
    Postblur_blur_r = 1.0;
    Postblur_blur_g = 1.0;
    Postblur_blur_b = 1.0;
    Postblur_blur_a = 0.6;
    Postblur_blur_center_x = 0.5;
    Postblur_blur_center_y = 0.5;
    UpdateFlg_blur = 1;
  }
LABEL_411:
    goto LABEL_412;
LABEL_329:
LABEL_412:
  if (EventNo != 682)
    goto LABEL_417;
LABEL_413:
  Postblur_distortionblur_speed = 1.5;
  Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 1.5;
  Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2
                                                       + Postblur_distortionblur_distor2;
  Postblur_distortionblur_r = Postblur_distortionblur_r * 0.7;
  Postblur_distortionblur_b = Postblur_distortionblur_b * 0.7;
LABEL_417:
  if (EventNo == 693)
  {
    Postblur_distortionblur_speed = Postblur_distortionblur_speed * 0.8;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.4;
    Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 0.6;
    Postblur_distortionblur_a = Postblur_distortionblur_a * 0.8;
    Postblur_distortionblur_moyaalp = -0.1;
  }
  else
  {
    v139 = EventNo;
    if (v139 < 710)
      goto LABEL_468;
  }
  else if (v139 > 722)
  {
    goto LABEL_468;
  }
  AlphaF = dds3FadeGetAlphaF();
  if (AlphaF <= 0.1)
  {
    v144 = 0.0;
  }
  else
  {
    ColAverageF = dds3FadeGetColAverageF();
    if (ColAverageF <= 0.5)
    {
      v143 = -0.4;
    }
    else
    {
      v143 = 0.4;
    }
    v144 = AlphaF * v143;
  }
  (*v145)->Postblur_distortionblur_moyaalp = v144;

  {
    Postblur_distortionblur_a = Postblur_distortionblur_a * 0.9;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.2;
    Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 0.9;
  }
LABEL_468:
    goto LABEL_471;
LABEL_469:
LABEL_471:
  if (EventNo == 718)
  {
    v148 = GetEventCamName();
    if (op_Equality(v148, "01cam_01", 0)
      || op_Equality(v148, "01cam_02", 0)
      || op_Equality(v148, "01cam_03", 0))
    {
      Postblur_distortionblur_speed = Postblur_distortionblur_speed * 1.5;
      Postblur_distortionblur_r = Postblur_distortionblur_r * 0.8;
      Postblur_distortionblur_g = Postblur_distortionblur_g * 0.8;
      Postblur_distortionblur_b = Postblur_distortionblur_b * 0.8;
      v151 = Postblur_distortionblur_a * 0.7;
      v152 = -1098907648;
    }
    else
    {
      if (!op_Equality(v148, "01cam_04", 0)
        && !op_Equality(v148, "01cam_05", 0))
      {
        goto LABEL_483;
      }
      Postblur_distortionblur_speed = Postblur_distortionblur_speed * 1.5;
      Postblur_distortionblur_r = Postblur_distortionblur_r * 0.8;
      Postblur_distortionblur_g = Postblur_distortionblur_g * 0.8;
      Postblur_distortionblur_b = Postblur_distortionblur_b * 0.8;
      v151 = Postblur_distortionblur_a * 0.7;
      v152 = -1102263091;
    }
    Postblur_distortionblur_a = v151;
    Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 1.2;
    Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 1.2;
    LODWORD(Postblur_distortionblur_moyaalp) = v152;
    Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                            * 1.2;
    Postblur_distortionblur_moya_r = 1.0;
    Postblur_distortionblur_moya_g = 1.0;
    Postblur_distortionblur_moya_b = 1.0;
    Postblur_distortionblur_moya_sizemul = 0.7;
  }
LABEL_483:
  if (EventNo == 719)
  {
    v154 = GetEventCamName();
    if (op_Equality(v154, "01cam_04", 0)
      || op_Equality(v154, "01cam_12", 0)
      || op_Equality(v154, "01cam_13", 0)
      || op_Equality(v154, "01cam_14", 0))
    {
      Postblur_distortionblur_a = Postblur_distortionblur_a * 0.7;
    }
  }
  if (EventNo == 908)
  {
    Postblur_distortionblur_r = Postblur_distortionblur_r * 0.75;
    Postblur_distortionblur_g = Postblur_distortionblur_g * 0.75;
    Postblur_distortionblur_b = Postblur_distortionblur_b * 0.75;
  }
LABEL_506:
  if (!evtBitCheck(3714))
    goto LABEL_544;
  abgr = (*hDistortionBlur)->param->abgr;
  if (!(abgr >> 28))
  {
    Majin_CntF = 0.0;
      goto LABEL_533;
    goto LABEL_512;
  }
  if (abgr >> 25 > 0x58)
  {
    Majin_CntF = Majin_CntF + 0.04;
    if (Majin_CntF > v29)
    {
      Majin_CntF = 1.0;
    }
  }
  else
  {
    Majin_CntF = Majin_CntF + -0.03;
    if (Majin_CntF < 0.0)
    {
      Majin_CntF = 0.0;
        goto LABEL_533;
      goto LABEL_512;
    }
  }
  {
LABEL_512:
  }
LABEL_533:
  Postblur_distortionblur_r = 1.0;
  Postblur_distortionblur_g = 0.8;
  Postblur_distortionblur_b = 0.9;
  Postblur_distortionblur_a = Postblur_distortionblur_a * 0.1;
  Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.7;
  Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 0.5;
  Postblur_distortionblur_speed = Postblur_distortionblur_speed * 0.8;
  Postblur_distortionblur_area_x = 1.0;
  Postblur_distortionblur_area_y = 1.0;
  Postblur_distortionblur_moyaalp = Postblur_distortionblur_a / 0.085;
  Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                          * 0.2;
  Postblur_distortionblur_moya_r = 1.0;
  Postblur_distortionblur_moya_g = 0.1;
  Postblur_distortionblur_moya_b = 0.3;
  Postblur_distortionblur_moya_sizemul = 0.7;
  if (Majin_CntF > 0.0)
  {
    Postblur_multiblur_blend = 2;
    Postblur_multiblur_rotation = 0.001;
    Postblur_multiblur_scale = 0.97;
    Postblur_multiblur_r = 1.0;
    Postblur_multiblur_g = 0.8;
    Postblur_multiblur_b = 0.9;
    Postblur_multiblur_a = Majin_CntF * 0.5;
    Postblur_multiblur_area = 3.0;
    Postblur_multiblur_center_x = 0.5;
    Postblur_multiblur_center_y = 0.5;
    UpdateFlg_multiblur = 1;
  }
LABEL_544:
  fieldID = fldGb->fieldID;
  if (fieldID >= 200)
  {
    if (fieldID <= 499)
    {
      if (fieldID == 215)
      {
        if (fldGb->areaID == 3)
        {
          if (ChkNbEventRun())
          {
            Postblur_distortionblur_a = Postblur_distortionblur_a * 0.6;
          }
        }
      }
      v171 = fldGb;
      if (v171->fieldID == 244)
      {
        if (v171->areaID == 2)
        {
          if (ChkNbEventRun())
          {
            Postblur_distortionblur_a = Postblur_distortionblur_a * 0.4;
            Postblur_distortionblur_moyaalp = -0.2;
            Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                                    * 1.2;
            Postblur_distortionblur_moya_r = 1.0;
            Postblur_distortionblur_moya_g = 1.0;
            Postblur_distortionblur_moya_b = 1.0;
            Postblur_distortionblur_moya_sizemul = 0.65;
          }
        }
      }
      v174 = fldGb;
      if (v174->fieldID == 245)
      {
        if (v174->areaID == 2)
        {
          if (ChkNbEventRun())
          {
            Postblur_distortionblur_a = Postblur_distortionblur_a * 0.2;
            Postblur_distortionblur_moyaalp = Postblur_distortionblur_a
                                                                 + Postblur_distortionblur_a;
          }
        }
      }
    }
  }
  if (FldEve_UnityEx_ID)
  {
    else if (FldEve_UnityEx_ID == 57700353)
    {
LABEL_607:
      Postblur_distortionblur_speed = 1.3;
      Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.5;
      Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 1.2;
      Postblur_distortionblur_g = Postblur_distortionblur_g * 0.3;
      Postblur_distortionblur_b = Postblur_distortionblur_b * 0.3;
      v181 = Postblur_distortionblur_a * 1.6667;
      Postblur_distortionblur_moyaalp = v181;
      Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                              * 2.5;
      Postblur_distortionblur_area_x = Postblur_distortionblur_area_x * 0.2;
      Postblur_distortionblur_area_y = Postblur_distortionblur_area_y * 1.1;
      Postblur_multifilter_blend = 1;
      Postblur_multifilter_r = 1.0;
      Postblur_multifilter_g = 0.0;
      Postblur_multifilter_b = 0.0;
      Postblur_multifilter_a = v181 * 0.5;
      Postblur_multifilter_area = (v181 * 0.2) + 0.1;
      Postblur_multifilter_center_x = 0.478;
      Postblur_multifilter_center_y = 0.432;
      UpdateFlg_multifilter = 1;
        goto LABEL_677;
      goto LABEL_614;
    }
    else if (FldEve_UnityEx_ID == 57700354)
    {
LABEL_620:
      Postblur_distortionblur_speed = 1.3;
      Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.5;
      Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 1.2;
      Postblur_distortionblur_g = Postblur_distortionblur_g * 0.5;
      Postblur_distortionblur_b = Postblur_distortionblur_b * 0.5;
      Postblur_distortionblur_moyaalp = (Postblur_distortionblur_a * 1.6667)
                                                           * 0.2;
      Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                              * 1.5;
      Postblur_distortionblur_area_y = 1.0;
      Postblur_distortionblur_area_x = 1.0;
      Postblur_distortionblur_a = Postblur_distortionblur_a * 0.5;
        goto LABEL_677;
      goto LABEL_614;
    }
    if (FldEve_UnityEx_ID == 67137539)
    {
      Postblur_distortionblur_speed = 1.3;
      Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1 * 0.1;
      Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2 * 0.5;
      v186 = sinf(FldEve_UnityEx_CntF * 0.1);
      v188 = fmaxf(v186, 0.0);
      Postblur_multifilter_blend = 2;
      Postblur_multifilter_r = 1.0;
      Postblur_multifilter_g = 0.7;
      Postblur_multifilter_b = 0.4;
      Postblur_multifilter_a = v188 * 0.5;
      Postblur_multifilter_area = (v188 * 1.4) + 0.4;
      Postblur_multifilter_center_x = 0.51;
      Postblur_multifilter_center_y = 0.53;
        goto LABEL_674;
      goto LABEL_643;
    }
    if (FldEve_UnityEx_ID == 67137540)
    {
      Postblur_distortionblur_blend = 6;
      Postblur_distortionblur_distor1 = 0.0;
      Postblur_distortionblur_area_y = 0.9;
      Postblur_distortionblur_area_x = 0.9;
      Postblur_distortionblur_moyaalp = 1.0;
      Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                              * 1.1;
        goto LABEL_677;
      goto LABEL_614;
    }
    if (FldEve_UnityEx_ID == 67137542)
    {
      Postblur_distortionblur_speed = Postblur_distortionblur_speed * 1.5;
      Postblur_distortionblur_distor1 = 0.0;
      Postblur_distortionblur_distor2 = Postblur_distortionblur_distor2
                                                           + Postblur_distortionblur_distor2;
      Postblur_distortionblur_a = Postblur_distortionblur_a * 1.2;
      v191 = fmaxf(30.0 - FldEve_UnityEx_CntF, 0.0);
      v193 = sinf(v191 * 0.07);
      v195 = v193;
      v196 = sinf(FldEve_UnityEx_CntF * 0.1);
      v198 = fmaxf(v196, 0.0);
      Postblur_multifilter_blend = 2;
      Postblur_multifilter_r = 1.0;
      Postblur_multifilter_g = 0.7;
      Postblur_multifilter_b = 0.4;
      Postblur_multifilter_a = v198 * 0.4;
      Postblur_multifilter_area = (v195 + v195) + 0.4;
      Postblur_multifilter_center_x = 0.5;
      Postblur_multifilter_center_y = 0.72;
        goto LABEL_674;
LABEL_643:
LABEL_674:
      UpdateFlg_multifilter = 1;
LABEL_675:
      FldEve_UnityEx_CntF = FldEve_UnityEx_CntF + v29;
LABEL_676:
      {
LABEL_677:
        FldEve_UnityEx_ID = 0;
        goto LABEL_678;
      }
LABEL_614:
      goto LABEL_677;
    }
    v201 = *&v176->_2.bitflags1;
    if ((v201 & 0x200) != 0)
    {
      v202 = v201 & 0x200;
      if (FldEve_UnityEx_ID == 67137543)
        goto LABEL_695;
    }
    else
    {
      v202 = 0;
      if (FldEve_UnityEx_ID == 67137543)
      {
LABEL_695:
        v203 = FldEve_UnityEx_CntF;
        v205 = fminf(v203 * 0.033333, v29);
        Postblur_distortionblur_a = v205 * Postblur_distortionblur_a;
        v206 = FldEve_UnityEx_CntF;
        if (v206 > 10.0)
        {
          v208 = fminf((v206 + -10.0) * 0.025, v29);
          Postblur_distortionblur_moyaalp = v208 * 0.5;
          Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                                  * 1.5;
        }
        goto LABEL_675;
      }
    }
    if (FldEve_UnityEx_ID != 38817800)
    {
      if (FldEve_UnityEx_ID == 38821889)
      {
        Postblur_distortionblur_moyaalp = -0.2;
          goto LABEL_677;
        goto LABEL_614;
      }
      if (FldEve_UnityEx_ID == 72519689)
      {
        FldEve_UnityEx_CntF = FldEve_UnityEx_CntF + v29;
        Postblur_distortionblur_a = Postblur_distortionblur_a * 1.5;
        Postblur_distortionblur_speed = Postblur_distortionblur_speed * 0.2;
        Postblur_distortionblur_distor1 = Postblur_distortionblur_distor1
                                                             * 0.3;
        Postblur_distortionblur_moyaalp = 0.4;
        Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                                * 0.8;
        Postblur_distortionblur_moya_r = 0.3;
        Postblur_distortionblur_moya_g = 0.0;
        Postblur_distortionblur_moya_b = 1.0;
        Postblur_distortionblur_moya_sizemul = 0.6;
          goto LABEL_677;
        goto LABEL_614;
      }
      goto LABEL_676;
    }
    FldEve_UnityEx_CntF = FldEve_UnityEx_CntF + v29;
    LODWORD(v159) = (*hDistortionBlur)->param->number;
    v210 = v159;
    *&v210 = v210;
    v211 = *&v210 / 60.0;
    Postblur_distortionblur_r = ((v211 * -0.1) + v29)
                                                   * Postblur_distortionblur_r;
    Postblur_distortionblur_g = (v29 - (v211 * 0.2))
                                                   * Postblur_distortionblur_g;
    Postblur_distortionblur_a = ((v211 * 0.3) + v29)
                                                   * Postblur_distortionblur_a;
    Postblur_distortionblur_speed = Postblur_distortionblur_speed * 0.7;
    Postblur_distortionblur_distor1 = ((v211 * 0.5) + 0.7)
                                                         * Postblur_distortionblur_distor1;
    Postblur_distortionblur_distor2 = ((v211 * 0.5) + 0.5)
                                                         * Postblur_distortionblur_distor2;
    Postblur_distortionblur_area_x = Postblur_distortionblur_area_x * 0.5;
    LODWORD(v210) = (*hDistortionBlur)->param->number;
    v212 = *&v210;
    Postblur_distortionblur_moyaalp = (v212 / 60.0) * 0.2;
    Postblur_distortionblur_moyarotspd = Postblur_distortionblur_moyarotspd
                                                            * 1.3;
    Postblur_multiblur_blend = 1;
    Postblur_multiblur_rotation = -0.001;
    Postblur_multiblur_scale = 0.975;
    Postblur_multiblur_r = 0.8;
    Postblur_multiblur_g = 0.1;
    Postblur_multiblur_b = 0.4;
    Postblur_multiblur_a = 0.0;
    Postblur_multiblur_area = 3.0;
    Postblur_multiblur_center_x = 0.5;
    Postblur_multiblur_center_y = 0.5;
    v213 = (*hDistortionBlur)->param->number;
    if (v213 == 11)
    {
      Postblur_multiblur_a = 0.1;
      v213 = (*hDistortionBlur)->param->number;
      if (v213 != 12)
      {
LABEL_733:
        if (v213 == 13)
          goto LABEL_734;
        goto LABEL_864;
      }
    }
    else if (v213 != 12)
    {
      goto LABEL_733;
    }
    Postblur_multiblur_a = 0.2;
    v213 = (*hDistortionBlur)->param->number;
    if (v213 == 13)
    {
LABEL_734:
      Postblur_multiblur_a = 0.3;
      v213 = (*hDistortionBlur)->param->number;
      if (v213 != 14)
      {
LABEL_738:
        if (v213 == 15)
          goto LABEL_739;
        goto LABEL_869;
      }
LABEL_865:
      Postblur_multiblur_a = 0.4;
      v213 = (*hDistortionBlur)->param->number;
      if (v213 == 15)
      {
LABEL_739:
        Postblur_multiblur_a = 0.5;
        v213 = (*hDistortionBlur)->param->number;
        if (v213 != 16)
        {
LABEL_743:
          if (v213 == 17)
            goto LABEL_744;
          goto LABEL_874;
        }
LABEL_870:
        Postblur_multiblur_a = 0.6;
        v213 = (*hDistortionBlur)->param->number;
        if (v213 == 17)
        {
LABEL_744:
          Postblur_multiblur_a = 0.6;
          v213 = (*hDistortionBlur)->param->number;
          if (v213 != 18)
          {
LABEL_748:
            if (v213 == 19)
              goto LABEL_749;
            goto LABEL_879;
          }
LABEL_875:
          Postblur_multiblur_a = 0.6;
          v213 = (*hDistortionBlur)->param->number;
          if (v213 == 19)
          {
LABEL_749:
            Postblur_multiblur_a = 0.6;
            v213 = (*hDistortionBlur)->param->number;
            if (v213 != 20)
            {
LABEL_753:
              if (v213 == 21)
                goto LABEL_754;
              goto LABEL_884;
            }
LABEL_880:
            Postblur_multiblur_a = 0.5;
            v213 = (*hDistortionBlur)->param->number;
            if (v213 == 21)
            {
LABEL_754:
              Postblur_multiblur_a = 0.5;
              v213 = (*hDistortionBlur)->param->number;
              if (v213 != 22)
              {
LABEL_758:
                if (v213 == 23)
                  goto LABEL_759;
                goto LABEL_889;
              }
LABEL_885:
              Postblur_multiblur_a = 0.5;
              v213 = (*hDistortionBlur)->param->number;
              if (v213 == 23)
              {
LABEL_759:
                Postblur_multiblur_a = 0.4;
                v213 = (*hDistortionBlur)->param->number;
                if (v213 != 24)
                {
LABEL_763:
                  if (v213 == 25)
                    goto LABEL_764;
                  goto LABEL_894;
                }
LABEL_890:
                Postblur_multiblur_a = 0.4;
                v213 = (*hDistortionBlur)->param->number;
                if (v213 == 25)
                {
LABEL_764:
                  Postblur_multiblur_a = 0.4;
                  v213 = (*hDistortionBlur)->param->number;
                  if (v213 != 26)
                  {
LABEL_768:
                    if (v213 == 27)
                      goto LABEL_769;
                    goto LABEL_899;
                  }
LABEL_895:
                  Postblur_multiblur_a = 0.3;
                  v213 = (*hDistortionBlur)->param->number;
                  if (v213 == 27)
                  {
LABEL_769:
                    Postblur_multiblur_a = 0.3;
                    v213 = (*hDistortionBlur)->param->number;
                    if (v213 != 28)
                    {
LABEL_773:
                      if (v213 == 29)
                        goto LABEL_774;
                      goto LABEL_904;
                    }
LABEL_900:
                    Postblur_multiblur_a = 0.2;
                    v213 = (*hDistortionBlur)->param->number;
                    if (v213 == 29)
                    {
LABEL_774:
                      {
                      }
                      Postblur_multiblur_a = 0.1;
                      v213 = (*hDistortionBlur)->param->number;
                      if (v213 != 31)
                      {
LABEL_778:
                        if (v213 == 32)
                          goto LABEL_779;
                        goto LABEL_909;
                      }
LABEL_905:
                      {
                      }
                      Postblur_multiblur_a = 0.1;
                      v213 = (*hDistortionBlur)->param->number;
                      if (v213 == 32)
                      {
LABEL_779:
                        {
                        }
                        Postblur_multiblur_a = 0.2;
                        v213 = (*hDistortionBlur)->param->number;
                        if (v213 != 33)
                        {
LABEL_783:
                          if (v213 == 34)
                            goto LABEL_784;
                          goto LABEL_914;
                        }
LABEL_910:
                        {
                        }
                        Postblur_multiblur_a = 0.3;
                        v213 = (*hDistortionBlur)->param->number;
                        if (v213 == 34)
                        {
LABEL_784:
                          {
                          }
                          Postblur_multiblur_a = 0.4;
                          v213 = (*hDistortionBlur)->param->number;
                          if (v213 != 35)
                          {
LABEL_788:
                            if (v213 == 36)
                              goto LABEL_789;
                            goto LABEL_919;
                          }
LABEL_915:
                          {
                          }
                          Postblur_multiblur_a = 0.5;
                          v213 = (*hDistortionBlur)->param->number;
                          if (v213 == 36)
                          {
LABEL_789:
                            {
                            }
                            Postblur_multiblur_a = 0.6;
                            v213 = (*hDistortionBlur)->param->number;
                            if (v213 != 37)
                            {
LABEL_793:
                              if (v213 == 38)
                                goto LABEL_794;
                              goto LABEL_924;
                            }
LABEL_920:
                            {
                            }
                            Postblur_multiblur_a = 0.6;
                            v213 = (*hDistortionBlur)->param->number;
                            if (v213 == 38)
                            {
LABEL_794:
                              {
                              }
                              Postblur_multiblur_a = 0.6;
                              v213 = (*hDistortionBlur)->param->number;
                              if (v213 != 39)
                              {
LABEL_798:
                                if (v213 == 40)
                                  goto LABEL_799;
                                goto LABEL_929;
                              }
LABEL_925:
                              {
                              }
                              Postblur_multiblur_a = 0.6;
                              v213 = (*hDistortionBlur)->param->number;
                              if (v213 == 40)
                              {
LABEL_799:
                                {
                                }
                                Postblur_multiblur_a = 0.5;
                                v213 = (*hDistortionBlur)->param->number;
                                if (v213 != 41)
                                {
LABEL_803:
                                  if (v213 == 42)
                                    goto LABEL_804;
                                  goto LABEL_934;
                                }
LABEL_930:
                                {
                                }
                                Postblur_multiblur_a = 0.5;
                                v213 = (*hDistortionBlur)->param->number;
                                if (v213 == 42)
                                {
LABEL_804:
                                  {
                                  }
                                  Postblur_multiblur_a = 0.5;
                                  v213 = (*hDistortionBlur)->param->number;
                                  if (v213 != 43)
                                  {
LABEL_808:
                                    if (v213 == 44)
                                      goto LABEL_809;
                                    goto LABEL_939;
                                  }
LABEL_935:
                                  {
                                  }
                                  Postblur_multiblur_a = 0.4;
                                  v213 = (*hDistortionBlur)->param->number;
                                  if (v213 == 44)
                                  {
LABEL_809:
                                    {
                                    }
                                    Postblur_multiblur_a = 0.4;
                                    v213 = (*hDistortionBlur)->param->number;
                                    if (v213 != 45)
                                    {
LABEL_813:
                                      if (v213 == 46)
                                        goto LABEL_814;
                                      goto LABEL_944;
                                    }
LABEL_940:
                                    {
                                    }
                                    Postblur_multiblur_a = 0.4;
                                    v213 = (*hDistortionBlur)->param->number;
                                    if (v213 == 46)
                                    {
LABEL_814:
                                      {
                                      }
                                      Postblur_multiblur_a = 0.3;
                                      v213 = (*hDistortionBlur)->param->number;
                                      if (v213 != 47)
                                      {
LABEL_818:
                                        if (v213 == 48)
                                          goto LABEL_819;
                                        goto LABEL_949;
                                      }
LABEL_945:
                                      {
                                      }
                                      Postblur_multiblur_a = 0.3;
                                      v213 = (*hDistortionBlur)->param->number;
                                      if (v213 == 48)
                                      {
LABEL_819:
                                        {
                                        }
                                        Postblur_multiblur_a = 0.2;
                                        v213 = (*hDistortionBlur)->param->number;
                                        if (v213 != 49)
                                        {
LABEL_823:
                                          if (v213 == 50)
                                            goto LABEL_824;
                                          goto LABEL_954;
                                        }
LABEL_950:
                                        {
                                        }
                                        Postblur_multiblur_a = 0.1;
                                        v213 = (*hDistortionBlur)->param->number;
                                        if (v213 == 50)
                                        {
LABEL_824:
                                          {
                                          }
                                          Postblur_multiblur_a = 0.1;
                                          v213 = (*hDistortionBlur)->param->number;
                                          if (v213 != 51)
                                          {
LABEL_828:
                                            if (v213 == 52)
                                              goto LABEL_829;
                                            goto LABEL_959;
                                          }
LABEL_955:
                                          {
                                          }
                                          Postblur_multiblur_a = 0.1;
                                          v213 = (*hDistortionBlur)->param->number;
                                          if (v213 == 52)
                                          {
LABEL_829:
                                            {
                                            }
                                            Postblur_multiblur_a = 0.2;
                                            v213 = (*hDistortionBlur)->param->number;
                                            if (v213 != 53)
                                            {
LABEL_833:
                                              if (v213 == 54)
                                                goto LABEL_834;
                                              goto LABEL_964;
                                            }
LABEL_960:
                                            {
                                            }
                                            Postblur_multiblur_a = 0.2;
                                            v213 = (*hDistortionBlur)->param->number;
                                            if (v213 == 54)
                                            {
LABEL_834:
                                              {
                                              }
                                              Postblur_multiblur_a = 0.3;
                                              v213 = (*hDistortionBlur)->param->number;
                                              if (v213 != 55)
                                              {
LABEL_838:
                                                if (v213 == 56)
                                                  goto LABEL_839;
                                                goto LABEL_969;
                                              }
LABEL_965:
                                              {
                                              }
                                              Postblur_multiblur_a = 0.3;
                                              v213 = (*hDistortionBlur)->param->number;
                                              if (v213 == 56)
                                              {
LABEL_839:
                                                {
                                                }
                                                Postblur_multiblur_a = 0.4;
                                                v213 = (*hDistortionBlur)->param->number;
                                                if (v213 != 57)
                                                {
LABEL_843:
                                                  if (v213 >= 0x3A)
                                                    goto LABEL_844;
                                                  goto LABEL_974;
                                                }
LABEL_970:
                                                {
                                                }
                                                Postblur_multiblur_a = 0.4;
                                                v213 = (*hDistortionBlur)->param->number;
                                                if (v213 >= 0x3A)
                                                {
LABEL_844:
                                                  {
                                                  }
                                                  Postblur_multiblur_a = 0.5;
                                                  if ((*hDistortionBlur)->param->number < 0x32)
                                                  {
LABEL_848:
                                                      goto LABEL_981;
                                                    goto LABEL_979;
                                                  }
LABEL_975:
                                                  {
                                                  }
                                                  Postblur_multiblur_rotation = -0.001;
                                                  Postblur_multiblur_scale = 1.05;
                                                  Postblur_multiblur_r = 1.0;
                                                  Postblur_multiblur_g = 1.0;
                                                  Postblur_multiblur_b = 1.0;
                                                  Postblur_multiblur_area = 0.4;
                                                  {
LABEL_981:
                                                    UpdateFlg_multiblur = 1;
                                                      goto LABEL_677;
                                                    goto LABEL_614;
                                                  }
LABEL_979:
                                                  goto LABEL_981;
                                                }
LABEL_974:
                                                if (v213 < 0x32)
                                                  goto LABEL_848;
                                                goto LABEL_975;
                                              }
LABEL_969:
                                              if (v213 != 57)
                                                goto LABEL_843;
                                              goto LABEL_970;
                                            }
LABEL_964:
                                            if (v213 != 55)
                                              goto LABEL_838;
                                            goto LABEL_965;
                                          }
LABEL_959:
                                          if (v213 != 53)
                                            goto LABEL_833;
                                          goto LABEL_960;
                                        }
LABEL_954:
                                        if (v213 != 51)
                                          goto LABEL_828;
                                        goto LABEL_955;
                                      }
LABEL_949:
                                      if (v213 != 49)
                                        goto LABEL_823;
                                      goto LABEL_950;
                                    }
LABEL_944:
                                    if (v213 != 47)
                                      goto LABEL_818;
                                    goto LABEL_945;
                                  }
LABEL_939:
                                  if (v213 != 45)
                                    goto LABEL_813;
                                  goto LABEL_940;
                                }
LABEL_934:
                                if (v213 != 43)
                                  goto LABEL_808;
                                goto LABEL_935;
                              }
LABEL_929:
                              if (v213 != 41)
                                goto LABEL_803;
                              goto LABEL_930;
                            }
LABEL_924:
                            if (v213 != 39)
                              goto LABEL_798;
                            goto LABEL_925;
                          }
LABEL_919:
                          if (v213 != 37)
                            goto LABEL_793;
                          goto LABEL_920;
                        }
LABEL_914:
                        if (v213 != 35)
                          goto LABEL_788;
                        goto LABEL_915;
                      }
LABEL_909:
                      if (v213 != 33)
                        goto LABEL_783;
                      goto LABEL_910;
                    }
LABEL_904:
                    if (v213 != 31)
                      goto LABEL_778;
                    goto LABEL_905;
                  }
LABEL_899:
                  if (v213 != 28)
                    goto LABEL_773;
                  goto LABEL_900;
                }
LABEL_894:
                if (v213 != 26)
                  goto LABEL_768;
                goto LABEL_895;
              }
LABEL_889:
              if (v213 != 24)
                goto LABEL_763;
              goto LABEL_890;
            }
LABEL_884:
            if (v213 != 22)
              goto LABEL_758;
            goto LABEL_885;
          }
LABEL_879:
          if (v213 != 20)
            goto LABEL_753;
          goto LABEL_880;
        }
LABEL_874:
        if (v213 != 18)
          goto LABEL_748;
        goto LABEL_875;
      }
LABEL_869:
      if (v213 != 16)
        goto LABEL_743;
      goto LABEL_870;
    }
LABEL_864:
    if (v213 != 14)
      goto LABEL_738;
    goto LABEL_865;
  }
LABEL_678:
  switch (SkillID)
  {
    case 196:
    case 197:
    case 198:
    case 199:
    case 209:
    case 214:
      Postblur_distortionblur_area_x = 0.0;
      Postblur_distortionblur_area_y = 0.0;
      Postblur_distortionblur_a = 1.0;
      break;
    default:
      break;
  }
  UpdateFlg_distortionblur = 1;
}

// 0x1383dd0
void dds3EffectDistortionBlurSetParam(effDistortionBlurHandle_t **hDistortionBlur, dds3Effect_DistortionBlurParam_t *pParam) {
  u32 number;

  number = (*hDistortionBlur)->param->number;
  (*hDistortionBlur)->param = pParam;
  (*hDistortionBlur)->param->number = number;
}

// 0x1383bf0
void dds3EffectDistortionBlur_SetArea(f32 area_x, f32 area_y) {
  Postblur_distortionblur_area_x = area_x;
  Postblur_distortionblur_area_y = area_y;
}

// 0x1383c70
void dds3EffectDistortionBlur_SetFldEvent(s32 feve_UnityEx_id) {
  FldEve_UnityEx_ID = feve_UnityEx_id;
}

// 0x1383ce0
void dds3EffectDistortionBlur_SetFldEventCntF(f32 feve_UnityEx_cntF) {
  FldEve_UnityEx_CntF = feve_UnityEx_cntF;
}

// 0x1383b70
void dds3EffectDistortionBlur_SetMoya(f32 moyaalp) {
  Postblur_distortionblur_moyaalp = moyaalp;
}

// 0x1386300
void dds3EffectEncountBlur(void) {
  dds3KernelDraw_c *v2;

  Postblur_blur_rotation = 0.0002;
  Postblur_blur_scale = 0.99;
  Postblur_blur_blend = 1;
  Postblur_blur_r = 1.0;
  Postblur_blur_g = 1.0;
  Postblur_blur_b = 1.0;
  Postblur_blur_a = 0.05;
  UpdateFlg_blur = 1;
  if (Postblur_encountblur_blend)
  {
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_17;
    goto LABEL_11;
  }
  Postblur_Encount1st = 1;
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_11:
  }
LABEL_17:
  Postblur_encountblur_blend = 1;
}

// 0x1386460
void dds3EffectEncountBlur1(f32 scale, f32 area) {
  Postblur_multiblur_blend = 2;
  Postblur_multiblur_rotation = 0.01;
  Postblur_multiblur_scale = 1.02;
  Postblur_multiblur_r = 1.0;
  Postblur_multiblur_g = 1.0;
  Postblur_multiblur_b = 1.0;
  Postblur_multiblur_a = 0.0078125;
  Postblur_multiblur_area = 300.0;
  Postblur_multiblur_center_x = 0.5;
  Postblur_multiblur_center_y = 0.5;
  UpdateFlg_multiblur = 1;
}

// 0x1386570
void dds3EffectEncountBlur2(void) {
  Postblur_filter_blend = 1;
  Postblur_filter_r = 0.0;
  Postblur_filter_g = 0.0;
  Postblur_filter_b = 0.0;
  Postblur_filter_a = 0.015625;
  UpdateFlg_filter = 1;
}

// 0x1386630
void dds3EffectEncountBlur3(s32 alp) {
  s32 v5;

  Postblur_blur_rotation = 0.0002;
  Postblur_blur_scale = 0.99;
  Postblur_blur_blend = 1;
  Postblur_blur_r = 1.0;
  Postblur_blur_g = 1.0;
  Postblur_blur_b = 1.0;
  Postblur_blur_a = alp * 0.0078125;
  UpdateFlg_blur = 1;
  if (alp < 113)
  {
    v5 = 0;
  }
  {
    v5 = 1;
  }
  else
  {
    v5 = 1;
  }
  Postblur_encountblur_blend = v5;
}

// 0x1384ce0
void dds3EffectFilter(dds3Effect_Filter_t **pFilter, s32 SkillID) {
  s32 v6;
  u32 abgr_low;
  f64 v8;
  f64 v9;
  u32 abgr;
  f32 v12;
  f32 v13;
  f32 v14;
  u32 v17;
  f32 v19;
  dds3KernelDraw_c *v20;
  f32 Postblur_filter_r;
  f32 Postblur_filter_b;
  f32 v24;
  effBlur_Filter_c *v27;
  System_String_o *EventCamName;
  struct dds3KernelDraw_StaticFields **p_static_fields;
  System_String_o *v42;
  System_String_o *v46;
  struct dds3KernelDraw_StaticFields **v49;
  f32 Postblur_blur_a;
  struct dds3KernelDraw_StaticFields **v60;
  f32 v62;
  f32 v63;

  switch ((*pFilter)->blend)
  {
    case 1:
    case 0x44:
      v6 = 1;
      break;
    case 3:
    case 0x42:
      v6 = 3;
      break;
    case 4:
    case 6:
      v6 = 4;
      break;
    default:
      v6 = 2;
      break;
  }
  Postblur_filter_blend = v6;
  abgr_low = LOBYTE((*pFilter)->abgr);
  v8 = abgr_low;
  *&v8 = abgr_low;
  *&v8 = *&v8 * 0.0078125;
  Postblur_filter_r = *&v8;
  LOBYTE(v8) = BYTE1((*pFilter)->abgr);
  v9 = *&v8;
  *&v9 = v9;
  Postblur_filter_g = *&v9 * 0.0078125;
  LOBYTE(v9) = BYTE2((*pFilter)->abgr);
  *&v9 = *&v9;
  Postblur_filter_b = *&v9 * 0.0078125;
  abgr = (*pFilter)->abgr;
  if (Postblur_filter_blend == 2)
  {
    v12 = HIBYTE(abgr);
    v13 = v12 / 255.0;
  }
  else
  {
    v14 = HIBYTE(abgr);
    v13 = v14 * 0.0078125;
  }
  Postblur_filter_a = v13;
  if (EventMode)
  {
    else if (EventNo != 614)
    {
      goto LABEL_43;
    }
    v17 = (*pFilter)->abgr;
    v19 = HIBYTE(v17);
    Postblur_filter_a = v19 / 255.0;
  }
LABEL_43:
  if (Postblur_filter_r >= Postblur_filter_g)
  {
LABEL_49:
    if ((v20->_2.bitflags2 & 2) == 0)
      goto LABEL_51;
    goto LABEL_50;
  }
  if ((v20->_2.bitflags2 & 2) == 0)
  {
    Postblur_filter_r = Postblur_filter_g;
    goto LABEL_49;
  }
  else
  {
    Postblur_filter_r = Postblur_filter_g;
      goto LABEL_51;
  }
LABEL_50:
LABEL_51:
  if (Postblur_filter_r >= Postblur_filter_b)
    goto LABEL_67;
LABEL_52:
  Postblur_filter_r = Postblur_filter_b;
  v24 = 1.0;
  if (Postblur_filter_b <= 1.0)
    goto LABEL_55;
LABEL_68:
  Postblur_filter_r = Postblur_filter_r / Postblur_filter_r;
  Postblur_filter_g = Postblur_filter_g / Postblur_filter_r;
  Postblur_filter_b = Postblur_filter_b / Postblur_filter_r;
  if ((v20->_2.bitflags2 & 2) == 0)
  {
LABEL_72:
    if (Postblur_filter_blend == 3)
      goto LABEL_58;
LABEL_73:
    if ((v20->_2.bitflags2 & 2) == 0)
      goto LABEL_75;
    goto LABEL_74;
  }
LABEL_56:
    goto LABEL_72;
  if (Postblur_filter_blend != 3)
    goto LABEL_73;
LABEL_58:
  Postblur_filter_a = Postblur_filter_a * 0.5;
  if ((v20->_2.bitflags2 & 2) == 0)
  {
LABEL_75:
    if (Postblur_filter_a < v24)
      goto LABEL_76;
    goto LABEL_146;
  }
LABEL_74:
    goto LABEL_75;
  if (Postblur_filter_a < v24)
  {
LABEL_76:
    if (SkillID == 263)
      goto LABEL_77;
    goto LABEL_150;
  }
LABEL_146:
  Postblur_filter_a = 1.0;
  if (SkillID == 263)
  {
LABEL_77:
    Postblur_filter_a = Postblur_filter_a * 0.5;
      goto LABEL_151;
    goto LABEL_81;
  }
LABEL_150:
    goto LABEL_151;
LABEL_81:
LABEL_151:
  if (!EventMode)
  {
LABEL_250:
    if ((v27->_2.bitflags2 & 2) == 0)
      goto LABEL_253;
    goto LABEL_251;
  }
LABEL_83:
  else if (EventNo != 621)
  {
    goto LABEL_90;
  }
  Postblur_filter_a = Postblur_filter_a * 0.6;
LABEL_90:
  else if (EventNo != 634)
  {
    goto LABEL_171;
  }
  EventCamName = GetEventCamName();
  if (!op_Equality(EventCamName, "cam11", 0))
    goto LABEL_171;
  if (!op_Equality(evtUpdateEx_FieldName, "f634_050(Clone)", 0))
  {
LABEL_171:
      goto LABEL_105;
LABEL_172:
    if (EventNo != 628)
      goto LABEL_173;
    goto LABEL_107;
  }
  Postblur_filter_a = Postblur_filter_a * 1.2;
    goto LABEL_172;
LABEL_105:
    goto LABEL_172;
  if (EventNo != 628)
    goto LABEL_173;
LABEL_107:
  if (Postblur_filter_blend == 3)
  {
    Postblur_filter_a = Postblur_filter_a * 0.3;
  }
  if (Postblur_blur_a < 0.1)
  {
    Postblur_filter_a = 0.0;
      goto LABEL_174;
    goto LABEL_123;
  }
LABEL_173:
    goto LABEL_174;
LABEL_123:
LABEL_174:
  if (EventNo != 661)
    goto LABEL_175;
LABEL_125:
  if (Postblur_filter_blend == 4)
  {
    Postblur_filter_r = 0.75;
    (*p_static_fields)->Postblur_filter_g = 0.8;
    (*p_static_fields)->Postblur_filter_b = 1.0;
    if (op_Equality(evtUpdateEx_FieldName, "f661_010(Clone)", 0))
    {
      v42 = GetEventCamName();
      if (op_Equality(v42, "cam06", 0))
      {
        Postblur_filter_r = 1.0;
        Postblur_filter_g = 1.0;
        Postblur_filter_b = 0.5;
          goto LABEL_177;
        goto LABEL_176;
      }
    }
LABEL_175:
      goto LABEL_177;
    goto LABEL_176;
  }
  if (!op_Equality(evtUpdateEx_FieldName, "f661_010(Clone)", 0))
    goto LABEL_175;
  v46 = GetEventCamName();
  if (!op_Equality(v46, "cam06", 0))
    goto LABEL_175;
  Postblur_filter_r = Postblur_filter_r * 1.3;
  Postblur_filter_g = Postblur_filter_g * 0.5;
  Postblur_filter_b = Postblur_filter_b * 0.5;
  {
LABEL_177:
    if (EventNo != 671)
      goto LABEL_190;
    goto LABEL_178;
  }
LABEL_176:
    goto LABEL_177;
  if (EventNo != 671)
    goto LABEL_190;
LABEL_178:
  Postblur_filter_a = Postblur_filter_a * 0.6;
  if (Postblur_blur_blend != 1)
  {
LABEL_190:
      goto LABEL_186;
LABEL_191:
    if (EventNo != 693)
      goto LABEL_210;
    goto LABEL_192;
  }
  Postblur_filter_r = Postblur_filter_r + (Postblur_blur_a * (v24 - Postblur_filter_r));
  (*v49)->Postblur_filter_g = (*v49)->Postblur_filter_g * (v24 - (*v49)->Postblur_blur_a);
  (*v49)->Postblur_filter_b = (*v49)->Postblur_filter_b * (v24 - (*v49)->Postblur_blur_a);
  (*v49)->Postblur_filter_a = (*v49)->Postblur_filter_a + (Postblur_blur_a * (v24 - (*v49)->Postblur_filter_a));
    goto LABEL_191;
LABEL_186:
    goto LABEL_191;
  if (EventNo != 693)
    goto LABEL_210;
LABEL_192:
  if (!op_Equality(evtUpdateEx_FieldName, "f693_020(Clone)", 0))
  {
LABEL_210:
      goto LABEL_211;
    goto LABEL_200;
  }
  Postblur_filter_r = 0.4;
  Postblur_filter_g = 0.36;
  Postblur_filter_b = 0.4;
  Postblur_filter_a = 0.5;
  {
LABEL_211:
    if (EventNo == 705)
      goto LABEL_212;
    goto LABEL_202;
  }
LABEL_200:
    goto LABEL_211;
  if (EventNo == 705)
  {
LABEL_212:
    if (fldGb->areaID == 4)
    {
      Postblur_filter_blend = 1;
      v62 = 0.8;
      v63 = 0.8;
    }
    else
    {
      Postblur_filter_blend = 1;
      if (Postblur_filter_r > v24)
      {
        Postblur_filter_r = 1.0;
      }
      if (Postblur_filter_g > v24)
      {
        Postblur_filter_g = 1.0;
      }
      if (Postblur_filter_b > v24)
      {
        Postblur_filter_b = 1.0;
      }
      v63 = 1.1;
      v62 = 0.9;
    }
    (*v60)->Postblur_filter_r = (*v60)->Postblur_filter_r * v62;
    (*v60)->Postblur_filter_g = (*v60)->Postblur_filter_g * v62;
    (*v60)->Postblur_filter_a = (*v60)->Postblur_filter_a * v63;
      goto LABEL_249;
    goto LABEL_203;
  }
LABEL_202:
    goto LABEL_249;
LABEL_203:
LABEL_249:
  if (EventNo != 699)
    goto LABEL_250;
LABEL_205:
  Postblur_filter_blend = 1;
  Postblur_filter_r = Postblur_filter_r * 0.8;
  Postblur_filter_g = Postblur_filter_g * 0.8;
  Postblur_filter_a = Postblur_filter_a * 0.8;
  if ((v27->_2.bitflags2 & 2) != 0)
  {
LABEL_251:
  }
LABEL_253:
  UpdateFlg_filter = 1;
}

// 0x137d230
dds3Effect_PartialMultiBlur_t *dds3EffectPartialMultiBlurCreate(dds3Effect_PartialMultiBlurParam_t *pParam) {
  dds3Effect_PartialMultiBlur_t_o *v3;

  v3 = Allocate(dds3Effect_PartialMultiBlur_t);
  dds3Effect_PartialMultiBlur_t___ctor(v3);
  v3->param = pParam;
  return v3;
}

// 0x137d2a0
void dds3EffectPartialMultiBlurDelete(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur) {
  ;
}

// 0x137d2b0
void dds3EffectPartialMultiBlurDraw(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, bool bPS2mode, s32 SkillID) {
  _BOOL4 EventMode;
  s32 v10;
  struct dds3Effect_Blur_t_o *Blur;
  s32 blend;
  dds3KernelDraw_c *v19;
  f32 rotate;
  f32 Postblur_multiblur_scale;
  u32 abgr_low;
  f64 v24;
  f64 v25;
  f64 v26;
  f32 Postblur_multiblur_r;
  f32 Postblur_multiblur_b;
  f32 v30;
  s32 area;
  f32 Postblur_multiblur_a;
  s32 width;
  struct System_Int32_array *pm;
  s32 v38;
  s32 v40;
  s32 v42;
  s32 height;
  struct System_Int32_array *v45;
  s32 v46;
  s32 v48;
  s32 v50;
  dds3KernelDraw_c *v51;
  f32 v52;
  struct System_Int32_array *v53;
  s32 v55;
  s32 v57;
  struct System_Int32_array *v59;
  s32 v61;
  f32 Postblur_multiblur_center_x;
  f32 v64;
  f32 Postblur_multiblur_center_y;
  f32 v67;
  f32 Postblur_multiblur_g;
  f32 v71;
  System_String_o *v73;
  dds3KernelDraw_c *v74;
  f32 E601_alp_CntF;
  f32 v78;
  f32 v80;
  f32 v81;
  f32 v82;
  f32 Postblur_filter_a;
  System_String_o *EventCamName;
  System_String_o *v88;
  f32 v91;
  System_String_o *v94;
  System_String_o *v95;
  System_String_o *v99;
  System_String_o *v102;
  System_String_o *v105;
  System_String_o *v107;
  System_String_o *v109;
  System_String_o *v111;
  s32 E674_aradia_fdof_CntI;
  f32 v117;
  f32 Postblur_multiblur_area;
  System_String_o *v119;
  System_String_o *v120;
  System_String_o *v123;
  s32 EventNo;
  s32 areaID;
  System_String_o *name;
  sdfModelRootNode_t_o *modelRoot;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 *p_SDF_CC_NDNM;
  f32 v160;
  f32 v161;
  f32 v162;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  f32 v167;
  f32 v168;
  f32 v170;
  struct fldGlobalWork_t_o *fldGb;
  s32 v173;
  struct dds3KernelDraw_StaticFields **p_static_fields;
  s64 v178;
  s32 v179;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector3_o v182;
  UnityEngine_Vector3_o v183;
  UnityEngine_Vector3_o v184;
  UnityEngine_Vector4_o v185;
  UnityEngine_Vector4_o v186;

  pFormation = 0;
  *&p.x = 0;
  *&p.z = 0;
  v179 = 0;
  v178 = 0;
  v10 = EventMode;
  if (SkillID && EventMode)
  {
    v10 = EventMode & ChkNbEventRun();
  }
  Blur = (*hPartialMultiBlur)->param->Blur;
  blend = Blur->blend;
  if (blend == 68 || blend == 1)
  {
    Postblur_multiblur_blend = 1;
    Blur = (*hPartialMultiBlur)->param->Blur;
    blend = Blur->blend;
  }
  if (blend == 72 || blend == 2)
  {
    Postblur_multiblur_blend = 2;
    Blur = (*hPartialMultiBlur)->param->Blur;
    blend = Blur->blend;
  }
  if (blend == 66 || blend == 3)
  {
    Postblur_multiblur_blend = 3;
    Blur = (*hPartialMultiBlur)->param->Blur;
    blend = Blur->blend;
  }
  if (blend == 4)
  {
    Postblur_multiblur_blend = 4;
    Blur = (*hPartialMultiBlur)->param->Blur;
  }
  rotate = Blur->rotate;
  Postblur_multiblur_rotation = rotate / 6.28;
  Postblur_multiblur_scale = (*hPartialMultiBlur)->param->Blur->scale;
  if (v10)
  {
    if (Postblur_multiblur_scale < 1.0)
    {
      Postblur_multiblur_scale = ((1.0 - Postblur_multiblur_scale) / -3.0) + 1.0;
    }
  }
  abgr_low = LOBYTE((*hPartialMultiBlur)->param->Blur->abgr);
  v24 = abgr_low;
  *&v24 = abgr_low;
  *&v24 = *&v24 * 0.0078125;
  Postblur_multiblur_r = *&v24;
  LOBYTE(v24) = BYTE1((*hPartialMultiBlur)->param->Blur->abgr);
  v25 = *&v24;
  *&v25 = v25;
  Postblur_multiblur_g = *&v25 * 0.0078125;
  LOBYTE(v25) = BYTE2((*hPartialMultiBlur)->param->Blur->abgr);
  v26 = *&v25;
  *&v26 = v26;
  *&v26 = *&v26 * 0.0078125;
  Postblur_multiblur_b = *&v26;
  LOBYTE(v26) = HIBYTE((*hPartialMultiBlur)->param->Blur->abgr);
  *&v26 = *&v26;
  Postblur_multiblur_a = *&v26 * 0.0078125;
  if (Postblur_multiblur_r >= Postblur_multiblur_g)
  {
LABEL_62:
    if ((v19->_2.bitflags2 & 2) == 0)
      goto LABEL_78;
    goto LABEL_63;
  }
  if ((v19->_2.bitflags2 & 2) == 0)
  {
    Postblur_multiblur_r = Postblur_multiblur_g;
    goto LABEL_62;
  }
  else
  {
    Postblur_multiblur_r = Postblur_multiblur_g;
      goto LABEL_78;
  }
LABEL_63:
LABEL_78:
  if (Postblur_multiblur_r < Postblur_multiblur_b)
    goto LABEL_79;
LABEL_65:
  v30 = 1.0;
  if (Postblur_multiblur_r > 1.0)
  {
LABEL_66:
    Postblur_multiblur_r = Postblur_multiblur_r / Postblur_multiblur_r;
    Postblur_multiblur_g = Postblur_multiblur_g / Postblur_multiblur_r;
    Postblur_multiblur_b = Postblur_multiblur_b / Postblur_multiblur_r;
    if ((v19->_2.bitflags2 & 2) == 0)
      goto LABEL_83;
    goto LABEL_70;
  }
LABEL_82:
  if ((v19->_2.bitflags2 & 2) == 0)
    goto LABEL_83;
LABEL_70:
LABEL_83:
  if (Postblur_multiblur_a <= v30)
    goto LABEL_84;
LABEL_72:
  Postblur_multiblur_a = 1.0;
LABEL_84:
  area = (*hPartialMultiBlur)->param->area;
  Postblur_multiblur_area = area / 224.0;
  Postblur_distortionblur_moyaalp = 0.0;
  Postblur_distortionblur_moyarotspd = 0.003;
  Postblur_multiblur_a = Postblur_multiblur_a * FldEve_Pow;
  FldEve_Pow = 1.0;
  if (bPS2mode)
  {
    width = get_width(0);
    pm = (*hPartialMultiBlur)->param->Blur->center->pm;
    v38 = width;
    v40 = pm->m_Items[0];
    v42 = get_width(0);
    Postblur_multiblur_center_x = (((((v38 * 0.5) / 320.0) * v40) / (v42 * 0.5)) * 0.5) + 0.5;
    height = get_height(0);
    v45 = (*hPartialMultiBlur)->param->Blur->center->pm;
    v46 = height;
    v48 = v45->m_Items[1];
    v50 = get_height(0);
    v52 = ((((v46 * 0.5) / 224.0) * v48) / (v50 * 0.5)) * 0.5;
  }
  else
  {
    v53 = (*hPartialMultiBlur)->param->Blur->center->pm;
    v55 = v53->m_Items[0];
    v57 = get_width(0);
    Postblur_multiblur_center_x = (v55 / v57) + 0.5;
    v59 = (*hPartialMultiBlur)->param->Blur->center->pm;
    v61 = v59->m_Items[1];
    v52 = v61 / get_height(0);
  }
  Postblur_multiblur_center_y = 0.5 - v52;
  if (Postblur_multiblur_center_x >= -0.5)
  {
    else
    {
      v64 = 1.5;
      if (Postblur_multiblur_center_x > 1.5)
        goto LABEL_170;
    }
    else
    {
      if (Postblur_multiblur_center_y < -0.5)
        goto LABEL_170;
    }
    if (Postblur_multiblur_center_y <= v64)
    {
      if (!v10)
        goto LABEL_173;
      goto LABEL_122;
    }
  }
LABEL_170:
  else
  {
    Postblur_multiblur_blend = 0;
    if (!v10)
      goto LABEL_173;
  }
LABEL_122:
  v67 = Postblur_multiblur_a;
  if (v67 > 0.0)
  {
    Postblur_multiblur_a = v67 * 1.1;
    if (Postblur_multiblur_a > v30)
    {
      Postblur_multiblur_a = 1.0;
    }
  }
  Postblur_multiblur_g = Postblur_multiblur_r;
  if (Postblur_multiblur_g < Postblur_multiblur_g)
  {
    if ((v51->_2.bitflags2 & 2) != 0)
    {
      else
      {
          goto LABEL_141;
      }
LABEL_142:
      v71 = Postblur_multiblur_b;
      if (Postblur_multiblur_g < v71)
        goto LABEL_143;
LABEL_167:
      if (Postblur_multiblur_g > v30)
        goto LABEL_151;
      goto LABEL_173;
    }
  }
  if ((v51->_2.bitflags2 & 2) == 0)
    goto LABEL_142;
LABEL_141:
    goto LABEL_142;
  v71 = Postblur_multiblur_b;
  if (Postblur_multiblur_g >= v71)
    goto LABEL_167;
LABEL_143:
  if ((v51->_2.bitflags2 & 2) == 0)
  {
    Postblur_multiblur_g = v71;
    if (v71 > v30)
      goto LABEL_151;
LABEL_173:
    if (SkillID == 263)
      goto LABEL_155;
LABEL_174:
    if (!v10)
      goto LABEL_471;
LABEL_175:
    if (EventNo != 601)
    {
LABEL_209:
      if (EventNo == 634)
      {
        if (op_Equality(evtUpdateEx_FieldName, "f634_050(Clone)", 0))
        {
          EventCamName = GetEventCamName();
          if (op_Equality(EventCamName, "cam01", 0))
            goto LABEL_225;
          v88 = GetEventCamName();
          if (op_Equality(v88, "cam02", 0))
          {
LABEL_225:
            Postblur_multiblur_center_x = Postblur_multiblur_center_x + -0.01;
            v91 = Postblur_multiblur_center_y + -0.025;
LABEL_229:
            Postblur_multiblur_center_y = v91;
            goto LABEL_230;
          }
          v123 = GetEventCamName();
          if (op_Equality(v123, "cam03", 0))
          {
            Postblur_multiblur_a = Postblur_multiblur_a * 1.2;
            Postblur_multiblur_area = Postblur_multiblur_area * 1.2;
            v91 = Postblur_multiblur_center_y * 1.2;
            goto LABEL_229;
          }
        }
      }
LABEL_230:
      if (EventNo == 651)
      {
        if (op_Equality(evtUpdateEx_FieldName, "f651_001(Clone)", 0))
        {
          v94 = GetEventCamName();
          if (op_Equality(v94, "cam10", 0))
            goto LABEL_246;
          v95 = GetEventCamName();
          if (op_Equality(v95, "cam11", 0))
          {
LABEL_246:
            Postblur_multiblur_a = Postblur_multiblur_a * 0.7;
          }
        }
      }
      if (EventNo == 661)
      {
        if (op_Equality(evtUpdateEx_FieldName, "f661_010(Clone)", 0))
        {
          v99 = GetEventCamName();
          if (op_Equality(v99, "cam06", 0))
          {
            Postblur_multiblur_a = Postblur_multiblur_a * 0.9;
            Postblur_multiblur_area = Postblur_multiblur_area * 1.2;
          }
          v102 = GetEventCamName();
          if (op_Equality(v102, "cam07", 0))
          {
            Postblur_multiblur_a = Postblur_multiblur_a * 0.8;
            Postblur_multiblur_area = Postblur_multiblur_area * 1.2;
          }
          v105 = GetEventCamName();
          if (op_Equality(v105, "cam08", 0))
            goto LABEL_282;
          v107 = GetEventCamName();
          if (op_Equality(v107, "cam09", 0))
          {
LABEL_282:
            Postblur_multiblur_a = Postblur_multiblur_a * 0.8;
            Postblur_multiblur_area = Postblur_multiblur_area * 1.4;
            Postblur_multiblur_center_y = Postblur_multiblur_center_y * 1.2;
          }
          v109 = GetEventCamName();
          if (op_Equality(v109, "cam10", 0))
          {
            Postblur_multiblur_a = Postblur_multiblur_a * 0.6;
            Postblur_multiblur_area = Postblur_multiblur_area * 1.2;
            Postblur_multiblur_center_x = 0.5;
            Postblur_multiblur_center_y = 0.556;
          }
        }
      }
      else if (EventNo != 674)
      {
        goto LABEL_388;
      }
      else if (Postblur_multiblur_blend != 2)
      {
        goto LABEL_388;
      }
      v111 = GetEventCamName();
      if (!op_Equality(v111, "cam09", 0))
      {
        v119 = GetEventCamName();
        if (op_Equality(v119, "cam09c", 0))
          goto LABEL_325;
        v120 = GetEventCamName();
        if (op_Equality(v120, "cam12", 0))
        {
LABEL_325:
          Postblur_multiblur_a = Postblur_multiblur_a * 0.8;
            goto LABEL_389;
        }
        else
        {
          Postblur_multiblur_r = Postblur_multiblur_r * 0.5;
          Postblur_multiblur_g = Postblur_multiblur_g * 0.8;
          Postblur_multiblur_area = Postblur_multiblur_area * 1.3;
          E674_aradia_fdof_CntI = 0;
            goto LABEL_389;
        }
LABEL_329:
LABEL_389:
        if (EventNo != 681)
          goto LABEL_422;
        goto LABEL_390;
      }
      Postblur_multiblur_blend = 1;
      Postblur_multiblur_rotation = 0.0;
      Postblur_multiblur_scale = 1.0;
      E674_aradia_fdof_CntI = ++E674_aradia_fdof_CntI;
      if (E674_aradia_fdof_CntI == 86)
      {
        Postblur_multiblur_a = 0.85;
        v117 = 2.6;
        goto LABEL_387;
      }
      if (E674_aradia_fdof_CntI == 87)
      {
        Postblur_multiblur_a = 0.9;
        v117 = 3.0;
        goto LABEL_387;
      }
      if (E674_aradia_fdof_CntI == 88)
      {
        Postblur_multiblur_a = 0.95;
        v117 = 3.2;
        goto LABEL_387;
      }
      if (E674_aradia_fdof_CntI == 89)
        goto LABEL_378;
      if (E674_aradia_fdof_CntI == 90)
      {
LABEL_378:
        {
LABEL_386:
          Postblur_multiblur_a = 1.0;
          v117 = 3.5;
LABEL_387:
          Postblur_multiblur_area = Postblur_multiblur_area * v117;
LABEL_388:
            goto LABEL_389;
          goto LABEL_329;
        }
      }
      else
      {
        if (E674_aradia_fdof_CntI != 91)
        {
          v117 = 2.2;
          goto LABEL_387;
        }
          goto LABEL_386;
      }
      goto LABEL_386;
    }
    v73 = GetEventCamName();
    if (op_Equality(v73, "cam01", 0))
    {
      Postblur_multiblur_center_y = 0.75;
      Postblur_multiblur_area = Postblur_multiblur_area * 0.6;
      E601_alp_CntF = 0.1;
      E601_area_CntF = 0.2;
      if ((v74->_2.bitflags2 & 2) == 0)
        goto LABEL_204;
    }
    else
    {
      E601_alp_CntF = E601_alp_CntF + 0.05;
      v78 = sinf(E601_alp_CntF);
      v80 = v78 * 0.02;
      E601_area_CntF = E601_area_CntF
                                                             + 0.06;
      v81 = sinf(E601_area_CntF);
      v82 = v81 * 0.05;
      Postblur_multiblur_rotation = 0.002;
      Postblur_multiblur_scale = (v82 * -0.005) + 0.99;
      Postblur_multiblur_blend = 1;
      Postblur_multiblur_center_y = 0.5;
      Postblur_multiblur_center_y = 0.778;
      Postblur_multiblur_a = v80 + 0.9;
      Postblur_multiblur_area = v82 + v30;
      if ((v74->_2.bitflags2 & 2) == 0)
        goto LABEL_204;
    }
LABEL_204:
    if (Postblur_filter_a > 0.9)
    {
      Postblur_multiblur_a = Postblur_multiblur_a * ((v30 - Postblur_filter_a) * 10.0);
    }
    goto LABEL_209;
  }
  else
  {
    Postblur_multiblur_g = Postblur_multiblur_b;
    if (Postblur_multiblur_g <= v30)
      goto LABEL_173;
  }
LABEL_151:
  Postblur_multiblur_r = Postblur_multiblur_r / Postblur_multiblur_g;
  Postblur_multiblur_g = Postblur_multiblur_g / Postblur_multiblur_g;
  Postblur_multiblur_b = Postblur_multiblur_b / Postblur_multiblur_g;
  if (SkillID != 263)
    goto LABEL_174;
LABEL_155:
  Postblur_multiblur_a = Postblur_multiblur_a * 0.6;
  if (v10)
    goto LABEL_175;
LABEL_471:
  else if (!effBTLSkillCheckRun2(0x85u))
  {
    goto LABEL_500;
  }
  pFormation = effBTLSkillGetInvokeFormation(0);
  *&p.x = 0;
  *&p.z = 0;
  name = get_name(pFormation->hunit->Model->modelRoot->modelobj);
  if (Equals_5234480(name, "devil_0x00(Clone)", 0))
  {
    modelRoot = pFormation->hunit->Model->modelRoot;
    if (!sdfModelGetMarkPosUnity(modelRoot, 0))
    {
      effBTLModelGetSphereCenter(&pFormation);
    }
    SDF_VU0__STOREVECTOR(&p);
    x = p.x;
    y = p.y;
    z = p.z;
    w = p.w;
    p_SDF_CC_NDNM = &SDF_CC_NDNM;
    v160 = p_SDF_CC_NDNM[41];
    v161 = p_SDF_CC_NDNM[42];
    v162 = p_SDF_CC_NDNM[43];
    v183.x = v160;
    v183.y = v161;
    v183.z = v162;
    v186 = op_Implicit(v183, 0);
    v185.x = x;
    v185.y = y;
    v185.z = z;
    v185.w = w;
    p = Scale(v185, v186);
    MainCamera = GetMainCamera(kernelObject);
    Component_object = GetComponent_object_(MainCamera);
    v184 = op_Implicit_8738992(p);
    v182 = WorldToScreenPoint_27174640(Component_object, v184);
    sub_8524C0(&v178, 0.0, 0.0, 0.0);
    v167 = get_width(0);
    v168 = get_height(0);
    *&v178 = v182.x / v167;
    *(&v178 + 1) = v182.y / v168;
    v170 = v182.y / v168;
    Postblur_multiblur_center_x = v182.x / v167;
    Postblur_multiblur_center_y = v170;
  }
LABEL_500:
  if (fldGb->fieldID == 31)
  {
    else
    {
      v173 = fldGb->areaID;
      if (v173 == 2)
        goto LABEL_526;
    }
    else if (v173 == 4)
    {
      goto LABEL_526;
    }
    if (v173 != 6)
    {
      if (v173 != 10)
      {
        if (v173 != 13)
          goto LABEL_538;
      }
    }
LABEL_526:
    if (Postblur_multiblur_blend == 1)
    {
      if (Postblur_multiblur_center_x < 0.3)
      {
        Postblur_multiblur_blend = 2;
        (*p_static_fields)->Postblur_multiblur_r = (*p_static_fields)->Postblur_multiblur_r * 0.7;
        (*p_static_fields)->Postblur_multiblur_g = (*p_static_fields)->Postblur_multiblur_g * 0.7;
        (*p_static_fields)->Postblur_multiblur_b = (*p_static_fields)->Postblur_multiblur_b * 0.7;
        (*p_static_fields)->Postblur_multiblur_center_x = 0.1;
      }
    }
  }
LABEL_538:
  UpdateFlg_multiblur = 1;
}

// 0x137f350
void dds3EffectPartialMultiBlurSetParam(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, dds3Effect_PartialMultiBlurParam_t *pParam) {
  (*hPartialMultiBlur)->param = pParam;
}

// 0x137f360
void dds3EffectPartialMultiBlurSetTex(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, sdfTexHandle_t *hTex) {
  (*hPartialMultiBlur)->hAlphaTex = hTex;
}

// 0x137f370
void dds3EffectPartialMultiBlurSetTexDef(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur) {
  dds3Effect_PartialMultiBlur_t_o *v3;

  v3 = *hPartialMultiBlur;
  v3->hAlphaTex = dds3BillboardGetGeneralTex(2);
}

// 0x1385be0
dds3Effect_PartialMultiFilter_t *dds3EffectPartialMultiFilterCreate(dds3Effect_PartialMultiFilterParam_t *pParam) {
  dds3Effect_PartialMultiFilter_t_o *v3;

  v3 = Allocate(dds3Effect_PartialMultiFilter_t);
  dds3Effect_PartialMultiFilter_t___ctor(v3);
  v3->param = pParam;
  return v3;
}

// 0x1385c50
void dds3EffectPartialMultiFilterDelete(dds3Effect_PartialMultiFilter_t *hPartialMultiFilter) {
  ;
}

// 0x1385c60
void dds3EffectPartialMultiFilterDraw(dds3Effect_PartialMultiFilter_t **hPartialMultiFilter) {
  s32 blend;
  s32 v5;
  u32 abgr_low;
  f64 v7;
  f64 v8;
  f64 v9;
  struct System_Int32_array *pm;
  s32 v12;
  struct System_Int32_array *v13;
  s32 v15;
  f32 v17;
  f32 Postblur_multifilter_center_x;
  f32 v21;
  f32 Postblur_multifilter_center_y;
  sdfModelRootNode_t_o *modelRoot;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 *p_SDF_CC_NDNM;
  f32 v35;
  f32 v36;
  f32 v37;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  f32 width;
  f32 height;
  f32 v46;
  s64 v47;
  s32 v48;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector3_o v51;
  UnityEngine_Vector3_o v52;
  UnityEngine_Vector3_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;

  *&p.z = 0;
  pFormation = 0;
  *&p.x = 0;
  v48 = 0;
  v47 = 0;
  blend = (*hPartialMultiFilter)->param->Filter->blend;
  switch (blend)
  {
    case 1:
    case 68:
      v5 = 1;
      goto LABEL_25;
    case 2:
    case 72:
      goto LABEL_9;
    case 3:
    case 66:
      v5 = 3;
      goto LABEL_25;
    case 4:
    case 6:
      v5 = 4;
      goto LABEL_25;
    case 5:
      v5 = 5;
      goto LABEL_25;
    default:
      if (blend < 5)
        goto LABEL_26;
LABEL_9:
      v5 = 2;
LABEL_25:
      Postblur_multifilter_blend = v5;
LABEL_26:
      abgr_low = LOBYTE((*hPartialMultiFilter)->param->Filter->abgr);
      v7 = abgr_low;
      *&v7 = abgr_low;
      *&v7 = *&v7 * 0.0078125;
      Postblur_multifilter_r = *&v7;
      LOBYTE(v7) = BYTE1((*hPartialMultiFilter)->param->Filter->abgr);
      v8 = *&v7;
      *&v8 = v8;
      Postblur_multifilter_g = *&v8 * 0.0078125;
      LOBYTE(v8) = BYTE2((*hPartialMultiFilter)->param->Filter->abgr);
      v9 = *&v8;
      *&v9 = v9;
      *&v9 = *&v9 * 0.0078125;
      Postblur_multifilter_b = *&v9;
      LOBYTE(v9) = HIBYTE((*hPartialMultiFilter)->param->Filter->abgr);
      *&v9 = *&v9;
      Postblur_multifilter_a = *&v9 * 0.0078125;
      Postblur_multifilter_area = (*hPartialMultiFilter)->param->area / 244.0;
      pm = (*hPartialMultiFilter)->param->center->pm;
      v12 = pm->m_Items[0];
      Postblur_multifilter_center_x = (v12 / get_width(0))
                                                                            + 0.5;
      v13 = (*hPartialMultiFilter)->param->center->pm;
      v15 = v13->m_Items[1];
      v17 = v15 / get_height(0);
      Postblur_multifilter_center_y = 0.5 - v17;
      if (Postblur_multifilter_center_x < -0.5)
        goto LABEL_50;
      else
      {
        v21 = 1.5;
        if (Postblur_multifilter_center_x > 1.5)
          goto LABEL_50;
      }
      if (Postblur_multifilter_center_y < -0.5)
        goto LABEL_50;
LABEL_40:
      if (Postblur_multifilter_center_y > v21)
        goto LABEL_50;
LABEL_54:
      UpdateFlg_multifilter = 1;
      else if (!effBTLSkillCheckRun2(0x6Fu))
      {
        return;
      }
      *&p.z = 0;
      pFormation = effBTLSkillGetInvokeFormation(0);
      *&p.x = 0;
      modelRoot = pFormation->hunit->Model->modelRoot;
      if (!sdfModelGetMarkPosUnity(modelRoot, 0))
      {
        effBTLModelGetSphereCenter(&pFormation);
      }
      SDF_VU0__STOREVECTOR(&p);
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      p_SDF_CC_NDNM = &SDF_CC_NDNM;
      v35 = p_SDF_CC_NDNM[41];
      v36 = p_SDF_CC_NDNM[42];
      v37 = p_SDF_CC_NDNM[43];
      v52.x = v35;
      v52.y = v36;
      v52.z = v37;
      v55 = op_Implicit(v52, 0);
      v54.x = x;
      v54.y = y;
      v54.z = z;
      v54.w = w;
      p = Scale(v54, v55);
      MainCamera = GetMainCamera(kernelObject);
      Component_object = GetComponent_object_(MainCamera);
      v53 = op_Implicit_8738992(p);
      v51 = WorldToScreenPoint_27174640(Component_object, v53);
      sub_8524C0(&v47, 0.0, 0.0, 0.0);
      width = get_width(0);
      height = get_height(0);
      *&v47 = v51.x / width;
      *(&v47 + 1) = v51.y / height;
      v46 = v51.y / height;
      Postblur_multifilter_center_x = v51.x / width;
      Postblur_multifilter_center_y = v46;
      return;
  }
}

// 0x1383df0
void dds3EffectRipBlurPartAreaSet(dds3Effect_RippleBlurParam_t *pParam, dds3Effect_RipBlurPart_tag **pPart) {
  struct System_Int32_array *pm;
  u32 max_length;
  s32 v5;
  s32 v7;
  s32 v8;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *v11;
  struct sdfIVector2_t_array *v13;
  struct System_Int32_array *v15;
  struct sdfIVector2_t_array *v17;
  struct System_Int32_array *v19;
  s32 v20;
  struct sdfIVector2_t_array *v22;
  struct System_Int32_array *v24;
  s32 v25;

  pm = pParam->center->pm;
  max_length = pm->max_length;
  v5 = pm->m_Items[0];
  v7 = pParam->center->pm->m_Items[1];
  v8 = ((*pPart)->scale * pParam->area);
  xy = (*pPart)->Blur->xy;
  v11 = xy->m_Items[0]->pm;
  v11->m_Items[0] = v5 - v8;
  v13 = (*pPart)->Blur->xy;
  v15 = v13->m_Items[0]->pm;
  v15->m_Items[1] = v7 - v8;
  v17 = (*pPart)->Blur->xy;
  v19 = v17->m_Items[1]->pm;
  v20 = v5 + v8;
  v19->m_Items[0] = v20;
  v22 = (*pPart)->Blur->xy;
  v24 = v22->m_Items[1]->pm;
  v25 = v7 + v8;
  v24->m_Items[1] = v25;
}

// 0x1383ff0
void dds3EffectRipBlurPartInit(dds3Effect_RippleBlurParam_t *pParam, dds3Effect_RipBlurPart_tag **pPart) {
  struct dds3Effect_Blur_t_o *Blur;
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;

  (*pPart)->radiun = 0.0;
  (*pPart)->scale = 0.0;
  Blur = (*pPart)->Blur;
  Blur->abgr = pParam->abgr;
  Blur->blend = pParam->blend;
  Blur->rotate = pParam->rotate;
  pm = Blur->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = Blur->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
}

// 0x1384210
effRippleBlurHandle_t *dds3EffectRippleBlurCreate(dds3Effect_RippleBlurParam_t *pParam) {
  u64 number;
  effRippleBlurHandle_t_o *v4;
  u64 i;
  u32 *pwork;
  u64 *v9;
  struct dds3Effect_RipBlurPart_tag_array *v11;
  dds3Effect_RipBlurPart_tag_o *v13;
  dds3Effect_RippleBlurParam_t_o *param;
  f32 v17;
  dds3Effect_RipBlurPart_tag_o *pPart;

  pPart = 0;
  number = pParam->number;
  v4 = Allocate(effRippleBlurHandle_t);
  effRippleBlurHandle_t___ctor(v4);
  v4->hMem = 0;
  v4->pwork = NewSpecific(dds3Effect_RipBlurPart_tag, number);
  v4->param = pParam;
  v4->hAlphaTex = dds3BillboardGetGeneralTex(3);
  if (number >= 1)
  {
    for (i = 0; i != number; ++i)
    {
      pwork = v4->pwork;
      v9 = Allocate(dds3Effect_RipBlurPart_tag);
      _ctor(v9, 0);
      *&pwork[2 * i + 8] = v9;
      v11 = v4->pwork;
      v13 = v11->m_Items[i];
      pPart = v13;
      Clear(v13, 0);
      param = v4->param;
      dds3EffectRipBlurPartInit(param, &pPart);
      v17 = -(v4->param->interval * i);
      v13->scale = v17;
    }
  }
  return v4;
}

// 0x1384400
void dds3EffectRippleBlurDelete(effRippleBlurHandle_t **hRippleBlur) {
  effRippleBlurHandle_t_o *v3;
  s32 number;
  s32 v5;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;

  v3 = *hRippleBlur;
  if (*hRippleBlur)
  {
    number = v3->param->number;
    if (number >= 1)
    {
      v5 = 0;
      if (!LODWORD(v3->pwork->max_length))
      {
LABEL_8:
      }
      while (number - 1 != v5)
      {
        if (++v5 >= LODWORD((*hRippleBlur)->pwork->max_length))
          goto LABEL_8;
      }
    }
  }
  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  if (op_Inequality(Component_object, 0, 0))
  {
    Destroy_27360000(Component_object);
  }
}

// 0x1384560
void dds3EffectRippleBlurDraw(effRippleBlurHandle_t **hRippleBlur, bool UnityCalc) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  Il2CppObject *v11;
  effRippleBlurHandle_t_o *v12;
  s64 number;
  s64 v14;
  u64 v15;
  struct dds3Effect_RipBlurPart_tag_array *pwork;
  dds3Effect_RipBlurPart_tag_o *v18;
  f32 scale;
  s64 Postblur_rippeblur_num;
  struct System_Single_array *Postblur_rippeblur_area;
  struct System_Single_array *Postblur_rippeblur_center_x;
  struct System_Single_array *Postblur_rippeblur_center_y;
  struct System_Single_array *v30;
  struct System_Single_array *v32;
  struct System_Int32_array *pm;
  struct System_Single_array *v36;
  struct System_Int32_array *v37;
  struct System_Single_array *Postblur_rippeblur_time;
  f32 power;
  f32 v44;
  s32 EventNo;
  dds3Effect_RippleBlurParam_t_o *param;
  dds3Effect_RipBlurPart_tag_o *pPart;

  pPart = 0;
  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  if (op_Equality(Component_object, 0, 0))
  {
    AddComponent_object_(MainCamera);
    v11 = GetComponent_object_(MainCamera);
    v11[4].klass = Find("Atlus/AtlusMat_Ripple", 0);
  }
  v12 = *hRippleBlur;
  number = (*hRippleBlur)->param->number;
  if (number >= 1)
  {
    v14 = number - 1;
    v15 = 0;
    pwork = v12->pwork;
    if (!LODWORD(pwork->max_length))
    {
LABEL_15:
    }
    while (1)
    {
      v18 = pwork->m_Items[v15];
      pPart = v18;
      scale = v18->scale;
      v18->scale = scale + v12->param->speed;
      if (scale < 0.0)
        goto LABEL_104;
      else
      {
        if (Postblur_rippeblur_num > 4)
          goto LABEL_96;
      }
      if (UnityCalc)
      {
        Postblur_rippeblur_area->m_Items[Postblur_rippeblur_num] = (*hRippleBlur)->param->unitycalc_area;
        Postblur_rippeblur_center_x->m_Items[Postblur_rippeblur_num] = (*hRippleBlur)->param->unitycalc_center_x;
        Postblur_rippeblur_center_y->m_Items[Postblur_rippeblur_num] = (*hRippleBlur)->param->unitycalc_center_y;
          goto LABEL_31;
      }
      else
      {
        v30 = Postblur_rippeblur_area;
        v30->m_Items[Postblur_rippeblur_num] = (*hRippleBlur)->param->area / 224.0;
        v32 = Postblur_rippeblur_center_x;
        pm = (*hRippleBlur)->param->center->pm;
        v32->m_Items[Postblur_rippeblur_num] = (pm->m_Items[0] * 0.0019531) + 0.5;
        v36 = Postblur_rippeblur_center_y;
        v37 = (*hRippleBlur)->param->center->pm;
        v36->m_Items[Postblur_rippeblur_num] = (v37->m_Items[1] / -448.0) + 0.5;
        {
LABEL_31:
        }
      }
      Postblur_rippeblur_time->m_Items[Postblur_rippeblur_num] = v18->scale;
      Postblur_rippeblur_blend = 1;
      power = (*hRippleBlur)->param->power;
      Postblur_rippeblur_power = power + power;
      if (UnityCalc)
      {
        v44 = (*hRippleBlur)->param->power;
        Postblur_rippeblur_power = v44 * 4.0;
      }
      else
      {
        if (!EventMode)
          goto LABEL_82;
      }
      else
      {
        if (EventNo == 614)
          goto LABEL_77;
      }
      else if (EventNo == 704)
      {
        goto LABEL_77;
      }
      if (EventNo == 617)
        goto LABEL_66;
LABEL_82:
      else
      {
        if (!kag_ripple)
          goto LABEL_89;
      }
      Postblur_rippeblur_power = Postblur_rippeblur_power * 0.25;
LABEL_89:
      else
      {
        if (Postblur_rippeblur_power > 0.8)
          goto LABEL_92;
      }
LABEL_96:
      ++Postblur_rippeblur_num;
      if (v18->scale > 1.0)
      {
        param = (*hRippleBlur)->param;
        dds3EffectRipBlurPartInit(param, &pPart);
      }
LABEL_104:
      if (v14 == v15)
        return;
      v12 = *hRippleBlur;
      ++v15;
      pwork = (*hRippleBlur)->pwork;
      if (v15 >= LODWORD(pwork->max_length))
        goto LABEL_15;
    }
  }
}

// 0x13840f0
void dds3EffectRippleBlurReset(effRippleBlurHandle_t **hRippleBlur) {
  effRippleBlurHandle_t_o *v4;
  s64 number;
  u64 v6;
  s64 v7;
  struct dds3Effect_RipBlurPart_tag_array *pwork;
  dds3Effect_RipBlurPart_tag_o *v10;
  dds3Effect_RippleBlurParam_t_o *param;
  dds3Effect_RipBlurPart_tag_o *pPart;

  pPart = 0;
  v4 = *hRippleBlur;
  number = (*hRippleBlur)->param->number;
  if (number >= 1)
  {
    v6 = 0;
    v7 = number - 1;
    pwork = v4->pwork;
    if (!LODWORD(pwork->max_length))
    {
LABEL_7:
    }
    while (1)
    {
      v10 = pwork->m_Items[v6];
      pPart = v10;
      param = v4->param;
      dds3EffectRipBlurPartInit(param, &pPart);
      v10->scale = -((*hRippleBlur)->param->interval * v6);
      if (v7 == v6)
        break;
      v4 = *hRippleBlur;
      ++v6;
      pwork = (*hRippleBlur)->pwork;
      if (v6 >= LODWORD(pwork->max_length))
        goto LABEL_7;
    }
  }
}

// 0x1386860
void dds3Effect_UpdateBigin(void) {
  dds3KernelDraw_c *v3;
  struct System_Single_array *Postblur_rippeblur_time;
  struct System_Single_array *v6;
  struct System_Single_array *v8;
  struct System_Single_array *v10;
  struct System_Single_array *v12;
  UnityEngine_Object_o *dbg_fps;

  UpdateFlg_blur = 0;
  UpdateFlg_multiblur = 0;
  UpdateFlg_distortionblur = 0;
  UpdateFlg_filter = 0;
  UpdateFlg_multifilter = 0;
  else
  {
    Postblur_rippeblur_num = 0;
    if ((v3->_2.bitflags2 & 2) == 0)
      goto LABEL_13;
  }
    goto LABEL_13;
  if (!LODWORD(Postblur_rippeblur_time->max_length))
  {
LABEL_17:
  }
LABEL_14:
  Postblur_rippeblur_time->m_Items[0] = 0.0;
  v6 = Postblur_rippeblur_time;
  v6->m_Items[1] = 0.0;
  v8 = Postblur_rippeblur_time;
  v8->m_Items[2] = 0.0;
  v10 = Postblur_rippeblur_time;
  v10->m_Items[3] = 0.0;
  v12 = Postblur_rippeblur_time;
  v12->m_Items[4] = 0.0;
  else if ((GetDrawFlag() & 0x2000000) != 0)
  {
    return;
  }
  if ((GetDrawFlag() & 0x8000000) != 0)
  {
    if (!get_activeSelf(kernelObject->btlui))
    {
      SetActive(kernelObject->btlui, 1, 0);
    }
    ClrDrawFlag(0x8000000u);
  }
  else if ((GetDrawFlag() & 0x10000000) == 0)
  {
    return;
  }
  if (op_Inequality(dbg_fps, 0, 0))
  {
    if (!get_activeSelf(dbg_fps))
    {
      SetActive(dbg_fps, 1, 0);
    }
  }
  ClrDrawFlag(0x10000000u);
}

// 0x1386cc0
void dds3Effect_UpdateEnd(void) {
  UnityEngine_Object_o *dbg_fps;
  effBlur_Filter_c *v15;
  char v16;
  char v24;

  else if ((GetDrawFlag() & 0x2000000) == 0)
  {
    goto LABEL_48;
  }
  ScreenStop1();
  DrawStopExec();
  if (get_activeSelf(kernelObject->btlui))
  {
    if ((GetDrawFlag() & 0x20000000) == 0)
    {
      SetActive(kernelObject->btlui, 0, 0);
      SetDrawFlag(0x8000000u, 1u);
    }
    ClrDrawFlag(0x2000000u);
  }
  if (op_Inequality(dbg_fps, 0, 0))
  {
    if (get_activeSelf(dbg_fps))
    {
      SetActive(dbg_fps, 0, 0);
      SetDrawFlag(0x10000000u, 1u);
    }
  }
  else
  {
    Find("Main Canvas", 0);
  }
LABEL_48:
  else if (UpdateFlg_blur)
  {
    goto LABEL_51;
  }
  Postblur_blur_blend = 0;
  v16 = 1;
  Postblur_blur_a = 0.0;
  if ((v15->_2.bitflags2 & 2) == 0)
  {
LABEL_83:
    if (!UpdateFlg_multiblur)
      goto LABEL_54;
LABEL_84:
    v16 = 0;
    if ((v15->_2.bitflags2 & 2) != 0)
      goto LABEL_58;
LABEL_85:
    if (!UpdateFlg_distortionblur)
      goto LABEL_60;
LABEL_86:
    v16 = 0;
    if ((v15->_2.bitflags2 & 2) != 0)
      goto LABEL_64;
LABEL_87:
    if (!UpdateFlg_filter)
      goto LABEL_66;
LABEL_88:
    v16 = 0;
    if ((v15->_2.bitflags2 & 2) != 0)
      goto LABEL_70;
LABEL_89:
    if (!UpdateFlg_multifilter)
      goto LABEL_72;
LABEL_90:
    v16 = 0;
    if ((v15->_2.bitflags2 & 2) == 0)
      goto LABEL_91;
    goto LABEL_76;
  }
LABEL_52:
    goto LABEL_83;
  if (UpdateFlg_multiblur)
    goto LABEL_84;
LABEL_54:
  Postblur_multiblur_blend = 0;
  Postblur_multiblur_a = 0.0;
  if ((v15->_2.bitflags2 & 2) == 0)
    goto LABEL_85;
LABEL_58:
    goto LABEL_85;
  if (UpdateFlg_distortionblur)
    goto LABEL_86;
LABEL_60:
  Postblur_distortionblur_blend = 0;
  Postblur_distortionblur_a = 0.0;
  if ((v15->_2.bitflags2 & 2) == 0)
    goto LABEL_87;
LABEL_64:
    goto LABEL_87;
  if (UpdateFlg_filter)
    goto LABEL_88;
LABEL_66:
  Postblur_filter_blend = 0;
  Postblur_filter_a = 0.0;
  if ((v15->_2.bitflags2 & 2) == 0)
    goto LABEL_89;
LABEL_70:
    goto LABEL_89;
  if (UpdateFlg_multifilter)
    goto LABEL_90;
LABEL_72:
  Postblur_multifilter_blend = 0;
  Postblur_multifilter_a = 0.0;
  if ((v15->_2.bitflags2 & 2) != 0)
  {
LABEL_76:
  }
LABEL_91:
  if (v16 & 1 | !UpdateFlg_AllOff)
  {
    v24 = 0;
  }
  else
  {
    v24 = 1;
  }
  Postblur_refresh = v24;
  UpdateFlg_AllOff = v16;
}

// 0x137a000
s32 dds3ScreenCaptureGetMode(void) {
  return 0;
}
