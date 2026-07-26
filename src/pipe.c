#include "types.h"

typedef struct tagPipeObject tagPipeObject;

// 0x153d130
void tagPipeObject__Copy(tagPipeObject *this, tagPipeObject *data) {
  f32 y;
  f32 v4;

  this->offset = data->offset;
  this->w = data->w;
  y = data->pos.y;
  this->pos.x = data->pos.x;
  this->pos.y = y;
  v4 = data->vpos.y;
  this->vpos.x = data->vpos.x;
  this->vpos.y = v4;
  this->id = data->id;
  this->action = data->action;
  this->enabled = data->enabled;
  this->mdl = data->mdl;
  this->count = data->count;
  this->status = data->status;
}
