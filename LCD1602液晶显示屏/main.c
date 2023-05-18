#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main()
{
	unsigned char arr[]={'a','b','c'};
	LCD_Init();
	LCD_ShowChar(1,1,'A');
	LCD_ShowString(2,1,arr);
	LCD_ShowNum(1,2,23,5);
	LCD_ShowSignedNum(1,9,-5,2);
	LCD_ShowHexNum(1,13,0XAA,2);
	LCD_ShowBinNum(2,5,134,6);
	LCD_ShowString(1,16,"Welcome to China!");
	while(1)
	{
		LCD_WriteCommand(0x18);
		Delay(1000);
	}
}