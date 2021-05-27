#include "init.h"


location locationStruct={44,8732,'N',13,8502,'E'};
message messageStruct={"+3859822222222","msg"};
call callStruct={"+385983333333"};

char buffer1[BUFSIZE]={'\0'};
char buffer2[BUFSIZE]= {'\0'};




void init (void) {


	  locationFlag=0;
	  messageFlag=0;
	  callFlag=0;
	  SMS=SMS_waiting;
	  loc=0;
	  sleepOK=0;
	  timeout=communicationPending;
	  debug=1;
	  wakeup=0;
	  interruptSet=0;
	  interruptTIM=0;
	  findLocation=0;


	  HAL_Init();

	  SystemClock_Config();

	  MX_GPIO_Init();
	  MX_LPUART1_UART_Init();
	  MX_USART2_UART_Init();
	  BSP_LED_Init(LED3);
	  MX_LPTIM1_Init();

	  HAL_Delay(1000);



}
