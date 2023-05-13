#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void MyI2C_W_SCL(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,(BitAction)BitValue);
	Delay_us(10);
}

void MyI2C_W_SDA(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,(BitAction)BitValue);
	Delay_us(10);
}

uint8_t MyI2C_R_SDA()
{
	uint8_t BitValute;
	BitValute=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
	Delay_us(10);
	return BitValute;
}

void MyI2C_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_10 | GPIO_Pin_11);

}

void MyI2C_Start()
{
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(0);
}

void MyI2C_Stop()
{
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);	
}

void MyI2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{	
	MyI2C_W_SDA(Byte&(0x80>>i));//开始后，发送数据SCL是低电频，低电频直接将数据放在SDA上
	MyI2C_W_SCL(1);//高电平是是从机读取数据，不需要主机操控
	MyI2C_W_SCL(0);
	}	
}

uint8_t MyI2C_ReceiveByte(void)
{
		uint8_t i;
		uint8_t Byte=0;
		MyI2C_W_SDA(1);//主机释放SDA数据线
		MyI2C_W_SCL(1);//这里释放SDA才可以读取数据，高电平读取，因为SDA不是由主机控制，只要读就行，不需要主机改变SDA！！！！
		for(i=0;i<8;i++)
		{
		MyI2C_W_SCL(1);//这里释放SDA才可以读取数据，高电平读取，因为SDA不是由主机控制，只要读就行，不需要主机改变SDA！！！！			
		if(MyI2C_R_SDA()==1){Byte|=(0x80>>i);}//读取SDA电频变化，连续8个BIT位，这里是由从机控制SDA
		MyI2C_W_SCL(0);//读取完数据后，SCL拉低	
		}
		return Byte;
}

void MyI2C_SendAck(uint8_t AckBit)//发送应答位，相当于发送一个字节
{
	MyI2C_W_SDA(AckBit);
	MyI2C_W_SCL(1);
	MyI2C_W_SCL(0);	
}

uint8_t MyI2C_ReceiveAck(void)//接收应答位，相当于接收一个字节
{
		uint8_t AckBit;
		MyI2C_W_SDA(1);
		MyI2C_W_SCL(1);		
		AckBit=MyI2C_R_SDA();
		MyI2C_W_SCL(0);
		return AckBit;
}
