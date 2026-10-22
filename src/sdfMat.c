#include "types.h"

typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;
typedef struct sdfMatDef_t sdfMatDef_t;
typedef struct sdfMatList_t sdfMatList_t;
typedef struct sdfMatPacket_t sdfMatPacket_t;
typedef struct sdfMatUvwParm_t sdfMatUvwParm_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static sdfDelayedResrcCB_t *sdfMatDelayedResrcCB;
static sdfDelayedResrcCB_t *sdfMatDelayedResrcCB2;
static s32 sdfMatAllocCount;

void sdfDelayedResrcEntry(sdfDelayedResrcCB_t *aCB, void *aItem);
void sdfMatListAdd(sdfMatList_t *aList, sdfMat_t *aMat);
sdfMat_t *sdfMatNew(void);

// 0x1794af0
sdfMatUvwParm_t *sdfMatAllocTexUvwParm(void) {
  return 0;
}

// 0x1795d90
void sdfMatCopyStat(sdfMat_t *aDstMat, sdfMat_t *aSrcMat) {
  aDstMat->duty = -1;
  aDstMat->flags = aSrcMat->flags;
  aDstMat->ambient = aSrcMat->ambient;
  aDstMat->diffuse = aSrcMat->diffuse;
  aDstMat->multiTexDiffuse = aSrcMat->multiTexDiffuse;
  aDstMat->constant = aSrcMat->constant;
  aDstMat->specular = aSrcMat->specular;
  aDstMat->refmap = aSrcMat->refmap;
  aDstMat->texHandle = aSrcMat->texHandle;
  if (aSrcMat->uvwParm)
  {
    if (!aDstMat->uvwParm)
    {
      aDstMat->uvwParm = 0;
    }
  }
  if (aSrcMat->multiTexUvwParm)
  {
    if (!aDstMat->multiTexUvwParm)
    {
      aDstMat->multiTexUvwParm = 0;
    }
  }
  aDstMat->fdBias = aSrcMat->fdBias;
  aDstMat->fdSoften = aSrcMat->fdSoften;
}

// 0x1795750
void sdfMatFree(sdfMat_t *aMat) {
  if (aMat)
  {
    --sdfMatAllocCount;
  }
}

// 0x17957d0
void sdfMatFreeDelayed(sdfMat_t *aMat) {
  sdfDelayedResrcCB_t_o *sdfMatDelayedResrcCB2;

  if (aMat)
  {
    sdfDelayedResrcEntry(sdfMatDelayedResrcCB2, aMat);
  }
}

// 0x1795000
sdfMatUvwParm_t *sdfMatGetMultiTexUvwParm(sdfMat_t *aMat) {
  sdfMatUvwParm_t_o *multiTexUvwParm;

  if ((byte_3F5A72C & 1) != 0)
  {
    multiTexUvwParm = aMat->multiTexUvwParm;
    if (multiTexUvwParm)
      return multiTexUvwParm;
  }
  else
  {
    multiTexUvwParm = aMat->multiTexUvwParm;
    if (multiTexUvwParm)
      return multiTexUvwParm;
  }
  aMat->multiTexUvwParm = 0;
  return multiTexUvwParm;
}

// 0x1794b00
sdfMatUvwParm_t *sdfMatGetTexUvwParm(sdfMat_t *aMat) {
  sdfMatUvwParm_t_o *uvwParm;

  if ((byte_3F5A729 & 1) != 0)
  {
    uvwParm = aMat->uvwParm;
    if (uvwParm)
      return uvwParm;
  }
  else
  {
    uvwParm = aMat->uvwParm;
    if (uvwParm)
      return uvwParm;
  }
  aMat->uvwParm = 0;
  return uvwParm;
}

// 0x17946f0
void sdfMatInitSystem(void) {
  ;
}

// 0x1794930
void sdfMatListAdd(sdfMatList_t *aList, sdfMat_t *aMat) {
  s32 count;
  struct sdfMat_t_array *items;

  count = aList->count;
  if (count >= aList->capacity
  {
    LOWORD(count) = aList->count;
  }
  items = aList->items;
  items->m_Items[count] = aMat;
  ++aList->count;
}

// 0x1794860
void sdfMatListFree(sdfMatList_t *aList, s32 aReleaseItems) {
  sdfDelayedResrcCB_t_o *sdfMatDelayedResrcCB;

  if (aList && aReleaseItems)
  {
    sdfDelayedResrcEntry(sdfMatDelayedResrcCB, aList);
  }
}

// 0x17946e0
void sdfMatListFreeResrc(sdfMatList_t *aList) {
  ;
}

// 0x1794920
void sdfMatListGrow(sdfMatList_t *aList) {
  ;
}

// 0x1795b20
sdfMatList_t *sdfMatListMake(sdfModelTexList_t *aTexList, s32 setCount, sdfMatDef_t *aData) {
  s32 v4;
  u32 v5;
  u64 *v6;
  sdfMat_t_o *v9;
  u64 *v10;

  v4 = setCount;
  if (v4 <= 32)
    v5 = 32;
  else
    v5 = v4;
LABEL_10:
  v6 = Allocate(sdfMatList_t);
  sdfMatList_t___ctor(v6);
  *(v6 + 12) = 0;
  *(v6 + 13) = v5;
  *(v6 + 7) = 0x80000;
  v6[4] = NewSpecific(sdfMat_t, v5);
  if (v4)
  {
    {
      v9 = sdfMatNew(sdfMat);
      if ((byte_3F5A72F & 1) == 0)
        goto LABEL_17;
LABEL_18:
      v10 = Allocate(sdfMatDef_t);
      sdfMatDef_t___ctor(v10);
      sdfMatListAdd(v6, v9);
      if (!--v4)
        return v6;
    }
    v9 = sdfMatNew();
    if ((byte_3F5A72F & 1) != 0)
      goto LABEL_18;
LABEL_17:
    goto LABEL_18;
  }
  return v6;
}

// 0x1794700
sdfMatList_t *sdfMatListNew(s32 aInitCapa) {
  u64 *v3;

  v3 = Allocate(sdfMatList_t);
  sdfMatList_t___ctor(v3);
  *(v3 + 12) = 0;
  *(v3 + 13) = aInitCapa;
  *(v3 + 7) = 0x80000;
  if (aInitCapa)
  {
    v3[4] = NewSpecific(sdfMat_t, aInitCapa);
  }
  else
  {
    v3[2] = 0;
    v3[4] = 0;
  }
  return v3;
}

// 0x1795cd0
void sdfMatListUpdatePacket(sdfMatList_t *aMatList, s32 aId) {
  s32 count;
  u32 i;

  count = aMatList->count;
  if (count >= 1)
  {
    for (i = 0; i != count; ++i)
    {
      while (1)
      {
          break;
        if (count == ++i)
          return;
      }
    }
  }
}

// 0x1795880
void *sdfMatMakePacket(sdfMat_t *aMat, void *aBuffer, s32 aId) {
  s32 v6;

  v6 = *il2cp::SizeOf(aBuffer, s32) + 16;
  return sub_8D3950(s32, &v6);
}

// 0x17954c0
sdfMat_t *sdfMatNew(void) {
  u64 *v1;
  u64 *v4;
  u64 v5;
  sdfMatPacket_t_o *v7;
  u64 v8;

  v1 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v1);
  ++sdfMatAllocCount;
  *(v1 + 22) = -1;
  v4 = Allocate(sdfMatPacket_t);
  sdfMatPacket_t___ctor(v4);
  v5 = v1[3];
  *(v5 + 32) = v4;
  *(v4 + 4) = 1845870592;
  *(v4 + 10) = 1610989573;
  v4[8] = 0x640CC00A00000000LL;
  v4[16] = 0x140000000400000CLL;
  v7 = Allocate(sdfMatPacket_t);
  sdfMatPacket_t___ctor(v7);
  v8 = v1[3];
  *(v8 + 40) = v7;
  v7->vifcode0 = 1845870592;
  v7->vifcode1 = 1610989573;
  v7->pad = 0;
  v7->vifcode2 = 1678557194;
  v7->cmd_call_spec = 67108876;
  v7->cmd_call_kind = 335544320;
  v1[4] = 0x8080808080808080LL;
  *(v1 + 10) = -2139062144;
  v1[13] = 0;
  return v1;
}

// 0x17956f0
sdfMatDef_t *sdfMatSet(sdfMat_t *aMatPtr, sdfModelTexList_t *aTexList, sdfMatDef_t *aDef) {
  u64 *v4;

  v4 = Allocate(sdfMatDef_t);
  sdfMatDef_t___ctor(v4);
  return v4;
}

// 0x1794a30
void sdfMatSetAmbient(sdfMat_t *aMat, u32 aColor) {
  u8 v3;

  v3 = aMat->duty | 3;
  aMat->ambient = aColor;
  aMat->duty = v3;
}

// 0x1794ab0
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio) {
  u8 v3;

  if (aMat)
  {
    v3 = aMat->duty | 3;
    aMat->constant = aRatio;
    aMat->duty = v3;
  }
}

// 0x1794a50
void sdfMatSetDiffuse(sdfMat_t *aMat, u32 aColor) {
  u8 v3;

  v3 = aMat->duty | 3;
  aMat->diffuse = aColor;
  aMat->duty = v3;
}

// 0x17954a0
void sdfMatSetFaceDivParm(sdfMat_t *aMat, f32 aBias, f32 aSoften) {
  u8 v4;

  v4 = aMat->duty | 0xC0;
  aMat->fdBias = aBias;
  aMat->fdSoften = aSoften;
  aMat->duty = v4;
}

// 0x1794fa0
void sdfMatSetMultiDiffuse(sdfMat_t *aMat, u32 aColor) {
  u8 v3;

  v3 = aMat->duty | 0x30;
  aMat->multiTexDiffuse = aColor;
  aMat->duty = v3;
}

// 0x1794fc0
void sdfMatSetMultiMethod(sdfMat_t *aMat, u32 aMethod) {
  u8 v3;

  v3 = aMat->duty | 0x30;
  aMat->multiTexMethod = aMethod;
  aMat->duty = v3;
}

// 0x1794fe0
void sdfMatSetMultiTex(sdfMat_t *aMat, sdfTexHandle_t *aTex) {
  u8 v3;

  v3 = aMat->duty | 0x30;
  aMat->multiTexHandle = aTex;
  aMat->duty = v3;
}

// 0x1795090
void sdfMatSetMultiTexUvw(sdfMat_t *aMat, f32 aOffsetX, f32 aOffsetY, f32 aTileX, f32 aTileY, f32 aAngle) {
  struct sdfMatUvwParm_t_o *multiTexUvwParm;
  struct System_Single_array *offset;
  struct System_Single_array *v15;
  struct System_Single_array *tile;
  struct System_Single_array *v19;

  else if ((byte_3F5A72C & 1) != 0)
  {
    goto LABEL_6;
  }
  multiTexUvwParm = aMat->multiTexUvwParm;
  if (multiTexUvwParm)
  {
LABEL_7:
    offset = multiTexUvwParm->offset;
    if (LODWORD(offset->max_length))
      goto LABEL_8;
LABEL_20:
  }
LABEL_17:
  else
  {
    aMat->multiTexUvwParm = 0;
    offset = multiTexUvwParm->offset;
    if (!LODWORD(offset->max_length))
      goto LABEL_20;
  }
LABEL_8:
  offset->m_Items[0] = aOffsetX;
  v15 = multiTexUvwParm->offset;
  v15->m_Items[1] = aOffsetY;
  tile = multiTexUvwParm->tile;
  tile->m_Items[0] = aTileX;
  v19 = multiTexUvwParm->tile;
  v19->m_Items[1] = aTileY;
  multiTexUvwParm->angle = aAngle;
  aMat->duty |= 0x30u;
}

// 0x1795240
void sdfMatSetMultiTexUvwByPtr(sdfMat_t *aMat, f32 **aParm) {
  struct sdfMatUvwParm_t_o *multiTexUvwParm;
  struct System_Single_array *offset;
  struct System_Single_array *v7;
  struct System_Single_array *tile;
  struct System_Single_array *v13;

  else if ((byte_3F5A72C & 1) != 0)
  {
    goto LABEL_6;
  }
  multiTexUvwParm = aMat->multiTexUvwParm;
  if (multiTexUvwParm)
  {
LABEL_7:
    offset = multiTexUvwParm->offset;
    if (LODWORD(aParm->max_length))
      goto LABEL_8;
LABEL_29:
  }
LABEL_26:
  else
  {
    aMat->multiTexUvwParm = 0;
    offset = multiTexUvwParm->offset;
    if (!LODWORD(aParm->max_length))
      goto LABEL_29;
  }
LABEL_8:
  offset->m_Items[0] = aParm->m_Items[0];
  v7 = multiTexUvwParm->offset;
  v7->m_Items[1] = aParm->m_Items[1];
  tile = multiTexUvwParm->tile;
  tile->m_Items[0] = aParm->m_Items[2];
  v13 = multiTexUvwParm->tile;
  v13->m_Items[1] = aParm->m_Items[3];
  multiTexUvwParm->angle = aParm->m_Items[4];
  aMat->duty |= 0x30u;
}

// 0x1794a90
void sdfMatSetRefMap(sdfMat_t *aMat, u32 aColor) {
  u8 v3;

  v3 = aMat->duty | 3;
  aMat->refmap = aColor;
  aMat->duty = v3;
}

// 0x1794a70
void sdfMatSetSpecular(sdfMat_t *aMat, u32 aColor) {
  u8 v3;

  v3 = aMat->duty | 3;
  aMat->specular = aColor;
  aMat->duty = v3;
}

// 0x1794ad0
void sdfMatSetTex(sdfMat_t *aMat, sdfTexHandle_t *aTex) {
  u8 v3;

  v3 = aMat->duty | 3;
  aMat->texHandle = aTex;
  aMat->duty = v3;
}

// 0x1794b90
void sdfMatSetTexUvw(sdfMat_t *aMat, f32 aOffsetX, f32 aOffsetY, f32 aTileX, f32 aTileY, f32 aAngle) {
  struct sdfMatUvwParm_t_o *uvwParm;
  struct System_Single_array *offset;
  struct System_Single_array *v15;
  struct System_Single_array *tile;
  struct System_Single_array *v19;

  else if ((byte_3F5A729 & 1) != 0)
  {
    goto LABEL_6;
  }
  uvwParm = aMat->uvwParm;
  if (uvwParm)
  {
LABEL_7:
    offset = uvwParm->offset;
    if (LODWORD(offset->max_length))
      goto LABEL_8;
LABEL_20:
  }
LABEL_17:
  else
  {
    aMat->uvwParm = 0;
    offset = uvwParm->offset;
    if (!LODWORD(offset->max_length))
      goto LABEL_20;
  }
LABEL_8:
  offset->m_Items[0] = aOffsetX;
  v15 = uvwParm->offset;
  v15->m_Items[1] = aOffsetY;
  tile = uvwParm->tile;
  tile->m_Items[0] = aTileX;
  v19 = uvwParm->tile;
  v19->m_Items[1] = aTileY;
  uvwParm->angle = aAngle;
  aMat->duty |= 0xCu;
}

// 0x1794d40
void sdfMatSetTexUvwByPtr(sdfMat_t *aMat, f32 **aParm) {
  struct sdfMatUvwParm_t_o *uvwParm;
  struct System_Single_array *offset;
  struct System_Single_array *v7;
  struct System_Single_array *tile;
  struct System_Single_array *v13;

  else if ((byte_3F5A729 & 1) != 0)
  {
    goto LABEL_6;
  }
  uvwParm = aMat->uvwParm;
  if (uvwParm)
  {
LABEL_7:
    offset = uvwParm->offset;
    if (LODWORD(aParm->max_length))
      goto LABEL_8;
LABEL_29:
  }
LABEL_26:
  else
  {
    aMat->uvwParm = 0;
    offset = uvwParm->offset;
    if (!LODWORD(aParm->max_length))
      goto LABEL_29;
  }
LABEL_8:
  offset->m_Items[0] = aParm->m_Items[0];
  v7 = uvwParm->offset;
  v7->m_Items[1] = aParm->m_Items[1];
  tile = uvwParm->tile;
  tile->m_Items[0] = aParm->m_Items[2];
  v13 = uvwParm->tile;
  v13->m_Items[1] = aParm->m_Items[3];
  uvwParm->angle = aParm->m_Items[4];
  aMat->duty |= 0xCu;
}

// 0x1795990
void sdfMatSetUvwParm(void *aUvwPacket, sdfMatUvwParm_t *aParm) {
  ;
}

// 0x1795b10
void sdfMatUpdatePacket(sdfMat_t *aMat, s32 aId) {
  ;
}

// 0x1795900
void sdfMatUpdatePacketBasic(sdfMat_t *aMat, sdfMatPacket_t *aPacket) {
  u64 *v5;

  v5 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v5);
  aPacket->ambient = aMat->ambient;
  aPacket->diffuse = aMat->diffuse;
  aPacket->constant = aMat->constant;
  aPacket->specularColor = aMat->specular;
  aPacket->refmapColor = aMat->refmap;
}

// 0x1795af0
void sdfMatUpdatePacketFaceDiv(sdfMat_t *aMat, sdfMatPacket_t *aPacket) {
  aPacket->fdBias = aMat->fdBias;
  aPacket->fdSoften = aMat->fdSoften;
}

// 0x1795a30
void sdfMatUpdatePacketMultiTex(sdfMat_t *aMat, sdfMatPacket_t *aPacket) {
  u64 *v5;

  v5 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v5);
  aPacket->mtexDiffuse = aMat->multiTexDiffuse;
  aPacket->mtexAlgo = aMat->multiTexMethod;
}

// 0x17959a0
void sdfMatUpdatePacketUvwParm(sdfMat_t *aMat, sdfMatPacket_t *aPacket) {

}

// 0x17945e0
void sdfTexListAdd(sdfModelTexList_t *aList, sdfTexHandle_t *aTexHandle) {
  ++aList->count;
}

// 0x1794610
sdfModelTexList_t *sdfTexListDup(sdfModelTexList_t *aList) {
  s16 count;

  if (aList)
  {
    count = aList->count;
    WORD4(xmmword_10) = count;
  }
  return 0;
}

// 0x17945d0
void sdfTexListFree(sdfModelTexList_t *aList, s32 aReleaseItems) {
  ;
}

// 0x17945c0
sdfModelTexList_t *sdfTexListNew(s32 aInitCapa) {
  return 0;
}

// 0x17945f0
void sdfTexListSetCapacity(sdfModelTexList_t *aList, s32 aCapa, s32 aReleaseItems) {
  if (aReleaseItems)
  {
    if (aList->count > aCapa)
      aList->count = aCapa;
  }
}

// 0x1794690
void sdfTexListSetClutColor(sdfModelTexList_t *aList, u32 aColor, f32 aRatio) {
  u64 *v4;

  v4 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v4);
}
