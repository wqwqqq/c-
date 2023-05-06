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
		K=Key();//��ȡ����ֵ
		if(K==1)//�����������1
		{
			set++;//++
		}
		
				if(set==1)//���set==1
		{

			if(K==2)//�������2���£�ʱ++
			{
				shi++;
			}
			if(K==3)//�������3���£�ʱ--
			{
				shi--;
			}
		}
		if(set==2)//���set����2
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
		if(set>=3)//set��ȡֵ��Χ��0��1��2
		{
			set=0;
		}

		LCD_ShowNum(1,1,shi,2);//��ʾʱ����
		LCD_ShowNum(1,4,fen,2);
		LCD_ShowNum(1,7,miao,2);
		LCD_ShowNum(2,7,set,2);//��ʾ���õ�

	}
}


void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=64535/256;//������������ֵ
		TL0=64535%256;
		count++;
		if(count>1000)//һ���ӽ���һ��
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