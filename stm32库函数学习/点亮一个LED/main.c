#include "stc32f10X.h"
#include "gpio.h"


int main()
{
	RCC_APB22ENR|=(1<4);//����GPIOʱ��
	
	//����IO��ģʽ
	GPIOC_CRH&=~(0x0f<<(4*5));//��Ӧ��λ���㣬��20-23λ����
	GPIOC_CRH|=(0x01<<(4*5));//������Ӧ��λ��11

	GPIO_SetBits(GPIOC,GPIO_Pin_1);
	GPIO_ResetBits(GPIOC,GPIO_Pin_2);
	
	while(1)
	{
		
	}	
}

void SystemInit(void)
{

}
