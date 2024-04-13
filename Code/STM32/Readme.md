/**************************************
左侧电机:
TIM1 -- CH1,CH2,CH3
EN -- PB8
IA1 -- PA1 -- ADC1_IN1
IA3 -- PA4 -- ADC1_IN4

右侧电机:
TIM3 -- CH1,CH2,CH3
EN -- PB2
IA1 -- PA5 -- ADC1_IN5
IA3 -- PB1 -- ADC1_IN9

左侧编码器:
I2C1

右侧编码器:
I2C2

陀螺仪MPU6050:
SCL -- PB14
SDA -- PB15
INT -- PB4

SWD下载口:
CLK -- PA14
DIO -- PA13

调试串口1:
TX -- PA15
RX -- PB3

同ESP32通讯串口2:
TX -- PA2
RX -- PA3

3.7V锂电池电量检测:
PA0

有源蜂鸣器:
PB13

未使用电流采样!!!
原理图有电流采样电路，但我没有测试。
***************************************/