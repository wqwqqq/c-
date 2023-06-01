#include <STC32G.H>
#include "motor.h"
#include "Key.h"
#include "Timer.h"
#include "LED.h"


 char PWM;

void main()
{
	unsigned char K=0;
	unsigned char Flag=0;
	LED_Init();
	Timer4Init();
	Key_Init();
	Motor_Init();
	while(1)
	{
		K=Key();
		if(K==1)
		{
			if(Flag==0)
			{
				PWM+=20;
				if(PWM>100)
				{
					Flag=!Flag;
					PWM-=20;
				}
			}
			else
			{
				PWM-=20;
				if(PWM<0)
				{
					Flag=!Flag;	
					PWM+=20;
				}
			}
		}
	}
}

/***********************************************************
������������ʱ��4�жϷ������
��ڲ�������
����ֵ����       250us����1���ж� 
************************************************************/
void timer4_int (void) interrupt 20
{
		static unsigned int count;
		count++;
		count%=100;
		if(PWM>=count&&PWM!=0)
		{
			Car_F();
			LED_ON();
		}
		else
		{
			Car_Stop();
			LED_OFF();
		}
} 

/*********************************END FILE********************************************/	

