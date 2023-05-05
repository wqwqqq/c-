#include <REGX52.H>

void Delay(unsigned int ms)		//@12.000MHz
{
	
	unsigned char i, j;

	while(ms--)
	{
	i = 195;
	j = 138;
	do
	{
		while (--j);
	} while (--i);	
	}
}


void main()
{
	
	while(1)
	{
		P2=~0X01;
		Delay(10);
		P2=0XFF;
		Delay(10);
	}
}