#ifndef _COMMAND_H
#define _COMMAND_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "usart.h"

#include "pid.h"

typedef enum
{
	COMMAND_UPLOAD_NONE,
	COMMAND_UPLOAD_PID,
	COMMAND_UPLOAD_VEL,
	COMMAND_UPLOAD_STEERING,
	COMMAND_UPLOAD_GYROSCOPE,
}command_upload_t;

typedef enum
{
	COMMAND_SET_NONE,
	COMMAND_SET_PID_RESET,
	COMMAND_SET_PID_SAVE,
}command_set_t;

struct _command_t;

typedef struct _command_t
{
	uint8_t id;
	float vel;
	float steering;
	pid_controller_t pid_velocity;
	pid_controller_t pid_stand;
	pid_controller_t pid_turn;
	
	command_upload_t upload_type;
	command_set_t set_type;
	
	void (*load_cb)(struct _command_t *command);
	void (*recv_cb)(struct _command_t *command);
	void (*upload_cb)(struct _command_t *command);
}command_typedef_t;

void uart_command_recv(char data);
void uart_command_process(command_typedef_t *command);
void uart_command_upload(command_typedef_t *command);

#endif