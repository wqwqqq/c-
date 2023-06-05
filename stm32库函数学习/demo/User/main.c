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

#include "stm32f10x.h"

int main()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
	while(1);
}

