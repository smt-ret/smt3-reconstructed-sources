#pragma once
#include "types.h"

typedef enum {
    SCR_DATATYPE_PROCTABLE = 0,
    SCR_DATATYPE_LABELTABLE = 1,
    SCR_DATATYPE_SCRDATA = 2,
    SCR_DATATYPE_MESSAGE = 3,
    SCR_DATATYPE_STRINGS = 4,
    SCR_DATATYPE_MAX = 5,
} SCR_DATATYPE;

typedef enum {
    SCR_STACK_TYPE_INT = 0,
    SCR_STACK_TYPE_FLOAT = 1,
    SCR_STACK_TYPE_INTVAR = 2,
    SCR_STACK_TYPE_FLOATVAR = 3,
    SCR_STACK_TYPE_RET = 4,
    SCR_STACK_TYPE_STRING = 5,
    SCR_STACK_TYPE_EMPTY = 6,
    SCR_STACK_TYPE_MAX = 7,
} SCR_STACK;

typedef enum {
    CODE_TYPE_PUSHI = 0,
    CODE_TYPE_PUSHF = 1,
    CODE_TYPE_PUSHIX = 2,
    CODE_TYPE_PUSHIY = 3,
    CODE_TYPE_PUSHREG = 4,
    CODE_TYPE_POPIX = 5,
    CODE_TYPE_POPIY = 6,
    CODE_TYPE_PROC = 7,
    CODE_TYPE_COMM = 8,
    CODE_TYPE_END = 9,
    CODE_TYPE_JUMP = 10,
    CODE_TYPE_CALL = 11,
    CODE_TYPE_RUN = 12,
    CODE_TYPE_GOTO = 13,
    CODE_TYPE_ADD = 14,
    CODE_TYPE_SUB = 15,
    CODE_TYPE_MUL = 16,
    CODE_TYPE_DIV = 17,
    CODE_TYPE_MINUS = 18,
    CODE_TYPE_NOT = 19,
    CODE_TYPE_OR = 20,
    CODE_TYPE_AND = 21,
    CODE_TYPE_EQ = 22,
    CODE_TYPE_NEQ = 23,
    CODE_TYPE_S = 24,
    CODE_TYPE_L = 25,
    CODE_TYPE_SE = 26,
    CODE_TYPE_LE = 27,
    CODE_TYPE_IF = 28,
    CODE_TYPE_PUSHIS = 29,
    CODE_TYPE_PUSHLIX = 30,
    CODE_TYPE_PUSHLFX = 31,
    CODE_TYPE_POPLIX = 32,
    CODE_TYPE_POPLFX = 33,
    CODE_TYPE_PUSHSTR = 34,
    CODE_TYPE_MAX = 35,
} CODE_TYPE;

typedef enum {
    CODE_RET_END = 0,
    CODE_RET_NEXT = 1,
    CODE_RET_SYNC = 2,
} CODE_RET;

typedef enum {
    SCR_RESULT_ERROR = 0,
    SCR_RESULT_CONTINUE = 1,
    SCR_RESULT_END = 2,
} SCR_RESULT;

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct scrCode_t scrCode_t;
typedef struct scrCommandTable_t scrCommandTable_t;
typedef struct scrCommandTable_t_funcDelegate scrCommandTable_t_funcDelegate;
typedef struct scrHeader_t scrHeader_t;
typedef struct scrLabelTable_t scrLabelTable_t;
typedef struct scrProcTable_t scrProcTable_t;
typedef struct scrProcessWork_s scrProcessWork_s;
typedef struct scrStackData_u scrStackData_u;
typedef struct scrTypeTable_t scrTypeTable_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct scrCommandTable_t {
    scrCommandTable_t_funcDelegate *comm;
    s32 paranum;
};

struct scrHeader_t {
    u8 FileType;
    u8 FileFormat;
    u16 UserID;
    s32 FileSize;
    u16 *MagicCode;
    s32 ExpandSize;
    s32 TypeTableCount;
    u16 LocalIntCount;
    u16 LocalFloatCount;
    s32 Resrve2;
    s32 Resrve3;
};

struct scrProcessWork_s {
    u8 Name[24];
    scrHeader_t Header;
    scrTypeTable_t *TypeTable;
    scrProcTable_t *ProcTable;
    scrLabelTable_t *LabelTable;
    scrCode_t *Code;
    u8 *MessageData;
    u8 *StringData;
    s32 CP;
    s32 SP;
    u8 StackType[28];
    scrStackData_u StackData[28];
    s32 StartProc;
    s32 MesHandle;
    s32 ScriptTimer;
    s32 CommandTimer;
    f32 ScriptTimerF;
    f32 CommandTimerF;
    sdfMemHandle_t *MemHandle;
    u32 *LocalInt;
    f32 *LocalFloat;
    dds3ProcessID_t *ProcessID;
    scrProcessWork_s *prev;
    scrProcessWork_s *next;
    void *data;
};

struct scrTypeTable_t {
    s32 Type;
    s32 ItemSize;
    s32 ItemCount;
    s32 ItemAddress;
};

struct scrProcTable_t {
    u8 Name[24];
    s32 CodeAddress;
    s32 Reserve1;
};

struct scrLabelTable_t {
    u8 Name[24];
    s32 CodeAddress;
    s32 Reserve1;
};

struct scrCode_t {
    s32 i;
    f32 f;
    s16 s0;
    s16 s1;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
};

struct scrStackData_u {
    s32 i;
    f32 f;
    s16 s0;
    s16 s1;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
};
