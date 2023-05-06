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
	TH0=64535/256;//赋初值
	TL0=64535%256;
	ET0=1;//开启中断
	EA=1;
	PT0=0;
}

//void Timer0_Routine() interrupt 1
//{
//		static unsigned int count;
//		TH0=64535/256;
//		TL0=64535%256;
//		count++;
//		if(count>1000)
//		{
//					P2=~P2;
//					count=0;
//		}


//}