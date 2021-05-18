#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

#include "stm32l0xx_hal.h"
#include "usart.h"
#include <string.h>
#include "user.h"
#include "lptim.h"
#include "main.h"
#endif

void  communicationTest(void);
void communicationRoutine(int status);

extern int timeout;
extern int debug;

