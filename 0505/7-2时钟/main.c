#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Timer0.h"
#include "LCD1602.h"

unsigned char shi,fen,miao,set,K;

void main()
{
	LCD_Init();
	Timer_Init();
	LCD_ShowString(2,1,"hello");
	LCD_ShowString(1,1,"  :  :");

	while(1)
	{
		K=Key();//获取按键值
		if(K==1)//如果按键按下1
		{
			set++;//++
		}
		
				if(set==1)//如果set==1
		{

			if(K==2)//如果按键2按下，时++
			{
				shi++;
			}
			if(K==3)//如果按键3按下，时--
			{
				shi--;
			}
		}
		if(set==2)//如果set等于2
		{
			if(K==2)
			{
				fen++;
			}
			if(K==3)
			{
				fen--;
			}
		}
		if(set>=3)//set的取值范围是0，1，2
		{
			set=0;
		}

		LCD_ShowNum(1,1,shi,2);//显示时分秒
		LCD_ShowNum(1,4,fen,2);
		LCD_ShowNum(1,7,miao,2);
		LCD_ShowNum(2,7,set,2);//显示设置的

	}
}


void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=64535/256;//给计数器赋初值
		TL0=64535%256;
		count++;
		if(count>1000)//一秒钟进来一次
		{
					count=0;
					miao++;					
					if(miao>=60)
					{
						fen++;
						miao=0;
						if(fen>=60)
						{
						shi++;
						fen=0;
							if(shi>=24)
							{
								shi=0;
							}
						}
					}
		}


}