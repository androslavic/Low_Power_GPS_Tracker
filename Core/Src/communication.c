#include "communication.h"

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

			  if (strchr(string,'K')){

				  USART2_SendString(string);
				  USART2_SendString("!!");
				  timeout=0;
			  }


	  }
	  HAL_Delay(1000);

	  /*
	strcpy(string,"AT\r\n");
	LPUART1_SendString(string);


	do{
		if (LPUART1_Dequeue (string) != 0){
			USART2_SendString(string);
		}
		d++;
	}
	while (d<10);

	strcpy(string,"Proslo!\r\n");

	USART2_SendString(string);


	do
	{
		if (LPUART1_Dequeue (&d) != 0)
		strncat( string,(const char*) &d, 1);
		USART2_SendString ("...\r\n");
		}
 	while (string[4]!=0 || timeout);

	if(strncmp(string,"OK",2)==0)
	USART2_SendString ("Communication OK!\r\n");
	else
	USART2_SendString ("communication not OK!\r\n");
	*/

	  }
}
