#include <STC32G.H>

sbit LED_L=P3^4;
sbit LED_R=P0^5;

void LED_Init()
{
	P3M0|=0X10;
	P3M1&=0XEF;
	
	P0M0|=0X20;
	P0M1&=0XDF;
	
}

void LED_ON()
{
	LED_L=1;	
	LED_R=1;
}

void LED_OFF()
{
	LED_L=0;	
	LED_R=0;
}
