#include "types.h"

typedef struct sdfCdImageDirEntry_t sdfCdImageDirEntry_t;

static char *sdfCdImageFileName;
static void *sdfCdImageIopBuff;
static u32 sdfCdImageLSN;
static sdfCdImageDirEntry_t *sdfCdImageDirData;
static sdfCdImageDirEntry_t *sdfCdImageCurrFile;
static s32 sdfCdImageCurrRemain;
static u8 sdfCdImageCurrActiveBuff[2048];
static u8 sdfCdImageCurrActivePtr;
static s32 sdfCdImageCurrActive;
static s32 sdfCdSemaId;
static u32 sdfCdStCurrLoc;
static u8 sdfCdImageMode;
static sdfCdImageDirEntry_t *sdfCdImageSearchFileDirect_ent;

sdfCdImageDirEntry_t *sdfCdImageSearchFile(char *fname, u32 lsn, u8 modePtr);

// 0x17e1100
s32 sdfCdImageCheckExist(char *fname) {
  u8 v2;

  return sdfCdImageSearchFile(fname, v2) != 0;
}

// 0x17e1070
void sdfCdImageClose(void) {
  sdfCd_c *v2;
  struct sdfCd_StaticFields *static_fields;

  static_fields = v2->static_fields;
  if (static_fields->sdfCdImageCurrFile)
  {
    static_fields->sdfCdImageCurrFile = 0;
  }
}

// 0x17e1200
s32 sdfCdImageGetCurrFileSize(void) {
  return sdfCdImageCurrFile->size_;
}

// 0x17e0930
sdfCdImageDirEntry_t *sdfCdImageGetDirData(void) {
  return sdfCdImageDirData;
}

// 0x17e1170
s32 sdfCdImageGetFileSize(char *fname) {
  u8 v2;
  sdfCdImageDirEntry_t_o *v5;

  else
  {
    v5 = sdfCdImageSearchFile(fname, v2);
    if (v5)
      return v5->size_;
  }
  return -1;
}

// 0x17e1280
void sdfCdImageInit(char *imageFile, char *dirFile) {
  sdfCdImageFileName = imageFile;
}

// 0x17e1270
void sdfCdImageLoadDir(char *dirFile) {
  ;
}

// 0x17e0cc0
s32 sdfCdImageLoadStart(char *fname) {
  sdfCdImageDirEntry_t_o *v5;
  sdfCdImageDirEntry_t_o *v7;
  u32 v10;
  u8 v11;

  v5 = sdfCdImageSearchFile(fname, v10, v11);
  if (!v5)
    return -1;
  v7 = v5;
  sdfCdImageCurrFile = v7;
  sdfCdImageCurrRemain = v7->size_;
  sdfCdImageCurrActive = 0;
  return v7->size_;
}

// 0x17e0dd0
s32 sdfCdImageRead(void *buff, s32 length) {
    return 0;
}

// 0x17e0b40
sdfCdImageDirEntry_t *sdfCdImageSearchFile(char *fname, u32 lsn, u8 modePtr) {
    return 0;
}

// 0x17e0ad0
sdfCdImageDirEntry_t *sdfCdImageSearchFileDirect(char *fname, u32 lsn, u8 modePtr) {
  return sdfCdImageSearchFileDirect_ent;
}

// 0x17e12f0
void sdfCdInit(void) {
  ;
}

// 0x17e0a20
void sdfCdStRead(s32 sectorCount, void *buff) {
  {
    if ((byte_3F5A8B5 & 1) == 0)
  }
  if ((byte_3F5A8B5 & 1) != 0)
}

// 0x17e09b0
void sdfCdStStart(u32 lsn) {

}

// 0x17e09a0
void sdfCdWaitTrayClose(void) {
  ;
}
