#pragma once
#include "types.h"

typedef struct Speaker_tag Speaker_tag;
typedef struct curctr_tag curctr_tag;
typedef struct instanceMes_tag instanceMes_tag;
typedef struct instanceMes_tag_func_kutiDelegate instanceMes_tag_func_kutiDelegate;
typedef struct message_tag message_tag;
typedef struct select_tag select_tag;
typedef struct variable_tag variable_tag;
typedef struct window_tag window_tag;

struct instanceMes_tag {
    u32 stat;
    void *pdata;
    void *pext;
    u32 z;
    s16 otindex;
    s16 type;
    Speaker_tag *speaker;
    message_tag *message;
    select_tag *select;
    window_tag *window;
    variable_tag *variable;
    curctr_tag *curctr;
    instanceMes_tag_func_kutiDelegate *func_kuti;
    char *master_text;
    char *key;
    s32 id;
};
