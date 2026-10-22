#pragma once
#include "types.h"

typedef struct dds3MagaFuncTable_t dds3MagaFuncTable_t;
typedef struct dds3MagaFuncTable_t_CreateDelegate dds3MagaFuncTable_t_CreateDelegate;
typedef struct dds3MagaFuncTable_t_DeleteDelegate dds3MagaFuncTable_t_DeleteDelegate;
typedef struct dds3MagaFuncTable_t_DrawDelegate dds3MagaFuncTable_t_DrawDelegate;
typedef struct dds3MagaFuncTable_t_SetPosDelegate dds3MagaFuncTable_t_SetPosDelegate;
typedef struct dds3MagaFuncTable_t_SetRGBADelegate dds3MagaFuncTable_t_SetRGBADelegate;
typedef struct dds3MagaFuncTable_t_SetRotateMatrixDelegate dds3MagaFuncTable_t_SetRotateMatrixDelegate;

struct dds3MagaFuncTable_t {
    dds3MagaFuncTable_t_CreateDelegate *Create;
    dds3MagaFuncTable_t_DrawDelegate *Draw;
    dds3MagaFuncTable_t_DeleteDelegate *Delete;
    dds3MagaFuncTable_t_SetPosDelegate *SetPos;
    dds3MagaFuncTable_t_SetRGBADelegate *SetRGBA;
    dds3MagaFuncTable_t_SetRotateMatrixDelegate *SetRotateMatrix;
};
