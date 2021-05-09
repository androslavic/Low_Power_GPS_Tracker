/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
char  RX_BUFFER[BUFSIZE];
char  RX_BUFFER_LP[BUFSIZE];
int  RX_BUFFER_HEAD , RX_BUFFER_TAIL;
int  RX_BUFFER_HEAD_LP , RX_BUFFER_TAIL_LP;
uint8_t  rx_data,rx_data_lp;
/* USER CODE END Includes */

extern UART_HandleTypeDef hlpuart1;
extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

void MX_LPUART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */
extern  char  RX_BUFFER[BUFSIZE];
extern  int  RX_BUFFER_HEAD , RX_BUFFER_TAIL;
extern  char  RX_BUFFER_LP[BUFSIZE];
extern  int  RX_BUFFER_HEAD_LP , RX_BUFFER_TAIL_LP;
void  USART2_SendChar(uint8_t c);
int  USART2_Dequeue(char* c);
void  LPUART1_SendChar(uint8_t c);
int  LPUART1_Dequeue(char* c);
void  USER_UART_IRQHandler(UART_HandleTypeDef *huart);
void Error_Handler(void);
void  LPUART1_SendString(char *c);
void  USART2_SendString(char *c);
void  USART2_Debug(char *c);
void LPUART_handler(char *str);
void USART2_handler(char *str);
void LPUART_reader(char *str);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
