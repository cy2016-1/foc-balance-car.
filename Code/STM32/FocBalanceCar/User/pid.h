#ifndef _PID_H
#define _PID_H

#include <stdint.h>
#include "macro.h"

typedef struct {
	float P; //!< ��������(P������)
	float I; //!< �������棨I�����棩
	float D; //!< ΢�����棨D�����棩
	float output_ramp;
	float limit;
	float error_prev; //!< ���ĸ������ֵ
	float output_prev;  //!< ���һ�� pid ���ֵ
	float integral_prev; //!< ���һ�����ַ���ֵ
	uint32_t timestamp_now; //!< ��ǰʱ���
	uint32_t timestamp_prev; //!< �ϴ�ִ��ʱ���
}pid_controller_t;

float pid_operator(float error, pid_controller_t* pid);

#endif