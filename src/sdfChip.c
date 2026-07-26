#include "types.h"

typedef struct sdfChipCB_tag sdfChipCB_tag;
typedef struct sdfChipInfo_t sdfChipInfo_t;
typedef struct sdfChipPageInfo_tag sdfChipPageInfo_tag;
typedef struct sdfChipRecord_t sdfChipRecord_t;
typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;

static sdfChipCB_tag *sdfChipCB[7];
static sdfChipPageInfo_tag sdfChipPageInfo[UNKNOWN_ARRAY_SIZE];
static sdfChipPageInfo_tag *sdfChipPageFreeLink;
static void *sdfChipPageTop;
static void *sdfChipPageEnd;
static s32 sdfChipPageCount;
static sdfDelayedResrcCB_t *sdfChipDelayedResrcCB;
static sdfChipRecord_t *sdfChipRecordList[256];

void *sdfChipAllocDirect(s32 aSize);
void *sdfChipAllocPageGrow(sdfChipCB_tag *aCB, sdfChipPageInfo_tag *aPageInfo);
void sdfChipFreeDirect(void *aPtr);
void sdfChipPurgeRecord(void *aPtr, char *aFile, s32 aLine);
void *sdfFillZero128(void *p, s32 l);

// 0x17e1680
void *sdfChipAllocDirect(s32 aSize) {
  u32 v4;
  s32 v5;
  struct sdfChipCB_tag_array *sdfChipCB;
  Il2CppClass **v9;
  sdfChipCB_tag_o *v10;
  sdfChipPageInfo_tag_o *currentPage;
  sdfChip_c *v13;
  struct sdfChip_StaticFields *static_fields;
  sdfChipPageInfo_tag_o *sdfChipPageFreeLink;
  u64 *v16;
  s64 v17;
  u64 v18;

  if (aSize >= 17)
  {
    v4 = 0;
    v5 = 16;
    do
    {
      v5 *= 2;
      ++v4;
    }
    while (v5 < aSize);
  }
  else
  {
    v4 = 0;
  }
  v9 = &sdfChipCB->obj.klass + v4;
  v10 = v9[4];
  currentPage = v10->currentPage;
  if (currentPage)
    return Invoke(currentPage->alloc, v9[4], currentPage);
  static_fields = v13->static_fields;
  sdfChipPageFreeLink = static_fields->sdfChipPageFreeLink;
  static_fields->sdfChipPageFreeLink = sdfChipPageFreeLink->next;
  v10->currentPage = sdfChipPageFreeLink;
  sdfChipPageFreeLink->owner = v10;
  v16 = Allocate(sdfChipPageInfo_tag_allocDelegate);
  v17 = Method_sdfChip_sdfChipAllocPageGrow__;
  v18 = *Method_sdfChip_sdfChipAllocPageGrow__;
  v16[4] = 0;
  v16[5] = v17;
  v16[2] = v18;
  sdfChipPageFreeLink->alloc = v16;
  sdfChipPageFreeLink->allocCount = 0;
  return sdfChipAllocPageGrow(v10, sdfChipPageFreeLink);
}

// 0x17e13e0
void *sdfChipAllocGetFree(sdfChipCB_tag *aCB, sdfChipPageInfo_tag *aPageInfo) {
  s16 v5;
  Il2CppObject *freeLink;
  struct sdfChipPageInfo_tag_o *v7;

  v5 = aPageInfo->allocCount + 1;
  aPageInfo->allocCount = v5;
  freeLink = aPageInfo->freeLink;
  if (aCB->chipsPerPage == v5)
  {
    v7 = aCB->freeLink;
    if (v7)
      aCB->freeLink = v7->next;
    aCB->currentPage = v7;
  }
  return freeLink;
}

// 0x17e15c0
void *sdfChipAllocNewPage(sdfChipCB_tag *aCB) {
  sdfChip_c *v3;
  struct sdfChip_StaticFields *static_fields;
  struct sdfChipPageInfo_tag_o *sdfChipPageFreeLink;
  u64 *v6;
  s64 v7;
  u64 v8;

  static_fields = v3->static_fields;
  sdfChipPageFreeLink = static_fields->sdfChipPageFreeLink;
  static_fields->sdfChipPageFreeLink = sdfChipPageFreeLink->next;
  aCB->currentPage = sdfChipPageFreeLink;
  sdfChipPageFreeLink->owner = aCB;
  v6 = Allocate(sdfChipPageInfo_tag_allocDelegate);
  v7 = Method_sdfChip_sdfChipAllocPageGrow__;
  v8 = *Method_sdfChip_sdfChipAllocPageGrow__;
  v6[4] = 0;
  v6[5] = v7;
  v6[2] = v8;
  sdfChipPageFreeLink->alloc = v6;
  sdfChipPageFreeLink->allocCount = 0;
  return sdfChipAllocPageGrow(aCB, sdfChipPageFreeLink);
}

// 0x17e13c0
void sdfChipAllocNextPage(sdfChipCB_tag *aCB) {
  struct sdfChipPageInfo_tag_o *freeLink;

  freeLink = aCB->freeLink;
  if (freeLink)
    aCB->freeLink = freeLink->next;
  aCB->currentPage = freeLink;
}

// 0x17e1480
void *sdfChipAllocPageGrow(sdfChipCB_tag *aCB, sdfChipPageInfo_tag *aPageInfo) {
    return 0;
}

// 0x17e2af0
void *sdfChipAllocRecord(s32 aSize, char *aFile, s32 aLine) {
    sdfChipAllocDirect(0);
    return 0;
}

// 0x17e1df0
void *sdfChipAllocZeroDirect(s32 aSize) {
  Il2CppObject *v3;

  v3 = sdfChipAllocDirect(aSize);
  return sdfFillZero128(v3, (aSize + 15) >> 4, 0);
}

// 0x17e2d10
void *sdfChipAllocZeroRecord(s32 aSize, char *aFile, s32 aLine) {
    sdfChipAllocDirect(0);
    sdfFillZero128(0, 0);
    return 0;
}

// 0x17e20d0
s32 sdfChipCheck(void *aPtr) {
  s64 sdfChipPageTop;
  s32 v5;
  s64 sdfChipPageEnd;
  s32 v10;

  v5 = *il2cp::SizeOf(aPtr, s32);
  if (v5 < *il2cp::SizeOf(sdfChipPageTop, s32))
    return 0;
  v10 = *il2cp::SizeOf(aPtr, s32);
  return v10 < *il2cp::SizeOf(sdfChipPageEnd, s32);
}

// 0x17e2030
void sdfChipFreeDelayedDirect(void *aPtr) {

}

// 0x17e30f0
void sdfChipFreeDelayedRecord(void *aPtr, char *aFile, s32 aLine) {
  if (aPtr)
  {
    sdfChipPurgeRecord(aPtr, aFile, aLine);
  }
}

// 0x17e1e70
void sdfChipFreeDirect(void *aPtr) {
  s64 sdfChipPageTop;
  s32 v5;
  s32 v7;
  struct sdfChipPageInfo_tag_array *sdfChipPageInfo;
  sdfChipPageInfo_tag_o *v10;
  s32 allocCount;
  struct sdfChipCB_tag_o *owner;
  sdfChipPageInfo_tag_o **p_freeLink;
  sdfChipPageInfo_tag_o *v14;
  struct sdfChipPageInfo_tag_o *freeLink;

  if (aPtr)
  {
    v5 = *il2cp::SizeOf(aPtr, s32);
    v7 = v5 - *il2cp::SizeOf(sdfChipPageTop, s32);
    v10 = sdfChipPageInfo->m_Items[(v7 + (v7 < 0 ? 0xFFF : 0)) >> 12];
    allocCount = v10->allocCount;
    owner = v10->owner;
    v10->allocCount = allocCount - 1;
    if (allocCount != 1)
    {
      if (allocCount == owner->chipsPerPage)
      {
        v10->next = owner->freeLink;
        owner->freeLink = v10;
      }
      v10->freeLink = aPtr;
      return;
    }
    if (owner->currentPage == v10)
    {
      freeLink = owner->freeLink;
      if (freeLink)
        owner->freeLink = freeLink->next;
      owner->currentPage = freeLink;
      v10->owner = 0;
    }
    else
    {
      p_freeLink = &owner->freeLink;
      do
      {
        v14 = *p_freeLink;
        p_freeLink = &(*p_freeLink)->next;
      }
      while (v14 != v10);
      v10->owner = 0;
      {
        v10->next = sdfChipPageFreeLink;
        sdfChipPageFreeLink = v10;
        return;
      }
    }
  }
}

// 0x17e3070
void sdfChipFreeRecord(void *aPtr, char *aFile, s32 aLine) {
  if (aPtr)
  {
    sdfChipPurgeRecord(aPtr, aFile, aLine);
    sdfChipFreeDirect(aPtr);
  }
}

// 0x17e2840
void sdfChipGetInfo(sdfChipInfo_t *aInfo) {
}

// 0x17e2a80
u32 sdfChipHashKey(void *aPtr) {
  u8 *v3;

  v3 = il2cp::SizeOf(aPtr, uint);
  return ((*v3 & 0x7F) + (*v3 >> 7));
}

// 0x17e21d0
void sdfChipInit(s32 aSize) {
}

// 0x17e2f80
void sdfChipPurgeRecord(void *aPtr, char *aFile, s32 aLine) {
    sdfChipFreeDirect(0);
}

// 0x17e31c0
void sdfChipRecordDump(void) {
}
