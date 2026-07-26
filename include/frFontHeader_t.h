#pragma once
#include "types.h"

typedef struct frFontHeader_t frFontHeader_t;

struct frFontHeader_t {
    u32 header_size;
    u32 file_size;
    u8 compress;
    u8 type;
    u8 clut_nums;
    u8 style;
    u16 ext_dic_no;
    u16 nums;
    u16 width;
    u16 height;
    u16 data_step;
    u8 sub_flag;
    u8 reserved[9];
};
