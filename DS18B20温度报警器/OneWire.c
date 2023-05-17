#include <REGX52.H>

sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init()//��ʼ��
{
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ=1;//�ȱ�֤DQΪ�ߵ�ƽ
	OneWire_DQ=0;//��DQ����
	i = 247;	while (--i);//Delay500us
	OneWire_DQ=1;//�ͷ�����
	i = 32;while (--i);//�ȴ�70us����ӻ��ͻ���Ӧ
	AckBit=OneWire_DQ;//��ȡ�ӻ���Ӧ��ֵ��0��Ӧ��1����
	i = 247;	while (--i);//Delay500us
	return AckBit;
}

void OneWire_SendBit(unsigned char Bit)//����һλ
{
	unsigned char i;
	EA=0;
	OneWire_DQ=0;
	i = 4;while (--i);
	OneWire_DQ=Bit;
	i = 24;while (--i);	
	OneWire_DQ=1;	
	EA=1;
}

unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i,Bit;
	EA=0;
	OneWire_DQ=0;
	i = 2;while (--i);
	OneWire_DQ=1;
	i = 2;while (--i);	
	Bit=OneWire_DQ;
	i = 24;while (--i);	
	EA=1;
	return Bit;
}

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

unsigned char OneWire_ReceiveByte()
{
	unsigned char i,Byte=0;
	for(i=0;i<8;i++)
	{
		if(OneWire_ReceiveBit())Byte|=(0x01<<i);
	}
	return Byte;
}

/******************������ֱ�ӷ���һ��ֱ�Ӻͽ���һ���ֽڵĺ���***************************/

//void SendByte(unsigned char Byte)
//{
//	unsigned char i,j;
//	for(j=0;j<8;j++)
//	{
//	OneWire_DQ=0;
//	i = 4;while (--i);
//	OneWire_DQ=Byte&(0x01<<i);
//	i = 24;while (--i);	
//	OneWire_DQ=1;	
//	}
//}

//unsigned char ReceiveByte(void)
//{
//	unsigned char i,j,Byte;
//	for(j=0;j<8;j++)
//	{
//	OneWire_DQ=0;
//	i = 2;while (--i);
//	OneWire_DQ=1;
//	i = 2;while (--i);	
//	if(OneWire_DQ)Byte|=(0x01<<j);
//	i = 24;while (--i);
//	}		
//	return Byte;
//	
//}
