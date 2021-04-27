#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l0xx_hal.h"
#include "stm32l0xx_nucleo_32.h"
#include "lptim.h"
#include "usart.h"
#include "gpio.h"
#include "sysclk.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "communication.h"
#include "init.h"
#include "commands.h"
#include "user.h"


void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif
