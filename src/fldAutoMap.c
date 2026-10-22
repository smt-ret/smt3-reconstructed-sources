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

static void *mapNodeList1Area;
static void **mapNodeList2Area;
static void *mapNodeList1Half;
static void **mapNodeList2Half;
static void *cameraMainObj;
static void *cameraAutoRealObj;
static void *cameraAutoHalfObj;
static void *_cameraMain;
static void *_cameraAutoReal;
static void *_cameraAutoHalf;
static void *_autoMapObj;
static autoMapUI *_autoMapUI;
static void *_autoMapIconTbl;
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
static fldAmAreaData_t *pfldAmArea;
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
  UnityEngine_AnimatorStateInfo_o v4;
  UnityEngine_AnimatorStateInfo_o v5;

  memset(&v5, 0, sizeof(v5));
  GetCurrentAnimatorStateInfo(&v4, _autoMapUI->floorChange, 0);
  v5 = v4;
  if (sub_85F980(&v5, "autm_floor_current"))
    return 1;
  if ((!sub_85F980(&v5, "autm_floor_up") || sub_85FB40(&v5) >= 1.0) && sub_85F980(&v5, "autm_floor_down"))
    sub_85FB40(&v5);
  return 0;
}

// 0xf8e230
void CheckFloorAnimeEnd(void) {
  UnityEngine_AnimatorStateInfo_o v5;
  UnityEngine_AnimatorStateInfo_o v6;

  memset(&v6, 0, sizeof(v6));
  GetCurrentAnimatorStateInfo(&v5, _autoMapUI->floorChange, 0);
  v6 = v5;
  if (!sub_85F980(&v6, "autm_floor_current")
    && (!sub_85F980(&v6, "autm_floor_up") || sub_85FB40(&v6) >= 1.0)
    && (!sub_85F980(&v6, "autm_floor_down") || sub_85FB40(&v6) >= 1.0))
  {
    SetInteger(_autoMapUI->floorChange, "autm_ud", 0);
  }
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
  Il2CppObject *v5;
  s32 v8;
  u32 v10;

  v5 = Allocate(fldAmMdl_t);
  _ctor(v5, 0);
  v5[1].klass = SetsdfModelDef(pData, addr, 0);
  v8 = addr + 4;
  v10 = ToUInt32(pData, v8, 0);
  v5[1].monitor = sub_8D3950(uint, &v10);
  return v5;
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
        if (v10 >= v9[6])
        {
LABEL_31:
        }
      }
      else
      {
        *(v29 + 32) = 0;
        if (v10 >= v9[6])
          goto LABEL_31;
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
  UnityEngine_Object_o *v4;
  u64 v7[3];
  s64 v8;
  s64 v9;
  s64 v10;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v11;
  s64 v12;

  v12 = 0;
  memset(&v11, 0, sizeof(v11));
  v9 = 0;
  v10 = 0;
  v8 = 0;
  fldAutoMap_childIcon___GetEnumerator(&v11, _autoMapIconFld);
  while ((sub_43A0C0(&v11)
         & 1) != 0)
  {
    sub_43A2E0(&v11, v7);
    v9 = v7[1];
    v10 = v7[2];
    v8 = v7[0];
    v4 = sub_1A0CA50(&v8);
    Destroy_27360000(v4);
  }
  nullsub_31(&v11);
  fldAutoMap_childIcon___Clear(_autoMapIconFld);
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
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", AutomapIconFullPath, "autmark_exit");
  v10 = Prefab_16624656;
  autoMapIconTbl->m_Items[0] = v10;
  v12 = _autoMapIconTbl;
  v13 = get_asset_bc();
  v14 = LoadPrefab_16624656(v13, "common", AutomapIconFullPath, "autmark_comb");
  v15 = v14;
  v12->m_Items[1] = v15;
  v18 = _autoMapIconTbl;
  v19 = get_asset_bc();
  v20 = LoadPrefab_16624656(v19, "common", AutomapIconFullPath, "autmark_recov");
  v21 = v20;
  v18->m_Items[2] = v21;
  v24 = _autoMapIconTbl;
  v25 = get_asset_bc();
  v26 = LoadPrefab_16624656(v25, "common", AutomapIconFullPath, "autmark_terminal");
  v27 = v26;
  v24->m_Items[3] = v27;
  v30 = _autoMapIconTbl;
  v31 = get_asset_bc();
  v32 = LoadPrefab_16624656(v31, "common", AutomapIconFullPath, "autmark_shop");
  v33 = v32;
  v30->m_Items[4] = v33;
  v36 = _autoMapIconTbl;
  v37 = get_asset_bc();
  v38 = LoadPrefab_16624656(v37, "common", AutomapIconFullPath, "autmark_rag");
  v39 = v38;
  v36->m_Items[5] = v39;
  v42 = _autoMapIconTbl;
  v43 = get_asset_bc();
  v44 = LoadPrefab_16624656(v43, "common", AutomapIconFullPath, "autmark_elevator");
  v45 = v44;
  v42->m_Items[6] = v45;
  v48 = _autoMapIconTbl;
  v49 = get_asset_bc();
  v50 = LoadPrefab_16624656(v49, "common", AutomapIconFullPath, "autmark_event");
  v51 = v50;
  v48->m_Items[7] = v51;
  v54 = _autoMapIconTbl;
  v55 = get_asset_bc();
  v56 = LoadPrefab_16624656(v55, "common", AutomapIconFullPath, "autmark_pit");
  v57 = v56;
  v54->m_Items[8] = v57;
  v60 = _autoMapIconTbl;
  v61 = get_asset_bc();
  v62 = LoadPrefab_16624656(v61, "common", AutomapIconFullPath, "autmark_up");
  v63 = v62;
  v60->m_Items[9] = v63;
  v66 = _autoMapIconTbl;
  v67 = get_asset_bc();
  v68 = LoadPrefab_16624656(v67, "common", AutomapIconFullPath, "autmark_down");
  v69 = v68;
  v66->m_Items[10] = v69;
}

// 0xf94c80
void fldAllIconScale(f32 scale) {
  UnityEngine_GameObject_o *v5;
  UnityEngine_Transform_o *transform;
  UnityEngine_Vector3_o v7;
  u64 v8[3];
  s64 v9;
  s64 v10;
  s64 v11;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v12;
  s64 v13;

  v13 = 0;
  memset(&v12, 0, sizeof(v12));
  v10 = 0;
  v11 = 0;
  v9 = 0;
  fldAutoMap_childIcon___GetEnumerator(&v12, _autoMapIconFld);
  while ((sub_43A0C0(&v12)
         & 1) != 0)
  {
    sub_43A2E0(&v12, v8);
    v10 = v8[1];
    v11 = v8[2];
    v9 = v8[0];
    v5 = sub_1A0CA50(&v9);
    transform = get_transform(v5, 0);
    v7.z = 0.0;
    *&v7.x = 0;
    sub_8524C0(&v7.x, scale, scale, 1.0);
    set_localScale(transform, v7);
  }
  nullsub_31(&v12);
}

// 0xf8d0d0
void fldAmModelLoadFile(void) {
  s32 fieldID;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v7;
  struct fldGlobalWork_t_o *v8;
  struct fldGlobalWork_t_o *v9;
  Il2CppObject *v10;
  u64 *v12;
  s64 *v13;
  System_String_o *v15;
  u64 *v17;
  System_String_o *v19;
  s32 v20;
  bool IsDLCField;
  s64 *v22;
  System_String_o *v23;
  System_Byte_array *v25;
  fldAmFileHeader2_t_o *v26;
  s32 v28;
  System_String_o *pathstr;
  System_Byte_array *aTopPtr;

  aTopPtr = 0;
  pathstr = "";
  fieldID = fldGb->fieldID;
  fldMakeFilePath(&pathstr, fieldID, 1);
  if (fldGb->fieldID == 25)
  {
    else if (fldGb->areaID >= 16)
    {
      goto LABEL_53;
    }
  }
  v7 = fldGb;
  if (v7->fieldID == 34)
  {
    else if (v7->areaID > 2)
    {
      goto LABEL_20;
    }
    v10 = pathstr;
      goto LABEL_51;
LABEL_45:
    v7 = fldGb;
LABEL_51:
    v28 = v7->fieldID;
    v12 = sub_8D3950(s32, &v28);
    v13 = &"{0}f{1:D3}.amb.bytes";
    goto LABEL_68;
  }
LABEL_20:
  if (fldGb->fieldID == 34)
  {
    else if (fldGb->areaID > 9)
    {
      goto LABEL_27;
    }
LABEL_53:
    v10 = pathstr;
    v28 = fldGb->fieldID;
    v12 = sub_8D3950(s32, &v28);
    v13 = &"{0}f{1:D3}b.amb.bytes";
    goto LABEL_68;
  }
LABEL_27:
  v8 = fldGb;
  if (v8->fieldID != 34)
    goto LABEL_34;
  v8 = fldGb;
  if (v8->areaID <= 17)
    goto LABEL_58;
LABEL_34:
  v9 = fldGb;
  if (v9->fieldID != 34)
    goto LABEL_41;
  else if (v9->areaID > 24)
  {
    goto LABEL_41;
  }
  v10 = pathstr;
  v28 = v9->fieldID;
  v12 = sub_8D3950(s32, &v28);
  v13 = &"{0}f{1:D3}d.amb.bytes";
LABEL_68:
  v15 = Format_5268592(*v13, v10, v12);
  v28 = fldGb->fieldID;
  v17 = sub_8D3950(s32, &v28);
  v19 = Format("f{0:D3}", v17, 0);
  v20 = fldGb->fieldID;
  IsDLCField = IsDLCField(v20);
  v22 = &"m";
  if (!IsDLCField)
    v22 = &"";
  v23 = Concat_5224608(v19, *v22);
  sdfDevLoadFileUnity_25061072(v15, &aTopPtr, 0, v23);
  v25 = aTopPtr;
  v26 = fldAddressResolverAMB(v25);
  pfldAmArea = v26->pArea;
  nfldAmArea = v26->nArea;
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
  bool v4;
  bool v6;
  u64 v7;
  bool v10;
  u64 v11;
  s32 v18;
  s32 v22;
  s32 v25;
  s32 v28;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v46;
  f32 v51;
  f32 getX1;
  s64 getZ0;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;

  *&v54.x = 0;
  *&v54.z = 0;
  *&v56.x = 0;
  *&v56.z = 0;
  *&v55.x = 0;
  *&v55.z = 0;
  sub_854690(&v54.x, 0.0, 0.0, -1.0, 1.0);
  getZ0 = 0;
  getX1 = 0.0;
  v51 = 0.0;
LABEL_7:
  if (AutoMapSeq)
  {
    if (fldDbg->AutomapRapid)
    {
      v4 = DDS3_PADCHECK_PRESS(2);
    }
    else
    {
      v4 = DDS3_PADCHECK_TRIG(2);
    }
    v6 = v4;
    if (v6)
    {
        goto LABEL_25;
      goto LABEL_136;
    }
    ++*(*(v7 + 184) + 144LL);
    v10 = DDS3_PADCHECK_TRIG(3);
    if (v10)
    {
      fldAllIconDel(v11);
      if (!AutoMapResetFlg)
      {
        {
LABEL_25:
        }
LABEL_136:
        fldAutoMapSeqEnd(v7);
        dds3FadeOut2(0);
        dds3FadeIn2(8u);
        return;
      }
      p2sdPlaySE(10);
      gAmap_OfsX = gAmap_InX;
      gAmap_OfsZ = gAmap_InZ;
      gAmap_NowFloor = gAmap_InFloor;
      AutoMapResetFlg = 0;
      ButtonGuideDispSet("AUTO01", 0, 0, 90);
      AutoMapGuidFlg = 0;
    }
    if (*(*(v11 + 184) + 144LL) == 6)
    {
      fldAutoMapOpenCheck(v11);
    }
    if (*(*(v11 + 184) + 144LL) < 11)
      goto LABEL_211;
    if (DDS3_ANALOGCHECK_PRESS(0))
    {
      if (!DDS3_ANALOGCHECK_REP(0))
        goto LABEL_211;
      if (!DDS3_PADCHECK_PRESS(5))
        goto LABEL_294;
      if (!DDS3_PADCHECK_PRESS(7))
      {
LABEL_294:
        if (!DDS3_PADCHECK_PRESS(5))
          goto LABEL_295;
        if (!DDS3_PADCHECK_PRESS(6))
        {
LABEL_295:
          if (!DDS3_PADCHECK_PRESS(4))
            goto LABEL_296;
          if (!DDS3_PADCHECK_PRESS(7))
          {
LABEL_296:
            if (!DDS3_PADCHECK_PRESS(4))
              goto LABEL_297;
            if (!DDS3_PADCHECK_PRESS(6))
            {
LABEL_297:
              if (!DDS3_PADCHECK_PRESS(5))
              {
                if (!DDS3_PADCHECK_PRESS(4))
                {
                  if (!DDS3_PADCHECK_PRESS(7))
                  {
                    if (DDS3_PADCHECK_PRESS(6))
                    {
LABEL_289:
                      goto LABEL_191;
                    }
LABEL_211:
                    if (AutoMapResetFlg)
                    {
                      if (!AutoMapGuidFlg)
                      {
                        ButtonGuideDispSet("AUTO02", 0, 0, 90);
                        AutoMapGuidFlg = 1;
                      }
                    }
                    fldAutoMapGetBBox(&getZ0 + 1, &getZ0, &getX1, &v51);
                    v33 = (1000 * ((*(&getZ0 + 1) + -1000.0) / 1000.0));
                    v34 = (1000 * ((getX1 + 1000.0) / 1000.0));
                    v35 = (1000 * ((*&getZ0 + -1000.0) / 1000.0));
                    *&getZ0 = v35;
                    *(&getZ0 + 1) = v33;
                    v36 = (1000 * ((v51 + 1000.0) / 1000.0));
                    v51 = v36;
                    getX1 = v34;
                    if (v33 > gAmap_OfsX)
                    {
                      gAmap_OfsX = v33;
                    }
                    if (v34 < gAmap_OfsX)
                    {
                      gAmap_OfsX = v34;
                    }
                    if (v36 > gAmap_OfsZ)
                    {
                      gAmap_OfsZ = v36;
                    }
                    if (v35 < gAmap_OfsZ)
                    {
                      gAmap_OfsZ = v35;
                    }
                    sub_854930(&v56, 0);
                    sub_854930(&v56, 1u);
                    sub_854930(&v56, 2u);
                    sub_854710(&v56, 0);
                    sub_854930(&v55, 0);
                    sub_854710(&v56, 1u);
                    sub_854930(&v55, 1u);
                    sub_854710(&v56, 2u);
                    sub_854930(&v55, 2u);
                    else if (DDS3_PADCHECK_PRESS(11))
                    {
                      goto LABEL_264;
                    }
                    set_orthographicSize(_cameraAutoReal, 65.0);
                    set_orthographicSize(_cameraAutoHalf, 65.0);
                    v46 = 1.0;
                    goto LABEL_273;
                  }
LABEL_282:
                  goto LABEL_173;
                }
LABEL_205:
                v28 = gAmap_OfsX - 1000;
LABEL_209:
                gAmap_OfsX = v28;
                goto LABEL_210;
              }
              goto LABEL_197;
            }
LABEL_186:
            v22 = gAmap_OfsX - 1000;
LABEL_190:
            gAmap_OfsX = v22;
LABEL_191:
            v25 = gAmap_OfsZ + 1000;
            goto LABEL_192;
          }
LABEL_168:
          v18 = gAmap_OfsX - 1000;
LABEL_172:
          gAmap_OfsX = v18;
LABEL_173:
          v25 = gAmap_OfsZ - 1000;
LABEL_192:
          gAmap_OfsZ = v25;
LABEL_210:
          AutoMapResetFlg = 1;
          goto LABEL_211;
        }
        goto LABEL_152;
      }
    }
    else
    {
      if (!DDS3_PADCHECK_PRESS(5))
        goto LABEL_298;
      if (!DDS3_PADCHECK_PRESS(7))
      {
LABEL_298:
        if (!DDS3_PADCHECK_PRESS(5))
          goto LABEL_299;
        if (!DDS3_PADCHECK_PRESS(6))
        {
LABEL_299:
          if (!DDS3_PADCHECK_PRESS(4))
            goto LABEL_300;
          if (!DDS3_PADCHECK_PRESS(7))
          {
LABEL_300:
            if (!DDS3_PADCHECK_PRESS(4))
              goto LABEL_301;
            if (!DDS3_PADCHECK_PRESS(6))
            {
LABEL_301:
              if (!DDS3_PADCHECK_REP(5))
              {
                if (!DDS3_PADCHECK_REP(4))
                {
                  if (!DDS3_PADCHECK_REP(7))
                  {
                    if (DDS3_PADCHECK_REP(6))
                      goto LABEL_289;
                    goto LABEL_211;
                  }
                  goto LABEL_282;
                }
                goto LABEL_205;
              }
LABEL_197:
              v28 = gAmap_OfsX + 1000;
              goto LABEL_209;
            }
            if (!DDS3_PADCHECK_REP(6))
              goto LABEL_211;
            goto LABEL_186;
          }
          if (!DDS3_PADCHECK_REP(7))
            goto LABEL_211;
          goto LABEL_168;
        }
        if (!DDS3_PADCHECK_REP(6))
          goto LABEL_211;
LABEL_152:
        v22 = gAmap_OfsX + 1000;
        goto LABEL_190;
      }
      if (!DDS3_PADCHECK_REP(7))
        goto LABEL_211;
    }
    v18 = gAmap_OfsX + 1000;
    goto LABEL_172;
  }
}

// 0xf94400
bool fldAutoMapChkChild(void *childObj, s32 num1, s32 num2, s32 num3) {
  s32 v8;
  u64 *v9;
  u64 *v10;
  u64 *v11;
  Il2CppObject *v13;
  struct UnityEngine_GameObject_o *v17;
  UnityEngine_Object_o *v18;
  s32 v21;
  s32 v22;
  s32 v23;

  if (num3 < 1)
    return 1;
  v8 = 0;
  while (1)
  {
    v23 = num1;
    v9 = sub_8D3950(s32, &v23);
    v22 = num2;
    v10 = sub_8D3950(s32, &v22);
    v21 = v8;
    v11 = sub_8D3950(s32, &v21);
    v13 = Format_5268688("{0:D3}{1:D3}{2:D3}", v9, v10, v11);
    if (fldAutoMap_childIcon___ContainsKey(_autoMapIconFld, v13))
    {
      v17 = fldAutoMap_childIcon___get_Item(_autoMapIconFld, v13).childObj;
      v18 = v17;
      if (op_Equality(v18, childObj, 0))
        break;
    }
    if (++v8 >= num3)
      return 1;
  }
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
        goto LABEL_45;
      }
      v18 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
      v19 = v7 - 40LL;
      if (v19 < LODWORD(v18->max_length))
        goto LABEL_32;
LABEL_31:
    }
    if ((v7 & 0xFFFFFFFE) == 0x3C)
    {
      amapEX_Ver7 = DDS3_GBWK->amapEX_Ver7;
      goto LABEL_30;
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
        goto LABEL_44;
    }
    else
    {
      v14 = DDS3_GBWK->fldSave->amap->blkOpenFlg;
      if (v8 < LODWORD(v14->max_length))
      {
LABEL_44:
        v12 = &v14->obj.klass + v8;
        goto LABEL_45;
      }
    }
  }
  if ((v7 & 0xFFFFFFFE) != 0x3C)
    return 0;
  amapEX_Ver7 = DDS3_GBWK->amapEX;
LABEL_30:
  v18 = amapEX_Ver7->blkOpenFlg;
  v19 = v7 - 60LL;
  if (v19 >= LODWORD(v18->max_length))
    goto LABEL_31;
LABEL_32:
  v12 = &v18->obj.klass + v19;
LABEL_45:
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
      goto LABEL_53;
    }
    v11 = SBlock - 33;
    if (v9 >= 40)
    {
      if ((v7 & 0xFFFFFFFE) != 0x3C)
        return;
      v13 = DDS3_GBWK->amapEX_Ver7->blkOpenFlg;
      v14 = v7 - 60LL;
      if (v14 < LODWORD(v13->max_length))
        goto LABEL_40;
    }
    else
    {
      if (v9 >= 30)
      {
        v13 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
        v14 = v7 - 40LL;
        if (v14 < LODWORD(v13->max_length))
          goto LABEL_40;
      }
      else
      {
        v13 = DDS3_GBWK->amap_Ver7->blkOpenFlg;
        v14 = v9;
        if (v9 < LODWORD(v13->max_length))
        {
LABEL_40:
          v28 = v13->m_Items[v14];
          v26 = v28 + 4 * v10;
          v30 = *(v26 + 32);
          v31 = 1 << v11;
LABEL_53:
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
  u32 v7;
  f32 fldAutoMapDrawIconOfsRF_alpcnt;
  f32 v10;
  u32 v11;
  u32 v12;
  u64 *v13;
  struct AMAP_MK_t_array *amap_mktbl;
  s32 u;
  s32 v;
  s32 w;
  s32 h;
  s32 aU2;
  s32 aV1;
  f32 v32;
  s32 aU1;
  s32 aV2;
  s32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  sdfGrOt_t_o *Ot;
  UnityEngine_Vector4_o v54;
  UnityEngine_Vector4_o v55;
  UnityEngine_Vector4_o v56;
  UnityEngine_Vector4_o p;

  v7 = -2139062144;
  *&p.x = 0;
  *&p.z = 0;
  *&v56.x = 0;
  *&v56.z = 0;
  *&v55.x = 0;
  *&v55.z = 0;
  *&v54.x = 0;
  *&v54.z = 0;
  if (tex == 1)
  {
    v10 = sdfSin(fldAutoMapDrawIconOfsRF_alpcnt);
    v11 = vcvts_n_s32_f32(v10, 6u);
    v12 = vcvts_n_u32_f32(v10, 6u);
    if ((v10 * 64.0) >= 0.0)
      v11 = v12;
    v7 = (v11 << 24) | 0x80808080;
    fldAutoMapDrawIconOfsRF_alpcnt = fldAutoMapDrawIconOfsRF_alpcnt
                                                                       + 0.2;
  }
  v13 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v13);
  sdfDrawTagInit(v13);
  sdf2DLinkTexPacket(v13, fldIFTexHandle1, 0);
  u = amap_mktbl->m_Items[tex]->u;
  v = amap_mktbl->m_Items[tex]->v;
  w = amap_mktbl->m_Items[tex]->w;
  h = amap_mktbl->m_Items[tex]->h;
  sub_854930(&p, 0);
  sub_854930(&p, 1u);
  sub_854930(&p, 2u);
  sub_854710(&p, 0);
  sub_854930(&v54, 0);
  sub_854930(&v54, 1u);
  sub_854710(&p, 2u);
  sub_854930(&v54, 2u);
  sub_854710(&v54, 0);
  sub_854930(&v56, 0);
  sub_854930(&v56, 1u);
  sub_854710(&p, 2u);
  sub_854930(&v56, 2u);
  sub_854710(&p, 0);
  sub_854930(&v55, 0);
  sub_854930(&v55, 1u);
  sub_854710(&v54, 2u);
  sub_854930(&v55, 2u);
  aU2 = 16 * u;
  aV1 = 16 * v;
  v32 = OOYRAD(r + 180.0);
  aU1 = aU2 + 16 * w;
  aV2 = aV1 + 16 * h;
  SetRotateMatrixY(v32);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(v56);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v56);
  SDF_VU0__LOADVECTOR(v55);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v55);
  SDF_VU0__LOADVECTOR(v54);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v54);
  sub_854710(&p, 2u);
  sub_854930(&p, 2u);
  sub_854710(&p, 0);
  sub_854930(&p, 0);
  sub_854710(&p, 2u);
  sub_854930(&p, 2u);
  sub_854710(&v56, 2u);
  sub_854930(&v56, 2u);
  sub_854710(&v56, 0);
  sub_854930(&v56, 0);
  sub_854710(&v56, 2u);
  sub_854930(&v56, 2u);
  sub_854710(&v55, 2u);
  sub_854930(&v55, 2u);
  sub_854710(&v55, 0);
  sub_854930(&v55, 0);
  sub_854710(&v55, 2u);
  sub_854930(&v55, 2u);
  sub_854710(&v54, 2u);
  sub_854930(&v54, 2u);
  sub_854710(&v54, 0);
  sub_854930(&v54, 0);
  sub_854710(&v54, 2u);
  sub_854930(&v54, 2u);
  v36 = SDF_GS_SET_ALPHA(0, 1, 0, 1, 0);
  sub_854710(&p, 0);
  v38 = v37;
  sub_854710(&p, 2u);
  v40 = v39;
  sub_854710(&v56, 0);
  v42 = v41;
  sub_854710(&v56, 2u);
  v44 = v43;
  sub_854710(&v55, 0);
  v46 = v45;
  sub_854710(&v55, 2u);
  v48 = v47;
  sub_854710(&v54, 0);
  v50 = v49;
  sub_854710(&v54, 2u);
  sdfPrimLinkFt4(v13, v7, v36, v38, v40, aU2, aV1, v42, v44, aU1, aV1, v46, v48, aU2, aV2, v50, v51, aU1, aV2, 0, 0);
  Ot = fldDrawGetOt();
  sdfDrawTagLinkOt(Ot, v13);
}

// 0xf93220
void fldAutoMapDrawIconOfsRForUnity(s32 tex, s32 AmArea, s32 nodeIdx, s32 loop2, s32 loop3) {
  System_Array_o *v9;
  u64 *v11;
  s64 *v12;
  s64 *v22;
  UnityEngine_Object_o *AutoMapObjArea;
  struct UnityEngine_GameObject_array_array *mapNodeList2Area;
  s32 max_length;
  struct UnityEngine_GameObject_array_array *v39;
  UnityEngine_GameObject_array *v41;
  UnityEngine_GameObject_o *v43;
  s32 fieldID;
  s64 v48;
  u32 v50;
  System_String_o **v66;
  System_String_o *v67;
  System_String_o *v69;
  UnityEngine_Transform_o *Child;
  char *v74;
  s32 *v75;
  s32 v76;
  UnityEngine_Camera_o *cameraMain;
  UnityEngine_Camera_o *cameraAutoReal;
  UnityEngine_RenderTexture_o *targetTexture;
  u64 *v82;
  u64 *v83;
  u64 *v84;
  System_String_o *v85;
  bool v87;
  struct UnityEngine_GameObject_o *iconObj;
  fldAutoMap_childIcon_o Item;
  struct UnityEngine_GameObject_array *autoMapIconTbl;
  s64 v93;
  Il2CppObject *v95;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v98;
  UnityEngine_Transform_o *v99;
  s32 v102;
  s32 v103;
  s32 v104;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v106;
  UnityEngine_Vector3_o v107;
  UnityEngine_Vector3_o localPosition;
  fldAutoMap_childIcon_o v109;
  UnityEngine_Vector3_o v110;
  UnityEngine_Vector3_o v111;

  v9 = NewSpecific(s32, 0x10u);
  InitializeArray_1543888(v9, Field__PrivateImplementationDetails__BFC0960F5E143BC46015AF1488B9B6CC1592064E);
  v11 = NewSpecific(string, 0x10u);
  v12 = "";
  v11[4] = "";
  v11[5] = "";
  v11[6] = "ex";
  v11[7] = "jk";
  v11[8] = "kf";
  v11[9] = "sv";
  v11[10] = "";
  v11[11] = "rg";
  v22 = "";
  v11[12] = "";
  v11[13] = "";
  v11[14] = "ev";
  v11[15] = "up";
  v11[16] = "dn";
  v11[17] = "";
  v11[18] = "im";
  v11[19] = "zz";
  if (!op_Equality(AutoMapObjArea, 0, 0))
  {
    max_length = mapNodeList2Area->max_length;
    if (max_length > AmArea)
    {
      if (SLODWORD(mapNodeList2Area->m_Items[AmArea]->max_length) > nodeIdx)
      {
        v39 = mapNodeList2Area;
        v41 = v39->m_Items[AmArea];
        v43 = v41->m_Items[nodeIdx];
        if (!op_Equality(v43, 0, 0))
        {
          fieldID = fldGb->fieldID;
          if (fieldID == 60)
            goto LABEL_104;
          if (fieldID == 61)
          {
LABEL_104:
            v48 = tex;
            v50 = *(&v9[2].klass + tex);
            if (v50 <= 7 && ((1 << v50) & 0xB7) != 0)
              return;
          }
          else
          {
            v48 = tex;
          }
          v66 = &"xx";
          if (tex != 14)
            v66 = &"";
          v67 = *v66;
          v69 = v11[v48 + 4];
          Child = fldAutoMapGetChild(v43, v69, v67, AmArea, loop2, loop3);
          if (!op_Equality(Child, 0, 0))
          {
            v74 = v9 + 4 * v48;
            v76 = *(v74 + 8);
            v75 = (v74 + 32);
            if ((v76 & 0x80000000) == 0)
            {
              cameraMain = _cameraMain;
              cameraAutoReal = _cameraAutoReal;
              position = get_position(Child);
              v106 = WorldToViewportPoint_27174800(cameraAutoReal, position);
              v111.x = v106.x;
              v111.y = v106.y;
              v111.z = 0.0;
              ViewportToScreenPoint(cameraMain, v111);
              targetTexture = get_targetTexture(cameraAutoReal);
              (targetTexture->klass->vtable._6_get_height.methodPtr)(
                targetTexture,
                targetTexture->klass->vtable._6_get_height.method);
              v107 = WorldToScreenPoint_27174640(cameraAutoReal, position);
              v104 = AmArea;
              v82 = sub_8D3950(s32, &v104);
              v103 = loop2;
              v83 = sub_8D3950(s32, &v103);
              v102 = loop3;
              v84 = sub_8D3950(s32, &v102);
              v85 = Format_5268688("{0:D3}{1:D3}{2:D3}", v82, v83, v84);
              v87 = fldAutoMap_childIcon___ContainsKey(_autoMapIconFld, v85);
              if (v87)
              {
                Item = fldAutoMap_childIcon___get_Item(_autoMapIconFld, v85);
                iconObj = Item.iconObj;
                  goto LABEL_161;
              }
              else
              {
                autoMapIconTbl = _autoMapIconTbl;
                v93 = *v75;
                v95 = autoMapIconTbl->m_Items[v93];
                transform = get_transform(
                              _autoMapUI->icon_Base,
                              0);
                {
                }
                iconObj = Instantiate_object__425664(v95, transform, 0);
                v109.childObj = get_gameObject(Child);
                v109.iconObj = iconObj;
                fldAutoMap_childIcon___Add(_autoMapIconFld, v85, v109);
                  goto LABEL_161;
              }
LABEL_161:
              v98 = get_transform(
                      *(*(Item.iconObj[7].m_CachedPtr + 88) + 112LL),
                      0);
              localPosition = get_localPosition(v98);
              v99 = get_transform(iconObj, 0);
              v110.x = v107.x - localPosition.x;
              v110.y = v107.y + localPosition.y;
              v110.z = v107.z;
              set_localPosition(v99, v110);
            }
          }
        }
      }
    }
  }
}

// 0xf8ddb0
void fldAutoMapDrawMdl1(sdfModelRootNode_t *modelRoot, f32 x, f32 y, f32 z) {
  struct sdfModelNode_t_array *items;
  struct sdfModelOt_t_array *dds3ModelOt;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;
  sdfModelNode_t_o *aNode;
  sdfModelRootNode_t_o *aRoot;

  aRoot = modelRoot;
  *&v14.z = 0;
  aNode = 0;
  *&v13.z = 0;
  *&v14.x = 0;
  *&v13.x = 0;
  sub_854690(&v14.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v13.x, 0.0, 0.0, 0.0, 0.0);
  items = modelRoot->nodeList->items;
  aNode = items->m_Items[0];
  sub_854930(&v14, 0);
  sub_854930(&v14, 1u);
  sub_854930(&v14, 2u);
  sub_854930(&v14, 3u);
  SDF_VU0__LOADVECTOR(v14);
  SDF_VU0__VECTOR_W_SET_ONE();
  SDF_VU0__STOREVECTOR(&v13);
  sub_1A00AD0(&modelRoot->tm, 3u);
  sdfModelMakeLocalTm(&aNode);
  sdfModelEvalTm(&aRoot);
  sdfModelLinkOt(&dds3ModelOt->m_Items[9], &aRoot);
}

// 0xf8e4e0
void fldAutoMapDrawOneArea(void) {
  __int128 v2;
  long f64 v3;
  __int128 v4;
  fldAutoMap_c *v5;
  s32 FloorMax;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  s64 v19;
  s64 v20;
  fldAutoMap_c *v24;
  s16 v26;
  s32 v27;
  s32 FloorNext;
  fldAutoMap_c *v32;
  s16 v34;
  s32 v35;
  s32 FloorPrev;
  fldAutoMap_c *v39;
  s32 fldAutoMapDrawOneArea_nalp;
  s32 fldAutoMapDrawOneArea_iny;
  s32 v45;
  f32 fldAutoMapDrawOneArea_oy;
  s16 v48;
  s32 v49;
  f32 v51;
  f32 v52;
  s64 v56;
  s64 v57;
  s64 v58;
  sdf3DScreenParam_t_o *dds3ScreenParam;
  s64 v60;
  s64 v61;
  s64 v62;
  s64 v63;
  bool v67;
  UnityEngine_GameObject_o *v69;
  fldAutoMap_c *v73;
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v76;
  Il2CppClass **v78;
  const char *namespaze;
  u64 v80;
  const char *v83;
  const char *v84;
  s64 v85;
  s32 v86;
  s32 v89;
  s64 v91;
  u64 v92;
  s64 v93;
  s64 v96;
  u32 v97;
  bool v98;
  s32 v99;
  f32 v102;
  f32 v104;
  f32 v106;
  UnityEngine_GameObject_o *AutoMapObjHalf;
  fldAutoMap_c *v110;
  s32 v112;
  struct fldAmAreaData_t_array *v113;
  u64 v114;
  s64 v116;
  s64 v117;
  s64 v118;
  s64 v119;
  u64 v120;
  s64 v121;
  s32 v124;
  s32 v127;
  fldAutoMap_c *v128;
  s32 v129;
  struct sdfModelRootNode_t_array *v130;
  sdfModelRootNode_t_o *v132;
  struct sdfModelRootNode_t_array *pfldAmRootNode;
  struct sdfModelRootNode_t_array *v138;
  UnityEngine_Object_o *v142;
  struct UnityEngine_GameObject_array_array *mapNodeList2Half;
  struct fldAmAreaData_t_array *v159;
  u64 v160;
  s32 v161;
  s64 v164;
  s64 v165;
  s64 v166;
  s64 v167;
  u64 v168;
  s64 v169;
  s32 v173;
  s32 v175;
  struct sdfModelRootNode_t_array *v178;
  sdfModelRootNode_t_o *v180;
  s64 v182;
  u64 v183;
  struct sdfModelRootNode_t_array *v185;
  struct sdfModelRootNode_t_array *v188;
  UnityEngine_Object_o *AutoMapObjArea;
  struct UnityEngine_GameObject_array_array *mapNodeList2Area;
  fldAutoMap_c *v214;
  u64 v216;
  struct fldAmAreaData_t_array *v217;
  s32 v218;
  Il2CppClass **v219;
  s64 v221;
  s64 v222;
  s64 v223;
  s64 v224;
  u64 v225;
  s64 v226;
  s32 v230;
  struct sdfModelRootNode_t_array *v234;
  sdfModelRootNode_t_o *v236;
  struct sdfModelRootNode_t_array *v239;
  struct sdfModelRootNode_t_array *v242;
  struct sdfModelRootNode_t_array *v246;
  struct sdfModelRootNode_t_array *v250;
  struct sdfModelRootNode_t_array *v254;
  s64 v259;
  u64 v260;
  s64 v261;
  s32 v264;
  s32 v266;
  struct sdfModelRootNode_t_array *v268;
  u64 v271;
  s64 v272;
  s32 v275;
  struct sdfModelRootNode_t_array *v277;
  struct sdfModelRootNode_t_array *v281;
  struct sdfModelRootNode_t_array *v284;
  struct sdfModelRootNode_t_array *v286;
  s64 v291;
  sdf3DScreenParam_t_o *v292;
  s64 v293;
  s64 v294;
  s64 v295;
  s64 v296;
  s64 v297;
  s64 v298;
  s32 v307;
  f32 x;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v313;
  fldAutoMap_c *v316;
  s32 gAmap_NowField;
  struct fldAmAreaData_t_array *v319;
  s64 v320;
  u64 v321;
  struct DLCAmIcon_t_array *DLCAmIcon;
  u64 max_length_low;
  s32 v325;
  struct DLCAmIcon_t_array *v328;
  struct DLCAmIcon_t_array *v332;
  struct DLCAmIcon_t_array *v336;
  u64 v339;
  Il2CppClass **v341;
  const char *v342;
  u64 v343;
  const char *v346;
  const char *v347;
  s64 v348;
  s32 v350;
  s64 v352;
  u64 v353;
  s64 v354;
  s64 v357;
  __int128 v358;
  f32 fldAutoMapDrawOneArea_npccntf;
  f32 v361;
  f32 v362;
  s64 v364;
  f32 v365;
  f32 v366;
  f32 v368;
  f32 v370;
  s32 v372;
  s32 v375;
  f32 v378;
  f32 v379;
  struct fldGlobalWork_t_o *fldGb;
  f32 v381;
  f32 v382;
  f32 v383;
  s16 v386;
  f32 v387;
  f32 v388;
  s32 v389;
  UnityEngine_GameObject_o *v391;
  UnityEngine_GameObject_o *v392;
  struct fldGlobalWork_t_o *v393;
  f32 v394;
  f32 v395;
  f32 v396;
  f32 playerX;
  f32 ooyCamKakudo;
  UnityEngine_GameObject_o *v407;
  UnityEngine_Transform_o *v408;
  UnityEngine_Transform_o *v409;
  s64 v411;
  UnityEngine_Transform_o *v412;
  f32 v413;
  UnityEngine_Transform_o *v414;
  UnityEngine_Transform_o *v415;
  UnityEngine_GameObject_o *playerObj;
  UnityEngine_GameObject_o *darkzone;
  s32 v427;
  s32 v429;
  UnityEngine_Animator_o *stairs_up;
  System_String_o *v432;
  s32 v433;
  s32 v436;
  s32 v438;
  UnityEngine_Animator_o *stairs_down;
  System_String_o *v441;
  s32 v442;
  f32 fldAutoMapDrawOneArea_scrcntf;
  f32 v448;
  f32 v449;
  f32 v450;
  struct UnityEngine_GameObject_array *v452;
  UnityEngine_GameObject_o *v454;
  UnityEngine_GameObject_o *v455;
  bool v456;
  struct UnityEngine_GameObject_array *dir;
  UnityEngine_GameObject_o *v459;
  s16 v462;
  s32 v463;
  struct UnityEngine_GameObject_array *v465;
  UnityEngine_GameObject_o *v467;
  UnityEngine_GameObject_o *v468;
  bool v469;
  struct UnityEngine_GameObject_array *v470;
  UnityEngine_GameObject_o *v472;
  s16 v475;
  s32 v476;
  struct UnityEngine_GameObject_array *v478;
  UnityEngine_GameObject_o *v480;
  UnityEngine_GameObject_o *v481;
  bool v482;
  struct UnityEngine_GameObject_array *v483;
  UnityEngine_GameObject_o *v485;
  s16 v488;
  s32 v489;
  struct UnityEngine_GameObject_array *v491;
  UnityEngine_GameObject_o *v493;
  UnityEngine_GameObject_o *v494;
  bool v495;
  struct UnityEngine_GameObject_array *v496;
  UnityEngine_GameObject_o *v498;
  System_String_o *FieldName;
  TMPro_TMP_Text_o *fldName;
  System_Object_array *v505;
  System_Object_array *v506;
  s64 *v507;
  s64 *v509;
  System_String_o *v511;
  s32 fldAutoMapDrawOneArea_ofloor;
  struct System_Int16_array *am_floorSL;
  s16 v520;
  s32 v521;
  struct TMPro_TextMeshProUGUI_array *areaName;
  UnityEngine_GameObject_o *v526;
  UnityEngine_Transform_o *v527;
  s32 fldAutoMapDrawOneArea_ioy;
  s32 v530;
  struct TMPro_TextMeshProUGUI_array *v531;
  TMPro_TMP_Text_o *v533;
  System_String_o *FloorName;
  System_Object_array *v536;
  s64 *v537;
  s64 *v539;
  System_String_o *v542;
  struct TMPro_TextMeshProUGUI_array *v543;
  long f64 v545;
  long f64 v546;
  long f64 v547;
  struct TMPro_TextMeshProUGUI_array *v548;
  struct TMPro_TextMeshProUGUI_array *v550;
  UnityEngine_Transform_o *v552;
  struct TMPro_TextMeshProUGUI_array *v554;
  f32 v555;
  UnityEngine_Transform_o *v557;
  s32 v560;
  struct System_Int16_array *v561;
  s16 v564;
  s32 v565;
  s32 v567;
  s32 v568;
  struct TMPro_TextMeshProUGUI_array *v569;
  TMPro_TMP_Text_o *v571;
  System_String_o *v573;
  System_Object_array *v574;
  s64 *v575;
  s64 *v577;
  System_String_o *v580;
  struct TMPro_TextMeshProUGUI_array *v581;
  long f64 v583;
  long f64 v584;
  long f64 v585;
  struct TMPro_TextMeshProUGUI_array *v586;
  struct TMPro_TextMeshProUGUI_array *v588;
  UnityEngine_Transform_o *v590;
  struct TMPro_TextMeshProUGUI_array *v592;
  f32 v593;
  UnityEngine_Transform_o *v595;
  s64 v598;
  s64 v599;
  s64 v600;
  s64 v601;
  s64 v602;
  s64 v603;
  s64 v604;
  s32 fldAutoMapDrawOneArea_floor;
  struct fldAmAreaData_t_array *v606;
  s32 v607;
  char *v608;
  char *v609;
  UnityEngine_Matrix4x4_o v610;
  UnityEngine_Matrix4x4_o v611;
  UnityEngine_Matrix4x4_o v612;
  UnityEngine_Matrix4x4_o v613;
  UnityEngine_Matrix4x4_o v614;
  s64 getZ1;
  s64 getZ0;
  UnityEngine_Vector3_o value;
  s64 v618;
  f32 v619;
  UnityEngine_Vector3_o v620;
  UnityEngine_Vector3_o v621;
  UnityEngine_Vector3_o v622;
  UnityEngine_Vector4_o dst;
  s64 getZ;
  u64 y2[2];
  UnityEngine_Vector3_o v626;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v628;
  UnityEngine_Vector3_o v629;
  UnityEngine_Vector3_o v630;
  UnityEngine_Quaternion_o v631;
  UnityEngine_Quaternion_o v632;

  v622.z = 0.0;
  *&v622.x = 0;
  v621.z = 0.0;
  *&v621.x = 0;
  v620.z = 0.0;
  *&v620.x = 0;
  v619 = 0.0;
  v618 = 0;
  value.z = 0.0;
  getZ1 = 0;
  getZ0 = 0;
  *&value.x = 0;
  getZ = 0;
  y2[0] = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  if (!fldDbg->NoClip)
    goto LABEL_14;
LABEL_6:
  else if (!DDS3_PADCHECK_PRESS(9))
  {
    goto LABEL_20;
  }
  else if (DDS3_PADCHECK_TRIG(11))
  {
LABEL_28:
    ++dbgfull;
    goto LABEL_32;
  }
LABEL_20:
  if (DDS3_PADCHECK_PRESS(11))
  {
    if (DDS3_PADCHECK_TRIG(9))
      goto LABEL_28;
  }
LABEL_32:
  dbgfull &= 1u;
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_15:
  }
LABEL_36:
  if (dbgfull)
  {
    fldDbgPrintStr2DC(0, 0, -1, "FullOpen", 20);
  }
  else
  {
    deleteFldMenuSub(20);
  }
  FloorMax = fldAutoMapGetFloorMax();
  frSetFontDrawOT(0x51u);
  v14 = *&dds3HCameraTM.m00;
  v15 = *&dds3HCameraTM.m20;
  v16 = *&dds3HCameraTM.m21;
  *&v614.m01 = *&dds3HCameraTM.m01;
  *&v614.m21 = v16;
  *&v614.m00 = v14;
  *&v614.m20 = v15;
  v17 = *&dds3HCameraTM.m02;
  v18 = *&dds3HCameraTM.m22;
  v20 = *&dds3HCameraTM.m03;
  v19 = *&dds3HCameraTM.m23;
  *&v614.m03 = v20;
  *&v614.m23 = v19;
  *&v614.m02 = v17;
  *&v614.m22 = v18;
  SDF_VU0__LOADMATRIX(&v614);
  InversMatrix();
  fldAutoMapDrawOneArea_floor = gAmap_NowFloor;
  else if (!DDS3_PADCHECK_TRIG(8))
  {
    goto LABEL_90;
  }
  if (fldAutoMapDrawOneArea_floor < FloorMax)
  {
    v26 = *&v24->_2.bitflags1;
    if ((v26 & 0x200) != 0)
    {
      v27 = v26 & 0x200;
      if (dbgfull)
      {
LABEL_66:
        FloorNext = fldAutoMapDrawOneArea_floor + 1;
        if ((v24->_2.bitflags2 & 2) == 0)
          goto LABEL_82;
LABEL_70:
LABEL_82:
        if (fldAutoMapDrawOneArea_floor == FloorNext)
          goto LABEL_90;
        goto LABEL_83;
      }
    }
    else
    {
      v27 = 0;
      if (dbgfull)
        goto LABEL_66;
    }
    FloorNext = fldAutoMapGetFloorNext(fldAutoMapDrawOneArea_floor);
      goto LABEL_82;
    goto LABEL_70;
  }
LABEL_90:
  else if (!DDS3_PADCHECK_TRIG(10))
  {
    goto LABEL_123;
  }
  if (fldAutoMapDrawOneArea_floor >= 2)
  {
    v34 = *&v32->_2.bitflags1;
    if ((v34 & 0x200) != 0)
    {
      v35 = v34 & 0x200;
      if (dbgfull)
      {
LABEL_99:
        FloorPrev = fldAutoMapDrawOneArea_floor - 1;
        if ((v32->_2.bitflags2 & 2) == 0)
          goto LABEL_115;
LABEL_103:
LABEL_115:
        if (fldAutoMapDrawOneArea_floor == FloorPrev)
          goto LABEL_123;
        goto LABEL_116;
      }
    }
    else
    {
      v35 = 0;
      if (dbgfull)
        goto LABEL_99;
    }
    FloorPrev = fldAutoMapGetFloorPrev(fldAutoMapDrawOneArea_floor);
      goto LABEL_115;
    goto LABEL_103;
  }
LABEL_123:
  else
  {
    if (fldAutoMapDrawOneArea_nalp > 127)
      goto LABEL_130;
  }
  fldAutoMapDrawOneArea_nalp = fldAutoMapDrawOneArea_nalp + 16;
LABEL_130:
  else
  {
    if ((fldAutoMapDrawOneArea_iny & 0x80000000) == 0)
      goto LABEL_133;
  }
  fldAutoMapDrawOneArea_iny = fldAutoMapDrawOneArea_iny + 4;
  fldAutoMapDrawOneArea_ioy += 4;
  if ((v39->_2.bitflags2 & 2) == 0)
  {
LABEL_144:
    v45 = fldAutoMapDrawOneArea_iny;
    if (v45 < 1)
      goto LABEL_149;
    goto LABEL_145;
  }
LABEL_134:
    goto LABEL_144;
  v45 = fldAutoMapDrawOneArea_iny;
  if (v45 < 1)
    goto LABEL_149;
LABEL_145:
  fldAutoMapDrawOneArea_iny = v45 - 4;
  fldAutoMapDrawOneArea_ioy -= 4;
LABEL_149:
  if (fldAutoMapDrawOneArea_oy < 1000.0)
  {
    else if (fldAutoMapDrawOneArea_oy > -1000.0)
    {
      goto LABEL_156;
    }
  }
  v48 = *&v39->_2.bitflags1;
  if ((v48 & 0x200) != 0)
  {
    v49 = v48 & 0x200;
  }
  else
  {
    v49 = 0;
  }
  v51 = fldAutoMapDrawOneArea_oy;
  if (v51 > 0.0)
  {
    v52 = -500.0;
    fldAutoMapDrawOneArea_oy = v51 + -500.0;
    goto LABEL_178;
  }
  else if (v51 < 0.0)
  {
    goto LABEL_174;
  }
  if (!v49)
  {
LABEL_183:
    fldAutoMapDrawOneArea_oy = 0.0;
    if ((v39->_2.bitflags2 & 2) == 0)
      goto LABEL_184;
LABEL_179:
    goto LABEL_184;
  }
LABEL_157:
    goto LABEL_183;
  fldAutoMapDrawOneArea_oy = 0.0;
  if ((v39->_2.bitflags2 & 2) != 0)
    goto LABEL_179;
LABEL_184:
  fldAutoMapDrawOneArea_oy = 0.0;
  fldAutoMapDrawOneArea_nalp = 128;
  gAmap_NowFloor = fldAutoMapDrawOneArea_floor;
  v56 = *&dds3HCameraTM.m00;
  v57 = *&dds3HCameraTM.m20;
  v58 = *&dds3HCameraTM.m21;
  *&v613.m01 = *&dds3HCameraTM.m01;
  *&v613.m21 = v58;
  *&v613.m00 = v56;
  *&v613.m20 = v57;
  v60 = *&dds3HCameraTM.m02;
  v61 = *&dds3HCameraTM.m22;
  v63 = *&dds3HCameraTM.m03;
  v62 = *&dds3HCameraTM.m23;
  *&v613.m03 = v63;
  *&v613.m23 = v62;
  *&v613.m02 = v60;
  *&v613.m22 = v61;
  v612 = v613;
  sdf3DSetCamera(dds3ScreenParam, &v612);
  rsetOtOfs(74);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  aDrawBoxF(0, 0, 512, 224, 0, 0, 0, 0);
  rsetOtOfs(75);
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  rsetOtOfs(74);
  rsetTest(1, 1, 128, 1, 0, 0, 1, 1);
  v67 = DDS3_PADCHECK_PRESS(9);
  if (!v67)
  {
    cmpSetupObject(AutoMapObjHalf, 0);
      goto LABEL_353;
    goto LABEL_271;
  }
  v69 = AutoMapObjHalf;
  cmpSetupObject(v69, 1);
  rsetAlpha(0);
  ooyTestRGBMaskOn();
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  if (fldAutoMapDrawOneArea_nalp >= 128)
  {
    v76 = 0;
    if ((v73->_2.bitflags2 & 2) != 0)
    {
LABEL_216:
    }
LABEL_218:
    if (v76 < nfldAmArea)
    {
      v78 = &pfldAmArea->obj.klass + v76;
      namespaze = v78[4]->_1.namespaze;
      v80 = 0;
      v608 = (v78 + 4);
      while (1)
      {
        if (v80 >= *(*v608 + 32LL))
        {
          ++v76;
            goto LABEL_216;
          goto LABEL_218;
        }
        v83 = &namespaze[8 * v80];
        v85 = *(v83 + 4);
        v84 = v83 + 32;
        v86 = *(v85 + 44);
        if (fldAutoMapDrawOneArea_floor - 2 == v86)
          goto LABEL_231;
        if (fldAutoMapDrawOneArea_floor == v86)
        {
LABEL_231:
          v89 = fldAutoMapChkOpen(gAmap_NowField, v76, v80);
          else if (!(dbgfull | v89))
          {
            goto LABEL_222;
          }
          v91 = *(*v84 + 32LL);
          if (v91)
          {
            v92 = 0;
            v93 = v91 + 32;
            if (v80 >= *(namespaze + 6))
            {
LABEL_243:
            }
            while (v92 < *(*v84 + 40LL))
            {
              v96 = *(v93 + 8 * v92);
              v97 = *(v96 + 16);
              v98 = v97 > 9;
              v99 = (1 << v97) & 0x3D2;
              if (!v98 && v99 != 0)
              {
                v102 = *(*(v96 + 24) + 16LL);
                v104 = fldAutoMapDrawOneArea_oy;
                v106 = *(*(*(v93 + 8 * v92) + 24LL) + 24LL);
                fldPoint3To2H(v102 + 0.0, v104, v106 + 0.0, y2 + 1, y2);
              }
              ++v92;
              if (v80 >= *(namespaze + 6))
                goto LABEL_243;
            }
          }
        }
LABEL_222:
        ++v80;
      }
    }
    getZ = 0;
  }
  v112 = fldAutoMapDrawOneArea_floor;
  v113 = pfldAmArea;
  v114 = 0;
  if ((v73->_2.bitflags2 & 2) != 0)
    goto LABEL_280;
LABEL_282:
  if (v114 < nfldAmArea)
  {
    v116 = v113 + 8 * v114;
    v118 = *(v116 + 32);
    v117 = v116 + 32;
    v119 = *(v118 + 24);
    v120 = 0;
    v121 = v119 + 32;
    while (1)
    {
      if (v120 >= *(*v117 + 32LL))
      {
        pfldAmRootNode->m_Items[v114]->color = -2139062144;
        v138 = pfldAmRootNode;
        fldAutoMapDrawMdl1(v138->m_Items[v114], 0.0, fldAutoMapDrawOneArea_oy, 0.0);
        v142 = AutoMapObjHalf;
        if (!op_Equality(v142, 0, 0))
        {
          if (v114 < SLODWORD(pfldAmRootNode->max_length))
          {
            else if (v114 < SLODWORD(mapNodeList2Half->max_length))
            {
              goto LABEL_330;
            }
          }
        }
        ++v114;
        {
LABEL_280:
        }
        goto LABEL_282;
      }
      v124 = *(*(v121 + 8 * v120) + 44LL);
      if (v112 - 2 != v124)
      {
        if (v112 != v124)
          break;
      }
      v127 = fldAutoMapChkOpen(gAmap_NowField, v114, v120);
      v129 = (dbgfull | v127) != 0;
      if ((v128->_2.bitflags2 & 2) != 0)
        goto LABEL_302;
LABEL_305:
      v130 = pfldAmRootNode;
      v132 = v130->m_Items[v114];
      fldAutoMapNodeSet(v132, *(*(v121 + 8 * v120++) + 24LL), v129);
    }
    v129 = 0;
      goto LABEL_305;
LABEL_302:
    goto LABEL_305;
  }
  ooyTestRGBMaskOff();
  rsetAlpha(0);
  rsetTest(1, 0, 128, 1, 1, 1, 1, 1);
  aDrawBoxF(0, 0, 512, 224, 64, 64, 96, 48);
  rsetTest(1, 1, 128, 1, 0, 0, 1, 1);
    goto LABEL_353;
LABEL_271:
LABEL_353:
  v159 = pfldAmArea;
  v160 = 0;
  v161 = fldAutoMapDrawOneArea_floor - 1;
  if ((v110->_2.bitflags2 & 2) != 0)
    goto LABEL_356;
  while (2)
  {
    if (v160 < nfldAmArea)
    {
      v164 = v159 + 8 * v160;
      v166 = *(v164 + 32);
      v165 = v164 + 32;
      v167 = *(v166 + 24);
      v168 = 0;
      v169 = v167 + 32;
LABEL_364:
      if (v168 >= *(*v165 + 32LL))
      {
        ++v160;
        {
LABEL_356:
        }
        continue;
      }
      if (v161 == *(*(v169 + 8 * v168) + 44LL))
      {
        v173 = fldAutoMapChkOpen(gAmap_NowField, v160, v168);
        v175 = (dbgfull | v173) != 0;
      }
      else
      {
        v175 = 0;
      }
      if (v160 == 7 && fldGb->fieldID == 20)
      {
        if (evtBitCheck(1259))
        {
          if (!v168)
            v175 = 0;
            goto LABEL_392;
LABEL_390:
LABEL_392:
          v178 = pfldAmRootNode;
          v180 = v178->m_Items[v160];
          fldAutoMapNodeSet(v180, *(*(v169 + 8 * v168++) + 24LL), v175);
          goto LABEL_364;
        }
        if (v168 == 4 || v168 == 2)
          v175 = 0;
      }
        goto LABEL_390;
      goto LABEL_392;
    }
    break;
  }
  v182 = pfldAmArea;
  v183 = 0;
  if ((v110->_2.bitflags2 & 2) != 0)
  {
LABEL_402:
  }
  while (2)
  {
    if (v183 < nfldAmArea)
    {
      else
      {
        v185 = pfldAmRootNode;
        if (v183 >= LODWORD(v185->max_length))
          goto LABEL_408;
      }
      v185->m_Items[v183]->color = -2139062144;
      v188 = pfldAmRootNode;
      fldAutoMapDrawMdl1(v188->m_Items[v183], 0.0, fldAutoMapDrawOneArea_oy, 0.0);
      if (!op_Equality(AutoMapObjArea, 0, 0))
      {
        if (v183 < SLODWORD(pfldAmRootNode->max_length))
        {
          else if (v183 < SLODWORD(mapNodeList2Area->max_length))
          {
            goto LABEL_425;
          }
        }
      }
      ++v183;
        goto LABEL_402;
      continue;
    }
    break;
  }
  rsetOtOfs(74);
  rsetAlpha(0);
  ooyTestRGBMaskOn();
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  aDrawBoxF(0, 0, 512, 224, 0, 0, 0, 0);
  v216 = 0;
  v217 = pfldAmArea;
  v218 = fldAutoMapDrawOneArea_floor - 1;
  if ((v214->_2.bitflags2 & 2) != 0)
    goto LABEL_455;
  while (2)
  {
    if (v216 < nfldAmArea)
    {
      v221 = v217 + 8 * v216;
      v223 = *(v221 + 32);
      v222 = v221 + 32;
      v224 = *(v223 + 24);
      v225 = 0;
      v226 = v224 + 32;
LABEL_463:
      if (v225 >= *(*v222 + 32LL))
      {
        v239 = pfldAmRootNode;
        v239->m_Items[v216]->color = -2139062144;
        v242 = pfldAmRootNode;
        fldAutoMapDrawMdl1(v242->m_Items[v216], -50.0, fldAutoMapDrawOneArea_oy, 50.0);
        v246 = pfldAmRootNode;
        fldAutoMapDrawMdl1(v246->m_Items[v216], 50.0, fldAutoMapDrawOneArea_oy, 50.0);
        v250 = pfldAmRootNode;
        fldAutoMapDrawMdl1(v250->m_Items[v216], -50.0, fldAutoMapDrawOneArea_oy, -50.0);
        v254 = pfldAmRootNode;
        fldAutoMapDrawMdl1(v254->m_Items[v216], 50.0, fldAutoMapDrawOneArea_oy, -50.0);
        v259 = *(*v222 + 24LL);
        if (v216 == 7)
        {
          v260 = 0;
          v261 = v259 + 32;
          if ((v217->max_length & 0xFFFFFFF8) == 0)
          {
LABEL_515:
          }
          while (v260 < *(*v222 + 32LL))
          {
            v264 = *(*(v261 + 8 * v260) + 44LL);
            v266 = v218 == v264;
            if (fldGb->fieldID == 20)
            {
              if (evtBitCheck(1259))
              {
                v266 = v260 != 0 && v218 == v264;
              }
              else if (v260 == 4 || v260 == 2)
              {
                v266 = 0;
              }
            }
            v268 = pfldAmRootNode;
            v182 = v268->m_Items[7];
            fldAutoMapNodeSet(v182, *(*(v261 + 8 * v260++) + 24LL), v266);
            if ((v217->max_length & 0xFFFFFFF8) == 0)
              goto LABEL_515;
          }
        }
        else
        {
          v271 = 0;
          v272 = v259 + 32;
          if (v216 >= LODWORD(v217->max_length))
          {
LABEL_538:
          }
          while (v271 < *(*v222 + 32LL))
          {
            v275 = v218 == *(*(v272 + 8 * v271) + 44LL);
            v277 = pfldAmRootNode;
            v182 = v277->m_Items[v216];
            fldAutoMapNodeSet(v182, *(*(v272 + 8 * v271++) + 24LL), v275);
            if (v216 >= LODWORD(v217->max_length))
              goto LABEL_538;
          }
        }
        v281 = pfldAmRootNode;
        v281->m_Items[v216]->color = 276856960;
        v284 = pfldAmRootNode;
        fldAutoMapDrawMdl1(v284->m_Items[v216], 0.0, fldAutoMapDrawOneArea_oy, 0.0);
        v286 = pfldAmRootNode;
        v219 = &v286->obj.klass + v216++;
        HIDWORD(v219[4]->_1.element_class) = -2139062144;
        if ((v214->_2.bitflags2 & 2) != 0)
        {
LABEL_455:
        }
        continue;
      }
      if (v218 == *(*(v226 + 8 * v225) + 44LL))
      {
        v230 = fldAutoMapChkOpen(gAmap_NowField, v216, v225);
        v182 = (dbgfull | v230) != 0;
      }
      else
      {
        v182 = 0;
      }
      if (v216 == 7 && fldGb->fieldID == 20)
      {
        if (evtBitCheck(1259))
        {
          if (v225)
          else
            v182 = 0;
            goto LABEL_492;
          goto LABEL_490;
        }
        if (v225 == 4 || v225 == 2)
          v182 = 0;
      }
      {
LABEL_492:
        v234 = pfldAmRootNode;
        v236 = v234->m_Items[v216];
        fldAutoMapNodeSet(v236, *(*(v226 + 8 * v225++) + 24LL), v182);
        goto LABEL_463;
      }
LABEL_490:
      goto LABEL_492;
    }
    break;
  }
  rsetOtOfs(78);
  ooyTestRGBMaskOff();
  rsetAlpha(0);
  rsetTest(1, 0, 128, 1, 1, 1, 1, 1);
  aDrawBoxF(0, 0, 512, 224, 128, 128, 162, 128);
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  v292 = dds3ScreenParam;
  v291 = *&dds3CameraTM.m00;
  v293 = *&dds3CameraTM.m20;
  v294 = *&dds3CameraTM.m21;
  *&v613.m01 = *&dds3CameraTM.m01;
  *&v613.m21 = v294;
  *&v613.m00 = v291;
  *&v613.m20 = v293;
  v295 = *&dds3CameraTM.m02;
  v296 = *&dds3CameraTM.m22;
  v298 = *&dds3CameraTM.m03;
  v297 = *&dds3CameraTM.m23;
  *&v613.m03 = v298;
  *&v613.m23 = v297;
  *&v613.m02 = v295;
  *&v613.m22 = v296;
  v611 = v613;
  sdf3DSetCamera(v292, &v611);
  fldAutoMapDrawOneArea_jointcntf = fldAutoMapDrawOneArea_jointcntf + 0.4;
  fldAutoMapDrawOneArea_npccntf = fldAutoMapDrawOneArea_npccntf + 0.2;
  SDF_VU0__COPYVECTOR(&dst, dds3HCameraTargetPos);
  if (fldAutoMapDrawOneArea_nalp < 128)
    goto LABEL_775;
  LODWORD(v2) = 0;
  sub_8524C0(&v622.x, 0.0, 400.0, 0.0);
  getZ = 0;
  v307 = fldAutoMapDrawOneArea_floor;
  if (v307 == fldGb->AmFloor)
  {
    fldAutoMapGetAreaPos(gAmap_NowArea, &getZ + 1, &getZ);
  }
  x = v622.x;
  v622.x = x - (gAmap_OfsX / 100);
  v622.z = v622.z - (gAmap_OfsZ / 100);
  transform = get_transform(cameraAutoRealObj, 0);
  set_localPosition(transform, v622);
  v622.x = v622.x + 2000.0;
  v313 = get_transform(cameraAutoHalfObj, 0);
  set_localPosition(v313, v622);
  v607 = fldAutoMapDrawOneArea_floor - 1;
  if (gAmap_NowField == 60)
    goto LABEL_592;
  v319 = pfldAmArea;
  if (gAmap_NowField != 61)
  {
LABEL_625:
    v339 = 0;
    v606 = v319;
    if ((v316->_2.bitflags2 & 2) != 0)
      goto LABEL_628;
    while (1)
    {
      if (v339 >= nfldAmArea)
        goto LABEL_694;
      v341 = &v319->obj.klass + v339;
      v342 = v341[4]->_1.namespaze;
      v343 = 0;
      v609 = (v341 + 4);
      while (v343 < *(*v609 + 32LL))
      {
        v346 = &v342[8 * v343];
        v348 = *(v346 + 4);
        v347 = v346 + 32;
        if (v607 == *(v348 + 44))
        {
          v350 = fldAutoMapChkOpen(gAmap_NowField, v339, v343);
          else if (!(dbgfull | v350))
          {
            goto LABEL_634;
          }
          v352 = *(*v347 + 32LL);
          if (v352)
          {
            v353 = 0;
            v354 = v352 + 32;
            if (v343 >= *(v342 + 6))
            {
LABEL_652:
            }
            while (v353 < *(*v347 + 40LL))
            {
              v357 = v182;
              v358 = v4;
              v4 = v2;
              v182 = 11;
              switch (*(*(v354 + 8 * v353) + 16LL))
              {
                case 1:
                  v4 = v2;
                  v182 = 10;
                  goto LABEL_675;
                case 2:
                  goto LABEL_675;
                case 3:
                  v182 = 12;
                  goto LABEL_674;
                case 4:
                  v4 = v2;
                  v182 = 5;
                  goto LABEL_675;
                case 5:
                  v182 = 2;
                  goto LABEL_674;
                case 6:
                  v182 = 4;
                  goto LABEL_674;
                case 7:
                  v182 = 6;
                  goto LABEL_674;
                case 8:
                  v182 = 7;
                  goto LABEL_674;
                case 9:
                  v182 = 3;
                  goto LABEL_674;
                case 0xA:
                  v182 = 14;
                  goto LABEL_674;
                case 0xB:
                  *&v4 = sdfSin(((v339 + v353) * 3.3) + fldAutoMapDrawOneArea_npccntf, 0) * 30.0;
                  v182 = 13;
                  goto LABEL_675;
                case 0xC:
                  v182 = 15;
LABEL_674:
                  v4 = v2;
LABEL_675:
                  sub_854710(&dst, 0);
                  v362 = v361;
                  v364 = *(*(v354 + 8 * v353) + 24LL);
                  v365 = v361 - (*&v4 + *(v364 + 16));
                  if (v365 >= 0.0)
                    v366 = v362 - (*&v4 + *(v364 + 16));
                  else
                    v366 = -v365;
                  sub_854710(&dst, 2u);
                  v370 = v368 - (*&v4 + *(*(*(v354 + 8 * v353) + 24LL) + 24LL));
                  if (v370 < 0.0)
                    v370 = -v370;
                  if (v366 < 80000.0 && v370 < 80000.0)
                  {
                    v372 = *(*v347 + 24LL);
                    fldAutoMapDrawIconOfsRForUnity(v182, v339, v372, v343, v353);
                  }
                  break;
                default:
                  v4 = v358;
                  v182 = v357;
                  break;
              }
              ++v353;
              if (v343 >= *(v342 + 6))
                goto LABEL_652;
            }
          }
        }
LABEL_634:
        v319 = v606;
        ++v343;
      }
      ++v339;
      {
LABEL_628:
      }
    }
  }
LABEL_592:
  v320 = 4;
  v321 = 0;
  if ((v316->_2.bitflags2 & 2) == 0)
    goto LABEL_597;
LABEL_595:
LABEL_597:
  while (1)
  {
    max_length_low = LODWORD(DLCAmIcon->max_length);
    if (v321 >= max_length_low)
      break;
    else
    {
      v325 = gAmap_NowField;
      if (v321 >= max_length_low)
        goto LABEL_601;
    }
    if (v325 == *(*(&DLCAmIcon->obj.klass + v320) + 16LL))
    {
      v328 = DLCAmIcon;
      if (v607 == *(*(&v328->obj.klass + v320) + 28LL))
      {
        v332 = DLCAmIcon;
        if (fldAutoMapChkOpen(
               gAmap_NowField,
               *(*(&v332->obj.klass + v320) + 20LL),
               *(*(&v332->obj.klass + v320) + 24LL)))
        {
          v336 = DLCAmIcon;
          fldAutoMapDrawIconOfsRForUnity(
            5,
            *(*(&v336->obj.klass + v320) + 20LL),
            *(*(&DLCAmIcon->obj.klass + v320) + 32LL),
            *(*(&DLCAmIcon->obj.klass + v320) + 24LL),
            0);
        }
      }
    }
    v321 = ++v320 - 4;
      goto LABEL_595;
  }
LABEL_694:
  v375 = fldAutoMapDrawOneArea_floor;
  if (v375 == fldGb->AmFloor)
  {
    rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
    rsetAlpha(1);
    sub_854710(&dst, 0);
    v379 = v378;
    v381 = *(&getZ + 1);
    v382 = v379 - (fldGb->playerX + *(&getZ + 1));
    if (v382 >= 0.0)
      v383 = v379 - (fldGb->playerX + *(&getZ + 1));
    else
      v383 = -v382;
    sub_854710(&dst, 2u);
    v388 = v387;
    if ((v386 & 0x200) != 0)
    {
      v389 = v386 & 0x200;
    }
    else
    {
      v389 = 0;
    }
    v393 = fldGb;
    v394 = *&getZ;
    v395 = v388 - (v393->playerZ + *&getZ);
    if (v395 >= 0.0)
      v396 = v388 - (v393->playerZ + *&getZ);
    else
      v396 = -v395;
    playerX = v393->playerX;
    sub_8524C0(
      &v621.x,
      (v381 + playerX) / -100.0,
      fldAutoMapDrawOneArea_oy / 100.0,
      (v394 + v393->playerZ) / -100.0);
    v626 = fldPoint3DTo2DPlayer(_cameraAutoReal, _cameraMain, v621);
    if (v383 >= 80000.0 || v396 >= 80000.0)
    {
      playerObj = _autoMapUI->playerObj;
      cmpSetupObject(playerObj, 0);
      cmpSetupObject(_autoMapUI->cameraObj, 0);
    }
    else
    {
      rsetAlpha(1);
      fldAutoMapDrawIconOfsRF(0.0, 0.0, 1, -ooyCamKakudo);
      rsetAlpha(0);
      fldAutoMapDrawIconOfsRF(0.0, 0.0, 0, fldGb->PlayerKakudo);
      sub_8524C0(&v620.x, v626.x, v626.y, 0.0);
      v407 = _autoMapUI->playerObj;
      cmpSetupObject(v407, 1);
      v408 = get_transform(_autoMapUI->playerObj, 0);
      set_localPosition(v408, v620);
      sub_8524C0(&v618, 0.0, 0.0, 0.0);
      v619 = fmodf(fldGb->PlayerKakudo + 180.0, 360.0);
      v409 = get_transform(_autoMapUI->playerObj, 0);
      v411 = v618;
      v412 = v409;
      v413 = v619;
      {
      }
      v631 = Euler(*&v411, *(&v411 + 1), v413, 0);
      set_rotation(v412, v631);
      cmpSetupObject(_autoMapUI->cameraObj, 1);
      v414 = get_transform(_autoMapUI->cameraObj, 0);
      set_localPosition(v414, v620);
      v619 = -fmodf(ooyCamKakudo + 180.0, 360.0);
      v415 = get_transform(_autoMapUI->cameraObj, 0);
      v632 = Euler(*&v618, *(&v618 + 1), v619, 0);
      set_rotation(v415, v632);
    }
    if (!gFldNowDZone)
      goto LABEL_767;
    if (fldGb->LightMa)
    {
LABEL_767:
      darkzone = _autoMapUI->darkzone;
      v392 = darkzone;
      goto LABEL_774;
    }
    v526 = _autoMapUI->darkzone;
    cmpSetupObject(v526, 1);
    sub_8524C0(&value.x, v626.x, v626.y, 0.0);
    v527 = get_transform(_autoMapUI->darkzone, 0);
    set_localPosition(v527, value);
  }
  else
  {
    v391 = _autoMapUI->playerObj;
    cmpSetupObject(v391, 0);
    cmpSetupObject(_autoMapUI->cameraObj, 0);
    v392 = _autoMapUI->darkzone;
LABEL_774:
    cmpSetupObject(v392, 0);
  }
LABEL_775:
  rsetOtOfs(81);
  rsetAlpha(0);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  ooyTestRGBMaskOn();
  aDrawBoxG(0, 0, 512, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  aDrawBoxGF(24.0, 79.0, 464.0, 346.0, 0, 0, 0, 128, 0, 0, 0, 128, 0, 0, 0, 128, 0, 0, 0, 128);
  if (gFldNowDZone)
  {
    else if (!fldGb->LightMa)
    {
LABEL_785:
      aDrawBoxF(0, 41, 24, 170, 0, 0, 0, 128);
      aDrawBoxF(488, 41, 24, 170, 0, 0, 0, 128);
    }
  }
  rsetTest(1, 0, 128, 1, 1, 0, 1, 1);
  ooyTestRGBMaskOff();
  rsetAlpha(1);
  aDrawBoxG(-88, 0, 600, 125, 22, 19, 73, 0, 22, 19, 73, 102, 22, 19, 73, 0, 22, 19, 73, 0);
  aDrawBoxG(0, 79, 280, 145, 30, 36, 56, 0, 30, 36, 56, 0, 30, 36, 56, 0, 30, 36, 56, 76);
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  rsetAlpha(0);
  rsetAlpha(0);
  v427 = fldAutoMapDrawOneArea_floor;
  v429 = fldAutoMapGetFloorNext(v427);
  if (v427 == v429)
  {
    stairs_up = _autoMapUI->stairs_up;
    v432 = "autmupdown";
    v433 = 0;
  }
  else
  {
    stairs_up = _autoMapUI->stairs_up;
    v432 = "autmupdown";
    v433 = 1;
  }
  SetInteger(stairs_up, v432, v433);
  v436 = fldAutoMapDrawOneArea_floor;
  v438 = fldAutoMapGetFloorPrev(v436);
  if (v436 == v438)
  {
    stairs_down = _autoMapUI->stairs_down;
    v441 = "autmupdown";
    v442 = 0;
  }
  else
  {
    stairs_down = _autoMapUI->stairs_down;
    v441 = "autmupdown";
    v442 = 1;
  }
  SetInteger(stairs_down, v441, v442);
  sdfSin(fldAutoMapDrawOneArea_scrcntf);
  fldAutoMapDrawOneArea_scrcntf = fldAutoMapDrawOneArea_scrcntf
                                                                    + 0.2;
  getZ1 = 0;
  getZ0 = 0;
  fldAutoMapGetBBox(&getZ0 + 1, &getZ0, &getZ1 + 1, &getZ1);
  v448 = (1000 * ((*(&getZ0 + 1) + -1000.0) / 1000.0));
  *(&getZ0 + 1) = v448;
  v449 = (1000 * ((*(&getZ1 + 1) + 1000.0) / 1000.0));
  *(&getZ1 + 1) = v449;
  v450 = (1000 * ((*&getZ1 + 1000.0) / 1000.0));
  *&getZ0 = (1000 * ((*&getZ0 + -1000.0) / 1000.0));
  *&getZ1 = v450;
  if (*&getZ0 <= gAmap_OfsZ)
  {
    else
    {
      dir = _autoMapUI->dir;
      if (!LODWORD(dir->max_length))
        goto LABEL_835;
    }
    v459 = dir->m_Items[0];
    v455 = v459;
    v456 = 0;
    goto LABEL_840;
  }
  else
  {
    v452 = _autoMapUI->dir;
    if (!LODWORD(v452->max_length))
      goto LABEL_827;
  }
  v454 = v452->m_Items[0];
  v455 = v454;
  v456 = 1;
LABEL_840:
  cmpSetupObject(v455, v456);
  if ((v462 & 0x200) != 0)
  {
    v463 = v462 & 0x200;
  }
  else
  {
    v463 = 0;
  }
  if (v450 >= gAmap_OfsZ)
  {
    v470 = _autoMapUI->dir;
    v472 = v470->m_Items[1];
    v468 = v472;
    v469 = 0;
  }
  else
  {
    v465 = _autoMapUI->dir;
    v467 = v465->m_Items[1];
    v468 = v467;
    v469 = 1;
  }
  cmpSetupObject(v468, v469);
  if ((v475 & 0x200) != 0)
  {
    v476 = v475 & 0x200;
  }
  else
  {
    v476 = 0;
  }
  if (v448 >= gAmap_OfsX)
  {
    v483 = _autoMapUI->dir;
    v485 = v483->m_Items[2];
    v481 = v485;
    v482 = 0;
  }
  else
  {
    v478 = _autoMapUI->dir;
    v480 = v478->m_Items[2];
    v481 = v480;
    v482 = 1;
  }
  cmpSetupObject(v481, v482);
  if ((v488 & 0x200) != 0)
  {
    v489 = v488 & 0x200;
  }
  else
  {
    v489 = 0;
  }
  if (v449 <= gAmap_OfsX)
  {
    v496 = _autoMapUI->dir;
    v498 = v496->m_Items[3];
    v494 = v498;
    v495 = 0;
  }
  else
  {
    v491 = _autoMapUI->dir;
    v493 = v491->m_Items[3];
    v494 = v493;
    v495 = 1;
  }
  cmpSetupObject(v494, v495);
  FieldName = GetFieldName(fldNameData, fldGb->fieldID % 100);
  fldName = _autoMapUI->fldName;
  v505 = NewSpecific(object, 1u);
  v613.m00 = 0.0;
  v506 = v505;
  v507 = sub_8D3950(s32, &v613);
  v509 = v507;
  v506->m_Items[0] = v509;
  v511 = RepColTag(FieldName, v506);
  set_text(fldName, v511);
  rsetOtOfs(81);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 2, 0, 0, 1, 2);
  rsetTest(1, 5, 128, 3, 0, 0, 1, 2);
  if (!fldAutoMapDrawOneArea_iny)
  {
    else
    {
      areaName = _autoMapUI->areaName;
      if (!LODWORD(areaName->max_length))
        goto LABEL_948;
    }
    set_text(areaName->m_Items[0], "");
    goto LABEL_995;
  }
  if (fldAutoMapDrawOneArea_ofloor >= 1)
  {
    if (fldAutoMapDrawOneArea_ofloor <= 40)
    {
      if (am_floorSL->m_Items[fldAutoMapDrawOneArea_ofloor] >= 2)
      {
        if ((v520 & 0x200) != 0)
        {
          v521 = v520 & 0x200;
        }
        else
        {
          v521 = 0;
        }
        if (fldAutoMapDrawOneArea_ioy >= 0)
          v530 = fldAutoMapDrawOneArea_ioy;
        else
          v530 = -fldAutoMapDrawOneArea_ioy;
        v531 = _autoMapUI->areaName;
        v533 = v531->m_Items[0];
        FloorName = GetFloorName(fldNameData, fldGb->fieldID, fldAutoMapDrawOneArea_ofloor);
        v536 = NewSpecific(object, 1u);
        v613.m00 = 0.0;
        v537 = sub_8D3950(s32, &v613);
        v539 = v537;
        v536->m_Items[0] = v539;
        v542 = RepColTag(FloorName, v536);
        set_text(v533, v542);
        v543 = _autoMapUI->areaName;
        v547 = (v543->m_Items[0]->klass->vtable._26_SetAllDirty.methodPtr)(
                 v543->m_Items[0],
                 v543->m_Items[0]->klass->vtable._26_SetAllDirty.method);
        v548 = _autoMapUI->areaName;
        *&v3 = (v530 / -24.0) + 1.0;
        (v548->m_Items[0]->klass->vtable._27_SetLayoutDirty.methodPtr)(
          v548->m_Items[0],
          v548->m_Items[0]->klass->vtable._27_SetLayoutDirty.v547,
          v545,
          v546,
          v3);
        v550 = _autoMapUI->areaName;
        v552 = get_transform(v550->m_Items[0], 0);
        localPosition = get_localPosition(v552);
        v554 = _autoMapUI->areaName;
        v555 = (-2 * fldAutoMapDrawOneArea_ioy);
        v557 = get_transform(v554->m_Items[0], 0);
        v629.x = localPosition.x;
        v629.y = v555;
        v629.z = localPosition.z;
        set_localPosition(v557, v629);
      }
    }
  }
LABEL_995:
  v560 = fldAutoMapDrawOneArea_floor;
  if (v560 >= 1)
  {
    if (v560 <= 40)
    {
      v561 = am_floorSL;
      if (v561->m_Items[v560] >= 2)
      {
        if ((v564 & 0x200) != 0)
        {
          v565 = v564 & 0x200;
        }
        else
        {
          v565 = 0;
        }
        v567 = fldAutoMapDrawOneArea_iny;
        if (v567 >= 0)
          v568 = fldAutoMapDrawOneArea_iny;
        else
          v568 = -v567;
        v569 = _autoMapUI->areaName;
        v571 = v569->m_Items[1];
        v573 = GetFloorName(fldNameData, fldGb->fieldID, fldAutoMapDrawOneArea_floor);
        v574 = NewSpecific(object, 1u);
        v613.m00 = 0.0;
        v575 = sub_8D3950(s32, &v613);
        v577 = v575;
        v574->m_Items[0] = v577;
        v580 = RepColTag(v573, v574);
        set_text(v571, v580);
        v581 = _autoMapUI->areaName;
        v585 = (v581->m_Items[1]->klass->vtable._26_SetAllDirty.methodPtr)(
                 v581->m_Items[1],
                 v581->m_Items[1]->klass->vtable._26_SetAllDirty.method);
        v586 = _autoMapUI->areaName;
        *&v3 = (v568 / -24.0) + 1.0;
        (v586->m_Items[1]->klass->vtable._27_SetLayoutDirty.methodPtr)(
          v586->m_Items[1],
          v586->m_Items[1]->klass->vtable._27_SetLayoutDirty.v585,
          v583,
          v584,
          v3);
        v588 = _autoMapUI->areaName;
        v590 = get_transform(v588->m_Items[1], 0);
        v628 = get_localPosition(v590);
        v592 = _autoMapUI->areaName;
        v593 = (-2 * fldAutoMapDrawOneArea_iny);
        v595 = get_transform(v592->m_Items[1], 0);
        v630.x = v628.x;
        v630.y = v593;
        v630.z = v628.z;
        set_localPosition(v595, v630);
      }
    }
  }
  v598 = *&dds3CameraTM.m00;
  v599 = *&dds3CameraTM.m20;
  v600 = *&dds3CameraTM.m21;
  *&v610.m01 = *&dds3CameraTM.m01;
  *&v610.m21 = v600;
  *&v610.m00 = v598;
  *&v610.m20 = v599;
  v601 = *&dds3CameraTM.m02;
  v602 = *&dds3CameraTM.m22;
  v604 = *&dds3CameraTM.m03;
  v603 = *&dds3CameraTM.m23;
  *&v610.m03 = v604;
  *&v610.m23 = v603;
  *&v610.m02 = v601;
  *&v610.m22 = v602;
  SDF_VU0__LOADMATRIX(&v610);
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
    else if ((v25->_2.bitflags2 & 2) == 0)
    {
      goto LABEL_54;
    }
  }
  else
  {
    fieldID = 0;
    if ((v25->_2.bitflags2 & 2) == 0)
      goto LABEL_54;
  }
LABEL_54:
  Item = _get_Item(
           fldNameData->_fldFieldNameTbl,
           fieldID);
  v41 = ToString_2975520(Item);
  v43 = get_Length(v41);
  am_fldSL = v43;
}

// 0xf95df0
void fldAutoMapFree(void) {
  s64 v2;
  u64 v3;
  fldAutoMap_c *v4;
  u32 v6;
  struct sdfModelRootNode_t_array *pfldAmRootNode;
  struct sdfModelRootNode_t_array *v10;
  s32 v12;
  s64 i;
  u64 v14;
  struct sdfModelRootNode_t_array *v15;
  struct System_Single_array_array *gfldAmPos;
  s64 v19;
  struct System_Single_array_array *v21;
  s64 v23;
  struct System_Single_array_array *v25;
  s64 v27;
  u32 v29;
  struct sdfTexHandle_t_array *gFldAmTex_Icon;
  struct sdfTexHandle_t_array *v32;
  struct sdfTexHandle_t_array *v35;
  struct sdfTexHandle_t_array *v38;
  struct sdfTexHandle_t_array *gFldAmTex_Bg;
  struct sdfTexHandle_t_array *v42;
  struct sdfTexHandle_t_array *v45;
  struct sdfTexHandle_t_array *v48;
  struct sdfTexHandle_t_array *v51;
  struct sdfTexHandle_t_array *v54;
  struct sdfTexHandle_t_array *v57;
  struct sdfTexHandle_t_array *v59;
  struct sdfTexHandle_t_array *v61;
  struct sdfTexHandle_t_array *v63;
  struct sdfTexHandle_t_array *v65;

  v2 = 32;
  v3 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    v6 = *&v4->_2.bitflags1;
    if (v3 >= nfldAmArea)
      break;
    else
    {
      if (v3 >= LODWORD(pfldAmRootNode->max_length))
        goto LABEL_12;
    }
    if (*(&pfldAmRootNode->obj.klass + v2))
    {
      v10 = pfldAmRootNode;
      else if (v3 >= LODWORD(v10->max_length))
      {
        goto LABEL_20;
      }
      sdfModelRootFree((v10 + v2), 1, 1, 0);
    }
    ++v3;
    v2 += 8;
      goto LABEL_6;
  }
  v12 = (v6 >> 9) & 1;
  for (i = 4; i != 36; ++i)
  {
    v14 = i - 4;
    v15 = pfldAmRootNode;
    *(&v15->obj.klass + i) = 0;
    v19 = *(&gfldAmPos->obj.klass + i);
    *(v19 + 32) = 0;
    v21 = gfldAmPos;
    v23 = *(&v21->obj.klass + i);
    *(v23 + 36) = 0;
    v25 = gfldAmPos;
    v27 = *(&v25->obj.klass + i);
    *(v27 + 40) = 0;
    v12 = (v29 >> 9) & 1;
  }
  else
  {
    if (!LODWORD(gFldAmTex_Icon->max_length))
      goto LABEL_48;
  }
  if (gFldAmTex_Icon->m_Items[0])
  {
    else
    {
      v32 = gFldAmTex_Icon;
      if (!LODWORD(v32->max_length))
        goto LABEL_53;
    }
    v32->m_Items[0] = 0;
  }
  v35 = gFldAmTex_Icon;
  if (v35->m_Items[1])
  {
    v38 = gFldAmTex_Icon;
    v38->m_Items[1] = 0;
  }
  else
  {
    if (!LODWORD(gFldAmTex_Bg->max_length))
      goto LABEL_70;
  }
  if (gFldAmTex_Bg->m_Items[0])
  {
    else
    {
      v42 = gFldAmTex_Bg;
      if (!LODWORD(v42->max_length))
        goto LABEL_75;
    }
    v42->m_Items[0] = 0;
  }
  v45 = gFldAmTex_Bg;
  if (v45->m_Items[1])
  {
    v48 = gFldAmTex_Bg;
    v48->m_Items[1] = 0;
  }
  v51 = gFldAmTex_Bg;
  if (v51->m_Items[2])
  {
    v54 = gFldAmTex_Bg;
    v54->m_Items[2] = 0;
  }
  else
  {
    v57 = gFldAmTex_Icon;
    if (!LODWORD(v57->max_length))
      goto LABEL_104;
  }
  v57->m_Items[0] = 0;
  v59 = gFldAmTex_Icon;
  v59->m_Items[1] = 0;
  v61 = gFldAmTex_Bg;
  v61->m_Items[0] = 0;
  v63 = gFldAmTex_Bg;
  v63->m_Items[1] = 0;
  v65 = gFldAmTex_Bg;
  v65->m_Items[2] = 0;
  AutoMapSeq = 0;
  frSetFontDrawOT(0x48u);
  AutoMapDispOff(kernelObject);
  _cameraMain = 0;
  _cameraAutoReal = 0;
  _cameraAutoHalf = 0;
  deleteFldMenuSub(20);
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
  fldAutoMap_c *v7;
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
  if ((v7->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
LABEL_11:
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
          goto LABEL_9;
        goto LABEL_11;
      }
      v19 = fldAutoMapChkOpen(gAmap_NowField, v9, v15, getZ1);
      else if (!(dbgfull | v19))
      {
        goto LABEL_15;
      }
      v21 = *(*&v16[8 * v15] + 48LL);
      if (v21)
      {
        if (*getX0 <= *(v21 + 16))
        {
          v24 = *getX0;
          if (v15 >= *(namespaze + 6))
            goto LABEL_35;
        }
        else
        {
          v24 = *(v21 + 16);
          *getX0 = v24;
          if (v15 >= *(namespaze + 6))
          {
LABEL_35:
          }
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
            goto LABEL_48;
        }
        else
        {
          v31 = *(v29 + 16);
          *getX1 = v31;
          if (v15 >= *(namespaze + 6))
          {
LABEL_48:
          }
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
            goto LABEL_61;
        }
        else
        {
          v38 = *(v36 + 24);
          *getZ0 = v38;
          if (v15 >= *(namespaze + 6))
          {
LABEL_61:
          }
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
            goto LABEL_74;
        }
        else
        {
          v45 = *(v43 + 24);
          *getZ1 = v45;
          if (v15 >= *(namespaze + 6))
          {
LABEL_74:
          }
        }
        v47 = *(*&v16[8 * v15] + 56LL);
        if (v45 > *(v47 + 24))
        {
          *getZ1 = *(v47 + 24);
        }
      }
LABEL_15:
      ++v15;
    }
  }
}

// 0xf94070
void *fldAutoMapGetChild(void *parentObj, char *name1, char *name2, s32 num1, s32 num2, s32 num3) {
  bool v13;
  UnityEngine_Transform_o *transform;
  s64 *Enumerator;
  UnityEngine_Object_o *v17;
  UnityEngine_Object_o *v18;
  UnityEngine_Object_c *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  System_String_o *name;
  UnityEngine_GameObject_o *gameObject;
  System_String_o *v27;
  s64 *Interface;
  UnityEngine_GameObject_o *v30;
  UnityEngine_Transform_o *v31;
  s64 v32;
  UnityEngine_GameObject_o *v33;
  s64 *v34;
  u64 v35[3];

  v13 = Equals_5234480(name1, "");
  transform = get_transform(parentObj, 0);
  if (v13)
    return GetChild(transform, 0);
  v33 = parentObj;
  v34 = &v32;
  Enumerator = GetEnumerator(transform);
  while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
  {
    v17 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
    v18 = v17;
    if (v17)
    {
      klass = v17->klass;
      if (v17->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, v35);
        if ((v35[0] & 1) != 0)
          v21 = v35[2];
        else
          v21 = v35 + 1;
        v22 = sub_8C4940(v21);
      }
    }
    name = get_name(v17);
    if (!Contains(name, name1, 0))
    {
      if (!op_Inequality(name2, "", 0))
        continue;
      v27 = get_name(v18);
      if (!Contains(v27, name2, 0))
        continue;
    }
    gameObject = get_gameObject(v18);
    if (fldAutoMapChkChild(gameObject, num1, num2, num3))
      goto LABEL_23;
  }
  v18 = 0;
LABEL_23:
  *v34 = 149;
  Interface = QueryInterface(Enumerator, System_IDisposable);
  v30 = v33;
  if (Interface)
    sub_22F10(0, System_IDisposable, Interface);
  if (op_Equality(v18, 0, 0))
  {
    v31 = get_transform(v30, 0);
    return GetChild(v31, 0);
  }
  return v18;
}

// 0xf8e0a0
s32 fldAutoMapGetFloorMax(void) {
  fldAutoMap_c *v2;
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
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
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
      goto LABEL_9;
  }
  return v5 + 1;
}

// 0xf8af20
s32 fldAutoMapGetFloorNext(s32 floor) {
  fldAutoMap_c *v4;
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v6;
  s32 v7;
  u32 i;
  s32 v13;

  v6 = 0;
  v7 = 999;
  if ((v4->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
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
      goto LABEL_9;
  }
  if (v7 == 999)
    return floor;
  else
    return v7;
}

// 0xf8a8e0
s32 fldAutoMapGetFloorPrev(s32 floor) {
  fldAutoMap_c *v4;
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v6;
  s32 v7;
  u32 i;
  s32 v13;

  v6 = 0;
  v7 = -1;
  if ((v4->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
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
      goto LABEL_9;
  }
  if (v7 == -1)
    return floor;
  else
    return v7;
}

// 0xf8d760
void fldAutoMapLoad(void) {
  struct sdfTexHandle_t_array *gFldAmTex_Icon;
  struct sdfTexHandle_t_array *v8;
  struct sdfTexHandle_t_array *gFldAmTex_Bg;
  struct sdfTexHandle_t_array *v12;
  struct sdfTexHandle_t_array *v14;
  u64 i;
  struct sdfModelRootNode_t_array *pfldAmRootNode;
  struct System_Single_array_array *gfldAmPos;
  u32 *v25;
  s64 *v26;
  s64 *v27;
  struct System_Single_array_array *v29;
  System_Single_array *v31;
  struct System_Single_array_array *v33;
  System_Single_array *v35;
  struct System_Single_array_array *v37;
  System_Single_array *v39;

  fldGb->nameU = -1;
  fldGb->nameD = -1;
  sub_854930(&AMapCameraTPos, 0);
  sub_854930(&AMapCameraTPos, 1u);
  sub_854930(&AMapCameraTPos, 2u);
  sub_854930(&AMapCameraTPos, 3u);
  sub_854930(&AMapCameraTPosOld, 0);
  sub_854930(&AMapCameraTPosOld, 1u);
  sub_854930(&AMapCameraTPosOld, 2u);
  sub_854930(&AMapCameraTPosOld, 3u);
  mhfldAmFile = 0;
  pfldAmArea = 0;
  nfldAmArea = 0;
  gFldAmTex_Icon->m_Items[0] = 0;
  v8 = gFldAmTex_Icon;
  v8->m_Items[1] = 0;
  gFldAmTex_Bg->m_Items[0] = 0;
  v12 = gFldAmTex_Bg;
  v12->m_Items[1] = 0;
  v14 = gFldAmTex_Bg;
  v14->m_Items[2] = 0;
  for (i = 0; i != 32; ++i)
  {
    pfldAmRootNode->m_Items[i] = 0;
    if (gfldAmPos->m_Items[i])
    {
        goto LABEL_40;
LABEL_29:
      goto LABEL_40;
    }
    v25 = gfldAmPos;
    v26 = NewSpecific(f32, 3u);
    v27 = v26;
    *&v25[2 * i + 8] = v27;
      goto LABEL_29;
LABEL_40:
    v29 = gfldAmPos;
    v31 = v29->m_Items[i];
    v31->m_Items[0] = 0.0;
    v33 = gfldAmPos;
    v35 = v33->m_Items[i];
    v35->m_Items[1] = 0.0;
    v37 = gfldAmPos;
    v39 = v37->m_Items[i];
    v39->m_Items[2] = 0.0;
  }
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
                goto LABEL_59;
              goto LABEL_57;
            }
            v19 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
            v20 = v6 - 40LL;
            if (v20 < LODWORD(v19->max_length))
            {
LABEL_44:
              v13 = v19->m_Items[v20];
                goto LABEL_59;
              goto LABEL_57;
            }
LABEL_43:
          }
          if ((v6 & 0xFFFFFFFE) == 0x3C)
          {
            amapEX_Ver7 = DDS3_GBWK->amapEX_Ver7;
            goto LABEL_42;
          }
          goto LABEL_62;
        }
        if (v8 >= 40)
        {
          if ((v6 & 0xFFFFFFFE) == 0x3C)
          {
            amapEX_Ver7 = DDS3_GBWK->amapEX;
LABEL_42:
            v19 = amapEX_Ver7->blkOpenFlg;
            v20 = v6 - 60LL;
            if (v20 < LODWORD(v19->max_length))
              goto LABEL_44;
            goto LABEL_43;
          }
LABEL_62:
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
LABEL_56:
            v13 = v15->m_Items[v8];
            {
LABEL_59:
              v23 = fldGb;
              v24 = v23->areaID;
              v13->m_Items[v24] |= 1 << v23->blockID;
              goto LABEL_62;
            }
LABEL_57:
            goto LABEL_59;
          }
        }
        else
        {
          v15 = DDS3_GBWK->fldSave->amap->blkOpenFlg;
          if (v8 < LODWORD(v15->max_length))
            goto LABEL_56;
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
      goto LABEL_53;
    }
    v11 = SBlock - 33;
    if (v9 >= 40)
    {
      if ((v7 & 0xFFFFFFFE) != 0x3C)
        return;
      v13 = DDS3_GBWK->amapEX_Ver7->blkOpenFlg;
      v14 = v7 - 60LL;
      if (v14 < LODWORD(v13->max_length))
        goto LABEL_40;
    }
    else
    {
      if (v9 >= 30)
      {
        v13 = DDS3_GBWK->amap31_Ver7->blkOpenFlg;
        v14 = v7 - 40LL;
        if (v14 < LODWORD(v13->max_length))
          goto LABEL_40;
      }
      else
      {
        v13 = DDS3_GBWK->amap_Ver7->blkOpenFlg;
        v14 = v9;
        if (v9 < LODWORD(v13->max_length))
        {
LABEL_40:
          v28 = v13->m_Items[v14];
          v26 = v28 + 4 * v10;
          v30 = *(v26 + 32);
          v31 = 1 << v11;
LABEL_53:
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
            goto LABEL_161;
          v5 = fieldID - 10;
          if (fieldID == 61)
          {
LABEL_161:
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
LABEL_81:
              if (v73)
              {
                v72 = v24->m_Items[v15];
                if (v72)
                {
                  if (LODWORD(AutoMapOpenTbl->m_Items[v5]->max_length) != 1)
                    goto LABEL_106;
                  v30 = AutoMapOpenTbl;
                  v31 = v30->m_Items[v5];
                  if (v31->m_Items[0])
                  {
LABEL_106:
                    v37 = 0;
                    v38 = 0;
                      goto LABEL_110;
LABEL_107:
                    while (1)
                    {
LABEL_110:
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
                        goto LABEL_107;
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
              goto LABEL_81;
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
  fldAutoMap_c *v7;
  s64 v8;
  struct fldAmAreaData_t_array *pfldAmArea;
  u64 v10;
  u32 *pfldAmRootNode;
  sdfModelDef_t_o **v15;
  s64 *Early;
  s64 *v17;
  struct System_Single_array_array *gfldAmPos;
  s64 v21;
  struct System_Single_array_array *v24;
  s64 v26;
  struct System_Single_array_array *v29;
  s64 v31;
  struct sdfTexHandle_t_array *gFldAmTex_Icon;
  Il2CppObject *gAmMk1LoadBuff;
  s64 *v38;
  s64 *v39;
  struct sdfTexHandle_t_array *v42;
  s64 *v43;
  s64 *v44;
  struct sdfTexHandle_t_array *gFldAmTex_Bg;
  s64 *v48;
  s64 *v49;
  struct sdfTexHandle_t_array *v52;
  s64 *v53;
  s64 *v54;
  struct sdfTexHandle_t_array *v57;
  s64 *v58;
  s64 *v60;
  f32 v67;
  struct UnityEngine_GameObject_o *AutoMapCameraHalf;
  Il2CppObject *Component_object;
  Il2CppObject *v80;
  struct UnityEngine_GameObject_o *AutoMapObj;
  System_String_o *LocalizeText;
  u64 v87;
  System_String_o *v89;
  struct TMPro_TextMeshProUGUI_array *floor_up;
  u64 max_length_low;
  TMPro_TMP_Text_o *v93;
  System_Object_array *v94;
  s64 *v95;
  s64 *v97;
  System_String_o *v101;
  u64 v102;
  u64 v103;
  s16 v104;
  System_String_o *v105;
  s32 i;
  struct TMPro_TextMeshProUGUI_array *floor_dn;
  u64 v108;
  TMPro_TMP_Text_o *v110;
  System_Object_array *v111;
  s64 *v112;
  s64 *v114;
  s32 v119;
  UnityEngine_Vector4_o v120;
  UnityEngine_Vector4_o v121;
  UnityEngine_Vector4_o v122;
  dds3Basic_t_o *basic;
  f32 getZ;
  f32 getX;

  *&v122.z = 0;
  basic = 0;
  *&v121.z = 0;
  *&v122.x = 0;
  *&v120.x = 0;
  getX = 0.0;
  *&v120.z = 0;
  *&v121.x = 0;
  getZ = 0.0;
  if (fldSeqCheckFlag(1u) != 1)
  {
    if (fldGb->fieldID >= 10)
    {
      basic = dds3GetActiveScene();
      dds3VisibleSceneBasic(&basic, 0);
      p2sdPlaySE(14);
      v8 = 4;
      v10 = 0;
      if ((v7->_2.bitflags2 & 2) != 0)
      {
LABEL_26:
      }
      while (1)
      {
        if (v10 >= nfldAmArea)
          break;
        v15 = (*(*(&pfldAmArea->obj.klass + v8) + 40LL) + 16LL);
        Early = sdfModelMakeEarly(0, v15);
        v17 = Early;
        *&pfldAmRootNode[2 * v8] = v17;
        v21 = *(&gfldAmPos->obj.klass + v8);
        *(v21 + 32) = *(*(*(&pfldAmArea->obj.klass + v8) + 48LL) + 16LL);
        v24 = gfldAmPos;
        v26 = *(&v24->obj.klass + v8);
        *(v26 + 36) = *(*(*(&pfldAmArea->obj.klass + v8) + 48LL) + 20LL);
        v29 = gfldAmPos;
        v31 = *(&v29->obj.klass + v8);
        *(v31 + 40) = *(*(*(&pfldAmArea->obj.klass + v8) + 48LL) + 24LL);
        v10 = ++v8 - 4;
          goto LABEL_26;
      }
      gAmMk1LoadBuff = fldGb->gAmMk1LoadBuff;
      v38 = sdfTexSet(gAmMk1LoadBuff);
      v39 = v38;
      gFldAmTex_Icon->m_Items[0] = v39;
      v42 = gFldAmTex_Icon;
      v43 = sdfTexSet(fldGb->gAmMk2LoadBuff);
      v44 = v43;
      v42->m_Items[1] = v44;
      v48 = sdfTexSet(fldGb->gAmBg1LoadBuff);
      v49 = v48;
      gFldAmTex_Bg->m_Items[0] = v49;
      v52 = gFldAmTex_Bg;
      v53 = sdfTexSet(fldGb->gAmBg2LoadBuff);
      v54 = v53;
      v52->m_Items[1] = v54;
      v57 = gFldAmTex_Bg;
      v58 = sdfTexSet(fldGb->gAmBg3LoadBuff);
      v60 = v58;
      v57->m_Items[2] = v60;
      AutoMapResetFlg = 0;
      AutoMapGuidFlg = 0;
      AutoMapSeq = 1;
      gAmap_NowArea = fldGb->areaID;
      gAmap_NowFloor = fldGb->AmFloor;
      gAmap_InFloor = gAmap_NowFloor;
      fldAutoMapGetAreaPos(gAmap_NowArea, &getX, &getZ);
      v67 = getZ;
      gAmap_InX = (fldGb->playerX + getX);
      gAmap_InZ = (fldGb->playerZ + v67);
      gAmap_OfsX = gAmap_InX;
      gAmap_OfsZ = gAmap_InZ;
      gAmap_Cnt = 0;
      fldSeqOnFlag(1u);
      fldReleaseUnitPad();
      evtDisableMoonDraw();
      *&v122.x = 0;
      *&v122.z = 0;
      *&v121.x = 0;
      *&v121.z = 0;
      sub_854690(&v120.x, 0.0, 0.0, -1.0, 1.0);
      sub_854930(&AMapCameraTPosOld, 0);
      sub_854930(&AMapCameraTPos, 0);
      sub_854930(&AMapCameraTPosOld, 1u);
      sub_854930(&AMapCameraTPos, 1u);
      sub_854930(&AMapCameraTPosOld, 2u);
      sub_854930(&AMapCameraTPos, 2u);
      sub_854930(&v122, 1u);
      sub_854930(&v122, 0);
      sub_854930(&v122, 2u);
      sub_854710(&v122, 0);
      sub_854930(&v121, 0);
      sub_854710(&v122, 1u);
      sub_854930(&v121, 1u);
      sub_854710(&v122, 2u);
      sub_854930(&v121, 2u);
      SDF_VU0__COPYVECTOR(&dds3HCameraEyePos, v121);
      SDF_VU0__COPYVECTOR(&dds3HCameraTargetPos, v122);
      SDF_VU0__COPYVECTOR(&dds3HCameraUpVector, v120);
      dds3HFogParam->fogMax = 255.0;
      dds3HFogParam->fogNear = 1000.0;
      dds3HFogParam->fogMin = 255.0;
      dds3HFogParam->fogFar = 20000.0;
      dds3HFogParam->color = 1081360;
      dds3HScreenParam->ox = 2048.0;
      dds3HScreenParam->oy = 2048.0;
      AutoMapDispOn(kernelObject);
      cameraMainObj = GetMainCamera(kernelObject);
      cameraAutoRealObj = GetAutoMapCameraReal(kernelObject);
      AutoMapCameraHalf = GetAutoMapCameraHalf(kernelObject);
      cameraAutoHalfObj = AutoMapCameraHalf;
      Component_object = GetComponent_object_(cameraMainObj);
      _cameraMain = Component_object;
      v80 = GetComponent_object_(cameraAutoRealObj);
      _cameraAutoReal = v80;
      _cameraAutoHalf = GetComponent_object_(cameraAutoHalfObj);
      AutoMapObj = GetAutoMapObj(kernelObject);
      _autoMapObj = AutoMapObj;
      _autoMapUI = GetComponent_object_(_autoMapObj);
      LocalizeText = GetLocalizeText("AUTOMAP_L0001");
      v87 = 0;
      {
LABEL_117:
      }
      while (1)
      {
        floor_up = _autoMapUI->floor_up;
        max_length_low = LODWORD(floor_up->max_length);
        if (v87 >= max_length_low)
          break;
        else if (v87 >= max_length_low)
        {
          goto LABEL_123;
        }
        v93 = floor_up->m_Items[v87];
        v94 = NewSpecific(object, 1u);
        v119 = 0;
        v95 = sub_8D3950(s32, &v119);
        v97 = v95;
        v94->m_Items[0] = v97;
        v89 = RepColTag(LocalizeText, v94);
        set_text(v93, v89);
        ++v87;
          goto LABEL_117;
      }
      v101 = GetLocalizeText("AUTOMAP_L0002");
      v102 = 0;
      if ((v104 & 0x200) != 0)
        goto LABEL_141;
LABEL_140:
      for (i = 0; ; i = v104 & 0x200)
      {
        floor_dn = *(*(*(v103 + 184) + 88LL) + 104LL);
        v108 = LODWORD(floor_dn->max_length);
        if (v102 >= v108)
          break;
        if (i && !*(v103 + 216))
        {
          floor_dn = _autoMapUI->floor_dn;
          if (v102 >= LODWORD(floor_dn->max_length))
          {
LABEL_148:
          }
        }
        else if (v102 >= v108)
        {
          goto LABEL_148;
        }
        v110 = floor_dn->m_Items[v102];
        v111 = NewSpecific(object, 1u);
        v119 = 0;
        v112 = sub_8D3950(s32, &v119);
        v114 = v112;
        v111->m_Items[0] = v114;
        v105 = RepColTag(v101, v111);
        set_text(v110, v105);
        ++v102;
        if ((v104 & 0x200) == 0)
          goto LABEL_140;
LABEL_141:
      }
      fldAllIconLoad(v103);
      fldAllIconDel();
      ButtonGuideDispSet("AUTO01", 0, 0, 90);
      ButtonGuideDispOn();
    }
  }
}

// 0xf98050
void fldAutoMapSetField(s32 fld, s32 area, s32 block) {
  gAmap_NowArea = area;
  sub_854930(&AMapCameraTPos, 0);
  sub_854930(&AMapCameraTPos, 1u);
  sub_854930(&AMapCameraTPos, 2u);
  fldGb->fieldID = fld;
  fldGb->areaID = area;
  fldGb->blockID = block;
  gAmap_NowField = fldGb->fieldID % 100;
}

// 0xf8ad50
s32 fldAutoMap_GetFloor(s32 area, s32 block) {
  fldAutoMap_c *v5;
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
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
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
      if (v7 >= LODWORD(pfldAmArea->max_length))
      {
LABEL_17:
      }
      while (v15 < *(*v12 + 32LL))
      {
        if (v8 == v15)
        {
          v9 = *(*&namespaze[8 * v15 + 32] + 44LL) + 1;
        }
        ++v15;
        if (v7 >= LODWORD(pfldAmArea->max_length))
          goto LABEL_17;
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
      goto LABEL_9;
  }
  return v9;
}

// 0xf99950
void fldDrawAreaBlockFont(s32 ofsx) {
  struct fldGlobalWork_t_o *fldGb;
  fldAutoMap_c *v4;
  struct fldAutoMap_StaticFields **p_static_fields;
  f32 gFldAreaNameCnt;
  s16 v8;
  s32 v9;
  s32 fldDrawAreaBlockFont_pm_mode;
  struct fldAutoMap_StaticFields *v11;
  struct fldAutoMap_StaticFields *static_fields;
  struct fldAutoMap_StaticFields *v15;
  f32 v19;
  f32 v20;
  f32 v21;
  s32 v22;
  s32 v23;
  struct fldGlobalWork_t_o *v24;
  struct System_Int16_array *am_spcSL;
  s64 nameD;
  dds3DefaultMain_o *kernelObject;
  System_String_o *AreaName;
  u32 v34;
  struct System_Int16_array *am_areaSL;
  s64 nameU;
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
        goto LABEL_77;
      case 1:
        gFldAreaNameCnt = 1.0;
        goto LABEL_77;
      case 2:
        if (gFldAreaNameCnt <= 0.0)
          goto LABEL_78;
        fldDrawAreaBlockFont_pm_mode = -1;
        gFldAreaNameCnt = gFldAreaNameCnt + -0.1;
        if (gFldAreaNameCnt >= 0.0)
          goto LABEL_78;
        goto LABEL_72;
      case 3:
        if (gFldAreaNameCnt < 1.0)
        {
          fldDrawAreaBlockFont_pm_mode = 1;
          gFldAreaNameCnt = gFldAreaNameCnt + 0.1;
          if (gFldAreaNameCnt > 1.0)
            goto LABEL_61;
        }
        goto LABEL_78;
      case 4:
      case 5:
      case 6:
      case 7:
        if (gFldAreaNameCnt >= 0.99)
          goto LABEL_78;
        if (gFldAreaNameCnt <= 0.01)
          goto LABEL_78;
        v8 = *&v4->_2.bitflags1;
        if ((v8 & 0x200) != 0)
        {
          v9 = v8 & 0x200;
          if (fldDrawAreaBlockFont_pm_mode != -1)
            goto LABEL_21;
        }
        else
        {
          v9 = 0;
          if (fldDrawAreaBlockFont_pm_mode != -1)
          {
LABEL_21:
            if (fldDrawAreaBlockFont_pm_mode != 1)
              goto LABEL_78;
            gFldAreaNameCnt = gFldAreaNameCnt + 0.1;
            v11 = *p_static_fields;
            if ((*p_static_fields)->gFldAreaNameCnt <= 1.0)
              goto LABEL_78;
LABEL_61:
            gFldAreaNameCnt = 1.0;
            goto LABEL_76;
          }
        }
        gFldAreaNameCnt = gFldAreaNameCnt + -0.1;
        v15 = *p_static_fields;
        if ((*p_static_fields)->gFldAreaNameCnt >= 0.0)
          goto LABEL_78;
LABEL_72:
        gFldAreaNameCnt = 0.0;
LABEL_76:
        static_fields = *p_static_fields;
LABEL_77:
        fldDrawAreaBlockFont_pm_mode = 0;
LABEL_78:
        if ((v4->_2.bitflags2 & 2) != 0)
        {
LABEL_34:
        }
LABEL_79:
        v19 = gFldAreaNameCnt;
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
            AreaName = GetAreaName(fldNameData, fldGb->fieldID, fldGb->nameU);
            v34 = -1600273536;
            goto LABEL_119;
          }
        }
        else
        {
          nameD = fldGb->nameD;
          if (am_spcSL->m_Items[nameD] > 1)
          {
            AreaName = GetBasyoName(fldNameData, fldGb->fieldID, fldGb->nameD);
            v34 = -253991808;
LABEL_119:
            v41 = kernelObject;
            v42 = 1;
            v43 = v22;
            v44 = v23;
            goto LABEL_124;
          }
        }
          goto LABEL_123;
        break;
      default:
          goto LABEL_34;
        goto LABEL_79;
    }
    goto LABEL_122;
  }
LABEL_123:
  v41 = kernelObject;
  v34 = -1;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  AreaName = 0;
LABEL_124:
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
