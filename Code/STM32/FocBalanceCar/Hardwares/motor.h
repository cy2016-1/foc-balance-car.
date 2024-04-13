#ifndef _MOTOR_H
#define _MOTOR_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "as5600.h"
#include "lowpass_filter.h"
#include "pid.h"

struct _motor_t;

typedef struct
{
	int id;
	int dir;
	int pole_pairs;
	int pwm_resolution;
	float voltage_limit;
	float voltage_power_supply;
}motor_user_params_t;

typedef struct _motor_t
{
	motor_user_params_t user_params;
	sensor_as5600_t as5600;
	lowpass_filter_t filter_velocity;
	pid_controller_t pid_velocity;
	
	float ua;
	float ub;
	float uc;
	
	uint32_t pwm_a;
	uint32_t pwm_b;
	uint32_t pwm_c;
	
	float vel_lpf;
	
	float zero_electric_angle;
	
	bool enable;
	
	void (*update_cb)(struct _motor_t *motor);
	void (*enable_cb)(struct _motor_t *motor);
	void (*pwm_set_cb)(struct _motor_t *motor);
}motor_typedef_t;

void motor_enable(motor_typedef_t *motor, bool state);
void motor_update(motor_typedef_t *motor);
void motor_set_torque(motor_typedef_t *motor, float uq);
void motor_align_sensor(motor_typedef_t *motor, void (*delay)(uint32_t));

#endif







