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
static s32 ModelViewerSetOptionCons_cursor_y_tbl[UNKNOWN_ARRAY_SIZE];
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
    ViewerDispOn(0);
    ModelViewerInitCamera();
    SDF_DEGtoRAD(0);
    ModelViewerLoadModel();
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    ModelViewerStartModeProc();
}

// 0x12a2c70
void KillModelViewer(void) {
  dds3KillProcessName(StringLiteral_5247, 0);
  dds3KillProcessName(StringLiteral_5248, 0);
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
        case 1:
          if (modelViewerWork->modelCount >= 2)
          {
            v12 = modelViewerWork->modelHandle;
            v12->m_Items[0] = 0;
            ModelViewerHandleBackRotate(v6);
            --modelViewerWork->modelCount;
          }
        case 2:
          if (modelViewerWork->modelCount >= 2)
          {
            if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
            ModelViewerHandleRotate(v6);
          }
        case 3:
          if (modelViewerWork->modelCount >= 2)
          {
            if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
            ModelViewerHandleBackRotate(v6);
          }
        case 4:
          v14 = 0;
          if ((*(v6 + 295) & 2) != 0)
          break;
        default:
      }
      while (1)
      {
        v15 = *(*(v6 + 184) + 8LL);
        if (v14 >= *(v15 + 80))
          break;
        if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
        {
          v16 = modelViewerWork->modelHandle;
        }
        else
        {
          v16 = *(v15 + 232);
          if (v14 >= LODWORD(v16->max_length))
        }
        ++v14;
        {
        }
      }
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
    DDS3_PADCHECK_TRIG(0);
    DDS3_PADCHECK_PRESS(0);
    SDF_VU0__LOADIDENTITYVECTOR();
    SDF_VU0__LOADVECTOR_MTXCOL_B(0);
    FromRotation_B(0);
    Mult();
    ToMatrix();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__APPLYMATRIX_XYZ1();
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    ModelViewerInitCamera();
}

// 0x12a37d0
void *ModelViewerCameraProc(dds3ProcessID_t *aProcId) {
  ModelViewerCamera();
  return 0;
}

// 0x12a7b00
void *ModelViewerDrawEndProc(dds3ProcessID_t *aProcId) {
    IsLoad(0, 0);
    GetFname(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    nbLoadStartUnitPack(0);
    return 0;
}

// 0x12a7af0
void ModelViewerDrawMarkPos(dds3ModelHandle_t *handle) {
  ;
}

// 0x12a5b00
void ModelViewerEffect(void) {
    DDS3_PADCHECK_TRIG(0);
    DDS3_PADCHECK_REP(0);
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
  }
  v20 = modelViewerWork->modelHandle;
  if (!v6)
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
  }
  v9->m_Items[0] = v7;
}

// 0x12a67a0
void ModelViewerInitCamera(void) {
  ModelViewer_c *v2;
  struct ModelViewer_StaticFields *static_fields;
  f32 w;
  struct ModelViewer_StaticFields *v5;
  f32 v6;
  struct ModelViewer_StaticFields *v7;
  f32 v8;

  static_fields = v2->static_fields;
  *&static_fields->modelViewerEyePos.x = *&static_fields->modelViewerEyeDefault.x;
  w = static_fields->modelViewerEyeDefault.w;
  static_fields->modelViewerEyePos.z = static_fields->modelViewerEyeDefault.z;
  static_fields->modelViewerEyePos.w = w;
  v5 = v2->static_fields;
  *&v5->modelViewerTargetPos.x = *&v5->modelViewerTargetDefault.x;
  v6 = v5->modelViewerTargetDefault.w;
  v5->modelViewerTargetPos.z = v5->modelViewerTargetDefault.z;
  v5->modelViewerTargetPos.w = v6;
  v7 = v2->static_fields;
  *&v7->modelViewerUpVector.x = *&v7->modelViewerUpDefault.x;
  v8 = v7->modelViewerUpDefault.w;
  v7->modelViewerUpVector.z = v7->modelViewerUpDefault.z;
  v7->modelViewerUpVector.w = v8;
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
  struct ModelViewer_StaticFields *static_fields;
  ModelViewer_c *v30;
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
        return;
      case 2:
        static_fields = ModelViewer->static_fields;
      case 3:
        if (!ModelViewerMoveCursorUD(&v14->smoothFrame, 100, 10))
        return;
      case 4:
        if (!ModelViewerMoveCursorUD(&v14->beforeFrame, 100, 10))
        return;
      default:
        if (DDS3_PADCHECK_TRIG(12))
          return;
        if (modelViewerWork->modelCursor <= 1)
        {
          if (DDS3_PADCHECK_TRIG(1))
          {
            v33 = modelViewerWork;
            if (v33->modelMajor != v33->modelMajorWrk)
            if (v33->modelMinor != v33->modelMinorWrk)
            {
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
        static_fields = v30->static_fields;
        v14 = static_fields->modelViewerWork;
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
      v17 = 1;
      modelViewerWork->motionSeek = v17;
      return;
    }
    if (DDS3_PADCHECK_PRESS(4))
    {
      v17 = -1;
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
    DDS3_PADCHECK_TRIG(0);
    DDS3_PADCHECK_REP(0);
    return 0;
}

// 0x12a62d0
s32 ModelViewerMoveCursorUD(s32 *aCursorPtr, s32 aMax, s32 aLarge) {
    DDS3_PADCHECK_TRIG(0);
    DDS3_PADCHECK_REP(0);
    return 0;
}

// 0x12a42e0
void ModelViewerObject(void) {
    DDS3_PADCHECK_TRIG(0);
    SDF_VU0__LOADIDENTITYVECTOR();
    DDS3_PADCHECK_PRESS(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    FromRotation_B(0);
    Mult();
    SDF_VU0__LOADVECTOR_MTXCOL_B(0);
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__SUBVECTOR();
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
    ModelViewerMoveCursorUD(0, 0, 0);
    DDS3_PADCHECK_TRIG(0);
}

// 0x12a5750
void *ModelViewerOptionProc(dds3ProcessID_t *aProcId) {
  ModelViewerOption();
  return 0;
}

// 0x12a7350
void *ModelViewerProc(dds3ProcessID_t *aProcId) {
    DDS3_PADCHECK_TRIG(0);
    ModelViewerStopModeProc();
    DDS3_PADCHECK_REP(0);
    ModelViewerStartModeProc();
    DDS3_PAD2CHECK_TRIG(0);
    ModelViewerSetModeCons();
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
  v3 = btlDevPrintf(0, 0, 0, 0, StringLiteral_5249, 0);
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
    initBtlMenuObj(0, 0, 0, 0, 0);
    PreBtlMenuObj(0);
    btlDevPrintf(0, 0, 0, 0, 0, 0);
    btlDrawTagLink(0, (bDrawText){0}, 0);
    SetBtlMenuObj(0);
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
  struct ModelViewer_StaticFields *static_fields;
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
  static_fields = ModelViewer->static_fields;
  modelViewerWork = static_fields->modelViewerWork;
  ModelViewerModeProcTable = static_fields->ModelViewerModeProcTable;
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
  return dds3SearchProcessName(StringLiteral_5252) != 0;
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
