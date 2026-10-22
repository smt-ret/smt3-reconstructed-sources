#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct mviDebugCb_t mviDebugCb_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

static mviDebugCb_t *mviDebugCb;
static s32 SOX;
static s32 SOY;
static u32 SZM;
static s32 CX__;
static s32 CY__;
static u32 Z__;
static s32 OX__;
static s32 OY__;
static s32 SX__;
static s32 SY__;
static u32 IPU_CTRL;

bool DDS3_PAD2CHECK_PRESS(s32 id);
bool DDS3_PAD2CHECK_REP(s32 id);
void dds3MovieDebugDefault(void);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);

// 0x19c7de0
void dds3MovieDebugDataActivate(void) {
  mviDebugCb->ioAct = 1;
  mviDebugCb->memAct = 1;
}

// 0x19c7f70
void dds3MovieDebugDataUpdate(void) {

}

// 0x19c7e60
void dds3MovieDebugDefault(void) {
  struct mviDebugCb_t_o *mviDebugCb;

  mviDebugCb->ioAddr = IPU_CTRL;
  mviDebugCb->memAddr = dds3MovieCb;
  mviDebugCb->ioAct = 1;
  mviDebugCb->memAct = 1;
}

// 0x19c7fe0
dds3ProcessFunc_t *dds3MovieDebugProcess(dds3ProcessID_t *id) {
  u64 v2;
  struct mviDebugCb_t_o *mviDebugCb;
  u64 *v9;
  s32 CY;
  s32 CX;
  u32 SZM;
  s32 SOY;
  s32 SOX;
  System_Object_array *v16;
  System_Object_array *v17;
  s64 *v18;
  s64 *v20;
  s32 v21;
  s32 v22;
  Il2CppObject *v25;
  u32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  s32 v32;
  System_Object_array *v33;
  System_Object_array *v34;
  s64 *v35;
  s64 *v37;
  s32 v39;
  s64 *v40;
  s32 v41;
  u32 v42;
  u32 v43;
  s32 v44;
  s32 v45;
  s32 v46;
  s32 v47;
  Il2CppObject *v50;
  s32 v53;
  s32 v54;
  s32 v55;
  s32 v58;
  u32 v59;
  s32 v60;
  System_Object_array *v61;
  System_Object_array *v62;
  s64 *v63;
  s64 *v65;
  Il2CppObject *v68;
  s32 v69;
  s64 v70;
  bool v71;
  u32 v74;
  System_Object_array *v75;
  struct System_Byte_array *memData;
  System_Object_array *v77;
  s64 *v79;
  s64 *v81;
  s64 *v83;
  u32 v84;
  u32 v85;
  Il2CppObject *v88;
  s16 v89;
  s32 v90;
  struct mviDebugCb_t_o *v96;
  u8 cursor;
  s32 v109;
  u8 v110[4];
  s32 v111;
  s32 ioData;
  s32 ioAddr;

  else
  {
    if (mviDebugCb->init)
      goto LABEL_11;
  }
  mviDebugCb->init = 1;
  dds3MovieDebugDefault(v2);
LABEL_11:
  else if (DDS3_PAD2CHECK_PRESS(1))
  {
LABEL_14:
    mviDebugCb->ioAct = 1;
    mviDebugCb->memAct = 1;
      goto LABEL_35;
LABEL_33:
    goto LABEL_35;
  }
  else if (DDS3_PAD2CHECK_PRESS(2))
  {
    goto LABEL_28;
  }
  if (!DDS3_PAD2CHECK_REP(5))
    goto LABEL_146;
LABEL_136:
  ++mviDebugCb->cursor;
  v96 = mviDebugCb;
  if (v96->cursor != 16)
  {
LABEL_32:
      goto LABEL_35;
    goto LABEL_33;
  }
  v96->cursor = 0;
    goto LABEL_33;
LABEL_35:
  v9 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v9);
  CY = CY__;
  CX = CX__;
  v16 = NewSpecific(object, 1u);
  ioAddr = mviDebugCb->ioAddr;
  v17 = v16;
  v18 = sub_8D3950(s32, &ioAddr);
  v20 = v18;
  v21 = SOX + 2 * CX;
  v22 = SOY + 2 * CY;
  v17->m_Items[0] = v20;
  v25 = sdfDevPrintf(v21, v22, SZM + 128, 0, "%08X", v17);
  sdfDrawTagLink(v9, v25);
  if (mviDebugCb->ioAct)
  {
    v28 = SZM;
    v29 = CX__;
    v30 = CY__;
    v32 = SOX;
    v31 = SOY;
    v33 = NewSpecific(object, 1u);
    ioData = mviDebugCb->ioData;
    v34 = v33;
    v35 = sub_8D3950(s32, &ioData);
    v37 = v35;
    v34->m_Items[0] = v37;
    v39 = v32 + 11 * v29;
    v40 = &"%08X";
    v41 = v31 + 2 * v30;
    v42 = v28 + 128;
  }
  else
  {
    v43 = SZM;
    v44 = CX__;
    v45 = CY__;
    v47 = SOX;
    v46 = SOY;
    v34 = Empty_string_();
    v39 = v47 + 11 * v44;
    v40 = &"********";
    v41 = v46 + 2 * v45;
    v42 = v43 + 128;
  }
  v50 = sdfDevPrintf(v39, v41, v42, 0, *v40, v34);
  sdfDrawTagLink(v9, v50);
  v53 = SOY + 4 * CY__;
  v54 = 0;
  v55 = 0;
  do
  {
    v109 = v54;
    v58 = SOX;
    v59 = SZM;
    v60 = CX__;
    v61 = NewSpecific(object, 1u);
    v111 = v55 + mviDebugCb->memAddr->mode;
    v62 = v61;
    v63 = sub_8D3950(s32, &v111);
    v65 = v63;
    v62->m_Items[0] = v65;
    v68 = sdfDevPrintf(v58 + 2 * v60, v53, v59 + 128, 0, "%08X", v62);
    sdfDrawTagLink(v9, v68);
    v69 = SOX + 11 * CX__;
    v70 = 0;
    do
    {
      if (mviDebugCb->memAct)
      {
        v74 = SZM;
        v75 = NewSpecific(object, 1u);
        memData = mviDebugCb->memData;
        v77 = v75;
        v110[0] = memData->m_Items[v55 + v70];
        v79 = sub_8D3950(qword_3F088F8, v110);
        v81 = v79;
        v77->m_Items[0] = v81;
        v83 = &"%02X";
        v84 = v74 + 128;
      }
      else
      {
        v85 = SZM;
        v77 = Empty_string_();
        v83 = &"**";
        v84 = v85 + 128;
      }
      v88 = sdfDevPrintf(v69, v53, v84, 0, *v83, v77);
      sdfDrawTagLink(v9, v88);
      if ((v89 & 0x200) != 0)
      {
        v90 = v89 & 0x200;
      }
      else
      {
        v90 = 0;
      }
      ++v70;
      v69 += 3 * CX__;
      v71 = v90 == 0;
    }
    while (v70 != 8);
    v55 += 8;
    v54 = v109 + 1;
    v53 += CY__;
  }
  while (v109 != 7);
  return 0;
}
