#ifndef __LCD1602_H
#define __LCD1602_H

void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char* String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Num,unsigned char Lenth );
unsigned int pf(unsigned char x);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Num,char Lenth);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,int Num,char Lenth);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_WriteCommand(unsigned char Command);


#endif