#include "types.h"

typedef struct dds3DrawEnv_t dds3DrawEnv_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfGrRefPacketHeader_t sdfGrRefPacketHeader_t;
typedef struct sdfGrStdDrawEnv_t sdfGrStdDrawEnv_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 PRIM;
static s32 RGBAQ;
static s32 XYZ2;
static s32 NOP;
static sdfGrOt_t *dds3Ot[1];
static u32 dds3RBackColor;
static dds3DrawEnv_t dds3DrawEnv[UNKNOWN_ARRAY_SIZE];
static sdfVector4_t dds3RCameraTargetPos;
static sdfVector4_t dds3RCameraEyePos;
static u32 effPktDefaultTriangleFaceIndex[32];
static s8 dds3CrossfadeRunFlag;
static u32 dds3CrossfadeFrame;
static u32 dds3CrossfadeFrame_End;

s32 dds3AllocRenderTexture(u16 sx, u16 sy, f32 aspect);
void dds3CrossfadeEnd(void);
void dds3FreeRenderTexture(void);
s32 dds3GetFrameID(void);
void dds3RenderTextureOFF(void);
s32 dds3RenderTextureON(void);
void *sdf2DAllocSprite(s32 aNumOfSpr);
s32 sdf2DGetPrimPacketSize(s32 aNumOfRegs, s32 aNumOfPrim);
void *sdf2DGetPrimPtr(void *aPacketPtr);
void *sdf2DLinkTexPacket(sdfDrawTag_t *aTag, sdfTexHandle_t *aTexHndl, s32 aCtx);
void *sdf2DMakePrimPacketHeader_24943632(void *aPacketPtr, s32 aPrimReg, s32 aNumOfRegs, u64 aGifRegs, s32 aNumOfPrim);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
void *sdfGrAllocPacketBuff(s32 aSize);
void sdfGrLinkDispFrameTex(sdfDrawTag_t *aTag, sdfGrStdDrawEnv_t *aEnv, sdfGrRefPacketHeader_t *aPkt);

// 0x122a110
s32 SDF_DMA_ID(s32 irq, s32 id, s32 pce) {
  return 0;
}

// 0x122a120
s32 SDF_DMA_SET_TAG(s32 p, s32 qwc, s32 id, s32 addr) {
  return 0;
}

// 0x122a0d0
s32 SDF_EVAL(s32 a) {
  return a;
}

// 0x122a170
s32 SDF_GIFTAG_PARM(s32 nloop, s32 eop, s32 pre, s32 prim, s32 flg, s32 nreg) {
  return 0;
}

// 0x122a180
s32 SDF_GIFTAG_REGS11(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4, s32 r5, s32 r6, s32 r7, s32 r8, s32 r9, s32 rA) {
  return 0;
}

// 0x122a160
s32 SDF_GIF_SET_XYZ2(s32 pkt, s32 x, s32 y, s32 z, s32 adc) {
  return 0;
}

// 0x122a1c0
u64 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix) {
  return a | (4 * b) | (16 * c) | fix | (d << 6);
}

// 0x122a130
s32 SDF_GS_SET_PRIM(s32 prim, s32 iip, s32 tme, s32 fge, s32 abe, s32 aa1, s32 fst, s32 ctxt, s32 fix) {
  return prim | (8 * iip) | (16 * tme) | (32 * fge) | (abe << 6) | (aa1 << 7) | (fst << 8) | (ctxt << 9) | (fix << 10);
}

// 0x122a1e0
u64 SDF_GS_SET_TEST(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  return ate | (2 * atst) | (16 * aref) | (afail << 12) | (date << 14) | (datm << 15) | (zte << 16) | (ztst << 17);
}

// 0x122a1b0
s32 SDF_GS_SET_TEXA(s32 ta0, s32 aem, s32 ta1) {
  return 0;
}

// 0x122a1a0
s32 SDF_GS_SET_XYZ2(s32 x, s32 y, s32 z) {
  return 0;
}

// 0x122a0e0
s32 SDF_MAKE32(s32 l, s32 h) {
  return 0;
}

// 0x122a100
s32 SDF_MAKE64(s32 l, s32 h) {
  return 0;
}

// 0x122a0f0
s32 SDF_POKE64(s32 p, s32 d) {
  return 0;
}

// 0x122a190
s32 SDF_SIZE_ADJUST(s32 i, s32 n) {
  return 0;
}

// 0x122a290
void SDF_STORE_UNALIGN96(void *p, u32 d) {
  ;
}

// 0x122a250
u32 SDF_VIF_SET_DIRECT(u32 addr) {
  return addr | 0x50000000;
}

// 0x122a260
u32 SDF_VIF_SET_DIRECTHL(u32 size) {
  return size | 0x51000000;
}

// 0x122a230
u32 SDF_VIF_SET_ITOP(u32 addr) {
  return addr | 0x4000000;
}

// 0x122a240
u32 SDF_VIF_SET_MPG(u32 addr, u32 size) {
  return addr | (size << 16) | 0x4A000000;
}

// 0x122a220
u32 SDF_VIF_SET_MSCAL(u32 addr) {
  return addr | 0x14000000;
}

// 0x122a270
u32 SDF_VIF_SET_UNPACK(u32 typ, u32 m, u32 usn, u32 flg, u32 addr, u32 size) {
  return (typ << 24) | (m << 28) | (usn << 14) | (flg << 15) | addr | (size << 16) | 0x60000000;
}

// 0x122a990
void dds3CrossfadeEnd(void) {
  dds3RenderTextureOFF();
  dds3FreeRenderTexture();
  dds3CrossfadeRunFlag = 0;
  Write(StringLiteral_15554, 0);
}

// 0x122aa60
void dds3CrossfadeRun(void) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    dds3GetFrameID();
    sdfGrLinkDispFrameTex(0, 0, 0);
    sdfDrawTagLink(0, 0);
    sdf2DAllocSprite(0);
    sdf2DGetPrimPtr(0);
    sdfDrawTagLinkOt(0, 0);
    sdf2DLinkTexPacket(0, 0, 0);
    dds3CrossfadeEnd();
}

// 0x122a610
void dds3CrossfadeStart(u32 frame) {
    dds3CrossfadeEnd();
    dds3AllocRenderTexture(0, 0, 0);
    dds3RenderTextureON();
}

// 0x122a2b0
sdfTexHandle_t *dds3GetRenderTexture(void) {
  return 0;
}

// 0x122a420
void *effPkt2DAllocF4(u32 prim) {
    sdfGrAllocPacketBuff(0);
    return 0;
}

// 0x122a340
void *effPkt2DAllocTriStrip(s32 num, u32 prim) {
  s32 v6;
  Il2CppObject *v8;

  v6 = sdf2DGetPrimPacketSize(9, num);
  v8 = sdfGrAllocPacketBuff(v6);
  sdf2DMakePrimPacketHeader_24943632(v8, prim | 0x54, 9, 0, num);
  return v8;
}

// 0x122a2c0
void *effPkt2DGetPrimPtr(void *pPkt) {
    return 0;
}

// 0x122a600
void *effPkt3DPrimMakePoly(sdf3DPrimPolyParm_t *aParm) {
  return 0;
}

// 0x122a210
void sdfSetPacketHeader(sdfGrPacketHeader_t *aHdr, s32 aSize) {
  ;
}

// 0x122a2a0
void sdfSetPacketHeaderN(sdfGrPacketHeader_t *aHdr, s32 n) {
  ;
}
