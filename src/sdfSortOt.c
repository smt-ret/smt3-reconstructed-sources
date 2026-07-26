#include "types.h"

typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfSortOtNode_tag sdfSortOtNode_tag;

void sdfGrSortOtFixup(sdfDrawTag_t *tag, sdfDrawTag_t **head_p, sdfDrawTag_t **tail_p);
void sdfSortOtAvlCheckBalance(sdfSortOtNode_tag **stack, s32 stack_depth, sdfSortOtNode_tag *node, sdfSortOtNode_tag **root_p);
sdfSortOtNode_tag *sdfSortOtAvlRotateLR(sdfSortOtNode_tag *node, sdfSortOtNode_tag *parent);
sdfSortOtNode_tag *sdfSortOtAvlRotateRL(sdfSortOtNode_tag *node, sdfSortOtNode_tag *parent);

// 0x17ac840
void sdfGrOtSetSort(sdfGrOt_t *aOt) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(sdfGrOt_t_regFuncDelegate);
  sdfGrOt_t_regFuncDelegate___ctor(v3, 0, Method_sdfSortOt_sdfGrSortOtReg__);
  aOt->regFunc = v3;
  v4 = Allocate(sdfGrOt_t_callbackFuncDelegate);
  sdfGrOt_t_callbackFuncDelegate___ctor(v4, 0, Method_sdfSortOt_sdfGrSortOtCallback__);
  aOt->callbackFunc = v4;
}

// 0x17ac830
void sdfGrSortOtCallback(sdfGrOt_t *aOt, s32 aFunc, void *aData) {
  ;
}

// 0x17ac670
void sdfGrSortOtFixup(sdfDrawTag_t *tag, sdfDrawTag_t **head_p, sdfDrawTag_t **tail_p) {
  sdfDrawTag_t_o *next;
  s64 *v8;

  if (tag)
  {
    next = tag;
    if (!tail_p->m_Items[0])
    {
      head_p->m_Items[0] = next;
    }
    do
    {
      v8 = next;
      next = next->next;
    }
    while (next);
    tail_p->m_Items[0] = v8;
  }
}

// 0x17ac660
void sdfGrSortOtReg(sdfGrOt_t *aOt, sdfDrawTag_t *aTag) {
  ;
}

// 0x17ac820
void sdfGrSortOtSetup(sdfGrOt_t *aOt) {
  ;
}

// 0x17ac770
void sdfGrSortOtTraverse(sdfSortOtNode_tag *node, sdfDrawTag_t **head_p, sdfDrawTag_t **tail_p) {
  struct sdfSortOtNode_tag_array *child;
  sdfSortOtNode_tag_o *v9;
  struct sdfSortOtNode_tag_array *v10;

  do
  {
    child = node->child;
    v9 = child->m_Items[0];
    if (v9)
      sdfGrSortOtTraverse(v9, head_p, tail_p);
    sdfGrSortOtFixup(node->tag, head_p, tail_p);
    v10 = node->child;
    node = v10->m_Items[1];
  }
  while (node);
}

// 0x17ac250
void sdfSortOtAvlCheckBalance(sdfSortOtNode_tag **stack, s32 stack_depth, sdfSortOtNode_tag *node, sdfSortOtNode_tag **root_p) {
  s32 v5;
  sdfSortOtNode_tag_o *v7;
  s64 v9;
  s32 v10;
  sdfSortOtNode_tag_o *v12;
  struct sdfSortOtNode_tag_array *child;
  s32 v15;
  s32 v16;
  s64 v17;
  s64 *v18;
  u32 v19;
  struct sdfSortOtNode_tag_array *v21;
  sdfSortOtNode_tag_o *v23;
  u32 max_length;

  v5 = stack_depth - 1;
  if (stack_depth >= 1)
  {
    v7 = node;
    v9 = stack_depth + 3LL;
    do
    {
      v10 = v5;
      v12 = *(&stack->obj.klass + v9);
      child = v12->child;
      if (v7 == child->m_Items[0])
        v15 = 1;
      else
        v15 = -1;
      v16 = v12->balance + v15;
      v12->balance = v16;
      if (!v16)
        return;
      if (v16 >= 2)
      {
        v18 = sdfSortOtAvlRotateLR(v7, v12, node);
        v19 = v10 - 1;
        if (v10 < 1)
      }
      if (v16 <= -2)
      {
        v18 = sdfSortOtAvlRotateRL(v7, v12, node);
        v19 = v10 - 1;
        if (v10 < 1)
      }
      v17 = v9 - 3;
      --v9;
      v5 = v10 - 1;
      v7 = v12;
    }
    while (v17 > 1);
    v18 = 0;
    v19 = v10 - 1;
    if (v10 < 1)
    {
      if (!v18)
        return;
    }
    v21 = stack->m_Items[v19]->child;
    root_p = v21;
    v23 = v21->m_Items[0];
    max_length = root_p->max_length;
    if (v23 == v12)
    {
      if (!max_length)
      root_p->m_Items[0] = v18;
      return;
    }
    root_p->m_Items[1] = v18;
  }
}

// 0x17ac470
void sdfSortOtAvlRegist(sdfSortOtNode_tag **root_p, sdfDrawTag_t *tag) {
  u32 *v5;
  f32 z;
  u32 *v8;
  u64 v9;
  u64 *v10;
  sdfSortOtNode_tag_o *v12;
  struct sdfDrawTag_t_o *v13;

  v5 = NewSpecific(sdfSortOtNode_tag, 0x20u);
  z = tag->z;
  v8 = v5;
  v9 = 0;
  v10 = v5 + 8;
  while (1)
  {
    v12 = root_p->m_Items[0];
    if (!v12)
      break;
    v13 = v12->tag;
    if (z == v13->z)
    {
      tag->next = v13;
      v12->tag = tag;
      return;
    }
    v10[v9++] = v12;
    if (!LODWORD(root_p->max_length))
  }
  tag->next = 0;
  MEMORY[0x4039E0803CEFDD8] = 0;
  MEMORY[0x4039E0803CEFDE0] = 0;
  *(&xmmword_10 + 1) = tag;
  LODWORD(qword_20) = 0;
  root_p->m_Items[0] = 0;
  if (v9)
    sdfSortOtAvlCheckBalance(v8, v9, 0, root_p);
}

// 0x17abc50
sdfSortOtNode_tag *sdfSortOtAvlRotateLR(sdfSortOtNode_tag *node, sdfSortOtNode_tag *parent) {
  struct sdfSortOtNode_tag_array *v5;
  struct sdfSortOtNode_tag_array *v6;
  s64 *v8;
  struct sdfSortOtNode_tag_array *v10;
  sdfSortOtNode_tag_o *v12;
  struct sdfSortOtNode_tag_array *child;
  struct sdfSortOtNode_tag_array *v15;
  struct sdfSortOtNode_tag_array *v16;
  s64 *v18;
  struct sdfSortOtNode_tag_array *v20;
  struct sdfSortOtNode_tag_array *v21;
  s64 *v23;
  struct sdfSortOtNode_tag_array *v25;
  struct sdfSortOtNode_tag_array *v27;
  s32 balance;
  s32 v29;
  s32 v30;

  if (node->balance < 0)
  {
    child = node->child;
    v12 = child->m_Items[1];
    v15 = v12->child;
    v16 = parent->child;
    v18 = v15->m_Items[1];
    v16->m_Items[0] = v18;
    v20 = v12->child;
    v21 = node->child;
    v23 = v20->m_Items[0];
    v21->m_Items[1] = v23;
    v25 = v12->child;
    v25->m_Items[1] = parent;
    v27 = v12->child;
    v27->m_Items[0] = node;
    balance = v12->balance;
    v29 = balance < 1;
    if (balance <= 0)
      v30 = 0;
    else
      v30 = -1;
    parent->balance = v30;
    node->balance = v29;
  }
  else
  {
    v5 = node->child;
    v6 = parent->child;
    v8 = v5->m_Items[1];
    v6->m_Items[0] = v8;
    v10 = node->child;
    v10->m_Items[1] = parent;
    v12 = node;
    parent->balance = 0;
  }
  v12->balance = 0;
  return v12;
}

// 0x17abf50
sdfSortOtNode_tag *sdfSortOtAvlRotateRL(sdfSortOtNode_tag *node, sdfSortOtNode_tag *parent) {
  struct sdfSortOtNode_tag_array *v5;
  sdfSortOtNode_tag_o *v7;
  struct sdfSortOtNode_tag_array *v8;
  struct sdfSortOtNode_tag_array *v9;
  s64 *v11;
  struct sdfSortOtNode_tag_array *v13;
  struct sdfSortOtNode_tag_array *v14;
  s64 *v16;
  struct sdfSortOtNode_tag_array *v18;
  struct sdfSortOtNode_tag_array *v20;
  s32 balance;
  s32 v23;
  s32 v24;
  struct sdfSortOtNode_tag_array *child;
  struct sdfSortOtNode_tag_array *v26;
  s64 *v28;
  struct sdfSortOtNode_tag_array *v30;

  if (node->balance < 1)
  {
    child = node->child;
    v26 = parent->child;
    v28 = child->m_Items[0];
    v26->m_Items[1] = v28;
    v30 = node->child;
    v30->m_Items[0] = parent;
    v7 = node;
    parent->balance = 0;
  }
  else
  {
    v5 = node->child;
    v7 = v5->m_Items[0];
    v8 = v7->child;
    v9 = parent->child;
    v11 = v8->m_Items[0];
    v9->m_Items[1] = v11;
    v13 = v7->child;
    v14 = node->child;
    v16 = v13->m_Items[1];
    v14->m_Items[0] = v16;
    v18 = v7->child;
    v18->m_Items[0] = parent;
    v20 = v7->child;
    v20->m_Items[1] = node;
    balance = v7->balance;
    v23 = balance < 1;
    if (balance <= 0)
      v24 = 0;
    else
      v24 = -1;
    parent->balance = v24;
    node->balance = v23;
  }
  v7->balance = 0;
  return v7;
}
