
#include "main.h"






int main(void)
{

  char c;
  int i;

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_LPTIM1_Init();
  MX_LPUART1_UART_Init();
  MX_USART2_UART_Init();




  while (1)
  {
	  if (USART2_Dequeue (&c) != 0) {
		  USART2_SendChar(c);
		  LPUART1_SendChar(c);
	  }
	  if (LPUART1_Dequeue (&c) != 0) {
		  LPUART1_SendChar(c);
	  }  }


}

