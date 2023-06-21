#include "config.h"
#include "TM1668.h"
#include "LED.h"

extern u8 Flag_ERROR;//称重状态标志位
extern u16 GapValue;//校准值
u8 Flag,num,Temp,Key,G_Flag=1,Buzzer_flag;//主函数中显示重量标志位，刷新时间标志位，
u8 epprom_add=0,read_add=0;//数据写地址，数据读地址
unsigned char count=0;

void Weight_DisPlay(long Weight_Shiwu)//重量显示函数，参数是出入的重量值，并根据称重状态标志位显示正负或其他
{			
			if(Weight_Shiwu<10000)//显示9.999kg——0kg
			{
			
			if(Flag_ERROR==0)//显示正数
			{
			TM1668_DisPlay(1,Weight_Shiwu%10);
			TM1668_DisPlay(2,Weight_Shiwu/10%10);
			TM1668_DisPlay(3,Weight_Shiwu/100%10);
			TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
			TM1668_DisPlay(5,21);
			TM1668_DisPlay(6,21);		
			}
			if(Flag_ERROR==2)//显示负数
			{
			TM1668_DisPlay(1,Weight_Shiwu%10);
			TM1668_DisPlay(2,Weight_Shiwu/10%10);
			TM1668_DisPlay(3,Weight_Shiwu/100%10);
			TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
			TM1668_DisPlay(5,20);
			TM1668_DisPlay(6,21);
			}
			}
			else if(Weight_Shiwu>=10000&&Weight_Shiwu<100000)//显示99.999kg-10.000kg
			{
				if(Flag_ERROR==0)//显示正数
				{
				TM1668_DisPlay(1,Weight_Shiwu%10);
				TM1668_DisPlay(2,Weight_Shiwu/10%10);
				TM1668_DisPlay(3,Weight_Shiwu/100%10);
				TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
				TM1668_DisPlay(5,Weight_Shiwu/10000%10);
				TM1668_DisPlay(6,21);		
				}
				if(Flag_ERROR==2)//显示负数
				{
				TM1668_DisPlay(1,Weight_Shiwu%10);
				TM1668_DisPlay(2,Weight_Shiwu/10%10);
				TM1668_DisPlay(3,Weight_Shiwu/100%10);
				TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
				TM1668_DisPlay(5,Weight_Shiwu/10000%10);
				TM1668_DisPlay(6,20);
				}
			}
		else if(Weight_Shiwu>=100000)//显示999.999kg-100.000kg
		{
				if(Flag_ERROR==0)
				{
				TM1668_DisPlay(1,Weight_Shiwu%10);
				TM1668_DisPlay(2,Weight_Shiwu/10%10);
				TM1668_DisPlay(3,Weight_Shiwu/100%10);
				TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
				TM1668_DisPlay(5,Weight_Shiwu/10000%10);
				TM1668_DisPlay(6,Weight_Shiwu/100000%10);		
				}
				if(Flag_ERROR==2)
				{
				TM1668_DisPlay(1,Weight_Shiwu/10%10);
				TM1668_DisPlay(2,Weight_Shiwu/100%10);
				TM1668_DisPlay(3,Weight_Shiwu/1000%10+10);
				TM1668_DisPlay(4,Weight_Shiwu/10000%10);
				TM1668_DisPlay(5,Weight_Shiwu/100000%10);
				TM1668_DisPlay(6,20);
				}
		
		}

}

//数据写，将重量的值写入eeprom里
void Weight_Write()
{
	char Data1,Data2,Data3,Data4,Data5,Data6;
	u8 signed_flag=0;
	long w=Get_Weight();
	signed_flag=Flag_ERROR;
	Data1=w%10;
	Data2=w/10%10;
	Data3=w/100%10;
	Data4=w/1000%10;
	Data5=w/10000%10;
	Data6=w/100000%10;
	EEPROM_Trig();
	EEPROM_write_n(0x0200+epprom_add,&Data1,1);
		delay_ms(10);
	EEPROM_write_n(0x0201+epprom_add,&Data2,1);
		delay_ms(10);
	EEPROM_write_n(0x0202+epprom_add,&Data3,1);
		delay_ms(10);
	EEPROM_write_n(0x0203+epprom_add,&Data4,1);
		delay_ms(10);
	EEPROM_write_n(0x0204+epprom_add,&Data5,1);
		delay_ms(10);
	EEPROM_write_n(0x0205+epprom_add,&Data6,1);
		delay_ms(10);
	EEPROM_write_n(0x0206+epprom_add,&signed_flag,1);
	epprom_add+=7;
//	TM1668_DisPlay(1,Data1);
//	TM1668_DisPlay(2,Data2);
//	TM1668_DisPlay(3,Data3);
//	TM1668_DisPlay(4,Data4);
//	TM1668_DisPlay(5,Data5);
//	TM1668_DisPlay(6,Data6);

	Weight_DisPlay(w);//显示要写入的值
	delay_255ms(2);
	TM1668_DisPlay(1,epprom_add/6%10);
	TM1668_DisPlay(2,epprom_add/6/10%10);
	TM1668_DisPlay(3,21);
	TM1668_DisPlay(4,21);
	TM1668_DisPlay(5,21);
	TM1668_DisPlay(6,21);		


}

//数据读，将eeprom中的值读出来
void Read_Weight()
{
		char Data1=0,Data2=0,Data3=0,Data4=0,Data5=0,Data6=0;
		u8 signed_flag=0;
		long w=0;
		if(read_add>=epprom_add)
		{
			read_add=0;
			if(read_add>=epprom_add)
			return;
		}

		EEPROM_Trig();
		EEPROM_read_n(0x0200+read_add,&Data1,1);
		delay_ms(10);
		EEPROM_read_n(0x0201+read_add,&Data2,1);
		delay_ms(10);
		EEPROM_read_n(0x0202+read_add,&Data3,1);
		delay_ms(10);
		EEPROM_read_n(0x0203+read_add,&Data4,1);
		delay_ms(10);
		EEPROM_read_n(0x0204+read_add,&Data5,1);
		delay_ms(10);
		EEPROM_read_n(0x0205+read_add,&Data6,1);
		delay_ms(10);
		EEPROM_read_n(0x0206+read_add,&signed_flag,1);
		read_add+=7;
	
		//显示存储的第几个值
		TM1668_DisPlay(1,read_add/6%10);
		TM1668_DisPlay(2,read_add/6/10%10);
		TM1668_DisPlay(3,21);
		TM1668_DisPlay(4,21);
		TM1668_DisPlay(5,21);
		TM1668_DisPlay(6,21);		
		w=Data1+Data2*10+Data3*100+Data4*1000+Data5*10000+Data6*100000;
		delay_255ms(2);
		Flag_ERROR=signed_flag;
		Weight_DisPlay(w);//显示要读初的值
//		TM1668_DisPlay(1,Data1);
//		TM1668_DisPlay(2,Data2);
//		TM1668_DisPlay(3,Data3);
//		TM1668_DisPlay(4,Data4);
//		TM1668_DisPlay(5,Data5);
//		TM1668_DisPlay(6,Data6);		
}

//开机显示动画
void menu()
{
	u8 i=0;
	TM1668_DisPlay(6,22);
	TM1668_DisPlay(5,2);
	TM1668_DisPlay(4,2);
	TM1668_DisPlay(3,1);
	TM1668_DisPlay(2,1);
	TM1668_DisPlay(1,1);
	delay_255ms(6);
	TM1668_DisPlay(6,5);
	TM1668_DisPlay(5,0);
	TM1668_DisPlay(4,0);
	TM1668_DisPlay(3,0);
	TM1668_DisPlay(2,0);
	TM1668_DisPlay(1,0);
	delay_255ms(6);
	for(i=0;i<10;i++)
	{
		TM1668_DisPlay(6,19-i);
		TM1668_DisPlay(5,19-i);
		TM1668_DisPlay(4,19-i);
		TM1668_DisPlay(3,19-i);
		TM1668_DisPlay(2,19-i);
		TM1668_DisPlay(1,19-i);
		if(i<9)
		{
		delay_255ms(2);		
		}
	}

}

int main()
{
	long Weight_Shiwu=0;//获取实物的变量
	Buzzer_Init();//蜂鸣器初始化
	Key_Init();//按键初始化
	TM1668_Init();//TM1668初始化
	LED_Init();//LED初始化
	P45=1;//上电蜂鸣器响，表示按键按下
	delay_255ms(1);
	P45=0;

	menu();//显示菜单
	Timer0_Init();//定时器初始化
	EA=1;//开启中断
	init_eeprom();//eeprom初始化
	HX711_Init();//HX711初始化
	delay_255ms(2);	//延迟
	Get_Maopi();//Get_Maopi();//除皮
	delay_255ms(2);
	TM1668_DisPlay(7,18);//

	while(1)
	{

		Get_Weight();//得到重量
		num++;//
		if(num>=10){num=0;Flag=0;}
		if(Flag==0&&G_Flag==1)
		{	
			Weight_Shiwu=Get_Weight();

			Weight_DisPlay(Weight_Shiwu);			
		}
		
		else if(Flag==1&&G_Flag==0)
		{
			TM1668_DisPlay(1,GapValue%10);
			TM1668_DisPlay(2,GapValue/10%10);
			TM1668_DisPlay(3,GapValue/100%10);
			TM1668_DisPlay(4,21);
			TM1668_DisPlay(5,21);
			TM1668_DisPlay(6,21);
		}
		
/***********************按下按键开关按键打开关闭***************************************/
		if(Temp==1)
		{
//			Buzzer_flag=2;
//			P45=1;
			Temp=0;
		}
/************************按下计数，开始计数*****************************************/
		if(Temp==2)
		{
			Buzzer_flag=2;
			P45=1;
			Weight_Write();
			Flag=1;num=0;			
			Temp=0;		
		}
/*************************按下累计读取计数的值，当长按功能键可以加校准值****************************************/
		if(Temp==3)
		{
			Buzzer_flag=1;
			P45=1;
			Read_Weight();	
			Flag=1;num=0;				
			Temp=0;
		}
/********************长按后，进入调整校准值界面，短按减校准值*********************************************/
		if(Temp==4)
		{
			Buzzer_flag=1;
			P45=1;
			if(G_Flag==0)
			{
				Flag=1;num=0;				
				if(GapValue>0)
				{
					GapValue--;
				}
				else if(GapValue>999)
				{
				GapValue=0;
				}
				write_eeprom();
			}

			Temp=0;
		}
/************************按键去皮*****************************************/
		if(Temp==5)
		{
/************长按功能按键*************************************************************/			
			Buzzer_flag=1;
			P45=1;
			if(G_Flag==0)
			{
				Flag=1;num=0;
				if(GapValue<999)
				{
					GapValue++;
				}
				else if(GapValue>999)
				{
					GapValue=0;
				}
			}
/*************************************************************************/			
			else
			Get_Maopi();
			Temp=0;
		}
/************************按键置0*****************************************/
		if(Temp==6)
		{
			Buzzer_flag=1;
			P45=1;
			read_add=0;
			epprom_add=0;
			EEPROM_Trig();

			delay_ms(10);
			EEPROM_SectorErase(0x0200);
			delay_ms(10);

			Temp=0;
		}
/*****************************************************************/
		if(Temp==11)
		{
			Buzzer_flag=2;
			P45=1;
			Flag=1;G_Flag=2;
			
			EEPROM_Trig();
			delay_ms(10);
			EEPROM_SectorErase(0x0200);
			delay_ms(10);
			
			TM1668_DisPlay(1,21);
			TM1668_DisPlay(2,21);
			TM1668_DisPlay(3,21);
			TM1668_DisPlay(4,21);
			TM1668_DisPlay(5,21);
			TM1668_DisPlay(6,21);
			P20=!P20;
			Temp=0;
		}
/*****************************************************************/
		if(Temp==12)
		{
			Temp=0;
		}
/*****************************************************************/
		if(Temp==13)
		{
			
			Temp=0;
		}
/*****************************************************************/
		if(Temp==14)
		{
			Buzzer_flag=2;
			P45=1;
			Flag=1;num=0;G_Flag=!G_Flag;
			Temp=0;
		}
/*****************************************************************/
		if(Temp==15)
		{
			Temp=0;
		}
/*****************************************************************/
		if(Temp==16)
		{
			Temp=0;
		}
		
		delay_ms(200);
	}
	
	
}

/********************* Timer0中断函数************************/
void timer0_int (void) interrupt TIMER0_VECTOR
{
	static unsigned int i,j;
	if(Buzzer_flag==1)
	{
		j=200;
		Buzzer_flag=0;
	}
	if(Buzzer_flag==2)
	{
		j=0;
		Buzzer_flag=0;
	}
	
	i++;j++;
	if(i>20)
	{
		Key=Key_Hander();
		i=0;
		if(Key)
		{
			Temp=Key;
		}
	}
	
	if(j>400)
	{
		j=0;
		P45=0;
	}
}
