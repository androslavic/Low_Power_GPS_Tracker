#include "communication.h"

int debug=1;
int timeout=1;

void communication_test(void){

	char d=0;
	char string[20]={};
	//todo timeout implementation


	  strcpy(string,"AT\r\n");
	  LPUART1_SendString(string);

	  HAL_Delay(1000);

	  while (timeout==1)
	  {
		  	if(LPUART1_Dequeue (&d) != 0) {


			  print2string(string,d);

			  if (strstr(string,"OK")){
				  USART2_Debug("Communication test OK.\r\n");
				  timeout=0;
			  }


	  }

	  }
}
