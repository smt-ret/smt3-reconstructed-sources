#include "types.h"

typedef struct datNormalSkillVisual_s datNormalSkillVisual_t;

static datNormalSkillVisual_t *tbl[288];
static datNormalSkillVisual_t *dante[8];

bool evtBitCheck(s32 no);

// 0x7bb990
datNormalSkillVisual_t *Get(s32 id) {
  struct datNormalSkillVisual_t_array *dante;
  datNormalSkillVisual_t_o **m_Items;
  struct datNormalSkillVisual_t_array *tbl;
  struct datNormalSkillVisual_t_array *v13;
  struct datNormalSkillVisual_t_array *v16;
  struct datNormalSkillVisual_t_array *v19;
  struct datNormalSkillVisual_t_array *v22;
  struct datNormalSkillVisual_t_array *v25;
  struct datNormalSkillVisual_t_array *v28;
  struct datNormalSkillVisual_t_array *v31;

  if (evtBitCheck(3712))
  {
    switch (id)
    {
      case 262:
        m_Items = dante->m_Items;
        break;
      case 263:
        v13 = dante;
        m_Items = &v13->m_Items[1];
        break;
      case 264:
        v16 = dante;
        m_Items = &v16->m_Items[2];
        break;
      case 265:
        v19 = dante;
        m_Items = &v19->m_Items[3];
        break;
      case 266:
        v22 = dante;
        m_Items = &v22->m_Items[4];
        break;
      case 267:
        v25 = dante;
        m_Items = &v25->m_Items[5];
        break;
      case 268:
        v28 = dante;
        m_Items = &v28->m_Items[6];
        break;
      case 269:
        v31 = dante;
        m_Items = &v31->m_Items[7];
        break;
      default:
    }
  }
  else
  {
    m_Items = &tbl->m_Items[id];
  }
  return *m_Items;
}
