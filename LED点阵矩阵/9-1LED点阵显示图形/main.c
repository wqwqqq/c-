#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

void _74HC595_WriteByte(unsigned char Byte)//дһλ���ݵ�74HC595����
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);//��λ��д��������&��0x80
		SCK=1;//��һ������������һλ
//		Delay(1);
		SCK=0;//��1���´ξͿ����ٸ�һ�������ؽ�������λ
	}
	RCK=1;//��һ�������ҽ�8λ������λ
//	Delay(1);
	RCK=0;
}

void MatrixLed_ShowColumn(unsigned char Colum,Data)//λѡ����ѡ
{
	_74HC595_WriteByte(Data);
	P0=~(0x80>>Colum);
	Delay(1);
	P0=0xff;//λ��0
}

void main()
{
	SCK=0;//��Ϊ�ϵ�Ĭ���Ǹߵ�ƽ������Ҫ��1
	RCK=0;
	MatrixLed_ShowColumn(7,0xaa);
	while(1)
	{
			MatrixLed_ShowColumn(0,0x3c);
			MatrixLed_ShowColumn(1,0x42);
			MatrixLed_ShowColumn(2,0xa9);
			MatrixLed_ShowColumn(3,0x85);
			MatrixLed_ShowColumn(4,0x85);
			MatrixLed_ShowColumn(5,0xa9);
			MatrixLed_ShowColumn(6,0x42);
			MatrixLed_ShowColumn(7,0x3c);
	}
}