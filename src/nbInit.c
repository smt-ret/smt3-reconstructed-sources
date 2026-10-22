#include "types.h"

u8 Get(s32 id);
void RemoveKeys(s32 type, char *key);
void nbInitMainProcess(s32 encpackno, s32 packno, s32 packindex, s32 encno, s32 stagemajor, s32 stageminor);
void nbInitPlayer(void);
void nbKillMainProcess(void);

// 0x19741d0
s32 NB_GET_ENCNO(s32 x) {
  return x;
}

// 0x19741c0
s32 NB_GET_PACKINDEX(s32 x) {
  return BYTE2(x);
}

// 0x19741b0
s32 NB_GET_PACKNO(s32 x) {
  return HIBYTE(x);
}

// 0x1973960
void _nbInit(void) {
  nbInitMainProcess(0, 0, 0, 1, 201, 1);
}

// 0x19741e0
void nbCallNewBattle(s32 encpack, s32 data) {
  datEncountPack_t_o *v5;
  u16 v8;
  u16 areaid;
  u16 stageid;
  s32 v11;
  s32 v12;

  if (encpack < 1)
  {
    stageid = Get(data, 0)->stageid;
    areaid = Get(data, 0)->areaid;
    if (areaid | stageid)
    {
      v8 = stageid;
    }
    else
    {
      areaid = 1;
      v8 = 201;
    }
  }
  else
  {
    v5 = Get(encpack, 0);
    v8 = v5->stageid;
    areaid = v5->areaid;
  }
  v11 = v8;
  v12 = areaid;
  nbInitMainProcess(encpack, HIBYTE(data), BYTE2(data), data, v11, v12);
}

// 0x1973fd0
void nbExit(void) {
  RemoveKeys(5, 0);
  SndAssetBundleManager_SndData___Clear(VoiceBundleTable);
  nbKillMainProcess();
}

// 0x19738f0
void nbInitPlayerData(void) {
  else
  {
    nbInitPlayer();
  }
}
