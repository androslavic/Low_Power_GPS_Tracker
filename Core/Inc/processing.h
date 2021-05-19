#ifndef __PROCESSING_H__
#define __PROCESSING_H__
#include "main.h"

void processMessage(char *str);

char locationBuffer[100];
char messageBuffer[100];
char callBuffer[100];
char auxBuffer[100];
char phoneNumber[100];

extern char locationBuffer[100];
extern char auxBuffer[100];
extern char phoneNumber[100];

#endif
