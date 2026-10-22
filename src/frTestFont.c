#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct frTestFont frTestFont;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct frTestFont {
    sdfTexHandle_t *gTex;
    s32 HandleInit_x;
    s32 HandleInit_y;
    u8 HandleInit_alpha;
};

static _FRQ *gFRQ;

bool DDS3_PADCHECK_PRESS(s32 id);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s8 fclDestroyMessage(void);
sdfTexHandle_t *fclLoadTexture(char *pFileName);
_FRQ *frDestroyFontRequestNow(_FRQ *pFRQ);
_FRQ *frwGetFontEx(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, s8 ChangeStyle, s8 Mode, _FRQ *pFRQ, s32 ftype);
dds3ProcessID_t *scrStartScript3(s32 priority, char *filename, s32 startproc, char *akey);

// 0x13a4f40
void HandleInit(frTestFont *this) {
  s32 v2;
  _FRQ_o *v3;
  s32 HandleInit_y;
  s32 HandleInit_x;
  s64 *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct _FRQ_o *gFRQ;
  s32 HandleInit_alpha;
  struct _FRQ_o *prev;
  s32 v20;
  struct _TEXT_o *i;
  u64 v23[3];

  HandleInit_x = this->HandleInit_x;
  HandleInit_y = this->HandleInit_y;
  v7 = "àâþ";
  if (!"àâþ")
    goto LABEL_12;
LABEL_6:
  Interface = QueryInterface(v7, byte);
  if (!Interface)
  {
    sub_8FC2C0(*(*v7 + 64), v8, v23);
    if ((v23[0] & 1) != 0)
      v10 = v23[2];
    else
      v10 = v23 + 1;
    v11 = sub_8C4940(v10);
  }
LABEL_13:
  gFRQ = frwGetFontEx(16 * HandleInit_x + 1024, 8 * HandleInit_y + 256, v2, 0x80808000, Interface, 1, 0, v3, -1);
  gFRQ->draw_spd = 12;
  else if (!DDS3_PADCHECK_PRESS(6))
  {
    goto LABEL_23;
  }
  HandleInit_alpha = this->HandleInit_alpha;
  if (HandleInit_alpha < 0)
    goto LABEL_23;
  this->HandleInit_alpha = HandleInit_alpha + 1;
  {
LABEL_25:
    if (!DDS3_PADCHECK_PRESS(7))
      goto LABEL_30;
    goto LABEL_26;
  }
LABEL_24:
    goto LABEL_25;
  if (!DDS3_PADCHECK_PRESS(7))
  {
LABEL_30:
      goto LABEL_33;
    goto LABEL_31;
  }
LABEL_26:
  if (!this->HandleInit_alpha)
    goto LABEL_30;
  --this->HandleInit_alpha;
    goto LABEL_33;
LABEL_31:
LABEL_33:
  prev = gFRQ;
  v20 = this->HandleInit_alpha;
  for (; prev; prev = prev->prev)
  {
    for (i = prev->str; i; i = i->next)
      i->color = v20 | 0x80808000;
  }
}

// 0x13a54b0
void frDrawFontUser(frTestFont *this, _FRQ *pFRQ) {
  struct _FRQ_o *head;
  _FRQ_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct _TEXT_o *str;
  _TEXT_c *v11;
  s64 v12;
  char *v13;
  s64 *v14;
  frFont_c *v15;
  u64 v16[2];
  char *v17;

  if (pFRQ)
  {
    head = pFRQ->head;
    if (head)
    {
      klass = head->klass;
      if (head->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != _FRQ)
      {
        sub_8FC2C0(klass->_1.element_class, _FRQ, v16);
        if ((v16[0] & 1) != 0)
          v7 = v17;
        else
          v7 = v16 + 1;
        v8 = sub_8C4940(v7);
      }
      do
      {
        str = head->str;
        if (str)
        {
          v11 = str->klass;
          if (str->klass->_2.typeHierarchyDepth < v12 || v11->_2.typeHierarchy[v12 - 1] != _TEXT)
          {
            sub_8FC2C0(v11->_1.element_class, _TEXT, v16);
            if ((v16[0] & 1) != 0)
              v13 = v17;
            else
              v13 = v16 + 1;
            v14 = sub_8C4940(v13);
          }
          do
          {
            while (1)
            {
              {
                      v15 = frFont,
                {
                        v15 = frFont,
                  {
                          v15 = frFont,
                    {
                            v15 = frFont,
                      {
                              v15 = frFont,
                        {
                                v15 = frFont,
                          {
                                  v15 = frFont,
                            {
                                break;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              str = str->next;
              if (!str)
                goto LABEL_37;
            }
            str = str->next;
          }
          while (str);
        }
LABEL_37:
        head = head->next;
      }
      while (head);
    }
  }
}

// 0x13a5390
void frTestFontDestroy(frTestFont *this, dds3ProcessID_t *id) {
  _FRQ_o *gFRQ;

  fclDestroyMessage();
LABEL_13:
  frDestroyFontRequestNow(gFRQ);
}

// 0x13a5230
void frTestFontInit(frTestFont *this) {
  u64 *v3;

  this->gTex = fclLoadTexture("/camp/test00.tmx");
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    this,
    Method_frTestFont_frTestFontMain__);
  dds3StartProcess("test_font", 0x2EE0u, 0, 0, v3, 0, 0, 0, 0, 0);
  scrStartScript3(600, "host0:../../../dds3data/facility/test.bf", 0, "e600");
}

// 0x13a5730
dds3ProcessFunc_t *frTestFontMain(frTestFont *this, dds3ProcessID_t *id) {
  return 0;
}
