#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct instanceMes_tag_func_kutiDelegate instanceMes_tag_func_kutiDelegate;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 dds3Ot[1];
static u8 script_scr[717];
static s32 g_pic;
static sdfTexHandle_t *g_texhandle;
static char *SwitchTexture_pfilename[3];
static sdfIVector4_t *itfMesMngTestDraw_pos;
static sdfIVector4_t *itfMesMngTestDraw_uv;
static sdfIVector4_t *itfMesMngTestDraw_color;

bool DDS3_PADCHECK_TRIG(s32 id);
void SwitchTexture(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void itfMesMngSetKutiCallback(s32 id, instanceMes_tag_func_kutiDelegate *func);
void itfMiscDrawAlphaPrim(sdfDrawTag_t *pdrawtag, s32 tp, s32 context);
void itfMiscDrawSpritePrim(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, sdfTexHandle_t *texhandle, s32 context, sdfDrawTag_t *pdrawtag);
dds3ProcessID_t *scrStartScript2(s32 a, void *b, s32 c);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void *sdfGrAllocPacketBuff(s32 aSize);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);

// 0x15a6660
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix) {
  return a | (4 * b) | (16 * c) | fix | (d << 6);
}

// 0x15a6680
s32 SDF_GS_SET_TEST(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  return ate | (2 * atst) | (16 * aref) | (afail << 12) | (date << 14) | (datm << 15) | (zte << 16) | (ztst << 17);
}

// 0x15a66b0
void SwitchTexture(void) {
  sdfTexHandle_t_o *g_texhandle;

  if (g_texhandle)
  {
    sdfTexFreeDelayed(g_texhandle);
    g_texhandle = 0;
  }
  ++g_pic;
  g_pic &= 3u;
}

// 0x15a6b80
void functest(void) {
  Write(StringLiteral_17062, 0);
}

// 0x15a6bf0
void itfDebugMesMngInitialize(void) {
    SwitchTexture();
    scrStartScript2(0, 0, 0);
    dds3GetProcessData(0);
    itfMesMngSetKutiCallback(0, 0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
}

// 0x15a67b0
dds3ProcessFunc_t *itfMesMngTestCalc(dds3ProcessID_t *proc_id) {
  else if (!DDS3_PADCHECK_TRIG(0))
  {
    return 0;
  }
  SwitchTexture();
  return 0;
}

// 0x15a6860
dds3ProcessFunc_t *itfMesMngTestDraw(dds3ProcessID_t *proc_id) {
    sdfGrAllocPacketBuff(0);
    sdfDrawTagInit(0);
    itfMiscDrawAlphaPrim(0, 0, 0);
    itfMiscDrawSpritePrim(0, 0, 0, 0, 0, 0, 0);
    return 0;
}

// 0x15a66a0
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b) {
  return 0;
}
