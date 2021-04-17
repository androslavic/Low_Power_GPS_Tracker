#include "init.h"

void init (void) {

	  HAL_Init();

	  SystemClock_Config();

	  MX_GPIO_Init();
	  MX_LPTIM1_Init();
	  MX_LPUART1_UART_Init();
	  MX_USART2_UART_Init();
	  BSP_LED_Init(LED3);

}
