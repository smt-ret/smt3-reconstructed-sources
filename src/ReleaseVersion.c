#include "types.h"

typedef struct ReleaseVersion ReleaseVersion;

// 0x1891c80
void Start(ReleaseVersion *this) {
  Il2CppObject *Switch_JA;
  System_String_o *v4;
  struct SettingData_o *settingData;
  TMPro_TMP_Text_o *VerText;
  System_String_o *v7;

  Switch_JA = this->settingData->Switch_JA;
  Log(Switch_JA, 0);
  v4 = StringLiteral_8856;
  this->Platform = 1;
  settingData = this->settingData;
  VerText = this->VerText;
  v7 = Concat_5224608(v4, settingData->Switch_JA);
  set_text(VerText, v7);
}

// 0x1891d30
void Update(ReleaseVersion *this) {
  ;
}
