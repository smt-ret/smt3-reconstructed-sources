#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;

static s32 btl_ai_rot_cnt;

void AiChkJoken(u32 c);
u8 Get(s32 id);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon16(void);
void itfMesMngSetVar(s32 id, s32 index, s32 num, s32 type);
s32 nbAiChkJoken(nbActionProcessData_t **a, u32 jo);
void nbAllFormDispOn(void);
void nbCameraScriptSet(sdfVector4_t pPos, sdfVector4_t pQ);
void nbCameraScriptSet1Shot(nbFormation_t **pTargetForm);
void nbCameraScriptSetBougai(nbFormation_t **pTargetForm);
void nbDelAllKoukaPacketType(s32 type);
s32 nbGetAisyoTable(s32 formindex);
nbMainProcessData_t *nbGetMainProcessData(void);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
u32 nbGetSelectBit(nbMainProcessData_t *data);
void nbGroupFormDispOff(s32 side);
void nbGroupFormDispOn(s32 side);
void nbPanelAllHide(void);
void nbPanelAutoHide(void);
s32 nbRunAi(nbActionProcessData_t **a);
s32 nbRunAiSub(nbActionProcessData_t **a, s32 tbl);
s32 nbSetAiTarget(nbActionProcessData_t **a, s32 code, s32 n);
s32 nbSetEnemySummonFormation(nbMainProcessData_t **data, s32 devilid);
void nbSetNormalSkill0(datUnitWork_t *work);
void *scrGetData(void);
f32 scrGetFloatPara(s32 n);
s32 scrGetIntPara(s32 n);
void scrSetIntReturnValue(s32 i);
void scrSetUserData(dds3ProcessID_t *id, void *p);
dds3ProcessID_t *scrStartScript2(s32 a, void *b, s32 c);

// 0xfa7690
void AiChkJoken(u32 c) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 v11;
  nbActionProcessData_t_o *v12[3];
  nbActionProcessData_t_o *a;

  a = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v12);
    if ((v12[0] & 1) != 0)
      v8 = v12[2];
    else
      v8 = v12 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_12:
  a = Data;
  Data->aiselect = 0;
  if (nbAiChkJoken(&a, c))
  {
    v11 = 1;
  }
  else
  {
    v11 = 0;
  }
  scrSetIntReturnValue(v11);
}

// 0xfa9170
s32 nbCommand_AI(void) {
  Il2CppObject *Data;
  nbActionProcessData_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  nbActionProcessData_t_o *v9[3];
  nbActionProcessData_t_o *a;

  a = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
LABEL_12:
  a = Data;
  nbRunAi(&a, v3);
  return 1;
}

// 0xfa5bb0
s32 nbCommand_AI_ACT_ATTACK(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  datUnitWork_t_o *v6;
  char *v8;
  s64 *v9;
  u64 v10[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  LOWORD(Data[5].klass->_1.parent) = 0;
  v6 = Data[5].klass;
  nbSetNormalSkill0(v6);
  return 1;
}

// 0xfa5cf0
s32 nbCommand_AI_ACT_ESCAPE(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  LOWORD(Data[5].klass->_1.parent) = 7;
  WORD1(Data[5].klass->_1.parent) = 0;
  return 1;
}

// 0xfa5f30
s32 nbCommand_AI_ACT_SKILL(void) {
  Il2CppObject *Data;
  s16 IntPara;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  Data = scrGetData();
  IntPara = scrGetIntPara(0);
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LOWORD(Data[5].klass->_1.parent) = 1;
  WORD1(Data[5].klass->_1.parent) = IntPara;
  return 1;
}

// 0xfa6060
s32 nbCommand_AI_ACT_SUMMON(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  s16 IntPara;
  s32 v9;
  s32 v11;
  nbMainProcessData_t_o **v12;
  u64 v14[3];

  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v5 = v14[2];
    else
      v5 = v14 + 1;
    v6 = sub_8C4940(v5);
  }
LABEL_12:
  IntPara = scrGetIntPara(0);
  LOWORD(Data[5].klass->_1.parent) = 1;
  WORD1(Data[5].klass->_1.parent) = IntPara;
  v9 = scrGetIntPara(1);
  LODWORD(Data[16].klass) = v9;
  v11 = v9;
  v12 = &Data[1];
  nbSetEnemySummonFormation(v12, v11);
  return 1;
}

// 0xfa5e10
s32 nbCommand_AI_ACT_WAIT(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  LOWORD(Data[5].klass->_1.parent) = 3;
  WORD1(Data[5].klass->_1.parent) = 0;
  return 1;
}

// 0xfa8230
s32 nbCommand_AI_CHK_BA(void) {
  AiChkJoken(0xF0000u);
  return 1;
}

// 0xfa7a10
s32 nbCommand_AI_CHK_DMGCNT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x30000);
  return 1;
}

// 0xfa7dd0
s32 nbCommand_AI_CHK_ENALLBAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xA0000);
  return 1;
}

// 0xfa7d30
s32 nbCommand_AI_CHK_ENBAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x90000);
  return 1;
}

// 0xfa7b50
s32 nbCommand_AI_CHK_ENCNT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x60000);
  return 1;
}

// 0xfa8310
s32 nbCommand_AI_CHK_ENDARK(void) {
  AiChkJoken(0x110000u);
  return 1;
}

// 0xfa9060
s32 nbCommand_AI_CHK_ENHAMAMHK(void) {
  AiChkJoken(0x1B0000u);
  return 1;
}

// 0xfa7fb0
s32 nbCommand_AI_CHK_ENHOJO(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xD0000);
  return 1;
}

// 0xfa80f0
s32 nbCommand_AI_CHK_ENHOJOMAX(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x190000);
  return 1;
}

// 0xfa7e70
s32 nbCommand_AI_CHK_ENID(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xB0000);
  return 1;
}

// 0xfa82a0
s32 nbCommand_AI_CHK_ENLIGHT(void) {
  AiChkJoken(0x100000u);
  return 1;
}

// 0xfa8e00
s32 nbCommand_AI_CHK_ESCAPE(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v6;
  s32 castClass_high;
  s32 v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v6 = Data[1].klass;
  if ((BYTE4(v6->_1.klass) & 1) != 0)
    goto LABEL_30;
  castClass_high = HIDWORD(v6->_1.castClass);
  if (Get(castClass_high, 0)->esc == 1)
  {
LABEL_30:
    v8 = 0;
  }
  else
  {
    v8 = 1;
  }
  scrSetIntReturnValue(v8);
  return 1;
}

// 0xfa7c90
s32 nbCommand_AI_CHK_FRBAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x80000);
  return 1;
}

// 0xfa7ab0
s32 nbCommand_AI_CHK_FRCNT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x50000);
  return 1;
}

// 0xfa8050
s32 nbCommand_AI_CHK_FRHOJO(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xE0000);
  return 1;
}

// 0xfa8190
s32 nbCommand_AI_CHK_FRHOJOMAX(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x1A0000);
  return 1;
}

// 0xfa7970
s32 nbCommand_AI_CHK_FRHP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x20000);
  return 1;
}

// 0xfa7f10
s32 nbCommand_AI_CHK_FRID(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xC0000);
  return 1;
}

// 0xfa7bf0
s32 nbCommand_AI_CHK_MYBAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x70000);
  return 1;
}

// 0xfa7830
s32 nbCommand_AI_CHK_MYHP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x10000);
  return 1;
}

// 0xfa78d0
s32 nbCommand_AI_CHK_MYMP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x180000);
  return 1;
}

// 0xfa83f0
s32 nbCommand_AI_CHK_PLV(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x130000);
  return 1;
}

// 0xfa8380
s32 nbCommand_AI_CHK_POW(void) {
  AiChkJoken(0x120000u);
  return 1;
}

// 0xfa8490
s32 nbCommand_AI_CHK_PPARTYLV(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x140000);
  return 1;
}

// 0xfa90d0
s32 nbCommand_AI_CHK_SKILLNOMP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x1C0000);
  return 1;
}

// 0xfa8650
s32 nbCommand_AI_GET_ALLKOUDO(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v6;
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;
  char *v11;
  s64 *v12;
  u64 v13[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v6 = *(Data[4].monitor + 89);
  PartyFromFormindex = nbGetPartyFromFormindex(v6);
  if (PartyFromFormindex)
  {
    count = PartyFromFormindex->count;
    LODWORD(PartyFromFormindex) = count->m_Items[17];
  }
  scrSetIntReturnValue(PartyFromFormindex);
  return 1;
}

// 0xfa8d60
s32 nbCommand_AI_GET_FUREA(void) {
  s32 AgeOfMoon16;
  s32 v4;

  AgeOfMoon16 = evtGetAgeOfMoon16();
  if (AgeOfMoon16 >= 0)
    v4 = AgeOfMoon16;
  else
    v4 = AgeOfMoon16 + 1;
  scrSetIntReturnValue(v4 >> 1);
  return 1;
}

// 0xfa8a90
s32 nbCommand_AI_GET_MYAISYO(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 AisyoTable;
  char *v7;
  s64 *v8;
  u64 v9[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  AisyoTable = nbGetAisyoTable(*(Data[4].monitor + 89), nbActionProcessData_t);
  scrSetIntReturnValue(AisyoTable);
  return 1;
}

// 0xfa8970
s32 nbCommand_AI_GET_MYLV(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  scrSetIntReturnValue(WORD2(Data[5].klass->_1.byval_arg.data), 0);
  return 1;
}

// 0xfa87e0
s32 nbCommand_AI_GET_PRESSKOUDO(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v6;
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;
  char *v11;
  s64 *v12;
  u64 v13[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v13);
    if ((v13[0] & 1) != 0)
      v11 = v13[2];
    else
      v11 = v13 + 1;
    v12 = sub_8C4940(v11);
  }
  v6 = *(Data[4].monitor + 89);
  PartyFromFormindex = nbGetPartyFromFormindex(v6);
  if (PartyFromFormindex)
  {
    count = PartyFromFormindex->count;
    LODWORD(PartyFromFormindex) = count->m_Items[18];
  }
  scrSetIntReturnValue(PartyFromFormindex);
  return 1;
}

// 0xfa8530
s32 nbCommand_AI_GET_TURN(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  scrSetIntReturnValue(BYTE4(Data[1].klass->_1.fields), 0);
  return 1;
}

// 0xfa6210
s32 nbCommand_AI_SET_CRITICAL(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  LOWORD(Data[4].klass->_1.name) |= 0x100u;
  return 1;
}

// 0xfa6330
s32 nbCommand_AI_TAR_AI(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v10;
  nbActionProcessData_t_o *v12;
  u64 v13[3];

  v12 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v13);
    if ((v13[0] & 1) != 0)
      v7 = v13[2];
    else
      v7 = v13 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v12 = Data;
  if (!nbSetAiTarget(&v12, 0, 0))
  {
    v10 = Data->data;
    Data->select = nbGetSelectBit(v10);
  }
  return 1;
}

// 0xfa6690
s32 nbCommand_AI_TAR_BAARLV(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v11;
  nbActionProcessData_t_o *v13;
  u64 v14[3];

  v13 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v7 = v14[2];
    else
      v7 = v14 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v13 = Data;
  if (!nbSetAiTarget(&v13, 9, 0))
    goto LABEL_20;
  if (!nbSetAiTarget(&v13, 0, 0))
  {
LABEL_20:
    v11 = Data->data;
    Data->select = nbGetSelectBit(v11);
  }
  return 1;
}

// 0xfa6a10
s32 nbCommand_AI_TAR_BAD(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  s32 IntPara;
  nbMainProcessData_t_o *v12;
  nbActionProcessData_t_o *v14[3];
  nbActionProcessData_t_o *a;

  a = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v5 = v14[2];
    else
      v5 = v14 + 1;
    v6 = sub_8C4940(v5);
  }
LABEL_12:
  a = Data;
  IntPara = scrGetIntPara(0);
  if (!nbSetAiTarget(&a, 2, IntPara))
    goto LABEL_20;
  if (!nbSetAiTarget(&a, 0, 0))
  {
LABEL_20:
    v12 = Data->data;
    Data->select = nbGetSelectBit(v12);
  }
  return 1;
}

// 0xfa6f90
s32 nbCommand_AI_TAR_DARK(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v11;
  nbActionProcessData_t_o *v13;
  u64 v14[3];

  v13 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v7 = v14[2];
    else
      v7 = v14 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v13 = Data;
  if (!nbSetAiTarget(&v13, 5, 0))
    goto LABEL_20;
  if (!nbSetAiTarget(&v13, 0, 0))
  {
LABEL_20:
    v11 = Data->data;
    Data->select = nbGetSelectBit(v11);
  }
  return 1;
}

// 0xfa6bf0
s32 nbCommand_AI_TAR_ID(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  s32 IntPara;
  nbMainProcessData_t_o *v12;
  nbActionProcessData_t_o *v14[3];
  nbActionProcessData_t_o *a;

  a = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v5 = v14[2];
    else
      v5 = v14 + 1;
    v6 = sub_8C4940(v5);
  }
LABEL_12:
  a = Data;
  IntPara = scrGetIntPara(0);
  if (!nbSetAiTarget(&a, 3, IntPara))
    goto LABEL_20;
  if (!nbSetAiTarget(&a, 0, 0))
  {
LABEL_20:
    v12 = Data->data;
    Data->select = nbGetSelectBit(v12);
  }
  return 1;
}

// 0xfa74d0
s32 nbCommand_AI_TAR_JOKEN(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v11;
  nbActionProcessData_t_o *v13;
  u64 v14[3];

  v13 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v7 = v14[2];
    else
      v7 = v14 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v13 = Data;
  if (!nbSetAiTarget(&v13, 7, 0))
    goto LABEL_20;
  if (!nbSetAiTarget(&v13, 0, 0))
  {
LABEL_20:
    v11 = Data->data;
    Data->select = nbGetSelectBit(v11);
  }
  return 1;
}

// 0xfa64d0
s32 nbCommand_AI_TAR_LIFEMIN(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v11;
  nbActionProcessData_t_o *v13;
  u64 v14[3];

  v13 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v7 = v14[2];
    else
      v7 = v14 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v13 = Data;
  if (!nbSetAiTarget(&v13, 1, 0))
    goto LABEL_20;
  if (!nbSetAiTarget(&v13, 0, 0))
  {
LABEL_20:
    v11 = Data->data;
    Data->select = nbGetSelectBit(v11);
  }
  return 1;
}

// 0xfa6dd0
s32 nbCommand_AI_TAR_LIGHT(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v11;
  nbActionProcessData_t_o *v13;
  u64 v14[3];

  v13 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v7 = v14[2];
    else
      v7 = v14 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v13 = Data;
  if (!nbSetAiTarget(&v13, 4, 0))
    goto LABEL_20;
  if (!nbSetAiTarget(&v13, 0, 0))
  {
LABEL_20:
    v11 = Data->data;
    Data->select = nbGetSelectBit(v11);
  }
  return 1;
}

// 0xfa6850
s32 nbCommand_AI_TAR_LVMIN(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v11;
  nbActionProcessData_t_o *v13;
  u64 v14[3];

  v13 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v7 = v14[2];
    else
      v7 = v14 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v13 = Data;
  if (!nbSetAiTarget(&v13, 10, 0))
    goto LABEL_20;
  if (!nbSetAiTarget(&v13, 0, 0))
  {
LABEL_20:
    v11 = Data->data;
    Data->select = nbGetSelectBit(v11);
  }
  return 1;
}

// 0xfa7150
s32 nbCommand_AI_TAR_PLAYER(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v11;
  nbActionProcessData_t_o *v13;
  u64 v14[3];

  v13 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v7 = v14[2];
    else
      v7 = v14 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v13 = Data;
  if (!nbSetAiTarget(&v13, 6, 0))
    goto LABEL_20;
  if (!nbSetAiTarget(&v13, 0, 0))
  {
LABEL_20:
    v11 = Data->data;
    Data->select = nbGetSelectBit(v11);
  }
  return 1;
}

// 0xfa7310
s32 nbCommand_AI_TAR_RND(void) {
  nbActionProcessData_t_o *Data;
  nbActionProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  nbMainProcessData_t_o *v11;
  nbActionProcessData_t_o *v13;
  u64 v14[3];

  v13 = 0;
  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v7 = v14[2];
    else
      v7 = v14 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  v13 = Data;
  if (!nbSetAiTarget(&v13, 8, 0))
    goto LABEL_20;
  if (!nbSetAiTarget(&v13, 0, 0))
  {
LABEL_20:
    v11 = Data->data;
    Data->select = nbGetSelectBit(v11);
  }
  return 1;
}

// 0xfa92c0
s32 nbCommand_AI_TBL(void) {
  s32 IntPara;
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppObject *v11;
  u64 v12[3];

  v11 = 0;
  IntPara = scrGetIntPara(0);
  Data = scrGetData();
  if (Data)
  {
    klass = Data->klass;
    if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v12);
      if ((v12[0] & 1) != 0)
        v8 = v12[2];
      else
        v8 = v12 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v11 = Data;
  nbRunAiSub(&v11, IntPara);
  return 1;
}

// 0xfaa300
s32 nbCommand_BTL_AI_CHANGE_OFF(void) {
  nbMainProcessData_t_o *MainProcessData;

  MainProcessData = nbGetMainProcessData();
  MainProcessData->stat |= 0x40000u;
  return 1;
}

// 0xfaa380
s32 nbCommand_BTL_AI_CHANGE_ON(void) {
  nbMainProcessData_t_o *MainProcessData;

  MainProcessData = nbGetMainProcessData();
  MainProcessData->stat &= ~0x40000u;
  return 1;
}

// 0xfaa130
s32 nbCommand_BTL_AI_ROT_CLR(void) {
  btl_ai_rot_cnt = 0;
  return 1;
}

// 0xfaa260
s32 nbCommand_BTL_AI_ROT_GET(void) {
  s32 btl_ai_rot_cnt;

  scrSetIntReturnValue(btl_ai_rot_cnt);
  return 1;
}

// 0xfaa1a0
s32 nbCommand_BTL_AI_ROT_NEXT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  ++btl_ai_rot_cnt;
  btl_ai_rot_cnt %= IntPara;
  return 1;
}

// 0xfa9c00
s32 nbCommand_BTL_ALLTAIKYO(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
LABEL_12:
  HIDWORD(Data[1].klass->_1.interfaceOffsets) = 6;
  WORD1(Data[1].klass->_1.interfaceOffsets) = *(Data[4].monitor + 89);
  LODWORD(Data[9].klass) = 0;
  return 1;
}

// 0xfa9600
s32 nbCommand_BTL_CAM_1SHOT(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  nbFormation_t_o **p_monitor;
  u64 v10[3];

  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v10);
    if ((v10[0] & 1) != 0)
      v6 = v10[2];
    else
      v6 = v10 + 1;
    v7 = sub_8C4940(v6);
  }
LABEL_12:
  p_monitor = &Data[4].monitor;
  nbCameraScriptSet1Shot(p_monitor);
  return 1;
}

// 0xfa9750
s32 nbCommand_BTL_CAM_2SHOT(void) {
  return 1;
}

// 0xfa9760
s32 nbCommand_BTL_CAM_BOUGAI(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  nbFormation_t_o **p_monitor;
  u64 v10[3];

  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v10);
    if ((v10[0] & 1) != 0)
      v6 = v10[2];
    else
      v6 = v10 + 1;
    v7 = sub_8C4940(v6);
  }
LABEL_12:
  p_monitor = &Data[4].monitor;
  nbCameraScriptSetBougai(p_monitor);
  return 1;
}

// 0xfa95f0
s32 nbCommand_BTL_CAM_ORG(void) {
  return 1;
}

// 0xfa9410
s32 nbCommand_BTL_CAM_SET(void) {
  s64 v3;
  s64 v4;
  s64 v5;
  s64 v6;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;

  v10 = 0;
  v11 = 0;
  sub_854690(&v10, 0.0, 0.0, 0.0, 0.0);
  v8 = 0;
  v9 = 0;
  scrGetData();
  scrGetFloatPara(0);
  sub_854930(&v10, 0);
  scrGetFloatPara(1);
  sub_854930(&v10, 1u);
  scrGetFloatPara(2);
  sub_854930(&v10, 2u);
  scrGetFloatPara(3);
  sub_854930(&v8, 0);
  scrGetFloatPara(4);
  sub_854930(&v8, 1u);
  scrGetFloatPara(5);
  sub_854930(&v8, 2u);
  scrGetFloatPara(6);
  sub_854930(&v8, 3u);
  v3 = v10;
  v4 = v11;
  v5 = v8;
  v6 = v9;
  *&v12.x = v3;
  *&v12.z = v4;
  *&v13.x = v5;
  *&v13.z = v6;
  nbCameraScriptSet(v12, v13);
  return 1;
}

// 0xfa99a0
s32 nbCommand_BTL_EVENT(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v5;
  char *v7;
  s64 *v8;
  u64 v9[3];

  Data = scrGetData();
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  v5 = Data[1].klass;
  LODWORD(v5->_1.implementedInterfaces) = scrGetIntPara(0);
  return 1;
}

// 0xfa9fc0
s32 nbCommand_BTL_FORM_ALL_ON(void) {
  nbAllFormDispOn();
  return 1;
}

// 0xfaa0b0
s32 nbCommand_BTL_FORM_ENE_ON(void) {
  nbGroupFormDispOff(0);
  nbGroupFormDispOn(1);
  return 1;
}

// 0xfaa030
s32 nbCommand_BTL_FORM_PLY_ON(void) {
  nbGroupFormDispOn(0);
  nbGroupFormDispOff(1);
  return 1;
}

// 0xfa9e80
s32 nbCommand_BTL_NAKAMA(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
LABEL_12:
  HIDWORD(Data[1].klass->_1.interfaceOffsets) = 3;
  WORD1(Data[1].klass->_1.interfaceOffsets) = *(Data[4].monitor + 89);
  LODWORD(Data[9].klass) = 0;
  return 1;
}

// 0xfa98b0
s32 nbCommand_BTL_PNL_OFF(void) {
  nbMainProcessData_t_o *MainProcessData;

  nbPanelAllHide();
  nbPanelAutoHide();
  else
  {
    MainProcessData = nbGetMainProcessData();
    if (!MainProcessData)
      return 1;
  }
  if (MainProcessData->encno == 93)
  {
    nbDelAllKoukaPacketType(16);
    nbDelAllKoukaPacketType(22);
    return 1;
  }
  return 1;
}

// 0xfa9990
s32 nbCommand_BTL_PNL_ON(void) {
  return 1;
}

// 0xfa9d40
s32 nbCommand_BTL_PRESS(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
LABEL_12:
  HIDWORD(Data[1].klass->_1.interfaceOffsets) = 4;
  WORD1(Data[1].klass->_1.interfaceOffsets) = *(Data[4].monitor + 89);
  LODWORD(Data[9].klass) = 0;
  return 1;
}

// 0xfa9ac0
s32 nbCommand_BTL_TAIKYO(void) {
  Il2CppObject *Data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v8[3];

  else
  {
    Data = scrGetData();
    if (!Data)
      goto LABEL_12;
  }
  klass = Data->klass;
  if (Data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v5 = v8[2];
    else
      v5 = v8 + 1;
    v6 = sub_8C4940(v5);
  }
LABEL_12:
  HIDWORD(Data[1].klass->_1.interfaceOffsets) = 2;
  WORD1(Data[1].klass->_1.interfaceOffsets) = *(Data[4].monitor + 89);
  LODWORD(Data[9].klass) = 0;
  return 1;
}

// 0xfaa400
void nbInitAiScript(nbActionProcessData_t **a, s32 no) {
  s32 fieldID;
  u32 priority;
  System_Byte_array *tbl;
  Il2CppObject *v14;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 monitor_high;
  s32 id;
  dds3ProcessID_t_o **p_MainProcessID;
  char *v23;
  s64 *v24;
  dds3ProcessID_t_o *started;
  u64 v26[3];

  started = 0;
  if (!evtBitCheck(3712))
  {
    fieldID = fldGb->fieldID;
    if (fieldID != 260)
    {
      else if (fieldID == 261)
      {
        goto LABEL_11;
      }
      priority = (*a)->data->MainProcessID->priority;
        goto LABEL_15;
      goto LABEL_22;
    }
  }
LABEL_11:
  priority = (*a)->data->MainProcessID->priority;
  tbl = ai_scrd;
  {
LABEL_15:
  }
LABEL_22:
  started = scrStartScript2(priority - 1, tbl, no);
  v14 = *a;
  scrSetUserData(started, v14);
  ProcessData = dds3GetProcessData(&started);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != scrProcessWork_s)
  {
    sub_8FC2C0(klass->_1.element_class, scrProcessWork_s, v26);
    if ((v26[0] & 1) != 0)
      v23 = v26[2];
    else
      v23 = v26 + 1;
    v24 = sub_8C4940(v23);
  }
  monitor_high = HIDWORD(ProcessData[8].monitor);
  if ((monitor_high & 0x80000000) == 0)
  {
    id = (*a)->work->id;
    itfMesMngSetVar(monitor_high, 0, id, 1);
  }
  p_MainProcessID = &(*a)->data->MainProcessID;
  dds3LinkProcess(p_MainProcessID, &started);
  (*a)->data->AiScriptProcessID = started;
}
