#include "types.h"

typedef struct effPCP_PBCamera_Param_t effPCP_PBCamera_Param_t;
typedef struct effPCP_PBCamera_tag effPCP_PBCamera_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCP_PBCamera_tag {
    sdfMatrix4_t matrix;
    sdfVector4_t pos;
    effPCP_PBCamera_Param_t *param;
    effPartHandle_t *hPB;
    u8 ex;
    s32 frame;
};

// 0x122a090
void Clear(effPCP_PBCamera_tag *this) {
  this->frame = 0;
  this->ex = 0;
  this->param = 0;
  this->hPB = 0;
  *&this->pos.x = 0;
  *&this->pos.z = 0;
  *&this->matrix.m03 = 0;
  *&this->matrix.m23 = 0;
  *&this->matrix.m02 = 0;
  *&this->matrix.m22 = 0;
  *&this->matrix.m01 = 0;
  *&this->matrix.m21 = 0;
  *&this->matrix.m00 = 0;
  *&this->matrix.m20 = 0;
}
