#include <REGX52.H>


void Int0_Init()
{
	IT0=1;//1位下降沿出触发，0为低电平触发
	IE0=0;
	EA=1;
	EX0=1;
	PX0=1;

}

/*
void Init0_Routine(void) interrupt 0
{
	Num++;
}

*/