#ifndef _AS5600_H
#define _AS5600_H

#include <stdint.h>
#include <math.h>
#include "macro.h"

#define SENSOR_AS5600_ADDR (0x36 << 1)
#define SENSOR_AS5600_ANGLE_REG 0x0C

struct _sensor_as5600_t;

typedef struct _sensor_as5600_t
{
	uint8_t data_h;
	uint8_t data_l;
	double angle; //传感器当前角度值
	float velocity;
	float angle_prev; //传感器角度累加值，用于计算完整的圈数和速度
	long angle_prev_ts; //上一次读取角度的时间戳
	float vel_angle_prev; //最后一次读取速度时的角度值
	long vel_angle_prev_ts; //最后一次速度计算时间戳
	int32_t full_rotations; //总圈数计数
	int32_t vel_full_rotations; //用于速度计算的完整圈数
}sensor_as5600_t;

void as5600_calc_angle(sensor_as5600_t *sensor);
void as5600_update(sensor_as5600_t *sensor);
float as5600_get_mechanical_angle(sensor_as5600_t *sensor);
float as5600_get_angle(sensor_as5600_t *sensor);
float as5600_get_velocity(sensor_as5600_t *sensor);

#endif