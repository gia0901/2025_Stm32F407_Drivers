#ifndef _STM32F4XX_HAL_CONF_H_
#define _STM32F4XX_HAL_CONF_H_

#ifdef __cplusplus
 extern "C" {
#endif





#ifdef USE_FULL_ASSERT
    //#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t*)__FILE__, __LINE__))
#else
    #define assert_param(expr) ((void)0U)   /* do nothing */
#endif

#ifdef __cplusplus
}
#endif

#endif // _STM32F4XX_HAL_CONF_H_
