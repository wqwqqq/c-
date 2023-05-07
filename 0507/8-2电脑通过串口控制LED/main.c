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
	if(RI==1)//判断是否是接收中断，接收中断就执行
	{
			P2=SBUF;//读出接收到的数据
			UART_SendByte(SBUF);//将读到的数据发送给电脑
			RI=0;//接收标志位需要由软件置0
	}
}