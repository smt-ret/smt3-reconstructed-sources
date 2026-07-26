#pragma once
#include "types.h"

typedef struct StaffStruct StaffStruct;
typedef struct stfNameTbl_s stfNameTbl_s;

struct StaffStruct {
    char *left_string;
    char *right_string;
    s32 font1;
    s32 font2;
    s32 yPos;
};

struct stfNameTbl_s {
    char *part;
    char *name;
};
