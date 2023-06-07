#include "Delay.h"

void Delay_Init()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//ѡ��ϵͳʱ��72������8��Ƶ
	((SysTick_Type*)(0xE000E010))->CTRL &=~(1<<2);//��ctrl�Ĵ����ĵ�2λ��0����Ƶϵ��Ϊ8
}

void Delay_ms(uint32_t nms)
{
	((SysTick_Type*)(0xE000E010))->LOAD=nms*9000;//��װ��ֵΪ9000����Ϊ��Ƶϵ����8,72/8,9MHZ
	((SysTick_Type*)(0xE000E010))->VAL=0;//������ֵΪ0
	((SysTick_Type*)(0xE000E010))->CTRL|=0x01;//���λ��1����ʱ��ʹ�ܿ�ʼ��ʱ
	
	while(((((SysTick_Type*)(0xE000E010))->CTRL)&(0x01<<16))==0);//�ȴ���־λ��1
}

void Delay_us(uint32_t nus)
{
	((SysTick_Type*)(0xE000E010))->LOAD=nus*9;//��װ��ֵΪ9000����Ϊ��Ƶϵ����8,72/8,9MHZ
	((SysTick_Type*)(0xE000E010))->VAL=0;//������ֵΪ0
	((SysTick_Type*)(0xE000E010))->CTRL|=0x01;//���λ��1����ʱ��ʹ�ܿ�ʼ��ʱ
	
	while((((SysTick_Type*)(0xE000E010))->CTRL&(0x01<<16))==0);//�ȴ���־λ��1
}
