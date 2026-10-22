#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct PostBlur PostBlur;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct stfGlobal stfGlobal;

static stfGlobal *gGlobal;
static s32 IMGcnt;
static s32 IMGcnt2;
static char *EndingBackImageStr;
static void *EndingBackImage;
static char *EndingLineImageStr;
static void *EndingLineImage;
static char *EndingMaskImageStr;
static void *EndingMaskImage;
static void *CapcomLogo;
static void *EndingUseBackImage;
static void *EndingUseLineImage;
static f32 red;
static f32 green;
static f32 blue;
static f32 alpha;
static f32 alpha_;
static f32 fill;
static s32 debugFlg;
static s32 debugPos;
static s32 debugStrPos;
static void *debugImage;
static s32 ImageTiming;
static f32 alphaSpeed;
static f32 alpha_Speed;
static f32 fill_Speed;
static f32 lineAdjust;
static f32 fillAdjust;
static bool PicDispflag;
static bool FadeOutflag;
static bool LastFade;
static f32 fx;
static f32 fa;
static f32 fmx;
static f32 fw1;
static f32 fa1;
static s32 STAFF_IMAGE_MAX_NO;
static s32 STAFF_IMAGE_ONE_TIME;
static void *ButtonObj;
static void *FFobj;
static void *Skyobj;
static void *Kuti;
static void *ShadowC;
static void *FFCobj;
static void *TalkObj;
static void *CameraObj;
static void *MainCamera;
static PostBlur *Blur;
static void *PostObj;
static void *EndingLineImage_;
static void *EndingBackImage_;
static char *g_staff_pic_filename[15];
static char *g_staff_mpic_filename[15];
static s32 center_cnt;
static s32 staffname_cnt;
static s32 jobname_cnt;
static s32 Mojimoveflag;
static s32 centername_cnt;
static s32 staffnameobj_cnt;
static s32 jobnameobj_cnt;
static s32 centerobj_max;
static s32 jobobj_max;
static s32 staffobj_max;
static f32 mojispeed;
static s32 LogoPos;
static s32 newStaffAdjust;
static f32 lastposAdjust;
static s32 LogoPosAdjust;
static f32 posAdjust;
static f32 FrameWidth;
static f32 FrameHeight;
static s32 useLang;
static void *useFont;
static char *centername_str;
static char *jobname_str;
static char *staffname_str;
static void *FrameWH;
static void *StaffUIObj;
static void *staff_nameobj;
static void *center_nameobj;
static void *job_nameobj;
static void *centerNameTM;
static void *staffNameTM;
static void *jobNameTM;
static void *oStaff_UI;

void ClearStaffUI(void);
void EndingStaffRollUnlock(void);
void FilterDelete(void);
s32 FindId(s32 type, char *name);
s32 GetLanguage(void);
void *GetMainCamera(dds3DefaultMain *this);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void *LoadAsset(AssetBundleCtrl *this, char *key, char *path, char *name);
void LoadKeys(s32 type, char *key, char *path);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void ObjDispON(void);
void ObjDispOff(void);
void RemoveKeys(s32 type, char *key);
void SetNormalFrameRate(dds3DefaultMain *this);
void StaffImageManager(void);
void UnloadAB(AssetBundleCtrl *this, char *key);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
s32 p2sdPlayBGM(s32 a);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void sdfTexFree(sdfTexHandle_t *aHandle);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);
sdfTexHandle_t *sdfTexSet(void *aTex);
void stfDrawImage2(void);
void stfFreeTex(void);
void stfImageEnd(void);
void stfImageStart(s32 no, s32 life, s32 dir);
void stfInit(void);
void stfSetTex(s32 i);

// 0x169b5d0
void ClearStaffUI(void) {
  UnityEngine_Object_o *oStaff_UI;
  UnityEngine_Object_o *v6;

  if (op_Inequality(oStaff_UI, 0, 0))
  {
    v6 = oStaff_UI;
    Destroy_27360000(v6);
    oStaff_UI = 0;
  }
}

// 0x169ad50
void *GetoStaffUI(void) {
  return oStaff_UI;
}

// 0x169b6d0
void ObjDispON(void) {
  UnityEngine_Object_o *ButtonObj;
  UnityEngine_Object_o *Skyobj;
  UnityEngine_Object_o *Kuti;
  UnityEngine_Object_o *TalkObj;
  UnityEngine_Object_o *ShadowC;
  UnityEngine_Object_o *FFCobj;

  set_enabled(Blur, 1);
  set_enabled(PostObj, 1);
  if (op_Inequality(ButtonObj, 0, 0))
  {
    if (!get_activeSelf(ButtonObj))
    {
      SetActive(ButtonObj, 1, 0);
    }
  }
  if (op_Inequality(Skyobj, 0, 0))
  {
    if (!get_activeSelf(Skyobj))
    {
      SetActive(Skyobj, 1, 0);
    }
  }
  if (op_Inequality(Kuti, 0, 0))
  {
    if (!get_activeSelf(Kuti))
    {
      SetActive(Kuti, 1, 0);
    }
  }
  if (op_Inequality(TalkObj, 0, 0))
  {
    if (get_activeSelf(TalkObj))
    {
      SetActive(TalkObj, 1, 0);
    }
  }
  if (op_Inequality(ShadowC, 0, 0))
  {
    if (!get_activeSelf(ShadowC))
    {
      SetActive(ShadowC, 1, 0);
    }
  }
  if (op_Inequality(FFCobj, 0, 0))
  {
    if (!get_activeSelf(FFCobj))
    {
      SetActive(FFCobj, 1, 0);
    }
  }
}

// 0x169adc0
void ObjDispOff(void) {
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  Il2CppObject *v8;
  Il2CppObject *v10;
  struct UnityEngine_GameObject_o *v12;
  UnityEngine_Object_o *ButtonObj;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Object_o *Skyobj;
  UnityEngine_GameObject_o *v28;
  UnityEngine_Object_o *Kuti;
  UnityEngine_GameObject_o *v36;
  UnityEngine_Object_o *TalkObj;
  UnityEngine_GameObject_o *v44;
  UnityEngine_Object_o *ShadowC;
  UnityEngine_GameObject_o *v52;
  UnityEngine_Object_o *FFCobj;

  MainCamera = GetMainCamera(kernelObject);
  CameraObj = MainCamera;
  Component_object = GetComponent_object_(CameraObj);
  Blur = Component_object;
  v8 = GetComponent_object_(CameraObj);
  MainCamera = v8;
  v10 = GetComponent_object_(CameraObj);
  PostObj = v10;
  set_enabled(Blur, 0);
  set_enabled(PostObj, 0);
  v12 = Find("buttonguide01", 0);
  ButtonObj = v12;
  if (op_Inequality(ButtonObj, 0, 0))
  {
    if (get_activeSelf(ButtonObj))
    {
      SetActive(ButtonObj, 0, 0);
    }
  }
  FilterDelete();
  v20 = Find("Canvas_UI/Sky", 0);
  Skyobj = v20;
  if (op_Inequality(Skyobj, 0, 0))
  {
    if (get_activeSelf(Skyobj))
    {
      SetActive(Skyobj, 0, 0);
    }
  }
  v28 = Find("Canvas_UI/KutiManager", 0);
  Kuti = v28;
  if (op_Inequality(Kuti, 0, 0))
  {
    if (get_activeSelf(Kuti))
    {
      SetActive(Kuti, 0, 0);
    }
  }
  v36 = Find("Canvas_UI/talkUI", 0);
  TalkObj = v36;
  if (op_Inequality(TalkObj, 0, 0))
  {
    if (get_activeSelf(TalkObj))
    {
      SetActive(TalkObj, 0, 0);
    }
  }
  v44 = Find("ShadowCameras", 0);
  ShadowC = v44;
  if (op_Inequality(ShadowC, 0, 0))
  {
    if (get_activeSelf(ShadowC))
    {
      SetActive(ShadowC, 0, 0);
    }
  }
  v52 = Find("FieldFilterCamera", 0);
  FFCobj = v52;
  if (op_Inequality(FFCobj, 0, 0))
  {
    if (get_activeSelf(FFCobj))
    {
      SetActive(FFCobj, 0, 0);
    }
  }
}

// 0x1695e30
s32 STAFF_IMAGE_DRAWTIME(s32 keisu) {
  return STAFF_IMAGE_ONE_TIME * keisu;
}

// 0x1695ea0
void StaffImageManager(void) {
  u64 v3;
  struct stfMain_StaticFields *static_fields;
  struct stfGlobal_o *gGlobal;
  s32 cnt;
  s16 v7;
  s32 v8;
  s32 ImgDrawCount;
  s32 v10;
  struct stfMain_StaticFields *v11;
  UnityEngine_Object_o *v12;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v16;
  struct UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v19;
  UnityEngine_Transform_o *v20;
  f32 x;
  UnityEngine_Transform_o *v22;
  s32 v25;
  s32 v26;
  UnityEngine_Transform_o *v27;
  UnityEngine_Transform_o *v28;
  f32 v29;
  UnityEngine_Transform_o *v30;
  f32 mojispeed;
  f32 v33;
  UnityEngine_Transform_o *v34;
  f32 z;
  f32 y;
  f32 v37;
  UnityEngine_Vector3_o v38;

  static_fields = *(v3 + 184);
  if (gGlobal->ImgDrawCount <= 14)
  {
    cnt = gGlobal->cnt;
    if (cnt >= 1920)
    {
      if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
      {
        cnt = gGlobal->cnt;
      }
      if ((cnt - 1920) / STAFF_IMAGE_ONE_TIME >= gGlobal->ImgDrawCount)
      {
        if (FadeOutflag)
        {
          v7 = *(v3 + 294);
          if ((v7 & 0x200) != 0)
          {
            v8 = v7 & 0x200;
          }
          else
          {
            v8 = 0;
          }
          ImgDrawCount = gGlobal->ImgDrawCount;
          if ((ImgDrawCount & 1) != 0)
            v10 = 1;
          else
            v10 = -1;
          if (v8 && !*(v3 + 216))
          stfImageStart(ImgDrawCount, 0, v10);
          ++gGlobal->ImgDrawCount;
        }
      }
    }
  }
  if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
  {
    if (IMGcnt > 15)
      goto LABEL_44;
  }
  else
  {
    v11 = *(v3 + 184);
    if (IMGcnt > 15)
      goto LABEL_44;
  }
  if (gGlobal->ImgDrawCount < 1)
  {
LABEL_44:
    if ((*(v3 + 295) & 2) == 0)
      goto LABEL_47;
    goto LABEL_45;
  }
  stfDrawImage2(v3);
  {
LABEL_45:
  }
LABEL_47:
  v12 = *(*(v3 + 184) + 64LL);
  if (op_Equality(v12, 0, 0))
  {
    transform = get_transform(oStaff_UI, 0);
    v16 = Find(transform, "CapcomLogo", 0);
    gameObject = get_gameObject(v16);
    CapcomLogo = gameObject;
    v19 = get_transform(CapcomLogo, 0);
    v20 = get_transform(CapcomLogo, 0);
    x = get_position(v20).x;
    v22 = get_transform(CapcomLogo, 0);
    z = get_position(v22).z;
    v38.z = 0.0;
    *&v38.x = 0;
    sub_8524C0(&v38.x, x, -100.0, z);
    set_position(v19, v38);
  }
  v25 = gGlobal->cnt;
  v26 = 2 * (LogoPos - LogoPosAdjust);
  if (v25 > v26)
  {
    if (v25 - v26 <= 1399)
    {
      v27 = get_transform(CapcomLogo, 0);
      v28 = get_transform(CapcomLogo, 0);
      v29 = get_position(v28).x;
      v30 = get_transform(CapcomLogo, 0);
      y = get_position(v30).y;
      v33 = y;
      v34 = get_transform(CapcomLogo, 0);
      v37 = get_position(v34).z;
      v38.z = 0.0;
      *&v38.x = 0;
      sub_8524C0(&v38.x, v29, v33 + mojispeed, v37);
      set_position(v27, v38);
    }
  }
}

// 0x1695e20
void frwFreeStaffFont(void) {
  ;
}

// 0x1695e10
void frwLoadStaffFont(void) {
  ;
}

// 0x169bdf0
s32 stfDebugStart(void) {
  LODWORD(v2[2].klass->_1.interopData) = 1;
  stfInit();
  return -1;
}

// 0x169b400
dds3ProcessFunc_t *stfDestroy(dds3ProcessID_t *id) {
  AssetBundleCtrl_o *asset_bc;

  RemoveKeys(1, "staff");
  RemoveKeys(3, "staff");
  asset_bc = get_asset_bc();
  UnloadAB(asset_bc, "staff");
  ClearStaffUI();
  if (get_activeSelf(EndingUseBackImage))
  {
    SetActive(EndingUseBackImage, 0, 0);
  }
  if (get_activeSelf(EndingUseLineImage))
  {
    SetActive(EndingUseLineImage, 0, 0);
  }
  ObjDispON();
  FadeOutflag = 0;
  LastFade = 0;
  gGlobal->mh = 0;
  return 0;
}

// 0x1696460
void stfDrawImage2(void) {
  stfMain_c *v2;
  stfMain_c *v5;
  u64 *v7;
  System_String_o *v8;
  s64 *v9;
  u64 *v13;
  System_String_o *v14;
  struct System_String_o *v16;
  UnityEngine_Transform_o *v19;
  UnityEngine_Component_o *v20;
  struct UnityEngine_GameObject_o *v21;
  u64 *v22;
  System_String_o *v23;
  s64 *v24;
  u64 *v25;
  struct System_String_o *v27;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v31;
  struct UnityEngine_GameObject_o *gameObject;
  u64 *v33;
  struct System_String_o *v35;
  UnityEngine_Transform_o *v38;
  UnityEngine_Component_o *v39;
  struct UnityEngine_GameObject_o *v40;
  Il2CppObject *Component_object;
  Il2CppObject *v43;
  u64 *v45;
  System_String_o *v46;
  struct System_String_o *v47;
  UnityEngine_Transform_o *v49;
  UnityEngine_Component_o *v50;
  struct UnityEngine_GameObject_o *v51;
  Il2CppObject *v52;
  f32 v53;
  Il2CppObject *v55;
  f32 v57;
  Il2CppObject *v58;
  u64 v60;
  f32 v61;
  struct stfGlobal_o *gGlobal;
  s32 ImgDrawCount;
  s32 ImgCnt;
  struct stfMain_StaticFields *v65;
  stfMain_c *v67;
  struct stfGlobal_o *v69;
  s32 ImageTiming;
  s32 v71;
  struct stfGlobal_o *v73;
  Il2CppObject *v74;
  Il2CppObject *v76;
  f32 red;
  f32 green;
  f32 blue;
  f32 alpha;
  stfMain_c *v87;
  s16 v88;
  s32 v89;
  struct stfMain_StaticFields **p_static_fields;
  struct stfGlobal_o *v92;
  s32 v93;
  s32 v94;
  struct stfMain_StaticFields *v95;
  f32 v96;
  f32 v98;
  UnityEngine_UI_Image_o *EndingLineImage;
  f32 v100;
  s32 v101;
  s32 v102;
  struct stfMain_StaticFields *v103;
  f32 v104;
  f32 v106;
  struct stfMain_StaticFields *v108;
  f32 v109;
  s32 v111;
  s32 v112;
  s32 v113;
  struct stfMain_StaticFields *v114;
  s32 v115;
  Il2CppObject *v117;
  f32 v119;
  f32 v120;
  f32 v121;
  f32 v122;
  Il2CppObject *v123;
  stfMain_c *v126;
  struct stfGlobal_o *v127;
  s16 v128;
  s32 v129;
  s32 FadeOutImgAlphaCnt;
  s32 v131;
  Il2CppObject *v132;
  Il2CppObject *v134;
  f32 v135;
  f32 v136;
  f32 v137;
  f32 v138;
  Il2CppObject *v139;
  f32 v141;
  f32 v142;
  f32 v143;
  f32 v144;
  Il2CppObject *v145;
  s32 v149;
  struct stfMain_StaticFields *v150;
  Il2CppObject *v151;
  f32 v153;
  f32 v154;
  f32 v155;
  f32 v156;
  Il2CppObject *v157;
  s64 v161;
  s64 v162;
  s64 v163;
  s64 v164;

  else
  {
    if (IMGcnt > 15)
      return;
  }
  else if (PicDispflag)
  {
    goto LABEL_9;
  }
  if (evtBitCheck(300) && evtBitCheck(3712))
  {
      goto LABEL_18;
    goto LABEL_29;
  }
  if (!debugFlg)
  {
    if (debugPos == 1)
    {
      if ((v5->_2.bitflags2 & 2) != 0)
      {
LABEL_18:
      }
LABEL_29:
      LODWORD(v163) = IMGcnt;
      v7 = sub_8D3950(s32, &v163);
      v8 = Format("ending_IMG{0:00}/IMG", v7, 0);
      v9 = &"mdending_IMG/";
LABEL_57:
      v27 = Concat_5224608(*v9, v8);
      EndingBackImageStr = v27;
      if (IMGcnt)
      {
        transform = get_transform(oStaff_UI, 0);
        v31 = Find(transform, EndingBackImageStr, 0);
        gameObject = get_gameObject(v31);
        EndingBackImage = gameObject;
      }
      LODWORD(v163) = IMGcnt2;
      v33 = sub_8D3950(s32, &v163);
      v23 = Format("ending_FrameIMG{0:00}/IMG", v33, 0);
      v24 = &"mending_FrameIMG/";
      goto LABEL_66;
    }
  }
  if (evtBitCheck(300) && !evtBitCheck(3712))
  {
LABEL_53:
    LODWORD(v163) = IMGcnt;
    v25 = sub_8D3950(s32, &v163);
    v8 = Format("ending_IMG{0:00}/IMG", v25, 0);
    v9 = &"mending_IMG/";
    goto LABEL_57;
  }
  if (!debugFlg)
  {
    if (debugPos == 2)
      goto LABEL_53;
  }
  LODWORD(v163) = IMGcnt;
  v13 = sub_8D3950(s32, &v163);
  v14 = Format("ending_IMG{0:00}/IMG", v13, 0);
  v16 = Concat_5224608("ending_IMG/", v14);
  EndingBackImageStr = v16;
  if (IMGcnt)
  {
    v19 = get_transform(oStaff_UI, 0);
    v20 = Find(v19, EndingBackImageStr, 0);
    v21 = get_gameObject(v20);
    EndingBackImage = v21;
  }
  LODWORD(v163) = IMGcnt2;
  v22 = sub_8D3950(s32, &v163);
  v23 = Format("ending_FrameIMG{0:00}/IMG", v22, 0);
  v24 = &"ending_FrameIMG/";
LABEL_66:
  v35 = Concat_5224608(*v24, v23);
  EndingLineImageStr = v35;
  if (IMGcnt)
  {
    v38 = get_transform(oStaff_UI, 0);
    v39 = Find(v38, EndingLineImageStr, 0);
    v40 = get_gameObject(v39);
    EndingLineImage = v40;
  }
  Component_object = GetComponent_object_(EndingLineImage);
  EndingLineImage_ = Component_object;
  v43 = GetComponent_object_(EndingBackImage);
  EndingBackImage_ = v43;
  LODWORD(v163) = IMGcnt2;
  v45 = sub_8D3950(s32, &v163);
  v46 = Format("ending_MaskIMG{0:00}", v45, 0);
  v47 = Concat_5224608("ending_MaskIMG/", v46);
  EndingMaskImageStr = v47;
  if (IMGcnt2)
  {
    v49 = get_transform(oStaff_UI, 0);
    v50 = Find(v49, EndingMaskImageStr, 0);
    v51 = get_gameObject(v50);
    EndingMaskImage = v51;
  }
  PicDispflag = 1;
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_10:
  }
LABEL_83:
  v52 = GetComponent_object_(EndingBackImage);
  v53 = (v52->klass->vtable[22].methodPtr)(v52, v52->klass->vtable[22].method);
  red = v53;
  v55 = GetComponent_object_(EndingBackImage);
  (v55->klass->vtable[22].methodPtr)(v55, v55->klass->vtable[22].method);
  green = v57;
  v58 = GetComponent_object_(EndingBackImage);
  (v58->klass->vtable[22].methodPtr)(v58, v58->klass->vtable[22].method);
  blue = v61;
  gGlobal = **(v60 + 184);
  ImgDrawCount = gGlobal->ImgDrawCount;
  ImgCnt = gGlobal->ImgCnt;
  if ((*(v60 + 295) & 2) != 0 && !*(v60 + 216))
  {
    if (ImgCnt < STAFF_IMAGE_ONE_TIME)
      goto LABEL_100;
  }
  else
  {
    v65 = *(v60 + 184);
    if (ImgCnt < STAFF_IMAGE_ONE_TIME)
      goto LABEL_100;
  }
  if (FadeOutflag)
  {
    stfImageEnd(v60);
    return;
  }
LABEL_100:
  rsetOtOfs(71);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  rsetAlpha(0);
  v69 = gGlobal;
  v71 = 3 * v69->ImgCnt;
  if (v71 <= ImageTiming)
  {
LABEL_109:
    if ((v67->_2.bitflags2 & 2) == 0)
      goto LABEL_144;
    goto LABEL_110;
  }
  if ((v67->_2.bitflags2 & 2) == 0)
  {
    v71 = ImageTiming;
    goto LABEL_109;
  }
  else
  {
    v71 = ImageTiming;
      goto LABEL_144;
  }
LABEL_110:
LABEL_144:
  if (v71 < ImageTiming)
    goto LABEL_145;
LABEL_112:
  gGlobal->ImgAlpCnt += 2;
  v73 = gGlobal;
  if (v73->ImgAlpCnt >= 129)
  {
    v73->ImgAlpCnt = 128;
  }
  rsetAlpha(0);
  v74 = GetComponent_object_(EndingBackImage);
  v76 = v74;
  v163 = 0;
  v164 = 0;
  sub_19EC630(&v163, red, green, blue, alpha);
  (v76->klass->vtable[23].methodPtr)(v76, v76->klass->vtable[23].*&v163, *(&v163 + 1), *&v164, *(&v164 + 1));
  if (alpha >= 1.0)
  {
    alpha = 1.0;
  }
  if (get_activeSelf(EndingMaskImage))
  {
LABEL_145:
      goto LABEL_148;
    goto LABEL_146;
  }
  SetActive(EndingMaskImage, 1, 0);
  {
LABEL_146:
  }
LABEL_148:
  rsetAlpha(1);
  if ((v88 & 0x200) != 0)
  {
    v89 = v88 & 0x200;
  }
  else
  {
    v89 = 0;
  }
  v92 = gGlobal;
  if ((gGlobal->ImgDir & 0x80000000) == 0)
  {
    v93 = 3 * v92->ImgCnt;
    if (v93 >= 768)
      v94 = 768;
    else
      v94 = v93;
    if (v94 <= 255)
    {
      fill_Speed = fill_Speed + 0.00004;
      (*p_static_fields)->alpha_Speed = 0.00125;
      v108 = *p_static_fields;
      if (v108->alpha_ <= v108->lineAdjust)
      {
        if (v108->alpha < 1.0)
        {
          v108->alpha_ = v108->alpha_ + v108->alpha_Speed;
        }
      }
      fill = fill + fill_Speed;
      v109 = v94;
      fx = 0.0;
    }
    else
    {
      if (v94 > 767)
      {
        alphaSpeed = 0.03;
        (*p_static_fields)->alpha_Speed = 0.005;
        v95 = *p_static_fields;
        v96 = v95->alpha_;
        if (v96 <= v95->lineAdjust)
        {
          v95->alpha_ = v96 + v95->alpha_Speed;
        }
        if (gGlobal->ImgCnt <= 953)
        {
          v98 = alpha;
          if (v98 < 1.0)
          {
            alpha = v98 + alphaSpeed;
          }
        }
        fill_Speed = fill_Speed + 0.002;
        fill = 1.0;
        fx = 0.0;
        set_fillAmount(EndingBackImage_, 1.0);
        EndingLineImage = EndingLineImage_;
        v100 = 1.0;
        goto LABEL_253;
      }
      if (v94 >= 513)
        v113 = 768 - v94;
      else
        v113 = 256;
      fill_Speed = fill_Speed + 0.000035;
      (*p_static_fields)->alpha_Speed = 0.00125;
      v114 = *p_static_fields;
      if (v114->alpha_ <= v114->lineAdjust)
      {
        if (v114->alpha < 1.0)
        {
          v114->alpha_ = v114->alpha_ + v114->alpha_Speed;
        }
      }
      v115 = v94 - 256;
      fill = fill + fill_Speed;
      fx = v115;
      v109 = v113;
    }
    fw1 = v109;
    set_fillAmount(
      EndingBackImage_,
      (fx * 0.0019531) + -0.03,
      0);
    EndingLineImage = EndingLineImage_;
    v100 = (fx * 0.0019531) + -0.03;
LABEL_253:
    set_fillAmount(EndingLineImage, v100);
    v117 = GetComponent_object_(EndingLineImage);
    v119 = blue;
    v120 = red;
    v121 = green;
    v122 = alpha_;
    v123 = v117;
    v163 = 0;
    v164 = 0;
    sub_19EC630(&v163, v120, v121, v119, v122);
    (v123->klass->vtable[23].methodPtr)(
      v123,
      v123->klass->vtable[23].*&v163,
      *(&v163 + 1),
      *&v164,
      *(&v164 + 1));
    goto LABEL_254;
  }
  v101 = -3 * v92->ImgCnt;
  v102 = v101 + 512;
  if (v101 + 512 < -255)
  {
    alphaSpeed = 0.04;
    (*p_static_fields)->alpha_Speed = 0.005;
    v103 = *p_static_fields;
    v104 = v103->alpha_;
    if (v104 <= v103->lineAdjust)
    {
      v103->alpha_ = v104 + v103->alpha_Speed;
    }
    if (gGlobal->ImgCnt <= 953)
    {
      v106 = alpha;
      if (v106 < 1.0)
      {
        alpha = v106 + alphaSpeed;
      }
    }
    fill_Speed = fill_Speed + 0.002;
    fill = 1.0;
    set_fillAmount(
      EndingBackImage_,
      (512.0 - (fx + fw1)) * 0.0019531,
      0);
    EndingLineImage = EndingLineImage_;
    v100 = (512.0 - (fx + fw1)) * 0.0019531;
    goto LABEL_253;
  }
  if (v102 < 0)
  {
    v112 = v101 + 768;
    if (v102 >= 0)
      v149 = v101 + 512;
    else
      v149 = v101 + 513;
    v102 = 0;
    v111 = -(v149 >> 1);
    if ((v87->_2.bitflags2 & 2) == 0)
      goto LABEL_317;
  }
  else
  {
    v111 = 0;
    v112 = 256;
    if ((v87->_2.bitflags2 & 2) == 0)
      goto LABEL_317;
  }
LABEL_317:
  fill_Speed = fill_Speed + 0.00002;
  (*p_static_fields)->alpha_Speed = 0.00125;
  v150 = *p_static_fields;
  if (v150->alpha_ <= v150->lineAdjust)
  {
    if (v150->alpha < 1.0)
    {
      v150->alpha_ = v150->alpha_ + v150->alpha_Speed;
    }
  }
  fill = fill + fill_Speed;
  fx = v102;
  fa1 = v111;
  set_fillAmount(
    EndingBackImage_,
    ((512.0 - (fx + fw1)) * 0.0019531) + -0.03,
    0);
  set_fillAmount(
    EndingLineImage_,
    ((512.0 - (fx + fw1)) * 0.0019531) + -0.03,
    0);
  v151 = GetComponent_object_(EndingLineImage);
  v153 = blue;
  v154 = red;
  v155 = green;
  v156 = alpha_;
  v157 = v151;
  v163 = 0;
  v164 = 0;
  sub_19EC630(&v163, v154, v155, v153, v156);
  (v157->klass->vtable[23].methodPtr)(v157, v157->klass->vtable[23].*&v163, *(&v163 + 1), *&v164, *(&v164 + 1));
  if (v102 + v112 <= 511)
  {
    if (alpha_ <= lineAdjust)
    {
      if (alpha < 1.0)
      {
        alpha_ = alpha_ + alpha_Speed;
      }
    }
    fill = fill + fill_Speed;
    fx = v102;
    fw1 = v112;
    set_fillAmount(
      EndingBackImage_,
      ((512.0 - (fx + fw1)) * 0.0019531) + -0.03,
      0);
    EndingLineImage = EndingLineImage_;
    v100 = ((512.0 - (fx + fw1)) * 0.0019531) + -0.03;
    goto LABEL_253;
  }
LABEL_254:
  rsetAlpha(0);
  v127 = gGlobal;
  if (v127->ImgCnt < 1105)
    goto LABEL_306;
  v128 = *&v126->_2.bitflags1;
  if ((v128 & 0x200) != 0)
  {
    v129 = v128 & 0x200;
    FadeOutImgAlphaCnt = v127->FadeOutImgAlphaCnt;
    if (FadeOutImgAlphaCnt <= 127)
    {
LABEL_263:
      if (ImgDrawCount == 15)
        v131 = 1;
      else
        v131 = 2;
      v127->FadeOutImgAlphaCnt = FadeOutImgAlphaCnt + v131;
      if ((v126->_2.bitflags2 & 2) == 0)
        goto LABEL_281;
      goto LABEL_270;
    }
  }
  else
  {
    v129 = 0;
    FadeOutImgAlphaCnt = v127->FadeOutImgAlphaCnt;
    if (FadeOutImgAlphaCnt <= 127)
      goto LABEL_263;
  }
  v127->FadeOutImgAlphaCnt = 128;
  if ((v126->_2.bitflags2 & 2) == 0)
    goto LABEL_281;
LABEL_270:
  {
  }
LABEL_281:
  alphaSpeed = 0.025;
  alpha_Speed = 0.025;
  alpha = alpha - alphaSpeed;
  alpha_ = alpha_ - alpha_Speed;
  v132 = GetComponent_object_(EndingBackImage);
  v134 = v132;
  v135 = red;
  v136 = green;
  v137 = blue;
  v138 = alpha;
  v163 = 0;
  v164 = 0;
  sub_19EC630(&v163, v135, v136, v137, v138);
  (v134->klass->vtable[23].methodPtr)(v134, v134->klass->vtable[23].*&v163, *(&v163 + 1), *&v164, *(&v164 + 1));
  v139 = GetComponent_object_(EndingLineImage);
  v141 = blue;
  v142 = red;
  v143 = green;
  v144 = alpha_;
  v145 = v139;
  v161 = 0;
  v162 = 0;
  sub_19EC630(&v161, v142, v143, v141, v144);
  (v145->klass->vtable[23].methodPtr)(v145, v145->klass->vtable[23].*&v161, *(&v161 + 1), *&v162, *(&v162 + 1));
  if (alpha_ <= 0.0)
  {
    alpha_ = 0.0;
  }
  if (alpha <= 0.0)
  {
    alpha = 0.0;
  }
  if (!FadeOutflag)
  {
    if (alpha <= 0.0)
    {
      FadeOutflag = 1;
    }
  }
LABEL_306:
  ++gGlobal->ImgCnt;
}

// 0x1698620
void stfFontDraw(f32 x, f32 y, s32 mode, s32 rgba, char **moji) {
  ;
}

// 0x1698630
s32 stfFontGetWidth(s32 mode, s32 rgba, char **moji) {
  return 0;
}

// 0x1697f90
void stfFree(void) {
  struct sdfMemHandle_t_array *hFileLine;
  struct sdfMemHandle_t_array *v6;
  struct sdfMemHandle_t_array *v9;
  struct sdfMemHandle_t_array *v12;
  struct sdfMemHandle_t_array *v15;
  struct sdfMemHandle_t_array *v18;
  struct sdfMemHandle_t_array *v21;
  struct sdfMemHandle_t_array *v24;
  struct sdfMemHandle_t_array *hFileMask;
  struct sdfMemHandle_t_array *v30;
  struct sdfMemHandle_t_array *v33;
  struct sdfMemHandle_t_array *v36;
  struct sdfMemHandle_t_array *v39;
  struct sdfMemHandle_t_array *v42;
  struct sdfMemHandle_t_array *v45;
  struct sdfMemHandle_t_array *v48;
  s32 v51;
  s64 i;
  u64 v53;
  struct sdfMemHandle_t_array *hFilePic;
  struct sdfMemHandle_t_array *v57;
  u32 v59;
  sdfTexHandle_t_o *CapcomSpriteHandle;
  struct stfGlobal_o *gGlobal;

  hFileLine = gGlobal->hFileLine;
  if (hFileLine->m_Items[0])
  {
    v6 = gGlobal->hFileLine;
    v6->m_Items[0] = 0;
  }
  v9 = gGlobal->hFileLine;
  if (v9->m_Items[1])
  {
    v12 = gGlobal->hFileLine;
    v12->m_Items[1] = 0;
  }
  v15 = gGlobal->hFileLine;
  if (v15->m_Items[2])
  {
    v18 = gGlobal->hFileLine;
    v18->m_Items[2] = 0;
  }
  v21 = gGlobal->hFileLine;
  if (v21->m_Items[3])
  {
    v24 = gGlobal->hFileLine;
    v24->m_Items[3] = 0;
  }
  hFileMask = gGlobal->hFileMask;
  if (hFileMask->m_Items[0])
  {
    v30 = gGlobal->hFileMask;
    v30->m_Items[0] = 0;
  }
  v33 = gGlobal->hFileMask;
  if (v33->m_Items[1])
  {
    v36 = gGlobal->hFileMask;
    v36->m_Items[1] = 0;
  }
  v39 = gGlobal->hFileMask;
  if (v39->m_Items[2])
  {
    v42 = gGlobal->hFileMask;
    v42->m_Items[2] = 0;
  }
  v45 = gGlobal->hFileMask;
  if (v45->m_Items[3])
  {
    v48 = gGlobal->hFileMask;
    v48->m_Items[3] = 0;
  }
  for (i = 4; i != 19; ++i)
  {
    v53 = i - 4;
    hFilePic = gGlobal->hFilePic;
    if (*(&hFilePic->obj.klass + i))
    {
      v57 = gGlobal->hFilePic;
      *(&v57->obj.klass + i) = 0;
    }
    v51 = (v59 >> 9) & 1;
  }
  CapcomSpriteHandle = gGlobal->CapcomSpriteHandle;
  if (CapcomSpriteHandle)
  {
    sdfTexFreeDelayed(CapcomSpriteHandle);
  }
  gGlobal->CapcomSpriteHandle = 0;
  if (gGlobal->hFileCapcom)
  {
    gGlobal->hFileCapcom = 0;
  }
}

// 0x1697d80
void stfFreeTex(void) {
  sdfTexHandle_t_o *LineSpriteHandle;
  sdfTexHandle_t_o *MaskSpriteHandle;
  sdfTexHandle_t_o *PicSpriteHandle;

  LineSpriteHandle = gGlobal->LineSpriteHandle;
  if (LineSpriteHandle)
  {
    sdfTexFree(LineSpriteHandle);
  }
  MaskSpriteHandle = gGlobal->MaskSpriteHandle;
  if (MaskSpriteHandle)
  {
    sdfTexFree(MaskSpriteHandle);
  }
  PicSpriteHandle = gGlobal->PicSpriteHandle;
  if (PicSpriteHandle)
  {
    sdfTexFree(PicSpriteHandle);
  }
  gGlobal->LineSpriteHandle = 0;
  gGlobal->MaskSpriteHandle = 0;
  gGlobal->PicSpriteHandle = 0;
}

// 0x1697b80
void stfImageEnd(void) {
  stfFreeTex();
  gGlobal->ImgNo = 0;
  gGlobal->ImgCnt = 0;
  gGlobal->ImgAlpCnt = 0;
  gGlobal->FadeOutImgAlphaCnt = 0;
  gGlobal->ImgLife = 0;
  gGlobal->ImgDir = 0;
  gGlobal->ImageDrawing = 0;
  PicDispflag = 0;
  FadeOutflag = 1;
  ++IMGcnt;
  ++IMGcnt2;
  if (get_activeSelf(EndingMaskImage))
  {
    SetActive(EndingMaskImage, 0, 0);
  }
  else
  {
    if (IMGcnt < 16)
      goto LABEL_18;
  }
  IMGcnt = 16;
LABEL_18:
  else
  {
    if (IMGcnt2 < 5)
      return;
  }
  IMGcnt2 = 1;
}

// 0x1696330
void stfImageStart(s32 no, s32 life, s32 dir) {
  u64 v7;

  if (*(**(v7 + 184) + 204LL) == 1)
  {
    stfImageEnd(v7);
  }
  *(**(v7 + 184) + 176LL) = no;
  *(**(v7 + 184) + 180LL) = 0;
  *(**(v7 + 184) + 184LL) = 0;
  *(**(v7 + 184) + 200LL) = 0;
  *(**(v7 + 184) + 188LL) = life;
  *(**(v7 + 184) + 192LL) = dir;
  stfSetTex(no, *&life);
  FadeOutflag = 0;
  gGlobal->ImageDrawing = 1;
}

// 0x169bb80
void stfInit(void) {
  u64 *v3;
  AssetBundleCtrl_o *asset_bc;
  u64 *v8;
  u64 *v9;

  dds3BackColor = 0x80000000;
  v3 = Allocate(stfGlobal);
  _ctor(v3, 0);
  gGlobal = v3;
  gGlobal->step = 0;
  gGlobal->pos = 0;
  gGlobal->cnt = 0;
  gGlobal->max = 0;
  gGlobal->roll = 0.0;
  gGlobal->speed = 0.1;
  gGlobal->LineSpriteHandle = 0;
  gGlobal->MaskSpriteHandle = 0;
  gGlobal->PicSpriteHandle = 0;
  IMGcnt = 1;
  IMGcnt2 = 1;
  Mojimoveflag = 0;
  job_nameobj = 0;
  staff_nameobj = 0;
  center_nameobj = 0;
  PicDispflag = 0;
  FadeOutflag = 1;
  asset_bc = get_asset_bc();
  Load(asset_bc, "staff", "staff", 0);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_stfMain_stfMain2__);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_stfMain_stfDestroy__);
  dds3StartProcess("staffProc", 0x2B19u, 0, 0, v8, 0, v9, 0, 0, 0);
}

// 0x1697f80
void stfLoad(void) {
  ;
}

// 0x16987f0
dds3ProcessFunc_t *stfMain2(dds3ProcessID_t *id) {
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *oStaff_UI;
  AssetBundleCtrl_o *v7;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v9;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v13;
  UnityEngine_Object_o *debugImage;
  bool v18;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v21;
  UnityEngine_Component_o *v22;
  struct UnityEngine_GameObject_o *v23;
  UnityEngine_Object_o *StaffUIObj;
  bool v30;
  u64 v31;
  struct stfMain_StaticFields *v32;
  struct UnityEngine_GameObject_array *v33;
  signed s64 v34;
  struct stfMain_StaticFields *v35;
  signed s64 centerobj_max;
  u32 *v38;
  u64 *v39;
  struct System_String_o *v40;
  u32 *center_nameobj;
  UnityEngine_Transform_o *v44;
  UnityEngine_Component_o *v45;
  s64 *v46;
  s64 *v47;
  struct stfMain_StaticFields *v49;
  struct UnityEngine_GameObject_array *v50;
  signed s64 v51;
  struct stfMain_StaticFields *v52;
  signed s64 jobobj_max;
  u32 *v55;
  u64 *v56;
  struct System_String_o *v57;
  u32 *job_nameobj;
  UnityEngine_Transform_o *v61;
  UnityEngine_Component_o *v62;
  s64 *v63;
  s64 *v64;
  struct stfMain_StaticFields *v66;
  struct UnityEngine_GameObject_array *v67;
  signed s64 v68;
  struct stfMain_StaticFields *v69;
  signed s64 staffobj_max;
  u32 *v72;
  u64 *v73;
  struct System_String_o *v74;
  u32 *staff_nameobj;
  UnityEngine_Transform_o *v78;
  UnityEngine_Component_o *v79;
  s64 *v80;
  s64 *v81;
  u64 v83;
  struct stfMain_StaticFields *v84;
  struct StaffStruct_array *staff_member;
  s32 yPos;
  struct TMPro_TextMeshProUGUI_array *centerNameTM;
  s32 cnt;
  s32 v93;
  UnityEngine_Object_o *v95;
  struct TMPro_TextMeshProUGUI_array *v98;
  UnityEngine_Transform_o *v100;
  f32 y;
  s32 height;
  s32 v103;
  stfMain_c *v104;
  s32 v105;
  struct TMPro_TextMeshProUGUI_array *staffNameTM;
  struct TMPro_TextMeshProUGUI_array *jobNameTM;
  struct TMPro_TextMeshProUGUI_array *v110;
  struct StaffStruct_array *v113;
  struct StaffStruct_array *v116;
  struct StaffStruct_array *v119;
  struct StaffStruct_array *v122;
  System_String_o *v125;
  struct TMPro_TextMeshProUGUI_array *v127;
  UnityEngine_Object_o *v129;
  bool v131;
  struct UnityEngine_GameObject_array *v134;
  u32 *v135;
  s64 jobname_cnt;
  s64 *Component_object;
  s64 *v139;
  struct TMPro_TextMeshProUGUI_array *v142;
  struct TMPro_TextMeshProUGUI_array *v144;
  struct TMPro_TextMeshProUGUI_array *v146;
  UnityEngine_Transform_o *v148;
  struct TMPro_TextMeshProUGUI_array *v149;
  UnityEngine_Transform_o *v150;
  UnityEngine_Transform_o *v152;
  struct TMPro_TextMeshProUGUI_array *v153;
  f32 v154;
  UnityEngine_Transform_o *v156;
  struct TMPro_TextMeshProUGUI_array *v160;
  UnityEngine_Transform_o *v162;
  struct TMPro_TextMeshProUGUI_array *v163;
  UnityEngine_Transform_o *v164;
  UnityEngine_Transform_o *v166;
  struct TMPro_TextMeshProUGUI_array *v167;
  f32 v168;
  UnityEngine_Transform_o *v170;
  struct TMPro_TextMeshProUGUI_array *v172;
  f32 v173;
  f32 v174;
  UnityEngine_Transform_o *v176;
  struct StaffStruct_array *v177;
  struct StaffStruct_array *v180;
  System_String_o *v183;
  struct TMPro_TextMeshProUGUI_array *v185;
  UnityEngine_Object_o *v187;
  bool v189;
  struct UnityEngine_GameObject_array *v192;
  u32 *v193;
  s64 staffname_cnt;
  s64 *v196;
  s64 *v197;
  struct TMPro_TextMeshProUGUI_array *v200;
  struct TMPro_TextMeshProUGUI_array *v202;
  struct TMPro_TextMeshProUGUI_array *v204;
  UnityEngine_Transform_o *v206;
  struct TMPro_TextMeshProUGUI_array *v207;
  UnityEngine_Transform_o *v208;
  UnityEngine_Transform_o *v210;
  struct TMPro_TextMeshProUGUI_array *v211;
  f32 v212;
  UnityEngine_Transform_o *v214;
  struct TMPro_TextMeshProUGUI_array *v217;
  UnityEngine_Transform_o *v219;
  struct TMPro_TextMeshProUGUI_array *v220;
  UnityEngine_Transform_o *v221;
  UnityEngine_Transform_o *v223;
  struct TMPro_TextMeshProUGUI_array *v224;
  f32 v225;
  UnityEngine_Transform_o *v227;
  f32 mojispeed;
  struct TMPro_TextMeshProUGUI_array *v230;
  f32 v231;
  UnityEngine_Transform_o *v233;
  struct StaffStruct_array *v235;
  System_String_o *v238;
  struct TMPro_TextMeshProUGUI_array *v240;
  UnityEngine_Object_o *v242;
  bool v243;
  struct UnityEngine_GameObject_array *v246;
  u32 *v247;
  s64 center_cnt;
  s64 *v250;
  s64 *v251;
  struct TMPro_TextMeshProUGUI_array *v255;
  struct TMPro_TextMeshProUGUI_array *v257;
  struct TMPro_TextMeshProUGUI_array *v259;
  UnityEngine_Transform_o *v261;
  struct TMPro_TextMeshProUGUI_array *v262;
  UnityEngine_Transform_o *v263;
  UnityEngine_Transform_o *v265;
  struct TMPro_TextMeshProUGUI_array *v266;
  f32 v267;
  UnityEngine_Transform_o *v269;
  struct TMPro_TextMeshProUGUI_array *v273;
  UnityEngine_Transform_o *v275;
  struct TMPro_TextMeshProUGUI_array *v276;
  UnityEngine_Transform_o *v278;
  struct TMPro_TextMeshProUGUI_array *v279;
  UnityEngine_Transform_o *v281;
  struct stfGlobal_o *gGlobal;
  s32 step;
  s32 v290;
  s64 v292;
  s32 v300;
  s64 v302;
  u64 *v304;
  s32 v311;
  s32 Language;
  s32 useLang;
  AssetBundleCtrl_o *v318;
  System_String_o *v319;
  s64 *v320;
  System_String_o *v321;
  s64 *v322;
  UnityEngine_Object_o *Asset;
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v327;
  stfMain_c *v329;
  s64 *v331;
  s64 *v332;
  UnityEngine_Transform_o *v335;
  UnityEngine_Component_o *v336;
  struct UnityEngine_GameObject_o *v337;
  UnityEngine_Transform_o *v339;
  UnityEngine_Component_o *v340;
  struct UnityEngine_GameObject_o *v342;
  u64 *v350;
  f32 x;
  f32 z;
  f32 v353;
  f32 v354;
  f32 v355;
  f32 v356;
  f32 v357;
  f32 v358;
  f32 v359;
  f32 v360;
  f32 v361;
  f32 v362;
  f32 v363;
  f32 v364;
  UnityEngine_Vector3_o v365;

  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, "staff"))
    return 0;
  if (op_Equality(oStaff_UI, 0, 0))
  {
    v7 = get_asset_bc();
    Prefab_16624656 = LoadPrefab_16624656(v7, "staff", "dds3data/staff", "staffUI");
    v9 = Find("Canvas_UI", 0);
    transform = get_transform(v9, 0);
    v13 = Instantiate_object__425664(Prefab_16624656, transform, 0);
    oStaff_UI = v13;
    AddComponent_object_(oStaff_UI);
  }
  v18 = op_Equality(debugImage, 0, 0);
  if (v18)
  {
    gameObject = get_gameObject(oStaff_UI);
    v21 = get_transform(gameObject, 0);
    v22 = Find(v21, "debugMenu", 0);
    v23 = get_gameObject(v22);
    debugImage = v23;
  }
  if (debugFlg == 1)
    return 0;
  if (get_activeSelf(debugImage))
  {
    SetActive(debugImage, 0, 0);
  }
  v30 = op_Equality(StaffUIObj, 0, 0);
  if (v30)
  {
    *(*(v31 + 184) + 432LL) = *(*(v31 + 184) + 488LL);
  }
  v32 = *(v31 + 184);
  if (center_nameobj)
    goto LABEL_93;
  v33 = NewSpecific(UnityEngine_GameObject, centerobj_max);
  center_nameobj = v33;
  v34 = 0;
  if ((*(v31 + 295) & 2) == 0)
    goto LABEL_76;
LABEL_71:
  if (*(v31 + 216))
  {
    while (1)
    {
LABEL_76:
      v35 = *(v31 + 184);
      if (v34 >= centerobj_max)
        goto LABEL_93;
LABEL_77:
      if ((*(v31 + 295) & 2) != 0 && !*(v31 + 216))
      {
        if (centername_cnt >= centerobj_max)
        {
LABEL_80:
          centername_cnt = 0;
        }
      }
      else if (centername_cnt >= centerobj_max)
      {
        goto LABEL_80;
      }
      v365.x = *(*(v31 + 184) + 328LL);
      v39 = sub_8D3950(s32, &v365);
      v40 = Format("CenterNameTM/center_name{0}", v39, 0);
      centername_str = v40;
      v44 = get_transform(StaffUIObj, 0);
      v45 = Find(v44, centername_str, 0);
      v46 = get_gameObject(v45);
      v47 = v46;
      v38 = &center_nameobj[2 * v34++];
      *(v38 + 4) = v47;
      ++centername_cnt;
      if ((*(v31 + 295) & 2) != 0)
        goto LABEL_71;
    }
  }
  if (v34 < centerobj_max)
    goto LABEL_77;
LABEL_93:
  v49 = *(v31 + 184);
  if (job_nameobj)
    goto LABEL_123;
  v50 = NewSpecific(UnityEngine_GameObject, jobobj_max);
  job_nameobj = v50;
  v51 = 0;
  if ((*(v31 + 295) & 2) == 0)
    goto LABEL_106;
LABEL_101:
  if (*(v31 + 216))
  {
    while (1)
    {
LABEL_106:
      v52 = *(v31 + 184);
      if (v51 >= jobobj_max)
        goto LABEL_123;
LABEL_107:
      if ((*(v31 + 295) & 2) != 0 && !*(v31 + 216))
      {
        if (jobnameobj_cnt >= jobobj_max)
        {
LABEL_110:
          jobnameobj_cnt = 0;
        }
      }
      else if (jobnameobj_cnt >= jobobj_max)
      {
        goto LABEL_110;
      }
      v365.x = *(*(v31 + 184) + 336LL);
      v56 = sub_8D3950(s32, &v365);
      v57 = Format("JobNameTM/job_name{0}", v56, 0);
      jobname_str = v57;
      v61 = get_transform(StaffUIObj, 0);
      v62 = Find(v61, jobname_str, 0);
      v63 = get_gameObject(v62);
      v64 = v63;
      v55 = &job_nameobj[2 * v51++];
      *(v55 + 4) = v64;
      ++jobnameobj_cnt;
      if ((*(v31 + 295) & 2) != 0)
        goto LABEL_101;
    }
  }
  if (v51 < jobobj_max)
    goto LABEL_107;
LABEL_123:
  v66 = *(v31 + 184);
  if (!staff_nameobj)
  {
    v67 = NewSpecific(UnityEngine_GameObject, staffobj_max);
    staff_nameobj = v67;
    v68 = 0;
    if ((*(v31 + 295) & 2) == 0)
      goto LABEL_136;
LABEL_131:
    if (!*(v31 + 216))
    {
      if (v68 < staffobj_max)
        goto LABEL_137;
      goto LABEL_153;
    }
    while (1)
    {
LABEL_136:
      v69 = *(v31 + 184);
      if (v68 >= staffobj_max)
        break;
LABEL_137:
      if ((*(v31 + 295) & 2) != 0 && !*(v31 + 216))
      {
        if (staffnameobj_cnt >= staffobj_max)
        {
LABEL_140:
          staffnameobj_cnt = 0;
        }
      }
      else if (staffnameobj_cnt >= staffobj_max)
      {
        goto LABEL_140;
      }
      v365.x = *(*(v31 + 184) + 332LL);
      v73 = sub_8D3950(s32, &v365);
      v74 = Format("StaffNameTM/staff_name{0}", v73, 0);
      staffname_str = v74;
      v78 = get_transform(StaffUIObj, 0);
      v79 = Find(v78, staffname_str, 0);
      v80 = get_gameObject(v79);
      v81 = v80;
      v72 = &staff_nameobj[2 * v68++];
      *(v72 + 4) = v81;
      ++staffnameobj_cnt;
      if ((*(v31 + 295) & 2) != 0)
        goto LABEL_131;
    }
  }
LABEL_153:
  v83 = 0;
  if ((*(v31 + 295) & 2) == 0)
    goto LABEL_157;
LABEL_154:
LABEL_157:
  while (1)
  {
    v84 = *(v31 + 184);
    if (v83 >= newStaffAdjust + 168LL)
      break;
    yPos = staff_member->m_Items[v83]->yPos;
    cnt = gGlobal->cnt;
    if (cnt >= 0)
      v93 = gGlobal->cnt;
    else
      v93 = cnt + 1;
    v95 = centerNameTM->m_Items[v83];
    if (!op_Inequality(v95, 0, 0))
      goto LABEL_187;
    if (v83 != newStaffAdjust + 167)
      goto LABEL_187;
    else
    {
      v98 = centerNameTM;
      if (v83 >= LODWORD(v98->max_length))
        goto LABEL_182;
    }
    v100 = get_transform(v98->m_Items[v83], 0);
    y = get_position(v100).y;
    height = get_height(0);
    v103 = height >= 0 ? height : height + 1;
    if (y < (v103 >> 1))
    {
LABEL_187:
      v105 = yPos - (v93 >> 1) + 448;
      if (v105 > 448)
        goto LABEL_199;
        goto LABEL_198;
LABEL_189:
      goto LABEL_198;
    }
    EndingStaffRollUnlock();
    Mojimoveflag = 1;
    v105 = 128;
    if ((v104->_2.bitflags2 & 2) != 0)
      goto LABEL_189;
LABEL_198:
    if (posAdjust > v105)
    {
LABEL_199:
      staffNameTM->m_Items[v83] = 0;
      jobNameTM->m_Items[v83] = 0;
      v110 = centerNameTM;
      v110->m_Items[v83] = 0;
      goto LABEL_156;
    }
    v113 = staff_member;
    if (!v113->m_Items[v83]->left_string)
      goto LABEL_221;
    v116 = staff_member;
    if (v116->m_Items[v83]->right_string)
    {
LABEL_221:
      v119 = staff_member;
      if (v119->m_Items[v83]->left_string)
      {
        v122 = staff_member;
        v125 = Format("{0}", v122->m_Items[v83]->left_string, 0);
        v127 = jobNameTM;
        v129 = v127->m_Items[v83];
        v131 = op_Equality(v129, 0, 0);
        if (v131)
        {
          v134 = job_nameobj;
          v135 = jobNameTM;
          Component_object = GetComponent_object_(v134->m_Items[jobname_cnt]);
          v139 = Component_object;
          *&v135[2 * v83 + 8] = v139;
          v142 = jobNameTM;
          set_font(v142->m_Items[v83], useFont);
          v144 = jobNameTM;
          set_text(v144->m_Items[v83], v125);
          v146 = jobNameTM;
          v148 = get_transform(v146->m_Items[v83], 0);
          v149 = jobNameTM;
          v150 = v148;
          v152 = get_transform(v149->m_Items[v83], 0);
          x = get_position(v152).x;
          v153 = jobNameTM;
          v154 = x;
          v156 = get_transform(v153->m_Items[v83], 0);
          z = get_position(v156).z;
          v365.z = 0.0;
          *&v365.x = 0;
          sub_8524C0(&v365.x, v154, -50.0, z);
          set_position(v150, v365);
          ++jobname_cnt;
          if (jobname_cnt == jobobj_max)
          {
            jobname_cnt = 0;
            {
LABEL_265:
            }
LABEL_280:
            v177 = staff_member;
            if (!v177->m_Items[v83]->right_string)
              goto LABEL_156;
            v180 = staff_member;
            v183 = Format("{0}", v180->m_Items[v83]->right_string, 0);
            v185 = staffNameTM;
            v187 = v185->m_Items[v83];
            v189 = op_Equality(v187, 0, 0);
            if (v189)
            {
              v192 = staff_nameobj;
              v193 = staffNameTM;
              v196 = GetComponent_object_(v192->m_Items[staffname_cnt]);
              v197 = v196;
              *&v193[2 * v83 + 8] = v197;
              v200 = staffNameTM;
              set_font(v200->m_Items[v83], useFont);
              v202 = staffNameTM;
              set_text(v202->m_Items[v83], v183);
              v204 = staffNameTM;
              v206 = get_transform(v204->m_Items[v83], 0);
              v207 = staffNameTM;
              v208 = v206;
              v210 = get_transform(v207->m_Items[v83], 0);
              v356 = get_position(v210).x;
              v211 = staffNameTM;
              v212 = v356;
              v214 = get_transform(v211->m_Items[v83], 0);
              v357 = get_position(v214).z;
              v365.z = 0.0;
              *&v365.x = 0;
              sub_8524C0(&v365.x, v212, -50.0, v357);
              set_position(v208, v365);
              ++staffname_cnt;
              if (staffname_cnt == staffobj_max)
              {
                staffname_cnt = 0;
              }
              goto LABEL_156;
            }
            v217 = staffNameTM;
            v219 = get_transform(v217->m_Items[v83], 0);
            v220 = staffNameTM;
            v221 = v219;
            v223 = get_transform(v220->m_Items[v83], 0);
            v358 = get_position(v223).x;
            v224 = staffNameTM;
            v225 = v358;
            v227 = get_transform(v224->m_Items[v83], 0);
            v359 = get_position(v227).y;
            v230 = staffNameTM;
            v231 = v359;
            if (v83 >= LODWORD(v230->max_length))
              goto LABEL_331;
            goto LABEL_332;
          }
        }
        else
        {
          v160 = jobNameTM;
          v162 = get_transform(v160->m_Items[v83], 0);
          v163 = jobNameTM;
          v164 = v162;
          v166 = get_transform(v163->m_Items[v83], 0);
          v353 = get_position(v166).x;
          v167 = jobNameTM;
          v168 = v353;
          v170 = get_transform(v167->m_Items[v83], 0);
          v354 = get_position(v170).y;
          v172 = jobNameTM;
          v173 = mojispeed;
          v174 = v354;
          v176 = get_transform(v172->m_Items[v83], 0);
          v355 = get_position(v176).z;
          v365.z = 0.0;
          *&v365.x = 0;
          sub_8524C0(&v365.x, v168, v174 + v173, v355);
          set_position(v164, v365);
        }
      }
        goto LABEL_265;
      goto LABEL_280;
    }
    v235 = staff_member;
    v238 = Format("{0}", v235->m_Items[v83]->left_string, 0);
    v240 = centerNameTM;
    v242 = v240->m_Items[v83];
    v243 = op_Equality(v242, 0, 0);
    if (v243)
    {
      v246 = center_nameobj;
      v247 = centerNameTM;
      v250 = GetComponent_object_(v246->m_Items[center_cnt]);
      v251 = v250;
      *&v247[2 * v83 + 8] = v251;
      v255 = centerNameTM;
      set_font(v255->m_Items[v83], useFont);
      v257 = centerNameTM;
      set_text(v257->m_Items[v83], v238);
      v259 = centerNameTM;
      v261 = get_transform(v259->m_Items[v83], 0);
      v262 = centerNameTM;
      v263 = v261;
      v265 = get_transform(v262->m_Items[v83], 0);
      v361 = get_position(v265).x;
      v266 = centerNameTM;
      v267 = v361;
      v269 = get_transform(v266->m_Items[v83], 0);
      v362 = get_position(v269).z;
      v365.z = 0.0;
      *&v365.x = 0;
      sub_8524C0(&v365.x, v267, -50.0, v362);
      set_position(v263, v365);
      ++center_cnt;
      if (center_cnt == centerobj_max)
      {
        center_cnt = 0;
      }
      goto LABEL_156;
    }
    if (Mojimoveflag)
      goto LABEL_156;
    v273 = centerNameTM;
    v275 = get_transform(v273->m_Items[v83], 0);
    v276 = centerNameTM;
    v221 = v275;
    v278 = get_transform(v276->m_Items[v83], 0);
    v363 = get_position(v278).x;
    v279 = centerNameTM;
    v225 = v363;
    v281 = get_transform(v279->m_Items[v83], 0);
    v364 = get_position(v281).y;
    v230 = centerNameTM;
    v231 = v364;
    if (v83 >= LODWORD(v230->max_length))
    {
LABEL_331:
    }
LABEL_332:
    v233 = get_transform(v230->m_Items[v83], 0);
    v360 = get_position(v233).z;
    v365.z = 0.0;
    *&v365.x = 0;
    sub_8524C0(&v365.x, v225, v231 + mojispeed, v360);
    set_position(v221, v365);
LABEL_156:
    ++v83;
      goto LABEL_154;
  }
  if ((*(v31 + 295) & 2) != 0)
  {
    step = gGlobal->step;
    if (step != 2)
      goto LABEL_436;
LABEL_393:
    ++gGlobal->cnt;
    StaffImageManager(v31);
    v290 = gGlobal->cnt;
    v292 = newStaffAdjust + 167LL;
    if (v290 == 60 * ((staff_member->m_Items[v292]->yPos + 224) / 30) + 360)
    {
      LastFade = 1;
      dds3FadeOut(0, 0, 0, 0x28u);
    }
    if (LastFade)
    {
      if (!dds3FadeCheck())
      {
        v300 = gGlobal->cnt;
        v302 = newStaffAdjust + 167LL;
        if (v300 / 60 > (staff_member->m_Items[v302]->yPos + 224) / 30)
        {
          if (evtBitCheck(300) && evtBitCheck(273) && !evtBitCheck(3712))
          {
            LODWORD(v365.x) = 756;
            v350 = sub_8D3950(s32, &v365);
            dds3AdminiCallSequence(8, v350, 4, 0);
          }
          else
          {
            LODWORD(v365.x) = 692;
            v304 = sub_8D3950(s32, &v365);
            dds3AdminiCallSequence(8, v304, 4, 0);
            gGlobal->step = 3;
          }
        }
      }
    }
  }
  else
  {
    step = gGlobal->step;
    if (step == 2)
      goto LABEL_393;
LABEL_436:
    if (!step)
    {
      dds3FadeIn(0, 0, 0, 0x1Eu);
      gGlobal->cnt = 0;
      gGlobal->step = 2;
      gGlobal->roll = 0.0;
      gGlobal->ImgDrawCount = 0;
      gGlobal->ImageDrawing = 0;
      LoadKeys(2, "staff", 0);
      LoadKeys(4, "staff", 0);
      set_targetFrameRate(60);
      set_vSyncCount(1);
      v311 = FindId(0, "STAFF_ADB");
      p2sdPlayBGM(v311);
      ObjDispOff();
      Language = GetLanguage(0);
      useLang = Language;
      if ((useLang - 1) < 5)
      {
        v318 = get_asset_bc();
        v319 = "_font-en";
        v320 = &"font-en";
        goto LABEL_460;
      }
      if (useLang == 6)
      {
        v318 = get_asset_bc();
        v319 = "_font-zh";
        v321 = "font-zh";
        v322 = &"EndCredit/DFMingMedium-B5 SDF";
      }
      else if (useLang == 7)
      {
        v318 = get_asset_bc();
        v319 = "_font-ko";
        v321 = "font-ko";
        v322 = &"EndCredit/AsiaKHM-M SDF";
      }
      else
      {
        v318 = get_asset_bc();
        v319 = "_font-ja";
        v320 = &"font-ja";
LABEL_460:
        v321 = *v320;
        v322 = &"EndCredit/FOT-TelopMinPro-B SDF";
      }
      Asset = LoadAsset(v318, v319, v321, *v322, 0);
      if (Asset
            Asset->klass->_2.typeHierarchyDepth >= typeHierarchyDepth))
      {
        if (Asset->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == TMPro_TMP_FontAsset)
          v327 = Asset;
        else
          v327 = 0;
      }
      else
      {
        v327 = 0;
      }
      useFont = v327;
      if (evtBitCheck(300) && evtBitCheck(3712))
      {
        {
LABEL_490:
          v331 = &"mending_FrameIMG";
          v332 = &"mdending_IMG";
          goto LABEL_519;
        }
LABEL_489:
          goto LABEL_490;
        v331 = &"mending_FrameIMG";
        v332 = &"mdending_IMG";
      }
      else
      {
        if (!debugFlg)
        {
          if (debugPos == 1)
          {
            if ((v329->_2.bitflags2 & 2) == 0)
              goto LABEL_490;
            goto LABEL_489;
          }
        }

        {
          if (debugFlg)
            goto LABEL_502;
          if (debugPos != 2)
          {
LABEL_502:
            else
            {
              v331 = &"ending_FrameIMG";
            }
            v332 = &"ending_IMG";
            goto LABEL_519;
          }
        }
        else
        {
          v331 = &"mending_FrameIMG";
        }
        v332 = &"mending_IMG";
      }
LABEL_519:
      v335 = get_transform(oStaff_UI, 0);
      v336 = Find(v335, *v332, 0);
      v337 = get_gameObject(v336);
      EndingUseBackImage = v337;
      v339 = get_transform(oStaff_UI, 0);
      v340 = Find(v339, *v331, 0);
      v342 = get_gameObject(v340);
      EndingUseLineImage = v342;
      if (!get_activeSelf(EndingUseBackImage))
      {
        SetActive(EndingUseBackImage, 1, 0);
      }
      if (!get_activeSelf(EndingUseLineImage))
      {
        SetActive(EndingUseLineImage, 1, 0);
      }
    }
  }
  return 0;
}

// 0x1698640
void stfSetTex(s32 i) {
  u64 *v3;
  u64 *v4;
  u64 *v6;
  struct stfGlobal_o *gGlobal;
  s32 v9;
  signed s32 v10;
  s64 v11;
  Il2CppObject *v13;
  struct stfGlobal_o *v14;
  struct stfGlobal_o *v16;

  v3 = NewSpecific(object, 4u);
  v4 = NewSpecific(object, 4u);
  v6 = NewSpecific(object, 0xFu);
  v9 = i + 3;
  if (i >= 0)
    v9 = i;
  v10 = i - (v9 & 0xFFFFFFFC);
  v11 = v10;
  v13 = v3[v10 + 4];
  gGlobal->LineSpriteHandle = sdfTexSet(v13);
  v14 = gGlobal;
  v14->MaskSpriteHandle = sdfTexSet(v4[v11 + 4]);
  v16 = gGlobal;
  v16->PicSpriteHandle = sdfTexSet(v6[i + 4]);
}

// 0x169bee0
s32 stfShutDown(void) {
  dds3KillProcessName("staffProc", 1);
  SetNormalFrameRate(kernelObject);
  return 0;
}

// 0x169be70
s32 stfStart(void) {
  stfInit();
  return -1;
}
