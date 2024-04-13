#include "command.h"

/********************************

接收命令格式
设置速度: M0 V5
设置转向: M0 T5
设置速度PID: M0 PVP0.01/I0.01/D0.01
设置直立PID: M0 PSP0.01/I0.01/D0.01
设置转向PID: M0 PTP0.01/I0.01/D0.01
保存PID数据: M0 SP
重置PID数据: M0 RP

查询PID    : M0 UP
查询陀螺仪 : M0 UG
查询速度   : M0 UV
查询转向   : M0 UT

查询上传数据格式
上传PID    : P 0 0 0 0 0 0 0 0 0 (三个一组，分别对应速度，直立，转向PID)
上传陀螺仪 : G 0 0 0 0 0 0 (对应roll pitch yaw x_gyro y_gyro z_gyro)
上传速度   : V 0
上传转向   : T 0
*********************************/

const uint8_t uart_command_buff_len = 16;
char uart_command_buff[uart_command_buff_len];
uint8_t uart_command_index;
bool uart_command_flag;

void uart_command_recv(char data)
{
	if(uart_command_flag)
	{
		uart_command_index = 0;
		return;
	}
	
	if(data != '\n' && (uart_command_index < uart_command_buff_len))
	{
		uart_command_buff[uart_command_index] = data;
		uart_command_index++;
	}
	else
	{
		uart_command_flag = true; //接收完成
	}
}

void uart_command_upload(command_typedef_t *command)
{
	if(NULL != command->upload_cb)
	{
		command->upload_cb(command);
	}
}

#include "s_queue.h"
extern s_queue_t squeue_log;

void uart_command_process(command_typedef_t *command)
{
	if(uart_command_flag)
	{
		pid_controller_t *pid = NULL;
		char *token = strtok(uart_command_buff, " ");
		
		while(NULL != token)
		{			
			if(token[0] == 'M')
			{
				command->id = atoi(token + 1);
				if(NULL != command->load_cb)
					command->load_cb(command);
			}
			else if(token[0] == 'V')
			{
				command->vel = atof(token + 1);
			}
			else if(token[0] == 'T')
			{
				command->steering = atof(token + 1);
			}
			else if(token[0] == 'R')
			{
				if(token[1] == 'P')
				{
					command->set_type = COMMAND_SET_PID_RESET;
				}
			}
			else if(token[0] == 'S')
			{
				if(token[1] == 'P')
				{
					command->set_type = COMMAND_SET_PID_SAVE;
				}
			}
			else if(token[0] == 'P')
			{
				if(token[1] == 'V')
				{
					pid = &command->pid_velocity;
				}
				else if(token[1] == 'S')
				{
					pid = &command->pid_stand;
				}
				else if(token[1] == 'T')
				{
					pid = &command->pid_turn;
				}
				
				if(NULL != pid)
				{
					switch(token[2])
					{
						case 'P':
							pid->P = atof(token + 3);
							break;
						case 'I':
							pid->I = atof(token + 3);
							break;
						case 'D':
							pid->D = atof(token + 3);
							break;
						default: break;
					}
				}
			}
			else if(token[0] == 'U')
			{
				switch(token[1])
				{
					case 'P':
						command->upload_type = COMMAND_UPLOAD_PID;
						break;
					case 'G':
						command->upload_type = COMMAND_UPLOAD_GYROSCOPE;
						break;
					case 'V':
						command->upload_type = COMMAND_UPLOAD_VEL;
						break;
					case 'T':
						command->upload_type = COMMAND_UPLOAD_STEERING;
						break;
				}
			}
			
			token = strtok(NULL, " ");
		}
		
		if(NULL != command->recv_cb && (command->upload_type == COMMAND_UPLOAD_NONE))
		{
			//接收设置数据
			command->recv_cb(command);
		}
		
		if(command->upload_type != COMMAND_UPLOAD_NONE)
		{
			//上传查询数据
			uart_command_upload(command);
		}
		
		memset(uart_command_buff, 0x0, uart_command_buff_len);
		uart_command_index = 0;
		uart_command_flag = false;
		command->upload_type = COMMAND_UPLOAD_NONE;
		command->set_type = COMMAND_SET_NONE;
	}
}



