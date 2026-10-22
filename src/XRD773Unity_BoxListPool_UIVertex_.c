#include "types.h"

typedef struct XRD773Unity_BoxObjectPool_List_T__ XRD773Unity_BoxObjectPool_List_T__;

static XRD773Unity_BoxObjectPool_List_T__ *s_ListPool;

// 0x8131f0
void *_Get(void) {
  s64 v1;
  XRD773Unity_BoxListPool_T__c *klass;
  s64 _0_XRD773Unity_BoxListPool_T;
  s16 v5;
  XRD773Unity_BoxListPool_T__c *v6;
  s64 v7;
  XRD773Unity_BoxListPool_T__c *v8;
  u64 v9;
  XRD773Unity_BoxListPool_T__c *v10;
  s64 v11;
  XRD773Unity_BoxListPool_T__c *v12;
  XRD773Unity_BoxListPool_T__c *v13;
  s64 v14;
  s16 v15;
  MethodInfo *_1_XRD773Unity_BoxObjectPool_List_T___Get;
  System_Collections_Generic_List_T__o *(__fastcall *methodPointer)(s64, MethodInfo *);
  System_Collections_Generic_List_T__o *(__fastcall *v19)(s64, MethodInfo *);

  klass = method->klass;
  if ((klass->_2.bitflags1 & 1) != 0)
  {
    _0_XRD773Unity_BoxListPool_T = klass->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
    v5 = *(_0_XRD773Unity_BoxListPool_T + 294);
    if ((v5 & 1) != 0)
      goto LABEL_3;
  }
  else
  {
    sub_88B3F0(method->klass, v1);
    _0_XRD773Unity_BoxListPool_T = klass->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
    v5 = *(_0_XRD773Unity_BoxListPool_T + 294);
    if ((v5 & 1) != 0)
    {
LABEL_3:
      if ((v5 & 0x200) == 0)
        goto LABEL_18;
      goto LABEL_4;
    }
  }
  sub_88B3F0(_0_XRD773Unity_BoxListPool_T, v1);
  if ((*(_0_XRD773Unity_BoxListPool_T + 294) & 0x200) == 0)
    goto LABEL_18;
LABEL_4:
  v6 = method->klass;
  if ((v6->_2.bitflags1 & 1) != 0)
  {
    v7 = v6->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
    if ((*(v7 + 294) & 1) != 0)
      goto LABEL_6;
  }
  else
  {
    sub_88B3F0(method->klass, v1);
    v7 = v6->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
    if ((*(v7 + 294) & 1) != 0)
    {
LABEL_6:
      if (!*(v7 + 216))
        goto LABEL_7;
LABEL_18:
      v10 = method->klass;
      if ((v10->_2.bitflags1 & 1) != 0)
        goto LABEL_20;
      goto LABEL_19;
    }
  }
  sub_88B3F0(v7, v1);
  if (*(v7 + 216))
    goto LABEL_18;
LABEL_7:
  v8 = method->klass;
  if ((v8->_2.bitflags1 & 1) == 0)
    sub_88B3F0(method->klass, v1);
  v9 = v8->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
  if ((*(v9 + 294) & 1) == 0)
    sub_88B3F0(v9, v1);
  v10 = method->klass;
  if ((v10->_2.bitflags1 & 1) == 0)
LABEL_19:
    sub_88B3F0(v10, v1);
LABEL_20:
  v11 = v10->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
  if ((*(v11 + 294) & 1) == 0)
    sub_88B3F0(v11, v1);
  v12 = method->klass;
  v13 = v12;
  v14 = **(v11 + 184);
  v15 = *&v12->_2.bitflags1;
  if ((v15 & 1) == 0)
  {
    sub_88B3F0(method->klass, v1);
    v13 = method->klass;
    v15 = *&v13->_2.bitflags1;
  }
  _1_XRD773Unity_BoxObjectPool_List_T___Get = v12->rgctx_data->_1_XRD773Unity_BoxObjectPool_List_T___Get;
  methodPointer = _1_XRD773Unity_BoxObjectPool_List_T___Get->methodPointer;
  if ((v15 & 1) == 0)
  {
    v19 = _1_XRD773Unity_BoxObjectPool_List_T___Get->methodPointer;
    sub_88B3F0(v13, v1);
    methodPointer = v19;
  }
  return methodPointer(v14, v13->rgctx_data->_1_XRD773Unity_BoxObjectPool_List_T___Get);
}

// 0x813380
void _Release(void *toRelease) {
  XRD773Unity_BoxListPool_T__c *klass;
  s64 _0_XRD773Unity_BoxListPool_T;
  s16 v6;
  XRD773Unity_BoxListPool_T__c *v7;
  s64 v8;
  XRD773Unity_BoxListPool_T__c *v9;
  u64 v10;
  XRD773Unity_BoxListPool_T__c *v11;
  s64 v12;
  XRD773Unity_BoxListPool_T__c *v13;
  XRD773Unity_BoxListPool_T__c *v14;
  s64 v15;
  s16 v16;
  MethodInfo *_2_XRD773Unity_BoxObjectPool_List_T___Release;
  void (__fastcall *methodPointer)(s64, System_Collections_Generic_List_T__o *, MethodInfo *);
  void (__fastcall *v19)(s64, System_Collections_Generic_List_T__o *, MethodInfo *);

  klass = method->klass;
  if ((klass->_2.bitflags1 & 1) != 0)
  {
    _0_XRD773Unity_BoxListPool_T = klass->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
    v6 = *(_0_XRD773Unity_BoxListPool_T + 294);
    if ((v6 & 1) != 0)
      goto LABEL_3;
  }
  else
  {
    sub_88B3F0(method->klass);
    _0_XRD773Unity_BoxListPool_T = klass->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
    v6 = *(_0_XRD773Unity_BoxListPool_T + 294);
    if ((v6 & 1) != 0)
    {
LABEL_3:
      if ((v6 & 0x200) == 0)
        goto LABEL_18;
      goto LABEL_4;
    }
  }
  sub_88B3F0(_0_XRD773Unity_BoxListPool_T);
  if ((*(_0_XRD773Unity_BoxListPool_T + 294) & 0x200) == 0)
    goto LABEL_18;
LABEL_4:
  v7 = method->klass;
  if ((v7->_2.bitflags1 & 1) != 0)
  {
    v8 = v7->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
    if ((*(v8 + 294) & 1) != 0)
      goto LABEL_6;
  }
  else
  {
    sub_88B3F0(method->klass);
    v8 = v7->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
    if ((*(v8 + 294) & 1) != 0)
    {
LABEL_6:
      if (!*(v8 + 216))
        goto LABEL_7;
LABEL_18:
      v11 = method->klass;
      if ((v11->_2.bitflags1 & 1) != 0)
        goto LABEL_20;
      goto LABEL_19;
    }
  }
  sub_88B3F0(v8);
  if (*(v8 + 216))
    goto LABEL_18;
LABEL_7:
  v9 = method->klass;
  if ((v9->_2.bitflags1 & 1) == 0)
    sub_88B3F0(method->klass);
  v10 = v9->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
  if ((*(v10 + 294) & 1) == 0)
    sub_88B3F0(v10);
  v11 = method->klass;
  if ((v11->_2.bitflags1 & 1) == 0)
LABEL_19:
    sub_88B3F0(v11);
LABEL_20:
  v12 = v11->rgctx_data->_0_XRD773Unity_BoxListPool_T_;
  if ((*(v12 + 294) & 1) == 0)
    sub_88B3F0(v12);
  v13 = method->klass;
  v14 = v13;
  v15 = **(v12 + 184);
  v16 = *&v13->_2.bitflags1;
  if ((v16 & 1) == 0)
  {
    sub_88B3F0(method->klass);
    v14 = method->klass;
    v16 = *&v14->_2.bitflags1;
  }
  _2_XRD773Unity_BoxObjectPool_List_T___Release = v13->rgctx_data->_2_XRD773Unity_BoxObjectPool_List_T___Release;
  methodPointer = _2_XRD773Unity_BoxObjectPool_List_T___Release->methodPointer;
  if ((v16 & 1) == 0)
  {
    v19 = _2_XRD773Unity_BoxObjectPool_List_T___Release->methodPointer;
    sub_88B3F0(v14);
    methodPointer = v19;
  }
  methodPointer(v15, toRelease, v14->rgctx_data->_2_XRD773Unity_BoxObjectPool_List_T___Release);
}
