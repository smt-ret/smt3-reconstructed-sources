#include "types.h"

typedef struct fldResHeadPos_t fldResHeadPos_t;
typedef struct fldResourcePoint_t fldResourcePoint_t;

// 0xf86800
void fldResHeadPos_t__Set(fldResHeadPos_t *this, sdfVector4_t Pos, sdfVector4_t Rot, sdfVector4_t Scl) {
  s64 v5;
  s64 v6;

  this->pos = Pos;
  this->rot = Rot;
  *&this->scl.x = v5;
  *&this->scl.z = v6;
}

// 0xf86a70
void fldResourcePoint_t__Set(fldResourcePoint_t *this, sdfVector4_t Pos, sdfVector4_t Rot, sdfVector4_t Scl) {
  s64 v5;
  s64 v6;

  this->rot = Pos;
  this->scl = Rot;
  *(this + 6) = v5;
  *(this + 7) = v6;
}
