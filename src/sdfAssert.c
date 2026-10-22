#include "types.h"

typedef struct sdfAssert_sdfAssertFunc_t sdfAssert_sdfAssertFunc_t;

static sdfAssert_sdfAssertFunc_t *sdfAssertFunc;

void sdfAbort(char *aFmt, void **LegacyParamArray);

// 0x17e01d0
void SDF_ABORT1(char *aFmt) {
  ;
}

// 0x17e01e0
void SDF_ABORT2(char *aFmt, void **LegacyParamArray) {
  System_String_o *v3;

  sdfAbort(v3, LegacyParamArray);
}

// 0x17e0250
void SDF_ABORT3(char *aFmt, void **LegacyParamArray) {
  System_String_o *v3;

  sdfAbort(v3, LegacyParamArray);
}

// 0x17e02c0
void SDF_ABORT4(char *aFmt, void **LegacyParamArray) {
  System_String_o *v3;

  sdfAbort(v3, LegacyParamArray);
}

// 0x17e01c0
void SDF_ASSERT(bool result) {
  ;
}

// 0x17e00e0
void sdfAbort(char *aFmt, void **LegacyParamArray) {
  System_Char_array *v3;
  System_String_o *String_5280336;
  sdfAssert_sdfAssertFunc_t_o *sdfAssertFunc;

  v3 = NewSpecific(char, 0x200u);
  String_5280336 = CreateString_5280336(0, v3);
  else
  {
    if (!sdfAssertFunc)
      return;
  }
  Invoke(sdfAssertFunc, String_5280336);
}

// 0x17df9c0
sdfAssert_sdfAssertFunc_t *sdfSetAssertFunc(sdfAssert_sdfAssertFunc_t *func) {
  return sdfAssertFunc;
}

// 0x17dfa30
void sdf_Assert(char *aFilename, s32 aLine, char *aCause) {
  u64 *v8;
  System_String_o *v11;
  s32 v13;

  if (sdfAssertFunc)
  {
    v13 = aLine;
    v8 = sub_8D3950(s32, &v13);
    v11 = Format_5268688("ASSERT: {0}:{1:D}:{2}", aFilename, v8, aCause);
    Invoke(sdfAssertFunc, v11);
  }
}
