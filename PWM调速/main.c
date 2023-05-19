#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"

unsigned char Ton;
void main()
{
	int i,j;
	Timer_Init();
	while(1)
	{
			for(j=0;j<100;j++)
			{
				for(i=0;i<10;i++)
				{
					if(i==9)
					{
						Ton++;
					}
				}
			}
			
			for(j=0;j<100;j++)
			{
				for(i=0;i<10;i++)
				{
					if(i==9)
					{
						Ton--;
					}
				}
			}
	}
}

void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=65525/256;
		TL0=65525%256;
		count++;
		count%=100;
		if(count>=Ton)
		{
			P2_1=0;
		}
		else
		{
			P2_1=1;
		}

}