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


void Timer0_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0xCD;				//���ö�ʱ��ʼֵ
	TH0 = 0xD4;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	EA=1;//������ʱ��
	ET0=1;//�����ж�

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
	TL0 = 0xCD;				//���ö�ʱ��ʼֵ
	TH0 = 0xD4;				//���ö�ʱ��ʼֵ
	
	count++;
	if(count>100)
	{
		count=0;
		shijian();
	}
	
	
}