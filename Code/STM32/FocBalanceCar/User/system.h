#ifndef _SYSTEM_H
#define _SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <stdint.h>

void system_init(void);

uint32_t millis(void);
uint32_t micros(void);
void delayMicroseconds(uint32_t us);
void delayMs(uint32_t ms);

//static inline void delayMicroseconds(uint32_t) __attribute__((always_inline, unused));
	
#ifdef __cplusplus
}
#endif


#endif