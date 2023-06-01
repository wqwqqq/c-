#include <STC32G.H>

void Delay(unsigned int xms)		//@24.000MHz
{
	unsigned long i;
	while(xms--)
	{	
		_nop_();
		_nop_();
		_nop_();
		i = 5998UL;
		while (i) i--;
	}
}
