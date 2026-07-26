#include "types.h"

typedef struct fclCombCom_t fclCombCom_t;
typedef struct fclCombSpirit_t fclCombSpirit_t;
typedef struct fclCombineTable_fclActParamTbl_t fclCombineTable_fclActParamTbl_t;
typedef struct fclEventDevil_t fclEventDevil_t;
typedef struct fclIkenieExtPatternDev2_t fclIkenieExtPatternDev2_t;
typedef struct fclIkenieExtPatternDevRace_t fclIkenieExtPatternDevRace_t;
typedef struct fclIkenieExtPatternDev_t fclIkenieExtPatternDev_t;
typedef struct fclIkenieExtPattern_t fclIkenieExtPattern_t;
typedef struct fclRankTbl_t fclRankTbl_t;

struct fclCombineTable_fclActParamTbl_t {
    u8 PosMode;
    u8 MotionNo;
    f32 EffOfs;
    f32 EffEraseSpd;
    f32 Radius;
    s32 Nums;
};

static u16 fclAccidentFailTbl[14];
static fclCombineTable_fclActParamTbl_t *fclActParamTbl[300];
static fclCombCom_t *fclBirthSpiritTbl[6];
static u8 *fclCombineTbl[32];
static u8 *fclCombineCurseTbl[32];
static u8 *fclCombineManinKagTbl[5];
static u8 fclCombineManinRaceTbl[4];
static u16 *fclCombineManinTbl[4];
static fclEventDevil_t *fclEventDevilTbl[32];
static fclCombCom_t *fclExtPatternTbl[3];
static fclIkenieExtPattern_t *fclIkenieExtPatternTbl[4];
static fclIkenieExtPatternDev_t *fclIkenieExtPatternDevTbl[7];
static fclIkenieExtPatternDev2_t *fclIkenieExtPatternDev2Tbl[19];
static fclIkenieExtPatternDevRace_t *fclIkenieExtPatternDevRaceTbl[2];
static fclRankTbl_t *fclRankUpDownTbl[4];
static fclCombSpirit_t *fclSpiritParamUpTbl[4];
