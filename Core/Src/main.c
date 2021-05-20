
#include "main.h"


//dummy initial location


int main(void)
{




  	init();

  	//communicationTest();


	USART2_Debug("Start!");


  while (1)
  {
		  LPUART_handler(buffer2);
		  USART2_handler(buffer1);
		  wakeup_handler(wakeup);
	  }


  }





/*todo:
-SLEEP/STOP mode enable?
*/


