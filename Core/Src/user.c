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



	  if (strstr(str,"+CGPSPWR")) {

		  USART2_SendString("POWER");

		  USART2_SendString(str);
	  }

	  if (strstr(str,"+CBC")) {

		  USART2_SendString("BATERIJA");

		  USART2_SendString(str);
	  }

	  if (strstr(str,"OK")) {
		  USART2_SendString(str);
	  }


}


void sendCommand (char *str){



	  // location status
	  if (strstr(str,"aaps")) {strcpy(str,"\r\nAT+CGPSSTATUS?\r\n");LPUART1_SendString(str);}

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
