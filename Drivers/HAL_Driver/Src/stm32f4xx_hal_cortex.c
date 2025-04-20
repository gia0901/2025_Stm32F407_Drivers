#include "stm32f4xx_hal.h"

/**
 * @brief Initialize System Timer and its interrupt, and starts the System Tick Timer.
 * @param TicksNumb specifies the ticks (number of ticks between 2 interrupts)
 * @retval status: - 0 Function succeeded
 *                 - 1 Function failed
 */
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb)
{
    return SysTick_Config(TicksNumb);
}