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
  s32 v7;
  s32 v10;
  u64 v11;
  s32 v12;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v16;
  s64 v18;
  System_String_array *v20;
  System_String_o *v22;
  System_String_array *v23;
  s64 *v25;
  Il2CppObject *v28;
  char *v30;
  s64 *v31;
  u64 v32[3];

  v7 = ox;
  v10 = 4 * (viewerinfo->work_y + viewerinfo->work_base == no);
  if (no)
  {
    v11 = 0;
    v12 = 0;
    while (1)
    {
      if (v11 != 3)
      {
        workdata = dds3GetActiveScene()->workdata;
        klass = workdata->klass;
        if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
        {
          sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v32);
          if ((v32[0] & 1) != 0)
            v30 = v32[2];
          else
            v30 = v32 + 1;
          v31 = sub_8C4940(v30);
        }
        v16 = workdata[2].klass;
        v18 = *(*(&v16->_1.byval_arg.data + v11) + 24LL);
        if (v18)
          break;
      }
LABEL_20:
      if (v11++ >= 0x11)
        return;
    }
    while (1)
    {
      if (*(v18 + 24))
      {
        if (++v12 == no)
          break;
      }
      v18 = *(v18 + 72);
      if (!v18)
        goto LABEL_20;
    }
    v20 = NewSpecific(object, 1u);
    v22 = *(v18 + 24);
    v23 = v20;
    v23->m_Items[0] = v22;
    v25 = &" %s";
  }
  else
  {
    v23 = Empty_string_();
    v25 = &" -----------------------";
  }
  v28 = sdfDevPrintf(v7, oy, 0xFEFFFFu, v10, *v25, v23);
  sdfDrawTagLink(tag, v28);
}

// 0x10e5bc0
s32 evtBasicListMenu(s32 x, s32 y) {
  u64 *v5;
  u64 v7;
  s32 v8;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v12;
  s64 v14;
  s64 v15;
  s32 v18;
  s32 work_base;
  u64 *v20;
  s64 v22;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v28;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 v31;
  char *v33;
  s64 *v34;
  u64 v36[3];
  s32 xa[2];

  *xa = 0;
  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  v7 = 0;
  v8 = 0;
  do
  {
    if (v7 != 3)
    {
      workdata = dds3GetActiveScene()->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v36);
        if ((v36[0] & 1) != 0)
          v33 = v36[2];
        else
          v33 = v36 + 1;
        v34 = sub_8C4940(v33);
      }
      v12 = workdata[2].klass;
      v14 = *(*(&v12->_1.byval_arg.data + v7) + 24LL);
      while (v14)
      {
        v15 = *(v14 + 24);
        v14 = *(v14 + 72);
        if (v15)
          ++v8;
      }
    }
  }
  while (v7++ < 0x11);
  v18 = v8 + 1;
  work_base = viewerinfo->work_base;
  v20 = Allocate(evtEventViewerMenu_itemDelegate);
  v22 = Method_evtEventViewerMenu_evtBasicListItem__;
  v20[2] = *Method_evtEventViewerMenu_evtBasicListItem__;
  v20[4] = 0;
  v20[5] = v22;
  item = v20;
  evtMenuDisp(v5, x, y, 26, 23, work_base, v18, 0, item);
  v28 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v28, v5);
  if (viewerinfo->nowmenu != 10)
    return 0;
  *xa = 0;
  if (v8 <= 21)
    v31 = v8 + 1;
  else
    v31 = 23;
  return dds3SelectMenu(0, 1, v18, 1, v31, &xa[1], &viewerinfo->work_base, xa, &viewerinfo->work_y);
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
      goto LABEL_15;
    case 0xE:
      if (!Eve_PartialMultiBlurEditorDraw())
        goto LABEL_15;
      return 0;
    case 0xF:
      if (!Eve_DistortionBlurEditorDraw())
        goto LABEL_15;
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
        goto LABEL_15;
      return 0;
    default:
      if (!DDS3_PADCHECK_TRIG(12))
        return 0;
LABEL_15:
      v7 = viewerinfo;
      if (!v7->pid)
        return 1;
LABEL_18:
      p_pid = &v7->pid;
      v9 = 1;
      dds3KillProcess(p_pid, 1);
      viewerinfo->pid = 0;
      return v9;
  }
}

// 0x10e5f10
void evtEventPosItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  s16 v10;
  s32 v11;
  _BOOL4 v12;
  evtFrameInfo_t_o *SelectFrameInfo;
  struct pmdDataInfo_t_array *v15;
  s64 i_high;
  struct pmdDataInfo_t_array *v18;
  struct pmdNameTable_t_array *nametable;
  System_String_o *Name;
  dds3Basic_t_o *v25;
  struct pmdDataInfo_t_array *v26;
  struct pmdDataInfo_t_array *data;
  System_Object_array *v30;
  s64 *v31;
  s64 *v33;
  Il2CppObject *v36;
  u64 *v37;
  s64 *v39;
  u64 *v40;
  System_String_array *v42;
  System_String_o *v43;
  s32 v44;
  s32 v45;
  s32 v46;
  System_Object_array *v47;
  Il2CppObject *v52;
  s32 v53;
  dds3Basic_t_o *scene;

  scene = 0;
  if ((v10 & 0x200) != 0)
  {
    v11 = v10 & 0x200;
  }
  else
  {
    v11 = 0;
  }
  v12 = viewerinfo->eventpos_y == no;
  SelectFrameInfo = evtGetSelectFrameInfo();
  if (no == 3)
    goto LABEL_37;
LABEL_11:
  if (no == 2)
  {
    v18 = SelectFrameInfo->data;
    i_high = SBYTE2(v18->m_Items[0].i);
    if (i_high < 0)
      goto LABEL_40;
  }
  else if (no == 1)
  {
    v15 = SelectFrameInfo->data;
    i_high = SBYTE1(v15->m_Items[0].i);
    if (i_high < 0)
    {
LABEL_40:
      v25 = 0;
      goto LABEL_41;
    }
  }
  else
  {
    v26 = SelectFrameInfo->data;
    i_high = SLOBYTE(v26->m_Items[0].i);
    if (i_high < 0)
      goto LABEL_40;
  }
LABEL_20:
  scene = dds3GetActiveScene();
  nametable = viewerinfo->nametable;
  Name = nametable->m_Items[i_high]->Name;
  v25 = dds3SceneBasicSearchName(&scene, Name);
LABEL_41:
  v53 = no;
  v30 = NewSpecific(object, 1u);
  v31 = sub_8D3950(s32, &v53);
  v33 = v31;
  v30->m_Items[0] = v33;
  v36 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 14, "P%d:", v30);
  sdfDrawTagLink(tag, v36);
  if (v25)
  {
    v37 = NewSpecific(object, 1u);
    v39 = v25->name;
    v40 = v37;
    v40[4] = v39;
    v43 = "   %s";
    v44 = ox;
    v45 = oy;
    v46 = 4 * v12;
    v47 = v40;
  }
  else
  {
    v42 = Empty_string_();
    v43 = "   -----------------------";
    v44 = ox;
    v45 = oy;
    v46 = 4 * v12;
    v47 = v42;
  }
  v52 = sdfDevPrintf(v44, v45, 0xFEFFFFu, v46, v43, v47);
  sdfDrawTagLink(tag, v52);
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
  u64 *v8;
  u64 *v9;
  s64 *v10;
  u64 *v11;
  u64 *v13;
  Il2CppObject *v16;
  u16 v19[2];
  u16 evt_file_major;

  v8 = sub_8D3950(ushort, &evt_file_major);
  v19[0] = evt_file_minor;
  v9 = sub_8D3950(ushort, v19);
  v10 = Format_5268592("[E{0, 3:D}_{1:D3}.PM1+2]", v8, v9, 0);
  v11 = NewSpecific(object, 1u);
  v13 = v11;
  v13[4] = v10;
  v16 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, "%s", v13);
  sdfDrawTagLink(tag, v16);
  return 2;
}

// 0x10e1e80
void evtFileName2Item(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  s32 v10;
  System_Object_array *v12;
  Il2CppObject *v14;
  System_Object_array *v16;
  s64 *v18;
  s64 *v19;
  s64 *v22;
  System_Object_array *v24;
  Il2CppObject *v26;
  s64 *v29;
  s64 *v30;
  Il2CppObject *v33;
  System_Object_array *v35;
  s64 *v36;
  Il2CppObject *v42;
  u16 v43[2];
  u16 evt_file_major;

  v10 = 4 * (viewerinfo->filename_y == no);
  switch (no)
  {
    case 0:
      v12 = Empty_string_();
      v14 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 14, " EVENT", v12);
      sdfDrawTagLink(tag, v14);
      v16 = NewSpecific(object, 1u);
      v18 = sub_8D3950(ushort, &evt_file_major);
      v19 = v18;
      v16->m_Items[0] = v19;
      v22 = &"%3d";
      goto LABEL_37;
    case 1:
      v24 = Empty_string_();
      v26 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 14, "   CUT", v24);
      sdfDrawTagLink(tag, v26);
      v16 = NewSpecific(object, 1u);
      v43[0] = evt_file_minor;
      v29 = sub_8D3950(ushort, v43);
      v30 = v29;
      v16->m_Items[0] = v30;
      v22 = &"%03d";
LABEL_37:
      v33 = sdfDevPrintf(ox + 1536, oy, 0xFEFFFFu, v10, *v22, v16);
      sdfDrawTagLink(tag, v33);
      return;
    case 3:
      v35 = Empty_string_();
      v36 = &" L,R = NO-+";
      goto LABEL_58;
    case 4:
      v35 = Empty_string_();
      v36 = &" U,D = SELECT";
      goto LABEL_58;
    case 5:
      v35 = Empty_string_();
      v36 = &" RR  = ENTER";
      goto LABEL_58;
    case 6:
      v35 = Empty_string_();
      v36 = &" RD  = CANCEL";
      goto LABEL_58;
    case 7:
      v35 = Empty_string_();
      v36 = &" RL  = SET 600";
LABEL_58:
      v42 = sdfDevPrintf(ox, oy, 0xFEFFFFu, v10, *v36, v35);
      sdfDrawTagLink(tag, v42);
      break;
    default:
      return;
  }
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
  s32 filename_y;
  u32 evt_file_major;
  s32 v30;
  u32 evt_file_minor;
  s32 v35;
  u32 v36;
  u32 v38;
  struct evtEventViewer_StaticFields **p_static_fields;
  s32 v43;
  u32 v44;
  struct evtEventViewer_StaticFields *v45;
  u32 v47;
  struct evtEventViewer_StaticFields *v48;
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
  if (!DDS3_PADCHECK_REP(4))
  {
LABEL_61:
      goto LABEL_64;
    goto LABEL_62;
  }
  filename_y = viewerinfo->filename_y;
  if (filename_y == 1)
  {
    if (evt_file_minor >= 2)
    {
      evt_file_minor = evt_file_minor - 1;
    }
    goto LABEL_61;
  }
  if (filename_y)
    goto LABEL_61;
  if (evt_file_major < 0x1F5)
    goto LABEL_61;
  evt_file_major = evt_file_major - 1;
  {
LABEL_62:
  }
LABEL_64:
  if (!DDS3_PADCHECK_REP(5))
    goto LABEL_87;
  v35 = viewerinfo->filename_y;
  if (v35 == 1)
  {
    v38 = evt_file_minor;
    if (v38 <= 0x3E6)
    {
      evt_file_minor = v38 + 1;
    }
LABEL_87:
      goto LABEL_90;
    goto LABEL_88;
  }
  if (v35)
    goto LABEL_87;
  v36 = evt_file_major;
  if (v36 > 0x3E6)
    goto LABEL_87;
  evt_file_major = v36 + 1;
  {
LABEL_88:
  }
LABEL_90:
  if (!DDS3_PADCHECK_REP(8))
    goto LABEL_121;
  v43 = viewerinfo->filename_y;
  if (v43 == 1)
  {
    v47 = evt_file_minor;
    if (v47 >= 2)
    {
      evt_file_minor = v47 - 10;
      v48 = *p_static_fields;
      if (!v48->evt_file_minor)
      {
        v48->evt_file_minor = 1;
      }
    }
LABEL_121:
      goto LABEL_124;
    goto LABEL_122;
  }
  if (v43)
    goto LABEL_121;
  v44 = evt_file_major;
  if (v44 < 0x1F5)
    goto LABEL_121;
  evt_file_major = v44 - 500;
  v45 = *p_static_fields;
  if (v45->evt_file_major > 0x1F3u)
    goto LABEL_121;
  v45->evt_file_major = 500;
  {
LABEL_122:
  }
LABEL_124:
  if (!DDS3_PADCHECK_REP(10))
    goto LABEL_134;
  v52 = viewerinfo->filename_y;
  if (v52 != 1)
  {
    if (!v52)
    {
      evt_file_major += 100;
    }
LABEL_134:
      goto LABEL_141;
    goto LABEL_135;
  }
  evt_file_minor += 10;
  {
LABEL_135:
  }
LABEL_141:
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

  v8 = Format_5268592("[{0}.{1}]", &viewerinfo->filename->obj, viewerinfo->fileext);
  v9 = NewSpecific(object, 1u);
  v11 = v9;
  v11[4] = v8;
  v14 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, "%s", v11);
  sdfDrawTagLink(tag, v14);
  return 2;
}

// 0x10e14d0
void evtFileNameItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  s32 v9;
  s32 v10;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 v14;
  System_Object_array *v16;
  struct System_String_array *filestr;
  s64 *v20;
  s64 *v22;
  Il2CppObject *v25;
  u16 Chars;

  v9 = 0;
  v10 = ox + 192;
  do
  {
    if (viewerinfo->filename_y != no)
    {
LABEL_19:
      v14 = 0;
      goto LABEL_20;
    }
    else if (v9 != viewerinfo->filename_x)
    {
      goto LABEL_19;
    }
    if (viewerinfo->nowmenu == 3)
      v14 = 4;
    else
      v14 = 5;
LABEL_20:
    v16 = NewSpecific(object, 1u);
    Chars = get_Chars(filestr->m_Items[no], v9);
    v20 = sub_8D3950(char, &Chars);
    v22 = v20;
    v16->m_Items[0] = v22;
    v25 = sdfDevPrintf(v10, oy, 0xFEFFFFu, v14, "%c", v16);
    sdfDrawTagLink(tag, v25);
    ++v9;
    v10 += 192;
  }
  while (v9 != 11);
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
  v27 = viewerinfo;
  filename_y = v27->filename_y;
  Chars = get_Chars(filestr->m_Items[filename_y], v27->filename_x);
  v33 = viewerinfo;
  if (v33->filename_y != 3)
    goto LABEL_36;
  if (v33->filename_x < 4)
  {
LABEL_36:
    v34 = 0;
    if ((v32->_2.bitflags2 & 2) == 0)
      goto LABEL_41;
LABEL_39:
    while (1)
    {
LABEL_41:
      filename = viewerinfo->filename;
      if (!filename->m_Items[v34])
        break;
      ++v34;
        goto LABEL_39;
    }
    if (v34 > 7)
      return 0;
    v38 = viewerinfo->filename;
    v38->m_Items[v34] = Chars;
    v40 = viewerinfo->filename;
    v42 = v40 + 2 * (v34 + 1);
    goto LABEL_53;
  }
  if (Chars <= 0x4Bu)
  {
    if (Chars == 66)
    {
LABEL_69:
      v46 = 0;
      if ((v32->_2.bitflags2 & 2) == 0)
        goto LABEL_74;
LABEL_72:
      while (1)
      {
LABEL_74:
        v47 = viewerinfo->filename;
        if (!v47->m_Items[v46])
          break;
        ++v46;
          goto LABEL_72;
      }
      if (!v46)
        return 0;
      v50 = viewerinfo->filename;
      v51 = v46 - 1;
      v52 = v46 - 1;
      v42 = v50 + 2 * v52;
LABEL_53:
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
    goto LABEL_69;
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
  v10 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, "VALUE CHANGE.", v8);
  sdfDrawTagLink(tag, v10);
  return 2;
}

// 0x10decd0
void evtFloatChangeItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  System_Object_array *v10;
  s64 *v12;
  s64 *v14;
  Il2CppObject *v18;
  System_Object_array *v20;
  s64 *v21;
  Il2CppObject *v26;
  f32 fvalue;

  switch (no)
  {
    case 0:
      v10 = NewSpecific(object, 1u);
      fvalue = viewerinfo->fvalue;
      v12 = sub_8D3950(f32, &fvalue);
      v14 = v12;
      v10->m_Items[0] = v14;
      v18 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 4, "     %.1f", v10);
      sdfDrawTagLink(tag, v18);
      return;
    case 2:
      v20 = Empty_string_();
      v21 = &" L,R = VALUE-+0.1";
      goto LABEL_35;
    case 3:
      v20 = Empty_string_();
      v21 = &" U,D = VALUE-+1.0";
      goto LABEL_35;
    case 4:
      v20 = Empty_string_();
      v21 = &" RR  = ENTER";
      goto LABEL_35;
    case 5:
      v20 = Empty_string_();
      v21 = &" RD  = CANCEL";
LABEL_35:
      v26 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, *v21, v20);
      sdfDrawTagLink(tag, v26);
      break;
    default:
      return;
  }
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
      goto LABEL_42;
    goto LABEL_40;
  }
  if (DDS3_PADCHECK_REP(5))
    v24 = 0.1;
  else
    v24 = 0.0;
  {
LABEL_40:
  }
LABEL_42:
  if (!DDS3_PADCHECK_REP(6))
  {
    if (DDS3_PADCHECK_REP(7))
      v24 = 1.0;
      goto LABEL_53;
    goto LABEL_51;
  }
  v24 = -1.0;
  {
LABEL_51:
  }
LABEL_53:
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
  v10 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, "FRAME CHANGE.", v8);
  sdfDrawTagLink(tag, v10);
  return 2;
}

// 0x10dfcf0
void evtFrameChangeItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  System_Object_array *v10;
  s64 *v12;
  s64 *v14;
  Il2CppObject *v18;
  System_Object_array *v20;
  s64 *v21;
  Il2CppObject *v28;
  s32 value;

  switch (no)
  {
    case 0:
      v10 = NewSpecific(object, 1u);
      value = viewerinfo->value;
      v12 = sub_8D3950(s32, &value);
      v14 = v12;
      v10->m_Items[0] = v14;
      v18 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 4, "     %d", v10);
      sdfDrawTagLink(tag, v18);
      return;
    case 2:
      v20 = Empty_string_();
      v21 = &" L,R = FRMAE-+";
      goto LABEL_43;
    case 3:
      v20 = Empty_string_();
      v21 = &" U,D = FRAME-+10";
      goto LABEL_43;
    case 4:
      v20 = Empty_string_();
      v21 = &" RR  = ENTER";
      goto LABEL_43;
    case 5:
      v20 = Empty_string_();
      v21 = &" RD  = CANCEL";
      goto LABEL_43;
    case 6:
      v20 = Empty_string_();
      v21 = &" RL  = NOW FRAME";
      goto LABEL_43;
    case 7:
      v20 = Empty_string_();
      v21 = &" ST  = CAMERA FOCUS";
LABEL_43:
      v28 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, *v21, v20);
      sdfDrawTagLink(tag, v28);
      break;
    default:
      return;
  }
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
        goto LABEL_39;
    }
    else
    {
      v24 = DDS3_PADCHECK_REP(5);
      {
LABEL_39:
        if (DDS3_PADCHECK_REP(6))
        {
          v24 = -10;
          {
LABEL_50:
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
            goto LABEL_50;
        }
        goto LABEL_50;
      }
    }
    goto LABEL_39;
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
  struct evtFrameList_t_array *v18;
  struct System_String_array *frameheadstr;
  struct System_SByte_array *list;
  s64 v23;
  s64 *v25;
  Il2CppObject *v28;
  struct evtFrameList_t_array *v30;
  struct System_SByte_array *framelist_xcnt;
  struct System_SByte_array *v33;
  s64 v35;

  v5 = ox;
  type = viewerinfo->framelist_target->type;
  v9 = 32;
  {
LABEL_9:
    goto LABEL_11;
  }
  while (1)
  {
LABEL_11:
    v12 = v9 - 32;
    if (v12 >= evtFrameList->m_Items[type]->cnt)
      return 1;
    v15 = NewSpecific(object, 1u);
    v18 = evtFrameList;
    list = v18->m_Items[type]->list;
    v23 = *(&list->obj.klass + v9);
    v25 = frameheadstr->m_Items[v23];
    v15->m_Items[0] = v25;
    v28 = sdfDevPrintf(v5, oy, 0xFEFFFFu, 14, "%s", v15);
    sdfDrawTagLink(tag, v28);
    v30 = evtFrameList;
    v33 = v30->m_Items[type]->list;
    v35 = *(&v33->obj.klass + v9);
    v5 += 192 * framelist_xcnt->m_Items[v35];
    ++v9;
      goto LABEL_9;
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
      goto LABEL_20;
    goto LABEL_18;
  }
  v14 = 0;
  if ((v10->_2.bitflags2 & 2) != 0)
  {
LABEL_18:
  }
LABEL_20:
  if (viewerinfo->framelist_y + viewerinfo->framelist_base == no)
  {
    if (viewerinfo->nowmenu == 5)
      v18 = 4;
    else
      v18 = 5;
    if (v14)
      goto LABEL_28;
  }
  else
  {
    v18 = 0;
    if (v14)
    {
LABEL_28:
      evtFrameListItemSub(tag, ox, oy, v18, v14);
      return;
    }
  }
  if (v18)
    v19 = v18;
  else
    v19 = 8;
  v21 = Empty_string_();
  v23 = sdfDevPrintf(ox, oy, 0xFEFFFFu, v19, "----- NEW FRAME -----", v21);
  sdfDrawTagLink(tag, v23);
}

// 0x10e40e0
void evtFrameListItemSub(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 co, evtFrameInfo_t *f) {
  s32 v6;
  s64 type;
  s32 i_low;
  s64 v10;
  struct evtFrameList_t_array *evtFrameList;
  u64 v13;
  s32 v18;
  struct evtFrameList_t_array *v19;
  struct System_SByte_array *list;
  System_String_array *v23;
  f32 v24;
  System_String_array *v25;
  pmdDataInfo_t_o *v27;
  s64 *v29;
  s64 *v30;
  s64 *v33;
  s64 *v35;
  s64 *v37;
  char *p_i;
  System_String_array *v40;
  f32 v46;
  s64 *v47;
  s64 *v49;
  pmdDataInfo_t_o *m_Items;
  pmdDataInfo_t_o *p_c2;
  s32 v58;
  System_Object_array *v64;
  struct System_String_array *evtFrameListItemSub_unitmodestr;
  struct pmdDataInfo_t_array *v67;
  Il2CppObject *v71;
  s64 *v74;
  s64 *v76;
  System_String_o *v78;
  s32 v79;
  s32 v80;
  s32 v81;
  System_Object_array *v82;
  Il2CppObject *v84;
  struct evtFrameList_t_array *v86;
  struct System_SByte_array *framelist_xcnt;
  struct System_SByte_array *v89;
  struct pmdNameTable_t_array *nametable;
  s64 *v99;
  System_Object_array *v105;
  s64 c0;
  s64 *v110;
  System_Object_array *v113;
  struct pmdDataInfo_t_array *v115;
  System_String_array *v120;
  s64 *v121;
  s64 *v123;
  System_Object_array *v130;
  s32 v131;
  struct pmdDataInfo_t_array **p_data;
  s32 i;
  f32 v138;

  v6 = ox;
  type = viewerinfo->framelist_target->type;
  v131 = type & 0xFFFFFFFE;
  *&i_low = 0.0;
  v10 = 32;
  p_data = &f->data;
  {
LABEL_7:
    goto LABEL_10;
  }
  while (1)
  {
LABEL_10:
    v13 = v10 - 32;
    if (v13 >= evtFrameList->m_Items[type]->cnt)
      break;
    if (v13 == viewerinfo->framelist_x)
      v18 = co;
    else
      v18 = 0;
    v19 = evtFrameList;
    list = v19->m_Items[type]->list;
    switch (*(&list->obj.klass + v10))
    {
      case 0:
        v23 = NewSpecific(object, 1u);
        LODWORD(v24) = f->frame;
        v25 = v23;
        goto LABEL_64;
      case 1:
        v40 = NewSpecific(object, 1u);
        LODWORD(v24) = f->length;
        v25 = v40;
        goto LABEL_64;
      case 2:
        if (type == 7)
        {
          i_low = *&(*p_data)->m_Items[0].c0;
        }
        goto LABEL_164;
      case 3:
        if (type == 12)
          goto LABEL_160;
        if (type != 8)
          goto LABEL_164;
        goto LABEL_96;
      case 4:
        v25 = NewSpecific(object, 1u);
        LODWORD(v24) = *&(*p_data)->m_Items[0].c2;
LABEL_64:
        v138 = v24;
        goto LABEL_165;
      case 5:
        if (type <= 0x17)
        {
          if (((1 << type) & 0x83E800) != 0)
          {
            i_low = *&(*p_data)->m_Items[0].c0;
          }
          else if (type == 8)
          {
            i_low = SLOWORD((*p_data)->m_Items[0].i);
          }
          else if (type == 10)
          {
            i_low = f->nameindex;
          }
        }
        goto LABEL_145;
      case 6:
        v25 = NewSpecific(object, 1u);
        v46 = *&(*p_data)->m_Items[0].c0;
        v138 = SDF_RADtoDEG(v46);
        v47 = sub_8D3950(f32, &v138);
        v49 = v47;
        v25->m_Items[0] = v49;
        v37 = &"%.1f";
        goto LABEL_173;
      case 7:
        if (type == 5)
        {
          i_low = *&(*p_data)->m_Items[0].c2;
        }
        goto LABEL_164;
      case 8:
        if (type <= 5)
        {
          if (type == 3)
          {
            i_low = SBYTE1((*p_data)->m_Items[0].i);
          }
          else if (type == 5)
          {
            i_low = *&(*p_data)->m_Items[0].c0;
          }
        }
        else
        {
          switch (type)
          {
            case 0xC:
              i_low = (*p_data)->m_Items[0].i;
              break;
            case 0x12:
              i_low = SLOBYTE((*p_data)->m_Items[0].i);
              break;
            case 0x13:
              i_low = *&(*p_data)->m_Items[0].c2;
              break;
          }
        }
        v120 = NewSpecific(object, 1u);
        v138 = *&i_low;
        v25 = v120;
        v121 = sub_8D3950(s32, &v138);
        v123 = v121;
        v25->m_Items[0] = v123;
        v37 = &"%d";
        goto LABEL_173;
      case 9:
        if (type == 3)
          goto LABEL_160;
        if (type == 18)
        {
LABEL_96:
          m_Items = (*p_data)->m_Items;
        }
        else
        {
          if (v131 != 20)
            goto LABEL_164;
LABEL_160:
          m_Items = &(*p_data)->m_Items[0].c2;
        }
        i_low = *&m_Items->c0;
LABEL_164:
        v25 = NewSpecific(object, 1u);
        v138 = *&i_low;
LABEL_165:
        v74 = sub_8D3950(s32, &v138);
        v76 = v74;
        v25->m_Items[0] = v76;
        v37 = &"%4d";
        goto LABEL_173;
      case 0xA:
        switch (type)
        {
          case 0x12:
            p_c2 = &(*p_data)->m_Items[0].c2;
            break;
          case 9:
            p_c2 = (*p_data)->m_Items;
            break;
          case 3:
            p_c2 = (&(*p_data)->m_Items[0].i + 2);
            break;
          default:
            goto LABEL_196;
        }
        i_low = *&p_c2->c0;
LABEL_196:
        if (i_low < 0)
        {
          v25 = Empty_string_();
          v37 = &"-----------";
        }
        else
        {
          v25 = NewSpecific(object, 1u);
          nametable = viewerinfo->nametable;
          v99 = nametable->m_Items[i_low];
          v25->m_Items[0] = v99;
          v37 = &"%-.11s";
        }
        goto LABEL_173;
      case 0xB:
        if (type == 22)
        {
          v27 = (*p_data)->m_Items;
        }
        else
        {
          if (type != 9)
            goto LABEL_145;
          v27 = &(*p_data)->m_Items[0].c2;
        }
        i_low = *&v27->c0;
        goto LABEL_145;
      case 0xC:
        if (type <= 6)
        {
          if (type == 1)
          {
            v113 = NewSpecific(object, 1u);
            v130 = v113;
            v115 = *p_data;
            c0 = v115->m_Items[0].c0;
            if (v115->m_Items[0].c0 >= LODWORD(evtFrameListItemSub_unitmodestr->max_length))
            {
LABEL_223:
            }
          }
          else
          {
            if (type != 6)
              goto LABEL_178;
            v64 = NewSpecific(object, 1u);
            v130 = v64;
            evtFrameListItemSub_unitmodestr = evtFrameListItemSub_fadestr;
            v67 = *p_data;
            if (!LODWORD((*p_data)->max_length))
            {
LABEL_221:
            }
LABEL_222:
            c0 = *&v67->m_Items[0].c0;
            if (*&v67->m_Items[0].c0 >= LODWORD(evtFrameListItemSub_unitmodestr->max_length))
              goto LABEL_223;
          }
          v110 = evtFrameListItemSub_unitmodestr->m_Items[c0];
          v130->m_Items[0] = v110;
          v79 = oy;
          v78 = "%s";
          v80 = v6;
          v81 = v18;
          v82 = v130;
          goto LABEL_174;
        }
        if (type == 19)
        {
          v105 = NewSpecific(object, 1u);
          v130 = v105;
          evtFrameListItemSub_unitmodestr = evtFrameListItemSub_bgmmodestr;
          v67 = *p_data;
          if (!LODWORD((*p_data)->max_length))
            goto LABEL_221;
          goto LABEL_222;
        }
        if (type != 12)
          goto LABEL_178;
        v58 = *&(*p_data)->m_Items[0].c0;
        if (v58 == 2)
        {
          v25 = Empty_string_();
          v37 = &"SUB";
        }
        else if (v58 == 1)
        {
          v25 = Empty_string_();
          v37 = &"ADD";
        }
        else
        {
          if (*&(*p_data)->m_Items[0].c0)
            goto LABEL_178;
          v25 = Empty_string_();
          v37 = &"NORMAL";
        }
LABEL_173:
        v78 = *v37;
        v79 = oy;
        v80 = v6;
        v81 = v18;
        v82 = v25;
LABEL_174:
        v84 = sdfDevPrintf(v80, v79, 0xFEFFFFu, v81, v78, v82);
        sdfDrawTagLink(tag, v84);
LABEL_178:
        {
LABEL_157:
        }
LABEL_179:
        v86 = evtFrameList;
        v89 = v86->m_Items[type]->list;
        v6 += 192 * framelist_xcnt->m_Items[*(&v89->obj.klass + v10++)];
          goto LABEL_7;
        break;
      case 0xD:
        v25 = Empty_string_();
        v37 = &"...";
        goto LABEL_173;
      case 0xE:
        v25 = NewSpecific(object, 2u);
        v138 = *&(*p_data)->m_Items[0].c0;
        v29 = sub_8D3950(f32, &v138);
        v30 = v29;
        v25->m_Items[0] = v30;
        i = (*p_data)->m_Items[0].i;
        v33 = sub_8D3950(f32, &i);
        v35 = v33;
        v25->m_Items[1] = v35;
        v37 = &"%.1f %.2f";
        goto LABEL_173;
      case 0xF:
        if (type <= 0x15 && ((1 << type) & 0x300008) != 0)
          i_low = f->length;
        goto LABEL_164;
      case 0x10:
        if (type == 3)
        {
          p_i = &(*p_data)->m_Items[0].i;
        }
        else
        {
          if (v131 != 20)
            goto LABEL_145;
          p_i = &(*p_data)->m_Items[0].c1;
        }
        i_low = *p_i;
LABEL_145:
        v25 = Empty_string_();
        if (*&i_low != 0.0)
        {
          v37 = &"ON ";
          goto LABEL_173;
        }
        v71 = sdfDevPrintf(v6, oy, 0xFEFFFFu, v18, "OFF", v25);
        sdfDrawTagLink(tag, v71);
        *&i_low = 0.0;
          goto LABEL_157;
        goto LABEL_179;
      default:
        goto LABEL_178;
    }
  }
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
  v10 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, "VALUE CHANGE.", v8);
  sdfDrawTagLink(tag, v10);
  return 2;
}

// 0x10df500
void evtIntChangeItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  System_Object_array *v10;
  s64 *v12;
  s64 *v14;
  Il2CppObject *v18;
  System_Object_array *v20;
  s64 *v21;
  Il2CppObject *v26;
  s32 value;

  switch (no)
  {
    case 0:
      v10 = NewSpecific(object, 1u);
      value = viewerinfo->value;
      v12 = sub_8D3950(s32, &value);
      v14 = v12;
      v10->m_Items[0] = v14;
      v18 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 4, "     %d", v10);
      sdfDrawTagLink(tag, v18);
      return;
    case 2:
      v20 = Empty_string_();
      v21 = &" L,R = VALUE-+";
      goto LABEL_35;
    case 3:
      v20 = Empty_string_();
      v21 = &" U,D = VALUE-+10";
      goto LABEL_35;
    case 4:
      v20 = Empty_string_();
      v21 = &" RR  = ENTER";
      goto LABEL_35;
    case 5:
      v20 = Empty_string_();
      v21 = &" RD  = CANCEL";
LABEL_35:
      v26 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, *v21, v20);
      sdfDrawTagLink(tag, v26);
      break;
    default:
      return;
  }
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
      goto LABEL_39;
    goto LABEL_37;
  }
  v24 = DDS3_PADCHECK_REP(5);
  {
LABEL_37:
  }
LABEL_39:
  if (!DDS3_PADCHECK_REP(6))
  {
    if (DDS3_PADCHECK_REP(7))
      v24 = 10;
      goto LABEL_50;
    goto LABEL_48;
  }
  v24 = -10;
  {
LABEL_48:
  }
LABEL_50:
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
  v10[4] = "SAVE PROJ    >>";
  v10[5] = "LOAD PROJ    >>";
  v10[6] = "LOAD NEW PROJ>>";
  v10[7] = "SET START FRAME";
  v10[8] = "SET END   FRAME";
  v10[9] = "SET TOTAL FRAME";
  v10[10] = "CAPTURE        ";
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
    v28 = sdfDevPrintf(ox, oy, 0xFEFFFFu, v20, "%s", v23);
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
      goto LABEL_8;
  }
  else
  {
    v23 = 0;
    v24 = sy;
    v25 = baseitem;
    if (sy <= 0)
      goto LABEL_8;
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
LABEL_8:
  {
    v27 = v24;
    else
    {
      if ((evtMenuDisp_cnt & 0x10) == 0)
        goto LABEL_33;
    }
  }
  else
  {
    v27 = v24;
    if ((evtMenuDisp_cnt & 0x10) == 0)
      goto LABEL_33;
  }
  v28 = 16 * (5 * v40 + x) + 28768;
  if (baseitem >= 1)
  {
    v30 = Empty_string_();
    v32 = sdfDevPrintf(v28, v21 + 30896, 0xFEFFFFu, 6, "^", v30);
    sdfDrawTagLink(tag, v32);
    v27 = v24;
  }
  if (v25 >= maxitem)
  {
LABEL_33:
      goto LABEL_36;
    goto LABEL_34;
  }
  v33 = 8 * (v39 + 12 * v27) + 30960;
  v35 = Empty_string_();
  v37 = sdfDevPrintf(v28, v33, 0xFEFFFFu, 6, "v", v35);
  sdfDrawTagLink(tag, v37);
  {
LABEL_34:
  }
LABEL_36:
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
  s32 v10;
  u64 *v12;
  u32 *v13;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 objcnt;
  evtViewerObject_s_o *firstobjinfo;
  s32 v43;
  s32 v44;
  s32 v45;
  s32 v46;
  u64 *v71;
  s64 type;
  u64 *v74;
  s64 *v76;
  Il2CppObject *v79;

  v12 = NewSpecific(string, 0x1Eu);
  v13 = v12 + 3;
  v12[4] = "STAGE";
  v12[5] = "UNIT";
  v12[6] = "CAMERA";
  v12[7] = "D3P";
  v12[8] = "MESSAGE";
  v12[9] = "SE";
  v12[10] = "FADE";
  v12[11] = "QUAKE";
  v12[12] = "BLUR";
  v12[13] = "LIGHT";
  v12[14] = "SLIGHT";
  v12[15] = "SFOG";
  v12[16] = "FF";
  v12[17] = "BLUR2";
  v12[18] = "MBLUR";
  v12[19] = "DBLUR";
  v12[20] = "FILTER";
  v12[21] = "MFILTER";
  v12[22] = "BED";
  v12[23] = "BGM";
  v12[24] = "MG1";
  v12[25] = "MG2";
  v12[26] = "FBOKASI";
  v12[27] = "RBLUR";
  objcnt = viewerinfo->objcnt;
  if (objcnt)
  {
    else if (objcnt <= no)
    {
      return;
    }
    firstobjinfo = viewerinfo->firstobjinfo;
    if (no >= 1)
    {
      v43 = no & 3;
      if ((no - 1) >= 3)
      {
        v44 = v43 - no;
        do
        {
          firstobjinfo = firstobjinfo->firstframeinfo[1].klass->_1.declaringType->_1.declaringType;
          v44 += 4;
        }
        while (v44);
      }
      if ((no & 3) != 0)
      {
        v45 = -v43;
        do
        {
          firstobjinfo = firstobjinfo->firstframeinfo;
          ++v45;
        }
        while (v45);
      }
    }
    if (viewerinfo->objlist_y + viewerinfo->objlist_base != no)
    {
      v46 = 0;
LABEL_160:
      v71 = NewSpecific(object, 1u);
      type = firstobjinfo->type;
      v74 = v71;
      v76 = v12[type + 4];
      v74[4] = v76;
      v79 = sdfDevPrintf(ox, oy, 0xFEFFFFu, v46, "%s", v74);
      sdfDrawTagLink(tag, v79);
      return;
    }
    else if (viewerinfo->nowmenu == 4)
    {
      goto LABEL_123;
    }
    v46 = 5;
LABEL_156:
    evtObjectListSub(tag, firstobjinfo, ox, v10);
    goto LABEL_160;
  }
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
  v11 = sdfDevPrintf(ox + 1728, 31168, 0xFEFFFFu, 14, "NAME:", v9);
  sdfDrawTagLink(tag, v11);
  if ((obj->nameindex & 0x80000000) == 0)
  {
    v13 = NewSpecific(object, 1u);
    nametable = viewerinfo->nametable;
    nameindex = obj->nameindex;
    Name = nametable->m_Items[nameindex]->Name;
    v13->m_Items[0] = Name;
    v22 = sdfDevPrintf(ox + 2688, 31168, 0xFEFFFFu, 0, "%s", v13);
    sdfDrawTagLink(tag, v22);
  }
}

// 0x10e3b00
s32 evtOjbectListMenu(s32 x, s32 y) {
  u64 *v5;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 objlist_base;
  s32 objcnt;
  u64 *v11;
  s64 v13;
  evtEventViewerMenu_itemDelegate_o *item;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v19;
  evtEventViewer_c *v21;
  struct evtViewerInfo_t_o *v22;
  s32 v23;
  s32 xa[2];

  *xa = 0;
  v5 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v5);
  objlist_base = viewerinfo->objlist_base;
  objcnt = viewerinfo->objcnt;
  v11 = Allocate(evtEventViewerMenu_itemDelegate);
  v13 = Method_evtEventViewerMenu_evtObjectListItem__;
  v11[2] = *Method_evtEventViewerMenu_evtObjectListItem__;
  v11[4] = 0;
  v11[5] = v13;
  item = v11;
  evtMenuDisp(v5, x, y, 8, 29, objlist_base, objcnt, 0, item);
  v19 = dds3Ot->m_Items[83];
  sdfDrawTagLinkOt(v19, v5);
  v22 = viewerinfo;
  if (v22->nowmenu != 4)
    return 0;
  v23 = v22->objcnt;
  if (!v23)
    return 0;
LABEL_21:
  v23 = viewerinfo->objcnt;
  if (v23 <= 28)
    goto LABEL_30;
LABEL_24:
  v23 = 29;
  *xa = 0;
  if ((v21->_2.bitflags2 & 2) != 0)
  {
LABEL_25:
  }
  return dds3SelectMenu(0, 1, viewerinfo->objcnt, 1, v23, &xa[1], &viewerinfo->objlist_base, xa, &viewerinfo->objlist_y);
}

// 0x10e0c50
s32 evtSelectHead(sdfDrawTag_t *tag, s32 ox, s32 oy) {
  System_Object_array *v8;
  s64 *select_header;
  Il2CppObject *v13;

  if (!viewerinfo->select_header)
    return 0;
LABEL_6:
  v8 = NewSpecific(object, 1u);
  select_header = viewerinfo->select_header;
  v8->m_Items[0] = select_header;
  v13 = sdfDevPrintf(ox, oy, 0xFEFFFFu, 0, "%s", v8);
  sdfDrawTagLink(tag, v13);
  return 2;
}

// 0x10e0e10
void evtSelectItem(sdfDrawTag_t *tag, s32 ox, s32 oy, s32 no) {
  struct evtViewerInfo_t_o *viewerinfo;
  s32 v11;
  System_Object_array *v13;
  struct System_String_array *select_str;
  s64 *v17;
  Il2CppObject *v20;

  if (viewerinfo->select_max > no)
  {
    else if (viewerinfo->select_y == no)
    {
      goto LABEL_10;
    }
    v11 = 0;
LABEL_19:
    v13 = NewSpecific(object, 1u);
    select_str = viewerinfo->select_str;
    v17 = select_str->m_Items[no];
    v13->m_Items[0] = v17;
    v20 = sdfDevPrintf(ox, oy, 0xFEFFFFu, v11, " %s", v13);
    sdfDrawTagLink(tag, v20);
  }
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
    goto LABEL_16;
LABEL_6:
  Length = get_Length(select_header);
  if (Length <= 6)
    v10 = 6;
  else
    v10 = Length;
  {
LABEL_13:
  }
LABEL_17:
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

  else if (type == 11)
  {
    goto LABEL_9;
  }
  if (viewerinfo->nowmenu == 11)
    return 0;
LABEL_9:
  return evtViewerMenu_t_menufuncDelegate__Invoke(viewermenu->m_Items[type]->menufunc, x, y);
}
