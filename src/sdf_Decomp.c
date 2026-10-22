#include "types.h"

typedef struct sdfDecompCb_t sdfDecompCb_t;

static u8 *src_start;
static u8 *dst_start;
static s32 direc_hist_index;
static s32 direc_hist[16];

s32 SDF_ABORT1(char *a);
void SDF_ABORT2(char *aFmt, void **LegacyParamArray);

// 0x15d8060
s32 sdfDecomp(sdfDecompCb_t *cb, void *src, s32 length) {
  u64 *v7;
  Il2CppObject *v9;
  s64 *Interface;
  s32 result;
  struct System_Byte_array *dstPtr;
  s32 v18;
  u32 v19;
  struct System_Byte_array *v22;
  char *v24;
  s64 v25;
  s32 v27;
  struct System_Byte_array *v28;
  u8 v30;
  s32 v31;
  s32 v32;
  s32 v34;
  struct System_Byte_array *v35;
  u8 v37;
  u8 *v38;
  s32 v39;
  struct System_Byte_array *v43;
  s32 v45;
  s32 v46;
  struct System_Byte_array *v49;
  u64 *v51;
  u64 *v52;
  s64 *v53;
  s64 *v55;
  s64 *v57;
  s64 v58;
  s32 v59;
  s32 v60;
  u8 *v61;
  struct System_Byte_array *v63;
  u8 v65;
  u64 *v68;
  s64 *v69;
  s64 *v71;
  s32 direcLeng;
  struct System_Int32_array *direc_hist;
  s64 direc_hist_index;
  s64 v82;
  s64 v83;
  struct System_Byte_array *src_start;
  u32 v87;
  System_String_array *v88;
  s64 *v91;
  s64 *v92;
  s64 *v97;
  s64 *v98;
  s64 *v103;
  s64 *v104;
  Il2CppObject *v108;
  struct System_Byte_array *v110;
  struct System_Byte_array *v113;
  u32 v116;
  s32 v119;
  bool v120;
  u64 *v121;
  u64 *v122;
  u8 *p_direc;
  u32 v124;
  u8 v125[4];
  u64 v126[3];

  v125[0] = 0;
  v124 = 0;
  LODWORD(v126[0]) = length;
  v7 = sub_8D3950(s32, v126);
  v9 = Concat("sdfDecomp = ", v7);
  Log(v9, 0);
  if (!cb->stat)
    return 1;
  else
  {
    if (src)
      goto LABEL_10;
  }
  Interface = 0;
LABEL_18:
  src_start = Interface;
  direc_hist_index = 0;
  dstPtr = cb->dstPtr;
  if (length < 1)
  {
    v18 = 0;
    goto LABEL_243;
  }
  p_direc = &cb->direc;
  v18 = 0;
  v19 = 0;
  while (2)
  {
    switch (cb->stat)
    {
      case 1u:
        Log("SDF_DECOMP_STAT_IDLE", 0);
        v82 = direc_hist + 4 * direc_hist_index;
        v83 = v18;
        *(v82 + 32) = v18;
        direc_hist_index = (LODWORD(direc_hist->max_length)
                                                              - 1)
                                                             & (direc_hist_index + 1);
        v87 = src_start->m_Items[v18++];
        --length;
        v125[0] = src_start->m_Items[v83];
        if (v87 >= 0xE0)
        {
          if (v87 == 255)
          {
            Log("SDF_DECOMP_CMD_END", 0);
            cb->stat = 0;
            LODWORD(v126[0]) = v18;
            v122 = sub_8D3950(s32, v126);
            cb->dstPtr = dstPtr;
            cb->srcPtr = v122;
            result = 1;
            goto LABEL_244;
          }
          v51 = NewSpecific(object, 1u);
          LOBYTE(v126[0]) = v125[0];
          v52 = v51;
          v53 = sub_8D3950(qword_3F088F8, v126);
          v55 = v53;
          v52[4] = v55;
          v57 = &"sdfDecomp : unknown command [%02X]\n";
LABEL_125:
          SDF_ABORT2(*v57, v52);
          if (length <= 0)
            goto LABEL_243;
        }
        else
        {
          *p_direc = v87 & 0xE0;
          v124 = v87 & 0x1F;
          v88 = NewSpecific(string, 6u);
          v88->m_Items[0] = "BITDATA = ";
          v91 = sub_3C25C0(v125, "X");
          v92 = v91;
          v88->m_Items[1] = v92;
          v88->m_Items[2] = ",";
          v97 = sub_3C25C0(p_direc, "X");
          v98 = v97;
          v88->m_Items[3] = v98;
          v88->m_Items[4] = ",";
          v103 = sub_232A70(&v124, "X");
          v104 = v103;
          v88->m_Items[5] = v104;
          v108 = Concat_5271600(v88);
          Log(v108, 0);
          if (v124)
          {
            cb->direcLeng = v124;
LABEL_216:
            cb->stat = 4;
            if (length <= 0)
              goto LABEL_243;
          }
          else
          {
            cb->stat = 2;
            if (length <= 0)
              goto LABEL_243;
          }
        }
        continue;
      case 2u:
        Log("SDF_DECOMP_STAT_DIREC_LENG0", 0);
        v110 = src_start;
        v125[0] = v110->m_Items[v18];
        cb->direcLeng = v125[0];
        ++v18;
        --length;
        cb->stat = 3;
        if (length <= 0)
          goto LABEL_243;
        continue;
      case 3u:
        Log("SDF_DECOMP_STAT_DIREC_LENG1", 0);
        v113 = src_start;
        v125[0] = v113->m_Items[v18++];
        cb->direcLeng |= v125[0] << 8;
        length -= 2;
        goto LABEL_216;
      case 4u:
        Log("SDF_DECOMP_STAT_DIREC", 0);
        v116 = *p_direc;
        if (v116 > 0x40)
        {
          switch (v116)
          {
            case 0x60u:
              Log("SDF_DECOMP_DIRECTIVE_SD", 0);
              cb->stat = 7;
              if (length <= 0)
                goto LABEL_243;
              break;
            case 0x80u:
              Log("SDF_DECOMP_DIRECTIVE_SD2", 0);
              cb->stat = 8;
              if (length <= 0)
                goto LABEL_243;
              break;
            case 0xA0u:
              Log("SDF_DECOMP_DIRECTIVE_WORD", 0);
              cb->stat = 10;
              if (length <= 0)
                goto LABEL_243;
              break;
            default:
              goto LABEL_116;
          }
        }
        else if (*p_direc)
        {
          if (v116 == 32)
          {
            Log("SDF_DECOMP_DIRECTIVE_ZERO", 0);
            direcLeng = cb->direcLeng;
            Clear(dstPtr, v19, direcLeng, 0);
            v19 += direcLeng;
            cb->stat = 1;
            if (length <= 0)
              goto LABEL_243;
          }
          else
          {
            if (v116 != 64)
            {
LABEL_116:
              v68 = NewSpecific(object, 1u);
              LOBYTE(v126[0]) = *p_direc;
              v52 = v68;
              v69 = sub_8D3950(qword_3F088F8, v126);
              v71 = v69;
              v52[4] = v71;
              v57 = &"sdfDecomp : unknown directive [%02X]\n";
              goto LABEL_125;
            }
            Log("SDF_DECOMP_DIRECTIVE_RLE", 0);
            cb->stat = 6;
            if (length <= 0)
              goto LABEL_243;
          }
        }
        else
        {
          Log("SDF_DECOMP_DIRECTIVE_NORMAL", 0);
          cb->stat = 5;
          if (length <= 0)
            goto LABEL_243;
        }
        continue;
      case 5u:
        Log("SDF_DECOMP_STAT_DEC_NORMAL", 0);
        if (length >= cb->direcLeng)
          v119 = cb->direcLeng;
        else
          v119 = length;
        Copy_3880080(src_start, v18, dstPtr, v19, v119);
        v19 += v119;
        v18 += v119;
        length -= v119;
        v120 = (cb->direcLeng - v119) == 0;
        cb->direcLeng -= v119;
        if (v120)
          goto LABEL_60;
        if (length <= 0)
          goto LABEL_243;
        continue;
      case 6u:
        Log("SDF_DECOMP_STAT_DEC_RLE", 0);
        v34 = cb->direcLeng;
        v35 = src_start;
        v37 = v35->m_Items[v18++];
        --length;
        v125[0] = v37;
        if (!v34)
          goto LABEL_60;
        v38 = &dstPtr->m_Items[v19];
        v39 = v34 - 1;
        if (v19 >= LODWORD(dstPtr->max_length))
          goto LABEL_57;
        while (1)
        {
          *v38 = v37;
          if (!v39)
            break;
          v37 = v125[0];
          ++v38;
          ++v19;
          --v39;
          if (v19 >= LODWORD(dstPtr->max_length))
          {
LABEL_57:
          }
        }
        ++v19;
LABEL_60:
        cb->stat = 1;
        if (length <= 0)
          goto LABEL_243;
        continue;
      case 7u:
        Log("SDF_DECOMP_STAT_DEC_SD_STEP0", 0);
        v27 = cb->direcLeng;
        v43 = src_start;
        v45 = v43->m_Items[v18++];
        --length;
        v46 = v19 - v45;
        goto LABEL_81;
      case 8u:
        Log("SDF_DECOMP_STAT_DEC_SD_STEP1", 0);
        v22 = src_start;
        v24 = v22 + v18;
        v25 = v18 + 1LL;
        cb->sdOfs = v24[32];
        if (length != 1)
        {
          v27 = cb->direcLeng;
          v28 = src_start;
          v30 = v28->m_Items[v25];
          v18 += 2;
          length -= 2;
LABEL_80:
          v46 = v19 - (cb->sdOfs | (v30 << 8));
LABEL_81:
          Copy_3880080(dstPtr, v46, dstPtr, v19, v27);
          cb->stat = 1;
          if (length <= 0)
            goto LABEL_243;
          continue;
        }
        length = 0;
        ++v18;
        cb->stat = 9;
LABEL_243:
        LODWORD(v126[0]) = v18;
        v121 = sub_8D3950(s32, v126);
        result = 0;
        cb->dstPtr = dstPtr;
        cb->srcPtr = v121;
LABEL_244:
        cb->srcRemain = length;
        return result;
      case 9u:
        Log("SDF_DECOMP_STAT_DEC_SD_STEP2", 0);
        v27 = cb->direcLeng;
        v49 = src_start;
        v30 = v49->m_Items[v18++];
        --length;
        goto LABEL_80;
      case 0xAu:
        Log("SDF_DECOMP_STAT_DEC_SD_WORD", 0);
        v31 = cb->direcLeng;
        v32 = length - v31;
        if (length >= v31)
        {
          cb->direcLeng = 0;
          cb->stat = 1;
        }
        else
        {
          v32 = 0;
          cb->direcLeng = v31 - length;
        }
        v58 = v18 + 32LL;
        v59 = ~v31;
        if (~length > v59)
          v59 = ~length;
        v60 = v59 + 1;
        v61 = &dstPtr->m_Items[v19 + 1];
        do
        {
          v63 = src_start;
          v65 = *(&v63->obj.klass + v58);
          *(v61 - 1) = v65;
          ++v18;
          ++v58;
          ++v60;
          v19 += 2;
          *v61 = 0;
          v61 += 2;
        }
        while (v60);
        length = v32;
        if (v32 <= 0)
          goto LABEL_243;
        continue;
      default:
        SDF_ABORT1("sdfDecomp : illegal stat.\n");
        if (length <= 0)
          goto LABEL_243;
        continue;
    }
  }
}

// 0x15d9120
void sdfDecompInit(sdfDecompCb_t *cb, void *dst) {
  Il2CppClass *v5;
  s64 *Interface;
  char *v7;
  s64 *v8;
  Il2CppClass *v10;
  s64 *v11;
  char *v12;
  s64 *v13;
  u64 v14[2];
  char *v15;

  cb->stat = 1;
  if (dst)
  {
    Interface = QueryInterface(dst, byte);
    if (!Interface)
    {
      sub_8FC2C0(dst->klass->_1.element_class, v5, v14);
      if ((v14[0] & 1) != 0)
        v7 = v15;
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  else
  {
    Interface = 0;
  }
  cb->dstPtr = Interface;
  if (!dst)
    goto LABEL_19;
LABEL_13:
  v11 = QueryInterface(dst, byte);
  if (!v11)
  {
    sub_8FC2C0(dst->klass->_1.element_class, v10, v14);
    if ((v14[0] & 1) != 0)
      v12 = v15;
    else
      v12 = v14 + 1;
    v13 = sub_8C4940(v12);
  }
LABEL_20:
  dst_start = v11;
}
