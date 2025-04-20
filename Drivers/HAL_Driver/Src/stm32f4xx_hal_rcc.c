#include "stm32f4xx_hal.h"

HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef* RCC_OscInitStruct)
{
    // uint32_t tickstart, pll_config;
    
    // if (RCC_OscInitStruct == NULL) {
    //     return HAL_ERROR;
    // }

    // //assert_param();
    // /*-------------------- Configure HSE Oscillator --------------------*/
    // if ((RCC_OscInitStruct->OscillatorType & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE)
    // {
    //     /* If sysclk is HSE or PLL + HSE */
    //     if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR_SWS_HSE) || 
    //         (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR_SWS_PLL && (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC == RCC_PLLCFGR_PLLSRC_HSE)))
    //     {
    //         /* if HSE is ready but HSE state is wanted to be OFF -> error
    //            else, nothing to be set for HSE -> skip */
    //         if ((__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET) && (RCC_OscInitStruct->HSEState == RCC_HSE_OFF))
    //             return HAL_ERROR;
    //     }
    //     /* HSE is not configured yet, now configure it based on requested state */
    //     else
    //     {
    //         __HAL_RCC_HSE_CONFIG(RCC_OscInitStruct->HSEState);

    //         /* Check does ON state (HSE_ON & HSE_BYP) finish or not */
    //         if (RCC_OscInitStruct->HSEState != RCC_HSE_OFF) {
    //             tickstart = HAL_GetTick();
                
    //             while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET) {
    //                 if (HAL_GetTick() - tickstart > HSE_TIMEOUT_VALUE)
    //                     return HAL_TIMEOUT;
    //             }
    //         }
    //         /* Check does OFF state finish (= RESET) or not */
    //         else {
    //             tickstart = HAL_GetTick();

    //             while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET) {
    //                 if (HAL_GetTick() - tickstart > HSE_TIMEOUT_VALUE)
    //                     return HAL_TIMEOUT;
    //             }
    //         }
    //     }
    // }


    /*-------------------- Configure HSI Oscillator --------------------*/
    

    return 0;
}