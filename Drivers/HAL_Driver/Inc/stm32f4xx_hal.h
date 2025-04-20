#ifndef _STM32F4XX_HAL_H_
#define _STM32F4XX_HAL_H_

// temporary including all HAL headers here
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_conf.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_cortex.h"

/* Initialization & Configuration functions */
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);

#endif // _STM32F4XX_HAL_H_