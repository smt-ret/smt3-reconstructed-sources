#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbDebugMode pbDebugMode;
typedef struct pb_debug_tag pb_debug_tag;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static char *DebugProcMenu_pstr_menu[4];
static pb_debug_tag *g_pdebug;

bool DDS3_PAD2CHECK_PRESS(s32 id);
bool DDS3_PAD2CHECK_REP(s32 id);
bool DDS3_PAD2CHECK_TRIG(s32 id);
void InitializeDebug(void);
void ReleaseDebug(void);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
void pbGetCameraParam(sdfVector4_t out);
void pbGotoNewStage(void);
void pbLoadSystemData(s32 num);
void pbRoundStageNext(s16 plevel, s16 pstage);
void pbRoundStagePrev(s16 plevel, s16 pstage);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x1643580
s32 DebugProcDegree(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
    pbGetCameraParam((sdfVector4_t){0});
    DDS3_PAD2CHECK_TRIG(0);
    DDS3_PAD2CHECK_PRESS(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x16445b0
s32 DebugProcFree(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
    DDS3_PAD2CHECK_REP(0);
    DDS3_PAD2CHECK_TRIG(0);
    pbLoadSystemData(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x1642b30
s32 DebugProcMenu(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
    DDS3_PAD2CHECK_REP(0);
    DDS3_PAD2CHECK_TRIG(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x1642fe0
s32 DebugProcRadius(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
    pbGetCameraParam((sdfVector4_t){0});
    DDS3_PAD2CHECK_TRIG(0);
    DDS3_PAD2CHECK_PRESS(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x1643b40
s32 DebugProcStage(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
    DDS3_PAD2CHECK_REP(0);
    pbRoundStagePrev(0, 0);
    pbRoundStageNext(0, 0);
    DDS3_PAD2CHECK_TRIG(0);
    pbGotoNewStage();
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x1642980
void InitializeDebug(void) {
  u64 *v1;
  u64 *v2;
  u64 *v3;

  v1 = Allocate(pb_debug_tag);
  _ctor(v1, 0);
  v2 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v2);
  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  *(v1 + 6) = 0;
  *(v1 + 14) = 0;
  *(v1 + 15) = pbWk->level;
  *(v1 + 16) = pbWk->stage;
  g_pdebug = v1;
}

// 0x1642960
sdfMemHandle_t *MemHandleCopyFrom(sdfMemHandle_t *a) {
  return 0;
}

// 0x1642950
s32 PdebugCopyFrom(sdfMemHandle_t *a) {
  return 0;
}

// 0x1642a80
void ReleaseDebug(void) {
  u64 *v1;
  pbDebugMode_c *v3;
  struct pbDebugMode_StaticFields *static_fields;

  v1 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v1);
  static_fields = v3->static_fields;
  if (static_fields->g_pdebug)
  {
    static_fields->g_pdebug = 0;
  }
}

// 0x1644870
dds3ProcessFunc_t *pbDebugProc(dds3ProcessID_t *proc_id) {
  u64 *v3;
  s64 *v4;
  s64 v5;
  s64 *v6;
  s64 *v8;
  s64 v9;
  s64 *v10;
  s64 *v12;
  s64 v13;
  s64 *v14;
  s64 *v16;
  s64 v17;
  s64 *v18;
  s64 *v20;
  s64 v21;
  s64 *v22;
  u64 *v24;
  u64 v26;
  u64 *v32;
  pb_debug_tag_o *g_pdebug;
  struct sdfGrOt_t_array *dds3Ot;

  v3 = NewSpecific(pbDebugMode_funcDelegate, 5u);
  v4 = Allocate(pbDebugMode_funcDelegate);
  v5 = Method_pbDebugMode_DebugProcMenu__;
  v6 = v4;
  v4[2] = *Method_pbDebugMode_DebugProcMenu__;
  v4[4] = 0;
  v4[5] = v5;
  v3[4] = v6;
  v8 = Allocate(pbDebugMode_funcDelegate);
  v9 = Method_pbDebugMode_DebugProcRadius__;
  v10 = v8;
  v8[2] = *Method_pbDebugMode_DebugProcRadius__;
  v8[4] = 0;
  v8[5] = v9;
  v3[5] = v10;
  v12 = Allocate(pbDebugMode_funcDelegate);
  v13 = Method_pbDebugMode_DebugProcDegree__;
  v14 = v12;
  v12[2] = *Method_pbDebugMode_DebugProcDegree__;
  v12[4] = 0;
  v12[5] = v13;
  v3[6] = v14;
  v16 = Allocate(pbDebugMode_funcDelegate);
  v17 = Method_pbDebugMode_DebugProcStage__;
  v18 = v16;
  v16[2] = *Method_pbDebugMode_DebugProcStage__;
  v16[4] = 0;
  v16[5] = v17;
  v3[7] = v18;
  v20 = Allocate(pbDebugMode_funcDelegate);
  v21 = Method_pbDebugMode_DebugProcFree__;
  v22 = v20;
  v20[2] = *Method_pbDebugMode_DebugProcFree__;
  v20[4] = 0;
  v20[5] = v21;
  v3[8] = v22;
  v24 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v24);
  else  if ((*(v26 + 295) & 2) != 0 && !*(v26 + 216))
  InitializeDebug(v26);
  v32 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v32);
  sdfDrawTagInit(v32);
  Invoke(v3[g_pdebug->phase + 4], g_pdebug, v32);
  sdfDrawTagLinkOt(dds3Ot->m_Items[81], v32);
  proc_id->func_ans = -1;
  return 0;
}

// 0x16452b0
void *pbDebugShutdown(dds3ProcessID_t *proc_id) {
  ReleaseDebug();
  return 0;
}

// 0x1642970
s32 sai(pbDebugMode *a, pbDebugMode *b, pbDebugMode *c, pbDebugMode *d, pbDebugMode *e) {
  return 0;
}
