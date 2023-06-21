#ifndef __KEY_S_H
#define __KEY_S_H
#include	"config.h"
 
sbit READ_KEY1=P4^4;
sbit READ_KEY2=P4^3;
sbit READ_KEY3=P4^2;
sbit READ_KEY4=P4^1;
sbit READ_KEY5=P3^7;
sbit READ_KEY6=P3^6; 
 
//#define READ_KEY1	P30
//#define READ_KEY2	P14
//#define READ_KEY3	P13
//#define READ_KEY4	P10
//#define READ_KEY5	P17
 
#define KEY1_PRES 0x01
#define KEY2_PRES 0x02
#define KEY3_PRES 0x04
#define KEY4_PRES 0x08
#define KEY5_PRES 0x10
#define KEY6_PRES 0x20
 
#define KEY_SHORT  0x40
#define KEY_LONG   0x80
#define KEY_NONE      0
 
 
void Key_Init();
u8 Key_Hander(void)	;
 
#endif
 
/*********************************************END OF FILE**********************************************/
 