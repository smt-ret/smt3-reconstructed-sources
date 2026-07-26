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
    sdfPacNewBlock(0);
    return 0;
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

  Log(StringLiteral_22044, 0);
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
}

// 0x15da5e0
void sdfPacModelDecoderEndFunc(sdfPacDecodeCb_t *cb) {
    sdfAddressResolver(0, 0, 0, 0);
    sdfPacEndBlock(0);
}

// 0x15d98d0
void sdfPacModelDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  u64 *v6;

  Write(StringLiteral_22046, 0);
  sdfPacMemDecoderFuncInit(cb, hdr);
  v6 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v6, 0, Method_sdf_PacDecode_sdfPacModelDecoderEndFunc__);
  cb->onEnd = v6;
}

// 0x15da720
void sdfPacMotionDecoderEndFunc(sdfPacDecodeCb_t *cb) {
    sdfAddressResolver(0, 0, 0, 0);
    sdfPacEndBlock(0);
}

// 0x15d9990
void sdfPacMotionDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  u64 *v6;

  Write(StringLiteral_22047, 0);
  sdfPacMemDecoderFuncInit(cb, hdr);
  v6 = Allocate(sdfPacDecodeFunc_t);
  sdfPacDecodeFunc_t___ctor(v6, 0, Method_sdf_PacDecode_sdfPacMotionDecoderEndFunc__);
  cb->onEnd = v6;
}

// 0x15d9d10
void sdfPacNewBlock(sdfPacDecodeCb_t *cb) {
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
    sdfPacMemDecoderInit(0, 0);
    sdfPacTmxDecoderInit(0, 0);
    sdfPacModelDecoderInit(0, 0);
    sdfPacMotionDecoderInit(0, 0);
    sdfPacTexListDecoderInit(0, 0);
    return 0;
}

// 0x15db130
void sdfPacTexListDecoder0(sdfPacDecodeCb_t *cb) {
}

// 0x15db070
void sdfPacTexListDecoder1(sdfPacDecodeCb_t *cb) {
    sdfPacTexListDecoderTmxStart(0);
}

// 0x15d9a50
void sdfPacTexListDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  sdfPacDecodeResrc_t_o *v4;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  struct sdfPacDecodeResrc_t_o **p_next;
  u64 *v7;

  Write(StringLiteral_22048, 0);
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
    sdfPacEndBlock(0);
    sdfPacTexListDecoderTmxStart(0);
}

// 0x15daf50
void sdfPacTexListDecoderTmxHeaderEndFunc(sdfPacDecodeCb_t *cb) {
    sdfPacTmxDecoderInitFunc(0, 0, 0);
}

// 0x15dae00
void sdfPacTexListDecoderTmxStart(sdfPacDecodeCb_t *cb) {
}

// 0x15dabf0
void sdfPacTmxDecoderEndFunc(sdfPacDecodeCb_t *cb) {
    sdfPacEndBlock(0);
}

// 0x15da860
void sdfPacTmxDecoderFunc(sdfPacDecodeCb_t *cb) {
}

// 0x15d9570
void sdfPacTmxDecoderInit(sdfPacDecodeCb_t *cb, sdfPacStdBlockHeader_t *hdr) {
  sdfPacDecodeResrc_t_o *v5;
  struct sdfPacDecodeResrc_t_o *resrcTail;
  struct sdfPacDecodeResrc_t_o **p_next;
  u64 *v9;

  Write(StringLiteral_22045, 0);
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
    sdfDecompInit(0, 0);
}

// 0x15daa20
void sdfPacTmxDecompDecoderFunc(sdfPacDecodeCb_t *cb) {

}

// 0x15daa60
void sdfPacTmxStayDecoderFunc(sdfPacDecodeCb_t *cb) {
}

// 0x15d9c80
void sdfPacUseSrc(sdfPacDecodeCb_t *cb, s32 size) {
}
