#include "key_s.h"

void Key_Init()//������ʼ��
{
	GPIO_InitTypeDef GPIOx;
	
	GPIOx.Mode=GPIO_OUT_PP;
	GPIOx.Pin=GPIO_Pin_0;	
	GPIO_Inilize(GPIO_P2,&GPIOx);
		
	
	GPIOx.Mode=GPIO_PullUp;
	GPIOx.Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;	
	GPIO_Inilize(GPIO_P4,&GPIOx);

	GPIOx.Mode=GPIO_PullUp;
	GPIOx.Pin=GPIO_Pin_6|GPIO_Pin_7;	
	GPIO_Inilize(GPIO_P3,&GPIOx);

}

//��ȡ������Ƶ
static u8 Key_Read(void)
{
    if(!READ_KEY1)  
		return KEY1_PRES;//0x01
    if(!READ_KEY2)  
		return KEY2_PRES;//0x02     
    if(!READ_KEY3)  
		return KEY3_PRES;//0x04
    if(!READ_KEY4)  
		return KEY4_PRES;//0x08
    if(!READ_KEY5)  
		return KEY5_PRES;//0x10		
    if(!READ_KEY6)  
		return KEY6_PRES;//0x20
	
	return KEY_NONE;
}

//״̬��
static u8 Key_Scan(void)
{
	static u8 state = 0; //������ʼ��״̬
	static u8 KEY_LAST=0,KEY_NOW=0; //��¼���ε�ƽ��״̬
	u8 KEY_VALUE=0;
 
	KEY_NOW = Key_Read();//��ȡ����
   
	switch(state)
	{
		case 0:
		{
			if(KEY_NOW != KEY_LAST)	state = 1; //�а�������
		}break;
		case 1: 
		{
			if(KEY_NOW == KEY_LAST)	state = 2; //����֮�󰴼���Ч
			else state = 0; //��Ϊ�ⴥ
		}break; 
		case 2: //����֮��
		{
			if(KEY_NOW == KEY_LAST) //���ǰ������µ�״̬
			{
			  	state = 3;//������״̬
			}
			else//�ɿ�
			{
				state = 0; 
				
				KEY_VALUE = KEY_LAST|KEY_SHORT;  //���ذ����̰���ֵ
			}
		}break;
		
		case 3: //�жϳ������Ƕ̰�
		{
			if(KEY_NOW == KEY_LAST) 
			{
			    static u8 cnt = 0;
				if(cnt++ > 120) //1200ms
				{
					cnt = 0; 
					state = 4;
					KEY_VALUE = KEY_LAST|KEY_LONG; //���ذ�������
				}			  
			}
			else
			{
				state = 0;
				KEY_VALUE = KEY_LAST|KEY_SHORT; //���򷵻ض̰�	
			}
		}break;
		case 4://��������Ƿ�����
		{
			if(KEY_NOW != KEY_LAST) 
				state = 5;
		}break;
		case 5://��������Ƿ�����
		{
			if(KEY_NOW == KEY_LAST) 
			{
			state = 0;
			return KEY_VALUE;//���ذ���ֵ
			}
		}break;
	}//switch
	
	KEY_LAST = KEY_NOW; //״̬���£�
	return KEY_VALUE;//���ذ���ֵ
}


/**************************************************************/
/*�������£��̰����ؼ���ֵ1 2 3 4 5 6���������ؼ���ֵ11 12 13 14 15 16 */
u8 Key_Hander(void)					
{
	u8 KEY_NUM=0;//��ȡ�ļ���ֵ
//	static u32 LAST=0;
//	if(Systick_ms-LAST<10)	return;
//	LAST = Systick_ms;	
	
	KEY_NUM = Key_Scan();  //��ȡ����ֵ
	if(KEY_NUM == KEY_NONE) return 0;//û�а������£�ֱ��return
	
	if(KEY_NUM & KEY_SHORT) //�������£�&�̰���ֵ������0���Ƕ̰���
	{    
		if(KEY_NUM & KEY1_PRES)//KEY1_PRES
		{				
			return 1;
		}
		else if(KEY_NUM & KEY2_PRES)//KEY2_PRES
		{
			return 2;
		}		
		else if(KEY_NUM & KEY3_PRES)//KEY3_PRES
		{
			return 3;
		}
		else if(KEY_NUM & KEY4_PRES)//KEY4_PRES
		{
			return 4;
		}
		else if(KEY_NUM & KEY5_PRES)//KEY5_PRES
		{
			return 5;
		}
		else if(KEY_NUM & KEY6_PRES)//KEY5_PRES
		{
			return 6;
		}
	}
	else if(KEY_NUM & KEY_LONG) //?? 
	{
		if(KEY_NUM & KEY1_PRES)//KEY1_PRES
		{
			return 11;
		}
		else if(KEY_NUM & KEY2_PRES)//KEY2_PRES
		{
			return 12;
		}		
		else if(KEY_NUM & KEY3_PRES)//KEY3_PRES
		{
			return 13;
		}
		else if(KEY_NUM & KEY4_PRES)//KEY4_PRES
		{
			return 14;
		}
		else if(KEY_NUM & KEY5_PRES)//KEY5_PRES
		{
			return 15;
		}
		else if(KEY_NUM & KEY6_PRES)//KEY5_PRES
		{
			return 16;
		}
	}	
	
	return 0;
}