#include "s_queue.h"

void squeue_init(s_queue_t *q)
{
	memset(q->data, 0x0, QUEUE_MAX_SIZE * QUEUE_DATA_SIZE);
	q->front = 0;
	q->rear = 0;
}

void squeue_clear(s_queue_t *q)
{
	q->front = 0;
	q->rear = 0;
}

int squeue_get_length(s_queue_t *q)
{
	return ((q->rear - q->front + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE);
}

bool squeue_in(s_queue_t *q, char *e)
{
	if((q->rear + 1) % QUEUE_MAX_SIZE == q->front)
	{
		return false;
	}
	
	strcpy(q->data[q->rear], e);
	q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;
	return true;
}

#include "user_inc.h"
bool squeue_in_printf(s_queue_t *q, const char* p_format, ...)
{
	va_list args;
	char buf[QUEUE_DATA_SIZE] = {0};
	
	va_start(args, p_format);
	vsnprintf(buf, sizeof(buf), p_format, args);
	va_end(args);
	
	return squeue_in(q, buf);
}

bool squeue_out(s_queue_t *q, char *e)
{
	if(q->front == q->rear)
	{
		return false;
	}
	
	strcpy(e, q->data[q->front]);
	q->front = (q->front + 1) % QUEUE_MAX_SIZE;
	return true;
}