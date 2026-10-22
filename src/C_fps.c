#include "types.h"

typedef struct C_fps C_fps;

// 0xfe18b0
void Start(C_fps *this) {
  this->nextTime = get_time(0) + 1.0;
  *&this->frameCount = 0;
  *&this->seconds = 0;
}

// 0xfe18f0
void Update(C_fps *this) {
  f32 unscaledTime;
  f32 nextTime;
  s32 frameCount;
  f32 *p_seconds;
  f32 seconds;
  f32 v8;
  TMPro_TMP_Text_o *fpsText;
  System_Object_array *v10;
  s64 *v12;
  s64 *v13;
  s64 *v16;
  s64 *v17;
  s64 *v20;
  s64 *v21;
  System_String_o *v23;
  s32 dispFrameCount;

  ++this->frameCount;
  unscaledTime = get_unscaledTime();
  nextTime = this->nextTime;
  if (unscaledTime >= nextTime)
  {
    frameCount = this->frameCount;
    this->frameCount = 0;
    this->dispFrameCount = frameCount;
    this->nextTime = nextTime + 1.0;
  }
  p_seconds = &this->seconds;
  seconds = this->seconds;
  v8 = seconds + get_unscaledDeltaTime();
  this->seconds = v8;
  if (v8 >= 60.0)
  {
    ++this->minute;
    this->seconds = v8 + -60.0;
  }
  fpsText = this->fpsText;
  v10 = NewSpecific(object, 6u);
  v10->m_Items[0] = "FPS : ";
  dispFrameCount = this->dispFrameCount;
  v12 = sub_8D3950(s32, &dispFrameCount);
  v13 = v12;
  v10->m_Items[1] = v13;
  v10->m_Items[2] = "  Time : ";
  v16 = sub_232A70(&this->minute, "00");
  v17 = v16;
  v10->m_Items[3] = v17;
  v10->m_Items[4] = " : ";
  v20 = sub_4FDC70(p_seconds, "0.0");
  v21 = v20;
  v10->m_Items[5] = v21;
  v23 = Concat_5270224(v10);
  set_text(fpsText, v23);
}
