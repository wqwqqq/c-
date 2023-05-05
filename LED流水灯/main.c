#include <REGX52.H>
#include "Delay.h"



void main()
{
	
	unsigned int i=0;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P2=~(0X01<<i);
			Delay(50);
		}
		for(i=6;i>0;i--)
		{
			P2=~(0X01<<i);
			Delay(50);		
		}
	}
}