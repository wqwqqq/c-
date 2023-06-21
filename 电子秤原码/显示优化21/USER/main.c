#include "config.h"
#include "TM1668.h"
#include "LED.h"

extern u8 Flag_ERROR;//����״̬��־λ
extern u16 GapValue;//У׼ֵ
u8 Flag,num,Temp,Key,G_Flag=1,Buzzer_flag;//����������ʾ������־λ��ˢ��ʱ���־λ��
u8 epprom_add=0,read_add=0;//����д��ַ�����ݶ���ַ
unsigned char count=0;

void Weight_DisPlay(long Weight_Shiwu)//������ʾ�����������ǳ��������ֵ�������ݳ���״̬��־λ��ʾ����������
{			
			if(Weight_Shiwu<10000)//��ʾ9.999kg����0kg
			{
			
			if(Flag_ERROR==0)//��ʾ����
			{
			TM1668_DisPlay(1,Weight_Shiwu%10);
			TM1668_DisPlay(2,Weight_Shiwu/10%10);
			TM1668_DisPlay(3,Weight_Shiwu/100%10);
			TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
			TM1668_DisPlay(5,21);
			TM1668_DisPlay(6,21);		
			}
			if(Flag_ERROR==2)//��ʾ����
			{
			TM1668_DisPlay(1,Weight_Shiwu%10);
			TM1668_DisPlay(2,Weight_Shiwu/10%10);
			TM1668_DisPlay(3,Weight_Shiwu/100%10);
			TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
			TM1668_DisPlay(5,20);
			TM1668_DisPlay(6,21);
			}
			}
			else if(Weight_Shiwu>=10000&&Weight_Shiwu<100000)//��ʾ99.999kg-10.000kg
			{
				if(Flag_ERROR==0)//��ʾ����
				{
				TM1668_DisPlay(1,Weight_Shiwu%10);
				TM1668_DisPlay(2,Weight_Shiwu/10%10);
				TM1668_DisPlay(3,Weight_Shiwu/100%10);
				TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
				TM1668_DisPlay(5,Weight_Shiwu/10000%10);
				TM1668_DisPlay(6,21);		
				}
				if(Flag_ERROR==2)//��ʾ����
				{
				TM1668_DisPlay(1,Weight_Shiwu%10);
				TM1668_DisPlay(2,Weight_Shiwu/10%10);
				TM1668_DisPlay(3,Weight_Shiwu/100%10);
				TM1668_DisPlay(4,Weight_Shiwu/1000%10+10);
				TM1668_DisPlay(5,Weight_Shiwu/10000%10);
				TM1668_DisPlay(6,20);
				}
			}
		else if(Weight_Shiwu>=100000)//��ʾ999.999kg-100.000kg
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

//����д����������ֵд��eeprom��
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

	Weight_DisPlay(w);//��ʾҪд���ֵ
	delay_255ms(2);
	TM1668_DisPlay(1,epprom_add/6%10);
	TM1668_DisPlay(2,epprom_add/6/10%10);
	TM1668_DisPlay(3,21);
	TM1668_DisPlay(4,21);
	TM1668_DisPlay(5,21);
	TM1668_DisPlay(6,21);		


}

//���ݶ�����eeprom�е�ֵ������
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
	
		//��ʾ�洢�ĵڼ���ֵ
		TM1668_DisPlay(1,read_add/6%10);
		TM1668_DisPlay(2,read_add/6/10%10);
		TM1668_DisPlay(3,21);
		TM1668_DisPlay(4,21);
		TM1668_DisPlay(5,21);
		TM1668_DisPlay(6,21);		
		w=Data1+Data2*10+Data3*100+Data4*1000+Data5*10000+Data6*100000;
		delay_255ms(2);
		Flag_ERROR=signed_flag;
		Weight_DisPlay(w);//��ʾҪ������ֵ
//		TM1668_DisPlay(1,Data1);
//		TM1668_DisPlay(2,Data2);
//		TM1668_DisPlay(3,Data3);
//		TM1668_DisPlay(4,Data4);
//		TM1668_DisPlay(5,Data5);
//		TM1668_DisPlay(6,Data6);		
}

//������ʾ����
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
	long Weight_Shiwu=0;//��ȡʵ��ı���
	Buzzer_Init();//��������ʼ��
	Key_Init();//������ʼ��
	TM1668_Init();//TM1668��ʼ��
	LED_Init();//LED��ʼ��
	P45=1;//�ϵ�������죬��ʾ��������
	delay_255ms(1);
	P45=0;

	menu();//��ʾ�˵�
	Timer0_Init();//��ʱ����ʼ��
	EA=1;//�����ж�
	init_eeprom();//eeprom��ʼ��
	HX711_Init();//HX711��ʼ��
	delay_255ms(2);	//�ӳ�
	Get_Maopi();//Get_Maopi();//��Ƥ
	delay_255ms(2);
	TM1668_DisPlay(7,18);//

	while(1)
	{

		Get_Weight();//�õ�����
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
		
/***********************���°������ذ����򿪹ر�***************************************/
		if(Temp==1)
		{
//			Buzzer_flag=2;
//			P45=1;
			Temp=0;
		}
/************************���¼�������ʼ����*****************************************/
		if(Temp==2)
		{
			Buzzer_flag=2;
			P45=1;
			Weight_Write();
			Flag=1;num=0;			
			Temp=0;		
		}
/*************************�����ۼƶ�ȡ������ֵ�����������ܼ����Լ�У׼ֵ****************************************/
		if(Temp==3)
		{
			Buzzer_flag=1;
			P45=1;
			Read_Weight();	
			Flag=1;num=0;				
			Temp=0;
		}
/********************�����󣬽������У׼ֵ���棬�̰���У׼ֵ*********************************************/
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
/************************����ȥƤ*****************************************/
		if(Temp==5)
		{
/************�������ܰ���*************************************************************/			
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
/************************������0*****************************************/
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

/********************* Timer0�жϺ���************************/
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
