#ifndef _STM32F407XX_H_
#define _STM32F407XX_H_


/*****************************************************************/
/*                  Cortex-M4 Processor         				 */
/*****************************************************************/
/**
 * @brief   Interrupt Number definition
 */
typedef enum
{
    /*--------------- Processor Exceptions --------------*/

    /*--------------- STM32 specific interrupt numbers ------------*/
    WWDG_IRQn           = 0,    /*< Window Watchdog interrupt >*/

    RCC_IRQn            = 5,    /*< RCC global interrupt >*/
    EXTI0_IRQn          = 6,    /*< EXTI Line0 interrupt >*/
    EXTI1_IRQn          = 7,    /*< EXTI Line1 interrupt >*/
    EXTI2_IRQn          = 8,    /*< EXTI Line2 interrupt >*/
    EXTI3_IRQn          = 9,    /*< EXTI Line3 interrupt >*/
    EXTI4_IRQn          = 10,   /*< EXTI Line4 interrupt >*/
    
} IRQn_Type;


#include "core_cm4.h"
#include <stdint.h>


/*****************************************************************/
/*                  Peripheral Registers Structure				 */
/*****************************************************************/

/**
 * @brief   System Configuration Controller (SYSCFG)
 * @details - Remap the memory accessible in the code area
 *          - Select PHY interface
 *          - Manage the external interrupt line connection to the GPIOs
 */
typedef struct
{
    __IO uint32_t MEMRMP;       /*< SYSCFG Memory Remap Register >*/
    __IO uint32_t PMC;          /*< SYSCFG Peripheral Mode Register >*/
    __IO uint32_t EXTICR1;      /*< SYSCFG External Interrupt Configuration Register 1>*/
    __IO uint32_t EXTICR2;      /*< SYSCFG External Interrupt Configuration Register 2>*/
    __IO uint32_t EXTICR3;      /*< SYSCFG External Interrupt Configuration Register 3>*/
    __IO uint32_t EXTICR4;      /*< SYSCFG External Interrupt Configuration Register 4>*/
    __IO uint32_t CMPCR;        /*< SYSCFG Compenstation Cell Control Register >*/
} SYSCFG_TypeDef;

/**
 * @brief   Reset and Clock Control (RCC)
 */
typedef struct
{
    __IO uint32_t CR;           /*< RCC clock control register >*/
    __IO uint32_t PLLCFGR;      /*< RCC PLL configuration register >*/
    __IO uint32_t CFGR;         /*< RCC clock configuration register >*/
    __IO uint32_t CIR;          /*< RCC clock interrupt register >*/
    __IO uint32_t AHB1RSTR;     /*< RCC AHB1 peripheral reset register >*/
    __IO uint32_t AHB2RSTR;     /*< RCC AHB2 peripheral reset register >*/
    __IO uint32_t AHB3RSTR;     /*< RCC AHB3 peripheral reset register >*/
    uint32_t      RESERVED0;    /*< Reserved: 0x1C >*/
    __IO uint32_t APB1RSTR;     /*< RCC APB1 peripheral reset register >*/
    __IO uint32_t APB2RSTR;     /*< RCC APB2 peripheral reset register >*/
    uint32_t      RESERVED1[2]; /*< Reserved: 0x28, 0x2C >*/
    __IO uint32_t AHB1ENR;      /*< RCC AHB1 peripheral clock enable register >*/
    __IO uint32_t AHB2ENR;      /*< RCC AHB2 peripheral clock enable register >*/
    __IO uint32_t AHB3ENR;      /*< RCC AHB3 peripheral clock enable register >*/
    uint32_t      RESERVED2;    /*< Reserved: 0x3C >*/
    __IO uint32_t APB1ENR;      /*< RCC APB1 peripheral clock enable register >*/
    __IO uint32_t APB2ENR;      /*< RCC APB2 peripheral clock enable register >*/
    uint32_t      RESERVED3[2]; /*< Reserved: 0x48, 0x4C >*/
    __IO uint32_t AHB1LPENR;    /*< RCC AHB1 peripheral clock enable in LPM register >*/
    __IO uint32_t AHB2LPENR;    /*< RCC AHB2 peripheral clock enable in LPM register >*/
    __IO uint32_t AHB3LPENR;    /*< RCC AHB3 peripheral clock enable in LPM register >*/
    uint32_t      RESERVED4;    /*< Reserved: 0x5C >*/
    __IO uint32_t APB1LPENR;    /*< RCC APB1 peripheral clock enable in LPM register >*/
    __IO uint32_t APB2LPENR;    /*< RCC APB2 peripheral clock enable in LPM register >*/
    uint32_t      RESERVED5[2]; /*< Reserved: 0x68, 0x6C >*/
    __IO uint32_t BDCR;         /*< RCC Backup domain control register >*/
    __IO uint32_t CSR;          /*< RCC Clock control & Status register >*/
    uint32_t      RESERVED6[2]; /*< Reserved: 0x78, 0x7C >*/
    __IO uint32_t SSCGR;        /*< RCC Spread spectrum clock generation register >*/
    __IO uint32_t PLLI2SCFGR;   /*< RCC PLLI2S configuration register >*/
} RCC_TypeDef;

/**
 * @brief: General Purpose Input/Output (GPIO)
 */
typedef struct
{
    __IO uint32_t MODER;    /*< GPIO port mode register >*/
    __IO uint32_t OTYPER;   /*< GPIO port output type register >*/
    __IO uint32_t OSPEEDR;  /*< GPIO port output speed register >*/
    __IO uint32_t PURDR;    /*< GPIO port pull-up/down register >*/
    __IO uint32_t IDR;      /*< GPIO port input data register >*/
    __IO uint32_t ODR;      /*< GPIO port output data register >*/
    __IO uint32_t BSRR;     /*< GPIO port bit set/reset register >*/
    __IO uint32_t LCKR;     /*< GPIO configuration lock register >*/
    __IO uint32_t AFRL;     /*< GPIO alternate func low register >*/
    __IO uint32_t AFRH;     /*< GPIO alternate func high register >*/
} GPIO_TypeDef;


/**
 * @brief   External interrupt/event controller (EXTI)
 */
typedef struct
{
    __IO uint32_t IMR;      /*< EXTI Interrupt Mask Register >*/
    __IO uint32_t EMR;      /*< EXTI Event Mask Register >*/
    __IO uint32_t RTSR;     /*< EXTI Rising Trigger Selection Register >*/
    __IO uint32_t FTSR;     /*< EXTI Falling Trigger Selection Register >*/
    __IO uint32_t SWIER;    /*< EXTI Software Interrupt Event Register >*/
    __IO uint32_t PR;       /*< EXTI Pending Register >*/
} EXTI_TypeDef;

/*****************************************************************/
/*                  Peripheral Memory Map						 */
/*****************************************************************/
/**
 * @brief: Regions (512MB each, total 4GB)
 */
#define SRAM_BASE           (0x20000000UL)
#define PERIPH_BASE         (0x40000000UL)

/**
 * @brief: Peripheral memory map
 */
#define APB1PERIPH_BASE     PERIPH_BASE                     /*< APB1 is the 1st periph */
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x10050000UL)    // is it right? HAL lib says it is 0x10000000 offset
#define AHB3PERIPH_BASE     (PERIPH_BASE + 0x20000000UL)

/**
 * @brief: APB1 peripherals
 * @note:  APB1 periph offsets are under 0x10000UL, hence write 4 digits offset helps easier to look at
 */
#define TIM2_BASE           (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE           (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE           (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE           (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE           (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE           (APB1PERIPH_BASE + 0x1400UL)
#define TIM12_BASE          (APB1PERIPH_BASE + 0x1800UL)
#define TIM13_BASE          (APB1PERIPH_BASE + 0x1C00UL)
#define TIM14_BASE          (APB1PERIPH_BASE + 0x2000UL)
#define RTC_BASE            (APB1PERIPH_BASE + 0x2800UL)
#define SPI2_BASE           (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE           (APB1PERIPH_BASE + 0x3C00UL)
#define USART2_BASE         (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE         (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE          (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE          (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE           (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE           (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE           (APB1PERIPH_BASE + 0x5C00UL)
#define CAN1_BASE           (APB1PERIPH_BASE + 0x6400UL)
#define CAN2_BASE           (APB1PERIPH_BASE + 0x6800UL)
#define PWR_BASE            (APB1PERIPH_BASE + 0x7000UL)
#define DAC_BASE            (APB1PERIPH_BASE + 0x7400UL)

/**
 * @brief: APB2 peripherals
 * @note:  APB2 periph offsets are under 0x10000UL, hence write 4 digits offset helps easier to look at
 */
#define TIM1_BASE           (APB2PERIPH_BASE + 0x0000UL)
#define TIM8_BASE           (APB2PERIPH_BASE + 0x0400UL)
#define USART1_BASE         (APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE         (APB2PERIPH_BASE + 0x1400UL)
#define SDIO_BASE           (APB2PERIPH_BASE + 0x2C00UL)
#define SPI1_BASE           (APB2PERIPH_BASE + 0x3000UL)
#define SYSCFG_BASE         (APB2PERIPH_BASE + 0x3800UL)
#define EXTI_BASE           (APB2PERIPH_BASE + 0x3C00UL)
#define TIM9_BASE           (APB2PERIPH_BASE + 0x4000UL)
#define TIM10_BASE          (APB2PERIPH_BASE + 0x4400UL)
#define TIM11_BASE          (APB2PERIPH_BASE + 0x4800UL)

/**
 * @brief: AHB1 peripherals
 */
#define GPIOA_BASE          (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE          (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE          (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE          (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE          (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE          (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE          (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE          (AHB1PERIPH_BASE + 0x1C00UL)
#define GPIOI_BASE          (AHB1PERIPH_BASE + 0x2000UL)
#define CRC_BASE            (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800UL)
#define FLASH_R_BASE        (AHB1PERIPH_BASE + 0x3C00UL)
#define DMA1_BASE           (AHB1PERIPH_BASE + 0x6000UL)
#define DMA2_BASE           (AHB1PERIPH_BASE + 0x6400UL)
#define ETH_BASE            (AHB1PERIPH_BASE + 0x8000UL)    /*< Ethernet MAC base address >*/

 /**
 * @brief: AHB2 peripherals
 */

/*****************************************************************/
/*                  Peripheral Declaration						 */
/*                  (be able to dereference)				     */
/*****************************************************************/

#define GPIOA       ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB       ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC       ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD       ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE       ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF       ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG       ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH       ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI       ((GPIO_TypeDef *) GPIOI_BASE)

//#define CRC         ((CRC_TypeDef *) CRC_BASE)
#define RCC         ((RCC_TypeDef *) RCC_BASE)

#define SYSCFG      ((SYSCFG_TypeDef *) SYSCFG_BASE)

#define EXTI        ((EXTI_TypeDef *) EXTI_BASE)



/*****************************************************************/
/*                      RCC peripheral						     */
/*                      bit definition							 */
/*****************************************************************/
/*------------- Bit definition of RCC_CR register ---------------*/
#define RCC_CR_HSION_Pos                (0U)
#define RCC_CR_HSION_Msk                (0x1UL << RCC_CR_HSION_Pos)
#define RCC_CR_HSION                    RCC_CR_HSION_Msk
#define RCC_CR_HSIRDY_Pos               (1U)
#define RCC_CR_HSIRDY_Msk               (0x1UL << RCC_CR_HSIRDY_Pos)
#define RCC_CR_HSIRDY                   RCC_CR_HSIRDY_Msk

#define RCC_CR_HSITRIM_Pos              (3U)
#define RCC_CR_HSITRIM_Msk              (0x1FUL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM                  RCC_CR_HSITRIM_Msk
#define RCC_CR_HSITRIM_0                (0x01UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_1                (0x02UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_2                (0x04UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_3                (0x08UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_4                (0x10UL << RCC_CR_HSITRIM_Pos)

#define RCC_CR_HSICAL_Pos               (8U)
#define RCC_CR_HSICAL_Msk               (0xFFUL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL                   RCC_CR_HSICAL_Msk
#define RCC_CR_HSICAL_0                 (0x01UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_1                 (0x02UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_2                 (0x04UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_3                 (0x08UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_4                 (0x10UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_5                 (0x20UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_6                 (0x40UL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_7                 (0x80UL << RCC_CR_HSICAL_Pos)

#define RCC_CR_HSEON_Pos                (16U)
#define RCC_CR_HSEON_Msk                (0x1UL << RCC_CR_HSEON_Pos)
#define RCC_CR_HSEON                    RCC_CR_HSEON_Msk
#define RCC_CR_HSERDY_Pos               (17U)
#define RCC_CR_HSERDY_Msk               (0x1UL << RCC_CR_HSERDY_Pos)
#define RCC_CR_HSERDY                   RCC_CR_HSERDY_Msk
#define RCC_CR_HSEBYP_Pos               (18U)
#define RCC_CR_HSEBYP_Msk               (0x1UL << RCC_CR_HSEBYP_Pos)
#define RCC_CR_HSEBYP                   RCC_CR_HSEBYP_Msk
/* Clock-Security-System Enable */
#define RCC_CR_CSSON_Pos                (19U)
#define RCC_CR_CSSON_Msk                (0x1UL << RCC_CR_CSSON_Pos)
#define RCC_CR_CSSON                    RCC_CR_CSSON_Msk
/* Main PLL */
#define RCC_CR_PLLON_Pos                (24U)
#define RCC_CR_PLLON_Msk                (0x1UL << RCC_CR_PLLON_Pos)
#define RCC_CR_PLLON                    RCC_CR_PLLON_Msk
#define RCC_CR_PLLRDY_Pos               (25U)
#define RCC_CR_PLLRDY_Msk               (0x1UL << RCC_CR_PLLRDY_Pos)
#define RCC_CR_PLLRDY                   RCC_CR_PLLRDY_Msk

#define RCC_CR_PLLI2SON_Pos             (26U)
#define RCC_CR_PLLI2SON_Msk             (0x1UL << RCC_CR_PLLI2SON_Pos)
#define RCC_CR_PLLI2SON                 RCC_CR_PLLI2SON_Msk

/*------------- Bit definition of RCC_CFGR register ---------------*/
/* System clock switch (select system clock source: HSE, HSI, PLL)*/
#define RCC_CFGR_SW_Pos                 (0U)
#define RCC_CFGR_SW_Msk                 (0x3UL << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW                     RCC_CFGR_SW_Msk
#define RCC_CFGW_SW_0                   (0x1UL << RCC_CFGR_SW_Pos)
#define RCC_CFGW_SW_1                   (0x2UL << RCC_CFGR_SW_Pos)
/* System clock switch Status (check which Osc is used as system clock)*/
#define RCC_CFGR_SWS_Pos                (2U)
#define RCC_CFGR_SWS_Msk                (0x3UL << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS                    RCC_CFGR_SWS_Msk
#define RCC_CFGR_SWS_0                  (0x1UL << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_1                  (0x2UL << RCC_CFGR_SWS_Pos)

#define RCC_CFGR_SWS_HSI                0x00000000U     /*< HSI is used as system clock >*/
#define RCC_CFGR_SWS_HSE                0x00000004U     /*< HSE is used as system clock >*/
#define RCC_CFGR_SWS_PLL                0x00000008U     /*< PLL is used as system clock >*/

/*------------- Bit definition of RCC_PLLCFGR register ---------------*/
/* PLLM configuration */
#define RCC_PLLCFGR_PLLM_Pos            (0U)
#define RCC_PLLCFGR_PLLM_Msk            (0x3FUL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM                RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0              (0x01UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_1              (0x02UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_2              (0x04UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_3              (0x08UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_4              (0x10UL << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM_5              (0x20UL << RCC_PLLCFGR_PLLM_Pos)
/* PLLN configuration */

/* PLLP configuration */

/* PLLSRC - PLL source configuration */
#define RCC_PLLCFGR_PLLSRC_Pos          (22U)
#define RCC_PLLCFGR_PLLSRC_Msk          (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)
#define RCC_PLLCFGR_PLLSRC              RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_HSE          RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_HSI          0x00000000U
/* Bit definition of RCC_AHB1ENR  */
#define RCC_AHB1ENR_GPIOAEN_Pos             (0U)
#define RCC_AHB1ENR_GPIOAEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)
#define RCC_AHB1ENR_GPIOAEN                 RCC_AHB1ENR_GPIOAEN_Msk
#define RCC_AHB1ENR_GPIOBEN_Pos             (1U)
#define RCC_AHB1ENR_GPIOBEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)
#define RCC_AHB1ENR_GPIOBEN                 RCC_AHB1ENR_GPIOBEN_Msk
#define RCC_AHB1ENR_GPIOCEN_Pos             (2U)
#define RCC_AHB1ENR_GPIOCEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOCEN_Pos)
#define RCC_AHB1ENR_GPIOCEN                 RCC_AHB1ENR_GPIOCEN_Msk
#define RCC_AHB1ENR_GPIODEN_Pos             (3U)
#define RCC_AHB1ENR_GPIODEN_Msk             (0x1UL << RCC_AHB1ENR_GPIODEN_Pos)
#define RCC_AHB1ENR_GPIODEN                 RCC_AHB1ENR_GPIODEN_Msk
#define RCC_AHB1ENR_GPIOEEN_Pos             (4U)
#define RCC_AHB1ENR_GPIOEEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOEEN_Pos)
#define RCC_AHB1ENR_GPIOEEN                 RCC_AHB1ENR_GPIOEEN_Msk
#define RCC_AHB1ENR_GPIOFEN_Pos             (5U)
#define RCC_AHB1ENR_GPIOFEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOFEN_Pos)
#define RCC_AHB1ENR_GPIOFEN                 RCC_AHB1ENR_GPIOFEN_Msk
#define RCC_AHB1ENR_GPIOGEN_Pos             (6U)
#define RCC_AHB1ENR_GPIOGEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOGEN_Pos)
#define RCC_AHB1ENR_GPIOGEN                 RCC_AHB1ENR_GPIOGEN_Msk
#define RCC_AHB1ENR_GPIOHEN_Pos             (7U)
#define RCC_AHB1ENR_GPIOHEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOHEN_Pos)
#define RCC_AHB1ENR_GPIOHEN                 RCC_AHB1ENR_GPIOHEN_Msk
#define RCC_AHB1ENR_GPIOIEN_Pos             (8U)
#define RCC_AHB1ENR_GPIOIEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOIEN_Pos)
#define RCC_AHB1ENR_GPIOIEN                 RCC_AHB1ENR_GPIOIEN_Msk

/*****************************************************************/
/*                      GPIO peripheral						     */
/*                      bit definition							 */
/*****************************************************************/
/* Bit definition of GPIO port mode register (MODER) */
#define GPIO_MODER_MODE0_Pos            (0U)
#define GPIO_MODER_MODE0_Msk            (0x3UL << GPIO_MODER_MODE0_Pos)
#define GPIO_MODER_MODE0                GPIO_MODER_MODE0_Msk
#define GPIO_MODER_MODE1_Pos            (2U)
#define GPIO_MODER_MODE1_Msk            (0x3UL << GPIO_MODER_MODE1_Pos)
#define GPIO_MODER_MODE1                GPIO_MODER_MODE1_Msk
#define GPIO_MODER_MODE2_Pos            (4U)
#define GPIO_MODER_MODE2_Msk            (0x3UL << GPIO_MODER_MODE2_Pos)
#define GPIO_MODER_MODE2                GPIO_MODER_MODE2_Msk
#define GPIO_MODER_MODE3_Pos            (6U)
#define GPIO_MODER_MODE3_Msk            (0x3UL << GPIO_MODER_MODE3_Pos)
#define GPIO_MODER_MODE3                GPIO_MODER_MODE3_Msk
#define GPIO_MODER_MODE4_Pos            (8U)
#define GPIO_MODER_MODE4_Msk            (0x3UL << GPIO_MODER_MODE4_Pos)
#define GPIO_MODER_MODE4                GPIO_MODER_MODE4_Msk
#define GPIO_MODER_MODE5_Pos            (10U)
#define GPIO_MODER_MODE5_Msk            (0x3UL << GPIO_MODER_MODE5_Pos)
#define GPIO_MODER_MODE5                GPIO_MODER_MODE5_Msk
#define GPIO_MODER_MODE6_Pos            (12U)
#define GPIO_MODER_MODE6_Msk            (0x3UL << GPIO_MODER_MODE6_Pos)
#define GPIO_MODER_MODE6                GPIO_MODER_MODE6_Msk
#define GPIO_MODER_MODE7_Pos            (14U)
#define GPIO_MODER_MODE7_Msk            (0x3UL << GPIO_MODER_MODE7_Pos)
#define GPIO_MODER_MODE7                GPIO_MODER_MODE7_Msk
#define GPIO_MODER_MODE8_Pos            (16U)
#define GPIO_MODER_MODE8_Msk            (0x3UL << GPIO_MODER_MODE8_Pos)
#define GPIO_MODER_MODE8                GPIO_MODER_MODE8_Msk
#define GPIO_MODER_MODE9_Pos            (18U)
#define GPIO_MODER_MODE9_Msk            (0x3UL << GPIO_MODER_MODE9_Pos)
#define GPIO_MODER_MODE9                GPIO_MODER_MODE9_Msk
#define GPIO_MODER_MODE10_Pos           (20U)
#define GPIO_MODER_MODE10_Msk           (0x3UL << GPIO_MODER_MODE10_Pos)
#define GPIO_MODER_MODE10               GPIO_MODER_MODE10_Msk
#define GPIO_MODER_MODE11_Pos           (22U)
#define GPIO_MODER_MODE11_Msk           (0x3UL << GPIO_MODER_MODE11_Pos)
#define GPIO_MODER_MODE11               GPIO_MODER_MODE11_Msk
#define GPIO_MODER_MODE12_Pos           (24U)
#define GPIO_MODER_MODE12_Msk           (0x3UL << GPIO_MODER_MODE12_Pos)
#define GPIO_MODER_MODE12               GPIO_MODER_MODE12_Msk
#define GPIO_MODER_MODE13_Pos           (26U)
#define GPIO_MODER_MODE13_Msk           (0x3UL << GPIO_MODER_MODE13_Pos)
#define GPIO_MODER_MODE13               GPIO_MODER_MODE13_Msk
#define GPIO_MODER_MODE14_Pos           (28U)
#define GPIO_MODER_MODE14_Msk           (0x3UL << GPIO_MODER_MODE14_Pos)
#define GPIO_MODER_MODE14               GPIO_MODER_MODE14_Msk
#define GPIO_MODER_MODE15_Pos           (30U)
#define GPIO_MODER_MODE15_Msk           (0x3UL << GPIO_MODER_MODE15_Pos)
#define GPIO_MODER_MODE15               GPIO_MODER_MODE15_Msk
/* GPIO output type register (OTYPER) */
#define GPIO_OTYPER_OT0_Pos             (0U)
#define GPIO_OTYPER_OT0_Msk             (0x1UL << GPIO_OTYPER_OT0_Pos)
#define GPIO_OTYPER_OT0                 GPIO_OTYPER_OT0_Msk
#define GPIO_OTYPER_OT1_Pos             (1U)
#define GPIO_OTYPER_OT1_Msk             (0x1UL << GPIO_OTYPER_OT1_Pos)
#define GPIO_OTYPER_OT1                 GPIO_OTYPER_OT1_Msk
#define GPIO_OTYPER_OT2_Pos             (2U)
#define GPIO_OTYPER_OT2_Msk             (0x1UL << GPIO_OTYPER_OT2_Pos)
#define GPIO_OTYPER_OT2                 GPIO_OTYPER_OT2_Msk
#define GPIO_OTYPER_OT3_Pos             (3U)
#define GPIO_OTYPER_OT3_Msk             (0x1UL << GPIO_OTYPER_OT3_Pos)
#define GPIO_OTYPER_OT3                 GPIO_OTYPER_OT3_Msk
#define GPIO_OTYPER_OT4_Pos             (4U)
#define GPIO_OTYPER_OT4_Msk             (0x1UL << GPIO_OTYPER_OT4_Pos)
#define GPIO_OTYPER_OT4                 GPIO_OTYPER_OT4_Msk
#define GPIO_OTYPER_OT5_Pos             (5U)
#define GPIO_OTYPER_OT5_Msk             (0x1UL << GPIO_OTYPER_OT5_Pos)
#define GPIO_OTYPER_OT5                 GPIO_OTYPER_OT5_Msk
#define GPIO_OTYPER_OT6_Pos             (6U)
#define GPIO_OTYPER_OT6_Msk             (0x1UL << GPIO_OTYPER_OT6_Pos)
#define GPIO_OTYPER_OT6                 GPIO_OTYPER_OT6_Msk
#define GPIO_OTYPER_OT7_Pos             (7U)
#define GPIO_OTYPER_OT7_Msk             (0x1UL << GPIO_OTYPER_OT7_Pos)
#define GPIO_OTYPER_OT7                 GPIO_OTYPER_OT7_Msk
#define GPIO_OTYPER_OT8_Pos             (8U)
#define GPIO_OTYPER_OT8_Msk             (0x1UL << GPIO_OTYPER_OT8_Pos)
#define GPIO_OTYPER_OT8                 GPIO_OTYPER_OT8_Msk
#define GPIO_OTYPER_OT9_Pos             (9U)
#define GPIO_OTYPER_OT9_Msk             (0x1UL << GPIO_OTYPER_OT9_Pos)
#define GPIO_OTYPER_OT9                 GPIO_OTYPER_OT9_Msk
#define GPIO_OTYPER_OT10_Pos            (10U)
#define GPIO_OTYPER_OT10_Msk            (0x1UL << GPIO_OTYPER_OT10_Pos)
#define GPIO_OTYPER_OT10                GPIO_OTYPER_OT10_Msk
#define GPIO_OTYPER_OT11_Pos            (11U)
#define GPIO_OTYPER_OT11_Msk            (0x1UL << GPIO_OTYPER_OT11_Pos)
#define GPIO_OTYPER_OT11                GPIO_OTYPER_OT11_Msk
#define GPIO_OTYPER_OT12_Pos            (12U)
#define GPIO_OTYPER_OT12_Msk            (0x1UL << GPIO_OTYPER_OT12_Pos)
#define GPIO_OTYPER_OT12                GPIO_OTYPER_OT12_Msk
#define GPIO_OTYPER_OT13_Pos            (13U)
#define GPIO_OTYPER_OT13_Msk            (0x1UL << GPIO_OTYPER_OT13_Pos)
#define GPIO_OTYPER_OT13                GPIO_OTYPER_OT13_Msk
#define GPIO_OTYPER_OT14_Pos            (14U)
#define GPIO_OTYPER_OT14_Msk            (0x1UL << GPIO_OTYPER_OT14_Pos)
#define GPIO_OTYPER_OT14                GPIO_OTYPER_OT14_Msk
#define GPIO_OTYPER_OT15_Pos            (15U)
#define GPIO_OTYPER_OT15_Msk            (0x1UL << GPIO_OTYPER_OT15_Pos)
#define GPIO_OTYPER_OT15                GPIO_OTYPER_OT15_Msk
/* GPIO output type register (OSPEEDR) */
#define GPIO_OSPEEDR_OSPEEDR0_Pos 		(0U)
#define GPIO_OSPEEDR_OSPEEDR0_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR0_Pos)
#define GPIO_OSPEEDR_OSPEEDR0     		GPIO_OSPEEDR_OSPEEDR0_Msk
#define GPIO_OSPEEDR_OSPEEDR1_Pos 		(2U)
#define GPIO_OSPEEDR_OSPEEDR1_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR1_Pos)
#define GPIO_OSPEEDR_OSPEEDR1     		GPIO_OSPEEDR_OSPEEDR1_Msk
#define GPIO_OSPEEDR_OSPEEDR2_Pos 		(4U)
#define GPIO_OSPEEDR_OSPEEDR2_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR2_Pos)
#define GPIO_OSPEEDR_OSPEEDR2     		GPIO_OSPEEDR_OSPEEDR2_Msk
#define GPIO_OSPEEDR_OSPEEDR3_Pos 		(6U)
#define GPIO_OSPEEDR_OSPEEDR3_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR3_Pos)
#define GPIO_OSPEEDR_OSPEEDR3     		GPIO_OSPEEDR_OSPEEDR3_Msk
#define GPIO_OSPEEDR_OSPEEDR4_Pos 		(8U)
#define GPIO_OSPEEDR_OSPEEDR4_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR4_Pos)
#define GPIO_OSPEEDR_OSPEEDR4     		GPIO_OSPEEDR_OSPEEDR4_Msk
#define GPIO_OSPEEDR_OSPEEDR5_Pos 		(10U)
#define GPIO_OSPEEDR_OSPEEDR5_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR5_Pos)
#define GPIO_OSPEEDR_OSPEEDR5     		GPIO_OSPEEDR_OSPEEDR5_Msk
#define GPIO_OSPEEDR_OSPEEDR6_Pos 		(12U)
#define GPIO_OSPEEDR_OSPEEDR6_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR6_Pos)
#define GPIO_OSPEEDR_OSPEEDR6     		GPIO_OSPEEDR_OSPEEDR6_Msk
#define GPIO_OSPEEDR_OSPEEDR7_Pos 		(14U)
#define GPIO_OSPEEDR_OSPEEDR7_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR7_Pos)
#define GPIO_OSPEEDR_OSPEEDR7     		GPIO_OSPEEDR_OSPEEDR7_Msk
#define GPIO_OSPEEDR_OSPEEDR8_Pos 		(16U)
#define GPIO_OSPEEDR_OSPEEDR8_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR8_Pos)
#define GPIO_OSPEEDR_OSPEEDR8     		GPIO_OSPEEDR_OSPEEDR8_Msk
#define GPIO_OSPEEDR_OSPEEDR9_Pos 		(18U)
#define GPIO_OSPEEDR_OSPEEDR9_Msk 		(0x3UL << GPIO_OSPEEDR_OSPEEDR9_Pos)
#define GPIO_OSPEEDR_OSPEEDR9     		GPIO_OSPEEDR_OSPEEDR9_Msk
#define GPIO_OSPEEDR_OSPEEDR10_Pos		(20U)
#define GPIO_OSPEEDR_OSPEEDR10_Msk		(0x3UL << GPIO_OSPEEDR_OSPEEDR10_Pos)
#define GPIO_OSPEEDR_OSPEEDR10    		GPIO_OSPEEDR_OSPEEDR10_Msk
#define GPIO_OSPEEDR_OSPEEDR11_Pos		(22U)
#define GPIO_OSPEEDR_OSPEEDR11_Msk		(0x3UL << GPIO_OSPEEDR_OSPEEDR11_Pos)
#define GPIO_OSPEEDR_OSPEEDR11    		GPIO_OSPEEDR_OSPEEDR11_Msk
#define GPIO_OSPEEDR_OSPEEDR12_Pos		(24U)
#define GPIO_OSPEEDR_OSPEEDR12_Msk		(0x3UL << GPIO_OSPEEDR_OSPEEDR12_Pos)
#define GPIO_OSPEEDR_OSPEEDR12    		GPIO_OSPEEDR_OSPEEDR12_Msk
#define GPIO_OSPEEDR_OSPEEDR13_Pos		(26U)
#define GPIO_OSPEEDR_OSPEEDR13_Msk		(0x3UL << GPIO_OSPEEDR_OSPEEDR13_Pos)
#define GPIO_OSPEEDR_OSPEEDR13    		GPIO_OSPEEDR_OSPEEDR13_Msk
#define GPIO_OSPEEDR_OSPEEDR14_Pos		(28U)
#define GPIO_OSPEEDR_OSPEEDR14_Msk		(0x3UL << GPIO_OSPEEDR_OSPEEDR14_Pos)
#define GPIO_OSPEEDR_OSPEEDR14    		GPIO_OSPEEDR_OSPEEDR14_Msk
#define GPIO_OSPEEDR_OSPEEDR15_Pos		(30U)
#define GPIO_OSPEEDR_OSPEEDR15_Msk		(0x3UL << GPIO_OSPEEDR_OSPEEDR15_Pos)
#define GPIO_OSPEEDR_OSPEEDR15    		GPIO_OSPEEDR_OSPEEDR15_Msk
/* GPIO pull-up/pull-down register */
#define GPIO_PUPDR_PUPDR0_Pos            (0U)
#define GPIO_PUPDR_PUPDR0_Msk            (0x3UL << GPIO_PUPDR_PUPDR0_Pos)
#define GPIO_PUPDR_PUPDR0                GPIO_PUPDR_PUPDR0_Msk
#define GPIO_PUPDR_PUPDR1_Pos            (2U)
#define GPIO_PUPDR_PUPDR1_Msk            (0x3UL << GPIO_PUPDR_PUPDR1_Pos)
#define GPIO_PUPDR_PUPDR1                GPIO_PUPDR_PUPDR1_Msk
#define GPIO_PUPDR_PUPDR2_Pos            (4U)
#define GPIO_PUPDR_PUPDR2_Msk            (0x3UL << GPIO_PUPDR_PUPDR2_Pos)
#define GPIO_PUPDR_PUPDR2                GPIO_PUPDR_PUPDR2_Msk
#define GPIO_PUPDR_PUPDR3_Pos            (6U)
#define GPIO_PUPDR_PUPDR3_Msk            (0x3UL << GPIO_PUPDR_PUPDR3_Pos)
#define GPIO_PUPDR_PUPDR3                GPIO_PUPDR_PUPDR3_Msk
#define GPIO_PUPDR_PUPDR4_Pos            (8U)
#define GPIO_PUPDR_PUPDR4_Msk            (0x3UL << GPIO_PUPDR_PUPDR4_Pos)
#define GPIO_PUPDR_PUPDR4                GPIO_PUPDR_PUPDR4_Msk
#define GPIO_PUPDR_PUPDR5_Pos            (10U)
#define GPIO_PUPDR_PUPDR5_Msk            (0x3UL << GPIO_PUPDR_PUPDR5_Pos)
#define GPIO_PUPDR_PUPDR5                GPIO_PUPDR_PUPDR5_Msk
#define GPIO_PUPDR_PUPDR6_Pos            (12U)
#define GPIO_PUPDR_PUPDR6_Msk            (0x3UL << GPIO_PUPDR_PUPDR6_Pos)
#define GPIO_PUPDR_PUPDR6                GPIO_PUPDR_PUPDR6_Msk
#define GPIO_PUPDR_PUPDR7_Pos            (14U)
#define GPIO_PUPDR_PUPDR7_Msk            (0x3UL << GPIO_PUPDR_PUPDR7_Pos)
#define GPIO_PUPDR_PUPDR7                GPIO_PUPDR_PUPDR7_Msk
#define GPIO_PUPDR_PUPDR8_Pos            (16U)
#define GPIO_PUPDR_PUPDR8_Msk            (0x3UL << GPIO_PUPDR_PUPDR8_Pos)
#define GPIO_PUPDR_PUPDR8                GPIO_PUPDR_PUPDR8_Msk
#define GPIO_PUPDR_PUPDR9_Pos            (18U)
#define GPIO_PUPDR_PUPDR9_Msk            (0x3UL << GPIO_PUPDR_PUPDR9_Pos)
#define GPIO_PUPDR_PUPDR9                GPIO_PUPDR_PUPDR9_Msk
#define GPIO_PUPDR_PUPDR10_Pos           (20U)
#define GPIO_PUPDR_PUPDR10_Msk           (0x3UL << GPIO_PUPDR_PUPDR10_Pos)
#define GPIO_PUPDR_PUPDR10               GPIO_PUPDR_PUPDR10_Msk
#define GPIO_PUPDR_PUPDR11_Pos           (22U)
#define GPIO_PUPDR_PUPDR11_Msk           (0x3UL << GPIO_PUPDR_PUPDR11_Pos)
#define GPIO_PUPDR_PUPDR11               GPIO_PUPDR_PUPDR11_Msk
#define GPIO_PUPDR_PUPDR12_Pos           (24U)
#define GPIO_PUPDR_PUPDR12_Msk           (0x3UL << GPIO_PUPDR_PUPDR12_Pos)
#define GPIO_PUPDR_PUPDR12               GPIO_PUPDR_PUPDR12_Msk
#define GPIO_PUPDR_PUPDR13_Pos           (26U)
#define GPIO_PUPDR_PUPDR13_Msk           (0x3UL << GPIO_PUPDR_PUPDR13_Pos)
#define GPIO_PUPDR_PUPDR13               GPIO_PUPDR_PUPDR13_Msk
#define GPIO_PUPDR_PUPDR14_Pos           (28U)
#define GPIO_PUPDR_PUPDR14_Msk           (0x3UL << GPIO_PUPDR_PUPDR14_Pos)
#define GPIO_PUPDR_PUPDR14               GPIO_PUPDR_PUPDR14_Msk
#define GPIO_PUPDR_PUPDR15_Pos           (30U)
#define GPIO_PUPDR_PUPDR15_Msk           (0x3UL << GPIO_PUPDR_PUPDR15_Pos)
#define GPIO_PUPDR_PUPDR15               GPIO_PUPDR_PUPDR15_Msk
/* GPIO Input Data Register (Read-only) */
#define GPIO_IDR_IDR0_Pos             	(0U)
#define GPIO_IDR_IDR0_Msk             	(0x1UL << GPIO_IDR_IDR0_Pos)
#define GPIO_IDR_IDR0                 	GPIO_IDR_IDR0_Msk
#define GPIO_IDR_IDR1_Pos             	(1U)
#define GPIO_IDR_IDR1_Msk             	(0x1UL << GPIO_IDR_IDR1_Pos)
#define GPIO_IDR_IDR1                 	GPIO_IDR_IDR1_Msk
#define GPIO_IDR_IDR2_Pos             	(2U)
#define GPIO_IDR_IDR2_Msk             	(0x1UL << GPIO_IDR_IDR2_Pos)
#define GPIO_IDR_IDR2                 	GPIO_IDR_IDR2_Msk
#define GPIO_IDR_IDR3_Pos             	(3U)
#define GPIO_IDR_IDR3_Msk             	(0x1UL << GPIO_IDR_IDR3_Pos)
#define GPIO_IDR_IDR3                 	GPIO_IDR_IDR3_Msk
#define GPIO_IDR_IDR4_Pos             	(4U)
#define GPIO_IDR_IDR4_Msk             	(0x1UL << GPIO_IDR_IDR4_Pos)
#define GPIO_IDR_IDR4                 	GPIO_IDR_IDR4_Msk
#define GPIO_IDR_IDR5_Pos             	(5U)
#define GPIO_IDR_IDR5_Msk             	(0x1UL << GPIO_IDR_IDR5_Pos)
#define GPIO_IDR_IDR5                 	GPIO_IDR_IDR5_Msk
#define GPIO_IDR_IDR6_Pos             	(6U)
#define GPIO_IDR_IDR6_Msk             	(0x1UL << GPIO_IDR_IDR6_Pos)
#define GPIO_IDR_IDR6                 	GPIO_IDR_IDR6_Msk
#define GPIO_IDR_IDR7_Pos             	(7U)
#define GPIO_IDR_IDR7_Msk             	(0x1UL << GPIO_IDR_IDR7_Pos)
#define GPIO_IDR_IDR7                 	GPIO_IDR_IDR7_Msk
#define GPIO_IDR_IDR8_Pos             	(8U)
#define GPIO_IDR_IDR8_Msk             	(0x1UL << GPIO_IDR_IDR8_Pos)
#define GPIO_IDR_IDR8                 	GPIO_IDR_IDR8_Msk
#define GPIO_IDR_IDR9_Pos             	(9U)
#define GPIO_IDR_IDR9_Msk             	(0x1UL << GPIO_IDR_IDR9_Pos)
#define GPIO_IDR_IDR9                 	GPIO_IDR_IDR9_Msk
#define GPIO_IDR_IDR10_Pos            	(10U)
#define GPIO_IDR_IDR10_Msk            	(0x1UL << GPIO_IDR_IDR10_Pos)
#define GPIO_IDR_IDR10                	GPIO_IDR_IDR10_Msk
#define GPIO_IDR_IDR11_Pos            	(11U)
#define GPIO_IDR_IDR11_Msk            	(0x1UL << GPIO_IDR_IDR11_Pos)
#define GPIO_IDR_IDR11                	GPIO_IDR_IDR11_Msk
#define GPIO_IDR_IDR12_Pos            	(12U)
#define GPIO_IDR_IDR12_Msk            	(0x1UL << GPIO_IDR_IDR12_Pos)
#define GPIO_IDR_IDR12                	GPIO_IDR_IDR12_Msk
#define GPIO_IDR_IDR13_Pos            	(13U)
#define GPIO_IDR_IDR13_Msk            	(0x1UL << GPIO_IDR_IDR13_Pos)
#define GPIO_IDR_IDR13                	GPIO_IDR_IDR13_Msk
#define GPIO_IDR_IDR14_Pos            	(14U)
#define GPIO_IDR_IDR14_Msk            	(0x1UL << GPIO_IDR_IDR14_Pos)
#define GPIO_IDR_IDR14                	GPIO_IDR_IDR14_Msk
#define GPIO_IDR_IDR15_Pos            	(15U)
#define GPIO_IDR_IDR15_Msk            	(0x1UL << GPIO_IDR_IDR15_Pos)
#define GPIO_IDR_IDR15                	GPIO_IDR_IDR15_Msk
/* GPIO Output Data Register */
#define GPIO_ODR_ODR0_Pos             	(0U)
#define GPIO_ODR_ODR0_Msk             	(0x1UL << GPIO_ODR_ODR0_Pos)
#define GPIO_ODR_ODR0                 	GPIO_ODR_ODR0_Msk
#define GPIO_ODR_ODR1_Pos             	(1U)
#define GPIO_ODR_ODR1_Msk             	(0x1UL << GPIO_ODR_ODR1_Pos)
#define GPIO_ODR_ODR1                 	GPIO_ODR_ODR1_Msk
#define GPIO_ODR_ODR2_Pos             	(2U)
#define GPIO_ODR_ODR2_Msk             	(0x1UL << GPIO_ODR_ODR2_Pos)
#define GPIO_ODR_ODR2                 	GPIO_ODR_ODR2_Msk
#define GPIO_ODR_ODR3_Pos             	(3U)
#define GPIO_ODR_ODR3_Msk             	(0x1UL << GPIO_ODR_ODR3_Pos)
#define GPIO_ODR_ODR3                 	GPIO_ODR_ODR3_Msk
#define GPIO_ODR_ODR4_Pos             	(4U)
#define GPIO_ODR_ODR4_Msk             	(0x1UL << GPIO_ODR_ODR4_Pos)
#define GPIO_ODR_ODR4                 	GPIO_ODR_ODR4_Msk
#define GPIO_ODR_ODR5_Pos             	(5U)
#define GPIO_ODR_ODR5_Msk             	(0x1UL << GPIO_ODR_ODR5_Pos)
#define GPIO_ODR_ODR5                 	GPIO_ODR_ODR5_Msk
#define GPIO_ODR_ODR6_Pos             	(6U)
#define GPIO_ODR_ODR6_Msk             	(0x1UL << GPIO_ODR_ODR6_Pos)
#define GPIO_ODR_ODR6                 	GPIO_ODR_ODR6_Msk
#define GPIO_ODR_ODR7_Pos             	(7U)
#define GPIO_ODR_ODR7_Msk             	(0x1UL << GPIO_ODR_ODR7_Pos)
#define GPIO_ODR_ODR7                 	GPIO_ODR_ODR7_Msk
#define GPIO_ODR_ODR8_Pos             	(8U)
#define GPIO_ODR_ODR8_Msk             	(0x1UL << GPIO_ODR_ODR8_Pos)
#define GPIO_ODR_ODR8                 	GPIO_ODR_ODR8_Msk
#define GPIO_ODR_ODR9_Pos             	(9U)
#define GPIO_ODR_ODR9_Msk             	(0x1UL << GPIO_ODR_ODR9_Pos)
#define GPIO_ODR_ODR9                 	GPIO_ODR_ODR9_Msk
#define GPIO_ODR_ODR10_Pos            	(10U)
#define GPIO_ODR_ODR10_Msk            	(0x1UL << GPIO_ODR_ODR10_Pos)
#define GPIO_ODR_ODR10                	GPIO_ODR_ODR10_Msk
#define GPIO_ODR_ODR11_Pos            	(11U)
#define GPIO_ODR_ODR11_Msk            	(0x1UL << GPIO_ODR_ODR11_Pos)
#define GPIO_ODR_ODR11                	GPIO_ODR_ODR11_Msk
#define GPIO_ODR_ODR12_Pos            	(12U)
#define GPIO_ODR_ODR12_Msk            	(0x1UL << GPIO_ODR_ODR12_Pos)
#define GPIO_ODR_ODR12                	GPIO_ODR_ODR12_Msk
#define GPIO_ODR_ODR13_Pos            	(13U)
#define GPIO_ODR_ODR13_Msk            	(0x1UL << GPIO_ODR_ODR13_Pos)
#define GPIO_ODR_ODR13                	GPIO_ODR_ODR13_Msk
#define GPIO_ODR_ODR14_Pos            	(14U)
#define GPIO_ODR_ODR14_Msk            	(0x1UL << GPIO_ODR_ODR14_Pos)
#define GPIO_ODR_ODR14                	GPIO_ODR_ODR14_Msk
#define GPIO_ODR_ODR15_Pos            	(15U)
#define GPIO_ODR_ODR15_Msk            	(0x1UL << GPIO_ODR_ODR15_Pos)
#define GPIO_ODR_ODR15                	GPIO_ODR_ODR15_Msk


/*****************************************************************/
/*                      Useful Macros							 */
/*****************************************************************/
/**
 * @brief: check GPIO instance
 */
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOD) || \
                                        ((INSTANCE) == GPIOE) || \
                                        ((INSTANCE) == GPIOF) || \
                                        ((INSTANCE) == GPIOG) || \
                                        ((INSTANCE) == GPIOH) || \
                                        ((INSTANCE) == GPIOI))


#endif // _STM32F407XX_H_
