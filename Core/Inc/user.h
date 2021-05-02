#ifndef __USER_H__
#define __USER_H__

#define BUFSIZE 200

#include "main.h"



void cleanBuffer(char *buffer);

void print2string (char *str, char c);

void processMessage(char *str);

void sendCommand (char *str);

void checkSMS(void);

void parseLocation (void);

void setLocationFlag(int *locationFlag);

void checkLocation(int *locationFlag,char *str);

int SMS;

extern int SMS;


#endif
