#include "communication.h"


void communicationTest(void){


	  while (timeout==communicationPending)
	  {
		  	communicationRoutine(communicationPending);
	  }

	  while(timeout==communicationFail){
		  USART2_Debug("Communication test failed. Trying device restart!");
		  PowerOnKey();
		  USART2_Debug("Device turned on via Key. Starting second communication test");
		  communicationRoutine(communicationFail);
	  }

		  if (timeout==communicationHardFail){
			  //STM reset
			  USART2_Debug("Communication test failed. Restarting MCU!");
			  __NVIC_SystemReset();
		  }

}


void communicationRoutine(int status){

	int check=0;
	char buffer[BUFSIZE]= {'\0'};
	char *sim808PowerOn="AT+CGPSPWR=1\r\n";
	char *gpsColdRestart="AT+CGPSRST=0\r\n";
	char *textMode="AT+CMGF=1\r\n";

	char d=0;
	char string[20]={};

	LPUART1_SendString("AT\r\n");

	HAL_Delay(1000);

	while(LPUART1_Dequeue (&d) != 0 ) {


		if (check==0){

  			print2string(string,d);

  			if (strstr(string,"OK")){
  				USART2_Debug("Communication test OK.");
  				timeout=communicationOK;
  				check=1;
  				}
	  		}
		if(check) {
			USART2_Debug("Turning sim808 power ON...");
			sendCommand(sim808PowerOn);
			HAL_Delay(100);
			LPUART_reader(buffer);
			USART2_Debug("Reseting GPS module...");
			sendCommand(gpsColdRestart);
			HAL_Delay(100);
			LPUART_reader(buffer);
			USART2_Debug("Enabling text mode...");
			sendCommand(textMode);
			HAL_Delay(100);
			LPUART_reader(buffer);
			break;
			}
		}

	if(timeout==communicationFail){
		timeout=communicationHardFail;
	}

	if(timeout==communicationPending){
		timeout=communicationFail;
	}





}
