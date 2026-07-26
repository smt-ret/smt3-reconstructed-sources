#include "types.h"

typedef struct sdfBillBoard1Packet_t sdfBillBoard1Packet_t;
typedef struct sdfBillBoardTMPacket_t sdfBillBoardTMPacket_t;
typedef struct sdfBillBoardVc1Packet_t sdfBillBoardVc1Packet_t;
typedef struct sdfMultiBillBoard1Packet_t sdfMultiBillBoard1Packet_t;
typedef struct sdfMultiBillBoardVc1Packet_t sdfMultiBillBoardVc1Packet_t;

// 0x17e03f0
s32 sdfBillBoardGetPacketSize(s32 aNum) {
  return (((aNum << 6) | 0x3C) + 15) & 0xFFFFFFC0;
}

// 0x17e03e0
void sdfBillBoardMake1(sdfBillBoard1Packet_t *aPacket, sdfVector4_t aCenter, u32 aColor, u16 aUVList, f32 **aXYOffsetList) {
  ;
}

// 0x17e0410
void *sdfBillBoardMakeN(sdfVector4_t aCenter, u32 aColor, u16 aUVList, f32 aXYOffsetList, s32 aNum, void *aAllocator) {
  return 0;
}

// 0x17e03d0
void sdfBillBoardMakeTMPacket(sdfBillBoardTMPacket_t *aPacket, sdfMatrix4_t *aTM) {
  ;
}

// 0x17e0470
s32 sdfBillBoardVcGetPacketSize(s32 aNum) {
  return (76 * aNum + 75) & 0xFFFFFFF0;
}

// 0x17e0460
void sdfBillBoardVcMake1(sdfBillBoardVc1Packet_t *aPacket, sdfVector4_t aCenter, u32 **aColor, u16 aUVList, f32 **aXYOffsetList) {
  ;
}

// 0x17e0490
void *sdfBillBoardVcMakeN(sdfVector4_t aCenter, u32 aColor, u16 aUVList, f32 aXYOffsetList, s32 aNum, void *aAllocator) {
  return 0;
}

// 0x17e0430
s32 sdfMultiBillBoardGetPacketSize(s32 aNum) {
  return (84 * aNum + 75) & 0xFFFFFFF0;
}

// 0x17e0420
void sdfMultiBillBoardMake1(sdfMultiBillBoard1Packet_t *aPacket, sdfVector4_t aCenter, u32 aColor0, u32 aColor1, u16 aUVList0, u16 aUVList1, f32 **aXYOffsetList) {
  ;
}

// 0x17e0450
void *sdfMultiBillBoardMakeN(sdfVector4_t aCenter, u32 aColor, u16 aUVList, f32 aXYOffsetList, s32 aNum, void *aAllocator) {
  return 0;
}

// 0x17e04b0
s32 sdfMultiBillBoardVcGetPacketSize(s32 aNum) {
  return (108 * aNum + 75) & 0xFFFFFFF0;
}

// 0x17e04a0
void sdfMultiBillBoardVcMake1(sdfMultiBillBoardVc1Packet_t *aPacket, sdfVector4_t aCenter, u32 aColor, u16 aUVList0, u16 aUVList1, f32 aXYOffsetList) {
  ;
}

// 0x17e04d0
void *sdfMultiBillBoardVcMakeN(sdfVector4_t aCenter, u32 aColor, u16 aUVList, f32 aXYOffsetList, s32 aNum, void *aAllocator) {
  return 0;
}
