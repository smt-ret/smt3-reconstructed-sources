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
static fldTest_FRO_ROUTEIDX_t pFroRouteIdx[UNKNOWN_ARRAY_SIZE];
static u8 pFroRouteData[UNKNOWN_ARRAY_SIZE];
static fldTest_FRO_MAPHEADER_t *pFroMapHead;
static fldTest_FRO_MAPDATA_t pFroMapData[UNKNOWN_ARRAY_SIZE];
static fldTest_FLDRUN_EFFTBL_t *fldRunEffTbl_0[5];
static fldTest_FLDRUN_EFFTBL_t *fldRunEffTbl_1[5];
static fldTest_FLDRUN_EFFTBL_t *fldRunEffTbl_All[UNKNOWN_ARRAY_SIZE];
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
  struct fldTest_StaticFields *static_fields;
  int16x4_t v9;
  f32 v10;
  f32 v11;
  s16 v12;
  s16 v13;
  s16 v14;
  f32 v15;
  s16 v16;
  struct fldTest_StaticFields *v17;
  s32 sizex;
  struct fldTest_FRO_MAPDATA_t_array *pFroMapData;
  s32 v20;
  fldTest_c *v22;
  struct fldTest_StaticFields *v23;
  f32 v24;
  f32 v25;
  f32 v26;

  v5 = fz;
  v6 = fx;
  static_fields = v7->static_fields;
  LOWORD(fx) = static_fields->fldRun_MAP_OX;
  v9.n64_u64[0] = vmovl_s16(*&fx).n128_u64[0];
  v10 = v9.n64_i32[0];
  v9.n64_u16[0] = static_fields->fldRun_MAP_OZ;
  v11 = 10000.0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = vmovl_s16(v9).n128_i32[0];
  while (v14 < pFroMapHead->sizez)
  {
    v16 = 0;
    if ((v7->_2.bitflags2 & 2) == 0)
    while (1)
    {
      v17 = v7->static_fields;
      sizex = v17->pFroMapHead->sizex;
      if (v16 >= sizex)
        break;
      pFroMapData = v17->pFroMapData;
      v20 = v16 + sizex * v14;
      if (pFroMapData->m_Items[v20]->link)
      {
        v23 = v22->static_fields;
        LOWORD(fz) = v23->fldRun_MAP_BX;
        v24 = v5 - ((v14 * -v23->fldRun_MAP_BZ) + v15);
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
    }
    ++v14;
    if ((v7->_2.bitflags2 & 2) != 0)
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
  struct fldTest_FRO_ROUTEIDX_t_array *pFroRouteIdx;
  u64 v11;
  fldTest_FRO_ROUTEIDX_t_o **m_Items;
  u8 *v13;

  v11 = 0;
  m_Items = pFroRouteIdx->m_Items;
  while (v11 < pFroHead->RouteNum)
  {
    v13 = m_Items[v11];
    if (v13[16] == sx && v13[17] == sz && v13[18] == gx && m_Items[v11]->gz == gz)
      return v11;
    ++v11;
  }
  return -1;
}

// 0x1783070
void FroItoF(s16 ix, s16 iz, f32 *fx, f32 *fz) {
  int16x4_t v5;
  int16x4_t v6;
  int16x4_t v7;
  fldTest_c *v12;
  struct fldTest_StaticFields *static_fields;

  static_fields = v12->static_fields;
  v7.n64_u16[0] = static_fields->fldRun_MAP_BX;
  v5.n64_u16[0] = static_fields->fldRun_MAP_OX;
  v6.n64_u16[0] = static_fields->fldRun_MAP_OZ;
  *fx = (ix * vmovl_s16(v7).n128_i32[0]) + vmovl_s16(v5).n128_i32[0];
  *fz = (iz * -fldRun_MAP_BZ) + vmovl_s16(v6).n128_i32[0];
}

// 0x1785d40
void FroLoad(void) {
    fldMakeFilePath(0, 0, 0);
    IsDLCField(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    fldTest_FRO_HEAD_t__Set(0, 0, 0);
    fldTest_FRO_ROUTEIDX_t__Set(0, 0, 0);
    fldTest_FRO_MAPHEADER_t__Set(0, 0, 0);
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
  dds3StartProcess(StringLiteral_16781, 0x2AF8u, 0, 0, v1, 0, 0, 0, 0, 0);
}

// 0x177b350
void KillOoyTest(void) {
  dds3KillProcessName(StringLiteral_16781, 1);
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
    ReleaseManiacsChar();
    billClrTexture(0);
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

  v5 = StringLiteral_416;
  frSetFontDrawOT(0x48u);
  if (floor >= 1001)
  {
    v16 = StringLiteral_5774;
  }
  else
  {
    if (floor >= 0)
      v7 = floor;
    else
      v7 = -floor;
    if (floor < 0)
      v8 = StringLiteral_5758;
    else
      v8 = v5;
    if (v7 - 10 <= 0x59)
    {
      v9 = Substring_5248048(StringLiteral_16782, v7 / 0xAu, 1);
      v8 = Concat_5224608(v8, v9);
    }
    v10 = Substring_5248048(StringLiteral_16782, v7 % 0xA, 1);
    v11 = Concat_5224608(v8, v10);
    v13 = Concat_5224608(v11, StringLiteral_5762);
    v16 = v13;
  }
  SetAreaUI(kernelObject, 1, 0, 0, v16, 0xFFFFFF80);
}

// 0x177b990
void fldElvFloorEnd(void) {
    StopSE_ALL();
    fldCamElvEnd();
}

// 0x177ba90
s32 fldElvFloorEndChk(void) {
  struct fldTest_StaticFields *static_fields;
  s32 gFldElvFloorNow;
  s32 v6;

  else
  {
    static_fields = fldTest->static_fields;
    if (static_fields->gFldElvFloorCancel == 1)
      return 2;
  }
  else if (static_fields->gFldElvFloorAnmCnt == -999)
  {
    return 0;
  }
  static_fields = fldTest->static_fields;
  gFldElvFloorNow = static_fields->gFldElvFloorNow;
  if (gFldElvFloorNow != static_fields->gFldElvFloorTo)
    return 0;
  if (static_fields->gFldElvFloorFrom >= gFldElvFloorNow)
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
  struct fldTest_StaticFields *static_fields;
  s32 gFldElvFloorNow;
  s16 v10;
  s32 v11;
  struct fldTest_StaticFields *v12;
  struct fldTest_StaticFields **p_static_fields;
  s32 gFldElvFloorFrom;
  s32 v17;
  fldTest_c *v18;
  struct fldTest_StaticFields *v19;
  s32 gFldElvFloorTo;
  s16 v21;
  struct fldTest_StaticFields **v22;
  struct fldTest_StaticFields *v23;
  s32 gFldElvFloorAnmCnt;
  s32 v25;

  v6 = fldDoor_ElvTakasaToFloor(from);
  gFldElvFloorNow = v6;
  gFldElvFloorFrom = gFldElvFloorNow;
  gFldElvFloorCancel = 0;
  static_fields = v7->static_fields;
  gFldElvFloorNow = static_fields->gFldElvFloorNow;
  if (gFldElvFloorNow >= 1001)
  {
    static_fields->gFldElvFloorNow = gFldElvFloorNow % 1000;
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
  p_static_fields = &v7->static_fields;
  v12 = v7->static_fields;
  gFldElvFloorFrom = v12->gFldElvFloorFrom;
  if (gFldElvFloorFrom < 1001)
  {
    v12->gFldElvFloorFromR = -999;
  }
  else
  {
    v12->gFldElvFloorFromR = gFldElvFloorFrom;
    (*p_static_fields)->gFldElvFloorFrom %= 1000;
    {
    }
  }
  v17 = fldDoor_ElvTakasaToFloor(to);
  gFldElvFloorTo = v17;
  v19 = v18->static_fields;
  gFldElvFloorTo = v19->gFldElvFloorTo;
  if (gFldElvFloorTo >= 1001)
  {
    v19->gFldElvFloorToR = gFldElvFloorTo;
    gFldElvFloorTo %= 1000;
    v21 = *&v18->_2.bitflags1;
    if (from != to)
    gFldElvFloorAnmCnt = -999;
    if ((v18->_2.bitflags2 & 2) != 0)
  }
  v19->gFldElvFloorToR = -999;
  v21 = *&v18->_2.bitflags1;
  if (from == to)
  gFldElvFloorAnmCnt = 0;
  v22 = &v18->static_fields;
  v23 = v18->static_fields;
  if (v23->gFldElvFloorNow == -999)
    return;
  else
  {
    gFldElvFloorAnmCnt = v23->gFldElvFloorAnmCnt;
    if (gFldElvFloorAnmCnt == -999)
      return;
  }
  v23->gFldElvFloorAnmCnt = gFldElvFloorAnmCnt + 1;
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
    DDS3_PADCHECK_TRIG(0);
    fldElvFloorDraw(0, 0, 0);
}

// 0x1781f30
void fldRunAiCng(s32 stat) {
    dds3GetRandA(0);
    FroFtoI(0, 0, 0, 0);
    FroGetRouteIdx(0, 0, 0, 0);
    GetFroRouteData(0);
    fldHitChkEnemy((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    fldRunGetLenKakudo2(0, 0, 0, 0);
}

// 0x178c1a0
void fldRunCngBgm(s32 mode) {
  s64 *v3;

  if (mode)
  {
    p2sdFadeIn2_20177360(StringLiteral_11803);
    v3 = &StringLiteral_11904;
  }
  else
  {
    p2sdFadeIn2_20177360(StringLiteral_11904);
    v3 = &StringLiteral_11803;
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
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      nextframe = fldRun_Dante->nextframe;
      if (nextframe >= 1)
      {
        fldRun_Dante->nextframe = nextframe - 1;
      }
      break;
    case 2:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fldRunDanteWait(v2);
      break;
    case 3:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fldRunDanteSoba(v2);
      break;
    case 4:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fldRunDantePatr(v2);
      break;
    case 5:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fldRunDantePwak(v2);
      break;
    case 7:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fldRunDanteGun1(v2);
      break;
    case 8:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fldRunDanteGun2(v2);
      break;
    case 9:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fldRunDanteDoin(v2);
      break;
    default:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fldRunDanteMove(v2);
      break;
  }
}

// 0x178acc0
void fldRunDanteCollision(void) {
    fldRunGetLenKakudo(0, 0);
    sdfSqrt(0);
    sdfAtan2(0, 0);
    R360_LR(0, 0);
    fldHitChkEnemy((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3GetRandA(0);
    fldRunAiCng(0);
    fldRunDanteSetModel();
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
    dds3GetControlScene();
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    fldDoor_Start(0);
    sdfSin(0);
    sdfCos(0);
    FroFtoI(0, 0, 0, 0);
}

// 0x178ca20
void fldRunDanteFree(void) {
  fldGlobal_c *v4;
  struct fldGlobal_StaticFields *static_fields;

  v2[2].klass->vtable[0].methodPtr = 0;
  *&v2[2].klass->_2.typeHierarchyDepth = 0;
  *&v2[2].klass->_2.nested_type_count = 0;
  *&v2[2].klass->_2.method_count = 0;
  *&v2[2].klass->_2.flags = 0;
  fldRunTamaFree();
  static_fields = v4->static_fields;
  if (static_fields->fldGb->AreaToArea)
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
    R360_LR(0, 0);
    sdfSin(0);
    sdfCos(0);
    dds3GetRandA(0);
    datPartyDamageFld(0);
    fldRunEffSet(0, 0, 0, 0, 0);
    dds3GetUnitHandleObjectBasic(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    FroFtoI(0, 0, 0, 0);
}

// 0x178a3f0
void fldRunDanteGun2(void) {
    R360_LR(0, 0);
    dds3GetRandA(0);
    datPartyDamageFld(0);
    fldRunEffSet(0, 0, 0, 0, 0);
    dds3GetUnitHandleObjectBasic(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    FroFtoI(0, 0, 0, 0);
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
  struct fldTest_StaticFields *static_fields;
  s16 v15;
  struct fldTest_StaticFields *v16;
  struct fldTest_StaticFields *v17;
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
    case 4:
      fldRun_MAP_OX = 200;
      fldRun_MAP_OZ = 100;
      fldRun_Dante->ix = 7;
      fldRun_Dante->iz = 0;
      fldRun_Player->ix = 3;
      fldRun_Player->iz = 2;
      if ((v13->_2.bitflags2 & 2) != 0)
    case 5:
      fldRun_MAP_OX = 3300;
      static_fields = v13->static_fields;
      v15 = -2100;
    case 7:
      fldRun_MAP_OX = -5250;
      static_fields = v13->static_fields;
      v15 = 4050;
    case 8:
      fldRun_MAP_OX = -3500;
      static_fields = v13->static_fields;
      v15 = -2900;
    case 9:
      fldRun_MAP_OX = 300;
      static_fields = v13->static_fields;
      v15 = 2100;
    case 0xA:
      v15 = -2700;
      fldRun_MAP_OX = -2700;
      static_fields = v13->static_fields;
      static_fields->fldRun_MAP_OZ = v15;
      fldRun_Dante->ix = 0;
      fldRun_Dante->iz = 0;
      if ((v13->_2.bitflags2 & 2) != 0)
    default:
      v16 = v13->static_fields;
      v7.n64_u16[0] = v16->fldRun_MAP_OX;
      v8.n64_u16[0] = v16->fldRun_MAP_OZ;
      v16->fldRun_Dante->now = 0;
      fldRun_Dante->goal = 0;
      fldRun_Dante->nextframe = -20;
      v17 = v13->static_fields;
      v9.n64_u16[0] = v17->fldRun_MAP_BX;
      fldRun_Dante = v17->fldRun_Dante;
      v10.n64_u16[0] = fldRun_Dante->ix;
      v19.n64_u64[0] = vmovl_s16(v9).n128_u64[0];
      v19.n64_f32[0] = v19.n64_i32[0] * vmovl_s16(v10).n128_i32[0];
      fldRun_Dante->x = v19.n64_f32[0] + vmovl_s16(v7).n128_i32[0];
      fldRun_Dante->y = 0.0;
      v20 = v13->static_fields;
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
          case 4:
            v28 = 2;
          case 5:
            v28 = 3;
            fldRunDanteStanceSet(v28, 0);
            evtBitOn(2804);
          case 7:
          case 8:
          case 9:
          case 0xA:
            v27 = 0;
          default:
            v27 = 2;
            fldRunAiCng(v27);
            evtBitOff(2804);
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
        if (!*(v25 + 216))
      }
      fldRunDanteSetModel(v25);
      return;
  }
}

// 0x1787690
void fldRunDanteMove(void) {
    GetFroRouteData(0);
    fldHitChkEnemy((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    fldRunGetLenKakudo2(0, 0, 0, 0);
    sdfSin(0);
    sdfCos(0);
    R360_LR(0, 0);
    fldRunAiCng(0);
    fldRunGetLenKakudo(0, 0);
}

// 0x1786e20
void fldRunDanteNull(void) {
  ;
}

// 0x1789230
void fldRunDantePatr(void) {
    FroFtoI(0, 0, 0, 0);
    FroGetRouteIdx(0, 0, 0, 0);
    GetFroRouteData(0);
    fldHitChkEnemy((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    fldRunGetLenKakudo2(0, 0, 0, 0);
    R360_LR(0, 0);
    sdfSin(0);
    sdfCos(0);
}

// 0x1788070
void fldRunDantePwak(void) {
    GetFroRouteData(0);
    fldHitChkEnemy((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    fldRunGetLenKakudo2(0, 0, 0, 0);
    sdfSin(0);
    sdfCos(0);
    R360_LR(0, 0);
    fldRunAiCng(0);
    fldRunGetLenKakudo(0, 0);
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
  fldTest_c *v12;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  _BOOL4 v14;
  _BOOL4 v15;
  s32 v17;
  System_String_o *v20;
  s32 Id;
  s32 fldRunDanteSe_asise;
  s32 v26;
  u32 RandA;
  struct fldTest_StaticFields *static_fields;
  s32 v29;
  s32 v30;
  System_String_o *v33;
  s32 v34;
  System_String_o *v36;
  struct fldTest_FLDRUN_DANTE_t_o *v37;

  IsDLC = IsDLC();
  v3 = &StringLiteral_1518;
  if (!IsDLC)
    v3 = &StringLiteral_4956;
  v5 = Format(StringLiteral_16803, *v3, 0);
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
    case 1:
      v17 = (fldRun_Dante->update_flag >> 1) & 1;
      if (v9 >= 3.0 && v8 < 3.0 || v9 >= 18.0 && v8 < 18.0)
      if (!v17)
    case 2:
      v14 = v8 < 5.0;
      v15 = v9 >= 5.0;
      if (v9 >= 24.0 && v8 < 24.0)
      if (!v15 || !v14)
      v17 = 0;
      v20 = Concat_5224608(v5, StringLiteral_1525);
      Id = FindId(1, v20);
      p2sdPlaySE_Vol(fldRunDanteSe_asise + Id, v11);
      v26 = fldRunDanteSe_asise;
      RandA = dds3GetRandA(StringLiteral_416);
      fldRunDanteSe_asise = v26 + ((RandA >> 4) & 1) + 1;
      static_fields = v12->static_fields;
      v29 = static_fields->fldRunDanteSe_asise;
      v30 = v29 + 3;
      if (v29 >= 0)
        v30 = static_fields->fldRunDanteSe_asise;
      static_fields->fldRunDanteSe_asise = v29 - (v30 & 0xFFFFFFFC);
      if (v17)
      {
        v33 = Concat_5224608(v5, StringLiteral_4962);
        p2sdPlaySE_Vol_20173952(v33, 30 * v11 / 100);
      }
      else      v34 = 30 * v11 / 100;
      v36 = Concat_5224608(v5, StringLiteral_1529);
      p2sdPlaySE_Vol_20173952(v36, v34);
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
    default:
  }
}

// 0x177e710
void fldRunDanteSetModel(void) {
    fldPlayer3LoadForUnity();
    dds3ObjectBaseGetModelHandle(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3OnPoseSetFlag(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfFabs(0);
    dds3OffPoseSetFlag(0, 0);
    mdlGetMotionMinorNum(0);
    dds3GetUnitHandleObjectBasic(0);
    mdlSetMotionSpeed(0, 0);
    mdlSmoothLoopMotionForUnity(0, 0, 0, 0, 0, 0);
    mdlGetMotionFrameForUnity(0);
    sdfModelGetMarkPosUnity(0, 0);
    ooyTestDrawMaruKage(0, 0, 0, 0, 0);
    fldRunGetLenKakudo(0, 0);
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    aDrawBoxF(0, 0, 0, 0, 0, 0, 0, 0);
    sdfSin(0);
    sdfCos(0);
    fldRunTamaSet(0, 0, 0, 0);
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
  fldTest_c *v21;
  struct fldTest_StaticFields *static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v23;
  f32 z;
  f32 v25;
  fldTest_c *v27;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_StaticFields *v29;
  struct fldTest_FLDRUN_DANTE_t_o *v30;
  s32 FLDRUN_BGM_NML;
  struct fldTest_StaticFields *v33;

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
    static_fields = v21->static_fields;
    v23 = static_fields->fldRun_Dante;
    z = static_fields->fldRun_Dante->z;
    v25 = sdfCos((static_fields->fldRun_Dante->dir * 3.14) / 180.0, 0);
    v23->z = z + (v25 * fldRun_Dante->speed);
  }
  FroFtoI(fldRun_Dante->x, fldRun_Dante->z, &fldRun_Dante->ix, &fldRun_Dante->iz);
  if (d_p_len >= 3600.0)
  {
    p_static_fields = &v27->static_fields;
    v33 = v27->static_fields;
    v30 = v33->fldRun_Dante;
    FLDRUN_BGM_NML = v33->FLDRUN_BGM_NML;
  }
  else
  {
    p_static_fields = &v27->static_fields;
    v29 = v27->static_fields;
    v30 = v29->fldRun_Dante;
    FLDRUN_BGM_NML = v29->FLDRUN_BGM_BTL;
    if (v30->bgm_mode != FLDRUN_BGM_NML)
    {
      v30->bgm_mode = FLDRUN_BGM_NML;
      (*p_static_fields)->fldRun_Dante->update_flag |= 4u;
    }
  }
}

// 0x1780360
void fldRunDanteStanceSet(s32 id, bool recover) {
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    fldRunGetLenKakudo(0, 0);
    evtBitCheck(0);
    fldRunAiCng(0);
    fldRunDanteSetModel();
    fldGetRestoreMode();
    FroFtoI(0, 0, 0, 0);
    evtBitOff(0);
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
  fldTest_c *v2;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  s32 nextframe;
  struct fldTest_StaticFields **p_static_fields;
  struct fldTest_StaticFields *static_fields;
  struct fldTest_FLDRUN_DANTE_t_o *v7;
  s32 FLDRUN_BGM_NML;

  nextframe = fldRun_Dante->nextframe;
  if (nextframe >= 1)
  {
    fldRun_Dante->nextframe = nextframe - 1;
  }
  p_static_fields = &v2->static_fields;
  static_fields = v2->static_fields;
  v7 = static_fields->fldRun_Dante;
  FLDRUN_BGM_NML = static_fields->FLDRUN_BGM_NML;
  if (v7->bgm_mode != FLDRUN_BGM_NML)
  {
    v7->bgm_mode = FLDRUN_BGM_NML;
    (*p_static_fields)->fldRun_Dante->update_flag |= 4u;
  }
}

// 0x1783f40
void fldRunEffSet(s32 id, f32 x, f32 y, f32 z, f32 r) {
    dds3EffectPartDelete(0);
    dds3EffectPartCreate(0, 0);
    dds3EffectDelete(0);
    dds3EffectLoad(0, 0, 0);
}

// 0x1784200
void fldRunEffTask(void) {
    dds3EffectPartDelete(0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    SetRotateMatrixY(0);
    SDF_VU0__STOREMATRIX(0);
    dds3EffectPartSetRotateMatrix(0, 0);
    dds3EffectPartDraw(0);
    dds3EffectGetState(0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    dds3EffectSetRotateMatrix(0, 0);
    dds3EffectDraw(0);
    dds3EffectDelete(0);
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

  v2 = StringLiteral_16750;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, v2))
  {
    v5 = get_asset_bc();
    Load(v5, v2, v2, 0);
  }
}

// 0x1783c90
void fldRunTamaFree(void) {
    dds3EffectPartDelete(0);
    dds3EffectDelete(0);
}

// 0x1783270
void fldRunTamaInit(void) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    SDF_VU0__STOREVECTOR(0);
    dds3SerializeID();
    dds3AddUnitObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    dds3ObjectBaseMakeUnit(0, 0, 0);
    dds3ObjectBaseOnFlag(0, 0, 0);
    LoadFileByte(0, 0, 0);
    LoadFile(0, 0, 0, 0, 0);
    billSetTexture(0);
}

// 0x1784780
void fldRunTamaSe(void) {
    dds3ObjectBaseGetModelHandle(0);
    mdlGetMotionFrame(0);
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    fldRunVolCalc(0, 0, 0);
    p2sdPlaySE_Vol_20173952(0, 0);
}

// 0x177fbc0
void fldRunTamaSet(f32 x, f32 y, f32 z, f32 r) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    FromRotation(0);
    SDF_VU0__STOREVECTOR(0);
    dds3ObjectBaseOffFlag(0, 0);
    dds3ObjectBaseGetModelHandle(0);
    mdlSingleMotion(0, 0, 0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
}

// 0x178d040
void fldRunView(void) {
  fldTest_c *v4;
  struct fldTest_StaticFields *static_fields;
  UnityEngine_Object_o *gameObject;

  if (player3 && evtBitCheck(2803))
  {
    static_fields = v4->static_fields;
    if (static_fields->bFirstStance)
    {
      static_fields->bFirstStance = 0;
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
    sdfSqrt(0);
    return 0;
}

// 0x177c360
void fldSdwDraw(dds3Basic_t *pObjectBasic) {
    dds3GetBaseControlWorkData(0);
    dds3ObjectBaseGetModelHandle(0);
    rsetOtOfs(0);
    dds3GetActiveScene();
    dds3SearchSceneBasic(0, 0, 0);
    dds3GetUnitHandleObjectBasic(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    sdfSqrt(0);
    sdfAtan2(0, 0);
    GetMotionMinorNum();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__NORMALIZE();
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
