#include "pid.h"

float pid_operator(float error, pid_controller_t* pid){
//	float Ts = (pid->timestamp_now - pid->timestamp_prev) * 1e-6f;
	float Ts = 5e-3f;
	// P��
	float proportional = pid->P * error;
	// Tustin ɢ����֣�I����
	float integral = pid->integral_prev + pid->I*Ts*0.5f*(error + pid->error_prev);
	integral = _constrain(integral, -pid->limit, pid->limit);
	// D����΢�ֻ��ڣ�
	float derivative = pid->D*(error - pid->error_prev)/Ts;

	// ��P,I,D�����ļ���ֵ������
	float output = proportional + integral + derivative;
	output = _constrain(output, -pid->limit, pid->limit);

	if(pid->output_ramp > 0){
		// ��PID�ı仯���ʽ�������
		float output_rate = (output - pid->output_prev)/Ts;
		if (output_rate > pid->output_ramp)
			output = pid->output_prev + pid->output_ramp*Ts;
		else if (output_rate < -pid->output_ramp)
			output = pid->output_prev - pid->output_ramp*Ts;
	}
	// ����ֵ��Ϊ����һ��ѭ����
	pid->integral_prev = integral;
	pid->output_prev = output;
	pid->error_prev = error;
	
	pid->timestamp_prev = pid->timestamp_now;
	
	return output;
}