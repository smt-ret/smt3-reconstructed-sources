#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effPCPDANTE_Thunder_Param_t effPCPDANTE_Thunder_Param_t;
typedef struct effPCPDANTE_Thunder_tag effPCPDANTE_Thunder_tag;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;

struct effPCPDANTE_Thunder_tag {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    effPCPDANTE_Thunder_Param_t *param;
    f32 length;
    u32 abgr;
    effPCP_ThunderPoly_t *pThunderPoly;
    s32 frame;
    u8 draw;
    dds3ProcessID_t *ProcessID;
};

// 0x11ee510
void Clear(effPCPDANTE_Thunder_tag *this) {
  this->ProcessID = 0;
  *(&this->pThunderPoly + 5) = 0;
  *&this->pos.x = 0;
  *&this->length = 0;
  this->pThunderPoly = 0;
  *&this->matrix.m23 = 0;
  this->param = 0;
  *&this->matrix.m22 = 0;
  *&this->matrix.m03 = 0;
  *&this->matrix.m21 = 0;
  *&this->matrix.m02 = 0;
  *&this->matrix.m20 = 0;
  *&this->matrix.m01 = 0;
  *&this->pos.z = 0;
  *&this->matrix.m00 = 0;
}
