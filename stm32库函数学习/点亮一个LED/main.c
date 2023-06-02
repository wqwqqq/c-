#include "stc32f10X.h"
#include "gpio.h"


int main()
{
	RCC_APB22ENR|=(1<4);//开启GPIO时钟
	
	//配置IO口模式
	GPIOC_CRH&=~(0x0f<<(4*5));//相应的位清零，第20-23位清零
	GPIOC_CRH|=(0x01<<(4*5));//操作相应的位置11

	GPIO_SetBits(GPIOC,GPIO_Pin_1);
	GPIO_ResetBits(GPIOC,GPIO_Pin_2);
	
	while(1)
	{
		
	}	
}

void SystemInit(void)
{

}
