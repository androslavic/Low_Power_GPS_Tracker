#include "wakeup.h"

void wakeup_handler(int wakeUp){


	if (wakeUp){

		HAL_Delay(1000);

    	USART2_Debug("Interrupt wake-up!");
		HAL_Delay(500);

		LPUART1_SendString("\r\nAT\r\n");

		HAL_Delay(50);

		wakeup=0;

		//checkSMS();

		if (SMS==SMS_processed){
			wakeup=0;
			//todo: back to sleep!!
		}

	}


}

