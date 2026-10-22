#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct ModelViewer_MODELVIEW_MODE ModelViewer_MODELVIEW_MODE;
typedef struct ModelViewer_ModelViewerDebugProcTable_t ModelViewer_ModelViewerDebugProcTable_t;
typedef struct ModelViewer_ModelViewerDebugProcTable_t_procDelegate ModelViewer_ModelViewerDebugProcTable_t_procDelegate;
typedef struct ModelViewer_ModelViewerModeProcTable_t ModelViewer_ModelViewerModeProcTable_t;
typedef struct ModelViewer_modelViewerWork_t ModelViewer_modelViewerWork_t;
typedef struct bDrawText bDrawText;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;

struct ModelViewer_modelViewerWork_t {
    dds3ProcessID_t *procId;
    dds3ProcessID_t *modeProcId;
    s32 exitFlag;
    s32 cursorTimer;
    s32 mode;
    s32 modeBack;
    s32 motionPause;
    s32 motionSeek;
    s32 drawMarkFlag;
    s32 hexModeFlag;
    s32 hideConsFlag;
    s32 padChar;
    s32 padShort;
    s32 modeSelCursor;
    s32 modelCount;
    s32 modelMajor;
    s32 modelMinor;
    s32 modelMajorWrk;
    s32 modelMinorWrk;
    s32 modelCursor;
    s32 motion;
    s32 motionWrk;
    s32 motionGroup;
    s32 motionWrk2[3];
    s32 smoothFrame;
    s32 beforeFrame;
    s32 motionCursor;
    s32 cameraMode;
    s32 objectMode;
    s32 arrangeCursor;
    s32 textureNum;
    s32 optionCursor;
    s32 optionMode;
    s32 effectMode;
    s32 effectCursor;
    s32 effectScrlTop;
    s32 effectCursor2;
    f32 motionSpeed;
    sdfVector4_t cameraVectX;
    sdfVector4_t cameraVectY;
    sdfVector4_t cameraVectZ;
    dds3ModelHandle_t *modelHandle[12];
    sdfDrawTag_t *consDrawTag;
    char *akey;
    s32 read_flag;
    s32 read_minor;
    void *modelobj;
    sdfVector3_t modelrot;
    void *modelanm;
};

struct ModelViewer_ModelViewerModeProcTable_t {
    char *name;
    void *proc;
    void *parm;
};

struct ModelViewer_MODELVIEW_MODE {
    s32 value__;
};

struct ModelViewer_ModelViewerDebugProcTable_t {
    char *name;
    ModelViewer_ModelViewerDebugProcTable_t_procDelegate *proc;
};

static char *modelViewerModeStr[13];
static ModelViewer_modelViewerWork_t *modelViewerWork;
static sdfVector4_t modelViewerEyeDefault;
static sdfVector4_t modelViewerTargetDefault;
static sdfVector4_t modelViewerUpDefault;
static sdfVector4_t modelViewerEyePos;
static sdfVector4_t modelViewerTargetPos;
static sdfVector4_t modelViewerUpVector;
static ModelViewer_ModelViewerModeProcTable_t *ModelViewerModeProcTable[12];
static s32 CX__;
static s32 CY__;
static s32 Z__;
static bDrawText bsetText;
static char *ModelViewerSetCameraSubModeCons_camera_mode_str[2];
static char *ModelViewerSetObjectSubModeCons_object_mode_str[2];
static char *ModelViewerSetArrangeCons_strs[5];
static s32 *ModelViewerSetOptionCons_cursor_y_tbl;
static char *ModelViewerSetOptionCons_msgs[3];
static sdfVector4_t ModelViewerSetCenterAxis_line_points[6];
static u32 ModelViewerSetCenterAxis_line_colors[6];
static sdfVector4_t ModelViewerSetObjectCenter_line_points[4];
static u32 ModelViewerSetObjectCenter_line_colors[4];
static s32 ModelViewerSetObjectCenter_f;
static s32 ModelViewerProc_c;
static s32 ModelViewerProc_sw;
static sdfVector4_t ModelViewerDrawMarkPos_line_points[6];
static u32 ModelViewerDrawMarkPos_line_colors[6];

bool DDS3_PAD2CHECK_TRIG(s32 id);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void FromRotation_B(f32 aAngle);
char *GetFname(s32 no);
bool IsLoad(AssetBundles *this, char *key);
void KillModelViewer(void);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void ModelViewerArrange(void);
void ModelViewerCamera(void);
void ModelViewerEffect(void);
void ModelViewerHandleBackRotate(void);
void ModelViewerHandleRotate(void);
void ModelViewerInitCamera(void);
void ModelViewerLoadModel(void);
void ModelViewerModel(void);
void ModelViewerMotion(void);
s32 ModelViewerMoveCursorLR(s32 *aCursorPtr, s32 aMax);
s32 ModelViewerMoveCursorUD(s32 *aCursorPtr, s32 aMax, s32 aLarge);
void ModelViewerObject(void);
void ModelViewerOption(void);
void ModelViewerSetModeCons(void);
void ModelViewerSetModelSelCons(void);
void ModelViewerStartModeProc(void);
void ModelViewerStopModeProc(void);
void ModelViewerTexture(void);
void Mult(void);
void PreBtlMenuObj(s32 idx);
f32 SDF_DEGtoRAD(f32 n);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX_XYZ1(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_MTXCOL_B(sdfMatrix4_t *p);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetBtlMenuObj(s32 idx);
void ToMatrix(void);
void UnloadAB(AssetBundleCtrl *this, char *key);
void ViewerDispOn(dds3DefaultMain *this);
bDrawText btlDevPrintf(s32 aX, s32 aY, s32 aZ, s32 color, char *aStr, s32 f);
void btlDrawTagLink(bDrawText *setText, bDrawText dt, s32 idx);
void dds3AdminiExitSequence(void);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void initBtlMenuObj(s32 x, s32 y, s32 w, s32 h, s32 idx);
s32 mdlGetNumOfMajor(void);
s32 mdlGetNumOfMinor(s32 aMajor);
char *nbLoadStartUnitPack(s32 unitid);

// 0x12a7f00
void InitModelViewer(void) {
  Il2CppObject *v2;
  u32 *gc_desc;
  u32 *v8;
  struct sdf3DScreenParam_t_o *dds3ScreenParam;
  struct sdf3DLight_t_array *dds3DirLights;
  sdf3DLight_t_o *v15;
  s64 v16;
  f32 v17;
  f32 v18;
  struct dds3ModelHandle_t_array *modelHandle;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  u64 *v25;
  u64 *v27;
  dds3ProcessID_t_o *started;
  s64 v29;
  s64 v30;

  v29 = 0;
  v30 = 0;
  else if (modelViewerWork)
  {
    goto LABEL_13;
  }
  v2 = Allocate(ModelViewer_modelViewerWork_t);
  v2[7].monitor = NewSpecific(s32, 3u);
  v2[14].monitor = NewSpecific(dds3ModelHandle_t, 0xCu);
  _ctor(v2, 0);
  modelViewerWork = v2;
LABEL_13:
  ViewerDispOn(kernelObject);
  *(v6[2].klass->_1.gc_desc + 10) = 1;
  *(v6[2].klass->_1.gc_desc + 11) = 1;
  gc_desc = v6[2].klass->_1.gc_desc;
  gc_desc[21] = 1;
  gc_desc[23] = 1;
  v8 = v6[2].klass->_1.gc_desc;
  v8[22] = 0;
  v8[24] = 0;
  *(v6[2].klass->_1.gc_desc + 8) = 0;
  *(v6[2].klass->_1.gc_desc + 9) = 0;
  *(v6[2].klass->_1.gc_desc + 25) = 0;
  *(v6[2].klass->_1.gc_desc + 32) = 0;
  *(v6[2].klass->_1.gc_desc + 33) = 0;
  *(v6[2].klass->_1.gc_desc + 36) = 0;
  *(v6[2].klass->_1.gc_desc + 37) = 0;
  *(v6[2].klass->_1.gc_desc + 12) = 0;
  *(v6[2].klass->_1.gc_desc + 45) = 1065353216;
  *(v6[2].klass->_1.gc_desc + 14) = 0;
  *(v6[2].klass->_1.gc_desc + 15) = 1;
  ModelViewerInitCamera();
  dds3ScreenParam->fovy = SDF_DEGtoRAD(25.0);
  sub_854690(&v29, 0.9811, 0.3967, 0.3606, 0.0);
  v15 = dds3DirLights->m_Items[0];
  v16 = 4;
  v18 = *&v30;
  v17 = *(&v30 + 1);
  *&v15->v.x = v29;
  v15->v.z = v18;
  v15->v.w = v17;
  do
  {
    modelHandle = modelViewerWork->modelHandle;
    *(&modelHandle->obj.klass + v16++) = 0;
  }
  while (v16 != 16);
  ModelViewerLoadModel();
  modelViewerWork->modelCount = 1;
  v25 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v25,
    0,
    Method_ModelViewer_ModelViewerProc__);
  modelViewerWork->procId = dds3StartProcess(
                                     "modelViewer",
                                     0x2AFFu,
                                     1,
                                     0,
                                     v25,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0);
  v27 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v27,
    0,
    Method_ModelViewer_ModelViewerDrawEndProc__);
  started = dds3StartProcess("modelViewerEnd", 0x2B01u, 1, 0, v27, 0, 0, 0, 0, 0);
  modelViewerWork->modeProcId = 0;
  ModelViewerStartModeProc(started);
}

// 0x12a2c70
void KillModelViewer(void) {
  dds3KillProcessName("modelViewer", 0);
  dds3KillProcessName("modelViewerEnd", 0);
}

// 0x12a6120
void LinkPanelPacket(s32 aX, s32 aY, u32 aZ, s32 aW, s32 aH, s32 aFlag) {
  ;
}

// 0x12a6110
void *MakePanelPacket(s32 aX, s32 aY, u32 aZ, s32 aW, s32 aH, s32 aFlag) {
  return 0;
}

// 0x12a5110
void ModelViewerArrange(void) {
  u64 v6;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  s32 modelCount;
  struct dds3ModelHandle_t_array *modelHandle;
  struct dds3ModelHandle_t_array *v12;
  u64 v14;
  s64 v15;
  struct dds3ModelHandle_t_array *v16;
  struct ModelViewer_modelViewerWork_t_o *v21;
  struct ModelViewer_modelViewerWork_t_o *v23;

  if (!ModelViewerMoveCursorUD(&modelViewerWork->arrangeCursor, 5, 1))
  {
    if (DDS3_PADCHECK_TRIG(1))
    {
      modelViewerWork = *(*(v6 + 184) + 8LL);
      switch (modelViewerWork->arrangeCursor)
      {
        case 0:
          modelCount = modelViewerWork->modelCount;
          if (modelCount != 12)
          {
            if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
            {
              modelCount = modelViewerWork->modelCount;
            }
            modelHandle = modelViewerWork->modelHandle;
            modelHandle->m_Items[modelCount] = 0;
            ++modelViewerWork->modelCount;
            ModelViewerHandleRotate(v6);
            ModelViewerLoadModel();
          }
          goto LABEL_72;
        case 1:
          if (modelViewerWork->modelCount >= 2)
          {
            v12 = modelViewerWork->modelHandle;
            v12->m_Items[0] = 0;
            ModelViewerHandleBackRotate(v6);
            --modelViewerWork->modelCount;
          }
          goto LABEL_72;
        case 2:
          if (modelViewerWork->modelCount >= 2)
          {
            ModelViewerHandleRotate(v6);
          }
          goto LABEL_72;
        case 3:
          if (modelViewerWork->modelCount >= 2)
          {
            ModelViewerHandleBackRotate(v6);
          }
          goto LABEL_72;
        case 4:
          v14 = 0;
          if ((*(v6 + 295) & 2) != 0)
            goto LABEL_54;
          break;
        default:
          goto LABEL_72;
      }
      while (1)
      {
        v15 = *(*(v6 + 184) + 8LL);
        if (v14 >= *(v15 + 80))
          break;
        if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
        {
          v16 = modelViewerWork->modelHandle;
          if (v14 >= LODWORD(v16->max_length))
          {
LABEL_60:
          }
        }
        else
        {
          v16 = *(v15 + 232);
          if (v14 >= LODWORD(v16->max_length))
            goto LABEL_60;
        }
        ++v14;
        {
LABEL_54:
        }
      }
LABEL_72:
      v21 = modelViewerWork;
      v21->modelMajor = 0;
      v21->modelMajorWrk = 0;
      v23 = modelViewerWork;
      v23->modelMinor = 0;
      v23->modelMinorWrk = 0;
      *&modelViewerWork->motion = 0;
    }
  }
}

// 0x12a50a0
void *ModelViewerArrangeProc(dds3ProcessID_t *aProcId) {
  ModelViewerArrange();
  return 0;
}

// 0x12a3840
void ModelViewerCamera(void) {
  if (!DDS3_PADCHECK_TRIG(12))
    goto LABEL_11;
LABEL_6:
  ModelViewerInitCamera();
}

// 0x12a37d0
void *ModelViewerCameraProc(dds3ProcessID_t *aProcId) {
  ModelViewerCamera();
  return 0;
}

// 0x12a7b00
void *ModelViewerDrawEndProc(dds3ProcessID_t *aProcId) {
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  AssetBundleCtrl_o *asset_bc;
  s32 read_minor;
  System_String_o *Fname;
  AssetBundleCtrl_o *v12;
  System_String_o *akey;
  AssetBundleCtrl_o *v14;
  System_String_o *v15;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v19;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v23;
  UnityEngine_Transform_o *v25;
  UnityEngine_Transform_o *Child;
  struct ModelViewer_modelViewerWork_t_o *v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  struct ModelViewer_modelViewerWork_t_o *v37;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Quaternion_o v40;

  *&rotation.x = 0;
  *&rotation.z = 0;
  if (modelViewerWork->read_flag)
  {
    else if (modelViewerWork->modelMajor != 1)
    {
      return 0;
    }
    asset_bc = get_asset_bc();
    if (IsLoad(asset_bc, modelViewerWork->akey))
    {
      read_minor = modelViewerWork->read_minor;
      Fname = GetFname(read_minor);
      v12 = get_asset_bc();
      akey = modelViewerWork->akey;
      v14 = v12;
      v15 = Concat_5224608("charactor/b/", Fname);
      Prefab_16624656 = LoadPrefab_16624656(v14, akey, v15, Fname);
      if (op_Inequality(Prefab_16624656, 0, 0))
      {
        v19 = Find("Character", 0);
        transform = get_transform(v19, 0);
        v23 = Instantiate_object__425664(Prefab_16624656, transform, 0);
        modelViewerWork->modelobj = v23;
        v25 = get_transform(v23, 0);
        Child = GetChild(v25, 0);
        rotation = get_rotation(Child);
        sub_1A1CAE0(&rotation.x, 0);
        v28 = modelViewerWork;
        v28->modelrot.x = v29;
        v28->modelrot.y = 180.0;
        v28->modelrot.z = v30;
        v31 = v29;
        v32 = v30;
        {
        }
        v40 = Euler(v31, 180.0, v32);
        set_rotation(Child, v40);
        gameObject = get_gameObject(Child);
        Component_object = GetComponent_object_(gameObject);
        modelViewerWork->modelanm = Component_object;
        modelViewerWork->read_flag = 0;
      }
      else
      {
        v37 = modelViewerWork;
        v37->akey = nbLoadStartUnitPack(61);
        modelViewerWork->read_minor = 61;
      }
    }
  }
  return 0;
}

// 0x12a7af0
void ModelViewerDrawMarkPos(dds3ModelHandle_t *handle) {
  ;
}

// 0x12a5b00
void ModelViewerEffect(void) {
  s32 effectMode;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  s32 effectCursor;
  s16 v20;
  s32 v21;
  struct ModelViewer_modelViewerWork_t_o *v22;
  s32 v23;
  struct ModelViewer_modelViewerWork_t_o *v26;
  s32 v27;

  effectMode = modelViewerWork->effectMode;
  if (effectMode == 1)
  {
    DDS3_PADCHECK_TRIG(3);
    modelViewerWork->effectMode = 0;
  }
  else
  {
    if (effectMode)
      return;
 if (DDS3_PADCHECK_TRIG(7))
    {
      goto LABEL_21;
    }
    else if (DDS3_PADCHECK_REP(7))
    {
      goto LABEL_51;
    }
    if (DDS3_PADCHECK_TRIG(6))
    {
      if ((v20 & 0x200) != 0)
      {
        v21 = v20 & 0x200;
        v22 = modelViewerWork;
        v23 = v22->effectCursor;
        if (!v23)
          goto LABEL_100;
      }
      else
      {
        v21 = 0;
        v22 = modelViewerWork;
        v23 = v22->effectCursor;
        if (!v23)
        {
LABEL_100:
          v22->effectCursor = -1;
          return;
        }
      }
      v22->effectCursor = v23 - 1;
    }
    else
    {
      if (DDS3_PADCHECK_REP(6))
      {
        v26 = modelViewerWork;
        v27 = v26->effectCursor;
        if (v27 >= 1)
        {
          v26->effectCursor = v27 - 1;
        }
      }
      else
      {
      }
    }
  }
}

// 0x12a6f40
s32 ModelViewerEffectGetCount(void) {
  return 0;
}

// 0x12a6fe0
void *ModelViewerEffectGetItem(void) {
  return 0;
}

// 0x12a5a90
void *ModelViewerEffectProc(dds3ProcessID_t *aProcId) {
  ModelViewerEffect();
  return 0;
}

// 0x12a6030
void *ModelViewerExitProc(dds3ProcessID_t *aProcId) {
  u64 v2;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;

  else
  {
    if (modelViewerWork->exitFlag)
      return 0;
  }
  modelViewerWork->exitFlag = 1;
  KillModelViewer(v2);
  dds3AdminiExitSequence();
  return 0;
}

// 0x12a6a50
void ModelViewerHandleBackRotate(void) {
  ModelViewer_c *v2;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  struct dds3ModelHandle_t_array *modelHandle;
  s64 *v6;
  s32 v7;
  u32 v8;
  u64 v9;
  s32 v10;
  s64 v11;
  u32 *v13;
  u64 v14;
  u32 *v16;
  s64 v17;
  u32 v19;
  struct dds3ModelHandle_t_array *v20;

  modelHandle = modelViewerWork->modelHandle;
  v6 = modelHandle->m_Items[0];
  v7 = modelViewerWork->modelCount - 1;
  v8 = *&v2->_2.bitflags1;
  if (v7 < 1)
  {
    LODWORD(v14) = 0;
    if ((v8 & 0x200) == 0)
      goto LABEL_26;
  }
  else
  {
    v9 = 0;
    v10 = (v8 >> 9) & 1;
    v11 = v7;
    do
    {
      v13 = modelViewerWork->modelHandle;
      v14 = v9 + 1;
      v16 = &v13[2 * v9];
      v17 = *(v16 + 5);
      *(v16 + 4) = v17;
      v10 = (v19 >> 9) & 1;
      ++v9;
    }
    while (v11 != v14);
    if ((v19 & 0x200) == 0)
      goto LABEL_26;
  }
LABEL_26:
  v20 = modelViewerWork->modelHandle;
  if (!v6)
    goto LABEL_28;
LABEL_27:
LABEL_28:
  v20->m_Items[v14] = v6;
}

// 0x12a6850
void ModelViewerHandleRotate(void) {
  ModelViewer_c *v2;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  struct dds3ModelHandle_t_array *modelHandle;
  s64 modelCount;
  s64 *v7;
  s32 v8;
  struct dds3ModelHandle_t_array *v9;
  u32 *v12;
  u32 *v14;
  s64 v15;
  s64 v16;

  modelHandle = modelViewerWork->modelHandle;
  modelCount = modelViewerWork->modelCount;
  v7 = modelHandle->m_Items[modelCount - 1];
  v8 = (v2->_2.bitflags2 >> 1) & 1;
  if (modelCount >= 2)
  {
    do
    {
      v12 = modelViewerWork->modelHandle;
      v14 = &v12[2 * modelCount];
      v15 = modelCount - 1;
      v16 = *(v14 + 2);
      *(v14 + 3) = v16;
      modelCount = v15;
    }
    while (v15 > 1);
  }
  else
  {
    v9 = modelViewerWork->modelHandle;
    if (!v7)
      goto LABEL_27;
  }
LABEL_27:
  v9->m_Items[0] = v7;
}

// 0x12a67a0
void ModelViewerInitCamera(void) {
  f32 w;
  f32 v6;
  f32 v8;

  *&modelViewerEyePos.x = *&modelViewerEyeDefault.x;
  w = modelViewerEyeDefault.w;
  modelViewerEyePos.z = modelViewerEyeDefault.z;
  modelViewerEyePos.w = w;
  *&modelViewerTargetPos.x = *&modelViewerTargetDefault.x;
  v6 = modelViewerTargetDefault.w;
  modelViewerTargetPos.z = modelViewerTargetDefault.z;
  modelViewerTargetPos.w = v6;
  *&modelViewerUpVector.x = *&modelViewerUpDefault.x;
  v8 = modelViewerUpDefault.w;
  modelViewerUpVector.z = modelViewerUpDefault.z;
  modelViewerUpVector.w = v8;
  modelViewerWork->cameraMode = 0;
}

// 0x12a7ef0
void ModelViewerLoadConf(void) {
  ;
}

// 0x12a6560
void ModelViewerLoadModel(void) {
  struct dds3ModelHandle_t_array *modelHandle;
  struct System_Int32_array *motionWrk2;
  struct System_Int32_array *v7;
  struct System_Int32_array *v9;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  s32 modelMinor;

  modelHandle = modelViewerWork->modelHandle;
  modelHandle->m_Items[0] = 0;
  modelViewerWork->motion = 0;
  modelViewerWork->motionWrk = 0;
  modelViewerWork->motionGroup = 0;
  motionWrk2 = modelViewerWork->motionWrk2;
  motionWrk2->m_Items[0] = 0;
  v7 = modelViewerWork->motionWrk2;
  v7->m_Items[1] = 0;
  v9 = modelViewerWork->motionWrk2;
  v9->m_Items[2] = 0;
  if (modelViewerWork->modelMajor == 1)
  {
    modelMinor = modelViewerWork->modelMinor;
    modelViewerWork->akey = nbLoadStartUnitPack(modelMinor);
    modelViewerWork->read_minor = modelViewerWork->modelMinor;
    modelViewerWork->read_flag = 1;
  }
  modelViewerWork->textureNum = 0;
}

// 0x12a6da0
void ModelViewerLoopMotion(void) {

}

// 0x12a2da0
void ModelViewerModel(void) {
  s32 v6;
  bool v9;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  s32 v12;
  struct ModelViewer_modelViewerWork_t_o *v14;
  s32 *p_modelMajorWrk;
  s32 NumOfMajor;
  s32 modelMajorWrk;
  s32 NumOfMinor;
  struct ModelViewer_modelViewerWork_t_o *v22;
  s32 v23;
  s32 v24;
  struct ModelViewer_modelViewerWork_t_o *v33;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *modelobj;
  bool v40;
  ModelViewer_c *v41;
  UnityEngine_Object_o *v42;
  struct dds3ModelHandle_t_array *modelHandle;

  if (!ModelViewerMoveCursorLR(&modelViewerWork->modelCursor, 5))
  {
    if (modelViewerWork->hexModeFlag)
      v6 = 16;
    else
      v6 = 10;
    v9 = DDS3_PADCHECK_TRIG(0);
    if (v9)
    {
      v12 = modelViewerWork->motionGroup + 1;
      modelViewerWork->motionGroup = v12;
      if (v12 == 4)
      {
        modelViewerWork->motionGroup = 0;
      }
      modelViewerWork->motionWrk = 0;
    }
    v14 = modelViewerWork;
    switch (v14->modelCursor)
    {
      case 0:
        p_modelMajorWrk = &v14->modelMajorWrk;
        NumOfMajor = mdlGetNumOfMajor();
        if (!ModelViewerMoveCursorUD(p_modelMajorWrk, NumOfMajor, 1))
          goto LABEL_77;
        modelMajorWrk = modelViewerWork->modelMajorWrk;
        NumOfMinor = mdlGetNumOfMinor(modelMajorWrk);
        v22 = modelViewerWork;
        if (v22->modelMinorWrk >= NumOfMinor)
        {
          v22->modelMinorWrk = NumOfMinor - 1;
        }
        return;
      case 1:
        v23 = v14->modelMajorWrk;
        v24 = mdlGetNumOfMinor(v23);
        if (!ModelViewerMoveCursorUD(&modelViewerWork->modelMinorWrk, v24, v6))
          goto LABEL_77;
        return;
      case 2:
          goto LABEL_144;
        goto LABEL_143;
      case 3:
        if (!ModelViewerMoveCursorUD(&v14->smoothFrame, 100, 10))
          goto LABEL_77;
        return;
      case 4:
        if (!ModelViewerMoveCursorUD(&v14->beforeFrame, 100, 10))
          goto LABEL_77;
        return;
      default:
LABEL_77:
        if (DDS3_PADCHECK_TRIG(12))
          return;
        if (modelViewerWork->modelCursor <= 1)
        {
          if (DDS3_PADCHECK_TRIG(1))
          {
            v33 = modelViewerWork;
            if (v33->modelMajor != v33->modelMajorWrk)
              goto LABEL_148;
            if (v33->modelMinor != v33->modelMinorWrk)
            {
LABEL_148:
              asset_bc = get_asset_bc();
              UnloadAB(asset_bc, modelViewerWork->akey);
              modelobj = modelViewerWork->modelobj;
              {
              }
              v40 = op_Inequality(modelobj, 0, 0);
              if (v40)
              {
                v42 = modelViewerWork->modelobj;
                {
                }
                Destroy_27360000(v42);
                modelViewerWork->modelobj = 0;
              }
              modelHandle = modelViewerWork->modelHandle;
              modelHandle->m_Items[0] = 0;
              modelViewerWork->modelMajor = modelViewerWork->modelMajorWrk;
              modelViewerWork->modelMinor = modelViewerWork->modelMinorWrk;
              ModelViewerLoadModel(v41);
            }
          }
          return;
        }
          goto LABEL_142;
LABEL_140:
LABEL_142:
LABEL_143:
        v14 = modelViewerWork;
LABEL_144:
        return;
    }
  }
}

// 0x12a2d30
void *ModelViewerModelProc(dds3ProcessID_t *aProcId) {
  ModelViewerModel();
  ModelViewerSetModelSelCons();
  return 0;
}

// 0x12a4dc0
void ModelViewerMotion(void) {
  f32 v3;
  s32 v4;
  s32 v6;
  s32 v7;
  s32 v9;
  s32 v10;
  bool v12;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  s32 v17;

  v3 = (modelViewerWork->motionSpeed * 100.0) + 0.5;
  v4 = v3;
  if (DDS3_PADCHECK_REP(7))
  {
    v6 = v4 + 100;
    if (v4 + 100 >= 2000)
      v6 = 2000;
    if (v4 <= 499)
      v6 = v4 + 10;
    if (v4 <= 49)
      v7 = v4 + 1;
    else
      v7 = v6;
      goto LABEL_32;
    goto LABEL_18;
  }
  if (DDS3_PADCHECK_REP(6))
  {
    v9 = v4 - 100;
    if (v4 <= 500)
      v9 = v4 - 10;
    v10 = v4 - 1;
    if (v4 - 1 <= 5)
      v10 = 5;
    if (v4 <= 50)
      v7 = v10;
    else
      v7 = v9;
      goto LABEL_32;
LABEL_18:
LABEL_32:
    modelViewerWork->motionSpeed = v7 * 0.01;
  }
  v12 = DDS3_PADCHECK_TRIG(3);
  if (v12)
  {
    modelViewerWork->motionPause ^= 1u;
  }
  modelViewerWork->motionSeek = 0;
  if (modelViewerWork->motionPause)
  {
    else if (DDS3_PADCHECK_PRESS(5))
    {
LABEL_48:
      v17 = 1;
LABEL_61:
      modelViewerWork->motionSeek = v17;
      return;
    }
    if (DDS3_PADCHECK_PRESS(4))
    {
      v17 = -1;
      goto LABEL_61;
    }
  }
}

// 0x12a4d50
void *ModelViewerMotionProc(dds3ProcessID_t *aProcId) {
  ModelViewerMotion();
  return 0;
}

// 0x12a6130
s32 ModelViewerMoveCursorLR(s32 *aCursorPtr, s32 aMax) {
  s32 v5;
  s32 v6;
  s32 v8;
  s32 result;
  bool v12;

  v5 = *aCursorPtr;
  v6 = aMax - 1;
  if (DDS3_PADCHECK_TRIG(5))
  {
    if (v5 < v6)
      v8 = v5 + 1;
    else
      v8 = 0;
LABEL_10:
    *aCursorPtr = v8;
    result = 1;
    modelViewerWork->cursorTimer = 0;
    return result;
  }
  else if (DDS3_PADCHECK_REP(5))
  {
LABEL_18:
    if (v5 >= v6)
      return 0;
    v8 = v5 + 1;
    goto LABEL_10;
  }
  else if (DDS3_PADCHECK_TRIG(4))
  {
    goto LABEL_25;
  }
  v12 = DDS3_PADCHECK_REP(4);
  result = 0;
  v8 = v5 - 1;
  if (v5 >= 1 && v12)
    goto LABEL_10;
  return result;
}

// 0x12a62d0
s32 ModelViewerMoveCursorUD(s32 *aCursorPtr, s32 aMax, s32 aLarge) {
  s32 v7;
  s32 v8;
  s32 result;
  bool v11;

  v7 = *aCursorPtr;
  v8 = aMax - 1;
  if (DDS3_PADCHECK_TRIG(7))
  {
    if (v7 < v8)
      v8 = v7 + 1;
    else
      v8 = 0;
    goto LABEL_55;
  }
  else if (DDS3_PADCHECK_REP(7))
  {
    goto LABEL_13;
  }
  else if (DDS3_PADCHECK_TRIG(6))
  {
    goto LABEL_19;
  }
  if (DDS3_PADCHECK_REP(6))
  {
    v8 = v7 - 1;
    if (v7 >= 1)
      goto LABEL_55;
    return 0;
  }
  if (!aLarge)
    return 0;
  if (DDS3_PADCHECK_TRIG(11))
  {
    if (v7 >= v8)
    {
      v8 = 0;
      goto LABEL_55;
    }
    goto LABEL_40;
  }
  if (DDS3_PADCHECK_REP(11))
  {
    if (v7 >= v8)
      return 0;
LABEL_40:
    if (v7 + aLarge <= v8)
      v8 = v7 + aLarge;
    goto LABEL_55;
  }
  if (DDS3_PADCHECK_TRIG(10))
  {
    if (v7 < 1)
      goto LABEL_55;
    goto LABEL_54;
  }
  v11 = DDS3_PADCHECK_REP(10);
  result = 0;
  if (v7 >= 1 && v11)
  {
LABEL_54:
    v8 = (v7 - aLarge) & ~((v7 - aLarge) >> 31);
    goto LABEL_55;
  }
  return result;
}

// 0x12a42e0
void ModelViewerObject(void) {
  s16 v8;
  s32 v9;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  sdfVu0_c *v13;
  f32 v14;
  f32 v16;
  sdfVu0_c *v20;
  f32 v22;
  sdfVu0_c *v26;
  f32 v27;
  sdfVu0_c *v29;
  sdfVu0_c *v31;
  f32 v32;
  sdfVu0_c *v34;
  sdfVu0_c *v36;
  sdfVu0_c *v38;
  struct dds3KernelDraw_StaticFields *static_fields;
  s64 v44;
  s64 v45;
  s64 v46;
  s64 v47;
  s64 v48;
  s64 v49;
  s64 v50;
  s64 v56;
  s64 v57;
  s64 v58;
  s64 v59;
  s64 v60;
  s64 v61;
  s64 v62;
  s64 v68;
  s64 v69;
  s64 v70;
  s64 v71;
  s64 v72;
  s64 v73;
  s64 v74;
  UnityEngine_Matrix4x4_o v77;
  UnityEngine_Matrix4x4_o v78;
  UnityEngine_Matrix4x4_o v79;
  u64 dest[8];
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o v82;
  UnityEngine_Vector4_o v83;
  UnityEngine_Vector4_o v84;
  UnityEngine_Vector4_o v85;
  UnityEngine_Vector4_o v86;
  UnityEngine_Vector4_o v87;
  UnityEngine_Vector4_o v88;

  memset(dest, 0, sizeof(dest));
  else if (DDS3_PADCHECK_TRIG(0))
  {
LABEL_6:
    modelViewerWork->objectMode ^= 1u;
    return;
  }
  else if (DDS3_PADCHECK_TRIG(12))
  {
    goto LABEL_14;
  }
  if ((v8 & 0x200) == 0)
  {
    v9 = 0;
    if (modelViewerWork->hideConsFlag)
      goto LABEL_22;
LABEL_38:
    if (modelViewerWork->objectMode)
    {
      if (DDS3_PADCHECK_PRESS(1))
      {
        v16 = 0.0087266;
          goto LABEL_72;
      }
      else
      {
        if (DDS3_PADCHECK_PRESS(3))
          v16 = 0.13963;
        else
          v16 = 0.034907;
        {
LABEL_72:
          if (DDS3_PADCHECK_PRESS(5))
          {
            memmove(dest, v26->static_fields, 0x40u);
            sub_1A00880(dest, 1u);
            SDF_VU0__LOADVECTOR_B(v83);
            v27 = v16;
          }
          else
          {
            if (!DDS3_PADCHECK_PRESS(4))
            {
LABEL_91:
              if (DDS3_PADCHECK_PRESS(6))
              {
                memmove(dest, v31->static_fields, 0x40u);
                sub_1A00880(dest, 0);
                SDF_VU0__LOADVECTOR_B(v85);
                v32 = v16;
              }
              else
              {
                if (!DDS3_PADCHECK_PRESS(7))
                  goto LABEL_108;
                memmove(dest, v34->static_fields, 0x40u);
                sub_1A00880(dest, 0);
                SDF_VU0__LOADVECTOR_B(v86);
                v32 = -v16;
              }
              FromRotation_B(v32);
              Mult();
LABEL_108:
              if (DDS3_PADCHECK_PRESS(9))
              {
                memmove(dest, v36->static_fields, 0x40u);
                sub_1A00880(dest, 2u);
                SDF_VU0__LOADVECTOR_B(v87);
                v14 = v16;
                goto LABEL_124;
              }
              if (DDS3_PADCHECK_PRESS(8))
              {
                memmove(dest, v38->static_fields, 0x40u);
                sub_1A00880(dest, 2u);
                SDF_VU0__LOADVECTOR_B(v88);
                v14 = -v16;
                goto LABEL_124;
              }
LABEL_125:
                goto LABEL_126;
LABEL_128:
              return;
            }
            memmove(dest, v29->static_fields, 0x40u);
            sub_1A00880(dest, 1u);
            SDF_VU0__LOADVECTOR_B(v84);
            v27 = -v16;
          }
          FromRotation_B(v27);
          Mult();
          goto LABEL_91;
        }
      }
      goto LABEL_72;
    }
    if (DDS3_PADCHECK_PRESS(1))
    {
      v22 = 1.25;
        goto LABEL_140;
    }
    else
    {
      if (DDS3_PADCHECK_PRESS(3))
        v22 = 20.0;
      else
        v22 = 5.0;
      {
LABEL_140:
        v44 = *&dds3CameraTM.m00;
        v45 = *&dds3CameraTM.m20;
        v46 = *&dds3CameraTM.m21;
        *&v79.m01 = *&dds3CameraTM.m01;
        *&v79.m21 = v46;
        *&v79.m00 = v44;
        *&v79.m20 = v45;
        v47 = *&dds3CameraTM.m02;
        v48 = *&dds3CameraTM.m22;
        v50 = *&dds3CameraTM.m03;
        v49 = *&dds3CameraTM.m23;
        *&v79.m03 = v50;
        *&v79.m23 = v49;
        *&v79.m02 = v47;
        *&v79.m22 = v48;
        SDF_VU0__LOADVECTOR_MTXCOL_B(&v79);
        SDF_VU0__SCALEVECTOR_B(v22);
        if (DDS3_PADCHECK_PRESS(5))
        {
          SDF_VU0__ADDVECTOR();
            goto LABEL_159;
        }
        else
        {
          if (DDS3_PADCHECK_PRESS(4))
            SDF_VU0__SUBVECTOR();
          {
LABEL_159:
            v56 = *&dds3CameraTM.m00;
            v57 = *&dds3CameraTM.m20;
            v58 = *&dds3CameraTM.m21;
            *&v78.m01 = *&dds3CameraTM.m01;
            *&v78.m21 = v58;
            *&v78.m00 = v56;
            *&v78.m20 = v57;
            v59 = *&dds3CameraTM.m02;
            v60 = *&dds3CameraTM.m22;
            v62 = *&dds3CameraTM.m03;
            v61 = *&dds3CameraTM.m23;
            *&v78.m03 = v62;
            *&v78.m23 = v61;
            *&v78.m02 = v59;
            *&v78.m22 = v60;
            SDF_VU0__LOADVECTOR_MTXCOL_B(&v78);
            SDF_VU0__SCALEVECTOR_B(v22);
            if (DDS3_PADCHECK_PRESS(6))
            {
              SDF_VU0__ADDVECTOR();
                goto LABEL_173;
            }
            else
            {
              if (DDS3_PADCHECK_PRESS(7))
                SDF_VU0__SUBVECTOR();
              {
LABEL_173:
                v68 = *&dds3CameraTM.m00;
                v69 = *&dds3CameraTM.m20;
                v70 = *&dds3CameraTM.m21;
                *&v77.m01 = *&dds3CameraTM.m01;
                *&v77.m21 = v70;
                *&v77.m00 = v68;
                *&v77.m20 = v69;
                v71 = *&dds3CameraTM.m02;
                v72 = *&dds3CameraTM.m22;
                v74 = *&dds3CameraTM.m03;
                v73 = *&dds3CameraTM.m23;
                *&v77.m03 = v74;
                *&v77.m23 = v73;
                *&v77.m02 = v71;
                *&v77.m22 = v72;
                SDF_VU0__LOADVECTOR_MTXCOL_B(&v77);
                SDF_VU0__SCALEVECTOR_B(v22);
                if (DDS3_PADCHECK_PRESS(9))
                {
                  SDF_VU0__ADDVECTOR();
                    goto LABEL_128;
                }
                else
                {
                  if (!DDS3_PADCHECK_PRESS(8))
                    goto LABEL_125;
                  SDF_VU0__SUBVECTOR();
                    goto LABEL_128;
                }
LABEL_126:
                goto LABEL_128;
              }
            }
            goto LABEL_173;
          }
        }
        goto LABEL_159;
      }
    }
    goto LABEL_140;
  }
  v9 = v8 & 0x200;
  if (!modelViewerWork->hideConsFlag)
    goto LABEL_38;
LABEL_22:
  if (DDS3_PADCHECK_TRIG(5))
  {
    memmove(dest, v13->static_fields, 0x40u);
    sub_1A00880(dest, 1u);
    SDF_VU0__LOADVECTOR_B(v81);
    v14 = 0.087266;
LABEL_124:
    FromRotation_B(v14);
    Mult();
    goto LABEL_125;
  }
  if (DDS3_PADCHECK_TRIG(4))
  {
    memmove(dest, v20->static_fields, 0x40u);
    sub_1A00880(dest, 1u);
    SDF_VU0__LOADVECTOR_B(v82);
    v14 = -0.087266;
    goto LABEL_124;
  }
}

// 0x12a4240
void *ModelViewerObjectProc(dds3ProcessID_t *aProcId) {
  ModelViewerObject();
  if (modelViewerWork->hideConsFlag
  {
    return 0;
  }
  return 0;
}

// 0x12a57c0
void ModelViewerOption(void) {
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;

  if (!modelViewerWork->optionMode)
    goto LABEL_15;
LABEL_6:
  if (DDS3_PADCHECK_TRIG(1))
    goto LABEL_33;
LABEL_9:
  if (DDS3_PADCHECK_TRIG(3))
    goto LABEL_33;
}

// 0x12a5750
void *ModelViewerOptionProc(dds3ProcessID_t *aProcId) {
  ModelViewerOption();
  return 0;
}

// 0x12a7350
void *ModelViewerProc(dds3ProcessID_t *aProcId) {
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  s32 v4;
  struct ModelViewer_modelViewerWork_t_o *v5;
  s32 modeSelCursor;
  ModelViewer_c *v11;
  s16 v13;
  s32 v14;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  struct ModelViewer_StaticFields *v24;
  s64 v25;
  f32 v27;
  struct ModelViewer_StaticFields *v28;
  s64 v29;
  f32 v31;
  bool v33;
  u64 v34;
  struct ModelViewer_modelViewerWork_t_o *v35;
  s32 max_length;

  ++modelViewerWork->cursorTimer;
  v4 = modelViewerWork->cursorTimer + 1;
  modelViewerWork->cursorTimer = v4;
  if (v4 == 30)
  {
    modelViewerWork->cursorTimer = 0;
  }
  else
  {
    v5 = modelViewerWork;
    if (v5->mode)
    {
LABEL_14:
      if (DDS3_PADCHECK_TRIG(2))
      {
        ModelViewerStopModeProc();
        modelViewerWork->modeSelCursor = modelViewerWork->mode
                                                                                   - 1;
        modelViewerWork->modeBack = modelViewerWork->mode;
        modelViewerWork->mode = 0;
          goto LABEL_74;
LABEL_72:
        goto LABEL_74;
      }
LABEL_71:
        goto LABEL_74;
      goto LABEL_72;
    }
  }
  modeSelCursor = v5->modeSelCursor;
  else if (!DDS3_PADCHECK_REP(7))
  {
    goto LABEL_38;
  }
  if (modeSelCursor < LODWORD(modelViewerModeStr->max_length) - 1)
  {
    if ((v11->_2.bitflags2 & 2) == 0)
      goto LABEL_53;
LABEL_35:
LABEL_53:
    modelViewerWork->modeSelCursor = modeSelCursor + 1;
      goto LABEL_74;
    goto LABEL_72;
  }
LABEL_38:
  if (!DDS3_PADCHECK_TRIG(7))
    goto LABEL_56;
LABEL_41:
  if ((v13 & 0x200) != 0)
  {
    v14 = v13 & 0x200;
  }
  else
  {
    v14 = 0;
  }
  if (modeSelCursor != LODWORD(modelViewerModeStr->max_length) - 1)
  {
    if (!v14)
      goto LABEL_53;
    goto LABEL_35;
  }
  modelViewerWork->modeSelCursor = 0;
    goto LABEL_72;
LABEL_74:
  x = modelViewerEyePos.x;
  y = modelViewerEyePos.y;
  z = modelViewerEyePos.z;
  w = modelViewerEyePos.w;
  dds3CameraEyePos.x = x;
  dds3CameraEyePos.y = y;
  dds3CameraEyePos.z = z;
  dds3CameraEyePos.w = w;
  v25 = *&modelViewerTargetPos.x;
  v27 = modelViewerTargetPos.z;
  *&v24 = modelViewerTargetPos.w;
  *&dds3CameraTargetPos.x = v25;
  dds3CameraTargetPos.z = v27;
  LODWORD(dds3CameraTargetPos.w) = v24;
  v29 = *&modelViewerUpVector.x;
  v31 = modelViewerUpVector.z;
  *&v28 = modelViewerUpVector.w;
  *&dds3CameraUpVector.x = v29;
  dds3CameraUpVector.z = v31;
  LODWORD(dds3CameraUpVector.w) = v28;
  v33 = DDS3_PAD2CHECK_TRIG(1);
  if (v33)
  {
    *(*(*(v34 + 184) + 8LL) + 64LL) ^= 1u;
  }
  if ((*(v34 + 295) & 2) != 0 && !*(v34 + 216))
  {
    v35 = modelViewerWork;
    if (v35->hideConsFlag)
      goto LABEL_88;
LABEL_92:
    ModelViewerSetModeCons(v34);
    return 0;
  }
  v35 = *(*(v34 + 184) + 8LL);
  if (!v35->hideConsFlag)
    goto LABEL_92;
LABEL_88:
  if ((*(v34 + 295) & 2) != 0 && !*(v34 + 216))
  {
    v35 = modelViewerWork;
  }
  if (v35->mode != 3)
    goto LABEL_92;
  return 0;
}

// 0x12a2d20
void ModelViewerReleaseModels(void) {
  ;
}

// 0x12a6100
void ModelViewerSaveConf(void) {
  ;
}

// 0x12a55d0
void ModelViewerSetArrangeCons(void) {
  ;
}

// 0x12a4230
void ModelViewerSetCameraSubModeCons(void) {
  ;
}

// 0x12a7080
void ModelViewerSetCenterAxis(void) {
  ;
}

// 0x12a6020
void ModelViewerSetEffectCons(void) {
  ;
}

// 0x12a6c80
void ModelViewerSetModeCons(void) {
  bDrawText_o v3;

  initBtlMenuObj(0, 0, 240, 32, 0);
  PreBtlMenuObj(0);
  v3 = btlDevPrintf(0, 0, 0, 0, "MODE  :", 0);
  btlDrawTagLink(&bsetText, v3, 0);
  SetBtlMenuObj(0);
}

// 0x12a6d80
void ModelViewerSetModeSelCons(void) {
  ;
}

// 0x12a6d90
void ModelViewerSetModelCons(void) {
  ;
}

// 0x12a3530
void ModelViewerSetModelSelCons(void) {
  s32 width;
  s32 height;
  s16 v6;
  s32 v7;
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  s32 v9;
  System_String_o *v11;
  s32 v13;
  System_String_o *v15;
  s64 v16;
  bDrawText_o v17;
  bDrawText_o v18;
  bDrawText_o v19;

  v16 = 0;
  width = get_width(0);
  height = get_height(0);
  initBtlMenuObj(width - 240, height - 64, 240, 32, 1);
  PreBtlMenuObj(1);
  if ((v6 & 0x200) != 0)
  {
    v7 = v6 & 0x200;
  }
  else
  {
    v7 = 0;
  }
  HIDWORD(v16) = modelViewerWork->modelMajorWrk;
  v9 = 4 * (modelViewerWork->modelCursor == 0);
  LODWORD(v16) = modelViewerWork->modelMinorWrk;
  v11 = sub_232A70(&v16 + 1, "x1");
  v17 = btlDevPrintf(0, 0, 0, v9, v11, 1);
  btlDrawTagLink(&bsetText, v17, 1);
  v18 = btlDevPrintf(0, 0, 0, 0, "-", 1);
  btlDrawTagLink(&bsetText, v18, 1);
  v13 = 4 * (modelViewerWork->modelCursor == 1);
  v15 = sub_232A70(&v16, "x3");
  v19 = btlDevPrintf(0, 0, 0, v13, v15, 1);
  btlDrawTagLink(&bsetText, v19, 1);
  SetBtlMenuObj(1);
}

// 0x12a5090
void ModelViewerSetMotionCons(void) {
  ;
}

// 0x12a7090
void ModelViewerSetObjectCenter(void) {
  ;
}

// 0x12a4d40
void ModelViewerSetObjectSubModeCons(void) {
  ;
}

// 0x12a5a80
void ModelViewerSetOptionCons(void) {
  ;
}

// 0x12a5740
void ModelViewerSetTextureCons(void) {
  ;
}

// 0x12a6e30
void ModelViewerSingleMotion(void) {

}

// 0x12a7180
void ModelViewerStartModeProc(void) {
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  struct ModelViewer_ModelViewerModeProcTable_t_array *ModelViewerModeProcTable;
  s64 v7;
  u32 max_length;
  s64 v9;
  struct ModelViewer_ModelViewerModeProcTable_t_array *v10;
  Il2CppClass **v12;
  struct ModelViewer_ModelViewerModeProcTable_t_array *v13;
  System_String_o *name;
  System_Func_dds3ProcessID_t__object__o *proc;
  Il2CppObject *data;

  ModelViewerStopModeProc();
  v7 = modelViewerWork->mode - 1LL;
  max_length = ModelViewerModeProcTable->max_length;
  v9 = modelViewerWork->mode - 1LL;
  v10 = ModelViewerModeProcTable;
  v12 = &ModelViewerModeProcTable->obj.klass + v7;
  v13 = ModelViewerModeProcTable;
  name = v12[4]->_1.name;
  proc = v10->m_Items[v9]->proc;
  data = v13->m_Items[v9]->parm;
  modelViewerWork->modeProcId = dds3StartProcess(name, 0x2B00u, 1, 0, proc, 0, 0, 0, data, 0);
  dds3LinkProcess(&modelViewerWork->procId, &modelViewerWork->modeProcId);
}

// 0x12a70a0
void ModelViewerStopModeProc(void) {
  struct ModelViewer_modelViewerWork_t_o *modelViewerWork;
  dds3ProcessID_t_o **p_modeProcId;

  if (modelViewerWork->modeProcId)
  {
    p_modeProcId = &modelViewerWork->modeProcId;
    dds3KillProcess(p_modeProcId, 0);
    modelViewerWork->modeProcId = 0;
  }
}

// 0x12a5650
void ModelViewerTexture(void) {
  struct dds3ModelHandle_t_array *modelHandle;
  struct sdfModelTexList_t_o *texList;
  s32 count;

  modelHandle = modelViewerWork->modelHandle;
  texList = modelHandle->m_Items[0]->modelRoot->texList;
  if (texList)
  {
    count = texList->count;
    if (count >= 1)
    {
      ModelViewerMoveCursorLR(&modelViewerWork->textureNum, count);
    }
  }
}

// 0x12a55e0
void *ModelViewerTextureProc(dds3ProcessID_t *aProcId) {
  ModelViewerTexture();
  return 0;
}

// 0x12a6ec0
s32 TimeGraphExist(void) {
  return dds3SearchProcessName("DebugTimeGrph") != 0;
}

// 0x12a2b80
void mdlFree(dds3ModelHandle_t *aHandle) {
  ;
}

// 0x12a2bf0
s32 mdlGetMajorNum(dds3ModelHandle_t **aHandle) {
  return 0;
}

// 0x12a2c00
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle) {
  return 0;
}

// 0x12a2bd0
s32 mdlGetMotionMinorNum(dds3ModelHandle_t **aHandle) {
  return 0;
}

// 0x12a2b60
s32 mdlGetMotionNum(dds3ModelHandle_t **aHandle, s32 aGroup) {
  return 0;
}

// 0x12a2b70
s32 mdlGetNumOfCut(dds3ModelHandle_t *aHandle, s32 aGroup) {
  return 0;
}

// 0x12a2bc0
void mdlGetPosition(dds3ModelHandle_t *aHandle) {
  ;
}

// 0x12a2bb0
void mdlGetRotate(dds3ModelHandle_t *aHandle) {
  ;
}

// 0x12a2b10
bool mdlHasMotion(dds3ModelHandle_t *HNDL) {
  return 0;
}

// 0x12a2b30
s32 mdlHasMotionEx(dds3ModelHandle_t **aHandle, s32 aGroup) {
  return 0;
}

// 0x12a2b00
dds3ModelHandle_t *mdlLoad(u32 aMajor, u32 aMinor) {
  return 0;
}

// 0x12a2b20
void mdlLoopMotion(dds3ModelHandle_t *aHandle, s32 aGroup, s32 aNumber) {
  ;
}

// 0x12a2c50
s32 mdlPibCheckItemType(void *data, s32 type) {
  return 0;
}

// 0x12a2c60
void mdlPibEditTrackInfo(void *data, s16 *cursor_p) {
  ;
}

// 0x12a2c10
void *mdlPibGetChunk(dds3ModelHandle_t *handle, s32 group) {
  return 0;
}

// 0x12a2c20
s32 mdlPibGetChunkItemCount(void *data) {
  return 0;
}

// 0x12a2c30
void *mdlPibGetFirstChunkItem(void *data) {
  return 0;
}

// 0x12a2c40
void *mdlPibGetNextChunkItem(void *data) {
  return 0;
}

// 0x12a2b90
void mdlSetPosition(dds3ModelHandle_t *aHandle) {
  ;
}

// 0x12a2ba0
void mdlSetRotate(dds3ModelHandle_t *aHandle) {
  ;
}

// 0x12a2b40
void mdlSmoothLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  ;
}

// 0x12a2b50
void mdlSmoothSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  ;
}

// 0x12a2be0
void sdfMotionChange(sdfMotionCtrlr_t *aCtrlr, s32 aCutNum, s32 aType) {
  ;
}
