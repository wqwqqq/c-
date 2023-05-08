#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

void _74HC595_WriteByte(unsigned char Byte)//写一位数据到74HC595里面
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);//高位先写，所以先&上0x80
		SCK=1;//给一个上升岩数据一位
//		Delay(1);
		SCK=0;//置1，下次就可以再给一个上升沿将数据移位
	}
	RCK=1;//给一个上升岩将8位数据移位
//	Delay(1);
	RCK=0;
}

void MatrixLed_ShowColumn(unsigned char Colum,Data)//位选，段选
{
	_74HC595_WriteByte(Data);
	P0=~(0x80>>Colum);
	Delay(1);
	P0=0xff;//位清0
}

void MatrixLED_Init()
{
	SCK=0;//因为上电默认是高电平，所以要置1
	RCK=0;

}
