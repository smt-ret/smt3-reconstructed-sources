#include "types.h"

typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrTagStdReg_t sdfGrTagStdReg_t;
typedef struct sdfGsMemSlice_t sdfGsMemSlice_t;
typedef struct sdfPreDrawHook_t sdfPreDrawHook_t;
typedef struct sdfPreDrawTag_t sdfPreDrawTag_t;
typedef struct sdfPrimBitBltElem_t sdfPrimBitBltElem_t;
typedef struct sdfPrimBitBltPacket_t sdfPrimBitBltPacket_t;
typedef struct sdfPrimBoxLineElem_t sdfPrimBoxLineElem_t;
typedef struct sdfPrimF3Elem_t sdfPrimF3Elem_t;
typedef struct sdfPrimF4Elem_t sdfPrimF4Elem_t;
typedef struct sdfPrimFt3Elem_t sdfPrimFt3Elem_t;
typedef struct sdfPrimFt4Elem_t sdfPrimFt4Elem_t;
typedef struct sdfPrimG3Elem_t sdfPrimG3Elem_t;
typedef struct sdfPrimG4Elem_t sdfPrimG4Elem_t;
typedef struct sdfPrimGt3Elem_t sdfPrimGt3Elem_t;
typedef struct sdfPrimGt4Elem_t sdfPrimGt4Elem_t;
typedef struct sdfPrimLineElem_t sdfPrimLineElem_t;
typedef struct sdfPrimRectElem_t sdfPrimRectElem_t;
typedef struct sdfPrimSpriteElem_t sdfPrimSpriteElem_t;
typedef struct sdfPrimTexflushPacket_t sdfPrimTexflushPacket_t;
typedef struct sdfPrimTransElem_t sdfPrimTransElem_t;
typedef struct sdfPrimTransPacket_t sdfPrimTransPacket_t;
typedef struct sdfPrim_aFuncDelegate sdfPrim_aFuncDelegate;

s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);

// 0x17a6e60
sdfDrawTag_t *sdfPrimAllocDrawTag(void *aAllocator) {
    sdfDrawTagInit(0);
    return 0;
}

// 0x17a7d20
void sdfPrimFrameMovePredraw(sdfPreDrawHook_t *aPre, s32 aEvenOdd) {
  ;
}

// 0x17a7d10
void sdfPrimLinkBitBltPacket(sdfDrawTag_t *aTag, u32 aDstGsAddr, s32 aDstBuffWidth, s32 aDstPixelFormat, s32 aDstX, s32 aDstY, u32 aSrcGsAddr, s32 aSrcBuffWidth, s32 aSrcPixelFormat, s32 aSrcX, s32 aSrcY, s32 aWidth, s32 aHeight, s32 aDirMode, void *aAllocator) {
  ;
}

// 0x17a7eb0
void sdfPrimLinkBoxLine(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7d70
void sdfPrimLinkF3(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, s32 aX2, s32 aY2, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7d90
void sdfPrimLinkF4(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, s32 aX2, s32 aY2, s32 aX3, s32 aY3, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7d30
void sdfPrimLinkFrameMovePacket(sdfDrawTag_t *aDrawTag, sdfPreDrawTag_t *aPreDrawTag, sdfGsMemSlice_t *aBuffHandle, s32 aDstX, s32 aDstY, s32 aSrcX, s32 aSrcY, s32 aWidth, s32 aHeight, s32 aFrameSw, void *aAllocator) {
  ;
}

// 0x17a7df0
void sdfPrimLinkFt3(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7e10
void sdfPrimLinkFt4(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, s32 aX3, s32 aY3, s32 aU3, s32 aV3, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7db0
void sdfPrimLinkG3(sdfDrawTag_t *aTag, u32 aPrim, s32 aX0, s32 aY0, u32 aColor0, s32 aX1, s32 aY1, u32 aColor1, s32 aX2, s32 aY2, u32 aColor2, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7dd0
void sdfPrimLinkG4(sdfDrawTag_t *aTag, u32 aPrim, s32 aX0, s32 aY0, u32 aColor0, s32 aX1, s32 aY1, u32 aColor1, s32 aX2, s32 aY2, u32 aColor2, s32 aX3, s32 aY3, u32 aColor3, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7e30
void sdfPrimLinkGt3(sdfDrawTag_t *aTag, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, u32 aColor0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, u32 aColor1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, u32 aColor2, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7e50
void sdfPrimLinkGt4(sdfDrawTag_t *aTag, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, u32 aColor0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, u32 aColor1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, u32 aColor2, s32 aX3, s32 aY3, s32 aU3, s32 aV3, u32 aColor3, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7e90
void sdfPrimLinkLine(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7e70
void sdfPrimLinkRect(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7420
void sdfPrimLinkSimplePacket(sdfDrawTag_t *aTag, sdfPrim_aFuncDelegate *aFunc, s32 aPacketSize, void *aAllocator) {
    sdfDrawTagLink(0, 0);
}

// 0x17a7d50
void sdfPrimLinkSprite(sdfDrawTag_t *aTag, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, u32 aZ, void *aAllocator) {
  ;
}

// 0x17a7c60
void sdfPrimSetAddTrans2Elem(sdfPrimTransElem_t *aElem) {
  ;
}

// 0x17a7c80
void sdfPrimSetAddTrans2Packet(sdfPrimTransPacket_t *aPkt) {
  ;
}

// 0x17a7c50
void sdfPrimSetAddTransElem(sdfPrimTransElem_t *aElem) {
  ;
}

// 0x17a7c70
void sdfPrimSetAddTransPacket(sdfPrimTransPacket_t *aPkt) {
  ;
}

// 0x17a7cf0
void sdfPrimSetBitBltElem(sdfPrimBitBltElem_t *aElem, u32 aDstGsAddr, s32 aDstBuffWidth, s32 aDstPixelFormat, s32 aDstX, s32 aDstY, u32 aSrcGsAddr, s32 aSrcBuffWidth, s32 aSrcPixelFormat, s32 aSrcX, s32 aSrcY, s32 aWidth, s32 aHeight, s32 aDirMode) {
  ;
}

// 0x17a7d00
void sdfPrimSetBitBltPacket(sdfPrimBitBltPacket_t *aPacket, u32 aDstGsAddr, s32 aDstBuffWidth, s32 aDstPixelFormat, s32 aDstX, s32 aDstY, u32 aSrcGsAddr, s32 aSrcBuffWidth, s32 aSrcPixelFormat, s32 aSrcX, s32 aSrcY, s32 aWidth, s32 aHeight, s32 aDirMode) {
  ;
}

// 0x17a7ea0
void sdfPrimSetBoxLineElem(sdfPrimBoxLineElem_t *aElem, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, u32 aZ) {
  ;
}

// 0x17a7d60
void sdfPrimSetF3Elem(sdfPrimF3Elem_t *aElem, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, s32 aX2, s32 aY2, u32 aZ) {
  ;
}

// 0x17a7d80
void sdfPrimSetF4Elem(sdfPrimF4Elem_t *aElem, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, s32 aX2, s32 aY2, s32 aX3, s32 aY3, u32 aZ) {
  ;
}

// 0x17a7de0
void sdfPrimSetFt3Elem(sdfPrimFt3Elem_t *aElem, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, u32 aZ) {
  ;
}

// 0x17a7e00
void sdfPrimSetFt4Elem(sdfPrimFt4Elem_t *aElem, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, s32 aX3, s32 aY3, s32 aU3, s32 aV3, u32 aZ) {
  ;
}

// 0x17a7da0
void sdfPrimSetG3Elem(sdfPrimG3Elem_t *aElem, u32 aPrim, s32 aX0, s32 aY0, u32 aColor0, s32 aX1, s32 aY1, u32 aColor1, s32 aX2, s32 aY2, u32 aColor2, u32 aZ) {
  ;
}

// 0x17a7dc0
void sdfPrimSetG4Elem(sdfPrimG4Elem_t *aElem, u32 aPrim, s32 aX0, s32 aY0, u32 aColor0, s32 aX1, s32 aY1, u32 aColor1, s32 aX2, s32 aY2, u32 aColor2, s32 aX3, s32 aY3, u32 aColor3, u32 aZ) {
  ;
}

// 0x17a7e20
void sdfPrimSetGt3Elem(sdfPrimGt3Elem_t *aElem, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, u32 aColor0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, u32 aColor1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, u32 aColor2, u32 aZ) {
  ;
}

// 0x17a7e40
void sdfPrimSetGt4Elem(sdfPrimGt4Elem_t *aElem, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, u32 aColor0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, u32 aColor1, s32 aX2, s32 aY2, s32 aU2, s32 aV2, u32 aColor2, s32 aX3, s32 aY3, s32 aU3, s32 aV3, u32 aColor3, u32 aZ) {
  ;
}

// 0x17a7e80
void sdfPrimSetLineElem(sdfPrimLineElem_t *aElem, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, u32 aZ) {
  ;
}

// 0x17a7be0
void sdfPrimSetOpaque2Elem(sdfPrimTransElem_t *aElem) {
  ;
}

// 0x17a7c00
void sdfPrimSetOpaque2Packet(sdfPrimTransPacket_t *aPkt) {
  ;
}

// 0x17a7bd0
void sdfPrimSetOpaqueElem(sdfPrimTransElem_t *aElem) {
  ;
}

// 0x17a7bf0
void sdfPrimSetOpaquePacket(sdfPrimTransPacket_t *aPkt) {
  ;
}

// 0x17a7e60
void sdfPrimSetRectElem(sdfPrimRectElem_t *aElem, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aX1, s32 aY1, u32 aZ) {
  ;
}

// 0x17a7c20
void sdfPrimSetSemiTrans2Elem(sdfPrimTransElem_t *aElem) {
  ;
}

// 0x17a7c40
void sdfPrimSetSemiTrans2Packet(sdfPrimTransPacket_t *aPkt) {
  ;
}

// 0x17a7c10
void sdfPrimSetSemiTransElem(sdfPrimTransElem_t *aElem) {
  ;
}

// 0x17a7c30
void sdfPrimSetSemiTransPacket(sdfPrimTransPacket_t *aPkt) {
  ;
}

// 0x17a7d40
void sdfPrimSetSpriteElem(sdfPrimSpriteElem_t *aElem, u32 aColor, u32 aPrim, s32 aX0, s32 aY0, s32 aU0, s32 aV0, s32 aX1, s32 aY1, s32 aU1, s32 aV1, u32 aZ) {
  ;
}

// 0x17a7ca0
void sdfPrimSetSubTrans2Elem(sdfPrimTransElem_t *aElem) {
  ;
}

// 0x17a7cc0
void sdfPrimSetSubTrans2Packet(sdfPrimTransPacket_t *aPkt) {
  ;
}

// 0x17a7c90
void sdfPrimSetSubTransElem(sdfPrimTransElem_t *aElem) {
  ;
}

// 0x17a7cb0
void sdfPrimSetSubTransPacket(sdfPrimTransPacket_t *aPkt) {
  ;
}

// 0x17a7cd0
void sdfPrimSetTexflushElem(sdfGrTagStdReg_t *aElem) {
  aElem->data = 0;
  aElem->reg = 63;
}

// 0x17a7ce0
void sdfPrimSetTexflushPacket(sdfPrimTexflushPacket_t *aPkt) {
  struct sdfGrTagStdReg_t_o *texflush;

  texflush = aPkt->texflush;
  texflush->data = 0;
  texflush->reg = 63;
}
