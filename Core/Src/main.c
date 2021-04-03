
#include "main.h"
#include "lptim.h"
#include "usart.h"
#include "gpio.h"
#include "sysclk.h"



int main(void)
{

  HAL_Init();

  SystemClock_Config();


  MX_GPIO_Init();
  MX_LPTIM1_Init();
  MX_LPUART1_UART_Init();
  MX_USART2_UART_Init();

  int i=0;

  while (1)
  {

	  i++;
  }
}





