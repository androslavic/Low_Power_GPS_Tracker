#include "processing.h"

void processMessage(char *str){

	static int locationFlag=0;
	static int messageFlag=0;

	//todo: implement action for not fix,2d fix,3d fix
	  if (strstr(str,"CGPSSTATUS")) {

		  if (strstr(str,"Not Fix")){
			  loc=1;
			  USART2_SendString(str);
		  }
		  if (strstr(str,"2D Fix")){
			  loc=2;
			  USART2_SendString(str);
		  }
		  if (strstr(str,"3D Fix")){
			  loc=3;
			  USART2_SendString(str);
		  }

		  // citam CGPSSTATUS dok nije 3d fix
		  // 3dfix--> pozivam novu funkciju sendCommand("aalocation");
	  }

	  if (strstr(str,"CGPSPWR")) {
		  //dummy implementation for power call
	  }

	  if (strstr(str,"CGPSRST")) {
		  //dummy implementation for reset call
	  }

	  //dummy implementation for low-voltage call
	  if (strstr(str,"LOW POWER")) {
		  USART2_SendString(str);
		  //sendCommand("LowPower");
	  }

	  if (strstr(str,"OVER-VOLTAGE WARNING")) {
		  //dummy implementation for over-voltage call
		  //sendCommand("overVoltage");
	  }

	  if (strstr(str,"+CGPSINF:")) {

		  setLocationFlag(&locationFlag);
	  }

	  if (strstr(str,"AT+CMGL=\"REC UNREAD\"")) {

		  setMessageFlag(&messageFlag);
	  }

	  if (strstr(str,"RING")) {
		  USART2_SendString(str);

		  //todo: pokreni rutinu isto ko i za SMS

		  // reject call
		  strcpy(str,"\r\nATH\r\n");
		  LPUART1_SendString(str);

		  sendLocation(phoneNumber);

	  }

	  if (strstr(str,"OK")) {

		  checkLocation(&locationFlag,str);
		  checkMessage(&messageFlag,str);
		  USART2_SendString(str);
		  USART2_SendString("\r\n");

	  }

}
