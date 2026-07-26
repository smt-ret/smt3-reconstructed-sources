#include "types.h"

typedef struct ButtonGuideList ButtonGuideList;
typedef struct GuideDataTbl_GuideData GuideDataTbl_GuideData;

// 0xfe0690
GuideDataTbl_GuideData *GetGuideData(ButtonGuideList *this, char *category) {
  Il2CppObject *v5;
  System_Collections_Generic_List_object__o *guideData;
  u64 *v7;

  v5 = Allocate(ButtonGuideList___c__DisplayClass1_0);
  _ctor(v5, 0);
  v5[1].klass = category;
  guideData = this->_guideData;
  v7 = Allocate(System_Predicate_GuideData_);
  __ctor(
    v7,
    v5,
    Method_ButtonGuideList___c__DisplayClass1_0__GetGuideData_b__0__);
  return _Find(
           guideData,
           v7);
}
