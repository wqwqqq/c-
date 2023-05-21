#include <REGX52.H>

/**
	* 	@brief	��ʼ����ʱ��0�����������ж�
	* 	@param	��
	* 	@retval	��
*/

void Timer_Init()
{
	TMOD&=0XF0;//���ö�ʱ��ģʽ
	TMOD|=0X01;
	TF0=0;//��ʱ����־λ��0
	TR0=1;//������ʱ��1
	TH0=0;//����ֵ
	TL0=0;
	ET0=1;//�����ж�
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