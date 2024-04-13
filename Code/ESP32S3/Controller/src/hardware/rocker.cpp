#include "rocker.h"
#include "extern_inc.h"

Rocker::Rocker(int pinx, int piny, int pinsw) : pin_x(pinx), pin_y(piny), pin_sw(pinsw)
{
  pinMode(pin_x, INPUT_PULLUP);
  pinMode(pin_y, INPUT_PULLUP);
  pinMode(pin_sw, INPUT_PULLUP);
}

Rocker::~Rocker()
{
}

void Rocker::read()
{
  int x = analogRead(pin_x);
  int y = analogRead(pin_y);
  rocker_data.data_sw = digitalRead(pin_sw);

  rocker_data.data_x = lpf_x(x);
  rocker_data.data_y = lpf_y(y);

  //转向
  if(rocker_data.data_x <= (mid_val_x - val_offset))
  {
    steering = map_float(rocker_data.data_x, 0, (mid_val_x - val_offset), steering_min, 0);
  }
  else if(rocker_data.data_x >= (mid_val_x + val_offset))
  {
    steering = map_float(rocker_data.data_x, (mid_val_x + val_offset), 4095, 0, steering_max);
  }
  else
  {
    steering = 0;
  }

  //速度
  if(rocker_data.data_y <= (mid_val_y - val_offset))
  {
    velocity = map_float(rocker_data.data_y, 0, (mid_val_y - val_offset), v_min, 0);
  }
  else if(rocker_data.data_y >= (mid_val_y + val_offset))
  {
    velocity = map_float(rocker_data.data_y, (mid_val_y + val_offset), 4095, 0, v_max);
  }
  else
  {
    velocity = 0;
  }
}

