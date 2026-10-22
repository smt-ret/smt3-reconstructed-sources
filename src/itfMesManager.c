#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct FldNameData FldNameData;
typedef struct Speaker_tag Speaker_tag;
typedef struct _FRQ _FRQ;
typedef struct btlKutiManager btlKutiManager;
typedef struct curctr_tag curctr_tag;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct debug_tag debug_tag;
typedef struct evtKutiManager evtKutiManager;
typedef struct instanceMes_tag instanceMes_tag;
typedef struct instanceMes_tag_func_kutiDelegate instanceMes_tag_func_kutiDelegate;
typedef struct itfMesBinFileHeader_t itfMesBinFileHeader_t;
typedef struct itfMesBinMesHeader_t itfMesBinMesHeader_t;
typedef struct itfMesBinTypeHeader2_t itfMesBinTypeHeader2_t;
typedef struct itfMesBinTypeHeader_t itfMesBinTypeHeader_t;
typedef struct itfmisclinkstack_t itfmisclinkstack_t;
typedef struct itfpanel_t itfpanel_t;
typedef struct manager_tag manager_tag;
typedef struct mesflow_tag mesflow_tag;
typedef struct message_tag message_tag;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct select_tag select_tag;
typedef struct talkUI talkUI;
typedef struct variable_tag variable_tag;
typedef struct window_tag window_tag;

static s32 SelectYesSe;
static manager_tag *g_manager;
static s32 OK;
static s32 CANCEL;
static s32 SDF_PADMAP_OK;
static bool bVoicePlaySw;
static bool bWaitVoiceStop;
static s32 bNowSpeaking;
static bool bDanteEvent;
static void *MsgWndOwner;
static void *MsgWnd;
static s32 MsgWndIndex;
static s32 SelWndId;
static void *MsgWndTMP;
static void *MsgWndCnv;
static void *SpkWndTMP;
static void *frqstr;
static debug_tag *g_debug;
static void *pMsgMes;
static f32 EnablePos[3];

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
s32 CMP_XM(s32 a);
s32 CMP_YM(s32 b);
void CalcMesFlow(instanceMes_tag *pinst);
void CalcMessage(instanceMes_tag *pinst);
void CalcSelect(instanceMes_tag *pinst);
void CalcWindow(instanceMes_tag *pinst);
void CallEventVoice(instanceMes_tag *pinst);
void ChangeSelection(s32 index, s32 onoff);
bool ChkVoicePlaying(void);
void ClearMessage(void);
void ClearSpeaker(void);
void CommitVarTable(variable_tag *pvar);
void ConvertZenkakuNumber(char **buf, s32 num);
bool DDS3_PAD2CHECK_PRESS(s32 id);
bool DDS3_PAD2CHECK_REP(s32 id);
bool DDS3_PAD2CHECK_TRIG(s32 id);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
mesflow_tag *DebugChangeInstance(mesflow_tag *pflow);
void DebugDrawWindowLine(itfpanel_t *meswin);
void DebugMoveWinAlpha(window_tag *pwin);
void DebugMoveWinVert(window_tag *pwin, s32 flag);
void DestructFlow(s32 id);
void Display(talkUI *this, bool sw);
void DisplayOff(talkUI *this);
void Draw(s32 x, s32 y, _FRQ *frq, s32 colno);
void DrawMesFlow(instanceMes_tag *pinst);
s32 DrawMessage(_FRQ *pfont);
void DrawSpeaker(_FRQ *pfont);
void DrawWindow(instanceMes_tag *pinst);
void FadeInWindow(void);
void FadeOutWindow(void);
u8 Get(s32 id);
s32 GetDisplayStatus(talkUI *this);
char *GetFRQString(_FRQ *frq);
_FRQ *GetFontHandleUnit(u8 **dat, u32 **ppstr, s32 **pplen, s32 num, u32 mask, s32 x, s32 y, u32 z);
evtKutiManager *GetKutiManager(void);
char *GetLocalizeText(char *ID);
s32 GetMaskedIndex(s32 index, u32 mask);
u8 **GetMessagePagePtr(itfMesBinMesHeader_t *pmesheader, u8 **data, s32 page);
char *GetSaveNmlName(FldNameData *this, s32 TmnlId);
char *GetSaveSmlName(FldNameData *this, s32 TmnlId);
u8 **GetSpeakerName(instanceMes_tag *pinst);
char *GetTag(s32 id);
itfMesBinTypeHeader_t *GetTypeHeader(instanceMes_tag *pinst, s32 index);
void Hide(talkUI *this);
void InitializeSelectWindow(_FRQ *pFRQ, s32 max);
bool IsConstantsVoice(char *name);
bool IsFadeOutWindow(void);
bool IsSelectWindowDispOn(void);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Log(char *fmt, void **parray);
_FRQ *MessageRequestEx2(s32 X, s32 Y, u32 Z, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ);
_FRQ *MessageRequestExLocalize(s32 x, s32 y, u8 Style, u8 ColNo, u8 Tp, u8 Spd, u8 **pMsg, _FRQ *pFRQ);
bool MsgWndActiveSelf(s32 i);
void MsgWndSetActive(s32 i, bool sw);
void OpenCheckSpeakerWindow(instanceMes_tag *pinst);
void OpenMessageWindow(instanceMes_tag *pinst);
void PlayVoice(char *name);
void ReadytoMessage(instanceMes_tag *pinst, s32 mode);
void ReleaseAllWindow(instanceMes_tag *pinst);
char *RepColTag(char *txt, void **LegacyParamArray);
char *ReplaceVoice(char *id);
void ResetWindowPara(window_tag *pwin, s32 type, s32 alpha);
s32 SelectItem(instanceMes_tag *pinst);
s32 SelectItemDefKey(select_tag *psel);
void SelectItemMove(select_tag *psel, s32 direct);
void SelectWindowDispOff(instanceMes_tag *pinst);
void SelectWindowDispOn(instanceMes_tag *pinst);
void SetKutiName(btlKutiManager *this, char *name);
void SetMessage(void *obj, s32 line, char *text);
void SetVar(instanceMes_tag *pinst, s32 index, char *pstr, s32 length);
void SlideUpDownMessage(instanceMes_tag *pinst, s32 y);
void StopKuti(btlKutiManager *this);
void StopVoice_Compulsion(void);
void SwitchOK(bool sw);
void SwitchSpeaker(bool sw, bool disp);
s32 ToSpeed(s32 speed);
_FRQ *UnchainFontHandleUnit(_FRQ *pfont, s32 index, s32 lines);
void WindowDispOff(bool sw);
void WindowDispOn_20618496(instanceMes_tag *pinst);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s8 fclChkSignal(s8 Idx);
void fclClearSignal(s8 Idx);
void fldPanelSet(s32 mode);
_FRQ *frDestroyFontRequestAfter(_FRQ *pFRQ);
s32 frDrawFont(_FRQ *pFRQ);
char *frGetCNameString(s8 TargetNo);
void frSetVariableRequest(s32 VarNo, char *pStr);
void itfMesMngChangeWindowType(s32 id, s32 type, s32 alpha);
void itfMesMngMsgWndCls(s32 msgid);
s32 itfMesMngRequestMessage(s32 id, s32 message, s32 page, s32 callmode);
void itfMesMngRequestMessageRelease(s32 id, s32 cls_speaker);
void itfMesMngRequestSelect(s32 id, s32 select);
void itfMesMngRequestSelectRelease(s32 id);
void *itfMesMngSetResourcePtr(s32 id, void *presource);
void itfMesMngSetSelect(s32 id, s32 selno);
s32 itfMesMngSetSelectDefKey(s32 id, s32 key, s32 index);
void itfMesMngSetVar(s32 id, s32 index, s32 num, s32 type);
void itfMesMngSetVarImmediate(s32 id, s32 index, char *pstr);
void itfMesMngSetVarImmediate2(s32 id, s32 index, char *pstr, s32 length);
void itfMesPos(s32 x, s32 y);
void itfMesPosDefault(void);
void itfMiscDrawAlphaPrim(sdfDrawTag_t *pdrawtag, s32 tp, s32 context);
void itfMiscDrawLineStripPrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, s32 num, u32 z, sdfDrawTag_t *pdrawtag);
void itfMiscDrawRectanglePrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, u32 z, sdfDrawTag_t *pdrawtag);
void itfMiscDrawSpritePlanePrim(sdfIVector4_t *pos, sdfIVector4_t *color, u32 z, s32 context, sdfDrawTag_t *pdrawtag);
void itfMiscDrawSpritePrim(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, sdfTexHandle_t *texhandle, s32 context, sdfDrawTag_t *pdrawtag);
void itfMiscLinkGive(mesflow_tag *pelem, itfmisclinkstack_t *pstack);
void itfMiscLinkInitialize(itfmisclinkstack_t *pstack, mesflow_tag ***ptop, s32 numelem);
mesflow_tag *itfMiscLinkTake(itfmisclinkstack_t *pstack);
void itfPnlDraw(itfpanel_t *handle, sdfGrOt_t *pot);
itfpanel_t *itfPnlRegist2(s32 type, sdfTexHandle_t *texhandle);
void itfPnlRelease(itfpanel_t *handle);
void itfPnlSetColor(itfpanel_t *handle, s32 r, s32 g, s32 b, s32 a);
void itfPnlSetPosition(itfpanel_t *handle, s32 x0, s32 y0, s32 x1, s32 y1, u32 z);
void itfPnlSetPositionOffset(itfpanel_t *handle, s32 x0, s32 y0, s32 x1, s32 y1, u32 z);
s32 p2sdPlaySE(s32 a);
s32 scrGetIntPara(s32 n);
s32 scrGetMessageHandle(void);
void scrSetIntReturnValue(s32 i);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);

// 0x13ae810
void CalcCurCtr(instanceMes_tag *pinst) {
  struct curctr_tag_o *curctr;
  u8 isdraw;
  s32 ctr1;
  s32 v5;
  s32 v6;
  s16 v7;

  curctr = pinst->curctr;
  isdraw = curctr->isdraw;
  if (isdraw)
  {
    ctr1 = curctr->ctr1;
    if (ctr1 >= 1)
      curctr->ctr1 = ctr1 - 8;
    if (curctr->phase == 1)
    {
      if ((isdraw & 1) != 0)
        v6 = 32;
      else
        v6 = 64;
      v7 = curctr->ctr0 - 8;
      curctr->ctr0 = v7;
      if (v6 >= v7)
      {
        curctr->phase = 0;
        curctr->ctr0 = v6;
      }
    }
    else if (!curctr->phase)
    {
      v5 = (curctr->ctr0 + 8);
      curctr->ctr0 += 8;
      if (v5 >= 255)
      {
        *&curctr->phase = 16711681;
        curctr->ctr1 = 128;
      }
    }
  }
}

// 0x13ba0d0
dds3ProcessFunc_t *CalcManagerProc(dds3ProcessID_t *proc_id) {
  itfMesManager_c *v2;
  struct mesflow_tag_o *puse_top;
  instanceMes_tag_o *pinst;
  mesflow_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v10[3];

  puse_top = g_manager->linkstack->puse_top;
  if (puse_top)
  {
    pinst = puse_top->pinst;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_12;
LABEL_10:
LABEL_12:
    while (1)
    {
      CalcMesFlow(pinst);
      puse_top = puse_top->linkheader->pnext;
      if (!puse_top)
        break;
      klass = puse_top->klass;
      if (puse_top->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mesflow_tag)
      {
        sub_8FC2C0(klass->_1.element_class, mesflow_tag, v10);
        if ((v10[0] & 1) != 0)
          v7 = v10[2];
        else
          v7 = v10 + 1;
        v8 = sub_8C4940(v7);
      }
      pinst = puse_top->pinst;
        goto LABEL_10;
    }
  }
  return 0;
}

// 0x13ad9f0
void CalcMesFlow(instanceMes_tag *pinst) {
  struct curctr_tag_o *curctr;
  u8 isdraw;
  s32 ctr1;
  s32 v8;
  s32 v9;
  s16 v10;

  CalcWindow(pinst);
  CalcMessage(pinst);
  CalcSelect(pinst);
  curctr = pinst->curctr;
  isdraw = curctr->isdraw;
  if (isdraw)
  {
    ctr1 = curctr->ctr1;
    if (ctr1 >= 1)
      curctr->ctr1 = ctr1 - 8;
    if (curctr->phase == 1)
    {
      if ((isdraw & 1) != 0)
        v9 = 32;
      else
        v9 = 64;
      v10 = curctr->ctr0 - 8;
      curctr->ctr0 = v10;
      if (v9 >= v10)
      {
        curctr->phase = 0;
        curctr->ctr0 = v9;
      }
    }
    else if (!curctr->phase)
    {
      v8 = (curctr->ctr0 + 8);
      curctr->ctr0 += 8;
      if (v8 >= 255)
      {
        *&curctr->phase = 16711681;
        curctr->ctr1 = 128;
      }
    }
  }
}

// 0x13ade50
void CalcMessage(instanceMes_tag *pinst) {
  struct message_tag_o *message;
  u32 stat;
  s32 v7;
  s32 v10;
  evtKutiManager_o *KutiManager;
  s32 OK;
  s32 CANCEL;
  struct _FRQ_o *pfont;
  struct _FRQ_o *v23;
  s16 v25;
  variable_tag_o *variable;
  Il2CppObject *pext;

  message = pinst->message;
  if (message->phase != 1)
    return;
  if ((pinst->stat & 7) != 4)
  {
    else if (!DDS3_PADCHECK_TRIG(OK))
    {
LABEL_65:
      if (!DDS3_PADCHECK_TRIG(CANCEL))
      {
        if (!DDS3_PADCHECK_PRESS(2))
          return;
      }
    }
    if ((pinst->stat & 0x400000) == 0)
    {
      pfont = message->pfont;
      for (; pfont; pfont = pfont->prev)
      {
        {
          pfont->draw_spd = 0x80;
          pfont = pfont->prev;
          if (!pfont)
            goto LABEL_90;
        }
        pfont->draw_spd = 0x80;
      }
LABEL_90:
      v23 = pinst->speaker->pfont;
      if (v23)
      {
        v23->draw_spd = 0x80;
      }
    }
    return;
  }
  if (fclChkSignal(7) == 1 && message->page + 1 >= message->maxpage)
  {
    fclClearSignal(7);
  }
  ++pinst->curctr->ctr_key;
  stat = pinst->stat;
  if ((stat & 0x800000) != 0)
    goto LABEL_123;
  if ((stat & 0x100000) == 0)
    pinst->curctr->isdraw = 1;
  v7 = OK;
  if (DDS3_PADCHECK_TRIG(v7))
    goto LABEL_126;
  v10 = CANCEL;
  if (DDS3_PADCHECK_TRIG(v10))
    goto LABEL_126;
  if (DDS3_PADCHECK_PRESS(2) && pinst->curctr->ctr_key > 4 || !message->wait)
  {
LABEL_126:
    if (message->wait)
    {
      if (cfgGetBit(2u))
      {
        if (bVoicePlaySw)
        {
          KutiManager = GetKutiManager();
          if (op_Inequality(KutiManager, 0, 0))
            StopKuti(KutiManager);
          StopVoice_Compulsion();
          {
LABEL_102:
            bVoicePlaySw = 0;
            bNowSpeaking = 2;
            SwitchOK(0);
            v25 = message->page + 1;
            message->page = v25;
            if (message->maxpage > v25)
            {
              variable = pinst->variable;
              CommitVarTable(variable);
              pext = pinst->pext;
              if (pext)
              {
                il2cp::SizeOf(pext, qword_3F088F8);
              }
              ReadytoMessage(pinst, 0);
              if (message->callmode == 1)
              {
                CallEventVoice(pinst);
              }
              OpenCheckSpeakerWindow(pinst);
              pinst->stat = pinst->stat & 0xFFFFFFF8 | 3;
              return;
            }
LABEL_123:
            message->phase = -1;
            return;
          }
LABEL_100:
          goto LABEL_102;
        }
      }
      p2sdPlaySE(9);
    }
      goto LABEL_102;
    goto LABEL_100;
  }
}

// 0x13ae460
void CalcSelect(instanceMes_tag *pinst) {
  struct select_tag_o *select;
  struct message_tag_o *message;
  u32 stat;
  struct _FRQ_o *pfont;
  struct _TEXT_o *i;
  System_String_o **v9;
  System_String_o *v10;
  s16 v11;
  _FRQ_o *v14;
  s32 v15;
  s32 lines;
  s32 v19;
  u32 mask;
  struct curctr_tag_o *curctr;
  s32 v23;
  struct curctr_tag_o *v24;
  struct _FRQ_o *prev;
  struct _TEXT_o *j;
  struct System_Int32_array *pm;

  select = pinst->select;
  message = pinst->message;
  stat = pinst->stat;
  switch (select->phase)
  {
    case 1:
      if ((pinst->stat & 0xC00) != 0x400)
      {
        pfont = message->pfont;
        if (pfont)
        {
          do
          {
            for (i = pfont->str; i; i = i->next)
              i->col_no = 3;
            pfont = pfont->prev;
          }
          while (pfont);
          stat = pinst->stat;
        }
        pinst->stat = stat & 0xFFFFFFC7 | 0x18;
        if (select->numdef)
          v9 = &"EVENT02";
        else
          v9 = &"EVENT01";
        v10 = *v9;
        ButtonGuideDispSet(v10, 0, 0, 90);
        v11 = 2;
        goto LABEL_55;
      }
      break;
    case 2:
      if ((pinst->stat & 0x38) == 0x20)
      {
        if (SelectItem(pinst) == 1)
        {
          v14 = select->pfont;
          v15 = select->select;
          lines = select->lines;
          select->pfont = UnchainFontHandleUnit(v14, v15, lines);
          if ((stat & 0xC00) == 0x800)
            pinst->stat |= 0xC00u;
          v19 = select->select;
          mask = select->mask;
          select->select = GetMaskedIndex(v19, mask);
          select->numdef = 0;
          curctr = pinst->curctr;
          *&curctr->phase = 8323073;
          curctr->ctr1 = 0;
          pinst->stat = pinst->stat & 0xFFFFFFC7 | 0x28;
          ButtonGuideDispOff();
          select->alpha = 128;
          v11 = 3;
          goto LABEL_55;
        }
      }
      break;
    case 3:
      v23 = (select->alpha - 16);
      select->alpha -= 16;
      if (v23 <= 0)
      {
        select->alpha = 0;
        select->phase = 4;
        v24 = pinst->curctr;
        v24->isdraw = 0;
        v24->ctr1 = 0;
        *&v24->phase = 0x400000;
        v24->ctr_key = 0;
        LOWORD(v23) = select->alpha;
      }
      prev = select->pfont;
      for (; prev; prev = prev->prev)
      {
        for (j = prev->str; j; j = j->next)
          j->color = j->color & 0xFFFFFF00 | v23;
      }
      break;
    case 4:
      if (!message->pfont)
        goto LABEL_54;
      pm = message->pos->pm;
      if (pm->m_Items[1] <= 6317)
      {
        SlideUpDownMessage(pinst, 144);
      }
      else
      {
LABEL_54:
        v11 = -1;
LABEL_55:
        select->phase = v11;
      }
      break;
    default:
      return;
  }
}

// 0x13adb00
void CalcWindow(instanceMes_tag *pinst) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  struct window_tag_o *window;
  struct itfpanel_t_o *mes;
  struct System_Int32_array *v9;
  struct System_Int32_array *pm;
  s32 v12;
  s32 v14;
  struct System_Int32_array *v16;
  struct System_Int32_array *v18;
  u32 stat;
  s32 v22;
  struct System_Int32_array *v24;
  struct System_Int32_array *v26;
  s32 v27;
  struct System_Int32_array *v29;
  struct System_Int32_array *v30;
  s32 v32;

  v3 = Allocate(itfpanel_t);
  v4 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v4);
  v3[2].klass = v4;
  v5 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v5);
  v3[2].monitor = v5;
  _ctor(v3, 0);
  window = pinst->window;
  mes = window->mes;
  if ((pinst->stat & 0x300) == 0x300)
  {
    pm = mes->color->pm;
    v12 = pm->m_Items[3];
    v14 = v12 - ToSpeed(8);
    pm->m_Items[3] = v14;
    v16 = mes->color->pm;
    if (v16->m_Items[3] <= 0)
    {
      v18 = mes->color->pm;
      v18->m_Items[3] = 0;
      pinst->stat &= 0xFFFFFCFF;
      ClearMessage();
      stat = pinst->stat;
      v22 = stat & 0x3000;
      if (v22 != 12288)
        goto LABEL_38;
LABEL_40:
      pinst->stat = stat & 0xFFFFCFFF;
      window->spk = 0;
      return;
    }
  }
  else if ((pinst->stat & 0x300) == 0x100)
  {
    v9 = mes->color->pm;
    v9->m_Items[3] += 24;
    v24 = mes->color->pm;
    v26 = window->mes_color->pm;
    v27 = v24->m_Items[3];
    if (v27 >= v26->m_Items[3])
    {
      v29 = mes->color->pm;
      v30 = window->mes_color->pm;
      v32 = v30->m_Items[3];
      v29->m_Items[3] = v32;
      pinst->stat = pinst->stat & 0xFFFFFCF8 | 0x203;
    }
  }
  stat = pinst->stat;
  v22 = stat & 0x3000;
  if (v22 == 12288)
    goto LABEL_40;
LABEL_38:
  if (v22 == 4096)
    pinst->stat = stat & 0xFFFFCFFF | 0x2000;
}

// 0x13ae8a0
void CallEventVoice(instanceMes_tag *pinst) {
  struct _FRQ_o *pfont;
  System_String_o *tag_id;
  System_String_o *v6;
  System_String_o *v8;
  evtKutiManager_o *KutiManager;
  System_String_o *v12;
  System_String_o *v16;
  s32 result;

  result = 0;
  pfont = pinst->message->pfont;
  if (pfont)
  {
    tag_id = pfont->tag_id;
    TagName = tag_id;
    VoiceName = "";
    if (!IsNullOrEmpty(tag_id))
    {
      v6 = Replace_5267216(tag_id, "<", "");
      v8 = Replace_5267216(v6, ">", "");
      bVoicePlaySw = 0;
      VoiceName = v8;
      result = -1;
      KutiManager = GetKutiManager();
      v12 = Substring_5248048(v8, 1, 3);
      if (TryParse(v12, &result, 0))
        goto LABEL_46;
      if (!check_aimsg(v8))
      {
LABEL_46:
        {
        }
        if (IsConstantsVoice(v8))
        {
          {
          }
          v16 = ReplaceVoice(v8);
          VoiceName = Concat_5221536(VoiceName, " / VOICE=", v16);
          if (op_Inequality(KutiManager, 0, 0))
            SetKutiName(KutiManager, v16);
          PlayVoice(v16);
          bVoicePlaySw = 1;
        }
      }
    }
  }
}

// 0x13abe50
void ChangeFontAlpha(_FRQ *pfont, s32 alpha) {
  struct _TEXT_o *i;

  for (; pfont; pfont = pfont->prev)
  {
    for (i = pfont->str; i; i = i->next)
      i->color = i->color & 0xFFFFFF00 | alpha;
  }
}

// 0x13ac300
void ChangeFontColor(_FRQ *pfont, s32 index, s32 lines, s32 color) {
  s32 y;
  s32 v6;
  s32 v7;
  bool v8;
  struct _TEXT_o *i;

  y = pfont->y;
  v6 = ~index + lines;
  if (v6 < 1)
  {
    v7 = pfont->y;
  }
  else
  {
    do
    {
      while (1)
      {
        v7 = pfont->y;
        if (y != v7)
          break;
        pfont = pfont->prev;
        if (!pfont)
          return;
      }
      v8 = v6-- < 2;
      y = pfont->y;
    }
    while (!v8);
  }
  do
  {
    for (i = pfont->str; i; i = i->next)
      i->col_no = color;
    pfont = pfont->prev;
  }
  while (pfont && v7 == pfont->y);
}

// 0x13ac370
void ChangeFontColorAll(_FRQ *pfont, s32 color) {
  struct _TEXT_o *i;

  for (; pfont; pfont = pfont->prev)
  {
    for (i = pfont->str; i; i = i->next)
      i->col_no = color;
  }
}

// 0x13ac2d0
void ChangeFontPosition(_FRQ *pfont, s32 dist_x, s32 dist_y) {
  s32 y;

  for (; pfont; pfont = pfont->prev)
  {
    y = pfont->y;
    pfont->x += dist_x;
    pfont->y = y + dist_y;
  }
}

// 0x13abe80
void ChangeSelection(s32 index, s32 onoff) {
  u64 *v5;
  System_String_o *v7;
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v11;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GameObject_o *v16;
  Il2CppObject *Component_object;
  System_String_o *text;
  s32 v19;
  s32 v20;
  s32 Length;
  System_Object_array *v22;
  s32 v23;
  System_Object_array *v24;
  s64 *v25;
  s64 *v28;
  System_String_o *v30;
  UnityEngine_Transform_o *v31;
  UnityEngine_Component_o *v32;
  UnityEngine_GameObject_o *v33;
  s32 v35;
  s32 v36;

  v36 = index + 1;
  v5 = sub_8D3950(s32, &v36);
  v7 = Format("choice_answer{0:D2}", v5, 0);
  Item = _get_Item(
           MsgWnd,
           MsgWndIndex + 2);
  transform = get_transform(Item, 0);
  v11 = Find(transform, v7, 0);
  gameObject = get_gameObject(v11);
  v13 = get_transform(gameObject, 0);
  v14 = Find(v13, "answer01TM", 0);
  v16 = get_gameObject(v14);
  if (op_Inequality(v16, 0, 0))
  {
    Component_object = GetComponent_object_(v16);
    text = get_text(Component_object);
    v19 = IndexOf(text, 0x3Eu, 0);
    if (v19 != -1)
    {
      v20 = v19;
      Length = get_Length(text);
      text = Substring_5248048(text, v20 + 1, Length + ~v20);
    }
    v22 = NewSpecific(object, 1u);
    if (onoff == 1)
      v23 = 8;
    else
      v23 = 22;
    v35 = v23;
    v24 = v22;
    v25 = sub_8D3950(UI_COL, &v35);
    v28 = v25;
    v24->m_Items[0] = v28;
    v30 = RepColTag(text, v24);
    set_text(Component_object, v30);
  }
  v31 = get_transform(gameObject, 0);
  v32 = Find(v31, "choice_cursur", 0);
  v33 = get_gameObject(v32);
  SetActive(v33, onoff == 1, 0);
}

// 0x13a9f90
void ChangeZBuffer(_FRQ *pfont, u32 z) {
  for (; pfont; pfont = pfont->prev)
    pfont->priority = z;
}

// 0x13a8f50
s32 CheckMessageBinary(itfMesBinFileHeader_t *pdata) {
  return (pdata->mgc | 0x1000000) == 826757965;
}

// 0x13a9950
void ClearMessage(void) {
  System_WeakReference_o *Item;
  System_WeakReference_o *v7;
  System_WeakReference_o *v11;

  Item = _get_Item(
           MsgWnd,
           MsgWndIndex);
  SetMessage(Item, 0, "<alpha=#00>あああああ</alpha>");
  v7 = _get_Item(
         MsgWnd,
         MsgWndIndex);
  SetMessage(v7, 1, "<alpha=#00>あああああ</alpha>");
  v11 = _get_Item(
          MsgWnd,
          MsgWndIndex);
  SetMessage(v11, 2, "<alpha=#00>あああああ</alpha>");
}

// 0x13aa9f0
void ClearSpeaker(void) {
  UnityEngine_Object_o *SpkWndTMP;
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;

  if (op_Inequality(SpkWndTMP, 0, 0))
  {
    set_text(SpkWndTMP, "");
  }
  Item = _get_Item(
           MsgWnd,
           MsgWndIndex + 1);
  Component_object = GetComponent_object_(Item);
  DisplayOff(Component_object);
}

// 0x13ab3f0
void CommitVarTable(variable_tag *pvar) {
  u64 *v3;
  u64 i;
  struct System_String_array *pptr;
  struct System_String_array *v9;
  System_String_o *v11;

  v3 = Allocate(System_Collections_Generic_List_byte_);
  __ctor(v3);
  for (i = 0; i != 32; ++i)
  {
    _Clear(v3);
    pptr = pvar->pptr;
    if (!IsNullOrEmpty(pptr->m_Items[i]))
    {
      v9 = pvar->pptr;
      v11 = v9->m_Items[i];
      frSetVariableRequest(i, v11);
    }
  }
}

// 0x13ad600
void ConvertZenkakuNumber(char **buf, s32 num) {
  u32 *v5;
  u32 *v6;
  u64 v7;
  u32 v17;
  System_String_o *v19;
  System_String_o *v21;
  bool v22;

  v5 = NewSpecific(s32, 0xAu);
  v6 = v5;
  v5[8] = num % 10;
  if (num >= 10)
  {
    v5[9] = num / 0xAu % 0xA;
    if (num >= 100)
    {
      v5[10] = num / 0x64u % 0xA;
      if (num >= 1000)
      {
        v5[11] = num / 0x3E8u % 0xA;
        if (num >= 10000)
        {
          v5[12] = num / 0x2710u % 0xA;
          if (num >= 100000)
          {
            v5[13] = num / 0x186A0u % 0xA;
            if (num >= 1000000)
            {
              v5[14] = num / 0xF4240u % 0xA;
              if (num >= 10000000)
              {
                v5[15] = num / 0x989680u % 0xA;
                if (num >= 100000000)
                {
                  v5[16] = num / 0x5F5E100u % 0xA;
                  if (num >= 1000000000)
                  {
                    v17 = num / 0x3B9ACA00u;
                    v5[17] = v17;
                    v7 = 9;
                  }
                  else
                  {
                    v7 = 8;
                  }
                }
                else
                {
                  v7 = 7;
                }
              }
              else
              {
                v7 = 6;
              }
            }
            else
            {
              v7 = 5;
            }
          }
          else
          {
            v7 = 4;
          }
        }
        else
        {
          v7 = 3;
        }
      }
      else
      {
        v7 = 2;
      }
    }
    else
    {
      v7 = 1;
    }
  }
  else
  {
    v7 = 0;
  }
  v19 = *buf;
  do
  {
    v21 = Substring_5248048("０１２３４５６７８９", v6[v7 + 8], 1);
    v19 = Concat_5224608(v19, v21);
    v22 = v7-- <= 0;
    *buf = v19;
  }
  while (!v22);
}

// 0x13a9fd0
s32 CountLineMessage(_FRQ *pfont_top, _FRQ *pfont) {
  s64 v3;

  v3 = 715827883LL * ((pfont->y - pfont_top->y) >> 3);
  return (v3 >> 34) + (v3 >> 63) + 1;
}

// 0x13a8610
char *DAT_STR_REF_DHNAME(s32 idx) {
  return Get(idx, 0);
}

// 0x13a84c0
char *DAT_STR_REF_DVNAME(s32 idx) {
  return GetTag(idx, 0);
}

// 0x13a85a0
char *DAT_STR_REF_ITNAME(s32 idx) {
  return Get(idx, 0);
}

// 0x13a8450
char *DAT_STR_REF_RCNAME(s32 idx) {
  return Get(idx, 0, 0);
}

// 0x13a8530
char *DAT_STR_REF_SKNAME(s32 idx) {
  return Get(idx, 0, 0);
}

// 0x13b62c0
mesflow_tag *DebugChangeInstance(mesflow_tag *pflow) {
  s32 numuse;
  s32 v5;
  mesflow_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  numuse = g_manager->numuse;
  if (numuse < 1)
    return 0;
  v5 = -1;
  while (1)
  {
    if (pflow && (pflow = pflow->linkheader->pprev) != 0)
    {
      klass = pflow->klass;
      if (pflow->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mesflow_tag)
      {
        sub_8FC2C0(klass->_1.element_class, mesflow_tag, v11);
        if ((v11[0] & 1) != 0)
          v8 = v11[2];
        else
          v8 = v11 + 1;
        v9 = sub_8C4940(v8);
      }
    }
    else
    {
      pflow = g_manager->linkstack->puse_tail;
    }
    if (pflow->pinst->window->mes)
      break;
    if (++v5 >= numuse)
      return 0;
  }
  return pflow;
}

// 0x13b8070
void DebugDrawWindowLine(itfpanel_t *meswin) {
  System_Array_o *v3;
  System_Byte_array *v4;
  sdfIVector4_t_array *v5;
  sdfIVector4_t_o *v6;
  System_Array_o *v7;
  sdfIVector2_t_array *v9;
  sdfIVector2_t_o *v10;
  struct System_Int32_array *v11;
  struct System_Int32_array *pm;
  s32 v13;
  struct System_Int32_array *v14;
  s32 v15;
  sdfIVector2_t_o *v19;
  struct System_Int32_array *v20;
  struct System_Int32_array *v21;
  s32 v23;
  struct System_Int32_array *v25;
  s32 v26;
  sdfIVector2_t_o *v30;
  struct System_Int32_array *v31;
  struct System_Int32_array *v32;
  s32 v34;
  struct System_Int32_array *v36;
  s32 v37;
  sdfIVector2_t_o *v41;
  struct System_Int32_array *v42;
  struct System_Int32_array *v43;
  s32 v44;
  struct System_Int32_array *v45;
  s32 v46;
  u64 *v50;
  struct sdfGrOt_t_array *dds3Ot;

  v3 = NewSpecific(byte, 5u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__4D8FA9E7DE487B9BD68773D30B62B436B9D121E9);
  v4 = NewSpecific(byte, 5u);
  v5 = NewSpecific(sdfIVector4_t, 1u);
  v6 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v6);
  v7 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v7, Field__PrivateImplementationDetails__C012C3EFDBB25A56012CB7B9EEB5A7C67106F98C);
  v6->pm = v7;
  v5->m_Items[0] = v6;
  v9 = NewSpecific(sdfIVector2_t, 4u);
  v10 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v10);
  v11 = NewSpecific(s32, 2u);
  pm = meswin->pos->pm;
  v13 = pm->m_Items[0];
  v11->m_Items[0] = v13;
  v14 = meswin->pos->pm;
  v15 = v14->m_Items[1];
  v11->m_Items[1] = v15;
  v10->pm = v11;
  v9->m_Items[0] = v10;
  v19 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v19);
  v20 = NewSpecific(s32, 2u);
  v21 = meswin->pos->pm;
  v23 = v21->m_Items[2];
  v20->m_Items[0] = v23;
  v25 = meswin->pos->pm;
  v26 = v25->m_Items[1];
  v20->m_Items[1] = v26;
  v19->pm = v20;
  v9->m_Items[1] = v19;
  v30 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v30);
  v31 = NewSpecific(s32, 2u);
  v32 = meswin->pos->pm;
  v34 = v32->m_Items[2];
  v31->m_Items[0] = v34;
  v36 = meswin->pos->pm;
  v37 = v36->m_Items[3];
  v31->m_Items[1] = v37;
  v30->pm = v31;
  v9->m_Items[2] = v30;
  v41 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v41);
  v42 = NewSpecific(s32, 2u);
  v43 = meswin->pos->pm;
  v44 = v43->m_Items[0];
  v42->m_Items[0] = v44;
  v45 = meswin->pos->pm;
  v46 = v45->m_Items[3];
  v42->m_Items[1] = v46;
  v41->pm = v42;
  v9->m_Items[3] = v41;
  v50 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v50);
  sdfDrawTagInit(v50);
  itfMiscDrawLineStripPrim(v9, 0, v5, v3, v4, 5, 0xFFFFFFu, v50);
  sdfDrawTagLinkOt(dds3Ot->m_Items[81], v50);
}

// 0x13b68d0
void DebugMoveWinAlpha(window_tag *pwin) {
  s32 v4;
  s32 v7;
  s32 OK;
  s32 v10;
  struct System_Int32_array *pm;
  struct System_Int32_array *v13;
  struct itfpanel_t_o *mes;
  struct System_Int32_array *v16;
  struct System_Int32_array *v17;
  s32 v19;

  else if (DDS3_PAD2CHECK_REP(4))
  {
    goto LABEL_6;
  }
  v4 = DDS3_PAD2CHECK_REP(5);
  {
LABEL_15:
    if (!DDS3_PAD2CHECK_REP(6))
      goto LABEL_17;
LABEL_16:
    v7 = -1;
    goto LABEL_23;
  }
LABEL_7:
    goto LABEL_15;
  if (DDS3_PAD2CHECK_REP(6))
    goto LABEL_16;
LABEL_17:
  if (DDS3_PAD2CHECK_REP(7))
    v7 = 1;
  else
    v7 = v4;
LABEL_23:
  if (DDS3_PAD2CHECK_PRESS(OK))
    v10 = 10 * v7;
  else
    v10 = v7;
  if (v10)
  {
    pm = pwin->mes_color->pm;
    pm->m_Items[3] += v10;
    v13 = pwin->mes_color->pm;
    v13->m_Items[3] = LOBYTE(v13->m_Items[3]);
    mes = pwin->mes;
    if (mes)
    {
      v16 = mes->color->pm;
      v17 = pwin->mes_color->pm;
      v19 = v17->m_Items[3];
      v16->m_Items[3] = v19;
    }
  }
}

// 0x13b6450
void DebugMoveWinVert(window_tag *pwin, s32 flag) {
  struct sdfIVector4_t_o *mes_offset;
  s32 v7;
  s32 v10;
  s32 OK;
  bool v13;
  s32 v15;
  s32 v16;
  itfpanel_t_o *v17;
  struct System_Int32_array *v18;
  struct System_Int32_array *v20;
  s32 *v21;
  s32 v22;
  s32 v23;
  itfpanel_t_o *mes;
  struct System_Int32_array *pm;
  struct System_Int32_array *v27;
  itfpanel_t_o *v28;
  struct System_Int32_array *v29;
  struct System_Int32_array *v33;
  s32 v34;

  if (!pwin->mes)
    return;
  mes_offset = pwin->mes_offset;
  if (!DDS3_PAD2CHECK_REP(4))
    goto LABEL_17;
LABEL_7:
  v7 = -16;
    goto LABEL_24;
LABEL_8:
LABEL_24:
  if (DDS3_PAD2CHECK_REP(6))
    goto LABEL_25;
LABEL_10:
  if (DDS3_PAD2CHECK_REP(7))
    v10 = 8;
  else
    v10 = 0;
LABEL_26:
  v13 = DDS3_PAD2CHECK_PRESS(OK);
  if (v13)
    v15 = 8 * v10;
  else
    v15 = v10;
  if (v13)
    v16 = 8 * v7;
  else
    v16 = v7;
  if (v16 | v15)
  {
    if (flag == 2)
    {
      mes = pwin->mes;
      itfPnlSetPositionOffset(mes, v16, v15, v16, v15, 0);
      pm = mes_offset->pm;
      pm->m_Items[0] += v16;
      v27 = mes_offset->pm;
      v27->m_Items[1] += v15;
      v29 = mes_offset->pm;
      if (LODWORD(v29->max_length) >= 3)
        goto LABEL_65;
    }
    else
    {
      if (flag != 1)
      {
        if (flag)
          return;
        v17 = pwin->mes;
        itfPnlSetPositionOffset(v17, v16, v15, 0, 0, 0);
        v18 = mes_offset->pm;
        v18->m_Items[0] += v16;
        v20 = mes_offset->pm;
        v22 = v20->m_Items[1];
        v21 = &v20->m_Items[1];
        v23 = v22 + v15;
        goto LABEL_68;
      }
      v28 = pwin->mes;
      itfPnlSetPositionOffset(v28, 0, 0, v16, v15, 0);
      v29 = mes_offset->pm;
      if (LODWORD(v29->max_length) >= 3)
      {
LABEL_65:
        v29->m_Items[2] += v16;
        v33 = mes_offset->pm;
        v34 = v33->m_Items[3];
        v21 = &v33->m_Items[3];
        v23 = v34 + v15;
LABEL_68:
        *v21 = v23;
        return;
      }
    }
  }
}

// 0x13aad00
s32 DebugWindowSwitch(s32 itfon) {
  char v2;
  bool v4;
  s32 v7;
  s32 v10;
  s32 v12;
  s32 v13;
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;
  System_WeakReference_o *v24;
  Il2CppObject *v25;

  v2 = itfon;
  v4 = !MsgWndActiveSelf(MsgWndIndex);
  if (v4)
    v7 = 0;
  else
    v7 = 2;
  v4 = !MsgWndActiveSelf(MsgWndIndex + 1);
  if (v4)
    v10 = 0;
  else
    v10 = 4;
  if (MsgWndActiveSelf(MsgWndIndex + 2))
    v12 = 8;
  else
    v12 = 0;
  if ((v2 & 1) != 0)
  {
    SetActive(MsgWndOwner, 1, 0);
    if ((v2 & 2) != 0)
    {
      MsgWndSetActive(MsgWndIndex, 1);
      Item = _get_Item(
               MsgWnd,
               MsgWndIndex);
      Component_object = GetComponent_object_(Item);
      Display(Component_object, 1);
      if ((v2 & 4) == 0)
      {
LABEL_31:
        {
LABEL_42:
          MsgWndSetActive(MsgWndIndex + 2, (v2 & 8) != 0);
          v13 = v10 | v7;
          return v13 | v12;
        }
LABEL_32:
        goto LABEL_42;
      }
    }
    else if ((v2 & 4) == 0)
    {
      goto LABEL_31;
    }
    MsgWndSetActive(MsgWndIndex + 1, 1);
    v24 = _get_Item(
            MsgWnd,
            MsgWndIndex + 1);
    v25 = GetComponent_object_(v24);
    Display(v25, 1);
      goto LABEL_42;
    goto LABEL_32;
  }
  v13 = v10 | v7 | 1;
  WindowDispOff(0);
  SwitchSpeaker(0, 0);
  MsgWndSetActive(MsgWndIndex + 2, 0);
  return v13 | v12;
}

// 0x13a8860
void DestructFlow(s32 id) {
  struct mesflow_tag_array *pmesflow;
  mesflow_tag_o *v7;
  instanceMes_tag_o *pinst;
  struct variable_tag_o *variable;
  s64 i;
  struct System_String_array *pptr;
  struct System_String_array *v16;
  itfmisclinkstack_t_o *linkstack;

  pmesflow = g_manager->pmesflow;
  v7 = pmesflow->m_Items[id];
  pinst = v7->pinst;
  if (pinst)
  {
    itfMesMngRequestMessageRelease(id, 1);
    itfMesMngRequestSelectRelease(id);
    ReleaseAllWindow(pinst);
    variable = pinst->variable;
    for (i = 4; i != 36; ++i)
    {
      pptr = variable->pptr;
      if (*(&pptr->obj.klass + i))
      {
        v16 = variable->pptr;
        *(&v16->obj.klass + i) = 0;
      }
    }
    pinst->stat = 0;
    v7->pinst = 0;
    linkstack = g_manager->linkstack;
    itfMiscLinkGive(v7, linkstack);
    --g_manager->numuse;
  }
}

// 0x13ba240
dds3ProcessFunc_t *DrawManagerProc(dds3ProcessID_t *proc_id) {
  itfMesManager_c *v2;
  struct mesflow_tag_o *puse_top;
  instanceMes_tag_o *pinst;
  mesflow_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v10[3];

  puse_top = g_manager->linkstack->puse_top;
  if (puse_top)
  {
    pinst = puse_top->pinst;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_12;
LABEL_10:
LABEL_12:
    while (1)
    {
      DrawMesFlow(pinst);
      puse_top = puse_top->linkheader->pnext;
      if (!puse_top)
        break;
      klass = puse_top->klass;
      if (puse_top->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mesflow_tag)
      {
        sub_8FC2C0(klass->_1.element_class, mesflow_tag, v10);
        if ((v10[0] & 1) != 0)
          v7 = v10[2];
        else
          v7 = v10 + 1;
        v8 = sub_8C4940(v7);
      }
      pinst = puse_top->pinst;
        goto LABEL_10;
    }
  }
  ++g_manager->ctr;
  return 0;
}

// 0x13b7450
void DrawMesFlow(instanceMes_tag *pinst) {
  u32 stat;
  _FRQ_o *pfont;
  _FRQ_o *v7;
  bool v9;
  s32 wait;
  bool IsSelectWindowDispOn;
  struct select_tag_o *select;
  s32 v17;

  stat = pinst->stat;
  g_manager->stat &= ~2u;
  DrawWindow(pinst);
  if ((stat & 0x10000) == 0)
  {
    pfont = pinst->speaker->pfont;
    if (pfont)
    {
      DrawSpeaker(pfont);
    }
  }
  if ((stat & 0x20000) == 0 && (stat & 7) >= 3)
  {
    v7 = pinst->message->pfont;
    if (DrawMessage(v7) >= 1 && (pinst->stat & 7) != 4)
    {
      pinst->stat = pinst->stat & 0xFFFFFFF8 | 4;
      v9 = ChkVoicePlaying();
      if (!v9)
      {
        bNowSpeaking = 3;
      }
      pinst->curctr->ctr_key = 0;
      wait = pinst->message->wait;
      SwitchOK(wait != 0);
    }
  }
  if ((stat & 0x40000) == 0 && (stat & 0x38) >= 0x18)
  {
    IsSelectWindowDispOn = IsSelectWindowDispOn();
    if ((stat & 0x3F) == 0x1C && IsSelectWindowDispOn)
    {
      select = pinst->select;
      v17 = select->select;
      if (v17 == 0xFFFF)
      {
        LOWORD(v17) = 0;
        *&select->select = 0;
      }
      ChangeSelection(v17, 1);
      pinst->stat = pinst->stat & 0xFFFFFFC7 | 0x20;
      pinst->curctr->isdraw = 2;
    }
  }
}

// 0x13b7ad0
s32 DrawMessage(_FRQ *pfont) {
  struct _FRQ_o *head;
  System_String_o *FRQString;
  struct itfMesManager_StaticFields *static_fields;
  u32 v10;
  struct _TEXT_o *str;
  s32 y;
  s32 col_no;
  System_Text_StringBuilder_o *pMsgMes;
  u64 *v16;
  s32 draw_spd;
  struct _TEXT_o *prev;
  u32 color;
  struct _FRQ_o *v20;
  struct _TEXT_o *str_end;
  s32 tp;
  u32 *p_color;
  u32 v24;
  s32 v25;
  u32 v26;
  s32 color_low;
  System_WeakReference_o *Item;
  System_String_o *v31;
  System_String_o *v32;
  u32 v35;
  System_WeakReference_o *v39;
  System_String_o *v40;
  System_String_o *v41;
  s32 v43;
  u32 v44;
  s32 v45;

  if (!pfont)
    return pfont;
  head = pfont->head;
  FRQString = GetFRQString(head);
  if (IsNullOrEmpty(FRQString))
  {
    return frDrawFont(pfont);
  }
  v43 = 3 * MsgWndIndex;
  Clear(pMsgMes, 0);
  LODWORD(pfont) = 1;
  v10 = 0;
  do
  {
    v44 = v10;
    if (!head)
    {
LABEL_62:
      v35 = v44;
        goto LABEL_63;
      goto LABEL_65;
    }
    do
    {
      str = head->str;
      y = head->y;
      col_no = str->col_no;
      v45 = col_no;
      v16 = sub_8D3950(s32, &v45);
      AppendFormat(pMsgMes, "<material=\"MsgFont{0}\">", v16);
      if (pfont == 1)
      {
LABEL_21:
        draw_spd = head->draw_spd;
        else
        {
          prev = str->prev;
          if (prev)
            goto LABEL_24;
LABEL_26:
          v20 = head->prev;
          if (v20)
          {
            str_end = v20->str_end;
            if (str_end)
            {
              color = str_end->color;
              tp = str_end->tp;
              p_color = &str->color;
              v24 = str->color;
              if (tp && tp != str->tp)
              {
                if (color != 128)
                  goto LABEL_42;
LABEL_31:
                LOBYTE(v25) = draw_spd;
                if ((draw_spd & 0x80000000) == 0)
                  v25 = (draw_spd << 6) / (str->lw + head->space);
                if (128 - v24 >= v25)
                  v26 = v24 + v25;
                else
                  v26 = v24 & 0xFFFFFF00 | 0x80;
                *p_color = v26;
                goto LABEL_42;
              }
LABEL_39:
              if (color < 0x1Cu)
                goto LABEL_42;
              goto LABEL_31;
            }
          }
          LOBYTE(color) = 0x80;
        }
        p_color = &str->color;
        v24 = str->color;
        goto LABEL_39;
      }
      while (1)
      {
LABEL_42:
        color_low = LOBYTE(str->color);
        LODWORD(pfont) = pfont & (color_low >> 7);
        if (color_low == 128)
        {
            goto LABEL_50;
LABEL_44:
          goto LABEL_50;
        }
        Append_5380272(pMsgMes, "<alpha=#00>");
          goto LABEL_44;
LABEL_50:
        Append_5387312(pMsgMes, str->chcode);
        str = str->next;
        if (!str)
          break;
        y = head->y;
        if (pfont == 1)
          goto LABEL_21;
      }
      head = head->next;
      if (!head)
        goto LABEL_62;
    }
    while (y == head->y);
    Item = _get_Item(
             MsgWndTMP,
             v44 + v43);
    v31 = (pMsgMes->klass->vtable._3_ToString.methodPtr)(
            pMsgMes,
            pMsgMes->klass->vtable._3_ToString.method);
    v32 = Replace_5267216(v31, "\t", "");
    set_text(Item, v32);
    (Item->klass[4].static_fields)(Item, Item->klass[4].rgctx_data);
    Clear(pMsgMes, 0);
    v10 = v44 + 1;
  }
  while (v44 != 2);
  v35 = 3;
    goto LABEL_65;
LABEL_63:
LABEL_65:
  if (get_Length(pMsgMes))
  {
    if (v35 <= 2)
    {
      v39 = _get_Item(
              MsgWndTMP,
              v35 + v43);
      v40 = (pMsgMes->klass->vtable._3_ToString.methodPtr)(
              pMsgMes,
              pMsgMes->klass->vtable._3_ToString.method);
      v41 = Replace_5267216(v40, "\t", "");
      set_text(v39, v41);
      (v39->klass[4].static_fields)(v39, v39->klass[4].rgctx_data);
    }
    Clear(pMsgMes, 0);
  }
  return pfont;
}

// 0x13b9cf0
void DrawRetPageCursor(instanceMes_tag *pinst) {
  sdfIVector4_t_o *v3;
  System_Array_o *v4;
  sdfIVector4_t_o *v5;
  System_Array_o *v6;
  sdfIVector4_t_o *v7;
  struct curctr_tag_o *curctr;
  struct System_Int32_array *pm;
  struct System_Int32_array *v11;
  struct System_Int32_array *v13;
  u32 max_length;
  struct System_Int32_array *v16;
  u32 v17;
  struct System_Int32_array *v20;
  u64 *v22;
  s32 ctr1;
  struct System_Int32_array *v25;
  s32 v26;
  s32 v27;
  struct System_Int32_array *v28;
  struct System_Int32_array *v31;
  struct System_Int32_array *v33;
  struct System_Int32_array *v35;

  v3 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v3);
  v4 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v4, Field__PrivateImplementationDetails__0698C76BEC55A57DA95EBC93F3B331A3B16A7E92);
  v3->pm = v4;
  v5 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v5);
  v6 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v6, Field__PrivateImplementationDetails__3180B0209A7B4635BC39C905CFF2F36FB10DB548);
  v5->pm = v6;
  v7 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v7);
  curctr = pinst->curctr;
  pm = v7->pm;
  pm->m_Items[0] = 6736;
  v11 = v7->pm;
  v11->m_Items[1] = 3232;
  v13 = v7->pm;
  max_length = v13->max_length;
  v13->m_Items[2] = v13->m_Items[0] + 272;
  v16 = v7->pm;
  v17 = v16->max_length;
  v16->m_Items[3] = v16->m_Items[1] + 136;
  v20 = v5->pm;
  v20->m_Items[3] = curctr->ctr0;
  v22 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v22);
  sdfDrawTagInit(v22);
  ctr1 = curctr->ctr1;
  if (ctr1 >= 1)
  {
    v25 = v7->pm;
    v26 = 128 - ctr1;
    v27 = 2 * (128 - ctr1);
    v25->m_Items[0] -= v27;
    v28 = v7->pm;
    v28->m_Items[1] -= v26;
    v31 = v7->pm;
    v31->m_Items[2] += v27;
    v33 = v7->pm;
    v33->m_Items[3] += v26;
    v35 = v5->pm;
    v35->m_Items[3] = ctr1;
  }
}

// 0x13b8790
void DrawSelectCursor(instanceMes_tag *pinst) {
  sdfIVector2_t_array *v3;
  sdfIVector2_t_o *v4;
  struct System_Int32_array *v6;
  s32 v7;
  s32 v9;
  sdfIVector2_t_o *v12;
  struct System_Int32_array *v13;
  s32 v14;
  s32 v16;
  sdfIVector2_t_o *v19;
  struct System_Int32_array *v20;
  s32 v21;
  s32 v23;
  sdfIVector2_t_o *v26;
  struct System_Int32_array *v27;
  s32 v28;
  s32 v30;
  sdfIVector4_t_array *v33;
  sdfIVector4_t_o *v34;
  struct System_Int32_array *v35;
  u32 max_length;
  sdfIVector4_t_o *v40;
  System_Array_o *v41;
  u64 *v43;
  u32 v44;
  System_Byte_array *v45;
  sdfIVector4_t_o *v47;
  sdfIVector4_t_o *v48;
  sdfIVector4_t_o *v49;
  struct select_tag_o *select;
  s32 select_imm;
  u64 *v52;
  struct System_Int32_array *pm;
  s32 v57;
  struct System_Int32_array *v58;
  s32 v60;
  s32 v61;
  struct System_Int32_array *v62;
  u32 v63;
  s32 v64;
  struct System_Int32_array *v66;
  struct System_Int32_array *v67;
  struct System_Int32_array *v68;
  s32 v69;
  struct System_Int32_array *v71;
  s32 v73;
  s32 v75;
  struct System_Int32_array *v77;
  struct System_Int32_array *v79;
  struct System_Int32_array *v81;
  struct System_Int32_array *v83;
  u64 *v87;
  struct System_Int32_array *v89;
  u32 v90;
  struct System_Int32_array *v91;
  struct System_Int32_array *v92;
  s32 v93;
  struct System_Int32_array *v94;
  struct System_Int32_array *v95;
  s32 v97;
  s32 v98;
  struct System_Int32_array *v100;
  struct System_Int32_array *v111;
  s32 v113;
  u64 *v115;
  struct System_Int32_array *v116;
  struct System_Int32_array *v118;
  instanceMes_tag_o *v119;
  u32 v120;
  struct System_Int32_array *v122;
  s32 v124;
  s32 v125;
  struct System_Int32_array *v127;
  s32 v129;
  s32 v130;
  struct System_Int32_array *v132;
  s32 v133;
  struct System_Int32_array *v135;
  s32 v136;
  struct System_Int32_array *v138;
  s32 v139;
  struct System_Int32_array *v141;
  s32 v143;
  struct System_Int32_array *v145;
  struct System_Int32_array *v147;
  struct System_Int32_array *v149;
  struct System_Int32_array *v151;
  u64 *v154;
  struct System_Int32_array *v155;
  s32 v157;
  s32 v158;
  struct System_Int32_array *v160;
  s32 v162;
  s32 v163;
  struct System_Int32_array *v165;
  s32 v166;
  struct System_Int32_array *v168;
  s32 v169;
  struct System_Int32_array *v171;
  s32 v172;
  struct System_Int32_array *v174;
  s32 v175;
  struct System_Int32_array *v177;
  u64 *v179;
  s32 ctr1;
  struct System_Int32_array *v182;
  s32 v183;
  struct System_Int32_array *v184;
  s32 v185;
  s32 v193;
  struct System_Int32_array *v194;
  struct System_Int32_array *v196;
  struct System_Int32_array *v198;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v207;
  struct curctr_tag_o *curctr;
  System_Array_o *pvertindex;
  instanceMes_tag_o *v211;
  s32 v212;
  u32 z;
  u32 v214;

  v3 = NewSpecific(sdfIVector2_t, 4u);
  v4 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v4);
  v6 = NewSpecific(s32, 2u);
  v7 = CMP_XM(129);
  v6->m_Items[0] = v7;
  v9 = CMP_YM(376);
  v6->m_Items[1] = v9;
  v4->pm = v6;
  v3->m_Items[0] = v4;
  v12 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v12);
  v13 = NewSpecific(s32, 2u);
  v14 = CMP_XM(195);
  v13->m_Items[0] = v14;
  v16 = CMP_YM(376);
  v13->m_Items[1] = v16;
  v12->pm = v13;
  v3->m_Items[1] = v12;
  v19 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v19);
  v20 = NewSpecific(s32, 2u);
  v21 = CMP_XM(195);
  v20->m_Items[0] = v21;
  v23 = CMP_YM(398);
  v20->m_Items[1] = v23;
  v19->pm = v20;
  v3->m_Items[2] = v19;
  v26 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v26);
  v27 = NewSpecific(s32, 2u);
  v28 = CMP_XM(129);
  v27->m_Items[0] = v28;
  v30 = CMP_YM(398);
  v27->m_Items[1] = v30;
  v26->pm = v27;
  v3->m_Items[3] = v26;
  v33 = NewSpecific(sdfIVector4_t, 2u);
  v34 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v34);
  v35 = NewSpecific(s32, 4u);
  max_length = v35->max_length;
  v35->m_Items[0] = 87;
  v35->m_Items[2] = 16;
  v34->pm = v35;
  v33->m_Items[0] = v34;
  v40 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v40);
  v41 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v41, Field__PrivateImplementationDetails__D89A0A163C6675B26F0127CB03FD29EB5150F83E);
  v40->pm = v41;
  v33->m_Items[1] = v40;
  pvertindex = NewSpecific(byte, 4u);
  InitializeArray_1543888(pvertindex, Field__PrivateImplementationDetails__A02A05B025B928C039CF1AE7E8EE04E7C190C0DB);
  v43 = NewSpecific(byte, 4u);
  v44 = *(v43 + 6);
  v45 = v43;
  *(v43 + 32) = 1;
  *(v43 + 35) = 1;
  v47 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v47);
  v48 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v48);
  v49 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v49);
  select = pinst->select;
  select_imm = select->select_imm;
  if (select_imm != 0xFFFF)
  {
    curctr = pinst->curctr;
    v211 = pinst;
    z = pinst->z;
    v52 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v52);
    sdfDrawTagInit(v52);
    pm = select->pos->pm;
    v57 = pm->m_Items[0];
    v212 = v57 - CMP_XM(21);
    v58 = select->pos->pm;
    v60 = v58->m_Items[1];
    v61 = CMP_YM(33 * select->lines - 24);
    v62 = v49->pm;
    v63 = v60 - v61 + vcvts_n_s32_f32((select_imm * 30.0) * 2.25, 3u);
    v64 = CMP_XM(6) + v212;
    v62->m_Items[0] = v64;
    v66 = v49->pm;
    v66->m_Items[1] = v63;
    v67 = v49->pm;
    v68 = v3->m_Items[0]->pm;
    v69 = 2 * v68->m_Items[0];
    v67->m_Items[2] = v69;
    v71 = v49->pm;
    v73 = v71->m_Items[1];
    v75 = CMP_YM(33) + v73;
    v71->m_Items[3] = v75;
    v77 = v48->pm;
    v77->m_Items[0] = 87;
    v79 = v48->pm;
    v79->m_Items[1] = 0;
    v81 = v48->pm;
    v81->m_Items[2] = 16;
    v83 = v48->pm;
    v214 = z >> 4;
    v83->m_Items[3] = 76;
    itfMiscDrawSpritePlanePrim(v49, v48, v214 - 1, 0, v52);
    Draw(gfxMgr, "MsgPanel", 0x4000000u, v52, 0);
    v87 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v87);
    sdfDrawTagInit(v87);
    v89 = v3->m_Items[0]->pm;
    v90 = v63 - CMP_YM(1);
    v89->m_Items[1] = v90;
    v91 = v3->m_Items[1]->pm;
    v92 = v3->m_Items[0]->pm;
    v93 = v92->m_Items[1];
    v91->m_Items[1] = v93;
    v94 = v3->m_Items[2]->pm;
    v95 = v3->m_Items[0]->pm;
    v97 = v95->m_Items[1];
    v98 = CMP_YM(22) + v97;
    v94->m_Items[1] = v98;
    v100 = v3->m_Items[3]->pm;
    v111 = v3->m_Items[2]->pm;
    v113 = v111->m_Items[1];
    v100->m_Items[1] = v113;
    itfMiscDrawRectanglePrim(v3, 0, v33, pvertindex, v45, v214 - 2, v87);
    Draw(gfxMgr, "MsgPanelG", 0x4000000u, v87, 0);
    v115 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v115);
    sdfDrawTagInit(v115);
    v116 = v49->pm;
    v116->m_Items[0] = v212;
    v118 = v49->pm;
    v119 = v211;
    v120 = CMP_YM(1) + v63;
    v118->m_Items[1] = v120;
    v122 = v49->pm;
    v124 = v122->m_Items[0];
    v125 = CMP_XM(6) + v124;
    v122->m_Items[2] = v125;
    v127 = v49->pm;
    v129 = v127->m_Items[1];
    v130 = CMP_YM(16) + v129;
    v127->m_Items[3] = v130;
    v132 = v47->pm;
    v133 = CMP_XM(21);
    v132->m_Items[0] = v133;
    v135 = v47->pm;
    v136 = CMP_XM(47);
    v135->m_Items[1] = v136;
    v138 = v47->pm;
    v139 = CMP_XM(27);
    v138->m_Items[2] = v139;
    v141 = v47->pm;
    v143 = CMP_XM(63);
    v141->m_Items[3] = v143;
    v145 = v48->pm;
    v145->m_Items[0] = 128;
    v147 = v48->pm;
    v147->m_Items[1] = 128;
    v149 = v48->pm;
    v149->m_Items[2] = 128;
    v151 = v48->pm;
    v151->m_Items[3] = 38;
    itfMiscDrawSpritePrim(v49, v47, v48, v214 - 3, g_manager->tex, 0, v115);
    Draw(gfxMgr, "MsgRound", 0x4000000u, v115, 0);
    v154 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v154);
    sdfDrawTagInit(v154);
    v155 = v49->pm;
    v157 = v155->m_Items[0];
    v158 = CMP_XM(16) + v157;
    v155->m_Items[2] = v158;
    v160 = v49->pm;
    v162 = v160->m_Items[1];
    v163 = CMP_YM(24) + v162;
    v160->m_Items[3] = v163;
    v165 = v47->pm;
    v166 = CMP_XM(38);
    v165->m_Items[0] = v166;
    v168 = v47->pm;
    v169 = CMP_XM(47);
    v168->m_Items[1] = v169;
    v171 = v47->pm;
    v172 = CMP_XM(54);
    v171->m_Items[2] = v172;
    v174 = v47->pm;
    v175 = CMP_XM(63);
    v174->m_Items[3] = v175;
    v177 = v48->pm;
    v177->m_Items[3] = curctr->ctr0;
    itfMiscDrawSpritePrim(v49, v47, v48, v214 - 4, g_manager->tex, 0, v154);
    Draw(gfxMgr, "MsgCsr", 0x4000000u, v154, 0);
    v179 = Allocate(sdfDrawTag_t);
    sdfDrawTag_t___ctor(v179);
    sdfDrawTagInit(v179);
    ctr1 = curctr->ctr1;
    if (ctr1 >= 1)
    {
      v182 = v49->pm;
      v183 = 128 - ctr1;
      v182->m_Items[0] -= v183;
      v184 = v49->pm;
      v185 = v183 >> 1;
      v184->m_Items[1] -= v183 >> 1;
      v193 = 2 * v183;
      v194 = v49->pm;
      v194->m_Items[2] += v193;
      v196 = v49->pm;
      v119 = v211;
      v196->m_Items[3] += v185;
      v198 = v48->pm;
      v198->m_Items[3] = ctr1;
      itfMiscDrawAlphaPrim(v179, 1, 0);
      itfMiscDrawSpritePrim(v49, v47, v48, v214 - 5, g_manager->tex, 0, v179);
      itfMiscDrawAlphaPrim(v179, 0, 0);
      Draw(gfxMgr, "MsgAlpha", 0x4000000u, v179, 0);
    }
    v207 = dds3Ot->m_Items[v119->otindex];
    sdfDrawTagLinkOt(v207, v179);
  }
}

// 0x13b7ff0
s32 DrawSelection(u32 stat) {
  char v2;

  v2 = stat;
  return ((v2 & 7) == 4) & IsSelectWindowDispOn();
}

// 0x13b7920
void DrawSpeaker(_FRQ *pfont) {
  System_String_o *FRQString;
  TMPro_TMP_Text_o *SpkWndTMP;
  System_Object_array *v7;
  s64 *v8;
  s64 *v11;
  System_String_o *v13;
  s32 v15;

  FRQString = GetFRQString(pfont);
  if (IsNullOrEmpty(FRQString))
  {
    frDrawFont(pfont);
  }
  else
  {
    v15 = 9;
    v7 = NewSpecific(object, 1u);
    v8 = sub_8D3950(UI_COL, &v15);
    v11 = v8;
    v7->m_Items[0] = v11;
    v13 = RepColTag(FRQString, v7);
    set_text(SpkWndTMP, v13);
  }
}

// 0x13b76d0
void DrawWindow(instanceMes_tag *pinst) {
  u32 stat;
  struct window_tag_o *window;
  itfpanel_t_o *mes;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v9;
  itfpanel_t_o *spk;
  struct sdfGrOt_t_array *v13;
  sdfGrOt_t_o *v15;
  struct mesflow_tag_o *pmesflow;
  itfpanel_t_o *v18;

  stat = pinst->stat;
  if ((stat & 0x80000) == 0)
  {
    window = pinst->window;
    if ((stat & 0x300) != 0)
    {
      mes = window->mes;
      v9 = dds3Ot->m_Items[pinst->otindex];
      itfPnlDraw(mes, v9);
      g_manager->stat |= 2u;
      spk = window->spk;
      if (spk)
      {
        v13 = dds3Ot;
        v15 = v13->m_Items[pinst->otindex];
        itfPnlDraw(spk, v15);
      }
    }
    else
    {
      pmesflow = g_debug->pmesflow;
      if (!pmesflow)
        return;
    }
    if (window && pmesflow->pinst == pinst)
    {
      v18 = window->mes;
      DebugDrawWindowLine(v18);
    }
  }
}

// 0x13a8680
s32 FR_DRAW_SPD(_FRQ *FRQ) {
  return FRQ->draw_spd >> 1;
}

// 0x13aa7f0
void FadeInWindow(void) {
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;

  SwitchOK(0);
  Item = _get_Item(
           MsgWnd,
           MsgWndIndex);
  Component_object = GetComponent_object_(Item);
  Display(Component_object, 1);
}

// 0x13ab240
void FadeOutWindow(void) {
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;

  SwitchSpeaker(0, 0);
  SwitchOK(0);
  Item = _get_Item(
           MsgWnd,
           MsgWndIndex);
  Component_object = GetComponent_object_(Item);
  Display(Component_object, 0);
}

// 0x13bada0
void FinalDanteEventMsg(void) {
  UnityEngine_Object_o *MsgWndOwner;
  u64 v9;
  u32 v10;
  s64 v11;
  s32 v12;
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  struct System_Single_array *EnablePos;
  f32 v18;
  System_WeakReference_o *v19;
  UnityEngine_Transform_o *v20;
  System_WeakReference_o *v21;
  System_WeakReference_o *v23;
  u32 v24;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v26;

  if (!op_Equality(MsgWndOwner, 0, 0))
  {
    if (get_activeSelf(MsgWndOwner))
    {
      SetActive(MsgWndOwner, 0, 0);
    }
    v9 = 0;
    v10 = 0;
    v11 = 32;
    do
    {
      Item = _get_Item(
               MsgWnd,
               v10);
      transform = get_transform(Item, 0);
      localPosition = get_localPosition(transform);
      v18 = *(&EnablePos->obj.klass + v11 - 12 * (v9 / 3));
      v19 = _get_Item(
              MsgWnd,
              v10);
      v20 = get_transform(v19, 0);
      v26.x = localPosition.x;
      v26.y = v18;
      v26.z = localPosition.z;
      set_localPosition(v20, v26);
      v21 = _get_Item(
              MsgWnd,
              v10);
      if (get_activeSelf(v21))
      {
        v23 = _get_Item(
                MsgWnd,
                v10);
        SetActive(v23, 0, 0);
      }
      ++v10;
      v11 += 4;
      v12 = (v24 >> 9) & 1;
      ++v9;
    }
    while (v10 != 6);
    bDanteEvent = 0;
  }
}

// 0x13ad5f0
void ForceSetCurCtr(curctr_tag *pcurctr, s16 phase, s16 ctr0, s16 ctr1) {
  pcurctr->phase = phase;
  pcurctr->ctr0 = ctr0;
  pcurctr->ctr1 = ctr1;
}

// 0x13aba90
u8 **GetDataBytes(u8 **data, s32 index, s32 len) {
  System_Array_o *v7;

  v7 = NewSpecific(byte, (len + 1));
  Copy_3880080(data, index, v7, 0, len);
  *(&v7[2].klass + len) = 0;
  return v7;
}

// 0x13a86a0
char *GetFRQString(_FRQ *frq) {
  struct _TEXT_o *str;

  Clear(frqstr, 0);
  str = frq->str;
  {
    Append_5387312(frqstr, str->chcode);
    str = str->next;
  }
  return (frqstr->klass->vtable._3_ToString.methodPtr)(
           frqstr,
           frqstr->klass->vtable._3_ToString.method);
}

// 0x13ab7f0
_FRQ *GetFontHandleUnit(u8 **dat, u32 **ppstr, s32 **pplen, s32 num, u32 mask, s32 x, s32 y, u32 z) {
  u64 v13;
  _FRQ_o *v14;
  s32 v16;
  s64 v18;
  System_Array_o *v19;
  _FRQ_o *v21;
  _FRQ_o *head;
  _FRQ_o *prev;
  _FRQ_o *v25;
  struct _TEXT_o *i;
  s32 max;
  s64 v31;

  max = num;
  if (num >= 1)
  {
    v31 = num;
    v13 = 0;
    v14 = 0;
    while (1)
    {
      v16 = ppstr->m_Items[v13];
      v18 = pplen->m_Items[v13];
        break;
      if ((byte_3F596B3 & 1) == 0)
        goto LABEL_14;
LABEL_15:
      v19 = NewSpecific(byte, (v18 + 1));
      Copy_3880080(dat, v16, v19, 0, v18);
      *(&v19[2].klass + v18) = 0;
      if ((mask & 1) == 0)
      {
        v21 = MessageRequestExLocalize(x, y, 0, 0, 0, 0x80u, v19, v14);
        y += 8 * v21->y_size;
        v14 = v21;
      }
      ++v13;
      mask >>= 1;
      if (v31 == v13)
        goto LABEL_25;
    }
    if ((byte_3F596B3 & 1) != 0)
      goto LABEL_15;
LABEL_14:
    goto LABEL_15;
  }
  v14 = 0;
LABEL_25:
  head = v14->head;
  InitializeSelectWindow(head, max, pplen);
  prev = v14;
  do
  {
    prev->priority = z;
    prev = prev->prev;
  }
  while (prev);
  v25 = v14;
  do
  {
    for (i = v25->str; i; i = i->next)
      LOBYTE(i->color) = 0x80;
    v25 = v25->prev;
  }
  while (v25);
  return v14;
}

// 0x13a9fb0
_FRQ *GetLastLinkFontHandle(_FRQ *pfont) {
  _FRQ_o *v2;

  do
  {
    v2 = pfont;
    pfont = pfont->prev;
  }
  while (pfont);
  return v2;
}

// 0x13a9b10
void GetLastMessagePara(_FRQ *pfont, message_tag *pmessage) {
  struct _TEXT_o *str_end;

  if (pfont)
  {
    str_end = pfont->str_end;
    if (str_end)
    {
      pmessage->last_spd = pfont->draw_spd >> 1;
      pmessage->last_style = str_end->style;
      pmessage->last_col = str_end->col_no;
      pmessage->last_tp = str_end->tp;
    }
  }
}

// 0x13ac460
s32 GetMaskedIndex(s32 index, u32 mask) {
  bool v3;

  if ((mask & 1) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 0;
  }
  if ((mask & 2) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 1;
  }
  if ((mask & 4) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 2;
  }
  if ((mask & 8) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 3;
  }
  if ((mask & 0x10) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 4;
  }
  if ((mask & 0x20) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 5;
  }
  if ((mask & 0x40) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 6;
  }
  if ((mask & 0x80) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 7;
  }
  if ((mask & 0x100) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 8;
  }
  if ((mask & 0x200) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 9;
  }
  if ((mask & 0x400) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 10;
  }
  if ((mask & 0x800) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 11;
  }
  if ((mask & 0x1000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 12;
  }
  if ((mask & 0x2000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 13;
  }
  if ((mask & 0x4000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 14;
  }
  if ((mask & 0x8000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 15;
  }
  if ((mask & 0x10000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 16;
  }
  if ((mask & 0x20000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 17;
  }
  if ((mask & 0x40000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 18;
  }
  if ((mask & 0x80000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 19;
  }
  if ((mask & 0x100000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 20;
  }
  if ((mask & 0x200000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 21;
  }
  if ((mask & 0x400000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 22;
  }
  if ((mask & 0x800000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 23;
  }
  if ((mask & 0x1000000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 24;
  }
  if ((mask & 0x2000000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 25;
  }
  if ((mask & 0x4000000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 26;
  }
  if ((mask & 0x8000000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 27;
  }
  if ((mask & 0x10000000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 28;
  }
  if ((mask & 0x20000000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 29;
  }
  if ((mask & 0x40000000) == 0)
  {
    v3 = __OFSUB__(index--, 1);
    if (index < 0 != v3)
      return 30;
  }
  if (index > 0 || (mask & 0x80000000) != 0)
    return 32;
  else
    return 31;
}

// 0x13a91c0
u8 **GetMessagePagePtr(itfMesBinMesHeader_t *pmesheader, u8 **data, s32 page) {
  struct System_UInt32_array *addr;
  struct System_Int32_array *len;
  s32 v10;
  s32 v12;
  System_Array_o *v13;

  if (page < 0 || pmesheader->page <= page)
    return 0;
  addr = pmesheader->addr;
  len = pmesheader->len;
  v10 = addr->m_Items[page];
  v12 = len->m_Items[page];
  v13 = NewSpecific(byte, (v12 + 1));
  Copy_3880080(data, v10, v13, 0, v12);
  *(&v13[2].klass + v12) = 0;
  return v13;
}

// 0x13ac3a0
s32 GetMessageWidth(_FRQ *pfont) {
  s32 v3;
  s32 y;
  s32 v5;
  s32 w_pxls;
  s32 v7;

  if (!pfont)
    return 0;
  v3 = 0;
LABEL_7:
  y = pfont->y;
  v5 = 0;
  while (1)
  {
    w_pxls = pfont->w_pxls;
    pfont = pfont->prev;
    v5 += w_pxls;
    if (!pfont)
      break;
    if (y != pfont->y)
    {
      if (v3 < v5)
        v3 = v5;
      goto LABEL_7;
    }
  }
  if (v3 >= v5)
    v7 = v3;
  else
    v7 = v5;
  return 16 * v7;
}

// 0x13ab7b0
s32 GetNumSelectItem(s32 allitem, u32 mask) {
  s32 result;
  s32 v5;
  char v6;

  if (allitem < 1)
    return 0;
  result = 0;
  v5 = allitem + 1;
  do
  {
    v6 = ~mask;
    mask >>= 1;
    --v5;
    result += v6 & 1;
  }
  while (v5 > 1);
  return result;
}

// 0x13ab510
u8 **GetSpeakerName(instanceMes_tag *pinst) {
  Il2CppObject *pdata;
  Il2CppClass *v4;
  s64 *Interface;
  char *v6;
  s64 *v7;
  itfMesBinTypeHeader2_t_o *v8;
  s32 v11;
  s32 v12;
  u64 *v13;
  u32 v14;
  u8 *v15;
  u64 v19[2];
  char *v20;
  s64 v21;
  s32 pos;

  pdata = pinst->pdata;
  if (pdata)
  {
    Interface = QueryInterface(pinst->pdata, byte);
    if (!Interface)
    {
      sub_8FC2C0(pdata->klass->_1.element_class, v4, v19);
      if ((v19[0] & 1) != 0)
        v6 = v20;
      else
        v6 = v19 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  else
  {
    Interface = 0;
  }
LABEL_14:
  pos = 0;
  v20 = 0;
  v21 = 0;
  v19[0] = 0;
  v19[1] = 0;
  sub_13A7EC0(v19, Interface, &pos);
  pos += 8 * v21;
  v8 = Allocate(itfMesBinTypeHeader2_t);
  itfMesBinTypeHeader2_t___ctor(v8, Interface, &pos);
  v11 = v8->ppspkhead + 4 * pinst->speaker->num + 32;
  v12 = ToInt32(Interface, v11, 0);
  v13 = Allocate(System_Collections_Generic_List_byte_);
  __ctor(v13);
  v14 = v12 + 32;
  v15 = Interface + v14 + 32;
  if (v14 >= *(Interface + 6))
  {
LABEL_20:
  }
  while (*v15)
  {
    _Add(v13, *v15);
    ++v14;
    ++v15;
    if (v14 >= *(Interface + 6))
      goto LABEL_20;
  }
  _Add(v13, 0);
  return _ToArray(v13);
}

// 0x13a8f70
itfMesBinTypeHeader_t *GetTypeHeader(instanceMes_tag *pinst, s32 index) {
  Il2CppObject *pdata;
  Il2CppClass *v6;
  s64 *Interface;
  char *v8;
  s64 *v9;
  u64 *v10;
  s32 v12;
  u64 v14[2];
  char *v15;
  s64 v16;
  s32 v17;

  v17 = 0;
  pdata = pinst->pdata;
  if (pdata)
  {
    Interface = QueryInterface(pinst->pdata, byte);
    if (!Interface)
    {
      sub_8FC2C0(pdata->klass->_1.element_class, v6, v14);
      if ((v14[0] & 1) != 0)
        v8 = v15;
      else
        v8 = v14 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    Interface = 0;
  }
  v17 = 0;
  v15 = 0;
  v16 = 0;
  v14[0] = 0;
  v14[1] = 0;
  sub_13A7EC0(v14, Interface, &v17);
  v17 += 8 * index;
  v10 = Allocate(itfMesBinTypeHeader_t);
  _ctor(v10, 0);
  v12 = v17;
  *(v10 + 4) = ToUInt32(Interface, v12, 0);
  *(v10 + 5) = ToInt32(Interface, v17 + 4, 0);
  return v10;
}

// 0x13a9120
itfMesBinTypeHeader2_t *GetTypeHeader2(u8 **pfileheader) {
  u64 *v3;
  u64 v6[3];
  s64 v7;
  s32 pos;

  pos = 0;
  v7 = 0;
  memset(v6, 0, sizeof(v6));
  sub_13A7EC0(v6, pfileheader, &pos);
  pos += 8 * v7;
  v3 = Allocate(itfMesBinTypeHeader2_t);
  itfMesBinTypeHeader2_t___ctor(v3, pfileheader, &pos);
  return v3;
}

// 0x13baa20
void InitDanteEventMsg(void) {
  UnityEngine_Object_o *MsgWndOwner;
  u64 v9;
  s64 i;
  u32 v11;
  System_WeakReference_o *v12;
  UnityEngine_Transform_o *transform;
  struct System_Single_array *EnablePos;
  f32 v17;
  System_WeakReference_o *v18;
  UnityEngine_Transform_o *v19;
  System_WeakReference_o *Item;
  System_WeakReference_o *v26;
  bool v27;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v30;

  if (!op_Equality(MsgWndOwner, 0, 0))
  {
    if (!get_activeSelf(MsgWndOwner))
    {
      SetActive(MsgWndOwner, 1, 0);
    }
    bDanteEvent = 1;
    v9 = 0;
    for (i = 32; ; i += 4)
    {
      v11 = v9 % 3;
      if (v9 % 3 != 2)
        break;
      Item = _get_Item(
               MsgWnd,
               v9);
      if (get_activeSelf(Item))
      {
        v26 = _get_Item(
                MsgWnd,
                v9);
        v27 = 0;
        goto LABEL_50;
      }
LABEL_51:
      if (v9 == 5)
        return;
      ++v9;
    }
    v12 = _get_Item(
            MsgWnd,
            v9);
    transform = get_transform(v12, 0);
    localPosition = get_localPosition(transform);
    v17 = *(&EnablePos->obj.klass + i - 12 * (v9 / 3));
    v18 = _get_Item(
            MsgWnd,
            v9);
    v19 = get_transform(v18, 0);
    v30.x = localPosition.x;
    v30.y = v17;
    v30.z = localPosition.z;
    set_localPosition(v19, v30);
    if (v11 != 1)
    {
      if (!v11)
      {
        ClearMessage();
      }
        goto LABEL_49;
      goto LABEL_36;
    }
    else
    {
      ClearSpeaker(itfMesManager);
      {
LABEL_49:
        MsgWndSetActive(v9, 1);
        v26 = _get_Item(
                MsgWnd,
                v9);
        v27 = 1;
LABEL_50:
        SetActive(v26, v27, 0);
        goto LABEL_51;
      }
    }
LABEL_36:
    goto LABEL_49;
  }
}

// 0x13ad5d0
void InitializeCurCtr(curctr_tag *pcurctr, s32 isdisp) {
  if (!isdisp)
    pcurctr->isdraw = 0;
  *&pcurctr->phase = 0x400000;
  pcurctr->ctr1 = 0;
  pcurctr->ctr_key = 0;
}

// 0x13ace90
void InitializeMessage(message_tag *pmessage, s32 defaultpos) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;

  if (defaultpos)
  {
    pm = pmessage->pos->pm;
    pm->m_Items[0] = 4500;
    v5 = pmessage->pos->pm;
    v5->m_Items[1] = 6318;
  }
  *&pmessage->lines = 0;
  pmessage->maxpage = 0;
  *(&pmessage->pfont + 5) = 0;
  pmessage->pfont = 0;
  pmessage->last_spd = 0x80;
}

// 0x13acf20
void InitializeSelect(select_tag *pselect) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v4;

  pm = pselect->pos->pm;
  pm->m_Items[0] = 5160;
  v4 = pselect->pos->pm;
  v4->m_Items[1] = 7506;
  pselect->pfont = 0;
  pselect->mask = 0;
  *&pselect->alpha = 0;
  *&pselect->phase = 0xFFFFFFFF0000LL;
}

// 0x13abb40
void InitializeSelectWindow(_FRQ *pFRQ, s32 max) {
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  u32 *v7;
  u64 v8;
  u32 *v9;
  u64 v10;
  u64 *v11;
  System_String_o *v12;
  UnityEngine_Component_o *v13;
  s64 *gameObject;
  UnityEngine_GameObject_o *v15;
  u32 *v19;
  u64 v20;
  Il2CppObject *ComponentInChildren_object;
  System_String_o *FRQString;
  s32 v29;

  Item = _get_Item(
           MsgWnd,
           MsgWndIndex + 2);
  transform = get_transform(Item, 0);
  v7 = NewSpecific(UnityEngine_GameObject, 8u);
  v8 = 0;
  v9 = v7 + 8;
  do
  {
    while (1)
    {
      v10 = v8 + 1;
      v29 = v8 + 1;
      v11 = sub_8D3950(s32, &v29);
      v12 = Format("choice_answer{0:D2}", v11, 0);
      v13 = Find(transform, v12, 0);
      gameObject = get_gameObject(v13);
      v15 = gameObject;
      *&v9[2 * v8] = v15;
      if (get_activeSelf(v15))
        break;
      ++v8;
      if (v10 == 8)
        goto LABEL_18;
    }
    SetActive(*&v9[2 * v8++], 0, 0);
  }
  while (v10 != 8);
LABEL_18:
  if (max >= 1)
  {
    v19 = v7 + 8;
    v20 = 0;
    do
    {
      ComponentInChildren_object = GetComponentInChildren_object_(*&v19[2 * v20]);
      if (!op_Equality(ComponentInChildren_object, 0, 0))
      {
        FRQString = GetFRQString(pFRQ);
        set_text(ComponentInChildren_object, FRQString);
        ChangeSelection(v20, 0);
        pFRQ = pFRQ->next;
        SetActive(*&v19[2 * v20], 1, 0);
        if (!pFRQ)
          break;
      }
      ++v20;
    }
    while (v20 < max);
  }
}

// 0x13ace10
void InitializeSpeaker(Speaker_tag *pspeaker, s32 defaultpos) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;

  if (defaultpos)
  {
    pm = pspeaker->pos->pm;
    pm->m_Items[0] = 4020;
    v5 = pspeaker->pos->pm;
    v5->m_Items[1] = 5832;
  }
  pspeaker->pfont = 0;
  pspeaker->num = -1;
}

// 0x13ad570
void InitializeVariable(variable_tag *pvariable) {
  u64 i;
  struct System_String_array *pptr;
  Il2CppClass **v5;

  for (i = 0; i != 32; ++i)
  {
    pptr = pvariable->pptr;
    v5 = &pptr->obj.klass + i;
    v5[4] = 0;
  }
}

// 0x13acfb0
void InitializeWindow(window_tag *pwindow) {
  pwindow->spk = 0;
  pwindow->mes = 0;
  ResetWindowPara(pwindow, 0, 0);
}

// 0x13a8790
bool IsCloseWindow(s32 id) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  return pinst && pinst->message->pfont != 0;
}

// 0x13aa740
bool IsFadeOutWindow(void) {
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;
  s32 DisplayStatus;

  Item = _get_Item(
           MsgWnd,
           MsgWndIndex);
  Component_object = GetComponent_object_(Item);
  DisplayStatus = GetDisplayStatus(Component_object);
  return DisplayStatus == 3 || DisplayStatus == 0;
}

// 0x13ab0b0
bool IsSelectWindowDispOff(void) {
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;

  Item = _get_Item(
           MsgWnd,
           MsgWndIndex + 2);
  Component_object = GetComponent_object_(Item);
  return GetDisplayStatus(Component_object) == 0;
}

// 0x13aafb0
bool IsSelectWindowDispOn(void) {
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;
  s32 DisplayStatus;
  System_WeakReference_o *v8;
  Il2CppObject *v9;

  Item = _get_Item(
           MsgWnd,
           MsgWndIndex + 2);
  Component_object = GetComponent_object_(Item);
  DisplayStatus = GetDisplayStatus(Component_object);
  if (DisplayStatus)
  {
    v8 = _get_Item(
           MsgWnd,
           MsgWndIndex + 2);
    v9 = GetComponent_object_(v8);
    LOBYTE(DisplayStatus) = get_alpha(v9) >= 0.75;
  }
  return DisplayStatus;
}

// 0x13ba920
bool IsSpeakStart(void) {
  else
  {
    if (bNowSpeaking == 2)
      return 0;
  }
  if (!bVoicePlaySw)
    return 0;
LABEL_9:
    return ChkVoicePlaying();
  return ChkVoicePlaying();
}

// 0x13ba7f0
bool IsSpeaking(void) {
  else
  {
    if (bNowSpeaking == 2)
      return 0;
  }
  else if (bVoicePlaySw)
  {
LABEL_11:
      return ChkVoicePlaying();
    return ChkVoicePlaying();
  }
  return bNowSpeaking != 3;
}

// 0x13aa2e0
bool MsgWndActiveSelf(s32 i) {
  s32 v4;
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  System_WeakReference_o *v9;

  {
    else
    {
      if (bDanteEvent)
        goto LABEL_5;
    }
  }
  else
  {
    v4 = 0;
    if (bDanteEvent)
    {
LABEL_5:
      Item = _get_Item(
               MsgWnd,
               i);
      transform = get_transform(Item, 0);
      return get_localPosition(transform).y == 10000.0;
    }
  }
  v9 = _get_Item(
         MsgWnd,
         i);
  return get_activeSelf(v9);
}

// 0x13aa410
void MsgWndSetActive(s32 i, bool sw) {
  s32 v6;
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  struct System_Single_array *EnablePos;
  f32 v14;
  System_WeakReference_o *v16;
  System_WeakReference_o *v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v20;

  {
    else
    {
      if (bDanteEvent)
        goto LABEL_5;
    }
  }
  else
  {
    v6 = 0;
    if (bDanteEvent)
    {
LABEL_5:
      Item = _get_Item(
               MsgWnd,
               i);
      transform = get_transform(Item, 0);
      localPosition = get_localPosition(transform);
      if (sw)
      {
        v14 = EnablePos->m_Items[i % 3];
          goto LABEL_24;
      }
      else
      {
        v14 = 10000.0;
        {
LABEL_24:
          v17 = _get_Item(
                  MsgWnd,
                  i);
          v18 = get_transform(v17, 0);
          v20.x = localPosition.x;
          v20.z = localPosition.z;
          v20.y = v14;
          set_localPosition(v18, v20);
          return;
        }
      }
      goto LABEL_24;
    }
  }
  v16 = _get_Item(
          MsgWnd,
          i);
  SetActive(v16, sw, 0);
}

// 0x13acb40
void OpenCheckSpeakerWindow(instanceMes_tag *pinst) {
  struct Speaker_tag_o *speaker;
  struct window_tag_o *window;
  struct _FRQ_o *pfont;
  u32 stat;
  s32 w_pxls;
  sdfTexHandle_t_o *tex;
  struct System_Int32_array *pm;
  s32 v14;
  s32 v15;
  struct System_Int32_array *v16;
  s32 v18;
  s32 v19;
  s32 v20;
  struct System_Int32_array *v21;
  s32 v22;
  s32 v24;
  s32 v25;
  struct System_Int32_array *v26;
  s32 v27;
  s32 v29;
  s32 v30;
  bool v31;
  bool v32;

  speaker = pinst->speaker;
  window = pinst->window;
  pfont = speaker->pfont;
  if (!pfont || (stat = pinst->stat, (stat & 0x10000) != 0))
  {
    if (!window->spk)
      return;
    pinst->stat |= 0x3000u;
    v31 = 0;
    v32 = 0;
  }
  else
  {
    if (!window->spk)
    {
      w_pxls = pfont->w_pxls;
      tex = g_manager->tex;
      window->spk = itfPnlRegist2(7, tex);
      pm = speaker->pos->pm;
      v14 = pm->m_Items[0];
      v15 = CMP_XM(45);
      v16 = speaker->pos->pm;
      v18 = v14 - v15;
      v19 = v16->m_Items[1];
      v20 = CMP_YM(9);
      v21 = speaker->pos->pm;
      v22 = v19 - v20;
      v24 = v21->m_Items[0];
      v25 = CMP_XM(w_pxls + 45);
      v26 = speaker->pos->pm;
      v27 = v25 + v24;
      v29 = v26->m_Items[1];
      v30 = CMP_YM(42);
      itfPnlSetPosition(window->spk, v18, v22, v27, v30 + v29, pinst->z);
      itfPnlSetColor(window->spk, 127, 127, 127, 0);
      stat = pinst->stat;
    }
    pinst->stat = stat & 0xFFFFCFFF | 0x1000;
    v31 = 1;
    v32 = 1;
  }
  SwitchSpeaker(v31, v32);
}

// 0x13ac770
void OpenMessageWindow(instanceMes_tag *pinst) {
  struct window_tag_o *window;
  struct message_tag_o *message;
  struct System_Int32_array *pm;
  struct System_Int32_array *v6;
  s32 v7;
  struct System_Int32_array *v9;
  s32 v10;
  struct System_Int32_array *v12;
  s32 v13;
  struct System_Int32_array *v15;
  s32 v16;
  struct System_Int32_array *v18;
  s32 v19;
  struct System_Int32_array *v21;
  s32 v22;
  s32 v24;
  struct System_Int32_array *v25;
  s32 v26;
  s32 v27;
  s32 v29;
  itfpanel_t_o *mes;
  u32 z;
  struct System_Int32_array *v32;
  u32 max_length;
  s32 v34;
  sdfTexHandle_t_o *tex;
  s32 v39;

  if ((byte_3F59609 & 1) != 0)
  {
    window = pinst->window;
    message = pinst->message;
    if (window->mes)
      goto LABEL_3;
  }
  else
  {
    window = pinst->window;
    message = pinst->message;
    if (window->mes)
    {
LABEL_3:
      pm = message->pos->pm;
      if (LODWORD(pm->max_length))
        goto LABEL_4;
LABEL_48:
    }
  }
  if (pinst->type == 2)
  {
    tex = g_manager->tex;
    v39 = 8;
  }
  else
  {
    tex = g_manager->tex;
    v39 = 6;
  }
  window->mes = itfPnlRegist2(v39, tex);
  pm = message->pos->pm;
  if (!LODWORD(pm->max_length))
    goto LABEL_48;
LABEL_4:
  v6 = window->mes_offset->pm;
  v7 = pm->m_Items[0];
  v9 = message->pos->pm;
  v10 = v6->m_Items[0];
  v12 = window->mes_offset->pm;
  v13 = v9->m_Items[1];
  v15 = message->pos->pm;
  v16 = v12->m_Items[1];
  v18 = window->mes_offset->pm;
  v19 = v15->m_Items[0];
  v21 = message->pos->pm;
  v22 = v18->m_Items[2];
  v24 = v16 + v13;
  v25 = window->mes_offset->pm;
  v26 = v10 + v7;
  v27 = v22 + v19;
  v29 = v25->m_Items[3] + v21->m_Items[1];
  mes = window->mes;
  z = pinst->z;
  itfPnlSetPosition(mes, v26, v24, v27, v29, z);
  v32 = window->mes_color->pm;
  max_length = v32->max_length;
  v34 = v32->m_Items[0];
  itfPnlSetColor(window->mes, v34, window->mes_color->pm->m_Items[1], window->mes_color->pm->m_Items[2], 0);
  WindowDispOn_20618496(pinst);
  pinst->stat = pinst->stat & 0xFFFFFCFF | 0x100;
}

// 0x13a9a60
void RaiseMessageSpeedMax(_FRQ *pfont) {
  for (; pfont; pfont = pfont->prev)
  {
    while (1)
    {
      while (pfont->str->tp)
      {
        pfont = pfont->prev;
        if (!pfont)
          return;
      }
        break;
      pfont->draw_spd = 0x80;
      pfont = pfont->prev;
      if (!pfont)
        return;
    }
    pfont->draw_spd = 0x80;
  }
}

// 0x13ac6e0
void RaiseMessageSpeedMaxAll(_FRQ *pfont) {
  for (; pfont; pfont = pfont->prev)
  {
    {
      pfont->draw_spd = 0x80;
      pfont = pfont->prev;
      if (!pfont)
        return;
    }
    pfont->draw_spd = 0x80;
  }
}

// 0x13a92f0
void ReadytoMessage(instanceMes_tag *pinst, s32 mode) {
  struct message_tag_o *message;
  _FRQ_o *pfont;
  itfMesBinMesHeader_t_o *pbinheader;
  s64 *pdata;
  s32 page;
  Il2CppClass *v11;
  s64 *Interface;
  char *v13;
  s64 *v14;
  System_Byte_array *MessagePagePtr;
  struct System_Int32_array *pm;
  u32 max_length;
  s32 v19;
  s32 v20;
  s32 v22;
  u8 last_style;
  u8 last_col;
  u8 last_tp;
  u8 last_spd;
  _FRQ_o *v29;
  _FRQ_o *prev;
  struct _TEXT_o *str_end;
  char gMessageRequestResult;
  struct _FRQ_o *v35;
  System_WeakReference_o *Item;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  instanceMes_tag_func_kutiDelegate_o *func_kuti;
  u32 z;
  _FRQ_o *v49;
  _FRQ_o *v50;
  _FRQ_o *v51;
  u64 v52;
  u64 v54[3];

  message = pinst->message;
  pfont = message->pfont;
  if (pfont)
  {
    frDestroyFontRequestAfter(pfont, *&mode);
    message->pfont = 0;
  }
  pbinheader = message->pbinheader;
  pdata = pinst->pdata;
  page = message->page;
  if (!pdata)
    goto LABEL_17;
LABEL_11:
  Interface = QueryInterface(pdata, byte);
  if (!Interface)
  {
    sub_8FC2C0(*(*pdata + 64), v11, v54);
    if ((v54[0] & 1) != 0)
      v13 = v54[2];
    else
      v13 = v54 + 1;
    v14 = sub_8C4940(v13);
  }
LABEL_18:
  MessagePagePtr = GetMessagePagePtr(pbinheader, Interface, page);
  ClearMessage(MessagePagePtr);
  bNowSpeaking = 1;
  pm = message->pos->pm;
  max_length = pm->max_length;
  v19 = pm->m_Items[0];
  v20 = mode;
  v22 = message->pos->pm->m_Items[1];
  last_style = message->last_style;
  last_col = message->last_col;
  last_tp = message->last_tp;
  last_spd = message->last_spd;
  v29 = MessageRequestExLocalize(v19, v22, last_style, last_col, last_tp, last_spd, MessagePagePtr, 0);
  if (v20 != 2)
  {
    if ((pinst->stat & 0x400000) == 0)
    {
      if ((g_manager->stat & 1) != 0)
      {
        if (v29)
        {
          prev = v29;
          do
          {
            while (1)
            {
              while (prev->str->tp)
              {
                prev = prev->prev;
                if (!prev)
                  goto LABEL_45;
              }
                break;
              prev->draw_spd = 0x80;
              prev = prev->prev;
              if (!prev)
                goto LABEL_45;
            }
            prev->draw_spd = 0x80;
            prev = prev->prev;
          }
          while (prev);
        }
      }
    }
LABEL_45:
    if (v29)
    {
      str_end = v29->str_end;
      if (str_end)
      {
        message->last_spd = v29->draw_spd >> 1;
        message->last_style = str_end->style;
        message->last_col = str_end->col_no;
        message->last_tp = str_end->tp;
      }
    }
    message->wait = gMessageRequestResult & 3;
    if ((gMessageRequestResult & 2) != 0)
    {
      SwitchSpeaker(0, 0);
      pinst->stat |= 0x10000u;
      if (fclCombineGreetingFlag)
      {
        Item = _get_Item(
                 MsgWnd,
                 MsgWndIndex + 1);
        gameObject = get_gameObject(Item);
        Component_object = GetComponent_object_(gameObject);
        Hide(Component_object);
        fclCombineGreetingFlag = 0;
      }
        goto LABEL_88;
    }
    else
    {
      v35 = pinst->speaker->pfont;
      SwitchSpeaker(v35 != 0, v35 != 0);
      pinst->stat &= ~0x10000u;
        goto LABEL_88;
    }
LABEL_88:
    WindowDispOn_20618496(pinst);
    if ((gMessageRequestResult & 4) != 0)
    {
      func_kuti = pinst->func_kuti;
      if (func_kuti)
        Invoke(func_kuti);
    }
    z = pinst->z;
    if (v29)
    {
      v49 = v29;
      do
      {
        v49->priority = z;
        v49 = v49->prev;
      }
      while (v49);
      v50 = v29;
      do
      {
        v51 = v50;
        v50 = v50->prev;
      }
      while (v50);
      v52 = 715827883LL * ((v29->y - v51->y) >> 3);
      message->lines = (v52 >> 34) + (v52 >> 63) + 1;
    }
  }
  message->pfont = v29;
}

// 0x13a8e80
void ReleaseAllVariable(variable_tag *pvariable) {
  s64 i;
  struct System_String_array *pptr;
  struct System_String_array *v5;

  for (i = 4; i != 36; ++i)
  {
    pptr = pvariable->pptr;
    if (*(&pptr->obj.klass + i))
    {
      v5 = pvariable->pptr;
      *(&v5->obj.klass + i) = 0;
    }
  }
}

// 0x13a8db0
void ReleaseAllWindow(instanceMes_tag *pinst) {
  struct window_tag_o *window;
  itfpanel_t_o *spk;
  itfpanel_t_o *mes;

  window = pinst->window;
  spk = window->spk;
  if (spk)
  {
    itfPnlRelease(spk);
    window->spk = 0;
  }
  mes = window->mes;
  if (mes)
  {
    itfPnlRelease(mes);
    window->mes = 0;
  }
  pinst->stat &= 0xFFFFF0FF;
}

// 0x13ad020
void ResetWindowPara(window_tag *pwin, s32 type, s32 alpha) {
  struct System_Int32_array *v7;
  s32 v8;
  struct System_Int32_array *v10;
  s32 v11;
  struct System_Int32_array *v13;
  s32 v14;
  struct System_Int32_array *v16;
  s32 v17;
  struct System_Int32_array *v19;
  struct System_Int32_array *v21;
  struct System_Int32_array *v23;
  struct System_Int32_array *v25;
  s32 v26;
  struct System_Int32_array *pm;
  s32 v28;
  struct System_Int32_array *v30;
  s32 v31;
  struct System_Int32_array *v33;
  s32 v34;
  struct System_Int32_array *v36;
  s32 v37;
  struct System_Int32_array *v39;
  struct System_Int32_array *v41;
  struct System_Int32_array *v43;
  struct System_Int32_array *v46;
  s32 v47;
  struct System_Int32_array *v49;
  s32 v50;
  struct System_Int32_array *v52;
  s32 v53;
  struct System_Int32_array *v55;
  s32 v56;
  struct System_Int32_array *v58;
  struct System_Int32_array *v60;
  struct System_Int32_array *v62;

  if (type == 1)
  {
    pm = pwin->mes_offset->pm;
    v28 = CMP_XM(-475);
    pm->m_Items[0] = v28;
    v30 = pwin->mes_offset->pm;
    v31 = CMP_YM(-95);
    v30->m_Items[1] = v31;
    v33 = pwin->mes_offset->pm;
    v34 = CMP_XM(707);
    v33->m_Items[2] = v34;
    v36 = pwin->mes_offset->pm;
    v37 = CMP_YM(169);
    v36->m_Items[3] = v37;
    v39 = pwin->mes_color->pm;
    v39->m_Items[0] = 127;
    v41 = pwin->mes_color->pm;
    v41->m_Items[1] = 127;
    v43 = pwin->mes_color->pm;
    v43->m_Items[2] = 127;
    v25 = pwin->mes_color->pm;
    if (alpha >= 1)
      v26 = 2 * alpha;
    else
      v26 = 174;
    if (LODWORD(v25->max_length) <= 3)
      goto LABEL_48;
  }
  else
  {
    if (type == 2)
    {
      v7 = pwin->mes_offset->pm;
      v8 = CMP_XM(-313);
      v7->m_Items[0] = v8;
      v10 = pwin->mes_offset->pm;
      v11 = CMP_YM(-65);
      v10->m_Items[1] = v11;
      v13 = pwin->mes_offset->pm;
      v14 = CMP_XM(675);
      v13->m_Items[2] = v14;
      v16 = pwin->mes_offset->pm;
      v17 = CMP_YM(130);
      v16->m_Items[3] = v17;
      v19 = pwin->mes_color->pm;
      v19->m_Items[0] = 127;
      v21 = pwin->mes_color->pm;
      v21->m_Items[1] = 127;
      v23 = pwin->mes_color->pm;
      v23->m_Items[2] = 127;
      v25 = pwin->mes_color->pm;
      if (alpha >= 1)
        v26 = 2 * alpha;
      else
        v26 = 270;
      if (LODWORD(v25->max_length) > 3)
        goto LABEL_49;
LABEL_48:
    }
    v46 = pwin->mes_offset->pm;
    v47 = CMP_XM(-313);
    v46->m_Items[0] = v47;
    v49 = pwin->mes_offset->pm;
    v50 = CMP_YM(-123);
    v49->m_Items[1] = v50;
    v52 = pwin->mes_offset->pm;
    v53 = CMP_XM(675);
    v52->m_Items[2] = v53;
    v55 = pwin->mes_offset->pm;
    v56 = CMP_YM(178);
    v55->m_Items[3] = v56;
    v58 = pwin->mes_color->pm;
    v58->m_Items[0] = 127;
    v60 = pwin->mes_color->pm;
    v60->m_Items[1] = 127;
    v62 = pwin->mes_color->pm;
    v62->m_Items[2] = 127;
    v25 = pwin->mes_color->pm;
    if (alpha >= 1)
      v26 = 2 * alpha;
    else
      v26 = 204;
    if (LODWORD(v25->max_length) <= 3)
      goto LABEL_48;
  }
LABEL_49:
  v25->m_Items[3] = v26;
}

// 0x13a8f10
void ResolveResourceAddress(void *pdata) {

}

// 0x13b6bb0
s32 SelectItem(instanceMes_tag *pinst) {
  struct select_tag_o *select;
  s32 v6;
  struct curctr_tag_o *curctr;
  s32 OK;
  s32 SelectYesSe;
  s32 v13;
  s32 v14;
  s32 v16;
  s32 v19;
  s32 v20;

  select = pinst->select;
  else if (DDS3_PADCHECK_REP(6))
  {
LABEL_6:
    if (select->select)
      goto LABEL_11;
    if (DDS3_PADCHECK_TRIG(6))
    {
LABEL_11:
      v6 = -1;
      goto LABEL_23;
    }
    goto LABEL_27;
  }
  if (DDS3_PADCHECK_REP(7))
  {
    if (select->lines - 1 != select->select)
      goto LABEL_22;
    if (DDS3_PADCHECK_TRIG(7))
    {
LABEL_22:
      v6 = 1;
LABEL_23:
      SelectItemMove(select, v6);
      curctr = pinst->curctr;
      *&curctr->phase = 0x400000;
      curctr->ctr1 = 0;
      curctr->ctr_key = 0;
    }
  }
LABEL_27:
  else if (DDS3_PADCHECK_TRIG(OK))
  {
LABEL_33:
    else
    {
      if (SelectYesSe < 1)
        goto LABEL_37;
    }
    if (!select->select)
    {
      v13 = SelectYesSe;
      goto LABEL_61;
    }
LABEL_37:
    v13 = 8;
LABEL_61:
    p2sdPlaySE(v13);
    return 1;
  }
  if (select->numdef < 1)
    return 0;
  v14 = SelectItemDefKey(select);
  if (v14 < 0)
    return 0;
LABEL_46:
  v16 = v14;
  p2sdPlaySE(8);
  v19 = select->select;
  if (v16 == v19)
    return 1;
  ChangeSelection(v19, 0);
  v20 = 1;
  ChangeSelection(v16, 1);
  select->select = v16;
  select->select_imm = v16;
  return v20;
}

// 0x13b7260
s32 SelectItemDefKey(select_tag *psel) {
  u64 v3;
  struct defkey_tag_array *defkey;
  defkey_tag_o *v7;
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v10;
  System_Byte_array *v12;
  s32 index;
  u32 mask;
  s32 v16;
  s32 v17;
  s32 result;
  s32 v19;
  u32 v20;
  s32 v21;
  s32 v22;

  if (psel->numdef >= 1)
  {
    v3 = 0;
    while (1)
    {
      defkey = psel->defkey;
      v7 = defkey->m_Items[v3];
      v10 = dds3PadMap->m_Items[1];
      v12 = v10->m_Items[0];
      if (v12->m_Items[v7->key] < 0)
      {
        index = v7->index;
        mask = psel->mask;
        v16 = mask & 1;
        if (index >= 1)
        {
          v17 = index & 3;
          if ((index - 1) >= 3)
          {
            result = 0;
            v19 = v17 - index;
            v20 = psel->mask;
            do
            {
              mask = v20 >> 4;
              result += (((v20 >> 3) & 1) == 0) + (((v20 >> 2) & 1) == 0) + (((v20 >> 1) & 1) == 0) + (v16 ^ 1);
              v16 = (v20 >> 4) & 1;
              v19 += 4;
              v20 >>= 4;
            }
            while (v19);
            if (v17)
              goto LABEL_26;
          }
          else
          {
            result = 0;
            if ((index & 3) == 0)
              goto LABEL_28;
LABEL_26:
            v21 = -v17;
            do
            {
              v22 = v16 ^ 1;
              v16 = (mask >> 1) & 1;
              mask >>= 1;
              result += v22;
              ++v21;
            }
            while (v21);
          }
LABEL_28:
          if (!v16)
            return result;
          goto LABEL_29;
        }
        result = 0;
        if ((mask & 1) == 0)
          return result;
      }
LABEL_29:
      if (++v3 >= psel->numdef)
        return -1;
    }
  }
  return -1;
}

// 0x13b7130
void SelectItemMove(select_tag *psel, s32 direct) {
  s32 select;
  s32 v8;

  select = psel->select;
  else
  {
    ChangeSelection(select, 0);
    if ((direct & 0x80000000) == 0)
      goto LABEL_6;
  }
  if (select <= 0)
  {
    v8 = psel->lines - 1;
      goto LABEL_17;
  }
  else
  {
    v8 = select - 1;
      goto LABEL_17;
  }
LABEL_10:
LABEL_17:
  ChangeSelection(v8, 1);
  psel->select = v8;
  psel->select_imm = v8;
  p2sdPlaySE(1);
}

// 0x13ab150
void SelectWindowDispOff(instanceMes_tag *pinst) {
  s32 id;
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;

  id = pinst->id;
  else
  {
    if (id != SelWndId)
      return;
  }
  Item = _get_Item(
           MsgWnd,
           MsgWndIndex + 2);
  Component_object = GetComponent_object_(Item);
  Display(Component_object, 0);
  SelWndId = -1;
}

// 0x13aab20
void SelectWindowDispOn(instanceMes_tag *pinst) {
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;
  s32 SelWndId;
  s32 v10;
  s32 id;
  System_Object_array *v13;

  Item = _get_Item(
           MsgWnd,
           MsgWndIndex + 2);
  Component_object = GetComponent_object_(Item);
  if ((GetDisplayStatus(Component_object) - 1) >= 2)
  {
    else
    {
      if (SelWndId == -1)
      {
LABEL_13:
        id = pinst->id;
        SelWndId = id;
        MsgWndSetActive(MsgWndIndex + 2, 1);
        Display(Component_object, 1);
        return;
      }
    }
    v10 = pinst->id;
    else if (v10 == SelWndId)
    {
      goto LABEL_13;
    }
    v13 = Empty_string_();
    Log("Not Closed", v13, 0);
  }
}

// 0x13aa890
void SetMessage(void *obj, s32 line, char *text) {
  s32 v8;
  System_WeakReference_o *Item;
  System_WeakReference_o *v10;
  UnityEngine_Canvas_o *v12;

  v8 = 3 * MsgWndIndex + line;
  Item = _get_Item(
           MsgWndTMP,
           v8);
  v10 = _get_Item(
          MsgWndCnv,
          v8);
  if (text)
  {
    v12 = v10;
    if (op_Inequality(Item, 0, 0))
      set_text(Item, text);
    if (op_Inequality(v12, 0, 0))
    {
      set_overrideSorting(v12, 1);
      set_sortingOrder(v12, 20);
    }
  }
}

// 0x13ab2f0
void SetVar(instanceMes_tag *pinst, s32 index, char *pstr, s32 length) {
  struct variable_tag_o *variable;
  struct System_String_array *pptr;
  s64 v9;
  struct System_String_array *v11;
  struct System_String_array *v13;

  variable = pinst->variable;
  pptr = variable->pptr;
  v9 = index;
  if (!IsNullOrEmpty(pptr->m_Items[index]))
  {
    v11 = variable->pptr;
    v11->m_Items[v9] = 0;
  }
  v13 = variable->pptr;
  v13->m_Items[v9] = pstr;
}

// 0x13ba3e0
void ShutdownProc(dds3ProcessID_t *proc_id) {
  struct mesflow_tag_o *puse_top;
  struct itfmisclinkheader_t_o *linkheader;
  s32 id;
  mesflow_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10;
  s16 v12;
  Il2CppClass **v13;
  s32 i;
  struct manager_tag_o *g_manager;
  struct UnityEngine_Texture2D_array *image;
  u64 max_length_low;
  u64 v19[3];

  puse_top = g_manager->linkstack->puse_top;
  if (puse_top)
  {
    while (1)
    {
      linkheader = puse_top->linkheader;
      puse_top = linkheader->pnext;
      id = linkheader->id;
      DestructFlow(id);
      if (!puse_top)
        break;
      klass = puse_top->klass;
      if (puse_top->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mesflow_tag)
      {
        sub_8FC2C0(klass->_1.element_class, mesflow_tag, v19);
        if ((v19[0] & 1) != 0)
          v8 = v19[2];
        else
          v8 = v19 + 1;
        v9 = sub_8C4940(v8);
      }
    }
  }
  v10 = 0;
  if ((v12 & 0x200) != 0)
    goto LABEL_23;
LABEL_22:
  for (i = 0; ; i = v12 & 0x200)
  {
    image = g_manager->tex->image;
    max_length_low = LODWORD(image->max_length);
    if (v10 >= max_length_low)
      break;
    else if (v10 >= max_length_low)
    {
      goto LABEL_30;
    }
    v13 = &image->obj.klass + v10++;
    v13[4] = 0;
    if ((v12 & 0x200) == 0)
      goto LABEL_22;
LABEL_23:
  }
  g_manager->tex = 0;
}

// 0x13b6f10
void SlideUpDownMessage(instanceMes_tag *pinst, s32 y) {
  struct Speaker_tag_o *speaker;
  struct message_tag_o *message;
  struct window_tag_o *window;
  struct System_Int32_array *pm;
  struct _FRQ_o *pfont;
  itfpanel_t_o *mes;
  itfpanel_t_o *spk;
  struct System_Int32_array *v13;
  struct _FRQ_o *prev;

  speaker = pinst->speaker;
  message = pinst->message;
  window = pinst->window;
  pm = message->pos->pm;
  pm->m_Items[1] += y;
  pfont = message->pfont;
  for (; pfont; pfont = pfont->prev)
    pfont->y += y;
  mes = window->mes;
  if (mes)
  {
    itfPnlSetPositionOffset(mes, 0, y, 0, 0, 0);
  }
  spk = window->spk;
  if (spk)
  {
    itfPnlSetPositionOffset(spk, 0, y, 0, y, 0);
  }
  if (speaker->pfont)
  {
    v13 = speaker->pos->pm;
    v13->m_Items[1] += y;
    prev = speaker->pfont;
    for (; prev; prev = prev->prev)
      prev->y += y;
  }
}

// 0x13aa640
void SwitchOK(bool sw) {
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v6;
  UnityEngine_GameObject_o *gameObject;

  Item = _get_Item(
           MsgWnd,
           MsgWndIndex);
  transform = get_transform(Item, 0);
  v6 = Find(transform, "ok", 0);
  gameObject = get_gameObject(v6);
  if (op_Inequality(gameObject, 0, 0))
    SetActive(gameObject, sw, 0);
}

// 0x13a9bb0
void SwitchSpeaker(bool sw, bool disp) {
  s32 v7;
  System_WeakReference_o *Item;
  s32 v12;
  bool v13;
  Il2CppObject *Component_object;

  v7 = MsgWndIndex + 1;
  Item = _get_Item(
           MsgWnd,
           v7);
  if (disp)
  {
    if (!MsgWndActiveSelf(v7))
    {
      v12 = v7;
      v13 = 1;
LABEL_23:
      MsgWndSetActive(v12, v13);
    }
  }
  else
  {
    if (MsgWndActiveSelf(v7))
    {
      v12 = v7;
      v13 = 0;
      goto LABEL_23;
    }
  }
  Component_object = GetComponent_object_(Item);
  Display(Component_object, sw);
}

// 0x13ac140
_FRQ *UnchainFontHandleUnit(_FRQ *pfont, s32 index, s32 lines) {
  s32 v7;
  s32 y;
  s32 v9;
  s32 v10;
  struct _FRQ_o *v11;
  bool v12;
  _FRQ_o *prev;
  _FRQ_o *v14;
  _FRQ_o *v15;
  _FRQ_o *v17;

  v7 = ~index;
  y = pfont->y;
  v9 = v7 + lines;
  if (v9 < 1)
  {
    v10 = pfont->y;
    goto LABEL_17;
  }
  v10 = pfont->y;
  if (y != v10)
  {
LABEL_12:
    while (1)
    {
      v12 = v9-- < 2;
      y = v10;
      if (v12)
        break;
      v10 = pfont->y;
      if (y == v10)
        goto LABEL_7;
    }
LABEL_17:
    prev = pfont;
    while (1)
    {
      v14 = prev;
      prev = prev->prev;
      if (!prev)
        break;
      if (v10 != prev->y)
      {
        do
        {
          while (1)
          {
            v15 = prev;
            prev = prev->prev;
            v15->head = v15;
            v15->prev = 0;
            v15->next = 0;
              break;
            frDestroyFontRequestAfter(v15, *&index);
            if (!prev)
              goto LABEL_25;
          }
          frDestroyFontRequestAfter(v15);
        }
        while (prev);
        break;
      }
    }
LABEL_25:
    pfont->next = 0;
    v14->prev = 0;
    if (pfont)
    {
      v17 = pfont;
      do
      {
        v17->head = v14;
        v17 = v17->prev;
      }
      while (v17);
    }
    return pfont;
  }
  while (1)
  {
LABEL_7:
    v11 = pfont->prev;
    pfont->prev = 0;
    pfont->next = 0;
    pfont->head = pfont;
    frDestroyFontRequestAfter(pfont, *&index);
    if (!v11)
      return 0;
    v10 = v11->y;
    pfont = v11;
    if (y != v10)
      goto LABEL_12;
  }
}

// 0x13aa0b0
void WindowDispOff(bool sw) {
  System_Object_array *v4;
  u32 i;
  System_WeakReference_o *v8;
  Il2CppObject *v10;
  System_WeakReference_o *Item;
  Il2CppObject *Component_object;

  v4 = Empty_string_();
  Log("WindowDispOff", v4, 0);
  for (i = 0; i != 6; ++i)
  {
    while (1)
    {
      if (3 * (i / 3) + 2 == i)
        break;
      Item = _get_Item(
               MsgWnd,
               i);
      Component_object = GetComponent_object_(Item);
      if (!op_Inequality(Component_object, 0, 0))
        goto LABEL_28;
      if (sw)
      {
        Display(Component_object, 0);
LABEL_28:
        if (++i == 6)
          return;
      }
      else
      {
        DisplayOff(Component_object);
        if (++i == 6)
          return;
      }
    }
    v8 = _get_Item(
           MsgWnd,
           i);
    v10 = GetComponent_object_(v8);
    if (!op_Inequality(v10, 0, 0))
      goto LABEL_28;
    if (sw)
      Display(v10, 0);
    DisplayOff(v10);
  }
}

// 0x13aa000
void WindowDispOn(s32 MsgID) {
  struct mesflow_tag_array *pmesflow;
  instanceMes_tag_o *pinst;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[MsgID]->pinst;
  WindowDispOff(0);
  WindowDispOn_20618496(pinst);
}

// 0x13a9d00
void WindowDispOn_20618496(instanceMes_tag *pinst) {
  s32 MsgWndIndex;
  System_String_o *v11;
  System_String_o *v12;
  System_Object_array *v14;
  s32 v18;
  char v26[4];

  v26[0] = 0;
  if (!get_activeSelf(MsgWndOwner))
  {
    SetActive(MsgWndOwner, 1, 0);
  }
  MsgWndIndex = 0;
  if (!MsgWndActiveSelf(MsgWndIndex))
  {
    MsgWndSetActive(MsgWndIndex, 1);
    v26[0] = 1;
  }
  v11 = sub_3C0020(v26);
  v12 = Concat_5224608("WindowDispOn : ", v11);
  v14 = Empty_string_();
  Log(v12, v14, 0);
  if (v26[0])
  {
    v18 = 3 - MsgWndIndex;
    MsgWndSetActive(MsgWndIndex + 1, 1);
    if (pinst->speaker->pfont)
    {
      SwitchSpeaker(1, 1);
    }
    SwitchOK(0);
    MsgWndSetActive(v18, 0);
    MsgWndSetActive(v18 + 1, 0);
  }
  else if (!IsFadeOutWindow(itfMesManager))
  {
    return;
  }
  FadeInWindow();
}

// 0x13a8690
sdfDrawTag_t *dds3AllocDrawTag(void) {
  return 0;
}

// 0x13b1c80
void itfMesMngChangeWindowType(s32 id, s32 type, s32 alpha) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  window_tag_o *window;
  window_tag_o *v12;
  struct System_Int32_array *pm;
  itfpanel_t_o *mes;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  if ((pinst->stat & 0x3000) == 0)
  {
    window = pinst->window;
    v12 = window;
    if (pinst->type != type)
      goto LABEL_14;
    pm = window->mes_color->pm;
    if (pm->m_Items[3] != alpha)
    {
      v12 = pinst->window;
LABEL_14:
      pinst->type = type;
      ResetWindowPara(v12, type, alpha);
      mes = window->mes;
      if (mes)
      {
        itfPnlRelease(mes);
        window->mes = 0;
      }
    }
  }
}

// 0x13b1330
void itfMesMngClearBitStat(s32 id, u32 flag) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  pinst->stat &= ~flag | 0xFFFF;
}

// 0x13b4f60
void itfMesMngClearBitStatManager(s32 flags) {
  s16 v2;

  v2 = flags;
  g_manager->stat &= ~v2;
}

// 0x13b0b40
s32 itfMesMngCloseSelectWindow(void) {
  return 1;
}

// 0x13b0880
s32 itfMesMngCloseWindow(void) {
  s32 MessageHandle;
  s32 v4;
  struct mesflow_tag_array *pmesflow;
  s32 v8;

  MessageHandle = scrGetMessageHandle();
  if (MessageHandle < 0)
    return 1;
LABEL_6:
  v4 = MessageHandle;
  pmesflow = g_manager->pmesflow;
  v8 = pmesflow->m_Items[v4]->pinst->stat & 0x300;
  if (v8 == 512 || v8 == 256)
  {
    itfMesMngMsgWndCls(v4);
    fldPanelSet(3);
  }
  return v8 == 0;
}

// 0x13b5050
dds3ProcessFunc_t *itfMesMngDebugProc(dds3ProcessID_t *proc_id) {
  u64 *v3;
  u64 *v4;
  char v5;
  char v7;
  char v9;
  char v11;
  char v13;
  u64 *v15;
  s16 v16;
  mesflow_tag_c *v18;
  s16 v20;
  struct debug_tag_o *g_debug;
  mesflow_tag_o *v24;
  struct mesflow_tag_o **p_pmesflow;
  mesflow_tag_o *v26;
  mesflow_tag_c *v27;
  s64 v28;
  char *v29;
  s64 *v30;
  struct debug_tag_o *v31;
  window_tag_o *window;
  s32 mode;
  itfMesManager_c *v35;
  struct debug_tag_o *v36;
  s32 v38;
  u64 v40;
  u64 *v41;
  u64 *v42;
  s32 v43;
  System_Object_array *v48;
  struct debug_tag_o *v50;
  System_String_o *v51;
  _BOOL8 v52;
  u16 *v54;
  s64 *v55;
  s64 *v56;
  s64 *v58;
  s64 *v60;
  Il2CppObject *v63;
  struct sdfIVector4_t_o *pos;
  System_Object_array *v65;
  struct System_Int32_array *pm;
  System_Object_array *v67;
  s64 *v69;
  s64 *v70;
  struct System_Int32_array *v72;
  s64 *v74;
  s64 *v76;
  Il2CppObject *v79;
  System_Object_array *v80;
  struct System_Int32_array *v81;
  System_Object_array *v82;
  s64 *v84;
  s64 *v85;
  struct System_Int32_array *v87;
  s64 *v89;
  s64 *v90;
  Il2CppObject *v92;
  System_Object_array *v93;
  struct System_Int32_array *v94;
  System_Object_array *v95;
  s64 *v97;
  s64 *v98;
  Il2CppObject *v100;
  struct sdfIVector4_t_o *mes_offset;
  System_Object_array *v104;
  struct System_Int32_array *v105;
  System_Object_array *v106;
  s64 *v108;
  s64 *v109;
  struct System_Int32_array *v111;
  s64 *v113;
  s64 *v114;
  struct System_Int32_array *v116;
  s64 *v118;
  s64 *v119;
  struct System_Int32_array *v121;
  s64 *v123;
  s64 *v124;
  Il2CppObject *v126;
  struct sdfGrOt_t_array *dds3Ot;
  mesflow_tag_o *pmesflow;
  mesflow_tag_c *klass;
  s64 typeHierarchyDepth;
  bool v147;
  struct debug_tag_o *v148;
  s32 OK;
  bool v150;
  struct debug_tag_o *v152;
  u32 cursor;
  s32 CANCEL;
  window_tag_o *v155;
  u64 *v156;
  s32 v157;
  s32 v158;
  s32 v159;
  s32 v160;
  s32 v161;
  s32 v162;
  s32 v163;
  s32 v164;
  char v165[16];
  char *v166;

  v3 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v3);
  v4 = NewSpecific(byte, 5u);
  v5 = *il2cp::SizeOf("LEFT-TOP", qword_3F088F8);
  *(v4 + 32) = v5;
  v7 = *il2cp::SizeOf("RIGHT-BOTTOM", qword_3F088F8);
  *(v4 + 33) = v7;
  v9 = *il2cp::SizeOf("POSITION", qword_3F088F8);
  *(v4 + 34) = v9;
  v11 = *il2cp::SizeOf("ALPHA", qword_3F088F8);
  *(v4 + 35) = v11;
  v13 = *il2cp::SizeOf("CHANGE INSTANCE", qword_3F088F8);
  *(v4 + 36) = v13;
  v15 = NewSpecific(char, 2u);
  v16 = *il2cp::SizeOf("> ", char);
  v156 = v15;
  *(v15 + 16) = v16;
  v20 = *il2cp::SizeOf("* ", char);
  *(v15 + 17) = v20;
  else
  {
    if (g_debug->pmesflow)
      goto LABEL_33;
  }
  else
  {
    v24 = 0;
    p_pmesflow = &g_debug->pmesflow;
  }
  v26 = DebugChangeInstance(v24, v18);
  if (v26)
  {
    v27 = v26->klass;
    if (v26->klass->_2.typeHierarchyDepth < v28 || v27->_2.typeHierarchy[v28 - 1] != mesflow_tag)
    {
      sub_8FC2C0(v27->_1.element_class, mesflow_tag, v165);
      if ((v165[0] & 1) != 0)
        v29 = v166;
      else
        v29 = &v165[1];
      v30 = sub_8C4940(v29);
    }
  }
  *p_pmesflow = v26;
  if (g_debug->pmesflow)
  {
LABEL_33:
    v31 = g_debug;
    window = v31->pmesflow->pinst->window;
    mode = v31->mode;
    switch (mode)
    {
      case 2:
        DebugMoveWinAlpha(window, v18);
        break;
      case 1:
        DebugMoveWinVert(window, v31->cursor);
        break;
      case 0:
        else if (DDS3_PAD2CHECK_REP(6))
        {
LABEL_42:
          --g_debug->cursor;
          v36 = g_debug;
          if (v36->cursor < 0)
          {
            v36->cursor = 2;
            if ((v35->_2.bitflags2 & 2) == 0)
            {
LABEL_203:
              v150 = DDS3_PAD2CHECK_TRIG(OK);
              if (v150)
              {
                v152 = g_debug;
                cursor = v152->cursor;
                if (cursor >= 3)
                {
                  if (cursor == 3)
                  {
                    v152->mode = 2;
                  }
                  else if (cursor == 4)
                  {
                    v152->pmesflow = DebugChangeInstance(v152->pmesflow, v18);
                  }
                }
                else
                {
                  v152->mode = 1;
                }
              }
              else
              {
                if (DDS3_PAD2CHECK_TRIG(CANCEL))
                {
                  proc_id->func_ans = -1;
                  return 0;
                }
              }
              goto LABEL_67;
            }
LABEL_201:
            goto LABEL_203;
          }
LABEL_200:
          if ((v35->_2.bitflags2 & 2) == 0)
            goto LABEL_203;
          goto LABEL_201;
        }
        v147 = DDS3_PAD2CHECK_REP(7);
        if (v147)
        {
          ++g_debug->cursor;
          v148 = g_debug;
          if (v148->cursor >= 5)
          {
            v148->cursor = 0;
          }
        }
        goto LABEL_200;
      default:
LABEL_67:
        v155 = window;
        dds3ConsPanelTagLink(0, 16, 16, 30, 9);
        v40 = 0;
        v41 = v4;
        v42 = v4 + 4;
        v43 = 31232;
        do
        {
          v48 = NewSpecific(object, 2u);
          v50 = g_debug;
          v51 = "{0}{1}";
          if (v40 == v50->cursor)
          {
            v52 = v50->mode != 0;
            v54 = v156 + v52 + 16;
          }
          else
          {
            v54 = il2cp::SizeOf("  ", char);
          }
          *v165 = *v54;
          v55 = sub_8D3950(char, v165);
          v56 = v55;
          v48->m_Items[0] = v56;
          LOBYTE(v164) = *(v42 + v40);
          v58 = sub_8D3950(qword_3F088F8, &v164);
          v60 = v58;
          v48->m_Items[1] = v60;
          v63 = sdfDevPrintf(29056, v43, 0xFFFFF0u, 0, v51, v48);
          sdfDrawTagLink(0, v63);
          ++v40;
          v43 += 96;
        }
        while (v40 != 5);
        pos = window->mes->pos;
        v65 = NewSpecific(object, 2u);
        pm = pos->pm;
        v67 = v65;
        *v165 = pm->m_Items[0] >> 4;
        v69 = sub_8D3950(s32, v165);
        v70 = v69;
        v67->m_Items[0] = v70;
        v72 = pos->pm;
        v164 = v72->m_Items[1] >> 3;
        v74 = sub_8D3950(s32, &v164);
        v76 = v74;
        v67->m_Items[1] = v76;
        v79 = sdfDevPrintf(32256, 31232, 0xFFFFF0u, 0, "({0},{1})", v67, 0);
        sdfDrawTagLink(0, v79);
        v80 = NewSpecific(object, 2u);
        v81 = pos->pm;
        v82 = v80;
        v163 = v81->m_Items[2] >> 4;
        v84 = sub_8D3950(s32, &v163);
        v85 = v84;
        v82->m_Items[0] = v85;
        v87 = pos->pm;
        v162 = v87->m_Items[3] >> 3;
        v89 = sub_8D3950(s32, &v162);
        v90 = v89;
        v82->m_Items[1] = v90;
        v92 = sdfDevPrintf(32256, 31328, 0xFFFFF0u, 0, "({0},{1})", v82, 0);
        sdfDrawTagLink(0, v92);
        v93 = NewSpecific(object, 1u);
        v94 = v155->mes_color->pm;
        v95 = v93;
        v161 = v94->m_Items[3];
        v97 = sub_8D3950(s32, &v161);
        v98 = v97;
        v95->m_Items[0] = v98;
        v100 = sdfDevPrintf(32256, 31520, 0xFFFFF0u, 0, "({0})", v95, 0);
        sdfDrawTagLink(0, v100);
        mes_offset = g_debug->pmesflow->pinst->window->mes_offset;
        v104 = NewSpecific(object, 4u);
        v105 = mes_offset->pm;
        v106 = v104;
        v160 = v105->m_Items[0] >> 4;
        v108 = sub_8D3950(s32, &v160);
        v109 = v108;
        v106->m_Items[0] = v109;
        v111 = mes_offset->pm;
        v159 = v111->m_Items[1] >> 3;
        v113 = sub_8D3950(s32, &v159);
        v114 = v113;
        v106->m_Items[1] = v114;
        v116 = mes_offset->pm;
        v158 = v116->m_Items[2] >> 4;
        v118 = sub_8D3950(s32, &v158);
        v119 = v118;
        v106->m_Items[2] = v119;
        v121 = mes_offset->pm;
        v157 = v121->m_Items[3] >> 3;
        v123 = sub_8D3950(s32, &v157);
        v124 = v123;
        v106->m_Items[3] = v124;
        v126 = sdfDevPrintf(29056, 31808, 0xFFFFF0u, 0, "OFFSET : {0}, {1} - {2}, {3}", v106, 0);
        sdfDrawTagLink(0, v126);
        sdfDrawTagLinkOt(dds3Ot->m_Items[83], 0);
        return 0;
    }
    v38 = CANCEL;
    if (DDS3_PAD2CHECK_TRIG(v38))
    {
      g_debug->mode = 0;
    }
    goto LABEL_67;
  }
  return 0;
}

// 0x13b6b20
void itfMesMngDebugShutdown(dds3ProcessID_t *proc_id) {
  g_debug->cursor = 0;
  g_debug->mode = 0;
  g_debug->pmesflow = 0;
}

// 0x13b3ec0
u8 **itfMesMngGetDataPtrImmediate(s32 id, s32 message, s32 page) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  itfMesBinMesHeader_t_o *pbinheader;
  s64 *pdata;
  Il2CppClass *v12;
  s64 *Interface;
  char *v14;
  s64 *v15;
  u64 v17[3];

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  pbinheader = pinst->message->pbinheader;
  pdata = pinst->pdata;
  if (pdata)
  {
    Interface = QueryInterface(pdata, byte);
    if (!Interface)
    {
      sub_8FC2C0(*(*pdata + 64), v12, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  else
  {
    Interface = 0;
  }
  return GetMessagePagePtr(pbinheader, Interface, page);
}

// 0x13b4190
_FRQ *itfMesMngGetFRQ(s32 id, s32 message) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  return pmesflow->m_Items[id]->pinst->message->pfont;
}

// 0x13b3b30
s32 itfMesMngGetMesCurrentPage(s32 id) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  return pmesflow->m_Items[id]->pinst->message->page;
}

// 0x13b3a80
s32 itfMesMngGetMesPage(s32 id) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  return pmesflow->m_Items[id]->pinst->message->maxpage;
}

// 0x13af6d0
s32 itfMesMngGetPhase(s32 msgid) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  return pmesflow->m_Items[msgid]->pinst->message->phase;
}

// 0x13b0050
s32 itfMesMngGetSelPhase(s32 msgid) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  return pmesflow->m_Items[msgid]->pinst->select->phase;
}

// 0x13b39d0
s32 itfMesMngGetSelect(s32 id) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  return pmesflow->m_Items[id]->pinst->select->select;
}

// 0x13b01b0
s32 itfMesMngGetSelectNo(s32 msgid) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  return pmesflow->m_Items[msgid]->pinst->select->select;
}

// 0x13b3870
u32 itfMesMngGetStat(s32 id) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  return pmesflow->m_Items[id]->pinst->stat;
}

// 0x13b4fe0
s32 itfMesMngGetStatManager(void) {
  return g_manager->stat;
}

// 0x13b4020
char *itfMesMngGetStrImmediate(s32 id, s32 message, s32 page) {
  s32 v8;
  System_String_o *v11;
  struct mesflow_tag_array *pmesflow;
  _FRQ_o *i;
  System_String_o *FRQString;
  System_String_o *v17;

  v8 = itfMesMngRequestMessage(id, message, page, 2);
  v11 = "";
  if (v8 == 1)
  {
    pmesflow = g_manager->pmesflow;
    for (i = pmesflow->m_Items[id]->pinst->message->pfont; i; v11 = v17)
    {
      FRQString = GetFRQString(i);
      v17 = Concat_5224608(v11, FRQString);
      i = i->next;
    }
  }
  itfMesMngRequestMessageRelease(id, 0);
  return v11;
}

// 0x13b3be0
u8 **itfMesMngGetVar(s32 id, s32 index) {
  struct mesflow_tag_array *pmesflow;
  struct System_String_array *pptr;
  System_String_o *v10;
  u64 *v11;
  System_Text_Encoding_o *ASCII;
  System_Collections_Generic_IEnumerable_T__o *v13;

  pmesflow = g_manager->pmesflow;
  pptr = pmesflow->m_Items[id]->pinst->variable->pptr;
  v10 = pptr->m_Items[index];
  v11 = Allocate(System_Collections_Generic_List_byte_);
  __ctor(v11);
  ASCII = get_ASCII();
  v13 = (ASCII->klass->vtable._28_GetBytes.methodPtr)(ASCII, v10, ASCII->klass->vtable._28_GetBytes.method);
  _AddRange(v11, v13);
  _Add(v11, 0);
  return _ToArray(v11);
}

// 0x13b28f0
char *itfMesMngGetVarLocalize(s32 id, s32 index) {
  struct mesflow_tag_array *pmesflow;
  struct System_String_array *pptr;

  pmesflow = g_manager->pmesflow;
  pptr = pmesflow->m_Items[id]->pinst->variable->pptr;
  return pptr->m_Items[index];
}

// 0x13b4240
s32 itfMesMngGetWidth(s32 id, s32 message, s32 page) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  s64 pext;
  itfMesBinMesHeader_t_o *pbinheader;
  s64 *pdata;
  System_Byte_array *MessagePagePtr;
  System_Byte_array *v20;
  _FRQ_o *v22;
  s32 y;
  s32 v24;
  _FRQ_o *prev;
  s32 v26;
  s32 w_pxls;
  s32 v28;
  s32 v29;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  CommitVarTable(pinst->variable, *&message);
  pext = pinst->pext;
  if (pext)
  {
    il2cp::SizeOf(pext, qword_3F088F8);
  }
  pbinheader = pinst->message->pbinheader;
  pdata = pinst->pdata;
  else if (pdata)
  {
    goto LABEL_16;
  }
  MessagePagePtr = GetMessagePagePtr(pbinheader, 0, page);
  if (!MessagePagePtr)
    return 0;
LABEL_18:
  v20 = MessagePagePtr;
  v22 = MessageRequestEx2(0, 0, 0, 0, 0, 0, 0x80u, v20, 0);
  if (v22)
  {
    y = v22->y;
    v24 = 0;
    prev = v22;
LABEL_36:
    v26 = 0;
    while (1)
    {
      w_pxls = prev->w_pxls;
      prev = prev->prev;
      v26 += w_pxls;
      if (!prev)
        break;
      if (y != prev->y)
      {
        if (v24 < v26)
          v24 = v26;
        y = prev->y;
        goto LABEL_36;
      }
    }
    if (v24 >= v26)
      v28 = v24;
    else
      v28 = v26;
    v29 = 16 * v28;
  }
  else
  {
    v29 = 0;
  }
  frDestroyFontRequestAfter(v22);
  return v29;
}

// 0x13b1150
s32 itfMesMngIgnoreConfig(void) {
  s32 MessageHandle;
  s32 v4;
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  u32 v10;
  struct mesflow_tag_array *v12;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    if (scrGetIntPara(0))
    {
      pmesflow = g_manager->pmesflow;
      pinst = pmesflow->m_Items[v4]->pinst;
      v10 = pinst->stat | 0x400000;
    }
    else
    {
      v12 = g_manager->pmesflow;
      pinst = v12->m_Items[v4]->pinst;
      v10 = pinst->stat & 0xFFBFFFFF;
    }
    pinst->stat = v10;
  }
  return 1;
}

// 0x13b21b0
s32 itfMesMngInitialize(void *presource, char **master_text, char *key) {
  Il2CppObject *Component_object;
  itfmisclinkstack_t_o *linkstack;
  mesflow_tag_o *v14;
  s32 id;
  mesflow_tag_o *v16;
  u64 *v17;
  u64 v22;
  s64 v23;
  s64 v25;
  u64 v27;
  s64 v28;
  s64 v30;
  u64 v32;
  s64 v33;
  s64 v35;
  window_tag_o *v37;
  u64 v38;
  u64 i;
  s64 v40;
  s64 v42;
  u64 v43;

  Component_object = GetComponent_object_(MsgWndOwner);
  if (op_Equality(Component_object, 0, 0))
  {
    AddComponent_object_(MsgWndOwner);
  }
  linkstack = g_manager->linkstack;
  v14 = itfMiscLinkTake(linkstack);
  id = v14->linkheader->id;
  v16 = v14;
  v17 = Allocate(instanceMes_tag);
  _ctor(v17);
  v16->pinst = v17;
  v17[3] = 0;
  itfMesMngSetResourcePtr(id, presource);
  v17[14] = key;
  v22 = v17[6];
  v17[12] = 0;
  v17[13] = master_text;
  *(v17 + 30) = id;
  *(v17 + 4) = 0;
  v17[5] = 0x4700FFFFF0LL;
  v23 = *(*(v22 + 16) + 16LL);
  *(v23 + 32) = 4020;
  v25 = *(*(v22 + 16) + 16LL);
  *(v25 + 36) = 5832;
  *(v22 + 24) = 0;
  *(v22 + 32) = -1;
  v27 = v17[7];
  v28 = *(*(v27 + 16) + 16LL);
  *(v28 + 32) = 4500;
  v30 = *(*(v27 + 16) + 16LL);
  *(v30 + 36) = 6318;
  *(v27 + 46) = 0;
  *(v27 + 50) = 0;
  *(v27 + 37) = 0;
  *(v27 + 32) = 0;
  *(v27 + 45) = 0x80;
  v32 = v17[8];
  v33 = *(*(v32 + 16) + 16LL);
  *(v33 + 32) = 5160;
  v35 = *(*(v32 + 16) + 16LL);
  *(v35 + 36) = 7506;
  *(v32 + 24) = 0;
  *(v32 + 32) = 0;
  *(v32 + 36) = 0xFFFFFFFF0000LL;
  *(v32 + 44) = 0;
  v37 = v17[9];
  v37->spk = 0;
  v37->mes = 0;
  ResetWindowPara(v37, 0, 0);
  v38 = v17[10];
  for (i = 0; i != 32; ++i)
  {
    v40 = *(v38 + 16);
    v42 = v40 + 8 * i;
    *(v42 + 32) = 0;
  }
  v43 = v17[11];
  *(v43 + 16) = 0;
  *(v43 + 18) = 0x400000;
  *(v43 + 22) = 0;
  *(v43 + 24) = 0;
  ++g_manager->numuse;
  return id;
}

// 0x13b46d0
void itfMesMngInitializeManager(void) {
  struct manager_tag_o *g_manager;
  itfmisclinkstack_t_o *linkstack;
  mesflow_tag_array **p_pmesflow;
  struct mesflow_tag_o *pdisuse_top;
  Il2CppObject *i;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 *v12;
  u64 *v14;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  u64 *v18;
  UnityEngine_GameObject_o *v21;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v24;
  u64 *v26;
  u64 *v27;
  itfMesManager_c *v29;
  s32 v30;
  s32 v31;
  UnityEngine_Transform_o *v32;
  s32 childCount;
  UnityEngine_Transform_o *v36;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  u64 *v39;
  System_String_o *v41;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *MsgWndTMP;
  UnityEngine_Transform_o *v44;
  UnityEngine_Component_o *v45;
  UnityEngine_GUILayer_o *Component_GUILayer;
  struct System_Collections_Generic_List_Canvas__o *MsgWndCnv;
  UnityEngine_Transform_o *v48;
  UnityEngine_Component_o *v49;
  UnityEngine_GUILayer_o *v50;
  u64 *v51;
  System_String_o *v53;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v55;
  UnityEngine_Transform_o *v56;
  UnityEngine_Component_o *v57;
  UnityEngine_GUILayer_o *v58;
  struct System_Collections_Generic_List_Canvas__o *v59;
  UnityEngine_Transform_o *v60;
  UnityEngine_Component_o *v61;
  UnityEngine_GUILayer_o *v62;
  u64 *v63;
  System_String_o *v65;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v67;
  UnityEngine_Transform_o *v68;
  UnityEngine_Component_o *v69;
  UnityEngine_GUILayer_o *v70;
  struct System_Collections_Generic_List_Canvas__o *v71;
  UnityEngine_Transform_o *v72;
  UnityEngine_Component_o *v73;
  UnityEngine_GUILayer_o *v74;
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *v76;
  UnityEngine_Component_o *v77;
  UnityEngine_GUILayer_o *v78;
  u64 v81[3];

  g_manager->numuse = 0;
  g_manager->ctr = 0;
  g_manager->stat = 0;
  linkstack = g_manager->linkstack;
  p_pmesflow = &g_manager->pmesflow;
  itfMiscLinkInitialize(linkstack, p_pmesflow, 128);
  pdisuse_top = g_manager->linkstack->pdisuse_top;
  if (pdisuse_top)
  {
    pdisuse_top->pinst = 0;
    for (i = pdisuse_top->linkheader->pnext; i; i = i[1].klass->_1.namespaze)
    {
      klass = i->klass;
      if (i->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mesflow_tag)
      {
        sub_8FC2C0(klass->_1.element_class, mesflow_tag, v81);
        if ((v81[0] & 1) != 0)
          v10 = v81[2];
        else
          v10 = v81 + 1;
        v11 = sub_8C4940(v10);
      }
      i[1].monitor = 0;
    }
  }
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_itfMesManager_CalcManagerProc__);
  dds3StartProcess("ItfMesCalc", 0x409u, 0, 0, v12, 0, 0, 0, 0, 0);
  v14 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v14,
    0,
    Method_itfMesManager_DrawManagerProc__);
  dds3StartProcess("ItfMesDraw", 0x2B1Au, 0, 0, v14, 0, 0, 0, 0, 0);
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", "dds3data/UI", "talkUI");
  v18 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v18);
  MsgWnd = v18;
  v21 = Find("Canvas_UI", 0);
  transform = get_transform(v21, 0);
  v24 = Instantiate_object__425520(Prefab_16624656, transform);
  MsgWndOwner = v24;
  set_name(MsgWndOwner, "talkUI");
  v26 = Allocate(System_Collections_Generic_List_TextMeshProUGUI_);
  __ctor(
    v26);
  MsgWndTMP = v26;
  v27 = Allocate(System_Collections_Generic_List_Canvas_);
  __ctor(v27);
  v30 = 0;
  v31 = 0;
  MsgWndCnv = v27;
  if ((v29->_2.bitflags2 & 2) != 0)
  {
LABEL_34:
  }
  while (1)
  {
    v32 = get_transform(MsgWndOwner, 0);
    childCount = get_childCount(v32);
    if (v31 >= childCount)
      break;
    v36 = get_transform(MsgWndOwner, 0);
    Child = GetChild(v36, v31);
    gameObject = get_gameObject(Child);
    _Add(MsgWnd, gameObject);
    SetActive(gameObject, 0, 0);
    if (!(v30 + 3 * (v31 / 3u)))
    {
      LODWORD(v81[0]) = 1;
      v39 = sub_8D3950(s32, v81);
      v41 = Format("talk_window/Text{0:D2}TM", v39, 0);
      v44 = get_transform(gameObject, 0);
      v45 = Find(v44, v41, 0);
      Component_GUILayer = GetComponent_GUILayer_(v45);
      _Add(MsgWndTMP, Component_GUILayer);
      v48 = get_transform(gameObject, 0);
      v49 = Find(v48, v41, 0);
      v50 = GetComponent_GUILayer_(v49);
      _Add(MsgWndCnv, v50);
      LODWORD(v81[0]) = 2;
      v51 = sub_8D3950(s32, v81);
      v53 = Format("talk_window/Text{0:D2}TM", v51, 0);
      v55 = MsgWndTMP;
      v56 = get_transform(gameObject, 0);
      v57 = Find(v56, v53, 0);
      v58 = GetComponent_GUILayer_(v57);
      _Add(v55, v58);
      v59 = MsgWndCnv;
      v60 = get_transform(gameObject, 0);
      v61 = Find(v60, v53, 0);
      v62 = GetComponent_GUILayer_(v61);
      _Add(v59, v62);
      LODWORD(v81[0]) = 3;
      v63 = sub_8D3950(s32, v81);
      v65 = Format("talk_window/Text{0:D2}TM", v63, 0);
      v67 = MsgWndTMP;
      v68 = get_transform(gameObject, 0);
      v69 = Find(v68, v65, 0);
      v70 = GetComponent_GUILayer_(v69);
      _Add(v67, v70);
      v71 = MsgWndCnv;
      v72 = get_transform(gameObject, 0);
      v73 = Find(v72, v65, 0);
      v74 = GetComponent_GUILayer_(v73);
      _Add(v71, v74);
    }
    ++v31;
    --v30;
      goto LABEL_34;
  }
  Item = _get_Item(
           MsgWnd,
           MsgWndIndex + 1);
  v76 = get_transform(Item, 0);
  v77 = Find(v76, "name_window/TextTM", 0);
  v78 = GetComponent_GUILayer_(v77);
  SpkWndTMP = v78;
  SetActive(MsgWndOwner, 0, 0);
  WindowDispOff(0);
}

// 0x13b07c0
void itfMesMngMarkBitStat(s32 id, u32 flag) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  pinst->stat |= flag & 0xFFFF0000;
}

// 0x13b0260
s32 itfMesMngMaskSelect(void) {
  s32 MessageHandle;
  s32 v4;
  s32 IntPara;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    IntPara = scrGetIntPara(0);
    else if ((byte_3F596AA & 1) != 0)
    {
      goto LABEL_14;
    }
    goto LABEL_14;
  }
  return 1;
}

// 0x13aeb90
s32 itfMesMngMessage(void) {
  s32 MessageHandle;
  s32 v4;
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  s32 IntPara;
  struct message_tag_o *message;
  s32 v13;
  s32 v14;

  else
  {
    MessageHandle = scrGetMessageHandle();
    if (MessageHandle < 0)
      return 1;
  }
  v4 = MessageHandle;
  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[v4]->pinst;
  IntPara = scrGetIntPara(0);
  message = pinst->message;
  if (message->phase)
  {
    if (message->phase < 0)
    {
      message->phase = 0;
      return 1;
    }
    return 0;
  }
  v13 = IntPara;
  v14 = 1;
  if (itfMesMngRequestMessage(v4, v13, 0, 1))
    return 0;
  return v14;
}

// 0x13b09e0
void itfMesMngMsgWndCls(s32 msgid) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  u32 stat;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[msgid]->pinst;
  stat = pinst->stat;
  if ((stat & 0x300) != 0)
  {
    pinst->stat = stat | 0x300;
    FadeOutWindow();
  }
  if ((stat & 0x3000) != 0)
  {
    pinst->stat |= 0x3000u;
    SwitchSpeaker(0, 0);
  }
  itfMesMngRequestMessageRelease(msgid, 1);
  itfMesMngRequestSelectRelease(msgid);
  pinst->stat &= ~0x200000u;
}

// 0x13b0b30
s32 itfMesMngOpenSelectWindow(void) {
  return 1;
}

// 0x13b0660
s32 itfMesMngOpenWindow(void) {
  s32 MessageHandle;
  s32 v4;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    else if ((byte_3F596AB & 1) != 0)
    {
      goto LABEL_11;
    }
    goto LABEL_11;
  }
  return 1;
}

// 0x13b2750
void itfMesMngRelease(s32 id) {
  struct mesflow_tag_array *pmesflow;

  if ((id & 0x80000000) == 0)
  {
    pmesflow = g_manager->pmesflow;
    if (pmesflow->m_Items[id]->pinst)
    {
      DestructFlow(id);
    }
  }
}

// 0x13aed00
s32 itfMesMngRequestMessage(s32 id, s32 message, s32 page, s32 callmode) {
  s16 v6;
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  u64 *v13;
  Il2CppObject *pdata;
  Il2CppClass *v16;
  s64 *Interface;
  char *v18;
  s64 *v19;
  s32 ptr;
  System_Array_o *v21;
  u64 v24;
  u64 v25;
  s32 v26;
  u32 v27;
  u64 v29;
  s32 v31;
  s32 v32;
  s64 v34;
  u64 v35;
  s64 v36;
  u64 v37;
  s32 v38;
  u64 v39;
  u64 v40;
  s64 v41;
  s32 v43;
  u64 v46;
  struct message_tag_o *v49;
  variable_tag_o *variable;
  s64 pext;
  struct Speaker_tag_o *speaker;
  s32 v57;
  _FRQ_o *pfont;
  u32 stat;
  s32 v65;
  s32 result;
  itfpanel_t_o *spk;
  struct System_Int32_array *pm;
  u32 max_length;
  s32 v70;
  s32 v71;
  _FRQ_o *bufferdata;
  struct System_Int32_array *v74;
  u32 v75;
  s32 v77;
  s32 v79;
  struct _FRQ_o *prev;
  u32 z;
  System_Byte_array *SpeakerName;
  s32 ida;
  s16 v88;
  u64 v89[3];

  v6 = page;
  v88 = v6;
  pmesflow = g_manager->pmesflow;
  ida = id;
  pinst = pmesflow->m_Items[id]->pinst;
  v13 = Allocate(itfMesBinMesHeader_t);
  _ctor(v13, 0);
  pdata = pinst->pdata;
  if (pdata)
  {
    Interface = QueryInterface(pinst->pdata, byte);
    if (!Interface)
    {
      sub_8FC2C0(pdata->klass->_1.element_class, v16, v89);
      if ((v89[0] & 1) != 0)
        v18 = v89[2];
      else
        v18 = v89 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  else
  {
    Interface = 0;
  }
  ptr = GetTypeHeader(pinst, message)->ptr;
  v21 = NewSpecific(byte, 0x18u);
  v13[2] = v21;
  Copy_3880080(Interface, ptr + 32, v21, 0, 24);
  *(v13 + 12) = ToInt16(Interface, ptr + 56, 0);
  *(v13 + 13) = ToUInt16(Interface, ptr + 58);
  v13[4] = NewSpecific(uint, *(v13 + 12));
  v13[5] = NewSpecific(s32, *(v13 + 12));
  v24 = v13[4];
  if (*(v13 + 12) >= 1)
  {
    v25 = 0;
    v26 = ptr + 60;
    do
    {
      v27 = ToUInt32(Interface, v26, 0) + 32;
      v29 = v24 + 4 * v25++;
      *(v29 + 32) = v27;
      v24 = v13[4];
      v26 += 4;
    }
    while (v25 < *(v13 + 12));
  }
  v31 = *(v24 + 32) - 4;
  v32 = ToInt32(Interface, v31, 0);
  v34 = *(v13 + 12);
  v35 = v13[5];
  v36 = v34 - 1;
  if (v34 - 1 < 1)
  {
    v38 = 0;
  }
  else
  {
    v37 = 0;
    v38 = 0;
    do
    {
      v39 = v13[4];
      v40 = *(v39 + 24);
      v41 = v37 + 1;
      v43 = *(v39 + 4 * v37 + 36);
      *(v35 + 4 * v37 + 32) = v43 - *(v13[4] + 4 * v37 + 32);
      v46 = v13[5];
      v35 = v46;
      v36 = *(v13 + 12) - 1LL;
      v38 += *(v46 + 4 * v37++ + 32);
    }
    while (v41 < v36);
  }
  *(v35 + 4 * v36 + 32) = v32 + ~v38;
  v49 = pinst->message;
  v49->pbinheader = v13;
  v49->page = v88;
  v49->maxpage = *(v13 + 12);
  v49->callmode = callmode;
  if (!*(v13 + 12))
    return 0;
  variable = pinst->variable;
  CommitVarTable(variable);
  pext = pinst->pext;
  if (pext)
  {
    il2cp::SizeOf(pext, qword_3F088F8);
  }
  ReadytoMessage(pinst, callmode);
  if (callmode == 2)
    return 1;
  if (callmode == 1)
  {
    CallEventVoice(pinst);
  }
  speaker = pinst->speaker;
  v57 = *(v13 + 13);
  pfont = speaker->pfont;
  if (speaker->num != v57)
  {
    if (pfont)
    {
      frDestroyFontRequestAfter(pfont);
      speaker->pfont = 0;
    }
    speaker->num = v57;
    if (v57 == 0xFFFF)
    {
      SwitchSpeaker(0, 0);
      pinst->stat &= 0xFFFFCFFF;
        goto LABEL_118;
      goto LABEL_69;
    }
    spk = pinst->window->spk;
    if (spk)
    {
      itfPnlRelease(spk);
      pinst->window->spk = 0;
    }
    if ((v57 & 0x8000) != 0)
    {
      bufferdata = create_bufferdata(ida, v57 & 0x7FFF);
      speaker->pfont = bufferdata;
      if (!bufferdata)
      {
LABEL_128:
        SwitchSpeaker(0, 0);
        pinst->stat &= 0xFFFFCFFF;
        speaker->num = 0;
          goto LABEL_118;
        goto LABEL_69;
      }
    }
    else
    {
      pm = speaker->pos->pm;
      max_length = pm->max_length;
      v70 = pm->m_Items[0];
      v71 = speaker->pos->pm->m_Items[1];
      SpeakerName = GetSpeakerName(pinst);
      bufferdata = MessageRequestExLocalize(v70, v71, 0, 3u, 0, 8u, SpeakerName, 0);
      speaker->pfont = bufferdata;
      if (!bufferdata)
        goto LABEL_128;
    }
    v74 = speaker->pos->pm;
    v75 = v74->max_length;
    v77 = v74->m_Items[0];
    v79 = speaker->pos->pm->m_Items[1];
    bufferdata->x = v77;
    bufferdata->y = v79;
    speaker->pfont->draw_spd = 20;
    prev = speaker->pfont;
    z = pinst->z;
    for (; prev; prev = prev->prev)
      prev->priority = z;
      goto LABEL_118;
    goto LABEL_69;
  }
  SwitchSpeaker(pfont != 0, pfont != 0);
  SwitchSpeaker(speaker->pfont != 0, speaker->pfont != 0);
    goto LABEL_118;
LABEL_69:
LABEL_118:
  OpenCheckSpeakerWindow(pinst);
  stat = pinst->stat;
  if ((stat & 0x200000) == 0)
    goto LABEL_119;
LABEL_71:
  if ((stat & 0x300) == 0x300 || (stat & 0x300) == 0)
  {
    OpenMessageWindow(pinst);
    stat = pinst->stat;
    v65 = 2;
    goto LABEL_120;
  }
LABEL_119:
  v65 = 3;
LABEL_120:
  result = 1;
  pinst->stat = stat & 0xFFFFFFF8 | v65;
  v49->phase = 1;
  return result;
}

// 0x13a8a10
void itfMesMngRequestMessageRelease(s32 id, s32 cls_speaker) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  struct message_tag_o *message;
  _FRQ_o *pfont;
  struct _FRQ_o **p_pfont;
  struct Speaker_tag_o *speaker;
  _FRQ_o *v13;
  System_Object_array *v17;
  struct Speaker_tag_o *v19;

  if ((id & 0x80000000) == 0)
  {
    pmesflow = g_manager->pmesflow;
    pinst = pmesflow->m_Items[id]->pinst;
    message = pinst->message;
    p_pfont = &message->pfont;
    pfont = message->pfont;
    if (pfont)
    {
      frDestroyFontRequestAfter(pfont, *&cls_speaker);
      *p_pfont = 0;
    }
    *&message->lines = 0;
    message->maxpage = 0;
    *(&message->pfont + 5) = 0;
    *p_pfont = 0;
    message->last_spd = 0x80;
    pinst->stat &= 0xFFFDFFF8;
    if (cls_speaker)
    {
      speaker = pinst->speaker;
      v13 = speaker->pfont;
      if (v13)
      {
        frDestroyFontRequestAfter(v13, *&cls_speaker);
        speaker->pfont = 0;
        SwitchSpeaker(0, 0);
      }
      v17 = Empty_string_();
      Log("@@@@@ SelectMessageRelease @@@@@", v17, 0);
      v19 = pinst->speaker;
      v19->pfont = 0;
      v19->num = -1;
    }
  }
}

// 0x13af9e0
void itfMesMngRequestSelect(s32 id, s32 select) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  Il2CppObject *pdata;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  itfMesBinTypeHeader_t_o *TypeHeader;
  struct select_tag_o *v16;
  _FRQ_o *pfont;
  itfMesBinTypeHeader_t_o *v18;
  s32 ptr;
  System_Array_o *v22;
  s16 v24;
  u64 v25;
  u64 *v26;
  u64 *v28;
  u64 v29;
  s32 v30;
  u32 v31;
  s32 v34;
  s32 v35;
  s64 v37;
  u64 v38;
  s32 v39;
  u64 v40;
  u64 v41;
  s32 v44;
  s32 v46;
  u32 mask;
  s32 v49;
  s32 v50;
  char v51;
  struct System_Int32_array *pm;
  s32 v54;
  s32 v55;
  s64 pext;
  struct System_Int32_array *v59;
  u32 v60;
  s32 v61;
  s32 v63;
  u32 z;
  System_Object_array *v68;
  System_Byte_array *dat;
  struct select_tag_o *v71;
  u64 v72[3];

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  pdata = pinst->pdata;
  if (pdata)
  {
    Interface = QueryInterface(pinst->pdata, byte);
    if (!Interface)
    {
      sub_8FC2C0(pdata->klass->_1.element_class, v10, v72);
      if ((v72[0] & 1) != 0)
        v12 = v72[2];
      else
        v12 = v72 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  TypeHeader = GetTypeHeader(pinst, select);
  v16 = pinst->select;
  pfont = v16->pfont;
  v18 = TypeHeader;
  if (pfont)
  {
    frDestroyFontRequestAfter(pfont);
    v16->pfont = 0;
    ClearMessage();
  }
  v71 = v16;
  ptr = v18->ptr;
  v22 = NewSpecific(byte, 0x18u);
  Copy_3880080(Interface, ptr + 32, v22, 0, 24);
  ToInt16(Interface, ptr + 56, 0);
  v24 = ToInt16(Interface, ptr + 58, 0);
  ToInt16(Interface, ptr + 60, 0);
  ToUInt16(Interface, ptr + 62);
  v25 = v24;
  v26 = NewSpecific(uint, v25);
  v28 = NewSpecific(s32, v25);
  if (v25 >= 1)
  {
    v29 = 0;
    v30 = ptr + 64;
    do
    {
      v31 = ToUInt32(Interface, v30, 0) + 32;
      *(v26 + v29++ + 8) = v31;
      v30 += 4;
    }
    while (v25 != v29);
  }
  v34 = *(v26 + 8) - 4;
  v35 = ToInt32(Interface, v34, 0);
  v37 = v25 - 1LL;
  dat = Interface;
  if (v37 < 1)
  {
    v46 = -1;
  }
  else
  {
    v38 = 0;
    v39 = 0;
    do
    {
      v40 = *(v26 + 6);
      v41 = v38 + 1;
      v44 = *(v26 + v38 + 9) - *(v26 + v38 + 8);
      *(v28 + v38 + 8) = v44;
      v39 += v44;
      ++v38;
    }
    while (v37 != v41);
    v46 = ~v39;
  }
  *(v28 + v37 + 8) = v35 + v46;
  mask = v71->mask;
  if (v25 < 1)
    goto LABEL_59;
LABEL_55:
  v49 = 0;
  v50 = v25 + 1;
  do
  {
    v51 = ~mask;
    mask >>= 1;
    --v50;
    v49 += v51 & 1;
  }
  while (v50 > 1);
LABEL_60:
  pm = v71->pos->pm;
  v54 = pm->m_Items[1];
  v55 = CMP_YM(33 * v49 - 33);
  CommitVarTable(pinst->variable);
  pext = pinst->pext;
  if (pext)
  {
    il2cp::SizeOf(pext, qword_3F088F8);
  }
  v59 = v71->pos->pm;
  v60 = v71->mask;
  v61 = v54 - v55;
  v63 = v59->m_Items[0];
  z = pinst->z;
  v71->pfont = GetFontHandleUnit(dat, v26, v28, v25, v60, v63, v61, z);
  v71->lines = v49;
  pinst->stat = pinst->stat & 0xFFFFFFC7 | 0x10;
  WindowDispOn_20618496(pinst);
  SelectWindowDispOn(pinst);
  v71->phase = 1;
  v68 = Empty_string_();
  Log("@@@@@ SelectRequest @@@@@", v68, 0);
}

// 0x13a8c20
void itfMesMngRequestSelectRelease(s32 id) {
  struct mesflow_tag_array *pmesflow;
  instanceMes_tag_o *pinst;
  struct select_tag_o *select;
  _FRQ_o *pfont;
  u32 stat;
  System_Object_array *v11;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  select = pinst->select;
  pfont = select->pfont;
  if (pfont)
  {
    frDestroyFontRequestAfter(pfont);
    select->pfont = 0;
  }
  select->lines = 0;
  *&select->mask = 0xFFFF000000000000LL;
  stat = pinst->stat;
  if ((stat & 0x40038) != 0)
  {
    pinst->stat = stat & 0xFFFBFFC7;
    SelectWindowDispOff(pinst);
    v11 = Empty_string_();
    Log("@@@@@ SelectRelease @@@@@", v11, 0);
  }
}

// 0x13af830
s32 itfMesMngSelect(void) {
  s32 MessageHandle;
  s32 v4;
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  s32 IntPara;
  struct select_tag_o *select;
  s32 v14;
  s32 v15;

  MessageHandle = scrGetMessageHandle();
  if (MessageHandle < 0)
    return 1;
LABEL_6:
  v4 = MessageHandle;
  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[v4]->pinst;
  IntPara = scrGetIntPara(0);
  select = pinst->select;
  if (select->phase)
  {
    if ((select->phase & 0x80000000) == 0)
      return 0;
    select->phase = 0;
    v15 = select->select;
    scrSetIntReturnValue(v15);
    itfMesMngRequestSelectRelease(v4);
    return 1;
  }
  v14 = IntPara;
  itfMesMngRequestSelect(v4, v14);
  return 0;
}

// 0x13b1ed0
s32 itfMesMngSelectDefKey(void) {
  s32 MessageHandle;
  s32 v4;
  s32 IntPara;
  s32 v8;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    IntPara = scrGetIntPara(0);
    v8 = scrGetIntPara(1);
    itfMesMngSetSelectDefKey(v4, IntPara, v8);
  }
  return 1;
}

// 0x13b4ee0
void itfMesMngSetBitStatManager(s32 flags) {
  s16 v2;

  v2 = flags;
  g_manager->stat |= v2;
}

// 0x13b4570
void itfMesMngSetDefaultSpeed(s32 id, s32 speed) {
  u8 v3;
  struct mesflow_tag_array *pmesflow;

  v3 = speed;
  pmesflow = g_manager->pmesflow;
  pmesflow->m_Items[id]->pinst->message->last_spd = v3;
}

// 0x13b4620
void itfMesMngSetKutiCallback(s32 id, instanceMes_tag_func_kutiDelegate *func) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  pmesflow->m_Items[id]->pinst->func_kuti = func;
}

// 0x13b03b0
void itfMesMngSetMaskSelect(s32 id, u32 maskpattern) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  pmesflow->m_Items[id]->pinst->select->mask = maskpattern;
}

// 0x13b16a0
s32 itfMesMngSetMesPosDefault(void) {
  if ((scrGetMessageHandle() & 0x80000000) == 0)
  {
    itfMesPosDefault();
  }
  return 1;
}

// 0x13b2e50
void itfMesMngSetMesPosition(s32 id, s32 x, s32 y) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  sdfIVector2_t_o *v11;
  struct message_tag_o *message;
  struct System_Int32_array *pm;
  struct System_Int32_array *v15;
  s32 v16;
  struct System_Int32_array *v18;
  struct System_Int32_array *v19;
  s32 v21;
  struct System_Int32_array *v22;
  struct System_Int32_array *v23;
  struct System_Int32_array *v27;
  struct _FRQ_o *pfont;
  u32 max_length;
  s32 v30;
  s32 v31;
  s32 v35;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  v11 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v11);
  message = pinst->message;
  pm = message->pos->pm;
  v15 = v11->pm;
  v16 = x - pm->m_Items[0];
  v15->m_Items[0] = v16;
  v18 = message->pos->pm;
  v19 = v11->pm;
  v21 = y - v18->m_Items[1];
  v19->m_Items[1] = v21;
  v22 = v11->pm;
  if (v22->m_Items[0])
    goto LABEL_22;
  v23 = v11->pm;
  if (v23->m_Items[1])
  {
LABEL_22:
    v27 = v11->pm;
    pfont = message->pfont;
    max_length = v27->max_length;
    v30 = v27->m_Items[0];
    v31 = v27->m_Items[1];
    else
    {
      if (!pfont)
        goto LABEL_33;
    }
    do
    {
      v35 = pfont->y;
      pfont->x += v30;
      pfont->y = v35 + v31;
      pfont = pfont->prev;
    }
    while (pfont);
    goto LABEL_33;
  }
}

// 0x13b3140
void itfMesMngSetMesPositionOffset(s32 id, s32 x, s32 y) {
  struct mesflow_tag_array *pmesflow;
  struct message_tag_o *message;
  struct _FRQ_o *i;
  s32 v12;
  struct System_Int32_array *pm;
  struct System_Int32_array *v14;

  pmesflow = g_manager->pmesflow;
  message = pmesflow->m_Items[id]->pinst->message;
  for (i = message->pfont; i; i = i->prev)
  {
    v12 = i->y;
    i->x += x;
    i->y = v12 + y;
  }
  pm = message->pos->pm;
  pm->m_Items[0] += x;
  v14 = message->pos->pm;
  v14->m_Items[1] += y;
}

// 0x13b13f0
s32 itfMesMngSetMesPositionScript(void) {
  s32 IntPara;
  s32 v6;

  if ((scrGetMessageHandle() & 0x80000000) == 0)
  {
    scrGetIntPara(0);
    IntPara = scrGetIntPara(1);
    itfMesPos(v6, IntPara);
  }
  return 1;
}

// 0x13af5e0
void itfMesMngSetOffsetY1(s32 msgid, s32 y1) {
  struct mesflow_tag_array *pmesflow;
  itfpanel_t_o *mes;

  pmesflow = g_manager->pmesflow;
  mes = pmesflow->m_Items[msgid]->pinst->window->mes;
  itfPnlSetPositionOffset(mes, 0, y1, 0, 0, 0);
}

// 0x13af780
void itfMesMngSetPhase(s32 msgid, s32 phase) {
  s8 v3;
  struct mesflow_tag_array *pmesflow;

  v3 = phase;
  pmesflow = g_manager->pmesflow;
  pmesflow->m_Items[msgid]->pinst->message->phase = v3;
}

// 0x13b3750
void itfMesMngSetPriority(s32 id, u32 z_buf) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  struct _FRQ_o *pfont;
  struct _FRQ_o *i;
  struct _FRQ_o *j;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  if (pinst->z != z_buf)
  {
    pfont = pinst->speaker->pfont;
    for (; pfont; pfont = pfont->prev)
      pfont->priority = z_buf;
    for (i = pinst->message->pfont; i; i = i->prev)
      i->priority = z_buf;
    for (j = pinst->select->pfont; j; j = j->prev)
      j->priority = z_buf;
    pinst->z = z_buf;
  }
}

// 0x13b2570
void *itfMesMngSetResourcePtr(s32 id, void *presource) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  Il2CppObject *pdata;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 *v14;
  u64 v17[2];
  char *v18;
  s64 v19;
  s32 pos;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  pdata = pinst->pdata;
  pinst->pdata = presource;
  if (presource)
  {
    Interface = QueryInterface(presource, byte);
    if (!Interface)
    {
      sub_8FC2C0(presource->klass->_1.element_class, v10, v17);
      if ((v17[0] & 1) != 0)
        v12 = v18;
      else
        v12 = v17 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  else
  {
    Interface = 0;
  }
  pos = 0;
  v18 = 0;
  v19 = 0;
  v17[0] = 0;
  v17[1] = 0;
  sub_13A7EC0(v17, Interface, &pos);
  pos += 8 * v19;
  v14 = Allocate(itfMesBinTypeHeader2_t);
  itfMesBinTypeHeader2_t___ctor(v14, Interface, &pos);
  return pdata;
}

// 0x13b0100
void itfMesMngSetSelPhase(s32 msgid, s32 phase) {
  s16 v3;
  struct mesflow_tag_array *pmesflow;

  v3 = phase;
  pmesflow = g_manager->pmesflow;
  pmesflow->m_Items[msgid]->pinst->select->phase = v3;
}

// 0x13b32d0
void itfMesMngSetSelPosition(s32 id, s32 x, s32 y) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  sdfIVector2_t_o *v11;
  struct select_tag_o *select;
  struct System_Int32_array *pm;
  struct System_Int32_array *v15;
  s32 v16;
  struct System_Int32_array *v18;
  struct System_Int32_array *v19;
  s32 v21;
  struct System_Int32_array *v22;
  struct System_Int32_array *v23;
  struct System_Int32_array *v27;
  struct _FRQ_o *pfont;
  u32 max_length;
  s32 v30;
  s32 v31;
  s32 v35;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  v11 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v11);
  select = pinst->select;
  pm = select->pos->pm;
  v15 = v11->pm;
  v16 = x - pm->m_Items[0];
  v15->m_Items[0] = v16;
  v18 = select->pos->pm;
  v19 = v11->pm;
  v21 = y - v18->m_Items[1];
  v19->m_Items[1] = v21;
  v22 = v11->pm;
  if (v22->m_Items[0])
    goto LABEL_22;
  v23 = v11->pm;
  if (v23->m_Items[1])
  {
LABEL_22:
    v27 = v11->pm;
    pfont = select->pfont;
    max_length = v27->max_length;
    v30 = v27->m_Items[0];
    v31 = v27->m_Items[1];
    else
    {
      if (!pfont)
        goto LABEL_33;
    }
    do
    {
      v35 = pfont->y;
      pfont->x += v30;
      pfont->y = v35 + v31;
      pfont = pfont->prev;
    }
    while (pfont);
    goto LABEL_33;
  }
}

// 0x13b35c0
void itfMesMngSetSelPositionOffset(s32 id, s32 x, s32 y) {
  struct mesflow_tag_array *pmesflow;
  struct select_tag_o *select;
  struct _FRQ_o *i;
  s32 v12;
  struct System_Int32_array *pm;
  struct System_Int32_array *v14;

  pmesflow = g_manager->pmesflow;
  select = pmesflow->m_Items[id]->pinst->select;
  for (i = select->pfont; i; i = i->prev)
  {
    v12 = i->y;
    i->x += x;
    i->y = v12 + y;
  }
  pm = select->pos->pm;
  pm->m_Items[0] += x;
  v14 = select->pos->pm;
  v14->m_Items[1] += y;
}

// 0x13b0530
void itfMesMngSetSelect(s32 id, s32 selno) {
  s32 v3;
  struct mesflow_tag_array *pmesflow;
  struct select_tag_o *select;
  u32 mask;
  s32 v11;
  char v12;
  s32 v13;
  u32 v14;
  s16 v15;
  s16 v16;

  pmesflow = g_manager->pmesflow;
  select = pmesflow->m_Items[id]->pinst->select;
  mask = select->mask;
  v11 = (mask & 1) == 0;
  if (selno < 1)
  {
    v12 = mask & 1;
  }
  else
  {
    if (selno != 1)
    {
      v13 = (selno & 1) - selno;
      do
      {
        v14 = mask;
        v11 += ((mask >> 1) & 1) == 0;
        mask >>= 2;
        if ((v14 & 4) == 0)
          ++v11;
        v13 += 2;
      }
      while (v13);
      v3 = (v14 >> 2) & 1;
    }
    if ((mask & 2) != 0)
      v15 = v11;
    else
      v15 = v11 + 1;
    if ((selno & 1) != 0)
      v12 = (mask & 2) != 0;
    else
      v12 = v3;
    if ((selno & 1) != 0)
      LOWORD(v11) = v15;
  }
  v16 = v11 - 1;
  if ((v12 & 1) != 0)
    v16 = 0;
  select->select = v16;
  select->select_imm = v16;
}

// 0x13b1fb0
s32 itfMesMngSetSelectDefKey(s32 id, s32 key, s32 index) {
  s16 v4;
  struct mesflow_tag_array *pmesflow;
  struct select_tag_o *select;
  s32 v12;
  s64 numdef;
  s64 v14;
  struct defkey_tag_array *defkey;
  s64 v17;
  struct defkey_tag_array *v18;
  defkey_tag_o *v20;
  struct defkey_tag_array *v21;

  v4 = index;
  pmesflow = g_manager->pmesflow;
  if (key > 0xF)
    return 0;
  select = pmesflow->m_Items[id]->pinst->select;
  v12 = 0;
  if ((key & 0xFFFFFFFE) != 6 && SDF_PADMAP_OK != key)
  {
    LODWORD(numdef) = select->numdef;
    if (numdef >= 1)
    {
      v14 = 4;
      while (1)
      {
        defkey = select->defkey;
        if (*(*(&defkey->obj.klass + v14) + 16LL) == key)
          break;
        numdef = select->numdef;
        v17 = v14 - 3;
        ++v14;
        if (v17 >= numdef)
        {
          if (numdef > 14)
            return 0;
          goto LABEL_21;
        }
      }
      v21 = select->defkey;
      v20 = *(&v21->obj.klass + v14);
      if (v20)
        goto LABEL_27;
      LOWORD(numdef) = select->numdef;
      if (numdef <= 14)
        goto LABEL_21;
      return 0;
    }
LABEL_21:
    v18 = select->defkey;
    v20 = v18->m_Items[numdef];
    select->numdef = numdef + 1;
LABEL_27:
    v12 = 1;
    v20->key = key;
    v20->index = v4;
  }
  return v12;
}

// 0x13b29d0
void itfMesMngSetSpeakerPosition(s32 id, s32 x, s32 y) {
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  sdfIVector2_t_o *v11;
  struct Speaker_tag_o *speaker;
  struct System_Int32_array *pm;
  struct System_Int32_array *v15;
  s32 v16;
  struct System_Int32_array *v18;
  struct System_Int32_array *v19;
  s32 v21;
  struct System_Int32_array *v22;
  struct System_Int32_array *v23;
  struct System_Int32_array *v27;
  struct _FRQ_o *pfont;
  u32 max_length;
  s32 v30;
  s32 v31;
  s32 v35;

  pmesflow = g_manager->pmesflow;
  pinst = pmesflow->m_Items[id]->pinst;
  v11 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v11);
  speaker = pinst->speaker;
  pm = speaker->pos->pm;
  v15 = v11->pm;
  v16 = x - pm->m_Items[0];
  v15->m_Items[0] = v16;
  v18 = speaker->pos->pm;
  v19 = v11->pm;
  v21 = y - v18->m_Items[1];
  v19->m_Items[1] = v21;
  v22 = v11->pm;
  if (v22->m_Items[0])
    goto LABEL_22;
  v23 = v11->pm;
  if (v23->m_Items[1])
  {
LABEL_22:
    v27 = v11->pm;
    pfont = speaker->pfont;
    max_length = v27->max_length;
    v30 = v27->m_Items[0];
    v31 = v27->m_Items[1];
    else
    {
      if (!pfont)
        goto LABEL_33;
    }
    do
    {
      v35 = pfont->y;
      pfont->x += v30;
      pfont->y = v35 + v31;
      pfont = pfont->prev;
    }
    while (pfont);
    goto LABEL_33;
  }
}

// 0x13b2cc0
void itfMesMngSetSpeakerPositionOffset(s32 id, s32 x, s32 y) {
  struct mesflow_tag_array *pmesflow;
  struct Speaker_tag_o *speaker;
  struct _FRQ_o *i;
  s32 v12;
  struct System_Int32_array *pm;
  struct System_Int32_array *v14;
  u32 max_length;
  s32 v16;

  pmesflow = g_manager->pmesflow;
  speaker = pmesflow->m_Items[id]->pinst->speaker;
  for (i = speaker->pfont; i; i = i->prev)
  {
    v12 = i->y;
    i->x += x;
    i->y = v12 + y;
  }
  pm = speaker->pos->pm;
  pm->m_Items[0] += x;
  v14 = speaker->pos->pm;
  max_length = v14->max_length;
  v16 = v14->m_Items[0] + y;
  v14->m_Items[1] = v16;
}

// 0x13b3920
void itfMesMngSetStat(s32 id, u32 flag) {
  s16 v3;
  struct mesflow_tag_array *pmesflow;

  v3 = HIWORD(flag);
  pmesflow = g_manager->pmesflow;
  HIWORD(pmesflow->m_Items[id]->pinst->stat) = v3;
}

// 0x13b0c50
void itfMesMngSetVar(s32 id, s32 index, s32 num, s32 type) {
  s32 v6;
  u64 *v9;
  System_String_o *v10;
  System_String_o *Tag;
  System_String_o *LocalizeText;
  System_String_o *v16;
  s64 *v17;
  System_String_o *SaveNmlName;
  System_String_o *v21;
  System_String_o *v23;
  s32 v24;
  s32 v25;
  System_String_o *CNameString;
  s32 v28;
  s32 v30;
  System_String_o *buf;

  v6 = num;
  buf = 0;
  switch (type)
  {
    case 0:
      v30 = v6;
      v9 = sub_8D3950(s32, &v30);
      v10 = Format("{0:D}", v9, 0);
      goto LABEL_81;
    case 1:
      Tag = GetTag(v6, 0);
      LocalizeText = GetLocalizeText(Tag);
      goto LABEL_71;
    case 3:
      LocalizeText = Get(v6, 0);
      goto LABEL_71;
    case 4:
      v16 = "";
      buf = "";
      if (v6 > 1000)
      {
        v17 = &"Ｒ";
      }
      else
      {
        if (v6 < 0)
        {
          v6 = -v6;
          buf = Concat_5224608("", "Ｂ");
        }
        ConvertZenkakuNumber(&buf, v6, *&num);
        v17 = &"Ｆ";
        v16 = buf;
      }
      v10 = Concat_5224608(v16, *v17);
LABEL_81:
      v21 = v10;
      buf = v10;
        goto LABEL_82;
      goto LABEL_51;
    case 5:
      LocalizeText = Get(v6, 0, 0);
      goto LABEL_71;
    case 6:
      SaveNmlName = GetSaveNmlName(fldNameData, v6);
      goto LABEL_50;
    case 7:
      SaveNmlName = GetSaveSmlName(fldNameData, v6);
LABEL_50:
      v21 = SaveNmlName;
      {
LABEL_51:
      }
LABEL_82:
      v24 = id;
      v25 = index;
      v23 = v21;
      goto LABEL_83;
    case 8:
      LocalizeText = Get(v6, 0, 0);
      goto LABEL_71;
    case 9:
      LocalizeText = Get(v6, 0);
LABEL_71:
      v23 = LocalizeText;
      v24 = id;
      v25 = index;
LABEL_83:
      itfMesMngSetVarImmediate(v24, v25, v23);
      break;
    case 10:
      CNameString = frGetCNameString(0, *&index);
      get_Length(CNameString);
      itfMesMngSetVarImmediate2(id, index, CNameString, v28);
      break;
    default:
      return;
  }
}

// 0x13b3d40
void itfMesMngSetVarImmediate(s32 id, s32 index, char *pstr) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  SetVar(pmesflow->m_Items[id]->pinst, index, pstr);
}

// 0x13b3e00
void itfMesMngSetVarImmediate2(s32 id, s32 index, char *pstr, s32 length) {
  struct mesflow_tag_array *pmesflow;

  pmesflow = g_manager->pmesflow;
  SetVar(pmesflow->m_Items[id]->pinst, index, pstr, length);
}

// 0x13b0b50
s32 itfMesMngSetVarScr(void) {
  s32 MessageHandle;
  s32 v4;
  s32 IntPara;
  s32 v6;
  s32 v9;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    IntPara = scrGetIntPara(0);
    v6 = scrGetIntPara(1);
    v9 = scrGetIntPara(2);
    itfMesMngSetVar(v4, IntPara, v6, v9);
  }
  return 1;
}

// 0x13b18d0
s32 itfMesMngValidateNext(void) {
  s32 MessageHandle;
  s32 v4;
  struct mesflow_tag_array *pmesflow;
  struct instanceMes_tag_o *pinst;
  struct mesflow_tag_array *v11;
  struct instanceMes_tag_o *v13;
  u32 v14;
  struct mesflow_tag_array *v16;
  struct instanceMes_tag_o *v18;
  struct mesflow_tag_array *v20;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    if (scrGetIntPara(0))
    {
      pmesflow = g_manager->pmesflow;
      pinst = pmesflow->m_Items[v4]->pinst;
      pinst->stat &= ~0x800000u;
      v11 = g_manager->pmesflow;
      v13 = v11->m_Items[v4]->pinst;
      v14 = v13->stat & 0xFFEFFFFF;
    }
    else
    {
      v16 = g_manager->pmesflow;
      v18 = v16->m_Items[v4]->pinst;
      v18->stat |= 0x800000u;
      v20 = g_manager->pmesflow;
      v13 = v20->m_Items[v4]->pinst;
      v14 = v13->stat | 0x100000;
    }
    v13->stat = v14;
  }
  return 1;
}

// 0x13b1bb0
s32 itfMesMngWindowType(void) {
  s32 MessageHandle;
  s32 v4;
  s32 IntPara;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    IntPara = scrGetIntPara(0);
    itfMesMngChangeWindowType(v4, IntPara, 0);
  }
  return 1;
}

// 0x13b1df0
s32 itfMesMngWindowTypeAlpha(void) {
  s32 MessageHandle;
  s32 v4;
  s32 IntPara;
  s32 v8;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    IntPara = scrGetIntPara(0);
    v8 = scrGetIntPara(1);
    itfMesMngChangeWindowType(v4, IntPara, v8);
  }
  return 1;
}

// 0x13b0460
s32 itfMesMng_SEL_SELNO(void) {
  s32 MessageHandle;
  s32 v4;
  s32 IntPara;

  MessageHandle = scrGetMessageHandle();
  if ((MessageHandle & 0x80000000) == 0)
  {
    v4 = MessageHandle;
    IntPara = scrGetIntPara(0);
    itfMesMngSetSelect(v4, IntPara);
  }
  return 1;
}

// 0x13b14c0
void itfMesPos(s32 x, s32 y) {
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  Il2CppObject *v10;
  f32 v11;
  UnityEngine_Transform_o *v12;
  f32 v13;
  UnityEngine_Transform_o *v14;
  System_WeakReference_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_GameObject_o *v18;
  Il2CppObject *v19;
  UnityEngine_Transform_o *v20;
  UnityEngine_Transform_o *v21;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v23;
  UnityEngine_Vector3_o v24;
  UnityEngine_Vector3_o v25;

  Item = _get_Item(
           MsgWnd,
           0);
  transform = get_transform(Item, 0);
  Child = GetChild(transform, 0);
  gameObject = get_gameObject(Child);
  Component_object = GetComponent_object_(gameObject);
  set_enabled(Component_object, 0);
  v10 = GetComponent_object_(gameObject);
  v11 = COERCE_FLOAT(LODWORD(get_sizeDelta(v10).y)) * 0.5;
  v12 = get_transform(gameObject, 0);
  localPosition = get_localPosition(v12);
  v13 = 380.0 - (v11 + y);
  v14 = get_transform(gameObject, 0);
  v24.x = localPosition.x;
  v24.y = v13;
  v24.z = localPosition.z;
  set_localPosition(v14, v24);
  v15 = _get_Item(
          MsgWnd,
          3);
  v16 = get_transform(v15, 0);
  v17 = GetChild(v16, 0);
  v18 = get_gameObject(v17);
  v19 = GetComponent_object_(v18);
  set_enabled(v19, 0);
  v20 = get_transform(v18, 0);
  v23 = get_localPosition(v20);
  v21 = get_transform(v18, 0);
  v25.x = v23.x;
  v25.y = v13;
  v25.z = v23.z;
  set_localPosition(v21, v25);
}

// 0x13b1730
void itfMesPosDefault(void) {
  System_WeakReference_o *Item;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *v8;
  UnityEngine_Transform_o *v9;
  System_WeakReference_o *v10;
  UnityEngine_Transform_o *v11;
  UnityEngine_Component_o *v12;
  UnityEngine_GameObject_o *v13;
  Il2CppObject *v14;
  UnityEngine_Transform_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v18;
  UnityEngine_Vector3_o v19;
  UnityEngine_Vector3_o v20;

  Item = _get_Item(
           MsgWnd,
           0);
  transform = get_transform(Item, 0);
  Child = GetChild(transform, 0);
  gameObject = get_gameObject(Child);
  Component_object = GetComponent_object_(gameObject);
  set_enabled(Component_object, 1);
  v8 = get_transform(gameObject, 0);
  localPosition = get_localPosition(v8);
  v9 = get_transform(gameObject, 0);
  v19.x = localPosition.x;
  v19.z = localPosition.z;
  v19.y = -352.0;
  set_localPosition(v9, v19);
  v10 = _get_Item(
          MsgWnd,
          3);
  v11 = get_transform(v10, 0);
  v12 = GetChild(v11, 0);
  v13 = get_gameObject(v12);
  v14 = GetComponent_object_(v13);
  set_enabled(v14, 1);
  v15 = get_transform(v13, 0);
  v18 = get_localPosition(v15);
  v16 = get_transform(v13, 0);
  v20.x = v18.x;
  v20.y = -352.0;
  v20.z = v18.z;
  set_localPosition(v16, v20);
}
