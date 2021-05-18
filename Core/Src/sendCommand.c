#include "sendCommand.h"

void sendCommand (char *str){


	  //clean buffer
	  if (strstr(str,"aacb"))  { cleanBuffer(str);USART2_SendString(str);}

	  //sms commands
	  if (strstr(str,"aass0")) { cleanBuffer(str); SMS=SMS_waiting;}
	  if (strstr(str,"aass1")) { cleanBuffer(str); SMS=SMS_recieved;}
	  if (strstr(str,"aass2")) { cleanBuffer(str); SMS=SMS_read;}
	  if (strstr(str,"aass3")) { cleanBuffer(str); SMS=SMS_processed;}

	  //turn on/off sim808 module with GPIO
	  if (strstr(str,"aakey")) { cleanBuffer(str); PowerOnKey();}

	  //restart mcu
	  if (strstr(str,"aamr")) { USART2_Debug("Restarting MCU!");  __NVIC_SystemReset();}

	  //perform communication test
	  if (strstr(str,"aact")) {  communicationTest();}

	  if (strstr(str,"aaoff")) {strcpy(str,"\r\nAT+CPOWD=1\r\n");LPUART1_SendString(str);}
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


	  //enter SLEEP mode
	  if (strstr(str,"aasss")) {
		  USART2_Debug("Suspend tick in 500ms");
		  HAL_SuspendTick();

		  memset(str,0,strlen(str));
		  HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	  	  }

	  //enter STOP mode
	  if (strstr(str,"aasss")) {
		  USART2_Debug("Suspend tick in 500ms");
		  HAL_SuspendTick();

		  memset(str,0,strlen(str));
		  HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
	  }

	  //print location
	  if (strstr(str,"aaloc")) {

		  cleanBuffer(str);
		  sprintf(locationBuffer,"\r\n%2d.%4d %c, %2d.%4d %c\r\n",
				  locationStruct.latitude1,locationStruct.latitude2,locationStruct.lat,
				  locationStruct.longitude1,locationStruct.longitude2,locationStruct.lon);
		  USART2_SendString(locationBuffer);
	  }

	  //everything else, performed when pressed ENTER
	  if (strchr(str,'\r')) {LPUART1_SendString(str);}

}

