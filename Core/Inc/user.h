#ifndef __USER_H__
#define __USER_H__

#define BUFSIZE 100

#include "main.h"



void cleanBuffer(char *buffer);

void print2string (char *str, char c);

void processMessage(char *str);

void sendCommand (char *str);

#endif
