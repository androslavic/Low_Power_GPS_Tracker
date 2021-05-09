#include "communication.h"

int debug=1;

void communication_test(void){

	char d=0;
	char string[20]={};
	int check=0;
	//todo timeout implementation
	char buffer[BUFSIZE]= {'\0'};
	char *sim808PowerOn="AT+CGPSPWR=1\r\n";
	char *gpsColdRestart="AT+CGPSRST=0\r\n";


	  LPUART1_SendString("AT\r\n");

	  HAL_Delay(100);

	  USART2_Debug("prvo");

	  while (timeout==communicationPending)
	  {
		  	if(LPUART1_Dequeue (&d) != 0 ) {

		  		if (check==0){

		  			print2string(string,d);

		  			if (strstr(string,"OK")){
		  				USART2_Debug("Communication test OK.");
		  				timeout=communicationOK;
		  				check=1;
		  				}
		  		}
		  		if(check) {
		  			USART2_Debug("Turning sim808 power ON.");
		  			sendCommand(sim808PowerOn);
		  			HAL_Delay(100);
		  			LPUART_reader(buffer);
		  			USART2_Debug("Reseting GPS module");
		  			sendCommand(gpsColdRestart);
		  			HAL_Delay(100);
		  			LPUART_reader(buffer);
		  		}
		  	}
	  }
	  USART2_Debug("prvo!");

	  if(timeout==communicationFail){
		  USART2_Debug("Communication test failed. Trying device restart!");
		  PowerOnKey();
		  USART2_Debug("Device turned on via Key. Starting second communication test");
	  }
	  USART2_Debug("drugo!");

		  if (timeout==communicationHardFail){
			  //STM reset
			  USART2_Debug("Communication test failed. Restarting MCU!");
			  __NVIC_SystemReset();
		  }
		  USART2_Debug("trece!");

}
