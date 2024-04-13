#ifndef _SYS_CONFIG_H
#define _SYS_CONFIG_H

#include <stdint.h>
#include <string.h>
#include <math.h>

#include "stm32f4xx_hal.h"
#include "flash_store.h"

typedef struct
{
	uint8_t dev_id[4]; //…Ë±∏ID
	float pid_vel[3]; //PID
	float pid_stand[3];
	float pid_turn[3];
}sys_config_t;

void sys_config_init(void);
void sys_config_read(void);
void sys_config_write(void);
void sys_config_reset(void);

#endif