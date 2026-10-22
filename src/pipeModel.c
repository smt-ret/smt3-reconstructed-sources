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
  u32 v14;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  u32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  tagpipeBasic_Fields *p_fields;
  dds3Basic_t_o *ControlScene;
  dds3Basic_t_o *basic;
  Il2CppObject *ModelHandle;
  s32 v31;
  s32 v32;
  f32 v34;
  f32 v35;
  f32 v36;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v39;
  s64 *v40;
  UnityEngine_GameObject_o *gameObject;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  u64 v50[3];
  f32 v51;
  f32 v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;

  v51 = frm1;
  v52 = frm2;
  v14 = dds3SerializeID();
  x = pModel->pos.x;
  y = pModel->pos.y;
  z = pModel->pos.z;
  w = pModel->pos.w;
  v20 = v14;
  v22 = pModel->rot.x;
  v21 = pModel->rot.y;
  v24 = pModel->rot.z;
  v23 = pModel->rot.w;
  v53.x = x;
  v53.y = y;
  v53.z = z;
  v53.w = w;
  v55.x = v22;
  v55.y = v21;
  v55.z = v24;
  v55.w = v23;
  pModel->basic = dds3AddUnitObjectBasic(v20, v53, v55);
  p_fields = &pModel->fields;
  ControlScene = dds3GetControlScene();
  basic = p_fields->basic;
  dds3SetActiveUnitSceneBasic(ControlScene, basic);
  dds3ObjectBaseMakeUnit(&pModel->basic, mNum, mPtn);
  ModelHandle = dds3ObjectBaseGetModelHandle(&pModel->basic);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v50);
      if ((v50[0] & 1) != 0)
        v39 = v50[2];
      else
        v39 = v50 + 1;
      v40 = sub_8C4940(v39);
    }
  }
  pModel->model = ModelHandle;
  LoadModel(pModel, v31, mPtn, v32, v34, v35, v36, name);
  if (motion != -1)
  {
    mdlSetMotionSpeed(&pModel->model, speed, 0);
    mdlSmoothLoopMotion(&pModel->model, 0, motion, v51, v52);
    dds3SetRadiusPoseSet(&pModel->basic, 60.0);
    dds3ObjectBaseOffFlag(&pModel->basic, 0x400u);
    if (!pModel->enabled)
    {
      dds3ObjectBaseOnFlag(&pModel->basic, 1u, 0);
      gameObject = p_fields->basic->gameObject;
      cmpSetupObject(gameObject, 0);
    }
  }
  v45 = pModel->scl.x;
  v46 = pModel->scl.y;
  v47 = pModel->scl.z;
  v48 = pModel->scl.w;
  v54.x = v45;
  v54.y = v46;
  v54.z = v47;
  v54.w = v48;
  dds3SetSclPoseSet(&pModel->basic, v54);
  dds3SetRotPoseSet(&pModel->basic, pModel->rot);
}

// 0x1536910
void LoadModel(tagpipeBasic *pModel, s32 mNum, s32 mPtn, s32 motion, f32 frm1, f32 frm2, f32 speed, char *name) {
  UnityEngine_Object_o *gameObject;
  AssetBundleCtrl_o *v16;
  System_String_o *v17;
  System_String_o *v18;
  s64 *v19;
  Il2CppObject *Prefab_16624656;
  s32 v21;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v24;
  System_String_o *v25;
  s64 *v26;
  dds3UnitObjectBasicWorkData_t_c *v27;
  struct dds3Basic_t_o *basic;
  UnityEngine_GameObject_o *v29;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v32;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *v34;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v38;
  struct dds3Basic_t_o *v39;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  AssetBundleCtrl_o *v43;
  Il2CppObject *v44;
  UnityEngine_Transform_o *v46;
  char *v47;
  s64 *v48;
  tagpipeBasic_o *v49;
  u64 v50[3];

  v49 = pModel;
  FldDispOn(kernelObject);
  gameObject = pModel->basic->gameObject;
  if (!op_Inequality(gameObject, 0, 0))
  {
    if (mPtn <= 21)
    {
      v21 = 0;
      Prefab_16624656 = 0;
      switch (mPtn)
      {
        case 0:
        case 16:
          asset_bc = get_asset_bc();
          v24 = "pipe_common";
          v25 = "charactor/e/player_tatoo";
          v26 = &"plyer_tatoo_pipe";
          break;
        case 8:
          v16 = get_asset_bc();
          v17 = "pipe_common";
          v18 = "charactor/e/pipedata";
          v19 = &"pipe1";
          goto LABEL_16;
        case 9:
          v16 = get_asset_bc();
          v17 = "pipe_common";
          v18 = "charactor/e/pipedata";
          v19 = &"pipe2";
          goto LABEL_16;
        case 10:
          v16 = get_asset_bc();
          v17 = "pipe_common";
          v18 = "charactor/e/pipedata";
          v19 = &"pipe3";
          goto LABEL_16;
        case 11:
          v16 = get_asset_bc();
          v17 = "pipe_common";
          v18 = "charactor/e/pipedata";
          v19 = &"pipe_blood1";
          goto LABEL_16;
        case 12:
          v16 = get_asset_bc();
          v17 = "pipe_common";
          v18 = "charactor/e/pipedata";
          v19 = &"pipe_blood2";
          goto LABEL_16;
        case 13:
          asset_bc = get_asset_bc();
          v24 = "pipe_common";
          v25 = "charactor/e/pipedata";
          v26 = &"pipe_maka1";
          break;
        case 14:
          v16 = get_asset_bc();
          v17 = "pipe_common";
          v18 = "charactor/e/pipedata";
          v19 = &"pipe_maka2";
          goto LABEL_16;
        case 15:
          v16 = get_asset_bc();
          v17 = "pipe_common";
          v18 = "charactor/e/pipedata";
          v19 = &"pipe_jewel1";
          goto LABEL_16;
        case 21:
          v16 = get_asset_bc();
          v17 = "pipe_common";
          v18 = "charactor/e/pipedata";
          v19 = &"makka_lost";
          goto LABEL_16;
        default:
          goto LABEL_24;
      }
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, v24, v25, *v26);
      v21 = 0;
        goto LABEL_60;
    }
    else if (mPtn == 33)
    {
      v16 = get_asset_bc();
      v17 = "pipe_common";
      v18 = "charactor/e/pipedata";
      v19 = &"jewel_lost";
LABEL_16:
      Prefab_16624656 = LoadPrefab_16624656(v16, v17, v18, *v19);
      v21 = 1;
        goto LABEL_60;
    }
    else
    {
      Prefab_16624656 = 0;
      v21 = 0;
LABEL_24:
        goto LABEL_60;
    }
LABEL_60:
    if (op_Inequality(Prefab_16624656, 0, 0))
    {
      basic = pModel->basic;
      v29 = Find("Character", 0);
      transform = get_transform(v29, 0);
      basic->gameObject = Instantiate_object__425664(Prefab_16624656, transform, 0);
      if (op_Inequality(name, "", 0))
        set_name(pModel->basic->gameObject, name);
      switch (mPtn)
      {
        case 0:
        case 16:
          v32 = get_transform(pModel->basic->gameObject, 0);
          Child = GetChild(v32, 0);
          v34 = get_gameObject(Child);
          Component_object = GetComponent_object_(v34);
          basicMyAnm = Component_object;
          v38 = get_gameObject(basicMyAnm);
          basicMyChk = AddComponent_object_(v38);
          if (mPtn == 14)
            goto LABEL_79;
          if (mPtn != 15)
            goto LABEL_75;
          goto LABEL_72;
        case 14:
LABEL_79:
          v43 = get_asset_bc();
          v44 = LoadPrefab_16624656(v43, "pipe_common", "charactor/e/pipedata", "zmakka_effect");
          v46 = get_transform(pModel->basic->gameObject, 0);
          Instantiate_object__425664(v44, v46, 0);
          if (!v21)
            break;
          goto LABEL_76;
        case 15:
        case 33:
LABEL_72:
          pModel->model->modelRoot->modelobj = pModel->basic->gameObject;
          pModel->model->modelRoot->effpos_type = 1;
          v39 = pModel->basic;
          workdata = v39->workdata;
          klass = workdata->klass;
          if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
          {
            sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v50);
            if ((v50[0] & 1) != 0)
              v47 = v50[2];
            else
              v47 = v50 + 1;
            v48 = sub_8C4940(v47);
          }
          workdata[2].klass->vtable[1].method = v39->gameObject;
          goto LABEL_75;
        default:
LABEL_75:
          if (v21)
LABEL_76:
            AddComponent_object_(pModel->basic->gameObject);
          break;
      }
    }
    SetMdlRotation(&v49, v27);
  }
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
  UnityEngine_Object_o *gameObject;
  UnityEngine_Transform_o *transform;
  struct dds3PoseSet_t_o *poseset;
  f32 x;
  f32 y;
  UnityEngine_Transform_o *v8;
  f32 z;
  f32 w;
  UnityEngine_Quaternion_o v11;

  gameObject = (*pWork)->basic->gameObject;
  if (op_Inequality(gameObject, 0, 0))
  {
    transform = get_transform((*pWork)->basic->gameObject, 0);
    poseset = (*pWork)->basic->poseset;
    x = poseset->rot.x;
    y = poseset->rot.y;
    v8 = transform;
    z = poseset->rot.z;
    w = poseset->rot.w;
    *&v11.x = 0;
    *&v11.z = 0;
    sub_1A1BDD0(&v11.x, x, y, z, w);
    set_localRotation(v8, v11);
  }
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
  tagpipeBasic_o **m_Items;
  s64 v10;
  s64 v11;
  Il2CppObject *v13;
  u64 *v14;

  if (mdlSize)
  {
    m_Items = pWork->m_Items;
    v10 = 0;
    v11 = mdlSize;
    do
    {
      v13 = Allocate(tagpipeBasic);
      v14 = Allocate(dds3ModelHandle_t);
      dds3ModelHandle_t___ctor(v14);
      v13[1].monitor = v14;
      v13[2].klass = NewSpecific(sbyte, 3u);
      _ctor(v13, 0);
      m_Items[v10] = v13;
      sub_854930(&v13[2].monitor + 4, 3u);
      sub_854930(&m_Items[v10]->scl, 0);
      sub_854930(&m_Items[v10]->scl, 1u);
      sub_854930(&m_Items[v10]->scl, 2u);
      sub_854930(&m_Items[v10++]->scl, 3u);
    }
    while (v11 != v10);
  }
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
  f32 v7;
  f32 v8;
  f32 w;
  f32 v10;
  tagpipeBasic_o *pWorka;
  UnityEngine_Vector4_o v13;

  pWorka = pWork;
  sub_854930(&pWork->pos, 0);
  sub_854930(&pWork->pos, 1u);
  sub_854930(&pWork->pos, 2u);
  v7 = pWork->pos.x;
  v8 = pWork->pos.y;
  v10 = pWork->pos.z;
  w = pWork->pos.w;
  v13.x = v7;
  v13.y = v8;
  v13.z = v10;
  v13.w = w;
  dds3SetPosPoseSet(&pWork->basic, v13);
  SetMdlPosition(&pWorka);
}

// 0x1537660
void mymdlRotSet(tagpipeBasic *pWork, f32 x, f32 y, f32 z) {
  f32 v7;
  f32 v8;
  f32 w;
  f32 v10;
  tagpipeBasic_o *pWorka;
  UnityEngine_Vector4_o v13;

  pWorka = pWork;
  sub_854930(&pWork->rot, 0);
  sub_854930(&pWork->rot, 1u);
  sub_854930(&pWork->rot, 2u);
  v7 = pWork->rot.x;
  v8 = pWork->rot.y;
  v10 = pWork->rot.z;
  w = pWork->rot.w;
  v13.x = v7;
  v13.y = v8;
  v13.z = v10;
  v13.w = w;
  dds3SetRotPoseSet(&pWork->basic, v13);
  SetMdlRotation(&pWorka);
}

// 0x1537760
void mymdlSclSet(tagpipeBasic *pWork, f32 scl) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  UnityEngine_Object_o *gameObject;
  UnityEngine_Transform_o *transform;
  f32 v13;
  f32 v14;
  UnityEngine_Transform_o *v15;
  f32 v16;
  f32 v17;
  UnityEngine_Vector3_o v18;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;

  sub_854930(&pWork->scl, 0);
  sub_854930(&pWork->scl, 1u);
  sub_854930(&pWork->scl, 2u);
  x = pWork->scl.x;
  y = pWork->scl.y;
  z = pWork->scl.z;
  w = pWork->scl.w;
  v19.x = x;
  v19.y = y;
  v19.z = z;
  v19.w = w;
  dds3SetSclPoseSet(&pWork->basic, v19);
  gameObject = pWork->basic->gameObject;
  if (op_Inequality(gameObject, 0, 0))
  {
    transform = get_transform(pWork->basic->gameObject, 0);
    v13 = pWork->scl.x;
    v14 = pWork->scl.y;
    v15 = transform;
    v17 = pWork->scl.z;
    v16 = pWork->scl.w;
    v20.x = v13;
    v20.y = v14;
    v20.z = v17;
    v20.w = v16;
    v18 = op_Implicit_8738992(v20);
    set_localScale(v15, v18);
  }
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
