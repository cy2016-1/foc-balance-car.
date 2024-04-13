#ifndef _LOWPASS_FILTER_H
#define _LOWPASS_FILTER_H

typedef struct {
	float tf; //!< ��ͨ�˲�ʱ�䳣��
	unsigned long timestamp_now;
	unsigned long timestamp_prev;  //!< ���ִ��ʱ���
	float y_prev; //!< ��һ��ѭ���еĹ��˺��ֵ
}lowpass_filter_t;

float lowpass_filter_operator(float x, lowpass_filter_t* filter);

#endif