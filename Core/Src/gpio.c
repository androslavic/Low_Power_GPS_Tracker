
#include "gpio.h"

void MX_GPIO_Init(void)
 {

  GPIO_InitTypeDef GPIO_InitStruct = {0};

   /* GPIO Ports Clock Enable */
   __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
 // GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

 }

/* USER CODE BEGIN 2 */



void HAL_GPIO_EXTI_Callback (uint16_t GPIO_Pin){


		if (GPIO_Pin==GPIO_PIN_5){
		  	 USART2_Debug("GPIO pin5!");
		       BSP_LED_Toggle(LED3);
		}
		if (GPIO_Pin==GPIO_PIN_4){
		  	 USART2_Debug("GPIO pin4!");
		       BSP_LED_Toggle(LED3);
		}
}

void USER_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin){


	 BSP_LED_Toggle(LED3);
}


/* USER CODE END 2 */
