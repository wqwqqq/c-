#include <REGX52.H>

sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init()//初始化
{
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ=1;//先保证DQ为高电平
	OneWire_DQ=0;//将DQ拉低
	i = 247;	while (--i);//Delay500us
	OneWire_DQ=1;//释放中线
	i = 32;while (--i);//等待70us，后从机就会相应
	AckBit=OneWire_DQ;//读取从机相应的值，0相应，1不想
	i = 247;	while (--i);//Delay500us
	return AckBit;
}

void OneWire_SendBit(unsigned char Bit)//发送一位
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

/******************下面是直接发送一个直接和接收一个字节的函数***************************/

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
