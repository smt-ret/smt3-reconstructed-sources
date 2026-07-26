#include "types.h"

typedef struct Disp_RevisionNo Disp_RevisionNo;

char *GetRevNo(void);

// 0xfe5c00
void Start(Disp_RevisionNo *this) {
  struct System_String_o *RevNo;

  RevNo = GetRevNo();
  this->Text = RevNo;
  set_text(this->RevNoText, RevNo);
}
