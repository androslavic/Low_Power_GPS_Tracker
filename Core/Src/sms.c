#include "sms.h"




void checkSMS(void){

	char str[BUFSIZE]={'\0'};


	if(SMS==SMS_recieved){
		USART2_Debug("SMS recieved!");
		LPUART1_SendString("AT+CMGL=\"REC UNREAD\"\r\n");

		HAL_Delay(500);
		LPUART_handler(str);
		SMS=SMS_pending;
	}

	if(SMS==SMS_read){
		USART2_Debug("SMS read!");
		sendLocation(phoneNumber);
	}


}

void sendLocation(char *number){

	char var[20];
	char c;


	if (strstr(messageStruct.text,"GPS")) {

		USART2_Debug("messageStruct.text==GPS");

		HAL_Delay(1000);


		while (LPUART1_Dequeue (&c) != 0);

		LPUART1_SendString("\r\nAT+CMGS=");
		LPUART1_SendString(messageStruct.phone);
		LPUART1_SendString("\r\n");

		HAL_Delay(2000);


		LPUART1_SendString(itoa(locationStruct.latitude1,var,10));
		LPUART1_SendChar('.');
		LPUART1_SendString(itoa(locationStruct.latitude2,var,10));
		LPUART1_SendChar(' ');
		LPUART1_SendChar(locationStruct.lat);
		LPUART1_SendChar(',');
		LPUART1_SendString(itoa(locationStruct.longitude1,var,10));
		LPUART1_SendChar('.');
		LPUART1_SendString(itoa(locationStruct.longitude2,var,10));
		LPUART1_SendChar(' ');
		LPUART1_SendChar(locationStruct.lon);

		LPUART1_SendChar(26);

		HAL_Delay(1000);

	}

	SMS=SMS_processed;

}


void setMessageFlag(int *messageFlag){

	*messageFlag=1;
}


void checkMessage(int *messageFlag, char *str){

	char * token;
	char * string;
	int cnt=0;

	strcpy(auxBuffer,str);

	if (*messageFlag){

		token = strtok (auxBuffer," ,.-");
		  while (token != NULL)
		  {
		    string=token;
			cnt++;
			messageStruct=parseMessage(cnt,string,messageStruct);

		    token = strtok (NULL, " ,.-");
		  }

		*messageFlag=0;

		SMS=SMS_read;
	}

}



message parseMessage (int cnt,char *string,message message){


	char *pointer;

	USART2_Debug(string);
	switch (cnt) {


	case 8:
		  strcpy(message.phone,string);
		break;
	case 11:
		  pointer=strchr(string,'\n');
		  strcpy(message.text,pointer+1);
		  USART2_Debug("message.text :");
		  USART2_SendString(message.text);
		break;

	default:
		break;

	}
	return message;
}
