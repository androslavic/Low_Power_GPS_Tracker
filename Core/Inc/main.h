#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l0xx_hal.h"
#include "stm32l0xx_nucleo_32.h"
#include "user.h"
#include "location.h"
#include "lptim.h"
#include "usart.h"
#include "gpio.h"
#include "sysclk.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "location.h"
#include "communication.h"
#include "sms.h"
#include "processing.h"
#include "sendCommand.h"
#include "init.h"



void Error_Handler(void);



enum communication {

	communicationOK=1,
	communicationFail=2,
	communicationHardFail=3,
	communicationPending=4
};

enum SMS_routine {

	SMS_waiting=0,
	SMS_recieved=1,
	SMS_read=2,
	SMS_processed=3,
};



#ifdef __cplusplus
}
#endif

#endif
