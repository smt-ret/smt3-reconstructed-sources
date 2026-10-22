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
  s32 v4;

  v4 = *il2cp::SizeOf(aPacketPtr, s32) + 32;
  return sub_8D3950(s32, &v4);
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  else if (!aPacket)
  {
    return aPacket;
  }
  klass = aPacket->klass;
  if (aPacket->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfGrPacketHeader_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfGrPacketHeader_t, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  return aPacket;
}

// 0x17c9480
void *sdf2DMakeTexPacket(void *aPacket, sdfTexHandle_t *aTexHndl, s32 aCtx) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  Il2CppClass *v11;
  u64 *monitor;
  u64 v14[3];

  if (aPacket)
  {
    klass = aPacket->klass;
    if (aPacket->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdf2DTexPacket_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdf2DTexPacket_t, v14);
      if ((v14[0] & 1) != 0)
        v9 = v14[2];
      else
        v9 = v14 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  LOWORD(aPacket[1].klass->_1.name) = 4;
  LODWORD(aPacket[1].klass->_1.byval_arg.data) = 0;
  v11 = aPacket[1].klass;
  HIDWORD(v11->_1.byval_arg.data) = SDF_VIF_SET_DIRECT(4u);
  monitor = aPacket[1].monitor;
  monitor[2] = SDF_GIFTAG_PARM(3u, 1u, 0, 0, 0, 1u);
  *(aPacket[1].monitor + 3) = 14;
  aPacket[3].klass->_1.name = aTexHndl;
  aPacket[3].klass->_1.byval_arg.data = (aCtx + 20);
  *(aPacket[2].monitor + 2) = aTexHndl;
  *(aPacket[2].monitor + 4) = aCtx + 6;
  *(aPacket[3].monitor + 2) = aTexHndl;
  *(aPacket[3].monitor + 4) = aCtx + 8;
  return aPacket;
}
