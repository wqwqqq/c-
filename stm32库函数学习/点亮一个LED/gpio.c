#include "gpio.h"

void GPIO_SetBits(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRR|=GPIO_Pin;
	
//	GPIOx->BARR|=(1<<pin),GPIO_Pinx�൱������
}

void GPIO_ResetBits(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BRR|=GPIO_Pin;
	
//	GPIOx->BARR|=(1<<pin),GPIO_Pinx�൱������
}
