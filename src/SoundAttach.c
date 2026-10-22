#include "types.h"

typedef struct SoundAttach SoundAttach;
typedef struct SoundManager SoundManager;

void PlayBGM(char *name);
s32 PlaySE(char *name);
void _PlayVoice(SoundManager *this, char *name);

// 0x13352c0
void CallBGM(SoundAttach *this, char *name) {
  System_String_o *v4;

  else
  {
    v4 = name;
  }
  PlayBGM(v4, name);
}

// 0x13353f0
void CallSE(SoundAttach *this, char *name) {
  System_String_o *v4;

  else
  {
    v4 = name;
  }
  PlaySE(v4, name);
}

// 0x1335570
void CallVoice(SoundAttach *this, char *name) {
LABEL_7:
  _PlayVoice(Instance, name);
}

// 0x13356b0
void CallVoiceE728(SoundAttach *this) {
  System_String_o **v4;
  System_String_o *v5;

  if (this->VoiceNo)
    v4 = &"E728_L0018_ADD_F";
  else
    v4 = &"E728_L0014_ADD_F";
  v5 = *v4;
LABEL_10:
  _PlayVoice(Instance, v5);
}

// 0x13357a0
void CallVoiceE730(SoundAttach *this) {
  System_String_o **v4;
  System_String_o *v5;

  if (this->VoiceNo)
    v4 = &"E730_L0025_ADD_F";
  else
    v4 = &"E730_L0022_ADD_F";
  v5 = *v4;
LABEL_10:
  _PlayVoice(Instance, v5);
}

// 0x1335890
void E723MSGTRIG(SoundAttach *this) {
  MSGTRG = 1;
}

// 0x13352b0
void SetVoiceNo(SoundAttach *this, s32 no) {
  this->VoiceNo = no;
}
