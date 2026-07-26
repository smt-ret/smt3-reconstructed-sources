#include "types.h"

static char *gCombineInfoStrTbl[3];
static char *gStatusPanelText1[4];
static char *gStatusPanelText2[1];
static char *gStatusPanelText3[1];
static char *gStatusPanelText4[1];
static void *ListObjs;
static void *TextObjs;
static void *CCtrObjs;
static void *AnimObjs;
static char *cmbIconName[7];
static s32 RibbonOld;

void *GetGameObject(char *name);

// 0x1463200
void FinalizeGameObject(void) {
  PropertySheet___Clear(AnimObjs);
  PropertySheet___Clear(CCtrObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(ListObjs);
}

// 0x145f250
void InitializeGameObject(void) {
    GetGameObject(0);
}

// 0x1469760
void UpdateDevilList(s32 mode) {
  switch (mode)
  {
    case 8:
      cmbCalcDevSelSac();
      cmbDrawInfoWindow(2);
      cmbDrawSelDevilInfo(2, CMB_GBWK->HelpFlag);
      cmbDrawSacDevilSelect();
      break;
    case 6:
      cmbCalcDevSel2nd();
      cmbDrawInfoWindow(1);
      cmbDrawSelDevilInfo(1, CMB_GBWK->HelpFlag);
      cmbDraw2ndDevilSelect();
      break;
    case 5:
      cmbCalcDevSel1st();
      cmbDrawInfoWindow(0);
      cmbDrawSelDevilInfo(0, CMB_GBWK->HelpFlag);
      cmbDraw1stDevilSelect();
      break;
  }
}
