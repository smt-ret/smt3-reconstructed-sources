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
    if (aPixelFormat != 27)
      return 0;
  }
  if (aPixelFormat == 19)
  {
    v8 = 256;
    v9 = 32;
  }
  if (aPixelFormat != 20)
    return 0;
  v8 = 64;
  v9 = 8;
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
    return 0;
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
    return 0;
}

// 0x15d4280
void *sdfTexTransData(s32 aGsAddr, s32 aWidth, s32 aHeight, s32 aPixelFormat, void *aSrcData, s32 aMemMode) {
    return 0;
}
