#include "types.h"

typedef struct NbNegoFlowBinjo_procfuncDelegate NbNegoFlowBinjo_procfuncDelegate;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowBinjo_procfuncDelegate *procfunc[3];

void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x12aca30
s32 Flow14_1(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;

  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 917506;
  return 0;
}

// 0x12acb00
s32 Flow14_2(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x1001Eu);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 272, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x12aca10
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x12aca20
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x12acc40
s32 nbNegoFlowBinjo(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowBinjo_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
