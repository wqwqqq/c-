//ʵ�����ݣ�ѧϰIO��������ƣ�ʵ����˸�Ĺ���
//ʵ�����ڣ�2023-05-30

#include <STC32G.H>
#include <Delay.h>
#define MAIN_Fosc			24000000

sbit LED_L=P3^4;
sbit LED_R=P0^5;

//void main()
//{
//	EAXFR=1;
//	CKCON=0X00;
//	WTST=0X00;
//	
//	P0M0=0X20;//����P0�ڶ˿�ģʽ
//	P0M1=0X00;
//	
//	P3M0=0X10;
//	P3M1=0X00;
//	
//	while(1)
//	{
//		LED_L=1;
//		LED_R=1;
//		Delay(100);
//		LED_L=0;
//		LED_R=0;
//		Delay(100);
//		LED_L=1;
//		LED_R=1;
//		Delay(100);
//		LED_L=0;
//		LED_R=0;
//		Delay(100);
//		LED_L=1;
//		LED_R=1;
//		Delay(100);
//		LED_L=0;
//		LED_R=0;
//		Delay(100);
//		LED_L=1;
//		LED_R=1;
//		Delay(100);
//		LED_L=0;
//		LED_R=0;
//		Delay(100);
//		
//		LED_L=1;
//		LED_R=1;
//		Delay(500);
//		LED_L=0;
//		LED_R=0;
//		Delay(500);
//	}
//}

long a=0;

void main()
{
		EAXFR=1;
		CKCON=0X00;
		WTST=0X00;
		
		P0M0=0X20;//����P0�ڶ˿�ģʽ
		P0M1=0X00;
		
		P3M0=0X10;
		P3M1=0X00;
	
		while(1)
		{
			unsigned i=25535;
			while(a<9294960)//����ռ�ձ�Ϊ20���õ���ѭ�������������ڶ�ʱ����ɨ�裬���Ⱦͻ�ܵ�
			{
				a++;
				LED_L=1;
				LED_R=1;
				LED_L=0;
				LED_R=0;
				LED_L=0;
				LED_R=0;
				LED_L=0;
				LED_R=0;
				LED_L=0;
				LED_R=0;	
			}
			
			while(a--)//������ȣ�ʵ��Զ���
			{
				LED_L=1;
				LED_R=1;			
			}
		}

}