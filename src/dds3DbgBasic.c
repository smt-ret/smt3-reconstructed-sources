#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

bool DDS3_PAD2CHECK_TRIG(s32 id);
s32 DispBaseData(dds3Basic_t *basic, s32 x, s32 y, sdfDrawTag_t *tag);
s32 DispObjectBaseData(dds3Basic_t *basic, s32 x, s32 y, sdfDrawTag_t *tag);
void dds3ConsPanelTagLink(sdfDrawTag_t *tag, s32 x, s32 y, s32 sx, s32 sy);
dds3Basic_t *dds3GetActiveScene(void);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3SceneBasicExistBasic(dds3Basic_t **scene, dds3Basic_t **target);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);

// 0x152ed30
s32 DispBaseData(dds3Basic_t *basic, s32 x, s32 y, sdfDrawTag_t *tag) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x152f680
s32 DispObjectBaseData(dds3Basic_t *basic, s32 x, s32 y, sdfDrawTag_t *tag) {
    dds3GetBaseControlWorkData(0);
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    return 0;
}

// 0x152f810
dds3ProcessFunc_t *dds3DebugBasic(dds3ProcessID_t *id) {
    dds3GetActiveScene();
    dds3GetProcessData(0);
    dds3SceneBasicExistBasic(0, 0);
    sdfDrawTagInit(0);
    DispBaseData(0, 0, 0, 0);
    DispObjectBaseData(0, 0, 0, 0);
    dds3ConsPanelTagLink(0, 0, 0, 0, 0);
    DDS3_PAD2CHECK_TRIG(0);
    return 0;
}
