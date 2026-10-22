#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct dds3DrawEnv_t dds3DrawEnv_t;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct dds3KernelDraw_FADEPKT_t dds3KernelDraw_FADEPKT_t;
typedef struct dds3KernelDraw_ZCLSPKT_t dds3KernelDraw_ZCLSPKT_t;
typedef struct sdf3DFogParam_t sdf3DFogParam_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct sdf3DScreenParam_t sdf3DScreenParam_t;
typedef struct sdfDmaTag_t sdfDmaTag_t;
typedef struct sdfGifTag_t sdfGifTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct dds3KernelDraw_FADEPKT_t {
    sdfDmaTag_t *dmatag;
    sdfGifTag_t *giftag0;
    sdfGifTag_t *giftag1;
    sdfGrTagStdReg_t *alpha1;
    sdfGrTagStdReg_t *pabe;
    sdfGrTagStdReg_t *fba1;
    sdfGrTagStdReg_t *test1;
    sdfGrTagStdReg_t *col0;
    sdfGrTagStdReg_t *xyz0;
    sdfGrTagStdReg_t *col1;
    sdfGrTagStdReg_t *xyz1;
};

struct dds3KernelDraw_ZCLSPKT_t {
    sdfDmaTag_t *dmatag;
    sdfGifTag_t *giftag0;
    sdfGrTagStdReg_t *test1_0;
    sdfGifTag_t *giftag1;
    sdfGrTagStdReg_t *col0;
    sdfGrTagStdReg_t *xyz0;
    sdfGrTagStdReg_t *col1;
    sdfGrTagStdReg_t *xyz1;
    sdfGifTag_t *giftag2;
    sdfGrTagStdReg_t *test1_2;
    sdfGrTagStdReg_t *alpha1;
};

static dds3KernelDraw_ZCLSPKT_t *zclspkt[3];
static dds3KernelDraw_FADEPKT_t *fadepkt;
static sdfGrOt_t *dds3Ot[85];
static sdfModelOt_t *dds3ModelOt[11];
static dds3DrawEnv_t *dds3DrawEnv[2];
static sdfVector4_t dds3CameraOffset;
static s32 egl_OT_Offset;
static sdf3DScreenParam_t *dds3ScreenParam;
static sdfMatrix4_t dds3CameraTM;
static sdfVector4_t dds3CameraTargetPos;
static sdfVector4_t dds3CameraEyePos;
static sdfVector4_t dds3CameraUpVector;
static sdf3DLight_t *dds3DirLights[3];
static sdfVector4_t dds3Ambient;
static u32 dds3BackColor;
static sdf3DFogParam_t *dds3FogParam;
static char *chgmat_name;
static s32 dds3RenderTex;
static sdf3DScreenParam_t *dds3HScreenParam;
static sdfMatrix4_t dds3HCameraTM;
static sdfVector4_t dds3HCameraTargetPos;
static sdfVector4_t dds3HCameraEyePos;
static sdfVector4_t dds3HCameraUpVector;
static sdf3DFogParam_t *dds3HFogParam;
static u32 dds3DrawFlag;
static u32 dds3DrawStopCount;
static u8 dds3ScreenBlurFlag;
static s16 dds3ScreenBlurAlpha;
static s16 dds3ScreenBlurScale;
static s32 dds3ScreenBlurPnt[2];
static u16 blurnow;
static u16 blurmax;
static s16 bluralphabase;
static s16 blurscalebase;
static s16 bluralphatarget;
static s16 blurscaletarget;
static u16 dds3QuakeFlag;
static s16 dds3QuakeFrame;
static u16 dds3QuakeXRange;
static u16 dds3QuakeYRange;
static u8 fadergba[4];
static u16 fadenow;
static u16 fademax;
static u16 lightrgbnow[3];
static u16 lightrgbmax[3];
static u16 lightdirnow[3];
static u16 lightdirmax[3];
static u16 ambientnow;
static u16 ambientmax;
static u32 lightrgbbase[3];
static u32 lightrgbtarget[3];
static u32 ambientbase;
static u32 ambienttarget;
static sdfVector4_t lightdirbase[3];
static sdfVector4_t lightdirquat[3];
static u16 fogrgbnow;
static u16 fogrgbmax;
static u16 fogparanow;
static u16 fogparamax;
static u32 fogrgbbase;
static u32 fogrgbtarget;
static sdfVector4_t fogparabase;
static sdfVector4_t fogparatarget;
static u16 sbnow;
static u16 sbmax;
static f32 softenbase;
static f32 softentarget;
static f32 biasbase;
static f32 biastarget;
static u16 mulblurnow;
static u16 mulblurmax;
static u16 mulblurabase;
static u16 mulbluratarget;
static u16 mulblurswapnow;
static u16 mulblurswapmax;
static dds3Effect_PartialMultiBlurParam_t *mulblurbase;
static dds3Effect_PartialMultiBlurParam_t *mulblurtarget;
static u16 distblurnow;
static u16 distblurmax;
static u16 distblurabase;
static u16 distbluratarget;
static u16 distblurswapnow;
static u16 distblurswapmax;
static dds3Effect_DistortionBlurParam_t *distblurbase;
static dds3Effect_DistortionBlurParam_t *distblurtarget;
static s32 distblurovercnt;
static u16 ripblurnow;
static u16 ripblurmax;
static u16 ripblurabase;
static u16 ripbluratarget;
static u16 ripblurswapnow;
static u16 ripblurswapmax;
static dds3Effect_RippleBlurParam_t *ripblurbase;
static dds3Effect_RippleBlurParam_t *ripblurtarget;
static s32 ripblurovercnt;
static u16 blur2now;
static u16 blur2max;
static u16 blur2abase;
static u16 blur2atarget;
static u16 blur2swapnow;
static u16 blur2swapmax;
static dds3Effect_Blur_t *blur2base;
static dds3Effect_Blur_t *blur2target;
static u16 filter2now;
static u16 filter2max;
static u16 filter2abase;
static u16 filter2atarget;
static u16 filter2swapnow;
static u16 filter2swapmax;
static dds3Effect_Filter_t *filter2base;
static dds3Effect_Filter_t *filter2target;
static u16 mfilternow;
static u16 mfiltermax;
static u16 mfilterabase;
static u16 mfilteratarget;
static u16 mfilterswapnow;
static u16 mfilterswapmax;
static dds3Effect_PartialMultiFilterParam_t *mfilterbase;
static dds3Effect_PartialMultiFilterParam_t *mfiltertarget;
static f32 Adj_ColorR;
static f32 Adj_ColorG;
static f32 Adj_ColorB;
static f32 ToonType;
static f32 ToonTypeStart;
static f32 ToonTypeDiv;
static bool Postblur_refresh;
static bool Postblur_Encount1st;
static f32 Postblur_FilterAlp;
static s32 Postblur_DrawStop;
static bool Postblur_AccumTex_NowMode;
static f32 Postblur_blur_rotation;
static f32 Postblur_blur_scale;
static s32 Postblur_blur_blend;
static f32 Postblur_blur_r;
static f32 Postblur_blur_g;
static f32 Postblur_blur_b;
static f32 Postblur_blur_a;
static f32 Postblur_blur_center_x;
static f32 Postblur_blur_center_y;
static f32 Postblur_multiblur_rotation;
static f32 Postblur_multiblur_scale;
static s32 Postblur_multiblur_blend;
static f32 Postblur_multiblur_r;
static f32 Postblur_multiblur_g;
static f32 Postblur_multiblur_b;
static f32 Postblur_multiblur_a;
static f32 Postblur_multiblur_area;
static f32 Postblur_multiblur_center_x;
static f32 Postblur_multiblur_center_y;
static s32 Postblur_rippeblur_num;
static s32 Postblur_rippeblur_blend;
static f32 Postblur_rippeblur_power;
static f32 Postblur_rippeblur_area[5];
static f32 Postblur_rippeblur_center_x[5];
static f32 Postblur_rippeblur_center_y[5];
static f32 Postblur_rippeblur_time[5];
static s32 Postblur_distortionblur_blend;
static f32 Postblur_distortionblur_r;
static f32 Postblur_distortionblur_g;
static f32 Postblur_distortionblur_b;
static f32 Postblur_distortionblur_a;
static f32 Postblur_distortionblur_area_x;
static f32 Postblur_distortionblur_area_y;
static f32 Postblur_distortionblur_center_x;
static f32 Postblur_distortionblur_center_y;
static f32 Postblur_distortionblur_speed;
static f32 Postblur_distortionblur_distor1;
static f32 Postblur_distortionblur_distor2;
static s32 Postblur_distortionblur_speedmode;
static f32 Postblur_distortionblur_moyaalp;
static f32 Postblur_distortionblur_moyarotspd;
static f32 Postblur_distortionblur_moya_r;
static f32 Postblur_distortionblur_moya_g;
static f32 Postblur_distortionblur_moya_b;
static f32 Postblur_distortionblur_moya_sizemul;
static s32 Postblur_filter_blend;
static f32 Postblur_filter_r;
static f32 Postblur_filter_g;
static f32 Postblur_filter_b;
static f32 Postblur_filter_a;
static s32 Postblur_multifilter_blend;
static f32 Postblur_multifilter_r;
static f32 Postblur_multifilter_g;
static f32 Postblur_multifilter_b;
static f32 Postblur_multifilter_a;
static f32 Postblur_multifilter_area;
static f32 Postblur_multifilter_center_x;
static f32 Postblur_multifilter_center_y;
static s32 Postblur_encountblur_blend;
static bool PPSV2_update;
static s32 PPSV2_bloom_type;
static f32 PPSV2_bloom_btl_Default;
static f32 PPSV2_bloom_btl_max;
static bool PPSV2_dof_update;
static bool PPSV2_dof_use;
static f32 PPSV2_dof1;
static f32 PPSV2_dof2;
static f32 PPSV2_dof3;
static bool PPSV2_StatusMode;
static s32 PPSV2_StatusDevilId;
static f32 PShadow_CamX;
static f32 PShadow_CamY;
static f32 PShadow_CamZ;
static f32 PShadow_RotX;
static f32 PShadow_RotY;
static f32 PShadow_CamSize;
static f32 PShadow_CamFar;
static f32 PShadow_OnOff;
static f32 PShadow_Alp;
static f32 PShadow_ClipX;
static f32 PShadow_ClipY;
static f32 PShadow_ClipZ;
static f32 PShadow_VecClipOnOff;
static f32 PShadow_YClipOnOff;
static f32 PShadow2_CamX;
static f32 PShadow2_CamY;
static f32 PShadow2_CamZ;
static f32 PShadow2_RotX;
static f32 PShadow2_RotY;
static f32 PShadow2_CamSize;
static f32 PShadow2_CamFar;
static f32 PShadow2_OnOff;
static f32 PShadow2_Alp;
static f32 PShadow2_ClipX;
static f32 PShadow2_ClipY;
static f32 PShadow2_ClipZ;
static f32 PShadow2_VecClipOnOff;
static f32 PShadow2_YClipOnOff;
static bool PShadow_TexClipMode;
static bool UnityEx_SkyFilterSkip;
static f32 BattleMarukageAlpMul;
static f32 RunTime;
static dds3Effect_PartialMultiBlurParam_t *mulblur;
static dds3Effect_DistortionBlurParam_t *distblur;
static dds3Effect_RippleBlurParam_t *ripblur;
static dds3Effect_Blur_t *blur2;
static dds3Effect_Filter_t *filter2;
static dds3Effect_PartialMultiFilterParam_t *mfilter;

void Draw(s32 x, s32 y, _FRQ *frq, s32 colno);
dds3Effect_Blur_t *Eve_BlurGetParam(void);
void Eve_BlurOFF(void);
void Eve_BlurON(void);
void Eve_BlurSetParam(dds3Effect_Blur_t *pParam);
dds3Effect_DistortionBlurParam_t *Eve_DistortionBlurEditorGetParams(void);
void Eve_DistortionBlurOFF(void);
void Eve_DistortionBlurON(void);
void Eve_DistortionBlurSetParam(dds3Effect_DistortionBlurParam_t *pParam);
dds3Effect_Filter_t *Eve_FilterEditorGetParams(void);
void Eve_FilterOFF(void);
void Eve_FilterON(void);
void Eve_FilterSetParam(dds3Effect_Filter_t *pParam);
dds3Effect_PartialMultiBlurParam_t *Eve_PartialMultiBlurEditorGetParams(void);
void Eve_PartialMultiBlurOFF(void);
void Eve_PartialMultiBlurON(void);
void Eve_PartialMultiBlurSetParam(dds3Effect_PartialMultiBlurParam_t *pParam);
dds3Effect_PartialMultiFilterParam_t *Eve_PartialMultiFilterEditorGetParams(void);
void Eve_PartialMultiFilterOFF(void);
void Eve_PartialMultiFilterON(void);
void Eve_PartialMultiFilterSetParam(dds3Effect_PartialMultiFilterParam_t *pParam);
dds3Effect_RippleBlurParam_t *Eve_RippleBlurEditorGetParams(void);
void Eve_RippleBlurOFF(void);
void Eve_RippleBlurON(void);
void Eve_RippleBlurSetParam(dds3Effect_RippleBlurParam_t *pParam);
bool IsStartModelLoaded(void);
void Lerp(f32 aRatio);
void Log(char *fmt, void **parray);
void Normalize(void);
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix);
u64 SDF_GS_SET_RGBAQ(u8 r, u8 g, u8 b, u8 a, s32 q);
u64 SDF_GS_SET_TEST(u8 ate, u8 atst, u8 aref, u8 afail, u8 date, u8 datm, u8 zte, u32 ztst);
u64 SDF_GS_SET_XYZ2(u16 x, u16 y, u32 z);
u32 SDF_VIF_SET_DIRECT(u32 addr);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETVECTOR_W(void);
f32 SDF_VU0__GETVECTOR_X(void);
f32 SDF_VU0__GETVECTOR_Y(void);
f32 SDF_VU0__GETVECTOR_Z(void);
f32 SDF_VU0__INNERPRODUCT(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__SETVECTOR_W(f32 v);
void SDF_VU0__SETVECTOR_Z(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SWAPVECTOR_A_B(void);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void ToMatrix(void);
void dds3DrawEnv_t__Clear(dds3DrawEnv_t *this);
void dds3Effect_Blur_t__Clear(dds3Effect_Blur_t *this);
void dds3Effect_DistortionBlurParam_t__Clear(dds3Effect_DistortionBlurParam_t *this);
void dds3Effect_Filter_t__Clear(dds3Effect_Filter_t *this);
void dds3Effect_PartialMultiBlurParam_t__Clear(dds3Effect_PartialMultiBlurParam_t *this);
void dds3Effect_PartialMultiFilterParam_t__Clear(dds3Effect_PartialMultiFilterParam_t *this);
void dds3Effect_RippleBlurParam_t__Clear(dds3Effect_RippleBlurParam_t *this);
void dds3FadeClear(void);
f32 dds3GetRandFloatA(char *name);
void dds3RotationArc(void);
void evtHokanBlur2(s32 hokan, f32 ratio, dds3Effect_Blur_t *key1, dds3Effect_Blur_t *key2, dds3Effect_Blur_t **d);
void evtHokanDistBlur(s32 hokan, f32 ratio, dds3Effect_DistortionBlurParam_t *key1, dds3Effect_DistortionBlurParam_t *key2, dds3Effect_DistortionBlurParam_t **d);
void evtHokanFilter(s32 hokan, f32 ratio, dds3Effect_Filter_t *key1, dds3Effect_Filter_t *key2, dds3Effect_Filter_t **d);
void evtHokanMultBlur(s32 hokan, f32 ratio, dds3Effect_PartialMultiBlurParam_t *key1, dds3Effect_PartialMultiBlurParam_t *key2, dds3Effect_PartialMultiBlurParam_t **d);
void evtHokanMultFilter(s32 hokan, f32 ratio, dds3Effect_PartialMultiFilterParam_t *key1, dds3Effect_PartialMultiFilterParam_t *key2, dds3Effect_PartialMultiFilterParam_t **d);
void evtHokanRipBlur(s32 hokan, f32 ratio, dds3Effect_RippleBlurParam_t *key1, dds3Effect_RippleBlurParam_t *key2, dds3Effect_RippleBlurParam_t **d);
void sdf3DMakeScreenParam(sdf3DScreenParam_t **aParam);
f32 sdfFabs(f32 c);
void setdraw_xy(sdfIVector2_t ***xy);

// 0x17bbe60
void AllClrDrawFlag(void) {
  dds3DrawFlag = 0;
}

// 0x17bbfe0
void ClrDrawFlag(u32 flag) {
  struct dds3KernelDraw_StaticFields **p_static_fields;

  if (flag == 0x2000000)
  {
    if ((dds3DrawStopCount & 0x8000) == 0)
    {
      dds3DrawFlag &= ~0x2000000u;
      (*p_static_fields)->dds3DrawStopCount = 0;
    }
  }
  else
  {
    dds3DrawFlag &= ~flag;
  }
}

// 0x17c6ed0
void DofOff(void) {
  PPSV2_dof_update = 1;
  PPSV2_dof_use = 0;
}

// 0x17c6e50
void DofOn(void) {
  PPSV2_dof_update = 1;
  PPSV2_dof_use = 1;
}

// 0x17c6f50
void DofSet(f32 dof1, f32 dof2, f32 dof3) {
  PPSV2_dof_update = 1;
  PPSV2_dof_use = 1;
  PPSV2_dof1 = dof1;
  PPSV2_dof2 = dof2;
  PPSV2_dof3 = dof3;
}

// 0x17bc130
void DrawStopExec(void) {
  struct dds3KernelDraw_StaticFields **p_static_fields;
  u32 dds3DrawStopCount;
  u32 v7;

  if (dds3DrawStopCount)
  {
    dds3DrawStopCount = dds3DrawStopCount - 1;
    v7 = dds3DrawStopCount;
    if ((v7 & 0x8000) != 0)
    {
      if ((v7 & 0x7FFF) == 0)
      {
        dds3DrawFlag &= ~0x2000000u;
        (*p_static_fields)->dds3DrawStopCount = 0;
      }
    }
  }
}

// 0x17bc0c0
u32 GetDrawFlag(void) {
  return dds3DrawFlag;
}

// 0x17c6de0
void ScreenStop1(void) {
  Postblur_DrawStop = 1;
}

// 0x17bbed0
void SetDrawFlag(u32 flag, u32 cnt) {
  if (flag != 0x2000000)
    goto LABEL_22;
  if ((dds3DrawFlag & 0x40000000) == 0)
  {
LABEL_22:
    dds3DrawFlag |= flag;
    if (flag == 0x2000000)
    {
      dds3DrawStopCount = cnt;
      if (cnt >= 2)
      {
        dds3DrawStopCount |= 0x8000u;
      }
    }
  }
}

// 0x17bc850
s32 dds3AllocRenderTexture(u16 sx, u16 sy, f32 aspect) {
  return 1;
}

// 0x17bd3a0
void dds3Blackout(bool sw) {
  System_String_o *v2;
  System_String_o *v3;
  System_Object_array *v5;
  struct System_Byte_array *fadergba;
  struct System_Byte_array *v10;
  struct System_Byte_array *v12;
  struct System_Byte_array *v14;
  bool v16[4];

  v16[0] = sw;
  v2 = sub_3C0020(v16);
  v3 = Concat_5224608("dds3BlackOut1 : ", v2);
  v5 = Empty_string_();
  Log(v3, v5, 0);
  else
  {
    if (!LODWORD(fadergba->max_length))
      goto LABEL_9;
  }
  fadergba->m_Items[0] = 0;
  v10 = fadergba;
  v10->m_Items[1] = 0;
  v12 = fadergba;
  v12->m_Items[2] = 0;
  v14 = fadergba;
  v14->m_Items[3] = v16[0] << 7;
}

// 0x17bd550
void dds3Blackout_24892752(s32 frame) {
  u64 *v3;
  System_String_o *v4;
  System_Object_array *v6;
  struct System_Byte_array *fadergba;
  struct System_Byte_array *v11;
  struct System_Byte_array *v13;
  struct System_Byte_array *v15;
  s32 v17;

  v17 = frame;
  v3 = sub_8D3950(s32, &v17);
  v4 = Concat("dds3BlackOut : ", v3);
  v6 = Empty_string_();
  Log(v4, v6, 0);
  else
  {
    if (!LODWORD(fadergba->max_length))
      goto LABEL_9;
  }
  fadergba->m_Items[0] = 0;
  v11 = fadergba;
  v11->m_Items[1] = 0;
  v13 = fadergba;
  v13->m_Items[2] = 0;
  v15 = fadergba;
  v15->m_Items[3] = 0x80;
  fadenow = 0;
  fademax = frame;
  dds3DrawFlag |= 3u;
}

// 0x17c0f20
void dds3Blur2Off(s32 frame) {
  blur2abase = HIBYTE(blur2target->abgr);
  blur2atarget = 0;
  blur2now = 0;
  blur2max = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x20000u;
  }
  else
  {
    dds3DrawFlag &= ~0x20000u;
    dds3DrawFlag &= ~0x40000u;
    else
    {
      Eve_BlurOFF();
    }
  }
}

// 0x17c0de0
void dds3Blur2On(s32 frame) {
  dds3Effect_Blur_t_o *blur2target;

  blur2abase = 0;
  blur2atarget = HIBYTE(blur2target->abgr);
  blur2now = 0;
  blur2max = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x20000u;
  }
  else
  {
    dds3DrawFlag &= ~0x20000u;
    setdraw_xy(&blur2target->xy);
    Eve_BlurSetParam(blur2target);
    Eve_BlurON();
  }
}

// 0x17c0900
void dds3Blur2Swap(s32 frame) {
  dds3Effect_Blur_t_o *Param;
  struct System_Int32_array *pm;
  struct System_Int32_array *v7;
  s32 v8;
  struct System_Int32_array *v9;
  struct System_Int32_array *v10;
  s32 v12;
  struct sdfIVector2_t_array *xy;
  struct sdfIVector2_t_array *v16;
  struct System_Int32_array *v17;
  struct System_Int32_array *v18;
  s32 v19;
  struct sdfIVector2_t_array *v20;
  struct sdfIVector2_t_array *v22;
  struct System_Int32_array *v23;
  struct System_Int32_array *v25;
  s32 v27;
  struct sdfIVector2_t_array *v29;
  struct sdfIVector2_t_array *v31;
  struct System_Int32_array *v32;
  struct System_Int32_array *v33;
  s32 v34;
  struct sdfIVector2_t_array *v35;
  struct sdfIVector2_t_array *v37;
  struct System_Int32_array *v38;
  struct System_Int32_array *v40;
  s32 v42;
  dds3Effect_Blur_t_o *blur2target;

  Param = Eve_BlurGetParam();
  blur2base->abgr = Param->abgr;
  blur2base->blend = Param->blend;
  blur2base->rotate = Param->rotate;
  blur2base->scale = Param->scale;
  pm = blur2base->center->pm;
  v7 = Param->center->pm;
  v8 = v7->m_Items[0];
  pm->m_Items[0] = v8;
  v9 = blur2base->center->pm;
  v10 = Param->center->pm;
  v12 = v10->m_Items[1];
  v9->m_Items[1] = v12;
  xy = blur2base->xy;
  v16 = Param->xy;
  v17 = xy->m_Items[0]->pm;
  v18 = v16->m_Items[0]->pm;
  v19 = v18->m_Items[0];
  v17->m_Items[0] = v19;
  v20 = blur2base->xy;
  v22 = Param->xy;
  v23 = v20->m_Items[0]->pm;
  v25 = v22->m_Items[0]->pm;
  v27 = v25->m_Items[1];
  v23->m_Items[1] = v27;
  v29 = blur2base->xy;
  v31 = Param->xy;
  v32 = v29->m_Items[1]->pm;
  v33 = v31->m_Items[1]->pm;
  v34 = v33->m_Items[0];
  v32->m_Items[0] = v34;
  v35 = blur2base->xy;
  v37 = Param->xy;
  v38 = v35->m_Items[1]->pm;
  v40 = v37->m_Items[1]->pm;
  v42 = v40->m_Items[1];
  v38->m_Items[1] = v42;
  blur2swapnow = 0;
  blur2swapmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x40000u;
  }
  else
  {
    dds3DrawFlag &= ~0x40000u;
    setdraw_xy(&blur2target->xy);
    Eve_BlurSetParam(blur2target);
  }
}

// 0x17c2a50
void dds3BlurUpdate(void) {
  u32 v2;
  u32 v3;
  dds3KernelDraw_c *v4;
  u32 blur2swapnow;
  f32 v13;
  dds3Effect_Blur_t_o *blur2base;
  dds3Effect_Blur_t_o *blur2target;
  dds3Effect_Blur_t_o *blur2;
  u32 blur2now;
  struct System_Int32_array *pm;
  struct System_Int32_array *v25;
  s32 v26;
  struct System_Int32_array *v28;
  struct System_Int32_array *v29;
  s32 v31;
  struct sdfIVector2_t_array *xy;
  struct sdfIVector2_t_array *v36;
  struct System_Int32_array *v37;
  struct System_Int32_array *v38;
  s32 v39;
  struct sdfIVector2_t_array *v41;
  struct sdfIVector2_t_array *v43;
  struct System_Int32_array *v44;
  struct System_Int32_array *v46;
  s32 v48;
  struct sdfIVector2_t_array *v51;
  struct sdfIVector2_t_array *v53;
  struct System_Int32_array *v54;
  struct System_Int32_array *v55;
  s32 v56;
  struct sdfIVector2_t_array *v58;
  struct sdfIVector2_t_array *v60;
  struct System_Int32_array *v61;
  struct System_Int32_array *v63;
  s32 v65;
  s32 blur2abase;
  s32 v70;
  s32 v71;
  dds3Effect_Blur_t_o *v73;
  u32 mulblurswapnow;
  f32 v87;
  dds3Effect_PartialMultiBlurParam_t_o *mulblurbase;
  dds3Effect_PartialMultiBlurParam_t_o *mulblurtarget;
  dds3Effect_PartialMultiBlurParam_t_o *mulblur;
  u32 mulblurnow;
  struct System_Int32_array *v97;
  struct System_Int32_array *v98;
  s32 v99;
  struct System_Int32_array *v101;
  struct System_Int32_array *v102;
  s32 v104;
  struct sdfIVector2_t_array *v107;
  struct System_Int32_array *v109;
  struct sdfIVector2_t_array *v110;
  struct System_Int32_array *v111;
  s32 v112;
  struct sdfIVector2_t_array *v114;
  struct System_Int32_array *v116;
  struct sdfIVector2_t_array *v117;
  struct System_Int32_array *v119;
  s32 v121;
  struct sdfIVector2_t_array *v124;
  struct sdfIVector2_t_array *v126;
  struct System_Int32_array *v127;
  struct System_Int32_array *v128;
  s32 v129;
  struct sdfIVector2_t_array *v131;
  struct sdfIVector2_t_array *v133;
  struct System_Int32_array *v134;
  struct System_Int32_array *v136;
  s32 v138;
  s32 mulblurabase;
  s32 v143;
  s32 v144;
  dds3Effect_PartialMultiBlurParam_t_o *v145;
  u32 distblurswapnow;
  f32 v159;
  dds3Effect_DistortionBlurParam_t_o *distblurbase;
  dds3Effect_DistortionBlurParam_t_o *distblurtarget;
  dds3Effect_DistortionBlurParam_t_o *distblur;
  u32 distblurnow;
  struct System_Int32_array *v169;
  struct System_Int32_array *v170;
  s32 v171;
  struct System_Int32_array *v173;
  struct System_Int32_array *v174;
  s32 v176;
  s32 distblurabase;
  s32 v181;
  s32 v182;
  dds3Effect_DistortionBlurParam_t_o *v183;
  u32 ripblurswapnow;
  f32 v191;
  dds3Effect_RippleBlurParam_t_o *ripblurbase;
  dds3Effect_RippleBlurParam_t_o *ripblurtarget;
  dds3Effect_RippleBlurParam_t_o *ripblur;
  u32 ripblurnow;
  struct System_Int32_array *v201;
  struct System_Int32_array *v202;
  s32 v203;
  struct System_Int32_array *v205;
  struct System_Int32_array *v206;
  s32 v208;
  s32 ripblurabase;
  s32 v213;
  s32 v214;
  dds3Effect_RippleBlurParam_t_o *v215;
  u32 filter2swapnow;
  f32 v223;
  dds3Effect_Filter_t_o *filter2base;
  dds3Effect_Filter_t_o *filter2target;
  dds3Effect_Filter_t_o *filter2;
  u32 filter2now;
  struct sdfIVector2_t_array *v234;
  struct sdfIVector2_t_array *v236;
  struct System_Int32_array *v237;
  struct System_Int32_array *v238;
  s32 v239;
  struct sdfIVector2_t_array *v241;
  struct sdfIVector2_t_array *v243;
  struct System_Int32_array *v244;
  struct System_Int32_array *v246;
  s32 v248;
  struct sdfIVector2_t_array *v251;
  struct sdfIVector2_t_array *v253;
  struct System_Int32_array *v254;
  struct System_Int32_array *v255;
  s32 v256;
  struct sdfIVector2_t_array *v258;
  struct sdfIVector2_t_array *v260;
  struct System_Int32_array *v261;
  struct System_Int32_array *v263;
  s32 v265;
  s32 filter2abase;
  s32 v270;
  s32 v271;
  dds3Effect_Filter_t_o *v273;
  u32 mfilterswapnow;
  f32 v285;
  dds3Effect_PartialMultiFilterParam_t_o *mfilterbase;
  dds3Effect_PartialMultiFilterParam_t_o *mfiltertarget;
  dds3Effect_PartialMultiFilterParam_t_o *mfilter;
  u32 mfilternow;
  struct System_Int32_array *v295;
  struct System_Int32_array *v296;
  s32 v297;
  struct System_Int32_array *v299;
  struct System_Int32_array *v300;
  s32 v302;
  struct sdfIVector2_t_array *v306;
  struct System_Int32_array *v308;
  struct sdfIVector2_t_array *v309;
  struct System_Int32_array *v310;
  s32 v311;
  struct sdfIVector2_t_array *v313;
  struct System_Int32_array *v315;
  struct sdfIVector2_t_array *v316;
  struct System_Int32_array *v318;
  s32 v320;
  struct sdfIVector2_t_array *v323;
  struct sdfIVector2_t_array *v325;
  struct System_Int32_array *v326;
  struct System_Int32_array *v327;
  s32 v328;
  struct sdfIVector2_t_array *v330;
  struct sdfIVector2_t_array *v332;
  struct System_Int32_array *v333;
  struct System_Int32_array *v335;
  s32 v337;
  s32 mfilterabase;
  s32 v342;
  s32 v343;
  dds3Effect_PartialMultiFilterParam_t_o *v344;

  else
  {
    if ((dds3DrawFlag & 0x800) == 0)
      goto LABEL_28;
  }
  ++blurnow;
  dds3ScreenBlurAlpha = bluralphabase + (bluralphatarget - bluralphabase) * blurnow / blurmax;
  dds3ScreenBlurScale = blurscalebase + (blurscaletarget - blurscalebase) * blurnow / blurmax;
  if (!dds3ScreenBlurAlpha)
  {
    if (!dds3ScreenBlurScale)
    {
      else
      {
        dds3ScreenBlurFlag = 0;
        if ((v4->_2.bitflags2 & 2) == 0)
          goto LABEL_27;
      }
      goto LABEL_18;
    }
  }
  dds3ScreenBlurFlag = 1;
  if ((v4->_2.bitflags2 & 2) != 0)
  {
LABEL_18:
  }
LABEL_27:
  if (blurnow >= blurmax)
  {
    dds3DrawFlag &= ~0x800u;
    if ((v4->_2.bitflags2 & 2) == 0)
      goto LABEL_59;
    goto LABEL_29;
  }
LABEL_28:
  if ((v4->_2.bitflags2 & 2) == 0)
    goto LABEL_59;
LABEL_29:
LABEL_59:
  if ((dds3DrawFlag & 0x40000) == 0)
    goto LABEL_66;
LABEL_31:
  if (blur2swapnow < blur2swapmax)
  {
    blur2swapnow = blur2swapnow + 1;
  }
  LOWORD(v2) = blur2swapnow;
  LOWORD(v3) = blur2swapmax;
  v13 = v2 / v3;
  evtHokanBlur2(1, v13, blur2base, blur2target, &blur2);
  setdraw_xy(&blur2->xy);
  Eve_BlurSetParam(blur2);
  if (HIBYTE(blur2->abgr))
  {
    Eve_BlurON();
    {
LABEL_53:
    }
  }
  else
  {
    Eve_BlurOFF();
      goto LABEL_53;
  }
  if (blur2swapnow < blur2swapmax)
  {
LABEL_66:
    if ((v4->_2.bitflags2 & 2) == 0)
      goto LABEL_126;
    goto LABEL_67;
  }
  dds3DrawFlag &= ~0x40000u;
  if ((v4->_2.bitflags2 & 2) == 0)
  {
LABEL_126:
    if ((dds3DrawFlag & 0x20000) == 0)
      goto LABEL_145;
    goto LABEL_69;
  }
LABEL_67:
    goto LABEL_126;
  if ((dds3DrawFlag & 0x20000) == 0)
    goto LABEL_145;
LABEL_69:
  if (blur2now < blur2max)
  {
    blur2now = blur2now + 1;
  }
  blur2->abgr = blur2target->abgr;
  blur2->blend = blur2target->blend;
  blur2->rotate = blur2target->rotate;
  blur2->scale = blur2target->scale;
  pm = blur2target->center->pm;
  v25 = blur2->center->pm;
  v26 = pm->m_Items[0];
  v25->m_Items[0] = v26;
  v28 = blur2target->center->pm;
  v29 = blur2->center->pm;
  v31 = v28->m_Items[1];
  v29->m_Items[1] = v31;
  xy = blur2->xy;
  v36 = blur2target->xy;
  v37 = xy->m_Items[0]->pm;
  v38 = v36->m_Items[0]->pm;
  v39 = v38->m_Items[0];
  v37->m_Items[0] = v39;
  v41 = blur2->xy;
  v43 = blur2target->xy;
  v44 = v41->m_Items[0]->pm;
  v46 = v43->m_Items[0]->pm;
  v48 = v46->m_Items[1];
  v44->m_Items[1] = v48;
  v51 = blur2->xy;
  v53 = blur2target->xy;
  v54 = v51->m_Items[1]->pm;
  v55 = v53->m_Items[1]->pm;
  v56 = v55->m_Items[0];
  v54->m_Items[0] = v56;
  v58 = blur2->xy;
  v60 = blur2target->xy;
  v61 = v58->m_Items[1]->pm;
  v63 = v60->m_Items[1]->pm;
  v65 = v63->m_Items[1];
  v61->m_Items[1] = v65;
  v70 = (blur2atarget - blur2abase) * blur2now / blur2max;
  v71 = v70 + blur2abase;
  HIBYTE(blur2->abgr) = v70 + blur2abase;
  setdraw_xy(&blur2->xy);
  v73 = blur2;
  Eve_BlurSetParam(v73);
  if (v71)
  {
    Eve_BlurON();
      goto LABEL_140;
  }
  else
  {
    Eve_BlurOFF();
      goto LABEL_140;
  }
LABEL_140:
  if (blur2now >= blur2max)
  {
    dds3DrawFlag &= ~0x20000u;
  }
LABEL_145:
  else
  {
    if ((dds3DrawFlag & 0x8000) == 0)
      goto LABEL_240;
  }
  if (mulblurswapnow < mulblurswapmax)
  {
    mulblurswapnow = mulblurswapnow + 1;
  }
  LOWORD(v2) = mulblurswapnow;
  LOWORD(v3) = mulblurswapmax;
  v87 = v2 / v3;
  evtHokanMultBlur(1, v87, mulblurbase, mulblurtarget, &mulblur);
  Eve_PartialMultiBlurSetParam(mulblur);
  if (HIBYTE(mulblur->Blur->abgr))
  {
    Eve_PartialMultiBlurON();
    {
LABEL_170:
    }
  }
  else
  {
    Eve_PartialMultiBlurOFF();
      goto LABEL_170;
  }
  if (mulblurswapnow < mulblurswapmax)
    goto LABEL_240;
  dds3DrawFlag &= ~0x8000u;
  if ((v4->_2.bitflags2 & 2) == 0)
    goto LABEL_241;
LABEL_181:
    goto LABEL_241;
  if ((dds3DrawFlag & 0x1000) == 0)
    goto LABEL_257;
LABEL_183:
  if (mulblurnow < mulblurmax)
  {
    mulblurnow = mulblurnow + 1;
  }
  mulblur->area = mulblurtarget->area;
  mulblur->Blur->abgr = mulblurtarget->Blur->abgr;
  mulblur->Blur->blend = mulblurtarget->Blur->blend;
  mulblur->Blur->rotate = mulblurtarget->Blur->rotate;
  mulblur->Blur->scale = mulblurtarget->Blur->scale;
  v97 = mulblurtarget->Blur->center->pm;
  v98 = mulblur->Blur->center->pm;
  v99 = v97->m_Items[0];
  v98->m_Items[0] = v99;
  v101 = mulblurtarget->Blur->center->pm;
  v102 = mulblur->Blur->center->pm;
  v104 = v101->m_Items[1];
  v102->m_Items[1] = v104;
  v107 = mulblur->Blur->xy;
  v109 = v107->m_Items[0]->pm;
  v110 = mulblurtarget->Blur->xy;
  v111 = v110->m_Items[0]->pm;
  v112 = v111->m_Items[0];
  v109->m_Items[0] = v112;
  v114 = mulblur->Blur->xy;
  v116 = v114->m_Items[0]->pm;
  v117 = mulblurtarget->Blur->xy;
  v119 = v117->m_Items[0]->pm;
  v121 = v119->m_Items[1];
  v116->m_Items[1] = v121;
  v124 = mulblur->Blur->xy;
  v126 = mulblurtarget->Blur->xy;
  v127 = v124->m_Items[1]->pm;
  v128 = v126->m_Items[1]->pm;
  v129 = v128->m_Items[0];
  v127->m_Items[0] = v129;
  v131 = mulblur->Blur->xy;
  v133 = mulblurtarget->Blur->xy;
  v134 = v131->m_Items[1]->pm;
  v136 = v133->m_Items[1]->pm;
  v138 = v136->m_Items[1];
  v134->m_Items[1] = v138;
  v143 = (mulbluratarget - mulblurabase) * mulblurnow / mulblurmax;
  v144 = v143 + mulblurabase;
  HIBYTE(mulblur->Blur->abgr) = v143 + mulblurabase;
  v145 = mulblur;
  Eve_PartialMultiBlurSetParam(v145);
  if (v144)
  {
    Eve_PartialMultiBlurON();
      goto LABEL_252;
  }
  else
  {
    Eve_PartialMultiBlurOFF();
      goto LABEL_252;
  }
LABEL_252:
  if (mulblurnow >= mulblurmax)
  {
    dds3DrawFlag &= ~0x1000u;
  }
LABEL_257:
  else
  {
    if ((dds3DrawFlag & 0x10000) == 0)
      goto LABEL_323;
  }
  if (distblurswapnow < distblurswapmax)
  {
    distblurswapnow = distblurswapnow + 1;
  }
  LOWORD(v2) = distblurswapnow;
  LOWORD(v3) = distblurswapmax;
  v159 = v2 / v3;
  evtHokanDistBlur(1, v159, distblurbase, distblurtarget, &distblur);
  Eve_DistortionBlurSetParam(distblur);
  if (HIBYTE(distblur->abgr))
  {
    Eve_DistortionBlurON();
    {
LABEL_282:
    }
  }
  else
  {
    Eve_DistortionBlurOFF();
      goto LABEL_282;
  }
  if (distblurswapnow < distblurswapmax)
    goto LABEL_323;
  dds3DrawFlag &= ~0x10000u;
  if ((v4->_2.bitflags2 & 2) == 0)
    goto LABEL_324;
LABEL_293:
    goto LABEL_324;
  if ((dds3DrawFlag & 0x2000) == 0)
    goto LABEL_337;
LABEL_295:
  if (distblurnow < distblurmax)
  {
    distblurnow = distblurnow + 1;
  }
  distblur->number = distblurtarget->number;
  distblur->interval = distblurtarget->interval;
  distblur->speed = distblurtarget->speed;
  distblur->abgr = distblurtarget->abgr;
  distblur->blend = distblurtarget->blend;
  distblur->rotate = distblurtarget->rotate;
  distblur->distortion = distblurtarget->distortion;
  v169 = distblurtarget->center->pm;
  v170 = distblur->center->pm;
  v171 = v169->m_Items[0];
  v170->m_Items[0] = v171;
  v173 = distblurtarget->center->pm;
  v174 = distblur->center->pm;
  v176 = v173->m_Items[1];
  v174->m_Items[1] = v176;
  distblur->area = distblurtarget->area;
  distblur->width = distblurtarget->width;
  v181 = (distbluratarget - distblurabase) * distblurnow / distblurmax;
  v182 = v181 + distblurabase;
  HIBYTE(distblur->abgr) = v181 + distblurabase;
  v183 = distblur;
  Eve_DistortionBlurSetParam(v183);
  if (v182)
  {
    Eve_DistortionBlurON();
      goto LABEL_332;
  }
  else
  {
    Eve_DistortionBlurOFF();
      goto LABEL_332;
  }
LABEL_332:
  if (distblurnow >= distblurmax)
  {
    dds3DrawFlag &= ~0x2000u;
  }
LABEL_337:
  else
  {
    if ((dds3DrawFlag & 0x1000000) == 0)
      goto LABEL_403;
  }
  if (ripblurswapnow < ripblurswapmax)
  {
    ripblurswapnow = ripblurswapnow + 1;
  }
  LOWORD(v2) = ripblurswapnow;
  LOWORD(v3) = ripblurswapmax;
  v191 = v2 / v3;
  evtHokanRipBlur(1, v191, ripblurbase, ripblurtarget, &ripblur);
  Eve_RippleBlurSetParam(ripblur);
  if (HIBYTE(ripblur->abgr))
  {
    Eve_RippleBlurON();
    {
LABEL_362:
    }
  }
  else
  {
    Eve_RippleBlurOFF();
      goto LABEL_362;
  }
  if (ripblurswapnow < ripblurswapmax)
    goto LABEL_403;
  dds3DrawFlag &= ~0x1000000u;
  if ((v4->_2.bitflags2 & 2) == 0)
    goto LABEL_404;
LABEL_373:
    goto LABEL_404;
  if ((dds3DrawFlag & 0x800000) == 0)
    goto LABEL_417;
LABEL_375:
  if (ripblurnow < ripblurmax)
  {
    ripblurnow = ripblurnow + 1;
  }
  ripblur->number = ripblurtarget->number;
  ripblur->speed = ripblurtarget->speed;
  ripblur->interval = ripblurtarget->interval;
  ripblur->abgr = ripblurtarget->abgr;
  ripblur->blend = ripblurtarget->blend;
  ripblur->rotate = ripblurtarget->rotate;
  ripblur->power = ripblurtarget->power;
  ripblur->frequency = ripblurtarget->frequency;
  v201 = ripblurtarget->center->pm;
  v202 = ripblur->center->pm;
  v203 = v201->m_Items[0];
  v202->m_Items[0] = v203;
  v205 = ripblurtarget->center->pm;
  v206 = ripblur->center->pm;
  v208 = v205->m_Items[1];
  v206->m_Items[1] = v208;
  ripblur->area = ripblurtarget->area;
  v213 = (ripbluratarget - ripblurabase) * ripblurnow / ripblurmax;
  v214 = v213 + ripblurabase;
  HIBYTE(ripblur->abgr) = v213 + ripblurabase;
  v215 = ripblur;
  Eve_RippleBlurSetParam(v215);
  if (v214)
  {
    Eve_RippleBlurON();
      goto LABEL_412;
  }
  else
  {
    Eve_RippleBlurOFF();
      goto LABEL_412;
  }
LABEL_412:
  if (ripblurnow >= ripblurmax)
  {
    dds3DrawFlag &= ~0x800000u;
  }
LABEL_417:
  else
  {
    if ((dds3DrawFlag & 0x100000) == 0)
      goto LABEL_506;
  }
  if (filter2swapnow < filter2swapmax)
  {
    filter2swapnow = filter2swapnow + 1;
  }
  LOWORD(v2) = filter2swapnow;
  LOWORD(v3) = filter2swapmax;
  v223 = v2 / v3;
  evtHokanFilter(1, v223, filter2base, filter2target, &filter2);
  setdraw_xy(&filter2->xy);
  Eve_FilterSetParam(filter2);
  if (HIBYTE(filter2->abgr))
  {
    Eve_FilterON();
    {
LABEL_442:
    }
  }
  else
  {
    Eve_FilterOFF();
      goto LABEL_442;
  }
  if (filter2swapnow < filter2swapmax)
    goto LABEL_506;
  dds3DrawFlag &= ~0x100000u;
  if ((v4->_2.bitflags2 & 2) == 0)
    goto LABEL_507;
LABEL_453:
    goto LABEL_507;
  if ((dds3DrawFlag & 0x80000) == 0)
    goto LABEL_521;
LABEL_455:
  if (filter2now < filter2max)
  {
    filter2now = filter2now + 1;
  }
  filter2->abgr = filter2target->abgr;
  filter2->blend = filter2target->blend;
  v234 = filter2->xy;
  v236 = filter2target->xy;
  v237 = v234->m_Items[0]->pm;
  v238 = v236->m_Items[0]->pm;
  v239 = v238->m_Items[0];
  v237->m_Items[0] = v239;
  v241 = filter2->xy;
  v243 = filter2target->xy;
  v244 = v241->m_Items[0]->pm;
  v246 = v243->m_Items[0]->pm;
  v248 = v246->m_Items[1];
  v244->m_Items[1] = v248;
  v251 = filter2->xy;
  v253 = filter2target->xy;
  v254 = v251->m_Items[1]->pm;
  v255 = v253->m_Items[1]->pm;
  v256 = v255->m_Items[0];
  v254->m_Items[0] = v256;
  v258 = filter2->xy;
  v260 = filter2target->xy;
  v261 = v258->m_Items[1]->pm;
  v263 = v260->m_Items[1]->pm;
  v265 = v263->m_Items[1];
  v261->m_Items[1] = v265;
  v270 = (filter2atarget - filter2abase) * filter2now / filter2max;
  v271 = v270 + filter2abase;
  HIBYTE(filter2->abgr) = v270 + filter2abase;
  setdraw_xy(&filter2->xy);
  v273 = filter2;
  Eve_FilterSetParam(v273);
  if (v271)
  {
    Eve_FilterON();
      goto LABEL_516;
  }
  else
  {
    Eve_FilterOFF();
      goto LABEL_516;
  }
LABEL_516:
  if (filter2now >= filter2max)
  {
    dds3DrawFlag &= ~0x80000u;
  }
LABEL_521:
  else
  {
    if ((dds3DrawFlag & 0x400000) == 0)
      goto LABEL_616;
  }
  if (mfilterswapnow < mfilterswapmax)
  {
    mfilterswapnow = mfilterswapnow + 1;
  }
  LOWORD(v2) = mfilterswapnow;
  LOWORD(v3) = mfilterswapmax;
  v285 = v2 / v3;
  evtHokanMultFilter(1, v285, mfilterbase, mfiltertarget, &mfilter);
  Eve_PartialMultiFilterSetParam(mfilter);
  if (HIBYTE(mfilter->Filter->abgr))
  {
    Eve_PartialMultiFilterON();
    {
LABEL_546:
    }
  }
  else
  {
    Eve_PartialMultiFilterOFF();
      goto LABEL_546;
  }
  if (mfilterswapnow >= mfilterswapmax)
  {
    dds3DrawFlag &= ~0x400000u;
    if ((v4->_2.bitflags2 & 2) == 0)
      goto LABEL_617;
    goto LABEL_557;
  }
LABEL_616:
  if ((v4->_2.bitflags2 & 2) == 0)
    goto LABEL_617;
LABEL_557:
LABEL_617:
  if ((dds3DrawFlag & 0x200000) == 0)
    return;
LABEL_559:
  if (mfilternow < mfiltermax)
  {
    mfilternow = mfilternow + 1;
  }
  mfilter->area = mfiltertarget->area;
  v295 = mfiltertarget->center->pm;
  v296 = mfilter->center->pm;
  v297 = v295->m_Items[0];
  v296->m_Items[0] = v297;
  v299 = mfiltertarget->center->pm;
  v300 = mfilter->center->pm;
  v302 = v299->m_Items[1];
  v300->m_Items[1] = v302;
  mfilter->Filter->abgr = mfiltertarget->Filter->abgr;
  mfilter->Filter->blend = mfiltertarget->Filter->blend;
  v306 = mfilter->Filter->xy;
  v308 = v306->m_Items[0]->pm;
  v309 = mfiltertarget->Filter->xy;
  v310 = v309->m_Items[0]->pm;
  v311 = v310->m_Items[0];
  v308->m_Items[0] = v311;
  v313 = mfilter->Filter->xy;
  v315 = v313->m_Items[0]->pm;
  v316 = mfiltertarget->Filter->xy;
  v318 = v316->m_Items[0]->pm;
  v320 = v318->m_Items[1];
  v315->m_Items[1] = v320;
  v323 = mfilter->Filter->xy;
  v325 = mfiltertarget->Filter->xy;
  v326 = v323->m_Items[1]->pm;
  v327 = v325->m_Items[1]->pm;
  v328 = v327->m_Items[0];
  v326->m_Items[0] = v328;
  v330 = mfilter->Filter->xy;
  v332 = mfiltertarget->Filter->xy;
  v333 = v330->m_Items[1]->pm;
  v335 = v332->m_Items[1]->pm;
  v337 = v335->m_Items[1];
  v333->m_Items[1] = v337;
  v342 = (mfilteratarget - mfilterabase) * mfilternow / mfiltermax;
  v343 = v342 + mfilterabase;
  HIBYTE(mfilter->Filter->abgr) = v342 + mfilterabase;
  v344 = mfilter;
  Eve_PartialMultiFilterSetParam(v344);
  if (v343)
  {
    Eve_PartialMultiFilterON();
      goto LABEL_628;
  }
  else
  {
    Eve_PartialMultiFilterOFF();
      goto LABEL_628;
  }
LABEL_628:
  if (mfilternow >= mfiltermax)
  {
    dds3DrawFlag &= ~0x200000u;
  }
}

// 0x17bc9b0
s32 dds3CheckRenderTexture(void) {
  return dds3RenderTex;
}

// 0x17c2080
void dds3DistBlurOff(s32 frame) {
  distblurabase = HIBYTE(distblurtarget->abgr);
  distbluratarget = 0;
  distblurnow = 0;
  distblurmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x2000u;
  }
  else
  {
    dds3DrawFlag &= ~0x2000u;
    dds3DrawFlag &= ~0x10000u;
    else
    {
      Eve_DistortionBlurOFF();
    }
  }
}

// 0x17c21b0
f32 dds3DistBlurOffRaito(void) {
  u32 v2;
  u32 distblurmax;
  f32 result;

  else
  {
    if ((dds3DrawFlag & 0x2000) == 0)
      return 0.0;
  }
  if (!distblurmax)
    return 0.0;
LABEL_9:
  LOWORD(v2) = distblurnow;
  result = v2 / distblurmax;
  if (distbluratarget)
    return 1.0 - result;
  return result;
}

// 0x17c1f20
void dds3DistBlurOn(s32 frame) {
  dds3Effect_DistortionBlurParam_t_o *distblurtarget;
  dds3Effect_DistortionBlurParam_t_o *v5;

  distblurabase = 0;
  distbluratarget = HIBYTE(distblurtarget->abgr);
  distblurnow = 0;
  distblurmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x2000u;
    Eve_DistortionBlurSetParam(distblurtarget);
    Eve_DistortionBlurOFF();
  }
  else
  {
    dds3DrawFlag &= ~0x2000u;
    v5 = distblurtarget;
    Eve_DistortionBlurSetParam(v5);
    Eve_DistortionBlurON();
  }
}

// 0x17c1c90
void dds3DistBlurSwap(s32 frame) {
  dds3Effect_DistortionBlurParam_t_o *Params;
  struct System_Int32_array *pm;
  struct System_Int32_array *v7;
  s32 v8;
  struct System_Int32_array *v9;
  struct System_Int32_array *v10;
  s32 v12;
  dds3Effect_DistortionBlurParam_t_o *distblurtarget;

  Params = Eve_DistortionBlurEditorGetParams();
  distblurbase->number = Params->number;
  distblurbase->interval = Params->interval;
  distblurbase->speed = Params->speed;
  distblurbase->abgr = Params->abgr;
  distblurbase->blend = Params->blend;
  distblurbase->rotate = Params->rotate;
  distblurbase->distortion = Params->distortion;
  pm = distblurbase->center->pm;
  v7 = Params->center->pm;
  v8 = v7->m_Items[0];
  pm->m_Items[0] = v8;
  v9 = distblurbase->center->pm;
  v10 = Params->center->pm;
  v12 = v10->m_Items[1];
  v9->m_Items[1] = v12;
  distblurbase->area = Params->area;
  distblurbase->width = Params->width;
  distblurswapnow = 0;
  distblurswapmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x10000u;
  }
  else
  {
    dds3DrawFlag &= ~0x10000u;
    Eve_DistortionBlurSetParam(distblurtarget);
  }
}

// 0x17beb40
void dds3DrawDistRipOverError(void) {
  ;
}

// 0x17beb50
void dds3DrawFade(void) {
  struct System_Byte_array *fadergba;
  u8 v5;
  struct sdfDmaTag_t_o *dmatag;
  struct sdfDmaTag_t_o *v9;
  struct sdfGrTagStdReg_t_o *alpha1;
  struct sdfGrTagStdReg_t_o *test1;
  s32 screen_wid;
  s32 screen_hei;
  struct System_Byte_array *v21;
  struct sdfGrTagStdReg_t_o *col0;
  u32 max_length;
  struct System_Byte_array *v24;
  u8 v25;
  struct sdfGrTagStdReg_t_o *xyz0;
  struct System_Byte_array *v31;
  struct sdfGrTagStdReg_t_o *col1;
  u32 v33;
  struct System_Byte_array *v34;
  u8 v35;
  struct System_Byte_array *v36;
  u8 v37;
  struct sdfGrTagStdReg_t_o *xyz1;
  s32 v45;

  if ((fadergba->m_Items[3] & 0x80u) != 0)
    v5 = 0x80;
  else
    v5 = fadergba->m_Items[3];
  fadepkt->dmatag->qwc = 10;
  fadepkt->dmatag->pad = 0;
  dmatag = fadepkt->dmatag;
  v45 = 0;
  dmatag->addr = sub_8D3950(s32, &v45);
  fadepkt->dmatag->dat0 = 0;
  v9 = fadepkt->dmatag;
  v9->dat1 = SDF_VIF_SET_DIRECT(0xAu);
  fadepkt->alpha1->reg = 66;
  alpha1 = fadepkt->alpha1;
  alpha1->data = SDF_GS_SET_ALPHA(1u, 0, 0, 0, 0);
  fadepkt->pabe->reg = 73;
  fadepkt->pabe->data = 0;
  fadepkt->fba1->reg = 74;
  fadepkt->fba1->data = 0;
  fadepkt->test1->reg = 71;
  test1 = fadepkt->test1;
  test1->data = SDF_GS_SET_TEST(1u, 1u, 0, 1u, 0, 0, 1u, 1u);
  fadepkt->col0->reg = 1;
  v21 = fadergba;
  col0 = fadepkt->col0;
  max_length = v21->max_length;
  v24 = v21;
  v25 = v21->m_Items[0];
  col0->data = SDF_GS_SET_RGBAQ(v25, v24->m_Items[1], v24->m_Items[2], v5, 1065353216);
  fadepkt->xyz0->reg = 5;
  xyz0 = fadepkt->xyz0;
  xyz0->data = SDF_GS_SET_XYZ2(0, 0, 0xFEFFFFu);
  fadepkt->col1->reg = 1;
  v31 = fadergba;
  col1 = fadepkt->col1;
  v33 = v31->max_length;
  v34 = v31;
  v35 = v31->m_Items[0];
  v36 = v34;
  v37 = v34->m_Items[1];
  col1->data = SDF_GS_SET_RGBAQ(v35, v37, v36->m_Items[2], v5, 1065353216);
  fadepkt->xyz1->reg = 5;
  xyz1 = fadepkt->xyz1;
  xyz1->data = SDF_GS_SET_XYZ2(screen_wid, screen_hei, 0xFEFFFFu);
  Draw(
    gfxMgr,
    "GdxFade",
    1u,
    fadepkt,
    0);
}

// 0x17be1f0
s32 dds3FadeCheck(void) {
  if (!IsStartModelLoaded())
    return 0;
LABEL_6:
  return (dds3DrawFlag & 3) != 0;
}

// 0x17bd720
void dds3FadeClear(void) {
  struct System_Byte_array *fadergba;
  struct System_Byte_array *v5;
  struct System_Byte_array *v7;
  struct System_Byte_array *v9;

  dds3DrawFlag &= 0xFFFFFFFC;
  fadergba->m_Items[0] = 0;
  v5 = fadergba;
  v5->m_Items[1] = 0;
  v7 = fadergba;
  v7->m_Items[2] = 0;
  v9 = fadergba;
  v9->m_Items[3] = 0;
}

// 0x17bda90
void dds3FadeColorGet(u32 *r, u32 *g, u32 *b, u32 *a) {
  struct System_Byte_array *fadergba;
  struct System_Byte_array *v11;
  struct System_Byte_array *v13;
  struct System_Byte_array *v15;

  else
  {
    if (!LODWORD(fadergba->max_length))
      goto LABEL_6;
  }
  *r = fadergba->m_Items[0];
  v11 = fadergba;
  *g = v11->m_Items[1];
  v13 = fadergba;
  *b = v13->m_Items[2];
  v15 = fadergba;
  *a = v15->m_Items[3];
}

// 0x17bd980
void dds3FadeColorSet(u32 r, u32 g, u32 b) {
  u8 v4;
  u8 v5;
  u8 v6;
  struct System_Byte_array *fadergba;
  struct System_Byte_array *v10;
  struct System_Byte_array *v12;

  v4 = b;
  v5 = g;
  v6 = r;
  else
  {
    if (!LODWORD(fadergba->max_length))
      goto LABEL_6;
  }
  fadergba->m_Items[0] = v6;
  v10 = fadergba;
  v10->m_Items[1] = v5;
  v12 = fadergba;
  v12->m_Items[2] = v4;
}

// 0x17be720
f32 dds3FadeGetAlphaF(void) {
  u32 v3;
  struct System_Byte_array *fadergba;

LABEL_7:
  else if (!IsStartModelLoaded())
  {
    return 0.0;
  }
  if ((dds3DrawFlag & 3) == 0)
    return 0.0;
LABEL_13:
  LOBYTE(v3) = fadergba->m_Items[3];
  return fminf(v3 * 0.0078125, 1.0);
}

// 0x17be890
f32 dds3FadeGetAlphaI(void) {
  u32 v2;
  struct System_Byte_array *fadergba;

  LOBYTE(v2) = fadergba->m_Items[3];
  return v2;
}

// 0x17be920
f32 dds3FadeGetColAverageF(void) {
  struct System_Byte_array *fadergba;
  u32 max_length;
  struct System_Byte_array *v7;
  s32 v8;

LABEL_7:
  else if (!IsStartModelLoaded())
  {
    return 0.0;
  }
  if ((dds3DrawFlag & 3) == 0)
    return 0.0;
LABEL_13:
  max_length = fadergba->max_length;
  v7 = fadergba;
  if (!max_length)
    goto LABEL_27;
LABEL_16:
  v8 = fadergba->m_Items[0];
  return fminf(fmaxf(((v7->m_Items[1] + v8 + v7->m_Items[2]) / 3.0) * 0.0078125, 0.0), 1.0);
}

// 0x17bdbe0
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame) {
  u8 v6;
  u8 v7;
  u8 v8;
  dds3KernelDraw_c *v9;
  struct System_Byte_array *fadergba;
  struct System_Byte_array *v12;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;
  struct System_Byte_array *v18;

  v6 = b;
  v7 = g;
  v8 = r;
  else
  {
    if (!LODWORD(fadergba->max_length))
      goto LABEL_6;
  }
  fadergba->m_Items[0] = v8;
  v12 = fadergba;
  v12->m_Items[1] = v7;
  v14 = fadergba;
  v14->m_Items[2] = v6;
  v16 = fadergba;
  v16->m_Items[3] = 0x80;
  fadenow = frame;
  fademax = frame;
  if (frame)
  {
    dds3DrawFlag |= 1u;
    dds3DrawFlag &= ~2u;
  }
  else
  {
    fadenow = 0;
    fademax = 0;
    v18 = fadergba;
    v18->m_Items[3] = 0;
    dds3FadeClear(v9);
  }
}

// 0x17bddd0
void dds3FadeIn2(u32 frame) {
  struct dds3KernelDraw_StaticFields **p_static_fields;
  s32 v6;
  struct System_Byte_array *fadergba;

  fadenow = frame;
  fademax = frame;
  if (frame)
  {
    dds3DrawFlag |= 1u;
    v6 = -3;
  }
  else
  {
    fadenow = 0;
    fademax = 0;
    fadergba->m_Items[3] = 0;
    v6 = -4;
  }
  (*p_static_fields)->dds3DrawFlag &= v6;
}

// 0x17bdee0
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame) {
  u8 v6;
  u8 v7;
  u8 v8;
  struct System_Byte_array *fadergba;
  struct System_Byte_array *v12;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;
  u32 v19;
  struct System_Byte_array *v20;

  v6 = b;
  v7 = g;
  v8 = r;
  else
  {
    if (!LODWORD(fadergba->max_length))
      goto LABEL_6;
  }
  fadergba->m_Items[0] = v8;
  v12 = fadergba;
  v12->m_Items[1] = v7;
  v14 = fadergba;
  v14->m_Items[2] = v6;
  v16 = fadergba;
  v16->m_Items[3] = 0;
  fadenow = 0;
  fademax = frame;
  if (frame)
  {
    dds3DrawFlag &= ~1u;
    v19 = dds3DrawFlag | 2;
  }
  else
  {
    fadenow = 0;
    fademax = 0;
    v20 = fadergba;
    v20->m_Items[3] = 0x80;
    v19 = dds3DrawFlag & 0xFFFFFFFC;
  }
  dds3DrawFlag = v19;
}

// 0x17be0d0
void dds3FadeOut2(u32 frame) {
  struct System_Byte_array *fadergba;

  fadenow = 0;
  fademax = frame;
  if (frame)
  {
    dds3DrawFlag &= ~1u;
    dds3DrawFlag |= 2u;
  }
  else
  {
    fadenow = 0;
    fademax = 0;
    fadergba->m_Items[3] = 0x80;
    dds3DrawFlag &= 0xFFFFFFFC;
  }
}

// 0x17bd840
void dds3FadeSet(u32 r, u32 g, u32 b, u32 a) {
  u8 v5;
  u8 v6;
  u8 v7;
  u8 v8;
  struct System_Byte_array *fadergba;
  struct System_Byte_array *v12;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;

  v5 = a;
  v6 = b;
  v7 = g;
  v8 = r;
  dds3DrawFlag &= 0xFFFFFFFC;
  fadergba->m_Items[0] = v8;
  v12 = fadergba;
  v12->m_Items[1] = v7;
  v14 = fadergba;
  v14->m_Items[2] = v6;
  v16 = fadergba;
  v16->m_Items[3] = v5;
}

// 0x17be2b0
void dds3FadeUpdate(void) {
  dds3KernelDraw_c *v3;
  u32 dds3DrawFlag;
  s32 v6;
  struct System_Byte_array *fadergba;
  struct dds3KernelDraw_StaticFields **p_static_fields;
  struct System_Byte_array *v11;
  s16 v13;
  s32 v14;
  s16 v16;
  struct System_Byte_array *v18;

LABEL_7:
  else if (!IsStartModelLoaded())
  {
    return;
  }
  else
  {
    if ((dds3DrawFlag & 3) == 0)
      return;
  }
  else
  {
    v6 = dds3DrawFlag & 3;
    if (!v6)
      goto LABEL_57;
  }
  if (v6 == 2)
  {
    if (fademax - 1 == fadenow)
    {
      fadergba->m_Items[3] = 0;
    }
    if (fadenow >= fademax)
    {
LABEL_31:
      dds3DrawFlag &= 0xFFFFFFFC;
      (*p_static_fields)->fadenow = 0;
      (*p_static_fields)->fademax = 0;
      return;
    }
  }
  else
  {
    if (fadenow == 1)
    {
      v11 = fadergba;
      v11->m_Items[3] = 0x80;
    }
    if (!fadenow)
      goto LABEL_31;
  }
LABEL_57:
  v13 = *&v3->_2.bitflags1;
  if ((v13 & 0x200) != 0)
  {
    v14 = v13 & 0x200;
    if ((dds3DrawFlag & 1) != 0)
      goto LABEL_59;
LABEL_66:
    v16 = 1;
    goto LABEL_70;
  }
  v14 = 0;
  if ((dds3DrawFlag & 1) == 0)
    goto LABEL_66;
LABEL_59:
  v16 = -1;
LABEL_70:
  fadenow += v16;
  v18 = fadergba;
  v18->m_Items[3] = (fadenow << 7) / fademax;
  if ((dds3DrawFlag & 1) != 0)
  {
    if (!fadenow)
      goto LABEL_94;
  }
  if ((dds3DrawFlag & 2) != 0)
  {
    if (fadenow == fademax)
    {
LABEL_94:
      fadenow = 0;
      fademax = 0;
      dds3DrawFlag &= 0xFFFFFFFC;
    }
  }
}

// 0x17bfa40
void dds3Filter2Off(s32 frame) {
  filter2abase = HIBYTE(filter2target->abgr);
  filter2atarget = 0;
  filter2now = 0;
  filter2max = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x80000u;
  }
  else
  {
    dds3DrawFlag &= ~0x80000u;
    dds3DrawFlag &= ~0x100000u;
    else
    {
      Eve_FilterOFF();
    }
  }
}

// 0x17bf900
void dds3Filter2On(s32 frame) {
  dds3Effect_Filter_t_o *filter2target;

  filter2abase = 0;
  filter2atarget = HIBYTE(filter2target->abgr);
  filter2now = 0;
  filter2max = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x80000u;
  }
  else
  {
    dds3DrawFlag &= ~0x80000u;
    setdraw_xy(&filter2target->xy);
    Eve_FilterSetParam(filter2target);
    Eve_FilterON();
  }
}

// 0x17bf500
void dds3Filter2Swap(s32 frame) {
  dds3Effect_Filter_t_o *Params;
  struct sdfIVector2_t_array *xy;
  struct sdfIVector2_t_array *v8;
  struct System_Int32_array *pm;
  struct System_Int32_array *v10;
  s32 v11;
  struct sdfIVector2_t_array *v12;
  struct sdfIVector2_t_array *v14;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;
  s32 v19;
  struct sdfIVector2_t_array *v21;
  struct sdfIVector2_t_array *v23;
  struct System_Int32_array *v24;
  struct System_Int32_array *v25;
  s32 v26;
  struct sdfIVector2_t_array *v27;
  struct sdfIVector2_t_array *v29;
  struct System_Int32_array *v30;
  struct System_Int32_array *v32;
  s32 v34;
  dds3Effect_Filter_t_o *filter2target;

  Params = Eve_FilterEditorGetParams();
  filter2base->abgr = Params->abgr;
  filter2base->blend = Params->blend;
  xy = filter2base->xy;
  v8 = Params->xy;
  pm = xy->m_Items[0]->pm;
  v10 = v8->m_Items[0]->pm;
  v11 = v10->m_Items[0];
  pm->m_Items[0] = v11;
  v12 = filter2base->xy;
  v14 = Params->xy;
  v15 = v12->m_Items[0]->pm;
  v17 = v14->m_Items[0]->pm;
  v19 = v17->m_Items[1];
  v15->m_Items[1] = v19;
  v21 = filter2base->xy;
  v23 = Params->xy;
  v24 = v21->m_Items[1]->pm;
  v25 = v23->m_Items[1]->pm;
  v26 = v25->m_Items[0];
  v24->m_Items[0] = v26;
  v27 = filter2base->xy;
  v29 = Params->xy;
  v30 = v27->m_Items[1]->pm;
  v32 = v29->m_Items[1]->pm;
  v34 = v32->m_Items[1];
  v30->m_Items[1] = v34;
  filter2swapnow = 0;
  filter2swapmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x100000u;
  }
  else
  {
    dds3DrawFlag &= ~0x100000u;
    setdraw_xy(&filter2target->xy);
    Eve_FilterSetParam(filter2target);
  }
}

// 0x17bc860
void dds3FreeRenderTexture(void) {
  dds3RenderTex = 0;
}

// 0x17bc250
void dds3InitDrawEnv(void) {
  struct dds3DrawEnv_t_array *v3;
  struct dds3DrawEnv_t_array *dds3DrawEnv;
  u64 *v6;
  struct dds3DrawEnv_t_array *v8;
  struct dds3DrawEnv_t_array *v12;
  u64 *v13;
  struct dds3DrawEnv_t_array *v15;
  u64 *v17;
  u64 *v20;
  u64 *v22;
  u64 *v24;
  u64 *v26;
  u64 *v28;
  u64 *v30;
  u64 *v32;
  u64 *v34;
  u64 *v36;
  u64 *v38;
  u64 *v40;
  u64 *v42;
  u64 *v44;
  u64 *v46;
  u64 *v48;
  u64 *v50;
  u64 *v52;

  sdf3DMakeScreenParam(&dds3ScreenParam);
  v3 = NewSpecific(dds3DrawEnv_t, 2u);
  dds3DrawEnv = v3;
  v6 = Allocate(dds3DrawEnv_t);
  dds3DrawEnv_t___ctor(v6);
  dds3DrawEnv->m_Items[0] = v6;
  v8 = dds3DrawEnv;
  dds3DrawEnv_t__Clear(v8->m_Items[0]);
  v12 = dds3DrawEnv;
  v13 = Allocate(dds3DrawEnv_t);
  dds3DrawEnv_t___ctor(v13);
  v12->m_Items[1] = v13;
  v15 = dds3DrawEnv;
  dds3DrawEnv_t__Clear(v15->m_Items[1]);
  v17 = Allocate(dds3Effect_PartialMultiBlurParam_t);
  dds3Effect_PartialMultiBlurParam_t___ctor(v17);
  mulblurbase = v17;
  dds3Effect_PartialMultiBlurParam_t__Clear(mulblurbase);
  v20 = Allocate(dds3Effect_PartialMultiBlurParam_t);
  dds3Effect_PartialMultiBlurParam_t___ctor(v20);
  mulblurtarget = v20;
  dds3Effect_PartialMultiBlurParam_t__Clear(mulblurtarget);
  v22 = Allocate(dds3Effect_DistortionBlurParam_t);
  dds3Effect_DistortionBlurParam_t___ctor(v22);
  distblurbase = v22;
  dds3Effect_DistortionBlurParam_t__Clear(distblurbase);
  v24 = Allocate(dds3Effect_DistortionBlurParam_t);
  dds3Effect_DistortionBlurParam_t___ctor(v24);
  distblurtarget = v24;
  dds3Effect_DistortionBlurParam_t__Clear(distblurtarget);
  v26 = Allocate(dds3Effect_RippleBlurParam_t);
  dds3Effect_RippleBlurParam_t___ctor(v26);
  ripblurbase = v26;
  dds3Effect_RippleBlurParam_t__Clear(ripblurbase);
  v28 = Allocate(dds3Effect_RippleBlurParam_t);
  dds3Effect_RippleBlurParam_t___ctor(v28);
  ripblurtarget = v28;
  dds3Effect_RippleBlurParam_t__Clear(ripblurtarget);
  v30 = Allocate(dds3Effect_Blur_t);
  dds3Effect_Blur_t___ctor(v30);
  blur2base = v30;
  dds3Effect_Blur_t__Clear(blur2base);
  v32 = Allocate(dds3Effect_Blur_t);
  dds3Effect_Blur_t___ctor(v32);
  blur2target = v32;
  dds3Effect_Blur_t__Clear(blur2target);
  v34 = Allocate(dds3Effect_Filter_t);
  dds3Effect_Filter_t___ctor(v34);
  filter2base = v34;
  dds3Effect_Filter_t__Clear(filter2base);
  v36 = Allocate(dds3Effect_Filter_t);
  dds3Effect_Filter_t___ctor(v36);
  filter2target = v36;
  dds3Effect_Filter_t__Clear(filter2target);
  v38 = Allocate(dds3Effect_PartialMultiFilterParam_t);
  dds3Effect_PartialMultiFilterParam_t___ctor(v38);
  mfilterbase = v38;
  dds3Effect_PartialMultiFilterParam_t__Clear(mfilterbase);
  v40 = Allocate(dds3Effect_PartialMultiFilterParam_t);
  dds3Effect_PartialMultiFilterParam_t___ctor(v40);
  mfiltertarget = v40;
  dds3Effect_PartialMultiFilterParam_t__Clear(mfiltertarget);
  v42 = Allocate(dds3Effect_PartialMultiBlurParam_t);
  dds3Effect_PartialMultiBlurParam_t___ctor(v42);
  mulblur = v42;
  dds3Effect_PartialMultiBlurParam_t__Clear(mulblur);
  v44 = Allocate(dds3Effect_DistortionBlurParam_t);
  dds3Effect_DistortionBlurParam_t___ctor(v44);
  distblur = v44;
  dds3Effect_DistortionBlurParam_t__Clear(distblur);
  v46 = Allocate(dds3Effect_RippleBlurParam_t);
  dds3Effect_RippleBlurParam_t___ctor(v46);
  ripblur = v46;
  dds3Effect_RippleBlurParam_t__Clear(ripblur);
  v48 = Allocate(dds3Effect_Blur_t);
  dds3Effect_Blur_t___ctor(v48);
  blur2 = v48;
  dds3Effect_Blur_t__Clear(blur2);
  v50 = Allocate(dds3Effect_Filter_t);
  dds3Effect_Filter_t___ctor(v50);
  filter2 = v50;
  dds3Effect_Filter_t__Clear(filter2);
  v52 = Allocate(dds3Effect_PartialMultiFilterParam_t);
  dds3Effect_PartialMultiFilterParam_t___ctor(v52);
  mfilter = v52;
  dds3Effect_PartialMultiFilterParam_t__Clear(mfilter);
}

// 0x17bc240
void dds3InitDrawEnvSub(s32 i) {
  ;
}

// 0x17bc840
void dds3InitRenderDrawEnv(void) {
  ;
}

// 0x17bd390
void dds3InitZClearDrawTag(void) {
  ;
}

// 0x17c0480
void dds3MFilterOff(s32 frame) {
  mfilterabase = HIBYTE(mfiltertarget->Filter->abgr);
  mfilteratarget = 0;
  mfilternow = 0;
  mfiltermax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x200000u;
  }
  else
  {
    dds3DrawFlag &= ~0x200000u;
    dds3DrawFlag &= ~0x400000u;
    else
    {
      Eve_PartialMultiFilterOFF();
    }
  }
}

// 0x17c0350
void dds3MFilterOn(s32 frame) {
  dds3Effect_PartialMultiFilterParam_t_o *mfiltertarget;

  mfilterabase = 0;
  mfilteratarget = HIBYTE(mfiltertarget->Filter->abgr);
  mfilternow = 0;
  mfiltermax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x200000u;
  }
  else
  {
    dds3DrawFlag &= ~0x200000u;
    Eve_PartialMultiFilterSetParam(mfiltertarget);
    Eve_PartialMultiFilterON();
  }
}

// 0x17bfd50
void dds3MFilterSwap(s32 frame) {
  dds3Effect_PartialMultiFilterParam_t_o *Params;
  struct System_Int32_array *pm;
  struct System_Int32_array *v7;
  s32 v8;
  struct System_Int32_array *v9;
  struct System_Int32_array *v10;
  s32 v12;
  struct sdfIVector2_t_array *xy;
  u64 *v16;
  struct sdfIVector2_t_array *v18;
  u64 *v19;
  struct sdfIVector2_t_array *v22;
  struct System_Int32_array *v24;
  struct sdfIVector2_t_array *v25;
  struct System_Int32_array *v26;
  s32 v27;
  struct sdfIVector2_t_array *v28;
  struct System_Int32_array *v30;
  struct sdfIVector2_t_array *v31;
  struct System_Int32_array *v33;
  s32 v35;
  struct sdfIVector2_t_array *v37;
  struct System_Int32_array *v39;
  struct sdfIVector2_t_array *v40;
  struct System_Int32_array *v41;
  s32 v42;
  struct sdfIVector2_t_array *v43;
  struct System_Int32_array *v45;
  struct sdfIVector2_t_array *v46;
  struct System_Int32_array *v48;
  s32 v50;
  dds3Effect_PartialMultiFilterParam_t_o *mfiltertarget;

  Params = Eve_PartialMultiFilterEditorGetParams();
  mfilterbase->area = Params->area;
  pm = mfilterbase->center->pm;
  v7 = Params->center->pm;
  v8 = v7->m_Items[0];
  pm->m_Items[0] = v8;
  v9 = mfilterbase->center->pm;
  v10 = Params->center->pm;
  v12 = v10->m_Items[1];
  v9->m_Items[1] = v12;
  mfilterbase->Filter->abgr = Params->Filter->abgr;
  mfilterbase->Filter->blend = Params->Filter->blend;
  xy = mfilterbase->Filter->xy;
  v16 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v16);
  xy->m_Items[0] = v16;
  v18 = mfilterbase->Filter->xy;
  v19 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v19);
  v18->m_Items[1] = v19;
  v22 = mfilterbase->Filter->xy;
  v24 = v22->m_Items[0]->pm;
  v25 = Params->Filter->xy;
  v26 = v25->m_Items[0]->pm;
  v27 = v26->m_Items[0];
  v24->m_Items[0] = v27;
  v28 = mfilterbase->Filter->xy;
  v30 = v28->m_Items[0]->pm;
  v31 = Params->Filter->xy;
  v33 = v31->m_Items[0]->pm;
  v35 = v33->m_Items[1];
  v30->m_Items[1] = v35;
  v37 = mfilterbase->Filter->xy;
  v39 = v37->m_Items[1]->pm;
  v40 = Params->Filter->xy;
  v41 = v40->m_Items[1]->pm;
  v42 = v41->m_Items[0];
  v39->m_Items[0] = v42;
  v43 = mfilterbase->Filter->xy;
  v45 = v43->m_Items[1]->pm;
  v46 = Params->Filter->xy;
  v48 = v46->m_Items[1]->pm;
  v50 = v48->m_Items[1];
  v45->m_Items[1] = v50;
  mfilterswapnow = 0;
  mfilterswapmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x400000u;
  }
  else
  {
    dds3DrawFlag &= ~0x400000u;
    Eve_PartialMultiFilterSetParam(mfiltertarget);
  }
}

// 0x17c18d0
void dds3MultiBlurOff(s32 frame) {
  mulblurabase = HIBYTE(mulblurtarget->Blur->abgr);
  mulbluratarget = 0;
  mulblurnow = 0;
  mulblurmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x1000u;
  }
  else
  {
    dds3DrawFlag &= ~0x1000u;
    dds3DrawFlag &= ~0x8000u;
    Eve_PartialMultiBlurOFF();
    Eve_PartialMultiBlurSetParam(mulblurtarget);
  }
}

// 0x17c17a0
void dds3MultiBlurOn(s32 frame) {
  dds3Effect_PartialMultiBlurParam_t_o *mulblurtarget;

  mulblurabase = 0;
  mulbluratarget = HIBYTE(mulblurtarget->Blur->abgr);
  mulblurnow = 0;
  mulblurmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x1000u;
  }
  else
  {
    dds3DrawFlag &= ~0x1000u;
    Eve_PartialMultiBlurSetParam(mulblurtarget);
    Eve_PartialMultiBlurON();
  }
}

// 0x17c1270
void dds3MultiBlurSwap(s32 frame) {
  dds3Effect_PartialMultiBlurParam_t_o *Params;
  struct System_Int32_array *pm;
  struct System_Int32_array *v7;
  s32 v8;
  struct System_Int32_array *v9;
  struct System_Int32_array *v10;
  s32 v12;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *v16;
  struct sdfIVector2_t_array *v17;
  struct System_Int32_array *v18;
  s32 v19;
  struct sdfIVector2_t_array *v20;
  struct System_Int32_array *v22;
  struct sdfIVector2_t_array *v23;
  struct System_Int32_array *v25;
  s32 v27;
  struct sdfIVector2_t_array *v29;
  struct System_Int32_array *v31;
  struct sdfIVector2_t_array *v32;
  struct System_Int32_array *v33;
  s32 v34;
  struct sdfIVector2_t_array *v35;
  struct System_Int32_array *v37;
  struct sdfIVector2_t_array *v38;
  struct System_Int32_array *v40;
  s32 v42;
  dds3Effect_PartialMultiBlurParam_t_o *mulblurtarget;

  Params = Eve_PartialMultiBlurEditorGetParams();
  mulblurbase->area = Params->area;
  mulblurbase->Blur->abgr = Params->Blur->abgr;
  mulblurbase->Blur->blend = Params->Blur->blend;
  mulblurbase->Blur->rotate = Params->Blur->rotate;
  mulblurbase->Blur->scale = Params->Blur->scale;
  pm = mulblurbase->Blur->center->pm;
  v7 = Params->Blur->center->pm;
  v8 = v7->m_Items[0];
  pm->m_Items[0] = v8;
  v9 = mulblurbase->Blur->center->pm;
  v10 = Params->Blur->center->pm;
  v12 = v10->m_Items[1];
  v9->m_Items[1] = v12;
  xy = mulblurbase->Blur->xy;
  v16 = xy->m_Items[0]->pm;
  v17 = Params->Blur->xy;
  v18 = v17->m_Items[0]->pm;
  v19 = v18->m_Items[0];
  v16->m_Items[0] = v19;
  v20 = mulblurbase->Blur->xy;
  v22 = v20->m_Items[0]->pm;
  v23 = Params->Blur->xy;
  v25 = v23->m_Items[0]->pm;
  v27 = v25->m_Items[1];
  v22->m_Items[1] = v27;
  v29 = mulblurbase->Blur->xy;
  v31 = v29->m_Items[1]->pm;
  v32 = Params->Blur->xy;
  v33 = v32->m_Items[1]->pm;
  v34 = v33->m_Items[0];
  v31->m_Items[0] = v34;
  v35 = mulblurbase->Blur->xy;
  v37 = v35->m_Items[1]->pm;
  v38 = Params->Blur->xy;
  v40 = v38->m_Items[1]->pm;
  v42 = v40->m_Items[1];
  v37->m_Items[1] = v42;
  mulblurswapnow = 0;
  mulblurswapmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x8000u;
  }
  else
  {
    dds3DrawFlag &= ~0x8000u;
    Eve_PartialMultiBlurSetParam(mulblurtarget);
  }
}

// 0x17bc940
void dds3RenderTextureOFF(void) {
  dds3RenderTex = 0;
}

// 0x17bc8d0
s32 dds3RenderTextureON(void) {
  dds3RenderTex = 1;
  return 1;
}

// 0x17c2920
void dds3RipBlurOff(s32 frame) {
  ripblurabase = HIBYTE(ripblurtarget->abgr);
  ripbluratarget = 0;
  ripblurnow = 0;
  ripblurmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x800000u;
  }
  else
  {
    dds3DrawFlag &= ~0x800000u;
    dds3DrawFlag &= ~0x1000000u;
    else
    {
      Eve_RippleBlurOFF();
    }
  }
}

// 0x17c27c0
void dds3RipBlurOn(s32 frame) {
  dds3Effect_RippleBlurParam_t_o *ripblurtarget;
  dds3Effect_RippleBlurParam_t_o *v5;

  ripblurabase = 0;
  ripbluratarget = HIBYTE(ripblurtarget->abgr);
  ripblurnow = 0;
  ripblurmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x800000u;
    Eve_RippleBlurSetParam(ripblurtarget);
    Eve_RippleBlurOFF();
  }
  else
  {
    dds3DrawFlag &= ~0x800000u;
    v5 = ripblurtarget;
    Eve_RippleBlurSetParam(v5);
    Eve_RippleBlurON();
  }
}

// 0x17c2530
void dds3RipBlurSwap(s32 frame) {
  dds3Effect_RippleBlurParam_t_o *Params;
  struct System_Int32_array *pm;
  struct System_Int32_array *v7;
  s32 v8;
  struct System_Int32_array *v9;
  struct System_Int32_array *v10;
  s32 v12;
  dds3Effect_RippleBlurParam_t_o *ripblurtarget;

  Params = Eve_RippleBlurEditorGetParams();
  ripblurbase->number = Params->number;
  ripblurbase->speed = Params->speed;
  ripblurbase->interval = Params->interval;
  ripblurbase->abgr = Params->abgr;
  ripblurbase->blend = Params->blend;
  ripblurbase->rotate = Params->rotate;
  ripblurbase->power = Params->power;
  ripblurbase->frequency = Params->frequency;
  pm = ripblurbase->center->pm;
  v7 = Params->center->pm;
  v8 = v7->m_Items[0];
  pm->m_Items[0] = v8;
  v9 = ripblurbase->center->pm;
  v10 = Params->center->pm;
  v12 = v10->m_Items[1];
  v9->m_Items[1] = v12;
  ripblurbase->area = Params->area;
  ripblurswapnow = 0;
  ripblurswapmax = frame;
  if (frame)
  {
    dds3DrawFlag |= 0x1000000u;
  }
  else
  {
    dds3DrawFlag &= ~0x1000000u;
    Eve_RippleBlurSetParam(ripblurtarget);
  }
}

// 0x17c5430
void dds3RotationArc(void) {
  f32 v1;
  f32 v2;
  f32 v4;
  f32 v5;
  UnityEngine_Vector4_o v6;
  UnityEngine_Vector4_o v7;

  *&v7.x = 0;
  *&v7.z = 0;
  *&v6.x = 0;
  *&v6.z = 0;
  sub_854690(&v7.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v6.x, 0.0, 0.0, 0.0, 0.0);
  SDF_VU0__VECTOR_W_SET_ZERO();
  SDF_VU0__NORMALIZE();
  SDF_VU0__SWAPVECTOR_A_B();
  SDF_VU0__VECTOR_W_SET_ZERO();
  SDF_VU0__NORMALIZE();
  SDF_VU0__SWAPVECTOR_A_B();
  v1 = SDF_VU0__INNERPRODUCT();
  if (v1 >= 0.9999)
  {
    SDF_VU0__LOADVECTOR(v7);
  }
  else if (v1 <= -0.9999)
  {
    v4 = SDF_VU0__GETVECTOR_Y();
    if (sdfFabs(v4) >= 0.9999)
    {
      SDF_VU0__LOADIDENTITYVECTOR();
      SDF_VU0__VECTOR_W_SET_ZERO();
      SDF_VU0__SETVECTOR_Z(-1.0);
    }
    else
    {
      SDF_VU0__GETVECTOR_Z();
      sub_854930(&v6, 0);
      sub_854930(&v6, 1u);
      SDF_VU0__GETVECTOR_X();
      sub_854930(&v6, 2u);
      sub_854930(&v6, 3u);
      SDF_VU0__LOADVECTOR(v6);
      SDF_VU0__NORMALIZE();
    }
    v5 = SDF_VU0__INNERPRODUCT();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__SETVECTOR_W(v5);
  }
  else
  {
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__COPYVECTOR_C_TO_B();
    v2 = SDF_VU0__INNERPRODUCT();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__STOREVECTOR(&v6);
    SDF_VU0__SETVECTOR_W(v2);
    Normalize(0);
  }
}

// 0x17bca20
void dds3RunQuake(void) {
  u64 *v1;
  u32 *v2;
  u32 v5;
  u32 *v6;

  v1 = NewSpecific(f32, 2u);
  v2 = NewSpecific(f32, 2u);
  v5 = v2[6];
  v6 = v2;
  v2[8] = 1058642330;
  v2[9] = 1058642330;
  else
  {
    if (dds3QuakeFlag)
      goto LABEL_10;
  }
  SDF_VU0__LOADIDENTITYVECTOR();
  SDF_VU0__VECTOR_W_SET_ZERO();
  SDF_VU0__STOREVECTOR(&dds3CameraOffset);
}

// 0x17c6090
void dds3SceneLightUpdateFirst(void) {
  u32 v2;
  dds3KernelDraw_c *v3;
  u64 v4;
  s32 v5;
  s64 v6;
  s32 v7;
  struct System_UInt16_array *lightdirnow;
  struct sdf3DLight_t_array *dds3DirLights;
  u32 v12;
  struct System_UInt16_array *lightrgbnow;
  struct System_UInt16_array *v17;
  struct System_UInt16_array *lightrgbmax;
  u32 v20;
  f32 v22;
  struct System_UInt32_array *lightrgbbase;
  f32 v24;
  struct System_UInt32_array *lightrgbtarget;
  struct sdf3DLight_t_array *v28;
  struct System_UInt16_array *v31;
  struct System_UInt16_array *v33;
  u32 v34;
  struct System_UInt16_array *v39;
  struct System_UInt16_array *lightdirmax;
  u32 v42;
  f32 v44;
  struct UnityEngine_Vector4_array *lightdirquat;
  struct UnityEngine_Vector4_array *lightdirbase;
  struct sdf3DLight_t_array *v49;
  struct System_UInt16_array *v52;
  struct System_UInt16_array *v54;
  u32 v55;
  s32 v58;
  u32 v59;
  u32 v61;
  u32 v62;
  f32 v65;
  u32 v68;
  u32 v69;
  f32 v72;
  struct sdf3DFogParam_t_o *dds3FogParam;
  u32 v76;
  u32 v77;
  f32 v80;
  struct sdf3DFogParam_t_o *v81;
  struct sdf3DFogParam_t_o *v82;
  struct sdf3DFogParam_t_o *v83;
  struct sdf3DFogParam_t_o *v84;
  u32 v87;
  u32 v88;
  f32 v91;
  f32 softenbase;
  f32 softentarget;

  v4 = 0;
  v5 = 4;
  v6 = 44;
  do
  {
    if (!dds3DirLights->m_Items[v4])
    {
      Log("=============================dds3SceneLightUpdateFirst:xxxx", 0);
      v58 = dds3DrawFlag & ~(v5 | (2 * v5));
      goto LABEL_78;
    }
    else if ((dds3DrawFlag & v5) != 0)
    {
LABEL_17:
      Log("=============================dds3SceneLightUpdateFirst:0001", 0);
      ++lightrgbnow->m_Items[v4];
      v17 = lightrgbnow;
      v20 = v17->m_Items[v4];
      LOWORD(v12) = lightrgbmax->m_Items[v4];
      v22 = v20;
      v24 = v22 / v12;
      SDF_VU0__dds3ColorItoF(lightrgbbase->m_Items[v4]);
      SDF_VU0__SCALEVECTOR(1.0 - v24);
      SDF_VU0__COPYVECTOR_A_TO_B();
      SDF_VU0__dds3ColorItoF(lightrgbtarget->m_Items[v4]);
      SDF_VU0__SCALEVECTOR(v24);
      SDF_VU0__ADDVECTOR();
      v28 = dds3DirLights;
      SDF_VU0__STOREVECTOR(&v28->m_Items[v4]->color);
      v31 = lightrgbnow;
      v33 = lightrgbmax;
      v34 = v31->m_Items[v4];
      if (v34 >= v33->m_Items[v4])
      {
        dds3DrawFlag &= ~v5;
      }
    }
    if ((dds3DrawFlag & (2 * v5)) != 0)
    {
      else
      {
        if (v4 >= LODWORD(lightdirnow->max_length))
        {
LABEL_51:
        }
      }
      ++lightdirnow->m_Items[v4];
      v39 = lightdirnow;
      v42 = v39->m_Items[v4];
      LOWORD(v2) = lightdirmax->m_Items[v4];
      v44 = v42 / v2;
      SDF_VU0__LOADIDENTITYVECTOR();
      SDF_VU0__VECTOR_W_SET_ONE();
      SDF_VU0__LOADVECTOR_B(*(lightdirquat + v6 - 12), 0);
      Lerp(v44, 0);
      ToMatrix();
      SDF_VU0__LOADVECTOR(*(lightdirbase + v6 - 12), 0);
      SDF_VU0__APPLYMATRIX();
      v49 = dds3DirLights;
      SDF_VU0__STOREVECTOR(&v49->m_Items[v4]->v);
      v52 = lightdirnow;
      v54 = lightdirmax;
      v55 = v52->m_Items[v4];
      if (v55 >= v54->m_Items[v4])
      {
        v58 = dds3DrawFlag & ~(2 * v5);
LABEL_78:
        dds3DrawFlag = v58;
      }
    }
    v59 = *&v3->_2.bitflags1;
    ++v4;
    v5 *= 4;
    v6 += 16;
    v7 = (v59 >> 9) & 1;
  }
  while (v4 != 3);
  if ((dds3DrawFlag & 0x100) == 0)
    goto LABEL_96;
LABEL_83:
  Log("=============================dds3SceneLightUpdateFirst:0002", 0);
  ++ambientnow;
  LOWORD(v61) = ambientnow;
  LOWORD(v62) = ambientmax;
  v65 = v61 / v62;
  SDF_VU0__dds3ColorItoF(ambientbase);
  SDF_VU0__SCALEVECTOR(1.0 - v65);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(ambienttarget);
  SDF_VU0__SCALEVECTOR(v65);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__VECTOR_W_SET_ONE();
  SDF_VU0__STOREVECTOR(&dds3Ambient);
  if (ambientnow < ambientmax)
  {
LABEL_96:
    if ((v3->_2.bitflags2 & 2) == 0)
      goto LABEL_98;
    goto LABEL_97;
  }
  dds3DrawFlag &= ~0x100u;
  if ((v3->_2.bitflags2 & 2) == 0)
  {
LABEL_98:
    if ((dds3DrawFlag & 0x200) != 0)
      goto LABEL_99;
LABEL_112:
    if ((v3->_2.bitflags2 & 2) != 0)
      goto LABEL_113;
LABEL_114:
    if ((dds3DrawFlag & 0x400) != 0)
      goto LABEL_115;
LABEL_128:
    if ((v3->_2.bitflags2 & 2) != 0)
      goto LABEL_129;
LABEL_130:
    if ((dds3DrawFlag & 0x4000) != 0)
      goto LABEL_131;
    return;
  }
LABEL_97:
    goto LABEL_98;
  if ((dds3DrawFlag & 0x200) == 0)
    goto LABEL_112;
LABEL_99:
  Log("=============================dds3SceneLightUpdateFirst:0003", 0);
  ++fogrgbnow;
  LOWORD(v68) = fogrgbnow;
  LOWORD(v69) = fogrgbmax;
  v72 = v68 / v69;
  SDF_VU0__dds3ColorItoF(fogrgbbase);
  SDF_VU0__SCALEVECTOR(1.0 - v72);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF(fogrgbtarget);
  SDF_VU0__SCALEVECTOR(v72);
  SDF_VU0__ADDVECTOR();
  dds3FogParam->color = SDF_VU0__dds3ColorFtoI(128.0);
  if (fogrgbnow < fogrgbmax)
    goto LABEL_112;
  dds3DrawFlag &= ~0x200u;
  if ((v3->_2.bitflags2 & 2) == 0)
    goto LABEL_114;
LABEL_113:
    goto LABEL_114;
  if ((dds3DrawFlag & 0x400) == 0)
    goto LABEL_128;
LABEL_115:
  Log("=============================dds3SceneLightUpdateFirst:0004", 0);
  ++fogparanow;
  LOWORD(v76) = fogparanow;
  LOWORD(v77) = fogparamax;
  v80 = v76 / v77;
  SDF_VU0__LOADVECTOR(fogparabase);
  SDF_VU0__LOADVECTOR_B(fogparatarget);
  SDF_VU0__SCALEVECTOR(1.0 - v80);
  SDF_VU0__SCALEVECTOR_B(v80);
  SDF_VU0__ADDVECTOR();
  v81 = dds3FogParam;
  v81->fogMax = SDF_VU0__GETVECTOR_X();
  v82 = dds3FogParam;
  v82->fogMin = SDF_VU0__GETVECTOR_Y();
  v83 = dds3FogParam;
  v83->fogNear = SDF_VU0__GETVECTOR_Z();
  v84 = dds3FogParam;
  v84->fogFar = SDF_VU0__GETVECTOR_W();
  if (fogparanow < fogparamax)
    goto LABEL_128;
  dds3DrawFlag &= ~0x400u;
  if ((v3->_2.bitflags2 & 2) == 0)
    goto LABEL_130;
LABEL_129:
    goto LABEL_130;
  if ((dds3DrawFlag & 0x4000) != 0)
  {
LABEL_131:
    Log("=============================dds3SceneLightUpdateFirst:0005", 0);
    ++sbnow;
    LOWORD(v87) = sbnow;
    LOWORD(v88) = sbmax;
    v91 = v87 / v88;
    sdfFaceDivSoften = (softentarget * v91) + (softenbase * (1.0 - v91));
    sdfFaceDivBias = ((1.0 - v91) * biasbase)
                                       + (v91 * biastarget);
    if (sbnow >= sbmax)
    {
      dds3DrawFlag &= ~0x4000u;
    }
  }
}

// 0x17bf0c0
void dds3SetAmbient(sdfVector4_t ambient) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o v8;

  w = ambient.w;
  z = ambient.z;
  y = ambient.y;
  x = ambient.x;
  v8.z = z;
  v8.w = w;
  v8.x = x;
  v8.y = y;
  SDF_VU0__COPYVECTOR(&dds3Ambient, v8);
}

// 0x17c5c60
void dds3SetAmbientColor(u32 frame, sdfVector4_t col) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  u32 v9;
  UnityEngine_Vector4_o v10;
  UnityEngine_Vector4_o v11;

  w = col.w;
  z = col.z;
  y = col.y;
  x = col.x;
  if (frame)
  {
    dds3DrawFlag |= 0x100u;
    ambientnow = 0;
    ambientmax = frame;
    SDF_VU0__LOADVECTOR(dds3Ambient);
    v9 = SDF_VU0__dds3ColorFtoI(128.0);
    v10.x = x;
    v10.y = y;
    v10.z = z;
    v10.w = w;
    ambientbase = v9;
    SDF_VU0__LOADVECTOR(v10);
    SDF_VU0__VECTOR_W_SET_ONE();
    ambienttarget = SDF_VU0__dds3ColorFtoI(128.0);
  }
  else
  {
    v11.x = x;
    v11.y = y;
    v11.z = z;
    v11.w = w;
    dds3DrawFlag &= ~0x100u;
    SDF_VU0__LOADVECTOR(v11);
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(&dds3Ambient);
  }
}

// 0x17c05b0
void dds3SetBlur(u32 frame, s32 alpha, s32 scale) {
  dds3KernelDraw_c *v7;
  u32 v9;

  if (!frame)
  {
    dds3ScreenBlurAlpha = alpha;
    dds3ScreenBlurScale = scale;
    if (alpha | scale)
    {
      dds3ScreenBlurFlag = 1;
      if ((v7->_2.bitflags2 & 2) == 0)
        goto LABEL_22;
    }
    else
    {
      dds3ScreenBlurFlag = 0;
      if ((v7->_2.bitflags2 & 2) == 0)
        goto LABEL_22;
    }
LABEL_22:
    v9 = dds3DrawFlag & 0xFFFFF7FF;
    goto LABEL_23;
  }
  bluralphabase = dds3ScreenBlurAlpha;
  blurscalebase = dds3ScreenBlurScale;
  bluralphatarget = alpha;
  blurscaletarget = scale;
  blurnow = 0;
  blurmax = frame;
  v9 = dds3DrawFlag | 0x800;
LABEL_23:
  dds3DrawFlag = v9;
}

// 0x17c0830
void dds3SetBlur2Area(s32 posx, s32 posy) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v8;

  pm = blur2target->center->pm;
  pm->m_Items[0] = posx;
  v8 = blur2target->center->pm;
  v8->m_Items[1] = posy;
}

// 0x17c0720
void dds3SetBlur2Para(f32 rotate, f32 scale, s32 blend) {
  blur2target->rotate = rotate;
  blur2target->scale = scale;
  blur2target->blend = blend;
}

// 0x17c07c0
void dds3SetBlur2RGBA(u32 rgba) {
  blur2target->abgr = rgba;
}

// 0x17c1bb0
void dds3SetDistBlurArea(s32 area, s32 posx, s32 posy) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v10;

  distblurtarget->area = area;
  pm = distblurtarget->center->pm;
  pm->m_Items[0] = posx;
  v10 = distblurtarget->center->pm;
  v10->m_Items[1] = posy;
}

// 0x17c1a10
void dds3SetDistBlurPara(s32 number, s32 width, s32 intval, f32 speed, f32 rotate, f32 distor, s32 blend) {
  if (number >= 101)
  {
    number = 100;
    ++distblurovercnt;
  }
  distblurtarget->number = number;
  distblurtarget->width = width;
  distblurtarget->interval = intval;
  distblurtarget->speed = speed;
  distblurtarget->rotate = rotate;
  distblurtarget->distortion = distor;
  distblurtarget->blend = blend;
}

// 0x17c1b40
void dds3SetDistBlurRGBA(u32 rgba) {
  distblurtarget->abgr = rgba;
}

// 0x17bf420
void dds3SetFilter2Para(s32 blend) {
  filter2target->blend = blend;
}

// 0x17bf490
void dds3SetFilter2RGBA(u32 rgba) {
  filter2target->abgr = rgba;
}

// 0x17bf160
void dds3SetFog(sdf3DFogParam_t *fog) {
  dds3FogParam = fog;
}

// 0x17c5df0
void dds3SetFogColor(u32 frame, sdfVector4_t col) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  u32 v9;
  UnityEngine_Vector4_o v11;

  w = col.w;
  z = col.z;
  y = col.y;
  x = col.x;
  v11.x = x;
  v11.y = y;
  v11.z = z;
  v11.w = w;
  SDF_VU0__LOADVECTOR(v11);
  SDF_VU0__VECTOR_W_SET_ZERO();
  v9 = SDF_VU0__dds3ColorFtoI(255.0);
  if (frame)
  {
    dds3DrawFlag |= 0x200u;
    fogrgbnow = 0;
    fogrgbmax = frame;
    fogrgbbase = dds3FogParam->color;
    fogrgbtarget = v9;
  }
  else
  {
    dds3DrawFlag &= ~0x200u;
    dds3FogParam->color = v9;
  }
}

// 0x17c5f20
void dds3SetFogPara(u32 frame, f32 max, f32 min, f32 near, f32 far) {
  f32 *p_w;

  if (frame)
  {
    dds3DrawFlag |= 0x400u;
    fogparanow = 0;
    fogparamax = frame;
    fogparabase.x = dds3FogParam->fogMax;
    fogparabase.y = dds3FogParam->fogMin;
    fogparabase.z = dds3FogParam->fogNear;
    fogparabase.w = dds3FogParam->fogFar;
    fogparatarget.x = max;
    fogparatarget.y = min;
    fogparatarget.z = near;
    p_w = &fogparatarget.w;
  }
  else
  {
    dds3DrawFlag &= ~0x400u;
    dds3FogParam->fogMax = max;
    dds3FogParam->fogMin = min;
    dds3FogParam->fogNear = near;
    p_w = &dds3FogParam->fogFar;
  }
  *p_w = far;
}

// 0x17bf1d0
void dds3SetLight(sdf3DLight_t *light, u32 no) {
  struct sdf3DLight_t_array *dds3DirLights;

  else
  {
    if (!light)
      goto LABEL_9;
  }
LABEL_9:
  dds3DirLights->m_Items[no] = light;
}

// 0x17c5680
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct sdf3DLight_t_array *dds3DirLights;
  s32 v14;
  struct System_UInt16_array *lightrgbnow;
  struct System_UInt16_array *lightrgbmax;
  struct sdf3DLight_t_array *v19;
  struct System_UInt32_array *lightrgbbase;
  u32 v22;
  struct System_UInt32_array *lightrgbtarget;
  u32 v25;
  struct sdf3DLight_t_array *v27;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o v30;

  w = col.w;
  z = col.z;
  y = col.y;
  x = col.x;
  if (dds3DirLights->m_Items[no])
  {
    v14 = 4 << (2 * (no & 0xF));
    if (frame)
    {
      dds3DrawFlag |= v14;
      lightrgbnow->m_Items[no] = 0;
      lightrgbmax->m_Items[no] = frame;
      v19 = dds3DirLights;
      SDF_VU0__LOADVECTOR(v19->m_Items[no]->color);
      v22 = SDF_VU0__dds3ColorFtoI(128.0);
      v29.x = x;
      v29.y = y;
      v29.z = z;
      v29.w = w;
      lightrgbbase->m_Items[no] = v22;
      SDF_VU0__LOADVECTOR(v29);
      SDF_VU0__VECTOR_W_SET_ZERO();
      v25 = SDF_VU0__dds3ColorFtoI(128.0);
      lightrgbtarget->m_Items[no] = v25;
    }
    else
    {
      v30.x = x;
      v30.y = y;
      v30.z = z;
      v30.w = w;
      dds3DrawFlag &= ~v14;
      SDF_VU0__LOADVECTOR(v30);
      SDF_VU0__VECTOR_W_SET_ZERO();
      v27 = dds3DirLights;
      SDF_VU0__STOREVECTOR(&v27->m_Items[no]->color);
    }
  }
}

// 0x17c5970
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct sdf3DLight_t_array *dds3DirLights;
  s32 v14;
  struct System_UInt16_array *lightdirnow;
  struct System_UInt16_array *lightdirmax;
  struct sdf3DLight_t_array *v19;
  struct UnityEngine_Vector4_array *lightdirbase;
  struct UnityEngine_Vector4_array *lightdirquat;
  UnityEngine_Vector4_o *v26;
  struct sdf3DLight_t_array *v27;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o v30;

  w = dir.w;
  z = dir.z;
  y = dir.y;
  x = dir.x;
  if (dds3DirLights->m_Items[no])
  {
    v14 = 8 << (2 * (no & 0xF));
    if (frame)
    {
      dds3DrawFlag |= v14;
      lightdirnow->m_Items[no] = 0;
      v29.x = x;
      v29.y = y;
      v29.z = z;
      v29.w = w;
      lightdirmax->m_Items[no] = frame;
      SDF_VU0__LOADVECTOR(v29);
      SDF_VU0__VECTOR_W_SET_ZERO();
      SDF_VU0__NORMALIZE();
      SDF_VU0__COPYVECTOR_A_TO_B();
      v19 = dds3DirLights;
      SDF_VU0__LOADVECTOR(v19->m_Items[no]->v);
      SDF_VU0__VECTOR_W_SET_ZERO();
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&lightdirbase->m_Items[no]);
      dds3RotationArc();
      v26 = (&lightdirquat->obj + no);
    }
    else
    {
      v30.x = x;
      v30.y = y;
      v30.z = z;
      v30.w = w;
      dds3DrawFlag &= ~v14;
      SDF_VU0__LOADVECTOR(v30);
      SDF_VU0__NORMALIZE();
      SDF_VU0__VECTOR_W_SET_ZERO();
      v27 = dds3DirLights;
      v26 = v27->m_Items[no];
    }
    SDF_VU0__STOREVECTOR(v26 + 2);
  }
}

// 0x17bfc70
void dds3SetMFilterArea(s32 area, s32 posx, s32 posy) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v10;

  mfiltertarget->area = area;
  pm = mfiltertarget->center->pm;
  pm->m_Items[0] = posx;
  v10 = mfiltertarget->center->pm;
  v10->m_Items[1] = posy;
}

// 0x17bfb70
void dds3SetMFilterPara(s32 blend) {
  mfiltertarget->Filter->blend = blend;
}

// 0x17bfbf0
void dds3SetMFilterRGBA(u32 rgba) {
  mfiltertarget->Filter->abgr = rgba;
}

// 0x17c1180
void dds3SetMultiBlurArea(s32 area, s32 posx, s32 posy) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v10;

  mulblurtarget->area = area;
  pm = mulblurtarget->Blur->center->pm;
  pm->m_Items[0] = posx;
  v10 = mulblurtarget->Blur->center->pm;
  v10->m_Items[1] = posy;
}

// 0x17c1050
void dds3SetMultiBlurPara(f32 rotate, f32 scale, s32 blend) {
  mulblurtarget->Blur->rotate = rotate;
  mulblurtarget->Blur->scale = scale;
  mulblurtarget->Blur->blend = blend;
}

// 0x17c1100
void dds3SetMultiBlurRGBA(u32 rgba) {
  mulblurtarget->Blur->abgr = rgba;
}

// 0x17bd1c0
void dds3SetQuake(s32 frame, u32 range) {
  dds3KernelDraw_c *v5;

  if (range)
  {
    dds3QuakeFlag = 1;

    {
      if ((*&v5->_2.bitflags1 & 0x200) != 0)
      {
        dds3QuakeFrame = -1;
        if ((v5->_2.bitflags2 & 2) == 0)
          goto LABEL_20;
        goto LABEL_11;
      }
      LOWORD(frame) = -1;
    }
    dds3QuakeFrame = frame;
    if ((v5->_2.bitflags2 & 2) != 0)
    {
LABEL_11:
    }
LABEL_20:
    dds3QuakeYRange = 10 * range;
    dds3QuakeXRange = (0x333333334LL * dds3QuakeYRange) >> 35;
    return;
  }
  dds3QuakeFlag = 0;
}

// 0x17c2450
void dds3SetRipBlurArea(s32 area, s32 posx, s32 posy) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v10;

  ripblurtarget->area = area;
  pm = ripblurtarget->center->pm;
  pm->m_Items[0] = posx;
  v10 = ripblurtarget->center->pm;
  v10->m_Items[1] = posy;
}

// 0x17c22b0
void dds3SetRipBlurPara(s32 number, f32 speed, f32 intval, f32 rotate, f32 distor, f32 distor_s, s32 blend) {
  if (number >= 41)
  {
    number = 40;
    ++ripblurovercnt;
  }
  ripblurtarget->number = number;
  ripblurtarget->speed = speed;
  ripblurtarget->interval = intval;
  ripblurtarget->rotate = rotate;
  ripblurtarget->power = distor;
  ripblurtarget->frequency = distor_s;
  ripblurtarget->blend = blend;
}

// 0x17c23e0
void dds3SetRipBlurRGBA(u32 rgba) {
  ripblurtarget->abgr = rgba;
}

// 0x17bf040
void dds3SetScreenFovy(f32 fovy) {
  dds3ScreenParam->fovy = fovy;
}

// 0x17c6c80
void dds3SetSoftenBias(u32 frame, f32 soften, f32 bias) {
  if (frame)
  {
    dds3DrawFlag |= 0x4000u;
    sbnow = 0;
    sbmax = frame;
    softenbase = sdfFaceDivSoften;
    softentarget = soften;
    biasbase = sdfFaceDivBias;
    biastarget = bias;
  }
  else
  {
    dds3DrawFlag &= ~0x4000u;
    sdfFaceDivSoften = soften;
    sdfFaceDivBias = bias;
  }
}

// 0x17bd320
void dds3StopQuake(void) {
  dds3QuakeFlag = 0;
}

// 0x17c7120
void egl3Dto2D(f32 x3, f32 y3, f32 z3, s32 *x2, s32 *y2) {
  ;
}

// 0x17c7000
void eglInit(void) {
  ;
}

// 0x17c7090
void eglLinkAlpha(s32 mode) {
  ;
}

// 0x17c70b0
void eglLinkBox(s32 x, s32 y, s32 w, s32 h, s32 rgba0, s32 rgba1, s32 rgba2, s32 rgba3) {
  ;
}

// 0x17c7110
void eglLinkKanji(s32 x, s32 y, s32 rgba, char **moji) {
  ;
}

// 0x17c70f0
void eglLinkLine(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, u32 col0, u32 col1) {
  ;
}

// 0x17c70d0
void eglLinkPoly4(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 x3, f32 y3, f32 z3, u32 col0, u32 col1, u32 col2, u32 col3) {
  ;
}

// 0x17c7100
void eglLinkPrint(s32 x, s32 y, s32 col, char **str) {
  ;
}

// 0x17c70a0
void eglLinkSprite(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba0, s32 rgba1, s32 rgba2, s32 rgba3, sdfTexHandle_t *th) {
  ;
}

// 0x17c7080
void eglLinkTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  ;
}

// 0x17c70e0
void eglLinkTexPoly4(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 x3, f32 y3, f32 z3, f32 s0, f32 t0, f32 s1, f32 t1, u32 col0, u32 col1, u32 col2, u32 col3, sdfTexHandle_t *th) {
  ;
}

// 0x17c70c0
void eglLinkTri(s32 x0, s32 y0, s32 x1, s32 y1, s32 x2, s32 y2, s32 rgba0, s32 rgba1, s32 rgba2) {
  ;
}

// 0x17c7010
void eglSetOt(s32 ot) {
  egl_OT_Offset = ot;
}

// 0x17bf2c0
void setdraw_xy(sdfIVector2_t ***xy) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v3;
  struct System_Int32_array *v6;
  struct System_Int32_array *v9;

  pm = (*xy)->m_Items[0]->pm;
  pm->m_Items[0] = 0;
  v3 = (*xy)->m_Items[0]->pm;
  v3->m_Items[1] = 0;
  v6 = (*xy)->m_Items[1]->pm;
  v6->m_Items[0] = 512;
  v9 = (*xy)->m_Items[1]->pm;
  v9->m_Items[1] = 448;
}
