#ifndef CJSON_API_H
#define CJSON_API_H

#include "cJSON.h"
#include "stdint.h"

#define   NAME            "name"     
#define   TEMP_NUM        "temp"  
#define   HUM_NUM         "hum" 

#define   DEFAULT_NAME          "fire"     
#define   DEFAULT_TEMP_NUM       25.0 
#define   DEFAULT_HUM_NUM        50.0 

#define   UPDATE_SUCCESS       1 
#define   UPDATE_FAIL          0

cJSON* CjsonDataInit(void);
uint8_t CjsonUpdate(const cJSON * const object,const char * const string,void *d);
void CjsonProscess(void* data);

#endif
