#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;

void main()
{
	UART_Init();
	while(1)
	{
//		UART_SendByte(Sec);
//		Sec++;
//		Delay(1000);
//		UART_SendByte(0x66);
//		Delay(1);
	}
}

void UART_Routine() interrupt 4
{
	if(RI==1)//�ж��Ƿ��ǽ����жϣ������жϾ�ִ��
	{
			P2=SBUF;//�������յ�������
			UART_SendByte(SBUF);//�����������ݷ��͸�����
			RI=0;//���ձ�־λ��Ҫ�������0
	}
}