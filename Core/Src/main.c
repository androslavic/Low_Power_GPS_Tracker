
#include "main.h"





int main(void)
{
  char buffer1[BUFSIZE]={'\0'};
  char buffer2[BUFSIZE]= {'\0'};
  SMS=0;

  	init();

  	HAL_Delay(1000);

//  if (HAL_LPTIM_TimeOut_Start_IT(&hlptim1, Period, Timeout) != HAL_OK)
	HAL_LPTIM_TimeOut_Start_IT(&hlptim1, 36999, 1000);



  communication_test();
  /* pri paljenju uređaja provjerimo da postoji komunikacija s sim808
   * nakon toga sleep
   * rutina se pali prilikom interrupta s sim808 (poruka/poziv)
   * pali se antena AT+CGPSPWR=1
   * cekamo status AT+CGPSSTATUS? svakih 30 sekundi
   * (proizvoljno,treba mu par min da se pronađe)
   * kad dobijemo odgovor 3D fix --> AT+CGPSINF=2
   * dobivamo koordinate --> šalje se SMS*/


  	USART2_Debug("Suspend tick in 500ms \r\n");
	HAL_SuspendTick();

	USART2_Debug("Enter SLEEP in 500ms \r\n");
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);


	//USART2_SendString("Debug: enter STOP in 500ms \r\n");
	//HAL_Delay(500);
	//HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
	//	STOP mode se ne budi?




	USART2_Debug("Start while(1) \r\n");


  while (1)
  {
	  USART2_handler(buffer1);
	  LPUART_handler(buffer2);

	  //todo: check SMS
	  checkSMS();

  }
}




