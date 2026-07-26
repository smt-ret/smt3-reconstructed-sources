#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtPicturePriTbl_t evtPicturePriTbl_t;
typedef struct evtPictureProcessData_t evtPictureProcessData_t;
typedef struct evtTexManager evtTexManager;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static dds3ProcessID_t *evtPicturePriProcess_id;
static s32 PlayEventNo;
static void *pictures;
static void *gFrame;
static s32 PicBuffer;
static bool bGouto;
static bool gPictureFlag;
static bool bGoutLoad;
static f32 MULTIPLE;

evtPictureProcessData_t *InitPictureProcessData(void);
bool IsDLC(void);
void Load(char *key, char *filePath);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void LoadTexture(evtTexManager *this, char *key, char *path, char *name);
void Log(char *fmt, void **parray);
void Set_EventID(s32 eno);
void Set_EventMode(bool onoff);
void Set_PicFlag(bool flag);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void eglLinkAlpha(s32 mode);
void eglLinkTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void eglSetOt(s32 ot);
void evtPicturePriAdd(evtPicturePriTbl_t *indata);
void evtPicturePriClear(void);
void evtPicturePriDraw(void);
sdfTexHandle_t *itfMiscLoadTexture(char *filename);

// 0x10f5140
bool GetPictureDisp(void) {
  return gPictureFlag;
}

// 0x10f4380
evtPictureProcessData_t *InitPictureProcessData(void) {
  u64 *v1;
  f32 MULTIPLE;

  v1 = Allocate(evtPictureProcessData_t);
  evtPictureProcessData_t___ctor(v1);
  *(v1 + 4) = 0;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0x8000000000LL;
  *(v1 + 12) = 1120403456;
  *(v1 + 13) = vcvts_n_s32_f32(MULTIPLE, 9u);
  *(v1 + 14) = (MULTIPLE * 384.0);
  *(v1 + 15) = vcvts_n_s32_f32(MULTIPLE, 9u);
  *(v1 + 100) = 128;
  *(v1 + 92) = 0x8000000000LL;
  *(v1 + 68) = 0;
  *(v1 + 76) = 0;
  *(v1 + 84) = 0;
  *(v1 + 31) = 0;
  *(v1 + 108) = 0x6400000000LL;
  *(v1 + 116) = 100;
  *(v1 + 16) = (MULTIPLE * 384.0);
  return v1;
}

// 0x10f44a0
void LoadTexture(evtPictureProcessData_t *data, char *texpath) {
  struct sdfTexHandle_t_o *tex;
  struct UnityEngine_Texture2D_array *image;
  System_String_o *name;
  bool v11;

  data->tex = itfMiscLoadTexture(texpath);
  bGouto = 0;
  tex = data->tex;
  if (tex)
  {
    image = tex->image;
    if (LODWORD(image->max_length) == 1)
    {
      name = get_name(image->m_Items[0]);
      v11 = Equals_5234480(name, StringLiteral_15940);
      bGouto = v11;
    }
  }
}

// 0x10f3880
void evtKillPictureProcess(dds3ProcessID_t *id) {
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3KillProcess(&ida, 1);
}

// 0x10f3700
void evtPictureDrawOff(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
}

// 0x10f3530
void evtPictureDrawOn(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
}

// 0x10f2660
void evtPicturePriAdd(evtPicturePriTbl_t *indata) {
    dds3GetProcessData(0);
}

// 0x10f21b0
void evtPicturePriClear(void) {
    dds3GetProcessData(0);
}

// 0x10f2c70
void evtPicturePriDraw(void) {
    dds3GetProcessData(0);
    eglSetOt(0);
    eglLinkTest(0, 0, 0, 0, 0, 0, 0, 0);
    eglLinkAlpha(0);
}

// 0x10f57f0
dds3ProcessFunc_t *evtPicturePriProcess(dds3ProcessID_t *id) {
  struct evtPicture_StaticFields *static_fields;
  AssetBundleCtrl_o *asset_bc;
  u64 v6;
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3GetProcessData(&ida);
  else
  {
    static_fields = evtPicture->static_fields;
    if (static_fields->bGoutLoad)
  }
  static_fields->bGoutLoad = 1;
  asset_bc = get_asset_bc();
  Load(asset_bc, StringLiteral_15951, StringLiteral_15951, 0);
  {
    if (!*(v6 + 216))
  }
  evtPicturePriDraw(v6);
  evtPicturePriClear();
  return 0;
}

// 0x10f5a10
void evtPicturePriProcessInit(void) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3SetProcessData(0, 0);
    evtPicturePriClear();
}

// 0x10f5960
void *evtPicturePriShutdown(dds3ProcessID_t *id) {
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3GetProcessData(&ida);
  evtPicturePriProcess_id = 0;
  ida->func_ans = -1;
  return 0;
}

// 0x10f45b0
dds3ProcessFunc_t *evtPictureProcess1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    Set_PicFlag(0);
    Set_EventMode(0);
    Set_EventID(0);
    evtPicturePriAdd(0);
    return 0;
}

// 0x10f3f90
void evtPictureSetAlpha(dds3ProcessID_t *id, s32 alp0, s32 alp1, s32 time) {
    dds3GetProcessData(0);
}

// 0x10f38f0
void evtPictureSetOt(dds3ProcessID_t *id, s32 ot) {
    dds3GetProcessData(0);
}

// 0x10f3cd0
void evtPictureSetPos(dds3ProcessID_t *id, s32 x0, s32 y0, s32 x1, s32 y1, s32 time) {
    dds3GetProcessData(0);
}

// 0x10f3a00
void evtPictureSetPri(dds3ProcessID_t *id, s32 pri) {
    dds3GetProcessData(0);
}

// 0x10f3b10
void evtPictureSetSize(dds3ProcessID_t *id, s32 sw, s32 sh, s32 tw, s32 th) {
    dds3GetProcessData(0);
}

// 0x10f40e0
void evtPictureSetZoom(dds3ProcessID_t *id, s32 zoom0, s32 zoom1, s32 time) {
    dds3GetProcessData(0);
}

// 0x10f4d30
void *evtPictureShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    Log(0, 0);
    Set_PicFlag(0);
    return 0;
}

// 0x10f4240
s32 evtPictureStat(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    return 0;
}

// 0x10f4230
void evtPictureSwap(dds3ProcessID_t *id1, dds3ProcessID_t *id2, s32 pat, s32 prm) {
  ;
}

// 0x10f51b0
dds3ProcessID_t *evtStartPictureProcess(s32 priority, char *texpath) {
  u64 *v5;
  evtPictureProcessData_t_o *data;
  System_String_o *v9;
  System_Object_array *v11;
  u64 v14;
  struct evtPicture_StaticFields *static_fields;
  s32 PlayEventNo;
  UnityEngine_Transform_o *transform;
  UnityEngine_Object_o *v19;
  UnityEngine_Object_o *gFrame;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v26;
  UnityEngine_Transform_o *v28;
  Il2CppObject *v30;
  evtPicture_c *v34;
  s32 v35;
  UnityEngine_Transform_o *v36;
  UnityEngine_Component_o *main;
  UnityEngine_Transform_o *v38;
  u64 *v39;
  u64 *v40;

  v5 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v5);
  data = InitPictureProcessData();
  v9 = Concat_5224608(StringLiteral_15945, texpath);
  v11 = Empty_string_();
  Log(v9, v11, 0);
  LoadTexture(data, texpath);
  static_fields = evtPicture->static_fields;
  PlayEventNo = static_fields->PlayEventNo;
  if (PlayEventNo >= 710)
  {
    if (PlayEventNo <= 721)
    {
      if ((*(v14 + 295) & 2) != 0 && !*(v14 + 216))
      {
        static_fields = evtPicture->static_fields;
      }
      transform = get_transform(static_fields->pictures, 0);
      v19 = Find(transform, StringLiteral_15946, 0);
      if (op_Equality(v19, 0, 0))
      {
        if (op_Equality(gFrame, 0, 0))
        {
          asset_bc = get_asset_bc();
          Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_4738, StringLiteral_15947, StringLiteral_15948);
          if (op_Inequality(Prefab_16624656, 0, 0))
          {
            v26 = Find(StringLiteral_4905, 0);
            v28 = get_transform(v26, 0);
            v30 = Instantiate_object__425520(Prefab_16624656, v28);
            gFrame = v30;
            set_name(gFrame, StringLiteral_15949);
            AddComponent_object_(gFrame);
          }
        }
      }
      SetActive(gFrame, 0, 0);
    }
  }
  if ((*(v14 + 295) & 2) != 0 && !*(v14 + 216))
  data->pic = create_eventpicture(v14);
  v35 = PlayEventNo;
  if (v35 < 710)
  {
    data->sp = 0;
    if ((v34->_2.bitflags2 & 2) == 0)
  }
  data->sp = v35 < 722;
  ++PicBuffer;
  v36 = get_transform(pictures, 0);
  main = get_main();
  v38 = get_transform(main, 0);
  LookAt(v36, v38);
  v39 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v39,
    0,
    Method_evtPicture_evtPictureProcess1__);
  v40 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v40,
    0,
    Method_evtPicture_evtPictureShutdown__);
  return dds3StartProcess(StringLiteral_15950, priority, 1, 1, v39, 0, v40, 0, data, 0);
}

// 0x10f56a0
dds3ProcessID_t *evtStartPictureProcess2(s32 priority, sdfTexHandle_t *texdata) {
  u64 *v5;
  evtPictureProcessData_t_o *inited;
  Il2CppObject *data;
  u64 *v10;
  u64 *v11;

  v5 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v5);
  inited = InitPictureProcessData();
  inited->tex = texdata;
  data = inited;
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_evtPicture_evtPictureProcess1__);
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_evtPicture_evtPictureShutdown__);
  return dds3StartProcess(StringLiteral_15950, priority, 1, 1, v10, 0, v11, 0, data, 0);
}
