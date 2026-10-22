#include "types.h"

typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;
typedef struct sdfGsMemSlice_t sdfGsMemSlice_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct sdfTexPacket_t sdfTexPacket_t;

static u8 *tmxFileSizeTable[5];
static sdfDelayedResrcCB_t *sdfTexDelayedResrcCB;
static sdfTexHandle_t *sdfTexHandleLink;

void sdfDelayedResrcEntry(sdfDelayedResrcCB_t *aCB, void *aItem);
sdfGsMemSlice_t *sdfGsMemAllocFromTail(s32 aSize, s32 aType);
void sdfTexRebuildPacket(sdfTexHandle_t *aHandle);
void *sdfTexTransCLUT(sdfTexHandle_t *aHandle, s32 aGsAddr, void *aDataPtr, s32 aMemMode);

// 0x15d44b0
sdfTexHandle_t *sdfTexAlloc(s32 aWidth, s32 aHeight, s32 aPixelFormat, s32 aNumOfMipmap, s32 aCLUTFormat, s32 aNumOfCLUT) {
  u64 *v7;
  u64 *v8;
  u64 *v10;

  v7 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v7);
  v8 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v8);
LABEL_7:
  v10 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v10);
  return v10;
}

// 0x15d3cd0
sdfGsMemSlice_t *sdfTexAllocClut(s32 aPixelFormat, s32 aCLUTFormat, s32 aNumOfCLUT) {
  u64 *v6;
  s32 v8;
  s16 v9;
  sdfGsMemSlice_t_o *result;

  v6 = Allocate(sdfGsMemSlice_t);
  sdfGsMemSlice_t___ctor(v6);
  if (aPixelFormat > 20)
  {
    v8 = 64;
    v9 = 8;
    if (aPixelFormat == 44 || aPixelFormat == 36)
      goto LABEL_12;
    if (aPixelFormat != 27)
      return 0;
    goto LABEL_11;
  }
  if (aPixelFormat == 19)
  {
LABEL_11:
    v8 = 256;
    v9 = 32;
    goto LABEL_12;
  }
  if (aPixelFormat != 20)
    return 0;
  v8 = 64;
  v9 = 8;
LABEL_12:
  result = sdfGsMemAllocFromTail(v8, 3);
  result->w = 8;
  result->h = v9;
  result->pixelFormat = aCLUTFormat;
  return result;
}

// 0x15d3df0
void sdfTexAllocClutBuff(sdfTexHandle_t *aHandle) {
  s32 numOfCLUT;

  numOfCLUT = aHandle->numOfCLUT;
  aHandle->clutDataSize = numOfCLUT << 6;
}

// 0x15d3b20
void sdfTexClutToGs(sdfTexHandle_t *aHandle) {
  struct sdfGsMemSlice_t_o *clutGsHandle;
  s32 addr;

  clutGsHandle = aHandle->clutGsHandle;
  if (clutGsHandle)
  {
    {
      addr = clutGsHandle->addr;
    }
    else
    {
      addr = 0;
    }
    sdfTexTransCLUT(aHandle, addr, aHandle->clutData, 0);
  }
}

// 0x15d3e70
void sdfTexCopyClutData(sdfTexHandle_t *aHandle, void *aData) {
  ;
}

// 0x15d4440
sdfTexHandle_t *sdfTexDup(sdfTexHandle_t *aHandle) {
  u64 *v2;
  u64 *v3;

  v2 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v2);
  v3 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v3);
  return v2;
}

// 0x15d4590
void sdfTexFree(sdfTexHandle_t *aHandle) {
  u64 *v2;
  u64 *v3;
  u64 *v4;

  v2 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v2);
  v3 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v3);
  v4 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v4);
}

// 0x15d4600
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle) {
  sdfDelayedResrcCB_t_o *sdfTexDelayedResrcCB;

  sdfDelayedResrcEntry(sdfTexDelayedResrcCB, aHandle);
}

// 0x15d3bc0
s32 sdfTexGetCLUTAddr(sdfTexHandle_t *aHandle) {
  struct sdfGsMemSlice_t_o *clutGsHandle;

  clutGsHandle = aHandle->clutGsHandle;
  if (clutGsHandle)
    return clutGsHandle->addr;
  else
    return 0;
}

// 0x15d3f70
s32 sdfTexGetCLUTCount(sdfTexHandle_t *aHandle) {
  return aHandle->numOfCLUT;
}

// 0x15d3fd0
u64 sdfTexGetClampReg(sdfTexHandle_t *aHandle) {
  return 0;
}

// 0x15d3e60
s32 sdfTexGetClutDataSize(s32 aPixelFormat, s32 aCLUTFormat, s32 aNumOfCLUT) {
  return aNumOfCLUT << 6;
}

// 0x15d3e80
void *sdfTexGetPacket(sdfTexHandle_t *aHandle) {
  return &aHandle->packet->obj;
}

// 0x15d3ea0
void *sdfTexGetPacketCtx2(sdfTexHandle_t *aHandle) {
  Il2CppObject *packetCtx2;

  packetCtx2 = aHandle->packetCtx2;
  if (!packetCtx2)
  {
    aHandle->packetCtx2 = 0;
  }
  return packetCtx2;
}

// 0x15d3f60
s32 sdfTexGetPacketCtx2Length(sdfTexHandle_t *aHandle) {
  return 0;
}

// 0x15d3e90
s32 sdfTexGetPacketLength(sdfTexHandle_t *aHandle) {
  return 0;
}

// 0x15d3f80
s32 sdfTexGetPixelAddr(sdfTexHandle_t *aHandle) {
  return aHandle->pixelGsHandle->addr;
}

// 0x15d3f90
s32 sdfTexGetPixelBitCount(s32 aFormat) {
  return 32;
}

// 0x15d3fb0
u64 sdfTexGetTex0Reg(sdfTexHandle_t *aHandle) {
  return 0;
}

// 0x15d3fc0
u64 sdfTexGetTex1Reg(sdfTexHandle_t *aHandle) {
  return 0;
}

// 0x15d3fa0
s32 sdfTexGetTexelBitCount(s32 aFormat) {
  return 32;
}

// 0x15d4bf0
void sdfTexInit(void) {
  ;
}

// 0x15d4310
void sdfTexLink(sdfTexHandle_t *handle) {
  u64 *v3;
  sdfTex_c *v5;
  struct sdfTexHandle_t_o *sdfTexHandleLink;

  v3 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v3);
  handle->prev = 0;
  else
  {
    if (sdfTexHandleLink)
      goto LABEL_6;
  }
  handle->next = 0;
  if ((v5->_2.bitflags2 & 2) == 0)
    goto LABEL_11;
LABEL_7:
LABEL_11:
  sdfTexHandleLink = handle;
}

// 0x15d46b0
void sdfTexMakeGIFPacket(sdfTexHandle_t *aHandle) {
  {
    aHandle->packet = 0;
  }
}

// 0x15d3a90
void sdfTexMakeGIFPacketCtx2(sdfTexHandle_t *aHandle) {
  {
    aHandle->packetCtx2 = 0;
  }
}

// 0x15d3b10
void *sdfTexMakeGIFPacketSub(sdfTexHandle_t *aHandle, s32 aContext) {
  return 0;
}

// 0x15d43e0
sdfTexHandle_t *sdfTexNew(s32 aWidth, s32 aHeight, s32 aPixelFormat, s32 aNumOfMipmap, sdfGsMemSlice_t *aPixelGsHandle, s32 aCLUTFormat, s32 aNumOfCLUT, sdfGsMemSlice_t *aCLUTGsHandle) {
  u64 *v9;

  v9 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v9);
  return v9;
}

// 0x15d4080
void sdfTexRebuildPacket(sdfTexHandle_t *aHandle) {
  struct System_Object_array *packet;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppObject *packetCtx2;
  Il2CppClass *v11;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[2];
  char *v16;

  if ((byte_3F5A031 & 1) == 0)
  {
    packet = aHandle->packet;
    if (LODWORD(packet->max_length))
      goto LABEL_3;
LABEL_6:
  }
  packet = aHandle->packet;
  if (!LODWORD(packet->max_length))
    goto LABEL_6;
LABEL_3:
  v4 = packet->m_Items[0];
  if (!v4)
    goto LABEL_13;
  klass = v4->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfTexPacket_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfTexPacket_t, v15);
    if ((v15[0] & 1) != 0)
      v8 = v16;
    else
      v8 = v15 + 1;
    v9 = sub_8C4940(v8);
  }
  else
  {
LABEL_13:
    packetCtx2 = aHandle->packetCtx2;
    if (!packetCtx2)
      return;
  }
  v11 = packetCtx2->klass;
  if (v11->_2.typeHierarchyDepth < v12 || v11->_2.typeHierarchy[v12 - 1] != sdfTexPacket_t)
  {
    sub_8FC2C0(v11->_1.element_class, sdfTexPacket_t, v15);
    if ((v15[0] & 1) != 0)
      v13 = v16;
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
}

// 0x15d4b40
sdfTexHandle_t *sdfTexSearch(u32 id) {
  u64 *v3;
  sdfTexHandle_t_o *result;

  v3 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v3);
  else
  {
    result = sdfTexHandleLink;
    if (!result)
      return result;
  }
  do
  {
    if (result->texId == id)
      break;
    result = result->next;
  }
  while (result);
  return result;
}

// 0x15d4790
sdfTexHandle_t *sdfTexSet(void *aTex) {
  u64 *v2;

LABEL_7:
  v2 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v2);
  return v2;
}

// 0x15d4b30
void sdfTexSetClutColor(sdfTexHandle_t *aHandle, u32 aColor, f32 aRatio) {
  ;
}

// 0x15d4a70
sdfTexHandle_t *sdfTexSetDirect(void *aTex) {
  u64 *v2;

LABEL_7:
  v2 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v2);
  return v2;
}

// 0x15d4730
sdfTexHandle_t *sdfTexSetEx(void *aTex, s32 aMemMode) {
  u64 *v3;

  v3 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v3);
  return v3;
}

// 0x15d3fe0
void sdfTexSetFilter(sdfTexHandle_t *aHandle, s32 aMagMode, s32 aMinMode) {
  ;
}

// 0x15d3ff0
void sdfTexSetFilterCtx2(sdfTexHandle_t *aHandle, s32 aMagMode, s32 aMinMode) {
  ;
}

// 0x15d4840
sdfTexHandle_t *sdfTexSetForUnity(void *aTex) {
  sdfTexHandle_t_o *v3;
  s32 v4;
  s32 v5;
  u64 *v6;
  UnityEngine_RenderTexture_o *active;
  u64 *v8;
  s32 v10;
  s32 v11;
  struct UnityEngine_Texture2D_array *v12;
  struct UnityEngine_Texture2D_array *v13;
  UnityEngine_Rect_o v17;

  *&v17.m_XMin = 0;
  *&v17.m_Width = 0;
  v3 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v3);
  v4 = (aTex->klass->vtable._4_get_width.methodPtr)(aTex, aTex->klass->vtable._4_get_width.method);
  v5 = (aTex->klass->vtable._6_get_height.methodPtr)(aTex, aTex->klass->vtable._6_get_height.method);
  v6 = Allocate(UnityEngine_Texture2D);
  _ctor_27469040(v6, v4, v5, 4, 0);
  active = get_active(0);
  v8 = Allocate(UnityEngine_RenderTexture);
  _ctor_27407312(v8, v4, v5, 32);
  Blit(aTex, v8, 0);
  set_active(v8, 0);
  v10 = (*(*v8 + 360))(v8, *(*v8 + 368));
  v11 = (*(*v8 + 392))(v8, *(*v8 + 400));
  sub_1A1D780(&v17.m_XMin, 0.0, 0.0, v10, v11);
  ReadPixels_27473280(v6, v17, 0, 0);
  Apply_27472496(v6);
  set_active(active, 0);
  v12 = NewSpecific(UnityEngine_Texture2D, 1u);
  v13 = v12;
  v3->image = v12;
  v13->m_Items[0] = v6;
  v3->width = v4;
  v3->height = v5;
  return v3;
}

// 0x15d4b20
void sdfTexSetMonoClut(sdfTexHandle_t *aHandle) {
  ;
}

// 0x15d46a0
void sdfTexSetPacket(sdfTexPacket_t *aPacket, s32 aWidth, s32 aHeight, s32 aGsAddr, s32 aPixelFormat, s32 aClutAddr, s32 aClutFormat, s32 aColorComp, s32 aNumOfMipmap, s32 aMipmapParm, s32 aWrapMode, s32 aContext) {
  ;
}

// 0x15d4000
void sdfTexSetWrapMode(sdfTexHandle_t *aHandle, s32 aMode) {
  u8 v3;

  v3 = aMode;
  aHandle->texWrapMode = v3;
  sdfTexRebuildPacket(aHandle, *&aMode);
}

// 0x15d3be0
void *sdfTexTransCLUT(sdfTexHandle_t *aHandle, s32 aGsAddr, void *aDataPtr, s32 aMemMode) {
  u64 *v6;
  s32 v8;

LABEL_7:
  v6 = Allocate(sdfImageSetParm_t);
  sdfImageSetParm_t___ctor(v6);
  v8 = *il2cp::SizeOf(aDataPtr, qword_3F088F8);
  return sub_8D3950(s32, &v8);
}

// 0x15d4280
void *sdfTexTransData(s32 aGsAddr, s32 aWidth, s32 aHeight, s32 aPixelFormat, void *aSrcData, s32 aMemMode) {
  u64 *v8;
  s32 v10;

  v8 = Allocate(sdfImageSetParm_t);
  sdfImageSetParm_t___ctor(v8);
  v10 = *il2cp::SizeOf(aSrcData, qword_3F088F8);
  return sub_8D3950(s32, &v10);
}
