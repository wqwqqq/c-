#include	"GPIO.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIOx;
	GPIOx.Mode=GPIO_OUT_PP;
	GPIOx.Pin=GPIO_Pin_3|GPIO_Pin_6|GPIO_Pin_5|GPIO_Pin_7;
	
	GPIO_Inilize(GPIO_P0,&GPIOx);
}
