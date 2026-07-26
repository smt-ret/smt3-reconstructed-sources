#include "types.h"

typedef struct p2sdFileStream p2sdFileStream;
typedef struct p2sdIOPtoEEpkt p2sdIOPtoEEpkt;
typedef struct p2sdPosvect p2sdPosvect;
typedef struct p2sdSMGstatus p2sdSMGstatus;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfSndMap_t sdfSndMap_t;
typedef struct sdfSndSeqInfo_t sdfSndSeqInfo_t;
typedef struct sdfSndVoiceInfo_t sdfSndVoiceInfo_t;
typedef struct sdfSndVoiceMap_t sdfSndVoiceMap_t;
typedef struct sdfSound_AudioPlayList sdfSound_AudioPlayList;
typedef struct sdfSound_PlaySTAT sdfSound_PlaySTAT;
typedef struct sdfSound_p2sdWaitCallbackDelegate sdfSound_p2sdWaitCallbackDelegate;

struct sdfSound_AudioPlayList {
    void *Clip;
    u32 Status;
};

struct sdfSound_PlaySTAT {
    u32 value__;
};

static u16 sdfSndBurstReqMode;
static s32 *sdfSndCmdIFBuffer[32];
static s16 sdfSndCmdHeadIndex;
static s16 sdfSndCmdTailIndex;
static s32 sdfSndCmdIFThreadId;
static u16 sdfSndCmdIFThreadStack[4096];
static u16 IOPcheckThreadStack[4096];
static s32 IOPcheckThreadID;
static sdfSndMap_t *sdfSndMap;
static void *sdfSndMapIop;
static s32 LastLoad;
static p2sdFileStream *p2sdStream;
static void *p2sdStreamCallback;
static char *AdpcmFileName;
static s32 AdpcmPlaying;
static s32 MoviePlaying;
static sdfSound_AudioPlayList *PlayList[32];
static sdfSound_p2sdWaitCallbackDelegate *p2sdWaitCallback;
static s32 sdfSndSendCmd_cmd_id;
static p2sdPosvect *p2sdSetStandPos_stock_pos;
static s32 p2sdLoadSMGFile_FileSemaId;
static u8 p2sdLoadSMGFile_rpc_rebuf[16];
static p2sdIOPtoEEpkt *p2sdLoadSMGFile_pkt;
static s32 p2sdLoadSMGFile_offset;
static sdfFileCmdHandle_t *p2sdLoadSMGFile_fileHandle;

s32 FindId_1916848(s32 type, s32 id);
s32 PlaySE_Ex_20150896(s32 id, f32 volume, f32 pan);
void p2sdBGMStopAll(void);
void p2sdBGMVolHalfDown(void);
void p2sdBGMVolHalfUp(void);
void p2sdBGMVolume(u16 vol);
void p2sdContinue(s32 MidiNo);
s32 p2sdFadeIn(s32 a);
void p2sdFadeIn2(s32 MidiNo);
s32 p2sdFadeOut(s32 a);
s32 p2sdLoadCheckMidi(s32 MidiNo);
void p2sdLoadSMGFile(s32 MidiNo);
void p2sdLoadSMGFileFname(char *aFilename);
void p2sdMelodyTrans(s32 midiNo);
void p2sdPause(s32 MidiNo);
s32 p2sdPlayBGM(s32 a);
void p2sdPlaySeEx(s32 MidiNo, s32 aVolume, s32 pan);
void p2sdSndStop(s32 MidiNo);
void p2sdSndStopAll(void);
s32 sdfSndSendCmd(s32 aCmd, s32 aParam, void *aExDataPtr, s32 aExDataSize);
void sdfSndSeqMapInit(sdfSndSeqInfo_t **aSqInfo, s32 aNumSq);
void sdfSndVoiceMapInit(sdfSndVoiceInfo_t *aVcInfo, s32 aNumVc);

// 0x15cf6c0
void IOPcheckLoop(void *dummy) {
  ;
}

// 0x15d22e0
void p2sdAdpcmStreamFadeout(u32 fade) {
    sdfSndSendCmd(0, 0, 0, 0);
}

// 0x15d1fa0
s32 p2sdAdpcmStreamPlay(u16 **fname, u8 vol) {
    sdfSndSendCmd(0, 0, 0, 0);
    return 0;
}

// 0x15d2210
void p2sdAdpcmStreamSetVolume(u16 vol) {
    sdfSndSendCmd(0, 0, 0, 0);
}

// 0x15d20d0
s32 p2sdAdpcmStreamStatus(void) {
  return AdpcmPlaying;
}

// 0x15d2140
void p2sdAdpcmStreamStop(void) {
    sdfSndSendCmd(0, 0, 0, 0);
}

// 0x15d0560
void p2sdBGMStopAll(void) {
    p2sdBGMStopAll();
}

// 0x15d1e40
void p2sdBGMVolHalfDown(void) {
    p2sdBGMVolHalfDown();
}

// 0x15d1eb0
void p2sdBGMVolHalfUp(void) {
    p2sdBGMVolHalfUp();
}

// 0x15d1560
void p2sdBGMVolume(u16 vol) {
  p2sdBGMVolume(vol);
}

// 0x15d0400
void p2sdContinue(s32 MidiNo) {
  s32 Id_1916848;
  s32 v5;

  Id_1916848 = FindId_1916848(0, MidiNo);
  if (Id_1916848)
  {
    v5 = Id_1916848;
    p2sdContinue(v5);
  }
}

// 0x15d1cc0
void p2sdFadeIn(s32 MidiNo) {
  if (MidiNo != -1)
  {
    p2sdFadeIn(MidiNo);
  }
}

// 0x15d1d40
void p2sdFadeIn2(s32 MidiNo) {
  if (MidiNo != -1)
  {
    p2sdFadeIn2(MidiNo);
  }
}

// 0x15d1dc0
void p2sdFadeOut(s32 MidiNo) {
  if (MidiNo != -1)
  {
    p2sdFadeOut(MidiNo);
  }
}

// 0x15d15d0
void p2sdFree(s32 MidiNo) {
    p2sdLoadCheckMidi(0);
    sdfSndSendCmd(0, 0, 0, 0);
}

// 0x15d1a70
s32 p2sdIOPerror(s32 error) {
  return sdfSndMap->error_count;
}

// 0x15d0f00
s32 p2sdLoadCheckMidi(s32 MidiNo) {
  struct p2sdSMGstatus_array *smg;
  s32 v5;
  struct p2sdSMGstatus_array *v7;
  struct p2sdSMGstatus_array *v9;
  struct p2sdSMGstatus_array *v12;
  struct p2sdSMGstatus_array *v14;
  struct p2sdSMGstatus_array *v17;
  struct p2sdSMGstatus_array *v20;

  smg = sdfSndMap->smg;
  v5 = MidiNo >> 16;
  if (smg->m_Items[0]->reqno == v5)
    return 1;
  v7 = sdfSndMap->smg;
  if (v7->m_Items[1]->reqno == v5)
    return 1;
  v9 = sdfSndMap->smg;
  if (v9->m_Items[2]->reqno == v5)
    return 1;
  v12 = sdfSndMap->smg;
  if (v12->m_Items[3]->reqno == v5)
    return 1;
  v14 = sdfSndMap->smg;
  if (v14->m_Items[4]->reqno == v5)
    return 1;
  v17 = sdfSndMap->smg;
  if (v17->m_Items[5]->reqno == v5)
    return 1;
  v20 = sdfSndMap->smg;
  if (v20->m_Items[6]->reqno == v5)
    return 1;
  return 2 * (LastLoad == v5);
}

// 0x15d1220
void p2sdLoadSMGFile(s32 MidiNo) {
  if (MidiNo != -1)
  {
    p2sdLoadSMGFile(MidiNo);
  }
}

// 0x15d12a0
void p2sdLoadSMGFileFname(char *aFilename) {
  p2sdLoadSMGFileFname(aFilename);
}

// 0x15d1310
void p2sdLoadSMGFileOnMem(u8 *po, s32 size) {
  p2sdStream->length = size;
  p2sdStream->mode = 1;
  p2sdStream->mempointer = *po;
  LastLoad = -1;
}

// 0x15d1490
void p2sdMasterVolume(u16 vol) {
    sdfSndSendCmd(0, 0, 0, 0);
}

// 0x15d1f20
void p2sdMelodyTrans(s32 midiNo) {
  if (midiNo != -1)
  {
    p2sdMelodyTrans(midiNo);
  }
}

// 0x15d13c0
void p2sdOutputMode(s32 output_mode) {
    sdfSndSendCmd(0, 0, 0, 0);
}

// 0x15d0350
void p2sdPause(s32 MidiNo) {
  s32 Id_1916848;
  s32 v5;

  Id_1916848 = FindId_1916848(0, MidiNo);
  if (Id_1916848)
  {
    v5 = Id_1916848;
    p2sdPause(v5);
  }
}

// 0x15d02a0
void p2sdPlayBGM(s32 MidiNo) {
  s32 Id_1916848;
  s32 v5;

  Id_1916848 = FindId_1916848(0, MidiNo);
  if (Id_1916848)
  {
    v5 = Id_1916848;
    p2sdPlayBGM(v5);
  }
}

// 0x15cf4b0
void p2sdPlaySE(s32 SENo) {
  if (SENo != -1)
  {
    p2sdPlaySeEx(SENo, 127, 63);
  }
}

// 0x15cf630
void p2sdPlaySE_Vol(s32 SENo, s32 vol) {
  if (SENo != -1)
  {
    p2sdPlaySeEx(SENo, vol, 63);
  }
}

// 0x15d0ae0
void p2sdPlaySe3DEx(s32 MidiNo, f32 posx, f32 posy, f32 posz, s32 limit) {
  p2sdPosvect_o *v11;
  s64 v13;
  Il2CppObject *v14;
  s32 v15;
  s32 v17;

  v11 = Allocate(p2sdPosvect);
  p2sdPosvect___ctor(v11);
  v11->cx = (posx * 0.1);
  v11->cy = (posy * 0.1);
  v11->cz = (posz * 0.1);
  v11->reqno = MidiNo;
  v11->limit = limit;
  {
  }
  SizeOf_sdfMemRecord_t_(v11);
  sdfSndSendCmd(v17, v13, v14, v15);
}

// 0x15d0950
void p2sdPlaySeDeg(s32 MidiNo, f32 deg, f32 dis, f32 hight) {
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  s32 v18;

  v9 = deg % 360;
  v10 = v9 + 360;
  if (v9 > -181)
    v10 = deg % 360;
  if (v9 >= 181)
    v11 = v9 - 360;
  else
    v11 = v10;
  if (v11 >= 0)
    v12 = v11;
  else
    v12 = -v11;
  if (v11 >= 0)
    v13 = 1;
  else
    v13 = -1;
  if (v12 <= 44)
  {
    v14 = v12 * 0.71111;
    v17 = 1.0;
  }
  else
  {
    if (v12 <= 90)
    {
      v14 = v12 * 0.7;
      v15 = (v12 - 45) * -0.004444;
      v16 = 1.0;
    }
    else
    {
      v14 = (180 - v12) * 0.7;
      v15 = (v12 - 90) * -0.005556;
      v16 = 0.75;
    }
    v17 = v15 + v16;
  }
  v18 = 63 - v13 * v14;
  if (dis > 1.0)
    v17 = v17 / ((dis * 0.333) + 1.0);
  p2sdPlaySeEx(MidiNo, (v17 * 127.0), v18);
}

// 0x15cf530
void p2sdPlaySeEx(s32 MidiNo, s32 aVolume, s32 pan) {
  s32 Id_1916848;
  s32 v9;

  Id_1916848 = FindId_1916848(1, MidiNo);
  if (Id_1916848 != -1)
  {
    v9 = Id_1916848;
    PlaySE_Ex_20150896(v9, aVolume / 127.0, (pan - 63) / 63.0, 0);
  }
}

// 0x15d05d0
void p2sdSEStopAll(void) {
  ;
}

// 0x15d1a00
p2sdSMGstatus **p2sdSMGStatusPo(void) {
  return sdfSndMap->smg;
}

// 0x15d17f0
s32 p2sdSMGbgmtimes(s32 level) {
  struct p2sdSMGstatus_array *smg;

  smg = sdfSndMap->smg;
  return smg->m_Items[level]->bgmtimes;
}

// 0x15d18a0
s32 p2sdSMGsetimes(s32 level) {
  struct p2sdSMGstatus_array *smg;
  s32 v6;

  smg = sdfSndMap->smg;
  v6 = smg->m_Items[level]->totaltimes
     - sdfSndMap->smg->m_Items[level]->bgmtimes;
  return v6 & ~(v6 >> 31);
}

// 0x15d1740
s32 p2sdSMGtotaltimes(s32 level) {
  struct p2sdSMGstatus_array *smg;

  smg = sdfSndMap->smg;
  return smg->m_Items[level]->totaltimes;
}

// 0x15d23b0
void *p2sdSetMovieCallback(void *func) {
  struct sdfSound_StaticFields *static_fields;

  else
  {
    static_fields = sdfSound->static_fields;
    if (static_fields->MoviePlaying)
      return 0;
  }
  static_fields->p2sdStreamCallback = func;
  return func;
}

// 0x15d0c30
void p2sdSetStandPos(f32 Cposx, f32 Cposy, f32 Cposz, f32 Pposx, f32 Pposy, f32 Pposz) {
  p2sdPosvect_o *v13;
  s32 cx;
  struct p2sdPosvect_o *p2sdSetStandPos_stock_pos;
  s64 v18;
  Il2CppObject *v19;
  s32 v20;
  s32 v22;

  v13 = Allocate(p2sdPosvect);
  p2sdPosvect___ctor(v13);
  cx = (Cposx * 0.1);
  v13->cx = cx;
  v13->cy = (Cposy * 0.1);
  v13->cz = (Cposz * 0.1);
  v13->px = (Pposx * 0.1);
  v13->py = (Pposy * 0.1);
  v13->pz = (Pposz * 0.1);
  if (p2sdSetStandPos_stock_pos->cx != cx)
  else  if (p2sdSetStandPos_stock_pos->px != v13->px)
  if (p2sdSetStandPos_stock_pos->py != v13->py)
  if (p2sdSetStandPos_stock_pos->pz != v13->pz)
  {
    {
    }
    SizeOf_sdfMemRecord_t_(v13);
    else if ((byte_3F5A0B2 & 1) != 0)
    {
      sdfSndSendCmd(v22, v18, v19, v20);
      return;
    }
  }
}

// 0x15d04b0
void p2sdSndStop(s32 MidiNo) {
  s32 Id_1916848;

  if (MidiNo != -1)
  {
    Id_1916848 = FindId_1916848(1, MidiNo);
    p2sdSndStop(Id_1916848);
  }
}

// 0x15d05e0
void p2sdSndStopAll(void) {
    p2sdSndStopAll();
}

// 0x15d1990
sdfSndVoiceMap_t **p2sdVoiceMapPo(void) {
  return sdfSndMap->voiceMap;
}

// 0x15d1ae0
void p2sdVoiceStatus(u16 **buffer) {
  u64 v3;
  u64 i;
  struct System_Byte_array_array *dbg_vostat_f;
  System_Byte_array *v8;
  u16 v10;
  u64 v12;
  u16 *v13;
  struct System_Byte_array_array *v16;
  System_Byte_array *v17;
  u16 v19;

  if (buffer)
  {
    v3 = 0;
    for (i = 0; i != 24; ++i)
    {
      dbg_vostat_f = sdfSndMap->dbg_vostat_f;
      v8 = dbg_vostat_f->m_Items[0];
      v10 = v8->m_Items[i];
      buffer->m_Items[i] = v10;
      v3 -= 2LL;
    }
    v12 = 0;
    v13 = &buffer->m_Items[v3 / 0xFFFFFFFFFFFFFFFELL];
    do
    {
      v16 = sdfSndMap->dbg_vostat_f;
      v17 = v16->m_Items[1];
      v19 = v17->m_Items[v12];
      ++v12;
      *v13++ = v19;
    }
    while (v12 != 24);
  }
}

// 0x15cf6f0
void sdfSndCmdIFThread(void) {
  sdfSound_c *v2;

  while (1)
  {
    else if (!sdfSndBurstReqMode)
    {
      while (1)
      {
        while ((*&v2->_2.bitflags1 & 0x200) == 0)
          ;
      }
    }
  }
}

// 0x15cf6e0
s32 sdfSndCmdTrans(void) {
  return 0;
}

// 0x15cff80
void sdfSndInit(sdfSndVoiceInfo_t *aVcInfo, s32 aNumVc, sdfSndSeqInfo_t **aSqInfo, s32 aNumSq) {
  u64 v8;
  sdfSound_c *v9;
  s16 v10;
  s32 *v11;
  s32 i;
  struct sdfSound_StaticFields *static_fields;
  s32 *sdfSndCmdIFBuffer;
  s64 *v15;
  s64 *v16;
  sdfSndVoiceInfo_t_o *v21;
  sdfMemRecord_t_o *sdfSndMap;
  struct sdfSndMap_t_o *v27;
  s64 v28;
  Il2CppObject *v29;
  s32 v30;
  s32 v32;

  v8 = 0;
  if ((v10 & 0x200) != 0)
  for (i = 0; ; i = v10 & 0x200)
  {
    static_fields = v9->static_fields;
    sdfSndCmdIFBuffer = static_fields->sdfSndCmdIFBuffer;
    if (v8 >= sdfSndCmdIFBuffer[6])
      break;
    v15 = NewSpecific(s32, 0x20u);
    v16 = v15;
    v11 = &sdfSndCmdIFBuffer[2 * v8++];
    *(v11 + 4) = v16;
    if ((v10 & 0x200) == 0)
  }
  static_fields->sdfSndBurstReqMode = 1;
  sdfSndCmdHeadIndex = 0;
  sdfSndCmdTailIndex = 0;
  Write(StringLiteral_22020, 0);
  sdfSndMap->readBuff = 0;
  sdfSndMap->readBuffSize = 0x4000;
  sdfSndVoiceMapInit(v21, aNumVc);
  sdfSndSeqMapInit(aSqInfo, aNumSq);
  Write(StringLiteral_22021, 0);
  {
  }
  SizeOf_sdfMemRecord_t_(sdfSndMap);
  sdfSndMapIop = 0;
  sdfSndMap->returnAddr = sdfSndMap;
  v27 = sdfSndMap;
  v27->returnSize = SizeOf_sdfMemRecord_t_(v27);
  SizeOf_sdfMemRecord_t_(sdfSndMap);
  SizeOf(sdfSndMapIop);
  sdfSndSendCmd(v32, v28, v29, v30);
  sdfSndBurstReqMode = 0;
}

// 0x15cf780
void sdfSndInitCmdIF(void) {
  sdfSndCmdHeadIndex = 0;
  sdfSndCmdTailIndex = 0;
}

// 0x15cf6d0
void *sdfSndIopAlloc(s32 aLeng) {
  return 0;
}

// 0x15d07b0
void sdfSndLoadBDFile(s32 aVcChNum, char *aFilename) {
  s64 v4;
  Il2CppObject *v5;
  s32 v6;
  s32 v8;

  get_Length(aFilename);
  sdfSndSendCmd(v8, v4, v5, v6);
}

// 0x15d06e0
void sdfSndLoadHDFile(s32 aVcChNum, char *aFilename) {
  s64 v4;
  Il2CppObject *v5;
  s32 v6;
  s32 v8;

  get_Length(aFilename);
  sdfSndSendCmd(v8, v4, v5, v6);
}

// 0x15cf9a0
void sdfSndLoadIRXModules(void) {
  ;
}

// 0x15d0880
void sdfSndLoadSQFile(s32 aSqChNum, char *aFilename) {
  s64 v4;
  Il2CppObject *v5;
  s32 v6;
  s32 v8;

  get_Length(aFilename);
  sdfSndSendCmd(v8, v4, v5, v6);
}

// 0x15cf7f0
s32 sdfSndSendCmd(s32 aCmd, s32 aParam, void *aExDataPtr, s32 aExDataSize) {
  sdfSound_c *v5;
  struct sdfSound_StaticFields *static_fields;
  s32 v7;

  static_fields = v5->static_fields;
  v7 = static_fields->sdfSndSendCmd_cmd_id + 1;
  static_fields->sdfSndSendCmd_cmd_id = v7;
  if (v7)
  {
    if ((v5->_2.bitflags2 & 2) == 0)
  }
  sdfSndSendCmd_cmd_id = 1;
  sdfSndCmdTailIndex = (sdfSndCmdTailIndex + 1) & 0x1F;
  return sdfSndSendCmd_cmd_id;
}

// 0x15cf920
s32 sdfSndSendSyncCmd(s32 aCmd, s32 aParam, void *aExDataPtr, s32 aExDataSize) {
  s32 v5;

  return sdfSndSendCmd(v5, aParam, aExDataPtr, aExDataSize);
}

// 0x15cfd60
void sdfSndSeqMapInit(sdfSndSeqInfo_t **aSqInfo, s32 aNumSq) {
}

// 0x15d0650
void sdfSndSetupVoice(s32 aVcChNum) {
    sdfSndSendCmd(0, 0, 0, 0);
}

// 0x15cf910
void sdfSndSyncCmd(s32 aCmdId) {
  ;
}

// 0x15cf990
void sdfSndTransToIOP(void *aIOPAddr, void *aEEAddr, s32 aSize) {
  ;
}

// 0x15cf9b0
void sdfSndVoiceMapInit(sdfSndVoiceInfo_t *aVcInfo, s32 aNumVc) {
}
