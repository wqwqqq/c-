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
#include "Delay.h"

//int main()
//{
//	
//	LED_GPIO_Confing();
//	while(1)
//	{
//		LED_GPIO_Low();
//		Delay_ms(500);
//		LED_GPIO_High();
//		Delay_ms(500);
//	}
//}

int main()
{
	uint8_t i;
	LED_GPIO_Confing();
	while(1)
	{
		for(i=0;i<8;i++)
		{
		GPIO_Write(GPIOA,0X01<<i);
		Delay_ms(500);
		}
		for(i=6;i>0;i--)
		{
		GPIO_Write(GPIOA,0X01<<i);
		Delay_ms(500);
		}
	
	}
}

