#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfRingStrmCB_t sdfRingStrmCB_t;
typedef struct sdfRingStrm_aCallbackDelegate sdfRingStrm_aCallbackDelegate;

static sdfRingStrmCB_t *sdfRingStrmCB;
static sdfMemHandle_t *ringStrmReadThStkMemHandle;
static s32 ringStrmReadThId;

// 0x17aa420
void sdfRingStrmClose(void) {
  else if (ringStrmReadThId == -1)
  {
    return;
  }
}

// 0x17aa2c0
void *sdfRingStrmDemand(s32 aLeng) {
    return 0;
}

// 0x17aa400
void sdfRingStrmEnd(void) {
  ;
}

// 0x17aa250
s32 sdfRingStrmGetReadyLength(void) {
    return 0;
  return 0;
}

// 0x17aa240
void sdfRingStrmIRelease(void) {
  ;
}

// 0x17aa410
void sdfRingStrmInit(s32 aBlockSize, s32 aNumOfBlock) {
  ;
}

// 0x17a9fe0
s32 sdfRingStrmIsReadEnd(void) {
  return sdfRingStrmCB->readStat == 2;
}

// 0x17aa060
void sdfRingStrmReadThread(void *aDummy) {
  struct sdfRingStrmCB_t_o *sdfRingStrmCB;
  signed s32 blockSize;
  char readStat;
  u16 blockTail;
  u16 v7;
  s32 readSize;
  s32 readProgress;
  s32 activeLeng;
  signed s32 v11;
  s32 numOfBlock;
  u16 v13;
  s32 v14;

  blockSize = sdfRingStrmCB->blockSize;
  readStat = sdfRingStrmCB->readStat;
  do
  {
    while (1)
    {
      while (readStat == 1)
      {
        readSize = sdfRingStrmCB->readSize;
        readProgress = sdfRingStrmCB->readProgress;
        activeLeng = sdfRingStrmCB->activeLeng;
        v11 = readSize - readProgress;
        numOfBlock = sdfRingStrmCB->numOfBlock;
        v13 = sdfRingStrmCB->blockActive + 1;
        if (blockSize <= readSize - readProgress)
          v11 = blockSize;
        v14 = v11 + readProgress;
        sdfRingStrmCB->readProgress = v14;
        sdfRingStrmCB->activeLeng = v11 + activeLeng;
        sdfRingStrmCB->blockActive = v13;
        if (v14 == readSize)
        {
          readStat = 2;
          sdfRingStrmCB->readStat = 2;
        }
        else
        {
          readStat = 1;
        }
        blockTail = sdfRingStrmCB->blockTail;
        if (numOfBlock == (blockTail + 1))
          v7 = 0;
        else
          v7 = blockTail + 1;
        sdfRingStrmCB->blockTail = v7;
      }
      if (readStat != 3)
        break;
      readStat = 0;
      sdfRingStrmCB->readStat = 0;
    }
  }
  while (readStat != 4);
  sdfRingStrmCB->readStat = 0;
  ringStrmReadThId = -1;
}

// 0x17aa190
void sdfRingStrmRelease(void) {
  struct sdfRingStrmCB_t_o *sdfRingStrmCB;
  u16 blockLock;
  u32 numOfBlock;
  s32 dataPos;
  s32 readSize;
  u16 v8;
  char v9;

  blockLock = sdfRingStrmCB->blockLock;
  numOfBlock = sdfRingStrmCB->numOfBlock;
  dataPos = sdfRingStrmCB->dataPos;
  readSize = sdfRingStrmCB->readSize;
  v8 = sdfRingStrmCB->blockHead + blockLock;
  if (numOfBlock > v8)
    LOWORD(numOfBlock) = 0;
  sdfRingStrmCB->blockActive -= blockLock;
  sdfRingStrmCB->blockHead = v8 - numOfBlock;
  if (dataPos < readSize)
    v9 = 1;
  else
    v9 = 3;
  sdfRingStrmCB->stat = v9;
}

// 0x17aa3f0
void sdfRingStrmStart(char *aFilename, s32 aSize, sdfRingStrm_aCallbackDelegate *aCallback, void *aParam) {
  ;
}
