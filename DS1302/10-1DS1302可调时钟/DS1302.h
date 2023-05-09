#ifndef __DS1302_H
#define __DS1302_H

//extern unsigned char DS1302_Time[]={23,5,8,22,12,50,10,1};

void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command,Data);
unsigned char DS1302_ReadByte(unsigned char Comand);
void DS1302_ReadTime(void);
void Ds1302_SetTime(void);

#endif