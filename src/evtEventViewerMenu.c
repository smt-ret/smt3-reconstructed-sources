#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtEventViewerMenu_headDelegate evtEventViewerMenu_headDelegate;
typedef struct evtEventViewerMenu_itemDelegate evtEventViewerMenu_itemDelegate;
typedef struct evtFrameInfo_t evtFrameInfo_t;
typedef struct evtFrameList_t evtFrameList_t;
typedef struct evtViewerMenu_t evtViewerMenu_t;
typedef struct evtViewerObject_s evtViewerObject_s;
typedef struct sdfDrawTag_t sdfDrawTag_t;

static char *frameheadstr[17];
static s8 framelist_xcnt[17];
static evtFrameList_t *evtFrameList[24];
static u32 evtMenuDisp_cnt;
static char *filestr[12];
static char *evtFrameListItemSub_fadestr[4];
static char *evtFrameListItemSub_bgmmodestr[7];
static char *evtFrameListItemSub_unitmodestr[5];
static evtViewerMenu_t *viewermenu[13];

bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
s32 Eve_BlurEditorDraw(void);
s32 Eve_DistortionBlurEditorDraw(void);
s32 Eve_FilterEditorDraw(void);
s32 Eve_PartialMultiBlurEditorDraw(void);
s32 Eve_PartialMultiFilterEditorDraw(void);
s32 Eve_RippleBlurEditorDraw(void);
f32 SDF_RADtoDEG(f32 n);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
dds3Basic_t *dds3GetActiveScene(void);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
dds3Basic_t *dds3SceneBasicSearchName(dds3Basic_t **scene, char *name);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);
void evtFrameListItemSub(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 co, evtFrameInfo_t *f);
evtFrameInfo_t *evtGetSelectFrameInfo(void);
void evtMenuDisp(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy, s32 baseitem, s32 maxitem, evtEventViewerMenu_headDelegate *head, evtEventViewerMenu_itemDelegate *item);
void evtObjectListSub(sdfDrawTag_t *tag, evtViewerObject_s *obj, s32 ox, s32 oy);
void evtRunFrame(s32 nowframe);
void evtViewerStopFrame(void);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x10e5890
void evtBasicListItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    dds3GetActiveScene();
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10e5bc0
s32 evtBasicListMenu(s32 x, s32 y) {
    dds3GetActiveScene();
    evtMenuDisp(0, 0, 0, 0, 0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
    dds3SelectMenu(0, 0, 0, 0, 0, 0, 0, 0, 0);
    return 0;
}

// 0x10e67c0
s32 evtDataMenu(s32 x, s32 y) {
  struct evtViewerInfo_t_o *viewerinfo;
  struct evtViewerInfo_t_o *v7;
  dds3ProcessID_t_o **p_pid;
  s32 v9;

  switch (viewerinfo->framelist_target->type)
  {
    case 0xD:
      if (Eve_BlurEditorDraw())
        return 0;
    case 0xE:
      if (!Eve_PartialMultiBlurEditorDraw())
      return 0;
    case 0xF:
      if (!Eve_DistortionBlurEditorDraw())
      return 0;
    case 0x10:
    case 0x11:
      else if (viewerinfo->pid)
      {
        return 0;
      }
      return 1;
    case 0x17:
      if (!Eve_RippleBlurEditorDraw())
      return 0;
    default:
      if (!DDS3_PADCHECK_TRIG(12))
        return 0;
      v7 = viewerinfo;
      if (!v7->pid)
        return 1;
      p_pid = &v7->pid;
      v9 = 1;
      dds3KillProcess(p_pid, 1);
      viewerinfo->pid = 0;
      return v9;
  }
}

// 0x10e5f10
void evtEventPosItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    evtGetSelectFrameInfo();
    dds3GetActiveScene();
    dds3SceneBasicSearchName(0, 0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10e63c0
s32 evtEventPosMenu(s32 x, s32 y) {
  u64 *v5;
  s32 type;
  s32 v9;
  u64 *v10;
  s64 v12;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v18;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 xa;
  s32 basey[2];

  *basey = 0;
  xa = 0;
  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  type = viewerinfo->framelist_target->type;
  if (type == 20)
  {
    v9 = 2;
  }
  else
  {
    if (type != 21)
      return -1;
    v9 = 4;
  }
  v10 = Allocate(evtEventViewerMenu_itemDelegate);
  v12 = Method_evtEventViewerMenu_evtEventPosItem__;
  v10[2] = *Method_evtEventViewerMenu_evtEventPosItem__;
  v10[4] = 0;
  v10[5] = v12;
  item = v10;
  evtMenuDisp(v5, x, y, 28, v9, 0, v9, 0, item);
  v18 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v18, v5);
  if (viewerinfo->nowmenu != 12)
    return 0;
  *basey = 0;
  xa = 0;
  return dds3SelectMenu(0, 1, v9, 1, v9, &basey[1], basey, &xa, &viewerinfo->eventpos_y);
}

// 0x10e1cb0
s32 evtFileName2Head(sdfDrawTag_t *tag, s32 ox, s32 oy) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x10e1e80
void evtFileName2Item(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10e2390
s32 evtFileName2Menu(s32 x, s32 y) {
  u64 *v5;
  u64 *v6;
  s64 v7;
  evtEventViewerMenu_headDelegate_o *v8;
  u64 *v9;
  s64 v11;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v17;
  evtEventViewer_c *v25;
  struct evtEventViewer_StaticFields *static_fields;
  s32 filename_y;
  u32 evt_file_major;
  s32 v30;
  u32 evt_file_minor;
  evtEventViewer_c *v33;
  struct evtEventViewer_StaticFields *v34;
  s32 v35;
  u32 v36;
  u32 v38;
  evtEventViewer_c *v40;
  struct evtEventViewer_StaticFields **p_static_fields;
  struct evtEventViewer_StaticFields *v42;
  s32 v43;
  u32 v44;
  struct evtEventViewer_StaticFields *v45;
  u32 v47;
  struct evtEventViewer_StaticFields *v48;
  evtEventViewer_c *v50;
  struct evtEventViewer_StaticFields *v51;
  s32 v52;

  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  v6 = Allocate(evtEventViewerMenu_headDelegate);
  v7 = Method_evtEventViewerMenu_evtFileName2Head__;
  v6[2] = *Method_evtEventViewerMenu_evtFileName2Head__;
  v8 = v6;
  v6[4] = 0;
  v6[5] = v7;
  v9 = Allocate(evtEventViewerMenu_itemDelegate);
  v11 = Method_evtEventViewerMenu_evtFileName2Item__;
  v9[2] = *Method_evtEventViewerMenu_evtFileName2Item__;
  v9[4] = 0;
  v9[5] = v11;
  item = v9;
  evtMenuDisp(v5, x, y, 17, 11, 0, 8, v8, item);
  v17 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v17, v5);
  if (viewerinfo->nowmenu != 9)
    return 0;
  if (DDS3_PADCHECK_TRIG(6))
  {
    viewerinfo->filename_y ^= 1u;
  }
  if (DDS3_PADCHECK_TRIG(7))
  {
    viewerinfo->filename_y ^= 1u;
  }
  static_fields = v25->static_fields;
  filename_y = static_fields->viewerinfo->filename_y;
  if (filename_y == 1)
  {
    evt_file_minor = static_fields->evt_file_minor;
    if (evt_file_minor >= 2)
    {
      static_fields->evt_file_minor = evt_file_minor - 1;
    }
  }
  if (filename_y)
  evt_file_major = static_fields->evt_file_major;
  if (evt_file_major < 0x1F5)
  static_fields->evt_file_major = evt_file_major - 1;
  {
  }
  if (!DDS3_PADCHECK_REP(5))
  v34 = v33->static_fields;
  v35 = v34->viewerinfo->filename_y;
  if (v35 == 1)
  {
    v38 = v34->evt_file_minor;
    if (v38 <= 0x3E6)
    {
      v34->evt_file_minor = v38 + 1;
    }
  }
  if (v35)
  v36 = v34->evt_file_major;
  if (v36 > 0x3E6)
  v34->evt_file_major = v36 + 1;
  {
  }
  if (!DDS3_PADCHECK_REP(8))
  p_static_fields = &v40->static_fields;
  v42 = v40->static_fields;
  v43 = v42->viewerinfo->filename_y;
  if (v43 == 1)
  {
    v47 = v42->evt_file_minor;
    if (v47 >= 2)
    {
      v42->evt_file_minor = v47 - 10;
      v48 = *p_static_fields;
      if (!v48->evt_file_minor)
      {
        v48->evt_file_minor = 1;
      }
    }
  }
  if (v43)
  v44 = v42->evt_file_major;
  if (v44 < 0x1F5)
  v42->evt_file_major = v44 - 500;
  v45 = *p_static_fields;
  if (v45->evt_file_major > 0x1F3u)
  v45->evt_file_major = 500;
  {
  }
  if (!DDS3_PADCHECK_REP(10))
  v51 = v50->static_fields;
  v52 = v51->viewerinfo->filename_y;
  if (v52 != 1)
  {
    if (!v52)
    {
      v51->evt_file_major += 100;
    }
  }
  v51->evt_file_minor += 10;
  {
  }
  v30 = 1;
  if (!DDS3_PADCHECK_TRIG(1))
  {
    else if (DDS3_PADCHECK_TRIG(3))
    {
      return -1;
    }
    v30 = 0;
    if (DDS3_PADCHECK_TRIG(0))
    {
      v30 = 0;
      evt_file_major = 600;
    }
  }
  return v30;
}

// 0x10e1340
s32 evtFileNameHead(sdfDrawTag_t *tag, s32 ox, s32 oy) {
  s64 *v8;
  u64 *v9;
  u64 *v11;
  Il2CppObject *v14;

  v8 = Format_5268592(StringLiteral_15853, &viewerinfo->filename->obj, viewerinfo->fileext);
  v9 = NewSpecific(object, 1u);
  v11 = v9;
  v11[4] = v8;
  v14 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, StringLiteral_15794, v11);
  sdfDrawTagLink(tag, v14);
  return 2;
}

// 0x10e14d0
void evtFileNameItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10e1770
s32 evtFileNameMenu(s32 x, s32 y) {
  u64 *v5;
  u64 *v6;
  s64 v7;
  evtEventViewerMenu_headDelegate_o *v8;
  u64 *v9;
  s64 v11;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v17;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 v21;
  evtEventViewerMenu_c *v23;
  struct evtEventViewerMenu_StaticFields *static_fields;
  struct System_String_array *filestr;
  struct evtViewerInfo_t_o *v27;
  s64 filename_y;
  u16 Chars;
  evtEventViewer_c *v32;
  struct evtViewerInfo_t_o *v33;
  u64 v34;
  struct System_Char_array *filename;
  struct System_Char_array *v38;
  struct System_Char_array *v40;
  char *v42;
  struct System_Char_array *v44;
  u64 v46;
  struct System_Char_array *v47;
  struct System_Char_array *v50;
  u32 v51;
  s64 v52;
  s32 basey[2];

  *basey = 0;
  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  v6 = Allocate(evtEventViewerMenu_headDelegate);
  v7 = Method_evtEventViewerMenu_evtFileNameHead__;
  v6[2] = *Method_evtEventViewerMenu_evtFileNameHead__;
  v8 = v6;
  v6[4] = 0;
  v6[5] = v7;
  v9 = Allocate(evtEventViewerMenu_itemDelegate);
  v11 = Method_evtEventViewerMenu_evtFileNameItem__;
  v9[2] = *Method_evtEventViewerMenu_evtFileNameItem__;
  v9[4] = 0;
  v9[5] = v11;
  item = v9;
  evtMenuDisp(v5, x, y, 14, 6, 0, 4, v8, item);
  v17 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v17, v5);
  if (viewerinfo->nowmenu != 3)
    return 0;
  *basey = 0;
  v21 = dds3SelectMenu(0, 11, 4, 11, 4, &basey[1], basey, &viewerinfo->filename_x, &viewerinfo->filename_y);
  if (v21 < 0)
    return -1;
  if (v21 != 1)
    return 0;
  static_fields = v23->static_fields;
  filestr = static_fields->filestr;
  v27 = viewerinfo;
  filename_y = v27->filename_y;
  Chars = get_Chars(filestr->m_Items[filename_y], v27->filename_x);
  v33 = viewerinfo;
  if (v33->filename_y != 3)
  if (v33->filename_x < 4)
  {
    v34 = 0;
    if ((v32->_2.bitflags2 & 2) == 0)
    while (1)
    {
      filename = viewerinfo->filename;
      if (!filename->m_Items[v34])
        break;
      ++v34;
    }
    if (v34 > 7)
      return 0;
    v38 = viewerinfo->filename;
    v38->m_Items[v34] = Chars;
    v40 = viewerinfo->filename;
    v42 = v40 + 2 * (v34 + 1);
  }
  if (Chars <= 0x4Bu)
  {
    if (Chars == 66)
    {
      v46 = 0;
      if ((v32->_2.bitflags2 & 2) == 0)
      while (1)
      {
        v47 = viewerinfo->filename;
        if (!v47->m_Items[v46])
          break;
        ++v46;
      }
      if (!v46)
        return 0;
      v50 = viewerinfo->filename;
      v51 = v46 - 1;
      v52 = v46 - 1;
      v42 = v50 + 2 * v52;
      *(v42 + 16) = 0;
      return 0;
    }
    if (Chars != 75)
      return 0;
  }
  else if (Chars != 79)
  {
    if (Chars != 83)
      return 0;
  }
  v44 = v33->filename;
  return v44->m_Items[0] != 0;
}

// 0x10e66f0
void *evtFilterEditorProcess(dds3ProcessID_t *id) {
  else if (Eve_FilterEditorDraw())
  {
    return 0;
  }
  viewerinfo->pid = 0;
  id->func_ans = -1;
  return 0;
}

// 0x10debe0
s32 evtFloatChangeHead(sdfDrawTag_t *tag, s32 ox, s32 oy) {
  System_Object_array *v8;
  Il2CppObject *v10;

  v8 = Empty_string_();
  v10 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, StringLiteral_15831, v8);
  sdfDrawTagLink(tag, v10);
  return 2;
}

// 0x10decd0
void evtFloatChangeItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10defe0
s32 evtFloatChangeMenu(s32 x, s32 y) {
  u64 *v5;
  u64 *v6;
  s64 v7;
  evtEventViewerMenu_headDelegate_o *v8;
  u64 *v9;
  s64 v11;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v17;
  s32 v20;
  f32 v24;
  struct evtViewerInfo_t_o *viewerinfo;
  struct evtViewerInfo_t_o *v29;

  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  v6 = Allocate(evtEventViewerMenu_headDelegate);
  v7 = Method_evtEventViewerMenu_evtFloatChangeHead__;
  v6[2] = *Method_evtEventViewerMenu_evtFloatChangeHead__;
  v8 = v6;
  v6[4] = 0;
  v6[5] = v7;
  v9 = Allocate(evtEventViewerMenu_itemDelegate);
  v11 = Method_evtEventViewerMenu_evtFloatChangeItem__;
  v9[2] = *Method_evtEventViewerMenu_evtFloatChangeItem__;
  v9[4] = 0;
  v9[5] = v11;
  item = v9;
  evtMenuDisp(v5, x, y, 22, 9, 0, 1, v8, item);
  v17 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v17, v5);
  if (viewerinfo->nowmenu != 8)
    return 0;
  v20 = 1;
  if (DDS3_PADCHECK_TRIG(1))
    return v20;
  else if (DDS3_PADCHECK_TRIG(3))
  {
    return -1;
  }
  if (DDS3_PADCHECK_REP(4))
  {
    v24 = -0.1;
  }
  if (DDS3_PADCHECK_REP(5))
    v24 = 0.1;
  else
    v24 = 0.0;
  {
  }
  if (!DDS3_PADCHECK_REP(6))
  {
    if (DDS3_PADCHECK_REP(7))
      v24 = 1.0;
  }
  v24 = -1.0;
  {
  }
  viewerinfo->fvalue = v24 + viewerinfo->fvalue;
  if (viewerinfo->fvalue < viewerinfo->fmin)
  {
    viewerinfo->fvalue = viewerinfo->fmin;
  }
  v29 = viewerinfo;
  if (v29->fvalue < v29->fmax)
    return 0;
  v20 = 0;
  v29->fvalue = v29->fmax;
  return v20;
}

// 0x10dfc00
s32 evtFrameChangeHead(sdfDrawTag_t *tag, s32 ox, s32 oy) {
  System_Object_array *v8;
  Il2CppObject *v10;

  v8 = Empty_string_();
  v10 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, StringLiteral_15840, v8);
  sdfDrawTagLink(tag, v10);
  return 2;
}

// 0x10dfcf0
void evtFrameChangeItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10e0080
s32 evtFrameChangeMenu(s32 x, s32 y) {
  u64 *v5;
  u64 *v6;
  s64 v7;
  evtEventViewerMenu_headDelegate_o *v8;
  u64 *v9;
  s64 v11;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v17;
  s32 v20;
  s32 v24;
  bool v29;
  struct evtViewerInfo_t_o *viewerinfo;
  struct evtViewerInfo_t_o *v32;
  s32 totalframe;
  struct evtViewerInfo_t_o *v36;
  s32 value;

  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  v6 = Allocate(evtEventViewerMenu_headDelegate);
  v7 = Method_evtEventViewerMenu_evtFrameChangeHead__;
  v6[2] = *Method_evtEventViewerMenu_evtFrameChangeHead__;
  v8 = v6;
  v6[4] = 0;
  v6[5] = v7;
  v9 = Allocate(evtEventViewerMenu_itemDelegate);
  v11 = Method_evtEventViewerMenu_evtFrameChangeItem__;
  v9[2] = *Method_evtEventViewerMenu_evtFrameChangeItem__;
  v9[4] = 0;
  v9[5] = v11;
  item = v9;
  evtMenuDisp(v5, x, y, 22, 11, 0, 1, v8, item);
  v17 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v17, v5);
  if (viewerinfo->nowmenu != 6)
    return 0;
  v20 = 1;
  if (!DDS3_PADCHECK_TRIG(1))
  {
    else if (DDS3_PADCHECK_TRIG(3))
    {
      return -1;
    }
    if (DDS3_PADCHECK_REP(4))
    {
      v24 = -1;
    }
    else
    {
      v24 = DDS3_PADCHECK_REP(5);
      {
        if (DDS3_PADCHECK_REP(6))
        {
          v24 = -10;
          {
            v29 = DDS3_PADCHECK_TRIG(0);
            if (v29)
            {
              v24 = viewerinfo->nowframe - viewerinfo->value;
            }
            viewerinfo->value += v24;
            if (viewerinfo->value < 0)
            {
              viewerinfo->value = 0;
            }
            v32 = viewerinfo;
            totalframe = v32->totalframe;
            if (v32->value >= totalframe)
            {
              v32->value = totalframe - 1;
            }
            if (DDS3_PADCHECK_PRESS(12))
            {
              v36 = viewerinfo;
              value = v36->value;
              if (v36->nowframe != value)
              {
                v36->nowframe = value;
                evtViewerStopFrame();
                evtRunFrame(viewerinfo->nowframe);
              }
            }
            return 0;
          }
        }
        else
        {
          if (DDS3_PADCHECK_REP(7))
            v24 = 10;
        }
      }
    }
  }
  return v20;
}

// 0x10e3dc0
s32 evtFrameListHead(sdfDrawTag_t *tag, s32 ox, s32 oy) {
  s32 v5;
  s64 type;
  s64 v9;
  struct evtFrameList_t_array *evtFrameList;
  u64 v12;
  System_Object_array *v15;
  evtEventViewerMenu_c *v16;
  struct evtEventViewerMenu_StaticFields *static_fields;
  struct evtFrameList_t_array *v18;
  struct System_String_array *frameheadstr;
  struct System_SByte_array *list;
  s64 v23;
  s64 *v25;
  Il2CppObject *v28;
  struct evtEventViewerMenu_StaticFields *v29;
  struct evtFrameList_t_array *v30;
  struct System_SByte_array *framelist_xcnt;
  struct System_SByte_array *v33;
  s64 v35;

  v5 = ox;
  type = viewerinfo->framelist_target->type;
  v9 = 32;
  {
  }
  while (1)
  {
    v12 = v9 - 32;
    if (v12 >= evtFrameList->m_Items[type]->cnt)
      return 1;
    v15 = NewSpecific(object, 1u);
    static_fields = v16->static_fields;
    v18 = static_fields->evtFrameList;
    frameheadstr = static_fields->frameheadstr;
    list = v18->m_Items[type]->list;
    v23 = *(&list->obj.klass + v9);
    v25 = frameheadstr->m_Items[v23];
    v15->m_Items[0] = v25;
    v28 = sdfDevPrintf(v5, oy, 0xFEFFFFu, 14, StringLiteral_15794, v15);
    sdfDrawTagLink(tag, v28);
    v29 = evtEventViewerMenu->static_fields;
    framelist_xcnt = v29->framelist_xcnt;
    v30 = v29->evtFrameList;
    v33 = v30->m_Items[type]->list;
    v35 = *(&v33->obj.klass + v9);
    v5 += 192 * framelist_xcnt->m_Items[v35];
    ++v9;
  }
}

// 0x10e5190
void evtFrameListItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  evtEventViewer_c *v10;
  struct evtViewerInfo_t_o *viewerinfo;
  struct evtViewerObject_s_o *framelist_target;
  s32 p;
  evtFrameInfo_t_o *v14;
  s32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  System_Object_array *v21;
  Il2CppObject *v23;

  framelist_target = viewerinfo->framelist_target;
  p = framelist_target->data.p;
  if (p < no)
    return;
  if (p != no)
  {
    v14 = framelist_target->p;
    if (no >= 1)
    {
      v15 = no & 3;
      if ((no - 1) >= 3)
      {
        v16 = v15 - no;
        do
        {
          v14 = *(*(*(v14->work.p + 48) + 48LL) + 48LL);
          v16 += 4;
        }
        while (v16);
      }
      if ((no & 3) != 0)
      {
        v17 = -v15;
        do
        {
          v14 = v14->work.p;
          ++v17;
        }
        while (v17);
      }
    }
    if ((v10->_2.bitflags2 & 2) == 0)
  }
  v14 = 0;
  if (viewerinfo->framelist_y + viewerinfo->framelist_base == no)
  {
    if (viewerinfo->nowmenu == 5)
      v18 = 4;
    else
      v18 = 5;
    if (v14)
  }
  else
  {
    v18 = 0;
    if (v14)
    {
      evtFrameListItemSub(tag, ox, oy, v18, v14);
      return;
    }
  }
  if (v18)
    v19 = v18;
  else
    v19 = 8;
  v21 = Empty_string_();
  v23 = sdfDevPrintf(ox, oy, 0xFEFFFFu, v19, StringLiteral_15890, v21);
  sdfDrawTagLink(tag, v23);
}

// 0x10e40e0
void evtFrameListItemSub(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 co, evtFrameInfo_t *f) {
    SDF_RADtoDEG(0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10e53f0
s32 evtFrameListMenu(s32 x, s32 y) {
  struct evtViewerInfo_t_o *viewerinfo;
  struct evtViewerObject_s_o *framelist_target;
  struct evtFrameList_t_array *evtFrameList;
  s64 type;
  u64 *v12;
  s32 framelist_base;
  s32 p;
  u64 *v17;
  s64 v18;
  evtEventViewerMenu_headDelegate_o *v19;
  u64 *v20;
  s64 v22;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v28;
  s32 v30;
  s32 v32;
  struct evtFrameList_t_array *v33;
  s64 v34;
  s32 cnt;
  s32 v38;
  s32 v40;
  evtFrameInfo_t_o *SelectFrameInfo;
  s32 frame;
  struct evtViewerInfo_t_o *v47;
  s32 basex;

  basex = 0;
  else
  {
    if (!viewerinfo->objcnt)
      return 0;
  }
  framelist_target = viewerinfo->framelist_target;
  type = framelist_target->type;
  if (!evtFrameList->m_Items[type]->cnt)
    return -1;
  v12 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v12);
  framelist_base = viewerinfo->framelist_base;
  p = framelist_target->data.p;
  v17 = Allocate(evtEventViewerMenu_headDelegate);
  v18 = Method_evtEventViewerMenu_evtFrameListHead__;
  v17[2] = *Method_evtEventViewerMenu_evtFrameListHead__;
  v19 = v17;
  v17[4] = 0;
  v17[5] = v18;
  v20 = Allocate(evtEventViewerMenu_itemDelegate);
  v22 = Method_evtEventViewerMenu_evtFrameListItem__;
  v20[2] = *Method_evtEventViewerMenu_evtFrameListItem__;
  item = v20;
  v20[4] = 0;
  v20[5] = v22;
  evtMenuDisp(v12, x, y, 28, 25, framelist_base, p + 1, v19, item);
  v28 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v28, v12);
  if (viewerinfo->nowmenu != 5)
    return 0;
  v30 = framelist_target->data.p;
  if (v30 <= 22)
    v32 = v30 + 1;
  else
    v32 = 24;
  v33 = evtFrameList;
  v34 = framelist_target->type;
  cnt = v33->m_Items[v34]->cnt;
  basex = 0;
  v38 = framelist_target->data.p;
  v40 = dds3SelectMenu(0, cnt, v38 + 1, cnt, v32, &basex, &viewerinfo->framelist_base, &viewerinfo->framelist_x, &viewerinfo->framelist_y);
  if (DDS3_PADCHECK_TRIG(0))
    v40 = -2;
  if (DDS3_PADCHECK_PRESS(12))
  {
    if (viewerinfo->framelist_y + viewerinfo->framelist_base < SLODWORD(framelist_target->data.p))
    {
      SelectFrameInfo = evtGetSelectFrameInfo();
      frame = SelectFrameInfo->frame;
      v47 = viewerinfo;
      if (v47->nowframe != frame)
      {
        v47->nowframe = frame;
        evtViewerStopFrame();
        evtRunFrame(viewerinfo->nowframe);
      }
    }
  }
  return v40;
}

// 0x10df410
s32 evtIntChangeHead(sdfDrawTag_t *tag, s32 ox, s32 oy) {
  System_Object_array *v8;
  Il2CppObject *v10;

  v8 = Empty_string_();
  v10 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, StringLiteral_15831, v8);
  sdfDrawTagLink(tag, v10);
  return 2;
}

// 0x10df500
void evtIntChangeItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10df810
s32 evtIntChangeMenu(s32 x, s32 y) {
  u64 *v5;
  u64 *v6;
  s64 v7;
  evtEventViewerMenu_headDelegate_o *v8;
  u64 *v9;
  s64 v11;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v17;
  s32 v20;
  s32 v24;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 min;
  struct evtViewerInfo_t_o *v30;
  s32 max;

  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  v6 = Allocate(evtEventViewerMenu_headDelegate);
  v7 = Method_evtEventViewerMenu_evtIntChangeHead__;
  v6[2] = *Method_evtEventViewerMenu_evtIntChangeHead__;
  v8 = v6;
  v6[4] = 0;
  v6[5] = v7;
  v9 = Allocate(evtEventViewerMenu_itemDelegate);
  v11 = Method_evtEventViewerMenu_evtIntChangeItem__;
  v9[2] = *Method_evtEventViewerMenu_evtIntChangeItem__;
  v9[4] = 0;
  v9[5] = v11;
  item = v9;
  evtMenuDisp(v5, x, y, 22, 9, 0, 1, v8, item);
  v17 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v17, v5);
  if (viewerinfo->nowmenu != 7)
    return 0;
  v20 = 1;
  if (DDS3_PADCHECK_TRIG(1))
    return v20;
  else if (DDS3_PADCHECK_TRIG(3))
  {
    return -1;
  }
  if (DDS3_PADCHECK_REP(4))
  {
    v24 = -1;
  }
  v24 = DDS3_PADCHECK_REP(5);
  {
  }
  if (!DDS3_PADCHECK_REP(6))
  {
    if (DDS3_PADCHECK_REP(7))
      v24 = 10;
  }
  v24 = -10;
  {
  }
  viewerinfo->value += v24;
  min = viewerinfo->min;
  if (viewerinfo->value < min)
  {
    viewerinfo->value = min;
  }
  v30 = viewerinfo;
  max = v30->max;
  if (v30->value < max)
    return 0;
  v20 = 0;
  v30->value = max;
  return v20;
}

// 0x10e0a50
s32 evtMainMenu(s32 x, s32 y) {
  u64 *v5;
  u64 *v6;
  s64 v8;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v14;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 xa;
  s32 basey[2];

  *basey = 0;
  xa = 0;
  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  v6 = Allocate(evtEventViewerMenu_itemDelegate);
  v8 = Method_evtEventViewerMenu_evtMainMenuItem__;
  v6[2] = *Method_evtEventViewerMenu_evtMainMenuItem__;
  v6[4] = 0;
  v6[5] = v8;
  item = v6;
  evtMenuDisp(v5, x, y, 15, 7, 0, 7, 0, item);
  v14 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v14, v5);
  if (viewerinfo->nowmenu != 1)
    return 0;
  *basey = 0;
  xa = 0;
  return dds3SelectMenu(0, 1, 7, 1, 7, &basey[1], basey, &xa, &viewerinfo->mainmenu_y);
}

// 0x10e0560
void evtMainMenuItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  u64 *v10;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 v20;
  u64 *v21;
  u64 *v23;
  s64 *v25;
  Il2CppObject *v28;

  v10 = NewSpecific(string, 0x1Eu);
  v10[4] = StringLiteral_15845;
  v10[5] = StringLiteral_15846;
  v10[6] = StringLiteral_15847;
  v10[7] = StringLiteral_15848;
  v10[8] = StringLiteral_15849;
  v10[9] = StringLiteral_15850;
  v10[10] = StringLiteral_15851;
  if (no <= 6)
  {
    if (viewerinfo->mainmenu_y == no)
    {
      if (viewerinfo->nowmenu == 1)
        v20 = 4;
      else
        v20 = 5;
    }
    else
    {
      v20 = 0;
    }
    v21 = NewSpecific(object, 1u);
    v23 = v21;
    v25 = v10[no + 4];
    v23[4] = v25;
    v28 = sdfDevPrintf(ox, oy, 0xFEFFFFu, v20, StringLiteral_15794, v23);
    sdfDrawTagLink(tag, v28);
  }
}

// 0x10ddb90
void evtMenuDisp(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy, s32 baseitem, s32 maxitem, evtEventViewerMenu_headDelegate *head, evtEventViewerMenu_itemDelegate *item) {
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  System_Object_array *v30;
  Il2CppObject *v32;
  s32 v33;
  System_Object_array *v35;
  Il2CppObject *v37;
  s32 v39;
  s32 v40;

  dds3ConsPanelTagLink(tag, x, y, sx, sy);
  v20 = 16 * x + 28672;
  v39 = y;
  v40 = sx;
  v21 = 8 * y;
  v22 = v21 + 30976;
  if (head)
  {
    v23 = Invoke(head, tag, v20, v22);
    v22 += 96 * v23;
    v24 = sy;
    v25 = baseitem;
    if (v23 >= sy)
  }
  else
  {
    v23 = 0;
    v24 = sy;
    v25 = baseitem;
    if (sy <= 0)
  }
  v25 = baseitem;
  if (item)
  {
    v26 = v24 - v23;
    v25 = baseitem;
    do
    {
      Invoke(item, tag, v20, v22, v25++);
      v22 += 96;
      --v26;
    }
    while (v26);
  }
  {
    v27 = v24;
    else
    {
      if ((evtMenuDisp_cnt & 0x10) == 0)
    }
  }
  else
  {
    v27 = v24;
    if ((evtMenuDisp_cnt & 0x10) == 0)
  }
  v28 = 16 * (5 * v40 + x) + 28768;
  if (baseitem >= 1)
  {
    v30 = Empty_string_();
    v32 = sdfDevPrintf(v28, v21 + 30896, 0xFEFFFFu, 6, StringLiteral_3421, v30);
    sdfDrawTagLink(tag, v32);
    v27 = v24;
  }
  v33 = 8 * (v39 + 12 * v27) + 30960;
  v35 = Empty_string_();
  v37 = sdfDevPrintf(v28, v33, 0xFEFFFFu, 6, StringLiteral_4654, v35);
  sdfDrawTagLink(tag, v37);
  {
  }
  ++evtMenuDisp_cnt;
}

// 0x10e6620
void *evtMultiFilterEditorProcess(dds3ProcessID_t *id) {
  else if (Eve_PartialMultiFilterEditorDraw())
  {
    return 0;
  }
  viewerinfo->pid = 0;
  id->func_ans = -1;
  return 0;
}

// 0x10e2dc0
void evtObjectListItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    evtObjectListSub(0, 0, 0, 0);
}

// 0x10e2b40
void evtObjectListSub(sdfDrawTag_t *tag, evtViewerObject_s *obj, s32 ox, s32 oy) {
  System_Object_array *v9;
  Il2CppObject *v11;
  System_Object_array *v13;
  struct pmdNameTable_t_array *nametable;
  s64 nameindex;
  s64 *Name;
  Il2CppObject *v22;

  dds3ConsPanelTagLink(tag, (ox - 26944) >> 4, 24, 28, 3, 0);
  v9 = Empty_string_();
  v11 = sdfDevPrintf(ox + 1728, 31168, 0xFEFFFFu, 14, StringLiteral_15862, v9);
  sdfDrawTagLink(tag, v11);
  if ((obj->nameindex & 0x80000000) == 0)
  {
    v13 = NewSpecific(object, 1u);
    nametable = viewerinfo->nametable;
    nameindex = obj->nameindex;
    Name = nametable->m_Items[nameindex]->Name;
    v13->m_Items[0] = Name;
    v22 = sdfDevPrintf(ox + 2688, 31168, 0xFEFFFFu, 0, StringLiteral_15794, v13);
    sdfDrawTagLink(tag, v22);
  }
}

// 0x10e3b00
s32 evtOjbectListMenu(s32 x, s32 y) {
    evtMenuDisp(0, 0, 0, 0, 0, 0, 0, 0, 0);
    sdfDrawTagLinkOt(0, 0);
    dds3SelectMenu(0, 0, 0, 0, 0, 0, 0, 0, 0);
    return 0;
}

// 0x10e0c50
s32 evtSelectHead(sdfDrawTag_t *tag, s32 ox, s32 oy) {
  System_Object_array *v8;
  s64 *select_header;
  Il2CppObject *v13;

  if (!viewerinfo->select_header)
    return 0;
  v8 = NewSpecific(object, 1u);
  select_header = viewerinfo->select_header;
  v8->m_Items[0] = select_header;
  v13 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, StringLiteral_15794, v8);
  sdfDrawTagLink(tag, v13);
  return 2;
}

// 0x10e0e10
void evtSelectItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x10e1070
s32 evtSelectMenu(s32 x, s32 y) {
  u64 *v5;
  System_String_o *select_header;
  s32 Length;
  s32 v10;
  s32 select_max;
  u64 *v12;
  s64 v13;
  evtEventViewerMenu_headDelegate_o *v14;
  u64 *v15;
  s64 v17;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v23;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 xa;
  s32 basey[2];

  *basey = 0;
  xa = 0;
  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  select_header = viewerinfo->select_header;
  if (!select_header)
  Length = get_Length(select_header);
  if (Length <= 6)
    v10 = 6;
  else
    v10 = Length;
  {
  }
  select_max = viewerinfo->select_max;
  v12 = Allocate(evtEventViewerMenu_headDelegate);
  v13 = Method_evtEventViewerMenu_evtSelectHead__;
  v12[2] = *Method_evtEventViewerMenu_evtSelectHead__;
  v14 = v12;
  v12[4] = 0;
  v12[5] = v13;
  v15 = Allocate(evtEventViewerMenu_itemDelegate);
  v17 = Method_evtEventViewerMenu_evtSelectItem__;
  v15[2] = *Method_evtEventViewerMenu_evtSelectItem__;
  v15[4] = 0;
  v15[5] = v17;
  item = v15;
  evtMenuDisp(v5, x, y, v10, select_max + 3, 0, select_max, v14, item);
  v23 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v23, v5);
  if (viewerinfo->nowmenu != 2)
    return 0;
  *basey = 0;
  xa = 0;
  return dds3SelectMenu(0, 1, viewerinfo->select_max, 1, viewerinfo->select_max, &basey[1], basey, &xa, &viewerinfo->select_y);
}

// 0x10e6a50
s32 evtViewerMenuRun(s32 type, s32 x, s32 y) {
  struct evtViewerMenu_t_array *viewermenu;

  else  if (viewerinfo->nowmenu == 11)
    return 0;
  return evtViewerMenu_t_menufuncDelegate__Invoke(viewermenu->m_Items[type]->menufunc, x, y);
}
