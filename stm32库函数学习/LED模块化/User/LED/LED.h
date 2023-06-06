#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED_GPIO_PIN	GPIO_Pin_1

void LED_GPIO_Confing(void);
void LED_GPIO_High(void);
void LED_GPIO_Low(void);

#endif
