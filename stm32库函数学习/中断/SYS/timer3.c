#include "timer3.h"
#include "led.h"
/********************
①能定时器时钟。
RCC_APB1PeriphClockCmd();
②  初始化定时器，配置ARR,PSC。
TIM_TimeBaseInit();
③开启定时器中断，配置NVIC。
void TIM_ITConfig();
NVIC_Init();
④使能定时器。
TIM_Cmd();
⑥编写中断服务函数。
TIMx_IRQHandler();
*****************/

uint8_t Flag;

void TIM3_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
	
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
			
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分租
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStructure);
	
	

	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设
	
}

void TIM3_IRQHandler(void)   //TIM3中断
{
	
	
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
		{
			Flag=!Flag;
			if(Flag)
			{
				LED_GPIO_High();
			}
			else
			{
				LED_GPIO_Low();
			}
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //清除TIMx的中断待处理位:TIM 中断源 
			
		}
}



