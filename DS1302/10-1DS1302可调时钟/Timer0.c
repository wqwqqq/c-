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
	TH0=64535/256;//����ֵ
	TL0=64535%256;
	ET0=1;//�����ж�
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