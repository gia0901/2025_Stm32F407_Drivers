#ifndef _CORE_CM4_H_
#define _CORE_CM4_H_

#include <stdint.h>


/**
 * @brief: IO definitions
 */
#define __I     volatile const  /*< read-only */
#define __O     volatile        /*< write-only */
#define __IO    volatile        /*< read/write */

#define __ASM           _asm
#define __INLINE        inline
#define __STATIC_INLINE static inline


/**
 * @brief   CMSIS_NVIC Nested Vectored Interrupt Controller
 */
typedef struct
{
    __IO uint32_t ISER[8U];         /*< 0xE100-0xE11C Interrupt Set-enable Register >*/
    uint32_t      RESERVED0[24U];   /*< 0xE120-0xE17F Reserved = (0x007F - 0x0020 + 1) = 96 bytes>*/
    __IO uint32_t ICER[8U];         /*< 0xE180-0xE19C Interrupt Clear-enable Register >*/
    uint32_t      RESERVED1[24U];   /*< 0xE1A0-0xE1FF Reserved = (1FF - 1A0 + 1) = 96 bytes */
    __IO uint32_t ISPR[8U];         /*< 0xE200-0xE21C Interrupt Set-pending Register >*/
    uint32_t      RESERVED2[24U];   /*< 0xE220-0xE27F */
    __IO uint32_t ICPR[8U];         /*< 0xE280-0xE29C Interrupt Clear-pending Register >*/
    uint32_t      RESERVED3[24U];   /*< 0xE2A0-0xE2FF>*/
    __IO uint32_t IABR[8U];         /*< 0xE300-0xE31C Interrupt Active Bit Register >*/
    // check the rest later
} NVIC_Type;


typedef struct
{

} SCB_Type;


typedef struct
{
    __IO uint32_t CTRL;      /*< SysTick Control and Status register >*/
    __IO uint32_t LOAD;      /*< Reload Value register >*/
    __IO uint32_t VAL;       /*< Current Value register >*/
    __I  uint32_t CALIB;     /*< Calibration Value register >*/
} SysTick_Type;



/*----------------------- Memory mapping of Core Hardware -----------------------*/

#define SysTick_BASE    (0xE000E010UL)
#define NVIC_BASE       (0xE000E100UL)
#define SCB_BASE        (0xE000ED00UL)  // is it right?????

#define SCB             ((SCB_Type      *)SCB_BASE)         /*< System Control Block >*/
#define SysTick         ((SysTick_Type  *)SysTick_BASE)
#define NVIC            ((NVIC_Type     *)NVIC_BASE)

/* SysTick Control and Status */
#define SysTick_CTRL_ENABLE_Pos     0U
#define SysTick_CTRL_ENABLE_Msk     (0x1UL << SysTick_CTRL_ENABLE_Pos)

#define SysTick_CTRL_TICKINT_Pos    1U
#define SysTick_CTRL_TICKINT_Msk    (0x1UL << SysTick_CTRL_TICKINT_Pos)

#define SysTick_CTRL_CLKSOURCE_Pos  2U
#define SysTick_CTRL_CLKSOURCE_Msk  (0x1UL << SysTick_CTRL_CLKSOURCE_Pos)

#define SysTick_CTRL_COUNTFLAG_Pos  16U
#define SysTick_CTRL_COUNTFLAG_Msk  (0x1UL << SysTick_CTRL_COUNTFLAG_Pos)

/* SysTick Reload Value  */
#define SysTick_LOAD_RELOAD_Pos     0U
#define SysTick_LOAD_RELOAD_Msk     (0xFFFFFFUL << SysTick_LOAD_RELOAD_Pos) /*< 3 bytes >*/






/*----------------------- Inline functions -----------------------*/
/**
 * @brief   Enable interrupt which is corresponding to input IRQ number
 */
__STATIC_INLINE void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
    
}

/**
 * @brief System Tick configuration
 */
__STATIC_INLINE uint32_t SysTick_Config(uint32_t ticks)
{
    return 0;
}

#endif // _CORE_CM4_H_