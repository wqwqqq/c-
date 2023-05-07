#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

void main()
{
	unsigned char K=0;
	LCD_Init();
	LCD_ShowString(1,1,"hello wangquanwu");
	while(1)
	{
		K=MatrixKey();
		if(K)
		{
			LCD_ShowNum(2,2,K,2);
		}
	}
}