#include "types.h"

typedef struct XRD773Unity_BoxObjectPool_object_ XRD773Unity_BoxObjectPool_object_;

struct XRD773Unity_BoxObjectPool_object_ {
    void *m_Stack;
    void *m_ActionOnGet;
    void *m_ActionOnRelease;
    s32 _countAll_k__BackingField;
};

// 0x8138e0
void *_Get(XRD773Unity_BoxObjectPool_object_ *this) {
  Il2CppObject *v4;
  struct UnityEngine_Events_UnityAction_T__o *m_ActionOnGet;
  s32 v7;

  if (!(method->klass->rgctx_data->_2_System_Collections_Generic_Stack_T__get_Count->methodPointer)(this->m_Stack))
  {
    v4 = (method->klass->rgctx_data->_5_System_Activator_CreateInstance_T_->methodPointer)();
    v7 = (method->klass->rgctx_data->_0_XRD773Unity_BoxObjectPool_T__get_countAll->methodPointer)(this);
    (method->klass->rgctx_data->_6_XRD773Unity_BoxObjectPool_T__set_countAll->methodPointer)(this, (v7 + 1));
    m_ActionOnGet = this->m_ActionOnGet;
    if (!m_ActionOnGet)
      return v4;
    goto LABEL_3;
  }
  v4 = (method->klass->rgctx_data->_7_System_Collections_Generic_Stack_T__Pop->methodPointer)(this->m_Stack);
  m_ActionOnGet = this->m_ActionOnGet;
  if (m_ActionOnGet)
LABEL_3:
    (method->klass->rgctx_data->_8_UnityEngine_Events_UnityAction_T__Invoke->methodPointer)(m_ActionOnGet, v4);
  return v4;
}

// 0x8139c0
void _Release(XRD773Unity_BoxObjectPool_object_ *this, void *element) {
  struct UnityEngine_Events_UnityAction_T__o *m_ActionOnRelease;

  if ((method->klass->rgctx_data->_2_System_Collections_Generic_Stack_T__get_Count->methodPointer)(this->m_Stack) >= 1
    && (method->klass->rgctx_data->_9_System_Collections_Generic_Stack_T__Peek->methodPointer)(this->m_Stack) == element)
  {
    LogError("Internal error. Trying to destroy object that is already released to pool.");
  }
  m_ActionOnRelease = this->m_ActionOnRelease;
  if (m_ActionOnRelease)
    (method->klass->rgctx_data->_8_UnityEngine_Events_UnityAction_T__Invoke->methodPointer)(m_ActionOnRelease, element);
  (method->klass->rgctx_data->_11_System_Collections_Generic_Stack_T__Push->methodPointer)(
    this->m_Stack,
    element);
}
