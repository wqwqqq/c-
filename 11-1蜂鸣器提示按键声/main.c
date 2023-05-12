#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"

unsigned char K;

void main()
{
	unsigned int i=0;
	Nixie(1,0);

	while(1)
	{
		K=Key();
		if(K)
		{
			Buzzer_Time(100);//��������������Ϸ�ת�������ĸߵ͵�ƽʹ����������
			Nixie(1,K);
		}
	}
}

