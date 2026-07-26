#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

static s32 base;
static s32 x;
static s32 y;
static void *strbuf;

bool DDS3_PAD2CHECK_REP(s32 id);
char *ToZenkaku(char *istr);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x1352630
dds3ProcessFunc_t *dds3BitEditorProcess(dds3ProcessID_t *id) {
    sdfDrawTagInit(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    evtBitCheck(0);
    ToZenkaku(0);
    sdfDrawTagLinkOt(0, 0);
    DDS3_PAD2CHECK_REP(0);
    dds3SelectMenu(0, 0, 0, 0, 0, 0, 0, 0, 0);
    evtBitOff(0);
    evtBitOn(0);
    return 0;
}
