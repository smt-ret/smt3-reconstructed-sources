#include "types.h"

typedef struct sdfDelayedResrcCB_t sdfDelayedResrcCB_t;
typedef struct sdfDelayedResrcChunk_t sdfDelayedResrcChunk_t;
typedef struct sdfDelayedResrc_free_funcDelegate sdfDelayedResrc_free_funcDelegate;

static sdfDelayedResrcChunk_t *sdfDelayedResrcList[2];
static sdfDelayedResrcChunk_t *sdfDelayedResrcLink;
static s32 sdfDelayedResrcSemaId;

// 0x17e4a90
s32 sdfDelayedResrcCheck(void) {
  return sdfDelayedResrcLink != 0;
}

// 0x17e4a20
s32 sdfDelayedResrcCheckFunc(void) {
  return sdfDelayedResrcLink != 0;
}

// 0x17e47f0
sdfDelayedResrcChunk_t *sdfDelayedResrcClose(void) {
  struct sdfDelayedResrc_StaticFields *v2;
  sdfDelayedResrcChunk_t_o *result;
  sdfDelayedResrcChunk_t_o *next;
  struct sdfDelayedResrc_StaticFields *static_fields;

  else
  {
    v2 = sdfDelayedResrc->static_fields;
    result = v2->sdfDelayedResrcLink;
    v2->sdfDelayedResrcLink = 0;
    if (!result)
      return result;
  }
  next = result;
  do
  {
    next->owner->chunk = 0;
    next = next->next;
  }
  while (next);
  return result;
}

// 0x17e20c0
void sdfDelayedResrcEntry(sdfDelayedResrcCB_t *aCB, void *aItem) {
  ;
}

// 0x17e27c0
void sdfDelayedResrcInitCB(sdfDelayedResrcCB_t *aCB, sdfDelayedResrc_free_funcDelegate *aFreeFunc) {
  {
    aCB->chunk = 0;
  }
}

// 0x17e4910
void sdfDelayedResrcProc(void) {
  struct sdfDelayedResrcChunk_t_array *sdfDelayedResrcList;
  sdfDelayedResrcChunk_t_o *v3;
  sdfDelayedResrcItems_t_o *next;

  if (!LODWORD(sdfDelayedResrcList->max_length))
  v3 = sdfDelayedResrcList->m_Items[0];
  next = Allocate(sdfDelayedResrcItems_t);
  sdfDelayedResrcItems_t___ctor(next);
  for (; v3; next = 0)
  {
    for (; next; next = next->next)
      ;
    v3 = v3->next;
  }
}

// 0x17e4890
void sdfDelayedResrcRelease(sdfDelayedResrcChunk_t *aChunk) {
  sdfDelayedResrcItems_t_o *next;

  next = Allocate(sdfDelayedResrcItems_t);
  sdfDelayedResrcItems_t___ctor(next);
  for (; aChunk; next = 0)
  {
    for (; next; next = next->next)
      ;
    aChunk = aChunk->next;
  }
}
