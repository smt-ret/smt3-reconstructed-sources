#include "types.h"

typedef struct FontGsControl_t FontGsControl_t;
typedef struct FontMem_t FontMem_t;
typedef struct fmgslCont fmgslCont;

struct fmgslCont {
    s8 fmInitFontMemControl_first_flag;
};

static FontGsControl_t *gFGC;

// 0x1398bd0
s8 fmDestroyFontMemControl(fmgslCont *this) {
  struct FontGsControl_t_o *gFGC;

  if (!gFGC->root)
    return 0;
  gFGC->root = 0;
  return 1;
}

// 0x13984a0
FontGsControl_t *fmGetInternalFGC(fmgslCont *this) {
  return gFGC;
}

// 0x1398510
s32 fmGetRestBufNum(fmgslCont *this) {
  return gFGC->unit_nums;
}

// 0x1398580
s8 fmInitFontMemControl(fmgslCont *this, u32 GSLocalAddr, s32 X_FontNums, s32 Y_FontNums, s32 FontWidth, s32 FontHeight, s32 UserDataSize) {
  fmgslCont_c *v12;
  struct FontGsControl_t_o *gFGC;
  u64 v15;
  s16 v16;
  s32 i;
  s64 v18;
  struct FontGsControl_t_o *v19;
  struct FontMem_t_array *root;
  u64 max_length_low;
  struct FontMem_t_array *v22;
  FontMem_t_o *v24;
  struct FontMem_t_array *v26;
  il2cpp_array_size_t max_length;
  s64 unit_nums;
  s32 v31;
  s64 v32;
  struct FontMem_t_array *v33;
  u64 v34;
  Il2CppClass **v36;
  s64 v38;
  struct FontGsControl_t_o *v39;
  struct FontMem_t_array *v40;
  u32 v41;
  struct FontMem_t_array *v42;
  s64 v44;
  FontMem_t_o *v45;
  s32 v47;
  s32 v48;
  s32 v49;
  s32 v50;
  s32 v51;
  s64 v52;
  s32 v53;
  s64 v54;
  struct FontMem_t_array *v57;
  s64 v59;
  s64 v60;
  s64 v62;
  u32 *v64;
  u32 v65;
  u32 *v67;
  u32 v68;
  struct FontGsControl_t_o *v72;
  s32 v73;
  fmgslCont_o *v74;
  s32 v75;
  s32 v76;
  s32 v77;

  else
  {
    if (gFGC->root)
      return 0;
  }
  gFGC->unit_width = FontWidth;
  gFGC->unit_height = FontHeight;
  gFGC->unit_size = FontHeight * FontWidth / 2;
  gFGC->unit_nums = Y_FontNums * X_FontNums;
  v15 = 0;
  gFGC->unit_num_max = gFGC->unit_nums;
  v16 = *&v12->_2.bitflags1;
  if ((v16 & 0x200) == 0)
  for (i = v16 & 0x200; ; i = 0)
  {
    v19 = gFGC;
    if (v15 >= v19->unit_nums - 1)
      break;
    root = v19->root;
    max_length_low = LODWORD(root->max_length);
    v22 = root;
    v24 = root->m_Items[v15];
    v18 = v22 + 8 * v15++;
    v24->next = *(v18 + 40);
    v16 = *&v12->_2.bitflags1;
    if ((v16 & 0x200) != 0)
    ;
  }
  v26 = gFGC->root;
  max_length = v26->max_length;
  if (v15 >= max_length)
  v26->m_Items[v15]->next = v26->m_Items[0];
  unit_nums = gFGC->unit_nums;
  v31 = (v12->_2.bitflags2 >> 1) & 1;
  if (unit_nums >= 2)
  {
    do
    {
      v32 = unit_nums - 1;
      v33 = gFGC->root;
      v34 = LODWORD(v33->max_length);
      v36 = &v33->obj.klass + unit_nums;
      v38 = gFGC->root + 8 * unit_nums--;
      *&v36[3]->_1.byval_arg.bits = *(v38 + 16);
      v31 = (v12->_2.bitflags2 >> 1) & 1;
    }
    while (v32 > 1);
  }
  v39 = gFGC;
  v40 = v39->root;
  v41 = v40->max_length;
  v42 = v39->root;
  v44 = v39->unit_nums;
  v45 = v40->m_Items[0];
  v45->prev = v42->m_Items[v44 - 1];
  if (Y_FontNums < 1)
  {
    this->fmInitFontMemControl_first_flag = 1;
    return 1;
  }
  else
  {
    v47 = 0;
    v48 = 0;
    v49 = 16 * FontWidth;
    v77 = 16 * FontHeight;
    v74 = this;
    v73 = Y_FontNums;
    while (X_FontNums < 1)
    {
      if (++v47 >= Y_FontNums)
    }
    v50 = v77 * v47;
    v51 = 0;
    v52 = 0;
    v76 = v47;
    v75 = v48;
    v53 = v48;
    v54 = 8LL * v48 + 32;
    while (1)
    {
      v57 = gFGC->root;
      v59 = *(&v57->obj.klass + 8 * v52 + v54);
      if (!v59)
        break;
      *(v59 + 16) = v53 + v52;
      v60 = *(v59 + 24);
      *(v60 + 32) = v51;
      v62 = *(v59 + 24);
      *(v62 + 36) = v50;
      v64 = *(v59 + 24);
      v65 = v64[6];
      v64[10] = v64[8] + v49;
      v67 = *(v59 + 24);
      v68 = v67[6];
      ++v52;
      v67[11] = v67[9] + v77;
      v51 += v49;
      *(v59 + 32) = 0;
      if (v52 >= X_FontNums)
      {
        v48 = v75 + v52;
        this = v74;
        Y_FontNums = v73;
        v47 = v76;
      }
    }
    v72 = gFGC;
    if (!v72->root)
      return 0;
    v72->root = 0;
    return 0;
  }
}

// 0x1398c90
FontMem_t *fmRentFontMem(fmgslCont *this) {
  struct FontMem_t_array *root;
  FontMem_t_o *next;

  root = gFGC->root;
  next = root->m_Items[0]->next;
  if (!next->id)
    return 0;
  next->prev->next = next->next;
  next->next->prev = next->prev;
  --gFGC->unit_nums;
  return next;
}

// 0x1398d90
u32 fmRetFontMem(FontMem_t *pFontArea) {
    return 0;
}
