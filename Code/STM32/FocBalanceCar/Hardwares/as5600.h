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
	double angle; //��������ǰ�Ƕ�ֵ
	float velocity;
	float angle_prev; //�������Ƕ��ۼ�ֵ�����ڼ���������Ȧ�����ٶ�
	long angle_prev_ts; //��һ�ζ�ȡ�Ƕȵ�ʱ���
	float vel_angle_prev; //���һ�ζ�ȡ�ٶ�ʱ�ĽǶ�ֵ
	long vel_angle_prev_ts; //���һ���ٶȼ���ʱ���
	int32_t full_rotations; //��Ȧ������
	int32_t vel_full_rotations; //�����ٶȼ��������Ȧ��
}sensor_as5600_t;

void as5600_calc_angle(sensor_as5600_t *sensor);
void as5600_update(sensor_as5600_t *sensor);
float as5600_get_mechanical_angle(sensor_as5600_t *sensor);
float as5600_get_angle(sensor_as5600_t *sensor);
float as5600_get_velocity(sensor_as5600_t *sensor);

#endif