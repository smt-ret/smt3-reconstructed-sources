#include "types.h"

typedef struct fclEncycRecord_t fclEncycRecord_t;
typedef struct fclencyceelem_t fclencyceelem_t;

void fclencyceelem_t__Clear(fclencyceelem_t *this);
void fclencyceelem_t__Copy(fclencyceelem_t *this, fclencyceelem_t *data);

// 0x195d140
s32 FACILITY__FCL_BLEND_ALPHA(s64 src, s64 dst) {
  return ((dst * src) >> 7) | src & 0xFFFFFF00;
}

// 0x1960700
void fclEncycRecord_t__Clear(fclEncycRecord_t *this) {
  struct fclencyceelem_t_array *v3;
  u32 *v4;
  s64 i;
  u64 v6;
  u64 *v7;
  struct fclencyceelem_t_array *pelem;

  *&this->num = 0;
  *&this->reserved1 = 0;
  v3 = NewSpecific(fclencyceelem_t, 0xB9u);
  this->pelem = v3;
  v4 = v3;
  for (i = 4; ; ++i)
  {
    v6 = i - 4;
    v7 = Allocate(fclencyceelem_t);
    _ctor(v7, 0);
    *&v4[2 * i] = v7;
    pelem = this->pelem;
    fclencyceelem_t__Clear(*(&pelem->obj.klass + i));
    if (i == 188)
      break;
    v4 = this->pelem;
  }
}

// 0x1960920
void fclEncycRecord_t__Copy(fclEncycRecord_t *this, fclEncycRecord_t *data) {
  struct fclencyceelem_t_array *v5;
  u32 *v6;
  s64 i;
  u64 v8;
  u64 *v9;
  struct fclencyceelem_t_array *pelem;
  struct fclencyceelem_t_array *v14;
  fclencyceelem_t_o *v15;

  this->num = data->num;
  this->reserved0 = data->reserved0;
  this->reserved1 = data->reserved1;
  this->reserved2 = data->reserved2;
  v5 = NewSpecific(fclencyceelem_t, 0xB9u);
  this->pelem = v5;
  v6 = v5;
  for (i = 4; ; ++i)
  {
    v8 = i - 4;
    v9 = Allocate(fclencyceelem_t);
    _ctor(v9, 0);
    *&v6[2 * i] = v9;
    pelem = this->pelem;
    v14 = data->pelem;
    v15 = *(&pelem->obj.klass + i);
    fclencyceelem_t__Copy(v15, *(&v14->obj.klass + i));
    if (i == 188)
      break;
    v6 = this->pelem;
  }
}

// 0x1960840
void fclencyceelem_t__Clear(fclencyceelem_t *this) {
  struct System_Byte_array *v3;

  *&this->maxmp = 0;
  *&this->id = 0;
  this->param = NewSpecific(sbyte, 6u);
  this->skillparam = NewSpecific(sbyte, 6u);
  this->skillcnt = 0;
  this->skill = NewSpecific(ushort, 0x18u);
  this->mitamaparam = NewSpecific(sbyte, 6u);
  this->levelupparam = NewSpecific(sbyte, 6u);
  this->keisyoskill = NewSpecific(ushort, 0x18u);
  v3 = NewSpecific(byte, 0x18u);
  *&this->hensinmae = 0;
  *&this->reserved2 = 0;
  this->keiattr = v3;
}

// 0x1960aa0
void fclencyceelem_t__Copy(fclencyceelem_t *this, fclencyceelem_t *data) {
  struct System_SByte_array *v5;
  struct System_SByte_array *param;
  s8 v7;
  struct System_SByte_array *v8;
  struct System_SByte_array *v9;
  s8 v10;
  struct System_SByte_array *v11;
  struct System_SByte_array *v12;
  s8 v14;
  struct System_SByte_array *v16;
  struct System_SByte_array *v17;
  s8 v18;
  struct System_SByte_array *v19;
  struct System_SByte_array *v20;
  s8 v22;
  struct System_SByte_array *v24;
  struct System_SByte_array *v25;
  s8 v27;
  struct System_SByte_array *v29;
  struct System_SByte_array *skillparam;
  s8 v31;
  struct System_SByte_array *v32;
  struct System_SByte_array *v33;
  s8 v34;
  struct System_SByte_array *v35;
  struct System_SByte_array *v36;
  s8 v38;
  struct System_SByte_array *v40;
  struct System_SByte_array *v41;
  s8 v42;
  struct System_SByte_array *v43;
  struct System_SByte_array *v44;
  s8 v46;
  struct System_SByte_array *v48;
  struct System_SByte_array *v49;
  s8 v51;
  struct System_UInt16_array *v53;
  s64 v54;
  struct System_UInt16_array *skill;
  s16 v56;
  struct System_SByte_array *v59;
  struct System_SByte_array *mitamaparam;
  s8 v61;
  struct System_SByte_array *v62;
  struct System_SByte_array *v63;
  s8 v64;
  struct System_SByte_array *v65;
  struct System_SByte_array *v66;
  s8 v68;
  struct System_SByte_array *v70;
  struct System_SByte_array *v71;
  s8 v72;
  struct System_SByte_array *v73;
  struct System_SByte_array *v74;
  s8 v76;
  struct System_SByte_array *v78;
  struct System_SByte_array *v79;
  s8 v81;
  struct System_SByte_array *v83;
  struct System_SByte_array *levelupparam;
  s8 v85;
  struct System_SByte_array *v86;
  struct System_SByte_array *v87;
  s8 v88;
  struct System_SByte_array *v89;
  struct System_SByte_array *v90;
  s8 v92;
  struct System_SByte_array *v94;
  struct System_SByte_array *v95;
  s8 v96;
  struct System_SByte_array *v97;
  struct System_SByte_array *v98;
  s8 v100;
  struct System_SByte_array *v102;
  struct System_SByte_array *v103;
  s8 v105;
  struct System_UInt16_array *v107;
  s64 v108;
  struct System_UInt16_array *keisyoskill;
  s16 v110;
  struct System_Byte_array *v113;
  s64 v114;
  struct System_Byte_array *keiattr;
  char v116;

  this->id = data->id;
  this->reserved0 = data->reserved0;
  this->maxhp = data->maxhp;
  this->maxmp = data->maxmp;
  this->exp = data->exp;
  this->level = data->level;
  v5 = NewSpecific(sbyte, 6u);
  this->param = v5;
  param = data->param;
  v7 = param->m_Items[0];
  v5->m_Items[0] = v7;
  v8 = data->param;
  v9 = this->param;
  v10 = v8->m_Items[1];
  v9->m_Items[1] = v10;
  v11 = data->param;
  v12 = this->param;
  v14 = v11->m_Items[2];
  v12->m_Items[2] = v14;
  v16 = data->param;
  v17 = this->param;
  v18 = v16->m_Items[3];
  v17->m_Items[3] = v18;
  v19 = data->param;
  v20 = this->param;
  v22 = v19->m_Items[4];
  v20->m_Items[4] = v22;
  v24 = data->param;
  v25 = this->param;
  v27 = v24->m_Items[5];
  v25->m_Items[5] = v27;
  v29 = NewSpecific(sbyte, 6u);
  this->skillparam = v29;
  skillparam = data->skillparam;
  v31 = skillparam->m_Items[0];
  v29->m_Items[0] = v31;
  v32 = data->skillparam;
  v33 = this->skillparam;
  v34 = v32->m_Items[1];
  v33->m_Items[1] = v34;
  v35 = data->skillparam;
  v36 = this->skillparam;
  v38 = v35->m_Items[2];
  v36->m_Items[2] = v38;
  v40 = data->skillparam;
  v41 = this->skillparam;
  v42 = v40->m_Items[3];
  v41->m_Items[3] = v42;
  v43 = data->skillparam;
  v44 = this->skillparam;
  v46 = v43->m_Items[4];
  v44->m_Items[4] = v46;
  v48 = data->skillparam;
  v49 = this->skillparam;
  v51 = v48->m_Items[5];
  v49->m_Items[5] = v51;
  this->skillcnt = data->skillcnt;
  v53 = NewSpecific(ushort, 0x18u);
  v54 = 16;
  this->skill = v53;
  while (1)
  {
    skill = data->skill;
    v56 = *(&skill->obj.klass + v54);
    *(&v53->obj.klass + v54) = v56;
    if (v54 == 39)
      break;
    v53 = this->skill;
    ++v54;
  }
  v59 = NewSpecific(sbyte, 6u);
  this->mitamaparam = v59;
  mitamaparam = data->mitamaparam;
  v61 = mitamaparam->m_Items[0];
  v59->m_Items[0] = v61;
  v62 = data->mitamaparam;
  v63 = this->mitamaparam;
  v64 = v62->m_Items[1];
  v63->m_Items[1] = v64;
  v65 = data->mitamaparam;
  v66 = this->mitamaparam;
  v68 = v65->m_Items[2];
  v66->m_Items[2] = v68;
  v70 = data->mitamaparam;
  v71 = this->mitamaparam;
  v72 = v70->m_Items[3];
  v71->m_Items[3] = v72;
  v73 = data->mitamaparam;
  v74 = this->mitamaparam;
  v76 = v73->m_Items[4];
  v74->m_Items[4] = v76;
  v78 = data->mitamaparam;
  v79 = this->mitamaparam;
  v81 = v78->m_Items[5];
  v79->m_Items[5] = v81;
  v83 = NewSpecific(sbyte, 6u);
  this->levelupparam = v83;
  levelupparam = data->levelupparam;
  v85 = levelupparam->m_Items[0];
  v83->m_Items[0] = v85;
  v86 = data->levelupparam;
  v87 = this->levelupparam;
  v88 = v86->m_Items[1];
  v87->m_Items[1] = v88;
  v89 = data->levelupparam;
  v90 = this->levelupparam;
  v92 = v89->m_Items[2];
  v90->m_Items[2] = v92;
  v94 = data->levelupparam;
  v95 = this->levelupparam;
  v96 = v94->m_Items[3];
  v95->m_Items[3] = v96;
  v97 = data->levelupparam;
  v98 = this->levelupparam;
  v100 = v97->m_Items[4];
  v98->m_Items[4] = v100;
  v102 = data->levelupparam;
  v103 = this->levelupparam;
  v105 = v102->m_Items[5];
  v103->m_Items[5] = v105;
  v107 = NewSpecific(ushort, 0x18u);
  v108 = 16;
  this->keisyoskill = v107;
  while (1)
  {
    keisyoskill = data->keisyoskill;
    v110 = *(&keisyoskill->obj.klass + v108);
    *(&v107->obj.klass + v108) = v110;
    if (v108 == 39)
      break;
    v107 = this->keisyoskill;
    ++v108;
  }
  v113 = NewSpecific(byte, 0x18u);
  v114 = 32;
  this->keiattr = v113;
  while (1)
  {
    keiattr = data->keiattr;
    v116 = *(&keiattr->obj.klass + v114);
    *(&v113->obj.klass + v114) = v116;
    if (v114 == 55)
      break;
    v113 = this->keiattr;
    ++v114;
  }
  this->hensinmae = data->hensinmae;
  this->reserved1 = data->reserved1;
  this->flag = data->flag;
  this->reserved2 = data->reserved2;
  this->hensinmaeexp = data->hensinmaeexp;
}
