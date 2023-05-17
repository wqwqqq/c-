#include <REGX52.H>
#include "DS18B20.h"
#include "LCD1602.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Key.h"
#include "Timer0.h"

float T,TShow;

void main()
{
	char TH=0,TL=0;
	unsigned char K;
	Timer0Init();
	TH=AT24C02_ReadByte(0);
	TL=AT24C02_ReadByte(1);
	if(TH>125||TL<-55||TH<TL)
	{
		TH=25;
		TL=18;
	}
	LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	LCD_ShowSignedNum(2,4,TH,3);
	LCD_ShowSignedNum(2,12,TL,3);
	while(1)
	{
		K=Key();
		DS18B20_Init();
		T=DS18B20_ReadT();
		if(T<0)
		{
			LCD_ShowChar(1,3,'-');
			TShow=-T;
		}
		else
		{
			TShow=T;
			LCD_ShowChar(1,3,'+');
		}
		LCD_ShowNum(1,4,TShow,3);
		LCD_ShowString(1,7,".");
		LCD_ShowNum(1,8,(unsigned long)(TShow*10000)%10000,2);
		
		if(K)
	{
		if(K==1)
		{
			TH++;
			if(TH>125)TH=125;
		}
		if(K==2)
		{
			TH--;
			if(TH<=TL)TH++;
		}
		if(K==3)
		{
			TL++;
			if(TL>=TH)TL--;
		}
		if(K==4)
		{
			TL--;
			if(TL<-55)TL=-55;
		}
		LCD_ShowSignedNum(2,4,TH,3);
		LCD_ShowSignedNum(2,12,TL,3);
		Delay(5);
		AT24C02_WiteByte(0,TH);
		Delay(5);
		AT24C02_WiteByte(1,TL);
	}
	if(T>TH)
	{
		LCD_ShowString(1,13,"OV:H");
	}
	else if(T<TL)
	{
		LCD_ShowString(1,13,"OV:L");
	}
	else
	{
		LCD_ShowString(1,13,"    ");
	}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//??????
	TH0 = 0xFC;		//??????
	T0Count++;
	if(T0Count>=20)
	{
		T0Count=0;
		Key_Loop();
	}
}

