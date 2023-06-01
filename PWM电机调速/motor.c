#include "motor.h"

sbit LH_B=P2^0;
sbit LH_F=P2^1;

sbit RH_F=P2^2;
sbit RH_B=P2^3;

sbit RQ_F=P1^4;
sbit RQ_B=P1^5;

sbit LQ_F=P1^7;
sbit LQ_B=P1^6;

void Motor_Init()
{
	P2M0=0X0F;
	P2M1=0X00;
	
	P1M0=0Xf0;
	P1M1=0X00;
}

void Car_F()
	
{
	LH_B=1;
	LH_F=0;
	
	RH_F=0;
	RH_B=1;
	
	RQ_F=1;
	RQ_B=0;
	
	LQ_F=1;
	LQ_B=0;
}

void Car_Stop()
{
	LH_B=0;
	LH_F=0;
	     
	RH_F=0;
	RH_B=0;
	     
	RQ_F=0;
	RQ_B=0;
	     
	LQ_F=0;
	LQ_B=0;
	
}