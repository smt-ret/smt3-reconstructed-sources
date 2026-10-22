#include "types.h"

typedef struct SoundAttach SoundAttach;

void FadeoutBGM_20166784(s32 id, f32 fadeTime);
s32 FindId_1916848(s32 type, s32 id);
void *GetAnimator(void *obj);
s32 GetMidiNo(s32 eventno, s32 seqno);
void Log(char *fmt, void **parray);
void PlayVoice(char *name);
void SetAnimVoice(s32 eventno, s32 no, s32 bno);
void SetVoiceNo(SoundAttach *this, s32 no);
void StopVoice(void);
bool evtBitCheck(s32 no);
void *fldGetCharObj(char *name);
s32 p2sdFadeIn(s32 a);
s32 p2sdFadeOut(s32 a);
void p2sdMelodyTrans(s32 midiNo);
s32 p2sdPlayBGM(s32 a);
s32 p2sdPlaySE(s32 a);
void p2sdPlaySE_20173184(char *define_name);
void p2sdSndStop(s32 MidiNo);
void p2sdSndStop_20178672(char *define_name);

// 0x194f250
s32 GetMidiNo(s32 eventno, s32 seqno) {
  s32 result;
  s32 v6;

  if (eventno > 722)
  {
    switch (eventno)
    {
      case 723:
        if (!evtBitCheck(3712))
          goto LABEL_33;
        result = 24772729;
        switch (seqno)
        {
          case 0:
            return 24772864;
          case 89:
            return result;
          case 90:
            return 24772730;
        }
        goto LABEL_33;
      case 724:
      case 725:
      case 726:
      case 727:
        goto LABEL_18;
      case 728:
        if (!evtBitCheck(3712))
          goto LABEL_33;
        return seqno + 25100544;
      case 729:
        if (!evtBitCheck(3712))
          goto LABEL_33;
        return seqno + 25166080;
      case 730:
        if (!evtBitCheck(3712))
          goto LABEL_33;
        return seqno + 25231616;
      case 731:
        if (!evtBitCheck(3712))
          goto LABEL_33;
        return seqno + 25297152;
      default:
        if (eventno == 799)
        {
          v6 = 199;
          return seqno + (v6 << 16) + 0x1000000;
        }
        if (eventno != 804)
          goto LABEL_18;
        if (seqno == 1)
          return 131073;
        break;
    }
    goto LABEL_36;
  }
  if (eventno == 640)
  {
    if (seqno == 1)
      return 131073;
    goto LABEL_33;
  }
  if (eventno == 656)
  {
    if (seqno == 1)
      return 131073;
    goto LABEL_33;
  }
  if (eventno != 660)
  {
LABEL_18:
    if (eventno > 799)
    {
      if (eventno <= 899)
      {
LABEL_36:
        v6 = eventno - 600;
        return seqno + (v6 << 16) + 0x1000000;
      }
      v6 = eventno - 670;
      return seqno + (v6 << 16) + 0x1000000;
    }
LABEL_33:
    v6 = eventno - 601;
    return seqno + (v6 << 16) + 0x1000000;
  }
  if (seqno != 1)
    goto LABEL_33;
  return 131073;
}

// 0x194fbf0
void SetAnimVoice(s32 eventno, s32 no, s32 bno) {
  u64 *v7;
  System_String_o *v9;
  UnityEngine_GameObject_o *CharObj;
  UnityEngine_Component_o *Animator;
  UnityEngine_Component_o *transform;
  UnityEngine_GUILayer_o *Component_GUILayer;
  System_Object_array *v19;
  s32 v20;

  v20 = eventno;
  v7 = sub_8D3950(s32, &v20);
  v9 = Format("raidou_e{0:D3}", v7, 0);
  CharObj = fldGetCharObj(v9);
  if (!op_Equality(CharObj, 0, 0))
  {
    Animator = GetAnimator(CharObj);
    if (!op_Equality(Animator, 0, 0))
    {
      transform = get_transform(Animator, 0);
      Component_GUILayer = GetComponent_GUILayer_(transform);
      if (op_Equality(Component_GUILayer, 0, 0))
      {
        v19 = Empty_string_();
        Log("!!!!! Not Attach Script !!!!!", v19, 0);
      }
      else
      {
        SetVoiceNo(Component_GUILayer, no - bno);
      }
    }
  }
}

// 0x194f510
s32 evtCheckSoundLoad(s32 eventno) {
  s32 MidiNo;

  if ((byte_3F5AA13 & 1) != 0)
  {
    if ((eventno - 600) > 0xFF)
      return 1;
  }
  else
  {
    if ((eventno - 600) > 0xFF)
      return 1;
  }
  MidiNo = GetMidiNo(eventno, 0);
  FindId_1916848(0, MidiNo);
  return 1;
}

// 0x194f7a0
s32 evtFadeInBgm(s32 eventno, s32 bgmno) {
  s32 v5;
  u64 *v7;
  s32 Id_1916848;
  s32 MidiNo;

  if ((eventno - 600) > 0xFF)
    return 0;
  MidiNo = GetMidiNo(eventno, bgmno);
  v5 = MidiNo;
  v7 = sub_8D3950(s32, &MidiNo);
  Write_2930400("Event BGM fade in play :{0:X8}\n", v7);
  Id_1916848 = FindId_1916848(0, v5);
  p2sdFadeIn(Id_1916848);
  return v5;
}

// 0x194f8d0
s32 evtFadeOutBgm(s32 eventno, s32 bgmno) {
  s32 MidiNo;
  s32 Id_1916848;
  s32 v9;

  if ((eventno - 600) > 0xFF)
    return 0;
  MidiNo = GetMidiNo(eventno, bgmno);
  Id_1916848 = FindId_1916848(0, MidiNo);
  if (Id_1916848 == 19267586)
  {
    FadeoutBGM_20166784(19267586, 4.0);
  }
  else
  {
    v9 = Id_1916848;
    p2sdFadeOut(v9);
  }
  return MidiNo;
}

// 0x194f470
s32 evtLoadSound(s32 eventno) {
  s32 MidiNo;

  if ((eventno - 600) > 0xFF)
    return 0;
  MidiNo = GetMidiNo(eventno, 0);
  return FindId_1916848(0, MidiNo);
}

// 0x194f5c0
s32 evtPlayBgm(s32 eventno, s32 bgmno) {
  s32 v5;
  u64 *v7;
  s32 Id_1916848;
  s32 MidiNo;

  if ((eventno - 600) > 0xFF)
    return 0;
  MidiNo = GetMidiNo(eventno, bgmno);
  v5 = MidiNo;
  v7 = sub_8D3950(s32, &MidiNo);
  Write_2930400("Event BGM play :{0:X8}\n", v7);
  Id_1916848 = FindId_1916848(0, v5);
  p2sdPlayBGM(Id_1916848);
  return v5;
}

// 0x194f9f0
s32 evtPlaySe(s32 eventno, s32 seno) {
  s32 MidiNo;
  s32 v9;

  if ((eventno - 600) > 0xFF)
    return 0;
  if (eventno == 724 && seno == 111)
  {
    p2sdPlaySE_20173184("E118_SE70");
    return 0;
  }
  MidiNo = GetMidiNo(eventno, seno);
  if (eventno == 730)
  {
    if ((seno - 512) < 2)
    {
      v9 = 730;
      goto LABEL_18;
    }
    if (seno != 514)
      goto LABEL_33;
    PlayVoice("E730_L0032m_ADD_F");
  }
  else
  {
    if (eventno == 728)
    {
      if ((seno & 0xFFFFFFFE) == 0x200)
      {
        v9 = 728;
LABEL_18:
        SetAnimVoice(v9, seno, 512);
        return MidiNo;
      }
LABEL_33:
      p2sdPlaySE(MidiNo);
      return MidiNo;
    }
    p2sdPlaySE(MidiNo);
    if (eventno == 651 && MidiNo == 20054125)
    {
      p2sdSndStop_20178672("E051_SE4E");
      p2sdSndStop_20178672("E051_SE4F");
      return 20054125;
    }
  }
  return MidiNo;
}

// 0x194fdf0
s32 evtStopSe(s32 eventno, s32 seno) {
  s32 MidiNo;

  if ((eventno - 600) > 0xFF)
    return 0;
  if (eventno == 731 && seno == 100)
  {
    StopVoice();
    return 0;
  }
  else
  {
    MidiNo = GetMidiNo(eventno, seno);
    p2sdSndStop(MidiNo);
  }
  return MidiNo;
}

// 0x194f6f0
void evtTransBgm(s32 eventno, s32 bgmno) {
  s32 MidiNo;

  if ((eventno - 600) <= 0xFF)
  {
    if (bgmno < 0)
      MidiNo = -1;
    else
      MidiNo = GetMidiNo(eventno, bgmno);
    p2sdMelodyTrans(MidiNo);
  }
}
