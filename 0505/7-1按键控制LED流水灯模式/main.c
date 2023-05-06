#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>

unsigned char MODE;

void main()
{

	unsigned char K;
	P2=0xfe;
	Timer_Init();
	while(1)
	{
		K=Key();
		if(K==1)
		{
			MODE=!MODE;
		}

	}
}

void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=64535/256;
		TL0=64535%256;
		count++;
		if(count>1000)
		{
					count=0;
					if(MODE==1)
					{
						P2=_crol_(P2,1);
					}
					if(MODE==0)
					{
						P2=_cror_(P2,1);
					}
		}


}