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
	  if (strstr(str,"CGPSSTATUS")) {
		  USART2_SendString(str);

		  // citam CGPSSTATUS dok nije 3d fix
		  // 3dfix--> pozivam novu funkciju sendCommand("aalocation");
		  USART2_SendString(" debug pm1\r\n");
	  }

	  if (strstr(str,"CGPSPWR")) {
		  USART2_SendString(str);
		  USART2_SendString(" debug pm2\r\n");
	  }

	  if (strstr(str,"CGPSRST")) {
		  USART2_SendString(str);
		  USART2_SendString(" debug pm3\r\n");
	  }

	  // todo: provjeri tocno poruku i testiraj
	  if (strstr(str,"LOW POWER")) {
		  USART2_SendString(str);
		  sendCommand("aaLowPower");
		  USART2_SendString(" debug pm3\r\n");
	  }

	  //dummy implemetacija
	  if (strstr(str,"SMS-lalallala")) {
		  USART2_SendString(str);
		  //procitaj sms
		  //if (sms==gps)
		  // pali power
		  // warm reset
		  // loop sa CGPSSTATUS  .....to ide ova prva funkcija
		  USART2_SendString(" debug pm1\r\n");
	  }

	  if (strstr(str,"OK")) {
		  USART2_SendString(str);
		  USART2_SendString("\r\n");
	  }

}


void sendCommand (char *str){



	  if (strstr(str,"aass0")) {SMS=0;}
	  if (strstr(str,"aass1")) {SMS=1;}
	  if (strstr(str,"aass2")) {SMS=2;}

	  if (strstr(str,"aasss")) {
		  USART2_Debug("Suspend tick in 500ms \r\n");
		  HAL_SuspendTick();

		  memset(str,0,strlen(str));
		  HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	  	  }

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


	  if (strstr(str,"aalocation")) {
		  strcpy(str,"\r\n......\r\n"); LPUART1_SendString(str);
		  strcpy(str,"\r\n......\r\n"); LPUART1_SendString(str);
		  strcpy(str,"\r\n......\r\n"); LPUART1_SendString(str);
	  }

	  if (strstr(str,"aaLowPower")) {
		  strcpy(str,"\r\n......\r\n"); LPUART1_SendString(str);
		  strcpy(str,"\r\n......\r\n"); LPUART1_SendString(str);
		  strcpy(str,"\r\n......\r\n"); LPUART1_SendString(str);
	  }


	  if (strchr(str,'\r')) {LPUART1_SendString(str);}

}




void checkSMS(void){

//	todo: connect SMS variable to SMS info / interrupt
	static int state=10;
	char buffer[100]={'\0'};
	char str[100]={'\0'};


	if (SMS==1){
		//clear SMS flag
		SMS=2;
		//start routine
		state=0;
		strcpy(str,"\r\nAT+CGPSPWR=1\r\n");
		LPUART1_SendString(str);

		HAL_Delay(500);
		LPUART_handler(str);

		USART2_Debug("end of 1 \r\n");

	}

	//todo: read SMS to buffer
	strcpy(buffer,"GPS");


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
		strcpy(buffer,"");
		SMS=0;
		USART2_Debug("End of SMS routine. \r\n");


		}


	}


}

