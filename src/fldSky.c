#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct XRD773Unity_BoxG XRD773Unity_BoxG;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3LightEditorWork_t dds3LightEditorWork_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldSky_FIL_t fldSky_FIL_t;
typedef struct fldSky_typeSKYTBL fldSky_typeSKYTBL;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct warp_elvtbl_s warp_elvtbl_s;

struct fldSky_typeSKYTBL {
    s32 FilterID;
    s32 FilterAlp;
    s32 FilterMode;
    s32 FilterAnm;
    s32 FilterPad0;
    s32 FilterPad1;
    s32 FilterPad2;
    s32 FogMax;
    s32 FogNear;
    s32 FogMin;
    s32 FogFar;
    s32 FogR;
    s32 FogG;
    s32 FogB;
    f32 sr0;
    f32 sg0;
    f32 sb0;
    f32 sx0;
    f32 sy0;
    f32 sz0;
    f32 sr1;
    f32 sg1;
    f32 sb1;
    f32 sx1;
    f32 sy1;
    f32 sz1;
    f32 sr2;
    f32 sg2;
    f32 sb2;
    f32 sx2;
    f32 sy2;
    f32 sz2;
    f32 sr3;
    f32 sg3;
    f32 sb3;
    f32 pr0;
    f32 pg0;
    f32 pb0;
    f32 px0;
    f32 py0;
    f32 pz0;
    f32 pr1;
    f32 pg1;
    f32 pb1;
    f32 px1;
    f32 py1;
    f32 pz1;
    f32 pr2;
    f32 pg2;
    f32 pb2;
    f32 px2;
    f32 py2;
    f32 pz2;
    f32 pr3;
    f32 pg3;
    f32 pb3;
};

struct fldSky_FIL_t {
    s32 alpmode;
    s32 *rgba[8];
};

static void SkyFilterObj[UNKNOWN_ARRAY_SIZE];
static s32 skyfilter_mx;
static s32 skyfilter_my;
static s32 gfldSkyHokan;
static dds3LightEditorWork_t *fld_player_light_work;
static sdf3DLight_t *fld_player_lights[3];
static sdfVector4_t fld_player_ambient;
static fldSky_typeSKYTBL gSkyTbl[UNKNOWN_ARRAY_SIZE];
static fldSky_typeSKYTBL gSkyBtlTbl[UNKNOWN_ARRAY_SIZE];
static fldSky_FIL_t gFilterBuff[UNKNOWN_ARRAY_SIZE];
static s32 gFilterAlpha;
static s32 gFilterAnime;
static f32 gFilterAnimeCntF;
static s32 gFilterAnimeOfsA;
static s32 gFilterNowIdx;
static s32 gFilterBlendIdx;
static f32 gFilterBlend;
static f32 gFilterBlendSpd;
static s32 gSkyTblNowIdx;
static s32 gSkyTblAnime;
static f32 gSkyTblAnimeCntI;
static s32 gSkyTblBaseIdx;
static s32 gSkyNowUpper;
static s32 bk_gFilterAnime;
static f32 bk_gFilterAnimeCntF;
static s32 bk_gFilterAnimeOfsA;
static s32 bk_gFilterNowIdx;
static s32 bk_gFilterBlendIdx;
static f32 bk_gFilterBlend;
static f32 bk_gFilterBlendSpd;
static s32 bk_gSkyTblNowIdx;
static s32 bk_gSkyTblAnime;
static f32 bk_gSkyTblAnimeCntI;
static s32 bk_gSkyTblBaseIdx;
static s32 gSkyTblNowIdxLM;
static s32 bk_SkyTblID;
static s32 gFilter_RgbPar;
static s32 gHokanOld_gFilter_RgbPar;
static s32 gHokanOld_gFilter_RgbPar_before;
static s32 gHokanOld_gFilter_RgbPar_BlendIdx;
static s32 gHokanOld_fldDbg_FilterAlp;
static bool colormode_setup;
static void *filter_obj[UNKNOWN_ARRAY_SIZE];
static s32 filter_type;

f32 Byte2Float(u8 **data, s32 pos);
s32 Byte2Int(warp_elvtbl_s *this, u8 **data, s32 pos);
void Clear(mdlManager_mdlTbMbAbLoadCb_t *this);
void FieldFilterAlf(dds3DefaultMain *this, f32 alpC);
void FieldFilterOn(dds3DefaultMain *this);
void FilterDelete(void);
void FilterSetUp(void);
void FilterSetUpInit(void);
bool GetPictureDisp(void);
void Get_OW_SkyAlp_Btl(s32 tbl_idx, s32 *to_alp, s32 *to_par);
bool IsDLCField(s32 area);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void OverWrite_SkyLight(s32 fld, s32 tbl_idx, f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b);
void Refresh(XRD773Unity_BoxG *this);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void dds3LightEditorWork_t__Clear(dds3LightEditorWork_t *this);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3SetAmbientColor(u32 frame, sdfVector4_t col);
void dds3SetFogColor(u32 frame, sdfVector4_t col);
void dds3SetFogPara(u32 frame, f32 max, f32 min, f32 near, f32 far);
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col);
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir);
void dds3UnitObjectBasicEL_LinkFree(dds3Basic_t **unitBasic);
bool evtBitCheck(s32 no);
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit);
void evtSetUnitLightAndAmbient(evtUnitHandle_t **h, u32 frame, u32 lrgb, u32 argb);
void evtSetUnitLightDir(evtUnitHandle_t **h, s32 frame);
void evtUnitLightOn(evtUnitHandle_t **h);
s32 fldAutoMapChkMode(void);
void fldMakeFilePath(char **pathstr, s32 field, s32 area);
void fldSkySetFilter(s32 idx, s32 mode, s32 hokan);
void fldSkySetPlayer(s32 intr, f32 r0, f32 g0, f32 b0, f32 r3, f32 g3, f32 b3, f32 x0, f32 y0, f32 z0);
void fldSkySetTbl(s32 idx, s32 hokan);
s32 fldSky_FIL_t__Copy(fldSky_FIL_t *this, u8 **data, s32 pos);
s32 fldSky_typeSKYTBL__Copy(fldSky_typeSKYTBL *this, u8 **data, s32 pos);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
f32 sdfSin(f32 aRadius);

// 0x160af10
f32 Byte2Float(u8 **data, s32 pos) {
  return ToSingle(data, pos, 0);
}

// 0x160ae90
s32 Byte2Int(u8 **data, s32 pos) {
  return ToInt32(data, pos, 0);
}

// 0x1776c70
void Clear(fldSky_FIL_t *this) {
  struct System_Int32_array_array *v3;
  struct System_Int32_array_array *v4;
  s64 *v5;
  s64 *v6;
  struct System_Int32_array_array *rgba;
  s64 *v9;
  s64 *v10;
  struct System_Int32_array_array *v12;
  s64 *v13;
  s64 *v14;
  struct System_Int32_array_array *v16;
  s64 *v17;
  s64 *v18;
  struct System_Int32_array_array *v20;
  s64 *v21;
  s64 *v22;
  struct System_Int32_array_array *v24;
  s64 *v25;
  s64 *v26;
  struct System_Int32_array_array *v28;
  s64 *v29;
  s64 *v30;
  struct System_Int32_array_array *v32;
  s64 *v33;
  s64 *v34;

  this->alpmode = 0;
  v3 = NewSpecific(int__, 8u);
  this->rgba = v3;
  v4 = v3;
  v5 = NewSpecific(s32, 9u);
  v6 = v5;
  v4->m_Items[0] = v6;
  rgba = this->rgba;
  v9 = NewSpecific(s32, 9u);
  v10 = v9;
  rgba->m_Items[1] = v10;
  v12 = this->rgba;
  v13 = NewSpecific(s32, 9u);
  v14 = v13;
  v12->m_Items[2] = v14;
  v16 = this->rgba;
  v17 = NewSpecific(s32, 9u);
  v18 = v17;
  v16->m_Items[3] = v18;
  v20 = this->rgba;
  v21 = NewSpecific(s32, 9u);
  v22 = v21;
  v20->m_Items[4] = v22;
  v24 = this->rgba;
  v25 = NewSpecific(s32, 9u);
  v26 = v25;
  v24->m_Items[5] = v26;
  v28 = this->rgba;
  v29 = NewSpecific(s32, 9u);
  v30 = v29;
  v28->m_Items[6] = v30;
  v32 = this->rgba;
  v33 = NewSpecific(s32, 9u);
  v34 = v33;
  v32->m_Items[7] = v34;
}

// 0x1612540
void FilterDelete(void) {
}

// 0x160fb80
void FilterSetUp(void) {
  u64 v3;
  s64 v4;
  s64 v5;
  s64 v6;
  s32 v8;
  fldSky_c *v12;
  u64 v13;
  s32 v14;
  struct fldSky_StaticFields *static_fields;
  s32 v16;
  s64 v17;
  struct fldSky_StaticFields *v18;
  struct UnityEngine_GameObject_array_array *filter_obj;
  struct UnityEngine_GameObject_array *SkyFilterObj;
  UnityEngine_GameObject_array *v22;
  Il2CppObject *v24;
  UnityEngine_GameObject_o *v25;
  UnityEngine_Transform_o *transform;
  s64 *v28;
  s64 *v29;
  struct UnityEngine_GameObject_array *v31;

  Log(StringLiteral_16778, 0);
  v4 = *(v3 + 184);
  v5 = *(v4 + 72);
  v6 = *(v4 + 96);
  v8 = *(*(v5 + 8 * v6 + 32) + 16LL);
  if (*(v4 + 216) == v8)
  {
    if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
    {
      if (SkyFilterObj)
        return;
    }
    else if (*v4)
    {
      return;
    }
  }
  if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
  FilterDelete(v3);
  SkyFilterObj = NewSpecific(
                                                   UnityEngine_GameObject,
                                                   (skyfilter_my
                                                  * skyfilter_mx));
  FieldFilterOn(kernelObject);
  v13 = 0;
  v14 = 0;
  {
  }
  while (1)
  {
    static_fields = v12->static_fields;
    if (v13 >= static_fields->skyfilter_my)
      break;
    v16 = 0;
    v17 = v14 + 4LL;
    if ((v12->_2.bitflags2 & 2) == 0)
    while (1)
    {
      v18 = v12->static_fields;
      if (v16 >= v18->skyfilter_mx)
        break;
      filter_obj = v18->filter_obj;
      SkyFilterObj = v18->SkyFilterObj;
      v22 = filter_obj->m_Items[v8];
      v24 = v22->m_Items[v13];
      v25 = Find(StringLiteral_16779, 0);
      transform = get_transform(v25, 0);
      v28 = Instantiate_object__425664(v24, transform, 0);
      v29 = v28;
      *(&SkyFilterObj->obj.klass + v17) = v29;
      v31 = SkyFilterObj;
      set_layer(*(&v31->obj.klass + v17), 19, 0);
      ++v16;
      ++v17;
    }
    ++v13;
    v14 = v17 - 4;
    if ((v12->_2.bitflags2 & 2) != 0)
  }
  static_fields->filter_type = v8;
}

// 0x160b550
void FilterSetUpInit(void) {
}

// 0x1612710
void SoftReset(void) {
  SkyFilterObj = 0;
  filter_obj = 0;
  filter_type = -1;
}

// 0x1611ea0
void fldSkyBattle(void) {
    Get_OW_SkyAlp_Btl(0, 0, 0);
    fldSkySetFilter(0, 0, 0);
    dds3SetFogColor(0, (sdfVector4_t){0});
    dds3SetFogPara(0, 0, 0, 0, 0);
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
}

// 0x15fdf60
void fldSkyCalcFilter(void) {
  fldSky_c *v2;
  struct fldSky_StaticFields **p_static_fields;
  struct fldSky_StaticFields *static_fields;
  f32 gFilterAnimeCntF;
  f32 v6;
  f32 v7;
  f32 v9;
  f32 v10;
  f32 v11;

  p_static_fields = &v2->static_fields;
  gFilterAnimeOfsA = 0;
  static_fields = v2->static_fields;
  switch (static_fields->gFilterAnime)
  {
    case 1:
      gFilterAnimeCntF = static_fields->gFilterAnimeCntF;
      v6 = 0.1;
    case 2:
      gFilterAnimeCntF = static_fields->gFilterAnimeCntF;
      v6 = 0.2;
    case 3:
      gFilterAnimeCntF = static_fields->gFilterAnimeCntF;
      v6 = 0.05;
      static_fields->gFilterAnimeCntF = gFilterAnimeCntF + v6;
      v7 = (*p_static_fields)->gFilterAnimeCntF;
      v9 = 32.0;
    case 4:
      v10 = static_fields->gFilterAnimeCntF;
      v11 = 0.1;
    case 5:
      v10 = static_fields->gFilterAnimeCntF;
      v11 = 0.2;
    case 6:
      v10 = static_fields->gFilterAnimeCntF;
      v11 = 0.05;
      static_fields->gFilterAnimeCntF = v10 + v11;
      v7 = (*p_static_fields)->gFilterAnimeCntF;
      v9 = 48.0;
      {
      }
      gFilterAnimeOfsA = (sdfSin(v7) * v9);
      break;
    default:
      return;
  }
}

// 0x15fdc60
void fldSkyCalcTable(void) {
    fldSkySetTbl(0, 0);
}

// 0x160af90
void fldSkyDefaultLoad(void) {
    Clear(0);
    LoadFileByte(0, 0, 0);
    fldSky_FIL_t__Copy(0, 0, 0);
    fldSky_typeSKYTBL__Copy(0, 0, 0);
    FilterSetUpInit();
}

// 0x160c2c0
void fldSkyDrawFilter(void) {
    fldAutoMapChkMode();
    rsetOtOfs(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    rsetAlpha(0);
    GetPictureDisp();
    Refresh(0);
    FieldFilterAlf(0, 0);
}

// 0x160bcf0
void fldSkyFieldLoad(s32 field) {
    fldMakeFilePath(0, 0, 0);
    evtBitCheck(0);
    IsDLCField(0);
    LoadFileByte(0, 0, 0);
    fldSky_typeSKYTBL__Copy(0, 0, 0);
    OverWrite_SkyLight(0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x1610040
s32 fldSkyGetAlpha(void) {
  return gFilterAlpha;
}

// 0x1610170
s32 fldSkyGetAlphaOfs(void) {
  return fldDbg->FilterAlp;
}

// 0x16101e0
s32 fldSkyGetFilterNowIdx(void) {
  return gFilterNowIdx;
}

// 0x16102c0
s32 fldSkyGet_RgbPar(void) {
  return gFilter_RgbPar;
}

// 0x160c170
void fldSkyLoadFromMem(void *data) {
  s64 typeHierarchyDepth;
  Il2CppObject *v4;
  System_Byte_array *bytes;
  u64 v7;
  s32 v8;
  struct fldSky_typeSKYTBL_array *gSkyTbl;
  s32 v12;

  else
  {
    gFilterAlpha = 128;
    if (!data)
  }
  if (data->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
  {
    if (data->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == UnityEngine_TextAsset)
      v4 = data;
    else
      v4 = 0;
  }
  v4 = 0;
  bytes = get_bytes(v4);
  v7 = 0;
  v8 = 0;
  do
  {
    v12 = fldSky_typeSKYTBL__Copy(gSkyTbl->m_Items[v7++], bytes, v8);
    v8 = v12;
  }
  while (v7 != 256);
}

// 0x15f5650
void fldSkyRefreshTbl(void) {
    fldSkySetFilter(0, 0, 0);
    dds3SetFogColor(0, (sdfVector4_t){0});
    dds3SetFogPara(0, 0, 0, 0, 0);
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    evtGetUnitHandle2(0);
    evtUnitLightOn(0);
    evtSetUnitLightAndAmbient(0, 0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    evtSetUnitLightDir(0, 0);
}

// 0x160ffd0
void fldSkySetAlpha(s32 alp) {
  gFilterAlpha = alp;
}

// 0x16100b0
void fldSkySetAlphaOfs(s32 alp) {
  s32 FilterAlp;

  FilterAlp = fldDbg->FilterAlp;
  gHokanOld_fldDbg_FilterAlp = FilterAlp;
  fldDbg->FilterAlp = alp;
}

// 0x1610330
void fldSkySetDante(s32 intr, f32 r0, f32 g0, f32 b0, f32 r3, f32 g3, f32 b3, f32 x0, f32 y0, f32 z0) {
  dds3Basic_t_o *player3;
  evtUnitHandle_t_o *h;

  h = 0;
  if (player3)
  {
    h = evtGetUnitHandle2(player3);
    evtSetUnitLightAndAmbient(
      &h,
      intr,
      vcvts_n_s32_f32(r0, 7u) | (vcvts_n_s32_f32(g0, 7u) << 8) | (vcvts_n_s32_f32(b0, 7u) << 16) | 0x80000000,
      vcvts_n_s32_f32(r3, 7u) | (vcvts_n_s32_f32(g3, 7u) << 8) | (vcvts_n_s32_f32(b3, 7u) << 16) | 0x80000000,
      0);
  }
}

// 0x160f8d0
void fldSkySetFilter(s32 idx, s32 mode, s32 hokan) {
    FilterSetUp();
}

// 0x160ff50
void fldSkySetFilterAnime(s32 type) {
  gFilterAnime = type;
  gFilterAnimeCntF = 0.0;
  gFilterAnimeOfsA = 0;
}

// 0x1610470
void fldSkySetPlayer(s32 intr, f32 r0, f32 g0, f32 b0, f32 r3, f32 g3, f32 b3, f32 x0, f32 y0, f32 z0) {
    evtGetUnitHandle2(0);
    evtUnitLightOn(0);
    evtSetUnitLightAndAmbient(0, 0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    evtSetUnitLightDir(0, 0);
}

// 0x15f9620
void fldSkySetTableAnime(s32 type) {
  gSkyTblAnime = type;
  gSkyTblAnimeCntI = 0.0;
  gSkyTblBaseIdx = fldDbg->SkyTblID;
  fldSkySetTbl(gSkyTblBaseIdx, 1);
}

// 0x15f8ef0
void fldSkySetTbl(s32 idx, s32 hokan) {
    fldSkySetFilter(0, 0, 0);
    dds3SetFogColor(0, (sdfVector4_t){0});
    dds3SetFogPara(0, 0, 0, 0, 0);
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    fldSkySetPlayer(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x1611d30
void fldSkySetTblIdxInit(s32 idx) {
  gSkyTblNowIdx = idx;
  bk_gSkyTblNowIdx = 0;
  fldDbg->SkyTblAnm = 0;
  fldDbg->SkyTblID = idx;
  gSkyTblNowIdxLM = 0;
}

// 0x1611620
void fldSkySetTblLightMa(s32 idx, s32 hokan) {
    fldSkySetFilter(0, 0, 0);
    dds3SetFogColor(0, (sdfVector4_t){0});
    dds3SetFogPara(0, 0, 0, 0, 0);
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    fldSkySetPlayer(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x1611540
void fldSkySetTblLightMaDZ(s32 idx) {
  if (idx)
  {
    dds3ObjectBaseOnFlag(&player, 0x100u, 0);
    dds3UnitObjectBasicEL_LinkFree(&player);
  }
  else
  {
    dds3ObjectBaseOffFlag(&player, 0x100u);
  }
}

// 0x1610b80
void fldSkySetTblModosu(s32 hokan) {
    fldSkySetTbl(0, 0);
}

// 0x1610d90
void fldSkySetTblUpper(s32 idx, s32 hokan) {
    fldSkySetFilter(0, 0, 0);
    dds3SetFogColor(0, (sdfVector4_t){0});
    dds3SetFogPara(0, 0, 0, 0, 0);
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    fldSkySetPlayer(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x1610250
void fldSkySet_RgbPar(s32 par) {
  gFilter_RgbPar = par;
}

// 0x1611e00
void fldSky_DebugFastInit(void) {
  fldSky_c *v3;
  struct fldSky_StaticFields *static_fields;
  struct dds3LightEditorWork_t_o *fld_player_light_work;
  s64 v6;
  f32 z;

  dds3LightEditorWork_t__Clear(fld_player_light_work);
  fld_player_light_work->lightSrc = fld_player_lights;
  static_fields = v3->static_fields;
  fld_player_light_work = static_fields->fld_player_light_work;
  v6 = *&static_fields->fld_player_ambient.x;
  z = static_fields->fld_player_ambient.z;
  *&static_fields = static_fields->fld_player_ambient.w;
  *&fld_player_light_work->ambientSrc.x = v6;
  fld_player_light_work->ambientSrc.z = z;
  LODWORD(fld_player_light_work->ambientSrc.w) = static_fields;
}

// 0x1777040
s32 fldSky_FIL_t__Copy(fldSky_FIL_t *this, u8 **data, s32 pos) {
  u64 v7;
  s32 v9;
  u64 i;
  struct System_Int32_array_array *rgba;
  System_Int32_array *v13;
  s32 v14;
  char *v16;

  v7 = 0;
  this->alpmode = Byte2Int(data, pos, 0);
  v9 = pos + 4;
  for (i = 0; ; i = 0)
  {
    do
    {
      rgba = this->rgba;
      v13 = rgba->m_Items[v7];
      v14 = Byte2Int(data, v9, 0);
      v16 = v13 + 4 * i++;
      v9 += 4;
      *(v16 + 8) = v14;
    }
    while (i != 9);
    if (++v7 == 8)
      break;
  }
  return v9;
}

// 0x1777190
s32 fldSky_typeSKYTBL__Copy(fldSky_typeSKYTBL *this, u8 **data, s32 pos) {
  this->FilterID = Byte2Int(data, pos, 0);
  this->FilterAlp = Byte2Int(data, pos + 4, 0);
  this->FilterMode = Byte2Int(data, pos + 8, 0);
  this->FilterAnm = Byte2Int(data, pos + 12, 0);
  this->FilterPad0 = Byte2Int(data, pos + 16, 0);
  this->FilterPad1 = Byte2Int(data, pos + 20, 0);
  this->FilterPad2 = Byte2Int(data, pos + 24, 0);
  this->FogMax = Byte2Int(data, pos + 28, 0);
  this->FogNear = Byte2Int(data, pos + 32, 0);
  this->FogMin = Byte2Int(data, pos + 36, 0);
  this->FogFar = Byte2Int(data, pos + 40, 0);
  this->FogR = Byte2Int(data, pos + 44, 0);
  this->FogG = Byte2Int(data, pos + 48, 0);
  this->FogB = Byte2Int(data, pos + 52, 0);
  this->sr0 = Byte2Float(data, pos + 56);
  this->sg0 = Byte2Float(data, pos + 60);
  this->sb0 = Byte2Float(data, pos + 64);
  this->sx0 = Byte2Float(data, pos + 68);
  this->sy0 = Byte2Float(data, pos + 72);
  this->sz0 = Byte2Float(data, pos + 76);
  this->sr1 = Byte2Float(data, pos + 80);
  this->sg1 = Byte2Float(data, pos + 84);
  this->sb1 = Byte2Float(data, pos + 88);
  this->sx1 = Byte2Float(data, pos + 92);
  this->sy1 = Byte2Float(data, pos + 96);
  this->sz1 = Byte2Float(data, pos + 100);
  this->sr2 = Byte2Float(data, pos + 104);
  this->sg2 = Byte2Float(data, pos + 108);
  this->sb2 = Byte2Float(data, pos + 112);
  this->sx2 = Byte2Float(data, pos + 116);
  this->sy2 = Byte2Float(data, pos + 120);
  this->sz2 = Byte2Float(data, pos + 124);
  this->sr3 = Byte2Float(data, pos + 128);
  this->sg3 = Byte2Float(data, pos + 132);
  this->sb3 = Byte2Float(data, pos + 136);
  this->pr0 = Byte2Float(data, pos + 140);
  this->pg0 = Byte2Float(data, pos + 144);
  this->pb0 = Byte2Float(data, pos + 148);
  this->px0 = Byte2Float(data, pos + 152);
  this->py0 = Byte2Float(data, pos + 156);
  this->pz0 = Byte2Float(data, pos + 160);
  this->pr1 = Byte2Float(data, pos + 164);
  this->pg1 = Byte2Float(data, pos + 168);
  this->pb1 = Byte2Float(data, pos + 172);
  this->px1 = Byte2Float(data, pos + 176);
  this->py1 = Byte2Float(data, pos + 180);
  this->pz1 = Byte2Float(data, pos + 184);
  this->pr2 = Byte2Float(data, pos + 188);
  this->pg2 = Byte2Float(data, pos + 192);
  this->pb2 = Byte2Float(data, pos + 196);
  this->px2 = Byte2Float(data, pos + 200);
  this->py2 = Byte2Float(data, pos + 204);
  this->pz2 = Byte2Float(data, pos + 208);
  this->pr3 = Byte2Float(data, pos + 212);
  this->pg3 = Byte2Float(data, pos + 216);
  this->pb3 = Byte2Float(data, pos + 220);
  return pos + 224;
}
