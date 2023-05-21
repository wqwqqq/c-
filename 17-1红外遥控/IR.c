#include <REGX52.H>
#include "Timer0.h"
#include "Int0.h"

unsigned int IR_Time;
unsigned char IR_State;

unsigned char IR_Data[4];
unsigned char IR_pData;

unsigned char IR_DataFalg;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;

void IR_Init()
{
	Timer_Init();
	Int0_Init();
}

unsigned char IR_GetDataFalg()
{
	if(IR_DataFlag)
	{
		IR_DataFlag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAddress()
{
	return IR_Address;
}

unsigned char IR_GetCommand()
{
	return IR_Command;
}

void Init0_Routine(void) interrupt 0
{
	if(IR_State==0)
	{
		Timer0_SetCounter(0);
		Timer0_Run();
		IR_State=1;
	}
	else if(IR_State==1)
	{
		IR_Time()=Timer0_GetCounter();
		Timer0_SteCounter(0);
		if(IR_Time>13500-500&&IR_Time<13500+500)
		{
			IR_State=2;
		}
		else if(IR_Time>11250-500&&IR_Time<11250+500)
		{
			IR_RepeaFlag=1;
			Timer0_Run(0);
			IR_State=0;
		}
		else
		{
			IR_State=1;
		}
	}
	else if(IR_State==2)
	{
		IR_Time=Time_GetCounter();
		Timer0_SetCounter(0);
		if(Timer>1120-500&&Timer<1120+500)
		{
			IR_Data[IR_pData/8]&=~(0x01<<(IR_pData%8));
			IR_pData++;
			//当IR_pData=0~7时数组的索引是0，也就是数组的第一个元素，后面是将这个数的位清0；
		}
		else if(Timer>2250-500&&Timer<2250+500)
		{		
			IR_Data[IR_pData/8]|=(0x01<<(IR_pData%8));
			IR_pData++;
		}
		else
		{
			IR_pData=0;
			IR_State=1;
		}
		
		if(IR_pData>=32)
		{
			IR_Address=IR_Data[0];			
			IR_Address=IR_Data[2];
			IR_DataFlag=1;
	}
		Timer0_Run(0);
		IR_State=0;
	}
}