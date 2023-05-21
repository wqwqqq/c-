#include <REGX52.H>

/**
	* 	@brief	初始化定时器0函数，并打开中断
	* 	@param	无
	* 	@retval	无
*/

void Timer_Init()
{
	TMOD&=0XF0;//设置定时器模式
	TMOD|=0X01;
	TF0=0;//定时器标志位清0
	TR0=1;//开启定时器1
	TH0=0;//赋初值
	TL0=0;
	ET0=1;//开启中断
	EA=1;
	PT0=0;
}

void Timer0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}

unsigned int Timer0_GetCounter()
{
	return (TH0<<8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
	TR0=Flag;
}