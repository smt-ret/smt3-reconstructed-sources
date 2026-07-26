#include "types.h"

// 0x1891b70
f32 ***RectangularFloatArray(s32 size1, s32 size2) {
  s64 v5;
  u32 *v6;
  u64 v7;
  s64 *v9;
  s64 *v10;

  v5 = size1;
  v6 = NewSpecific(float__, size1);
  if (size1 >= 1)
  {
    v7 = 0;
    do
    {
      v9 = NewSpecific(f32, size2);
      v10 = v9;
      *&v6[2 * v7++ + 8] = v10;
    }
    while (v5 != v7);
  }
  return v6;
}
