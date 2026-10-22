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
static fldResHead_t *g_pModelData;
static u32 g_nModelData;
static fldResHead_t *g_pHitData;
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
static void *hFldF1EffTex;
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
  UnityEngine_GameObject_array_array *v9;
  u64 v10;
  u64 v12;
  u64 v14;
  UnityEngine_GameObject_o *v17;
  UnityEngine_GameObject_array *Children;
  il2cpp_array_size_t max_length;
  UnityEngine_Material_o **m_Items;
  UnityEngine_GameObject_array_array *v44;
  u64 v45;
  s64 v46;
  u64 v47;

  v9 = List2;
  if (SLODWORD(List1->max_length) >= 1)
  {
    v10 = 0;
    v44 = v9;
    while (1)
    {
      v46 = &v9->m_Items[v10];
      if (*v46)
        break;
LABEL_63:
      if (++v10 >= SLODWORD(List1->max_length))
        return;
    }
    v12 = 0;
    v45 = v10;
    if (v10 >= LODWORD(v9->max_length))
    {
LABEL_11:
    }
    while (1)
    {
      v14 = *(*v46 + 24LL);
      if (v12 >= v14)
        goto LABEL_63;
      v47 = v12;
      v17 = *(*v46 + 8 * v12 + 32);
      else
      {
        Children = GetChildren(v17, List2);
        if (Children)
          goto LABEL_20;
      }
      v9 = v44;
      v10 = v45;
      v12 = v47 + 1;
      if (v45 >= LODWORD(v44->max_length))
        goto LABEL_11;
    }
  }
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
          if (v10 >= LODWORD((*List2)->max_length))
          {
LABEL_18:
          }
          while (v12 < SLODWORD(v13->m_Items[v10]->max_length))
          {
            v17 = (*List2)->m_Items[v10];
            v14 = &v17->obj.klass + v12++;
            v14[4] = 0;
            v13 = *List2;
            if (v10 >= LODWORD((*List2)->max_length))
              goto LABEL_18;
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
    if (!LODWORD(v10->max_length))
    {
LABEL_10:
    }
    while (1)
    {
      v14 = v10->m_Items[v12];
      else
      {
        v15 = GetChildren(v14);
        if (!v15)
          goto LABEL_17;
      }
LABEL_17:
      *&v11[2 * v12 + 8] = v15;
      if ((*List2)->m_Items[v12])
      {
        v20 = 0;
        v21 = *List2;
        if (v12 >= LODWORD((*List2)->max_length))
        {
LABEL_25:
        }
        while (v20 < SLODWORD(v21->m_Items[v12]->max_length))
        {
          v24 = (*List2)->m_Items[v12];
          v26 = v24->m_Items[v20];
          cmpSetupObject(v26, 0);
          ++v20;
          v21 = *List2;
          if (v12 >= LODWORD((*List2)->max_length))
            goto LABEL_25;
        }
      }
      v10 = *List1;
      if (++v12 >= SLODWORD((*List1)->max_length))
        return;
      v11 = *List2;
      if (v12 >= LODWORD(v10->max_length))
        goto LABEL_10;
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
  if (addr >= LODWORD(pData->max_length))
  {
LABEL_7:
  }
  while (v5[v6 + 32])
  {
    if ((addr + ++v6) >= LODWORD(pData->max_length))
      goto LABEL_7;
  }
  v8 = NewSpecific(byte, v6);
  v9 = v8;
  v10 = 0;
  v11 = v5 + 32;
  v12 = addr;
  if (addr >= LODWORD(pData->max_length))
  {
LABEL_12:
  }
  while (v11[v10])
  {
    *(v8 + v10 + 32) = v11[v10];
    v12 = addr + ++v10;
    if ((addr + v10) >= LODWORD(pData->max_length))
      goto LABEL_12;
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
      goto LABEL_14;
  }
  else
  {
    v12 = addr + 8;
      goto LABEL_14;
  }
LABEL_14:
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
      if (v8 >= v7[6])
      {
LABEL_38:
      }
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
          goto LABEL_38;
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
  s64 v7;
  UnityEngine_Vector4_array *v8;
  UnityEngine_Vector4_array *v10;
  u64 v11;
  s64 m_Items;
  s32 v14;
  s32 v16;
  s32 v18;

  v7 = size;
  v8 = NewSpecific(UnityEngine_Vector4, size);
  v10 = v8;
  if (size >= 1)
  {
    v11 = 0;
    m_Items = v8->m_Items;
    do
    {
      ToSingle(pData, addr, 0);
      sub_854930(m_Items, 0);
      v14 = addr + 4;
      ToSingle(pData, v14, 0);
      sub_854930(m_Items, 1u);
      v16 = v14 + 4;
      ToSingle(pData, v16, 0);
      sub_854930(m_Items, 2u);
      v18 = v16 + 4;
      ToSingle(pData, v18, 0);
      sub_854930(m_Items, 3u);
      ++v11;
      m_Items += 16;
      addr = v18 + 4;
    }
    while (v7 != v11);
  }
  return v10;
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
  u64 *v5;

  if (!addr)
    return 0;
  v5 = Allocate(fldResHeadPos_t);
  fldResHeadPos_t___ctor(v5);
  ToSingle(pData, addr, 0);
  sub_854930((v5 + 2), 0);
  ToSingle(pData, addr + 4, 0);
  sub_854930((v5 + 2), 1u);
  ToSingle(pData, addr + 8, 0);
  sub_854930((v5 + 2), 2u);
  ToSingle(pData, addr + 12, 0);
  sub_854930((v5 + 2), 3u);
  ToSingle(pData, addr + 16, 0);
  sub_854930((v5 + 4), 0);
  ToSingle(pData, addr + 20, 0);
  sub_854930((v5 + 4), 1u);
  ToSingle(pData, addr + 24, 0);
  sub_854930((v5 + 4), 2u);
  ToSingle(pData, addr + 28, 0);
  sub_854930((v5 + 4), 3u);
  ToSingle(pData, addr + 32, 0);
  sub_854930((v5 + 6), 0);
  ToSingle(pData, addr + 36, 0);
  sub_854930((v5 + 6), 1u);
  ToSingle(pData, addr + 40, 0);
  sub_854930((v5 + 6), 2u);
  ToSingle(pData, addr + 44, 0);
  sub_854930((v5 + 6), 3u);
  return v5;
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
          goto LABEL_52;
        case 2:
          v28 = ToInt32(pData, v17, 0);
          v24 = SetfldResourcePathData_Vector4(pData, v28);
          goto LABEL_52;
        case 4:
          v32 = ToInt32(pData, v17, 0);
          v24 = SetfldResourcePathData_Float(pData, v32);
          goto LABEL_52;
        case 5:
          v36 = ToInt32(pData, v17, 0);
          v24 = SetfldResourcePathData_Light(pData, v36);
LABEL_52:
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
  s64 v7;
  u64 *v8;
  UnityEngine_Vector3_array *v10;
  u64 v11;
  u32 *v12;
  f32 v13;
  f32 v14;
  s32 v15;
  f32 v16;
  f32 v17;
  s32 v18;
  s32 v19;
  s64 v22;
  s32 v23;

  v7 = size;
  v8 = NewSpecific(UnityEngine_Vector3, size);
  v10 = v8;
  if (size >= 1)
  {
    v11 = 0;
    v12 = v8 + 5;
    do
    {
      v13 = ToSingle(pData, addr, 0);
      v14 = ToSingle(pData, addr + 4, 0);
      v15 = addr + 8;
      v16 = v14;
      v17 = ToSingle(pData, v15, 0);
      v23 = 0;
      v22 = 0;
      sub_8524C0(&v22, v13, v16, v17);
      v18 = HIDWORD(v22);
      v19 = v23;
      ++v11;
      *(v12 - 2) = v22;
      *(v12 - 1) = v18;
      addr = v15 + 4;
      *v12 = v19;
      v12 += 3;
    }
    while (v7 != v11);
  }
  return v10;
}

// 0x1274d50
sdfVector4_t **SetfldResourcePathVector4(u8 **pData, s32 size, s32 addr) {
  s64 v7;
  u64 *v8;
  UnityEngine_Vector4_array *v10;
  u64 v11;
  u32 *v12;
  f32 v13;
  f32 v14;
  f32 v15;
  s32 v16;
  f32 v17;
  f32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s64 v24;
  s64 v25;

  v7 = size;
  v8 = NewSpecific(UnityEngine_Vector4, size);
  v10 = v8;
  if (size >= 1)
  {
    v11 = 0;
    v12 = v8 + 11;
    do
    {
      v13 = ToSingle(pData, addr, 0);
      v14 = ToSingle(pData, addr + 4, 0);
      v15 = ToSingle(pData, addr + 8, 0);
      v16 = addr + 12;
      v17 = v15;
      v18 = ToSingle(pData, v16, 0);
      v24 = 0;
      v25 = 0;
      sub_854690(&v24, v13, v14, v17, v18);
      v19 = HIDWORD(v24);
      v21 = v25;
      v20 = HIDWORD(v25);
      ++v11;
      *(v12 - 3) = v24;
      *(v12 - 2) = v19;
      *(v12 - 1) = v21;
      *v12 = v20;
      v12 += 4;
      addr = v16 + 4;
    }
    while (v7 != v11);
  }
  return v10;
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
  sdfModelDef_t_o *v7;
  s32 v9;
  s32 v11;
  s32 v13;
  s32 v16;
  struct sdfModelNodeDef_t_array *v17;
  s32 modelDef;
  u32 *nodeDef;
  u64 v21;
  s64 *v23;
  s64 *v24;
  u32 *v26;
  u32 v29;
  u32 v30;
  s32 addra;

  addra = 0;
  v7 = Allocate(sdfModelDef_t);
  sdfModelDef_t___ctor(v7);
  addra = ToUInt32(pData, addr, 0) + 16;
  v9 = ToInt32(pData, addr, 0);
  v7->modelDef = ToInt32(pData, v9, 0);
  v11 = addr + 4;
  if (set)
  {
    v30 = ToUInt32(pData, v11, 0);
    v7->matDef_Old = sub_8D3950(uint, &v30);
  }
  else
  {
    v13 = ToInt32(pData, v11, 0);
    v7->count = ToInt32(pData, v13, 0);
    v16 = v13 + 16;
    v7->matDef_New = SetsdfMatDef(pData, v16);
    v17 = NewSpecific(sdfModelNodeDef_t, v7->modelDef);
    modelDef = v7->modelDef;
    v7->nodeDef = v17;
    if (modelDef >= 1)
    {
      nodeDef = v17;
      v21 = 0;
        goto LABEL_23;
LABEL_21:
      while (1)
      {
LABEL_23:
        v23 = SetsdfModelNodeDef(pData, &addra);
        v24 = v23;
        v26 = &nodeDef[2 * v21++];
        *(v26 + 4) = v24;
        if (v21 >= v7->modelDef)
          break;
        nodeDef = v7->nodeDef;
          goto LABEL_21;
      }
    }
  }
  v7->morphCount = ToUInt32(pData, addr + 8, 0);
  v29 = ToUInt32(pData, addr + 12, 0);
  v7->extraData = sub_8D3950(uint, &v29);
  return v7;
}

// 0x1274fa0
sdfModelNodeDef_t *SetsdfModelNodeDef(u8 **pData, s32 *addr) {
  u64 *v5;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  f32 v13;
  s32 v14;
  f32 v15;
  f32 v16;
  s32 v17;
  f32 v18;
  f32 v19;
  s32 v20;
  f32 v21;
  f32 v22;
  s32 v23;
  s32 v24;
  f32 v25;
  s32 v26;
  f32 v27;
  f32 v28;
  s32 v29;
  f32 v30;
  f32 v31;
  s32 v32;
  f32 v33;
  f32 v34;
  s32 v35;
  s32 v36;
  f32 v37;
  s32 v38;
  f32 v39;
  f32 v40;
  s32 v41;
  f32 v42;
  f32 v43;
  s32 v44;
  f32 v45;
  f32 v46;
  s32 v47;
  s32 v48;
  s32 v50;
  s32 *v51;
  u32 *v52;
  u64 v53;
  s64 *v55;
  s64 *v56;
  s32 *v58;
  u64 v60;
  s64 v61;
  u64 v62;
  s64 v63;
  u64 v64;
  s64 v65;

  v5 = Allocate(sdfModelNodeDef_t);
  sdfModelNodeDef_t___ctor(v5);
  v7 = *addr;
  *(v5 + 8) = ToUInt16(pData, v7);
  v8 = *addr + 2;
  *addr = v8;
  *(v5 + 9) = ToUInt16(pData, v8);
  v9 = *addr + 2;
  *addr = v9;
  *(v5 + 5) = ToUInt32(pData, v9, 0);
  v10 = *addr + 4;
  *addr = v10;
  *(v5 + 6) = ToUInt32(pData, v10, 0);
  v11 = *addr + 4;
  *addr = v11;
  *(v5 + 7) = ToInt32(pData, v11, 0);
  v12 = *addr + 4;
  *addr = v12;
  v13 = ToSingle(pData, v12, 0);
  v14 = *addr + 4;
  v15 = v13;
  *addr = v14;
  v16 = ToSingle(pData, v14, 0);
  v17 = *addr + 4;
  v18 = v16;
  *addr = v17;
  v19 = ToSingle(pData, v17, 0);
  v20 = *addr + 4;
  v21 = v19;
  *addr = v20;
  v22 = ToSingle(pData, v20, 0);
  *addr += 4;
  v64 = 0;
  v65 = 0;
  sub_854690(&v64, v15, v18, v21, v22);
  v24 = v65;
  v23 = HIDWORD(v65);
  v5[4] = v64;
  *(v5 + 10) = v24;
  *(v5 + 11) = v23;
  v25 = ToSingle(pData, *addr, 0);
  v26 = *addr + 4;
  v27 = v25;
  *addr = v26;
  v28 = ToSingle(pData, v26, 0);
  v29 = *addr + 4;
  v30 = v28;
  *addr = v29;
  v31 = ToSingle(pData, v29, 0);
  v32 = *addr + 4;
  v33 = v31;
  *addr = v32;
  v34 = ToSingle(pData, v32, 0);
  *addr += 4;
  v62 = 0;
  v63 = 0;
  sub_854690(&v62, v27, v30, v33, v34);
  v36 = v63;
  v35 = HIDWORD(v63);
  v5[6] = v62;
  *(v5 + 14) = v36;
  *(v5 + 15) = v35;
  v37 = ToSingle(pData, *addr, 0);
  v38 = *addr + 4;
  v39 = v37;
  *addr = v38;
  v40 = ToSingle(pData, v38, 0);
  v41 = *addr + 4;
  v42 = v40;
  *addr = v41;
  v43 = ToSingle(pData, v41, 0);
  v44 = *addr + 4;
  v45 = v43;
  *addr = v44;
  v46 = ToSingle(pData, v44, 0);
  *addr += 4;
  v60 = 0;
  v61 = 0;
  sub_854690(&v60, v39, v42, v45, v46);
  v48 = v61;
  v47 = HIDWORD(v61);
  v5[8] = v60;
  *(v5 + 18) = v48;
  *(v5 + 19) = v47;
  *(v5 + 20) = ToSingle(pData, *addr, 0);
  v50 = *addr + 4;
  *addr = v50;
  v51 = v5[11];
  v52 = (v51 + 6);
  if (v51[6] >= 1)
  {
    v53 = 0;
    do
    {
      LODWORD(v64) = ToUInt32(pData, v50, 0);
      v55 = sub_8D3950(uint, &v64);
      v56 = v55;
      v58 = &v51[2 * v53++];
      *(v58 + 4) = v56;
      v50 = *addr + 4;
      *addr = v50;
      v51 = v5[11];
      v52 = (v51 + 6);
    }
    while (v53 < v51[6]);
  }
  return v5;
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
  autoMapPrefab = "";
  DelAutoMapObj(&AutoMapObjArea, &mapNodeList1Area, &mapNodeList2Area);
  DelAutoMapObj(&AutoMapObjHalf, &mapNodeList1Half, &mapNodeList2Half);
}

// 0x127aae0
bool fldCheckNextFile(s32 field) {
  System_Object_array *v3;
  s64 *v5;
  s64 *v7;
  s64 *v11;
  s64 *v12;
  s64 *v15;
  s64 *v16;
  Il2CppObject *v19;
  s32 v22;
  s32 v29;
  bool IsDLCField;
  s64 *v33;
  System_String_o *v34;
  System_String_o *FieldAssetName;
  u32 v38;
  Il2CppObject *v40;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *v46;
  AssetBundleCtrl_o *v48;
  System_String_o *v50;
  AssetBundleCtrl_o *v51;
  Il2CppObject *v54;
  AssetBundleCtrl_o *v56;
  s32 CashStat;
  s32 fieldID;
  s32 v60;

  v3 = NewSpecific(object, 6u);
  v3->m_Items[0] = "fldCheckNextFile : ";
  v60 = field;
  v5 = sub_8D3950(s32, &v60);
  v7 = v5;
  v3->m_Items[1] = v7;
  v3->m_Items[2] = ",";
  fieldID = fldGb->fieldID;
  v11 = sub_8D3950(s32, &fieldID);
  v12 = v11;
  v3->m_Items[3] = v12;
  v3->m_Items[4] = ",";
  CashStat = fldGb->CashStat;
  v15 = sub_8D3950(s32, &CashStat);
  v16 = v15;
  v3->m_Items[5] = v16;
  v19 = Concat_5270224(v3);
  Log(v19, 0);
  v22 = fldGb->fieldID;
  if (v22 == field)
    return 1;
  else if (v22 < 201)
  {
    goto LABEL_50;
  }
  else if (v22 < 500)
  {
    return 1;
  }
LABEL_50:
  v29 = fldGb->fieldID;
  if (v29 == 809)
    return 1;
  IsDLCField = IsDLCField(field);
  v33 = &"m";
  if (!IsDLCField)
    v33 = &"";
  v34 = *v33;
  FieldAssetName = GetFieldAssetName("f{0:D3}", field);
  v38 = fldGb->CashStat;
  if (v38 != 2)
  {
    if (v38 <= 1)
    {
      v40 = Concat_5224608("Loading : ", FieldAssetName);
      Log(v40, 0);
      asset_bc = get_asset_bc();
      if (!IsLoad(asset_bc, FieldAssetName))
      {
        LoadAssetExt(FieldAssetName, FieldAssetName, v34);
      }
      fldGb->CashStat = 2;
      return 0;
    }
    return 1;
  }
  v46 = Concat_5224608("Loading : ", FieldAssetName);
  Log(v46, 0);
  v48 = get_asset_bc();
  if (IsLoad(v48, FieldAssetName))
  {
    v50 = GetFieldAssetName("f{0:D3}", v29);
    v51 = get_asset_bc();
    if (IsLoad(v51, v50))
    {
      v54 = Concat_5221536("!!!!! Unload ", v50, " !!!!!");
      Log(v54, 0);
      v56 = get_asset_bc();
      IsLoad(v56, v50);
    }
    fldGb->CashStat = 0;
    return 1;
  }
  return 0;
}

// 0x127aa70
void fldFileAddrResetMode(s32 mode) {
  gFldFileResetMode = mode;
}

// 0x12712e0
void fldFileResolverFL1(fldFileInfoHeaderFL1_t *pInfoHeaderFL1, u8 **pHead, char *akey) {
  System_Char_array *v6;
  System_Char_array *v7;
  System_Char_array *v8;
  s32 SkyTblIdx;
  struct System_String_array *pEffFileName;
  s64 *filename0;
  struct System_String_array *v17;
  s64 *filename1;
  struct System_String_array *v20;
  s64 *filename2;
  struct System_String_array *v23;
  s64 *filename3;
  u64 i;
  System_String_o *v29;
  struct System_String_array *v30;
  Il2CppClass **v32;
  System_String_o *v33;
  s32 v34;
  s32 v35;
  u16 Chars;
  u32 *v37;
  struct sdfMemHandle_t_array *hFldF1Eff;
  struct System_Byte_array_array *pFldF1Eff;
  struct sdfMemHandle_t_array *v45;
  struct System_Byte_array_array *v47;
  struct sdfMemHandle_t_array *v49;
  struct System_Byte_array_array *v51;
  struct sdfMemHandle_t_array *v53;
  struct System_Byte_array_array *v55;
  EventPack_c *v58;
  u64 *v63;
  evtTexManager_o *currTexMngr;
  s32 fieldID;
  fldResourceTypeTable_t_array *pResourceTypeTable;
  u32 nResourceTypeTable;
  fldFileInfoHeaderFL1_t_o *v99;
  System_Byte_array *pHeada;
  System_String_o *pathstr;

  v6 = NewSpecific(char, 0x18u);
  pathstr = CreateString_5280336(0, v6);
  v7 = NewSpecific(char, 0x40u);
  CreateString_5280336(0, v7);
  v8 = NewSpecific(char, 0x18u);
  CreateString_5280336(0, v8);
  SkyTblIdx = pInfoHeaderFL1->pAreaData->SkyTblIdx;
  fldSkySetTblIdxInit(SkyTblIdx);
  filename0 = pInfoHeaderFL1->pAreaData->filename0;
  pEffFileName->m_Items[0] = filename0;
  v17 = pEffFileName;
  filename1 = pInfoHeaderFL1->pAreaData->filename1;
  v17->m_Items[1] = filename1;
  v20 = pEffFileName;
  filename2 = pInfoHeaderFL1->pAreaData->filename2;
  v20->m_Items[2] = filename2;
  v23 = pEffFileName;
  filename3 = pInfoHeaderFL1->pAreaData->filename3;
  v23->m_Items[3] = filename3;
  v99 = pInfoHeaderFL1;
  pHeada = pHead;
  if (fldGb->fieldID == 24 && evtBitCheck(79))
  {
    for (i = 0; i != 4; ++i)
    {
      v29 = "";
      v30 = pEffFileName;
      v32 = &v30->obj.klass + i;
      v33 = v32[4];
      if (!v33)
        continue;
      if (get_Length(v32[4]) >= 1)
      {
        v34 = 0;
        v35 = 0;
        do
        {
          if (get_Chars(v33, v34) == 46)
          {
            v29 = ChangeCharacter(v29, v35 + v34, 0x62u);
            v35 = 1;
          }
          Chars = get_Chars(v33, v34);
          v29 = ChangeCharacter(v29, v35 + v34++, Chars);
        }
        while (v34 < get_Length(v33));
      }
      else
      {
        v37 = pEffFileName;
        if (v29)
          goto LABEL_45;
      }
      *&v37[2 * i + 8] = v29;
    }
  }
  else
  {
    if (!LODWORD(hFldF1Eff->max_length))
      goto LABEL_55;
  }
  hFldF1Eff->m_Items[0] = 0;
  pFldF1Eff->m_Items[0] = 0;
  v45 = hFldF1Eff;
  v45->m_Items[1] = 0;
  v47 = pFldF1Eff;
  v47->m_Items[1] = 0;
  v49 = hFldF1Eff;
  v49->m_Items[2] = 0;
  v51 = pFldF1Eff;
  v51->m_Items[2] = 0;
  v53 = hFldF1Eff;
  v53->m_Items[3] = 0;
  v55 = pFldF1Eff;
  v55->m_Items[3] = 0;
  if (fldGb->fieldID <= 499)
  {
    else if (currTexMngr)
    {
      goto LABEL_86;
    }
    v63 = Allocate(evtTexManager);
    _ctor(v63, 0);
    currTexMngr = v63;
    if ((v58->_2.bitflags2 & 2) == 0)
      goto LABEL_100;
    goto LABEL_87;
  }
LABEL_142:
  pResourceTypeTable = v99->pResourceTypeTable;
  nResourceTypeTable = v99->nResourceTypeTable;
  fldMakeResouceBasicFL1(pResourceTypeTable, nResourceTypeTable, pHeada);
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
  else if (fldTitleChk() != 1)
  {
    goto LABEL_13;
  }
  dds3KillProcessName("fldTitle", 1);
LABEL_13:
  else if (fldTitleMiniChk() != 1)
  {
    goto LABEL_20;
  }
  dds3KillProcessName("fldTitleMini", 1);
LABEL_20:
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
  fldFileResolver_c *v5;
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
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_12:
    goto LABEL_14;
  }
  while (1)
  {
LABEL_14:
    if (v8 >= g_nHitData)
      return 0;
    v10 = &g_pHitData->obj.klass + v8;
    v13 = v10[4];
    v12 = (v10 + 4);
    v11 = v13;
    if (v6 == LODWORD(v13->_1.name))
      break;
LABEL_11:
    ++v8;
      goto LABEL_12;
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
    goto LABEL_11;
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
  fldFileResolver_c *v5;
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
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_12:
  }
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
      goto LABEL_12;
  }
  return 0;
}

// 0x127a110
void fldHojiDebugView(void) {
  System_String_o *v2;
  s32 v3;
  s32 v4;
  u64 *v5;
  System_String_o *v8;
  s32 i;
  s32 v11;
  u64 *v12;
  System_String_o *v13;
  System_String_o *v14;
  System_String_o *v17;
  s32 j;
  s32 v20;
  u64 *v21;
  System_String_o *v22;
  s32 v23;
  s32 v24;
  s32 v25;

  v2 = "GMC-HOJI                       HIT-HOJI";
  fldDbgPrintStr2DC(84, 0, -1, v2, 4);
  fldDbgPrintStr2DC(84, 12, -1, "0123456789ABCDEF   0123456789ABCDEF", 4);
  v3 = 0;
  do
  {
    v4 = v3++;
    v25 = v3;
    v5 = sub_8D3950(s32, &v25);
    v8 = Format("{0:D2} ", v5, 0);
    for (i = 0; i != 16; ++i)
    {
      v11 = fldGbChkGimic(fldGb->fieldID, v3, i);
      if (v11)
      {
        v24 = v11;
        v12 = sub_8D3950(s32, &v24);
        v13 = Format("{0:D}", v12, 0);
      }
      else
      {
        v13 = ".";
      }
      v14 = Concat_5224608(v8, v13);
      v8 = v14;
    }
    v17 = Concat_5224608(v14, "   ");
    for (j = 0; j != 16; ++j)
    {
      v20 = fldGbChkHit(fldGb->fieldID, v3, j);
      if (v20)
      {
        v23 = v20;
        v21 = sub_8D3950(s32, &v23);
        v22 = Format("{0:D}", v21, 0);
      }
      else
      {
        v22 = ".";
      }
      v17 = Concat_5224608(v17, v22);
    }
    fldDbgPrintStr2DC(24, 12 * v4 + 24, -1, v17, 4);
  }
  while (v3 != 31);
}

// 0x127a5c0
void fldHojiDebugView2(void) {
  System_String_o *v2;
  s32 v3;
  s32 v4;
  u64 *v5;
  System_String_o *v8;
  s32 i;
  s32 v11;
  u64 *v12;
  System_String_o *v13;
  System_String_o *v14;
  System_String_o *v17;
  s32 j;
  s32 v20;
  u64 *v21;
  System_String_o *v22;
  s32 v23;
  s32 v24;
  s32 v25;

  v2 = "VIS-HOJI                       ANM-HOJI";
  fldDbgPrintStr2DC(84, 0, -1, v2, 4);
  fldDbgPrintStr2DC(84, 12, -1, "0123456789ABCDEF   0123456789ABCDEF", 4);
  v3 = 0;
  do
  {
    v4 = v3++;
    v25 = v3;
    v5 = sub_8D3950(s32, &v25);
    v8 = Format("{0:D2} ", v5, 0);
    for (i = 0; i != 16; ++i)
    {
      v11 = fldGbChkView(fldGb->fieldID, v3, i);
      if (v11)
      {
        v24 = v11;
        v12 = sub_8D3950(s32, &v24);
        v13 = Format("{0:D}", v12, 0);
      }
      else
      {
        v13 = ".";
      }
      v14 = Concat_5224608(v8, v13);
      v8 = v14;
    }
    v17 = Concat_5224608(v14, "   ");
    for (j = 0; j != 16; ++j)
    {
      v20 = fldGbChkAnime(fldGb->fieldID, v3, j);
      if (v20)
      {
        v23 = v20;
        v21 = sub_8D3950(s32, &v23);
        v22 = Format("{0:D}", v21, 0);
      }
      else
      {
        v22 = ".";
      }
      v17 = Concat_5224608(v17, v22);
    }
    fldDbgPrintStr2DC(24, 12 * v4 + 24, -1, v17, 4);
  }
  while (v3 != 31);
}

// 0x1276e10
void *fldLoadFile(char *pFileName, char *akey) {
  u32 MapNo;
  s32 v8;
  System_Object_array *v9;
  s64 *v11;
  s64 *v12;
  s64 *v15;
  s64 *v16;
  Il2CppObject *v19;
  System_String_o *FieldAssetName;
  EventEMsgData_o *Data;
  s32 fieldID;
  u64 *v29;
  System_String_array *v31;
  u32 max_length;
  System_String_array *v33;
  System_String_o *v37;
  s32 v39;
  System_String_o *v42;
  UnityEngine_GameObject_o *v43;
  System_String_o *v47;
  UnityEngine_Object_o *Prefab_16624656;
  bool v49;
  System_String_o *v56;
  Il2CppObject *v57;
  char *v58;
  s64 *v59;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *EvtInstCash;
  UnityEngine_Transform_o *transform;
  f32 v68;
  f32 v69;
  f32 v70;
  f32 v71;
  f32 v72;
  f32 v73;
  UnityEngine_Transform_o *v75;
  UnityEngine_GameObject_o *v79;
  UnityEngine_Transform_o *v81;
  Il2CppObject *v83;
  UnityEngine_Transform_o *v85;
  f32 v86;
  f32 v87;
  f32 v88;
  f32 v89;
  f32 v90;
  f32 v91;
  UnityEngine_Transform_o *v93;
  System_String_o *v96;
  AssetBundleCtrl_o *v97;
  Il2CppObject *v98;
  UnityEngine_GameObject_o *v99;
  UnityEngine_Transform_o *v101;
  Il2CppObject *v103;
  bool v107;
  System_String_o *v109;
  UnityEngine_GameObject_o *FildMapObj;
  Il2CppObject *v113;
  System_String_o *v114;
  System_String_o *v116;
  System_String_o *v118;
  u64 *v119;
  System_String_array *v121;
  System_String_array *v122;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v127;
  struct fldGlobalWork_t_o *v128;
  struct fldGlobalWork_t_o *v129;
  struct fldGlobalWork_t_o *v130;
  s64 *v132;
  UnityEngine_GameObject_o *v133;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v135;
  System_String_o *v136;
  UnityEngine_Component_o *v137;
  UnityEngine_GameObject_o *v139;
  Il2CppObject *Component_object;
  FieldBgHD_o *v143;
  System_String_o *v144;
  System_String_o *v146;
  struct System_String_o *v150;
  u32 v154;
  System_String_o *v158;
  AssetBundleCtrl_o *v159;
  Il2CppObject *v161;
  UnityEngine_GameObject_o *v162;
  UnityEngine_Transform_o *v164;
  Il2CppObject *v167;
  UnityEngine_GameObject_o *AutoMapObjArea;
  Il2CppObject *v171;
  UnityEngine_GameObject_o *v172;
  UnityEngine_Transform_o *v173;
  Il2CppObject *v174;
  UnityEngine_Transform_o *v177;
  UnityEngine_Transform_o *v178;
  System_String_o *v181;
  AssetBundleCtrl_o *v182;
  UnityEngine_Object_o *File;
  s64 typeHierarchyDepth;
  Il2CppObject *v185;
  Il2CppObject *v187;
  AssetBundleCtrl_o *v189;
  UnityEngine_Object_o *v190;
  s64 v192;
  Il2CppObject *v193;
  Il2CppObject *v196;
  AssetBundleCtrl_o *v198;
  UnityEngine_Object_o *v199;
  s64 v201;
  Il2CppObject *v202;
  Il2CppObject *v206;
  UnityEngine_GameObject_array *mapNodeList1Half;
  UnityEngine_GameObject_array_array *mapNodeList2Half;
  Il2CppObject *v213;
  struct fldGlobalWork_t_o *v220;
  s32 v221;
  System_String_o *v228;
  sdfModelTexList_t_o *TexList;
  System_String_o *v233;
  fldFileResolver_c *v234;
  s64 *gFldFileF2;
  AssetBundleCtrl_o *v236;
  Il2CppObject *v238;
  Il2CppClass *v240;
  s64 *Interface;
  char *v242;
  s64 *v243;
  System_Array_o *v244;
  System_Byte_array *v246;
  u64 *v247;
  Il2CppObject *v249;
  System_Byte_array *v253;
  fldFileInfoHeaderFL2_t_o *v254;
  System_String_o *v258;
  fldFileResolver_c *v259;
  s64 *gFldFileF1;
  AssetBundleCtrl_o *v261;
  Il2CppObject *v263;
  System_Byte_array *v265;
  Il2CppClass *v266;
  char *v267;
  s64 *v268;
  System_Array_o *v269;
  System_Byte_array *v271;
  u64 *v272;
  Il2CppObject *v274;
  System_Byte_array *v278;
  fldFileInfoHeaderFL1_t_o *v279;
  s32 v285;
  Il2CppObject *gFldFileBF;
  Il2CppObject *v290;
  u64 *v291;
  System_String_o *v293;
  System_String_o *key;
  s32 v300;
  UnityEngine_Quaternion_o rotation;
  dds3Basic_t_o *scene;
  System_String_o *pathstr;
  char v304[16];
  char *v305;
  System_Byte_array *aTopPtr;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v308;
  UnityEngine_Quaternion_o v309;
  UnityEngine_Quaternion_o v310;

  *&rotation.z = 0;
  scene = 0;
  *&rotation.x = 0;
  aTopPtr = 0;
  pathstr = "";
  gFldFileResetMode = 0;
  gFldFileF1 = 0;
  gFldFileF2 = 0;
  gFldInf_WpExit = 0;
  scene = dds3GetControlScene();
  MapNo = dds3GetMapNo(&scene);
  v8 = HIWORD(MapNo);
  v9 = NewSpecific(object, 4u);
  v9->m_Items[0] = "fldLoadFile field=";
  *v304 = HIWORD(MapNo);
  v11 = sub_8D3950(s32, v304);
  v12 = v11;
  v9->m_Items[1] = v12;
  v9->m_Items[2] = " area=";
  v300 = MapNo;
  v15 = sub_8D3950(s32, &v300);
  v16 = v15;
  v9->m_Items[3] = v16;
  v19 = Concat_5270224(v9);
  Log(v19, 0);
  if (v8 != fldGb->fieldID)
  {
    FieldAssetName = GetFieldAssetName("e{0:D3}", v8);
    Data = GetData(FieldAssetName, 0);
    LoadEventVoice(v8, FieldAssetName, Data);
  }
  fldAutoMapSetField(v8, MapNo - 1, 0);
  if (fldGb->fieldID <= 199)
  {
    fldPlayerALoad();
  }
  fieldID = fldGb->fieldID;
  if (fieldID < 200)
    goto LABEL_558;
  if (fieldID >= 500)
  {
LABEL_558:
    fldDrwZAlloc();
  }
  v29 = NewSpecific(char, 1u);
  *(v29 + 16) = 47;
  v31 = Split(pFileName, v29);
  max_length = v31->max_length;
  v33 = v31;
  v37 = Concat_5271136("field/", v31->m_Items[2], "/", v31->m_Items[3]);
  v39 = fldGb->fieldID;
  if (v39 <= 99)
  {
    v47 = Concat_5224608(v33->m_Items[4], "(Clone)", 0);
    v43 = nbFldCache_ToField_F(v47);
    goto LABEL_99;
  }
  else if (v39 < 200)
  {
    goto LABEL_110;
  }
  if (v39 > 299)
    goto LABEL_110;
LABEL_87:
  v42 = Concat_5224608(v33->m_Items[4], "(Clone)", 0);
  v43 = nbFldCache_ToField(v42);
LABEL_99:
  Prefab_16624656 = v43;
  v49 = op_Inequality(Prefab_16624656, 0, 0);
LABEL_111:
  if (op_Equality(Prefab_16624656, 0, 0))
  {
    v56 = v33->m_Items[4];
    v57 = GetData(v56, 0);
    Prefab_16624656 = v57;
    if (v57)
    {
      if (v57->klass != UnityEngine_GameObject)
      {
        sub_8FC2C0(v57->klass->_1.element_class, UnityEngine_GameObject, v304);
        if ((v304[0] & 1) != 0)
          v58 = v305;
        else
          v58 = &v304[1];
        v59 = sub_8C4940(v58);
      }
    }
  }
  if (op_Equality(Prefab_16624656, 0, 0))
  {
    asset_bc = get_asset_bc();
    Prefab_16624656 = LoadPrefab_16624656(asset_bc, akey, v37, v33->m_Items[4]);
  }
  EvtInstCash = GetEvtInstCash(Prefab_16624656);
  key = akey;
  if (op_Inequality(EvtInstCash, 0, 0))
  {
    FildMapObj = EvtInstCash;
    transform = get_transform(FildMapObj, 0);
    rotation = get_rotation(transform);
    sub_1A1CAE0(&rotation.x, 0);
    v69 = v68;
    v72 = v71;
    v73 = fmodf(v70 + 180.0, 360.0);
    v75 = get_transform(FildMapObj, 0);
    v309 = Euler(v69, v73, v72);
    set_rotation(v75, v309);
    set_layer(FildMapObj, 16);
    SetActive(FildMapObj, 1, 0);
    if (LODWORD(v33->max_length) > 4)
      goto LABEL_202;
LABEL_201:
  }
  if (!op_Inequality(Prefab_16624656, 0, 0))
  {
LABEL_200:
    if (LODWORD(v33->max_length) > 4)
      goto LABEL_202;
    goto LABEL_201;
  }
  if (v49)
  {
    FildMapObj = Prefab_16624656;
    {
LABEL_160:
    }
  }
  else
  {
    v79 = Find("Field", 0);
    v81 = get_transform(v79, 0);
    v83 = Instantiate_object__425664(Prefab_16624656, v81, 0);
    FildMapObj = v83;
    v85 = get_transform(FildMapObj, 0);
    rotation = get_rotation(v85);
    sub_1A1CAE0(&rotation.x, 0);
    v87 = v86;
    v90 = v89;
    v91 = fmodf(v88 + 180.0, 360.0);
    v93 = get_transform(FildMapObj, 0);
    v310 = Euler(v87, v91, v90);
    set_rotation(v93, v310);
    set_layer(FildMapObj, 16);
      goto LABEL_160;
  }
  if (fldGb->fieldID == 1)
  {
    v96 = Concat_5224608(v33->m_Items[3], "_mask_Camera");
    v97 = get_asset_bc();
    v98 = LoadPrefab_16624656(v97, akey, v37, v96);
    v99 = Find("Main Camera", 0);
    v101 = get_transform(v99, 0);
    v103 = Instantiate_object__425664(v98, v101, 0);
    FildMaskObj = v103;
  }
  v107 = Contains(v33->m_Items[4], "f800_001", 0);
  v109 = v33->m_Items[4];
  if (v107)
  {
    kernelObject->fldprefab = FildMapObj;
    v113 = AddComponent_object_(FildMapObj);
    v114 = Concat_5224608(v109, "(Clone)", 0);
    SetFiledName(v113, v114);
    v116 = Concat_5224608(v109, "(Clone)", 0);
    evtUpdateEx_FieldLoadAfter(v113, FildMapObj, v116);
    goto LABEL_200;
  }
  v133 = Find("Field", 0);
  gameObject = get_gameObject(v133);
  v135 = get_transform(gameObject, 0);
  v136 = Concat_5224608(v109, "(Clone)", 0);
  v137 = Find(v135, v136, 0);
  v139 = get_gameObject(v137);
  if (v49)
  {
    kernelObject->fldprefab = v139;
    Component_object = GetComponent_object_(v139);
  }
  else
  {
    kernelObject->fldprefab = v139;
    Component_object = AddComponent_object_(v139);
  }
  v143 = Component_object;
  v144 = Concat_5224608(v109, "(Clone)", 0);
  SetFiledName(v143, v144);
  v146 = Concat_5224608(v109, "(Clone)", 0);
  evtUpdateEx_FieldLoadAfter(v143, v139, v146);
  if (LODWORD(v33->max_length) <= 4)
    goto LABEL_201;
LABEL_202:
  v118 = v33->m_Items[4];
  v119 = NewSpecific(char, 1u);
  *(v119 + 16) = 95;
  v121 = Split(v118, v119);
  v122 = v121;
  Concat_5224608(v121->m_Items[0], "_am");
  if (fldGb->fieldID == 25)
  {
    else if (fldGb->areaID < 16)
    {
      goto LABEL_213;
    }
    if (!LODWORD(v122->max_length))
      goto LABEL_268;
    goto LABEL_252;
  }
LABEL_213:
  v127 = fldGb;
  if (v127->fieldID == 34)
  {
    else if (v127->areaID > 2)
    {
      goto LABEL_220;
    }
LABEL_254:
    v132 = &"_am";
    goto LABEL_273;
  }
LABEL_220:
  v128 = fldGb;
  if (v128->fieldID == 34)
  {
    else if (v128->areaID > 9)
    {
      goto LABEL_227;
    }
    if (!LODWORD(v122->max_length))
    {
LABEL_268:
    }
LABEL_252:
    v132 = &"b_am";
    goto LABEL_273;
  }
LABEL_227:
  v129 = fldGb;
  if (v129->fieldID != 34)
  {
LABEL_234:
    v130 = fldGb;
    if (v130->fieldID == 34)
    {
      if (v130->areaID <= 24)
      {
        v132 = &"d_am";
        goto LABEL_273;
      }
    }
    goto LABEL_254;
  }
  else if (v129->areaID > 17)
  {
    goto LABEL_234;
  }
  v132 = &"c_am";
LABEL_273:
  v150 = Concat_5224608(v122->m_Items[0], *v132);
  if (!Equals_5234480(autoMapPrefab, v150))
  {
    fldAutoMapDelete();
    autoMapPrefab = v150;
    v154 = v33->max_length;
    v158 = Concat_5271136("dds3data/fld/", v33->m_Items[2], "/automap/", v33->m_Items[3]);
    v159 = get_asset_bc();
    v161 = LoadPrefab_16624656(v159, akey, v158, v150);
    if (op_Inequality(v161, 0, 0))
    {
      v162 = Find("Field", 0);
      v164 = get_transform(v162, 0);
      v167 = Instantiate_object__425664(v161, v164, 0);
      AutoMapObjArea = v167;
      GetChildList(AutoMapObjArea, &mapNodeList1Area, &mapNodeList2Area);
      v171 = AddComponent_object_(AutoMapObjArea);
      SetLayerAll(v171, AutoMapObjArea, 21, 0);
      v172 = Find("Field", 0);
      v173 = get_transform(v172, 0);
      v174 = Instantiate_object__425664(v161, v173, 0);
      AutoMapObjHalf = v174;
      GetChildList(AutoMapObjHalf, &mapNodeList1Half, &mapNodeList2Half);
      v177 = get_transform(AutoMapObjHalf, 0);
      localPosition = get_localPosition(v177);
      v178 = get_transform(AutoMapObjHalf, 0);
      v308.x = 2000.0;
      v308.y = localPosition.y;
      v308.z = localPosition.z;
      set_localPosition(v178, v308);
      v181 = Concat_5221536("dds3data/fld/", v33->m_Items[2], "/automap/material");
      v182 = get_asset_bc();
      File = LoadFile(v182, "common", v181, "am_black_material_alpha", ".mat");
      if (File
            File->klass->_2.typeHierarchyDepth >= typeHierarchyDepth))
      {
        if (File->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == UnityEngine_Material)
          v185 = File;
        else
          v185 = 0;
      }
      else
      {
        v185 = 0;
      }
      if (op_Inequality(v185, 0, 0))
      {
        v187 = Instantiate_object_(v185);
        mat_black = v187;
      }
      v189 = get_asset_bc();
      v190 = LoadFile(v189, "common", v181, "am_white_material_alpha", ".mat");
      if (v190
      {
        if (v190->klass->_2.typeHierarchy[v192 - 1] == UnityEngine_Material)
          v193 = v190;
        else
          v193 = 0;
          goto LABEL_331;
      }
      else
      {
        v193 = 0;
          goto LABEL_331;
      }
LABEL_331:
      if (op_Inequality(v193, 0, 0))
      {
        v196 = Instantiate_object_(v193);
        mat_white = v196;
      }
      v198 = get_asset_bc();
      v199 = LoadFile(v198, "common", v181, "am_line_material_alpha", ".mat");
      if (v199)
      {
        if (v199->klass->_2.typeHierarchyDepth < v201)
        {
          v202 = 0;
            goto LABEL_345;
LABEL_353:
          if (op_Inequality(v202, 0, 0))
          {
            v206 = Instantiate_object_(v202);
            mat_line = v206;
          }
          ChangeMaterial(mapNodeList1Half, mapNodeList2Half, mat_black, mat_white, mat_white);
          v213 = AddComponent_object_(AutoMapObjHalf);
          SetLayerAll(v213, AutoMapObjHalf, 21, 0);
          goto LABEL_368;
        }
        if (v199->klass->_2.typeHierarchy[v201 - 1] == UnityEngine_Material)
          v202 = v199;
        else
          v202 = 0;
          goto LABEL_353;
      }
      else
      {
        v202 = 0;
          goto LABEL_353;
      }
LABEL_345:
      goto LABEL_353;
    }
  }
LABEL_368:
  fldClrCollision();
  fldEveHit_Init();
  fldSe_Init();
  fldNpcClear(0);
  fldTakaraWorkClear();
  v220 = fldGb;
  if (!v220->AreaToArea)
    goto LABEL_391;
LABEL_383:
  else
  {
    v221 = v220->fieldID;
    if (v221 == 25)
      goto LABEL_413;
  }
  if (fldGb->fieldID != 34)
    goto LABEL_407;
LABEL_413:
  fldAutoMapModelLoad();
  {
LABEL_408:
  }
LABEL_417:
  gFldFileTB = 0;
  if (gFldFileTB)
  {
    gFldFileTB = 0;
  }
  else
  {
    v228 = Format("{0}.TB.bytes", pFileName, 0);
    TexList = sdfDevLoadTexList(v228);
    gFldTexList = TexList;
  }
  v233 = Format("{0}.f2.bytes", pFileName, 0);
LABEL_430:
  gFldFileF2 = pFldNextFileDataF2;
  if (gFldFileF2)
  {
    if ((v234->_2.bitflags2 & 2) == 0)
      goto LABEL_452;
LABEL_435:
LABEL_452:
    if (!gFldFileF2)
    {
LABEL_458:
      Interface = 0;
LABEL_459:
      aTopPtr = Interface;
      Log("Copy..F2", 0);
      goto LABEL_463;
    }
LABEL_453:
    Interface = QueryInterface(gFldFileF2, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*gFldFileF2 + 64), v240, v304);
      if ((v304[0] & 1) != 0)
        v242 = v305;
      else
        v242 = &v304[1];
      v243 = sub_8C4940(v242);
    }
    goto LABEL_459;
  }
  v236 = get_asset_bc();
  if (!IsLoad(v236, akey))
  {
      goto LABEL_452;
    goto LABEL_435;
  }
  Log("Load..F2", 0);
  v238 = sdfDevLoadFileUnity_25061072(v233, &aTopPtr, 0, akey);
  gFldFileF2 = v238;
LABEL_463:
  v244 = NewSpecific(byte, (LODWORD(aTopPtr->max_length) - 8));
  BlockCopy(aTopPtr, 8, v244, 0, LODWORD(aTopPtr->max_length) - 8, 0);
  v246 = aTopPtr;
  *v304 = ToInt32(v246, 0, 0);
  v247 = sub_8D3950(s32, v304);
  v249 = Concat("F2:Ver=", v247);
  Log(v249, 0);
  pF2FileData = v244;
  v253 = aTopPtr;
  pF2Head = &aTopPtr->obj;
  v254 = fldAddressResolverFL2(v253);
  fldFileResolverFL2(v254, aTopPtr);
  billClrTexture(0);
  v258 = Format("{0}.f1.bytes", pFileName, 0);
LABEL_479:
  gFldFileF1 = pFldNextFileDataF1;
  if (gFldFileF1)
  {
    if ((v259->_2.bitflags2 & 2) == 0)
      goto LABEL_498;
LABEL_484:
LABEL_498:
    if (!gFldFileF1)
    {
LABEL_504:
      v265 = 0;
LABEL_505:
      aTopPtr = v265;
      goto LABEL_506;
    }
LABEL_499:
    v265 = QueryInterface(gFldFileF1, byte);
    if (!v265)
    {
      sub_8FC2C0(*(*gFldFileF1 + 64), v266, v304);
      if ((v304[0] & 1) != 0)
        v267 = v305;
      else
        v267 = &v304[1];
      v268 = sub_8C4940(v267);
    }
    goto LABEL_505;
  }
  v261 = get_asset_bc();
  if (!IsLoad(v261, key))
  {
      goto LABEL_498;
    goto LABEL_484;
  }
  v263 = sdfDevLoadFileUnity_25061072(v258, &aTopPtr, 0, key);
  gFldFileF1 = v263;
  v265 = aTopPtr;
LABEL_506:
  v269 = NewSpecific(byte, (LODWORD(v265->max_length) - 8));
  BlockCopy(aTopPtr, 8, v269, 0, LODWORD(aTopPtr->max_length) - 8, 0);
  v271 = aTopPtr;
  *v304 = ToInt32(v271, 0, 0);
  v272 = sub_8D3950(s32, v304);
  v274 = Concat("F1:Ver=", v272);
  Log(v274, 0);
  pF1FileData = v269;
  v278 = aTopPtr;
  pF1Head = &aTopPtr->obj;
  v279 = fldAddressResolverFL1(v278);
  fldFileResolverFL1(v279, aTopPtr, key);
  fldMakeObjectBasic2();
  fldMakeObjectBasic3();
  if (MapNo >> 19 <= 0x18 && fldSceneParam.loadScript)
  {
    gFldFileBF = pFldNextFileDataBF;
    if (gFldFileBF)
    {
      dds3SceneBasicLoadScriptFile_FromMem(&scene, gFldFileBF);
    }
    else
    {
      fldMakeFilePath(&pathstr, v8, v285);
      v290 = pathstr;
      *v304 = v8;
      v291 = sub_8D3950(s32, v304);
      v293 = Format_5268592("{0}f{1:D3}.bf", v290, v291);
      dds3SceneBasicLoadScriptFile(&scene, v293, key);
    }
  }
  fldDoor_AllSet();
  fldGb->AreaToArea = 0;
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
          goto LABEL_40;
        if (fldGb->CashAreaID == area)
        {
          v7 = 2;
        }
        else
        {
LABEL_40:
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
  else
  {
    if (pFldNextFileDataBF)
      return 1;
  }
  if (pFldNextFileDataTB)
    return 1;
LABEL_9:
  if (pFldNextFileDataF1)
    return 1;
  if (pFldNextFileDataF2)
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

  CashStat = fldGb->CashStat;
  if (CashStat)
  {
    if (CashStat != 1)
    {
        goto LABEL_20;
LABEL_19:
LABEL_20:
      fldGb->CashStat = 0;
      return 0;
    }
    if (IsFldDataLoaded())
    {
      goto LABEL_19;
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
  u32 v2;
  UnityEngine_Vector4_o v4;
  UnityEngine_Vector4_o v5;
  dds3Basic_t_o *basic;

  basic = 0;
  *&v5.x = 0;
  *&v5.z = 0;
  *&v4.x = 0;
  *&v4.z = 0;
  sub_854930(&v5, 0);
  sub_854930(&v5, 1u);
  sub_854930(&v5, 2u);
  sub_854930(&v5, 3u);
  sub_854930(&v4, 0);
  sub_854930(&v4, 1u);
  sub_854930(&v4, 2u);
  sub_854930(&v4, 3u);
  v2 = dds3SerializeID();
  basic = dds3AddMatterObjectBasic(v2, v5, v4);
  dds3SetBasicName(&basic, "FLD_DMY_MATTER");
  return basic;
}

// 0x1262f90
void fldMakeFilePath(char **pathstr, s32 field, s32 area) {
  u64 *v6;
  s64 *v7;
  s32 v8;

  if (field <= 199)
  {
    else if (IsDLCField(field))
    {
LABEL_7:
      v8 = field;
      v6 = sub_8D3950(s32, &v8);
      v7 = &"dds3data/fld/f/f{0:D3}m/";
      goto LABEL_13;
    }
    v8 = field;
    v6 = sub_8D3950(s32, &v8);
    v7 = &"dds3data/fld/f/f{0:D3}/";
    goto LABEL_13;
  }
  v8 = field;
  v6 = sub_8D3950(s32, &v8);
  if (field > 499)
    v7 = &"dds3data/fld/e/f{0:D3}/";
  else
    v7 = &"dds3data/fld/b/f{0:D3}/";
LABEL_13:
  *pathstr = Format(*v7, v6, 0);
}

// 0x126f440
void fldMakeObjectBasic2(void) {
  u64 v5;
  il2cpp_array_size_t *p_max_length;
  s32 v7;
  s64 v9;
  s64 v10;
  s64 v11;
  System_Byte_array *v12;
  s32 v13;
  fldResModel_t_o *v15;
  sdfModelDef_t_o *v18;
  sdfMotionPlayBook_t_o *v20;
  s64 v23;
  System_String_o *v34;
  UnityEngine_Object_o *FildMapObj;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v43;
  dds3Basic_t_o *v44;
  s32 fieldID;
  System_String_o **v49;
  s32 HojiID;
  u32 v53;
  fldFileResolver_c *v54;
  struct fldResHead_t_array *g_pHitData;
  u64 v56;
  Il2CppClass **v58;
  char *v59;
  Il2CppClass *v60;
  s64 v61;
  s64 v63;
  u64 v64;
  s64 v70;
  dds3Basic_t_o *v71;
  s32 v72;
  System_String_o *v74;
  dds3Basic_t_o *v75;
  s64 g_nModelData;
  struct fldResHead_t_array *g_pModelData;
  dds3Basic_t_o *pItemBasic;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;
  dds3Basic_t_o *basic;

  basic = 0;
  pItemBasic = 0;
  pBasic = 0;
  *&v81.x = 0;
  *&v81.z = 0;
  *&v80.x = 0;
  *&v80.z = 0;
  if (g_pModelData)
  {
    pBasic = dds3GetControlScene();
    if (g_nModelData)
    {
      v5 = 0;
      p_max_length = &g_pModelData->max_length;
      while (1)
      {
        v9 = g_pModelData + 8 * v5;
        v11 = *(v9 + 32);
        v10 = v9 + 32;
        v12 = *(v11 + 80);
        v13 = *(v11 + 72);
        v15 = SetfldResModel(v12, v13);
        v18 = SetsdfModelDef(*(*v10 + 80LL), v15->pMdl, 1);
        v20 = SetsdfMotionPlayBook(*(*v10 + 80LL), v15->pMot);
        dds3AddModelBasic2(
          *(*v10 + 16LL),
          v18,
          v20,
          gFldTexList,
          *(*v10 + 24LL),
          0);
        v23 = *(*v10 + 40LL);
        if (v23)
        {
          sub_854710(v23 + 16, 0);
          sub_854930(&v81, 0);
          sub_854710(*(*v10 + 40LL) + 16LL, 1u);
          sub_854930(&v81, 1u);
          sub_854710(*(*v10 + 40LL) + 16LL, 2u);
          sub_854930(&v81, 2u);
          sub_854930(&v81, 3u);
          sub_854710(*(*v10 + 40LL) + 32LL, 0);
          sub_854930(&v80, 0);
          sub_854710(*(*v10 + 40LL) + 32LL, 1u);
          sub_854930(&v80, 1u);
          sub_854710(*(*v10 + 40LL) + 32LL, 2u);
          sub_854930(&v80, 2u);
          sub_854710(*(*v10 + 40LL) + 32LL, 3u);
        }
        else
        {
          sub_854930(&v81, 0);
          sub_854930(&v81, 1u);
          sub_854930(&v81, 2u);
          sub_854930(&v81, 3u);
          sub_854930(&v80, 0);
          sub_854930(&v80, 1u);
          sub_854930(&v80, 2u);
        }
        sub_854930(&v80, 3u);
        basic = dds3AddMatterObjectBasic(*(*v10 + 16LL), v81, v80, 0);
        v34 = *(*v10 + 24LL);
        dds3SetBasicName(&basic, v34);
        if (op_Inequality(FildMapObj, 0, 0))
        {
          transform = get_transform(FildMapObj, 0);
          v43 = Find(transform, *(*v10 + 24LL), 0);
          if (op_Inequality(v43, 0, 0))
          {
            v44 = basic;
            v44->gameObject = get_gameObject(v43);
          }
        }
        fieldID = fldGb->fieldID;
        if (fieldID < 200)
          break;
        else if (fieldID > 499)
        {
          break;
        }
        switch (v5)
        {
          case 0:
            v7 = 1;
            break;
          case 1:
            v7 = 2;
            break;
          case 2:
            v7 = 3;
            break;
          case 3:
            v7 = 4;
            break;
          default:
            v7 = 5;
            break;
        }
LABEL_81:
        dds3MatterObjectBasicSetOt(&basic, v7);
        v49 = (*v10 + 24LL);
        HojiID = fldCommand_GetHojiID(v49);
        dds3MatterObjectBasicSetHojiID(&basic, HojiID);
        v53 = *(*v10 + 16LL);
        pItemBasic = dds3SearchSceneBasic(&pBasic, v53, 0xAu);
        dds3ObjectBaseSetControlBasic(&basic, &pItemBasic);
        dds3ObjectBaseMakeMatter(&basic);
        v56 = 0;
        if ((v54->_2.bitflags2 & 2) == 0)
          goto LABEL_99;
LABEL_95:
LABEL_99:
        while (v56 < g_nHitData)
        {
LABEL_100:
          v58 = &g_pHitData->obj.klass + v56;
          v60 = v58[4];
          v59 = (v58 + 4);
          v61 = *&v60->_1.this_arg.bits;
          if (v61)
          {
            v63 = *(v61 + 24);
            v64 = 0;
            while (1)
            {
              if (v64 >= *(*(*v59 + 56LL) + 16LL))
                break;
              if (!Compare(*(*v10 + 24LL), *(*(v63 + 32 + 8 * v64++) + 24LL), 0))
              {
                v70 = *v59;
                v71 = basic;
                v72 = *(v70 + 16);
                fldHitLinkMatter(v72, v71);
                break;
              }
            }
          }
          ++v56;
            goto LABEL_95;
        }
LABEL_120:
        if (basic)
        {
          v74 = *(*(*v10 + 48LL) + 24LL);
          v75 = pBasic;
          pItemBasic = dds3SceneBasicSearchNameAndType(v75, 2u, v74);
          dds3ObjectBaseSetControlBasic(&basic, &pItemBasic);
          dds3ObjectBaseRegistArea(&basic);
        }
        if (++v5 == g_nModelData)
          goto LABEL_128;
      }
      v7 = 6;
      goto LABEL_81;
    }
  }
LABEL_128:
  FindHojiObj();
}

// 0x12704a0
void fldMakeObjectBasic3(void) {
  u32 i;
  s32 v11;
  u64 *v14;
  u64 *v15;
  u64 *v16;
  System_String_o *v18;
  s32 v19;
  s32 v21;
  dds3Basic_t_o *v24;
  System_Object_array *v27;
  s64 *v29;
  s64 *v31;
  System_String_o *v32;
  System_String_o *v36;
  u64 *v52;
  s32 v55;
  fldGlobal_c *v57;
  s16 v58;
  s32 v59;
  System_Object_array *v61;
  s64 *v63;
  s64 *v64;
  s64 *v66;
  s64 *v68;
  System_String_o *v70;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 v74;
  u32 areaID;
  struct fldGlobalWork_t_o *v76;
  u32 v77;
  u32 v80;
  s32 v81;
  dds3Basic_t_o *pMoverBasic;
  dds3PathBasicControl_t_o *pControl;
  dds3Basic_t_o *pPathBasic;
  dds3Basic_t_o *pObjectBasic;
  dds3Basic_t_o *pBasic;
  System_String_o *v87;
  System_String_o *v88[3];
  System_String_o *pName;

  pName = 0;
  pBasic = 0;
  v87 = 0;
  pControl = 0;
  pPathBasic = 0;
  pObjectBasic = 0;
  pMoverBasic = 0;
  pBasic = dds3GetControlScene();
  for (i = 0; i < 0xF; ++i)
  {
    v11 = i + 1;
    if (fldGbChkGimic(fldGb->fieldID, fldGb->areaID + 1, v11))
    {
      LODWORD(v88[0]) = i + 1;
      v14 = sub_8D3950(s32, v88);
      pName = Format("md_hoji_{0:D2}", v14, 0);
      v81 = i + 1;
      v15 = sub_8D3950(s32, &v81);
      v87 = Format("atari_hoji_{0:D2}", v15, 0);
      v80 = i + 1;
      v16 = sub_8D3950(s32, &v80);
      v18 = Format("path_hoji_{0:D2}", v16, 0);
      v19 = fldCommand_SEARCH_ID(&pName);
      v21 = fldCommand_SEARCH_ID(&v87);
      if (v19 != -1)
      {
        pObjectBasic = dds3SearchSceneBasic(&pBasic, v19, 6u);
        if (!pObjectBasic)
        {
          pObjectBasic = fldGetMatter_From_ModelRangeID(v21);
          v24 = pBasic;
            goto LABEL_57;
          goto LABEL_33;
        }
        goto LABEL_32;
      }
      else
      {
        pObjectBasic = fldGetMatter_From_ModelRangeID(v21);
        if (pObjectBasic)
          goto LABEL_32;
      }
      v27 = NewSpecific(object, 3u);
      LODWORD(v88[0]) = fldGb->areaID + 1;
      v29 = sub_8D3950(s32, v88);
      v31 = v29;
      v27->m_Items[0] = v31;
      v32 = pName;
      v27->m_Items[1] = v32;
      v36 = v87;
      v27->m_Items[2] = v36;
      SDF_ABORT4("FUKI NotFound %03d [%s][%s]", v27);
      v24 = pBasic;
        goto LABEL_57;
      goto LABEL_33;
    }
LABEL_77:
    if (fldGbChkView(fldGb->fieldID, fldGb->areaID + 1, v11))
    {
      LODWORD(v88[0]) = i + 1;
      v52 = sub_8D3950(s32, v88);
      pName = Format("md_hoji_{0:D2}", v52, 0);
      v55 = fldCommand_SEARCH_ID(&pName);
      pObjectBasic = dds3SearchSceneBasic(&pBasic, v55, 6u);
      if (pObjectBasic)
      {
        if ((v58 & 0x200) == 0)
          goto LABEL_89;
LABEL_109:
        v59 = v58 & 0x200;
      }
      else
      {
        v61 = NewSpecific(object, 3u);
        LODWORD(v88[0]) = fldGb->fieldID;
        v63 = sub_8D3950(s32, v88);
        v64 = v63;
        v61->m_Items[0] = v64;
        v81 = fldGb->areaID + 1;
        v66 = sub_8D3950(s32, &v81);
        v68 = v66;
        v61->m_Items[1] = v68;
        v70 = pName;
        v61->m_Items[2] = v70;
        SDF_ABORT4("FUKI NotFound f%03d_%03d [%s]", v61);
        if ((v58 & 0x200) != 0)
          goto LABEL_109;
LABEL_89:
        v59 = 0;
      }
      fieldID = fldGb->fieldID;
      if (fieldID == 8)
        v74 = 10;
      else
        v74 = 2;
      else if (fieldID == 18)
      {
LABEL_118:
        areaID = fldGb->areaID;
        if (areaID <= 6 && ((1 << areaID) & 0x43) != 0)
        {
          v74 = 10;
          if ((v57->_2.bitflags2 & 2) == 0)
            goto LABEL_129;
          goto LABEL_127;
        }
      }
      if ((v57->_2.bitflags2 & 2) == 0)
      {
LABEL_129:
        v76 = fldGb;
        if (v76->fieldID == 28)
        {
          v77 = v76->areaID;
          if (v77 <= 9 && ((1 << v77) & 0x320) != 0)
            v74 = 10;
        }
        dds3MatterObjectBasicSetAlpMode(&pObjectBasic, v74);
        continue;
      }
LABEL_127:
      goto LABEL_129;
    }
  }
}

// 0x12610f0
void fldMakeResouceBasicFL1(fldResourceTypeTable_t **pTypeTable, u32 nTypeTable, u8 **pHead) {
  u64 *v7;
  u32 *v9;
  u64 v11;
  fldResourceTypeTable_t_o *v13;
  struct fldResHead_t_array *pResourceDataTable;
  u64 v16;
  fldResHead_t_o **v17;
  Il2CppObject *v19;
  s32 v23;
  Il2CppObject *v24;
  u64 v26;
  fldResHead_t_o **m_Items;
  Il2CppObject *resourceName;
  struct fldResHeadPos_t_o *sisei;
  s32 v43;
  fldResCollision_t_o *v44;
  s32 v46;
  Il2CppObject *v47;
  fldResCollisionPoly_t_o *v49;
  System_String_o **p_resourceName;
  System_Byte_array *v52;
  u64 *v53;
  s32 HojiID;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s32 v61;
  s32 resourceID;
  u64 v65;
  fldResHead_t_o **v66;
  Il2CppObject *v68;
  struct fldResHeadPos_t_o *v70;
  s32 v81;
  fldResourceEffect_t_o *v82;
  s32 v83;
  u32 type;
  struct System_String_array *pEffFileName;
  u32 noEffect;
  s64 v89;
  dds3Basic_t_o *v91;
  struct System_Single_array *size;
  struct System_String_array *v96;
  u32 v97;
  s64 v98;
  u32 v102;
  struct System_Byte_array_array *pFldF1Eff;
  fldGlobal_c *v106;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  struct System_String_array *v112;
  s64 v113;
  System_String_o *v115;
  System_String_o *v116;
  u64 *v117;
  System_String_o *v118;
  s64 v119;
  s64 v121;
  dds3Basic_t_o *v122;
  s32 v127;
  struct System_String_array *v128;
  s64 v129;
  System_String_o *v131;
  System_String_o *v132;
  u64 *v133;
  System_String_o *v134;
  s64 v135;
  s64 v137;
  dds3Basic_t_o *v138;
  struct System_Byte_array_array *v143;
  s64 v144;
  u64 v146;
  fldResHead_t_o **v147;
  Il2CppObject *v149;
  struct fldResHeadPos_t_o *v151;
  s32 v162;
  struct fldGlobalWork_t_o *v165;
  s32 areaID;
  s32 v167;
  System_String_o *v169;
  System_String_o *v173;
  s32 v174;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v179;
  s64 *v180;
  u64 v181;
  fldResourceTypeTable_t_array *v182;
  u32 *v183;
  u64 v184;
  u64 nResourceDataTable;
  fldResourceLight_t_o *pLight;
  fldResourceEffect_t_o *pResEff;
  System_String_o *pathstr;
  dds3Basic_t_o *basic;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *aPtr;
  UnityEngine_Vector4_o v192;
  UnityEngine_Vector4_o pos;
  u64 v194[4];
  UnityEngine_Vector4_o v195;

  pBasic = 0;
  aPtr = 0;
  basic = 0;
  pLight = 0;
  pResEff = 0;
  *&pos.x = 0;
  *&pos.z = 0;
  pathstr = "";
  *&v192.x = 0;
  *&v192.z = 0;
  v7 = NewSpecific(char, 4u);
  v9 = NewSpecific(dds3Basic_t, 4u);
  g_pModelData = 0;
  g_nModelData = 0;
  if (nTypeTable)
  {
    v11 = 0;
    v181 = nTypeTable;
    v182 = pTypeTable;
    v183 = v9;
LABEL_8:
    v13 = pTypeTable->m_Items[v11];
    nResourceDataTable = v13->nResourceDataTable;
    pResourceDataTable = v13->pResourceDataTable;
    v184 = v11;
    switch (v13->type)
    {
      case 2u:
        g_pModelData = pResourceDataTable;
        g_nModelData = nResourceDataTable;
        goto LABEL_293;
      case 3u:
        if (nResourceDataTable)
        {
          v26 = 0;
          m_Items = pResourceDataTable->m_Items;
          do
          {
            while (1)
            {
              resourceName = m_Items[v26]->resourceName;
              Write_2930400("RHIT Name:{0}\n", resourceName);
              m_Items[v26]->resourceID |= 0x20000u;
              sisei = m_Items[v26]->sisei;
              if (sisei)
              {
                sub_854710(&sisei->fields, 0);
                sub_854930(&pos, 0);
                sub_854710(&m_Items[v26]->sisei->fields, 1u);
                sub_854930(&pos, 1u);
                sub_854710(&m_Items[v26]->sisei->fields, 2u);
                sub_854930(&pos, 2u);
                sub_854930(&pos, 3u);
                sub_854710(&m_Items[v26]->sisei->rot, 0);
                sub_854930(&v192, 0);
                sub_854710(&m_Items[v26]->sisei->rot, 1u);
                sub_854930(&v192, 1u);
                sub_854710(&m_Items[v26]->sisei->rot, 2u);
                sub_854930(&v192, 2u);
                sub_854710(&m_Items[v26]->sisei->rot, 3u);
              }
              else
              {
                sub_854930(&pos, 0);
                sub_854930(&pos, 1u);
                sub_854930(&pos, 2u);
                sub_854930(&pos, 3u);
                sub_854930(&v192, 0);
                sub_854930(&v192, 1u);
                sub_854930(&v192, 2u);
              }
              sub_854930(&v192, 3u);
              v43 = m_Items[v26]->_union;
              v44 = SetfldResCollision(pHead, v43);
              if (!v44->Type)
                break;
              if (nResourceDataTable == ++v26)
                goto LABEL_293;
            }
            v46 = v44->_union;
            v47 = v44;
            v49 = SetfldResCollisionPoly(pHead, v46);
            p_resourceName = &m_Items[v26]->resourceName;
            v52 = pHead;
            v53 = v7;
            HojiID = fldCommand_GetHojiID(p_resourceName);
            x = pos.x;
            y = pos.y;
            z = pos.z;
            w = pos.w;
            v61 = HojiID;
            resourceID = m_Items[v26]->resourceID;
            v195.x = x;
            v195.y = y;
            v195.z = z;
            v195.w = w;
            fldAddCollisionPoly(v49, v195, resourceID, v61, -1);
            v7 = v53;
            aPtr = dds3AddModelRangeBasicNew(m_Items[v26]->resourceID, v47, pos, m_Items[v26]->resourceName);
            dds3ModelRangeBasicSetBlockID(&aPtr, v26 + 1);
            pHead = v52;
            v9 = v183;
            ++v26;
          }
          while (nResourceDataTable != v26);
        }
        goto LABEL_293;
      case 9u:
        if (nResourceDataTable)
        {
          v16 = 0;
          v17 = pResourceDataTable->m_Items;
          do
          {
            v19 = v17[v16]->resourceName;
            Write_2930400("RMOT Name:{0}\n", v19);
            v23 = v17[v16]->_union;
            v24 = SetfldResourcePathTableInfo(pHead, v23);
            dds3AddPathBasic(v17[v16]->resourceID, v24, v17[v16]->resourceName);
            ++v16;
          }
          while (nResourceDataTable != v16);
        }
        goto LABEL_293;
      case 0xBu:
        if (!nResourceDataTable)
          goto LABEL_293;
        v65 = 0;
        v66 = pResourceDataTable->m_Items;
        while (1)
        {
          v68 = v66[v65]->resourceName;
          Write_2930400("REFF Name:{0}\n", v68);
          v70 = v66[v65]->sisei;
          if (v70)
          {
            sub_854710(&v70->fields, 0);
            sub_854930(&pos, 0);
            sub_854710(&v66[v65]->sisei->fields, 1u);
            sub_854930(&pos, 1u);
            sub_854710(&v66[v65]->sisei->fields, 2u);
            sub_854930(&pos, 2u);
            sub_854930(&pos, 3u);
            sub_854710(&v66[v65]->sisei->rot, 0);
            sub_854930(&v192, 0);
            sub_854710(&v66[v65]->sisei->rot, 1u);
            sub_854930(&v192, 1u);
            sub_854710(&v66[v65]->sisei->rot, 2u);
            sub_854930(&v192, 2u);
            sub_854710(&v66[v65]->sisei->rot, 3u);
          }
          else
          {
            sub_854930(&pos, 0);
            sub_854930(&pos, 1u);
            sub_854930(&pos, 2u);
            sub_854930(&pos, 3u);
            sub_854930(&v192, 0);
            sub_854930(&v192, 1u);
            sub_854930(&v192, 2u);
          }
          sub_854930(&v192, 3u);
          v81 = v66[v65]->_union;
          v82 = SetfldResourceEffect(pHead, v81);
          pResEff = v82;
          type = v82->type;
          switch (type)
          {
            case 0u:
            case 3u:
              noEffect = v82->noEffect;
              if (*(v7 + noEffect + 16))
              {
                v89 = pResEff->noEffect;
                v91 = dds3AddTMXEffectObjectBasic3(&v9[2 * v89 + 8], pos, v192);
                goto LABEL_140;
              }
              fieldID = fldGb->fieldID;
              fldMakeFilePath(&pathstr, fieldID, v83);
              v112 = pEffFileName;
              v113 = pResEff->noEffect;
              v115 = Format_5268592("{0}{1}", pathstr, v112->m_Items[v113]);
              LODWORD(v194[0]) = fldGb->fieldID;
              v116 = v115;
              v117 = sub_8D3950(s32, v194);
              v118 = Format("f{0:D3}", v117, 0);
              basic = dds3AddTMXEffectObjectBasic(v116, pos, v192, v118);
              dds3EffectObjectBasicStatOn(&basic, 1u);
              dds3EffectObjectBasicSetFldEx(&basic, &pResEff);
              v119 = pResEff->noEffect;
              *(v7 + v119 + 16) = 1;
              v121 = pResEff->noEffect;
              v122 = basic;
              *&v9[2 * v121 + 8] = v122;
              goto LABEL_232;
            case 1u:
              v96 = pEffFileName;
              v97 = v82->noEffect;
              if (!*(v7 + v97 + 16))
              {
                v127 = fldGb->fieldID;
                fldMakeFilePath(&pathstr, v127, v83);
                v128 = pEffFileName;
                v129 = pResEff->noEffect;
                v131 = Format_5268592("{0}{1}", pathstr, v128->m_Items[v129]);
                LODWORD(v194[0]) = fldGb->fieldID;
                v132 = v131;
                v133 = sub_8D3950(s32, v194);
                v134 = Format("f{0:D3}", v133, 0);
                basic = dds3AddP2AEffectObjectBasic(v132, pos, v192, v134);
                dds3EffectObjectBasicStatOn(&basic, 1u);
                v135 = pResEff->noEffect;
                *(v7 + v135 + 16) = 1;
                v137 = pResEff->noEffect;
                v138 = basic;
                *&v9[2 * v137 + 8] = v138;
                goto LABEL_231;
              }
              v98 = pResEff->noEffect;
              v91 = dds3AddP2AEffectObjectBasic3(&v9[2 * v98 + 8], pos, v192);
LABEL_140:
              basic = v91;
              dds3EffectObjectBasicStatOn(&basic, 1u);
              dds3EffectObjectBasicSetFldEx(&basic, &pResEff);
              goto LABEL_232;
            case 2u:
              v102 = v82->noEffect;
              if (!pFldF1Eff->m_Items[v102])
                goto LABEL_232;
              if (fldGb->fieldID != 20)
                goto LABEL_225;
              else if (fldGb->areaID)
              {
                goto LABEL_200;
              }
              if (pResEff->noEffect <= 1)
              {
                tpAlfRaitoSet(2.0);
                  goto LABEL_201;
LABEL_161:
                goto LABEL_201;
              }
LABEL_200:
              if ((v106->_2.bitflags2 & 2) != 0)
                goto LABEL_161;
LABEL_201:
              if (fldGb->areaID == 1 && pResEff->noEffect <= 1)
              {
                tpAlfRaitoSet(2.0);
              }
              if (fldGb->areaID == 13 && pResEff->noEffect <= 1)
              {
                tpAlfRaitoSet(2.0);
              }
              if (fldGb->areaID == 24 && pResEff->noEffect <= 1)
              {
                tpAlfRaitoSet(2.0);
              }
LABEL_225:
              v143 = pFldF1Eff;
              v144 = pResEff->noEffect;
              basic = dds3AddD3PEffectObjectBasic2(&v143->m_Items[v144]->obj, pos, v192);
              dds3EffectObjectBasicStatOn(&basic, 1u);
LABEL_231:
              dds3EffectObjectBasicSetFldEx(&basic, &pResEff);
LABEL_232:
              if (nResourceDataTable == ++v65)
                goto LABEL_293;
              break;
            default:
              if (type == 100)
              {
                size = v82->size;
                basic = dds3AddESPEffectObjectBasic(v66[v65]->resourceName, pos, v192, size->m_Items[0] * 0.5);
                dds3EffectObjectBasicStatOff(&basic, 1u);
              }
              goto LABEL_232;
          }
        }
      case 0xCu:
        if (!nResourceDataTable)
          goto LABEL_293;
        v146 = 0;
        v147 = pResourceDataTable->m_Items;
        break;
      default:
        goto LABEL_293;
    }
    while (1)
    {
      v149 = v147[v146]->resourceName;
      Write_2930400("RELT Name:{0}\n", v149);
      v151 = v147[v146]->sisei;
      if (v151)
      {
        sub_854710(&v151->fields, 0);
        sub_854930(&pos, 0);
        sub_854710(&v147[v146]->sisei->fields, 1u);
        sub_854930(&pos, 1u);
        sub_854710(&v147[v146]->sisei->fields, 2u);
        sub_854930(&pos, 2u);
        sub_854930(&pos, 3u);
        sub_854710(&v147[v146]->sisei->rot, 0);
        sub_854930(&v192, 0);
        sub_854710(&v147[v146]->sisei->rot, 1u);
        sub_854930(&v192, 1u);
        sub_854710(&v147[v146]->sisei->rot, 2u);
        sub_854930(&v192, 2u);
        sub_854710(&v147[v146]->sisei->rot, 3u);
      }
      else
      {
        sub_854930(&pos, 0);
        sub_854930(&pos, 1u);
        sub_854930(&pos, 2u);
        sub_854930(&pos, 3u);
        sub_854930(&v192, 0);
        sub_854930(&v192, 1u);
        sub_854930(&v192, 2u);
      }
      sub_854930(&v192, 3u);
      v162 = v147[v146]->_union;
      pLight = SetfldResourceLight(pHead, v162);
      v165 = fldGb;
      v167 = v165->fieldID;
      areaID = v165->areaID;
      v169 = v147[v146]->resourceName;
      fldLoad_BasicLightLoadAfter(v167, areaID + 1, &pLight, &pos, v169);
      pBasic = dds3AddLightObjectBasic(v147[v146]->resourceID);
      v173 = v147[v146]->resourceName;
      dds3SetBasicName(&pBasic, v173);
      dds3SetPosPoseSet(&pBasic, pos);
      dds3SetRadiusPoseSet(&pBasic, pLight->OutsideR);
      dds3SetLightObjectResoruce(&pBasic, pLight);
      v174 = fldGb->fieldID;
      if (v174 < 200)
        goto LABEL_292;
      else if (v174 <= 499)
      {
LABEL_286:
        workdata = pBasic->workdata;
        klass = workdata->klass;
        if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
        {
          sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v194);
          if ((v194[0] & 1) != 0)
            v179 = v194[2];
          else
            v179 = v194 + 1;
          v180 = sub_8C4940(v179);
        }
        HIDWORD(workdata[3].monitor) |= 8u;
        dds3SetBasicName(&pBasic, "BTL_DEF_LIGHT");
      }
LABEL_292:
      if (++v146 >= nResourceDataTable)
      {
LABEL_293:
        pTypeTable = v182;
        v11 = v184 + 1;
        if (v184 + 1 >= v181)
          return;
        goto LABEL_8;
      }
    }
  }
}

// 0x126d340
void fldMakeResouceBasicFL2(fldResourceTypeTable_t **pTypeTable, u32 nTypeTable, u8 **pHead) {
  u64 *v7;
  u64 v11;
  fldResourceTypeTable_t_o *v13;
  u64 nResourceDataTable;
  struct fldResHead_t_array *pResourceDataTable;
  u64 v17;
  fldResHead_t_o **m_Items;
  Il2CppObject *resourceName;
  struct fldResHeadPos_t_o *sisei;
  s32 v34;
  fldResCollision_t_o *v35;
  fldResCollision_t_o *v36;
  System_String_o **p_resourceName;
  s32 HojiID;
  s32 v42;
  s32 v43;
  fldResCollisionPoly_t_o *v44;
  s64 v47;
  s64 v48;
  fldResCollisionPoly_t_o *v49;
  s32 resourceID;
  u64 v53;
  fldResHead_t_o **v54;
  Il2CppObject *v56;
  s32 v60;
  Il2CppObject *v61;
  u64 v63;
  fldResHead_t_o **v64;
  fldResEvent_t_o *v66;
  s32 v68;
  dds3Basic_t_o *v71;
  fldResHead_t_o *v73;
  u64 v74;
  fldResHead_t_o **v75;
  Il2CppObject *v77;
  struct fldResHeadPos_t_o *v79;
  s32 v90;
  fldResCam_t_o *v91;
  f32 v93;
  f32 *workdata;
  s64 v96;
  s64 typeHierarchyDepth;
  System_String_o *v99;
  u64 v100;
  il2cpp_array_size_t *p_max_length;
  fldResHead_t_o **v102;
  fldResHead_t_o **v105;
  Il2CppObject *v106;
  struct fldResHeadPos_t_o *v108;
  s32 v118;
  fldResPut_t_o *pPut;
  s64 v121;
  s64 v122;
  s64 v123;
  s64 v124;
  s64 v125;
  fldResPut_t_o *v126;
  struct fldResHeadPos_t_o *v128;
  fldResHead_t_o *v130;
  u32 v131;
  System_String_o *v132;
  s32 v133;
  fldResPutNpc_t_o *v134;
  u32 v136;
  s32 v138;
  s32 v140;
  s32 fieldID;
  f32 v143;
  f32 v144;
  f32 v145;
  f32 v146;
  s64 v148;
  s64 v149;
  s32 EveIdx;
  f32 v151;
  f32 v152;
  struct fldResHeadPos_t_o *v155;
  fldResHead_t_o *v157;
  u32 v158;
  System_String_o *v159;
  dds3Basic_t_o *v161;
  fldResHead_t_o *v163;
  s32 v164;
  fldResPutItemBox_t_o *v165;
  struct fldGlobalWork_t_o *fldGb;
  s32 v168;
  s32 id;
  f32 v170;
  f32 v171;
  f32 v172;
  f32 v173;
  s64 v175;
  s64 v176;
  f32 v177;
  f32 v178;
  s32 v179;
  fldResPutSE_t_o *v180;
  f32 r;
  s32 v182;
  f32 v183;
  f32 v184;
  f32 v185;
  f32 v186;
  f32 v188;
  f32 v189;
  char *v190;
  s64 *v191;
  u64 v192;
  fldResourceTypeTable_t_array *v193;
  u64 v194;
  fldResourcePoint_t_o v195;
  fldResourcePoint_t_o v196;
  fldResourcePoint_t_o v197;
  fldResourcePoint_t_o v198;
  fldResourcePoint_t_o v199;
  System_String_o *pName;
  dds3Basic_t_o *aPtr;
  UnityEngine_Vector4_o v202;
  UnityEngine_Vector4_o v203;
  UnityEngine_Vector4_o v204;
  UnityEngine_Vector4_o v205;
  UnityEngine_Vector4_o v206;

  pName = 0;
  memset(&v199, 0, sizeof(v199));
  memset(&v198, 0, sizeof(v198));
  *&v203.x = 0;
  *&v203.z = 0;
  *&v202.x = 0;
  *&v202.z = 0;
  v7 = Allocate(dds3Basic_t);
  dds3Basic_t___ctor(v7);
  aPtr = v7;
  g_pHitData = 0;
  g_nHitData = 0;
  if (nTypeTable)
  {
    v192 = nTypeTable;
    v193 = pTypeTable;
    v11 = 0;
LABEL_8:
    v13 = pTypeTable->m_Items[v11];
    nResourceDataTable = v13->nResourceDataTable;
    pResourceDataTable = v13->pResourceDataTable;
    v194 = v11;
    switch (v13->type)
    {
      case 3u:
        g_pHitData = pResourceDataTable;
        g_nHitData = nResourceDataTable;
        if (!nResourceDataTable)
          goto LABEL_271;
        v17 = 0;
        m_Items = pResourceDataTable->m_Items;
        do
        {
          while (1)
          {
            resourceName = m_Items[v17]->resourceName;
            Write_2930400("RHIT Name:{0}\n", resourceName);
            m_Items[v17]->resourceID |= 0x10000u;
            sisei = m_Items[v17]->sisei;
            if (sisei)
            {
              sub_854710(&sisei->fields, 0);
              sub_854930(&v203, 0);
              sub_854710(&m_Items[v17]->sisei->fields, 1u);
              sub_854930(&v203, 1u);
              sub_854710(&m_Items[v17]->sisei->fields, 2u);
              sub_854930(&v203, 2u);
              sub_854930(&v203, 3u);
              sub_854710(&m_Items[v17]->sisei->rot, 0);
              sub_854930(&v202, 0);
              sub_854710(&m_Items[v17]->sisei->rot, 1u);
              sub_854930(&v202, 1u);
              sub_854710(&m_Items[v17]->sisei->rot, 2u);
              sub_854930(&v202, 2u);
              sub_854710(&m_Items[v17]->sisei->rot, 3u);
            }
            else
            {
              sub_854930(&v203, 0);
              sub_854930(&v203, 1u);
              sub_854930(&v203, 2u);
              sub_854930(&v203, 3u);
              sub_854930(&v202, 0);
              sub_854930(&v202, 1u);
              sub_854930(&v202, 2u);
            }
            sub_854930(&v202, 3u);
            v34 = m_Items[v17]->_union;
            v35 = SetfldResCollision(pHead, v34);
            if (!v35->Type)
              break;
            if (nResourceDataTable == ++v17)
              goto LABEL_271;
          }
          v36 = v35;
          p_resourceName = &m_Items[v17]->resourceName;
          HojiID = fldCommand_GetHojiID(p_resourceName);
          v42 = v36->_union;
          v43 = HojiID;
          v44 = SetfldResCollisionPoly(pHead, v42);
          v47 = *&v203.x;
          v48 = *&v203.z;
          v49 = v44;
          resourceID = m_Items[v17]->resourceID;
          *&v204.x = v47;
          *&v204.z = v48;
          fldAddCollisionPoly(v49, v204, resourceID, v43, -1);
          aPtr = dds3AddModelRangeBasicNew(m_Items[v17]->resourceID, v36, v203, m_Items[v17]->resourceName);
          dds3ModelRangeBasicSetBlockID(&aPtr, ++v17);
        }
        while (nResourceDataTable != v17);
        goto LABEL_271;
      case 4u:
        if (!nResourceDataTable)
          goto LABEL_271;
        v74 = 0;
        v75 = pResourceDataTable->m_Items;
        while (1)
        {
          v77 = v75[v74]->resourceName;
          Write_2930400("RCAM Name:{0}\n", v77);
          v79 = v75[v74]->sisei;
          if (v79)
          {
            sub_854710(&v79->fields, 0);
            sub_854930(&v203, 0);
            sub_854710(&v75[v74]->sisei->fields, 1u);
            sub_854930(&v203, 1u);
            sub_854710(&v75[v74]->sisei->fields, 2u);
            sub_854930(&v203, 2u);
            sub_854930(&v203, 3u);
            sub_854710(&v75[v74]->sisei->rot, 0);
            sub_854930(&v202, 0);
            sub_854710(&v75[v74]->sisei->rot, 1u);
            sub_854930(&v202, 1u);
            sub_854710(&v75[v74]->sisei->rot, 2u);
            sub_854930(&v202, 2u);
            sub_854710(&v75[v74]->sisei->rot, 3u);
          }
          else
          {
            sub_854930(&v203, 0);
            sub_854930(&v203, 1u);
            sub_854930(&v203, 2u);
            sub_854930(&v203, 3u);
            sub_854930(&v202, 0);
            sub_854930(&v202, 1u);
            sub_854930(&v202, 2u);
          }
          sub_854930(&v202, 3u);
          aPtr = dds3AddCameraObjectBasicTypeFree(v75[v74]->resourceID, v203, v202);
          v90 = v75[v74]->_union;
            break;
          if ((byte_3F59183 & 1) == 0)
            goto LABEL_137;
LABEL_138:
          v91 = Allocate(fldResCam_t);
          fldResCam_t___ctor(v91);
          v93 = ToSingle(pHead, v90, 0);
          v91->fovy = v93;
          workdata = aPtr->workdata;
          v96 = *workdata;
          if (*(*workdata + 288LL) < typeHierarchyDepth
            || *(*(v96 + 200) + 8 * typeHierarchyDepth - 8) != dds3CameraObjectBasicWorkData_t)
          {
            sub_8FC2C0(*(v96 + 64), dds3CameraObjectBasicWorkData_t, &v197);
            if ((LOBYTE(v197.pos.x) & 1) != 0)
              v190 = *&v197.rot.x;
            else
              v190 = &v197.pos.x + 1;
            v191 = sub_8C4940(v190);
          }
          workdata[26] = v93;
          v99 = v75[v74]->resourceName;
          dds3SetBasicName(&aPtr, v99);
          if (++v74 >= nResourceDataTable)
            goto LABEL_271;
        }
        if ((byte_3F59183 & 1) != 0)
          goto LABEL_138;
LABEL_137:
        goto LABEL_138;
      case 6u:
        if (!nResourceDataTable)
          goto LABEL_271;
        v63 = 0;
        v64 = pResourceDataTable->m_Items;
        break;
      case 7u:
        while (1)
          ;
      case 9u:
        if (nResourceDataTable)
        {
          v53 = 0;
          v54 = pResourceDataTable->m_Items;
          do
          {
            v56 = v54[v53]->resourceName;
            Write_2930400("RMOT Name:{0}\n", v56);
            v60 = v54[v53]->_union;
            v61 = SetfldResourcePathTableInfo(pHead, v60);
            dds3AddPathBasic(v54[v53]->resourceID, v61, v54[v53]->resourceName);
            ++v53;
          }
          while (nResourceDataTable != v53);
        }
        goto LABEL_271;
      case 0xAu:
        if (!nResourceDataTable)
          goto LABEL_271;
        v100 = 0;
        p_max_length = &pResourceDataTable->max_length;
        v102 = pResourceDataTable->m_Items;
        while (2)
        {
          v105 = &v102[v100];
          v106 = (*v105)->resourceName;
          Write_2930400("RPOS Name:{0}\n", v106);
          v108 = (*v105)->sisei;
          if (v108)
          {
            sub_854710(&v108->fields, 0);
            sub_854930(&v203, 0);
            sub_854710(&(*v105)->sisei->fields, 1u);
            sub_854930(&v203, 1u);
            sub_854710(&(*v105)->sisei->fields, 2u);
            sub_854930(&v203, 2u);
            sub_854930(&v203, 3u);
            sub_854710(&(*v105)->sisei->rot, 0);
            sub_854930(&v202, 0);
            sub_854710(&(*v105)->sisei->rot, 1u);
            sub_854930(&v202, 1u);
            sub_854710(&(*v105)->sisei->rot, 2u);
            sub_854930(&v202, 2u);
            sub_854710(&(*v105)->sisei->rot, 3u);
          }
          else
          {
            sub_854930(&v203, 0);
            sub_854930(&v203, 1u);
            sub_854930(&v203, 2u);
            sub_854930(&v203, 3u);
            sub_854930(&v202, 0);
            sub_854930(&v202, 1u);
            sub_854930(&v202, 2u);
          }
          sub_854930(&v202, 3u);
          v118 = (*v105)->_union;
          pPut = (*v105)->pPut;
          v126 = SetfldResPut(pHead, v118, pPut);
          switch (v126->Type)
          {
            case 0u:
              memset(&v199, 0, sizeof(v199));
              v128 = (*v105)->sisei;
              sub_F86A30(&v199, v128->pos.x, v128->pos.y, v128->pos.z, v128->pos.w, v128->rot.x, v128->rot.y, v128->rot.z, v128->rot.w, 0, v121, v122, v123, v124, v125, *&v128->scl.x, *&v128->scl.z);
              v130 = *v105;
              v131 = (*v105)->resourceID;
              v197 = v199;
              v132 = v130->resourceName;
              v196 = v199;
              dds3AddPointBasic(v131, &v196, v132);
              if (nResourceDataTable == ++v100)
                goto LABEL_271;
              continue;
            case 1u:
              memset(&v198, 0, sizeof(v198));
              v155 = (*v105)->sisei;
              sub_F86A30(&v198, v155->pos.x, v155->pos.y, v155->pos.z, v155->pos.w, v155->rot.x, v155->rot.y, v155->rot.z, v155->rot.w, 0, v121, v122, v123, v124, v125, *&v155->scl.x, *&v155->scl.z);
              v157 = *v105;
              v158 = (*v105)->resourceID;
              v197 = v198;
              v159 = v157->resourceName;
              v195 = v198;
              v161 = dds3AddPointBasic(v158, &v195, v159);
              v163 = *v105;
              fldEveHit_AddEveHit(v163, v161);
              if (nResourceDataTable == ++v100)
                goto LABEL_271;
              continue;
            case 2u:
              v133 = v126->_union;
              else if ((byte_3F59184 & 1) != 0)
              {
                goto LABEL_202;
              }
LABEL_202:
              v134 = Allocate(fldResPutNpc_t);
              fldResPutNpc_t___ctor(v134);
              {
              }
              v136 = ToUInt32(pHead, v133, 0);
              v134->id = v136;
              v138 = v136;
              pName = (*v105)->resourceName;
              v140 = fldCommand_GetHojiID(&pName);
              fieldID = fldGb->fieldID;
              if (fieldID == 60)
                goto LABEL_221;
              else if (fieldID == 61)
              {
                goto LABEL_221;
              }
              sub_854710(&v203, 0);
              v144 = v143;
              sub_854710(&v203, 1u);
              v146 = v145;
              sub_854710(&v203, 2u);
              v148 = *&v202.x;
              v149 = *&v202.z;
              EveIdx = v126->EveIdx;
              v152 = v151;
              *&v205.x = v148;
              *&v205.z = v149;
              fldNpcAdd(v138, v144, v146, v152, v205, v140, &pName, EveIdx);
LABEL_221:
              (*v105)->resourceName = pName;
              if (nResourceDataTable == ++v100)
                goto LABEL_271;
              continue;
            case 3u:
              v164 = v126->_union;
              else if ((byte_3F59185 & 1) != 0)
              {
                goto LABEL_240;
              }
LABEL_240:
              v165 = Allocate(fldResPutItemBox_t);
              fldResPutItemBox_t___ctor(v165);
              {
              }
              v165->id = ToUInt32(pHead, v164, 0);
              if (fldGb->fieldID != 20)
                goto LABEL_251;
              else if (fldGb->areaID != 17)
              {
                goto LABEL_251;
              }
              sub_854930(&v203, 1u);
LABEL_251:
              v168 = fldGb->fieldID;
              if (v168 == 60)
                goto LABEL_270;
              else if (v168 == 61)
              {
LABEL_270:
                if (nResourceDataTable == ++v100)
                  goto LABEL_271;
                continue;
              }
              id = v165->id;
              sub_854710(&v203, 0);
              v171 = v170;
              sub_854710(&v203, 1u);
              v173 = v172;
              sub_854710(&v203, 2u);
              v175 = *&v202.x;
              v176 = *&v202.z;
              v178 = v177;
              *&v206.x = v175;
              *&v206.z = v176;
              fldItemBoxAdd(id, v171, v173, v178, v206);
              if (nResourceDataTable != ++v100)
                continue;
LABEL_271:
              pTypeTable = v193;
              v11 = v194 + 1;
              if (v194 + 1 >= v192)
                return;
              goto LABEL_8;
            case 7u:
              v179 = v126->_union;
              v180 = SetfldResPutSE(pHead, v179);
              r = v180->r;
              v182 = v180->id;
              sub_854710(&v203, 0);
              v184 = v183;
              sub_854710(&v203, 1u);
              v186 = v185;
              sub_854710(&v203, 2u);
              v189 = v188;
              fldSe_Add(v182, r, v184, v186, v189);
              goto LABEL_270;
            default:
              goto LABEL_270;
          }
        }
      default:
        goto LABEL_271;
    }
    while (1)
    {
      v68 = v64[v63]->_union;
      else
      {
        v66 = SetfldResEvent(pHead, v68);
        if (v66)
        {
LABEL_92:
          aPtr = dds3AddEventBasic(v64[v63]->resourceID, v66->label, v64[v63]->resourceName);
          v71 = aPtr;
          v73 = v64[v63];
          fldEveHit_AddEveData(v73, v71);
        }
      }
      if (nResourceDataTable == ++v63)
        goto LABEL_271;
    }
  }
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
      v6 = &"FLD01";
    }
    else
    {
      v6 = &"FLD02";
    }
LABEL_58:
    ButtonGuideDispSet(*v6, 1, 1, 90);
LABEL_59:
    else
    {
      ButtonGuideDispOff();
    }
    return;
  }
  else if (fieldID == 11)
  {
    goto LABEL_54;
  }
  if (fieldID == 14)
    goto LABEL_54;
LABEL_23:
  if (!CheckTypeClose())
  {
    v9 = fldGb->fieldID;
    if (v9 >= 15)
    {
      if (v9 <= 99)
      {
        ButtonGuideDispSet("MAP02", 1, 1, 90);
      }
    }
    SetTypeClose(0);
    goto LABEL_59;
  }
  ButtonGuideDispSet("FLD02", 1, 1, 150);
}

// 0x1271ea0
void sdfAddressResolverReset(void *aDataBody, u32 aOffset, u8 aAddrInfoPtr, s32 aAddrInfoLeng) {
  ;
}
