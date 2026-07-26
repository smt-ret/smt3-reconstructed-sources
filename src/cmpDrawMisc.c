#include "types.h"

typedef struct cmpDrawMisc_Line_t cmpDrawMisc_Line_t;
typedef struct cmpDrawMisc_TriangleStrip_t cmpDrawMisc_TriangleStrip_t;
typedef struct cmpDrawMisc_Triangle_t cmpDrawMisc_Triangle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct sdf3DInitPacket_t sdf3DInitPacket_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdf3DViewportPacket_t sdf3DViewportPacket_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrTagRGBA_t sdfGrTagRGBA_t;
typedef struct sdfGrTagXYZ2_t sdfGrTagXYZ2_t;

struct cmpDrawMisc_Triangle_t {
    sdfGrTagRGBA_t *rgba0;
    sdfGrTagXYZ2_t *xyz0;
    sdfGrTagRGBA_t *rgba1;
    sdfGrTagXYZ2_t *xyz1;
    sdfGrTagRGBA_t *rgba2;
    sdfGrTagXYZ2_t *xyz2;
};

struct cmpDrawMisc_TriangleStrip_t {
    sdfGrTagRGBA_t *rgba0;
    sdfGrTagXYZ2_t *xyz0;
    sdfGrTagRGBA_t *rgba1;
    sdfGrTagXYZ2_t *xyz1;
    sdfGrTagRGBA_t *rgba2;
    sdfGrTagXYZ2_t *xyz2;
    sdfGrTagRGBA_t *rgba3;
    sdfGrTagXYZ2_t *xyz3;
};

struct cmpDrawMisc_Line_t {
    sdfGrTagRGBA_t *rgba0;
    sdfGrTagXYZ2_t *xyz0;
    sdfGrTagRGBA_t *rgba1;
    sdfGrTagXYZ2_t *xyz1;
};

static s32 CMP_OFS_X;
static s32 CMP_OFS_Y;
static sdfDrawTag_t *cmpPersDrawTag[2];
static sdf3DInitPacket_t *cmpTdPacket[2];
static sdfDrawTag_t *cmpDirLightDrawTag[2];
static sdf3DLightParallelPacket_t *cmpDirLightPacket[2];
static sdf3DViewportPacket_t *cmpViewportPacket[2];
static dds3ProcessFunc_t *cmpFadeCallbackTerm;
