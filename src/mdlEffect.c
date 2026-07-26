#include "types.h"

typedef struct ADUP_aDupFuncDelegate ADUP_aDupFuncDelegate;
typedef struct Eff_ModelTrackPolyParam_t Eff_ModelTrackPolyParam_t;
typedef struct Eff_ModelTrackPoly_tag Eff_ModelTrackPoly_tag;
typedef struct billHandle_t billHandle_t;
typedef struct dds3ModelEffectCtrlr_t dds3ModelEffectCtrlr_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct effHandle_t effHandle_t;
typedef struct mdlEffectResrcItem_t mdlEffectResrcItem_t;
typedef struct mdlEffectResrcList_t mdlEffectResrcList_t;
typedef struct mdlEffectResrc_IPU_t mdlEffectResrc_IPU_t;
typedef struct pibChunkItem_BLUR_t pibChunkItem_BLUR_t;
typedef struct pibChunkItem_P2A_D3P_t pibChunkItem_P2A_D3P_t;
typedef struct pibChunkItem_TRACK_t pibChunkItem_TRACK_t;
typedef struct pibChunkItem_t pibChunkItem_t;
typedef struct pibChunk_t pibChunk_t;
typedef struct pibHeaderChunk_t pibHeaderChunk_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfIpuInitParm_t sdfIpuInitParm_t;
typedef struct sdfModelExtraChunkMarkPos_t sdfModelExtraChunkMarkPos_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static u16 CX__;
static u16 CY__;
static u16 mdlPibDrawTrackInfo_curPos[4];
static u8 mdlPibDrawTrackInfo_tagAttr[4];
static char *mdlPibDrawTrackInfo_tagStr[4];
static s32 kag_ripple;

u32 Byte2UInt32(u8 **bytedata, s32 pos);
Eff_ModelTrackPoly_tag *Eff_ModelTrackPolyCreate(Eff_ModelTrackPolyParam_t *pParam);
void Eff_ModelTrackPolyDelete(Eff_ModelTrackPoly_tag **hMTPoly);
void Eff_ModelTrackPolyDraw(Eff_ModelTrackPoly_tag **hMTPoly);
bool IsModelDante(s32 id);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__LOADVECTOR_C(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR_A_C(void);
void billSetTexture(void **pTexture);
billHandle_t *dds3BillboardCopyO(void **hData, s32 bPos, bool tbldata);
billHandle_t *dds3BillboardCreate(s32 type, void *pTex, s32 bPos, char *callname);
void dds3BillboardDelete(void **hData);
void dds3BillboardDraw(void **hData);
void dds3BillboardDrawOff(void **hData);
void dds3BillboardSetPositionO(void **hData, sdfVector4_t pPos);
void dds3BillboardSetRGBAO(void **hData, u32 abgr);
void dds3BillboardSetScaleO(void **hData, f32 x, f32 y);
effHandle_t *dds3EffectCopy(void **pData, s32 bPos, bool tbldata);
void dds3EffectDelete(void **pData);
void dds3EffectDraw(void **pData);
void dds3EffectDrawOff(void **pData);
effHandle_t *dds3EffectLoad(void **pD3P, s32 bPos, bool tbldata);
void dds3EffectSetPosition(void **pData, sdfVector4_t pPos);
void dds3EffectSetRGBA(void **pData, u32 abgr);
void dds3EffectSetScale(void **pData, f32 scale);
void mdlCreateEffect(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 *bPos);
void mdlCreateEffect_BLUR(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 *bPos);
void mdlCreateEffect_P2A_D3P(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 aType, ADUP_aDupFuncDelegate *aDupFunc, s32 *bPos);
void mdlCreateEffect_TRACK(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 *bPos);
void mdlEffect_P2A_D3P_GetPos(sdfModelRootNode_t *model, dds3ModelEffectCtrlr_t *effect, sdfVector4_t *vect);
void mdlFreeEffect(dds3ModelEffectCtrlr_t *aCtrlr);
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle);
void *mdlPibGetChunk(dds3ModelHandle_t *handle, s32 group);
s32 mdlPibGetChunkCount(void *data, s32 bPos);
void *mdlPibGetFirstChunkItem(void *data);
void *mdlPibGetNextChunkItem(void *data);
void mdlSetBlur(dds3ModelHandle_t **aHandle, s32 interval, s32 count, u32 startColor, u32 endColor);
void pibChunkItem_BLUR_t__pCopy(pibChunkItem_BLUR_t *this, u8 **bytedata, s32 pos);
s32 pibChunkItem_P2A_D3P_t__GetSize(pibChunkItem_P2A_D3P_t *this);
void pibChunkItem_P2A_D3P_t__pCopy(pibChunkItem_P2A_D3P_t *this, u8 **bytedata, s32 pos);
void pibChunkItem_TRACK_t__pCopy(pibChunkItem_TRACK_t *this, u8 **bytedata, s32 pos);
void pibChunkItem_t__pCopy(pibChunkItem_t *this, u8 **bytedata, s32 pos);
s32 pibChunk_t__GetSize(pibChunk_t *this);
void pibChunk_t__pCopy(pibChunk_t *this, u8 **bytedata, s32 pos);
s32 pibHeaderChunk_t__GetSize(pibHeaderChunk_t *this);
void pibHeaderChunk_t__pCopy(pibHeaderChunk_t *this, u8 **bytedata, s32 pos);
s32 sdfModelMakeMarkPosUnity(sdfModelRootNode_t **aRoot, sdfModelExtraChunkMarkPos_t *aMark);
sdfModelExtraChunkMarkPos_t *sdfModelSearchMarkPosDataUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0xdfe960
void mdlCreateEffect(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 *bPos) {
    Byte2UInt32(0, 0);
    mdlCreateEffect_P2A_D3P(0, 0, 0, 0, 0, 0);
    mdlCreateEffect_TRACK(0, 0, 0, 0);
    mdlCreateEffect_BLUR(0, 0, 0, 0);
}

// 0xdfdbc0
dds3ModelEffectCtrlr_t *mdlCreateEffectCtrlr(dds3ModelHandle_t **aHandle, s32 aType, s32 aPlayGroup) {
  s16 v4;
  u16 v5;
  dds3ModelEffectCtrlr_t_o *v7;

  v4 = aPlayGroup;
  v5 = aType;
  v7 = Allocate(dds3ModelEffectCtrlr_t);
  dds3ModelEffectCtrlr_t___ctor(v7);
  v7->type = v5;
  v7->playGroup = v4;
  v7->next = (*aHandle)->effects;
  v7->work = NewSpecific(object, 6u);
  (*aHandle)->effects = v7;
  return v7;
}

// 0xdfd7c0
void mdlCreateEffectResrc_D3P(mdlEffectResrcList_t **listPtr, void *data, void **pTexture) {
  u64 *v6;
  Il2CppObject *pD3P;

  pD3P = data;
  v6 = Allocate(mdlEffectResrcItem_t);
  mdlEffectResrcItem_t___ctor(v6);
  _Add(
    (*listPtr)->items,
    v6);
  v6[2] = 1;
  if (pTexture)
  {
    billSetTexture(pTexture);
  }
  v6[3] = dds3EffectLoad(&pD3P, 0, 0, 0);
  v6[5] = pTexture;
  ++(*listPtr)->count;
}

// 0xdfd8d0
void mdlCreateEffectResrc_IPU(mdlEffectResrcList_t **listPtr, void *data, void *handle, s32 size, void **pTexture) {
  ;
}

// 0xdfd6a0
void mdlCreateEffectResrc_P2A(mdlEffectResrcList_t **listPtr, void *data, void **pTexture) {
  u64 *v7;

  v7 = Allocate(mdlEffectResrcItem_t);
  mdlEffectResrcItem_t___ctor(v7);
  _Add(
    (*listPtr)->items,
    v7);
  v7[2] = 0;
  if (pTexture)
  {
    billSetTexture(pTexture);
  }
  v7[3] = dds3BillboardCreate(1, data, 0, StringLiteral_416);
  v7[5] = pTexture;
  ++(*listPtr)->count;
}

// 0xdfe7d0
void mdlCreateEffect_BLUR(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 *bPos) {
    pibChunkItem_BLUR_t__pCopy(0, 0, 0);
    mdlSetBlur(0, 0, 0, 0, 0);
}

// 0xdfe940
void mdlCreateEffect_IPU(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup) {
  ;
}

// 0xdfde40
void mdlCreateEffect_P2A_D3P(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 aType, ADUP_aDupFuncDelegate *aDupFunc, s32 *bPos) {
    pibChunkItem_P2A_D3P_t__pCopy(0, 0, 0);
    pibChunkItem_P2A_D3P_t__GetSize(0);
    sdfModelSearchMarkPosDataUnity(0, 0);
    dds3BillboardCopyO(0, 0, 0);
    dds3EffectCopy(0, 0, 0);
}

// 0xdfe3a0
void mdlCreateEffect_TRACK(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 *bPos) {
    pibChunkItem_TRACK_t__pCopy(0, 0, 0);
    mdlGetMinorNum(0);
    IsModelDante(0);
    Eff_ModelTrackPolyCreate(0);
}

// 0xdfd8e0
void mdlDeleteEffectResrc_IPU(mdlEffectResrc_IPU_t *ipu) {
  ;
}

// 0xdfe950
void mdlDrawEffect_IPU(dds3ModelEffectCtrlr_t **effect) {
  ;
}

// 0xdfdd00
void *mdlEffectDup_D3P(mdlEffectResrcItem_t **efcResPtr) {
  Il2CppObject **p_handle;
  Il2CppObject *result;

  p_handle = &(*efcResPtr)->handle;
  result = dds3EffectCopy(p_handle, 0, 0);
  ++(*efcResPtr)->count;
  return result;
}

// 0xdfdc70
void *mdlEffectDup_P2A(mdlEffectResrcItem_t **efcResPtr) {
  Il2CppObject **p_handle;
  Il2CppObject *result;

  p_handle = &(*efcResPtr)->handle;
  result = dds3BillboardCopyO(p_handle, 0, 0);
  ++(*efcResPtr)->count;
  return result;
}

// 0xdfd960
void mdlEffectResrcListFree(mdlEffectResrcList_t *efcResList) {
    dds3EffectDelete(0);
    dds3BillboardDelete(0);
}

// 0xdfd900
mdlEffectResrcList_t *mdlEffectResrcListNew(s32 initCapa) {
  u64 *v2;

  v2 = Allocate(mdlEffectResrcList_t);
  mdlEffectResrcList_t___ctor(v2);
  return v2;
}

// 0xdfef90
void mdlEffect_P2A_D3P_GetPos(sdfModelRootNode_t *model, dds3ModelEffectCtrlr_t *effect, sdfVector4_t *vect) {
    sdfModelMakeMarkPosUnity(0, 0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR_C((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR_A_C();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
}

// 0xdfed10
void mdlFreeEffect(dds3ModelEffectCtrlr_t *aCtrlr) {
    Eff_ModelTrackPolyDelete(0);
    dds3EffectDelete(0);
    dds3BillboardDelete(0);
}

// 0xdfec00
bool mdlGenEffect(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aPlayGroup) {
  dds3ModelHandle_t_o *v7;
  Il2CppObject *Chunk;
  Il2CppObject *effectData;
  s32 bPos;

  bPos = 16;
  v7 = *aHandle;
  Chunk = mdlPibGetChunk(v7, aGroup, &bPos);
  if (Chunk)
  {
    effectData = (*aHandle)->resrc->effectData;
    if (mdlPibGetFirstChunkItem(effectData, &bPos))
    {
      do
      {
        mdlCreateEffect(aHandle, effectData, aPlayGroup, &bPos);
      }
      while (mdlPibGetNextChunkItem(effectData, &bPos));
    }
    LOBYTE(Chunk) = 1;
  }
  return Chunk;
}

// 0xdfdd90
mdlEffectResrcItem_t *mdlGetEffectResrc(dds3ModelHandle_t *handle, s32 effectIndex) {
  struct mdlEffectResrcList_t_o *effectResrcList;

  effectResrcList = handle->resrc->effectResrcList;
  if (!effectResrcList)
    return 0;
  if (effectResrcList->count <= effectIndex)
    return 0;
  return _get_Item(
           effectResrcList->items,
           effectIndex);
}

// 0xdffb00
void mdlHideEffect(dds3ModelHandle_t **HNDL) {
  if (*HNDL)
    (*HNDL)->stat |= 2u;
}

// 0xdff220
void mdlLinkEffect(dds3ModelHandle_t **aHandle, dds3ModelEffectCtrlr_t **aEffect, void *modelobj) {
    mdlEffect_P2A_D3P_GetPos(0, 0, 0);
    dds3BillboardSetPositionO(0, (sdfVector4_t){0});
    dds3BillboardDraw(0);
    dds3EffectSetPosition(0, (sdfVector4_t){0});
    dds3EffectDraw(0);
    Eff_ModelTrackPolyDraw(0);
}

// 0xdffa20
void mdlLinkEffectOff(dds3ModelHandle_t **aHandle, dds3ModelEffectCtrlr_t **aEffect, void *modelobj) {
  dds3ModelEffectCtrlr_t_o *v5;
  Il2CppObject *hData;

  hData = 0;
  v5 = *aEffect;
  if ((*aEffect)->type == 1)
  {
    hData = v5->handle;
    dds3EffectDrawOff(&hData);
  }
  else if (!(*aEffect)->type)
  {
    hData = v5->handle;
    dds3BillboardDrawOff(&hData);
  }
}

// 0xdfd300
s32 mdlPibCheckItemType(void *data, s32 type, s32 bPos) {
    pibChunkItem_t__pCopy(0, 0, 0);
    return 0;
}

// 0xdfd670
void mdlPibDrawEffectInfo(sdfDrawTag_t *tag, s32 x, s32 y, u32 z, s32 attr, void *data) {
  ;
}

// 0xdfd680
void mdlPibDrawTrackInfo(sdfDrawTag_t *tag, s32 x, s32 y, u32 z, void *data, s32 cursor) {
  ;
}

// 0xdfd690
void mdlPibEditTrackInfo(void *data, s16 *cursor_p) {
  ;
}

// 0xdfcbb0
void *mdlPibGetChunk(dds3ModelHandle_t *handle, s32 group, s32 *bPos) {
    mdlPibGetChunkCount(0, 0);
    pibHeaderChunk_t__GetSize(0);
    pibChunk_t__pCopy(0, 0, 0);
    return 0;
}

// 0xdfca90
s32 mdlPibGetChunkCount(void *data, s32 bPos) {
    pibHeaderChunk_t__pCopy(0, 0, 0);
    return 0;
}

// 0xdfd160
s32 mdlPibGetChunkItemCount(void *data, s32 *bPos) {
    pibChunk_t__pCopy(0, 0, 0);
    mdlPibGetFirstChunkItem(0);
    mdlPibGetNextChunkItem(0);
    return 0;
}

// 0xdfd430
s32 mdlPibGetEffectCount(void *data, s32 bPos) {
    pibHeaderChunk_t__pCopy(0, 0, 0);
    return 0;
}

// 0xdfcd90
pibChunkItem_t *mdlPibGetFirstChunkItem(void *data, s32 *bPos) {
    pibChunk_t__pCopy(0, 0, 0);
    pibChunk_t__GetSize(0);
    pibChunkItem_t__pCopy(0, 0, 0);
    return 0;
}

// 0xdfd550
s32 mdlPibGetMotionCount(void *data, s32 bPos) {
    pibHeaderChunk_t__pCopy(0, 0, 0);
    return 0;
}

// 0xdfcf90
pibChunkItem_t *mdlPibGetNextChunkItem(void *data, s32 *bPos) {
    pibChunkItem_t__pCopy(0, 0, 0);
    return 0;
}

// 0xdfc970
s32 mdlPibGetVersion(void *data, s32 *bPos) {
    pibHeaderChunk_t__pCopy(0, 0, 0);
    return 0;
}

// 0xdff860
void mdlSetEffectColorSub(dds3ModelHandle_t **aHandle, dds3ModelEffectCtrlr_t **aEffect, u32 aColor) {
  dds3ModelEffectCtrlr_t_o *v6;
  Il2CppObject **v7;
  Il2CppObject **p_handle;

  v6 = *aEffect;
  if ((*aEffect)->type == 1)
  {
    p_handle = &v6->handle;
    dds3EffectSetRGBA(p_handle, aColor);
  }
  else if (!(*aEffect)->type)
  {
    v7 = &v6->handle;
    dds3BillboardSetRGBAO(v7, aColor);
  }
}

// 0xdff940
void mdlSetEffectScaleSub(dds3ModelHandle_t **aHandle, dds3ModelEffectCtrlr_t **aEffect, f32 aScale) {
  dds3ModelEffectCtrlr_t_o *v6;
  s32 type;
  Il2CppObject *hData;

  v6 = *aEffect;
  hData = (*aEffect)->handle;
  type = v6->type;
  if (type == 1)
  {
    dds3EffectSetScale(&hData, aScale);
  }
  else if (!type)
  {
    dds3BillboardSetScaleO(&hData, aScale, aScale);
  }
}

// 0xdffb20
void mdlShowEffect(dds3ModelHandle_t **HNDL) {
  if (*HNDL)
    (*HNDL)->stat &= ~2u;
}

// 0xdfd8f0
void mdlStartEffectResrc_IPU(mdlEffectResrc_IPU_t **ipu, sdfTexHandle_t *tex, sdfIpuInitParm_t *parm) {
  ;
}

// 0xdfeef0
void mdlStopEffect(dds3ModelHandle_t **aHandle, s32 aPlayGroup) {
  struct dds3ModelEffectCtrlr_t_o *effects;
  struct dds3ModelEffectCtrlr_t_o *next;

  if (*aHandle)
  {
    effects = (*aHandle)->effects;
    if (effects)
    {
      do
      {
        next = effects->next;
        if (effects->playGroup == aPlayGroup)
        {
          mdlFreeEffect(effects, *&aPlayGroup);
        }
        effects = next;
      }
      while (next);
    }
  }
}
