
#include "main.h"





int main(void)
{
  char buffer1[BUFSIZE]={'\0'};
  char buffer2[BUFSIZE]= {'\0'};
//  char c=0,d=0;
//  int i=0;


  	init();

  	//communication_test();

//  USART2_Debug("Suspend tick in 500ms");
//	HAL_SuspendTick();
//
//	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
////
//	HAL_Delay(500);
//
//	USART2_Debug("Debug: enter STOP in 500ms");
//	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
//	HAL_ResumeTick();
//
////		STOP mode se ne budi?
//
//

//
//
	USART2_Debug("Start while(1)");


  while (1)
  {
		  //checkSMS();
		  LPUART_handler(buffer2);
		  USART2_handler(buffer1);
	  }


  }







