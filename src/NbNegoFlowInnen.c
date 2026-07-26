#include "types.h"

typedef struct NbNegoFlowInnen_procfuncDelegate NbNegoFlowInnen_procfuncDelegate;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static u32 INNEN_SYOKAI_BIT_START;
static NbNegoFlowInnen_procfuncDelegate *procfunc[22];

void datAddItem(s32 id, s32 num);
s32 datSearchDevilStock(s32 id);
bool evtBitCheck(s32 no);
void evtBitOn(s32 no);
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
void nbSetMesItem(s32 msgid, s32 it);

// 0x539170
s32 Flow5_1(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x50002u);
  return 0;
}

// 0x539e30
s32 Flow5_10(nbNegoProcessData_t **n) {
  return 0;
}

// 0x539e40
s32 Flow5_11(nbNegoProcessData_t **n) {
  return 0;
}

// 0x539e50
s32 Flow5_12(nbNegoProcessData_t **n) {
  return 0;
}

// 0x539e60
s32 Flow5_13(nbNegoProcessData_t **n) {
  return 0;
}

// 0x539e70
s32 Flow5_14(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 innenmsg;
  struct datInnenNegoTable_t_array *InnenNegoTable;
  s64 innen_id;
  s32 losemes;

  v3 = *n;
  innenmsg = (*n)->innenmsg;
  innen_id = v3->innen_id;
  losemes = InnenNegoTable->m_Items[innen_id]->losemes;
  nbDispNegoMessage(n, innenmsg, losemes, 0);
  return 6;
}

// 0x539f60
s32 Flow5_15(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 innenmsg;
  struct datInnenNegoTable_t_array *InnenNegoTable;
  s64 innen_id;

  nbAddNegoIdKouho(n, 0x50012u);
  v4 = *n;
  innenmsg = (*n)->innenmsg;
  innen_id = v4->innen_id;
  nbDispNegoMessage(n, innenmsg, InnenNegoTable->m_Items[innen_id]->winmes, 0);
  return 0;
}

// 0x53a080
s32 Flow5_16(nbNegoProcessData_t **n) {
  return 0;
}

// 0x53a090
s32 Flow5_17(nbNegoProcessData_t **n) {
  return 0;
}

// 0x53a0a0
s32 Flow5_18(nbNegoProcessData_t **n) {
  s64 v3;
  struct datInnenNegoTable_t_array *InnenNegoTable;
  s64 innen_id;
  u64 v7;
  struct System_UInt16_array_array *item;
  s64 v10;
  nbNegoProcessData_t_o *v12;
  nbNegoProcessData_t_o *v13;
  struct datInnenNegoTable_t_array *v14;
  s64 v15;
  struct System_UInt16_array_array *v17;
  s64 v19;
  s32 getitem;
  s64 v22;
  struct datInnenNegoTable_t_array *v23;
  struct System_UInt16_array_array *v25;
  s64 v26;
  s32 v27;

  v3 = 4;
  do
  {
    innen_id = (*n)->innen_id;
    v7 = v3 - 4;
    item = InnenNegoTable->m_Items[innen_id]->item;
    v10 = *(&item->obj.klass + v3);
    if (!*(v10 + 32))
      break;
    v12 = *n;
    else
    {
      v13 = *n;
    }
    v14 = InnenNegoTable;
    v15 = v13->innen_id;
    v17 = v14->m_Items[v15]->item;
    v19 = *(&v17->obj.klass + v3);
    v12->getitem = *(v19 + 32);
    getitem = (*n)->getitem;
    v22 = (*n)->innen_id;
    v23 = InnenNegoTable;
    v25 = v23->m_Items[v22]->item;
    v26 = *(&v25->obj.klass + v3);
    v27 = *(v26 + 34);
    datAddItem(getitem, v27);
    ++v3;
  }
  while (v7 < 5);
  nbAddNegoIdKouho(n, 0x50015u);
  return 0;
}

// 0x53a390
s32 Flow5_19(nbNegoProcessData_t **n) {
  return 0;
}

// 0x539210
s32 Flow5_2(nbNegoProcessData_t **n) {
  s32 id;
  nbNegoProcessData_t_o *v6;
  struct System_UInt32_array *nextkouho;
  bool v10;
  nbNegoProcessData_t_o *v12;
  struct System_UInt32_array *v13;
  u32 max_length;

  nbAddNegoIdKouho(n, 0x50003u);
  nbAddNegoIdKouho(n, 0x10021u);
  id = (*n)->ework->id;
  else if ((datSearchDevilStock(id) & 0x80000000) == 0)
  {
    v6 = *n;
    nextkouho = v6->nextkouho;
    v6->nextnegoid = nextkouho->m_Items[1];
    return 0;
  }
  v10 = evtBitCheck((*n)->innen_id + INNEN_SYOKAI_BIT_START, 0);
  v12 = *n;
  v13 = (*n)->nextkouho;
  max_length = v13->max_length;
  if (v10)
  {
    v12->nextnegoid = v13->m_Items[1];
  }
  else
  {
    v12->nextnegoid = v13->m_Items[0];
    evtBitOn((*n)->innen_id + INNEN_SYOKAI_BIT_START, 0);
  }
  return 0;
}

// 0x53a3a0
s32 Flow5_20(nbNegoProcessData_t **n) {
  return 0;
}

// 0x53a3b0
s32 Flow5_21(nbNegoProcessData_t **n) {
  struct datInnenNegoTable_t_array *InnenNegoTable;
  s64 innen_id;
  Il2CppClass **v7;
  s64 nownegophase;
  const char *namespaze;
  s64 v10;
  nbNegoProcessData_t_o *v12;
  nbNegoProcessData_t_o *v13;
  struct datInnenNegoTable_t_array *v17;
  s64 v18;
  Il2CppClass **v20;
  s64 v21;
  const char *v22;
  s64 v24;
  s32 helpmsg;
  s32 getitem;

  innen_id = (*n)->innen_id;
  v7 = &InnenNegoTable->obj.klass + innen_id;
  nownegophase = (*n)->nownegophase;
  namespaze = v7[4]->_1.namespaze;
  v10 = *&namespaze[8 * nownegophase + 32];
  if (!*(v10 + 32))
    return 6;
  v12 = *n;
  else
  {
    v13 = *n;
  }
  v17 = InnenNegoTable;
  v18 = v13->innen_id;
  v20 = &v17->obj.klass + v18;
  v21 = v13->nownegophase;
  v22 = v20[4]->_1.namespaze;
  v24 = *&v22[8 * v21 + 32];
  v12->getitem = *(v24 + 32);
  helpmsg = (*n)->helpmsg;
  getitem = (*n)->getitem;
  nbSetMesItem(helpmsg, getitem);
  nbDispNegoMessage(n, (*n)->helpmsg, 5, 0, 0);
  return 0;
}

// 0x539400
s32 Flow5_3(nbNegoProcessData_t **n) {
  struct datInnenNegoTable_t_array *InnenNegoTable;
  nbNegoProcessData_t_o *v5;
  s64 innen_id;
  s32 innenmsg;
  struct datInnenNegoTable_t_array *v10;
  s64 v11;
  s32 mainmes;
  s32 nownegophase;
  s64 i;
  struct datInnenNegoTable_t_array *v18;
  s64 v19;
  u64 v20;
  struct InnenMotionInfo_s_array *innen_motion;
  nbNegoProcessData_t_o *v24;
  struct datInnenNegoTable_t_array *v26;
  s64 v27;
  struct InnenMotionInfo_s_array *v29;
  nbNegoProcessData_t_o *v31;
  nbFormation_t_o **p_pform;
  struct datInnenNegoTable_t_array *v34;
  s64 v35;
  struct InnenMotionInfo_s_array *v37;
  s32 v39;
  nbFormation_t_o *form;

  form = 0;
  v5 = *n;
  innen_id = (*n)->innen_id;
  if (v5->nownegophase >= InnenNegoTable->m_Items[innen_id]->mescnt)
  {
    nbAddNegoIdKouho(n, 0x50004u);
  }
  else
  {
    innenmsg = v5->innenmsg;
    v10 = InnenNegoTable;
    v11 = v5->innen_id;
    mainmes = v10->m_Items[v11]->mainmes;
    nownegophase = v5->nownegophase;
    nbDispNegoMessage(n, innenmsg, nownegophase + mainmes, 0);
    for (i = 4; i != 7; ++i)
    {
      v18 = InnenNegoTable;
      v19 = (*n)->innen_id;
      v20 = i - 4;
      innen_motion = v18->m_Items[v19]->innen_motion;
      v24 = *n;
      if ((*n)->nownegophase + 1 == *(*(&innen_motion->obj.klass + i) + 16LL))
      {
        v26 = InnenNegoTable;
        v27 = v24->innen_id;
        v29 = v26->m_Items[v27]->innen_motion;
        v31 = *n;
        if (*(*(&v29->obj.klass + i) + 18LL) == 1)
          p_pform = &(*n)->pform;
        else
          p_pform = &(*n)->eform;
        form = *p_pform;
        v34 = InnenNegoTable;
        v35 = v31->innen_id;
        v37 = v34->m_Items[v35]->innen_motion;
        if (*(*(&v37->obj.klass + i) + 20LL) == 1)
          v39 = 14;
        else
          v39 = 15;
        nbAddMotionKoukaPacket(0, 0, &form, v39);
      }
    }
  }
  return 0;
}

// 0x539790
s32 Flow5_4(nbNegoProcessData_t **n) {
  struct datInnenNegoTable_t_array *InnenNegoTable;
  s64 innen_id;
  nbNegoProcessData_t_o *v7;
  struct System_UInt32_array *nextkouho;

  innen_id = (*n)->innen_id;
  if (InnenNegoTable->m_Items[innen_id]->result == 1)
    return 4;
  if (!InnenNegoTable->m_Items[innen_id]->result)
  {
    nbAddNegoIdKouho(n, 0x50006u);
    v7 = *n;
    nextkouho = v7->nextkouho;
    v7->nextnegoid = nextkouho->m_Items[0];
  }
  return 0;
}

// 0x5398e0
s32 Flow5_5(nbNegoProcessData_t **n) {
  return 0;
}

// 0x5398f0
s32 Flow5_6(nbNegoProcessData_t **n) {
  s64 v3;
  struct datInnenNegoTable_t_array *InnenNegoTable;
  s64 innen_id;
  u64 v7;
  struct System_UInt16_array_array *item;
  s64 v10;
  nbNegoProcessData_t_o *v12;
  nbNegoProcessData_t_o *v13;
  struct datInnenNegoTable_t_array *v14;
  s64 v15;
  struct System_UInt16_array_array *v17;
  s64 v19;
  s32 getitem;
  s64 v22;
  struct datInnenNegoTable_t_array *v23;
  struct System_UInt16_array_array *v25;
  s64 v26;
  s32 v27;

  v3 = 4;
  do
  {
    innen_id = (*n)->innen_id;
    v7 = v3 - 4;
    item = InnenNegoTable->m_Items[innen_id]->item;
    v10 = *(&item->obj.klass + v3);
    if (!*(v10 + 32))
      break;
    v12 = *n;
    else
    {
      v13 = *n;
    }
    v14 = InnenNegoTable;
    v15 = v13->innen_id;
    v17 = v14->m_Items[v15]->item;
    v19 = *(&v17->obj.klass + v3);
    v12->getitem = *(v19 + 32);
    getitem = (*n)->getitem;
    v22 = (*n)->innen_id;
    v23 = InnenNegoTable;
    v25 = v23->m_Items[v22]->item;
    v26 = *(&v25->obj.klass + v3);
    v27 = *(v26 + 34);
    datAddItem(getitem, v27);
    ++v3;
  }
  while (v7 < 5);
  nbAddNegoIdKouho(n, 0x50009u);
  return 0;
}

// 0x539be0
s32 Flow5_7(nbNegoProcessData_t **n) {
  return 0;
}

// 0x539bf0
s32 Flow5_8(nbNegoProcessData_t **n) {
  return 0;
}

// 0x539c00
s32 Flow5_9(nbNegoProcessData_t **n) {
  struct datInnenNegoTable_t_array *InnenNegoTable;
  s64 innen_id;
  Il2CppClass **v7;
  s64 nownegophase;
  const char *namespaze;
  s64 v10;
  nbNegoProcessData_t_o *v12;
  nbNegoProcessData_t_o *v13;
  struct datInnenNegoTable_t_array *v17;
  s64 v18;
  Il2CppClass **v20;
  s64 v21;
  const char *v22;
  s64 v24;
  s32 helpmsg;
  s32 getitem;

  innen_id = (*n)->innen_id;
  v7 = &InnenNegoTable->obj.klass + innen_id;
  nownegophase = (*n)->nownegophase;
  namespaze = v7[4]->_1.namespaze;
  v10 = *&namespaze[8 * nownegophase + 32];
  if (!*(v10 + 32))
    return 2;
  v12 = *n;
  else
  {
    v13 = *n;
  }
  v17 = InnenNegoTable;
  v18 = v13->innen_id;
  v20 = &v17->obj.klass + v18;
  v21 = v13->nownegophase;
  v22 = v20[4]->_1.namespaze;
  v24 = *&v22[8 * v21 + 32];
  v12->getitem = *(v24 + 32);
  helpmsg = (*n)->helpmsg;
  getitem = (*n)->getitem;
  nbSetMesItem(helpmsg, getitem);
  nbDispNegoMessage(n, (*n)->helpmsg, 8, 0, 0);
  return 0;
}

// 0x539150
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x539160
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x53a5e0
s32 nbNegoFlowInnen(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowInnen_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
