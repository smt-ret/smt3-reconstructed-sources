#include "types.h"

typedef struct sdfDecompCb_t sdfDecompCb_t;
typedef struct sdf_PacDecode2_AddressDecoder_t sdf_PacDecode2_AddressDecoder_t;
typedef struct sdf_PacDecode2_sdfPac2Callback_t sdf_PacDecode2_sdfPac2Callback_t;
typedef struct sdf_PacDecode2_sdfPac2DecodeCb_t sdf_PacDecode2_sdfPac2DecodeCb_t;
typedef struct sdf_PacDecode2_sdfPac2DecodeFunc_t sdf_PacDecode2_sdfPac2DecodeFunc_t;
typedef struct sdf_PacDecode2_sdfPac2DecodeResrc_t sdf_PacDecode2_sdfPac2DecodeResrc_t;
typedef struct sdf_PacDecode2_sdfPac2StdBlockHeader_t sdf_PacDecode2_sdfPac2StdBlockHeader_t;

struct sdf_PacDecode2_sdfPac2StdBlockHeader_t {
    u8 fileType;
    u8 compression;
    u16 userId;
    u32 size;
    u32 magicCode;
    u32 realSize;
    s32 header_p;
};

struct sdf_PacDecode2_sdfPac2DecodeResrc_t {
    sdf_PacDecode2_sdfPac2DecodeResrc_t *next;
    sdf_PacDecode2_sdfPac2DecodeCb_t *cb;
    u8 *handle;
    s32 ptr;
    sdf_PacDecode2_sdfPac2StdBlockHeader_t *header;
};

struct sdf_PacDecode2_sdfPac2DecodeCb_t {
    s32 stat;
    u32 flag;
    s32 currBlockNum;
    sdf_PacDecode2_sdfPac2Callback_t *callback;
    sdf_PacDecode2_sdfPac2DecodeFunc_t *decoder;
    sdf_PacDecode2_sdfPac2DecodeFunc_t *onEnd;
    u8 *srcData;
    s32 srcData_p;
    s32 srcLength;
    s32 srcTotal;
    u8 *workPtr;
    s32 workPtr_p;
    s32 rest;
    sdfDecompCb_t *decompWork;
    s32 decompWork_p;
    u8 *decodeCb;
    s32 decodeCb_p;
    u8 *decodeWork;
    s32 decodeWork_p;
    sdf_PacDecode2_sdfPac2DecodeResrc_t *resrcHead;
    sdf_PacDecode2_sdfPac2DecodeResrc_t *resrcTail;
};

struct sdf_PacDecode2_AddressDecoder_t {
    u32 dataSize;
    u32 addrInfoSize;
    u32 pad[2];
};

void SDF_ABORT2(char *aFmt, void **LegacyParamArray);
void SDF_ASSERT(bool result);
s32 sdfDecomp(sdfDecompCb_t *cb, void *src, s32 length);
void sdfDecompInit(sdfDecompCb_t *cb, void *dst);
void sdfPacEndBlock(sdf_PacDecode2_sdfPac2DecodeCb_t *cb);
void sdfPacMemDecoderFuncInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr);
void sdfPacMemDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr);
void sdfPacModelDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr);
void sdfPacMotionDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr);
void sdfPacNewBlock(sdf_PacDecode2_sdfPac2DecodeCb_t *cb);
s32 sdf_PacDecode2_AddressDecoder_t__Set(sdf_PacDecode2_AddressDecoder_t *this, u8 **data, s32 index);
void sdf_PacDecode2_sdfPac2StdBlockHeader_t__Set(sdf_PacDecode2_sdfPac2StdBlockHeader_t *this, u8 **dat, s32 idx);

// 0x15db500
void Clear(sdf_PacDecode2_sdfPac2DecodeCb_t *this) {
  *&this->stat = 0;
  this->currBlockNum = 0;
  this->callback = 0;
  this->decodeCb = 0;
  this->decodeCb_p = 0;
  this->decodeWork = 0;
  this->decodeWork_p = 0;
  this->srcTotal = 0;
  this->onEnd = 0;
  this->decompWork_p = 0;
  this->workPtr = 0;
  this->srcData = 0;
  *&this->srcData_p = 0;
  *&this->workPtr_p = 0;
  this->decompWork = 0;
  this->resrcHead = 0;
  this->resrcTail = 0;
}

// 0x15db2f0
void LOG(char *log) {
  Log(log, 0);
}

// 0x15db410
s32 sdfPac2GetCompMode(sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr) {
  return hdr->compression & 0xF;
}

// 0x15db420
s32 sdfPac2GetHeaderAddSize(sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr) {
  return hdr->compression & 0xF0;
}

// 0x15db400
sdf_PacDecode2_sdfPac2DecodeResrc_t *sdfPac2GetResrc(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  return cb->resrcHead;
}

// 0x15dcca0
s32 sdfPac2StdCallback(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, s32 cause, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr) {
  s32 result;
  Il2CppObject *v8;
  Il2CppObject *v10;
  Il2CppObject *v11;
  Il2CppObject *v12;
  Il2CppObject *v14;

  if (!cause)
  {
    result = 3;
    switch (hdr->fileType)
    {
      case 1u:
        v8 = "SDF_PAC_FILE_ID_BIN";
        Log(v8, 0);
        sdfPacMemDecoderInit(cb, hdr);
        return 0;
      case 2u:
        v11 = "SDF_PAC_FILE_ID_TMX";
        if ((byte_3F5A0D5 & 1) != 0)
          goto LABEL_36;
        goto LABEL_35;
      case 3u:
      case 4u:
      case 5u:
      case 7u:
        return result;
      case 6u:
        v12 = "SDF_PAC_FILE_ID_MODEL";
        Log(v12, 0);
        sdfPacModelDecoderInit(cb, hdr);
        return 0;
      case 8u:
        v14 = "SDF_PAC_FILE_ID_MOTION";
        Log(v14, 0);
        sdfPacMotionDecoderInit(cb, hdr);
        return 0;
      case 9u:
        v11 = "SDF_PAC_FILE_ID_TEXPACK";
LABEL_36:
        Log(v11, 0);
        return 0;
      default:
        if (hdr->fileType == 255)
        {
          v10 = "SDF_PAC_FILE_ID_END";
          Log(v10, 0);
          return 1;
        }
        return result;
    }
  }
  return 0;
}

// 0x15dc500
s32 sdfPacDecode(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, u8 **data, s32 length) {
  s32 result;
  s32 rest;
  s32 srcTotal;
  s32 v8;
  s32 v9;

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
          *&length = cb->srcLength;
          result = cb->stat;
          if (length > 0)
            continue;
          break;
        case 1:
          rest = cb->rest;
          srcTotal = cb->srcTotal;
          if (rest <= length)
            v8 = cb->rest;
          else
            v8 = length;
          cb->srcData_p += v8;
          v9 = rest - v8;
          cb->rest = v9;
          cb->srcLength = length - v8;
          cb->srcTotal = srcTotal + v8;
          if (v9)
            goto LABEL_9;
          cb->stat = 0;
          *&length = cb->srcLength;
          result = 0;
          if (length > 0)
            continue;
          break;
        case 2:
          Invoke(cb->decoder, cb, *&length);
          *&length = cb->srcLength;
          result = cb->stat;
          if (length > 0)
            continue;
          break;
        default:
LABEL_9:
          *&length = cb->srcLength;
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

// 0x15db590
void sdfPacDecodeEnd(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  cb->stat = -1;
}

// 0x15dc3f0
void sdfPacEndBlock(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  s32 v4;
  s32 v6;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *resrcHead;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *resrcTail;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *v9;

  v4 = Invoke(cb->callback, cb, 1, cb->resrcTail->header);
  if (v4 == 1)
  {
    cb->stat = -1;
  }
  else
  {
    v6 = v4;
    if (v4 == 4)
    {
      resrcHead = cb->resrcHead;
      resrcTail = cb->resrcTail;
      if (resrcHead == resrcTail)
      {
        cb->resrcHead = 0;
        cb->resrcTail = 0;
        cb->stat = 0;
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
        cb->stat = 0;
      }
    }
    else
    {
      SDF_ASSERT(v6 == 0);
      cb->stat = 0;
    }
  }
}

// 0x15db570
void sdfPacFree(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o **p_resrcHead;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *v3;

  p_resrcHead = &cb->resrcHead;
  do
  {
    v3 = *p_resrcHead;
    p_resrcHead = &(*p_resrcHead)->next;
  }
  while (v3);
}

// 0x15dcc50
sdf_PacDecode2_sdfPac2DecodeResrc_t *sdfPacFreeResrc(sdf_PacDecode2_sdfPac2DecodeResrc_t *resrc) {
  struct sdf_PacDecode2_sdfPac2DecodeCb_t_o *cb;
  sdf_PacDecode2_sdfPac2DecodeResrc_t_o *v3;
  sdf_PacDecode2_sdfPac2DecodeResrc_t_o **p_resrcHead;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *v5;
  sdf_PacDecode2_sdfPac2DecodeResrc_t_o *next;

  cb = resrc->cb;
  v3 = 0;
  p_resrcHead = &cb->resrcHead;
  do
  {
    v5 = v3;
    v3 = *p_resrcHead;
    p_resrcHead = &(*p_resrcHead)->next;
  }
  while (v3 != resrc);
  next = resrc->next;
  if (cb->resrcTail != resrc)
    return resrc->next;
  cb->resrcTail = v5;
  return next;
}

// 0x15db430
void sdfPacInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2Callback_t *callback) {
  struct sdf_PacDecode2_sdfPac2Callback_t_o *v5;
  s64 v6;

  *&cb->stat = 0;
  cb->callback = 0;
  cb->decodeCb = 0;
  cb->decodeCb_p = 0;
  cb->decodeWork = 0;
  cb->decodeWork_p = 0;
  cb->srcTotal = 0;
  cb->onEnd = 0;
  cb->decompWork_p = 0;
  cb->workPtr = 0;
  cb->currBlockNum = -1;
  cb->srcData = 0;
  *&cb->srcData_p = 0;
  *&cb->workPtr_p = 0;
  cb->decompWork = 0;
  cb->resrcHead = 0;
  cb->resrcTail = 0;
  if (callback)
  {
    cb->callback = callback;
  }
  else
  {
    v5 = Allocate(sdf_PacDecode2_sdfPac2Callback_t);
    v6 = Method_sdf_PacDecode2_sdfPac2StdCallback__;
    v5->method_ptr = *Method_sdf_PacDecode2_sdfPac2StdCallback__;
    v5->m_target = 0;
    v5->method = v6;
    cb->callback = v5;
  }
}

// 0x15dd200
void sdfPacMemDecoderFunc(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  Il2CppObject *v3;
  s32 rest;
  s32 workPtr_p;
  u64 v6;
  u64 *v7;
  struct System_Byte_array *v8;
  s32 srcLength;
  s32 v11;
  s32 v12;
  s32 srcTotal;

  v3 = "sdfPacMemDecoderFunc";
  Log(v3, 0);
  if (cb->rest <= cb->srcLength)
    rest = cb->rest;
  else
    rest = cb->srcLength;
  if (rest)
  {
    workPtr_p = cb->workPtr_p;
    v6 = (workPtr_p + rest);
    v7 = NewSpecific(byte, v6);
    Copy_3886320(cb->workPtr, v7, cb->workPtr->max_length);
    v8 = NewSpecific(byte, v6);
    cb->workPtr = v8;
    Copy_3886320(v7, v8, *(v7 + 6), 0);
    Copy_3880080(cb->srcData, cb->srcData_p, cb->workPtr, cb->workPtr_p, rest);
    srcLength = cb->srcLength;
    cb->srcData_p += rest;
    v11 = cb->workPtr_p;
    v12 = cb->rest;
    srcTotal = cb->srcTotal;
    cb->srcLength = srcLength - rest;
    cb->srcTotal = srcTotal + rest;
    cb->workPtr_p = v11 + rest;
    cb->rest = v12 - rest;
    if (v12 == rest)
      Invoke(cb->onEnd, cb);
  }
}

// 0x15dd5e0
void sdfPacMemDecoderFuncInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr) {
  Il2CppObject *v5;
  u32 realSize;
  u64 *v8;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *v9;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o **p_resrcHead;
  s32 v11;
  u64 *v12;
  Il2CppObject *v14;
  Il2CppObject *v16;
  s32 compression;
  u64 *v18;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *resrcTail;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o **p_next;
  s32 header_p;
  u64 *v22;
  Il2CppObject *v24;
  struct sdf_PacDecode2_sdfPac2DecodeFunc_t_o *v25;
  s64 *v26;
  struct System_Byte_array *v27;
  s32 v29;
  Il2CppObject *v30;
  Il2CppObject *v31;
  u64 *v32;
  struct System_Byte_array *workPtr;
  intptr_t *v36;
  System_Object_array *v37;
  s64 *v38;
  s64 *v40;
  s32 v43;
  s32 v44;
  s32 v45;

  v5 = "sdfPackMemDecoderFuncInit";
  Log(v5, 0);
  realSize = hdr->realSize;
  if (realSize)
  {
    if ((cb->flag & 1) == 0)
      goto LABEL_10;
LABEL_24:
    compression = hdr->compression;
    SDF_ASSERT(compression == 0);
    v18 = Allocate(sdf_PacDecode2_sdfPac2DecodeResrc_t);
    _ctor(v18, 0);
    v18[6] = hdr;
    v18[3] = cb;
    resrcTail = cb->resrcTail;
    if (resrcTail)
      p_next = &resrcTail->next;
    else
      p_next = &cb->resrcHead;
    *p_next = v18;
    cb->resrcTail = v18;
    header_p = hdr->header_p;
    *(v18 + 10) = header_p;
    v45 = header_p;
    v22 = sub_8D3950(s32, &v45);
    v24 = Concat("sdfPacMemDecoderFuncInit2 : ", v22);
    Log(v24, 0);
    v25 = Allocate(sdf_PacDecode2_sdfPac2DecodeFunc_t);
    v26 = &Method_sdf_PacDecode2_sdfPacMemStayDecoderFunc__;
    goto LABEL_60;
  }
  realSize = hdr->size + (hdr->compression & 0xF0) - 16;
  if ((cb->flag & 1) != 0)
    goto LABEL_24;
LABEL_10:
  cb->stat = 2;
  v8 = Allocate(sdf_PacDecode2_sdfPac2DecodeResrc_t);
  _ctor(v8, 0);
  v8[6] = hdr;
  v8[3] = cb;
  v9 = cb->resrcTail;
  if (v9)
    p_resrcHead = &v9->next;
  else
    p_resrcHead = &cb->resrcHead;
  *p_resrcHead = v8;
  cb->resrcTail = v8;
  v11 = hdr->header_p;
  *(v8 + 10) = v11;
  v44 = v11;
  v12 = sub_8D3950(s32, &v44);
  v14 = Concat("sdfPacMemDecoderFuncInit2 : ", v12);
  Log(v14, 0);
  if ((cb->flag & 2) == 0)
  {
    v16 = "ALLOC HEAD";
    if ((byte_3F5A0D5 & 1) != 0)
      goto LABEL_40;
    goto LABEL_39;
  }
  v16 = "ALLOC TAIL";
LABEL_40:
  Log(v16, 0);
  v27 = NewSpecific(byte, realSize);
  v8[4] = v27;
  cb->workPtr = v27;
  cb->workPtr_p = 0;
  *(v8 + 10) = 0;
  v29 = hdr->compression & 0xF;
  if (v29 == 1)
  {
    v31 = "SDF_PAC_FILE_COMPRESS";
    Log(v31, 0);
    v32 = Allocate(sdfDecompCb_t);
    sdfDecompCb_t___ctor(v32);
    cb->decompWork = v32;
    workPtr = cb->workPtr;
    sdfDecompInit(v32, &workPtr->obj);
    v25 = Allocate(sdf_PacDecode2_sdfPac2DecodeFunc_t);
    v26 = &Method_sdf_PacDecode2_sdfPacMemDecompDecoderFunc__;
    goto LABEL_60;
  }
  if (!v29)
  {
    v30 = "SDF_PAC_FILE_NOCOMPRESS";
    Log(v30, 0);
    v25 = Allocate(sdf_PacDecode2_sdfPac2DecodeFunc_t);
    v26 = &Method_sdf_PacDecode2_sdfPacMemDecoderFunc__;
LABEL_60:
    v36 = *v26;
    v25->method_ptr = *v36;
    v25->m_target = 0;
    v25->method = v36;
    cb->decoder = v25;
    return;
  }
  v37 = NewSpecific(object, 1u);
  v43 = v29;
  v38 = sub_8D3950(s32, &v43);
  v40 = v38;
  v37->m_Items[0] = v40;
  SDF_ABORT2("sdfPacDecode: unknown compression mode. [%d]\n", v37);
}

// 0x15dcf60
void sdfPacMemDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr) {
  Il2CppObject *v5;
  struct sdf_PacDecode2_sdfPac2DecodeFunc_t_o *v7;
  s64 v8;

  v5 = "sdfPacMemDecoderInit";
  Log(v5, 0);
  sdfPacMemDecoderFuncInit(cb, hdr);
  v7 = Allocate(sdf_PacDecode2_sdfPac2DecodeFunc_t);
  v8 = Method_sdf_PacDecode2_sdfPacEndBlock__;
  v7->method_ptr = *Method_sdf_PacDecode2_sdfPacEndBlock__;
  v7->m_target = 0;
  v7->method = v8;
  cb->onEnd = v7;
}

// 0x15dd3b0
void sdfPacMemDecompDecoderFunc(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  Il2CppObject *v3;
  s32 srcLength;
  sdfDecompCb_t_o *decompWork;
  struct System_Byte_array *srcData;
  s32 v9;
  u32 v11;
  s32 v12;

  v3 = "sdfPacMemDecompDecoderFunc";
  Log(v3, 0);
  srcLength = cb->srcLength;
  decompWork = cb->decompWork;
  srcData = cb->srcData;
  v9 = sdfDecomp(decompWork, &srcData->obj, srcLength);
  v11 = srcLength - cb->decompWork->srcRemain;
  v12 = cb->srcLength - v11;
  cb->srcData_p += v11;
  cb->srcLength = v12;
  cb->srcTotal += v11;
  if (v9)
  {
    cb->decompWork = 0;
    Invoke(cb->onEnd, cb);
  }
}

// 0x15dd4e0
void sdfPacMemStayDecoderFunc(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  Il2CppObject *v3;
  s32 rest;
  s32 srcLength;
  s32 v7;
  s32 srcData_p;
  s32 srcTotal;
  s32 v10;

  v3 = "sdfPacMemStayDecoderFunc";
  Log(v3, 0);
  rest = cb->rest;
  srcLength = cb->srcLength;
  if (rest <= srcLength)
    v7 = cb->rest;
  else
    v7 = cb->srcLength;
  if (v7)
  {
    srcData_p = cb->srcData_p;
    srcTotal = cb->srcTotal;
    cb->srcLength = srcLength - v7;
    v10 = rest - v7;
    cb->rest = v10;
    cb->srcData_p = srcData_p + v7;
    cb->srcTotal = srcTotal + v7;
    if (!v10)
      Invoke(cb->onEnd, cb);
  }
}

// 0x15ddb90
void sdfPacModelDecoderEndFunc(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  Il2CppObject *v3;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *resrcTail;
  u64 *v5;
  System_Array_o *v7;

  v3 = "sdfPacModelDecoderEndFunc";
  Log(v3, 0);
  resrcTail = cb->resrcTail;
  v5 = Allocate(sdf_PacDecode2_AddressDecoder_t);
  v5[3] = NewSpecific(uint, 2u);
  _ctor(v5, 0);
  sdf_PacDecode2_AddressDecoder_t__Set(v5, cb->srcData, resrcTail->ptr);
  resrcTail->ptr += 16;
  v7 = NewSpecific(byte, *(v5 + 4));
  Copy_3886832(cb->srcData, resrcTail->ptr, v7, 0, *(v5 + 4), 0);
  sdfPacEndBlock(cb);
}

// 0x15dd040
void sdfPacModelDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr) {
  Il2CppObject *v5;
  struct sdf_PacDecode2_sdfPac2DecodeFunc_t_o *v7;
  s64 v8;

  v5 = "sdfPacModelDecoderInit";
  Log(v5, 0);
  sdfPacMemDecoderFuncInit(cb, hdr);
  v7 = Allocate(sdf_PacDecode2_sdfPac2DecodeFunc_t);
  v8 = Method_sdf_PacDecode2_sdfPacModelDecoderEndFunc__;
  v7->method_ptr = *Method_sdf_PacDecode2_sdfPacModelDecoderEndFunc__;
  v7->m_target = 0;
  v7->method = v8;
  cb->onEnd = v7;
}

// 0x15dde60
void sdfPacMotionDecoderEndFunc(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  Il2CppObject *v3;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *resrcTail;
  u64 *v5;
  System_Array_o *v7;

  v3 = "sdfPacMotionDecoderEndFunc";
  Log(v3, 0);
  resrcTail = cb->resrcTail;
  v5 = Allocate(sdf_PacDecode2_AddressDecoder_t);
  v5[3] = NewSpecific(uint, 2u);
  _ctor(v5, 0);
  sdf_PacDecode2_AddressDecoder_t__Set(v5, cb->srcData, resrcTail->ptr);
  resrcTail->ptr += 16;
  v7 = NewSpecific(byte, *(v5 + 4));
  Copy_3886832(cb->srcData, resrcTail->ptr, v7, 0, *(v5 + 4), 0);
  sdfPacEndBlock(cb);
}

// 0x15dd120
void sdfPacMotionDecoderInit(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr) {
  Il2CppObject *v5;
  struct sdf_PacDecode2_sdfPac2DecodeFunc_t_o *v7;
  s64 v8;

  v5 = "sdfPackMotionDecoderInit";
  Log(v5, 0);
  sdfPacMemDecoderFuncInit(cb, hdr);
  v7 = Allocate(sdf_PacDecode2_sdfPac2DecodeFunc_t);
  v8 = Method_sdf_PacDecode2_sdfPacMotionDecoderEndFunc__;
  v7->method_ptr = *Method_sdf_PacDecode2_sdfPacMotionDecoderEndFunc__;
  v7->m_target = 0;
  v7->method = v8;
  cb->onEnd = v7;
}

// 0x15db5c0
void sdfPacNewBlock(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  s32 srcTotal;
  System_Object_array *v4;
  s64 *v6;
  s64 *v7;
  s32 v9;
  s64 *v11;
  s64 *v12;
  s64 *v15;
  s64 *v16;
  Il2CppObject *v19;
  s32 srcLength;
  u64 *v28;
  s32 v30;
  s32 v31;
  System_Object_array *v32;
  s64 *v34;
  s64 *v35;
  s64 *v40;
  s64 *v41;
  Il2CppObject *v45;
  s32 v46;
  sdf_PacDecode2_sdfPac2Callback_t_o *callback;
  s32 v49;
  s32 v51;
  s32 v52;
  s32 v54;
  s32 v55;
  s32 v56;

  srcTotal = cb->srcTotal;
  v4 = NewSpecific(object, 6u);
  v4->m_Items[0] = "sdfPacNewBlock : cb.srcTotal = ";
  v56 = cb->srcTotal;
  v6 = sub_8D3950(s32, &v56);
  v7 = v6;
  v4->m_Items[1] = v7;
  v9 = srcTotal & 0x3F;
  v4->m_Items[2] = ",leng = ";
  v55 = v9;
  v11 = sub_8D3950(s32, &v55);
  v12 = v11;
  v4->m_Items[3] = v12;
  v4->m_Items[4] = ",HEADER_SIZE = ";
  v54 = 16;
  v15 = sub_8D3950(s32, &v54);
  v16 = v15;
  v4->m_Items[5] = v16;
  v19 = Concat_5270224(v4);
  else
  {
    Log(v19, 0);
    if (v9)
    {
LABEL_32:
      cb->stat = 1;
      cb->rest = 64 - v9;
      return;
    }
  }
  srcLength = cb->srcLength;
  SDF_ASSERT(srcLength > 15);
  v28 = Allocate(sdf_PacDecode2_sdfPac2StdBlockHeader_t);
  _ctor(v28, 0);
  sdf_PacDecode2_sdfPac2StdBlockHeader_t__Set(v28, cb->srcData, cb->srcData_p);
  *(v28 + 8) = cb->srcData_p + 16;
  v30 = cb->srcLength;
  cb->srcData_p += 16;
  cb->srcLength = v30 - 16;
  cb->srcTotal += 16;
  ++cb->currBlockNum;
  v31 = *(v28 + 17) & 0xF0;
  v32 = NewSpecific(object, 4u);
  v32->m_Items[0] = "header_add_size = ";
  v56 = v31;
  v34 = sub_8D3950(s32, &v56);
  v35 = v34;
  v32->m_Items[1] = v35;
  v32->m_Items[2] = ",compression = ";
  LOBYTE(v55) = *(v28 + 17);
  v40 = sub_8D3950(qword_3F088F8, &v55);
  v41 = v40;
  v32->m_Items[3] = v41;
  v45 = Concat_5270224(v32);
  v46 = v31 + 16;
  Log(v45, 0);
  SDF_ASSERT(*(v28 + 5) >= v46, 0);
  SDF_ASSERT(cb->srcLength >= v46);
  callback = cb->callback;
  cb->rest = *(v28 + 5) - v46;
  v49 = Invoke(callback, cb, 0, v28);
  if (v49 == 2)
  {
    cb->stat = 1;
    cb->rest = (cb->rest + 63) & 0xFFFFFFC0;
  }
  else
  {
    v51 = v49;
    if (v49 == 1)
    {
      v52 = -1;
    }
    else
    {
      SDF_ASSERT(v51 == 0);
      v52 = 2;
    }
    cb->stat = v52;
  }
}

// 0x15dcbb0
sdf_PacDecode2_sdfPac2DecodeResrc_t *sdfPacNewResrc(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, sdf_PacDecode2_sdfPac2StdBlockHeader_t *hdr) {
  Il2CppObject *v5;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o *resrcTail;
  struct sdf_PacDecode2_sdfPac2DecodeResrc_t_o **p_next;

  v5 = Allocate(sdf_PacDecode2_sdfPac2DecodeResrc_t);
  _ctor(v5, 0);
  v5[3].klass = hdr;
  v5[1].monitor = cb;
  resrcTail = cb->resrcTail;
  if (resrcTail)
    p_next = &resrcTail->next;
  else
    p_next = &cb->resrcHead;
  *p_next = v5;
  cb->resrcTail = v5;
  return v5;
}

// 0x15db560
void sdfPacSetFromTail(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  cb->flag |= 2u;
}

// 0x15db550
void sdfPacSetStay(sdf_PacDecode2_sdfPac2DecodeCb_t *cb) {
  cb->flag |= 1u;
}

// 0x15db5a0
void sdfPacUseSrc(sdf_PacDecode2_sdfPac2DecodeCb_t *cb, s32 size) {
  s32 v3;

  v3 = cb->srcLength - size;
  cb->srcData_p += size;
  cb->srcLength = v3;
  cb->srcTotal += size;
}

// 0x15ddd50
s32 sdf_PacDecode2_AddressDecoder_t__Set(sdf_PacDecode2_AddressDecoder_t *this, u8 **data, s32 index) {
  u32 v7;
  struct System_UInt32_array *pad;
  u32 v9;
  struct System_UInt32_array *v11;
  u32 v12;

  this->dataSize = ToUInt32(data, index, 0);
  v7 = ToUInt32(data, index + 4, 0);
  pad = this->pad;
  this->addrInfoSize = v7;
  v9 = ToUInt32(data, index + 8, 0);
  pad->m_Items[0] = v9;
  v11 = this->pad;
  v12 = ToUInt32(data, index + 12, 0);
  v11->m_Items[1] = v12;
  return index + 16;
}

// 0x15dbca0
void sdf_PacDecode2_sdfPac2StdBlockHeader_t__Set(sdf_PacDecode2_sdfPac2StdBlockHeader_t *this, u8 **dat, s32 idx) {
  s64 v8;

  v8 = idx + 1LL;
  this->fileType = dat->m_Items[idx];
  this->compression = dat->m_Items[v8];
  this->userId = ToUInt16(dat, idx + 2);
  this->size = ToUInt32(dat, idx + 4, 0);
  this->magicCode = ToUInt32(dat, idx + 8, 0);
  this->realSize = ToUInt32(dat, idx + 12, 0);
}

// 0x15db360
void update_buffer(u8 ***buf, s32 ptr, s32 len) {
  u64 v7;
  u64 *v8;
  System_Byte_array *v9;

  v7 = (len + ptr);
  v8 = NewSpecific(byte, v7);
  Copy_3886320(*buf, v8, (*buf)->max_length, 0);
  v9 = NewSpecific(byte, v7);
  *buf = v9;
  Copy_3886320(v8, v9, *(v8 + 6), 0);
}
