#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned int Password;//�������������

//void main()
//{
//	unsigned char K=0,count=0;//��ȡ�İ�������ֵ���ƴ�
//	LCD_Init();//��ʼ��LCD��ʾ��
//	LCD_ShowString(1,1,"Passworld: ");//��ʾ�ַ���
//	while(1)
//	{
//		K=MatrixKey();//��ȡ����ֵ
//		if(K)
//		{
//				if(K<=10)//������s1-s10;
//				{
//					count++;//�ƴ�
//					if(count<=4)
//					{
//						Password*=10;//���������ֵ��Χ��0-9999
//						Password+=K%10;	
//					}
//						LCD_ShowNum(2,1,Password,4);		//��ʾ���������									
//				}
//				if(K==11)//�����������Ĳ���
//				{
//					Password=0;//����������0
//					count=0;//�ƴ�����
//					LCD_ShowNum(2,1,Password,4);//��ʾ����
//					LCD_ShowString(1,1,"Passworld:      ");//��ʾ����
//					
//				}
//				if(K==12)
//				{
//					if(Password==1234)//������ȷ����1234
//					{
//						LCD_ShowString(1,1,"Passworld:   ok");						
//						Password=0;
//						count=0;
//						LCD_ShowNum(2,1,Password,4);																	
//					}
//					else//������ʾ����������������
//					{
//						Password=0;
//						LCD_ShowString(1,1,"Passworld:  err");
//						count=0;
//						LCD_ShowNum(2,1,Password,4);											
//						
//					}
//				}
//		}
//	}
//}

void main()
{
	unsigned char K=0,count=0;//��ȡ�İ�������ֵ���ƴ�
	LCD_Init();//��ʼ��LCD��ʾ��
	LCD_ShowString(1,1,"Passworld: ");//��ʾ�ַ���
	while(1)
	{
		K=MatrixKey();//��ȡ����ֵ
		if(K)
		{
				if(K<=10)//������s1-s10;
				{
					count++;//�ƴ�
					if(count<=4)
					{
						Password*=10;//���������ֵ��Χ��0-9999
						Password+=K%10;	
					}
//						LCD_ShowNum(2,1,Password,4);		//��ʾ���������									
				}
				if(K==11)//�����������Ĳ���
				{
					Password=0;//����������0
					count=0;//�ƴ�����
//					LCD_ShowNum(2,1,Password,4);//��ʾ����
					LCD_ShowString(1,1,"Passworld:      ");//��ʾ����
					
				}
				if(K==12)
				{
					if(Password==1234)//������ȷ����1234
					{
						LCD_ShowString(1,1,"Passworld:   ok");						
						Password=0;
						count=0;
//						LCD_ShowNum(2,1,Password,4);																	
					}
					else//������ʾ����������������
					{
						Password=0;
						LCD_ShowString(1,1,"Passworld:  err");//������ʾ
						count=0;
//						LCD_ShowNum(2,1,Password,4);											
						
					}
				}
				LCD_ShowNum(2,1,Password,4);
		}
	}
}