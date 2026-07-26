#include "types.h"

typedef struct datInfoSelectTable_s datInfoSelectTable_t;
typedef struct datInnenNegoTable_s datInnenNegoTable_t;
typedef struct datNegoNormalQuesInfo_s datNegoNormalQuesInfo_t;

static u8 *datNegoReqTable[UNKNOWN_ARRAY_SIZE];
static u8 **datNegoReqItemListA[UNKNOWN_ARRAY_SIZE];
static u8 *datNegoTuikaReqtype[UNKNOWN_ARRAY_SIZE];
static u8 **datNegoReqItemListB[UNKNOWN_ARRAY_SIZE];
static u8 *datNegoMukanTypeList[UNKNOWN_ARRAY_SIZE];
static u8 *datNegoFightTaido[UNKNOWN_ARRAY_SIZE];
static u8 *datNegoPrivateQues[UNKNOWN_ARRAY_SIZE];
static datNegoNormalQuesInfo_t *datNegoNormalQuesInfo[UNKNOWN_ARRAY_SIZE];
static u8 ***datNegoKotowariQuesInfo[UNKNOWN_ARRAY_SIZE];
static datInnenNegoTable_t InnenNegoTable[UNKNOWN_ARRAY_SIZE];
static datInfoSelectTable_t InfoSelectTable[UNKNOWN_ARRAY_SIZE];
