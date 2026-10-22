#include "types.h"

typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static s32 nbCameraPressRunFlag;
static s32 nbCameraPressFrame;
static s32 nbCameraPressThrough;
static dds3Effect_Blur_t *nbCameraPressBlur_Player;
static dds3Effect_Blur_t *nbCameraPressBlur_Enemy;

u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
nbMainProcessData_t *nbGetMainProcessData(void);

// 0x167ae30
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x167b200
s32 nbCameraPressProcessCheckRun(void) {
  return nbCameraPressRunFlag;
}

// 0x167b270
s32 nbCameraPressProcessGetFrame(void) {
  return nbCameraPressFrame;
}

// 0x167b0f0
void nbCameraPressProcessInit(void) {
  s32 v3;

  {
    else
    {
      if (nbCameraPressThrough)
        goto LABEL_5;
    }
  }
  else
  {
    v3 = 0;
    if (nbCameraPressThrough)
    {
LABEL_5:
      nbCameraPressRunFlag = 0;
      nbCameraPressFrame = 100;
      nbCameraPressThrough = 0;
      return;
    }
  }
  nbCameraPressRunFlag = 1;
  nbCameraPressFrame = 0;
}

// 0x167ae40
void nbCameraPressProcessRun(void) {
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v5;
  nbCameraPress_c *v6;
  s32 nbCameraPressFrame;
  struct dds3Effect_Blur_t_o *nbCameraPressBlur_Enemy;
  s16 v10;
  s32 v11;
  s32 v12;
  f32 v13;

  if (nbCameraPressRunFlag)
  {
    MainProcessData = nbGetMainProcessData();
    if (MainProcessData)
    {
      v5 = MainProcessData;
      if (nbCameraPressFrame > 9)
        goto LABEL_48;
      if (nbCameraPressFrame < 0)
        goto LABEL_48;
      if ((v5->stat & 8) != 0)
      {
        v10 = *&v6->_2.bitflags1;
        if ((v10 & 0x200) != 0)
        {
LABEL_24:
          v11 = v10 & 0x200;
          v12 = nbCameraPressFrame;
          if (v12 <= 2)
            goto LABEL_27;
          goto LABEL_35;
        }
      }
      else
      {
        nbCameraPressBlur_Enemy = nbCameraPressBlur_Player;
        v10 = *&v6->_2.bitflags1;
        if ((v10 & 0x200) != 0)
          goto LABEL_24;
      }
      v11 = 0;
      v12 = nbCameraPressFrame;
      if (v12 <= 2)
      {
LABEL_27:
        goto LABEL_44;
      }
LABEL_35:
      v12 = 10 - v12;
      if (v12 > 3)
      {
        v13 = 1.0;
        if ((v6->_2.bitflags2 & 2) != 0)
          goto LABEL_45;
        goto LABEL_47;
      }
LABEL_44:
      v13 = v12 / 3.0;
      if ((v6->_2.bitflags2 & 2) != 0)
      {
LABEL_45:
      }
LABEL_47:
      nbCameraPressBlur_Enemy->abgr = effColorBlend(0x808080u, 0x60808080u, v13);
LABEL_48:
      ++nbCameraPressFrame;
      if (nbCameraPressFrame >= 21)
      {
        nbCameraPressRunFlag = 0;
      }
    }
  }
}

// 0x167b2e0
void nbCameraPressProcessThrough(void) {
  nbCameraPressThrough = 1;
}
