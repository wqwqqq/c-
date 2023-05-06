#include <REGX52.H>
#include "Delay.h"

unsigned int Key()
{
	unsigned int k=0;
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);k=1;}
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);k=2;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);k=3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);k=4;}
	
	return k;
}

void main()
{
	char i=0;
	unsigned char K;
	P2=~0X01;
	while(1)
	{
		K=Key();
		if(K==1)
		{
			i++;						
			if(i>=8)
			{
				i=0;
			}
			P2=~(0X01<<i);			
		}
		if(K==2)
		{
			i--;			
			if(i<0)
			{
				i=7;
			}
			P2=~(0X01<<i);			
		}
	}
}