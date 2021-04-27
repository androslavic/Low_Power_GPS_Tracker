#include "user.h"


void cleanBuffer(char *buffer){

	int i;
    for(i=0;i<BUFSIZE;i++){
    	buffer[i]= 0;
    }

}

void print2string (char *str, char c){

	int i;

	for (i=0;i<(BUFSIZE-2);i++){

		if (str[i]=='\0')
		{
			str[i+1]=str[i];
			str[i]=c;
			return;
		}

	}

}

void processMessage(char *str){


		//todo: implement action for not fix,2d fix,3d fix
	  if (strstr(str,"CGPSSTATUS:") && 0) {
		  USART2_SendString(str);
		  USART2_SendString("\r\n");
	  }



	  if (strstr(str,"OK")) {
		  USART2_SendString(str);
		  USART2_SendString("\r\n");
	  }


}


void sendCommand (char *str){



	  // location status
	  if (strstr(str,"aags")) {strcpy(str,"\r\nAT+CGPSSTATUS?\r\n");LPUART1_SendString(str);}

	  // power status (on / off)
	  if (strstr(str,"aap?")) {strcpy(str,"\r\nAT+CGPSPWR?\r\n"); LPUART1_SendString(str);}

	  // power on
	  if (strstr(str,"aagp1")) {strcpy(str,"\r\nAT+CGPSPWR=1\r\n"); LPUART1_SendString(str);}

	  // power off
	  if (strstr(str,"aagp0")) {strcpy(str,"\r\nAT+CGPSPWR=0\r\n"); LPUART1_SendString(str);}

	  // gps cold restart
	  if (strstr(str,"aagr0")) {strcpy(str,"\r\nAT+CGPSRST=0\r\n"); LPUART1_SendString(str);}

	  // gps warm restart
	  if (strstr(str,"aagr1")) {strcpy(str,"\r\nAT+CGPSRST=1\r\n"); LPUART1_SendString(str);}

	  // gps formated information
	  if (strstr(str,"aagi")) {strcpy(str,"\r\nAT+CGPSINF=2\r\n"); LPUART1_SendString(str);}

	  // battery status
	  if (strstr(str,"aabs")) {strcpy(str,"\r\nAT+CBC\r\n"); LPUART1_SendString(str);}

	  if (strchr(str,'\r')) {LPUART1_SendString(str);}


}


void USART2_handler(char *str){

	char c=0;

	if (USART2_Dequeue (&c) != 0) {

		  USART2_SendChar(c);
		  print2string(str,c);
		  sendCommand(str);
	}
}


void LPUART_handler(char *str){

	char c=0;

	if (LPUART1_Dequeue (&c) != 0) {

		print2string(str,c);
		processMessage(str);
	  }
}


void checkSMS(void){

//	todo: connect SMS variable to SMS info / interrupt
	static int state=0;
	char buffer[100]={'\0'};
	char str[100]={'\0'};


	if (SMS==1){
		//clear SMS flag
		SMS=0;
		//start routine
		state=0;

	}

	//todo: read SMS to buffer
	strcpy(buffer,"GPS");


	if(strstr(buffer,"GPS")){

		switch (state){

		case 0:
			//sendCommand("aagp1");
			strcpy(str,"\r\nAT+CGPSPWR=1\r\n");
			LPUART1_SendString(str);
			strcpy(str, "");
			state++;
			break;

		case 1:
			strcpy(str,"\r\nAT+CGPSRST=0\r\n");
			LPUART1_SendString(str);
			strcpy(str, "");
			//sendCommand("aagr1");
			state++;
			break;
		}


	}


}

