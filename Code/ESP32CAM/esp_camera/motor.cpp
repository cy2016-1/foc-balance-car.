#include <Arduino.h>
#include "esp_camera.h"
#include "esp32-hal-ledc.h"

#define ROCKER_DATA_OFFSET 200
#define ROCKER_DATA_MIN 20
#define ROCKER_DATA_MAX 4095

#define ROCKER_X_MID_VAL 2100
#define ROCKER_Y_MID_VAL 2350
#define ROCKER_X_MID_MIN (ROCKER_X_MID_VAL - ROCKER_DATA_OFFSET)
#define ROCKER_X_MID_MAX (ROCKER_X_MID_VAL + ROCKER_DATA_OFFSET)
#define ROCKER_Y_MID_MIN (ROCKER_Y_MID_VAL - ROCKER_DATA_OFFSET)
#define ROCKER_Y_MID_MAX (ROCKER_Y_MID_VAL + ROCKER_DATA_OFFSET)

#define XY_LIMIT_VALUE 60
#define SPEED_MAX 255

const int motor_pins[][2] = {
  {12, 13},
  {14, 15}
};

const int motor_ledc_chs[][2] = {
  {LEDC_CHANNEL_2, LEDC_CHANNEL_3},
  {LEDC_CHANNEL_4, LEDC_CHANNEL_5}
};

static uint8_t quadrant_detect(int x, int y) {
  if (x > XY_LIMIT_VALUE && y > 0)
    return 1;
  else if (x < -XY_LIMIT_VALUE && y > 0)
    return 2;
  else if (x < -XY_LIMIT_VALUE && y < 0)
    return 3;
  else if (x > XY_LIMIT_VALUE && y < 0)
    return 4;
  else if (x >= -XY_LIMIT_VALUE && x <= XY_LIMIT_VALUE && y > 0)
    return 5;
  else if (x >= -XY_LIMIT_VALUE && x <= XY_LIMIT_VALUE && y < 0)
    return 6;

  return 0;
}

static void speed_set(int8_t dir, uint8_t index, uint8_t speed) {
  if (dir > 0) {
    ledcWrite(motor_ledc_chs[index][0], speed);
    ledcWrite(motor_ledc_chs[index][1], 0);
  }
  else {
    ledcWrite(motor_ledc_chs[index][0], 0);
    ledcWrite(motor_ledc_chs[index][1], speed);
  }
}

void motor_stop() {
  for (int i = 0; i < 2; i++) {
    //ledcWrite(motor_ledc_chs[i][0], 0);
    //ledcWrite(motor_ledc_chs[i][1], 0);
    digitalWrite(motor_pins[i][0], HIGH);
    digitalWrite(motor_pins[i][1], HIGH);
  }
}

void motor_init() {
  for (int i = 0; i < 2; i++) {
    pinMode(motor_pins[i][0], OUTPUT);
    pinMode(motor_pins[i][1], OUTPUT);

    ledcSetup(motor_ledc_chs[i][0], 1000, LEDC_TIMER_8_BIT);
    ledcAttachPin(motor_pins[i][0], motor_ledc_chs[i][0]);

    ledcSetup(motor_ledc_chs[i][1], 1000, LEDC_TIMER_8_BIT);
    ledcAttachPin(motor_pins[i][1], motor_ledc_chs[i][1]);
  }

  motor_stop();
}

void motor_control(int x, int y) {
  if (x < ROCKER_X_MID_MIN) {
    //x_min~x_mid_min ==> -255~0
    x = map(x, ROCKER_DATA_MIN, ROCKER_X_MID_MIN, -SPEED_MAX, 0);
  }
  else if (x > ROCKER_X_MID_MAX) {
    //x_mid_max~x_max ==> 0~255
    x = map(x, ROCKER_X_MID_MAX, ROCKER_DATA_MAX, 0, SPEED_MAX);
  }
  else
    x = 0;

  if (y < ROCKER_Y_MID_MIN) {
    //y_mid_min~y_min ==> 0~255
    y = map(y, ROCKER_Y_MID_MIN, ROCKER_DATA_MIN, 0, -SPEED_MAX);
  }
  else if (y > ROCKER_Y_MID_MAX) {
    //y_mid_max~y_max ==> -255~0
    y = map(y, ROCKER_Y_MID_MAX, ROCKER_DATA_MAX, 0, SPEED_MAX);                                                                                                                                                                                                                                                                                                                                                                                                                         
  }
  else
    y = 0;

  //  Serial.print("x, y: ");
  //  Serial.print(x);
  //  Serial.print(", ");
  //  Serial.print(y);
  //  Serial.println();

  //摇杆数据转换为左右轮子速度
  uint8_t q = quadrant_detect(x, y);
  int8_t dir = 1; //前进1,后退-1
  uint8_t speed_left = 0;
  uint8_t speed_right = 0;

  switch (q)
  {
    case 0:
      //stop
      break;
    case 1:
    case 4:
      //右进、右退，右轮速度小
      dir = y > 0 ? 1 : -1;
      speed_left = max(abs(x), abs(y));
      speed_right = min(abs(x), abs(y));
      break;
    case 2:
    case 3:
      //左进、左退,左轮速度小
      dir = y > 0 ? 1 : -1;
      speed_left = min(abs(x), abs(y));
      speed_right = max(abs(x), abs(y));
      break;
    case 5:
      //前进
      speed_left = speed_right = max(abs(x), abs(y));
      break;
    case 6:
      //后退
      dir = -1;
      speed_left = speed_right = max(abs(x), abs(y));
      break;
  }

  //左右轮子速度
  //  Serial.print("dir: ");
  //  Serial.print(dir);
  //  Serial.print(", ");
  //  Serial.print("left: ");
  //  Serial.print(speed_left);
  //  Serial.print(", ");
  //  Serial.print("right: ");
  //  Serial.print(", ");
  //  Serial.println(speed_right);

  speed_set(dir, 0, speed_right);
  speed_set(dir, 1, speed_left);
}
