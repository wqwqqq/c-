#include <REGX52.H>
#include "Delay.h"

unsigned char KK;

unsigned char Key()
{
	unsigned char Temp=0;
	Temp=KK;
	KK=0;
	return Temp;
}

unsigned char KeyGet()
{
	unsigned char KeyNumber=0;
	
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){KeyNumber=3;}
	if(P3_3==0){KeyNumber=4;}
	
	return KeyNumber;
}

void Key_Loop(void)
{
	static unsigned char NOW,LAST;
	LAST=NOW;
	NOW=KeyGet();
	if(LAST==1&&NOW==0){KK=1;}
	if(LAST==2&&NOW==0){KK=2;}
	if(LAST==3&&NOW==0){KK=3;}
	if(LAST==4&&NOW==0){KK=4;}
}