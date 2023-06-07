#include "Delay.h"

void Delay_Init()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//选择系统时钟72，并且8分频
	((SysTick_Type*)(0xE000E010))->CTRL &=~(1<<2);//将ctrl寄存器的低2位置0，分频系数为8
}

void Delay_ms(uint32_t nms)
{
	((SysTick_Type*)(0xE000E010))->LOAD=nms*9000;//重装载值为9000，因为分频系数是8,72/8,9MHZ
	((SysTick_Type*)(0xE000E010))->VAL=0;//计数器值为0
	((SysTick_Type*)(0xE000E010))->CTRL|=0x01;//最低位置1，计时器使能开始计时
	
	while(((((SysTick_Type*)(0xE000E010))->CTRL)&(0x01<<16))==0);//等待标志位置1
}

void Delay_us(uint32_t nus)
{
	((SysTick_Type*)(0xE000E010))->LOAD=nus*9;//重装载值为9000，因为分频系数是8,72/8,9MHZ
	((SysTick_Type*)(0xE000E010))->VAL=0;//计数器值为0
	((SysTick_Type*)(0xE000E010))->CTRL|=0x01;//最低位置1，计时器使能开始计时
	
	while((((SysTick_Type*)(0xE000E010))->CTRL&(0x01<<16))==0);//等待标志位置1
}
