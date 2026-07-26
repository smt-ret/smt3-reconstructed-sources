#include "types.h"

typedef struct NbNegoFlowStock_procfuncDelegate NbNegoFlowStock_procfuncDelegate;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowStock_procfuncDelegate *procfunc[3];

void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);

// 0xef3870
s32 Flow3_1(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x30002u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 48, 0);
  return 0;
}

// 0xef3960
s32 Flow3_2(nbNegoProcessData_t **n) {
  s32 helpmsg;

  helpmsg = (*n)->helpmsg;
  nbDispNegoMessage(n, helpmsg, 1, 0);
  return 2;
}

// 0xef3850
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0xef3860
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0xef39f0
s32 nbNegoFlowStock(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowStock_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
