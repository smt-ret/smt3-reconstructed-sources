#pragma once
#include "types.h"

typedef struct XRD773Unity_BoxObjectPool_T_ XRD773Unity_BoxObjectPool_T_;

struct XRD773Unity_BoxObjectPool_T_ {
    void *m_Stack;
    void *m_ActionOnGet;
    void *m_ActionOnRelease;
    s32 _countAll_k__BackingField;
};
