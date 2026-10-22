#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

bool DDS3_PADCHECK_TRIG2(s32 id);
u64 GetOneShotKey(s32 kind);
u64 GetRepeatKey(bool oneShot, s32 kind);
void SelectSub(s32 *pbase, s32 *pm, s32 list, s32 win, s32 pad, s32 pluskey, s32 minuskey);
u32 dds3GetProcessRunTime(dds3ProcessID_t **id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void dds3PadAct(u32 mode, u8 pow, u32 frame);

// 0x14e42e0
void SelectSub(s32 *pbase, s32 *pm, s32 list, s32 win, s32 pad, s32 pluskey, s32 minuskey) {
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v17;
  System_Byte_array *v18;
  struct System_Byte_array_array_array *v20;
  s32 v22;
  s32 *v23;
  System_Byte_array_array *v26;
  System_Byte_array *v27;
  s32 v29;
  s32 v30;
  s32 v31;

  GetRepeatKey(1, pad);
  if (list < 2)
    return;
  if (!LODWORD(dds3PadMap->max_length))
    goto LABEL_24;
LABEL_10:
  v17 = dds3PadMap->m_Items[0];
  v18 = v17->m_Items[0];
  if ((v18->m_Items[minuskey] & 2) == 0)
  {
      goto LABEL_32;
    goto LABEL_14;
  }
  v22 = *pm;
  v23 = pm;
  if (!*pbase)
  {
    if (v22 > 0)
      goto LABEL_31;
    if (list >= win)
      v22 = win;
    else
      v22 = list;
    goto LABEL_30;
  }
  if (v22 <= 0)
  {
    v22 = *pbase;
    v23 = pbase;
    if (*pbase <= 0)
    {
      v22 = list;
      v23 = pm;
      if (list > win)
      {
        v22 = win;
        *pbase = list - win;
LABEL_30:
        v23 = pm;
      }
    }
  }
LABEL_31:
  *v23 = v22 - 1;
  {
LABEL_32:
    v20 = dds3PadMap;
    if (!LODWORD(v20->max_length))
      goto LABEL_41;
    goto LABEL_33;
  }
LABEL_14:
    goto LABEL_32;
  v20 = dds3PadMap;
  if (!LODWORD(v20->max_length))
  {
LABEL_41:
  }
LABEL_33:
  v26 = v20->m_Items[0];
  v27 = v26->m_Items[0];
  if ((v27->m_Items[pluskey] & 2) != 0)
  {
    v29 = *pm;
    v30 = *pbase;
    v31 = win - 1;
    if (*pbase)
    {
      if (v29 >= v31)
      {
        if (v30 + win < list)
        {
          *pbase = v30 + 1;
          return;
        }
        *pbase = 0;
        goto LABEL_46;
      }
    }
    else if (v29 >= v31)
    {
LABEL_46:
      *pm = 0;
      return;
    }
    *pm = v29 + 1;
  }
}

// 0x14e4860
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy) {
  ;
}

// 0x14e4870
void dds3ConsPanelTagLinkZ(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy, s32 z) {
  ;
}

// 0x14e45b0
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y) {
  s32 v21;

  SelectSub(basey, y, listsy, winsy, pad, 7, 6, x);
  SelectSub(basex, x, listsx, winsx, pad, 5, 4);
  GetOneShotKey(pad);
  if (pad)
  {
    v21 = 1;
    if (!DDS3_PADCHECK_TRIG2(1))
      goto LABEL_10;
  }
  else
  {
    v21 = 1;
    if (!DDS3_PADCHECK_TRIG2(1))
    {
LABEL_20:
      if (!DDS3_PADCHECK_TRIG2(3))
        return 0;
      return -1;
    }
  }
  return v21;
}

// 0x14e4880
void *dds3VibrationTestProcess(dds3ProcessID_t *id) {
  char RandIntA;
  dds3ProcessID_t_o *ida;

  ida = id;
  if (dds3GetProcessRunTime(&ida) % 0x4650)
    return 0;
  dds3PadAct(0, 1u, 0xFu);
  RandIntA = dds3GetRandIntA(0x96u, "");
  dds3PadAct(1u, RandIntA + 100, 0x1Eu);
  return 0;
}
