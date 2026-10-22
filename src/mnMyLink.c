#include "types.h"

typedef struct mnMyLink_h_tagPipeLData mnMyLink_h_tagPipeLData;
typedef struct mnMyLink_h_tagPipeLTable mnMyLink_h_tagPipeLTable;
typedef struct mnMyLink_h_tagPipeLinkData mnMyLink_h_tagPipeLinkData;
typedef struct mnMyLink_h_tagPipeLinkInfo mnMyLink_h_tagPipeLinkInfo;

struct mnMyLink_h_tagPipeLinkInfo {
    mnMyLink_h_tagPipeLinkData *aHandle;
    mnMyLink_h_tagPipeLinkData *linkPtr;
    s32 nodeMax;
    s32 linkIndex;
};

struct mnMyLink_h_tagPipeLinkData {
    u16 indexID;
    u16 partsID;
    void *next;
    void *prev;
    u16 resv;
};

struct mnMyLink_h_tagPipeLData {
    u8 data;
    mnMyLink_h_tagPipeLData *link;
};

struct mnMyLink_h_tagPipeLTable {
    s32 linkMax;
    mnMyLink_h_tagPipeLData *link;
};

s32 pipeCreateLink(mnMyLink_h_tagPipeLinkInfo *pInfo, s32 nodeNum);
s32 pipeInitLink(mnMyLink_h_tagPipeLinkInfo *pInfo);
mnMyLink_h_tagPipeLinkData *pipeMakeNodeLink(mnMyLink_h_tagPipeLinkInfo *pInfo);

// 0x19b9af0
s32 LoadLinkData(mnMyLink_h_tagPipeLinkInfo **linkInfoPtr, mnMyLink_h_tagPipeLTable *linkTablePtr, s32 mode) {
  struct mnMyLink_h_tagPipeLData_o *link;
  s32 linkMax;
  u32 v8;
  struct mnMyLink_h_tagPipeLData_o *v9;
  mnMyLink_h_tagPipeLinkData_o *NodeLink;
  u32 data;
  s16 v14;
  char v15;
  struct mnMyLink_h_tagPipeLinkData_o *v16;
  char v17;
  s32 v18;
  s16 v19;
  u32 v20;
  mnMyLink_h_tagPipeLinkData_o *v21;
  u32 v22;
  s32 v23;
  char v24;
  mnMyLink_h_tagPipeLinkData_o *v25;
  char v26;
  s32 v27;

  link = linkTablePtr->link;
  if (link)
  {
    linkMax = linkTablePtr->linkMax;
    v8 = 1;
    if (linkMax >= 2)
    {
      v8 = 1;
      v9 = link;
      do
      {
        if (++v8 >= linkMax)
          break;
        v9 = v9->link;
      }
      while (v9);
    }
  }
  else
  {
    v8 = 1;
  }
  pipeCreateLink(*linkInfoPtr, v8, *&mode);
  NodeLink = pipeMakeNodeLink(*linkInfoPtr);
  data = link->data;
  v14 = data > 0xA;
  if (link->data)
    v15 = link->data;
  else
    v15 = 6;
  NodeLink->indexID = 1;
  v16 = NodeLink;
  if (data >= 0xB)
    v17 = data - 10;
  else
    v17 = v15;
  {
  }
  v18 = v17;
  v19 = v17 | (v14 << 6);
  v20 = 1;
  v16->partsID = v19 | 8;
  (*linkInfoPtr)->linkPtr = v16;
  do
  {
    link = link->link;
    v21 = pipeMakeNodeLink(*linkInfoPtr);
    v22 = link->data;
    v23 = v22 > 0xA;
    if (link->data)
      v24 = link->data;
    else
      v24 = 6;
    v25 = v21;
    if (v22 >= 0xB)
      v26 = v22 - 10;
    else
      v26 = v24;
    {
    }
    v27 = (v23 << 6) | ((117440512 - (v18 << 24)) >> 21);
    v18 = v26;
    v25->partsID = v27 | v26;
    if (v25)
    {
      v16->next = v25;
      v25->prev = v16;
    }
    ++v20;
    v16 = v25;
  }
  while (v20 < v8);
  v25->indexID = -1;
  return 1;
}

// 0x19b9f60
s32 MAKEPTYPE(s32 t, s32 h, s32 l) {
  return (8 * h) | (t << 6) | l;
}

// 0x19ba0a0
mnMyLink_h_tagPipeLinkData *PLINFO_GETPTR(mnMyLink_h_tagPipeLinkInfo *o) {
  struct mnMyLink_h_tagPipeLinkData_array *aHandle;

  aHandle = o->aHandle;
  return aHandle->m_Items[0];
}

// 0x19ba7a0
s32 PTYPE2_BACK(s32 o) {
  {
  }
  return o | 0x68;
}

// 0x19bd280
s32 PTYPE2_BDOWN(void) {
  {
    if ((byte_3F5AC9D & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 110;
  }
  return 110;
}

// 0x19bd4c0
s32 PTYPE2_BFRONT(void) {
  {
    if ((byte_3F5AC9D & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 106;
  }
  return 106;
}

// 0x19bd340
s32 PTYPE2_BLEFT(void) {
  {
    if ((byte_3F5AC9D & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 107;
  }
  return 107;
}

// 0x19bd400
s32 PTYPE2_BRIGHT(void) {
  {
    if ((byte_3F5AC9D & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 108;
  }
  return 108;
}

// 0x19bd1c0
s32 PTYPE2_BUP(void) {
  {
    if ((byte_3F5AC9D & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 105;
  }
  return 105;
}

// 0x19bc500
s32 PTYPE2_DBACK(void) {
  {
    if ((byte_3F5AC9A & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 117;
  }
  return 117;
}

// 0x19bc5c0
s32 PTYPE2_DFRONT(void) {
  {
    if ((byte_3F5AC9A & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 114;
  }
  return 114;
}

// 0x19bc380
s32 PTYPE2_DLEFT(void) {
  {
    if ((byte_3F5AC9A & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 115;
  }
  return 115;
}

// 0x19ba630
s32 PTYPE2_DOWN(s32 o) {
  {
    return o | 0x70;
  }
  return o | 0x70;
}

// 0x19bc440
s32 PTYPE2_DRIGHT(void) {
  {
    if ((byte_3F5AC9A & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 116;
  }
  return 116;
}

// 0x19bc2c0
s32 PTYPE2_DUP(void) {
  {
    if ((byte_3F5AC9A & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 113;
  }
  return 113;
}

// 0x19bd100
s32 PTYPE2_FBACK(void) {
  {
    if ((byte_3F5AC9E & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 85;
  }
  return 85;
}

// 0x19bcec0
s32 PTYPE2_FDOWN(void) {
  {
    if ((byte_3F5AC9E & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 86;
  }
  return 86;
}

// 0x19bcf80
s32 PTYPE2_FLEFT(void) {
  {
    if ((byte_3F5AC9E & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 83;
  }
  return 83;
}

// 0x19bd040
s32 PTYPE2_FRIGHT(void) {
  {
    if ((byte_3F5AC9E & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 84;
  }
  return 84;
}

// 0x19ba810
s32 PTYPE2_FRONT(s32 o) {
  {
  }
  return o | 0x50;
}

// 0x19bce00
s32 PTYPE2_FUP(void) {
  {
    if ((byte_3F5AC9E & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 81;
  }
  return 81;
}

// 0x19bc8c0
s32 PTYPE2_LBACK(void) {
  {
    if ((byte_3F5AC9B & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 93;
  }
  return 93;
}

// 0x19bc740
s32 PTYPE2_LDOWN(void) {
  {
    if ((byte_3F5AC9B & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 94;
  }
  return 94;
}

// 0x19ba6b0
s32 PTYPE2_LEFT(s32 o) {
  {
  }
  return o | 0x58;
}

// 0x19bc980
s32 PTYPE2_LFRONT(void) {
  {
    if ((byte_3F5AC9B & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 90;
  }
  return 90;
}

// 0x19bc800
s32 PTYPE2_LRIGHT(void) {
  {
    if ((byte_3F5AC9B & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 92;
  }
  return 92;
}

// 0x19bc680
s32 PTYPE2_LUP(void) {
  {
    if ((byte_3F5AC9B & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 89;
  }
  return 89;
}

// 0x19bcc80
s32 PTYPE2_RBACK(void) {
  {
    if ((byte_3F5AC9C & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 101;
  }
  return 101;
}

// 0x19bcb00
s32 PTYPE2_RDOWN(void) {
  {
    if ((byte_3F5AC9C & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 102;
  }
  return 102;
}

// 0x19bcd40
s32 PTYPE2_RFRONT(void) {
  {
    if ((byte_3F5AC9C & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 98;
  }
  return 98;
}

// 0x19ba720
s32 PTYPE2_RIGHT(s32 o) {
  {
    return o | 0x60;
  }
  return o | 0x60;
}

// 0x19bcbc0
s32 PTYPE2_RLEFT(void) {
  {
    if ((byte_3F5AC9C & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 99;
  }
  return 99;
}

// 0x19bca40
s32 PTYPE2_RUP(void) {
  {
    if ((byte_3F5AC9C & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 97;
  }
  return 97;
}

// 0x19bc140
s32 PTYPE2_UBACK(void) {
  {
    if ((byte_3F5AC99 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 77;
  }
  return 77;
}

// 0x19bbf00
s32 PTYPE2_UDOWN(void) {
  {
    if ((byte_3F5AC99 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 78;
  }
  return 78;
}

// 0x19bc200
s32 PTYPE2_UFRONT(void) {
  {
    if ((byte_3F5AC99 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 74;
  }
  return 74;
}

// 0x19bbfc0
s32 PTYPE2_ULEFT(void) {
  {
    if ((byte_3F5AC99 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 75;
  }
  return 75;
}

// 0x19ba5c0
s32 PTYPE2_UP(s32 o) {
  {
  }
  return o | 0x48;
}

// 0x19bc080
s32 PTYPE2_URIGHT(void) {
  {
    if ((byte_3F5AC99 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 76;
  }
  return 76;
}

// 0x19ba4d0
s32 PTYPE_BACK(s32 o) {
  {
  }
  return o | 0x28;
}

// 0x19bbc00
s32 PTYPE_BDOWN(void) {
  {
    if ((byte_3F5AC97 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 46;
  }
  return 46;
}

// 0x19bbe40
s32 PTYPE_BFRONT(void) {
  {
    if ((byte_3F5AC97 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 42;
  }
  return 42;
}

// 0x19bbcc0
s32 PTYPE_BLEFT(void) {
  {
    if ((byte_3F5AC97 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 43;
  }
  return 43;
}

// 0x19bbd80
s32 PTYPE_BRIGHT(void) {
  {
    if ((byte_3F5AC97 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 44;
  }
  return 44;
}

// 0x19bbb40
s32 PTYPE_BUP(void) {
  {
    if ((byte_3F5AC97 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 41;
  }
  return 41;
}

// 0x19bae80
s32 PTYPE_DBACK(void) {
  {
    if ((byte_3F5AC94 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 53;
  }
  return 53;
}

// 0x19baf40
s32 PTYPE_DFRONT(void) {
  {
    if ((byte_3F5AC94 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 50;
  }
  return 50;
}

// 0x19bad00
s32 PTYPE_DLEFT(void) {
  {
    if ((byte_3F5AC94 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 51;
  }
  return 51;
}

// 0x19ba350
s32 PTYPE_DOWN(s32 o) {
  {
    return o | 0x30;
  }
  return o | 0x30;
}

// 0x19badc0
s32 PTYPE_DRIGHT(void) {
  {
    if ((byte_3F5AC94 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 52;
  }
  return 52;
}

// 0x19bac40
s32 PTYPE_DUP(void) {
  {
    if ((byte_3F5AC94 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 49;
  }
  return 49;
}

// 0x19bba80
s32 PTYPE_FBACK(void) {
  {
    if ((byte_3F5AC98 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 21;
  }
  return 21;
}

// 0x19bb840
s32 PTYPE_FDOWN(void) {
  {
    if ((byte_3F5AC98 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 22;
  }
  return 22;
}

// 0x19bb900
s32 PTYPE_FLEFT(void) {
  {
    if ((byte_3F5AC98 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 19;
  }
  return 19;
}

// 0x19bb9c0
s32 PTYPE_FRIGHT(void) {
  {
    if ((byte_3F5AC98 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 20;
  }
  return 20;
}

// 0x19ba540
s32 PTYPE_FRONT(s32 o) {
  {
    return o | 0x10;
  }
  return o | 0x10;
}

// 0x19bb780
s32 PTYPE_FUP(void) {
  {
    if ((byte_3F5AC98 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 17;
  }
  return 17;
}

// 0x19bb240
s32 PTYPE_LBACK(void) {
  {
    if ((byte_3F5AC95 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 29;
  }
  return 29;
}

// 0x19bb0c0
s32 PTYPE_LDOWN(void) {
  {
    if ((byte_3F5AC95 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 30;
  }
  return 30;
}

// 0x19ba3d0
s32 PTYPE_LEFT(s32 o) {
  {
    return o | 0x18;
  }
  return o | 0x18;
}

// 0x19bb300
s32 PTYPE_LFRONT(void) {
  {
    if ((byte_3F5AC95 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 26;
  }
  return 26;
}

// 0x19bb180
s32 PTYPE_LRIGHT(void) {
  {
    if ((byte_3F5AC95 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 28;
  }
  return 28;
}

// 0x19bb000
s32 PTYPE_LUP(void) {
  {
    if ((byte_3F5AC95 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 25;
  }
  return 25;
}

// 0x19bb600
s32 PTYPE_RBACK(void) {
  {
    if ((byte_3F5AC96 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 37;
  }
  return 37;
}

// 0x19bb480
s32 PTYPE_RDOWN(void) {
  {
    if ((byte_3F5AC96 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 38;
  }
  return 38;
}

// 0x19bb6c0
s32 PTYPE_RFRONT(void) {
  {
    if ((byte_3F5AC96 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 34;
  }
  return 34;
}

// 0x19ba450
s32 PTYPE_RIGHT(s32 o) {
  {
    return o | 0x20;
  }
  return o | 0x20;
}

// 0x19bb540
s32 PTYPE_RLEFT(void) {
  {
    if ((byte_3F5AC96 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 35;
  }
  return 35;
}

// 0x19bb3c0
s32 PTYPE_RUP(void) {
  {
    if ((byte_3F5AC96 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 33;
  }
  return 33;
}

// 0x19baac0
s32 PTYPE_UBACK(void) {
  {
    if ((byte_3F5AC93 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 13;
  }
  return 13;
}

// 0x19ba880
s32 PTYPE_UDOWN(void) {
  {
    if ((byte_3F5AC93 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 14;
  }
  return 14;
}

// 0x19bab80
s32 PTYPE_UFRONT(void) {
  {
    if ((byte_3F5AC93 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 10;
  }
  return 10;
}

// 0x19ba940
s32 PTYPE_ULEFT(void) {
  {
    if ((byte_3F5AC93 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 11;
  }
  return 11;
}

// 0x19ba2d0
s32 PTYPE_UP(s32 o) {
  {
    return o | 8;
  }
  return o | 8;
}

// 0x19baa00
s32 PTYPE_URIGHT(void) {
  {
    if ((byte_3F5AC93 & 1) != 0)
      goto LABEL_7;
    goto LABEL_6;
  }
LABEL_7:
  {
    return 12;
  }
  return 12;
}

// 0x19b9f70
s32 pipeConnectLink(mnMyLink_h_tagPipeLinkData *pPrev, mnMyLink_h_tagPipeLinkData *pNext) {
  s32 result;

  result = 0;
  if (pPrev)
  {
    if (pNext)
    {
      pPrev->next = pNext;
      pNext->prev = pPrev;
      return 1;
    }
  }
  return result;
}

// 0x19b9cd0
s32 pipeCreateLink(mnMyLink_h_tagPipeLinkInfo *pInfo, s32 nodeNum) {
  struct mnMyLink_h_tagPipeLinkData_array *v5;
  u32 *aHandle;
  u64 i;
  u64 *v9;

  if (!pInfo)
    return 0;
  v5 = NewSpecific(mnMyLink_h_tagPipeLinkData, nodeNum);
  pInfo->aHandle = v5;
  if (nodeNum >= 1)
  {
    aHandle = v5;
    for (i = 0; ; ++i)
    {
      v9 = Allocate(mnMyLink_h_tagPipeLinkData);
      _ctor(v9, 0);
      *&aHandle[2 * i + 8] = v9;
      if (nodeNum - 1LL == i)
        break;
      aHandle = pInfo->aHandle;
    }
  }
  pInfo->nodeMax = nodeNum;
  pipeInitLink(pInfo);
  return 1;
}

// 0x19ba0f0
s32 pipeDellLink(mnMyLink_h_tagPipeLinkData *pData) {
  Il2CppObject *prev;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *next;
  Il2CppClass *v9;
  s64 v10;
  char *v11;
  s64 *v12;
  u64 v14[2];
  char *v15;

  if (!pData)
    return 0;
  prev = pData->prev;
  if (prev)
  {
    klass = prev->klass;
    if (prev->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mnMyLink_h_tagPipeLinkData)
    {
      sub_8FC2C0(klass->_1.element_class, mnMyLink_h_tagPipeLinkData, v14);
      if ((v14[0] & 1) != 0)
        v6 = v15;
      else
        v6 = v14 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  next = pData->next;
  if (next)
  {
    v9 = next->klass;
    if (next->klass->_2.typeHierarchyDepth < v10
      || v9->_2.typeHierarchy[v10 - 1] != mnMyLink_h_tagPipeLinkData)
    {
      sub_8FC2C0(v9->_1.element_class, mnMyLink_h_tagPipeLinkData, v14);
      if ((v14[0] & 1) != 0)
        v11 = v15;
      else
        v11 = v14 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  if (prev)
    prev[1].monitor = next;
  if (next)
    next[2].klass = prev;
  return 1;
}

// 0x19ba290
void pipeFreeLink(mnMyLink_h_tagPipeLinkInfo *pInfo) {
  if (pInfo)
  {
    if (pInfo->aHandle)
    {
      pipeInitLink(pInfo);
      pInfo->aHandle = 0;
    }
  }
}

// 0x19b9fa0
s32 pipeInitLink(mnMyLink_h_tagPipeLinkInfo *pInfo) {
  u64 v4;
  struct mnMyLink_h_tagPipeLinkData_array *aHandle;
  Il2CppClass **v7;

  if (pInfo)
  {
    {
      if (!LODWORD(pInfo->aHandle->max_length))
      {
LABEL_7:
      }
    }
    else if (!LODWORD(pInfo->aHandle->max_length))
    {
      goto LABEL_7;
    }
    if (pInfo->nodeMax >= 1)
    {
      v4 = 0;
      do
      {
        aHandle = pInfo->aHandle;
        v7 = &aHandle->obj.klass + v4++;
        LOWORD(v7[4]->_1.name) = 0;
      }
      while (v4 < pInfo->nodeMax);
    }
    pInfo->linkPtr = 0;
    pInfo->linkIndex = 1;
  }
  return 0;
}

// 0x19b9ca0
s32 pipeLinkGetNum(mnMyLink_h_tagPipeLData *lPtr, s32 size) {
  s32 result;

  result = 1;
  if (size >= 2 && lPtr)
  {
    result = 1;
    do
    {
      if (++result >= size)
        break;
      lPtr = lPtr->link;
    }
    while (lPtr);
  }
  return result;
}

// 0x19b9e10
mnMyLink_h_tagPipeLinkData *pipeMakeNodeLink(mnMyLink_h_tagPipeLinkInfo *pInfo) {
  s64 i;
  struct mnMyLink_h_tagPipeLinkData_array *aHandle;
  s64 v7;
  mnMyLink_h_tagPipeLinkData_o *result;
  struct mnMyLink_h_tagPipeLinkData_array *v9;
  s32 linkIndex;

  {
    if (LODWORD(pInfo->aHandle->max_length))
      goto LABEL_6;
LABEL_9:
  }
  if (!LODWORD(pInfo->aHandle->max_length))
    goto LABEL_9;
LABEL_6:
  if (pInfo->nodeMax < 1)
    return 0;
  for (i = 4; ; ++i)
  {
    aHandle = pInfo->aHandle;
    if (!*(*(&aHandle->obj.klass + i) + 16LL))
      break;
    v7 = i - 3;
    if (v7 >= pInfo->nodeMax)
      return 0;
  }
  v9 = pInfo->aHandle;
  linkIndex = pInfo->linkIndex;
  result = *(&v9->obj.klass + i);
  pInfo->linkIndex = linkIndex + 1;
  result->indexID = linkIndex;
  result->next = 0;
  result->prev = 0;
  return result;
}
