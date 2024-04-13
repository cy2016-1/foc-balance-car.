#include "as5600.h"

void as5600_calc_angle(sensor_as5600_t *sensor)
{
	uint16_t read_value = 0;
	
  int _bit_resolution=12;
  int _bits_used_msb=11-7;
  float cpr = pow(2, _bit_resolution);
  int lsb_used = _bit_resolution - _bits_used_msb;

  uint8_t lsb_mask = (uint8_t)( (2 << lsb_used) - 1 );
  uint8_t msb_mask = (uint8_t)( (2 << _bits_used_msb) - 1 );
	
	read_value = (sensor->data_l & lsb_mask);
	read_value += ((sensor->data_h & msb_mask) << lsb_used);
	
	sensor->angle = (read_value / (float)cpr) * _2PI;
}

/**
 * 角度传感器数据更新
 * 调用此函数前，应先获取传感器当前角度以及读取角度时的时间戳
 */
void as5600_update(sensor_as5600_t *sensor)
{
	as5600_calc_angle(sensor);
	
	float d_angle = sensor->angle - sensor->angle_prev;
	if(fabsf(d_angle) > (0.8f * _2PI))
		sensor->full_rotations += (d_angle > 0) ? -1 : 1;
	sensor->angle_prev = sensor->angle;
}

float as5600_get_mechanical_angle(sensor_as5600_t *sensor)
{
	return sensor->angle_prev;
}

float as5600_get_angle(sensor_as5600_t *sensor)
{
	return (float)sensor->full_rotations * _2PI + sensor->angle_prev;
}

float as5600_get_velocity(sensor_as5600_t *sensor)
{
	//计算采样时间
//	float ts = (sensor->angle_prev_ts - sensor->vel_angle_prev_ts) * 1e-6f;
	//溢出修复
//	if(ts <= 0) ts = 1e-3f;
	
	float ts = 5e-3f;
	
	//速度计算
	sensor->velocity = ( (float)(sensor->full_rotations - sensor->vel_full_rotations)*_2PI + (sensor->angle_prev - sensor->vel_angle_prev) ) / ts;
	//变量记录
	sensor->vel_angle_prev = sensor->angle_prev;
	sensor->vel_full_rotations = sensor->full_rotations;
	sensor->vel_angle_prev_ts = sensor->angle_prev_ts;
	
	return sensor->velocity;
}