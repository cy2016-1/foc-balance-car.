#ifndef _LOWPASS_FILTER_H
#define _LOWPASS_FILTER_H

typedef struct {
	float tf; //!< 低通滤波时间常数
	unsigned long timestamp_now;
	unsigned long timestamp_prev;  //!< 最后执行时间戳
	float y_prev; //!< 上一个循环中的过滤后的值
}lowpass_filter_t;

float lowpass_filter_operator(float x, lowpass_filter_t* filter);

#endif