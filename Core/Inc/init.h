
#ifndef __INIT_H__
#define __INIT_H__

#include "stm32l0xx_hal.h"
#include "lptim.h"
#include "usart.h"
#include "gpio.h"
#include "sysclk.h"
#include "user.h"


char buffer1[BUFSIZE];
char buffer2[BUFSIZE];

#endif


void init (void);


int loc;
int sleepOK;
int timeout;
int interruptSet;
int interruptTIM;
int locationFlag;
int messageFlag;
int findLocation;
int callFlag;
