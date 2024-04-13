#pragma once

#include <Arduino.h>
#include "lowpass_filter.h"

typedef struct
{
  int data_x;
  int data_y;
  int data_sw;
} rocker_data_t;

class Rocker
{
private:
  int pin_x;
  int pin_y;
  int pin_sw;

  int mid_val_x, mid_val_y;
  int val_offset;

  float v_max, v_min;
  float steering_max, steering_min;

  float velocity;
  float steering;

  rocker_data_t rocker_data;

  LowPassFilter lpf_x = LowPassFilter(0.01);
  LowPassFilter lpf_y = LowPassFilter(0.01);

public:
  Rocker(int pinx, int piny, int pinsw);
  ~Rocker();
  void read();

  void set_velocity_range(float min, float max)
  {
    v_min = min;
    v_max = max;
  }

  void set_steering_range(float min, float max)
  {
    steering_min = min;
    steering_max = max;
  }

  void set_mid_val(int x, int y, int offset)
  {
    mid_val_x = x;
    mid_val_y = y;
    val_offset = offset;
  }

  rocker_data_t *rocker_get_data() { return &rocker_data; }
  float rocker_get_velocity() { return velocity; }
  float rocker_get_steering() { return steering; }
};
