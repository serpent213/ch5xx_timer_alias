# WCH CH5xx Timer Alias Helper
 
## Easily switch between timers and their corresponding GPIO pins

This header file maps TMR[A-D] to TMR[0-3] during compilation, no runtime
overhead is added. The static mapping can be defined in the head of the program.
 
|      | Pin  | Alt. Pin |       |
| ---- | ---- | -------- | ----- |
| TMR0 | PA9  | PB23     |       |
| TMR1 | PA10 | PB10     | (DMA) |
| TMR2 | PA11 | PB11     | (DMA) |
| TMR3 | PB22 | PA2      |       |
 
Copy the [`timer_alias.h`](https://raw.githubusercontent.com/serpent213/ch5xx_timer_alias/master/timer_alias.h)
file to your source folder or include directory.

### Example usage:

```c
// select a timer (0 to 3)
#define TMRA_TARGET 3
// leave out or set to FALSE for default pin
#define TMRA_ALT_PIN TRUE
// header file has to be included last
#include "timer_alias.h"
```

In your application you can do now:
   
```c
// resolves to nothing if remapping is not required
TMRA_GPIO_MaybePinRemap();

TMRA_GPIO_ModeCfg(GPIO_ModeOut_PP_5mA);
TMRA_GPIO_SetBit();
TMRA_GPIO_ResetBit();
TMRA_PFIC_EnableIRQ();
TMRA_PFIC_DisableIRQ();
printf("timer pin: " TMRA_PIN_NAME);
```
   
All other (timer specific) functions resemble exactly the original, just replacing
TMR[0-3] with TMR[A-D]. For example:
   
```c
TMRA_CAPTimeoutCfg(FREQ_SYS / 1000);
TMRA_ITCfg(ENABLE, TMR0_3_IT_DATA_ACT | TMR0_3_IT_CYC_END);
TMRA_CapInit(Edge_To_Edge);
uint32_t tick = TMRA_GetCurrentTimer();
```

Interrupt handlers are supported, so

```c
#define TMRC_TARGET 2
#include "timer_alias.h"

void TMRC_IRQHandler(void)
{
  if (TMRC_GetITFlag(TMR0_3_IT_DATA_ACT)) {
    TMRC_ClearITFlag(TMR0_3_IT_DATA_ACT);
  }
}
```

becomes

```c
void TMR2_IRQHandler(void)
{
  if (TMR2_GetITFlag(TMR0_3_IT_DATA_ACT)) {
    TMR2_ClearITFlag(TMR0_3_IT_DATA_ACT);
  }
}
```

and then


```c
void TMR2_IRQHandler(void)
{
  if (((*((PUINT8V)0x40002806)) & 0x02)) {
    ((*((PUINT8V)0x40002806)) = 0x02);
  }
}
```
