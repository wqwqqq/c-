#ifndef __HX711_H__
#define __HX711_H__

#include "config.h"
#include <intrins.h>

//IO����
sbit HX711_DOUT=P3^3; 
sbit HX711_SCK=P3^4; 

//�������߱�������
extern void Delay__hx711_us(void);
extern unsigned long HX711_Read(void);
void HX711_Init();

#endif