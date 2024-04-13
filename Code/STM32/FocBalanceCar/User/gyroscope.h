#ifndef _GYROSCOPE_H
#define _GYROSCOPE_H

#include "mpu6050.h"

typedef struct
{
	float x_roll; //ºá¹ö½Ç Roll  : X
	float y_pitch;  //¸©Ñö½Ç Pitch : Y
	float z_yaw; //º½Æ«½Ç Yaw   : Z
	float x_gyro; //x½ÇËÙ¶È
	float y_gyro; //y½ÇËÙ¶È
	float z_gyro; //z½ÇËÙ¶È
	int temp;
}gyroscope_data_t;

void gyroscope_init(void);
void gyroscope_read();

extern gyroscope_data_t gyroscope_data;

#endif




