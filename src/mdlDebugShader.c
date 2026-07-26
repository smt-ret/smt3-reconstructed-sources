#include "types.h"

typedef struct bDrawText bDrawText;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mdlDebugShader_SN mdlDebugShader_SN;
typedef struct mdlDebugShader_SPOS mdlDebugShader_SPOS;

struct mdlDebugShader_SPOS {
    s32 value__;
};

struct mdlDebugShader_SN {
    s32 value__;
};

static s32 select_pos;
static s32 select_shader;
static char *shader_name[3];
static bDrawText bsetText;

bool DDS3_PAD2CHECK_REP(s32 id);
void PreBtlMenuObj(s32 idx);
void SetBtlMenuObj(s32 idx);
bDrawText btlDevPrintf(s32 aX, s32 aY, s32 aZ, s32 color, char *aStr, s32 f);
void btlDrawTagLink(bDrawText *setText, bDrawText dt, s32 idx);
void initBtlMenuObj(s32 x, s32 y, s32 w, s32 h, s32 idx);

// 0xdfc420
void *dds3ShaderEditorProcess(dds3ProcessID_t *aId) {
    initBtlMenuObj(0, 0, 0, 0, 0);
    PreBtlMenuObj(0);
    DDS3_PAD2CHECK_REP(0);
    btlDevPrintf(0, 0, 0, 0, 0, 0);
    btlDrawTagLink(0, (bDrawText){0}, 0);
    SetBtlMenuObj(0);
    return 0;
}
