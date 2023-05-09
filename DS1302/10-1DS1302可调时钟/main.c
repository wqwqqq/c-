#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
#include "Key.h"
#include "Timer0.h"

extern unsigned char DS1302_Time[];
unsigned char MODE,TimeSetSelect,K;
bit FLAG;

void TimeShow()
{
		DS1302_ReadTime();
		LCD_ShowNum(1,1,DS1302_Time[0],2);
		LCD_ShowNum(1,4,DS1302_Time[1],2);
		LCD_ShowNum(1,7,DS1302_Time[2],2);
		LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,4,DS1302_Time[4],2);
		LCD_ShowNum(2,7,DS1302_Time[5],2);

}

void TimeSet()
{
	if(K==2)
	{
		TimeSetSelect++;
		TimeSetSelect%=6;
	}
	if(K==3)
	{
		DS1302_Time[TimeSetSelect]++;
		if(DS1302_Time[0]>99){DS1302_Time[0]=1;}
		if(DS1302_Time[1]>12){DS1302_Time[1]=1;}
		if(DS1302_Time[1]==1||DS1302_Time[1]==3||DS1302_Time[1]==5||DS1302_Time[1]==6||DS1302_Time[1]==8||DS1302_Time[1]==10||DS1302_Time[1]==12)
		{
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}
		}
		if(DS1302_Time[1]==4||DS1302_Time[1]==7||DS1302_Time[1]==9||DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		if(DS1302_Time[1]==2&&DS1302_Time[0]%4==0)
		{
			if(DS1302_Time[2]>29){DS1302_Time[2]=1;}			
		}
		if(DS1302_Time[1]==2&&DS1302_Time[0]%4!=0)
		{
			if(DS1302_Time[2]>28){DS1302_Time[2]=1;}					
		}
		if(DS1302_Time[3]>=24){DS1302_Time[3]=0;}
		if(DS1302_Time[4]>=60){DS1302_Time[4]=0;}
		if(DS1302_Time[5]>=60){DS1302_Time[5]=0;}
	}
		if(K==4)
	{
		DS1302_Time[TimeSetSelect]--;
		if(DS1302_Time[0]<1){DS1302_Time[0]=99;}
		if(DS1302_Time[1]<1){DS1302_Time[1]=12;}
		if(DS1302_Time[1]==1||DS1302_Time[1]==3||DS1302_Time[1]==5||DS1302_Time[1]==7||DS1302_Time[1]==8||DS1302_Time[1]==10||DS1302_Time[1]==12)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=31;}
		}
		if(DS1302_Time[1]==4||DS1302_Time[1]==6||DS1302_Time[1]==9||DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=30;}
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}

		}
		if(DS1302_Time[1]==2&&DS1302_Time[0]%4==0)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=29;}			
			if(DS1302_Time[2]>29){DS1302_Time[2]=1;}			
		}
		if(DS1302_Time[1]==2&&DS1302_Time[0]%4!=0)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=28;}					
			if(DS1302_Time[2]>28){DS1302_Time[2]=1;}					
		}
		if(DS1302_Time[3]>24){DS1302_Time[3]=23;}
		if(DS1302_Time[4]>60){DS1302_Time[4]=59;}
		if(DS1302_Time[5]>60){DS1302_Time[5]=59;}
		
	}
			if(FLAG==0&&TimeSetSelect==0){LCD_ShowString(1,1,"  ");}
			else LCD_ShowNum(1,1,DS1302_Time[0],2);
			
			if(FLAG==0&&TimeSetSelect==1){LCD_ShowString(1,4,"  ");}
			else LCD_ShowNum(1,4,DS1302_Time[1],2);
			
			if(FLAG==0&&TimeSetSelect==2){LCD_ShowString(1,7,"  ");}
			else LCD_ShowNum(1,7,DS1302_Time[2],2);
			
			if(FLAG==0&&TimeSetSelect==3){LCD_ShowString(2,1,"  ");}
			else LCD_ShowNum(2,1,DS1302_Time[3],2);
			
			if(FLAG==0&&TimeSetSelect==4){LCD_ShowString(2,4,"  ");}
			else LCD_ShowNum(2,4,DS1302_Time[4],2);
			
			if(FLAG==0&&TimeSetSelect==5){LCD_ShowString(2,7,"  ");}
			else LCD_ShowNum(2,7,DS1302_Time[5],2);

}

void main()
{
	Timer_Init();
	LCD_Init();
	DS1302_Init();	
	Ds1302_SetTime();
	LCD_ShowString(1,3,"-  -  ");
	LCD_ShowString(2,3,":  :  ");
	
	while(1)
	{	
		K=Key();
		if(K==1)
		{
			if(MODE==1){MODE=0;Ds1302_SetTime();}
			else if(MODE==0){MODE=1;TimeSetSelect=0;}
		}
		if(MODE==1)
		{
			TimeSet();
		}
		else if(MODE==0)
		{

			TimeShow();
		}
		
	}
}

void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=64535/256;
		TL0=64535%256;
		count++;
		if(count>400)
		{
					count=0;
					FLAG=!FLAG;
		}


}