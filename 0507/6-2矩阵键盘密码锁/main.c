#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned int Password;//定义输入的密码

//void main()
//{
//	unsigned char K=0,count=0;//获取的按键键码值，计次
//	LCD_Init();//初始化LCD显示屏
//	LCD_ShowString(1,1,"Passworld: ");//显示字符串
//	while(1)
//	{
//		K=MatrixKey();//获取按键值
//		if(K)
//		{
//				if(K<=10)//按键按s1-s10;
//				{
//					count++;//计次
//					if(count<=4)
//					{
//						Password*=10;//输入的密码值范围是0-9999
//						Password+=K%10;	
//					}
//						LCD_ShowNum(2,1,Password,4);		//显示输入的密码									
//				}
//				if(K==11)//清除输入密码的操作
//				{
//					Password=0;//输入密码清0
//					count=0;//计次清零
//					LCD_ShowNum(2,1,Password,4);//显示密码
//					LCD_ShowString(1,1,"Passworld:      ");//显示更新
//					
//				}
//				if(K==12)
//				{
//					if(Password==1234)//输入正确密码1234
//					{
//						LCD_ShowString(1,1,"Passworld:   ok");						
//						Password=0;
//						count=0;
//						LCD_ShowNum(2,1,Password,4);																	
//					}
//					else//否则显示错误，输入的密码清空
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
	unsigned char K=0,count=0;//获取的按键键码值，计次
	LCD_Init();//初始化LCD显示屏
	LCD_ShowString(1,1,"Passworld: ");//显示字符串
	while(1)
	{
		K=MatrixKey();//获取按键值
		if(K)
		{
				if(K<=10)//按键按s1-s10;
				{
					count++;//计次
					if(count<=4)
					{
						Password*=10;//输入的密码值范围是0-9999
						Password+=K%10;	
					}
//						LCD_ShowNum(2,1,Password,4);		//显示输入的密码									
				}
				if(K==11)//清除输入密码的操作
				{
					Password=0;//输入密码清0
					count=0;//计次清零
//					LCD_ShowNum(2,1,Password,4);//显示密码
					LCD_ShowString(1,1,"Passworld:      ");//显示更新
					
				}
				if(K==12)
				{
					if(Password==1234)//输入正确密码1234
					{
						LCD_ShowString(1,1,"Passworld:   ok");						
						Password=0;
						count=0;
//						LCD_ShowNum(2,1,Password,4);																	
					}
					else//否则显示错误，输入的密码清空
					{
						Password=0;
						LCD_ShowString(1,1,"Passworld:  err");//更新显示
						count=0;
//						LCD_ShowNum(2,1,Password,4);											
						
					}
				}
				LCD_ShowNum(2,1,Password,4);
		}
	}
}