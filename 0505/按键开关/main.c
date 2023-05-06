#include <REGX52.H>
#include "Delay.h"



unsigned int Key()
{
	unsigned int k=0;
	if(P3_1==0){Delay(10);while(P3_1==0);Delay(10);k=1;}
	if(P3_0==0){Delay(10);while(P3_0==0);Delay(10);k=2;}
	if(P3_2==0){Delay(10);while(P3_2==0);Delay(10);k=3;}
	if(P3_3==0){Delay(10);while(P3_3==0);Delay(10);k=4;}
	
	return k;
}

void main()
{
	
	unsigned int a;
	while(1)
	{
//		if(P3_1==0){
//		Delay(20);while(P3_1==0);Delay(20);
//		P2_0=!P2_0;
//		}
		a=Key();
		if(a==1)
		{
			P2_0=!P2_0;
		}

	}
}