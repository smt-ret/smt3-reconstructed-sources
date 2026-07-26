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
static u32 bupmap[UNKNOWN_ARRAY_SIZE];
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
static pbLevelTable_t *pbLevelTable[UNKNOWN_ARRAY_SIZE];
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
  pbGame_c *v2;
  s16 v3;
  s32 v4;
  struct pbGame_StaticFields **p_static_fields;
  struct pbGame_StaticFields *static_fields;
  struct pbGame_StaticFields *v7;
  struct pbGame_StaticFields *v8;
  UnityEngine_GameObject_o *RenderCamera;
  pbModel_c *v13;
  struct pbModel_StaticFields *v14;
  f32 x;
  f32 y;
  f32 z;
  struct UnityEngine_Vector3_array *pbcCameraPos;
  u32 pb_cdir;
  struct pbModel_StaticFields *v20;
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
  struct pbModel_StaticFields *v49;
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
    p_static_fields = &v2->static_fields;
    static_fields = v2->static_fields;
    if (static_fields->degree_mode)
  }
  else
  {
    v4 = 0;
    p_static_fields = &pbGame->static_fields;
    static_fields = pbGame->static_fields;
    if (static_fields->degree_mode)
    {
      static_fields->cameraDegree = static_fields->cameraDegree + 0.3;
      v7 = v2->static_fields;
      if (v7->cameraDegree > 1.5608)
      {
        v7->cameraDegree = 1.5608;
        (*p_static_fields)->degree_mode = 0;
        (*p_static_fields)->cameraDegree = (*p_static_fields)->cameraDegreeInit;
      }
    }
  }
  static_fields->cameraDegree = static_fields->cameraDegree + -0.15;
  v8 = v2->static_fields;
  if (v8->cameraDegree < v8->cameraDegreeInit)
  {
    v8->cameraDegree = v8->cameraDegreeInit;
    (*p_static_fields)->degree_mode = 0;
  }
  RenderCamera = GetRenderCamera(kernelObject);
  GetComponent_object_(RenderCamera);
  if (pbViewChangeflag == 1)
  {
    v14 = v13->static_fields;
    x = v14->r_cameraPos.x;
    y = v14->r_cameraPos.y;
    z = v14->r_cameraPos.z;
    pbcCameraPos = v14->pbcCameraPos;
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
    v20 = v13->static_fields;
    v21 = v20->r_cameraPos.x;
    v22 = v20->r_cameraPos.y;
    v23 = v20->r_cameraPos.z;
    v24 = v20->pbcCameraPos;
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
  v49 = pbModel->static_fields;
  v49->r_cameraPos.x = v51;
  v49->r_cameraPos.y = v52;
  v49->r_cameraPos.z = v53;
  pbChangeCameraMovflag = 1;
}

// 0x1665b70
dds3ProcessFunc_t *ClearProc(dds3ProcessID_t *id) {
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
    ButtonGuideDispOff();
    pbGotoNewStage();
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
}

// 0x1662e20
void SetCameraQuake(s32 frame, s32 range) {
  pbGame_c *v5;
  struct pbGame_StaticFields *static_fields;
  s64 v7;

  if (range)
  {
    pbCameraQuakeflag = 1;
    if (frame)
    {
      pbQuakeFrame = frame;
      if ((v5->_2.bitflags2 & 2) == 0)
    }
    else
    {
      pbQuakeFrame = -1;
      if ((v5->_2.bitflags2 & 2) == 0)
    }
    pbQuakePosY = 10 * range;
    static_fields = v5->static_fields;
    v7 = 6871947676LL * static_fields->pbQuakePosY;
    static_fields->pbQuakePosX = (v7 >> 34) + (v7 >> 63);
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
  v12 = Find(StringLiteral_5594, 0);
  if (op_Inequality(v12, 0, 0) && !get_activeSelf(v12))
    SetActive(v12, 1, 0);
  if (op_Inequality(pModelObj, 0, 0))
  {
    v18 = pModelObj;
    Destroy_27360000(v18);
    pModelObj = 0;
  }
  SetActive(kernelObject->btldevil, 0, 0);
  Remove(StringLiteral_21769, 0);
  ButtonGuideDispOff();
  ClearoPB_UI();
  return 0;
}

// 0x1662910
dds3ProcessFunc_t *deleteMoveBlock(dds3ProcessID_t *id) {
    SetCameraQuake(0, 0);
    pbPushRecord(0);
    pb_General__SET_MAP_HALL_(0, 0, 0);
    pbReleaseGroupDB(0, 0);
    setMoveBlockData(0, 0);
    hallCheck(0);
    pbStartMoveBlock(0, 0, 0);
    return 0;
}

// 0x1661a20
dds3ProcessFunc_t *deleteMoveChar(dds3ProcessID_t *id) {
    pbMoveMyCharcter2(0, 0, 0);
    pbGetMyCharcterPos2(0, 0, 0);
    FindId(0, 0);
    p2sdPlaySE(0);
    getCharacterNum();
    dds3KillProcess(0, 0);
    pbChangeMotion(0, 0);
    pbGetCurrentProcess();
    pbStartClear(0);
    pbClearRecord(0);
    pbDispMyCharacter(0, 0);
    return 0;
}

// 0x1665320
dds3ProcessFunc_t *deleteRoundAutoCamera(dds3ProcessID_t *id) {
    return 0;
}

// 0x1663660
dds3ProcessFunc_t *deleteRoundBlock(dds3ProcessID_t *id) {
    pbPushRecord(0);
    setRoundBlockData(0, 0);
    return 0;
}

// 0x1665a50
dds3ProcessFunc_t *deleteViewModeCamera(dds3ProcessID_t *id) {
    return 0;
}

// 0x165f770
dds3ProcessFunc_t *game(dds3ProcessID_t *id) {
    pb_General__PB_PROC_REF_MESS(0);
    pbInitGame(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    ButtonGuideDispSet(0, 0, 0, 0);
    pbSetMyCharcterRot(0, 0);
    hitCheck(0, 0);
    FindId(0, 0);
    p2sdPlaySE(0);
    pbStartMoveChar(0, 0, 0);
    pbAddRecord_char(0, 0, 0);
    pbStartMoveBlock(0, 0, 0);
    roundDirCheck(0, 0, 0);
    pbStartRoundBlock(0, 0, 0);
    pbChangeMotion(0, 0);
    DDS3_PADCHECK_TRIG(0);
    pbStartMenu(0, 0);
    dds3SearchProcessName(0);
    CalcDegreeMode();
    pbRotateYCamera2(0, 0, 0);
    fclChkMessageDraw(0);
    fclChkSignal(0);
    pbGetCurrentProcess();
    return 0;
}

// 0x165ad30
s32 gameKey0(void) {
    DDS3_PADCHECK_PRESS(0);
    DDS3_PADCHECK_REP(0);
    pbGetKeyAction(0);
    pbRotateXCamera(0);
    pbRoundCamera(0);
    return 0;
}

// 0x165b440
s32 gameKey1(void) {
    DDS3_PADCHECK_TRIG(0);
    FindId(0, 0);
    p2sdPlaySE(0);
    pbSetMapCursorFlag(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    pb_General__PB_PROC_SEND_MESS(0, 0);
    pbGetMyCharcterPos2(0, 0, 0);
    pbStartViewModeCamera(0);
    DDS3_PADCHECK_PRESS(0);
    pbGetKeyAction(0);
    ButtonGuideDispSet(0, 0, 0, 0);
    pbSetGameCamera4(0, 0);
    ScrollArrowDraw();
    pbGetKeyMode();
    pbRoundCamera(0);
    GetMainCamera(0);
    GetRenderCamera(0);
    return 0;
}

// 0x165ea60
s32 gameKey2(void) {
    DDS3_PADCHECK_PRESS(0);
    DDS3_PADCHECK_REP(0);
    pbGetKeyAction(0);
    pbRotateXCamera(0);
    pbRotateYCamera(0);
    return 0;
}

// 0x165ed80
u32 getCharacterNum(void) {
    pbMyCharacterDispStat(0);
    return 0;
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
    pbGetMyCharcterPos2(0, 0, 0);
    pb_General__GET_MAP_HALL_(0, 0);
    pb_General__GET_MAP_BLK_(0, 0);
    pb_General__GET_MAP_GRPID_(0, 0);
    pushCheck(0, 0, 0);
    roundCheck(0, 0, 0);
    return 0;
}

// 0x1662570
dds3ProcessFunc_t *moveBlock(dds3ProcessID_t *id) {
    return 0;
}

// 0x1661620
dds3ProcessFunc_t *moveChar(dds3ProcessID_t *id) {
    pbMoveMyCharcter(0, 0, 0);
    return 0;
}

// 0x1667f30
s8 pbCheckPreviousRecord(void) {
  return pbCheckPopRecord(&record);
}

// 0x1643440
void pbGetCameraParam(sdfVector4_t out) {
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
    Write(StringLiteral_21779, 0);
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
    pbRotateYCamera2(0, 0, 0);
    Set(0, 0);
    pbCheckMap();
    dds3FadeIn2(0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    pbInitMyCharacterDraw(0, 0, 0);
    pbDispMyCharacter(0, 0);
    pbSetMyCharcterPos2(0, 0, 0);
    updateMotion();
    pbClearRecord(0);
    GetStageScriptLabel();
    fclClearSignal(0);
    fclSetVal(0, 0);
    scrStartScript2(0, 0, 0);
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
  pbGame_c *v15;
  struct pbGame_StaticFields *static_fields;
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
      static_fields = v15->static_fields;
      v18 = static_fields->cameraFunc;
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
  struct pbGame_StaticFields *v22;
  s32 *v23;
  s64 v24;
  u32 *v26;
  s32 v27;
  s32 v28;
  struct pbGame_StaticFields *v29;

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
      }
      else
      {
        pbcCameraPos = pbCameraPos;
        if ((v9->_2.bitflags2 & 2) == 0)
      }
      static_fields = v9->static_fields;
      v17 = static_fields[51];
      v19 = (pbcCameraPos + 12 * v17);
      v20 = v19[9];
      v21 = v19[8];
      LODWORD(v19) = v19[10];
      static_fields[82] = v21;
      static_fields[83] = v20;
      static_fields[84] = v19;
      ++pb_cdir;
      v22 = v9->static_fields;
      if (v22->pb_cdir >= 4)
      {
        v22->pb_cdir = 0;
      }
      return;
    }
    pbRotLKeyAct();
    if (pbViewChangeflag)
    {
      pbCameraPos = pbcCameraPos;
      if ((v13->_2.bitflags2 & 2) == 0)
    }
    else
    {
      if ((v13->_2.bitflags2 & 2) == 0)
    }
    v23 = v13->static_fields;
    v24 = v23[51];
    v26 = (pbCameraPos + 12 * v24);
    v27 = v26[9];
    v28 = v26[8];
    LODWORD(v26) = v26[10];
    v23[82] = v28;
    v23[83] = v27;
    v23[84] = v26;
    --pb_cdir;
    v29 = v13->static_fields;
    if (v29->pb_cdir < 0)
    {
      v29->pb_cdir = 3;
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
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x16670c0
void pbSetGameCamera1(void) {
    pbGetMyCharcterPos(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1667640
void pbSetGameCamera2(void) {
    pbGetMyCharcterPos(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1667bc0
void pbSetGameCamera3(void) {
    pbGetMyCharcterPos(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    pbGetMyCharcterRot(0);
}

// 0x165d1a0
void pbSetGameCamera4(s16 x, s16 y) {
    GetRenderCamera(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1666f60
void pbSetGameCameraUnity(void) {
  ;
}

// 0x1666ba0
pbProcHandle_t *pbStartAutoRoundCamera(pbProcHandle_t *parent, s32 dir) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    pbGetKeyMode();
    dds3SetProcessData(0, 0);
    dds3SearchProcessName(0);
    dds3ResetProcessFlag(0, 0, 0);
    return 0;
}

// 0x1662090
pbProcHandle_t *pbStartClear(pbProcHandle_t *parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
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
  v4->id = dds3StartProcess(StringLiteral_21772, 0x3EEu, 1, 1, v9, 0, v10, 0, 0, 0);
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
  Id = FindId(0, StringLiteral_11814);
  p2sdPlayBGM(Id);
  cameraAngle = 0.0;
  cameraRadius = 700.0;
  cameraDegree = 1.1;
  cameraDegreeInit = 1.1;
  pbInitGameCamera();
  v36 = Find(StringLiteral_5594, 0);
  if (op_Inequality(v36, 0, 0) && get_activeSelf(v36))
    SetActive(v36, 0, 0);
  dds3FadeIn2(0x1Eu);
  if (op_Equality(oPB_UI, 0, 0))
  {
    asset_bc = get_asset_bc();
    Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_4611, StringLiteral_5156, StringLiteral_21773);
    v44 = Find(StringLiteral_4905, 0);
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
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    dds3SetProcessData(0, 0);
    FindId(0, 0);
    p2sdPlaySE(0);
    pbAddRecord_flor(0, 0);
    dds3PadAct(0, 0, 0);
    pbAddRecord_blk(0, 0);
    pb_General__CLR_MAP_BLKDAT_(0, 0);
    return 0;
}

// 0x16605a0
pbProcHandle_t *pbStartMoveChar(pbProcHandle_t *parent, s32 dir, u32 scl) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    dds3SetProcessData(0, 0);
    pbChangeMotion(0, 0);
    return 0;
}

// 0x1660d20
pbProcHandle_t *pbStartRoundBlock(pbProcHandle_t *parent, pbGroupData_t *grp, s32 dir) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    dds3SetProcessData(0, 0);
    pbAddRecord_blk(0, 0);
    pb_General__CLR_MAP_BLKDAT_(0, 0);
    return 0;
}

// 0x165cee0
pbProcHandle_t *pbStartViewModeCamera(pbProcHandle_t *parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    dds3SetProcessData(0, 0);
    return 0;
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
    GetRenderCamera(0);
    pbRotateYCamera2(0, 0, 0);
    return 0;
}

// 0x1663230
dds3ProcessFunc_t *roundBlock(dds3ProcessID_t *id) {
    return 0;
}

// 0x1659090
u32 roundCheck(s32 dir, u32 grpID, pbGroupData_t **grp) {
    pbSearchGroupDB(0, 0);
    pbGetMyCharcterPos2(0, 0, 0);
    roundDirCheck(0, 0, 0);
    pb_General__GET_MAP_HALL_(0, 0);
    pb_General__GET_MAP_BLK_(0, 0);
    pb_General__GET_MAP_GRPID_(0, 0);
    return 0;
}

// 0x1659810
s32 roundDirCheck(s32 dir, u32 grpID, u32 *speed) {
    pbSearchGroupDB(0, 0);
    pbGetMyCharcterPos2(0, 0, 0);
    pb_General__GET_MAP_GRPID_(0, 0);
    return 0;
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
    pb_General__SET_MAP_GRPID_(0, 0, 0);
    pb_General__SET_MAP_BLK_(0, 0, 0);
    pbRebuildOutline(0);
}

// 0x16589c0
void updateMotion(void) {
    pbChangeMotion(0, 0);
}

// 0x1665500
dds3ProcessFunc_t *viewModeCamera(dds3ProcessID_t *id) {
    GetRenderCamera(0);
    pb_General__PB_PROC_REF_MESS(0);
    pb_General__PB_PROC_SEND_MESS(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    return 0;
}
