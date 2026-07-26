#include "types.h"

typedef struct NbNegoFlowKoketa_procfuncDelegate NbNegoFlowKoketa_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowKoketa_procfuncDelegate *procfunc[4];

s32 datGetRace(datUnitWork_t *work);
s32 evtGetAgeOfMoon(void);
nbKoukaPacket_t *nbAddMojiEffKoukaPacket(s32 startframe, s32 frame, s32 uniqueid, nbFormation_t **form, s32 type);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbCameraSetBougai(nbFormation_t **pTargetForm);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);

// 0x53d730
s32 Flow16_1(nbNegoProcessData_t **n) {
  nbFormation_t_o **p_eform;
  datUnitWork_t_o *ework;
  nbNegoProcessData_t_o *v7;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0x100002u);
  nbAddNegoIdKouho(n, 0x100003u);
  nbAddMojiEffKoukaPacket(0, 30, (*n)->actdata->uniqueid, &(*n)->eform, 0, 0);
  p_eform = &(*n)->eform;
  nbCameraSetBougai(p_eform);
  ework = (*n)->ework;
  if ((datGetRace(ework) - 21) <= 2)
  {
    v7 = *n;
    nextkouho = v7->nextkouho;
    v7->nextnegoid = nextkouho->m_Items[1];
  }
  return 0;
}

// 0x53d8a0
s32 Flow16_2(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 id;
  bool v5;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v9;
  s32 v10;
  s32 AgeOfMoon;
  struct System_Int32_array *v13;
  s64 v14;

  v3 = *n;
  id = (*n)->ework->id;
  v5 = id > 0x1E || ((1 << id) & 0x61012538) == 0;
  if (!v5 || id == 150 || id == 153)
  AgeOfMoon = evtGetAgeOfMoon();
  v3 = *n;
  if (AgeOfMoon != 8)
  {
    flowmsg = v3->flowmsg;
    ekucyo = v3->ekucyo;
    v9 = flowmsg->m_Items[ekucyo];
    v10 = 300;
  }
  else
  {
    v13 = v3->flowmsg;
    v14 = v3->ekucyo;
    v9 = v13->m_Items[v14];
    v10 = 296;
  }
  nbDispNegoMessage(n, v9, v10, 0);
  return 4;
}

// 0x53da20
s32 Flow16_3(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v6;

  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v6 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v6, 300, 0);
  return 4;
}

// 0x53d710
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x53d720
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x53dae0
s32 nbNegoFlowKoketa(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowKoketa_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
