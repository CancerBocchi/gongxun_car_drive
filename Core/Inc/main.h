/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SDA_Pin GPIO_PIN_0
#define SDA_GPIO_Port GPIOC
#define SCL_Pin GPIO_PIN_1
#define SCL_GPIO_Port GPIOC
#define M3_PWM_Pin GPIO_PIN_0
#define M3_PWM_GPIO_Port GPIOA
#define M2_PWM_Pin GPIO_PIN_1
#define M2_PWM_GPIO_Port GPIOA
#define M1_PWM_Pin GPIO_PIN_2
#define M1_PWM_GPIO_Port GPIOA
#define M4_PWM_Pin GPIO_PIN_3
#define M4_PWM_GPIO_Port GPIOA
#define KEY1_Pin GPIO_PIN_4
#define KEY1_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_5
#define KEY2_GPIO_Port GPIOC
#define KEY1B0_Pin GPIO_PIN_0
#define KEY1B0_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_2
#define LED_R_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_10
#define LED_G_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_11
#define BUZZER_GPIO_Port GPIOA
#define IN_M4__Pin GPIO_PIN_15
#define IN_M4__GPIO_Port GPIOA
#define IN_M4_C10_Pin GPIO_PIN_10
#define IN_M4_C10_GPIO_Port GPIOC
#define IN_M3__Pin GPIO_PIN_11
#define IN_M3__GPIO_Port GPIOC
#define IN_M2__Pin GPIO_PIN_12
#define IN_M2__GPIO_Port GPIOC
#define IN_M2_D2_Pin GPIO_PIN_2
#define IN_M2_D2_GPIO_Port GPIOD
#define IN_M3_B4_Pin GPIO_PIN_4
#define IN_M3_B4_GPIO_Port GPIOB
#define IN_M1__Pin GPIO_PIN_5
#define IN_M1__GPIO_Port GPIOB
#define IN_M1_B8_Pin GPIO_PIN_8
#define IN_M1_B8_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
