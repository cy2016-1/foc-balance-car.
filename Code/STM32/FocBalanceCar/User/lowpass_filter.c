#include "lowpass_filter.h"

float lowpass_filter_operator(float x, lowpass_filter_t* filter)
{
//	float dt = (filter->timestamp_now - filter->timestamp_prev)*1e-6f;
	
//	if (dt < 0.0f ) dt = 1e-3f;
//	else if(dt > 0.3f) {
//			filter->y_prev = x;
//			filter->timestamp_prev = filter->timestamp_now;
//			return x;
//	}
	
	float dt = 5e-3f;

	float alpha = filter->tf/(filter->tf + dt);
	float y = alpha*filter->y_prev + (1.0f - alpha)*x;
	filter->y_prev = y;
	filter->timestamp_prev = filter->timestamp_now;
	
	return y;
}