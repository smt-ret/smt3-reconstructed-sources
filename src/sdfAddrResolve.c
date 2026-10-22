#include "types.h"

// 0x17df9b0
void sdfAddressResolver(void *aDataBody, u32 aOffset, u8 aAddrInfoPtr, s32 aAddrInfoLeng) {
  ;
}

// 0x17df110
void sdfAddressResolverUnity(u8 **aDataBody, u32 aOffset, u8 **aAddrInfoPtr, u32 aAddrOfs, s32 aAddrInfoLeng) {
  s64 v10;
  s64 v11;
  u32 v12;
  il2cpp_array_size_t max_length;
  s64 v14;
  u32 v16;
  s64 v17;
  u32 v19;
  u8 v21;
  s64 v22;
  u32 v24;
  u32 v25;
  System_Byte_array *Bytes_3927696;
  s64 v29;
  s64 v34;
  u8 *v37;
  s64 v38;
  u32 v41;
  System_Byte_array *v42;
  u8 *v45;
  s64 v50;
  System_Byte_array *v51;
  u32 v52;

  if (aAddrInfoLeng >= 1)
  {
    v10 = aAddrInfoLeng;
    LODWORD(v11) = 0;
    v50 = aAddrInfoLeng;
    v12 = aAddrOfs;
    v52 = aAddrOfs;
    v51 = aAddrInfoPtr;
    do
    {
      while (1)
      {
        max_length = aAddrInfoPtr->max_length;
        v14 = v12;
        if (v12 >= max_length)
          return;
        ++v12;
        v16 = aAddrInfoPtr->m_Items[v14];
        if ((v16 & 1) != 0)
          break;
        v17 = v16 >> 1;
LABEL_20:
        v11 = 4 * v17 + v11;
        v25 = ToUInt32(aDataBody, v11, 0);
        Bytes_3927696 = GetBytes_3927696(v25 + aOffset);
        aDataBody->m_Items[v11] = Bytes_3927696->m_Items[0];
        v29 = v11 + 1LL;
        aDataBody->m_Items[v29] = Bytes_3927696->m_Items[1];
        aDataBody->m_Items[v11 + 2] = Bytes_3927696->m_Items[2];
        v34 = v11 + 3LL;
        aDataBody->m_Items[v34] = Bytes_3927696->m_Items[3];
        if (v12 - aAddrOfs >= v10)
          return;
      }
      if ((v16 & 2) == 0)
      {
        v17 = (v16 & 0xFFFF00FF | (aAddrInfoPtr->m_Items[v12] << 8)) >> 2;
        v12 = v14 + 2;
        goto LABEL_20;
      }
      if ((v16 & 4) == 0)
      {
        v19 = aAddrInfoPtr->max_length;
        v21 = aAddrInfoPtr->m_Items[v12];
        v22 = v14 + 2LL;
        v24 = v16 & 0xFFFF00FF | (v21 << 8);
        v12 = v14 + 3;
        v17 = (v24 & 0xFF00FFFF | (aAddrInfoPtr->m_Items[v22] << 16)) >> 3;
        goto LABEL_20;
      }
      v37 = &aDataBody->m_Items[v11 + 4];
      v38 = 0;
      do
      {
        v41 = ToUInt32(aDataBody, v11 + v38 + 4, 0);
        v42 = GetBytes_3927696(v41 + aOffset);
        v37[v38] = v42->m_Items[0];
        v45 = &v37[v38];
        v37[v38 + 1] = v42->m_Items[1];
        v45[2] = v42->m_Items[2];
        v38 += 4;
        v45[3] = v42->m_Items[3];
      }
      while (((v16 >> 1) & 0x7C) + 8 != v38);
      LODWORD(v11) = v11 + v38;
      aAddrOfs = v52;
      v10 = v50;
      aAddrInfoPtr = v51;
    }
    while (v12 - v52 < v50);
  }
}

// 0x17df5f0
void sdfAddressResolverUnity2(u8 **dat, u32 packet, u32 aOffset, u32 aAddrInfoPtr, s32 aAddrInfoLeng) {
  s64 v8;
  s64 v10;
  u32 v11;
  u32 v12;
  signed s32 v13;
  u32 v15;
  s64 v16;
  u32 v18;
  u8 v20;
  s64 v21;
  char *v23;
  u32 v24;
  u32 max_length;
  s64 v28;
  s64 v30;
  s64 v32;
  u8 *v33;
  u32 v34;
  u32 v35;
  s64 v40;
  u32 v41;

  LODWORD(v8) = packet;
  if (aAddrInfoLeng >= 1)
  {
    v10 = aAddrInfoLeng;
    v41 = aAddrInfoPtr;
    v40 = aAddrInfoLeng;
    v11 = aAddrInfoPtr;
    do
    {
      while (1)
      {
        v12 = v11 + 1;
        v13 = v11;
        v15 = dat->m_Items[v11];
        if ((v15 & 1) != 0)
          break;
        v16 = v15 >> 1;
LABEL_19:
        v8 = 4 * v16 + v8;
        v24 = ToUInt32(dat, v8, 0) + aOffset;
        max_length = dat->max_length;
        dat->m_Items[v8] = v24;
        dat->m_Items[v8 + 1] = v24 >> 1;
        v28 = v8 + 2LL;
        dat->m_Items[v28] = v24 >> 2;
        v30 = v8 + 3LL;
        dat->m_Items[v30] = v24 >> 3;
        v11 = v12;
        if (v12 - aAddrInfoPtr >= v10)
          return;
      }
      if ((v15 & 2) == 0)
      {
        v16 = (v15 & 0xFFFF00FF | (dat->m_Items[v12] << 8)) >> 2;
        v12 = v13 + 2;
        goto LABEL_19;
      }
      if ((v15 & 4) == 0)
      {
        v18 = dat->max_length;
        v20 = dat->m_Items[v12];
        v21 = v13 + 2LL;
        v23 = dat + v21;
        v12 = v13 + 3;
        v16 = (v15 & 0xFF0000FF | (v20 << 8) | (v23[32] << 16)) >> 3;
        goto LABEL_19;
      }
      v32 = 0;
      v33 = &dat->m_Items[v8 + 7];
      do
      {
        v34 = ToUInt32(dat, v8 + v32 + 4, 0) + aOffset;
        v35 = dat->max_length;
        dat->m_Items[(v8 + v32 + 4)] = v34;
        v33[v32 - 2] = v34 >> 1;
        v33[v32 - 1] = v34 >> 2;
        v33[v32] = v34 >> 3;
        v32 += 4;
      }
      while (((v15 >> 1) & 0x7C) + 8 != v32);
      aAddrInfoPtr = v41;
      v10 = v40;
      LODWORD(v8) = v8 + v32;
      v11 = v12;
    }
    while (v12 - v41 < v40);
  }
}
