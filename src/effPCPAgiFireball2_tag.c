#include "types.h"

typedef struct effPCPAgiFireball2Param_t effPCPAgiFireball2Param_t;
typedef struct effPCPAgiFireball2_tag effPCPAgiFireball2_tag;
typedef struct effPCPAgiFireball_tag effPCPAgiFireball_tag;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;

struct effPCPAgiFireball2_tag {
    effPCPAgiFireball2Param_t *param;
    effPCPAgiFireball_tag *pAgiFireball[3];
    s32 frame;
};

void Clear(mdlManager_mdlTbMbAbLoadCb_t *this);

// 0x16c3ac0
void Clear(effPCPAgiFireball2_tag *this) {
  struct effPCPAgiFireball_tag_array *v3;
  struct effPCPAgiFireball_tag_array *v4;
  u64 *v5;
  struct effPCPAgiFireball_tag_array *pAgiFireball;
  struct effPCPAgiFireball_tag_array *v8;
  u64 *v9;
  struct effPCPAgiFireball_tag_array *v12;
  struct effPCPAgiFireball_tag_array *v14;
  u64 *v15;
  struct effPCPAgiFireball_tag_array *v18;

  v3 = NewSpecific(effPCPAgiFireball_tag, 3u);
  this->pAgiFireball = v3;
  v4 = v3;
  v5 = Allocate(effPCPAgiFireball_tag);
  _ctor(v5, 0);
  v4->m_Items[0] = v5;
  pAgiFireball = this->pAgiFireball;
  Clear(pAgiFireball->m_Items[0]);
  v8 = this->pAgiFireball;
  v9 = Allocate(effPCPAgiFireball_tag);
  _ctor(v9, 0);
  v8->m_Items[1] = v9;
  v12 = this->pAgiFireball;
  Clear(v12->m_Items[1]);
  v14 = this->pAgiFireball;
  v15 = Allocate(effPCPAgiFireball_tag);
  _ctor(v15, 0);
  v14->m_Items[2] = v15;
  v18 = this->pAgiFireball;
  Clear(v18->m_Items[2]);
}
