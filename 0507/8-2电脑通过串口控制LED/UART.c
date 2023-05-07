#include <REGX52.H>

/**
	* 	@brief	串口初始化函数，波特率4800
	* 	@param  无
	* 	@retval	无
*/

void UART_Init()
{
	SCON=0X50;//串口接收初始化，模式1
	PCON|=0x80;//波特率加倍
	
	//下面是配置定时器1，串口需要用定时器1,一定要注意配置的是定时器1
	TMOD&=0X0F;////8位自动重装模式
	TMOD|=0X20;
//TF1=0;//清除2中断标志位
	TR1=1;//启动定时器
	TH1=0XF3;//设置定时器重装值
	TL1=0XF3;//设置定时器初值
	ET1=0;//只发送，不接受可以不开启中断，禁止定时器中断
	EA=1;//开启中断
	ES=1;//注意这里是串口中断，只打开串口的就行，ET1定时中断不要打开
}

/**
	* 	@brief	串口发送一个数据
	* 	@param	要发送的数据
	* 	@retval	无
*/

void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;//发送一个字节数据，将数据写入SBUF寄存器中
	while(TI==0);//检查是否发送，发送标志位等于1时发送完
	TI=0;//需要软件复位
}

/**
	* 	@brief	串口中断模板
	* 	@param
	* 	@retval
*/
/*
void UART_Routine() interrupt 4
{
	if(RI==1)//判断是否是接收中断，接收中断就执行
	{
			P2=SBUF;//读出接收到的数据
			UART_SendByte(SBUF);//将读到的数据发送给电脑
			RI=0;//接收标志位需要由软件置0
	}
}
*/