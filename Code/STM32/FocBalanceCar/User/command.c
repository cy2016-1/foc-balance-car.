#include "command.h"

/********************************

���������ʽ
�����ٶ�: M0 V5
����ת��: M0 T5
�����ٶ�PID: M0 PVP0.01/I0.01/D0.01
����ֱ��PID: M0 PSP0.01/I0.01/D0.01
����ת��PID: M0 PTP0.01/I0.01/D0.01
����PID����: M0 SP
����PID����: M0 RP

��ѯPID    : M0 UP
��ѯ������ : M0 UG
��ѯ�ٶ�   : M0 UV
��ѯת��   : M0 UT

��ѯ�ϴ����ݸ�ʽ
�ϴ�PID    : P 0 0 0 0 0 0 0 0 0 (����һ�飬�ֱ��Ӧ�ٶȣ�ֱ����ת��PID)
�ϴ������� : G 0 0 0 0 0 0 (��Ӧroll pitch yaw x_gyro y_gyro z_gyro)
�ϴ��ٶ�   : V 0
�ϴ�ת��   : T 0
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
		uart_command_flag = true; //�������
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
			//������������
			command->recv_cb(command);
		}
		
		if(command->upload_type != COMMAND_UPLOAD_NONE)
		{
			//�ϴ���ѯ����
			uart_command_upload(command);
		}
		
		memset(uart_command_buff, 0x0, uart_command_buff_len);
		uart_command_index = 0;
		uart_command_flag = false;
		command->upload_type = COMMAND_UPLOAD_NONE;
		command->set_type = COMMAND_SET_NONE;
	}
}



