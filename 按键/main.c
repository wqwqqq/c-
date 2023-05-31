#include <STC32G.H>
#include "Key.h"
#include "LED.h"

#define MAIN_Fosc			24000000

void main()
{
	unsigned char K=0;
	
	Key_Init();
	LED_Init();
	
	while(1)
	{
		K=Key();
		if(K==1)
		{
			LED_R=~LED_R;
			LED_L=~LED_L;
		}
	}
}
