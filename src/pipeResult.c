#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static sdfMemHandle_t *MessageMH;
static u8 pMessage[UNKNOWN_ARRAY_SIZE];
static u8 ResultIndex;
static u8 frame;
static u8 messIdx;
static s8 messCount;
static s8 mapIdx;
static u8 rBoxIdx[10];
static s8 pipeComp;
static s32 MaxMakaNum;
static s32 *ItemBuffer[7];

u8 Get(s32 id);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void RemoveKeys(s32 type, char *key);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
void datPartyDamagePipe(s32 big, s32 sml);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
u32 dds3GetRandA(char *name);
s8 fclChkMessage(void);
s8 fclDestroyMessage(void);
s8 fclEndMessage(void);
s8 fclInitMessage(void *pData);
void fclSetMessageVar_20743088(s8 Index, char *pStr);
s8 fclStartMessage(s32 MsgNo);
void fclUpdateMessage(void);
s8 pipeMessDraw(void);
void pipeMessInit(void);
void pipeMessStartA(s32 maka);
void pipeMessStartB(s32 itemid, s8 itemnum);
void pipeMessStartIdx(void);
u8 pipeResultDraw(void);
s32 pipeResultMakeRBox(void);

// 0x1542d00
s32 LDAMAGE(s32 o) {
  return HIWORD(o);
}

// 0x1542d10
s32 SDAMAGE(s32 o) {
  return o;
}

// 0x15433d0
void pipeMessDestroy(void) {
    fclDestroyMessage();
}

// 0x1543520
s8 pipeMessDraw(void) {
  if (fclChkMessage())
  {
    fclUpdateMessage();
    return 0;
  }
  else
  {
    fclEndMessage();
    return 1;
  }
}

// 0x1542d20
void pipeMessInit(void) {
    LoadFileByte(0, 0, 0);
    fclInitMessage(0);
}

// 0x15438f0
void pipeMessStartA(s32 maka) {
    fclSetMessageVar_20743088(0, 0);
    fclStartMessage(0);
}

// 0x1543ac0
void pipeMessStartB(s32 itemid, s8 itemnum) {
    Get(0);
    fclSetMessageVar_20743088(0, 0);
    fclStartMessage(0);
}

// 0x1543810
void pipeMessStartC(void) {
  fclStartMessage(2);
}

// 0x15435e0
void pipeMessStartIdx(void) {
  u64 v2;
  s32 messIdx;
  struct pipeResult_StaticFields *static_fields;
  char v5;
  s32 myMaka;

  if (messIdx == 2)
  if (messIdx == 1)
  {
    pipeMessStartA(myMaka);
    datAddMaka(myMaka);
    static_fields = pipeResult->static_fields;
    v5 = 2;
  }
  else
  {
    if (messIdx)
      return;
    if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
    fclStartMessage(2);
    static_fields = pipeResult->static_fields;
    v5 = 1;
  }
  static_fields->messIdx = v5;
}

// 0x15431b0
u8 pipeResultDraw(void) {
  s32 rBoxNum;
  u32 playerDAMAGE;
  u64 v6;
  s16 v7;
  s32 v8;

  if (!pipeMessDraw(pipeResult))
    return 0;
  if ((v7 & 0x200) != 0)
  {
    v8 = v7 & 0x200;
  }
  else
  {
    v8 = 0;
  }
  if (*(*(v6 + 184) + 32LL) + rBoxNum >= *(*(v6 + 184) + 19LL))
  {
    if (v8 && !*(v6 + 216))
    pipeMessStartIdx(v6);
    ++messCount;
    return 0;
  }
  else
  {
    if (v8 && !*(v6 + 216))
    datPartyDamagePipe(HIWORD(playerDAMAGE), playerDAMAGE, 0);
    return 1;
  }
}

// 0x15439b0
s32 pipeResultMakeRBox(void) {
  pipeResult_c *v2;
  struct pipeResult_StaticFields *static_fields;
  struct System_Int32_array_array *ItemBuffer;
  s64 v5;
  System_Int32_array *v7;
  s64 v8;

  static_fields = v2->static_fields;
  ItemBuffer = static_fields->ItemBuffer;
  v5 = static_fields->mapIdx - 1LL;
  v7 = ItemBuffer->m_Items[v5];
  v8 = dds3GetRandA(StringLiteral_416) % 0xA;
  return v7->m_Items[v8];
}

// 0x1533360
s32 pipeResultSection(void) {
  u64 v2;
  struct pipeResult_StaticFields *static_fields;
  u32 ResultIndex;
  s32 v6;
  s16 v7;
  s32 v8;
  u32 frame;
  struct tagpipeBasic_array *basicMy;
  UnityEngine_Object_o *gameObject;
  struct tagpipeBasic_array *v22;

  static_fields = pipeResult->static_fields;
  ResultIndex = static_fields->ResultIndex;
  if (ResultIndex > 3)
  {
    if (ResultIndex != 255)
      return 0;
    v7 = *(v2 + 294);
    if ((v7 & 0x200) != 0)
    {
      if (!*(v2 + 216))
      {
        static_fields = pipeResult->static_fields;
      }
      v8 = v7 & 0x200;
      frame = static_fields->frame;
      if (frame <= 0x1E)
    }
    else
    {
      v8 = 0;
      frame = static_fields->frame;
      if (frame <= 0x1E)
      {
        if (v8 && !*(v2 + 216))
        {
          static_fields = pipeResult->static_fields;
          LOBYTE(frame) = static_fields->frame;
        }
        v6 = 0;
        static_fields->frame = frame + 1;
        return v6;
      }
    }
    if (v8 && !*(v2 + 216))
    {
      static_fields = pipeResult->static_fields;
    }
    static_fields->ResultIndex = 0;
    fclDestroyMessage();
    gameObject = basicMy->m_Items[0]->basic->gameObject;
    Destroy_27360000(gameObject);
    v22 = basicMy;
    v22->m_Items[0]->basic->gameObject = 0;
    v6 = 1;
    RemoveKeys(1, StringLiteral_19042);
    RemoveKeys(3, StringLiteral_19042);
    return v6;
  }
  switch (ResultIndex)
  {
    case 0u:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      pipeMessInit(v2);
      frame = 0;
      v6 = 0;
      ResultIndex = 1;
      return v6;
    case 1u:
      dds3FadeIn(0xFFu, 0xFFu, 0xFFu, 0x1Eu);
      v6 = 0;
      ResultIndex = 2;
    case 2u:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      if (!pipeResultDraw(v2))
        return 0;
      v6 = 0;
      ResultIndex = 3;
      return v6;
    case 3u:
      dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0x1Eu);
      v6 = 0;
      ResultIndex = -1;
      frame = 0;
      break;
    default:
  }
  return v6;
}
