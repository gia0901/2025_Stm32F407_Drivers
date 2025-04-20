#ifndef _STM32F4XX_HAL_RCC_H_
#define _STM32F4XX_HAL_RCC_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal_def.h"

/**
 * @brief: RCC PLL configuration structure
 */
typedef struct
{
    uint32_t PLLState;
    uint32_t PLLSource;
    uint32_t PLLM;
    uint32_t PLLN;
    uint32_t PLLP;
    uint32_t PLLQ;

} RCC_PLLInitTypeDef;

/**
 * @brief: RCC oscillator (HSE,HSI,LSE,LSI) configuration structure
 */
typedef struct
{
    uint32_t OscillatorType;    /*< Type of osc.        See @ref RCC_Oscillator_Type >*/
    uint32_t HSEState;          /*< New state of HSE.   See @ref RCC_HSE_Config >*/
    uint32_t LSEState;
    uint32_t LSIState;
    uint32_t HSIState;
    uint32_t HSICalibrationState;

    RCC_PLLInitTypeDef PLL;     /*< PLL structure param >*/

} RCC_OscInitTypeDef;


typedef struct
{
    uint32_t ClockType;
    uint32_t SYSCLKSource;
    uint32_t AHBCLKDivider;
    uint32_t APB1CLKDivider;
    uint32_t APB2CLKDivider;

} RCC_ClkInitTypeDef;

/*--------------------------------- Macros ---------------------------------*/
/**
 * @defgroup HSE/HSI values
 */
#define HSE_VALUE                   8000000U                /*< 8.000.000 Hz >*/
#define HSE_TIMEOUT_VALUE           100U                    /*< Timeout for HSE startup, in ms >*/

#define HSI_VALUE                   ((uint32_t)16000000U)   /*< 16.000.000 Hz. Use uint32_t to make sure no issues when operating with other uint32_t values >*/
#define HSI_TIMEOUT_VALUE           2U                      /*< 2ms >*/
/**
 * @defgroup RCC_Oscillator_Type
 */
#define RCC_OSCILLATORTYPE_NONE     0x00000000U
#define RCC_OSCILLATORTYPE_HSE      0x00000001U
#define RCC_OSCILLATORTYPE_HSI      0x00000002U
#define RCC_OSCILLATORTYPE_LSE      0x00000004U
#define RCC_OSCILLATORTYPE_LSI      0x00000008U
/**
 * @defgroup RCC_HSE_Config
 */
#define RCC_HSE_OFF                 0x00000000U
#define RCC_HSE_ON                  RCC_CR_HSEON
#define RCC_HSE_BYPASS              ((uint32_t)(RCC_CR_HSEBYP | RCC_CR_HSEON))  /* Enable bypass + turn on HSE */

#define RCC_HSI_OFF                 0x00000000U
#define RCC_HSI_ON                  RCC_CR_HSION

/**
 * @defgroup RCC_FLAG
 */
#define RCC_FLAG_HSIRDY             0x00000001U
#define RCC_FLAG_HSERDY             0x00000002U
#define RCC_FLAG_PLLRDY             0x00000003U



/*-------------------------------- Checking Macros ------------------------------------*/
/**
 * @brief: Get clock source used as SYSCLK
 */
#define __HAL_RCC_GET_SYSCLK_SOURCE() (RCC->CFGR & RCC_CFGR_SWS)

/**
 * @brief: RCC_HSE Configuration
 * @note:  After enabling HSE, application shuold wait on HSERDY flag to be set 
 *         indicating that HSE clock is stable and can be used to supply PLL/System clock
 * 
 * @param: __STATE__ specifies the new state of HSE
 *          @arg RCC_HSE_OFF    : Turn off HSE Osc
 *          @arg RCC_HSE_ON     : Turn on HSE Osc
 *          @arg RCC_HSE_BYPASS : HSE Osc bypassed with the external clock (HSE Osc must be disabled first)
 */
#define __HAL_RCC_HSE_CONFIG(__STATE__)                     \
                do {                                        \
                    if (__STATE__ == RCC_HSE_ON) {          \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);     \
                    }                                       \
                    else if (__STATE__ == RCC_HSE_BYPASS) { \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);    \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);     \
                    }                                       \
                    else if (__STATE__ == RCC_HSE_OFF) {    \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);  \
                    }                                       \
                } while(0)

/**
 * @brief: Check RCC flag is set or not
 * @param: __FLAG__ specifies the flag to check
 *          @arg RCC_FLAG_HSIRDY
 *          @arg RCC_FLAG_HSERDY
 *          @arg RCC_FLAG_PLLRDY
 *          @arg RCC_FLAG_...
 */

#define __HAL_RCC_GET_FLAG(__FLAG__) \
    ((__FLAG__) == RCC_FLAG_HSIRDY ? ((RCC->CR & RCC_CR_HSIRDY) == RCC_CR_HSIRDY ? SET : RESET) : \
    ((__FLAG__) == RCC_FLAG_HSERDY ? ((RCC->CR & RCC_CR_HSERDY) == RCC_CR_HSERDY ? SET : RESET) : \
    ((__FLAG__) == RCC_FLAG_PLLRDY ? ((RCC->CR & RCC_CR_PLLRDY) == RCC_CR_PLLRDY ? SET : RESET) : RESET)))


/**
 * @brief   RCC Clock Enable
 * @note    Make some delays by reading the register -> wait for Clock to be stable.
 *          This could cost a few CPU cycles without being optimized out, better than using a loop.
 */
#define __HAL_RCC_GPIOA_CLK_ENABLE()    do { \
                                            __IO uint32_t tempreg = 0x00U; \
                                            SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN); \
                                            tempreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN); \
                                            UNUSED(tempreg); \
                                        } while(0)
#define __HAL_RCC_GPIOB_CLK_ENABLE()    do { \
                                            __IO uint32_t tempreg = 0x00U; \
                                            SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN); \
                                            tempreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN); \
                                            UNUSED(tempreg); \
                                        } while (0)
#define __HAL_RCC_GPIOC_CLK_ENABLE()    do { \
                                            __IO uint32_t tempreg = 0x00U; \
                                            SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN); \
                                            tempreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN); \
                                            UNUSED(tempreg); \
                                        } while (0)
#define __HAL_RCC_GPIOD_CLK_ENABLE()    do { \
                                            __IO uint32_t tempreg = 0x00U; \
                                            SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN); \
                                            tempreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN); \
                                            UNUSED(tempreg); \
                                        } while(0U)

/*------------------------------ HAL_RCC APIs ----------------------------------*/
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);



#ifdef __cplusplus
}
#endif

#endif // _STM32F4XX_HAL_RCC_H_