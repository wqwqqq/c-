#include "stm32f10x.h"                  // Device header

void My_USART_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	GPIO_InitTypeDef GPIO_Initsturct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_Initsturct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initsturct.GPIO_Pin=GPIO_Pin_9;
	GPIO_Initsturct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initsturct);
	
	GPIO_Initsturct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initsturct.GPIO_Pin=GPIO_Pin_10;
	GPIO_Initsturct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initsturct);
	
	USART_InitStruct.USART_BaudRate=9600;//波特率9600
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//硬件流控制，无
	USART_InitStruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_Parity=USART_Parity_No;//无校验
	USART_InitStruct.USART_StopBits=USART_StopBits_1;//一位停止位
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
	
	USART_Cmd(USART1,ENABLE);
}

void USART_SendByte(USART_TypeDef* USARTx, uint8_t Data)
{
  /* Check the parameters */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_DATA(Data)); 
    
  /* Transmit Data */
  USARTx->DR = Data;	
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
}

void USART_SendArr(USART_TypeDef* USARTx, uint8_t* arr)
{
	while(*arr!=0)
	{
		USART_SendByte(USARTx,*arr);
		arr++;
	}
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==0);
}

uint8_t USART_ReceiveByte(USART_TypeDef* USARTx)
{
  /* Check the parameters */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
	
//  while(USART_GetFlagStatus(USARTx,USART_FLAG_RXNE)==RESET);
  /* Receive Data */
  return USARTx->DR ;		
}

void USART1_IRQHandler(void)
{
	uint8_t temp;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
	{
		temp=USART_ReceiveByte(USART1);
		USART_SendByte(USART1,temp);
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}
