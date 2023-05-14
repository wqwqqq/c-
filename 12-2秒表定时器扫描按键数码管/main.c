#include <REGX52.H>
#include "Nixie.h"
#include "Key.h"
#include "Timer0.h"
#include "AT24C02.h"
#include "Delay.h"

unsigned char haomiao,Sec,Min;
unsigned char Flag;

void shijian()
{
	if(Flag)
	{
		haomiao++;
		if(haomiao>=100)
		{
			haomiao=0;
			Sec++;
			if(Sec>=60)
			{
				Sec=0;
				Min++;
				if(Min>=60)
				{
					Min=0;
				}
			}
		}
	}
}


void main()
{
	unsigned char KeyNum,Temp;
	Timer0Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Flag=!Flag;
		}
		if(KeyNum==2)
		{
			haomiao=0;
			Min=0;
			Sec=0;
		}
		if(KeyNum==3)
		{
			AT24C02_WiteByte(1,Min);
			Delay(3);
			AT24C02_WiteByte(2,Sec);
			Delay(3);
			AT24C02_WiteByte(3,haomiao);
			Delay(3);
		}
		if(KeyNum==4)
		{
			haomiao=AT24C02_ReadByte(3);
			Min=AT24C02_ReadByte(1);
			Sec=AT24C02_ReadByte(2);
		}
		Nixie(1,Min/10);
		Nixie(2,Min%10);
		Nixie(3,11);
		Nixie(4,Sec/10);
		Nixie(5,Sec%10);
		Nixie(6,11);
		Nixie(7,haomiao/10);
		Nixie(8,haomiao%10);
		
	}
}


void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x18;		//??????
	TH0 = 0xFC;		//??????
	T0Count1++;
	T0Count2++;
	T0Count3++;
	if(T0Count1>=15)
	{
		T0Count1=0;
//		P2=~P2;
		Key_Loop();
	}

			Nixie_Loop();
		if(T0Count3>=10)
		{
			shijian();
			T0Count3=0;
		}


}
