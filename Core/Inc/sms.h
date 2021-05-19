#ifndef __SMS_H__
#define __SMS_H__
#include "main.h"


typedef struct {

	char phone[20];
	char text[20];
}message;

void checkSMS(void);
void sendLocation(char *number);
void setMessageFlag(int *messageFlag);
void checkMessage(int *messageFlag, char *str);
message parseMessage (int cnt,char *string,message message);


int SMS;

extern int SMS;


extern message messageStruct;

#endif