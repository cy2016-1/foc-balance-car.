#include "gyroscope.h"

gyroscope_data_t gyroscope_data;

void gyroscope_init()
{
//	__disable_irq();
	
	if(MPU6050_testConnection())
	{
		DEBUG_P("mpu6050 find\n");
		MPU6050_initialize();
		DMP_Init();
	}
	else
	{
		DEBUG_P("mpu6050 not find\n");
	}

//	__enable_irq();
}

void gyroscope_read()
{
//	gyroscope_data.temp = Read_Temperature();
	Read_DMP(&gyroscope_data.y_pitch,&gyroscope_data.x_roll,&gyroscope_data.z_yaw);
	gyroscope_data.x_gyro = gyro[0] / 32.8f;
	gyroscope_data.y_gyro = gyro[1] / 32.8f;
	gyroscope_data.z_gyro = gyro[2] / 32.8f;
}








