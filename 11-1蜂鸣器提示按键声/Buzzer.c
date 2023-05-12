#include <REGX52.H>
#include "Delay.h"
#include <INTRINS.H>

sbit Buzzer=P1^5;

void Delay500us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 247;
	while (--i);
}

/**
	* 	@brief	蜂鸣器响的时间
	* 	@param	ms发声的时间
	* 	@retval	无
*/
void Buzzer_Time(unsigned int ms)
{
		unsigned int i;
		for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Delay500us();
	}

}
