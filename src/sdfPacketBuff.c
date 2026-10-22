#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;

static sdfMemHandle_t *sdfGrPacketBuffHandle;
static s32 sdfGrPacketBuffSize;
static void *sdfGrPacketBuffPtr;
static void *sdfGrPacketBuffLimit;
static u8 sdfPacketBuffFlag;

// 0x17a5e40
void *sdfGrAllocPacketBuff(s32 aSize) {
  u64 *v2;
  u64 *v3;

  v2 = Allocate(object);
  _ctor(v2, 0);
  v3 = Allocate(object);
  _ctor(v3, 0);
  sdfGrPacketBuffPtr = v2;
  return v3;
}

// 0x17a5f60
void sdfGrClosePacketBuff(void *aBuffPtr) {
  ;
}

// 0x17a5da0
s32 sdfGrGetPacketBuffRemain(void) {
  s64 sdfGrPacketBuffPtr;
  s32 v5;

  v5 = *il2cp::SizeOf(sdfGrPacketBuffLimit, s32);
  return v5 - *il2cp::SizeOf(sdfGrPacketBuffPtr, s32);
}

// 0x17a5c10
void sdfGrMakePacketBuff(s32 aPacketBuffSize) {
  u64 *v3;
  u64 *v7;

  v3 = Allocate(object);
  _ctor(v3, 0);
  if (sdfGrPacketBuffHandle)
  {
    sdfGrPacketBuffHandle = 0;
  }
  sdfGrPacketBuffSize = aPacketBuffSize;
  v7 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v7);
  sdfGrPacketBuffHandle = v7;
  sdfPacketBuffFlag = 0;
}

// 0x17a5ef0
void *sdfGrOpenPacketBuff(void) {
  return sdfGrPacketBuffPtr;
}

// 0x17a5d10
void sdfGrSetupPacketBuff(s32 aFrameId) {
  u64 *v2;

  v2 = Allocate(object);
  _ctor(v2, 0);
  sdfPacketBuffFlag = 1;
  sdfGrPacketBuffPtr = v2;
}
