#ifndef _PID_H
#define _PID_H

#include <stdint.h>
#include "macro.h"

typedef struct {
	float P; //!< 比例增益(P环增益)
	float I; //!< 积分增益（I环增益）
	float D; //!< 微分增益（D环增益）
	float output_ramp;
	float limit;
	float error_prev; //!< 最后的跟踪误差值
	float output_prev;  //!< 最后一个 pid 输出值
	float integral_prev; //!< 最后一个积分分量值
	uint32_t timestamp_now; //!< 当前时间戳
	uint32_t timestamp_prev; //!< 上次执行时间戳
}pid_controller_t;

float pid_operator(float error, pid_controller_t* pid);

#endif