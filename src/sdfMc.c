#include "types.h"

typedef struct sdfMcCb_tag sdfMcCb_tag;
typedef struct sdfMcCtrlWork_tag sdfMcCtrlWork_tag;

static s8 sdfMcReady;
static s8 sdfMcManagerFlag;
static s32 sdfMcSemaId;
static sdfMcCtrlWork_tag *sdfMcCtrlWork;
static char *sdfMcInit_irxName[2];

// 0x1796dc0
s32 sdfMcChkCmdEnd(sdfMcCtrlWork_tag *mccb, s32 *result, s32 *cmdResult) {
  return 0;
}

// 0x1796a90
s32 sdfMcChkIllegalCard(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb, s32 result) {
  return 0;
}

// 0x1796a80
s32 sdfMcChkNoCard(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb, s32 result) {
  return 0;
}

// 0x1796ab0
s32 sdfMcChkReady(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb, s32 result) {
  return 0;
}

// 0x1796aa0
s32 sdfMcChkUnformatedCard(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb, s32 result) {
  return 0;
}

// 0x1796f00
s32 sdfMcCmdSync(s32 type, s32 port, s32 mode) {
  struct sdfMcCb_tag_o *cbLink;

LABEL_7:
  cbLink = sdfMcCtrlWork->cbLink;
  if (cbLink->mediaType == type)
    goto LABEL_12;
  do
  {
    do
      cbLink = cbLink->next;
    while (cbLink->mediaType != type);
LABEL_12:
    ;
  }
  while ((port & 0xF) != cbLink->port || port >> 4 != cbLink->slot);
  return cbLink->reqResult;
}

// 0x1797060
s32 sdfMcFormat(s32 type, s32 port) {
  return 0;
}

// 0x1796c30
void sdfMcFuncFormat(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796c40
void sdfMcFuncFormat1(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796b80
void sdfMcFuncGetFileInfo(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  System_Char_array *v3;

  v3 = NewSpecific(char, 0x43u);
  CreateString_5280336(0, v3);
}

// 0x1796be0
void sdfMcFuncGetFileInfo1(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796bf0
void sdfMcFuncGetFileInfo2(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796c00
void sdfMcFuncGetFileInfo3(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796c10
void sdfMcFuncGetFileInfo4(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x17969a0
void sdfMcFuncGetInfo(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  s32 timer;

  timer = cb->timer;
  cb->cmdDoing = 0;
  if (timer)
    cb->timer = timer - 1;
}

// 0x17969c0
void sdfMcFuncGetInfo1(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  mccb->cmdDoing = 0;
  {
    {
      {
        {
        }
      }
    }
  }
}

// 0x1796cd0
void sdfMcFuncMkdir(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796ce0
void sdfMcFuncMkdir1(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796c50
void sdfMcFuncRead(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796c60
void sdfMcFuncRead1(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796c70
void sdfMcFuncRead2(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796c80
void sdfMcFuncRead3(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796b70
void sdfMcFuncReady(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796c20
void sdfMcFuncUnformat(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796ac0
void sdfMcFuncUnformatedCheck(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796ad0
void sdfMcFuncUnformatedCheck1(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  mccb->cmdDoing = 0;
  {
    {
      {
      }
    }
  }
}

// 0x1796c90
void sdfMcFuncWrite(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796ca0
void sdfMcFuncWrite1(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796cb0
void sdfMcFuncWrite2(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796cc0
void sdfMcFuncWrite3(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1797070
s32 sdfMcGetFileInfoCount(s32 type, s32 port) {
  struct sdfMcCb_tag_o *cbLink;

LABEL_7:
  cbLink = sdfMcCtrlWork->cbLink;
  if (!cbLink)
    return 0;
LABEL_10:
  while (cbLink->mediaType != type || (port & 0xF) != cbLink->port || port >> 4 != cbLink->slot)
  {
    cbLink = cbLink->next;
    if (!cbLink)
      return 0;
  }
  return cbLink->fileInfoCount;
}

// 0x1796de0
void sdfMcGetFileInfoSub(sdfMcCtrlWork_tag *mccb, sdfMcCb_tag *cb) {
  ;
}

// 0x1796df0
s32 sdfMcGetStatus(s32 type, s32 port) {
  struct sdfMcCb_tag_o *cbLink;

LABEL_7:
  cbLink = sdfMcCtrlWork->cbLink;
  if (cbLink->mediaType == type)
    goto LABEL_12;
  do
  {
    do
      cbLink = cbLink->next;
    while (cbLink->mediaType != type);
LABEL_12:
    ;
  }
  while ((port & 0xF) != cbLink->port || port >> 4 != cbLink->slot);
  return cbLink->cardStat;
}

// 0x1797320
void sdfMcInit(char *irxPath, s32 irxMode) {
  ;
}

// 0x1797300
void sdfMcLockManager(void) {
  ;
}

// 0x17971b0
void sdfMcManager(void) {

}

// 0x1797220
void sdfMcManagerDisable(void) {
  sdfMcManagerFlag = 1;
}

// 0x1797290
void sdfMcManagerEnable(void) {
  sdfMcManagerFlag = 0;
}

// 0x1797040
s32 sdfMcMkdir(s32 type, s32 port, char *path) {
  return 0;
}

// 0x1797020
s32 sdfMcRead(s32 type, s32 port, char *filename, void *buff, s32 size) {
  return 0;
}

// 0x1797050
s32 sdfMcRegetInfo(s32 type, s32 port) {
  return 0;
}

// 0x1797010
s32 sdfMcReqRwCmd(s32 type, s32 port, char *filename, s32 cmd, void *buff, s32 size) {
  return 0;
}

// 0x1796dd0
void sdfMcResetFileInfo(sdfMcCb_tag *cb) {
  ;
}

// 0x1796cf0
sdfMcCb_tag *sdfMcSearchCb(s32 type, s32 port) {
  sdfMcCb_tag_o *result;

  else
  {
    result = sdfMcCtrlWork->cbLink;
    if (!result)
      return result;
  }
  do
  {
    if (result->mediaType == type && (port & 0xF) == result->port && port >> 4 == result->slot)
      break;
    result = result->next;
  }
  while (result);
  return result;
}

// 0x1797310
void sdfMcUnlockManager(void) {
  ;
}

// 0x1797030
s32 sdfMcWrite(s32 type, s32 port, char *filename, void *buff, s32 size) {
  return 0;
}
