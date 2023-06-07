#include "stm32f10x.h"                  // Device header

//int main()
//{
//	GPIO_InitTypeDef GPIO_InitStruct;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1;
//	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStruct);
//	
//	GPIO_WriteBit(GPIOA,GPIO_Pin_1,(BitAction)1);
//	while(1)
//	{
//	
//	}
//}
#include "LED.h"
#include "timer3.h"

int main()
{
	LED_GPIO_Confing();
	
	TIM3_Init(9999,7199);//重装值+1，分频值+1
	
	
	while(1)
		
	{
	
	}
	
}
