#include <REGX52.H>
#include "OneWrie.h"

#define DS18B20_SKIP_ROM  0XCC
#define DS18B20_CONVERT_T 0X44
#define DS18B20_READ_SCRATCHPAD	0XBE

void DS18B20_Init()
{
	OneWire_Init();//初始化单总线
	OneWire_SendByte(DS18B20_SKIP_ROM);//发送跳过ROM
	OneWire_SendByte(DS18B20_CONVERT_T);//发送转换
}

float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;//16位，读两次
	int Temp;
	float T;
//	EA=0;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_ReceiveByte();
	TMSB=OneWire_ReceiveByte();
	Temp=(TMSB*256)|TLSB;//合成16位数据
	T=Temp/16.0;//后面4位是小数
//	EA=1;
	return T;//返回T
}