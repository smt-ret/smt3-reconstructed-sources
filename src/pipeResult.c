#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static sdfMemHandle_t *MessageMH;
static u8 *pMessage;
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
  else
  {
    fclDestroyMessage();
  }
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
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  Il2CppObject *p_obj;
  s16 v9;
  s32 v10;
  s32 dbZMAKANum;
  s32 v14;
  s32 dbMAKANum;
  s32 v17;
  s32 v18;
  s32 MaxMakaNum;
  char v22;
  char v23;
  pipeMain_c *v24;
  s32 mapIndex;
  struct pipeResult_StaticFields **p_static_fields;
  s32 v28;
  s16 v29;
  s32 v30;
  u32 v33;

  asset_bc = get_asset_bc();
  FileByte = LoadFileByte(asset_bc, "pipe_common", "dds3data/pipe/pipemes.bmd.bytes");
  pMessage = FileByte;
  p_obj = &pMessage->obj;
  fclInitMessage(p_obj);
  MaxMakaNum = 0;
  if ((v9 & 0x200) == 0)
  {
    v10 = 0;
    if (dbZMAKANum > 7)
      goto LABEL_14;
LABEL_22:
    else
    {
        goto LABEL_25;
    }
    v17 = 100 << dbZMAKANum;
    v18 = 5 * dbMAKANum - 100;
    goto LABEL_31;
  }
  v10 = v9 & 0x200;
  if (dbZMAKANum <= 7)
    goto LABEL_22;
LABEL_14:
  else
  {
    v14 = dbMAKANum;
      goto LABEL_17;
  }
  v17 = 9999 * dbZMAKANum;
  v18 = 5 * v14 - 57293;
LABEL_31:
  MaxMakaNum = v18 + v17;
  if (MaxMakaNum == myMaka)
  {
    else
    {
      v22 = 0;
      v23 = 1;
    }
  }
  else
  {
    v23 = 0;
    v22 = 1;
  }
  pipeComp = v23;
  messIdx = v22;
  messCount = 0;
  else
  {
    if (mapIndex == 1)
    {
LABEL_51:
      LOBYTE(v28) = 1;
LABEL_78:
      (*p_static_fields)->mapIdx = v28;
      return;
    }
  }
  v29 = *&v24->_2.bitflags1;
  if ((v29 & 0x200) == 0)
  {
    v30 = 0;
    if (mapIndex > 9)
      goto LABEL_58;
LABEL_68:
    if (mapIndex >= 0)
      v33 = mapIndex;
    else
      v33 = mapIndex + 1;
    v28 = (v33 >> 1) + 1;
    goto LABEL_78;
  }
  v30 = v29 & 0x200;
  if (mapIndex <= 9)
    goto LABEL_68;
LABEL_58:
  else if (mapIndex == 10)
  {
    goto LABEL_61;
  }
  if (mapIndex == 11)
  {
    LOBYTE(v28) = 7;
    goto LABEL_78;
  }
}

// 0x15438f0
void pipeMessStartA(s32 maka) {
  u64 *v3;
  System_String_o *v5;
  s32 v6;

  v6 = maka;
  v3 = sub_8D3950(s32, &v6);
  v5 = Format("{0:D}", v3, 0);
  fclSetMessageVar_20743088(0, v5);
  fclStartMessage(0);
}

// 0x1543ac0
void pipeMessStartB(s32 itemid, s8 itemnum) {
  System_String_o *v6;
  u64 *v7;
  System_String_o *v8;
  s8 v9[4];

  v6 = Get(itemid, 0);
  fclSetMessageVar_20743088(0, v6);
  v9[0] = itemnum;
  v7 = sub_8D3950(sbyte, v9);
  v8 = Format("{0:D}", v7, 0);
  fclSetMessageVar_20743088(1, v8);
  fclStartMessage(1);
}

// 0x1543810
void pipeMessStartC(void) {
  fclStartMessage(2);
}

// 0x15435e0
void pipeMessStartIdx(void) {
  u64 v2;
  s32 messIdx;
  char v5;
  s32 myMaka;

  if (messIdx == 2)
    goto LABEL_35;
LABEL_6:
  if (messIdx == 1)
  {
    pipeMessStartA(myMaka);
    datAddMaka(myMaka);
    v5 = 2;
  }
  else
  {
    if (messIdx)
      return;
    if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
    fclStartMessage(2);
    v5 = 1;
  }
  messIdx = v5;
}

// 0x15431b0
u8 pipeResultDraw(void) {
  s32 rBoxNum;
  u32 playerDAMAGE;
  u64 v6;
  s16 v7;
  s32 v8;

LABEL_7:
  if (!pipeMessDraw(pipeResult))
    return 0;
LABEL_18:
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
  struct System_Int32_array_array *ItemBuffer;
  s64 v5;
  System_Int32_array *v7;
  s64 v8;

  v5 = mapIdx - 1LL;
  v7 = ItemBuffer->m_Items[v5];
  v8 = dds3GetRandA("") % 0xA;
  return v7->m_Items[v8];
}

// 0x1533360
s32 pipeResultSection(void) {
  u64 v2;
  u32 ResultIndex;
  s32 v6;
  s16 v7;
  s32 v8;
  u32 frame;
  struct tagpipeBasic_array *basicMy;
  UnityEngine_Object_o *gameObject;
  struct tagpipeBasic_array *v22;

  if (ResultIndex > 3)
  {
LABEL_12:
    if (ResultIndex != 255)
      return 0;
    v7 = *(v2 + 294);
    if ((v7 & 0x200) != 0)
    {
      v8 = v7 & 0x200;
      if (frame <= 0x1E)
        goto LABEL_15;
    }
    else
    {
      v8 = 0;
      if (frame <= 0x1E)
      {
LABEL_15:
        if (v8 && !*(v2 + 216))
        {
          LOBYTE(frame) = frame;
        }
        v6 = 0;
        frame = frame + 1;
        return v6;
      }
    }
    ResultIndex = 0;
    fclDestroyMessage();
    gameObject = basicMy->m_Items[0]->basic->gameObject;
    Destroy_27360000(gameObject);
    v22 = basicMy;
    v22->m_Items[0]->basic->gameObject = 0;
    v6 = 1;
    RemoveKeys(1, "pipe_common");
    RemoveKeys(3, "pipe_common");
    return v6;
  }
LABEL_6:
  switch (ResultIndex)
  {
    case 0u:
      pipeMessInit(v2);
      frame = 0;
      v6 = 0;
      ResultIndex = 1;
      return v6;
    case 1u:
      dds3FadeIn(0xFFu, 0xFFu, 0xFFu, 0x1Eu);
      v6 = 0;
      ResultIndex = 2;
      goto LABEL_42;
    case 2u:
      if (!pipeResultDraw(v2))
        return 0;
      v6 = 0;
      ResultIndex = 3;
      return v6;
    case 3u:
      dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0x1Eu);
      v6 = 0;
      ResultIndex = -1;
LABEL_42:
      frame = 0;
      break;
    default:
      goto LABEL_12;
  }
  return v6;
}
