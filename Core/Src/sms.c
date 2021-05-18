#include "sms.h"




void checkSMS(void){

//	todo: connect SMS variable to SMS info / interrupt
	static int state=10;
	char buffer[BUFSIZE]={'\0'};
	char str[BUFSIZE]={'\0'};


	if (SMS==SMS_recieved){

		USART2_Debug("SMS recieved!");
		LPUART1_SendString("AT+CMGL=\"REC UNREAD\"\r\n");

		HAL_Delay(500);
		LPUART_handler(str);

		SMS=SMS_read;


	}

	//todo: read SMS to buffer


	if(strstr(buffer,"GPS")){

		switch (state){

		case 0:
			//sendCommand("aagp1");
			strcpy(str,"\r\nAT+CGPSSTATUS?\r\n");
			LPUART1_SendString(str);
			strcpy(str, "");


			strcpy(buffer,"GPx");
			break;

		case 1:

			strcpy(str, "");
			//sendCommand("aagr1");
			state++;
			break;

		default:
		SMS=SMS_waiting;


		}


	}


}
