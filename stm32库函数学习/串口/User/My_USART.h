#ifndef __MY_USART_H
#define __MY_USART_H

void USART_SendByte(USART_TypeDef* USARTx, uint16_t Data);
void My_USART_Init(void);
void USART_SendArr(USART_TypeDef* USARTx, uint8_t* arr);

#endif
