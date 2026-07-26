#include "types.h"

typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

u64 SDF_GIFTAG_PARM(u16 nloop, u32 eop, u8 pre, u16 prim, u8 flg, u8 nreg);
u32 SDF_VIF_SET_DIRECT(u32 addr);
void *sdf2DMakeTexPacket(void *aPacket, sdfTexHandle_t *aTexHndl, s32 aCtx);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
void *sdfGrAllocPacketBuff(s32 aSize);

// 0x17c9c80
void *sdf2DAllocSprite(s32 aNumOfSpr) {
  s32 v3;

  v3 = 80 * aNumOfSpr + 32;
  return sdfGrAllocPacketBuff(v3);
}

// 0x17c9ae0
s32 sdf2DGetPrimPacketSize(s32 aNumOfRegs, s32 aNumOfPrim) {
  return 16 * aNumOfRegs * aNumOfPrim + 32;
}

// 0x17c9af0
void *sdf2DGetPrimPtr(void *aPacketPtr) {
    return 0;
}

// 0x17c9470
s32 sdf2DGetTexPacketSize(sdfTexHandle_t *aTexHndl) {
  return 0;
}

// 0x17c9620
void *sdf2DLinkTexPacket(sdfDrawTag_t *aTag, sdfTexHandle_t *aTexHndl, s32 aCtx) {
  u64 *v7;

  v7 = Allocate(sdf2DTexPacket_t);
  _ctor(v7);
  sdf2DMakeTexPacket(v7, aTexHndl, aCtx);
  sdfDrawTagLink(aTag, v7);
  return v7;
}

// 0x17c9b70
void *sdf2DMakePrimPacketHeader(sdfGrPacketHeader_t *aPacketPtr, s32 aPrimReg, s32 aNumOfRegs, u64 aGifRegs, s32 aNumOfPrim) {
  struct sdfDmaTag_t_o *dmatag;
  u16 v8;
  u16 v9;
  u8 v11;
  struct sdfGifTag_t_o *giftag;

  aPacketPtr->dmatag->qwc = aNumOfPrim * aNumOfRegs + 1;
  aPacketPtr->dmatag->dat0 = 0;
  dmatag = aPacketPtr->dmatag;
  v8 = aPrimReg;
  v9 = aNumOfPrim;
  v11 = aNumOfRegs;
  dmatag->dat1 = SDF_VIF_SET_DIRECT(aNumOfPrim * aNumOfRegs + 1);
  giftag = aPacketPtr->giftag;
  giftag->parm = SDF_GIFTAG_PARM(v9, 1u, 1u, v8, 0, v11);
  aPacketPtr->giftag->regs = aGifRegs;
  return aPacketPtr;
}

// 0x17c9c10
void *sdf2DMakePrimPacketHeader_24943632(void *aPacketPtr, s32 aPrimReg, s32 aNumOfRegs, u64 aGifRegs, s32 aNumOfPrim) {
  sdf2DTexPacket_t_o *v7;

  v7 = Allocate(sdf2DTexPacket_t);
  _ctor(v7);
  v7->giftag->regs = aGifRegs;
  return v7;
}

// 0x17c99c0
void *sdf2DMakeStdPacket(void *aPacket, s32 aLeng) {
    return 0;
}

// 0x17c9480
void *sdf2DMakeTexPacket(void *aPacket, sdfTexHandle_t *aTexHndl, s32 aCtx) {
    SDF_VIF_SET_DIRECT(0);
    SDF_GIFTAG_PARM(0, 0, 0, 0, 0, 0);
    return 0;
}
