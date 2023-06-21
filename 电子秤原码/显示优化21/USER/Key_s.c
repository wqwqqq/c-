#include "key_s.h"

void Key_Init()//按键初始化
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

//读取按键电频
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

//状态机
static u8 Key_Scan(void)
{
	static u8 state = 0; //按键初始化状态
	static u8 KEY_LAST=0,KEY_NOW=0; //记录两次电平的状态
	u8 KEY_VALUE=0;
 
	KEY_NOW = Key_Read();//读取按键
   
	switch(state)
	{
		case 0:
		{
			if(KEY_NOW != KEY_LAST)	state = 1; //有按键按下
		}break;
		case 1: 
		{
			if(KEY_NOW == KEY_LAST)	state = 2; //消抖之后按键有效
			else state = 0; //认为吴触
		}break; 
		case 2: //消抖之后
		{
			if(KEY_NOW == KEY_LAST) //还是按键按下的状态
			{
			  	state = 3;//长按的状态
			}
			else//松开
			{
				state = 0; 
				
				KEY_VALUE = KEY_LAST|KEY_SHORT;  //返回按键短按的值
			}
		}break;
		
		case 3: //判断长按还是短按
		{
			if(KEY_NOW == KEY_LAST) 
			{
			    static u8 cnt = 0;
				if(cnt++ > 120) //1200ms
				{
					cnt = 0; 
					state = 4;
					KEY_VALUE = KEY_LAST|KEY_LONG; //返回按键长安
				}			  
			}
			else
			{
				state = 0;
				KEY_VALUE = KEY_LAST|KEY_SHORT; //否则返回短按	
			}
		}break;
		case 4://长按检查是否松手
		{
			if(KEY_NOW != KEY_LAST) 
				state = 5;
		}break;
		case 5://长按检查是否松手
		{
			if(KEY_NOW == KEY_LAST) 
			{
			state = 0;
			return KEY_VALUE;//返回按键值
			}
		}break;
	}//switch
	
	KEY_LAST = KEY_NOW; //状态更新，
	return KEY_VALUE;//返回按键值
}


/**************************************************************/
/*按键按下，短按返回键码值1 2 3 4 5 6，长按返回键码值11 12 13 14 15 16 */
u8 Key_Hander(void)					
{
	u8 KEY_NUM=0;//获取的键码值
//	static u32 LAST=0;
//	if(Systick_ms-LAST<10)	return;
//	LAST = Systick_ms;	
	
	KEY_NUM = Key_Scan();  //读取键码值
	if(KEY_NUM == KEY_NONE) return 0;//没有按键按下，直接return
	
	if(KEY_NUM & KEY_SHORT) //按键按下，&短按的值不等于0就是短按了
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