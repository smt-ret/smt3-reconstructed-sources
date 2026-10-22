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
  Write("********* AAAA ********\n", 0);
}

// 0x15a6bf0
void itfDebugMesMngInitialize(void) {
  Il2CppObject *v1;
  u64 *v2;
  System_Byte_array *script_scr;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 monitor_high;
  u64 *v13;
  u64 *v15;
  u64 *v16;
  char *v17;
  s64 *v18;
  dds3ProcessID_t_o *v19[3];
  dds3ProcessID_t_o *id;

  id = 0;
  v1 = Allocate(dds3ProcessID_t);
  v1[1].klass = NewSpecific(byte, 0x18u);
  _ctor(v1, 0);
  id = v1;
  v2 = Allocate(scrHandle_t);
  scrHandle_t___ctor(v2);
  dds3BackColor = -2130706433;
  SwitchTexture();
  id = scrStartScript2(1000, script_scr, 0);
  ProcessData = dds3GetProcessData(&id);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != scrHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, scrHandle_t, v19);
    if ((v19[0] & 1) != 0)
      v17 = v19[2];
    else
      v17 = v19 + 1;
    v18 = sub_8C4940(v17);
  }
  monitor_high = HIDWORD(ProcessData[8].monitor);
  v13 = Allocate(instanceMes_tag_func_kutiDelegate);
  _ctor(v13, 0, Method_itfTestMesManager_functest__, 0);
  itfMesMngSetKutiCallback(monitor_high, v13);
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_itfTestMesManager_itfMesMngTestCalc__);
  dds3StartProcess("TestMsgMngC", 0x3EFu, 0, 0, v15, 0, 0, 0, 0, 0);
  v16 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v16,
    0,
    Method_itfTestMesManager_itfMesMngTestDraw__);
  dds3StartProcess("TestMsgMngD", 0x2AFEu, 0, 0, v16, 0, 0, 0, 0, 0);
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
  Il2CppObject *v4;
  Il2CppClass *element_class;
  s32 *v7;
  Il2CppObject *v8;
  sdfDrawTag_t_o *v10;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  char *v22;
  s64 *v23;
  u64 v24[2];
  char *v25;

  else
  {
    if (!g_texhandle)
      return 0;
  }
  else if (g_pic == 3)
  {
    return 0;
  }
  v4 = Allocate(sdfDrawTag_t);
  v4[4].klass = NewSpecific(object, 2u);
  _ctor(v4, 0);
  element_class = v4->klass->_1.element_class;
  {
    sub_8FC2C0(element_class, s32, v24);
    if ((v24[0] & 1) != 0)
      v22 = v25;
    else
      v22 = v24 + 1;
    v23 = sub_8C4940(v22);
  }
  v7 = sub_8D3F90(v4);
  v8 = sdfGrAllocPacketBuff(*v7);
  v10 = v8;
  if (v8)
  {
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, v24);
      if ((v24[0] & 1) != 0)
        v13 = v25;
      else
        v13 = v24 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  sdfDrawTagInit(v10);
  itfMiscDrawAlphaPrim(v10, 0, 0);
  itfMiscDrawSpritePrim(itfMesMngTestDraw_pos, itfMesMngTestDraw_uv, itfMesMngTestDraw_color, 0xFFFu, g_texhandle, 0, v10);
  return 0;
}

// 0x15a66a0
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b) {
  return 0;
}
