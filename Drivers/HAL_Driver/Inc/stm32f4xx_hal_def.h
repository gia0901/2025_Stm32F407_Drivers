#ifndef _STM32F4XX_HAL_DEF_H_
#define _STM32F4XX_HAL_DEF_H_

#include <stddef.h>
#include "stm32f4xx.h"

/**
 * @brief: HAL status
 */
typedef enum
{
    HAL_OK      = 0x00U,
    HAL_ERROR   = 0x01U,
    HAL_BUSY    = 0x02U,
    HAL_TIMEOUT = 0x03U,
} HAL_StatusTypeDef;

/**
 * @brief: HAL Lock
 */
typedef enum
{
    HAL_UNLOCKED = 0x00U,
    HAL_LOCKED   = 0x01U,
} HAL_LockTypeDef;

/*--------------------------- Macros --------------------------*/
#define UNUSED(X) (void)X

#define __weak      __attribute__((weak))
#define __NOINLINE  __attribute__((noinline))

/*-------------------------------------------------------------*/


#endif // _STM32F4XX_HAL_DEF_H_