#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Int0.h"
#include "IR.h"

unsigned char Num;
unsigned char Address;
unsigned char Command;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADDR  CMD  NUM");
	LCD_ShowString(2,1,"00    00   000");
	
	IR_Init();
	
	while(1)
	{
		if(IR_GetDataFalg() || IR_GetRepeatFlag())	//??????????????
		{
			Address=IR_GetAddress();		//????????
			Command=IR_GetCommand();		//????????
			
			LCD_ShowHexNum(2,1,Address,2);	//????????
			LCD_ShowHexNum(2,7,Command,2);	//????????
			
			if(Command==IR_VOL_MINUS)		//?????VOL-????
			{
				Num--;						//Num??
			}
			if(Command==IR_VOL_ADD)			//?????VOL+????
			{
				Num++;						//Num??
			}
			
			LCD_ShowNum(2,12,Num,3);		//??Num
		}
	}
}

