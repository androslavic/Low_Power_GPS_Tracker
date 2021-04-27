#ifndef __USER_H__
#define __USER_H__

#define BUFSIZE 100

#include "main.h"



void cleanBuffer(char *buffer);

void print2string (char *str, char c);

void processMessage(char *str);

void sendCommand (char *str);


void USART2_handler(char *str);


void LPUART_handler(char *str);


void checkSMS(void);

int SMS;

extern int SMS;


#endif
