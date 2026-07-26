#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

static s32 PublicPan;
static s32 PublicSE;
static bool sndInitFlag;
static s16 sndNowBgmNum;
static void *sound_test;
static void *audio_source;
static char *SoundList[6];
static s32 SoundType[6];
static char *PatternList[4];
static s32 SPIndex;
static s32 SPType;
static s32 cursor;

bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void LoadResideSE(void);
void PlayData(void);
void SoundManagerInit(void);
void StopBGM_ALL(void);
void StopSE_ALL(void);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void p2sdSndStopAll(void);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x168d920
void LoadSound(char *key, char *path) {
  ;
}

// 0x168e760
void PlayData(void) {
  sndManager_c *v2;
  struct sndManager_StaticFields *static_fields;
  struct System_Int32_array *SoundType;
  s64 SPIndex;
  System_String_o **v7;
  System_String_o *v9;
  sndManager_c *v10;
  struct sndManager_StaticFields *v11;
  struct System_String_array *SoundList;
  s64 v13;
  s64 v15;
  struct System_String_array *PatternList;
  s64 SPType;
  System_String_o *v19;
  Il2CppObject *v21;
  Il2CppObject *object;
  struct sndManager_StaticFields *v26;
  struct System_Int32_array *v27;
  s64 v28;

  static_fields = v2->static_fields;
  SoundType = static_fields->SoundType;
  SPIndex = static_fields->SPIndex;
  if (SoundType->m_Items[SPIndex])
    v7 = &StringLiteral_22137;
  else
    v7 = &StringLiteral_22138;
  v9 = Concat_5224608(StringLiteral_22136, *v7);
  v11 = v10->static_fields;
  SoundList = v11->SoundList;
  v13 = v11->SPIndex;
  v15 = SoundList + 8 * v13;
  PatternList = v11->PatternList;
  SPType = v11->SPType;
  v19 = Concat_5271136(v9, *(v15 + 32), StringLiteral_558, PatternList->m_Items[SPType], 0);
  v21 = Concat_5224608(StringLiteral_22139, v19);
  Log(v21, 0);
  object = Load_object_(v19);
  if (!op_Equality(object, 0, 0))
  {
    set_clip(audio_source, object);
    v26 = sndManager->static_fields;
    v27 = v26->SoundType;
    v28 = v26->SPIndex;
    set_loop(v26->audio_source, v27->m_Items[v28] == 0);
    Play_8758880(audio_source);
  }
}

// 0x168d930
void ReleaseSound(char *key) {
  ;
}

// 0x168db60
void *SndPtnTestProcess(dds3ProcessID_t *id) {
    sdfDrawTagInit(0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
    DDS3_PADCHECK_REP(0);
    DDS3_PADCHECK_TRIG(0);
    PlayData();
    return 0;
}

// 0x168ea10
void *SndPtnTestShutdown(dds3ProcessID_t *id) {
  UnityEngine_Object_o *sound_test;

  StopBGM_ALL();
  StopSE_ALL();
  DestroyImmediate_27360336(sound_test);
  sound_test = 0;
  id->func_ans = -1;
  return 0;
}

// 0x168d770
void sdfSndMakeFilename(char **aDstName, char *aSrcName) {
  System_String_o *v5;

  v5 = StringLiteral_22127;
  *aDstName = StringLiteral_22127;
  *aDstName = Concat_5224608(v5, aSrcName);
}

// 0x168d940
s32 sndGetNumOfReq(void) {
  return 0;
}

// 0x168d7e0
void sndInit(void) {
    p2sdSndStopAll();
    SoundManagerInit();
    LoadResideSE();
}

// 0x168daf0
void sndPtnTestShutDown(void) {
  dds3KillProcessName(StringLiteral_14941, 1);
}

// 0x168d950
void sndPtnTestStart(s32 no) {
  u64 *v3;
  u64 *v6;
  u64 *v7;

  dds3BackColor = -2130706433;
  v3 = Allocate(UnityEngine_GameObject);
  _ctor(v3, StringLiteral_22128, 0);
  sound_test = v3;
  audio_source = AddComponent_object_(sound_test);
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_sndManager_SndPtnTestProcess__);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_sndManager_SndPtnTestShutdown__);
  dds3StartProcess(StringLiteral_14941, 0x2AF9u, 1, 1, v6, 0, v7, 0, 0, 0);
}
