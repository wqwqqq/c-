#include <STC32G.H>
#include "Delay.h"

sbit KEY_N=P3^7;

void Key_Init()
{
	EAXFR=1;
	CKCON=0X00;
	WTST=0X00;
	
	P3M0=0X10;//配置P0口端口模式
	P3M1=0X80;
	
	P3PU=0x80;//配置上拉电阻
	
}

unsigned char Key()
{
	unsigned char K=0; 
	if(KEY_N==0){Delay(10);while(KEY_N==0);Delay(10);K=1;}
	return K;
}