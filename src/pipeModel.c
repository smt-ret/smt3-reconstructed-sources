#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct tagpipeBasic tagpipeBasic;

void FldDispOn(dds3DefaultMain *this);
void LoadModel(tagpipeBasic *pModel, s32 mNum, s32 mPtn, s32 motion, f32 frm1, f32 frm2, f32 speed, char *name);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void SetMdlPosition(tagpipeBasic **pWork);
void SetMdlRotation(tagpipeBasic **pWork);
dds3Basic_t *dds3AddUnitObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot);
void dds3DeleteUnitObjectBasic(dds3Basic_t **aPtr);
dds3Basic_t *dds3GetControlScene(void);
void *dds3ObjectBaseGetModelHandle(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseMakeUnit(dds3Basic_t **pObjectBasic, s32 major, s32 minor);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
u32 dds3SerializeID(void);
dds3Basic_t *dds3SetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic, dds3Basic_t *pUnitBasic);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3SetSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
u32 mdlGetColor(dds3ModelHandle_t **aHandle);
sdfMotionCtrlr_t *mdlGetMotionCtrlr(dds3ModelHandle_t **aHandle, s32 aGroup);
void mdlSetColor(dds3ModelHandle_t **aHandle, u32 aColor);
void mdlSetMotionSpeed(dds3ModelHandle_t **aHandle, f32 speed);
void mdlSmoothLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng);
void mymdlVisible(tagpipeBasic *pWork, s8 value);

// 0x1536570
void InitModel(tagpipeBasic *pModel, s32 mNum, s32 mPtn, s32 motion, f32 frm1, f32 frm2, f32 speed, char *name) {
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3GetControlScene();
    dds3SetActiveUnitSceneBasic(0, 0);
    dds3ObjectBaseMakeUnit(0, 0, 0);
    dds3ObjectBaseGetModelHandle(0);
    LoadModel(0, 0, 0, 0, 0, 0, 0, 0);
    mdlSetMotionSpeed(0, 0);
    mdlSmoothLoopMotion(0, 0, 0, 0, 0);
    dds3SetRadiusPoseSet(0, 0);
    dds3ObjectBaseOffFlag(0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
}

// 0x1536910
void LoadModel(tagpipeBasic *pModel, s32 mNum, s32 mPtn, s32 motion, f32 frm1, f32 frm2, f32 speed, char *name) {
    FldDispOn(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    SetMdlRotation(0);
}

// 0x1537530
void SetMdlPosition(tagpipeBasic **pWork) {
  UnityEngine_Object_o *gameObject;
  struct dds3Basic_t_o *basic;
  f32 *poseset;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  UnityEngine_Transform_o *transform;
  UnityEngine_Vector3_o v12;
  UnityEngine_Vector3_o v13;
  UnityEngine_Vector4_o v14;

  gameObject = (*pWork)->basic->gameObject;
  if (op_Inequality(gameObject, 0, 0))
  {
    basic = (*pWork)->basic;
    poseset = basic->poseset;
    v7 = poseset[6];
    v8 = poseset[7];
    v10 = poseset[8];
    v9 = poseset[9];
    v14.x = v7;
    v14.y = v8;
    v14.z = v10;
    v14.w = v9;
    v12 = op_Implicit_8738992(v14);
    transform = get_transform(basic->gameObject, 0);
    v13.x = v12.x / 100.0;
    v13.y = v12.y / -100.0;
    v13.z = v12.z / 100.0;
    set_localPosition(transform, v13);
  }
}

// 0x1537070
void SetMdlRotation(tagpipeBasic **pWork) {
}

// 0x1537ec0
void SetObjPosition(void **obj, sdfVector3_t setPos) {
  f32 v3;
  f32 v4;
  f32 v5;
  UnityEngine_Transform_o *transform;
  UnityEngine_Vector3_o v7;

  v3 = setPos.x / 100.0;
  v4 = setPos.y / -100.0;
  v5 = setPos.z / 100.0;
  transform = get_transform(*obj, 0);
  v7.x = v3;
  v7.y = v4;
  v7.z = v5;
  set_localPosition(transform, v7);
}

// 0x1536560
u16 mdlGetMotionLength(dds3ModelHandle_t *aHandle) {
  return aHandle->motionCtrlr->frameLength;
}

// 0x1537150
s16 mymdlAddObject(tagpipeBasic **pWork, u16 mdlSize) {
  s32 v5;
  s16 v6;
  Il2CppClass **v8;
  Il2CppClass *v9;
  char *v10;
  Il2CppClass *v11;
  UnityEngine_GameObject_o *v15;

  v5 = mdlSize;
  if (!mdlSize)
    return -1;
  v6 = 0;
  while (1)
  {
    v8 = &pWork->obj.klass + v6;
    v11 = v8[4];
    v10 = (v8 + 4);
    v9 = v11;
    if (!v11->_1.byval_arg.bits)
      break;
    if (v5 <= ++v6)
      return -1;
  }
  dds3ObjectBaseOffFlag(&v9->_1.name, 1u);
  v15 = *(*(*v10 + 16LL) + 128LL);
  cmpSetupObject(v15, 1);
  *(*v10 + 40LL) = 1;
  return v6;
}

// 0x1537900
void mymdlAlphaSet(tagpipeBasic *pWork, u8 alpha) {
  dds3ModelHandle_t_o **p_model;
  u32 Color;

  p_model = &pWork->model;
  Color = mdlGetColor(p_model);
  mdlSetColor(p_model, Color & 0xFFFFFF | (alpha << 24), 0);
}

// 0x15378f0
void mymdlColorSet(tagpipeBasic *pWork, u32 color) {
  ;
}

// 0x15372b0
void mymdlDelObject(tagpipeBasic *pWork) {
  UnityEngine_GameObject_o *gameObject;

  pWork->enabled = 0;
  dds3ObjectBaseOnFlag(&pWork->basic, 1u, 0);
  gameObject = pWork->basic->gameObject;
  cmpSetupObject(gameObject, 0);
}

// 0x15342a0
void mymdlDelete(tagpipeBasic **pWork, s16 mNum) {
  tagpipeBasic_o **m_Items;
  s64 v6;
  s64 v7;
  tagpipeBasic_o *v9;
  dds3Basic_t_o **p_basic;
  UnityEngine_Object_o *gameObject;

  if (mNum >= 1)
  {
    m_Items = pWork->m_Items;
    v6 = 0;
    v7 = mNum;
    do
    {
      v9 = m_Items[v6];
      if (v9->basic)
      {
        p_basic = &v9->basic;
        dds3DeleteUnitObjectBasic(p_basic);
        gameObject = m_Items[v6]->basic->gameObject;
        Destroy_27360000(gameObject);
        m_Items[v6]->basic->gameObject = 0;
        m_Items[v6]->basic = 0;
      }
      ++v6;
    }
    while (v7 != v6);
  }
}

// 0x1537990
void mymdlInit(tagpipeBasic **pWork, f32 sclx, f32 scly, f32 sclz, f32 sclw, u16 mdlSize) {
}

// 0x1537340
void mymdlInitObject(tagpipeBasic **pWork, u16 mdlSize) {
  s32 v3;
  s16 v5;
  s16 v6;
  tagpipeBasic_o *v8;
  UnityEngine_GameObject_o *gameObject;

  v3 = mdlSize;
  if (mdlSize)
  {
    v5 = 0;
    do
    {
      v6 = v5;
      v8 = pWork->m_Items[v5];
      v8->enabled = 0;
      dds3ObjectBaseOnFlag(&v8->basic, 1u, 0);
      gameObject = v8->basic->gameObject;
      cmpSetupObject(gameObject, 0);
      v5 = v6 + 1;
    }
    while (v3 > (v6 + 1));
  }
}

// 0x1537430
void mymdlPosSet(tagpipeBasic *pWork, f32 x, f32 y, f32 z) {
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SetMdlPosition(0);
}

// 0x1537660
void mymdlRotSet(tagpipeBasic *pWork, f32 x, f32 y, f32 z) {
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    SetMdlRotation(0);
}

// 0x1537760
void mymdlSclSet(tagpipeBasic *pWork, f32 scl) {
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
}

// 0x1537e50
void mymdlSetMotion(tagpipeBasic *pWork, f32 motion) {
  dds3ModelHandle_t_o **p_model;

  p_model = &pWork->model;
  mdlGetMotionCtrlr(p_model, 0);
}

// 0x1537ca0
void mymdlVisible(tagpipeBasic *pWork, s8 value) {
  tagpipeBasic_Fields *p_fields;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v8;
  bool v9;
  UnityEngine_GameObject_o *v11;

  p_fields = &pWork->fields;
  if (value == 1)
  {
    dds3ObjectBaseOffFlag(&p_fields->basic, 1u);
    gameObject = p_fields->basic->gameObject;
    v8 = gameObject;
    v9 = 1;
  }
  else
  {
    dds3ObjectBaseOnFlag(&p_fields->basic, 1u, 0);
    v11 = p_fields->basic->gameObject;
    v8 = v11;
    v9 = 0;
  }
  cmpSetupObject(v8, v9);
}

// 0x1537d80
void mymdlVisibleAll(tagpipeBasic **pWork, s16 mdlSize, s8 value) {
  s64 v6;
  s64 v7;
  tagpipeBasic_o **m_Items;
  tagpipeBasic_o *v9;

  if (mdlSize >= 1)
  {
    v6 = 0;
    v7 = mdlSize;
    m_Items = pWork->m_Items;
    do
    {
      while (1)
      {
        v9 = m_Items[v6];
        if (v9->enabled == 1)
          break;
        if (v7 == ++v6)
          return;
      }
      mymdlVisible(v9, value, value);
      ++v6;
    }
    while (v7 != v6);
  }
}
