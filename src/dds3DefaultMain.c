#include "types.h"

typedef struct FsSaveData FsSaveData;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3DefaultMain__InitLoad_d__112 dds3DefaultMain__InitLoad_d__112;
typedef struct evtTexManager evtTexManager;

struct dds3DefaultMain__InitLoad_d__112 {
    s32 __1__state;
    void *__2__current;
    dds3DefaultMain *__4__this;
    char *_fontName_5__2;
    char *_langTbl_5__3[8];
    char *_load_tex1_5__4;
    char *_load_tex2_5__5;
    char *__7__wrap5;
    s32 __7__wrap6;
    char *_name_5__8;
};

void HighContrastTextureInit(void);
void InitShadow(dds3DefaultMain *this);
void Initialize(evtTexManager *this, char *key, char *path);
void Load(char *key, char *filePath);
char *RepColTag(char *txt, void **LegacyParamArray);
void SaveInit(FsSaveData *this);
void SetShadowMode(dds3DefaultMain *this, s32 mode);
void m_dds3KernelMainLoop(void);
void sdfInit(s32 aBuffSize, s32 aChipSize, s32 aFrameBuffSize);

// 0x1531610
void AutoMapDispOff(dds3DefaultMain *this) {
  UnityEngine_Object_o *autoMapCamera;
  UnityEngine_Object_o *autoMapCameraHalf;
  UnityEngine_Object_o *autoMapObj;

  autoMapCamera = this->autoMapCamera;
  if (op_Inequality(autoMapCamera, 0, 0))
    SetActive(this->autoMapCamera, 0, 0);
  autoMapCameraHalf = this->autoMapCameraHalf;
  if (op_Inequality(autoMapCameraHalf, 0, 0))
    SetActive(this->autoMapCameraHalf, 0, 0);
  autoMapObj = this->autoMapObj;
  if (op_Inequality(autoMapObj, 0, 0))
    SetActive(this->autoMapObj, 0, 0);
}

// 0x15314f0
void AutoMapDispOn(dds3DefaultMain *this) {
  UnityEngine_Object_o *autoMapCamera;
  UnityEngine_Object_o *autoMapCameraHalf;
  UnityEngine_Object_o *autoMapObj;

  autoMapCamera = this->autoMapCamera;
  if (op_Inequality(autoMapCamera, 0, 0))
    SetActive(this->autoMapCamera, 1, 0);
  autoMapCameraHalf = this->autoMapCameraHalf;
  if (op_Inequality(autoMapCameraHalf, 0, 0))
    SetActive(this->autoMapCameraHalf, 1, 0);
  autoMapObj = this->autoMapObj;
  if (op_Inequality(autoMapObj, 0, 0))
    SetActive(this->autoMapObj, 1, 0);
}

// 0x1531e30
void Awake(dds3DefaultMain *this) {
  u64 *v5;

  Log("dds3DefaultMain : Awake()", 0);
  set_targetFrameRate(30);
  set_vSyncCount(2);
  kernelObject = this;
  v5 = Allocate(FsSaveData);
  _ctor(v5, 0);
  saveData = v5;
  SaveInit(saveData);
  sdfInit(23986176, 1966080, 0x400000);
  this->initflag = 0;
  this->frameCount = 0;
  this->nextTimeMax = 0.5;
  this->nextTime = get_time(0) + this->nextTimeMax;
}

// 0x15319c0
void BlurScreenOff(dds3DefaultMain *this) {
  UnityEngine_Object_o *BlurScreen;

  BlurScreen = this->BlurScreen;
  if (op_Inequality(BlurScreen, 0, 0)
    && get_activeSelf(this->BlurScreen))
  {
    SetActive(this->BlurScreen, 0, 0);
  }
}

// 0x1531920
void BlurScreenOn(dds3DefaultMain *this) {
  UnityEngine_Object_o *BlurScreen;

  BlurScreen = this->BlurScreen;
  if (op_Inequality(BlurScreen, 0, 0)
    && !get_activeSelf(this->BlurScreen))
  {
    SetActive(this->BlurScreen, 1, 0);
  }
}

// 0x15306c0
void BtlDispOff(dds3DefaultMain *this) {
  UnityEngine_Object_o *btldevil;
  UnityEngine_Object_o *btlui;
  UnityEngine_Object_o *fldmap;
  UnityEngine_GameObject_o *FieldFilterCamera;

  btldevil = this->btldevil;
  if (op_Inequality(btldevil, 0, 0))
    SetActive(this->btldevil, 0, 0);
  btlui = this->btlui;
  if (op_Inequality(btlui, 0, 0))
    SetActive(this->btlui, 0, 0);
  fldmap = this->fldmap;
  if (op_Inequality(fldmap, 0, 0))
    SetActive(this->fldmap, 0, 0);
  FieldFilterCamera = this->FieldFilterCamera;
  this->fldprefab = 0;
  SetActive(FieldFilterCamera, 0, 0);
  SetActive(this->fldmapfilter, 0, 0);
  SetActive(this->fldmapfilter_render, 0, 0);
  SetActive(this->fldSky, 0, 0);
}

// 0x15305a0
void BtlDispOn(dds3DefaultMain *this) {
  UnityEngine_Object_o *btldevil;
  UnityEngine_Object_o *btlui;
  UnityEngine_Object_o *fldmap;

  btldevil = this->btldevil;
  if (op_Inequality(btldevil, 0, 0))
    SetActive(this->btldevil, 1, 0);
  btlui = this->btlui;
  if (op_Inequality(btlui, 0, 0))
    SetActive(this->btlui, 1, 0);
  fldmap = this->fldmap;
  if (op_Inequality(fldmap, 0, 0))
    SetActive(this->fldmap, 1, 0);
}

// 0x152c8a0
bool CampBaseOff(dds3DefaultMain *this) {
  UnityEngine_Object_o *campObjUI;

  campObjUI = this->campObjUI;
  if (op_Equality(campObjUI, 0, 0))
    return 0;
  if (!get_activeSelf(this->campObjUI))
    return 0;
  SetActive(this->campObjUI, 0, 0);
  return 1;
}

// 0x152d440
bool CampBaseOn(dds3DefaultMain *this) {
  UnityEngine_Object_o *campObjUI;

  campObjUI = this->campObjUI;
  if (!op_Equality(campObjUI, 0, 0))
  {
    if (get_activeSelf(this->campObjUI))
      return 1;
    SetActive(this->campObjUI, 1, 0);
  }
  return 0;
}

// 0x152d100
void CampDispOff(dds3DefaultMain *this, bool titlemode) {
  UnityEngine_Object_o *campObjBG;
  UnityEngine_Object_o *campObjUI;
  UnityEngine_Object_o *campObjCamera;
  UnityEngine_Transform_o *transform;
  s64 *Enumerator;
  s64 v12;
  UnityEngine_Component_o *v14;
  s64 v15;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  UnityEngine_GameObject_o *gameObject;
  s64 *Interface;
  u64 v21[3];

  campObjBG = this->campObjBG;
  if (op_Inequality(campObjBG, 0, 0))
    SetActive(this->campObjBG, 0, 0);
  campObjUI = this->campObjUI;
  if (op_Inequality(campObjUI, 0, 0))
    SetActive(this->campObjUI, 0, 0);
  campObjCamera = this->campObjCamera;
  if (op_Inequality(campObjCamera, 0, 0))
  {
    SetActive(this->campObjCamera, 0, 0);
    SetActive(this->AdAdjustObj, 1, 0);
  }
  if (!titlemode)
  {
    transform = get_transform(this->fldSky, 0);
    Enumerator = GetEnumerator(transform);
    while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
    {
      v12 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
      v14 = v12;
      if (v12)
      {
        v15 = *v12;
        if (*(*v12 + 288LL) < typeHierarchyDepth
          || *(*(v15 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Transform)
        {
          sub_8FC2C0(*(v15 + 64), UnityEngine_Transform, v21);
          if ((v21[0] & 1) != 0)
            v17 = v21[2];
          else
            v17 = v21 + 1;
          v18 = sub_8C4940(v17);
        }
      }
      if (op_Inequality(v14, 0, 0))
      {
        gameObject = get_gameObject(v14);
        SetActive(gameObject, 1, 0);
      }
    }
    Interface = QueryInterface(Enumerator, System_IDisposable);
    if (Interface)
      sub_22F10(0, System_IDisposable, Interface);
  }
}

// 0x152c960
void CampDispOn(dds3DefaultMain *this, bool titlemode) {
  UnityEngine_Object_o *campObjBG;
  UnityEngine_Object_o *campObjUI;
  UnityEngine_Object_o *campObjCamera;
  UnityEngine_Transform_o *transform;
  s64 *Enumerator;
  s64 v12;
  UnityEngine_Component_o *v14;
  s64 v15;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  UnityEngine_GameObject_o *gameObject;
  s64 *Interface;
  u64 v21[3];

  campObjBG = this->campObjBG;
  if (op_Inequality(campObjBG, 0, 0))
    SetActive(this->campObjBG, 1, 0);
  campObjUI = this->campObjUI;
  if (op_Inequality(campObjUI, 0, 0))
    SetActive(this->campObjUI, 1, 0);
  campObjCamera = this->campObjCamera;
  if (op_Inequality(campObjCamera, 0, 0))
  {
    SetActive(this->campObjCamera, 1, 0);
    SetActive(this->AdAdjustObj, 0, 0);
  }
  if (!titlemode)
  {
    transform = get_transform(this->fldSky, 0);
    Enumerator = GetEnumerator(transform);
    while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
    {
      v12 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
      v14 = v12;
      if (v12)
      {
        v15 = *v12;
        if (*(*v12 + 288LL) < typeHierarchyDepth
          || *(*(v15 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Transform)
        {
          sub_8FC2C0(*(v15 + 64), UnityEngine_Transform, v21);
          if ((v21[0] & 1) != 0)
            v17 = v21[2];
          else
            v17 = v21 + 1;
          v18 = sub_8C4940(v17);
        }
      }
      if (op_Inequality(v14, 0, 0))
      {
        gameObject = get_gameObject(v14);
        SetActive(gameObject, 0, 0);
      }
    }
    Interface = QueryInterface(Enumerator, System_IDisposable);
    if (Interface)
      sub_22F10(0, System_IDisposable, Interface);
  }
}

// 0x1530360
void FieldFilterAlf(dds3DefaultMain *this, f32 alpC) {
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  UnityEngine_Component_o *transform;
  UnityEngine_Camera_o *Component_GUILayer;
  UnityEngine_Component_o *v14;
  UnityEngine_GUILayer_o *v15;
  s64 v17;
  s32 Postblur_DrawStop;
  UnityEngine_Material_o *v22;
  s32 id_BlendPower;
  f32 v24;
  UnityEngine_Color_o v28;

  v5 = alpC / 255.0;
  v6 = fminf((alpC / 255.0) + 1.0, 1.0);
  v7 = 0.0;
  v8 = fmaxf(v6, 0.0);
  transform = get_transform(this->FieldFilterCamera, 0);
  Component_GUILayer = GetComponent_GUILayer_(transform);
  *&v28.r = 0;
  *&v28.b = 0;
  sub_19EC630(&v28.r, 0.0, 0.0, 0.0, v8);
  set_backgroundColor(Component_GUILayer, v28);
  if (!UnityEx_SkyFilterSkip)
    goto LABEL_11;
LABEL_6:
  UnityEx_SkyFilterSkip = 0;
LABEL_12:
  v14 = get_transform(this->fldmapfilter_render, 0);
  v15 = GetComponent_GUILayer_(v14);
  v17 = (v15->klass[2]._1.parent)(v15, v15->klass[2]._1.generic_class);
  if (Postblur_DrawStop < 1)
  {
    v22 = v17;
    v24 = v7;
  }
  else
  {
    v22 = v17;
    v24 = 0.0;
  }
  SetFloat_27246832(v22, id_BlendPower, v24);
  Postblur_FilterAlp = v7;
}

// 0x1530300
void FieldFilterOff(dds3DefaultMain *this) {
  SetActive(this->FieldFilterCamera, 0, 0);
  SetActive(this->fldmapfilter, 0, 0);
  SetActive(this->fldmapfilter_render, 0, 0);
  SetActive(this->fldSky, 0, 0);
}

// 0x15302a0
void FieldFilterOn(dds3DefaultMain *this) {
  SetActive(this->FieldFilterCamera, 1, 0);
  SetActive(this->fldmapfilter, 1, 0);
  SetActive(this->fldmapfilter_render, 1, 0);
  SetActive(this->fldSky, 1, 0);
}

// 0x1530a80
void FldDispOff(dds3DefaultMain *this) {
  UnityEngine_Object_o *fldmap;
  UnityEngine_Object_o *fldmapfilter;
  UnityEngine_Object_o *fldplayer;
  UnityEngine_GameObject_o *FieldFilterCamera;

  fldmap = this->fldmap;
  if (op_Inequality(fldmap, 0, 0))
    SetActive(this->fldmap, 0, 0);
  fldmapfilter = this->fldmapfilter;
  if (op_Inequality(fldmapfilter, 0, 0))
    SetActive(this->fldmapfilter, 0, 0);
  fldplayer = this->fldplayer;
  if (op_Inequality(fldplayer, 0, 0))
    SetActive(this->fldplayer, 0, 0);
  FieldFilterCamera = this->FieldFilterCamera;
  this->fldprefab = 0;
  SetActive(FieldFilterCamera, 0, 0);
  SetActive(this->fldmapfilter, 0, 0);
  SetActive(this->fldmapfilter_render, 0, 0);
  SetActive(this->fldSky, 0, 0);
}

// 0x1530930
void FldDispOn(dds3DefaultMain *this) {
  UnityEngine_Object_o *fldmap;
  UnityEngine_Object_o *fldmapfilter;
  UnityEngine_Object_o *fldplayer;

  fldmap = this->fldmap;
  if (op_Inequality(fldmap, 0, 0))
    SetActive(this->fldmap, 1, 0);
  fldmapfilter = this->fldmapfilter;
  if (op_Inequality(fldmapfilter, 0, 0))
    SetActive(this->fldmapfilter, 1, 0);
  fldplayer = this->fldplayer;
  if (op_Inequality(fldplayer, 0, 0))
    SetActive(this->fldplayer, 1, 0);
  SetActive(this->FieldFilterCamera, 1, 0);
  SetActive(this->fldmapfilter, 1, 0);
  SetActive(this->fldmapfilter_render, 1, 0);
  SetActive(this->fldSky, 1, 0);
}

// 0x1530d50
void *GetAnnounceUI(dds3DefaultMain *this) {
  return this->announceUI;
}

// 0x1531740
void *GetAutoMapCameraHalf(dds3DefaultMain *this) {
  return this->autoMapCameraHalf;
}

// 0x1531730
void *GetAutoMapCameraReal(dds3DefaultMain *this) {
  return this->autoMapCamera;
}

// 0x1531750
void *GetAutoMapObj(dds3DefaultMain *this) {
  return this->autoMapObj;
}

// 0x1531910
void *GetBlurScreen(dds3DefaultMain *this) {
  return this->BlurScreen;
}

// 0x1531760
void *GetButtonGuide(dds3DefaultMain *this) {
  return this->buttonGuide;
}

// 0x1530bf0
void *GetCampCameraObj(dds3DefaultMain *this) {
  return this->campObjCamera;
}

// 0x1530be0
void *GetCampDevil(dds3DefaultMain *this) {
  return this->campDevilObj;
}

// 0x1530bd0
void *GetCampObj(dds3DefaultMain *this) {
  return this->campObjUI;
}

// 0x1530d40
void *GetEnemyUI(dds3DefaultMain *this) {
  return this->enemyUI;
}

// 0x15317b0
void *GetMainCamera(dds3DefaultMain *this) {
  return this->MainCamera;
}

// 0x1530d20
void *GetMoonUI(dds3DefaultMain *this) {
  return this->moonUI;
}

// 0x1530d30
void *GetRadarUI(dds3DefaultMain *this) {
  return this->radarUI;
}

// 0x15317c0
void *GetRenderCamera(dds3DefaultMain *this) {
  return this->RenderCamera;
}

// 0x1531a60
void *GetShadowMapTex(dds3DefaultMain *this) {
  UnityEngine_Object_o *ShadowMap;
  u64 *v4;

  ShadowMap = this->ShadowMap;
  if (op_Equality(ShadowMap, 0, 0))
  {
    v4 = Allocate(UnityEngine_RenderTexture);
    _ctor_27407296(v4, 512, 512, 16, 0);
    this->ShadowMap = v4;
    set_name(v4, "ShadowMapRT");
    set_filterMode(this->ShadowMap, 1);
    set_wrapMode(this->ShadowMap, 1);
  }
  return this->ShadowMap;
}

// 0x1531780
s32 GetStChrMinor(dds3DefaultMain *this) {
  return this->st_char_minor;
}

// 0x15317a0
s32 GetStChrUnknown(dds3DefaultMain *this) {
  return this->st_char_unknown;
}

// 0x1532260
void *InitLoad(dds3DefaultMain *this) {
  dds3DefaultMain__InitLoad_d__112_o *v3;

  v3 = Allocate(dds3DefaultMain__InitLoad_d__112);
  InitLoad_d__112___ctor(v3, 0);
  v3->__4__this = this;
  return v3;
}

// 0x1531b50
void InitShadow(dds3DefaultMain *this) {
  UnityEngine_GameObject_o *v3;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_Transform_o *v6;
  UnityEngine_Component_o *v7;

  v3 = Find("ShadowCameras", 0);
  transform = get_transform(v3, 0);
  v5 = Find(transform, "ShadowCamera1", 0);
  this->ShadowCamera_1 = get_gameObject(v5);
  v6 = get_transform(v3, 0);
  v7 = Find(v6, "ShadowCamera2", 0);
  this->ShadowCamera_2 = get_gameObject(v7);
  SetShadowMode(this, 0);
}

// 0x1530c90
void PbDispOff(dds3DefaultMain *this) {
  UnityEngine_Object_o *ObjectsFolder3D;

  ObjectsFolder3D = this->ObjectsFolder3D;
  if (op_Inequality(ObjectsFolder3D, 0, 0))
    SetActive(this->ObjectsFolder3D, 0, 0);
}

// 0x1530c00
void PbDispOn(dds3DefaultMain *this) {
  UnityEngine_Object_o *ObjectsFolder3D;

  ObjectsFolder3D = this->ObjectsFolder3D;
  if (op_Inequality(ObjectsFolder3D, 0, 0))
    SetActive(this->ObjectsFolder3D, 1, 0);
}

// 0x1531870
void RenderCameraOff(dds3DefaultMain *this) {
  UnityEngine_Object_o *RenderCamera;

  RenderCamera = this->RenderCamera;
  if (op_Inequality(RenderCamera, 0, 0)
    && get_activeSelf(this->RenderCamera))
  {
    SetActive(this->RenderCamera, 0, 0);
  }
}

// 0x15317d0
void RenderCameraOn(dds3DefaultMain *this) {
  UnityEngine_Object_o *RenderCamera;

  RenderCamera = this->RenderCamera;
  if (op_Inequality(RenderCamera, 0, 0)
    && !get_activeSelf(this->RenderCamera))
  {
    SetActive(this->RenderCamera, 1, 0);
  }
}

// 0x1530d60
void SetAreaUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, char *text, u32 rgba) {
  UnityEngine_Object_o *areaUI;
  bool activeSelf;
  UnityEngine_Transform_o *transform;
  TMPro_TMP_Text_o *monitor;
  System_Object_array *v17;
  s64 *v18;
  s64 *v20;
  System_String_o *v23;
  UnityEngine_Vector3_o v24;
  s32 v25;

  v24.z = 0.0;
  *&v24.x = 0;
  areaUI = this->areaUI;
  if (!op_Equality(areaUI, 0, 0))
  {
    activeSelf = get_activeSelf(this->areaUI);
    if (disp)
    {
      if (!activeSelf)
        SetActive(this->areaUI, 1, 0);
      sub_8524C0(&v24.x, 1920.0, -46.0, 0.0);
      v24.x = v24.x + x;
      v24.y = v24.y + y;
      transform = get_transform(this->areaUI, 0);
      set_localPosition(transform, v24);
      monitor = GetComponent_object_(this->areaUI)[1].monitor;
      v17 = NewSpecific(object, 1u);
      if (rgba == -253991808)
        v25 = 9;
      else
        v25 = 0;
      v18 = sub_8D3950(s32, &v25);
      v20 = v18;
      v17->m_Items[0] = v20;
      v23 = RepColTag(text, v17);
      set_text(monitor, v23);
    }
    else if (activeSelf)
    {
      SetActive(this->areaUI, 0, 0);
    }
  }
}

// 0x1531fb0
void SetBoostFrameRate(dds3DefaultMain *this) {
  set_targetFrameRate(60);
  set_vSyncCount(1);
}

// 0x1531fe0
void SetCameraArrow(dds3DefaultMain *this, bool hdr, bool msaa) {
  Il2CppObject *Component_object;

  Component_object = GetComponent_object_(kernelObject->MainCamera);
  set_allowHDR(Component_object, hdr);
  set_allowMSAA(Component_object, msaa);
}

// 0x1532090
void SetCameraFar(dds3DefaultMain *this, f32 far) {
  Il2CppObject *Component_object;

  Component_object = GetComponent_object_(kernelObject->MainCamera);
  set_farClipPlane(Component_object, far);
}

// 0x1531110
void SetEnemyUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, s32 type, bool bad, bool direction, f32 cameraDir, f32 playerDir) {
  _BOOL4 v12;
  _BOOL4 v13;
  UnityEngine_Object_o *enemyUI;
  bool activeSelf;
  UnityEngine_Transform_o *transform;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *v24;
  UnityEngine_Transform_o *v25;
  UnityEngine_Vector3_o v26;
  UnityEngine_Quaternion_o v27;
  UnityEngine_Quaternion_o v28;

  v12 = direction;
  v13 = bad;
  v26.z = 0.0;
  *&v26.x = 0;
  enemyUI = this->enemyUI;
  if (!op_Equality(enemyUI, 0, 0))
  {
    activeSelf = get_activeSelf(this->enemyUI);
    if (disp)
    {
      if (!activeSelf)
        SetActive(this->enemyUI, 1, 0);
      sub_8524C0(&v26.x, 1728.0, -918.0, 0.0);
      v26.x = v26.x + x;
      v26.y = v26.y + y;
      transform = get_transform(this->enemyUI, 0);
      set_localPosition(transform, v26);
      Component_object = GetComponent_object_(this->enemyUI);
      SetInteger(Component_object[1].monitor, "compass", type);
      if (((get_activeSelf(Component_object[2].klass) ^ v13) & 1) != 0)
        SetActive(Component_object[2].klass, v13, 0);
      if (((get_activeSelf(Component_object[2].monitor) ^ v12) & 1) != 0)
        SetActive(Component_object[2].monitor, v12, 0);
      if (v12)
      {
        v24 = get_transform(Component_object[3].klass, 0);
        {
        }
        v27 = Euler(0.0, 0.0, cameraDir);
        set_rotation(v24, v27);
        v25 = get_transform(Component_object[3].monitor, 0);
        v28 = Euler(0.0, 0.0, playerDir);
        set_rotation(v25, v28);
      }
    }
    else if (activeSelf)
    {
      SetActive(this->enemyUI, 0, 0);
    }
  }
}

// 0x1530fa0
void SetMoonUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, s32 type) {
  UnityEngine_Object_o *moonUI;
  bool activeSelf;
  UnityEngine_Transform_o *transform;
  Il2CppObject *Component_object;
  UnityEngine_Vector3_o v15;

  v15.z = 0.0;
  *&v15.x = 0;
  moonUI = this->moonUI;
  if (!op_Equality(moonUI, 0, 0))
  {
    activeSelf = get_activeSelf(this->moonUI);
    if (disp)
    {
      if (!activeSelf)
        SetActive(this->moonUI, 1, 0);
      sub_8524C0(&v15.x, 40.0, -36.0, 0.0);
      v15.x = v15.x + x;
      v15.y = v15.y + y;
      transform = get_transform(this->moonUI, 0);
      set_localPosition(transform, v15);
      Component_object = GetComponent_object_(this->moonUI);
      SetInteger(Component_object[1].monitor, "moon", type);
    }
    else if (activeSelf)
    {
      SetActive(this->moonUI, 0, 0);
    }
  }
}

// 0x1531f80
void SetNormalFrameRate(dds3DefaultMain *this) {
  set_targetFrameRate(30);
  set_vSyncCount(2);
}

// 0x1531380
void SetRadarUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, s32 type) {
  UnityEngine_Object_o *radarUI;
  bool activeSelf;
  UnityEngine_Transform_o *transform;
  Il2CppObject *Component_object;
  UnityEngine_Vector3_o v15;

  v15.z = 0.0;
  *&v15.x = 0;
  radarUI = this->radarUI;
  if (!op_Equality(radarUI, 0, 0))
  {
    activeSelf = get_activeSelf(this->radarUI);
    if (disp)
    {
      if (!activeSelf)
        SetActive(this->radarUI, 1, 0);
      sub_8524C0(&v15.x, 148.0, -950.0, 0.0);
      v15.x = v15.x + x;
      v15.y = v15.y + y;
      transform = get_transform(this->radarUI, 0);
      set_localPosition(transform, v15);
      Component_object = GetComponent_object_(this->radarUI);
      SetInteger(Component_object[1].monitor, "farea", type);
    }
    else if (activeSelf)
    {
      SetActive(this->radarUI, 0, 0);
    }
  }
}

// 0x1531c10
void SetShadowMode(dds3DefaultMain *this, s32 mode) {
  Il2CppObject *Component_object;
  Il2CppObject *v6;
  s32 v7;
  s32 v8;
  UnityEngine_GameObject_o *ShadowCamera_2;
  bool v10;
  s32 cullingMask;
  s32 v12;
  s32 v13;
  s32 v14;
  UnityEngine_GameObject_o *ShadowCamera_1;
  bool v16;
  s32 v17;
  s32 v18;
  s32 v19;

  Component_object = GetComponent_object_(this->ShadowCamera_1);
  v6 = GetComponent_object_(this->ShadowCamera_2);
  switch (mode)
  {
    case 0:
      SetActive(this->ShadowCamera_1, 0, 0);
      cullingMask = get_cullingMask(Component_object);
      set_cullingMask(Component_object, cullingMask | 0x2000);
      v12 = get_cullingMask(Component_object);
      set_cullingMask(Component_object, v12 | 0x8000);
      ShadowCamera_2 = this->ShadowCamera_2;
      v10 = 0;
      goto LABEL_6;
    case 1:
    case 2:
      SetActive(this->ShadowCamera_1, 1, 0);
      v7 = get_cullingMask(Component_object);
      set_cullingMask(Component_object, v7 | 0x2000);
      v8 = get_cullingMask(Component_object);
      set_cullingMask(Component_object, v8 & 0xFFFF7FFF);
      ShadowCamera_2 = this->ShadowCamera_2;
      v10 = 1;
LABEL_6:
      SetActive(ShadowCamera_2, v10, 0);
      v13 = get_cullingMask(v6);
      set_cullingMask(v6, v13 & 0xFFFFDFFF);
      v14 = get_cullingMask(v6) | 0x8000;
      goto LABEL_10;
    case 3:
      ShadowCamera_1 = this->ShadowCamera_1;
      v16 = 1;
      goto LABEL_9;
    case 4:
      ShadowCamera_1 = this->ShadowCamera_1;
      v16 = 0;
LABEL_9:
      SetActive(ShadowCamera_1, v16, 0);
      v17 = get_cullingMask(Component_object);
      set_cullingMask(Component_object, v17 | 0x2000);
      v18 = get_cullingMask(Component_object);
      set_cullingMask(Component_object, v18 | 0x8000);
      SetActive(this->ShadowCamera_2, 0, 0);
      v19 = get_cullingMask(v6);
      set_cullingMask(v6, v19 & 0xFFFFDFFF);
      v14 = get_cullingMask(v6) & 0xFFFF7FFF;
LABEL_10:
      set_cullingMask(v6, v14);
      break;
    default:
      return;
  }
}

// 0x1531770
void SetStChrMinor(dds3DefaultMain *this, s32 minor) {
  this->st_char_minor = minor;
}

// 0x1531790
void SetStChrUnknown(dds3DefaultMain *this, s32 flag) {
  this->st_char_unknown = flag;
}

// 0x1532120
void Start(dds3DefaultMain *this) {
  dds3DefaultMain__InitLoad_d__112_o *v7;
  UnityEngine_GameObject_o *gameObject;

  Log("dds3DefaultMain : Start()", 0);
  InitShadow(this);
  HighContrastTextureInit();
  Load(saveData, 0);
  v7 = Allocate(dds3DefaultMain__InitLoad_d__112);
  InitLoad_d__112___ctor(v7, 0);
  v7->__4__this = this;
  StartCoroutine_27343696(this, v7);
  gameObject = get_gameObject(this);
  Initialize(gameObject, 0);
}

// 0x15322d0
void Update(dds3DefaultMain *this) {
  if (this->initflag)
  {
    else
    {
      m_dds3KernelMainLoop();
    }
  }
}

// 0x15308a0
void ViewerDispOff(dds3DefaultMain *this) {
  UnityEngine_Object_o *btldevil;

  btldevil = this->btldevil;
  if (op_Inequality(btldevil, 0, 0))
    SetActive(this->btldevil, 0, 0);
}

// 0x1530810
void ViewerDispOn(dds3DefaultMain *this) {
  UnityEngine_Object_o *btldevil;

  btldevil = this->btldevil;
  if (op_Inequality(btldevil, 0, 0))
    SetActive(this->btldevil, 1, 0);
}
