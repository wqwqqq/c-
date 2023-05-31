#include <STC32G.H>
#include "LED.h"

void LED_Init()
{
	P0M0=0X20;//配置P0口端口模式
	P0M1=0X00;
	
	P3M0=0X10;
	P3M1=0X00;
}