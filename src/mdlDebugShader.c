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
  struct System_String_array *shader_name;
  s64 select_shader;
  struct System_String_array *v17;
  s64 v18;
  System_String_o *v20;
  bDrawText_o v22;

  initBtlMenuObj(1380, 0, 540, 720, 0);
  PreBtlMenuObj(0);
  else if (DDS3_PAD2CHECK_REP(6))
  {
    goto LABEL_53;
  }
  if (!DDS3_PAD2CHECK_REP(7))
  {
    else if (DDS3_PAD2CHECK_REP(4))
    {
      goto LABEL_16;
    }
    if (DDS3_PAD2CHECK_REP(5))
    {
      ++select_shader;
      if (select_shader < 3)
        goto LABEL_40;
      select_shader = 0;
      goto LABEL_39;
    }
    DDS3_PAD2CHECK_REP(1);
  }
LABEL_53:
  v17 = shader_name;
  v18 = select_shader;
  v20 = v17->m_Items[v18];
  v22 = btlDevPrintf(0, 0, 0, 0, v20, 0);
  btlDrawTagLink(&bsetText, v22, 0);
  SetBtlMenuObj(0);
  return 0;
}
