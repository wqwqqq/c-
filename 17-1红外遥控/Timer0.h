#ifndef __TIMER0_H
#define __TIMER0_H

void Timer_Init(void);
void Timer0_Run(unsigned char Flag);
void Timer0_SetCounter(unsigned int Value);
unsigned int Timer0_GetCounter();

#endif