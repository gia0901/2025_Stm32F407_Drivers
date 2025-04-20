#ifndef _STM32F4XX_HAL_GPIO_H_
#define _STM32F4XX_HAL_GPIO_H_


#include "stm32f4xx_hal_def.h"

/**
 * @brief: GPIO Init structure
 */
typedef struct
{
    uint32_t Pin;           /* refer @GPIO_pin_define*/
    uint32_t Mode;          /* refer @GPIO_mode_define*/
    uint32_t Pull;          /* refer @GPIO_pull_define */
    uint32_t Speed;         /* refer @GPIO_speed_define*/
    uint32_t Alternate;     /* refer @GPIO_alternate_define */
} GPIO_InitTypeDef;


/**
 * @brief   Bit SET & RESET
 */
typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET   = 1,
} GPIO_PinState;


/**
 * @brief   GPIO_pin_define
 */
#define GPIO_PIN_0      ((uint16_t)0x0001)  /* 0b 0000 0001 */
#define GPIO_PIN_1      ((uint16_t)0x0002)  /* 0b 0000 0010 */
#define GPIO_PIN_2      ((uint16_t)0x0004)  /* 0b 0000 0100 */
#define GPIO_PIN_3      ((uint16_t)0x0008)  /* 0b 0000 1000 */
#define GPIO_PIN_4      ((uint16_t)0x0010)  /* 0b 0001 0000 */
#define GPIO_PIN_5      ((uint16_t)0x0020)  /* 0b 0010 0000 */
#define GPIO_PIN_6      ((uint16_t)0x0040)  /* 0b 0100 0000 */
#define GPIO_PIN_7      ((uint16_t)0x0080)  /* 0b 1000 0000 */
#define GPIO_PIN_8      ((uint16_t)0x0100)  /* 0b 0000 0001 ...*/
#define GPIO_PIN_9      ((uint16_t)0x0200)  /* 0b 0000 0010 ...*/
#define GPIO_PIN_10     ((uint16_t)0x0400)  /* 0b 0000 0100 ...*/
#define GPIO_PIN_11     ((uint16_t)0x0800)  /* 0b 0000 1000 ...*/
#define GPIO_PIN_12     ((uint16_t)0x1000)  /* 0b 0001 0000 ...*/
#define GPIO_PIN_13     ((uint16_t)0x2000)  /* 0b 0010 0000 ...*/
#define GPIO_PIN_14     ((uint16_t)0x4000)  /* 0b 0100 0000 ...*/
#define GPIO_PIN_15     ((uint16_t)0x8000)  /* 0b 1000 0000 ...*/
#define GPIO_PIN_ALL    ((uint16_t)0xFFFF)  /* Selected all pins */

#define GPIO_PIN_MASK   0x0000FFFFU         /* 16-bit of pins */

/**
 * @brief       GPIO_mode_define
 *              Contains 24 bits in total:
 * @details     0-3:   Mode
 *              4-7:   Output type
 *              8-15:  Empty
 *              16-19: EXTI Mode (interrupt)
 *              20-28: Trigger Mode
 */
/* Private */
#define GPIO_MODE_Pos       0U
#define GPIO_MODE           (0x3UL << GPIO_MODE_Pos)    // 0b 11  (mode can be at max of 3 bits) 
#define MODE_INPUT          (0x0UL << GPIO_MODE_Pos)    // 0b 00
#define MODE_OUTPUT         (0x1UL << GPIO_MODE_Pos)    // 0b 01
#define MODE_AF             (0x2UL << GPIO_MODE_Pos)    // 0b 10
#define MODE_ANALOG         (0x3UL << GPIO_MODE_Pos)    // 0b 11
#define OUTPUT_TYPE_Pos     4U
#define OUTPUT_TYPE         (0x1UL << OUTPUT_TYPE_Pos)  // Output type contains 1 bit
#define OUTPUT_PP           (0x0UL << OUTPUT_TYPE_Pos)
#define OUTPUT_OD           (0x1UL << OUTPUT_TYPE_Pos)
#define EXTI_MODE_Pos       16U
/* Exported */
#define GPIO_MODE_INPUT         MODE_INPUT
#define GPIO_MODE_OUTPUT_PP     (MODE_OUTPUT | OUTPUT_PP)
#define GPIO_MODE_OUTPUT_OD     (MODE_OUTPUT | OUTPUT_OD)
#define GPIO_MODE_AF_PP         (MODE_AF | OUTPUT_PP)
#define GPIO_MODE_AF_OD         (MODE_AF | OUTPUT_OD)
#define GPIO_MODE_ANALOG        (MODE_ANALOG)


/**
 * @brief       GPIO_speed_define
 */
#define GPIO_SPEED_FREQ_LOW         0x00000000U     /* IO works at 2 MHz, refer product datasheet */
#define GPIO_SPEED_FREQ_MEDIUM      0x00000001U     /* IO works at 12,5 - 50 MHz */
#define GPIO_SPEED_FREQ_HIGH        0x00000002U     /* IO works at 25 - 100 MHz */
#define GPIO_SPEED_FREQ_VERY_HIGH   0x00000003U     /* IO works at 50 - 200 MHz */

/**
 * @brief       GPIO_pull_define
 */
#define GPIO_NOPULL     0x00000000U
#define GPIO_PULLUP     0x00000001U
#define GPIO_PULLDOWN   0x00000002U

/**
 * @brief       GPIO APIs
 */
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void HAL_GPIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);


/**
 * @brief    GPIO checking methods
 * @note     available pin -> mask -> must be != 0
 *           available pin -> in range -> mask ~MASK -> must be all 0
 */
#define IS_GPIO_PIN(PIN)    ( (((uint32_t)PIN & GPIO_PIN_MASK) != 0x00U) && (((uint32_t)PIN & ~GPIO_PIN_MASK) == 0x0U))
#define IS_GPIO_MODE(MODE)  ( ((MODE) == GPIO_MODE_INPUT)               || \
                              ((MODE) == GPIO_MODE_OUTPUT_PP)           || \
                              ((MODE) == GPIO_MODE_OUTPUT_OD)           || \
                              ((MODE) == GPIO_MODE_AF_PP)               || \
                              ((MODE) == GPIO_MODE_AF_OD)               || \
                              ((MODE) == GPIO_MODE_IT_RISING)           || \
                              ((MODE) == GPIO_MODE_IT_FALLING)          || \
                              ((MODE) == GPIO_MODE_IT_RISING_FALLING)   || \
                              ((MODE) == GPIO_MODE_ANALOG))


#endif // _STM32F4XX_HAL_GPIO_H_