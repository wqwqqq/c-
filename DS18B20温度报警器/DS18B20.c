#include <REGX52.H>
#include "OneWrie.h"

#define DS18B20_SKIP_ROM  0XCC
#define DS18B20_CONVERT_T 0X44
#define DS18B20_READ_SCRATCHPAD	0XBE

void DS18B20_Init()
{
	OneWire_Init();//��ʼ��������
	OneWire_SendByte(DS18B20_SKIP_ROM);//��������ROM
	OneWire_SendByte(DS18B20_CONVERT_T);//����ת��
}

float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;//16λ��������
	int Temp;
	float T;
//	EA=0;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_ReceiveByte();
	TMSB=OneWire_ReceiveByte();
	Temp=(TMSB*256)|TLSB;//�ϳ�16λ����
	T=Temp/16.0;//����4λ��С��
//	EA=1;
	return T;//����T
}