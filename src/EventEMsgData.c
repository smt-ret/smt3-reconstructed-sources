#include "types.h"

typedef struct EventEMsgData EventEMsgData;

// 0xfe7380
char *GetMsgText(EventEMsgData *this, char *id) {
  Il2CppObject *v5;
  System_Collections_Generic_List_object__o *eventEMsgData;
  u64 *v7;
  System_String_o *result;

  v5 = Allocate(EventEMsgData___c__DisplayClass1_0);
  _ctor(v5, 0);
  v5[1].klass = id;
  eventEMsgData = this->_eventEMsgData;
  v7 = Allocate(System_Predicate_MsgData_);
  __ctor(
    v7,
    v5,
    Method_EventEMsgData___c__DisplayClass1_0__GetMsgText_b__0__);
  result = _Find(
             eventEMsgData,
             v7);
  if (result)
    return result[1].klass;
  return result;
}
