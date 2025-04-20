#ifndef _STM32F4XX_H_
#define _STM32F4XX_H_


#include "stm32f4xx_hal.h"
/* Chip should be checked here*/
#include "stm32f407xx.h"


/*****************************************************************/
/*                       Status									 */
/*****************************************************************/
typedef enum {
    RESET = 0U,
    SET = 1U,
} FlagStatus, ITStatus;

typedef enum {
    DISABLE = 0U,
    ENABLE = 1U,
} FunctionalState;

typedef enum {
    SUCCESS = 0U,
    ERROR = 1U,
} ErrorStatus;

/*****************************************************************/
/*                       Bit handling							 */
/*****************************************************************/
/* Bit operation */
#define SET_BIT(REG, BIT)       ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)     ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)      ((REG) & (BIT))
/* Register operation */
#define CLEAR_REG(REG)          ((REG) &= (0x0))
#define WRITE_REG(REG, VAL)     ((REG) & (VAL))



#endif // _STM32F4XX_H_