
#include "main.h"





int main(void)
{
  char c=0,i;
  char buffer1[BUFSIZE]={'\0'};
  char buffer2[BUFSIZE]= {'\0'};


  init();

  HAL_Delay(1000);

//  if (HAL_LPTIM_TimeOut_Start_IT(&hlptim1, Period, Timeout) != HAL_OK)
	HAL_LPTIM_TimeOut_Start_IT(&hlptim1, 36999, 1000);


  /* ### - 4 - Enter in Stop mode ########################################### */
  //HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);

  //communication_test();
  /* pri paljenju uređaja provjerimo da postoji komunikacija s sim808
   * nakon toga sleep
   * rutina se pali prilikom interrupta s sim808 (poruka/poziv)
   * pali se antena AT+CGPSPWR=1
   * cekamo status AT+CGPSSTATUS? svakih 30 sekundi
   * (proizvoljno,treba mu par min da se pronađe)
   * kad dobijemo odgovor 3D fix --> AT+CGPSINF=2
   * dobivamo koordinate --> šalje se SMS*/

  USART2_SendString("Debug: Start while(1) \r\n");
  HAL_Delay(1000);


  while (1)
  {




	  if (USART2_Dequeue (&c) != 0) {

		  USART2_SendChar(c);
		  print2string(buffer1,c);
		  sendCommand(buffer1);


	  }



	  if (LPUART1_Dequeue (&c) != 0) {


		  print2string(buffer2,c);
		  processMessage(buffer2);

		  }
  }
}




