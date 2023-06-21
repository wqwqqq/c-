#include "HX711.h"



//****************************************************
//��ʱ����
//****************************************************
void Delay__hx711_us(void)
{
	_nop_();
	_nop_();
}

//*********************************************************
//��ʼ������
//*********************************************************
void HX711_Init()
{
	GPIO_InitTypeDef GPIOx;
	GPIOx.Mode=GPIO_OUT_PP;
	GPIOx.Pin=GPIO_Pin_4;	
	GPIO_Inilize(GPIO_P3,&GPIOx);
	
	GPIOx.Mode=GPIO_PullUp;
	GPIOx.Pin=GPIO_Pin_3;	
	GPIO_Inilize(GPIO_P3,&GPIOx);
}

//****************************************************
//��ȡHX711
//****************************************************
unsigned long HX711_Read(void)	//����128
{
	unsigned long count; 
	unsigned char i; 
  	HX711_DOUT=1; 
	Delay__hx711_us();
  	HX711_SCK=0; 
  	count=0;
	EA = 1; 
  	while(HX711_DOUT); 
	EA = 0;
  	for(i=0;i<24;i++)
	{ 
	  	HX711_SCK=1; 
	  	count=count<<1; 
		HX711_SCK=0; 
	  	if(HX711_DOUT)
			count++; 
	} 
 	HX711_SCK=1; 
    count=count^0x800000;//��25�������½�����ʱ��ת������
	Delay__hx711_us();
	HX711_SCK=0;  
	EA = 1; 

	return(count);
}






