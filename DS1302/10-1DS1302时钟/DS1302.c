#include <REGX52.H>

#define DS1302_SECOND  0X80
#define DS1302_MINUTE  0X82
#define DS1302_HOUR    0X84
#define DS1302_DATE 	 0X86
#define DS1302_MONTH  0X88
#define DS1302_DAY     0X8A
#define DS1302_YEAR    0X8C
#define DS1302_WP      0X8E

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

unsigned char DS1302_Time[]={23,5,8,22,12,50,1};

void DS1302_Init()
{
	DS1302_CE=0;
	DS1302_SCLK=0;
}

void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i=0;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}

unsigned char DS1302_ReadByte(unsigned char Comand)
{
	unsigned char Byte=0;
	unsigned char i=0;
	Comand|=0X01;//改变为读命令
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Comand&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;//这里时序要好好注意一下
	}	
		for(i=0;i<8;i++)
		{
			DS1302_SCLK=1;
			DS1302_SCLK=0;
			if(DS1302_IO)Byte|=(0X01<<i);		
		}
	DS1302_CE=0;
	DS1302_IO=0;


	return Byte;
}

void Ds1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP,0);//关闭写保护
	DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP,0X80);//打开写保护

}

void DS1302_ReadTime(void)
{
	unsigned char Temp;
	Temp=DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6]=Temp/16*10+Temp%16;
}