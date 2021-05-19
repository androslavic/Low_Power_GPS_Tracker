
#ifndef INC_CALL_H_
#define INC_CALL_H_

#include "main.h"



typedef struct {

	char phone[20];

}call;


void setCallFlag(int *callFlag);
void checkCall(int *callFlag, char *str);
call parseCall (int cnt,char *string,call call);




extern call callStruct;

#endif
