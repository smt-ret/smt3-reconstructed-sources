#include "types.h"

typedef struct FieldBgHD FieldBgHD;
typedef struct FieldChrHD FieldChrHD;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_PartialMultiFilter_t dds3Effect_PartialMultiFilter_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct dds3UnityEx_Eve_DOF dds3UnityEx_Eve_DOF;
typedef struct dds3UnityEx_Filter_OverwriteSky dds3UnityEx_Filter_OverwriteSky;
typedef struct dds3UnityEx_Filter_OverwriteSky_Btl dds3UnityEx_Filter_OverwriteSky_Btl;
typedef struct dds3UnityEx_Filter_SkipSky dds3UnityEx_Filter_SkipSky;
typedef struct dds3UnityEx_FldEve_Bloom dds3UnityEx_FldEve_Bloom;
typedef struct dds3UnityEx_Fld_FldSkyLightOvweWrite_t dds3UnityEx_Fld_FldSkyLightOvweWrite_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldResourceLight_t fldResourceLight_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

struct dds3UnityEx_Eve_DOF {
    s32 eveno;
    s32 area;
    s32 dante;
    s32 other;
    char *cam;
    s32 bloom;
    f32 dofa;
    f32 dofb;
    f32 dofc;
};

struct dds3UnityEx_FldEve_Bloom {
    s32 fld;
    s32 area;
    s32 bloom_type;
    f32 blur_pow;
    char *jyoken_scr;
    char *jyoken_cam;
    char *jyoken_npc;
    s32 dof_ow;
    f32 dofa;
    f32 dofb;
    f32 dofc;
};

struct dds3UnityEx_Filter_OverwriteSky {
    s32 eveno;
    s32 dante;
    s32 idx;
    s32 alp;
    s32 to_alp;
    s32 to_par;
};

struct dds3UnityEx_Filter_SkipSky {
    s32 eveno;
    s32 dante;
    s32 idx;
    s32 alp;
    s32 flame;
};

struct dds3UnityEx_Filter_OverwriteSky_Btl {
    s32 idx;
    s32 alp;
    s32 mode;
    s32 to_alp;
    s32 to_par;
};

struct dds3UnityEx_Fld_FldSkyLightOvweWrite_t {
    s32 fld;
    s32 idx1;
    s32 idx2;
    s32 lzero;
    s32 azero;
    f32 m_lr;
    f32 m_lg;
    f32 m_lb;
    f32 a_lr;
    f32 a_lg;
    f32 a_lb;
    f32 m_ar;
    f32 m_ag;
    f32 m_ab;
    f32 a_ar;
    f32 a_ag;
    f32 a_ab;
};

static char *evtUpdateEx_Camname;
static s32 evtUpdateEx_CamRunTime;
static s32 evtUpdateEx_CamCngCount;
static s32 evtUpdateEx_NowEveNo;
static void *evtUpdateEx_GameObject;
static char *evtUpdateEx_FieldName;
static f32 evtUpdateEx_LocalFloat0;
static s32 evtUpdateEx_LocalInt0;
static bool evtUpdateEx_ArkOpen_e674after;
static f32 evtUpdateEx_Dante_e723dofcnt;
static bool evtUpdateEx_Dante_e730after;
static bool evtUpdateEx_ArkOpen_F037_07_THOR_AFTER_Dead;
static dds3Effect_Blur_t *BlurBuff;
static dds3Effect_Filter_t *BlurFilterBuff;
static dds3Effect_PartialMultiFilter_t *BlurMultiFilterBuff;
static dds3Effect_PartialMultiFilterParam_t *BlurMultiFilter_Param;
static bool e659_Ara_Out;
static f32 dbg_x;
static f32 dbg_y;
static f32 dbg_z;
static dds3Basic_t *evtUpdateEx_old_camera;
static s32 Ex_NowFrame;
static dds3UnityEx_Eve_DOF *Tbl_Eve_DOF[366];
static dds3UnityEx_FldEve_Bloom *Tbl_FldEve_BloomDof[57];
static s32 FldEve_Bloom_Idx;
static s32 FldEve_Dof_Idx;

static f32 dbg_x;
static f32 dbg_y;
static f32 dbg_z;
static s32 dbg_skyidx;
static s32 dbg_skyalp;
static dds3UnityEx_Filter_OverwriteSky *Tbl_OverwriteSky[214];
static dds3UnityEx_Filter_SkipSky *Tbl_SkipSky[3];
static dds3UnityEx_Filter_OverwriteSky_Btl *Tbl_OverwriteSky_Btl[81];

static s32 *fld_pps;
static f32 *fld_dof;
static dds3UnityEx_Fld_FldSkyLightOvweWrite_t *Tbl_FldSkyLightOvweWrite[33];

static f32 LocalFloat0;
static s32 LocalInt0;
static f32 bk_l0_r;
static f32 bk_l0_g;
static f32 bk_l0_b;
static f32 bk_v0_x;
static f32 bk_v0_y;
static f32 bk_v0_z;
static f32 bk_a0_r;
static f32 bk_a0_g;
static f32 bk_a0_b;
static f32 SpHokan_l0_r;
static f32 SpHokan_l0_g;
static f32 SpHokan_l0_b;
static f32 SpHokan_v0_x;
static f32 SpHokan_v0_y;
static f32 SpHokan_v0_z;
static f32 SpHokan_a0_r;
static f32 SpHokan_a0_g;
static f32 SpHokan_a0_b;
static f32 SpHokan2_l0_r;
static f32 SpHokan2_l0_g;
static f32 SpHokan2_l0_b;
static f32 SpHokan2_v0_x;
static f32 SpHokan2_v0_y;
static f32 SpHokan2_v0_z;
static f32 SpHokan2_a0_r;
static f32 SpHokan2_a0_g;
static f32 SpHokan2_a0_b;
static f32 e618_rot;
static f32 dbg_x;
static f32 dbg_y;
static f32 dbg_z;
static bool SpHokanMode;
static bool SpHokan2Mode;
static s32 gJyakyou_Aruji_idx;
static f32 *jyakyo_aruji_normal_combine_tbl;

void BasicLight_Char_Color_Standard(f32 soften, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b);
s32 CheckLoad(nbMainProcessData_t **data);
bool DDS3_PADCHECK_REP(s32 id);
void Debug_OW_SkyAlp(void);
void DofOff(void);
void DofSet(f32 dof1, f32 dof2, f32 dof3);
void Eve_DOF_Set(s32 eveid, char *camname);
void FldEve_Blur_Pow(f32 pow);
void *GetCampCameraObj(dds3DefaultMain *this);
char *GetEventCamName(void);
void *GetMainCamera(dds3DefaultMain *this);
char *GetNowCameraName(void);
s32 GetNowFrame(void);
char *GetNowName_SCR_RUN(void);
void Ktyousei_DOF(void);
void Log(char *fmt, void **parray);
void PlayVoice(char *name);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void SetDrawFlag(u32 flag, u32 cnt);
void SetLayerAll2(FieldChrHD *this, void *rootobj, s32 setlayer);
void Set_EventID(s32 eno);
void Set_EventMode(bool onoff);
void SpHokan2_ColorVec(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow);
void SpHokan_Color(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow);
void SpHokan_ColorVec(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow);
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID);
void dds3EffectDistortionBlur_SetFldEvent(s32 feve_UnityEx_id);
void dds3EffectDistortionBlur_SetFldEventCntF(f32 feve_UnityEx_cntF);
void dds3EffectFilter(dds3Effect_Filter_t *pFilter);
dds3Effect_PartialMultiFilter_t *dds3EffectPartialMultiFilterCreate(dds3Effect_PartialMultiFilterParam_t *pParam);
void dds3EffectPartialMultiFilterDraw(dds3Effect_PartialMultiFilter_t **hPartialMultiFilter);
f32 dds3FadeGetAlphaI(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveCameraSceneBasic(dds3Basic_t **pBasic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessRunTime(dds3ProcessID_t **id);
char *dds3GetScriptProcName(void);
bool evtBitCheck(s32 no);
void fldEve_Bloom_Init(void);
void fldPPSV2_Set(s32 fld, s32 area);
void fldSdwDraw_Skep1(void);
void fldSkySetAlphaOfs(s32 alp);
void p2sdPlaySE_20173184(char *define_name);

// 0x1808920
void BasicLight_Char_Color(char *objname, evtUnitHandle_t *hunit, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim) {
  f32 v23;
  s32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  s32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 *v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 *v44;
  s32 v45;
  System_String_o *v47;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  System_String_o *v55;
  bool v56;
  f32 v57;
  f32 v58;
  f32 v59;
  System_String_o *v61;
  bool v63;
  dds3UnityEx_Light_c *v64;
  f32 e618_rot;
  f32 v69;
  f32 v70;
  f32 v71;
  f32 v72;
  f32 v74;
  f32 v76;
  s32 v79;
  f32 v80;
  f32 v83;
  f32 v84;
  f32 v86;
  f32 v87;
  f32 v88;
  f32 v89;
  f32 v90;
  f32 v91;
  bool v92;
  f32 v94;
  f32 v95;
  System_String_o *NowName_SCR_RUN;
  System_String_o *EventCamName;
  System_String_o *v101;
  f32 v102;
  f32 v103;
  f32 v104;
  f32 v106;
  f32 v107;
  f32 v108;
  System_String_o *v109;
  System_String_o *v111;
  System_String_o *v113;
  f32 v114;
  f32 v115;
  f32 v116;
  f32 v117;
  f32 v118;
  f32 *v119;
  s32 v120;
  f32 v121;
  f32 v122;
  f32 v123;
  System_String_o *v125;
  f32 v128;
  f32 v129;
  f32 v130;
  f32 v131;
  f32 v133;
  f32 v134;
  f32 *v136;
  f32 v137;
  f32 v138;
  f32 v139;
  s32 v140;
  f32 v141;
  f32 v142;
  f32 v143;
  f32 v144;
  f32 v145;
  System_String_o *v147;
  bool v148;
  f32 v149;
  f32 v151;
  f32 v152;
  f32 v153;
  f32 v154;
  System_String_o *v156;
  f32 v158;
  f32 v161;
  System_String_o *v163;
  System_String_o *v164;
  System_String_o *v167;
  f32 v169;
  f32 v170;
  f32 v171;
  f32 v172;
  System_String_o *v174;
  bool v175;
  f32 v176;
  f32 v177;
  f32 v178;
  f32 v179;
  System_String_o *v181;
  System_String_o *v183;
  bool v184;
  f32 v186;
  System_String_o *v187;
  f32 v189;
  f32 v190;
  System_String_o *v192;
  f32 v194;
  System_String_o *v197;
  System_String_o *v199;
  f32 v200;
  f32 v201;
  f32 v202;
  System_String_o *NowCameraName;
  bool v206;
  System_String_o *v208;
  struct fldGlobalWork_t_o *fldGb;
  System_String_Fields fields;
  s64 v216;
  System_String_Fields v219;
  s64 v221;
  System_String_Fields v224;
  s64 v226;
  System_String_Fields v229;
  s64 v231;
  s32 v234;
  s32 Length;
  System_String_o *v238;
  System_String_o *v240;
  System_String_o *v242;
  bool v243;
  f32 v245;
  f32 v246;
  System_String_o *v248;
  f32 v249;
  f32 v250;
  f32 v251;
  System_String_o *v253;
  f32 v254;
  s64 gJyakyou_Aruji_idx;
  s64 v257;
  s64 v258;
  s64 v259;
  System_String_o *a;
  System_String_o *aa;
  System_String_o *ab;
  System_String_o *ac;
  System_String_o *ad;
  s64 v267;
  f32 v268;
  s64 v269;
  s32 v270;

  v268 = 0.0;
  v267 = 0;
  v23 = *l0_r;
  bk_l0_r = v23;
  bk_l0_g = *l0_g;
  bk_l0_b = *l0_b;
  bk_v0_x = *v0_x;
  bk_v0_y = *v0_y;
  bk_v0_z = *v0_z;
  bk_a0_r = *a0_r;
  bk_a0_g = *a0_g;
  bk_a0_b = *a0_b;
  if (op_Equality(objname, "npc_kaihuku_e801", 0))
  {
    v24 = 1092616192;
LABEL_8:
    *soften = v24;
    goto LABEL_18;
  }
  if (op_Equality(objname, "npc_isamu_e605", 0))
  {
    v25 = 0.8;
    *bias = *bias + -0.1;
    v26 = *l0_r;
LABEL_14:
    *l0_r = v26 * v25;
    v27 = *l0_g * v25;
LABEL_15:
    *l0_g = v27;
    *l0_b = *l0_b * v25;
    v28 = 0.9;
LABEL_16:
    v29 = *a0_r;
LABEL_17:
    *a0_r = v29 * v28;
    *a0_g = *a0_g * v28;
    *a0_b = *a0_b * v28;
    goto LABEL_18;
  }
  if (op_Equality(objname, "player_first_e605", 0)
    || op_Equality(objname, "player_first2_e605", 0))
  {
    v26 = *l0_r;
    v25 = 0.85;
    goto LABEL_14;
  }
  if (op_Equality(objname, "npc_tiaki_e621", 0))
  {
    *soften = 7.0;
    *bias = 0.0;
    *l0_g = *l0_g * 0.9;
    *l0_b = *l0_b * 0.9;
    *a0_r = *a0_r * 0.8;
    *a0_g = *a0_g * 0.8;
    *a0_b = *a0_b * 0.8;
    goto LABEL_18;
  }
  if (op_Equality(objname, "player_tatoo_e621", 0))
    goto LABEL_51;
  if (op_Equality(objname, "devil_0x16_e628_050_4", 0))
  {
    *bias = -0.4;
    goto LABEL_18;
  }
  if (op_Equality(objname, "gozu_e629", 0))
  {
    v24 = 1088421888;
    goto LABEL_8;
  }
  if (op_Equality(objname, "npc_hijiri_e632", 0))
  {
    *soften = 15.0;
    a = GetEventCamName();
    if (op_Equality(a, "cam07", 0) || op_Equality(a, "cam09", 0))
    {
      *v0_x = 0.009;
      *v0_y = -0.005;
      *v0_z = 0.0;
    }
    else if (op_Equality(a, "cam12", 0))
    {
      *v0_x = 0.008;
      *v0_y = -0.006;
      *v0_z = 0.002;
    }
    goto LABEL_18;
  }
  if (op_Equality(objname, "player_tatoo_e632", 0))
  {
    v24 = 1097859072;
    goto LABEL_8;
  }
  if (op_Equality(objname, "f634_manineji", 0))
  {
    NowName_SCR_RUN = GetNowName_SCR_RUN();
    if (!op_Equality(NowName_SCR_RUN, "e634_080", 0))
      goto LABEL_186;
    EventCamName = GetEventCamName();
    if (!op_Equality(EventCamName, "cam13", 0))
    {
      v101 = GetEventCamName();
      if (!op_Equality(v101, "cam15", 0))
      {
LABEL_186:
        *soften = 2.0;
        *bias = 0.1;
        v28 = 0.7;
        *l0_r = *l0_r * 0.7;
        *l0_g = *l0_g * 0.7;
        *l0_b = *l0_b * 0.7;
        goto LABEL_16;
      }
    }
    *soften = 2.0;
    *bias = 0.0;
    *l0_r = *l0_r * 0.3;
    *l0_g = *l0_g * 0.3;
    *l0_b = *l0_b * 0.4;
    *a0_r = *a0_r * 0.3;
    *a0_g = *a0_g * 0.3;
    *a0_b = *a0_b * 0.4;
    goto LABEL_18;
  }
  if (op_Equality(objname, "player_tatoo_e636", 0))
  {
    *soften = 7.0;
    *bias = *bias * -0.5;
    goto LABEL_18;
  }
  if (op_Equality(objname, "npc_mane_e636", 0))
  {
    *soften = 7.0;
    *bias = *bias * -0.05;
    goto LABEL_18;
  }
  if (op_Equality(objname, "gozu_e636", 0))
  {
    v116 = *soften + -7.0;
    *soften = 7.0;
    *bias = *bias + (v116 * 0.01);
    goto LABEL_18;
  }
  if (op_Equality(objname, "player_tatoo_e636_050", 0))
  {
    *soften = 7.0;
    v117 = 0.0;
    *bias = *bias * 0.5;
LABEL_211:
    *a0_r = *a0_r * v117;
    *a0_g = *a0_g * v117;
    *a0_b = *a0_b * v117;
    goto LABEL_18;
  }
  if (op_Equality(objname, "gozu_e636_050", 0))
  {
    v118 = *soften + -7.0;
    *soften = 7.0;
    *bias = *bias + (v118 * 0.01);
    goto LABEL_18;
  }
  if (op_Equality(objname, "npc_isamu_e655", 0))
  {
    *soften = 20.0;
    v119 = bias;
    v120 = -1102263091;
LABEL_219:
    *v119 = v120;
    goto LABEL_18;
  }
  if (op_Equality(objname, "player_tatoo_e658", 0))
  {
    v125 = GetEventCamName();
    if (op_Equality(v125, "cam01", 0))
    {
      *soften = 10.0;
      v119 = bias;
      v120 = -1092196762;
      goto LABEL_219;
    }
    *soften = 7.0;
    *bias = 0.0;
    goto LABEL_247;
  }
  if (op_Equality(objname, "majyo_tiaki_e672", 0))
  {
LABEL_247:
    v130 = *l0_r;
    v131 = 0.9;
LABEL_248:
    *l0_r = v130 * v131;
    *l0_g = *l0_g * v131;
    *l0_b = *l0_b * v131;
    goto LABEL_18;
  }
  if (op_Equality(objname, "majyo_tiaki_e673", 0))
  {
    *bias = *bias + 0.08;
    goto LABEL_247;
  }
  if (op_Equality(objname, "player_tatoo_e673", 0)
    || op_Equality(objname, "player_tatoo_e673_030", 0))
  {
    *soften = 5.0;
    *a0_r = *a0_r * 0.1;
    *a0_g = *a0_g * 0.1;
    *a0_b = *a0_b * 0.1;
    goto LABEL_18;
  }
  if (op_Equality(objname, "devil_0x120_e673_030_0", 0)
    || op_Equality(objname, "devil_0x120_e673_1", 0)
    || op_Equality(objname, "devil_0x120_e673_040_2", 0))
  {
    *soften = 10.0;
    *bias = -0.44;
    *l0_r = *l0_r * 1.5;
    *l0_g = *l0_g * 1.1;
    *l0_b = *l0_b * 1.6;
    *a0_r = *a0_r * 0.2;
    *a0_g = *a0_g * 0.0;
    *a0_b = *a0_b * 0.3;
    *a0_r = *a0_r + 0.1;
    *a0_g = *a0_g + 0.0;
    *a0_b = *a0_b + 0.1;
    v136 = v0_z;
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_z = v270;
    *v0_y = 0.0;
    v270 = 0;
    v269 = 0;
    v137 = *v0_x;
    v138 = *v0_z;
    v139 = 0.0;
LABEL_280:
    sub_8524C0(&v269, v137, v139, v138);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v136 = v270;
    goto LABEL_18;
  }
  if (op_Equality(objname, "npc_yuuko_e674", 0))
  {
    v147 = GetEventCamName();
    v148 = op_Equality(v147, "cam09a", 0);
    v130 = *l0_r;
    if (v148)
    {
      v131 = 0.6;
      goto LABEL_248;
    }
LABEL_303:
    *l0_r = v130 * 0.85;
    *l0_g = *l0_g * 0.85;
    v117 = 1.2;
    *l0_b = *l0_b * 0.85;
    goto LABEL_211;
  }
  if (op_Equality(objname, "npc_yuuko_e6740", 0))
  {
    v130 = *l0_r;
    goto LABEL_303;
  }
  if (op_Equality(objname, "npc_hikawa_e674", 0))
  {
    *l0_r = *l0_r * 0.9;
    *l0_g = *l0_g * 0.9;
    *l0_b = *l0_b * 0.9;
    if (!op_Equality(hunit->BasicLight->name, "light02", 0))
      goto LABEL_18;
    v151 = *bias * -1.5152;
    v152 = v151 * 0.4;
    *bias = *bias * 0.2;
    v153 = *l0_r * ((v151 * 0.4) + 1.0);
    v154 = (v151 * 0.2) + 1.0;
    *l0_r = v153;
    *l0_g = v154 * *l0_g;
    *l0_b = v154 * *l0_b;
    *a0_r = (1.3 - v152) * *a0_r;
    *a0_g = (1.3 - v152) * *a0_g;
    *a0_b = (1.3 - v152) * *a0_b;
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v0_z = v270;
    v156 = GetEventCamName();
    if (op_Equality(v156, "cam08", 0))
    {
      *v0_x = *v0_x * 0.2;
      v158 = -*v0_y;
    }
    else
    {
      v164 = GetEventCamName();
      if (!op_Equality(v164, "cam09b", 0))
        goto LABEL_340;
      *bias = *bias + -0.1;
      v158 = 0.0;
    }
    *v0_y = v158;
LABEL_340:
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v0_z = v270;
    if (evtUpdateEx_ArkOpen_e674after)
    {
      v167 = GetEventCamName();
      if (op_Equality(v167, "cam13", 0))
      {
        *l0_r = *l0_r * 0.8;
        *l0_g = *l0_g * 0.8;
        *l0_b = *l0_b * 0.8;
        v169 = 0.5;
      }
      else
      {
        v169 = 0.3;
      }
      *a0_r = *a0_r + v169;
      *a0_g = *a0_g + v169;
      *a0_b = *a0_b + v169;
      v170 = 0.8;
    }
    else
    {
      *l0_r = *l0_r * 0.8;
      *l0_g = *l0_g * 0.8;
      *l0_b = *l0_b * 0.8;
      *a0_r = *a0_r * 1.2;
      *a0_g = *a0_g * 1.2;
      *a0_b = *a0_b * 1.2;
      *a0_r = *a0_r + 0.3;
      *a0_g = *a0_g + 0.3;
      *a0_b = *a0_b + 0.3;
      v170 = 0.95;
    }
    SpHokan2_ColorVec(l0_r, l0_g, l0_b, v0_x, v0_y, v0_z, a0_r, a0_g, a0_b, v170);
    goto LABEL_18;
  }
  if (op_Equality(objname, "npc_yuuko_p_e674", 0))
  {
    *l0_r = *l0_r * 0.75;
    *l0_g = *l0_g * 0.75;
    *l0_b = *l0_b * 0.75;
    *a0_r = *a0_r * 1.1;
    *a0_g = *a0_g * 1.1;
    *a0_b = *a0_b * 1.1;
    *v0_x = 1.0;
    *v0_y = -0.5;
    *v0_z = -0.7;
    v161 = -0.7;
    {
LABEL_321:
    }
LABEL_323:
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, v161);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    v120 = v270;
    v119 = v0_z;
    goto LABEL_219;
  }
  if (op_Equality(objname, "devil_0x120_e682_0", 0))
  {
    v131 = 0.7;
    *bias = *bias + 0.1;
    v130 = *l0_r;
    goto LABEL_248;
  }
  if (op_Equality(objname, "npc_hikawa_e697", 0))
  {
    *soften = 15.0;
    *bias = *bias + -0.15;
    return;
  }
  if (op_Equality(objname, "npc_hijiri_e715", 0))
    goto LABEL_247;
  if (op_Equality(objname, "player_tatoo_e718", 0))
  {
    v174 = GetEventCamName();
    v175 = op_Equality(v174, "01cam_05", 0);
    v130 = *l0_r;
    if (v175)
    {
      *l0_r = v130 * 0.95;
      *l0_g = *l0_g * 0.95;
      v117 = 0.9;
      *l0_b = *l0_b * 0.95;
      goto LABEL_211;
    }
    goto LABEL_486;
  }
  if (op_Equality(objname, "player_tatoo_e719", 0))
  {
    v181 = GetEventCamName();
    if (!op_Equality(v181, "01cam_08", 0))
    {
      *l0_r = *l0_r * 0.65;
      v27 = *l0_g * 0.6;
      v25 = 0.55;
      goto LABEL_15;
    }
    goto LABEL_18;
  }
  if (op_Equality(objname, "npc_luci_e726", 0))
  {
    *soften = 8.001;
    *bias = *bias + 0.1;
    goto LABEL_18;
  }
  if (!op_Equality(objname, "npc_luci_old_e726", 0))
  {
    if (op_Equality(objname, "npc_gomo_e726", 0))
    {
      *soften = 8.001;
      *bias = *bias + 0.1;
      v192 = GetEventCamName();
      if (op_Equality(v192, "cam06", 0)
        || op_Equality(v192, "cam075", 0)
        || op_Equality(v192, "cam08", 0)
        || op_Equality(v192, "cam09", 0))
      {
        *l0_r = *l0_r * 0.6;
        *l0_g = *l0_g * 0.6;
        *l0_b = *l0_b * 0.6;
        *a0_r = *a0_r * 0.8;
        *a0_g = *a0_g * 0.8;
        *a0_b = *a0_b * 0.8;
      }
      if (op_Equality(v192, "cam07", 0))
      {
        v53 = *l0_r;
        v54 = 0.7;
        goto LABEL_52;
      }
      goto LABEL_18;
    }
    if (op_Equality(objname, "player_tatoo_e726", 0))
    {
      if (op_Equality(hunit->BasicLight->name, "light02", 0))
      {
        *bias = *bias * 0.5;
        v29 = *a0_r;
        v28 = 0.4;
        goto LABEL_17;
      }
      goto LABEL_18;
    }
    if (op_Equality(objname, "gouto_e731", 0))
    {
      *soften = 0.0;
      *bias = 0.0;
      goto LABEL_18;
    }
    if (op_Equality(objname, "player_tatoo_e740", 0)
      || op_Equality(objname, "player_tatoo_e743", 0)
      || op_Equality(objname, "player_tatoo_e744", 0)
      || op_Equality(objname, "player_tatoo_e745", 0)
      || op_Equality(objname, "player_tatoo_e746", 0))
    {
      v194 = *l0_r;
      v117 = 0.85;
LABEL_445:
      *l0_r = v194 * v117;
      *l0_g = *l0_g * v117;
      *l0_b = *l0_b * v117;
      goto LABEL_211;
    }
    if (!op_Equality(objname, "devil_0xc4_e743_0", 0))
    {
      if (op_Equality(objname, "devil_0x161_e748_0", 0))
      {
        v194 = *l0_r;
        v117 = 0.8;
        goto LABEL_445;
      }
      if (op_Equality(objname, "player_tatoo_e748", 0))
      {
        v130 = *l0_r;
LABEL_486:
        v131 = 0.8;
        goto LABEL_248;
      }
      if (op_Equality(objname, "devil_0x156_e750_0", 0))
      {
        v119 = soften;
        v120 = 1088421888;
        goto LABEL_219;
      }
      if (!op_Equality(objname, "npc_isamu_fieldevent01_2", 0))
      {
        if (op_Equality(objname, "devil_0xce_0", 0))
        {
          *soften = 7.0;
          *bias = -0.3;
          v136 = v0_z;
          v270 = 0;
          v269 = 0;
          sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
          sub_8531D0(&v269, 0);
          *v0_x = v269;
          *v0_y = *(&v269 + 1);
          *v0_z = v270;
          *v0_x = *v0_x * 0.8;
          v139 = *v0_y * 1.2;
          *v0_y = v139;
          v270 = 0;
          v269 = 0;
          v137 = *v0_x;
          v138 = *v0_z;
          goto LABEL_280;
        }
        if (!op_Equality(objname, "npc_jakyo_e807", 0))
          goto LABEL_18;
        if (fldGb->fieldID != 800)
          goto LABEL_18;
        if (fldGb->areaID != 69)
          goto LABEL_18;
        *soften = 15.0;
        *bias = -0.11;
        aa = jyakyo_aruji_normal_combine_tbl;
        fields = aa->fields;
        v216 = *(*&fields + 16LL);
        *l0_r = *(&aa[1].monitor + v216 * gJyakyou_Aruji_idx);
        v257 = gJyakyou_Aruji_idx;
        ab = jyakyo_aruji_normal_combine_tbl;
        v219 = ab->fields;
        v221 = *(*&v219 + 16LL);
        *l0_g = *(&ab[1].monitor + v221 * v257 + 1);
        v258 = gJyakyou_Aruji_idx;
        ac = jyakyo_aruji_normal_combine_tbl;
        v224 = ac->fields;
        v226 = *(*&v224 + 16LL);
        *l0_b = *(&ac[1].m_stringLength + v226 * v258);
        v259 = gJyakyou_Aruji_idx;
        ad = jyakyo_aruji_normal_combine_tbl;
        v229 = ad->fields;
        v231 = *(*&v229 + 16LL);
        *a0_r = *(&ad[1].m_firstChar + v231 * v259);
        *a0_g = 0.5;
        *a0_b = 0.5;
        v234 = gJyakyou_Aruji_idx;
        Length = GetLength(jyakyo_aruji_normal_combine_tbl, 0);
        if (v234 + 1 >= Length)
        {
          {
          }
          gJyakyou_Aruji_idx = 0;
        }
        else
        {
          {
          }
          ++gJyakyou_Aruji_idx;
        }
        *v0_x = 0.001;
        *v0_y = -0.009;
        *v0_z = -0.005;
        v161 = -0.005;
          goto LABEL_321;
        goto LABEL_323;
      }
    }
    v119 = rim;
    v120 = 1105723392;
    goto LABEL_219;
  }
  *rim = 29.0;
  *soften = 8.001;
  v183 = GetEventCamName();
  v184 = op_Equality(v183, "cam06", 0);
  v186 = 0.18;
  if (v184)
    v186 = 0.3;
  *bias = *bias + v186;
  v187 = GetEventCamName();
  if (op_Inequality(v187, "cam10", 0))
  {
LABEL_51:
    v53 = *l0_r;
    v54 = 0.8;
LABEL_52:
    *l0_r = v53 * v54;
    *l0_g = *l0_g * v54;
    *l0_b = *l0_b * v54;
  }
LABEL_18:
  if (op_Equality(objname, "npc_tiaki_e603", 0))
    v30 = 0;
  else
    v30 = 126;
  if (v30 != 126)
  {
LABEL_22:
    v31 = *l0_r;
    v32 = 1.1;
LABEL_23:
    *l0_r = v31 * v32;
    *l0_g = *l0_g * v32;
    *l0_b = *l0_b * v32;
    v33 = 1.3;
LABEL_24:
    v34 = *a0_r;
LABEL_25:
    v35 = v34 * v33;
LABEL_26:
    *a0_r = v35;
    v36 = *a0_g * v33;
LABEL_27:
    *a0_g = v36;
    v37 = *a0_b;
LABEL_28:
    *a0_b = v37 * v33;
    goto LABEL_108;
  }
  if (op_Equality(objname, "npc_yuuko_e615", 0))
  {
    *soften = 0.0;
    *bias = 0.22;
    *l0_r = *l0_r * 1.6;
    *l0_g = *l0_g * 1.6;
    *l0_b = *l0_b * 1.6;
    *a0_r = *a0_r * 1.6;
    *a0_g = *a0_g * 1.6;
    *a0_b = *a0_b * 1.6;
    SpHokan_Color(l0_r, l0_g, l0_b, a0_r, a0_g, a0_b, 0.95);
    v40 = v0_z;
    *v0_x = -0.006;
    *v0_y = 0.0;
    *v0_z = 0.008;
    v270 = 0;
    v269 = 0;
    v41 = *v0_x;
    v42 = *v0_y;
    v43 = 0.008;
    goto LABEL_34;
  }
  if (op_Equality(objname, "npc_yuuko_e616", 0))
  {
    v44 = rim;
    *l0_r = *l0_r * 1.3;
    v45 = 1105723392;
    *l0_g = *l0_g * 1.3;
    *l0_b = *l0_b * 1.2;
    *l0_r = *l0_r + 0.1;
    *l0_g = *l0_g + 0.1;
    *l0_b = *l0_b + 0.1;
    *a0_r = *a0_r * 1.2;
    *a0_g = *a0_g * 1.2;
    *a0_b = *a0_b * 1.2;
    *a0_r = *a0_r + 0.1;
    *a0_g = *a0_g + 0.1;
    *a0_b = *a0_b + 0.1;
LABEL_107:
    *v44 = v45;
    goto LABEL_108;
  }
  if (op_Equality(objname, "player_tatoo_e618", 0))
  {
    *soften = 20.0;
    *bias = 0.0;
    v47 = GetEventCamName();
    if (op_Equality(v47, "cam04", 0))
    {
      *l0_r = *l0_r * 0.95;
      *l0_g = *l0_g * 0.95;
      *l0_b = *l0_b * 0.95;
      v49 = *a0_r;
      v50 = 0.9;
    }
    else
    {
      v55 = GetEventCamName();
      v56 = op_Equality(v55, "cam05", 0);
      v50 = 1.2;
      *l0_r = *l0_r * 1.2;
      *l0_g = *l0_g * 1.2;
      *l0_b = *l0_b * 1.2;
      v49 = *a0_r;
      if (!v56)
      {
        v58 = 1.32;
        v50 = 1.3;
        v57 = v49 * 1.32;
        goto LABEL_63;
      }
    }
    v57 = v49 * v50;
    v58 = v50;
LABEL_63:
    *a0_r = v57;
    *a0_g = *a0_g * v50;
    *a0_b = *a0_b * v58;
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v0_z = v270;
    v59 = *v0_y * 0.2;
    *v0_y = v59;
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, v59, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v0_z = v270;
    v61 = GetEventCamName();
    v63 = op_Equality(v61, "cam05", 0);
    if (!v63)
    {
      e618_rot = -45.0;
      goto LABEL_108;
    }
    if (e618_rot <= -230.0)
    {
      e618_rot = e618_rot + -0.45;
      if ((v64->_2.bitflags2 & 2) == 0)
      {
LABEL_89:
        if (e618_rot < -310.0)
        {
          e618_rot = -310.0;
        }
        v69 = e618_rot;
        if (v69 < 0.0)
          v69 = v69 + 360.0;
        v70 = v69 * 0.017453;
        v71 = sinf(v70);
        v72 = cosf(v70);
        sub_8524C0(&v267, -v71, 0.0, -v72);
        sub_8531D0(&v267, 0);
        *v0_x = v267;
        *v0_y = -0.4;
        v74 = v268;
        *v0_z = v268;
        v76 = v74;
          goto LABEL_105;
        goto LABEL_103;
      }
    }
    else
    {
      e618_rot = e618_rot + -0.8;
      if ((v64->_2.bitflags2 & 2) == 0)
        goto LABEL_89;
    }
    goto LABEL_89;
  }
  if (op_Equality(objname, "npc_hijiri_e619", 0)
    || op_Equality(objname, "player_tatoo_e619_0", 0))
  {
    goto LABEL_47;
  }
  if (op_Equality(objname, "player_tatoo_e628", 0))
  {
    *soften = 15.0;
    *bias = -0.56;
    *l0_r = *l0_r * 1.2;
    *l0_g = *l0_g * 1.2;
    v33 = 0.2;
    *l0_b = *l0_b * 1.2;
    goto LABEL_24;
  }
  if (op_Equality(objname, "npc_tiaki_e635", 0))
  {
    if (op_Equality(hunit->BasicLight->name, "light04", 0))
    {
      *soften = 7.0;
LABEL_132:
      *bias = 0.0;
      v83 = 1.2;
      v84 = *l0_r * 1.2;
LABEL_133:
      *l0_r = v84;
      *l0_g = *l0_g * v83;
      *l0_b = *l0_b * v83;
      v33 = 1.1;
      goto LABEL_24;
    }
    v92 = op_Equality(hunit->BasicLight->name, "light10", 0);
    *soften = 7.0;
    if (v92)
    {
      *bias = 0.0;
      *l0_r = *l0_r * 1.2;
      *l0_g = *l0_g * 1.4;
      *l0_b = *l0_b * 1.3;
      *a0_r = *l0_r * 0.6;
      *a0_g = *l0_g * 0.6;
      *a0_b = *l0_b * 0.6;
      v40 = v0_z;
      v270 = 0;
      v269 = 0;
      sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
      sub_8531D0(&v269, 0);
      *v0_x = v269;
      *v0_y = *(&v269 + 1);
      *v0_z = v270;
      *v0_x = *v0_x * 0.2;
      v42 = *v0_y * 0.3;
      *v0_y = v42;
      v43 = *v0_z;
      v270 = 0;
      v269 = 0;
      v41 = *v0_x;
      goto LABEL_34;
    }
    *bias = -0.1;
    *l0_r = *l0_r * 1.2;
    *l0_g = *l0_g * 1.4;
    v33 = 0.6;
    *l0_b = *l0_b * 1.3;
LABEL_176:
    *a0_r = *l0_r * v33;
    *a0_g = *l0_g * v33;
    v37 = *l0_b;
    goto LABEL_28;
  }
  if (op_Equality(objname, "npc_hijiri_e646", 0))
  {
    *l0_b = 1.0;
    *soften = 15.0;
    *bias = -0.15;
LABEL_143:
    v86 = *a0_r;
    v87 = 0.25;
LABEL_144:
    v88 = v86 + v87;
LABEL_145:
    *a0_r = v88;
LABEL_146:
    v89 = *a0_g;
LABEL_147:
    v90 = v89 + v87;
LABEL_148:
    *a0_g = v90;
LABEL_149:
    v91 = *a0_b + v87;
LABEL_150:
    *a0_b = v91;
    goto LABEL_108;
  }
  if (op_Equality(objname, "npc_yuuko_e651_010", 0))
    goto LABEL_159;
  if (op_Equality(objname, "npc_hijiri_e652", 0))
    goto LABEL_143;
  if (op_Equality(objname, "devil_0x113_e658_0", 0))
  {
    *soften = 5.0;
    *bias = 0.33;
    v102 = 1.3;
    *l0_r = *l0_r * 1.2;
    *l0_g = *l0_g * 1.3;
    *l0_b = *l0_b * 1.4;
    v103 = *a0_r * 1.4;
LABEL_180:
    *a0_r = v103;
    v104 = *a0_g * v102;
LABEL_181:
    *a0_g = v104;
    *a0_b = *a0_b * v102;
    v87 = 0.1;
    v86 = *a0_r;
    goto LABEL_144;
  }
  if (op_Equality(objname, "majyo_tiaki_e661", 0))
  {
    v106 = *l0_r;
    v107 = *l0_g;
    v108 = *l0_b;
    *l0_r = *a0_r * 1.4;
    *l0_g = *a0_g * 1.4;
    *l0_b = *a0_b * 1.4;
    *a0_r = v106 * 0.7;
    *a0_g = v107 * 0.7;
    *a0_b = v108 * 0.7;
    *v0_x = -*v0_x;
    *v0_y = -*v0_y;
    *v0_z = -*v0_z;
    v109 = GetEventCamName();
    if (op_Equality(v109, "cam08", 0))
      goto LABEL_202;
    v111 = GetEventCamName();
    if (op_Equality(v111, "cam09", 0))
      goto LABEL_202;
    v113 = GetEventCamName();
    if (op_Equality(v113, "cam10", 0))
    {
LABEL_202:
      *soften = 7.0;
      *bias = 0.38;
    }
    *l0_r = *l0_r * 1.3;
    *l0_g = *l0_g * 1.3;
    *l0_b = *l0_b * 1.4;
    *l0_r = *l0_r + 0.0;
    *l0_g = *l0_g + 0.0;
    v114 = 0.1;
    *l0_b = *l0_b + 0.1;
    *a0_r = *a0_r * 1.3;
    *a0_g = *a0_g * 1.3;
    *a0_b = *a0_b * 1.4;
    *a0_r = *a0_r + 0.0;
    v115 = *a0_g + 0.0;
    goto LABEL_204;
  }
  if (op_Equality(objname, "gozhead_e661", 0))
  {
    *bias = *bias * 0.7;
    *l0_r = *l0_r * 1.4;
    *l0_g = *l0_g * 1.3;
    *l0_b = *l0_b * 1.3;
    v87 = 0.0;
    *l0_r = *l0_r + 0.2;
    *l0_g = *l0_g + 0.0;
    *l0_b = *l0_b + 0.0;
    *a0_r = *a0_r * 1.1;
    *a0_g = *a0_g * 0.8;
    *a0_b = *a0_b * 0.6;
    v88 = *a0_r + 0.3;
    goto LABEL_145;
  }
  if (op_Equality(objname, "npc_hijiri_e662", 0))
    goto LABEL_143;
  if (op_Equality(objname, "npc_hijiri_e670", 0))
  {
    *soften = 20.0;
    *l0_r = *l0_r * 1.7;
    *l0_g = *l0_g * 1.8;
    *l0_b = *l0_b * 1.9;
    *l0_r = *l0_r + 0.0;
    *l0_g = *l0_g + 0.1;
    v33 = 1.6;
    *l0_b = *l0_b + 0.2;
    *a0_r = *a0_r * 1.6;
    v36 = *a0_g * 1.5;
    goto LABEL_27;
  }
  if (op_Equality(objname, "devil_0x11b_e672_0", 0))
  {
    *soften = 5.0;
    *bias = 0.3;
LABEL_222:
    v121 = 0.9;
    v122 = *a0_r * 0.9;
LABEL_223:
    *a0_r = v122;
    v123 = *a0_g * v121;
LABEL_224:
    *a0_g = v123;
    v91 = *a0_b * v121;
    goto LABEL_150;
  }
  if (op_Equality(objname, "e674_arku", 0))
  {
    *soften = 1.0;
    *bias = 0.0;
    if (op_Equality(hunit->BasicLight->name, "light03", 0))
    {
      v128 = *l0_r;
      if (evtUpdateEx_ArkOpen_e674after)
      {
        *l0_r = v128 * 1.2;
        *l0_g = *l0_g * 0.9;
        *a0_r = *a0_r * 0.4;
        *a0_g = *a0_g * 0.5;
        *a0_b = *a0_b * 0.4;
        v129 = 0.8;
      }
      else
      {
        *l0_r = v128 * 0.8;
        *l0_g = *l0_g * 0.9;
        *a0_r = *a0_r * 0.8;
        *a0_b = *a0_b * 0.9;
        *l0_r = *l0_r + 0.1;
        *l0_g = *l0_g + 0.1;
        *l0_b = *l0_b + 0.1;
        *a0_r = *a0_r + 0.3;
        *a0_g = *a0_g + 0.3;
        *a0_b = *a0_b + 0.3;
        v129 = 0.95;
      }
    }
    else
    {
      *l0_r = *l0_r * 0.8;
      *l0_g = *l0_g * 0.9;
      *a0_r = *a0_r * 0.8;
      *a0_b = *a0_b * 0.9;
      v129 = 0.0;
    }
    SpHokan_ColorVec(l0_r, l0_g, l0_b, v0_x, v0_y, v0_z, a0_r, a0_g, a0_b, v129);
    goto LABEL_108;
  }
  if (op_Equality(objname, "npc_aradia_e674", 0))
  {
    *soften = 15.0;
    *bias = 0.0;
    *l0_r = *l0_r * 1.5;
    *l0_g = *l0_g * 1.5;
    *l0_b = *l0_b * 1.5;
    v33 = 0.8;
    goto LABEL_176;
  }
  if (op_Equality(objname, "devil_0x123_e674_0", 0))
  {
    v133 = *l0_r;
    *soften = 15.0;
    if (v133 < 0.795)
    {
      *bias = -0.55;
      *l0_r = *l0_r * 1.5;
      *l0_g = *l0_g * 1.5;
      *l0_b = *l0_b * 1.5;
      v33 = 0.7;
      goto LABEL_24;
    }
    *bias = -0.51;
    *l0_r = *l0_r * 1.4;
    *l0_g = *l0_g * 1.4;
    *l0_b = *l0_b * 1.6;
    *a0_r = *a0_r * 1.1;
    *a0_g = *a0_g * 1.3;
    *a0_b = *a0_b * 1.1;
    v40 = v0_z;
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_z = v270;
    *v0_y = 0.0;
    v270 = 0;
    v269 = 0;
    v41 = *v0_x;
    v43 = *v0_z;
    v42 = 0.0;
LABEL_34:
    sub_8524C0(&v269, v41, v42, v43);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v40 = v270;
    goto LABEL_108;
  }
  if (op_Equality(objname, "devil_0x124_e677_0", 0))
  {
    *l0_r = *l0_r * 0.8;
    *l0_g = *l0_g * 0.8;
    goto LABEL_108;
  }
  if (op_Equality(objname, "devil_0x123_e678_0", 0))
  {
    *soften = 7.001;
    *bias = 0.05;
    *l0_r = *l0_r * 1.5;
    *l0_g = *l0_g * 1.5;
    *l0_b = *l0_b * 1.5;
    *l0_r = *l0_r + 0.0;
    *l0_g = *l0_g + 0.0;
    v134 = *l0_b + 0.2;
LABEL_272:
    *l0_b = v134;
    v34 = *a0_r;
    v33 = 1.2;
    goto LABEL_25;
  }
  if (op_Equality(objname, "player_tatoo_e684_010", 0))
    goto LABEL_282;
  if (op_Equality(objname, "player_tatoo_e684", 0))
  {
    *bias = 0.0;
    v141 = *a0_r;
    v121 = 1.1;
    v142 = 1.2;
    goto LABEL_286;
  }
  if (op_Equality(objname, "player_tatoo_e686_010", 0))
  {
    *bias = -0.3;
LABEL_289:
    v143 = *l0_r;
    v144 = 1.1;
LABEL_290:
    *l0_r = v143 * v144;
    *l0_g = *l0_g * v144;
    *l0_b = *l0_b * v144;
    v33 = 1.2;
    v145 = 1.3;
LABEL_300:
    *a0_r = *a0_r * v33;
    v36 = *a0_g * v145;
    goto LABEL_27;
  }
  if (op_Equality(objname, "player_tatoo_e686", 0))
  {
    *soften = 15.001;
    *bias = 0.36;
    *l0_r = *l0_r * 0.95;
    *l0_g = *l0_g * 0.95;
    v149 = *l0_b * 0.95;
    v33 = 1.3;
    v145 = 1.4;
LABEL_299:
    *l0_b = v149;
    goto LABEL_300;
  }
  if (op_Equality(objname, "npc_hikawa_e686", 0))
  {
    *soften = 15.001;
    *bias = 0.22;
    v143 = *l0_r;
    v144 = 0.95;
    goto LABEL_290;
  }
  if (op_Equality(objname, "player_tatoo_e686_020", 0))
  {
    if (op_Equality(hunit->BasicLight->name, "light11", 0))
    {
      *soften = 15.001;
      *bias = 0.33;
      *l0_r = *l0_r * 0.95;
      *l0_g = *l0_g * 0.95;
      *l0_b = *l0_b * 0.95;
      *a0_r = *a0_r * 1.2;
      *a0_g = *a0_g * 1.3;
      *a0_b = *a0_b * 1.2;
      *v0_x = 0.01;
      *v0_y = 0.0;
      v45 = -1157426577;
      goto LABEL_106;
    }
LABEL_362:
    if (!op_Equality(hunit->BasicLight->name, "light12", 0))
      goto LABEL_108;
    *soften = 15.001;
    v171 = *l0_r;
    v172 = 1.3;
LABEL_364:
    *l0_r = v171 * v172;
    *l0_g = *l0_g * v172;
    *l0_b = *l0_b * v172;
    goto LABEL_108;
  }
  if (op_Equality(objname, "player_tatoo_e688_010", 0))
  {
    v163 = GetEventCamName();
    if (op_Equality(v163, "cam03", 0))
    {
      v140 = 1054951342;
      goto LABEL_283;
    }
    goto LABEL_282;
  }
  if (op_Equality(objname, "player_tatoo_e688", 0))
  {
    *bias = 0.0;
    goto LABEL_289;
  }
  if (op_Equality(objname, "player_tatoo_e688_020", 0))
  {
    if (!op_Equality(hunit->BasicLight->name, "light10", 0))
    {
      if (op_Equality(hunit->BasicLight->name, "light11", 0))
      {
        *bias = 0.4;
        v143 = *l0_r;
        v144 = 0.9;
        goto LABEL_290;
      }
      goto LABEL_362;
    }
LABEL_282:
    v140 = -1097229926;
LABEL_283:
    *bias = v140;
    v141 = *a0_r;
    v121 = 1.2;
    v142 = 1.3;
LABEL_286:
    *a0_r = v141 * v121;
    v123 = *a0_g * v142;
    goto LABEL_224;
  }
  if (op_Equality(objname, "npc_yuuko_e693_020", 0))
  {
    v176 = *l0_r;
    v177 = 1.3;
LABEL_380:
    *l0_r = v176 * v177;
    *l0_g = *l0_g * v177;
    v134 = *l0_b * v177;
    goto LABEL_272;
  }
  if (op_Equality(objname, "player_tatoo_e705_010", 0))
  {
    v178 = *l0_r;
    v179 = 0.65;
    goto LABEL_383;
  }
  if (op_Equality(objname, "player_tatoo_e705", 0))
  {
    *soften = 15.0;
    *bias = -0.44;
    *a0_r = *a0_r * 1.2;
    *a0_g = *a0_g * 1.2;
    *a0_b = *a0_b * 1.2;
    goto LABEL_392;
  }
  if (op_Equality(objname, "k_ball", 0))
  {
    *soften = 0.0;
    *bias = 0.0;
    v51 = *l0_r;
    v33 = 0.5;
    goto LABEL_48;
  }
  if (op_Equality(objname, "devil_0x108_e705_0", 0)
    || op_Equality(objname, "devil_0x108_e705_1", 0))
  {
    *soften = 7.0;
    *bias = 0.15;
    *l0_r = *l0_r * 0.35;
    *l0_g = *l0_g * 0.35;
    *l0_b = *l0_b * 0.35;
    *a0_r = *a0_r * 0.6;
    *a0_g = *a0_g * 0.6;
    *a0_b = *a0_b * 0.6;
    v40 = v0_z;
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v0_z = v270;
    *v0_x = *v0_x * 0.2;
    v189 = *v0_y;
    v190 = -1.5;
LABEL_435:
    *v0_y = v189 * v190;
    v43 = *v40 * 0.2;
LABEL_436:
    *v40 = v43;
    v270 = 0;
    v269 = 0;
    v41 = *v0_x;
    v42 = *v0_y;
    goto LABEL_34;
  }
  if (op_Equality(objname, "devil_0x108_e699_005_1", 0)
    || op_Equality(objname, "devil_0x108_e699_005_2", 0))
  {
    *soften = 7.0;
    *bias = 0.0;
    *l0_r = *l0_r * 0.47;
    *l0_g = *l0_g * 0.47;
    *l0_b = *l0_b * 0.52;
    *a0_r = *a0_r * 0.5;
    *a0_g = *a0_g * 0.5;
    *a0_b = *a0_b * 0.6;
    v40 = v0_z;
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v0_z = v270;
    *v0_x = *v0_x * 0.2;
    v189 = *v0_y;
    v190 = 1.5;
    goto LABEL_435;
  }
  if (op_Equality(objname, "player_tatoo_e699_005", 0))
  {
    *soften = 15.0;
    *bias = -0.44;
    *l0_r = *l0_r * 1.2;
    *l0_g = *l0_g * 1.2;
    *l0_b = *l0_b * 1.2;
    *a0_r = *a0_r * 1.4;
    *a0_g = *a0_g * 1.4;
    *a0_b = *a0_b * 1.4;
LABEL_392:
    *v0_x = -0.419;
    *v0_y = -0.37;
    *v0_z = -0.829;
    v76 = -0.829;
    {
LABEL_105:
      v270 = 0;
      v269 = 0;
      sub_8524C0(&v269, *v0_x, *v0_y, v76);
      sub_8531D0(&v269, 0);
      *v0_x = v269;
      *v0_y = *(&v269 + 1);
      v45 = v270;
LABEL_106:
      v44 = v0_z;
      goto LABEL_107;
    }
LABEL_103:
    goto LABEL_105;
  }
  if (op_Equality(objname, "player_tatoo_e703", 0))
  {
    *soften = 15.0;
    *bias = -0.4;
    *l0_r = *l0_r * 1.2;
    *l0_g = *l0_g * 1.2;
    *l0_b = *l0_b * 1.2;
    *l0_r = *l0_r + 0.2;
    *l0_g = *l0_g + 0.1;
    *l0_b = *l0_b + 0.1;
    *a0_r = *a0_r * 1.5;
    *a0_g = *a0_g * 1.5;
    *a0_b = *a0_b * 1.5;
    *a0_r = *a0_r + 0.2;
    *a0_g = *a0_g + 0.2;
    *a0_b = *a0_b + 0.2;
    v40 = v0_z;
    v270 = 0;
    v269 = 0;
    sub_8524C0(&v269, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v269, 0);
    *v0_x = v269;
    *v0_y = *(&v269 + 1);
    *v0_z = v270;
    *v0_x = -*v0_x;
    *v0_y = -*v0_y;
    v43 = -*v0_z;
    goto LABEL_436;
  }
  if (op_Equality(objname, "npc_extra01", 0))
  {
    *soften = 15.0;
    *bias = 0.0;
    *l0_r = *l0_r * 1.1;
    *l0_g = *l0_g * 1.1;
    v33 = 1.4;
    *l0_b = *l0_b * 1.1;
    goto LABEL_24;
  }
  if (op_Equality(objname, "player_tatoo_e719", 0))
  {
    *soften = 7.0;
    v32 = 1.6;
    *bias = *bias + 0.05;
    v31 = *l0_r;
    goto LABEL_23;
  }
  if (op_Equality(objname, "player_tatoo_e723_raidou", 0))
  {
    v197 = GetEventCamName();
    if (op_Equality(v197, "cut01", 0)
      || op_Equality(v197, "cut02", 0)
      || op_Equality(v197, "cut03", 0)
      || op_Equality(v197, "cut04", 0))
    {
      *soften = 7.0;
      *bias = 0.25;
      *l0_r = *l0_r * 0.7;
      *l0_g = *l0_g * 0.7;
      *l0_b = *l0_b * 0.7;
      *a0_r = *a0_r * 0.85;
      v36 = *a0_g * 0.82;
      v33 = 0.8;
      goto LABEL_27;
    }
    *soften = 7.0;
    *bias = -0.2;
    if (!op_Equality(v197, "camera02", 0)
      && !op_Equality(v197, "camera03", 0)
      && !op_Equality(v197, "camera04", 0))
    {
      v94 = *l0_r;
      v95 = 0.75;
      goto LABEL_160;
    }
LABEL_159:
    v94 = *l0_r;
    v95 = 0.7;
LABEL_160:
    *l0_r = v94 * v95;
    *l0_g = *l0_g * v95;
    *l0_b = *l0_b * v95;
    v33 = 0.8;
    goto LABEL_24;
  }
  if (op_Equality(objname, "mokoi_e723", 0))
  {
    *soften = 7.0;
    *bias = -0.2;
    v33 = 0.8;
    *l0_r = *l0_r * 0.8;
    *l0_g = *l0_g * 0.75;
    *l0_b = *l0_b * 0.75;
    v35 = *a0_r * 0.9;
    goto LABEL_26;
  }
  if (op_Equality(objname, "raidou_e723", 0))
  {
    *soften = 7.0;
    *bias = -0.2;
    v199 = GetEventCamName();
    if (op_Equality(v199, "cut01", 0)
      || op_Equality(v199, "cut02", 0)
      || op_Equality(v199, "cut03", 0)
      || op_Equality(v199, "cut04", 0)
      || op_Equality(v199, "cut05", 0)
      || op_Equality(v199, "cut06", 0))
    {
      v200 = *l0_r;
      v201 = 0.7;
    }
    else
    {
      v200 = *l0_r;
      v201 = 0.8;
    }
    *l0_r = v200 * v201;
    *l0_g = *l0_g * v201;
    v202 = *l0_b * v201;
    v33 = 0.75;
    *l0_b = v202;
    goto LABEL_24;
  }
  if (op_Equality(objname, "gouto_e723", 0))
  {
    *soften = 7.0;
    *bias = -0.2;
    goto LABEL_159;
  }
  if (op_Equality(objname, "player_tatoo_e723_010", 0))
  {
    if (!evtBitCheck(3712))
      goto LABEL_108;
    *l0_r = *l0_r * 1.2;
    v52 = *l0_g * 1.2;
    v33 = 1.1;
    goto LABEL_49;
  }
  if (op_Equality(objname, "player_tatoo_e723_030", 0))
  {
    if (!evtBitCheck(3712))
      goto LABEL_108;
    NowCameraName = GetNowCameraName();
    if (op_Equality(NowCameraName, "Camera03", 0)
      || op_Equality(NowCameraName, "Camera04", 0)
      || op_Equality(NowCameraName, "Camera05", 0))
    {
      goto LABEL_22;
    }
    v206 = op_Equality(NowCameraName, "Camera06", 0);
    v178 = *l0_r;
    if (!v206)
    {
      *l0_r = v178 * 0.9;
      *l0_g = *l0_g * 0.9;
      *l0_b = *l0_b * 0.9;
      *a0_r = *a0_r * 1.1;
      goto LABEL_108;
    }
    v179 = 0.7;
LABEL_383:
    *l0_r = v178 * v179;
    *l0_g = *l0_g * 0.8;
    *l0_b = *l0_b * 0.8;
    v35 = *a0_r * 0.8;
    v33 = 0.9;
    goto LABEL_26;
  }
  if (op_Equality(objname, "dante_e723_030", 0))
  {
    v208 = GetNowCameraName();
    if (op_Equality(v208, "Camera03", 0)
      || op_Equality(v208, "Camera04", 0)
      || op_Equality(v208, "Camera05", 0)
      || op_Equality(v208, "Camera06", 0))
    {
      *soften = 24.0;
      *bias = -0.22;
      *l0_r = *l0_r * 1.1;
      *l0_g = *l0_g * 1.1;
      v102 = 1.2;
      *l0_b = *l0_b * 1.1;
      v103 = *a0_r * 1.2;
      goto LABEL_180;
    }
    if (!op_Equality(v208, "Camera07", 0))
      goto LABEL_108;
    *soften = 5.0;
    *bias = -0.22;
    *l0_g = *l0_g * 0.9;
    *l0_b = *l0_b * 0.9;
    v122 = *a0_r * 1.2;
    v121 = 1.1;
    goto LABEL_223;
  }
  if (op_Equality(objname, "dante_e723", 0))
  {
    v238 = GetEventCamName();
    if (op_Equality(v238, "cam05", 0))
    {
      *soften = 25.0;
      *bias = -0.6;
      *l0_r = (*l0_r * 1.15) + 0.1;
      *l0_g = *l0_g + 0.0;
      v149 = *l0_b + 0.0;
      v33 = 0.8;
      v145 = 0.7;
    }
    else
    {
      v240 = GetEventCamName();
      if (op_Equality(v240, "cam04", 0))
      {
        *soften = 21.0;
        *bias = -0.5;
        *l0_r = *l0_r * 1.3;
        *l0_g = *l0_g * 1.2;
        *l0_b = *l0_b * 1.2;
        *l0_r = *l0_r + 0.15;
        *l0_g = *l0_g + 0.0;
        *l0_b = *l0_b + 0.1;
        *a0_r = *a0_r * 1.1;
        v36 = *a0_g * 0.8;
        v33 = 0.9;
        goto LABEL_27;
      }
      v242 = GetEventCamName();
      v243 = op_Equality(v242, "cam03", 0);
      *soften = 25.0;
      if (!v243)
      {
        *bias = -0.2;
        *l0_r = *l0_r * 1.3;
        *l0_g = *l0_g * 1.1;
        *l0_b = *l0_b * 1.2;
        *l0_r = *l0_r + 0.2;
        *l0_g = *l0_g + 0.05;
        *l0_b = *l0_b + 0.05;
        v87 = 0.1;
        *a0_r = *a0_r * 0.9;
        goto LABEL_149;
      }
      *bias = -0.1;
      *l0_r = *l0_r * 1.2;
      *l0_g = *l0_g * 1.1;
      *l0_b = *l0_b * 1.15;
      *l0_r = *l0_r + 0.0;
      *l0_g = *l0_g + 0.0;
      v149 = *l0_b + 0.1;
      v33 = 0.9;
      v145 = 0.8;
    }
    goto LABEL_299;
  }
  if (op_Equality(objname, "player_tatoo_e723", 0))
  {
    *l0_r = *l0_r * 0.8;
    *l0_g = *l0_g * 0.85;
    v33 = 0.9;
    *l0_b = *l0_b * 0.85;
    goto LABEL_24;
  }
  if (op_Equality(objname, "e726_body_blood", 0))
  {
    *soften = 15.0;
    *bias = 0.0;
    *l0_r = *l0_r * 0.5;
    *l0_g = *l0_g * 0.5;
    *l0_b = *l0_b * 0.5;
    *a0_r = *a0_r * 0.5;
    *a0_g = *a0_g * 0.5;
    v76 = 0.0;
    *a0_b = *a0_b * 0.5;
    *v0_x = 0.0;
    *v0_y = -1.0;
    *v0_z = 0.0;
      goto LABEL_105;
    goto LABEL_103;
  }
  if (op_Equality(objname, "e726_lucifer", 0))
  {
    v245 = fminf(fmaxf(GetNowFrame() + -400.0, 0.0), 50.0) / 50.0;
    *soften = 7.001;
    v246 = (v245 * 0.5) + 0.5;
    *bias = v245 * -0.3;
    *l0_r = *l0_r * v246;
    *l0_g = *l0_g * v246;
    *l0_b = *l0_b * v246;
    *v0_x = -0.081;
    *v0_y = v245 * -0.64;
    *v0_z = -0.764;
    v76 = -0.764;
      goto LABEL_105;
    goto LABEL_103;
  }
  if (op_Equality(objname, "dante_e728", 0))
  {
    v248 = GetEventCamName();
    if (op_Equality(v248, "01cam_02", 0))
    {
      *bias = 0.15;
      *l0_r = *l0_r * 1.2;
      *l0_g = *l0_g * 1.3;
      *l0_b = *l0_b * 1.4;
      *l0_r = *l0_r + 0.1;
      *l0_g = *l0_g + 0.2;
      *l0_b = *l0_b + 0.2;
      v33 = 1.5;
      *a0_r = *a0_r * 1.3;
      v36 = *a0_g * 1.4;
      goto LABEL_27;
    }
    if (op_Equality(v248, "01cam_03", 0))
    {
      *bias = 0.15;
      *l0_r = *l0_r * 1.3;
      *l0_g = *l0_g * 1.3;
      *l0_b = *l0_b * 1.4;
      *l0_r = *l0_r + 0.1;
      *l0_g = *l0_g + 0.2;
      *l0_b = *l0_b + 0.2;
      *a0_r = *a0_r * 1.3;
      *a0_g = *a0_g * 1.4;
      *a0_b = *a0_b * 1.5;
      v87 = 0.3;
      *a0_r = *a0_r + 0.0;
      v90 = *a0_g + 0.2;
      goto LABEL_148;
    }
    if (op_Equality(v248, "01cam_04", 0))
    {
      *bias = 0.15;
      *l0_r = *l0_r * 1.3;
      *l0_g = *l0_g * 1.3;
      *l0_b = *l0_b * 1.4;
      v114 = 0.2;
      *l0_r = *l0_r + 0.1;
      *l0_g = *l0_g + 0.2;
      *l0_b = *l0_b + 0.2;
      *a0_r = *a0_r * 1.3;
      *a0_g = *a0_g * 1.4;
      *a0_b = *a0_b * 1.5;
      *a0_r = *a0_r + 0.0;
      v115 = *a0_g + 0.2;
LABEL_204:
      *a0_g = v115;
      v91 = *a0_b + v114;
      goto LABEL_150;
    }
    if (op_Equality(v248, "01cam_05", 0))
    {
      *bias = 0.15;
      *l0_r = *l0_r * 1.3;
      *l0_g = *l0_g * 1.3;
      *l0_b = *l0_b * 1.4;
      *l0_r = *l0_r + 0.0;
      *l0_g = *l0_g + 0.2;
      *l0_b = *l0_b + 0.2;
      *a0_r = *a0_r * 1.3;
      *a0_g = *a0_g * 1.4;
      *a0_b = *a0_b * 1.5;
      v251 = *a0_r + 0.2;
LABEL_617:
      *a0_r = v251;
      v89 = *a0_g;
      v87 = 0.3;
      goto LABEL_147;
    }
    if (op_Equality(v248, "01cam_08", 0))
    {
      *bias = 0.15;
      *l0_r = *l0_r * 1.1;
      *l0_g = *l0_g * 1.2;
      *l0_b = *l0_b * 1.2;
      *a0_r = *a0_r * 1.3;
      *a0_g = *a0_g * 1.4;
      *a0_b = *a0_b * 1.5;
      v251 = *a0_r + 0.2;
      goto LABEL_617;
    }
    if (op_Equality(v248, "01cam_06", 0))
    {
      *bias = 0.15;
      v250 = *a0_g * 1.1;
      v249 = 1.2;
      goto LABEL_606;
    }
    if (op_Equality(v248, "01cam_07", 0)
      || op_Equality(v248, "01cam_09", 0))
    {
      *bias = 0.15;
      *l0_r = *l0_r * 1.2;
      *l0_g = *l0_g * 1.2;
      *l0_b = *l0_b * 1.3;
      *l0_r = *l0_r + 0.1;
      *l0_g = *l0_g + 0.2;
      *l0_b = *l0_b + 0.2;
      *a0_r = *a0_r * 1.3;
      *a0_g = *a0_g * 1.4;
      *a0_b = *a0_b * 1.5;
      *a0_r = *a0_r + 0.0;
      *a0_g = *a0_g + 0.2;
      v91 = *a0_b + 0.2;
      goto LABEL_150;
    }
  }
  else
  {
    if (op_Equality(objname, "player_tatoo_e728", 0))
    {
      v176 = *l0_r;
      v177 = 1.1;
      goto LABEL_380;
    }
    if (op_Equality(objname, "dante_e729", 0))
    {
      *bias = 0.0;
      *l0_r = *l0_r * 1.2;
      *l0_g = *l0_g * 1.2;
      *l0_b = *l0_b * 1.2;
      *l0_r = *l0_r + 0.2;
      *l0_g = *l0_g + 0.2;
      v249 = 1.3;
      *l0_b = *l0_b + 0.2;
      *a0_r = *a0_r * 1.3;
      v250 = *a0_g * 1.3;
LABEL_606:
      *a0_g = v250;
      *a0_b = *a0_b * v249;
      *a0_r = *a0_r + 0.0;
      v87 = 0.1;
      goto LABEL_146;
    }
    if (op_Equality(objname, "dante_e730", 0))
    {
      *bias = 0.0;
      v84 = *l0_r * 1.05;
      v83 = 1.15;
      goto LABEL_133;
    }
    if (op_Equality(objname, "raidou_e730", 0))
    {
      *soften = 7.0;
      *bias = 0.0;
      v84 = *l0_r * 0.9;
      v83 = 0.95;
      goto LABEL_133;
    }
    if (!op_Equality(objname, "player_tatoo_e730", 0)
      && !op_Equality(objname, "player_tatoo_e730_raidou", 0))
    {
      if (op_Equality(objname, "dante_e731", 0))
      {
        v253 = GetEventCamName();
        if (op_Equality(v253, "01cam_07", 0))
        {
          *soften = 21.0;
          *bias = -0.36;
          v33 = 1.4;
          *l0_r = *l0_r * 1.4;
          *l0_g = *l0_g * 1.4;
          *l0_b = *l0_b * 1.4;
          v35 = *a0_r * 1.3;
          goto LABEL_26;
        }
        if (!op_Equality(v253, "01cam_09", 0))
        {
          if (op_Equality(v253, "01cam_11", 0))
          {
            *bias = -0.46;
            *l0_r = *l0_r * 1.2;
            *l0_g = *l0_g * 1.2;
            *l0_b = *l0_b * 1.2;
            v254 = *a0_r * 1.3;
          }
          else
          {
            if (!op_Equality(v253, "01cam_12", 0))
            {
              if (!op_Equality(v253, "01cam_13", 0))
                goto LABEL_108;
              goto LABEL_132;
            }
            *bias = 0.0;
            *l0_r = *l0_r * 1.4;
            *l0_g = *l0_g * 1.4;
            *l0_b = *l0_b * 1.4;
            v254 = *a0_r * 1.3;
          }
          *a0_r = v254;
          *a0_g = *a0_g * 1.4;
          *a0_b = *a0_b * 1.5;
          v87 = 0.2;
          v86 = *a0_r;
          goto LABEL_144;
        }
        *bias = -0.28;
        *l0_r = *l0_r * 1.2;
        *l0_g = *l0_g * 1.3;
        *l0_b = *l0_b * 1.3;
        *a0_r = *a0_r * 1.3;
        v104 = *a0_g * 1.4;
        v102 = 1.5;
        goto LABEL_181;
      }
      if (op_Equality(objname, "DANTE_UNIT", 0))
      {
        *soften = 7.0;
        *bias = 0.0;
LABEL_47:
        v51 = *l0_r;
        v33 = 1.1;
LABEL_48:
        *l0_r = v51 * v33;
        v52 = *l0_g * v33;
LABEL_49:
        *l0_g = v52;
        *l0_b = *l0_b * v33;
        goto LABEL_24;
      }
      if (op_Equality(objname, "npc_kaihuku_e801", 0))
      {
        v171 = *l0_r;
        v172 = 1.1;
        goto LABEL_364;
      }
      if (op_Equality(objname, "npc_mane_e802", 0))
      {
        v171 = *l0_r;
        v172 = 0.9;
        goto LABEL_364;
      }
      if (op_Equality(objname, "devil_0x3c_shop_0", 0)
        || op_Equality(objname, "npc_mane_f", 0)
        || op_Equality(objname, "npc_rag_e803", 0))
      {
        goto LABEL_222;
      }
    }
  }
LABEL_108:
  if (op_Equality(objname, "f803_chain", 0))
    v79 = 0;
  else
    v79 = 322;
  if (v79 == 322)
  {
    v80 = *soften;
    BasicLight_Char_Color_Standard(v80, l0_r, l0_g, l0_b, a0_r, a0_g, a0_b);
  }
  else
  {
    *a0_r = *a0_r * 0.9;
    *a0_g = *a0_g * 0.9;
    *a0_b = *a0_b * 0.9;
  }
  if (op_Equality(objname, "npc_tiaki_e684", 0)
    || op_Equality(objname, "npc_tiaki_e684_010", 0))
  {
    *l0_r = bk_l0_r;
    *l0_g = bk_l0_g;
    *l0_b = bk_l0_b;
    *a0_r = bk_a0_r;
    *a0_g = bk_a0_g;
    *a0_b = bk_a0_b;
    *soften = 0.0;
    *bias = 0.0;
    *rim = 29.0;
  }
  else if (op_Equality(objname, "npc_isamu_e655_010", 0)
         || op_Equality(objname, "npc_isamu_e655_010_mirrer", 0))
  {
    *l0_r = 0.0;
    *l0_g = 0.0;
    *l0_b = 0.0;
    *a0_r = 0.0;
    *a0_g = 0.0;
    *a0_b = 0.0;
  }
}

// 0x1805a40
void BasicLight_Char_Color_Standard(f32 soften, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b) {
  s32 v8;
  s64 v9;
  f32 v10;
  f32 v11;

  v8 = (soften + 0.001) - 2;
  if (v8 <= 0x12 && ((0x43FFFu >> v8) & 1) != 0)
  {
    v9 = 4LL * v8;
    v10 = *(&unk_33CD978 + v9);
    v11 = *(&unk_33CD9C4 + v9);
    *l0_r = *l0_r * v10;
    *l0_g = *l0_g * v10;
    *l0_b = *l0_b * v10;
    *a0_r = *a0_r * v11;
    *a0_g = *a0_g * v11;
    *a0_b = *a0_b * v11;
  }
}

// 0x1806590
void BattleLight_Char_Color(char *objname, nbFormation_t *unit_form, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim) {
  f32 v21;
  f32 v22;
  f32 v23;
  f32 *v25;
  f32 *v26;
  f32 *v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 *v35;
  f32 *v36;
  f32 *v37;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *transform;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  UnityEngine_GameObject_o *v48;
  Il2CppObject *v49;
  UnityEngine_Transform_o *v50;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  s32 v58;
  bool v59;
  f32 v60;
  struct fldGlobalWork_t_o *fldGb;
  f32 v63;
  s64 v67;
  s32 v68;
  UnityEngine_Quaternion_o v69;
  s64 v70;
  s32 v71;
  UnityEngine_Quaternion_o rotation;
  s64 v73;
  s32 v74;

  *&rotation.x = 0;
  *&rotation.z = 0;
  v71 = 0;
  *&v69.z = 0;
  v70 = 0;
  *&v69.x = 0;
  v68 = 0;
  v67 = 0;
  if (op_Equality(objname, "devil_0x03(Clone)", 0))
  {
    *l0_r = *l0_r * 0.8;
    *l0_g = *l0_g * 0.8;
    v21 = *l0_b * 0.8;
    v22 = 0.9;
LABEL_7:
    *l0_b = v21;
    *a0_r = *a0_r * v22;
    v23 = *a0_g * v22;
LABEL_8:
    *a0_g = v23;
    *a0_b = *a0_b * v22;
    return;
  }
  if (op_Equality(objname, "devil_0x06(Clone)", 0))
  {
    v22 = 0.2;
    *l0_r = *l0_r * 0.2;
    *l0_g = *l0_g * 0.2;
    v21 = *l0_b * 0.2;
    goto LABEL_7;
  }
  if (op_Equality(objname, "devil_0x100(Clone)", 0))
  {
    *l0_r = *l0_r * 1.1;
    *l0_g = *l0_g * 1.1;
    *l0_b = *l0_b * 1.1;
    *l0_r = *l0_r + 0.0;
    *l0_g = *l0_g + 0.0;
    *l0_b = *l0_b + 0.2;
    *a0_r = *a0_r * 1.3;
    *a0_g = *a0_g * 1.2;
    *a0_b = *a0_b * 1.3;
    *soften = 7.0;
    *bias = 0.0;
    v25 = v0_y;
    v26 = v0_x;
    v27 = v0_z;
    v74 = 0;
    v73 = 0;
    sub_8524C0(&v73, *v0_x, *v0_y, *v0_z);
    sub_8531D0(&v73, 0);
    *v0_x = v73;
    *v0_y = *(&v73 + 1);
    *v0_z = v74;
    v28 = *v0_y;
    v29 = 1.5;
LABEL_14:
    v30 = v28 * v29;
    *v25 = v30;
    v74 = 0;
    v73 = 0;
    v31 = *v26;
    v32 = *v27;
LABEL_15:
    sub_8524C0(&v73, v31, v30, v32);
    sub_8531D0(&v73, 0);
    *v26 = v73;
    *v25 = *(&v73 + 1);
    *v27 = v74;
    return;
  }
  if (op_Equality(objname, "devil_0x9b(Clone)", 0)
    || op_Equality(objname, "devil_0x116(Clone)", 0))
  {
    *soften = 7.0;
    *bias = 0.0;
    *l0_r = *l0_r * 0.9;
    *l0_g = *l0_g * 0.9;
    *l0_b = *l0_b * 0.9;
    *a0_r = *a0_r * 0.9;
    *a0_g = *a0_g * 0.9;
    *a0_b = *a0_b * 0.9;
    {
      v36 = v0_z;
      v35 = v0_y;
      v37 = v0_x;
    }
    else
    {
      v36 = v0_z;
      v35 = v0_y;
      v37 = v0_x;
    }
    MainCamera = GetMainCamera(kernelObject);
    Component_object = GetComponent_object_(MainCamera);
    transform = get_transform(Component_object, 0);
    rotation = get_rotation(transform);
    sub_1A1CAE0(&rotation.x, 0);
    v43 = v42 * 0.017453;
    v44 = sinf(v43);
    v45 = cosf(v43);
    sub_8524C0(&v70, -v44, 0.0, -v45);
    sub_8531D0(&v70, 0);
    HIDWORD(v70) = -1082130432;
    sub_8531D0(&v70, 0);
    *v37 = v70;
    *v35 = *(&v70 + 1);
    *v36 = v71;
  }
  else if (op_Equality(objname, "devil_0x117(Clone)", 0)
         || op_Equality(objname, "devil_0x118(Clone)", 0)
         || op_Equality(objname, "devil_0x119(Clone)", 0)
         || op_Equality(objname, "devil_0x11a(Clone)", 0))
  {
    *soften = 7.0;
    *bias = 0.0;
    *l0_r = *l0_r * 1.1;
    *l0_g = *l0_g * 1.1;
    *l0_b = *l0_b * 1.1;
    *l0_r = *l0_r + 0.1;
    *l0_g = *l0_g + 0.1;
    *l0_b = *l0_b + 0.1;
    *a0_r = *a0_r * 1.1;
    *a0_g = *a0_g * 1.1;
    *a0_b = *a0_b * 1.1;
    *v0_x = 0.0;
    *v0_y = -1.0;
    *v0_z = -0.8;
    v48 = GetMainCamera(kernelObject);
    v49 = GetComponent_object_(v48);
    v50 = get_transform(v49, 0);
    v69 = get_rotation(v50);
    sub_1A1CAE0(&v69.x, 0);
    v53 = v52 * 0.017453;
    v54 = sinf(v53);
    v55 = cosf(v53);
    sub_8524C0(&v67, -v54, 0.0, -v55);
    sub_8531D0(&v67, 0);
    HIDWORD(v67) = -1082130432;
    sub_8531D0(&v67, 0);
    *v0_x = v67;
    *v0_y = *(&v67 + 1);
    *v0_z = v68;
  }
  else if (op_Equality(objname, "devil_0x123(Clone)", 0))
  {
    *l0_r = *l0_r * 1.3;
    *l0_g = *l0_g * 1.3;
    *l0_b = *l0_b * 1.4;
    *a0_r = *a0_r * 1.3;
    *a0_g = *a0_g * 1.3;
    *a0_b = *a0_b * 1.4;
    *soften = 7.0;
    *bias = 0.2;
  }
  else
  {
    if (op_Equality(objname, "devil_0x125(Clone)", 0))
    {
      *soften = 0.0;
      *bias = 0.5;
      *l0_r = *l0_r * 0.6;
      *l0_g = *l0_g * 0.6;
      *l0_b = *l0_b * 0.8;
      *a0_r = *a0_r * 0.4;
      v23 = *a0_g * 0.4;
      v22 = 0.7;
      goto LABEL_8;
    }
    if (op_Equality(objname, "devil_0x108(Clone)", 0))
    {
      *soften = 7.0;
      *bias = 0.0;
      *l0_r = *l0_r * 0.7;
      *l0_g = *l0_g * 0.7;
      *l0_b = *l0_b * 0.8;
      *a0_r = *a0_r * 0.3;
      *a0_g = *a0_g * 0.3;
      *a0_b = *a0_b * 0.4;
      v25 = v0_y;
      v26 = v0_x;
      v27 = v0_z;
      v74 = 0;
      v73 = 0;
      sub_8524C0(&v73, *v0_x, *v0_y, *v0_z);
      sub_8531D0(&v73, 0);
      *v0_x = v73;
      *v0_y = *(&v73 + 1);
      *v0_z = v74;
      v28 = *v0_y;
      v29 = -1.25;
      goto LABEL_14;
    }
    if (op_Equality(objname, "devil_0x156(Clone)", 0))
    {
      *soften = 7.0;
      *bias = -0.3;
      *v0_x = -*v0_x;
    }
    else if (op_Equality(objname, "devil_0xc4(Clone)", 0))
    {
      *l0_r = *l0_r * 1.3;
      *l0_g = *l0_g * 1.3;
      *l0_b = *l0_b * 1.3;
      *l0_r = *l0_r + 0.1;
      *l0_g = *l0_g + 0.1;
      *l0_b = *l0_b + 0.1;
      *a0_r = *a0_r * 1.1;
      *a0_g = *a0_g * 1.1;
      *a0_b = *a0_b * 1.1;
      *soften = 7.0;
      *bias = 0.0;
    }
    else if (Equals_5234480(objname, "devil_0xc0d(Clone)", 0))
    {
      if (unit_form && (unit_form->stat & 0x200) != 0)
      {
        if (fldGb->fieldID != 223)
          goto LABEL_67;
        if (fldGb->areaID != 2)
        {
LABEL_67:
          *l0_r = *l0_r * 1.4;
          *l0_g = *l0_g * 1.3;
          *l0_b = *l0_b * 1.3;
          *l0_r = *l0_r + 0.1;
          *l0_g = *l0_g + 0.1;
          *l0_b = *l0_b + 0.1;
          *a0_r = *a0_r * 1.4;
          *a0_g = *a0_g * 1.2;
          v63 = 0.0;
          *a0_b = *a0_b * 1.2;
          *a0_r = *a0_r + 0.1;
          *a0_g = *a0_g + 0.0;
          *a0_b = *a0_b + 0.0;
          *soften = 4.001;
          *bias = 0.3;
          *v0_y = 0.0;
          v26 = v0_x;
          v27 = v0_z;
          v74 = 0;
          v73 = 0;
          sub_8524C0(&v73, *v0_x, v63, *v0_z);
          sub_8531D0(&v73, 0);
          *v0_x = v73;
          v25 = v0_y;
          *v0_z = v74;
          *v0_y = 0.25;
          v74 = 0;
          v73 = 0;
          v31 = *v0_x;
          v32 = *v0_z;
          v30 = 0.25;
          goto LABEL_15;
        }
        *l0_r = *l0_r * 1.3;
        *l0_g = *l0_g * 1.3;
        *l0_b = *l0_b * 1.3;
        *l0_r = *l0_r + 0.1;
        *l0_g = *l0_g + 0.1;
        *l0_b = *l0_b + 0.1;
        *a0_r = *a0_r * 1.2;
        *a0_g = *a0_g * 1.2;
        *a0_b = *a0_b * 1.2;
        *soften = 7.0;
        v58 = -1091190129;
      }
      else
      {
        *l0_r = *l0_r * 1.3;
        *l0_g = *l0_g * 1.3;
        *l0_b = *l0_b * 1.3;
        *l0_r = *l0_r + 0.1;
        *l0_g = *l0_g + 0.1;
        *l0_b = *l0_b + 0.1;
        *a0_r = *a0_r * 1.3;
        *a0_g = *a0_g * 1.3;
        *a0_b = *a0_b * 1.3;
        *soften = 7.0;
        v58 = 1053609165;
      }
      *bias = v58;
    }
    else
    {
      v59 = op_Equality(objname, "devil_0x11b(Clone)", 0);
      v60 = *l0_r;
      if (v59)
      {
        *l0_r = v60 * 1.4;
        *l0_g = *l0_g * 1.4;
        *l0_b = *l0_b * 1.4;
      }
      else
      {
        *l0_r = v60 * 1.3;
        *l0_g = *l0_g * 1.3;
        *l0_b = *l0_b * 1.3;
        *l0_r = *l0_r + 0.1;
        *l0_g = *l0_g + 0.1;
        *l0_b = *l0_b + 0.1;
        *a0_r = *a0_r * 1.1;
        *a0_g = *a0_g * 1.1;
        *a0_b = *a0_b * 1.1;
        *soften = 7.0;
        *bias = 0.0;
      }
    }
  }
}

// 0x1806290
void CampLight_Char_Color(char *objname, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim) {
  f32 v22;
  f32 v23;
  UnityEngine_GameObject_o *CampCameraObj;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *transform;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  s64 v35;
  s32 v36;
  UnityEngine_Quaternion_o rotation;

  *&rotation.x = 0;
  *&rotation.z = 0;
  v36 = 0;
  v35 = 0;
  if (op_Equality(objname, "devil_0x03(Clone)", 0))
  {
    *l0_r = *l0_r * 0.8;
    *l0_g = *l0_g * 0.8;
    v22 = *l0_b * 0.8;
    v23 = 0.9;
LABEL_7:
    *l0_b = v22;
    *a0_r = *a0_r * v23;
    *a0_g = *a0_g * v23;
    *a0_b = *a0_b * v23;
    return;
  }
  if (op_Equality(objname, "devil_0x06(Clone)", 0))
  {
    v23 = 0.1;
    *l0_r = *l0_r * 0.1;
    *l0_g = *l0_g * 0.1;
    v22 = *l0_b * 0.1;
    goto LABEL_7;
  }
  if (op_Equality(objname, "devil_0x3c(Clone)", 0))
  {
    *bias = -0.2;
  }
  else if (op_Equality(objname, "devil_0x9b(Clone)", 0))
  {
    *l0_r = *l0_r * 0.9;
    *l0_g = *l0_g * 0.9;
    *l0_b = *l0_b * 0.9;
    *a0_r = *a0_r * 0.9;
    *a0_g = *a0_g * 0.9;
    *a0_b = *a0_b * 0.9;
    CampCameraObj = GetCampCameraObj(kernelObject);
    Component_object = GetComponent_object_(CampCameraObj);
    transform = get_transform(Component_object, 0);
    rotation = get_rotation(transform);
    sub_1A1CAE0(&rotation.x, 0);
    v31 = v30 * 0.017453;
    v32 = sinf(v31);
    v33 = cosf(v31);
    sub_8524C0(&v35, -v32, 0.0, -v33);
    sub_8531D0(&v35, 0);
    HIDWORD(v35) = -1082130432;
    sub_8531D0(&v35, 0);
    *v0_x = v35;
    *v0_y = *(&v35 + 1);
    *v0_z = v36;
  }
}

// 0x1004130
bool ChkAtlusMat(void *rootobj) {
  Il2CppObject *Component_object;
  UnityEngine_Material_o *sharedMaterial;
  UnityEngine_Object_o *shader;
  System_String_o *name;
  UnityEngine_Transform_o *transform;
  s32 v11;
  UnityEngine_Transform_o *v12;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v16;

  Component_object = GetComponent_object_(rootobj);
  if (op_Inequality(Component_object, 0, 0))
  {
    sharedMaterial = get_sharedMaterial(Component_object);
    if (op_Inequality(sharedMaterial, 0, 0))
    {
      shader = get_shader(sharedMaterial);
      name = get_name(shader);
      if (op_Equality(name, "Atlus/AtlusMat", 0))
        return 1;
    }
  }
  transform = get_transform(rootobj, 0);
  if (get_childCount(transform) < 1)
    return 0;
  v11 = 0;
  while (1)
  {
    v12 = get_transform(rootobj, 0);
    Child = GetChild(v12, v11);
    gameObject = get_gameObject(Child);
    if (ChkAtlusMat(gameObject))
      break;
    ++v11;
    v16 = get_transform(rootobj, 0);
    if (v11 >= get_childCount(v16))
      return 0;
  }
  return 1;
}

// 0x1003fa0
bool ChkUseSceneLight(evtUnitHandle_t **h) {
  if (!*h)
    return 1;
  if (((*h)->Flag & 0x40100) != 0)
    return 0;
  return ((*h)->Flag & 0x1800) == 0;
}

// 0x17f0460
void Debug_OW_SkyAlp(void) {
  ;
}

// 0x100c620
void Eve_DOF_Set(s32 eveid, char *camname) {
  u64 v6;
  s32 v7;
  struct dds3UnityEx_Eve_DOF_array *Tbl_Eve_DOF;
  u64 max_length_low;
  struct dds3UnityEx_Eve_DOF_array *v13;
  struct dds3UnityEx_Eve_DOF_array *v16;
  struct dds3UnityEx_Eve_DOF_array *v19;
  struct dds3UnityEx_Eve_DOF_array *v22;
  struct dds3UnityEx_Eve_DOF_array *v25;
  struct dds3UnityEx_Eve_DOF_array *v28;
  struct dds3UnityEx_Eve_DOF_array *v31;
  bool v33;
  struct dds3UnityEx_Eve_DOF_array *v35;
  struct dds3UnityEx_Eve_DOF_array *v37;
  struct dds3UnityEx_Eve_DOF_array *v41;
  struct dds3UnityEx_Eve_DOF_array *v44;
  struct dds3UnityEx_Eve_DOF_array *v48;
  u32 v49;
  struct dds3UnityEx_Eve_DOF_array *v50;
  struct dds3UnityEx_Eve_DOF_array *v52;
  struct dds3UnityEx_Eve_DOF_array *v56;
  struct dds3UnityEx_Eve_DOF_array *v59;
  struct dds3UnityEx_Eve_DOF_array *v62;
  u32 max_length;
  struct dds3UnityEx_Eve_DOF_array *v64;
  u64 v66;
  f32 dofa;
  f32 dofb;
  dds3UnityEx_Eve_DOF_o *v71;
  f32 dofc;

  v6 = 0;
  v7 = fldGb->areaID + 1;
  {
LABEL_7:
    goto LABEL_10;
  }
  while (1)
  {
LABEL_10:
    max_length_low = LODWORD(Tbl_Eve_DOF->max_length);
    if (v6 >= max_length_low)
      goto LABEL_128;
    else if (v6 >= max_length_low)
    {
      goto LABEL_14;
    }
    if (Tbl_Eve_DOF->m_Items[v6]->eveno > eveid)
      goto LABEL_128;
    v13 = Tbl_Eve_DOF;
    if (v13->m_Items[v6]->eveno != eveid)
      goto LABEL_9;
    v16 = Tbl_Eve_DOF;
    if (v16->m_Items[v6]->area)
    {
      v19 = Tbl_Eve_DOF;
      if (v19->m_Items[v6]->area != v7)
        goto LABEL_9;
    }
    v22 = Tbl_Eve_DOF;
    if (v22->m_Items[v6]->dante)
    {
      v25 = Tbl_Eve_DOF;
      if (v25->m_Items[v6]->dante != 1 || !evtBitCheck(3712))
      {
        v28 = Tbl_Eve_DOF;
        if (v28->m_Items[v6]->dante != -1 || evtBitCheck(3712))
          goto LABEL_9;
      }
    }
    v31 = Tbl_Eve_DOF;
    v33 = op_Equality(v31->m_Items[v6]->cam, camname, 0);
    if (v33)
      break;
    v35 = Tbl_Eve_DOF;
    if (v35->m_Items[v6]->other)
    {
      v52 = Tbl_Eve_DOF;
      if (v52->m_Items[v6]->bloom >= 1)
      {
        PPSV2_update = 1;
        v56 = Tbl_Eve_DOF;
        PPSV2_bloom_type = v56->m_Items[v6]->bloom;
      }
      v59 = Tbl_Eve_DOF;
      if (v59->m_Items[v6]->dofa > 0.0)
      {
LABEL_123:
        v62 = Tbl_Eve_DOF;
        max_length = v62->max_length;
        v64 = Tbl_Eve_DOF;
        dofa = v62->m_Items[v6]->dofa;
        dofb = v64->m_Items[v6]->dofb;
        v71 = v64->m_Items[v6];
        goto LABEL_139;
      }
      goto LABEL_128;
    }
LABEL_9:
    ++v6;
      goto LABEL_7;
  }
  v37 = Tbl_Eve_DOF;
  if (v37->m_Items[v6]->bloom >= 1)
  {
    PPSV2_update = 1;
    v41 = Tbl_Eve_DOF;
    PPSV2_bloom_type = v41->m_Items[v6]->bloom;
  }
  v44 = Tbl_Eve_DOF;
  if (v44->m_Items[v6]->dofa <= 0.0)
  {
LABEL_128:
    DofOff();
      goto LABEL_134;
    goto LABEL_132;
  }
  if (eveid != 677 || !op_Equality(camname, "cam04", 0))
    goto LABEL_123;
  if (evtUpdateEx_CamCngCount != 4 || !evtBitCheck(147))
    goto LABEL_123;
  v48 = Tbl_Eve_DOF;
  v49 = v48->max_length;
  v50 = Tbl_Eve_DOF;
  dofa = v48->m_Items[v6 + 1]->dofa;
  dofb = v50->m_Items[v6 + 1]->dofb;
  v71 = v50->m_Items[v6 + 1];
LABEL_139:
  dofc = v71->dofc;
  DofSet(dofa, dofb, dofc);
  {
LABEL_132:
  }
LABEL_134:
  Ktyousei_DOF(v66);
}

// 0x1805b70
void FieldLight_Char_Color(char *objname, evtUnitHandle_t *hunit, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  u32 areaID;
  f32 v29;
  f32 v30;
  s32 v31;
  f32 *v33;
  f32 v34;
  f32 v35;
  f32 v36;
  bool v37;
  struct dds3Basic_t_o *BasicLight;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v45;
  f32 v46;
  s64 v48;
  s32 v49;

  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  if (op_Equality(objname, "mark_wpc(Clone)", 0))
  {
    *soften = 1.0;
    *bias = 0.0;
    *l0_r = *l0_r * 1.1;
    *l0_g = *l0_g * 1.1;
    *l0_b = *l0_b * 1.4;
    *a0_r = *a0_r * 1.1;
    *a0_g = *a0_g * 1.1;
    *a0_b = *a0_b * 1.2;
    if (fldGb->fieldID == 1)
    {
      *bias = -0.2;
      v49 = 0;
      v48 = 0;
      sub_8524C0(&v48, *v0_x, *v0_y, *v0_z);
      sub_8531D0(&v48, 0);
      *v0_x = v48;
      *v0_y = *(&v48 + 1);
      *v0_z = v49;
      v29 = *v0_y;
      v30 = -0.1;
    }
    else
    {
      v49 = 0;
      v48 = 0;
      sub_8524C0(&v48, *v0_x, *v0_y, *v0_z);
      sub_8531D0(&v48, 0);
      *v0_x = v48;
      *v0_y = *(&v48 + 1);
      *v0_z = v49;
      v29 = *v0_y;
      v30 = 0.1;
    }
    v36 = v29 * v30;
    *v0_y = v36;
    v49 = 0;
    v48 = 0;
    sub_8524C0(&v48, *v0_x, v36, *v0_z);
    sub_8531D0(&v48, 0);
    *v0_x = v48;
    *v0_y = *(&v48 + 1);
    *v0_z = v49;
  }
  else
  {
    v31 = areaID + 1;
    if (fieldID == 12 && v31 == 2)
    {
LABEL_59:
      v42 = *l0_r;
      v43 = 0.9;
LABEL_60:
      *l0_r = v42 * v43;
      *l0_g = *l0_g * v43;
      *l0_b = *l0_b * v43;
    }
    else
    {
      switch (fieldID)
      {
        case 13:
          goto LABEL_42;
        case 15:
          if (areaID - 3 <= 1)
            goto LABEL_39;
          goto LABEL_61;
        case 16:
LABEL_39:
          v41 = *l0_r * 1.1;
LABEL_40:
          *l0_r = v41;
          *l0_g = *l0_g * 1.1;
          v33 = a0_r;
          *l0_b = *l0_b * 1.1;
          v34 = *a0_r;
          v35 = 1.2;
          goto LABEL_62;
        case 18:
        case 28:
        case 30:
          v33 = a0_r;
          *l0_r = *l0_r * 0.8;
          *l0_g = *l0_g * 0.77;
          *l0_b = *l0_b * 0.77;
          v34 = *a0_r;
          v35 = 0.7;
          goto LABEL_62;
        case 20:
          switch (areaID)
          {
            case 0u:
            case 1u:
            case 4u:
            case 6u:
            case 7u:
            case 9u:
            case 0xDu:
            case 0x10u:
            case 0x11u:
            case 0x12u:
            case 0x13u:
            case 0x1Du:
              goto LABEL_42;
            case 8u:
            case 0xEu:
            case 0xFu:
            case 0x5Eu:
            case 0x5Fu:
            case 0x60u:
              v45 = *l0_r;
              v35 = 0.8;
              goto LABEL_52;
            case 0x17u:
            case 0x1Cu:
              v33 = a0_r;
              *l0_r = *l0_r * 0.9;
              *l0_g = *l0_g * 0.9;
              *l0_b = *l0_b * 0.9;
              v34 = *a0_r;
              v35 = 0.8;
              goto LABEL_62;
            case 0x18u:
              v45 = *l0_r;
              v35 = 0.7;
              goto LABEL_52;
            default:
              goto LABEL_61;
          }
        case 27:
          if (areaID <= 6 && ((1 << areaID) & 0x63) != 0)
          {
            v45 = *l0_r;
            v35 = 1.2;
LABEL_52:
            *l0_r = v45 * v35;
            *l0_g = *l0_g * v35;
            *l0_b = *l0_b * v35;
            *a0_r = *a0_r * v35;
            goto LABEL_63;
          }
          if (areaID <= 4)
          {
LABEL_42:
            v42 = *l0_r;
            v43 = 1.1;
            goto LABEL_60;
          }
          goto LABEL_61;
        default:
          if (hunit && (fieldID == 31 ? (v37 = v31 == 15) : (v37 = 0), v37))
          {
            BasicLight = hunit->BasicLight;
            if (BasicLight && op_Equality(BasicLight->name, "light02", 0))
            {
              v49 = 0;
              v48 = 0;
              sub_8524C0(&v48, *v0_x, *v0_y, *v0_z);
              sub_8531D0(&v48, 0);
              *v0_x = v48;
              *v0_y = *(&v48 + 1);
              *v0_z = v49;
              *v0_y = *v0_y * 5.0;
              v40 = *v0_z * 0.2;
              *v0_z = v40;
              v49 = 0;
              v48 = 0;
              sub_8524C0(&v48, *v0_x, *v0_y, v40);
              sub_8531D0(&v48, 0);
              *v0_x = v48;
              *v0_y = *(&v48 + 1);
              *v0_z = v49;
            }
LABEL_61:
            v33 = a0_r;
            *l0_r = *l0_r * 1.4;
            *l0_g = *l0_g * 1.4;
            *l0_b = *l0_b * 1.4;
            v34 = *a0_r;
            v35 = 1.3;
LABEL_62:
            *v33 = v34 * v35;
LABEL_63:
            *a0_g = *a0_g * v35;
            *a0_b = *a0_b * v35;
          }
          else
          {
            switch (fieldID)
            {
              case '"':
                if (areaID - 1 <= 1)
                  goto LABEL_59;
                goto LABEL_61;
              case '#':
                if (areaID)
                  v46 = 0.9;
                else
                  v46 = 1.1;
                *l0_r = *l0_r * v46;
                *l0_g = *l0_g * v46;
                *l0_b = *l0_b * v46;
                *a0_r = *a0_r + 0.1;
                *a0_g = *a0_g + 0.1;
                *a0_b = *a0_b + 0.1;
                break;
              case '(':
              case '-':
                if (!areaID)
                  goto LABEL_42;
                goto LABEL_61;
              case ')':
              case '*':
              case '+':
              case ',':
                if (v31 >= 3)
                  goto LABEL_61;
                goto LABEL_42;
              case '=':
                v41 = *l0_r * 0.9;
                goto LABEL_40;
              default:
                goto LABEL_61;
            }
          }
          break;
      }
    }
  }
}

// 0x1005670
s32 GetCamRunTime(void) {
  return evtUpdateEx_CamRunTime;
}

// 0x1005600
char *GetEventCamName(void) {
  return evtUpdateEx_Camname;
}

// 0x1003fe0
void *GetGameObject_PartName(void *rootobj, char *findname) {
  System_String_o *name;
  UnityEngine_Object_o *GameObject_PartName;
  UnityEngine_Transform_o *transform;
  s32 v8;
  UnityEngine_Transform_o *v9;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v15;

  name = get_name(rootobj);
  if (Contains(name, findname, 0))
    return rootobj;
  transform = get_transform(rootobj, 0);
  if (get_childCount(transform) < 1)
    return 0;
  v8 = 0;
  while (1)
  {
    v9 = get_transform(rootobj, 0);
    Child = GetChild(v9, v8);
    gameObject = get_gameObject(Child);
    GameObject_PartName = GetGameObject_PartName(gameObject, findname);
    if (op_Inequality(GameObject_PartName, 0, 0))
      break;
    ++v8;
    v15 = get_transform(rootobj, 0);
    if (v8 >= get_childCount(v15))
      return 0;
  }
  return GameObject_PartName;
}

// 0x17efd80
void Get_OW_SkyAlp(s32 idx, s32 alp, s32 *to_alp, s32 *to_par) {
  u64 v9;
  struct dds3UnityEx_Filter_OverwriteSky_array *Tbl_OverwriteSky;
  u64 max_length_low;
  s32 eveno;
  struct dds3UnityEx_Filter_OverwriteSky_array *v17;
  s32 v19;
  struct dds3UnityEx_Filter_OverwriteSky_array *v21;
  struct dds3UnityEx_Filter_OverwriteSky_array *v24;
  struct dds3UnityEx_Filter_OverwriteSky_array *v27;
  struct dds3UnityEx_Filter_OverwriteSky_array *v30;
  System_Object_array *v33;
  s64 *v37;
  s64 *v38;
  s64 *v41;
  s64 *v42;
  s64 *v45;
  s64 *v46;
  Il2CppObject *v49;
  s32 v50;
  struct dds3UnityEx_Filter_OverwriteSky_array *v57;
  struct dds3UnityEx_Filter_OverwriteSky_array *v59;
  s32 v61;
  s32 v62;
  s32 evtUpdateEx_NowEveNo;

  v9 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(Tbl_OverwriteSky->max_length);
    if (v9 >= max_length_low)
      break;
    else if (v9 >= max_length_low)
    {
      goto LABEL_12;
    }
    eveno = Tbl_OverwriteSky->m_Items[v9]->eveno;
    if (eveno > evtUpdateEx_NowEveNo)
      break;
    v17 = Tbl_OverwriteSky;
    v19 = v17->m_Items[v9]->eveno;
    else if (v19 != evtUpdateEx_NowEveNo)
    {
      goto LABEL_5;
    }
    v21 = Tbl_OverwriteSky;
    if (!v21->m_Items[v9]->dante)
      goto LABEL_49;
    v24 = Tbl_OverwriteSky;
    if (v24->m_Items[v9]->dante && evtBitCheck(3712))
    {
LABEL_49:
      v27 = Tbl_OverwriteSky;
      if (v27->m_Items[v9]->idx == idx)
      {
        v30 = Tbl_OverwriteSky;
        if (v30->m_Items[v9]->alp == alp)
        {
          v57 = Tbl_OverwriteSky;
          *to_alp = v57->m_Items[v9]->to_alp;
          v59 = Tbl_OverwriteSky;
          v50 = v59->m_Items[v9]->to_par;
          goto LABEL_89;
        }
      }
    }
LABEL_5:
    ++v9;
      goto LABEL_6;
  }
  if (idx)
  {
    v33 = NewSpecific(object, 6u);
    v33->m_Items[0] = "★★★フィールドフィルタの上書きテーブルが見つかりません★★★  eve:";
    v37 = sub_8D3950(s32, &evtUpdateEx_NowEveNo);
    v38 = v37;
    v33->m_Items[1] = v38;
    v33->m_Items[2] = " idx:";
    v62 = idx;
    v41 = sub_8D3950(s32, &v62);
    v42 = v41;
    v33->m_Items[3] = v42;
    v33->m_Items[4] = "  alp:";
    v61 = alp;
    v45 = sub_8D3950(s32, &v61);
    v46 = v45;
    v33->m_Items[5] = v46;
    v49 = Concat_5270224(v33);
    Log(v49, 0);
  }
  v50 = 0;
  *to_alp = alp;
LABEL_89:
  *to_par = v50;
}

// 0x17f0470
void Get_OW_SkyAlp_Btl(s32 tbl_idx, s32 *to_alp, s32 *to_par) {
  struct dds3UnityEx_Filter_OverwriteSky_Btl_array *v8;
  struct dds3UnityEx_Filter_OverwriteSky_Btl_array *v10;
  s64 v12;
  struct dds3UnityEx_Filter_OverwriteSky_Btl_array *Tbl_OverwriteSky_Btl;
  struct dds3UnityEx_Filter_OverwriteSky_Btl_array *v15;

  if (tbl_idx > 79)
  {
    *to_alp = Tbl_OverwriteSky_Btl->m_Items[100]->to_alp;
    v15 = Tbl_OverwriteSky_Btl;
    v12 = &v15->m_Items[100];
  }
  else
  {
    v8 = Tbl_OverwriteSky_Btl;
    *to_alp = v8->m_Items[tbl_idx]->to_alp;
    v10 = Tbl_OverwriteSky_Btl;
    v12 = &v10->m_Items[tbl_idx];
  }
  *to_par = *(*v12 + 32LL);
}

// 0x17efa00
bool Get_Skip_PM_Sky(s32 idx, s32 alp, s32 flame) {
  s64 v7;
  u64 v9;
  struct dds3UnityEx_Filter_SkipSky_array *Tbl_SkipSky;
  u64 max_length_low;
  s32 v14;
  struct dds3UnityEx_Filter_SkipSky_array *v16;
  s32 v18;
  struct dds3UnityEx_Filter_SkipSky_array *v20;
  struct dds3UnityEx_Filter_SkipSky_array *v23;
  struct dds3UnityEx_Filter_SkipSky_array *v26;
  struct dds3UnityEx_Filter_SkipSky_array *v29;
  struct dds3UnityEx_Filter_SkipSky_array *v32;

  v7 = 4;
  v9 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(Tbl_SkipSky->max_length);
    if (v9 >= max_length_low)
      return 0;
    else if (v9 >= max_length_low)
    {
      goto LABEL_12;
    }
    v14 = *(*(&Tbl_SkipSky->obj.klass + v7) + 16LL);
    if (v14 > evtUpdateEx_NowEveNo)
      return 0;
    v16 = Tbl_SkipSky;
    v18 = *(*(&v16->obj.klass + v7) + 16LL);
    else if (v18 != evtUpdateEx_NowEveNo)
    {
      goto LABEL_5;
    }
    v20 = Tbl_SkipSky;
    if (!*(*(&v20->obj.klass + v7) + 20LL))
      goto LABEL_55;
    v23 = Tbl_SkipSky;
    if (*(*(&v23->obj.klass + v7) + 20LL) && evtBitCheck(3712))
    {
LABEL_55:
      v26 = Tbl_SkipSky;
      if (*(*(&v26->obj.klass + v7) + 24LL) == idx)
      {
        v29 = Tbl_SkipSky;
        if (*(*(&v29->obj.klass + v7) + 28LL) == alp)
        {
          v32 = Tbl_SkipSky;
          if (*(*(&v32->obj.klass + v7) + 32LL) == flame)
            return 1;
        }
      }
    }
LABEL_5:
    ++v7;
    v9 = v7 - 4;
      goto LABEL_6;
  }
}

// 0x17fc3f0
void HighContrastTextureInit(void) {
  struct dds3DefaultMain_o *kernelObject;
  u64 *v4;
  u64 *v5;
  s64 v6;
  s64 v7;
  u32 *v8;
  u32 *v9;
  u32 *v10;
  s64 v11;
  u32 *v12;
  s32 v14;
  s32 v15;
  s32 v16;
  s64 v18;
  u32 *v19;
  f32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s64 v25;
  u32 *v26;
  f32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  f32 *p_b;
  s64 v33;
  s64 v34;
  f32 *v35;
  u64 v36;
  s64 v37;
  s32 v38;
  s32 v39;
  s32 v40;
  s64 v42;
  s64 v43;
  f32 *v44;
  s64 v45;
  s64 v46;
  u64 v47;
  s32 v48;
  s32 v49;
  s32 v50;
  Il2CppObject *v52;
  s32 v53;
  s32 v54;
  s32 v55;
  Il2CppObject *v57;
  s32 v58;
  s32 v59;
  s32 v60;
  Il2CppObject *v62;
  s32 v63;
  s32 v64;
  s32 v65;
  Il2CppObject *v67;
  s32 v68;
  s32 v69;
  s32 v70;
  Il2CppObject *v72;
  s32 v73;
  s32 v74;
  s32 v75;
  Il2CppObject *v77;
  s32 v78;
  s32 v79;
  s32 v80;
  Il2CppObject *v82;
  s32 v84;
  s32 v85;
  s32 v86;
  Il2CppObject *v88;
  s64 v89;
  f32 *v90;
  f32 v91;
  s32 v92;
  s32 v93;
  s32 v94;
  f32 *v96;
  s64 v97;
  f32 v98;
  s32 v99;
  s32 v100;
  s32 v101;
  f32 *v103;
  s64 v104;
  s32 v105;
  s32 v106;
  s32 v107;
  u32 *v109;
  f32 *v110;
  s64 v111;
  s64 v112;
  s64 v113;
  s64 v114;
  s64 v115;
  s32 v117;
  s32 v118;
  s32 v119;
  f32 *v121;
  s64 v122;
  f32 v123;
  s32 v124;
  s32 v125;
  s32 v126;
  s64 v128;
  f32 *v129;
  s32 v130;
  s32 v131;
  s32 v132;
  s64 v134;
  s64 v135;
  s64 v136;
  u32 *v137;
  s64 v138;
  f32 *v139;
  s64 v140;
  s32 v142;
  s32 v143;
  s32 v144;
  f32 *v146;
  s64 v147;
  f32 v148;
  s32 v149;
  s32 v150;
  s32 v151;
  s64 v153;
  f32 *v154;
  s32 v155;
  s32 v156;
  s32 v157;
  s64 v159;
  s64 v160;
  s64 v161;
  u32 *v162;
  s64 v163;
  s64 v164;
  s64 v165;
  s32 v167;
  s32 v168;
  s32 v169;
  f32 *v171;
  s64 v172;
  f32 v173;
  s32 v174;
  s32 v175;
  s32 v176;
  f32 *v178;
  s64 v179;
  f32 v180;
  s32 v181;
  s32 v182;
  s32 v183;
  f32 *v185;
  s64 v186;
  f32 v187;
  s32 v188;
  s32 v189;
  s32 v190;
  f32 *v192;
  s64 v193;
  f32 v194;
  s32 v195;
  s32 v196;
  s32 v197;
  s64 v199;
  s64 v200;
  s64 v201;
  u32 *v202;
  s64 v203;
  s64 v204;
  s64 v205;
  s32 v207;
  s32 v208;
  s32 v209;
  f32 *v211;
  s64 v212;
  f32 v213;
  s32 v214;
  s32 v215;
  s32 v216;
  f32 *v218;
  s64 v219;
  f32 v220;
  s32 v221;
  s32 v222;
  s32 v223;
  f32 *v225;
  s64 v226;
  f32 v227;
  s32 v228;
  s32 v229;
  s32 v230;
  f32 *v232;
  s64 v233;
  s32 v234;
  s32 v235;
  s32 v236;
  s64 v238;
  s64 v239;
  s64 v240;
  u32 *v241;
  s64 v242;
  s64 v243;
  s64 v244;
  s32 v246;
  s32 v247;
  s32 v248;
  f32 *v250;
  s64 v251;
  f32 v252;
  s32 v253;
  s32 v254;
  s32 v255;
  f32 *v257;
  s64 v258;
  f32 v259;
  s32 v260;
  s32 v261;
  s32 v262;
  f32 *v264;
  s64 v265;
  f32 v266;
  s32 v267;
  s32 v268;
  s32 v269;
  f32 *v271;
  s64 v272;
  s32 v273;
  s32 v274;
  s32 v275;
  s64 v277;
  s64 v278;
  s64 v279;
  u32 *v280;
  s64 v281;
  s64 v282;
  s64 v283;
  s32 v285;
  s32 v286;
  s32 v287;
  f32 *v289;
  s64 v290;
  f32 v291;
  s32 v292;
  s32 v293;
  s32 v294;
  f32 *v296;
  s64 v297;
  f32 v298;
  s32 v299;
  s32 v300;
  s32 v301;
  f32 *v303;
  s64 v304;
  f32 v305;
  s32 v306;
  s32 v307;
  s32 v308;
  f32 *v310;
  s64 v311;
  s32 v312;
  s32 v313;
  s32 v314;
  s64 v316;
  s64 v317;
  s64 v318;
  u32 *v319;
  s64 v320;
  s64 v321;
  s64 v322;
  s32 v324;
  s32 v325;
  s32 v326;
  f32 *v328;
  s64 v329;
  f32 v330;
  s32 v331;
  s32 v332;
  s32 v333;
  f32 *v335;
  s64 v336;
  f32 v337;
  s32 v338;
  s32 v339;
  s32 v340;
  f32 *v342;
  s64 v343;
  f32 v344;
  s32 v345;
  s32 v346;
  s32 v347;
  f32 *v349;
  s64 v350;
  s32 v351;
  s32 v352;
  s32 v353;
  s64 v355;
  s64 v356;
  s64 v357;
  u32 *v358;
  s64 v359;
  s64 v360;
  s64 v361;
  s32 v363;
  s32 v364;
  s32 v365;
  f32 *v367;
  s64 v368;
  f32 v369;
  s32 v370;
  s32 v371;
  s32 v372;
  f32 *v374;
  s64 v375;
  f32 v376;
  s32 v377;
  s32 v378;
  s32 v379;
  f32 *v381;
  s64 v382;
  f32 v383;
  s32 v384;
  s32 v385;
  s32 v386;
  f32 *v388;
  s64 v389;
  s32 v390;
  s32 v391;
  s32 v392;
  s64 v394;
  s64 v395;
  s64 v396;
  s64 v397;
  u32 *v398;
  s64 v399;
  s64 v400;
  s32 v402;
  s32 v403;
  s32 v404;
  f32 *v406;
  s64 v407;
  f32 v408;
  s32 v409;
  s32 v410;
  s32 v411;
  f32 *v413;
  s64 v414;
  f32 v415;
  s32 v416;
  s32 v417;
  s32 v418;
  f32 *v420;
  s64 v421;
  f32 v422;
  s32 v423;
  s32 v424;
  s32 v425;
  f32 *v427;
  s64 v428;
  s32 v429;
  s32 v430;
  s32 v431;
  f32 *v433;
  f32 *v434;
  s64 v435;
  s64 v436;
  f32 *v437;
  f32 *v438;
  s64 v439;
  f32 *v440;
  s64 v441;
  s64 v442;
  s64 v443;
  s64 v444;
  f32 v445;
  f32 *v446;
  s64 v447;
  s32 v449;
  s32 v450;
  s32 v451;
  f32 *v453;
  s64 v454;
  f32 v455;
  s32 v456;
  s32 v457;
  s32 v458;
  f32 *v460;
  s64 v461;
  f32 v462;
  s32 v463;
  s32 v464;
  s32 v465;
  f32 *v467;
  s64 v468;
  f32 v469;
  s32 v470;
  s32 v471;
  s32 v472;
  f32 *v474;
  u64 v475;
  s64 v476;
  s32 v477;
  s32 v478;
  s32 v479;
  f32 *v481;
  f32 *v482;
  f32 *v483;
  s32 v484;
  s64 v485;
  s64 v486;
  s64 v487;
  s64 v488;
  f32 *v489;
  s64 v490;
  s32 v492;
  s32 v493;
  s32 v494;
  f32 *v496;
  s64 v497;
  f32 v498;
  s32 v499;
  s32 v500;
  s32 v501;
  f32 *v503;
  s64 v504;
  s32 v505;
  s32 v506;
  s32 v507;
  s64 v509;
  s64 v510;
  s64 v511;
  u32 *v512;
  s64 v513;
  f32 *v514;
  s64 v515;
  s32 v517;
  s32 v518;
  s32 v519;
  f32 *v521;
  s64 v522;
  f32 v523;
  s32 v524;
  s32 v525;
  s32 v526;
  s64 v528;
  f32 *v529;
  s32 v530;
  s32 v531;
  s32 v532;
  s64 v534;
  s64 v535;
  s64 v536;
  s64 v537;
  u32 *v538;
  s64 v539;
  s64 v540;
  s32 v542;
  s32 v543;
  s32 v544;
  f32 *v546;
  s64 v547;
  f32 v548;
  s32 v549;
  s32 v550;
  s32 v551;
  f32 *v553;
  s64 v554;
  f32 v555;
  s32 v556;
  s32 v557;
  s32 v558;
  f32 *v560;
  s64 v561;
  f32 v562;
  s32 v563;
  s32 v564;
  s32 v565;
  f32 *v567;
  s64 v568;
  s32 v569;
  s32 v570;
  s32 v571;
  s64 v573;
  s64 v574;
  s64 v575;
  s64 v576;
  u32 *v577;
  s64 v578;
  s64 v579;
  s32 v581;
  s32 v582;
  s32 v583;
  f32 *v585;
  s64 v586;
  f32 v587;
  s32 v588;
  s32 v589;
  s32 v590;
  f32 *v592;
  s64 v593;
  f32 v594;
  s32 v595;
  s32 v596;
  s32 v597;
  f32 *v599;
  s64 v600;
  f32 v601;
  s32 v602;
  s32 v603;
  s32 v604;
  f32 *v606;
  s64 v607;
  s32 v608;
  s32 v609;
  s32 v610;
  s64 v612;
  s64 v613;
  s64 v614;
  s64 v615;
  u32 *v616;
  s64 v617;
  s64 v618;
  s32 v620;
  s32 v621;
  s32 v622;
  f32 *v624;
  s64 v625;
  f32 v626;
  s32 v627;
  s32 v628;
  s32 v629;
  f32 *v631;
  s64 v632;
  f32 v633;
  s32 v634;
  s32 v635;
  s32 v636;
  f32 *v638;
  s64 v639;
  f32 v640;
  s32 v641;
  s32 v642;
  s32 v643;
  f32 *v645;
  s64 v646;
  s32 v647;
  s32 v648;
  s32 v649;
  s64 v651;
  s64 v652;
  s64 v653;
  s64 v654;
  s64 v655;
  u64 v656;
  s32 v657;
  s32 v658;
  s32 v659;
  Il2CppObject *v661;
  u64 v662;
  s32 v663;
  s32 v664;
  s32 v665;
  Il2CppObject *v667;
  s32 v668;
  s32 v669;
  s32 v670;
  Il2CppObject *v672;
  s32 v673;
  s32 v674;
  s32 v675;
  Il2CppObject *v677;
  s32 v678;
  s32 v679;
  s32 v680;
  Il2CppObject *v682;
  s32 v683;
  s32 v684;
  s32 v685;
  Il2CppObject *v687;
  s32 v688;
  s32 v689;
  s32 v690;
  Il2CppObject *v692;
  s32 v694;
  s32 v695;
  s32 v696;
  Il2CppObject *v698;
  f32 *v699;
  s64 v700;
  f32 v701;
  s32 v702;
  s32 v703;
  s32 v704;
  f32 *v706;
  s64 v707;
  f32 v708;
  s32 v709;
  s32 v710;
  s32 v711;
  f32 *v713;
  s64 v714;
  f32 v715;
  s32 v716;
  s32 v717;
  s32 v718;
  f32 *v720;
  s64 v721;
  s32 v722;
  s32 v723;
  s32 v724;
  s64 v726;
  s64 v727;
  s64 v728;
  s64 v729;
  s64 v730;
  u64 v731;
  s32 v732;
  s32 v733;
  s32 v734;
  Il2CppObject *v736;
  s32 v738;
  s32 v739;
  s32 v740;
  u64 v741;
  Il2CppObject *v743;
  f32 *v744;
  s64 v745;
  f32 v746;
  s32 v747;
  s32 v748;
  s32 v749;
  f32 *v751;
  s64 v752;
  f32 v753;
  s32 v754;
  s32 v755;
  s32 v756;
  f32 *v758;
  s64 v759;
  f32 v760;
  s32 v761;
  s32 v762;
  s32 v763;
  f32 *v765;
  s64 v766;
  s32 v767;
  s32 v768;
  s32 v769;
  u32 *v771;
  u64 v772;
  s32 v773;
  s32 v774;
  s32 v775;
  s64 v777;
  u32 *v778;
  s32 v779;
  s32 v780;
  s32 v781;
  s64 v783;
  u32 *v784;
  s32 v785;
  s32 v786;
  s32 v787;
  s64 v789;
  u32 *v790;
  s32 v791;
  s32 v792;
  s32 v793;
  s64 v795;
  u32 *v796;
  s32 v797;
  s32 v798;
  s32 v799;
  s64 v801;
  u32 *v802;
  s32 v803;
  s32 v804;
  s32 v805;
  s64 v807;
  u32 *v808;
  s32 v809;
  s32 v810;
  s32 v811;
  s64 v813;
  u32 *v814;
  s32 v816;
  s32 v817;
  s32 v818;
  f32 *v820;
  s64 v821;
  s64 v822;
  s64 v823;
  s64 v824;
  s64 v825;
  f32 *v826;
  f32 v827;
  s32 v828;
  s32 v829;
  s32 v830;
  f32 *v832;
  s64 v833;
  f32 v834;
  s32 v835;
  s32 v836;
  s32 v837;
  s32 v839;
  s32 v840;
  s32 v841;
  Il2CppObject *v843;
  s32 v844;
  s32 v845;
  s32 v846;
  Il2CppObject *v848;
  s32 v849;
  s32 v850;
  s32 v851;
  Il2CppObject *v853;
  s32 v854;
  s32 v855;
  s32 v856;
  Il2CppObject *v858;
  s32 v859;
  s32 v860;
  s32 v861;
  Il2CppObject *v863;
  s64 v864;
  bool v865;
  s32 v866;
  s32 v867;
  s32 v868;
  Il2CppObject *v870;
  u32 *v871;
  u64 v872;
  s32 v873;
  s32 v874;
  s32 v875;
  s64 v877;
  u32 *v878;
  s32 v879;
  s32 v880;
  s32 v881;
  s64 v883;
  u32 *v884;
  s32 v885;
  s32 v886;
  s32 v887;
  s64 v889;
  u32 *v890;
  s32 v891;
  s32 v892;
  s32 v893;
  s64 v895;
  u32 *v896;
  s32 v897;
  s32 v898;
  s32 v899;
  s64 v901;
  u32 *v902;
  s32 v903;
  s32 v904;
  s32 v905;
  s64 v907;
  u32 *v908;
  s32 v909;
  s32 v910;
  s32 v911;
  s64 v913;
  u32 *v914;
  s32 v915;
  s32 v916;
  s32 v917;
  s64 v919;
  u32 *v920;
  s32 v921;
  s32 v922;
  s32 v923;
  s64 v925;
  u32 *v926;
  s32 v927;
  s32 v928;
  s32 v929;
  s64 v931;
  u32 *v932;
  s32 v933;
  s32 v934;
  s32 v935;
  s64 v937;
  u32 *v938;
  s32 v939;
  s32 v940;
  s32 v941;
  s64 v943;
  u32 *v944;
  s32 v945;
  s32 v946;
  s32 v947;
  s64 v949;
  u32 *v950;
  s32 v951;
  s32 v952;
  s32 v953;
  s64 v955;
  u32 *v956;
  s32 v957;
  s32 v958;
  s32 v959;
  u32 *v961;
  u64 v962;
  s32 v964;
  s32 v965;
  s32 v966;
  u32 *v968;
  f32 *v969;
  s64 v970;
  s64 v971;
  s64 v972;
  s64 v973;
  f32 v974;
  s32 v975;
  s32 v976;
  s32 v977;
  s64 v979;
  f32 *v980;
  s32 v981;
  s32 v982;
  s32 v983;
  u32 *v985;
  f32 *v986;
  s64 v987;
  s64 v988;
  s64 v989;
  f32 v990;
  s32 v991;
  s32 v992;
  s32 v993;
  s64 v995;
  f32 *v996;
  s32 v997;
  s32 v998;
  s32 v999;
  UnityEngine_Color_array *v1002;
  s64 v1003;
  s64 v1004;
  s64 v1005;
  s64 v1006;
  s64 v1007;
  f32 *v1008;
  s64 v1009;
  f32 *v1010;
  f32 *v1011;
  f32 *v1012;
  f32 *v1013;
  UnityEngine_Color_array *colors;
  s64 v1015;
  s64 v1016;
  s64 v1017;
  s64 v1018;
  s64 v1019;
  s64 v1020;
  s64 v1021;
  u32 *v1022;
  f32 *v1023;
  s64 v1024;
  s64 v1025;
  s64 v1026;
  s64 v1027;
  s64 v1028;
  s64 v1029;
  f32 *v1030;
  s64 v1031;
  f32 *v1032;
  s32 v1033;
  u32 *v1034;
  u32 *v1035;
  u32 *v1036;
  u32 *v1037;
  u32 *v1038;
  f32 *v1039;
  u32 *v1040;
  f32 *v1041;
  f32 *v1042;
  s64 v1043;
  s64 v1044;
  s64 v1045;
  f32 *v1046;
  f32 *v1047;
  f32 *v1048;
  f32 *v1049;
  f32 *v1050;
  f32 *v1051;
  f32 *v1052;
  f32 *v1053;
  f32 *v1054;
  u32 *v1055;
  u32 *v1056;
  u32 *v1057;
  s64 v1058;
  f32 *v1059;
  f32 *v1060;
  f32 *v1061;
  f32 *v1062;
  f32 *v1063;
  f32 *v1064;
  f32 *v1065;
  u64 v1066;
  f32 *v1067;
  f32 *v1068;
  f32 *v1069;
  f32 *v1070;
  f32 *v1071;
  s64 v1072;
  f32 *v1073;
  f32 *v1074;
  f32 *v1075;
  f32 *v1076;
  f32 *v1077;
  f32 *v1078;
  f32 *v1079;
  s64 v1080;
  f32 *v1081;
  f32 *v1082;
  f32 *v1083;
  f32 *v1084;
  f32 *v1085;
  s64 b;
  s64 v1087;
  s64 v1088;
  f32 *v1089;
  f32 *v1090;
  f32 *v1091;
  f32 *v1092;
  f32 *v1093;
  f32 *v1094;
  s64 v1095;
  f32 *v1096;
  s64 v1097;
  f32 *v1098;
  f32 *v1099;
  f32 *v1100;
  f32 *v1101;
  f32 *v1102;
  f32 *v1103;
  u32 *v1104;
  u32 *v1105;
  s64 v1106;
  s64 v1107;
  s64 v1108;
  s64 v1109;
  s64 v1110;
  s64 v1111;
  s64 v1112;
  s64 v1113;
  f32 *v1114;
  u32 *v1115;
  f32 *v1116;
  f32 *v1117;
  f32 *v1118;
  f32 *v1119;
  f32 *v1120;
  f32 *v1121;
  s64 v1122;
  f32 *v1123;
  f32 *v1124;
  f32 *v1125;
  s64 v1126;
  f32 *v1127;
  f32 *v1128;
  s64 v1129;
  s64 v1130;
  s64 v1131;
  u64 v1132;
  f32 *v1133;
  f32 *v1134;
  u32 *v1135;
  u32 *v1136;
  u32 *v1137;
  s64 v1138;
  s64 v1139;

  v4 = Allocate(UnityEngine_Texture2D);
  _ctor_27469040(v4, 256, 256, 4, 0);
  kernelObject->HighContrastMode_ToneTexture = v4;
  set_wrapMode(kernelObject->HighContrastMode_ToneTexture, 1);
  set_filterMode(kernelObject->HighContrastMode_ToneTexture, 0);
  v5 = NewSpecific(UnityEngine_Color, 0x10000u);
  v1137 = (v5 + 3);
  v6 = 0;
  v7 = 0;
  v8 = v5 + 11;
  v9 = v5 + 419;
  colors = v5;
  v10 = v5 + 515;
  do
  {
    v1122 = v7;
    v11 = 0;
    v12 = v8;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v14 = HIDWORD(v1138);
      v16 = v1139;
      v15 = HIDWORD(v1139);
      ++v11;
      *(v12 - 3) = v1138;
      *(v12 - 2) = v14;
      *(v12 - 1) = v16;
      *v12 = v15;
      v12 += 4;
    }
    while (v11 != 102);
    v18 = 0;
    v19 = v9;
    do
    {
      v20 = Lerp(1.0, 0.635, v18 * 0.041667, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v20, v20, v20, 1.0);
      v21 = HIDWORD(v1138);
      v23 = v1139;
      v22 = HIDWORD(v1139);
      ++v18;
      *(v19 - 3) = v1138;
      *(v19 - 2) = v21;
      *(v19 - 1) = v23;
      *v19 = v22;
      v19 += 4;
    }
    while (v18 != 24);
    v25 = 0;
    v26 = v10;
    do
    {
      v27 = Lerp(0.624, 0.251, v25 * 0.0076923, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v27, v27, v27, 1.0);
      v28 = HIDWORD(v1138);
      v30 = v1139;
      v29 = HIDWORD(v1139);
      ++v25;
      *(v26 - 3) = v1138;
      *(v26 - 2) = v28;
      *(v26 - 1) = v30;
      *v26 = v29;
      v26 += 4;
    }
    while (v25 != 130);
    v7 = v1122 + 1;
    v6 += 256;
    v8 += 1024;
    v9 += 1024;
    v10 += 1024;
  }
  while (v1122 != 7);
  p_b = &colors->m_Items[2048].b;
  v33 = 8;
  v34 = 2048;
  do
  {
    v35 = p_b;
    v36 = v34;
    v37 = 256;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, (v37 - 1) * 0.0039216, (v37 - 1) * 0.0039216, (v37 - 1) * 0.0039216, 1.0);
      v38 = HIDWORD(v1138);
      v39 = v1139;
      v40 = HIDWORD(v1139);
      *(v35 - 2) = v1138;
      *(v35 - 1) = v38;
      --v37;
      ++v36;
      *v35 = v39;
      *(v35 + 1) = v40;
      v35 += 4;
    }
    while (v37);
    ++v33;
    v34 += 256;
    p_b += 1024;
  }
  while (v33 != 16);
  v42 = 4103;
  v43 = 4159;
  v44 = &colors->m_Items[4103].b;
  v45 = 16;
  v1123 = &colors->m_Items[4159].b;
  v1103 = &colors->m_Items[4311].b;
  v46 = 4311;
  do
  {
    b = v45;
    v47 = v45 << 8;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v48 = HIDWORD(v1138);
    v50 = v1139;
    v49 = HIDWORD(v1139);
    v52 = &colors->obj + v47;
    LODWORD(v52[2].klass) = v1138;
    HIDWORD(v52[2].klass) = v48;
    LODWORD(v52[2].monitor) = v50;
    HIDWORD(v52[2].monitor) = v49;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v53 = HIDWORD(v1138);
    v55 = v1139;
    v54 = HIDWORD(v1139);
    v57 = &colors->obj + (v47 | 1);
    LODWORD(v57[2].klass) = v1138;
    HIDWORD(v57[2].klass) = v53;
    LODWORD(v57[2].monitor) = v55;
    HIDWORD(v57[2].monitor) = v54;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v58 = HIDWORD(v1138);
    v60 = v1139;
    v59 = HIDWORD(v1139);
    v62 = &colors->obj + (v47 | 2);
    LODWORD(v62[2].klass) = v1138;
    HIDWORD(v62[2].klass) = v58;
    LODWORD(v62[2].monitor) = v60;
    HIDWORD(v62[2].monitor) = v59;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v63 = HIDWORD(v1138);
    v65 = v1139;
    v64 = HIDWORD(v1139);
    v67 = &colors->obj + (v47 | 3);
    LODWORD(v67[2].klass) = v1138;
    HIDWORD(v67[2].klass) = v63;
    LODWORD(v67[2].monitor) = v65;
    HIDWORD(v67[2].monitor) = v64;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v68 = HIDWORD(v1138);
    v70 = v1139;
    v69 = HIDWORD(v1139);
    v72 = &colors->obj + (v47 | 4);
    LODWORD(v72[2].klass) = v1138;
    HIDWORD(v72[2].klass) = v68;
    LODWORD(v72[2].monitor) = v70;
    HIDWORD(v72[2].monitor) = v69;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v73 = HIDWORD(v1138);
    v75 = v1139;
    v74 = HIDWORD(v1139);
    v77 = &colors->obj + (v47 | 5);
    LODWORD(v77[2].klass) = v1138;
    HIDWORD(v77[2].klass) = v73;
    LODWORD(v77[2].monitor) = v75;
    HIDWORD(v77[2].monitor) = v74;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v78 = HIDWORD(v1138);
    v80 = v1139;
    v79 = HIDWORD(v1139);
    v82 = &colors->obj + (v47 | 6);
    LODWORD(v82[2].klass) = v1138;
    HIDWORD(v82[2].klass) = v78;
    LODWORD(v82[2].monitor) = v80;
    HIDWORD(v82[2].monitor) = v79;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v84 = HIDWORD(v1138);
    v85 = v1139;
    v86 = HIDWORD(v1139);
    v88 = &colors->obj + (v47 | 7);
    LODWORD(v88[2].klass) = v1138;
    HIDWORD(v88[2].klass) = v84;
    v89 = 0;
    v90 = v44;
    LODWORD(v88[2].monitor) = v85;
    HIDWORD(v88[2].monitor) = v86;
    do
    {
      v91 = Lerp(1.0, 0.3, v89 * 0.017544, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v91, v91, v91, 1.0);
      v92 = HIDWORD(v1138);
      v94 = v1139;
      v93 = HIDWORD(v1139);
      ++v89;
      *(v90 - 2) = v1138;
      *(v90 - 1) = v92;
      *v90 = v94;
      *(v90 + 1) = v93;
      v90 += 4;
    }
    while (v89 != 57);
    v96 = v1123;
    v97 = 0;
    do
    {
      v98 = Lerp(0.3, 0.0, v97 * 0.0065359, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v98, v98, v98, 1.0);
      v99 = HIDWORD(v1138);
      v101 = v1139;
      v100 = HIDWORD(v1139);
      ++v97;
      *(v96 - 2) = v1138;
      *(v96 - 1) = v99;
      *v96 = v101;
      *(v96 + 1) = v100;
      v96 += 4;
    }
    while (v97 != 153);
    v103 = v1103;
    v104 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
      v105 = HIDWORD(v1138);
      v107 = v1139;
      v106 = HIDWORD(v1139);
      ++v104;
      *(v103 - 2) = v1138;
      *(v103 - 1) = v105;
      *v103 = v107;
      *(v103 + 1) = v106;
      v103 += 4;
    }
    while (v104 != 41);
    v45 = b + 1;
    v1123 += 1024;
    v42 += 256;
    v44 += 1024;
    v43 += 256;
    v46 += 256;
    v1103 += 1024;
  }
  while (b != 23);
  v109 = &colors->m_Items[6144].b;
  v1124 = &colors->m_Items[6243].b;
  v110 = &colors->m_Items[6335].b;
  v111 = 24;
  v112 = 6144;
  v113 = 6243;
  v114 = 6335;
  do
  {
    v1087 = v111;
    v1104 = v109;
    v115 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v117 = HIDWORD(v1138);
      v118 = v1139;
      v119 = HIDWORD(v1139);
      ++v115;
      *(v109 - 2) = v1138;
      *(v109 - 1) = v117;
      *v109 = v118;
      v109[1] = v119;
      v109 += 4;
    }
    while (v115 != 100);
    v121 = v1124;
    v122 = 0;
    do
    {
      v123 = Lerp(1.0, 0.1, v122 * 0.010753, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v123, v123, v123, 1.0);
      v124 = HIDWORD(v1138);
      v125 = v1139;
      v126 = HIDWORD(v1139);
      ++v122;
      *(v121 - 2) = v1138;
      *(v121 - 1) = v124;
      *v121 = v125;
      *(v121 + 1) = v126;
      v121 += 4;
    }
    while (v122 != 93);
    v128 = 0;
    v129 = v110;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.1, 0.1, 0.1, 1.0);
      v130 = HIDWORD(v1138);
      v131 = v1139;
      v132 = HIDWORD(v1139);
      ++v128;
      *(v129 - 2) = v1138;
      *(v129 - 1) = v130;
      *v129 = v131;
      *(v129 + 1) = v132;
      v129 += 4;
    }
    while (v128 != 65);
    v111 = v1087 + 1;
    v112 += 256;
    v109 = v1104 + 1024;
    v113 += 256;
    v114 += 256;
    v110 += 1024;
    v1124 += 1024;
  }
  while (v1087 != 31);
  v134 = 0x2000;
  v135 = 8323;
  v136 = 8415;
  v137 = &colors->m_Items[0x2000].b;
  v138 = 32;
  v1125 = &colors->m_Items[8323].b;
  v139 = &colors->m_Items[8415].b;
  do
  {
    v1088 = v138;
    v1105 = v137;
    v140 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v142 = HIDWORD(v1138);
      v143 = v1139;
      v144 = HIDWORD(v1139);
      ++v140;
      *(v137 - 2) = v1138;
      *(v137 - 1) = v142;
      *v137 = v143;
      v137[1] = v144;
      v137 += 4;
    }
    while (v140 != 132);
    v146 = v1125;
    v147 = 0;
    do
    {
      v148 = Lerp(1.0, 0.1, v147 * 0.010753, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v148, v148, v148, 1.0);
      v149 = HIDWORD(v1138);
      v150 = v1139;
      v151 = HIDWORD(v1139);
      ++v147;
      *(v146 - 2) = v1138;
      *(v146 - 1) = v149;
      *v146 = v150;
      *(v146 + 1) = v151;
      v146 += 4;
    }
    while (v147 != 93);
    v153 = 0;
    v154 = v139;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.1, 0.1, 0.1, 1.0);
      v155 = HIDWORD(v1138);
      v156 = v1139;
      v157 = HIDWORD(v1139);
      ++v153;
      *(v154 - 2) = v1138;
      *(v154 - 1) = v155;
      *v154 = v156;
      *(v154 + 1) = v157;
      v154 += 4;
    }
    while (v153 != 33);
    v138 = v1088 + 1;
    v134 += 256;
    v137 = v1105 + 1024;
    v135 += 256;
    v136 += 256;
    v139 += 1024;
    v1125 += 1024;
  }
  while (v1088 != 39);
  v159 = 10329;
  v160 = 10337;
  v161 = 10407;
  v162 = &colors->m_Items[10240].b;
  v163 = 40;
  v1089 = &colors->m_Items[10329].b;
  v1073 = &colors->m_Items[10337].b;
  v1059 = &colors->m_Items[10367].b;
  v1046 = &colors->m_Items[10407].b;
  v1106 = 10240;
  v164 = 10367;
  do
  {
    v1025 = v163;
    v1034 = v162;
    v165 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v167 = HIDWORD(v1138);
      v169 = v1139;
      v168 = HIDWORD(v1139);
      ++v165;
      *(v162 - 2) = v1138;
      *(v162 - 1) = v167;
      *v162 = v169;
      v162[1] = v168;
      v162 += 4;
    }
    while (v165 != 90);
    v171 = v1089;
    v172 = 0;
    do
    {
      v173 = Lerp(1.0, 0.9, v172 * 0.11111, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v173, v173, v173, 1.0);
      v174 = HIDWORD(v1138);
      v176 = v1139;
      v175 = HIDWORD(v1139);
      ++v172;
      *(v171 - 2) = v1138;
      *(v171 - 1) = v174;
      *v171 = v176;
      *(v171 + 1) = v175;
      v171 += 4;
    }
    while (v172 != 9);
    v178 = v1073;
    v179 = 0;
    do
    {
      v180 = Lerp(0.9, 0.2, v179 * 0.032258, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v180, v180, v180, 1.0);
      v181 = HIDWORD(v1138);
      v183 = v1139;
      v182 = HIDWORD(v1139);
      ++v179;
      *(v178 - 2) = v1138;
      *(v178 - 1) = v181;
      *v178 = v183;
      *(v178 + 1) = v182;
      v178 += 4;
    }
    while (v179 != 31);
    v185 = v1059;
    v186 = 0;
    do
    {
      v187 = Lerp(0.2, 0.1, v186 * 0.02439, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v187, v187, v187, 1.0);
      v188 = HIDWORD(v1138);
      v190 = v1139;
      v189 = HIDWORD(v1139);
      ++v186;
      *(v185 - 2) = v1138;
      *(v185 - 1) = v188;
      *v185 = v190;
      *(v185 + 1) = v189;
      v185 += 4;
    }
    while (v186 != 41);
    v192 = v1046;
    v193 = 0;
    do
    {
      v194 = Lerp(0.1, 0.1, v193 * 0.011236, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v194, v194, v194, 1.0);
      v195 = HIDWORD(v1138);
      v197 = v1139;
      v196 = HIDWORD(v1139);
      ++v193;
      *(v192 - 2) = v1138;
      *(v192 - 1) = v195;
      *v192 = v197;
      *(v192 + 1) = v196;
      v192 += 4;
    }
    while (v193 != 89);
    v1106 += 256;
    v1089 += 1024;
    v1073 += 1024;
    v163 = v1025 + 1;
    v162 = v1034 + 1024;
    v159 += 256;
    v160 += 256;
    v164 += 256;
    v161 += 256;
    v1059 += 1024;
    v1046 += 1024;
  }
  while (v1025 != 47);
  v199 = 12382;
  v200 = 12391;
  v201 = 12437;
  v202 = &colors->m_Items[12288].b;
  v203 = 48;
  v1090 = &colors->m_Items[12382].b;
  v1074 = &colors->m_Items[12391].b;
  v1060 = &colors->m_Items[12437].b;
  v1047 = &colors->m_Items[12463].b;
  v1107 = 12288;
  v204 = 12463;
  do
  {
    v1026 = v203;
    v1035 = v202;
    v205 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v207 = HIDWORD(v1138);
      v209 = v1139;
      v208 = HIDWORD(v1139);
      ++v205;
      *(v202 - 2) = v1138;
      *(v202 - 1) = v207;
      *v202 = v209;
      v202[1] = v208;
      v202 += 4;
    }
    while (v205 != 95);
    v211 = v1090;
    v212 = 0;
    do
    {
      v213 = Lerp(1.0, 0.87, v212 * 0.1, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v213, v213, v213, 1.0);
      v214 = HIDWORD(v1138);
      v216 = v1139;
      v215 = HIDWORD(v1139);
      *(v211 - 2) = v1138;
      *(v211 - 1) = v214;
      ++v212;
      *v211 = v216;
      *(v211 + 1) = v215;
      v211 += 4;
    }
    while (v212 != 10);
    v218 = v1074;
    v219 = 0;
    do
    {
      v220 = Lerp(0.87, 0.284, v219 * 0.021277, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v220, v220, v220, 1.0);
      v221 = HIDWORD(v1138);
      v223 = v1139;
      v222 = HIDWORD(v1139);
      ++v219;
      *(v218 - 2) = v1138;
      *(v218 - 1) = v221;
      *v218 = v223;
      *(v218 + 1) = v222;
      v218 += 4;
    }
    while (v219 != 47);
    v225 = v1060;
    v226 = 0;
    do
    {
      v227 = Lerp(0.284, 0.15, v226 * 0.037037, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v227, v227, v227, 1.0);
      v228 = HIDWORD(v1138);
      v230 = v1139;
      v229 = HIDWORD(v1139);
      ++v226;
      *(v225 - 2) = v1138;
      *(v225 - 1) = v228;
      *v225 = v230;
      *(v225 + 1) = v229;
      v225 += 4;
    }
    while (v226 != 27);
    v232 = v1047;
    v233 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.15, 0.15, 0.15, 1.0);
      v234 = HIDWORD(v1138);
      v236 = v1139;
      v235 = HIDWORD(v1139);
      ++v233;
      *(v232 - 2) = v1138;
      *(v232 - 1) = v234;
      *v232 = v236;
      *(v232 + 1) = v235;
      v232 += 4;
    }
    while (v233 != 81);
    v1107 += 256;
    v1090 += 1024;
    v1074 += 1024;
    v203 = v1026 + 1;
    v202 = v1035 + 1024;
    v199 += 256;
    v200 += 256;
    v201 += 256;
    v204 += 256;
    v1060 += 1024;
    v1047 += 1024;
  }
  while (v1026 != 55);
  v238 = 14430;
  v239 = 14445;
  v240 = 14511;
  v241 = &colors->m_Items[14336].b;
  v242 = 56;
  v1091 = &colors->m_Items[14430].b;
  v1075 = &colors->m_Items[14445].b;
  v1061 = &colors->m_Items[14485].b;
  v1048 = &colors->m_Items[14511].b;
  v1108 = 14336;
  v243 = 14485;
  do
  {
    v1027 = v242;
    v1036 = v241;
    v244 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v246 = HIDWORD(v1138);
      v248 = v1139;
      v247 = HIDWORD(v1139);
      ++v244;
      *(v241 - 2) = v1138;
      *(v241 - 1) = v246;
      *v241 = v248;
      v241[1] = v247;
      v241 += 4;
    }
    while (v244 != 95);
    v250 = v1091;
    v251 = 0;
    do
    {
      v252 = Lerp(1.0, 0.85, v251 * 0.0625, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v252, v252, v252, 1.0);
      v253 = HIDWORD(v1138);
      v255 = v1139;
      v254 = HIDWORD(v1139);
      ++v251;
      *(v250 - 2) = v1138;
      *(v250 - 1) = v253;
      *v250 = v255;
      *(v250 + 1) = v254;
      v250 += 4;
    }
    while (v251 != 16);
    v257 = v1075;
    v258 = 0;
    do
    {
      v259 = Lerp(0.85, 0.284, v258 * 0.02439, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v259, v259, v259, 1.0);
      v260 = HIDWORD(v1138);
      v262 = v1139;
      v261 = HIDWORD(v1139);
      ++v258;
      *(v257 - 2) = v1138;
      *(v257 - 1) = v260;
      *v257 = v262;
      *(v257 + 1) = v261;
      v257 += 4;
    }
    while (v258 != 41);
    v264 = v1061;
    v265 = 0;
    do
    {
      v266 = Lerp(0.284, 0.2, v265 * 0.037037, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v266, v266, v266, 1.0);
      v267 = HIDWORD(v1138);
      v269 = v1139;
      v268 = HIDWORD(v1139);
      ++v265;
      *(v264 - 2) = v1138;
      *(v264 - 1) = v267;
      *v264 = v269;
      *(v264 + 1) = v268;
      v264 += 4;
    }
    while (v265 != 27);
    v271 = v1048;
    v272 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.2, 0.2, 0.2, 1.0);
      v273 = HIDWORD(v1138);
      v275 = v1139;
      v274 = HIDWORD(v1139);
      ++v272;
      *(v271 - 2) = v1138;
      *(v271 - 1) = v273;
      *v271 = v275;
      *(v271 + 1) = v274;
      v271 += 4;
    }
    while (v272 != 81);
    v1108 += 256;
    v1091 += 1024;
    v1075 += 1024;
    v242 = v1027 + 1;
    v241 = v1036 + 1024;
    v238 += 256;
    v239 += 256;
    v243 += 256;
    v240 += 256;
    v1061 += 1024;
    v1048 += 1024;
  }
  while (v1027 != 63);
  v277 = 16486;
  v278 = 16497;
  v279 = 16563;
  v280 = &colors->m_Items[0x4000].b;
  v281 = 64;
  v1092 = &colors->m_Items[16486].b;
  v1076 = &colors->m_Items[16497].b;
  v1062 = &colors->m_Items[16537].b;
  v1049 = &colors->m_Items[16563].b;
  v1109 = 0x4000;
  v282 = 16537;
  do
  {
    v1028 = v281;
    v1037 = v280;
    v283 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v285 = HIDWORD(v1138);
      v287 = v1139;
      v286 = HIDWORD(v1139);
      ++v283;
      *(v280 - 2) = v1138;
      *(v280 - 1) = v285;
      *v280 = v287;
      v280[1] = v286;
      v280 += 4;
    }
    while (v283 != 103);
    v289 = v1092;
    v290 = 0;
    do
    {
      v291 = Lerp(1.0, 0.85, v290 * 0.083333, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v291, v291, v291, 1.0);
      v292 = HIDWORD(v1138);
      v294 = v1139;
      v293 = HIDWORD(v1139);
      ++v290;
      *(v289 - 2) = v1138;
      *(v289 - 1) = v292;
      *v289 = v294;
      *(v289 + 1) = v293;
      v289 += 4;
    }
    while (v290 != 12);
    v296 = v1076;
    v297 = 0;
    do
    {
      v298 = Lerp(0.85, 0.284, v297 * 0.02439, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v298, v298, v298, 1.0);
      v299 = HIDWORD(v1138);
      v301 = v1139;
      v300 = HIDWORD(v1139);
      ++v297;
      *(v296 - 2) = v1138;
      *(v296 - 1) = v299;
      *v296 = v301;
      *(v296 + 1) = v300;
      v296 += 4;
    }
    while (v297 != 41);
    v303 = v1062;
    v304 = 0;
    do
    {
      v305 = Lerp(0.284, 0.15, v304 * 0.037037, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v305, v305, v305, 1.0);
      v306 = HIDWORD(v1138);
      v308 = v1139;
      v307 = HIDWORD(v1139);
      ++v304;
      *(v303 - 2) = v1138;
      *(v303 - 1) = v306;
      *v303 = v308;
      *(v303 + 1) = v307;
      v303 += 4;
    }
    while (v304 != 27);
    v310 = v1049;
    v311 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.15, 0.15, 0.15, 1.0);
      v312 = HIDWORD(v1138);
      v314 = v1139;
      v313 = HIDWORD(v1139);
      ++v311;
      *(v310 - 2) = v1138;
      *(v310 - 1) = v312;
      *v310 = v314;
      *(v310 + 1) = v313;
      v310 += 4;
    }
    while (v311 != 77);
    v1109 += 256;
    v1092 += 1024;
    v1076 += 1024;
    v281 = v1028 + 1;
    v280 = v1037 + 1024;
    v277 += 256;
    v278 += 256;
    v282 += 256;
    v279 += 256;
    v1062 += 1024;
    v1049 += 1024;
  }
  while (v1028 != 71);
  v316 = 18534;
  v317 = 18545;
  v318 = 18585;
  v319 = &colors->m_Items[18432].b;
  v320 = 72;
  v1093 = &colors->m_Items[18534].b;
  v1077 = &colors->m_Items[18545].b;
  v1063 = &colors->m_Items[18585].b;
  v1050 = &colors->m_Items[18611].b;
  v1110 = 18432;
  v321 = 18611;
  do
  {
    v1029 = v320;
    v1038 = v319;
    v322 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v324 = HIDWORD(v1138);
      v326 = v1139;
      v325 = HIDWORD(v1139);
      ++v322;
      *(v319 - 2) = v1138;
      *(v319 - 1) = v324;
      *v319 = v326;
      v319[1] = v325;
      v319 += 4;
    }
    while (v322 != 103);
    v328 = v1093;
    v329 = 0;
    do
    {
      v330 = Lerp(1.0, 0.85, v329 * 0.083333, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v330, v330, v330, 1.0);
      v331 = HIDWORD(v1138);
      v333 = v1139;
      v332 = HIDWORD(v1139);
      ++v329;
      *(v328 - 2) = v1138;
      *(v328 - 1) = v331;
      *v328 = v333;
      *(v328 + 1) = v332;
      v328 += 4;
    }
    while (v329 != 12);
    v335 = v1077;
    v336 = 0;
    do
    {
      v337 = Lerp(0.85, 0.284, v336 * 0.02439, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v337, v337, v337, 1.0);
      v338 = HIDWORD(v1138);
      v340 = v1139;
      v339 = HIDWORD(v1139);
      ++v336;
      *(v335 - 2) = v1138;
      *(v335 - 1) = v338;
      *v335 = v340;
      *(v335 + 1) = v339;
      v335 += 4;
    }
    while (v336 != 41);
    v342 = v1063;
    v343 = 0;
    do
    {
      v344 = Lerp(0.284, 0.1, v343 * 0.037037, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v344, v344, v344, 1.0);
      v345 = HIDWORD(v1138);
      v347 = v1139;
      v346 = HIDWORD(v1139);
      ++v343;
      *(v342 - 2) = v1138;
      *(v342 - 1) = v345;
      *v342 = v347;
      *(v342 + 1) = v346;
      v342 += 4;
    }
    while (v343 != 27);
    v349 = v1050;
    v350 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.1, 0.1, 0.1, 1.0);
      v351 = HIDWORD(v1138);
      v353 = v1139;
      v352 = HIDWORD(v1139);
      ++v350;
      *(v349 - 2) = v1138;
      *(v349 - 1) = v351;
      *v349 = v353;
      *(v349 + 1) = v352;
      v349 += 4;
    }
    while (v350 != 77);
    v1110 += 256;
    v1093 += 1024;
    v1077 += 1024;
    v320 = v1029 + 1;
    v319 = v1038 + 1024;
    v316 += 256;
    v317 += 256;
    v318 += 256;
    v321 += 256;
    v1063 += 1024;
    v1050 += 1024;
  }
  while (v1029 != 79);
  v355 = 20584;
  v356 = 20601;
  v357 = 20663;
  v358 = &colors->m_Items[20480].b;
  v359 = 80;
  v1064 = &colors->m_Items[20584].b;
  v1051 = &colors->m_Items[20601].b;
  v1039 = &colors->m_Items[20637].b;
  v1030 = &colors->m_Items[20663].b;
  v1111 = 20480;
  v360 = 20637;
  do
  {
    v1019 = v359;
    v1022 = v358;
    v361 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v363 = HIDWORD(v1138);
      v365 = v1139;
      v364 = HIDWORD(v1139);
      ++v361;
      *(v358 - 2) = v1138;
      *(v358 - 1) = v363;
      *v358 = v365;
      v358[1] = v364;
      v358 += 4;
    }
    while (v361 != 105);
    v367 = v1064;
    v368 = 0;
    do
    {
      v369 = Lerp(1.0, 0.95, v368 * 0.055556, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v369, v369, v369, 1.0);
      v370 = HIDWORD(v1138);
      v372 = v1139;
      v371 = HIDWORD(v1139);
      ++v368;
      *(v367 - 2) = v1138;
      *(v367 - 1) = v370;
      *v367 = v372;
      *(v367 + 1) = v371;
      v367 += 4;
    }
    while (v368 != 18);
    v374 = v1051;
    v375 = 0;
    do
    {
      v376 = Lerp(0.95, 0.284, v375 * 0.027027, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v376, v376, v376, 1.0);
      v377 = HIDWORD(v1138);
      v379 = v1139;
      v378 = HIDWORD(v1139);
      ++v375;
      *(v374 - 2) = v1138;
      *(v374 - 1) = v377;
      *v374 = v379;
      *(v374 + 1) = v378;
      v374 += 4;
    }
    while (v375 != 37);
    v381 = v1039;
    v382 = 0;
    do
    {
      v383 = Lerp(0.284, 0.05, v382 * 0.037037, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v383, v383, v383, 1.0);
      v384 = HIDWORD(v1138);
      v386 = v1139;
      v385 = HIDWORD(v1139);
      ++v382;
      *(v381 - 2) = v1138;
      *(v381 - 1) = v384;
      *v381 = v386;
      *(v381 + 1) = v385;
      v381 += 4;
    }
    while (v382 != 27);
    v388 = v1030;
    v389 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.05, 0.05, 0.05, 1.0);
      v390 = HIDWORD(v1138);
      v392 = v1139;
      v391 = HIDWORD(v1139);
      ++v389;
      *(v388 - 2) = v1138;
      *(v388 - 1) = v390;
      *v388 = v392;
      *(v388 + 1) = v391;
      v388 += 4;
    }
    while (v389 != 73);
    v1111 += 256;
    v1064 += 1024;
    v1051 += 1024;
    v359 = v1019 + 1;
    v358 = v1022 + 1024;
    v355 += 256;
    v356 += 256;
    v360 += 256;
    v357 += 256;
    v1039 += 1024;
    v1030 += 1024;
  }
  while (v1019 != 87);
  v394 = 22630;
  v395 = 22645;
  v396 = 22685;
  v397 = 22711;
  v398 = &colors->m_Items[22528].b;
  v399 = 88;
  v1094 = &colors->m_Items[22630].b;
  v1078 = &colors->m_Items[22645].b;
  v1065 = &colors->m_Items[22685].b;
  v1052 = &colors->m_Items[22711].b;
  v1112 = 22528;
  do
  {
    v1031 = v399;
    v1040 = v398;
    v400 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v402 = HIDWORD(v1138);
      v404 = v1139;
      v403 = HIDWORD(v1139);
      ++v400;
      *(v398 - 2) = v1138;
      *(v398 - 1) = v402;
      *v398 = v404;
      v398[1] = v403;
      v398 += 4;
    }
    while (v400 != 103);
    v406 = v1094;
    v407 = 0;
    do
    {
      v408 = Lerp(1.0, 0.85, v407 * 0.0625, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v408, v408, v408, 1.0);
      v409 = HIDWORD(v1138);
      v411 = v1139;
      v410 = HIDWORD(v1139);
      ++v407;
      *(v406 - 2) = v1138;
      *(v406 - 1) = v409;
      *v406 = v411;
      *(v406 + 1) = v410;
      v406 += 4;
    }
    while (v407 != 16);
    v413 = v1078;
    v414 = 0;
    do
    {
      v415 = Lerp(0.85, 0.284, v414 * 0.02439, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v415, v415, v415, 1.0);
      v416 = HIDWORD(v1138);
      v418 = v1139;
      v417 = HIDWORD(v1139);
      ++v414;
      *(v413 - 2) = v1138;
      *(v413 - 1) = v416;
      *v413 = v418;
      *(v413 + 1) = v417;
      v413 += 4;
    }
    while (v414 != 41);
    v420 = v1065;
    v421 = 0;
    do
    {
      v422 = Lerp(0.284, 0.0, v421 * 0.037037, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v422, v422, v422, 1.0);
      v423 = HIDWORD(v1138);
      v425 = v1139;
      v424 = HIDWORD(v1139);
      ++v421;
      *(v420 - 2) = v1138;
      *(v420 - 1) = v423;
      *v420 = v425;
      *(v420 + 1) = v424;
      v420 += 4;
    }
    while (v421 != 27);
    v427 = v1052;
    v428 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
      v429 = HIDWORD(v1138);
      v431 = v1139;
      v430 = HIDWORD(v1139);
      ++v428;
      *(v427 - 2) = v1138;
      *(v427 - 1) = v429;
      *v427 = v431;
      *(v427 + 1) = v430;
      v427 += 4;
    }
    while (v428 != 73);
    v1112 += 256;
    v1094 += 1024;
    v1078 += 1024;
    v399 = v1031 + 1;
    v398 = v1040 + 1024;
    v394 += 256;
    v395 += 256;
    v396 += 256;
    v397 += 256;
    v1065 += 1024;
    v1052 += 1024;
  }
  while (v1031 != 95);
  v433 = &colors->m_Items[24576].b;
  v434 = &colors->m_Items[24679].b;
  v435 = 96;
  v436 = 24576;
  v437 = &colors->m_Items[24694].b;
  v438 = &colors->m_Items[24725].b;
  v439 = 0;
  v440 = &colors->m_Items[24751].b;
  v1095 = 32;
  v1113 = 104;
  v441 = 24679;
  v442 = 24694;
  v443 = 24725;
  v1015 = 104;
  v1017 = 81;
  v444 = 24751;
  do
  {
    v1066 = v444;
    v1079 = v440;
    v1008 = v440;
    v1009 = v439 + 1;
    v1003 = v443;
    v445 = 1.0 / (158 - 8 * (v439 + 1) - (v439 + 118));
    v446 = v433;
    v1010 = v438;
    v1053 = v438;
    v1126 = v443;
    v1011 = v437;
    v1012 = v434;
    v1032 = v434;
    v1041 = v437;
    v1013 = v433;
    v1004 = v442;
    v1005 = v441;
    v1006 = v436;
    v1007 = v435;
    do
    {
      v1020 = v435;
      v1023 = v446;
      v447 = 0;
      do
      {
        v1138 = 0;
        v1139 = 0;
        sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
        v449 = HIDWORD(v1138);
        v451 = v1139;
        v450 = HIDWORD(v1139);
        *(v446 - 2) = v1138;
        *(v446 - 1) = v449;
        ++v447;
        *v446 = v451;
        *(v446 + 1) = v450;
        v446 += 4;
      }
      while (v1113 != v447);
      v453 = v1032;
      v454 = 0;
      do
      {
        v455 = Lerp(1.0, 0.85, v454 * 0.0625, 0);
        v1138 = 0;
        v1139 = 0;
        sub_19EC630(&v1138, v455, v455, v455, 1.0);
        v456 = HIDWORD(v1138);
        v458 = v1139;
        v457 = HIDWORD(v1139);
        ++v454;
        *(v453 - 2) = v1138;
        *(v453 - 1) = v456;
        *v453 = v458;
        *(v453 + 1) = v457;
        v453 += 4;
      }
      while (v454 != 16);
      v460 = v1041;
      v461 = 0;
      do
      {
        v462 = Lerp(0.85, 0.284, v445 * v461, 0);
        v1138 = 0;
        v1139 = 0;
        sub_19EC630(&v1138, v462, v462, v462, 1.0);
        v463 = HIDWORD(v1138);
        v465 = v1139;
        v464 = HIDWORD(v1139);
        *(v460 - 2) = v1138;
        *(v460 - 1) = v463;
        ++v461;
        *v460 = v465;
        *(v460 + 1) = v464;
        v460 += 4;
      }
      while (v1095 != v461);
      v467 = v1053;
      v468 = 0;
      do
      {
        v469 = Lerp(0.284, 0.0, v468 * 0.037037, 0);
        v1138 = 0;
        v1139 = 0;
        sub_19EC630(&v1138, v469, v469, v469, 1.0);
        v470 = HIDWORD(v1138);
        v472 = v1139;
        v471 = HIDWORD(v1139);
        ++v468;
        *(v467 - 2) = v1138;
        *(v467 - 1) = v470;
        *v467 = v472;
        *(v467 + 1) = v471;
        v467 += 4;
      }
      while (v468 != 27);
      v475 = v1066;
      v474 = v1079;
      v476 = v1017;
      do
      {
        v1138 = 0;
        v1139 = 0;
        sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
        v477 = HIDWORD(v1138);
        v479 = v1139;
        v478 = HIDWORD(v1139);
        *(v474 - 2) = v1138;
        *(v474 - 1) = v477;
        --v476;
        ++v475;
        *v474 = v479;
        *(v474 + 1) = v478;
        v474 += 4;
      }
      while (v476);
      v436 += 256;
      v435 = v1020 + 1;
      v446 = v1023 + 1024;
      v441 += 256;
      v442 += 256;
      v1032 += 1024;
      v1041 += 1024;
      v1126 += 256;
      v1053 += 1024;
      v1066 += 256LL;
      v1079 += 1024;
    }
    while (v1020 + 1 != v1015);
    v433 = v1013 + 0x2000;
    v435 = v1007 + 8;
    v436 = v1006 + 2048;
    v441 = v1005 + 2049;
    v444 += 2040;
    ++v1113;
    v442 = v1004 + 2049;
    v439 = v1009;
    v443 = v1003 + 2040;
    v1015 += 8;
    v434 = v1012 + 8196;
    v437 = v1011 + 8196;
    v438 = v1010 + 8160;
    v440 = v1008 + 8160;
    v1095 -= 9;
    v1017 += 8;
  }
  while (v1009 != 3);
  v481 = &colors->m_Items[30720].b;
  v482 = &colors->m_Items[30825].b;
  v483 = &colors->m_Items[30843].b;
  v1080 = 128;
  v484 = 15;
  v485 = 120;
  v486 = 30720;
  v487 = 30825;
  v488 = 30843;
  do
  {
    v1033 = v484;
    v1042 = v483;
    v489 = v481;
    v1127 = v483;
    v1016 = v488;
    v1054 = v482;
    v1114 = v482;
    v1018 = v487;
    v1067 = v481;
    v1021 = v486;
    v1024 = v485;
    do
    {
      v490 = 0;
      v1096 = v489;
      do
      {
        v1138 = 0;
        v1139 = 0;
        sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
        v492 = HIDWORD(v1138);
        v494 = v1139;
        v493 = HIDWORD(v1139);
        ++v490;
        *(v489 - 2) = v1138;
        *(v489 - 1) = v492;
        *v489 = v494;
        *(v489 + 1) = v493;
        v489 += 4;
      }
      while (v490 != 106);
      v496 = v1114;
      v497 = 0;
      do
      {
        v498 = Lerp(1.0, 0.0, v497 * 0.052632, 0);
        v1138 = 0;
        v1139 = 0;
        sub_19EC630(&v1138, v498, v498, v498, 1.0);
        v499 = HIDWORD(v1138);
        v501 = v1139;
        v500 = HIDWORD(v1139);
        ++v497;
        *(v496 - 2) = v1138;
        *(v496 - 1) = v499;
        *v496 = v501;
        *(v496 + 1) = v500;
        v496 += 4;
      }
      while (v497 != 19);
      v503 = v1127;
      v504 = 0;
      do
      {
        v1138 = 0;
        v1139 = 0;
        sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
        v505 = HIDWORD(v1138);
        v507 = v1139;
        v506 = HIDWORD(v1139);
        ++v504;
        *(v503 - 2) = v1138;
        *(v503 - 1) = v505;
        *v503 = v507;
        *(v503 + 1) = v506;
        v503 += 4;
      }
      while (v504 != 133);
      v1114 += 1024;
      v1127 += 1024;
      ++v485;
      v486 += 256;
      v489 = v1096 + 1024;
      v487 += 256;
      v488 += 256;
    }
    while (v485 != v1080);
    v484 = v1033 + 1;
    v485 = v1024 + 8;
    v486 = v1021 + 2048;
    v481 = v1067 + 0x2000;
    v487 = v1018 + 2048;
    v482 = v1054 + 0x2000;
    v488 = v1016 + 2048;
    v483 = v1042 + 0x2000;
    v1080 += 8;
  }
  while (v1033 != 20);
  v509 = 0x8000;
  v510 = 32839;
  v511 = 32862;
  v512 = &colors->m_Items[0x8000].b;
  v513 = 128;
  v1128 = &colors->m_Items[32839].b;
  v514 = &colors->m_Items[32862].b;
  do
  {
    v1097 = v513;
    v1115 = v512;
    v515 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v517 = HIDWORD(v1138);
      v518 = v1139;
      v519 = HIDWORD(v1139);
      ++v515;
      *(v512 - 2) = v1138;
      *(v512 - 1) = v517;
      *v512 = v518;
      v512[1] = v519;
      v512 += 4;
    }
    while (v515 != 72);
    v521 = v1128;
    v522 = 0;
    do
    {
      v523 = Lerp(1.0, 0.2, v522 * 0.041667, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v523, v523, v523, 1.0);
      v524 = HIDWORD(v1138);
      v525 = v1139;
      v526 = HIDWORD(v1139);
      ++v522;
      *(v521 - 2) = v1138;
      *(v521 - 1) = v524;
      *v521 = v525;
      *(v521 + 1) = v526;
      v521 += 4;
    }
    while (v522 != 24);
    v528 = 0;
    v529 = v514;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.2, 0.2, 0.2, 1.0);
      v530 = HIDWORD(v1138);
      v531 = v1139;
      v532 = HIDWORD(v1139);
      ++v528;
      *(v529 - 2) = v1138;
      *(v529 - 1) = v530;
      *v529 = v531;
      *(v529 + 1) = v532;
      v529 += 4;
    }
    while (v528 != 162);
    v513 = v1097 + 1;
    v509 += 256;
    v512 = v1115 + 1024;
    v510 += 256;
    v511 += 256;
    v514 += 1024;
    v1128 += 1024;
  }
  while (v1097 != 135);
  v534 = 43071;
  v535 = 43077;
  v536 = 43127;
  v537 = 43157;
  v538 = &colors->m_Items[43008].b;
  v539 = 168;
  v1116 = &colors->m_Items[43071].b;
  v1098 = &colors->m_Items[43077].b;
  v1081 = &colors->m_Items[43127].b;
  v1068 = &colors->m_Items[43157].b;
  v1129 = 43008;
  do
  {
    v1043 = v539;
    v1055 = v538;
    v540 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v542 = HIDWORD(v1138);
      v544 = v1139;
      v543 = HIDWORD(v1139);
      ++v540;
      *(v538 - 2) = v1138;
      *(v538 - 1) = v542;
      *v538 = v544;
      v538[1] = v543;
      v538 += 4;
    }
    while (v540 != 64);
    v546 = v1116;
    v547 = 0;
    do
    {
      v548 = Lerp(1.0, 0.85, v547 * 0.14286, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v548, v548, v548, 1.0);
      v549 = HIDWORD(v1138);
      v551 = v1139;
      v550 = HIDWORD(v1139);
      ++v547;
      *(v546 - 2) = v1138;
      *(v546 - 1) = v549;
      *v546 = v551;
      *(v546 + 1) = v550;
      v546 += 4;
    }
    while (v547 != 7);
    v553 = v1098;
    v554 = 0;
    do
    {
      v555 = Lerp(0.85, 0.25, v554 * 0.019608, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v555, v555, v555, 1.0);
      v556 = HIDWORD(v1138);
      v558 = v1139;
      v557 = HIDWORD(v1139);
      ++v554;
      *(v553 - 2) = v1138;
      *(v553 - 1) = v556;
      *v553 = v558;
      *(v553 + 1) = v557;
      v553 += 4;
    }
    while (v554 != 51);
    v560 = v1081;
    v561 = 0;
    do
    {
      v562 = Lerp(0.25, 0.2, v561 * 0.032258, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v562, v562, v562, 1.0);
      v563 = HIDWORD(v1138);
      v565 = v1139;
      v564 = HIDWORD(v1139);
      ++v561;
      *(v560 - 2) = v1138;
      *(v560 - 1) = v563;
      *v560 = v565;
      *(v560 + 1) = v564;
      v560 += 4;
    }
    while (v561 != 31);
    v567 = v1068;
    v568 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.2, 0.2, 0.2, 1.0);
      v569 = HIDWORD(v1138);
      v571 = v1139;
      v570 = HIDWORD(v1139);
      ++v568;
      *(v567 - 2) = v1138;
      *(v567 - 1) = v569;
      *v567 = v571;
      *(v567 + 1) = v570;
      v567 += 4;
    }
    while (v568 != 107);
    v1129 += 256;
    v1116 += 1024;
    v1098 += 1024;
    v539 = v1043 + 1;
    v538 = v1055 + 1024;
    v534 += 256;
    v535 += 256;
    v536 += 256;
    v537 += 256;
    v1081 += 1024;
    v1068 += 1024;
  }
  while (v1043 != 175);
  v573 = 45135;
  v574 = 45155;
  v575 = 45180;
  v576 = 45205;
  v577 = &colors->m_Items[45056].b;
  v578 = 176;
  v1117 = &colors->m_Items[45135].b;
  v1099 = &colors->m_Items[45155].b;
  v1082 = &colors->m_Items[45180].b;
  v1069 = &colors->m_Items[45205].b;
  v1130 = 45056;
  do
  {
    v1044 = v578;
    v1056 = v577;
    v579 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v581 = HIDWORD(v1138);
      v583 = v1139;
      v582 = HIDWORD(v1139);
      ++v579;
      *(v577 - 2) = v1138;
      *(v577 - 1) = v581;
      *v577 = v583;
      v577[1] = v582;
      v577 += 4;
    }
    while (v579 != 80);
    v585 = v1117;
    v586 = 0;
    do
    {
      v587 = Lerp(1.0, 0.85, v586 * 0.047619, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v587, v587, v587, 1.0);
      v588 = HIDWORD(v1138);
      v590 = v1139;
      v589 = HIDWORD(v1139);
      ++v586;
      *(v585 - 2) = v1138;
      *(v585 - 1) = v588;
      *v585 = v590;
      *(v585 + 1) = v589;
      v585 += 4;
    }
    while (v586 != 21);
    v592 = v1099;
    v593 = 0;
    do
    {
      v594 = Lerp(0.85, 0.25, v593 * 0.038462, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v594, v594, v594, 1.0);
      v595 = HIDWORD(v1138);
      v597 = v1139;
      v596 = HIDWORD(v1139);
      ++v593;
      *(v592 - 2) = v1138;
      *(v592 - 1) = v595;
      *v592 = v597;
      *(v592 + 1) = v596;
      v592 += 4;
    }
    while (v593 != 26);
    v599 = v1082;
    v600 = 0;
    do
    {
      v601 = Lerp(0.25, 0.2, v600 * 0.038462, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v601, v601, v601, 1.0);
      v602 = HIDWORD(v1138);
      v604 = v1139;
      v603 = HIDWORD(v1139);
      ++v600;
      *(v599 - 2) = v1138;
      *(v599 - 1) = v602;
      *v599 = v604;
      *(v599 + 1) = v603;
      v599 += 4;
    }
    while (v600 != 26);
    v606 = v1069;
    v607 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.2, 0.2, 0.2, 1.0);
      v608 = HIDWORD(v1138);
      v610 = v1139;
      v609 = HIDWORD(v1139);
      ++v607;
      *(v606 - 2) = v1138;
      *(v606 - 1) = v608;
      *v606 = v610;
      *(v606 + 1) = v609;
      v606 += 4;
    }
    while (v607 != 107);
    v1130 += 256;
    v1117 += 1024;
    v1099 += 1024;
    v578 = v1044 + 1;
    v577 = v1056 + 1024;
    v573 += 256;
    v574 += 256;
    v575 += 256;
    v576 += 256;
    v1082 += 1024;
    v1069 += 1024;
  }
  while (v1044 != 183);
  v612 = 47183;
  v613 = 47203;
  v614 = 47228;
  v615 = 47253;
  v616 = &colors->m_Items[47104].b;
  v617 = 184;
  v1118 = &colors->m_Items[47183].b;
  v1100 = &colors->m_Items[47203].b;
  v1083 = &colors->m_Items[47228].b;
  v1070 = &colors->m_Items[47253].b;
  v1131 = 47104;
  do
  {
    v1045 = v617;
    v1057 = v616;
    v618 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
      v620 = HIDWORD(v1138);
      v622 = v1139;
      v621 = HIDWORD(v1139);
      ++v618;
      *(v616 - 2) = v1138;
      *(v616 - 1) = v620;
      *v616 = v622;
      v616[1] = v621;
      v616 += 4;
    }
    while (v618 != 80);
    v624 = v1118;
    v625 = 0;
    do
    {
      v626 = Lerp(1.0, 0.85, v625 * 0.047619, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v626, v626, v626, 1.0);
      v627 = HIDWORD(v1138);
      v629 = v1139;
      v628 = HIDWORD(v1139);
      ++v625;
      *(v624 - 2) = v1138;
      *(v624 - 1) = v627;
      *v624 = v629;
      *(v624 + 1) = v628;
      v624 += 4;
    }
    while (v625 != 21);
    v631 = v1100;
    v632 = 0;
    do
    {
      v633 = Lerp(0.85, 0.0, v632 * 0.038462, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v633, v633, v633, 1.0);
      v634 = HIDWORD(v1138);
      v636 = v1139;
      v635 = HIDWORD(v1139);
      ++v632;
      *(v631 - 2) = v1138;
      *(v631 - 1) = v634;
      *v631 = v636;
      *(v631 + 1) = v635;
      v631 += 4;
    }
    while (v632 != 26);
    v638 = v1083;
    v639 = 0;
    do
    {
      v640 = Lerp(0.0, 0.0, v639 * 0.038462, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v640, v640, v640, 1.0);
      v641 = HIDWORD(v1138);
      v643 = v1139;
      v642 = HIDWORD(v1139);
      ++v639;
      *(v638 - 2) = v1138;
      *(v638 - 1) = v641;
      *v638 = v643;
      *(v638 + 1) = v642;
      v638 += 4;
    }
    while (v639 != 26);
    v645 = v1070;
    v646 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
      v647 = HIDWORD(v1138);
      v649 = v1139;
      v648 = HIDWORD(v1139);
      ++v646;
      *(v645 - 2) = v1138;
      *(v645 - 1) = v647;
      *v645 = v649;
      *(v645 + 1) = v648;
      v645 += 4;
    }
    while (v646 != 107);
    v1131 += 256;
    v1118 += 1024;
    v1100 += 1024;
    v617 = v1045 + 1;
    v616 = v1057 + 1024;
    v612 += 256;
    v613 += 256;
    v614 += 256;
    v615 += 256;
    v1083 += 1024;
    v1070 += 1024;
  }
  while (v1045 != 191);
  v651 = 49159;
  v652 = 49167;
  v653 = 49189;
  v1119 = &colors->m_Items[49159].b;
  v654 = 192;
  v1101 = &colors->m_Items[49167].b;
  v1084 = &colors->m_Items[49189].b;
  v1071 = &colors->m_Items[49279].b;
  v655 = 49279;
  do
  {
    v1058 = v654;
    v656 = v654 << 8;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v657 = HIDWORD(v1138);
    v658 = v1139;
    v659 = HIDWORD(v1139);
    v661 = &colors->obj + v656;
    LODWORD(v661[2].klass) = v1138;
    HIDWORD(v661[2].klass) = v657;
    LODWORD(v661[2].monitor) = v658;
    HIDWORD(v661[2].monitor) = v659;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v662 = v656 | 1;
    v1132 = v656;
    v663 = HIDWORD(v1138);
    v665 = v1139;
    v664 = HIDWORD(v1139);
    v667 = &colors->obj + v662;
    LODWORD(v667[2].klass) = v1138;
    HIDWORD(v667[2].klass) = v663;
    LODWORD(v667[2].monitor) = v665;
    HIDWORD(v667[2].monitor) = v664;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v668 = HIDWORD(v1138);
    v670 = v1139;
    v669 = HIDWORD(v1139);
    v672 = &colors->obj + (v1132 | 2);
    LODWORD(v672[2].klass) = v1138;
    HIDWORD(v672[2].klass) = v668;
    LODWORD(v672[2].monitor) = v670;
    HIDWORD(v672[2].monitor) = v669;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v673 = HIDWORD(v1138);
    v675 = v1139;
    v674 = HIDWORD(v1139);
    v677 = &colors->obj + (v1132 | 3);
    LODWORD(v677[2].klass) = v1138;
    HIDWORD(v677[2].klass) = v673;
    LODWORD(v677[2].monitor) = v675;
    HIDWORD(v677[2].monitor) = v674;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v678 = HIDWORD(v1138);
    v680 = v1139;
    v679 = HIDWORD(v1139);
    v682 = &colors->obj + (v1132 | 4);
    LODWORD(v682[2].klass) = v1138;
    HIDWORD(v682[2].klass) = v678;
    LODWORD(v682[2].monitor) = v680;
    HIDWORD(v682[2].monitor) = v679;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v683 = HIDWORD(v1138);
    v685 = v1139;
    v684 = HIDWORD(v1139);
    v687 = &colors->obj + (v1132 | 5);
    LODWORD(v687[2].klass) = v1138;
    HIDWORD(v687[2].klass) = v683;
    LODWORD(v687[2].monitor) = v685;
    HIDWORD(v687[2].monitor) = v684;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v688 = HIDWORD(v1138);
    v690 = v1139;
    v689 = HIDWORD(v1139);
    v692 = &colors->obj + (v1132 | 6);
    LODWORD(v692[2].klass) = v1138;
    HIDWORD(v692[2].klass) = v688;
    LODWORD(v692[2].monitor) = v690;
    HIDWORD(v692[2].monitor) = v689;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v694 = HIDWORD(v1138);
    v696 = v1139;
    v695 = HIDWORD(v1139);
    v698 = &colors->obj + (v1132 | 7);
    LODWORD(v698[2].klass) = v1138;
    HIDWORD(v698[2].klass) = v694;
    v699 = v1119;
    v700 = 0;
    LODWORD(v698[2].monitor) = v696;
    HIDWORD(v698[2].monitor) = v695;
    do
    {
      v701 = Lerp(1.0, 0.85, v700 * 0.11111, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v701, v701, v701, 1.0);
      v702 = HIDWORD(v1138);
      v704 = v1139;
      v703 = HIDWORD(v1139);
      ++v700;
      *(v699 - 2) = v1138;
      *(v699 - 1) = v702;
      *v699 = v704;
      *(v699 + 1) = v703;
      v699 += 4;
    }
    while (v700 != 9);
    v706 = v1101;
    v707 = 0;
    do
    {
      v708 = Lerp(0.85, 0.3, v707 * 0.043478, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v708, v708, v708, 1.0);
      v709 = HIDWORD(v1138);
      v711 = v1139;
      v710 = HIDWORD(v1139);
      ++v707;
      *(v706 - 2) = v1138;
      *(v706 - 1) = v709;
      *v706 = v711;
      *(v706 + 1) = v710;
      v706 += 4;
    }
    while (v707 != 23);
    v713 = v1084;
    v714 = 0;
    do
    {
      v715 = Lerp(0.3, 0.0, v714 * 0.010989, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v715, v715, v715, 1.0);
      v716 = HIDWORD(v1138);
      v718 = v1139;
      v717 = HIDWORD(v1139);
      ++v714;
      *(v713 - 2) = v1138;
      *(v713 - 1) = v716;
      *v713 = v718;
      *(v713 + 1) = v717;
      v713 += 4;
    }
    while (v714 != 91);
    v720 = v1071;
    v721 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
      v722 = HIDWORD(v1138);
      v724 = v1139;
      v723 = HIDWORD(v1139);
      ++v721;
      *(v720 - 2) = v1138;
      *(v720 - 1) = v722;
      *v720 = v724;
      *(v720 + 1) = v723;
      v720 += 4;
    }
    while (v721 != 129);
    v1119 += 1024;
    v1101 += 1024;
    v654 = v1058 + 1;
    v651 += 256;
    v652 += 256;
    v653 += 256;
    v655 += 256;
    v1084 += 1024;
    v1071 += 1024;
  }
  while (v1058 != 199);
  v726 = 51201;
  v727 = 51215;
  v728 = 51399;
  v1133 = &colors->m_Items[51201].b;
  v729 = 200;
  v1120 = &colors->m_Items[51215].b;
  v1102 = &colors->m_Items[51329].b;
  v1085 = &colors->m_Items[51399].b;
  v730 = 51329;
  do
  {
    v1072 = v729;
    v731 = v729 << 8;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v732 = HIDWORD(v1138);
    v734 = v1139;
    v733 = HIDWORD(v1139);
    v736 = &colors->obj + v731;
    LODWORD(v736[2].klass) = v1138;
    HIDWORD(v736[2].klass) = v732;
    LODWORD(v736[2].monitor) = v734;
    HIDWORD(v736[2].monitor) = v733;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v738 = HIDWORD(v1138);
    v740 = v1139;
    v739 = HIDWORD(v1139);
    v741 = v731 | 1;
    v743 = &colors->obj + v741;
    LODWORD(v743[2].klass) = v1138;
    HIDWORD(v743[2].klass) = v738;
    v744 = v1133;
    v745 = 0;
    LODWORD(v743[2].monitor) = v740;
    HIDWORD(v743[2].monitor) = v739;
    do
    {
      v746 = Lerp(1.0, 0.85, v745 * 0.066667, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v746, v746, v746, 1.0);
      v747 = HIDWORD(v1138);
      v749 = v1139;
      v748 = HIDWORD(v1139);
      ++v745;
      *(v744 - 2) = v1138;
      *(v744 - 1) = v747;
      *v744 = v749;
      *(v744 + 1) = v748;
      v744 += 4;
    }
    while (v745 != 15);
    v751 = v1120;
    v752 = 0;
    do
    {
      v753 = Lerp(0.85, 0.2, v752 * 0.0086957, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v753, v753, v753, 1.0);
      v754 = HIDWORD(v1138);
      v756 = v1139;
      v755 = HIDWORD(v1139);
      ++v752;
      *(v751 - 2) = v1138;
      *(v751 - 1) = v754;
      *v751 = v756;
      *(v751 + 1) = v755;
      v751 += 4;
    }
    while (v752 != 115);
    v758 = v1102;
    v759 = 0;
    do
    {
      v760 = Lerp(0.2, 0.1, v759 * 0.014085, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v760, v760, v760, 1.0);
      v761 = HIDWORD(v1138);
      v763 = v1139;
      v762 = HIDWORD(v1139);
      ++v759;
      *(v758 - 2) = v1138;
      *(v758 - 1) = v761;
      *v758 = v763;
      *(v758 + 1) = v762;
      v758 += 4;
    }
    while (v759 != 71);
    v765 = v1085;
    v766 = 0;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.1, 0.1, 0.1, 1.0);
      v767 = HIDWORD(v1138);
      v769 = v1139;
      v768 = HIDWORD(v1139);
      ++v766;
      *(v765 - 2) = v1138;
      *(v765 - 1) = v767;
      *v765 = v769;
      *(v765 + 1) = v768;
      v765 += 4;
    }
    while (v766 != 57);
    v1133 += 1024;
    v1120 += 1024;
    v729 = v1072 + 1;
    v726 += 256;
    v727 += 256;
    v730 += 256;
    v728 += 256;
    v1102 += 1024;
    v1085 += 1024;
  }
  while (v1072 != 207);
  v771 = &colors->m_Items[53248].b;
  v772 = 53248;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v773 = HIDWORD(v1138);
    v775 = v1139;
    v774 = HIDWORD(v1139);
    ++v772;
    *(v771 - 2) = v1138;
    *(v771 - 1) = v773;
    *v771 = v775;
    v771[1] = v774;
    v771 += 4;
  }
  while (v772 != 53504);
  v777 = 0;
  v778 = &colors->m_Items[53504].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v779 = HIDWORD(v1138);
    v781 = v1139;
    v780 = HIDWORD(v1139);
    ++v777;
    *(v778 - 2) = v1138;
    *(v778 - 1) = v779;
    *v778 = v781;
    v778[1] = v780;
    v778 += 4;
  }
  while (v777 != 256);
  v783 = 0;
  v784 = &colors->m_Items[53760].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v785 = HIDWORD(v1138);
    v787 = v1139;
    v786 = HIDWORD(v1139);
    ++v783;
    *(v784 - 2) = v1138;
    *(v784 - 1) = v785;
    *v784 = v787;
    v784[1] = v786;
    v784 += 4;
  }
  while (v783 != 256);
  v789 = 0;
  v790 = &colors->m_Items[54016].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v791 = HIDWORD(v1138);
    v793 = v1139;
    v792 = HIDWORD(v1139);
    ++v789;
    *(v790 - 2) = v1138;
    *(v790 - 1) = v791;
    *v790 = v793;
    v790[1] = v792;
    v790 += 4;
  }
  while (v789 != 256);
  v795 = 0;
  v796 = &colors->m_Items[54272].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v797 = HIDWORD(v1138);
    v799 = v1139;
    v798 = HIDWORD(v1139);
    ++v795;
    *(v796 - 2) = v1138;
    *(v796 - 1) = v797;
    *v796 = v799;
    v796[1] = v798;
    v796 += 4;
  }
  while (v795 != 256);
  v801 = 0;
  v802 = &colors->m_Items[54528].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v803 = HIDWORD(v1138);
    v805 = v1139;
    v804 = HIDWORD(v1139);
    ++v801;
    *(v802 - 2) = v1138;
    *(v802 - 1) = v803;
    *v802 = v805;
    v802[1] = v804;
    v802 += 4;
  }
  while (v801 != 256);
  v807 = 0;
  v808 = &colors->m_Items[54784].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v809 = HIDWORD(v1138);
    v811 = v1139;
    v810 = HIDWORD(v1139);
    ++v807;
    *(v808 - 2) = v1138;
    *(v808 - 1) = v809;
    *v808 = v811;
    v808[1] = v810;
    v808 += 4;
  }
  while (v807 != 256);
  v813 = 0;
  v814 = &colors->m_Items[55040].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v816 = HIDWORD(v1138);
    v818 = v1139;
    v817 = HIDWORD(v1139);
    ++v813;
    *(v814 - 2) = v1138;
    *(v814 - 1) = v816;
    *v814 = v818;
    v814[1] = v817;
    v814 += 4;
  }
  while (v813 != 256);
  v820 = &colors->m_Items[55296].b;
  v1134 = &colors->m_Items[55486].b;
  v821 = 216;
  v822 = 55296;
  v823 = 55486;
  do
  {
    v824 = 0;
    v825 = v821 << 8;
    v826 = v820;
    v1121 = v820;
    do
    {
      v827 = Lerp(0.0, 0.5, v824 * 0.0052632, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v827, v827, v827, 1.0);
      v828 = HIDWORD(v1138);
      v830 = v1139;
      v829 = HIDWORD(v1139);
      ++v824;
      *(v826 - 2) = v1138;
      *(v826 - 1) = v828;
      *v826 = v830;
      *(v826 + 1) = v829;
      v826 += 4;
    }
    while (v824 != 190);
    v832 = v1134;
    v833 = 0;
    do
    {
      v834 = Lerp(0.5, 1.0, v833 * 0.016667, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v834, v834, v834, 1.0);
      v835 = HIDWORD(v1138);
      v837 = v1139;
      v836 = HIDWORD(v1139);
      ++v833;
      *(v832 - 2) = v1138;
      *(v832 - 1) = v835;
      *v832 = v837;
      *(v832 + 1) = v836;
      v832 += 4;
    }
    while (v833 != 60);
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v839 = HIDWORD(v1138);
    v841 = v1139;
    v840 = HIDWORD(v1139);
    v843 = &colors->obj + (v825 | 0xFA);
    LODWORD(v843[2].klass) = v1138;
    HIDWORD(v843[2].klass) = v839;
    LODWORD(v843[2].monitor) = v841;
    HIDWORD(v843[2].monitor) = v840;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v844 = HIDWORD(v1138);
    v846 = v1139;
    v845 = HIDWORD(v1139);
    v848 = &colors->obj + (v825 | 0xFB);
    LODWORD(v848[2].klass) = v1138;
    HIDWORD(v848[2].klass) = v844;
    LODWORD(v848[2].monitor) = v846;
    HIDWORD(v848[2].monitor) = v845;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v849 = HIDWORD(v1138);
    v851 = v1139;
    v850 = HIDWORD(v1139);
    v853 = &colors->obj + (v825 | 0xFC);
    LODWORD(v853[2].klass) = v1138;
    HIDWORD(v853[2].klass) = v849;
    LODWORD(v853[2].monitor) = v851;
    HIDWORD(v853[2].monitor) = v850;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v854 = HIDWORD(v1138);
    v856 = v1139;
    v855 = HIDWORD(v1139);
    v858 = &colors->obj + (v825 | 0xFD);
    LODWORD(v858[2].klass) = v1138;
    HIDWORD(v858[2].klass) = v854;
    LODWORD(v858[2].monitor) = v856;
    HIDWORD(v858[2].monitor) = v855;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v859 = HIDWORD(v1138);
    v861 = v1139;
    v860 = HIDWORD(v1139);
    v863 = &colors->obj + (v825 | 0xFE);
    LODWORD(v863[2].klass) = v1138;
    HIDWORD(v863[2].klass) = v859;
    LODWORD(v863[2].monitor) = v861;
    HIDWORD(v863[2].monitor) = v860;
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 1.0, 1.0, 1.0, 1.0);
    v864 = v825 | 0xFF;
    v865 = (v825 | 0xFFuLL) >= LODWORD(colors->max_length);
    v866 = HIDWORD(v1138);
    v868 = v1139;
    v867 = HIDWORD(v1139);
    v870 = &colors->obj + v864;
    ++v821;
    v822 += 256;
    v823 += 256;
    v820 = v1121 + 1024;
    v1134 += 1024;
    LODWORD(v870[2].klass) = v1138;
    HIDWORD(v870[2].klass) = v866;
    LODWORD(v870[2].monitor) = v868;
    HIDWORD(v870[2].monitor) = v867;
  }
  while (v821 != 224);
  v871 = &colors->m_Items[57344].b;
  v872 = 57344;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v873 = HIDWORD(v1138);
    v875 = v1139;
    v874 = HIDWORD(v1139);
    ++v872;
    *(v871 - 2) = v1138;
    *(v871 - 1) = v873;
    *v871 = v875;
    v871[1] = v874;
    v871 += 4;
  }
  while (v872 != 57600);
  v877 = 0;
  v878 = &colors->m_Items[57600].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v879 = HIDWORD(v1138);
    v881 = v1139;
    v880 = HIDWORD(v1139);
    ++v877;
    *(v878 - 2) = v1138;
    *(v878 - 1) = v879;
    *v878 = v881;
    v878[1] = v880;
    v878 += 4;
  }
  while (v877 != 256);
  v883 = 0;
  v884 = &colors->m_Items[57856].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v885 = HIDWORD(v1138);
    v887 = v1139;
    v886 = HIDWORD(v1139);
    ++v883;
    *(v884 - 2) = v1138;
    *(v884 - 1) = v885;
    *v884 = v887;
    v884[1] = v886;
    v884 += 4;
  }
  while (v883 != 256);
  v889 = 0;
  v890 = &colors->m_Items[58112].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v891 = HIDWORD(v1138);
    v893 = v1139;
    v892 = HIDWORD(v1139);
    ++v889;
    *(v890 - 2) = v1138;
    *(v890 - 1) = v891;
    *v890 = v893;
    v890[1] = v892;
    v890 += 4;
  }
  while (v889 != 256);
  v895 = 0;
  v896 = &colors->m_Items[58368].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v897 = HIDWORD(v1138);
    v899 = v1139;
    v898 = HIDWORD(v1139);
    ++v895;
    *(v896 - 2) = v1138;
    *(v896 - 1) = v897;
    *v896 = v899;
    v896[1] = v898;
    v896 += 4;
  }
  while (v895 != 256);
  v901 = 0;
  v902 = &colors->m_Items[58624].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v903 = HIDWORD(v1138);
    v905 = v1139;
    v904 = HIDWORD(v1139);
    ++v901;
    *(v902 - 2) = v1138;
    *(v902 - 1) = v903;
    *v902 = v905;
    v902[1] = v904;
    v902 += 4;
  }
  while (v901 != 256);
  v907 = 0;
  v908 = &colors->m_Items[58880].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v909 = HIDWORD(v1138);
    v911 = v1139;
    v910 = HIDWORD(v1139);
    ++v907;
    *(v908 - 2) = v1138;
    *(v908 - 1) = v909;
    *v908 = v911;
    v908[1] = v910;
    v908 += 4;
  }
  while (v907 != 256);
  v913 = 0;
  v914 = &colors->m_Items[59136].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v915 = HIDWORD(v1138);
    v917 = v1139;
    v916 = HIDWORD(v1139);
    ++v913;
    *(v914 - 2) = v1138;
    *(v914 - 1) = v915;
    *v914 = v917;
    v914[1] = v916;
    v914 += 4;
  }
  while (v913 != 256);
  v919 = 0;
  v920 = &colors->m_Items[59392].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v921 = HIDWORD(v1138);
    v923 = v1139;
    v922 = HIDWORD(v1139);
    ++v919;
    *(v920 - 2) = v1138;
    *(v920 - 1) = v921;
    *v920 = v923;
    v920[1] = v922;
    v920 += 4;
  }
  while (v919 != 256);
  v925 = 0;
  v926 = &colors->m_Items[59648].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v927 = HIDWORD(v1138);
    v929 = v1139;
    v928 = HIDWORD(v1139);
    ++v925;
    *(v926 - 2) = v1138;
    *(v926 - 1) = v927;
    *v926 = v929;
    v926[1] = v928;
    v926 += 4;
  }
  while (v925 != 256);
  v931 = 0;
  v932 = &colors->m_Items[59904].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v933 = HIDWORD(v1138);
    v935 = v1139;
    v934 = HIDWORD(v1139);
    ++v931;
    *(v932 - 2) = v1138;
    *(v932 - 1) = v933;
    *v932 = v935;
    v932[1] = v934;
    v932 += 4;
  }
  while (v931 != 256);
  v937 = 0;
  v938 = &colors->m_Items[60160].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v939 = HIDWORD(v1138);
    v941 = v1139;
    v940 = HIDWORD(v1139);
    ++v937;
    *(v938 - 2) = v1138;
    *(v938 - 1) = v939;
    *v938 = v941;
    v938[1] = v940;
    v938 += 4;
  }
  while (v937 != 256);
  v943 = 0;
  v944 = &colors->m_Items[60416].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v945 = HIDWORD(v1138);
    v947 = v1139;
    v946 = HIDWORD(v1139);
    ++v943;
    *(v944 - 2) = v1138;
    *(v944 - 1) = v945;
    *v944 = v947;
    v944[1] = v946;
    v944 += 4;
  }
  while (v943 != 256);
  v949 = 0;
  v950 = &colors->m_Items[60672].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v951 = HIDWORD(v1138);
    v953 = v1139;
    v952 = HIDWORD(v1139);
    ++v949;
    *(v950 - 2) = v1138;
    *(v950 - 1) = v951;
    *v950 = v953;
    v950[1] = v952;
    v950 += 4;
  }
  while (v949 != 256);
  v955 = 0;
  v956 = &colors->m_Items[60928].b;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v957 = HIDWORD(v1138);
    v959 = v1139;
    v958 = HIDWORD(v1139);
    ++v955;
    *(v956 - 2) = v1138;
    *(v956 - 1) = v957;
    *v956 = v959;
    v956[1] = v958;
    v956 += 4;
  }
  while (v955 != 256);
  v961 = &colors->m_Items[61184].b;
  v962 = 61184;
  do
  {
    v1138 = 0;
    v1139 = 0;
    sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
    v964 = HIDWORD(v1138);
    v966 = v1139;
    v965 = HIDWORD(v1139);
    ++v962;
    *(v961 - 2) = v1138;
    *(v961 - 1) = v964;
    *v961 = v966;
    v961[1] = v965;
    v961 += 4;
  }
  while (v962 != 61440);
  v968 = &colors->m_Items[61440].b;
  v969 = &colors->m_Items[61568].b;
  v970 = 240;
  v971 = 61440;
  v972 = 61568;
  do
  {
    v973 = 0;
    v1135 = v968;
    do
    {
      v974 = Lerp(1.0, 0.0, v973 * 0.0078125, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v974, v974, v974, 1.0);
      v975 = HIDWORD(v1138);
      v977 = v1139;
      v976 = HIDWORD(v1139);
      ++v973;
      *(v968 - 2) = v1138;
      *(v968 - 1) = v975;
      *v968 = v977;
      v968[1] = v976;
      v968 += 4;
    }
    while (v973 != 128);
    v979 = 0;
    v980 = v969;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
      v981 = HIDWORD(v1138);
      v983 = v1139;
      v982 = HIDWORD(v1139);
      ++v979;
      *(v980 - 2) = v1138;
      *(v980 - 1) = v981;
      *v980 = v983;
      *(v980 + 1) = v982;
      v980 += 4;
    }
    while (v979 != 128);
    ++v970;
    v971 += 256;
    v972 += 256;
    v969 += 1024;
    v968 = v1135 + 1024;
  }
  while (v970 != 248);
  v985 = &colors->m_Items[63488].b;
  v986 = &colors->m_Items[63568].b;
  v987 = 63488;
  v988 = 63568;
  do
  {
    v989 = 0;
    v1136 = v985;
    do
    {
      v990 = Lerp(1.0, 0.0, v989 * 0.0125, 0);
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, v990, v990, v990, 1.0);
      v991 = HIDWORD(v1138);
      v993 = v1139;
      v992 = HIDWORD(v1139);
      ++v989;
      *(v985 - 2) = v1138;
      *(v985 - 1) = v991;
      *v985 = v993;
      v985[1] = v992;
      v985 += 4;
    }
    while (v989 != 80);
    v995 = 0;
    v996 = v986;
    do
    {
      v1138 = 0;
      v1139 = 0;
      sub_19EC630(&v1138, 0.0, 0.0, 0.0, 1.0);
      v997 = HIDWORD(v1138);
      v999 = v1139;
      v998 = HIDWORD(v1139);
      ++v995;
      *(v996 - 2) = v1138;
      *(v996 - 1) = v997;
      *v996 = v999;
      *(v996 + 1) = v998;
      v996 += 4;
    }
    while (v995 != 176);
    ++v970;
    v987 += 256;
    v988 += 256;
    v986 += 1024;
    v985 = v1136 + 1024;
  }
  while (v970 != 256);
  {
    v1002 = colors;
  }
  else
  {
    v1002 = colors;
  }
  SetPixels_27471904(kernelObject->HighContrastMode_ToneTexture, v1002);
  set_anisoLevel(kernelObject->HighContrastMode_ToneTexture, 0);
  set_name(kernelObject->HighContrastMode_ToneTexture, "HighContrastMode_ToneTexture");
  Apply_27472496(kernelObject->HighContrastMode_ToneTexture);
}

// 0x100e680
void Ktyousei_DOF(void) {
  UnityEngine_GameObject_o *v2;
  Il2CppObject *Component_object;
  UnityEngine_Rendering_PostProcessing_PostProcessProfile_o *profile;
  Il2CppObject *Setting_object;
  dds3KernelDraw_c *v7;
  Il2CppClass *klass;

  v2 = Find("PPSV2", 0);
  if (op_Inequality(v2, 0, 0))
  {
    Component_object = GetComponent_object_(v2);
    profile = get_profile(Component_object);
    Setting_object = GetSetting_object_(profile);
    if (PPSV2_dof_update)
    {
      else if (PPSV2_dof_use)
      {
        goto LABEL_14;
      }
      LOBYTE(Setting_object[1].monitor) = 0;
      klass = Setting_object[3].klass;
      if ((v7->_2.bitflags2 & 2) != 0)
      {
LABEL_15:
      }
LABEL_19:
      HIDWORD(klass->_1.name) = LODWORD(PPSV2_dof1);
      *(Setting_object[3].monitor + 5) = LODWORD(PPSV2_dof2);
      *(&Setting_object[4].klass->_1.name + 1) = PPSV2_dof3 * 1.02;
      PPSV2_dof_update = 0;
    }
  }
}

// 0x1805ae0
void LightVecInput(f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *soften, f32 *bias) {
  ;
}

// 0x1805af0
void LightVecInput2(f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *soften, f32 *bias) {
  ;
}

// 0x18050a0
void LightVecNormalize(f32 *v0_x, f32 *v0_y, f32 *v0_z) {
  s64 v7;
  s32 v8;

  v8 = 0;
  v7 = 0;
  sub_8524C0(&v7, *v0_x, *v0_y, *v0_z);
  sub_8531D0(&v7, 0);
  *v0_x = v7;
  *v0_y = *(&v7 + 1);
  *v0_z = v8;
}

// 0x18037f0
void NoFindHelper0(char *Owner_name, char *Light_name, sdfVector4_t *pos, sdfVector4_t *lpos) {
  System_String_o *EventCamName;
  f32 y;
  f32 v10;
  f32 z;
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
  f32 *p_z;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  bool v29;
  f32 x;
  f32 v31;
  f32 v32;
  bool v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  System_String_o *v44;
  f32 v45;
  f32 v46;
  bool v47;
  f32 v48;
  f32 v49;
  f32 v50;
  u64 v51;
  System_String_o *v53;
  bool v54;
  bool v55;
  f32 v56;
  f32 v57;
  f32 v58;
  u64 v59;
  f32 v60;
  f32 v61;
  f32 v62;
  f32 v63;
  f32 v64;
  f32 v65;
  f32 v66;
  f32 v67;
  f32 v68;

  EventCamName = GetEventCamName();
  if (op_Equality(Owner_name, "npc_hikawa_e615", 0))
    pos->y = pos->y + -55.0;
  if (op_Equality(Owner_name, "npc_hikawa_e615_060", 0))
    pos->y = pos->y + -55.0;
  if (op_Equality(Owner_name, "npc_yuuko_e615", 0))
    pos->y = pos->y + -100.7;
  if (op_Equality(Owner_name, "npc_gomo_e617", 0))
    pos->y = pos->y + -540.0;
  if (op_Equality(Owner_name, "npc_luci_e617", 0))
    pos->y = pos->y + -547.0;
  if (op_Equality(Owner_name, "npc_tiaki_e621", 0))
    pos->z = pos->z + -60.0;
  if (op_Equality(Owner_name, "npc_hijiri_e623", 0))
  {
    if (!op_Equality(EventCamName, "cam06", 0)
      && !op_Equality(EventCamName, "cam07", 0)
      && !op_Equality(EventCamName, "cam08", 0))
    {
      y = pos->y;
      v10 = -95.0;
      goto LABEL_23;
    }
LABEL_22:
    y = pos->y;
    v10 = -70.0;
LABEL_23:
    pos->y = y + v10;
    return;
  }
  if (op_Equality(Owner_name, "player_tatoo_e628", 0))
    pos->z = -1400.0;
  if (op_Equality(Owner_name, "devil_0x16_e628_0", 0))
  {
    z = pos->z;
    pos->y = pos->y + -270.0;
    pos->z = z + 860.0;
  }
  if (op_Equality(Owner_name, "devil_0x16_e628_050_4", 0))
  {
    if (op_Equality(Light_name, "light02", 0))
    {
      pos->x = pos->x + -80.0;
      v12 = 760.0;
      v13 = -200.0;
    }
    else
    {
      v12 = 860.0;
      v13 = -270.0;
    }
    v14 = pos->z + v12;
    pos->y = pos->y + v13;
    pos->z = v14;
  }
  if (op_Equality(Owner_name, "npc_hijiri_e632", 0))
  {
    if (op_Equality(EventCamName, "cam06", 0))
    {
      v15 = pos->y;
      pos->x = pos->x + 390.0;
      pos->y = v15 + -70.0;
      return;
    }
    if (op_Equality(EventCamName, "cam07", 0)
      || op_Equality(EventCamName, "cam08", 0))
    {
      v20 = pos->y + 170.0;
      v21 = pos->z;
      pos->x = pos->x + 600.0;
      pos->y = v20;
      v22 = 130.0;
    }
    else if (op_Equality(EventCamName, "cam09", 0)
           || op_Equality(EventCamName, "cam10", 0)
           || op_Equality(EventCamName, "cam11", 0))
    {
      v26 = pos->y + 170.0;
      v21 = pos->z;
      pos->x = pos->x + 680.0;
      pos->y = v26;
      v22 = 190.0;
    }
    else
    {
      if (!op_Equality(EventCamName, "cam12", 0))
        goto LABEL_22;
      v32 = pos->y + 160.0;
      v21 = pos->z;
      pos->x = pos->x + 360.0;
      pos->y = v32;
      v22 = 250.0;
    }
    goto LABEL_57;
  }
  if (op_Equality(Owner_name, "f634_manineji", 0))
  {
    v16 = pos->z;
    v17 = pos->y + -60.0;
    pos->x = pos->x + -10.0;
    pos->y = v17;
    v18 = 50.0;
LABEL_38:
    v19 = v16 + v18;
LABEL_58:
    pos->z = v19;
    return;
  }
  if (op_Equality(Owner_name, "npc_tiaki_e635", 0))
  {
    if (op_Equality(Light_name, "light10", 0))
    {
      pos->x = pos->x + -70.0;
      p_z = &pos->z;
      v24 = -370.0;
    }
    else
    {
      if (!op_Equality(Light_name, "light04", 0)
        && !op_Equality(Light_name, "light05", 0))
      {
LABEL_64:
        if (op_Equality(Light_name, "light04", 0))
        {
          *&pos->x = 0xC2C681063D71A9FCLL;
          pos->z = 1294.1;
        }
        return;
      }
      v24 = -100.0;
      p_z = &pos->y;
    }
    *p_z = *p_z + v24;
    goto LABEL_64;
  }
  if (op_Equality(Owner_name, "gozu_e636", 0))
  {
    *&pos->x = 0xC3DF000000000000LL;
    pos->z = 1376.0;
  }
  if (op_Equality(Owner_name, "npc_mane_e636", 0)
    && op_Equality(EventCamName, "cam01", 0))
  {
    v16 = pos->z;
    v25 = pos->y + 80.0;
    pos->x = pos->x + -30.0;
    pos->y = v25;
    v18 = -35.0;
    goto LABEL_38;
  }
  if (op_Equality(Owner_name, "player_tatoo_e636_050", 0))
  {
    y = pos->y;
    v10 = 100.0;
    goto LABEL_23;
  }
  if (op_Equality(Owner_name, "npc_isamu_e639", 0))
    pos->y = -100.0;
  if (op_Equality(Owner_name, "npc_hijiri_e646", 0))
  {
    y = pos->y;
    v10 = -100.0;
    goto LABEL_23;
  }
  if (op_Equality(Owner_name, "npc_yuuko_e651_010", 0))
  {
    y = pos->y;
    v10 = -230.0;
    goto LABEL_23;
  }
  if (op_Equality(Owner_name, "npc_hijiri_e652", 0))
    pos->y = -55.0;
  if (op_Equality(Owner_name, "npc_isamu_e655", 0))
    pos->y = -100.0;
  if (op_Equality(Owner_name, "npc_yuuko_e657", 0))
  {
    v27 = pos->z;
    v28 = pos->y + -40.0;
    pos->x = pos->x + 30.0;
    pos->y = v28;
    pos->z = v27 + 45.0;
  }
  if (op_Equality(Owner_name, "player_tatoo_e658", 0))
  {
    v29 = op_Equality(EventCamName, "cam01", 0);
    x = pos->x;
    v21 = pos->z;
    v31 = pos->y + -180.0;
    if (v29)
    {
      pos->x = x + 130.0;
      pos->y = v31;
      v22 = -1550.0;
    }
    else
    {
      pos->x = x + 120.0;
      pos->y = v31;
      v22 = -1530.0;
    }
    goto LABEL_57;
  }
  if (op_Equality(Owner_name, "devil_0x113_e658_0", 0))
  {
    v33 = op_Equality(EventCamName, "cam03", 0);
    v34 = pos->y;
    pos->x = pos->x + 110.0;
    v35 = pos->z;
    if (v33)
      v36 = 280.0;
    else
      v36 = 190.0;
    pos->y = v34 + v36;
    v19 = v35 + -10.0;
    goto LABEL_58;
  }
  if (op_Equality(Owner_name, "gozhead_e661", 0))
  {
    *&pos->x = 0xC2D53333BFA66666LL;
    pos->z = -154.3;
    return;
  }
  if (op_Equality(Owner_name, "majyo_tiaki_e661", 0))
  {
    if (op_Equality(EventCamName, "cam08", 0)
      || op_Equality(EventCamName, "cam09", 0)
      || op_Equality(EventCamName, "cam10", 0))
    {
      *&pos->x = 0xC234000043570000LL;
      pos->z = -24.0;
    }
    return;
  }
  if (op_Equality(Owner_name, "npc_hijiri_e662", 0))
    pos->y = 0.0;
  if (op_Equality(Owner_name, "npc_isamu_e670", 0))
  {
    y = pos->y;
    v10 = -96.0;
    goto LABEL_23;
  }
  if (op_Equality(Owner_name, "devil_0x11b_e672_0", 0))
  {
    v37 = pos->y + -950.0;
    v21 = pos->z;
    pos->x = pos->x + 330.0;
    pos->y = v37;
    v22 = 880.0;
    goto LABEL_57;
  }
  if (op_Equality(Owner_name, "devil_0x124_e677_0", 0))
  {
    *&pos->x = 0xC480C000C38C0000LL;
    pos->z = -350.0;
    return;
  }
  if (op_Equality(Owner_name, "devil_0x123_e678_0", 0))
  {
    *&pos->x = 0;
    pos->z = 0.0;
    return;
  }
  if (op_Equality(Owner_name, "npc_tiaki_e684_010", 0)
    || op_Equality(Owner_name, "npc_tiaki_e684", 0))
  {
    y = pos->y;
    v10 = -110.0;
    goto LABEL_23;
  }
  if (op_Equality(Owner_name, "player_tatoo_e684_010", 0))
    goto LABEL_110;
  if (op_Equality(Owner_name, "player_tatoo_e684", 0))
  {
    v39 = pos->y + 0.0;
    v16 = pos->z;
    pos->x = pos->x + 1000.0;
    pos->y = v39;
    v18 = 1500.0;
    goto LABEL_38;
  }
  if (op_Equality(Owner_name, "player_tatoo_e686_010", 0))
  {
LABEL_110:
    v38 = pos->z;
    pos->y = pos->y + 80.0;
    v19 = v38 + 650.0;
    goto LABEL_58;
  }
  if (op_Equality(Owner_name, "player_tatoo_e686", 0))
  {
    v40 = pos->y + 80.0;
    v21 = pos->z;
    pos->x = pos->x + 140.0;
    pos->y = v40;
    v22 = 830.0;
    goto LABEL_57;
  }
  if (op_Equality(Owner_name, "player_tatoo_e686_020", 0))
  {
    if (!op_Equality(Light_name, "light11", 0)
      && !op_Equality(Light_name, "light12", 0))
    {
      return;
    }
    v41 = pos->y + 50.0;
    v21 = pos->z;
    pos->x = pos->x + -50.0;
    pos->y = v41;
    v22 = 580.0;
LABEL_57:
    v19 = v21 + v22;
    goto LABEL_58;
  }
  if (op_Equality(Owner_name, "npc_hikawa_e686", 0))
  {
    v42 = pos->y + -100.0;
    pos->x = pos->x + -10.0;
    pos->y = v42;
    v19 = pos->z + -10.0;
    goto LABEL_58;
  }
  if (op_Equality(Owner_name, "player_tatoo_e688_010", 0))
  {
    v44 = GetEventCamName();
    if (op_Equality(v44, "cam03", 0))
    {
      v16 = pos->z;
      v45 = pos->y + 80.0;
      pos->x = pos->x + -25.0;
      pos->y = v45;
      v18 = 650.0;
      goto LABEL_38;
    }
    goto LABEL_110;
  }
  if (op_Equality(Owner_name, "player_tatoo_e688", 0))
  {
    v46 = pos->y + 50.0;
    v21 = pos->z;
    pos->x = pos->x + -150.0;
    pos->y = v46;
    v22 = -380.0;
    goto LABEL_57;
  }
  if (op_Equality(Owner_name, "player_tatoo_e688_020", 0))
  {
    v47 = op_Equality(Light_name, "light10", 0);
    v48 = pos->y;
    pos->x = pos->x + 650.0;
    pos->y = v48 + 50.0;
    v49 = pos->z;
    if (v47)
      v19 = v49 + 180.0;
    else
      v19 = v49 + -70.0;
    goto LABEL_58;
  }
  if (op_Equality(Owner_name, "npc_yuuko_e693_020", 0))
  {
    *&pos->y = 0xC30C0000C2C80000LL;
    return;
  }
  if (op_Equality(Owner_name, "player_tatoo_e705", 0))
  {
    v50 = pos->y;
    pos->x = pos->x + -120.0;
    pos->y = v50 + 160.0;
  }
  if (op_Equality(Owner_name, "npc_luci_old_e713", 0)
    || op_Equality(Owner_name, "npc_luci_old_e714", 0)
    || op_Equality(Owner_name, "npc_luci_old_e715", 0)
    || op_Equality(Owner_name, "npc_luci_old_e718", 0)
    || op_Equality(Owner_name, "npc_luci_old_e719", 0))
  {
    v19 = pos->z + 2280.0;
    goto LABEL_58;
  }
  if (op_Equality(Owner_name, "player_tatoo_e723_raidou", 0))
  {
    v51 = 0xC4610000C1200000LL;
    goto LABEL_146;
  }
  if (op_Equality(Owner_name, "raidou_e723", 0))
  {
    if (!op_Equality(Light_name, "light10", 0))
    {
      *&pos->x = 0xC37A0000C1200000LL;
      pos->z = 3550.0;
      return;
    }
    v53 = GetEventCamName();
    if (op_Equality(v53, "cut01", 0)
      || op_Equality(v53, "cut04", 0))
    {
      *&pos->x = 0xC43B8000C2200000LL;
    }
    else
    {
      if (op_Equality(v53, "cut03", 0)
        || op_Equality(v53, "cut05", 0))
      {
        *&pos->x = 0xC43B8000C2200000LL;
        pos->z = 5210.0;
        return;
      }
      v54 = op_Equality(v53, "cut06", 0);
      *&pos->x = 0xC43B8000C2200000LL;
      if (v54)
      {
        pos->z = 4000.0;
        return;
      }
    }
    pos->z = 5010.0;
    return;
  }
  if (op_Equality(Owner_name, "gouto_e723", 0))
  {
    if (op_Equality(Light_name, "light10", 0))
    {
      *&pos->x = 0xC38C0000C2200000LL;
      pos->z = 5330.0;
    }
    else if (op_Equality(Light_name, "light01", 0))
    {
      *&pos->x = 0xC1200000C2C80000LL;
      pos->z = 3200.0;
    }
    else
    {
      *&pos->x = 0xC1200000C3C80000LL;
      pos->z = 3500.0;
    }
    return;
  }
  if (op_Equality(Owner_name, "player_tatoo_e723_010", 0))
  {
    if (!evtBitCheck(3712))
      return;
    v51 = 0xC3960000C1200000LL;
    goto LABEL_146;
  }
  if (op_Equality(Owner_name, "dante_e723_030", 0))
  {
    *&pos->x = 0xC38C0000C3820000LL;
    pos->z = 5570.0;
    return;
  }
  if (op_Equality(Owner_name, "player_tatoo_e723_030", 0))
  {
    if (!evtBitCheck(3712))
      return;
    v51 = 0xC4250000C1200000LL;
LABEL_146:
    *&pos->x = v51;
    pos->z = 5680.0;
    return;
  }
  if (op_Equality(Owner_name, "dante_e723", 0))
  {
    if (op_Equality(EventCamName, "cam05", 0))
    {
      *&pos->x = 0xC42C800044070000LL;
      pos->z = 5090.0;
    }
    else if (op_Equality(EventCamName, "cam04", 0))
    {
      *&pos->x = 0xC422800044070000LL;
      pos->z = 5120.0;
    }
    else
    {
      v55 = op_Equality(EventCamName, "cam03", 0);
      pos->x = 540.0;
      if (v55)
        *&pos->y = 0x459F1000C4200000LL;
      else
        *&pos->y = 0x459F1000C4250000LL;
    }
    return;
  }
  if (op_Equality(Owner_name, "player_tatoo_e723", 0))
  {
    if (evtBitCheck(3712))
    {
      *&pos->x = 0xC42C8000C2480000LL;
      pos->z = 5460.0;
    }
    return;
  }
  if (op_Equality(Owner_name, "npc_luci_e726", 0))
  {
    *&pos->x = 0xC2A00000C3FA0000LL;
    return;
  }
  if (op_Equality(Owner_name, "npc_luci_old_e726", 0))
  {
    v56 = 320.0;
    if (!op_Equality(EventCamName, "cam06", 0)
      && !op_Equality(EventCamName, "cam075", 0))
    {
      if (op_Equality(EventCamName, "cam09", 0))
        v56 = 320.0;
      else
        v56 = 220.0;
    }
    pos->y = pos->y + v56;
  }
  if (op_Equality(Owner_name, "dante_e728", 0))
  {
    if (op_Equality(EventCamName, "01cam_02", 0))
    {
      *&pos->x = 0;
      pos->z = 200.0;
      return;
    }
    if (op_Equality(EventCamName, "01cam_03", 0))
    {
      v57 = pos->y;
      pos->x = pos->x + 20.0;
      pos->y = v57 + 0.0;
      v19 = pos->z + -100.0;
      goto LABEL_58;
    }
    if (op_Equality(EventCamName, "01cam_04", 0))
    {
      v58 = pos->y + 0.0;
      v21 = pos->z;
      pos->x = pos->x + -190.0;
      pos->y = v58;
      v22 = 20.0;
      goto LABEL_57;
    }
    if (op_Equality(EventCamName, "01cam_05", 0))
    {
      *&pos->x = 0x42DC0000C2C80000LL;
      pos->z = -620.0;
      return;
    }
    if (op_Equality(EventCamName, "01cam_08", 0))
    {
      *&pos->x = 0x447A0000C4278000LL;
      pos->z = -500.0;
      return;
    }
    if (op_Equality(EventCamName, "01cam_06", 0))
    {
      *&pos->x = 0xC1A0000000000000LL;
      pos->z = -650.0;
      return;
    }
    if (op_Equality(EventCamName, "01cam_07", 0)
      || op_Equality(EventCamName, "01cam_09", 0))
    {
      *&pos->x = 0xC3200000433E0000LL;
      pos->z = -870.0;
      return;
    }
  }
  if (op_Equality(Owner_name, "raidou_e730", 0))
  {
    *&pos->x = 0xC3BE000000000000LL;
    pos->z = 50.0;
    if (op_Equality(EventCamName, "01cam_05", 0))
    {
      v59 = 0xC3960000C3910000LL;
      goto LABEL_222;
    }
    if (op_Equality(EventCamName, "01cam_09", 0))
    {
      v59 = 0xC3480000C3910000LL;
      goto LABEL_222;
    }
    if (op_Equality(EventCamName, "01cam_12", 0))
    {
      *&pos->x = 0xC396000042200000LL;
      pos->z = 140.0;
      return;
    }
  }
  if (op_Equality(Owner_name, "dante_e730", 0))
  {
    if (!op_Equality(EventCamName, "01cam_12", 0))
    {
      *&pos->x = 0xC3AA0000C2DC0000LL;
      pos->z = 80.0;
      return;
    }
    v59 = 0x41200000C44A8000LL;
LABEL_222:
    *&pos->x = v59;
    pos->z = 150.0;
    return;
  }
  if (op_Equality(Owner_name, "dante_e731", 0))
  {
    if (op_Equality(EventCamName, "01cam_07", 0))
    {
      v60 = pos->y + 500.0;
      v61 = pos->z;
      pos->x = pos->x + 320.0;
      pos->y = v60;
      pos->z = v61 + 460.0;
    }
    if (op_Equality(EventCamName, "01cam_09", 0))
    {
      v62 = pos->y;
      pos->x = pos->x + 20.0;
      pos->y = v62 + 0.0;
      pos->z = pos->z + 360.0;
    }
    if (op_Equality(EventCamName, "01cam_11", 0))
    {
      v63 = pos->z;
      v64 = pos->y + 80.0;
      pos->x = pos->x + -20.0;
      pos->y = v64;
      pos->z = v63 + 500.0;
    }
    if (op_Equality(EventCamName, "01cam_12", 0))
    {
      v65 = pos->z;
      v66 = pos->y + 80.0;
      pos->x = pos->x + -20.0;
      pos->y = v66;
      pos->z = v65 + 500.0;
    }
    if (op_Equality(EventCamName, "01cam_13", 0))
    {
      v16 = pos->z;
      v67 = pos->y + 80.0;
      pos->x = pos->x + -20.0;
      pos->y = v67;
      v18 = 500.0;
      goto LABEL_38;
    }
  }
  else
  {
    if (op_Equality(Owner_name, "raidou_e731", 0))
    {
      v19 = pos->z + -1030.0;
      goto LABEL_58;
    }
    if (op_Equality(Owner_name, "devil_0x156_e750_0", 0))
    {
      v68 = pos->y + 0.0;
      v16 = pos->z;
      pos->x = pos->x + 1200.0;
      pos->y = v68;
      v18 = -350.0;
      goto LABEL_38;
    }
  }
}

// 0x1802a90
void NoFindHelper0_DbgInput(sdfVector4_t *pos, sdfVector4_t *lpos, char *Light_name) {
  bool v20;
  f32 x;
  f32 y;
  f32 z;
  System_Object_array *v25;
  s64 *v27;
  s64 *v28;
  s64 *v31;
  s64 *v32;
  s64 *v35;
  s64 *v36;
  s64 *v39;
  s64 *v40;
  s64 *v43;
  s64 *v44;
  s64 *v47;
  s64 *v48;
  s64 *v51;
  s64 *v52;
  s64 *v55;
  s64 *v56;
  s64 *v59;
  s64 *v60;
  Il2CppObject *v65;
  f32 v66;
  f32 v67;
  f32 v68;
  f32 v69;
  f32 v70;
  f32 v71;
  UnityEngine_Color_o color;
  f32 v93;
  f32 v94;
  f32 v95;
  f32 v96;
  f32 v97;
  f32 v98;
  f32 dbg_z;
  f32 dbg_y;
  f32 dbg_x;
  s64 v102;
  f32 v103;
  s64 v104;
  f32 v105;
  UnityEngine_Vector3_o v106;
  UnityEngine_Vector3_o v107;

  v105 = 0.0;
  v104 = 0;
  v103 = 0.0;
  v102 = 0;
  else if (!DDS3_PADCHECK_REP(10))
  {
    goto LABEL_10;
  }
  dbg_x = 0.0;
  dbg_y = 0.0;
  dbg_z = 0.0;
LABEL_10:
  else if (!DDS3_PADCHECK_REP(4))
  {
    goto LABEL_17;
  }
  dbg_x = dbg_x + -10.0;
LABEL_17:
  else if (!DDS3_PADCHECK_REP(5))
  {
    goto LABEL_24;
  }
  dbg_x = dbg_x + 10.0;
LABEL_24:
  else if (!DDS3_PADCHECK_REP(7))
  {
    goto LABEL_31;
  }
  dbg_z = dbg_z + -10.0;
LABEL_31:
  else if (!DDS3_PADCHECK_REP(6))
  {
    goto LABEL_38;
  }
  dbg_z = dbg_z + 10.0;
LABEL_38:
  else if (!DDS3_PADCHECK_REP(8))
  {
    goto LABEL_45;
  }
  dbg_y = dbg_y + -10.0;
LABEL_45:
  v20 = DDS3_PADCHECK_REP(9);
  if (v20)
  {
    dbg_y = dbg_y + 10.0;
  }
  x = pos->x;
  y = pos->y;
  z = pos->z;
  pos->x = x + dbg_x;
  pos->y = y + dbg_y;
  pos->z = z + dbg_z;
  v25 = NewSpecific(object, 0x14u);
  v25->m_Items[0] = "dbg_xyz : ";
  v27 = sub_8D3950(f32, &dbg_x);
  v28 = v27;
  v25->m_Items[1] = v28;
  v25->m_Items[2] = " , ";
  v31 = sub_8D3950(f32, &dbg_y);
  v32 = v31;
  v25->m_Items[3] = v32;
  v25->m_Items[4] = " , ";
  v35 = sub_8D3950(f32, &dbg_z);
  v36 = v35;
  v25->m_Items[5] = v36;
  v25->m_Items[6] = "   キャラxyz : ";
  v98 = pos->x;
  v39 = sub_8D3950(f32, &v98);
  v40 = v39;
  v25->m_Items[7] = v40;
  v25->m_Items[8] = " , ";
  v97 = pos->y;
  v43 = sub_8D3950(f32, &v97);
  v44 = v43;
  v25->m_Items[9] = v44;
  v25->m_Items[10] = " , ";
  v96 = pos->z;
  v47 = sub_8D3950(f32, &v96);
  v48 = v47;
  v25->m_Items[11] = v48;
  v25->m_Items[12] = "   配置ライトxyz : ";
  v95 = lpos->x;
  v51 = sub_8D3950(f32, &v95);
  v52 = v51;
  v25->m_Items[13] = v52;
  v25->m_Items[14] = " , ";
  v94 = lpos->y;
  v55 = sub_8D3950(f32, &v94);
  v56 = v55;
  v25->m_Items[15] = v56;
  v25->m_Items[16] = " , ";
  v93 = lpos->z;
  v59 = sub_8D3950(f32, &v93);
  v60 = v59;
  v25->m_Items[17] = v60;
  v25->m_Items[18] = "  : ";
  v25->m_Items[19] = Light_name;
  v65 = Concat_5270224(v25);
  Log(v65, 0);
  sub_8524C0(&v104, pos->x, pos->y, pos->z);
  sub_8524C0(&v102, lpos->x - pos->x, lpos->y - pos->y, lpos->z - pos->z);
  v105 = v105 / 100.0;
  v67 = v105;
  v103 = v103 / 100.0;
  v69 = v103;
  *&v104 = *&v104 / 100.0;
  v66 = *&v104;
  *(&v104 + 1) = *(&v104 + 1) / -100.0;
  v70 = *(&v104 + 1);
  *&v102 = *&v102 / 100.0;
  v68 = *&v102;
  *(&v102 + 1) = *(&v102 + 1) / -100.0;
  v71 = *(&v102 + 1);
  color = get_green();
  v106.x = v66;
  v106.y = v70;
  v106.z = v67;
  v107.x = v68;
  v107.y = v71;
  v107.z = v69;
  DrawRay(v106, v107, color);
}

// 0x17fa500
void OverWrite_SkyLight(s32 fld, s32 tbl_idx, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b) {
  u64 v16;
  struct dds3UnityEx_Fld_FldSkyLightOvweWrite_t_array *Tbl_FldSkyLightOvweWrite;
  u64 max_length_low;
  dds3UnityEx_Fld_FldSkyLightOvweWrite_t_o *v21;
  s32 v22;
  System_Object_array *v23;
  s64 *v25;
  s64 *v26;
  s64 *v31;
  s64 *v32;
  s64 *v37;
  s64 *v38;
  s64 *v43;
  s64 *v44;
  s64 *v49;
  s64 *v50;
  s64 *v55;
  s64 *v56;
  s64 *v61;
  s64 *v62;
  Il2CppObject *v66;
  s32 v69;

  v16 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(Tbl_FldSkyLightOvweWrite->max_length);
    if (v16 >= max_length_low)
      break;
    else if (v16 >= max_length_low)
    {
      goto LABEL_12;
    }
    v21 = Tbl_FldSkyLightOvweWrite->m_Items[v16];
    v22 = v21->fld;
    if (v22 > fld)
      break;
    if (v22 == fld && (v21->idx1 == tbl_idx || v21->idx2 == tbl_idx))
    {
      v23 = NewSpecific(object, 0xEu);
      v23->m_Items[0] = "SKY環境ライト  gSkyTbl[";
      v69 = tbl_idx;
      v25 = sub_8D3950(s32, &v69);
      v26 = v25;
      v23->m_Items[1] = v26;
      v23->m_Items[2] = "]  Light : ";
      v31 = sub_4FDC70(l0_r, "f02");
      v32 = v31;
      v23->m_Items[3] = v32;
      v23->m_Items[4] = "  ";
      v37 = sub_4FDC70(l0_g, "f02");
      v38 = v37;
      v23->m_Items[5] = v38;
      v23->m_Items[6] = "  ";
      v43 = sub_4FDC70(l0_b, "f02");
      v44 = v43;
      v23->m_Items[7] = v44;
      v23->m_Items[8] = " Amb : ";
      v49 = sub_4FDC70(a0_r, "f02");
      v50 = v49;
      v23->m_Items[9] = v50;
      v23->m_Items[10] = "  ";
      v55 = sub_4FDC70(a0_g, "f02");
      v56 = v55;
      v23->m_Items[11] = v56;
      v23->m_Items[12] = "  ";
      v61 = sub_4FDC70(a0_b, "f02");
      v62 = v61;
      v23->m_Items[13] = v62;
      v66 = Concat_5270224(v23);
      Log(v66, 0);
      if (v21->lzero == 1)
      {
        *&v21->m_lr = 0;
        v21->m_lb = 0.0;
      }
      if (v21->azero == 1)
      {
        *&v21->m_ar = 0;
        v21->m_ab = 0.0;
      }
      *l0_r = *l0_r * v21->m_lr;
      *l0_g = *l0_g * v21->m_lg;
      *l0_b = *l0_b * v21->m_lb;
      *l0_r = *l0_r + v21->a_lr;
      *l0_g = *l0_g + v21->a_lg;
      *l0_b = *l0_b + v21->a_lb;
      *a0_r = *a0_r * v21->m_ar;
      *a0_g = *a0_g * v21->m_ag;
      *a0_b = *a0_b * v21->m_ab;
      *a0_r = *a0_r + v21->a_ar;
      *a0_g = *a0_g + v21->a_ag;
      *a0_b = *a0_b + v21->a_ab;
      return;
    }
    ++v16;
      goto LABEL_6;
  }
}

// 0x1807370
void SceneLight_Char_Color(char *objname, evtUnitHandle_t *hunit, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim) {
  System_String_o *NowName_SCR_RUN;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  System_String_o *EventCamName;
  System_String_o *v29;
  System_String_o *v31;
  System_String_o *v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  System_String_o *v52;
  bool v53;
  f32 v54;
  System_String_o *v56;
  bool v57;
  f32 v58;
  System_String_o *NowCameraName;
  s32 v62;
  System_String_o *v65;
  f32 v67;
  s64 v71;
  s32 v72;
  f32 *v73;

  v73 = v0_z;
  if (op_Equality(objname, "npc_yuuko_e601", 0))
  {
    *soften = 15.0;
    *bias = -0.2;
    *l0_r = *l0_r * 0.8;
    *l0_g = *l0_g * 0.8;
    *l0_b = *l0_b * 0.8;
    *a0_r = *a0_r * 0.7;
    *a0_g = *a0_g * 0.7;
    *a0_b = *a0_b * 0.7;
  }
  if (op_Equality(objname, "npc_hikawa_e634", 0))
  {
    NowName_SCR_RUN = GetNowName_SCR_RUN();
    if (op_Equality(NowName_SCR_RUN, "e634_080", 0)
      || op_Equality(NowName_SCR_RUN, "e634_010_10", 0))
    {
      *soften = 5.0;
      *bias = -0.065;
      v23 = *l0_r;
      v24 = *l0_g;
      v25 = *l0_b;
      *l0_r = *a0_r * 1.4;
      *l0_g = *a0_g * 1.4;
      *l0_b = *a0_b * 1.4;
      *a0_r = v23 * 0.7;
      *a0_g = v24 * 0.7;
      *a0_b = v25 * 0.7;
      *v0_x = -*v0_x;
      *v0_y = -*v0_y;
      *v73 = -*v73;
      *l0_b = *l0_b + 0.2;
      v26 = *a0_b + 0.2;
    }
    else
    {
      EventCamName = GetEventCamName();
      if (op_Equality(EventCamName, "cam05", 0))
        goto LABEL_20;
      v29 = GetEventCamName();
      if (op_Equality(v29, "cam07", 0))
      {
LABEL_20:
        *soften = 15.0;
        *bias = 0.0;
        *l0_r = *l0_r * 0.9;
        *l0_g = *l0_g * 0.9;
        *l0_r = *l0_r + 0.0;
        *l0_g = *l0_g + 0.1;
        *l0_b = *l0_b + 0.2;
        *a0_r = *a0_r * 1.5;
        *a0_g = *a0_g * 1.5;
      }
      else
      {
        *soften = 15.0;
        *bias = 0.04;
        *l0_r = *l0_r * 1.2;
        *l0_g = *l0_g * 1.2;
        *l0_b = *l0_b * 1.2;
        *a0_r = *a0_r * 1.2;
        *a0_g = *a0_g * 1.2;
      }
      v26 = *a0_b * 1.9;
    }
    *a0_b = v26;
  }
  if (op_Equality(objname, "f634_maga", 0))
  {
    *soften = 0.0;
    *l0_r = *l0_r * 0.8;
    *l0_g = *l0_g * 0.8;
    *l0_b = *l0_b * 0.8;
    *a0_r = *a0_r * 0.8;
    *a0_g = *a0_g * 0.8;
    *a0_b = *a0_b * 0.8;
  }
  if (op_Equality(objname, "devil_0x47_e634_0", 0))
  {
    v31 = GetEventCamName();
    if (op_Equality(v31, "cam13", 0))
      goto LABEL_35;
    v33 = GetEventCamName();
    if (op_Equality(v33, "cam15", 0))
    {
LABEL_35:
      *soften = 5.0;
      *bias = 0.2;
      *l0_r = *l0_r * 1.4;
      *l0_g = *l0_g * 1.2;
      *l0_b = *l0_b * 1.4;
      *a0_r = *a0_r * 1.4;
      *a0_g = *a0_g * 0.8;
      v34 = *a0_b * 0.9;
    }
    else
    {
      *soften = 5.0;
      *bias = 0.0;
      v35 = *l0_r;
      v36 = *l0_g;
      v37 = *l0_b;
      *l0_r = *a0_r * 1.4;
      *l0_g = *a0_g * 1.4;
      *l0_b = *a0_b * 1.4;
      *a0_r = v35 * 0.7;
      *a0_g = v36 * 0.7;
      *a0_b = v37 * 0.7;
      *v0_x = -*v0_x;
      *v0_y = -*v0_y;
      *v73 = -*v73;
      *l0_b = *l0_b + 0.3;
      v34 = *a0_b + 0.3;
    }
    *a0_b = v34;
  }
  if (op_Equality(objname, "e635_tukue", 0))
  {
    v38 = (*l0_r + *a0_r) * 0.5;
    *a0_r = v38;
    *l0_r = v38;
    v39 = (*l0_g + *a0_g) * 0.5;
    *a0_g = v39;
    *l0_g = v39;
    v40 = (*l0_b + *a0_b) * 0.5;
    *a0_b = v40;
    *l0_b = v40;
    *div = 0.0;
    *rim = 29.0;
    return;
  }
  if (op_Equality(objname, "e634_sinen_a", 0)
    || op_Equality(objname, "e634_sinen_b", 0)
    || op_Equality(objname, "e634_sinen_c", 0)
    || op_Equality(objname, "e634_sinen_d", 0))
  {
    *bias = -0.8;
    return;
  }
  if (op_Equality(objname, "npc_extra01", 0))
  {
    *soften = 0.0;
    *bias = 0.25;
    *l0_r = *l0_r * 1.45;
    *l0_g = *l0_g * 1.4;
    *l0_b = *l0_b * 1.5;
    *a0_r = *a0_r * 1.1;
    v42 = 0.5;
    *a0_b = *a0_b * 1.1;
    *v0_x = 1.0;
    *v0_y = -0.2;
    *v73 = 0.5;
    v72 = 0;
    v71 = 0;
    sub_8524C0(&v71, *v0_x, *v0_y, v42);
    sub_8531D0(&v71, 0);
    *v0_x = v71;
    *v0_y = *(&v71 + 1);
    *v73 = v72;
    return;
  }
  if (op_Equality(objname, "kage_e661", 0))
  {
    *soften = 0.0;
    *bias = 0.0;
    *l0_r = *l0_r * 0.0;
    *l0_g = *l0_g * 0.0;
    *l0_b = *l0_b * 0.0;
    *a0_r = *a0_r * 0.0;
    *a0_g = *a0_g * 0.0;
    *a0_b = *a0_b * 0.0;
  }
  if (op_Equality(objname, "npc_tiaki_e661", 0))
  {
    *soften = 5.001;
    *bias = -0.2;
    *l0_r = *l0_r * 1.7;
    *l0_g = *l0_g * 1.7;
    *l0_b = *l0_b * 1.7;
    *l0_r = *l0_r + 0.05;
    *l0_g = *l0_g + 0.15;
    *l0_b = *l0_b + 0.15;
    *a0_r = *a0_r * 1.3;
    *a0_g = *a0_g * 1.3;
    *a0_b = *a0_b * 1.3;
    v43 = *a0_r + 0.1;
    v44 = 0.0;
LABEL_55:
    *a0_r = v43;
    v45 = *a0_g + v44;
LABEL_56:
    *a0_g = v45;
    *a0_b = *a0_b + v44;
    return;
  }
  if (op_Equality(objname, "npc_tiaki_e661_010", 0))
  {
    *soften = 5.001;
    *bias = -0.2;
    *l0_r = *l0_r * 1.7;
    *l0_g = *l0_g * 1.5;
    *l0_b = *l0_b * 1.5;
    *l0_r = *l0_r + 0.2;
    *l0_g = *l0_g + 0.0;
    *l0_b = *l0_b + 0.1;
    *a0_r = *a0_r * 1.1;
    return;
  }
  if (op_Equality(objname, "devil_0x120_e679_0", 0))
  {
    *soften = 5.001;
    *bias = -0.1;
    *l0_r = *l0_r * 1.6;
    *l0_g = *l0_g * 1.6;
    *l0_b = *l0_b * 1.6;
    *l0_r = *l0_r + 0.0;
    *l0_g = *l0_g + 0.0;
    v46 = 1.2;
    *l0_b = *l0_b + 0.1;
LABEL_67:
    *a0_b = *a0_b * v46;
    return;
  }
  if (op_Equality(objname, "devil_0x124_e680_001_0", 0))
  {
    *soften = 5.001;
    *bias = 0.4;
    *l0_g = *l0_g * 1.2;
    *l0_b = *l0_b * 1.3;
    *a0_r = *a0_r * 0.8;
    *a0_g = *a0_g * 0.8;
    *a0_b = *a0_b * 0.8;
    return;
  }
  if (op_Equality(objname, "npc_isamu_e680", 0))
  {
    *soften = 15.001;
    *bias = 0.0;
    *l0_r = *l0_r * 1.4;
    *l0_g = *l0_g * 1.4;
    v47 = *l0_b * 1.4;
LABEL_65:
    *l0_b = v47;
    v48 = *a0_r;
    v46 = 1.2;
LABEL_66:
    *a0_r = v48 * v46;
    *a0_g = *a0_g * v46;
    goto LABEL_67;
  }
  if (op_Equality(objname, "devil_0x123_e681_0", 0))
  {
    *soften = 15.001;
    *bias = -0.07;
    *l0_r = *l0_r * 1.3;
    *l0_g = *l0_g * 1.3;
    *l0_b = *l0_b * 1.4;
    *a0_r = *a0_r * 1.3;
    *a0_g = *a0_g * 1.3;
    *a0_b = *a0_b * 1.4;
    return;
  }
  if (op_Equality(objname, "e681_bigtubeB", 0)
    || op_Equality(objname, "e681_bigtubeC", 0))
  {
    *soften = 15.001;
    *bias = -0.07;
    *l0_r = *l0_r * 1.3;
    *l0_g = *l0_g * 1.3;
    *l0_b = *l0_b * 1.4;
    *a0_r = *a0_r * 1.3;
    *a0_g = *a0_g * 1.3;
    *a0_b = *a0_b * 1.4;
  }
  if (op_Equality(objname, "player_first_e693_010", 0)
    || op_Equality(objname, "player_first2_e693_010", 0))
  {
    *soften = 5.001;
    *bias = -0.05;
    *l0_r = *l0_r * 1.7;
    *l0_g = *l0_g * 1.7;
    *l0_b = *l0_b * 1.7;
    *a0_r = *a0_r * 1.2;
    *a0_g = *a0_g * 1.2;
    *a0_b = *a0_b * 1.1;
    *a0_r = *a0_r + 0.1;
    v45 = *a0_g + 0.1;
    v44 = 0.0;
    goto LABEL_56;
  }
  if (op_Equality(objname, "npc_isamu_e693_010", 0))
  {
    *soften = 5.001;
    *bias = -0.1;
    *l0_r = *l0_r * 1.6;
    *l0_g = *l0_g * 1.6;
    *l0_b = *l0_b * 1.6;
    *l0_r = *l0_r + 0.1;
    *l0_g = *l0_g + 0.1;
    *l0_b = *l0_b + 0.1;
    *a0_r = *a0_r * 1.4;
    v49 = *a0_g * 1.4;
    v50 = 1.3;
LABEL_80:
    *a0_g = v49;
    *a0_b = *a0_b * v50;
    v44 = 0.2;
LABEL_81:
    v43 = *a0_r + 0.2;
    goto LABEL_55;
  }
  if (op_Equality(objname, "npc_hijiri_e693_030", 0))
  {
    *soften = 15.001;
    *bias = 0.0;
    *l0_r = *l0_r * 1.1;
    *l0_g = *l0_g * 1.1;
    v50 = 1.2;
    *l0_b = *l0_b * 1.1;
    *a0_r = *a0_r * 1.2;
    v49 = *a0_g * 1.2;
    goto LABEL_80;
  }
  if (op_Equality(objname, "npc_tiaki_e693_040", 0)
    || op_Equality(objname, "npc_isamu_e693_040", 0))
  {
    *soften = 0.001;
    *bias = 0.0;
    *l0_r = *l0_r * 1.3;
    *l0_g = *l0_g * 1.3;
    *l0_b = *l0_b * 1.3;
    *l0_r = *l0_r + 0.1;
    *l0_g = *l0_g + 0.1;
    v47 = *l0_b + 0.1;
    goto LABEL_65;
  }
  if (op_Equality(objname, "player_first_e693_040", 0)
    || op_Equality(objname, "player_first2_e693_040", 0))
  {
    *soften = 15.001;
    *bias = 0.0;
    *l0_r = *l0_r * 1.3;
    *l0_g = *l0_g * 1.3;
    v46 = 1.1;
    *l0_b = *l0_b * 1.3;
    v48 = *a0_r;
    goto LABEL_66;
  }
  if (op_Equality(objname, "npc_luci_e694", 0))
  {
    *soften = 15.0;
    v52 = GetEventCamName();
    v53 = op_Equality(v52, "cam02", 0);
    v54 = -0.39;
    if (!v53)
      v54 = 0.1;
    *bias = v54;
    *l0_r = *l0_r * 1.5;
    *l0_g = *l0_g * 1.5;
    *l0_b = *l0_b * 1.8;
    *l0_r = *l0_r + 0.1;
    *l0_g = *l0_g + 0.1;
    *l0_b = *l0_b + 0.1;
    *a0_r = *a0_r * 1.3;
    *a0_g = *a0_g * 1.3;
    *a0_b = *a0_b * 1.5;
LABEL_102:
    *a0_r = *a0_r + 0.2;
    v45 = *a0_g + 0.2;
    v44 = 0.3;
    goto LABEL_56;
  }
  if (op_Equality(objname, "npc_gomo_e694", 0))
  {
    *soften = 15.0;
    v56 = GetEventCamName();
    v57 = op_Equality(v56, "cam02", 0);
    v58 = 0.1;
    if (v57)
      v58 = -0.39;
    *bias = v58;
    *l0_r = *l0_r * 1.5;
    *l0_g = *l0_g * 1.5;
    *l0_b = *l0_b * 1.8;
    *a0_b = *a0_b * 1.4;
    goto LABEL_102;
  }
  if (op_Equality(objname, "player_tatoo_e676_010", 0))
  {
    *soften = 15.0;
    *bias = -0.49;
    *l0_r = *l0_r * 1.4;
    *l0_g = *l0_g * 1.4;
    v44 = 0.2;
    *l0_b = *l0_b * 1.4;
    *l0_r = *l0_r + 0.2;
    *l0_g = *l0_g + 0.2;
    *l0_b = *l0_b + 0.2;
    *a0_r = *a0_r * 1.5;
    *a0_g = *a0_g * 1.5;
    *a0_b = *a0_b * 1.5;
    goto LABEL_81;
  }
  if (op_Equality(objname, "mani_e615", 0))
  {
    *v0_x = 0.0036631;
    *v0_y = -0.005136;
    *v73 = 0.0;
  }
  if (op_Equality(objname, "dante_e723_010", 0))
  {
    NowCameraName = GetNowCameraName();
    v62 = 1101529612;
    if (!op_Equality(NowCameraName, "Camera01", 0)
      && !op_Equality(NowCameraName, "Camera014", 0)
      && !op_Equality(NowCameraName, "Camera015", 0))
    {
      if (!op_Equality(NowCameraName, "Camera02", 0))
        goto LABEL_117;
      v62 = 1102053900;
    }
    *soften = v62;
LABEL_117:
    *bias = sdfFaceDivBias * -1.1;
    *l0_r = *l0_r * 1.5;
    *l0_g = *l0_g * 1.4;
    *l0_b = *l0_b * 1.4;
    *a0_r = *a0_r * 1.2;
    *a0_g = *a0_g * 1.2;
    *a0_b = *a0_b * 1.2;
  }
  if (op_Equality(objname, "dante_e723_020", 0))
  {
    v65 = GetNowCameraName();
    if (op_Equality(v65, "Camera01", 0))
    {
      *soften = 23.0;
      *l0_r = *l0_r * 1.4;
      *l0_g = *l0_g * 1.4;
      *l0_b = *l0_b * 1.4;
      *a0_r = *a0_r * 0.0;
      *a0_g = *a0_g * 0.0;
      v67 = *a0_b * 0.0;
    }
    else
    {
      *soften = 22.0;
      *l0_r = *l0_r * 1.2;
      *a0_r = *a0_r * 1.2;
      v67 = *a0_b;
    }
    *a0_b = v67;
    *bias = sdfFaceDivBias * -0.5;
  }
}

// 0x1805b00
void SceneLight_Char_SetUp(char *objname) {
  SpHokanMode = 0;
  SpHokan2Mode = 0;
}

// 0x1005530
void SetEventNo(s32 event_no) {
  if (event_no <= 698)
  {
    if (event_no == 676)
    {
      event_no = 703;
      goto LABEL_16;
    }
    if (event_no != 693)
      return;
LABEL_9:
LABEL_16:
    evtUpdateEx_NowEveNo = event_no;
    return;
  }
  if (event_no == 699 || event_no == 723)
    goto LABEL_9;
}

// 0x18056d0
void SpHokan2_ColorVec(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow) {
  dds3UnityEx_Light_c *v20;
  s32 v21;
  f32 v23;
  f32 v24;
  s64 v25;
  s32 v26;

  {
    else
    {
      if (SpHokan2Mode)
        goto LABEL_5;
    }
LABEL_13:
    SpHokan2Mode = 1;
    v24 = *l0_r;
    if ((v20->_2.bitflags2 & 2) != 0)
      goto LABEL_9;
    goto LABEL_17;
  }
  v21 = 0;
  if (!SpHokan2Mode)
    goto LABEL_13;
LABEL_5:
  *l0_r = (SpHokan2_l0_r * hokanpow) + ((1.0 - hokanpow) * *l0_r);
  *l0_g = (SpHokan2_l0_g * hokanpow) + ((1.0 - hokanpow) * *l0_g);
  *l0_b = (SpHokan2_l0_b * hokanpow) + ((1.0 - hokanpow) * *l0_b);
  *a0_r = (SpHokan2_a0_r * hokanpow) + ((1.0 - hokanpow) * *a0_r);
  *a0_g = (SpHokan2_a0_g * hokanpow) + ((1.0 - hokanpow) * *a0_g);
  *a0_b = (SpHokan2_a0_b * hokanpow) + ((1.0 - hokanpow) * *a0_b);
  v26 = 0;
  v25 = 0;
  sub_8524C0(&v25, *v0_x, *v0_y, *v0_z);
  sub_8531D0(&v25, 0);
  *v0_x = v25;
  *v0_y = *(&v25 + 1);
  *v0_z = v26;
  *v0_x = (SpHokan2_v0_x * hokanpow) + ((1.0 - hokanpow) * *v0_x);
  *v0_y = (SpHokan2_v0_y * hokanpow) + ((1.0 - hokanpow) * *v0_y);
  v23 = (SpHokan2_v0_z * hokanpow) + ((1.0 - hokanpow) * *v0_z);
  *v0_z = v23;
  v26 = 0;
  v25 = 0;
  sub_8524C0(&v25, *v0_x, *v0_y, v23);
  sub_8531D0(&v25, 0);
  *v0_x = v25;
  *v0_y = *(&v25 + 1);
  *v0_z = v26;
  v24 = *l0_r;
  {
LABEL_9:
  }
LABEL_17:
  SpHokan2_l0_r = v24;
  SpHokan2_l0_g = *l0_g;
  SpHokan2_l0_b = *l0_b;
  SpHokan2_a0_r = *a0_r;
  SpHokan2_a0_g = *a0_g;
  SpHokan2_a0_b = *a0_b;
  SpHokan2_v0_x = *v0_x;
  SpHokan2_v0_y = *v0_y;
  SpHokan2_v0_z = *v0_z;
}

// 0x1805120
void SpHokan_Color(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow) {
  dds3UnityEx_Light_c *v15;
  s32 v16;
  f32 v18;

  {
    else
    {
      if (SpHokanMode)
        goto LABEL_5;
    }
LABEL_13:
    SpHokanMode = 1;
    v18 = *l0_r;
    if ((v15->_2.bitflags2 & 2) != 0)
      goto LABEL_9;
    goto LABEL_17;
  }
  v16 = 0;
  if (!SpHokanMode)
    goto LABEL_13;
LABEL_5:
  *l0_r = (SpHokan_l0_r * hokanpow) + ((1.0 - hokanpow) * *l0_r);
  *l0_g = (SpHokan_l0_g * hokanpow) + ((1.0 - hokanpow) * *l0_g);
  *l0_b = (SpHokan_l0_b * hokanpow) + ((1.0 - hokanpow) * *l0_b);
  *a0_r = (SpHokan_a0_r * hokanpow) + ((1.0 - hokanpow) * *a0_r);
  *a0_g = (SpHokan_a0_g * hokanpow) + ((1.0 - hokanpow) * *a0_g);
  *a0_b = (SpHokan_a0_b * hokanpow) + ((1.0 - hokanpow) * *a0_b);
  v18 = *l0_r;
  {
LABEL_9:
  }
LABEL_17:
  SpHokan_l0_r = v18;
  SpHokan_l0_g = *l0_g;
  SpHokan_l0_b = *l0_b;
  SpHokan_a0_r = *a0_r;
  SpHokan_a0_g = *a0_g;
  SpHokan_a0_b = *a0_b;
}

// 0x1805360
void SpHokan_ColorVec(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow) {
  dds3UnityEx_Light_c *v20;
  s32 v21;
  f32 v23;
  f32 v24;
  s64 v25;
  s32 v26;

  {
    else
    {
      if (SpHokanMode)
        goto LABEL_5;
    }
LABEL_13:
    SpHokanMode = 1;
    v24 = *l0_r;
    if ((v20->_2.bitflags2 & 2) != 0)
      goto LABEL_9;
    goto LABEL_17;
  }
  v21 = 0;
  if (!SpHokanMode)
    goto LABEL_13;
LABEL_5:
  *l0_r = (SpHokan_l0_r * hokanpow) + ((1.0 - hokanpow) * *l0_r);
  *l0_g = (SpHokan_l0_g * hokanpow) + ((1.0 - hokanpow) * *l0_g);
  *l0_b = (SpHokan_l0_b * hokanpow) + ((1.0 - hokanpow) * *l0_b);
  *a0_r = (SpHokan_a0_r * hokanpow) + ((1.0 - hokanpow) * *a0_r);
  *a0_g = (SpHokan_a0_g * hokanpow) + ((1.0 - hokanpow) * *a0_g);
  *a0_b = (SpHokan_a0_b * hokanpow) + ((1.0 - hokanpow) * *a0_b);
  v26 = 0;
  v25 = 0;
  sub_8524C0(&v25, *v0_x, *v0_y, *v0_z);
  sub_8531D0(&v25, 0);
  *v0_x = v25;
  *v0_y = *(&v25 + 1);
  *v0_z = v26;
  *v0_x = (SpHokan_v0_x * hokanpow) + ((1.0 - hokanpow) * *v0_x);
  *v0_y = (SpHokan_v0_y * hokanpow) + ((1.0 - hokanpow) * *v0_y);
  v23 = (SpHokan_v0_z * hokanpow) + ((1.0 - hokanpow) * *v0_z);
  *v0_z = v23;
  v26 = 0;
  v25 = 0;
  sub_8524C0(&v25, *v0_x, *v0_y, v23);
  sub_8531D0(&v25, 0);
  *v0_x = v25;
  *v0_y = *(&v25 + 1);
  *v0_z = v26;
  v24 = *l0_r;
  {
LABEL_9:
  }
LABEL_17:
  SpHokan_l0_r = v24;
  SpHokan_l0_g = *l0_g;
  SpHokan_l0_b = *l0_b;
  SpHokan_a0_r = *a0_r;
  SpHokan_a0_g = *a0_g;
  SpHokan_a0_b = *a0_b;
  SpHokan_v0_x = *v0_x;
  SpHokan_v0_y = *v0_y;
  SpHokan_v0_z = *v0_z;
}

// 0x100d4e0
s32 UnityEx_GetPM_NowFrame(void) {
  return Ex_NowFrame;
}

// 0x100d550
void UnityEx_SetPM_NowCamera(void) {
  s32 evtUpdateEx_NowEveNo;

  if (evtUpdateEx_NowEveNo == 693)
    goto LABEL_12;
LABEL_6:
  if (evtUpdateEx_NowEveNo == 703)
    goto LABEL_12;
}

// 0x100f2c0
void btlEve_BloomDof_Set(s32 btleve_no) {
  if (btleve_no == 913)
  {
    PPSV2_update = 1;
    PPSV2_bloom_type = 913;
    DofOff();
  }
}

// 0x100cf00
void *evtPolygonMovieUpdateEx_Unity(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  pmdProcessWork_t_o *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 NowFrame;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Component_o *v15;
  bool v16;
  UnityEngine_Transform_o *transform;
  s64 *v18;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v22;
  bool v23;
  UnityEngine_GameObject_o *v24;
  s32 v29;
  dds3ProcessID_t_o *v35[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdProcessWork_t)
    {
      sub_8FC2C0(klass->_1.element_class, pmdProcessWork_t, v35);
      if ((v35[0] & 1) != 0)
        v7 = v35[2];
      else
        v7 = v35 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  else if (!CheckLoad(ProcessData, 0))
  {
    return 0;
  }
  if ((v4->flag & 9) != 8)
    return 0;
  NowFrame = v4->NowFrame;
  Ex_NowFrame = NowFrame;
  if (evtUpdateEx_NowEveNo == 693)
  {
    v13 = Find("Character", 0);
    v15 = 0;
    if (op_Inequality(v13, 0, 0))
    {
      v16 = evtBitCheck(2224);
      transform = get_transform(v13, 0);
      v18 = &"player_first_e693_010";
      if (!v16)
        v18 = &"player_first2_e693_010";
      v15 = Find(transform, *v18, 0);
    }
    if (op_Equality(evtUpdateEx_Camname, "cam01", 0))
    {
      if (op_Inequality(v15, 0, 0))
      {
        gameObject = get_gameObject(v15);
        if (get_activeSelf(gameObject))
        {
          v22 = get_gameObject(v15);
          v23 = 0;
LABEL_46:
          SetActive(v22, v23, 0);
        }
      }
    }
    else
    {
      if (op_Inequality(v15, 0, 0))
      {
        v24 = get_gameObject(v15);
        if (!get_activeSelf(v24))
        {
          v22 = get_gameObject(v15);
          v23 = 1;
          goto LABEL_46;
        }
      }
    }
  }
  if (!evtBitCheck(3712))
    return 0;
  if (op_Equality(evtUpdateEx_FieldName, "f723_010(Clone)", 0))
  {
    PShadow_YClipOnOff = 0.0;
    v29 = v4->NowFrame;
    if (v29 > 59)
    {
      if (v29 > 149)
      {
        PShadow_OnOff = 0.0;
        return 0;
      }
      PShadow_CamX = 2.0;
      PShadow_CamY = 7.0;
      PShadow_CamZ = 57.0;
      PShadow_RotX = 70.0;
      PShadow_RotY = 270.0;
      PShadow_CamSize = 2.5;
      PShadow_CamFar = 10.0;
      PShadow_Alp = 0.3;
LABEL_77:
      PShadow_OnOff = 1.0;
      return 0;
    }
    PShadow_CamX = 2.0;
    PShadow_CamY = 7.0;
    PShadow_CamZ = 54.0;
    PShadow_RotX = 70.0;
    PShadow_RotY = 270.0;
    PShadow_CamSize = 2.5;
    PShadow_CamFar = 10.0;
    PShadow_Alp = 0.3;
    PShadow_OnOff = 1.0;
    PShadow_VecClipOnOff = 0.0;
    PShadow_YClipOnOff = 1.0;
  }
  else
  {
    if (op_Equality(evtUpdateEx_FieldName, "f723_030(Clone)", 0))
    {
      PShadow_CamX = 0.0;
      PShadow_CamY = 8.0;
      PShadow_CamZ = 56.5;
      PShadow_RotX = 70.0;
      PShadow_RotY = 270.0;
      PShadow_CamSize = 1.0;
      PShadow_CamFar = 10.0;
      PShadow_Alp = 0.2;
      goto LABEL_77;
    }
  }
  return 0;
}

// 0x10056e0
void *evtShutdownEx_Unity(dds3ProcessID_t *id) {
  Set_EventMode(0);
  return 0;
}

// 0x10054a0
void evtUpdateEx_BGM_FADEOUT_E_After(s32 eid, s32 bgmid) {
  if (eid == 659 && bgmid == 2)
  {
    e659_Ara_Out = 1;
  }
}

// 0x10042f0
void evtUpdateEx_CharLoadAfter(FieldChrHD *fHD, void *rootobj, dds3Basic_t *unit, char *mname) {
  System_String_o *v8;
  System_Object_array *v10;

  v8 = Concat_5224608("■■■■イベントの特殊処理 キャラモデルロード直後: ", mname);
  v10 = Empty_string_();
  Log(v8, v10, 0);
  if (op_Equality(mname, "npc_tiaki_e605", 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, "e615_door", 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, "mani_e619", 0)
    || op_Equality(mname, "mani_e623", 0)
    || op_Equality(mname, "mani_e632", 0)
    || op_Equality(mname, "mani_e639", 0)
    || op_Equality(mname, "mani_e646", 0)
    || op_Equality(mname, "mani_e652", 0)
    || op_Equality(mname, "mani_e662", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "f634_maga", 0)
    || op_Equality(mname, "f634_manineji", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "e644_d_mane", 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, "e651_hikari", 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, "e655_field", 0)
    || op_Equality(mname, "e655_field2", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "f659_kage", 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, "kage_e661", 0)
    || op_Equality(mname, "kourin", 0)
    || op_Equality(mname, "gozhead_e661", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "f673_rock1", 0)
    || op_Equality(mname, "f673_rock2", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "npc_tiaki_e684", 0)
    || op_Equality(mname, "npc_tiaki_e684_010", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "devil_0x123_e681_0", 0)
    || op_Equality(mname, "e681_bigtube", 0)
    || op_Equality(mname, "e681_bigtubeD", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "e697_field01", 0)
    || op_Equality(mname, "e697_field02", 0)
    || op_Equality(mname, "mani_e697", 0)
    || op_Equality(mname, "mani_6970", 0)
    || op_Equality(mname, "mani_6976", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "player_tatoo_e699_005", 0))
  {
    Postblur_AccumTex_NowMode = 1;
  }
  if (op_Equality(mname, "flash_e726", 0)
    || op_Equality(mname, "shadow_l_e726", 0)
    || op_Equality(mname, "shadow_l_e726_4", 0)
    || op_Equality(mname, "shadow_o_e726", 0)
    || op_Equality(mname, "npc_luci_e726", 0)
    || op_Equality(mname, "npc_luci_old_e726", 0)
    || op_Equality(mname, "npc_gomo_e726", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "e728_door", 0)
    || op_Equality(mname, "hole_e728", 0)
    || op_Equality(mname, "misya_e728", 0)
    || op_Equality(mname, "e728_door_m", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "e730_door", 0)
    || op_Equality(mname, "shadow_e730", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "raidou_e731", 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, "speed_line_e741", 0)
    || op_Equality(mname, "devil_0x15e/devil_0x15e_e741", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, "circle_n_e800", 0)
    || op_Equality(mname, "circle_c_e800", 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
}

// 0x10053e0
void evtUpdateEx_FLD_MSE_After(s32 seid) {
  struct fldGlobalWork_t_o *fldGb;

  if (fldGb->fieldID == 37 && seid == 76 && fldGb->areaID == 6)
  {
    evtUpdateEx_ArkOpen_F037_07_THOR_AFTER_Dead = 1;
  }
}

// 0x1004ae0
void evtUpdateEx_FieldLoadAfter(FieldBgHD *fobj, void *rootobj, char *mname) {
  System_String_o *v5;
  System_Object_array *v7;
  UnityEngine_GameObject_o *v11;
  s32 v14;

  v5 = Concat_5224608("■■■■イベントの特殊処理 背景モデルロード直後: ", mname);
  v7 = Empty_string_();
  Log(v5, v7, 0);
  evtUpdateEx_FieldName = mname;
  if (op_Equality(mname, "f621_001(Clone)", 0))
  {
    v11 = Find("Plane12", 0);
    if (op_Inequality(v11, 0, 0))
      SetActive(v11, 0, 0);
    return;
  }
  if (op_Equality(mname, "f693_010(Clone)", 0))
  {
    Set_EventMode(1);
    Set_EventID(693);
  }
  if (op_Equality(mname, "f634_070(Clone)", 0))
  {
    Set_EventMode(1);
    v14 = 634;
    goto LABEL_35;
  }
  if (op_Equality(mname, "f676_030(Clone)", 0))
  {
    Set_EventMode(1);
    v14 = 703;
    goto LABEL_35;
  }
  if (op_Equality(mname, "f693_020(Clone)", 0))
  {
    Set_EventMode(1);
    v14 = 693;
    goto LABEL_35;
  }
  if (op_Equality(mname, "f693_040(Clone)", 0))
  {
    PShadow_CamX = -47.4;
    PShadow_CamY = 3.0;
    PShadow_CamZ = -2.0;
    PShadow_RotX = 80.0;
    PShadow_RotY = 180.0;
    PShadow_CamSize = 3.9;
    PShadow_Alp = 0.3;
    PShadow_OnOff = 1.0;
    PShadow_ClipY = 0.0;
    Set_EventMode(0);
  }
  else
  {
    if (!op_Equality(mname, "f699_005(Clone)", 0))
    {
      if (!op_Equality(mname, "f723_010(Clone)", 0)
        && !op_Equality(mname, "f723_020(Clone)", 0)
        && !op_Equality(mname, "f723_030(Clone)", 0)
        || !evtBitCheck(3712))
      {
        return;
      }
      Set_EventMode(1);
      v14 = 723;
LABEL_35:
      Set_EventID(v14);
      return;
    }
    Set_EventMode(1);
    Set_EventID(699);
    PPSV2_update = 1;
    PPSV2_bloom_type = 705;
    DofOff();
  }
}

// 0x1004fc0
void evtUpdateEx_SE_E_After(s32 eid, s32 seid) {
  System_String_o *v4;
  System_String_o *v5;
  System_Object_array *v7;
  s16 v10;
  s32 v11;
  s32 evtUpdateEx_NowEveNo;
  s32 v14;
  s64 *v15;
  s32 v16;

  v16 = seid;
  v4 = sub_232A70(&v16, "X08");
  v5 = Concat_5224608("■■■■イベントの特殊処理 イベントＳＥ呼び出し直後: ", v4);
  v7 = Empty_string_();
  Log(v5, v7, 0);
  if ((v10 & 0x200) != 0)
  {
    v11 = v10 & 0x200;
  }
  else
  {
    v11 = 0;
  }
  v14 = v16;
  if (eid == 674 && evtUpdateEx_NowEveNo == 674 && v16 == 109)
  {
    evtUpdateEx_ArkOpen_e674after = 1;
    return;
  }
  if (eid == 710 && evtUpdateEx_NowEveNo == 710 && v14 == 108)
  {
    v15 = &"E110_SE71";
LABEL_78:
    p2sdPlaySE_20173184(*v15);
    return;
  }
  if (eid == 711 && evtUpdateEx_NowEveNo == 711 && v14 == 111)
  {
    v15 = &"E111_SE71";
    goto LABEL_78;
  }
  if (eid == 712 && evtUpdateEx_NowEveNo == 712 && v14 == 111)
  {
    v15 = &"E112_SE71";
    goto LABEL_78;
  }
  if (eid == 713 && evtUpdateEx_NowEveNo == 713 && v14 == 111)
  {
    v15 = &"E113_SE71";
    goto LABEL_78;
  }
  if (eid == 714 && evtUpdateEx_NowEveNo == 714 && v14 == 111)
  {
    v15 = &"E114_SE71";
    goto LABEL_78;
  }
  if (eid == 715 && evtUpdateEx_NowEveNo == 715 && v14 == 111)
  {
    v15 = &"E115_SE71";
    goto LABEL_78;
  }
  if (eid == 731 && v14 == 1000)
  {
    PlayVoice("E731_L0000m_ADD_F");
  }
}

// 0x18029c0
void evtUpdateEx_UnitLightColorAfter(evtUnitHandle_t **hunit) {
  struct dds3Basic_t_o *Owner;
  System_String_o *name;
  evtUnitHandle_t_o *v5;

  if (*hunit)
  {
    Owner = (*hunit)->Owner;
    if (Owner)
    {
      name = Owner->name;
      if (name)
      {
        if (op_Equality(name, "f615_bafo_060", 0)
          || op_Equality(name, "f615_bafo", 0))
        {
          SDF_VU0__dds3ColorItoF((*hunit)->NowLightRGB, 0);
          SDF_VU0__SCALEVECTOR(0.2);
          SDF_VU0__VECTOR_W_SET_ZERO();
          v5 = *hunit;
          v5->NowLightRGB = SDF_VU0__dds3ColorFtoI(128.0);
        }
      }
    }
  }
}

// 0x1005750
void *evtUpdateEx_Unity(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  s32 v16;
  s32 *v17;
  s32 v18;
  dds3Basic_t_o *ActiveCameraSceneBasic;
  System_String_o *name;
  dds3Basic_t_o *v24;
  s32 v26;
  bool v30;
  struct dds3Basic_t_o *evtUpdateEx_old_camera;
  struct dds3PoseSet_t_o *poseset;
  f64 v37;
  long f64 v38;
  long f64 v39;
  s32 v40;
  bool v42;
  s32 v43;
  s32 v44;
  s32 v46;
  s32 v47;
  s32 v48;
  s32 v49;
  s32 v52;
  s32 v53;
  s32 v57;
  s32 v58;
  s32 v59;
  s32 v61;
  s32 v62;
  System_Object_array *v67;
  s64 *v70;
  s64 *v72;
  s64 *v82;
  s64 *v83;
  System_String_o *v88;
  System_Object_array *v90;
  System_Object_array *v93;
  s32 v95;
  dds3KernelDraw_c *v96;
  s32 v98;
  f32 evtUpdateEx_LocalFloat0;
  f32 v102;
  f32 v104;
  s32 v105;
  struct System_Int32_array *pm;
  struct System_Int32_array *v108;
  s32 v111;
  f32 v114;
  f32 v115;
  f32 v116;
  f32 v117;
  s32 v120;
  s32 v122;
  s32 evtUpdateEx_CamRunTime;
  struct System_Int32_array *v130;
  struct System_Int32_array *v132;
  dds3Effect_PartialMultiFilterParam_t_o *BlurMultiFilter_Param;
  struct dds3Effect_PartialMultiFilter_t_o *v135;
  s32 v139;
  struct System_Int32_array *v143;
  struct System_Int32_array *v145;
  dds3Effect_PartialMultiFilterParam_t_o *v147;
  struct dds3Effect_PartialMultiFilter_t_o *v148;
  bool v150;
  s32 v152;
  bool v155;
  struct dds3Effect_Filter_t_o *BlurFilterBuff;
  s32 v159;
  s32 v163;
  s32 v167;
  s32 v169;
  bool v171;
  bool v172;
  s32 v174;
  s32 v176;
  s32 v179;
  s32 v182;
  s32 v186;
  bool v190;
  s16 v191;
  s32 v193;
  s32 v195;
  bool v198;
  s32 v204;
  struct System_Int32_array *v208;
  s32 v212;
  s32 v215;
  s32 v219;
  s32 v221;
  s32 v223;
  s32 v225;
  bool v232;
  s32 v234;
  s64 *v237;
  s32 v242;
  s32 v245;
  bool v251;
  s32 v253;
  s32 v258;
  s32 v265;
  s32 v267;
  bool v268;
  s32 v270;
  bool v271;
  bool v272;
  s32 v276;
  f32 v277;
  s32 v280;
  s32 v284;
  UnityEngine_GameObject_o *v285;
  UnityEngine_Transform_o *v286;
  UnityEngine_Transform_o *v287;
  UnityEngine_GameObject_o *v288;
  UnityEngine_Transform_o *v289;
  f32 v290;
  s32 v293;
  bool v294;
  s32 v296;
  bool v297;
  s32 v301;
  UnityEngine_GameObject_o *v302;
  UnityEngine_Transform_o *v303;
  f32 v304;
  s32 v306;
  UnityEngine_Object_o *v310;
  UnityEngine_Transform_o *v311;
  f32 v312;
  s32 v314;
  s32 v316;
  struct System_Int32_array *v319;
  s32 width;
  struct System_Int32_array *v322;
  struct System_Int32_array *v325;
  struct System_Int32_array *v327;
  struct dds3UnityEx_StaticFields **p_static_fields;
  struct dds3UnityEx_StaticFields *v331;
  u32 v332;
  struct dds3Effect_Blur_t_o *BlurBuff;
  s32 v334;
  s32 v336;
  s32 v342;
  s32 v346;
  f32 PShadow_Alp;
  s32 v350;
  bool v352;
  bool v353;
  s32 v356;
  f32 v357;
  f32 v360;
  bool v362;
  bool v365;
  s32 v368;
  s32 v371;
  f32 v372;
  bool v377;
  bool v383;
  bool v384;
  bool v387;
  s32 v389;
  s32 v391;
  bool v392;
  UnityEngine_GameObject_o *v394;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v396;
  UnityEngine_GameObject_o *v397;
  UnityEngine_Transform_o *v398;
  f32 y;
  f32 z;
  UnityEngine_Transform_o *v403;
  s32 v407;
  s32 v410;
  s32 v415;
  f32 v419;
  f32 v421;
  f32 v423;
  s32 evtUpdateEx_CamCngCount;
  s64 v425;
  s32 v426;
  dds3Basic_t_o *pBasic;
  dds3ProcessID_t_o *v428[3];
  dds3ProcessID_t_o *ida;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v432;
  UnityEngine_Vector3_o v433;
  UnityEngine_Vector3_o v434;
  UnityEngine_Vector3_o v435;

  ida = id;
  pBasic = 0;
  v426 = 0;
  v425 = 0;
  else if (dds3GetProcessRunTime(&ida))
  {
    goto LABEL_6;
  }
  evtUpdateEx_Camname = "";
  PShadow_CamFar = 10.0;
  PShadow_Alp = 0.2;
  PShadow_OnOff = 0.0;
  PShadow_VecClipOnOff = 0.0;
  PShadow_YClipOnOff = 1.0;
  evtUpdateEx_CamRunTime = 0;
  evtUpdateEx_CamCngCount = 0;
  evtUpdateEx_GameObject = 0;
  evtUpdateEx_LocalFloat0 = 0.0;
  evtUpdateEx_LocalInt0 = 0;
  evtUpdateEx_old_camera = 0;
  Set_EventMode(1);
  e659_Ara_Out = 0;
  evtUpdateEx_ArkOpen_e674after = 0;
  evtUpdateEx_Dante_e730after = 0;
  evtUpdateEx_ArkOpen_F037_07_THOR_AFTER_Dead = 0;
  PPSV2_update = 1;
  PPSV2_bloom_type = 600;
  DofOff();
  {
LABEL_7:
  }
LABEL_20:
  ProcessData = dds3GetProcessData(&ida);
  v11 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPackProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtPackProcessData_t, v428);
      if ((v428[0] & 1) != 0)
        v14 = v428[2];
      else
        v14 = v428 + 1;
      v15 = sub_8C4940(v14);
    }
    v26 = v11[1].klass;
    evtUpdateEx_NowEveNo = v26;
  }
  v18 = v11[1].klass;
  v17 = &v11[1];
  v16 = v18;
  Set_EventID(v16);
  pBasic = dds3GetActiveScene();
  if (!pBasic)
    return 0;
  ActiveCameraSceneBasic = dds3GetActiveCameraSceneBasic(&pBasic);
  if (!ActiveCameraSceneBasic)
    return 0;
  name = ActiveCameraSceneBasic->name;
  v24 = ActiveCameraSceneBasic;
  if (!name)
  {
    if (*v17 == 614 || *v17 == 601)
    {
      SetDrawFlag(0x2000000u, 1u);
      name = v24->name;
    }
    else
    {
      name = 0;
    }
  }
  v30 = op_Inequality(evtUpdateEx_Camname, name, 0);
  if (!v30)
  {
    ++evtUpdateEx_CamRunTime;
    goto LABEL_219;
  }
  evtUpdateEx_Camname = name;
  evtUpdateEx_CamRunTime = 0;
  ++evtUpdateEx_CamCngCount;
  Eve_DOF_Set(*v17, name);
  if (!evtUpdateEx_old_camera)
    goto LABEL_72;
  poseset = evtUpdateEx_old_camera->poseset;
  if (!poseset)
    goto LABEL_72;
  sub_8524C0(&v425, poseset->pos.x - v24->poseset->pos.x, poseset->pos.y - v24->poseset->pos.y, poseset->pos.z - v24->poseset->pos.z);
  v39 = sub_8535D0(&v425, 0, v37, v38);
  if (*&v39 >= 0.1)
  {
LABEL_72:
    v42 = *v17 != 615 && *v17 != 605 && (*v17 - 603) > 1;
    if (*v17 == 619
      && (op_Equality(name, "cam06", 0)
       || op_Equality(name, "cam09", 0)))
    {
      v42 = 0;
    }
    v43 = *v17;
    v44 = v42 && *v17 != 621;
    if (*v17 == 623)
    {
      v44 &= !op_Equality(name, "cam06", 0);
      v43 = *v17;
    }
    if (v43 == 628)
    {
      if (op_Equality(name, "c02", 0)
        || op_Equality(name, "c03", 0)
        || op_Equality(name, "c05", 0)
        || op_Equality(name, "cam06", 0))
      {
        LOBYTE(v44) = 0;
      }
      if (op_Equality(name, "c03", 0)
        || op_Equality(name, "c04", 0)
        || op_Equality(name, "c05", 0)
        || op_Equality(name, "c06", 0))
      {
        Postblur_AccumTex_NowMode = 1;
      }
    }
    v46 = *v17;
    v47 = (*v17 != 635) & v44 & ((*v17 | 2) != 634);
    if (*v17 == 636)
    {
      v47 &= !op_Inequality(name, "cam01", 0);
      v46 = *v17;
    }
    v48 = (v46 != 661) & (v46 != 659) & ((v46 | 4) != 655) & (v46 != 644) & v47 & (v46 != 639);
    if (v46 == 670)
    {
      v48 &= !op_Inequality(name, "cam02", 0);
      v46 = *v17;
    }
    v49 = (v46 != 682) & ((v46 - 679) > 1) & ((v46 - 673) > 1) & v48 & (v46 != 671);
    if (v46 == 684)
    {
      if (op_Equality(name, "cam03", 0)
        || op_Equality(name, "cam04", 0)
        || op_Equality(name, "cam05", 0)
        || op_Equality(name, "cam06", 0))
      {
        Postblur_AccumTex_NowMode = 1;
      }
      v49 &= !op_Equality(name, "cam06", 0);
      v46 = *v17;
    }
    v52 = v49 & (v46 != 686);
    if (v46 == 688)
    {
      v52 &= !op_Equality(name, "cam05", 0);
      v46 = *v17;
    }
    v53 = v52 & (v46 != 697);
    if (v46 == 705)
    {
      else
      {
        v46 = 705;
      }
      v53 = v53 & (fldGb->areaID != 0);
      if (v46 == 705)
      {
        else
        {
          v46 = 705;
        }
        v53 = v53 & (fldGb->areaID == 0);
      }
    }
    if ((v46 - 710) <= 0xC)
    {
      Postblur_AccumTex_NowMode = 1;
      v46 = *v17;
      v53 = 0;
    }
    if (v46 == 723)
    {
      v53 &= !evtBitCheck(3712);
      if (*v17 == 723)
      {
        if (op_Equality(name, "camera07", 0))
          v53 &= evtBitCheck(3712);
        v57 = *v17;
        if (*v17 != 723)
        {
LABEL_130:
          v58 = v53 & (v57 != 726);
          if (v57 == 728 && op_Inequality(name, "01cam_08", 0))
            v58 &= evtBitCheck(3712);
          v59 = *v17;
          if (*v17 == 728)
          {
            if ((v58 & evtBitCheck(3712)) == 1)
            {
              UnityEx_SkyFilterSkip = 1;
            }
            v59 = *v17;
          }
          if (v59 == 729)
          {
            v58 &= !op_Inequality(name, "01cam_03", 0);
            v59 = *v17;
          }
          v61 = v58 & (v59 != 730);
          if (v59 == 731 && op_Equality(name, "01cam_09", 0))
            v61 &= !evtBitCheck(3712);
          v62 = *v17;
          if (*v17 == 731 && v61)
          {
            UnityEx_SkyFilterSkip = 1;
            v62 = *v17;
          }
          if ((v62 - 740) <= 8)
          {
            Postblur_AccumTex_NowMode = 1;
            v62 = *v17;
            if (*v17 == 748)
            {
              op_Equality(name, "01cam_08", 0);
              v62 = *v17;
            }
            LOBYTE(v61) = 0;
          }
          v40 = v61 & (v62 != 807);
            goto LABEL_161;
          goto LABEL_159;
        }
        if (op_Equality(name, "cut06", 0))
          v53 &= evtBitCheck(3712);
      }
    }
    v57 = *v17;
    goto LABEL_130;
  }
  v40 = 0;
  {
LABEL_159:
  }
LABEL_161:
  evtUpdateEx_old_camera = v24;
  if (DisableStop1EventNo)
  {
    v40 = 0;
    DisableStop1EventNo = 0;
  }
  v67 = NewSpecific(object, 7u);
  v67->m_Items[0] = "●●●●eventno:";
  LODWORD(v428[0]) = *v17;
  v70 = sub_8D3950(s32, v428);
  v72 = v70;
  v67->m_Items[1] = v72;
  v67->m_Items[2] = " camera:";
  v67->m_Items[3] = name;
  v67->m_Items[4] = " [";
  v82 = sub_8D3950(s32, &evtUpdateEx_CamCngCount);
  v83 = v82;
  v67->m_Items[5] = v83;
  v67->m_Items[6] = "]";
  v88 = Concat_5270224(v67);
  v90 = Empty_string_();
  Log(v88, v90, 0);
  if (v40)
  {
    SetDrawFlag(0x2000000u, 1u);
  }
  else
  {
    v93 = Empty_string_();
    Log("カメラ座標は同じor条件オフなので1フレ描画停止はスキップします", v93, 0);
  }
LABEL_219:
  Debug_OW_SkyAlp();
  v95 = *v17;
  if (*v17 == 601)
  {
    if (!op_Equality(name, "cam01", 0))
    {
      evtUpdateEx_LocalFloat0 = evtUpdateEx_LocalFloat0 + 0.05;
      v102 = sinf(evtUpdateEx_LocalFloat0);
      v104 = v102 + v102;
      BlurBuff->abgr = 75006080;
      v105 = v104;
      if (v104 >= 0.0)
        v105 = v104;
      BlurBuff->abgr += v105 << 24;
      BlurBuff->blend = 2;
      BlurBuff->rotate = 0.001;
      BlurBuff->scale = 0.9;
      pm = BlurBuff->center->pm;
      pm->m_Items[0] = 0;
      v108 = BlurBuff->center->pm;
      v108->m_Items[1] = 0;
      dds3EffectBlur(&BlurBuff, 0, 0);
      return 0;
    }
    v95 = *v17;
  }
  switch (v95)
  {
    case 602:
      PShadow_CamX = -52.0;
      PShadow_CamY = 2.0;
      PShadow_CamZ = -3.5;
      PShadow_RotX = 60.0;
      v98 = 1112014848;
      goto LABEL_250;
    case 603:
      PShadow_CamX = -7.5;
      PShadow_CamY = 2.0;
      PShadow_CamZ = 14.5;
      PShadow_RotX = 70.0;
      v98 = 1114636288;
LABEL_250:
      LODWORD(PShadow_RotY) = v98;
      v111 = 1077936128;
      goto LABEL_286;
    case 605:
      if (op_Equality(name, "cam01", 0)
        || op_Equality(name, "cam02", 0)
        || op_Equality(name, "cam04", 0)
        || op_Equality(name, "cam07", 0)
        || op_Equality(name, "cam09", 0)
        || op_Equality(name, "cam11", 0)
        || op_Equality(name, "cam16", 0))
      {
        v114 = 18.5;
        v115 = -7.9;
        v116 = 0.5;
        v117 = 2.0;
          goto LABEL_261;
      }
      else
      {
        v171 = op_Equality(name, "cam06", 0);
        if (v171)
        {
          v116 = 5.0;
          v114 = 21.0;
          v117 = 3.0;
          v115 = -9.0;
            goto LABEL_261;
        }
        else
        {
          v116 = 1.6;
          v114 = 19.2;
          v115 = -8.1;
          v117 = 3.0;
            goto LABEL_261;
        }
      }
LABEL_261:
      PShadow_CamX = v115;
      PShadow_CamY = v117;
      PShadow_CamZ = v114;
      PShadow_RotX = 70.0;
      PShadow_RotY = -40.0;
      PShadow_CamSize = v116;
      PShadow_OnOff = 1.0;
        goto LABEL_263;
      goto LABEL_264;
    case 615:
      if (op_Equality(name, "cam04", 0))
      {
        PShadow_CamX = -72.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = -24.1;
        PShadow_RotX = 70.0;
        v120 = 1124204544;
LABEL_270:
        LODWORD(PShadow_RotY) = v120;
        PShadow_CamSize = 1.0;
        v122 = 1050253722;
        goto LABEL_271;
      }
      if (!op_Equality(name, "cam12", 0)
        && !op_Equality(name, "cam13", 0)
        && !op_Equality(name, "cam14", 0))
      {
        PShadow_CamX = -72.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = -19.1;
        PShadow_RotX = 75.0;
        v120 = 1127481344;
        goto LABEL_270;
      }
      PShadow_CamX = -72.5;
      PShadow_CamY = 3.0;
      PShadow_CamZ = -24.8;
      PShadow_RotX = 75.0;
      PShadow_RotY = 130.0;
      v152 = 1067030938;
      goto LABEL_377;
    case 616:
      if (!op_Equality(name, "cam03", 0))
        return 0;
      PShadow_CamX = 2.0;
      PShadow_CamY = 2.2;
      PShadow_CamZ = -1.0;
      PShadow_RotX = 60.0;
      PShadow_RotY = -40.0;
      v111 = 1070386381;
      goto LABEL_286;
    case 617:
      return 0;
    case 618:
      if (op_Equality(name, "cam01", 0))
      {
        if (!evtUpdateEx_CamRunTime)
        {
          evtUpdateEx_LocalInt0 = 0;
          BlurMultiFilter_Param->Filter->blend = 5;
          BlurMultiFilter_Param->Filter->abgr = -2139062144;
          BlurMultiFilter_Param->area = 276;
          v130 = BlurMultiFilter_Param->center->pm;
          v130->m_Items[0] = 0;
          v132 = BlurMultiFilter_Param->center->pm;
          v132->m_Items[1] = 0;
          v135 = dds3EffectPartialMultiFilterCreate(BlurMultiFilter_Param);
          BlurMultiFilterBuff = v135;
        }
        dds3EffectPartialMultiFilterDraw(&BlurMultiFilterBuff);
      }
      if (op_Equality(name, "cam02", 0))
      {
        ++evtUpdateEx_LocalInt0;
        v139 = 96 - evtUpdateEx_LocalInt0;
        if (v139 >= 1)
        {
          BlurFilterBuff->abgr = (v139 << 24) | 0x747474;
          BlurFilterBuff->blend = 2;
          dds3EffectFilter(&BlurFilterBuff, 0, 0);
        }
      }
      if (op_Equality(name, "cam04", 0))
      {
        if (!evtUpdateEx_CamRunTime)
        {
          BlurMultiFilter_Param->Filter->blend = 5;
          BlurMultiFilter_Param->Filter->abgr = -2139851660;
          BlurMultiFilter_Param->area = 414;
          v143 = BlurMultiFilter_Param->center->pm;
          v143->m_Items[0] = -256;
          v145 = BlurMultiFilter_Param->center->pm;
          v145->m_Items[1] = 92;
          v147 = BlurMultiFilter_Param;
          v148 = dds3EffectPartialMultiFilterCreate(v147);
          BlurMultiFilterBuff = v148;
        }
        dds3EffectPartialMultiFilterDraw(&BlurMultiFilterBuff);
      }
      v150 = op_Equality(name, "cam06", 0);
      if (v150)
      {
        PShadow_CamX = -86.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = -65.5;
        PShadow_RotX = 80.0;
        PShadow_RotY = 0.0;
        v152 = 1069547520;
        goto LABEL_377;
      }
      PShadow_Alp = 0.3;
      PShadow_CamSize = 1.5;
      return 0;
    case 619:
      PShadow_CamX = -0.5;
      v152 = 0x40000000;
      PShadow_CamY = 2.0;
      PShadow_CamZ = 0.6;
      PShadow_RotX = 90.0;
      PShadow_RotY = -40.0;
      goto LABEL_377;
    case 621:
      PShadow_Alp = 0.3;
      v155 = op_Equality(name, "cam03", 0);
      if (v155)
      {
        PShadow_CamX = -80.5;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 11.6;
        PShadow_RotX = 50.0;
        PShadow_RotY = 130.0;
        PShadow_CamSize = 1.0;
        PShadow_Alp = 0.5;
        PShadow_OnOff = 1.0;
        v159 = 268452921;
      }
      else
      {
        PShadow_CamX = -84.4;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 14.2;
        PShadow_RotX = 60.0;
        PShadow_RotY = 210.0;
        PShadow_CamSize = 1.0;
        PShadow_Alp = 0.3;
        PShadow_OnOff = 1.0;
        v159 = 536888377;
      }
      BlurFilterBuff->abgr = v159;
      BlurFilterBuff->blend = 1;
      dds3EffectFilter(&BlurFilterBuff, 0, 0);
      return 0;
    case 623:
      PShadow_Alp = 0.3;
      PShadow_RotX = 80.0;
      return 0;
    case 628:
      if (op_Equality(name, "cam01", 0))
      {
        if (evtUpdateEx_CamRunTime > 107)
        {
          PShadow_CamX = 0.0;
          PShadow_CamY = 4.0;
          PShadow_CamZ = 10.0;
          PShadow_RotX = 50.0;
          PShadow_RotY = 190.0;
          v111 = 0x40000000;
LABEL_286:
          LODWORD(PShadow_CamSize) = v111;
LABEL_380:
LABEL_414:
          PShadow_OnOff = 1.0;
          return 0;
        }
        PShadow_CamX = 0.0;
        PShadow_CamY = 3.0;
        v169 = -1053818880;
LABEL_411:
        LODWORD(PShadow_CamZ) = v169;
        PShadow_RotX = 60.0;
        v167 = 1127481344;
        goto LABEL_412;
      }
      if (op_Equality(name, "cam02", 0)
        || op_Equality(name, "cam03", 0)
        || op_Equality(name, "c01", 0)
        || op_Equality(name, "c02", 0)
        || op_Equality(name, "c03", 0)
        || op_Equality(name, "c04", 0))
      {
        PShadow_CamX = 2.1;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 7.0;
        PShadow_RotX = 90.0;
        v167 = -1028390912;
LABEL_412:
        LODWORD(PShadow_RotY) = v167;
        PShadow_CamSize = 1.0;
        goto LABEL_413;
      }
      if (op_Equality(name, "cam06", 0)
        || op_Equality(name, "cam07", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 4.0;
        PShadow_CamZ = 10.0;
        PShadow_RotX = 50.0;
        PShadow_RotY = 190.0;
        v111 = 1091567616;
        goto LABEL_286;
      }
      v95 = *v17;
LABEL_432:
      if (v95 != 629)
        break;
      v172 = op_Equality(name, "cam07", 0);
      if (v172)
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 2.0;
        PShadow_CamZ = -5.0;
        v174 = 1103626240;
LABEL_438:
        LODWORD(PShadow_RotX) = v174;
        v176 = 1127481344;
LABEL_439:
        LODWORD(PShadow_RotY) = v176;
LABEL_440:
        PShadow_CamSize = 2.0;
        v163 = 1056964608;
        goto LABEL_379;
      }
      PShadow_OnOff = 0.0;
      v95 = *v17;
      break;
    default:
      goto LABEL_432;
  }
  switch (v95)
  {
    case 632:
      if (op_Equality(name, "cam03", 0)
        || op_Equality(name, "cam04", 0)
        || op_Equality(name, "cam05", 0)
        || op_Equality(name, "cam06", 0)
        || op_Equality(name, "cam07", 0)
        || op_Equality(name, "cam09", 0)
        || op_Equality(name, "cam10", 0))
      {
        v111 = 1077936128;
        PShadow_CamX = 3.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = -2.0;
        v182 = 1116471296;
        goto LABEL_461;
      }
      if (!op_Equality(name, "cam08", 0))
      {
        if (!op_Equality(name, "cam11", 0)
          && !op_Equality(name, "cam12", 0))
        {
          PShadow_CamX = 2.0;
          PShadow_CamY = 2.0;
          PShadow_CamZ = -3.5;
          PShadow_RotX = 85.0;
          v167 = 1119092736;
          goto LABEL_412;
        }
          goto LABEL_1346;
        goto LABEL_1344;
      }
      v410 = evtUpdateEx_CamRunTime;
      if (v410 > 267)
      {
        {
LABEL_1346:
          v111 = 1077936128;
          PShadow_CamX = 3.0;
          PShadow_CamY = 3.0;
          PShadow_CamZ = -2.0;
          v182 = 1117782016;
LABEL_461:
          LODWORD(PShadow_RotX) = v182;
          PShadow_RotY = 90.0;
          goto LABEL_286;
        }
LABEL_1344:
        goto LABEL_1346;
      }
        goto LABEL_1275;
      goto LABEL_1273;
    case 634:
      PShadow_ClipX = 0.0;
      PShadow_ClipY = 0.0;
      PShadow_ClipZ = 300.0;
      PShadow_YClipOnOff = 1.0;
      PShadow_VecClipOnOff = 1.0;
      if (op_Equality(name, "cam03", 0)
        || op_Equality(name, "cam04", 0)
        || op_Equality(name, "cam05", 0)
        || op_Equality(name, "cam06", 0))
      {
        goto LABEL_741;
      }
      if (op_Equality(name, "cam07", 0)
        || op_Equality(name, "cam08", 0)
        || op_Equality(name, "cam09", 0)
        || op_Equality(name, "cam10", 0))
      {
        PShadow_CamX = -3.5;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 4.2;
        v186 = 1112014848;
        goto LABEL_1254;
      }
      if (op_Equality(name, "cam11", 0))
      {
        PShadow_CamX = -1.0;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 5.0;
        v174 = 1112014848;
        goto LABEL_438;
      }
      if (op_Equality(name, "cam13", 0)
        || op_Equality(name, "cam15", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 3.5;
        PShadow_RotX = 60.0;
        v391 = 1134886912;
        goto LABEL_1249;
      }
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.0;
      PShadow_CamZ = 2.0;
      PShadow_RotX = 50.0;
      PShadow_RotY = 0.0;
      goto LABEL_500;
    case 635:
      if (op_Equality(name, "cam05", 0))
      {
        if (!evtUpdateEx_CamRunTime)
        {
          dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0);
        }
        if (evtUpdateEx_CamRunTime == 1)
        {
          dds3FadeIn(0xFFu, 0xFFu, 0xFFu, 0xFu);
        }
      }
      if (op_Equality(name, "cam01", 0)
        || op_Equality(name, "cam02", 0))
      {
        PShadow_CamX = -2.2;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 7.5;
        PShadow_RotX = 70.0;
        PShadow_RotY = 180.0;
LABEL_500:
        PShadow_CamSize = 1.0;
        v122 = 1056964608;
        goto LABEL_271;
      }
      if (op_Equality(name, "cam03", 0))
      {
        PShadow_CamX = -2.0;
        PShadow_CamY = 2.3;
        if (evtUpdateEx_CamRunTime <= 169)
        {
          v360 = 5.5;
          if ((*&v96->_2.bitflags1 & 0x200) == 0)
            goto LABEL_1245;
        }
        else
        {
          v360 = 2.5;
          if ((*&v96->_2.bitflags1 & 0x200) == 0)
            goto LABEL_1245;
        }
LABEL_1245:
        PShadow_CamZ = v360;
        PShadow_RotX = 60.0;
        v391 = 1125515264;
LABEL_1249:
        LODWORD(PShadow_RotY) = v391;
        goto LABEL_440;
      }
      if (op_Equality(name, "cam21", 0)
        || op_Equality(name, "cam04", 0))
      {
        PShadow_CamX = -1.6;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 2.0;
        PShadow_RotX = 60.0;
        v176 = 1125515264;
        goto LABEL_439;
      }
      if (op_Equality(name, "cam05", 0)
        || op_Equality(name, "cam10", 0))
      {
        v394 = Find("npc_tiaki_e635", 0);
        transform = get_transform(v394, 0);
        localPosition = get_localPosition(transform);
        v396 = get_transform(v394, 0);
        v434.y = -0.05;
        v434.x = localPosition.x;
        v434.z = localPosition.z;
        set_localPosition(v396, v434);
      }
      if (op_Equality(name, "cam13", 0))
      {
        v397 = Find("npc_tiaki_e635", 0);
        v398 = get_transform(v397, 0);
        v432 = get_localPosition(v398);
        y = v432.y;
        z = v432.z;
        if (evtUpdateEx_LocalInt0)
          z = -0.05;
        else
          y = -0.05;
        v403 = get_transform(v397, 0);
        v435.x = v432.x;
        v435.y = y;
        v435.z = z;
        set_localPosition(v403, v435);
      }
      if (op_Equality(name, "cam06", 0)
        || op_Equality(name, "cam07", 0))
      {
        evtUpdateEx_LocalInt0 = 1;
      }
      goto LABEL_1059;
    case 636:
      v190 = op_Equality(name, "cam03", 0);
      if (v190)
        goto LABEL_1272;
      PShadow_CamX = 0.0;
      PShadow_CamY = 4.5;
      PShadow_CamZ = 2.4;
      PShadow_RotX = 70.0;
      PShadow_RotY = 180.0;
      PShadow_CamSize = 4.3;
      v193 = 1050253722;
      goto LABEL_946;
    case 639:
      PShadow_CamX = 0.7;
      PShadow_CamY = 2.0;
      PShadow_CamZ = -0.3;
      PShadow_RotX = 70.0;
      PShadow_RotY = 0.0;
      v195 = 1061997773;
      goto LABEL_1240;
    case 644:
      PShadow_YClipOnOff = 0.0;
      v198 = op_Equality(name, "cam04", 0);
      if (v198)
      {
        PShadow_CamX = 19.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 6.0;
        PShadow_RotX = 60.0;
        PShadow_RotY = -90.0;
      }
      else
      {
        PShadow_CamX = 31.8;
        PShadow_CamY = 4.0;
        PShadow_CamZ = 3.7;
        PShadow_RotX = 70.0;
        PShadow_RotY = 0.0;
      }
      goto LABEL_879;
    case 650:
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.0;
      v169 = 1090519040;
      goto LABEL_411;
    case 651:
      if (!op_Equality(evtUpdateEx_FieldName, "f651_010(Clone)", 0))
        goto LABEL_1166;
      if (op_Equality(name, "cam03", 0))
      {
        PShadow_CamX = 0.0;
        v195 = 1075838976;
        PShadow_CamY = 2.5;
        PShadow_CamZ = -3.5;
        PShadow_RotX = 70.0;
        PShadow_RotY = 180.0;
        goto LABEL_1240;
      }
      if (op_Equality(name, "cam04", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 4.0;
        PShadow_CamZ = 0.0;
        PShadow_RotX = 70.0;
        PShadow_RotY = 180.0;
        v195 = 1075838976;
        goto LABEL_1240;
      }
      if (op_Equality(name, "cam10", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 4.0;
        PShadow_CamZ = 0.0;
        PShadow_RotX = 70.0;
        PShadow_RotY = 180.0;
        v225 = 0x40000000;
        goto LABEL_1086;
      }
LABEL_1166:
      if (!op_Equality(evtUpdateEx_FieldName, "f651_001(Clone)", 0))
        goto LABEL_1325;
      if (op_Equality(name, "cam01", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 2.0;
        PShadow_CamZ = -1.1;
        PShadow_RotX = 90.0;
        PShadow_RotY = 180.0;
        v152 = 1069547520;
        goto LABEL_377;
      }
      if (op_Equality(name, "cam04", 0)
        || op_Equality(name, "cam05", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 2.0;
        PShadow_CamZ = -0.2;
        PShadow_RotX = 80.0;
        PShadow_RotY = 180.0;
        v225 = 1058642330;
        goto LABEL_1086;
      }
      if (op_Equality(name, "cam08", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 2.0;
        PShadow_CamZ = -0.2;
        PShadow_RotX = 80.0;
        PShadow_RotY = 180.0;
        v195 = 1060320051;
        goto LABEL_1240;
      }
      if (op_Equality(name, "cam11", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 2.5;
        PShadow_CamZ = -0.2;
        PShadow_RotX = 80.0;
        v389 = 1127481344;
        goto LABEL_1239;
      }
      if (op_Equality(name, "cam12", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 2.5;
        PShadow_CamZ = -1.4;
        PShadow_RotX = 65.0;
        PShadow_RotY = 160.0;
        goto LABEL_879;
      }
LABEL_1325:
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.0;
      PShadow_CamZ = -80.5;
      PShadow_RotX = 70.0;
      PShadow_RotY = 0.0;
      PShadow_CamSize = 2.0;
      goto LABEL_1275;
    case 655:
      goto LABEL_1059;
    case 658:
      if (op_Equality(name, "cam01", 0))
      {
        PShadow_CamX = 1.3;
        PShadow_CamY = 6.0;
        PShadow_CamZ = -15.3;
        PShadow_RotX = 80.0;
        PShadow_RotY = 200.0;
        PShadow_CamSize = 1.0;
        v204 = 1050253722;
LABEL_576:
        LODWORD(PShadow_Alp) = v204;
        goto LABEL_948;
      }
      if (!op_Equality(name, "cam02", 0))
        goto LABEL_1059;
      v316 = evtUpdateEx_CamRunTime;
      if (v316 > 459)
      {
        PShadow_CamX = 2.0;
        PShadow_CamY = 2.0;
        PShadow_CamZ = -12.0;
        PShadow_RotX = 70.0;
        PShadow_RotY = 20.0;
        v195 = 1077936128;
        goto LABEL_1240;
      }
      PShadow_CamX = 2.0;
      PShadow_CamY = 2.0;
      PShadow_CamZ = -1.0;
      PShadow_RotX = 70.0;
      PShadow_RotY = 290.0;
      goto LABEL_879;
    case 659:
      if (op_Equality(name, "cam04", 0))
      {
          goto LABEL_540;
        goto LABEL_539;
      }
      if (op_Equality(name, "cam05", 0))
      {
        BlurBuff->abgr = 1216381056;
        BlurBuff->blend = 1;
        BlurBuff->rotate = 0.001;
        BlurBuff->scale = 0.99;
        v319 = BlurBuff->center->pm;
        width = get_width(0);
        v319->m_Items[0] = width / 4;
        goto LABEL_896;
      }
      if (op_Equality(name, "cam06", 0))
      {
        if (!e659_Ara_Out)
        {
            goto LABEL_541;
LABEL_539:
LABEL_540:
LABEL_541:
          BlurBuff->abgr = 1216381056;
          BlurBuff->blend = 1;
          BlurBuff->rotate = 0.001;
          BlurBuff->scale = 0.985;
          v208 = BlurBuff->center->pm;
          v208->m_Items[0] = 0;
LABEL_896:
          v322 = BlurBuff->center->pm;
          v322->m_Items[1] = 0;
          dds3EffectBlur(&BlurBuff, 0, 0);
        }
      }
      if (op_Equality(name, "cam01", 0))
      {
        PShadow_YClipOnOff = 0.0;
        goto LABEL_1275;
      }
      if (op_Equality(name, "cam02", 0))
      {
        v356 = evtUpdateEx_CamRunTime;
        if (v356 <= 19)
        {
          v357 = -5.5;
            goto LABEL_1235;
        }
        else
        {
          if (v356 <= 27)
          {
            v357 = -5.8;
              goto LABEL_1235;
          }
          else
          {
            v357 = -6.0;
              goto LABEL_1235;
          }
        }
LABEL_1235:
        PShadow_CamZ = v357;
        PShadow_CamX = -0.7;
        PShadow_CamY = 3.0;
        PShadow_RotX = 80.0;
        v389 = 1119092736;
LABEL_1239:
        LODWORD(PShadow_RotY) = v389;
        v195 = 1056964608;
LABEL_1240:
        LODWORD(PShadow_CamSize) = v195;
LABEL_1241:
        v163 = 1053609165;
        goto LABEL_379;
      }
      if (op_Equality(name, "cam03", 0))
      {
        PShadow_CamX = -1.0;
        v195 = 1077936128;
        PShadow_CamY = 3.0;
        PShadow_CamZ = -4.0;
        PShadow_RotX = 80.0;
        PShadow_RotY = 90.0;
        goto LABEL_1240;
      }
      v387 = op_Equality(name, "cam07", 0);
      if (v387)
      {
        PShadow_CamX = -1.0;
        PShadow_CamY = 2.0;
        PShadow_CamZ = -4.5;
        PShadow_RotX = 80.0;
        PShadow_RotY = 90.0;
        v152 = 1077936128;
LABEL_377:
        LODWORD(PShadow_CamSize) = v152;
        goto LABEL_378;
      }
      PShadow_CamX = -1.0;
      PShadow_CamY = 2.0;
      PShadow_CamZ = -2.0;
      PShadow_RotX = 80.0;
      PShadow_RotY = 90.0;
LABEL_879:
      PShadow_CamSize = 1.0;
      goto LABEL_1013;
    case 661:
    case 674:
    case 693:
    case 694:
      return 0;
    case 671:
      if (!op_Equality(name, "cam21", 0)
        && !op_Equality(name, "cam26", 0))
      {
        goto LABEL_1059;
      }
      PShadow_CamX = -0.6;
      PShadow_CamY = 7.0;
      PShadow_CamZ = -22.2;
      PShadow_RotX = 70.0;
      v212 = 1121714176;
      goto LABEL_575;
    case 672:
      if (op_Equality(name, "cam015", 0)
        || op_Equality(name, "cam02", 0)
        || op_Equality(name, "cam03", 0)
        || op_Equality(name, "cam04", 0))
      {
        PShadow_CamX = 1.0;
        PShadow_CamY = -5.0;
        PShadow_CamZ = -10.5;
        PShadow_RotX = 80.0;
        PShadow_RotY = 90.0;
        PShadow_CamSize = 1.0;
        v122 = 1056964608;
        goto LABEL_271;
      }
      v314 = 1056964608;
      goto LABEL_874;
    case 673:
      v215 = evtUpdateEx_CamCngCount;
      if (v215 == 2)
        goto LABEL_566;
      if (v215 == 5)
      {
LABEL_566:
        PShadow_CamX = 0.0;
        PShadow_CamY = -4.0;
        PShadow_CamZ = -14.0;
        PShadow_RotX = 60.0;
        PShadow_RotY = 0.0;
        goto LABEL_944;
      }
      if (v215 != 15)
        goto LABEL_1272;
      PShadow_CamX = 0.0;
      PShadow_CamY = -4.0;
      PShadow_CamZ = -20.0;
      PShadow_RotX = 60.0;
      PShadow_RotY = 0.0;
      PShadow_CamSize = 2.0;
      goto LABEL_1221;
    case 677:
      PShadow_CamX = 1.5;
      PShadow_CamY = -3.0;
      v179 = -1046478848;
      goto LABEL_574;
    case 678:
    case 679:
      PShadow_CamX = 0.0;
      PShadow_CamY = -3.0;
      v179 = -1049624576;
LABEL_574:
      LODWORD(PShadow_CamZ) = v179;
      PShadow_RotX = 70.0;
      v212 = 1127481344;
LABEL_575:
      LODWORD(PShadow_RotY) = v212;
      PShadow_CamSize = 1.0;
      v204 = 1056964608;
      goto LABEL_576;
    case 680:
    case 681:
      goto LABEL_940;
    case 682:
      BlurBuff->abgr = 813715544;
      BlurBuff->blend = 2;
      BlurBuff->rotate = 0.001;
      v219 = evtUpdateEx_CamCngCount;
      if (v219 <= 3)
      {
        BlurBuff->abgr = 812666992;
        goto LABEL_911;
      }
      if (v219 == 4)
        goto LABEL_1392;
      if (v219 == 7)
      {
LABEL_1392:
          goto LABEL_911;
        goto LABEL_1121;
      }
      BlurBuff->scale = 0.99;
      v325 = BlurBuff->center->pm;
      v325->m_Items[0] = 0;
      v327 = BlurBuff->center->pm;
      v327->m_Items[1] = 0;
      if (evtUpdateEx_CamCngCount == 9)
      {
        if (evtUpdateEx_CamRunTime >= 121)
        {
          BlurBuff->scale = 0.9;
          v331 = *p_static_fields;
          v332 = v331->evtUpdateEx_CamRunTime - 120;
          BlurBuff = v331->BlurBuff;
          v334 = v332 >> 1 << 24;
          if (v332 > 0xA1)
            v334 = 1342177280;
          BlurBuff->abgr += v334;
        }
      }
      dds3EffectBlur(&BlurBuff, 0, 0);
LABEL_940:
      PShadow_CamX = 0.0;
      PShadow_CamY = -3.0;
      PShadow_CamZ = -15.0;
      PShadow_RotX = 70.0;
      PShadow_RotY = 180.0;
LABEL_944:
      PShadow_CamSize = 2.0;
LABEL_945:
      v193 = 1056964608;
      goto LABEL_946;
    case 684:
      v221 = evtUpdateEx_CamCngCount;
      if (v221 < 5)
      {
        PShadow_CamX = -0.5;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 5.2;
        v223 = 1115815936;
        goto LABEL_609;
      }
      PShadow_CamX = -1.0;
      PShadow_CamY = 3.0;
      PShadow_CamZ = 6.0;
      PShadow_RotX = 70.0;
      v336 = 1120403456;
      goto LABEL_1085;
    case 686:
      PShadow_CamX = -0.4;
      PShadow_CamY = 3.0;
      PShadow_CamZ = 5.7;
      PShadow_RotX = 60.0;
      PShadow_RotY = 40.0;
      v225 = 1070386381;
      goto LABEL_1086;
    case 688:
      if (op_Equality(name, "cam01", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 5.0;
        v223 = 1117126656;
LABEL_609:
        LODWORD(PShadow_RotX) = v223;
        PShadow_RotY = 45.0;
        v225 = 1067030938;
      }
      else if (op_Equality(name, "cam02", 0))
      {
        PShadow_CamX = -1.0;
        PShadow_CamY = 3.0;
        v225 = 0x40000000;
        PShadow_CamZ = 2.0;
        PShadow_RotX = 60.0;
        PShadow_RotY = 90.0;
      }
      else
      {
        if (!op_Equality(name, "cam04", 0)
          && !op_Equality(name, "cam05", 0))
        {
          PShadow_CamX = -0.5;
          PShadow_CamY = 3.0;
          PShadow_CamZ = 7.0;
          v186 = 1114636288;
LABEL_1254:
          LODWORD(PShadow_RotX) = v186;
          PShadow_RotY = 150.0;
          PShadow_CamSize = 1.0;
LABEL_1255:
          v122 = 1045220557;
          goto LABEL_271;
        }
        PShadow_CamX = -1.3;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 1.1;
        PShadow_RotX = 60.0;
        v336 = 1119092736;
LABEL_1085:
        LODWORD(PShadow_RotY) = v336;
        v225 = 1060320051;
      }
LABEL_1086:
      LODWORD(PShadow_CamSize) = v225;
      goto LABEL_1087;
    case 697:
      if (op_Equality(name, "cam01", 0))
      {
        PShadow_CamX = -0.2;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 35.2;
        PShadow_RotX = 80.0;
        PShadow_RotY = 170.0;
        PShadow_CamSize = 0.4;
        PShadow_Alp = 0.1;
        PShadow_OnOff = 1.0;
        PShadow_ClipY = 160.0;
        goto LABEL_949;
      }
      if (op_Equality(name, "cam06", 0))
      {
        PShadow_CamX = 0.5;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 35.0;
        PShadow_RotX = 80.0;
        PShadow_RotY = 250.0;
        PShadow_CamSize = 1.0;
        PShadow_Alp = 0.3;
      }
      else
      {
        v365 = op_Equality(name, "cam07", 0);
        if (!v365)
          goto LABEL_1272;
        PShadow_CamX = 0.0;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 34.0;
        PShadow_RotX = 80.0;
        PShadow_RotY = 250.0;
        PShadow_CamSize = 1.5;
        PShadow_Alp = 0.3;
      }
      PShadow_OnOff = 1.0;
      PShadow_ClipY = 150.0;
      PShadow_YClipOnOff = 1.0;
      return 0;
    case 705:
      if (op_Equality(name, "cam06", 0)
        || op_Equality(name, "cam07", 0)
        || op_Equality(name, "cam08", 0))
      {
        goto LABEL_870;
      }
      if (evtUpdateEx_CamCngCount >= 5)
      {
LABEL_870:
        PShadow_CamX = 1.0;
        PShadow_CamY = -3.0;
        PShadow_CamZ = -56.5;
        PShadow_RotX = 50.0;
        PShadow_RotY = 180.0;
        PShadow_CamSize = 1.0;
        PShadow_OnOff = 1.0;
        v314 = 1045220557;
LABEL_874:
        LODWORD(PShadow_Alp) = v314;
        goto LABEL_949;
      }
      if (!op_Equality(name, "cam00", 0)
        && !op_Equality(name, "cam01", 0)
        && !op_Equality(name, "cam02", 0))
      {
        goto LABEL_1059;
      }
      PShadow_CamX = 0.0;
      PShadow_CamY = 11.5;
      PShadow_CamZ = 12.5;
      PShadow_RotX = 70.0;
      PShadow_RotY = 0.0;
      PShadow_CamSize = 1.5;
      goto LABEL_947;
    case 710:
      if (op_Equality(name, "01cam_01", 0))
      {
        if (evtUpdateEx_CamRunTime == 150)
        {
          p2sdPlaySE_20173184("E110_SE70");
        }
      }
      v232 = op_Equality(name, "01cam_01", 0);
      if (v232)
        goto LABEL_1272;
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.5;
      PShadow_CamZ = 23.0;
      v234 = 1119092736;
      goto LABEL_749;
    case 711:
      if (!op_Equality(name, "01cam_01", 0))
        goto LABEL_684;
      if (evtUpdateEx_CamRunTime != 150)
        goto LABEL_684;
      v237 = &"E111_SE70";
      goto LABEL_683;
    case 712:
      if (!op_Equality(name, "01cam_01", 0))
        goto LABEL_684;
      if (evtUpdateEx_CamRunTime != 60)
        goto LABEL_684;
      v237 = &"E112_SE70";
      goto LABEL_683;
    case 713:
      if (op_Equality(name, "01cam_01", 0))
      {
        if (evtUpdateEx_CamRunTime == 120)
        {
          p2sdPlaySE_20173184("E113_SE70");
        }
      }
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.5;
      v242 = 1102577664;
      goto LABEL_688;
    case 714:
      if (!op_Equality(name, "01cam_01", 0))
        goto LABEL_684;
      if (evtUpdateEx_CamRunTime != 60)
        goto LABEL_684;
      v237 = &"E114_SE70";
LABEL_683:
      p2sdPlaySE_20173184(*v237);
LABEL_684:
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.5;
      v242 = 1103101952;
LABEL_688:
      LODWORD(PShadow_CamZ) = v242;
      PShadow_RotX = 70.0;
      PShadow_RotY = 180.0;
      v245 = 0x40000000;
      goto LABEL_689;
    case 715:
      if (op_Equality(name, "01cam_01", 0))
      {
        if (evtUpdateEx_CamRunTime == 10)
        {
          p2sdPlaySE_20173184("E115_SE70");
        }
      }
      if (op_Equality(name, "01cam_08", 0))
      {
        if (!evtUpdateEx_CamRunTime)
        {
          fldSkySetAlphaOfs(-50);
        }
      }
      v251 = op_Equality(name, "01cam_03", 0);
      if (v251)
      {
        PShadow_CamX = 1.2;
        PShadow_CamY = 2.5;
        PShadow_CamZ = 22.5;
        PShadow_RotX = 70.0;
        PShadow_RotY = 180.0;
        v253 = 1060320051;
        goto LABEL_1220;
      }
      PShadow_CamX = 0.3;
      PShadow_CamY = 2.5;
      PShadow_CamZ = 23.0;
      PShadow_RotX = 70.0;
      PShadow_RotY = 180.0;
      v245 = 1069547520;
LABEL_689:
      LODWORD(PShadow_CamSize) = v245;
      PShadow_CamFar = 10.0;
      PShadow_Alp = 0.5;
      PShadow_OnOff = 1.0;
      if (!op_Equality(name, "01cam_01", 0))
        return 0;
        goto LABEL_1275;
      goto LABEL_1274;
    case 717:
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.5;
      PShadow_CamZ = 19.0;
      PShadow_RotX = 80.0;
      PShadow_RotY = 180.0;
      v163 = 1056964608;
      PShadow_CamSize = 0.5;
      goto LABEL_1138;
    case 718:
      if (op_Equality(name, "01cam_15", 0))
      {
        if (dds3FadeGetAlphaI() > 120.0)
        {
          BlurFilterBuff->abgr = -2139062144;
          BlurFilterBuff->blend = 1;
          dds3EffectFilter(&BlurFilterBuff, 0, 0);
        }
      }
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.5;
      PShadow_CamZ = 23.0;
      PShadow_RotX = 70.0;
      PShadow_RotY = 180.0;
      PShadow_CamSize = 2.0;
      PShadow_CamFar = 10.0;
      PShadow_Alp = 0.5;
      PShadow_OnOff = 1.0;
      if (!op_Equality(name, "01cam_01", 0)
        && !op_Equality(name, "01cam_02", 0)
        && !op_Equality(name, "01cam_03", 0)
        && !op_Equality(name, "01cam_04", 0)
        && !op_Equality(name, "01cam_05", 0)
        && !op_Equality(name, "01cam_06", 0))
      {
        return 0;
      }
LABEL_741:
        goto LABEL_1274;
      goto LABEL_1275;
    case 719:
      PShadow_CamX = 0.0;
      PShadow_CamY = 2.5;
      v258 = 1102577664;
      goto LABEL_748;
    case 723:
      if (!evtBitCheck(3712))
      {
        if (op_Equality(name, "camera01", 0))
        {
          PShadow_CamX = 0.0;
          PShadow_CamY = 8.0;
          PShadow_CamZ = 52.0;
          PShadow_RotX = 70.0;
          PShadow_RotY = 180.0;
          v342 = 1077936128;
LABEL_973:
          LODWORD(PShadow_CamSize) = v342;
          PShadow_CamFar = 10.0;
          goto LABEL_945;
        }
        if (op_Equality(name, "camera02", 0))
        {
          Postblur_AccumTex_NowMode = 1;
          goto LABEL_1275;
        }
        if (op_Equality(name, "camera03", 0)
          || op_Equality(name, "camera04", 0))
        {
          Postblur_AccumTex_NowMode = 1;
          PShadow_CamX = 6.0;
          PShadow_CamY = 8.0;
          PShadow_CamZ = 56.8;
          PShadow_RotX = 70.0;
          PShadow_RotY = 180.0;
LABEL_1219:
          v253 = 1075838976;
          goto LABEL_1220;
        }
        if (!op_Equality(name, "camera05", 0)
          && !op_Equality(name, "camera06", 0)
          && !op_Equality(name, "camera07", 0)
          && !op_Equality(name, "camera09", 0))
        {
          if (op_Equality(name, "camera08", 0))
          {
            v407 = evtUpdateEx_CamRunTime;
            if (v407 > 79)
            {
              PShadow_CamX = 0.0;
              PShadow_CamY = 8.0;
              PShadow_CamZ = 50.0;
              PShadow_RotX = 70.0;
              PShadow_RotY = 180.0;
              v368 = 0x40000000;
LABEL_1106:
              LODWORD(PShadow_CamSize) = v368;
              PShadow_CamFar = 10.0;
LABEL_378:
              v163 = 1050253722;
LABEL_379:
              LODWORD(PShadow_Alp) = v163;
              goto LABEL_380;
            }
            PShadow_CamX = 0.0;
            PShadow_CamY = 8.0;
            PShadow_CamZ = 40.0;
            PShadow_RotX = 70.0;
            PShadow_RotY = 180.0;
            v253 = 1077936128;
            goto LABEL_1220;
          }
          if (op_Equality(name, "cut01", 0))
          {
            PShadow_CamX = -1.2;
            PShadow_CamY = 8.2;
            PShadow_CamZ = 53.2;
            PShadow_RotX = 70.0;
            PShadow_RotY = 120.0;
            v415 = 1075838976;
          }
          else
          {
            if (!op_Equality(name, "cut02", 0)
              && !op_Equality(name, "cut03", 0)
              && !op_Equality(name, "cut05", 0))
            {
              if (op_Equality(name, "cut04", 0)
                || op_Equality(name, "cut06", 0))
              {
                PShadow_CamX = -0.5;
                PShadow_CamY = 8.2;
                PShadow_CamZ = 55.5;
                PShadow_RotX = 70.0;
                PShadow_RotY = 120.0;
                v342 = 1058642330;
                goto LABEL_973;
              }
              PShadow_CamX = 0.0;
              PShadow_CamY = 8.0;
              v258 = 1112276992;
LABEL_748:
              LODWORD(PShadow_CamZ) = v258;
              v234 = 1116471296;
LABEL_749:
              LODWORD(PShadow_RotX) = v234;
              PShadow_RotY = 180.0;
              v253 = 0x40000000;
LABEL_1220:
              LODWORD(PShadow_CamSize) = v253;
              PShadow_CamFar = 10.0;
LABEL_1221:
              v163 = 1056964608;
              goto LABEL_379;
            }
            PShadow_CamX = -1.0;
            PShadow_CamY = 8.2;
            PShadow_CamZ = 49.8;
            PShadow_RotX = 70.0;
            PShadow_RotY = 120.0;
            v415 = 1067030938;
          }
          LODWORD(PShadow_CamSize) = v415;
          PShadow_CamFar = 10.0;
          v193 = 1050253722;
          goto LABEL_946;
        }
LABEL_1059:
        {
LABEL_1273:
        }
LABEL_1275:
        PShadow_OnOff = 0.0;
        return 0;
      }
      evtUpdateEx_Dante_e730after = 1;
      if (op_Equality(name, "cam01", 0)
        || op_Equality(name, "cam02", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 8.6;
        PShadow_CamZ = 51.5;
        PShadow_RotX = 88.0;
        PShadow_RotY = 45.0;
        PShadow_CamSize = 3.0;
        PShadow_CamFar = 10.0;
        v193 = 1045220557;
LABEL_946:
        LODWORD(PShadow_Alp) = v193;
LABEL_947:
LABEL_948:
        PShadow_OnOff = 1.0;
LABEL_949:
        PShadow_YClipOnOff = 0.0;
        return 0;
      }
      if (op_Equality(name, "cam03", 0)
        || op_Equality(name, "cam04", 0)
        || op_Equality(name, "cam05", 0))
      {
        PShadow_CamX = -1.0;
        PShadow_CamY = 8.6;
        PShadow_CamZ = 47.6;
        PShadow_RotX = 80.0;
        PShadow_RotY = 45.0;
        PShadow_CamSize = 1.3;
        PShadow_CamFar = 10.0;
        PShadow_Alp = 0.2;
        PShadow_OnOff = 1.0;
        PShadow_YClipOnOff = 0.0;
        if (op_Equality(name, "cam05", 0))
        {
LABEL_264:
          PShadow_Alp = 0.1;
        }
      }
      return 0;
    case 726:
      if (op_Equality(evtUpdateEx_FieldName, "f726_001(Clone)", 0))
      {
        if (op_Equality(name, "cam04", 0))
        {
          PShadow_CamX = 0.0;
          PShadow_CamY = 3.0;
          PShadow_CamZ = 1.5;
          v265 = 1114636288;
LABEL_814:
          LODWORD(PShadow_RotX) = v265;
          PShadow_RotY = 180.0;
          goto LABEL_1184;
        }
        if (op_Equality(name, "cam05", 0))
          goto LABEL_1059;
        v383 = op_Equality(name, "cam10", 0);
        if (!v383)
        {
          PShadow_CamX = 0.0;
          PShadow_CamY = 3.0;
          PShadow_CamZ = -0.8;
          PShadow_RotX = 85.0;
          PShadow_RotY = 0.0;
          PShadow_CamSize = 1.2;
          PShadow_CamFar = 10.0;
          v163 = 1061997773;
          goto LABEL_379;
        }
        {
LABEL_1183:
          PShadow_CamX = 0.0;
          PShadow_CamY = 3.0;
          PShadow_CamZ = -2.0;
          PShadow_RotX = 50.0;
          PShadow_RotY = 0.0;
LABEL_1184:
          PShadow_CamSize = 1.0;
LABEL_1185:
          PShadow_CamFar = 10.0;
          v122 = 1061997773;
          goto LABEL_271;
        }
      }
      else
      {
        if (!op_Equality(name, "cam10", 0)
          && !op_Equality(name, "cam00", 0)
          && !op_Equality(name, "cam02", 0))
        {
          PShadow_CamX = 0.0;
          PShadow_CamY = 3.0;
          PShadow_CamZ = 1.0;
          PShadow_RotX = 50.0;
          PShadow_RotY = 180.0;
          PShadow_CamSize = 1.5;
          goto LABEL_1185;
        }
          goto LABEL_1183;
      }
      goto LABEL_1183;
    case 728:
      if (evtBitCheck(3712))
      {
        if (!op_Equality(name, "01cam_02", 0))
          goto LABEL_1059;
        v267 = evtUpdateEx_CamRunTime;
        if (v267 <= 99)
        {
          v163 = 1056964608;
          PShadow_CamX = 0.5;
          PShadow_CamY = 3.0;
          PShadow_CamZ = 2.0;
        }
        else
        {
          v163 = 1056964608;
          PShadow_CamX = 0.5;
          PShadow_CamY = 3.0;
          PShadow_CamZ = 0.0;
        }
        PShadow_RotX = 80.0;
        PShadow_RotY = 230.0;
        v350 = 1075838976;
        goto LABEL_1137;
      }
      if (!op_Equality(name, "01cam_01", 0))
      {
        if (!op_Equality(name, "01cam_04", 0)
          && !op_Equality(name, "01cam_08", 0)
          && !op_Equality(name, "01cam_07", 0))
        {
          goto LABEL_1059;
        }
        PShadow_CamX = 0.5;
        PShadow_CamY = 3.0;
        PShadow_CamZ = -1.5;
        PShadow_RotX = 65.0;
        PShadow_RotY = -20.0;
        v368 = 1075838976;
        goto LABEL_1106;
      }
      v346 = evtUpdateEx_CamRunTime;
      if (v346 > 179)
      {
        if (PShadow_Alp < 0.3)
        {
          PShadow_Alp = PShadow_Alp + 0.02;
        }
        PShadow_CamX = 0.5;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 2.5;
        PShadow_RotX = 80.0;
        PShadow_RotY = 280.0;
        PShadow_CamSize = 2.0;
        PShadow_CamFar = 10.0;
        goto LABEL_380;
      }
      PShadow_OnOff = 0.0;
      PShadow_Alp = 0.0;
      return 0;
    case 729:
      evtBitCheck(3712);
      v268 = op_Equality(name, "01cam_01", 0);
      if (!v268)
        goto LABEL_1272;
      PShadow_CamX = 0.0;
      PShadow_CamY = 3.0;
      PShadow_CamZ = 3.0;
      v270 = 1114636288;
      goto LABEL_1218;
    case 730:
      v271 = evtBitCheck(3712);
      v272 = op_Equality(name, "01cam_00", 0);
      if (v271)
      {
        if (!v272)
        {
          if (op_Equality(name, "01cam_02", 0))
          {
            v276 = evtUpdateEx_CamRunTime;
            if (v276 <= 119)
            {
              v277 = -11.0;
              {
LABEL_1214:
                PShadow_CamX = v277;
LABEL_1217:
                PShadow_CamY = 2.0;
                PShadow_CamZ = 2.0;
                v270 = 1117782016;
LABEL_1218:
                LODWORD(PShadow_RotX) = v270;
                PShadow_RotY = 0.0;
                goto LABEL_1219;
              }
            }
            else
            {
              v277 = -9.0;
                goto LABEL_1214;
            }
            goto LABEL_1214;
          }
          if (!op_Equality(name, "01cam_14", 0))
          {
            v377 = op_Equality(name, "01cam_13", 0);
            if (!v377)
              goto LABEL_1272;
            PShadow_CamX = -9.0;
            goto LABEL_1217;
          }
LABEL_1198:
          PShadow_CamX = -8.0;
          PShadow_CamY = 2.0;
          PShadow_CamZ = 2.4;
          PShadow_RotX = 80.0;
          PShadow_RotY = 0.0;
          v284 = 1060320051;
LABEL_808:
          LODWORD(PShadow_CamSize) = v284;
          PShadow_CamFar = 10.0;
LABEL_1087:
          v163 = 1045220557;
          goto LABEL_379;
        }
LABEL_998:
        v163 = 1056964608;
        PShadow_CamX = 0.5;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 3.0;
        PShadow_RotX = 60.0;
        PShadow_RotY = 270.0;
        v350 = 0x40000000;
LABEL_1137:
        LODWORD(PShadow_CamSize) = v350;
LABEL_1138:
        PShadow_CamFar = 10.0;
        goto LABEL_379;
      }
      if (v272)
        goto LABEL_998;
      if (!op_Equality(name, "01cam_02", 0))
      {
        if (op_Equality(name, "01cam_14", 0))
          goto LABEL_1198;
        v392 = op_Equality(name, "01cam_13", 0);
        if (!v392)
          goto LABEL_1272;
        PShadow_CamX = -9.0;
LABEL_1271:
        v253 = 0x40000000;
        PShadow_CamY = 2.0;
        PShadow_CamZ = 2.0;
        PShadow_RotX = 80.0;
        PShadow_RotY = 0.0;
        goto LABEL_1220;
      }
      v371 = evtUpdateEx_CamRunTime;
      if (v371 <= 119)
      {
        v372 = -11.0;
        {
LABEL_1259:
          PShadow_CamX = v372;
          goto LABEL_1271;
        }
      }
      else
      {
        v372 = -9.0;
          goto LABEL_1259;
      }
      goto LABEL_1259;
    case 731:
      if (evtBitCheck(3712))
        goto LABEL_1059;
      if (op_Equality(name, "01cam_02", 0))
      {
        PShadow_CamX = -0.3;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 1.3;
        PShadow_RotX = 70.0;
        PShadow_RotY = 140.0;
        v280 = 1076258406;
      }
      else
      {
        v362 = op_Equality(name, "01cam_06", 0);
        if (!v362)
          goto LABEL_1272;
        PShadow_CamX = -0.4;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 0.0;
        PShadow_RotX = 70.0;
        PShadow_RotY = 140.0;
        v280 = 1080033280;
      }
      goto LABEL_841;
    case 740:
      {
      }
      if (op_Equality(name, "01cam_01", 0))
      {
        PShadow_CamX = -1.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = -4.0;
        PShadow_RotX = 50.0;
        PShadow_RotY = 140.0;
        v284 = 0x40000000;
        goto LABEL_808;
      }
      if (op_Equality(name, "01cam_02", 0)
        || op_Equality(name, "01cam_03", 0)
        || op_Equality(name, "01cam_04", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 3.0;
        v293 = -1063256064;
        goto LABEL_1009;
      }
      if (!op_Equality(name, "01cam_07", 0)
        && !op_Equality(name, "01cam_10", 0))
      {
        goto LABEL_1059;
      }
      PShadow_CamX = -1.2;
      PShadow_CamY = 3.0;
      PShadow_CamZ = -4.3;
      PShadow_RotX = 20.0;
      PShadow_RotY = 15.0;
      v280 = 1068708659;
      goto LABEL_841;
    case 741:
      if (!op_Equality(name, "01cam_05", 0))
        goto LABEL_1059;
      v285 = Find("player_tatoo_e741", 0);
      v286 = get_transform(v285, 0);
      position = get_position(v286);
      v287 = get_transform(v285, 0);
      v433.y = -0.1;
      v433.x = position.x;
      v433.z = position.z;
      set_position(v287, v433);
      v288 = Find("p_a_skin", 0);
      v289 = get_transform(v288, 0);
      v419 = get_position(v289).z;
      v290 = v419;
      PShadow_CamX = 3.0;
      PShadow_CamY = 3.0;
      PShadow_CamZ = v290 + -3.0;
      v265 = 1109393408;
      goto LABEL_814;
    case 743:
      if (op_Equality(name, "01cam_02", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 3.0;
        v293 = -1071644672;
LABEL_1009:
        LODWORD(PShadow_CamZ) = v293;
        v301 = 1117782016;
        goto LABEL_1010;
      }
      v352 = op_Equality(name, "01cam_07", 0);
      if (!v352)
        goto LABEL_1272;
      PShadow_CamX = -1.5;
      PShadow_CamY = 3.0;
      PShadow_CamZ = -2.0;
      PShadow_RotX = 50.0;
      v296 = 1117782016;
LABEL_834:
      LODWORD(PShadow_RotY) = v296;
      goto LABEL_1011;
    case 744:
      v294 = op_Equality(name, "01cam_02", 0);
      if (!v294)
        goto LABEL_1272;
      PShadow_CamX = -1.0;
      PShadow_CamY = 3.0;
      PShadow_CamZ = -7.4;
      PShadow_RotX = 60.0;
      v296 = 1110704128;
      goto LABEL_834;
    case 745:
      v297 = op_Equality(name, "01cam_04", 0);
      if (!v297)
        goto LABEL_1272;
      PShadow_CamX = -1.5;
      PShadow_CamY = 3.0;
      PShadow_CamZ = -6.5;
      PShadow_RotX = 60.0;
      v296 = 1119092736;
      goto LABEL_834;
    case 746:
      PShadow_CamX = 1.5;
      PShadow_CamY = 3.0;
      PShadow_CamZ = -3.0;
      PShadow_RotX = 60.0;
      v296 = -1036779520;
      goto LABEL_834;
    case 747:
      if (op_Equality(name, "01cam_02", 0)
        || op_Equality(name, "01cam_03", 0))
      {
        PShadow_CamX = -0.5;
        PShadow_CamY = 3.0;
        PShadow_CamZ = 6.0;
        PShadow_RotX = 70.0;
        PShadow_RotY = 0.0;
        v280 = 1067030938;
      }
      else
      {
        if (op_Equality(name, "01cam_04", 0))
        {
          PShadow_CamX = 1.0;
          PShadow_CamY = 5.0;
          PShadow_CamZ = 2.0;
          PShadow_RotX = 70.0;
          PShadow_RotY = 0.0;
          PShadow_CamSize = 4.5;
LABEL_1012:
          PShadow_CamFar = 10.0;
LABEL_1013:
          v122 = 1053609165;
LABEL_271:
          LODWORD(PShadow_Alp) = v122;
LABEL_413:
          goto LABEL_414;
        }
        v384 = op_Equality(name, "01cam_06", 0);
        if (!v384)
        {
LABEL_1272:
          if ((v191 & 0x200) != 0)
            goto LABEL_1273;
          goto LABEL_1275;
        }
        PShadow_CamX = 0.0;
        PShadow_CamY = 5.0;
        PShadow_CamZ = 12.0;
        PShadow_RotX = 60.0;
        PShadow_RotY = 0.0;
        v280 = 0x40000000;
      }
LABEL_841:
      LODWORD(PShadow_CamSize) = v280;
      PShadow_CamFar = 10.0;
      goto LABEL_1241;
    case 748:
      if (op_Equality(name, "01cam_07", 0))
      {
        PShadow_CamX = 0.0;
        PShadow_CamY = 3.0;
        PShadow_CamZ = -8.0;
        v301 = 1116471296;
LABEL_1010:
        LODWORD(PShadow_RotX) = v301;
        PShadow_RotY = 0.0;
LABEL_1011:
        PShadow_CamSize = 1.0;
        goto LABEL_1012;
      }
      v353 = op_Equality(name, "01cam_08", 0);
      if (!v353)
        goto LABEL_1272;
      PShadow_CamX = -1.5;
      PShadow_CamY = 3.0;
      PShadow_CamZ = -9.0;
      PShadow_RotX = 50.0;
      PShadow_RotY = 45.0;
      PShadow_CamSize = 1.0;
      PShadow_CamFar = 10.0;
      goto LABEL_1255;
    case 749:
      if (!op_Equality(name, "01cam_10", 0)
        && !op_Equality(name, "01cam_11", 0)
        && !op_Equality(name, "01cam_02", 0)
        && !op_Equality(name, "01cam_06", 0))
      {
        goto LABEL_1059;
      }
      v302 = Find("p_a_skin", 0);
      v303 = get_transform(v302, 0);
      v421 = get_position(v303).z;
      v304 = v421;
      PShadow_CamX = 0.5;
      PShadow_CamY = 3.0;
      PShadow_CamZ = v304 + 1.0;
      PShadow_RotX = 70.0;
      v306 = 1130102784;
      goto LABEL_869;
    default:
      if (v95 != 750)
        return 0;
      if (op_Equality(name, "01cam_07", 0))
      {
        Postblur_blur_a = Postblur_blur_a * 0.5;
      }
      v310 = Find("p_a_skin", 0);
      if (!op_Inequality(v310, 0, 0))
        goto LABEL_1059;
      v311 = get_transform(v310, 0);
      v423 = get_position(v311).z;
      v312 = v423;
      PShadow_CamX = 0.0;
      PShadow_CamY = 4.0;
      PShadow_CamZ = v312 + 1.0;
      PShadow_RotX = 70.0;
      v306 = 1127481344;
LABEL_869:
      LODWORD(PShadow_RotY) = v306;
      PShadow_CamSize = 1.0;
      PShadow_CamFar = 10.0;
      v122 = 1058642330;
      goto LABEL_271;
  }
}

// 0x100e8b0
void fldEve_BloomDof_AfterEnd(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;

  else
  {
    if (FldEve_Bloom_Idx != -1)
      goto LABEL_13;
  }
  else if (FldEve_Dof_Idx == -1)
  {
    return;
  }
LABEL_13:
  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  fldPPSV2_Set(fieldID, areaID + 1);
}

// 0x100e9d0
void fldEve_BloomDof_Set(void) {
  System_String_o *name;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  System_String_o *ScriptProcName;
  s32 v9;
  u64 v11;
  char v12;
  struct dds3UnityEx_FldEve_Bloom_array *Tbl_FldEve_BloomDof;
  u64 max_length_low;
  struct dds3UnityEx_FldEve_Bloom_array *v17;
  struct dds3UnityEx_FldEve_Bloom_array *v20;
  struct dds3UnityEx_FldEve_Bloom_array *v23;
  struct dds3UnityEx_FldEve_Bloom_array *v26;
  struct dds3UnityEx_FldEve_Bloom_array *v29;
  struct dds3UnityEx_FldEve_Bloom_array *v32;
  bool v34;
  struct dds3UnityEx_FldEve_Bloom_array *v37;
  UnityEngine_Object_o *v40;
  struct dds3UnityEx_FldEve_Bloom_array *v41;
  bool v43;
  struct dds3UnityEx_FldEve_Bloom_array *v47;
  struct dds3UnityEx_FldEve_Bloom_array *v51;
  struct dds3UnityEx_FldEve_Bloom_array *v54;
  f32 blur_pow;
  struct dds3UnityEx_FldEve_Bloom_array *v58;
  struct dds3UnityEx_FldEve_Bloom_array *v61;
  struct dds3UnityEx_FldEve_Bloom_array *v64;
  u32 max_length;
  struct dds3UnityEx_FldEve_Bloom_array *v66;
  f32 dofa;
  f32 dofb;
  f32 dofc;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  name = "";
  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  ScriptProcName = dds3GetScriptProcName();
  v9 = areaID + 1;
  pBasic = dds3GetActiveScene();
  if (pBasic)
  {
    name = dds3GetActiveCameraSceneBasic(&pBasic)->name;
  }
  v11 = 0;
  v12 = 0;
  {
LABEL_20:
  }
  while (1)
  {
    max_length_low = LODWORD(Tbl_FldEve_BloomDof->max_length);
    if (v11 >= max_length_low)
      break;
    else if (v11 >= max_length_low)
    {
      goto LABEL_26;
    }
    if (Tbl_FldEve_BloomDof->m_Items[v11]->fld > fieldID)
      break;
    v17 = Tbl_FldEve_BloomDof;
    if (v17->m_Items[v11]->fld != fieldID)
      goto LABEL_19;
    v20 = Tbl_FldEve_BloomDof;
    if (v20->m_Items[v11]->area != v9)
      goto LABEL_19;
    v23 = Tbl_FldEve_BloomDof;
    if (!op_Equality(v23->m_Items[v11]->jyoken_scr, ScriptProcName, 0))
      goto LABEL_19;
    v26 = Tbl_FldEve_BloomDof;
    if (!op_Equality(v26->m_Items[v11]->jyoken_cam, "", 0))
    {
      v29 = Tbl_FldEve_BloomDof;
      if (!op_Equality(v29->m_Items[v11]->jyoken_cam, name, 0))
        goto LABEL_19;
    }
    v32 = Tbl_FldEve_BloomDof;
    if (op_Equality(v32->m_Items[v11]->jyoken_npc, "", 0))
    {
      v34 = 1;
        goto LABEL_78;
LABEL_65:
      goto LABEL_78;
    }
    v37 = Tbl_FldEve_BloomDof;
    v40 = Find(v37->m_Items[v11]->jyoken_npc, 0);
    v34 = op_Inequality(v40, 0, 0);
      goto LABEL_65;
LABEL_78:
    v41 = Tbl_FldEve_BloomDof;
    v43 = v41->m_Items[v11]->bloom_type == 0;
    v12 |= v43;
    if (v34)
    {
      if (FldEve_Bloom_Idx != v11)
      {
        v47 = Tbl_FldEve_BloomDof;
        if (v47->m_Items[v11]->bloom_type)
        {
          FldEve_Bloom_Idx = v11;
          PPSV2_update = 1;
          v51 = Tbl_FldEve_BloomDof;
          PPSV2_bloom_type = v51->m_Items[v11]->bloom_type;
        }
      }
      v54 = Tbl_FldEve_BloomDof;
      blur_pow = v54->m_Items[v11]->blur_pow;
      FldEve_Blur_Pow(blur_pow);
      v58 = Tbl_FldEve_BloomDof;
      if (v58->m_Items[v11]->dof_ow)
      {
        v61 = Tbl_FldEve_BloomDof;
        if (v61->m_Items[v11]->dof_ow >= 1)
        {
          FldEve_Dof_Idx = v11;
          v64 = Tbl_FldEve_BloomDof;
          max_length = v64->max_length;
          v66 = Tbl_FldEve_BloomDof;
          dofa = v64->m_Items[v11]->dofa;
          dofb = v66->m_Items[v11]->dofb;
          dofc = v66->m_Items[v11]->dofc;
          DofSet(dofa, dofb, dofc);
        }
        return;
      }
      goto LABEL_136;
    }
LABEL_19:
    ++v11;
      goto LABEL_20;
  }
  if (!(v12 & 1 | (FldEve_Bloom_Idx == -1)))
  {
    fldPPSV2_Set(fieldID, v9);
  }
  if (op_Equality(name, "P_Cam", 0))
  {
LABEL_136:
    DofOff();
  }
}

// 0x100e830
void fldEve_Bloom_Init(void) {
  FldEve_Bloom_Idx = -1;
  FldEve_Dof_Idx = -1;
}

// 0x100d960
void fldEventUpdateEx_Unity(s32 fld, s32 area, char *scr_label, char *cam_name) {
  UnityEngine_GameObject_o *v10;
  Il2CppObject *v12;
  UnityEngine_GameObject_o *v14;
  Il2CppObject *v16;
  UnityEngine_GameObject_o *v18;
  Il2CppObject *v20;
  UnityEngine_GameObject_o *v22;
  Il2CppObject *v25;
  s32 v28;
  UnityEngine_GameObject_o *v32;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v35;
  UnityEngine_GameObject_o *v38;
  UnityEngine_Transform_o *v39;
  UnityEngine_Transform_o *v40;
  s32 v46;
  UnityEngine_GameObject_o *v51;
  Il2CppObject *Component_object;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v66;
  UnityEngine_Vector3_o v67;
  UnityEngine_Vector3_o v68;

  if (!scr_label || !cam_name)
    return;
  if (fld != 15 || area != 12)
  {
    if (fld == 15 && area == 20)
    {
      if (op_Equality(scr_label, "020_start", 0) && !evtBitCheck(3712))
      {
        PShadow2_Alp = 0.0;
        PShadow2_OnOff = 0.0;
        if (op_Equality(cam_name, "01cam_10", 0))
        {
          v32 = Find("raidou@f015", 0);
          if (op_Inequality(v32, 0, 0))
          {
            transform = get_transform(v32, 0);
            localPosition = get_localPosition(transform);
            v35 = get_transform(v32, 0);
            v67.y = -0.043;
            v67.x = localPosition.x;
            v67.z = localPosition.z;
            set_localPosition(v35, v67);
          }
          PShadow2_CamX = -0.2;
          PShadow2_CamY = 5.66;
          PShadow2_CamZ = 2.8;
          PShadow2_RotX = 80.0;
          PShadow2_RotY = 90.0;
          PShadow2_CamSize = 0.25;
          PShadow2_Alp = 0.2;
          PShadow2_OnOff = 1.0;
        }
        if (op_Equality(cam_name, "01cam_11", 0))
        {
          v38 = Find("raidou@f015", 0);
          if (op_Inequality(v38, 0, 0))
          {
            v39 = get_transform(v38, 0);
            v66 = get_localPosition(v39);
            v40 = get_transform(v38, 0);
            v68.y = 0.0;
            v68.x = v66.x;
            v68.z = v66.z;
            set_localPosition(v40, v68);
          }
        }
      }
      if (!op_Equality(scr_label, "020_start", 0) || !evtBitCheck(3712))
        return;
      PShadow2_Alp = 0.0;
      PShadow2_OnOff = 0.0;
      if (!op_Equality(cam_name, "01cam_10", 0))
        return;
      PShadow2_CamX = 0.5;
      PShadow2_CamY = 5.66;
      PShadow2_CamZ = 3.9;
      PShadow2_RotX = 70.0;
      PShadow2_RotY = 200.0;
      PShadow2_CamSize = 0.3;
      v46 = 1045220557;
    }
    else
    {
      if (fld != 20 || area != 8)
      {
        if (fld == 20 && area == 21)
        {
          if (op_Equality(scr_label, "021_start", 0)
            && op_Equality(cam_name, "01cam_01", 0))
          {
            PShadow2_Alp = 0.0;
            PShadow2_OnOff = 0.0;
          }
          return;
        }
        if (fld == 22 && area == 9)
        {
          if (op_Equality(scr_label, "009_start", 0)
            && (op_Equality(cam_name, "01cam_19", 0)
             || op_Equality(cam_name, "01cam_20", 0)))
          {
            v51 = Find("npc_mane_b_7", 0);
            if (op_Inequality(v51, 0, 0))
            {
              Component_object = GetComponent_object_(v51);
              {
              }
              if (op_Inequality(Component_object, 0, 0))
                SetLayerAll2(Component_object, v51, 13);
            }
            PShadow_CamX = 4.0;
            PShadow_CamY = 2.0;
            PShadow_CamZ = 26.0;
            PShadow_RotX = 80.0;
            PShadow_RotY = 0.0;
            PShadow_CamSize = 2.0;
            PShadow_CamFar = 10.0;
            PShadow_Alp = 0.2;
            PShadow_OnOff = 1.0;
            fldSdwDraw_Skep1();
          }
          return;
        }
        if (fld == 24 && area == 8)
        {
          if (op_Equality(scr_label, "008_01eve_08", 0)
            && op_Equality(cam_name, "01cam_07", 0))
          {
            PShadow_CamX = -15.0;
            PShadow_CamY = 3.0;
            PShadow_CamZ = -1.0;
            PShadow_RotX = 70.0;
            PShadow_RotY = -20.0;
            PShadow_CamSize = 1.2;
            PShadow_CamFar = 10.0;
            PShadow_Alp = 0.2;
            PShadow_OnOff = 1.0;
            PShadow2_CamX = -10.0;
            PShadow2_CamY = 4.0;
            PShadow2_CamZ = 0.0;
            PShadow2_RotX = 70.0;
            PShadow2_RotY = 90.0;
            PShadow2_CamSize = 4.0;
            PShadow2_Alp = 0.2;
            PShadow2_OnOff = 1.0;
          }
          return;
        }
        if (area == 14 && fld == 24)
        {
          if (!op_Equality(scr_label, "014_start", 0))
            return;
          PShadow2_CamX = -20.0;
          PShadow2_CamY = 3.0;
          PShadow2_CamZ = 28.0;
          PShadow2_RotX = 60.0;
        }
        else
        {
          if (fld != 35 || area != 10)
            return;
          if (!op_Equality(scr_label, "010_01eve_01", 0))
          {
            if (op_Equality(scr_label, "010_yogen_tar", 0))
            {
              PShadow2_CamX = 0.7;
              PShadow2_CamY = 3.0;
              PShadow2_CamZ = 25.5;
              PShadow2_RotX = 60.0;
              PShadow2_RotY = 250.0;
              v28 = 1070386381;
              goto LABEL_50;
            }
            return;
          }
          if (op_Equality(cam_name, "01cam_05", 0))
          {
            PShadow2_RotY = 80.0;
          }
          if (!op_Equality(cam_name, "01cam_08", 0))
            return;
          PShadow2_CamX = -1.0;
          PShadow2_CamY = 3.0;
          PShadow2_CamZ = 25.0;
          PShadow2_RotY = 60.0;
        }
        PShadow2_RotY = 40.0;
        v28 = 1067030938;
LABEL_50:
        LODWORD(PShadow2_CamSize) = v28;
        return;
      }
      if (!op_Equality(scr_label, "008_start", 0))
        return;
      PShadow2_CamX = 2.2;
      PShadow2_CamY = 6.0;
      PShadow2_CamZ = -14.0;
      PShadow2_RotX = 80.0;
      PShadow2_RotY = 220.0;
      PShadow2_CamSize = 2.5;
      v46 = 1050253722;
    }
    LODWORD(PShadow2_Alp) = v46;
    PShadow2_OnOff = 1.0;
    return;
  }
  if (op_Equality(scr_label, "012_start", 0))
  {
    if (op_Equality(cam_name, "01cam_04", 0))
    {
      v10 = Find("devil_0x83_1", 0);
      if (op_Inequality(v10, 0, 0))
      {
        v12 = GetComponent_object_(v10);
        if (op_Inequality(v12, 0, 0))
          SetLayerAll2(v12, v10, 14);
      }
      v14 = Find("devil_0x83_2", 0);
      if (op_Inequality(v14, 0, 0))
      {
        v16 = GetComponent_object_(v14);
        if (op_Inequality(v16, 0, 0))
          SetLayerAll2(v16, v14, 14);
      }
    }
    if (op_Equality(cam_name, "01cam_08", 0))
    {
      v18 = Find("devil_0x83_1", 0);
      if (op_Inequality(v18, 0, 0))
      {
        v20 = GetComponent_object_(v18);
        if (op_Inequality(v20, 0, 0))
          SetLayerAll2(v20, v18, 15);
      }
      v22 = Find("devil_0x83_2", 0);
      if (op_Inequality(v22, 0, 0))
      {
        v25 = GetComponent_object_(v22);
        if (op_Inequality(v25, 0, 0))
          SetLayerAll2(v25, v22, 15);
      }
      v28 = 1080033280;
      goto LABEL_50;
    }
  }
}

// 0x100f360
void fldEventUpdateEx_Unity_2(void) {
  System_String_o *name;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  System_String_o *ScriptProcName;
  s32 v9;
  _BOOL4 v13;
  s64 *v16;
  s32 v18;
  struct System_Int32_array *pm;
  struct System_Int32_array *v25;
  dds3Effect_PartialMultiFilterParam_t_o *BlurMultiFilter_Param;
  struct dds3Effect_PartialMultiFilter_t_o *v28;
  s32 v34;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  name = "";
  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  ScriptProcName = dds3GetScriptProcName();
  v9 = areaID + 1;
  pBasic = dds3GetActiveScene();
  if (pBasic)
  {
    name = dds3GetActiveCameraSceneBasic(&pBasic)->name;
  }
  if (fieldID == 25 && v9 == 9)
  {
    if (op_Equality(ScriptProcName, "009_start", 0)
      && evtBitCheck(1434)
      && !evtBitCheck(1435))
    {
      v18 = 38817800;
      goto LABEL_138;
    }
    return;
  }
  if (fieldID == 25 && v9 == 6)
  {
    if (op_Equality(ScriptProcName, "006_start", 0) && !evtBitCheck(1415))
    {
      v18 = 38821889;
      goto LABEL_138;
    }
    return;
  }
  v13 = areaID == 0;
  if (fieldID == 42 && areaID == 0)
  {
    if (op_Equality(ScriptProcName, "001_01eve_04", 0))
    {
      if (op_Equality(name, "01cam_13", 0))
      {
        BlurMultiFilter_Param->Filter->blend = 2;
        BlurMultiFilter_Param->Filter->abgr = 1346388032;
        BlurMultiFilter_Param->area = 488;
        pm = BlurMultiFilter_Param->center->pm;
        pm->m_Items[0] = -480;
        v25 = BlurMultiFilter_Param->center->pm;
        v25->m_Items[1] = -540;
        v28 = dds3EffectPartialMultiFilterCreate(BlurMultiFilter_Param);
        BlurMultiFilterBuff = v28;
        dds3EffectPartialMultiFilterDraw(&BlurMultiFilterBuff);
        return;
      }
      if (op_Equality(name, "01cam_14", 0))
      {
        BlurFilterBuff->abgr = 272646208;
        BlurFilterBuff->blend = 1;
        dds3EffectFilter(&BlurFilterBuff, 0, 0);
        return;
      }
    }
    v34 = 0;
    v13 = 1;
    if ((fieldID - 41) > 4)
      goto LABEL_122;
  }
  else
  {
    if (fieldID == 37 && v9 == 7)
    {
      if (!op_Equality(ScriptProcName, "007_01eve_05", 0))
      {
        if (!op_Equality(ScriptProcName, "007_THOR_AFTER", 0))
          return;
        if (evtUpdateEx_ArkOpen_F037_07_THOR_AFTER_Dead)
        {
          v18 = 57700354;
        }
        else
        {
          v18 = 57700353;
        }
        goto LABEL_138;
      }
      evtUpdateEx_ArkOpen_F037_07_THOR_AFTER_Dead = 0;
      return;
    }
    if (fieldID == 41 && areaID == 10)
    {
      v16 = &"011_01eve_01";
      goto LABEL_36;
    }
    if (fieldID == 43)
    {
      if (areaID == 5
        && (op_Equality(ScriptProcName, "006_01eve_01", 0)
         || op_Equality(ScriptProcName, "006_01eve_02", 0)))
      {
        goto LABEL_37;
      }
      if (areaID != 6)
        goto LABEL_121;
      if (op_Equality(ScriptProcName, "007_01eve_01", 0))
        goto LABEL_37;
      v16 = &"007_01eve_02";
LABEL_36:
      if (op_Equality(ScriptProcName, *v16, 0))
      {
LABEL_37:
        if (op_Equality(name, "P_Cam", 0))
        {
          dds3EffectDistortionBlur_SetFldEventCntF(0.0);
        }
        v18 = 67137539;
LABEL_138:
        dds3EffectDistortionBlur_SetFldEvent(v18);
        return;
      }
LABEL_121:
      v34 = 0;
      if ((fieldID - 41) > 4)
        goto LABEL_122;
      goto LABEL_93;
    }
    if (fieldID == 44 && areaID == 27)
    {
      v16 = &"028_01eve_01";
      goto LABEL_36;
    }
    if (fieldID != 45)
      goto LABEL_121;
    if (areaID == 7
      && (op_Equality(ScriptProcName, "008_01eve_01", 0)
       || op_Equality(ScriptProcName, "008_01eve_02", 0)))
    {
      goto LABEL_37;
    }
    v34 = 1;
  }
LABEL_93:
  if (v13 && op_Equality(ScriptProcName, "001_01eve_01", 0))
  {
    if (op_Equality(name, "P_Cam", 0))
    {
      dds3EffectDistortionBlur_SetFldEventCntF(0.0);
    }
    v18 = 67137542;
    goto LABEL_138;
  }
LABEL_122:
  if ((fieldID - 43) <= 1 && op_Equality(ScriptProcName, "warp_label", 0))
  {
    dds3EffectDistortionBlur_SetFldEvent(67137543);
  }
  if (!((v9 != 29) | (v34 ^ 1) & 1) && op_Equality(ScriptProcName, "029start", 0))
  {
    v18 = 72519689;
    goto LABEL_138;
  }
}

// 0x100fb60
char *fldEvent_GetCameraName(void) {
  System_String_o *result;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  result = dds3GetActiveScene();
  pBasic = result;
  if (result)
  {
    return dds3GetActiveCameraSceneBasic(&pBasic)->name;
  }
  return result;
}

// 0x1801a90
void fldLoad_BasicLightLoadAfter(s32 fld_id, s32 area_id, fldResourceLight_t **pLight, sdfVector4_t *pos, char *name) {
  System_String_o *v10;
  System_Object_array *v12;
  System_Object_array *v13;
  s64 *v15;
  s64 *v16;
  s64 *v19;
  s64 *v20;
  s64 *v23;
  s64 *v24;
  System_String_o *v26;
  System_Object_array *v27;
  System_Object_array *v28;
  s64 *v30;
  s64 *v31;
  s64 *v34;
  s64 *v35;
  s64 *v38;
  s64 *v39;
  System_String_o *v41;
  System_Object_array *v42;
  System_Object_array *v43;
  s32 v45;
  s64 *v46;
  s64 *v47;
  s32 v50;
  s64 *v51;
  s64 *v52;
  s32 v55;
  s64 *v56;
  s64 *v57;
  System_String_o *v59;
  System_Object_array *v60;
  fldResourceLight_t_o *v61;
  s32 v62;
  fldResourceLight_t_o *v63;
  f32 v64;
  f32 v65;
  f32 v66;
  f32 v67;
  f32 v68;
  f32 v69;
  f32 v70;
  f32 v71;
  f32 v72;
  fldResourceLight_t_o *v73;
  f32 v74;
  fldResourceLight_t_o *v93;
  fldResourceLight_t_o *v94;
  f32 v95;
  f32 v96;
  f32 v97;
  fldResourceLight_t_o *v98;
  s32 v99;
  s32 v101;
  s32 v102;
  s32 v103;
  f32 AmbientB;
  f32 AmbientG;
  f32 AmbientR;
  f32 DiffuseB;
  f32 DiffuseG;
  f32 DiffuseR;

  v10 = Concat_5224608("★★★配置ライト:", name);
  v12 = Empty_string_();
  Log(v10, v12, 0);
  v13 = NewSpecific(object, 6u);
  v13->m_Items[0] = "★★★DiffuseRGB :";
  DiffuseR = (*pLight)->DiffuseR;
  v15 = sub_8D3950(f32, &DiffuseR);
  v16 = v15;
  v13->m_Items[1] = v16;
  v13->m_Items[2] = " , ";
  DiffuseG = (*pLight)->DiffuseG;
  v19 = sub_8D3950(f32, &DiffuseG);
  v20 = v19;
  v13->m_Items[3] = v20;
  v13->m_Items[4] = " , ";
  DiffuseB = (*pLight)->DiffuseB;
  v23 = sub_8D3950(f32, &DiffuseB);
  v24 = v23;
  v13->m_Items[5] = v24;
  v26 = Concat_5270224(v13);
  v27 = Empty_string_();
  Log(v26, v27, 0);
  v28 = NewSpecific(object, 6u);
  v28->m_Items[0] = "★★★AmbientRGB :";
  AmbientR = (*pLight)->AmbientR;
  v30 = sub_8D3950(f32, &AmbientR);
  v31 = v30;
  v28->m_Items[1] = v31;
  v28->m_Items[2] = " , ";
  AmbientG = (*pLight)->AmbientG;
  v34 = sub_8D3950(f32, &AmbientG);
  v35 = v34;
  v28->m_Items[3] = v35;
  v28->m_Items[4] = " , ";
  AmbientB = (*pLight)->AmbientB;
  v38 = sub_8D3950(f32, &AmbientB);
  v39 = v38;
  v28->m_Items[5] = v39;
  v41 = Concat_5270224(v28);
  v42 = Empty_string_();
  Log(v41, v42, 0);
  v43 = NewSpecific(object, 6u);
  v43->m_Items[0] = "★★★POS        :";
  sub_854710(pos, 0);
  v103 = v45;
  v46 = sub_8D3950(f32, &v103);
  v47 = v46;
  v43->m_Items[1] = v47;
  v43->m_Items[2] = " , ";
  sub_854710(pos, 1u);
  v102 = v50;
  v51 = sub_8D3950(f32, &v102);
  v52 = v51;
  v43->m_Items[3] = v52;
  v43->m_Items[4] = " , ";
  sub_854710(pos, 2u);
  v101 = v55;
  v56 = sub_8D3950(f32, &v101);
  v57 = v56;
  v43->m_Items[5] = v57;
  v59 = Concat_5270224(v43);
  v60 = Empty_string_();
  Log(v59, v60, 0);
  if ((fld_id - 200) > 0x12B)
  {
    switch (fld_id)
    {
      case 615:
        if (op_Equality(name, "y_light02", 0)
          || op_Equality(name, "y_light03", 0))
        {
          v95 = (*pLight)->DiffuseB;
          v96 = (*pLight)->DiffuseR;
          v97 = (*pLight)->DiffuseG;
          (*pLight)->DiffuseR = (*pLight)->AmbientR;
          (*pLight)->DiffuseG = (*pLight)->AmbientG;
          (*pLight)->DiffuseB = (*pLight)->AmbientB;
          (*pLight)->AmbientR = v96;
          (*pLight)->AmbientG = v97;
          (*pLight)->AmbientB = v95;
        }
        return;
      case 616:
      case 619:
      case 620:
      case 621:
      case 622:
      case 623:
      case 624:
      case 625:
      case 626:
      case 627:
      case 628:
      case 629:
      case 630:
      case 631:
      case 632:
      case 633:
      case 635:
      case 636:
      case 637:
      case 638:
      case 640:
      case 641:
      case 642:
      case 643:
      case 644:
      case 645:
      case 647:
      case 648:
      case 649:
      case 650:
      case 651:
      case 653:
      case 654:
      case 655:
      case 657:
      case 658:
      case 659:
      case 660:
      case 661:
        return;
      case 617:
        (*pLight)->DiffuseR = 0.3;
        (*pLight)->DiffuseG = 0.5;
        (*pLight)->DiffuseB = 0.5;
        (*pLight)->AmbientR = 0.14;
        v98 = *pLight;
        v99 = 1045891646;
        goto LABEL_147;
      case 618:
        if (op_Equality(name, "light01", 0))
        {
          (*pLight)->DiffuseR = 0.539;
          (*pLight)->DiffuseG = 0.574;
          (*pLight)->DiffuseB = 0.609;
          (*pLight)->AmbientR = 0.264;
          (*pLight)->AmbientG = 0.4;
          (*pLight)->AmbientB = 0.4;
        }
        if (op_Equality(name, "light02", 0))
        {
          (*pLight)->DiffuseR = 0.35;
          (*pLight)->DiffuseG = 0.35;
          (*pLight)->DiffuseB = 0.364;
          (*pLight)->AmbientR = 0.189;
          (*pLight)->AmbientG = 0.189;
          (*pLight)->AmbientB = 0.168;
        }
        if (!op_Equality(name, "light03", 0))
          return;
        (*pLight)->DiffuseR = 0.539;
        (*pLight)->DiffuseG = 0.574;
        (*pLight)->DiffuseB = 0.609;
        (*pLight)->AmbientR = 0.231;
        v61 = *pLight;
        v62 = 1049582633;
        goto LABEL_121;
      case 634:
        if (area_id != 1)
          return;
        v73 = *pLight;
        v74 = (*pLight)->AmbientB + 0.6;
        goto LABEL_94;
      case 639:
        if (op_Equality(name, "light01", 0))
        {
          (*pLight)->DiffuseR = 0.8;
          (*pLight)->DiffuseG = 0.8;
          (*pLight)->DiffuseB = 1.0;
          (*pLight)->AmbientR = 0.3;
          (*pLight)->AmbientG = 0.3;
          (*pLight)->AmbientB = 0.2;
        }
        if (!op_Equality(name, "light04", 0))
          return;
        (*pLight)->DiffuseR = 0.8;
        (*pLight)->DiffuseG = 0.9;
        (*pLight)->DiffuseB = 1.0;
        (*pLight)->AmbientR = 0.3;
        (*pLight)->AmbientG = 0.3;
        v93 = *pLight;
        v62 = 1045220557;
        goto LABEL_148;
      case 646:
      case 652:
      case 656:
      case 662:
        if (!op_Equality(name, "light01", 0))
          return;
        (*pLight)->DiffuseR = 0.67;
        (*pLight)->DiffuseG = 0.82;
        (*pLight)->DiffuseB = 1.0;
        (*pLight)->AmbientR = 0.165;
        v61 = *pLight;
        v62 = 1045220557;
        goto LABEL_121;
      default:
        if (fld_id != 14
          || area_id != 6
          || !op_Equality(name, "FieldObj01", 0)
          && !op_Equality(name, "FieldObj02", 0))
        {
          return;
        }
        v94 = *pLight;
        v72 = 0.8;
        goto LABEL_144;
    }
  }
  v63 = *pLight;
  v64 = (*pLight)->DiffuseR;
  v65 = (*pLight)->DiffuseG;
  v66 = (*pLight)->DiffuseB;
  if (v64 >= v65)
    v67 = (*pLight)->DiffuseR;
  else
    v67 = (*pLight)->DiffuseG;
  if (v67 >= v66)
    v68 = v67;
  else
    v68 = (*pLight)->DiffuseB;
  if (v68 <= 1.0)
  {
    if (fld_id != 261)
    {
      if (fld_id != 260)
        return;
      goto LABEL_120;
    }
LABEL_146:
    v63->DiffuseR = 0.6;
    (*pLight)->DiffuseG = 0.6;
    (*pLight)->DiffuseB = 0.8;
    v99 = 1050253722;
    (*pLight)->AmbientR = 0.3;
    v98 = *pLight;
LABEL_147:
    LODWORD(v98->AmbientG) = v99;
    v93 = *pLight;
    v62 = 1053609165;
LABEL_148:
    LODWORD(v93->AmbientB) = v62;
    return;
  }
  v69 = v64 / v68;
  v70 = v65 / v68;
  v71 = v66 / v68;
  if ((v64 / v68) > 0.8)
  {
    v69 = v69 * 0.83;
    v70 = v70 * 0.83;
    v71 = v71 * 0.83;
  }
  v63->DiffuseR = v69;
  (*pLight)->DiffuseG = v70;
  (*pLight)->DiffuseB = v71;
  v72 = 0.9;
  (*pLight)->AmbientR = (*pLight)->AmbientR * 0.9;
  (*pLight)->AmbientG = (*pLight)->AmbientG * 0.9;
  (*pLight)->AmbientB = (*pLight)->AmbientB * 0.9;
  if (fld_id == 215 && area_id == 4)
  {
    (*pLight)->DiffuseR = (*pLight)->DiffuseR * 0.8;
    (*pLight)->DiffuseG = (*pLight)->DiffuseG * 0.9;
    (*pLight)->AmbientR = (*pLight)->AmbientR * 0.6;
    (*pLight)->AmbientG = (*pLight)->AmbientG * 0.6;
    v73 = *pLight;
    v74 = (*pLight)->AmbientB * 0.8;
LABEL_94:
    v73->AmbientB = v74;
    return;
  }
  if (fld_id != 218)
  {
    if (fld_id != 261)
    {
      if (fld_id != 260)
        return;
      v63 = *pLight;
LABEL_120:
      v63->DiffuseR = 0.7;
      (*pLight)->DiffuseG = 0.7;
      (*pLight)->DiffuseB = 0.7;
      v62 = 1050253722;
      (*pLight)->AmbientR = 0.3;
      v61 = *pLight;
LABEL_121:
      LODWORD(v61->AmbientG) = v62;
      v93 = *pLight;
      goto LABEL_148;
    }
    v63 = *pLight;
    goto LABEL_146;
  }
  v94 = *pLight;
LABEL_144:
  v94->DiffuseR = v94->DiffuseR * v72;
  (*pLight)->DiffuseG = (*pLight)->DiffuseG * v72;
  (*pLight)->DiffuseB = (*pLight)->DiffuseB * v72;
}

// 0x17f9e00
void fldPPSV2_Set(s32 fld, s32 area) {
  bool v8;
  dds3KernelDraw_c *v9;
  s32 v11;
  bool v12;
  s32 v13;
  u64 v14;
  struct System_Int32_array *fld_pps;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  struct System_Int32_array *v22;
  Il2CppArrayBounds *v23;
  il2cpp_array_size_t v25;
  struct System_Int32_array *v30;
  Il2CppArrayBounds *v31;
  il2cpp_array_size_t v33;
  s32 v36;
  struct System_Int32_array *v37;
  Il2CppArrayBounds *v38;
  il2cpp_array_size_t v39;
  s64 v40;
  struct System_Single_array *fld_dof;
  Il2CppArrayBounds *v43;
  il2cpp_array_size_t v45;
  f32 v47;
  struct System_Single_array *v48;
  Il2CppArrayBounds *v49;
  il2cpp_array_size_t v51;
  f32 v53;
  struct System_Single_array *v54;
  Il2CppArrayBounds *v55;
  il2cpp_array_size_t v57;
  f32 v59;

  PPSV2_update = 1;
  fldEve_Bloom_Init();
  switch (fld)
  {
    case 25:
      if (!evtBitCheck(1433) || evtBitCheck(1859))
        goto LABEL_56;
      PPSV2_bloom_type = 15;
      PPSV2_update = 1;
      goto LABEL_115;
    case 41:
      if (area != 1)
        goto LABEL_56;
      v8 = evtBitCheck(1889);
      if (!v8)
        goto LABEL_53;
      v11 = 41;
      goto LABEL_52;
    case 42:
      if (area != 1)
        goto LABEL_56;
      if (!evtBitCheck(1921) && !evtBitCheck(1922))
        goto LABEL_114;
      v11 = 42;
      goto LABEL_52;
    case 43:
      if (area != 1)
        goto LABEL_56;
      if (!evtBitCheck(1953) && !evtBitCheck(1954) && !evtBitCheck(1955))
        goto LABEL_114;
      v11 = 43;
      goto LABEL_52;
    case 44:
      if (area != 1)
        goto LABEL_56;
      if (!evtBitCheck(1985)
        && !evtBitCheck(1986)
        && !evtBitCheck(1987)
        && !evtBitCheck(1988))
      {
        goto LABEL_114;
      }
      v11 = 44;
      goto LABEL_52;
    case 45:
      if (area != 1)
        goto LABEL_56;
      v12 = evtBitCheck(2017);
      if (!v12)
        goto LABEL_53;
      v11 = 45;
LABEL_52:
      PPSV2_bloom_type = v11;
      PPSV2_update = 1;
LABEL_53:
      if ((v9->_2.bitflags2 & 2) != 0)
        goto LABEL_54;
      goto LABEL_115;
    default:
LABEL_56:
      v13 = area + 1000 * fld;
      v14 = 0;
      break;
  }
  while (1)
  {
    bounds = fld_pps->bounds;
    length = bounds[1].length;
    if (fld_pps->m_Items[length * v14] == 999999)
      break;
    v22 = fld_pps;
    v23 = v22->bounds;
    v25 = v23[1].length;
    if (v22->m_Items[v25 * v14] == v13)
    {
      v30 = fld_pps;
      v31 = v30->bounds;
      v33 = v31[1].length;
      v36 = v30->m_Items[v33 * v14 + 1];
      PPSV2_bloom_type = v36;
      v37 = fld_pps;
      v38 = v37->bounds;
      v39 = v38[1].length;
      v40 = v37->m_Items[v39 * v14 + 2];
      if (v40)
      {
        v43 = fld_dof->bounds;
        v45 = v43[1].length;
        v47 = fld_dof->m_Items[v45 * v40];
        v48 = fld_dof;
        v49 = v48->bounds;
        v51 = v49[1].length;
        v53 = v48->m_Items[v51 * v40 + 1];
        v54 = fld_dof;
        v55 = v54->bounds;
        v57 = v55[1].length;
        v59 = v54->m_Items[v57 * v40 + 2];
        DofSet(v47, v53, v59);
      }
      else
      {
LABEL_114:
        {
LABEL_54:
        }
LABEL_115:
        DofOff();
      }
      return;
    }
    if (v14++ >= 0x3E6)
    {
      DofOff();
      PPSV2_update = 1;
      PPSV2_bloom_type = 0;
      return;
    }
  }
}
