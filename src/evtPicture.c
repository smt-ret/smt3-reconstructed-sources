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
      v11 = Equals_5234480(name, "aibo");
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
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  UnityEngine_Object_o *v9;
  dds3ProcessID_t_o *v10;
  u64 v11[3];

  v10 = id;
  ProcessData = dds3GetProcessData(&v10);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v11);
      if ((v11[0] & 1) != 0)
        v7 = v11[2];
      else
        v7 = v11 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  LODWORD(ProcessData[1].klass) &= ~1u;
  v9 = ProcessData[8].klass;
  if (op_Inequality(v9, 0, 0) && get_activeSelf(v4[8].klass))
    SetActive(v4[8].klass, 0, 0);
}

// 0x10f3530
void evtPictureDrawOn(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  UnityEngine_Object_o *v9;
  UnityEngine_Transform_o *transform;
  dds3ProcessID_t_o *v12;
  u64 v13[3];
  UnityEngine_Quaternion_o v14;

  v12 = id;
  ProcessData = dds3GetProcessData(&v12);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v13);
      if ((v13[0] & 1) != 0)
        v7 = v13[2];
      else
        v7 = v13 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  LODWORD(ProcessData[1].klass) |= 1u;
  v9 = ProcessData[8].klass;
  if (op_Inequality(v9, 0, 0) && !get_activeSelf(v4[8].klass))
  {
    SetActive(v4[8].klass, 1, 0);
    transform = get_transform(v4[8].klass, 0);
    v14 = Euler(0.0, 0.0, 0.0);
    set_rotation(transform, v14);
  }
}

// 0x10f2660
void evtPicturePriAdd(evtPicturePriTbl_t *indata) {
  s64 *ProcessData;
  Il2CppClass *v4;
  s64 *v5;
  s64 *Interface;
  char *v7;
  s64 *v8;
  evtPicturePriTbl_t_o **v9;
  u32 v15;
  u64 v21[3];

  ProcessData = dds3GetProcessData(&evtPicturePriProcess_id);
  if (ProcessData)
  {
    v5 = ProcessData;
    Interface = QueryInterface(ProcessData, evtPicturePriTbl_t);
    if (!Interface)
    {
      sub_8FC2C0(*(*v5 + 64), v4, v21);
      if ((v21[0] & 1) != 0)
        v7 = v21[2];
      else
        v7 = v21 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  else
  {
    Interface = 0;
  }
  v9 = (Interface + 4);
  if (!*(Interface[4] + 16))
  {
    v15 = 0;
    if (!indata)
      goto LABEL_56;
    goto LABEL_55;
  }
  v9 = (Interface + 5);
  if (!*(Interface[5] + 16))
  {
    v15 = 1;
    if (!indata)
      goto LABEL_56;
    goto LABEL_55;
  }
  v9 = (Interface + 6);
  if (!*(Interface[6] + 16))
  {
    v15 = 2;
    if (!indata)
      goto LABEL_56;
    goto LABEL_55;
  }
  v9 = (Interface + 7);
  if (!*(Interface[7] + 16))
  {
    v15 = 3;
    if (!indata)
      goto LABEL_56;
    goto LABEL_55;
  }
  v9 = (Interface + 8);
  if (!*(Interface[8] + 16))
  {
    v15 = 4;
    if (!indata)
      goto LABEL_56;
    goto LABEL_55;
  }
  v9 = (Interface + 9);
  if (!*(Interface[9] + 16))
  {
    v15 = 5;
    if (!indata)
      goto LABEL_56;
    goto LABEL_55;
  }
  v9 = (Interface + 10);
  if (!*(Interface[10] + 16))
  {
    v15 = 6;
    if (!indata)
    {
LABEL_56:
      *v9 = indata;
      return;
    }
LABEL_55:
    goto LABEL_56;
  }
  v9 = (Interface + 11);
  if (!*(Interface[11] + 16))
  {
    v15 = 7;
    if (!indata)
      goto LABEL_56;
    goto LABEL_55;
  }
}

// 0x10f21b0
void evtPicturePriClear(void) {
  s64 *ProcessData;
  Il2CppClass *v3;
  s64 *v4;
  s64 *Interface;
  char *v6;
  s64 *v7;
  u64 v32[3];

  ProcessData = dds3GetProcessData(&evtPicturePriProcess_id);
  if (ProcessData)
  {
    v4 = ProcessData;
    Interface = QueryInterface(ProcessData, evtPicturePriTbl_t);
    if (!Interface)
    {
      sub_8FC2C0(*(*v4 + 64), v3, v32);
      if ((v32[0] & 1) != 0)
        v6 = v32[2];
      else
        v6 = v32 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  else
  {
    Interface = 0;
  }
  *(Interface[4] + 16) = 0;
  *(Interface[4] + 68) = 0;
  *(Interface[4] + 24) = 0;
  *(Interface[5] + 16) = 0;
  *(Interface[5] + 68) = 0;
  *(Interface[5] + 24) = 0;
  *(Interface[6] + 16) = 0;
  *(Interface[6] + 68) = 0;
  *(Interface[6] + 24) = 0;
  *(Interface[7] + 16) = 0;
  *(Interface[7] + 68) = 0;
  *(Interface[7] + 24) = 0;
  *(Interface[8] + 16) = 0;
  *(Interface[8] + 68) = 0;
  *(Interface[8] + 24) = 0;
  *(Interface[9] + 16) = 0;
  *(Interface[9] + 68) = 0;
  *(Interface[9] + 24) = 0;
  *(Interface[10] + 16) = 0;
  *(Interface[10] + 68) = 0;
  *(Interface[10] + 24) = 0;
  *(Interface[11] + 16) = 0;
  *(Interface[11] + 68) = 0;
  *(Interface[11] + 24) = 0;
}

// 0x10f2c70
void evtPicturePriDraw(void) {
  sdfIVector4_t_o *v1;
  struct System_Int32_array *v3;
  u32 max_length;
  sdfIVector4_t_o *v8;
  struct System_Int32_array *v9;
  u32 v10;
  sdfIVector4_t_o *v13;
  System_Array_o *v14;
  s32 v16;
  s32 v17;
  s32 v18;
  s64 *ProcessData;
  Il2CppClass *v20;
  s64 *v21;
  s64 *Interface;
  char *v23;
  s64 *v24;
  u64 v25;
  s64 *v26;
  s64 v30;
  f32 v31;
  f32 v32;
  s64 v34;
  UnityEngine_GameObject_o *v37;
  evtPicturePriTbl_t_o *v39;
  Il2CppObject *Component_object;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_Sprite_o *sprite;
  s64 v45;
  f32 v47;
  f32 v50;
  f32 v51;
  long f64 v52;
  long f64 v53;
  long f64 v54;
  s64 v57;
  f32 v58;
  s32 v59;
  f32 v60;
  Il2CppObject *v61;
  UnityEngine_Vector3_o v64;
  char *v65;
  UnityEngine_Quaternion_o v66;

  v1 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v1);
  v3 = NewSpecific(s32, 4u);
  max_length = v3->max_length;
  v3->m_Items[2] = 16 * screen_wid;
  v3->m_Items[3] = 8 * screen_hei;
  v1->pm = v3;
  v8 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v8);
  v9 = NewSpecific(s32, 4u);
  v10 = v9->max_length;
  v9->m_Items[2] = 30720;
  v9->m_Items[3] = 17280;
  v8->pm = v9;
  v13 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v13);
  v14 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v14, Field__PrivateImplementationDetails__2FD8E5B8C0083A6C00EC06C57728087819F8BE34);
  v13->pm = v14;
  v16 = 0;
  v17 = 4;
  do
  {
    v18 = v17;
    ProcessData = dds3GetProcessData(&evtPicturePriProcess_id);
    if (ProcessData)
    {
      v21 = ProcessData;
      Interface = QueryInterface(ProcessData, evtPicturePriTbl_t);
      if (!Interface)
      {
        sub_8FC2C0(*(*v21 + 64), v20, &v64);
        if ((LOBYTE(v64.x) & 1) != 0)
          v23 = v65;
        else
          v23 = &v64.x + 1;
        v24 = sub_8C4940(v23);
      }
    }
    else
    {
      Interface = 0;
    }
    v25 = 0;
    v26 = Interface + 4;
    do
    {
      v34 = v26[v25];
      if (*(v34 + 16))
      {
        if (*(v34 + 68) == v18)
        {
          if (v16)
          {
            if (v25 >= *(Interface + 6))
              goto LABEL_48;
          }
          else
          {
            eglSetOt(71);
            v16 = 1;
            eglLinkTest(1, 0, 128, 1, 0, 0, 1, 1);
            eglLinkAlpha(0);
            eglSetOt(51);
            eglLinkTest(1, 0, 128, 1, 0, 0, 1, 1);
            eglLinkAlpha(0);
            if (v25 >= *(Interface + 6))
            {
LABEL_48:
            }
          }
          v37 = *(v26[v25] + 72);
          if (!op_Equality(v37, 0, 0))
          {
            v39 = v26[v25];
            cut_sprite(v39);
            Component_object = GetComponent_object_(v37);
            get_sizeDelta(Component_object);
            get_sizeDelta(Component_object);
            Component_GUILayer = GetComponent_GUILayer_(Component_object);
            sprite = get_sprite(Component_GUILayer);
            get_rect(sprite);
            v45 = v26[v25];
            if (*(v45 + 80))
            {
              v47 = *(v45 + 28);
              v31 = v47 + -484.0;
              v30 = v26[v25];
              v32 = ((screen_hei * 0.5) + -80.0) - *(v30 + 32);
            }
            else
            {
              v30 = v26[v25];
              v31 = *(v30 + 28) + (screen_wid * -0.5);
              v32 = (screen_hei * 0.5) - *(v30 + 32);
            }
            v50 = v31 + -48.4;
            v51 = v32 + 36.3;
            if (!*(v30 + 80))
            {
              v51 = v32;
              v50 = v31;
            }
            v64.z = 0.0;
            *&v64.x = 0;
            sub_8524C0(&v64.x, v50, v51, 0.0);
            set_localPosition(Component_object, v64);
            v52 = (*&Component_GUILayer->klass[1]._2.typeHierarchyDepth)(
                    Component_GUILayer,
                    Component_GUILayer->klass[1].vtable._0_Equals.methodPtr);
            (Component_GUILayer->klass[1].vtable._0_Equals.method)(
              Component_GUILayer,
              Component_GUILayer->klass[1].vtable._1_Finalize.methodPtr,
              v52,
              v53,
              v54,
              *(v26[v25] + 64) * 0.0078125);
            v57 = v26[v25];
            v58 = *(v57 + 44);
            v59 = *(v57 + 80);
            v60 = v58 * 1.1;
            *&v64.x = 0;
            if (!v59)
              v60 = v58;
            v64.z = 0.0;
            sub_8524C0(&v64.x, v60, v60, 1.0);
            set_localScale(Component_object, v64);
            v61 = GetComponent_object_(v37);
            set_sortingOrder(v61, 4 - *(v26[v25] + 68), 0);
            {
            }
            v66 = Euler(0.0, 0.0, 0.0);
            set_localRotation(Component_object, v66);
          }
        }
      }
      ++v25;
    }
    while (v25 != 8);
    v17 = v18 - 1;
  }
  while (v18);
}

// 0x10f57f0
dds3ProcessFunc_t *evtPicturePriProcess(dds3ProcessID_t *id) {
  AssetBundleCtrl_o *asset_bc;
  u64 v6;
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3GetProcessData(&ida);
  else
  {
    if (bGoutLoad)
      goto LABEL_22;
  }
  bGoutLoad = 1;
  if (IsDLC())
  {
LABEL_22:
      goto LABEL_25;
    goto LABEL_23;
  }
  asset_bc = get_asset_bc();
  Load(asset_bc, "extrar_o", "extrar_o", 0);
  {
LABEL_23:
  }
LABEL_25:
  evtPicturePriDraw(v6);
  evtPicturePriClear();
  return 0;
}

// 0x10f5a10
void evtPicturePriProcessInit(void) {
  Il2CppObject *v1;
  u64 *v2;
  u64 *v4;
  u64 *v6;
  u64 *v8;
  u64 *v10;
  u64 *v12;
  u64 *v14;
  u64 *v16;
  u64 *v18;
  UnityEngine_Transform_o *transform;
  UnityEngine_GameObject_o *v22;
  UnityEngine_Transform_o *v23;
  Il2CppObject *v24;
  Il2CppObject *v25;
  UnityEngine_GameObject_o *v26;
  Il2CppObject *Component_object;
  s32 screen_wid;
  s32 screen_hei;
  u64 *v33;
  u64 *v34;
  UnityEngine_Vector2_o v46;

  v1 = NewSpecific(evtPicturePriTbl_t, 8u);
  v2 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v2);
  v1[2].klass = v2;
  v4 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v4);
  v1[2].monitor = v4;
  v6 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v6);
  v1[3].klass = v6;
  v8 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v8);
  v1[3].monitor = v8;
  v10 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v10);
  v1[4].klass = v10;
  v12 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v12);
  v1[4].monitor = v12;
  v14 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v14);
  v1[5].klass = v14;
  v16 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v16);
  v1[5].monitor = v16;
  v18 = Allocate(UnityEngine_GameObject);
  _ctor(v18, "pictures", 0);
  pictures = v18;
  transform = get_transform(pictures, 0);
  v22 = Find("Field", 0);
  v23 = get_transform(v22, 0);
  SetParent(transform, v23);
  v24 = AddComponent_object_(pictures);
  v25 = AddComponent_object_(pictures);
  set_renderMode(v24, 1);
  v26 = Find("Main Camera", 0);
  Component_object = GetComponent_object_(v26);
  set_worldCamera(v24, Component_object);
  set_uiScaleMode(v25, 1);
  v46 = 0;
  sub_851710(&v46, screen_wid, screen_hei);
  set_referenceResolution(v25, v46);
  v33 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v33,
    0,
    Method_evtPicture_evtPicturePriProcess__);
  v34 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v34,
    0,
    Method_evtPicture_evtPicturePriShutdown__);
  evtPicturePriProcess_id = dds3StartProcess(
                                                                  "picpri",
                                                                  0x2AF8u,
                                                                  1,
                                                                  1,
                                                                  v33,
                                                                  0,
                                                                  v34,
                                                                  0,
                                                                  0,
                                                                  0);
  dds3SetProcessData(&evtPicturePriProcess_id, v1);
  evtPicturePriClear();
  PlayEventNo = 0;
  PicBuffer = 0;
  bGoutLoad = 0;
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
  u64 *v2;
  Il2CppObject *ProcessData;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  s32 PlayEventNo;
  _BOOL4 v13;
  void *monitor;
  System_String_o *v15;
  UnityEngine_Object_o *FildMapObj;
  u64 v19;
  s32 monitor_high;
  bool v21;
  s32 v22;
  s32 v23;
  s32 klass_high;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  s32 v32;
  s32 v33;
  s32 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  s32 v38;
  s32 v39;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  s64 v50;
  s32 v52;
  u64 *v53;
  s64 v54;
  s32 v56;
  f32 v57;
  f32 v58;
  f32 v60;
  f32 v61;
  f32 v62;
  f32 v63;
  f32 v64;
  UnityEngine_Object_o *gFrame;
  dds3ProcessID_t_o *v70;
  u64 v71[3];

  v70 = id;
  v2 = Allocate(evtPicturePriTbl_t);
  evtPicturePriTbl_t___ctor(v2);
  ProcessData = dds3GetProcessData(&v70);
  v6 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v71);
      if ((v71[0] & 1) != 0)
        v9 = v71[2];
      else
        v9 = v71 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    if (PlayEventNo < 710)
      goto LABEL_16;
  }
  v13 = PlayEventNo < 722;
  monitor = v6[1].monitor;
  if (monitor)
  {
LABEL_23:
    v15 = *(monitor + 15);
    if (Equals_5239888(v15, "f020_bg01", 5)
      || Equals_5239888(v15, "f031_bg01", 5)
      || Equals_5239888(v15, "f035_bg01", 5))
    {
      if (op_Inequality(FildMapObj, 0, 0))
      {
        SetActive(FildMapObj, 0, 0);
      }
    }
  }
LABEL_37:
  if ((v6[1].klass & 1) == 0)
    return 0;
  v19 = v6[1].monitor;
  if (!v19)
    return 0;
  monitor_high = HIDWORD(v6[5].monitor);
  v21 = __OFSUB__(monitor_high, 1);
  v22 = monitor_high - 1;
  if (v22 < 0 == v21)
  {
    klass_high = HIDWORD(v6[5].klass);
    v23 = v6[5].monitor;
    v25 = v6[4].monitor;
    v27 = HIDWORD(v6[4].monitor);
    v26 = v6[5].klass;
    HIDWORD(v6[5].monitor) = v22;
    v28 = v23 - v22;
    HIDWORD(v6[2].klass) = v28 * (v26 - v25) / v23 + v25;
    LODWORD(v6[2].monitor) = (klass_high - v27) * v28 / v23 + v27;
  }
  v29 = HIDWORD(v6[6].monitor);
  v21 = __OFSUB__(v29, 1);
  v30 = v29 - 1;
  if (v30 < 0 == v21)
  {
    v31 = v6[6].klass;
    v32 = HIDWORD(v6[6].klass);
    v33 = v6[6].monitor;
    HIDWORD(v6[6].monitor) = v30;
    v34 = (v33 - v30) * (v32 - v31) / v33 + v31;
    HIDWORD(v6[2].monitor) = v34;
    if (v34 < 0)
    {
      HIDWORD(v6[2].monitor) = 0;
    }
    else if (v34 >= 129)
    {
      HIDWORD(v6[2].monitor) = 128;
      v35 = HIDWORD(v6[7].monitor);
      v21 = __OFSUB__(v35, 1);
      v36 = v35 - 1;
      if (v36 < 0 != v21)
        goto LABEL_50;
      goto LABEL_49;
    }
  }
  v37 = HIDWORD(v6[7].monitor);
  v21 = __OFSUB__(v37, 1);
  v36 = v37 - 1;
  if (v36 < 0 == v21)
  {
LABEL_49:
    v38 = v6[7].klass;
    v39 = HIDWORD(v6[7].klass) - v38;
    HIDWORD(v6[7].monitor) = v36;
    *&v6[3].klass = ((v39 * (LODWORD(v6[7].monitor) - v36)) / SLODWORD(v6[7].monitor)) + v38;
  }
LABEL_50:
  v2[2] = v19;
  if (bGouto)
  {
    if (v13)
      goto LABEL_55;
  }
  else
  {
    gPictureFlag = 1;
    if (v13)
    {
LABEL_55:
      v42 = ((*&v6[3].klass * SHIDWORD(v6[3].klass)) / 100.0) - SHIDWORD(v6[3].klass);
      v43 = SHIDWORD(v6[2].klass) - (v42 * 0.5);
      *(v2 + 7) = v43;
      *(v2 + 9) = v42 + (v43 + SHIDWORD(v6[3].klass));
      v44 = ((*&v6[3].klass * SLODWORD(v6[3].monitor)) / 100.0) - SLODWORD(v6[3].monitor);
      v45 = SLODWORD(v6[2].monitor) - (v44 * 0.5);
      *(v2 + 8) = v45;
      *(v2 + 10) = v44 + (v45 + SLODWORD(v6[3].monitor));
      Set_PicFlag(1);
      Set_EventMode(1);
      Set_EventID(PlayEventNo);
        goto LABEL_76;
      goto LABEL_62;
    }
  }
  v50 = *(v6[1].monitor + 16);
  v52 = (*(**(v50 + 32) + 360LL))(*(v50 + 32), *(**(v50 + 32) + 368LL));
  v53 = v6[1].monitor;
  HIDWORD(v6[3].monitor) = v52;
  HIDWORD(v6[3].klass) = v52;
  v54 = v53[16];
  v56 = (*(**(v54 + 32) + 392LL))(*(v54 + 32), *(**(v54 + 32) + 400LL));
  v57 = (*&v6[3].klass * v56) / 100.0;
  v58 = SLODWORD(v6[2].monitor) + ((v57 - v56) * -0.5);
  LODWORD(v6[4].klass) = v56;
  LODWORD(v6[3].monitor) = v56;
  *(v2 + 8) = v58;
  v60 = v58 * (screen_hei / 384.0);
  *(v2 + 8) = v60;
  *(v2 + 10) = v57 + v60;
  v61 = SHIDWORD(v6[3].klass);
  v62 = (*&v6[3].klass * v61) / 100.0;
  v63 = SHIDWORD(v6[2].klass) + ((v62 - v61) * -0.5);
  *(v2 + 7) = v63;
  v64 = v63 * (screen_wid * 0.0019531);
  *(v2 + 7) = v64;
  *(v2 + 9) = v62 + v64;
    goto LABEL_76;
LABEL_62:
LABEL_76:
  if (op_Inequality(gFrame, 0, 0))
  {
    if (!get_activeSelf(gFrame))
    {
      SetActive(gFrame, 1, 0);
    }
  }
  v2[6] = 0;
  *(v2 + 14) = HIDWORD(v6[3].monitor);
  *(v2 + 15) = v6[4].klass;
  v2[9] = v6[8].klass;
  *(v2 + 16) = HIDWORD(v6[2].monitor);
  *(v2 + 17) = HIDWORD(v6[4].klass);
  *(v2 + 6) = v6[2].klass;
  *(v2 + 80) = v6[8].monitor;
  *(v2 + 11) = *&v6[3].klass / 100.0;
  evtPicturePriAdd(v2);
  return 0;
}

// 0x10f3f90
void evtPictureSetAlpha(dds3ProcessID_t *id, s32 alp0, s32 alp1, s32 time) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3ProcessID_t_o *v13;
  u64 v14[3];

  v13 = id;
  else
  {
    ProcessData = dds3GetProcessData(&v13);
    if (!ProcessData)
      goto LABEL_12;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v11 = v14[2];
    else
      v11 = v14 + 1;
    v12 = sub_8C4940(v11);
  }
LABEL_12:
  HIDWORD(ProcessData[2].monitor) = alp0;
  LODWORD(ProcessData[6].klass) = alp0;
  HIDWORD(ProcessData[6].klass) = alp1;
  LODWORD(ProcessData[6].monitor) = time;
  HIDWORD(ProcessData[6].monitor) = time;
}

// 0x10f38f0
void evtPictureSetOt(dds3ProcessID_t *id, s32 ot) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3ProcessID_t_o *v9;
  u64 v10[3];

  v9 = id;
  ProcessData = dds3GetProcessData(&v9);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v10);
    if ((v10[0] & 1) != 0)
      v7 = v10[2];
    else
      v7 = v10 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD(ProcessData[2].klass) = ot;
}

// 0x10f3cd0
void evtPictureSetPos(dds3ProcessID_t *id, s32 x0, s32 y0, s32 x1, s32 y1, s32 time) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v17;
  char *v18;
  s64 *v19;
  Il2CppClass *v20;
  s64 v21;
  char *v22;
  s64 *v23;
  f32 MULTIPLE;
  s32 v27;
  s32 v28;
  dds3ProcessID_t_o *v29;
  u64 v30[2];
  char *v31;

  v29 = id;
  ProcessData = dds3GetProcessData(&v29);
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || (v17 = ProcessData, klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t))
    {
      sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v30);
      if ((v30[0] & 1) != 0)
        v18 = v31;
      else
        v18 = v30 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  else
  {
    v17 = 0;
  }
  if (PlayEventNo > 709)
  {
    else
    {
      if (PlayEventNo <= 721)
        goto LABEL_29;
    }
    MULTIPLE = 1.0;
LABEL_35:
    ProcessData = v17;
    goto LABEL_36;
  }
  if (ProcessData)
  {
    v20 = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < v21
      || v20->_2.typeHierarchy[v21 - 1] != evtPictureProcessData_t)
    {
      sub_8FC2C0(v20->_1.element_class, evtPictureProcessData_t, v30);
      if ((v30[0] & 1) != 0)
        v22 = v31;
      else
        v22 = v30 + 1;
      v23 = sub_8C4940(v22);
    }
  }
  MULTIPLE = 1.0;
LABEL_36:
  v27 = (MULTIPLE * x0);
  LODWORD(ProcessData[5].monitor) = time;
  HIDWORD(ProcessData[5].monitor) = time;
  v28 = (MULTIPLE * y0);
  HIDWORD(ProcessData[2].klass) = v27;
  LODWORD(ProcessData[2].monitor) = v28;
  LODWORD(ProcessData[4].monitor) = v27;
  HIDWORD(ProcessData[4].monitor) = v28;
  LODWORD(ProcessData[5].klass) = (MULTIPLE * x1);
  HIDWORD(ProcessData[5].klass) = (MULTIPLE * y1);
}

// 0x10f3a00
void evtPictureSetPri(dds3ProcessID_t *id, s32 pri) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3ProcessID_t_o *v9;
  u64 v10[3];

  v9 = id;
  ProcessData = dds3GetProcessData(&v9);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v10);
    if ((v10[0] & 1) != 0)
      v7 = v10[2];
    else
      v7 = v10 + 1;
    v8 = sub_8C4940(v7);
  }
  HIDWORD(ProcessData[4].klass) = pri;
}

// 0x10f3b10
void evtPictureSetSize(dds3ProcessID_t *id, s32 sw, s32 sh, s32 tw, s32 th) {
  Il2CppObject *ProcessData;
  Il2CppObject *v12;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v15;
  s64 *v16;
  dds3ProcessID_t_o *v18;
  u64 v19[3];

  v18 = id;
  ProcessData = dds3GetProcessData(&v18);
  v12 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v19);
      if ((v19[0] & 1) != 0)
        v15 = v19[2];
      else
        v15 = v19 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  HIDWORD(v12[3].klass) = (MULTIPLE * sw);
  LODWORD(v12[3].monitor) = (MULTIPLE * sh);
  HIDWORD(v12[3].monitor) = (MULTIPLE * tw);
  LODWORD(v12[4].klass) = (MULTIPLE * th);
}

// 0x10f40e0
void evtPictureSetZoom(dds3ProcessID_t *id, s32 zoom0, s32 zoom1, s32 time) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3ProcessID_t_o *v13;
  u64 v14[3];

  v13 = id;
  else
  {
    ProcessData = dds3GetProcessData(&v13);
    if (!ProcessData)
      goto LABEL_12;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v11 = v14[2];
    else
      v11 = v14 + 1;
    v12 = sub_8C4940(v11);
  }
LABEL_12:
  *&ProcessData[3].klass = zoom0;
  LODWORD(ProcessData[7].klass) = zoom0;
  HIDWORD(ProcessData[7].klass) = zoom1;
  LODWORD(ProcessData[7].monitor) = time;
  HIDWORD(ProcessData[7].monitor) = time;
}

// 0x10f4d30
void *evtPictureShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  UnityEngine_Object_o *v9;
  UnityEngine_Object_o *v11;
  u64 *monitor;
  s64 v13;
  s64 v14;
  u64 v15;
  s32 PicBuffer;
  u64 *v20;
  System_String_o *v21;
  System_Object_array *v23;
  UnityEngine_Object_o *gFrame;
  UnityEngine_Object_o *v29;
  dds3ProcessID_t_o *v34;
  u64 v35[3];

  v34 = id;
  ProcessData = dds3GetProcessData(&v34);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v35);
      if ((v35[0] & 1) != 0)
        v7 = v35[2];
      else
        v7 = v35 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = ProcessData[8].klass;
  if (op_Inequality(v9, 0, 0))
  {
    v11 = v4[8].klass;
    Destroy_27360000(v11);
  }
  monitor = v4[1].monitor;
  if (monitor)
  {
    v13 = monitor[16];
    v14 = *(v13 + 24);
    if (v14 >= 1)
    {
      v15 = 0;
      do
      {
        v14 = v13 + 8 * v15++;
        *(v14 + 32) = 0;
        v13 = *(v4[1].monitor + 16);
        LODWORD(v14) = *(v13 + 24);
      }
      while (v15 < v14);
    }
    v4[1].monitor = 0;
    v34->func_ans = -1;
    if (PicBuffer)
    {
      PicBuffer = PicBuffer - 1;
    }
    LODWORD(v35[0]) = PicBuffer;
    v20 = sub_8D3950(s32, v35);
    v21 = Concat("PicBuffer = ", v20);
    v23 = Empty_string_();
    Log(v21, v23, 0);
    if (!PicBuffer)
    {
      if (op_Inequality(gFrame, 0, 0))
      {
        v29 = gFrame;
        Destroy_27360000(v29);
      }
      gFrame = 0;
    }
    UnloadUnusedAssets();
  }
  else
  {
    v34->func_ans = -1;
  }
  Set_PicFlag(0);
  gPictureFlag = 0;
  return 0;
}

// 0x10f4240
s32 evtPictureStat(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v5;
  char *v7;
  s64 *v8;
  dds3ProcessID_t_o *v9[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPictureProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPictureProcessData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v5 = HIDWORD(ProcessData[5].monitor) != 0;
  if (HIDWORD(ProcessData[6].monitor))
    v5 |= 2u;
  if (HIDWORD(ProcessData[7].monitor))
    return v5 | 4;
  else
    return v5;
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
  v9 = Concat_5224608("evtStartPictureProcess : ", texpath);
  v11 = Empty_string_();
  Log(v9, v11, 0);
  LoadTexture(data, texpath);
  if (PlayEventNo >= 710)
  {
    if (PlayEventNo <= 721)
    {
      transform = get_transform(pictures, 0);
      v19 = Find(transform, "Canvas_UI/EvtFrame", 0);
      if (op_Equality(v19, 0, 0))
      {
        if (op_Equality(gFrame, 0, 0))
        {
          asset_bc = get_asset_bc();
          Prefab_16624656 = LoadPrefab_16624656(asset_bc, "ecmn", "dds3data/UI/event_frame", "event_frame");
          if (op_Inequality(Prefab_16624656, 0, 0))
          {
            v26 = Find("Canvas_UI", 0);
            v28 = get_transform(v26, 0);
            v30 = Instantiate_object__425520(Prefab_16624656, v28);
            gFrame = v30;
            set_name(gFrame, "EvtFrame");
            AddComponent_object_(gFrame);
          }
        }
      }
      SetActive(gFrame, 0, 0);
    }
  }
  data->pic = create_eventpicture(v14);
  v35 = PlayEventNo;
  if (v35 < 710)
  {
    data->sp = 0;
    if ((v34->_2.bitflags2 & 2) == 0)
      goto LABEL_57;
    goto LABEL_51;
  }
  data->sp = v35 < 722;
  if ((v34->_2.bitflags2 & 2) != 0)
  {
LABEL_51:
  }
LABEL_57:
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
  return dds3StartProcess("Picture", priority, 1, 1, v39, 0, v40, 0, data, 0);
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
  return dds3StartProcess("Picture", priority, 1, 1, v10, 0, v11, 0, data, 0);
}
