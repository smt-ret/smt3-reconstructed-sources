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
  if (!LODWORD(skill->max_length))
  {
LABEL_8:
  }
  while (1)
  {
    *(&skill->obj.klass + v4) = 0;
    if (v4 == 31)
      break;
    skill = this->skill;
    if (++v4 - 8 >= LODWORD(skill->max_length))
      goto LABEL_8;
  }
  this->skillcnt = 0;
  *&this->nowcommand = 0;
  *&this->prevcommand = 0;
  this->mitamaparam = NewSpecific(sbyte, 6u);
  this->levelupparam = NewSpecific(sbyte, 6u);
  keisyoskill = NewSpecific(ushort, 0x18u);
  v7 = 0;
  this->keisyoskill = keisyoskill;
  if (!LODWORD(keisyoskill->max_length))
  {
LABEL_15:
  }
  while (1)
  {
    keisyoskill->m_Items[v7] = 0;
    if (v7 == 23)
      break;
    keisyoskill = this->keisyoskill;
    if (++v7 >= LODWORD(keisyoskill->max_length))
      goto LABEL_15;
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
  if (!LODWORD(keisyoskill->max_length))
  {
LABEL_6:
  }
  while (1)
  {
    keisyoskill->m_Items[v4] = 0;
    if (v4 == 23)
      break;
    keisyoskill = this->keisyoskill;
    if (++v4 >= LODWORD(keisyoskill->max_length))
      goto LABEL_6;
  }
}

// 0x15c3c30
void datUnitWork_t__ClearSkill(datUnitWork_t *this) {
  struct System_Int32_array *skill;
  s64 v4;

  skill = NewSpecific(s32, 0x18u);
  v4 = 0;
  this->skill = skill;
  if (!LODWORD(skill->max_length))
  {
LABEL_6:
  }
  while (1)
  {
    skill->m_Items[v4] = 0;
    if (v4 == 23)
      break;
    skill = this->skill;
    if (++v4 >= LODWORD(skill->max_length))
      goto LABEL_6;
  }
  this->skillcnt = 0;
}

// 0x15c3d90
void datUnitWork_t__Copy(datUnitWork_t *this, datUnitWork_t *dat) {
  struct System_SByte_array *param;
  struct System_SByte_array *v4;
  s8 v5;
  struct System_SByte_array *v6;
  struct System_SByte_array *v7;
  s8 v8;
  struct System_SByte_array *v9;
  struct System_SByte_array *v10;
  s8 v12;
  struct System_SByte_array *v14;
  struct System_SByte_array *v15;
  s8 v16;
  struct System_SByte_array *v17;
  struct System_SByte_array *v18;
  s8 v20;
  struct System_SByte_array *v22;
  struct System_SByte_array *v23;
  s8 v25;
  struct System_SByte_array *skillparam;
  struct System_SByte_array *v28;
  s8 v29;
  struct System_SByte_array *v30;
  struct System_SByte_array *v31;
  s8 v32;
  struct System_SByte_array *v33;
  struct System_SByte_array *v34;
  s8 v36;
  struct System_SByte_array *v38;
  struct System_SByte_array *v39;
  s8 v40;
  struct System_SByte_array *v41;
  struct System_SByte_array *v42;
  s8 v44;
  struct System_SByte_array *v46;
  struct System_SByte_array *v47;
  s8 v49;
  struct System_Char_array *namecode;
  struct System_Char_array *v52;
  u16 v53;
  struct System_Char_array *v54;
  struct System_Char_array *v55;
  u16 v56;
  struct System_Char_array *v57;
  struct System_Char_array *v58;
  u16 v60;
  struct System_Char_array *v62;
  struct System_Char_array *v63;
  u16 v64;
  struct System_Char_array *v65;
  struct System_Char_array *v66;
  u16 v68;
  struct System_Char_array *v70;
  struct System_Char_array *v71;
  u16 v73;
  struct System_Char_array *v75;
  struct System_Char_array *v76;
  u16 v78;
  struct System_Char_array *v80;
  struct System_Char_array *v81;
  u16 v82;
  s64 v83;
  struct System_Int32_array *skill;
  struct System_Int32_array *v85;
  s32 v86;
  struct System_SByte_array *mitamaparam;
  struct System_SByte_array *v90;
  s8 v91;
  struct System_SByte_array *v92;
  struct System_SByte_array *v93;
  s8 v94;
  struct System_SByte_array *v95;
  struct System_SByte_array *v96;
  s8 v98;
  struct System_SByte_array *v100;
  struct System_SByte_array *v101;
  s8 v102;
  struct System_SByte_array *v103;
  struct System_SByte_array *v104;
  s8 v106;
  struct System_SByte_array *v108;
  struct System_SByte_array *v109;
  s8 v111;
  struct System_SByte_array *levelupparam;
  struct System_SByte_array *v114;
  s8 v115;
  struct System_SByte_array *v116;
  struct System_SByte_array *v117;
  s8 v118;
  struct System_SByte_array *v119;
  struct System_SByte_array *v120;
  s8 v122;
  struct System_SByte_array *v124;
  struct System_SByte_array *v125;
  s8 v126;
  struct System_SByte_array *v127;
  struct System_SByte_array *v128;
  s8 v130;
  struct System_SByte_array *v132;
  struct System_SByte_array *v133;
  s8 v135;
  s64 i;
  struct System_UInt16_array *keisyoskill;
  struct System_UInt16_array *v139;
  s16 v140;
  s64 j;
  struct System_Byte_array *keiattr;
  struct System_Byte_array *v145;
  char v146;
  struct System_UInt16_array *getdevilhearts;
  struct System_UInt16_array *v150;
  u16 v151;
  struct System_UInt16_array *v152;
  struct System_UInt16_array *v153;
  u16 v154;
  struct System_UInt16_array *v155;
  struct System_UInt16_array *v156;
  u16 v158;
  struct System_UInt16_array *v160;
  struct System_UInt16_array *v161;
  u16 v162;
  struct System_Char_array *fullnamecode;
  struct System_Char_array *v164;
  u16 v165;
  struct System_Char_array *v166;
  struct System_Char_array *v167;
  u16 v168;
  struct System_Char_array *v169;
  struct System_Char_array *v170;
  u16 v172;
  struct System_Char_array *v174;
  struct System_Char_array *v175;
  u16 v176;
  struct System_Char_array *v177;
  struct System_Char_array *v178;
  u16 v180;
  struct System_Char_array *v182;
  struct System_Char_array *v183;
  u16 v185;
  struct System_Char_array *v187;
  struct System_Char_array *v188;
  u16 v190;
  struct System_Char_array *v192;
  struct System_Char_array *v193;
  u16 v194;

  this->flag = dat->flag;
  this->id = dat->id;
  this->hp = dat->hp;
  this->maxhp = dat->maxhp;
  this->mp = dat->mp;
  this->maxmp = dat->maxmp;
  this->badstatus = dat->badstatus;
  this->exp = dat->exp;
  this->level = dat->level;
  param = dat->param;
  v4 = this->param;
  v5 = param->m_Items[0];
  v4->m_Items[0] = v5;
  v6 = dat->param;
  v7 = this->param;
  v8 = v6->m_Items[1];
  v7->m_Items[1] = v8;
  v9 = dat->param;
  v10 = this->param;
  v12 = v9->m_Items[2];
  v10->m_Items[2] = v12;
  v14 = dat->param;
  v15 = this->param;
  v16 = v14->m_Items[3];
  v15->m_Items[3] = v16;
  v17 = dat->param;
  v18 = this->param;
  v20 = v17->m_Items[4];
  v18->m_Items[4] = v20;
  v22 = dat->param;
  v23 = this->param;
  v25 = v22->m_Items[5];
  v23->m_Items[5] = v25;
  skillparam = dat->skillparam;
  if (skillparam)
  {
    v28 = this->skillparam;
    v29 = skillparam->m_Items[0];
    v28->m_Items[0] = v29;
    v30 = dat->skillparam;
    v31 = this->skillparam;
    v32 = v30->m_Items[1];
    v31->m_Items[1] = v32;
    v33 = dat->skillparam;
    v34 = this->skillparam;
    v36 = v33->m_Items[2];
    v34->m_Items[2] = v36;
    v38 = dat->skillparam;
    v39 = this->skillparam;
    v40 = v38->m_Items[3];
    v39->m_Items[3] = v40;
    v41 = dat->skillparam;
    v42 = this->skillparam;
    v44 = v41->m_Items[4];
    v42->m_Items[4] = v44;
    v46 = dat->skillparam;
    v47 = this->skillparam;
    v49 = v46->m_Items[5];
    v47->m_Items[5] = v49;
    this->uniqueid = dat->uniqueid;
    this->reserve1 = dat->reserve1;
    this->reserve2 = dat->reserve2;
    namecode = dat->namecode;
    v52 = this->namecode;
    v53 = namecode->m_Items[0];
    v52->m_Items[0] = v53;
    v54 = dat->namecode;
    v55 = this->namecode;
    v56 = v54->m_Items[1];
    v55->m_Items[1] = v56;
    v57 = dat->namecode;
    v58 = this->namecode;
    v60 = v57->m_Items[2];
    v58->m_Items[2] = v60;
    v62 = dat->namecode;
    v63 = this->namecode;
    v64 = v62->m_Items[3];
    v63->m_Items[3] = v64;
    v65 = dat->namecode;
    v66 = this->namecode;
    v68 = v65->m_Items[4];
    v66->m_Items[4] = v68;
    v70 = dat->namecode;
    v71 = this->namecode;
    v73 = v70->m_Items[5];
    v71->m_Items[5] = v73;
    v75 = dat->namecode;
    v76 = this->namecode;
    v78 = v75->m_Items[6];
    v76->m_Items[6] = v78;
    v80 = dat->namecode;
    v81 = this->namecode;
    v82 = v80->m_Items[7];
    v81->m_Items[7] = v82;
    v83 = 8;
    this->skillcnt = dat->skillcnt;
    do
    {
      skill = dat->skill;
      v85 = this->skill;
      v86 = *(&skill->obj.klass + v83);
      *(&v85->obj.klass + v83++) = v86;
    }
    while (v83 != 32);
    this->nowcommand = dat->nowcommand;
    this->nowindex = dat->nowindex;
    this->nowtarea = dat->nowtarea;
    this->nowtform = dat->nowtform;
    this->prevcommand = dat->prevcommand;
    this->previndex = dat->previndex;
    this->prevtarea = dat->prevtarea;
    this->prevtform = dat->prevtform;
    mitamaparam = dat->mitamaparam;
    v90 = this->mitamaparam;
    v91 = mitamaparam->m_Items[0];
    v90->m_Items[0] = v91;
    v92 = dat->mitamaparam;
    v93 = this->mitamaparam;
    v94 = v92->m_Items[1];
    v93->m_Items[1] = v94;
    v95 = dat->mitamaparam;
    v96 = this->mitamaparam;
    v98 = v95->m_Items[2];
    v96->m_Items[2] = v98;
    v100 = dat->mitamaparam;
    v101 = this->mitamaparam;
    v102 = v100->m_Items[3];
    v101->m_Items[3] = v102;
    v103 = dat->mitamaparam;
    v104 = this->mitamaparam;
    v106 = v103->m_Items[4];
    v104->m_Items[4] = v106;
    v108 = dat->mitamaparam;
    v109 = this->mitamaparam;
    v111 = v108->m_Items[5];
    v109->m_Items[5] = v111;
    levelupparam = dat->levelupparam;
    v114 = this->levelupparam;
    v115 = levelupparam->m_Items[0];
    v114->m_Items[0] = v115;
    v116 = dat->levelupparam;
    v117 = this->levelupparam;
    v118 = v116->m_Items[1];
    v117->m_Items[1] = v118;
    v119 = dat->levelupparam;
    v120 = this->levelupparam;
    v122 = v119->m_Items[2];
    v120->m_Items[2] = v122;
    v124 = dat->levelupparam;
    v125 = this->levelupparam;
    v126 = v124->m_Items[3];
    v125->m_Items[3] = v126;
    v127 = dat->levelupparam;
    v128 = this->levelupparam;
    v130 = v127->m_Items[4];
    v128->m_Items[4] = v130;
    v132 = dat->levelupparam;
    v133 = this->levelupparam;
    v135 = v132->m_Items[5];
    v133->m_Items[5] = v135;
    for (i = 16; i != 40; ++i)
    {
      keisyoskill = dat->keisyoskill;
      v139 = this->keisyoskill;
      v140 = *(&keisyoskill->obj.klass + i);
      *(&v139->obj.klass + i) = v140;
    }
    for (j = 32; j != 56; ++j)
    {
      keiattr = dat->keiattr;
      v145 = this->keiattr;
      v146 = *(&keiattr->obj.klass + j);
      *(&v145->obj.klass + j) = v146;
    }
    this->hensinmae = dat->hensinmae;
    getdevilhearts = dat->getdevilhearts;
    v150 = this->getdevilhearts;
    v151 = getdevilhearts->m_Items[0];
    v150->m_Items[0] = v151;
    v152 = dat->getdevilhearts;
    v153 = this->getdevilhearts;
    v154 = v152->m_Items[1];
    v153->m_Items[1] = v154;
    v155 = dat->getdevilhearts;
    v156 = this->getdevilhearts;
    v158 = v155->m_Items[2];
    v156->m_Items[2] = v158;
    v160 = dat->getdevilhearts;
    v161 = this->getdevilhearts;
    v162 = v160->m_Items[3];
    v161->m_Items[3] = v162;
    this->hensinmaeexp = dat->hensinmaeexp;
    fullnamecode = dat->fullnamecode;
    v164 = this->fullnamecode;
    v165 = fullnamecode->m_Items[0];
    v164->m_Items[0] = v165;
    v166 = dat->fullnamecode;
    v167 = this->fullnamecode;
    v168 = v166->m_Items[1];
    v167->m_Items[1] = v168;
    v169 = dat->fullnamecode;
    v170 = this->fullnamecode;
    v172 = v169->m_Items[2];
    v170->m_Items[2] = v172;
    v174 = dat->fullnamecode;
    v175 = this->fullnamecode;
    v176 = v174->m_Items[3];
    v175->m_Items[3] = v176;
    v177 = dat->fullnamecode;
    v178 = this->fullnamecode;
    v180 = v177->m_Items[4];
    v178->m_Items[4] = v180;
    v182 = dat->fullnamecode;
    v183 = this->fullnamecode;
    v185 = v182->m_Items[5];
    v183->m_Items[5] = v185;
    v187 = dat->fullnamecode;
    v188 = this->fullnamecode;
    v190 = v187->m_Items[6];
    v188->m_Items[6] = v190;
    v192 = dat->fullnamecode;
    v193 = this->fullnamecode;
    v194 = v192->m_Items[7];
    v193->m_Items[7] = v194;
  }
}
