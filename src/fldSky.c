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

static void *SkyFilterObj;
static s32 skyfilter_mx;
static s32 skyfilter_my;
static s32 gfldSkyHokan;
static dds3LightEditorWork_t *fld_player_light_work;
static sdf3DLight_t *fld_player_lights[3];
static sdfVector4_t fld_player_ambient;
static fldSky_typeSKYTBL *gSkyTbl;
static fldSky_typeSKYTBL *gSkyBtlTbl;
static fldSky_FIL_t *gFilterBuff;
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
static void **filter_obj;
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
  fldSky_c *v2;
  s64 v3;
  s16 v4;
  u64 v5;
  s32 i;
  struct UnityEngine_GameObject_array *SkyFilterObj;
  UnityEngine_Object_o *v10;
  struct UnityEngine_GameObject_array *v11;

  if (SkyFilterObj)
  {
    v3 = 4;
    v4 = *&v2->_2.bitflags1;
    v5 = 0;
    if ((v4 & 0x200) != 0)
      goto LABEL_11;
LABEL_10:
    for (i = 0; ; i = v4 & 0x200)
    {
      if (v5 >= skyfilter_my * skyfilter_mx)
        break;
      else
      {
        if (v5 >= LODWORD(SkyFilterObj->max_length))
          goto LABEL_18;
      }
      v10 = *(&SkyFilterObj->obj.klass + v3);
      Destroy_27360000(v10);
      v11 = SkyFilterObj;
      *(&v11->obj.klass + v3) = 0;
      ++v3;
      v5 = v3 - 4;
      if ((v4 & 0x200) == 0)
        goto LABEL_10;
LABEL_11:
    }
    SkyFilterObj = 0;
  }
  colormode_setup = 0;
  filter_type = -1;
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
  s32 v16;
  s64 v17;
  struct UnityEngine_GameObject_array_array *filter_obj;
  struct UnityEngine_GameObject_array *SkyFilterObj;
  UnityEngine_GameObject_array *v22;
  Il2CppObject *v24;
  UnityEngine_GameObject_o *v25;
  UnityEngine_Transform_o *transform;
  s64 *v28;
  s64 *v29;
  struct UnityEngine_GameObject_array *v31;

  Log("====================FilterSetUp", 0);
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
  FilterDelete(v3);
  SkyFilterObj = NewSpecific(
                                                   UnityEngine_GameObject,
                                                   (skyfilter_my
                                                  * skyfilter_mx));
  FieldFilterOn(kernelObject);
  v13 = 0;
  v14 = 0;
  {
LABEL_24:
  }
  while (1)
  {
    if (v13 >= skyfilter_my)
      break;
    v16 = 0;
    v17 = v14 + 4LL;
    if ((v12->_2.bitflags2 & 2) == 0)
      goto LABEL_32;
LABEL_30:
LABEL_32:
    while (1)
    {
      if (v16 >= skyfilter_mx)
        break;
      v22 = filter_obj->m_Items[v8];
      v24 = v22->m_Items[v13];
      v25 = Find("FieldFilter/Sky", 0);
      transform = get_transform(v25, 0);
      v28 = Instantiate_object__425664(v24, transform, 0);
      v29 = v28;
      *(&SkyFilterObj->obj.klass + v17) = v29;
      v31 = SkyFilterObj;
      set_layer(*(&v31->obj.klass + v17), 19, 0);
      ++v16;
      ++v17;
        goto LABEL_30;
    }
    ++v13;
    v14 = v17 - 4;
    if ((v12->_2.bitflags2 & 2) != 0)
      goto LABEL_24;
  }
  filter_type = v8;
}

// 0x160b550
void FilterSetUpInit(void) {
  struct UnityEngine_GameObject_array_array *v3;
  fldSky_c *v4;
  u64 v5;
  u32 *filter_obj;
  s64 *v8;
  s64 *v9;
  u64 v11;
  u32 *v13;
  struct UnityEngine_GameObject_array_array *v15;
  u32 *v17;
  s64 *v18;
  s64 *v19;
  char *v20;
  s64 *v21;
  char *v22;
  s64 *v23;
  u64 v26;
  u32 *v28;
  struct UnityEngine_GameObject_array_array *v30;
  u32 *v32;
  s64 *v33;
  s64 *v34;
  char *v35;
  s64 *v36;
  char *v37;
  s64 *v38;
  u64 v41;
  u32 *v43;
  struct UnityEngine_GameObject_array_array *v45;
  u32 *v47;
  u64 *v48;
  System_String_o *v49;
  s64 *v50;
  s64 *v51;
  char *v52;
  s64 *v53;
  char *v54;
  s64 *v55;
  s32 v59;
  u64 v60[2];
  char *v61;

  else if (filter_obj)
  {
    return;
  }
  v3 = NewSpecific(UnityEngine_GameObject__, 3u);
  filter_obj = v3;
  v5 = 0;
  if ((v4->_2.bitflags2 & 2) != 0)
  {
LABEL_12:
    goto LABEL_14;
  }
  while (1)
  {
LABEL_14:
    v8 = NewSpecific(UnityEngine_GameObject, skyfilter_my);
    v9 = v8;
    *&filter_obj[2 * v5 + 8] = v9;
    if (v5)
    {
      if (v5 == 1)
      {
        v41 = 0;
          goto LABEL_80;
LABEL_78:
LABEL_80:
        while (1)
        {
          if (v41 >= skyfilter_my)
            break;
          else
          {
            v45 = filter_obj;
            if (v5 >= LODWORD(v45->max_length))
              goto LABEL_84;
          }
          v47 = v45->m_Items[v5];
          v59 = v41;
          v48 = sub_8D3950(s32, &v59);
          v49 = Concat("Filter/SkyFilterAddLine", v48);
          v50 = Load(v49, 0);
          v51 = v50;
          if (v50)
          {
            if (*v50 != UnityEngine_GameObject)
            {
              sub_8FC2C0(*(*v50 + 64), UnityEngine_GameObject, v60);
              if ((v60[0] & 1) != 0)
                v52 = v61;
              else
                v52 = v60 + 1;
              v53 = sub_8C4940(v52);
            }
            if (*v51 != UnityEngine_GameObject)
            {
              sub_8FC2C0(*(*v51 + 64), UnityEngine_GameObject, v60);
              if ((v60[0] & 1) != 0)
                v54 = v61;
              else
                v54 = v60 + 1;
              v55 = sub_8C4940(v54);
            }
          }
          v43 = &v47[2 * v41++];
          *(v43 + 4) = v51;
            goto LABEL_78;
        }
      }
      else if (v5 == 2)
      {
        v11 = 0;
          goto LABEL_26;
LABEL_24:
LABEL_26:
        while (1)
        {
          if (v11 >= skyfilter_my)
            break;
          else
          {
            v15 = filter_obj;
            if (v5 >= LODWORD(v15->max_length))
              goto LABEL_30;
          }
          v17 = v15->m_Items[v5];
          v18 = Load("Filter/SkyFilterAddSub", 0);
          v19 = v18;
          if (v18)
          {
            if (*v18 != UnityEngine_GameObject)
            {
              sub_8FC2C0(*(*v18 + 64), UnityEngine_GameObject, v60);
              if ((v60[0] & 1) != 0)
                v20 = v61;
              else
                v20 = v60 + 1;
              v21 = sub_8C4940(v20);
            }
            if (*v19 != UnityEngine_GameObject)
            {
              sub_8FC2C0(*(*v19 + 64), UnityEngine_GameObject, v60);
              if ((v60[0] & 1) != 0)
                v22 = v61;
              else
                v22 = v60 + 1;
              v23 = sub_8C4940(v22);
            }
          }
          v13 = &v17[2 * v11++];
          *(v13 + 4) = v19;
            goto LABEL_24;
        }
      }
    }
    else
    {
      v26 = 0;
        goto LABEL_53;
LABEL_51:
LABEL_53:
      while (1)
      {
        if (v26 >= skyfilter_my)
          break;
        else
        {
          v30 = filter_obj;
          if (v5 >= LODWORD(v30->max_length))
            goto LABEL_57;
        }
        v32 = v30->m_Items[v5];
        v33 = Load("Filter/SkyFilterBlend", 0);
        v34 = v33;
        if (v33)
        {
          if (*v33 != UnityEngine_GameObject)
          {
            sub_8FC2C0(*(*v33 + 64), UnityEngine_GameObject, v60);
            if ((v60[0] & 1) != 0)
              v35 = v61;
            else
              v35 = v60 + 1;
            v36 = sub_8C4940(v35);
          }
          if (*v34 != UnityEngine_GameObject)
          {
            sub_8FC2C0(*(*v34 + 64), UnityEngine_GameObject, v60);
            if ((v60[0] & 1) != 0)
              v37 = v61;
            else
              v37 = v60 + 1;
            v38 = sub_8C4940(v37);
          }
        }
        v28 = &v32[2 * v26++];
        *(v28 + 4) = v34;
          goto LABEL_51;
      }
    }
    if (v5 > 1)
      break;
    ++v5;
      goto LABEL_12;
  }
}

// 0x1612710
void SoftReset(void) {
  SkyFilterObj = 0;
  filter_obj = 0;
  filter_type = -1;
}

// 0x1611ea0
void fldSkyBattle(void) {
  struct fldSky_typeSKYTBL_array *gSkyBtlTbl;
  s64 gSkyTblNowIdx;
  fldSky_typeSKYTBL_o *v8;
  s32 v10;
  s32 v13;
  s32 FilterAlp;
  s32 v17;
  s32 FilterAnm;
  s64 v22;
  s64 v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o v25;
  s32 to_par[2];
  UnityEngine_Vector4_o v27;

  *to_par = 0;
  *&v25.x = 0;
  *&v25.z = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  v8 = gSkyBtlTbl->m_Items[gSkyTblNowIdx];
  fldDbg->FilterID = v8->FilterID;
  fldDbg->FilterID = LOBYTE(fldDbg->FilterID);
  gHokanOld_fldDbg_FilterAlp = fldDbg->FilterAlp;
  fldDbg->FilterAlp = v8->FilterAlp;
  fldDbg->FilterMode = v8->FilterMode;
  fldDbg->FilterAnm = v8->FilterAnm;
  v10 = gSkyTblNowIdx;
  Get_OW_SkyAlp_Btl(v10, &to_par[1], to_par);
  v13 = to_par[1];
  FilterAlp = fldDbg->FilterAlp;
  gHokanOld_fldDbg_FilterAlp = FilterAlp;
  fldDbg->FilterAlp = v13;
  v17 = to_par[0];
  gFilter_RgbPar = v17;
  fldSkySetFilter(fldDbg->FilterID, fldDbg->FilterMode, 0);
  FilterAnm = fldDbg->FilterAnm;
  gFilterAnime = FilterAnm;
  gFilterAnimeCntF = 0.0;
  gFilterAnimeOfsA = 0;
  sub_854930(&v25, 0);
  sub_854930(&v25, 1u);
  sub_854930(&v25, 2u);
  sub_854930(&v25, 3u);
  v22 = *&v25.x;
  v23 = *&v25.z;
  *&v27.x = v22;
  *&v27.z = v23;
  dds3SetFogColor(0, v27);
  dds3SetFogPara(0, v8->FogMax, v8->FogMin, v8->FogNear, v8->FogFar);
  sub_854930(&v24, 0);
  sub_854930(&v24, 1u);
  sub_854930(&v24, 2u);
  sub_854930(&v24, 3u);
  dds3SetLightDir(0, 0, v24);
  sub_854930(&v25, 0);
  sub_854930(&v25, 1u);
  sub_854930(&v25, 2u);
  sub_854930(&v25, 3u);
  dds3SetLightColor(0, 0, v25);
  sub_854930(&v24, 0);
  sub_854930(&v24, 1u);
  sub_854930(&v24, 2u);
  sub_854930(&v24, 3u);
  dds3SetLightDir(0, 1u, v24);
  sub_854930(&v25, 0);
  sub_854930(&v25, 1u);
  sub_854930(&v25, 2u);
  sub_854930(&v25, 3u);
  dds3SetLightColor(0, 1u, v25);
  sub_854930(&v24, 0);
  sub_854930(&v24, 1u);
  sub_854930(&v24, 2u);
  sub_854930(&v24, 3u);
  dds3SetLightDir(0, 2u, v24);
  sub_854930(&v25, 0);
  sub_854930(&v25, 1u);
  sub_854930(&v25, 2u);
  sub_854930(&v25, 3u);
  dds3SetLightColor(0, 2u, v25);
  sub_854930(&v25, 0);
  sub_854930(&v25, 1u);
  sub_854930(&v25, 2u);
  sub_854930(&v25, 3u);
  dds3SetAmbientColor(0, v25);
}

// 0x15fdf60
void fldSkyCalcFilter(void) {
  struct fldSky_StaticFields **p_static_fields;
  f32 gFilterAnimeCntF;
  f32 v6;
  f32 v7;
  f32 v9;
  f32 v10;
  f32 v11;

  gFilterAnimeOfsA = 0;
  switch (gFilterAnime)
  {
    case 1:
      v6 = 0.1;
      goto LABEL_19;
    case 2:
      v6 = 0.2;
      goto LABEL_19;
    case 3:
      v6 = 0.05;
LABEL_19:
      gFilterAnimeCntF = gFilterAnimeCntF + v6;
      v7 = (*p_static_fields)->gFilterAnimeCntF;
      v9 = 32.0;
        goto LABEL_20;
      goto LABEL_35;
    case 4:
      v10 = gFilterAnimeCntF;
      v11 = 0.1;
      goto LABEL_34;
    case 5:
      v10 = gFilterAnimeCntF;
      v11 = 0.2;
      goto LABEL_34;
    case 6:
      v10 = gFilterAnimeCntF;
      v11 = 0.05;
LABEL_34:
      gFilterAnimeCntF = v10 + v11;
      v7 = (*p_static_fields)->gFilterAnimeCntF;
      v9 = 48.0;
      {
LABEL_20:
      }
LABEL_35:
      gFilterAnimeOfsA = (sdfSin(v7) * v9);
      break;
    default:
      return;
  }
}

// 0x15fdc60
void fldSkyCalcTable(void) {
  s32 gSkyTblAnime;
  f32 v7;
  s32 v8;
  s32 v9;
  f32 v11;
  f32 gSkyTblAnimeCntI;
  s32 gSkyTblBaseIdx;
  s32 v15;

  if (gSkyTblAnime == 3)
    goto LABEL_26;
LABEL_6:
  if (gSkyTblAnime == 2)
  {
    gSkyTblAnimeCntI = gSkyTblAnimeCntI + 1.0;
    v11 = gSkyTblAnimeCntI;
    if (v11 == 15.0)
    {
      v8 = (LOBYTE(gSkyTblBaseIdx) + 1);
      v9 = 1;
      goto LABEL_16;
    }
    if (v11 == 30.0)
    {
      v15 = 1;
      goto LABEL_58;
    }
  }
  else
  {
    if (gSkyTblAnime != 1)
      return;
    gSkyTblAnimeCntI = gSkyTblAnimeCntI + 1.0;
    v7 = gSkyTblAnimeCntI;
    if (v7 == 30.0)
    {
      v8 = (LOBYTE(gSkyTblBaseIdx) + 1);
      v9 = 30;
LABEL_16:
      fldSkySetTbl(v8, v9);
      return;
    }
    if (v7 == 60.0)
    {
      v15 = 30;
LABEL_58:
      fldSkySetTbl(gSkyTblBaseIdx, v15);
      gSkyTblAnimeCntI = 0.0;
    }
  }
}

// 0x160af90
void fldSkyDefaultLoad(void) {
  struct fldSky_typeSKYTBL_array *v4;
  u64 i;
  u32 *gSkyTbl;
  u64 *v8;
  u32 *v10;
  struct fldSky_typeSKYTBL_array *v11;
  u64 j;
  u32 *gSkyBtlTbl;
  u64 *v15;
  u32 *v17;
  struct fldSky_FIL_t_array *v18;
  fldSky_c *v19;
  s64 v20;
  u64 v21;
  u32 *gFilterBuff;
  u64 *v23;
  struct fldSky_FIL_t_array *v25;
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  u64 v31;
  s32 v32;
  struct fldSky_FIL_t_array *v34;
  s32 v36;
  AssetBundleCtrl_o *v37;
  System_Byte_array *v39;
  u64 v40;
  u64 v41;
  s32 v42;
  s32 v43;
  s64 v44;
  u32 v46;

  Log("fldSkyDefaultLoad:", 0);
  else if (gSkyTbl)
  {
    goto LABEL_24;
  }
  v4 = NewSpecific(fldSky_typeSKYTBL, 0x100u);
  gSkyTbl = v4;
  for (i = 0; i != 256; ++i)
  {
    v8 = Allocate(fldSky_typeSKYTBL);
    _ctor(v8, 0);
    v10 = &gSkyTbl[2 * i];
    *(v10 + 4) = v8;
  }
LABEL_24:
  else if (gSkyBtlTbl)
  {
    goto LABEL_42;
  }
  v11 = NewSpecific(fldSky_typeSKYTBL, 0x100u);
  gSkyBtlTbl = v11;
  for (j = 0; j != 256; ++j)
  {
    v15 = Allocate(fldSky_typeSKYTBL);
    _ctor(v15, 0);
    v17 = &gSkyBtlTbl[2 * j];
    *(v17 + 4) = v15;
  }
LABEL_42:
  else if (gFilterBuff)
  {
    goto LABEL_63;
  }
  v18 = NewSpecific(fldSky_FIL_t, 0x100u);
  gFilterBuff = v18;
  v20 = 4;
  if ((v19->_2.bitflags2 & 2) != 0)
  {
LABEL_51:
    goto LABEL_53;
  }
  while (1)
  {
LABEL_53:
    v21 = v20 - 4;
    v23 = Allocate(fldSky_FIL_t);
    _ctor(v23, 0);
    *&gFilterBuff[2 * v20] = v23;
    v25 = gFilterBuff;
    Clear(*(&v25->obj.klass + v20), 0);
    if (v20 == 259)
      break;
    ++v20;
      goto LABEL_51;
  }
LABEL_63:
  asset_bc = get_asset_bc();
  FileByte = LoadFileByte(asset_bc, "f_bin", "dds3data/fld/f/bin/FILTER.FLD.bytes");
  v31 = 0;
  v32 = 0;
  do
  {
    v34 = gFilterBuff;
    v36 = fldSky_FIL_t__Copy(v34->m_Items[v31++], FileByte, v32);
    v32 = v36;
  }
  while (v31 != 256);
  v37 = get_asset_bc();
  v39 = LoadFileByte(v37, "f_bin", "dds3data/fld/f/bin/BATTLEBG.SKY.bytes");
  v41 = 0;
  v42 = 0;
  do
  {
    v44 = *(*(v40 + 184) + 64LL);
    v42 = fldSky_typeSKYTBL__Copy(*(v44 + 8 * v41 + 32), v39, v42, 0);
    ++v41;
    v43 = (v46 >> 9) & 1;
  }
  while (v41 != 256);
  FilterSetUpInit(v40);
}

// 0x160c2c0
void fldSkyDrawFilter(void) {
  u32 gFilterNowIdx;
  struct fldSky_StaticFields **p_static_fields;
  f32 gFilterBlend;
  f32 v10;
  s32 FilterAlp;
  s64 v16;
  struct fldSky_FIL_t_array *gFilterBuff;
  s32 alpmode;
  s32 v21;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v24;
  struct fldGlobalWork_t_o *v26;
  struct fldGlobalWork_t_o *v28;
  struct fldGlobalWork_t_o *v31;
  struct fldGlobalWork_t_o *v33;
  struct fldGlobalWork_t_o *v35;
  s32 areaID;
  struct fldGlobalWork_t_o *v38;
  struct fldGlobalWork_t_o *v40;
  s32 v41;
  struct fldGlobalWork_t_o *v43;
  struct fldGlobalWork_t_o *v45;
  struct fldGlobalWork_t_o *v47;
  struct fldGlobalWork_t_o *v50;
  s32 v51;
  s32 fieldID;
  f32 v56;
  f32 v58;
  s32 v60;
  f32 v61;
  u64 v62;
  s32 v63;
  u64 v64;
  f32 v65;
  u64 v66;
  struct fldSky_FIL_t_array *v69;
  struct System_Int32_array_array *rgba;
  System_Int32_array *v73;
  struct fldSky_FIL_t_array *v75;
  struct System_Int32_array_array *v77;
  System_Int32_array *v79;
  struct fldSky_FIL_t_array *v81;
  struct System_Int32_array_array *v83;
  System_Int32_array *v85;
  struct fldSky_FIL_t_array *v87;
  struct System_Int32_array_array *v89;
  System_Int32_array *v91;
  s32 v93;
  struct fldSky_FIL_t_array *v94;
  struct System_Int32_array_array *v96;
  System_Int32_array *v98;
  u64 v99;
  struct fldSky_FIL_t_array *v101;
  struct System_Int32_array_array *v103;
  System_Int32_array *v105;
  struct fldSky_FIL_t_array *v107;
  struct System_Int32_array_array *v109;
  System_Int32_array *v111;
  struct fldSky_FIL_t_array *v113;
  struct System_Int32_array_array *v115;
  System_Int32_array *v117;
  s32 v119;
  struct fldSky_FIL_t_array *v120;
  struct System_Int32_array_array *v122;
  System_Int32_array *v124;
  struct fldSky_FIL_t_array *v126;
  struct System_Int32_array_array *v128;
  System_Int32_array *v130;
  struct fldSky_FIL_t_array *v132;
  struct System_Int32_array_array *v134;
  System_Int32_array *v136;
  struct fldSky_FIL_t_array *v138;
  struct System_Int32_array_array *v140;
  System_Int32_array *v142;
  s32 v144;
  struct fldSky_FIL_t_array *v145;
  struct System_Int32_array_array *v147;
  System_Int32_array *v149;
  struct fldSky_FIL_t_array *v151;
  struct System_Int32_array_array *v153;
  System_Int32_array *v155;
  struct fldSky_FIL_t_array *v157;
  struct System_Int32_array_array *v159;
  System_Int32_array *v161;
  struct fldSky_FIL_t_array *v163;
  struct System_Int32_array_array *v165;
  System_Int32_array *v167;
  s32 v169;
  fldSky_c *v170;
  s32 gFilterAnimeOfsA;
  s32 gFilter_RgbPar;
  s32 v175;
  s32 v176;
  s32 v177;
  s32 v178;
  s32 v179;
  s32 v180;
  s32 v181;
  s32 v182;
  s32 v183;
  s32 v184;
  s32 v185;
  s32 v186;
  s32 v187;
  s32 v188;
  s32 v189;
  s32 v190;
  s32 v191;
  s32 v192;
  s32 v193;
  s32 v194;
  s32 v195;
  s32 v196;
  s32 v197;
  s32 v198;
  s32 v199;
  s32 v200;
  s32 v201;
  s32 v202;
  s32 gHokanOld_gFilter_RgbPar;
  s32 v319;
  s32 gFilterAlpha;
  s32 v321;
  s32 v322;
  s32 v354;
  struct UnityEngine_GameObject_array *SkyFilterObj;
  s32 v356;
  UnityEngine_GameObject_o *v358;
  UnityEngine_Component_o *transform;
  UnityEngine_GUILayer_o *Component_GUILayer;
  Il2CppObject *Component_object;
  s32 v363;
  Il2CppClass *v364;
  s32 v365;
  UnityEngine_Vector2_o v366;
  s32 v367;
  Il2CppClass *v368;
  s32 v369;
  s32 v370;
  s32 v371;
  s32 v372;
  s32 v373;
  s32 v374;
  f32 v376;
  struct fldGlobalWork_t_o *v378;
  f32 v379;
  s32 v380;
  struct fldGlobalWork_t_o *v381;
  s32 v382;
  struct fldGlobalWork_t_o *v383;
  s32 v384;
  s32 v385;
  struct fldGlobalWork_t_o *v386;
  s32 v388;
  dds3DefaultMain_o *kernelObject;
  f32 v390;
  f32 v392;
  s32 gHokanOld_fldDbg_FilterAlp;
  f32 v394;
  s64 v403;
  s64 v404;
  s32 v407;
  s32 v408;
  s64 gFilterBlendIdx;
  s32 v416;
  u64 v417;
  s32 v418;
  s32 v419;
  s32 v420;
  s32 v421;
  s32 v422;
  s32 v423;
  s32 v424;
  s32 v425;
  s32 v426;
  s32 v427;
  s32 v428;
  s32 v429;
  u32 v430;
  Il2CppClass *v431;
  s32 v432;
  Il2CppClass *v433;
  s32 v434;
  void *v435;
  s32 v436;
  void *v437;
  s32 v438;
  Il2CppClass *v439;
  s64 v440;
  Il2CppClass *v441;
  s64 v442;
  UnityEngine_Vector2_o v443;
  s64 v444;
  Il2CppClass *v445;
  s64 v446;
  UnityEngine_Vector3_o v447;

  if (SkyFilterObj)
  {
    if (gFilterNowIdx)
    {
      else if (fldAutoMapChkMode())
      {
        return;
      }
      v10 = 1.0;
      if (gFilterBlend < 1.0)
      {
        gFilterBlend = gFilterBlend + (1.0 / gFilterBlendSpd);
        if (gFilterBlend > 1.0)
        {
          gFilterBlend = 1.0;
          (*p_static_fields)->gFilterBlendIdx = gFilterNowIdx;
          gHokanOld_fldDbg_FilterAlp = fldDbg->FilterAlp;
        }
      }
      v394 = gFilterBlend;
      FilterAlp = fldDbg->FilterAlp;
      v16 = gFilterNowIdx;
      rsetOtOfs(57);
      rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
      alpmode = gFilterBuff->m_Items[gFilterNowIdx]->alpmode;
      if (alpmode == 2)
      {
        v21 = 2;
      }
      else if (alpmode == 1)
      {
        v21 = 1;
      }
      else
      {
        if (alpmode)
          goto LABEL_58;
        v21 = 0;
      }
      rsetAlpha(v21);
LABEL_58:
      if (fldGb->fieldID == 224)
      {
        if (fldGb->areaID == 2)
          goto LABEL_74;
      }
      v24 = fldGb;
      if (v24->fieldID == 224)
      {
        if (v24->areaID == 5)
        {
LABEL_74:
          gFilter_RgbPar = 75;
        }
      }
      v26 = fldGb;
      if (v26->fieldID == 238)
      {
        if (!v26->areaID)
        {
          gFilter_RgbPar = 75;
        }
      }
      v28 = fldGb;
      if (v28->fieldID == 602)
      {
        if (!v28->areaID)
        {
          gFilter_RgbPar = 80;
        }
      }
      if (fldGb->fieldID == 634)
      {
        gFilter_RgbPar = 80;
      }
      v31 = fldGb;
      if (v31->fieldID == 12)
      {
        if (v31->areaID == 1)
        {
          gFilter_RgbPar = 50;
        }
      }
      v33 = fldGb;
      if (v33->fieldID == 18)
      {
        if (v33->areaID == 3)
        {
          gFilter_RgbPar = 80;
        }
      }
      v35 = fldGb;
      if (v35->fieldID == 20)
      {
        areaID = v35->areaID;
        if (!areaID)
          goto LABEL_150;
        if (areaID == 13)
          goto LABEL_150;
        if (areaID == 24)
        {
LABEL_150:
          gFilter_RgbPar = 80;
        }
      }
      v38 = fldGb;
      if (v38->fieldID == 20)
      {
        if (v38->areaID == 29)
        {
          gFilter_RgbPar = 60;
        }
      }
      v40 = fldGb;
      if (v40->fieldID == 20)
      {
        v41 = v40->areaID;
        if (v41 == 16)
          goto LABEL_186;
        if (v41 == 17)
          goto LABEL_186;
        if (v41 == 18)
          goto LABEL_186;
        if (v41 == 19)
        {
LABEL_186:
          gFilter_RgbPar = 200;
        }
      }
      v43 = fldGb;
      if (v43->fieldID == 24)
      {
        if (v43->areaID == 17)
        {
          gFilter_RgbPar = 60;
        }
      }
      v45 = fldGb;
      if (v45->fieldID == 37)
      {
        if (v45->areaID == 26)
        {
          gFilter_RgbPar = 70;
        }
      }
      v47 = fldGb;
      if (v47->fieldID == 30)
      {
        if (v47->areaID == 1)
        {
          gFilter_RgbPar = 70;
        }
      }
      if (fldDbg->FilterID == 101)
      {
        v50 = fldGb;
        if (v50->fieldID == 31)
        {
          v51 = v50->areaID;
          if (v51 == 2)
            goto LABEL_254;
          if (v51 == 4)
            goto LABEL_254;
          if (v51 == 6)
            goto LABEL_254;
          if (v51 == 10)
            goto LABEL_254;
          if (v51 == 13)
          {
LABEL_254:
            gFilter_RgbPar = 200;
          }
        }
      }
      v430 = gFilterNowIdx;
      v403 = gFilterNowIdx;
      if (!GetPictureDisp())
        goto LABEL_311;
      fieldID = fldGb->fieldID;
      if (fieldID == 1)
        goto LABEL_310;
      if (fieldID == 3)
        goto LABEL_310;
      if (fieldID == 4)
        goto LABEL_310;
      if (fieldID == 6)
        goto LABEL_310;
      if (fieldID == 7)
        goto LABEL_310;
      if (fieldID == 14)
        goto LABEL_310;
      if (fieldID == 15)
        goto LABEL_310;
      if (fieldID == 16)
        goto LABEL_310;
      if (fieldID == 17)
        goto LABEL_310;
      if (fieldID == 20)
        goto LABEL_310;
      v16 = gFilterNowIdx;
      v10 = 1.0;
      if (fieldID == 25)
        goto LABEL_310;
      v16 = gFilterNowIdx;
      v10 = 1.0;
      if (fieldID == 31)
LABEL_310:
        v408 = 1;
      else
LABEL_311:
        v408 = 0;
      v56 = FilterAlp;
      v392 = v10 - v394;
      v58 = v394 * v56;
      v60 = gFilterBlendIdx;
      if (gHokanOld_gFilter_RgbPar_BlendIdx != v60)
      {
        gHokanOld_gFilter_RgbPar_BlendIdx = v60;
        gHokanOld_gFilter_RgbPar = gHokanOld_gFilter_RgbPar_before;
      }
      v61 = v58 + (v392 * gHokanOld_fldDbg_FilterAlp);
      gHokanOld_gFilter_RgbPar_before = gFilter_RgbPar;
      v62 = 0;
      v63 = 0;
      while (1)
      {
        v64 = v62++;
        v65 = (v64 * -155.0) + 462.5;
        v66 = 0;
        v407 = v63;
        v404 = 8LL * v63 + 32;
        do
        {
          v69 = gFilterBuff;
          rgba = v69->m_Items[v16]->rgba;
          v73 = rgba->m_Items[v64];
          v429 = LOBYTE(v73->m_Items[v66]);
          v75 = gFilterBuff;
          v77 = v75->m_Items[v16]->rgba;
          v79 = v77->m_Items[v64];
          v428 = BYTE1(v79->m_Items[v66]);
          v81 = gFilterBuff;
          v83 = v81->m_Items[v16]->rgba;
          v85 = v83->m_Items[v64];
          v427 = BYTE2(v85->m_Items[v66]);
          v87 = gFilterBuff;
          v89 = v87->m_Items[v16]->rgba;
          v91 = v89->m_Items[v64];
          v93 = HIBYTE(v91->m_Items[v66]);
          v94 = gFilterBuff;
          v96 = v94->m_Items[v16]->rgba;
          v98 = v96->m_Items[v64];
          v99 = v66 + 1;
          v426 = LOBYTE(v98->m_Items[v66 + 1]);
          v101 = gFilterBuff;
          v103 = v101->m_Items[v16]->rgba;
          v105 = v103->m_Items[v64];
          v425 = BYTE1(v105->m_Items[v66 + 1]);
          v107 = gFilterBuff;
          v109 = v107->m_Items[v16]->rgba;
          v111 = v109->m_Items[v64];
          v424 = BYTE2(v111->m_Items[v66 + 1]);
          v113 = gFilterBuff;
          v115 = v113->m_Items[v16]->rgba;
          v117 = v115->m_Items[v64];
          v119 = HIBYTE(v117->m_Items[v66 + 1]);
          v120 = gFilterBuff;
          v122 = v120->m_Items[v16]->rgba;
          v124 = v122->m_Items[v62];
          v423 = LOBYTE(v124->m_Items[v66 + 1]);
          v126 = gFilterBuff;
          v128 = v126->m_Items[v16]->rgba;
          v130 = v128->m_Items[v62];
          v422 = BYTE1(v130->m_Items[v66 + 1]);
          v132 = gFilterBuff;
          v134 = v132->m_Items[v16]->rgba;
          v136 = v134->m_Items[v62];
          v421 = BYTE2(v136->m_Items[v66 + 1]);
          v138 = gFilterBuff;
          v140 = v138->m_Items[v16]->rgba;
          v142 = v140->m_Items[v62];
          v144 = HIBYTE(v142->m_Items[v66 + 1]);
          v145 = gFilterBuff;
          v147 = v145->m_Items[v16]->rgba;
          v149 = v147->m_Items[v62];
          v420 = LOBYTE(v149->m_Items[v66]);
          v151 = gFilterBuff;
          v153 = v151->m_Items[v16]->rgba;
          v155 = v153->m_Items[v62];
          v419 = BYTE1(v155->m_Items[v66]);
          v157 = gFilterBuff;
          v159 = v157->m_Items[v16]->rgba;
          v161 = v159->m_Items[v62];
          v416 = BYTE2(v161->m_Items[v66]);
          v163 = gFilterBuff;
          v165 = v163->m_Items[v16]->rgba;
          v167 = v165->m_Items[v62];
          v169 = HIBYTE(v167->m_Items[v66]);
          v175 = v408;
          v176 = fldDbg->FilterAlp + gFilterAnimeOfsA;
          if (!v408)
          {
            v175 = gFilter_RgbPar;
            if (!gFilter_RgbPar)
              goto LABEL_470;
LABEL_434:
            v177 = v175 * v428;
            if (v175 * v429 > 25599)
              v178 = 255;
            else
              v178 = v175 * v429 / 100;
            v429 = v178;
            v179 = v175 * v427;
            if (v177 > 25599)
              v180 = 255;
            else
              v180 = v177 / 100;
            v428 = v180;
            v181 = v175 * v426;
            if (v179 > 25599)
              v182 = 255;
            else
              v182 = v179 / 100;
            v427 = v182;
            v183 = v175 * v425;
            if (v181 > 25599)
              v184 = 255;
            else
              v184 = v181 / 100;
            v426 = v184;
            v185 = v175 * v424;
            if (v183 > 25599)
              v186 = 255;
            else
              v186 = v183 / 100;
            v425 = v186;
            v187 = v175 * v423;
            if (v185 > 25599)
              v188 = 255;
            else
              v188 = v185 / 100;
            v424 = v188;
            v189 = v175 * v422;
            if (v187 > 25599)
              v190 = 255;
            else
              v190 = v187 / 100;
            v423 = v190;
            v191 = v175 * v421;
            if (v189 > 25599)
              v192 = 255;
            else
              v192 = v189 / 100;
            v422 = v192;
            v193 = v175 * v420;
            if (v191 > 25599)
              v194 = 255;
            else
              v194 = v191 / 100;
            v421 = v194;
            v195 = v175 * v419;
            if (v193 > 25599)
              v196 = 255;
            else
              v196 = v193 / 100;
            v420 = v196;
            v197 = v175 * v416;
            if (v195 > 25599)
            {
              v419 = 255;
              if (v197 <= 25599)
                goto LABEL_468;
LABEL_466:
              v198 = 255;
            }
            else
            {
              v419 = v195 / 100;
              if (v197 > 25599)
                goto LABEL_466;
LABEL_468:
              v198 = v197 / 100;
            }
            v416 = v198;
            goto LABEL_470;
          }
          if (!gFilter_RgbPar)
            goto LABEL_434;
          v175 = gFilter_RgbPar * v408 / 100;
          if (v175)
            goto LABEL_434;
LABEL_470:
          v199 = (v176 + v93) & ~((v176 + v93) >> 31);
          if (v199 >= 255)
            v199 = 255;
          if (((v176 + v119) & ~((v176 + v119) >> 31)) >= 255)
            v200 = 255;
          else
            v200 = (v176 + v119) & ~((v176 + v119) >> 31);
          if (((v176 + v144) & ~((v176 + v144) >> 31)) >= 255)
            v201 = 255;
          else
            v201 = (v176 + v144) & ~((v176 + v144) >> 31);
          v418 = v199;
          else
          {
            v202 = v176 + v169;
            if (gFilterBlend < v10)
              goto LABEL_481;
          }
          v319 = v416;
          if ((v170->_2.bitflags2 & 2) == 0)
            goto LABEL_635;
LABEL_589:
LABEL_635:
          if (gFilterAlpha == 128)
          {
LABEL_591:
            v417 = v66 + 1;
            if ((v170->_2.bitflags2 & 2) == 0)
              goto LABEL_592;
            goto LABEL_643;
          }
LABEL_636:
          v429 = gFilterAlpha * v429 / 128;
          v428 = gFilterAlpha * v428 / 128;
          v427 = gFilterAlpha * v427 / 128;
          v418 = gFilterAlpha * v418 / 128;
          if (gFilterAlpha * v426 >= 0)
            v354 = gFilterAlpha * v426;
          else
            v354 = gFilterAlpha * v426 + 127;
          v426 = v354 >> 7;
          v425 = gFilterAlpha * v425 / 128;
          v424 = gFilterAlpha * v424 / 128;
          v200 = gFilterAlpha * v200 / 128;
          v423 = gFilterAlpha * v423 / 128;
          v422 = gFilterAlpha * v422 / 128;
          v421 = gFilterAlpha * v421 / 128;
          v201 = gFilterAlpha * v201 / 128;
          v420 = gFilterAlpha * v420 / 128;
          v419 = gFilterAlpha * v419 / 128;
          v319 = gFilterAlpha * v319 / 128;
          v202 = gFilterAlpha * v202 / 128;
          v417 = v66 + 1;
          if ((v170->_2.bitflags2 & 2) == 0)
          {
LABEL_592:
            v321 = v201;
            v322 = v319;
            goto LABEL_645;
          }
LABEL_643:
          v321 = v201;
          v322 = v319;
LABEL_645:
          v356 = v202;
          v358 = *(&SkyFilterObj->obj.klass + 8 * v66 + v404);
          transform = get_transform(v358, 0);
          Component_GUILayer = GetComponent_GUILayer_(transform);
          v443 = 0;
          sub_851710(&v443, 240.0, 155.0);
          set_sizeDelta(Component_GUILayer, v443);
          LODWORD(v446) = 0;
          v445 = 0;
          sub_8524C0(&v445, (v66 * 240.0) + -840.0, v65, 0.0);
          *&v447.x = v445;
          LODWORD(v447.z) = v446;
          set_localPosition(Component_GUILayer, v447);
          Component_object = GetComponent_object_(v358);
          if (op_Inequality(Component_object, 0, 0))
          {
            v445 = 0;
            v446 = 0;
            sub_19EC630(&v445, v429 / 255.0, v428 / 255.0, v427 / 255.0, v418 * 0.0078125);
            v363 = HIDWORD(v446);
            v364 = v445;
            LODWORD(Component_object[3].monitor) = v446;
            HIDWORD(Component_object[3].monitor) = v363;
            Component_object[3].klass = v364;
            v443 = 0;
            v444 = 0;
            v10 = 1.0;
            sub_19EC630(&v443, v426 / 255.0, v425 / 255.0, v424 / 255.0, v200 * 0.0078125);
            v365 = HIDWORD(v444);
            v366 = v443;
            LODWORD(Component_object[4].monitor) = v444;
            HIDWORD(Component_object[4].monitor) = v365;
            Component_object[4].klass = v366;
            v441 = 0;
            v442 = 0;
            sub_19EC630(&v441, v423 / 255.0, v422 / 255.0, v421 / 255.0, v321 * 0.0078125);
            v367 = HIDWORD(v442);
            v368 = v441;
            LODWORD(Component_object[5].monitor) = v442;
            HIDWORD(Component_object[5].monitor) = v367;
            Component_object[5].klass = v368;
            v439 = 0;
            v440 = 0;
            sub_19EC630(&v439, v420 / 255.0, v419 / 255.0, v322 / 255.0, v356 * 0.0078125);
            v370 = v440;
            v369 = HIDWORD(v440);
            Component_object[2].klass = v439;
            LODWORD(Component_object[2].monitor) = v370;
            HIDWORD(Component_object[2].monitor) = v369;
            v438 = 0;
            v437 = 0;
            sub_8524C0(&v437, -120.0, 77.5, 0.0);
            v371 = v438;
            *(&Component_object[6].monitor + 4) = v437;
            HIDWORD(Component_object[7].klass) = v371;
            v436 = 0;
            v435 = 0;
            sub_8524C0(&v435, 120.0, 77.5, 0.0);
            v372 = v436;
            Component_object[7].monitor = v435;
            LODWORD(Component_object[8].klass) = v372;
            v434 = 0;
            v433 = 0;
            sub_8524C0(&v433, 120.0, -77.5, 0.0);
            v373 = v434;
            v65 = (v64 * -155.0) + 462.5;
            *(&Component_object[8].klass + 4) = v433;
            HIDWORD(Component_object[8].monitor) = v373;
            v432 = 0;
            v431 = 0;
            sub_8524C0(&v431, -120.0, -77.5, 0.0);
            v374 = v432;
            Component_object[6].klass = v431;
            LODWORD(Component_object[6].monitor) = v374;
            Refresh(Component_object);
          }
          v16 = v403;
          gFilterNowIdx = v430;
          v66 = v417;
        }
        while (v417 != 8);
        v63 = v407 + 8;
        if (v62 == 7)
        {
          v376 = gFilterAnimeOfsA;
          v378 = fldGb;
          v379 = v61 + v376;
          if (v378->fieldID == 14)
          {
            v380 = v378->areaID;
            if (v380 == 5)
              goto LABEL_669;
            if (v380 == 16)
LABEL_669:
              v379 = -90.0;
          }
          v381 = fldGb;
          if (v381->fieldID == 17)
          {
            v382 = v381->areaID;
            if (v382 == 1)
              goto LABEL_686;
            if (v382 == 2)
              goto LABEL_686;
            if (v382 == 4)
LABEL_686:
              v379 = -90.0;
          }
          v383 = fldGb;
          if (v383->fieldID == 35)
          {
            v384 = v383->areaID;
            if (!v384)
              goto LABEL_715;
            if (v384 == 2)
              goto LABEL_715;
            if (v384 == 3)
              goto LABEL_715;
            if (v384 == 4)
              goto LABEL_715;
            if (v384 == 5)
              goto LABEL_715;
            if (v384 == 6)
LABEL_715:
              v379 = -80.0;
          }
          v385 = fldGb->fieldID;
          if (v385 == 60)
            goto LABEL_724;
          if (v385 == 61)
LABEL_724:
            v379 = -100.0;
          v386 = fldGb;
          v388 = v386->fieldID;
          v390 = v379 + v379;
          if (v388 == 3)
            v390 = -150.0;
          FieldFilterAlf(kernelObject, v390);
          rsetTest(1, 5, 128, 1, 0, 0, 1, 2);
          rsetAlpha(0);
          return;
        }
      }
    }
  }
}

// 0x160bcf0
void fldSkyFieldLoad(s32 field) {
  Il2CppObject *v7;
  u64 *v8;
  s64 *v9;
  System_String_o *v10;
  System_String_o *v11;
  u64 *v12;
  System_String_o *v14;
  bool IsDLCField;
  s64 *v16;
  System_String_o *v18;
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  u64 v22;
  s32 v23;
  struct fldSky_typeSKYTBL_array *gSkyTbl;
  s32 v27;
  u64 i;
  struct fldSky_typeSKYTBL_array *v30;
  fldSky_typeSKYTBL_o *v32;
  s32 v33;
  s64 a0_b;
  s64 a0_r;
  s64 l0_g;
  System_String_o *pathstr;

  a0_r = 0;
  l0_g = 0;
  a0_b = 0;
  pathstr = "";
  gFilterAlpha = 128;
  if (field <= 199)
  {
    fldMakeFilePath(&pathstr, field, 1);
    if (fldGb->fieldID == 25
      && evtBitCheck(1433)
      && !evtBitCheck(1859))
    {
      goto LABEL_21;
    }
    if (fldGb->fieldID == 24)
    {
      if (evtBitCheck(79))
      {
LABEL_21:
        v33 = field;
        v7 = pathstr;
        v8 = sub_8D3950(s32, &v33);
        v9 = &"{0}F{1:D3}b.SKY.bytes";
LABEL_30:
        v10 = Format_5268592(*v9, v7, v8);
        v33 = field;
        v11 = v10;
        v12 = sub_8D3950(s32, &v33);
        v14 = Format("f{0:D3}", v12, 0);
        IsDLCField = IsDLCField(field);
        v16 = &"m";
        if (!IsDLCField)
          v16 = &"";
        v18 = Concat_5224608(v14, *v16);
        asset_bc = get_asset_bc();
        FileByte = LoadFileByte(asset_bc, v18, v11);
        v22 = 0;
        v23 = 0;
        do
        {
          v27 = fldSky_typeSKYTBL__Copy(gSkyTbl->m_Items[v22++], FileByte, v23);
          v23 = v27;
        }
        while (v22 != 256);
        for (i = 0; i != 64; ++i)
        {
          v30 = gSkyTbl;
          v32 = v30->m_Items[i];
          HIDWORD(l0_g) = LODWORD(v32->sr0);
          *&l0_g = v32->sg0;
          HIDWORD(a0_r) = LODWORD(v32->sb0);
          *&a0_r = v32->sr3;
          HIDWORD(a0_b) = LODWORD(v32->sg3);
          *&a0_b = v32->sb3;
          OverWrite_SkyLight(field, i, &l0_g + 1, &l0_g, &a0_r + 1, &a0_r, &a0_b + 1, &a0_b);
          v32->sr0 = *(&l0_g + 1);
          LODWORD(v32->sg0) = l0_g;
          v32->sb0 = *(&a0_r + 1);
          LODWORD(v32->sr3) = a0_r;
          v32->sg3 = *(&a0_b + 1);
          LODWORD(v32->sb3) = a0_b;
        }
        return;
      }
    }
    if (fldGb->fieldID == 24 && evtBitCheck(22) && !evtBitCheck(62))
    {
      v33 = field;
      v7 = pathstr;
      v8 = sub_8D3950(s32, &v33);
      v9 = &"{0}F{1:D3}c.SKY.bytes";
    }
    else
    {
      v33 = field;
      v7 = pathstr;
      v8 = sub_8D3950(s32, &v33);
      v9 = &"{0}F{1:D3}.SKY.bytes";
    }
    goto LABEL_30;
  }
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
      goto LABEL_11;
  }
  if (data->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
  {
    if (data->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == UnityEngine_TextAsset)
      v4 = data;
    else
      v4 = 0;
    goto LABEL_12;
  }
LABEL_11:
  v4 = 0;
LABEL_12:
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
  s32 v5;
  s32 gSkyTblNowIdxLM;
  struct fldSky_typeSKYTBL_array *gSkyTbl;
  s64 gSkyTblNowIdx;
  fldSky_typeSKYTBL_o *v12;
  struct fldDebug_t_o *fldDbg;
  s32 FilterID;
  s32 FilterMode;
  s32 FilterAnm;
  s64 v20;
  s64 v21;
  u64 *v22;
  dds3Basic_t_o *player;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o v26;
  evtUnitHandle_t_o *h;
  UnityEngine_Vector4_o v28;

  h = 0;
  *&v26.x = 0;
  *&v26.z = 0;
  *&v25.x = 0;
  *&v25.z = 0;
  if (fldGb->fieldID <= 199)
  {
    {
      else
      {
        if (gSkyTblNowIdxLM)
          goto LABEL_9;
      }
    }
    else
    {
      v5 = 0;
      if (gSkyTblNowIdxLM)
      {
LABEL_9:
        gSkyTblNowIdx = gSkyTblNowIdxLM;
        if (gSkyTblNowIdxLM >= LODWORD(gSkyTbl->max_length))
          goto LABEL_13;
LABEL_14:
        v12 = gSkyTbl->m_Items[gSkyTblNowIdx];
        FilterID = fldDbg->FilterID;
        FilterMode = fldDbg->FilterMode;
        fldSkySetFilter(FilterID, FilterMode, 0);
        FilterAnm = fldDbg->FilterAnm;
        gFilterAnime = FilterAnm;
        gFilterAnimeCntF = 0.0;
        gFilterAnimeOfsA = 0;
        sub_854930(&v26, 0);
        sub_854930(&v26, 1u);
        sub_854930(&v26, 2u);
        sub_854930(&v26, 3u);
        v20 = *&v26.x;
        v21 = *&v26.z;
        *&v28.x = v20;
        *&v28.z = v21;
        dds3SetFogColor(0, v28);
        dds3SetFogPara(0, v12->FogMax, v12->FogMin, v12->FogNear, v12->FogFar);
        sub_854930(&v25, 0);
        sub_854930(&v25, 1u);
        sub_854930(&v25, 2u);
        sub_854930(&v25, 3u);
        dds3SetLightDir(0, 0, v25);
        sub_854930(&v26, 0);
        sub_854930(&v26, 1u);
        sub_854930(&v26, 2u);
        sub_854930(&v26, 3u);
        dds3SetLightColor(0, 0, v26);
        sub_854930(&v25, 0);
        sub_854930(&v25, 1u);
        sub_854930(&v25, 2u);
        sub_854930(&v25, 3u);
        dds3SetLightDir(0, 1u, v25);
        sub_854930(&v26, 0);
        sub_854930(&v26, 1u);
        sub_854930(&v26, 2u);
        sub_854930(&v26, 3u);
        dds3SetLightColor(0, 1u, v26);
        sub_854930(&v25, 0);
        sub_854930(&v25, 1u);
        sub_854930(&v25, 2u);
        sub_854930(&v25, 3u);
        dds3SetLightDir(0, 2u, v25);
        sub_854930(&v26, 0);
        sub_854930(&v26, 1u);
        sub_854930(&v26, 2u);
        sub_854930(&v26, 3u);
        dds3SetLightColor(0, 2u, v26);
        sub_854930(&v26, 0);
        sub_854930(&v26, 1u);
        sub_854930(&v26, 2u);
        sub_854930(&v26, 3u);
        dds3SetAmbientColor(0, v26);
        v22 = Allocate(evtUnitHandle_t);
        evtUnitHandle_t___ctor(v22);
        h = v22;
        h = evtGetUnitHandle2(player);
        evtUnitLightOn(&h);
        evtSetUnitLightAndAmbient(
          &h,
          0,
          vcvts_n_s32_f32(v12->pr0, 7u)
        | (vcvts_n_s32_f32(v12->pg0, 7u) << 8)
        | (vcvts_n_s32_f32(v12->pb0, 7u) << 16)
        | 0x80000000,
          vcvts_n_s32_f32(v12->pr3, 7u)
        | (vcvts_n_s32_f32(v12->pg3, 7u) << 8)
        | (vcvts_n_s32_f32(v12->pb3, 7u) << 16)
        | 0x80000000,
          0);
        sub_854930(&v25, 0);
        sub_854930(&v25, 1u);
        sub_854930(&v25, 2u);
        sub_854930(&v25, 3u);
        SDF_VU0__LOADVECTOR(v25);
        evtSetUnitLightDir(&h, 0);
        SDF_VU0__LOADVECTOR(v25);
        evtSetUnitLightDir(&h, 0);
        return;
      }
    }
    if (gSkyTblNowIdx >= LODWORD(gSkyTbl->max_length))
    {
LABEL_13:
    }
    goto LABEL_14;
  }
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
  struct fldGlobalWork_t_o *fldGb;
  fldSky_c *v9;
  s64 gFilterNowIdx;

  if (!gfldSkyHokan)
    goto LABEL_21;
LABEL_6:
  if (!hokan)
    goto LABEL_29;
LABEL_7:
  if (fldGb->fieldID != 651)
    goto LABEL_14;
  else if (fldGb->areaID)
  {
    goto LABEL_14;
  }
  if (!SkyFilterObj)
    goto LABEL_14;
  if (gFilterBlend <= 0.99)
    goto LABEL_14;
  if (gFilterNowIdx != idx)
  {
LABEL_14:
    gFilterBlend = 0.0;
    gFilterBlendIdx = gFilterNowIdx;
    gFilterBlendSpd = hokan;
    if ((v9->_2.bitflags2 & 2) == 0)
      goto LABEL_33;
    goto LABEL_18;
  }
}

// 0x160ff50
void fldSkySetFilterAnime(s32 type) {
  gFilterAnime = type;
  gFilterAnimeCntF = 0.0;
  gFilterAnimeOfsA = 0;
}

// 0x1610470
void fldSkySetPlayer(s32 intr, f32 r0, f32 g0, f32 b0, f32 r3, f32 g3, f32 b3, f32 x0, f32 y0, f32 z0) {
  u64 *v18;
  dds3Basic_t_o *player2;
  dds3Basic_t_o *player3;
  dds3Basic_t_o *player;
  u32 v24;
  u32 v25;
  struct sdf3DLight_t_array *fld_player_lights;
  struct sdf3DLight_t_array *v36;
  struct sdf3DLight_t_array *v38;
  struct sdf3DLight_t_array *v40;
  struct sdf3DLight_t_array *v42;
  struct sdf3DLight_t_array *v44;
  UnityEngine_Vector4_o v46;
  evtUnitHandle_t_o *UnitHandle2;
  evtUnitHandle_t_o *h;
  evtUnitHandle_t_o *v49;

  v18 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v18);
  v49 = v18;
  UnitHandle2 = 0;
  h = 0;
  *&v46.x = 0;
  *&v46.z = 0;
  if (player2)
  {
    h = evtGetUnitHandle2(player2);
    evtUnitLightOn(&h);
  }
  if (player3)
  {
    UnitHandle2 = evtGetUnitHandle2(player3);
    evtUnitLightOn(&UnitHandle2);
  }
  v49 = evtGetUnitHandle2(player);
  evtUnitLightOn(&v49);
  v24 = vcvts_n_s32_f32(r0, 7u) | (vcvts_n_s32_f32(g0, 7u) << 8) | (vcvts_n_s32_f32(b0, 7u) << 16) | 0x80000000;
  v25 = vcvts_n_s32_f32(r3, 7u) | (vcvts_n_s32_f32(g3, 7u) << 8) | (vcvts_n_s32_f32(b3, 7u) << 16) | 0x80000000;
  evtSetUnitLightAndAmbient(&v49, intr, v24, v25);
  if (player2)
  {
    evtSetUnitLightAndAmbient(&h, intr, v24, v25);
  }
  if (player3)
  {
    evtSetUnitLightAndAmbient(&UnitHandle2, intr, v24, v25);
  }
  sub_854930(&v46, 0);
  sub_854930(&v46, 1u);
  sub_854930(&v46, 2u);
  sub_854930(&v46, 3u);
  SDF_VU0__LOADVECTOR(v46);
  evtSetUnitLightDir(&v49, intr);
  if (player2)
  {
    evtSetUnitLightDir(&h, intr);
  }
  if (player3)
  {
    evtSetUnitLightDir(&UnitHandle2, intr);
  }
  SDF_VU0__LOADVECTOR(v46);
  evtSetUnitLightDir(&v49, 0);
  if (player2)
  {
    evtSetUnitLightDir(&h, 0);
  }
  if (player3)
  {
    evtSetUnitLightDir(&UnitHandle2, 0);
  }
  else
  {
    if (!LODWORD(fld_player_lights->max_length))
      goto LABEL_85;
  }
  sub_854930(&fld_player_lights->m_Items[0]->fields, 0);
  v36 = fld_player_lights;
  sub_854930(&v36->m_Items[0]->fields, 1u);
  v38 = fld_player_lights;
  sub_854930(&v38->m_Items[0]->fields, 2u);
  v40 = fld_player_lights;
  sub_854930(&v40->m_Items[0]->v, 0);
  v42 = fld_player_lights;
  sub_854930(&v42->m_Items[0]->v, 1u);
  v44 = fld_player_lights;
  sub_854930(&v44->m_Items[0]->v, 2u);
  sub_854930(&fld_player_ambient, 0);
  sub_854930(&fld_player_ambient, 1u);
  sub_854930(&fld_player_ambient, 2u);
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
  s32 v4;
  s32 v9;
  struct fldSky_typeSKYTBL_array *gSkyTbl;
  s64 gSkyTblNowIdx;
  fldSky_typeSKYTBL_o *v16;
  s32 FilterAnm;
  s64 v21;
  s64 v22;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;

  v4 = hokan;
  *&v26.x = 0;
  *&v26.z = 0;
  *&v25.x = 0;
  *&v25.z = 0;
  if (fldGb->fieldID > 199)
    return;
  else if (!gfldSkyHokan)
  {
    goto LABEL_10;
  }
  if (v4)
    v9 = 15;
  else
    v9 = 0;
  if (v4 < 2)
    v4 = v9;
  gSkyTblNowIdx = idx;
  bk_gSkyTblNowIdx = gSkyTblNowIdx;
  gSkyNowUpper = 0;
  else if (fldGb->LightMa)
  {
    return;
  }
  v16 = gSkyTbl->m_Items[gSkyTblNowIdx];
  fldDbg->FilterID = v16->FilterID;
  fldDbg->FilterID = LOBYTE(fldDbg->FilterID);
  gHokanOld_fldDbg_FilterAlp = fldDbg->FilterAlp;
  fldDbg->FilterAlp = v16->FilterAlp;
  fldDbg->FilterMode = v16->FilterMode;
  fldDbg->FilterAnm = v16->FilterAnm;
  fldSkySetFilter(fldDbg->FilterID, fldDbg->FilterMode, v4);
  FilterAnm = fldDbg->FilterAnm;
  gFilterAnime = FilterAnm;
  gFilterAnimeCntF = 0.0;
  gFilterAnimeOfsA = 0;
  sub_854930(&v26, 0);
  sub_854930(&v26, 1u);
  sub_854930(&v26, 2u);
  sub_854930(&v26, 3u);
  v21 = *&v26.x;
  v22 = *&v26.z;
  *&v27.x = v21;
  *&v27.z = v22;
  dds3SetFogColor(v4, v27);
  dds3SetFogPara(v4, v16->FogMax, v16->FogMin, v16->FogNear, v16->FogFar);
  sub_854930(&v25, 0);
  sub_854930(&v25, 1u);
  sub_854930(&v25, 2u);
  sub_854930(&v25, 3u);
  dds3SetLightDir(v4, 0, v25);
  sub_854930(&v26, 0);
  sub_854930(&v26, 1u);
  sub_854930(&v26, 2u);
  sub_854930(&v26, 3u);
  dds3SetLightColor(v4, 0, v26);
  sub_854930(&v25, 0);
  sub_854930(&v25, 1u);
  sub_854930(&v25, 2u);
  sub_854930(&v25, 3u);
  dds3SetLightDir(v4, 1u, v25);
  sub_854930(&v26, 0);
  sub_854930(&v26, 1u);
  sub_854930(&v26, 2u);
  sub_854930(&v26, 3u);
  dds3SetLightColor(v4, 1u, v26);
  sub_854930(&v25, 0);
  sub_854930(&v25, 1u);
  sub_854930(&v25, 2u);
  sub_854930(&v25, 3u);
  dds3SetLightDir(v4, 2u, v25);
  sub_854930(&v26, 0);
  sub_854930(&v26, 1u);
  sub_854930(&v26, 2u);
  sub_854930(&v26, 3u);
  dds3SetLightColor(v4, 2u, v26);
  sub_854930(&v26, 0);
  sub_854930(&v26, 1u);
  sub_854930(&v26, 2u);
  sub_854930(&v26, 3u);
  dds3SetAmbientColor(v4, v26);
  gFilter_RgbPar = 0;
  gHokanOld_gFilter_RgbPar = 0;
  gHokanOld_gFilter_RgbPar_before = 0;
  gHokanOld_gFilter_RgbPar_BlendIdx = 0;
  fldSkySetPlayer(v4, v16->pr0, v16->pg0, v16->pb0, v16->pr3, v16->pg3, v16->pb3, v16->px0, v16->py0, v16->pz0);
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
  s32 v4;
  s32 v9;
  s32 SkyTblID;
  struct fldSky_typeSKYTBL_array *gSkyTbl;
  s64 gSkyTblNowIdxLM;
  fldSky_typeSKYTBL_o *v17;
  s32 FilterAnm;
  s64 v23;
  s64 v24;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o v28;

  v4 = hokan;
  *&v27.x = 0;
  *&v27.z = 0;
  *&v26.x = 0;
  *&v26.z = 0;
  if (fldGb->fieldID <= 199)
  {
    else if (!gfldSkyHokan)
    {
      goto LABEL_10;
    }
    if (v4)
      v9 = 15;
    else
      v9 = 0;
    if (v4 < 2)
      v4 = v9;
    if (gSkyTblNowIdxLM != idx)
    {
      SkyTblID = fldDbg->SkyTblID;
      bk_SkyTblID = SkyTblID;
      if (!idx)
      {
        idx = gSkyTblNowIdx;
      }
      fldDbg->SkyTblID = idx;
      gSkyTblNowIdxLM = idx;
      v17 = gSkyTbl->m_Items[gSkyTblNowIdxLM];
      fldDbg->FilterID = v17->FilterID;
      fldDbg->FilterID = LOBYTE(fldDbg->FilterID);
      gHokanOld_fldDbg_FilterAlp = fldDbg->FilterAlp;
      fldDbg->FilterAlp = v17->FilterAlp;
      fldDbg->FilterMode = v17->FilterMode;
      fldDbg->FilterAnm = v17->FilterAnm;
      fldSkySetFilter(fldDbg->FilterID, fldDbg->FilterMode, v4);
      FilterAnm = fldDbg->FilterAnm;
      gFilterAnime = FilterAnm;
      gFilterAnimeCntF = 0.0;
      gFilterAnimeOfsA = 0;
      sub_854930(&v27, 0);
      sub_854930(&v27, 1u);
      sub_854930(&v27, 2u);
      sub_854930(&v27, 3u);
      v23 = *&v27.x;
      v24 = *&v27.z;
      *&v28.x = v23;
      *&v28.z = v24;
      dds3SetFogColor(v4, v28);
      dds3SetFogPara(v4, v17->FogMax, v17->FogMin, v17->FogNear, v17->FogFar);
      sub_854930(&v26, 0);
      sub_854930(&v26, 1u);
      sub_854930(&v26, 2u);
      sub_854930(&v26, 3u);
      dds3SetLightDir(v4, 0, v26);
      sub_854930(&v27, 0);
      sub_854930(&v27, 1u);
      sub_854930(&v27, 2u);
      sub_854930(&v27, 3u);
      dds3SetLightColor(v4, 0, v27);
      sub_854930(&v26, 0);
      sub_854930(&v26, 1u);
      sub_854930(&v26, 2u);
      sub_854930(&v26, 3u);
      dds3SetLightDir(v4, 1u, v26);
      sub_854930(&v27, 0);
      sub_854930(&v27, 1u);
      sub_854930(&v27, 2u);
      sub_854930(&v27, 3u);
      dds3SetLightColor(v4, 1u, v27);
      sub_854930(&v26, 0);
      sub_854930(&v26, 1u);
      sub_854930(&v26, 2u);
      sub_854930(&v26, 3u);
      dds3SetLightDir(v4, 2u, v26);
      sub_854930(&v27, 0);
      sub_854930(&v27, 1u);
      sub_854930(&v27, 2u);
      sub_854930(&v27, 3u);
      dds3SetLightColor(v4, 2u, v27);
      sub_854930(&v27, 0);
      sub_854930(&v27, 1u);
      sub_854930(&v27, 2u);
      sub_854930(&v27, 3u);
      dds3SetAmbientColor(v4, v27);
      fldSkySetPlayer(v4, v17->pr0, v17->pg0, v17->pb0, v17->pr3, v17->pg3, v17->pb3, v17->px0, v17->py0, v17->pz0);
    }
  }
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
  fldSky_c *v4;
  s32 bk_gSkyTblNowIdx;

  if (!gfldSkyHokan)
    goto LABEL_11;
LABEL_6:
  if ((v4->_2.bitflags2 & 2) == 0)
    goto LABEL_17;
LABEL_7:
LABEL_17:
  if (!bk_gSkyTblNowIdx)
    return;
LABEL_18:
  if (gSkyTblNowIdx != bk_gSkyTblNowIdx)
    goto LABEL_23;
}

// 0x1610d90
void fldSkySetTblUpper(s32 idx, s32 hokan) {
  s32 v4;
  s32 v9;
  struct fldSky_typeSKYTBL_array *gSkyTbl;
  s64 gSkyTblNowIdx;
  fldSky_typeSKYTBL_o *v19;
  s32 FilterAnm;
  s64 v25;
  s64 v26;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o v29;
  UnityEngine_Vector4_o v30;

  v4 = hokan;
  *&v29.x = 0;
  *&v29.z = 0;
  *&v28.x = 0;
  *&v28.z = 0;
  if (fldGb->fieldID <= 199)
  {
    else if (!gfldSkyHokan)
    {
      goto LABEL_10;
    }
    if (v4)
      v9 = 15;
    else
      v9 = 0;
    if (v4 < 2)
      v4 = v9;
    if (gSkyTblNowIdx != idx)
    {
      bk_gFilterAnime = gFilterAnime;
      bk_gFilterAnimeCntF = gFilterAnimeCntF;
      bk_gFilterAnimeOfsA = gFilterAnimeOfsA;
      bk_gFilterNowIdx = gFilterNowIdx;
      bk_gFilterBlendIdx = gFilterBlendIdx;
      bk_gFilterBlend = gFilterBlend;
      bk_gFilterBlendSpd = gFilterBlendSpd;
      if (!gSkyNowUpper)
      {
        bk_gSkyTblNowIdx = gSkyTblNowIdx;
      }
      bk_gSkyTblAnime = gSkyTblAnime;
      bk_gSkyTblAnimeCntI = gSkyTblAnimeCntI;
      bk_gSkyTblBaseIdx = gSkyTblBaseIdx;
      gSkyNowUpper = 1;
      gSkyTblNowIdx = idx;
      if (!fldGb->LightMa)
      {
        fldDbg->SkyTblID = idx;
        v19 = gSkyTbl->m_Items[gSkyTblNowIdx];
        fldDbg->FilterID = v19->FilterID;
        fldDbg->FilterID = LOBYTE(fldDbg->FilterID);
        gHokanOld_fldDbg_FilterAlp = fldDbg->FilterAlp;
        fldDbg->FilterAlp = v19->FilterAlp;
        fldDbg->FilterMode = v19->FilterMode;
        fldDbg->FilterAnm = v19->FilterAnm;
        fldSkySetFilter(fldDbg->FilterID, fldDbg->FilterMode, v4);
        FilterAnm = fldDbg->FilterAnm;
        gFilterAnime = FilterAnm;
        gFilterAnimeCntF = 0.0;
        gFilterAnimeOfsA = 0;
        sub_854930(&v29, 0);
        sub_854930(&v29, 1u);
        sub_854930(&v29, 2u);
        sub_854930(&v29, 3u);
        v25 = *&v29.x;
        v26 = *&v29.z;
        *&v30.x = v25;
        *&v30.z = v26;
        dds3SetFogColor(v4, v30);
        dds3SetFogPara(v4, v19->FogMax, v19->FogMin, v19->FogNear, v19->FogFar);
        sub_854930(&v28, 0);
        sub_854930(&v28, 1u);
        sub_854930(&v28, 2u);
        sub_854930(&v28, 3u);
        dds3SetLightDir(v4, 0, v28);
        sub_854930(&v29, 0);
        sub_854930(&v29, 1u);
        sub_854930(&v29, 2u);
        sub_854930(&v29, 3u);
        dds3SetLightColor(v4, 0, v29);
        sub_854930(&v28, 0);
        sub_854930(&v28, 1u);
        sub_854930(&v28, 2u);
        sub_854930(&v28, 3u);
        dds3SetLightDir(v4, 1u, v28);
        sub_854930(&v29, 0);
        sub_854930(&v29, 1u);
        sub_854930(&v29, 2u);
        sub_854930(&v29, 3u);
        dds3SetLightColor(v4, 1u, v29);
        sub_854930(&v28, 0);
        sub_854930(&v28, 1u);
        sub_854930(&v28, 2u);
        sub_854930(&v28, 3u);
        dds3SetLightDir(v4, 2u, v28);
        sub_854930(&v29, 0);
        sub_854930(&v29, 1u);
        sub_854930(&v29, 2u);
        sub_854930(&v29, 3u);
        dds3SetLightColor(v4, 2u, v29);
        sub_854930(&v29, 0);
        sub_854930(&v29, 1u);
        sub_854930(&v29, 2u);
        sub_854930(&v29, 3u);
        dds3SetAmbientColor(v4, v29);
        fldSkySetPlayer(v4, v19->pr0, v19->pg0, v19->pb0, v19->pr3, v19->pg3, v19->pb3, v19->px0, v19->py0, v19->pz0);
      }
    }
  }
}

// 0x1610250
void fldSkySet_RgbPar(s32 par) {
  gFilter_RgbPar = par;
}

// 0x1611e00
void fldSky_DebugFastInit(void) {
  struct fldSky_StaticFields *static_fields;
  struct dds3LightEditorWork_t_o *fld_player_light_work;
  s64 v6;
  f32 z;

  dds3LightEditorWork_t__Clear(fld_player_light_work);
  fld_player_light_work->lightSrc = fld_player_lights;
  v6 = *&fld_player_ambient.x;
  z = fld_player_ambient.z;
  *&static_fields = fld_player_ambient.w;
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
