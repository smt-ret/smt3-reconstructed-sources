#pragma once
#include "types.h"

typedef enum {
    FR_COL_DEF = 0,
    FR_COL_RED = 1,
    FR_COL_BLUE = 2,
    FR_COL_YELLOW = 3,
    FR_COL_GREEN = 4,
    FR_COL_GLAY = 5,
    FR_COL_MAX = 6,
} FR_COL;

typedef enum {
    TMC00 = 0,
    TMC01 = 1,
    TMC02 = 2,
    TMC03 = 3,
    TMC04 = 4,
    TMC05 = 5,
    TMC06 = 6,
    TMC07 = 7,
    TMC08 = 8,
    TMC09 = 9,
    TMC10 = 10,
    TMC11 = 11,
    TMC12 = 12,
    TMC13 = 13,
    TMC14 = 14,
    TMC15 = 15,
    TMC16 = 16,
    TMC17 = 17,
    TMC18 = 18,
    TMC19 = 19,
    TMC20 = 20,
    TMC21 = 21,
    TMC22 = 22,
    TMC23 = 23,
    TMC24 = 24,
    TMC25 = 25,
} UI_COL;

typedef enum {
    FR_STYLE_MIN = 0,
    FR_STYLE_HELP = 1,
    FR_STYLE_SNUM = 2,
    FR_STYLE_LNUM = 3,
    FR_STYEL_MAX = 4,
} FR_STYLE;

typedef enum {
    FRW_HELP_SKILL = 0,
    FRW_HELP_ITEM = 1,
    FRW_HELP_HEARTS = 2,
} FRW_HELP;

typedef enum {
    FRW_RETTAG_OFF = 0,
    FRW_RETTAG_ON = 1,
    FRW_AFDELTAG_OFF = 2,
    FRW_AFDELTAG_ON = 3,
} FRW_RETTAG;

typedef enum {
    ITF_MESBINTYPE_MES = 0,
    ITF_MESBINTYPE_SEL = 1,
} ITF_MESBINTYPE;

typedef enum {
    ITF_MESBIN_SELPATTERN_TOP = 0,
    ITF_MESBIN_SELPATTERN_UNDER = 1,
} ITF_MESBIN;

typedef enum {
    ITF_MESMNG_STAT_NULL = 0,
    ITF_MESMNG_STAT_MES = 7,
    ITF_MESMNG_STAT_MES_NONE = 0,
    ITF_MESMNG_STAT_MES_READY = 1,
    ITF_MESMNG_STAT_MES_WAITWIN = 2,
    ITF_MESMNG_STAT_MES_BUSY = 3,
    ITF_MESMNG_STAT_MES_END = 4,
    ITF_MESMNG_STAT_SEL = 56,
    ITF_MESMNG_STAT_SEL_NONE = 0,
    ITF_MESMNG_STAT_SEL_READY = 8,
    ITF_MESMNG_STAT_SEL_WAITWIN = 16,
    ITF_MESMNG_STAT_SEL_BUSY = 24,
    ITF_MESMNG_STAT_SEL_SELECT = 32,
    ITF_MESMNG_STAT_SEL_END = 40,
    ITF_MESMNG_STAT_MESWIN = 768,
    ITF_MESMNG_STAT_MESWIN_CLOSED = 0,
    ITF_MESMNG_STAT_MESWIN_OPENING = 256,
    ITF_MESMNG_STAT_MESWIN_OPENED = 512,
    ITF_MESMNG_STAT_MESWIN_CLOSING = 768,
    ITF_MESMNG_STAT_SELWIN = 3072,
    ITF_MESMNG_STAT_SELWIN_CLOSED = 0,
    ITF_MESMNG_STAT_SELWIN_OPENING = 1024,
    ITF_MESMNG_STAT_SELWIN_OPENED = 2048,
    ITF_MESMNG_STAT_SELWIN_CLOSING = 3072,
    ITF_MESMNG_STAT_SPKWIN = 12288,
    ITF_MESMNG_STAT_SPKWIN_CLOSED = 0,
    ITF_MESMNG_STAT_SPKWIN_OPENING = 4096,
    ITF_MESMNG_STAT_SPKWIN_OPENED = 8192,
    ITF_MESMNG_STAT_SPKWIN_CLOSING = 12288,
    ITF_MESMNG_STAT_READONLY = 65535,
    ITF_MESMNG_STAT_NODISP_SPK = 65536,
    ITF_MESMNG_STAT_NODISP_MES = 131072,
    ITF_MESMNG_STAT_NODISP_SEL = 262144,
    ITF_MESMNG_STAT_NODISP_WIN = 524288,
    ITF_MESMNG_STAT_NODISP_LEAF = 1048576,
    ITF_MESMNG_STAT_REQ_WIN = 2097152,
    ITF_MESMNG_STAT_IGNORE_SPDUP = 4194304,
    ITF_MESMNG_STAT_IGNORE_NEXTPAGE = 8388608,
} ITF_MESMNG_STAT;

typedef enum {
    ITF_MESMNG_VAR_INT = 0,
    ITF_MESMNG_VAR_DEVIL = 1,
    ITF_MESMNG_VAR_HUMAN = 2,
    ITF_MESMNG_VAR_ITEM = 3,
    ITF_MESMNG_VAR_FLOOR = 4,
    ITF_MESMNG_VAR_SKILL = 5,
    ITF_MESMNG_VAR_NTERM = 6,
    ITF_MESMNG_VAR_STERM = 7,
    ITF_MESMNG_VAR_RACE = 8,
    ITF_MESMNG_VAR_DH = 9,
    ITF_MESMNG_VAR_CODENAME = 10,
} ITF_MESMNG_VAR;

typedef enum {
    ITF_MESMNG_CONFIG_HIGHSPEED = 1,
    ITF_MESMNG_DISPWIN = 2,
} ITF_MESMNG;

typedef enum {
    ITF_PANEL_TYPE_NORMAL = 0,
    ITF_PANEL_TYPE_MESWIN = 1,
    ITF_PANEL_TYPE_SELWIN = 2,
    ITF_PANEL_TYPE_PLAIN = 3,
    ITF_PANEL_TYPE_PERA1 = 4,
    ITF_PANEL_TYPE_LEFTFADE = 5,
    ITF_PANEL_TYPE_MESWIN2 = 6,
    ITF_PANEL_TYPE_SPKWIN2 = 7,
    ITF_PANEL_TYPE_FACILITY = 8,
    ITF_PANEL_NUM_TYPE = 9,
} ITF_PANEL_TYPE;

typedef struct FontGsControl_t FontGsControl_t;
typedef struct FontMem_t FontMem_t;
typedef struct GsFont_t GsFont_t;
typedef struct _FRQ _FRQ;
typedef struct _RING_BUF _RING_BUF;
typedef struct _TEXT _TEXT;
typedef struct hmDecodeTbl_t hmDecodeTbl_t;
typedef struct hmHeader_t hmHeader_t;
typedef struct hmTreeTbl_t hmTreeTbl_t;
typedef struct itfMesBinFileHeader_t itfMesBinFileHeader_t;
typedef struct itfMesBinMesHeader_t itfMesBinMesHeader_t;
typedef struct itfMesBinSelHeader_t itfMesBinSelHeader_t;
typedef struct itfMesBinTypeHeader2_t itfMesBinTypeHeader2_t;
typedef struct itfMesBinTypeHeader_t itfMesBinTypeHeader_t;
typedef struct itfMiscCoord_t itfMiscCoord_t;
typedef struct itfPanelTypeWork_t itfPanelTypeWork_t;
typedef struct itfmisclinkheader_t itfmisclinkheader_t;
typedef struct itfmisclinkstack_t itfmisclinkstack_t;
typedef struct itfpanel_t itfpanel_t;
typedef struct mesflow_tag mesflow_tag;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct _FRQ {
    u8 draw_spd;
    s8 space;
    s16 x_size;
    s16 y_size;
    s16 voice;
    s32 x;
    s32 y;
    s32 w_pxls;
    u32 priority;
    s32 strlen;
    _TEXT *str;
    _TEXT *str_end;
    _FRQ *head;
    _FRQ *prev;
    _FRQ *next;
    char *tag_id;
};

struct _TEXT {
    u16 code;
    u16 draw_count;
    s32 lx;
    s32 ly;
    s32 lw;
    u32 color;
    u32 color_base;
    u32 color_edge;
    u8 col_no;
    u8 style;
    u8 tp;
    u8 mode;
    u8 width;
    u8 height;
    GsFont_t *gs_font;
    GsFont_t *user_font;
    _TEXT *prev;
    _TEXT *next;
    u16 chcode;
};

struct GsFont_t {
    u16 font_no;
    u16 y_shift;
    u16 used_count;
    FontMem_t *font_mem;
};

struct FontMem_t {
    u32 id;
    s32 uv[4];
    void *user_data;
    FontMem_t *prev;
    FontMem_t *next;
};

struct FontGsControl_t {
    sdfMemHandle_t *mh;
    sdfMemHandle_t *ud_mh;
    u32 unit_width;
    u32 unit_height;
    u32 unit_size;
    u32 unit_num_max;
    u32 unit_nums;
    FontMem_t root[UNKNOWN_ARRAY_SIZE];
};

struct _RING_BUF {
    s32 ID;
    _RING_BUF *Next;
    void *obj;
};

struct itfMesBinMesHeader_t {
    u8 label[UNKNOWN_ARRAY_SIZE];
    s16 page;
    u16 speaker;
    u32 addr[UNKNOWN_ARRAY_SIZE];
    s32 len[UNKNOWN_ARRAY_SIZE];
};

struct itfpanel_t {
    itfPanelTypeWork_t *pwork;
    s32 type;
    u32 z;
    sdfIVector4_t *pos;
    sdfIVector4_t *color;
};

struct itfmisclinkheader_t {
    void *pprev;
    void *pnext;
    s32 id;
};

struct itfmisclinkstack_t {
    mesflow_tag *puse_top;
    mesflow_tag *puse_tail;
    mesflow_tag *pdisuse_top;
    mesflow_tag *pdisuse_tail;
};

struct hmHeader_t {
    u32 header_size;
    u32 flag_size;
    u32 enc_byte_size;
    u32 enc_bit_size;
    u32 unit_dec_size;
    u32 access_tbl_num;
    u32 access_tbl_size;
    u32 org_size;
};

struct hmTreeTbl_t {
    u16 tree_id;
    u16 tree_branch[2];
};

struct hmDecodeTbl_t {
    hmTreeTbl_t tree_table[UNKNOWN_ARRAY_SIZE];
    u8 access_table;
    u8 data[UNKNOWN_ARRAY_SIZE];
};

struct itfMesBinFileHeader_t {
    u8 filetype;
    u8 format;
    s16 user_id;
    u32 filesize;
    u32 mgc;
    u32 extsize;
    u32 ofs_addrinfo;
    u32 size_addrinfo;
    u32 numtypeheader;
    u8 resolveaddress;
    u8 reserved0;
    u16 version;
};

struct itfMesBinTypeHeader_t {
    u32 type;
    s32 ptr;
};

struct itfMesBinTypeHeader2_t {
    s32 ppspkhead;
    s32 spknum;
    s32 pextdata;
    u32 reserved;
};

struct itfMesBinSelHeader_t {
    u8 label[UNKNOWN_ARRAY_SIZE];
    s16 ext;
    s16 item;
    s16 pattern;
    u16 reserved;
    u32 ptr[UNKNOWN_ARRAY_SIZE];
    s32 len[UNKNOWN_ARRAY_SIZE];
};

struct itfMiscCoord_t {
    sdfVector3_t pos;
    sdfVector3_t rot;
    sdfVector3_t scl;
};
