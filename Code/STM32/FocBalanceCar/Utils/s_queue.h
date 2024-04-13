#ifndef _S_QUEUE_H
#define _S_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#define QUEUE_MAX_SIZE 32
#define QUEUE_DATA_SIZE 128

typedef struct
{
	char data[QUEUE_MAX_SIZE][QUEUE_DATA_SIZE];
	int front;
	int rear;
}s_queue_t;

void squeue_init(s_queue_t *q);
void squeue_clear(s_queue_t *q);
int squeue_get_length(s_queue_t *q);
bool squeue_in(s_queue_t *q, char *e);
bool squeue_in_printf(s_queue_t *q, const char* p_format, ...);
bool squeue_out(s_queue_t *q, char *e);

#endif