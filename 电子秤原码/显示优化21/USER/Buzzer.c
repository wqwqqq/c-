#include "config.h"

void Buzzer_Init()
{
	GPIO_InitTypeDef GPIOx;
	GPIOx.Mode=GPIO_OUT_PP;
	GPIOx.Pin=GPIO_Pin_5;
	
	GPIO_Inilize(GPIO_P4,&GPIOx);	
	
	P45=0;
}