#include "sms.h"




void checkSMS(void){

	char buffer[BUFSIZE]={'\0'};
	char str[BUFSIZE]={'\0'};


	if (SMS==SMS_recieved){

		USART2_Debug("SMS recieved!");
		LPUART1_SendString("AT+CMGL=\"REC UNREAD\"\r\n");

		HAL_Delay(500);
		LPUART_handler(str);

		SMS=SMS_read;


	}


	if(strstr(buffer,"GPS"));

	sendLocation(phoneNumber);



}

void sendLocation(char *number){

	char var[20];
	char c;

	USART2_Debug(callStruct.phone);
	USART2_Debug(messageStruct.phone);
	HAL_Delay(1000);

	while (LPUART1_Dequeue (&c) != 0);

	LPUART1_SendString("\r\nAT+CMGS=\"");
	LPUART1_SendString("+385955189053");
	LPUART1_SendString("\"\r\n");

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

		  sprintf(messageBuffer,"\r\n%s %s\r\n",
				  messageStruct.phone,messageStruct.text);
		  USART2_SendString(messageBuffer);
	}

}



message parseMessage (int cnt,char *string,message message){


	char *pointer;

	switch (cnt) {


	case 8:
		  strcpy(message.phone,string);
		break;
	case 11:
		  pointer=strchr(string,'\n');
		  strcpy(message.text,pointer+1);
		break;

	default:
		break;

	}
	return message;
}
