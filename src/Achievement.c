#include "types.h"

typedef struct DefineAchievementID_string_ DefineAchievementID_string_;

static DefineAchievementID_string_ *_achievementTbl_k__BackingField;

// 0xfd4790
void Initialize(void *gameObj) {
  Il2CppObject *v2;
  u64 *v3;

  v2 = StringLiteral_4527;
  Log(v2, 0);
  v3 = Allocate(AchivementDummyID);
  _ctor(v3, 0);
  _achievementTbl_k__BackingField = v3;
}

// 0xfd4720
void Log(char *log) {
  Log(log, 0);
}

// 0xfd4890
void Unlock(s32 id) {
}

// 0xfd4950
void Unlock_16599376(char *id) {
  System_String_o *v3;
  Il2CppObject *v5;

  v3 = (id->klass->vtable._3_ToString.methodPtr)(id, id->klass->vtable._3_ToString.method);
  v5 = Concat_5224608(StringLiteral_4529, v3);
  Log(v5, 0);
}
