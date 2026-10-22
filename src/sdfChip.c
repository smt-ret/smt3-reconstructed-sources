#include "types.h"

typedef struct sdfChipCB_tag sdfChipCB_tag;
typedef struct sdfChipInfo_t sdfChipInfo_t;
typedef struct sdfChipPageInfo_tag sdfChipPageInfo_tag;
typedef struct sdfChipRecord_t sdfChipRecord_t;
typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;

static sdfChipCB_tag *sdfChipCB[7];
static sdfChipPageInfo_tag *sdfChipPageInfo;
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
  sdfChipPageFreeLink = sdfChipPageFreeLink->next;
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
  struct sdfChipPageInfo_tag_o *sdfChipPageFreeLink;
  u64 *v6;
  s64 v7;
  u64 v8;

  sdfChipPageFreeLink = sdfChipPageFreeLink->next;
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
  s32 chipsPerPage;
  s32 growLeft;
  s32 chipSize;
  u64 *v8;
  struct sdfChipPageInfo_tag_allocDelegate_o *v9;
  s64 v11;
  struct sdfChipPageInfo_tag_o *freeLink;
  s32 v14;

  chipsPerPage = aCB->chipsPerPage;
  growLeft = aPageInfo->growLeft;
  ++aPageInfo->allocCount;
  chipSize = aCB->chipSize;
  v14 = *il2cp::SizeOf(aPageInfo->page, s32) + (chipsPerPage - growLeft) * chipSize;
  v8 = sub_8D3950(s32, &v14);
  aPageInfo->growLeft = growLeft - 1;
  if (growLeft == 1)
  {
    v9 = Allocate(sdfChipPageInfo_tag_allocDelegate);
    v11 = Method_sdfChip_sdfChipAllocGetFree__;
    v9->method_ptr = *Method_sdfChip_sdfChipAllocGetFree__;
    v9->m_target = 0;
    v9->method = v11;
    LODWORD(v11) = aPageInfo->allocCount;
    aPageInfo->alloc = v9;
    if (v11 == chipsPerPage)
    {
      freeLink = aCB->freeLink;
      if (freeLink)
        aCB->freeLink = freeLink->next;
      aCB->currentPage = freeLink;
    }
  }
  return v8;
}

// 0x17e2af0
void *sdfChipAllocRecord(s32 aSize, char *aFile, s32 aLine) {
  u64 *v7;
  Il2CppObject *v10;
  s32 v11;
  s64 *v13;
  s64 *v14;
  s64 v15;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  struct sdfChipRecord_t_array *sdfChipRecordList;
  struct sdfChipRecord_t_array *v22;
  u64 v26[3];

  v7 = Allocate(sdfChipRecord_t);
  _ctor(v7, 0);
  v10 = sdfChipAllocDirect(aSize);
  {
  }
  v11 = SizeOf_sdfMemRecord_t_(v7);
  v13 = sdfChipAllocDirect(v11);
  v14 = v13;
  if (v13)
  {
    v15 = *v13;
    if (*(*v13 + 288) < typeHierarchyDepth || *(*(v15 + 200) + 8 * typeHierarchyDepth - 8) != sdfChipRecord_t)
    {
      sub_8FC2C0(*(v15 + 64), sdfChipRecord_t, v26);
      if ((v26[0] & 1) != 0)
        v17 = v26[2];
      else
        v17 = v26 + 1;
      v18 = sub_8C4940(v17);
    }
  }
  v13[2] = sdfChipRecordList->m_Items[0];
  v13[3] = v10;
  v13[4] = aFile;
  *(v13 + 10) = aLine;
  v22 = sdfChipRecordList;
  v22->m_Items[0] = v14;
  return v10;
}

// 0x17e1df0
void *sdfChipAllocZeroDirect(s32 aSize) {
  Il2CppObject *v3;

  v3 = sdfChipAllocDirect(aSize);
  return sdfFillZero128(v3, (aSize + 15) >> 4, 0);
}

// 0x17e2d10
void *sdfChipAllocZeroRecord(s32 aSize, char *aFile, s32 aLine) {
  u64 *v7;
  Il2CppObject *v9;
  Il2CppObject *v11;
  s32 v12;
  s64 *v14;
  s64 *v15;
  s64 v16;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  struct sdfChipRecord_t_array *sdfChipRecordList;
  struct sdfChipRecord_t_array *v23;
  u64 v27[3];

  v7 = Allocate(sdfChipRecord_t);
  _ctor(v7, 0);
LABEL_7:
  v9 = sdfChipAllocDirect(aSize);
  v11 = sdfFillZero128(v9, (aSize + 15) >> 4, 0);
  {
  }
  v12 = SizeOf_sdfMemRecord_t_(v7);
  v14 = sdfChipAllocDirect(v12);
  v15 = v14;
  if (v14)
  {
    v16 = *v14;
    if (*(*v14 + 288) < typeHierarchyDepth || *(*(v16 + 200) + 8 * typeHierarchyDepth - 8) != sdfChipRecord_t)
    {
      sub_8FC2C0(*(v16 + 64), sdfChipRecord_t, v27);
      if ((v27[0] & 1) != 0)
        v18 = v27[2];
      else
        v18 = v27 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  v14[2] = sdfChipRecordList->m_Items[0];
  v14[3] = v11;
  v14[4] = aFile;
  *(v14 + 10) = aLine;
  v23 = sdfChipRecordList;
  v23->m_Items[0] = v15;
  return v11;
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
        goto LABEL_25;
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
LABEL_25:
        v10->next = sdfChipPageFreeLink;
        sdfChipPageFreeLink = v10;
        return;
      }
    }
    goto LABEL_25;
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
  s32 sdfChipPageCount;
  struct System_Int32_array *severalAllocCount;
  struct System_Int32_array *v7;
  struct System_Int32_array *v9;
  struct System_Int32_array *v11;
  struct System_Int32_array *v13;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;

  severalAllocCount = aInfo->severalAllocCount;
  aInfo->total = sdfChipPageCount << 12;
  aInfo->pageCount = sdfChipPageCount;
  severalAllocCount->m_Items[0] = 0;
  v7 = aInfo->severalAllocCount;
  v7->m_Items[1] = 0;
  v9 = aInfo->severalAllocCount;
  v9->m_Items[2] = 0;
  v11 = aInfo->severalAllocCount;
  v11->m_Items[3] = 0;
  v13 = aInfo->severalAllocCount;
  v13->m_Items[4] = 0;
  v15 = aInfo->severalAllocCount;
  v15->m_Items[5] = 0;
  v17 = aInfo->severalAllocCount;
  v17->m_Items[6] = 0;
  else if (LODWORD(sdfChipPageInfo->max_length))
  {
    goto LABEL_23;
  }
}

// 0x17e2a80
u32 sdfChipHashKey(void *aPtr) {
  u8 *v3;

  v3 = il2cp::SizeOf(aPtr, uint);
  return ((*v3 & 0x7F) + (*v3 >> 7));
}

// 0x17e21d0
void sdfChipInit(s32 aSize) {
  u64 *v3;
  struct sdfChipPageInfo_tag_array *v5;
  s32 v7;
  s32 v8;
  struct sdfChipPageInfo_tag_array *sdfChipPageInfo;
  s32 v10;
  Il2CppObject *v12;
  s32 v13;
  u64 *v14;
  char *v15;
  s64 *v16;
  Il2CppObject *v17;
  s32 v19;
  s32 v21;
  u64 *v23;
  struct sdfChipPageInfo_tag_array *v26;
  struct sdfChipCB_tag_array *sdfChipCB;
  sdfChipCB_tag_o *v30;
  struct sdfChipCB_tag_array *v31;
  sdfChipCB_tag_o *v33;
  struct sdfChipCB_tag_array *v34;
  sdfChipCB_tag_o *v36;
  struct sdfChipCB_tag_array *v37;
  sdfChipCB_tag_o *v39;
  struct sdfChipCB_tag_array *v40;
  sdfChipCB_tag_o *v42;
  struct sdfChipCB_tag_array *v43;
  sdfChipCB_tag_o *v45;
  struct sdfChipCB_tag_array *v46;
  sdfChipCB_tag_o *v48;
  struct sdfDelayedResrcCB_t_o *sdfChipDelayedResrcCB;
  u64 *v51;
  s64 v53;
  s32 v54;
  u64 v55[3];

  v3 = Allocate(sdfChipPageInfo_tag);
  _ctor(v3, 0);
  v5 = NewSpecific(sdfChipPageInfo_tag, aSize);
  sdfChipPageInfo = v5;
  {
  }
  v7 = aSize
     / (SizeOf_sdfMemRecord_t_(v3)
      + 4096);
  v8 = SizeOf_sdfMemRecord_t_(v3);
  v10 = v8;
  v12 = sdfChipPageInfo->m_Items[v7];
  v13 = -*il2cp::SizeOf(v12, s32) & 0x3F;
  v54 = v13;
  v14 = sub_8D3950(s32, &v54);
  if (v12 && v12->klass != string)
  {
    sub_8FC2C0(v12->klass->_1.element_class, string, v55);
    if ((v55[0] & 1) != 0)
      v15 = v55[2];
    else
      v15 = v55 + 1;
    v16 = sub_8C4940(v15);
  }
  v17 = Concat(v12, v14);
  sdfChipPageTop = v17;
  v19 = aSize - v10 * v7 - v13;
  if (v19 >= 0)
    v21 = aSize - v10 * v7 - v13;
  else
    v21 = v19 + 4095;
  sdfChipPageCount = v21 >> 12;
  LODWORD(v55[0]) = v21 & 0xFFFFF000 | *il2cp::SizeOf(v17, qword_3F088F8);
  v23 = sub_8D3950(s32, v55);
  sdfChipPageEnd = v23;
  v26 = sdfChipPageInfo;
  sdfChipPageFreeLink = v26->m_Items[0];
  v30 = sdfChipCB->m_Items[0];
  *&v30->chipSize = 16777232;
  v30->currentPage = 0;
  v30->freeLink = 0;
  v31 = sdfChipCB;
  v33 = v31->m_Items[1];
  *&v33->chipSize = 8388640;
  v33->currentPage = 0;
  v33->freeLink = 0;
  v34 = sdfChipCB;
  v36 = v34->m_Items[2];
  *&v36->chipSize = 4194368;
  v36->currentPage = 0;
  v36->freeLink = 0;
  v37 = sdfChipCB;
  v39 = v37->m_Items[3];
  *&v39->chipSize = 2097280;
  v39->currentPage = 0;
  v39->freeLink = 0;
  v40 = sdfChipCB;
  v42 = v40->m_Items[4];
  *&v42->chipSize = 1048832;
  v42->currentPage = 0;
  v42->freeLink = 0;
  v43 = sdfChipCB;
  v45 = v43->m_Items[5];
  *&v45->chipSize = 524800;
  v45->currentPage = 0;
  v45->freeLink = 0;
  v46 = sdfChipCB;
  v48 = v46->m_Items[6];
  *&v48->chipSize = 263168;
  v48->currentPage = 0;
  v48->freeLink = 0;
  v51 = Allocate(sdfDelayedResrc_free_funcDelegate);
  v53 = Method_sdfChip_sdfChipFreeDirect__;
  v51[2] = *Method_sdfChip_sdfChipFreeDirect__;
  v51[4] = 0;
  v51[5] = v53;
LABEL_66:
  sdfChipDelayedResrcCB->chunk = 0;
}

// 0x17e2f80
void sdfChipPurgeRecord(void *aPtr, char *aFile, s32 aLine) {
  struct sdfChipRecord_t_array *sdfChipRecordList;
  sdfChipRecord_t_o **m_Items;
  sdfChipRecord_t_o *v8;

  else
  {
    if (!LODWORD(sdfChipRecordList->max_length))
      goto LABEL_6;
  }
  m_Items = sdfChipRecordList->m_Items;
  while (1)
  {
    v8 = *m_Items;
    if (!*m_Items)
      break;
    m_Items = &v8->next;
    if (v8->ptr == aPtr)
    {
      sdfChipFreeDirect(v8, aFile);
      return;
    }
  }
}

// 0x17e31c0
void sdfChipRecordDump(void) {
  u64 i;
  struct sdfChipRecord_t_array *sdfChipRecordList;
  sdfChipRecord_t_o *j;
  Il2CppObject *file;
  u64 *v9;
  u64 *v11;
  s32 v12;
  s32 line;

  Write("<<< dump sdfChip >>>\n", 0);
  for (i = 0; i != 256; ++i)
  {
    for (j = sdfChipRecordList->m_Items[i]; j; j = j->next)
    {
      file = j->file;
      line = j->line;
      v9 = sub_8D3950(s32, &line);
      v12 = *il2cp::SizeOf(j->ptr, uint);
      v11 = sub_8D3950(uint, &v12);
      Write_2930912("chip {0} #{1:D} [{2:x8}]\n", file, v9, v11);
    }
  }
  Write("\n", 0);
}
