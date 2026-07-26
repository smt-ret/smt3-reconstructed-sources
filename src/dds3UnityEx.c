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

static s32 fld_pps[UNKNOWN_ARRAY_SIZE];
static f32 fld_dof[UNKNOWN_ARRAY_SIZE];
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
static f32 jyakyo_aruji_normal_combine_tbl[UNKNOWN_ARRAY_SIZE];

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
    GetEventCamName();
    GetNowName_SCR_RUN();
    SpHokan2_ColorVec(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SpHokan_Color(0, 0, 0, 0, 0, 0, 0);
    SpHokan_ColorVec(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    evtBitCheck(0);
    GetNowCameraName();
    GetNowFrame();
    BasicLight_Char_Color_Standard(0, 0, 0, 0, 0, 0, 0);
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
    GetMainCamera(0);
}

// 0x1806290
void CampLight_Char_Color(char *objname, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim) {
    GetCampCameraObj(0);
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
      if (op_Equality(name, StringLiteral_4818, 0))
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
    evtBitCheck(0);
    DofOff();
    DofSet(0, 0, 0);
    Ktyousei_DOF();
}

// 0x1805b70
void FieldLight_Char_Color(char *objname, evtUnitHandle_t *hunit, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim) {
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
    evtBitCheck(0);
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
    evtBitCheck(0);
    return 0;
}

// 0x17fc3f0
void HighContrastTextureInit(void) {
}

// 0x100e680
void Ktyousei_DOF(void) {
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
}

// 0x18037f0
void NoFindHelper0(char *Owner_name, char *Light_name, sdfVector4_t *pos, sdfVector4_t *lpos) {
    GetEventCamName();
    evtBitCheck(0);
}

// 0x1802a90
void NoFindHelper0_DbgInput(sdfVector4_t *pos, sdfVector4_t *lpos, char *Light_name) {
    DDS3_PADCHECK_REP(0);
}

// 0x17fa500
void OverWrite_SkyLight(s32 fld, s32 tbl_idx, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b) {
}

// 0x1807370
void SceneLight_Char_Color(char *objname, evtUnitHandle_t *hunit, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *soften, f32 *bias, f32 *div, f32 *rim) {
    GetNowName_SCR_RUN();
    GetEventCamName();
    GetNowCameraName();
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
    }
    if (event_no != 693)
      return;
    evtUpdateEx_NowEveNo = event_no;
    return;
  }
  if (event_no == 699 || event_no == 723)
}

// 0x18056d0
void SpHokan2_ColorVec(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow) {
}

// 0x1805120
void SpHokan_Color(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow) {
  dds3UnityEx_Light_c *v15;
  s32 v16;
  struct dds3UnityEx_Light_StaticFields *static_fields;
  f32 v18;

  {
    else
    {
      static_fields = dds3UnityEx_Light->static_fields;
      if (static_fields->SpHokanMode)
    }
    static_fields->SpHokanMode = 1;
    v18 = *l0_r;
    if ((v15->_2.bitflags2 & 2) != 0)
  }
  v16 = 0;
  static_fields = dds3UnityEx_Light->static_fields;
  if (!static_fields->SpHokanMode)
  *l0_r = (static_fields->SpHokan_l0_r * hokanpow) + ((1.0 - hokanpow) * *l0_r);
  *l0_g = (SpHokan_l0_g * hokanpow) + ((1.0 - hokanpow) * *l0_g);
  *l0_b = (SpHokan_l0_b * hokanpow) + ((1.0 - hokanpow) * *l0_b);
  *a0_r = (SpHokan_a0_r * hokanpow) + ((1.0 - hokanpow) * *a0_r);
  *a0_g = (SpHokan_a0_g * hokanpow) + ((1.0 - hokanpow) * *a0_g);
  *a0_b = (SpHokan_a0_b * hokanpow) + ((1.0 - hokanpow) * *a0_b);
  v18 = *l0_r;
  {
  }
  SpHokan_l0_r = v18;
  SpHokan_l0_g = *l0_g;
  SpHokan_l0_b = *l0_b;
  SpHokan_a0_r = *a0_r;
  SpHokan_a0_g = *a0_g;
  SpHokan_a0_b = *a0_b;
}

// 0x1805360
void SpHokan_ColorVec(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 hokanpow) {
}

// 0x100d4e0
s32 UnityEx_GetPM_NowFrame(void) {
  return Ex_NowFrame;
}

// 0x100d550
void UnityEx_SetPM_NowCamera(void) {
    GetNowCameraName();
    Eve_DOF_Set(0, 0);
    Log(0, 0);
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
    dds3GetProcessData(0);
    CheckLoad(0);
    evtBitCheck(0);
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

  v8 = Concat_5224608(StringLiteral_15023, mname);
  v10 = Empty_string_();
  Log(v8, v10, 0);
  if (op_Equality(mname, StringLiteral_15024, 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, StringLiteral_15025, 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, StringLiteral_15026, 0)
    || op_Equality(mname, StringLiteral_15027, 0)
    || op_Equality(mname, StringLiteral_4802, 0)
    || op_Equality(mname, StringLiteral_15028, 0)
    || op_Equality(mname, StringLiteral_15029, 0)
    || op_Equality(mname, StringLiteral_15030, 0)
    || op_Equality(mname, StringLiteral_15031, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15032, 0)
    || op_Equality(mname, StringLiteral_15033, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15034, 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, StringLiteral_15035, 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, StringLiteral_4805, 0)
    || op_Equality(mname, StringLiteral_4804, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15036, 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, StringLiteral_4824, 0)
    || op_Equality(mname, StringLiteral_15037, 0)
    || op_Equality(mname, StringLiteral_15038, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15039, 0)
    || op_Equality(mname, StringLiteral_15040, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15041, 0)
    || op_Equality(mname, StringLiteral_15042, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_4794, 0)
    || op_Equality(mname, StringLiteral_15043, 0)
    || op_Equality(mname, StringLiteral_15044, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_4768, 0)
    || op_Equality(mname, StringLiteral_4769, 0)
    || op_Equality(mname, StringLiteral_4796, 0)
    || op_Equality(mname, StringLiteral_15045, 0)
    || op_Equality(mname, StringLiteral_15046, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15047, 0))
  {
    Postblur_AccumTex_NowMode = 1;
  }
  if (op_Equality(mname, StringLiteral_15048, 0)
    || op_Equality(mname, StringLiteral_15049, 0)
    || op_Equality(mname, StringLiteral_15050, 0)
    || op_Equality(mname, StringLiteral_15051, 0)
    || op_Equality(mname, StringLiteral_15052, 0)
    || op_Equality(mname, StringLiteral_15053, 0)
    || op_Equality(mname, StringLiteral_15054, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15055, 0)
    || op_Equality(mname, StringLiteral_15056, 0)
    || op_Equality(mname, StringLiteral_15057, 0)
    || op_Equality(mname, StringLiteral_15058, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15059, 0)
    || op_Equality(mname, StringLiteral_15060, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15061, 0))
    SetLayerAll2(fHD, rootobj, 14);
  if (op_Equality(mname, StringLiteral_15062, 0)
    || op_Equality(mname, StringLiteral_15063, 0))
  {
    SetLayerAll2(fHD, rootobj, 14);
  }
  if (op_Equality(mname, StringLiteral_15064, 0)
    || op_Equality(mname, StringLiteral_15065, 0))
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

  v5 = Concat_5224608(StringLiteral_15066, mname);
  v7 = Empty_string_();
  Log(v5, v7, 0);
  evtUpdateEx_FieldName = mname;
  if (op_Equality(mname, StringLiteral_15067, 0))
  {
    v11 = Find(StringLiteral_15068, 0);
    if (op_Inequality(v11, 0, 0))
      SetActive(v11, 0, 0);
    return;
  }
  if (op_Equality(mname, StringLiteral_15069, 0))
  {
    Set_EventMode(1);
    Set_EventID(693);
  }
  if (op_Equality(mname, StringLiteral_15070, 0))
  {
    Set_EventMode(1);
    v14 = 634;
  }
  if (op_Equality(mname, StringLiteral_15071, 0))
  {
    Set_EventMode(1);
    v14 = 703;
  }
  if (op_Equality(mname, StringLiteral_15072, 0))
  {
    Set_EventMode(1);
    v14 = 693;
  }
  if (op_Equality(mname, StringLiteral_15073, 0))
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
    if (!op_Equality(mname, StringLiteral_15074, 0))
    {
      if (!op_Equality(mname, StringLiteral_15075, 0)
        && !op_Equality(mname, StringLiteral_15076, 0)
        && !op_Equality(mname, StringLiteral_15077, 0)
        || !evtBitCheck(3712))
      {
        return;
      }
      Set_EventMode(1);
      v14 = 723;
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
    Log(0, 0);
    p2sdPlaySE_20173184(0);
    PlayVoice(0);
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
        if (op_Equality(name, StringLiteral_15224, 0)
          || op_Equality(name, StringLiteral_15225, 0))
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
    dds3GetProcessRunTime(0);
    Set_EventMode(0);
    DofOff();
    dds3GetProcessData(0);
    Set_EventID(0);
    dds3GetActiveScene();
    dds3GetActiveCameraSceneBasic(0);
    SetDrawFlag(0, 0);
    Eve_DOF_Set(0, 0);
    evtBitCheck(0);
    Log(0, 0);
    Debug_OW_SkyAlp();
    dds3EffectBlur(0, 0, 0);
    dds3EffectPartialMultiFilterCreate(0);
    dds3EffectPartialMultiFilterDraw(0);
    dds3EffectFilter(0);
    dds3FadeOut(0, 0, 0, 0);
    dds3FadeIn(0, 0, 0, 0);
    p2sdPlaySE_20173184(0);
    fldSkySetAlphaOfs(0);
    dds3FadeGetAlphaI();
    return 0;
}

// 0x100e8b0
void fldEve_BloomDof_AfterEnd(void) {
  struct dds3UnityEx_StaticFields *static_fields;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;

  else
  {
    static_fields = dds3UnityEx->static_fields;
    if (static_fields->FldEve_Bloom_Idx != -1)
  }
  else if (static_fields->FldEve_Dof_Idx == -1)
  {
    return;
  }
  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  fldPPSV2_Set(fieldID, areaID + 1);
}

// 0x100e9d0
void fldEve_BloomDof_Set(void) {
    dds3GetScriptProcName();
    dds3GetActiveScene();
    dds3GetActiveCameraSceneBasic(0);
    FldEve_Blur_Pow(0);
    DofSet(0, 0, 0);
    fldPPSV2_Set(0, 0);
    DofOff();
}

// 0x100e830
void fldEve_Bloom_Init(void) {
  FldEve_Bloom_Idx = -1;
  FldEve_Dof_Idx = -1;
}

// 0x100d960
void fldEventUpdateEx_Unity(s32 fld, s32 area, char *scr_label, char *cam_name) {
    evtBitCheck(0);
    SetLayerAll2(0, 0, 0);
    fldSdwDraw_Skep1();
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
  name = StringLiteral_416;
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
    if (op_Equality(ScriptProcName, StringLiteral_15149, 0)
      && evtBitCheck(1434)
      && !evtBitCheck(1435))
    {
      v18 = 38817800;
    }
    return;
  }
  if (fieldID == 25 && v9 == 6)
  {
    if (op_Equality(ScriptProcName, StringLiteral_15159, 0) && !evtBitCheck(1415))
    {
      v18 = 38821889;
    }
    return;
  }
  v13 = areaID == 0;
  if (fieldID == 42 && areaID == 0)
  {
    if (op_Equality(ScriptProcName, StringLiteral_15160, 0))
    {
      if (op_Equality(name, StringLiteral_15134, 0))
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
      if (op_Equality(name, StringLiteral_15133, 0))
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
  }
  else
  {
    if (fieldID == 37 && v9 == 7)
    {
      if (!op_Equality(ScriptProcName, StringLiteral_15161, 0))
      {
        if (!op_Equality(ScriptProcName, StringLiteral_15162, 0))
          return;
        if (evtUpdateEx_ArkOpen_F037_07_THOR_AFTER_Dead)
        {
          v18 = 57700354;
        }
        else
        {
          v18 = 57700353;
        }
      }
      evtUpdateEx_ArkOpen_F037_07_THOR_AFTER_Dead = 0;
      return;
    }
    if (fieldID == 41 && areaID == 10)
    {
      v16 = &StringLiteral_15163;
    }
    if (fieldID == 43)
    {
      if (areaID == 5
        && (op_Equality(ScriptProcName, StringLiteral_15164, 0)
         || op_Equality(ScriptProcName, StringLiteral_15165, 0)))
      {
      }
      if (areaID != 6)
      if (op_Equality(ScriptProcName, StringLiteral_15166, 0))
      v16 = &StringLiteral_15167;
      if (op_Equality(ScriptProcName, *v16, 0))
      {
        if (op_Equality(name, StringLiteral_15158, 0))
        {
          dds3EffectDistortionBlur_SetFldEventCntF(0.0);
        }
        v18 = 67137539;
        dds3EffectDistortionBlur_SetFldEvent(v18);
        return;
      }
      v34 = 0;
      if ((fieldID - 41) > 4)
    }
    if (fieldID == 44 && areaID == 27)
    {
      v16 = &StringLiteral_15168;
    }
    if (fieldID != 45)
    if (areaID == 7
      && (op_Equality(ScriptProcName, StringLiteral_15169, 0)
       || op_Equality(ScriptProcName, StringLiteral_15170, 0)))
    {
    }
    v34 = 1;
  }
  if (v13 && op_Equality(ScriptProcName, StringLiteral_15171, 0))
  {
    if (op_Equality(name, StringLiteral_15158, 0))
    {
      dds3EffectDistortionBlur_SetFldEventCntF(0.0);
    }
    v18 = 67137542;
  }
  if ((fieldID - 43) <= 1 && op_Equality(ScriptProcName, StringLiteral_15172, 0))
  {
    dds3EffectDistortionBlur_SetFldEvent(67137543);
  }
  if (!((v9 != 29) | (v34 ^ 1) & 1) && op_Equality(ScriptProcName, StringLiteral_15173, 0))
  {
    v18 = 72519689;
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
    Log(0, 0);
}

// 0x17f9e00
void fldPPSV2_Set(s32 fld, s32 area) {
  bool v8;
  dds3KernelDraw_c *v9;
  struct dds3KernelDraw_StaticFields *static_fields;
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
      PPSV2_bloom_type = 15;
      PPSV2_update = 1;
    case 41:
      if (area != 1)
      v8 = evtBitCheck(1889);
      if (!v8)
      static_fields = v9->static_fields;
      v11 = 41;
    case 42:
      if (area != 1)
      if (!evtBitCheck(1921) && !evtBitCheck(1922))
      static_fields = v9->static_fields;
      v11 = 42;
    case 43:
      if (area != 1)
      if (!evtBitCheck(1953) && !evtBitCheck(1954) && !evtBitCheck(1955))
      static_fields = v9->static_fields;
      v11 = 43;
    case 44:
      if (area != 1)
      if (!evtBitCheck(1985)
        && !evtBitCheck(1986)
        && !evtBitCheck(1987)
        && !evtBitCheck(1988))
      {
      }
      static_fields = v9->static_fields;
      v11 = 44;
    case 45:
      if (area != 1)
      v12 = evtBitCheck(2017);
      if (!v12)
      static_fields = v9->static_fields;
      v11 = 45;
      static_fields->PPSV2_bloom_type = v11;
      PPSV2_update = 1;
      if ((v9->_2.bitflags2 & 2) != 0)
    default:
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
        {
        }
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
