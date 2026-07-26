#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct debug_tag debug_tag;
typedef struct fldSceneParam_t fldSceneParam_t;
typedef struct pacFileHandle_t pacFileHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct tgsGlobal tgsGlobal;

static tgsGlobal *gGlobal;
static s32 gGemeMode;
static s32 NoClip;
static s32 EncountOn;
static s32 SCE_WRONLY;
static s32 SCE_TRUNC;
static s32 SCE_CREAT;
static s32 F061_SMG;
static s32 F061_01;
static s32 P2SDREQ_OK;
static s32 P2SDREQ_CANSEL;
static s32 P2SDREQ_CURSOR_NORMAL;
static void htitMem_v[UNKNOWN_ARRAY_SIZE];
static void hmoaMem_v[UNKNOWN_ARRAY_SIZE];
static void hmodMem_v[UNKNOWN_ARRAY_SIZE];
static char *tit_textbl[5];
static char *moa_textbl[4];
static char *mod_textbl[4];

bool DDS3_PAD2CHECK_TRIG(s32 id);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void TgsTitle_CurDraw(s32 flg);
void TgsTitle_DrawMask(void);
void TgsTitle_DrawMode(s32 flg);
void TgsTitle_DrawTitle(s32 flg);
void TgsTitle_GetAlpha(void);
void TgsTitle_MCurDraw(s32 flg);
void TgsTitle_MemoryInit(void);
void TgsTitle_ModeRGBASet(void);
void TgsTitle_SpriteDelete(s32 sw);
void TgsTitle_SpriteDelete_Vram(s32 sw);
void TgsTitle_SpriteLoad(s32 flg);
void TgsTitle_SpriteSetVram(s32 sw);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3CreateGameData(s32 no);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void dds3GlobalWorkUserInit2(s32 mode);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void eglLinkAlpha(s32 mode);
void eglLinkBox(s32 x, s32 y, s32 w, s32 h, s32 rgba0, s32 rgba1, s32 rgba2, s32 rgba3);
void eglLinkSprite(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba0, s32 rgba1, s32 rgba2, s32 rgba3, sdfTexHandle_t *th);
void eglLinkTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void eglSetOt(s32 ot);
void evtBitOn(s32 no);
sdfTexHandle_t *fclLoadTexture(char *pFileName);
void fldProcNext(s32 fld, s32 eveno);
void fldSetSceneParam2(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName);
s32 p2sdFadeIn(s32 a);
s32 p2sdFadeOut(s32 a);
s32 p2sdLoadCheckMidi(s32 MidiNo);
void p2sdLoadSMGFile(s32 MidiNo);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
char *sdfFileGetHostRoot(void);
debug_tag *sdfMemLock(void *aHandle);
f32 sdfSin(f32 aRadius);
void sdfTexFree(sdfTexHandle_t *aHandle);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);
sdfTexHandle_t *sdfTexSet(void *aTex);
void tgsCheckPadInput(void);
void tgsCheckPadInput2(void);
void tgsDestroySprite(void);
void tgsDrawKotowari(void);
void tgsInit(s32 mode);
void tgsInitSprite(void);
void tgsLoad(s32 mode);
void tgsNext1(void);
void tgsSave(s32 mode);

// 0x1853df0
void TgsTitle_CurDraw(s32 flg) {
  s16 v3;
  s32 v4;
  struct tgsGlobal_o *gGlobal;
  s32 v6;
  u32 titcur_alpha;
  struct tgsGlobal_o *v9;
  u32 titcur_cnt;
  s32 v11;
  s32 v12;
  struct sdfTexHandle_t_array *htittex;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  if (gGlobal->ModePos)
    v6 = 244;
  else
    v6 = 7;
  titcur_alpha = gGlobal->titcur_alpha;
  eglSetOt(71);
  eglLinkTest(1, 1, 128, 3, 0, 0, 1, 1);
  v9 = gGlobal;
  titcur_cnt = v9->titcur_cnt;
  v11 = titcur_cnt - 180;
  v12 = -180 - titcur_cnt;
  if (v11 >= 0)
    v12 = v11;
  v9->titcur_w = v12;
  eglLinkAlpha(1);
  htittex = gGlobal->htittex;
  eglLinkSprite(
    v6,
    180,
    258,
    258,
    0,
    0,
    256,
    256,
    (titcur_alpha << 24) | 0x808080,
    (titcur_alpha << 24) | 0x808080,
    (titcur_alpha << 24) | 0x808080,
    (titcur_alpha << 24) | 0x808080,
    htittex->m_Items[4],
    0);
}

// 0x18549c0
void TgsTitle_DrawMask(void) {
  s32 v4;

  eglSetOt(71);
  eglLinkTest(1, 1, 128, 3, 0, 0, 1, 1);
  v4 = (gGlobal->bg_maskrgba << 24) | 0x404040;
  eglLinkAlpha(2);
  eglLinkBox(0, 0, 512, 448, v4, v4, v4, v4);
}

// 0x1854c50
void TgsTitle_DrawMode(s32 flg) {
  struct tgsGlobal_o *gGlobal;
  struct System_UInt32_array *mode_rgba;
  struct tgsGlobal_o *v11;
  struct System_UInt32_array *v12;
  s32 v13;
  struct sdfTexHandle_t_array *hmoatex;
  struct tgsGlobal_o *v15;
  struct System_UInt32_array *v16;
  s32 rgba1;
  struct tgsGlobal_o *v20;
  struct System_UInt32_array *v21;
  s32 v22;
  struct sdfTexHandle_t_array *hmodtex;
  struct tgsGlobal_o *v24;
  struct System_UInt32_array *v25;
  s32 v26;
  s32 rgba3;
  struct sdfTexHandle_t_array *v32;
  struct tgsGlobal_o *v35;
  struct System_UInt32_array *v36;
  s32 v37;
  s32 v38;
  s32 rgba2;
  s32 v41;
  struct sdfTexHandle_t_array *v42;
  s32 v46;
  struct sdfTexHandle_t_array *v47;
  struct tgsGlobal_o *v50;
  struct System_UInt32_array *v51;

  eglSetOt(71);
  eglLinkTest(1, 1, 128, 3, 0, 0, 1, 1);
  if (!flg)
  {
    mode_rgba = gGlobal->mode_rgba;
    mode_rgba->m_Items[1] = (gGlobal->mode_alpha << 24) | 0x808080;
  }
  if (gGlobal->ModePos)
  {
    eglLinkAlpha(0);
    v11 = gGlobal;
    v12 = v11->mode_rgba;
    v13 = v12->m_Items[0];
    hmoatex = v11->hmoatex;
    eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, v13, v11->mode_rgba->m_Items[0], v11->mode_rgba->m_Items[0], v11->mode_rgba->m_Items[0], hmoatex->m_Items[0]);
    eglLinkAlpha(1);
    v15 = gGlobal;
    v16 = v15->mode_rgba;
    rgba1 = v16->m_Items[1];
    rgba3 = v16->m_Items[1];
    v32 = v15->hmoatex;
    eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, rgba1, rgba1, rgba1, rgba3, v32->m_Items[1]);
    TgsTitle_MCurDraw(flg);
    eglLinkAlpha(0);
    v35 = gGlobal;
    v36 = v35->mode_rgba;
    v37 = v36->m_Items[2];
    v38 = v37;
    rgba2 = v37;
    v41 = v36->m_Items[2];
    v42 = v35->hmoatex;
    if (LODWORD(v42->max_length) <= 2)
  }
  else
  {
    eglLinkAlpha(0);
    v20 = gGlobal;
    v21 = v20->mode_rgba;
    v22 = v21->m_Items[0];
    hmodtex = v20->hmodtex;
    eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, v22, v20->mode_rgba->m_Items[0], v20->mode_rgba->m_Items[0], v20->mode_rgba->m_Items[0], hmodtex->m_Items[0]);
    eglLinkAlpha(1);
    v24 = gGlobal;
    v25 = v24->mode_rgba;
    v26 = v25->m_Items[1];
    v46 = v25->m_Items[1];
    v47 = v24->hmodtex;
    eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, v26, v26, v26, v46, v47->m_Items[1]);
    TgsTitle_MCurDraw(flg);
    eglLinkAlpha(0);
    v50 = gGlobal;
    v51 = v50->mode_rgba;
    v37 = v51->m_Items[2];
    v38 = v37;
    rgba2 = v37;
    v41 = v51->m_Items[2];
    v42 = v50->hmodtex;
  }
  eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, v37, v38, rgba2, v41, v42->m_Items[2]);
}

// 0x18537c0
void TgsTitle_DrawTitle(s32 flg) {
  struct tgsGlobal_o *gGlobal;
  struct System_UInt32_array *bg_rgba;
  s32 rgba1;
  s32 rgba3;
  struct sdfTexHandle_t_array *htittex;
  s32 v11;
  struct tgsGlobal_o *v13;
  struct System_UInt32_array *v14;
  s32 rgba2;
  s32 v17;
  struct sdfTexHandle_t_array *v18;
  struct tgsGlobal_o *v20;
  struct System_UInt32_array *v21;
  s32 v22;
  s32 v24;
  struct sdfTexHandle_t_array *v25;
  struct tgsGlobal_o *v27;
  struct System_UInt32_array *v28;
  s32 v29;
  struct sdfTexHandle_t_array *v30;

  eglSetOt(71);
  eglLinkTest(1, 1, 128, 3, 0, 0, 1, 1);
  eglLinkAlpha(0);
  bg_rgba = gGlobal->bg_rgba;
  rgba1 = bg_rgba->m_Items[3];
  rgba3 = bg_rgba->m_Items[3];
  htittex = gGlobal->htittex;
  eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, rgba1, rgba1, rgba1, rgba3, htittex->m_Items[3]);
  TgsTitle_CurDraw(v11);
  eglLinkAlpha(1);
  v13 = gGlobal;
  v14 = v13->bg_rgba;
  rgba2 = v14->m_Items[2];
  v17 = v14->m_Items[2];
  v18 = v13->htittex;
  eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, rgba2, rgba2, rgba2, v17, v18->m_Items[2]);
  eglLinkAlpha(0);
  v20 = gGlobal;
  v21 = v20->bg_rgba;
  v22 = v21->m_Items[1];
  v24 = v21->m_Items[1];
  v25 = v20->htittex;
  eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, v22, v22, v22, v24, v25->m_Items[1]);
  eglLinkAlpha(1);
  v27 = gGlobal;
  v28 = v27->bg_rgba;
  v29 = v28->m_Items[0];
  v30 = v27->htittex;
  eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, v29, v27->bg_rgba->m_Items[0], v27->bg_rgba->m_Items[0], v27->bg_rgba->m_Items[0], v30->m_Items[0]);
}

// 0x18543a0
s8 TgsTitle_FadeTitle(s32 flg) {
  s16 v4;
  s32 v5;
  s16 v7;
  s32 v8;
  struct tgsGlobal_o *v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s64 v13;
  u64 v14;
  struct System_UInt32_array *v15;
  s32 v17;
  char v18;
  char v20;
  char v21;
  u8 v22;
  struct System_UInt32_array *v23;
  struct tgsGlobal_o *gGlobal;
  s32 v27;
  s32 v28;
  u32 v29;
  struct System_UInt32_array *mode_rgba;
  u8 v32;
  struct System_UInt32_array *v33;
  struct System_UInt32_array *v36;
  u8 v38;
  struct System_UInt32_array *v39;
  struct System_UInt32_array *v42;
  u8 v44;
  struct System_UInt32_array *v45;
  struct System_UInt32_array *v48;
  u8 v50;
  struct System_UInt32_array *v51;

  if (flg == 1)
  {
    if ((v7 & 0x200) != 0)
    {
      v8 = v7 & 0x200;
    }
    else
    {
      v8 = 0;
    }
    v27 = gGlobal->bg_maskrgba + 16;
    if (v27 >= 128)
      v28 = 128;
    else
      v28 = gGlobal->bg_maskrgba + 16;
    if (v27 >= 1)
      v29 = v28;
    else
      v29 = 0;
    gGlobal->bg_maskrgba = v29;
    mode_rgba = gGlobal->mode_rgba;
    if (HIBYTE(mode_rgba->m_Items[0]) + 16 >= 0x80)
      v32 = 0x80;
    else
      v32 = HIBYTE(mode_rgba->m_Items[0]) + 16;
    v33 = gGlobal->mode_rgba;
    v33->m_Items[0] = v33->m_Items[0] & 0xFFFFFF | (v32 << 24);
    v36 = gGlobal->mode_rgba;
    if (HIBYTE(v36->m_Items[1]) + 16 >= 0x80)
      v38 = 0x80;
    else
      v38 = HIBYTE(v36->m_Items[1]) + 16;
    v39 = gGlobal->mode_rgba;
    v39->m_Items[1] = v39->m_Items[1] & 0xFFFFFF | (v38 << 24);
    v42 = gGlobal->mode_rgba;
    if (HIBYTE(v42->m_Items[2]) + 16 >= 0x80)
      v44 = 0x80;
    else
      v44 = HIBYTE(v42->m_Items[2]) + 16;
    v45 = gGlobal->mode_rgba;
    v45->m_Items[2] = v45->m_Items[2] & 0xFFFFFF | (v44 << 24);
    v48 = gGlobal->mode_rgba;
    if (HIBYTE(v48->m_Items[3]) + 16 >= 0x64)
      v50 = 100;
    else
      v50 = HIBYTE(v48->m_Items[3]) + 16;
    v51 = gGlobal->mode_rgba;
    v51->m_Items[3] = v51->m_Items[3] & 0xFFFFFF | (v50 << 24);
    if (v27 < 128)
      return 0;
  }
  else
  {
    if (flg)
      return 0;
    if ((v4 & 0x200) != 0)
    {
      v5 = v4 & 0x200;
    }
    else
    {
      v5 = 0;
    }
    v9 = gGlobal;
    v10 = v9->bg_maskrgba - 16;
    if (v10 >= 128)
      v11 = 128;
    else
      v11 = v9->bg_maskrgba - 16;
    if (v10 >= 1)
      v12 = v11;
    else
      v12 = 0;
    v13 = 8;
    v9->bg_maskrgba = v12;
    v14 = 0;
    while (1)
    {
      v15 = gGlobal->mode_rgba;
      v17 = *(&v15->obj.klass + 4 * v13 + 3) - 16;
      if (v17 >= 100)
        v18 = 100;
      else
        v18 = *(&v15->obj.klass + 4 * v13 + 3) - 16;
      if (v17 < 1)
        v18 = 0;
      if (v17 >= 128)
        v20 = 0x80;
      else
        v20 = *(&v15->obj.klass + 4 * v13 + 3) - 16;
      if (v17 >= 1)
        v21 = v20;
      else
        v21 = 0;
      if (v13 == 11)
        v22 = v18;
      else
        v22 = v21;
      v23 = gGlobal->mode_rgba;
      *(&v23->obj.klass + v13) = *(&v23->obj.klass + v13) & 0xFFFFFF | (v22 << 24);
      if (v13 == 11)
        break;
      v14 = ++v13 - 8;
    }
    if (v12 > 0)
      return 0;
  }
  return 1;
}

// 0x1853fe0
void TgsTitle_GetAlpha(void) {
  struct System_UInt32_array *bg_cnt;
  struct tgsGlobal_o *gGlobal;
  struct System_UInt32_array *bg_alpha;
  struct System_UInt32_array *v7;
  u32 v9;
  f32 v10;
  f32 v11;
  s32 v12;
  struct tgsGlobal_o *v15;
  struct System_UInt32_array *v16;
  struct System_UInt32_array *bg_rgba;
  s32 v19;
  struct System_UInt32_array *v21;
  struct tgsGlobal_o *v23;
  struct System_UInt32_array *v24;
  struct System_UInt32_array *v25;
  f32 v27;
  f32 v28;
  s32 v29;
  struct tgsGlobal_o *v31;
  struct System_UInt32_array *v32;
  struct System_UInt32_array *v34;

  bg_cnt = gGlobal->bg_cnt;
  bg_cnt->m_Items[0] = (bg_cnt->m_Items[0] + 6) % 0x168;
  v7 = gGlobal->bg_cnt;
  bg_alpha = gGlobal->bg_alpha;
  v9 = v7->m_Items[0];
  v10 = ((v9 + 90) % 0x168);
  v11 = (((sdfSin((v10 / 180.0) * 3.1416, 0) + 1.0) * 0.5) * 88.0) + 40.0;
  if (v11 >= 0.0)
    v12 = v11;
  else
    v12 = v11;
  bg_alpha->m_Items[0] = v12;
  v15 = gGlobal;
  v16 = v15->bg_alpha;
  bg_rgba = v15->bg_rgba;
  v19 = (v16->m_Items[0] << 24) | 0x808080;
  bg_rgba->m_Items[2] = v19;
  v21 = gGlobal->bg_cnt;
  v21->m_Items[1] = (v21->m_Items[1] + 6) % 0x168;
  v23 = gGlobal;
  v25 = v23->bg_cnt;
  v24 = v23->bg_alpha;
  v27 = ((v25->m_Items[1] + 90) % 0x168);
  v28 = (((sdfSin((v27 / 180.0) * 3.1416, 0) + 1.0) * 0.5) * 108.0) + 20.0;
  if (v28 >= 0.0)
    v29 = v28;
  else
    v29 = v28;
  v24->m_Items[1] = v29;
  v31 = gGlobal;
  v32 = v31->bg_alpha;
  v34 = v31->bg_rgba;
  v34->m_Items[0] = (v32->m_Items[1] << 24) | 0x808080;
}

// 0x18555d0
void TgsTitle_MCurDraw(s32 flg) {
  struct tgsGlobal_o *gGlobal;
  struct System_UInt32_array *mode_rgba;
  s32 v9;
  s16 v12;
  s32 v13;
  struct tgsGlobal_o *v14;
  struct System_UInt32_array *v15;
  s32 v16;
  s32 rgba1;
  struct System_UInt32_array *v18;
  s32 rgba2;
  s32 rgba3;
  struct sdfTexHandle_t_array *hmoatex;
  sdfTexHandle_t_o *th;

  eglSetOt(71);
  eglLinkTest(1, 1, 128, 3, 0, 0, 1, 1);
  if (!flg)
  {
    mode_rgba = gGlobal->mode_rgba;
    mode_rgba->m_Items[3] = (gGlobal->modecur_alpha << 24) | 0x808080;
  }
  if (gGlobal->YnPos)
    v9 = 345;
  else
    v9 = 309;
  eglLinkAlpha(1);
  if ((v12 & 0x200) != 0)
  {
    v13 = v12 & 0x200;
    v14 = gGlobal;
    if (v14->ModePos)
    {
      else
      {
        v15 = v14->mode_rgba;
        if (LODWORD(v15->max_length) >= 4)
        {
          v16 = v15->m_Items[3];
          rgba1 = v16;
          rgba2 = v16;
          rgba3 = v15->m_Items[3];
          hmoatex = v14->hmoatex;
          if (LODWORD(hmoatex->max_length) <= 3)
        }
      }
    }
  }
  else
  {
    v13 = 0;
    v14 = gGlobal;
    if (v14->ModePos)
  }
  v18 = v14->mode_rgba;
  if (LODWORD(v18->max_length) < 4)
  v16 = v18->m_Items[3];
  rgba1 = v16;
  rgba2 = v16;
  rgba3 = v18->m_Items[3];
  hmoatex = v14->hmodtex;
  th = hmoatex->m_Items[3];
  eglLinkSprite(80, v9, 256, 128, 0, 0, 256, 128, v16, rgba1, rgba2, rgba3, th);
}

// 0x1851750
void TgsTitle_MemoryInit(void) {
  struct sdfTexHandle_t_array *htittex;
  struct sdfMemHandle_t_array *htitMem;
  struct System_UInt32_array *bg_rgba;
  struct sdfTexHandle_t_array *v9;
  struct sdfMemHandle_t_array *v11;
  struct System_UInt32_array *v13;
  struct sdfTexHandle_t_array *v15;
  struct sdfMemHandle_t_array *v17;
  struct System_UInt32_array *v19;
  struct sdfTexHandle_t_array *v21;
  struct sdfMemHandle_t_array *v23;
  struct System_UInt32_array *v25;
  struct sdfTexHandle_t_array *v27;
  struct sdfMemHandle_t_array *v29;
  struct System_UInt32_array *v31;
  struct sdfMemHandle_t_array *hmodMem;
  struct sdfTexHandle_t_array *hmodtex;
  struct sdfMemHandle_t_array *v37;
  struct sdfTexHandle_t_array *v39;
  struct sdfMemHandle_t_array *v41;
  struct sdfTexHandle_t_array *v43;
  struct sdfMemHandle_t_array *v45;
  struct sdfTexHandle_t_array *v47;
  struct sdfMemHandle_t_array *hmoaMem;
  struct sdfTexHandle_t_array *hmoatex;
  struct sdfMemHandle_t_array *v53;
  struct sdfTexHandle_t_array *v55;
  struct sdfMemHandle_t_array *v57;
  struct sdfTexHandle_t_array *v59;
  struct sdfMemHandle_t_array *v61;
  struct sdfTexHandle_t_array *v63;

  gGlobal->bg_maskrgba = 0;
  htittex = gGlobal->htittex;
  htittex->m_Items[0] = 0;
  htitMem = gGlobal->htitMem;
  htitMem->m_Items[0] = 0;
  bg_rgba = gGlobal->bg_rgba;
  bg_rgba->m_Items[0] = -2139062144;
  v9 = gGlobal->htittex;
  v9->m_Items[1] = 0;
  v11 = gGlobal->htitMem;
  v11->m_Items[1] = 0;
  v13 = gGlobal->bg_rgba;
  v13->m_Items[1] = -2139062144;
  v15 = gGlobal->htittex;
  v15->m_Items[2] = 0;
  v17 = gGlobal->htitMem;
  v17->m_Items[2] = 0;
  v19 = gGlobal->bg_rgba;
  v19->m_Items[2] = -2139062144;
  v21 = gGlobal->htittex;
  v21->m_Items[3] = 0;
  v23 = gGlobal->htitMem;
  v23->m_Items[3] = 0;
  v25 = gGlobal->bg_rgba;
  v25->m_Items[3] = -2139062144;
  v27 = gGlobal->htittex;
  v27->m_Items[4] = 0;
  v29 = gGlobal->htitMem;
  v29->m_Items[4] = 0;
  v31 = gGlobal->bg_rgba;
  v31->m_Items[4] = -2139062144;
  hmodMem = gGlobal->hmodMem;
  hmodMem->m_Items[0] = 0;
  hmodtex = gGlobal->hmodtex;
  hmodtex->m_Items[0] = 0;
  v37 = gGlobal->hmodMem;
  v37->m_Items[1] = 0;
  v39 = gGlobal->hmodtex;
  v39->m_Items[1] = 0;
  v41 = gGlobal->hmodMem;
  v41->m_Items[2] = 0;
  v43 = gGlobal->hmodtex;
  v43->m_Items[2] = 0;
  v45 = gGlobal->hmodMem;
  v45->m_Items[3] = 0;
  v47 = gGlobal->hmodtex;
  v47->m_Items[3] = 0;
  hmoaMem = gGlobal->hmoaMem;
  hmoaMem->m_Items[0] = 0;
  hmoatex = gGlobal->hmoatex;
  hmoatex->m_Items[0] = 0;
  v53 = gGlobal->hmoaMem;
  v53->m_Items[1] = 0;
  v55 = gGlobal->hmoatex;
  v55->m_Items[1] = 0;
  v57 = gGlobal->hmoaMem;
  v57->m_Items[2] = 0;
  v59 = gGlobal->hmoatex;
  v59->m_Items[2] = 0;
  v61 = gGlobal->hmoaMem;
  v61->m_Items[3] = 0;
  v63 = gGlobal->hmoatex;
  v63->m_Items[3] = 0;
}

// 0x1854ad0
void TgsTitle_ModeRGBASet(void) {
  struct System_UInt32_array *mode_rgba;
  struct System_UInt32_array *v5;
  struct System_UInt32_array *v7;
  struct System_UInt32_array *v9;

  mode_rgba = gGlobal->mode_rgba;
  mode_rgba->m_Items[0] = 8421504;
  v5 = gGlobal->mode_rgba;
  v5->m_Items[1] = 8421504;
  v7 = gGlobal->mode_rgba;
  v7->m_Items[2] = 8421504;
  v9 = gGlobal->mode_rgba;
  v9->m_Items[3] = 8421504;
}

// 0x18533e0
void TgsTitle_SpriteDelete(s32 sw) {

}

// 0x1853030
void TgsTitle_SpriteDelete_Vram(s32 sw) {
  s64 v3;
  u64 v5;
  struct sdfTexHandle_t_array *hmoatex;
  struct sdfTexHandle_t_array *v9;
  sdfTexHandle_t_o *v11;
  struct sdfTexHandle_t_array *v13;
  u64 v16;
  struct sdfTexHandle_t_array *htittex;
  struct sdfTexHandle_t_array *v20;
  sdfTexHandle_t_o *v22;
  struct sdfTexHandle_t_array *v24;
  u64 v27;
  struct sdfTexHandle_t_array *hmodtex;
  struct sdfTexHandle_t_array *v31;
  sdfTexHandle_t_o *v33;
  struct sdfTexHandle_t_array *v35;

  v3 = 4;
  if (sw)
  {
    if (sw == 2)
    {
      do
      {
        v5 = v3 - 4;
        hmoatex = gGlobal->hmoatex;
        if (*(&hmoatex->obj.klass + v3))
        {
          v9 = gGlobal->hmoatex;
          v11 = *(&v9->obj.klass + v3);
          sdfTexFree(v11);
        }
        v13 = gGlobal->hmoatex;
        *(&v13->obj.klass + v3++) = 0;
      }
      while (v3 != 8);
    }
    else
    {
      do
      {
        v27 = v3 - 4;
        hmodtex = gGlobal->hmodtex;
        if (*(&hmodtex->obj.klass + v3))
        {
          v31 = gGlobal->hmodtex;
          v33 = *(&v31->obj.klass + v3);
          sdfTexFree(v33);
        }
        v35 = gGlobal->hmodtex;
        *(&v35->obj.klass + v3++) = 0;
      }
      while (v3 != 8);
    }
  }
  else
  {
    do
    {
      v16 = v3 - 4;
      htittex = gGlobal->htittex;
      if (*(&htittex->obj.klass + v3))
      {
        v20 = gGlobal->htittex;
        v22 = *(&v20->obj.klass + v3);
        sdfTexFree(v22);
      }
      v24 = gGlobal->htittex;
      *(&v24->obj.klass + v3++) = 0;
    }
    while (v3 != 9);
  }
}

// 0x1851f40
void TgsTitle_SpriteLoad(s32 flg) {
  tgsMain_c *v3;
  struct tgsMain_StaticFields *static_fields;
  struct sdfMemHandle_t_array *hmodMem;
  tgsMain_c *v6;
  tgsMain_c *v7;
  struct tgsMain_StaticFields *v8;
  struct sdfMemHandle_t_array *htitMem;
  tgsMain_c *v10;
  tgsMain_c *v11;
  struct tgsMain_StaticFields *v12;
  struct sdfMemHandle_t_array *hmoaMem;
  tgsMain_c *v14;
  struct tgsMain_StaticFields *v18;
  struct sdfMemHandle_t_array *v19;
  tgsMain_c *v20;
  struct tgsMain_StaticFields *v24;
  struct sdfMemHandle_t_array *v25;
  tgsMain_c *v26;
  struct tgsMain_StaticFields *v30;
  struct sdfMemHandle_t_array *v31;
  tgsMain_c *v32;
  struct tgsMain_StaticFields *v36;
  struct sdfMemHandle_t_array *v37;
  tgsMain_c *v38;
  struct tgsMain_StaticFields *v42;
  struct sdfMemHandle_t_array *v43;
  struct tgsMain_StaticFields *v48;
  struct sdfMemHandle_t_array *v49;
  tgsMain_c *v50;
  struct tgsMain_StaticFields *v54;
  struct sdfMemHandle_t_array *v55;
  tgsMain_c *v56;
  struct tgsMain_StaticFields *v60;
  struct sdfMemHandle_t_array *v61;
  tgsMain_c *v62;
  struct tgsMain_StaticFields *v66;
  struct tgsMain_StaticFields *v72;
  struct sdfMemHandle_t_array *v73;

  if (flg)
  {
    if (flg == 1)
    {
      static_fields = v3->static_fields;
      hmodMem = static_fields->gGlobal->hmodMem;
      hmodMem->m_Items[0] = 0;
      v18 = v6->static_fields;
      v19 = v18->gGlobal->hmodMem;
      v19->m_Items[1] = 0;
      v36 = v20->static_fields;
      v37 = v36->gGlobal->hmodMem;
      v37->m_Items[2] = 0;
      v42 = v38->static_fields;
      v43 = v42->gGlobal->hmodMem;
      if ((v42->hmodMem_v->max_length & 0xFFFFFFFC) == 0)
    }
    else
    {
      v12 = v11->static_fields;
      hmoaMem = v12->gGlobal->hmoaMem;
      hmoaMem->m_Items[0] = 0;
      v30 = v14->static_fields;
      v31 = v30->gGlobal->hmoaMem;
      v31->m_Items[1] = 0;
      v60 = v32->static_fields;
      v61 = v60->gGlobal->hmoaMem;
      v61->m_Items[2] = 0;
      v66 = v62->static_fields;
      v43 = v66->gGlobal->hmoaMem;
    }
    v43->m_Items[3] = 0;
  }
  else
  {
    v8 = v7->static_fields;
    htitMem = v8->gGlobal->htitMem;
    htitMem->m_Items[0] = 0;
    v24 = v10->static_fields;
    v25 = v24->gGlobal->htitMem;
    v25->m_Items[1] = 0;
    v48 = v26->static_fields;
    v49 = v48->gGlobal->htitMem;
    v49->m_Items[2] = 0;
    v54 = v50->static_fields;
    v55 = v54->gGlobal->htitMem;
    v55->m_Items[3] = 0;
    v72 = v56->static_fields;
    v73 = v72->gGlobal->htitMem;
    v73->m_Items[4] = 0;
  }
}

// 0x18528c0
void TgsTitle_SpriteSetVram(s32 sw) {
  s64 i;
  tgsMain_c *v5;
  u64 v6;
  struct tgsMain_StaticFields *v7;
  struct System_Object_array *htitMem_v;
  u32 *htittex;
  Il2CppObject *v11;
  s64 *v12;
  s64 *v13;
  tgsMain_c *v15;
  struct tgsMain_StaticFields *static_fields;
  struct System_Object_array *hmodMem_v;
  struct sdfTexHandle_t_array *hmodtex;
  Il2CppObject *v20;
  s64 *v21;
  s64 *v23;
  tgsMain_c *v24;
  tgsMain_c *v25;
  struct tgsMain_StaticFields *v26;
  struct System_Object_array *hmoaMem_v;
  struct sdfTexHandle_t_array *hmoatex;
  Il2CppObject *v30;
  s64 *v31;
  s64 *v33;
  tgsMain_c *v34;
  struct tgsMain_StaticFields *v37;
  struct System_Object_array *v38;
  struct sdfTexHandle_t_array *v39;
  Il2CppObject *v40;
  s64 *v42;
  s64 *v44;
  tgsMain_c *v45;
  struct tgsMain_StaticFields *v48;
  struct System_Object_array *v49;
  struct sdfTexHandle_t_array *v50;
  Il2CppObject *v51;
  s64 *v53;
  s64 *v55;
  tgsMain_c *v56;
  struct tgsMain_StaticFields *v59;
  struct System_Object_array *v60;
  struct sdfTexHandle_t_array *v61;
  Il2CppObject *v63;
  s64 *v64;
  s64 *v66;
  tgsMain_c *v69;
  struct tgsMain_StaticFields *v70;
  struct sdfTexHandle_t_array *v71;
  struct System_Object_array *v72;
  struct tgsMain_StaticFields *v75;
  struct System_Object_array *v76;
  struct sdfTexHandle_t_array *v77;
  Il2CppObject *v79;
  s64 *v80;
  s64 *v81;
  tgsMain_c *v84;
  struct tgsMain_StaticFields *v85;
  Il2CppObject *v87;
  s64 *v88;
  s64 *v89;

  if (sw == 1)
  {
    static_fields = v15->static_fields;
    hmodMem_v = static_fields->hmodMem_v;
    hmodtex = static_fields->gGlobal->hmodtex;
    v20 = hmodMem_v->m_Items[0];
    v21 = sdfTexSet(v20);
    v23 = v21;
    hmodtex->m_Items[0] = v23;
    v37 = v24->static_fields;
    v38 = v37->hmodMem_v;
    v39 = v37->gGlobal->hmodtex;
    v40 = v38->m_Items[1];
    v42 = sdfTexSet(v40);
    v44 = v42;
    v39->m_Items[1] = v44;
    v59 = v45->static_fields;
    v60 = v59->hmodMem_v;
    v61 = v59->gGlobal->hmodtex;
    v63 = v60->m_Items[2];
    v64 = sdfTexSet(v63);
    v66 = v64;
    v61->m_Items[2] = v66;
    v70 = v69->static_fields;
    v71 = v70->gGlobal->hmodtex;
    v72 = v70->hmodMem_v;
    if ((v72->max_length & 0xFFFFFFFC) == 0)
  }
  else
  {
    if (!sw)
    {
      for (i = 4; i != 9; ++i)
      {
        v6 = i - 4;
        v7 = v5->static_fields;
        htitMem_v = v7->htitMem_v;
        htittex = v7->gGlobal->htittex;
        v11 = *(&htitMem_v->obj.klass + i);
        v12 = sdfTexSet(v11);
        v13 = v12;
        *&htittex[2 * i] = v13;
      }
      return;
    }
    v26 = v25->static_fields;
    hmoaMem_v = v26->hmoaMem_v;
    hmoatex = v26->gGlobal->hmoatex;
    v30 = hmoaMem_v->m_Items[0];
    v31 = sdfTexSet(v30);
    v33 = v31;
    hmoatex->m_Items[0] = v33;
    v48 = v34->static_fields;
    v49 = v48->hmoaMem_v;
    v50 = v48->gGlobal->hmoatex;
    v51 = v49->m_Items[1];
    v53 = sdfTexSet(v51);
    v55 = v53;
    v50->m_Items[1] = v55;
    v75 = v56->static_fields;
    v76 = v75->hmoaMem_v;
    v77 = v75->gGlobal->hmoatex;
    v79 = v76->m_Items[2];
    v80 = sdfTexSet(v79);
    v81 = v80;
    v77->m_Items[2] = v81;
    v85 = v84->static_fields;
    v71 = v85->gGlobal->hmoatex;
    v72 = v85->hmoaMem_v;
  }
  v87 = v72->m_Items[3];
  v88 = sdfTexSet(v87);
  v89 = v88;
  v71->m_Items[3] = v89;
}

// 0x18513e0
_FRQ *frwGetSmallNumFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 pStr, _FRQ *pFRQ) {
  return 0;
}

// 0x1851360
s32 p2sdPlaySE(s32 a) {
  return 0;
}

// 0x18513c0
pacFileHandle_t *pacLoad(char *filename) {
  return 0;
}

// 0x1851370
s32 sceClose(s32 a) {
  return 0;
}

// 0x1851390
s32 sceOpen(s8 a, s32 b, s32 d) {
  return 0;
}

// 0x1851380
s32 sceSync(char *a, s32 b) {
  return 0;
}

// 0x18513a0
s32 sceWrite(s32 a, void *b, void *c) {
  return 0;
}

// 0x18513d0
sdfMemHandle_t *sdfDevLoadFile(char *aFilename, void *aTopPtr, void *a) {
  return 0;
}

// 0x18513b0
void sdfMemFreeDelayed(sdfMemHandle_t *aHandle) {
  ;
}

// 0x1855c60
void tgsCheckPadInput(void) {
    DDS3_PADCHECK_REP(0);
}

// 0x1855e50
void tgsCheckPadInput2(void) {
    DDS3_PADCHECK_REP(0);
}

// 0x18565f0
void tgsDestroy(dds3ProcessID_t *id) {
  tgsDestroySprite();
  gGlobal = 0;
}

// 0x1856280
void tgsDestroySprite(void) {
  sdfTexHandle_t_o *KotowariSpriteHandle;
  s32 v6;

  KotowariSpriteHandle = gGlobal->KotowariSpriteHandle;
  if (KotowariSpriteHandle)
  {
    sdfTexFreeDelayed(KotowariSpriteHandle);
    gGlobal->KotowariSpriteHandle = 0;
  }
  TgsTitle_SpriteDelete_Vram(0);
  TgsTitle_SpriteDelete_Vram(1);
  TgsTitle_SpriteDelete_Vram(2);
  TgsTitle_SpriteDelete(v6);
}

// 0x1856030
void tgsDrawKotowari(void) {
  s32 v3;
  s32 rgba1;
  s32 rgba2;
  s32 rgba3;

  eglSetOt(71);
  eglLinkTest(1, 0, 128, 3, 0, 0, 1, 1);
  eglLinkAlpha(0);
  v3 = ToInt32_2965280(0x80404040);
  rgba1 = ToInt32_2965280(0x80404040);
  rgba2 = ToInt32_2965280(0x80404040);
  rgba3 = ToInt32_2965280(0x80404040);
  eglLinkSprite(0, 0, 512, 448, 0, 0, 512, 448, v3, rgba1, rgba2, rgba3, gGlobal->KotowariSpriteHandle);
}

// 0x18571a0
s32 tgsGemeMode(void) {
  return gGemeMode;
}

// 0x1856380
void tgsInit(s32 mode) {
    sdfMemLock(0);
    tgsInitSprite();
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
}

// 0x18561c0
void tgsInitSprite(void) {
  struct tgsGlobal_o *gGlobal;
  sdfTexHandle_t_o *Texture;

  Texture = fclLoadTexture(StringLiteral_22458);
  gGlobal->KotowariSpriteHandle = Texture;
  TgsTitle_MemoryInit(Texture);
  TgsTitle_SpriteLoad(0);
  TgsTitle_SpriteLoad(1);
  TgsTitle_SpriteLoad(2);
  TgsTitle_SpriteSetVram(0);
}

// 0x1851610
void tgsLoad(s32 mode) {
}

// 0x1855a40
void tgsNext1(void) {
    dds3GlobalWorkUserInit2(0);
    tgsLoad(0);
    evtBitOn(0);
    fldProcNext(0, 0);
    fldSetSceneParam2(0, 0, 0, 0);
    dds3AdminiCallSequence(0, 0, 0, 0);
}

// 0x18513f0
void tgsSave(s32 mode) {
    sdfFileGetHostRoot();
}

// 0x18570a0
s32 tgsShutDown(void) {
  tgsDestroySprite();
  gGlobal = 0;
  dds3KillProcessName(StringLiteral_22459, 1);
  return 0;
}

// 0x1857030
s32 tgsStart(s32 mode) {
  s32 v2;

  tgsInit(v2);
  return -1;
}

// 0x1856660
dds3ProcessFunc_t *tgs_Main(dds3ProcessID_t *id) {
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    p2sdLoadCheckMidi(0);
    p2sdLoadSMGFile(0);
    TgsTitle_GetAlpha();
    TgsTitle_DrawTitle(0);
    dds3FadeIn(0, 0, 0, 0);
    p2sdFadeIn(0);
    tgsCheckPadInput();
    DDS3_PADCHECK_TRIG(0);
    TgsTitle_SpriteSetVram(0);
    TgsTitle_ModeRGBASet();
    DDS3_PAD2CHECK_TRIG(0);
    tgsSave(0);
    tgsCheckPadInput2();
    TgsTitle_DrawMask();
    TgsTitle_DrawMode(0);
    p2sdFadeOut(0);
    dds3FadeOut(0, 0, 0, 0);
    tgsDrawKotowari();
    dds3FadeCheck();
    dds3CreateGameData(0);
    tgsNext1();
    return 0;
}
