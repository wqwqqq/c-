#include "config.h"

u8 num1,num2,gapvalue_flag;
extern u16 GapValue;

void write_eeprom()
{
	num1=GapValue/256;
	num2=GapValue%256;
	EEPROM_SectorErase(0x00);
	EEPROM_write_n(0x00,&num1,1);
	EEPROM_write_n(0x01,&num2,1);
	EEPROM_write_n(0x02,&gapvalue_flag,1);
}

void read_eeprom()
{
	EEPROM_read_n(0x00,&num1,1);
	EEPROM_read_n(0x01,&num2,1);
	EEPROM_read_n(0x02,&gapvalue_flag,1);
	
	GapValue=num1*256+num2;
}

void init_eeprom()
{
	read_eeprom();
	if(gapvalue_flag!=3)
	{
		GapValue=400;
		gapvalue_flag=3;
		write_eeprom();
	}
}