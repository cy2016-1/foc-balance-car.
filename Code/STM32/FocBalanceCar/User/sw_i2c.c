#include "sw_i2c.h"
//#include "dwt_stm32_delay.h"

//void I2C_bus_init(uint8_t scl_pin, uint8_t sda_pin, uint8_t port){
//	  /*Configure GPIO pins : SW_I2C_SCL_Pin SW_I2C_SDA_Pin */
//	  GPIO_InitStruct.Pin = SW_I2C_SCL_Pin|SW_I2C_SDA_Pin;
//	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
//	  GPIO_InitStruct.Pull = GPIO_PULLUP;
//	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//}

void _sda_out()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
  GPIO_InitStruct.Pin = SW_I2C_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SW_I2C_SDA_GPIO_Port, &GPIO_InitStruct);
}

void _sda_in()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
  GPIO_InitStruct.Pin = SW_I2C_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SW_I2C_SDA_GPIO_Port, &GPIO_InitStruct);
}

void IIC_Init()
{
	I2C_SET_SCL
	I2C_SET_SDA
}

//产生IIC起始信号
u8 IIC_Start(void)
{
	I2C_SDA_OUT     //sda线输出
	I2C_SET_SDA
	if(!I2C_SDA_RD)return 0;	
	I2C_SET_SCL
	IIC_Delay
 	I2C_CLEAR_SDA//START:when CLK is high,DATA change form high to low 
	if(I2C_SDA_RD)return 0;
	IIC_Delay
	I2C_CLEAR_SCL//钳住I2C总线，准备发送或接收数据 
	return 1;
//	I2C_SDA_OUT     //sda线输出
//	I2C_SET_SDA	  	  
//	I2C_SET_SCL
//	IIC_Delay
// 	I2C_CLEAR_SDA//START:when CLK is high,DATA change form high to low 
//	IIC_Delay
//	I2C_CLEAR_SCL//钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void IIC_Stop(void)
{
	I2C_SDA_OUT//sda线输出
	I2C_CLEAR_SCL
	I2C_CLEAR_SDA//STOP:when CLK is high DATA change form low to high
 	IIC_Delay
	I2C_SET_SCL 
	I2C_SET_SDA//发送I2C总线结束信号
	IIC_Delay							   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	I2C_SDA_IN      //SDA设置为输入  
	I2C_SET_SDA
	IIC_Delay	   
	I2C_SET_SCL
	IIC_Delay	 
	while(I2C_SDA_RD)
	{
		ucErrTime++;
		if(ucErrTime>100)
		{
			IIC_Stop();   //
			return 0;
		}
		IIC_Delay
	}
	I2C_CLEAR_SCL//时钟输出0 	   
	return 1;  
} 
//产生ACK应答
void IIC_Ack(void)
{
	I2C_CLEAR_SCL
	I2C_SDA_OUT
	I2C_CLEAR_SDA
	IIC_Delay
	I2C_SET_SCL
	IIC_Delay
	I2C_CLEAR_SCL
}
//不产生ACK应答		    
void IIC_NAck(void)
{
	I2C_CLEAR_SCL
	I2C_SDA_OUT
	I2C_SET_SDA
	IIC_Delay
	I2C_SET_SCL
	IIC_Delay
	I2C_CLEAR_SCL
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	I2C_SDA_OUT 
	I2C_CLEAR_SCL//拉低时钟开始数据传输
	for(t=0;t<8;t++)
	{              
			//IIC_SDA=(txd&0x80)>>7;
	if((txd&0x80)>>7)
		I2C_SET_SDA
	else
		I2C_CLEAR_SDA
	txd<<=1; 	  
	IIC_Delay   //对TEA5767这三个延时都是必须的
	I2C_SET_SCL
	IIC_Delay 
	I2C_CLEAR_SCL	
	IIC_Delay
	}	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	I2C_SDA_IN//SDA设置为输入
    for(i=0;i<8;i++ )
		{
        I2C_CLEAR_SCL 
        IIC_Delay
				I2C_SET_SCL
        receive<<=1;
        if(I2C_SDA_RD)receive++;   
			IIC_Delay 
    }					 
    if (!ack)
        IIC_NAck();//发送nACK
    else
        IIC_Ack(); //发送ACK   
    return receive;
}
//****************************
//
//********添加代码************
//
/**************************实现函数********************************************
*函数原型:		bool i2cWrite(uint8_t addr, uint8_t reg, uint8_t data)
*功　　能:		
*******************************************************************************/
int i2cWrite(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data)
{
		int i;
    if (!IIC_Start())
        return 1;
    IIC_Send_Byte(addr << 1 );
    if (!IIC_Wait_Ack()) {
        IIC_Stop();
        return 1;
    }
    IIC_Send_Byte(reg);
    IIC_Wait_Ack();
		for (i = 0; i < len; i++) {
        IIC_Send_Byte(data[i]);
        if (!IIC_Wait_Ack()) {
            IIC_Stop();
            return 0;
        }
    }
    IIC_Stop();
    return 0;
}
/**************************实现函数********************************************
*函数原型:		bool i2cWrite(uint8_t addr, uint8_t reg, uint8_t data)
*功　　能:		
*******************************************************************************/
int i2cRead(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf)
{
    if (!IIC_Start())
        return 1;
    IIC_Send_Byte(addr << 1);
    if (!IIC_Wait_Ack()) {
        IIC_Stop();
        return 1;
    }
    IIC_Send_Byte(reg);
    IIC_Wait_Ack();
    IIC_Start();
    IIC_Send_Byte((addr << 1)+1);
    IIC_Wait_Ack();
    while (len) {
        if (len == 1)
            *buf = IIC_Read_Byte(0);
        else
            *buf = IIC_Read_Byte(1);
        buf++;
        len--;
    }
    IIC_Stop();
    return 0;
}
/**************************实现函数********************************************
*函数原型:		unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr)
*功　　能:	    读取指定设备 指定寄存器的一个值
输入	I2C_Addr  目标设备地址
		addr	   寄存器地址
返回   读出来的值
*******************************************************************************/ 
unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr)
{
	unsigned char res=0;
	
	IIC_Start();	
	IIC_Send_Byte(I2C_Addr);	   //发送写命令
	res++;
	IIC_Wait_Ack();
	IIC_Send_Byte(addr); res++;  //发送地址
	IIC_Wait_Ack();	  
	IIC_Stop();//产生一个停止条件	
	IIC_Start();
	IIC_Send_Byte(I2C_Addr+1); res++;          //进入接收模式			   
	IIC_Wait_Ack();
	res=IIC_Read_Byte(0);	   
	IIC_Stop();//产生一个停止条件

	return res;
}


/**************************实现函数********************************************
*函数原型:		u8 IICreadBytes(u8 dev, u8 reg, u8 length, u8 *data)
*功　　能:	    读取指定设备 指定寄存器的 length个值
输入	dev  目标设备地址
		reg	  寄存器地址
		length 要读的字节数
		*data  读出的数据将要存放的指针
返回   读出来的字节数量
*******************************************************************************/ 
u8 IICreadBytes(u8 dev, u8 reg, u8 length, u8 *data){
    u8 count = 0;
	
	IIC_Start();
	IIC_Send_Byte(dev);	   //发送写命令
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);   //发送地址
    IIC_Wait_Ack();	  
	IIC_Start();
	IIC_Send_Byte(dev+1);  //进入接收模式	
	IIC_Wait_Ack();
	
    for(count=0;count<length;count++){
		 
		 if(count!=length-1)data[count]=IIC_Read_Byte(1);  //带ACK的读数据
		 	else  data[count]=IIC_Read_Byte(0);	 //最后一个字节NACK
	}
    IIC_Stop();//产生一个停止条件
    return count;
}

/**************************实现函数********************************************
*函数原型:		u8 IICwriteBytes(u8 dev, u8 reg, u8 length, u8* data)
*功　　能:	    将多个字节写入指定设备 指定寄存器
输入	dev  目标设备地址
		reg	  寄存器地址
		length 要写的字节数
		*data  将要写的数据的首地址
返回   返回是否成功
*******************************************************************************/ 
u8 IICwriteBytes(u8 dev, u8 reg, u8 length, u8* data){
  
 	u8 count = 0;
	IIC_Start();
	IIC_Send_Byte(dev);	   //发送写命令
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);   //发送地址
    IIC_Wait_Ack();	  
	for(count=0;count<length;count++){
		IIC_Send_Byte(data[count]); 
		IIC_Wait_Ack(); 
	 }
	IIC_Stop();//产生一个停止条件

    return 1; //status == 0;
}

/**************************实现函数********************************************
*函数原型:		u8 IICreadByte(u8 dev, u8 reg, u8 *data)
*功　　能:	    读取指定设备 指定寄存器的一个值
输入	dev  目标设备地址
		reg	   寄存器地址
		*data  读出的数据将要存放的地址
返回   1
*******************************************************************************/ 
u8 IICreadByte(u8 dev, u8 reg, u8 *data){
	*data=I2C_ReadOneByte(dev, reg);
    return 1;
}

/**************************实现函数********************************************
*函数原型:		unsigned char IICwriteByte(unsigned char dev, unsigned char reg, unsigned char data)
*功　　能:	    写入指定设备 指定寄存器一个字节
输入	dev  目标设备地址
		reg	   寄存器地址
		data  将要写入的字节
返回   1
*******************************************************************************/ 
unsigned char IICwriteByte(unsigned char dev, unsigned char reg, unsigned char data){
    return IICwriteBytes(dev, reg, 1, &data);
}

/**************************实现函数********************************************
*函数原型:		u8 IICwriteBits(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
*功　　能:	    读 修改 写 指定设备 指定寄存器一个字节 中的多个位
输入	dev  目标设备地址
		reg	   寄存器地址
		bitStart  目标字节的起始位
		length   位长度
		data    存放改变目标字节位的值
返回   成功 为1 
 		失败为0
*******************************************************************************/ 
u8 IICwriteBits(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{

    u8 b;
    if (IICreadByte(dev, reg, &b) != 0) {
        u8 mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
        data <<= (8 - length);
        data >>= (7 - bitStart);
        b &= mask;
        b |= data;
        return IICwriteByte(dev, reg, b);
    } else {
        return 0;
    }
}

/**************************实现函数********************************************
*函数原型:		u8 IICwriteBit(u8 dev, u8 reg, u8 bitNum, u8 data)
*功　　能:	    读 修改 写 指定设备 指定寄存器一个字节 中的1个位
输入	dev  目标设备地址
		reg	   寄存器地址
		bitNum  要修改目标字节的bitNum位
		data  为0 时，目标位将被清0 否则将被置位
返回   成功 为1 
 		失败为0
*******************************************************************************/ 
u8 IICwriteBit(u8 dev, u8 reg, u8 bitNum, u8 data){
    u8 b;
    IICreadByte(dev, reg, &b);
    b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
    return IICwriteByte(dev, reg, b);
}

//------------------End of File----------------------------



