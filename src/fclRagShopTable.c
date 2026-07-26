#include "types.h"

typedef struct fclRagDevil_t fclRagDevil_t;
typedef struct fclRagItem_t fclRagItem_t;
typedef struct fclRagMitamaPack_t fclRagMitamaPack_t;
typedef struct fclRagSeireiPack_t fclRagSeireiPack_t;
typedef struct fclRag_t fclRag_t;

static fclRag_t *fclRagTbl[2];
static u16 fclRagDefaultMitamaTbl[4];
static u16 fclRagDefaultSeireiTbl[4];
static fclRagItem_t *fclRagItemTbl[25];
static u8 *fclRagItemPackTbl[2];
static fclRagDevil_t *fclRagMitamaTbl[21];
static fclRagMitamaPack_t *fclRagMitamaPackTbl[2];
static fclRagDevil_t *fclRagSeireiTbl[21];
static fclRagSeireiPack_t *fclRagSeireiPackTbl[2];
