

int main()
{
	*(unsigned int*)(0x40021018)|=(1<4);//开启GPIO时钟
	
	//配置IO口模式
	*(unsigned int*)0x40011004&=~(0x0f<<(4*5));//相应的位清零，第20-23位清零
	*(unsigned int*)0x40011004|=(0x01<<(4*5));//操作相应的位置11

		//给I对应IO口写相应数据
	*(unsigned int*)0x4001100c&=0<<13;//第13位数据清0
	*(unsigned int*)0x4001100c|=1<<13;//将第13位置位高电平
	
	while(1)
	{
		
	}	
}

void SystemInit(void)
{

}
