#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effHandle_t effHandle_t;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldRunSuspendData fldRunSuspendData;
typedef struct fldTest_FLDRUN_DANTE_t fldTest_FLDRUN_DANTE_t;
typedef struct fldTest_FLDRUN_DOOR_t fldTest_FLDRUN_DOOR_t;
typedef struct fldTest_FLDRUN_EFFTBL_t fldTest_FLDRUN_EFFTBL_t;
typedef struct fldTest_FLDRUN_EFF_t fldTest_FLDRUN_EFF_t;
typedef struct fldTest_FLDRUN_PLAYER_t fldTest_FLDRUN_PLAYER_t;
typedef struct fldTest_FRO_HEAD_t fldTest_FRO_HEAD_t;
typedef struct fldTest_FRO_MAPDATA_t fldTest_FRO_MAPDATA_t;
typedef struct fldTest_FRO_MAPHEADER_t fldTest_FRO_MAPHEADER_t;
typedef struct fldTest_FRO_ROUTEDATA_t fldTest_FRO_ROUTEDATA_t;
typedef struct fldTest_FRO_ROUTEIDX_t fldTest_FRO_ROUTEIDX_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

struct fldTest_FLDRUN_DANTE_t {
    s32 status;
    f32 x;
    f32 y;
    f32 z;
    f32 r;
    f32 oldframe;
    f32 nowframe;
    s16 ix;
    s16 iz;
    s16 goal_ix;
    s16 goal_iz;
    s16 tikamiti;
    s16 wkmode;
    s32 RouteIdx;
    s32 RouteDataTop;
    s32 now;
    s32 goal;
    s32 nextframe;
    f32 dir;
    f32 speed;
    s32 cnt_ex;
    s32 gunlight_anime;
    s32 update_flag;
    s32 motion;
    s32 bgm_mode;
    f32 d_p_len;
    f32 d_p_dir;
    f32 d_c_dir;
    s32 stance;
    fldTest_FLDRUN_DOOR_t *pDoor;
    s16 backup_ix;
    s16 backup_iz;
    s32 old_status;
};

struct fldTest_FLDRUN_PLAYER_t {
    s16 ix;
    s16 iz;
};

struct fldTest_FLDRUN_EFF_t {
    sdfMemHandle_t *mhFile;
    void *ptr;
    s32 size;
    effPartHandle_t *pcf;
    effHandle_t *d3p;
    s32 cnt;
    f32 x;
    f32 y;
    f32 z;
    f32 r;
};

struct fldTest_FRO_HEAD_t {
    u32 RouteAddr;
    u32 RouteNum;
    u32 MapAddr;
    u32 Res;
};

struct fldTest_FRO_MAPHEADER_t {
    u16 sizex;
    u16 sizez;
    u32 MapAddr;
    u32 MapNum;
    u32 res;
};

struct fldTest_FLDRUN_DOOR_t {
    char *name;
    s16 ix;
    s16 iz;
    f32 dir;
};

struct fldTest_FRO_ROUTEIDX_t {
    u8 sx;
    u8 sz;
    u8 gx;
    u8 gz;
    u32 flag;
    u32 RouteAddr;
    u32 RouteNum;
};

struct fldTest_FRO_MAPDATA_t {
    u8 link;
    u8 res;
};

struct fldTest_FLDRUN_EFFTBL_t {
    fldTest_FLDRUN_EFF_t *pEff;
    s32 time;
    s32 effmode;
    s32 rotmode;
    f32 off_cam_range_min;
    f32 off_cam_range_max;
};

struct fldTest_FRO_ROUTEDATA_t {
    u8 x;
    u8 z;
    u16 d;
};

static fldTest_FLDRUN_DANTE_t *fldRun_Dante;
static fldTest_FLDRUN_PLAYER_t *fldRun_Player;
static s32 FRO_MDLINK__U;
static s32 FRO_MDLINK_RU;
static s32 FRO_MDLINK_R_;
static s32 FRO_MDLINK_RD;
static s32 FRO_MDLINK__D;
static s32 FRO_MDLINK_LD;
static s32 FRO_MDLINK_L_;
static s32 FRO_MDLINK_LU;
static f32 ooyTestCamSaka;
static f32 ooyCamKakudo;
static f32 ooyCamKakudoY;
static f32 ooyCamLeng;
static s32 ELEVPOS_X;
static s32 ELEVPOS_Y;
static fldRunSuspendData *SuspendData;
static fldRunSuspendData *SuspendDataCopy;
static bool bSuspendBGM;
static bool bMotionRestart;
static bool bFirstStance;
static char *elvfont[13];
static s32 gFldElvFloorNow;
static s32 gFldElvFloorFrom;
static s32 gFldElvFloorFromR;
static s32 gFldElvFloorTo;
static s32 gFldElvFloorToR;
static s32 gFldElvFloorAnmCnt;
static s32 gFldElvFloorCancel;
static sdfVector4_t fldSdwDraw_lightv;
static s32 fldSdwDraw_srgba;
static s32 fldSdwDraw_sdwlink;
static bool fldSdwDraw_Skip1;
static s32 MotionAnimTable[5];
static fldTest_FLDRUN_EFF_t *fldRunEff_DSPARK01_PCF;
static fldTest_FLDRUN_EFF_t *fldRunEff_DSMOKE2_D3P;
static fldTest_FLDRUN_EFF_t *fldRunEff_DSPARK02_D3P;
static fldTest_FLDRUN_EFF_t *fldRunEff_GUN02A_D3P;
static fldTest_FLDRUN_EFF_t *fldRunEff_GUN01A0_D3P;
static fldTest_FLDRUN_EFF_t *fldRunEff_MUZZLE_B010_PCF;
static fldTest_FLDRUN_EFF_t *fldRunEff_DSMOKE1_D3P;
static fldTest_FLDRUN_EFF_t *fldRunEff_DFLASH1_PCF;
static void *fldRunEff_Tex[2];
static s16 fldRun_MAP_OX;
static s16 fldRun_MAP_OZ;
static s16 fldRun_MAP_BX;
static s16 fldRun_MAP_BZ;
static s32 FLDRUN_BGM_NML;
static s32 FLDRUN_BGM_BTL;
static s32 FLDRUN_GUNDMGCNT;
static fldTest_FRO_HEAD_t *pFroHead;
static fldTest_FRO_ROUTEIDX_t *pFroRouteIdx;
static u8 *pFroRouteData;
static fldTest_FRO_MAPHEADER_t *pFroMapHead;
static fldTest_FRO_MAPDATA_t *pFroMapData;
static fldTest_FLDRUN_EFFTBL_t *fldRunEffTbl_0[5];
static fldTest_FLDRUN_EFFTBL_t *fldRunEffTbl_1[5];
static fldTest_FLDRUN_EFFTBL_t **fldRunEffTbl_All;
static fldTest_FLDRUN_DOOR_t *fldRunDoorTbl[8];
static dds3Basic_t *fldBasic_tama1;
static dds3Basic_t *fldBasic_tama2;
static dds3Basic_t *fldBasic_tama3;
static s32 fldRunTamaSet_flip_cnt;
static s32 fldRunDanteSe_asise;

void Copy(fldTest_FLDRUN_DOOR_t *this, fldTest_FLDRUN_DOOR_t *t);
bool DDS3_PADCHECK_TRIG(s32 id);
s32 FindId(s32 type, char *name);
s32 FroFtoI(f32 fx, f32 fz, s16 *rx, s16 *rz);
s32 FroGetRouteIdx(s16 sx, s16 sz, s16 gx, s16 gz);
void FroLoad(void);
void FromRotation(f32 aAngle);
fldTest_FRO_ROUTEDATA_t *GetFroRouteData(s32 id);
s32 GetMotionMinorNum(void);
bool IsDLC(void);
bool IsDLCField(s32 area);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void Mult(void);
f32 R360_LR(f32 a, f32 b);
void ReleaseManiacsChar(void);
void Restore(fldRunSuspendData *this, fldTest_FLDRUN_DANTE_t **d, fldTest_FLDRUN_PLAYER_t **p);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetAreaUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, char *text, u32 rgba);
void SetRotateMatrixY(f32 aAngle);
void StopSE_ALL(void);
void aDrawBoxF(s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 a);
void billClrTexture(bool allclear);
void billSetTexture(void **pTexture);
void datPartyDamageFld(s32 mode);
dds3Basic_t *dds3AddUnitObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot);
void dds3EffectDelete(void **pData);
void dds3EffectDraw(void **pData);
u16 dds3EffectGetState(effHandle_t *hEffect);
effHandle_t *dds3EffectLoad(void **pD3P, s32 bPos, bool tbldata);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos);
void dds3EffectPartSetRotateMatrix(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix);
void dds3EffectSetPosition(void **pData, sdfVector4_t pPos);
void dds3EffectSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix);
dds3Basic_t *dds3GetActiveScene(void);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
u32 dds3GetRandA(char *name);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3ObjectBaseGetModelHandle(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseMakeUnit(dds3Basic_t **pObjectBasic, s32 major, s32 minor);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3OnPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
u32 dds3SerializeID(void);
void dds3SetBasicName(dds3Basic_t **basic, char *name);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 encChk(void);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
s32 fldAutoMapChkMode(void);
void fldCamElvEnd(void);
void fldCamElvStart(s32 updown);
s32 fldDoor_ElvTakasaToFloor(s32 takasa);
void fldDoor_Start(s32 evehit_resid);
void fldDrawBokasi(void);
void fldElvFloorDraw(s32 x, s32 y, s32 floor);
s32 fldGetRestoreMode(void);
s32 fldHitChkEnemy(sdfVector4_t cpos, sdfVector4_t tpos, sdfVector4_t hitpos);
void fldMakeFilePath(char **pathstr, s32 field, s32 area);
void *fldPlayer3LoadForUnity(void);
s32 fldProcCampChk(void);
s8 fldProcCheckFlag(u32 flag);
void fldRunAiCng(s32 stat);
void fldRunCngBgm(s32 mode);
void fldRunDanteAi(void);
void fldRunDanteCollision(void);
void fldRunDanteDoin(void);
void fldRunDanteGun1(void);
void fldRunDanteGun2(void);
void fldRunDanteMove(void);
void fldRunDantePatr(void);
void fldRunDantePwak(void);
void fldRunDanteSe(void);
void fldRunDanteSetModel(void);
void fldRunDanteSoba(void);
void fldRunDanteStanceSet(s32 id, bool recover);
void fldRunDanteWait(void);
void fldRunEffSet(s32 id, f32 x, f32 y, f32 z, f32 r);
void fldRunEffTask(void);
void fldRunGetLenKakudo(f32 *len, f32 *kakudo);
void fldRunGetLenKakudo2(f32 fx, f32 fz, f32 *len, f32 *kakudo);
void fldRunSoundLoad(void);
void fldRunTamaFree(void);
void fldRunTamaInit(void);
void fldRunTamaSe(void);
void fldRunTamaSet(f32 x, f32 y, f32 z, f32 r);
s32 fldRunVolCalc(f32 x, f32 y, f32 z);
void fldSkyDrawFilter(void);
void fldTest_FRO_HEAD_t__Set(fldTest_FRO_HEAD_t *this, u8 **ptr, s32 *addr);
void fldTest_FRO_MAPHEADER_t__Set(fldTest_FRO_MAPHEADER_t *this, u8 **ptr, s32 *addr);
void fldTest_FRO_ROUTEIDX_t__Set(fldTest_FRO_ROUTEIDX_t *this, u8 **ptr, s32 *addr);
void frSetFontDrawOT(u32 OtType);
s32 mdlGetMotionFrame(dds3ModelHandle_t **aHandle);
s32 mdlGetMotionFrameForUnity(void *obj);
s32 mdlGetMotionMinorNum(dds3ModelHandle_t **aHandle);
void mdlSetMotionSpeed(dds3ModelHandle_t **aHandle, f32 speed);
void mdlSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber);
void mdlSmoothLoopMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);
void ooyTestDrawMaruKage(f32 x, f32 y, f32 z, f32 r, s32 a);
void p2sdFadeIn2_20177360(char *define_name);
void p2sdFadeOut_20177680(char *define_name);
void p2sdPlaySE_Vol(s32 SENo, s32 vol);
void p2sdPlaySE_Vol_20173952(char *define_name, s32 volume);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
f32 sdfFabs(f32 c);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSin(f32 aRadius);
f32 sdfSqrt(f32 aValue);

// 0x17831d0
void Copy(fldTest_FLDRUN_DOOR_t *this, fldTest_FLDRUN_DOOR_t *t) {
  this->fields = t->fields;
}

// 0x1786960
void FroFree(void) {
  pFroMapData = 0;
  pFroMapHead = 0;
  pFroRouteData = 0;
  pFroRouteIdx = 0;
  pFroHead = 0;
}

// 0x1781ca0
s32 FroFtoI(f32 fx, f32 fz, s16 *rx, s16 *rz) {
  f32 v5;
  f32 v6;
  fldTest_c *v7;
  int16x4_t v9;
  f32 v10;
  f32 v11;
  s16 v12;
  s16 v13;
  s16 v14;
  f32 v15;
  s16 v16;
  s32 sizex;
  struct fldTest_FRO_MAPDATA_t_array *pFroMapData;
  s32 v20;
  f32 v24;
  f32 v25;
  f32 v26;

  v5 = fz;
  v6 = fx;
  LOWORD(fx) = fldRun_MAP_OX;
  v9.n64_u64[0] = vmovl_s16(*&fx).n128_u64[0];
  v10 = v9.n64_i32[0];
  v9.n64_u16[0] = fldRun_MAP_OZ;
  v11 = 10000.0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = vmovl_s16(v9).n128_i32[0];
  if ((v7->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
  while (v14 < pFroMapHead->sizez)
  {
    v16 = 0;
    if ((v7->_2.bitflags2 & 2) == 0)
      goto LABEL_17;
LABEL_15:
LABEL_17:
    while (1)
    {
      sizex = pFroMapHead->sizex;
      if (v16 >= sizex)
        break;
      v20 = v16 + sizex * v14;
      if (pFroMapData->m_Items[v20]->link)
      {
        LOWORD(fz) = fldRun_MAP_BX;
        v24 = v5 - ((v14 * -fldRun_MAP_BZ) + v15);
        v25 = v6 - ((v16 * vmovl_s16(*&fz).n128_i32[0]) + v10);
        v26 = sdfSqrt((v25 * v25) + (v24 * v24), 0);
        if (v11 > v26)
        {
          v11 = v26;
          v12 = v14;
          v13 = v16;
        }
      }
      ++v16;
        goto LABEL_15;
    }
    ++v14;
    if ((v7->_2.bitflags2 & 2) != 0)
      goto LABEL_9;
  }
  *rx = v13;
  *rz = v12;
  if (v12 | v13)
    return 0;
  else
    return -1;
}

// 0x17869f0
s32 FroGetRouteIdx(s16 sx, s16 sz, s16 gx, s16 gz) {
  fldTest_c *v9;
  struct fldTest_FRO_ROUTEIDX_t_array *pFroRouteIdx;
  u64 v11;
  fldTest_FRO_ROUTEIDX_t_o **m_Items;
  u8 *v13;

  v11 = 0;
  m_Items = pFroRouteIdx->m_Items;
  if ((v9->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
  while (v11 < pFroHead->RouteNum)
  {
    v13 = m_Items[v11];
    if (v13[16] == sx && v13[17] == sz && v13[18] == gx && m_Items[v11]->gz == gz)
      return v11;
    ++v11;
      goto LABEL_9;
  }
  return -1;
}

// 0x1783070
void FroItoF(s16 ix, s16 iz, f32 *fx, f32 *fz) {
  int16x4_t v5;
  int16x4_t v6;
  int16x4_t v7;

  v7.n64_u16[0] = fldRun_MAP_BX;
  v5.n64_u16[0] = fldRun_MAP_OX;
  v6.n64_u16[0] = fldRun_MAP_OZ;
  *fx = (ix * vmovl_s16(v7).n128_i32[0]) + vmovl_s16(v5).n128_i32[0];
  *fz = (iz * -fldRun_MAP_BZ) + vmovl_s16(v6).n128_i32[0];
}

// 0x1785d40
void FroLoad(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  u64 *v6;
  System_String_o *v8;
  s32 v9;
  bool IsDLCField;
  s64 *v11;
  System_String_o *v13;
  Il2CppObject *v15;
  u64 *v16;
  u64 *v17;
  System_String_o *v18;
  u64 *v19;
  struct fldTest_FRO_HEAD_t_o *pFroHead;
  u64 RouteNum;
  struct fldTest_FRO_ROUTEIDX_t_array *v26;
  fldTest_c *v27;
  s32 v28;
  s64 v29;
  s16 v30;
  u64 v31;
  s64 v32;
  s32 i;
  struct fldTest_FRO_HEAD_t_o *v35;
  u32 *pFroRouteIdx;
  u64 *v37;
  struct fldTest_FRO_ROUTEIDX_t_array *v40;
  struct fldTest_FRO_ROUTEIDX_t_array *v43;
  struct fldTest_FRO_ROUTEIDX_t_array *v45;
  s64 v47;
  s32 v49;
  u32 v50;
  struct System_Byte_array *v51;
  u64 *v53;
  u64 v56;
  struct fldTest_FRO_MAPDATA_t_array *v58;
  fldTest_c *v59;
  struct fldTest_FRO_MAPHEADER_t_o *pFroMapHead;
  s64 MapAddr;
  s64 v62;
  s64 v63;
  s64 v64;
  u64 v65;
  u32 *pFroMapData;
  u64 *v67;
  struct fldTest_FRO_MAPDATA_t_array *v69;
  System_Byte_array *v71;
  s64 v72;
  char *v74;
  Il2CppObject *v78;
  s32 v79;
  s32 v80;
  s32 addr;
  System_Byte_array *aTopPtr;
  System_String_o *pathstr;

  addr = 0;
  pathstr = "";
  aTopPtr = 0;
  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  fldMakeFilePath(&pathstr, fieldID, areaID + 1);
  v80 = fldGb->fieldID;
  v6 = sub_8D3950(s32, &v80);
  v8 = Format("f{0:D3}", v6, 0);
  v9 = fldGb->fieldID;
  IsDLCField = IsDLCField(v9);
  v11 = &"m";
  if (!IsDLCField)
    v11 = &"";
  v13 = Concat_5224608(v8, *v11);
  v15 = pathstr;
  v80 = fldGb->fieldID;
  v16 = sub_8D3950(s32, &v80);
  v79 = fldGb->areaID + 1;
  v17 = sub_8D3950(s32, &v79);
  v18 = Format_5268688("{0}F{1:D3}_{2:D3}.FRO.bytes", v15, v16, v17);
  sdfDevLoadFileUnity_25061072(v18, &aTopPtr, 0, v13);
  if (!aTopPtr)
  {
    v78 = Concat_5221536("!!!! FileNotFound ", v18, " !!!!!");
    Log(v78, 0);
    return;
  }
  addr = 0;
  v19 = Allocate(fldTest_FRO_HEAD_t);
  _ctor(v19, 0);
  pFroHead = v19;
  fldTest_FRO_HEAD_t__Set(pFroHead, aTopPtr, &addr);
  RouteNum = pFroHead->RouteNum;
  addr = pFroHead->RouteAddr;
  v26 = NewSpecific(fldTest_FRO_ROUTEIDX_t, RouteNum);
  pFroRouteIdx = v26;
  v28 = 0;
  v29 = 4;
  v30 = *&v27->_2.bitflags1;
  v31 = 0;
  if ((v30 & 0x200) != 0)
    goto LABEL_25;
LABEL_24:
  for (i = 0; ; i = v30 & 0x200)
  {
    v35 = pFroHead;
    if (v31 >= v35->RouteNum)
      break;
    v37 = Allocate(fldTest_FRO_ROUTEIDX_t);
    _ctor(v37, 0);
    *&pFroRouteIdx[2 * v29] = v37;
    v40 = pFroRouteIdx;
    fldTest_FRO_ROUTEIDX_t__Set(*(&v40->obj.klass + v29), aTopPtr, &addr);
    if (v28)
    {
        goto LABEL_48;
LABEL_40:
      goto LABEL_48;
    }
    v43 = pFroRouteIdx;
    v28 = *(*(&v43->obj.klass + v29) + 24LL);
      goto LABEL_40;
LABEL_48:
    v45 = pFroRouteIdx;
    v47 = *(&v45->obj.klass + v29);
    v32 = *(&pFroRouteIdx->obj.klass + v29++);
    *(v47 + 24) = (*(v32 + 24) - v28) / 4;
    v30 = *&v27->_2.bitflags1;
    v31 = v29 - 4;
    if ((v30 & 0x200) == 0)
      goto LABEL_24;
LABEL_25:
  }
  v49 = addr;
  v50 = v35->MapAddr - addr;
  v51 = NewSpecific(byte, v50);
  pFroRouteData = v51;
  Copy_3880080(aTopPtr, v49, pFroRouteData, 0, v50);
  addr = pFroHead->MapAddr;
  v53 = Allocate(fldTest_FRO_MAPHEADER_t);
  _ctor(v53, 0);
  pFroMapHead = v53;
  fldTest_FRO_MAPHEADER_t__Set(pFroMapHead, aTopPtr, &addr);
  v56 = pFroMapHead->sizez
      * pFroMapHead->sizex;
  v58 = NewSpecific(fldTest_FRO_MAPDATA_t, v56);
  pFroMapData = v58;
  MapAddr = pFroMapHead->MapAddr;
  addr = pFroMapHead->MapAddr;
  if (v56)
  {
    v62 = 0;
    v63 = 2 * v56 - 2;
    v64 = 4;
    if ((v59->_2.bitflags2 & 2) == 0)
      goto LABEL_61;
LABEL_59:
    while (1)
    {
LABEL_61:
      v65 = v64 - 4;
      v67 = Allocate(fldTest_FRO_MAPDATA_t);
      _ctor(v67, 0);
      *&pFroMapData[2 * v64] = v67;
      v69 = pFroMapData;
      v71 = aTopPtr;
      v72 = *(&v69->obj.klass + v64);
      v74 = aTopPtr + MapAddr + v62;
      *(v72 + 16) = v74[32];
      *(v72 + 17) = v74[33];
      if (v63 == v62)
        break;
      ++v64;
      v62 += 2;
        goto LABEL_59;
    }
    addr = MapAddr + v62 + 2;
  }
}

// 0x177ad10
fldTest_FRO_ROUTEDATA_t *GetFroRouteData(s32 id) {
  u64 *v3;
  struct System_Byte_array *pFroRouteData;
  s64 v7;
  struct System_Byte_array *v9;
  s64 v10;
  System_Byte_array *v12;

  v3 = Allocate(fldTest_FRO_ROUTEDATA_t);
  _ctor(v3, 0);
  v7 = 4LL * id;
  *(v3 + 16) = pFroRouteData->m_Items[v7];
  v9 = pFroRouteData;
  v10 = v7 | 1LL;
  *(v3 + 17) = v9->m_Items[v10];
  v12 = pFroRouteData;
  *(v3 + 9) = ToUInt16(v12, v7 | 2);
  return v3;
}

// 0x177b280
void InitOoyTest(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_fldTest_ooyTestDrawProc__);
  dds3StartProcess("fldTestDraw", 0x2AF8u, 0, 0, v1, 0, 0, 0, 0, 0);
}

// 0x177b350
void KillOoyTest(void) {
  dds3KillProcessName("fldTestDraw", 1);
}

// 0x177ae90
f32 OOYDEG(f32 a) {
  return (a * 180.0) / 3.14;
}

// 0x177ae70
f32 OOYRAD(f32 a) {
  return (a * 3.14) / 180.0;
}

// 0x178c260
void ReleaseChar(void) {
  u64 v4;
  Il2CppClass **v6;
  struct UnityEngine_Texture_array *fldRunEff_Tex;
  u64 max_length_low;

  ReleaseManiacsChar();
  else if (!fldRunEff_Tex)
  {
    return;
  }
  billClrTexture(0);
  v4 = 0;
  {
LABEL_15:
  }
  while (1)
  {
    max_length_low = LODWORD(fldRunEff_Tex->max_length);
    if (v4 >= max_length_low)
      break;
    else if (v4 >= max_length_low)
    {
      goto LABEL_21;
    }
    v6 = &fldRunEff_Tex->obj.klass + v4++;
    v6[4] = 0;
      goto LABEL_15;
  }
  UnloadUnusedAssets();
}

// 0x177c280
bool fldElvChk(void) {
  return gFldElvFloorNow != -999;
}

// 0x177b3c0
void fldElvFloorDraw(s32 x, s32 y, s32 floor) {
  s64 v5;
  u32 v7;
  System_String_o *v8;
  System_String_o *v9;
  System_String_o *v10;
  System_String_o *v11;
  System_String_o *v13;
  dds3DefaultMain_o *kernelObject;
  System_String_o *v16;

  v5 = "";
  frSetFontDrawOT(0x48u);
  if (floor >= 1001)
  {
    v16 = "Ｒ";
  }
  else
  {
    if (floor >= 0)
      v7 = floor;
    else
      v7 = -floor;
    if (floor < 0)
      v8 = "Ｂ";
    else
      v8 = v5;
    if (v7 - 10 <= 0x59)
    {
      v9 = Substring_5248048("０１２３４５６７８９", v7 / 0xAu, 1);
      v8 = Concat_5224608(v8, v9);
    }
    v10 = Substring_5248048("０１２３４５６７８９", v7 % 0xA, 1);
    v11 = Concat_5224608(v8, v10);
    v13 = Concat_5224608(v11, "Ｆ");
    v16 = v13;
  }
  SetAreaUI(kernelObject, 1, 0, 0, v16, 0xFFFFFF80);
}

// 0x177b990
void fldElvFloorEnd(void) {
  gFldElvFloorNow = -999;
  gFldElvFloorFrom = -999;
  gFldElvFloorFromR = -999;
  gFldElvFloorTo = -999;
  gFldElvFloorToR = -999;
  gFldElvFloorAnmCnt = -999;
  gFldElvFloorCancel = 0;
  StopSE_ALL();
  else
  {
    fldCamElvEnd();
  }
}

// 0x177ba90
s32 fldElvFloorEndChk(void) {
  s32 gFldElvFloorNow;
  s32 v6;

  else
  {
    if (gFldElvFloorCancel == 1)
      return 2;
  }
  else if (gFldElvFloorAnmCnt == -999)
  {
    return 0;
  }
  if (gFldElvFloorNow != gFldElvFloorTo)
    return 0;
LABEL_16:
  if (gFldElvFloorFrom >= gFldElvFloorNow)
  {
    v6 = -2;
  }
  else
  {
    v6 = 2;
  }
  fldCamElvStart(v6);
  return 1;
}

// 0x177b590
void fldElvFloorStart(s32 from, s32 to) {
  s32 v6;
  fldTest_c *v7;
  s32 gFldElvFloorNow;
  s16 v10;
  s32 v11;
  struct fldTest_StaticFields **p_static_fields;
  s32 gFldElvFloorFrom;
  s32 v17;
  fldTest_c *v18;
  s32 gFldElvFloorTo;
  s16 v21;
  struct fldTest_StaticFields **v22;
  s32 gFldElvFloorAnmCnt;
  s32 v25;

  v6 = fldDoor_ElvTakasaToFloor(from);
  gFldElvFloorNow = v6;
  gFldElvFloorFrom = gFldElvFloorNow;
  gFldElvFloorCancel = 0;
  if (gFldElvFloorNow >= 1001)
  {
    gFldElvFloorNow = gFldElvFloorNow % 1000;
  }
  v10 = *&v7->_2.bitflags1;
  if ((v10 & 0x200) != 0)
  {
    v11 = v10 & 0x200;
  }
  else
  {
    v11 = 0;
  }
  if (gFldElvFloorFrom < 1001)
  {
    gFldElvFloorFromR = -999;
      goto LABEL_24;
  }
  else
  {
    gFldElvFloorFromR = gFldElvFloorFrom;
    (*p_static_fields)->gFldElvFloorFrom %= 1000;
    {
LABEL_24:
    }
  }
  v17 = fldDoor_ElvTakasaToFloor(to);
  gFldElvFloorTo = v17;
  if (gFldElvFloorTo >= 1001)
  {
    gFldElvFloorToR = gFldElvFloorTo;
    gFldElvFloorTo %= 1000;
    v21 = *&v18->_2.bitflags1;
    if (from != to)
      goto LABEL_38;
LABEL_48:
    gFldElvFloorAnmCnt = -999;
    if ((v18->_2.bitflags2 & 2) != 0)
      goto LABEL_42;
    goto LABEL_52;
  }
  gFldElvFloorToR = -999;
  v21 = *&v18->_2.bitflags1;
  if (from == to)
    goto LABEL_48;
LABEL_38:
  gFldElvFloorAnmCnt = 0;
  if ((v18->_2.bitflags2 & 2) != 0)
  {
LABEL_42:
  }
LABEL_52:
  if (gFldElvFloorNow == -999)
    return;
  else
  {
    if (gFldElvFloorAnmCnt == -999)
      return;
  }
  gFldElvFloorAnmCnt = gFldElvFloorAnmCnt + 1;
  if ((*v22)->gFldElvFloorFrom >= (*v22)->gFldElvFloorTo)
  {
    v25 = -1;
  }
  else
  {
    v25 = 1;
  }
  fldCamElvStart(v25);
}

// 0x177bc30
void fldElvFloorTask(void) {
  System_Array_o *v1;
  fldTest_c *v3;
  struct fldTest_StaticFields **p_static_fields;
  s32 gFldElvFloorAnmCnt;
  struct fldTest_StaticFields *v7;
  s32 gFldElvFloorTo;
  u32 v9;
  s32 gFldElvFloorNow;
  s32 v11;
  u32 v12;

  v1 = NewSpecific(s32, 6u);
  InitializeArray_1543888(v1, Field__PrivateImplementationDetails__2D889424CEDF4BBA56FE9209AAAF376B9ED287BC);
  if (gFldElvFloorNow != -999)
  {
    if (gFldElvFloorAnmCnt == -999)
      goto LABEL_84;
    gFldElvFloorAnmCnt = gFldElvFloorAnmCnt + 1;
    v7 = *p_static_fields;
    v9 = gFldElvFloorTo >> 31;
    if ((v3->_2.bitflags2 & 2) == 0)
    {
      v11 = gFldElvFloorTo < gFldElvFloorNow;
LABEL_16:
      v12 = gFldElvFloorNow >> 31;
      goto LABEL_21;
    }
    else
    {
      v11 = gFldElvFloorTo < gFldElvFloorNow;
        goto LABEL_16;
    }
    v12 = gFldElvFloorNow >> 31;
      goto LABEL_21;
    goto LABEL_79;
  }
}

// 0x1781f30
void fldRunAiCng(s32 stat) {
  fldTest_c *v4;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  struct fldTest_FLDRUN_DANTE_t_o *v6;
  s32 v7;
  struct fldTest_FLDRUN_DANTE_t_o *v8;
  s32 v9;
  u32 RandA;
  struct fldTest_StaticFields *static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v17;
  int16x4_t v21;
  int16x4_t v22;
  int16x4_t v23;
  fldTest_c *v24;
  struct fldTest_FLDRUN_DANTE_t_o *v25;
  struct fldTest_FRO_ROUTEIDX_t_array *pFroRouteIdx;
  s64 RouteIdx;
  struct fldTest_FLDRUN_DANTE_t_o *v30;
  f32 v31;
  struct fldTest_FLDRUN_DANTE_t_o *v36;
  struct fldTest_FLDRUN_DANTE_t_o *v40;
  s32 v41;
  struct fldTest_FRO_ROUTEIDX_t_array *v42;
  struct fldTest_FRO_ROUTEIDX_t_array *v45;
  s64 v46;
  struct fldTest_FLDRUN_DANTE_t_o *v49;
  u32 v50;
  struct fldTest_FLDRUN_DANTE_t_o *v52;
  fldTest_c *v55;
  struct fldTest_FLDRUN_DANTE_t_o *v57;
  s32 v58;
  struct fldTest_FRO_ROUTEIDX_t_array *v59;
  struct fldTest_FRO_ROUTEIDX_t_array *v62;
  s64 v63;
  struct fldTest_FLDRUN_DANTE_t_o *v66;
  u32 v67;
  u32 v68;
  struct fldTest_StaticFields *v71;
  struct fldTest_FLDRUN_DANTE_t_o *v73;
  struct fldTest_FLDRUN_PLAYER_t_o *fldRun_Player;
  s32 iz;
  s16 ix;
  struct fldTest_FLDRUN_DANTE_t_o *v79;
  f32 v80;
  struct fldTest_FRO_ROUTEIDX_t_array *v82;
  s64 v83;
  s32 RouteAddr;
  struct fldTest_FRO_ROUTEIDX_t_array *v87;
  s64 v88;
  s64 v92;
  s64 v93;
  s64 v94;
  s64 v95;
  fldTest_FRO_ROUTEDATA_t_o *FroRouteData;
  int16x4_t v100;
  int16x4_t v101;
  int16x4_t v102;
  u32 x;
  u32 z;
  s16 v107;
  s32 v108;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v110;
  s64 v111;
  s64 v112;
  s64 v113;
  s64 v114;
  s64 kakudo;
  UnityEngine_Vector4_o v116;
  UnityEngine_Vector4_o v117;
  UnityEngine_Vector4_o v118;

  v114 = 0;
  kakudo = 0;
  v113 = 0;
  v111 = 0;
  v112 = 0;
  HIDWORD(kakudo) = LODWORD(fldRun_Dante->d_p_len);
  *&kakudo = fldRun_Dante->d_p_dir;
  fldRun_Dante->cnt_ex = 0;
  fldRun_Dante->tikamiti = 0;
  switch (stat)
  {
    case 0:
      fldRun_Dante->status = 0;
      fldRun_Dante->wkmode = 0;
      fldRun_Dante->nextframe = 0;
      fldRun_Dante->speed = 0.0;
      return;
    case 1:
      v6 = fldRun_Dante;
      v7 = 1;
      goto LABEL_19;
    case 2:
      v6 = fldRun_Dante;
      v7 = 2;
LABEL_19:
      v6->status = v7;
      fldRun_Dante->wkmode = 0;
      fldRun_Dante->nextframe = 30;
      fldRun_Dante->speed = 0.0;
      fldRun_Dante->update_flag |= 2u;
      v8 = fldRun_Dante;
      v9 = 3;
      goto LABEL_170;
    case 3:
      fldRun_Dante->status = 3;
      RandA = dds3GetRandA("");
      fldRun_Dante->nextframe = (RandA >> 3)
                                                                      - 40 * (((3435973837u * (RandA >> 3)) >> 32) >> 5)
                                                                      + 40;
      fldRun_Dante->speed = 25.0;
      fldRun_Dante->update_flag |= 2u;
      goto LABEL_175;
    case 4:
      fldRun_Dante->status = 4;
      FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
      FroFtoI(fldGb->playerX, fldGb->playerZ, &fldRun_Player->ix, &fldRun_Player->iz);
      v17 = fldRun_Dante;
      v17->RouteIdx = FroGetRouteIdx(v17->ix, v17->iz, fldRun_Player->ix, fldRun_Player->iz);
      *&fldRun_Dante->goal_ix = fldRun_Player->fields;
      v25 = fldRun_Dante;
      if (v25->RouteIdx != -1)
      {
        v25->now = 0;
        fldRun_Dante->nextframe = 0;
        RouteIdx = fldRun_Dante->RouteIdx;
        fldRun_Dante->goal = pFroRouteIdx->m_Items[RouteIdx]->RouteNum - 1;
        v30 = fldRun_Dante;
        if (v30->wkmode)
        {
          v31 = 6.0;
          if ((*&v24->_2.bitflags1 & 0x200) == 0)
          {
LABEL_121:
            v30->speed = v31;
            v82 = pFroRouteIdx;
            v83 = fldRun_Dante->RouteIdx;
            RouteAddr = v82->m_Items[v83]->RouteAddr;
            v87 = pFroRouteIdx;
            v88 = fldRun_Dante->RouteIdx;
            if (v87->m_Items[v88]->RouteNum >= 2)
            {
              GetFroRouteData(RouteAddr + 1);
              sub_854930(&v113, 0);
              sub_854930(&v113, 1u);
              sub_854930(&v113, 2u);
              sub_854930(&v113, 3u);
              sub_854930(&v111, 0);
              sub_854930(&v111, 1u);
              sub_854930(&v111, 2u);
              sub_854930(&v111, 3u);
              v92 = v113;
              v93 = v114;
              v94 = v111;
              v95 = v112;
              *&v117.x = v92;
              *&v117.z = v93;
              *&v118.x = v94;
              *&v116.x = 0;
              *&v118.z = v95;
              if (fldHitChkEnemy(v117, v118, v116) == -1)
              {
                ++RouteAddr;
                ++fldRun_Dante->now;
              }
            }
            FroRouteData = GetFroRouteData(RouteAddr);
            x = FroRouteData->x;
            z = FroRouteData->z;
            v102.n64_u16[0] = fldRun_MAP_BX;
            v100.n64_u16[0] = fldRun_MAP_OX;
            v101.n64_u16[0] = fldRun_MAP_OZ;
            fldRunGetLenKakudo2(
              (x * vmovl_s16(v102).n128_i32[0]) + vmovl_s16(v100).n128_i32[0],
              (z * -fldRun_MAP_BZ) + vmovl_s16(v101).n128_i32[0],
              &kakudo + 1,
              &kakudo);
            goto LABEL_157;
          }
        }
        else
        {
          v31 = 20.0;
          if ((*&v24->_2.bitflags1 & 0x200) == 0)
            goto LABEL_121;
        }
        goto LABEL_121;
      }
      v25->now = 0;
      fldRun_Dante->goal = 0;
      fldRun_Dante->dir = 0.0;
      fldRun_Dante->nextframe = 20;
      fldRun_Dante->speed = 0.0;
      v73 = fldRun_Dante;
      if (v73->ix == fldRun_Player->ix)
      {
        iz = v73->iz;
        if (iz == fldRun_Player->iz)
        {
          ix = v73->ix;
          v23.n64_u16[0] = fldRun_MAP_BX;
          v21.n64_u16[0] = fldRun_MAP_OX;
          v22.n64_u16[0] = fldRun_MAP_OZ;
          fldRunGetLenKakudo2(
            (ix * vmovl_s16(v23).n128_i32[0]) + vmovl_s16(v21).n128_i32[0],
            (iz * -fldRun_MAP_BZ) + vmovl_s16(v22).n128_i32[0],
            &kakudo + 1,
            &kakudo);
          v79 = fldRun_Dante;
          if (v79->wkmode)
          {
            v80 = 6.0;
            {
LABEL_179:
              v79->speed = v80;
                goto LABEL_158;
LABEL_157:
LABEL_158:
              fldRun_Dante->nextframe = (*(&kakudo + 1)
                                                                  / fldRun_Dante->speed);
              LODWORD(fldRun_Dante->dir) = kakudo;
              goto LABEL_159;
            }
          }
          else
          {
            v80 = 20.0;
              goto LABEL_179;
          }
          goto LABEL_179;
        }
      }
LABEL_159:
      v107 = *&v24->_2.bitflags1;
      if ((v107 & 0x200) != 0)
      {
        v108 = v107 & 0x200;
      }
      else
      {
        v108 = 0;
      }
      v110 = fldRun_Dante;
      if (v110->wkmode)
      {
        v110->update_flag |= 2u;
        v71 = *p_static_fields;
        goto LABEL_169;
      }
      v110->update_flag |= 2u;
      static_fields = *p_static_fields;
      goto LABEL_175;
    case 5:
      fldRun_Dante->status = 5;
      fldRun_Dante->wkmode = 1;
      FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
      FroFtoI(fldGb->playerX, fldGb->playerZ, &fldRun_Player->ix, &fldRun_Player->iz);
      v36 = fldRun_Dante;
      v36->RouteIdx = FroGetRouteIdx(v36->ix, v36->iz, fldRun_Player->ix, fldRun_Player->iz);
      *&fldRun_Dante->goal_ix = fldRun_Player->fields;
      v40 = fldRun_Dante;
      v41 = fldRun_Dante->RouteIdx;
      if (v41 == -1)
      {
        v40->RouteDataTop = -1;
        fldRun_Dante->now = 0;
        fldRun_Dante->goal = 0;
        fldRun_Dante->dir = 0.0;
        fldRun_Dante->nextframe = 20;
        fldRun_Dante->speed = 0.0;
        if ((v4->_2.bitflags2 & 2) != 0)
          goto LABEL_57;
      }
      else
      {
        v42 = pFroRouteIdx;
        v40->RouteDataTop = v42->m_Items[v41]->RouteAddr;
        fldRun_Dante->now = 0;
        v45 = pFroRouteIdx;
        v46 = fldRun_Dante->RouteIdx;
        fldRun_Dante->goal = v45->m_Items[v46]->RouteNum - 1;
        fldRun_Dante->nextframe = 120;
        fldRun_Dante->speed = 5.0;
        v49 = fldRun_Dante;
        LOWORD(v50) = GetFroRouteData(fldRun_Dante->RouteDataTop)->d;
        v49->dir = v50;
        {
LABEL_57:
        }
      }
LABEL_88:
      fldRun_Dante->update_flag |= 2u;
LABEL_169:
      v8 = fldRun_Dante;
      v9 = 2;
LABEL_170:
      v8->motion = v9;
      return;
    case 6:
      fldRun_Dante->status = 6;
      fldRun_Dante->wkmode = 0;
      FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
      v52 = fldRun_Dante;
      v52->RouteIdx = FroGetRouteIdx(v52->ix, v52->iz, fldRun_Player->ix, fldRun_Player->iz);
      *&fldRun_Dante->goal_ix = fldRun_Player->fields;
      v57 = fldRun_Dante;
      v58 = fldRun_Dante->RouteIdx;
      if (v58 == -1)
      {
        v57->RouteDataTop = -1;
        fldRun_Dante->now = 0;
        fldRun_Dante->goal = 0;
        fldRun_Dante->dir = 0.0;
        fldRun_Dante->nextframe = 20;
        fldRun_Dante->speed = 0.0;
        if ((v55->_2.bitflags2 & 2) != 0)
          goto LABEL_71;
      }
      else
      {
        v59 = pFroRouteIdx;
        v57->RouteDataTop = v59->m_Items[v58]->RouteAddr;
        fldRun_Dante->now = 0;
        v62 = pFroRouteIdx;
        v63 = fldRun_Dante->RouteIdx;
        fldRun_Dante->goal = v62->m_Items[v63]->RouteNum - 1;
        fldRun_Dante->nextframe = 30;
        fldRun_Dante->speed = 20.0;
        v66 = fldRun_Dante;
        LOWORD(v67) = GetFroRouteData(fldRun_Dante->RouteDataTop)->d;
        v66->dir = v67;
        {
LABEL_71:
        }
      }
      fldRun_Dante->update_flag |= 2u;
LABEL_175:
      fldRun_Dante->motion = 0;
      return;
    case 7:
      fldRun_Dante->status = 7;
      fldRun_Dante->wkmode = 0;
      v68 = dds3GetRandA("");
      fldRun_Dante->nextframe = (v68 >> 3)
                                                                      - 60 * (((2290649225u * (v68 >> 3)) >> 32) >> 5)
                                                                      + 50;
      fldRun_Dante->speed = 8.0;
      fldRun_Dante->update_flag |= 2u;
      v9 = 1;
      v8 = fldRun_Dante;
      goto LABEL_170;
    case 8:
      fldRun_Dante->status = 8;
      fldRun_Dante->wkmode = 0;
      fldRun_Dante->nextframe = 90;
      fldRun_Dante->speed = 0.0;
      fldRun_Dante->update_flag |= 2u;
      v8 = fldRun_Dante;
      v9 = 4;
      goto LABEL_170;
    case 9:
      fldRun_Dante->status = 9;
      fldRun_Dante->nextframe = 80;
      fldRun_Dante->speed = 10.0;
      goto LABEL_88;
    default:
      return;
  }
}

// 0x178c1a0
void fldRunCngBgm(s32 mode) {
  s64 *v3;

  if (mode)
  {
    p2sdFadeIn2_20177360("B1100_B1101_BGM01");
    v3 = &"F043_01";
  }
  else
  {
    p2sdFadeIn2_20177360("F043_01");
    v3 = &"B1100_B1101_BGM01";
  }
  p2sdFadeOut_20177680(*v3);
}

// 0x178bea0
void fldRunDanteAi(void) {
  u64 v2;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 nextframe;

  switch (*(**(v2 + 184) + 16LL))
  {
    case 0:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      break;
    case 1:
      nextframe = fldRun_Dante->nextframe;
      if (nextframe >= 1)
      {
        fldRun_Dante->nextframe = nextframe - 1;
      }
      break;
    case 2:
      fldRunDanteWait(v2);
      break;
    case 3:
      fldRunDanteSoba(v2);
      break;
    case 4:
      fldRunDantePatr(v2);
      break;
    case 5:
      fldRunDantePwak(v2);
      break;
    case 7:
      fldRunDanteGun1(v2);
      break;
    case 8:
      fldRunDanteGun2(v2);
      break;
    case 9:
      fldRunDanteDoin(v2);
      break;
    default:
      fldRunDanteMove(v2);
      break;
  }
}

// 0x178acc0
void fldRunDanteCollision(void) {
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v13;
  f32 v14;
  f32 v16;
  f32 v17;
  f32 v19;
  f32 r;
  f32 v22;
  fldTest_c *v23;
  f32 v24;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 status;
  s16 v27;
  s32 v28;
  struct fldTest_FLDRUN_DANTE_t_o *v29;
  s32 v30;
  s32 v31;
  s64 v34;
  s64 v35;
  s64 v36;
  s64 v37;
  s32 v38;
  int16x4_t v39;
  int16x4_t v40;
  int16x4_t v41;
  s16 v42;
  s32 v43;
  struct fldTest_FLDRUN_DANTE_t_o *v44;
  s32 stance;
  u32 RandA;
  u32 v47;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_PLAYER_t_o *fldRun_Player;
  s32 ix;
  struct fldTest_FLDRUN_DANTE_t_o *v54;
  struct fldTest_FLDRUN_DANTE_t_o *v55;
  struct fldTest_FLDRUN_DANTE_t_o *v56;
  s16 v57;
  s32 v58;
  struct fldTest_FLDRUN_DANTE_t_o *v59;
  struct fldTest_FLDRUN_DANTE_t_o *v60;
  struct fldTest_FLDRUN_DANTE_t_o *v61;
  u32 v62;
  u32 v63;
  s16 v64;
  s32 v65;
  struct fldTest_FLDRUN_DANTE_t_o *v67;
  struct fldTest_FLDRUN_PLAYER_t_o *v68;
  struct fldTest_FLDRUN_PLAYER_t_o *v70;
  s32 v72;
  struct fldTest_FLDRUN_DANTE_t_o *v73;
  s32 v74;
  s16 v75;
  s32 v76;
  struct fldTest_FLDRUN_DANTE_t_o *v77;
  s32 v78;
  u32 v79;
  u32 v80;
  s16 v81;
  s32 v82;
  s16 v83;
  u32 v84;
  s32 v85;
  s32 v86;
  struct fldTest_FLDRUN_DANTE_t_o *v87;
  struct fldTest_FLDRUN_DANTE_t_o *v88;
  s16 v89;
  s16 iz;
  struct fldTest_StaticFields **v94;
  struct fldTest_FLDRUN_DANTE_t_o *v96;
  s32 FLDRUN_BGM_NML;
  s64 v99;
  s64 v100;
  s64 v101;
  s64 v102;
  UnityEngine_Vector4_o v103;
  UnityEngine_Vector4_o v104;
  UnityEngine_Vector4_o v105;

  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  fldRun_Dante->update_flag = 0;
  fldRunGetLenKakudo(&fldRun_Dante->d_p_len, &fldRun_Dante->d_p_dir);
  sub_854710(&dds3CameraTargetPos, 0);
  v7 = v6;
  sub_854710(&dds3CameraEyePos, 0);
  v9 = v7 - v8;
  sub_854710(&dds3CameraTargetPos, 2u);
  v11 = v10;
  sub_854710(&dds3CameraEyePos, 2u);
  v14 = v11 - v13;
  if (sdfSqrt((v9 * v9) + (v14 * v14), 0) >= 1.0)
  {
    v17 = sdfAtan2(v9, v14);
    v16 = (v17 * 180.0) / 3.14;
  }
  else
  {
    v16 = 0.0;
  }
  v19 = 180.0 - v16;
  r = fldRun_Dante->r;
  v22 = R360_LR(v19, r);
  if (v22 >= 0.0)
    v24 = v22;
  else
    v24 = -v22;
  fldRun_Dante->d_c_dir = v24;
  status = fldRun_Dante->status;
  if (!status)
    return;
  else if (status != 1)
  {
    goto LABEL_43;
  }
  if (fldRun_Dante->nextframe > 0)
    return;
LABEL_43:
  v27 = *&v23->_2.bitflags1;
  if ((v27 & 0x200) != 0)
  {
    v28 = v27 & 0x200;
  }
  else
  {
    v28 = 0;
  }
  v29 = fldRun_Dante;
  v30 = v29->status;
  if (v30 != 2)
  {
    else if (v30 == 9)
    {
LABEL_60:
      if (v29->nextframe > 0)
        return;
      if ((v23->_2.bitflags2 & 2) == 0)
        goto LABEL_67;
      goto LABEL_65;
    }
    sub_854930(&v101, 0);
    sub_854930(&v101, 1u);
    sub_854930(&v101, 2u);
    sub_854930(&v101, 3u);
    sub_854930(&v99, 0);
    sub_854930(&v99, 1u);
    sub_854930(&v99, 2u);
    sub_854930(&v99, 3u);
    v34 = v101;
    v35 = v102;
    v36 = v99;
    v37 = v100;
    *&v104.x = v34;
    *&v104.z = v35;
    *&v105.x = v36;
    *&v103.x = 0;
    *&v105.z = v37;
    v38 = fldHitChkEnemy(v104, v105, v103);
    if (v38 == -1)
    {
      if ((v42 & 0x200) == 0)
      {
LABEL_85:
        v43 = 0;
        goto LABEL_90;
      }
    }
    else
    {
      fldRun_Dante->update_flag |= 1u;
      v42 = *&v23->_2.bitflags1;
      if ((v42 & 0x200) == 0)
        goto LABEL_85;
    }
    v43 = v42 & 0x200;
LABEL_90:
    v44 = fldRun_Dante;
    stance = v44->stance;
    if (stance == 4)
    {
      if (v44->nextframe > 0)
        return;
      if ((v44->update_flag & 1) != 0)
        goto LABEL_361;
      RandA = dds3GetRandA("");
      v47 = (RandA >> 3) - 100 * (((1374389535 * (RandA >> 3)) >> 32) >> 5);
      if (v47 > 0x1D)
      {
LABEL_361:
        if (fldRun_Dante->status != 1)
        {
          v31 = 1;
          goto LABEL_68;
        }
        return;
      }
        goto LABEL_267;
      goto LABEL_266;
    }
    if (stance == 9)
    {
      if (v44->nextframe <= 0)
      {
        if (v44->status == 1)
        {
          if ((v44->update_flag & 1) != 0)
            return;
          if (v44->d_p_len >= 900.0)
            return;
          goto LABEL_298;
        }
      }
      if (fldGb->areaID == 7)
      {
        ix = fldRun_Player->ix;
        if (ix >= 5)
        {
          if (ix <= 7)
          {
            if (fldRun_Player->iz <= 3)
            {
              v54 = fldRun_Dante;
              if (v54->iz >= 6)
              {
                v54->ix = 6;
                (*p_static_fields)->fldRun_Dante->iz = 8;
                (*p_static_fields)->fldRun_Dante->dir = 180.0;
                v87 = (*p_static_fields)->fldRun_Dante;
                v39.n64_f32[0] = 180.0 - v87->dir;
                LODWORD(v87->r) = v39.n64_u32[0];
                v88 = (*p_static_fields)->fldRun_Dante;
                v89 = v88->ix;
                iz = v88->iz;
                v41.n64_u16[0] = fldRun_MAP_BX;
                v39.n64_u16[0] = fldRun_MAP_OX;
                v40.n64_u16[0] = fldRun_MAP_OZ;
                v88->x = (v89 * vmovl_s16(v41).n128_i32[0]) + vmovl_s16(v39).n128_i32[0];
                v88->z = (iz * -fldRun_MAP_BZ) + vmovl_s16(v40).n128_i32[0];
                fldRunAiCng(1);
                fldRunDanteSetModel();
                v96 = fldRun_Dante;
                if (v96->bgm_mode != FLDRUN_BGM_NML)
                {
                  v96->bgm_mode = FLDRUN_BGM_NML;
                  (*v94)->fldRun_Dante->update_flag |= 4u;
                }
                return;
              }
            }
          }
        }
      }
    }
    if (v38 != -1)
    {
      v55 = fldRun_Dante;
      if (v55->status == 7)
      {
        if (v55->cnt_ex < 15)
          return;
      }
      v56 = fldRun_Dante;
      if (v56->status == 8)
      {
        if (v56->cnt_ex < 30)
          return;
      }
      v57 = *&v23->_2.bitflags1;
      if ((v57 & 0x200) != 0)
      {
        v58 = v57 & 0x200;
      }
      else
      {
        v58 = 0;
      }
      v67 = fldRun_Dante;
      if (fldRun_Dante->status == 4)
      {
        if (v67->nextframe > 0)
        {
          v68 = fldRun_Player;
          if (v67->goal_ix == v68->ix)
          {
            if (v67->goal_iz == v68->iz)
              return;
          }
          goto LABEL_262;
        }
        if (!v58)
        {
LABEL_67:
          v31 = 6;
LABEL_68:
          fldRunAiCng(v31);
          return;
        }
LABEL_65:
        goto LABEL_67;
      }
      v70 = fldRun_Player;
      if (v67->goal_ix == v70->ix)
      {
        if (v67->goal_iz == v70->iz)
        {
          v72 = v67->status;
          if (v72 == 6)
            return;
          if (v72 == 5)
            return;
LABEL_262:
          if ((v23->_2.bitflags2 & 2) != 0)
          {
LABEL_318:
          }
LABEL_320:
          v31 = 4;
          goto LABEL_68;
        }
      }
      v73 = fldRun_Dante;
      v74 = v73->status;
      if (v74 != 5)
      {
        if (v74 != 6)
          goto LABEL_262;
        v75 = *&v23->_2.bitflags1;
        if ((v75 & 0x200) != 0)
        {
          v76 = v75 & 0x200;
          if (!v73->tikamiti)
          {
LABEL_312:
            if (!v76)
              goto LABEL_67;
            goto LABEL_65;
          }
        }
        else
        {
          v76 = 0;
          if (!v73->tikamiti)
            goto LABEL_312;
        }
LABEL_317:
        if (v76)
          goto LABEL_318;
        goto LABEL_320;
      }
      v83 = *&v23->_2.bitflags1;
      if ((v83 & 0x200) != 0)
      {
        v76 = v83 & 0x200;
        if (v73->tikamiti)
          goto LABEL_317;
      }
      else
      {
        v76 = 0;
        if (v73->tikamiti)
          goto LABEL_317;
      }
      v31 = 5;
      goto LABEL_68;
    }
    v59 = fldRun_Dante;
    if (v59->status == 6)
    {
      if (v59->nextframe >= 1)
      {
        if (v59->cnt_ex >= 6)
        {
          v59->nextframe = 0;
        }
      }
    }
    v60 = fldRun_Dante;
    if (v60->status == 5)
    {
      v60->nextframe = 0;
    }
    v61 = fldRun_Dante;
    if (v61->status == 4)
    {
      if (v61->cnt_ex > 2)
        goto LABEL_362;
      if (v61->nextframe <= 2)
      {
LABEL_362:
        fldRun_Dante->nextframe = 0;
      }
    }
    if (fldRun_Dante->nextframe > 0)
      return;
    v62 = dds3GetRandA("") >> 3;
    v63 = v62 % 0x64;
    if ((v64 & 0x200) != 0)
    {
      v65 = v64 & 0x200;
    }
    else
    {
      v65 = 0;
    }
    v77 = fldRun_Dante;
    v78 = v77->stance;
    if (v78 == 7)
      v63 += 50;
    if (v78 == 9)
      v79 = v63 + 50;
    else
      v79 = v63;
    if (v79 <= 0x4F)
    {
      if (v77->status == 3)
        return;
LABEL_298:
      v31 = 3;
      goto LABEL_68;
    }
    if (v77->d_p_len >= 900.0)
    {
      if ((v23->_2.bitflags2 & 2) == 0)
        goto LABEL_354;
      goto LABEL_352;
    }
    v80 = dds3GetRandA("") >> 3;
    if ((v81 & 0x200) != 0)
    {
      v82 = v81 & 0x200;
    }
    else
    {
      v82 = 0;
    }
    v77 = fldRun_Dante;
    v84 = v80 % 0x64;
    v85 = v77->stance;
    else
    {
      v86 = v77->stance;
      if (v84 > 0x4F)
        goto LABEL_351;
    }
    if (v85 != 7 && v86 != 9)
    {
LABEL_266:
LABEL_267:
      v77 = fldRun_Dante;
      goto LABEL_268;
    }
LABEL_351:
    if (!v82)
      goto LABEL_354;
LABEL_352:
LABEL_354:
    if (v77->status != 7)
    {
      v31 = 7;
      goto LABEL_68;
    }
    return;
  }
  if (v29->nextframe <= 0)
  {
    v31 = 9;
    goto LABEL_68;
  }
}

// 0x1782fd0
void fldRunDanteDirReset(void) {
  f32 kakudo;
  f32 len;

  len = 0.0;
  kakudo = 0.0;
  fldRunGetLenKakudo(&len, &kakudo);
  fldRun_Dante->dir = kakudo;
  fldRun_Dante->r = 180.0 - fldRun_Dante->dir;
}

// 0x1786fe0
void fldRunDanteDoin(void) {
  fldTest_c *v3;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 nextframe;
  struct fldTest_FLDRUN_DANTE_t_o *v6;
  dds3Basic_t_o *ControlScene;
  System_String_o *name;
  dds3Basic_t_o *v11;
  fldTest_c *v13;
  s64 v14;
  u64 v15;
  struct fldTest_FLDRUN_DOOR_t_array *fldRunDoorTbl;
  u64 max_length_low;
  struct fldTest_FLDRUN_DOOR_t_array *v20;
  struct fldTest_FLDRUN_DOOR_t_array *v23;
  f32 v25;
  struct fldTest_FLDRUN_DOOR_t_o *pDoor;
  struct fldTest_FLDRUN_DOOR_t_array *v28;
  s64 v30;
  dds3Basic_t_o *v31;
  struct fldTest_FLDRUN_DOOR_t_array *v33;
  dds3Basic_t_o *v34;
  System_String_o *v36;
  dds3Basic_t_o *v38;
  struct fldTest_FLDRUN_DOOR_t_array *v40;
  System_String_o *v42;
  s32 serialID;
  s16 v44;
  s32 v45;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v47;
  s32 v48;
  f32 v49;
  f32 x;
  f32 v51;
  struct fldTest_FLDRUN_DANTE_t_o *v54;
  f32 z;
  f32 v56;

  nextframe = fldRun_Dante->nextframe;
  if (nextframe >= 1)
  {
    fldRun_Dante->nextframe = nextframe - 1;
  }
  v6 = fldRun_Dante;
  if (v6->nextframe == 78)
  {
    if (v6->pDoor)
    {
      ControlScene = dds3GetControlScene();
      name = fldRun_Dante->pDoor->name;
      v11 = dds3SceneBasicSearchNameAndType(ControlScene, 0x11u, name);
      if (!v11)
      {
        v14 = 4;
        v15 = 0;
          goto LABEL_34;
LABEL_32:
        while (1)
        {
LABEL_34:
          max_length_low = LODWORD(fldRunDoorTbl->max_length);
          if (v15 >= max_length_low)
            goto LABEL_71;
          else if (v15 >= max_length_low)
          {
            goto LABEL_38;
          }
          if (*(*(&fldRunDoorTbl->obj.klass + v14) + 24LL) == fldRun_Dante->pDoor->ix)
          {
            else
            {
              v20 = fldRunDoorTbl;
              if (v15 >= LODWORD(v20->max_length))
                goto LABEL_43;
            }
            if (*(*(&v20->obj.klass + v14) + 26LL) == fldRun_Dante->pDoor->iz)
            {
              else
              {
                v23 = fldRunDoorTbl;
                if (v15 >= LODWORD(v23->max_length))
                  goto LABEL_48;
              }
              v25 = *(*(&v23->obj.klass + v14) + 28LL);
              pDoor = fldRun_Dante->pDoor;
              if (v25 == pDoor->dir)
                break;
            }
          }
          v15 = ++v14 - 4;
          if ((v13->_2.bitflags2 & 2) != 0)
            goto LABEL_32;
        }
        v28 = fldRunDoorTbl;
        v30 = *(&v28->obj.klass + v14);
        pDoor->name = *(v30 + 16);
        pDoor->ix = *(v30 + 24);
        pDoor->iz = *(v30 + 26);
        pDoor->dir = *(v30 + 28);
        v31 = dds3GetControlScene();
        v33 = fldRunDoorTbl;
        v34 = v31;
        v36 = *(*(&v33->obj.klass + v14) + 16LL);
        v11 = dds3SceneBasicSearchNameAndType(v34, 0x11u, v36);
        if (!v11)
        {
LABEL_71:
          v38 = dds3GetControlScene();
          v40 = fldRunDoorTbl;
          v42 = v40->m_Items[0]->name;
          v11 = dds3SceneBasicSearchNameAndType(v38, 0x11u, v42);
        }
      }
      serialID = v11->serialID;
      fldDoor_Start(serialID);
    }
  }
  v44 = *&v3->_2.bitflags1;
  if ((v44 & 0x200) != 0)
  {
    v45 = v44 & 0x200;
  }
  else
  {
    v45 = 0;
  }
  v47 = fldRun_Dante;
  v48 = v47->nextframe;
  if (v48 >= 21)
  {
    v49 = (v47->dir * 3.14) / 180.0;
    x = v47->x;
    v51 = sdfSin(v49);
    v47->x = x + (v51 * fldRun_Dante->speed);
    v54 = fldRun_Dante;
    z = fldRun_Dante->z;
    v56 = sdfCos((fldRun_Dante->dir * 3.14) / 180.0, 0);
    v54->z = z + (v56 * fldRun_Dante->speed);
LABEL_109:
    if ((v3->_2.bitflags2 & 2) == 0)
      goto LABEL_112;
    goto LABEL_110;
  }
  if (v48 != 20)
    goto LABEL_109;
  v47->update_flag |= 2u;
  (*p_static_fields)->fldRun_Dante->motion = 3;
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_110:
  }
LABEL_112:
  FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
}

// 0x178ca20
void fldRunDanteFree(void) {
LABEL_7:
  v2[2].klass->vtable[0].methodPtr = 0;
  *&v2[2].klass->_2.typeHierarchyDepth = 0;
  *&v2[2].klass->_2.nested_type_count = 0;
  *&v2[2].klass->_2.method_count = 0;
  *&v2[2].klass->_2.flags = 0;
  fldRunTamaFree();
  if (fldGb->AreaToArea)
  {
    fldRun_Dante->old_status = fldRun_Dante->status;
  }
  else
  {
    fldRun_Dante->old_status = -1;
  }
}

// 0x1789a40
void fldRunDanteGun1(void) {
  u64 *v1;
  System_Array_o *v2;
  System_Array_o *v3;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 cnt_ex;
  struct fldTest_FLDRUN_DANTE_t_o *v8;
  s32 nextframe;
  struct fldTest_FLDRUN_DANTE_t_o *v10;
  f32 d_p_len;
  struct fldTest_FLDRUN_DANTE_t_o *v12;
  f32 r;
  f32 dir;
  f32 v15;
  f32 v18;
  f32 v19;
  f32 v20;
  struct fldTest_FLDRUN_DANTE_t_o *v22;
  f32 v23;
  f32 x;
  f32 v25;
  struct fldTest_FLDRUN_DANTE_t_o *v28;
  f32 z;
  f32 v30;
  struct fldTest_FLDRUN_DANTE_t_o *v31;
  f32 oldframe;
  f32 nowframe;
  u64 i;
  f32 v36;
  u32 RandA;
  u32 v41;
  bool v42;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v51;
  f32 v52;
  s32 v53;
  sdfModelRootNode_t_o *modelRoot;
  f32 v59;
  f32 v60;
  f32 v61;
  f32 v62;
  f32 v65;
  f32 v66;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v71;
  s32 FLDRUN_BGM_BTL;
  UnityEngine_Vector4_o p;

  v1 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v1);
  *&p.x = 0;
  *&p.z = 0;
  v2 = NewSpecific(f32, 4u);
  InitializeArray_1543888(v2, Field__PrivateImplementationDetails__0B97B08A3922C9CB92C1F02840F30F466631C221);
  v3 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__571C82CF218E740460EACAFCA963ACF36E254AD4);
  cnt_ex = fldRun_Dante->cnt_ex;
  if (cnt_ex <= 299)
  {
    fldRun_Dante->cnt_ex = cnt_ex + 1;
  }
  v8 = fldRun_Dante;
  nextframe = v8->nextframe;
  if (nextframe >= 1)
  {
    v8->nextframe = nextframe - 1;
  }
  v10 = fldRun_Dante;
  v10->dir = v10->d_p_dir;
  d_p_len = v10->d_p_len;
  v12 = fldRun_Dante;
  r = v12->r;
  dir = v12->dir;
  v15 = 180.0 - dir;
  v18 = R360_LR(r, v15);
  v19 = v18 / 10.0;
  if ((v18 / 10.0) < 0.0)
    v19 = -(v18 / 10.0);
  v20 = fmaxf(v19, 1.0);
  if ((v18 < 0.0 || v18 > v20) && (v18 > 0.0 || v18 < -v20))
  {
    if (v18 >= 0.0)
      v15 = r + v20;
    else
      v15 = r - v20;
  }
  v12->r = v15;
  if (d_p_len > 100.0)
  {
    v22 = fldRun_Dante;
    v23 = (v22->dir * 3.14) / 180.0;
    x = v22->x;
    v25 = sdfSin(v23);
    v22->x = x + (v25 * fldRun_Dante->speed);
    v28 = fldRun_Dante;
    z = fldRun_Dante->z;
    v30 = sdfCos((fldRun_Dante->dir * 3.14) / 180.0, 0);
    v28->z = z + (v30 * fldRun_Dante->speed);
  }
  else
  {
    v31 = fldRun_Dante;
    if ((v31->update_flag & 2) == 0)
      goto LABEL_47;
  }
  oldframe = 0.0;
  nowframe = 0.0;
LABEL_53:
  for (i = 0; i != 3; ++i)
  {
    v36 = *(&v2[2].klass + i);
    if (v36 > oldframe)
    {
      if (v36 <= nowframe)
      {
        fldRun_Dante->update_flag |= 8u;
        fldRun_Dante->gunlight_anime = 8;
        RandA = dds3GetRandA("");
        if ((fldRun_Dante->update_flag & 1) == 0)
        {
          v41 = (RandA >> 3) - 100 * (((1374389535 * (RandA >> 3)) >> 32) >> 5);
          v42 = v41 > 1 || d_p_len <= 2400.0;
          if (!v42
            || d_p_len > 1800.0 && v41 <= 4
            || d_p_len > 1200.0 && v41 <= 0x13
            || v41 < 0x32
            || v41 < 0x1E && d_p_len > 600.0)
          {
            fldGb->GunDmgOn = 1;
            gfldPlayerDamegeCnt = 8;
            datPartyDamageFld(3);
            dds3GetRandA("");
            sub_854930(&p, 0);
            dds3GetRandA("");
            sub_854930(&p, 1u);
            dds3GetRandA("");
            sub_854930(&p, 2u);
            sub_854710(&p, 0);
            v47 = v46;
            sub_854710(&p, 1u);
            v49 = v48;
            sub_854710(&p, 2u);
            v52 = v51;
            fldRunEffSet(0, v47, v49, v52, 0.0);
          }
        }
        v53 = *(&v3[2].klass + i);
        if (v53 == 20)
        {
          fldRun_Dante->update_flag |= 0x10u;
            goto LABEL_102;
        }
        else
        {
          {
LABEL_102:
            {
            }
            modelRoot = dds3GetUnitHandleObjectBasic(&player3)->Model->modelRoot;
            if (sdfModelGetMarkPosUnity(modelRoot, v53))
            {
              SDF_VU0__STOREVECTOR(&p);
              sub_854710(&p, 0);
              v60 = v59;
              sub_854710(&p, 1u);
              v62 = v61;
              sub_854710(&p, 2u);
              v66 = v65;
              fldRunEffSet(1, v60, v62, v66, fldRun_Dante->r);
            }
            continue;
          }
        }
        goto LABEL_102;
      }
    }
  }
  FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
  v71 = fldRun_Dante;
  if (v71->bgm_mode != FLDRUN_BGM_BTL)
  {
    v71->bgm_mode = FLDRUN_BGM_BTL;
    (*p_static_fields)->fldRun_Dante->update_flag |= 4u;
  }
}

// 0x178a3f0
void fldRunDanteGun2(void) {
  u64 *v1;
  System_Array_o *v2;
  System_Array_o *v3;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 cnt_ex;
  struct fldTest_FLDRUN_DANTE_t_o *v8;
  s32 nextframe;
  struct fldTest_FLDRUN_DANTE_t_o *v10;
  f32 d_p_len;
  struct fldTest_FLDRUN_DANTE_t_o *v12;
  f32 r;
  f32 dir;
  f32 v15;
  f32 v18;
  f32 v19;
  f32 v20;
  struct fldTest_FLDRUN_DANTE_t_o *v21;
  f32 oldframe;
  f32 nowframe;
  u64 i;
  f32 v26;
  signed s32 RandA;
  s32 v31;
  bool v32;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v41;
  f32 v42;
  s32 v43;
  sdfModelRootNode_t_o *modelRoot;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v55;
  f32 v56;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v61;
  s32 FLDRUN_BGM_BTL;
  UnityEngine_Vector4_o p;

  v1 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v1);
  *&p.x = 0;
  *&p.z = 0;
  v2 = NewSpecific(f32, 6u);
  InitializeArray_1543888(v2, Field__PrivateImplementationDetails__121399DC17CC544E284952F820620E3D450304E3);
  v3 = NewSpecific(s32, 6u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__ED3FC9027FA90BA65AF41A743AC6DD8107E17863);
  cnt_ex = fldRun_Dante->cnt_ex;
  if (cnt_ex <= 299)
  {
    fldRun_Dante->cnt_ex = cnt_ex + 1;
  }
  v8 = fldRun_Dante;
  nextframe = v8->nextframe;
  if (nextframe >= 1)
  {
    v8->nextframe = nextframe - 1;
  }
  v10 = fldRun_Dante;
  v10->dir = v10->d_p_dir;
  d_p_len = v10->d_p_len;
  v12 = fldRun_Dante;
  r = v12->r;
  dir = v12->dir;
  v15 = 180.0 - dir;
  v18 = R360_LR(r, v15);
  v19 = v18 / 10.0;
  if ((v18 / 10.0) < 0.0)
    v19 = -(v18 / 10.0);
  v20 = fmaxf(v19, 1.0);
  if ((v18 < 0.0 || v18 > v20) && (v18 > 0.0 || v18 < -v20))
  {
    if (v18 >= 0.0)
      v15 = r + v20;
    else
      v15 = r - v20;
  }
  v12->r = v15;
  v21 = fldRun_Dante;
  if ((v21->update_flag & 2) != 0)
  {
    oldframe = 0.0;
    nowframe = 0.0;
  }
  else
  {
    oldframe = v21->oldframe;
    nowframe = v21->nowframe;
  }
  for (i = 0; i != 6; ++i)
  {
    v26 = *(&v2[2].klass + i);
    if (v26 > oldframe)
    {
      if (v26 <= nowframe)
      {
        fldRun_Dante->update_flag |= 8u;
        fldRun_Dante->gunlight_anime = 8;
        RandA = dds3GetRandA("");
        if ((fldRun_Dante->update_flag & 1) == 0)
        {
          v31 = (RandA >> 3) % 100;
          v32 = v31 > 1 || d_p_len <= 2400.0;
          if (!v32
            || d_p_len > 1800.0 && v31 <= 4
            || d_p_len > 1200.0 && v31 <= 19
            || v31 < 50
            || v31 < 30 && d_p_len > 600.0)
          {
            fldGb->GunDmgOn = 1;
            gfldPlayerDamegeCnt = 8;
            datPartyDamageFld(3);
            dds3GetRandA("");
            sub_854930(&p, 0);
            dds3GetRandA("");
            sub_854930(&p, 1u);
            dds3GetRandA("");
            sub_854930(&p, 2u);
            sub_854710(&p, 0);
            v37 = v36;
            sub_854710(&p, 1u);
            v39 = v38;
            sub_854710(&p, 2u);
            v42 = v41;
            fldRunEffSet(0, v37, v39, v42, 0.0);
          }
        }
        v43 = *(&v3[2].klass + i);
        if (v43 == 20)
        {
          fldRun_Dante->update_flag |= 0x10u;
            goto LABEL_91;
        }
        else
        {
          {
LABEL_91:
            {
            }
            modelRoot = dds3GetUnitHandleObjectBasic(&player3)->Model->modelRoot;
            if (sdfModelGetMarkPosUnity(modelRoot, v43))
            {
              SDF_VU0__STOREVECTOR(&p);
              sub_854710(&p, 0);
              v50 = v49;
              sub_854710(&p, 1u);
              v52 = v51;
              sub_854710(&p, 2u);
              v56 = v55;
              fldRunEffSet(1, v50, v52, v56, fldRun_Dante->r);
            }
            continue;
          }
        }
        goto LABEL_91;
      }
    }
  }
  FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
  v61 = fldRun_Dante;
  if (v61->bgm_mode != FLDRUN_BGM_BTL)
  {
    v61->bgm_mode = FLDRUN_BGM_BTL;
    (*p_static_fields)->fldRun_Dante->update_flag |= 4u;
  }
}

// 0x177fa20
void fldRunDanteGunLight(f32 x, f32 y, f32 z, f32 r, s32 a) {
  ;
}

// 0x178c3f0
void fldRunDanteInit(void) {
  int16x4_t v7;
  int16x4_t v8;
  int16x4_t v9;
  int16x4_t v10;
  fldTest_c *v13;
  s16 v15;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  int16x4_t v19;
  s16 *v20;
  u64 *v21;
  u64 v25;
  s32 v27;
  s32 v28;

  BYTE1(v2[2].klass->_1.parent) = 0;
  BYTE2(v2[2].klass->_1.parent) = 0;
  FroLoad();
  fldRunSoundLoad();
  fldRunTamaInit();
  fldRun_MAP_BX = 600;
  fldRun_MAP_BZ = 600;
  switch (fldGb->areaID)
  {
    case 3:
      fldRun_MAP_OX = 3950;
      fldRun_MAP_OZ = 3100;
      fldRun_Dante->ix = 3;
      fldRun_Dante->iz = 10;
      if ((v13->_2.bitflags2 & 2) != 0)
        goto LABEL_43;
      goto LABEL_45;
    case 4:
      fldRun_MAP_OX = 200;
      fldRun_MAP_OZ = 100;
      fldRun_Dante->ix = 7;
      fldRun_Dante->iz = 0;
      fldRun_Player->ix = 3;
      fldRun_Player->iz = 2;
      if ((v13->_2.bitflags2 & 2) != 0)
        goto LABEL_43;
      goto LABEL_45;
    case 5:
      fldRun_MAP_OX = 3300;
      v15 = -2100;
      goto LABEL_42;
    case 7:
      fldRun_MAP_OX = -5250;
      v15 = 4050;
      goto LABEL_42;
    case 8:
      fldRun_MAP_OX = -3500;
      v15 = -2900;
      goto LABEL_42;
    case 9:
      fldRun_MAP_OX = 300;
      v15 = 2100;
      goto LABEL_42;
    case 0xA:
      v15 = -2700;
      fldRun_MAP_OX = -2700;
LABEL_42:
      fldRun_MAP_OZ = v15;
      fldRun_Dante->ix = 0;
      fldRun_Dante->iz = 0;
      if ((v13->_2.bitflags2 & 2) != 0)
        goto LABEL_43;
      goto LABEL_45;
    default:
        goto LABEL_45;
LABEL_43:
LABEL_45:
      v7.n64_u16[0] = fldRun_MAP_OX;
      v8.n64_u16[0] = fldRun_MAP_OZ;
      fldRun_Dante->now = 0;
      fldRun_Dante->goal = 0;
      fldRun_Dante->nextframe = -20;
      v9.n64_u16[0] = fldRun_MAP_BX;
      v10.n64_u16[0] = fldRun_Dante->ix;
      v19.n64_u64[0] = vmovl_s16(v9).n128_u64[0];
      v19.n64_f32[0] = v19.n64_i32[0] * vmovl_s16(v10).n128_i32[0];
      fldRun_Dante->x = v19.n64_f32[0] + vmovl_s16(v7).n128_i32[0];
      fldRun_Dante->y = 0.0;
      v19.n64_u16[0] = *(*v20 + 46LL);
      *(*v20 + 28LL) = (-v20[123] * vmovl_s16(v19).n128_i32[0]) + vmovl_s16(v8).n128_i32[0];
      fldRun_Dante->dir = 0.0;
      fldRun_Dante->speed = 0.0;
      fldRun_Dante->gunlight_anime = 0;
      fldRun_Dante->update_flag = 0;
      fldRun_Dante->bgm_mode = 0;
      fldRun_Dante->stance = 0;
      fldRun_Dante->d_c_dir = 0.0;
      fldRun_Dante->wkmode = 0;
      if (!SuspendData->IsRestored)
      {
        switch (fldGb->areaID)
        {
          case 3:
            v28 = 6;
            goto LABEL_81;
          case 4:
            v28 = 2;
            goto LABEL_81;
          case 5:
            v28 = 3;
LABEL_81:
            fldRunDanteStanceSet(v28, 0);
            evtBitOn(2804);
              goto LABEL_58;
            goto LABEL_56;
          case 7:
          case 8:
          case 9:
          case 0xA:
            v27 = 0;
            goto LABEL_67;
          default:
            v27 = 2;
LABEL_67:
            fldRunAiCng(v27);
            evtBitOff(2804);
              goto LABEL_58;
            goto LABEL_56;
        }
      }
      Copy(
        SuspendData,
        &SuspendDataCopy,
        0);
      Restore(SuspendData, &fldRun_Dante, &fldRun_Player);
      v21 = Allocate(evtUnitHandle_t);
      evtUnitHandle_t___ctor(v21);
      dds3GetUnitHandleObjectBasic(&player3);
      bMotionRestart = 1;
      bSuspendBGM = 1;
      bFirstStance = 1;
      {
LABEL_56:
      }
LABEL_58:
      fldRunDanteSetModel(v25);
      return;
  }
}

// 0x1787690
void fldRunDanteMove(void) {
  int16x4_t v3;
  int16x4_t v4;
  fldTest_c *v5;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 cnt_ex;
  struct fldTest_FLDRUN_DANTE_t_o *v9;
  s32 nextframe;
  struct fldTest_FLDRUN_DANTE_t_o *v11;
  s32 RouteDataTop;
  s32 now;
  s32 v14;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s32 v21;
  s16 v22;
  s32 v23;
  fldTest_FRO_ROUTEDATA_t_o *FroRouteData;
  int16x4_t v27;
  int16x4_t v28;
  int16x4_t v29;
  u32 x;
  u32 z;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v35;
  f32 v36;
  f32 v37;
  f32 v38;
  struct fldTest_FLDRUN_DANTE_t_o *v41;
  f32 v42;
  f32 v44;
  struct fldTest_FLDRUN_DANTE_t_o *v46;
  f32 r;
  f32 dir;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  s32 v54;
  struct fldTest_FLDRUN_DANTE_t_o *v55;
  s32 v56;
  s32 v57;
  f32 v58;
  f32 v59;
  fldTest_FRO_ROUTEDATA_t_o *v60;
  struct fldTest_StaticFields **v61;
  struct fldTest_FLDRUN_DANTE_t_o *v63;
  struct fldTest_FLDRUN_PLAYER_t_o *fldRun_Player;
  struct fldTest_StaticFields **v68;
  struct fldTest_FLDRUN_DANTE_t_o *v70;
  s32 FLDRUN_BGM_NML;
  s64 v75;
  s64 v76;
  s64 v77;
  s64 v78;
  s64 kakudo;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o v82;

  kakudo = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v3.n64_u16[0] = fldRun_MAP_OX;
  v4.n64_u16[0] = fldRun_MAP_OZ;
  cnt_ex = fldRun_Dante->cnt_ex;
  if (cnt_ex <= 299)
  {
    fldRun_Dante->cnt_ex = cnt_ex + 1;
  }
  v9 = fldRun_Dante;
  nextframe = v9->nextframe;
  if (nextframe >= 1)
  {
    v9->nextframe = nextframe - 1;
  }
  v11 = fldRun_Dante;
  RouteDataTop = v11->RouteDataTop;
  if (RouteDataTop == -1)
    goto LABEL_39;
  now = v11->now;
  if (now + 2 > v11->goal)
    goto LABEL_39;
  v14 = RouteDataTop + now + 2;
  GetFroRouteData(v14);
  sub_854930(&v77, 0);
  sub_854930(&v77, 1u);
  sub_854930(&v77, 2u);
  sub_854930(&v77, 3u);
  sub_854930(&v75, 0);
  sub_854930(&v75, 1u);
  sub_854930(&v75, 2u);
  sub_854930(&v75, 3u);
  v17 = v77;
  v18 = v78;
  v19 = v75;
  v20 = v76;
  *&v81.x = v17;
  *&v81.z = v18;
  *&v82.x = v19;
  *&v80.x = 0;
  *&v82.z = v20;
  v21 = fldHitChkEnemy(v81, v82, v80);
  if (v21 == -1)
  {
    fldRun_Dante->tikamiti = 1;
    FroRouteData = GetFroRouteData(v14);
    x = FroRouteData->x;
    z = FroRouteData->z;
    v29.n64_u16[0] = fldRun_MAP_BX;
    v27.n64_u16[0] = fldRun_MAP_OX;
    v28.n64_u16[0] = fldRun_MAP_OZ;
    fldRunGetLenKakudo2(
      (x * vmovl_s16(v29).n128_i32[0]) + vmovl_s16(v27).n128_i32[0],
      (z * -fldRun_MAP_BZ) + vmovl_s16(v28).n128_i32[0],
      &kakudo + 1,
      &kakudo);
    fldRun_Dante->nextframe = (*(&kakudo + 1)
                                                                     / fldRun_Dante->speed);
    LODWORD(fldRun_Dante->dir) = kakudo;
    ++fldRun_Dante->now;
    v22 = *&v5->_2.bitflags1;
    if ((v22 & 0x200) == 0)
      goto LABEL_40;
  }
  else
  {
LABEL_39:
    v22 = *&v5->_2.bitflags1;
    if ((v22 & 0x200) == 0)
    {
LABEL_40:
      v23 = 0;
      goto LABEL_53;
    }
  }
  v23 = v22 & 0x200;
LABEL_53:
  v35 = fldRun_Dante;
  if (v35->nextframe > 0)
  {
    v36 = (v35->dir * 3.14) / 180.0;
    v37 = v35->x;
    v38 = sdfSin(v36);
    v35->x = v37 + (v38 * fldRun_Dante->speed);
    v41 = fldRun_Dante;
    v42 = fldRun_Dante->z;
    v44 = sdfCos((fldRun_Dante->dir * 3.14) / 180.0, 0);
    v41->z = v42 + (v44 * fldRun_Dante->speed);
    v46 = fldRun_Dante;
    r = v46->r;
    dir = v46->dir;
    v49 = 180.0 - dir;
    v50 = R360_LR(r, v49);
    v51 = v50 / 10.0;
    if ((v50 / 10.0) < 0.0)
      v51 = -(v50 / 10.0);
    v52 = fmaxf(v51, 1.0);
    if ((v50 < 0.0 || v50 > v52) && (v50 > 0.0 || v50 < -v52))
    {
      if (v50 < 0.0)
      {
        v46->r = r - v52;
          goto LABEL_111;
        goto LABEL_104;
      }
      v49 = r + v52;
    }
    v46->r = v49;
      goto LABEL_111;
LABEL_104:
    goto LABEL_111;
  }
  v54 = v35->now;
  if (v54 < v35->goal)
  {
    v35->now = v54 + 1;
    (*p_static_fields)->fldRun_Dante->nextframe = 30;
  }
  v55 = fldRun_Dante;
  v56 = v55->RouteDataTop;
  if (v56 != -1)
  {
    v57 = vmovl_s16(v4).n128_u32[0];
    v58 = vmovl_s16(v3).n128_i32[0];
    v59 = v57;
    v60 = GetFroRouteData(v55->now + v56);
    fldRun_Dante->ix = v60->x;
    fldRun_Dante->iz = v60->z;
    fldRun_Dante->x = v58 + (fldRun_MAP_BX * v60->x);
    fldRun_Dante->z = v59 + -(v60->z * fldRun_MAP_BZ);
  }
  v63 = fldRun_Dante;
  if (fldRun_Player->ix != v63->ix)
    goto LABEL_107;
  if (fldRun_Player->iz != v63->iz)
    goto LABEL_107;
LABEL_97:
  v63->RouteIdx = -1;
  (*v61)->fldRun_Dante->RouteDataTop = -1;
  (*v61)->fldRun_Dante->now = 0;
  (*v61)->fldRun_Dante->goal = 0;
  (*v61)->fldRun_Dante->nextframe = 20;
  (*v61)->fldRun_Dante->speed = 0.0;
    goto LABEL_104;
LABEL_111:
  fldRunGetLenKakudo(&kakudo + 1, &kakudo);
  if (*(&kakudo + 1) >= 3000.0)
  {
    v70 = fldRun_Dante;
    if (v70->bgm_mode != FLDRUN_BGM_NML)
    {
      goto LABEL_126;
    }
  }
  else
  {
    v70 = fldRun_Dante;
    FLDRUN_BGM_NML = FLDRUN_BGM_BTL;
    if (v70->bgm_mode != FLDRUN_BGM_NML)
    {
LABEL_126:
      v70->bgm_mode = FLDRUN_BGM_NML;
      (*v68)->fldRun_Dante->update_flag |= 4u;
    }
  }
}

// 0x1786e20
void fldRunDanteNull(void) {
  ;
}

// 0x1789230
void fldRunDantePatr(void) {
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 cnt_ex;
  struct fldTest_FLDRUN_DANTE_t_o *v6;
  s32 nextframe;
  s32 RouteIdx;
  struct fldTest_FRO_ROUTEIDX_t_array *pFroRouteIdx;
  struct fldTest_FRO_ROUTEIDX_t_array *v19;
  u32 max_length;
  s64 v22;
  s32 RouteAddr;
  s64 v27;
  s64 v28;
  s64 v29;
  s64 v30;
  fldTest_FRO_ROUTEDATA_t_o *FroRouteData;
  int16x4_t v35;
  int16x4_t v36;
  int16x4_t v37;
  u32 x;
  u32 z;
  struct fldTest_FLDRUN_DANTE_t_o *v42;
  f32 r;
  f32 dir;
  f32 v45;
  f32 v47;
  f32 v48;
  f32 v49;
  struct fldTest_FLDRUN_DANTE_t_o *v50;
  f32 v51;
  f32 v52;
  f32 v53;
  struct fldTest_FLDRUN_DANTE_t_o *v56;
  f32 v57;
  f32 v58;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v64;
  s32 FLDRUN_BGM_BTL;
  s64 v67;
  s64 v68;
  s64 v69;
  s64 v70;
  s64 kakudo;
  UnityEngine_Vector4_o v72;
  UnityEngine_Vector4_o v73;
  UnityEngine_Vector4_o v74;

  v70 = 0;
  kakudo = 0;
  v69 = 0;
  v67 = 0;
  v68 = 0;
  cnt_ex = fldRun_Dante->cnt_ex;
  if (cnt_ex <= 299)
  {
    fldRun_Dante->cnt_ex = cnt_ex + 1;
  }
  v6 = fldRun_Dante;
  nextframe = v6->nextframe;
  if (nextframe >= 1)
  {
    v6->nextframe = nextframe - 1;
  }
  FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
  FroFtoI(fldGb->playerX, fldGb->playerZ, &fldRun_Player->ix, &fldRun_Player->iz);
  RouteIdx = FroGetRouteIdx(fldRun_Dante->ix, fldRun_Dante->iz, fldRun_Player->ix, fldRun_Player->iz);
  if (RouteIdx != -1)
  {
    fldRun_Dante->RouteIdx = RouteIdx;
    fldRun_Dante->goal_ix = fldRun_Player->ix;
    fldRun_Dante->goal_iz = fldRun_Player->iz;
    fldRun_Dante->now = 0;
    fldRun_Dante->nextframe = 0;
    fldRun_Dante->goal = pFroRouteIdx->m_Items[RouteIdx]->RouteNum - 1;
    v19 = pFroRouteIdx;
    max_length = v19->max_length;
    v22 = fldRun_Dante->RouteIdx;
    RouteAddr = v19->m_Items[RouteIdx]->RouteAddr;
    if (v19->m_Items[v22]->RouteNum >= 2)
    {
      GetFroRouteData(RouteAddr + 1);
      sub_854930(&v69, 0);
      sub_854930(&v69, 1u);
      sub_854930(&v69, 2u);
      sub_854930(&v69, 3u);
      sub_854930(&v67, 0);
      sub_854930(&v67, 1u);
      sub_854930(&v67, 2u);
      sub_854930(&v67, 3u);
      v27 = v69;
      v28 = v70;
      v29 = v67;
      v30 = v68;
      *&v73.x = v27;
      *&v73.z = v28;
      *&v74.x = v29;
      *&v72.x = 0;
      *&v74.z = v30;
      if (fldHitChkEnemy(v73, v74, v72) == -1)
      {
        ++fldRun_Dante->now;
        ++RouteAddr;
        fldRun_Dante->tikamiti = 1;
      }
    }
    FroRouteData = GetFroRouteData(RouteAddr);
    x = FroRouteData->x;
    z = FroRouteData->z;
    v37.n64_u16[0] = fldRun_MAP_BX;
    v35.n64_u16[0] = fldRun_MAP_OX;
    v36.n64_u16[0] = fldRun_MAP_OZ;
    fldRunGetLenKakudo2(
      (x * vmovl_s16(v37).n128_i32[0]) + vmovl_s16(v35).n128_i32[0],
      (z * -fldRun_MAP_BZ) + vmovl_s16(v36).n128_i32[0],
      &kakudo + 1,
      &kakudo);
    fldRun_Dante->nextframe = (*(&kakudo + 1)
                                                                     / fldRun_Dante->speed);
    LODWORD(fldRun_Dante->dir) = kakudo;
  }
  v42 = fldRun_Dante;
  r = v42->r;
  dir = v42->dir;
  v45 = 180.0 - dir;
  v47 = R360_LR(r, v45);
  v48 = v47 / 15.0;
  if ((v47 / 15.0) < 0.0)
    v48 = -(v47 / 15.0);
  v49 = fmaxf(v48, 1.0);
  if ((v47 < 0.0 || v47 > v49) && (v47 > 0.0 || v47 < -v49))
  {
    if (v47 >= 0.0)
      v45 = r + v49;
    else
      v45 = r - v49;
  }
  v42->r = v45;
  v50 = fldRun_Dante;
  v51 = (v50->dir * 3.14) / 180.0;
  v52 = v50->x;
  v53 = sdfSin(v51);
  v50->x = v52 + (v53 * fldRun_Dante->speed);
  v56 = fldRun_Dante;
  v57 = fldRun_Dante->z;
  v58 = sdfCos((fldRun_Dante->dir * 3.14) / 180.0, 0);
  v56->z = v57 + (v58 * fldRun_Dante->speed);
  FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
  v64 = fldRun_Dante;
  if (v64->bgm_mode != FLDRUN_BGM_BTL)
  {
    v64->bgm_mode = FLDRUN_BGM_BTL;
    (*p_static_fields)->fldRun_Dante->update_flag |= 4u;
  }
}

// 0x1788070
void fldRunDantePwak(void) {
  int16x4_t v3;
  int16x4_t v4;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 cnt_ex;
  struct fldTest_FLDRUN_DANTE_t_o *v9;
  s32 nextframe;
  struct fldTest_FLDRUN_DANTE_t_o *v11;
  s32 RouteDataTop;
  s32 now;
  s32 v14;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s16 v22;
  s32 v23;
  fldTest_FRO_ROUTEDATA_t_o *FroRouteData;
  int16x4_t v29;
  int16x4_t v30;
  int16x4_t v31;
  u32 x;
  u32 z;
  fldTest_FRO_ROUTEDATA_t_o *v34;
  f32 v37;
  f32 v38;
  System_Object_array *v40;
  System_Object_array *v41;
  s64 *v42;
  s64 *v43;
  s64 *v46;
  s64 *v47;
  s64 *v50;
  s64 *v51;
  s64 *v54;
  s64 *v55;
  System_Object_array *v58;
  System_Object_array *v59;
  s64 *v60;
  s64 *v61;
  s64 *v64;
  s64 *v65;
  s64 *v68;
  s64 *v69;
  s64 *v72;
  s64 *v73;
  s64 *v76;
  s64 *v77;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v81;
  f32 v82;
  f32 v83;
  f32 v84;
  struct fldTest_FLDRUN_DANTE_t_o *v87;
  f32 v88;
  f32 v90;
  struct fldTest_FLDRUN_DANTE_t_o *v92;
  f32 r;
  f32 v94;
  f32 v95;
  f32 v96;
  f32 v97;
  f32 v98;
  s32 v100;
  struct fldTest_FLDRUN_DANTE_t_o *v101;
  s32 v102;
  f32 v103;
  f32 v104;
  fldTest_FRO_ROUTEDATA_t_o *v105;
  struct fldTest_StaticFields **v106;
  struct fldTest_FLDRUN_DANTE_t_o *v108;
  struct fldTest_FLDRUN_PLAYER_t_o *fldRun_Player;
  struct fldTest_StaticFields **v113;
  struct fldTest_FLDRUN_DANTE_t_o *v115;
  s32 FLDRUN_BGM_NML;
  f32 dir;
  s16 v121[2];
  s16 ix;
  u8 v123[4];
  u8 v124[4];
  f32 v125;
  f32 v126;
  f32 v127;
  f32 v128;
  s64 v129;
  s64 v130;
  s64 v131;
  s64 v132;
  s64 kakudo;
  UnityEngine_Vector4_o v134;
  UnityEngine_Vector4_o v135;
  UnityEngine_Vector4_o v136;

  v132 = 0;
  kakudo = 0;
  v131 = 0;
  v129 = 0;
  v130 = 0;
  v3.n64_u16[0] = fldRun_MAP_OX;
  v4.n64_u16[0] = fldRun_MAP_OZ;
  cnt_ex = fldRun_Dante->cnt_ex;
  if (cnt_ex <= 299)
  {
    fldRun_Dante->cnt_ex = cnt_ex + 1;
  }
  v9 = fldRun_Dante;
  nextframe = v9->nextframe;
  if (nextframe >= 1)
  {
    v9->nextframe = nextframe - 1;
  }
  v11 = fldRun_Dante;
  RouteDataTop = v11->RouteDataTop;
  if (RouteDataTop == -1)
    goto LABEL_39;
  now = v11->now;
  if (now + 2 > v11->goal)
    goto LABEL_39;
  v14 = RouteDataTop + now + 2;
  GetFroRouteData(v14);
  sub_854930(&v131, 0);
  sub_854930(&v131, 1u);
  sub_854930(&v131, 2u);
  sub_854930(&v131, 3u);
  sub_854930(&v129, 0);
  sub_854930(&v129, 1u);
  sub_854930(&v129, 2u);
  sub_854930(&v129, 3u);
  v17 = v131;
  v18 = v132;
  v19 = v129;
  v20 = v130;
  *&v135.x = v17;
  *&v135.z = v18;
  *&v136.x = v19;
  *&v134.x = 0;
  *&v136.z = v20;
  if (fldHitChkEnemy(v135, v136, v134) == -1)
  {
    Write("TIKAMITI!!!\n", 0);
    fldRun_Dante->tikamiti = 1;
    FroRouteData = GetFroRouteData(v14);
    x = FroRouteData->x;
    z = FroRouteData->z;
    v34 = FroRouteData;
    v31.n64_u16[0] = fldRun_MAP_BX;
    v29.n64_u16[0] = fldRun_MAP_OX;
    v30.n64_u16[0] = fldRun_MAP_OZ;
    v37 = (x * vmovl_s16(v31).n128_i32[0]) + vmovl_s16(v29).n128_i32[0];
    v38 = (z * -fldRun_MAP_BZ) + vmovl_s16(v30).n128_i32[0];
    fldRunGetLenKakudo2(v37, v38, &kakudo + 1, &kakudo);
    fldRun_Dante->nextframe = (*(&kakudo + 1)
                                                                     / fldRun_Dante->speed);
    LODWORD(fldRun_Dante->dir) = kakudo;
    ++fldRun_Dante->now;
    v40 = NewSpecific(object, 4u);
    v128 = fldRun_Dante->x;
    v41 = v40;
    v42 = sub_8D3950(f32, &v128);
    v43 = v42;
    v41->m_Items[0] = v43;
    v127 = fldRun_Dante->z;
    v46 = sub_8D3950(f32, &v127);
    v47 = v46;
    v41->m_Items[1] = v47;
    v126 = v37;
    v50 = sub_8D3950(f32, &v126);
    v51 = v50;
    v41->m_Items[2] = v51;
    v125 = v38;
    v54 = sub_8D3950(f32, &v125);
    v55 = v54;
    v41->m_Items[3] = v55;
    Write_2930544("d:{0:f}, {1:f}, path:{2:f}, {3:f}\n", v41, 0);
    v58 = NewSpecific(object, 5u);
    v124[0] = v34->x;
    v59 = v58;
    v60 = sub_8D3950(qword_3F088F8, v124);
    v61 = v60;
    v59->m_Items[0] = v61;
    v123[0] = v34->z;
    v64 = sub_8D3950(qword_3F088F8, v123);
    v65 = v64;
    v59->m_Items[1] = v65;
    ix = fldRun_Dante->ix;
    v68 = sub_8D3950(s16, &ix);
    v69 = v68;
    v59->m_Items[2] = v69;
    v121[0] = fldRun_Dante->iz;
    v72 = sub_8D3950(s16, v121);
    v73 = v72;
    v59->m_Items[3] = v73;
    dir = fldRun_Dante->dir;
    v76 = sub_8D3950(f32, &dir);
    v77 = v76;
    v59->m_Items[4] = v77;
    Write_2930544("path_i:{0:D}, {1:D}  d_i:{2:D}, {3:D}  dir:{4:f}\n", v59, 0);
    if ((v22 & 0x200) == 0)
      goto LABEL_40;
  }
  else
  {
LABEL_39:
    if ((v22 & 0x200) == 0)
    {
LABEL_40:
      v23 = 0;
      goto LABEL_101;
    }
  }
  v23 = v22 & 0x200;
LABEL_101:
  v81 = fldRun_Dante;
  if (v81->nextframe > 0)
  {
    v82 = (v81->dir * 3.14) / 180.0;
    v83 = v81->x;
    v84 = sdfSin(v82);
    v81->x = v83 + (v84 * fldRun_Dante->speed);
    v87 = fldRun_Dante;
    v88 = fldRun_Dante->z;
    v90 = sdfCos((fldRun_Dante->dir * 3.14) / 180.0, 0);
    v87->z = v88 + (v90 * fldRun_Dante->speed);
    v92 = fldRun_Dante;
    r = v92->r;
    v94 = v92->dir;
    v95 = 180.0 - v94;
    v96 = R360_LR(r, v95);
    v97 = v96 / 15.0;
    if ((v96 / 15.0) < 0.0)
      v97 = -(v96 / 15.0);
    v98 = fmaxf(v97, 1.0);
    if ((v96 < 0.0 || v96 > v98) && (v96 > 0.0 || v96 < -v98))
    {
      if (v96 < 0.0)
      {
        v92->r = r - v98;
          goto LABEL_159;
        goto LABEL_152;
      }
      v95 = r + v98;
    }
    v92->r = v95;
      goto LABEL_159;
LABEL_152:
    goto LABEL_159;
  }
  v100 = v81->now;
  if (v100 < v81->goal)
  {
    v81->now = v100 + 1;
    (*p_static_fields)->fldRun_Dante->nextframe = 120;
  }
  v101 = fldRun_Dante;
  v102 = v101->RouteDataTop;
  if (v102 != -1)
  {
    v103 = vmovl_s16(v3).n128_i32[0];
    v104 = vmovl_s16(v4).n128_i32[0];
    v105 = GetFroRouteData(v101->now + v102);
    fldRun_Dante->ix = v105->x;
    fldRun_Dante->iz = v105->z;
    fldRun_Dante->x = v103 + (fldRun_MAP_BX * v105->x);
    fldRun_Dante->z = v104 + -(v105->z * fldRun_MAP_BZ);
  }
  v108 = fldRun_Dante;
  if (fldRun_Player->ix != v108->ix)
    goto LABEL_155;
  if (fldRun_Player->iz != v108->iz)
    goto LABEL_155;
LABEL_145:
  v108->RouteIdx = -1;
  (*v106)->fldRun_Dante->RouteDataTop = -1;
  (*v106)->fldRun_Dante->now = 0;
  (*v106)->fldRun_Dante->goal = 0;
  (*v106)->fldRun_Dante->nextframe = 20;
  (*v106)->fldRun_Dante->speed = 0.0;
    goto LABEL_152;
LABEL_159:
  fldRunGetLenKakudo(&kakudo + 1, &kakudo);
  if (*(&kakudo + 1) >= 3000.0)
  {
    v115 = fldRun_Dante;
    if (v115->bgm_mode != FLDRUN_BGM_NML)
    {
      goto LABEL_174;
    }
  }
  else
  {
    v115 = fldRun_Dante;
    FLDRUN_BGM_NML = FLDRUN_BGM_BTL;
    if (v115->bgm_mode != FLDRUN_BGM_NML)
    {
LABEL_174:
      v115->bgm_mode = FLDRUN_BGM_NML;
      (*v113)->fldRun_Dante->update_flag |= 4u;
    }
  }
}

// 0x178cb90
void fldRunDanteSe(void) {
  bool IsDLC;
  s64 *v3;
  System_String_o *v5;
  f32 *image;
  f32 v8;
  f32 v9;
  s32 v11;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  _BOOL4 v14;
  _BOOL4 v15;
  s32 v17;
  System_String_o *v20;
  s32 Id;
  s32 fldRunDanteSe_asise;
  s32 v26;
  u32 RandA;
  s32 v29;
  s32 v30;
  System_String_o *v33;
  s32 v34;
  System_String_o *v36;
  struct fldTest_FLDRUN_DANTE_t_o *v37;

  IsDLC = IsDLC();
  v3 = &"M";
  if (!IsDLC)
    v3 = &"R";
  v5 = Format("F058{0}_7", *v3, 0);
  image = v6[2].klass->_1.image;
  v8 = image[9];
  v9 = image[10];
  v11 = fldRunVolCalc(image[5], image[6], image[7]);
  switch (fldRun_Dante->motion)
  {
    case 0:
      v14 = v8 < 5.0;
      v15 = v9 >= 5.0;
      if (v9 >= 15.0 && v8 < 15.0)
        goto LABEL_29;
      goto LABEL_16;
    case 1:
      v17 = (fldRun_Dante->update_flag >> 1) & 1;
      if (v9 >= 3.0 && v8 < 3.0 || v9 >= 18.0 && v8 < 18.0)
        goto LABEL_30;
      if (!v17)
        goto LABEL_55;
      goto LABEL_51;
    case 2:
      v14 = v8 < 5.0;
      v15 = v9 >= 5.0;
      if (v9 >= 24.0 && v8 < 24.0)
        goto LABEL_29;
LABEL_16:
      if (!v15 || !v14)
        goto LABEL_55;
LABEL_29:
      v17 = 0;
LABEL_30:
      v20 = Concat_5224608(v5, "1");
      Id = FindId(1, v20);
      p2sdPlaySE_Vol(fldRunDanteSe_asise + Id, v11);
      v26 = fldRunDanteSe_asise;
      RandA = dds3GetRandA("");
      fldRunDanteSe_asise = v26 + ((RandA >> 4) & 1) + 1;
      v29 = fldRunDanteSe_asise;
      v30 = v29 + 3;
      if (v29 >= 0)
        v30 = fldRunDanteSe_asise;
      fldRunDanteSe_asise = v29 - (v30 & 0xFFFFFFFC);
      if (v17)
      {
LABEL_51:
        v33 = Concat_5224608(v5, "A");
        p2sdPlaySE_Vol_20173952(v33, 30 * v11 / 100);
      }
LABEL_55:
      else if ((fldRun_Dante->update_flag & 8) == 0)
      {
        goto LABEL_62;
      }
      v34 = 30 * v11 / 100;
      v36 = Concat_5224608(v5, "5");
      p2sdPlaySE_Vol_20173952(v36, v34);
LABEL_62:
      else
      {
        v37 = fldRun_Dante;
        if ((v37->update_flag & 4) == 0)
          return;
      }
      fldRunCngBgm(v37->bgm_mode);
      return;
    case 4:
      if (v9 < 17.0 || v8 >= 17.0)
        goto LABEL_55;
      goto LABEL_51;
    default:
      goto LABEL_55;
  }
}

// 0x177e710
void fldRunDanteSetModel(void) {
  UnityEngine_Object_o *gameObject;
  struct dds3Basic_t_o *player3;
  UnityEngine_Object_o *v8;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v14;
  Il2CppObject *v17;
  Il2CppClass *v19;
  s64 v20;
  char *v21;
  s64 *v22;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  dds3PoseSet_t_o **v30;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  dds3PoseSet_t_o **p_poseset;
  f32 v44;
  f32 v45;
  f32 v47;
  f32 v48;
  f32 v50;
  s64 p_pos2;
  f32 v53;
  f32 v54;
  f32 v56;
  f32 v57;
  f32 v59;
  s64 v61;
  f32 v62;
  f32 v63;
  f32 v65;
  f32 v66;
  f32 v68;
  s64 v70;
  char *v121;
  s64 *v122;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  evtUnitHandle_t_o *h;
  dds3ModelHandle_t_o *aHandle;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v127;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v129;
  u64 v130[2];
  char *v131;
  f32 kakudo;
  f32 len;
  UnityEngine_Vector4_o v134;

  *&v129.x = 0;
  *&v129.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v127.x = 0;
  *&v127.z = 0;
  UnitHandleObjectBasic = 0;
  *&p.x = 0;
  *&p.z = 0;
  h = 0;
  aHandle = 0;
  sub_854690(&v129.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&dst.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v127.x, 0.0, 1.0, 0.0, 1.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  len = 0.0;
  kakudo = 0.0;
  gameObject = player3->gameObject;
  if (op_Equality(gameObject, 0, 0))
  {
    player3->gameObject = fldPlayer3LoadForUnity();
    v8 = player3->gameObject;
    if (op_Inequality(v8, 0, 0))
    {
      ModelHandle = dds3ObjectBaseGetModelHandle(&player3);
      klass = ModelHandle->klass;
      if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v130);
        if ((v130[0] & 1) != 0)
          v121 = v131;
        else
          v121 = v130 + 1;
        v122 = sub_8C4940(v121);
      }
      ModelHandle[6].klass = player3;
    }
  }
  v14 = player3->gameObject;
  if (!op_Equality(v14, 0, 0))
  {
    v17 = dds3ObjectBaseGetModelHandle(&player3);
    if (v17)
    {
      v19 = v17->klass;
      if (v17->klass->_2.typeHierarchyDepth < v20
        || v19->_2.typeHierarchy[v20 - 1] != dds3ModelHandle_t)
      {
        sub_8FC2C0(v19->_1.element_class, dds3ModelHandle_t, v130);
        if ((v130[0] & 1) != 0)
          v21 = v131;
        else
          v21 = v130 + 1;
        v22 = sub_8C4940(v21);
      }
    }
    aHandle = v17;
    sub_854930(&v129, 0);
    sub_854930(&v129, 1u);
    sub_854930(&v129, 2u);
    x = v129.x;
    y = v129.y;
    z = v129.z;
    w = v129.w;
    v134.x = x;
    v134.y = y;
    v134.z = z;
    v134.w = w;
    dds3SetPosPoseSet(&player3, v134);
    SDF_VU0__LOADVECTOR(v127);
    FromRotation((fldRun_Dante->r * 3.14) / 180.0, 0);
    SDF_VU0__STOREVECTOR(&p);
    dds3SetRotPoseSet(&player3, p);
    if ((fldRun_Dante->update_flag & 0x40) != 0)
    {
      p_poseset = &player3->poseset;
      dds3OnPoseSetFlag(p_poseset, 8u);
      SDF_VU0__COPYVECTOR(&dst, player3->poseset->pos2);
      sub_854710(&dst, 0);
      v45 = v44;
      sub_854710(&v129, 0);
      v48 = v47;
      v50 = sdfFabs(v45 - v48);
      if (v50 >= 1.0)
      {
        p_pos2 = &player3->poseset->pos2;
        sub_854710(&dst, 0);
        sub_854710(&v129, 0);
        sub_854710(&dst, 0);
      }
      else
      {
        p_pos2 = &player3->poseset->pos2;
        sub_854710(&v129, 0);
      }
      sub_854930(p_pos2, 0);
      sub_854710(&dst, 1u);
      v54 = v53;
      sub_854710(&v129, 1u);
      v57 = v56;
      v59 = sdfFabs(v54 - v57);
      if (v59 >= 1.0)
      {
        v61 = &player3->poseset->pos2;
        sub_854710(&dst, 1u);
        sub_854710(&v129, 1u);
        sub_854710(&dst, 1u);
      }
      else
      {
        v61 = &player3->poseset->pos2;
        sub_854710(&v129, 1u);
      }
      sub_854930(v61, 1u);
      sub_854710(&dst, 2u);
      v63 = v62;
      sub_854710(&v129, 2u);
      v66 = v65;
      v68 = sdfFabs(v63 - v66);
      if (v68 >= 1.0)
      {
        v70 = &player3->poseset->pos2;
        sub_854710(&dst, 2u);
        sub_854710(&v129, 2u);
        sub_854710(&dst, 2u);
      }
      else
      {
        v70 = &player3->poseset->pos2;
        sub_854710(&v129, 2u);
      }
      sub_854930(v70, 2u);
      sub_854930(&player3->poseset->pos2, 3u);
        goto LABEL_136;
    }
    else
    {
      v30 = &player3->poseset;
      dds3OffPoseSetFlag(v30, 8u);
        goto LABEL_136;
    }
LABEL_136:
    if ((fldRun_Dante->update_flag & 0x20) != 0)
      goto LABEL_137;
    goto LABEL_59;
  }
}

// 0x1788e90
void fldRunDanteSoba(void) {
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 nextframe;
  struct fldTest_FLDRUN_DANTE_t_o *v5;
  f32 d_p_len;
  struct fldTest_FLDRUN_DANTE_t_o *v7;
  f32 r;
  f32 dir;
  f32 v10;
  f32 v13;
  f32 v14;
  f32 v15;
  struct fldTest_FLDRUN_DANTE_t_o *v17;
  f32 v18;
  f32 x;
  f32 v20;
  struct fldTest_FLDRUN_DANTE_t_o *v23;
  f32 z;
  f32 v25;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v30;
  s32 FLDRUN_BGM_NML;

  nextframe = fldRun_Dante->nextframe;
  if (nextframe >= 1)
  {
    fldRun_Dante->nextframe = nextframe - 1;
  }
  v5 = fldRun_Dante;
  v5->dir = v5->d_p_dir;
  d_p_len = v5->d_p_len;
  v7 = fldRun_Dante;
  r = v7->r;
  dir = v7->dir;
  v10 = 180.0 - dir;
  v13 = R360_LR(r, v10);
  v14 = v13 / 10.0;
  if ((v13 / 10.0) < 0.0)
    v14 = -(v13 / 10.0);
  v15 = fmaxf(v14, 1.0);
  if ((v13 < 0.0 || v13 > v15) && (v13 > 0.0 || v13 < -v15))
  {
    if (v13 >= 0.0)
      v10 = r + v15;
    else
      v10 = r - v15;
  }
  v7->r = v10;
  if (d_p_len > 100.0)
  {
    v17 = fldRun_Dante;
    v18 = (v17->dir * 3.14) / 180.0;
    x = v17->x;
    v20 = sdfSin(v18);
    v17->x = x + (v20 * fldRun_Dante->speed);
    v23 = fldRun_Dante;
    z = fldRun_Dante->z;
    v25 = sdfCos((fldRun_Dante->dir * 3.14) / 180.0, 0);
    v23->z = z + (v25 * fldRun_Dante->speed);
  }
  FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
  if (d_p_len >= 3600.0)
  {
    v30 = fldRun_Dante;
    if (v30->bgm_mode != FLDRUN_BGM_NML)
    {
      goto LABEL_54;
    }
  }
  else
  {
    v30 = fldRun_Dante;
    FLDRUN_BGM_NML = FLDRUN_BGM_BTL;
    if (v30->bgm_mode != FLDRUN_BGM_NML)
    {
LABEL_54:
      v30->bgm_mode = FLDRUN_BGM_NML;
      (*p_static_fields)->fldRun_Dante->update_flag |= 4u;
    }
  }
}

// 0x1780360
void fldRunDanteStanceSet(s32 id, bool recover) {
  struct fldTest_FLDRUN_DANTE_t_o *v10;
  f32 v11;
  struct fldTest_FLDRUN_DANTE_t_o *v12;
  f32 v13;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  f32 v22;
  struct fldTest_FLDRUN_DANTE_t_o *v23;
  f32 v25;
  struct fldTest_FLDRUN_DANTE_t_o *v26;
  f32 x;
  f32 z;
  s16 *p_ix;
  s16 *p_iz;
  struct fldTest_FLDRUN_DANTE_t_o *v32;
  struct fldTest_FLDRUN_DANTE_t_o *v35;
  struct fldTest_FLDRUN_DANTE_t_o *v38;
  Il2CppObject *v39;
  System_Char_array *v40;
  int16x4_t v42;
  int16x4_t v43;
  int16x4_t v44;
  struct fldTest_FLDRUN_DOOR_t_array *fldRunDoorTbl;
  struct fldTest_FLDRUN_DOOR_t_o *pDoor;
  fldTest_FLDRUN_DOOR_t_o *v50;
  struct fldTest_FLDRUN_DANTE_t_o *v51;
  s32 RestoreMode;
  fldTest_c *v56;
  struct fldTest_FLDRUN_DANTE_t_o *v59;
  f32 v60;
  struct fldTest_FLDRUN_DANTE_t_o *v61;
  f32 v62;
  struct fldGlobalWork_t_o *v64;
  struct fldTest_FLDRUN_PLAYER_t_o *fldRun_Player;
  s32 v71;
  struct fldTest_FLDRUN_DANTE_t_o *v74;
  f32 v75;
  struct fldTest_FLDRUN_DANTE_t_o *v76;
  f32 v77;
  struct fldTest_FLDRUN_DANTE_t_o *v83;
  f32 v84;
  struct fldTest_FLDRUN_DANTE_t_o *v85;
  f32 v86;
  s32 v89;
  struct fldTest_FLDRUN_DANTE_t_o *v90;
  Il2CppObject *v91;
  System_Char_array *v92;
  struct fldTest_FLDRUN_DOOR_t_array *v94;
  struct fldTest_FLDRUN_DOOR_t_o *v95;
  fldTest_FLDRUN_DOOR_t_o *v97;
  struct fldTest_FLDRUN_DANTE_t_o *v98;
  s16 ix;
  s16 iz;
  struct fldTest_FLDRUN_DANTE_t_o *v103;
  Il2CppObject *v104;
  System_Char_array *v105;
  int16x4_t v107;
  int16x4_t v108;
  int16x4_t v109;
  struct fldTest_FLDRUN_DOOR_t_array *v112;
  struct fldTest_FLDRUN_DOOR_t_o *v113;
  fldTest_FLDRUN_DOOR_t_o *v115;
  struct fldTest_FLDRUN_DANTE_t_o *v116;
  struct fldTest_FLDRUN_DANTE_t_o *v117;
  s16 v118;
  s16 v119;
  struct fldTest_FLDRUN_DANTE_t_o *v121;
  Il2CppObject *v122;
  System_Char_array *v123;
  int16x4_t v124;
  int16x4_t v125;
  struct fldTest_FLDRUN_DOOR_t_array *v128;
  struct fldTest_FLDRUN_DOOR_t_o *v129;
  fldTest_FLDRUN_DOOR_t_o *v131;
  struct fldTest_FLDRUN_DANTE_t_o *v132;
  struct fldGlobalWork_t_o *fldGb;
  struct fldTest_FLDRUN_DANTE_t_o *v137;
  Il2CppObject *v138;
  System_Char_array *v139;
  int16x4_t v140;
  int16x4_t v141;
  int16x4_t v142;
  struct fldTest_FLDRUN_DOOR_t_array *v144;
  struct fldTest_FLDRUN_DOOR_t_o *v145;
  fldTest_FLDRUN_DOOR_t_o **v147;
  struct fldTest_FLDRUN_DANTE_t_o *v148;
  Il2CppObject *v149;
  System_Char_array *v150;
  struct fldTest_FLDRUN_DOOR_t_array *v153;
  struct fldTest_FLDRUN_DOOR_t_o *v154;
  fldTest_FLDRUN_DOOR_t_o *v156;
  struct fldTest_FLDRUN_DANTE_t_o *v157;
  struct fldTest_FLDRUN_DOOR_t_o *v158;
  struct fldTest_FLDRUN_DANTE_t_o *v159;
  s16 v160;
  s16 v161;
  struct fldTest_FLDRUN_DANTE_t_o *v164;
  Il2CppObject *v165;
  System_Char_array *v166;
  struct fldTest_FLDRUN_DOOR_t_array *v168;
  struct fldTest_FLDRUN_DOOR_t_o *v169;
  fldTest_FLDRUN_DOOR_t_o **v171;
  struct fldTest_FLDRUN_DANTE_t_o *v172;
  Il2CppObject *v173;
  System_Char_array *v174;
  struct fldTest_FLDRUN_DOOR_t_array *v176;
  fldTest_FLDRUN_DOOR_t_o *v178;
  struct fldTest_FLDRUN_DANTE_t_o *v179;
  struct fldTest_FLDRUN_DANTE_t_o *v180;
  s16 v181;
  s16 v182;
  struct fldTest_FLDRUN_DANTE_t_o *v185;
  Il2CppObject *v186;
  System_Char_array *v187;
  struct fldTest_FLDRUN_DOOR_t_array *v189;
  fldTest_FLDRUN_DOOR_t_o *v191;
  struct fldTest_FLDRUN_DANTE_t_o *v192;
  struct fldTest_FLDRUN_DOOR_t_o *v193;
  s16 v194;
  int16x4_t v196;
  int16x4_t v197;
  int16x4_t v198;
  UnityEngine_Vector4_o p;
  s64 kakudo;
  UnityEngine_Vector4_o zero;

  *&p.x = 0;
  *&p.z = 0;
  zero = get_zero();
  v196.n64_u16[1] = HIWORD(zero.x);
  v197.n64_u16[1] = HIWORD(zero.y);
  v198.n64_u16[1] = HIWORD(zero.z);
  p = zero;
  fldRun_Dante->update_flag = 0;
  fldRun_Dante->stance = id;
  fldRun_Dante->update_flag |= 0x40u;
  switch (id)
  {
    case 1:
      dds3GetPosPoseSet(&player3);
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&p, 0);
      fldRun_Dante->x = v22;
      v23 = fldRun_Dante;
      sub_854710(&p, 2u);
      v23->z = v25;
      v26 = fldRun_Dante;
      x = v26->x;
      z = v26->z;
      p_ix = &v26->ix;
      p_iz = &v26->iz;
      goto LABEL_84;
    case 2:
      kakudo = 0;
      fldRunGetLenKakudo(&kakudo + 1, &kakudo);
      LODWORD(fldRun_Dante->dir) = kakudo;
      v32 = fldRun_Dante;
      v196.n64_f32[0] = 180.0 - v32->dir;
      LODWORD(v32->r) = v196.n64_u32[0];
      if (fldGb->areaOldID == 4)
      {
        v35 = fldRun_Dante;
        if (v35->old_status != 1)
          goto LABEL_195;
      }
      if (evtBitCheck(1969) && evtBitCheck(1970) && !recover)
      {
        v38 = fldRun_Dante;
        v39 = Allocate(fldTest_FLDRUN_DOOR_t);
        v40 = NewSpecific(char, 8u);
        v39[1].klass = CreateString_5280336(0, v40);
        _ctor(v39, 0);
        v38->pDoor = v39;
        pDoor = fldRun_Dante->pDoor;
        v50 = fldRunDoorTbl->m_Items[0];
        pDoor->name = v50->name;
        pDoor->ix = v50->ix;
        pDoor->iz = v50->iz;
        pDoor->dir = v50->dir;
        fldRun_Dante->ix = fldRun_Dante->pDoor->ix;
        fldRun_Dante->iz = fldRun_Dante->pDoor->iz;
        fldRun_Dante->dir = fldRun_Dante->pDoor->dir;
        fldRun_Dante->pDoor = 0;
        v51 = fldRun_Dante;
        v42.n64_f32[0] = 180.0 - v51->dir;
LABEL_141:
        LODWORD(v51->r) = v42.n64_u32[0];
        v98 = fldRun_Dante;
        ix = v98->ix;
        iz = v98->iz;
        v44.n64_u16[0] = fldRun_MAP_BX;
        v42.n64_u16[0] = fldRun_MAP_OX;
        v43.n64_u16[0] = fldRun_MAP_OZ;
        v98->x = (ix * vmovl_s16(v44).n128_i32[0]) + vmovl_s16(v42).n128_i32[0];
        v98->z = (iz * -fldRun_MAP_BZ) + vmovl_s16(v43).n128_i32[0];
        fldRun_Dante->update_flag |= 0x20u;
        fldRunAiCng(1);
        fldRunDanteSetModel();
        fldRun_Dante->stance = 9;
        return;
      }
      if (fldGb->areaOldID == 3)
      {
          goto LABEL_247;
        goto LABEL_245;
      }
      if (fldGb->playerZ >= -4000.0)
      {
        {
LABEL_247:
          v185 = fldRun_Dante;
          v186 = Allocate(fldTest_FLDRUN_DOOR_t);
          v187 = NewSpecific(char, 8u);
          v186[1].klass = CreateString_5280336(0, v187);
          _ctor(v186, 0);
          v185->pDoor = v186;
          v189 = fldRunDoorTbl;
          v169 = fldRun_Dante->pDoor;
          v171 = &v189->m_Items[2];
          goto LABEL_252;
        }
LABEL_245:
        goto LABEL_247;
      }
      v164 = fldRun_Dante;
      v165 = Allocate(fldTest_FLDRUN_DOOR_t);
      v166 = NewSpecific(char, 8u);
      v165[1].klass = CreateString_5280336(0, v166);
      _ctor(v165, 0);
      v164->pDoor = v165;
      v168 = fldRunDoorTbl;
      v169 = fldRun_Dante->pDoor;
      v171 = &v168->m_Items[1];
LABEL_252:
      v191 = *v171;
      v169->name = v191->name;
      v169->ix = v191->ix;
      v169->iz = v191->iz;
      v169->dir = v191->dir;
      v192 = fldRun_Dante;
      v193 = v192->pDoor;
      if (v193)
      {
        v192->ix = v193->ix;
        fldRun_Dante->iz = fldRun_Dante->pDoor->iz;
        fldRun_Dante->dir = fldRun_Dante->pDoor->dir;
      }
      v132 = fldRun_Dante;
      v124.n64_f32[0] = 180.0 - v132->dir;
LABEL_264:
      LODWORD(v132->r) = v124.n64_u32[0];
      v159 = fldRun_Dante;
      v194 = v159->ix;
      v161 = v159->iz;
      v125.n64_u16[0] = fldRun_MAP_BX;
      v124.n64_u16[0] = fldRun_MAP_OX;
      v197.n64_u16[0] = fldRun_MAP_OZ;
      v159->x = (v194 * vmovl_s16(v125).n128_i32[0]) + vmovl_s16(v124).n128_i32[0];
      v89 = 2;
LABEL_270:
      v159->z = (v161 * -fldRun_MAP_BZ) + vmovl_s16(v197).n128_i32[0];
LABEL_271:
      fldRunAiCng(v89);
LABEL_272:
      fldRunDanteSetModel();
      return;
    case 3:
      RestoreMode = fldGetRestoreMode();
      kakudo = 0;
      fldRunGetLenKakudo(&kakudo + 1, &kakudo);
      LODWORD(fldRun_Dante->dir) = kakudo;
      fldRun_Dante->r = 180.0 - fldRun_Dante->dir;
      if (RestoreMode == 1)
      {
        if ((v56->_2.bitflags2 & 2) == 0)
          goto LABEL_241;
        goto LABEL_101;
      }
      if (fldGb->playerZ >= -4000.0)
      {
        v172 = fldRun_Dante;
        v173 = Allocate(fldTest_FLDRUN_DOOR_t);
        v174 = NewSpecific(char, 8u);
        v173[1].klass = CreateString_5280336(0, v174);
        _ctor(v173, 0);
        v172->pDoor = v173;
        v176 = fldRunDoorTbl;
        v145 = fldRun_Dante->pDoor;
        v147 = &v176->m_Items[5];
      }
      else
      {
        v137 = fldRun_Dante;
        v138 = Allocate(fldTest_FLDRUN_DOOR_t);
        v139 = NewSpecific(char, 8u);
        v138[1].klass = CreateString_5280336(0, v139);
        _ctor(v138, 0);
        v137->pDoor = v138;
        v144 = fldRunDoorTbl;
        v145 = fldRun_Dante->pDoor;
        v147 = &v144->m_Items[4];
      }
      v178 = *v147;
      v145->name = v178->name;
      v145->ix = v178->ix;
      v145->iz = v178->iz;
      v145->dir = v178->dir;
      v157 = fldRun_Dante;
      v158 = v157->pDoor;
      if (!v158)
        goto LABEL_232;
      goto LABEL_228;
    case 4:
    case 104:
      dds3GetPosPoseSet(&player3);
      SDF_VU0__STOREVECTOR(&p);
      v10 = fldRun_Dante;
      sub_854710(&p, 0);
      v10->x = v11;
      v12 = fldRun_Dante;
      sub_854710(&p, 2u);
      v12->z = v13;
      FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
      fldRunAiCng(1);
      if ((byte_3F5A644 & 1) != 0)
        goto LABEL_86;
      kakudo = 0;
        goto LABEL_21;
      goto LABEL_87;
    case 5:
      dds3GetPosPoseSet(&player3);
      SDF_VU0__STOREVECTOR(&p);
      v59 = fldRun_Dante;
      sub_854710(&p, 0);
      v59->x = v60;
      v61 = fldRun_Dante;
      sub_854710(&p, 2u);
      v61->z = v62;
      FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
      v64 = fldGb;
      x = v64->playerX;
      z = v64->playerZ;
      p_ix = &fldRun_Player->ix;
      p_iz = &fldRun_Player->iz;
LABEL_84:
      FroFtoI(x, z, p_ix, p_iz);
      fldRunAiCng(6);
      if ((byte_3F5A644 & 1) == 0)
        goto LABEL_85;
      goto LABEL_86;
    case 6:
      v71 = fldGetRestoreMode();
      kakudo = 0;
      fldRunGetLenKakudo(&kakudo + 1, &kakudo);
      LODWORD(fldRun_Dante->dir) = kakudo;
      fldRun_Dante->r = 180.0 - fldRun_Dante->dir;
      if (v71 == 1)
      {
        if ((*&v56->_2.bitflags1 & 0x200) != 0)
        {
LABEL_101:
        }
      }
      else
      {
        v148 = fldRun_Dante;
        v149 = Allocate(fldTest_FLDRUN_DOOR_t);
        v150 = NewSpecific(char, 8u);
        v149[1].klass = CreateString_5280336(0, v150);
        _ctor(v149, 0);
        v148->pDoor = v149;
        v153 = fldRunDoorTbl;
        v154 = fldRun_Dante->pDoor;
        v156 = v153->m_Items[6];
        v154->name = v156->name;
        v154->ix = v156->ix;
        v154->iz = v156->iz;
        v154->dir = v156->dir;
        v157 = fldRun_Dante;
        v158 = v157->pDoor;
        if (v158)
        {
LABEL_228:
          v157->ix = v158->ix;
          fldRun_Dante->iz = fldRun_Dante->pDoor->iz;
          fldRun_Dante->dir = fldRun_Dante->pDoor->dir;
        }
LABEL_232:
        v179 = fldRun_Dante;
        v140.n64_f32[0] = 180.0 - v179->dir;
        LODWORD(v179->r) = v140.n64_u32[0];
        v180 = fldRun_Dante;
        v181 = v180->ix;
        v182 = v180->iz;
        v142.n64_u16[0] = fldRun_MAP_BX;
        v140.n64_u16[0] = fldRun_MAP_OX;
        v141.n64_u16[0] = fldRun_MAP_OZ;
        v180->x = (v181 * vmovl_s16(v142).n128_i32[0]) + vmovl_s16(v140).n128_i32[0];
        v180->z = (v182 * -fldRun_MAP_BZ) + vmovl_s16(v141).n128_i32[0];
      }
LABEL_241:
      fldRunAiCng(2);
      goto LABEL_272;
    case 7:
      dds3GetPosPoseSet(&player3);
      SDF_VU0__STOREVECTOR(&p);
      v74 = fldRun_Dante;
      sub_854710(&p, 0);
      v74->x = v75;
      v76 = fldRun_Dante;
      sub_854710(&p, 2u);
      v76->z = v77;
      FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
      fldRunAiCng(5);
      if ((byte_3F5A644 & 1) != 0)
        goto LABEL_86;
LABEL_85:
LABEL_86:
      kakudo = 0;
        goto LABEL_87;
LABEL_21:
LABEL_87:
      fldRunGetLenKakudo(&kakudo + 1, &kakudo);
      LODWORD(fldRun_Dante->dir) = kakudo;
      fldRun_Dante->r = 180.0 - fldRun_Dante->dir;
      goto LABEL_272;
    case 9:
      if (fldGb->areaOldID != 7)
        goto LABEL_123;
      v35 = fldRun_Dante;
      if (v35->old_status != 1)
      {
LABEL_195:
        v35->ix = v35->backup_ix;
        fldRun_Dante->iz = fldRun_Dante->backup_iz;
        v159 = fldRun_Dante;
        v160 = v159->ix;
        v161 = v159->iz;
        v198.n64_u16[0] = fldRun_MAP_BX;
        v196.n64_u16[0] = fldRun_MAP_OX;
        v197.n64_u16[0] = fldRun_MAP_OZ;
        v159->x = (v160 * vmovl_s16(v198).n128_i32[0]) + vmovl_s16(v196).n128_i32[0];
        v89 = 6;
        goto LABEL_270;
      }
LABEL_123:
      dds3GetPosPoseSet(&player3);
      SDF_VU0__STOREVECTOR(&p);
      v83 = fldRun_Dante;
      sub_854710(&p, 0);
      v83->x = v84;
      v85 = fldRun_Dante;
      sub_854710(&p, 2u);
      v85->z = v86;
      FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
      fldRun_Dante->dir = 180.0;
      fldRun_Dante->r = 180.0 - fldRun_Dante->dir;
      v89 = 1;
      goto LABEL_271;
    case 10:
      v90 = fldRun_Dante;
      v91 = Allocate(fldTest_FLDRUN_DOOR_t);
      v92 = NewSpecific(char, 8u);
      v91[1].klass = CreateString_5280336(0, v92);
      _ctor(v91, 0);
      v90->pDoor = v91;
      v94 = fldRunDoorTbl;
      v95 = fldRun_Dante->pDoor;
      v97 = v94->m_Items[0];
      v95->name = v97->name;
      v95->ix = v97->ix;
      v95->iz = v97->iz;
      v95->dir = v97->dir;
      fldRun_Dante->ix = fldRun_Dante->pDoor->ix;
      fldRun_Dante->iz = fldRun_Dante->pDoor->iz;
      fldRun_Dante->dir = fldRun_Dante->pDoor->dir;
      fldRun_Dante->pDoor = 0;
      v51 = fldRun_Dante;
      v43.n64_u16[1] = 17204;
      v42.n64_f32[0] = 180.0 - v51->dir;
      goto LABEL_141;
    case 11:
      v103 = fldRun_Dante;
      v104 = Allocate(fldTest_FLDRUN_DOOR_t);
      v105 = NewSpecific(char, 8u);
      v104[1].klass = CreateString_5280336(0, v105);
      _ctor(v104, 0);
      v103->pDoor = v104;
      v112 = fldRunDoorTbl;
      v113 = fldRun_Dante->pDoor;
      v115 = v112->m_Items[2];
      v113->name = v115->name;
      v113->ix = v115->ix;
      v113->iz = v115->iz;
      v113->dir = v115->dir;
      fldRun_Dante->ix = fldRun_Dante->pDoor->ix;
      fldRun_Dante->iz = fldRun_Dante->pDoor->iz;
      fldRun_Dante->dir = fldRun_Dante->pDoor->dir;
      v116 = fldRun_Dante;
      v108.n64_u16[1] = 17204;
      v107.n64_f32[0] = 180.0 - v116->dir;
      LODWORD(v116->r) = v107.n64_u32[0];
      v117 = fldRun_Dante;
      v118 = v117->ix;
      v119 = v117->iz;
      v109.n64_u16[0] = fldRun_MAP_BX;
      v107.n64_u16[0] = fldRun_MAP_OX;
      v108.n64_u16[0] = fldRun_MAP_OZ;
      v117->x = (v118 * vmovl_s16(v109).n128_i32[0]) + vmovl_s16(v107).n128_i32[0];
      v117->z = (v119 * -fldRun_MAP_BZ) + vmovl_s16(v108).n128_i32[0];
      fldRunAiCng(2);
      evtBitOff(2804);
      goto LABEL_272;
    case 12:
      v121 = fldRun_Dante;
      v122 = Allocate(fldTest_FLDRUN_DOOR_t);
      v123 = NewSpecific(char, 8u);
      v122[1].klass = CreateString_5280336(0, v123);
      _ctor(v122, 0);
      v121->pDoor = v122;
      v128 = fldRunDoorTbl;
      v129 = fldRun_Dante->pDoor;
      v131 = v128->m_Items[2];
      v129->name = v131->name;
      v129->ix = v131->ix;
      v129->iz = v131->iz;
      v129->dir = v131->dir;
      fldRun_Dante->ix = fldRun_Dante->pDoor->ix;
      fldRun_Dante->iz = fldRun_Dante->pDoor->iz;
      fldRun_Dante->dir = fldRun_Dante->pDoor->dir;
      v132 = fldRun_Dante;
      v197.n64_u16[1] = 17204;
      v124.n64_f32[0] = 180.0 - v132->dir;
      goto LABEL_264;
    default:
      return;
  }
}

// 0x1786e30
void fldRunDanteStnd(void) {
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 nextframe;

  nextframe = fldRun_Dante->nextframe;
  if (nextframe >= 1)
  {
    fldRun_Dante->nextframe = nextframe - 1;
  }
}

// 0x1786ed0
void fldRunDanteWait(void) {
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 nextframe;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v7;
  s32 FLDRUN_BGM_NML;

  nextframe = fldRun_Dante->nextframe;
  if (nextframe >= 1)
  {
    fldRun_Dante->nextframe = nextframe - 1;
  }
  v7 = fldRun_Dante;
  if (v7->bgm_mode != FLDRUN_BGM_NML)
  {
    v7->bgm_mode = FLDRUN_BGM_NML;
    (*p_static_fields)->fldRun_Dante->update_flag |= 4u;
  }
}

// 0x1783f40
void fldRunEffSet(s32 id, f32 x, f32 y, f32 z, f32 r) {
  struct fldTest_FLDRUN_EFFTBL_t_array_array *fldRunEffTbl_All;
  fldTest_FLDRUN_EFFTBL_t_array *v14;
  s64 v15;
  fldTest_FLDRUN_EFFTBL_t_o *v17;
  struct fldTest_FLDRUN_EFF_t_o *pEff;
  f32 d_c_dir;
  Il2CppObject *pD3P;
  Il2CppObject *pData;

  pData = 0;
  pD3P = 0;
  v14 = fldRunEffTbl_All->m_Items[id];
  v15 = 0;
  if (!LODWORD(v14->max_length))
  {
LABEL_11:
  }
  while (1)
  {
    v17 = v14->m_Items[v15];
    pEff = v17->pEff;
    if (!pEff)
      break;
    d_c_dir = fldRun_Dante->d_c_dir;
    if (d_c_dir <= v17->off_cam_range_min)
      goto LABEL_10;
    else if (d_c_dir < v17->off_cam_range_max)
    {
      goto LABEL_20;
    }
LABEL_10:
    if (++v15 >= LODWORD(v14->max_length))
      goto LABEL_11;
  }
}

// 0x1784200
void fldRunEffTask(void) {
  s64 v2;
  u64 v4;
  struct fldTest_FLDRUN_EFFTBL_t_array_array *fldRunEffTbl_All;
  fldTest_FLDRUN_EFFTBL_t_array *v7;
  s64 v8;
  fldTest_FLDRUN_EFFTBL_t_o *v10;
  struct fldTest_FLDRUN_EFF_t_o *pEff;
  s32 cnt;
  s64 v14;
  s64 v15;
  f32 r;
  f32 v18;
  effHandle_t_o *d3p;
  s64 v23;
  s64 v24;
  f32 v26;
  f32 v27;
  UnityEngine_Matrix4x4_o v29;
  UnityEngine_Matrix4x4_o v30;
  UnityEngine_Matrix4x4_o v31;
  Il2CppObject *v32;
  UnityEngine_Matrix4x4_o aMatrix;
  s64 v34;
  s64 v35;
  Il2CppObject *pData;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o v38;

  v34 = 0;
  v35 = 0;
  pData = 0;
  v32 = 0;
  sub_854690(&v34, 0.0, 0.0, 0.0, 1.0);
  v2 = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  do
  {
    v4 = v2;
    v7 = fldRunEffTbl_All->m_Items[v4];
    v8 = 0;
    if (!LODWORD(v7->max_length))
    {
LABEL_12:
    }
    while (1)
    {
      v10 = v7->m_Items[v8];
      pEff = v10->pEff;
      if (!pEff)
        break;
      if (v10->effmode)
      {
        if (pEff->pcf)
        {
          cnt = pEff->cnt;
          if (cnt < 0)
          {
            dds3EffectPartDelete(&pEff->pcf);
            pEff->pcf = 0;
            goto LABEL_11;
          }
          pEff->cnt = cnt - 1;
          sub_854930(&v34, 0);
          sub_854930(&v34, 1u);
          sub_854930(&v34, 2u);
          v14 = v34;
          v15 = v35;
          *&v37.x = v14;
          *&v37.z = v15;
          dds3EffectPartSetPosition(&pEff->pcf, v37);
          if (v10->rotmode == 1)
          {
            r = pEff->r;
            v18 = ((90.0 - r) * 3.14) / 180.0;
            SetRotateMatrixY(v18);
            SDF_VU0__STOREMATRIX(&aMatrix);
            v31 = aMatrix;
            v29 = v31;
            dds3EffectPartSetRotateMatrix(&pEff->pcf, &v29);
          }
          dds3EffectPartDraw(&pEff->pcf);
          if (++v8 >= LODWORD(v7->max_length))
            goto LABEL_12;
        }
        else
        {
LABEL_11:
          if (++v8 >= LODWORD(v7->max_length))
            goto LABEL_12;
        }
      }
      else
      {
        d3p = pEff->d3p;
        if (!d3p)
          goto LABEL_11;
        if (dds3EffectGetState(d3p))
        {
          sub_854930(&v34, 0);
          sub_854930(&v34, 1u);
          sub_854930(&v34, 2u);
          pData = pEff->d3p;
          v23 = v34;
          v24 = v35;
          *&v38.x = v23;
          *&v38.z = v24;
          dds3EffectSetPosition(&pData, v38);
          if (v10->rotmode == 1)
          {
            v26 = pEff->r;
            v27 = ((90.0 - v26) * 3.14) / 180.0;
            SetRotateMatrixY(v27);
            SDF_VU0__STOREMATRIX(&aMatrix);
            pData = pEff->d3p;
            v31 = aMatrix;
            v30 = v31;
            dds3EffectSetRotateMatrix(&pData, &v30);
          }
          pData = pEff->d3p;
          dds3EffectDraw(&pData);
          if (++v8 >= LODWORD(v7->max_length))
            goto LABEL_12;
        }
        else
        {
          v32 = pEff->d3p;
          dds3EffectDelete(&v32);
          pEff->d3p = 0;
          if (++v8 >= LODWORD(v7->max_length))
            goto LABEL_12;
        }
      }
    }
    v2 = 1;
  }
  while (!v4);
}

// 0x178d270
s32 fldRunEncountChk(void) {
  bool v3;
  s32 result;
  f32 kakudo;
  f32 len;

  len = 0.0;
  kakudo = 0.0;
  v3 = evtBitCheck(2803);
  result = 0;
  if (v3)
  {
    else if ((fldRun_Dante->update_flag & 1) == 0)
    {
LABEL_7:
      fldRunGetLenKakudo(&len, &kakudo);
      return len < 250.0;
    }
    return 0;
  }
  return result;
}

// 0x1786d40
f32 fldRunGetHokanKakudo(f32 now, f32 goal, f32 s, f32 min) {
  f32 v10;
  f32 v11;

  v10 = R360_LR(now, goal);
  v11 = v10 / s;
  if ((v10 / s) < 0.0)
    v11 = -(v10 / s);
  if (v11 < min)
    v11 = min;
  if ((v10 < 0.0 || v10 > v11) && (v10 > 0.0 || v10 < -v11))
  {
    if (v10 >= 0.0)
      return v11 + now;
    else
      return now - v11;
  }
  return goal;
}

// 0x177fa30
void fldRunGetLenKakudo(f32 *len, f32 *kakudo) {
  struct fldGlobalWork_t_o *fldGb;
  f32 playerX;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  f32 v10;
  f32 v11;
  f32 v13;
  f32 v14;
  f32 v16;

  playerX = fldGb->playerX;
  v10 = playerX - fldRun_Dante->x;
  v11 = fldGb->playerZ - fldRun_Dante->z;
  v13 = sdfSqrt((v10 * v10) + (v11 * v11), 0);
  if (v13 >= 1.0)
  {
    v16 = sdfAtan2(v10, v11);
    v14 = (v16 * 180.0) / 3.14;
  }
  else
  {
    v14 = 0.0;
  }
  *len = v13;
  *kakudo = v14;
}

// 0x1786bf0
void fldRunGetLenKakudo2(f32 fx, f32 fz, f32 *len, f32 *kakudo) {
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  f32 v11;
  f32 v12;
  f32 v14;
  f32 v15;
  f32 v17;

  v11 = fx - fldRun_Dante->x;
  v12 = fz - fldRun_Dante->z;
  v14 = sdfSqrt((v11 * v11) + (v12 * v12), 0);
  if (v14 >= 1.0)
  {
    v17 = sdfAtan2(v11, v12);
    v15 = (v17 * 180.0) / 3.14;
  }
  else
  {
    v15 = 0.0;
  }
  *len = v14;
  *kakudo = v15;
}

// 0x1783200
void fldRunInit(void) {
  fldRun_Dante->old_status = -1;
}

// 0x178c0e0
void fldRunSoundLoad(void) {
  System_String_o *v2;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v5;

  v2 = "b_bgm11";
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, v2))
  {
    v5 = get_asset_bc();
    Load(v5, v2, v2, 0);
  }
}

// 0x1783c90
void fldRunTamaFree(void) {
  struct fldTest_FLDRUN_EFFTBL_t_array_array *fldRunEffTbl_All;
  fldTest_FLDRUN_EFFTBL_t_array *v4;
  s64 v5;
  fldTest_FLDRUN_EFFTBL_t_o *v7;
  struct fldTest_FLDRUN_EFF_t_o *pEff;
  struct fldTest_FLDRUN_EFFTBL_t_array_array *v10;
  fldTest_FLDRUN_EFFTBL_t_array *v12;
  s64 v13;
  fldTest_FLDRUN_EFFTBL_t_o *v15;
  struct fldTest_FLDRUN_EFF_t_o *v16;
  Il2CppObject *pData;

  pData = 0;
  else
  {
    if (!LODWORD(fldRunEffTbl_All->max_length))
      goto LABEL_6;
  }
  v4 = fldRunEffTbl_All->m_Items[0];
  v5 = 0;
  if (!LODWORD(v4->max_length))
  {
LABEL_10:
  }
  while (1)
  {
    v7 = v4->m_Items[v5];
    pEff = v7->pEff;
    if (!pEff)
      break;
    if (v7->effmode)
    {
      if (pEff->pcf)
      {
        dds3EffectPartDelete(&pEff->pcf);
        pEff->pcf = 0;
        if (!pEff->mhFile)
          goto LABEL_9;
LABEL_25:
        pEff->mhFile = 0;
        goto LABEL_9;
      }
    }
    else if (pEff->d3p)
    {
      pData = pEff->d3p;
      dds3EffectDelete(&pData);
      pEff->d3p = 0;
    }
    if (pEff->mhFile)
      goto LABEL_25;
LABEL_9:
    if (++v5 >= LODWORD(v4->max_length))
      goto LABEL_10;
  }
  v10 = fldRunEffTbl_All;
  v12 = v10->m_Items[1];
  v13 = 0;
  if (!LODWORD(v12->max_length))
  {
LABEL_34:
  }
  while (2)
  {
    v15 = v12->m_Items[v13];
    v16 = v15->pEff;
    if (v16)
    {
      if (v15->effmode)
      {
        if (v16->pcf)
        {
          dds3EffectPartDelete(&v16->pcf);
          v16->pcf = 0;
          if (!v16->mhFile)
          {
LABEL_33:
            if (++v13 >= LODWORD(v12->max_length))
              goto LABEL_34;
            continue;
          }
LABEL_49:
          v16->mhFile = 0;
          goto LABEL_33;
        }
      }
      else if (v16->d3p)
      {
        pData = v16->d3p;
        dds3EffectDelete(&pData);
        v16->d3p = 0;
      }
      if (!v16->mhFile)
        goto LABEL_33;
      goto LABEL_49;
    }
    break;
  }
}

// 0x1783270
void fldRunTamaInit(void) {
  u64 *v1;
  u32 v4;
  s64 v6;
  s64 v7;
  u32 v8;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  dds3Basic_t_o *v14;
  u32 v16;
  struct dds3Basic_t_o *v17;
  u32 v19;
  struct dds3Basic_t_o *v20;
  struct UnityEngine_Texture_array *v22;
  struct fldTest_FLDRUN_EFF_t_o *fldRunEff_DSPARK01_PCF;
  AssetBundleCtrl_o *asset_bc;
  struct fldTest_FLDRUN_EFF_t_o *fldRunEff_DSMOKE2_D3P;
  AssetBundleCtrl_o *v28;
  struct fldTest_FLDRUN_EFF_t_o *fldRunEff_DSPARK02_D3P;
  AssetBundleCtrl_o *v30;
  struct fldTest_FLDRUN_EFF_t_o *fldRunEff_GUN02A_D3P;
  AssetBundleCtrl_o *v32;
  struct UnityEngine_Texture_array *fldRunEff_Tex;
  AssetBundleCtrl_o *v34;
  s64 *File;
  s64 *v36;
  s64 v37;
  s64 typeHierarchyDepth;
  char *v39;
  s64 *v40;
  s64 v42;
  s64 v43;
  char *v44;
  s64 *v45;
  struct fldTest_FLDRUN_EFF_t_o *fldRunEff_GUN01A0_D3P;
  AssetBundleCtrl_o *v48;
  struct UnityEngine_Texture_array *v49;
  AssetBundleCtrl_o *v50;
  s64 *v51;
  s64 *v52;
  s64 v53;
  s64 v54;
  char *v55;
  s64 *v56;
  s64 v58;
  s64 v59;
  char *v60;
  s64 *v61;
  struct fldTest_FLDRUN_EFF_t_o *fldRunEff_MUZZLE_B010_PCF;
  AssetBundleCtrl_o *v64;
  struct fldTest_FLDRUN_EFF_t_o *fldRunEff_DSMOKE1_D3P;
  AssetBundleCtrl_o *v66;
  struct fldTest_FLDRUN_EFF_t_o *fldRunEff_DFLASH1_PCF;
  AssetBundleCtrl_o *v68;
  UnityEngine_Texture_array *v70;
  UnityEngine_Vector4_o v71;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v73;
  u64 v74[2];
  char *v75;
  UnityEngine_Vector4_o v76;
  UnityEngine_Vector4_o v77;

  *&v73.x = 0;
  *&v73.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&v73.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  *&v71.x = 0;
  *&v71.z = 0;
  sub_854690(&v71.x, 0.0, 1.0, 0.0, 1.0);
  v1 = Allocate(fldTest_FLDRUN_EFF_t);
  _ctor(v1);
  SDF_VU0__LOADVECTOR(v71);
  FromRotation(3.1416);
  SDF_VU0__LOADVECTOR_B(p);
  Mult();
  SDF_VU0__STOREVECTOR(&p);
  v4 = dds3SerializeID();
  v6 = *&v73.x;
  v7 = *&v73.z;
  v8 = v4;
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  *&v76.x = v6;
  *&v76.z = v7;
  v77.x = x;
  v77.y = y;
  v77.z = z;
  v77.w = w;
  v14 = dds3AddUnitObjectBasic(v8, v76, v77);
  fldBasic_tama1 = v14;
  dds3SetBasicName(&fldBasic_tama1, "TAMA1_UNIT");
  dds3ObjectBaseMakeUnit(&fldBasic_tama1, 2, 17);
  dds3ObjectBaseOnFlag(&fldBasic_tama1, 1u, 0);
  dds3ObjectBaseOnFlag(&fldBasic_tama1, 0x100u, 0);
  v16 = dds3SerializeID();
  v17 = dds3AddUnitObjectBasic(v16, v73, p);
  fldBasic_tama2 = v17;
  dds3SetBasicName(&fldBasic_tama2, "TAMA2_UNIT");
  dds3ObjectBaseMakeUnit(&fldBasic_tama2, 2, 18);
  dds3ObjectBaseOnFlag(&fldBasic_tama2, 1u, 0);
  dds3ObjectBaseOnFlag(&fldBasic_tama2, 0x100u, 0);
  v19 = dds3SerializeID();
  v20 = dds3AddUnitObjectBasic(v19, v73, p);
  fldBasic_tama3 = v20;
  dds3SetBasicName(&fldBasic_tama3, "TAMA3_UNIT");
  dds3ObjectBaseMakeUnit(&fldBasic_tama3, 2, 19);
  dds3ObjectBaseOnFlag(&fldBasic_tama3, 1u, 0);
  dds3ObjectBaseOnFlag(&fldBasic_tama3, 0x100u, 0);
  v22 = NewSpecific(UnityEngine_Texture, 2u);
  fldRunEff_Tex = v22;
  fldRunEff_DSPARK01_PCF->size = 0;
  fldRunEff_DSPARK01_PCF->mhFile = 0;
  fldRunEff_DSPARK01_PCF->ptr = 0;
  *&fldRunEff_DSPARK01_PCF->cnt = 0;
  *&fldRunEff_DSPARK01_PCF->y = 0;
  fldRunEff_DSPARK01_PCF->pcf = 0;
  fldRunEff_DSPARK01_PCF->d3p = 0;
  asset_bc = get_asset_bc();
  fldRunEff_DSPARK01_PCF->ptr = LoadFileByte(asset_bc, "common", "dds3data/fld/f/bin/DSPARK01.PCF.bytes");
  fldRunEff_DSMOKE2_D3P->size = 0;
  fldRunEff_DSMOKE2_D3P->mhFile = 0;
  fldRunEff_DSMOKE2_D3P->ptr = 0;
  fldRunEff_DSMOKE2_D3P->r = 0.0;
  *&fldRunEff_DSMOKE2_D3P->cnt = 0;
  *&fldRunEff_DSMOKE2_D3P->y = 0;
  fldRunEff_DSMOKE2_D3P->pcf = 0;
  fldRunEff_DSMOKE2_D3P->d3p = 0;
  v28 = get_asset_bc();
  fldRunEff_DSMOKE2_D3P->ptr = LoadFileByte(v28, "common", "dds3data/fld/f/bin/DSMOKE2.D3P.bytes");
  fldRunEff_DSPARK02_D3P->size = 0;
  fldRunEff_DSPARK02_D3P->mhFile = 0;
  fldRunEff_DSPARK02_D3P->ptr = 0;
  fldRunEff_DSPARK02_D3P->r = 0.0;
  *&fldRunEff_DSPARK02_D3P->cnt = 0;
  *&fldRunEff_DSPARK02_D3P->y = 0;
  fldRunEff_DSPARK02_D3P->pcf = 0;
  fldRunEff_DSPARK02_D3P->d3p = 0;
  v30 = get_asset_bc();
  fldRunEff_DSPARK02_D3P->ptr = LoadFileByte(v30, "common", "dds3data/fld/f/bin/DSPARK02.D3P.bytes");
  fldRunEff_GUN02A_D3P->size = 0;
  fldRunEff_GUN02A_D3P->mhFile = 0;
  fldRunEff_GUN02A_D3P->ptr = 0;
  fldRunEff_GUN02A_D3P->r = 0.0;
  *&fldRunEff_GUN02A_D3P->cnt = 0;
  *&fldRunEff_GUN02A_D3P->y = 0;
  fldRunEff_GUN02A_D3P->pcf = 0;
  fldRunEff_GUN02A_D3P->d3p = 0;
  v32 = get_asset_bc();
  fldRunEff_GUN02A_D3P->ptr = LoadFileByte(v32, "common", "dds3data/fld/f/bin/GUN02A.D3P.bytes");
  v34 = get_asset_bc();
  File = LoadFile(v34, "common", "dds3data/fld/f/bin", "GUN02A.D3P", ".png");
  v36 = File;
  if (File)
  {
    v37 = *File;
    if (*(*File + 288) < typeHierarchyDepth
      || *(*(v37 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Texture)
    {
      sub_8FC2C0(*(v37 + 64), UnityEngine_Texture, v74);
      if ((v74[0] & 1) != 0)
        v39 = v75;
      else
        v39 = v74 + 1;
      v40 = sub_8C4940(v39);
    }
    v42 = *v36;
    if (*(*v36 + 288) < v43 || *(*(v42 + 200) + 8 * v43 - 8) != UnityEngine_Texture)
    {
      sub_8FC2C0(*(v42 + 64), UnityEngine_Texture, v74);
      if ((v74[0] & 1) != 0)
        v44 = v75;
      else
        v44 = v74 + 1;
      v45 = sub_8C4940(v44);
    }
  }
  fldRunEff_Tex->m_Items[0] = v36;
  fldRunEff_GUN01A0_D3P->size = 0;
  fldRunEff_GUN01A0_D3P->mhFile = 0;
  fldRunEff_GUN01A0_D3P->ptr = 0;
  fldRunEff_GUN01A0_D3P->r = 0.0;
  *&fldRunEff_GUN01A0_D3P->cnt = 0;
  *&fldRunEff_GUN01A0_D3P->y = 0;
  fldRunEff_GUN01A0_D3P->pcf = 0;
  fldRunEff_GUN01A0_D3P->d3p = 0;
  v48 = get_asset_bc();
  fldRunEff_GUN01A0_D3P->ptr = LoadFileByte(v48, "common", "dds3data/fld/f/bin/GUN01A0.D3P.bytes");
  v49 = fldRunEff_Tex;
  v50 = get_asset_bc();
  v51 = LoadFile(v50, "common", "dds3data/fld/f/bin", "GUN01A0", ".png");
  v52 = v51;
  if (v51)
  {
    v53 = *v51;
    if (*(*v51 + 288) < v54 || *(*(v53 + 200) + 8 * v54 - 8) != UnityEngine_Texture)
    {
      sub_8FC2C0(*(v53 + 64), UnityEngine_Texture, v74);
      if ((v74[0] & 1) != 0)
        v55 = v75;
      else
        v55 = v74 + 1;
      v56 = sub_8C4940(v55);
    }
    v58 = *v52;
    if (*(*v52 + 288) < v59 || *(*(v58 + 200) + 8 * v59 - 8) != UnityEngine_Texture)
    {
      sub_8FC2C0(*(v58 + 64), UnityEngine_Texture, v74);
      if ((v74[0] & 1) != 0)
        v60 = v75;
      else
        v60 = v74 + 1;
      v61 = sub_8C4940(v60);
    }
  }
  v49->m_Items[1] = v52;
  fldRunEff_MUZZLE_B010_PCF->size = 0;
  fldRunEff_MUZZLE_B010_PCF->mhFile = 0;
  fldRunEff_MUZZLE_B010_PCF->ptr = 0;
  fldRunEff_MUZZLE_B010_PCF->r = 0.0;
  *&fldRunEff_MUZZLE_B010_PCF->cnt = 0;
  *&fldRunEff_MUZZLE_B010_PCF->y = 0;
  fldRunEff_MUZZLE_B010_PCF->pcf = 0;
  fldRunEff_MUZZLE_B010_PCF->d3p = 0;
  v64 = get_asset_bc();
  fldRunEff_MUZZLE_B010_PCF->ptr = LoadFileByte(v64, "common", "dds3data/fld/f/bin/MUZZLE_B010.PCF.bytes");
  fldRunEff_DSMOKE1_D3P->size = 0;
  fldRunEff_DSMOKE1_D3P->mhFile = 0;
  fldRunEff_DSMOKE1_D3P->ptr = 0;
  fldRunEff_DSMOKE1_D3P->r = 0.0;
  *&fldRunEff_DSMOKE1_D3P->cnt = 0;
  *&fldRunEff_DSMOKE1_D3P->y = 0;
  fldRunEff_DSMOKE1_D3P->pcf = 0;
  fldRunEff_DSMOKE1_D3P->d3p = 0;
  v66 = get_asset_bc();
  fldRunEff_DSMOKE1_D3P->ptr = LoadFileByte(v66, "common", "dds3data/fld/f/bin/DSMOKE1.D3P.bytes");
  fldRunEff_DFLASH1_PCF->size = 0;
  fldRunEff_DFLASH1_PCF->mhFile = 0;
  fldRunEff_DFLASH1_PCF->ptr = 0;
  fldRunEff_DFLASH1_PCF->r = 0.0;
  *&fldRunEff_DFLASH1_PCF->cnt = 0;
  *&fldRunEff_DFLASH1_PCF->y = 0;
  fldRunEff_DFLASH1_PCF->pcf = 0;
  fldRunEff_DFLASH1_PCF->d3p = 0;
  v68 = get_asset_bc();
  fldRunEff_DFLASH1_PCF->ptr = LoadFileByte(v68, "common", "dds3data/fld/f/bin/DFLASH1.PCF.bytes");
  v70 = fldRunEff_Tex;
  billSetTexture(v70);
}

// 0x1784780
void fldRunTamaSe(void) {
  u64 *v1;
  u64 *v2;
  u64 *v3;
  u64 *v4;
  System_Array_o *v5;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  f32 MotionFrame;
  f32 v17;
  s64 v18;
  f32 v21;
  f32 v25;
  f32 v27;
  f32 v31;
  f32 v34;
  f32 v37;
  f32 v39;
  f32 v43;
  f32 v46;
  f32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v53;
  s32 v55;
  s32 v57;
  Il2CppObject *v59;
  Il2CppClass *v61;
  s64 v62;
  char *v63;
  s64 *v64;
  f32 v66;
  f32 v67;
  s64 v70;
  f32 v72;
  f32 v76;
  f32 v78;
  f32 v82;
  f32 v85;
  f32 v88;
  f32 v90;
  f32 v94;
  f32 v97;
  f32 v99;
  f32 v100;
  f32 v101;
  f32 v102;
  f32 v104;
  s32 v106;
  s32 v108;
  Il2CppObject *v110;
  Il2CppClass *v112;
  s64 v113;
  char *v114;
  s64 *v115;
  f32 v117;
  f32 v118;
  s64 v121;
  f32 v123;
  f32 v127;
  f32 v129;
  f32 v133;
  f32 v136;
  f32 v139;
  f32 v141;
  f32 v145;
  f32 v148;
  f32 v150;
  f32 v151;
  f32 v152;
  f32 v153;
  f32 v155;
  s32 v157;
  s32 v159;
  UnityEngine_Vector4_o p;
  u64 v161[2];
  char *v162;
  dds3ModelHandle_t_o *aHandle;

  *&p.x = 0;
  *&p.z = 0;
  v1 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v1);
  aHandle = v1;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  v2 = NewSpecific(f32, 0xAu);
  InitializeArray_1543888(v2, Field__PrivateImplementationDetails__37023762F847A50137B4980B12E1A1862B81EA5E);
  v3 = NewSpecific(f32, 0xAu);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__B34A6DAF33C3CCB153119F920FC93C89D1EB02D2);
  v4 = NewSpecific(f32, 0xAu);
  InitializeArray_1543888(v4, Field__PrivateImplementationDetails__3D83287C9CBD638F78A9F44865484ADBD39BBADD);
  v5 = NewSpecific(s16, 0xAu);
  InitializeArray_1543888(v5, Field__PrivateImplementationDetails__0C1919BF254E8182200058256A269C85C3D4AABC);
  ModelHandle = dds3ObjectBaseGetModelHandle(&fldBasic_tama1);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v161);
      if ((v161[0] & 1) != 0)
        v12 = v162;
      else
        v12 = v161 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  aHandle = ModelHandle;
  MotionFrame = mdlGetMotionFrame(&aHandle);
  v17 = *(v2 + 8);
  if ((v17 + -0.5) < MotionFrame)
  {
    if ((v17 + 0.5) > MotionFrame)
    {
      v18 = 0;
        goto LABEL_22;
LABEL_96:
      dds3GetPosPoseSet(&fldBasic_tama1);
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&p, 0);
      v49 = v48;
      sub_854710(&p, 1u);
      v51 = v50;
      sub_854710(&p, 2u);
      v55 = fldRunVolCalc(v49, v51, v53);
      v57 = v55 * *(&v5[2].klass + v18);
      p2sdPlaySE_Vol_20173952("F058_06", v57 / 256);
      goto LABEL_105;
    }
  }
  v21 = *(v2 + 9);
  if ((v21 + -0.5) < MotionFrame)
  {
    if ((v21 + 0.5) > MotionFrame)
    {
      v18 = 1;
        goto LABEL_96;
      goto LABEL_22;
    }
  }
  v25 = *(v2 + 10);
  if ((v25 + -0.5) < MotionFrame)
  {
    if ((v25 + 0.5) > MotionFrame)
    {
      v18 = 2;
        goto LABEL_96;
      goto LABEL_22;
    }
  }
  v27 = *(v2 + 11);
  if ((v27 + -0.5) < MotionFrame)
  {
    if ((v27 + 0.5) > MotionFrame)
    {
      v18 = 3;
        goto LABEL_96;
      goto LABEL_22;
    }
  }
  v31 = *(v2 + 12);
  if ((v31 + -0.5) < MotionFrame)
  {
    if ((v31 + 0.5) > MotionFrame)
    {
      v18 = 4;
        goto LABEL_96;
      goto LABEL_22;
    }
  }
  v34 = *(v2 + 13);
  if ((v34 + -0.5) < MotionFrame)
  {
    if ((v34 + 0.5) > MotionFrame)
    {
      v18 = 5;
        goto LABEL_96;
      goto LABEL_22;
    }
  }
  v37 = *(v2 + 14);
  if ((v37 + -0.5) < MotionFrame)
  {
    if ((v37 + 0.5) > MotionFrame)
    {
      v18 = 6;
        goto LABEL_96;
      goto LABEL_22;
    }
  }
  v39 = *(v2 + 15);
  if ((v39 + -0.5) < MotionFrame)
  {
    if ((v39 + 0.5) > MotionFrame)
    {
      v18 = 7;
        goto LABEL_96;
      goto LABEL_22;
    }
  }
  v43 = *(v2 + 16);
  if ((v43 + -0.5) < MotionFrame)
  {
    if ((v43 + 0.5) > MotionFrame)
    {
      v18 = 8;
        goto LABEL_96;
LABEL_22:
      goto LABEL_96;
    }
  }
  v46 = *(v2 + 17);
  if ((v46 + -0.5) < MotionFrame)
  {
    if ((v46 + 0.5) > MotionFrame)
    {
      v18 = 9;
        goto LABEL_96;
      goto LABEL_22;
    }
  }
LABEL_105:
  v59 = dds3ObjectBaseGetModelHandle(&fldBasic_tama2);
  if (v59)
  {
    v61 = v59->klass;
    if (v59->klass->_2.typeHierarchyDepth < v62 || v61->_2.typeHierarchy[v62 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v61->_1.element_class, dds3ModelHandle_t, v161);
      if ((v161[0] & 1) != 0)
        v63 = v162;
      else
        v63 = v161 + 1;
      v64 = sub_8C4940(v63);
    }
  }
  aHandle = v59;
  v66 = mdlGetMotionFrame(&aHandle);
  v67 = *(v3 + 8);
  if ((v67 + -0.5) < v66)
  {
    if ((v67 + 0.5) > v66)
    {
      v70 = 0;
        goto LABEL_199;
      goto LABEL_126;
    }
  }
  v72 = *(v3 + 9);
  if ((v72 + -0.5) < v66)
  {
    if ((v72 + 0.5) > v66)
    {
      v70 = 1;
        goto LABEL_199;
LABEL_126:
      goto LABEL_199;
    }
  }
  v76 = *(v3 + 10);
  if ((v76 + -0.5) < v66)
  {
    if ((v76 + 0.5) > v66)
    {
      v70 = 2;
        goto LABEL_126;
      goto LABEL_199;
    }
  }
  v78 = *(v3 + 11);
  if ((v78 + -0.5) < v66)
  {
    if ((v78 + 0.5) > v66)
    {
      v70 = 3;
        goto LABEL_126;
      goto LABEL_199;
    }
  }
  v82 = *(v3 + 12);
  if ((v82 + -0.5) < v66)
  {
    if ((v82 + 0.5) > v66)
    {
      v70 = 4;
        goto LABEL_126;
      goto LABEL_199;
    }
  }
  v85 = *(v3 + 13);
  if ((v85 + -0.5) < v66)
  {
    if ((v85 + 0.5) > v66)
    {
      v70 = 5;
        goto LABEL_126;
      goto LABEL_199;
    }
  }
  v88 = *(v3 + 14);
  if ((v88 + -0.5) < v66)
  {
    if ((v88 + 0.5) > v66)
    {
      v70 = 6;
        goto LABEL_126;
      goto LABEL_199;
    }
  }
  v90 = *(v3 + 15);
  if ((v90 + -0.5) < v66)
  {
    if ((v90 + 0.5) > v66)
    {
      v70 = 7;
        goto LABEL_126;
      goto LABEL_199;
    }
  }
  v94 = *(v3 + 16);
  if ((v94 + -0.5) < v66)
  {
    if ((v94 + 0.5) > v66)
    {
      v70 = 8;
        goto LABEL_126;
LABEL_199:
      dds3GetPosPoseSet(&fldBasic_tama2);
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&p, 0);
      v100 = v99;
      sub_854710(&p, 1u);
      v102 = v101;
      sub_854710(&p, 2u);
      v106 = fldRunVolCalc(v100, v102, v104);
      v108 = v106 * *(&v5[2].klass + v70);
      p2sdPlaySE_Vol_20173952("F058_06", v108 / 256);
      goto LABEL_208;
    }
  }
  v97 = *(v3 + 17);
  if ((v97 + -0.5) < v66)
  {
    if ((v97 + 0.5) > v66)
    {
      v70 = 9;
        goto LABEL_199;
      goto LABEL_126;
    }
  }
LABEL_208:
  v110 = dds3ObjectBaseGetModelHandle(&fldBasic_tama3);
  if (v110)
  {
    v112 = v110->klass;
    if (v110->klass->_2.typeHierarchyDepth < v113
      || v112->_2.typeHierarchy[v113 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v112->_1.element_class, dds3ModelHandle_t, v161);
      if ((v161[0] & 1) != 0)
        v114 = v162;
      else
        v114 = v161 + 1;
      v115 = sub_8C4940(v114);
    }
  }
  aHandle = v110;
  v117 = mdlGetMotionFrame(&aHandle);
  v118 = *(v4 + 8);
  if ((v118 + -0.5) < v117)
  {
    if ((v118 + 0.5) > v117)
    {
      v121 = 0;
        goto LABEL_302;
      goto LABEL_229;
    }
  }
  v123 = *(v4 + 9);
  if ((v123 + -0.5) < v117)
  {
    if ((v123 + 0.5) > v117)
    {
      v121 = 1;
        goto LABEL_302;
LABEL_229:
      goto LABEL_302;
    }
  }
  v127 = *(v4 + 10);
  if ((v127 + -0.5) < v117)
  {
    if ((v127 + 0.5) > v117)
    {
      v121 = 2;
        goto LABEL_229;
      goto LABEL_302;
    }
  }
  v129 = *(v4 + 11);
  if ((v129 + -0.5) < v117)
  {
    if ((v129 + 0.5) > v117)
    {
      v121 = 3;
        goto LABEL_229;
      goto LABEL_302;
    }
  }
  v133 = *(v4 + 12);
  if ((v133 + -0.5) < v117)
  {
    if ((v133 + 0.5) > v117)
    {
      v121 = 4;
        goto LABEL_229;
      goto LABEL_302;
    }
  }
  v136 = *(v4 + 13);
  if ((v136 + -0.5) < v117)
  {
    if ((v136 + 0.5) > v117)
    {
      v121 = 5;
        goto LABEL_229;
      goto LABEL_302;
    }
  }
  v139 = *(v4 + 14);
  if ((v139 + -0.5) < v117)
  {
    if ((v139 + 0.5) > v117)
    {
      v121 = 6;
        goto LABEL_229;
      goto LABEL_302;
    }
  }
  v141 = *(v4 + 15);
  if ((v141 + -0.5) < v117)
  {
    if ((v141 + 0.5) > v117)
    {
      v121 = 7;
        goto LABEL_229;
      goto LABEL_302;
    }
  }
  v145 = *(v4 + 16);
  if ((v145 + -0.5) < v117)
  {
    if ((v145 + 0.5) > v117)
    {
      v121 = 8;
        goto LABEL_229;
LABEL_302:
      dds3GetPosPoseSet(&fldBasic_tama3);
      SDF_VU0__STOREVECTOR(&p);
      sub_854710(&p, 0);
      v151 = v150;
      sub_854710(&p, 1u);
      v153 = v152;
      sub_854710(&p, 2u);
      v157 = fldRunVolCalc(v151, v153, v155);
      v159 = v157 * *(&v5[2].klass + v121);
      p2sdPlaySE_Vol_20173952("F058_06", v159 / 256);
      return;
    }
  }
  v148 = *(v4 + 17);
  if ((v148 + -0.5) < v117)
  {
    if ((v148 + 0.5) > v117)
    {
      v121 = 9;
        goto LABEL_302;
      goto LABEL_229;
    }
  }
}

// 0x177fbc0
void fldRunTamaSet(f32 x, f32 y, f32 z, f32 r) {
  u64 *v6;
  s32 fldRunTamaSet_flip_cnt;
  Il2CppObject *v11;
  Il2CppClass *v13;
  s64 v14;
  char *v15;
  s64 *v16;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  dds3Basic_t_o **p_fldBasic_tama1;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v27;
  s64 *v28;
  f32 v30;
  f32 v31;
  f32 w;
  f32 v33;
  Il2CppObject *v34;
  Il2CppClass *v36;
  s64 v37;
  char *v38;
  s64 *v39;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  dds3ModelHandle_t_o *v46;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o v49;
  char *v50;
  UnityEngine_Vector4_o v51;
  UnityEngine_Vector4_o v52;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;

  *&v48.x = 0;
  *&v48.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&v48.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  *&v49.x = 0;
  *&v49.z = 0;
  sub_854690(&v49.x, 0.0, 1.0, 0.0, 1.0);
  v6 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v6);
  v46 = v6;
  sub_854930(&v48, 0);
  sub_854930(&v48, 1u);
  sub_854930(&v48, 2u);
  SDF_VU0__LOADVECTOR(v49);
  FromRotation((r * 3.14) / 180.0, 0);
  SDF_VU0__STOREVECTOR(&p);
  switch (fldRunTamaSet_flip_cnt)
  {
    case 0:
      dds3ObjectBaseOffFlag(&fldBasic_tama1, 1u);
      ModelHandle = dds3ObjectBaseGetModelHandle(&fldBasic_tama1);
      if (ModelHandle)
      {
        klass = ModelHandle->klass;
        if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
        {
          sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, &v49);
          if ((LOBYTE(v49.x) & 1) != 0)
            v27 = v50;
          else
            v27 = &v49.x + 1;
          v28 = sub_8C4940(v27);
        }
      }
      v46 = ModelHandle;
      mdlSingleMotion(&v46, 0, 0);
      v31 = p.x;
      v30 = p.y;
      v33 = p.z;
      w = p.w;
      v53.x = v31;
      v53.y = v30;
      v53.z = v33;
      v53.w = w;
      dds3SetRotPoseSet(&fldBasic_tama1, v53);
      v52 = v48;
      p_fldBasic_tama1 = &fldBasic_tama1;
      goto LABEL_60;
    case 1:
      dds3ObjectBaseOffFlag(&fldBasic_tama2, 1u);
      v34 = dds3ObjectBaseGetModelHandle(&fldBasic_tama2);
      if (v34)
      {
        v36 = v34->klass;
        if (v34->klass->_2.typeHierarchyDepth < v37
          || v36->_2.typeHierarchy[v37 - 1] != dds3ModelHandle_t)
        {
          sub_8FC2C0(v36->_1.element_class, dds3ModelHandle_t, &v49);
          if ((LOBYTE(v49.x) & 1) != 0)
            v38 = v50;
          else
            v38 = &v49.x + 1;
          v39 = sub_8C4940(v38);
        }
      }
      v46 = v34;
      mdlSingleMotion(&v46, 0, 0);
      v42 = p.x;
      v41 = p.y;
      v44 = p.z;
      v43 = p.w;
      v54.x = v42;
      v54.y = v41;
      v54.z = v44;
      v54.w = v43;
      dds3SetRotPoseSet(&fldBasic_tama2, v54);
      v52 = v48;
      p_fldBasic_tama1 = &fldBasic_tama2;
      goto LABEL_60;
    case 2:
      dds3ObjectBaseOffFlag(&fldBasic_tama3, 1u);
      v11 = dds3ObjectBaseGetModelHandle(&fldBasic_tama3);
      if (v11)
      {
        v13 = v11->klass;
        if (v11->klass->_2.typeHierarchyDepth < v14
          || v13->_2.typeHierarchy[v14 - 1] != dds3ModelHandle_t)
        {
          sub_8FC2C0(v13->_1.element_class, dds3ModelHandle_t, &v49);
          if ((LOBYTE(v49.x) & 1) != 0)
            v15 = v50;
          else
            v15 = &v49.x + 1;
          v16 = sub_8C4940(v15);
        }
      }
      v46 = v11;
      mdlSingleMotion(&v46, 0, 0);
      v19 = p.x;
      v18 = p.y;
      v21 = p.z;
      v20 = p.w;
      v51.x = v19;
      v51.y = v18;
      v51.z = v21;
      v51.w = v20;
      dds3SetRotPoseSet(&fldBasic_tama3, v51);
      v52 = v48;
      p_fldBasic_tama1 = &fldBasic_tama3;
LABEL_60:
      dds3SetPosPoseSet(p_fldBasic_tama1, v52);
      break;
  }
  ++fldRunTamaSet_flip_cnt;
  fldRunTamaSet_flip_cnt %= 3;
}

// 0x178d040
void fldRunView(void) {
  UnityEngine_Object_o *gameObject;

  if (player3 && evtBitCheck(2803))
  {
    if (bFirstStance)
    {
      bFirstStance = 0;
    }
    if (evtBitCheck(2804))
    {
      if (fldProcCheckFlag(0x40u))
      {
        gameObject = player3->gameObject;
        if (op_Inequality(gameObject, 0, 0))
        {
          fldRunDanteCollision();
          fldRunDanteAi();
        }
        fldRunDanteSetModel();
        fldRunDanteSe();
        fldRunEffTask();
        fldRunTamaSe();
        FroFtoI(fldGb->playerX, fldGb->playerZ, &fldRun_Player->ix, &fldRun_Player->iz);
        fldRun_Dante->backup_ix = fldRun_Dante->ix;
        fldRun_Dante->backup_iz = fldRun_Dante->iz;
      }
    }
  }
}

// 0x177e590
s32 fldRunVolCalc(f32 x, f32 y, f32 z) {
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v14;
  f32 v15;
  f32 v16;
  s32 v17;
  s32 v18;

  sub_854710(&g_cameraPos, 0);
  v10 = v9;
  sub_854710(&g_cameraPos, 1u);
  v12 = v11 - y;
  sub_854710(&g_cameraPos, 2u);
  v15 = v14 - z;
  v16 = v10 - x;
  v17 = 127
      * (7000 - fmaxf(fminf(sdfSqrt(((v16 * v16) + (v12 * v12)) + (v15 * v15), 0) + -500.0, 7000.0), 0.0));
  if (v17 > 895999)
    v18 = 127;
  else
    v18 = v17 / 7000;
  return v18 & ~(v18 >> 31);
}

// 0x177c360
void fldSdwDraw(dds3Basic_t *pObjectBasic) {
  u64 *v2;
  u64 *v3;
  s32 fieldID;
  s32 v7;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  fldGlobal_c *v16;
  u64 *v17;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  f32 v21;
  s64 p_NowLightDir;
  f32 v23;
  struct dds3PoseSet_t_o *v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  Il2CppObject *workdata;
  Il2CppClass *v38;
  s64 v39;
  fldTest_c *v40;
  struct fldTest_StaticFields **p_static_fields;
  u32 v44;
  dds3Basic_t_o *v46;
  sdfModelRootNode_t_o *modelRoot;
  f32 v52;
  f32 v53;
  struct dds3PoseSet_t_o *v54;
  f32 v55;
  f32 v56;
  f32 v58;
  f32 v59;
  dds3Basic_t_o *v60;
  s32 v63;
  s16 v65;
  s32 v66;
  s32 v67;
  f32 v71;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 v78;
  f32 v79;
  f32 v81;
  struct UnityEngine_Vector4_o *v83;
  s64 p_fldSdwDraw_lightv;
  struct UnityEngine_Vector4_o *v85;
  f32 x;
  f32 v89;
  struct dds3PoseSet_t_o *poseset;
  f32 z;
  f32 v92;
  f32 v93;
  f32 v94;
  f32 v96;
  f32 v97;
  f32 v98;
  f32 v100;
  dds3Basic_t_o *v101;
  s32 fldSdwDraw_srgba;
  f32 PShadow_Alp;
  struct sdf3DLight_t_array *dds3DirLights;
  struct sdf3DLight_t_array *v111;
  struct sdf3DLight_t_array *v113;
  f32 v115;
  struct dds3KernelDraw_StaticFields **v116;
  struct dds3KernelDraw_StaticFields *v118;
  f32 v119;
  dds3Basic_t_o *v120;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v123;
  s32 areaID;
  s32 v126;
  s32 v128;
  s32 v130;
  s32 v132;
  UnityEngine_Object_o *fldPlayerObj;
  s32 v138;
  struct sdf3DLight_t_array *fld_player_lights;
  struct sdf3DLight_t_array *v145;
  f32 v150;
  f32 v151;
  f32 v152;
  f32 v153;
  f32 v154;
  f32 v155;
  f32 v157;
  f32 v158;
  f32 v160;
  struct UnityEngine_Vector4_o *v162;
  s64 v163;
  struct UnityEngine_Vector4_o *v164;
  s32 v167;
  f32 v168;
  s32 v169;
  s32 v170;
  f32 v172;
  f32 v173;
  struct dds3PoseSet_t_o *v174;
  f32 v175;
  f32 v176;
  f32 v177;
  f32 v178;
  f32 v180;
  f32 v181;
  f32 v183;
  f32 v185;
  dds3Basic_t_o *v186;
  struct UnityEngine_Vector4_o *v187;
  s32 v190;
  s32 v192;
  f32 v195;
  s32 v197;
  char *v199;
  s64 *v200;
  u64 v201[2];
  u64 v202[2];
  u64 v203[2];
  u64 v204[2];
  u64 v205[2];
  dds3Basic_t_o *pBasic;
  s64 v207;
  s64 v208;
  UnityEngine_Vector4_o p;
  u64 v210[2];
  u64 v211[2];
  u64 v212[2];
  dds3Basic_t_o *pObjectBasica;
  u64 v214[2];
  char *v215;

  pObjectBasica = pObjectBasic;
  v212[0] = 0;
  v212[1] = 0;
  v211[0] = 0;
  v211[1] = 0;
  *&p.x = 0;
  *&p.z = 0;
  pBasic = 0;
  v207 = 0;
  v208 = 0;
  v2 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v2);
  sub_854690(v212, 0.0, 0.0, 0.0, 1.0);
  sub_854690(v211, 0.0, 0.0, 0.0, 1.0);
  v214[0] = 0;
  v214[1] = 0;
  sub_854690(v214, 0.0, 0.0, 0.0, 1.0);
  v210[0] = 0;
  v210[1] = 0;
  NewSpecific(UnityEngine_Vector4, 0x11u);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  v205[0] = 0;
  v205[1] = 0;
  sub_854690(v205, 0.0, 0.0, 0.0, 1.0);
  v204[0] = 0;
  v204[1] = 0;
  sub_854690(v204, 0.0, 0.0, 0.0, 1.0);
  v203[0] = 0;
  v203[1] = 0;
  sub_854690(v203, 0.0, 0.0, 0.0, 1.0);
  v202[0] = 0;
  v202[1] = 0;
  sub_854690(v202, 0.0, 0.0, 0.0, 1.0);
  v201[0] = 0;
  v201[1] = 0;
  sub_854690(v201, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v207, 0.0, 0.0, 0.0, 1.0);
  v3 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v3);
  fieldID = fldGb->fieldID;
  if (fieldID == 18)
    goto LABEL_17;
  else if (fieldID == 28)
  {
    goto LABEL_17;
  }
  if (fieldID == 30)
    goto LABEL_17;
LABEL_13:
  v7 = 20;
LABEL_18:
  dds3GetBaseControlWorkData(&pObjectBasica);
  ModelHandle = dds3ObjectBaseGetModelHandle(&pObjectBasica);
  if (ModelHandle)
  {
    klass = ModelHandle->klass;
    if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v214);
      if ((v214[0] & 1) != 0)
        v11 = v215;
      else
        v11 = v214 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  sub_854930(v212, 0);
  sub_854930(v212, 1u);
  sub_854930(v212, 2u);
  sub_854930(v212, 3u);
  sub_854930(v211, 0);
  sub_854930(v211, 1u);
  sub_854930(v211, 2u);
  sub_854930(v211, 3u);
  rsetOtOfs(37);
  if (fldGb->fieldID < 500)
  {
    else if (fldSdwDraw_Skip1)
    {
      goto LABEL_35;
    }
    PShadow_VecClipOnOff = 1.0;
    PShadow_YClipOnOff = 1.0;
    workdata = pObjectBasica->workdata;
    v38 = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < v39
      || v38->_2.typeHierarchy[v39 - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(v38->_1.element_class, dds3UnitObjectBasicWorkData_t, v214);
      if ((v214[0] & 1) != 0)
        v199 = v215;
      else
        v199 = v214 + 1;
      v200 = sub_8C4940(v199);
    }
    if (LODWORD(workdata[3].klass) != -1)
    {
      if (fldSdwDraw_sdwlink)
      {
        pBasic = dds3GetActiveScene();
        v44 = workdata[3].klass;
        v46 = dds3SearchSceneBasic(&pBasic, v44, 9u);
        modelRoot = dds3GetUnitHandleObjectBasic(&pObjectBasica)->Model->modelRoot;
        if (sdfModelGetMarkPosUnity(modelRoot, 0))
        {
          SDF_VU0__STOREVECTOR(&p);
          sub_854710(&p, 0);
          sub_854710(&v46->poseset->pos, 0);
          sub_854930(&fldSdwDraw_lightv, 0);
          sub_854710(&p, 2u);
        }
        else
        {
          sub_854710(&v46->poseset->pos, 0);
          sub_854930(&fldSdwDraw_lightv, 0);
        }
        sub_854710(&v46->poseset->pos, 2u);
        sub_854930(&fldSdwDraw_lightv, 2u);
        sub_854710(&fldSdwDraw_lightv, 0);
        v72 = v71;
        sub_854710(&fldSdwDraw_lightv, 0);
        v74 = v73;
        sub_854710(&fldSdwDraw_lightv, 2u);
        v76 = v75;
        sub_854710(&fldSdwDraw_lightv, 2u);
        v79 = v78;
        v81 = sdfSqrt((v72 * v74) + (v76 * v79), 0);
        if (v81 >= 0.01)
        {
          p_fldSdwDraw_lightv = &fldSdwDraw_lightv;
          sub_854710(p_fldSdwDraw_lightv, 0);
          sub_854930(p_fldSdwDraw_lightv, 0);
          sub_854930(&fldSdwDraw_lightv, 1u);
          v85 = &fldSdwDraw_lightv;
          sub_854710(v85, 2u);
          v83 = v85;
        }
        else
        {
          sub_854930(&fldSdwDraw_lightv, 0);
          sub_854930(&fldSdwDraw_lightv, 1u);
          v83 = &fldSdwDraw_lightv;
        }
        sub_854930(v83, 2u);
        x = pObjectBasica->poseset->pos2.x;
        sub_854710(&fldSdwDraw_lightv, 0);
        *&v207 = (x - (v89 * 80.0)) / 100.0;
        poseset = pObjectBasica->poseset;
        z = poseset->pos2.z;
        *(&v207 + 1) = (poseset->pos2.y + -200.0) / -100.0;
        sub_854710(&fldSdwDraw_lightv, 2u);
        *&v208 = (z - (v92 * 80.0)) / 100.0;
        sub_854710(&fldSdwDraw_lightv, 0);
        v94 = v93;
        sub_854710(&fldSdwDraw_lightv, 2u);
        v97 = v96;
        v98 = (sdfAtan2(v94, v97) * 180.0) / 3.14;
        v100 = *&v207;
        PShadow_CamX = v100;
        PShadow_CamY = *(&v207 + 1);
        LODWORD(PShadow_CamZ) = v208;
        PShadow_RotX = 60.0;
        PShadow_RotY = v98;
        PShadow_CamSize = 1.2;
        PShadow_CamFar = 10.0;
        PShadow_Alp = 0.4;
        PShadow_OnOff = 1.0;
        v101 = pObjectBasica;
        PShadow_ClipX = pObjectBasica->poseset->pos2.x;
        PShadow_ClipZ = v101->poseset->pos2.z;
        PShadow_ClipY = v101->poseset->pos2.y;
        if (fldSdwDraw_srgba <= 47)
        {
          fldSdwDraw_srgba = fldSdwDraw_srgba + 2;
        }
        PShadow_Alp = PShadow_Alp * (fldSdwDraw_srgba / 48.0);
        goto LABEL_185;
      }
      v65 = *&v40->_2.bitflags1;
      if ((v65 & 0x200) != 0)
      {
        v66 = v65 & 0x200;
        v67 = fldSdwDraw_srgba;
        if (v67 <= v7)
        {
LABEL_98:
          fldSdwDraw_sdwlink = 1;
          (*p_static_fields)->fldSdwDraw_srgba = 8;
            goto LABEL_181;
          goto LABEL_179;
        }
      }
      else
      {
        v66 = 0;
        v67 = fldSdwDraw_srgba;
        if (v67 <= v7)
          goto LABEL_98;
      }
      fldSdwDraw_srgba = v67 - 2;
        goto LABEL_181;
LABEL_179:
LABEL_181:
      PShadow_Alp = 0.4;
      v118 = *v116;
      v119 = (*v116)->PShadow_Alp;
      v118->PShadow_Alp = v119 * (fldSdwDraw_srgba / 48.0);
      v120 = pObjectBasica;
      (*v116)->PShadow_ClipX = pObjectBasica->poseset->pos2.x;
      (*v116)->PShadow_ClipZ = v120->poseset->pos2.z;
      (*v116)->PShadow_ClipY = v120->poseset->pos2.y;
      goto LABEL_185;
    }
    if (fldSdwDraw_sdwlink)
    {
      v52 = pObjectBasica->poseset->pos2.x;
      sub_854710(&fldSdwDraw_lightv, 0);
      *&v207 = (v52 - (v53 * 80.0)) / 100.0;
      v54 = pObjectBasica->poseset;
      v55 = v54->pos2.z;
      *(&v207 + 1) = (v54->pos2.y + -200.0) / -100.0;
      sub_854710(&fldSdwDraw_lightv, 2u);
      v58 = (v55 - (v56 * 80.0)) / 100.0;
      *&v208 = v58;
      v59 = *&v207;
      PShadow_CamX = v59;
      PShadow_CamY = *(&v207 + 1);
      PShadow_CamZ = v58;
      PShadow_Alp = 0.4;
      v60 = pObjectBasica;
      PShadow_ClipX = pObjectBasica->poseset->pos2.x;
      PShadow_ClipZ = v60->poseset->pos2.z;
      PShadow_ClipY = v60->poseset->pos2.y;
      v63 = fldSdwDraw_srgba;
      if (v63 <= v7)
      {
        fldSdwDraw_sdwlink = 0;
        fldSdwDraw_srgba = 6;
          goto LABEL_168;
      }
      else
      {
        fldSdwDraw_srgba = v63 - 4;
          goto LABEL_168;
      }
LABEL_168:
      v115 = PShadow_Alp;
      PShadow_Alp = v115 * (fldSdwDraw_srgba / 48.0);
      goto LABEL_185;
    }
    if (fldGb->fieldID <= 199)
    {
      sub_854710(&fld_player_lights->m_Items[0]->v, 0);
      sub_854930(&fldSdwDraw_lightv, 0);
      v145 = fld_player_lights;
      sub_854710(&v145->m_Items[0]->v, 1u);
      sub_854930(&fldSdwDraw_lightv, 1u);
      v113 = fld_player_lights;
      if (!LODWORD(v113->max_length))
      {
LABEL_328:
      }
    }
    else
    {
      sub_854710(&dds3DirLights->m_Items[0]->v, 0);
      sub_854930(&fldSdwDraw_lightv, 0);
      v111 = dds3DirLights;
      sub_854710(&v111->m_Items[0]->v, 1u);
      sub_854930(&fldSdwDraw_lightv, 1u);
      v113 = dds3DirLights;
      if (!LODWORD(v113->max_length))
        goto LABEL_328;
    }
    sub_854710(&v113->m_Items[0]->v, 2u);
    sub_854930(&fldSdwDraw_lightv, 2u);
    sub_854710(&fldSdwDraw_lightv, 0);
    v151 = v150;
    sub_854710(&fldSdwDraw_lightv, 0);
    v153 = v152;
    sub_854710(&fldSdwDraw_lightv, 2u);
    v155 = v154;
    sub_854710(&fldSdwDraw_lightv, 2u);
    v158 = v157;
    v160 = sdfSqrt((v151 * v153) + (v155 * v158), 0);
    if (v160 >= 0.01)
    {
      v163 = &fldSdwDraw_lightv;
      sub_854710(v163, 0);
      sub_854930(v163, 0);
      sub_854930(&fldSdwDraw_lightv, 1u);
      v164 = &fldSdwDraw_lightv;
      sub_854710(v164, 2u);
      v162 = v164;
    }
    else
    {
      sub_854930(&fldSdwDraw_lightv, 0);
      sub_854930(&fldSdwDraw_lightv, 1u);
      v162 = &fldSdwDraw_lightv;
    }
    sub_854930(v162, 2u);
    v167 = fldGb->fieldID;
    if (v167 == 18)
      goto LABEL_356;
    if (v167 == 28)
      goto LABEL_356;
    if (v167 == 30)
    {
LABEL_356:
      v168 = 40.0;
      v169 = 1117126656;
      v170 = 1061997773;
    }
    else
    {
      v168 = 80.0;
      v169 = 1114636288;
      v170 = 1053609165;
    }
    v172 = pObjectBasica->poseset->pos2.x;
    sub_854710(&fldSdwDraw_lightv, 0);
    *&v207 = (v172 - (v173 * v168)) / 100.0;
    v174 = pObjectBasica->poseset;
    v175 = v174->pos2.z;
    *(&v207 + 1) = (v174->pos2.y + -200.0) / -100.0;
    sub_854710(&fldSdwDraw_lightv, 2u);
    *&v208 = (v175 - (v176 * v168)) / 100.0;
    sub_854710(&fldSdwDraw_lightv, 0);
    v178 = v177;
    sub_854710(&fldSdwDraw_lightv, 2u);
    v181 = v180;
    v183 = (sdfAtan2(v178, v181) * 180.0) / 3.14;
    v185 = *&v207;
    PShadow_CamX = v185;
    PShadow_CamY = *(&v207 + 1);
    LODWORD(PShadow_CamZ) = v208;
    LODWORD(PShadow_RotX) = v169;
    PShadow_RotY = v183;
    PShadow_CamSize = 1.2;
    PShadow_CamFar = 10.0;
    LODWORD(PShadow_Alp) = v170;
    PShadow_OnOff = 1.0;
    v186 = pObjectBasica;
    PShadow_ClipX = pObjectBasica->poseset->pos2.x;
    PShadow_ClipZ = v186->poseset->pos2.z;
    PShadow_ClipY = v186->poseset->pos2.y;
    v187 = &fldSdwDraw_lightv;
    sub_854710(v187, 0);
    sub_854930(v187, 0);
    v190 = fldSdwDraw_srgba;
    if (v190 > v7)
    {
      fldSdwDraw_srgba = v190 - 2;
    }
    v192 = fldSdwDraw_srgba;
    if (v192 < v7)
    {
      fldSdwDraw_srgba = v192 + 2;
    }
    v195 = PShadow_Alp;
    PShadow_Alp = v195 * (fldSdwDraw_srgba / 48.0);
    v197 = fldGb->fieldID;
    if (v197 > 9)
    {
LABEL_185:
        goto LABEL_188;
      goto LABEL_186;
    }
    if (v197 == 1)
    {
      PShadow_RotX = 90.0;
      PShadow_RotY = 140.0;
      PShadow_CamSize = 2.0;
      PShadow_Alp = 0.2;
        goto LABEL_188;
    }
    else
    {
      PShadow_RotX = 60.0;
      PShadow_RotY = 15.0;
      PShadow_CamSize = 2.0;
      PShadow_Alp = 0.3;
      {
LABEL_188:
        if (fldGb->fieldID == 19)
        {
          if (fldGb->areaID == 6)
          {
            PShadow_Alp = PShadow_Alp * 1.5;
          }
        }
        v123 = fldGb;
        if (v123->fieldID == 20)
        {
          areaID = v123->areaID;
          if (!areaID)
            goto LABEL_217;
          if (areaID == 1)
            goto LABEL_217;
          if (areaID == 13)
            goto LABEL_217;
          if (areaID == 24)
          {
LABEL_217:
            PShadow_Alp = PShadow_Alp * 0.4;
          }
        }
        v126 = fldGb->fieldID;
        if (v126 != 18)
        {
          else if (v126 == 28)
          {
            goto LABEL_236;
          }
          if (v126 != 30)
          {
            if ((v16->_2.bitflags2 & 2) == 0)
              goto LABEL_240;
            goto LABEL_233;
          }
        }
LABEL_236:
        PShadow_YClipOnOff = PShadow_YClipOnOff * 4.0;
        if ((v16->_2.bitflags2 & 2) == 0)
        {
LABEL_240:
          v128 = fldGb->fieldID;
          if (v128 != 31)
          {
            else if (v128 != 32)
            {
LABEL_244:
              if (v128 != 36)
              {
                if (v128 != 37)
                  goto LABEL_258;
              }
            }
          }
          PShadow_Alp = PShadow_Alp * 1.2;
LABEL_258:
          v130 = fldGb->fieldID;
          if (v130 >= 41)
          {
            if (v130 <= 45)
            {
              PShadow_Alp = PShadow_Alp * 1.3;
              PShadow_ClipY = PShadow_ClipY + 60.0;
            }
          }
          v132 = fldGb->fieldID;
          if (v132 >= 2)
          {
            if (v132 <= 9)
            {
              PShadow_OnOff = 0.0;
            }
          }
          if (op_Inequality(fldPlayerObj, 0, 0))
          {
            if (get_activeSelf(fldPlayerObj))
            {
              v138 = fldGb->fieldID;
              if (v138 >= 12)
              {
                if (v138 != 14)
                {
                  if (GetMotionMinorNum() == 11)
                  {
                    if (fldGb->PlayerMotionFrame >= 37.0)
                    {
                      {
                      }
                      PShadow_OnOff = 0.0;
                    }
                  }
                }
              }
            }
          }
          goto LABEL_313;
        }
LABEL_233:
        goto LABEL_240;
      }
    }
LABEL_186:
    goto LABEL_188;
  }
  v17 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v17);
  UnitHandleObjectBasic = dds3GetUnitHandleObjectBasic(&pObjectBasica);
  if (UnitHandleObjectBasic && (UnitHandleObjectBasic->Flag & 0x40000) != 0)
  {
    v21 = pObjectBasica->poseset->pos.x;
    p_NowLightDir = &UnitHandleObjectBasic->NowLightDir;
    sub_854710(&UnitHandleObjectBasic->NowLightDir, 0);
    *&v207 = (v21 - (v23 * 50.0)) / 100.0;
    v24 = pObjectBasica->poseset;
    v25 = v24->pos.z;
    *(&v207 + 1) = (v24->pos.y + -200.0) / -100.0;
    sub_854710(p_NowLightDir, 2u);
    *&v208 = (v25 - (v26 * 50.0)) / 100.0;
    sub_854710(p_NowLightDir, 0);
    v28 = v27;
    sub_854710(p_NowLightDir, 2u);
    v31 = v30;
    v32 = sdfAtan2(v28, v31);
    v33 = (v32 * 180.0) / 3.14;
    v34 = *&v207;
    PShadow_CamX = v34;
    PShadow_CamY = *(&v207 + 1);
    LODWORD(PShadow_CamZ) = v208;
    PShadow_RotX = 70.0;
    PShadow_RotY = v33;
    PShadow_CamSize = 2.0;
    PShadow_CamFar = 10.0;
    PShadow_Alp = 0.2;
    PShadow_OnOff = 1.0;
    PShadow_ClipY = pObjectBasica->poseset->pos.y;
  }
LABEL_313:
  sub_854930(&fldSdwDraw_lightv, 3u);
  SDF_VU0__LOADVECTOR(fldSdwDraw_lightv);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&fldSdwDraw_lightv);
  sub_854710(&fldSdwDraw_lightv, 0);
  sub_854930(v210, 0);
  sub_854710(&fldSdwDraw_lightv, 1u);
  sub_854930(v210, 1u);
  sub_854710(&fldSdwDraw_lightv, 2u);
  sub_854930(v210, 2u);
  sub_854930(v210, 3u);
  SDF_VU0__LOADVECTOR(fldSdwDraw_lightv);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&fldSdwDraw_lightv);
  fldSdwDraw_Skip1 = 0;
}

// 0x177c2f0
void fldSdwDraw_Skep1(void) {
  fldSdwDraw_Skip1 = 1;
}

// 0x17864f0
void fldTest_FRO_HEAD_t__Set(fldTest_FRO_HEAD_t *this, u8 **ptr, s32 *addr) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *addr;
  this->RouteAddr = ToUInt32(ptr, v7, 0);
  v8 = *addr + 4;
  *addr = v8;
  this->RouteNum = ToUInt32(ptr, v8, 0);
  v9 = *addr + 4;
  *addr = v9;
  this->MapAddr = ToUInt32(ptr, v9, 0);
  v10 = *addr + 4;
  *addr = v10;
  this->Res = ToUInt32(ptr, v10, 0);
  *addr += 4;
}

// 0x17868c0
void fldTest_FRO_MAPDATA_t__Set(fldTest_FRO_MAPDATA_t *this, u8 **ptr, s32 *addr) {
  s64 v4;
  s64 v6;

  v4 = *addr;
  this->link = ptr->m_Items[v4];
  v6 = *addr + 1LL;
  *addr = v6;
  this->res = ptr->m_Items[v6];
  ++*addr;
}

// 0x17867a0
void fldTest_FRO_MAPHEADER_t__Set(fldTest_FRO_MAPHEADER_t *this, u8 **ptr, s32 *addr) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;

  v7 = *addr;
  this->sizex = ToUInt16(ptr, v7);
  v8 = *addr + 2;
  *addr = v8;
  this->sizez = ToUInt16(ptr, v8);
  v9 = *addr + 2;
  *addr = v9;
  this->MapAddr = ToUInt32(ptr, v9, 0);
  v10 = *addr + 4;
  *addr = v10;
  this->MapNum = ToUInt32(ptr, v10, 0);
  v11 = *addr + 4;
  *addr = v11;
  this->res = ToUInt32(ptr, v11, 0);
  *addr += 4;
}

// 0x17865f0
void fldTest_FRO_ROUTEIDX_t__Set(fldTest_FRO_ROUTEIDX_t *this, u8 **ptr, s32 *addr) {
  s64 v7;
  s64 v9;
  s64 v11;
  s64 v13;
  s32 v15;
  s32 v16;
  s32 v17;

  v7 = *addr;
  this->sx = ptr->m_Items[v7];
  v9 = *addr + 1LL;
  *addr = v9;
  this->sz = ptr->m_Items[v9];
  v11 = *addr + 1LL;
  *addr = v11;
  this->gx = ptr->m_Items[v11];
  v13 = *addr + 1LL;
  *addr = v13;
  this->gz = ptr->m_Items[v13];
  v15 = *addr + 1;
  *addr = v15;
  this->flag = ToUInt32(ptr, v15, 0);
  v16 = *addr + 4;
  *addr = v16;
  this->RouteAddr = ToUInt32(ptr, v16, 0);
  v17 = *addr + 4;
  *addr = v17;
  this->RouteNum = ToUInt32(ptr, v17, 0);
  *addr += 4;
}

// 0x1780200
void mdlLoopMotionForUnity(void *obj, char *path, s32 motion) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  struct System_Int32_array *MotionAnimTable;

  if (!op_Equality(obj, 0, 0))
  {
    transform = get_transform(obj, 0);
    Child = GetChild(transform, 0);
    gameObject = get_gameObject(Child);
    Component_object = GetComponent_object_(gameObject);
    if (!op_Equality(Component_object, 0, 0))
    {
      SetInteger(Component_object, path, MotionAnimTable->m_Items[motion]);
    }
  }
}

// 0x177aeb0
void ooyTestDrawMaruKage(f32 x, f32 y, f32 z, f32 r, s32 a) {
  else if (!a)
  {
    return;
  }
}

// 0x177afe0
dds3ProcessFunc_t *ooyTestDrawProc(dds3ProcessID_t *aProcId) {
  s32 v8;

  else if (encChk())
  {
    return 0;
  }
  if (fldProcCampChk() != 1)
  {
    rsetOtOfs(71);
    rsetTest(1, 0, 129, 3, 0, 0, 1, 1);
    rsetAlpha(0);
    fldSkyDrawFilter();
    if (fldDbg->BlurOn)
    {
      if (fldAutoMapChkMode())
      {
        v8 = 81;
      }
      else
      {
        v8 = 71;
      }
      rsetOtOfs(v8);
      fldDrawBokasi();
    }
    rsetOtOfs(39);
    rsetTest(1, 5, 128, 1, 0, 0, 1, 2);
    rsetAlpha(0);
    rsetOtOfs(46);
    rsetTest(1, 5, 128, 1, 0, 0, 1, 2);
    rsetAlpha(0);
  }
  return 0;
}
