#include "stm32f4xx_hal.h"

/**
 * @brief: initialize HAL library, it must be the first instruction to be executed in the main program
 *         (before calling any other HAL function), it performs the following:
 *          - Configure Flash
 *          - Configure Systick which generates an interrupt every 1 ms
 *          - Set NVIC Group Priority to 4
 *          - Calls HAL_MspInit() callback function defined in user file "stm32f4xx_hal_msp.c" to do
 *            the global low-level hardware initialization
 * 
 * @note:  SysTick is used as the time base for the HAL_Delay() function, the application need to ensure
 *         the SysTick timebase is always set to 1 ms to have correct HAL operation
 */
HAL_StatusTypeDef HAL_Init(void)
{
    // __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
    // __HAL_FLASH_DATA_CACHE_ENABLE():
    // __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
    
    //HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    //HAL_InitTick(TICK_INT_PRIORITY);
    
    return 0;
}

HAL_StatusTypeDef HAL_DeInit(void)
{
    return 0;
}

void HAL_MspInit(void)
{

}

void HAL_MspDeInit(void)
{

}

__weak HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
    return 0;
}