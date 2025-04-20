#include "main.h"

void Error_Handler();
void SystemClock_Config(void);
void Simple_Delay(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_SPI1_Init(void);


int main(void)
{
    //HAL_Init();
    
    SystemClock_Config();

    MX_GPIO_Init();
    MX_I2C1_Init();
    MX_SPI1_Init();

    while (1)
    {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
        Simple_Delay();
    }
}

void SystemClock_Config(void)
{
    // RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    // RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    // /* Configure Power Clock (for standby, sleep,...)*/
    // __HAL_RCC_PWR_CLK_ENABLE();
    // __HAL_RCC_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    // /* Configure Oscillator */
    // RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    // RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    // if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    //    Error_Handler();
    // }

    
}
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable GPIO clocks */
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /* Configure LED pin: PD12 - PD13 - PD14 - PD15 .*/
    GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}
static void MX_I2C1_Init(void)
{
    
}
static void MX_SPI1_Init(void)
{
    
}

void Error_Handler()
{
    while(1) {

    }
}

/**
 * @brief   0.5 second Simple Delay (based on Default SYSCLK)
 * @note    Default SYSCLK is HSI (16 MHz) -> Each CPU cycle costs (1/16.000.000) seconds.
 * 
 *          cycle_time = 62,5ns
 *          500.000 loops = 0.5s
 *          -> 0.5s / 62.5ns ~= 8.000.000 CPU cycles cost 0.5s
 */
void Simple_Delay(void)
{
    for (int i = 0; i < 500000U; i++) {

    }
}