#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct FieldBgHD FieldBgHD;
typedef struct FieldChrHD FieldChrHD;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct evtTexManager evtTexManager;
typedef struct fldConstruntAreaFL2_t fldConstruntAreaFL2_t;
typedef struct fldFileAreaDataFL1_t fldFileAreaDataFL1_t;
typedef struct fldFileAreaDataFL2_t fldFileAreaDataFL2_t;
typedef struct fldFileInfoHeaderFL1_t fldFileInfoHeaderFL1_t;
typedef struct fldFileInfoHeaderFL2_t fldFileInfoHeaderFL2_t;
typedef struct fldResCam_t fldResCam_t;
typedef struct fldResCollPolyTomeName_t fldResCollPolyTomeName_t;
typedef struct fldResCollPolyTome_t fldResCollPolyTome_t;
typedef struct fldResCollisionPolyFace_t fldResCollisionPolyFace_t;
typedef struct fldResCollisionPoly_t fldResCollisionPoly_t;
typedef struct fldResCollision_t fldResCollision_t;
typedef struct fldResEvent_t fldResEvent_t;
typedef struct fldResHeadAreaName_t fldResHeadAreaName_t;
typedef struct fldResHeadLinkData_t fldResHeadLinkData_t;
typedef struct fldResHeadLink_t fldResHeadLink_t;
typedef struct fldResHeadPos_t fldResHeadPos_t;
typedef struct fldResHead_t fldResHead_t;
typedef struct fldResModel_t fldResModel_t;
typedef struct fldResPutEveBall_t fldResPutEveBall_t;
typedef struct fldResPutEveBox_t fldResPutEveBox_t;
typedef struct fldResPutEvePoly_t fldResPutEvePoly_t;
typedef struct fldResPutItemBox_t fldResPutItemBox_t;
typedef struct fldResPutNpc_t fldResPutNpc_t;
typedef struct fldResPutSE_t fldResPutSE_t;
typedef struct fldResPut_t fldResPut_t;
typedef struct fldResourceEffect_t fldResourceEffect_t;
typedef struct fldResourceLight_t fldResourceLight_t;
typedef struct fldResourcePathData_t_Float fldResourcePathData_t_Float;
typedef struct fldResourcePathData_t_Light fldResourcePathData_t_Light;
typedef struct fldResourcePathData_t_Vector3 fldResourcePathData_t_Vector3;
typedef struct fldResourcePathData_t_Vector4 fldResourcePathData_t_Vector4;
typedef struct fldResourcePathTableInfo_t fldResourcePathTableInfo_t;
typedef struct fldResourcePathTable_t fldResourcePathTable_t;
typedef struct fldResourcePoint_t fldResourcePoint_t;
typedef struct fldResourceTypeTable_t fldResourceTypeTable_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfMatDef_t sdfMatDef_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelNodeDef_t sdfModelNodeDef_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfMotionCutChunk_t sdfMotionCutChunk_t;
typedef struct sdfMotionCutDef_t sdfMotionCutDef_t;
typedef struct sdfMotionNodeDef_t sdfMotionNodeDef_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;

static void *FildMapObj;
static void *FildMaskObj;
static void *AutoMapObjArea;
static void *AutoMapObjHalf;
static void *mat_black;
static void *mat_white;
static void *mat_line;
static char *autoMapPrefab;
static fldResHead_t g_pModelData[UNKNOWN_ARRAY_SIZE];
static u32 g_nModelData;
static fldResHead_t g_pHitData[UNKNOWN_ARRAY_SIZE];
static u32 g_nHitData;
static sdfModelTexList_t *gFldTexList;
static char *pEffFileName[4];
static void *pF1FileData;
static void *pF1Head;
static void *pF2FileData;
static void *pF2Head;
static u32 gFldFileResetMode;
static sdfMemHandle_t *hFldF1Eff[4];
static u8 *pFldF1Eff[4];
static void hFldF1EffTex[UNKNOWN_ARRAY_SIZE];
static sdfModelRootNode_t *gFT_pRootNode;
static sdfModelDef_t *gFL_ModelDefPtr;
static void *gFldFileBF;
static void *pFldNextFileDataBF;
static char *strBF;
static s32 gFldNextSizeBF;
static void *gFldFileTB;
static void *gFldFileF1;
static void *gFldFileF2;
static void *pFldNextFileDataTB;
static void *pFldNextFileDataF1;
static void *pFldNextFileDataF2;
static char *strTB;
static char *strF1;
static char *strF2;
static s32 gFldNextSizeTB;
static s32 gFldNextSizeF1;
static s32 gFldNextSizeF2;
static s32 gFldBtlRet_Field;
static s32 gFldBtlRet_Area;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
char *ChangeCharacter(char *sourceString, s32 charIndex, u16 newChar);
void ChangeMaterial(void **List1, void ***List2, void *mat_black, void *mat_white, void *mat_line);
bool CheckCashField(void);
bool CheckTypeClose(void);
void DelAutoMapObj(void **AutoMapObj, void ***List1, void ****List2);
void FindHojiObj(void);
void GetChildList(void *AutoMapObj, void ***List1, void ****List2);
void **GetChildren(void *parentObj);
EventEMsgData *GetData(char *key);
void *GetEvtInstCash(void *obj);
char *GetFieldAssetName(char *fmt, s32 field);
char *GetStringToByte(u8 **pData, s32 addr);
bool IsDLCField(s32 area);
bool IsFldDataLoaded(void);
bool IsLoad(AssetBundles *this, char *key);
void LoadAssetExt(char *key, char *name, char *dlc);
void LoadEventVoice(s32 eventno, char *key, EventEMsgData *data);
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void LoadTexture_26559536(evtTexManager *this, void ***tex, char *key);
void SDF_ABORT4(char *aFmt, void **LegacyParamArray);
void SetFiledName(FieldBgHD *this, char *name);
void SetLayerAll(FieldChrHD *this, void *rootobj);
void SetTypeClose(bool flg);
fldConstruntAreaFL2_t **SetfldConstruntAreaFL2(u8 **pData, u32 size, s32 addr);
fldFileAreaDataFL1_t *SetfldFileAreaDataFL1(u8 **pData, s32 addr);
fldFileAreaDataFL2_t *SetfldFileAreaDataFL2(u8 **pData, s32 addr);
fldResCollPolyTome_t *SetfldResCollPolyTome(u8 **pData, s32 addr);
fldResCollPolyTomeName_t **SetfldResCollPolyTomeName(u8 **pData, s32 size, s32 addr);
fldResCollision_t *SetfldResCollision(u8 **pData, s32 addr);
fldResCollisionPoly_t *SetfldResCollisionPoly(u8 **pData, s32 addr);
fldResCollisionPolyFace_t **SetfldResCollisionPolyFace(u8 **pData, s32 size, s32 addr);
sdfVector4_t **SetfldResCollisionpVertex(u8 **pData, s32 size, s32 addr);
fldResEvent_t *SetfldResEvent(u8 **pData, s32 addr);
fldResHeadAreaName_t *SetfldResHeadAreaName(u8 **pData, s32 addr);
fldResHeadLink_t *SetfldResHeadLink(u8 **pData, s32 addr);
fldResHeadLinkData_t *SetfldResHeadLinkData(u8 **pData, s32 *addr);
fldResHeadPos_t *SetfldResHeadPos(u8 **pData, s32 addr);
fldResModel_t *SetfldResModel(u8 **pData, s32 addr);
fldResPut_t *SetfldResPut(u8 **pData, s32 addr, fldResPut_t *pPut);
fldResPutSE_t *SetfldResPutSE(u8 **pData, s32 addr);
fldResHead_t **SetfldResourceDataTable(u8 **pData, u32 size, s32 addr);
fldResourceEffect_t *SetfldResourceEffect(u8 **pData, s32 addr);
fldResourceLight_t *SetfldResourceLight(u8 **pData, s32 addr);
fldResourcePathData_t_Float *SetfldResourcePathData_Float(u8 **pData, s32 addr);
fldResourcePathData_t_Light *SetfldResourcePathData_Light(u8 **pData, s32 addr);
fldResourcePathData_t_Vector3 *SetfldResourcePathData_Vector3(u8 **pData, s32 addr);
fldResourcePathData_t_Vector4 *SetfldResourcePathData_Vector4(u8 **pData, s32 addr);
fldResourcePathTable_t **SetfldResourcePathTable(u8 **pData, s32 size, s32 addr);
fldResourcePathTableInfo_t *SetfldResourcePathTableInfo(u8 **pData, s32 addr);
u32 **SetfldResourcePathUInt32(u8 **pData, s32 size, s32 addr);
sdfVector3_t **SetfldResourcePathVector3(u8 **pData, s32 size, s32 addr);
sdfVector4_t **SetfldResourcePathVector4(u8 **pData, s32 size, s32 addr);
fldResourceTypeTable_t **SetfldResourceTypeTable(u8 **pData, u32 size, s32 addr);
sdfMatDef_t *SetsdfMatDef(u8 **pData, s32 addr);
sdfModelDef_t *SetsdfModelDef(u8 **pData, s32 addr, bool set);
sdfModelNodeDef_t *SetsdfModelNodeDef(u8 **pData, s32 *addr);
sdfMotionCutChunk_t **SetsdfMotionCutChunk(u8 **pData, s32 addr);
sdfMotionCutDef_t **SetsdfMotionCutDef(u8 **pData, s32 size, s32 addr);
sdfMotionNodeDef_t **SetsdfMotionNodeDef(u8 **pData, s32 len, s32 addr);
sdfMotionPlayBook_t *SetsdfMotionPlayBook(u8 **pData, s32 addr);
void billClrTexture(bool allclear);
void billSetTexture(void **pTexture);
dds3Basic_t *dds3AddAreaBasic(u32 serialID, char *pName);
dds3Basic_t *dds3AddCameraObjectBasicTypeFree(u32 serialID, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddD3PEffectObjectBasic2(void *effdata, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddESPEffectObjectBasic(char *name, sdfVector4_t pos, sdfVector4_t rot, f32 r);
dds3Basic_t *dds3AddEventBasic(u32 serialID, void *pData, char *pName);
dds3Basic_t *dds3AddLightObjectBasic(u32 serial);
dds3Basic_t *dds3AddMatterObjectBasic(u32 serialID, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddModelBasic2(u32 serialID, sdfModelDef_t *pModelDef, sdfMotionPlayBook_t *pMotDef, sdfModelTexList_t *pTexList, char *pName);
dds3Basic_t *dds3AddModelRangeBasicNew(u32 serialID, void *pData, sdfVector4_t pos, char *pName);
dds3Basic_t *dds3AddP2AEffectObjectBasic(char *file, sdfVector4_t pos, sdfVector4_t rot, char *akey);
dds3Basic_t *dds3AddP2AEffectObjectBasic3(dds3Basic_t **ebasic, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddPathBasic(u32 serialID, void *pData, char *pName);
dds3Basic_t *dds3AddPointBasic(u32 serialID, fldResourcePoint_t *pData, char *pName);
dds3Basic_t *dds3AddTMXEffectObjectBasic(char *file, sdfVector4_t pos, sdfVector4_t rot, char *akey);
dds3Basic_t *dds3AddTMXEffectObjectBasic3(dds3Basic_t **ebasic, sdfVector4_t pos, sdfVector4_t rot);
void dds3EffectObjectBasicSetFldEx(dds3Basic_t **basic, fldResourceEffect_t **pResEff);
void dds3EffectObjectBasicStatOff(dds3Basic_t **basic, u32 s);
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3GetMapNo(dds3Basic_t **scene);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ObjectBaseControlWorkData_t *dds3MatterObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
void dds3MatterObjectBasicSetAlpMode(dds3Basic_t **aPtr, s32 alpmode);
void dds3MatterObjectBasicSetHojiID(dds3Basic_t **aPtr, s32 hojiID);
void dds3MatterObjectBasicSetOt(dds3Basic_t **aPtr, s32 idx);
void dds3ModelRangeBasicSetBlockID(dds3Basic_t **aPtr, s32 blockID);
dds3PathBasicControl_t *dds3MoverBasicGetPathControl(dds3Basic_t **pMoverBasic);
void dds3MoverBasicMakePath(dds3Basic_t **pMoverBasic);
void dds3MoverBasicSetPath(dds3Basic_t **pMoverBasic, dds3Basic_t **pPathBasic);
s32 dds3MoverBasicUpdate(dds3Basic_t **pBasic);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseMakeMatter(dds3Basic_t **pObjectBasic);
s32 dds3ObjectBaseRegistArea(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3ObjectBaseSetControlBasic(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic);
void dds3PathBasicControlAlterMode(dds3PathBasicControl_t **pControl, u32 mode);
s32 dds3SceneBasicLoadScriptFile(dds3Basic_t **scene, char *scrfile, char *akey);
s32 dds3SceneBasicLoadScriptFile_FromMem(dds3Basic_t **scene, void *mem);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
u32 dds3SerializeID(void);
void dds3SetBasicName(dds3Basic_t **basic, char *name);
void dds3SetLightObjectResoruce(dds3Basic_t **basic, fldResourceLight_t *resource);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius);
bool evtBitCheck(s32 no);
void evtPathRate(dds3Basic_t *basic, f32 rate);
void evtUpdateEx_FieldLoadAfter(FieldBgHD *fobj, void *rootobj, char *mname);
void fldAddCollisionPoly(fldResCollisionPoly_t *pDataPoly, sdfVector4_t pos, s32 resID, s32 hojiID, s32 npcID);
fldFileInfoHeaderFL1_t *fldAddressResolverFL1(u8 **pData);
fldFileInfoHeaderFL2_t *fldAddressResolverFL2(u8 **pData);
void fldAutoMapDelete(void);
void fldAutoMapModelLoad(void);
void fldAutoMapSetField(s32 fld, s32 area, s32 block);
void fldClrCollision(void);
s32 fldCommand_GetHojiID(char **pName);
s32 fldCommand_SEARCH_ID(char **pName);
void fldDbgPrintStr2DC(s32 x, s32 y, s32 col, char *str, s32 second);
void fldDoorLoad(s32 field);
void fldDoor_AllSet(void);
void fldDrwZAlloc(void);
s32 fldEveHit_AddEveData(fldResHead_t *pEve, dds3Basic_t *pBasic);
s32 fldEveHit_AddEveHit(fldResHead_t *pEvnRng, dds3Basic_t *pBasic);
void fldEveHit_Init(void);
void fldFileResolverFL1(fldFileInfoHeaderFL1_t *pInfoHeaderFL1, u8 **pHead, char *akey);
void fldFileResolverFL2(fldFileInfoHeaderFL2_t *pInfoHeaderFL2, u8 **pHead);
s32 fldGbChkAnime(s32 fld, s32 area, s32 blk);
s32 fldGbChkGimic(s32 fld, s32 area, s32 hojiID);
s32 fldGbChkHit(s32 fld, s32 area, s32 blk);
s32 fldGbChkView(s32 fld, s32 area, s32 blk);
dds3Basic_t *fldGetMatter_From_ModelRangeID(s32 modelRangeID);
dds3Basic_t *fldHitGetMatter(s32 HitResID);
void fldHitLinkMatter(s32 HitResID, dds3Basic_t *matter);
void fldInfLoad(s32 field);
void fldItemBoxAdd(s32 idx, f32 x, f32 y, f32 z, sdfVector4_t rot);
void fldLoad_BasicLightLoadAfter(s32 fld_id, s32 area_id, fldResourceLight_t **pLight, sdfVector4_t *pos, char *name);
void fldMakeBlockBasicFL2(fldConstruntAreaFL2_t **pBlockTable, u32 nBlock);
dds3Basic_t *fldMakeDmyMatter(void);
void fldMakeFilePath(char **pathstr, s32 field, s32 area);
void fldMakeObjectBasic2(void);
void fldMakeObjectBasic3(void);
void fldMakeResouceBasicFL1(fldResourceTypeTable_t **pTypeTable, u32 nTypeTable, u8 **pHead);
void fldMakeResouceBasicFL2(fldResourceTypeTable_t **pTypeTable, u32 nTypeTable, u8 **pHead);
void fldNpcAdd(s32 Type, f32 x, f32 y, f32 z, sdfVector4_t rot, s32 hojiID, char **name, s32 eveidx);
void fldNpcClear(bool clrflg);
void fldNpcLightLoad(s32 field);
void fldNpcLoad(void);
void fldPlayerALoad(void);
void fldSe_Add(s32 id, f32 r, f32 x, f32 y, f32 z);
void fldSe_Init(void);
void fldSe_Kill(void);
void fldSetupButtonGuide(void);
void fldSkyFieldLoad(s32 field);
void fldSkySetTblIdxInit(s32 idx);
void fldTakaraWorkClear(void);
s32 fldTitleChk(void);
s32 fldTitleMiniChk(void);
void *nbFldCache_ToField(char *fld_name);
void *nbFldCache_ToField_F(char *fld_name);
bool nbNoDestroy_MoveCache_Field_F(void *modelobj);
void sdfAddressResolverUnity(u8 **aDataBody, u32 aOffset, u8 **aAddrInfoPtr, u32 aAddrOfs, s32 aAddrInfoLeng);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
sdfModelTexList_t *sdfDevLoadTexList(char *aFilename);
void tpAlfRaitoSet(f32 raito);

// 0x12767b0
void ChangeMaterial(void **List1, void ***List2, void *mat_black, void *mat_white, void *mat_line) {
    GetChildren(0);
}

// 0x1276c10
void DelAutoMapObj(void **AutoMapObj, void ***List1, void ****List2) {
  UnityEngine_Object_o *v7;
  UnityEngine_Object_o *v9;
  u64 v10;
  u64 v12;
  UnityEngine_GameObject_array_array *v13;
  Il2CppClass **v14;
  UnityEngine_GameObject_array *v17;
  UnityEngine_GameObject_array *v19;
  il2cpp_array_size_t max_length;
  u64 v21;

  v7 = *AutoMapObj;
  if (op_Inequality(v7, 0, 0))
  {
    v9 = *AutoMapObj;
    Destroy_27360000(v9);
    if (SLODWORD((*List1)->max_length) >= 1)
    {
      v10 = 0;
      do
      {
        if ((*List2)->m_Items[v10])
        {
          v12 = 0;
          v13 = *List2;
          while (v12 < SLODWORD(v13->m_Items[v10]->max_length))
          {
            v17 = (*List2)->m_Items[v10];
            v14 = &v17->obj.klass + v12++;
            v14[4] = 0;
            v13 = *List2;
            if (v10 >= LODWORD((*List2)->max_length))
          }
        }
        v19 = *List1;
        max_length = (*List1)->max_length;
        ++v10;
      }
      while (v10 < max_length);
      if (max_length >= 1)
      {
        v21 = 0;
        do
        {
          if (v19)
          {
            v19->m_Items[v21] = 0;
            v19 = *List1;
          }
          ++v21;
        }
        while (v21 < SLODWORD(v19->max_length));
      }
    }
    *AutoMapObj = 0;
  }
}

// 0x1276510
void GetChildList(void *AutoMapObj, void ***List1, void ****List2) {
  UnityEngine_GameObject_array *Children;
  UnityEngine_GameObject_array_array *v8;
  UnityEngine_GameObject_array *v10;
  u32 *v11;
  u64 v12;
  UnityEngine_GameObject_o *v14;
  s64 *v15;
  u64 v20;
  UnityEngine_GameObject_array_array *v21;
  UnityEngine_GameObject_array *v24;
  UnityEngine_GameObject_o *v26;

  Children = GetChildren(AutoMapObj, List1);
  *List1 = Children;
  v8 = NewSpecific(UnityEngine_GameObject__, LODWORD(Children->max_length));
  *List2 = v8;
  v10 = *List1;
  if (SLODWORD((*List1)->max_length) >= 1)
  {
    v11 = v8;
    v12 = 0;
    while (1)
    {
      v14 = v10->m_Items[v12];
      else
      {
        v15 = GetChildren(v14);
        if (!v15)
      }
      *&v11[2 * v12 + 8] = v15;
      if ((*List2)->m_Items[v12])
      {
        v20 = 0;
        v21 = *List2;
        while (v20 < SLODWORD(v21->m_Items[v12]->max_length))
        {
          v24 = (*List2)->m_Items[v12];
          v26 = v24->m_Items[v20];
          cmpSetupObject(v26, 0);
          ++v20;
          v21 = *List2;
          if (v12 >= LODWORD((*List2)->max_length))
        }
      }
      v10 = *List1;
      if (++v12 >= SLODWORD((*List1)->max_length))
        return;
      v11 = *List2;
      if (v12 >= LODWORD(v10->max_length))
    }
  }
}

// 0x12763a0
void **GetChildren(void *parentObj) {
  u32 *v3;
  UnityEngine_Transform_o *transform;
  s32 childCount;
  s64 v6;
  u64 i;
  UnityEngine_Transform_o *v9;
  UnityEngine_Component_o *Child;
  s64 *gameObject;
  s64 *v12;

  v3 = 0;
  if (!op_Equality(parentObj, 0, 0))
  {
    transform = get_transform(parentObj, 0);
    childCount = get_childCount(transform);
    if (childCount < 1)
    {
      return 0;
    }
    else
    {
      v6 = childCount;
      v3 = NewSpecific(UnityEngine_GameObject, childCount);
      for (i = 0; i != v6; ++i)
      {
        v9 = get_transform(parentObj, 0);
        Child = GetChild(v9, i);
        gameObject = get_gameObject(Child);
        v12 = gameObject;
        *&v3[2 * i + 8] = v12;
      }
    }
  }
  return v3;
}

// 0x1271f90
char *GetStringToByte(u8 **pData, s32 addr) {
  char *v5;
  u64 v6;
  u64 *v8;
  u64 *v9;
  u64 v10;
  char *v11;
  u32 v12;
  System_Text_Encoding_o *ASCII;

  if (!addr)
    return 0;
  v5 = pData + addr;
  v6 = 0;
  while (v5[v6 + 32])
  {
    if ((addr + ++v6) >= LODWORD(pData->max_length))
  }
  v8 = NewSpecific(byte, v6);
  v9 = v8;
  v10 = 0;
  v11 = v5 + 32;
  v12 = addr;
  while (v11[v10])
  {
    *(v8 + v10 + 32) = v11[v10];
    v12 = addr + ++v10;
    if ((addr + v10) >= LODWORD(pData->max_length))
  }
  ASCII = get_ASCII();
  return (ASCII->klass[1]._1.byval_arg.data)(ASCII, v9, *&ASCII->klass[1]._1.byval_arg.bits);
}

// 0x1272860
fldConstruntAreaFL2_t **SetfldConstruntAreaFL2(u8 **pData, u32 size, s32 addr) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 *v10;
  u64 v11;
  fldConstruntAreaFL2_t_o *v12;
  s64 v17;
  s32 v18;
  s32 v21;
  s64 v23;
  u32 v24;

  v7 = size;
  v8 = NewSpecific(fldConstruntAreaFL2_t, size);
  v9 = v8;
  if (size)
  {
    v10 = v8 + 8;
    v11 = 0;
    do
    {
      v12 = Allocate(fldConstruntAreaFL2_t);
      fldConstruntAreaFL2_t___ctor(v12);
      v10[v11] = v12;
      v12->flag = ToUInt32(pData, addr, 0);
      v17 = v10[v11];
      v18 = addr + 4;
      v21 = ToInt32(pData, v18, 0);
      *(v17 + 24) = GetStringToByte(pData, v21);
      v23 = v10[v11];
      v24 = ToUInt32(pData, v18 + 4, 0);
      ++v11;
      addr = v18 + 8;
      *(v23 + 32) = v24;
    }
    while (v7 != v11);
  }
  return v9;
}

// 0x1273eb0
u32 SetfldEveType(u8 **pData, s32 addr, fldResPut_t *pPut) {
  struct fldResPutEveBall_t_o *pEveBall;

  if (pPut)
  {
    pEveBall = pPut->pEveBall;
    if (pEveBall)
      return pEveBall->Type;
    else
      return 0;
  }
  else
  {
    return ToUInt32(pData, addr, 0);
  }
}

// 0x1272470
fldFileAreaDataFL1_t *SetfldFileAreaDataFL1(u8 **pData, s32 addr) {
  fldFileAreaDataFL1_t_o *v5;
  s32 v9;
  s32 v10;
  s32 v12;
  s32 v14;

  v5 = Allocate(fldFileAreaDataFL1_t);
  fldFileAreaDataFL1_t___ctor(v5);
  v5->fileID = ToUInt32(pData, addr, 0);
  v5->SkyTblIdx = ToUInt32(pData, addr + 4, 0);
  v9 = ToInt32(pData, addr + 8, 0);
  v5->filename0 = GetStringToByte(pData, v9);
  v10 = ToInt32(pData, addr + 12, 0);
  v5->filename1 = GetStringToByte(pData, v10);
  v12 = ToInt32(pData, addr + 16, 0);
  v5->filename2 = GetStringToByte(pData, v12);
  v14 = ToInt32(pData, addr + 20, 0);
  v5->filename3 = GetStringToByte(pData, v14);
  return v5;
}

// 0x1272720
fldFileAreaDataFL2_t *SetfldFileAreaDataFL2(u8 **pData, s32 addr) {
  fldFileAreaDataFL2_t_o *v5;
  s32 v9;
  System_String_o *StringToByte;
  s32 v12;

  v5 = Allocate(fldFileAreaDataFL2_t);
  fldFileAreaDataFL2_t___ctor(v5);
  v5->fileID = ToUInt32(pData, addr, 0);
  v9 = ToInt32(pData, addr + 4, 0);
  StringToByte = GetStringToByte(pData, v9);
  v5->label = StringToByte;
  if (StringToByte)
  {
    v12 = v9 + get_Length(StringToByte) + 1;
  }
  else
  {
    v12 = addr + 8;
  }
  v5->areaFrameno = ToInt32(pData, v12, 0);
  return v5;
}

// 0x126f280
fldResCam_t *SetfldResCam(u8 **pData, s32 addr) {
  fldResCam_t_o *v5;

  v5 = Allocate(fldResCam_t);
  fldResCam_t___ctor(v5);
  v5->fovy = ToSingle(pData, addr, 0);
  return v5;
}

// 0x1273bd0
fldResCollPolyTome_t *SetfldResCollPolyTome(u8 **pData, s32 addr) {
  fldResCollPolyTome_t_o *v5;
  s32 v7;
  s32 v10;
  s32 v11;

  v5 = Allocate(fldResCollPolyTome_t);
  fldResCollPolyTome_t___ctor(v5);
  v7 = ToInt32(pData, addr, 0);
  v5->Num = v7;
  v10 = v7;
  v11 = addr + 4;
  v5->TomeName = SetfldResCollPolyTomeName(pData, v10, v11);
  return v5;
}

// 0x1273cb0
fldResCollPolyTomeName_t **SetfldResCollPolyTomeName(u8 **pData, s32 size, s32 addr) {
  u32 *v7;
  u64 v8;
  u32 *v9;
  fldResCollPolyTomeName_t_o *v10;
  s32 v16;
  s64 v18;
  s32 v19;

  if (size < 1)
    return 0;
  v7 = NewSpecific(fldResCollPolyTomeName_t, size);
  v8 = 0;
  v9 = v7 + 8;
  do
  {
    v10 = Allocate(fldResCollPolyTomeName_t);
    fldResCollPolyTomeName_t___ctor(v10);
    *&v9[2 * v8] = v10;
    v16 = ToInt32(pData, addr, 0);
    v10->Name = GetStringToByte(pData, v16);
    v18 = *&v9[2 * v8];
    v19 = ToInt32(pData, addr + 4, 0);
    ++v8;
    addr += 8;
    *(v18 + 24) = v19;
  }
  while (size != v8);
  return v7;
}

// 0x1263340
fldResCollision_t *SetfldResCollision(u8 **pData, s32 addr) {
  fldResCollision_t_o *v5;

  v5 = Allocate(fldResCollision_t);
  fldResCollision_t___ctor(v5);
  v5->Type = ToUInt32(pData, addr, 0);
  v5->Attr = ToUInt32(pData, addr + 4, 0);
  v5->_union = ToUInt32(pData, addr + 8, 0);
  return v5;
}

// 0x1263410
fldResCollisionPoly_t *SetfldResCollisionPoly(u8 **pData, s32 addr) {
  fldResCollisionPoly_t_o *v5;
  u32 v7;
  s32 nVertex;
  s32 v11;
  UnityEngine_Vector4_array *v12;
  s32 nFace;
  s32 v14;
  s32 v16;

  v5 = Allocate(fldResCollisionPoly_t);
  fldResCollisionPoly_t___ctor(v5);
  v5->nVertex = ToUInt32(pData, addr, 0);
  v5->nFace = ToUInt32(pData, addr + 4, 0);
  v7 = ToUInt32(pData, addr + 8, 0);
  nVertex = v5->nVertex;
  v5->n3 = v7;
  v11 = ToInt32(pData, addr + 12, 0);
  v12 = SetfldResCollisionpVertex(pData, nVertex, v11);
  nFace = v5->nFace;
  v5->pVertex = v12;
  v14 = ToInt32(pData, addr + 16, 0);
  v5->pFace = SetfldResCollisionPolyFace(pData, nFace, v14);
  v16 = ToInt32(pData, addr + 20, 0);
  v5->pTome = SetfldResCollPolyTome(pData, v16);
  return v5;
}

// 0x12736c0
fldResCollisionPolyFace_t **SetfldResCollisionPolyFace(u8 **pData, s32 size, s32 addr) {
  u32 *v7;
  u64 v8;
  fldResCollisionPolyFace_t_o *v9;
  u32 *v11;
  u32 *v12;
  s64 v15;
  char *v18;
  s64 v19;
  s64 v23;
  s64 v25;
  s64 v26;
  char *v29;
  s64 v30;
  s64 v34;
  u64 v35;
  s64 v37;
  s64 v39;
  s64 v40;
  u32 v41;
  s64 v44;
  s64 v46;
  s64 v48;
  s64 v50;
  s32 v51;

  v50 = size;
  v7 = NewSpecific(fldResCollisionPolyFace_t, size);
  if (size >= 1)
  {
    v8 = 0;
    do
    {
      v9 = Allocate(fldResCollisionPolyFace_t);
      fldResCollisionPolyFace_t___ctor(v9);
      v11 = &v7[2 * v8];
      *(v11 + 4) = v9;
      v12 = v11 + 8;
      v9->Attr = ToUInt32(pData, addr, 0);
      v15 = addr + 4LL;
      v18 = pData + v15;
      v19 = addr + 5LL;
      *(*v12 + 20LL) = v18[32];
      *(*v12 + 21LL) = pData->m_Items[v19];
      v23 = *v12;
      *(v23 + 22) = ToUInt16(pData, addr + 6);
      v25 = *v12;
      *(v25 + 24) = ToUInt16(pData, addr + 8);
      v26 = addr + 10LL;
      v29 = pData + v26;
      v30 = addr + 11LL;
      *(*v12 + 26LL) = v29[32];
      *(*v12 + 27LL) = pData->m_Items[v30];
      v51 = addr;
      v34 = *v12;
      v35 = 0;
      *(v34 + 32) = NewSpecific(uint, 4u);
      v37 = 32;
      while (1)
      {
        v39 = *v12;
        if (v37 == 48)
          break;
        v40 = *(v39 + 32);
        v41 = ToUInt32(pData, v51 + v37 - 20, 0);
        *(v40 + v37) = v41;
        ++v35;
        v37 += 4;
        if (v8 >= v7[6])
      }
      *(v39 + 40) = ToInt16(pData, v51 + 28, 0);
      v44 = *v12;
      *(v44 + 42) = ToInt16(pData, v51 + 30, 0);
      v46 = *v12;
      *(v46 + 44) = ToInt16(pData, v51 + 32, 0);
      v48 = *v12;
      addr = v51 + 36;
      ++v8;
      *(v48 + 46) = ToInt16(pData, v51 + 34, 0);
    }
    while (v8 != v50);
  }
  return v7;
}

// 0x12734d0
sdfVector4_t **SetfldResCollisionpVertex(u8 **pData, s32 size, s32 addr) {
    return 0;
}

// 0x126eea0
fldResEvent_t *SetfldResEvent(u8 **pData, s32 addr) {
  fldResEvent_t_o *v5;
  s32 v9;

  v5 = Allocate(fldResEvent_t);
  fldResEvent_t___ctor(v5);
  v5->flag = ToUInt32(pData, addr, 0);
  v9 = ToInt32(pData, addr + 4, 0);
  v5->label = GetStringToByte(pData, v9);
  return v5;
}

// 0x12730a0
fldResHeadAreaName_t *SetfldResHeadAreaName(u8 **pData, s32 addr) {
  fldResHeadAreaName_t_o *v5;
  s32 v9;

  if (!addr)
    return 0;
  v5 = Allocate(fldResHeadAreaName_t);
  fldResHeadAreaName_t___ctor(v5);
  v5->num = ToUInt32(pData, addr, 0);
  v9 = ToInt32(pData, addr + 4, 0);
  v5->name = GetStringToByte(pData, v9);
  return v5;
}

// 0x1273190
fldResHeadLink_t *SetfldResHeadLink(u8 **pData, s32 addr) {
  fldResHeadLink_t_o *v5;
  u32 v7;
  struct fldResHeadLinkData_t_array *v8;
  u32 num;
  s64 v10;
  u32 *v11;
  u64 v12;
  u64 *v13;
  u32 *data;
  s64 *v18;
  s64 *v19;
  s32 addra;

  addra = addr;
  if (!addr)
    return 0;
  v5 = Allocate(fldResHeadLink_t);
  fldResHeadLink_t___ctor(v5);
  v7 = ToUInt32(pData, addr, 0);
  v5->num = v7;
  addra = addr + 4;
  v8 = NewSpecific(fldResHeadLinkData_t, v7);
  num = v5->num;
  v5->data = v8;
  if (num)
  {
    v10 = 4;
    v11 = v8;
    while (1)
    {
      v12 = v10 - 4;
      v13 = Allocate(fldResHeadLinkData_t);
      fldResHeadLinkData_t___ctor(v13);
      *&v11[2 * v10] = v13;
      data = v5->data;
      v18 = SetfldResHeadLinkData(pData, &addra);
      v19 = v18;
      *&data[2 * v10] = v19;
      if (v10 - 3 >= v5->num)
        break;
      v11 = v5->data;
      ++v10;
    }
  }
  return v5;
}

// 0x12733b0
fldResHeadLinkData_t *SetfldResHeadLinkData(u8 **pData, s32 *addr) {
  fldResHeadLinkData_t_o *v5;
  s32 v7;
  s32 v8;
  s32 v11;
  s32 v12;

  v5 = Allocate(fldResHeadLinkData_t);
  fldResHeadLinkData_t___ctor(v5);
  v7 = *addr;
  v5->mode = ToUInt32(pData, v7, 0);
  v8 = *addr + 4;
  *addr = v8;
  v11 = ToInt32(pData, v8, 0);
  v5->name = GetStringToByte(pData, v11);
  v12 = *addr + 4;
  *addr = v12;
  v5->scl = ToUInt32(pData, v12, 0);
  *addr += 4;
  return v5;
}

// 0x1272e70
fldResHeadPos_t *SetfldResHeadPos(u8 **pData, s32 addr) {
    return 0;
}

// 0x126ff60
fldResModel_t *SetfldResModel(u8 **pData, s32 addr) {
  fldResModel_t_o *v5;

  v5 = Allocate(fldResModel_t);
  fldResModel_t___ctor(v5);
  v5->Flag = ToUInt32(pData, addr, 0);
  v5->nLod = ToUInt32(pData, addr + 4, 0);
  v5->dmy = ToUInt32(pData, addr + 8, 0);
  v5->dmy2 = ToUInt32(pData, addr + 12, 0);
  v5->pMdl = ToUInt32(pData, addr + 16, 0);
  v5->pMat = ToUInt32(pData, addr + 20, 0);
  v5->dmy3 = ToUInt32(pData, addr + 24, 0);
  v5->dmy4 = ToUInt32(pData, addr + 28, 0);
  v5->pMot = ToUInt32(pData, addr + 32, 0);
  return v5;
}

// 0x126ef90
fldResPut_t *SetfldResPut(u8 **pData, s32 addr, fldResPut_t *pPut) {
  fldResPut_t_o *v7;

  v7 = Allocate(fldResPut_t);
  fldResPut_t___ctor(v7);
  if (!pPut)
  {
    v7->Type = ToUInt32(pData, addr, 0);
    v7->EveIdx = ToUInt32(pData, addr + 4, 0);
    v7->Visible = ToUInt32(pData, addr + 8, 0);
    pPut = v7;
    v7->_union = ToUInt32(pData, addr + 12, 0);
    v7->pDate = pData;
    v7->pEveBall = 0;
  }
  return pPut;
}

// 0x1273f60
fldResPutEveBall_t *SetfldResPutEveBall(u8 **pData, s32 addr, fldResPut_t *pPut) {
  fldResPutEveBall_t_o *v7;

  v7 = Allocate(fldResPutEveBall_t);
  fldResPutEveBall_t___ctor(v7);
  if (pPut)
    return pPut->pEveBall;
  v7->Type = ToUInt32(pData, addr, 0);
  v7->r = ToSingle(pData, addr + 4, 0);
  return v7;
}

// 0x1275b40
fldResPutEveBox_t *SetfldResPutEveBox(u8 **pData, s32 addr) {
  fldResPutEveBox_t_o *v5;

  v5 = Allocate(fldResPutEveBox_t);
  fldResPutEveBox_t___ctor(v5);
  v5->Type = ToUInt32(pData, addr, 0);
  v5->y = ToSingle(pData, addr + 4, 0);
  v5->x = ToSingle(pData, addr + 8, 0);
  v5->z = ToSingle(pData, addr + 12, 0);
  return v5;
}

// 0x1275a70
fldResPutEvePoly_t *SetfldResPutEvePoly(u8 **pData, s32 addr) {
  fldResPutEvePoly_t_o *v5;

  v5 = Allocate(fldResPutEvePoly_t);
  fldResPutEvePoly_t___ctor(v5);
  v5->Type = ToUInt32(pData, addr, 0);
  v5->y = ToSingle(pData, addr + 4, 0);
  v5->z = ToSingle(pData, addr + 8, 0);
  return v5;
}

// 0x126f120
fldResPutItemBox_t *SetfldResPutItemBox(u8 **pData, s32 addr) {
  fldResPutItemBox_t_o *v5;

  v5 = Allocate(fldResPutItemBox_t);
  fldResPutItemBox_t___ctor(v5);
  v5->id = ToUInt32(pData, addr, 0);
  return v5;
}

// 0x126f080
fldResPutNpc_t *SetfldResPutNpc(u8 **pData, s32 addr) {
  fldResPutNpc_t_o *v5;

  v5 = Allocate(fldResPutNpc_t);
  fldResPutNpc_t___ctor(v5);
  v5->id = ToUInt32(pData, addr, 0);
  return v5;
}

// 0x126f1c0
fldResPutSE_t *SetfldResPutSE(u8 **pData, s32 addr) {
  fldResPutSE_t_o *v5;

  v5 = Allocate(fldResPutSE_t);
  fldResPutSE_t___ctor(v5);
  v5->r = ToSingle(pData, addr, 0);
  v5->id = ToInt32(pData, addr + 4, 0);
  return v5;
}

// 0x1272a80
fldResHead_t **SetfldResourceDataTable(u8 **pData, u32 size, s32 addr) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 *v10;
  u64 v11;
  fldResHead_t_o *v12;
  s64 v17;
  s32 v18;
  s64 v20;
  s32 v21;
  s32 v24;
  s64 v26;
  s32 v27;
  s64 v29;
  s32 v30;
  s32 v31;
  s64 v34;
  s32 v35;
  s32 v36;
  s64 v39;
  s32 v40;
  s32 v41;
  s64 v44;
  s32 v45;
  s32 v46;
  s64 v49;
  s32 v50;
  s64 v53;

  v7 = size;
  v8 = NewSpecific(fldResHead_t, size);
  v9 = v8;
  if (size)
  {
    v10 = v8 + 8;
    v11 = 0;
    do
    {
      v12 = Allocate(fldResHead_t);
      fldResHead_t___ctor(v12);
      v10[v11] = v12;
      v12->resourceID = ToUInt32(pData, addr, 0);
      v17 = v10[v11];
      v18 = addr + 4;
      *(v17 + 20) = ToUInt32(pData, v18, 0);
      v20 = v10[v11];
      v21 = v18 + 4;
      v24 = ToInt32(pData, v21, 0);
      *(v20 + 24) = GetStringToByte(pData, v24);
      v26 = v10[v11];
      v27 = v21 + 4;
      *(v26 + 32) = ToUInt32(pData, v27, 0);
      v29 = v10[v11];
      v30 = v27 + 4;
      v31 = ToInt32(pData, v30, 0);
      *(v29 + 40) = SetfldResHeadPos(pData, v31);
      v34 = v10[v11];
      v35 = v30 + 4;
      v36 = ToInt32(pData, v35, 0);
      *(v34 + 48) = SetfldResHeadAreaName(pData, v36);
      v39 = v10[v11];
      v40 = v35 + 4;
      v41 = ToInt32(pData, v40, 0);
      *(v39 + 56) = SetfldResHeadLink(pData, v41);
      v44 = v10[v11];
      v45 = v40 + 4;
      v46 = ToInt32(pData, v45, 0);
      *(v44 + 64) = GetStringToByte(pData, v46);
      v49 = v10[v11];
      v50 = v45 + 4;
      *(v49 + 72) = ToUInt32(pData, v50, 0);
      *(v10[v11] + 80LL) = pData;
      v53 = v10[v11++];
      addr = v50 + 4;
      *(v53 + 88) = 0;
    }
    while (v7 != v11);
  }
  return v9;
}

// 0x1262dc0
fldResourceEffect_t *SetfldResourceEffect(u8 **pData, s32 addr) {
  fldResourceEffect_t_o *v5;
  u32 v7;
  struct System_Single_array *size;
  f32 v9;
  struct System_Single_array *v11;
  f32 v12;
  struct System_Single_array *v14;
  f32 v15;

  v5 = Allocate(fldResourceEffect_t);
  fldResourceEffect_t___ctor(v5);
  v5->flag = ToUInt32(pData, addr, 0);
  v5->type = ToUInt32(pData, addr + 4, 0);
  v7 = ToUInt32(pData, addr + 8, 0);
  size = v5->size;
  v5->noEffect = v7;
  v9 = ToSingle(pData, addr + 12, 0);
  size->m_Items[0] = v9;
  v11 = v5->size;
  v12 = ToSingle(pData, addr + 16, 0);
  v11->m_Items[1] = v12;
  v14 = v5->size;
  v15 = ToSingle(pData, addr + 20, 0);
  v14->m_Items[2] = v15;
  v5->offsetZ = ToUInt32(pData, addr + 24, 0);
  v5->groupID = ToUInt32(pData, addr + 28, 0);
  v5->param0 = ToUInt32(pData, addr + 32, 0);
  v5->param1 = ToUInt32(pData, addr + 36, 0);
  return v5;
}

// 0x12630d0
fldResourceLight_t *SetfldResourceLight(u8 **pData, s32 addr) {
  fldResourceLight_t_o *v5;

  v5 = Allocate(fldResourceLight_t);
  fldResourceLight_t___ctor(v5);
  v5->resv = ToUInt32(pData, addr, 0);
  v5->Flag = ToUInt32(pData, addr + 4, 0);
  v5->AnimeType = ToUInt32(pData, addr + 8, 0);
  v5->InsideR = ToSingle(pData, addr + 12, 0);
  v5->OutsideR = ToSingle(pData, addr + 16, 0);
  v5->Soften = ToSingle(pData, addr + 20, 0);
  v5->Bias = ToSingle(pData, addr + 24, 0);
  v5->DiffuseR = ToSingle(pData, addr + 28, 0);
  v5->DiffuseG = ToSingle(pData, addr + 32, 0);
  v5->DiffuseB = ToSingle(pData, addr + 36, 0);
  v5->AmbientR = ToSingle(pData, addr + 40, 0);
  v5->AmbientG = ToSingle(pData, addr + 44, 0);
  v5->AmbientB = ToSingle(pData, addr + 48, 0);
  return v5;
}

// 0x1274400
fldResourcePathData_t_Float *SetfldResourcePathData_Float(u8 **pData, s32 addr) {
  fldResourcePathData_t_Float_o *v5;
  u32 v7;
  s32 v8;
  s64 v9;
  s32 v10;
  s32 v12;
  s32 v13;
  u64 v14;
  struct System_Single_array *pItem;
  f32 v16;
  f32 *v18;
  s32 v21;

  v5 = Allocate(fldResourcePathData_t_Float);
  fldResourcePathData_t_Float___ctor(v5);
  v7 = ToUInt32(pData, addr, 0);
  v5->nKey = v7;
  v8 = v7;
  v9 = v7;
  v5->pItem = NewSpecific(f32, v7);
  v10 = ToInt32(pData, addr + 4, 0);
  v12 = addr + 8;
  if (v8 >= 1)
  {
    v13 = v10;
    v14 = 0;
    do
    {
      pItem = v5->pItem;
      v16 = ToSingle(pData, v13, 0);
      v18 = (pItem + 4 * v14++);
      v13 += 4;
      v18[8] = v16;
    }
    while (v9 != v14);
  }
  v21 = ToInt32(pData, v12, 0);
  v5->pKey = SetfldResourcePathUInt32(pData, v9, v21);
  return v5;
}

// 0x1274810
fldResourcePathData_t_Light *SetfldResourcePathData_Light(u8 **pData, s32 addr) {
  fldResourcePathData_t_Light_o *v5;
  u32 v7;
  s32 v8;
  s64 v9;
  s32 v10;
  s32 v12;
  s32 v13;
  u64 v14;
  fldResourceLightPath_t_o *v16;
  f32 v18;
  s32 v19;
  u32 *pItem;
  u32 *v22;
  s32 v25;

  v5 = Allocate(fldResourcePathData_t_Light);
  fldResourcePathData_t_Light___ctor(v5);
  v7 = ToUInt32(pData, addr, 0);
  v5->nKey = v7;
  v8 = v7;
  v9 = v7;
  v5->pItem = NewSpecific(fldResourceLightPath_t, v7);
  v10 = ToInt32(pData, addr + 4, 0);
  v12 = addr + 8;
  if (v8 >= 1)
  {
    v13 = v10;
    v14 = 0;
    do
    {
      v16 = Allocate(fldResourceLightPath_t);
      fldResourceLightPath_t___ctor(v16);
      v16->InsideR = ToSingle(pData, v13, 0);
      v16->OutsideR = ToSingle(pData, v13 + 4, 0);
      v16->Soften = ToSingle(pData, v13 + 8, 0);
      v16->Bias = ToSingle(pData, v13 + 12, 0);
      v16->DiffuseR = ToSingle(pData, v13 + 16, 0);
      v16->DiffuseG = ToSingle(pData, v13 + 20, 0);
      v16->DiffuseB = ToSingle(pData, v13 + 24, 0);
      v16->AmbientR = ToSingle(pData, v13 + 28, 0);
      v18 = ToSingle(pData, v13 + 32, 0);
      v19 = v13 + 36;
      v16->AmbientG = v18;
      v16->AmbientB = ToSingle(pData, v19, 0);
      pItem = v5->pItem;
      v22 = &pItem[2 * v14++];
      v13 = v19 + 4;
      *(v22 + 4) = v16;
    }
    while (v9 != v14);
  }
  v25 = ToInt32(pData, v12, 0);
  v5->pKey = SetfldResourcePathUInt32(pData, v9, v25);
  return v5;
}

// 0x12745d0
fldResourcePathData_t_Vector3 *SetfldResourcePathData_Vector3(u8 **pData, s32 addr) {
  fldResourcePathData_t_Vector3_o *v5;
  s32 v7;
  s32 v10;
  s32 v11;

  v5 = Allocate(fldResourcePathData_t_Vector3);
  fldResourcePathData_t_Vector3___ctor(v5);
  v7 = ToUInt32(pData, addr, 0);
  v5->nKey = v7;
  v10 = ToInt32(pData, addr + 4, 0);
  v5->pItem = SetfldResourcePathVector3(pData, v7, v10);
  v11 = ToInt32(pData, addr + 8, 0);
  v5->pKey = SetfldResourcePathUInt32(pData, v7, v11);
  return v5;
}

// 0x12746f0
fldResourcePathData_t_Vector4 *SetfldResourcePathData_Vector4(u8 **pData, s32 addr) {
  fldResourcePathData_t_Vector4_o *v5;
  s32 v7;
  s32 v10;
  s32 v11;

  v5 = Allocate(fldResourcePathData_t_Vector4);
  fldResourcePathData_t_Vector4___ctor(v5);
  v7 = ToUInt32(pData, addr, 0);
  v5->nKey = v7;
  v10 = ToInt32(pData, addr + 4, 0);
  v5->pItem = SetfldResourcePathVector4(pData, v7, v10);
  v11 = ToInt32(pData, addr + 8, 0);
  v5->pKey = SetfldResourcePathUInt32(pData, v7, v11);
  return v5;
}

// 0x1274030
fldResourcePathTable_t **SetfldResourcePathTable(u8 **pData, s32 size, s32 addr) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 v10;
  u64 *v11;
  fldResourcePathTable_t_o *v12;
  s32 v17;
  s64 v19;
  s32 v23;
  void *v24;
  s32 v28;
  s32 v32;
  s32 v36;

  v7 = size;
  v8 = NewSpecific(fldResourcePathTable_t, size);
  v9 = v8;
  if (size >= 1)
  {
    v10 = 0;
    v11 = v8 + 8;
    do
    {
      v12 = Allocate(fldResourcePathTable_t);
      fldResourcePathTable_t___ctor(v12);
      v11[v10] = v12;
      v12->type = ToUInt32(pData, addr, 0);
      v17 = addr + 4;
      v19 = v11[v10];
      switch (*(v19 + 16))
      {
        case 0:
          v23 = ToInt32(pData, v17, 0);
          v24 = SetfldResourcePathData_Vector3(pData, v23);
        case 2:
          v28 = ToInt32(pData, v17, 0);
          v24 = SetfldResourcePathData_Vector4(pData, v28);
        case 4:
          v32 = ToInt32(pData, v17, 0);
          v24 = SetfldResourcePathData_Float(pData, v32);
        case 5:
          v36 = ToInt32(pData, v17, 0);
          v24 = SetfldResourcePathData_Light(pData, v36);
          v17 = addr + 8;
          *(v19 + 24) = v24;
          break;
        default:
          break;
      }
      ++v10;
      addr = v17;
    }
    while (v7 != v10);
  }
  return v9;
}

// 0x1263260
fldResourcePathTableInfo_t *SetfldResourcePathTableInfo(u8 **pData, s32 addr) {
  fldResourcePathTableInfo_t_o *v5;
  u32 v7;
  s32 v10;
  s32 v11;

  v5 = Allocate(fldResourcePathTableInfo_t);
  fldResourcePathTableInfo_t___ctor(v5);
  v7 = ToUInt32(pData, addr, 0);
  v5->nPathTable = v7;
  v10 = v7;
  v11 = addr + 4;
  v5->pPathTableDat = SetfldResourcePathTable(pData, v10, v11);
  return v5;
}

// 0x1274af0
u32 **SetfldResourcePathUInt32(u8 **pData, s32 size, s32 addr) {
  s64 v7;
  u64 *v9;
  u64 v10;
  u32 v11;

  v7 = size;
  v9 = NewSpecific(uint, size);
  if (size >= 1)
  {
    v10 = 0;
    do
    {
      v11 = ToUInt32(pData, addr, 0);
      *(v9 + v10++ + 8) = v11;
      addr += 4;
    }
    while (v7 != v10);
  }
  return v9;
}

// 0x1274bf0
sdfVector3_t **SetfldResourcePathVector3(u8 **pData, s32 size, s32 addr) {
    return 0;
}

// 0x1274d50
sdfVector4_t **SetfldResourcePathVector4(u8 **pData, s32 size, s32 addr) {
    return 0;
}

// 0x1272230
fldResourceTypeTable_t **SetfldResourceTypeTable(u8 **pData, u32 size, s32 addr) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 v10;
  u64 *v11;
  fldResourceTypeTable_t_o *v13;
  s64 v17;
  s32 v18;
  s64 v20;
  u32 v21;
  s32 v22;
  s32 v25;

  v7 = size;
  v8 = NewSpecific(fldResourceTypeTable_t, size);
  v9 = v8;
  if (size)
  {
    v10 = 0;
    v11 = v8 + 8;
    do
    {
      v13 = Allocate(fldResourceTypeTable_t);
      fldResourceTypeTable_t___ctor(v13);
      v11[v10] = v13;
      v13->type = ToUInt32(pData, addr, 0);
      v17 = v11[v10];
      v18 = addr + 4;
      *(v17 + 20) = ToUInt32(pData, v18, 0);
      v20 = v11[v10];
      v21 = *(v20 + 20);
      v22 = v18 + 4;
      v25 = ToInt32(pData, v22, 0);
      ++v10;
      addr = v22 + 4;
      *(v20 + 24) = SetfldResourceDataTable(pData, v21, v25);
    }
    while (v7 != v10);
  }
  return v9;
}

// 0x1274ed0
sdfMatDef_t *SetsdfMatDef(u8 **pData, s32 addr) {
  sdfMatDef_t_o *v5;

  v5 = Allocate(sdfMatDef_t);
  sdfMatDef_t___ctor(v5);
  v5->id = ToUInt32(pData, addr, 0);
  v5->flags = ToUInt16(pData, addr + 4);
  v5->parmBits = ToUInt16(pData, addr + 6);
  return v5;
}

// 0x12700a0
sdfModelDef_t *SetsdfModelDef(u8 **pData, s32 addr, bool set) {
    SetsdfMatDef(0, 0);
    SetsdfModelNodeDef(0, 0);
    return 0;
}

// 0x1274fa0
sdfModelNodeDef_t *SetsdfModelNodeDef(u8 **pData, s32 *addr) {
    return 0;
}

// 0x1275770
sdfMotionCutChunk_t **SetsdfMotionCutChunk(u8 **pData, s32 addr) {
  sdfMotionCutChunk_t_array *v5;
  sdfMotionCutChunk_t_o *v6;
  sdfMotionCutChunk_t_o *v9;
  sdfMotionCutChunk_t_o *v11;
  sdfMotionCutChunk_t_o *v13;
  sdfMotionCutChunk_t_o *v14;
  u64 v15;
  u64 v17;
  s32 v18;
  struct System_UInt16_array *keyFrameList;
  u16 v21;
  char *v23;

  v5 = NewSpecific(sdfMotionCutChunk_t, 1u);
  v6 = Allocate(sdfMotionCutChunk_t);
  sdfMotionCutChunk_t___ctor(v6);
  v5->m_Items[0] = v6;
  v6->size = ToUInt32(pData, addr, 0);
  v9 = v5->m_Items[0];
  v9->numOfKey = ToUInt16(pData, addr + 4);
  v11 = v5->m_Items[0];
  v11->keyElemSize = ToUInt16(pData, addr + 6);
  v13 = v5->m_Items[0];
  v13->pad = ToUInt32(pData, addr + 8, 0);
  v14 = v5->m_Items[0];
  v15 = v14->numOfKey * (v14->keyElemSize >> 1);
  v14->keyFrameList = NewSpecific(ushort, v15);
  if (v15)
  {
    v17 = 0;
    v18 = addr + 12;
    do
    {
      keyFrameList = v5->m_Items[0]->keyFrameList;
      v21 = ToUInt16(pData, v18);
      v23 = keyFrameList + 2 * v17++;
      v18 += 2;
      *(v23 + 16) = v21;
    }
    while (v15 != v17);
  }
  return v5;
}

// 0x12753d0
sdfMotionCutDef_t **SetsdfMotionCutDef(u8 **pData, s32 size, s32 addr) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 *v10;
  u64 v11;
  u64 *v13;
  s32 v16;
  s64 v18;
  s32 v21;
  s64 v23;

  v7 = size;
  v8 = NewSpecific(sdfMotionCutDef_t, size);
  v9 = v8;
  if (size >= 1)
  {
    v10 = v8 + 8;
    v11 = 0;
    do
    {
      v13 = Allocate(sdfMotionCutDef_t);
      sdfMotionCutDef_t___ctor(v13);
      v10[v11] = v13;
      v16 = ToUInt32(pData, addr, 0);
      v18 = v10[v11];
      *(v18 + 16) = ToUInt32(pData, v16, 0);
      v21 = v16 + 4;
      v23 = v10[v11];
      ++v11;
      *(v23 + 24) = SetsdfMotionCutChunk(pData, v21);
    }
    while (v7 != v11);
  }
  return v9;
}

// 0x12755b0
sdfMotionNodeDef_t **SetsdfMotionNodeDef(u8 **pData, s32 len, s32 addr) {
  s64 v7;
  u32 *v8;
  u32 *v9;
  u64 *v10;
  u64 v11;
  sdfMotionNodeDef_t_o *v12;
  s64 v17;
  u32 v18;

  v7 = len;
  v8 = NewSpecific(sdfMotionNodeDef_t, len);
  v9 = v8;
  if (len >= 1)
  {
    v10 = v8 + 8;
    v11 = 0;
    do
    {
      v12 = Allocate(sdfMotionNodeDef_t);
      sdfMotionNodeDef_t___ctor(v12);
      v10[v11] = v12;
      v12->typeId = ToUInt32(pData, addr, 0);
      v17 = v10[v11];
      v18 = ToUInt32(pData, addr + 4, 0);
      ++v11;
      addr += 8;
      *(v17 + 20) = v18;
    }
    while (v7 != v11);
  }
  return v9;
}

// 0x1270380
sdfMotionPlayBook_t *SetsdfMotionPlayBook(u8 **pData, s32 addr) {
  sdfMotionPlayBook_t_o *v5;
  u16 v7;
  s32 numOfCut;
  s32 v11;
  sdfMotionCutDef_t_array *v12;
  s32 numOfNode;

  v5 = Allocate(sdfMotionPlayBook_t);
  sdfMotionPlayBook_t___ctor(v5);
  v5->numOfCut = ToUInt16(pData, addr);
  v7 = ToUInt16(pData, addr + 2);
  numOfCut = v5->numOfCut;
  v5->numOfNode = v7;
  v11 = ToInt32(pData, addr + 4, 0);
  v12 = SetsdfMotionCutDef(pData, numOfCut, v11);
  numOfNode = v5->numOfNode;
  v5->cutList = v12;
  v5->nodeDefList = SetsdfMotionNodeDef(pData, numOfNode, addr + 8);
  return v5;
}

// 0x1271eb0
void fldAddressResolver(u8 **pFileTop, u8 **pData) {
  u32 v5;
  s32 v6;
  u32 v7;

  ToUInt32(pData, 0, 0);
  v5 = ToUInt32(pData, 4, 0);
  v6 = ToInt32(pData, 8, 0);
  v7 = ToUInt32(pFileTop, 0, 0);
  sdfAddressResolverUnity(pFileTop, v7, pFileTop, v5, v6);
}

// 0x1272120
fldFileInfoHeaderFL1_t *fldAddressResolverFL1(u8 **pData) {
  fldFileInfoHeaderFL1_t_o *v3;
  u32 v5;
  s32 v8;
  s32 v9;

  v3 = Allocate(fldFileInfoHeaderFL1_t);
  fldFileInfoHeaderFL1_t___ctor(v3);
  v5 = ToUInt32(pData, 20, 0);
  v3->nResourceTypeTable = v5;
  v8 = ToInt32(pData, 24, 0);
  v3->pResourceTypeTable = SetfldResourceTypeTable(pData, v5, v8);
  v9 = ToInt32(pData, 28, 0);
  v3->pAreaData = SetfldFileAreaDataFL1(pData, v9);
  return v3;
}

// 0x12725d0
fldFileInfoHeaderFL2_t *fldAddressResolverFL2(u8 **pData) {
  fldFileInfoHeaderFL2_t_o *v3;
  u32 v5;
  s32 v8;
  s32 v9;
  u32 v11;
  s32 v12;

  v3 = Allocate(fldFileInfoHeaderFL2_t);
  fldFileInfoHeaderFL2_t___ctor(v3);
  v5 = ToUInt32(pData, 20, 0);
  v3->nResourceTypeTable = v5;
  v8 = ToInt32(pData, 24, 0);
  v3->pResourceTypeTable = SetfldResourceTypeTable(pData, v5, v8);
  v9 = ToInt32(pData, 28, 0);
  v3->pAreaData = SetfldFileAreaDataFL2(pData, v9);
  v11 = ToUInt32(pData, 32, 0);
  v3->nArea = v11;
  v12 = ToInt32(pData, 36, 0);
  v3->pAreaTable = SetfldConstruntAreaFL2(pData, v11, v12);
  return v3;
}

// 0x1271f80
void fldAddressResolverReset(void *pFileTop, void *pData) {
  ;
}

// 0x12793d0
void fldAutoMapDelete(void) {
  autoMapPrefab = StringLiteral_416;
  DelAutoMapObj(&AutoMapObjArea, &mapNodeList1Area, &mapNodeList2Area);
  DelAutoMapObj(&AutoMapObjHalf, &mapNodeList1Half, &mapNodeList2Half);
}

// 0x127aae0
bool fldCheckNextFile(s32 field) {
    IsDLCField(0);
    GetFieldAssetName(0, 0);
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    return 0;
}

// 0x127aa70
void fldFileAddrResetMode(s32 mode) {
  gFldFileResetMode = mode;
}

// 0x12712e0
void fldFileResolverFL1(fldFileInfoHeaderFL1_t *pInfoHeaderFL1, u8 **pHead, char *akey) {
    fldSkySetTblIdxInit(0);
    evtBitCheck(0);
    ChangeCharacter(0, 0, 0);
    LoadTexture_26559536(0, 0, 0);
    billSetTexture(0);
    fldMakeFilePath(0, 0, 0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    fldMakeResouceBasicFL1(0, 0, 0);
}

// 0x1271db0
void fldFileResolverFL2(fldFileInfoHeaderFL2_t *pInfoHeaderFL2, u8 **pHead) {
  fldConstruntAreaFL2_t_array *pAreaTable;
  u32 nArea;

  pAreaTable = pInfoHeaderFL2->pAreaTable;
  nArea = pInfoHeaderFL2->nArea;
  fldMakeBlockBasicFL2(pAreaTable, nArea);
  fldMakeResouceBasicFL2(pInfoHeaderFL2->pResourceTypeTable, pInfoHeaderFL2->nResourceTypeTable, pHead);
  fldGb->startPro = pInfoHeaderFL2->pAreaData->label;
}

// 0x1279a10
void fldFreeFile(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  struct fldGlobalWork_t_o *v8;
  s32 areaID;
  UnityEngine_Object_o *FildMapObj;
  UnityEngine_GameObject_o *v18;
  UnityEngine_Object_o *v20;
  UnityEngine_Object_o *FildMaskObj;
  bool v25;
  UnityEngine_Object_o *v27;
  UnityEngine_Object_o *mat_black;
  UnityEngine_Object_o *v31;
  UnityEngine_Object_o *mat_white;
  UnityEngine_Object_o *v36;
  UnityEngine_Object_o *mat_line;
  UnityEngine_Object_o *v41;

  fldSe_Kill();
  fldSe_Kill();
  else  dds3KillProcessName(StringLiteral_16661, 1);
  else  dds3KillProcessName(StringLiteral_16662, 1);
  fieldID = fldGb->fieldID;
  if (fieldID <= 199)
  {
    if (fldGb->fieldOldID != fieldID)
    {
      fldGb->fieldOldID = fieldID;
    }
    v8 = fldGb;
    areaID = v8->areaID;
    if (v8->areaOldID != areaID)
    {
      v8->areaOldID = areaID;
    }
  }
  if (fldGb->fieldID <= 199)
  {
    fldClrCollision();
    fldEveHit_Init();
    fldSe_Init();
    fldNpcClear(0);
  }
  if (op_Inequality(FildMapObj, 0, 0))
  {
    v18 = FildMapObj;
    if (!nbNoDestroy_MoveCache_Field_F(v18))
    {
      if (!CheckCashField())
      {
        v20 = FildMapObj;
        Destroy_27360000(v20);
      }
    }
    FildMapObj = 0;
  }
  v25 = op_Inequality(FildMaskObj, 0, 0);
  if (v25)
  {
    v27 = FildMaskObj;
    Destroy_27360000(v27);
    FildMaskObj = 0;
  }
  if (op_Inequality(mat_black, 0, 0))
  {
    v31 = mat_black;
    Destroy_27360000(v31);
  }
  mat_black = 0;
  if (op_Inequality(mat_white, 0, 0))
  {
    v36 = mat_white;
    Destroy_27360000(v36);
  }
  mat_white = 0;
  if (op_Inequality(mat_line, 0, 0))
  {
    v41 = mat_line;
    Destroy_27360000(v41);
  }
  mat_line = 0;
  UnloadUnusedAssets();
}

// 0x1275f00
void fldFreeNextFile(void) {
  pFldNextFileDataBF = 0;
  pFldNextFileDataF1 = 0;
  pFldNextFileDataF2 = 0;
  pFldNextFileDataTB = 0;
}

// 0x1276390
void fldFreePac0(void) {
  ;
}

// 0x1271e80
void *fldGetInfoHeader(void *pData) {
  return pData;
}

// 0x1271e90
s32 fldGetInfoHeaderForUnity(void) {
  return 20;
}

// 0x12608e0
dds3Basic_t *fldGetMatter_From_ModelRangeID(s32 modelRangeID) {
  dds3Basic_t_o *ControlScene;
  s64 v6;
  struct fldResHead_t_array *g_pHitData;
  u64 v8;
  Il2CppClass **v10;
  Il2CppClass *v11;
  char *v12;
  Il2CppClass *v13;
  s64 v15;
  u64 i;
  System_String_o *v19;
  dds3Basic_t_o *v20;
  dds3Basic_t_o *Matter;
  s32 name;
  s32 v29;

  ControlScene = dds3GetControlScene();
  v6 = modelRangeID;
  v8 = 0;
  while (1)
  {
    if (v8 >= g_nHitData)
      return 0;
    v10 = &g_pHitData->obj.klass + v8;
    v13 = v10[4];
    v12 = (v10 + 4);
    v11 = v13;
    if (v6 == LODWORD(v13->_1.name))
      break;
    ++v8;
  }
  if (*&v11->_1.this_arg.bits)
  {
    v15 = *(*&v11->_1.this_arg.bits + 24LL);
    for (i = 0; ; ++i)
    {
      if (i >= *(*(*v12 + 56LL) + 16LL))
        break;
      v19 = *(*(v15 + 32 + 8 * i) + 24LL);
      v20 = dds3SceneBasicSearchNameAndType(ControlScene, 6u, v19);
      if (v20)
        return v20;
    }
  }
  name = v11->_1.name;
  Matter = fldHitGetMatter(name);
  if (!Matter)
  {
    Matter = fldMakeDmyMatter();
    v29 = *(*v12 + 16LL);
    fldHitLinkMatter(v29, Matter);
  }
  return Matter;
}

// 0x1260ea0
dds3Basic_t *fldGetModelRange_From_MatterName(char **matterName) {
  dds3Basic_t_o *ControlScene;
  struct fldResHead_t_array *g_pHitData;
  u64 v7;
  Il2CppClass **v9;
  char *v10;
  Il2CppClass *v11;
  s64 v12;
  s64 v14;
  u64 i;
  System_String_o *v19;
  dds3Basic_t_o *result;

  ControlScene = dds3GetControlScene();
  v7 = 0;
  while (v7 < g_nHitData)
  {
    v9 = &g_pHitData->obj.klass + v7;
    v11 = v9[4];
    v10 = (v9 + 4);
    v12 = *&v11->_1.this_arg.bits;
    if (v12)
    {
      v14 = *(v12 + 24);
      for (i = 0; i < *(*(*v10 + 56LL) + 16LL); ++i)
      {
        if (!Compare(*matterName, *(*(v14 + 32 + 8 * i) + 24LL), 0))
        {
          v19 = *(*v10 + 24LL);
          result = dds3SceneBasicSearchNameAndType(ControlScene, 0xBu, v19);
          if (result)
            return result;
        }
      }
    }
    ++v7;
  }
  return 0;
}

// 0x127a110
void fldHojiDebugView(void) {
    fldDbgPrintStr2DC(0, 0, 0, 0, 0);
    fldGbChkGimic(0, 0, 0);
    fldGbChkHit(0, 0, 0);
}

// 0x127a5c0
void fldHojiDebugView2(void) {
    fldDbgPrintStr2DC(0, 0, 0, 0, 0);
    fldGbChkView(0, 0, 0);
    fldGbChkAnime(0, 0, 0);
}

// 0x1276e10
void *fldLoadFile(char *pFileName, char *akey) {
    dds3GetControlScene();
    dds3GetMapNo(0);
    GetFieldAssetName(0, 0);
    GetData(0);
    LoadEventVoice(0, 0, 0);
    fldAutoMapSetField(0, 0, 0);
    fldPlayerALoad();
    fldDrwZAlloc();
    nbFldCache_ToField_F(0);
    nbFldCache_ToField(0);
    GetData(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    GetEvtInstCash(0);
    SetFiledName(0, 0);
    evtUpdateEx_FieldLoadAfter(0, 0, 0);
    fldAutoMapDelete();
    GetChildList(0, 0, 0);
    SetLayerAll(0, 0);
    LoadFile(0, 0, 0, 0, 0);
    ChangeMaterial(0, 0, 0, 0, 0);
    fldClrCollision();
    fldEveHit_Init();
    fldSe_Init();
    fldNpcClear(0);
    fldTakaraWorkClear();
    fldNpcLoad();
    fldAutoMapModelLoad();
    fldSkyFieldLoad(0);
    fldNpcLightLoad(0);
    fldDoorLoad(0);
    fldInfLoad(0);
    sdfDevLoadTexList(0);
    IsLoad(0, 0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    fldAddressResolverFL2(0);
    fldFileResolverFL2(0, 0);
    billClrTexture(0);
    fldAddressResolverFL1(0);
    fldFileResolverFL1(0, 0, 0);
    fldMakeObjectBasic2();
    fldMakeObjectBasic3();
    dds3SceneBasicLoadScriptFile_FromMem(0, 0);
    fldMakeFilePath(0, 0, 0);
    dds3SceneBasicLoadScriptFile(0, 0, 0);
    fldDoor_AllSet();
    fldSetupButtonGuide();
    return 0;
}

// 0x12799a0
void *fldLoadFile_FromMemory(s32 field, s32 area, void *pF1, void *pF2, void *pTB, void *pBF) {
  return gFldFileF1;
}

// 0x1275cf0
s32 fldLoadNextFile(s32 field, s32 area) {
  struct fldGlobalWork_t_o *fldGb;
  s32 v7;

  if (field >= 10)
  {
    if (fldGb->fieldID == field)
    {
      if (fldGb->CashStat != 1)
      {
        if (fldGb->CashFieldID != field)
        if (fldGb->CashAreaID == area)
        {
          v7 = 2;
        }
        else
        {
          pFldNextFileDataBF = 0;
          pFldNextFileDataF1 = 0;
          pFldNextFileDataF2 = 0;
          pFldNextFileDataTB = 0;
          fldGb->CashFieldID = field;
          fldGb->CashAreaID = area;
          v7 = 1;
        }
        fldGb->CashStat = v7;
      }
    }
  }
  return 1;
}

// 0x1276230
void *fldLoadNextFileBF(void *pData, s32 field, s32 area) {
  return pFldNextFileDataBF;
}

// 0x1275c40
void fldLoadNextFileCallback1(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
  ;
}

// 0x1275c50
void fldLoadNextFileCallback2(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
  ;
}

// 0x1275c20
void fldLoadNextFileCallbackBF(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
  ;
}

// 0x1275c30
void fldLoadNextFileCallbackTB(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
  ;
}

// 0x12762b0
void *fldLoadNextFileF1(void *pData, s32 field, s32 area) {
  return pFldNextFileDataF1;
}

// 0x1276320
void *fldLoadNextFileF2(u8 **pData, s32 field, s32 area) {
  return pFldNextFileDataF2;
}

// 0x12762a0
void *fldLoadNextFileTB(void *pData, s32 field, s32 area) {
  return 0;
}

// 0x1275ce0
s32 fldLoadNextFile_BtlRet(void) {
  return 0;
}

// 0x1275c60
void fldLoadNextFile_SetId_BtlRet(s32 field, s32 area) {
  gFldBtlRet_Field = field;
  gFldBtlRet_Area = area;
}

// 0x1276070
s32 fldLoadNextGetStatus(void) {
  return fldGb->CashStat;
}

// 0x12760e0
s32 fldLoadNextGetStatus2(void) {
  struct fldFileResolver_StaticFields *static_fields;

  else
  {
    static_fields = fldFileResolver->static_fields;
    if (static_fields->pFldNextFileDataBF)
      return 1;
  }
  if (static_fields->pFldNextFileDataTB)
    return 1;
  if (static_fields->pFldNextFileDataF1)
    return 1;
  if (static_fields->pFldNextFileDataF2)
    return 1;
  return fldGb->CashStat != 0;
}

// 0x1276220
s32 fldLoadNextGetStatus3(s32 field, s32 area) {
  return 0;
}

// 0x1275f80
s32 fldLoadNextTask(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 CashStat;
  fldGlobal_c *v6;
  struct fldGlobal_StaticFields *static_fields;

  CashStat = fldGb->CashStat;
  if (CashStat)
  {
    if (CashStat != 1)
    {
      static_fields = fldGlobal->static_fields;
      fldGb = static_fields->fldGb;
      fldGb->CashStat = 0;
      return 0;
    }
    if (IsFldDataLoaded())
    {
      static_fields = v6->static_fields;
    }
  }
  return 0;
}

// 0x126f320
void fldMakeBlockBasicFL2(fldConstruntAreaFL2_t **pBlockTable, u32 nBlock) {
  u64 v5;
  s64 v6;
  dds3Basic_t_o *v8;
  struct dds3Basic_t_o *v10;

  else
  {
    dds3GetControlScene();
    if (!nBlock)
      return;
  }
  v5 = 0;
  v6 = nBlock;
  do
  {
    while (1)
    {
      v8 = dds3AddAreaBasic(pBlockTable->m_Items[v5]->areaID, pBlockTable->m_Items[v5]->areaName);
      if (!v5)
        break;
      if (v6 == ++v5)
        return;
    }
    v10 = v8;
    fldGb->fastArea = v10;
    v5 = 1;
  }
  while (v6 != 1);
}

// 0x1260780
dds3Basic_t *fldMakeDmyMatter(void) {
    dds3SerializeID();
    dds3AddMatterObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    return 0;
}

// 0x1262f90
void fldMakeFilePath(char **pathstr, s32 field, s32 area) {
    IsDLCField(0);
}

// 0x126f440
void fldMakeObjectBasic2(void) {
    dds3GetControlScene();
    SetfldResModel(0, 0);
    SetsdfModelDef(0, 0, 0);
    SetsdfMotionPlayBook(0, 0);
    dds3AddModelBasic2(0, 0, 0, 0, 0);
    dds3AddMatterObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    dds3MatterObjectBasicSetOt(0, 0);
    fldCommand_GetHojiID(0);
    dds3MatterObjectBasicSetHojiID(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    dds3ObjectBaseSetControlBasic(0, 0);
    dds3ObjectBaseMakeMatter(0);
    fldHitLinkMatter(0, 0);
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    dds3ObjectBaseRegistArea(0);
    FindHojiObj();
}

// 0x12704a0
void fldMakeObjectBasic3(void) {
    dds3GetControlScene();
    fldGbChkGimic(0, 0, 0);
    fldCommand_SEARCH_ID(0);
    dds3SearchSceneBasic(0, 0, 0);
    fldGetMatter_From_ModelRangeID(0);
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    dds3MatterObjectBasicGetControlWorkData(0);
    dds3ObjectBaseCreateMover(0);
    dds3MoverBasicSetPath(0, 0);
    dds3MoverBasicMakePath(0);
    dds3MoverBasicGetPathControl(0);
    dds3PathBasicControlAlterMode(0, 0);
    evtPathRate(0, 0);
    dds3MoverBasicUpdate(0);
    SDF_ABORT4(0, 0);
    fldGbChkView(0, 0, 0);
    dds3MatterObjectBasicSetAlpMode(0, 0);
}

// 0x12610f0
void fldMakeResouceBasicFL1(fldResourceTypeTable_t **pTypeTable, u32 nTypeTable, u8 **pHead) {
    SetfldResCollision(0, 0);
    SetfldResCollisionPoly(0, 0);
    fldCommand_GetHojiID(0);
    fldAddCollisionPoly(0, (sdfVector4_t){0}, 0, 0, 0);
    dds3AddModelRangeBasicNew(0, 0, (sdfVector4_t){0}, 0);
    dds3ModelRangeBasicSetBlockID(0, 0);
    SetfldResourcePathTableInfo(0, 0);
    dds3AddPathBasic(0, 0, 0);
    SetfldResourceEffect(0, 0);
    dds3AddTMXEffectObjectBasic3(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    fldMakeFilePath(0, 0, 0);
    dds3AddTMXEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0}, 0);
    dds3EffectObjectBasicStatOn(0, 0);
    dds3EffectObjectBasicSetFldEx(0, 0);
    dds3AddP2AEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0}, 0);
    dds3AddP2AEffectObjectBasic3(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    tpAlfRaitoSet(0);
    dds3AddD3PEffectObjectBasic2(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3AddESPEffectObjectBasic(0, (sdfVector4_t){0}, (sdfVector4_t){0}, 0);
    dds3EffectObjectBasicStatOff(0, 0);
    SetfldResourceLight(0, 0);
    fldLoad_BasicLightLoadAfter(0, 0, 0, 0, 0);
    dds3AddLightObjectBasic(0);
    dds3SetBasicName(0, 0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3SetRadiusPoseSet(0, 0);
    dds3SetLightObjectResoruce(0, 0);
}

// 0x126d340
void fldMakeResouceBasicFL2(fldResourceTypeTable_t **pTypeTable, u32 nTypeTable, u8 **pHead) {
    SetfldResCollision(0, 0);
    fldCommand_GetHojiID(0);
    SetfldResCollisionPoly(0, 0);
    fldAddCollisionPoly(0, (sdfVector4_t){0}, 0, 0, 0);
    dds3AddModelRangeBasicNew(0, 0, (sdfVector4_t){0}, 0);
    dds3ModelRangeBasicSetBlockID(0, 0);
    dds3AddCameraObjectBasicTypeFree(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3SetBasicName(0, 0);
    SetfldResourcePathTableInfo(0, 0);
    dds3AddPathBasic(0, 0, 0);
    SetfldResPut(0, 0, 0);
    dds3AddPointBasic(0, 0, 0);
    fldEveHit_AddEveHit(0, 0);
    fldNpcAdd(0, 0, 0, 0, (sdfVector4_t){0}, 0, 0, 0);
    fldItemBoxAdd(0, 0, 0, 0, (sdfVector4_t){0});
    SetfldResPutSE(0, 0);
    fldSe_Add(0, 0, 0, 0, 0);
    SetfldResEvent(0, 0);
    dds3AddEventBasic(0, 0, 0);
    fldEveHit_AddEveData(0, 0);
}

// 0x12796a0
void fldSetupButtonGuide(void) {
  s16 v3;
  s32 v4;
  s32 fieldID;
  s64 *v6;
  s32 v9;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  fieldID = fldGb->fieldID;
  if (fieldID <= 9)
  {
    if (fieldID == 1)
    {
      v6 = &StringLiteral_16657;
    }
    else
    {
      v6 = &StringLiteral_16658;
    }
    ButtonGuideDispSet(*v6, 1, 1, 90);
    else
    {
      ButtonGuideDispOff();
    }
    return;
  }
  else  if (fieldID == 14)
  if (!CheckTypeClose())
  {
    v9 = fldGb->fieldID;
    if (v9 >= 15)
    {
      if (v9 <= 99)
      {
        ButtonGuideDispSet(StringLiteral_16660, 1, 1, 90);
      }
    }
    SetTypeClose(0);
  }
  ButtonGuideDispSet(StringLiteral_16658, 1, 1, 150);
}

// 0x1271ea0
void sdfAddressResolverReset(void *aDataBody, u32 aOffset, u8 aAddrInfoPtr, s32 aAddrInfoLeng) {
  ;
}
