/*
 * WCH CH5xx Timer Alias Helper
 *
 * Easily switch between timers and their corresponding GPIO pins.
 *
 * This header file maps TMR[A-D] to TMR[0-3] during compilation, no runtime
 * overhead is added. The static mapping can be defined in the head of the program.
 *
 *          Pin    Alt. Pin
 *
 * TMR0     PA9      PB23
 * TMR1     PA10     PB10     (DMA)
 * TMR2     PA11     PB11     (DMA)
 * TMR3     PB22     PA2
 *
 * Example usage:
 *
 * // select timer 0 to 3
 * #define TMRA_TARGET 3
 * // leave out or set to FALSE for default pin
 * #define TMRA_ALT_PIN TRUE
 * // header file has to be included last
 * #include "timer_alias.h"
 *
 * In your application you can do now:
 *
 * // resolves to nothing if remapping is not required
 * TMRA_GPIO_MaybePinRemap();
 *
 * TMRA_GPIO_ModeCfg(GPIO_ModeOut_PP_5mA);
 * TMRA_GPIO_SetBit()
 * TMRA_GPIO_ResetBit()
 * TMRA_PFIC_EnableIRQ()
 * TMRA_PFIC_DisableIRQ()
 *
 * All other (timer specific) functions resemble exactly the original, for example:
 *
 * TMRA_CAPTimeoutCfg(FREQ_SYS / 1000);
 * TMRA_ITCfg(ENABLE, TMR0_3_IT_DATA_ACT | TMR0_3_IT_CYC_END);
 * TMRA_CapInit(Edge_To_Edge);
 * uint32_t tick = TMRA_GetCurrentTimer();
 * void TMRA_IRQHandler(void) {}
 *
 * June 2023        Steffen Beyer <steffen@beyer.io>
 *                  Initial release
 *
 * License: BSD 3-Clause
 * GitHub: https://github.com/serpent213/ch5xx_timer_alias/
 *
 */

#ifndef __CH5xx_TIMER_ALIAS_H__
#define __CH5xx_TIMER_ALIAS_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TMRA_TARGET
    #define TMRA_TARGET 0
#endif
#ifndef TMRB_TARGET
    #define TMRB_TARGET 1
#endif
#ifndef TMRC_TARGET
    #define TMRC_TARGET 2
#endif
#ifndef TMRD_TARGET
    #define TMRD_TARGET 3
#endif

#if TMRA_TARGET == 0
    #if TMRA_ALT_PIN == TRUE
        #define TMRA_GPIO_BANK B
        #define TMRA_GPIO_PIN 23
    #else
        #define TMRA_GPIO_BANK A
        #define TMRA_GPIO_PIN 9
    #endif
#endif
#if TMRA_TARGET == 1
    #if TMRA_ALT_PIN == TRUE
        #define TMRA_GPIO_BANK B
        #define TMRA_GPIO_PIN 10
    #else
        #define TMRA_GPIO_BANK A
        #define TMRA_GPIO_PIN 10
    #endif
#endif
#if TMRA_TARGET == 2
    #if TMRA_ALT_PIN == TRUE
        #define TMRA_GPIO_BANK B
        #define TMRA_GPIO_PIN 11
    #else
        #define TMRA_GPIO_BANK A
        #define TMRA_GPIO_PIN 11
    #endif
#endif
#if TMRA_TARGET == 3
    #if TMRA_ALT_PIN == TRUE
        #define TMRA_GPIO_BANK A
        #define TMRA_GPIO_PIN 2
    #else
        #define TMRA_GPIO_BANK B
        #define TMRA_GPIO_PIN 22
    #endif
#endif

#if TMRB_TARGET == 0
    #if TMRB_ALT_PIN == TRUE
        #define TMRB_GPIO_BANK B
        #define TMRB_GPIO_PIN 23
    #else
        #define TMRB_GPIO_BANK A
        #define TMRB_GPIO_PIN 9
    #endif
#endif
#if TMRB_TARGET == 1
    #if TMRB_ALT_PIN == TRUE
        #define TMRB_GPIO_BANK B
        #define TMRB_GPIO_PIN 10
    #else
        #define TMRB_GPIO_BANK A
        #define TMRB_GPIO_PIN 10
    #endif
#endif
#if TMRB_TARGET == 2
    #if TMRB_ALT_PIN == TRUE
        #define TMRB_GPIO_BANK B
        #define TMRB_GPIO_PIN 11
    #else
        #define TMRB_GPIO_BANK A
        #define TMRB_GPIO_PIN 11
    #endif
#endif
#if TMRB_TARGET == 3
    #if TMRB_ALT_PIN == TRUE
        #define TMRB_GPIO_BANK A
        #define TMRB_GPIO_PIN 2
    #else
        #define TMRB_GPIO_BANK B
        #define TMRB_GPIO_PIN 22
    #endif
#endif

#if TMRC_TARGET == 0
    #if TMRC_ALT_PIN == TRUE
        #define TMRC_GPIO_BANK B
        #define TMRC_GPIO_PIN 23
    #else
        #define TMRC_GPIO_BANK A
        #define TMRC_GPIO_PIN 9
    #endif
#endif
#if TMRC_TARGET == 1
    #if TMRC_ALT_PIN == TRUE
        #define TMRC_GPIO_BANK B
        #define TMRC_GPIO_PIN 10
    #else
        #define TMRC_GPIO_BANK A
        #define TMRC_GPIO_PIN 10
    #endif
#endif
#if TMRC_TARGET == 2
    #if TMRC_ALT_PIN == TRUE
        #define TMRC_GPIO_BANK B
        #define TMRC_GPIO_PIN 11
    #else
        #define TMRC_GPIO_BANK A
        #define TMRC_GPIO_PIN 11
    #endif
#endif
#if TMRC_TARGET == 3
    #if TMRC_ALT_PIN == TRUE
        #define TMRC_GPIO_BANK A
        #define TMRC_GPIO_PIN 2
    #else
        #define TMRC_GPIO_BANK B
        #define TMRC_GPIO_PIN 22
    #endif
#endif

#if TMRD_TARGET == 0
    #if TMRD_ALT_PIN == TRUE
        #define TMRD_GPIO_BANK B
        #define TMRD_GPIO_PIN 23
    #else
        #define TMRD_GPIO_BANK A
        #define TMRD_GPIO_PIN 9
    #endif
#endif
#if TMRD_TARGET == 1
    #if TMRD_ALT_PIN == TRUE
        #define TMRD_GPIO_BANK B
        #define TMRD_GPIO_PIN 10
    #else
        #define TMRD_GPIO_BANK A
        #define TMRD_GPIO_PIN 10
    #endif
#endif
#if TMRD_TARGET == 2
    #if TMRD_ALT_PIN == TRUE
        #define TMRD_GPIO_BANK B
        #define TMRD_GPIO_PIN 11
    #else
        #define TMRD_GPIO_BANK A
        #define TMRD_GPIO_PIN 11
    #endif
#endif
#if TMRD_TARGET == 3
    #if TMRD_ALT_PIN == TRUE
        #define TMRD_GPIO_BANK A
        #define TMRD_GPIO_PIN 2
    #else
        #define TMRD_GPIO_BANK B
        #define TMRD_GPIO_PIN 22
    #endif
#endif

// nesting required for proper macro expansion
#define TA_STR(s) #s
#define TA_STR_STR(s) TA_STR(s)
#define _TA_CONCAT(x, y) x ## y
#define TA_CONCAT(x, y) _TA_CONCAT(x, y)
#define _TA_CONCAT3(x, y, z) x ## y ## z
#define TA_CONCAT3(x, y, z) _TA_CONCAT3(x, y, z)

#define TMRA_PIN_NAME TA_STR_STR(TA_CONCAT3(P, TMRA_GPIO_BANK, TMRA_GPIO_PIN))
#define TMRB_PIN_NAME TA_STR_STR(TA_CONCAT3(P, TMRB_GPIO_BANK, TMRB_GPIO_PIN))
#define TMRC_PIN_NAME TA_STR_STR(TA_CONCAT3(P, TMRC_GPIO_BANK, TMRC_GPIO_PIN))
#define TMRD_PIN_NAME TA_STR_STR(TA_CONCAT3(P, TMRD_GPIO_BANK, TMRD_GPIO_PIN))

#if TMRA_ALT_PIN == TRUE
    #define TMRA_GPIO_MaybePinRemap() GPIOPinRemap(ENABLE, TA_CONCAT(RB_PIN_TMR, TMRA_TARGET))
#else
    #define TMRA_GPIO_MaybePinRemap()
#endif
#if TMRB_ALT_PIN == TRUE
    #define TMRB_GPIO_MaybePinRemap() GPIOPinRemap(ENABLE, TA_CONCAT(RB_PIN_TMR, TMRB_TARGET))
#else
    #define TMRB_GPIO_MaybePinRemap()
#endif
#if TMRC_ALT_PIN == TRUE
    #define TMRC_GPIO_MaybePinRemap() GPIOPinRemap(ENABLE, TA_CONCAT(RB_PIN_TMR, TMRC_TARGET))
#else
    #define TMRC_GPIO_MaybePinRemap()
#endif
#if TMRD_ALT_PIN == TRUE
    #define TMRD_GPIO_MaybePinRemap() GPIOPinRemap(ENABLE, TA_CONCAT(RB_PIN_TMR, TMRD_TARGET))
#else
    #define TMRD_GPIO_MaybePinRemap()
#endif

#define TMRA_GPIO_ModeCfg(ARG1) TA_CONCAT3(GPIO, TMRA_GPIO_BANK, _ModeCfg)(TA_CONCAT(GPIO_Pin_, TMRA_GPIO_PIN), ARG1)
#define TMRA_GPIO_SetBit() TA_CONCAT3(GPIO, TMRA_GPIO_BANK, _SetBits)(TA_CONCAT(GPIO_Pin_, TMRA_GPIO_PIN))
#define TMRA_GPIO_ResetBit() TA_CONCAT3(GPIO, TMRA_GPIO_BANK, _ResetBits)(TA_CONCAT(GPIO_Pin_, TMRA_GPIO_PIN))

#define TMRA_Enable TA_CONCAT3(TMR, TMRA_TARGET, _Enable)
#define TMRA_Disable TA_CONCAT3(TMR, TMRA_TARGET, _Disable)
#define TMRA_TimerInit TA_CONCAT3(TMR, TMRA_TARGET, _TimerInit)
#define TMRA_GetCurrentCount TA_CONCAT3(TMR, TMRA_TARGET, _GetCurrentCount)
#define TMRA_GetCurrentTimer TA_CONCAT3(TMR, TMRA_TARGET, _GetCurrentTimer)
#define TMRA_CountOverflowCfg TA_CONCAT3(TMR, TMRA_TARGET, _CountOverflowCfg)
#define TMRA_EXTSingleCounterInit TA_CONCAT3(TMR, TMRA_TARGET, _EXTSingleCounterInit)
#define TMRA_DMACfg TA_CONCAT3(TMR, TMRA_TARGET, _DMACfg)

#define TMRA_CapInit TA_CONCAT3(TMR, TMRA_TARGET, _CapInit)
#define TMRA_CAPTimeoutCfg TA_CONCAT3(TMR, TMRA_TARGET, _CAPTimeoutCfg)
#define TMRA_CAPGetData TA_CONCAT3(TMR, TMRA_TARGET, _CAPGetData)
#define TMRA_CAPDataCounter TA_CONCAT3(TMR, TMRA_TARGET, _CAPDataCounter)

#define TMRA_PWMInit TA_CONCAT3(TMR, TMRA_TARGET, _PWMInit)
#define TMRA_PWMCycleCfg TA_CONCAT3(TMR, TMRA_TARGET, _PWMCycleCfg)
#define TMRA_PWMActDataWidth TA_CONCAT3(TMR, TMRA_TARGET, _PWMActDataWidth)

#define TMRA_ITCfg TA_CONCAT3(TMR, TMRA_TARGET, _ITCfg)
#define TMRA_GetITFlag TA_CONCAT3(TMR, TMRA_TARGET, _GetITFlag)
#define TMRA_ClearITFlag TA_CONCAT3(TMR, TMRA_TARGET, _ClearITFlag)
#define TMRA_PFIC_EnableIRQ() PFIC_EnableIRQ(TA_CONCAT3(TMR, TMRA_TARGET, _IRQn))
#define TMRA_PFIC_DisableIRQ() PFIC_DisableIRQ(TA_CONCAT3(TMR, TMRA_TARGET, _IRQn))
#define TMRA_IRQHandler TA_CONCAT3(TMR, TMRA_TARGET, _IRQHandler)

#define TMRB_GPIO_ModeCfg(ARG1) TA_CONCAT3(GPIO, TMRB_GPIO_BANK, _ModeCfg)(TA_CONCAT(GPIO_Pin_, TMRB_GPIO_PIN), ARG1)
#define TMRB_GPIO_SetBit() TA_CONCAT3(GPIO, TMRB_GPIO_BANK, _SetBits)(TA_CONCAT(GPIO_Pin_, TMRB_GPIO_PIN))
#define TMRB_GPIO_ResetBit() TA_CONCAT3(GPIO, TMRB_GPIO_BANK, _ResetBits)(TA_CONCAT(GPIO_Pin_, TMRB_GPIO_PIN))

#define TMRB_Enable TA_CONCAT3(TMR, TMRB_TARGET, _Enable)
#define TMRB_Disable TA_CONCAT3(TMR, TMRB_TARGET, _Disable)
#define TMRB_TimerInit TA_CONCAT3(TMR, TMRB_TARGET, _TimerInit)
#define TMRB_GetCurrentCount TA_CONCAT3(TMR, TMRB_TARGET, _GetCurrentCount)
#define TMRB_GetCurrentTimer TA_CONCAT3(TMR, TMRB_TARGET, _GetCurrentTimer)
#define TMRB_CountOverflowCfg TA_CONCAT3(TMR, TMRB_TARGET, _CountOverflowCfg)
#define TMRB_EXTSingleCounterInit TA_CONCAT3(TMR, TMRB_TARGET, _EXTSingleCounterInit)
#define TMRB_DMACfg TA_CONCAT3(TMR, TMRB_TARGET, _DMACfg)

#define TMRB_CapInit TA_CONCAT3(TMR, TMRB_TARGET, _CapInit)
#define TMRB_CAPTimeoutCfg TA_CONCAT3(TMR, TMRB_TARGET, _CAPTimeoutCfg)
#define TMRB_CAPGetData TA_CONCAT3(TMR, TMRB_TARGET, _CAPGetData)
#define TMRB_CAPDataCounter TA_CONCAT3(TMR, TMRB_TARGET, _CAPDataCounter)

#define TMRB_PWMInit TA_CONCAT3(TMR, TMRB_TARGET, _PWMInit)
#define TMRB_PWMCycleCfg TA_CONCAT3(TMR, TMRB_TARGET, _PWMCycleCfg)
#define TMRB_PWMActDataWidth TA_CONCAT3(TMR, TMRB_TARGET, _PWMActDataWidth)

#define TMRB_ITCfg TA_CONCAT3(TMR, TMRB_TARGET, _ITCfg)
#define TMRB_GetITFlag TA_CONCAT3(TMR, TMRB_TARGET, _GetITFlag)
#define TMRB_ClearITFlag TA_CONCAT3(TMR, TMRB_TARGET, _ClearITFlag)
#define TMRB_PFIC_EnableIRQ() PFIC_EnableIRQ(TA_CONCAT3(TMR, TMRB_TARGET, _IRQn))
#define TMRB_PFIC_DisableIRQ() PFIC_DisableIRQ(TA_CONCAT3(TMR, TMRB_TARGET, _IRQn))
#define TMRB_IRQHandler TA_CONCAT3(TMR, TMRB_TARGET, _IRQHandler)

#define TMRC_GPIO_ModeCfg(ARG1) TA_CONCAT3(GPIO, TMRC_GPIO_BANK, _ModeCfg)(TA_CONCAT(GPIO_Pin_, TMRC_GPIO_PIN), ARG1)
#define TMRC_GPIO_SetBit() TA_CONCAT3(GPIO, TMRC_GPIO_BANK, _SetBits)(TA_CONCAT(GPIO_Pin_, TMRC_GPIO_PIN))
#define TMRC_GPIO_ResetBit() TA_CONCAT3(GPIO, TMRC_GPIO_BANK, _ResetBits)(TA_CONCAT(GPIO_Pin_, TMRC_GPIO_PIN))

#define TMRC_Enable TA_CONCAT3(TMR, TMRC_TARGET, _Enable)
#define TMRC_Disable TA_CONCAT3(TMR, TMRC_TARGET, _Disable)
#define TMRC_TimerInit TA_CONCAT3(TMR, TMRC_TARGET, _TimerInit)
#define TMRC_GetCurrentCount TA_CONCAT3(TMR, TMRC_TARGET, _GetCurrentCount)
#define TMRC_GetCurrentTimer TA_CONCAT3(TMR, TMRC_TARGET, _GetCurrentTimer)
#define TMRC_CountOverflowCfg TA_CONCAT3(TMR, TMRC_TARGET, _CountOverflowCfg)
#define TMRC_EXTSingleCounterInit TA_CONCAT3(TMR, TMRC_TARGET, _EXTSingleCounterInit)
#define TMRC_DMACfg TA_CONCAT3(TMR, TMRC_TARGET, _DMACfg)

#define TMRC_CapInit TA_CONCAT3(TMR, TMRC_TARGET, _CapInit)
#define TMRC_CAPTimeoutCfg TA_CONCAT3(TMR, TMRC_TARGET, _CAPTimeoutCfg)
#define TMRC_CAPGetData TA_CONCAT3(TMR, TMRC_TARGET, _CAPGetData)
#define TMRC_CAPDataCounter TA_CONCAT3(TMR, TMRC_TARGET, _CAPDataCounter)

#define TMRC_PWMInit TA_CONCAT3(TMR, TMRC_TARGET, _PWMInit)
#define TMRC_PWMCycleCfg TA_CONCAT3(TMR, TMRC_TARGET, _PWMCycleCfg)
#define TMRC_PWMActDataWidth TA_CONCAT3(TMR, TMRC_TARGET, _PWMActDataWidth)

#define TMRC_ITCfg TA_CONCAT3(TMR, TMRC_TARGET, _ITCfg)
#define TMRC_GetITFlag TA_CONCAT3(TMR, TMRC_TARGET, _GetITFlag)
#define TMRC_ClearITFlag TA_CONCAT3(TMR, TMRC_TARGET, _ClearITFlag)
#define TMRC_PFIC_EnableIRQ() PFIC_EnableIRQ(TA_CONCAT3(TMR, TMRC_TARGET, _IRQn))
#define TMRC_PFIC_DisableIRQ() PFIC_DisableIRQ(TA_CONCAT3(TMR, TMRC_TARGET, _IRQn))
#define TMRC_IRQHandler TA_CONCAT3(TMR, TMRC_TARGET, _IRQHandler)

#define TMRD_GPIO_ModeCfg(ARG1) TA_CONCAT3(GPIO, TMRD_GPIO_BANK, _ModeCfg)(TA_CONCAT(GPIO_Pin_, TMRD_GPIO_PIN), ARG1)
#define TMRD_GPIO_SetBit() TA_CONCAT3(GPIO, TMRD_GPIO_BANK, _SetBits)(TA_CONCAT(GPIO_Pin_, TMRD_GPIO_PIN))
#define TMRD_GPIO_ResetBit() TA_CONCAT3(GPIO, TMRD_GPIO_BANK, _ResetBits)(TA_CONCAT(GPIO_Pin_, TMRD_GPIO_PIN))

#define TMRD_Enable TA_CONCAT3(TMR, TMRD_TARGET, _Enable)
#define TMRD_Disable TA_CONCAT3(TMR, TMRD_TARGET, _Disable)
#define TMRD_TimerInit TA_CONCAT3(TMR, TMRD_TARGET, _TimerInit)
#define TMRD_GetCurrentCount TA_CONCAT3(TMR, TMRD_TARGET, _GetCurrentCount)
#define TMRD_GetCurrentTimer TA_CONCAT3(TMR, TMRD_TARGET, _GetCurrentTimer)
#define TMRD_CountOverflowCfg TA_CONCAT3(TMR, TMRD_TARGET, _CountOverflowCfg)
#define TMRD_EXTSingleCounterInit TA_CONCAT3(TMR, TMRD_TARGET, _EXTSingleCounterInit)
#define TMRD_DMACfg TA_CONCAT3(TMR, TMRD_TARGET, _DMACfg)

#define TMRD_CapInit TA_CONCAT3(TMR, TMRD_TARGET, _CapInit)
#define TMRD_CAPTimeoutCfg TA_CONCAT3(TMR, TMRD_TARGET, _CAPTimeoutCfg)
#define TMRD_CAPGetData TA_CONCAT3(TMR, TMRD_TARGET, _CAPGetData)
#define TMRD_CAPDataCounter TA_CONCAT3(TMR, TMRD_TARGET, _CAPDataCounter)

#define TMRD_PWMInit TA_CONCAT3(TMR, TMRD_TARGET, _PWMInit)
#define TMRD_PWMCycleCfg TA_CONCAT3(TMR, TMRD_TARGET, _PWMCycleCfg)
#define TMRD_PWMActDataWidth TA_CONCAT3(TMR, TMRD_TARGET, _PWMActDataWidth)

#define TMRD_ITCfg TA_CONCAT3(TMR, TMRD_TARGET, _ITCfg)
#define TMRD_GetITFlag TA_CONCAT3(TMR, TMRD_TARGET, _GetITFlag)
#define TMRD_ClearITFlag TA_CONCAT3(TMR, TMRD_TARGET, _ClearITFlag)
#define TMRD_PFIC_EnableIRQ() PFIC_EnableIRQ(TA_CONCAT3(TMR, TMRD_TARGET, _IRQn))
#define TMRD_PFIC_DisableIRQ() PFIC_DisableIRQ(TA_CONCAT3(TMR, TMRD_TARGET, _IRQn))
#define TMRD_IRQHandler TA_CONCAT3(TMR, TMRD_TARGET, _IRQHandler)

#ifdef __cplusplus
}
#endif

#endif // __CH5xx_TIMER_ALIAS_H__
