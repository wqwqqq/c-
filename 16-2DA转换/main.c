#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"

unsigned char Ton;
void main()
{
	int i;
	Timer_Init();
	while(1)
	{
		for(i=0;i<=100;i++)
		{
			Ton=i;
			Delay(5);
		}
		for(i=100;i>=0;i--)
		{
			Ton=i;
			Delay(5);
		}
	}
}

void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=0xFF;
		TL0=0x9c;
		count++;
		count%=100;
		if(count<Ton)
		{
			P2_1=0;
		}
		else
		{
			P2_1=1;
		}

}

//sbit DA=P2^1;

//unsigned char Counter,Compare;	//???????,????PWM
//unsigned char i;

//void main()
//{
//	Timer_Init();
//	while(1)
//	{
//		for(i=0;i<100;i++)
//		{
//			Compare=i;			//?????,??PWM???
//			Delay(10);
//		}
//		for(i=100;i>0;i--)
//		{
//			Compare=i;			//?????,??PWM???
//			Delay(10);
//		}
//	}
//}

//void Timer0_Routine() interrupt 1
//{
//	TL0 = 0x9C;		//??????
//	TH0 = 0xFF;		//??????
//	Counter++;
//	Counter%=100;	//??????????0~99
//	if(Counter<Compare)	//????????
//	{
//		DA=1;		//??1
//	}
//	else				//????????
//	{
//		DA=0;		//??0
//	}
//}
