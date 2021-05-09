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

	  while (timeout==1)
	  {
		  	if(LPUART1_Dequeue (&d) != 0 ) {

		  		if (check==0){

		  			print2string(string,d);

		  			if (strstr(string,"OK")){
		  				USART2_Debug("Communication test OK.");
		  				timeout=0;
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
}
