#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct pbGame_cameraFuncDelegate pbGame_cameraFuncDelegate;
typedef struct pbGame_keyFuncDelegate pbGame_keyFuncDelegate;
typedef struct pbGroupData_t pbGroupData_t;
typedef struct pbLevelTable_t pbLevelTable_t;
typedef struct pbProcHandle_t pbProcHandle_t;

static u32 pb_play;
static pbProcHandle_t *blockDB;
static pbProcHandle_t *bmap;
static pbProcHandle_t *mychar[4];
static pbProcHandle_t *goal;
static pbProcHandle_t *record;
static pbProcHandle_t *mapCursor;
static pbProcHandle_t *clear;
static pbProcHandle_t *moveC;
static pbProcHandle_t *moveB;
static pbProcHandle_t *roundCamera;
static pbProcHandle_t *moveViewCamera;
static dds3ProcessID_t *scr_msg;
static u32 current_char;
static f32 cameraAngle;
static f32 cameraRadius;
static f32 cameraDegree;
static f32 cameraDegreeInit;
static s32 pb_ctr;
static f32 *move_count[5];
static f32 *round_count[4];
static u8 degree_mode;
static u8 cameraWk_flg;
static sdfVector4_t cameraWk[2];
static u32 *bupmap;
static void *pbCameraObj;
static void *pbCameraCtrl;
static void *pbrCameraObj;
static void *pbrCameraCtrl;
static s32 stage_val;
static s32 pb_cdir;
static s32 pb_cdirflag;
static f32 rot_x[5];
static f32 rot_z[5];
static s32 rotblk_cnt;
static f32 roted_blkx[5];
static f32 roted_blkz[5];
static s32 pbViewChangeflag;
static s32 pbCameraWorkDir;
static s32 pbCameraQuakeflag;
static s32 pbQuakeFrame;
static s32 pbQuakePosX;
static s32 pbQuakePosY;
static s32 pbScrollCameraPosMovX;
static s32 pbScrollCameraPosMovY;
static s32 pbCameraRotateflag;
static s32 pbScrollCameraPosMovXbup;
static s32 pbScrollCameraPosMovYbup;
static s32 pbChangeCameraMovflag;
static sdfVector3_t pbRotateMov;
static sdfVector3_t pb_cameraAngle;
static sdfVector3_t pb_CameraPosbup;
static sdfVector3_t pbBGRotateMov;
static sdfVector3_t pbBG_cameraAngle;
static s32 clearAutLine;
static s32 startclearAutoLine;
static s32 changeAutLine;
static s32 MRblockAutLine;
static s32 MBlkFallflag;
static s32 BGDrawflag;
static bool MoveOutLineflag;
static bool MoveBlkFallflag;
static pbLevelTable_t *pLevel1[22];
static pbLevelTable_t *pLevel2[3];
static pbLevelTable_t *pLevel3[3];
static pbLevelTable_t **pbLevelTable;
static s16 gameKey1_x;
static s16 gameKey1_y;
static pbGame_keyFuncDelegate *keyFunc[3];
static pbGame_cameraFuncDelegate *cameraFunc[3];
static u32 game_motion_time;
static void *oPB_UI;
static void *oPB_BG;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void CalcDegreeMode(void);
void ClearoPB_UI(void);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
s32 FindId(s32 type, char *name);
s32 GetAllStageClearBit(void);
void *GetMainCamera(dds3DefaultMain *this);
void *GetRenderCamera(dds3DefaultMain *this);
s32 GetStageNumber(void);
s32 GetStageScriptLabel(void);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Remove(char *key);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void ScrollArrowDraw(void);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetCameraQuake(s32 frame, s32 range);
void dds3FadeIn2(u32 frame);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
void dds3ResetProcessFlag(dds3ProcessID_t **target, u32 flag, s32 type);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void evtBitOn(s32 no);
s8 fclChkMessageDraw(dds3ProcessID_t *PID);
s8 fclChkSignal(s8 Idx);
void fclClearSignal(s8 Idx);
s8 fclSetVal(s8 Idx, s32 Val);
u32 getCharacterNum(void);
s8 hallCheck(pbGroupData_t **grp);
u32 hitCheck(s32 dir, pbGroupData_t **grp);
s32 p2sdPlayBGM(s32 a);
s32 p2sdPlaySE(s32 a);
u32 pbAddRecord_blk(pbProcHandle_t **p, pbGroupData_t **grp);
u32 pbAddRecord_char(pbProcHandle_t **p, u32 idx, pbProcHandle_t ***c);
u32 pbAddRecord_flor(pbProcHandle_t **p, pbGroupData_t **grp);
void pbChangeMotion(pbProcHandle_t **p, u32 num);
u32 pbCheckMap(void);
s8 pbCheckPopRecord(pbProcHandle_t **p);
void pbClearRecord(pbProcHandle_t **p);
void pbDispMyCharacter(pbProcHandle_t **p, s8 sw);
pbProcHandle_t *pbGetCurrentProcess(void);
u8 pbGetKeyAction(u8 press);
u8 pbGetKeyMode(void);
void pbGetMyCharcterPos(pbProcHandle_t **p, sdfVector4_t *pos);
void pbGetMyCharcterPos2(pbProcHandle_t **p, s16 *x, s16 *y);
s32 pbGetMyCharcterRot(pbProcHandle_t **p);
void pbGotoNewStage(void);
pbProcHandle_t *pbInitExitDraw(pbProcHandle_t **parent);
void pbInitGame(pbProcHandle_t **p, dds3ProcessID_t *id);
void pbInitGameCamera(void);
pbProcHandle_t *pbInitMapBaseDraw(pbProcHandle_t **parent, u32 sw);
pbProcHandle_t *pbInitMyCharacterDraw(pbProcHandle_t **parent, u32 col, u32 motion);
void pbLoadSystemData(s32 num);
void pbMoveMyCharcter(pbProcHandle_t **p, f32 x, f32 y);
void pbMoveMyCharcter2(pbProcHandle_t **p, s16 x, s16 y);
u32 pbMyCharacterDispStat(pbProcHandle_t **p);
s32 pbPopRecord(pbProcHandle_t **p, pbProcHandle_t ***c, pbProcHandle_t **blkDB);
u32 pbPushRecord(pbProcHandle_t **p);
void pbRebuildOutline(pbGroupData_t **p);
void pbReleaseGroupDB(pbProcHandle_t **p, u32 grpID);
u8 pbRotLKeyAct(void);
u8 pbRotRKeyAct(void);
void pbRotateXCamera(f32 angle);
void pbRotateYCamera(f32 angle);
void pbRotateYCamera2(f32 angle, f32 radius, f32 degree);
void pbRoundCamera(s32 dir);
pbGroupData_t *pbSearchGroupDB(pbProcHandle_t **p, u32 grpID);
void pbSetGameCamera0(void);
void pbSetGameCamera1(void);
void pbSetGameCamera2(void);
void pbSetGameCamera4(s16 x, s16 y);
void pbSetMapCursorFlag(pbProcHandle_t **p, s32 flag);
void pbSetMyCharcterPos2(pbProcHandle_t **p, s16 x, s16 y);
void pbSetMyCharcterRot(pbProcHandle_t **p, s32 dir);
pbProcHandle_t *pbStartAutoRoundCamera(pbProcHandle_t *parent, s32 dir);
pbProcHandle_t *pbStartBlockDataBase(pbProcHandle_t **parent);
pbProcHandle_t *pbStartClear(pbProcHandle_t *parent);
pbProcHandle_t *pbStartDrawMapCursor(pbProcHandle_t **parent);
pbProcHandle_t *pbStartErrorDraw(pbProcHandle_t *parent, u32 eCode, u32 frame);
pbProcHandle_t *pbStartMenu(pbProcHandle_t **parent, u32 mode);
pbProcHandle_t *pbStartMoveBlock(pbProcHandle_t *parent, pbGroupData_t *grp, s32 dir);
pbProcHandle_t *pbStartMoveChar(pbProcHandle_t *parent, s32 dir, u32 scl);
pbProcHandle_t *pbStartRecord(pbProcHandle_t **parent);
pbProcHandle_t *pbStartRoundBlock(pbProcHandle_t *parent, pbGroupData_t *grp, s32 dir);
pbProcHandle_t *pbStartViewModeCamera(pbProcHandle_t *parent);
void pb_General__CLR_MAP_BLKDAT_(s32 x, s32 y);
u16 pb_General__GET_MAP_BLK_(s32 x, s32 y);
u32 pb_General__GET_MAP_GRPID_(s32 x, s32 y);
s32 pb_General__GET_MAP_HALL_(s32 x, s32 y);
s32 pb_General__PB_PROC_REF_MESS(pbProcHandle_t *p);
void pb_General__PB_PROC_SEND_MESS(pbProcHandle_t *p, s32 mes);
void pb_General__SET_MAP_BLK_(s32 x, s32 y, s32 v);
void pb_General__SET_MAP_GRPID_(s32 x, s32 y, s32 id);
void pb_General__SET_MAP_HALL_(s32 x, s32 y, s32 v);
u32 pushCheck(s32 dir, u32 grpID, pbGroupData_t **grp);
u32 roundCheck(s32 dir, u32 grpID, pbGroupData_t **grp);
s32 roundDirCheck(s32 dir, u32 grpID, u32 *speed);
dds3ProcessID_t *scrStartScript2(s32 a, void *b, s32 c);
void setMoveBlockData(pbGroupData_t **grp, s32 dir);
void setRoundBlockData(pbGroupData_t **grp, s32 dir);
void updateMotion(void);

// 0x165a660
void CalcDegreeMode(void) {
  s16 v3;
  s32 v4;
  struct pbGame_StaticFields **p_static_fields;
  UnityEngine_GameObject_o *RenderCamera;
  f32 x;
  f32 y;
  f32 z;
  struct UnityEngine_Vector3_array *pbcCameraPos;
  u32 pb_cdir;
  f32 v21;
  f32 v22;
  f32 v23;
  struct UnityEngine_Vector3_array *v24;
  u32 v25;
  f32 *v27;
  f32 v28;
  f32 v29;
  f32 v30;
  struct UnityEngine_Vector3_array *pbCameraPos;
  f32 *v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 *v39;
  f32 v40;
  f32 v41;
  f32 v42;
  struct UnityEngine_Vector3_array *v43;
  f32 *v45;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  UnityEngine_Vector3_o v56;
  UnityEngine_Vector3_o v57;
  UnityEngine_Vector3_o v58;
  UnityEngine_Vector3_o v59;
  UnityEngine_Vector3_o v60;
  UnityEngine_Vector3_o v61;
  UnityEngine_Vector3_o v62;
  UnityEngine_Vector3_o v63;
  UnityEngine_Vector3_o v64;
  UnityEngine_Vector3_o v65;
  UnityEngine_Vector3_o v66;
  UnityEngine_Vector3_o v67;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
    if (degree_mode)
      goto LABEL_5;
  }
  else
  {
    v4 = 0;
    if (degree_mode)
    {
LABEL_5:
      cameraDegree = cameraDegree + 0.3;
      if (cameraDegree > 1.5608)
      {
        cameraDegree = 1.5608;
        (*p_static_fields)->degree_mode = 0;
        (*p_static_fields)->cameraDegree = (*p_static_fields)->cameraDegreeInit;
      }
      goto LABEL_24;
    }
  }
  cameraDegree = cameraDegree + -0.15;
  if (cameraDegree < cameraDegreeInit)
  {
    cameraDegree = cameraDegreeInit;
    (*p_static_fields)->degree_mode = 0;
  }
LABEL_24:
  RenderCamera = GetRenderCamera(kernelObject);
  GetComponent_object_(RenderCamera);
  if (pbViewChangeflag == 1)
  {
    x = r_cameraPos.x;
    y = r_cameraPos.y;
    z = r_cameraPos.z;
    v54 = z;
    v27 = (pbcCameraPos + 12 * pb_cdir);
    v28 = v27[10];
    v29 = v27[8];
    v30 = v27[9];
    v33 = (pbCameraPos + 12 * pb_cdir);
    v34 = v33[8];
    v35 = v33[9];
    v36 = v33[10];
    v58.x = v29;
    v58.y = v30;
    v58.z = v28;
    v64.x = v34;
    v64.y = v35;
    v64.z = v36;
    v62 = op_Subtraction(v58, v64);
    v65 = op_Division(v62, 3.0);
    v59.z = v54;
    v59.x = x;
    v59.y = y;
    v56 = op_Addition(v59, v65);
    v51 = v56.x;
    v52 = v56.y;
    v53 = v56.z;
  }
  else
  {
    v21 = r_cameraPos.x;
    v22 = r_cameraPos.y;
    v23 = r_cameraPos.z;
    v24 = pbcCameraPos;
    v25 = pb_cdir;
    v55 = v23;
    v39 = (v24 + 12 * v25);
    v40 = v39[10];
    v41 = v39[8];
    v42 = v39[9];
    v43 = pbCameraPos;
    v45 = (v43 + 12 * v25);
    v46 = v45[8];
    v47 = v45[9];
    v48 = v45[10];
    v60.x = v41;
    v60.y = v42;
    v60.z = v40;
    v66.x = v46;
    v66.y = v47;
    v66.z = v48;
    v63 = op_Subtraction(v60, v66);
    v67 = op_Division(v63, 3.0);
    v61.z = v55;
    v61.x = v21;
    v61.y = v22;
    v57 = op_Subtraction(v61, v67);
    v51 = v57.x;
    v52 = v57.y;
    v53 = v57.z;
  }
  r_cameraPos.x = v51;
  r_cameraPos.y = v52;
  r_cameraPos.z = v53;
  pbChangeCameraMovflag = 1;
}

// 0x1665b70
dds3ProcessFunc_t *ClearProc(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v10;
  UnityEngine_GameObject_o *gameObject;
  bool activeSelf;
  u64 *image;
  s64 v14;
  Il2CppClass *v15;
  char *v16;
  s64 *v17;
  u64 *v18;
  s64 v19;
  char *v20;
  s64 *v21;
  s32 v22;
  s64 i;
  u64 v26;
  struct XRD773Unity_CommonMesh_array *pBlk_Mesh;
  UnityEngine_Object_o *v29;
  struct XRD773Unity_CommonMesh_array *v32;
  UnityEngine_Object_o *v35;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  UnityEngine_Object_o *v39;
  struct XRD773Unity_CommonMesh_array *v41;
  UnityEngine_Object_o *v44;
  UnityEngine_Object_o *v46;
  char *v48;
  s64 *v49;
  u64 v50[2];
  char *v51;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v50);
    if ((v50[0] & 1) != 0)
      v48 = v51;
    else
      v48 = v50 + 1;
    v49 = sub_8C4940(v48);
  }
  v7 = workdata[2].klass;
LABEL_9:
  transform = get_transform(oPB_UI, 0);
  v10 = Find(transform, "pzlclear", 0);
  gameObject = get_gameObject(v10);
  activeSelf = get_activeSelf(gameObject);
  if (v7)
  {
    image = v7->_1.image;
    if (*(v7->_1.image + 288) < v14 || (v15 = v7, *(image[25] + 8 * v14 - 8) != pbclearwork_tag))
    {
      sub_8FC2C0(image[8], pbclearwork_tag, v50);
      if ((v50[0] & 1) != 0)
        v16 = v51;
      else
        v16 = v50 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  else
  {
    v15 = 0;
  }
  if (activeSelf)
  {
    v18 = v7->_1.image;
    if (*(v7->_1.image + 288) < v19 || *(v18[25] + 8 * v19 - 8) != pbclearwork_tag)
    {
      sub_8FC2C0(v18[8], pbclearwork_tag, v50);
      if ((v50[0] & 1) != 0)
        v20 = v51;
      else
        v20 = v50 + 1;
      v21 = sub_8C4940(v20);
    }
  }
  else
  {
    SetActive(gameObject, 1, 0);
    v7 = v15;
  }
  v22 = *(&xmmword_10 + v7);
  *(&xmmword_10 + v7) = v22 - 1;
  if (v22 <= 0)
  {
    if (get_activeSelf(gameObject))
      SetActive(gameObject, 0, 0);
    for (i = 4; i != 404; ++i)
    {
      v26 = i - 4;
      v29 = *(&pBlk_Mesh->obj.klass + i);
      if (op_Inequality(v29, 0, 0))
      {
        v32 = pBlk_Mesh;
        v35 = get_gameObject(*(&v32->obj.klass + i), 0);
        Destroy_27360000(v35);
      }
      v39 = *(&pMRBlk_Mesh->obj.klass + i);
      if (op_Inequality(v39, 0, 0))
      {
        v41 = pMRBlk_Mesh;
        v44 = get_gameObject(*(&v41->obj.klass + i), 0);
        Destroy_27360000(v44);
      }
    }
    v46 = Find("pbInitMyCharacterDraw", 0);
    Destroy_27360000(v46);
    id->func_ans = -1;
  }
  return 0;
}

// 0x1661480
void ClearoPB_UI(void) {
  UnityEngine_Object_o *oPB_UI;
  bool v5;
  UnityEngine_Object_o *v7;
  UnityEngine_Object_o *oPB_BG;
  UnityEngine_Object_o *v11;

  v5 = op_Inequality(oPB_UI, 0, 0);
  if (v5)
  {
    v7 = oPB_UI;
    Destroy_27360000(v7);
    oPB_UI = 0;
  }
  if (op_Inequality(oPB_BG, 0, 0))
  {
    v11 = oPB_BG;
    Destroy_27360000(v11);
    oPB_BG = 0;
  }
}

// 0x16660b0
dds3ProcessFunc_t *DeleteClearProc(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v15[3];

  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v15);
      if ((v15[0] & 1) != 0)
        v6 = v15[2];
      else
        v6 = v15 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  ButtonGuideDispOff();
  ++pbWk->stage;
  pbGotoNewStage();
  clearAutLine = 1;
  StageDrawflag = 0;
  MRBlockDrawflag = 0;
  WallChangeflag = 0;
  OutLineFDraw = 0;
  return 0;
}

// 0x165ac50
s32 GetAllStageClearBit(void) {
  struct pbLevelTable_t_array_array *pbLevelTable;
  s64 level;
  pbLevelTable_t_array *v7;

  level = pbWk->level;
  v7 = pbLevelTable->m_Items[level];
  return v7->m_Items[0]->stage;
}

// 0x165ab50
s32 GetStageNumber(void) {
  struct pbLevelTable_t_array_array *pbLevelTable;
  struct pbWork_t_o *pbWk;
  s64 level;
  pbLevelTable_t_array *v8;
  s64 v9;

  level = pbWk->level;
  v8 = pbLevelTable->m_Items[level];
  v9 = pbWk->stage + 1LL;
  return v8->m_Items[v9]->stage;
}

// 0x165a560
s32 GetStageScriptLabel(void) {
  struct pbLevelTable_t_array_array *pbLevelTable;
  struct pbWork_t_o *pbWk;
  s64 level;
  pbLevelTable_t_array *v8;
  s64 v9;

  level = pbWk->level;
  v8 = pbLevelTable->m_Items[level];
  v9 = pbWk->stage + 1LL;
  return v8->m_Items[v9]->label;
}

// 0x1668390
void *GetoPB_BG(void) {
  return oPB_BG;
}

// 0x1657d10
void *GetoPB_UI(void) {
  return oPB_UI;
}

// 0x165ea10
u32 RotateBit(u32 val, s32 loop) {
  s32 v3;

  if (loop >= 1)
  {
    if (loop != 1)
    {
      v3 = (loop & 1) - loop;
      do
      {
        val = (4 * val) & 8 | (((8 * (val & 1)) | (val >> 1)) >> 1);
        v3 += 2;
      }
      while (v3);
    }
    if ((loop & 1) != 0)
      return (8 * (val & 1)) | (val >> 1);
  }
  return val;
}

// 0x165d910
void ScrollArrowDraw(void) {
  UnityEngine_GameObject_o *oPB_UI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  s64 *gameObject;
  UnityEngine_Transform_o *v7;
  UnityEngine_Component_o *v8;
  s64 *v9;
  UnityEngine_Transform_o *v10;
  UnityEngine_Component_o *v11;
  s64 *v12;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  s64 *v15;
  u64 *v16;
  s64 *v17;
  s64 *v18;
  s64 *v23;
  s64 *v24;
  s64 *v30;
  s64 *v31;
  s64 *v37;
  s64 *v38;
  s64 v46;
  s64 v47;
  s64 v50;
  s64 v52;
  UnityEngine_GameObject_o *v54;
  bool v55;
  s64 pb_cdir;
  s64 v57;
  s64 v59;
  s64 v61;
  s16 v64;
  s32 v65;
  s64 v67;
  s64 v69;
  s64 v73;
  s64 v75;
  UnityEngine_GameObject_o *v77;
  bool v78;
  s64 v79;
  s64 v81;
  s64 v84;
  s64 v86;
  s16 v89;
  s32 v90;
  s64 v92;
  s64 v94;
  s64 v98;
  s64 v100;
  UnityEngine_GameObject_o *v102;
  bool v103;
  s64 v104;
  s64 v106;
  s64 v109;
  s64 v111;
  s16 v114;
  s32 v115;
  s64 v117;
  s64 v119;
  s64 v123;
  s64 v125;
  UnityEngine_GameObject_o *v127;
  bool v128;
  s64 v129;
  s64 v131;
  s64 v135;
  s64 v137;

LABEL_7:
  transform = get_transform(oPB_UI, 0);
  v5 = Find(transform, "pzlscroll/puzlscroll_yau", 0);
  gameObject = get_gameObject(v5);
  v7 = get_transform(oPB_UI, 0);
  v8 = Find(v7, "pzlscroll/puzlscroll_yad", 0);
  v9 = get_gameObject(v8);
  v10 = get_transform(oPB_UI, 0);
  v11 = Find(v10, "pzlscroll/puzlscroll_yar", 0);
  v12 = get_gameObject(v11);
  v13 = get_transform(oPB_UI, 0);
  v14 = Find(v13, "pzlscroll/puzlscroll_yal", 0);
  v15 = get_gameObject(v14);
  v16 = NewSpecific(UnityEngine_GameObject__, 4u);
  v17 = NewSpecific(UnityEngine_GameObject, 4u);
  v18 = v17;
  v18[4] = gameObject;
  v18[5] = v15;
  v18[6] = v9;
  v18[7] = v12;
  v16[4] = v18;
  v23 = NewSpecific(UnityEngine_GameObject, 4u);
  v24 = v23;
  v24[4] = v12;
  v24[5] = gameObject;
  v24[6] = v15;
  v24[7] = v9;
  v16[5] = v24;
  v30 = NewSpecific(UnityEngine_GameObject, 4u);
  v31 = v30;
  v31[4] = v9;
  v31[5] = v12;
  v31[6] = gameObject;
  v31[7] = v15;
  v16[6] = v31;
  v37 = NewSpecific(UnityEngine_GameObject, 4u);
  v38 = v37;
  v38[4] = v15;
  v38[5] = v9;
  v38[6] = v12;
  v38[7] = gameObject;
  v16[7] = v38;
  if (gameKey1_y <= 18)
  {
    v57 = v16[pb_cdir + 4];
    if (!get_activeSelf(*(v57 + 32), 0))
    {
      v59 = pb_cdir;
      v61 = v16[v59 + 4];
      v54 = *(v61 + 32);
      v55 = 1;
      goto LABEL_114;
    }
  }
  else
  {
    v46 = pb_cdir;
    v47 = v16[v46 + 4];
    if (get_activeSelf(*(v47 + 32), 0))
    {
      v50 = pb_cdir;
      v52 = v16[v50 + 4];
      v54 = *(v52 + 32);
      v55 = 0;
LABEL_114:
      SetActive(v54, v55, 0);
    }
  }
  if ((v64 & 0x200) != 0)
  {
    v65 = v64 & 0x200;
    if (gameKey1_x >= 1)
    {
LABEL_117:
      else
      {
        v67 = pb_cdir;
        if (v67 >= *(v16 + 6))
          goto LABEL_120;
      }
      v69 = v16[v67 + 4];
      if (!get_activeSelf(*(v69 + 40), 0))
      {
        v73 = pb_cdir;
        v75 = v16[v73 + 4];
        v77 = *(v75 + 40);
        v78 = 1;
LABEL_151:
        SetActive(v77, v78, 0);
        goto LABEL_152;
      }
      goto LABEL_152;
    }
  }
  else
  {
    v65 = 0;
    if (gameKey1_x >= 1)
      goto LABEL_117;
  }
  v79 = pb_cdir;
  v81 = v16[v79 + 4];
  if (get_activeSelf(*(v81 + 40), 0))
  {
    v84 = pb_cdir;
    v86 = v16[v84 + 4];
    v77 = *(v86 + 40);
    v78 = 0;
    goto LABEL_151;
  }
LABEL_152:
  if ((v89 & 0x200) != 0)
  {
    v90 = v89 & 0x200;
    if (gameKey1_y >= 1)
    {
LABEL_154:
      else
      {
        v92 = pb_cdir;
        if (v92 >= *(v16 + 6))
          goto LABEL_157;
      }
      v94 = v16[v92 + 4];
      if (!get_activeSelf(*(v94 + 48), 0))
      {
        v98 = pb_cdir;
        v100 = v16[v98 + 4];
        v102 = *(v100 + 48);
        v103 = 1;
LABEL_188:
        SetActive(v102, v103, 0);
        goto LABEL_189;
      }
      goto LABEL_189;
    }
  }
  else
  {
    v90 = 0;
    if (gameKey1_y >= 1)
      goto LABEL_154;
  }
  v104 = pb_cdir;
  v106 = v16[v104 + 4];
  if (get_activeSelf(*(v106 + 48), 0))
  {
    v109 = pb_cdir;
    v111 = v16[v109 + 4];
    v102 = *(v111 + 48);
    v103 = 0;
    goto LABEL_188;
  }
LABEL_189:
  if ((v114 & 0x200) != 0)
  {
    v115 = v114 & 0x200;
    if (gameKey1_x <= 18)
    {
LABEL_191:
      else
      {
        v117 = pb_cdir;
        if (v117 >= *(v16 + 6))
          goto LABEL_194;
      }
      v119 = v16[v117 + 4];
      if (!get_activeSelf(*(v119 + 56), 0))
      {
        v123 = pb_cdir;
        v125 = v16[v123 + 4];
        v127 = *(v125 + 56);
        v128 = 1;
LABEL_224:
        SetActive(v127, v128, 0);
        return;
      }
      return;
    }
  }
  else
  {
    v115 = 0;
    if (gameKey1_x <= 18)
      goto LABEL_191;
  }
  else
  {
    v129 = pb_cdir;
    if (v129 >= *(v16 + 6))
      goto LABEL_212;
  }
  v131 = v16[v129 + 4];
  if (get_activeSelf(*(v131 + 56), 0))
  {
    v135 = pb_cdir;
    v137 = v16[v135 + 4];
    v127 = *(v137 + 56);
    v128 = 0;
    goto LABEL_224;
  }
}

// 0x1662e20
void SetCameraQuake(s32 frame, s32 range) {
  pbGame_c *v5;
  s64 v7;

  if (range)
  {
    pbCameraQuakeflag = 1;
    if (frame)
    {
      pbQuakeFrame = frame;
      if ((v5->_2.bitflags2 & 2) == 0)
        goto LABEL_22;
    }
    else
    {
      pbQuakeFrame = -1;
      if ((v5->_2.bitflags2 & 2) == 0)
        goto LABEL_22;
    }
LABEL_22:
    pbQuakePosY = 10 * range;
    v7 = 6871947676LL * pbQuakePosY;
    pbQuakePosX = (v7 >> 34) + (v7 >> 63);
    return;
  }
  pbCameraQuakeflag = 0;
}

// 0x16610c0
dds3ProcessFunc_t *deleteGame(dds3ProcessID_t *id) {
  UnityEngine_Object_o *gameObject;
  UnityEngine_Object_o *v11;
  UnityEngine_GameObject_o *v12;
  UnityEngine_Object_o *pModelObj;
  UnityEngine_Object_o *v18;

  gameObject = get_gameObject(pGoalBlk_Mesh);
  Destroy_27360000(gameObject);
  Destroy_27360000(pMRBlk_GameObj);
  Destroy_27360000(pMBlk_GameObj);
  Destroy_27360000(pBlk_GameObj);
  PropertySheet___Clear(Line3D);
  pb_cdir = 0;
  pb_cdirflag = 0;
  pbViewChangeflag = 0;
  BlkInitflag = 0;
  fBlk_allCntbup = 0;
  mBlkStageChangeflag = 1;
  StageDrawflag = 0;
  MRBlockDrawflag = 0;
  WallChangeflag = 0;
  OutLineFDraw = 0;
  BGflag = 0;
  BGDrawflag = 0;
  v11 = get_gameObject(BGImage);
  Destroy_27360000(v11);
  v12 = Find("FieldFilter", 0);
  if (op_Inequality(v12, 0, 0) && !get_activeSelf(v12))
    SetActive(v12, 1, 0);
  if (op_Inequality(pModelObj, 0, 0))
  {
    v18 = pModelObj;
    Destroy_27360000(v18);
    pModelObj = 0;
  }
  SetActive(kernelObject->btldevil, 0, 0);
  Remove("PBMESSAGE", 0);
  ButtonGuideDispOff();
  ClearoPB_UI();
  return 0;
}

// 0x1662910
dds3ProcessFunc_t *deleteMoveBlock(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  u64 *image;
  s64 v10;
  char *v11;
  s64 *v12;
  pbGroupData_t_o **p_byval_arg;
  s32 name_low;
  pbGroupData_t_o *v17;
  s64 v18;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_o *core;
  u64 max_length_low;
  s16 x;
  struct pbBlockData_t_array *v23;
  s16 v25;
  s16 v27;
  s64 v28;
  u32 grpID;
  UnityEngine_Object_o *pMBlk_GameObj;
  pbGame_c *v35;
  pbGroupData_t_o *v39;
  struct pbProcHandle_t_o *started;
  char *v44;
  s64 *v45;
  u64 v46[2];
  char *v47;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v46);
    if ((v46[0] & 1) != 0)
      v44 = v47;
    else
      v44 = v46 + 1;
    v45 = sub_8C4940(v44);
  }
  v8 = workdata[2].klass;
  if (v8)
  {
    image = v8->_1.image;
    if (*(v8->_1.image + 288) < v10 || *(image[25] + 8 * v10 - 8) != pbMove_t)
    {
      sub_8FC2C0(image[8], pbMove_t, v46);
      if ((v46[0] & 1) != 0)
        v11 = v47;
      else
        v11 = v46 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  p_byval_arg = &v8->_1.byval_arg;
  *(v8->_1.byval_arg.data + 4) = 0;
  MRBlockDrawflag = 0;
  name_low = SLOWORD(v8->_1.name);
  if (name_low == 4)
  {
    SetCameraQuake(30, 80);
    pbPushRecord(&record);
    v17 = *p_byval_arg;
    if ((*p_byval_arg)->num >= 1)
    {
      v18 = 4;
      do
      {
        blk = v17->blk;
        core = v17->core;
        max_length_low = LODWORD(blk->max_length);
        x = core->x;
        v23 = blk;
        v25 = *(*(&blk->obj.klass + v18) + 18LL);
        v27 = *(*(&v23->obj.klass + v18) + 20LL) + core->y;
        pb_General__SET_MAP_HALL_((v25 + x), v27, 0, 0);
        v17 = *p_byval_arg;
        v28 = v18 - 3;
        ++v18;
      }
      while (v28 < (*p_byval_arg)->num);
    }
    grpID = v17->grpID;
    pbReleaseGroupDB(&blockDB, grpID);
    moveB = 0;
    pbBlkDalateflag = 1;
    mBlk_Resetflag = 1;
    changeAutLine = 1;
    --mBlk_grpCnt;
    mBlk_grpID = 0;
    mBlk_grpIDCnt = 0;
    NBlkDrawflag = 0;
    StageDrawflag = 0;
    MBlkFallflag = 1;
    Destroy_27360000(pMBlk_GameObj);
    MoveBlkFallflag = 1;
    if ((v35->_2.bitflags2 & 2) != 0)
    {
LABEL_43:
    }
  }
  else
  {
    setMoveBlockData(p_byval_arg, name_low);
    if (hallCheck(p_byval_arg) == 1)
    {
      v39 = *p_byval_arg;
      started = pbStartMoveBlock(0, v39, 4);
      moveB = started;
      if ((v35->_2.bitflags2 & 2) != 0)
        goto LABEL_43;
    }
    else
    {
      pbPushRecord(&record);
      moveB = 0;
      if ((v35->_2.bitflags2 & 2) != 0)
        goto LABEL_43;
    }
  }
  MRblockAutLine = 1;
  outlineDrawflag = 0;
  return 0;
}

// 0x1661a20
dds3ProcessFunc_t *deleteMoveChar(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  struct System_Int16_array_array *pbMoveDir;
  System_Int16_array *v19;
  struct System_Int16_array_array *v21;
  f32 v22;
  s16 v23;
  System_Int16_array *v25;
  s16 v27;
  f32 v28;
  struct pbProcHandle_t_array *v31;
  s64 v32;
  s32 v35;
  s32 v36;
  struct pbProcHandle_t_o *goal;
  s32 v40;
  struct pbProcHandle_t_array *v58;
  s64 v59;
  char *v63;
  s64 *v64;
  u64 v65[2];
  char *v66;
  s16 y[2];
  s16 x;

  x = 0;
  y[0] = 0;
  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v65);
    if ((v65[0] & 1) != 0)
      v63 = v66;
    else
      v63 = v65 + 1;
    v64 = sub_8C4940(v63);
  }
  v7 = workdata[2].klass;
  if (v7)
  {
    image = v7->_1.image;
    if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbMove_t)
    {
      sub_8FC2C0(image[8], pbMove_t, v65);
      if ((v65[0] & 1) != 0)
        v10 = v66;
      else
        v10 = v65 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  x = 0;
  y[0] = 0;
  v19 = pbMoveDir->m_Items[SLOWORD(v7->_1.name)];
  v21 = pbMoveDir;
  v22 = *&v7->_1.namespaze;
  v23 = v19->m_Items[0];
  v25 = v21->m_Items[SLOWORD(v7->_1.name)];
  v27 = v25->m_Items[1];
  v28 = *&v7->_1.namespaze;
  else if (current_char >= LODWORD(mychar->max_length))
  {
    goto LABEL_29;
  }
  pbMoveMyCharcter2(&mychar->m_Items[current_char], v23 * v22, v27 * v28);
  v31 = mychar;
  v32 = current_char;
  pbGetMyCharcterPos2(&v31->m_Items[v32], &x, y);
  v35 = x;
  v36 = y[0];
  if (v35 != goal->x)
    goto LABEL_74;
  if (v36 != goal->y)
  {
LABEL_74:
      goto LABEL_89;
    goto LABEL_75;
  }
  v40 = FindId(1, "JYAKYO02_SE09");
  p2sdPlaySE(v40);
  else if (getCharacterNum(pbGame) <= 1)
  {
    goto LABEL_51;
  }
  v58 = mychar;
  v59 = current_char;
  pbDispMyCharacter(&v58->m_Items[v59], 0);
  changeCharacter();
  {
LABEL_75:
  }
LABEL_89:
  moveC = 0;
  return 0;
}

// 0x1665320
dds3ProcessFunc_t *deleteRoundAutoCamera(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s16 v9;
  s32 v10;
  f32 cameraAngle;
  f32 v13;
  u64 v15[3];

  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v15);
      if ((v15[0] & 1) != 0)
        v6 = v15[2];
      else
        v6 = v15 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if ((v9 & 0x200) != 0)
  {
    v10 = v9 & 0x200;
  }
  else
  {
    v10 = 0;
  }
  if (cameraAngle > 6.2832)
  {
    v13 = cameraAngle + -6.2832;
LABEL_28:
    cameraAngle = v13;
    goto LABEL_29;
  }
  if (cameraAngle < 0.0)
  {
    v13 = cameraAngle + 6.2832;
    goto LABEL_28;
  }
LABEL_29:
  pbCameraRotateflag = 0;
  roundCamera = 0;
  return 0;
}

// 0x1663660
dds3ProcessFunc_t *deleteRoundBlock(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  char *v18;
  s64 *v19;
  u64 v20[2];
  char *v21;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v20);
    if ((v20[0] & 1) != 0)
      v18 = v21;
    else
      v18 = v20 + 1;
    v19 = sub_8C4940(v18);
  }
  v7 = workdata[2].klass;
  if (v7)
  {
    image = v7->_1.image;
    if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbMove_t)
    {
      sub_8FC2C0(image[8], pbMove_t, v20);
      if ((v20[0] & 1) != 0)
        v10 = v21;
      else
        v10 = v20 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  pbPushRecord(&record);
  setRoundBlockData(&v7->_1.byval_arg, SLOWORD(v7->_1.name));
  *(v7->_1.byval_arg.data + 4) = 0;
  moveB = 0;
  changeAutLine = 1;
  MRblockAutLine = 1;
  MRBlockDrawflag = 0;
  return 0;
}

// 0x1665a50
dds3ProcessFunc_t *deleteViewModeCamera(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v10[3];

  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  moveViewCamera = 0;
  return 0;
}

// 0x165f770
dds3ProcessFunc_t *game(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v8;
  dds3ProcessID_t_o *scr_msg;
  pbProcHandle_t_o *CurrentProcess;
  u32 speed;
  pbGroupData_t_o *grp;
  pbProcHandle_t_o *v116[3];
  pbProcHandle_t_o *p;

  p = 0;
  grp = 0;
  speed = 0;
  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v116);
      if ((v116[0] & 1) != 0)
        v6 = v116[2];
      else
        v6 = v116 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p = id->workdata;
  v8 = Allocate(pbGroupData_t);
  pbGroupData_t___ctor(v8);
  grp = v8;
  if (!scr_msg)
    goto LABEL_35;
LABEL_13:
  if (!fclChkMessageDraw(scr_msg))
  {
    scr_msg = 0;
    if (fclChkSignal(0))
    {
      CurrentProcess = pbGetCurrentProcess();
      pb_General__PB_PROC_SEND_MESS(CurrentProcess, 6);
      goto LABEL_84;
    }
    pb_play = 0;
  }
  return 0;
}

// 0x165ad30
s32 gameKey0(void) {
  s32 v3;
  _BOOL8 v5;
  f32 v7;
  s32 KeyAction;
  bool v12;
  u8 v14;
  s32 v16;
  bool v17;

  else if (!DDS3_PADCHECK_PRESS(8))
  {
    goto LABEL_16;
  }
  if (!DDS3_PADCHECK_PRESS(10))
    goto LABEL_16;
LABEL_9:
  v3 = 1;
    goto LABEL_17;
LABEL_10:
LABEL_17:
  v5 = DDS3_PADCHECK_REP(6);
  if (v5)
    goto LABEL_18;
LABEL_20:
  v5 = DDS3_PADCHECK_REP(7);
  if (!v5)
    goto LABEL_34;
LABEL_23:
  if (!v3)
  {
    v14 = 2;
    goto LABEL_54;
  }
  v7 = -0.2;
LABEL_25:
  pbRotateXCamera(v7, v5);
  KeyAction = -1;
    goto LABEL_55;
LABEL_26:
    goto LABEL_55;
  v12 = DDS3_PADCHECK_PRESS(8);
  if (v3)
    goto LABEL_61;
LABEL_56:
  if (v12)
  {
    v16 = -1;
    goto LABEL_70;
  }
LABEL_61:
  v17 = DDS3_PADCHECK_PRESS(10);
  if (!v3 && v17)
  {
    v16 = 1;
LABEL_70:
    pbRoundCamera(v16);
  }
  return KeyAction;
}

// 0x165b440
s32 gameKey1(void) {
  UnityEngine_GameObject_o *oPB_UI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_GameObject_o *gameObject;
  s32 Id;
  struct UnityEngine_Vector4_array *cameraWk;
  struct UnityEngine_Vector4_array *v17;
  pbProcHandle_t_o *moveViewCamera;
  s32 v26;
  s32 v29;
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  struct UnityEngine_Vector4_array *v35;
  struct UnityEngine_Vector4_array *v37;
  u8 v42;
  s32 KeyAction;
  UnityEngine_Transform_o *v48;
  UnityEngine_Component_o *v49;
  UnityEngine_GameObject_o *v50;
  Il2CppObject *Component_object;
  u64 v54;
  s32 v55;
  struct System_Int16_array_array *pbMoveDir;
  System_Int16_array *v58;
  s32 gameKey1_x;
  struct System_Int16_array_array *v63;
  System_Int16_array *v64;
  s16 v68;
  struct System_Int16_array_array *v69;
  System_Int16_array *v71;
  struct System_Int16_array_array *v74;
  s64 v75;
  System_Int16_array *v77;
  s32 gameKey1_y;
  struct System_Int16_array_array *v87;
  System_Int16_array *v89;
  s32 v94;
  struct System_Int16_array_array *v95;
  System_Int16_array *v97;
  s16 v102;
  struct System_Int16_array_array *v103;
  System_Int16_array *v105;
  struct System_Int16_array_array *v108;
  s64 pbCameraWorkDir;
  System_Int16_array *v111;
  s16 v114;
  s32 v115;
  struct pbGame_StaticFields *v116;
  u32 v117;
  s32 KeyMode;
  s32 v121;
  s32 v122;
  s32 v127;
  s32 v133;
  UnityEngine_GameObject_o *MainCamera;
  UnityEngine_GameObject_o *RenderCamera;
  pbGame_c *v139;
  f32 y;
  f32 x;
  s16 v166;
  s32 v167;
  struct pbGame_StaticFields **p_static_fields;
  s32 v170;
  s32 v172;
  s32 pb_cdir;
  struct pbGame_StaticFields *v174;
  struct pbGame_StaticFields *v175;
  s32 v176;
  struct pbGame_StaticFields *v184;
  s32 v185;
  UnityEngine_GameObject_o *v187;
  UnityEngine_Transform_o *v189;
  UnityEngine_GameObject_o *v193;
  UnityEngine_Transform_o *v194;

LABEL_7:
  transform = get_transform(oPB_UI, 0);
  v5 = Find(transform, "pzlscroll", 0);
  gameObject = get_gameObject(v5);
  else if (!DDS3_PADCHECK_TRIG(2))
  {
    goto LABEL_83;
  }
  Id = FindId(1, "JYAKYO02_SE08");
  p2sdPlaySE(Id);
  pbScrollCameraPosMovXbup = 0;
  pbScrollCameraPosMovYbup = 0;
  if (cameraWk_flg)
  {
    pbSetMapCursorFlag(&mapCursor, 0);
    SDF_VU0__COPYVECTOR(&dds3CameraEyePos, cameraWk->m_Items[0]);
    v17 = cameraWk;
    SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, v17->m_Items[1]);
    cameraWk_flg = 0;
    SetActive(gameObject, 0, 0);
    pb_General__PB_PROC_SEND_MESS(moveViewCamera, 5);
      goto LABEL_84;
    goto LABEL_40;
  }
  pbGetMyCharcterPos2(&mychar->m_Items[current_char], &gameKey1_x, &gameKey1_y);
  v35 = cameraWk;
  SDF_VU0__COPYVECTOR(v35->m_Items, dds3CameraEyePos);
  v37 = cameraWk;
  SDF_VU0__COPYVECTOR(&v37->m_Items[1], dds3CameraTargetPos);
  cameraWk_flg = 1;
  SetActive(gameObject, 1, 0);
  moveViewCamera = pbStartViewModeCamera(0);
LABEL_83:
    goto LABEL_84;
LABEL_40:
LABEL_84:
  if (!DDS3_PADCHECK_TRIG(3))
    goto LABEL_85;
LABEL_42:
  else
  {
    if (pbCameraRotateflag)
      goto LABEL_85;
  }
  if (pbChangeCameraMovflag)
  {
LABEL_85:
      goto LABEL_88;
    goto LABEL_86;
  }
  v26 = FindId(1, "JYAKYO02_SE08");
  p2sdPlaySE(v26);
  degree_mode ^= 2u;
  degree_mode |= 1u;
  if (pbViewChangeflag)
  {
    v29 = 0;
  }
  else
  {
    v29 = 1;
  }
  pbViewChangeflag = v29;
  pb_cdirflag = 0;
  if (cameraWk_flg == 1)
  {
    pbChangeInitPosflag = 1;
  }
  pbChangeCameraMovflag = 1;
  {
LABEL_86:
  }
LABEL_88:
  if (DDS3_PADCHECK_PRESS(6))
  {
    v42 = 0;
    goto LABEL_119;
  }
  else if (DDS3_PADCHECK_PRESS(7))
  {
    goto LABEL_96;
  }
  else if (DDS3_PADCHECK_PRESS(4))
  {
    goto LABEL_106;
  }
  if (!DDS3_PADCHECK_PRESS(5))
  {
    KeyAction = -1;
      goto LABEL_122;
    goto LABEL_120;
  }
  v42 = 1;
LABEL_119:
  KeyAction = pbGetKeyAction(v42);
    goto LABEL_122;
LABEL_120:
LABEL_122:
  if (!cameraWk_flg)
    goto LABEL_247;
  ButtonGuideDispSet("PZL02", 0, 0, 90);
  v48 = get_transform(oPB_UI, 0);
  v49 = Find(v48, "pzlscroll", 0);
  v50 = get_gameObject(v49);
  Component_object = GetComponent_object_(v50);
  Play_8766576(Component_object, "pzlscroll");
  *(*(v54 + 184) + 260LL) = KeyAction;
  if (KeyAction != -1)
  {
    v55 = *(*(v54 + 184) + 424LL);
    v58 = pbMoveDir->m_Items[KeyAction];
    if (v58->m_Items[0] + v55 < 0)
      goto LABEL_169;
    v63 = pbMoveDir;
    v64 = v63->m_Items[KeyAction];
    if (v64->m_Items[0] + gameKey1_x > 19)
    {
LABEL_169:
      {
LABEL_170:
        v87 = pbMoveDir;
        v89 = v87->m_Items[KeyAction];
        if (v89->m_Items[1] + gameKey1_y >= 0)
        {
          v94 = gameKey1_y;
          v95 = pbMoveDir;
          v97 = v95->m_Items[KeyAction];
          if (v97->m_Items[1] + v94 <= 19)
          {
            v102 = gameKey1_y;
            v103 = pbMoveDir;
            v105 = v103->m_Items[KeyAction];
            gameKey1_y = v105->m_Items[1] + v102;
            v108 = pbMoveDir;
            v111 = v108->m_Items[pbCameraWorkDir];
            pbScrollCameraPosMovY = 10 * v111->m_Items[1];
          }
        }
        pbSetGameCamera4(gameKey1_x, gameKey1_y);
        goto LABEL_208;
      }
    }
    else
    {
      v68 = gameKey1_x;
      v69 = pbMoveDir;
      v71 = v69->m_Items[KeyAction];
      gameKey1_x = v71->m_Items[0] + v68;
      v74 = pbMoveDir;
      v75 = pbCameraWorkDir;
      v77 = v74->m_Items[v75];
      pbScrollCameraPosMovX = 10 * v77->m_Items[0];
        goto LABEL_170;
    }
    goto LABEL_170;
  }
LABEL_208:
  v114 = *(v54 + 294);
  if ((v114 & 0x200) != 0)
  {
    v115 = v114 & 0x200;
  }
  else
  {
    v115 = 0;
  }
  v116 = *(v54 + 184);
  v117 = gameKey1_y < 19;
  if (!v115)
  {
    if (gameKey1_x >= 1)
      v117 |= 2u;
    goto LABEL_222;
  }
  if (*(v54 + 216))
  {
    if (gameKey1_x >= 1)
      v117 |= 2u;
    goto LABEL_226;
  }
  if (gameKey1_x >= 1)
    v117 |= 2u;
  {
LABEL_222:
    if (gameKey1_y >= 1)
      v117 |= 4u;
    goto LABEL_224;
  }
LABEL_226:
  if (!*(v54 + 216))
  {
    if (gameKey1_y >= 1)
      v117 |= 4u;
    {
        goto LABEL_230;
      goto LABEL_273;
    }
LABEL_224:
    if (gameKey1_x <= 18)
      v117 |= 8u;
    goto LABEL_234;
  }
  if (gameKey1_y >= 1)
    v117 |= 4u;
  if (!*(v54 + 216))
  {
LABEL_230:
    if (gameKey1_x <= 18)
      v117 |= 8u;
      goto LABEL_234;
    goto LABEL_276;
  }
LABEL_273:
  if (gameKey1_x <= 18)
    v117 |= 8u;
  if (*(v54 + 216))
    goto LABEL_234;
LABEL_276:
LABEL_234:
  ScrollArrowDraw(v54);
  KeyMode = pbGetKeyMode();
  if (KeyMode)
  {
    v121 = KeyMode & 1;
    if (KeyMode != 1)
    {
      v122 = v121 - KeyMode;
      do
      {
        v117 = (4 * v117) & 8 | (((8 * (v117 & 1)) | (v117 >> 1)) >> 1);
        v122 += 2;
      }
      while (v122);
    }
    if (v121)
      v117 = (8 * (v117 & 1)) | (v117 >> 1);
  }
  pbSetMapCursorFlag(&mapCursor, v117);
  KeyAction = -1;
LABEL_247:
  else if (!DDS3_PADCHECK_TRIG(8))
  {
    goto LABEL_278;
  }
  else
  {
    if (pbCameraRotateflag)
      goto LABEL_278;
  }
  if (!pbChangeCameraMovflag)
  {
    v127 = FindId(1, "JYAKYO02_SE08");
    p2sdPlaySE(v127);
    pbRoundCamera(-1);
    pbCameraRotateflag = 1;
    goto LABEL_301;
  }
LABEL_278:
  else if (!DDS3_PADCHECK_TRIG(10))
  {
    goto LABEL_301;
  }
  else
  {
    if (pbCameraRotateflag)
      goto LABEL_301;
  }
  if (!pbChangeCameraMovflag)
  {
    v133 = FindId(1, "JYAKYO02_SE08");
    p2sdPlaySE(v133);
    pbRoundCamera(1);
    pbCameraRotateflag = 1;
  }
LABEL_301:
  MainCamera = GetMainCamera(kernelObject);
  GetComponent_object_(MainCamera);
  RenderCamera = GetRenderCamera(kernelObject);
  GetComponent_object_(RenderCamera);
  else
  {
    if (pbCameraRotateflag)
      goto LABEL_319;
  }
  else if (!pbChangeCameraMovflag)
  {
    goto LABEL_310;
  }
LABEL_319:
  if (pbChangeCameraMovflag == 1)
    goto LABEL_322;
LABEL_337:
  v166 = *&v139->_2.bitflags1;
  if ((v166 & 0x200) != 0)
  {
    v167 = v166 & 0x200;
    if (pbViewChangeflag)
      goto LABEL_339;
LABEL_352:
    else
    {
      if (pb_cdir)
      {
LABEL_355:
        else if (pb_cdir == 1)
        {
          goto LABEL_358;
        }
        if (pb_cdir == 2)
        {
          pb_cameraAngle.x = 60.0;
          v174 = *p_static_fields;
          v172 = 1127481344;
        }
        else
        {
          if (pb_cdir != 3)
            goto LABEL_432;
          pb_cameraAngle.x = 60.0;
          v174 = *p_static_fields;
          v172 = 1119092736;
        }
LABEL_419:
        LODWORD(v174->pb_cameraAngle.y) = v172;
        v184 = *p_static_fields;
        v185 = 1125515264;
LABEL_430:
        LODWORD(v184->pbBG_cameraAngle.x) = v185;
LABEL_431:
        LODWORD((*p_static_fields)->pbBG_cameraAngle.y) = v172;
        goto LABEL_432;
      }
    }
    pb_cameraAngle.x = 60.0;
    (*p_static_fields)->pb_cameraAngle.y = 0.0;
    v175 = *p_static_fields;
    v176 = 1125515264;
    goto LABEL_382;
  }
  v167 = 0;
  if (!pbViewChangeflag)
    goto LABEL_352;
LABEL_339:
  else
  {
    v170 = pb_cdir;
    if (v170)
      goto LABEL_342;
  }
  pb_cameraAngle.x = 90.0;
  (*p_static_fields)->pb_cameraAngle.y = 0.0;
  v175 = *p_static_fields;
  v176 = 1127481344;
LABEL_382:
  LODWORD(v175->pbBG_cameraAngle.x) = v176;
  (*p_static_fields)->pbBG_cameraAngle.y = 0.0;
  if ((v139->_2.bitflags2 & 2) == 0)
    goto LABEL_433;
LABEL_383:
LABEL_433:
  if (pbChangeCameraMovflag == 1)
    goto LABEL_434;
LABEL_385:
  else if (pbViewChangeflag != 1)
  {
    goto LABEL_388;
  }
LABEL_434:
  v187 = get_gameObject(pb_camera);
  v189 = get_transform(v187, 0);
  set_localEulerAngles(v189, pbRotateMov);
  v193 = get_gameObject(BGImage);
  v194 = get_transform(v193, 0);
  set_localEulerAngles(v194, pbBGRotateMov);
  {
LABEL_389:
  }
LABEL_444:
  pbChangeCameraMovflag = 0;
  return KeyAction;
}

// 0x165ea60
s32 gameKey2(void) {
  s32 v3;
  _BOOL8 v5;
  f32 v7;
  s32 KeyAction;
  _BOOL8 v12;
  u8 v14;
  f32 v16;

  else if (!DDS3_PADCHECK_PRESS(8))
  {
    goto LABEL_16;
  }
  if (!DDS3_PADCHECK_PRESS(10))
    goto LABEL_16;
LABEL_9:
  v3 = 1;
    goto LABEL_17;
LABEL_10:
LABEL_17:
  v5 = DDS3_PADCHECK_REP(6);
  if (v5)
    goto LABEL_18;
LABEL_20:
  v5 = DDS3_PADCHECK_REP(7);
  if (!v5)
    goto LABEL_34;
LABEL_23:
  if (!v3)
  {
    v14 = 2;
    goto LABEL_54;
  }
  v7 = -0.2;
LABEL_25:
  pbRotateXCamera(v7, v5);
  KeyAction = -1;
    goto LABEL_55;
LABEL_26:
    goto LABEL_55;
  v12 = DDS3_PADCHECK_PRESS(8);
  if (v3)
    goto LABEL_58;
LABEL_56:
  if (v12)
  {
    v16 = 0.2;
LABEL_64:
    pbRotateYCamera(v16, v12);
    return KeyAction;
  }
LABEL_58:
  v12 = DDS3_PADCHECK_PRESS(10);
  if (v12 && v3)
  {
    v16 = -0.2;
    goto LABEL_64;
  }
  return KeyAction;
}

// 0x165ed80
u32 getCharacterNum(void) {
  u64 v2;
  u32 v3;
  s64 v4;
  struct pbProcHandle_t_array *mychar;

  v2 = 0;
  v3 = 0;
  v4 = 32;
  {
LABEL_8:
  }
  while (v2 < pbWk->bup->pchar_num)
  {
    else if (v2 >= LODWORD(mychar->max_length))
    {
      goto LABEL_17;
    }
    if (pbMyCharacterDispStat((mychar + v4), 0))
      ++v3;
    ++v2;
    v4 += 8;
      goto LABEL_8;
  }
  return v3;
}

// 0x1659b70
s8 goalHitCheck(s16 x, s16 y) {
  struct pbProcHandle_t_o *goal;

  if (goal->x == x)
  {
    else if (goal->y == y)
    {
      return 1;
    }
  }
  return 0;
}

// 0x165f630
s8 hallCheck(pbGroupData_t **grp) {
  pbGroupData_t_o *v3;
  s32 num;
  struct pbBlockData_t_o *core;
  s32 x;
  s32 y;
  s64 i;
  struct pbBlockData_t_array *blk;
  s64 v10;
  s32 v12;
  s32 v13;
  s32 v14;
  s64 v15;

  v3 = *grp;
  num = (*grp)->num;
  if (num < 1)
  {
    v10 = 0;
  }
  else
  {
    core = v3->core;
    x = core->x;
    y = core->y;
    for (i = 4; ; ++i)
    {
      blk = v3->blk;
      v10 = i - 4;
      v12 = *(*(&blk->obj.klass + i) + 18LL);
      v13 = *(*(&v3->blk->obj.klass + i) + 20LL);
      v14 = pb_General__GET_MAP_HALL_(v12 + x, v13 + y);
      v3 = *grp;
      LOWORD(num) = (*grp)->num;
      if (!v14)
        break;
      v15 = i + 1;
      if (i - 3 >= (*grp)->num)
      {
        v10 = v15 - 4;
        return v10 >= num;
      }
    }
  }
  return v10 >= num;
}

// 0x165f110
u32 hitCheck(s32 dir, pbGroupData_t **grp) {
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  s32 v12;
  struct System_Int16_array_array *pbMoveDir;
  System_Int16_array *v16;
  struct System_Int16_array_array *v18;
  s32 v19;
  s16 v20;
  System_Int16_array *v22;
  s16 v24;
  s32 v25;
  s32 v26;
  struct pbProcHandle_t_o *goal;
  u32 result;
  s64 v30;
  s16 v31;
  struct System_UInt16_array *mapdata;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  struct System_UInt16_array *v41;
  Il2CppArrayBounds *v42;
  il2cpp_array_size_t v44;
  s32 v47;
  u32 v50;
  u32 v53;
  s16 y[2];
  s16 x;

  x = 0;
  y[0] = 0;
  *grp = 0;
  else if (current_char >= LODWORD(mychar->max_length))
  {
    goto LABEL_9;
  }
  pbGetMyCharcterPos2(&mychar->m_Items[current_char], &x, y);
  v12 = x;
  v16 = pbMoveDir->m_Items[dir];
  v18 = pbMoveDir;
  v19 = v16->m_Items[0];
  v20 = y[0];
  v22 = v18->m_Items[dir];
  v24 = v22->m_Items[1];
  v25 = x;
  v26 = y[0];
  if (v25 == goal->x)
  {
    else if (v26 == goal->y)
    {
      return 6;
    }
  }
  LODWORD(v30) = v19 + v12;
  if (v30 << 16 > 0x130000u)
    return 1;
  v31 = v24 + v20;
  if ((v31 >> 2) > 4u)
    return 1;
  if (charHitCheck(v31, v30) == 1)
    return 1;
  if (pb_General__GET_MAP_HALL_(v31, v30))
    return 1;
  mapdata = pbWk->bup->mapdata;
  bounds = mapdata->bounds;
  length = bounds[1].length;
  if (mapdata->m_Items[v31 + length * v30] == 0x2000)
    return 1;
  v41 = pbWk->bup->mapdata;
  v42 = v41->bounds;
  v44 = v42[1].length;
  if (v41->m_Items[v31 + v44 * v30] == 2048)
    return 1;
  v47 = pb_General__GET_MAP_BLK_(v31, v30);
  result = 0;
  switch (v47)
  {
    case 0:
      return result;
    case 2:
    case 3:
      v50 = pb_General__GET_MAP_GRPID_(v31, v30);
      result = pushCheck(dir, v50, grp);
      break;
    case 4:
      result = 2;
      break;
    case 5:
      v53 = pb_General__GET_MAP_GRPID_(v31, v30);
      result = roundCheck(dir, v53, grp);
      break;
    default:
      return 1;
  }
  return result;
}

// 0x1662570
dds3ProcessFunc_t *moveBlock(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  u64 *image;
  s64 v8;
  char *v9;
  s64 *v10;
  s64 v11;
  struct System_Single_array_array *move_count;
  s64 v17;
  struct System_Single_array_array *v18;
  s64 v21;
  struct System_Single_array_array *v22;
  char *v28;
  s64 *v29;
  u64 v30[2];
  char *v31;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v30);
    if ((v30[0] & 1) != 0)
      v28 = v31;
    else
      v28 = v30 + 1;
    v29 = sub_8C4940(v28);
  }
  v6 = workdata[2].klass;
  if (v6)
  {
    image = v6->_1.image;
    if (*(v6->_1.image + 288) < v8 || *(image[25] + 8 * v8 - 8) != pbMove_t)
    {
      sub_8FC2C0(image[8], pbMove_t, v30);
      if ((v30[0] & 1) != 0)
        v9 = v31;
      else
        v9 = v30 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  if (HIDWORD(v6->_1.name) > 3)
  {
    id->func_ans = -1;
  }
  else
  {
    v11 = v6->_1.byval_arg.data + 64;
    sub_854710(v11, 0);
    sub_854930(v11, 0);
    v17 = v6->_1.byval_arg.data + 64;
    sub_854710(v17, 1u);
    v18 = move_count;
    sub_854930(v17, 1u);
    v21 = v6->_1.byval_arg.data + 64;
    sub_854710(v21, 2u);
    v22 = move_count;
    sub_854930(v21, 2u);
    ++HIDWORD(v6->_1.name);
    MRBlockDrawflag = 0;
  }
  return 0;
}

// 0x1661620
dds3ProcessFunc_t *moveChar(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  struct System_Single_array_array *move_count;
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  System_Single_array *v18;
  struct System_Single_array_array *v20;
  f32 v21;
  f32 v22;
  System_Single_array *v24;
  f32 v26;
  f32 v27;
  struct pbGame_cameraFuncDelegate_array *cameraFunc;
  s64 camera_mode;
  struct pbGame_cameraFuncDelegate_array *v37;
  s64 v38;
  u32 v40;
  char *v42;
  s64 *v43;
  u64 v44[2];
  char *v45;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v44);
    if ((v44[0] & 1) != 0)
      v42 = v45;
    else
      v42 = v44 + 1;
    v43 = sub_8C4940(v42);
  }
  v7 = workdata[2].klass;
  if (v7)
  {
    image = v7->_1.image;
    if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbMove_t)
    {
      sub_8FC2C0(image[8], pbMove_t, v44);
      if ((v44[0] & 1) != 0)
        v10 = v45;
      else
        v10 = v44 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  if (HIDWORD(v7->_1.name) <= 3)
  {
    v18 = move_count->m_Items[SLOWORD(v7->_1.name)];
    v20 = move_count;
    v21 = v18->m_Items[0];
    v22 = *&v7->_1.namespaze;
    v24 = v20->m_Items[SLOWORD(v7->_1.name)];
    v26 = v24->m_Items[2];
    v27 = *&v7->_1.namespaze;
    pbMoveMyCharcter(&mychar->m_Items[current_char], v21 * v22, v26 * v27);
  }
  camera_mode = pbWk->camera_mode;
  if (cameraFunc->m_Items[camera_mode])
  {
    v37 = cameraFunc;
    v38 = pbWk->camera_mode;
    Invoke(v37->m_Items[v38], 0);
  }
  v40 = HIDWORD(v7->_1.name) + 1;
  HIDWORD(v7->_1.name) = v40;
  if (v40 >= 4)
    id->func_ans = -1;
  return 0;
}

// 0x1667f30
s8 pbCheckPreviousRecord(void) {
  return pbCheckPopRecord(&record);
}

// 0x1643440
void pbGetCameraParam(sdfVector4_t out) {
  UnityEngine_Vector4_o v3;

  v3 = out;
  sub_854930(&v3, 0);
  sub_854930(&v3, 1u);
  sub_854930(&v3, 2u);
}

// 0x1668320
dds3ProcessID_t *pbGetMessageScriptProc(void) {
  return scr_msg;
}

// 0x16440d0
void pbGotoNewStage(void) {
  s32 StageNumber;
  UnityEngine_Object_o *v6;
  UnityEngine_Object_o *pBlk_GameObj;
  s32 AllStageClearBit;
  pbProcHandle_t_o *CurrentProcess;
  s64 i;
  u64 v19;
  struct XRD773Unity_CommonMesh_array *pBlk_Mesh;
  UnityEngine_Object_o *v22;
  struct XRD773Unity_CommonMesh_array *v25;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *pMRBlk_Mesh;
  UnityEngine_Object_o *v32;
  struct XRD773Unity_CommonMesh_array *v34;
  UnityEngine_Object_o *v37;

  StageNumber = GetStageNumber();
  if (scr_msg)
  {
    dds3KillProcess(&scr_msg, 0);
    scr_msg = 0;
  }
  if (StageNumber < 0)
  {
    Destroy_27360000(pBlk_GameObj);
    Destroy_27360000(pMRBlk_GameObj);
    AllStageClearBit = GetAllStageClearBit();
    evtBitOn(AllStageClearBit);
    Write("****** CONGRATULATIONS !! ******\n", 0);
    CurrentProcess = pbGetCurrentProcess();
    pb_General__PB_PROC_SEND_MESS(CurrentProcess, 6);
  }
  else
  {
    v6 = pBlk_GameObj;
    Destroy_27360000(v6);
    Destroy_27360000(pMBlk_GameObj);
    Destroy_27360000(pMRBlk_GameObj);
    MBlockStrbup = NewSpecific(string, 0);
    pbLoadSystemData(StageNumber);
  }
  for (i = 4; i != 404; ++i)
  {
    v19 = i - 4;
    v22 = *(&pBlk_Mesh->obj.klass + i);
    if (op_Inequality(v22, 0, 0))
    {
      v25 = pBlk_Mesh;
      gameObject = get_gameObject(*(&v25->obj.klass + i), 0);
      Destroy_27360000(gameObject);
    }
    v32 = *(&pMRBlk_Mesh->obj.klass + i);
    if (op_Inequality(v32, 0, 0))
    {
      v34 = pMRBlk_Mesh;
      v37 = get_gameObject(*(&v34->obj.klass + i), 0);
      Destroy_27360000(v37);
    }
  }
  mBlkStageChangeflag = 1;
}

// 0x1659c50
void pbInitGame(pbProcHandle_t **p, dds3ProcessID_t *id) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v8;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  s32 stage;
  struct System_UInt16_array *exit_pos;
  u32 max_length;
  u16 v21;
  u16 v23;
  u64 *v25;
  u64 *v26;
  u64 v28;
  u64 v29;
  u32 v30;
  s32 v31;
  s64 v33;
  struct pbProcHandle_t_array *mychar;
  pbProcHandle_t_o *v38;
  struct pbProcHandle_t_array *v39;
  struct System_Byte_array *pchar_reg;
  struct pbProcHandle_t_array *v45;
  s64 *inited;
  s64 *v47;
  struct pbProcHandle_t_array *v49;
  struct pbProcHandle_t_array *v53;
  struct System_UInt16_array *pchar_pos;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s16 v59;
  struct System_UInt16_array *v60;
  Il2CppArrayBounds *v61;
  il2cpp_array_size_t v63;
  s16 v65;
  u32 v67;
  struct pbGame_cameraFuncDelegate_array *cameraFunc;
  s64 camera_mode;
  struct pbGame_cameraFuncDelegate_array *v76;
  s64 v77;
  s32 StageScriptLabel;
  s32 v83;
  System_Byte_array *pscript;
  dds3ProcessID_t_o *started;
  UnityEngine_Color_o v93;

  LODWORD(v4[2].klass->_1.typeDefinition) = 0;
  HIDWORD(v4[2].klass->_1.klass) = 2;
  LODWORD(v4[2].klass->_1.image) = 1;
  pbRotateYCamera2(cameraAngle, cameraRadius, cameraDegree);
  transform = get_transform(oPB_UI, 0);
  v8 = Find(transform, "pzlstage/pzlstage_num", 0);
  gameObject = get_gameObject(v8);
  Component_object = GetComponent_object_(gameObject);
  stage = pbWk->stage;
  *&v93.r = 0;
  *&v93.b = 0;
  sub_19EC630(&v93.r, 1.0, 1.0, 1.0, 1.0);
  Set(Component_object, stage + 1, v93, 0, 0);
  clearAutLine = 0;
  cameraWk_flg = 0;
  else if (pbCheckMap(pbEdit))
  {
    return;
  }
  dds3FadeIn2(0x1Eu);
  exit_pos = pbWk->bup->exit_pos;
  max_length = exit_pos->max_length;
  v21 = exit_pos->m_Items[0];
  v23 = pbWk->bup->exit_pos->m_Items[1];
  goal->x = v21;
  goal->y = v23;
  v25 = Allocate(pbExit_t);
  v26 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v26);
  v25[3] = v26;
  _ctor(v25, 0);
  *(v25 + 4) = 1;
  v29 = 0;
  v30 = 0;
  do
  {
    v33 = *(*(v28 + 184) + 24LL);
    if (*(v33 + 8 * v29 + 32))
    {
      v38 = mychar->m_Items[v29];
      pb_General__PB_PROC_SEND_MESS(v38, 5);
      v39 = mychar;
      v39->m_Items[v29] = 0;
    }
    pchar_reg = pbWk->bup->pchar_reg;
    if (pchar_reg->m_Items[v29])
    {
      v45 = mychar;
      inited = pbInitMyCharacterDraw(p, v29, 0);
      v47 = inited;
      v45->m_Items[v30] = v47;
      v49 = mychar;
      pbDispMyCharacter(&v49->m_Items[v30], 1);
      v53 = mychar;
      pchar_pos = pbWk->bup->pchar_pos;
      bounds = pchar_pos->bounds;
      length = bounds[1].length;
      v59 = pchar_pos->m_Items[length * v29];
      v60 = pbWk->bup->pchar_pos;
      v61 = v60->bounds;
      v63 = v61[1].length;
      v65 = v60->m_Items[v63 * v29 + 1];
      pbSetMyCharcterPos2(&v53->m_Items[v30++], v59, v65);
    }
    ++v29;
    v31 = (v67 >> 9) & 1;
  }
  while (v29 != 4);
  updateMotion(v28);
  camera_mode = pbWk->camera_mode;
  if (cameraFunc->m_Items[camera_mode])
  {
    v76 = cameraFunc;
    v77 = pbWk->camera_mode;
    Invoke(v76->m_Items[v77], 0);
  }
  pbClearRecord(&record);
  StageScriptLabel = GetStageScriptLabel();
  if (StageScriptLabel < 0)
  {
    pb_play = 0;
  }
  else
  {
    v83 = StageScriptLabel;
    fclClearSignal(0);
    fclSetVal(0, v83);
    pscript = pbWk->pscript;
    started = scrStartScript2(1006, pscript, 0);
    scr_msg = started;
  }
}

// 0x16669a0
void pbInitGameCamera(void) {
  u32 camera_mode;
  struct UnityEngine_Vector4_array *pbCameraEye;
  struct UnityEngine_Vector4_array *pbCameraTgt;

  camera_mode = pbWk->camera_mode;
  switch (camera_mode)
  {
    case 2u:
      pbSetGameCamera2();
      break;
    case 1u:
      SDF_VU0__COPYVECTOR(&dds3CameraEyePos, pbCameraEye->m_Items[1]);
      SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, pbCameraTgt->m_Items[1]);
      pbSetGameCamera1();
      break;
    case 0u:
      pbSetGameCamera0();
      cameraAngle = 0.0;
      break;
  }
}

// 0x1667fa0
void pbPreviousRecord(void) {
  s32 v3;
  u32 v6;
  pbProcHandle_t_o *blockDB;
  struct pbGame_cameraFuncDelegate_array *cameraFunc;
  s64 camera_mode;
  struct pbGame_cameraFuncDelegate_array *v18;
  s64 v19;

  v3 = pbPopRecord(&record, &mychar, &blockDB);
  if ((v3 & 0x80000000) == 0)
  {
    v6 = v3;
    pbStartErrorDraw(0, 9u, 0x1Eu);
    pb_General__PB_PROC_SEND_MESS(blockDB, 1);
    current_char = v6;
    updateMotion();
    camera_mode = pbWk->camera_mode;
    if (cameraFunc->m_Items[camera_mode])
    {
      v18 = cameraFunc;
      v19 = pbWk->camera_mode;
      Invoke(v18->m_Items[v19], 0);
    }
  }
}

// 0x165b090
void pbRoundCamera(s32 dir) {
  s32 v4;
  struct pbProcHandle_t_o *started;
  pbGame_c *v9;
  struct UnityEngine_Vector3_array *pbcCameraPos;
  pbGame_c *v13;
  struct UnityEngine_Vector3_array *pbCameraPos;
  s32 *static_fields;
  s64 v17;
  u32 *v19;
  s32 v20;
  s32 v21;
  s32 *v23;
  s64 v24;
  u32 *v26;
  s32 v27;
  s32 v28;

  if (dir == -1)
    v4 = 1;
  else
    v4 = -1;
  started = pbStartAutoRoundCamera(0, v4);
  roundCamera = started;
  if (!pbCameraRotateflag)
  {
    if (dir != -1)
    {
      pbRotRKeyAct();
      if (pbViewChangeflag)
      {
        if ((v9->_2.bitflags2 & 2) == 0)
          goto LABEL_42;
      }
      else
      {
        pbcCameraPos = pbCameraPos;
        if ((v9->_2.bitflags2 & 2) == 0)
          goto LABEL_42;
      }
LABEL_42:
      v17 = static_fields[51];
      v19 = (pbcCameraPos + 12 * v17);
      v20 = v19[9];
      v21 = v19[8];
      LODWORD(v19) = v19[10];
      static_fields[82] = v21;
      static_fields[83] = v20;
      static_fields[84] = v19;
      ++pb_cdir;
      if (pb_cdir >= 4)
      {
        pb_cdir = 0;
      }
      return;
    }
    pbRotLKeyAct();
    if (pbViewChangeflag)
    {
      pbCameraPos = pbcCameraPos;
      if ((v13->_2.bitflags2 & 2) == 0)
        goto LABEL_56;
    }
    else
    {
      if ((v13->_2.bitflags2 & 2) == 0)
        goto LABEL_56;
    }
LABEL_56:
    v24 = v23[51];
    v26 = (pbCameraPos + 12 * v24);
    v27 = v26[9];
    v28 = v26[8];
    LODWORD(v26) = v26[10];
    v23[82] = v28;
    v23[83] = v27;
    v23[84] = v26;
    --pb_cdir;
    if (pb_cdir < 0)
    {
      pb_cdir = 3;
    }
  }
}

// 0x1643ff0
void pbRoundStageNext(s16 plevel, s16 pstage) {
  s32 v3;

  v3 = pstage;
}

// 0x1643ef0
void pbRoundStagePrev(s16 plevel, s16 pstage) {
  s16 v6;
  struct pbLevelTable_t_array_array *pbLevelTable;
  pbLevelTable_t_array *v9;
  s16 v10;
  s64 v11;

  if ((pstage - 1) < 0)
  {
    if (((plevel - 1) & 0x8000) != 0)
      v6 = 2;
    else
      v6 = plevel - 1;
    v9 = pbLevelTable->m_Items[v6];
    v10 = 0;
    do
    {
      v11 = v10 + 2LL;
      ++v10;
    }
    while ((v9->m_Items[v11]->stage & 0x80000000) == 0);
  }
}

// 0x16682a0
void pbSetCameraAngle(f32 angle) {
  cameraAngle = angle;
}

// 0x1643a40
void pbSetCameraDegree(f32 degree) {
  cameraDegree = degree;
}

// 0x1643ac0
void pbSetCameraDegreeInit(f32 degree) {
  cameraDegreeInit = degree;
}

// 0x1643500
void pbSetCameraRadius(f32 radius) {
  cameraRadius = radius;
}

// 0x1666f70
void pbSetGameCamera0(void) {
  struct UnityEngine_Vector4_array *pbCameraEye;
  struct UnityEngine_Vector4_array *pbCameraTgt;

  else
  {
    if (!LODWORD(pbCameraEye->max_length))
      goto LABEL_9;
  }
  SDF_VU0__COPYVECTOR(&dds3CameraEyePos, pbCameraEye->m_Items[0]);
  SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, pbCameraTgt->m_Items[0]);
}

// 0x16670c0
void pbSetGameCamera1(void) {
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  struct pbProcHandle_t_array *v9;
  s64 v10;
  struct UnityEngine_Vector4_array *pbCameraTgt;
  struct UnityEngine_Vector4_array *v18;
  struct UnityEngine_Vector4_array *v22;
  struct UnityEngine_Vector4_array *v26;
  UnityEngine_Vector4_o v39;
  UnityEngine_Vector4_o v40;

  *&v40.x = 0;
  *&v40.z = 0;
  *&v39.x = 0;
  *&v39.z = 0;
  if (mychar->m_Items[current_char])
  {
    v9 = mychar;
    v10 = current_char;
    else if (v10 >= LODWORD(v9->max_length))
    {
      goto LABEL_15;
    }
    pbGetMyCharcterPos(&v9->m_Items[v10], &v39);
    sub_854710(&v39, 0);
    sub_854710(&pbCameraTgt->m_Items[1], 0);
    sub_854930(&v39, 0);
    sub_854710(&v39, 1u);
    v18 = pbCameraTgt;
    sub_854710(&v18->m_Items[1], 1u);
    sub_854930(&v39, 1u);
    sub_854710(&v39, 2u);
    v22 = pbCameraTgt;
    sub_854710(&v22->m_Items[1], 2u);
    sub_854930(&v39, 2u);
    sub_854710(&v39, 3u);
    v26 = pbCameraTgt;
    sub_854710(&v26->m_Items[1], 3u);
    sub_854930(&v39, 3u);
    sub_854710(&dds3CameraEyePos, 0);
    sub_854710(&dds3CameraTargetPos, 0);
    sub_854710(&v39, 0);
    sub_854930(&v40, 0);
    sub_854710(&dds3CameraEyePos, 1u);
    sub_854710(&dds3CameraTargetPos, 1u);
    sub_854710(&v39, 1u);
    sub_854930(&v40, 1u);
    sub_854710(&dds3CameraEyePos, 2u);
    sub_854710(&dds3CameraTargetPos, 2u);
    sub_854710(&v39, 2u);
    sub_854930(&v40, 2u);
    sub_854710(&dds3CameraEyePos, 3u);
    sub_854710(&dds3CameraTargetPos, 3u);
    sub_854710(&v39, 3u);
    sub_854930(&v40, 3u);
    SDF_VU0__COPYVECTOR(&dds3CameraEyePos, v40);
    SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, v39);
  }
}

// 0x1667640
void pbSetGameCamera2(void) {
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  struct pbProcHandle_t_array *v9;
  s64 v10;
  struct UnityEngine_Vector4_array *pbCameraTgt;
  struct UnityEngine_Vector4_array *v18;
  struct UnityEngine_Vector4_array *v22;
  struct UnityEngine_Vector4_array *v26;
  UnityEngine_Vector4_o v39;
  UnityEngine_Vector4_o v40;

  *&v40.x = 0;
  *&v40.z = 0;
  *&v39.x = 0;
  *&v39.z = 0;
  if (mychar->m_Items[current_char])
  {
    v9 = mychar;
    v10 = current_char;
    else if (v10 >= LODWORD(v9->max_length))
    {
      goto LABEL_15;
    }
    pbGetMyCharcterPos(&v9->m_Items[v10], &v39);
    sub_854710(&v39, 0);
    sub_854710(&pbCameraTgt->m_Items[1], 0);
    sub_854930(&v39, 0);
    sub_854710(&v39, 1u);
    v18 = pbCameraTgt;
    sub_854710(&v18->m_Items[1], 1u);
    sub_854930(&v39, 1u);
    sub_854710(&v39, 2u);
    v22 = pbCameraTgt;
    sub_854710(&v22->m_Items[1], 2u);
    sub_854930(&v39, 2u);
    sub_854710(&v39, 3u);
    v26 = pbCameraTgt;
    sub_854710(&v26->m_Items[1], 3u);
    sub_854930(&v39, 3u);
    sub_854710(&dds3CameraEyePos, 0);
    sub_854710(&dds3CameraTargetPos, 0);
    sub_854710(&v39, 0);
    sub_854930(&v40, 0);
    sub_854710(&dds3CameraEyePos, 1u);
    sub_854710(&dds3CameraTargetPos, 1u);
    sub_854710(&v39, 1u);
    sub_854930(&v40, 1u);
    sub_854710(&dds3CameraEyePos, 2u);
    sub_854710(&dds3CameraTargetPos, 2u);
    sub_854710(&v39, 2u);
    sub_854930(&v40, 2u);
    sub_854710(&dds3CameraEyePos, 3u);
    sub_854710(&dds3CameraTargetPos, 3u);
    sub_854710(&v39, 3u);
    sub_854930(&v40, 3u);
    SDF_VU0__COPYVECTOR(&dds3CameraEyePos, v40);
    SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, v39);
  }
}

// 0x1667bc0
void pbSetGameCamera3(void) {
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  struct pbProcHandle_t_array *v9;
  s64 v10;
  struct pbProcHandle_t_array *v13;
  s64 v14;
  s32 MyCharcterRot;
  struct System_Int16_array_array *pbMoveDir;
  struct System_Int16_array_array *v22;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o dst;

  *&dst.x = 0;
  *&dst.z = 0;
  *&v27.x = 0;
  *&v27.z = 0;
  if (mychar->m_Items[current_char])
  {
    v9 = mychar;
    v10 = current_char;
    else if (v10 >= LODWORD(v9->max_length))
    {
      goto LABEL_15;
    }
    pbGetMyCharcterPos(&v9->m_Items[v10], &v27);
    SDF_VU0__COPYVECTOR(&dst, v27);
    v13 = mychar;
    v14 = current_char;
    MyCharcterRot = pbGetMyCharcterRot(&v13->m_Items[v14]);
    sub_854710(&dst, 0);
    sub_854930(&dst, 0);
    sub_854710(&dst, 2u);
    v22 = pbMoveDir;
    sub_854930(&dst, 2u);
    sub_854710(&dst, 1u);
    sub_854930(&dst, 1u);
    sub_854710(&v27, 1u);
    sub_854930(&v27, 1u);
    SDF_VU0__COPYVECTOR(&dds3CameraEyePos, dst);
    SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, v27);
  }
}

// 0x165d1a0
void pbSetGameCamera4(s16 x, s16 y) {
  UnityEngine_GameObject_o *RenderCamera;
  struct UnityEngine_Vector4_array *pbCameraTgt;
  struct UnityEngine_Vector4_array *v11;
  struct UnityEngine_Vector4_array *v15;
  struct UnityEngine_Vector4_array *v19;
  pbGame_c *v30;
  s32 v31;
  s32 v32;
  UnityEngine_Transform_o *transform;
  f32 v36;
  s32 pbScrollCameraPosMovX;
  UnityEngine_Transform_o *v38;
  f32 v39;
  UnityEngine_Transform_o *v40;
  s32 pbScrollCameraPosMovY;
  f32 v44;
  UnityEngine_Transform_o *v45;
  f32 v49;
  f32 v51;
  s32 v52;
  f32 v53;
  f32 v54;
  f32 v56;
  u32 v57;
  f32 v60;
  f32 z;
  s64 v62;
  f32 v63;
  s64 v64;
  f32 v65;
  UnityEngine_Vector4_o v66;
  UnityEngine_Vector4_o v67;

  *&v67.x = 0;
  *&v67.z = 0;
  *&v66.x = 0;
  *&v66.z = 0;
  RenderCamera = GetRenderCamera(kernelObject);
  GetComponent_object_(RenderCamera);
  v65 = 0.0;
  v64 = 0;
  sub_8524C0(&v64, 0.0, 0.0, 0.0);
  sub_854930(&v66, 0);
  sub_854930(&v66, 2u);
  sub_854710(&v66, 0);
  sub_854710(&pbCameraTgt->m_Items[1], 0);
  sub_854930(&v66, 0);
  sub_854710(&v66, 1u);
  v11 = pbCameraTgt;
  sub_854710(&v11->m_Items[1], 1u);
  sub_854930(&v66, 1u);
  sub_854710(&v66, 2u);
  v15 = pbCameraTgt;
  sub_854710(&v15->m_Items[1], 2u);
  sub_854930(&v66, 2u);
  sub_854710(&v66, 3u);
  v19 = pbCameraTgt;
  sub_854710(&v19->m_Items[1], 3u);
  sub_854930(&v66, 3u);
  sub_854710(&dds3CameraEyePos, 0);
  sub_854710(&dds3CameraTargetPos, 0);
  sub_854710(&v66, 0);
  sub_854930(&v67, 0);
  sub_854710(&dds3CameraEyePos, 1u);
  sub_854710(&dds3CameraTargetPos, 1u);
  sub_854710(&v66, 1u);
  sub_854930(&v67, 1u);
  sub_854710(&dds3CameraEyePos, 2u);
  sub_854710(&dds3CameraTargetPos, 2u);
  sub_854710(&v66, 2u);
  sub_854930(&v67, 2u);
  sub_854710(&dds3CameraEyePos, 3u);
  sub_854710(&dds3CameraTargetPos, 3u);
  sub_854710(&v66, 3u);
  sub_854930(&v67, 3u);
  v31 = 4;
  do
  {
    transform = get_transform(pb_camera, 0);
    v60 = get_position(transform).x;
    v36 = v60;
    v38 = get_transform(pb_camera, 0);
    v39 = get_position(v38).y;
    v40 = get_transform(pb_camera, 0);
    z = get_position(v40).z;
    v65 = 0.0;
    v64 = 0;
    sub_8524C0(&v64, v36 + pbScrollCameraPosMovX, v39, z + pbScrollCameraPosMovY);
    v44 = v65;
    *&r_cameraPos.x = v64;
    r_cameraPos.z = v44;
    v45 = get_transform(pb_camera, 0);
    set_position(v45, r_cameraPos);
    v49 = pbScrollCameraPosMovX;
    v51 = BGImagePos.x;
    v52 = pbScrollCameraPosMovY;
    v53 = BGImagePos.z;
    v54 = BGImagePos.y;
    v63 = 0.0;
    v62 = 0;
    sub_8524C0(&v62, v51 + v49, v54, v53 + v52);
    v56 = v63;
    *&BGImagePos.x = v62;
    BGImagePos.z = v56;
    pbScrollCameraPosMovXbup += pbScrollCameraPosMovX;
    pbScrollCameraPosMovYbup += pbScrollCameraPosMovY;
    v57 = *&v30->_2.bitflags1;
    v32 = (v57 >> 9) & 1;
    --v31;
  }
  while (v31);
  pbScrollCameraPosMovX = 0;
  pbScrollCameraPosMovY = 0;
  SDF_VU0__COPYVECTOR(&dds3CameraEyePos, v67);
  SDF_VU0__COPYVECTOR(&dds3CameraTargetPos, v66);
}

// 0x1666f60
void pbSetGameCameraUnity(void) {
  ;
}

// 0x1666ba0
pbProcHandle_t *pbStartAutoRoundCamera(pbProcHandle_t *parent, s32 dir) {
  u64 *v5;
  pbProcHandle_t_o *v6;
  u64 *v7;
  u64 *v8;
  pbProcHandle_t_Fields *p_fields;
  u64 *v12;
  u64 v14;
  s64 typeHierarchyDepth;
  f32 v17;
  char *v21;
  s64 *v22;
  dds3ProcessID_t_o *target;
  u64 v24[3];

  v5 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v5);
  target = v5;
  v6 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v6);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_pbGame_roundAutoCamera__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbGame_deleteRoundAutoCamera__);
  v6->id = dds3StartProcess("pb-proc-move camera", 0x3EEu, 0, 0, v7, 0, v8, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, &v6->id);
  }
  pb_General__PB_PROC_SEND_MESS(v6, 0);
  v12 = Allocate(pbCameraRot_t);
  _ctor(v12, 0);
  v6->data = v12;
  v14 = *v12;
  if (*(*v12 + 288) < typeHierarchyDepth || *(*(v14 + 200) + 8 * typeHierarchyDepth - 8) != pbCameraRot_t)
  {
    sub_8FC2C0(*(v14 + 64), pbCameraRot_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v24[2];
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  *(v12 + 4) = dir;
  *(v12 + 5) = 0;
  switch (pbGetKeyMode())
  {
    case 0u:
      if (dir == 1)
      {
        v17 = 1.5708;
      }
      else
      {
        cameraAngle = 6.2832;
        v17 = 4.7124;
      }
      goto LABEL_31;
    case 1u:
      v17 = flt_32C2500[dir == 1];
      goto LABEL_31;
    case 2u:
      v17 = flt_32C24F8[dir == 1];
      goto LABEL_31;
    case 3u:
      v17 = 3.1416;
      if (dir != 1)
        v17 = 0.0;
LABEL_31:
      *(v12 + 5) = v17;
      break;
    default:
      break;
  }
  dds3SetProcessData(&v6->id, v6);
  target = dds3SearchProcessName("DebugOwner");
  if (target)
  {
    dds3ResetProcessFlag(&target, 0x10u, 2);
  }
  return v6;
}

// 0x1662090
pbProcHandle_t *pbStartClear(pbProcHandle_t *parent) {
  pbProcHandle_t_o *v3;
  u64 *v4;
  u64 *v5;
  pbProcHandle_t_Fields *p_fields;
  pbclearwork_tag_o *v9;
  pbclearwork_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  u64 v16[3];

  v3 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v3);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_pbGame_ClearProc__);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_pbGame_DeleteClearProc__);
  v3->id = dds3StartProcess("pb-proc-clear", 0x3EEu, 1, 1, v4, 0, v5, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, &v3->id);
  }
  pb_General__PB_PROC_SEND_MESS(v3, 0);
  v9 = Allocate(pbclearwork_tag);
  _ctor(v9, 0);
  v3->data = v9;
  klass = v9->klass;
  if (v9->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbclearwork_tag)
  {
    sub_8FC2C0(klass->_1.element_class, pbclearwork_tag, v16);
    if ((v16[0] & 1) != 0)
      v14 = v16[2];
    else
      v14 = v16 + 1;
    v15 = sub_8C4940(v14);
  }
  v9->ctr = 30;
  dds3SetProcessData(&v3->id, v3);
  return v3;
}

// 0x16662a0
pbProcHandle_t *pbStartGame(pbProcHandle_t **parent) {
  u64 *v3;
  pbProcHandle_t_o *v4;
  s32 StageNumber;
  u64 *v9;
  u64 *v10;
  pbProcHandle_t_Fields *p_fields;
  struct pbProcHandle_t_array *mychar;
  struct pbProcHandle_t_array *v19;
  struct pbProcHandle_t_array *v21;
  struct pbProcHandle_t_array *v23;
  pbProcHandle_t_o *started;
  s32 Id;
  UnityEngine_GameObject_o *v36;
  UnityEngine_Object_o *oPB_UI;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v44;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v48;
  pbProcHandle_t_o *parenta;

  v3 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v3);
  v4 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v4);
  parenta = v4;
  StageNumber = GetStageNumber();
  pbLoadSystemData(StageNumber);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_pbGame_game__);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_pbGame_deleteGame__);
  v4->id = dds3StartProcess("pb-proc-game", 0x3EEu, 1, 1, v9, 0, v10, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, &v4->id);
  }
  pb_General__PB_PROC_SEND_MESS(v4, 1);
  dds3SetProcessData(&v4->id, v4);
  blockDB = 0;
  bmap = 0;
  goal = 0;
  record = 0;
  mapCursor = 0;
  roundCamera = 0;
  moveViewCamera = 0;
  clear = 0;
  scr_msg = 0;
  if (!LODWORD(mychar->max_length))
    goto LABEL_33;
LABEL_29:
  mychar->m_Items[0] = 0;
  v19 = mychar;
  v19->m_Items[1] = 0;
  v21 = mychar;
  v21->m_Items[2] = 0;
  v23 = mychar;
  v23->m_Items[3] = 0;
  started = pbStartBlockDataBase(&parenta);
  blockDB = started;
  bmap = pbInitMapBaseDraw(&parenta, 1u);
  goal = pbInitExitDraw(&parenta);
  record = pbStartRecord(&parenta);
  mapCursor = pbStartDrawMapCursor(&parenta);
  Id = FindId(0, "JYAKYO02_BGM00");
  p2sdPlayBGM(Id);
  cameraAngle = 0.0;
  cameraRadius = 700.0;
  cameraDegree = 1.1;
  cameraDegreeInit = 1.1;
  pbInitGameCamera();
  v36 = Find("FieldFilter", 0);
  if (op_Inequality(v36, 0, 0) && get_activeSelf(v36))
    SetActive(v36, 0, 0);
  dds3FadeIn2(0x1Eu);
  if (op_Equality(oPB_UI, 0, 0))
  {
    asset_bc = get_asset_bc();
    Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", "dds3data/UI", "pzlUI");
    v44 = Find("Canvas_UI", 0);
    transform = get_transform(v44, 0);
    v48 = Instantiate_object__425664(Prefab_16624656, transform, 0);
    oPB_UI = v48;
    AddComponent_object_(oPB_UI);
  }
  return parenta;
}

// 0x1668190
dds3ProcessID_t *pbStartGiveupConfirm(void) {
  System_Byte_array *pscript;
  dds3ProcessID_t_o *started;

  fclClearSignal(0);
  pscript = pbWk->pscript;
  started = scrStartScript2(1006, pscript, 1);
  scr_msg = started;
  return scr_msg;
}

// 0x16608b0
pbProcHandle_t *pbStartMoveBlock(pbProcHandle_t *parent, pbGroupData_t *grp, s32 dir) {
  u64 *v7;
  pbProcHandle_t_o *v8;
  u64 *v9;
  u64 *v10;
  pbProcHandle_t_Fields *p_fields;
  pbMove_t_o *v14;
  pbMove_t_c *klass;
  s64 typeHierarchyDepth;
  pbGroupData_t_o **p_grp;
  s32 Id;
  s64 v27;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_o *core;
  s16 x;
  s16 v32;
  s16 v33;
  s64 v34;
  char *v36;
  s64 *v37;
  u64 v38[3];

  v7 = Allocate(pbMove_t);
  _ctor(v7, 0);
  v8 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v8);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_pbGame_moveBlock__);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_pbGame_deleteMoveBlock__);
  v8->id = dds3StartProcess("pb-proc-move block", 0x3EEu, 0, 0, v9, 0, v10, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, &v8->id);
  }
  pb_General__PB_PROC_SEND_MESS(v8, 0);
  v14 = Allocate(pbMove_t);
  _ctor(v14, 0);
  v8->data = v14;
  klass = v14->klass;
  if (v14->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMove_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbMove_t, v38);
    if ((v38[0] & 1) != 0)
      v36 = v38[2];
    else
      v36 = v38 + 1;
    v37 = sub_8C4940(v36);
  }
  v14->grp = grp;
  p_grp = &v14->grp;
  *(p_grp - 3) = 0;
  *(p_grp - 8) = dir;
  dds3SetProcessData(&v8->id, v8);
  if (dir == 4)
  {
    Id = FindId(1, "JYAKYO02_SE03");
    p2sdPlaySE(Id);
    pbAddRecord_flor(&record, p_grp);
    dds3PadAct(1u, 0x6Eu, 0xCu);
  }
  else
  {
    pbAddRecord_blk(&record, p_grp);
  }
  grp->flag = 1;
  if (grp->num >= 1)
  {
    v27 = 4;
    do
    {
      blk = grp->blk;
      core = grp->core;
      x = core->x;
      v32 = *(*(&blk->obj.klass + v27) + 18LL);
      v33 = *(*(&grp->blk->obj.klass + v27) + 20LL) + core->y;
      pb_General__CLR_MAP_BLKDAT_((v32 + x), v33, 0);
      v34 = v27 - 3;
      ++v27;
    }
    while (v34 < grp->num);
  }
  return v8;
}

// 0x16605a0
pbProcHandle_t *pbStartMoveChar(pbProcHandle_t *parent, s32 dir, u32 scl) {
  s16 v5;
  pbProcHandle_t_o *v7;
  u64 *v8;
  u64 *v9;
  pbProcHandle_t_Fields *p_fields;
  pbMove_t_o *v13;
  pbMove_t_c *klass;
  s64 typeHierarchyDepth;
  f32 v17;
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  char *v25;
  s64 *v26;
  u64 v27[3];

  v5 = dir;
  v7 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v7);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbGame_moveChar__);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_pbGame_deleteMoveChar__);
  v7->id = dds3StartProcess("pb-proc-move char", 0x3EEu, 0, 0, v8, 0, v9, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, &v7->id);
  }
  pb_General__PB_PROC_SEND_MESS(v7, 0);
  v13 = Allocate(pbMove_t);
  _ctor(v13, 0);
  v7->data = v13;
  klass = v13->klass;
  if (v13->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMove_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbMove_t, v27);
    if ((v27[0] & 1) != 0)
      v25 = v27[2];
    else
      v25 = v27 + 1;
    v26 = sub_8C4940(v25);
  }
  v17 = scl;
  v13->cnt = 0;
  v13->dir = v5;
  v13->scl = v17;
  dds3SetProcessData(&v7->id, v7);
  else if (current_char >= LODWORD(mychar->max_length))
  {
    goto LABEL_25;
  }
  pbChangeMotion(&mychar->m_Items[current_char], 1u);
  return v7;
}

// 0x1660d20
pbProcHandle_t *pbStartRoundBlock(pbProcHandle_t *parent, pbGroupData_t *grp, s32 dir) {
  s16 v4;
  u64 *v7;
  pbProcHandle_t_o *v8;
  u64 *v9;
  u64 *v10;
  pbProcHandle_t_Fields *p_fields;
  pbMove_t_o *v14;
  pbMove_t_c *klass;
  s64 typeHierarchyDepth;
  pbGroupData_t_o *v21;
  s64 v22;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_o *core;
  u64 max_length_low;
  s16 x;
  struct pbBlockData_t_array *v27;
  s16 v29;
  s16 v31;
  s64 v32;
  char *v34;
  s64 *v35;
  pbGroupData_t_o *grpa;
  u64 v37[3];

  v4 = dir;
  grpa = grp;
  v7 = Allocate(pbMove_t);
  _ctor(v7, 0);
  v8 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v8);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_pbGame_roundBlock__);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_pbGame_deleteRoundBlock__);
  v8->id = dds3StartProcess("pb-proc-move block", 0x3EEu, 0, 0, v9, 0, v10, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, &v8->id);
  }
  pb_General__PB_PROC_SEND_MESS(v8, 0);
  v14 = Allocate(pbMove_t);
  _ctor(v14, 0);
  v8->data = v14;
  klass = v14->klass;
  if (v14->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMove_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbMove_t, v37);
    if ((v37[0] & 1) != 0)
      v34 = v37[2];
    else
      v34 = v37 + 1;
    v35 = sub_8C4940(v34);
  }
  v14->cnt = 0;
  v14->dir = v4;
  v14->grp = grp;
  dds3SetProcessData(&v8->id, v8);
  pbAddRecord_blk(&record, &grpa);
  v21 = grpa;
  grpa->flag = 1;
  if (v21->num >= 1)
  {
    v22 = 4;
    do
    {
      blk = v21->blk;
      core = v21->core;
      max_length_low = LODWORD(blk->max_length);
      x = core->x;
      v27 = blk;
      v29 = *(*(&blk->obj.klass + v22) + 18LL);
      v31 = *(*(&v27->obj.klass + v22) + 20LL) + core->y;
      pb_General__CLR_MAP_BLKDAT_((v29 + x), v31, 0);
      v21 = grpa;
      v32 = v22 - 3;
      ++v22;
    }
    while (v32 < grpa->num);
  }
  return v8;
}

// 0x165cee0
pbProcHandle_t *pbStartViewModeCamera(pbProcHandle_t *parent) {
  pbProcHandle_t_o *v3;
  u64 *v4;
  u64 *v5;
  pbProcHandle_t_Fields *p_fields;
  u64 *v9;
  u64 v11;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  u64 v18[3];

  v3 = Allocate(pbProcHandle_t);
  pbProcHandle_t___ctor(v3);
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_pbGame_viewModeCamera__);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_pbGame_deleteViewModeCamera__);
  v3->id = dds3StartProcess("pb-proc-move view camera", 0x3EEu, 0, 0, v4, 0, v5, 0, 0, 0);
  if (parent)
  {
    p_fields = &parent->fields;
    dds3LinkProcess(&p_fields->id, &v3->id);
  }
  pb_General__PB_PROC_SEND_MESS(v3, 0);
  v9 = Allocate(pbViewModeCamera_t);
  _ctor(v9, 0);
  v3->data = v9;
  v11 = *v9;
  if (*(*v9 + 288) < typeHierarchyDepth || *(*(v11 + 200) + 8 * typeHierarchyDepth - 8) != pbViewModeCamera_t)
  {
    sub_8FC2C0(*(v11 + 64), pbViewModeCamera_t, v18);
    if ((v18[0] & 1) != 0)
      v16 = v18[2];
    else
      v16 = v18 + 1;
    v17 = sub_8C4940(v16);
  }
  *(v9 + 4) = 1065353216;
  SDF_VU0__COPYVECTOR((v9 + 20), dds3CameraEyePos, 0);
  SDF_VU0__COPYVECTOR((v9 + 36), dds3CameraTargetPos, 0);
  dds3SetProcessData(&v3->id, v3);
  return v3;
}

// 0x1658b10
u32 pushCheck(s32 dir, u32 grpID, pbGroupData_t **grp) {
  pbGroupData_t_o *v7;
  struct pbBlockData_t_o *core;
  s16 y;
  struct System_Int16_array_array *pbMoveDir;
  System_Int16_array *v15;
  struct System_Int16_array_array *v17;
  s16 v18;
  System_Int16_array *v20;
  pbGroupData_t_o *v22;
  s16 v23;
  s64 v24;
  s32 v25;
  s16 v26;
  u32 v27;
  s16 v28;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_array *v30;
  s32 v32;
  s16 v33;
  s32 v35;
  s64 v36;

  v7 = pbSearchGroupDB(&blockDB, grpID);
  *grp = v7;
  core = v7->core;
  y = core->y;
  v15 = pbMoveDir->m_Items[dir];
  v17 = pbMoveDir;
  v18 = v15->m_Items[0];
  v20 = v17->m_Items[dir];
  v22 = *grp;
  if ((*grp)->num < 1)
    return 3;
  v23 = v18 + y;
  v24 = 4;
  v25 = v23;
  v26 = v20->m_Items[1] + (*grp)->core->x;
  v27 = 3;
  v28 = v26;
  while (1)
  {
    blk = v22->blk;
    v30 = blk;
    v32 = v25 + *(*(&blk->obj.klass + v24) + 20LL);
    if ((v32 << 16) > 0x130000)
      break;
    v33 = v28 + *(*(&v30->obj.klass + v24) + 18LL);
    if ((v33 >> 2) > 4u)
      break;
    if (charHitCheck(v33, v32) == 1)
      break;
    v35 = pb_General__GET_MAP_BLK_(v33, v32);
    if (v35)
    {
      if (v35 == 1)
      {
        v27 = 2;
      }
      else
      {
        if (pb_General__GET_MAP_GRPID_(v33, v32) != (*grp)->grpID)
          v27 = 2;
      }
    }
    v22 = *grp;
    v36 = v24 - 3;
    ++v24;
    if (v36 >= (*grp)->num)
      return v27;
  }
  return 2;
}

// 0x1659b10
void rotXY(s16 *x, s16 *y, s32 dir) {
  s32 v4;
  s32 v5;

  v4 = *x;
  v5 = *y;
  if (v4 | v5)
  {
    *x = v5;
    *y = v4;
    if (dir == 1)
    {
      if (!*x)
        *y = -v4;
    }
    else if (dir == -1 && !v4)
    {
      *x = -*x;
    }
  }
}

// 0x1663870
dds3ProcessFunc_t *roundAutoCamera(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  UnityEngine_GameObject_o *RenderCamera;
  UnityEngine_Transform_o *transform;
  f32 v18;
  s32 pbScrollCameraPosMovXbup;
  UnityEngine_Transform_o *v20;
  f32 y;
  UnityEngine_Transform_o *v22;
  struct pbGame_StaticFields **v26;
  f32 v29;
  struct UnityEngine_Vector3_o *v30;
  struct pbGame_StaticFields **p_static_fields;
  f32 v34;
  struct UnityEngine_Vector3_o *p_pbBGRotateMov;
  s32 v38;
  s32 v40;
  struct UnityEngine_Vector3_o *v51;
  f32 v52;
  f32 *v56;
  f32 v58;
  struct UnityEngine_Vector3_array *v60;
  f32 v61;
  s64 v62;
  f32 v64;
  f32 v65;
  struct UnityEngine_Vector3_o *v66;
  f32 v67;
  struct UnityEngine_Vector3_array *v68;
  s64 v69;
  f32 v70;
  f32 v72;
  UnityEngine_GameObject_o *v73;
  UnityEngine_Transform_o *v74;
  UnityEngine_GameObject_o *v77;
  UnityEngine_Transform_o *v78;
  f32 v79;
  f32 v80;
  f32 v81;
  pbGame_c *v83;
  UnityEngine_Transform_o *v84;
  s64 v86;
  UnityEngine_Transform_o *v87;
  f32 v88;
  f32 v91;
  f32 v92;
  f32 v93;
  f32 v94;
  UnityEngine_Transform_o *v95;
  s32 v99;
  s32 pbViewChangeflag;
  struct UnityEngine_Vector3_o *v112;
  f32 v113;
  f32 *v115;
  f32 v117;
  struct UnityEngine_Vector3_array *pbCameraPos;
  f32 v120;
  s64 pb_cdir;
  f32 v123;
  f32 v124;
  struct UnityEngine_Vector3_o *p_r_cameraPos;
  f32 v126;
  struct UnityEngine_Vector3_array *v127;
  s64 v128;
  f32 v129;
  f32 v131;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v133;
  UnityEngine_GameObject_o *v136;
  UnityEngine_Transform_o *v137;
  f32 v138;
  f32 v139;
  f32 v140;
  UnityEngine_Transform_o *v146;
  UnityEngine_GameObject_o *v149;
  UnityEngine_Transform_o *v150;
  UnityEngine_Transform_o *v151;
  f32 v152;
  struct pbGame_StaticFields **v153;
  f32 v155;
  struct pbGame_StaticFields *v156;
  s64 v157;
  struct pbGame_StaticFields *v158;
  UnityEngine_GameObject_o *v160;
  UnityEngine_Transform_o *v161;
  struct UnityEngine_Vector3_array *v166;
  s64 v167;
  f32 v169;
  struct UnityEngine_Vector3_array *v170;
  s64 v171;
  f32 v173;
  struct UnityEngine_Vector3_array *v176;
  s64 v177;
  char *v179;
  s64 v182;
  UnityEngine_Transform_o *v183;
  UnityEngine_GameObject_o *v184;
  UnityEngine_Transform_o *v185;
  UnityEngine_GameObject_o *v188;
  UnityEngine_Transform_o *v189;
  UnityEngine_GameObject_o *v192;
  UnityEngine_Transform_o *v194;
  UnityEngine_Transform_o *v197;
  s64 v199;
  UnityEngine_Transform_o *v200;
  f32 v201;
  f32 v204;
  f32 v205;
  f32 v206;
  f32 v207;
  UnityEngine_Transform_o *v208;
  UnityEngine_Transform_o *v210;
  UnityEngine_Transform_o *v211;
  UnityEngine_Transform_o *v215;
  UnityEngine_GameObject_o *v218;
  UnityEngine_Transform_o *v219;
  UnityEngine_Transform_o *v220;
  f32 v221;
  f32 v223;
  s64 v225;
  f32 v227;
  struct UnityEngine_Vector3_array *pbcCameraPos;
  s64 v231;
  f32 v233;
  struct UnityEngine_Vector3_array *v234;
  s64 v235;
  f32 v237;
  struct UnityEngine_Vector3_array *v240;
  s64 v241;
  char *v243;
  s64 v246;
  UnityEngine_Transform_o *v247;
  UnityEngine_GameObject_o *v248;
  UnityEngine_Transform_o *v249;
  UnityEngine_GameObject_o *v252;
  UnityEngine_Transform_o *v253;
  UnityEngine_GameObject_o *v256;
  UnityEngine_Transform_o *v258;
  char *v261;
  s64 *v262;
  f32 x;
  f32 z;
  s64 v266;
  f32 v267;
  UnityEngine_Vector3_o v268;
  char *v269;
  UnityEngine_Vector3_o v270;
  UnityEngine_Vector3_o v273;
  UnityEngine_Vector3_o v274;
  UnityEngine_Vector3_o v275;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o up;
  UnityEngine_Vector3_o v278;
  UnityEngine_Vector3_o v279;
  UnityEngine_Vector3_o v282;
  UnityEngine_Vector3_o v283;
  UnityEngine_Vector3_o v284;
  UnityEngine_Vector3_o v285;

  v267 = 0.0;
  v266 = 0;
  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, &v268);
    if ((LOBYTE(v268.x) & 1) != 0)
      v261 = v269;
    else
      v261 = &v268.x + 1;
    v262 = sub_8C4940(v261);
  }
  v7 = workdata[2].klass;
  if (v7)
  {
    image = v7->_1.image;
    if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbCameraRot_t)
    {
      sub_8FC2C0(image[8], pbCameraRot_t, &v268);
      if ((LOBYTE(v268.x) & 1) != 0)
        v10 = v269;
      else
        v10 = &v268.x + 1;
      v11 = sub_8C4940(v10);
    }
  }
  RenderCamera = GetRenderCamera(kernelObject);
  GetComponent_object_(RenderCamera);
  transform = get_transform(childobj, 0);
  x = get_position(transform).x;
  v18 = x;
  v20 = get_transform(childobj, 0);
  y = get_position(v20).y;
  v22 = get_transform(childobj, 0);
  z = get_position(v22).z;
  sub_8524C0(&v266, v18 + pbScrollCameraPosMovXbup, y, z + pbScrollCameraPosMovYbup);
  if (SLODWORD(v7->_1.name) < 1)
  {
    else
    {
      if (pbViewChangeflag)
        goto LABEL_32;
    }
    cameraAngle = cameraAngle + -0.18;
    sub_8529B0(&(*p_static_fields)->pbRotateMov, 1, 10.0);
    p_pbBGRotateMov = &pbBGRotateMov;
    v34 = 10.0;
LABEL_97:
    sub_8529B0(p_pbBGRotateMov, 1, v34);
    {
      v99 = 0;
      if (cameraWk_flg)
        goto LABEL_99;
LABEL_115:
      if (pbViewChangeflag)
      {
        v115 = &r_cameraPos.x;
        v117 = sub_8527D0(v115, 0);
        v120 = v117;
        v123 = sub_8527D0(&pbCameraPos->m_Items[pb_cdir].x, 0);
        v124 = sub_8527D0(&pb_CameraPosbup.x, 0);
        sub_8529B0(v115, 0, v120 + ((v123 - v124) / 11.0));
        p_r_cameraPos = &r_cameraPos;
        v126 = sub_8527D0(&p_r_cameraPos->x, 2);
        v127 = pbCameraPos;
        v128 = pb_cdir;
        v129 = v126;
        v131 = sub_8527D0(&v127->m_Items[v128].x, 2);
        v113 = v129 + ((v131 - sub_8527D0(&pb_CameraPosbup.x, 2)) / 11.0);
        v112 = p_r_cameraPos;
LABEL_130:
        sub_8529B0(v112, 2, v113);
        gameObject = get_gameObject(pb_camera);
        v133 = get_transform(gameObject, 0);
        set_localEulerAngles(v133, pbRotateMov);
        v136 = get_gameObject(BGImage);
        v137 = get_transform(v136, 0);
        v138 = sub_8527D0(&pbBGRotateMov.x, 0);
        v139 = sub_8527D0(&pbRotateMov.x, 1);
        v140 = sub_8527D0(&pbRotateMov.x, 2);
        v268.z = 0.0;
        *&v268.x = 0;
        sub_8524C0(&v268.x, v138, v139, v140);
        set_localEulerAngles(v137, v268);
        {
LABEL_134:
        }
LABEL_236:
        v223 = *(&v7->_1.name + 1);
        if (cameraAngle > v223)
          goto LABEL_281;
        cameraAngle = v223;
        v225 = *&pb_cameraAngle.x;
        pbRotateMov.z = pb_cameraAngle.z;
        *&pbRotateMov.x = v225;
        v227 = pbBG_cameraAngle.z;
        *&pbBGRotateMov.x = *&pbBG_cameraAngle.x;
        pbBGRotateMov.z = v227;
        if (cameraWk_flg)
        {
          if (pbViewChangeflag)
          {
            v231 = pb_cdir;
            v233 = sub_8527D0(&pbcCameraPos->m_Items[v231].x, 0);
            sub_8529B0(&r_cameraPos, 0, v233 + pbScrollCameraPosMovXbup);
            v234 = pbcCameraPos;
            v235 = pb_cdir;
            v237 = sub_8527D0(&v234->m_Items[v235].x, 2);
            sub_8529B0(&r_cameraPos, 2, v237 + pbScrollCameraPosMovYbup);
LABEL_269:
            v247 = get_transform(pb_camera, 0);
            set_position(v247, r_cameraPos);
            v248 = get_gameObject(pb_camera);
            v249 = get_transform(v248, 0);
            set_localEulerAngles(v249, pbRotateMov);
            v252 = get_gameObject(BGImage);
            v253 = get_transform(v252, 0);
LABEL_280:
            set_localEulerAngles(v253, pbBGRotateMov);
            id->func_ans = -1;
LABEL_281:
            if ((v83->_2.bitflags2 & 2) == 0)
              goto LABEL_282;
            goto LABEL_209;
          }
        }
        else
        {
          if (pbViewChangeflag == 1)
          {
            v240 = pbCameraPos;
            v241 = pb_cdir;
            v243 = v240 + 12 * v241;
            v246 = *(v243 + 4);
            LODWORD(v243) = *(v243 + 10);
            *&r_cameraPos.x = v246;
            LODWORD(r_cameraPos.z) = v243;
            goto LABEL_269;
          }
        }
        v256 = get_gameObject(BGImage);
        v258 = get_transform(v256, 0);
        v253 = v258;
        goto LABEL_280;
      }
      v210 = get_transform(pbCameraObj, 0);
      v211 = get_transform(childobj, 0);
      position = get_position(v211);
      up = get_up();
      v204 = up.x;
      v205 = up.y;
      v206 = up.z;
      v207 = -sub_8527D0(&pbRotateMov.x, 1);
      v283 = position;
      v208 = v210;
      goto LABEL_232;
    }
    else
    {
      if (!cameraWk_flg)
        goto LABEL_115;
    }
LABEL_99:
    else
    {
      if (pbViewChangeflag)
        goto LABEL_102;
    }
    v197 = get_transform(pbCameraObj, 0);
    v199 = v266;
    v200 = v197;
    v201 = v267;
    v275 = get_up();
    v204 = v275.x;
    v205 = v275.y;
    v206 = v275.z;
    v207 = -sub_8527D0(&pbRotateMov.x, 1);
    v208 = v200;
    *&v283.x = v199;
    v283.z = v201;
LABEL_232:
    v285.x = v204;
    v285.y = v205;
    v285.z = v206;
    RotateAround(v208, v283, v285, v207);
    v215 = get_transform(pbCameraObj, 0);
    r_cameraPos = get_position(v215);
    v218 = get_gameObject(BGImage);
    v219 = get_transform(v218, 0);
    v220 = get_transform(childobj, 0);
    v278 = get_position(v220);
    v279 = get_up();
    v221 = -sub_8527D0(&pbBGRotateMov.x, 1);
    RotateAround(v219, v278, v279, v221);
      goto LABEL_134;
    goto LABEL_236;
  }
  else
  {
    if (pbViewChangeflag)
      goto LABEL_25;
  }
  cameraAngle = cameraAngle + 0.18;
  sub_8529B0(&(*v26)->pbRotateMov, 1, 10.0);
  v30 = &pbBGRotateMov;
  v29 = 10.0;
LABEL_41:
  sub_8529B0(v30, 1, v29);
  {
    else
    {
      if (!cameraWk_flg)
        goto LABEL_59;
    }
LABEL_43:
    else
    {
      v40 = pbViewChangeflag;
      if (v40)
        goto LABEL_46;
    }
    v84 = get_transform(pbCameraObj, 0);
    v86 = v266;
    v87 = v84;
    v88 = v267;
    v270 = get_up();
    v91 = v270.x;
    v92 = v270.y;
    v93 = v270.z;
    v94 = sub_8527D0(&pbRotateMov.x, 1);
    v95 = v87;
    *&v282.x = v86;
    v282.z = v88;
LABEL_149:
    v284.x = v91;
    v284.y = v92;
    v284.z = v93;
    RotateAround(v95, v282, v284, v94);
    v146 = get_transform(pbCameraObj, 0);
    r_cameraPos = get_position(v146);
    v149 = get_gameObject(BGImage);
    v150 = get_transform(v149, 0);
    v151 = get_transform(childobj, 0);
    v273 = get_position(v151);
    v274 = get_up();
    v152 = sub_8527D0(&pbBGRotateMov.x, 1);
    RotateAround(v150, v273, v274, v152);
      goto LABEL_77;
    goto LABEL_153;
  }
  v38 = 0;
  if (cameraWk_flg)
    goto LABEL_43;
LABEL_59:
  if (!pbViewChangeflag)
    goto LABEL_139;
LABEL_62:
  v56 = &r_cameraPos.x;
  v58 = sub_8527D0(v56, 0);
  v60 = pbCameraPos;
  v61 = v58;
  v62 = pb_cdir;
  v64 = sub_8527D0(&v60->m_Items[v62].x, 0);
  v65 = sub_8527D0(&pb_CameraPosbup.x, 0);
  sub_8529B0(v56, 0, v61 + ((v64 - v65) / 11.0));
  v66 = &r_cameraPos;
  v67 = sub_8527D0(&v66->x, 2);
  v68 = pbCameraPos;
  v69 = pb_cdir;
  v70 = v67;
  v72 = sub_8527D0(&v68->m_Items[v69].x, 2);
  v52 = v70 + ((v72 - sub_8527D0(&pb_CameraPosbup.x, 2)) / 11.0);
  v51 = v66;
LABEL_73:
  sub_8529B0(v51, 2, v52);
  v73 = get_gameObject(pb_camera);
  v74 = get_transform(v73, 0);
  set_localEulerAngles(v74, pbRotateMov);
  v77 = get_gameObject(BGImage);
  v78 = get_transform(v77, 0);
  v79 = sub_8527D0(&pbBGRotateMov.x, 0);
  v80 = sub_8527D0(&pbRotateMov.x, 1);
  v81 = sub_8527D0(&pbRotateMov.x, 2);
  v268.z = 0.0;
  *&v268.x = 0;
  sub_8524C0(&v268.x, v79, v80, v81);
  set_localEulerAngles(v78, v268);
  {
LABEL_77:
  }
LABEL_153:
  v155 = *(&v7->_1.name + 1);
  if (cameraAngle < v155)
    goto LABEL_281;
  cameraAngle = v155;
  v156 = *v153;
  v157 = *&(*v153)->pb_cameraAngle.x;
  v156->pbRotateMov.z = (*v153)->pb_cameraAngle.z;
  *&v156->pbRotateMov.x = v157;
  v158 = *v153;
  *&v157 = v158->pbBG_cameraAngle.z;
  *&v158->pbBGRotateMov.x = *&v158->pbBG_cameraAngle.x;
  LODWORD(v158->pbBGRotateMov.z) = v157;
  v160 = get_gameObject(BGImage);
  v161 = get_transform(v160, 0);
  set_localEulerAngles(v161, pbRotateMov);
  if (cameraWk_flg)
  {
    if (pbViewChangeflag)
    {
      v166 = pbcCameraPos;
      v167 = pb_cdir;
      v169 = sub_8527D0(&v166->m_Items[v167].x, 0);
      sub_8529B0(&r_cameraPos, 0, v169 + pbScrollCameraPosMovXbup);
      v170 = pbcCameraPos;
      v171 = pb_cdir;
      v173 = sub_8527D0(&v170->m_Items[v171].x, 2);
      sub_8529B0(&r_cameraPos, 2, v173 + pbScrollCameraPosMovYbup);
LABEL_189:
      v183 = get_transform(pb_camera, 0);
      set_position(v183, r_cameraPos);
      v184 = get_gameObject(pb_camera);
      v185 = get_transform(v184, 0);
      set_localEulerAngles(v185, pbRotateMov);
      v188 = get_gameObject(BGImage);
      v189 = get_transform(v188, 0);
      goto LABEL_200;
    }
  }
  else
  {
    if (pbViewChangeflag == 1)
    {
      v176 = pbCameraPos;
      v177 = pb_cdir;
      v179 = v176 + 12 * v177;
      v182 = *(v179 + 4);
      LODWORD(v179) = *(v179 + 10);
      *&r_cameraPos.x = v182;
      LODWORD(r_cameraPos.z) = v179;
      goto LABEL_189;
    }
  }
  v192 = get_gameObject(BGImage);
  v194 = get_transform(v192, 0);
  v189 = v194;
LABEL_200:
  set_localEulerAngles(v189, pbBGRotateMov);
  if (cameraAngle >= 6.2832)
  {
    cameraAngle = 0.0;
  }
  id->func_ans = -1;
  if ((v83->_2.bitflags2 & 2) != 0)
  {
LABEL_209:
  }
LABEL_282:
  pbRotateYCamera2(cameraAngle, cameraRadius, cameraDegree, v83);
  return 0;
}

// 0x1663230
dds3ProcessFunc_t *roundBlock(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  s16 *data;
  s64 v13;
  s64 v14;
  u64 v16;
  struct System_Single_array *roted_blkx;
  struct System_Single_array *rot_x;
  s32 v21;
  struct System_Single_array *roted_blkz;
  struct System_Single_array *rot_z;
  s32 v27;
  s64 v29;
  s64 v30;
  s32 name_low;
  s64 v33;
  s64 v34;
  u64 v36;
  struct System_Single_array *v37;
  struct System_Single_array *v39;
  s64 v41;
  char *v45;
  s64 *v46;
  u64 v47[2];
  char *v48;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v47);
    if ((v47[0] & 1) != 0)
      v45 = v48;
    else
      v45 = v47 + 1;
    v46 = sub_8C4940(v45);
  }
  v7 = workdata[2].klass;
  if (v7)
  {
    image = v7->_1.image;
    if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbMove_t)
    {
      sub_8FC2C0(image[8], pbMove_t, v47);
      if ((v47[0] & 1) != 0)
        v10 = v48;
      else
        v10 = v47 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  data = v7->_1.byval_arg.data;
  LODWORD(v13) = data[11];
  if (v13 >= 1)
  {
    v14 = 8;
    do
    {
      v16 = v14 - 8;
      v21 = *(&roted_blkx->obj.klass + v14);
      *(&rot_x->obj.klass + v14) = v21;
      v27 = *(&roted_blkz->obj.klass + v14);
      *(&rot_z->obj.klass + v14) = v27;
      data = v7->_1.byval_arg.data;
      v13 = data[11];
      v29 = v14 - 7;
      ++v14;
    }
    while (v29 < v13);
  }
  if (HIDWORD(v7->_1.name) < 4)
  {
    v30 = (data + 24);
    sub_854710((data + 24), 1u);
    sub_854930(v30, 1u);
    name_low = LOWORD(v7->_1.name);
    if (name_low == 0xFFFF)
    {
      v33 = v7->_1.byval_arg.data + 48;
    }
    else
    {
      if (name_low != 1)
        goto LABEL_46;
      v33 = v7->_1.byval_arg.data + 48;
    }
    sub_854930(v33, 1u);
LABEL_46:
    ++HIDWORD(v7->_1.name);
    MRBlockDrawflag = 0;
    return 0;
  }
  if (v13 >= 1)
  {
    v34 = 8;
    do
    {
      v36 = v34 - 8;
      v37 = rot_x;
      *(&v37->obj.klass + v34) = 0;
      v39 = rot_z;
      *(&v39->obj.klass + v34) = 0;
      v41 = v34 - 7;
      ++v34;
    }
    while (v41 < *(v7->_1.byval_arg.data + 11));
  }
  kakekaris = 1;
  id->func_ans = -1;
  return 0;
}

// 0x1659090
u32 roundCheck(s32 dir, u32 grpID, pbGroupData_t **grp) {
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  struct pbBlockData_t_o *core;
  u32 result;
  pb_General_c **v17;
  u64 v18;
  s32 v20;
  struct System_Int16_array_array *pbMoveDir;
  System_Int16_array *v23;
  s32 v25;
  struct System_Int16_array_array *v26;
  s32 v27;
  System_Int16_array *v28;
  u64 v29;
  s32 v30;
  u64 v34;
  s64 v35;
  s64 v37;
  s32 v38;
  struct System_Int16_array_array *v39;
  System_Int16_array *v41;
  pb_General_c **v42;
  struct System_Int16_array_array *v44;
  s32 v45;
  System_Int16_array *v47;
  s32 v48;
  u32 v50;
  s64 v51;
  u32 v52;
  s64 v54;
  pbGroupData_t_o *v57;
  u64 v58;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_o *v60;
  struct pbBlockData_t_array *v61;
  s32 v62;
  s32 v63;
  pbBlockData_t_o *v65;
  s32 v66;
  s32 v67;
  s32 v68;
  s32 v69;
  s32 v70;
  s16 v73;
  s16 v74;
  u64 v76;
  u16 v77;
  u16 v78;
  u64 v79;
  u64 v80;
  s32 v81;
  s32 v82;
  struct System_Single_array *roted_blkz;
  struct System_Single_array *roted_blkx;
  f32 *v88;
  s32 v89;
  pbGroupData_t_o **v90;
  u64 v91;
  u32 speed;
  s16 y[2];
  s16 x;

  x = 0;
  y[0] = 0;
  speed = 0;
  *grp = pbSearchGroupDB(&blockDB, grpID);
  else if (current_char >= LODWORD(mychar->max_length))
  {
    goto LABEL_12;
  }
  pbGetMyCharcterPos2(&mychar->m_Items[current_char], &x, y);
  core = (*grp)->core;
  if (x != core->y && y[0] != core->x)
  {
    v90 = grp;
    v89 = roundDirCheck(dir, grpID, &speed);
    v91 = speed;
    v17 = &pb_General;
    v18 = 0;
    do
    {
      v20 = y[0];
      v23 = pbMoveDir->m_Items[dir];
      v25 = v23->m_Items[1];
      v26 = pbMoveDir;
      v27 = x;
      v28 = v26->m_Items[dir];
      v29 = *v17;
      v30 = v28->m_Items[0];
      if (((*v17)->_2.bitflags2 & 2) != 0 && !*(v29 + 216))
      if (pb_General__GET_MAP_HALL_(v20 + v18 * v25, v27 + v18 * v30))
        return 1;
      v34 = *v17;
      if (((*v17)->_2.bitflags2 & 2) != 0 && !*(v34 + 216))
      {
        v34 = *v17;
      }
      v35 = *(v34 + 184);
      v37 = *(*(*v35 + 16LL) + 48LL);
      v38 = x;
      v39 = pbMoveDir;
      v41 = v39->m_Items[dir];
      v42 = v17;
      v44 = pbMoveDir;
      v45 = v41->m_Items[0];
      v47 = v44->m_Items[dir];
      v48 = v18 * v45;
      v50 = y[0] + v18 * v47->m_Items[1];
      v51 = *(v37 + 16);
      v52 = v48 + v38;
      v54 = *(v51 + 16);
      v17 = v42;
      if (*(v37 + 2 * (v50 + v54 * v52) + 32) == 0x2000)
        return 1;
    }
    while (v18++ < v91);
    v57 = *grp;
    if ((*grp)->num < 1)
      return 4;
    v58 = 0;
    while (1)
    {
      blk = v57->blk;
      v60 = v57->core;
      v61 = blk;
      v62 = v60->x;
      v63 = v60->y;
      v65 = blk->m_Items[v58];
      v66 = v65->x;
      x = v65->x;
      v67 = v61->m_Items[v58]->y;
      y[0] = v67;
      else if (!(v67 | v66))
      {
        goto LABEL_73;
      }
      if (v89 == 1)
      {
        if (!v67)
          v66 = -v66;
      }
      else if (v89 == -1)
      {
        if (v66)
          LOWORD(v68) = v67;
        else
          v68 = -v67;
        goto LABEL_74;
      }
      LOWORD(v68) = v67;
LABEL_74:
      v69 = v62 + v68;
      v70 = v63 + v66;
      if (charHitCheck(v62 + v68, v70) == 1)
        return 2;
      v73 = x;
      v74 = y[0];
      if (charHitCheck(v73 + v69, v74 + v70) == 1)
        return 2;
      v76 = *v17;
      if (((*v17)->_2.bitflags2 & 2) != 0 && !*(v76 + 216))
      v77 = pb_General__GET_MAP_BLK_(v69, v70);
      v78 = pb_General__GET_MAP_BLK_(v69 + x, v70 + y[0]);
      result = 2;
      if (v77 == 1 || v78 == 1)
        return result;
      if (v77 >= 2u)
      {
        v79 = *v17;
        if (((*v17)->_2.bitflags2 & 2) != 0 && !*(v79 + 216))
        if (pb_General__GET_MAP_GRPID_(v69, v70) != (*v90)->grpID)
          return 2;
      }
      if (v78 >= 2u)
      {
        v80 = *v17;
        v81 = x;
        v82 = y[0];
        if (((*v17)->_2.bitflags2 & 2) != 0 && !*(v80 + 216))
        if (pb_General__GET_MAP_GRPID_(v69 + v81, v70 + v82) != (*v90)->grpID)
          return 2;
      }
      roted_blkz->m_Items[v58] = (40 * v69 - 380);
      v88 = (roted_blkx + 4 * v58++);
      v88[8] = (40 * v70 - 380);
      v57 = *v90;
      result = 4;
      if (v58 >= (*v90)->num)
        return result;
    }
  }
  return 2;
}

// 0x1659810
s32 roundDirCheck(s32 dir, u32 grpID, u32 *speed) {
  pbGroupData_t_o *v7;
  struct pbBlockData_t_o *core;
  s32 v10;
  s32 v11;
  struct pbProcHandle_t_array *mychar;
  s64 current_char;
  s32 v17;
  s32 v18;
  bool v19;
  s32 v20;
  s32 v21;
  bool v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s16 y[2];
  s16 x;

  x = 0;
  y[0] = 0;
  v7 = pbSearchGroupDB(&blockDB, grpID);
  x = 0;
  y[0] = 0;
  core = v7->core;
  v10 = core->x;
  v11 = core->y;
  else if (current_char >= LODWORD(mychar->max_length))
  {
    goto LABEL_12;
  }
  pbGetMyCharcterPos2(&mychar->m_Items[current_char], &x, y);
  v17 = x;
  v18 = y[0];
  switch (dir)
  {
    case 0:
      v19 = x < v11;
      v20 = -1;
      goto LABEL_18;
    case 1:
      v22 = y[0] < v10;
      v23 = 1;
      goto LABEL_34;
    case 2:
      v19 = x < v11;
      v20 = 1;
LABEL_18:
      if (v19)
        v21 = v20;
      else
        v21 = -v20;
      *speed = 1;
      if (v17 <= 18)
      {
        v24 = v17 + 1;
        if (pb_General__GET_MAP_GRPID_(v18, v24) == grpID)
          *speed = 2;
      }
      v25 = x - 1;
      if (x < 1)
        return v21;
      v26 = y[0];
      if (pb_General__GET_MAP_GRPID_(v26, v25) != grpID)
        return v21;
      goto LABEL_48;
    case 3:
      v22 = y[0] < v10;
      v23 = -1;
LABEL_34:
      if (v22)
        v21 = v23;
      else
        v21 = -v23;
      *speed = 1;
      if (v18 <= 18)
      {
        v27 = v18 + 1;
        if (pb_General__GET_MAP_GRPID_(v27, v17) == grpID)
          *speed = 2;
      }
      v28 = y[0] - 1;
      if (y[0] >= 1)
      {
        v29 = x;
        if (pb_General__GET_MAP_GRPID_(v28, v29) == grpID)
LABEL_48:
          *speed = 2;
      }
      break;
    default:
      *speed = 1;
      v21 = -1;
      break;
  }
  return v21;
}

// 0x1662300
void setMoveBlockData(pbGroupData_t **grp, s32 dir) {
  struct pbBlockData_t_o *core;
  s16 y;
  struct System_Int16_array_array *pbMoveDir;
  System_Int16_array *v10;
  struct System_Int16_array_array *v12;
  System_Int16_array *v14;
  pbGroupData_t_o *v16;
  s64 v17;
  struct pbBlockData_t_array *blk;
  struct pbBlockData_t_o *v19;
  s32 grpID;
  s16 v22;
  s16 v23;
  struct pbBlockData_t_array *v24;
  s64 v26;

  core = (*grp)->core;
  y = core->y;
  v10 = pbMoveDir->m_Items[dir];
  core->y = v10->m_Items[0] + y;
  v12 = pbMoveDir;
  v14 = v12->m_Items[dir];
  (*grp)->core->x += v14->m_Items[1];
  v16 = *grp;
  if ((*grp)->num >= 1)
  {
    v17 = 4;
    do
    {
      blk = v16->blk;
      v19 = v16->core;
      grpID = v16->grpID;
      v22 = *(*(&blk->obj.klass + v17) + 18LL) + v19->x;
      v23 = *(*(&v16->blk->obj.klass + v17) + 20LL) + v19->y;
      pb_General__SET_MAP_GRPID_(v22, v23, grpID);
      v24 = (*grp)->blk;
      pb_General__SET_MAP_BLK_(v22, v23, *(*(&v24->obj.klass + v17) + 16LL), 0);
      v16 = *grp;
      v26 = v17 - 3;
      ++v17;
    }
    while (v26 < (*grp)->num);
  }
}

// 0x1662f70
void setRoundBlockData(pbGroupData_t **grp, s32 dir) {
  pbGroupData_t_o *v6;
  s64 v7;
  struct pbBlockData_t_array *blk;
  u64 v9;
  struct pbBlockData_t_array *v10;
  s64 v11;
  s64 v12;
  s32 v13;
  s32 v14;
  struct pbBlockData_t_array *v16;
  struct pbBlockData_t_o *core;
  s32 grpID;
  s16 v20;
  s16 v21;
  struct pbBlockData_t_array *v22;
  s64 v24;

  sub_854930(&(*grp)->angle, 1u);
  v6 = *grp;
  if ((*grp)->num >= 1)
  {
    v7 = 4;
    do
    {
      blk = v6->blk;
      v9 = v7 - 4;
      v10 = blk;
      v11 = *(&blk->obj.klass + v7);
      v12 = *(&v10->obj.klass + v7);
      else
      {
        v13 = *(v11 + 18);
        v14 = *(v12 + 20);
        if (v14 | v13)
          goto LABEL_12;
      }
      v16 = (*grp)->blk;
      core = (*grp)->core;
      grpID = (*grp)->grpID;
      v20 = *(*(&v16->obj.klass + v7) + 18LL) + core->x;
      v21 = *(*(&(*grp)->blk->obj.klass + v7) + 20LL) + core->y;
      pb_General__SET_MAP_GRPID_(v20, v21, grpID);
      v22 = (*grp)->blk;
      pb_General__SET_MAP_BLK_(v20, v21, *(*(&v22->obj.klass + v7) + 16LL), 0);
      v6 = *grp;
      v24 = v7 - 3;
      ++v7;
    }
    while (v24 < (*grp)->num);
  }
  pbRebuildOutline(grp);
}

// 0x16589c0
void updateMotion(void) {
  u64 v2;
  s64 v3;
  struct pbProcHandle_t_array *mychar;

  v2 = 0;
  v3 = 32;
  {
LABEL_6:
  }
  while (v2 < pbWk->bup->pchar_num)
  {
    {
      {
      }
    }
    else if (v2 >= LODWORD(mychar->max_length))
    {
      goto LABEL_17;
    }
    pbChangeMotion((mychar + v3), 0, 0);
    ++v2;
    v3 += 8;
      goto LABEL_6;
  }
}

// 0x1665500
dds3ProcessFunc_t *viewModeCamera(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v7;
  u64 *image;
  s64 v9;
  char *v10;
  s64 *v11;
  UnityEngine_GameObject_o *RenderCamera;
  s32 v15;
  f32 v17;
  char *v21;
  s64 *v22;
  s64 v23;
  s64 v24;
  s64 v25;
  s32 v26;
  char *v27;

  v23 = 0;
  v24 = 0;
  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, &v25);
    if ((v25 & 1) != 0)
      v21 = v27;
    else
      v21 = &v25 + 1;
    v22 = sub_8C4940(v21);
  }
  v7 = workdata[2].klass;
  if (v7)
  {
    image = v7->_1.image;
    if (*(v7->_1.image + 288) < v9 || *(image[25] + 8 * v9 - 8) != pbViewModeCamera_t)
    {
      sub_8FC2C0(image[8], pbViewModeCamera_t, &v25);
      if ((v25 & 1) != 0)
        v10 = v27;
      else
        v10 = &v25 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  v23 = 0;
  v24 = 0;
  RenderCamera = GetRenderCamera(kernelObject);
  GetComponent_object_(RenderCamera);
  v26 = 0;
  v25 = 0;
  sub_8524C0(&v25, 0.0, 0.0, 0.0);
  v15 = pb_General__PB_PROC_REF_MESS(workdata);
  if (v15 == 5)
    goto LABEL_29;
  if (v15 == 1)
  {
    pb_General__PB_PROC_SEND_MESS(workdata, 0);
  }
  v17 = *&v7->_1.name;
  if (v17 >= 1.025)
  {
LABEL_29:
    id->func_ans = -1;
  }
  else
  {
    *&v7->_1.name = v17 + 0.005;
    sub_854710(&v7->_1.name + 4, 0);
    sub_854710(&v7->_1.byval_arg.data + 4, 0);
    sub_854930(&v23, 0);
    sub_854710(&v23, 0);
    sub_854930(&v23, 0);
    sub_854710(&v23, 0);
    sub_854710(&v7->_1.byval_arg.data + 4, 0);
    sub_854930(&v7->_1.name + 4, 0);
    sub_854710(&v7->_1.name + 4, 1u);
    sub_854710(&v7->_1.byval_arg.data + 4, 1u);
    sub_854930(&v23, 1u);
    sub_854710(&v23, 1u);
    sub_854930(&v23, 1u);
    sub_854710(&v23, 1u);
    sub_854710(&v7->_1.byval_arg.data + 4, 1u);
    sub_854930(&v7->_1.name + 4, 1u);
    sub_854710(&v7->_1.name + 4, 2u);
    sub_854710(&v7->_1.byval_arg.data + 4, 2u);
    sub_854930(&v23, 2u);
    sub_854710(&v23, 2u);
    sub_854930(&v23, 2u);
    sub_854710(&v23, 2u);
    sub_854710(&v7->_1.byval_arg.data + 4, 2u);
    sub_854930(&v7->_1.name + 4, 2u);
    sub_854710(&v7->_1.name + 4, 3u);
    sub_854710(&v7->_1.byval_arg.data + 4, 3u);
    sub_854930(&v23, 3u);
    sub_854710(&v23, 3u);
    sub_854930(&v23, 3u);
    sub_854710(&v23, 3u);
    sub_854710(&v7->_1.byval_arg.data + 4, 3u);
    sub_854930(&v7->_1.name + 4, 3u);
    SDF_VU0__COPYVECTOR(&dds3CameraEyePos, *(&v7->_1.name + 4), 0);
    SDF_VU0__COPYVECTOR(
      &dds3CameraTargetPos,
      *(&v7->_1.byval_arg + 4),
      0);
  }
  return 0;
}
