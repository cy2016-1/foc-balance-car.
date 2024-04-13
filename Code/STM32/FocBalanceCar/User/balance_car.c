#include "balance_car.h"

/**************************************
左侧电机:
TIM1 -- CH1,CH2,CH3
EN -- PB8
IA1 -- PA1 -- ADC1_IN1
IA3 -- PA4 -- ADC1_IN4

右侧电机:
TIM3 -- CH1,CH2,CH3
EN -- PB2
IA1 -- PA5 -- ADC1_IN5
IA3 -- PB1 -- ADC1_IN9

左侧编码器:
I2C1

右侧编码器:
I2C2

陀螺仪MPU6050:
SCL -- PB14
SDA -- PB15
INT -- PB4

SWD下载口:
CLK -- PA14
DIO -- PA13

调试串口1:
TX -- PA15
RX -- PB3

同ESP32通讯串口2:
TX -- PA2
RX -- PA3

3.7V锂电池电量检测:
PA0

有源蜂鸣器:
PB13

未使用电流采样!!!
***************************************/

#define VELOCITY_UPDATE_STEP 10.0f

enum
{
	MOTOR_L = 1,
	MOTOR_R,
};

void motor_pwm_setcallback(motor_typedef_t *motor);
void motor_update_callback(motor_typedef_t *motor);
void motor_enable_callback(motor_typedef_t *motor);

void command_recv_callback(command_typedef_t *command);
void command_load_callback(command_typedef_t *command);
void command_upload_callback(command_typedef_t *command);

s_queue_t squeue_log, squeue_command;
uint32_t t_millis;

const float offset_parameters = 1.8f;
float car_target_velocity = 0.0f;
float car_target_steering = 0.0f;
float motor_l_output, motor_r_output;
bool run_flag;

volatile char uart1_recv_data, uart2_recv_data;

command_typedef_t command_recv_data = {
	.load_cb = command_load_callback,
	.recv_cb = command_recv_callback,
	.upload_cb = command_upload_callback,
};

motor_typedef_t motor_l = {
	.user_params = {
		.id = MOTOR_L,
		.dir = -1,
		.pole_pairs = 7,
		.pwm_resolution = 2500,
		.voltage_limit = 6.5,
		.voltage_power_supply = 12.6,
	},
	.filter_velocity = {
		.tf = 0.07,
	},
	.enable_cb = motor_enable_callback,
	.update_cb = motor_update_callback,
	.pwm_set_cb = motor_pwm_setcallback,
};

motor_typedef_t motor_r = {
	.user_params = {
		.id = MOTOR_R,
		.dir = 1,
		.pole_pairs = 7,
		.pwm_resolution = 2500,
		.voltage_limit = 6.5,
		.voltage_power_supply = 12.6,
	},
	.filter_velocity = {
		.tf = 0.07,
	},
	.enable_cb = motor_enable_callback,
	.update_cb = motor_update_callback,
	.pwm_set_cb = motor_pwm_setcallback,
};

pid_controller_t pid_vel = {
	.P = DEF_PID_VEL_P,
	.I = DEF_PID_VEL_I,
	.D = DEF_PID_VEL_D,
	.output_ramp=10000,
	.limit=6.5,
};

pid_controller_t pid_stand = {
	.P = DEF_PID_STAND_P,
	.I = DEF_PID_STAND_I,
	.D = DEF_PID_STAND_D,
	.output_ramp=10000,
	.limit=6.5,
};

pid_controller_t pid_turn = {
	.P = DEF_PID_TURN_P,
	.I = DEF_PID_TURN_I,
	.D = DEF_PID_TURN_D,
};

void motor_pwm_setcallback(motor_typedef_t *motor)
{
	if(motor->user_params.id == MOTOR_L)
	{
		TIM1->CCR1 = motor->pwm_a;
		TIM1->CCR2 = motor->pwm_b;
		TIM1->CCR3 = motor->pwm_c;
	}
	else if(motor->user_params.id == MOTOR_R)
	{
		TIM3->CCR1 = motor->pwm_a;
		TIM3->CCR2 = motor->pwm_c;
		TIM3->CCR3 = motor->pwm_b;
	}
}

void motor_update_callback(motor_typedef_t *motor)
{
	uint8_t angle_buff[2];
	
	if(motor->user_params.id == MOTOR_L)
	{
		HAL_I2C_Mem_Read(&hi2c1, SENSOR_AS5600_ADDR, SENSOR_AS5600_ANGLE_REG, I2C_MEMADD_SIZE_8BIT, angle_buff, 2, 100);
	}
	else if(motor->user_params.id == MOTOR_R)
	{
		HAL_I2C_Mem_Read(&hi2c2, SENSOR_AS5600_ADDR, SENSOR_AS5600_ANGLE_REG, I2C_MEMADD_SIZE_8BIT, angle_buff, 2, 100);
	}
	
	if(motor->user_params.id == MOTOR_L || motor->user_params.id == MOTOR_R)
	{
		motor->as5600.data_h = angle_buff[0];
		motor->as5600.data_l = angle_buff[1];
		
		as5600_update(&motor->as5600);
	}

}

void motor_enable_callback(motor_typedef_t *motor)
{
	if(motor->user_params.id == MOTOR_L)
	{
		if(motor->enable)
		{
			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
		}
		else
		{
			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
		}
		
		HAL_GPIO_WritePin(EN_ML_GPIO_Port, EN_ML_Pin, motor->enable ? GPIO_PIN_SET : GPIO_PIN_RESET);
	}
	else if(motor->user_params.id == MOTOR_R)
	{
		if(motor->enable)
		{
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		}
		else
		{
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
		}
		
		HAL_GPIO_WritePin(EN_MR_GPIO_Port, EN_MR_Pin, motor->enable ? GPIO_PIN_SET : GPIO_PIN_RESET);
	}
}

void command_load_callback(command_typedef_t *command)
{
	command->vel = car_target_velocity;
	command->steering = car_target_steering;
	
	memcpy(&command->pid_velocity, &pid_vel, sizeof(pid_controller_t));
	memcpy(&command->pid_stand, &pid_stand, sizeof(pid_controller_t));
	memcpy(&command->pid_turn, &pid_turn, sizeof(pid_controller_t));
}

void command_recv_callback(command_typedef_t *command)
{
	car_target_velocity = command->vel;
	car_target_steering = command->steering;
	
	memcpy(&pid_vel, &command->pid_velocity, sizeof(pid_controller_t));
	memcpy(&pid_stand, &command->pid_stand, sizeof(pid_controller_t));
	memcpy(&pid_turn, &command->pid_turn, sizeof(pid_controller_t));
	
	//重置PID
	if(command->set_type == COMMAND_SET_PID_RESET)
	{
		pid_vel.P = DEF_PID_VEL_P;
		pid_vel.I = DEF_PID_VEL_I;
		pid_vel.D = DEF_PID_VEL_D;
		
		pid_stand.P = DEF_PID_STAND_P;
		pid_stand.I = DEF_PID_STAND_I;
		pid_stand.D = DEF_PID_STAND_D;
		
		pid_turn.P = DEF_PID_TURN_P;
		pid_turn.I = DEF_PID_TURN_I;
		pid_turn.D = DEF_PID_TURN_D;
	}
	
	//保存PID
	if(command->set_type == COMMAND_SET_PID_SAVE)
	{
		
	}
}

void command_upload_callback(command_typedef_t *command)
{
	squeue_in_printf(&squeue_log, "comand upload\n");
	if(command->upload_type == COMMAND_UPLOAD_PID)
	{
		squeue_in_printf(&squeue_command, 
										"P %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n",
										pid_vel.P, pid_vel.I, pid_vel.D,
										pid_stand.P, pid_stand.I, pid_stand.D,
										pid_turn.P, pid_turn.I, pid_turn.D);
	}
	else if(command->upload_type == COMMAND_UPLOAD_GYROSCOPE)
	{
		squeue_in_printf(&squeue_command, 
										"G %.3f %.3f %.3f %.3f %.3f %.3f\n",
										gyroscope_data.x_roll, gyroscope_data.y_pitch, gyroscope_data.z_yaw,
										gyroscope_data.x_gyro, gyroscope_data.y_gyro, gyroscope_data.z_gyro);
	}
	else if(command->upload_type == COMMAND_UPLOAD_VEL)
	{
		squeue_in_printf(&squeue_command, "V %.2f\n", car_target_velocity);
	}
	else if(command->upload_type == COMMAND_UPLOAD_STEERING)
	{
		squeue_in_printf(&squeue_command, "T %.2f\n", car_target_steering);
	}
}

void uart_logout(s_queue_t *sq, void(*dma_handle)(const char*))
{
	static uint32_t t_millis = 0;
	static char buff[QUEUE_DATA_SIZE];
	
	if(squeue_get_length(sq) <= 0)
		return;
	
	if(millis() - t_millis > 20)
	{
		t_millis = millis();
	
		memset(buff, '\0', sizeof(buff));
		squeue_out(sq, buff);
		dma_handle(buff);
	}

}

void balance_keep_update()
{
	float vel_aver = (motor_l.vel_lpf + motor_r.vel_lpf) / 2.0f;
	float angle_target_pitch = pid_operator((car_target_velocity - vel_aver) * 180.0f / _PI, &pid_vel);
	
//	angle_target_pitch = 0;
	
	float output = pid_stand.P * (offset_parameters - gyroscope_data.x_roll - angle_target_pitch) + pid_stand.D * gyroscope_data.x_gyro;
	
	float output_turn = car_target_steering != 0 ? pid_turn.P * car_target_steering : pid_turn.D * gyroscope_data.z_gyro;
	
	motor_l_output = output + output_turn;
	motor_r_output = output - output_turn;
	
}

void state_detect()
{
	if(gyroscope_data.x_roll > 40 || gyroscope_data.x_roll < -40)
	{
		if(run_flag)
		{
			run_flag = false;
			motor_enable(&motor_l, run_flag);
			motor_enable(&motor_r, run_flag);
		}
	}
	else
	{
		if(!run_flag)
		{
			run_flag = true;
			motor_enable(&motor_l, run_flag);
			motor_enable(&motor_r, run_flag);
		}
	}
}

void balance_car_init()
{
	/* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
  #endif

	//时钟初始化
	system_init();
	squeue_init(&squeue_log);	
	
	//版本信息
	LOG_INFO("%s Power On!\n", APP_NAME);
	LOG_INFO("%s\n", FIRMWARE_VER_STR);
	LOG_INFO("^_^ Welcome! ^_^\r\n\r\n");
	
	//配置存储初始化
	sys_config_init();
	
	//I2C初始化
	IIC_Init();
	
	//陀螺仪初始化
	gyroscope_init();
	
	//电机使能
	motor_enable(&motor_l, true);
	motor_enable(&motor_r, true);
	
	//电机校准
	motor_align_sensor(&motor_l, HAL_Delay);
	motor_align_sensor(&motor_r, HAL_Delay);
	
	t_millis = millis();
	
	//定时器初始化
	HAL_TIM_Base_Start_IT(&htim10);	
	HAL_TIM_Base_Start_IT(&htim11);	
	
	//串口接收中断
	HAL_UART_Receive_IT(&huart1, (uint8_t*)&uart1_recv_data, 1);
	HAL_UART_Receive_IT(&huart2, (uint8_t*)&uart2_recv_data, 1);
	
	run_flag = true;
	buzzer_on();
	HAL_Delay(150);
	buzzer_off();
	HAL_Delay(50);
}

void balance_car_run()
{
	state_detect();	
	
	if(run_flag)
	{
		motor_set_torque(&motor_l, motor_l_output);
		motor_set_torque(&motor_r, motor_r_output);
	}
	
#if 0
	if(millis() - t_millis > 1000)
	{
		t_millis = millis();
		squeue_in_printf(&squeue_log, "angleL, angleR: %.3f, %.3f\n", as5600_get_angle(&motor_l.as5600), as5600_get_angle(&motor_r.as5600));
		squeue_in_printf(&squeue_log, "vel_l, vel_r: %.3f, %.3f\n", motor_l.as5600.velocity, motor_r.as5600.velocity);
		squeue_in_printf(&squeue_log, "x,y,z: %.3f, %.3f, %.3f\n", gyroscope_data.x_roll, gyroscope_data.y_pitch, gyroscope_data.z_yaw);
		squeue_in_printf(&squeue_log, "wx,wy,wz: %.3f, %.3f, %.3f\n", gyroscope_data.x_gyro, gyroscope_data.y_gyro, gyroscope_data.z_gyro);
	}
#endif
	
	uart_command_process(&command_recv_data);
	uart_logout(&squeue_log, UART_DMA1);
	uart_logout(&squeue_command, UART_DMA2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == htim10.Instance)
	{
		//2ms
		gyroscope_read();
	}
	else if(htim->Instance == htim11.Instance)
	{
		//5ms
		motor_update(&motor_l);
		motor_update(&motor_r);
		balance_keep_update();
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
	{		

	}
	else if(huart->Instance == USART2)
	{
		uart_command_recv(uart2_recv_data);
		HAL_UART_Receive_IT(&huart2, (uint8_t*)&uart2_recv_data, 1);
	}
}





