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
  struct System_Int32_array *SoundType;
  s64 SPIndex;
  System_String_o **v7;
  System_String_o *v9;
  struct System_String_array *SoundList;
  s64 v13;
  s64 v15;
  struct System_String_array *PatternList;
  s64 SPType;
  System_String_o *v19;
  Il2CppObject *v21;
  Il2CppObject *object;
  struct System_Int32_array *v27;
  s64 v28;

  if (SoundType->m_Items[SPIndex])
    v7 = &"Se/";
  else
    v7 = &"Bgm/";
  v9 = Concat_5224608("Sounds/", *v7);
  v13 = SPIndex;
  v15 = SoundList + 8 * v13;
  v19 = Concat_5271136(v9, *(v15 + 32), "_", PatternList->m_Items[SPType], 0);
  v21 = Concat_5224608("Load PlayData : ", v19);
  Log(v21, 0);
  object = Load_object_(v19);
  if (!op_Equality(object, 0, 0))
  {
    set_clip(audio_source, object);
    v27 = SoundType;
    v28 = SPIndex;
    set_loop(audio_source, v27->m_Items[v28] == 0);
    Play_8758880(audio_source);
  }
}

// 0x168d930
void ReleaseSound(char *key) {
  ;
}

// 0x168db60
void *SndPtnTestProcess(dds3ProcessID_t *id) {
  u64 *v3;
  s16 v7;
  s32 v8;
  s32 v10;
  struct System_String_array *SoundList;
  s64 SPIndex;
  System_String_o *v14;
  System_Object_array *v16;
  Il2CppObject *v18;
  s32 v21;
  struct System_String_array *PatternList;
  s64 SPType;
  System_String_o *v25;
  System_Object_array *v27;
  Il2CppObject *v29;
  System_Object_array *v30;
  Il2CppObject *v31;
  System_Object_array *v32;
  Il2CppObject *v33;
  System_Object_array *v34;
  Il2CppObject *v35;
  System_Object_array *v36;
  Il2CppObject *v37;
  System_Object_array *v38;
  Il2CppObject *v39;
  struct sdfGrOt_t_array *dds3Ot;
  s32 v51;
  s32 v53;
  struct System_Int32_array *SoundType;
  s64 v56;
  s32 v60;
  struct System_Int32_array *v62;
  s64 v63;
  s32 max_length;
  sndManager_c *v69;
  s32 v70;
  struct System_Int32_array *v72;
  s64 v73;
  s32 v76;
  s32 v78;
  struct System_Int32_array *v81;
  s64 v82;
  s32 v86;
  s32 v89;

  v3 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v3);
  sdfDrawTagInit(v3);
  dds3ConsPanelTagLink(v3, 132, 84, 21, 10);
  if ((v7 & 0x200) != 0)
  {
    v8 = v7 & 0x200;
  }
  else
  {
    v8 = 0;
  }
  if (cursor)
    v10 = 0;
  else
    v10 = 6;
  v14 = Format("SoundData : {0} ", SoundList->m_Items[SPIndex], 0);
  v16 = Empty_string_();
  v18 = sdfDevPrintf(30784, 31648, 0xFEFFFFu, v10, v14, v16);
  sdfDrawTagLink(v3, v18);
  if (cursor == 1)
    v21 = 6;
  else
    v21 = 0;
  v25 = Format("Pattern : {0} ", PatternList->m_Items[SPType], 0);
  v27 = Empty_string_();
  v29 = sdfDevPrintf(30784, 31936, 0xFEFFFFu, v21, v25, v27);
  sdfDrawTagLink(v3, v29);
  v30 = Empty_string_();
  v31 = sdfDevPrintf(30976, 32224, 0xFEFFFFu, 0, "U, D  = Category Change", v30, 0);
  sdfDrawTagLink(v3, v31);
  v32 = Empty_string_();
  v33 = sdfDevPrintf(30976, 32416, 0xFEFFFFu, 0, "L, R = Data Select", v32, 0);
  sdfDrawTagLink(v3, v33);
  v34 = Empty_string_();
  v35 = sdfDevPrintf(30976, 32608, 0xFEFFFFu, 0, "A or 〇   = Play", v34);
  sdfDrawTagLink(v3, v35);
  v36 = Empty_string_();
  v37 = sdfDevPrintf(30976, 32800, 0xFEFFFFu, 0, "B or ×   = Stop", v36);
  sdfDrawTagLink(v3, v37);
  v38 = Empty_string_();
  v39 = sdfDevPrintf(30976, 32992, 0xFEFFFFu, 0, "Y or □   = Exit", v38);
  sdfDrawTagLink(v3, v39);
  sdfDrawTagLinkOt(dds3Ot->m_Items[81], v3);
  else if (!DDS3_PADCHECK_REP(7))
  {
    goto LABEL_51;
  }
  cursor = 1 - cursor;
LABEL_51:
  else if (!DDS3_PADCHECK_REP(6))
  {
    goto LABEL_58;
  }
  cursor = 1 - cursor;
LABEL_58:
  else if (!DDS3_PADCHECK_REP(4))
  {
    goto LABEL_116;
  }
  {
    else
    {
      if (cursor)
        goto LABEL_63;
    }
  }
  else
  {
    v51 = 0;
    if (cursor)
    {
LABEL_63:
      v53 = SPType;
      SPType = v53 - 1;
      if (v53 <= 0)
      {
        SPType = LODWORD(PatternList->max_length) - 1;
        v56 = SPIndex;
        if (!SoundType->m_Items[v56])
        {
          --SPType;
        }
      }
      if (get_isPlaying(audio_source, 0))
      {
        Stop(audio_source);
          goto LABEL_118;
        goto LABEL_117;
      }
LABEL_116:
        goto LABEL_118;
      goto LABEL_117;
    }
  }
  v60 = SPIndex;
  SPIndex = v60 - 1;
  if (v60 <= 0)
  {
    SPIndex = LODWORD(SoundList->max_length) - 1;
  }
  v62 = SoundType;
  v63 = SPIndex;
  if (v62->m_Items[v63])
    goto LABEL_116;
  max_length = PatternList->max_length;
  if (SPType != max_length - 1)
    goto LABEL_116;
  SPType = max_length - 2;
  {
LABEL_118:
    if (!DDS3_PADCHECK_REP(5))
      goto LABEL_175;
    goto LABEL_119;
  }
LABEL_117:
    goto LABEL_118;
  if (!DDS3_PADCHECK_REP(5))
    goto LABEL_175;
LABEL_119:
  {
    else
    {
      if (cursor)
        goto LABEL_121;
    }
  }
  else
  {
    v70 = 0;
    if (cursor)
    {
LABEL_121:
      v72 = SoundType;
      v73 = SPIndex;
      if (v72->m_Items[v73])
      {
        v76 = SPType + 1;
        SPType = v76;
        if (v76 >= SLODWORD(PatternList->max_length))
          goto LABEL_131;
      }
      else
      {
        v89 = SPType + 1;
        SPType = v89;
        if (v89 >= LODWORD(PatternList->max_length) - 1)
        {
LABEL_131:
          SPType = 0;
          if ((v69->_2.bitflags2 & 2) == 0)
            goto LABEL_170;
          goto LABEL_168;
        }
      }
      if ((v69->_2.bitflags2 & 2) == 0)
      {
LABEL_170:
        if (get_isPlaying(audio_source, 0))
        {
          Stop(audio_source);
        }
        goto LABEL_175;
      }
LABEL_168:
      goto LABEL_170;
    }
  }
  v78 = SPIndex + 1;
  SPIndex = v78;
  if (v78 >= SLODWORD(SoundList->max_length))
  {
    SPIndex = 0;
  }
  v81 = SoundType;
  v82 = SPIndex;
  if (v81->m_Items[v82])
    goto LABEL_175;
  v86 = PatternList->max_length;
  if (SPType != v86 - 1)
  {
LABEL_175:
      goto LABEL_177;
    goto LABEL_176;
  }
  SPType = v86 - 2;
  {
LABEL_177:
    if (DDS3_PADCHECK_TRIG(1))
      goto LABEL_178;
    goto LABEL_183;
  }
LABEL_176:
    goto LABEL_177;
  if (DDS3_PADCHECK_TRIG(1))
  {
LABEL_178:
    PlayData();
    return 0;
  }
LABEL_183:
  if (DDS3_PADCHECK_TRIG(3))
  {
    Stop(audio_source);
    set_clip(audio_source, 0);
  }
  if (DDS3_PADCHECK_TRIG(0))
    id->func_ans = -1;
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

  v5 = "/sound/";
  *aDstName = "/sound/";
  *aDstName = Concat_5224608(v5, aSrcName);
}

// 0x168d940
s32 sndGetNumOfReq(void) {
  return 0;
}

// 0x168d7e0
void sndInit(void) {
  else if (sndInitFlag)
  {
LABEL_6:
    else
    {
      p2sdSndStopAll();
    }
    return;
  }
  SoundManagerInit();
  LoadResideSE();
  sndInitFlag = 1;
  PublicPan = 4;
  PublicSE = 0;
  sndNowBgmNum = -1;
}

// 0x168daf0
void sndPtnTestShutDown(void) {
  dds3KillProcessName("SndPtnTest", 1);
}

// 0x168d950
void sndPtnTestStart(s32 no) {
  u64 *v3;
  u64 *v6;
  u64 *v7;

  dds3BackColor = -2130706433;
  v3 = Allocate(UnityEngine_GameObject);
  _ctor(v3, "SoundTestManager", 0);
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
  dds3StartProcess("SndPtnTest", 0x2AF9u, 1, 1, v6, 0, v7, 0, 0, 0);
}
