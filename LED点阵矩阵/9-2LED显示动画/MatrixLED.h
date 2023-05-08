#ifndef __MATRIXLED_H
#define __MATRIXLED_H

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

void MatrixLED_Init(void);
void _74HC595_WriteByte(unsigned char Byte);
void MatrixLed_ShowColumn(unsigned char Colum,Data);

#endif