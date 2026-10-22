#include "types.h"

typedef struct datInfoSelectTable_s datInfoSelectTable_t;
typedef struct datInnenNegoTable_s datInnenNegoTable_t;
typedef struct datNegoNormalQuesInfo_s datNegoNormalQuesInfo_t;

static u8 **datNegoReqTable;
static u8 ***datNegoReqItemListA;
static u8 **datNegoTuikaReqtype;
static u8 ***datNegoReqItemListB;
static u8 **datNegoMukanTypeList;
static u8 **datNegoFightTaido;
static u8 **datNegoPrivateQues;
static datNegoNormalQuesInfo_t **datNegoNormalQuesInfo;
static u8 ****datNegoKotowariQuesInfo;
static datInnenNegoTable_t *InnenNegoTable;
static datInfoSelectTable_t *InfoSelectTable;
