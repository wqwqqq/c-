#include <REGX52.H>
#include "LCD1602.h"

unsigned char sec,min,hour;

void shijian()
{
	sec++;
	if(sec>=60)
	{
		min++;
		sec=0;
		if(min>=60)
		{
			hour++;
			min=0;
			if(hour>=24)
			{
				hour=0;
			}
		}
	}
}


void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0xCD;				//设置定时初始值
	TH0 = 0xD4;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	EA=1;//开启定时器
	ET0=1;//开启中断

}

void main()
{
	Timer0_Init();
	LCD_Init();
	LCD_ShowString(1,3,":  :");
	while(1)
	{
		LCD_ShowNum(1,1,hour,2);
		LCD_ShowNum(1,4,min,2);
		LCD_ShowNum(1,7,sec,2);
	}
}

void Timer0_Routine() interrupt 1
{
	
	static unsigned int count;
	TL0 = 0xCD;				//设置定时初始值
	TH0 = 0xD4;				//设置定时初始值
	
	count++;
	if(count>100)
	{
		count=0;
		shijian();
	}
	
	
}