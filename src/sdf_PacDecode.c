#include "types.h"

typedef struct sdfDecompCb_t sdfDecompCb_t;
typedef struct sdfPacCallback_t sdfPacCallback_t;
typedef struct sdfPacDecodeCb_t sdfPacDecodeCb_t;
typedef struct sdfPacDecodeResrc_t sdfPacDecodeResrc_t;
typedef struct sdfPacStdBlockHeader_t sdfPacStdBlockHeader_t;
typedef struct sdfPacTmxDecodeCb_t sdfPacTmxDecodeCb_t;
typedef struct sdf_PacDecode2_sdfPac2DecodeCb_t sdf_PacDecode2_sdfPac2DecodeCb_t;
typedef struct sdf_PacDecode2_sdfPac2StdBlockHeader_t sdf_PacDecode2_sdfPac2StdBlockHeader_t;

void sdfAddressResolver(void *aDataBody, u32 aOffset, u8 aAddrInfoPtr, s32 aAddrInfoLeng);
void sdfDecompInit(sdfDecompCb_t *cb, void *dst);
void sdfPacEndBlock(sdf_PacDecode2_sdfPac2DecodeCb_t *cb);
void sdfPacMemDecoderFuncInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr);
void sdfPacMemDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr);
void sdfPacModelDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr);
void sdfPacMotionDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr);
void sdfPacNewBlock(sdf_PacDecode2_sdfPac2DecodeCb_t *cb);
void sdfPacTexListDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr);
void sdfPacTexListDecoderTmxStart(sdfPacDecodeCb_t *cb);
void sdfPacTmxDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr);
void sdfPacTmxDecoderInitFunc(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr, sdfPacTmxDecodeCb_t *tmxCb);

// 0x15da040
s32 sdfPacDecode(sdfPacDecodeCb_t *cb, void *data, s32 length) {
  s32 result;
  s32 rest;
  u64 *v7;
  s32 v8;
  s32 v9;
  s32 v10;

  cb->srcData = data;
  cb->srcLength = length;
  result = cb->stat;
  if (length >= 1)
  {
    while (2)
    {
      switch (result)
      {
        case -1:
          return result;
        case 0:
          sdfPacNewBlock(cb, data);
          length = cb->srcLength;
          result = cb->stat;
          if (length > 0)
            continue;
          break;
        case 1:
          if (cb->rest <= length)
            rest = cb->rest;
          else
            rest = length;
          v10 = *il2cp::SizeOf(cb->srcData, s32) + rest;
          v7 = sub_8D3950(s32, &v10);
          v8 = cb->srcTotal + rest;
          cb->srcLength -= rest;
          cb->srcTotal = v8;
          v9 = cb->rest - rest;
          cb->srcData = v7;
          cb->rest = v9;
          if (v9)
            goto LABEL_11;
          cb->stat = 0;
          length = cb->srcLength;
          result = cb->stat;
          if (length > 0)
            continue;
          break;
        case 2:
          sdfPacDecodeFunc_t__Invoke(cb->decoder, cb);
          length = cb->srcLength;
          result = cb->stat;
          if (length > 0)
            continue;
          break;
        default:
LABEL_11:
          length = cb->srcLength;
          result = cb->stat;
          if (length > 0)
            continue;
          break;
      }
      break;
    }
  }
  return result;
}

// 0x15d9c70
void sdfPacDecodeEnd(sdfPacDecodeCb_t *cb) {
  cb->stat = -1;
}

// 0x15d9f50
void sdfPacEndBlock(sdfPacDecodeCb_t *cb) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  s32 v6;
  struct sdfPacDecodeResrc_t_o *resrcHead;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  struct sdfPacDecodeResrc_t_o *v9;

  v3 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v3);
  v4 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v4);
  v5 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v5);
  v6 = sdfPacCallback_t__Invoke(cb->callback, cb, 1, cb->resrcTail->header);
  if (v6 == 1)
  {
    cb->stat = -1;
  }
  else
  {
    if (v6 == 4)
    {
      resrcHead = cb->resrcHead;
      resrcTail = cb->resrcTail;
      if (resrcHead == resrcTail)
      {
        cb->resrcHead = 0;
        cb->resrcTail = 0;
      }
      else
      {
        do
        {
          v9 = resrcHead;
          resrcHead = resrcHead->next;
        }
        while (resrcHead != resrcTail);
        v9->next = 0;
      }
    }
    cb->stat = 0;
  }
}

// 0x15d9c10
void sdfPacFree(sdfPacDecodeCb_t *cb) {
  u64 *v2;
  u64 *v3;

  v2 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v2);
  v3 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v3);
}

// 0x15da1a0
sdfPacDecodeResrc_t *sdfPacFreeResrc(sdfPacDecodeResrc_t *resrc) {
  struct sdfPacDecodeCb_t_o *cb;
  u64 *v4;
  u64 *v5;
  sdfPacDecodeResrc_t_o *v6;
  sdfPacDecodeResrc_t_o **p_resrcHead;
  struct sdfPacDecodeResrc_t_o *v8;
  sdfPacDecodeResrc_t_o *result;

  cb = resrc->cb;
  v4 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v4);
  v5 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v5);
  v6 = 0;
  p_resrcHead = &cb->resrcHead;
  do
  {
    v8 = v6;
    v6 = *p_resrcHead;
    p_resrcHead = &(*p_resrcHead)->next;
  }
  while (v6 != resrc);
  result = resrc->next;
  if (cb->resrcTail == resrc)
    cb->resrcTail = v8;
  return result;
}

// 0x15da3d0
char *sdfPacGetResrcFileName(sdfPacDecodeResrc_t *resrc) {
  return 0;
}

// 0x15d9b60
void sdfPacInit(sdfPacDecodeCb_t *cb, sdfPacCallback_t *callback) {
  cb->currBlockNum = -1;
  if (!callback)
  {
    callback = Allocate(sdfPacCallback_t);
    sdfPacCallback_t___ctor(callback, 0, Method_sdf_PacDecode_sdfPacStdCallback__);
  }
  cb->callback = callback;
}

// 0x15da3e0
void sdfPacMemDecoderFunc(sdfPacDecodeCb_t *cb) {
  s32 rest;
  u64 *v4;
  s32 srcTotal;
  Il2CppObject *workPtr;
  u64 *v7;
  s32 v8;
  s32 v9;
  s32 v10;

  if (cb->rest <= cb->srcLength)
    rest = cb->rest;
  else
    rest = cb->srcLength;
  if (rest)
  {
    v10 = *il2cp::SizeOf(cb->srcData, s32) + rest;
    v4 = sub_8D3950(s32, &v10);
    srcTotal = cb->srcTotal;
    cb->srcLength -= rest;
    cb->srcData = v4;
    workPtr = cb->workPtr;
    cb->srcTotal = srcTotal + rest;
    v9 = *il2cp::SizeOf(workPtr, s32) + rest;
    v7 = sub_8D3950(s32, &v9);
    v8 = cb->rest - rest;
    cb->workPtr = v7;
    cb->rest = v8;
    if (!v8)
      sdfPacDecodeFunc_t__Invoke(cb->onEnd, cb);
  }
}

// 0x15d9400
void sdfPacMemDecoderFuncInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  u64 *v4;
  sdfPacDecodeResrc_t_o *v5;
  struct sdfPacDecodeResrc_t_o *v6;
  struct sdfPacDecodeResrc_t_o **p_resrcHead;
  u64 *v8;
  intptr_t *v9;
  sdfPacDecodeResrc_t_o *v10;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  struct sdfPacDecodeResrc_t_o **p_next;
  struct sdfPacDecodeFunc_t_o *v13;

  v4 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v4);
  if ((cb->flag & 1) != 0)
  {
    v10 = Allocate(sdfPacDecodeResrc_t);
    sdfPacDecodeResrc_t___ctor(v10);
    v10->cb = cb;
    resrcTail = cb->resrcTail;
    if (resrcTail)
      p_next = &resrcTail->next;
    else
      p_next = &cb->resrcHead;
    *p_next = v10;
    cb->resrcTail = v10;
    v8 = Allocate(sdfPacDecodeFunc_t);
    v9 = &Method_sdf_PacDecode_sdfPacMemStayDecoderFunc__;
  }
  else
  {
    cb->stat = 2;
    v5 = Allocate(sdfPacDecodeResrc_t);
    sdfPacDecodeResrc_t___ctor(v5);
    v5->cb = cb;
    v6 = cb->resrcTail;
    if (v6)
      p_resrcHead = &v6->next;
    else
      p_resrcHead = &cb->resrcHead;
    *p_resrcHead = v5;
    cb->resrcTail = v5;
    v8 = Allocate(sdfPacDecodeFunc_t);
    v9 = &Method_sdf_PacDecode_sdfPacMemDecoderFunc__;
  }
  v13 = v8;
  sdfPacDecodeFunc_t___ctor(v8, 0, *v9);
  cb->decoder = v13;
}

// 0x15d9340
void sdfPacMemDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  u64 *v6;

  Log("sdfPacMemDecoderInit", 0);
  sdfPacMemDecoderFuncInit(cb, hdr);
  v6 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v6, 0, Method_sdf_PacDecode_sdfPacEndBlock__);
  cb->onEnd = v6;
}

// 0x15da500
void sdfPacMemDecompDecoderFunc(sdfPacDecodeCb_t *cb) {
  ;
}

// 0x15da510
void sdfPacMemStayDecoderFunc(sdfPacDecodeCb_t *cb) {
  s32 rest;
  u64 *v4;
  s32 v5;
  s32 v6;
  s32 v7;

  if (cb->rest <= cb->srcLength)
    rest = cb->rest;
  else
    rest = cb->srcLength;
  if (rest)
  {
    v7 = *il2cp::SizeOf(cb->srcData, s32) + rest;
    v4 = sub_8D3950(s32, &v7);
    v5 = cb->srcTotal + rest;
    cb->srcLength -= rest;
    cb->srcTotal = v5;
    v6 = cb->rest - rest;
    cb->srcData = v4;
    cb->rest = v6;
    if (!v6)
      sdfPacDecodeFunc_t__Invoke(cb->onEnd, cb);
  }
}

// 0x15da5e0
void sdfPacModelDecoderEndFunc(sdfPacDecodeCb_t *cb) {
  u64 *v3;
  sdfPacDecodeClass_c *v4;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  Il2CppObject *ptr;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  s32 klass_high;
  u64 v12[3];

  v3 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v3);
  resrcTail = cb->resrcTail;
  ptr = resrcTail->ptr;
  if (ptr)
  {
    klass = ptr->klass;
    if (ptr->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfPacDecodeClass)
    {
      sub_8FC2C0(klass->_1.element_class, sdfPacDecodeClass, v12);
      if ((v12[0] & 1) != 0)
        v9 = v12[2];
      else
        v9 = v12 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  resrcTail->ptr = 0;
  klass_high = HIDWORD(ptr[1].klass);
  if (klass_high)
  {
    sdfAddressResolver(0, 0, ptr[1].klass, klass_high);
    HIDWORD(ptr[1].klass) = 0;
  }
  sdfPacEndBlock(cb, v4);
}

// 0x15d98d0
void sdfPacModelDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  u64 *v6;

  Write("sdfPacModelDecoderInit:\n", 0);
  sdfPacMemDecoderFuncInit(cb, hdr);
  v6 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v6, 0, Method_sdf_PacDecode_sdfPacModelDecoderEndFunc__);
  cb->onEnd = v6;
}

// 0x15da720
void sdfPacMotionDecoderEndFunc(sdfPacDecodeCb_t *cb) {
  u64 *v3;
  sdfPacDecodeClass_c *v4;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  Il2CppObject *ptr;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  s32 klass_high;
  u64 v12[3];

  v3 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v3);
  resrcTail = cb->resrcTail;
  ptr = resrcTail->ptr;
  if (ptr)
  {
    klass = ptr->klass;
    if (ptr->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfPacDecodeClass)
    {
      sub_8FC2C0(klass->_1.element_class, sdfPacDecodeClass, v12);
      if ((v12[0] & 1) != 0)
        v9 = v12[2];
      else
        v9 = v12 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  resrcTail->ptr = 0;
  klass_high = HIDWORD(ptr[1].klass);
  if (klass_high)
  {
    sdfAddressResolver(0, 0, ptr[1].klass, klass_high);
    HIDWORD(ptr[1].klass) = 0;
  }
  sdfPacEndBlock(cb, v4);
}

// 0x15d9990
void sdfPacMotionDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  u64 *v6;

  Write("sdfPacMotionDecoderInit:\n", 0);
  sdfPacMemDecoderFuncInit(cb, hdr);
  v6 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v6, 0, Method_sdf_PacDecode_sdfPacMotionDecoderEndFunc__);
  cb->onEnd = v6;
}

// 0x15d9d10
void sdfPacNewBlock(sdfPacDecodeCb_t *cb) {
  u64 *v3;
  s32 v5;
  s32 v6;
  Il2CppObject *srcData;
  s32 v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 *v13;
  s32 srcTotal;
  s16 v15;
  sdfPacCallback_t_o *callback;
  s32 v17;
  s8 v18;
  u64 v19[3];

  v3 = Allocate(sdfPacStdBlockHeader_t);
  sdfPacStdBlockHeader_t___ctor(v3);
  {
  }
  v5 = SizeOf_sdfMemRecord_t_(v3);
  v6 = cb->srcTotal & 0x3F;
  if (v6)
  {
    cb->stat = 1;
    cb->rest = 64 - v6;
  }
  else
  {
    srcData = cb->srcData;
    v8 = v5;
    if (srcData)
    {
      klass = srcData->klass;
      if (srcData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfPacStdBlockHeader_t)
      {
        sub_8FC2C0(klass->_1.element_class, sdfPacStdBlockHeader_t, v19);
        if ((v19[0] & 1) != 0)
          v11 = v19[2];
        else
          v11 = v19 + 1;
        v12 = sub_8C4940(v11);
      }
    }
    LODWORD(v19[0]) = *il2cp::SizeOf(cb->srcData, s32) + v8;
    v13 = sub_8D3950(s32, v19);
    srcTotal = cb->srcTotal;
    cb->srcLength -= v8;
    cb->srcTotal = srcTotal + v8;
    v15 = cb->currBlockNum + 1;
    cb->srcData = v13;
    callback = cb->callback;
    cb->currBlockNum = v15;
    cb->rest = HIDWORD(srcData[1].klass) - v8;
    v17 = sdfPacCallback_t__Invoke(callback, cb, 0, srcData);
    if (v17 == 2)
    {
      cb->stat = 1;
      cb->rest = (cb->rest + 63) & 0xFFFFFFC0;
    }
    else
    {
      if (v17 == 1)
        v18 = -1;
      else
        v18 = 2;
      cb->stat = v18;
    }
  }
}

// 0x15d96a0
sdfPacDecodeResrc_t *sdfPacNewResrc(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  sdfPacDecodeResrc_t_o *v4;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  struct sdfPacDecodeResrc_t_o **p_next;

  v4 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v4);
  v4->cb = cb;
  resrcTail = cb->resrcTail;
  if (resrcTail)
    p_next = &resrcTail->next;
  else
    p_next = &cb->resrcHead;
  *p_next = v4;
  cb->resrcTail = v4;
  return v4;
}

// 0x15d9c00
void sdfPacSetFromTail(sdfPacDecodeCb_t *cb) {
  cb->flag |= 2u;
}

// 0x15d9bf0
void sdfPacSetStay(sdfPacDecodeCb_t *cb) {
  cb->flag |= 1u;
}

// 0x15da260
s32 sdfPacStdCallback(sdfPacDecodeCb_t *cb, s32 cause, sdfPacStdBlockHeader_t *hdr) {
  s32 result;
  u64 *v8;
  Il2CppObject *v10;
  sdfPacStdBlockHeader_t_o *v11;
  u8 v13[4];

  if (cause)
    return 0;
  v13[0] = hdr->fileType;
  v8 = sub_8D3950(qword_3F088F8, v13);
  v10 = Concat("hdr.fileType = ", v8);
  Log(v10, 0);
  switch (hdr->fileType)
  {
    case 1u:
      sdfPacMemDecoderInit(cb, hdr);
      result = 0;
      break;
    case 2u:
      sdfPacTmxDecoderInit(cb, hdr);
      result = 0;
      break;
    case 3u:
    case 4u:
    case 5u:
    case 7u:
      goto LABEL_9;
    case 6u:
      sdfPacModelDecoderInit(cb, hdr);
      result = 0;
      break;
    case 8u:
      sdfPacMotionDecoderInit(cb, hdr);
      result = 0;
      break;
    case 9u:
      sdfPacTexListDecoderInit(cb, v11);
      result = 0;
      break;
    default:
      if (hdr->fileType == 255)
        result = 1;
      else
LABEL_9:
        result = 3;
      break;
  }
  return result;
}

// 0x15db130
void sdfPacTexListDecoder0(sdfPacDecodeCb_t *cb) {
  u64 *v3;
  s32 v4;
  u64 *v5;
  s32 srcTotal;
  Il2CppObject *decodeWork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *v10;
  char *v11;
  s64 *v12;
  u64 v13[3];

  v3 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v3);
  if (cb->srcLength)
  {
    v4 = *il2cp::SizeOf(cb->srcData, uint);
    LODWORD(v13[0]) = *il2cp::SizeOf(cb->srcData, s32) + 4;
    v5 = sub_8D3950(s32, v13);
    srcTotal = cb->srcTotal;
    cb->srcLength -= 4;
    cb->srcData = v5;
    cb->srcTotal = srcTotal + 4;
    decodeWork = cb->decodeWork;
    klass = decodeWork->klass;
    if (decodeWork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfPacTexListDecodeCb_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfPacTexListDecodeCb_t, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
    LODWORD(decodeWork[1].klass) = v4;
    HIDWORD(decodeWork[1].klass) = 0;
    v10 = Allocate(sdfPacDecodeFunc_t);
    sdfPacDecodeFunc_t___ctor(v10, 0, Method_sdf_PacDecode_sdfPacTexListDecoder1__);
    cb->decoder = v10;
  }
}

// 0x15db070
void sdfPacTexListDecoder1(sdfPacDecodeCb_t *cb) {
  s32 srcLength;
  u64 *v4;
  s32 v6;
  s32 v7;
  s32 v8;

  if (cb->srcLength <= cb->rest)
    srcLength = cb->srcLength;
  else
    srcLength = cb->rest;
  v8 = *il2cp::SizeOf(cb->srcData, s32) + srcLength;
  v4 = sub_8D3950(s32, &v8);
  v6 = cb->srcTotal + srcLength;
  cb->srcLength -= srcLength;
  cb->srcTotal = v6;
  v7 = cb->rest - srcLength;
  cb->srcData = v4;
  cb->rest = v7;
  if (!v7)
    sdfPacTexListDecoderTmxStart(cb);
}

// 0x15d9a50
void sdfPacTexListDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  sdfPacDecodeResrc_t_o *v4;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  struct sdfPacDecodeResrc_t_o **p_next;
  u64 *v7;

  Write("sdfPacTexListDecoderInit:\n", 0);
  v4 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v4);
  v4->cb = cb;
  resrcTail = cb->resrcTail;
  if (resrcTail)
    p_next = &resrcTail->next;
  else
    p_next = &cb->resrcHead;
  *p_next = v4;
  cb->resrcTail = v4;
  v7 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v7, 0, Method_sdf_PacDecode_sdfPacTexListDecoder0__);
  cb->decoder = v7;
}

// 0x15dace0
void sdfPacTexListDecoderTmxBodyEndFunc(sdfPacDecodeCb_t *cb) {
  Il2CppObject *decodeWork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 v8;
  s32 v9;
  u64 v10[3];

  decodeWork = cb->decodeWork;
  if (decodeWork)
  {
    klass = decodeWork->klass;
    if (decodeWork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfPacTexListDecodeCb_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfPacTexListDecodeCb_t, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = decodeWork[1].klass;
  v9 = HIDWORD(decodeWork[1].klass) + 1;
  HIDWORD(decodeWork[1].klass) = v9;
  if (v9 == v8)
    sdfPacEndBlock(cb);
  else
    sdfPacTexListDecoderTmxStart(cb);
}

// 0x15daf50
void sdfPacTexListDecoderTmxHeaderEndFunc(sdfPacDecodeCb_t *cb) {
  Il2CppObject *decodeWork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *v7;
  char *v8;
  s64 *v9;
  u64 v10[3];

  decodeWork = cb->decodeWork;
  klass = decodeWork->klass;
  if (decodeWork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfPacTexListDecodeCb_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfPacTexListDecodeCb_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  sdfPacTmxDecoderInitFunc(cb, decodeWork[2].klass, decodeWork[2].monitor);
  v7 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v7, 0, Method_sdf_PacDecode_sdfPacTexListDecoderTmxBodyEndFunc__);
  cb->onEnd = v7;
}

// 0x15dae00
void sdfPacTexListDecoderTmxStart(sdfPacDecodeCb_t *cb) {
  Il2CppObject **decodeWork;
  Il2CppObject *v4;
  s64 typeHierarchyDepth;
  u64 *v6;
  u64 *v7;
  char *v8;
  s64 *v9;
  u64 v10[3];

  decodeWork = cb->decodeWork;
  v4 = *decodeWork;
  if (LOBYTE((*decodeWork)[18].klass) < typeHierarchyDepth
    || *(v4[12].monitor + typeHierarchyDepth - 1) != sdfPacTexListDecodeCb_t)
  {
    sub_8FC2C0(v4[4].klass, sdfPacTexListDecodeCb_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  cb->workPtr = decodeWork[4];
  v6 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v6, 0, Method_sdf_PacDecode_sdfPacMemDecoderFunc__);
  cb->decoder = v6;
  v7 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v7, 0, Method_sdf_PacDecode_sdfPacTexListDecoderTmxHeaderEndFunc__);
  cb->onEnd = v7;
}

// 0x15dabf0
void sdfPacTmxDecoderEndFunc(sdfPacDecodeCb_t *cb) {
  Il2CppObject **decodeWork;
  sdfPacTmxDecodeCb_t_c *v4;
  Il2CppObject *v5;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  decodeWork = cb->decodeWork;
  v5 = *decodeWork;
  if (LOBYTE((*decodeWork)[18].klass) < typeHierarchyDepth
    || *(v5[12].monitor + typeHierarchyDepth - 1) != sdfPacTmxDecodeCb_t)
  {
    sub_8FC2C0(v5[4].klass, sdfPacTmxDecodeCb_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  cb->resrcTail->handle = decodeWork[2];
  sdfPacEndBlock(cb, v4);
}

// 0x15da860
void sdfPacTmxDecoderFunc(sdfPacDecodeCb_t *cb) {
  Il2CppObject *decodeCb;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  s32 monitor;
  u64 *v9;
  s32 srcTotal;
  u64 *v11;
  s32 v12;
  u64 v13[3];

  decodeCb = cb->decodeCb;
  if (decodeCb)
  {
    klass = decodeCb->klass;
    if (decodeCb->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfPacTmxDecodeCb_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfPacTmxDecodeCb_t, v13);
      if ((v13[0] & 1) != 0)
        v6 = v13[2];
      else
        v6 = v13 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (SLODWORD(decodeCb[2].monitor) <= cb->srcLength)
    monitor = decodeCb[2].monitor;
  else
    monitor = cb->srcLength;
  if (monitor)
  {
    LODWORD(v13[0]) = *il2cp::SizeOf(cb->srcData, s32) + monitor;
    v9 = sub_8D3950(s32, v13);
    srcTotal = cb->srcTotal;
    cb->srcLength -= monitor;
    cb->srcData = v9;
    cb->srcTotal = srcTotal + monitor;
    LODWORD(v13[0]) = *il2cp::SizeOf(decodeCb[2].klass, s32) + monitor;
    v11 = sub_8D3950(s32, v13);
    v12 = LODWORD(decodeCb[2].monitor) - monitor;
    decodeCb[2].klass = v11;
    LODWORD(decodeCb[2].monitor) = v12;
    if (!v12)
      sdfPacDecodeFunc_t__Invoke(cb->onEnd, cb);
  }
}

// 0x15d9570
void sdfPacTmxDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  sdfPacDecodeResrc_t_o *v5;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  struct sdfPacDecodeResrc_t_o **p_next;
  u64 *v9;

  Write("sdfPacTmxDecoderInit:\n", 0);
  v5 = Allocate(sdfPacDecodeResrc_t);
  sdfPacDecodeResrc_t___ctor(v5);
  v5->cb = cb;
  resrcTail = cb->resrcTail;
  if (resrcTail)
    p_next = &resrcTail->next;
  else
    p_next = &cb->resrcHead;
  *p_next = v5;
  cb->resrcTail = v5;
  cb->decodeWork = 0;
  sdfPacTmxDecoderInitFunc(cb, hdr, 0);
  v9 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v9, 0, Method_sdf_PacDecode_sdfPacTmxDecoderEndFunc__);
  cb->onEnd = v9;
}

// 0x15d9720
void sdfPacTmxDecoderInitFunc(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr, sdfPacTmxDecodeCb_t *tmxCb) {
  u8 flag;
  u64 *v8;
  intptr_t *v9;
  Il2CppObject *decompWork;
  Il2CppObject *workPtr;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  struct sdfPacDecodeFunc_t_o *v16;
  u64 v17[3];

  flag = cb->flag;
  cb->decodeCb = tmxCb;
  if ((flag & 1) != 0)
  {
    v8 = Allocate(sdfPacDecodeFunc_t);
    v9 = &Method_sdf_PacDecode_sdfPacTmxStayDecoderFunc__;
  }
  else if (hdr->compression == 1)
  {
    decompWork = cb->decompWork;
    workPtr = tmxCb->workPtr;
    if (decompWork)
    {
      klass = decompWork->klass;
      if (decompWork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDecompCb_t)
      {
        sub_8FC2C0(klass->_1.element_class, sdfDecompCb_t, v17);
        if ((v17[0] & 1) != 0)
          v14 = v17[2];
        else
          v14 = v17 + 1;
        v15 = sub_8C4940(v14);
      }
    }
    sdfDecompInit(decompWork, workPtr, tmxCb);
    v8 = Allocate(sdfPacDecodeFunc_t);
    v9 = &Method_sdf_PacDecode_sdfPacTmxDecompDecoderFunc__;
  }
  else
  {
    if (hdr->compression)
      return;
    v8 = Allocate(sdfPacDecodeFunc_t);
    v9 = &Method_sdf_PacDecode_sdfPacTmxDecoderFunc__;
  }
  v16 = v8;
  sdfPacDecodeFunc_t___ctor(v8, 0, *v9);
  cb->decoder = v16;
}

// 0x15daa20
void sdfPacTmxDecompDecoderFunc(sdfPacDecodeCb_t *cb) {

}

// 0x15daa60
void sdfPacTmxStayDecoderFunc(sdfPacDecodeCb_t *cb) {
  Il2CppObject *decodeCb;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 monitor;
  u64 *v7;
  s32 srcTotal;
  s32 v9;
  char *v10;
  s64 *v11;
  u64 v12[3];

  decodeCb = cb->decodeCb;
  klass = decodeCb->klass;
  if (decodeCb->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfPacTmxDecodeCb_t)
  {
    sub_8FC2C0(klass->_1.element_class, sdfPacTmxDecodeCb_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  if (SLODWORD(decodeCb[2].monitor) <= cb->srcLength)
    monitor = decodeCb[2].monitor;
  else
    monitor = cb->srcLength;
  if (monitor)
  {
    LODWORD(v12[0]) = *il2cp::SizeOf(cb->srcData, s32) + monitor;
    v7 = sub_8D3950(s32, v12);
    srcTotal = cb->srcTotal;
    cb->srcLength -= monitor;
    cb->srcData = v7;
    cb->srcTotal = srcTotal + monitor;
    v9 = LODWORD(decodeCb[2].monitor) - monitor;
    LODWORD(decodeCb[2].monitor) = v9;
    if (!v9)
      sdfPacDecodeFunc_t__Invoke(cb->onEnd, cb);
  }
}

// 0x15d9c80
void sdfPacUseSrc(sdfPacDecodeCb_t *cb, s32 size) {
  u64 *v5;
  s32 srcTotal;
  s32 v7;

  v7 = *il2cp::SizeOf(cb->srcData, s32) + size;
  v5 = sub_8D3950(s32, &v7);
  srcTotal = cb->srcTotal;
  cb->srcLength -= size;
  cb->srcData = v5;
  cb->srcTotal = srcTotal + size;
}
