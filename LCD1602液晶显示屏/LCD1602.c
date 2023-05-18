#include <REGX52.H>

sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_E=P2^7;

#define LCD_DataPort P0

void LCD_Delay()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort=Command;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
	LCD_Delay();
}

void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort=Data;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
	LCD_Delay();
}

void LCD_Init()
{
	LCD_WriteCommand(0x38);//设置模式
	LCD_WriteCommand(0X0C);
	LCD_WriteCommand(0X06);
	LCD_WriteCommand(0X01);
}

void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}

}

void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}
	LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char* String)
{
		unsigned char i;
		if(Line==1)
		{
			LCD_WriteCommand(0x80|(Column-1));
		}
		else
		{
			LCD_WriteCommand(0x80|(Column-1)+0x40);
		}
		for(i=0;String[i]!=0;i++)
		{
			LCD_WriteData(String[i]);
		}
}

unsigned int pf(unsigned char x)
{
	unsigned int y=1;
	while(--x)//这里要--x,先--再使用
	{
		y*=10;
	}
	return y;
}

void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Num,unsigned char Lenth )
{
		unsigned char i;
		if(Line==1)
		{
			LCD_WriteCommand(0x80|(Column-1));
		}
		else
		{
			LCD_WriteCommand(0x80|(Column-1)+0x40);
		}
		for(i=0;i<Lenth;i++)
		{
			LCD_WriteData(Num/pf(Lenth-i)%10+0x30);
		}
}


/**********************显示无符号数字************************/
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Num,char Lenth)
{
	unsigned int Num1;
	unsigned char i;
	LCD_SetCursor(Line,Column);
	if(Num>=0)
	{
				LCD_WriteData('+');
				for(i=0;i<Lenth;i++)
				{
					LCD_WriteData(Num/pf(Lenth-i)%10+0x30);
				}

	}
	else
	{
		LCD_WriteData('-');
		Num1=-Num;
		for(i=0;i<Lenth;i++)
		{
			LCD_WriteData(Num1/pf(Lenth-i)%10+0x30);
		}
		
	}
}
/***************************************************************/
unsigned int pf1(unsigned char x)
{
	unsigned int y=1;
	while(--x)//这里要--x,先--再使用
	{
		y*=16;
	}
	return y;
}

void LCD_ShowHexNum(unsigned char Line,unsigned char Column,int Num,char Lenth)
{
	unsigned char i=0;
	unsigned char SingleNumber;
	LCD_SetCursor(Line,Column);
	for(i=0;i<Lenth;i++)
	{
		SingleNumber=Num/pf1(Lenth-i)%16;
		if(SingleNumber<10)
		{
			LCD_WriteData(SingleNumber+0x30);
		}
		else
		{		
			LCD_WriteData(SingleNumber+'A'-10);
		}
	}

}

int LCD_Pow(int X,int Y)
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}

void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number/LCD_Pow(2,i-1)%2+'0');
	}
}
