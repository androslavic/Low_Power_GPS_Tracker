/**
  ******************************************************************************
  * @file    lptim.h
  * @brief   This file contains all the function prototypes for
  *          the lptim.c file
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
#ifndef __LPTIM_H__
#define __LPTIM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
int timerFlag;

/* Set the Maximum value of the counter (Auto-Reload) that defines the Period */
#define Period               (uint32_t) 65535

/* Set the Timeout value */
#define Timeout              (uint32_t) (32768 - 1)
/* USER CODE END Includes */

extern LPTIM_HandleTypeDef hlptim1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_LPTIM1_Init(void);
void USER_LPTIM_IRQHandler (LPTIM_HandleTypeDef *hlptim);
void flag_Toggle (int *flag);

/* USER CODE BEGIN Prototypes */
extern int timerFlag;
extern int timeout;
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __LPTIM_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
