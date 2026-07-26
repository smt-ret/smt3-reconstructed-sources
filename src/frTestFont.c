#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct frTestFont frTestFont;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct frTestFont {
    sdfTexHandle_t *gTex;
    s32 HandleInit_x;
    s32 HandleInit_y;
    u8 HandleInit_alpha;
};

static _FRQ *gFRQ;

bool DDS3_PADCHECK_PRESS(s32 id);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s8 fclDestroyMessage(void);
sdfTexHandle_t *fclLoadTexture(char *pFileName);
_FRQ *frDestroyFontRequestNow(_FRQ *pFRQ);
_FRQ *frwGetFontEx(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, s8 ChangeStyle, s8 Mode, _FRQ *pFRQ, s32 ftype);
dds3ProcessID_t *scrStartScript3(s32 priority, char *filename, s32 startproc, char *akey);

// 0x13a4f40
void HandleInit(frTestFont *this) {
    frwGetFontEx(0, 0, 0, 0, 0, 0, 0, 0, 0);
    DDS3_PADCHECK_PRESS(0);
}

// 0x13a54b0
void frDrawFontUser(frTestFont *this, _FRQ *pFRQ) {
}

// 0x13a5390
void frTestFontDestroy(frTestFont *this, dds3ProcessID_t *id) {
  _FRQ_o *gFRQ;

  fclDestroyMessage();
  frDestroyFontRequestNow(gFRQ);
}

// 0x13a5230
void frTestFontInit(frTestFont *this) {
  u64 *v3;

  this->gTex = fclLoadTexture(StringLiteral_17015);
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    this,
    Method_frTestFont_frTestFontMain__);
  dds3StartProcess(StringLiteral_17016, 0x2EE0u, 0, 0, v3, 0, 0, 0, 0, 0);
  scrStartScript3(600, StringLiteral_17017, 0, StringLiteral_17018);
}

// 0x13a5730
dds3ProcessFunc_t *frTestFontMain(frTestFont *this, dds3ProcessID_t *id) {
  return 0;
}
