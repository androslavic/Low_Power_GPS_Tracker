#include "processing.h"

void processMessage(char *str){

	static int locationFlag=0;

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

	  // todo: provjeri tocno poruku i testiraj
	  if (strstr(str,"LOW POWER")) {
		  USART2_SendString(str);
		  sendCommand("aaLowPower");
	  }

	  if (strstr(str,"OVER-VOLTAGE WARNING")) {
		  //dummy implementation for over-voltage call
		  //sendCommand("overVoltage");
	  }

	  if (strstr(str,"+CGPSINF:")) {

		  setLocationFlag(&locationFlag);
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

	  if (strstr(str,"RING")) {
		  USART2_SendString("zvoni mi...");
		  USART2_SendString("mobilni");
		  USART2_SendString("te amo");
		  USART2_SendString("te amooooo");
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
