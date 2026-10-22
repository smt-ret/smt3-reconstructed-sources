#include "types.h"

void utf8_utf16(void **dst, u8 ***src, s32 *iidx);

// 0x1349ac0
u8 **EncodingSJIS(char *instr) {
  System_Text_Encoding_o *UTF8;
  u64 *v4;
  s32 max_length;
  s32 iidx;
  System_Collections_Generic_List_byte__o *dst;
  System_Byte_array *src;

  UTF8 = get_UTF8();
  src = (UTF8->klass->vtable._28_GetBytes.methodPtr)(UTF8, instr, UTF8->klass->vtable._28_GetBytes.method);
  v4 = Allocate(System_Collections_Generic_List_byte_);
  __ctor(v4);
  dst = v4;
  _Clear(v4);
  max_length = src->max_length;
  iidx = 0;
  if (max_length >= 1)
  {
    do
      utf8_utf16(&dst, &src, &iidx);
    while (iidx < max_length);
  }
  _Add(v4, 0);
  return _ToArray(v4);
}

// 0x13493d0
u16 encode(u16 code) {
  if ((code - 12353) <= 0x20u)
    return code + 20638;
  if ((code - 12386) <= 0x31u)
    return code + 20766;
  if ((code - 12449) <= 0x4Du)
    return code + 20753;
  if ((code - 12527) <= 7u)
    return code + 20881;
  if (code == 12540)
    return -32103;
  if ((code + 240) <= 9u || (code + 223) <= 0x19u)
    return code - 32384;
  if ((code + 191) >= 0x1Au)
    return -32448;
  return code - 32384;
}

// 0x13494b0
void utf8_utf16(void **dst, u8 ***src, s32 *iidx) {
  u8 v7;
  System_Collections_Generic_List_byte__o *v9;
  const MethodInfo_1260 *v10;
  u8 v11;
  s64 v12;
  s32 v14;
  s64 v17;
  s16 v19;
  System_Byte_array *v20;
  s64 v21;
  u32 max_length;
  System_Byte_array *v23;
  u8 v25;
  s64 v26;
  s16 v28;
  s16 v29;
  u8 v30;
  s64 v31;
  System_Byte_array *v33;
  s64 v34;
  u32 v36;
  s16 v37;

  v7 = (*src)->m_Items[*iidx];
  if (((*src)->m_Items[*iidx] & 0x80000000) == 0)
  {
    _Add(*dst, 0);
    v9 = *dst;
    v10 = Method_System_Collections_Generic_List_byte__Add__;
    v11 = v7;
LABEL_12:
    _Add(v9, v11, v10);
    v14 = *iidx + 1;
LABEL_13:
    *iidx = v14;
    return;
  }
  v12 = *iidx;
  if (((*src)->m_Items[v12] & 0xC0) == 0x80)
  {
    _Add(*dst, 0);
    v9 = *dst;
    v10 = Method_System_Collections_Generic_List_byte__Add__;
    v11 = 32;
    goto LABEL_12;
  }
  if (((*src)->m_Items[*iidx] & 0xE0) == 0xC0)
  {
    _Add(*dst, 0x81u);
    _Add(*dst, 0x40u);
    v14 = *iidx + 2;
    goto LABEL_13;
  }
  v17 = *iidx;
  v19 = (*src)->m_Items[v17];
  if (((*src)->m_Items[*iidx] & 0xF0) == 0xE0)
  {
    v20 = *src;
    v21 = *iidx;
    max_length = (*src)->max_length;
    v23 = *src;
    v25 = v20->m_Items[v21 + 1];
    v26 = v21 + 2LL;
    v28 = (v19 << 12) | ((v25 & 0x1F) << 6) | v23->m_Items[v26] & 0x3F;
    if ((v28 - 12353) > 0x20u)
    {
      if ((v28 - 12386) > 0x31u)
      {
        if ((v28 - 12449) > 0x4Du)
        {
          if ((v28 - 12527) > 7u)
          {
            if (v28 == 12540)
            {
              v30 = -126;
              LOBYTE(v29) = -103;
            }
            else if ((v28 + 240) > 9u && (v28 + 223) > 0x19u)
            {
              v36 = (v28 + 191);
              v37 = v28 - 32384;
              if (v36 >= 0x1A)
                v29 = -32448;
              else
                v29 = v37;
              v30 = HIBYTE(v29);
            }
            else
            {
              LOBYTE(v29) = v28 ^ 0x80;
              v30 = 0x80;
            }
          }
          else
          {
            LOBYTE(v29) = v28 - 111;
            v30 = -126;
          }
        }
        else
        {
          LOBYTE(v29) = v28 + 17;
          v30 = -127;
        }
      }
      else
      {
        LOBYTE(v29) = v28 + 30;
        v30 = -127;
      }
    }
    else
    {
      LOBYTE(v29) = v28 - 98;
      v30 = 0x80;
    }
    _Add(*dst, v30);
    _Add(*dst, v29);
    v14 = *iidx + 3;
    goto LABEL_13;
  }
  if ((v19 & 0xF8) == 0xF0)
  {
    Log("!!!!! Not Support 4 byte UTF8 !!!!!", 0);
    _Add(*dst, 0);
    _Add(*dst, 0x20u);
    v14 = *iidx + 4;
    goto LABEL_13;
  }
  v31 = *iidx;
  if (((*src)->m_Items[v31] & 0xFC) == 0xF8)
  {
    Log("!!!!! Not Support 5 byte UTF8 !!!!!", 0);
    _Add(*dst, 0);
    _Add(*dst, 0x20u);
    v14 = *iidx + 5;
    goto LABEL_13;
  }
  v33 = *src;
  v34 = *iidx;
  if ((v33->m_Items[v34] & 0xFE) == 0xFC)
  {
    Log("!!!!! Not Support 6 byte UTF8 !!!!!", 0);
    _Add(*dst, 0);
    _Add(*dst, 0x20u);
    v14 = *iidx + 6;
    goto LABEL_13;
  }
  Log("!!!!! HALT !!!!!!", 0);
}
