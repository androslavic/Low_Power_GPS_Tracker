#include "sendCommand.h"

void sendCommand (char *str){


	  if (strstr(str,"aaloc")) {

		  cleanBuffer(str);
		  sprintf(locationBuffer,"\r\n%2d.%4d %c, %2d.%4d %c\r\n",
				  locationStruct.latitude1,locationStruct.latitude2,locationStruct.lat,
				  locationStruct.longitude1,locationStruct.longitude2,locationStruct.lon);
		  USART2_SendString(locationBuffer);


	  }

	  if (strstr(str,"aacb")) {
		  cleanBuffer(str);
		  USART2_SendString(str);
	  }

	  if (strstr(str,"aass0")) {
		  SMS=0;
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
	  if (strstr(str,"aamr")) {
		  USART2_Debug("Restarting MCU!");
		  __NVIC_SystemReset();
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

