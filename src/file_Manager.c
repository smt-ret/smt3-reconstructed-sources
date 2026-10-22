#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct debug_tag debug_tag;
typedef struct fileCb_t fileCb_t;
typedef struct fileEndCallback_t fileEndCallback_t;
typedef struct fileMngCb_tag fileMngCb_tag;
typedef struct pacFileCb_t pacFileCb_t;
typedef struct pacFileEndCallback_t pacFileEndCallback_t;
typedef struct sdfFileCmdCallback_t sdfFileCmdCallback_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfPacCallback_t sdfPacCallback_t;
typedef struct sdf_PacDecode2_sdfPac2Callback_t sdf_PacDecode2_sdfPac2Callback_t;
typedef struct sdf_PacDecode2_sdfPac2DecodeCb_t sdf_PacDecode2_sdfPac2DecodeCb_t;

static fileMngCb_tag *fileMngCb;
static s32 fileExecStat;

void fileExecCallback(void);
void fileExecQueue(void);
fileCb_t *fileLoadEx(char *filename, s32 headOrTail, fileEndCallback_t *endCallback, void *callbackParm);
s32 fileManager(void);
fileCb_t *fileSaveEx(char *filename, void *buff, s32 size, fileEndCallback_t *endCallback, void *callbackParm);
void fileSync_16292480(pacFileCb_t *pacFileHandle);
pacFileCb_t *pacLoadEx(char *filename, s32 headOrTail, sdfPacCallback_t *callback, pacFileEndCallback_t *pendCallback, void *callbackParm);
s32 sdfFileCmdClose(sdfFileCmdHandle_t *aHandle);
s32 sdfFileCmdFileSize(sdfFileCmdHandle_t *aHandle);
s32 sdfFileCmdFree(sdfFileCmdHandle_t *aHandle);
sdfFileCmdHandle_t *sdfFileCmdReadOpen(char *aFileName, sdfFileCmdCallback_t *aCallback, void *aUserData);
void sdfFileCmdThreadSetHiPrio(void);
sdfMemHandle_t *sdfMemAlloc2Direct(s32 aSize);
sdfMemHandle_t *sdfMemAllocFromTailDirect(s32 aSize);
debug_tag *sdfMemLock(void *aHandle);
s32 sdfPacDecode(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, u8 **data, s32 length);
void sdfPacInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2Callback_t *callback);
void sdfPacSetFromTail(sdf_PacDecode2_sdfPac2DecodeCb_t *cb);

// 0xf89650
s32 fileCheckEnd(fileCb_t *fileHandle) {
  return fileHandle->phase == 6;
}

// 0xf8a280
void fileExecCallback(void) {
  struct fileMngCb_tag_o *fileMngCb;
  Il2CppObject *v4;
  u64 *v5;
  u64 *v6;
  pacFileCb_t_o *v7;
  fileCb_t_o *endCallbackLink;
  fileEndCallback_t_o *fendCallback;

  v4 = Allocate(fileCb_t);
  v5 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v5);
  v4[2].monitor = v5;
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v4[5].klass = v6;
  _ctor(v4, 0);
  v7 = Allocate(pacFileCb_t);
  pacFileCb_t___ctor(v7);
  while (1)
  {
    endCallbackLink = fileMngCb->endCallbackLink;
    if (!endCallbackLink)
      break;
    fileMngCb->endCallbackLink = endCallbackLink->callbackNext;
    fendCallback = endCallbackLink->fendCallback;
    if (fendCallback)
    {
      fileEndCallback_t__Invoke(fendCallback, endCallbackLink, endCallbackLink->endCallbackParm);
    }
    else if (endCallbackLink->pendCallback)
    {
      v7->_base = endCallbackLink;
      pacFileEndCallback_t__Invoke(endCallbackLink->pendCallback, v7, endCallbackLink->endCallbackParm);
    }
  }
}

// 0xf88cd0
void fileExecQueue(void) {
  struct fileMngCb_tag_o *fileMngCb;
  Il2CppObject *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  struct fileCb_t_o *queue;
  s32 type;
  System_String_o *v12;
  u64 *v13;
  System_String_o *v15;
  sdfFileCmdCallback_t_o *v16;
  Il2CppObject *v17;
  System_String_o *filename;
  u64 *v19;
  s32 size;
  sdfMemHandle_t_o *v22;

  v4 = Allocate(fileCb_t);
  v5 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v5);
  v4[2].monitor = v5;
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v4[5].klass = v6;
  _ctor(v4, 0);
  v7 = Allocate(pacFileCb_t);
  pacFileCb_t___ctor(v7);
  queue = fileMngCb->queue;
  if (queue)
  {
    type = queue->type;
    if (type == 2)
    {
      if (!queue->phase)
        queue->phase = 1;
    }
    else if (type == 1)
    {
 if (!queue->phase)
      {
        queue->phase = 1;
        filename = queue->filename;
        v19 = Allocate(sdfFileCmdCallback_t);
        sdfFileCmdCallback_t___ctor(v19, 0, Method_file_Manager_pacLoadCallback__);
        v15 = filename;
        v16 = v19;
        v17 = v7;
        goto LABEL_24;
      }
    }
    else if (!queue->type)
    {
      if (queue->phase == 7)
      {
        size = queue->size;
        v22 = sdfMemAlloc2Direct(size);
        queue->memHandle = v22;
        if (!v22)
          --queue->allocRetry;
      }
      else if (!queue->phase)
      {
        queue->phase = 1;
        v12 = queue->filename;
        v13 = Allocate(sdfFileCmdCallback_t);
        sdfFileCmdCallback_t___ctor(v13, 0, Method_file_Manager_fileLoadCallback__);
        v15 = v12;
        v16 = v13;
        v17 = queue;
LABEL_24:
        queue->fileHandle = sdfFileCmdReadOpen(v15, v16, v17);
      }
    }
  }
}

// 0xf89620
void *fileGetLoadPtr(fileCb_t *fileHandle) {
  return fileHandle->topPtr;
}

// 0xf89640
s32 fileGetLoadRemain(fileCb_t *fileHandle) {
  return fileHandle->loadRemain;
}

// 0xf89630
s32 fileGetLoadSize(fileCb_t *fileHandle) {
  return fileHandle->size;
}

// 0xf89610
sdfMemHandle_t *fileGetMemHandle(fileCb_t *fileHandle) {
  return fileHandle->memHandle;
}

// 0xf89030
s32 fileHandleFree(fileCb_t *fileHandle) {
  return 0;
}

// 0xf89140
void fileLinkCloseWait(fileMngCb_tag *cb, fileCb_t *fileHandle) {
  fileHandle->next = cb->closeLink;
  cb->closeLink = fileHandle;
}

// 0xf89040
void fileLinkQueue(fileCb_t *fileHandle, s32 type, char *filename, fileEndCallback_t *fendCallback, void *callbackParm, pacFileEndCallback_t *pendCallback) {
  u8 v11;
  u64 v13;
  s64 v14;
  s64 v15;

  v11 = type;
  v14 = **(v13 + 184);
  fileHandle->type = v11;
  fileHandle->filename = filename;
  fileHandle->fendCallback = fendCallback;
  fileHandle->pendCallback = pendCallback;
  fileHandle->endCallbackParm = callbackParm;
  v15 = *(v14 + 32);
  if (v15)
  {
    *(v15 + 24) = fileHandle;
    *(v14 + 32) = fileHandle;
  }
  else
  {
    *(v14 + 24) = fileHandle;
    *(v14 + 32) = fileHandle;
    fileExecQueue(v13);
  }
}

// 0xf89510
fileCb_t *fileLoad(char *filename) {
  s64 v2;
  fileEndCallback_t_o *v3;
  Il2CppObject *v4;
  System_String_o *v6;
  s32 v8;

  v8 = 0;
  sub_8D3950(s32, &v8);
  fileLoadEx(v6, v2, v3, v4);
  return 0;
}

// 0xf89e10
void fileLoadCallback(sdfFileCmdHandle_t *fileHandle, s32 cause, void *buffer, s32 length, void *data) {
  s32 v8;
  struct fileMngCb_tag_o *fileMngCb;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  Il2CppClass *v16;
  s32 v17;
  Il2CppObject *v19;
  u64 *v20;
  u64 *v21;
  struct fileCb_t_o *endCallbackLink;
  Il2CppClass *v23;
  Il2CppClass *v25;
  Il2CppObject *v26;
  char *v27;
  char v28;
  struct fileCb_t_o *monitor;
  s32 fileExecStat;
  u64 v34[3];

  v8 = cause;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fileCb_t)
    {
      sub_8FC2C0(klass->_1.element_class, fileCb_t, v34);
      if ((v34[0] & 1) != 0)
        v14 = v34[2];
      else
        v14 = v34 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  switch (v8)
  {
    case 2:
      data[2].monitor = fileHandle;
      BYTE1(data[1].klass) = 2;
      sdfFileCmdFileSize(fileHandle);
      break;
    case 4:
      LODWORD(data[3].klass) = length;
      HIDWORD(data[3].klass) = length;
      if (BYTE3(data[1].klass))
      {
        v16 = sdfMemAllocFromTailDirect(length);
        data[5].klass = v16;
      }
      else
      {
        v23 = sdfMemAlloc2Direct(length);
        data[5].klass = v23;
        if (!v23)
        {
          *(&data[1].klass + 1) = 2567;
          return;
        }
        v25 = v23;
        v16 = v25;
      }
      v26 = sdfMemLock(v16);
      v27 = il2cp::SizeOf(v26, qword_3F088F8);
      v28 = *v27;
      LOBYTE(data[6].klass) = *v27;
      LOBYTE(v34[0]) = v28;
      data[5].monitor = sub_8D3950(qword_3F088F8, v34);
      BYTE1(data[1].klass) = 3;
        goto LABEL_46;
      break;
    case 5:
      v17 = LODWORD(data[3].klass) - length;
      LODWORD(data[3].klass) = v17;
      if (v17)
      {
        LOBYTE(data[6].klass) += length;
        BYTE1(data[1].klass) = 3;
      }
      else
      {
        BYTE1(data[1].klass) = 5;
        if (fileMngCb->queue == data)
        {
          monitor = data[1].monitor;
          fileMngCb->queue = monitor;
          if (!monitor)
            fileMngCb->queueTail = 0;
        }
      }
      if (BYTE1(data[1].klass) == 5)
      {
        data[1].monitor = fileMngCb->closeLink;
        fileMngCb->closeLink = data;
        v31 = sdfFileCmdClose(fileHandle);
        fileExecStat = 2;
        fileExecQueue();
      }
      {
LABEL_46:
      }
      break;
    case 7:
      sdfFileCmdFree(fileHandle);
      data[2].monitor = 0;
      BYTE1(data[1].klass) = 6;
      if (data[3].monitor)
      {
        v19 = Allocate(fileCb_t);
        v20 = Allocate(sdfFileCmdHandle_t);
        sdfFileCmdHandle_t___ctor(v20);
        v19[2].monitor = v20;
        v21 = Allocate(sdfMemHandle_t);
        sdfMemHandle_t___ctor(v21);
        v19[5].klass = v21;
        _ctor(v19, 0);
        endCallbackLink = fileMngCb->endCallbackLink;
        if (endCallbackLink)
        {
          do
            endCallbackLink = endCallbackLink->callbackNext;
          while (endCallbackLink);
          loc_68 = data;
        }
        else
        {
          fileMngCb->endCallbackLink = data;
        }
      }
      break;
    default:
      return;
  }
}

// 0xf89440
fileCb_t *fileLoadEx(char *filename, s32 headOrTail, fileEndCallback_t *endCallback, void *callbackParm) {
  Il2CppObject *v5;
  u64 *v6;
  u64 *v7;

  v5 = Allocate(fileCb_t);
  v6 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v6);
  v5[2].monitor = v6;
  v7 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v7);
  v5[5].klass = v7;
  _ctor(v5, 0);
  return v5;
}

// 0xf89590
fileCb_t *fileLoadUseTail(char *filename) {
  s64 v2;
  fileEndCallback_t_o *v3;
  Il2CppObject *v4;
  System_String_o *v6;
  s32 v8;

  v8 = 0;
  sub_8D3950(s32, &v8);
  fileLoadEx(v6, v2, v3, v4);
  return 0;
}

// 0xf89790
s32 fileManager(void) {
  struct fileMngCb_tag_o *fileMngCb;
  Il2CppObject *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;
  s64 index;
  u64 *v12;
  struct pacBlockData_t_array *data;
  struct pacFileCb_t_o *handle;
  struct pacBlockData_t_array *v16;
  struct fileCb_t_o *v18;
  u64 *v19;
  struct pacFileCb_t_o **p_pacEndCallbackLink;
  struct pacFileCb_t_o *v22;
  u8 freeCount;
  u8 v24;
  u8 v25;
  u64 *v28;
  struct pacFileCb_t_o *pacEndCallbackLink;
  fileCb_t_o *v32;
  s32 v34;

  v4 = Allocate(fileCb_t);
  v5 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v5);
  v4[2].monitor = v5;
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v4[5].klass = v6;
  _ctor(v4, 0);
  v7 = Allocate(pacFileCb_t);
  pacFileCb_t___ctor(v7);
  fileExecCallback();
  if (fileMngCb->activeCount)
  {
    do
    {
      while (1)
      {
        index = fileMngCb->index;
        v34 = fileMngCb->buffer | (fileMngCb->index << 16);
        v12 = sub_8D3950(s32, &v34);
        data = fileMngCb->data;
        handle = data->m_Items[index]->handle;
        if (handle->_base->type == 1)
          break;
        if (!fileMngCb->activeCount)
          goto LABEL_30;
      }
      if (!handle)
        goto LABEL_21;
      v16 = fileMngCb->data;
      if (sdfPacDecode(handle->decodeCb, v12, v16->m_Items[index]->size) != -1)
        goto LABEL_21;
      else
      {
        v18 = handle->_base;
        handle->decodeEnd = 1;
        if (!v18->fendCallback)
          goto LABEL_21;
      }
      v19 = Allocate(pacFileCb_t);
      pacFileCb_t___ctor(v19);
      p_pacEndCallbackLink = &fileMngCb->pacEndCallbackLink;
      do
      {
        v22 = *p_pacEndCallbackLink;
        p_pacEndCallbackLink = &(*p_pacEndCallbackLink)->endCallbackLink;
      }
      while (v22);
LABEL_21:
      freeCount = fileMngCb->freeCount;
      if (index == 3)
        v24 = 0;
      else
        v24 = index + 1;
      fileMngCb->index = v24;
      fileMngCb->freeCount = freeCount + 1;
      v25 = fileMngCb->activeCount - 1;
      fileMngCb->activeCount = v25;
    }
    while (v25);
  }
LABEL_30:
  fileExecQueue();
  v28 = Allocate(pacFileCb_t);
  pacFileCb_t___ctor(v28);
  pacEndCallbackLink = fileMngCb->pacEndCallbackLink;
  while (pacEndCallbackLink)
  {
    v32 = pacEndCallbackLink->_base;
    pacEndCallbackLink = pacEndCallbackLink->endCallbackLink;
    if (v32->phase == 6)
      fileEndCallback_t__Invoke(v32->fendCallback, v32, v32->endCallbackParm);
  }
  return fileMngCb->queue != 0;
}

// 0xf8a3d0
dds3ProcessFunc_t *fileManagerProc(dds3ProcessID_t *procId) {
  fileManager();
  return 0;
}

// 0xf89e00
void fileRead(fileCb_t *fileHandle) {
  ;
}

// 0xf89d80
fileCb_t *fileSave(char *filename, void *buff, s32 size) {
  Il2CppObject *v4;
  System_String_o *v6;

  fileSaveEx(v6, buff, size, v4);
  return 0;
}

// 0xf8a270
s32 fileSaveCallback(sdfFileCmdHandle_t *fileHandle, s32 cause, void *buffer, s32 length, void *data) {
  return 0;
}

// 0xf89cb0
fileCb_t *fileSaveEx(char *filename, void *buff, s32 size, fileEndCallback_t *endCallback, void *callbackParm) {
  Il2CppObject *v6;
  u64 *v7;
  u64 *v8;

  v6 = Allocate(fileCb_t);
  v7 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v7);
  v6[2].monitor = v7;
  v8 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v8);
  v6[5].klass = v8;
  _ctor(v6, 0);
  return v6;
}

// 0xf896d0
void fileSync(fileCb_t *fileHandle) {
  while (1)
  {
    if (fileHandle->phase == 6)
      break;
    sdfFileCmdThreadSetHiPrio();
    fileManager();
  }
}

// 0xf89bf0
void fileSyncAll(void) {
  struct fileMngCb_tag_o *fileMngCb;

  else
  {
    if (fileMngCb->queue)
      goto LABEL_11;
  }
  while (fileMngCb->closeLink)
  {
    do
    {
LABEL_11:
      fileManager();
    }
    while (fileMngCb->queue);
  }
}

// 0xf89a80
void fileSync_16292480(pacFileCb_t *pacFileHandle) {
  struct fileCb_t_o *base;

  while (1)
  {
    else
    {
      base = pacFileHandle->_base;
      if (base->type != 1)
        goto LABEL_10;
    }
    if (!pacFileHandle->decodeEnd)
      goto LABEL_11;
LABEL_10:
    if (base->phase == 6)
      break;
LABEL_11:
    sdfFileCmdThreadSetHiPrio();
    fileManager();
  }
}

// 0xf8a440
void fileSysInit(void) {
  ;
}

// 0xf89150
void fileUnlinkCloseWait(fileMngCb_tag *cb, fileCb_t *fileHandle) {
  ;
}

// 0xf89130
void fileUnlinkQueue(fileCb_t *fileHandle) {
  ;
}

// 0xf8a260
void fileWrite(fileCb_t *fileHandle) {
  ;
}

// 0xf896a0
s32 pacCheckEnd(pacFileCb_t *pacHandle) {
  return pacHandle->decodeEnd && pacHandle->_base->phase == 6;
}

// 0xf89660
s32 pacFileCheckEnd(pacFileCb_t *pacFileHandle) {
  struct fileCb_t_o *base;

  base = pacFileHandle->_base;
  if (base->type != 1)
    return base->phase == 6;
  if (pacFileHandle->decodeEnd)
    return base->phase == 6;
  return 0;
}

// 0xf88fc0
s32 pacFileHandleFree(pacFileCb_t *pacHandle) {
    return 0;
  return 0;
}

// 0xf88fb0
s32 pacFileHandleFree_(pacFileCb_t *pacHandle) {
  return 0;
}

// 0xf89300
pacFileCb_t *pacLoad(char *filename) {
  u64 *v5;
  s32 v7;

  v7 = 0;
  v5 = sub_8D3950(s32, &v7);
  pacLoadEx(filename, 0, 0, 0, v5);
  return 0;
}

// 0xf89df0
void pacLoadCallback(sdfFileCmdHandle_t *fileHandle, s32 cause, void *buffer, s32 length, void *data) {
  ;
}

// 0xf89160
pacFileCb_t *pacLoadEx(char *filename, s32 headOrTail, sdfPacCallback_t *callback, pacFileEndCallback_t *pendCallback, void *callbackParm) {
  pacFileCb_t_o *v11;
  struct fileCb_t_o *base;
  u64 v16;
  s64 v17;
  s64 v18;

  v11 = Allocate(pacFileCb_t);
  pacFileCb_t___ctor(v11);
  Write_2930400("pac load {0}\n", filename);
  sdfPacInit(v11->decodeCb, callback);
  if (headOrTail)
    sdfPacSetFromTail(v11->decodeCb);
  base = v11->_base;
LABEL_12:
  v17 = **(v16 + 184);
  base->type = 1;
  base->filename = filename;
  base->endCallbackParm = callbackParm;
  base->fendCallback = 0;
  base->pendCallback = pendCallback;
  v18 = *(v17 + 32);
  if (v18)
  {
    *(v18 + 24) = base;
    *(v17 + 32) = base;
  }
  else
  {
    *(v17 + 24) = base;
    *(v17 + 32) = base;
    fileExecQueue(v16);
  }
  return v11;
}

// 0xf893a0
pacFileCb_t *pacLoadUseTail(char *filename) {
  u64 *v5;
  s32 v7;

  v7 = 0;
  v5 = sub_8D3950(s32, &v7);
  pacLoadEx(filename, 1, 0, 0, v5);
  return 0;
}

// 0xf88fa0
void pacRead(pacFileCb_t *pacHandle) {
  ;
}

// 0xf89b70
void pacSync(pacFileCb_t *pacFileHandle) {
  pacFileCb_t_o *v3;

  else
  {
    v3 = pacFileHandle;
  }
  fileSync_16292480(v3);
}
