#include "types.h"

typedef struct debug_tag debug_tag;
typedef struct sdfFileCmdCallback_t sdfFileCmdCallback_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfFileDeviceCB_t sdfFileDeviceCB_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static sdfFileDeviceCB_t *sdfFileDeviceCB[4];
static sdfFileCmdHandle_t *sdfFileCmdQueueHead;
static sdfFileCmdHandle_t *sdfFileCmdQueueTail;
static s16 sdfFileCmdFreeQueueCount;
static sdfFileCmdHandle_t *sdfFileCmdFreeQueueHead;
static sdfFileCmdHandle_t *sdfFileCmdFreeQueueTail;
static s16 sdfFileCmdQueueCount;
static u8 sdfFileCmdDefaultDevice;
static u8 sdfFileCmdThreadPrioCheckCounter;
static s32 sdfFileCmdThreadPrio;
static u16 sdfFileCmdDefaultCreateMode;

char *ChangeCharacter(char *sourceString, s32 charIndex, u16 newChar);
char *StrChr(char *stringToSearch, u16 charToFind);
s32 sdfCdImageLoadStart(char *fname);
s32 sdfCdImageRead(void *buff, s32 length);
void *sdfChipAllocRecord(s32 aSize, char *aFile, s32 aLine);
void *sdfChipAllocZeroRecord(s32 aSize, char *aFile, s32 aLine);
void sdfChipFreeDirect(void *aPtr);
void sdfChipPurgeRecord(void *aPtr, char *aFile, s32 aLine);
s32 sdfCreateSema(s32 initCount, s32 maxCount, s32 option);
s32 sdfFileCmdAnalyzeFileName(char *aFileName, char **aRealNamePtr);
void sdfFileCmdEntry(sdfFileCmdHandle_t *aHandle);
void sdfFileCmdError(sdfFileCmdHandle_t *aHandle, s32 aError);
char *sdfFileCmdMakeRealFileName(char *aSrcName, s32 aDeviceType);
void sdfFileCmdReleaseHandle(sdfFileCmdHandle_t *aHandle);
void sdfFileCmdStartThread(s32 deviceType);
void sdfFileCmdThreadSetPrio(s32 prio);
void sdfFileCmdUnlink(sdfFileCmdHandle_t *aHandle);
sdfMemHandle_t *sdfMemAllocRecord(s32 aSize, char *aFile, s32 aLine);
debug_tag *sdfMemLock(void *aHandle);

// 0x17ec720
void sdfFileCdImageCmdThread(void *aCB) {
    sdfCdImageLoadStart(0);
    sdfCdImageRead(0, 0);
    sdfFileCmdUnlink(0);
    sdfMemAllocRecord(0, 0, 0);
    sdfMemLock(0);
    sdfFileCmdError(0, 0);
}

// 0x17ed730
s32 sdfFileCmdAnalyzeFileName(char *aFileName, char **aRealNamePtr) {
  bool v7;
  s32 v8;
  s32 sdfFileCmdDefaultDevice;
  sdfFileIO_c *v10;

  if (!StrChr(aFileName, 0x3Au))
  {
    if ((v10->_2.bitflags2 & 2) == 0)
  }
  if (op_Equality(aFileName, StringLiteral_22004, 0))
  {
    v7 = EndsWith(aFileName, StringLiteral_19164);
    if (v7)
      v8 = 0;
    else
      v8 = 7;
    if (v7)
      sdfFileCmdDefaultDevice = 3;
    else
      sdfFileCmdDefaultDevice = 0;
  }
  else
  {
    if (op_Equality(aFileName, StringLiteral_22005, 0))
    {
      sdfFileCmdDefaultDevice = 1;
    }
    else
    {
      if (op_Equality(aFileName, StringLiteral_22006, 0))
      {
        sdfFileCmdDefaultDevice = 2;
        v8 = 5;
      }
      if (!op_Equality(aFileName, StringLiteral_22007, 0))
        return -1;
      sdfFileCmdDefaultDevice = 3;
    }
    v8 = 6;
  }
  aFileName = Substring(aFileName, v8);
  {
  }
  *aRealNamePtr = sdfFileCmdMakeRealFileName(aFileName, sdfFileCmdDefaultDevice);
  return sdfFileCmdDefaultDevice;
}

// 0x17eb740
s32 sdfFileCmdClearError(sdfFileCmdHandle_t *aHandle) {
  if (aHandle->stat != 9)
    return -1;
  aHandle->stat = 7;
  aHandle->errorCode = 0;
  return 0;
}

// 0x17eb9a0
s32 sdfFileCmdClose(sdfFileCmdHandle_t *aHandle) {
  if (aHandle->stat != 7)
    return -1;
  aHandle->cmd = 7;
  return 0;
}

// 0x17ed160
void sdfFileCmdEnding(sdfFileCmdHandle_t *aHandle) {
    sdfFileCmdUnlink(0);
}

// 0x17ecd40
void sdfFileCmdEntry(sdfFileCmdHandle_t *aHandle) {
  sdfFileCmdHandle_t_o *v3;
  s64 device;
  struct sdfFileDeviceCB_t_array *sdfFileDeviceCB;

  v3 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v3);
  device = aHandle->device;
  if (sdfFileDeviceCB->m_Items[device]->thId < 0)
  {
    else
    {
      sdfFileCmdStartThread(device);
      aHandle->prev = v3;
      if (!v3)
    }
    v3->next = aHandle;
    aHandle->devicePrev = v3;
    v3->deviceNext = aHandle;
  }
  aHandle->prev = v3;
  if (v3)
  aHandle->devicePrev = 0;
  ++sdfFileCmdQueueCount;
}

// 0x17ec460
void sdfFileCmdError(sdfFileCmdHandle_t *aHandle, s32 aError) {
    sdfFileCmdUnlink(0);
}

// 0x17ebbe0
s32 sdfFileCmdFileSize(sdfFileCmdHandle_t *aHandle) {
  if (aHandle->stat != 7)
    return -1;
  aHandle->cmd = 4;
  return 0;
}

// 0x17eb9d0
s32 sdfFileCmdFree(sdfFileCmdHandle_t *aHandle) {
  if ((aHandle->stat - 7) > 1)
    return -1;
  sdfFileCmdReleaseHandle(aHandle);
  return 0;
}

// 0x17ed1e0
char *sdfFileCmdMakeRealFileName(char *aSrcName, s32 aDeviceType) {
    sdfChipAllocRecord(0, 0, 0);
    ChangeCharacter(0, 0, 0);
    return 0;
}

// 0x17ed8d0
sdfFileCmdHandle_t *sdfFileCmdNewHandle(char *aFileName, s32 aDeviceType, s32 aCmd, sdfFileCmdCallback_t *aCallback, void *aUserData) {
    sdfChipAllocZeroRecord(0, 0, 0);
    return 0;
}

// 0x17ebb00
s32 sdfFileCmdRead(sdfFileCmdHandle_t *aHandle, void *aBuffer, s32 aLength) {
  if (aHandle->stat != 7)
    return -1;
  aHandle->cmd = 5;
  aHandle->length = aLength;
  aHandle->buffer = aBuffer;
  return 0;
}

// 0x17edbf0
sdfFileCmdHandle_t *sdfFileCmdReadFile(char *aFileName, void *aBuffer, s32 aLength, sdfFileCmdCallback_t *aCallback, void *aUserData) {
  s16 v6;
  sdfFileCmdHandle_t_o *v9;
  System_String_o *aRealNamePtr;

  v6 = aLength;
  aRealNamePtr = StringLiteral_416;
  v9 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v9);
  if (sdfFileCmdAnalyzeFileName(aFileName, &aRealNamePtr) < 0)
    return 0;
  v9->offset = 0;
  v9->length = v6;
  v9->buffer = aBuffer;
  sdfFileCmdEntry(v9);
  return v9;
}

// 0x17eb660
sdfFileCmdHandle_t *sdfFileCmdReadOpen(char *aFileName, sdfFileCmdCallback_t *aCallback, void *aUserData) {
  u64 *v5;
  System_String_o *aRealNamePtr;

  aRealNamePtr = StringLiteral_416;
  v5 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v5);
  if (sdfFileCmdAnalyzeFileName(aFileName, &aRealNamePtr) < 0)
    return 0;
  sdfFileCmdEntry(v5);
  return v5;
}

// 0x17ecfe0
void sdfFileCmdReleaseHandle(sdfFileCmdHandle_t *aHandle) {
  u64 *v3;
  u64 *v4;
  System_String_o *v5;
  s32 v6;
  struct sdfFileCmdHandle_t_o *next;
  struct sdfFileCmdHandle_t_o *prev;
  struct System_Char_array *filename;

  v3 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v3);
  v4 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v4);
  next = aHandle->next;
  prev = aHandle->prev;
  if (prev)
    prev->next = next;
  if (next)
    next->prev = prev;
  --sdfFileCmdFreeQueueCount;
  filename = aHandle->filename;
  if (filename)
  {
    sdfChipPurgeRecord(&filename->obj, v5, v6);
    sdfChipFreeDirect(&filename->obj);
  }
  sdfChipPurgeRecord(aHandle, v5, v6);
  sdfChipFreeDirect(aHandle);
}

// 0x17ebce0
s32 sdfFileCmdSeek(sdfFileCmdHandle_t *aHandle, s32 aOffset, s32 aWhence) {
  if (aHandle->stat != 7)
    return -1;
  aHandle->cmd = 3;
  aHandle->offset = aOffset;
  aHandle->cmdParm = aWhence;
  return 0;
}

// 0x17ebfc0
void sdfFileCmdSetDefaultSrc(s32 aType) {
  u8 v2;

  v2 = aType;
  sdfFileCmdDefaultDevice = v2;
}

// 0x17eceb0
void sdfFileCmdStartThread(s32 deviceType) {
  struct sdfFileDeviceCB_t_array *sdfFileDeviceCB;
  sdfFileDeviceCB_t_o *v5;
  s32 thId;

  v5 = sdfFileDeviceCB->m_Items[deviceType];
  thId = v5->thId;
  if (thId < 0)
  {
    v5->semaId = sdfCreateSema(0, 255, 0);
    sdfFileCmdThreadPrio = 72;
    v5->thId = thId;
  }
}

// 0x17ec150
void sdfFileCmdThread(void *aCB) {
    sdfFileCmdUnlink(0);
    sdfFileCmdError(0, 0);
    sdfMemAllocRecord(0, 0, 0);
    sdfMemLock(0);
}

// 0x17ee020
void sdfFileCmdThreadCheckPrio(void) {
  struct sdfFileIO_StaticFields *static_fields;
  s32 sdfFileCmdThreadPrioCheckCounter;
  s32 v5;

  else
  {
    static_fields = sdfFileIO->static_fields;
    sdfFileCmdThreadPrioCheckCounter = static_fields->sdfFileCmdThreadPrioCheckCounter;
    if (!static_fields->sdfFileCmdThreadPrioCheckCounter)
      return;
  }
  else
  {
    v5 = sdfFileCmdThreadPrioCheckCounter - 1;
    static_fields->sdfFileCmdThreadPrioCheckCounter = v5;
    if (v5)
      return;
  }
  sdfFileCmdThreadSetPrio(72);
}

// 0x17edfb0
void sdfFileCmdThreadSetHiPrio(void) {
  sdfFileCmdThreadSetPrio(72);
}

// 0x17edf40
void sdfFileCmdThreadSetLoPrio(void) {
  sdfFileCmdThreadPrioCheckCounter = 3;
  sdfFileCmdThreadSetPrio(120);
}

// 0x17ede30
void sdfFileCmdThreadSetPrio(s32 prio) {
  struct sdfFileIO_StaticFields *static_fields;
  u32 v5;

  else
  {
    static_fields = sdfFileIO->static_fields;
    if (static_fields->sdfFileCmdThreadPrio == prio)
      return;
  }
  v5 = 0;
  static_fields->sdfFileCmdThreadPrio = prio;
  do
  {
    ++v5;
  }
  while (v5 < SLODWORD(sdfFileDeviceCB->max_length));
}

// 0x17ec590
void sdfFileCmdUnlink(sdfFileCmdHandle_t *aHandle) {
  u64 *v3;
  u64 *v4;
  sdfFileCmdHandle_t_o *v5;
  struct sdfFileCmdHandle_t_o *next;
  struct sdfFileCmdHandle_t_o *prev;
  struct sdfFileCmdHandle_t_o *deviceNext;
  struct sdfFileCmdHandle_t_o *devicePrev;
  sdfFileIO_c *v13;
  struct sdfFileIO_StaticFields *static_fields;

  v3 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v3);
  v4 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v4);
  v5 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v5);
  next = aHandle->next;
  prev = aHandle->prev;
  if (prev)
    prev->next = next;
  if (next)
    next->prev = prev;
  deviceNext = aHandle->deviceNext;
  devicePrev = aHandle->devicePrev;
  if (devicePrev)
    devicePrev->deviceNext = deviceNext;
  if (deviceNext)
    deviceNext->devicePrev = devicePrev;
  aHandle->prev = v5;
  if (v5)
    v5->next = aHandle;
  aHandle->next = 0;
  ++sdfFileCmdFreeQueueCount;
  --sdfFileCmdQueueCount;
  static_fields = v13->static_fields;
  if (static_fields->sdfFileCmdFreeQueueCount >= 9)
  {
    sdfFileCmdReleaseHandle(static_fields->sdfFileCmdFreeQueueHead);
  }
}

// 0x17edbc0
s32 sdfFileCmdWrite(sdfFileCmdHandle_t *aHandle, void *aBuffer, s32 aLength) {
  if (aHandle->stat != 7)
    return -1;
  aHandle->cmd = 6;
  aHandle->length = aLength;
  aHandle->buffer = aBuffer;
  return 0;
}

// 0x17edcf0
sdfFileCmdHandle_t *sdfFileCmdWriteFile(char *aFileName, void *aBuffer, s32 aLength, sdfFileCmdCallback_t *aCallback, void *aUserData, s32 aMode) {
  s16 v8;
  sdfFileCmdHandle_t_o *v11;
  sdfFileIO_c *v15;
  System_String_o *aRealNamePtr;

  v8 = aLength;
  aRealNamePtr = StringLiteral_416;
  v11 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v11);
  if (sdfFileCmdAnalyzeFileName(aFileName, &aRealNamePtr) < 0)
    return 0;
  v11->offset = 0;
  v11->length = v8;
  v11->buffer = aBuffer;
  if (!aMode)
  {
    v11->cmdParm = sdfFileCmdDefaultCreateMode;
    if ((v15->_2.bitflags2 & 2) == 0)
  }
  v11->cmdParm = aMode;
  sdfFileCmdEntry(v11);
  return v11;
}

// 0x17eda90
sdfFileCmdHandle_t *sdfFileCmdWriteOpen(char *aFileName, sdfFileCmdCallback_t *aCallback, void *aUserData, s32 aMode) {
  sdfFileCmdHandle_t_o *v7;
  sdfFileIO_c *v11;
  System_String_o *aRealNamePtr;

  aRealNamePtr = StringLiteral_416;
  v7 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v7);
  if (sdfFileCmdAnalyzeFileName(aFileName, &aRealNamePtr) < 0)
    return 0;
  if (!aMode)
  {
    v7->cmdParm = sdfFileCmdDefaultCreateMode;
    if ((v11->_2.bitflags2 & 2) == 0)
  }
  v7->cmdParm = aMode;
  sdfFileCmdEntry(v7);
  return v7;
}
