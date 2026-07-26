#include "types.h"

typedef struct AMAP_MK_t AMAP_MK_t;
typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct DLCAmIcon_t DLCAmIcon_t;
typedef struct FldNameData FldNameData;
typedef struct _FRQ _FRQ;
typedef struct autoMapUI autoMapUI;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct fldAmAreaData_t fldAmAreaData_t;
typedef struct fldAmFileHeader2_t fldAmFileHeader2_t;
typedef struct fldAmIcon_t fldAmIcon_t;
typedef struct fldAmMdl_t fldAmMdl_t;
typedef struct fldAmSBlock_t fldAmSBlock_t;
typedef struct fldAmXYZ_t fldAmXYZ_t;
typedef struct fldAutoMap_childIcon fldAutoMap_childIcon;
typedef struct sdf3DScreenParam_t sdf3DScreenParam_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelNode_t sdfModelNode_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct fldAutoMap_childIcon {
    void *iconObj;
    void *childObj;
};

static void mapNodeList1Area[UNKNOWN_ARRAY_SIZE];
static void *mapNodeList2Area[UNKNOWN_ARRAY_SIZE];
static void mapNodeList1Half[UNKNOWN_ARRAY_SIZE];
static void *mapNodeList2Half[UNKNOWN_ARRAY_SIZE];
static void *cameraMainObj;
static void *cameraAutoRealObj;
static void *cameraAutoHalfObj;
static void *_cameraMain;
static void *_cameraAutoReal;
static void *_cameraAutoHalf;
static void *_autoMapObj;
static autoMapUI *_autoMapUI;
static void _autoMapIconTbl[UNKNOWN_ARRAY_SIZE];
static void *_autoMapIconFld;
static f32 fldAutoMapDrawIconOfsRF_alpcnt;
static s32 gAmap_NowField;
static s32 gAmap_NowArea;
static s32 gAmap_NowFloor;
static s32 gAmap_OfsX;
static s32 gAmap_OfsZ;
static s32 gAmap_InX;
static s32 gAmap_InZ;
static s32 gAmap_Cnt;
static s32 gAmap_InFloor;
static sdfTexHandle_t *gFldAmTex_Icon[2];
static sdfTexHandle_t *gFldAmTex_Bg[3];
static s32 AutoMapResetFlg;
static s32 AutoMapSeq;
static s32 AutoMapGuidFlg;
static sdfVector4_t AMapCameraTPos;
static sdfVector4_t AMapCameraTPosOld;
static sdfModelRootNode_t *pfldAmRootNode[32];
static f32 *gfldAmPos[32];
static fldAmAreaData_t pfldAmArea[UNKNOWN_ARRAY_SIZE];
static s32 nfldAmArea;
static sdfMemHandle_t *mhfldAmFile;
static AMAP_MK_t *amap_mktbl[16];
static s16 am_fldSL;
static s16 am_areaSL[41];
static s16 am_floorSL[41];
static s16 am_spcSL[32];
static s32 dbgfull;
static _FRQ *fldAutoMapDrawOneArea_handle;
static s32 fldAutoMapDrawOneArea_floor;
static s32 fldAutoMapDrawOneArea_ofloor;
static f32 fldAutoMapDrawOneArea_oy;
static f32 fldAutoMapDrawOneArea_ooy;
static s32 fldAutoMapDrawOneArea_nalp;
static s32 fldAutoMapDrawOneArea_iny;
static s32 fldAutoMapDrawOneArea_ioy;
static f32 fldAutoMapDrawOneArea_scrcntf;
static f32 fldAutoMapDrawOneArea_jointcntf;
static f32 fldAutoMapDrawOneArea_npccntf;
static DLCAmIcon_t *DLCAmIcon[4];
static f32 fldAutoMapDrawWindow_bg3sin;
static f32 gFldAreaNameCnt;
static s32 fldDrawAreaBlockFont_pm_mode;
static u32 *AutoMapOpenTbl[38];

void AutoMapDispOff(dds3DefaultMain *this);
void AutoMapDispOn(dds3DefaultMain *this);
void ButtonGuideDispOn(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
bool DDS3_ANALOGCHECK_PRESS(s32 id);
bool DDS3_ANALOGCHECK_REP(s32 id);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
char *GetAreaName(FldNameData *this, s32 fld, s32 area);
void *GetAutoMapCameraHalf(dds3DefaultMain *this);
void *GetAutoMapCameraReal(dds3DefaultMain *this);
void *GetAutoMapObj(dds3DefaultMain *this);
char *GetBasyoName(s32 fieldID, s32 nameU, s32 nameD);
char *GetFieldName(FldNameData *this, s32 fld);
char *GetFloorName(FldNameData *this, s32 fld, s32 floor);
char *GetLocalizeText(char *ID);
void *GetMainCamera(dds3DefaultMain *this);
char *GetStringToByte(u8 **pData, s32 addr);
void InversMatrix(void);
bool IsDLCField(s32 area);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
f32 OOYRAD(f32 a);
char *RepColTag(char *txt, void **LegacyParamArray);
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void SetAreaUI(dds3DefaultMain *this, bool disp, s32 x, s32 y, char *text, u32 rgba);
void SetRotateMatrixY(f32 aAngle);
fldAmAreaData_t **SetfldAmAreaData(u8 **pData, s32 addr, u32 size);
fldAmIcon_t **SetfldAmIcon(u8 **pData, s32 addr, u32 size);
fldAmMdl_t *SetfldAmMdl(u8 **pData, s32 addr);
fldAmSBlock_t **SetfldAmSBlock(u8 **pData, s32 addr, u32 size);
fldAmXYZ_t *SetfldAmXYZ(u8 **pData, s32 addr);
sdfModelDef_t *SetsdfModelDef(u8 **pData, s32 addr, bool set);
void aDrawBoxF(s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 a);
void aDrawBoxG(s32 x, s32 y, s32 w, s32 h, s32 r0, s32 g0, s32 b0, s32 a0, s32 r1, s32 g1, s32 b1, s32 a1, s32 r2, s32 g2, s32 b2, s32 a2, s32 r3, s32 g3, s32 b3, s32 a3);
void aDrawBoxGF(f32 x, f32 y, f32 w, f32 h, s32 r0, s32 g0, s32 b0, s32 a0, s32 r1, s32 g1, s32 b1, s32 a1, s32 r2, s32 g2, s32 b2, s32 a2, s32 r3, s32 g3, s32 b3, s32 a3);
bool autoMapOpenCheck(s32 fieldID);
void dds3FadeIn2(u32 frame);
void dds3FadeOut2(u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible);
void deleteFldMenuSub(s32 second);
bool evtBitCheck(s32 no);
void evtDisableMoonDraw(void);
void evtEnableMoonDraw(void);
fldAmFileHeader2_t *fldAddressResolverAMB(u8 **pData);
void fldAllIconDel(void);
void fldAllIconLoad(void);
void fldAllIconScale(f32 scale);
void fldAmModelLoadFile(void);
s32 fldAreaNameGetIdx(s32 fld, s32 area);
void fldAutoMapAllOpenCheck(void);
void fldAutoMapCalc(void);
bool fldAutoMapChkChild(void *childObj, s32 num1, s32 num2, s32 num3);
s32 fldAutoMapChkOpen(s32 fld, s32 area, s32 block);
void fldAutoMapDrawFloor(sdfModelRootNode_t *root_node, void **obj, s32 nodeidx);
void fldAutoMapDrawIconOfsRF(f32 x, f32 y, s32 tex, f32 r);
void fldAutoMapDrawIconOfsRForUnity(s32 tex, s32 AmArea, s32 nodeIdx, s32 loop2, s32 loop3);
void fldAutoMapDrawMdl1(sdfModelRootNode_t *modelRoot, f32 x, f32 y, f32 z);
void fldAutoMapDrawOneArea(void);
void fldAutoMapFontInit(s32 bank);
void fldAutoMapFree(void);
void fldAutoMapGetAreaPos(s32 area, f32 *getX, f32 *getZ);
void fldAutoMapGetBBox(f32 *getX0, f32 *getZ0, f32 *getX1, f32 *getZ1);
void *fldAutoMapGetChild(void *parentObj, char *name1, char *name2, s32 num1, s32 num2, s32 num3);
s32 fldAutoMapGetFloorMax(void);
s32 fldAutoMapGetFloorNext(s32 floor);
s32 fldAutoMapGetFloorPrev(s32 floor);
void fldAutoMapNodeSet(sdfModelRootNode_t *root_node, s32 nodeidx, s32 mode);
void fldAutoMapOpenBlock2(s32 fld, s32 area, s32 SBlock);
void fldAutoMapOpenCheck(void);
void fldAutoMapSeqEnd(void);
s32 fldAutoMap_GetFloor(s32 area, s32 block);
s32 fldBasyoNameGetIdx(s32 fld, s32 basyo);
s32 fldChkVortex(void);
void fldDbgPrintStr2DC(s32 x, s32 y, s32 col, char *str, s32 second);
sdfGrOt_t *fldDrawGetOt(void);
s32 fldFloorNameGetIdx(s32 fld, s32 floor);
void fldMakeFilePath(char **pathstr, s32 field, s32 area);
sdfVector3_t fldPoint3DTo2DPlayer(void *camera3D, void *camera2D, sdfVector3_t pos3D);
void fldPoint3To2H(f32 x3, f32 y3, f32 z3, f32 *x2, f32 *y2);
s8 fldProcCheckFlag(u32 flag);
void fldRegistUnitPad(void);
void fldReleaseUnitPad(void);
s8 fldSeqCheckFlag(u32 flag);
void fldSeqOffFlag(u32 flag);
void fldSeqOnFlag(u32 flag);
void fldSetupButtonGuide(void);
void frSetFontDrawOT(u32 OtType);
void ooyTestRGBMaskOff(void);
void ooyTestRGBMaskOn(void);
s32 p2sdPlaySE(s32 a);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void *sdf2DLinkTexPacket(sdfDrawTag_t *aTag, sdfTexHandle_t *aTexHndl, s32 aCtx);
void sdf3DSetCamera(sdf3DScreenParam_t *aParam, sdfMatrix4_t *aCamera);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
void sdfModelEvalTm(sdfModelRootNode_t **aRoot);
void sdfModelLinkOt(sdfModelOt_t **aOt, sdfModelRootNode_t **aRoot);
sdfModelRootNode_t *sdfModelMakeEarly(sdfModelTexList_t *aTexList, sdfModelDef_t **aModelData);
void sdfModelMakeLocalTm(sdfModelNode_t **aNode);
void sdfModelRootFree(sdfModelRootNode_t **aRoot, s32 aReleaseNodes, s32 aReleaseMatList);
void sdfPrimLinkFt4(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, s32 aX3, s32 aY3, s32 aU3, s32 aV3, u32 aZ, void *aAllocator);
f32 sdfSin(f32 aRadius);
sdfTexHandle_t *sdfTexSet(void *aTex);

// 0xf8e3a0
bool ChangeFloorAnimeEnd(void) {
    return 0;
}

// 0xf8e230
void CheckFloorAnimeEnd(void) {
}

// 0xf8c600
fldAmAreaData_t **SetfldAmAreaData(u8 **pData, s32 addr, u32 size) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 v10;
  u64 *v11;
  Il2CppObject *v13;
  s32 v17;
  s32 v18;
  s32 v19;
  s64 v21;
  s32 v22;
  s64 v24;
  s32 v25;
  s32 v28;
  s64 v30;
  s32 v31;
  s32 v32;
  s64 v36;
  fldAmSBlock_t_array *v37;

  v7 = size;
  v8 = NewSpecific(fldAmAreaData_t, size);
  v9 = v8;
  if (size)
  {
    v10 = 0;
    v11 = v8 + 8;
    do
    {
      v13 = Allocate(fldAmAreaData_t);
      _ctor(v13, 0);
      v11[v10] = v13;
      v17 = ToInt32(pData, addr, 0);
      v13[1].klass = GetStringToByte(pData, v17);
      v18 = addr + 4;
      v19 = ToInt32(pData, addr + 4, 0);
      v21 = v11[v10];
      v22 = v18 + 4;
      *(v21 + 32) = ToUInt32(pData, v22, 0);
      v24 = v11[v10];
      v25 = v22 + 4;
      v28 = ToInt32(pData, v25, 0);
      *(v24 + 40) = SetfldAmMdl(pData, v28);
      v30 = v11[v10];
      v31 = v25 + 4;
      v32 = ToInt32(pData, v31, 0);
      *(v30 + 48) = SetfldAmXYZ(pData, v32);
      v36 = v11[v10];
      v37 = SetfldAmSBlock(pData, v19, *(v36 + 32));
      ++v10;
      addr = v31 + 4;
      *(v36 + 24) = v37;
    }
    while (v7 != v10);
  }
  return v9;
}

// 0xf8cee0
fldAmIcon_t **SetfldAmIcon(u8 **pData, s32 addr, u32 size) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 *v10;
  u64 v11;
  u64 *v12;
  s64 v17;
  s32 v18;
  s32 v21;

  v7 = size;
  v8 = NewSpecific(fldAmIcon_t, size);
  v9 = v8;
  if (size)
  {
    v10 = v8 + 8;
    v11 = 0;
    do
    {
      v12 = Allocate(fldAmIcon_t);
      _ctor(v12, 0);
      v10[v11] = v12;
      *(v12 + 4) = ToUInt32(pData, addr, 0);
      v17 = v10[v11];
      v18 = addr + 4;
      v21 = ToInt32(pData, v18, 0);
      ++v11;
      addr = v18 + 4;
      *(v17 + 24) = SetfldAmXYZ(pData, v21);
    }
    while (v7 != v11);
  }
  return v9;
}

// 0xf8c900
fldAmMdl_t *SetfldAmMdl(u8 **pData, s32 addr) {
    SetsdfModelDef(0, 0, 0);
    return 0;
}

// 0xf8cad0
fldAmSBlock_t **SetfldAmSBlock(u8 **pData, s32 addr, u32 size) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 v10;
  u64 *v11;
  Il2CppObject *v13;
  s32 v18;
  s64 v20;
  u32 v21;
  s32 v22;
  s32 v23;
  s64 v25;
  s32 v26;
  s64 v29;
  u32 v31;
  s64 v33;
  s32 v34;
  s64 v36;
  s32 v37;
  s32 v40;
  s64 v42;
  s32 v43;

  v7 = size;
  v8 = NewSpecific(fldAmSBlock_t, size);
  v9 = v8;
  if (size)
  {
    v10 = 0;
    v11 = v8 + 8;
    do
    {
      v13 = Allocate(fldAmSBlock_t);
      _ctor(v13, 0);
      v11[v10] = v13;
      v18 = ToInt32(pData, addr, 0);
      v13[1].klass = GetStringToByte(pData, v18);
      v20 = v11[v10];
      v21 = ToUInt32(pData, addr + 4, 0);
      v22 = addr + 8;
      *(v20 + 24) = v21;
      v23 = ToInt32(pData, v22, 0);
      v25 = v11[v10];
      v26 = v22 + 4;
      *(v25 + 40) = ToUInt32(pData, v26, 0);
      v29 = v11[v10];
      if (*(v29 + 40))
      {
        v31 = *(v29 + 40);
        *(v29 + 32) = SetfldAmIcon(pData, v23, v31);
      }
      else
      {
        *(v29 + 32) = 0;
        if (v10 >= v9[6])
      }
      v33 = v11[v10];
      v34 = v26 + 4;
      *(v33 + 44) = ToInt32(pData, v34, 0);
      v36 = v11[v10];
      v37 = v34 + 4;
      v40 = ToInt32(pData, v37, 0);
      *(v36 + 48) = SetfldAmXYZ(pData, v40);
      v42 = v11[v10];
      v43 = ToInt32(pData, v37 + 4, 0);
      ++v10;
      addr = v37 + 8;
      *(v42 + 56) = SetfldAmXYZ(pData, v43);
    }
    while (v7 != v10);
  }
  return v9;
}

// 0xf8ca00
fldAmXYZ_t *SetfldAmXYZ(u8 **pData, s32 addr) {
  u64 *v5;

  v5 = Allocate(fldAmXYZ_t);
  _ctor(v5, 0);
  *(v5 + 4) = ToSingle(pData, addr, 0);
  *(v5 + 5) = ToSingle(pData, addr + 4, 0);
  *(v5 + 6) = ToSingle(pData, addr + 8, 0);
  return v5;
}

// 0xf9a2f0
bool autoMapLengthCheck(s32 fieldID) {
  if (fieldID <= 59)
  {
    return fieldID - 10 < SLODWORD(DDS3_GBWK->GameFileInfo->autoMapOpen->max_length);
  }
  return fieldID - 60 < SLODWORD(DDS3_GBWK->GameFileInfo->autoMapOpenEX->max_length);
}

// 0xf9a1c0
bool autoMapOpenCheck(s32 fieldID) {
  struct System_SByte_array *autoMapOpen;
  s64 v5;
  struct System_SByte_array *autoMapOpenEX;
  s64 v9;

  if (fieldID > 59)
  {
    autoMapOpenEX = DDS3_GBWK->GameFileInfo->autoMapOpenEX;
    v9 = fieldID - 60LL;
    if (autoMapOpenEX->m_Items[v9] == 1)
      return 1;
  }
  else
  {
    autoMapOpen = DDS3_GBWK->GameFileInfo->autoMapOpen;
    v5 = fieldID - 10LL;
    if (autoMapOpen->m_Items[v5] == 1)
      return 1;
  }
  return 0;
}

// 0xf8c500
fldAmFileHeader2_t *fldAddressResolverAMB(u8 **pData) {
  fldAmFileHeader2_t_o *v3;
  s32 pArea;
  u32 nArea;
  u32 nArea_1;

  v3 = Allocate(fldAmFileHeader2_t);
  _ctor(v3, 0);
  v3->pAmInfo = ToUInt32(pData, 20, 0);
  pArea = ToInt32(pData, 24, 0);
  nArea = ToUInt32(pData, 28, 0);
  v3->nArea = nArea;
  nArea_1 = nArea;
  v3->pArea = SetfldAmAreaData(pData, pArea, nArea_1);
  return v3;
}

// 0xf93030
void fldAllIconDel(void) {
}

// 0xf945b0
void fldAllIconLoad(void) {
  struct UnityEngine_GameObject_array *v3;
  struct UnityEngine_GameObject_array *autoMapIconTbl;
  AssetBundleCtrl_o *asset_bc;
  s64 *Prefab_16624656;
  s64 *v10;
  struct UnityEngine_GameObject_array *v12;
  AssetBundleCtrl_o *v13;
  s64 *v14;
  s64 *v15;
  struct UnityEngine_GameObject_array *v18;
  AssetBundleCtrl_o *v19;
  s64 *v20;
  s64 *v21;
  struct UnityEngine_GameObject_array *v24;
  AssetBundleCtrl_o *v25;
  s64 *v26;
  s64 *v27;
  struct UnityEngine_GameObject_array *v30;
  AssetBundleCtrl_o *v31;
  s64 *v32;
  s64 *v33;
  struct UnityEngine_GameObject_array *v36;
  AssetBundleCtrl_o *v37;
  s64 *v38;
  s64 *v39;
  struct UnityEngine_GameObject_array *v42;
  AssetBundleCtrl_o *v43;
  s64 *v44;
  s64 *v45;
  struct UnityEngine_GameObject_array *v48;
  AssetBundleCtrl_o *v49;
  s64 *v50;
  s64 *v51;
  struct UnityEngine_GameObject_array *v54;
  AssetBundleCtrl_o *v55;
  s64 *v56;
  s64 *v57;
  struct UnityEngine_GameObject_array *v60;
  AssetBundleCtrl_o *v61;
  s64 *v62;
  s64 *v63;
  struct UnityEngine_GameObject_array *v66;
  AssetBundleCtrl_o *v67;
  s64 *v68;
  s64 *v69;

  else if (_autoMapIconTbl)
  {
    return;
  }
  v3 = NewSpecific(UnityEngine_GameObject, 0xBu);
  _autoMapIconTbl = v3;
  autoMapIconTbl = _autoMapIconTbl;
  asset_bc = get_asset_bc();
  {
  }
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16563);
  v10 = Prefab_16624656;
  autoMapIconTbl->m_Items[0] = v10;
  v12 = _autoMapIconTbl;
  v13 = get_asset_bc();
  v14 = LoadPrefab_16624656(v13, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16564);
  v15 = v14;
  v12->m_Items[1] = v15;
  v18 = _autoMapIconTbl;
  v19 = get_asset_bc();
  v20 = LoadPrefab_16624656(v19, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16565);
  v21 = v20;
  v18->m_Items[2] = v21;
  v24 = _autoMapIconTbl;
  v25 = get_asset_bc();
  v26 = LoadPrefab_16624656(v25, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16566);
  v27 = v26;
  v24->m_Items[3] = v27;
  v30 = _autoMapIconTbl;
  v31 = get_asset_bc();
  v32 = LoadPrefab_16624656(v31, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16567);
  v33 = v32;
  v30->m_Items[4] = v33;
  v36 = _autoMapIconTbl;
  v37 = get_asset_bc();
  v38 = LoadPrefab_16624656(v37, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16568);
  v39 = v38;
  v36->m_Items[5] = v39;
  v42 = _autoMapIconTbl;
  v43 = get_asset_bc();
  v44 = LoadPrefab_16624656(v43, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16569);
  v45 = v44;
  v42->m_Items[6] = v45;
  v48 = _autoMapIconTbl;
  v49 = get_asset_bc();
  v50 = LoadPrefab_16624656(v49, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16570);
  v51 = v50;
  v48->m_Items[7] = v51;
  v54 = _autoMapIconTbl;
  v55 = get_asset_bc();
  v56 = LoadPrefab_16624656(v55, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16571);
  v57 = v56;
  v54->m_Items[8] = v57;
  v60 = _autoMapIconTbl;
  v61 = get_asset_bc();
  v62 = LoadPrefab_16624656(v61, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16572);
  v63 = v62;
  v60->m_Items[9] = v63;
  v66 = _autoMapIconTbl;
  v67 = get_asset_bc();
  v68 = LoadPrefab_16624656(v67, StringLiteral_4611, AutomapIconFullPath, StringLiteral_16573);
  v69 = v68;
  v66->m_Items[10] = v69;
}

// 0xf94c80
void fldAllIconScale(f32 scale) {
}

// 0xf8d0d0
void fldAmModelLoadFile(void) {
    fldMakeFilePath(0, 0, 0);
    IsDLCField(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    fldAddressResolverAMB(0);
}

// 0xf8d600
void fldAmbLoadFromMem(void *data, sdfMemHandle_t *mh) {
  ;
}

// 0xf9a0d0
void fldAutoMapAllOpenCheck(void) {
  System_Array_o *v1;
  void *monitor;
  u64 v4;
  s32 v6;

  v1 = NewSpecific(s32, 0x23u);
  InitializeArray_1543888(v1, Field__PrivateImplementationDetails__BE321D449706CDF383F9AA9590D34771A797ACEE);
  monitor = v1[1].monitor;
  if (monitor >= 1)
  {
    v4 = 0;
    do
    {
      v6 = *(&v1[2].klass + v4);
      if (autoMapOpenCheck(v6))
        break;
      LODWORD(monitor) = v1[1].monitor;
      ++v4;
    }
    while (v4 < monitor);
  }
}

// 0xf967a0
void fldAutoMapCalc(void) {
    DDS3_PADCHECK_PRESS(0);
    DDS3_PADCHECK_TRIG(0);
    fldAllIconDel();
    fldAutoMapSeqEnd();
    dds3FadeOut2(0);
    dds3FadeIn2(0);
    p2sdPlaySE(0);
    ButtonGuideDispSet(0, 0, 0, 0);
    fldAutoMapOpenCheck();
    DDS3_ANALOGCHECK_PRESS(0);
    DDS3_ANALOGCHECK_REP(0);
    fldAutoMapGetBBox(0, 0, 0, 0);
    fldAllIconScale(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    DDS3_PADCHECK_REP(0);
}

// 0xf94400
bool fldAutoMapChkChild(void *childObj, s32 num1, s32 num2, s32 num3) {
    return 0;
}

// 0xf96730
s32 fldAutoMapChkMode(void) {
  return AutoMapSeq;
}

// 0xf8aa80
s32 fldAutoMapChkOpen(s32 fld, s32 area, s32 block) {
  s32 v7;
  s64 v8;
  struct System_UInt32_array_array *blkOpenFlg;
  Il2CppClass **v12;
  struct System_UInt32_array_array *v14;
  struct fldAutoMapBuffEX_t_o *amapEX_Ver7;
  struct System_UInt32_array_array *v18;
  s64 v19;
  Il2CppClass *v23;

  v7 = fld % 100;
  if (fld % 100 < 10)
    return 0;
  v8 = v7 - 10LL;
  if (block > 31)
  {
    LOBYTE(block) = block - 32;
    if (v8 < 40)
    {
      if (v8 < 30)
      {
        blkOpenFlg = DDS3_GBWK->amap_Ver7->blkOpenFlg;
        v12 = &blkOpenFlg->obj.klass + v8;
      }
      v18 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
      v19 = v7 - 40LL;
      if (v19 < LODWORD(v18->max_length))
    }
    if ((v7 & 0xFFFFFFFE) == 0x3C)
    {
      amapEX_Ver7 = DDS3_GBWK->amapEX_Ver7;
    }
    return 0;
  }
  if (v8 < 40)
  {
    if (v8 >= 30)
    {
      v14 = DDS3_GBWK->amap31->blkOpenFlg;
      v8 = v7 - 40LL;
      if (v8 < LODWORD(v14->max_length))
    }
    else
    {
      v14 = DDS3_GBWK->fldSave->amap->blkOpenFlg;
      if (v8 < LODWORD(v14->max_length))
      {
        v12 = &v14->obj.klass + v8;
      }
    }
  }
  if ((v7 & 0xFFFFFFFE) != 0x3C)
    return 0;
  amapEX_Ver7 = DDS3_GBWK->amapEX;
  v18 = amapEX_Ver7->blkOpenFlg;
  v19 = v7 - 60LL;
  if (v19 >= LODWORD(v18->max_length))
  v12 = &v18->obj.klass + v19;
  v23 = v12[4];
  return (*(&v23->_1.byval_arg.data + area) & (1 << block)) != 0;
}

// 0xf99450
void fldAutoMapClear(void) {
  u64 i;
  u64 j;
  struct System_UInt32_array_array *blkOpenFlg;
  System_UInt32_array *v7;
  s64 v9;
  u64 k;
  u64 m;
  struct System_UInt32_array_array *v13;
  System_UInt32_array *v15;
  s64 v17;
  u64 n;
  struct System_UInt32_array_array *v21;
  System_UInt32_array *v22;
  s64 v24;
  u64 ii;
  struct System_UInt32_array_array *v28;
  System_UInt32_array *v29;
  s64 v31;
  u64 jj;
  u64 kk;
  struct System_UInt32_array_array *v35;
  System_UInt32_array *v37;
  s64 v39;
  u64 mm;
  u64 nn;
  struct System_UInt32_array_array *v43;
  System_UInt32_array *v45;
  s64 v47;
  u64 i1;
  struct System_UInt32_array_array *v51;
  System_UInt32_array *v52;
  s64 v54;
  u64 i2;
  struct System_UInt32_array_array *v58;
  System_UInt32_array *v59;
  s64 v61;

  for (i = 0; i != 30; ++i)
  {
    for (j = 0; j != 32; ++j)
    {
      blkOpenFlg = DDS3_GBWK->fldSave->amap->blkOpenFlg;
      v7 = blkOpenFlg->m_Items[i];
      v9 = v7 + 4 * j;
      *(v9 + 32) = 0;
    }
  }
  for (k = 0; k != 8; ++k)
  {
    for (m = 0; m != 32; ++m)
    {
      v13 = DDS3_GBWK->amap31->blkOpenFlg;
      v15 = v13->m_Items[k];
      v17 = v15 + 4 * m;
      *(v17 + 32) = 0;
    }
  }
  for (n = 0; n != 32; ++n)
  {
    v21 = DDS3_GBWK->amapEX->blkOpenFlg;
    v22 = v21->m_Items[0];
    v24 = v22 + 4 * n;
    *(v24 + 32) = 0;
  }
  for (ii = 0; ii != 32; ++ii)
  {
    v28 = DDS3_GBWK->amapEX->blkOpenFlg;
    v29 = v28->m_Items[1];
    v31 = v29 + 4 * ii;
    *(v31 + 32) = 0;
  }
  for (jj = 0; jj != 30; ++jj)
  {
    for (kk = 0; kk != 32; ++kk)
    {
      v35 = DDS3_GBWK->amap_Ver7->blkOpenFlg;
      v37 = v35->m_Items[jj];
      v39 = v37 + 4 * kk;
      *(v39 + 32) = 0;
    }
  }
  for (mm = 0; mm != 8; ++mm)
  {
    for (nn = 0; nn != 32; ++nn)
    {
      v43 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
      v45 = v43->m_Items[mm];
      v47 = v45 + 4 * nn;
      *(v47 + 32) = 0;
    }
  }
  for (i1 = 0; i1 != 32; ++i1)
  {
    v51 = DDS3_GBWK->amapEX_Ver7->blkOpenFlg;
    v52 = v51->m_Items[0];
    v54 = v52 + 4 * i1;
    *(v54 + 32) = 0;
  }
  for (i2 = 0; i2 != 32; ++i2)
  {
    v58 = DDS3_GBWK->amapEX_Ver7->blkOpenFlg;
    v59 = v58->m_Items[1];
    v61 = v59 + 4 * i2;
    *(v61 + 32) = 0;
  }
}

// 0xf98e00
void fldAutoMapCloseBlock2(s32 fld, s32 area, s32 SBlock) {
  s32 v7;
  char v8;
  s64 v9;
  s64 v10;
  char v11;
  struct System_UInt32_array_array *v13;
  s64 v14;
  struct System_UInt32_array_array *v16;
  Il2CppClass **v18;
  struct System_UInt32_array_array *blkOpenFlg;
  s64 v22;
  System_UInt32_array *v24;
  s64 v26;
  System_UInt32_array *v28;
  s32 v30;
  s32 v31;
  struct System_UInt32_array_array *v32;
  s64 v33;
  Il2CppClass *v35;

  v7 = fld % 100;
  if (fld % 100 >= 10)
  {
    v8 = SBlock - 1;
    v9 = v7 - 10LL;
    v10 = area - 1LL;
    if (SBlock - 1 <= 31)
    {
      if (v9 >= 40)
      {
        if ((v7 & 0xFFFFFFFE) != 0x3C)
          return;
        blkOpenFlg = DDS3_GBWK->amapEX->blkOpenFlg;
        v22 = v7 - 60LL;
        v24 = blkOpenFlg->m_Items[v22];
        v26 = v24 + 4 * v10;
      }
      else
      {
        if (v9 >= 30)
        {
          v32 = DDS3_GBWK->amap31->blkOpenFlg;
          v33 = v7 - 40LL;
          v18 = &v32->obj.klass + v33;
        }
        else
        {
          v16 = DDS3_GBWK->fldSave->amap->blkOpenFlg;
          v18 = &v16->obj.klass + v9;
        }
        v35 = v18[4];
        v26 = v35 + 4 * v10;
      }
      v30 = *(v26 + 32);
      v31 = 1 << v8;
    }
    v11 = SBlock - 33;
    if (v9 >= 40)
    {
      if ((v7 & 0xFFFFFFFE) != 0x3C)
        return;
      v13 = DDS3_GBWK->amapEX_Ver7->blkOpenFlg;
      v14 = v7 - 60LL;
      if (v14 < LODWORD(v13->max_length))
    }
    else
    {
      if (v9 >= 30)
      {
        v13 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
        v14 = v7 - 40LL;
        if (v14 < LODWORD(v13->max_length))
      }
      else
      {
        v13 = DDS3_GBWK->amap_Ver7->blkOpenFlg;
        v14 = v9;
        if (v9 < LODWORD(v13->max_length))
        {
          v28 = v13->m_Items[v14];
          v26 = v28 + 4 * v10;
          v30 = *(v26 + 32);
          v31 = 1 << v11;
          *(v26 + 32) = v30 & ~v31;
          return;
        }
      }
    }
  }
}

// 0xf993a0
void fldAutoMapDraw(void) {
  u64 v2;

  else if (AutoMapSeq != 1)
  {
    return;
  }
  if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
  fldAutoMapDrawOneArea(v2);
}

// 0xf8dfb0
void fldAutoMapDrawBgOfsRF(f32 x, f32 y, f32 r) {
  ;
}

// 0xf8dc30
void fldAutoMapDrawFloor(sdfModelRootNode_t *root_node, void **obj, s32 nodeidx) {
  s64 v7;
  struct sdfModelNode_t_array *items;
  struct sdfModelNode_t_o *children;
  s32 max_length;
  Il2CppClass **v13;
  UnityEngine_Object_o *v14;
  UnityEngine_GameObject_o **v15;
  UnityEngine_Object_o *v16;
  UnityEngine_GameObject_o *v19;
  UnityEngine_GameObject_o *v20;
  bool v21;

  v7 = nodeidx + 1LL;
  items = root_node->nodeList->items;
  if (obj)
  {
    children = items->m_Items[v7]->children;
    if (children)
    {
      max_length = obj->max_length;
      if (max_length > nodeidx)
      {
        v13 = &obj->obj.klass + nodeidx;
        v16 = v13[4];
        v15 = (v13 + 4);
        v14 = v16;
        if (!op_Equality(v14, 0, 0))
        {
          v19 = *v15;
          if ((children->flags & 1) != 0)
          {
            v20 = v19;
            v21 = 0;
          }
          else
          {
            v20 = v19;
            v21 = 1;
          }
          cmpSetupObject(v20, v21);
        }
      }
    }
  }
}

// 0xf8b0c0
void fldAutoMapDrawIconOfsR(f32 x, f32 y, s32 tex, s32 r) {
  ;
}

// 0xf8b0d0
void fldAutoMapDrawIconOfsRF(f32 x, f32 y, s32 tex, f32 r) {
    sdfSin(0);
    sdfDrawTagInit(0);
    sdf2DLinkTexPacket(0, 0, 0);
    OOYRAD(0);
    SetRotateMatrixY(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX_XYZ();
    SDF_VU0__STOREVECTOR(0);
    SDF_GS_SET_ALPHA(0, 0, 0, 0, 0);
    sdfPrimLinkFt4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    fldDrawGetOt();
    sdfDrawTagLinkOt(0, 0);
}

// 0xf93220
void fldAutoMapDrawIconOfsRForUnity(s32 tex, s32 AmArea, s32 nodeIdx, s32 loop2, s32 loop3) {
    fldAutoMapGetChild(0, 0, 0, 0, 0, 0);
}

// 0xf8ddb0
void fldAutoMapDrawMdl1(sdfModelRootNode_t *modelRoot, f32 x, f32 y, f32 z) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(0);
    sdfModelMakeLocalTm(0);
    sdfModelEvalTm(0);
    sdfModelLinkOt(0, 0);
}

// 0xf8e4e0
void fldAutoMapDrawOneArea(void) {
    DDS3_PADCHECK_PRESS(0);
    DDS3_PADCHECK_TRIG(0);
    fldDbgPrintStr2DC(0, 0, 0, 0, 0);
    deleteFldMenuSub(0);
    fldAutoMapGetFloorMax();
    frSetFontDrawOT(0);
    SDF_VU0__LOADMATRIX(0);
    InversMatrix();
    p2sdPlaySE(0);
    fldAllIconDel();
    fldAutoMapGetFloorNext(0);
    fldAutoMapGetFloorPrev(0);
    sdf3DSetCamera(0, 0);
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    aDrawBoxF(0, 0, 0, 0, 0, 0, 0, 0);
    ooyTestRGBMaskOn();
    fldAutoMapChkOpen(0, 0, 0);
    fldPoint3To2H(0, 0, 0, 0, 0);
    fldAutoMapDrawMdl1(0, 0, 0, 0);
    fldAutoMapDrawFloor(0, 0, 0);
    fldAutoMapNodeSet(0, 0, 0);
    ooyTestRGBMaskOff();
    evtBitCheck(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    fldAutoMapGetAreaPos(0, 0, 0);
    sdfSin(0);
    fldAutoMapDrawIconOfsRForUnity(0, 0, 0, 0, 0);
    fldPoint3DTo2DPlayer(0, 0, (sdfVector3_t){0});
    fldAutoMapDrawIconOfsRF(0, 0, 0, 0);
    aDrawBoxG(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    aDrawBoxGF(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    fldAutoMapGetBBox(0, 0, 0, 0);
    GetFieldName(0, 0);
    RepColTag(0, 0);
    GetFloorName(0, 0, 0);
}

// 0xf94e50
void fldAutoMapDrawWindow(void) {
  ;
}

// 0xf8d750
void fldAutoMapFileFree(void) {
  ;
}

// 0xf8c0e0
void fldAutoMapFontInit(s32 bank) {
  u64 i;
  s32 Idx;
  struct System_Int16_array *am_areaSL;
  System_String_o *klass;
  System_String_o *v10;
  s16 Length;
  char *v13;
  u64 j;
  s32 v16;
  struct System_Int16_array *am_floorSL;
  System_String_o *v20;
  System_String_o *v21;
  s16 v22;
  char *v24;
  fldGlobal_c *v25;
  u64 v26;
  s32 v29;
  struct System_Int16_array *am_spcSL;
  System_String_o *v33;
  System_String_o *v34;
  s16 v35;
  char *v37;
  s32 fieldID;
  System_String_o *Item;
  System_String_o *v41;
  s16 v43;

  for (i = 0; i != 41; ++i)
  {
    Idx = fldAreaNameGetIdx(bank, i);
    klass = _get_Item(
              fldNameData->_fldAreaNameTbl,
              Idx)[1].klass;
    v10 = ToString_2975520(klass);
    Length = get_Length(v10);
    v13 = am_areaSL + 2 * i;
    *(v13 + 16) = Length;
  }
  for (j = 0; j != 41; ++j)
  {
    v16 = fldFloorNameGetIdx(bank, j);
    v20 = _get_Item(
            fldNameData->_fldFloorNameTbl,
            v16)[1].klass;
    v21 = ToString_2975520(v20);
    v22 = get_Length(v21);
    v24 = am_floorSL + 2 * j;
    *(v24 + 16) = v22;
  }
  v26 = 0;
  do
  {
    v29 = fldBasyoNameGetIdx(bank, v26);
    v33 = _get_Item(
            fldNameData->_fldBasyoNameTbl,
            v29)[1].klass;
    v34 = ToString_2975520(v33);
    v35 = get_Length(v34);
    v37 = am_spcSL + 2 * v26++;
    *(v37 + 16) = v35;
  }
  while (v26 != 24);
  fieldID = fldGb->fieldID;
  if (fieldID <= 49)
  {
    else  }
  else
  {
    fieldID = 0;
    if ((v25->_2.bitflags2 & 2) == 0)
  }
  Item = _get_Item(
           fldNameData->_fldFieldNameTbl,
           fieldID);
  v41 = ToString_2975520(Item);
  v43 = get_Length(v41);
  am_fldSL = v43;
}

// 0xf95df0
void fldAutoMapFree(void) {
    sdfModelRootFree(0, 0, 0);
    frSetFontDrawOT(0);
    AutoMapDispOff(0);
    deleteFldMenuSub(0);
}

// 0xf8bfa0
void fldAutoMapGetAreaPos(s32 area, f32 *getX, f32 *getZ) {
  struct fldAmAreaData_t_array *pfldAmArea;
  s32 v9;
  Il2CppClass **v11;
  char *v12;
  Il2CppClass *v13;

  v9 = 0;
  do
  {
    if (v9 >= nfldAmArea)
    {
      *getX = 0.0;
      *getZ = 0.0;
      return;
    }
    ++v9;
  }
  while (area + 1 != v9);
  v11 = &pfldAmArea->obj.klass + area;
  v13 = v11[4];
  v12 = (v11 + 4);
  *getX = *(v13->_1.this_arg.data + 4);
  *getZ = *(*(*v12 + 48LL) + 24LL);
}

// 0xf8ba20
void fldAutoMapGetBBox(f32 *getX0, f32 *getZ0, f32 *getX1, f32 *getZ1) {
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v9;
  Il2CppClass **v11;
  char *v12;
  Il2CppClass *v13;
  const char *namespaze;
  u64 v15;
  const char *v16;
  s32 v19;
  s64 v21;
  f32 v24;
  s64 v26;
  s64 v29;
  f32 v31;
  s64 v33;
  s64 v36;
  f32 v38;
  s64 v40;
  s64 v43;
  f32 v45;
  s64 v47;

  *getX0 = 0.0;
  *getZ0 = 0.0;
  *getX1 = 0.0;
  *getZ1 = 0.0;
  v9 = 0;
  if (v9 < nfldAmArea)
  {
    v11 = &pfldAmArea->obj.klass + v9;
    v13 = v11[4];
    v12 = (v11 + 4);
    namespaze = v13->_1.namespaze;
    v15 = 0;
    v16 = namespaze + 32;
    while (1)
    {
      if (v15 >= *(*v12 + 32LL))
      {
        ++v9;
      }
      v19 = fldAutoMapChkOpen(gAmap_NowField, v9, v15, getZ1);
      else      v21 = *(*&v16[8 * v15] + 48LL);
      if (v21)
      {
        if (*getX0 <= *(v21 + 16))
        {
          v24 = *getX0;
          if (v15 >= *(namespaze + 6))
        }
        else
        {
          v24 = *(v21 + 16);
          *getX0 = v24;
        }
        v26 = *(*&v16[8 * v15] + 56LL);
        if (v24 > *(v26 + 16))
        {
          *getX0 = *(v26 + 16);
        }
        v29 = *(*&v16[8 * v15] + 48LL);
        if (*getX1 >= *(v29 + 16))
        {
          v31 = *getX1;
          if (v15 >= *(namespaze + 6))
        }
        else
        {
          v31 = *(v29 + 16);
          *getX1 = v31;
        }
        v33 = *(*&v16[8 * v15] + 56LL);
        if (v31 < *(v33 + 16))
        {
          *getX1 = *(v33 + 16);
        }
        v36 = *(*&v16[8 * v15] + 48LL);
        if (*getZ0 >= *(v36 + 24))
        {
          v38 = *getZ0;
          if (v15 >= *(namespaze + 6))
        }
        else
        {
          v38 = *(v36 + 24);
          *getZ0 = v38;
        }
        v40 = *(*&v16[8 * v15] + 56LL);
        if (v38 < *(v40 + 24))
        {
          *getZ0 = *(v40 + 24);
        }
        v43 = *(*&v16[8 * v15] + 48LL);
        if (*getZ1 <= *(v43 + 24))
        {
          v45 = *getZ1;
          if (v15 >= *(namespaze + 6))
        }
        else
        {
          v45 = *(v43 + 24);
          *getZ1 = v45;
        }
        v47 = *(*&v16[8 * v15] + 56LL);
        if (v45 > *(v47 + 24))
        {
          *getZ1 = *(v47 + 24);
        }
      }
      ++v15;
    }
  }
}

// 0xf94070
void *fldAutoMapGetChild(void *parentObj, char *name1, char *name2, s32 num1, s32 num2, s32 num3) {
    fldAutoMapChkChild(0, 0, 0, 0);
    return 0;
}

// 0xf8e0a0
s32 fldAutoMapGetFloorMax(void) {
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v4;
  s32 v5;
  Il2CppClass **v7;
  char *v8;
  Il2CppClass *v9;
  const char *namespaze;
  u64 i;

  v4 = 0;
  v5 = 0;
  while (v4 < nfldAmArea)
  {
    v7 = &pfldAmArea->obj.klass + v4;
    v9 = v7[4];
    v8 = (v7 + 4);
    namespaze = v9->_1.namespaze;
    for (i = 0; i < *(*v8 + 32LL); ++i)
    {
      if (v5 < *(*&namespaze[8 * i + 32] + 44LL))
      {
        v5 = *(*&namespaze[8 * i + 32] + 44LL);
      }
    }
    ++v4;
  }
  return v5 + 1;
}

// 0xf8af20
s32 fldAutoMapGetFloorNext(s32 floor) {
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v6;
  s32 v7;
  u32 i;
  s32 v13;

  v6 = 0;
  v7 = 999;
  while (v6 < nfldAmArea)
  {
    for (i = 0; i < pfldAmArea->m_Items[v6]->nSB; ++i)
    {
      if (fldAutoMapChkOpen(gAmap_NowField, v6, i))
      {
        v13 = fldAutoMap_GetFloor(v6, i);
        if (v7 > v13 && v13 > floor)
          v7 = v13;
      }
    }
    ++v6;
  }
  if (v7 == 999)
    return floor;
  else
    return v7;
}

// 0xf8a8e0
s32 fldAutoMapGetFloorPrev(s32 floor) {
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v6;
  s32 v7;
  u32 i;
  s32 v13;

  v6 = 0;
  v7 = -1;
  while (v6 < nfldAmArea)
  {
    for (i = 0; i < pfldAmArea->m_Items[v6]->nSB; ++i)
    {
      if (fldAutoMapChkOpen(gAmap_NowField, v6, i))
      {
        v13 = fldAutoMap_GetFloor(v6, i);
        if (v7 < v13 && v13 < floor)
          v7 = v13;
      }
    }
    ++v6;
  }
  if (v7 == -1)
    return floor;
  else
    return v7;
}

// 0xf8d760
void fldAutoMapLoad(void) {
}

// 0xf8d610
void fldAutoMapModelLoad(void) {
  s32 fieldID;

  fieldID = fldGb->fieldID;
  if (fieldID <= 199)
  {
    fldAutoMapFontInit(fieldID % 100);
    if (fldGb->fieldID >= 10)
    {
      fldAmModelLoadFile();
    }
  }
}

// 0xf991f0
void fldAutoMapNameD(s32 nameID) {
  {
    nameID = -1;
  }
  fldGb->nameD = nameID;
}

// 0xf99150
void fldAutoMapNameU(s32 nameID) {
  {
    nameID = -1;
  }
  fldGb->nameU = nameID;
}

// 0xf8dfc0
void fldAutoMapNodeSet(sdfModelRootNode_t *root_node, s32 nodeidx, s32 mode) {
  struct sdfModelNode_t_array *items;
  s32 max_length;
  s64 v6;
  sdfModelNode_t_o *v8;
  struct sdfModelNode_t_o *children;
  u16 flags;
  u16 v11;
  u16 v12;
  struct sdfModelNode_t_o *next;

  items = root_node->nodeList->items;
  max_length = items->max_length;
  v6 = nodeidx + 1LL;
  if (v6 < max_length)
  {
    v8 = items->m_Items[v6];
    children = v8->children;
    if (children)
    {
      flags = children->flags;
      v11 = flags & 0xFFFE;
      v12 = flags | 1;
      if (mode)
        v12 = v11;
      children->flags = v12;
      next = children->next;
      if (next)
      {
        if (mode)
        {
          do
          {
            if (children == next)
              break;
            if (v8 != next->parent)
              break;
            next->flags &= ~1u;
            next = next->next;
          }
          while (next);
        }
        else
        {
          do
          {
            if (children == next)
              break;
            if (v8 != next->parent)
              break;
            next->flags |= 1u;
            next = next->next;
          }
          while (next);
        }
      }
    }
  }
}

// 0xf981d0
void fldAutoMapOpenBlock(s32 blockID) {
  s32 v6;
  s64 v8;
  struct System_UInt32_array_array *blkOpenFlg;
  System_UInt32_array *v13;
  struct System_UInt32_array_array *v15;
  struct fldAutoMapBuffEX_t_o *amapEX_Ver7;
  struct System_UInt32_array_array *v19;
  s64 v20;
  struct fldGlobalWork_t_o *v23;
  s64 v24;
  struct fldGlobalWork_t_o *fldGb;
  s32 areaID;
  s32 v29;

  if (blockID >= 1)
  {
    if (!fldProcCheckFlag(0x80u))
    {
      v6 = gAmap_NowField % 100;
      if (v6 >= 10)
      {
        v8 = v6 - 10LL;
        fldGb->blockID = blockID - 1;
        if (fldGb->blockID > 31)
        {
          if (v8 < 40)
          {
            if (v8 < 30)
            {
              blkOpenFlg = DDS3_GBWK->amap_Ver7->blkOpenFlg;
              v13 = blkOpenFlg->m_Items[v8];
            }
            v19 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
            v20 = v6 - 40LL;
            if (v20 < LODWORD(v19->max_length))
            {
              v13 = v19->m_Items[v20];
            }
          }
          if ((v6 & 0xFFFFFFFE) == 0x3C)
          {
            amapEX_Ver7 = DDS3_GBWK->amapEX_Ver7;
          }
        }
        if (v8 >= 40)
        {
          if ((v6 & 0xFFFFFFFE) == 0x3C)
          {
            amapEX_Ver7 = DDS3_GBWK->amapEX;
            v19 = amapEX_Ver7->blkOpenFlg;
            v20 = v6 - 60LL;
            if (v20 < LODWORD(v19->max_length))
          }
          fldGb->AmSBlock = blockID;
          areaID = fldGb->areaID;
          v29 = fldGb->blockID;
          fldGb->AmFloor = fldAutoMap_GetFloor(areaID, v29);
          if (gAmap_NowField == 25)
          {
            if (!fldGb->areaID)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 17, blockID);
            }
            if (fldGb->areaID == 16)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 1, blockID);
            }
            if (fldGb->areaID == 1)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 18, blockID);
            }
            if (fldGb->areaID == 17)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 2, blockID);
            }
            if (fldGb->areaID == 2)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 19, blockID);
            }
            if (fldGb->areaID == 18)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 3, blockID);
            }
            if (fldGb->areaID == 3)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 20, blockID);
            }
            if (fldGb->areaID == 19)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 4, blockID);
            }
            if (fldGb->areaID == 4)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 21, blockID);
            }
            if (fldGb->areaID == 20)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 5, blockID);
            }
          }
          if (gAmap_NowField == 34)
          {
            if (fldGb->areaID == 1)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 3, blockID);
            }
            if (fldGb->areaID == 2)
            {
              fldAutoMapOpenBlock2(gAmap_NowField, 2, blockID);
            }
          }
          return;
        }
        if (v8 >= 30)
        {
          v15 = DDS3_GBWK->amap31->blkOpenFlg;
          v8 = v6 - 40LL;
          if (v8 < LODWORD(v15->max_length))
          {
            v13 = v15->m_Items[v8];
            {
              v23 = fldGb;
              v24 = v23->areaID;
              v13->m_Items[v24] |= 1 << v23->blockID;
            }
          }
        }
        else
        {
          v15 = DDS3_GBWK->fldSave->amap->blkOpenFlg;
          if (v8 < LODWORD(v15->max_length))
        }
      }
    }
  }
}

// 0xf98ab0
void fldAutoMapOpenBlock2(s32 fld, s32 area, s32 SBlock) {
  s32 v7;
  char v8;
  s64 v9;
  s64 v10;
  char v11;
  struct System_UInt32_array_array *v13;
  s64 v14;
  struct System_UInt32_array_array *v16;
  Il2CppClass **v18;
  struct System_UInt32_array_array *blkOpenFlg;
  s64 v22;
  System_UInt32_array *v24;
  s64 v26;
  System_UInt32_array *v28;
  s32 v30;
  s32 v31;
  struct System_UInt32_array_array *v32;
  s64 v33;
  Il2CppClass *v35;

  v7 = fld % 100;
  if (fld % 100 >= 10)
  {
    v8 = SBlock - 1;
    v9 = v7 - 10LL;
    v10 = area - 1LL;
    if (SBlock - 1 <= 31)
    {
      if (v9 >= 40)
      {
        if ((v7 & 0xFFFFFFFE) != 0x3C)
          return;
        blkOpenFlg = DDS3_GBWK->amapEX->blkOpenFlg;
        v22 = v7 - 60LL;
        v24 = blkOpenFlg->m_Items[v22];
        v26 = v24 + 4 * v10;
      }
      else
      {
        if (v9 >= 30)
        {
          v32 = DDS3_GBWK->amap31->blkOpenFlg;
          v33 = v7 - 40LL;
          v18 = &v32->obj.klass + v33;
        }
        else
        {
          v16 = DDS3_GBWK->fldSave->amap->blkOpenFlg;
          v18 = &v16->obj.klass + v9;
        }
        v35 = v18[4];
        v26 = v35 + 4 * v10;
      }
      v30 = *(v26 + 32);
      v31 = 1 << v8;
    }
    v11 = SBlock - 33;
    if (v9 >= 40)
    {
      if ((v7 & 0xFFFFFFFE) != 0x3C)
        return;
      v13 = DDS3_GBWK->amapEX_Ver7->blkOpenFlg;
      v14 = v7 - 60LL;
      if (v14 < LODWORD(v13->max_length))
    }
    else
    {
      if (v9 >= 30)
      {
        v13 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
        v14 = v7 - 40LL;
        if (v14 < LODWORD(v13->max_length))
      }
      else
      {
        v13 = DDS3_GBWK->amap_Ver7->blkOpenFlg;
        v14 = v9;
        if (v9 < LODWORD(v13->max_length))
        {
          v28 = v13->m_Items[v14];
          v26 = v28 + 4 * v10;
          v30 = *(v26 + 32);
          v31 = 1 << v11;
          *(v26 + 32) = v30 | v31;
          return;
        }
      }
    }
  }
}

// 0xf97700
void fldAutoMapOpenCheck(void) {
  s32 fieldID;
  s32 v5;
  fldAutoMap_c **v6;
  s32 v7;
  s32 v10;
  struct dds3GlobalWork_t_o *v13;
  struct System_UInt32_array_array *v14;
  s64 v15;
  System_UInt32_array *v17;
  void *amap31_Ver7;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_UInt32_array_array *blkOpenFlg;
  System_UInt32_array *v23;
  struct System_UInt32_array_array *v24;
  struct System_UInt32_array_array *AutoMapOpenTbl;
  struct System_UInt32_array_array *v30;
  System_UInt32_array *v31;
  struct dds3GlobalWork_t_o *v32;
  struct System_UInt32_array_array *v33;
  u64 v37;
  u64 v38;
  fldAutoMap_c *v39;
  struct System_UInt32_array_array *v40;
  u64 v43;
  s64 v44;
  s64 v46;
  s32 v48;
  struct System_UInt32_array_array *v50;
  u64 *v51;
  System_UInt32_array *v53;
  u32 v55;
  s64 v56;
  s64 v58;
  u64 v60;
  s64 v61;
  s64 v63;
  struct System_SByte_array *autoMapOpenEX;
  char *v68;
  struct System_SByte_array *autoMapOpen;
  u64 v71;
  System_UInt32_array *v72;
  System_UInt32_array *v73;
  u32 v74;

  else if (!fldChkVortex())
  {
    return;
  }
  fieldID = fldGb->fieldID;
  if (fieldID >= 10)
  {
    else if (fieldID == 12)
    {
      return;
    }
    if (fieldID != 13)
    {
      if (fieldID != 30)
      {
        if (fieldID != 40)
        {
          if (fieldID == 60)
          v5 = fieldID - 10;
          if (fieldID == 61)
          {
            v5 = fldGb->fieldID - 24;
          }
          v6 = &fldAutoMap;
          v7 = fldGb->fieldID;
          if (v7 > 59)
          {
            if (v7 - 60 >= SLODWORD(DDS3_GBWK->GameFileInfo->autoMapOpenEX->max_length))
              return;
          }
          else
          {
            if (v7 - 10 >= SLODWORD(DDS3_GBWK->GameFileInfo->autoMapOpen->max_length))
              return;
          }
          v10 = fldGb->fieldID;
          if (autoMapOpenCheck(v10))
            return;
          if (v5 <= 29)
          {
            blkOpenFlg = DDS3_GBWK->fldSave->amap->blkOpenFlg;
            v15 = v5;
            v23 = blkOpenFlg->m_Items[v5];
            v24 = DDS3_GBWK->amap_Ver7->blkOpenFlg;
            v73 = v23;
            if (v5 < LODWORD(v24->max_length))
            {
              if (v73)
              {
                v72 = v24->m_Items[v15];
                if (v72)
                {
                  if (LODWORD(AutoMapOpenTbl->m_Items[v5]->max_length) != 1)
                  v30 = AutoMapOpenTbl;
                  v31 = v30->m_Items[v5];
                  if (v31->m_Items[0])
                  {
                    v37 = 0;
                    v38 = 0;
                    while (1)
                    {
                      v40 = AutoMapOpenTbl;
                      if (v37 >= SLODWORD(v40->m_Items[v5]->max_length))
                        break;
                      v43 = *v6;
                      v74 = v73->m_Items[v38];
                      if (((*v6)->_2.bitflags2 & 2) != 0 && !*(v43 + 216))
                      {
                        v43 = *v6;
                      }
                      v44 = *(*(v43 + 184) + 376LL);
                      v46 = *(v44 + 8LL * v5 + 32);
                      v48 = *(v46 + 4 * v37 + 36);
                      v50 = (*v6)->static_fields->AutoMapOpenTbl;
                      v51 = v6;
                      v53 = v50->m_Items[v5];
                      v55 = v53->m_Items[v37];
                      v56 = *(*(*v51 + 184) + 376LL);
                      v58 = *(v56 + 8LL * v5 + 32);
                      if ((v55 & v72->m_Items[v38]) != *(v58 + 4 * v37 + 32))
                        return;
                      v60 = *v51;
                      v6 = v51;
                      if ((*(*v51 + 295) & 2) != 0 && !*(v60 + 216))
                      {
                        v60 = *v51;
                      }
                      v61 = *(*(v60 + 184) + 376LL);
                      v63 = *(v61 + 8LL * v5 + 32);
                      if ((v48 & v74) != *(v63 + 4 * v37 + 36))
                        return;
                      ++v38;
                      v37 += 2LL;
                      v39 = *v51;
                      if ((*(*v51 + 295) & 2) != 0)
                    }
                    if (v5 <= 34)
                    {
                      {
                      }
                      autoMapOpen = DDS3_GBWK->GameFileInfo->autoMapOpen;
                      v68 = autoMapOpen + v5;
                    }
                    else
                    {
                      {
                      }
                      autoMapOpenEX = DDS3_GBWK->GameFileInfo->autoMapOpenEX;
                      v68 = autoMapOpenEX + v5 - 36;
                    }
                    v68[32] = 1;
                    v71 = *v6;
                    if (((*v6)->_2.bitflags2 & 2) != 0 && !*(v71 + 216))
                    fldAutoMapAllOpenCheck(v71);
                  }
                }
              }
              return;
            }
          }
          else
          {
            if (v5 <= 35)
            {
              v32 = DDS3_GBWK;
              v33 = v32->amap31->blkOpenFlg;
              v15 = v5 - 30LL;
              v17 = v33->m_Items[v15];
              amap31_Ver7 = v32->amap31_Ver7;
            }
            else
            {
              v13 = DDS3_GBWK;
              v14 = v13->amapEX->blkOpenFlg;
              v15 = v5 - 36LL;
              v17 = v14->m_Items[v15];
              amap31_Ver7 = v13->amapEX_Ver7;
            }
            v73 = v17;
            v24 = *(amap31_Ver7 + 2);
            if (v15 < LODWORD(v24->max_length))
          }
        }
      }
    }
  }
}

// 0xf99290
void fldAutoMapProc(void) {
  s32 fieldID;
  u64 v4;

  fieldID = fldGb->fieldID;
  if (fieldID >= 10)
  {
    else if (fieldID > 199)
    {
      return;
    }
    else if (AutoMapSeq != 1)
    {
      return;
    }
    if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
    fldAutoMapCalc(v4);
  }
}

// 0xf96560
void fldAutoMapSeqEnd(void) {
  dds3Basic_t_o *basic;

  basic = 0;
  fldAutoMapFree();
  AutoMapSeq = 0;
  fldSeqOffFlag(1u);
  fldRegistUnitPad();
  evtEnableMoonDraw();
  fldGb->NoInpAmCnt = 4;
  frSetFontDrawOT(0x48u);
  basic = dds3GetActiveScene();
  dds3VisibleSceneBasic(&basic, 1);
  fldSetupButtonGuide();
}

// 0xf94e60
void fldAutoMapSeqStart(void) {
    fldSeqCheckFlag(0);
    dds3GetActiveScene();
    dds3VisibleSceneBasic(0, 0);
    p2sdPlaySE(0);
    sdfModelMakeEarly(0, 0);
    sdfTexSet(0);
    fldAutoMapGetAreaPos(0, 0, 0);
    fldSeqOnFlag(0);
    fldReleaseUnitPad();
    evtDisableMoonDraw();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    AutoMapDispOn(0);
    GetMainCamera(0);
    GetAutoMapCameraReal(0);
    GetAutoMapCameraHalf(0);
    GetAutoMapObj(0);
    GetLocalizeText(0);
    RepColTag(0, 0);
    fldAllIconLoad();
    fldAllIconDel();
    ButtonGuideDispSet(0, 0, 0, 0);
    ButtonGuideDispOn();
}

// 0xf98050
void fldAutoMapSetField(s32 fld, s32 area, s32 block) {
}

// 0xf8ad50
s32 fldAutoMap_GetFloor(s32 area, s32 block) {
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v7;
  s32 v8;
  s32 v9;
  Il2CppClass **v10;
  Il2CppClass *v11;
  char *v12;
  Il2CppClass *v13;
  const char *namespaze;
  u64 v15;
  u32 v19;

  v7 = 0;
  v8 = block;
  v9 = 1;
  while (v7 < nfldAmArea)
  {
    v10 = &pfldAmArea->obj.klass + v7;
    v13 = v10[4];
    v12 = (v10 + 4);
    v11 = v13;
    if (v7 == area)
    {
      namespaze = v11->_1.namespaze;
      v15 = 0;
      while (v15 < *(*v12 + 32LL))
      {
        if (v8 == v15)
        {
          v9 = *(*&namespaze[8 * v15 + 32] + 44LL) + 1;
        }
        ++v15;
        if (v7 >= LODWORD(pfldAmArea->max_length))
      }
    }
    else
    {
      v19 = -1;
      do
      {
        ++v19;
      }
      while (v19 < LODWORD(v11->_1.byval_arg.data));
    }
    ++v7;
  }
  return v9;
}

// 0xf99950
void fldDrawAreaBlockFont(s32 ofsx) {
  struct fldGlobalWork_t_o *fldGb;
  fldAutoMap_c *v4;
  struct fldAutoMap_StaticFields **p_static_fields;
  struct fldAutoMap_StaticFields *v6;
  f32 gFldAreaNameCnt;
  s16 v8;
  s32 v9;
  s32 fldDrawAreaBlockFont_pm_mode;
  struct fldAutoMap_StaticFields *v11;
  GlobalData_c *v12;
  struct fldAutoMap_StaticFields *static_fields;
  struct fldAutoMap_StaticFields *v14;
  struct fldAutoMap_StaticFields *v15;
  struct fldAutoMap_StaticFields *v16;
  struct fldAutoMap_StaticFields *v17;
  f32 v19;
  f32 v20;
  f32 v21;
  s32 v22;
  s32 v23;
  struct fldGlobalWork_t_o *v24;
  struct System_Int16_array *am_spcSL;
  s64 nameD;
  struct GlobalData_StaticFields *v30;
  dds3DefaultMain_o *kernelObject;
  System_String_o *AreaName;
  u32 v34;
  struct System_Int16_array *am_areaSL;
  s64 nameU;
  struct GlobalData_StaticFields *v39;
  dds3DefaultMain_o *v41;
  bool v42;
  s32 v43;
  s32 v44;

  if (fldGb->fieldID < 200)
  {
    switch (fldGb->AllPanelMode)
    {
      case 0:
        gFldAreaNameCnt = 0.0;
        static_fields = v4->static_fields;
      case 1:
        gFldAreaNameCnt = 1.0;
        static_fields = v4->static_fields;
      case 2:
        p_static_fields = &v4->static_fields;
        v14 = v4->static_fields;
        if (v14->gFldAreaNameCnt <= 0.0)
        v14->fldDrawAreaBlockFont_pm_mode = -1;
        gFldAreaNameCnt = gFldAreaNameCnt + -0.1;
        v15 = v4->static_fields;
        if (v15->gFldAreaNameCnt >= 0.0)
      case 3:
        p_static_fields = &v4->static_fields;
        v16 = v4->static_fields;
        if (v16->gFldAreaNameCnt < 1.0)
        {
          v16->fldDrawAreaBlockFont_pm_mode = 1;
          gFldAreaNameCnt = gFldAreaNameCnt + 0.1;
          v11 = v4->static_fields;
          if (v11->gFldAreaNameCnt > 1.0)
        }
      case 4:
      case 5:
      case 6:
      case 7:
        p_static_fields = &v4->static_fields;
        v6 = v4->static_fields;
        gFldAreaNameCnt = v6->gFldAreaNameCnt;
        if (gFldAreaNameCnt >= 0.99)
        if (gFldAreaNameCnt <= 0.01)
        v8 = *&v4->_2.bitflags1;
        if ((v8 & 0x200) != 0)
        {
          v9 = v8 & 0x200;
          fldDrawAreaBlockFont_pm_mode = v6->fldDrawAreaBlockFont_pm_mode;
          if (fldDrawAreaBlockFont_pm_mode != -1)
        }
        else
        {
          v9 = 0;
          fldDrawAreaBlockFont_pm_mode = v6->fldDrawAreaBlockFont_pm_mode;
          if (fldDrawAreaBlockFont_pm_mode != -1)
          {
            if (fldDrawAreaBlockFont_pm_mode != 1)
            v6->gFldAreaNameCnt = v6->gFldAreaNameCnt + 0.1;
            v11 = *p_static_fields;
            if ((*p_static_fields)->gFldAreaNameCnt <= 1.0)
            v11->gFldAreaNameCnt = 1.0;
          }
        }
        v6->gFldAreaNameCnt = v6->gFldAreaNameCnt + -0.1;
        v15 = *p_static_fields;
        if ((*p_static_fields)->gFldAreaNameCnt >= 0.0)
        v15->gFldAreaNameCnt = 0.0;
        static_fields = *p_static_fields;
        static_fields->fldDrawAreaBlockFont_pm_mode = 0;
        v17 = v4->static_fields;
        v19 = v17->gFldAreaNameCnt;
        v20 = 1.0 - v19;
        v21 = v19 * 0.0;
        v22 = ((v21 + (v20 * 250.0)) * 3.75);
        v23 = ((v21 + (v20 * 0.0)) * 2.25);
        v24 = fldGb;
        if (v24->nameD == -1)
        {
          if (v24->nameU == -1)
            return;
          nameU = fldGb->nameU;
          if (am_areaSL->m_Items[nameU] > 1)
          {
            v39 = v12->static_fields;
            kernelObject = v39->kernelObject;
            AreaName = GetAreaName(fldNameData, fldGb->fieldID, fldGb->nameU);
            v34 = -1600273536;
          }
        }
        else
        {
          nameD = fldGb->nameD;
          if (am_spcSL->m_Items[nameD] > 1)
          {
            v30 = v12->static_fields;
            kernelObject = v30->kernelObject;
            AreaName = GetBasyoName(fldNameData, fldGb->fieldID, fldGb->nameD);
            v34 = -253991808;
            v41 = kernelObject;
            v42 = 1;
            v43 = v22;
            v44 = v23;
          }
        }
        break;
      default:
    }
  }
  v41 = kernelObject;
  v34 = -1;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  AreaName = 0;
  SetAreaUI(v41, v42, v43, v44, AreaName, v34);
}

// 0xf93ff0
sdfVector3_t fldPoint3DTo2D(void *camera3D, void *camera2D, sdfVector3_t pos3D) {
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_RenderTexture_o *targetTexture;
  UnityEngine_Vector3_o v10;
  UnityEngine_Vector3_o v11;
  UnityEngine_Vector3_o v13;

  z = pos3D.z;
  y = pos3D.y;
  x = pos3D.x;
  v10 = WorldToViewportPoint_27174800(camera3D, pos3D);
  v13.x = v10.x;
  v13.y = v10.y;
  v13.z = 0.0;
  ViewportToScreenPoint(camera2D, v13);
  targetTexture = get_targetTexture(camera3D);
  (targetTexture->klass->vtable._6_get_height.methodPtr)(
    targetTexture,
    targetTexture->klass->vtable._6_get_height.method);
  v11.y = y;
  v11.z = z;
  v11.x = x;
  return WorldToScreenPoint_27174640(camera3D, v11);
}

// 0xf93ef0
sdfVector3_t fldPoint3DTo2DPlayer(void *camera3D, void *camera2D, sdfVector3_t pos3D) {
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Transform_o *transform;
  UnityEngine_Vector3_o v15;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v17;
  UnityEngine_Vector3_o v18;
  UnityEngine_Vector3_o v19;
  UnityEngine_Vector3_o v20;
  UnityEngine_Vector3_o result;

  z = pos3D.z;
  y = pos3D.y;
  x = pos3D.x;
  v18.x = x;
  v18.y = y;
  v18.z = z;
  v15 = WorldToViewportPoint_27174800(camera3D, v18);
  v20.x = v15.x;
  v20.y = v15.y;
  v20.z = 0.0;
  ViewportToScreenPoint(camera2D, v20);
  transform = get_transform(_autoMapUI->screenObj, 0);
  localPosition = get_localPosition(transform);
  v19.x = x;
  v19.y = y;
  v19.z = z;
  v17 = WorldToScreenPoint_27174640(camera3D, v19);
  result.z = v17.z;
  result.x = v17.x - localPosition.x;
  result.y = localPosition.y + v17.y;
  return result;
}
