#include "wakeup.h"

void wakeup_handler(int wakeUp){



	char *sim808PowerOn="AT+CGPSPWR=1\r\n";
	char *gpsWarmRestart="AT+CGPSRST=1\r\n";
	char buffer[BUFSIZE]= {'\0'};
	static int awake=0;


	if (wakeup){

		if(!awake){

			sendCommand(sim808PowerOn);
			HAL_Delay(100);
			LPUART_reader(buffer);
			sendCommand(gpsWarmRestart);
			HAL_Delay(100);
			LPUART_reader(buffer);
			awake=1;
		}


		checkSMS();


		if (SMS==SMS_processed){
			wakeup=0;
			awake=0;
			USART2_Debug("SMS processed!");
			//todo: back to sleep!!
		}

	}

}


