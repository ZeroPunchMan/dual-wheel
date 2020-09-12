/**
  ******************************************************************************
  * File Name          : IWDG.c
  * Description        : This file provides code for the configuration
  *                      of the IWDG instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "iwdg.h"

/* USER CODE BEGIN 0 */
#include "sys_time.h"
/* USER CODE END 0 */

/* IWDG init function */
void MX_IWDG_Init(void)
{

  LL_IWDG_Enable(IWDG);
  LL_IWDG_EnableWriteAccess(IWDG);
  LL_IWDG_SetPrescaler(IWDG, LL_IWDG_PRESCALER_256);
  LL_IWDG_SetReloadCounter(IWDG, 1250);
  while (LL_IWDG_IsReady(IWDG) != 1)
  {
  }

  LL_IWDG_ReloadCounter(IWDG);

}

/* USER CODE BEGIN 1 */
void IWDG_Process(void)
{
    static uint64_t lastFeedTime = 0;

    if(TimeElapsed(lastFeedTime) > WDG_FEED_INTERVAL)
    {   //达到喂狗间隔时间,喂狗
        SetToCurTime(&lastFeedTime);
        LL_IWDG_ReloadCounter(IWDG);
//        Log("定时喂狗\r\n");
    }
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
