#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x10dd210
void *FrameVarProcess(dds3ProcessID_t *id) {
  struct evtViewerInfo_t_o *viewerinfo;
  u64 *v4;
  System_Object_array *v6;
  s64 *v8;
  s64 *v10;
  Il2CppObject *v13;
  evtEventViewer_c *v15;
  struct evtViewerInfo_t_o *v16;
  s32 nowframe;
  s32 totalframe;
  s32 v19;
  System_Object_array *v21;
  sdfDrawTag_t_o *v23;
  s64 *v24;
  s64 *v26;
  Il2CppObject *v29;
  System_Object_array *v30;
  System_Object_array *v31;
  s64 *v32;
  s64 *v33;
  Il2CppObject *v35;
  evtEventViewer_c *v37;
  struct evtViewerInfo_t_o *v38;
  struct System_Object_array *p;
  u64 *v40;
  s32 v41;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v48;
  struct sdfGrOt_t_array *v51;
  sdfGrOt_t_o *v53;
  s32 lastframe;
  s32 v56;
  s32 firstframe;

  else
  {
    if (viewerinfo->framedisp)
      goto LABEL_12;
  }
  if (!viewerinfo->menusw)
    return 0;
LABEL_12:
  v4 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v4);
  dds3ConsPanelTagLink(v4, 30, 400, 38, 2);
  v6 = NewSpecific(object, 1u);
  firstframe = viewerinfo->firstframe;
  v8 = sub_8D3950(s32, &firstframe);
  v10 = v8;
  v6->m_Items[0] = v10;
  v13 = sdfDevPrintf(29152, 34176, 0xFEFFFFu, 0, "%3d", v6);
  sdfDrawTagLink(v4, v13);
  if (viewerinfo->firstframe >= 1
  {
  }
  if (viewerinfo->lastframe < viewerinfo->totalframe - 1
    && (v15->_2.bitflags2 & 2) != 0
  {
  }
  if ((v15->_2.bitflags2 & 2) != 0)
  {
          v15 = evtEventViewer,
    {
    }
  }
  v16 = viewerinfo;
  nowframe = v16->nowframe;
  totalframe = v16->totalframe;
  if ((v16->stat & 1) != 0)
    v19 = 5;
  else
    v19 = 6;
  v21 = NewSpecific(object, 1u);
  else
  {
    v23 = v4;
  }
  v56 = viewerinfo->nowframe;
  v24 = sub_8D3950(s32, &v56);
  v26 = v24;
  v21->m_Items[0] = v26;
  v29 = sdfDevPrintf(
          16 * (360 * nowframe / totalframe) + 29920,
          34272,
          0xFEFFFFu,
          v19,
          "%3d",
          v21,
          0);
  sdfDrawTagLink(v23, v29);
  v30 = NewSpecific(object, 1u);
  lastframe = viewerinfo->lastframe;
  v31 = v30;
  v32 = sub_8D3950(s32, &lastframe);
  v33 = v32;
  v31->m_Items[0] = v33;
  v35 = sdfDevPrintf(35680, 34176, 0xFEFFFFu, 0, "%3d", v31);
  sdfDrawTagLink(v23, v35);
  v38 = viewerinfo;
  if (v38->framelist_target)
  {
    if (v38->menusw == 1)
    {
      else
      {
        p = v38->framelist_target->p;
        if (p)
        {
LABEL_69:
          v40 = 0;
          v41 = 0;
          if ((v37->_2.bitflags2 & 2) == 0)
            goto LABEL_74;
LABEL_72:
          while (1)
          {
LABEL_74:
            if (v41 == viewerinfo->framelist_y
                      + viewerinfo->framelist_base)
            {
              v40 = Allocate(sdfDrawTag_t);
              sdfDrawTag_t___ctor(v40);
            }
            else
            {
              p = p->m_Items[2];
              if (!p)
                goto LABEL_88;
            }
            ++v41;
              goto LABEL_72;
          }
        }
      }
    }
  }
  v40 = 0;
LABEL_88:
  v48 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v48, v23);
  if (v40)
  {
    v51 = dds3Ot;
    v53 = v51->m_Items[83];
    sdfDrawTagLinkOt(v53, v40);
  }
  return 0;
}

// 0x10dd920
dds3ProcessID_t *evtInitFrameVar(void) {
  u64 *v1;
  u64 *v2;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_evtEventViewerFrameVar_FrameVarProcess__);
  return dds3StartProcess("FrameVar", 0x2AF9u, 1, 1, v2, 0, 0, 0, 0, 0);
}
