#include "motor.h"
#include "macro.h"
#include "arm_math.h"

float _normalize_angle(float angle){
  float a = fmodf(angle, 2.0f*_PI);   //取余运算可以用于归一化，列出特殊值例子算便知
  return a >= 0 ? a : (a + 2.0f*_PI);
}

float _electrical_angle(motor_typedef_t *motor) {
	return _normalize_angle(((float)(motor->user_params.dir * motor->user_params.pole_pairs) * as5600_get_mechanical_angle(&motor->as5600) )- motor->zero_electric_angle);
}

void set_pwm(motor_typedef_t* motor, float ua, float ub, float uc) {
	float dc_a, dc_b, dc_c;
	
	// 限制上限
	ua = _constrain(ua, 0.0f, motor->user_params.voltage_limit);
	ub = _constrain(ub, 0.0f, motor->user_params.voltage_limit);
	uc = _constrain(uc, 0.0f, motor->user_params.voltage_limit);
	// 计算占空比
	// 限制占空比从0到1
	dc_a = _constrain(ua / motor->user_params.voltage_power_supply, 0.0f , 1.0f );
	dc_b = _constrain(ub / motor->user_params.voltage_power_supply, 0.0f , 1.0f );
	dc_c = _constrain(uc / motor->user_params.voltage_power_supply, 0.0f , 1.0f );

	//写入PWM到PWM 0 1 2 通道
	motor->pwm_a = (uint32_t) roundf(dc_a * motor->user_params.pwm_resolution);
	motor->pwm_b = (uint32_t) roundf(dc_b * motor->user_params.pwm_resolution);
	motor->pwm_c = (uint32_t) roundf(dc_c * motor->user_params.pwm_resolution);
	
	if(motor->pwm_set_cb != NULL)
		motor->pwm_set_cb(motor);

}

void set_phase_voltage(motor_typedef_t* motor, float uq, float angle_el) {
	float32_t sq3_in = 3.0f;
	float32_t sq3_out = 0.0f;
	arm_sqrt_f32(sq3_in, &sq3_out);
	
  // 帕克逆变换
  float u_alpha =  -uq * arm_sin_f32(angle_el);
  float u_beta =   uq * arm_cos_f32(angle_el);

  // 克拉克逆变换
  motor->ua	= u_alpha + motor->user_params.voltage_power_supply/2;
  motor->ub = (sq3_out * u_beta - u_alpha)/2 + motor->user_params.voltage_power_supply/2;
  motor->uc	= (-u_alpha - sq3_out * u_beta)/2 + motor->user_params.voltage_power_supply/2;
	
  set_pwm(motor, motor->ua,motor->ub,motor->uc);
}

void set_phase_voltage_svpwm(motor_typedef_t* motor, float uq, float angle_el)
{	
  if (uq < 0){
	  angle_el += _PI;
		uq = fabsf(uq);
  }
	
  angle_el =  _normalize_angle (angle_el + _PI_2);
  int sector = floorf(angle_el / _PI_3) + 1;
	
  // calculate the duty cycles
	float T1 = _SQRT3 * arm_sin_f32(sector * _PI_3 - angle_el) * uq / motor->user_params.voltage_power_supply;
	float T2 = _SQRT3 * arm_sin_f32(angle_el - (sector - 1.0f) * _PI_3) * uq / motor->user_params.voltage_power_supply;
	float T0 = 1 - T1 - T2;
	
	float Ta, Tb, Tc;
	switch (sector)
	{
	case 1:
		Ta = T1 + T2 + T0 / 2;
		Tb = T2 + T0 / 2;
		Tc = T0 / 2;
		break;
	case 2:
		Ta = T1 + T0 / 2;
		Tb = T1 + T2 + T0 / 2;
		Tc = T0 / 2;
		break;
	case 3:
		Ta = T0 / 2;
		Tb = T1 + T2 + T0 / 2;
		Tc = T2 + T0 / 2;
		break;
	case 4:
		Ta = T0 / 2;
		Tb = T1 + T0 / 2;
		Tc = T1 + T2 + T0 / 2;
		break;
	case 5:
		Ta = T2 + T0 / 2;
		Tb = T0 / 2;
		Tc = T1 + T2 + T0 / 2;
		break;
	case 6:
		Ta = T1 + T2 + T0 / 2;
		Tb = T0 / 2;
		Tc = T1 + T0 / 2;
		break;
	default:
		Ta = 0;
		Tb = 0;
		Tc = 0;
	}
	
	// 克拉克逆变换
	motor->ua = Ta * motor->user_params.voltage_power_supply;
	motor->ub = Tb * motor->user_params.voltage_power_supply;
	motor->uc = Tc * motor->user_params.voltage_power_supply;
	
	set_pwm(motor, motor->ua,motor->ub,motor->uc);
}

void motor_set_torque(motor_typedef_t *motor, float uq)
{
	set_phase_voltage_svpwm(motor, uq, _electrical_angle(motor));
//	set_phase_voltage(motor, uq, _electrical_angle(motor));
}

void motor_align_sensor(motor_typedef_t *motor, void (*delay)(uint32_t))
{
	if(NULL != delay)
	{
		set_phase_voltage_svpwm(motor, 3, _3PI_2);
		delay(1000);
	}
	motor->update_cb(motor);
	motor->zero_electric_angle = _electrical_angle(motor);
	set_phase_voltage_svpwm(motor, 0, _3PI_2);
}

void motor_enable(motor_typedef_t *motor, bool state)
{
	motor->enable = state;
	if(NULL != motor->enable_cb)
	{
		motor->enable_cb(motor);
	}
}

void motor_update(motor_typedef_t *motor)
{
	if(NULL != motor->update_cb)
	{
		motor->update_cb(motor);
		
		float vel = as5600_get_velocity(&motor->as5600) * motor->user_params.dir;
		motor->vel_lpf = lowpass_filter_operator(vel, &motor->filter_velocity);
		
		motor->as5600.velocity = motor->vel_lpf;;
	}
}




