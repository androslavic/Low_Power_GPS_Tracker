
#include "main.h"



int main(void)
{




  	init();

  	communicationTest();

	USART2_Debug("Start!");


  while (1)
  {
		  LPUART_handler(buffer2);
		  USART2_handler(buffer1);
		  wakeup_handler(wakeup);
		  location_handler();

  }


  }





/*todo:
-SLEEP/STOP mode enable?
*/


