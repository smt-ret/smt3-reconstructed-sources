#include "types.h"

typedef struct sdfCdImageDirEntry_t sdfCdImageDirEntry_t;
typedef struct sdfFileCmdCallback_t sdfFileCmdCallback_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;

static u8 sdfFileDefaultSrcType;
static char *sdfFileHostRootPath;
static s32 sdfFileLengthWork;
static s32 sdfFileSeekWork;
static s32 sdfFileSemaId;

char *ChangeCharacter(char *sourceString, s32 charIndex, u16 newChar);
char *StrChr(char *stringToSearch, u16 charToFind);
sdfCdImageDirEntry_t *sdfCdImageSearchFile(char *fname, u32 lsn, u8 modePtr);
s32 sdfCreateSema(s32 initCount, s32 maxCount, s32 option);
sdfFileCmdHandle_t *sdfFileCmdReadOpen(char *aFileName, sdfFileCmdCallback_t *aCallback, void *aUserData);
void sdfFileCmdReleaseHandle(sdfFileCmdHandle_t *aHandle);
char *sdfFileMakeFilename(char *aFilename);
void sdfFileSetCdFilename(char **aDst, u16 **aSrc);
void sdfFileSetHostFilename(char **aDst, char *aSrc);

// 0x17eb420
void sdfFileCallback(sdfFileCmdHandle_t *fileHandle, s32 cause, void *buffer, s32 length, void *data) {
  if (cause == 3)
  {
    sdfFileSeekWork = length;
  }
  else if (cause == 4)
  {
    sdfFileLengthWork = length;
  }
}

// 0x17eb770
s32 sdfFileCheckExist(char *aFilename) {
  System_String_o *Filename;
  s64 v4;
  u8 v5;

  Filename = sdfFileMakeFilename(aFilename);
  if (get_Chars(Filename, 0) != 47)
    return 1;
LABEL_11:
  return sdfCdImageSearchFile(Filename, v4, v5) != 0;
}

// 0x17eb0b0
s32 sdfFileChkCdFile(char *aFilename) {
  return 0;
}

// 0x17eb0d0
s32 sdfFileChkHddFile(char *aFilename) {
  return 0;
}

// 0x17eb0c0
s32 sdfFileChkHostFile(char *aFilename) {
  return 0;
}

// 0x17eb890
void sdfFileClose(sdfFileCmdHandle_t *aHandle) {
  s32 stat;

  else
  {
    stat = aHandle->stat;
    if (stat != 7)
      goto LABEL_6;
  }
  aHandle->cmd = 7;
  if ((byte_3F5A8EE & 1) == 0)
    goto LABEL_14;
LABEL_7:
  if ((stat - 7) > 1)
    return;
LABEL_8:
  sdfFileCmdReleaseHandle(aHandle);
}

// 0x17ebe60
char *sdfFileGetHostRoot(void) {
  return sdfFileHostRootPath;
}

// 0x17ebb30
s32 sdfFileLength(sdfFileCmdHandle_t *aHandle) {
  if (aHandle->stat == 7)
LABEL_6:
    aHandle->cmd = 4;
LABEL_7:
  return sdfFileLengthWork;
}

// 0x17eb0e0
char *sdfFileMakeFilename(char *aFilename) {
  System_String_o *v5;
  System_Char_array *v6;
  u64 v7;
  u16 *m_Items;
  s32 v10;
  s16 v11;
  sdfFile_c *v14;
  s32 sdfFileDefaultSrcType;
  System_Char_array *v18;
  u32 v19;
  u32 max_length;
  u32 v22;
  System_String_o *aDst;

  aDst = "";
  get_Length(aFilename);
  if (StrChr(aFilename, 0x3Au))
  {
    aDst = aFilename;
    if (Compare_5254944(aFilename, 0, "cdrom", 0, 5))
      return aDst;
    v5 = Substring(aFilename, 5);
    v6 = ToCharArray(v5);
    v7 = 0;
    m_Items = v6->m_Items;
    if (!LODWORD(v6->max_length))
    {
LABEL_8:
    }
    while (1)
    {
      v10 = m_Items[v7];
      if (v10 == 47)
        break;
      if (!m_Items[v7])
      {
        v19 = v7 + 1;
        v6->m_Items[v7] = 59;
        max_length = v6->max_length;
        v22 = v7 + 2;
        v6->m_Items[v19] = 49;
        v6->m_Items[v22] = 0;
        return aDst;
      }
      if ((v10 - 97) <= 0x19)
      {
        v11 = v10 - 32;
LABEL_16:
        m_Items[v7] = v11;
      }
      if (++v7 >= LODWORD(v6->max_length))
        goto LABEL_8;
    }
    v11 = 92;
    goto LABEL_16;
  }
  {
          v14 = sdfFile,
    {
      {
        {
        }
      }
    }
  }
  if (sdfFileDefaultSrcType == 2)
  {
    return Concat_5224608("pfs0:", aFilename);
  }
  else if (sdfFileDefaultSrcType == 1)
  {
    sdfFileSetHostFilename(&aDst, aFilename);
  }
  else if (sdfFileDefaultSrcType)
  {
    return aFilename;
  }
  else
  {
    v18 = ToCharArray(aFilename);
    sdfFileSetCdFilename(&aDst, v18);
  }
  return aDst;
}

// 0x17eb4f0
sdfFileCmdHandle_t *sdfFileOpen(char *aFileName) {
  u64 *v3;
  s32 Sema;
  u64 *v8;
  sdfFileCmdCallback_t_o *v9;
  Il2CppObject *v10;
  sdfFileCmdHandle_t_o *result;

  v3 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v3);
  else if ((sdfFileSemaId & 0x80000000) == 0)
  {
    goto LABEL_14;
  }
  Sema = sdfCreateSema(0, 128, 0);
  sdfFileSemaId = Sema;
LABEL_14:
  v8 = Allocate(sdfFileCmdCallback_t);
  sdfFileCmdCallback_t___ctor(v8, 0, Method_sdfFile_sdfFileCallback__);
  result = sdfFileCmdReadOpen(aFileName, v9, v10);
  if (result->stat == 9)
  {
    result->stat = 7;
    result->errorCode = 0;
  }
  return result;
}

// 0x17eba60
void sdfFileRead(sdfFileCmdHandle_t *aHandle, void *aPtr, s32 aLeng) {
  s16 v4;

  v4 = aLeng;
  else if (aHandle->stat != 7)
  {
    return;
  }
  aHandle->cmd = 5;
  aHandle->length = v4;
  aHandle->buffer = aPtr;
}

// 0x17ebc10
s32 sdfFileSeek(sdfFileCmdHandle_t *aHandle, s32 aPos, s32 aWhence) {
  s16 v5;

  v5 = aPos;
  if (aHandle->stat == 7)
  {
LABEL_6:
    aHandle->cmd = 3;
    aHandle->offset = v5;
    aHandle->cmdParm = aWhence;
  }
LABEL_7:
  return sdfFileSeekWork;
}

// 0x17eade0
void sdfFileSetCdFilename(char **aDst, u16 **aSrc) {
  System_String_o *v5;
  System_String_o *v6;
  System_Char_array *v7;
  u64 v8;
  u16 *m_Items;
  s32 v11;
  u16 v12;
  u64 v13;
  u32 max_length;

  v5 = "cdrom0:";
  *aDst = "cdrom0:";
  v6 = Substring(v5, 7);
  v7 = ToCharArray(v6);
  v8 = 0;
  m_Items = aSrc->m_Items;
  if (!LODWORD(aSrc->max_length))
  {
LABEL_6:
  }
  while (1)
  {
    v11 = m_Items[v8];
    if (!m_Items[v8])
      break;
    if (v11 == 47)
      LOWORD(v11) = 92;
    if ((v11 - 97) <= 0x19u)
      v12 = v11 - 32;
    else
      v12 = v11;
    v13 = v8 + 1;
    v7->m_Items[v8++] = v12;
    if (v13 >= LODWORD(aSrc->max_length))
      goto LABEL_6;
  }
  max_length = v7->max_length;
  v7->m_Items[0] = 59;
  v7->m_Items[1] = 49;
  v7->m_Items[2] = 0;
}

// 0x17ebed0
void sdfFileSetDefaultSrc(s32 aType) {
  u8 v2;

  v2 = aType;
  sdfFileDefaultSrcType = v2;
LABEL_10:
  sdfFileCmdDefaultDevice = v2;
}

// 0x17eb040
void sdfFileSetHddFilename(char **aDst, char *aSrc) {
  System_String_o *v5;

  v5 = "pfs0:";
  *aDst = "pfs0:";
  *aDst = Concat_5224608(v5, aSrc);
}

// 0x17eaf80
void sdfFileSetHostFilename(char **aDst, char *aSrc) {
  System_String_o *sdfFileHostRootPath;

  {
    sdfFileHostRootPath = "host0:";
  }
  *aDst = sdfFileHostRootPath;
  *aDst = Concat_5224608(sdfFileHostRootPath, aSrc);
}

// 0x17ebd10
void sdfFileSetHostRoot(char *aRootPath) {
  s32 Length;
  System_String_o *v5;
  s32 Chars;
  struct sdfFile_StaticFields **p_static_fields;
  s32 v11;
  struct System_String_o *v12;

  Length = get_Length(aRootPath);
  v5 = Concat_5224608("host0:", aRootPath);
  sdfFileHostRootPath = v5;
  Chars = get_Chars(aRootPath, Length - 1);
  if (Chars == 0x2F)
  {
    v11 = 6;
  }
  else
  {
    v12 = ChangeCharacter(sdfFileHostRootPath, Length + 6, 0x2Fu);
    sdfFileHostRootPath = v12;
    v11 = 7;
  }
  sdfFileHostRootPath = ChangeCharacter(
                                                           (*p_static_fields)->sdfFileHostRootPath,
                                                           Length + v11,
                                                           0,
                                                           0);
}
