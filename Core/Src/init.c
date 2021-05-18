#include "init.h"

void init (void) {


	  SMS=SMS_waiting;
	  loc=0;
	  sleepOK=0;
	  timeout=communicationPending;
	  debug=1;


	  HAL_Init();

	  SystemClock_Config();

	  MX_GPIO_Init();
	  MX_LPUART1_UART_Init();
	  MX_USART2_UART_Init();
	  BSP_LED_Init(LED3);
	  MX_LPTIM1_Init();

	  HAL_Delay(1000);



}
