#include "types.h"

typedef struct datDevilAI_s datDevilAI_t;
typedef struct datDevilAI_t2 datDevilAI_t2;
typedef struct datUnitWork_s datUnitWork_t;

// 0x15c2e10
void datDevilAI_t2__Copy(datDevilAI_t2 *this, datDevilAI_t **data) {
  datDevilAI_t_o *v5;
  datDevilAI_t_o *v6;
  s32 *aichk;
  u32 *v8;
  s64 v9;
  struct datDevilAIChk_s_array *v11;
  s64 *v13;
  s64 v15;
  struct datDevilAITbl_s_array_array *aitable;
  s64 *v17;
  s64 *v18;
  s64 i;
  struct datDevilAITbl_s_array_array *v21;
  u64 v22;
  struct datDevilAITbl_s_array_array *v23;
  struct datDevilAITbl_s_array *aitable1;
  u32 *v27;
  s64 *v29;
  s64 *v32;
  s64 *v33;
  s64 j;
  struct datDevilAITbl_s_array_array *v36;
  u64 v37;
  struct datDevilAITbl_s_array_array *v38;
  struct datDevilAITbl_s_array *aitable2;
  u32 *v42;
  s64 *v44;
  s64 *v47;
  s64 *v48;
  s64 k;
  datDevilAI_t_o *v51;
  struct datDevilAITbl_s_array_array *v52;
  u64 v53;
  struct datDevilAITbl_s_array_array *v55;
  u32 *v57;
  struct datDevilAITbl_s_array *aitable3;
  s64 *v60;

  (*data)->scriptid = this->scriptid;
  (*data)->ailevel = this->ailevel;
  v5 = *data;
  v5->aichk = NewSpecific(datDevilAIChk_s, 3u);
  v6 = *data;
  aichk = (*data)->aichk;
  v8 = (aichk + 6);
  if (aichk[6] >= 1)
  {
    v9 = 4;
    do
    {
      v11 = this->aichk;
      v13 = *(&v11->obj.klass + v9);
      *&aichk[2 * v9] = v13;
      v6 = *data;
      aichk = (*data)->aichk;
      v15 = v9 - 3;
      v8 = (aichk + 6);
      ++v9;
    }
    while (v15 < aichk[6]);
  }
  v6->aitable = NewSpecific(datDevilAITbl_s__, 3u);
  aitable = (*data)->aitable;
  v17 = NewSpecific(datDevilAITbl_s, 5u);
  v18 = v17;
  aitable->m_Items[0] = v18;
  for (i = 4; ; ++i)
  {
    v21 = (*data)->aitable;
    v22 = i - 4;
    v23 = v21;
    if (v22 >= SLODWORD(v21->m_Items[0]->max_length))
      break;
    aitable1 = this->aitable1;
    v27 = v23->m_Items[0];
    v29 = *(&aitable1->obj.klass + i);
    *&v27[2 * i] = v29;
  }
  v32 = NewSpecific(datDevilAITbl_s, 5u);
  v33 = v32;
  v23->m_Items[1] = v33;
  for (j = 4; ; ++j)
  {
    v36 = (*data)->aitable;
    v37 = j - 4;
    v38 = v36;
    if (v37 >= SLODWORD(v36->m_Items[1]->max_length))
      break;
    aitable2 = this->aitable2;
    v42 = v38->m_Items[1];
    v44 = *(&aitable2->obj.klass + j);
    *&v42[2 * j] = v44;
  }
  v47 = NewSpecific(datDevilAITbl_s, 5u);
  v48 = v47;
  v38->m_Items[2] = v48;
  for (k = 4; ; ++k)
  {
    v51 = *data;
    v52 = (*data)->aitable;
    v53 = k - 4;
    if (v53 >= SLODWORD(v52->m_Items[2]->max_length))
      break;
    v55 = v51->aitable;
    v57 = v55->m_Items[2];
    aitable3 = this->aitable3;
    v60 = *(&aitable3->obj.klass + k);
    *&v57[2 * k] = v60;
  }
  v51->deadscriptid = this->deadscriptid;
  (*data)->deadeventno = this->deadeventno;
}

// 0x15c27b0
void datDevilAI_t__Copy(datDevilAI_t *this, datDevilAI_t *data) {
  struct datDevilAIChk_s_array *v5;
  struct datDevilAIChk_s_array *aichk;
  struct datDevilAIChk_s_array *v7;
  s64 *v8;
  struct datDevilAIChk_s_array *v11;
  struct datDevilAIChk_s_array *v12;
  s64 *v13;
  struct datDevilAIChk_s_array *v16;
  struct datDevilAIChk_s_array *v17;
  s64 *v19;
  struct datDevilAITbl_s_array_array *v21;
  struct datDevilAITbl_s_array_array *v22;
  s64 *v23;
  s64 *v24;
  s64 i;
  struct datDevilAITbl_s_array_array *aitable;
  u32 *v30;
  struct datDevilAITbl_s_array_array *v31;
  u64 v32;
  datDevilAITbl_s_array *v33;
  s64 *v34;
  struct datDevilAITbl_s_array_array *v38;
  s64 *v39;
  s64 *v40;
  s64 j;
  struct datDevilAITbl_s_array_array *v44;
  u32 *v46;
  struct datDevilAITbl_s_array_array *v47;
  u64 v48;
  datDevilAITbl_s_array *v49;
  s64 *v50;
  struct datDevilAITbl_s_array_array *v54;
  s64 *v55;
  s64 *v56;
  s64 k;
  struct datDevilAITbl_s_array_array *v60;
  u32 *v62;
  struct datDevilAITbl_s_array_array *v63;
  u64 v64;
  datDevilAITbl_s_array *v65;
  s64 *v66;

  this->scriptid = data->scriptid;
  this->ailevel = data->ailevel;
  v5 = NewSpecific(datDevilAIChk_s, 3u);
  this->aichk = v5;
  aichk = data->aichk;
  v7 = v5;
  v8 = aichk->m_Items[0];
  v7->m_Items[0] = v8;
  v11 = data->aichk;
  v12 = this->aichk;
  v13 = v11->m_Items[1];
  v12->m_Items[1] = v13;
  v16 = data->aichk;
  v17 = this->aichk;
  v19 = v16->m_Items[2];
  v17->m_Items[2] = v19;
  v21 = NewSpecific(datDevilAITbl_s__, 3u);
  this->aitable = v21;
  v22 = v21;
  v23 = NewSpecific(datDevilAITbl_s, 5u);
  v24 = v23;
  v22->m_Items[0] = v24;
  for (i = 4; i != 9; ++i)
  {
    aitable = this->aitable;
    v30 = aitable->m_Items[0];
    v31 = data->aitable;
    v32 = i - 4;
    v33 = v31->m_Items[0];
    v34 = *(&v33->obj.klass + i);
    *&v30[2 * i] = v34;
  }
  v38 = this->aitable;
  v39 = NewSpecific(datDevilAITbl_s, 5u);
  v40 = v39;
  v38->m_Items[1] = v40;
  for (j = 4; j != 9; ++j)
  {
    v44 = this->aitable;
    v46 = v44->m_Items[1];
    v47 = data->aitable;
    v48 = j - 4;
    v49 = v47->m_Items[1];
    v50 = *(&v49->obj.klass + j);
    *&v46[2 * j] = v50;
  }
  v54 = this->aitable;
  v55 = NewSpecific(datDevilAITbl_s, 5u);
  v56 = v55;
  v54->m_Items[2] = v56;
  for (k = 4; k != 9; ++k)
  {
    v60 = this->aitable;
    v62 = v60->m_Items[2];
    v63 = data->aitable;
    v64 = k - 4;
    v65 = v63->m_Items[2];
    v66 = *(&v65->obj.klass + k);
    *&v62[2 * k] = v66;
  }
  this->deadscriptid = data->deadscriptid;
  this->deadeventno = data->deadeventno;
}

// 0x15c3a10
void datUnitWork_t__Clear(datUnitWork_t *this) {
  struct System_Int32_array *skill;
  s64 v4;
  struct System_UInt16_array *keisyoskill;
  s64 v7;

  *&this->badstatus = 0;
  *&this->flag = 0;
  *&this->maxhp = 0;
  this->param = NewSpecific(sbyte, 6u);
  this->skillparam = NewSpecific(sbyte, 6u);
  *&this->uniqueid = 0;
  this->reserve2 = 0;
  this->namecode = NewSpecific(char, 8u);
  skill = NewSpecific(s32, 0x18u);
  v4 = 8;
  this->skill = skill;
  while (1)
  {
    *(&skill->obj.klass + v4) = 0;
    if (v4 == 31)
      break;
    skill = this->skill;
    if (++v4 - 8 >= LODWORD(skill->max_length))
  }
  this->skillcnt = 0;
  *&this->nowcommand = 0;
  *&this->prevcommand = 0;
  this->mitamaparam = NewSpecific(sbyte, 6u);
  this->levelupparam = NewSpecific(sbyte, 6u);
  keisyoskill = NewSpecific(ushort, 0x18u);
  v7 = 0;
  this->keisyoskill = keisyoskill;
  while (1)
  {
    keisyoskill->m_Items[v7] = 0;
    if (v7 == 23)
      break;
    keisyoskill = this->keisyoskill;
    if (++v7 >= LODWORD(keisyoskill->max_length))
  }
  this->keiattr = NewSpecific(byte, 0x18u);
  this->hensinmae = 0;
  this->getdevilhearts = NewSpecific(ushort, 4u);
  this->hensinmaeexp = 0;
  this->fullnamecode = NewSpecific(char, 8u);
}

// 0x15c3ce0
void datUnitWork_t__ClearKeisyoSkill(datUnitWork_t *this) {
  struct System_UInt16_array *keisyoskill;
  s64 v4;

  keisyoskill = NewSpecific(ushort, 0x18u);
  v4 = 0;
  this->keisyoskill = keisyoskill;
  while (1)
  {
    keisyoskill->m_Items[v4] = 0;
    if (v4 == 23)
      break;
    keisyoskill = this->keisyoskill;
    if (++v4 >= LODWORD(keisyoskill->max_length))
  }
}

// 0x15c3c30
void datUnitWork_t__ClearSkill(datUnitWork_t *this) {
  struct System_Int32_array *skill;
  s64 v4;

  skill = NewSpecific(s32, 0x18u);
  v4 = 0;
  this->skill = skill;
  while (1)
  {
    skill->m_Items[v4] = 0;
    if (v4 == 23)
      break;
    skill = this->skill;
    if (++v4 >= LODWORD(skill->max_length))
  }
  this->skillcnt = 0;
}

// 0x15c3d90
void datUnitWork_t__Copy(datUnitWork_t *this, datUnitWork_t *dat) {
}
