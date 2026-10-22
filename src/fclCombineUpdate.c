#include "types.h"

static void *OyajiObj;

void DevilStatusMode(bool flag, bool stat);
void *GetRootGameObject(void);
void Log(char *fmt, void **parray);
void WindowDispOff(bool sw);

// 0x1191790
void DevilStatusMode(bool sw, bool gc) {
  System_Object_array *v6;
  UnityEngine_Object_o *RootGameObject;
  UnityEngine_GameObject_o *v11;
  bool v12;
  UnityEngine_Object_o *v15;
  System_Object_array *v18;

  DevilStatusMode(sw, 0);
  v6 = Empty_string_();
  if (sw)
  {
    Log("DevilStatusMode = ON", v6, 0);
    RootGameObject = GetRootGameObject();
    if (op_Inequality(RootGameObject, 0, 0))
    {
      v11 = RootGameObject;
      v12 = 0;
LABEL_29:
      SetActive(v11, v12, 0);
    }
  }
  else
  {
    Log("DevilStatusMode = OFF", v6, 0);
    v15 = GetRootGameObject();
    if (op_Inequality(v15, 0, 0))
    {
      v11 = v15;
      v12 = 1;
      goto LABEL_29;
    }
  }
  else
  {
    WindowDispOff(1);
    if (!gc)
      return;
  }
  Collect(0);
  v18 = Empty_string_();
  Log("!!!!! GC !!!!!", v18, 0);
}

// 0x1197bf0
bool IsZensyoMode(void) {
  struct cmbGlobalWork_t_o *CMB_GBWK;

  if (!CMB_GBWK)
    return 0;
LABEL_6:
  if (CMB_GBWK->SeqInfo->Current != 2)
    return 0;
LABEL_9:
  return CMB_GBWK->bReadPhase;
}

// 0x1193e00
void OyajiOff(void) {
  UnityEngine_Object_o *OyajiObj;
  UnityEngine_GameObject_o *v5;
  UnityEngine_GameObject_o *gameObject;

  if (op_Equality(OyajiObj, 0, 0))
  {
    v5 = Find("Character/npc_jakyo", 0);
    gameObject = get_gameObject(v5);
    OyajiObj = gameObject;
  }
  if (get_activeSelf(OyajiObj))
  {
    SetActive(OyajiObj, 0, 0);
  }
}

// 0x1197d00
void UnlockTrophy(void) {
  ;
}

// 0x1190460
void UpdateCursor1st(s32 ocsr, s32 ncsr) {
  s32 v6;

  if (ocsr == ncsr)
  {
    v6 = 0;
  }
  else
  {
    v6 = ocsr + 1;
  }
  CMB_GBWK->EffCsr = v6;
}
