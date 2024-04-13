#ifndef _SW_I2C_H
#define _SW_I2C_H

#include "main.h"
#include "system.h"

typedef uint8_t u8;

//#define SW_I2C_SCL_GPIO_Port GPIOB
//#define SW_I2C_SCL_Pin GPIO_PIN_8
//#define SW_I2C_SDA_GPIO_Port GPIOB
//#define SW_I2C_SDA_Pin GPIO_PIN_9

#define I2C_CLEAR_SDA HAL_GPIO_WritePin(SW_I2C_SDA_GPIO_Port, SW_I2C_SDA_Pin, GPIO_PIN_RESET);
#define I2C_SET_SDA HAL_GPIO_WritePin(SW_I2C_SDA_GPIO_Port, SW_I2C_SDA_Pin, GPIO_PIN_SET);

#define I2C_CLEAR_SCL HAL_GPIO_WritePin(SW_I2C_SCL_GPIO_Port, SW_I2C_SCL_Pin, GPIO_PIN_RESET);
#define I2C_SET_SCL HAL_GPIO_WritePin(SW_I2C_SCL_GPIO_Port, SW_I2C_SCL_Pin, GPIO_PIN_SET);

#define I2C_SDA_IN  _sda_in();
#define I2C_SDA_OUT _sda_out();
#define I2C_SDA_RD  HAL_GPIO_ReadPin(SW_I2C_SDA_GPIO_Port, SW_I2C_SDA_Pin)

#define IIC_Delay delayMicroseconds(1); // 5 microsecond delay

void IIC_Init(void);	 
u8 IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	  

unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr);
unsigned char IICwriteByte(unsigned char dev, unsigned char reg, unsigned char data);
u8 IICwriteBytes(u8 dev, u8 reg, u8 length, u8* data);
u8 IICwriteBits(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data);
u8 IICwriteBit(u8 dev,u8 reg,u8 bitNum,u8 data);
u8 IICreadBytes(u8 dev, u8 reg, u8 length, u8 *data);

int i2cWrite(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data);
int i2cRead(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf);


#endif /*__GD32_SW_I2C_H */
