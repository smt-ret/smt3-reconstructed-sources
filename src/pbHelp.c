#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbHelp_t pbHelp_t;
typedef struct pbProcHandle_t pbProcHandle_t;

struct pbHelp_t {
    u32 page;
};

static s32 NmlCnt;
static char *pbHelpLcl[12];

bool DDS3_PADCHECK_TRIG(s32 id);
s32 FindId(s32 type, char *name);
char *GetLocalizeText(char *ID);
void *GetoPB_UI(void);
char *RepColTag(char *txt, void **LegacyParamArray);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
s32 p2sdPlaySE(s32 a);
pbProcHandle_t *pbStartHelp(pbProcHandle_t *parent, u32 page);

// 0x14a1360
dds3ProcessFunc_t *deleteHelp(dds3ProcessID_t *id) {
    return 0;
}

// 0x149fd40
dds3ProcessFunc_t *help(dds3ProcessID_t *id) {
    GetoPB_UI();
    GetLocalizeText(0);
    RepColTag(0, 0);
    DDS3_PADCHECK_TRIG(0);
    FindId(0, 0);
    p2sdPlaySE(0);
    return 0;
}

// 0x14a1530
pbProcHandle_t *pbStartHelp(pbProcHandle_t *parent, u32 page) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x14a17f0
pbProcHandle_t *pbStartHelp2(pbProcHandle_t **parent) {
    pbStartHelp(0, 0);
    return 0;
}

// 0x149fd30
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
