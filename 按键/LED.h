#ifndef __LED_H
#define __LED_H

sbit LED_L=P3^4;
sbit LED_R=P0^5;

void LED_Init();

#endif