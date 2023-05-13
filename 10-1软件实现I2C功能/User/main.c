#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MyI2C.h"

int main()
{
	OLED_Init();
	MyI2C_Init();
	MyI2C_Start();
	MyI2C_SendByte(0xd2);
	uint8_t a=MyI2C_ReceiveAck();
	MyI2C_Stop();
	OLED_ShowNum(1,1,a,3);
	while(1)
	{
	}
}
