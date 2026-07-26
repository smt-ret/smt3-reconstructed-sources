#include "types.h"

typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfIopFileWork_t sdfIopFileWork_t;

static s32 sdfIopFileInitThId;
static sdfIopFileWork_t *sdfIopFileWork;
static u8 sdfIopFileDataBuff[256];
static u8 sdfIopFileReBuff[64];
static u8 sdfIopFileReadBuff[16384];

// 0x1793700
s32 sdfIopFileCallback(sdfFileCmdHandle_t *fileHandle, s32 cause, void *buffer, s32 length, void *data) {
  return 0;
}

// 0x1793790
void sdfIopFileInit(void) {
  ;
}

// 0x1793690
void sdfIopFileReadSub(void) {

}

// 0x1793710
void *sdfIopFileService(u32 funcNum, void *data, s32 size) {
  return &sdfIopFileReBuff->obj;
}

// 0x1793780
void sdfIopFileThread(void *dummy) {
  ;
}
