#ifndef _GYROSCOPE_H
#define _GYROSCOPE_H

#include "mpu6050.h"

typedef struct
{
	float x_roll; //����� Roll  : X
	float y_pitch;  //������ Pitch : Y
	float z_yaw; //��ƫ�� Yaw   : Z
	float x_gyro; //x���ٶ�
	float y_gyro; //y���ٶ�
	float z_gyro; //z���ٶ�
	int temp;
}gyroscope_data_t;

void gyroscope_init(void);
void gyroscope_read();

extern gyroscope_data_t gyroscope_data;

#endif




