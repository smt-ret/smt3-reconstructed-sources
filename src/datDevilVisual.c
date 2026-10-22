#include "types.h"

typedef struct datUnitVisual_s datUnitVisual_t;

static u8 *datDevilMotionAtoB;
static datUnitVisual_t *tbl_0_000_01F;
static datUnitVisual_t *tbl_1_020_03F;
static datUnitVisual_t *tbl_2_040_05F;
static datUnitVisual_t *tbl_3_060_07F;
static datUnitVisual_t *tbl_4_080_09F;
static datUnitVisual_t *tbl_5_0A0_0BF;
static datUnitVisual_t *tbl_6_0C0_0DF;
static datUnitVisual_t *tbl_7_0E0_0FF;
static datUnitVisual_t *tbl_8_100_11F;
static datUnitVisual_t *tbl_9_120_13F;
static datUnitVisual_t *tbl_10_140_15F;
static datUnitVisual_t *tbl_11_160_17F;
static datUnitVisual_t *dante;

bool evtBitCheck(s32 no);

// 0x8fe8f0
datUnitVisual_t *Get(s32 id) {
  struct datUnitVisual_t_array *v5;
  datUnitVisual_t_o **m_Items;
  struct datUnitVisual_t_array *v9;
  s32 v12;
  struct datUnitVisual_t_array *tbl_0_000_01F;
  Il2CppClass **v16;
  struct datUnitVisual_t_array *tbl_1_020_03F;
  s64 v19;
  struct datUnitVisual_t_array *v24;
  struct datUnitVisual_t_array *dante;

  if (!evtBitCheck(3712))
    goto LABEL_21;
  if (id > 339)
  {
    if (id == 340)
    {
      m_Items = &dante->m_Items[2];
    }
    else
    {
      if (id != 341)
        goto LABEL_21;
      v9 = dante;
      m_Items = &v9->m_Items[3];
    }
  }
  else
  {
    if (id != 192)
    {
      if (id == 339)
      {
        v5 = dante;
        m_Items = &v5->m_Items[1];
        return *m_Items;
      }
LABEL_21:
      v12 = convDLCDevilNumber(id);
      if (v12 <= 31)
      {
        v16 = &tbl_0_000_01F->obj.klass + v12;
        goto LABEL_38;
      }
      if (v12 <= 63)
      {
        v19 = v12 - 32LL;
        if (v19 >= LODWORD(tbl_1_020_03F->max_length))
          goto LABEL_36;
LABEL_37:
        v16 = &tbl_1_020_03F->obj.klass + v19;
LABEL_38:
        m_Items = (v16 + 4);
        return *m_Items;
      }
      if (v12 > 95)
      {
        if (v12 > 127)
        {
          if (v12 > 159)
          {
            if (v12 > 191)
            {
              if (v12 > 223)
              {
                if (v12 > 255)
                {
                  if (v12 > 287)
                  {
                    if (v12 > 319)
                    {
                      if (v12 > 351)
                      {
                        {
                        }
                        tbl_1_020_03F = tbl_11_160_17F;
                        v19 = v12 - 352LL;
                        if (v19 < LODWORD(tbl_1_020_03F->max_length))
                          goto LABEL_37;
                      }
                      else
                      {
                        {
                        }
                        tbl_1_020_03F = tbl_10_140_15F;
                        v19 = v12 - 320LL;
                        if (v19 < LODWORD(tbl_1_020_03F->max_length))
                          goto LABEL_37;
                      }
                    }
                    else
                    {
                      {
                      }
                      tbl_1_020_03F = tbl_9_120_13F;
                      v19 = v12 - 288LL;
                      if (v19 < LODWORD(tbl_1_020_03F->max_length))
                        goto LABEL_37;
                    }
                  }
                  else
                  {
                    tbl_1_020_03F = tbl_8_100_11F;
                    v19 = v12 - 256LL;
                    if (v19 < LODWORD(tbl_1_020_03F->max_length))
                      goto LABEL_37;
                  }
                }
                else
                {
                  tbl_1_020_03F = tbl_7_0E0_0FF;
                  v19 = v12 - 224LL;
                  if (v19 < LODWORD(tbl_1_020_03F->max_length))
                    goto LABEL_37;
                }
              }
              else
              {
                tbl_1_020_03F = tbl_6_0C0_0DF;
                v19 = v12 - 192LL;
                if (v19 < LODWORD(tbl_1_020_03F->max_length))
                  goto LABEL_37;
              }
            }
            else
            {
              tbl_1_020_03F = tbl_5_0A0_0BF;
              v19 = v12 - 160LL;
              if (v19 < LODWORD(tbl_1_020_03F->max_length))
                goto LABEL_37;
            }
          }
          else
          {
            tbl_1_020_03F = tbl_4_080_09F;
            v19 = v12 - 128LL;
            if (v19 < LODWORD(tbl_1_020_03F->max_length))
              goto LABEL_37;
          }
        }
        else
        {
          tbl_1_020_03F = tbl_3_060_07F;
          v19 = v12 - 96LL;
          if (v19 < LODWORD(tbl_1_020_03F->max_length))
            goto LABEL_37;
        }
      }
      else
      {
        tbl_1_020_03F = tbl_2_040_05F;
        v19 = v12 - 64LL;
        if (v19 < LODWORD(tbl_1_020_03F->max_length))
          goto LABEL_37;
      }
LABEL_36:
    }
    v24 = dante;
    m_Items = v24->m_Items;
  }
  return *m_Items;
}

// 0x8fee30
datUnitVisual_t *Get2(s32 id) {
  s32 v4;
  struct datUnitVisual_t_array *tbl_0_000_01F;
  Il2CppClass **v8;
  struct datUnitVisual_t_array *tbl_1_020_03F;
  s64 v11;

  v4 = convDLCDevilNumber(id);
  if (v4 > 31)
  {
    if (v4 <= 63)
    {
      v11 = v4 - 32LL;
      if (v11 >= LODWORD(tbl_1_020_03F->max_length))
        goto LABEL_18;
LABEL_19:
      v8 = &tbl_1_020_03F->obj.klass + v11;
      return v8[4];
    }
    if (v4 > 95)
    {
      if (v4 > 127)
      {
        if (v4 > 159)
        {
          if (v4 > 191)
          {
            if (v4 > 223)
            {
              if (v4 > 255)
              {
                if (v4 > 287)
                {
                  if (v4 > 319)
                  {
                    if (v4 > 351)
                    {
                      {
                      }
                      tbl_1_020_03F = tbl_11_160_17F;
                      v11 = v4 - 352LL;
                      if (v11 < LODWORD(tbl_1_020_03F->max_length))
                        goto LABEL_19;
                    }
                    else
                    {
                      {
                      }
                      tbl_1_020_03F = tbl_10_140_15F;
                      v11 = v4 - 320LL;
                      if (v11 < LODWORD(tbl_1_020_03F->max_length))
                        goto LABEL_19;
                    }
                  }
                  else
                  {
                    tbl_1_020_03F = tbl_9_120_13F;
                    v11 = v4 - 288LL;
                    if (v11 < LODWORD(tbl_1_020_03F->max_length))
                      goto LABEL_19;
                  }
                }
                else
                {
                  tbl_1_020_03F = tbl_8_100_11F;
                  v11 = v4 - 256LL;
                  if (v11 < LODWORD(tbl_1_020_03F->max_length))
                    goto LABEL_19;
                }
              }
              else
              {
                tbl_1_020_03F = tbl_7_0E0_0FF;
                v11 = v4 - 224LL;
                if (v11 < LODWORD(tbl_1_020_03F->max_length))
                  goto LABEL_19;
              }
            }
            else
            {
              tbl_1_020_03F = tbl_6_0C0_0DF;
              v11 = v4 - 192LL;
              if (v11 < LODWORD(tbl_1_020_03F->max_length))
                goto LABEL_19;
            }
          }
          else
          {
            tbl_1_020_03F = tbl_5_0A0_0BF;
            v11 = v4 - 160LL;
            if (v11 < LODWORD(tbl_1_020_03F->max_length))
              goto LABEL_19;
          }
        }
        else
        {
          tbl_1_020_03F = tbl_4_080_09F;
          v11 = v4 - 128LL;
          if (v11 < LODWORD(tbl_1_020_03F->max_length))
            goto LABEL_19;
        }
      }
      else
      {
        tbl_1_020_03F = tbl_3_060_07F;
        v11 = v4 - 96LL;
        if (v11 < LODWORD(tbl_1_020_03F->max_length))
          goto LABEL_19;
      }
    }
    else
    {
      tbl_1_020_03F = tbl_2_040_05F;
      v11 = v4 - 64LL;
      if (v11 < LODWORD(tbl_1_020_03F->max_length))
        goto LABEL_19;
    }
LABEL_18:
  }
  v8 = &tbl_0_000_01F->obj.klass + v4;
  return v8[4];
}
