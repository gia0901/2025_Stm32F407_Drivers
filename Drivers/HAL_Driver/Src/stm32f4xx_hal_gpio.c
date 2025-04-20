#include "stm32f4xx_hal.h"

/**
 * @brief: Private macros
 */
#define GPIO_NUMBER     16U

/**
 * @brief: Initializes GPIOx peripheral according to the params of GPIO_Init
 */
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
    uint32_t position;
    uint32_t ioposition;
    uint32_t iocurrent = 0x00U;
    uint32_t temp = 0x00U;

    /* Check params */
    // assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
    // assert_param(IS_GPIO_PIN(GPIO_Init->Pin));
    // assert_param(IS_GPIO_MODE(GPIO_Init->Mode));
    /* Use a loop to be able to setup multiple pins (if user adds more than 1 pin in GPIO_Init)*/
    for (position = 0U; position < GPIO_NUMBER; position++)
    {
        /* Get IO (pin) position */
        ioposition = 0x01U << position;
        iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;

        /* current position is also the pin needed to be set(iocurrent) */
        if (iocurrent == ioposition)
        {
            /* OUTPUT attributes (Alternate could be output also, so add it into the condition) */
            if ((GPIO_Init->Mode & GPIO_MODE) == MODE_OUTPUT || \
                (GPIO_Init->Mode & GPIO_MODE) == MODE_AF)
            {
                /* Configure IO speed */
                //assert_param(IS_GPIO_SPEED(GPIO_Init->Speed));
                temp = GPIOx->OSPEEDR;
                temp &= ~(GPIO_OSPEEDR_OSPEEDR0_Msk << (position*2U));  /* Clear 2 position bits. It's good to use OSPEEDR0 instead of hardcoding */
                temp |= (GPIO_Init->Speed << (position*2U));
                GPIOx->OSPEEDR = temp;

                /* Configure IO output type (we're in output mode now)*/
                temp = GPIOx->OTYPER;
                temp &= ~(GPIO_OTYPER_OT0 << position);
                temp |= ((GPIO_Init->Mode & OUTPUT_TYPE) >> OUTPUT_TYPE_Pos) << position; /* Mask out output_type from Mode variable -> shift back to 0 pos before actually set OTYPER */
                GPIOx->OTYPER = temp;
            }
            /* Configure Pull resistors when mode is NOT analog (RM - pg. 281)*/
            if ((GPIO_Init->Mode & GPIO_MODE) != MODE_ANALOG)
            {
                //assert_param(IS_GPIO_PULL(GPIO_Init->Pull));
                temp = GPIOx->PURDR;
                temp &= (GPIO_PUPDR_PUPDR0 << (position*2U));
                temp |= (GPIO_Init->Pull << (position*2U));
                GPIOx->PURDR = temp;
            }
            /* Configure Alternate Mode */
            if ((GPIO_Init->Mode & GPIO_MODE) == MODE_AF)
            {
                //assert_param(IS_GPIO_AF(GPIO_Init->Alternate))

            }
            /* Configure MODE register */
            temp = GPIOx->MODER;
            temp &= ~(GPIO_MODER_MODE0 << (position * 2U));
            temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2U)); /* GPIO_MODE_Pos = 0 -> no shift */
            GPIOx->MODER = temp;

            /*----------------------- EXTI Mode (interrupt) configuration ---------------------------*/

        }
    }
}

void HAL_GPIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{

}

/**
 * @brief   Read data port ibt
 * @param   GPIOx - x is the port (A...I)
 * @param   GPIO_Pin - specifies port bit to be written
 * @retval  Input port pin value
 */
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    GPIO_PinState bit_status;

    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET) /* We can't know the exact value if using '==', so using '!= RESET' is the best way */
        bit_status = GPIO_PIN_SET;
    else
        bit_status = GPIO_PIN_RESET;
    
    return bit_status;
}

/**
 * @brief   Set/clear data port bit
 * @note    This function uses GPIOx_BSRR to allow atomic read/modify access.
 *          In this way, there is no risk of an IRQ occuring between the read & modify access.
 *          This is a better way than modifying GPIOx_ODR (RM - pg. 286)
 * @param   GPIOx - x is the port (A...I)
 * @param   GPIO_Pin - specifies port bit to be written
 * @param   PinState - specifies value to be written:
 *                      + GPIO_PIN_RESET: clear the port pin
 *                      + GPIO_PIN_SET: set the port pin
 * @retval  None
 */
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    //assert_param(IS_GPIO_PIN(GPIO_Pin));

    if (PinState != GPIO_PIN_RESET)
        GPIOx->BSRR = GPIO_Pin;
    else
        GPIOx->BSRR = ((uint32_t)GPIO_Pin << 16U);    /* Reset bit (BRx) starts from 16th bit*/
}

/**
 * @brief   Toggle the specified GPIO pin
 * @note    Only output pin can be toggled!!!
 * @param   GPIOx - x is the port (A...I)
 * @param   GPIO_Pin - specifies port pin to be toggled
 * @retval  None
 */
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    uint32_t odr;
    uint32_t reset_state, set_state;
    //assert_param(IS_GPIO_PIN(GPIO_Pin));

    /* Check ODR, and reverse the state in BSRR (for atomic modify access)*/
    odr = GPIOx->ODR;

    /*  When it is    1 -> reset_state = 1 -> Pin will be reset in BSRR
        else if it is 0 -> reset_state = 0 -> Write 0 won't affect anything (RM - pg. 287).*/
    reset_state = ((odr & GPIO_Pin) << 16U);

    /*  If current pin state = OFF (0) -> ~ODR & Pin = (1 << Pin) 
           current pin state = ON  (1) -> ~ODR & Pin = (0 << Pin)

        When it    is 0 -> set_state = 1 -> Pin will be turned ON
        else if it is 1 -> set_state = 0 -> Write 0 won't affect anything (RM - pg. 287). */
    set_state = (~odr & GPIO_Pin);

    /* Combine 2 methods above we can toggle the pin */
    GPIOx->BSRR = reset_state | set_state;
}

HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{

    return 0;
}

void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin)
{

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}