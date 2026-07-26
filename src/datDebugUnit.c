#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

static char *DispUnit1_bad[13];
static s32 kotowaricur;
static s32 kotowarimax;
static char *kotowari_str[8];

bool DDS3_PAD2CHECK_REP(s32 id);
void DispList(s32 x, s32 y, sdfDrawTag_t *tag);
void DispUnit1(s32 i, s32 x, s32 y, sdfDrawTag_t *tag);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0xcc97c0
void DispList(s32 x, s32 y, sdfDrawTag_t *tag) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0xcc9b90
void DispUnit1(s32 i, s32 x, s32 y, sdfDrawTag_t *tag) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0xcca6e0
dds3ProcessFunc_t *datDebugKotowariProcess(dds3ProcessID_t *id) {
    sdfDrawTagInit(0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
    dds3SelectMenu(0, 0, 0, 0, 0, 0, 0, 0, 0);
    DDS3_PAD2CHECK_REP(0);
    return 0;
}

// 0xcca480
dds3ProcessFunc_t *datDebugUnitProcess(dds3ProcessID_t *id) {
  u64 *v2;
  System_Object_array *v7;
  Il2CppObject *v8;
  s32 i;
  u64 *v12;
  struct sdfGrOt_t_array *dds3Ot;
  struct sdfGrOt_t_array *v18;

  v2 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v2);
  sdfDrawTagInit(v2);
  DispList(2, 10, v2);
  v7 = Empty_string_();
  v8 = sdfDevPrintf(29056, 32320, 0xFEFFFFu, 4, StringLiteral_12682, v7);
  sdfDrawTagLink(v2, v8);
  for (i = 0; i != 16; ++i)
  {
    DispUnit1(i, 2, i + 15, v2);
  }
  v12 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v12);
  sdfDrawTagInit(v12);
  dds3ConsPanelTagLink(v12, 24, 114, 37, 23);
  sdfDrawTagLinkOt(dds3Ot->m_Items[81], v12);
  v18 = dds3Ot;
  sdfDrawTagLinkOt(v18->m_Items[81], v2);
  return 0;
}
