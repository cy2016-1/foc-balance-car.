#include "system.h"

void system_init()
{
	if(SysTick_Config(SystemCoreClock / 1000) == HAL_ERROR)
	{
		while(1);
	}
}

uint32_t getCurrentMillis(void)
{
  return HAL_GetTick();
}

uint32_t getCurrentMicros(void)
{
  uint32_t m0 = HAL_GetTick();
  __IO uint32_t u0 = SysTick->VAL;
  uint32_t m1 = HAL_GetTick();
  __IO uint32_t u1 = SysTick->VAL;
  const uint32_t tms = SysTick->LOAD + 1;

  if (m1 != m0) {
    return (m1 * 1000 + ((tms - u1) * 1000) / tms);
  } else {
    return (m0 * 1000 + ((tms - u0) * 1000) / tms);
  }
}

uint32_t millis(void)
{
  // ToDo: ensure no interrupts
  return getCurrentMillis();
}

uint32_t micros(void)
{
  return getCurrentMicros();
}

void delayMicroseconds(uint32_t us)
{
  //·½·¨Ò»
  __IO uint32_t currentTicks = SysTick->VAL;
  /* Number of ticks per millisecond */
 const uint32_t tickPerMs = SysTick->LOAD + 1;
  /* Number of ticks to count */
 const uint32_t nbTicks = ((us - ((us > 0) ? 1 : 0)) * tickPerMs) / 1000;
  /* Number of elapsed ticks */
 uint32_t elapsedTicks = 0;
  __IO uint32_t oldTicks = currentTicks;
 do {
    currentTicks = SysTick->VAL;
    elapsedTicks += (oldTicks < currentTicks) ? tickPerMs + oldTicks - currentTicks :
                    oldTicks - currentTicks;
    oldTicks = currentTicks;
  } while (nbTicks > elapsedTicks);
}

void delayMs(uint32_t ms)
{
	delayMicroseconds(ms * 1000);
}


