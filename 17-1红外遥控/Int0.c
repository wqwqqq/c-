#include <REGX52.H>


void Int0_Init()
{
	IT0=1;//1λ�½��س�������0Ϊ�͵�ƽ����
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