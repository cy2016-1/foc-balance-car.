#ifndef _USER_INC_H
#define _USER_INC_H

#include "usart.h"
#include "tim.h"
#include "i2c.h"

#include "macro.h"
#include "s_queue.h"
#include "user_config.h"

#include "system.h"
#include "motor.h"
#include "sw_i2c.h"
#include "gyroscope.h"
#include "command.h"
#include "sys_config.h"
#include "buzzer.h"


#if DEBUG_ENABLE
static inline void UART_DMA1(const char* buff)
{
	HAL_UART_Transmit_DMA(&huart1, (uint8_t*)buff, strlen(buff));
}
#else
static inline void UART_DMA1(const char* buff)
{
	
}
#endif

static inline void UART_DMA2(const char* buff)
{
	HAL_UART_Transmit_DMA(&huart2, (uint8_t*)buff, strlen(buff));
}

#endif