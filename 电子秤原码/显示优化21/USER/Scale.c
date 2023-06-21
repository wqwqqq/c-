#include "Scale.h"
#include "stdlib.h"

long Weight_Maopi;
u8 Flag_ERROR;
u16 GapValue=400;

//****************************************************
//����
//****************************************************
long Get_Weight()
{
	long Weight_Shiwu=0,Weight_Temp=0;;
	Weight_Shiwu = HX711_Read();
	if(Weight_Shiwu<(Weight_Maopi-10))
	{
		Weight_Shiwu=Weight_Maopi-Weight_Shiwu;
		Flag_ERROR=2;
	}
	else if(Weight_Shiwu>=Weight_Maopi-10)
	{
		Weight_Shiwu = Weight_Shiwu - Weight_Maopi;		//��ȡ����
		Flag_ERROR = 0;
	}
	
	
		Weight_Shiwu = (unsigned long)(((float)Weight_Shiwu*25)/GapValue); 	//����ʵ���ʵ������
																		
		if(Weight_Shiwu > 500000)		//���ر���
		{
			Flag_ERROR = 1;
		}
		else
		{			
			if(Weight_Shiwu%10>5)
			{
				Weight_Shiwu=((Weight_Shiwu/10)*10)+5;
			}
			else
			{
				Weight_Shiwu=((Weight_Shiwu/10)*10);
			}
			
			if(Weight_Shiwu%10==0&&Weight_Shiwu/10%10==0&&Weight_Shiwu/100%10==0&&Weight_Shiwu/1000%10==0&&Weight_Shiwu/10000%10==0&&Weight_Shiwu/100000%10==0)																
			{
				Flag_ERROR = 0;				
			}
			return Weight_Shiwu;
		}
	Flag_ERROR=0;
	return 0;
}

//****************************************************
//��ȡëƤ����
//****************************************************
void Get_Maopi()
{	
	Weight_Maopi = HX711_Read();
} 
