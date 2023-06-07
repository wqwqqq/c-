#include "LED.h"

void LED_GPIO_Confing(void)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LED_GPIO_PIN|GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
}

void LED_GPIO_High(void)
{
	GPIO_SetBits(GPIOA,LED_GPIO_PIN);
}

void LED_GPIO_Low(void)
{
	GPIO_ResetBits(GPIOA,LED_GPIO_PIN);
}
