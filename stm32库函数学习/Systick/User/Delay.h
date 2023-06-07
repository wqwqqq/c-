#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"                  // Device header

void Delay_us(uint32_t nus);
void Delay_ms(uint32_t nms);
void Delay_Init(void);

#endif
