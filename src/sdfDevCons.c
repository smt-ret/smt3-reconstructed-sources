#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct sdfDevConsCB_tag sdfDevConsCB_tag;
typedef struct sdfDevConsDrawCB_t sdfDevConsDrawCB_t;
typedef struct sdfDevPrintCB_t sdfDevPrintCB_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static sdfDevConsCB_tag *devConsTop;
static s32 alreadyInitDevCons;
static sdfTexHandle_t *sdfDebugFontHandle;
static s32 devConsSemaId;
static u32 sdfDevConsColorTable[15];

static s32 alreadyInitDevCons;
static s32 devConsID;
static s32 devConsSemaId;

void Draw(s32 x, s32 y, _FRQ *frq, s32 colno);
void sdfDevSetPrintCB(sdfDevPrintCB_t *aCB, s32 aX, s32 aY, u32 aZ, s32 aAttr);
void *sdfDevVprintf(sdfDevPrintCB_t *aCB, char *aStr, void **LegacyParamArray);

// 0x17e5730
void sdfDevConsClearInside(sdfDevConsCB_tag *aHndl) {
  *&aHndl->locX = 0;
}

// 0x17e59b0
void sdfDevConsDrawAll(void) {
  ;
}

// 0x17e5920
void sdfDevConsDrawBG(sdfDevConsCB_tag *aHndl, sdfDevConsDrawCB_t *aCB) {

}

// 0x17e5910
void sdfDevConsDrawFlush(sdfDevConsDrawCB_t *aCB) {
  ;
}

// 0x17e59a0
void sdfDevConsDrawInit(sdfDevConsDrawCB_t *aCB, void *aPacketBuffer, s32 aBufferSize) {
  ;
}

// 0x17e5370
sdfTexHandle_t *sdfDevConsGetFontHandle(void) {
  struct sdfDevCons_StaticFields *static_fields;
  struct sdfDevCons_StaticFields **p_static_fields;

  else
  {
    p_static_fields = &sdfDevCons->static_fields;
    static_fields = sdfDevCons->static_fields;
    if (static_fields->alreadyInitDevCons)
      return static_fields->sdfDebugFontHandle;
  }
  static_fields->alreadyInitDevCons = 1;
  return (*p_static_fields)->sdfDebugFontHandle;
}

// 0x17e5480
u32 sdfDevConsGetFontUvTable(void) {
  return 0;
}

// 0x17e5f40
s32 sdfDevConsGetID(void) {
  return devConsID;
}

// 0x17e58e0
s32 sdfDevConsGetMode(sdfDevConsCB_tag *aHndl) {
  return aHndl->mode;
}

// 0x17e52c0
void sdfDevConsInit(void) {
  struct sdfDevCons_StaticFields *static_fields;

  else
  {
    static_fields = sdfDevCons->static_fields;
    if (static_fields->alreadyInitDevCons)
      return;
  }
  static_fields->alreadyInitDevCons = 1;
}

// 0x17e5490
void sdfDevConsLinkToTop(sdfDevConsCB_tag *aHndl) {
  struct sdfDevConsCB_tag_o *devConsTop;

  aHndl->prev = 0;
  aHndl->next = devConsTop;
  if (devConsTop)
  {
    devConsTop->prev = aHndl;
  }
  devConsTop = aHndl;
}

// 0x17e5800
void sdfDevConsNewLine(sdfDevConsCB_tag *aHndl) {
  s32 locY;

  locY = aHndl->locY;
  if (aHndl->h - 1 != locY)
    aHndl->locY = locY + 1;
  aHndl->locX = 0;
}

// 0x17e5830
void sdfDevConsPutInside(sdfDevConsCB_tag *aHndl, s32 aChar, s32 aAttr) {
  ;
}

// 0x17e58f0
void sdfDevConsSetMode(sdfDevConsCB_tag *aHndl, s32 aMode) {
  aHndl->mode = aMode;
}

// 0x17e5900
void sdfDevConsTagClose(sdfDevConsDrawCB_t *aCB) {
  ;
}

// 0x17e5550
void sdfDevConsUnlink(sdfDevConsCB_tag *aHndl) {
  Il2CppObject *v3;
  u64 *v4;
  Il2CppObject *v5;
  u64 *v6;
  struct sdfDevConsCB_tag_o *next;
  struct sdfDevConsCB_tag_o *prev;

  v3 = Allocate(sdfDevConsCB_tag);
  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  v3[3].klass = v4;
  _ctor(v3, 0);
  v5 = Allocate(sdfDevConsCB_tag);
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v5[3].klass = v6;
  _ctor(v5, 0);
  prev = aHndl->prev;
  next = aHndl->next;
  if (prev)
  {
    prev->next = next;
    if (!next)
      return;
  }
  devConsTop = next;
  if (next)
    next->prev = prev;
}

// 0x17e58d0
void sdfDevCons__sdfDevConsAttribute(sdfDevConsCB_tag *aHndl, s32 aAttr) {
  aHndl->attr = aAttr;
}

// 0x17e5740
void sdfDevCons__sdfDevConsClear(sdfDevConsCB_tag *aHndl) {
  ;
}

// 0x17e5720
void sdfDevCons__sdfDevConsClose(sdfDevConsCB_tag *aHndl) {
  ;
}

// 0x17e5990
void sdfDevCons__sdfDevConsDraw(sdfDevConsCB_tag *aHndl, sdfDevConsDrawCB_t *aCB) {
  ;
}

// 0x17e58c0
void sdfDevCons__sdfDevConsLocate(sdfDevConsCB_tag *aHndl, s32 aLocX, s32 aLocY) {
  aHndl->locX = aLocX;
  aHndl->locY = aLocY;
}

// 0x17e5750
sdfDevConsCB_tag *sdfDevCons__sdfDevConsOpen(s32 aOfsX, s32 aOfsY, s32 aWidth, s32 aHeight) {
  Il2CppObject *v5;
  u64 *v6;

  v5 = Allocate(sdfDevConsCB_tag);
  v6 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v6);
  v5[3].klass = v6;
  _ctor(v5, 0);
  return v5;
}

// 0x17e5850
s32 sdfDevCons__sdfDevConsPrintf(sdfDevConsCB_tag *aHndl, char *aStr, void **LegacyParamArray) {
  System_Char_array *v4;

  v4 = NewSpecific(char, 0x200u);
  CreateString_5280336(0, v4);
  return 0;
}

// 0x17e5840
void sdfDevCons__sdfDevConsPut(sdfDevConsCB_tag *aHndl, s32 aChar, s32 aAttr) {
  ;
}

// 0x17e6360
void sdfDevCons_old__sdfDevConsAttribute(s32 aAttr) {

}

// 0x17e6170
void sdfDevCons_old__sdfDevConsClear(void) {

}

// 0x17e5fb0
void sdfDevCons_old__sdfDevConsClose(void) {
  sdfDevCons_old_c *v2;
  struct sdfDevCons_old_StaticFields *static_fields;

  static_fields = v2->static_fields;
  if (static_fields->devConsID != -1)
  {
    static_fields->devConsID = -1;
  }
}

// 0x17e63d0
void sdfDevCons_old__sdfDevConsDraw(void) {

}

// 0x17e62f0
void sdfDevCons_old__sdfDevConsLocate(s32 aLocX, s32 aLocY) {

}

// 0x17e6050
void sdfDevCons_old__sdfDevConsOpen(s32 aOfsX, s32 aOfsY, s32 aWidth, s32 aHeight) {
  sdfDevCons_old_c *v5;
  struct sdfDevCons_old_StaticFields *static_fields;

  static_fields = v5->static_fields;
  if (static_fields->devConsID != -1)
  {
    static_fields->devConsID = -1;
    static_fields = sdfDevCons_old->static_fields;
  }
  if (!static_fields->alreadyInitDevCons)
  {
    static_fields->alreadyInitDevCons = 1;
  }
}

// 0x17e6250
s32 sdfDevCons_old__sdfDevConsPrintf(char *aStr, void **LegacyParamArray) {
  System_Char_array *v3;

  v3 = NewSpecific(char, 0x200u);
  CreateString_5280336(0, v3);
    return 0;
  return 0;
}

// 0x17e61e0
void sdfDevCons_old__sdfDevConsPut(s32 aChar, s32 aAttr) {

}

// 0x17e5b20
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray) {
  u64 *v13;

  v13 = Allocate(sdfDevPrintCB_t);
  sdfDevPrintCB_t___ctor(v13);
  sdfDevSetPrintCB(v13, aX, aY, aZ, aAttr);
  sdfDevVprintf(v13, aStr, LegacyParamArray);
  return 0;
}

// 0x17e5b10
void *sdfDevPrintfEx(sdfDevPrintCB_t *aCB, char *aStr, void **LegacyParamArray) {
  return 0;
}

// 0x17e5d10
void sdfDevSetPrintAttr(sdfDevPrintCB_t *aCB, s32 aAttr) {
  struct System_UInt32_array *sdfDevConsColorTable;

  aCB->attr = sdfDevConsColorTable->m_Items[aAttr];
}

// 0x17e5c00
void sdfDevSetPrintCB(sdfDevPrintCB_t *aCB, s32 aX, s32 aY, u32 aZ, s32 aAttr) {
  struct System_UInt32_array *sdfDevConsColorTable;

  aCB->x = aX;
  aCB->y = aY;
  aCB->z = aZ;
  aCB->attr = sdfDevConsColorTable->m_Items[aAttr];
}

// 0x17e59c0
void *sdfDevVprintf(sdfDevPrintCB_t *aCB, char *aStr, void **LegacyParamArray) {
    Draw(0, 0, 0, 0);
    return 0;
}
