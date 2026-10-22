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
  f32 v12;
  f32 v14;
  f32 v15;
  System_Object_array *v22;
  Il2CppObject *v24;
  System_Object_array *v25;
  s32 v26;
  s64 *v27;
  s64 *v28;
  Il2CppObject *v30;
  u64 v33[2];
  s32 v34;
  UnityEngine_Vector4_o v35;

  v33[0] = 0;
  v33[1] = 0;
  v35.x = 0.0;
  v35.y = 0.0;
  v35.z = 0.0;
  v35.w = 0.0;
  pbGetCameraParam(v35);
  if (DDS3_PAD2CHECK_TRIG(3))
LABEL_9:
    pdebug->phase = 0;
LABEL_10:
  else if (DDS3_PAD2CHECK_PRESS(6))
  {
    goto LABEL_29;
  }
  if (DDS3_PAD2CHECK_PRESS(4))
    goto LABEL_29;
LABEL_16:
  else if (DDS3_PAD2CHECK_PRESS(7))
  {
    goto LABEL_32;
  }
  if (DDS3_PAD2CHECK_PRESS(5))
  {
LABEL_32:
    sub_854710(v33, 2u);
    sub_854930(v33, 2u);
    sub_854710(v33, 2u);
    if (v12 >= 0.0)
    {
LABEL_34:
      sub_854710(v33, 2u);
      v15 = v14;
      else if ((byte_3F5A27F & 1) != 0)
      {
        goto LABEL_38;
      }
      goto LABEL_38;
    }
LABEL_33:
    sub_854930(v33, 2u);
    goto LABEL_34;
  }
LABEL_47:
  dds3ConsPanelTagLink(pdrawtag, 16, 16, 24, 4);
  v22 = Empty_string_();
  v24 = sdfDevPrintf(29056, 31232, 0xFFFFF0u, 0, "CAMERA DEGREE (RADIAN)", v22, 0);
  sdfDrawTagLink(pdrawtag, v24);
  v25 = NewSpecific(object, 1u);
  sub_854710(v33, 2u);
  v34 = v26;
  v27 = sub_8D3950(f32, &v34);
  v28 = v27;
  v25->m_Items[0] = v28;
  v30 = sdfDevPrintf(31104, 31328, 0xFFFFF0u, 0, "%f", v25);
  sdfDrawTagLink(pdrawtag, v30);
  return 0;
}

// 0x16445b0
s32 DebugProcFree(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
  s16 v6;
  s16 systemfileNum;
  s16 v9;
  s32 v12;
  System_Object_array *v13;
  System_Object_array *v14;
  s64 *v15;
  s64 *v17;
  Il2CppObject *v20;
  s16 v23;

  else if (!DDS3_PAD2CHECK_REP(6))
  {
    goto LABEL_9;
  }
  v6 = pdebug->systemfileNum - 1;
  if (v6 < 0)
    v6 = 49;
  pdebug->systemfileNum = v6;
LABEL_9:
  else if (!DDS3_PAD2CHECK_REP(7))
  {
    goto LABEL_16;
  }
  systemfileNum = pdebug->systemfileNum;
  if ((systemfileNum + 1) <= 49)
    v9 = systemfileNum + 1;
  else
    v9 = 0;
  pdebug->systemfileNum = v9;
LABEL_16:
  else if (DDS3_PAD2CHECK_TRIG(3))
  {
LABEL_19:
    pdebug->phase = 0;
    goto LABEL_33;
  }
  if (DDS3_PAD2CHECK_TRIG(1))
  {
    v12 = pdebug->systemfileNum;
    pbLoadSystemData(v12);
  }
LABEL_33:
  dds3ConsPanelTagLink(pdrawtag, 16, 16, 24, 3);
  v13 = NewSpecific(object, 1u);
  v23 = pdebug->systemfileNum;
  v14 = v13;
  v15 = sub_8D3950(s16, &v23);
  v17 = v15;
  v14->m_Items[0] = v17;
  v20 = sdfDevPrintf(29056, 31232, 0xFFFFF0u, 0, "DATA SELECT : %2d", v14);
  sdfDrawTagLink(pdrawtag, v20);
  return 0;
}

// 0x1642b30
s32 DebugProcMenu(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
  s16 *p_menu_cursor;
  s16 v7;
  s16 menu_cursor;
  s16 v11;
  struct System_String_array *DebugProcMenu_pstr_menu;
  System_String_o *v15;
  System_Object_array *v17;
  Il2CppObject *v19;
  struct System_String_array *v22;
  System_String_o *v24;
  System_Object_array *v26;
  Il2CppObject *v28;
  struct System_String_array *v31;
  System_String_o *v33;
  System_Object_array *v35;
  Il2CppObject *v37;
  s32 v38;
  System_Object_array *v40;
  Il2CppObject *v42;

  else if (DDS3_PAD2CHECK_REP(6))
  {
    goto LABEL_6;
  }
  if (DDS3_PAD2CHECK_REP(7))
  {
    p_menu_cursor = &pdebug->menu_cursor;
    menu_cursor = pdebug->menu_cursor;
    if ((menu_cursor + 1) < 3)
      v7 = menu_cursor + 1;
    else
      v7 = 0;
LABEL_16:
    *p_menu_cursor = v7;
  }
  else if (DDS3_PAD2CHECK_TRIG(3))
  {
    return 1;
  }
  if (DDS3_PAD2CHECK_TRIG(1))
  {
    switch (pdebug->menu_cursor)
    {
      case 0:
        v11 = 1;
        goto LABEL_31;
      case 1:
        v11 = 2;
        goto LABEL_31;
      case 2:
        v11 = 3;
        goto LABEL_31;
      case 3:
        v11 = 4;
LABEL_31:
        pdebug->phase = v11;
        break;
      default:
        break;
    }
  }
  dds3ConsPanelTagLink(pdrawtag, 16, 16, 24, 6);
  else
  {
    if (!LODWORD(DebugProcMenu_pstr_menu->max_length))
      goto LABEL_35;
  }
  v15 = DebugProcMenu_pstr_menu->m_Items[0];
  v17 = Empty_string_();
  v19 = sdfDevPrintf(29568, 31232, 0xFFFFF0u, 0, v15, v17);
  sdfDrawTagLink(pdrawtag, v19);
  v22 = DebugProcMenu_pstr_menu;
  v24 = v22->m_Items[1];
  v26 = Empty_string_();
  v28 = sdfDevPrintf(29568, 31328, 0xFFFFF0u, 0, v24, v26);
  sdfDrawTagLink(pdrawtag, v28);
  v31 = DebugProcMenu_pstr_menu;
  v33 = v31->m_Items[2];
  v35 = Empty_string_();
  v37 = sdfDevPrintf(29568, 31424, 0xFFFFF0u, 0, v33, v35);
  sdfDrawTagLink(pdrawtag, v37);
  v38 = pdebug->menu_cursor;
  v40 = Empty_string_();
  v42 = sdfDevPrintf(29056, 96 * v38 + 31232, 0xFFFFF0u, 0, ">", v40);
  sdfDrawTagLink(pdrawtag, v42);
  return 0;
}

// 0x1642fe0
s32 DebugProcRadius(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
  System_Object_array *v17;
  Il2CppObject *v19;
  System_Object_array *v20;
  s32 v21;
  s64 *v22;
  s64 *v23;
  Il2CppObject *v25;
  f32 v28;
  u64 v29[2];
  s32 v30;
  UnityEngine_Vector4_o v31;

  v29[0] = 0;
  v29[1] = 0;
  v31.x = 0.0;
  v31.y = 0.0;
  v31.z = 0.0;
  v31.w = 0.0;
  pbGetCameraParam(v31);
  if (DDS3_PAD2CHECK_TRIG(3))
LABEL_9:
    pdebug->phase = 0;
LABEL_10:
  else if (DDS3_PAD2CHECK_PRESS(6))
  {
    goto LABEL_29;
  }
  if (DDS3_PAD2CHECK_PRESS(4))
    goto LABEL_29;
LABEL_16:
  else if (DDS3_PAD2CHECK_PRESS(7))
  {
    goto LABEL_54;
  }
  if (DDS3_PAD2CHECK_PRESS(5))
  {
LABEL_54:
    sub_854710(v29, 1u);
    sub_854930(v29, 1u);
    sub_854710(v29, 1u);
    if (v28 <= 1500.0)
      goto LABEL_31;
    goto LABEL_30;
  }
LABEL_39:
  dds3ConsPanelTagLink(pdrawtag, 16, 16, 24, 4);
  v17 = Empty_string_();
  v19 = sdfDevPrintf(29056, 31232, 0xFFFFF0u, 0, "CAMERA RADIUS (LENGTH)", v17, 0);
  sdfDrawTagLink(pdrawtag, v19);
  v20 = NewSpecific(object, 1u);
  sub_854710(v29, 1u);
  v30 = v21;
  v22 = sub_8D3950(f32, &v30);
  v23 = v22;
  v20->m_Items[0] = v23;
  v25 = sdfDevPrintf(31104, 31328, 0xFFFFF0u, 0, "%f", v20);
  sdfDrawTagLink(pdrawtag, v25);
  return 0;
}

// 0x1643b40
s32 DebugProcStage(pb_debug_tag *pdebug, sdfDrawTag_t *pdrawtag) {
  s16 d_level;
  s16 d_stage;
  s16 v11;
  s16 v12;
  System_Object_array *v17;
  System_Object_array *v18;
  s64 *v19;
  s64 *v20;
  s64 *v22;
  s64 *v24;
  Il2CppObject *v27;
  s32 v31;
  s32 v32;

  else if (!DDS3_PAD2CHECK_REP(6))
  {
    goto LABEL_10;
  }
  d_level = pdebug->d_level;
  d_stage = pdebug->d_stage;
  pbRoundStagePrev(d_level, d_stage);
LABEL_10:
  else if (!DDS3_PAD2CHECK_REP(7))
  {
    goto LABEL_17;
  }
  v11 = pdebug->d_level;
  v12 = pdebug->d_stage;
  pbRoundStageNext(v11, v12);
LABEL_17:
  else if (DDS3_PAD2CHECK_TRIG(3))
  {
LABEL_20:
    pdebug->phase = 0;
    goto LABEL_37;
  }
  if (DDS3_PAD2CHECK_TRIG(1))
  {
    pbWk->level = pdebug->d_level;
    pbWk->stage = pdebug->d_stage;
    pbGotoNewStage();
  }
LABEL_37:
  dds3ConsPanelTagLink(pdrawtag, 16, 16, 24, 3);
  v17 = NewSpecific(object, 2u);
  v32 = pdebug->d_level + 1;
  v18 = v17;
  v19 = sub_8D3950(s32, &v32);
  v20 = v19;
  v18->m_Items[0] = v20;
  v31 = pdebug->d_stage + 1;
  v22 = sub_8D3950(s32, &v31);
  v24 = v22;
  v18->m_Items[1] = v24;
  v27 = sdfDevPrintf(29056, 31232, 0xFFFFF0u, 0, "STAGE : %d -%2d", v18);
  sdfDrawTagLink(pdrawtag, v27);
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

  v1 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v1);
  if (g_pdebug)
  {
    g_pdebug = 0;
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
  else if (g_pdebug)
  {
    goto LABEL_36;
  }
  InitializeDebug(v26);
LABEL_36:
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
