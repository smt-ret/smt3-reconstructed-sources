#include "types.h"

typedef struct SoundAttach SoundAttach;
typedef struct SoundManager SoundManager;

void PlayBGM(char *name);
s32 PlaySE(char *name);
void _PlayVoice(SoundManager *this, char *name);

// 0x13352c0
void CallBGM(SoundAttach *this, char *name) {
    PlayBGM(0);
}

// 0x13353f0
void CallSE(SoundAttach *this, char *name) {
    PlaySE(0);
}

// 0x1335570
void CallVoice(SoundAttach *this, char *name) {
  _PlayVoice(Instance, name);
}

// 0x13356b0
void CallVoiceE728(SoundAttach *this) {
  System_String_o **v4;
  System_String_o *v5;

  if (this->VoiceNo)
    v4 = &StringLiteral_12141;
  else
    v4 = &StringLiteral_12142;
  v5 = *v4;
  _PlayVoice(Instance, v5);
}

// 0x13357a0
void CallVoiceE730(SoundAttach *this) {
  System_String_o **v4;
  System_String_o *v5;

  if (this->VoiceNo)
    v4 = &StringLiteral_12143;
  else
    v4 = &StringLiteral_12144;
  v5 = *v4;
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
