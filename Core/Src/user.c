#include "user.h"


void setLocationFlag(int *locationFlag){

	*locationFlag=1;
}

void checkLocation(int *locationFlag, char *str){

	  char * token;
	  char * string;
	  int cnt=0;

	if (*locationFlag){


		token = strtok (str," ,.-");
		  while (token != NULL)
		  {
		    string=token;
			cnt++;
			parseLocation(cnt,string);

			USART2_SendString(string);
			USART2_SendString("\r\n");
		    token = strtok (NULL, " ,.-");
		  }

		*locationFlag=0;
	}
}


void cleanBuffer(char *buffer){

	int i;
    for(i=0;i<BUFSIZE;i++){
    	buffer[i]= 0;
    }

}

void parseLocation (int cnt,char *string){

//	char c=0;
//	char *str="";
//
//	HAL_Delay(50);
//	if (LPUART1_Dequeue (&c) != 0) {
//		USART2_SendChar(c);
//		print2string(str,c);
//		HAL_Delay(10);
//	}

	switch (cnt) {

	case 4:
		break;
	case 5:
		break;
	case 6:
		break;


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


	static int locationFlag=0;

		//todo: implement action for not fix,2d fix,3d fix
	  if (strstr(str,"CGPSSTATUS")) {

		  if (strstr(str,"Not Fix"))
			  loc=1;
		  if (strstr(str,"2D Fix"))
			  loc=2;
		  if (strstr(str,"3D Fix"))
			  loc=3;

		  USART2_SendString(str);

		  // citam CGPSSTATUS dok nije 3d fix
		  // 3dfix--> pozivam novu funkciju sendCommand("aalocation");
	  }

	  if (strstr(str,"CGPSPWR")) {
		  USART2_SendString(str);
	  }

	  if (strstr(str,"CGPSRST")) {
		  USART2_SendString(str);
	  }

	  // todo: provjeri tocno poruku i testiraj
	  if (strstr(str,"LOW POWER")) {
		  USART2_SendString(str);
		  sendCommand("aaLowPower");
	  }

	  if (strstr(str,"+CGPSINF:")) {

		  setLocationFlag(&locationFlag);
		  USART2_SendString(str);
		  str="";

	  }

	  //dummy implemetacija
	  if (strstr(str,"SMS-lalallala")) {
		  USART2_SendString(str);
		  //procitaj sms
		  //if (sms==gps)
		  // pali power
		  // warm reset
		  // loop sa CGPSSTATUS  .....to ide ova prva funkcija
	  }

	  if (strstr(str,"OK")) {

		  checkLocation(&locationFlag,str);
		  USART2_SendString(str);
		  USART2_SendString("\r\n");
	  }

}


void sendCommand (char *str){



	  if (strstr(str,"aass0")) {
		  SMS=0;
		  cleanBuffer(str);
	  }
	  if (strstr(str,"aass1")) {
		  SMS=1;
		  cleanBuffer(str);
	  }
	  if (strstr(str,"aass2")) {
		  SMS=2;
		  cleanBuffer(str);
	  }

	  if (strstr(str,"aakey")) {
		  cleanBuffer(str);
		  PowerOnKey();
	  }

	  if (strstr(str,"aaoff")) {
		  cleanBuffer(str);
		  LPUART1_SendString("\r\nAT+CPOWD=1\r\n");
	  }


	  if (strstr(str,"aasss")) {
		  USART2_Debug("Suspend tick in 500ms");
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
	char buffer[BUFSIZE]={'\0'};
	char str[BUFSIZE]={'\0'};


	if (SMS==3){
		//clear SMS flag
		SMS=2;
		//start routine
		state=0;
		strcpy(str,"\r\nAT+CGPSPWR=1\r\n");
		LPUART1_SendString(str);

		HAL_Delay(500);
		LPUART_handler(str);

		USART2_Debug("end of 1");

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
		USART2_Debug("End of SMS routine.");


		}


	}


}

void PowerOnKey (void){

	//switch power on via Key pin on sim808

	  //USART2_Debug("Key set to 0 for 1 second");
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1,GPIO_PIN_RESET);
	  HAL_Delay(1000);
	  //USART2_Debug("Key set to 1");
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1,GPIO_PIN_SET);
	  USART2_SendString("\r\n");

}
