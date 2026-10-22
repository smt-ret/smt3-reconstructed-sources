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
  s32 v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  s32 v15;
  u64 *v17;
  ADUP_aDupFuncDelegate_o *v19;
  dds3ModelHandle_t_o **v21;
  Il2CppObject *v22;
  s32 v23;
  s32 v24;
  u64 *v25;
  u64 v27[3];

  v9 = *bPos;
  if (!aData)
    goto LABEL_12;
LABEL_6:
  Interface = QueryInterface(aData, byte);
  if (!Interface)
  {
    sub_8FC2C0(aData->klass->_1.element_class, v10, v27);
    if ((v27[0] & 1) != 0)
      v12 = v27[2];
    else
      v12 = v27 + 1;
    v13 = sub_8C4940(v12);
  }
LABEL_13:
  switch (Byte2UInt32(Interface, v9))
  {
    case 1u:
      v17 = Allocate(ADUP_aDupFuncDelegate);
      _ctor(v17, 0, Method_mdlEffect_mdlEffectDup_P2A__, 0);
      v21 = aHandle;
      v22 = aData;
      v23 = aPlayGroup;
      v24 = 0;
      goto LABEL_22;
    case 2u:
      v25 = Allocate(ADUP_aDupFuncDelegate);
      _ctor(v25, 0, Method_mdlEffect_mdlEffectDup_D3P__, 0);
      v21 = aHandle;
      v22 = aData;
      v23 = aPlayGroup;
      v24 = 1;
LABEL_22:
      mdlCreateEffect_P2A_D3P(v21, v22, v23, v24, v19, bPos);
      break;
    case 3u:
      mdlCreateEffect_TRACK(aHandle, aData, aPlayGroup, bPos);
      break;
    case 4u:
      mdlCreateEffect_BLUR(aHandle, aData, v15, bPos);
      break;
    case 5u:
      break;
    default:
      return;
  }
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
  v7[3] = dds3BillboardCreate(1, data, 0, "");
  v7[5] = pTexture;
  ++(*listPtr)->count;
}

// 0xdfe7d0
void mdlCreateEffect_BLUR(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 *bPos) {
  pibChunkItem_BLUR_t_o *v8;
  s32 v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  s32 interval;
  s32 count;
  u32 endColor;
  u32 startColor;
  u64 v19[3];

  v8 = Allocate(pibChunkItem_BLUR_t);
  pibChunkItem_BLUR_t___ctor(v8);
  v9 = *bPos;
  if (aData)
  {
    Interface = QueryInterface(aData, byte);
    if (!Interface)
    {
      sub_8FC2C0(aData->klass->_1.element_class, v10, v19);
      if ((v19[0] & 1) != 0)
        v12 = v19[2];
      else
        v12 = v19 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  pibChunkItem_BLUR_t__pCopy(v8, Interface, v9);
  interval = v8->interval;
  count = v8->count;
  startColor = v8->startColor;
  endColor = v8->endColor;
  mdlSetBlur(aHandle, interval, count, startColor, endColor);
}

// 0xdfe940
void mdlCreateEffect_IPU(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup) {
  ;
}

// 0xdfde40
void mdlCreateEffect_P2A_D3P(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 aType, ADUP_aDupFuncDelegate *aDupFunc, s32 *bPos) {
  u64 *v11;
  s32 v12;
  Il2CppClass *v13;
  s64 *Interface;
  char *v15;
  s64 *v16;
  s32 v18;
  s32 v19;
  dds3ModelHandle_t_o *v20;
  s32 v21;
  struct mdlEffectResrcList_t_o *effectResrcList;
  System_WeakReference_o *Item;
  s64 v24;
  System_WeakReference_o *v25;
  s32 v27;
  s32 v28;
  sdfModelRootNode_t_o *modelRoot;
  sdfModelExtraChunkMarkPos_t_o *v35;
  s64 *v36;
  dds3ModelEffectCtrlr_t_o *v37;
  s16 v38;
  Il2CppObject *v39;
  struct System_Object_array *work;
  struct System_Object_array *v41;
  struct System_Object_array *v43;
  s64 *v44;
  s64 *v45;
  u64 v47[3];
  u32 index;
  s32 v49;

  v49 = aPlayGroup;
  v11 = Allocate(pibChunkItem_P2A_D3P_t);
  pibChunkItem_P2A_D3P_t___ctor(v11);
  v12 = *bPos;
  if (aData)
  {
    Interface = QueryInterface(aData, byte);
    if (!Interface)
    {
      sub_8FC2C0(aData->klass->_1.element_class, v13, v47);
      if ((v47[0] & 1) != 0)
        v15 = v47[2];
      else
        v15 = v47 + 1;
      v16 = sub_8C4940(v15);
    }
  }
  else
  {
    Interface = 0;
  }
  pibChunkItem_P2A_D3P_t__pCopy(v11, Interface, v12);
  v18 = *(v11 + 14);
  v19 = *(v11 + 6);
  v20 = *aHandle;
  v21 = *(v11 + 15);
LABEL_14:
  effectResrcList = v20->resrc->effectResrcList;
  if (effectResrcList)
  {
    if (effectResrcList->count > v21)
    {
      Item = _get_Item(
               effectResrcList->items,
               v21);
      if (Item)
      {
        v24 = *(v11 + 5);
        v25 = Item;
        if (v24 <= pibChunkItem_P2A_D3P_t__GetSize(v11) - 4)
          v27 = 0;
        else
          v27 = *(v11 + 8);
        index = 21701;
        v28 = -v18;
        while (1)
        {
          modelRoot = (*aHandle)->modelRoot;
          v35 = sdfModelSearchMarkPosDataUnity(modelRoot, v19);
          if (!v35)
            goto LABEL_68;
          v36 = v35;
            break;
          if ((byte_3F583BE & 1) == 0)
            goto LABEL_40;
LABEL_41:
          v37 = Allocate(dds3ModelEffectCtrlr_t);
          dds3ModelEffectCtrlr_t___ctor(v37);
          v38 = v49;
          v37->type = aType;
          v37->playGroup = v38;
          v37->next = (*aHandle)->effects;
          v37->work = NewSpecific(object, 6u);
          (*aHandle)->effects = v37;
          if (!aType)
          {
            else if ((byte_3F583BF & 1) == 0)
            {
LABEL_53:
            }
            v39 = dds3BillboardCopyO(&v25[1], 0, 0);
            goto LABEL_58;
          }
          if ((byte_3F583C0 & 1) == 0)
            goto LABEL_45;
LABEL_46:
          v39 = dds3EffectCopy(&v25[1], 0, 0);
LABEL_58:
          ++v25->gcHandle.handle;
          v37->handle = v39;
          work = v37->work;
          v37->pTexture = v25[1].fields;
          work->m_Items[0] = v25;
          v41 = v37->work;
          v41->m_Items[1] = v36;
          v43 = v37->work;
          LODWORD(v47[0]) = v27;
          v44 = sub_8D3950(f32, v47);
          v45 = v44;
          v43->m_Items[2] = v45;
          v37->mark_id = v19;
LABEL_68:
          ++v19;
          if (!++v28)
            return;
        }
        if ((byte_3F583BE & 1) != 0)
          goto LABEL_41;
LABEL_40:
        goto LABEL_41;
      }
    }
  }
}

// 0xdfe3a0
void mdlCreateEffect_TRACK(dds3ModelHandle_t **aHandle, void *aData, s32 aPlayGroup, s32 *bPos) {
  s16 v6;
  pibChunkItem_TRACK_t_o *v9;
  Eff_ModelTrackPolyParam_t_o *v10;
  s32 v11;
  Il2CppClass *v12;
  s64 *Interface;
  char *v14;
  s64 *v15;
  u32 v17;
  struct System_UInt32_array *mark;
  struct System_UInt32_array *v19;
  u32 v20;
  struct System_UInt32_array *v21;
  struct System_UInt32_array *v22;
  u32 v24;
  f32 v26;
  s32 MinorNum;
  s32 v29;
  struct System_UInt32_array *colors;
  struct System_UInt32_array *v32;
  struct System_UInt32_array *v34;
  struct System_UInt32_array *v36;
  dds3ModelEffectCtrlr_t_o *v38;
  Eff_ModelTrackPoly_tag_o *v40;
  struct System_Object_array *work;
  u64 v46[3];

  v6 = aPlayGroup;
  v9 = Allocate(pibChunkItem_TRACK_t);
  pibChunkItem_TRACK_t___ctor(v9);
  v10 = Allocate(Eff_ModelTrackPolyParam_t);
  Eff_ModelTrackPolyParam_t___ctor(v10);
  v11 = *bPos;
  if (aData)
  {
    Interface = QueryInterface(aData, byte);
    if (!Interface)
    {
      sub_8FC2C0(aData->klass->_1.element_class, v12, v46);
      if ((v46[0] & 1) != 0)
        v14 = v46[2];
      else
        v14 = v46 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  else
  {
    Interface = 0;
  }
  pibChunkItem_TRACK_t__pCopy(v9, Interface, v11);
  v10->hModel = *aHandle;
  mark = v9->mark;
  v19 = v10->mark;
  v20 = mark->m_Items[0];
  v19->m_Items[0] = v20;
  v21 = v9->mark;
  v22 = v10->mark;
  v24 = v21->m_Items[1];
  v22->m_Items[1] = v24;
  LOWORD(v17) = v9->startFrame;
  v26 = v17;
  v10->frame_s = v26;
  LOWORD(v26) = v9->endFrame;
  v10->frame_e = LODWORD(v26);
  v10->record = v9->interval;
  v10->face = v9->face;
  MinorNum = mdlGetMinorNum(aHandle);
  if (IsModelDante(MinorNum))
    v29 = 4;
  else
    v29 = 3;
  v10->split = v29;
  v10->blend = v9->blendAlgo;
  colors = v9->colors;
  v10->abgr->s0 = colors->m_Items[0];
  v32 = v9->colors;
  v10->abgr->s1 = v32->m_Items[1];
  v34 = v9->colors;
  v10->abgr->e0 = v34->m_Items[2];
  v36 = v9->colors;
  v10->abgr->e1 = v36->m_Items[3];
LABEL_34:
  v38 = Allocate(dds3ModelEffectCtrlr_t);
  dds3ModelEffectCtrlr_t___ctor(v38);
  v38->type = 2;
  v38->playGroup = v6;
  v38->next = (*aHandle)->effects;
  v38->work = NewSpecific(object, 6u);
  (*aHandle)->effects = v38;
  v40 = Eff_ModelTrackPolyCreate(v10);
  work = v38->work;
  v38->handle = v40;
  work->m_Items[0] = v9;
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
  s32 i;
  System_WeakReference_o *Item;
  s32 v6;
  System_WeakReference_o *v7;
  System_WeakReference_Fields fields;
  System_WeakReference_c *klass;
  u64 *image;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  u64 v14;
  u64 v15;
  u64 v17[3];

  if (efcResList && efcResList->count >= 1)
  {
    for (i = 0; i < efcResList->count; ++i)
    {
      Item = _get_Item(
               efcResList->items,
               i);
      v6 = *&Item->isLongReference;
      v7 = Item;
      switch (v6)
      {
        case 3:
          klass = Item[1].klass;
          else if (!klass)
          {
            break;
          }
          image = klass->_1.image;
          if (*(klass->_1.image + 288) < typeHierarchyDepth
            || *(image[25] + 8 * typeHierarchyDepth - 8) != mdlEffectResrc_IPU_t)
          {
            sub_8FC2C0(image[8], mdlEffectResrc_IPU_t, v17);
            if ((v17[0] & 1) != 0)
              v12 = v17[2];
            else
              v12 = v17 + 1;
            v13 = sub_8C4940(v12);
          }
          break;
        case 1:
          dds3EffectDelete(&v7[1]);
          break;
        case 0:
          dds3BillboardDelete(&v7[1]);
          fields = v7[1].fields;
          if (!*&fields)
            goto LABEL_35;
LABEL_30:
          v14 = *(*&fields + 24LL);
          if (v14 >= 1)
          {
            v15 = 0;
            do
            {
              v14 = *&fields + 8 * v15++;
              *(v14 + 32) = 0;
              fields = v7[1].fields;
              LODWORD(v14) = *(*&fields + 24LL);
            }
            while (v15 < v14);
          }
          goto LABEL_35;
      }
      fields = v7[1].fields;
      if (fields)
        goto LABEL_30;
LABEL_35:
      v7[1].fields = 0;
    }
  }
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
  dds3ModelEffectCtrlr_t_o *v5;
  struct System_Object_array *work;
  sdfModelExtraChunkMarkPos_t_o *v7;
  sdfModelExtraChunkMarkPos_t_c *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  struct System_Object_array *v13;
  s64 v15;
  Il2CppClass *v18;
  f32 *v19;
  char *v20;
  s64 *v21;
  u64 v22[2];
  char *v23;
  sdfModelRootNode_t_o *aRoot;

  v5 = effect;
  aRoot = model;
  if ((byte_3F5839F & 1) == 0)
  {
    work = v5->work;
    if (LODWORD(work->max_length) > 1)
      goto LABEL_3;
LABEL_6:
  }
  work = effect->work;
  if (LODWORD(work->max_length) <= 1)
    goto LABEL_6;
LABEL_3:
  v7 = work->m_Items[1];
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfModelExtraChunkMarkPos_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfModelExtraChunkMarkPos_t, v22);
      if ((v22[0] & 1) != 0)
        v11 = v23;
      else
        v11 = v22 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  if (sdfModelMakeMarkPosUnity(&aRoot, v7))
  {
    v13 = v5->work;
    v15 = v13->m_Items[2];
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR_C(dds3CameraEyePos);
    SDF_VU0__SUBVECTOR_A_C();
    SDF_VU0__NORMALIZE();
    if (!v15)
      sub_8C38A0();
    v18 = *(*v15 + 64LL);
    {
      sub_8FC2C0(v18, f32, v22);
      if ((v22[0] & 1) != 0)
        v20 = v23;
      else
        v20 = v22 + 1;
      v21 = sub_8C4940(v20);
    }
    v19 = sub_8D3F90(v15);
    SDF_VU0__SCALEVECTOR(*v19);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(vect);
  }
}

// 0xdfed10
void mdlFreeEffect(dds3ModelEffectCtrlr_t *aCtrlr) {
  s32 type;
  struct System_Object_array *work;
  Il2CppObject *handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppObject *v11;
  u64 v12[3];

  v11 = 0;
  type = aCtrlr->type;
  if (type == 2)
  {
    handle = aCtrlr->handle;
    if (handle)
    {
      klass = handle->klass;
      if (handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != Eff_ModelTrackPoly_tag)
      {
        sub_8FC2C0(klass->_1.element_class, Eff_ModelTrackPoly_tag, v12);
        if ((v12[0] & 1) != 0)
          v8 = v12[2];
        else
          v8 = v12 + 1;
        v9 = sub_8C4940(v8);
      }
    }
    v11 = aCtrlr->handle;
    Eff_ModelTrackPolyDelete(&v11);
    work = aCtrlr->work;
    if (LODWORD(work->max_length))
      goto LABEL_28;
    goto LABEL_27;
  }
  if (type == 1)
  {
    dds3EffectDelete(&aCtrlr->handle);
    work = aCtrlr->work;
    if (LODWORD(work->max_length))
      goto LABEL_28;
LABEL_27:
  }
  if (aCtrlr->type)
    return;
  dds3BillboardDelete(&aCtrlr->handle);
  work = aCtrlr->work;
  if (!LODWORD(work->max_length))
    goto LABEL_27;
LABEL_28:
  work->m_Items[0] = 0;
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
  s32 effpos_type;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v13;
  UnityEngine_Transform_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Transform_o *v17;
  UnityEngine_Transform_o *v18;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *v21;
  UnityEngine_Component_o *v22;
  UnityEngine_GameObject_o *v23;
  UnityEngine_Transform_o *v24;
  UnityEngine_Transform_o *v25;
  UnityEngine_Transform_o *v26;
  f32 v27;
  UnityEngine_Transform_o *v28;
  UnityEngine_Component_o *v29;
  UnityEngine_Object_o *v31;
  UnityEngine_Transform_o *v32;
  UnityEngine_Transform_o *v33;
  f32 x;
  f32 y;
  dds3ModelEffectCtrlr_t_o *v36;
  struct sdfModelRootNode_t_o *modelRoot;
  f32 v39;
  f32 v40;
  f32 w;
  f32 v42;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  UnityEngine_Object_o *v49;
  System_String_o *name;
  Il2CppObject *handle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v58;
  s64 *v59;
  f32 z;
  Il2CppObject *v61;
  UnityEngine_Vector4_o vect;
  Il2CppObject *v63[3];
  Il2CppObject *hData;
  UnityEngine_Vector4_o v65;
  UnityEngine_Vector4_o v66;

  hData = 0;
  v61 = 0;
  *&vect.x = 0;
  *&vect.z = 0;
  if (op_Inequality(modelobj, 0, 0))
  {
    effpos_type = (*aHandle)->modelRoot->effpos_type;
    transform = get_transform(modelobj, 0);
    Child = GetChild(transform, 0);
    gameObject = get_gameObject(Child);
    v13 = get_transform(modelobj, 0);
    v15 = GetChild(v13, 0);
    if (op_Inequality(gameObject, 0, 0))
    {
      if (effpos_type)
      {
        v16 = get_transform(modelobj, 0);
        vect.x = get_position(v16).x * 100.0;
        v17 = get_transform(modelobj, 0);
        vect.y = get_position(v17).y * -100.0;
        v18 = get_transform(modelobj, 0);
        vect.z = COERCE_FLOAT(LODWORD(get_position(v18).z)) * 100.0;
        Component_object = GetComponent_object_(gameObject);
        if (op_Inequality(Component_object, 0, 0))
        {
          v21 = get_transform(gameObject, 0);
          v22 = GetChild(v21, 0);
          v23 = get_gameObject(v22);
          v24 = get_transform(v23, 0);
          vect.x = get_position(v24).x * 100.0;
          v25 = get_transform(v23, 0);
          vect.y = get_position(v25).y * -100.0;
          v26 = get_transform(v23, 0);
          v27 = COERCE_FLOAT(LODWORD(get_position(v26).z)) * 100.0;
LABEL_22:
          vect.z = v27;
        }
      }
      else
      {
        v28 = get_transform(gameObject, 0);
        v29 = GetChild(v28, 0);
        v31 = get_gameObject(v29);
        if (op_Inequality(v31, 0, 0))
        {
          v32 = get_transform(gameObject, 0);
          v33 = GetChild(v32, 0);
          x = get_localPosition(v15).x;
          vect.x = (x + get_localPosition(v33).x) * 100.0;
          y = get_localPosition(v15).y;
          vect.y = (y + get_localPosition(v33).y) * -100.0;
          z = get_localPosition(v15).z;
          v27 = (z + COERCE_FLOAT(LODWORD(get_localPosition(v33).z))) * 100.0;
          goto LABEL_22;
        }
      }
    }
  }
  v36 = *aEffect;
  modelRoot = (*aHandle)->modelRoot;
  switch ((*aEffect)->type)
  {
    case 0u:
      mdlEffect_P2A_D3P_GetPos(modelRoot, v36, &vect);
      hData = (*aEffect)->handle;
      v40 = vect.x;
      v39 = vect.y;
      v42 = vect.z;
      w = vect.w;
      v65.x = v40;
      v65.y = v39;
      v65.z = v42;
      v65.w = w;
      dds3BillboardSetPositionO(&hData, v65);
      dds3BillboardDraw(&hData);
      break;
    case 1u:
      mdlEffect_P2A_D3P_GetPos(modelRoot, v36, &vect);
      hData = (*aEffect)->handle;
      v45 = vect.x;
      v44 = vect.y;
      v47 = vect.z;
      v46 = vect.w;
      v66.x = v45;
      v66.y = v44;
      v66.z = v47;
      v66.w = v46;
      dds3EffectSetPosition(&hData, v66);
      v49 = modelRoot->modelobj;
      if (op_Inequality(v49, 0, 0))
      {
        name = get_name(modelRoot->modelobj);
        if (Contains(name, "devil_0x108", 0))
        {
          kag_ripple = 1;
        }
      }
      dds3EffectDraw(&hData);
      kag_ripple = 0;
      break;
    case 2u:
      handle = v36->handle;
      if (handle)
      {
        klass = handle->klass;
        if (handle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != Eff_ModelTrackPoly_tag)
        {
          sub_8FC2C0(klass->_1.element_class, Eff_ModelTrackPoly_tag, v63);
          if ((v63[0] & 1) != 0)
            v58 = v63[2];
          else
            v58 = v63 + 1;
          v59 = sub_8C4940(v58);
        }
      }
      v61 = v36->handle;
      Eff_ModelTrackPolyDraw(&v61);
      break;
    case 3u:
      break;
    default:
      return;
  }
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
  pibChunkItem_t_o *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  u64 v13[3];

  v7 = Allocate(pibChunkItem_t);
  pibChunkItem_t___ctor(v7);
  if (data)
  {
    Interface = QueryInterface(data, byte);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v8, v13);
      if ((v13[0] & 1) != 0)
        v10 = v13[2];
      else
        v10 = v13 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  pibChunkItem_t__pCopy(v7, Interface, bPos);
  return v7->type == type;
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
  Il2CppObject *effectData;
  s32 v8;
  s32 ChunkCount;
  u64 *v10;
  s32 v11;
  s32 i;
  pibChunk_t_o *v13;
  Il2CppClass *v14;
  s32 v15;
  s64 *Interface;
  char *v17;
  s64 *v18;
  u64 v20[3];

  effectData = handle->resrc->effectData;
  if (effectData)
  {
    v8 = *bPos;
    ChunkCount = mdlPibGetChunkCount(effectData, v8, bPos);
    v10 = Allocate(pibHeaderChunk_t);
    pibHeaderChunk_t___ctor(v10);
    v11 = *bPos;
    for (i = pibHeaderChunk_t__GetSize(v10) + v11; ; i = v13->size + *bPos)
    {
      *bPos = i;
      v13 = Allocate(pibChunk_t);
      pibChunk_t___ctor(v13);
      v15 = *bPos;
      Interface = QueryInterface(effectData, byte);
      if (!Interface)
      {
        sub_8FC2C0(effectData->klass->_1.element_class, v14, v20);
        if ((v20[0] & 1) != 0)
          v17 = v20[2];
        else
          v17 = v20 + 1;
        v18 = sub_8C4940(v17);
      }
      pibChunk_t__pCopy(v13, Interface, v15);
      if (!ChunkCount)
        break;
      if (v13->group == group)
        return v13;
      --ChunkCount;
    }
  }
  return 0;
}

// 0xdfca90
s32 mdlPibGetChunkCount(void *data, s32 bPos) {
  pibHeaderChunk_t_o *v5;
  Il2CppClass *v6;
  s64 *Interface;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = Allocate(pibHeaderChunk_t);
  pibHeaderChunk_t___ctor(v5);
  if (data)
  {
    Interface = QueryInterface(data, byte);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v6, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    Interface = 0;
  }
  pibHeaderChunk_t__pCopy(v5, Interface, bPos);
  return v5->chunkCount;
}

// 0xdfd160
s32 mdlPibGetChunkItemCount(void *data, s32 *bPos) {
  u64 *v5;
  s32 v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 v17[3];

  v5 = Allocate(pibChunk_t);
  pibChunk_t___ctor(v5);
  v6 = *bPos;
  if (data)
  {
    Interface = QueryInterface(data, byte);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v7, v17);
      if ((v17[0] & 1) != 0)
        v9 = v17[2];
      else
        v9 = v17 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  pibChunk_t__pCopy(v5, Interface, v6);
  if (v5)
  {
    LODWORD(v5) = 0;
    if (mdlPibGetFirstChunkItem(data, bPos))
    {
      do
      {
        while (1)
        {
          LODWORD(v5) = v5 + 1;
            break;
          if (!mdlPibGetNextChunkItem(data, bPos))
            return v5;
        }
      }
      while (mdlPibGetNextChunkItem(data, bPos));
    }
  }
  return v5;
}

// 0xdfd430
s32 mdlPibGetEffectCount(void *data, s32 bPos) {
  pibHeaderChunk_t_o *v5;
  Il2CppClass *v6;
  s64 *Interface;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = Allocate(pibHeaderChunk_t);
  pibHeaderChunk_t___ctor(v5);
  if (data)
  {
    Interface = QueryInterface(data, byte);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v6, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    Interface = 0;
  }
  pibHeaderChunk_t__pCopy(v5, Interface, bPos);
  return v5->effectCount;
}

// 0xdfcd90
pibChunkItem_t *mdlPibGetFirstChunkItem(void *data, s32 *bPos) {
  u64 *v5;
  s32 v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  s32 v11;
  pibChunkItem_t_o *v12;
  s32 v13;
  Il2CppClass *v14;
  s64 *v15;
  char *v16;
  s64 *v17;
  u64 v19[2];
  char *v20;

  v5 = Allocate(pibChunk_t);
  pibChunk_t___ctor(v5);
  v6 = *bPos;
  if (data)
  {
    Interface = QueryInterface(data, byte);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v7, v19);
      if ((v19[0] & 1) != 0)
        v9 = v20;
      else
        v9 = v19 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  pibChunk_t__pCopy(v5, Interface, v6);
  v11 = *bPos;
  *bPos = pibChunk_t__GetSize(v5) + v11;
  v12 = Allocate(pibChunkItem_t);
  pibChunkItem_t___ctor(v12);
  v13 = *bPos;
  if (data)
  {
    v15 = QueryInterface(data, byte);
    if (!v15)
    {
      sub_8FC2C0(data->klass->_1.element_class, v14, v19);
      if ((v19[0] & 1) != 0)
        v16 = v20;
      else
        v16 = v19 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  else
  {
    v15 = 0;
  }
  pibChunkItem_t__pCopy(v12, v15, v13);
  if (v12->type == 0xFFFF)
    return 0;
  else
    return v12;
}

// 0xdfd550
s32 mdlPibGetMotionCount(void *data, s32 bPos) {
  pibHeaderChunk_t_o *v5;
  Il2CppClass *v6;
  s64 *Interface;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = Allocate(pibHeaderChunk_t);
  pibHeaderChunk_t___ctor(v5);
  if (data)
  {
    Interface = QueryInterface(data, byte);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v6, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    Interface = 0;
  }
  pibHeaderChunk_t__pCopy(v5, Interface, bPos);
  return v5->motionCount;
}

// 0xdfcf90
pibChunkItem_t *mdlPibGetNextChunkItem(void *data, s32 *bPos) {
  s32 v5;
  pibChunkItem_t_o *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  s32 v11;
  Il2CppClass *v12;
  s64 *v13;
  char *v14;
  s64 *v15;
  u64 v17[2];
  char *v18;

  v5 = *bPos;
  v6 = Allocate(pibChunkItem_t);
  pibChunkItem_t___ctor(v6);
  if (data)
  {
    Interface = QueryInterface(data, byte);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v7, v17);
      if ((v17[0] & 1) != 0)
        v9 = v18;
      else
        v9 = v17 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  pibChunkItem_t__pCopy(v6, Interface, v5);
  v11 = v6->size + *bPos;
  *bPos = v11;
  if (data)
  {
    v13 = QueryInterface(data, byte);
    if (!v13)
    {
      sub_8FC2C0(data->klass->_1.element_class, v12, v17);
      if ((v17[0] & 1) != 0)
        v14 = v18;
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  else
  {
    v13 = 0;
  }
  pibChunkItem_t__pCopy(v6, v13, v11);
  if (v6->type == 0xFFFF)
    return 0;
  else
    return v6;
}

// 0xdfc970
s32 mdlPibGetVersion(void *data, s32 *bPos) {
  pibHeaderChunk_t_o *v5;
  s32 v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  u64 v12[3];

  v5 = Allocate(pibHeaderChunk_t);
  pibHeaderChunk_t___ctor(v5);
  v6 = *bPos;
  if (data)
  {
    Interface = QueryInterface(data, byte);
    if (!Interface)
    {
      sub_8FC2C0(data->klass->_1.element_class, v7, v12);
      if ((v12[0] & 1) != 0)
        v9 = v12[2];
      else
        v9 = v12 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  pibHeaderChunk_t__pCopy(v5, Interface, v6);
  return v5->version;
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
