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
  sdfFileCmdHandle_t_o *v2;
  s32 cmd;
  struct System_Char_array *filename;
  System_String_o *v8;
  sdfFileCmdCallback_t_o *callback;
  u64 *v10;
  Il2CppObject *userData;
  Il2CppObject *v12;
  sdfFileCmdCallback_t_o *v13;
  sdfFileCmdHandle_t_o *v14;
  s32 v15;
  sdfFileCmdCallback_t_o *v16;
  s32 v20;
  Il2CppObject *buffer;
  s32 length;
  s32 v23;
  u32 v24;
  sdfFileCmdCallback_t_o *v27;
  u64 *v28;
  struct System_Char_array *v29;
  System_String_o *v31;
  s32 v39;
  s32 v41;

  v2 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v2);
  while (1)
  {
    while (!v2)
      ;
    cmd = v2->cmd;
    v2->cmd = 0;
    switch (cmd)
    {
      case 1:
        filename = v2->filename;
        v2->stat = 2;
        v8 = (filename->obj.klass->vtable[3].methodPtr)(filename, filename->obj.klass->vtable[3].method);
        else if ((sdfCdImageLoadStart(v8) & 0x80000000) == 0)
        {
LABEL_13:
          callback = v2->callback;
          v2->stat = 7;
          v2->currentOffset = 0;
          if (callback)
          {
            v41 = 0;
            v10 = sub_8D3950(s32, &v41);
            userData = v2->userData;
            v12 = v10;
            v13 = callback;
            v14 = v2;
            v15 = 2;
LABEL_46:
            v20 = 0;
            goto LABEL_102;
          }
        }
        continue;
      case 2:
      case 3:
      case 6:
      case 9:
        goto LABEL_7;
      case 4:
        v16 = v2->callback;
        v2->stat = 7;
        if (!v16)
          continue;
        else if ((byte_3F5A8BD & 1) != 0)
        {
          goto LABEL_20;
        }
        goto LABEL_20;
      case 5:
        v2->stat = 4;
        buffer = v2->buffer;
        length = v2->length;
        v23 = sdfCdImageRead(buffer, length);
        if (v23 < 0)
          goto LABEL_61;
        v13 = v2->callback;
        v24 = v2->currentOffset + v23;
        v2->stat = 7;
        v2->currentOffset = v24;
        if (!v13)
          continue;
        v12 = v2->buffer;
        userData = v2->userData;
        v14 = v2;
        v15 = 5;
        goto LABEL_101;
      case 7:
        v2->stat = 6;
        if ((byte_3F5A8BB & 1) == 0)
          goto LABEL_33;
LABEL_34:
        else
        {
          if (sdfCdImageCurrFile)
            goto LABEL_37;
        }
        sdfFileCmdUnlink(v2);
        v27 = v2->callback;
        v2->stat = 8;
        if (v27)
        {
          v39 = 0;
          v28 = sub_8D3950(s32, &v39);
          userData = v2->userData;
          v12 = v28;
          v13 = v27;
          v14 = v2;
          v15 = 7;
          goto LABEL_46;
        }
        continue;
      case 8:
        v29 = v2->filename;
        v2->stat = 2;
        v31 = (v29->obj.klass->vtable[3].methodPtr)(v29, v29->obj.klass->vtable[3].method);
        else
        {
          if ((sdfCdImageLoadStart(v31) & 0x80000000) == 0)
            goto LABEL_50;
LABEL_7:
          sdfFileCmdError(v2, 0);
        }
        break;
      default:
        continue;
    }
  }
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
      goto LABEL_25;
    goto LABEL_15;
  }
  if (op_Equality(aFileName, "cdrom0:", 0))
  {
    v7 = EndsWith(aFileName, "/movie/");
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
    if (op_Equality(aFileName, "host0:", 0))
    {
      sdfFileCmdDefaultDevice = 1;
    }
    else
    {
      if (op_Equality(aFileName, "pfs0:", 0))
      {
        sdfFileCmdDefaultDevice = 2;
        v8 = 5;
        goto LABEL_24;
      }
      if (!op_Equality(aFileName, "cdimg:", 0))
        return -1;
      sdfFileCmdDefaultDevice = 3;
    }
    v8 = 6;
  }
LABEL_24:
  aFileName = Substring(aFileName, v8);
  {
LABEL_15:
  }
LABEL_25:
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
  sdfFileCmdHandle_t_o *v3;

  aHandle->fd = -1;
  else
  {
    v3 = aHandle;
  }
  sdfFileCmdUnlink(v3);
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
        goto LABEL_16;
    }
LABEL_9:
    v3->next = aHandle;
    aHandle->devicePrev = v3;
    v3->deviceNext = aHandle;
      goto LABEL_17;
    goto LABEL_10;
  }
  aHandle->prev = v3;
  if (v3)
    goto LABEL_9;
LABEL_16:
  aHandle->devicePrev = 0;
    goto LABEL_17;
LABEL_10:
LABEL_17:
  ++sdfFileCmdQueueCount;
}

// 0x17ec460
void sdfFileCmdError(sdfFileCmdHandle_t *aHandle, s32 aError) {
  sdfFileCmdCallback_t_o *callback;
  u64 *v6;
  s32 v8;

  aHandle->stat = 9;
  aHandle->errorCode = aError;
LABEL_7:
  aHandle->fd = -1;
  else
  {
    sdfFileCmdUnlink(aHandle, *&aError);
    callback = aHandle->callback;
    if (!callback)
      return;
  }
  v8 = 0;
  v6 = sub_8D3950(s32, &v8);
  sdfFileCmdCallback_t__Invoke(callback, aHandle, 0, v6, 0, aHandle->userData);
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
  s32 Length;
  Il2CppObject *v8;
  char *v9;
  s64 *v10;
  System_String_o *v11;
  s32 i;
  u16 Chars;
  u16 v14;
  System_String_o *sdfFileHostRootPath;
  s32 v21;
  Il2CppObject *v22;
  char *v23;
  s64 *v24;
  Il2CppObject *v26;
  char *v27;
  s64 *v28;
  s64 *v29;
  Il2CppObject *v30;
  char *v31;
  s64 *v32;
  System_String_o *v33;
  System_String_o *v34;
  Il2CppObject *v35;
  char *v36;
  s64 *v37;
  u64 v39[2];
  char *v40;

  Length = get_Length(aSrcName);
  switch (aDeviceType)
  {
    case 0:
      v8 = sdfChipAllocRecord(Length + 10, 0, 0);
      if (v8 && v8->klass != string)
      {
        sub_8FC2C0(v8->klass->_1.element_class, string, v39);
        if ((v39[0] & 1) != 0)
          v9 = v40;
        else
          v9 = v39 + 1;
        v10 = sub_8C4940(v9);
      }
      v11 = "cdrom0:";
      for (i = 9; ; ++i)
      {
        Chars = get_Chars(aSrcName, i - 9);
        v14 = 92;
        if (Chars != 47)
        {
          if (!Chars)
          {
            v33 = ChangeCharacter(v11, i - 2, 0x3Bu);
            v34 = ChangeCharacter(v33, i - 1, 0x31u);
            return ChangeCharacter(v34, i, 0);
          }
          if ((Chars - 97) <= 0x19u)
            v14 = Chars - 32;
          else
            v14 = Chars;
        }
        v11 = ChangeCharacter(v11, i - 2, v14);
      }
    case 1:
      if (get_Chars(aSrcName, 0) == 47)
      {
        v21 = get_Length(sdfFileHostRootPath);
        v22 = sdfChipAllocRecord(v21 + Length, 0, 0);
        if (v22 && v22->klass != string)
        {
          sub_8FC2C0(v22->klass->_1.element_class, string, v39);
          if ((v39[0] & 1) != 0)
            v23 = v40;
          else
            v23 = v39 + 1;
          v24 = sub_8C4940(v23);
        }
        return Concat_5224608(sdfFileHostRootPath, aSrcName);
      }
      else
      {
        v35 = sdfChipAllocRecord(Length + 7, 0, 0);
        if (v35 && v35->klass != string)
        {
          sub_8FC2C0(v35->klass->_1.element_class, string, v39);
          if ((v39[0] & 1) != 0)
            v36 = v40;
          else
            v36 = v39 + 1;
          v37 = sub_8C4940(v36);
        }
        v29 = &"host0:";
        i = Length + 6;
LABEL_70:
        v34 = Concat_5224608(*v29, aSrcName);
        return ChangeCharacter(v34, i, 0);
      }
    case 2:
      v26 = sdfChipAllocRecord(Length + 6, 0, 0);
      if (v26 && v26->klass != string)
      {
        sub_8FC2C0(v26->klass->_1.element_class, string, v39);
        if ((v39[0] & 1) != 0)
          v27 = v40;
        else
          v27 = v39 + 1;
        v28 = sub_8C4940(v27);
      }
      v29 = &"pfs0:";
      i = Length + 5;
      goto LABEL_70;
    case 3:
      v30 = sdfChipAllocRecord(Length + 1, 0, 0);
      if (v30 && v30->klass != string)
      {
        sub_8FC2C0(v30->klass->_1.element_class, string, v39);
        if ((v39[0] & 1) != 0)
          v31 = v40;
        else
          v31 = v39 + 1;
        v32 = sub_8C4940(v31);
      }
      return aSrcName;
    default:
      return 0;
  }
}

// 0x17ed8d0
sdfFileCmdHandle_t *sdfFileCmdNewHandle(char *aFileName, s32 aDeviceType, s32 aCmd, sdfFileCmdCallback_t *aCallback, void *aUserData) {
  u8 v8;
  u8 v9;
  u64 *v11;
  s32 v15;
  Il2CppObject *v16;
  sdfFileCmdHandle_t_o *v17;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v20;
  s64 *v21;
  System_Char_array *v22;
  u64 v24[3];

  v8 = aCmd;
  v9 = aDeviceType;
  v11 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v11);
  {
  }
  v15 = SizeOf_sdfMemRecord_t_(v11);
  v16 = sdfChipAllocZeroRecord(v15, 0, 0);
  v17 = v16;
  if (v16)
  {
    klass = v16->klass;
    if (v16->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfFileCmdHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfFileCmdHandle_t, v24);
      if ((v24[0] & 1) != 0)
        v20 = v24[2];
      else
        v20 = v24 + 1;
      v21 = sub_8C4940(v20);
    }
  }
  v22 = ToCharArray(aFileName);
  v17->device = v9;
  v17->filename = v22;
  v17->cmd = v8;
  v17->stat = 0;
  v17->fd = -1;
  v17->callback = aCallback;
  v17->userData = aUserData;
  return v17;
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
  aRealNamePtr = "";
  v9 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v9);
  if (sdfFileCmdAnalyzeFileName(aFileName, &aRealNamePtr) < 0)
    return 0;
LABEL_6:
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

  aRealNamePtr = "";
  v5 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v5);
  if (sdfFileCmdAnalyzeFileName(aFileName, &aRealNamePtr) < 0)
    return 0;
LABEL_6:
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
LABEL_14:
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
  sdfFileCmdHandle_t_o *v2;
  s32 cmd;
  sdfFileCmdCallback_t_o *callback;
  u64 *v7;
  Il2CppObject *userData;
  Il2CppObject *buffer;
  sdfFileCmdCallback_t_o *v10;
  sdfFileCmdHandle_t_o *v11;
  s32 v12;
  sdfFileCmdCallback_t_o *v13;
  u64 *v14;
  sdfFileCmdCallback_t_o *v15;
  u64 *v16;
  sdfFileCmdCallback_t_o *v17;
  u64 *v18;
  s32 v19;
  s32 length;
  Il2CppObject *v21;
  sdfMemHandle_t_o *v22;
  s32 v23;

  v2 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v2);
  while (1)
  {
    cmd = v2->cmd;
    v2->cmd = 0;
    switch (cmd)
    {
      case 1:
      case 2:
        callback = v2->callback;
        v2->stat = 7;
        v2->currentOffset = 0;
        v2->fd = 0;
        if (!callback)
          continue;
        v23 = 0;
        v7 = sub_8D3950(s32, &v23);
        userData = v2->userData;
        buffer = v7;
        v10 = callback;
        v11 = v2;
        v12 = 2;
        goto LABEL_21;
      case 3:
        v13 = v2->callback;
        v2->stat = 7;
        v2->currentOffset = 0;
        if (!v13)
          continue;
        v23 = 0;
        v14 = sub_8D3950(s32, &v23);
        userData = v2->userData;
        buffer = v14;
        v10 = v13;
        v11 = v2;
        v12 = 3;
        goto LABEL_21;
      case 4:
        v15 = v2->callback;
        v2->stat = 7;
        v2->currentOffset = 0;
        if (!v15)
          continue;
        v23 = 0;
        v16 = sub_8D3950(s32, &v23);
        userData = v2->userData;
        buffer = v16;
        v10 = v15;
        v11 = v2;
        v12 = 4;
        goto LABEL_21;
      case 5:
        v10 = v2->callback;
        v2->stat = 7;
        if (!v10)
          continue;
        buffer = v2->buffer;
        userData = v2->userData;
        v11 = v2;
        v12 = 5;
        goto LABEL_21;
      case 6:
        v10 = v2->callback;
        v2->stat = 7;
        if (!v10)
          continue;
        buffer = v2->buffer;
        userData = v2->userData;
        v11 = v2;
        v12 = 6;
        goto LABEL_21;
      case 7:
        v2->stat = 6;
        v2->fd = -1;
        sdfFileCmdUnlink(v2);
        v17 = v2->callback;
        v2->stat = 8;
        if (!v17)
          continue;
        v23 = 0;
        v18 = sub_8D3950(s32, &v23);
        userData = v2->userData;
        buffer = v18;
        v10 = v17;
        v11 = v2;
        v12 = 7;
LABEL_21:
        v19 = 0;
        goto LABEL_4;
      case 8:
        v2->stat = 2;
        v2->fd = 0;
        length = v2->length;
        if (length < 0)
        {
          v2->stat = 3;
LABEL_38:
          sdfFileCmdError(v2, length);
        }
        else
        {
          if (v2->length)
          {
            v21 = v2->buffer;
            if (!v21)
            {
              v22 = sdfMemAllocRecord(length, 0, 0);
              v21 = sdfMemLock(v22);
            }
            v2->buffer = v21;
            v2->stat = 4;
          }
LABEL_32:
          v2->stat = 6;
          v2->fd = -1;
          sdfFileCmdUnlink(v2);
          v10 = v2->callback;
          v2->stat = 8;
          if (v10)
          {
            buffer = v2->buffer;
            userData = v2->userData;
            v11 = v2;
            v12 = 8;
            v19 = length;
LABEL_4:
            sdfFileCmdCallback_t__Invoke(v10, v11, v12, buffer, v19, userData);
          }
        }
        break;
      case 9:
        v2->stat = 2;
        v2->fd = 0;
        length = v2->length;
        if (!v2->length)
          goto LABEL_32;
        v2->stat = 5;
        if ((length & 0x80000000) == 0)
          goto LABEL_32;
        goto LABEL_38;
      default:
        continue;
    }
  }
}

// 0x17ee020
void sdfFileCmdThreadCheckPrio(void) {
  s32 sdfFileCmdThreadPrioCheckCounter;
  s32 v5;

  else
  {
    if (!sdfFileCmdThreadPrioCheckCounter)
      return;
  }
  else
  {
    v5 = sdfFileCmdThreadPrioCheckCounter - 1;
    sdfFileCmdThreadPrioCheckCounter = v5;
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
  u32 v5;

  else
  {
    if (sdfFileCmdThreadPrio == prio)
      return;
  }
  v5 = 0;
  sdfFileCmdThreadPrio = prio;
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
  if (sdfFileCmdFreeQueueCount >= 9)
  {
    sdfFileCmdReleaseHandle(sdfFileCmdFreeQueueHead);
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
  aRealNamePtr = "";
  v11 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v11);
  if (sdfFileCmdAnalyzeFileName(aFileName, &aRealNamePtr) < 0)
    return 0;
LABEL_6:
  v11->offset = 0;
  v11->length = v8;
  v11->buffer = aBuffer;
  if (!aMode)
  {
    v11->cmdParm = sdfFileCmdDefaultCreateMode;
    if ((v15->_2.bitflags2 & 2) == 0)
      goto LABEL_14;
    goto LABEL_8;
  }
  v11->cmdParm = aMode;
  if ((v15->_2.bitflags2 & 2) != 0)
  {
LABEL_8:
  }
LABEL_14:
  sdfFileCmdEntry(v11);
  return v11;
}

// 0x17eda90
sdfFileCmdHandle_t *sdfFileCmdWriteOpen(char *aFileName, sdfFileCmdCallback_t *aCallback, void *aUserData, s32 aMode) {
  sdfFileCmdHandle_t_o *v7;
  sdfFileIO_c *v11;
  System_String_o *aRealNamePtr;

  aRealNamePtr = "";
  v7 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v7);
  if (sdfFileCmdAnalyzeFileName(aFileName, &aRealNamePtr) < 0)
    return 0;
LABEL_6:
  if (!aMode)
  {
    v7->cmdParm = sdfFileCmdDefaultCreateMode;
    if ((v11->_2.bitflags2 & 2) == 0)
      goto LABEL_14;
    goto LABEL_8;
  }
  v7->cmdParm = aMode;
  if ((v11->_2.bitflags2 & 2) != 0)
  {
LABEL_8:
  }
LABEL_14:
  sdfFileCmdEntry(v7);
  return v7;
}
